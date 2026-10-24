/* Ghidra decompilation of asm/code_080A96CC.s (reference only; not compiled). */

// AgbMain @ 0x080A96CC

void AgbMain(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  REG_WAITCNT = 0x4014;
  sub_080A9794();
  uVar2 = 0;
  puVar4 = (undefined4 *)0x815eaa8;
  puVar3 = (undefined4 *)0x30020f0;
  do {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  sub_080D1180();
  m4aSoundInit();
  DAT_030031b4 = 0;
  DAT_030031ec = 0;
  DAT_030031d4 = 0;
  sub_080A98F4();
  sub_080A9AC0();
  sub_080A99BC();
  DAT_030031bc = 0;
  sub_080AABD4(0);
  sub_080DF2E8();
  sub_080C2998();
  sub_080C2AA8();
  sub_080D5B8C(0);
  sub_080C10F4();
  do {
    DAT_030031d4 = 1;
    sub_080A9A04();
    sub_080ACC30();
    sub_080DF370();
    m4aSoundMain();
    sub_080A9D90();
    _call_via_r0(DAT_030020e4);
    sub_080A9DD0();
    sub_080AAE58();
    DAT_030031bc = DAT_030031bc + 1;
    sub_080AC468();
    sub_080DF360();
    DAT_030031d4 = 0;
    VBlankIntrWait();
  } while( true );
}


// sub_080A9794 @ 0x080A9794

void sub_080A9794(void)

{
  sub_080A97A4();
  sub_080A97E0();
  return;
}


// sub_080A97A4 @ 0x080A97A4

void sub_080A97A4(void)

{
  undefined4 uVar1;
  undefined1 local_4 [4];
  
  REG_DMA3SAD = local_4;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x85010000;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = local_4;
  REG_DMA3DAD = 0x3000000;
  REG_DMA3CNT = 0x85001f80;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080A97E0 @ 0x080A97E0

void sub_080A97E0(void)

{
  sub_080A97F4();
  sub_080A981C();
  sub_080A9880();
  return;
}


// sub_080A97F4 @ 0x080A97F4

void sub_080A97F4(void)

{
  undefined4 uVar1;
  undefined1 local_4 [4];
  
  REG_DMA3SAD = local_4;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x8100c000;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080A981C @ 0x080A981C

void sub_080A981C(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_07000000;
  iVar2 = 0x1f;
  do {
    *puVar1 = 0x200;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0x100;
    puVar1[4] = 0x200;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0x200;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0x200;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
    puVar1[0xf] = 0x100;
    puVar1 = puVar1 + 0x10;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return;
}


// sub_080A9880 @ 0x080A9880

void sub_080A9880(void)

{
  undefined4 uVar1;
  undefined1 local_4 [4];
  
  REG_DMA3SAD = local_4;
  REG_DMA3DAD = 0x5000000;
  REG_DMA3CNT = 0x81000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080A98A8 @ 0x080A98A8

int sub_080A98A8(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = (int)(short)arg1 * (int)(short)arg0;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xff;
  }
  return (iVar1 << 8) >> 0x10;
}


// sub_080A98C4 @ 0x080A98C4

void sub_080A98C4(int arg0,undefined4 arg1)

{
  __divsi3((arg0 << 0x10) >> 8,(int)(short)arg1);
  return;
}


// sub_080A98DC @ 0x080A98DC

int sub_080A98DC(undefined4 arg0)

{
  undefined4 uVar1;
  
  uVar1 = __divsi3(0x10000,(int)(short)arg0);
  return (int)(short)uVar1;
}


// sub_080A98F4 @ 0x080A98F4

void sub_080A98F4(void)

{
  undefined4 uVar1;
  
  sub_080A9974();
  DAT_03003960 = 0x80a9971;
  REG_DMA3SAD = 0x80000fc;
  REG_DMA3DAD = 0x3003980;
  REG_DMA3CNT = 0x80000100;
  uVar1 = REG_DMA3CNT;
  DAT_03007ffc = 0x3003980;
  return;
}


// sub_080A9934 @ 0x080A9934

void sub_080A9934(dword arg0)

{
  DAT_03003960 = arg0;
  if (arg0 == 0) {
    DAT_03003960 = 0x80a9971;
  }
  return;
}


// VBlankIntr @ 0x080A9950

void VBlankIntr(void)

{
  if (DAT_03003960 != 0) {
    _call_via_r0(DAT_03003960);
  }
  sub_080A9988();
  return;
}


// HBlankIntr @ 0x080A996C

void HBlankIntr(void)

{
  return;
}


// IntrDummy @ 0x080A9970

void IntrDummy(void)

{
  return;
}


// sub_080A9974 @ 0x080A9974

void sub_080A9974(void)

{
  DAT_03003b80 = DAT_03003b80 & 0xfffe;
  return;
}


// sub_080A9988 @ 0x080A9988

void sub_080A9988(void)

{
  REG_IE._2_2_ = 1;
  DAT_03003b80 = 1;
  return;
}


// sub_080A999C @ 0x080A999C

void sub_080A999C(void)

{
  sub_080A9974();
  do {
    software_interrupt(2);
  } while ((DAT_03003b80 & 1) == 0);
  return;
}


// sub_080A99BC @ 0x080A99BC

void sub_080A99BC(void)

{
  DAT_030031d0 = 0;
  DAT_030031b0 = 0;
  DAT_030031b8 = 0;
  DAT_030031c4 = 0;
  DAT_03003968 = 0xffff;
  DAT_0300396a = 0;
  DAT_03003964 = 0;
  DAT_0300396c = 0;
  DAT_0300396e = 0;
  DAT_0300396f = 0;
  return;
}


// sub_080A9A04 @ 0x080A9A04

void sub_080A9A04(void)

{
  ushort uVar1;
  
  uVar1 = REG_KEYINPUT;
  DAT_030031d0 = uVar1 ^ 0x3ff;
  DAT_030031c4 = DAT_030031d0 & ~DAT_030031b0;
  DAT_030031b8 = DAT_030031d0 & ~DAT_030031b0;
  DAT_030031b0 = DAT_030031d0;
  DAT_0300396a = DAT_030031d0;
  DAT_03003964 = DAT_030031d0 & ~DAT_03003968;
  DAT_0300396c = DAT_03003964;
  if ((uint)DAT_03003968 * 0x10000 + (uint)DAT_030031d0 * -0x10000 != 0) {
    DAT_0300396f = 8;
  }
  if ((DAT_03003968 & DAT_030031d0) == 0) {
    DAT_0300396e = '\0';
    DAT_0300396f = 8;
  }
  else if (DAT_0300396e < 0x10) {
    DAT_03003964 = 0;
    DAT_0300396e = DAT_0300396e + 1;
  }
  else {
    DAT_0300396e = DAT_0300396e - 2;
    DAT_0300396f = 0x10;
    DAT_03003964 = DAT_030031d0;
  }
  DAT_03003968 = DAT_030031d0;
  return;
}


// sub_080A9AB4 @ 0x080A9AB4

void sub_080A9AB4(undefined4 arg0)

{
  DAT_030020e4 = arg0;
  return;
}


// sub_080A9AC0 @ 0x080A9AC0

void sub_080A9AC0(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x3003900;
  REG_DMA3CNT = 0x85000014;
  uVar1 = REG_DMA3CNT;
  sub_080A9934(0x80a9af5);
  return;
}


// sub_080A9AF4 @ 0x080A9AF4

void sub_080A9AF4(void)

{
  undefined4 uVar1;
  int iVar2;
  
  m4aSoundVSync();
  sub_080DF15C();
  if (DAT_030031d4 == 0) {
    REG_DMA3SAD = 0x3000000;
    REG_DMA3DAD = 0x4000010;
    REG_DMA3CNT = 0x84000011;
    uVar1 = REG_DMA3CNT;
    REG_DMA3SAD = 0x30033f0;
    REG_DMA3DAD = 0x7000000;
    REG_DMA3CNT = 0x84000100;
    uVar1 = REG_DMA3CNT;
    iVar2 = sub_080AABC8();
    if (iVar2 == 1) {
      REG_DMA3SAD = 0x3002db0;
      REG_DMA3DAD = 0x5000000;
      REG_DMA3CNT = 0x84000100;
      uVar1 = REG_DMA3CNT;
      sub_080AABBC();
    }
    sub_080A9C78(1);
  }
  else {
    REG_BG0HOFS = DAT_03000000;
    REG_BG0VOFS = DAT_03000002;
    REG_BG1HOFS = DAT_03000004;
    REG_BG1VOFS = DAT_03000006;
    REG_BG2HOFS = DAT_03000008;
    REG_BG2VOFS = DAT_0300000a;
    REG_BG3HOFS = DAT_0300000c;
    REG_BG3VOFS = DAT_0300000e;
    sub_080A9C78(2);
    m4aSoundMain();
  }
  DAT_03007ff8 = 1;
  return;
}


// sub_080A9BE8 @ 0x080A9BE8

undefined4 sub_080A9BE8(void)

{
  short *psVar1;
  uint uVar2;
  
  uVar2 = 0;
  psVar1 = (short *)0x3003900;
  do {
    if (*psVar1 == 0) {
      return psVar1;
    }
    psVar1 = psVar1 + 4;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 10);
  return 0;
}


// sub_080A9C0C @ 0x080A9C0C

undefined2 * sub_080A9C0C(undefined4 arg0)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)sub_080A9BE8();
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 1;
    puVar1[1] = 0xffff;
    *(undefined4 *)(puVar1 + 2) = arg0;
  }
  return puVar1;
}


// sub_080A9C30 @ 0x080A9C30

void sub_080A9C30(void)

{
  undefined4 in_r0;
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)sub_080A9C0C(in_r0);
  *puVar1 = 2;
  return;
}


// DisplayList_Add @ 0x080A9C40

undefined2 * DisplayList_Add(undefined4 arg0,undefined4 arg1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)sub_080A9BE8();
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 1;
    puVar1[1] = (undefined2)arg1;
    *(undefined4 *)(puVar1 + 2) = arg0;
  }
  return puVar1;
}


// sub_080A9C64 @ 0x080A9C64

void sub_080A9C64(undefined4 arg0,uint arg1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)DisplayList_Add(arg0,arg1 & 0xffff);
  *puVar1 = 2;
  return;
}


// sub_080A9C78 @ 0x080A9C78

void sub_080A9C78(undefined4 arg0)

{
  ushort uVar1;
  short sVar2;
  ushort *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    puVar3 = (ushort *)(uVar4 * 8 + 0x3003900);
    uVar1 = *puVar3;
    if ((uVar1 != 0) && ((ushort)arg0 <= uVar1)) {
      _call_via_r0((&DAT_03003904)[uVar4 * 2]);
      sVar2 = (&DAT_03003902)[uVar4 * 4];
      if (sVar2 != -1) {
        (&DAT_03003902)[uVar4 * 4] = sVar2 + -1;
        if (sVar2 == 1) {
          *puVar3 = 0;
        }
      }
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 10);
  return;
}


// sub_080A9CC0 @ 0x080A9CC0

dword sub_080A9CC0(int arg0)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  DAT_030020e8 = 0;
  DAT_030020e9 = 0;
  DAT_030020ea = 0;
  DAT_030020eb = 0;
  DAT_030020ec = 0;
  DAT_030020ed = 0;
  DAT_030020ee = 0;
  DAT_030020ef = 0;
  if (arg0 != 0) {
    uVar1 = __umodsi3(arg0,100000000);
    uVar2 = __udivsi3(uVar1,10000000);
    DAT_030020ef = (undefined1)uVar2;
    uVar1 = __umodsi3(uVar1,10000000);
    uVar2 = __udivsi3(uVar1,1000000);
    DAT_030020ee = (undefined1)uVar2;
    uVar1 = __umodsi3(uVar1,1000000);
    uVar2 = __udivsi3(uVar1,100000);
    DAT_030020ed = (undefined1)uVar2;
    uVar1 = __umodsi3(uVar1,100000);
    uVar2 = __udivsi3(uVar1,10000);
    DAT_030020ec = (undefined1)uVar2;
    uVar1 = __umodsi3(uVar1,10000);
    uVar2 = __udivsi3(uVar1,1000);
    DAT_030020eb = (undefined1)uVar2;
    uVar1 = __umodsi3(uVar1,1000);
    uVar2 = __udivsi3(uVar1,100);
    DAT_030020ea = (undefined1)uVar2;
    uVar1 = __umodsi3(uVar1,100);
    uVar2 = __udivsi3(uVar1,10);
    DAT_030020e9 = (undefined1)uVar2;
    uVar1 = __umodsi3(uVar1,10);
    DAT_030020e8 = (undefined1)uVar1;
  }
  return 0x30020e8;
}


// sub_080A9D90 @ 0x080A9D90

void sub_080A9D90(void)

{
  undefined4 uVar1;
  undefined1 auStack_c [4];
  
  DAT_030031c8 = 0;
  DAT_03002128 = 0;
  sub_080A9E78();
  REG_DMA3SAD = auStack_c;
  REG_DMA3DAD = 0x30031f0;
  REG_DMA3CNT = 0x85000080;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080A9DD0 @ 0x080A9DD0

void sub_080A9DD0(void)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)0x30033f0;
  uVar6 = 0;
  uVar5 = 0;
  do {
    bVar1 = *(byte *)(uVar5 + 0x30031e0);
    while (-1 < (int)((uint)bVar1 * 0x1000000)) {
      iVar4 = ((int)((uint)bVar1 * 0x1000000) >> 0x18) * 0xc;
      uVar3 = *(undefined4 *)(&DAT_03002134 + iVar4);
      *puVar7 = *(undefined4 *)(iVar4 + 0x3002130);
      puVar7[1] = uVar3;
      puVar7 = puVar7 + 2;
      uVar6 = uVar6 + 1 & 0xff;
      bVar1 = (&DAT_03002138)[iVar4];
    }
    uVar5 = uVar5 + 1 & 0xff;
    uVar2 = uVar6;
  } while (uVar5 < 10);
  while (-1 < (int)(uVar2 * 0x1000000)) {
    *(byte *)((int)&DAT_030033f0 + uVar6 * 8 + 1) =
         *(byte *)((int)&DAT_030033f0 + uVar6 * 8 + 1) & 0xfc | 2;
    uVar2 = uVar6 + 1;
    uVar6 = uVar2 & 0xff;
  }
  uVar6 = 0;
  do {
    *(undefined2 *)((int)&DAT_030033f4 + uVar6 * 0x20 + 2) = (&DAT_030031f8)[uVar6 * 8];
    *(undefined2 *)((int)&DAT_030033fc + uVar6 * 0x20 + 2) = (&DAT_030031fa)[uVar6 * 8];
    (&DAT_03003406)[uVar6 * 0x10] = (&DAT_030031fc)[uVar6 * 8];
    (&DAT_0300340e)[uVar6 * 0x10] = (&DAT_030031fe)[uVar6 * 8];
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 0x20);
  return;
}


// sub_080A9E78 @ 0x080A9E78

void sub_080A9E78(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    *(undefined1 *)(uVar1 + 0x30031e0) = 0xff;
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 10);
  DAT_03003950 = 0;
  return;
}


// sub_080A9EA8 @ 0x080A9EA8

int sub_080A9EA8(uint arg0)

{
  int iVar1;
  byte *pbVar2;
  
  if ((char)DAT_03003950 < '\0') {
    iVar1 = 0;
  }
  else {
    pbVar2 = (byte *)((arg0 & 0xff) + 0x30031e0);
    (&DAT_03002138)[(uint)DAT_03003950 * 0xc] = *pbVar2;
    *pbVar2 = DAT_03003950;
    DAT_03003950 = DAT_03003950 + 1;
    DAT_030031c8 = DAT_030031c8 + 1;
    iVar1 = (uint)DAT_03003950 * 0xc + 0x3002124;
  }
  return iVar1;
}


// sub_080A9F04 @ 0x080A9F04

void sub_080A9F04(undefined4 *arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  uint uVar6;
  byte bVar7;
  ushort *puVar8;
  uint uVar9;
  ushort *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  byte bVar15;
  uint uVar16;
  ushort *puVar17;
  int arg0_00;
  short *psVar18;
  code *UNRECOVERED_JUMPTABLE;
  short in_stack_00000000;
  ushort in_stack_00000004;
  char in_stack_00000008;
  byte in_stack_0000000c;
  ushort *local_40;
  uint local_34;
  
  puVar8 = (ushort *)arg0[1];
  uVar9 = (uint)*(ushort *)*arg0;
  local_40 = (ushort *)*arg0 + (uVar9 - 1) * 3 + 1;
  local_34 = 0;
  if (uVar9 != 0) {
    bVar7 = (in_stack_0000000c & 3) << 2;
    do {
      puVar10 = (ushort *)sub_080A9EA8(arg1 & 0xff);
      *puVar10 = *local_40;
      puVar10[1] = local_40[1];
      puVar10[2] = local_40[2];
      uVar6 = DAT_03002128;
      local_40 = local_40 + -3;
      if (puVar8 != (ushort *)0x0) {
        uVar16 = local_34;
        if ((int)(*puVar8 - 1) < (int)local_34) {
          uVar16 = *puVar8 - 1 & 0xffff;
        }
        puVar17 = puVar8 + uVar16 * 3 + 1;
        uVar2 = *puVar17;
        uVar3 = puVar17[1];
        uVar4 = puVar17[2];
        arg0_00 = (int)*(short *)((uVar2 + 0x40) * 2 + 0x815e828);
        uVar11 = sub_080A98DC((int)(short)uVar3);
        uVar11 = sub_080A98A8(arg0_00,(int)(short)uVar11);
        psVar18 = (short *)((uint)uVar2 * 2 + 0x815e828);
        sVar5 = *psVar18;
        uVar12 = sub_080A98DC((int)(short)uVar3);
        uVar12 = sub_080A98A8((int)sVar5,(int)(short)uVar12);
        sVar5 = *psVar18;
        uVar13 = sub_080A98DC((int)(short)uVar4);
        uVar13 = sub_080A98A8((int)-sVar5,(int)(short)uVar13);
        uVar14 = sub_080A98DC((int)(short)uVar4);
        uVar14 = sub_080A98A8(arg0_00,(int)(short)uVar14);
        (&DAT_030031f8)[uVar6 * 8] = (short)uVar11;
        (&DAT_030031fa)[uVar6 * 8] = (short)uVar12;
        (&DAT_030031fc)[uVar6 * 8] = (short)uVar13;
        (&DAT_030031fe)[uVar6 * 8] = (short)uVar14;
        *(byte *)((int)puVar10 + 1) =
             *(byte *)((int)puVar10 + 1) & 0xfc | *(byte *)((int)puVar10 + 1) & 3 | 1;
        *(byte *)((int)puVar10 + 3) =
             *(byte *)((int)puVar10 + 3) & 0xf1 | (byte)((DAT_03002128 & 7) << 1);
        DAT_03002128 = DAT_03002128 + 1;
      }
      puVar10[1] = puVar10[1] & 0xfe00 | (puVar10[1] & 0x1ff) + (in_stack_00000004 & 0x1ff) & 0x1ff;
      *(char *)puVar10 = (char)*puVar10 + in_stack_00000008;
      bVar1 = *(byte *)((int)puVar10 + 1);
      bVar15 = bVar1 & 0xf3 | bVar7;
      *(byte *)((int)puVar10 + 1) = bVar15;
      if ((in_stack_00000004 & 0xf000) == 0x8000) {
        bVar15 = bVar15 | 0x10;
      }
      else {
        bVar15 = bVar1 & 0xe3 | bVar7;
      }
      *(byte *)((int)puVar10 + 1) = bVar15;
      *(byte *)((int)puVar10 + 5) = *(byte *)((int)puVar10 + 5) & 0xf3 | ((byte)arg3 & 3) << 2;
      puVar10[2] = puVar10[2] & 0xfc00 | in_stack_00000000 + (puVar10[2] & 0x3ff) & 0x3ff;
      *(byte *)((int)puVar10 + 5) =
           *(byte *)((int)puVar10 + 5) & 0xf |
           ((char)arg2 + (*(byte *)((int)puVar10 + 5) >> 4)) * '\x10';
      local_34 = local_34 + 1 & 0xffff;
    } while (local_34 < uVar9);
  }
                    /* WARNING: Could not recover jumptable at 0x080aa17a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AA184 @ 0x080AA184

void sub_080AA184(undefined4 arg0,uint arg1,uint arg2,uint arg3)

{
  sub_080A9F04(arg0,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  return;
}


// sub_080AA1BC @ 0x080AA1BC

void sub_080AA1BC(undefined4 arg0,uint arg1,uint arg2,uint arg3)

{
  sub_080A9F04(arg0,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  return;
}


// sub_080AA1F4 @ 0x080AA1F4

void sub_080AA1F4(undefined2 *arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  byte bVar1;
  char *pcVar2;
  short in_stack_00000000;
  ushort in_stack_00000004;
  char in_stack_00000008;
  
  pcVar2 = (char *)sub_080A9EA8(arg1 & 0xff);
  *(undefined2 *)pcVar2 = *arg0;
  *(undefined2 *)(pcVar2 + 2) = arg0[1];
  *(undefined2 *)(pcVar2 + 4) = arg0[2];
  *(ushort *)(pcVar2 + 2) =
       *(ushort *)(pcVar2 + 2) & 0xfe00 |
       (*(ushort *)(pcVar2 + 2) & 0x1ff) + (in_stack_00000004 & 0x1ff) & 0x1ff;
  *pcVar2 = *pcVar2 + in_stack_00000008;
  pcVar2[5] = pcVar2[5] & 0xf3U | ((byte)arg3 & 3) << 2;
  if ((in_stack_00000004 & 0xf000) == 0x8000) {
    bVar1 = pcVar2[1] | 0x10;
  }
  else {
    bVar1 = pcVar2[1] & 0xef;
  }
  pcVar2[1] = bVar1;
  *(ushort *)(pcVar2 + 4) =
       *(ushort *)(pcVar2 + 4) & 0xfc00 |
       in_stack_00000000 + (*(ushort *)(pcVar2 + 4) & 0x3ff) & 0x3ff;
  pcVar2[5] = pcVar2[5] & 0xfU | (((byte)pcVar2[5] >> 4) + (char)arg2) * '\x10';
  return;
}


// sub_080AA2DC @ 0x080AA2DC

void sub_080AA2DC(undefined4 *arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  ushort *puVar6;
  ushort *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  ushort *puVar14;
  int arg0_00;
  short *psVar15;
  code *UNRECOVERED_JUMPTABLE;
  short in_stack_00000000;
  ushort in_stack_00000004;
  char in_stack_00000008;
  ushort *local_34;
  uint local_28;
  
  puVar6 = (ushort *)arg0[1];
  uVar13 = (uint)*(ushort *)*arg0;
  local_34 = (ushort *)*arg0 + (uVar13 - 1) * 3 + 1;
  local_28 = 0;
  if (uVar13 != 0) {
    do {
      puVar7 = (ushort *)sub_080A9EA8(arg1 & 0xff);
      *puVar7 = *local_34;
      puVar7[1] = local_34[1];
      puVar7[2] = local_34[2];
      uVar5 = DAT_03002128;
      local_34 = local_34 + -3;
      if (puVar6 != (ushort *)0x0) {
        uVar12 = local_28;
        if ((int)(*puVar6 - 1) < (int)local_28) {
          uVar12 = *puVar6 - 1 & 0xffff;
        }
        puVar14 = puVar6 + uVar12 * 3 + 1;
        uVar1 = *puVar14;
        uVar2 = puVar14[1];
        uVar3 = puVar14[2];
        arg0_00 = (int)*(short *)((uVar1 + 0x40) * 2 + 0x815e828);
        uVar8 = sub_080A98DC((int)(short)uVar2);
        uVar8 = sub_080A98A8(arg0_00,(int)(short)uVar8);
        psVar15 = (short *)((uint)uVar1 * 2 + 0x815e828);
        sVar4 = *psVar15;
        uVar9 = sub_080A98DC((int)(short)uVar2);
        uVar9 = sub_080A98A8((int)sVar4,(int)(short)uVar9);
        sVar4 = *psVar15;
        uVar10 = sub_080A98DC((int)(short)uVar3);
        uVar10 = sub_080A98A8((int)-sVar4,(int)(short)uVar10);
        uVar11 = sub_080A98DC((int)(short)uVar3);
        uVar11 = sub_080A98A8(arg0_00,(int)(short)uVar11);
        (&DAT_030031f8)[uVar5 * 8] = (short)uVar8;
        (&DAT_030031fa)[uVar5 * 8] = (short)uVar9;
        (&DAT_030031fc)[uVar5 * 8] = (short)uVar10;
        (&DAT_030031fe)[uVar5 * 8] = (short)uVar11;
        *(byte *)((int)puVar7 + 1) =
             *(byte *)((int)puVar7 + 1) & 0xfc | *(byte *)((int)puVar7 + 1) & 3 | 1;
        *(byte *)((int)puVar7 + 3) =
             *(byte *)((int)puVar7 + 3) & 0xf1 | (byte)((DAT_03002128 & 7) << 1);
        DAT_03002128 = DAT_03002128 + 1;
      }
      puVar7[1] = puVar7[1] & 0xfe00 | (puVar7[1] & 0x1ff) + (in_stack_00000004 & 0x1ff) & 0x1ff;
      *(char *)puVar7 = (char)*puVar7 + in_stack_00000008;
      *(byte *)((int)puVar7 + 5) = *(byte *)((int)puVar7 + 5) & 0xf3 | ((byte)arg3 & 3) << 2;
      puVar7[2] = puVar7[2] & 0xfc00 | in_stack_00000000 + (puVar7[2] & 0x3ff) & 0x3ff;
      *(byte *)((int)puVar7 + 1) = *(byte *)((int)puVar7 + 1) & 0xef;
      *(byte *)((int)puVar7 + 5) =
           *(byte *)((int)puVar7 + 5) & 0xf |
           ((char)arg2 + (*(byte *)((int)puVar7 + 5) >> 4)) * '\x10';
      local_28 = local_28 + 1 & 0xffff;
    } while (local_28 < uVar13);
  }
                    /* WARNING: Could not recover jumptable at 0x080aa4f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AA514 @ 0x080AA514

void sub_080AA514(undefined4 *arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  byte bVar6;
  ushort *puVar7;
  ushort *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint uVar13;
  ushort *puVar14;
  int arg0_00;
  uint uVar15;
  short *psVar16;
  code *UNRECOVERED_JUMPTABLE;
  short in_stack_00000000;
  ushort in_stack_00000004;
  char in_stack_00000008;
  byte in_stack_0000000c;
  ushort *local_3c;
  uint local_30;
  
  puVar7 = (ushort *)arg0[1];
  uVar15 = (uint)*(ushort *)*arg0;
  local_3c = (ushort *)*arg0 + (uVar15 - 1) * 3 + 1;
  local_30 = 0;
  if (uVar15 != 0) {
    do {
      puVar8 = (ushort *)sub_080A9EA8(arg1 & 0xff);
      *puVar8 = *local_3c;
      puVar8[1] = local_3c[1];
      puVar8[2] = local_3c[2];
      uVar5 = DAT_03002128;
      local_3c = local_3c + -3;
      if (puVar7 != (ushort *)0x0) {
        uVar13 = local_30;
        if ((int)(*puVar7 - 1) < (int)local_30) {
          uVar13 = *puVar7 - 1 & 0xffff;
        }
        puVar14 = puVar7 + uVar13 * 3 + 1;
        uVar1 = *puVar14;
        uVar2 = puVar14[1];
        uVar3 = puVar14[2];
        arg0_00 = (int)*(short *)((uVar1 + 0x40) * 2 + 0x815e828);
        uVar9 = sub_080A98DC((int)(short)uVar2);
        uVar9 = sub_080A98A8(arg0_00,(int)(short)uVar9);
        psVar16 = (short *)((uint)uVar1 * 2 + 0x815e828);
        sVar4 = *psVar16;
        uVar10 = sub_080A98DC((int)(short)uVar2);
        uVar10 = sub_080A98A8((int)sVar4,(int)(short)uVar10);
        sVar4 = *psVar16;
        uVar11 = sub_080A98DC((int)(short)uVar3);
        uVar11 = sub_080A98A8((int)-sVar4,(int)(short)uVar11);
        uVar12 = sub_080A98DC((int)(short)uVar3);
        uVar12 = sub_080A98A8(arg0_00,(int)(short)uVar12);
        (&DAT_030031f8)[uVar5 * 8] = (short)uVar9;
        (&DAT_030031fa)[uVar5 * 8] = (short)uVar10;
        (&DAT_030031fc)[uVar5 * 8] = (short)uVar11;
        (&DAT_030031fe)[uVar5 * 8] = (short)uVar12;
        *(byte *)((int)puVar8 + 1) =
             *(byte *)((int)puVar8 + 1) & 0xfc | *(byte *)((int)puVar8 + 1) & 3 | 1;
        *(byte *)((int)puVar8 + 3) =
             *(byte *)((int)puVar8 + 3) & 0xf1 | (byte)((DAT_03002128 & 7) << 1);
        DAT_03002128 = DAT_03002128 + 1;
      }
      puVar8[1] = puVar8[1] & 0xfe00 | (puVar8[1] & 0x1ff) + (in_stack_00000004 & 0x1ff) & 0x1ff;
      *(char *)puVar8 = (char)*puVar8 + in_stack_00000008;
      *(byte *)((int)puVar8 + 5) = *(byte *)((int)puVar8 + 5) & 0xf3 | ((byte)arg3 & 3) << 2;
      puVar8[2] = puVar8[2] & 0xfc00 | in_stack_00000000 + (puVar8[2] & 0x3ff) & 0x3ff;
      bVar6 = *(byte *)((int)puVar8 + 1) & 0xe3 | (in_stack_0000000c & 3) << 2;
      *(byte *)((int)puVar8 + 1) = bVar6;
      if ((in_stack_00000004 & 0xf000) == 0x8000) {
        bVar6 = bVar6 | 0x10;
      }
      *(byte *)((int)puVar8 + 1) = bVar6;
      *(byte *)((int)puVar8 + 5) =
           *(byte *)((int)puVar8 + 5) & 0xf |
           ((char)arg2 + (*(byte *)((int)puVar8 + 5) >> 4)) * '\x10';
      local_30 = local_30 + 1 & 0xffff;
    } while (local_30 < uVar15);
  }
                    /* WARNING: Could not recover jumptable at 0x080aa78c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AA790 @ 0x080AA790

void sub_080AA790(undefined4 *arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  ushort *puVar11;
  uint uVar12;
  uint uVar13;
  short *psVar14;
  ushort *puVar15;
  short in_stack_00000000;
  ushort in_stack_00000004;
  char in_stack_00000008;
  byte in_stack_0000000c;
  
  uVar12 = (uint)in_stack_0000000c;
  puVar15 = (ushort *)*arg0;
  iVar5 = arg0[1];
  uVar13 = (uint)*puVar15;
  psVar6 = (short *)(iVar5 + 2);
  if (psVar6 != (short *)0x0) {
    sVar1 = *(short *)(iVar5 + 4);
    uVar2 = *(ushort *)(iVar5 + 6);
    iVar5 = (int)*(short *)((uVar2 + 0x40) * 2 + 0x815e828);
    sVar3 = *psVar6;
    uVar7 = sub_080A98DC((int)sVar3);
    uVar7 = sub_080A98A8(iVar5,(int)(short)uVar7);
    psVar14 = (short *)((uint)uVar2 * 2 + 0x815e828);
    sVar4 = *psVar14;
    uVar8 = sub_080A98DC((int)sVar3);
    uVar8 = sub_080A98A8((int)sVar4,(int)(short)uVar8);
    sVar3 = *psVar14;
    uVar9 = sub_080A98DC((int)sVar1);
    uVar9 = sub_080A98A8((int)-sVar3,(int)(short)uVar9);
    uVar10 = sub_080A98DC((int)sVar1);
    uVar10 = sub_080A98A8(iVar5,(int)(short)uVar10);
    (&DAT_030031f8)[uVar12 * 8] = (short)uVar7;
    (&DAT_030031fa)[uVar12 * 8] = (short)uVar8;
    (&DAT_030031fc)[uVar12 * 8] = (short)uVar9;
    (&DAT_030031fe)[uVar12 * 8] = (short)uVar10;
  }
  puVar15 = puVar15 + (uVar13 - 1) * 3 + 1;
  uVar12 = 0;
  if (uVar13 != 0) {
    do {
      puVar11 = (ushort *)sub_080A9EA8(arg1 & 0xff);
      *puVar11 = *puVar15;
      puVar11[1] = puVar15[1];
      puVar11[2] = puVar15[2];
      puVar15 = puVar15 + -3;
      if (psVar6 != (short *)0x0) {
        *(byte *)((int)puVar11 + 1) =
             *(byte *)((int)puVar11 + 1) & 0xfc | *(byte *)((int)puVar11 + 1) & 3 | 1;
        *(byte *)((int)puVar11 + 3) =
             *(byte *)((int)puVar11 + 3) & 0xf1 | (in_stack_0000000c & 7) << 1;
      }
      puVar11[1] = puVar11[1] & 0xfe00 | (puVar11[1] & 0x1ff) + (in_stack_00000004 & 0x1ff) & 0x1ff;
      *(char *)puVar11 = (char)*puVar11 + in_stack_00000008;
      *(byte *)((int)puVar11 + 5) = *(byte *)((int)puVar11 + 5) & 0xf3 | ((byte)arg3 & 3) << 2;
      puVar11[2] = puVar11[2] & 0xfc00 | in_stack_00000000 + (puVar11[2] & 0x3ff) & 0x3ff;
      *(byte *)((int)puVar11 + 1) = *(byte *)((int)puVar11 + 1) & 0xef;
      *(byte *)((int)puVar11 + 5) =
           *(byte *)((int)puVar11 + 5) & 0xf |
           ((char)arg2 + (*(byte *)((int)puVar11 + 5) >> 4)) * '\x10';
      uVar12 = uVar12 + 1 & 0xffff;
    } while (uVar12 < uVar13);
  }
  return;
}


// sub_080AA998 @ 0x080AA998

void sub_080AA998(undefined4 *arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  ushort *puVar11;
  uint uVar12;
  uint uVar13;
  short *psVar14;
  ushort *puVar15;
  short in_stack_00000000;
  ushort in_stack_00000004;
  char in_stack_00000008;
  byte in_stack_0000000c;
  byte in_stack_00000010;
  
  uVar12 = (uint)in_stack_0000000c;
  puVar15 = (ushort *)*arg0;
  iVar5 = arg0[1];
  uVar13 = (uint)*puVar15;
  psVar6 = (short *)(iVar5 + 2);
  if (psVar6 != (short *)0x0) {
    sVar1 = *(short *)(iVar5 + 4);
    uVar2 = *(ushort *)(iVar5 + 6);
    iVar5 = (int)*(short *)((uVar2 + 0x40) * 2 + 0x815e828);
    sVar3 = *psVar6;
    uVar7 = sub_080A98DC((int)sVar3);
    uVar7 = sub_080A98A8(iVar5,(int)(short)uVar7);
    psVar14 = (short *)((uint)uVar2 * 2 + 0x815e828);
    sVar4 = *psVar14;
    uVar8 = sub_080A98DC((int)sVar3);
    uVar8 = sub_080A98A8((int)sVar4,(int)(short)uVar8);
    sVar3 = *psVar14;
    uVar9 = sub_080A98DC((int)sVar1);
    uVar9 = sub_080A98A8((int)-sVar3,(int)(short)uVar9);
    uVar10 = sub_080A98DC((int)sVar1);
    uVar10 = sub_080A98A8(iVar5,(int)(short)uVar10);
    (&DAT_030031f8)[uVar12 * 8] = (short)uVar7;
    (&DAT_030031fa)[uVar12 * 8] = (short)uVar8;
    (&DAT_030031fc)[uVar12 * 8] = (short)uVar9;
    (&DAT_030031fe)[uVar12 * 8] = (short)uVar10;
  }
  puVar15 = puVar15 + (uVar13 - 1) * 3 + 1;
  uVar12 = 0;
  if (uVar13 != 0) {
    do {
      puVar11 = (ushort *)sub_080A9EA8(arg1 & 0xff);
      *puVar11 = *puVar15;
      puVar11[1] = puVar15[1];
      puVar11[2] = puVar15[2];
      puVar15 = puVar15 + -3;
      if (psVar6 != (short *)0x0) {
        *(byte *)((int)puVar11 + 1) = *(byte *)((int)puVar11 + 1) & 0xfc | 3;
        *(byte *)((int)puVar11 + 3) =
             *(byte *)((int)puVar11 + 3) & 0xf1 | (in_stack_0000000c & 7) << 1;
      }
      puVar11[1] = puVar11[1] & 0xfe00 | (puVar11[1] & 0x1ff) + (in_stack_00000004 & 0x1ff) & 0x1ff;
      *(char *)puVar11 = (char)*puVar11 + in_stack_00000008;
      *(byte *)((int)puVar11 + 5) = *(byte *)((int)puVar11 + 5) & 0xf3 | ((byte)arg3 & 3) << 2;
      puVar11[2] = puVar11[2] & 0xfc00 | in_stack_00000000 + (puVar11[2] & 0x3ff) & 0x3ff;
      *(byte *)((int)puVar11 + 1) =
           *(byte *)((int)puVar11 + 1) & 0xe3 | (in_stack_00000010 & 3) << 2;
      *(byte *)((int)puVar11 + 5) =
           *(byte *)((int)puVar11 + 5) & 0xf |
           ((char)arg2 + (*(byte *)((int)puVar11 + 5) >> 4)) * '\x10';
      uVar12 = uVar12 + 1 & 0xffff;
    } while (uVar12 < uVar13);
  }
  return;
}


// sub_080AABB0 @ 0x080AABB0

void sub_080AABB0(void)

{
  DAT_030031c0 = 1;
  return;
}


// sub_080AABBC @ 0x080AABBC

void sub_080AABBC(void)

{
  DAT_030031c0 = 0;
  return;
}


// sub_080AABC8 @ 0x080AABC8

undefined4 sub_080AABC8(void)

{
  return DAT_030031c0;
}


// sub_080AABD4 @ 0x080AABD4

void sub_080AABD4(int arg0)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x3002730;
  REG_DMA3CNT = 0x850000a0;
  uVar1 = REG_DMA3CNT;
  if (arg0 == 0) {
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x3002db0;
    REG_DMA3CNT = 0x85000100;
    uVar1 = REG_DMA3CNT;
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x30029b0;
    REG_DMA3CNT = 0x85000100;
    uVar1 = REG_DMA3CNT;
  }
  local_8[0] = 0;
  sub_080AABB0();
  return;
}


// sub_080AAC34 @ 0x080AAC34

undefined4 sub_080AAC34(uint arg0)

{
  short *psVar1;
  dword dVar2;
  uint uVar3;
  
  uVar3 = 0;
  dVar2 = 0x3002730;
  psVar1 = (short *)0x3002730;
  while ((*psVar1 == 0 || ((uint)(ushort)psVar1[6] != (arg0 & 0xffff) + 0x8000))) {
    psVar1 = psVar1 + 0x28;
    dVar2 = dVar2 + 0x50;
    uVar3 = uVar3 + 1;
    if (7 < uVar3) {
      return 0;
    }
  }
  return dVar2;
}


// sub_080AAC70 @ 0x080AAC70

void sub_080AAC70(int arg0)

{
  short *psVar1;
  short *psVar2;
  uint uVar3;
  
  uVar3 = 0;
  psVar1 = (short *)(arg0 + 0x10);
  psVar2 = (short *)0x815eae0;
  do {
    *psVar1 = *psVar2 + *psVar1;
    psVar1 = psVar1 + 1;
    psVar2 = psVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x20);
  return;
}


// sub_080AAC98 @ 0x080AAC98

void sub_080AAC98(int arg0)

{
  ushort *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = (ushort *)(arg0 + 0x10);
  do {
    if (999 < *puVar1) {
      *puVar1 = *puVar1 - 1000;
    }
    puVar1 = puVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x20);
  return;
}


// sub_080AACC8 @ 0x080AACC8

undefined4 sub_080AACC8(int arg0,uint arg1,uint arg2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar4 = arg1 & 0xffff;
  uVar3 = arg2 & 0xffff;
  if (uVar4 != uVar3) {
    if (uVar3 < uVar4) {
      uVar4 = uVar4 - 1 & 0xffff;
      if (uVar4 == uVar3) goto LAB_080aad12;
      uVar4 = uVar4 - 1;
    }
    else {
      uVar1 = __udivsi3((uint)*(ushort *)(arg0 + 0x10 + uVar3 * 2),1000);
      if ((uVar4 == uVar3) || (uVar4 = uVar4 + (uVar1 & 0xffff) & 0xffff, uVar4 == uVar3))
      goto LAB_080aad12;
      uVar4 = uVar4 + (uVar1 & 0xffff);
    }
    uVar4 = uVar4 & 0xffff;
  }
LAB_080aad12:
                    /* WARNING: Could not recover jumptable at 0x080aad18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar4);
  return uVar2;
}


// sub_080AAD1C @ 0x080AAD1C

void sub_080AAD1C(short *arg0)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  uint uVar10;
  
  if (*arg0 != 0) {
    uVar1 = arg0[6];
    if ((uVar1 != 0) && ((uVar1 & 0x8000) == 0)) {
      iVar4 = sub_080AAC34((uint)(ushort)arg0[6]);
      if (iVar4 == 0) {
        return;
      }
      arg0[6] = uVar1 & 0x8000;
    }
    sVar2 = arg0[3];
    arg0[3] = sVar2 + -1;
    if ((short)(sVar2 + -1) == 0) {
      bVar3 = true;
      arg0[3] = arg0[2];
      sub_080AAC70(arg0);
      uVar1 = arg0[5];
      puVar5 = (ushort *)((uint)(ushort)arg0[4] * 2 + 0x3002db0);
      puVar9 = (ushort *)((uint)(ushort)arg0[4] * 2 + 0x30029b0);
      uVar10 = 0;
      if (uVar1 != 0) {
        do {
          uVar6 = (uint)*puVar5;
          uVar7 = sub_080AACC8(arg0,uVar6 & 0x1f,*puVar9 & 0x1f);
          uVar8 = sub_080AACC8(arg0,(uVar6 & 0x3e0) >> 5,(*puVar9 & 0x3e0) >> 5);
          uVar6 = sub_080AACC8(arg0,(uVar6 & 0x7c00) >> 10,(*puVar9 & 0x7c00) >> 10);
          uVar6 = (uVar8 & 0xffff) << 5 | uVar7 & 0xffff | (uVar6 & 0xffff) << 10;
          *puVar5 = (ushort)uVar6;
          if ((uVar6 & 0x7fff) != (*puVar9 & 0x7fff)) {
            bVar3 = false;
          }
          uVar10 = uVar10 + 1;
          puVar5 = puVar5 + 1;
          puVar9 = puVar9 + 1;
        } while (uVar10 < uVar1);
      }
      sub_080AAC98(arg0);
      sVar2 = arg0[1];
      if ((sVar2 != -1) && (arg0[1] = sVar2 + -1, sVar2 == 1)) {
        bVar3 = true;
      }
      if (bVar3) {
        *arg0 = 0;
      }
      sub_080AABB0();
    }
  }
  return;
}


// sub_080AAE58 @ 0x080AAE58

void sub_080AAE58(void)

{
  dword arg0;
  uint uVar1;
  
  uVar1 = 0;
  arg0 = 0x3002730;
  do {
    sub_080AAD1C(arg0);
    arg0 = arg0 + 0x50;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  return;
}


// sub_080AAE78 @ 0x080AAE78

undefined4 sub_080AAE78(void)

{
  short *psVar1;
  uint uVar2;
  
  uVar2 = 0;
  psVar1 = (short *)0x3002730;
  do {
    if (*psVar1 == 0) {
      return psVar1;
    }
    psVar1 = psVar1 + 0x28;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  return 0;
}


// sub_080AAE9C @ 0x080AAE9C

void sub_080AAE9C(undefined2 *arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined4 uVar1;
  undefined1 local_10 [4];
  
  REG_DMA3SAD = local_10;
  REG_DMA3DAD = arg0;
  REG_DMA3CNT = 0x85000014;
  uVar1 = REG_DMA3CNT;
  arg0[2] = (undefined2)arg3;
  arg0[3] = (undefined2)arg3;
  arg0[4] = (undefined2)arg1;
  arg0[5] = (undefined2)arg2;
  arg0[1] = 0xffff;
  *arg0 = 1;
  return;
}


// sub_080AAEDC @ 0x080AAEDC

int sub_080AAEDC(uint arg0)

{
  int arg0_00;
  
  arg0_00 = sub_080AAE78();
  if (arg0_00 != 0) {
    sub_080ACFA4(3,0,0x3002db0,0x400);
    sub_080AABB0();
    sub_080AAE9C(arg0_00,0,0x200,arg0 & 0xffff);
  }
  return arg0_00;
}


// sub_080AAF20 @ 0x080AAF20

void sub_080AAF20(undefined4 arg0,uint arg1)

{
  sub_080AAEDC(arg1 & 0xffff);
  return;
}


// sub_080AAF30 @ 0x080AAF30

void sub_080AAF30(uint arg0)

{
  sub_080AB008(0,0x200,arg0 & 0xffff);
  return;
}


// sub_080AAF48 @ 0x080AAF48

int sub_080AAF48(uint arg0)

{
  int arg0_00;
  
  arg0_00 = sub_080AAE78();
  if (arg0_00 != 0) {
    sub_080ACFA4(3,0,0x30029b0,0x400);
    sub_080AAE9C(arg0_00,0,0x200,arg0 & 0xffff);
  }
  return arg0_00;
}


// sub_080AAF88 @ 0x080AAF88

void sub_080AAF88(undefined4 arg0,uint arg1)

{
  sub_080AAF48(arg1 & 0xffff);
  return;
}


// sub_080AAF98 @ 0x080AAF98

void sub_080AAF98(uint arg0)

{
  int arg0_00;
  
  arg0_00 = sub_080AAE78();
  if (arg0_00 != 0) {
    sub_080AAE9C(arg0_00,0,0x200,arg0 & 0xffff);
  }
  return;
}


// sub_080AAFBC @ 0x080AAFBC

int sub_080AAFBC(uint arg0,uint arg1,uint arg2)

{
  int arg0_00;
  
  arg0_00 = sub_080AAE78();
  if (arg0_00 != 0) {
    sub_080ACFA4(3,0,(arg0 & 0xffff) * 2 + 0x3002db0,(arg1 & 0xffff) << 1);
    sub_080AABB0();
    sub_080AAE9C(arg0_00,arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff);
  }
  return arg0_00;
}


// sub_080AB008 @ 0x080AB008

int sub_080AB008(uint arg0,uint arg1,uint arg2)

{
  int arg0_00;
  
  arg0_00 = sub_080AAE78();
  if (arg0_00 != 0) {
    sub_080ACFA4(3,0x7fff,(arg0 & 0xffff) * 2 + 0x30029b0,(arg1 & 0xffff) << 1);
    sub_080AAE9C(arg0_00,arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff);
  }
  return arg0_00;
}


// sub_080AB054 @ 0x080AB054

int sub_080AB054(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  int arg0_00;
  
  arg0_00 = sub_080AAE78();
  if (arg0_00 != 0) {
    sub_080AAE9C(arg0_00,arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff);
    *(undefined2 *)(arg0_00 + 2) = (undefined2)arg3;
  }
  return arg0_00;
}


// sub_080AB090 @ 0x080AB090

int sub_080AB090(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  int arg0_00;
  
  arg0_00 = sub_080AAE78();
  if (arg0_00 != 0) {
    sub_080ACFA4(3,0,(arg0 & 0xffff) * 2 + 0x3002db0,(arg1 & 0xffff) << 1);
    sub_080AABB0();
    sub_080AAE9C(arg0_00,arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff);
    *(undefined2 *)(arg0_00 + 0xc) = (undefined2)arg3;
  }
  return arg0_00;
}


// sub_080AB0F0 @ 0x080AB0F0

int sub_080AB0F0(uint arg0,uint arg1,uint arg2)

{
  int arg0_00;
  
  arg0_00 = sub_080AAE78();
  if (arg0_00 != 0) {
    sub_080ACFA4(3,0,(arg0 & 0xffff) * 2 + 0x30029b0,(arg1 & 0xffff) << 1);
    sub_080AAE9C(arg0_00,arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff);
  }
  return arg0_00;
}


// sub_080AB138 @ 0x080AB138

int sub_080AB138(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  int iVar1;
  
  iVar1 = sub_080AB0F0(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff);
  *(undefined2 *)(iVar1 + 2) = (undefined2)arg3;
  return iVar1;
}


// sub_080AB158 @ 0x080AB158

int sub_080AB158(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  int iVar1;
  
  iVar1 = sub_080AB0F0(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff);
  *(undefined2 *)(iVar1 + 0xc) = (undefined2)arg3;
  return iVar1;
}


// sub_080AB178 @ 0x080AB178

uint sub_080AB178(ushort *arg0)

{
  return -(uint)*arg0 >> 0x1f;
}


// sub_080AB184 @ 0x080AB184

undefined4 sub_080AB184(void)

{
  short *psVar1;
  uint uVar2;
  
  uVar2 = 0;
  psVar1 = (short *)0x3002730;
  do {
    if (*psVar1 != 0) {
      return 0;
    }
    psVar1 = psVar1 + 0x28;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  return 1;
}


// sub_080AB1A8 @ 0x080AB1A8

void sub_080AB1A8(int arg0)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = sub_080AB184();
  uVar1 = (undefined2)uVar2;
  if ((uVar2 & 0xffff) != 1) {
    uVar1 = 0;
  }
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
  return;
}


// sub_080AB1C4 @ 0x080AB1C4

void sub_080AB1C4(int arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  uint in_stack_00000000;
  uint in_stack_00000004;
  uint in_stack_00000008;
  
  uVar1 = 0;
  if ((in_stack_00000008 & 0xffff) != 0) {
    do {
      uVar3 = 0;
      if ((in_stack_00000004 & 0xffff) != 0) {
        do {
          puVar2 = (ushort *)
                   (arg0 + (uVar1 + (in_stack_00000000 & 0xffff)) * 0x40 +
                   (uVar3 + (arg3 & 0xffff)) * 2);
          *puVar2 = *puVar2 + (short)arg1 & 0xfff | (short)arg2 << 0xc;
          uVar3 = uVar3 + 1 & 0xffff;
        } while (uVar3 < (in_stack_00000004 & 0xffff));
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < (in_stack_00000008 & 0xffff));
  }
  return;
}


// sub_080AB250 @ 0x080AB250

void sub_080AB250(int arg0,int arg1,undefined4 arg2,undefined4 arg3)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint in_stack_00000000;
  uint in_stack_00000004;
  uint in_stack_00000008;
  uint in_stack_0000000c;
  
  uVar2 = 0;
  if ((in_stack_0000000c & 0xffff) != 0) {
    do {
      uVar3 = 0;
      if ((in_stack_00000008 & 0xffff) != 0) {
        do {
          sVar1 = *(short *)(uVar3 * 2 + uVar2 * 0x40 + arg0);
          if (sVar1 != 0) {
            sVar1 = sVar1 + (short)arg2;
          }
          *(short *)(arg1 + (uVar2 + (in_stack_00000004 & 0xffff)) * 0x40 +
                    (uVar3 + (in_stack_00000000 & 0xffff)) * 2) = sVar1 + (short)arg3 * 0x1000;
          uVar3 = uVar3 + 1 & 0xffff;
        } while (uVar3 < (in_stack_00000008 & 0xffff));
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < (in_stack_0000000c & 0xffff));
  }
  return;
}


// sub_080AB2F4 @ 0x080AB2F4

void sub_080AB2F4(int arg0,int arg1,undefined4 arg2,undefined4 arg3)

{
  uint uVar1;
  uint uVar2;
  uint in_stack_00000000;
  uint in_stack_00000004;
  uint in_stack_00000008;
  uint in_stack_0000000c;
  
  uVar1 = 0;
  if ((in_stack_0000000c & 0xffff) != 0) {
    do {
      uVar2 = 0;
      if ((in_stack_00000008 & 0xffff) != 0) {
        do {
          *(short *)(arg1 + (uVar1 + (in_stack_00000004 & 0xffff)) * 0x40 +
                    (uVar2 + (in_stack_00000000 & 0xffff)) * 2) =
               *(short *)(uVar2 * 2 + uVar1 * 0x40 + arg0) + (short)arg2 + (short)arg3 * 0x1000;
          uVar2 = uVar2 + 1 & 0xffff;
        } while (uVar2 < (in_stack_00000008 & 0xffff));
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < (in_stack_0000000c & 0xffff));
  }
  return;
}


// sub_080AB390 @ 0x080AB390

void sub_080AB390(int arg0,int arg1,undefined4 arg2,undefined4 arg3)

{
  uint uVar1;
  uint uVar2;
  uint in_stack_00000000;
  uint in_stack_00000004;
  uint in_stack_00000008;
  uint in_stack_0000000c;
  uint in_stack_00000010;
  
  uVar1 = 0;
  if ((in_stack_0000000c & 0xffff) != 0) {
    do {
      uVar2 = 0;
      if ((in_stack_00000008 & 0xffff) != 0) {
        do {
          *(short *)(arg1 + (uVar1 + (in_stack_00000004 & 0xffff)) * 0x40 +
                    (uVar2 + (in_stack_00000000 & 0xffff)) * 2) =
               *(short *)(uVar2 * 2 + uVar1 * (in_stack_00000010 & 0xffff) * 2 + arg0) + (short)arg2
               + (short)arg3 * 0x1000;
          uVar2 = uVar2 + 1 & 0xffff;
        } while (uVar2 < (in_stack_00000008 & 0xffff));
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < (in_stack_0000000c & 0xffff));
  }
  return;
}


// sub_080AB438 @ 0x080AB438

void sub_080AB438(undefined4 arg0,int arg1,uint arg2,uint arg3)

{
  uint uVar1;
  uint uVar2;
  uint in_stack_00000000;
  uint in_stack_00000004;
  
  uVar1 = 0;
  if ((in_stack_00000004 & 0xffff) != 0) {
    do {
      uVar2 = 0;
      if ((in_stack_00000000 & 0xffff) != 0) {
        do {
          *(undefined2 *)(arg1 + (uVar1 + (arg3 & 0xffff)) * 0x40 + (uVar2 + (arg2 & 0xffff)) * 2) =
               (undefined2)arg0;
          uVar2 = uVar2 + 1 & 0xffff;
        } while (uVar2 < (in_stack_00000000 & 0xffff));
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < (in_stack_00000004 & 0xffff));
  }
  return;
}


// sub_080AB49C @ 0x080AB49C

void sub_080AB49C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x20381dc;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080AB4BC @ 0x080AB4BC

void sub_080AB4BC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x20381dc;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080AB4E0 @ 0x080AB4E0

void sub_080AB4E0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x20381dc;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080AB504 @ 0x080AB504

void sub_080AB504(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x20381dc;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080AB528 @ 0x080AB528

void sub_080AB528(int arg0,uint arg1,uint arg2,uint arg3)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000000;
  
  uVar7 = arg3 & 0xffff;
  uVar1 = in_stack_00000000 & 0xffff;
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      uVar4 = 0;
      if (uVar7 != 0) {
        uVar6 = uVar1 - 1;
        do {
          iVar3 = 4;
          if (uVar4 == 0) {
            if (uVar5 == 0) {
              iVar3 = 0;
            }
            else {
              if (uVar5 != uVar6) goto LAB_080ab5a4;
              iVar3 = 6;
            }
          }
          else {
LAB_080ab5a4:
            if (uVar4 == uVar7 - 1) {
              if (uVar5 == 0) {
                iVar3 = 2;
              }
              else {
                if (uVar5 != uVar6) goto LAB_080ab5ba;
                iVar3 = 8;
              }
            }
            else {
LAB_080ab5ba:
              if (uVar4 == 0) {
                iVar3 = 3;
              }
              else if (uVar5 == 0) {
                iVar3 = 1;
              }
              else if (uVar4 == uVar7 - 1) {
                iVar3 = 5;
              }
              else if (uVar5 == uVar6) {
                iVar3 = 7;
              }
            }
          }
          if ((*(short *)(arg0 + 6) == 4) && (*(short *)(arg0 + 0xe) == 1)) {
            puVar2 = (undefined2 *)(iVar3 * 2 + 0x815eb32);
          }
          else {
            puVar2 = (undefined2 *)(iVar3 * 2 + 0x815eb20);
          }
          *(undefined2 *)
           (((arg2 & 0xffff) + uVar5) * 0x40 + ((arg1 & 0xffff) + uVar4) * 2 + 0x20381dc) = *puVar2;
          uVar4 = uVar4 + 1 & 0xffff;
        } while (uVar4 < uVar7);
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < uVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x080ab61a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AB61C @ 0x080AB61C

void sub_080AB61C(int arg0)

{
  dword arg0_00;
  
  if (arg0 == 1) {
    arg0_00 = 0x80ab4bd;
  }
  else if (arg0 == 0) {
    arg0_00 = 0x80ab49d;
  }
  else {
    if (arg0 != 2) {
      if (arg0 != 3) {
        return;
      }
      DisplayList_Add(0x80ab505,1);
      return;
    }
    arg0_00 = 0x80ab4e1;
  }
  DisplayList_Add(arg0_00,1);
  return;
}


// sub_080AB660 @ 0x080AB660

void sub_080AB660(int arg0)

{
  sub_080AB438(0,0x20381dc,(uint)*(ushort *)(arg0 + 0x24),(uint)*(ushort *)(arg0 + 0x26));
  sub_080AB61C((uint)*(ushort *)(arg0 + 0x2c));
  DAT_020391dc = DAT_020391dc + -1;
  return;
}


// sub_080AB69C @ 0x080AB69C

void sub_080AB69C(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x1e) = (undefined2)arg1;
  return;
}


// sub_080AB6A0 @ 0x080AB6A0

void sub_080AB6A0(int arg0,int arg1)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080AB528(arg0 + 0x24,(uint)*(ushort *)(arg0 + 0x24),(uint)*(ushort *)(arg0 + 0x26),
               (uint)*(ushort *)(arg0 + 0x28));
  sub_080AB61C((uint)*(ushort *)(arg0 + 0x2c));
  if (arg1 == 0) {
    if (*(short *)(arg0 + 0x2e) != *(short *)(arg0 + 0x2a)) {
      *(undefined2 *)(arg0 + 0x1c) = 0;
      *(short *)(arg0 + 0x2e) = *(short *)(arg0 + 0x2e) + 1;
      goto LAB_080ab750;
    }
    uVar3 = 1;
LAB_080ab74e:
    *(undefined2 *)(arg0 + 0x1c) = uVar3;
  }
  else {
    if (arg1 == 1) {
      sub_080AB438(0,0x20381dc,(uint)*(ushort *)(arg0 + 0x24),
                   (uint)*(ushort *)(arg0 + 0x2e) + (uint)*(ushort *)(arg0 + 0x26) & 0xffff);
      if (*(short *)(arg0 + 0x2e) != 2) {
        *(undefined2 *)(arg0 + 0x1c) = 0;
        *(short *)(arg0 + 0x2e) = *(short *)(arg0 + 0x2e) + -1;
        goto LAB_080ab750;
      }
    }
    else {
      sub_080AB438(0,0x20381dc,(uint)*(ushort *)(arg0 + 0x24),
                   (uint)*(ushort *)(arg0 + 0x2e) + (uint)*(ushort *)(arg0 + 0x26) & 0xffff);
      uVar1 = *(ushort *)(arg0 + 0x2e);
      if (uVar1 != *(ushort *)(arg0 + 0x2a)) {
        if (*(ushort *)(arg0 + 0x2a) < uVar1) {
          sVar2 = -1;
        }
        else {
          sVar2 = 1;
        }
        *(ushort *)(arg0 + 0x2e) = uVar1 + sVar2;
        uVar3 = 0;
        goto LAB_080ab74e;
      }
    }
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
LAB_080ab750:
                    /* WARNING: Could not recover jumptable at 0x080ab756. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AB758 @ 0x080AB758

void sub_080AB758(int arg0)

{
  if (((*(short *)(arg0 + 0x2a) == 8) && (*(short *)(arg0 + 0x26) == 0xb)) &&
     (DAT_030020e4 == 0x80c1851)) {
    DAT_0200e804 = 1;
    DAT_0200e812 = 1;
  }
  return;
}


// sub_080AB78C @ 0x080AB78C

void sub_080AB78C(void)

{
  undefined4 uVar1;
  undefined1 local_4 [4];
  
  REG_DMA3SAD = local_4;
  REG_DMA3DAD = 0x20381dc;
  REG_DMA3CNT = 0x81000800;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = local_4;
  REG_DMA3DAD = 0x200dfd4;
  REG_DMA3CNT = 0x81000400;
  uVar1 = REG_DMA3CNT;
  DAT_020391dc = 0;
  return;
}


// sub_080AB7D4 @ 0x080AB7D4

int sub_080AB7D4(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  undefined4 uVar1;
  int iVar2;
  uint in_stack_00000000;
  undefined1 local_20 [4];
  uint local_1c;
  uint local_18;
  
  local_1c = arg3 & 0xffff;
  local_18 = in_stack_00000000 & 0xffff;
  iVar2 = sub_080AD0FC(0x815eb44,0xffff);
  *(undefined2 *)(iVar2 + 0x24) = (undefined2)arg0;
  *(undefined2 *)(iVar2 + 0x26) = (undefined2)arg1;
  *(undefined2 *)(iVar2 + 0x28) = (undefined2)arg2;
  *(short *)(iVar2 + 0x2a) = (short)local_1c;
  *(short *)(iVar2 + 0x2c) = (short)local_18;
  *(undefined2 *)(iVar2 + 0x32) = 0;
  *(undefined2 *)(iVar2 + 0x2e) = 2;
  if (DAT_020391dc == 0) {
    REG_DMA3SAD = local_20;
    REG_DMA3DAD = 0x20381dc;
    REG_DMA3CNT = 0x81000800;
    uVar1 = REG_DMA3CNT;
  }
  DAT_020391dc = DAT_020391dc + 1;
  return iVar2;
}


// sub_080AB860 @ 0x080AB860

int sub_080AB860(uint arg0,uint arg1,uint arg2,uint arg3)

{
  int iVar1;
  
  iVar1 = sub_080AB7D4(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  *(undefined2 *)(iVar1 + 0x2e) = *(undefined2 *)(iVar1 + 0x2a);
  return iVar1;
}


// sub_080AB890 @ 0x080AB890

int sub_080AB890(uint arg0,uint arg1,uint arg2,uint arg3)

{
  int iVar1;
  
  iVar1 = sub_080AB7D4(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  *(undefined2 *)(iVar1 + 0x32) = 1;
  return iVar1;
}


// sub_080AB8BC @ 0x080AB8BC

void sub_080AB8BC(uint arg0,uint arg1,uint arg2,uint arg3)

{
  int iVar1;
  
  iVar1 = sub_080AB7D4(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  *(undefined2 *)(iVar1 + 0x32) = 1;
  *(undefined2 *)(iVar1 + 0x2e) = *(undefined2 *)(iVar1 + 0x2a);
  return;
}


// sub_080AB8F0 @ 0x080AB8F0

void sub_080AB8F0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200e314;
  REG_DMA3DAD = 0x6001340;
  REG_DMA3CNT = 0x80000020;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080AB91C @ 0x080AB91C

void sub_080AB91C(int arg0,int arg1)

{
  int iVar1;
  
  if (arg0 != 0) {
    if ((((*(short *)(arg0 + 0x2a) == 8) && (*(short *)(arg0 + 0x26) == 0xb)) &&
        (DAT_030020e4 == 0x80c1851)) && (DAT_0200e810 == 0)) {
      DAT_0200e812 = DAT_0200e810;
      iVar1 = sub_080C8AF8();
      if ((iVar1 == 1) && (DAT_0200e7de == 0)) {
        DAT_0200e804 = DAT_0200e7de;
      }
    }
    if (arg1 == 0) {
      *(undefined2 *)(arg0 + 0x1e) = 1;
    }
    else {
      sub_080AB660(arg0);
      sub_080AD1FC(arg0);
    }
  }
  return;
}


// sub_080AB98C @ 0x080AB98C

void sub_080AB98C(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x2a) = (undefined2)arg1;
  *(undefined2 *)(arg0 + 0x1e) = 2;
  return;
}


// sub_080AB994 @ 0x080AB994

undefined4 sub_080AB994(short *arg0)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*arg0 == 0) || (arg0[0xf] == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}


// sub_080AB9B0 @ 0x080AB9B0

void sub_080AB9B0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200dfd4;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080AB9D0 @ 0x080AB9D0

void sub_080AB9D0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200dfd4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


