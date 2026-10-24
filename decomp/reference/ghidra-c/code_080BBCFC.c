/* Ghidra decompilation of asm/code_080BBCFC.s (reference only; not compiled). */

// sub_080BBCFC @ 0x080BBCFC

void sub_080BBCFC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016800;
  REG_DMA3CNT = 0x84000600;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BBD20 @ 0x080BBD20

void sub_080BBD20(undefined4 arg0,int arg1)

{
  dword arg0_00;
  undefined4 in_r2;
  uint uVar1;
  
  if (arg1 == 0) {
    LZ77UnCompWram(0x8174294,0x2001000,in_r2);
    sub_080ACFCC(3,0x8174cf8,0x3003170,0x20);
    arg0_00 = 0x80bbcd9;
  }
  else {
    if (arg1 != 1) {
      uVar1 = arg1 - 2U & 0xffff;
      LZ77UnCompWram(*(undefined4 *)(uVar1 * 4 + 0x818b5f0),uVar1 * 0x800 + 0x2001000,0x2001000);
      if (uVar1 == 6) {
        sub_080ACFCC(3,0x817748c,0x3003170,0x20);
        DisplayList_Add(0x80bbcd9,1);
      }
      goto LAB_080bbdc8;
    }
    LZ77UnCompWram(0x8174d18,0x2001000,in_r2);
    sub_080ACFCC(3,0x81755f0,0x3003190,0x20);
    arg0_00 = 0x80bbcfd;
  }
  DisplayList_Add(arg0_00,1);
LAB_080bbdc8:
  sub_080AABB0();
  return;
}


// sub_080BBDE8 @ 0x080BBDE8

void sub_080BBDE8(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x24) = (undefined2)arg1;
  return;
}


// sub_080BBDEC @ 0x080BBDEC

void sub_080BBDEC(int arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  int in_stack_00000000;
  
  iVar1 = sub_080AD0FC(arg1,(uint)*(ushort *)(arg0 + 2));
  *(undefined2 *)(iVar1 + 0x26) = (undefined2)arg2;
  *(undefined2 *)(iVar1 + 0x28) = (undefined2)arg3;
  if (in_stack_00000000 == 1) {
    *(int *)(arg0 + 0x30) = iVar1;
  }
  if (in_stack_00000000 == 2) {
    *(int *)(arg0 + 0x34) = iVar1;
  }
  return;
}


// sub_080BBE20 @ 0x080BBE20

void sub_080BBE20(int arg0)

{
  sub_080AA184(*(undefined4 *)((uint)*(ushort *)(arg0 + 0x24) * 4 + 0x818b60c),6,0xe,2);
  return;
}


// sub_080BBE54 @ 0x080BBE54

void sub_080BBE54(int arg0)

{
  sub_080AA184(*(undefined4 *)((uint)*(ushort *)(arg0 + 0x24) * 4 + 0x818b720),9,0xf,3);
  return;
}


// sub_080BBE88 @ 0x080BBE88

void sub_080BBE88(int arg0)

{
  short sVar1;
  
  sub_080AA184(*(undefined4 *)((uint)*(ushort *)(arg0 + 0x24) * 4 + 0x818b720),9,0xf,3);
  if (((DAT_030031bc & 7) == 0) &&
     (sVar1 = *(short *)(arg0 + 0x24) + 1, *(short *)(arg0 + 0x24) = sVar1, sVar1 == 0xd)) {
    *(undefined2 *)(arg0 + 0x24) = 7;
  }
  return;
}


// sub_080BBEE8 @ 0x080BBEE8

void sub_080BBEE8(int arg0)

{
  *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) + -1;
  return;
}


// sub_080BBEF4 @ 0x080BBEF4

void sub_080BBEF4(int arg0)

{
  sub_080AD1FC(*(undefined4 *)(arg0 + 0x34));
  return;
}


// sub_080BBF00 @ 0x080BBF00

void sub_080BBF00(int arg0)

{
  sub_080AA184(*(undefined4 *)((uint)*(ushort *)(arg0 + 0x24) * 4 + 0x818b834),4,0xe,2);
  return;
}


// sub_080BBF34 @ 0x080BBF34

void sub_080BBF34(int arg0)

{
  sub_080AA184(*(undefined4 *)((uint)*(ushort *)(arg0 + 0x24) * 4 + 0x818b960),7,0xe,2);
  return;
}


// sub_080BBF68 @ 0x080BBF68

void sub_080BBF68(int arg0)

{
  *(short *)(*(int *)(arg0 + 0x30) + 0x28) = *(short *)(*(int *)(arg0 + 0x30) + 0x28) + -1;
  return;
}


// sub_080BBF74 @ 0x080BBF74

void sub_080BBF74(void)

{
  sub_080B8AE0(0x7fff,1);
  return;
}


// sub_080BBF88 @ 0x080BBF88

void sub_080BBF88(void)

{
  sub_080AB0F0(0x1e0,0x20,1);
  return;
}


// sub_080BBF9C @ 0x080BBF9C

void sub_080BBF9C(int arg0)

{
  sub_080AD1FC(*(undefined4 *)(arg0 + 0x30));
  return;
}


// sub_080BBFA8 @ 0x080BBFA8

void sub_080BBFA8(void)

{
  sub_080C4618(0,0x161,0x28,3);
  return;
}


// sub_080BBFC8 @ 0x080BBFC8

void sub_080BBFC8(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080BC230(0x161);
  *(ushort *)(arg0 + 0x1c) = (ushort)(*(int *)(iVar1 + 0xc) == -1);
  return;
}


// sub_080BBFF0 @ 0x080BBFF0

void sub_080BBFF0(void)

{
  int iVar1;
  
  iVar1 = sub_080BC230(0x161);
  *(undefined4 *)(iVar1 + 0xc) = 1;
  return;
}


// sub_080BC004 @ 0x080BC004

void sub_080BC004(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080BC230(0x161);
  *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 == 0);
  return;
}


// sub_080BC028 @ 0x080BC028

void sub_080BC028(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BC04C @ 0x080BC04C

void sub_080BC04C(int arg0)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x818c0c8,0x2001000,in_r2);
  sub_080ACFCC(3,0x818c5e0,0x3003150,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80bc029,1);
  *(undefined2 *)(arg0 + 0x24) = 1;
  *(undefined2 *)(arg0 + 0x26) = 4;
  *(undefined2 *)(arg0 + 0x28) = 4;
  *(undefined2 *)(arg0 + 0x2a) = 0;
  return;
}


// sub_080BC0A4 @ 0x080BC0A4

void sub_080BC0A4(int arg0)

{
  ushort uVar1;
  undefined *local_20;
  int local_1c;
  
  uVar1 = *(ushort *)(arg0 + 0x26);
  __divsi3((uint)uVar1 * 0x28,0xff);
  __divsi3((uint)uVar1 * 0x24,0xff);
  local_20 = &DAT_0800784c;
  local_1c = arg0 + 0x24;
  sub_0815851C(&local_20);
  local_20 = (undefined *)0x3003800;
  local_1c = arg0 + 0x24;
  sub_080AA790(&local_20,0,0xd,0);
  sub_080AA790(&local_20,0,0xd,0);
  return;
}


// sub_080BC154 @ 0x080BC154

void sub_080BC154(int arg0)

{
  *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + 4;
  *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) + 4;
  return;
}


// sub_080BC164 @ 0x080BC164

void sub_080BC164(void)

{
  undefined4 in_r0;
  
  sub_080BC260(in_r0,0xbe);
  return;
}


// sub_080BC170 @ 0x080BC170

void sub_080BC170(void)

{
  sub_080BA7A0(1);
  sub_080BA7CC(0x818f010,0x818eea0,0xe,0x1a);
  return;
}


// sub_080BC198 @ 0x080BC198

void sub_080BC198(void)

{
  uint uVar1;
  
  if ((DAT_030031bc & 1) == 0) {
    uVar1 = sub_080C2244();
    sub_080C4618(3,200,(uVar1 & 0x7f) + 0x30,0);
    uVar1 = sub_080C2244();
    sub_080C4618(4,0xc9,(uVar1 & 0x7f) + 0x30,0);
    uVar1 = sub_080C2244();
    sub_080C4618(5,0xca,(uVar1 & 0x7f) + 0x30,0);
  }
  return;
}


// sub_080BC200 @ 0x080BC200

void sub_080BC200(void)

{
  DAT_0300000e = DAT_0300000e + -1;
  sub_080BA7CC(0x818f010,0x818eea0,0xe,0x1a);
  return;
}


// sub_080BC230 @ 0x080BC230

undefined4 sub_080BC230(undefined4 arg0)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  piVar2 = (int *)0x2036094;
  while ((iVar1 = *piVar2, iVar1 == 0 || (*(short *)(iVar1 + 0x2a) != (short)arg0))) {
    piVar2 = piVar2 + 1;
    uVar3 = uVar3 + 1;
    if (5 < uVar3) {
      return 0;
    }
  }
  return iVar1;
}


// sub_080BC260 @ 0x080BC260

void sub_080BC260(undefined4 arg0,uint arg1)

{
  int arg0_00;
  
  arg0_00 = sub_080BC230(arg1 & 0xffff);
  if (arg0_00 != 0) {
    sub_080C48F0(arg0_00);
  }
  return;
}


// sub_080BC278 @ 0x080BC278

void sub_080BC278(int arg0,undefined4 arg1)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  switch(arg1) {
  case 0:
    sub_080BC260(arg0,0xb0);
    sub_080BC260(arg0,0xb1);
    uVar1 = 0xc5;
    goto LAB_080bc456;
  case 1:
    uVar1 = 0xc6;
LAB_080bc456:
    sub_080C4618(2,uVar1,0x51,0x40);
    break;
  case 2:
    sub_080BAD88(arg0,0xc6,0,0xffffffff);
    break;
  case 3:
  case 4:
    sub_080C4618(2,199,0x50,0xff70);
    break;
  case 7:
    sub_080B0820();
    break;
  case 8:
    DAT_0300000e = 0;
    break;
  case 9:
    sub_080B4140();
    sub_080B0778();
    break;
  case 100:
    uVar1 = 0xc5;
    goto LAB_080bc4ac;
  case 0x65:
    uVar1 = 199;
LAB_080bc4ac:
    iVar2 = sub_080BC230(uVar1);
    if (*(int *)(iVar2 + 0xc) == -1) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  return;
}


// sub_080BC4C8 @ 0x080BC4C8

void sub_080BC4C8(undefined4 arg0,int arg1)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    iVar1 = sub_080BC230(0xd8);
    if (iVar1 != 0) {
      sub_080C48F0(iVar1);
    }
  }
  else if (((arg1 != 1) && (arg1 == 2)) && (iVar1 = sub_080BC230(0xd9), iVar1 != 0)) {
    sub_080C48F0(iVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x080bc4fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BC4FC @ 0x080BC4FC

void sub_080BC4FC(void)

{
  int iVar1;
  
  iVar1 = sub_080BC230(0xd9);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 1;
  }
  iVar1 = sub_080BC230(0x1be);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 1;
  }
  iVar1 = sub_080BC230(0x1bf);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 1;
  }
  iVar1 = sub_080BC230(0x16b);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 1;
  }
  iVar1 = sub_080BC230(0x16c);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 1;
  }
  return;
}


// sub_080BC560 @ 0x080BC560

void sub_080BC560(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016800;
  REG_DMA3CNT = 0x84000300;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BC584 @ 0x080BC584

void sub_080BC584(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6013000;
  REG_DMA3CNT = 0x84000e00;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BC5A8 @ 0x080BC5A8

void sub_080BC5A8(undefined4 arg0,int arg1)

{
  int arg0_00;
  dword arg0_01;
  undefined4 uVar1;
  
  if (arg1 == 0) {
    uVar1 = 0x78;
    sub_080C4618(2,0xd9,0x78,0x46);
    arg0_00 = sub_080BC230(0xd8);
    if (arg0_00 != 0) {
      sub_080C48F0(arg0_00);
    }
    LZ77UnCompWram(0x8554e10,0x2001000,uVar1);
    LZ77UnCompWram(0x8555260,&DAT_02001800,uVar1);
    sub_080ACFCC(3,0x8555694,0x3003190,0x20);
    sub_080AABB0();
    arg0_01 = 0x80bc561;
  }
  else {
    if (arg1 != 1) {
      if (arg1 != 2) {
        return;
      }
      sub_080C4618(2,0x1be,0x78,0x46);
      sub_080C4618(3,0x1bf,0x78,0x46);
      sub_080C4618(0,0x16d,0x78,0x36);
      return;
    }
    sub_080C4618(4,0x16b,0x78,0x36);
    uVar1 = 0x78;
    sub_080C4618(5,0x16c,0x78,0x46);
    LZ77UnCompWram(0x8552ce0,0x2001000,uVar1);
    LZ77UnCompWram(0x85537c8,&DAT_02002000,0x1000);
    uVar1 = 0x2000;
    LZ77UnCompWram(0x8554300,&DAT_02003000,0x2000);
    LZ77UnCompWram(0x8554ae4,&DAT_02004000,uVar1);
    sub_080ACFCC(3,0x8554ac4,0x3003150,0x20);
    sub_080ACFCC(3,0x8554df0,&DAT_03003170,0x20);
    sub_080AABB0();
    arg0_01 = 0x80bc585;
  }
  DisplayList_Add(arg0_01,1);
  return;
}


// sub_080BC710 @ 0x080BC710

void sub_080BC710(undefined4 arg0,int arg1)

{
  int iVar1;
  
  sub_080BC230(0x1be);
  if (arg1 == 0) {
    iVar1 = sub_080BC230(0x1be);
    *(short *)(iVar1 + 0x2e) = *(short *)(iVar1 + 0x2e) + -1;
    iVar1 = sub_080BC230(0x16d);
    *(short *)(iVar1 + 0x2e) = *(short *)(iVar1 + 0x2e) + -1;
  }
  iVar1 = sub_080BC230(0x1bf);
  *(short *)(iVar1 + 0x2e) = *(short *)(iVar1 + 0x2e) + 1;
  iVar1 = sub_080BC230(0x16b);
  *(short *)(iVar1 + 0x2e) = *(short *)(iVar1 + 0x2e) + 1;
  iVar1 = sub_080BC230(0x16c);
  *(short *)(iVar1 + 0x2e) = *(short *)(iVar1 + 0x2e) + 1;
  iVar1 = sub_080C2340(0xc6);
  if (iVar1 == 0) {
    DAT_03000034 = 0xe0;
    DAT_03000035 = 0x68;
    DAT_03000038 = 0x3d;
  }
  else {
    DAT_03000032 = 0xe8;
    DAT_03000033 = 8;
    DAT_03000036 = 0x68;
    DAT_03000034 = 0x68;
    DAT_03000037 = 0;
    DAT_03000035 = 0;
    DAT_03000038 = 0x3f;
    DAT_03000039 = 0x3f;
    DAT_0300003a = 0;
    DAT_0300003b = 0;
  }
  DAT_03000031 = 8;
  DAT_03000030 = 0xe8;
  DAT_03000006 = DAT_03000006 + -1;
  return;
}


// sub_080BC83C @ 0x080BC83C

void sub_080BC83C(void)

{
  DAT_03000006 = 0;
  DAT_03000038 = 0x3f;
  DisplayList_Add(0x80bad29,1);
  return;
}


// sub_080BC864 @ 0x080BC864

void sub_080BC864(void)

{
  int iVar1;
  
  iVar1 = sub_080BC230(0x1bb);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 1;
  }
  iVar1 = sub_080BC230(0x1bd);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 1;
  }
  iVar1 = sub_080BC230(0x1b9);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 1;
  }
  iVar1 = sub_080BC230(0x1ba);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 1;
  }
  return;
}


// sub_080BC8B8 @ 0x080BC8B8

void sub_080BC8B8(void)

{
  sub_080C4618(3,0x1bb,0x78,0x46);
  return;
}


// sub_080BC8D8 @ 0x080BC8D8

void sub_080BC8D8(undefined4 arg0,int arg1)

{
  int iVar1;
  
  iVar1 = sub_080BC230(0x1bb);
  sub_080D95F4((uint)*(ushort *)(iVar1 + 0x2a));
  *(short *)(iVar1 + 0x3c) = (short)arg1;
  if (arg1 - 3U < 2) {
    iVar1 = sub_080BC230(0x1b9);
    *(short *)(iVar1 + 0x2e) = *(short *)(iVar1 + 0x2e) + -1;
    iVar1 = sub_080BC230(0x1ba);
    *(short *)(iVar1 + 0x2e) = *(short *)(iVar1 + 0x2e) + -1;
  }
  return;
}


// sub_080BC924 @ 0x080BC924

void sub_080BC924(void)

{
  sub_080B8AE0(0x7fff,1);
  sub_080C4618(4,0x1bd,0x78,0x46);
  sub_080C4618(5,0x1b9,0x78,0x36);
  sub_080C4618(6,0x1ba,0x78,0x3e);
  return;
}


// sub_080BC978 @ 0x080BC978

void sub_080BC978(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001800;
  REG_DMA3DAD = 0x6013000;
  REG_DMA3CNT = 0x84000c00;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BC99C @ 0x080BC99C

void sub_080BC99C(void)

{
  undefined4 in_r2;
  undefined4 arg2;
  
  LZ77UnCompWram(0x85537c8,0x2001000,in_r2);
  arg2 = 0x1000;
  LZ77UnCompWram(0x8554300,&DAT_02002000,0x1000);
  LZ77UnCompWram(0x8174d18,&DAT_02003000,arg2);
  sub_080ACFCC(3,0x8554ac4,0x3003170,0x20);
  sub_080ACFCC(3,0x81755f0,&DAT_03003190,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80bc979,1);
  return;
}


// sub_080BCA1C @ 0x080BCA1C

void sub_080BCA1C(void)

{
  sub_080AB138(0x1e0,0x10,1,0x20);
  sub_080AB138(0x1f0,0x10,1,0x20);
  return;
}


// sub_080BCA40 @ 0x080BCA40

void sub_080BCA40(undefined4 arg0,int arg1)

{
  sub_080AA184(*(undefined4 *)(arg1 * 4 + 0x818f54c),0,0xe,0);
  return;
}


// sub_080BCA6C @ 0x080BCA6C

void sub_080BCA6C(undefined4 arg0,int arg1)

{
  sub_080AA184(*(undefined4 *)(arg1 * 4 + 0x818f634),7,0xf,2);
  return;
}


// sub_080BCA9C @ 0x080BCA9C

void sub_080BCA9C(int arg0,int arg1)

{
  undefined4 uVar1;
  
  if (arg1 == 0) {
    uVar1 = sub_080AD0FC(0x818f564,0xffff);
    *(undefined4 *)(arg0 + 0x24) = uVar1;
  }
  else {
    uVar1 = sub_080AD0FC(0x818f650,0xffff);
    *(undefined4 *)(arg0 + 0x28) = uVar1;
  }
  return;
}


// sub_080BCAD4 @ 0x080BCAD4

void sub_080BCAD4(int arg0)

{
  sub_080AD1FC(*(undefined4 *)(arg0 + 0x24));
  sub_080AD1FC(*(undefined4 *)(arg0 + 0x28));
  return;
}


// sub_080BCAEC @ 0x080BCAEC

void sub_080BCAEC(int arg0)

{
  *(undefined2 *)(arg0 + 0x26) = 4;
  *(undefined2 *)(arg0 + 0x28) = 4;
  *(undefined2 *)(arg0 + 0x2a) = 0;
  return;
}


// sub_080BCAFC @ 0x080BCAFC

void sub_080BCAFC(int arg0)

{
  ushort uVar1;
  undefined *local_1c;
  int local_18;
  
  uVar1 = *(ushort *)(arg0 + 0x26);
  __divsi3((uint)uVar1 * 0x28,0xff);
  __divsi3((uint)uVar1 * 0x24,0xff);
  local_1c = &DAT_08006144;
  local_18 = arg0 + 0x24;
  sub_0815851C(&local_1c);
  local_1c = (undefined *)0x3003800;
  if ((DAT_030031bc & 1) != 0) {
    local_18 = arg0 + 0x24;
    sub_080AA184(0x8006170,0,0xd,0);
  }
  return;
}


// sub_080BCB80 @ 0x080BCB80

void sub_080BCB80(int arg0,undefined4 arg1)

{
  *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + (short)arg1;
  *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) + (short)arg1;
  return;
}


// sub_080BCB90 @ 0x080BCB90

void sub_080BCB90(undefined4 arg0,int arg1)

{
  int iVar1;
  
  if (arg1 == 0) {
    sub_080C4618(0,0x195,0xf0,0xfff3);
  }
  else {
    iVar1 = sub_080BC230(0x195);
    *(short *)(iVar1 + 0x2c) = *(short *)(iVar1 + 0x2c) + -1;
    DAT_03000004 = DAT_03000004 + 1;
  }
  return;
}


// sub_080BCBD8 @ 0x080BCBD8

void sub_080BCBD8(int arg0,int arg1)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    sub_080C4618(1,0xc0,0x50,0xffd3);
  }
  else {
    iVar1 = sub_080BC230(0xc0);
    *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 == 0);
  }
                    /* WARNING: Could not recover jumptable at 0x080bcc10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BCC14 @ 0x080BCC14

void sub_080BCC14(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6017800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BCC38 @ 0x080BCC38

void sub_080BCC38(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x8532abc,0x2001000,in_r2);
  sub_080ACFCC(3,0x8532d50,0x3003150,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80bcc15,1);
  return;
}


// sub_080BCC7C @ 0x080BCC7C

void sub_080BCC7C(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_080AD0FC(0x818f760,0xffff);
  uVar2 = sub_080C2244();
  *(ushort *)(iVar1 + 0x2e) = ((ushort)uVar2 & 0x3f) + 0x30;
  uVar2 = sub_080C2244();
  *(ushort *)(iVar1 + 0x30) = ((ushort)uVar2 & 0x3f) - 0xd;
  return;
}


// sub_080BCCB4 @ 0x080BCCB4

void sub_080BCCB4(undefined4 arg0,undefined4 arg1)

{
  switch(arg1) {
  case 0:
    sub_080C4618(1,0xcb,0x50,0x6b);
    break;
  case 1:
    DAT_0300000e = DAT_0300000e + -1;
    break;
  case 2:
    sub_080C4618(0,0xc6,0x50,0xffc0);
    break;
  case 4:
    DAT_0300000e = DAT_0300000e + 1;
  case 3:
    sub_080BAD88(arg0,0xc6,0,1);
    break;
  case 6:
    sub_080BCDC4();
    break;
  case 7:
    sub_080C3818(1);
    break;
  case 8:
    DAT_030068f0 = sub_080C4618(0,0x1c4,0x50,0x6b);
    break;
  case 9:
    sub_080BCE0C();
  }
  return;
}


// sub_080BCD84 @ 0x080BCD84

void sub_080BCD84(void)

{
  DAT_0200e808 = 1;
  sub_080AB0F0(0,0x200,8);
  return;
}


// sub_080BCDA0 @ 0x080BCDA0

void sub_080BCDA0(undefined4 arg0,uint arg1,undefined4 arg2)

{
  sub_080C4618(0,arg1 & 0xffff,0x50,0xffd3);
  return;
}


// sub_080BCDC4 @ 0x080BCDC4

void sub_080BCDC4(void)

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


// sub_080BCE0C @ 0x080BCE0C

void sub_080BCE0C(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 arg1;
  dword arg2;
  uint uVar4;
  
  if ((DAT_0200ab04 & 0x8000) == 0) {
    sub_080B04BC();
    sub_080AB054(0x80,0x80,2,0x20);
  }
  else {
    sub_080B4140();
    sub_080AB054(0x80,0x80,2,0x20);
  }
  uVar4 = 0;
  do {
    iVar2 = *(int *)(uVar4 * 4 + 0x2036094);
    if (iVar2 != 0) {
      iVar3 = sub_080D95F4((uint)*(ushort *)(iVar2 + 0x2a));
      arg1 = *(undefined4 *)(iVar3 + 0x24);
      uVar1 = DAT_0203db28;
      if ((*(short *)(iVar2 + 0x2a) == 0x1c1) ||
         (uVar1 = DAT_0203db2a, *(short *)(iVar2 + 0x2a) == 0x1c0)) {
        iVar3 = sub_080D8248((uint)uVar1);
        arg1 = *(undefined4 *)(iVar3 + 4);
      }
      if (*(short *)(iVar2 + 0x28) == 1) {
        if (*(short *)(iVar2 + 0x26) == 0) {
          arg2 = 0x3002d70;
        }
        else {
          if (*(short *)(iVar2 + 0x26) != 1) {
            sub_080ACFCC(3,arg1,0x3002d50,0x20);
            goto LAB_080bced0;
          }
          arg2 = 0x3002d90;
        }
        sub_080ACFCC(3,arg1,arg2,0x20);
      }
    }
LAB_080bced0:
    uVar4 = uVar4 + 1;
    if (5 < uVar4) {
      sub_080AB054(0x1d0,0x30,2,0x20);
      return;
    }
  } while( true );
}


// sub_080BCEF0 @ 0x080BCEF0

void sub_080BCEF0(void)

{
  undefined4 uVar1;
  undefined4 local_c;
  
  REG_DMA3SAD = &local_c;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85001000;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = &local_c;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x85000020;
  uVar1 = REG_DMA3CNT;
  local_c = 0;
  REG_DMA3SAD = &local_c;
  REG_DMA3DAD = 0x6008000;
  REG_DMA3CNT = 0x85000020;
  uVar1 = REG_DMA3CNT;
  sub_080C1450();
  DAT_03000032 = 0xe8;
  DAT_03000030 = 0xe8;
  DAT_03000033 = 8;
  DAT_03000031 = 8;
  DAT_03000036 = 0x68;
  DAT_03000034 = 0x68;
  DAT_03000037 = 0;
  DAT_03000035 = 0;
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0;
  DAT_0300003b = 0;
  return;
}


// sub_080BCFB0 @ 0x080BCFB0

void sub_080BCFB0(void)

{
  DAT_0200e808 = 1;
  return;
}


// sub_080BCFBC @ 0x080BCFBC

void sub_080BCFBC(undefined4 arg0)

{
  sub_080C6E30(1);
  DAT_0200e804 = 1;
  sub_080BCFB0();
  DAT_03004534 = 0;
  DisplayList_Add(0x80bcef1,1);
  return;
}


// sub_080BCFF4 @ 0x080BCFF4

void sub_080BCFF4(undefined4 arg0,undefined4 arg1,int arg2)

{
  int arg2_00;
  
  arg2_00 = arg2;
  HuffUnComp(arg1,0x200afc8,arg2);
  LZ77UnCompWram(0x200afc8,arg2 + 0x2001000,arg2_00);
  return;
}


// sub_080BD01C @ 0x080BD01C

void sub_080BD01C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84001500;
  uVar1 = REG_DMA3CNT;
  REG_DISPCNT = 0x7800;
  DAT_03000032 = 0xe8;
  DAT_03000030 = 0xe8;
  DAT_03000033 = 8;
  DAT_03000031 = 8;
  DAT_03000036 = 0x68;
  DAT_03000034 = 0x68;
  DAT_03000037 = 0;
  DAT_03000035 = 0;
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0;
  DAT_0300003b = 0;
  DAT_0300000e = 0;
  DAT_0300000c = 0;
  return;
}


// sub_080BD0E0 @ 0x080BD0E0

void sub_080BD0E0(void)

{
  undefined4 in_r2;
  
  HuffUnComp(0x8194c78,0x200afc8,in_r2);
  LZ77UnCompWram(0x200afc8,0x2000000,in_r2);
  sub_080ACFCC(3,0x8195278,0x30029b0,0x100);
  DisplayList_Add(0x80bd01d,1);
  return;
}


// sub_080BD130 @ 0x080BD130

void sub_080BD130(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6010000;
  REG_DMA3CNT = 0x84001000;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080BD154 @ 0x080BD154

void sub_080BD154(int arg0)

{
  sub_080ACFCC(3,0x8196438,0x3002d70,0x20);
  sub_080ACFCC(3,0x8196c80,&DAT_03002d90,0x20);
  DisplayList_Add(0x80bd131,1);
  *(undefined2 *)(arg0 + 0x26) = 0x100;
  *(undefined2 *)(arg0 + 0x28) = 0x100;
  *(undefined2 *)(arg0 + 0x2a) = 0;
  *(undefined2 *)(arg0 + 0x2c) = 0;
  *(undefined2 *)(arg0 + 0x2e) = 0x20;
  *(undefined2 *)(arg0 + 0x30) = 0x78;
  *(undefined2 *)(arg0 + 0x32) = 0xfff8;
  *(undefined2 *)(arg0 + 0x34) = 0x118;
  *(undefined2 *)(arg0 + 0x36) = 0x48;
  return;
}


// sub_080BD1C4 @ 0x080BD1C4

void sub_080BD1C4(int arg0)

{
  short sVar1;
  dword *pdVar2;
  int iVar3;
  dword local_14;
  int local_10;
  
  iVar3 = arg0 + 0x24;
  pdVar2 = (dword *)0x80075d8;
  if ((DAT_030031bc >> 2 & 1) == 0) {
    pdVar2 = (dword *)0x80075a0;
  }
  local_14 = *pdVar2;
  local_10 = iVar3;
  sub_0815862C(&local_14,(uint)*(ushort *)(arg0 + 0x26),(uint)*(ushort *)(arg0 + 0x28),0);
  local_14 = 0x3003800;
  if (*(short *)(arg0 + 0x26) != 4) {
    local_10 = iVar3;
    sub_080AA790(&local_14,0,0xf,0);
  }
  local_14 = **(dword **)((uint)*(ushort *)(arg0 + 0x2c) * 4 + 0x8196ca0);
  local_10 = iVar3;
  sub_0815862C(&local_14,(uint)*(ushort *)(arg0 + 0x26),(uint)*(ushort *)(arg0 + 0x28),0);
  local_14 = 0x3003800;
  if (*(short *)(arg0 + 0x26) != 4) {
    local_10 = iVar3;
    sub_080AA790(&local_14,0,0xe,0);
  }
  if ((*(short *)(arg0 + 0x2c) != 0xc) &&
     (sVar1 = *(short *)(arg0 + 0x2e) + -1, *(short *)(arg0 + 0x2e) = sVar1, sVar1 == 0)) {
    *(undefined2 *)(arg0 + 0x2e) = 0x20;
    *(short *)(arg0 + 0x2c) = *(short *)(arg0 + 0x2c) + 1;
  }
  if ((DAT_030031bc & 3) == 0) {
    DAT_0300000e = DAT_0300000e + 1;
  }
  return;
}


// sub_080BD2A8 @ 0x080BD2A8

void sub_080BD2A8(int arg0)

{
  if ((DAT_030031bc & 3) == 0) {
    *(short *)(arg0 + 0x32) = *(short *)(arg0 + 0x32) + 1;
  }
  return;
}


// sub_080BD2C8 @ 0x080BD2C8

void sub_080BD2C8(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (*(short *)(arg0 + 0x2c) == 0xc) {
    *(undefined2 *)(arg0 + 0x36) = *(undefined2 *)(arg0 + 0x32);
    *(undefined2 *)(arg0 + 0x34) = *(undefined2 *)(arg0 + 0x30);
    if (*(short *)(arg0 + 0x26) == 4) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    else {
      *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + -2;
      *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) + -2;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080bd2fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BD2FC @ 0x080BD2FC

void sub_080BD2FC(undefined4 arg0,uint arg1)

{
  sub_080AB008(1,0x1ff,arg1 & 0xffff);
  return;
}


// sub_080BD314 @ 0x080BD314

void sub_080BD314(void)

{
  sub_080C2364(0xfd);
  sub_080C2364(0x10d);
  sub_080C2364(0x10e);
  return;
}


// sub_080BD334 @ 0x080BD334

void sub_080BD334(void)

{
  DAT_03000032 = 0xe8;
  DAT_03000030 = 0xe8;
  DAT_03000033 = 8;
  DAT_03000031 = 8;
  DAT_03000036 = 0x68;
  DAT_03000034 = 0x68;
  DAT_03000037 = 0;
  DAT_03000035 = 0;
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0;
  DAT_0300003b = 0;
  DAT_0300000e = 0;
  DAT_0300000c = 0;
  DAT_03000006 = 0;
  DAT_03000004 = 0;
  return;
}


// sub_080BD3C4 @ 0x080BD3C4

void sub_080BD3C4(void)

{
  DisplayList_Add(0x80bd335,1);
  return;
}


// sub_080BD3D8 @ 0x080BD3D8

void sub_080BD3D8(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B6DB4(0x6d);
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  return;
}


// sub_080BD3EC @ 0x080BD3EC

void sub_080BD3EC(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(ushort *)(arg0 + 0x1c) = (ushort)(**(short **)(arg0 + 0x24) == 0);
                    /* WARNING: Could not recover jumptable at 0x080bd402. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BD404 @ 0x080BD404

void sub_080BD404(void)

{
  int iVar1;
  
  iVar1 = sub_080BC230(0x11e);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 3;
  }
  return;
}


// sub_080BD41C @ 0x080BD41C

void sub_080BD41C(void)

{
  sub_080AB138(0x1e0,0x10,0x10,8);
  sub_080AB138(0x80,0x80,0x10,8);
  return;
}


// sub_080BD43C @ 0x080BD43C

void sub_080BD43C(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B6DB4(0x71);
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  return;
}


// sub_080BD450 @ 0x080BD450

void sub_080BD450(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(ushort *)(arg0 + 0x1c) = (ushort)(**(short **)(arg0 + 0x24) == 0);
                    /* WARNING: Could not recover jumptable at 0x080bd466. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BD468 @ 0x080BD468

void sub_080BD468(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x600f800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  REG_DISPCNT = 0x7900;
  REG_BG0CNT = 0x800b;
  REG_BG3CNT = 0x8604;
  DAT_03000032 = 0xe8;
  DAT_03000030 = 0xe8;
  DAT_03000033 = 8;
  DAT_03000031 = 8;
  DAT_03000036 = 0x68;
  DAT_03000034 = 0x68;
  DAT_03000037 = 0;
  DAT_03000035 = 0;
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0;
  DAT_0300003b = 0;
  DAT_0300000e = 0;
  DAT_0300000c = 0;
  DAT_03000002 = 0;
  DAT_03000000 = 0;
  return;
}


// sub_080BD550 @ 0x080BD550

void sub_080BD550(void)

{
  sub_080AB250(0x81974f4,0x2000000,0x3c0,8);
  DisplayList_Add(0x80bd469,1);
  return;
}


// sub_080BD58C @ 0x080BD58C

void sub_080BD58C(void)

{
  sub_080C2364(0xfd);
  return;
}


// sub_080BD598 @ 0x080BD598

void sub_080BD598(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080BC230(0x21);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(short *)(iVar1 + 0x2c) = *(short *)(iVar1 + 0x2c) + -1;
  *(ushort *)(iVar1 + 0x24) = *(ushort *)(iVar1 + 0x24) | 0x20;
  *(undefined2 *)(iVar1 + 0x36) = 1;
  if (*(ushort *)(iVar1 + 0x2c) < 0x51) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080BD5CC @ 0x080BD5CC

void sub_080BD5CC(int arg0)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x818c0c8,0x2001000,in_r2);
  sub_080ACFCC(3,0x818c600,0x3003150,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80bc029,1);
  *(undefined2 *)(arg0 + 0x24) = 1;
  *(undefined2 *)(arg0 + 0x26) = 0x140;
  *(undefined2 *)(arg0 + 0x28) = 0x140;
  *(undefined2 *)(arg0 + 0x2a) = 0;
  return;
}


// sub_080BD628 @ 0x080BD628

void sub_080BD628(int arg0,undefined4 arg1)

{
  undefined *local_14;
  int local_10;
  
  local_14 = &DAT_0800787c;
  local_10 = arg0 + 0x24;
  sub_0815862C(&local_14,(uint)*(ushort *)(arg0 + 0x26),(uint)*(ushort *)(arg0 + 0x28),0);
  local_14 = (undefined *)0x3003800;
  local_10 = arg0 + 0x24;
  sub_080AA998(&local_14,0,0xd,0);
  return;
}


// sub_080BD680 @ 0x080BD680

void sub_080BD680(int arg0)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x818c0c8,0x2001000,in_r2);
  sub_080ACFCC(3,0x818c5e0,0x3003150,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80bc029,1);
  *(undefined2 *)(arg0 + 0x24) = 1;
  *(undefined2 *)(arg0 + 0x26) = 4;
  *(undefined2 *)(arg0 + 0x28) = 4;
  *(undefined2 *)(arg0 + 0x2a) = 0;
  return;
}


// sub_080BD6D8 @ 0x080BD6D8

void sub_080BD6D8(int arg0)

{
  undefined *local_14;
  int local_10;
  
  local_14 = &DAT_0800787c;
  local_10 = arg0 + 0x24;
  sub_0815862C(&local_14,(uint)*(ushort *)(arg0 + 0x26),(uint)*(ushort *)(arg0 + 0x28),0);
  local_14 = (undefined *)0x3003800;
  local_10 = arg0 + 0x24;
  sub_080AA998(&local_14,0,0xd,0);
  return;
}


// sub_080BD72C @ 0x080BD72C

void sub_080BD72C(int arg0,undefined4 arg1)

{
  *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + (short)arg1;
  *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) + (short)arg1;
  return;
}


// sub_080BD73C @ 0x080BD73C

void sub_080BD73C(void)

{
  sub_080E9044(DAT_030069c0,0);
  DAT_030069c0 = 0;
  return;
}


// sub_080BD758 @ 0x080BD758

void sub_080BD758(void)

{
  DAT_0203db28 = 0x22;
  DAT_030068f0 = sub_080C4618(0,0x1c1,0x50,0x43);
  DAT_0203db2a = 0x47;
  DAT_030068f4 = sub_080C4618(1,0x1c0,0x50,0x43);
  return;
}


// sub_080BD7A4 @ 0x080BD7A4

void sub_080BD7A4(undefined4 arg0,int arg1)

{
  int iVar1;
  
  if (arg1 == 0) {
    sub_080ACFA4(3,0x7fff,0x3003170,0x20);
    sub_080ACFA4(3,0x7fff,&DAT_03003190,0x20);
    sub_080AABB0();
  }
  else {
    iVar1 = sub_080D8248((uint)DAT_0203db28);
    sub_080ACFCC(3,*(undefined4 *)(iVar1 + 4),0x3002d70,0x20);
    iVar1 = sub_080D8248((uint)DAT_0203db2a);
    sub_080ACFCC(3,*(undefined4 *)(iVar1 + 4),&DAT_03002d90,0x20);
    sub_080AB054(0x1e0,0x20,1,0x20);
  }
  return;
}


// sub_080BD830 @ 0x080BD830

void sub_080BD830(void)

{
  int iVar1;
  
  iVar1 = DAT_030068f4;
  if ((DAT_030031bc & 1) != 0) {
    *(short *)(DAT_030068f0 + 0x2c) = *(short *)(DAT_030068f0 + 0x2c) + -1;
    *(short *)(iVar1 + 0x2c) = *(short *)(iVar1 + 0x2c) + 1;
  }
  return;
}


// sub_080BD864 @ 0x080BD864

void sub_080BD864(void)

{
  sub_080B8AE0(0x7fff,1);
  return;
}


