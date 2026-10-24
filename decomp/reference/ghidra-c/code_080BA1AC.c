/* Ghidra decompilation of asm/code_080BA1AC.s (reference only; not compiled). */

// sub_080BA1AC @ 0x080BA1AC

void sub_080BA1AC(void)

{
  DisplayList_Add(0x80ba171,1);
  return;
}


// sub_080BA1C0 @ 0x080BA1C0

void sub_080BA1C0(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_03003fc0;
  DAT_03003fc0 = 0x2001000;
  _call_via_r1(0x8173578,0x3004011);
  DAT_03003fc0 = uVar1;
  DisplayList_Add(0x80b2881,1);
  return;
}


// sub_080BA1F8 @ 0x080BA1F8

void sub_080BA1F8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BA21C @ 0x080BA21C

void sub_080BA21C(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x8165ad4,0x2001000,in_r2);
  LZ77UnCompWram(0x81660d4,&DAT_02002000,in_r2);
  DisplayList_Add(0x80ba1f9,1);
  sub_080ACFCC(3,0x8165a54,0x3002b70,0x40);
  sub_080ACFCC(3,0x8165a94,&DAT_03002b50,0x20);
  sub_080ACFCC(3,0x8165ab4,&DAT_03002d50,0x20);
  sub_080ACFCC(3,0x8165a94,&DAT_03002d70,0x20);
  DAT_0300452c = sub_080AB090(0xd0,0x30,1,0x8001);
  sub_080AAFBC(0x1d0,0x20,1);
  return;
}


// sub_080BA2D8 @ 0x080BA2D8

void sub_080BA2D8(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B1A1C((uint)DAT_03004552);
  DAT_03004552 = (short)uVar1;
  return;
}


// sub_080BA2F0 @ 0x080BA2F0

void sub_080BA2F0(int arg0)

{
  if (*(short *)(arg0 + 0x54) != -0x8000) {
    sub_080AA184(0x8002d08,9,0xe,3);
    sub_080AA184(0x8002d44,9,0xe,3);
  }
  if (*(short *)(arg0 + 0x56) != -0x8000) {
    sub_080AA184(0x8002cac,9,0xd,3);
    sub_080AA184(0x8002c88,9,0xd,3);
    sub_080AA184(0x8002c70,9,0xd,3);
    sub_080B29A8(0);
  }
  return;
}


// sub_080BA3B4 @ 0x080BA3B4

void sub_080BA3B4(int arg0)

{
  *(short *)(arg0 + 0x54) = *(short *)(arg0 + 0x54) + 2;
  return;
}


// sub_080BA3C0 @ 0x080BA3C0

void sub_080BA3C0(int arg0)

{
  *(undefined2 *)(arg0 + 0x54) = 0x8000;
  *(undefined2 *)(arg0 + 0x56) = 0;
  return;
}


// sub_080BA3D0 @ 0x080BA3D0

void sub_080BA3D0(int arg0)

{
  *(short *)(arg0 + 0x56) = *(short *)(arg0 + 0x56) + 2;
  return;
}


// sub_080BA3DC @ 0x080BA3DC

void sub_080BA3DC(void)

{
  DisplayList_Add(0x80adf65,1);
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x3f;
  return;
}


// sub_080BA408 @ 0x080BA408

void sub_080BA408(int arg0)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  code *UNRECOVERED_JUMPTABLE;
  short local_1c;
  short local_1a;
  
  iVar2 = sub_080C8B10((uint)(ushort)DAT_03004614,
                       (uint)*(ushort *)(arg0 + 0x44 + *(int *)(arg0 + 0x2c) * 2));
  iVar3 = sub_080C8B10((uint)(ushort)DAT_03004614,
                       (uint)*(ushort *)(arg0 + 0x44 + *(int *)(arg0 + 0x30) * 2));
  sVar4 = *(short *)(iVar3 + 6);
  sVar1 = *(short *)(iVar2 + 6);
  if (*(short *)(iVar2 + 6) < 0) {
    sVar1 = -*(short *)(iVar2 + 6);
  }
  if (sVar4 < 0) {
    sVar4 = -sVar4;
  }
  *(undefined4 *)(arg0 + 0x58) = 0;
  *(undefined2 *)(arg0 + 0x5c) = 0;
  sub_080C1F50((uint)DAT_03004562,(uint)DAT_03004564,&local_1c,&local_1a);
  if ((local_1c == 0x40) && (local_1a == 0xc)) {
    sVar4 = sVar1 - sVar4;
    sVar1 = 0xa8;
  }
  else {
    if (sVar4 < sVar1) {
      sVar1 = sVar1 - sVar4;
    }
    else {
      sVar1 = sVar4 - sVar1;
    }
    sVar4 = 0xa8;
  }
  *(short *)(arg0 + 0x5e) = sVar4 * sVar1;
                    /* WARNING: Could not recover jumptable at 0x080ba4c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BA4C4 @ 0x080BA4C4

void sub_080BA4C4(int arg0)

{
  undefined4 uVar1;
  short local_10;
  short local_e;
  
  sub_080C1F50((uint)DAT_03004562,(uint)DAT_03004564,&local_10,&local_e);
  if (((local_10 == 0x40) && (local_e == 0xc)) ||
     (*(uint *)(arg0 + 0x30) < (uint)*(ushort *)(arg0 + 0x44 + *(int *)(arg0 + 0x2c) * 2))) {
    uVar1 = __umodsi3((uint)*(ushort *)(arg0 + 0x5c),0xa8);
    DAT_0300000e = 0xa8 - ((ushort)uVar1 & 0xff);
  }
  else {
    uVar1 = __umodsi3((uint)*(ushort *)(arg0 + 0x5c),0xa8);
    DAT_0300000e = (ushort)uVar1 & 0xff;
  }
  return;
}


// sub_080BA538 @ 0x080BA538

void sub_080BA538(int arg0)

{
  uint uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar1 = *(int *)(arg0 + 0x58) + 0x1000;
  *(uint *)(arg0 + 0x58) = uVar1;
  if (8 < uVar1 >> 0x10) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  *(short *)(arg0 + 0x5c) = *(short *)(arg0 + 0x5c) + *(short *)(arg0 + 0x5a);
  sub_080BA4C4(arg0);
  return;
}


// sub_080BA56C @ 0x080BA56C

void sub_080BA56C(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(short *)(arg0 + 0x5c) = *(short *)(arg0 + 0x5c) + *(short *)(arg0 + 0x5a);
  sub_080BA4C4(arg0);
  if ((int)((uint)*(ushort *)(arg0 + 0x5e) - (uint)(*(ushort *)(arg0 + 0x5e) >> 4)) <
      (int)(uint)*(ushort *)(arg0 + 0x5c)) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080BA59C @ 0x080BA59C

void sub_080BA59C(int arg0)

{
  ushort uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (2 < *(uint *)(arg0 + 0x58) >> 0x10) {
    *(uint *)(arg0 + 0x58) = *(uint *)(arg0 + 0x58) - 0x1000;
  }
  uVar1 = *(short *)(arg0 + 0x5c) + *(short *)(arg0 + 0x5a);
  *(ushort *)(arg0 + 0x5c) = uVar1;
  if (*(ushort *)(arg0 + 0x5e) < uVar1) {
    *(ushort *)(arg0 + 0x5c) = *(ushort *)(arg0 + 0x5e);
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  sub_080BA4C4(arg0);
  return;
}


// sub_080BA5E0 @ 0x080BA5E0

undefined4 sub_080BA5E0(undefined4 arg0,undefined4 arg1)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  
  if (DAT_03004552 == 1) {
    if (0 < (short)arg0) {
      return 0;
    }
    uVar3 = DAT_03004562 - (short)arg1;
    sVar1 = DAT_03004564 + (short)arg0;
  }
  else {
    sVar1 = DAT_03004564;
    uVar3 = DAT_03004562;
    if (DAT_03004552 < 2) {
      if (DAT_03004552 == 0) {
        uVar3 = DAT_03004562 + (short)arg0;
        sVar1 = DAT_03004564 + (short)arg1;
      }
    }
    else if (DAT_03004552 == 2) {
      if ((short)arg1 < 0) {
        return 0;
      }
      uVar3 = DAT_03004562 - (short)arg0;
      sVar1 = DAT_03004564 - (short)arg1;
    }
    else if (DAT_03004552 == 3) {
      if ((short)arg0 < 0) {
        return 0;
      }
      uVar3 = DAT_03004562 + (short)arg1;
      sVar1 = DAT_03004564 - (short)arg0;
    }
  }
  if (((uVar3 < 3) && (iVar2 = (int)sVar1, -1 < iVar2)) && (iVar2 < 0xd)) {
    return (uint)*(ushort *)(((int)((uint)uVar3 << 0x10) >> 0xf) + iVar2 * 8 + 0x817417c);
  }
  return 0;
}


// sub_080BA6B4 @ 0x080BA6B4

undefined4 sub_080BA6B4(undefined4 arg0)

{
  undefined4 uVar1;
  int iVar2;
  dword unaff_r4;
  int *piVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((short)arg0 == 0) || ((short)arg0 == 3)) {
    unaff_r4 = 0x8173d04;
  }
  else if ((short)arg0 == 1) {
    unaff_r4 = 0x8173fbc;
  }
  else if (((short)arg0 == 2) && (unaff_r4 = 0x8174144, DAT_03004558 == -1)) {
    unaff_r4 = 0x817410c;
  }
  piVar3 = (int *)(unaff_r4 + (uint)DAT_0300455e * 8 + -8);
  if (*piVar3 == 0) {
    DAT_0300455e = 0;
    DisplayList_Add(0x80b2881,1);
    uVar1 = 1;
  }
  else {
    DAT_0300455e = DAT_0300455e + 1;
    iVar2 = sub_080BA5E0((int)(short)piVar3[1],(int)*(short *)((int)piVar3 + 6));
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      _call_via_r5();
      uVar1 = 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080ba754. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar1;
}


// sub_080BA758 @ 0x080BA758

void sub_080BA758(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = DAT_03004638 * 0x20 + 0x6004000;
  REG_DMA3CNT = 0x840000e0;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6003800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BA7A0 @ 0x080BA7A0

void sub_080BA7A0(int arg0)

{
  undefined4 in_r2;
  
  if (arg0 == 0) {
    LZ77UnCompWram(0x8182270,0x2000000,in_r2);
  }
  else {
    LZ77UnCompWram(0x8182688,0x2000000,in_r2);
  }
  return;
}


// sub_080BA7CC @ 0x080BA7CC

void sub_080BA7CC(int arg0,int arg1,uint arg2,int arg3)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  short *psVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  ushort *puVar9;
  byte *pbVar10;
  int in_stack_00000000;
  
  uVar8 = (-(uint)DAT_0300000e & 0xffff) >> 3;
  uVar6 = (arg3 - uVar8) - 1;
  uVar3 = uVar6 & 0xffff;
  if ((int)(uVar6 * 0x10000) < 0) {
    uVar3 = 0;
  }
  pbVar10 = (byte *)(arg1 + arg2 * uVar3);
  LZ77UnCompWram(*(undefined4 *)(uVar3 * 4 + arg0),0x200afc8,arg2);
  iVar4 = 0x1f - uVar8;
  if (in_stack_00000000 == 0) {
    uVar3 = 0;
    if (arg2 != 0) {
      psVar5 = &DAT_02000002 + iVar4 * 0x20;
      do {
        bVar1 = *pbVar10;
        pbVar10 = pbVar10 + 1;
        *psVar5 = ((bVar1 & 0xf) + 8) * 0x1000 + *psVar5;
        psVar5 = psVar5 + 1;
        uVar3 = uVar3 + 1;
      } while (uVar3 < arg2);
    }
  }
  else {
    uVar3 = 0;
    if (arg2 != 0) {
      puVar9 = &DAT_02000002 + iVar4 * 0x20;
      puVar7 = (ushort *)((iVar4 * 0x20 + 0x1c) * 2 + 0x2000000);
      do {
        bVar1 = *pbVar10;
        pbVar10 = pbVar10 + 1;
        sVar2 = ((bVar1 & 0xf) + 8) * 0x1000;
        *puVar9 = (*puVar9 & 0xfff) + sVar2;
        *puVar7 = (*puVar7 & 0xfff) + sVar2;
        puVar7 = puVar7 + -1;
        puVar9 = puVar9 + 1;
        uVar3 = uVar3 + 1;
      } while (uVar3 < arg2);
    }
  }
  DAT_03004638 = *(undefined4 *)((0x1f - uVar8) * 4 + 0x8182aa0);
  DisplayList_Add(0x80ba759,1);
  return;
}


// sub_080BA8D8 @ 0x080BA8D8

void sub_080BA8D8(undefined4 arg0,uint arg1)

{
  dword dVar1;
  int arg0_00;
  
  if ((short)arg0 == 0) {
    dVar1 = 0x8182b20;
  }
  else {
    dVar1 = 0x8182b54;
  }
  arg0_00 = *(int *)((arg1 & 0xffff) * 4 + dVar1);
  if (arg0_00 == 0) {
    DAT_0300463c = 0;
  }
  else {
    DAT_0300463c = sub_080AD0FC(arg0_00,0xffff);
  }
  return;
}


// sub_080BA920 @ 0x080BA920

undefined4 sub_080BA920(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((DAT_0300463c == (short *)0x0) || (*DAT_0300463c == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}


// sub_080BA940 @ 0x080BA940

void sub_080BA940(void)

{
  if (DAT_0300463c != (undefined2 *)0x0) {
    *DAT_0300463c = 0;
    DAT_0300463c = (undefined2 *)0x0;
  }
  return;
}


// sub_080BA958 @ 0x080BA958

void sub_080BA958(undefined4 arg0,undefined4 arg1)

{
  if (((short)arg0 == 0) && ((short)arg1 == 2)) {
    if ((DAT_0200ab04 & 0x8000) == 0) {
      DisplayList_Add(0x80b2881,1);
    }
    DAT_0300000e = *(undefined2 *)(DAT_0300463c + 0x24);
  }
  sub_080BA940();
  return;
}


// sub_080BA9A0 @ 0x080BA9A0

void sub_080BA9A0(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B6DB4(0x1c);
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  return;
}


// sub_080BA9B4 @ 0x080BA9B4

void sub_080BA9B4(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(ushort *)(arg0 + 0x1c) = (ushort)(**(short **)(arg0 + 0x24) == 0);
                    /* WARNING: Could not recover jumptable at 0x080ba9ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BA9CC @ 0x080BA9CC

void sub_080BA9CC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x600e000;
  REG_DMA3CNT = 0x84000300;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BA9F0 @ 0x080BA9F0

void sub_080BA9F0(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x8182f4c,0x2001000,in_r2);
  DisplayList_Add(0x80ba9cd,1);
  return;
}


// sub_080BAA14 @ 0x080BAA14

void sub_080BAA14(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x81831b4,0x2001000,in_r2);
  DisplayList_Add(0x80ba9cd,1);
  return;
}


// sub_080BAA38 @ 0x080BAA38

void sub_080BAA38(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BAA5C @ 0x080BAA5C

void sub_080BAA5C(void)

{
  undefined4 local_c;
  
  local_c = 0;
  CpuSet(&local_c,0x2000000,0x5000400);
  DisplayList_Add(0x80baa39,1);
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x3f;
  DAT_03000006 = 0;
  return;
}


// sub_080BAAAC @ 0x080BAAAC

void sub_080BAAAC(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x8183474,0x200bfc8,in_r2);
  sub_080AB250(0x200bfc8,0x2000000,0x300,7);
  sub_080ACFCC(3,0x8183454,0x3002a90,0x20);
  sub_080AB090(0x70,0x10,1,1);
  DisplayList_Add(0x80baa39,1);
  DAT_03000006 = 0x78;
  DAT_03000030 = 0xe8;
  DAT_03000031 = 8;
  DAT_03000034 = 0xe0;
  DAT_03000035 = 0x68;
  DAT_03000038 = 0x3d;
  return;
}


// sub_080BAB54 @ 0x080BAB54

void sub_080BAB54(undefined4 arg0,undefined4 arg1)

{
  DAT_03000006 = DAT_03000006 + (short)arg1;
  if ((DAT_030031bc >> 3 & 1) == 0) {
    sub_080BA9F0();
  }
  else {
    sub_080BAA14();
  }
  return;
}


// sub_080BAB8C @ 0x080BAB8C

void sub_080BAB8C(undefined4 arg0,undefined4 arg1)

{
  DAT_03000006 = (undefined2)arg1;
  return;
}


// sub_080BAB98 @ 0x080BAB98

void sub_080BAB98(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BABBC @ 0x080BABBC

void sub_080BABBC(int arg0)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x8182cc4,0x2001000,in_r2);
  DisplayList_Add(0x80bab99,1);
  sub_080ACFCC(3,0x8183434,0x3002d50,0x20);
  sub_080AB090(0x1d0,0x10,1,1);
  DisplayList_Add(0x80bab99,1);
  *(undefined2 *)(arg0 + 0x28) = 0x30;
  return;
}


// sub_080BAC1C @ 0x080BAC1C

void sub_080BAC1C(undefined4 arg0)

{
  if ((DAT_030031bc >> 3 & 1) == 0) {
    sub_080AA184(0x800781c,0,0xd,3);
    sub_080AA184(0x800781c,0,0xd,3);
  }
  else {
    sub_080AA184(0x8007844,0,0xd,3);
    sub_080AA184(0x8007844,0,0xd,3);
  }
  return;
}


// sub_080BACB8 @ 0x080BACB8

void sub_080BACB8(int arg0,undefined4 arg1)

{
  *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) + (short)arg1;
  return;
}


// sub_080BACC4 @ 0x080BACC4

void sub_080BACC4(void)

{
  REG_BG1CNT = 0x4209;
  return;
}


// sub_080BACD8 @ 0x080BACD8

void sub_080BACD8(void)

{
  DAT_03000030 = 8;
  DAT_03000031 = 0;
  DAT_03000034 = 0x68;
  DAT_03000035 = 0;
  DAT_03000038 = 0x3d;
  DisplayList_Add(0x80bacc5,1);
  DAT_03000004 = DAT_03000004 + 1;
  return;
}


// sub_080BAD28 @ 0x080BAD28

void sub_080BAD28(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x85000200;
  uVar1 = REG_DMA3CNT;
  REG_BG1CNT = 0x8209;
  return;
}


// sub_080BAD5C @ 0x080BAD5C

void sub_080BAD5C(undefined4 arg0,int arg1)

{
  if (arg1 == 0) {
    DisplayList_Add(0x80bad29,1);
  }
  else {
    DAT_03000004 = 0;
    DAT_03000038 = 0x3f;
  }
  return;
}


// sub_080BAD88 @ 0x080BAD88

void sub_080BAD88(undefined4 arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  piVar2 = (int *)0x2036094;
  do {
    iVar1 = *piVar2;
    if ((iVar1 != 0) && (*(ushort *)(iVar1 + 0x2a) == arg1)) {
      *(short *)(iVar1 + 0x2c) = *(short *)(iVar1 + 0x2c) + (short)arg2;
      *(short *)(iVar1 + 0x2e) = *(short *)(iVar1 + 0x2e) + (short)arg3;
    }
    piVar2 = piVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  return;
}


// sub_080BADC4 @ 0x080BADC4

void sub_080BADC4(void)

{
  int arg0;
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  piVar1 = (int *)0x2036094;
  do {
    arg0 = *piVar1;
    if ((arg0 != 0) && (*(short *)(arg0 + 0x2a) == 0x157)) {
      sub_080C48F0(arg0);
    }
    piVar1 = piVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  return;
}


// sub_080BADF8 @ 0x080BADF8

void sub_080BADF8(undefined4 arg0,undefined4 arg1)

{
  if (DAT_02036094 != 0) {
    *(undefined2 *)(DAT_02036094 + 0x1e) = (undefined2)arg1;
  }
  return;
}


// sub_080BAE0C @ 0x080BAE0C

void sub_080BAE0C(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_02036094 == 0);
  return;
}


// sub_080BAE28 @ 0x080BAE28

void sub_080BAE28(void)

{
  sub_080AB91C(DAT_03006968,1);
  DAT_03006968 = 0;
  DAT_0203db6c = 0;
  return;
}


// sub_080BAE4C @ 0x080BAE4C

void sub_080BAE4C(int arg0,undefined4 arg1)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B6DB4(arg1);
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  return;
}


// sub_080BAE60 @ 0x080BAE60

void sub_080BAE60(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(ushort *)(arg0 + 0x1c) = (ushort)(**(short **)(arg0 + 0x24) == 0);
                    /* WARNING: Could not recover jumptable at 0x080bae76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BAE78 @ 0x080BAE78

void sub_080BAE78(undefined4 arg0,uint arg1,uint arg2,uint arg3)

{
  uint in_stack_00000000;
  
  sub_080C4618(arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff,in_stack_00000000 & 0xffff);
  return;
}


// sub_080BAEA8 @ 0x080BAEA8

void sub_080BAEA8(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080BC230(400);
  *(ushort *)(arg0 + 0x1c) = (ushort)(*(int *)(iVar1 + 0xc) == -1);
                    /* WARNING: Could not recover jumptable at 0x080baeca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BAECC @ 0x080BAECC

void sub_080BAECC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6013000;
  REG_DMA3CNT = 0x84000700;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BAEF0 @ 0x080BAEF0

void sub_080BAEF0(void)

{
  int iVar1;
  undefined4 in_r2;
  
  LZ77UnCompWram(0x81839f4,0x2001000,in_r2);
  LZ77UnCompWram(0x81845e4,&DAT_02002000,in_r2);
  iVar1 = sub_080B098C();
  if (iVar1 == 0) {
    sub_080ACFCC(3,0x8184ba4,0x3003190,0x20);
    sub_080AABB0();
  }
  else {
    sub_080ACFCC(3,0x8184ba4,0x3002d90,0x20);
    sub_080AB090(0x1f0,0x10,1,1);
  }
  DisplayList_Add(0x80baecd,1);
  return;
}


// sub_080BAF7C @ 0x080BAF7C

void sub_080BAF7C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x600e000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BAFB8 @ 0x080BAFB8

void sub_080BAFB8(undefined4 arg0,int arg1)

{
  undefined4 uVar1;
  undefined4 in_r2;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack_14;
  
  if (arg1 == 1) {
    LZ77UnCompWram(0x818596c,0x2002000,in_r2);
  }
  else if (arg1 == 0) {
    LZ77UnCompWram(0x8184bc4,0x2001000,in_r2);
  }
  else if (arg1 == 2) {
    uStack_14 = 0;
    REG_DMA3SAD = &uStack_14;
    REG_DMA3DAD = 0x2000000;
    REG_DMA3CNT = 0x85000400;
    uVar1 = REG_DMA3CNT;
    LZ77UnCompWram(0x8186524,0x200bfc8,in_r2);
    sub_080AB250(0x200bfc8,0x2000000,0x300,7);
  }
  else if (arg1 == 3) {
    DisplayList_Add(0x80baf7d,1);
    DAT_03000006 = 0xa8;
    DAT_03000030 = 0xe8;
    DAT_03000031 = 8;
    DAT_03000034 = 0xe0;
    DAT_03000035 = 0x68;
    DAT_03000038 = 0x3d;
  }
                    /* WARNING: Could not recover jumptable at 0x080bb076. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BB094 @ 0x080BB094

void sub_080BB094(undefined4 arg0,int arg1)

{
  undefined2 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    sub_080C7C60();
  }
  else {
    if (arg1 == 1) {
      DAT_03000040 = 0x3c40;
      uVar1 = 0x820b;
    }
    else {
      sub_080C1440();
      DAT_03000006 = 0;
      uVar1 = 0x8209;
    }
    REG_BG1CNT = uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x080bb0d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BB0E4 @ 0x080BB0E4

void sub_080BB0E4(int arg0)

{
  ushort uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031bc & 7) == 0) {
    if (DAT_0300000e == 0) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    else {
      DAT_0300000e = DAT_0300000e + -1;
    }
  }
  if ((*(short *)(arg0 + 0x1c) == 0) && ((DAT_030031bc & 3) == 0)) {
    DAT_03000006 = DAT_03000006 + -1;
    uVar1 = *(short *)(arg0 + 0x28) + 1;
    *(ushort *)(arg0 + 0x28) = uVar1;
    if (0x38 < uVar1) {
      *(undefined4 *)(arg0 + 0x20) = 0;
    }
  }
  return;
}


// sub_080BB14C @ 0x080BB14C

void sub_080BB14C(void)

{
  int iVar1;
  
  iVar1 = sub_080BC230(0x162);
  *(short *)(iVar1 + 0x2e) = *(short *)(iVar1 + 0x2e) + -1;
  return;
}


// sub_080BB164 @ 0x080BB164

void sub_080BB164(int arg0)

{
  int iVar1;
  uint arg0_00;
  
  sub_080BC230(0x162);
  if ((DAT_030031bc & 3) == 0) {
    arg0_00 = 0;
    iVar1 = DAT_02036094;
    while ((iVar1 != 0 && (arg0_00 = arg0_00 + 1 & 0xffff, arg0_00 < 6))) {
      iVar1 = *(int *)(arg0_00 * 4 + 0x2036094);
    }
    if (arg0_00 != 6) {
      iVar1 = sub_080C2244();
      sub_080C4618(arg0_00,0x177,iVar1 + 0x40U & 0x7f,*(ushort *)(arg0 + 0x28) + 0xe & 0xffff);
    }
  }
  return;
}


// sub_080BB1DC @ 0x080BB1DC

void sub_080BB1DC(void)

{
  sub_080AB0F0(0x1e0,0x10,1);
  return;
}


// sub_080BB1F0 @ 0x080BB1F0

void sub_080BB1F0(void)

{
  DAT_0300000e = 0;
  DAT_03000006 = 0xffd8;
  return;
}


// sub_080BB20C @ 0x080BB20C

void sub_080BB20C(int arg0)

{
  *(undefined2 *)(arg0 + 0x28) = 0x73;
  *(undefined2 *)(arg0 + 0x2a) = 6;
  return;
}


// sub_080BB218 @ 0x080BB218

void sub_080BB218(int arg0,uint arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  uVar1 = sub_080C4618(0,arg1 & 0xffff,(uint)*(ushort *)(arg0 + 0x28),(uint)*(ushort *)(arg0 + 0x2a)
                      );
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) - (short)arg2;
  return;
}


// sub_080BB248 @ 0x080BB248

void sub_080BB248(int arg0,undefined4 arg1)

{
  *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) - (short)arg1;
  sub_080C48CC(*(undefined4 *)(arg0 + 0x24),(uint)*(ushort *)(arg0 + 0x28),
               (uint)*(ushort *)(arg0 + 0x2a));
  return;
}


// sub_080BB264 @ 0x080BB264

void sub_080BB264(int arg0)

{
  sub_080C48F0(*(undefined4 *)(arg0 + 0x24));
  return;
}


// sub_080BB274 @ 0x080BB274

void sub_080BB274(undefined4 arg0,int arg1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 1) {
    sub_080C2364(0x102);
    sub_080C2364(0x106);
  }
  else {
    sub_080C23BC(0x102);
    sub_080C23BC(0x106);
  }
                    /* WARNING: Could not recover jumptable at 0x080bb29e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BB2A0 @ 0x080BB2A0

void sub_080BB2A0(void)

{
  if ((DAT_0200ab04 & 0x8000) == 0) {
    sub_080AB008(0x80,0x80,2);
    sub_080AB008(0x1d0,0x30,2);
  }
  else {
    sub_080AB008(0x80,0x80,2);
    sub_080AB008(0x1d0,0x30,2);
  }
  return;
}


// sub_080BB2E8 @ 0x080BB2E8

void sub_080BB2E8(void)

{
  sub_080AB138(0x80,0x80,1,0x20);
  sub_080AB138(0x1d0,0x30,1,0x20);
  return;
}


// sub_080BB308 @ 0x080BB308

void sub_080BB308(void)

{
  sub_080C2364(0x105);
  return;
}


// sub_080BB318 @ 0x080BB318

void sub_080BB318(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6013000;
  REG_DMA3CNT = 0x84001200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BB33C @ 0x080BB33C

void sub_080BB33C(int arg0)

{
  undefined4 in_r2;
  undefined4 arg2;
  
  LZ77UnCompWram(0x8186eb0,0x2001000,in_r2);
  LZ77UnCompWram(0x81873fc,&DAT_02001c00,0xc00);
  arg2 = 0x2000;
  LZ77UnCompWram(0x8187d00,&DAT_02003000,0x2000);
  LZ77UnCompWram(0x81892c8,&DAT_02005000,arg2);
  sub_080ACFCC(3,0x8189434,0x3002d30,0x20);
  sub_080ACFCC(3,0x8189454,&DAT_03002d50,0x20);
  sub_080ACFCC(3,0x8189474,&DAT_03002d70,0x20);
  sub_080ACFCC(3,0x8189494,&DAT_03002d90,0x20);
  sub_080AB090(0x1c0,0x40,1,1);
  DisplayList_Add(0x80bb319,1);
  *(undefined2 *)(arg0 + 0x24) = 1;
  *(undefined2 *)(arg0 + 0x26) = 0x100;
  *(undefined2 *)(arg0 + 0x28) = 0x100;
  *(undefined2 *)(arg0 + 0x2a) = 0;
  *(undefined2 *)(arg0 + 0x36) = 1;
  *(undefined2 *)(arg0 + 0x38) = 0x20;
  *(undefined2 *)(arg0 + 0x3a) = 0x20;
  *(undefined2 *)(arg0 + 0x3c) = 0;
  *(undefined2 *)(arg0 + 0x2c) = 0;
  *(undefined2 *)(arg0 + 0x2e) = 0;
  *(undefined2 *)(arg0 + 0x32) = 0;
  *(undefined2 *)(arg0 + 0x40) = 0;
  *(undefined2 *)(arg0 + 0x44) = 0;
  *(undefined2 *)(arg0 + 0x3e) = 0;
  return;
}


// sub_080BB430 @ 0x080BB430

void sub_080BB430(void)

{
  sub_080AB0F0(0x1c0,0x40,1);
  return;
}


// sub_080BB444 @ 0x080BB444

void sub_080BB444(int arg0)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  undefined *puStack_20;
  int iStack_1c;
  
  iVar3 = arg0 + 0x24;
  uVar1 = *(ushort *)(arg0 + 0x26);
  __divsi3((uint)uVar1 * 0x38,0xff);
  __divsi3((uint)uVar1 * 0x30,0xff);
  puStack_20 = &DAT_08007348;
  iStack_1c = iVar3;
  sub_0815862C(&puStack_20,(uint)*(ushort *)(arg0 + 0x26),(uint)*(ushort *)(arg0 + 0x28),8);
  puStack_20 = (undefined *)0x3003800;
  iStack_1c = iVar3;
  sub_080AA790(&puStack_20,4,0xe,3);
  if (*(short *)(arg0 + 0x40) != 0) {
    puStack_20 = (undefined *)**(undefined4 **)((uint)*(ushort *)(arg0 + 0x42) * 4 + 0x81894b4);
    iStack_1c = iVar3;
    sub_0815862C(&puStack_20,(uint)*(ushort *)(arg0 + 0x26),(uint)*(ushort *)(arg0 + 0x28),8);
    puStack_20 = (undefined *)0x3003800;
    iStack_1c = iVar3;
    sub_080AA790(&puStack_20,3,0xf,3);
    if (((DAT_030031bc & 3) == 0) &&
       (sVar2 = *(short *)(arg0 + 0x42) + 1, *(short *)(arg0 + 0x42) = sVar2, sVar2 == 5)) {
      *(undefined2 *)(arg0 + 0x42) = 0;
    }
  }
  if (*(short *)(arg0 + 0x32) != 0) {
    puStack_20 = (undefined *)**(undefined4 **)((uint)*(ushort *)(arg0 + 0x34) * 4 + 0x81894c8);
    iStack_1c = arg0 + 0x36;
    sub_0815862C(&puStack_20,(uint)*(ushort *)(arg0 + 0x38),(uint)*(ushort *)(arg0 + 0x3a),8);
    puStack_20 = (undefined *)0x3003800;
    iStack_1c = arg0 + 0x36;
    sub_080AA790(&puStack_20,2,0xd,3);
    sVar2 = *(short *)(arg0 + 0x34) + 1;
    *(short *)(arg0 + 0x34) = sVar2;
    if (sVar2 == 2) {
      *(undefined2 *)(arg0 + 0x34) = 0;
    }
    if (*(short *)(arg0 + 0x38) == 0x100) {
      *(undefined2 *)(arg0 + 0x32) = 0;
    }
    else {
      *(short *)(arg0 + 0x38) = *(short *)(arg0 + 0x38) + 8;
      *(short *)(arg0 + 0x3a) = *(short *)(arg0 + 0x3a) + 8;
    }
  }
  if ((*(short *)(arg0 + 0x3e) == 1) && (*(short *)(arg0 + 0x26) != 0x18)) {
    *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + -1;
    *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) + -1;
  }
  return;
}


// sub_080BB5D0 @ 0x080BB5D0

void sub_080BB5D0(int arg0)

{
  *(undefined2 *)(arg0 + 0x32) = 1;
  *(undefined2 *)(arg0 + 0x40) = 1;
  *(undefined2 *)(arg0 + 0x44) = 1;
  sub_080C51D4(0x98);
  return;
}


// sub_080BB5E8 @ 0x080BB5E8

void sub_080BB5E8(int arg0,undefined4 arg1)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B6DB4(arg1);
  *(undefined4 *)(arg0 + 0x48) = uVar1;
  return;
}


// sub_080BB5FC @ 0x080BB5FC

void sub_080BB5FC(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (**(short **)(arg0 + 0x48) == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    *(undefined2 *)(arg0 + 0x3e) = 1;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080bb61a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BB61C @ 0x080BB61C

void sub_080BB61C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6013000;
  REG_DMA3CNT = 0x84001200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BB640 @ 0x080BB640

void sub_080BB640(int arg0)

{
  int arg2;
  
  arg2 = arg0 + 0x24;
  DAT_03004640 = arg2;
  *(undefined2 *)(arg0 + 0x24) = 1;
  *(undefined2 *)(arg0 + 0x26) = 0x100;
  *(undefined2 *)(arg0 + 0x28) = 0x100;
  *(undefined2 *)(arg0 + 0x2a) = 0;
  *(undefined2 *)(arg0 + 0x2c) = 0x78;
  *(undefined2 *)(arg0 + 0x2e) = 0x44;
  *(undefined2 *)(arg0 + 0x30) = 8;
  LZ77UnCompWram(0x8189570,0x2001000,arg2);
  LZ77UnCompWram(0x8189bfc,&DAT_02002000,arg2);
  sub_080ACFCC(3,0x8189bdc,0x3002d70,0x20);
  sub_080ACFCC(3,0x818b1c0,&DAT_03002d90,0x20);
  sub_080AB090(0x1e0,0x20,1,1);
  DisplayList_Add(0x80bb61d,1);
  return;
}


// sub_080BB6E0 @ 0x080BB6E0

void sub_080BB6E0(int arg0,undefined4 arg1)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B6DB4(arg1);
  *(undefined4 *)(arg0 + 0x34) = uVar1;
  return;
}


// sub_080BB6F4 @ 0x080BB6F4

void sub_080BB6F4(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(ushort *)(arg0 + 0x1c) = (ushort)(**(short **)(arg0 + 0x34) == 0);
                    /* WARNING: Could not recover jumptable at 0x080bb70a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BB70C @ 0x080BB70C

void sub_080BB70C(int arg0)

{
  undefined4 *puVar1;
  int iVar2;
  undefined *local_18;
  int local_14;
  
  iVar2 = arg0 + 0x24;
  local_18 = &DAT_08007130;
  DAT_03004640 = iVar2;
  local_14 = iVar2;
  sub_0815862C(&local_18,(uint)*(ushort *)(arg0 + 0x26),(uint)*(ushort *)(arg0 + 0x28),8);
  local_18 = (undefined *)0x3003800;
  local_14 = iVar2;
  sub_080AA790(&local_18,1,0xe,3);
  puVar1 = (undefined4 *)0x80071fc;
  if ((DAT_030031bc >> 2 & 1) == 0) {
    puVar1 = (undefined4 *)0x80071b0;
  }
  local_18 = (undefined *)*puVar1;
  local_14 = iVar2;
  sub_0815862C(&local_18,(uint)*(ushort *)(arg0 + 0x26),(uint)*(ushort *)(arg0 + 0x28),8);
  local_18 = (undefined *)0x3003800;
  local_14 = iVar2;
  sub_080AA790(&local_18,0,0xf,3);
  return;
}


// sub_080BB7B4 @ 0x080BB7B4

void sub_080BB7B4(undefined4 arg0,int arg1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    sub_080AB0F0(0x80,0x80,8);
  }
  else {
    sub_080AB0F0(0x1e0,0x20,1);
  }
                    /* WARNING: Could not recover jumptable at 0x080bb7d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BB7D8 @ 0x080BB7D8

void sub_080BB7D8(int arg0,int arg1)

{
  short sVar1;
  
  if (*(short *)(arg0 + 0x26) != 0x20) {
    *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + -1;
    *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) + -1;
  }
  if (arg1 == 0) {
    DAT_0300000e = DAT_0300000e + -1;
  }
  sVar1 = *(short *)(arg0 + 0x30) + -1;
  *(short *)(arg0 + 0x30) = sVar1;
  if (sVar1 == 0) {
    *(undefined2 *)(arg0 + 0x30) = 8;
    *(short *)(arg0 + 0x2e) = *(short *)(arg0 + 0x2e) + -1;
    *(short *)(arg0 + 0x2c) = *(short *)(arg0 + 0x2c) + 1;
  }
  return;
}


// sub_080BB820 @ 0x080BB820

void sub_080BB820(int arg0)

{
  short sVar1;
  
  if ((DAT_03003964 & 0x40) == 0) {
    if ((DAT_03003964 & 0x80) == 0) {
      return;
    }
    if (*(short *)(arg0 + 0x26) == 0x200) {
      return;
    }
    *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + 1;
    sVar1 = *(short *)(arg0 + 0x28) + 1;
  }
  else {
    if (*(short *)(arg0 + 0x26) == 0) {
      return;
    }
    *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + -1;
    sVar1 = *(short *)(arg0 + 0x28) + -1;
  }
  *(short *)(arg0 + 0x28) = sVar1;
  return;
}


// sub_080BB868 @ 0x080BB868

void sub_080BB868(undefined4 arg0,byte *arg1,undefined4 arg2,ushort *arg3)

{
  byte bVar1;
  int iVar2;
  
  LZ77UnCompWram(arg0,arg2,arg2);
  iVar2 = 0x1c;
  do {
    bVar1 = *arg1;
    arg1 = arg1 + 1;
    *arg3 = *arg3 & 0xfff | ((bVar1 & 0xf) + 8) * 0x1000;
    arg3 = arg3 + 1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return;
}


// sub_080BB8A0 @ 0x080BB8A0

void sub_080BB8A0(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x85001000;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BB8E0 @ 0x080BB8E0

void sub_080BB8E0(void)

{
  sub_080C14FC();
  sub_080AB438(0,0x2000000,1,0);
  DisplayList_Add(0x80bb8a1,1);
  DisplayList_Add(0x80c153d,1);
  DAT_0200e804 = 1;
  return;
}


// sub_080BB928 @ 0x080BB928

void sub_080BB928(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x600e000;
  REG_DMA3CNT = 0x84000500;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BB964 @ 0x080BB964

void sub_080BB964(void)

{
  int iVar1;
  undefined4 in_r2;
  short *psVar2;
  
  psVar2 = (short *)0x2000000;
  LZ77UnCompWram(0x8181238,0x2001000,in_r2);
  LZ77UnCompWram(0x8181f84,0x2000000,in_r2);
  iVar1 = 0x800;
  do {
    if (*psVar2 != 0) {
      *psVar2 = *psVar2 + -32000;
    }
    iVar1 = iVar1 + -1;
    psVar2 = psVar2 + 1;
  } while (iVar1 != 0);
  DAT_03000040 = 0;
  DAT_03000006 = 8;
  DAT_03000030 = 0xf0;
  DAT_03000031 = 0;
  DAT_03000034 = 0xe0;
  DAT_03000035 = 0x68;
  DAT_03000038 = 0x3d;
  iVar1 = sub_080C2340(0xc6);
  if (iVar1 != 0) {
    DAT_03000034 = 0x68;
    DAT_0300003b = 0;
  }
  DisplayList_Add(0x80bb929,1);
  return;
}


// sub_080BBA1C @ 0x080BBA1C

void sub_080BBA1C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2005000;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84001000;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  REG_BG3CNT = 0x8607;
  return;
}


// sub_080BBA64 @ 0x080BBA64

void sub_080BBA64(int arg0)

{
  int iVar1;
  
  iVar1 = (uint)*(ushort *)(arg0 + 0x24) * 8;
  sub_080BB868(*(undefined4 *)(iVar1 + 0x818b2e0),*(undefined4 *)(&DAT_0818b2e4 + iVar1),
               (uint)*(ushort *)(arg0 + 0x28) * 0x400 + 0x2005020,
               (uint)*(ushort *)(arg0 + 0x26) * 0x40 + 0x2000000);
  if (*(short *)(arg0 + 0x24) != 0) {
    *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
  }
  *(ushort *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) - 1U & 0xf;
  *(ushort *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) - 1U & 0x3f;
  return;
}


// sub_080BBAC0 @ 0x080BBAC0

void sub_080BBAC0(int arg0)

{
  ushort uVar1;
  dword arg2;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = 0;
  CpuSet(&local_18,0x2005000,0x5001000);
  local_14 = 0;
  arg2 = 0x5000400;
  CpuSet(&local_14,0x2000000,0x5000400);
  LZ77UnCompWram(0x8180ba0,0x2000000,arg2);
  *(undefined2 *)(arg0 + 0x24) = 0x61;
  *(undefined2 *)(arg0 + 0x26) = 0x3f;
  *(undefined2 *)(arg0 + 0x28) = 0xf;
  uVar1 = 0;
  do {
    sub_080BBA64(arg0);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x10);
  DAT_0300000e = 0x198;
  DisplayList_Add(0x80bba1d,1);
  DAT_0200ab04 = DAT_0200ab04 | 0x8000;
  DAT_03004534 = 0x66;
  sub_080ACFCC(3,0x8181138,0x3002ab0,0x100);
  DAT_030029b0 = 0;
  DAT_03002db0 = 0;
  DAT_0300452c = sub_080AB090(0x80,0x80,1,0x8001);
  return;
}


// sub_080BBBA4 @ 0x080BBBA4

void sub_080BBBA4(int arg0)

{
  short sVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0300000e = DAT_0300000e - 1;
  if (-0xa0 < DAT_03000006) {
    DAT_03000006 = DAT_03000006 + -1;
  }
  if ((DAT_0300000e & 7) == 0) {
    sub_080BBA64(arg0);
    DisplayList_Add(0x80bba1d,1);
  }
  sVar1 = *(short *)(*(int *)(arg0 + 0x30) + 0x28);
  if (sVar1 != 0x40) {
    *(short *)(*(int *)(arg0 + 0x30) + 0x28) = sVar1 + 1;
  }
  if (*(short *)(arg0 + 0x24) == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080BBC10 @ 0x080BBC10

void sub_080BBC10(int arg0)

{
  undefined2 uVar1;
  
  if ((DAT_030031bc & 7) == 0) {
    if (*(short *)(arg0 + 0x2a) == 0) {
      DAT_0300000c = 0xffff;
      DAT_03000004 = 0xffff;
      *(undefined2 *)(arg0 + 0x2a) = 0xffff;
    }
    else {
      DAT_0300000c = 0;
      DAT_03000004 = 0;
      *(undefined2 *)(arg0 + 0x2a) = 0;
    }
    if (*(short *)(arg0 + 0x2c) == 0) {
      DAT_0300000e = 0x197;
      DAT_03000006 = 7;
      uVar1 = 0xffff;
    }
    else {
      DAT_0300000e = 0x198;
      DAT_03000006 = 8;
      uVar1 = 0;
    }
    *(undefined2 *)(arg0 + 0x2c) = uVar1;
  }
  return;
}


// sub_080BBCB8 @ 0x080BBCB8

void sub_080BBCB8(int arg0)

{
  DAT_0300000e = 0x198;
  DAT_03000006 = 8;
  *(undefined4 *)(arg0 + 0x20) = 0;
  return;
}


// sub_080BBCD8 @ 0x080BBCD8

void sub_080BBCD8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6013000;
  REG_DMA3CNT = 0x84000d00;
  uVar1 = REG_DMA3CNT;
  return;
}


