// Build the SMT2 program in Ghidra from the decomp's own discovery (tools/trace.py), instead of
// letting Ghidra guess ARM vs Thumb.  Every traced instruction gets the right TMode context and
// is disassembled without flow-following; functions, names, far jumps (agbcc `bl` used as a
// branch), no-return calls and switch tables are applied from build/ghidra_input.tsv.
//@category SMT2

import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.DWordDataType;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;

import java.io.*;
import java.math.BigInteger;
import java.nio.file.*;
import java.util.*;

public class SetupFromTrace extends GhidraScript {
    private Address a(String hex) {
        return toAddr(Long.parseLong(hex, 16));
    }

    private void block(String name, long start, long len, boolean volatileIo) throws Exception {
        Memory mem = currentProgram.getMemory();
        Address s = toAddr(start);
        if (mem.getBlock(s) != null) return;
        MemoryBlock b = mem.createUninitializedBlock(name, s, len, false);
        b.setRead(true);
        b.setWrite(true);
        b.setVolatile(volatileIo);
    }

    @Override
    public void run() throws Exception {
        String input = getScriptArgs()[0];
        List<String> lines = Files.readAllLines(Paths.get(input));

        block("EWRAM", 0x02000000L, 0x40000, false);
        block("IWRAM", 0x03000000L, 0x8000, false);
        block("IO", 0x04000000L, 0x400, true);
        block("PLTT", 0x05000000L, 0x400, false);
        block("VRAM", 0x06000000L, 0x18000, false);
        block("OAM", 0x07000000L, 0x400, false);
        MemoryBlock rom = currentProgram.getMemory().getBlock(toAddr(0x08000000L));
        if (rom != null) {
            rom.setWrite(false);
            rom.setExecute(true);
        }

        ProgramContext ctx = currentProgram.getProgramContext();
        Register tmode = ctx.getRegister("TMode");
        AddressSet thumb = new AddressSet();
        AddressSet arm = new AddressSet();
        Listing listing = currentProgram.getListing();
        List<String[]> funcs = new ArrayList<>();
        List<String[]> jumps = new ArrayList<>();
        List<String[]> far = new ArrayList<>();
        List<String> noret = new ArrayList<>();
        List<String[]> data = new ArrayList<>();
        List<Address> lits = new ArrayList<>();
        for (String ln : lines) {
            String[] p = ln.split("\t");
            switch (p[0]) {
                case "F": funcs.add(p); break;
                case "I": {
                    Address s = a(p[1]);
                    Address e = s.add(Integer.parseInt(p[2]) - 1);
                    (p[3].equals("thumb") ? thumb : arm).add(s, e);
                    break;
                }
                case "L": lits.add(a(p[1])); break;
                case "J": jumps.add(p); break;
                case "X": far.add(p); break;
                case "N": noret.add(p[1]); break;
                case "D": data.add(p); break;
            }
        }
        println("thumb ranges " + thumb.getNumAddressRanges() + ", arm " + arm.getNumAddressRanges());
        for (AddressRange r : thumb) ctx.setValue(tmode, r.getMinAddress(), r.getMaxAddress(), BigInteger.ONE);
        for (AddressRange r : arm) ctx.setValue(tmode, r.getMinAddress(), r.getMaxAddress(), BigInteger.ZERO);
        for (Address l : lits) {
            try { createData(l, DWordDataType.dataType); } catch (Exception ex) { }
        }
        AddressSet all = new AddressSet(thumb);
        all.add(arm);
        DisassembleCommand dc = new DisassembleCommand(all, all, false);
        dc.applyTo(currentProgram, monitor);
        println("disassembled; instructions = " + listing.getNumInstructions());

        for (String[] p : far) {
            Instruction ins = listing.getInstructionAt(a(p[1]));
            if (ins != null) ins.setFlowOverride(FlowOverride.BRANCH);
        }
        for (String s : noret) {
            Instruction ins = listing.getInstructionAt(a(s));
            if (ins != null) ins.setFlowOverride(FlowOverride.CALL_RETURN);
        }
        ReferenceManager rm = currentProgram.getReferenceManager();
        for (String[] p : jumps) {
            Address site = a(p[1]);
            for (int k = 3; k < p.length; k++) {
                rm.addMemoryReference(site, a(p[k]), RefType.COMPUTED_JUMP, SourceType.ANALYSIS, Reference.MNEMONIC);
            }
        }
        SymbolTable st = currentProgram.getSymbolTable();
        FunctionManager fm = currentProgram.getFunctionManager();
        int made = 0;
        for (String[] p : funcs) {
            Address e = a(p[1]);
            Function f = fm.getFunctionAt(e);
            if (f == null) {
                f = createFunction(e, p[3]);
            }
            if (f != null) {
                f.setName(p[3], SourceType.USER_DEFINED);
                made++;
            } else {
                println("could not create function at " + p[1]);
            }
        }
        // agbcc never tail-calls, so re-derive bodies now that every entry exists.
        for (String[] p : funcs) {
            Function f = fm.getFunctionAt(a(p[1]));
            if (f != null) {
                ghidra.app.cmd.function.CreateFunctionCmd.fixupFunctionBody(currentProgram, f, monitor);
            }
        }
        for (String[] p : data) {
            st.createLabel(a(p[1]), p[2], SourceType.USER_DEFINED);
        }
        println("functions " + made + " of " + funcs.size());
    }
}
