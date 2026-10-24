/* Ghidra decompilation of asm/code_080D8248.s (reference only; not compiled). */

// sub_080D8248 @ 0x080D8248

int sub_080D8248(uint arg0)

{
  return (arg0 & 0xffff) * 0x1c + 0x872c774;
}


// sub_080D8260 @ 0x080D8260

void sub_080D8260(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D8284 @ 0x080D8284

void sub_080D8284(int arg0,int arg1)

{
  int iVar1;
  dword arg0_00;
  undefined4 in_r2;
  undefined4 arg2;
  int arg0_01;
  
  arg0_01 = arg0 + 0x24;
  iVar1 = sub_080D8248((uint)*(ushort *)(arg1 * 2 + 0x203db28));
  *(int *)(arg0 + 0x48) = arg1;
  if (*(short *)(arg0 + 0x26) == 0) {
    HuffUnComp(*(undefined4 *)(iVar1 + 0xc),0x200afc8,in_r2);
    LZ77UnCompWram(0x200afc8,0x2001000,in_r2);
    arg2 = 0x1e0;
    sub_080C3F4C(arg0_01,*(undefined4 *)(iVar1 + 4),0x1e0,0x20);
    if (*(int *)(iVar1 + 0x14) == 0) {
      arg0_00 = 0x80c3ebd;
    }
    else {
      HuffUnComp(*(int *)(iVar1 + 0x14),&DAT_0200bfc8,arg2);
      LZ77UnCompWram(&DAT_0200bfc8,&DAT_02002000,arg2);
      arg0_00 = 0x80d8261;
    }
  }
  else {
    if (*(short *)(arg0 + 0x26) != 1) {
      HuffUnComp(*(undefined4 *)(iVar1 + 0xc),0x200cfc8,in_r2);
      LZ77UnCompWram(0x200cfc8,0x2003000,in_r2);
      sub_080C3F4C(arg0_01,*(undefined4 *)(iVar1 + 4),0x1d0,0x20);
      DisplayList_Add(0x80c3f05,1);
      return;
    }
    HuffUnComp(*(undefined4 *)(iVar1 + 0xc),0x200bfc8,in_r2);
    LZ77UnCompWram(0x200bfc8,0x2002000,in_r2);
    sub_080C3F4C(arg0_01,*(undefined4 *)(iVar1 + 4),0x1f0,0x20);
    arg0_00 = 0x80c3ee1;
  }
  DisplayList_Add(arg0_00,1);
  return;
}


// sub_080D8384 @ 0x080D8384

void sub_080D8384(int arg0)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 unaff_r7;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080D8248((uint)*(ushort *)(*(int *)(arg0 + 0x48) * 2 + 0x203db28));
  uVar3 = sub_080C4388(arg0 + 0x24);
  puVar4 = *(undefined4 **)(*(int *)(iVar2 + 8) + 4);
  if ((DAT_030031bc >> 4 & 1) == 0) {
    puVar4 = puVar4 + 2;
  }
  uVar1 = *(ushort *)(arg0 + 0x26);
  if (uVar1 == 1) {
    unaff_r7 = 0xf;
  }
  else if (uVar1 < 2) {
    if (uVar1 == 0) {
      unaff_r7 = 0xe;
    }
  }
  else if (uVar1 == 2) {
    unaff_r7 = 0xd;
  }
  sub_080C44CC(arg0 + 0x24,*puVar4,uVar3 & 0xffff,unaff_r7);
                    /* WARNING: Could not recover jumptable at 0x080d8420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D8428 @ 0x080D8428

void sub_080D8428(void)

{
  undefined4 in_r0;
  
  sub_080D7A84(in_r0,0x8005064);
  return;
}


// sub_080D8438 @ 0x080D8438

void sub_080D8438(void)

{
  undefined4 in_r0;
  
  sub_080D7A84(in_r0,0x8005088);
  return;
}


// sub_080D8448 @ 0x080D8448

void sub_080D8448(int arg0)

{
  *(undefined2 *)(arg0 + 0x2e) = 1;
  sub_080D7A84(arg0,0x8005104);
  return;
}


// sub_080D845C @ 0x080D845C

void sub_080D845C(void)

{
  undefined4 in_r0;
  
  sub_080D7A84(in_r0,0x800520c);
  return;
}


// sub_080D846C @ 0x080D846C

void sub_080D846C(undefined4 arg0)

{
  if ((DAT_030031bc >> 4 & 1) != 0) {
    sub_080C44B0(arg0);
  }
  return;
}


// sub_080D848C @ 0x080D848C

void sub_080D848C(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080AD0FC(0x81a64a8,(uint)*(ushort *)(arg0 + 2));
  *(undefined4 *)(arg0 + 0x44) = uVar1;
  return;
}


// sub_080D84A8 @ 0x080D84A8

void sub_080D84A8(int arg0)

{
  dword arg1;
  
  if (*(short *)(arg0 + 0x2a) == 0xf2) {
    if ((DAT_030031bc >> 4 & 1) == 0) {
      arg1 = 0x8005514;
    }
    else {
      arg1 = 0x80054d4;
    }
    sub_080D7A84(arg0,arg1);
  }
  else {
    sub_080D7A84(arg0,0x80054d4);
  }
  return;
}


// sub_080D84EC @ 0x080D84EC

void sub_080D84EC(void)

{
  undefined4 in_r0;
  
  sub_080D7A84(in_r0,0x8005554);
  return;
}


// sub_080D84FC @ 0x080D84FC

void sub_080D84FC(int arg0)

{
  dword arg1;
  
  if (*(short *)(arg0 + 0x2a) == 0xf3) {
    if ((DAT_030031bc >> 4 & 1) == 0) {
      arg1 = 0x80055e4;
    }
    else {
      arg1 = 0x800559c;
    }
    sub_080D7A84(arg0,arg1);
  }
  else {
    sub_080D7A84(arg0,0x800559c);
  }
  return;
}


// sub_080D8540 @ 0x080D8540

void sub_080D8540(void)

{
  undefined4 in_r0;
  
  sub_080D7A84(in_r0,0x8005624);
  return;
}


// sub_080D8550 @ 0x080D8550

void sub_080D8550(void)

{
  undefined4 in_r0;
  
  sub_080D7A84(in_r0,0x8005664);
  return;
}


// sub_080D8560 @ 0x080D8560

void sub_080D8560(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2003000;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D8584 @ 0x080D8584

void sub_080D8584(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x85171c4,0x2003000,in_r2);
  sub_080ACFCC(3,0x8517414,0x3003150,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80d8561,1);
  return;
}


// sub_080D85C8 @ 0x080D85C8

void sub_080D85C8(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C4388(arg0 + 0x24);
  sub_080C44CC(arg0 + 0x24,*(undefined4 *)((*(ushort *)(arg0 + 0x2a) - 0x3b) * 4 + 0x85651b0),
               uVar1 & 0xffff,0xd);
  return;
}


// sub_080D8610 @ 0x080D8610

void sub_080D8610(int arg0,undefined4 arg1)

{
  short sVar1;
  uint uVar2;
  int arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg0 + 0x24;
  sVar1 = *(short *)(arg0 + 0x26);
  uVar2 = sub_080C4388(arg0_00);
  uVar2 = uVar2 & 0xffff;
  if (sVar1 == 0) {
    sub_080C44CC(arg0_00,arg1,uVar2,0xe);
  }
  else if (sVar1 == 1) {
    sub_080C44CC(arg0_00,arg1,uVar2,0xf);
  }
  else {
    sub_080C44CC(arg0_00,arg1,uVar2,0xd);
  }
                    /* WARNING: Could not recover jumptable at 0x080d86c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D86C8 @ 0x080D86C8

void sub_080D86C8(void)

{
  undefined4 in_r0;
  
  sub_080D8610(in_r0,0x800521c);
  return;
}


// sub_080D86D8 @ 0x080D86D8

void sub_080D86D8(void)

{
  undefined4 in_r0;
  
  sub_080D8610(in_r0,0x800522c);
  return;
}


// sub_080D86E8 @ 0x080D86E8

void sub_080D86E8(void)

{
  undefined4 in_r0;
  
  sub_080D8610(in_r0,0x800523c);
  return;
}


// sub_080D86F8 @ 0x080D86F8

void sub_080D86F8(void)

{
  undefined4 in_r0;
  
  sub_080D8610(in_r0,0x8005254);
  return;
}


// sub_080D8708 @ 0x080D8708

void sub_080D8708(void)

{
  undefined4 in_r0;
  
  sub_080D8610(in_r0,0x8005278);
  return;
}


// sub_080D8718 @ 0x080D8718

void sub_080D8718(void)

{
  undefined4 in_r0;
  
  sub_080D8610(in_r0,0x8005290);
  return;
}


// sub_080D8728 @ 0x080D8728

void sub_080D8728(void)

{
  undefined4 in_r0;
  
  sub_080D8610(in_r0,0x80052c0);
  return;
}


// sub_080D8738 @ 0x080D8738

void sub_080D8738(void)

{
  undefined4 in_r0;
  
  sub_080D8610(in_r0,0x80052f0);
  return;
}


// sub_080D8748 @ 0x080D8748

void sub_080D8748(void)

{
  undefined4 in_r0;
  
  sub_080D8610(in_r0,0x8005314);
  return;
}


// sub_080D8758 @ 0x080D8758

void sub_080D8758(void)

{
  undefined4 in_r0;
  
  sub_080D8610(in_r0,0x8005338);
  return;
}


// sub_080D8768 @ 0x080D8768

void sub_080D8768(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2003000;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D878C @ 0x080D878C

undefined4 sub_080D878C(int arg0,undefined4 arg1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = 0;
  piVar3 = (int *)0x2036094;
  while (((iVar2 = *piVar3, iVar2 == 0 || (iVar2 == arg0)) ||
         (*(short *)(iVar2 + 0x2a) != (short)arg1))) {
    piVar3 = piVar3 + 1;
    uVar1 = uVar1 + 1;
    if (5 < uVar1) {
      return 0;
    }
  }
  return iVar2;
}


// sub_080D87C0 @ 0x080D87C0

void sub_080D87C0(undefined4 arg0)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_r2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080D878C(arg0,0xac);
  if ((((iVar2 == 0) && (iVar2 = sub_080D878C(arg0,0xad), iVar2 == 0)) &&
      (iVar2 = sub_080D878C(arg0,0xae), iVar2 == 0)) &&
     (iVar2 = sub_080D878C(arg0,0xaf), iVar2 == 0)) {
    LZ77UnCompWram(0x852c434,0x2003000,in_r2);
    LZ77UnCompWram(0x852c8cc,&DAT_02003800,in_r2);
    sub_080ACFCC(3,0x852cc0c,0x3002d10,0x20);
    sub_080ACFCC(3,&DAT_0852cc2c,&DAT_03002d30,0x20);
    sub_080ACFCC(3,&DAT_0852cc4c,&DAT_03002d50,0x20);
    sub_080ACFCC(3,&DAT_0852cc6c,&DAT_03002d90,0x20);
    iVar2 = sub_080B098C();
    if (iVar2 == 0) {
      REG_DMA3SAD = 0x3002d10;
      REG_DMA3DAD = 0x3003110;
      REG_DMA3CNT = 0x84000008;
      uVar1 = REG_DMA3CNT;
      REG_DMA3SAD = 0x3002d30;
      REG_DMA3DAD = 0x3003130;
      REG_DMA3CNT = 0x84000008;
      uVar1 = REG_DMA3CNT;
      REG_DMA3SAD = 0x3002d50;
      REG_DMA3DAD = 0x3003150;
      REG_DMA3CNT = 0x84000008;
      uVar1 = REG_DMA3CNT;
      REG_DMA3SAD = 0x3002d90;
      REG_DMA3DAD = 0x3003190;
      REG_DMA3CNT = 0x84000008;
      uVar1 = REG_DMA3CNT;
      sub_080AABB0();
    }
    else {
      sub_080AB090(0x1b0,0x10,1,1);
      sub_080AB090(0x1c0,0x10,1,1);
      sub_080AB090(0x1d0,0x10,1,1);
      sub_080AB090(0x1f0,0x10,1,1);
    }
    DisplayList_Add(0x80d8769,1);
  }
                    /* WARNING: Could not recover jumptable at 0x080d891c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D8924 @ 0x080D8924

void sub_080D8924(int arg0)

{
  ushort uVar1;
  uint uVar2;
  dword arg1;
  int arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg0 + 0x24;
  uVar2 = sub_080C4388(arg0_00);
  uVar1 = *(ushort *)(arg0 + 0x2a);
  if (uVar1 == 0xad) {
    arg1 = 0x80053c4;
  }
  else if (uVar1 < 0xae) {
    if (uVar1 != 0xac) goto LAB_080d89a0;
    arg1 = 0x800536c;
  }
  else {
    if (uVar1 != 0xae) {
      if (uVar1 == 0xaf) {
        sub_080C44CC(arg0_00,0x800542c,uVar2 & 0xffff,0xc);
      }
      goto LAB_080d89a0;
    }
    arg1 = 0x80053f8;
  }
  sub_080C44CC(arg0_00,arg1,uVar2 & 0xffff,0xb);
LAB_080d89a0:
                    /* WARNING: Could not recover jumptable at 0x080d89a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D89AC @ 0x080D89AC

void sub_080D89AC(int arg0,undefined4 arg1)

{
  short sVar1;
  uint uVar2;
  int arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg0 + 0x24;
  sVar1 = *(short *)(arg0 + 0x26);
  uVar2 = sub_080C4388(arg0_00);
  uVar2 = uVar2 & 0xffff;
  if (sVar1 == 0) {
    sub_080C44CC(arg0_00,arg1,uVar2,0xe);
  }
  else if (sVar1 == 1) {
    sub_080C44CC(arg0_00,arg1,uVar2,0xf);
  }
  else {
    sub_080C44CC(arg0_00,arg1,uVar2,0xd);
  }
                    /* WARNING: Could not recover jumptable at 0x080d8a62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D8A64 @ 0x080D8A64

void sub_080D8A64(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x8005460);
  return;
}


// sub_080D8A74 @ 0x080D8A74

void sub_080D8A74(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x8005494);
  return;
}


// sub_080D8A84 @ 0x080D8A84

void sub_080D8A84(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000600;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D8AA8 @ 0x080D8AA8

void sub_080D8AA8(void)

{
  undefined4 in_r2;
  undefined4 arg2;
  
  LZ77UnCompWram(0x85332ec,0x2001000,in_r2);
  arg2 = 0x800;
  LZ77UnCompWram(0x8533788,&DAT_02001800,0x800);
  LZ77UnCompWram(0x8533c94,&DAT_02002000,arg2);
  sub_080ACFCC(3,0x85340d8,0x3003170,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80d8a85,1);
  return;
}


// sub_080D8B10 @ 0x080D8B10

void sub_080D8B10(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x8005810);
  return;
}


// sub_080D8B20 @ 0x080D8B20

void sub_080D8B20(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x8005850);
  return;
}


// sub_080D8B30 @ 0x080D8B30

void sub_080D8B30(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x8005898);
  return;
}


// sub_080D8B40 @ 0x080D8B40

void sub_080D8B40(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x80058ec);
  return;
}


// sub_080D8B50 @ 0x080D8B50

void sub_080D8B50(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x800594c);
  return;
}


// sub_080D8B60 @ 0x080D8B60

void sub_080D8B60(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x80056ac);
  return;
}


// sub_080D8B70 @ 0x080D8B70

void sub_080D8B70(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x80056f8);
  return;
}


// sub_080D8B80 @ 0x080D8B80

void sub_080D8B80(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x8005744);
  return;
}


// sub_080D8B90 @ 0x080D8B90

void sub_080D8B90(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x8005790);
  return;
}


// sub_080D8BA0 @ 0x080D8BA0

void sub_080D8BA0(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x80057d0);
  return;
}


// sub_080D8BB0 @ 0x080D8BB0

void sub_080D8BB0(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x800595c);
  return;
}


// sub_080D8BC0 @ 0x080D8BC0

void sub_080D8BC0(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x8005974);
  return;
}


// sub_080D8BD0 @ 0x080D8BD0

void sub_080D8BD0(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x800598c);
  return;
}


// sub_080D8BE0 @ 0x080D8BE0

void sub_080D8BE0(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x80059a4);
  return;
}


// sub_080D8BF0 @ 0x080D8BF0

void sub_080D8BF0(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x80059b4);
  return;
}


// sub_080D8C00 @ 0x080D8C00

void sub_080D8C00(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x80059c4);
  return;
}


// sub_080D8C10 @ 0x080D8C10

void sub_080D8C10(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000600;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D8C34 @ 0x080D8C34

void sub_080D8C34(int arg0)

{
  uint uVar1;
  int iVar2;
  undefined4 in_r2;
  undefined4 arg2;
  
  LZ77UnCompWram(0x8535510,0x2001000,in_r2);
  arg2 = 0x800;
  LZ77UnCompWram(0x8535988,&DAT_02001800,0x800);
  LZ77UnCompWram(0x8535fb8,&DAT_02002000,arg2);
  sub_080ACFCC(3,0x8536318,0x3003170,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80d8c11,1);
  uVar1 = sub_080C2244();
  *(undefined4 *)(arg0 + 0x48) = *(undefined4 *)((uVar1 & 0xf) * 4 + 0x8565c08);
  uVar1 = sub_080C2244();
  iVar2 = (uVar1 & 1) + 1;
  *(int *)(arg0 + 0x4c) = iVar2;
  *(int *)(arg0 + 0x50) = iVar2;
  *(undefined4 *)(arg0 + 0x54) = 0x50;
  return;
}


// sub_080D8CC8 @ 0x080D8CC8

void sub_080D8CC8(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C4388(arg0 + 0x24);
  sub_080C44CC(arg0 + 0x24,*(undefined4 *)(arg0 + 0x48),uVar1 & 0xffff,0xe);
  return;
}


// sub_080D8D08 @ 0x080D8D08

void sub_080D8D08(int arg0)

{
  int iVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined4 *)(arg0 + 0x50) = *(undefined4 *)(arg0 + 0x4c);
  *(short *)(arg0 + 0x2e) = *(short *)(arg0 + 0x2e) + 2;
  iVar1 = *(int *)(arg0 + 0x54) + -1;
  *(int *)(arg0 + 0x54) = iVar1;
  if (iVar1 == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080D8D30 @ 0x080D8D30

void sub_080D8D30(void)

{
  undefined4 in_r0;
  
  sub_080D89AC(in_r0,0x8005b40);
  return;
}


// sub_080D8D40 @ 0x080D8D40

void sub_080D8D40(int arg0)

{
  *(undefined2 *)(arg0 + 0x48) = 1;
  *(undefined2 *)(arg0 + 0x4a) = 0x100;
  *(undefined2 *)(arg0 + 0x4c) = 0x100;
  *(undefined2 *)(arg0 + 0x4e) = 0;
  return;
}


// sub_080D8D54 @ 0x080D8D54

void sub_080D8D54(undefined4 arg0,undefined4 arg1,int arg2)

{
  int arg2_00;
  
  arg2_00 = arg2;
  HuffUnComp(arg1,0x200afc8,arg2);
  LZ77UnCompWram(0x200afc8,arg2 * 0x800 + 0x2001000,arg2_00);
  return;
}


// sub_080D8D80 @ 0x080D8D80

void sub_080D8D80(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6013000;
  REG_DMA3CNT = 0x84000c00;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D8DA4 @ 0x080D8DA4

void sub_080D8DA4(void)

{
  undefined4 in_r1;
  
  sub_080ACFCC(3,in_r1,0x3003150,0x40);
  sub_080AABB0();
  DisplayList_Add(0x80d8d81,1);
  return;
}


// sub_080D8DD0 @ 0x080D8DD0

void sub_080D8DD0(int arg0)

{
  sub_080C4388(arg0 + 0x24);
  sub_080AA184(*(undefined4 *)((uint)*(ushort *)(arg0 + 0x3c) * 4 + 0x8565cd8),7,0xd,3);
  return;
}


// sub_080D8E18 @ 0x080D8E18

void sub_080D8E18(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x3c) = (undefined2)arg1;
  return;
}


// sub_080D8E1C @ 0x080D8E1C

void sub_080D8E1C(int arg0)

{
  sub_080C4388(arg0 + 0x24);
  if (*(short *)(arg0 + 0x30) == 0) {
    sub_080AA184(*(undefined4 *)((uint)*(ushort *)(arg0 + 0x3c) * 4 + 0x8565dc4),7,0xd,3);
  }
  else {
    sub_080AA184(*(undefined4 *)((uint)*(ushort *)(arg0 + 0x3c) * 4 + 0x8565de8),7,0xd,3);
  }
  return;
}


// sub_080D8EA0 @ 0x080D8EA0

void sub_080D8EA0(int arg0)

{
  dword local_18;
  int local_14;
  
  sub_080C4388(arg0 + 0x24);
  if (*(short *)(arg0 + 0x30) == 0) {
    local_18 = **(dword **)((uint)*(ushort *)(arg0 + 0x3c) * 4 + 0x8565f20);
    local_14 = arg0 + 0x48;
    sub_0815862C(&local_18,(uint)*(ushort *)(arg0 + 0x4a),(uint)*(ushort *)(arg0 + 0x4c),0x10);
    local_18 = 0x3003800;
    local_14 = arg0 + 0x48;
    sub_080AA790(&local_18,0,0xd,3);
  }
  else {
    sub_080AA184(*(undefined4 *)((*(ushort *)(arg0 + 0x3c) + 2) * 4 + 0x8565f20),0,0xd,3);
  }
  return;
}


// sub_080D8F48 @ 0x080D8F48

void sub_080D8F48(int arg0)

{
  dword local_18;
  int local_14;
  
  sub_080C4388(arg0 + 0x24);
  if (*(short *)(arg0 + 0x30) == 0) {
    local_18 = **(dword **)((uint)*(ushort *)(arg0 + 0x3c) * 4 + 0x8565fe4);
    local_14 = arg0 + 0x48;
    sub_0815862C(&local_18,(uint)*(ushort *)(arg0 + 0x4a),(uint)*(ushort *)(arg0 + 0x4c),0x10);
    local_18 = 0x3003800;
    local_14 = arg0 + 0x48;
    sub_080AA790(&local_18,0,0xd,3);
  }
  else {
    sub_080AA184(*(undefined4 *)((*(ushort *)(arg0 + 0x3c) + 4) * 4 + 0x8565fe4),0,0xd,3);
  }
  return;
}


// sub_080D8FF0 @ 0x080D8FF0

void sub_080D8FF0(int arg0)

{
  *(short *)(arg0 + 0x2c) = 0x3d - (short)*(undefined4 *)(arg0 + 0x48);
  *(undefined2 *)(arg0 + 0x2e) = 0;
  sub_080C43F8(arg0,0x8004ff8,0,0);
  *(short *)(arg0 + 0x2c) = (short)*(undefined4 *)(arg0 + 0x48) + 99;
  *(undefined2 *)(arg0 + 0x2e) = 0;
  sub_080C43F8(arg0,0x8005028,0,0);
  return;
}


// sub_080D9034 @ 0x080D9034

void sub_080D9034(int arg0)

{
  *(undefined4 *)(arg0 + 0x48) = 0;
  return;
}


// sub_080D903C @ 0x080D903C

void sub_080D903C(int arg0)

{
  *(int *)(arg0 + 0x48) = *(int *)(arg0 + 0x48) + 1;
  DAT_03000030 = 0x3d;
  DAT_03000031 = 0;
  DAT_03000034 = 0x47;
  DAT_03000035 = 0;
  DAT_03000038 = 0x2f;
  DAT_03000032 = 0xf0;
  DAT_03000033 = 0xb3;
  DAT_03000036 = 0x47;
  DAT_03000037 = 0;
  DAT_03000039 = 0x2f;
  DAT_0300003a = 0x3f;
  return;
}


// sub_080D90B4 @ 0x080D90B4

void sub_080D90B4(void)

{
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x3f;
  return;
}


// sub_080D90D0 @ 0x080D90D0

void sub_080D90D0(int arg0)

{
  *(short *)(arg0 + 0x2c) = 0x4d - (short)*(undefined4 *)(arg0 + 0x48);
  *(undefined2 *)(arg0 + 0x2e) = 0x20;
  sub_080C43F8(arg0,0x8004ff8,0,0);
  *(short *)(arg0 + 0x2c) = (short)*(undefined4 *)(arg0 + 0x48) + 0x53;
  *(undefined2 *)(arg0 + 0x2e) = 0x20;
  sub_080C43F8(arg0,0x8005028,0,0);
  return;
}


// sub_080D9114 @ 0x080D9114

void sub_080D9114(int arg0)

{
  *(undefined4 *)(arg0 + 0x48) = 0;
  return;
}


// sub_080D911C @ 0x080D911C

void sub_080D911C(int arg0)

{
  *(int *)(arg0 + 0x48) = *(int *)(arg0 + 0x48) + 1;
  DAT_03000030 = 0x4d;
  DAT_03000031 = 0;
  DAT_03000034 = 0x57;
  DAT_03000035 = 0;
  DAT_03000038 = 0x2f;
  DAT_03000032 = 0xf0;
  DAT_03000033 = 0xa3;
  DAT_03000036 = 0x57;
  DAT_03000037 = 0;
  DAT_03000039 = 0x2f;
  DAT_0300003a = 0x3f;
  return;
}


// sub_080D9194 @ 0x080D9194

void sub_080D9194(void)

{
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x3f;
  return;
}


// sub_080D91B0 @ 0x080D91B0

void sub_080D91B0(int arg0)

{
  undefined2 uVar1;
  
  uVar1 = *(undefined2 *)(arg0 + 0x2c);
  sub_080C43F8(arg0,0x8004ff8,0,0);
  *(short *)(arg0 + 0x2c) = *(short *)(arg0 + 0x2c) + 0x50;
  sub_080C43F8(arg0,0x8005028,0,0);
  *(undefined2 *)(arg0 + 0x2c) = uVar1;
  return;
}


// sub_080D91E8 @ 0x080D91E8

void sub_080D91E8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6014c00;
  REG_DMA3CNT = 0x84000d00;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D920C @ 0x080D920C

void sub_080D920C(int arg0)

{
  undefined4 in_r2;
  undefined4 arg2;
  
  LZ77UnCompWram(0x8566c34,0x2001000,in_r2);
  LZ77UnCompWram(0x8567060,&DAT_02002000,0x1000);
  arg2 = 0x2000;
  LZ77UnCompWram(0x85673d0,&DAT_02003000,0x2000);
  LZ77UnCompWram(0x85677a4,&DAT_02004000,arg2);
  sub_080C3F4C(arg0 + 0x24,0x8567894,0x1e0,0x20);
  DisplayList_Add(0x80d91e9,1);
  *(undefined4 *)(arg0 + 0x48) = 0;
  *(undefined2 *)(arg0 + 0x28) = 1;
  return;
}


// sub_080D9288 @ 0x080D9288

void sub_080D9288(int arg0)

{
  sub_080C4388(arg0 + 0x24);
  sub_080AA184(*(undefined4 *)(*(int *)(arg0 + 0x48) * 4 + 0x85678b4),9,0xe,3);
  return;
}


// sub_080D92D0 @ 0x080D92D0

void sub_080D92D0(int arg0,undefined4 arg1)

{
  *(undefined4 *)(arg0 + 0x48) = arg1;
  return;
}


// sub_080D92D4 @ 0x080D92D4

void sub_080D92D4(int arg0)

{
  sub_080C4388(arg0 + 0x24);
  sub_080AA1BC(*(undefined4 *)(*(int *)(arg0 + 0x48) * 4 + 0x856793c),8,0xf,3);
  return;
}


// sub_080D931C @ 0x080D931C

void sub_080D931C(int arg0,undefined4 arg1)

{
  *(undefined4 *)(arg0 + 0x48) = arg1;
  return;
}


// sub_080D9320 @ 0x080D9320

void sub_080D9320(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000b00;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D9344 @ 0x080D9344

void sub_080D9344(int arg0)

{
  undefined4 in_r2;
  undefined4 arg2;
  
  LZ77UnCompWram(0x8567a04,0x2001000,in_r2);
  arg2 = 0x1000;
  LZ77UnCompWram(0x8567f4c,&DAT_02002000,0x1000);
  LZ77UnCompWram(0x8568218,&DAT_02003000,arg2);
  sub_080ACFCC(3,0x85683d0,0x3003170,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80d9321,1);
  *(undefined4 *)(arg0 + 0x48) = 0;
  *(undefined2 *)(arg0 + 0x28) = 1;
  return;
}


// sub_080D93B8 @ 0x080D93B8

void sub_080D93B8(int arg0)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = sub_080C4388(arg0 + 0x24);
  uVar2 = *(uint *)(arg0 + 0x48);
  if (uVar2 < 10) {
    sub_080AA1BC(*(undefined4 *)(uVar2 * 4 + 0x85683f0),uVar1 & 0xffff,0xe,3);
  }
  else {
    sub_080AA184(*(undefined4 *)(uVar2 * 4 + 0x85683f0),uVar1 & 0xffff,0xe,3);
  }
  return;
}


// sub_080D943C @ 0x080D943C

void sub_080D943C(int arg0)

{
  *(int *)(arg0 + 0x48) = *(int *)(arg0 + 0x48) + 1;
  return;
}


// sub_080D9448 @ 0x080D9448

void sub_080D9448(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6013000;
  REG_DMA3CNT = 0x84000e00;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D946C @ 0x080D946C

void sub_080D946C(int arg0)

{
  undefined4 in_r2;
  undefined4 arg2;
  
  LZ77UnCompWram(0x853131c,0x2001000,in_r2);
  LZ77UnCompWram(0x8531914,&DAT_02002000,0x1000);
  arg2 = 0x2000;
  LZ77UnCompWram(0x8532034,&DAT_02003000,0x2000);
  LZ77UnCompWram(0x8532744,&DAT_02004000,arg2);
  sub_080ACFCC(3,0x8532a9c,0x3003150,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80d9449,1);
  *(undefined4 *)(arg0 + 0x48) = 0;
  *(undefined2 *)(arg0 + 0x28) = 1;
  return;
}


// sub_080D94F0 @ 0x080D94F0

void sub_080D94F0(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C4388(arg0 + 0x24);
  sub_080AA1BC(*(undefined4 *)(*(int *)(arg0 + 0x48) * 4 + 0x8568c14),uVar1 & 0xffff,0xd,3);
  return;
}


// sub_080D953C @ 0x080D953C

void sub_080D953C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016800;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D9560 @ 0x080D9560

void sub_080D9560(int arg0)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x8550398,0x2001000,in_r2);
  sub_080ACFCC(3,0x8550ebc,0x3003170,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80d953d,1);
  *(undefined4 *)(arg0 + 0x48) = 0;
  *(undefined2 *)(arg0 + 0x28) = 1;
  return;
}


// sub_080D95B0 @ 0x080D95B0

void sub_080D95B0(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C4388(arg0 + 0x24);
  sub_080AA184(0x80061a0,uVar1 & 0xffff,0xe,3);
  return;
}


// sub_080D95F4 @ 0x080D95F4

int sub_080D95F4(uint arg0)

{
  return (arg0 & 0xffff) * 0x2c + 0x8568d78;
}


// sub_080D9608 @ 0x080D9608

void sub_080D9608(void)

{
  undefined4 uVar1;
  undefined2 local_14 [2];
  undefined4 local_10;
  undefined4 local_c;
  
  sub_080C1450();
  local_14[0] = 0;
  REG_DMA3SAD = local_14;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x81002000;
  uVar1 = REG_DMA3CNT;
  Font_ResetGlyphSpriteCache(0x180);
  sub_080AB78C();
  sub_080C1328();
  sub_080C1384();
  local_10 = 0;
  CpuSet(&local_10,0x201d874,0x5001a00);
  local_c = 0;
  CpuSet(&local_c,0x2024074,0x5001000);
  REG_IE._0_2_ = 0x2003;
  REG_DISPSTAT = 0x18;
  REG_IME = 1;
  sub_080ACFF4();
  sub_080AE2D0();
  sub_080D110C(4,3);
  sub_080C5170(0xd);
  sub_080A9AB4(0x80d977d);
  return;
}


// sub_080D96BC @ 0x080D96BC

void sub_080D96BC(void)

{
  undefined4 uVar1;
  undefined2 local_14 [2];
  undefined4 local_10;
  undefined4 local_c;
  
  sub_080C1450();
  local_14[0] = 0;
  REG_DMA3SAD = local_14;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x81002000;
  uVar1 = REG_DMA3CNT;
  Font_ResetGlyphSpriteCache(0x180);
  local_10 = 0;
  CpuSet(&local_10,0x201d874,0x5001a00);
  local_c = 0;
  CpuSet(&local_c,0x2024074,0x5001000);
  REG_IE._0_2_ = 0x2003;
  REG_DISPSTAT = 0x18;
  REG_IME = 1;
  sub_080ACFF4();
  sub_080AE2D0();
  DAT_03006098 = 0;
  sub_080AD0FC(0x85816b8,0xffff);
  sub_080C5170(0xd);
  DAT_0300609c = 0;
  sub_080A9AB4(0x80d977d);
  return;
}


