// Decompile every function and write one C file per decomp source file (layout.json ranges),
// so reference/ghidra-c/<file>.c sits beside asm/<file>.s.  This is the readable reference
// decompilation; it is not compiled.
//@category SMT2

import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;

import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.regex.*;

public class ExportDecomp extends GhidraScript {
    @Override
    public void run() throws Exception {
        String layoutPath = getScriptArgs()[0];
        String outDir = getScriptArgs()[1];
        String layout = new String(Files.readAllBytes(Paths.get(layoutPath)));
        Matcher m = Pattern.compile("\"start\": \"0x([0-9A-F]+)\", \"end\": \"0x([0-9A-F]+)\", \"file\": \"asm/([^\"]+)\\.s\"").matcher(layout);
        TreeMap<Long, String[]> files = new TreeMap<>();
        while (m.find()) {
            files.put(Long.parseLong(m.group(1), 16), new String[]{m.group(2), m.group(3)});
        }
        DecompInterface di = new DecompInterface();
        DecompileOptions opt = new DecompileOptions();
        di.setOptions(opt);
        di.toggleCCode(true);
        di.toggleSyntaxTree(false);
        di.openProgram(currentProgram);
        Map<String, StringBuilder> out = new TreeMap<>();
        int n = 0, fail = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            long ea = f.getEntryPoint().getOffset();
            Map.Entry<Long, String[]> e = files.floorEntry(ea);
            if (e == null || ea >= Long.parseLong(e.getValue()[0], 16)) continue;
            String file = e.getValue()[1];
            StringBuilder sb = out.computeIfAbsent(file, k -> new StringBuilder(
                "/* Ghidra decompilation of asm/" + k + ".s (reference only; not compiled). */\n\n"));
            DecompileResults r = di.decompileFunction(f, 60, monitor);
            sb.append(String.format("// %s @ 0x%08X\n", f.getName(), ea));
            if (r != null && r.decompileCompleted()) {
                sb.append(r.getDecompiledFunction().getC()).append("\n");
            } else {
                sb.append("/* decompilation failed: " + (r == null ? "?" : r.getErrorMessage()) + " */\n\n");
                fail++;
            }
            n++;
            if (n % 250 == 0) println("decompiled " + n);
        }
        Files.createDirectories(Paths.get(outDir));
        for (Map.Entry<String, StringBuilder> e : out.entrySet()) {
            Files.write(Paths.get(outDir, e.getKey() + ".c"), e.getValue().toString().getBytes("UTF-8"));
        }
        println("exported " + n + " functions, " + fail + " failed");
    }
}
