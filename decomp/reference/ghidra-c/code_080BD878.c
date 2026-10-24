/* Ghidra decompilation of asm/code_080BD878.s (reference only; not compiled). */

// sub_080BD878 @ 0x080BD878

void sub_080BD878(void)

{
  short *psVar1;
  uint uVar2;
  
  uVar2 = 0;
  psVar1 = (short *)0x3002730;
  do {
    if (*psVar1 != 0) {
      psVar1[2] = 8;
    }
    psVar1 = psVar1 + 0x28;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  return;
}


// sub_080BD898 @ 0x080BD898

void sub_080BD898(void)

{
  sub_080AB0F0(0x1d0,0x30,1);
  return;
}


// sub_080BD8AC @ 0x080BD8AC

void sub_080BD8AC(void)

{
  if (DAT_03004534 == 0x1c) {
    sub_080AB0F0(0x70,0x10,1);
  }
  return;
}


// sub_080BD8C8 @ 0x080BD8C8

void sub_080BD8C8(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BD8F0 @ 0x080BD8F0

void sub_080BD8F0(void)

{
  if (DAT_03004534 == 0x1c) {
    DisplayList_Add(0x80bd8c9,1);
  }
  else if (DAT_030020e4 == 0x80d977d) {
    DAT_0300000e = 0;
    DAT_03000006 = 0;
    DisplayList_Add(0x80bd8c9,1);
  }
  return;
}


// sub_080BD940 @ 0x080BD940

void sub_080BD940(void)

{
  sub_080C2364(0xfd);
  return;
}


// sub_080BD94C @ 0x080BD94C

void sub_080BD94C(undefined4 arg0)

{
  sub_08157EB0(1,arg0,0);
  return;
}


// sub_080BD95C @ 0x080BD95C

void sub_080BD95C(int arg0)

{
  undefined2 uVar1;
  int iVar2;
  
  if (DAT_03004534 == 0x86) {
    uVar1 = 0x182;
  }
  else {
    if (4 < (ushort)(DAT_03004534 - 0x8aU)) goto LAB_080bd988;
    uVar1 = 0x18e;
  }
  *(undefined2 *)(arg0 + 0x24) = uVar1;
LAB_080bd988:
  iVar2 = sub_080BC230((uint)*(ushort *)(arg0 + 0x24));
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0xc) = 1;
  }
  return;
}


// sub_080BD99C @ 0x080BD99C

void sub_080BD99C(int arg0)

{
  int iVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  iVar1 = sub_080BC230((uint)*(ushort *)(arg0 + 0x24));
  if (iVar1 == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080BD9B8 @ 0x080BD9B8

void sub_080BD9B8(void)

{
  sub_080C33AC((uint)DAT_0203db50);
  return;
}


// sub_080BD9CC @ 0x080BD9CC

void sub_080BD9CC(void)

{
  sub_080C3328((uint)DAT_0203db50);
  return;
}


// sub_080BD9E0 @ 0x080BD9E0

void sub_080BD9E0(void)

{
  DAT_0203db2a = DAT_0203db28;
  return;
}


// sub_080BD9EC @ 0x080BD9EC

void sub_080BD9EC(void)

{
  sub_080B8AE0(0x1f,1);
  return;
}


// sub_080BD9FC @ 0x080BD9FC

void sub_080BD9FC(void)

{
  sub_080B8AE0(0x3ff,1);
  return;
}


// sub_080BDA10 @ 0x080BDA10

void sub_080BDA10(undefined4 arg0,int arg1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 1) {
    sub_080C2364(0x108);
  }
  else {
    sub_080C23BC(0x108);
  }
  DAT_030045a2 = 0;
                    /* WARNING: Could not recover jumptable at 0x080bda32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BDA38 @ 0x080BDA38

void sub_080BDA38(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 | 2;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 | 0x10;
  if ((DAT_030031bc & 1) == 0) {
    DAT_030045a2 = DAT_030045a2 + 1 & 0x3f;
  }
  return;
}


// sub_080BDA7C @ 0x080BDA7C

void sub_080BDA7C(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 & 0xfffd;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 & 0xffef;
  DAT_030020f4 = 0x80a9971;
  return;
}


// sub_080BDAB0 @ 0x080BDAB0

void sub_080BDAB0(void)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  
  bVar1 = REG_VCOUNT._0_1_;
  uVar3 = (uint)bVar1;
  if (uVar3 < 100) {
    iVar4 = (int)*(short *)(((DAT_030045a2 + uVar3) * 4 & 0xff) * 2 + 0x815e828);
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0x1f;
    }
    REG_BG3HOFS = (short)(iVar4 >> 5);
    iVar4 = (int)*(short *)(((DAT_030045a2 + uVar3) * 4 & 0xff) * 2 + 0x815e828);
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0x1f;
    }
    uVar2 = (undefined2)(iVar4 >> 5);
  }
  else {
    uVar2 = 0;
    REG_BG3HOFS = 0;
  }
  REG_BG1HOFS = uVar2;
  return;
}


// sub_080BDB24 @ 0x080BDB24

void sub_080BDB24(void)

{
  DAT_030020f4 = 0x80bdab1;
  sub_080A9C64(0x80bda39,1);
  return;
}


// sub_080BDB44 @ 0x080BDB44

void sub_080BDB44(void)

{
  sub_080A9C64(0x80bda7d,1);
  return;
}


// sub_080BDB58 @ 0x080BDB58

void sub_080BDB58(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C2340(0x108);
  if (iVar1 == 0) {
    if (DAT_030045a0 != 0) {
      sub_080BDB44();
      DAT_030045a0 = 0;
    }
  }
  else {
    if (DAT_030045a0 == 0) {
      DAT_030045a0 = 1;
    }
    if (DAT_030045a0 == 1) {
      sub_080BDB24();
    }
    else {
      sub_080BDB44();
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080bdba4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BDBAC @ 0x080BDBAC

void sub_080BDBAC(undefined4 arg0,undefined4 arg1)

{
  DAT_0300000c = (undefined2)arg1;
  return;
}


// sub_080BDBB8 @ 0x080BDBB8

void sub_080BDBB8(void)

{
  sub_080C2364(0x10f);
  return;
}


// sub_080BDBC8 @ 0x080BDBC8

void sub_080BDBC8(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080B098C();
  if (iVar1 == 0) {
    sub_080AB138(0x80,0x80,2,6);
  }
  else {
    sub_080C2364(0x10d);
  }
                    /* WARNING: Could not recover jumptable at 0x080bdbe8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BDBF0 @ 0x080BDBF0

void sub_080BDBF0(void)

{
  undefined4 arg1;
  
  arg1 = sub_080C5F60((uint)DAT_03004534);
  sub_080ACFCC(3,arg1,0x3002ab0,0x100);
  sub_080AB054(0x80,0x80,1,0x20);
  return;
}


// sub_080BDC28 @ 0x080BDC28

void sub_080BDC28(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080B098C();
  if (iVar1 == 0) {
    sub_080AB138(0x1d0,0x30,2,6);
  }
  else {
    sub_080C2364(0x10e);
  }
                    /* WARNING: Could not recover jumptable at 0x080bdc4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BDC50 @ 0x080BDC50

void sub_080BDC50(void)

{
  DAT_03000030 = 0xe8;
  DAT_03000031 = 8;
  DAT_03000034 = 0xa0;
  DAT_03000035 = 0x60;
  DAT_03000038 = 0x35;
  DAT_03000032 = 0xe8;
  DAT_03000033 = 8;
  DAT_03000036 = 8;
  DAT_03000037 = 0;
  DAT_03000039 = 0x3d;
  return;
}


// sub_080BDCB8 @ 0x080BDCB8

void sub_080BDCB8(void)

{
  m4aSongNumStop(0x13f);
  return;
}


// sub_080BDCC8 @ 0x080BDCC8

void sub_080BDCC8(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BDD00 @ 0x080BDD00

void sub_080BDD00(void)

{
  DisplayList_Add(0x80bdcc9,1);
  DAT_03000006 = 0;
  DAT_03000004 = 0;
  DAT_0300000e = 0;
  DAT_0300000c = 0;
  return;
}


// sub_080BDD34 @ 0x080BDD34

void sub_080BDD34(void)

{
  int iVar1;
  
  iVar1 = sub_080C2340(0xc6);
  if (iVar1 == 0) {
    sub_080AB91C(DAT_03006968,1);
    DAT_0203db6c = 0;
    DAT_03006968 = 0;
  }
  return;
}


// sub_080BDD60 @ 0x080BDD60

void sub_080BDD60(void)

{
  int iVar1;
  
  iVar1 = sub_080C2340(0xc6);
  if (iVar1 == 0) {
    DAT_03006968 = sub_080AB7D4(2,0xb,0x1a,8);
    DAT_0203db6c = 1;
  }
  return;
}


// sub_080BDD94 @ 0x080BDD94

void sub_080BDD94(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080BC230(0x14d);
  *(ushort *)(iVar1 + 0x24) = *(ushort *)(iVar1 + 0x24) | 0x20;
  *(undefined2 *)(arg0 + 0x24) = 0xffff;
  *(undefined2 *)(arg0 + 0x26) = 8;
  *(undefined2 *)(arg0 + 0x28) = 0x10;
  DAT_03000042 = *(ushort *)(arg0 + 0x24) | 0x800;
  DAT_03000044 = 0x10;
  return;
}


// sub_080BDDDC @ 0x080BDDDC

void sub_080BDDDC(int arg0)

{
  ushort uVar1;
  
  uVar1 = *(short *)(arg0 + 0x24) - 1;
  *(ushort *)(arg0 + 0x24) = uVar1;
  DAT_03000042 = uVar1 | *(short *)(arg0 + 0x26) << 8;
  DAT_03000044 = *(undefined2 *)(arg0 + 0x28);
  return;
}


// sub_080BDE00 @ 0x080BDE00

void sub_080BDE00(undefined4 arg0,int arg1)

{
  if (arg1 == 0) {
    sub_080BC260(arg0,0x14d);
  }
  else {
    sub_080C1440();
  }
  return;
}


// sub_080BDE1C @ 0x080BDE1C

void sub_080BDE1C(undefined4 arg0)

{
  int iVar1;
  undefined4 arg0_00;
  undefined4 arg1;
  undefined4 arg2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C2340(0x10a);
  if (iVar1 == 0) goto switchD_080bde42_caseD_104;
  switch((undefined2)arg0) {
  case 0x103:
  case 0x111:
  case 0x113:
  case 0x114:
  case 0x115:
  case 0x118:
  case 0x119:
  case 0x11a:
  case 0x11b:
  case 0x11c:
  case 0x11d:
  case 0x11e:
  case 0x11f:
  case 0x120:
  case 0x121:
  case 0x122:
  case 0x123:
  case 0x124:
  case 0x126:
  case 0x127:
  case 0x129:
  case 0x12a:
  case 299:
  case 300:
  case 0x12e:
  case 0x12f:
    arg0_00 = 0;
    arg1 = 0x78;
    break;
  default:
    goto switchD_080bde42_caseD_104;
  case 0x10f:
    arg0_00 = 1;
    arg1 = 0xa1;
    break;
  case 0x110:
    arg0_00 = 0;
    arg1 = 0x50;
    break;
  case 0x125:
    arg0_00 = 0;
    arg1 = 0x78;
    arg2 = 0x6a;
    goto LAB_080bdf22;
  case 0x128:
    arg0_00 = 0;
    arg1 = 0x78;
    arg2 = 0x6a;
    goto LAB_080bdf22;
  case 0x12d:
    sub_080E8F80(0,0x78,0x56,3);
    goto switchD_080bde42_caseD_104;
  }
  arg2 = 0x56;
LAB_080bdf22:
  sub_080E8F80(arg0_00,arg1,arg2,3);
switchD_080bde42_caseD_104:
                    /* WARNING: Could not recover jumptable at 0x080bdf3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BDF3C @ 0x080BDF3C

void sub_080BDF3C(undefined4 arg0)

{
  int iVar1;
  
  iVar1 = sub_080C2340(0x10a);
  if (iVar1 != 0) {
    switch((undefined2)arg0) {
    case 0x22:
      DAT_0300000e = 0x48;
      break;
    case 0x3a:
      DAT_0300000e = 0x68;
      break;
    case 0x3b:
    case 0x3c:
    case 0x50:
      DAT_0300000e = 0x60;
      break;
    case 0x51:
      DAT_0300000e = 0x40;
      break;
    case 0x53:
      DAT_0300000e = 0x40;
      break;
    case 0x54:
      DAT_0300000e = 0x40;
      break;
    case 0x5d:
      DAT_0300000e = 0x40;
      break;
    case 0x5e:
      DAT_0300000e = 0x40;
      break;
    case 0x70:
      DAT_0300000e = 0x20;
    }
  }
  return;
}


// sub_080BE114 @ 0x080BE114

void sub_080BE114(void)

{
  sub_080AB0F0(0x80,0x80,1);
  sub_080AB0F0(0x1d0,0x30,1);
  return;
}


// sub_080BE130 @ 0x080BE130

void sub_080BE130(int arg0)

{
  undefined2 uVar1;
  
  *(undefined2 *)(arg0 + 0x24) = DAT_0300000e;
  *(undefined2 *)(arg0 + 0x26) = 0;
  *(undefined2 *)(arg0 + 0x28) = 4;
  *(undefined2 *)(arg0 + 0x2a) = 4;
  *(undefined2 *)(arg0 + 0x2c) = 2;
  *(undefined2 *)(arg0 + 0x2e) = 2;
  switch(DAT_0203cb90) {
  case 0x103:
  case 0x10f:
  case 0x110:
    *(undefined2 *)(arg0 + 0x26) = 0x28;
  default:
    goto switchD_080be168_caseD_104;
  case 0x111:
  case 0x113:
  case 0x124:
  case 300:
    uVar1 = 0x22;
    break;
  case 0x114:
    uVar1 = 0x25;
    break;
  case 0x115:
    uVar1 = 5;
    break;
  case 0x118:
    uVar1 = 0x23;
    break;
  case 0x119:
    uVar1 = 0x23;
    break;
  case 0x11a:
    uVar1 = 0x23;
    break;
  case 0x11b:
    uVar1 = 0x23;
    break;
  case 0x11c:
    uVar1 = 0x23;
    break;
  case 0x11d:
    uVar1 = 0x23;
    break;
  case 0x11e:
    uVar1 = 0x23;
    break;
  case 0x11f:
    uVar1 = 0x23;
    break;
  case 0x120:
    uVar1 = 0x23;
    break;
  case 0x121:
    uVar1 = 0x23;
    break;
  case 0x122:
    uVar1 = 0x23;
    break;
  case 0x123:
    uVar1 = 0x1e;
    break;
  case 0x126:
    *(undefined2 *)(arg0 + 0x26) = 0x1e;
    uVar1 = 8;
    goto LAB_080be288;
  case 0x127:
    uVar1 = 0x23;
    break;
  case 0x128:
    uVar1 = 0xf;
    break;
  case 0x12f:
    uVar1 = 0x24;
  }
  *(undefined2 *)(arg0 + 0x26) = uVar1;
  uVar1 = 7;
LAB_080be288:
  *(undefined2 *)(arg0 + 0x2e) = uVar1;
  *(undefined2 *)(arg0 + 0x2c) = uVar1;
switchD_080be168_caseD_104:
  switch(DAT_03004534) {
  case 0x3b:
  case 0x3c:
    *(undefined2 *)(arg0 + 0x28) = 1;
    *(undefined2 *)(arg0 + 0x2a) = 1;
  }
  return;
}


// sub_080BE3F4 @ 0x080BE3F4

void sub_080BE3F4(int arg0)

{
  short sVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  sVar1 = *(short *)(arg0 + 0x2a) + -1;
  *(short *)(arg0 + 0x2a) = sVar1;
  if (sVar1 == 0) {
    *(undefined2 *)(arg0 + 0x2a) = *(undefined2 *)(arg0 + 0x28);
    if (*(short *)(arg0 + 0x24) != 0) {
      DAT_0300000e = DAT_0300000e + -1;
      *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
    }
  }
  sVar1 = *(short *)(arg0 + 0x2e) + -1;
  *(short *)(arg0 + 0x2e) = sVar1;
  if ((sVar1 == 0) &&
     (*(undefined2 *)(arg0 + 0x2e) = *(undefined2 *)(arg0 + 0x2c), *(short *)(arg0 + 0x26) != 0)) {
    DAT_0203cfaa = DAT_0203cfaa + 1;
    *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + -1;
    if (DAT_0203cb90 == 0x110) {
      DAT_0203cfea = DAT_0203cfea + 1;
    }
  }
  if (*(int *)(arg0 + 0x24) == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080BE484 @ 0x080BE484

void sub_080BE484(void)

{
  sub_080C51BC(1);
  return;
}


// sub_080BE490 @ 0x080BE490

void sub_080BE490(void)

{
  sub_080AB008(0x1d0,0x30,4);
  return;
}


// sub_080BE4A4 @ 0x080BE4A4

void sub_080BE4A4(void)

{
  DAT_0200ab04 = 0;
  return;
}


// sub_080BE4B0 @ 0x080BE4B0

void sub_080BE4B0(void)

{
  sub_080C3818(1);
  sub_080AABD4(0);
  return;
}


// sub_080BE4C4 @ 0x080BE4C4

void sub_080BE4C4(void)

{
  *(undefined4 *)(DAT_0300463c + 0xc) = 1;
  return;
}


// sub_080BE4D4 @ 0x080BE4D4

void sub_080BE4D4(void)

{
  sub_080AAF48(1);
  DAT_0200e808 = 1;
  return;
}


// sub_080BE4EC @ 0x080BE4EC

void sub_080BE4EC(int arg0)

{
  sub_0813EE90((*(ushort *)(arg0 + 0x24) & 0xf0) >> 4,*(ushort *)(arg0 + 0x24) & 0xf);
  return;
}


// sub_080BE504 @ 0x080BE504

void sub_080BE504(void)

{
  undefined4 uVar1;
  undefined4 auStack_8 [2];
  
  auStack_8[0] = 0;
  REG_DMA3SAD = auStack_8;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85001000;
  uVar1 = REG_DMA3CNT;
  sub_080C1450();
  return;
}


// sub_080BE530 @ 0x080BE530

void sub_080BE530(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x2028074;
  REG_DMA3CNT = 0x85000008;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = DAT_03003b94;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  sub_080ADF64();
  return;
}


// sub_080BE57C @ 0x080BE57C

void sub_080BE57C(undefined4 arg0,uint arg1)

{
  dword arg0_00;
  int iVar1;
  int iVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  undefined1 auStack_28 [6];
  undefined2 uStack_22;
  undefined2 uStack_1a;
  
  if (arg1 == 3) {
    uStack_22 = 8;
    uStack_1a = 0;
    sub_080AB528(auStack_28,2,0xb,0x1a);
    sub_080AB61C(0);
  }
  else if (arg1 < 4) {
    if (arg1 == 1) {
      sub_080C14FC();
      arg0_00 = 0x80c153d;
    }
    else {
      if (1 < arg1) {
        Party_BuildMemberNameTiles();
        sub_080C6FD8();
        sub_080C65C8();
        sub_080C6764();
        goto LAB_080be6d4;
      }
      Font_ResetGlyphSpriteCache(0x180);
      sub_080C1328();
      sub_080C1384();
      arg0_00 = 0x80be505;
    }
    DisplayList_Add(arg0_00,1);
  }
  else if (arg1 == 5) {
    if ((DAT_0200ab04 & 0x8000) == 0) {
      DAT_030029b0 = *DAT_03004630;
      sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
      sub_080ACFCC(3,DAT_03004510,&DAT_03002b50,0x20);
      DisplayList_Add(0x80be531,1);
      sub_080AE304();
    }
    else {
      sub_080B437C();
    }
  }
  else if (arg1 < 5) {
    uVar3 = 0;
    do {
      iVar1 = *(int *)(uVar3 * 4 + 0x2036094);
      if (iVar1 != 0) {
        iVar2 = sub_080D95F4((uint)*(ushort *)(iVar1 + 0x2a));
        sub_080C4080(iVar1 + 0x24,*(undefined4 *)(iVar2 + 4),0,0);
        sub_080C4080(iVar1 + 0x24,*(undefined4 *)(iVar2 + 8),0,1);
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < 4);
  }
  else if (arg1 == 6) {
    DAT_0200e808 = 0;
    sub_080C1440();
  }
  else if (arg1 == 0x100) {
    sub_080AAEDC(1);
    sub_080A9AB4(0x80c1851);
  }
LAB_080be6d4:
                    /* WARNING: Could not recover jumptable at 0x080be6da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BE6E0 @ 0x080BE6E0

void sub_080BE6E0(undefined4 arg0)

{
  DAT_0300463c = sub_080AD0FC(0x8198128,0xffff);
  *(undefined2 *)(DAT_0300463c + 0x24) = (undefined2)arg0;
  return;
}


// sub_080BE70C @ 0x080BE70C

undefined4 sub_080BE70C(void)

{
  char *pcVar1;
  char local_c [2];
  byte local_a [2];
  
  sub_080C1F50((uint)DAT_03004562,(uint)DAT_03004564,local_c,local_a);
  pcVar1 = (char *)0x8198278;
  while( true ) {
    if (*pcVar1 == -1) {
      return 0;
    }
    if (((*pcVar1 == local_c[0]) && ((pcVar1[1] & 0x3fU) == local_a[0])) &&
       ((byte)pcVar1[1] >> 6 == (byte)DAT_03004552)) break;
    pcVar1 = pcVar1 + 4;
  }
  return pcVar1;
}


// sub_080BE76C @ 0x080BE76C

undefined4 sub_080BE76C(void)

{
  int iVar1;
  dword arg0;
  undefined4 uVar2;
  byte bVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080BE70C();
  bVar3 = *(byte *)(iVar1 + 2) & 0xf;
  if (bVar3 == 1) {
    arg0 = 0x8198554;
  }
  else {
    if (bVar3 < 2) {
LAB_080be7c8:
      uVar2 = 0;
      goto LAB_080be7ca;
    }
    if (bVar3 == 2) {
      arg0 = 0x8198648;
    }
    else {
      if ((bVar3 != 3) || (iVar1 = sub_080C2340(*(byte *)(iVar1 + 3) + 0x110), iVar1 != 0))
      goto LAB_080be7c8;
      arg0 = 0x8198328;
    }
  }
  sub_080AD0FC(arg0,0xffff);
  Field_SetState(0x1a);
  uVar2 = 1;
LAB_080be7ca:
                    /* WARNING: Could not recover jumptable at 0x080be7cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080BE7D0 @ 0x080BE7D0

void sub_080BE7D0(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = Door_KeypadInitInputState(arg0);
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  return;
}


// sub_080BE7E0 @ 0x080BE7E0

void sub_080BE7E0(int arg0)

{
  *(undefined4 *)(*(int *)(arg0 + 0x24) + 0xc) = 1;
  return;
}


// sub_080BE7E8 @ 0x080BE7E8

void sub_080BE7E8(void)

{
  DAT_03004550 = 1;
  DAT_03003ff4 = 0;
  return;
}


// sub_080BE800 @ 0x080BE800

void sub_080BE800(int arg0)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080BE70C();
  iVar3 = (uint)*(byte *)(iVar2 + 3) * 4;
  pcVar4 = (char *)sub_080A9CC0(DAT_030031cc);
  if ((((pcVar4[3] == *(char *)(iVar3 + 0x81982fd)) && (pcVar4[2] == (&DAT_081982fe)[iVar3])) &&
      (pcVar4[1] == (&DAT_081982ff)[iVar3])) && (*pcVar4 == (&DAT_08198300)[iVar3])) {
    *(undefined2 *)(arg0 + 0x1e) = 0;
    sub_080C2364(*(byte *)(iVar2 + 3) + 0x110);
  }
  else {
    iVar2 = *(int *)(arg0 + 0x28) + 1;
    *(int *)(arg0 + 0x28) = iVar2;
    if (iVar2 == 3) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    *(undefined2 *)(arg0 + 0x1e) = uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x080be872. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BE874 @ 0x080BE874

void sub_080BE874(int arg0)

{
  *(short *)(arg0 + 0x1e) = (short)DAT_030031cc;
  return;
}


// sub_080BE880 @ 0x080BE880

void sub_080BE880(undefined4 arg0,int arg1)

{
  undefined4 uVar1;
  
  if (arg1 == 0) {
    uVar1 = sub_080B1A1C((uint)DAT_03004552);
    DAT_03004552 = (ushort)uVar1;
    sub_080B2840(0,0,0);
  }
  else {
    DisplayList_Add(0x80b0159,1);
  }
  return;
}


// sub_080BE8B4 @ 0x080BE8B4

void sub_080BE8B4(int arg0)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  byte local_18 [8];
  
  iVar1 = sub_080C0148(0x8000);
  iVar2 = sub_080BE70C();
  local_18[0] = *(byte *)(iVar1 + 0x28);
  local_18[1] = *(undefined1 *)(iVar1 + 0x29);
  local_18[2] = *(undefined1 *)(iVar1 + 0x2a);
  local_18[3] = *(undefined1 *)(iVar1 + 0x2b);
  local_18[4] = *(undefined1 *)(iVar1 + 0x2c);
  local_18[5] = *(undefined1 *)(iVar1 + 0x2d);
  uVar3 = sub_080C0818((uint)*(byte *)(iVar1 + 0xc));
  if ((uVar3 & 0x800) != 0) {
    local_18[0] = 1;
    local_18[1] = 1;
    local_18[2] = 1;
    local_18[3] = 1;
    local_18[4] = 1;
    local_18[5] = 0x28;
  }
  bVar4 = (ushort)local_18[*(ushort *)(iVar2 + 2) >> 4 & 0xf] < *(ushort *)(iVar2 + 2) >> 8;
  if (bVar4) {
    sub_080B832C();
  }
  else {
    sub_080B832C();
  }
  *(ushort *)(arg0 + 0x1c) = (ushort)!bVar4;
  return;
}


// sub_080BE968 @ 0x080BE968

void sub_080BE968(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = sub_080C0148(0x8000);
  iVar4 = sub_080BE70C();
  uVar5 = 0;
  if (*(ushort *)(iVar3 + 0x58) < 0x7000) {
    uVar5 = -(*(ushort *)(iVar4 + 2) & 0x40) >> 0x1f;
  }
  else {
    if (*(ushort *)(iVar3 + 0x58) < 0x9000) {
      uVar1 = *(ushort *)(iVar4 + 2);
      uVar2 = 0x10;
    }
    else {
      uVar1 = *(ushort *)(iVar4 + 2);
      uVar2 = 0x20;
    }
    if ((uVar2 & uVar1) != 0) {
      uVar5 = 1;
    }
  }
  if (uVar5 == 1) {
    sub_080B832C();
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else {
    sub_080B832C();
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_080BE9E4 @ 0x080BE9E4

void sub_080BE9E4(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080AB7D4(2,0xb,0x1a,2);
  *(undefined4 *)(arg0 + 0x30) = uVar1;
  return;
}


// sub_080BEA08 @ 0x080BEA08

void sub_080BEA08(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((*(uint *)(arg0 + 0x24) & 1 << (*(ushort *)(arg0 + 0x2c) & 0xff)) == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    *(short *)(arg0 + 0x2c) = *(short *)(arg0 + 0x2c) + 1;
  }
  return;
}


// sub_080BEA34 @ 0x080BEA34

void sub_080BEA34(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) != 0) {
    *(short *)(arg0 + 0x2c) = *(short *)(arg0 + 0x2c) + 1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// Status_ShowAfflictionMessage @ 0x080BEA60

void Status_ShowAfflictionMessage(int arg0)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 arg0_00;
  uint arg3;
  dword unaff_r6;
  undefined4 *puVar4;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack_38;
  undefined4 uStack_34;
  ushort auStack_30 [16];
  
  puVar4 = &uStack_38;
  if (*(short *)(arg0 + 0x2c) == 0) {
    uVar1 = *(ushort *)(arg0 + 0x28);
    if ((*(uint *)(arg0 + 0x24) & 1) == 0) goto LAB_080bec1a;
    uVar2 = 0x8000;
  }
  else {
    uVar1 = *(ushort *)(arg0 + 0x2a);
    if ((*(uint *)(arg0 + 0x24) & 2) == 0) goto LAB_080bec1a;
    iVar3 = sub_080C1B50();
    uVar2 = iVar3 + 0x8000U & 0xffff;
  }
  arg0_00 = sub_080F2F64(uVar2);
  if (uVar1 == 0x100) {
    unaff_r6 = 0x81987ba;
  }
  else if (uVar1 < 0x101) {
    if (uVar1 == 0x10) {
      unaff_r6 = 0x81987fc;
    }
    else if (uVar1 < 0x11) {
      if (uVar1 == 4) {
        unaff_r6 = 0x8198822;
      }
      else if (uVar1 < 5) {
        if (uVar1 == 2) {
          unaff_r6 = 0x8198834;
        }
      }
      else if (uVar1 == 8) {
        unaff_r6 = 0x819880e;
      }
    }
    else if (uVar1 == 0x40) {
      unaff_r6 = 0x81987d4;
    }
    else if (uVar1 < 0x41) {
      if (uVar1 == 0x20) {
        unaff_r6 = 0x81987e6;
      }
    }
    else if (uVar1 == 0x80) {
      unaff_r6 = 0x81987c8;
    }
  }
  else if (uVar1 == 0x1000) {
    unaff_r6 = 0x819876c;
  }
  else if (uVar1 < 0x1001) {
    if (uVar1 == 0x400) {
      unaff_r6 = 0x8198794;
    }
    else if (uVar1 < 0x401) {
      if (uVar1 == 0x200) {
        unaff_r6 = 0x81987a8;
      }
    }
    else if (uVar1 == 0x800) {
      unaff_r6 = 0x8198780;
    }
  }
  else if (uVar1 == 0x4000) {
    unaff_r6 = 0x8198748;
  }
  else if (uVar1 < 0x4001) {
    if (uVar1 == 0x2000) {
      unaff_r6 = 0x819875e;
    }
  }
  else if (uVar1 == 0x8000) {
    unaff_r6 = 0x819873c;
  }
  arg3 = 0x10;
  Combatant_DecodeName(arg0_00,auStack_30);
  uVar2 = 0;
  while (*(short *)((int)puVar4 + 8) != 0) {
    uStack_38 = 0x59;
    FontSprite_DrawGlyph((uint)auStack_30[uVar2],0,0,arg3);
    arg3 = arg3 + 0xc & 0xffff;
    uVar2 = uVar2 + 1 & 0xffff;
    if (7 < uVar2) break;
    puVar4 = (undefined4 *)((int)&uStack_38 + uVar2 * 2);
  }
  uStack_38 = 0x59;
  uStack_34 = 0xc;
  Text_DrawSpriteString(unaff_r6,0,0,arg3);
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_080C4AB0(0,0,0xd6,0x61);
  }
LAB_080bec1a:
                    /* WARNING: Could not recover jumptable at 0x080bec20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BEC28 @ 0x080BEC28

void sub_080BEC28(int arg0)

{
  sub_080AB91C(*(undefined4 *)(arg0 + 0x30),1);
  Field_SetState(1);
  return;
}


// sub_080BEC3C @ 0x080BEC3C

void sub_080BEC3C(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x8198848,0xffff);
  *(undefined4 *)(iVar1 + 0x24) = arg0;
  *(undefined2 *)(iVar1 + 0x28) = (undefined2)arg1;
  *(undefined2 *)(iVar1 + 0x2a) = (undefined2)arg2;
  return;
}


// sub_080BEC6C @ 0x080BEC6C

void sub_080BEC6C(int arg0)

{
  *(undefined4 *)(arg0 + 0x24) = DAT_03006a1c;
  *(undefined2 *)(arg0 + 0x28) = DAT_03006a20;
  *(undefined2 *)(arg0 + 0x2a) = DAT_03006a22;
  return;
}


// sub_080BEC84 @ 0x080BEC84

void sub_080BEC84(int arg0)

{
  sub_080AB91C(*(undefined4 *)(arg0 + 0x30),1);
  DAT_0300456e = 0;
  Field_SetState(0x1e);
  return;
}


// sub_080BECA4 @ 0x080BECA4

uint sub_080BECA4(void)

{
  uint uVar1;
  
  uVar1 = sub_080C1D9C();
  uVar1 = uVar1 & 0xf0;
  if (0x8f < uVar1) {
    uVar1 = 0x80 - (uVar1 + 0x80 & 0xff) & 0xff;
  }
  return uVar1;
}


// sub_080BECCC @ 0x080BECCC

undefined4 sub_080BECCC(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080BECA4();
  iVar2 = sub_080C2340(0x1d);
  if (iVar2 == 0) {
    if (((uVar1 & 0xff) == 0x80) || (uVar1 = sub_080C2244(), (uVar1 & 0xff) < 0x20)) {
LAB_080bed08:
      uVar3 = 2;
      goto LAB_080bed5a;
    }
  }
  else {
    iVar2 = sub_080C2340(0x23);
    if (iVar2 == 0) {
      uVar1 = sub_080C2244();
      if ((uVar1 & 0xff) < 0x80) goto LAB_080bed08;
    }
    else {
      iVar2 = sub_080C2340(0x68);
      if (iVar2 == 0) {
        uVar1 = sub_080C2244();
        if ((uVar1 & 0xff) < 0x80) {
LAB_080bed44:
          uVar3 = 3;
          goto LAB_080bed5a;
        }
      }
      else {
        iVar2 = sub_080C2340(0x96);
        if ((iVar2 == 0) && (iVar2 = sub_080C2340(0x7d), iVar2 == 0)) {
          uVar1 = sub_080C2244();
          if ((uVar1 & 0xff) < 0x20) goto LAB_080bed44;
        }
        else {
          uVar1 = sub_080C2244();
          if ((uVar1 & 0xff) < 0x40) {
            uVar3 = 4;
            goto LAB_080bed5a;
          }
        }
      }
    }
  }
  uVar3 = 1;
LAB_080bed5a:
                    /* WARNING: Could not recover jumptable at 0x080bed5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar3);
  return uVar3;
}


// sub_080BED60 @ 0x080BED60

undefined4 sub_080BED60(void)

{
  int iVar1;
  undefined4 uVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  short local_24;
  short local_22;
  
  sub_080C1F50((uint)DAT_03004562,(uint)DAT_03004564,&local_24,&local_22);
  DAT_030045b2 = 0;
  uVar5 = 0;
  psVar3 = (short *)0x8198978;
  iVar4 = 0;
  while ((local_24 != *psVar3 || (local_22 != *(short *)((int)&DAT_0819897a + iVar4)))) {
LAB_080bee04:
    psVar3 = psVar3 + 3;
    iVar4 = iVar4 + 6;
    uVar5 = uVar5 + 1;
    if (0x2f < uVar5) {
LAB_080bee12:
      uVar2 = 0;
LAB_080bee14:
                    /* WARNING: Could not recover jumptable at 0x080bee22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
      return uVar2;
    }
  }
  if (DAT_03004552 != psVar3[2]) goto LAB_080bee12;
  iVar1 = sub_080C2340(0xae);
  if (((iVar1 == 0) && (iVar1 = sub_080C2340(0x65), iVar1 == 0)) &&
     (iVar1 = sub_080C2340(0x9c), iVar1 == 0)) {
    iVar1 = sub_080C2340(0x16);
    if (iVar1 == 0) goto LAB_080bee04;
    uVar5 = sub_080BECCC();
    if ((uVar5 & 0xffff) < 2) {
      DAT_030045b2 = 0;
      goto LAB_080bee12;
    }
    DAT_030045b2 = (short)uVar5 + -2;
  }
  uVar2 = 1;
  goto LAB_080bee14;
}


// sub_080BEE24 @ 0x080BEE24

int sub_080BEE24(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 arg0;
  
  iVar1 = sub_080BED60();
  if (iVar1 != 0) {
    arg0 = *(undefined4 *)((uint)DAT_030045b2 * 4 + 0x8198a98);
    uVar2 = ScriptVM_RunAlt(arg0);
    if (((short)uVar2 == 1) || (uVar2 = ScriptVM_RunAlt(arg0), (short)uVar2 == 2)) {
      sub_080AF178(0xc,arg0);
    }
  }
  return iVar1;
}


// sub_080BEE74 @ 0x080BEE74

void sub_080BEE74(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x6004040;
  REG_DMA3DAD = 0x600cc00;
  REG_DMA3CNT = 0x840007f0;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x6008040;
  REG_DMA3DAD = 0x600ebc0;
  REG_DMA3CNT = 0x84000440;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BEEB0 @ 0x080BEEB0

void sub_080BEEB0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x6004040;
  REG_DMA3DAD = 0x600cc00;
  REG_DMA3CNT = 0x840005b8;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x6008e00;
  REG_DMA3DAD = 0x600e2e0;
  REG_DMA3CNT = 0x840005b8;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BEEE8 @ 0x080BEEE8

void sub_080BEEE8(void)

{
  int iVar1;
  
  iVar1 = sub_080C5F04((uint)DAT_03004534,8);
  if (iVar1 == 0) {
    DisplayList_Add(0x80bee75,1);
  }
  else {
    DisplayList_Add(0x80beeb1,1);
  }
  return;
}


// sub_080BEF1C @ 0x080BEF1C

void sub_080BEF1C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  REG_BG2CNT = 0x8408;
  return;
}


// sub_080BEF4C @ 0x080BEF4C

void sub_080BEF4C(void)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  short *psVar8;
  uint uVar9;
  short sVar10;
  short sVar11;
  undefined4 local_28;
  byte *local_24;
  
  sVar11 = 0x260;
  pbVar4 = (byte *)sub_080C5F40((uint)DAT_03004534,0);
  local_24 = (byte *)sub_080C5F40((uint)DAT_03004534,1);
  local_28 = 0;
  REG_DMA3SAD = &local_28;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x85000400;
  uVar3 = REG_DMA3CNT;
  iVar5 = sub_080C5F04((uint)DAT_03004534,8);
  if (iVar5 == 0) {
    if ((ushort)(DAT_03004534 - 0xd9) < 2) {
      sVar10 = 8;
      if (DAT_03004534 == 0xda) {
        sVar10 = 7;
      }
      uVar6 = 0;
      do {
        uVar9 = 0;
        uVar7 = uVar6 + 1;
        psVar8 = (short *)(uVar6 * 0x40 + 0x2000000);
        do {
          bVar1 = *pbVar4;
          pbVar4 = pbVar4 + 1;
          *psVar8 = sVar11 + ((bVar1 & 0xf) + sVar10) * 0x1000;
          sVar11 = sVar11 + 1;
          psVar8 = psVar8 + 1;
          uVar9 = uVar9 + 1;
        } while (uVar9 < 0x1e);
        uVar6 = uVar7;
      } while (uVar7 < 0xd);
    }
    else {
      uVar6 = 0;
      do {
        uVar7 = 0;
        uVar9 = uVar6 + 1;
        iVar5 = uVar6 * 0x40 + 0x2000000;
        do {
          bVar1 = *pbVar4;
          pbVar4 = pbVar4 + 1;
          *(ushort *)(iVar5 + 2) = sVar11 + ((bVar1 & 0xf) + 8) * 0x1000;
          sVar11 = sVar11 + 1;
          iVar5 = iVar5 + 2;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0x1c);
        uVar6 = uVar9;
      } while (uVar9 < 0xd);
    }
  }
  else {
    uVar6 = 0;
    do {
      uVar7 = 0;
      uVar9 = uVar6 + 1;
      iVar5 = uVar6 * 0x40 + 0x2000000;
      psVar8 = (short *)((uVar6 * 0x20 + 0x1c) * 2 + 0x2000000);
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 1;
        bVar2 = *local_24;
        local_24 = local_24 + 1;
        *(ushort *)(iVar5 + 2) = sVar11 + ((bVar1 & 0xf) + 8) * 0x1000;
        *psVar8 = sVar11 + ((bVar2 & 0xf) + 8) * 0x1000 + 0x4b7;
        sVar11 = sVar11 + 1;
        psVar8 = psVar8 + -1;
        iVar5 = iVar5 + 2;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 0xe);
      uVar6 = uVar9;
    } while (uVar9 < 0x1a);
  }
  DisplayList_Add(0x80bef1d,1);
  sub_080C140C(0x10,0);
  DAT_03000044 = 8;
  return;
}


// sub_080BF0C0 @ 0x080BF0C0

void sub_080BF0C0(int arg0)

{
  uint arg0_00;
  int iVar1;
  uint uVar2;
  int arg0_01;
  uint arg2;
  uint uVar3;
  uint arg1;
  uint unaff_r10;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  arg1 = (uint)*(ushort *)(arg0 + 0x2a);
  arg2 = *(ushort *)(arg0 + 0x2c) & 0x3f;
  arg0_00 = 0;
  while( true ) {
    uStack_24 = arg2;
    uVar2 = sub_080C8B3C(arg0_00);
    arg0_01 = sub_080C8B10(arg0_00,0);
    arg2 = uStack_24;
    if (arg0_01 == 0) break;
    uVar3 = 0;
    if (uVar2 != 0) {
      do {
        if ((((*(ushort *)(arg0_01 + 8) <= arg1) && (*(ushort *)(arg0_01 + 10) <= arg2)) &&
            (arg1 <= *(ushort *)(arg0_01 + 0xc))) && (arg2 <= *(ushort *)(arg0_01 + 0xe))) {
          uStack_24 = arg2;
          iVar1 = sub_080B7944(arg0_01,arg1,arg2);
          arg2 = uStack_24;
          if (iVar1 == 1) {
            arg1 = arg1 - *(ushort *)(arg0_01 + 8) & 0xffff;
            arg2 = uStack_24 - *(ushort *)(arg0_01 + 10) & 0xffff;
            unaff_r10 = arg0_00;
            uStack_28 = uVar3;
            break;
          }
        }
        uVar3 = uVar3 + 1 & 0xffff;
        arg0_01 = arg0_01 + 0x268;
      } while (uVar3 < uVar2);
    }
    if (uVar3 != uVar2) break;
    arg0_00 = arg0_00 + 1 & 0xffff;
  }
  DAT_03004514 = uStack_28;
  DAT_03004562 = (undefined2)arg1;
  DAT_03004564 = (undefined2)arg2;
  DAT_03004552 = (undefined2)((*(ushort *)(arg0 + 0x2c) >> 5 & 6) >> 1);
  uStack_2c = 0;
  DAT_03004614 = unaff_r10;
  CpuSet(&uStack_2c,0x2005004,0x5001000);
  sub_080AE234();
  sub_080ADCCC(DAT_03004614,DAT_03004514);
                    /* WARNING: Could not recover jumptable at 0x080bf1a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BF1B8 @ 0x080BF1B8

void sub_080BF1B8(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x2028074;
  REG_DMA3CNT = 0x85000008;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = DAT_03003b94;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BF1FC @ 0x080BF1FC

void sub_080BF1FC(int arg0)

{
  if (DAT_03003ff8 == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_0300455e = 0;
    DisplayList_Add(0x80adf65,1);
    DisplayList_Add(0x80bf1b9,1);
  }
  else {
    sub_080AD824((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514,0x3003ff8);
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_080BF254 @ 0x080BF254

void sub_080BF254(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BF278 @ 0x080BF278

void sub_080BF278(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  REG_DMA3SAD = 0x857d9c0;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  uVar2 = 0;
  do {
    uVar4 = 0;
    do {
      iVar3 = uVar2 * 0x20 + uVar4;
      (&DAT_02000042)[iVar3] = (&DAT_081b83b2)[iVar3];
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < 0x1c);
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0xc);
  sub_080AB1C4(0x2000000,1,0xd,1);
  sub_080AE330();
  DisplayList_Add(0x80bf255,1);
  return;
}


// sub_080BF300 @ 0x080BF300

void sub_080BF300(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x8198ad0,0xffff);
  *(undefined2 *)(iVar1 + 0x2a) = (undefined2)arg0;
  *(undefined2 *)(iVar1 + 0x2c) = (undefined2)arg1;
  return;
}


// sub_080BF32C @ 0x080BF32C

int sub_080BF32C(uint arg0)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xffff;
  if ((arg0 & 0x8000) != 0) {
    uVar1 = arg0 & 0xff;
  }
  return uVar1 * 0x24 + 0x8198b74;
}


// Equipment_GetRecord36_MidRange @ 0x080BF354

int Equipment_GetRecord36_MidRange(uint arg0)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xffff;
  if ((arg0 & 0x8000) != 0) {
    uVar1 = arg0 & 0xff;
  }
  return uVar1 * 0x24 + 0x8198b74;
}


// sub_080BF37C @ 0x080BF37C

void sub_080BF37C(uint arg0,uint arg1,uint arg2,uint arg3)

{
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000004;
  
  uVar3 = arg0 & 0xffff;
  if ((arg0 & 0x8000) != 0) {
    uVar3 = arg0 & 0xff;
  }
  if (uVar3 < 0xd0) {
    if (uVar3 < 0x80) {
      iVar1 = sub_080BF32C(uVar3);
    }
    else {
      iVar1 = Equipment_GetRecord36_MidRange(uVar3);
    }
    puVar2 = (ushort *)(iVar1 + 0x14);
  }
  else {
    iVar1 = Action_GetRecord(uVar3);
    puVar2 = (ushort *)(iVar1 + 0xc);
  }
  uVar3 = 0;
  do {
    if (*puVar2 == 0) break;
    FontSprite_DrawGlyph((uint)*puVar2,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
    puVar2 = puVar2 + 1;
    arg3 = (arg3 & 0xffff) + (in_stack_00000004 & 0xffff);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
                    /* WARNING: Could not recover jumptable at 0x080bf414. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// Action_GetRecord @ 0x080BF418

int Action_GetRecord(uint arg0)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xffff;
  if ((arg0 & 0x8000) != 0) {
    uVar1 = arg0 & 0xff;
  }
  return uVar1 * 0x20 + 0x8198eb4;
}


// sub_080BF43C @ 0x080BF43C

void sub_080BF43C(byte *arg0,byte *arg1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 2;
  do {
    bVar1 = *arg0;
    *arg1 = bVar1 >> 4;
    arg1[1] = bVar1 & 0xf;
    arg0 = arg0 + 1;
    arg1 = arg1 + 2;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return;
}


// sub_080BF468 @ 0x080BF468

void sub_080BF468(uint arg0,int arg1,uint *arg2)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  
  if ((arg0 & 0x8000) != 0) {
    arg0 = arg0 & 0xff;
  }
  if ((int)arg0 < 0x80) {
    pbVar1 = (byte *)sub_080BF32C(arg0 & 0xffff);
    switch(arg1) {
    case 0:
switchD_080bf49a_caseD_0:
      uVar3 = *pbVar1 & 0xf0;
      goto LAB_080bf5b6;
    case 1:
switchD_080bf49a_caseD_1:
      uVar3 = *pbVar1 & 0xf;
      goto LAB_080bf5b6;
    case 2:
switchD_080bf49a_caseD_2:
      uVar3 = (uint)pbVar1[1];
      goto LAB_080bf5b6;
    case 3:
switchD_080bf49a_caseD_3:
      uVar3 = (uint)pbVar1[2];
      goto LAB_080bf5b6;
    case 4:
switchD_080bf49a_caseD_4:
      uVar3 = (uint)pbVar1[3];
      goto LAB_080bf5b6;
    case 5:
      pbVar1 = pbVar1 + 4;
LAB_080bf5a6:
      sub_080BF43C(pbVar1,arg2);
      return;
    case 6:
switchD_080bf49a_caseD_6:
      uVar3 = (uint)*(ushort *)(pbVar1 + 8);
      goto LAB_080bf5b6;
    case 7:
      uVar3 = (uint)pbVar1[0xb];
      goto LAB_080bf5b6;
    }
  }
  else if ((int)arg0 < 0xd0) {
    pbVar1 = (byte *)Equipment_GetRecord36_MidRange(arg0 & 0xffff);
    switch(arg1) {
    case 0:
      goto switchD_080bf49a_caseD_0;
    case 1:
      goto switchD_080bf49a_caseD_1;
    case 5:
      pbVar1 = pbVar1 + 4;
      goto LAB_080bf5a6;
    case 6:
      goto switchD_080bf49a_caseD_6;
    case 7:
      goto switchD_080bf49a_caseD_4;
    case 8:
      goto switchD_080bf49a_caseD_2;
    case 9:
      goto switchD_080bf49a_caseD_3;
    }
  }
  else {
    pbVar1 = (byte *)Action_GetRecord(arg0 & 0xffff);
    if (arg1 - 1U < 0xd) {
      uVar2 = *(uint *)((arg1 - 1U) * 4 + 0x80bf540);
      switch(arg1) {
      case 1:
        goto switchD_080bf49a_caseD_1;
      default:
        goto switchD_080bf49a_default;
      case 5:
        pbVar1 = pbVar1 + 1;
        goto LAB_080bf5a6;
      case 10:
        goto switchD_080bf49a_caseD_0;
      case 0xb:
        uVar3 = (uint)(char)pbVar1[1];
        break;
      case 0xc:
        uVar3 = (uint)pbVar1[2];
        if (arg0 == 0xf0) {
          sub_080F6278();
        }
        else {
          if (arg0 != 0xf8) break;
          uVar2 = sub_080F6390();
        }
        uVar3 = uVar2 & 0xffff;
        break;
      case 0xd:
        goto switchD_080bf49a_caseD_4;
      }
      goto LAB_080bf5b6;
    }
  }
switchD_080bf49a_default:
  uVar3 = 0xffffffff;
LAB_080bf5b6:
  *arg2 = uVar3;
  return;
}


// sub_080BF5C0 @ 0x080BF5C0

int sub_080BF5C0(uint arg0)

{
  return (arg0 & 0xffff) * 0x1c + 0x819b9f4;
}


// sub_080BF5D8 @ 0x080BF5D8

void sub_080BF5D8(uint arg0,uint arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  uint in_stack_00000004;
  
  iVar2 = sub_080BF5C0(arg0 & 0xffff);
  puVar3 = (ushort *)(iVar2 + 6);
  uVar4 = 0;
  uVar1 = *(ushort *)(iVar2 + 6);
  while( true ) {
    if (uVar1 == 0) {
      return;
    }
    FontSprite_DrawGlyph((uint)*puVar3,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
    puVar3 = puVar3 + 1;
    arg3 = (arg3 & 0xffff) + (in_stack_00000004 & 0xffff);
    uVar4 = uVar4 + 1;
    if (7 < uVar4) break;
    uVar1 = *puVar3;
  }
  return;
}


// sub_080BF648 @ 0x080BF648

undefined * sub_080BF648(uint arg0)

{
  undefined *puVar1;
  dword arg0_00;
  uint uVar2;
  int arg0_01;
  
  uVar2 = arg0 & 0xffff;
  arg0_01 = uVar2 * 0x60 + 0x819cb74;
  CpuSet(arg0_01,0x3005fc0,0x4000018);
  if (((uVar2 == 0x106) || (uVar2 == 0x109)) || (uVar2 == 0x10c)) {
    Combatant_DecodeName(0x30050c8,0x3005fe2);
    puVar1 = &DAT_03005fc0;
  }
  else {
    if (uVar2 == 0x108) {
      arg0_00 = 0x30050d0;
    }
    else {
      if (uVar2 != 0x10e) {
        return (undefined *)arg0_01;
      }
      arg0_00 = 0x30050c0;
    }
    Combatant_DecodeName(arg0_00,&DAT_03005fe2);
    puVar1 = (undefined *)0x3005fc0;
  }
  return puVar1;
}


// sub_080BF6D4 @ 0x080BF6D4

void sub_080BF6D4(uint arg0,uint arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  uint in_stack_00000004;
  
  iVar2 = sub_080BF648(arg0 & 0xffff);
  puVar3 = (ushort *)(iVar2 + 0x22);
  uVar4 = 0;
  uVar1 = *(ushort *)(iVar2 + 0x22);
  while( true ) {
    if (uVar1 == 0) {
      return;
    }
    FontSprite_DrawGlyph((uint)*puVar3,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
    puVar3 = puVar3 + 1;
    arg3 = (arg3 & 0xffff) + (in_stack_00000004 & 0xffff);
    uVar4 = uVar4 + 1;
    if (7 < uVar4) break;
    uVar1 = *puVar3;
  }
  return;
}


// sub_080BF748 @ 0x080BF748

void sub_080BF748(undefined1 *arg0,int arg1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  dword dVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_14;
  
  local_14 = 0;
  REG_DMA3SAD = &local_14;
  REG_DMA3DAD = arg0;
  REG_DMA3CNT = 0x85000020;
  uVar1 = REG_DMA3CNT;
  iVar5 = arg1 * 8;
  *arg0 = *(undefined1 *)(iVar5 + 0x81a5a00);
  arg0[1] = (&DAT_081a5a01)[iVar5];
  arg0[2] = (&DAT_081a5a02)[iVar5];
  arg0[3] = (&DAT_081a5a03)[iVar5];
  arg0[4] = (&DAT_081a5a04)[iVar5];
  arg0[5] = (&DAT_081a5a05)[iVar5];
  arg0[6] = (&DAT_081a5a06)[iVar5];
  arg0[7] = (&DAT_081a5a07)[iVar5];
  if (arg1 == 0) {
    arg0[0xd] = 6;
    *(undefined4 *)(arg0 + 8) = 0x15e;
    arg0[0x28] = 6;
    arg0[0x29] = 5;
    arg0[0x2a] = 4;
    arg0[0x2b] = 6;
    arg0[0x2c] = 6;
    uVar2 = 3;
  }
  else {
    if (arg1 == 1) {
      uVar6 = sub_080C2244();
      puVar4 = (undefined1 *)((uVar6 & 3) * 6 + 0x81a5a20);
      arg0[0xd] = 0x12;
      dVar3 = 0x25da;
    }
    else {
      uVar6 = sub_080C2244();
      puVar4 = (undefined1 *)((uVar6 & 3) * 6 + 0x81a5a38);
      arg0[0xd] = 0x18;
      dVar3 = 23000;
    }
    *(dword *)(arg0 + 8) = dVar3;
    arg0[0x28] = *puVar4;
    arg0[0x29] = puVar4[1];
    arg0[0x2a] = puVar4[2];
    arg0[0x2b] = puVar4[3];
    arg0[0x2c] = puVar4[4];
    uVar2 = puVar4[5];
  }
  arg0[0x2d] = uVar2;
  *(undefined4 *)(arg0 + 0x40) = *(undefined4 *)(arg0 + 0x28);
  *(undefined4 *)(arg0 + 0x44) = *(undefined4 *)(arg0 + 0x2c);
  arg0[0x21] = 0xff;
  arg0[0x20] = 0xff;
  arg0[0x23] = 0xff;
  arg0[0x22] = 0xff;
  arg0[0x25] = 0xff;
  arg0[0x24] = 0xff;
  arg0[0x26] = 0xff;
  arg0[0xc] = (char)arg1;
  uVar6 = 0;
  do {
    arg0[uVar6 + 0x5d] = 0xff;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x20);
  sub_080F4260((uint)(byte)arg0[0xc]);
  if (arg1 < 4) {
    *(ushort *)(arg0 + 0x14) = (ushort)*(byte *)(arg1 + 0x81a59fc);
    *(undefined2 *)(arg0 + 0x58) = *(undefined2 *)(arg1 * 2 + 0x81a59f4);
    *(short *)(arg0 + 0x12) = (short)arg1 + -0x8000;
  }
  return;
}


// sub_080BF8D8 @ 0x080BF8D8

void sub_080BF8D8(int arg0)

{
  byte *pbVar1;
  int arg1;
  
  arg1 = 0;
  pbVar1 = (byte *)(arg0 * 7 + 0x81a5a50);
  do {
    sub_080C0074(arg0,arg1,(uint)*pbVar1);
    pbVar1 = pbVar1 + 1;
    arg1 = arg1 + 1;
  } while (arg1 < 7);
  sub_080BF938(arg0);
  return;
}


