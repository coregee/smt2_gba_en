/* Ghidra decompilation of asm/code_0814E844.s (reference only; not compiled). */

// sub_0814E844 @ 0x0814E844

undefined4 sub_0814E844(int arg0)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = sub_080C0148(arg0 + 0x8000U & 0xffff);
  sVar1 = *(short *)(iVar2 + 0x12);
  if (((((ushort)(sVar1 - 0x16aU) < 0x12) || (sVar1 == 0xde)) || (sVar1 == 0)) ||
     (((uVar3 = sub_080C0818((uint)*(byte *)(iVar2 + 0xc)), (uVar3 & 0x8000) != 0 ||
       (uVar3 = sub_080C0818((uint)*(byte *)(iVar2 + 0xc)), (uVar3 & 0x2000) != 0)) ||
      ((*(short *)(iVar2 + 0x12) == 0x8b && (iVar2 = sub_080C2340(0x23), iVar2 == 0)))))) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


// sub_0814E8B0 @ 0x0814E8B0

int sub_0814E8B0(void)

{
  int iVar1;
  uint arg0;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = 0;
  arg0 = 4;
  puVar2 = &DAT_030048c0;
  do {
    iVar1 = sub_080C09B0(arg0);
    if ((iVar1 != 0) && (iVar1 = sub_0814E844((uint)(byte)puVar2[0xc]), iVar1 == 1)) {
      iVar3 = iVar3 + 1;
    }
    puVar2 = puVar2 + 0x80;
    arg0 = arg0 + 1;
  } while (arg0 < 0x10);
  return iVar3;
}


