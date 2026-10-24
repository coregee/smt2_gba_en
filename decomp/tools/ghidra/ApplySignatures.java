// Apply tools/signatures.py results (argument count, value or void return) and I/O register
// labels.  Without this, agbcc's `pop {r0}; bx r0` epilogue makes every function "return" lr.
//@category SMT2

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;

import java.nio.file.*;
import java.util.*;

public class ApplySignatures extends GhidraScript {
    @Override
    public void run() throws Exception {
        List<String> sigs = Files.readAllLines(Paths.get(getScriptArgs()[0]));
        List<String> labels = Files.readAllLines(Paths.get(getScriptArgs()[1]));
        FunctionManager fm = currentProgram.getFunctionManager();
        int n = 0;
        for (String ln : sigs) {
            if (ln.startsWith("address")) continue;
            String[] p = ln.split("\t");
            Function f = fm.getFunctionAt(toAddr(Long.parseLong(p[0], 16)));
            if (f == null) continue;
            int args = Integer.parseInt(p[1]);
            boolean ret = p[2].equals("1");
            List<Variable> params = new ArrayList<>();
            for (int i = 0; i < args; i++) {
                params.add(new ParameterImpl("arg" + i, Undefined4DataType.dataType, currentProgram));
            }
            ReturnParameterImpl rv = new ReturnParameterImpl(
                ret ? (DataType) Undefined4DataType.dataType : VoidDataType.dataType, currentProgram);
            f.updateFunction("__stdcall", rv, params,
                Function.FunctionUpdateType.DYNAMIC_STORAGE_FORMAL_PARAMS, true, SourceType.USER_DEFINED);
            n++;
        }
        for (String ln : labels) {
            String[] p = ln.split("\t");
            if (p.length < 2) continue;
            Address a = toAddr(Long.parseLong(p[0], 16));
            currentProgram.getSymbolTable().createLabel(a, p[1], SourceType.USER_DEFINED);
        }
        println("signatures applied to " + n + " functions");
    }
}
