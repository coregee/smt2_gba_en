/* Ghidra decompilation of asm/code_080B6B58.s (reference only; not compiled). */

// sub_080B6B58 @ 0x080B6B58

int sub_080B6B58(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x8163be8,0xffff);
  *(undefined4 *)(iVar1 + 0x24) = arg0;
  if (DAT_03004598 == 1) {
    DAT_03004598 = 2;
  }
  if (DAT_0300459c == 1) {
    DAT_0300459c = 2;
  }
  if (DAT_030045a0 == 1) {
    DAT_030045a0 = 2;
  }
  *(undefined4 *)(iVar1 + 0x2c) = arg1;
  return iVar1;
}


// sub_080B6BB0 @ 0x080B6BB0

int sub_080B6BB0(undefined4 arg0)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x8163e78,0xffff);
  *(undefined4 *)(iVar1 + 0x24) = arg0;
  if (DAT_03004598 == 1) {
    DAT_03004598 = 2;
  }
  if (DAT_0300459c == 1) {
    DAT_0300459c = 2;
  }
  if (DAT_030045a0 == 1) {
    DAT_030045a0 = 2;
  }
  return iVar1;
}


// sub_080B6C00 @ 0x080B6C00

void sub_080B6C00(int arg0,undefined4 arg1)

{
  int iVar1;
  dword arg0_00;
  
  switch(arg1) {
  case 0:
    arg0_00 = 0x80b3e8d;
    break;
  case 1:
    iVar1 = sub_080B3EA4(0);
    if (iVar1 == 0) {
      *(undefined2 *)(arg0 + 0x1c) = 0;
      return;
    }
    *(undefined2 *)(arg0 + 0x1c) = 1;
    return;
  case 2:
    arg0_00 = 0x80b3ed1;
    break;
  case 3:
    arg0_00 = 0x80b3f1d;
    break;
  case 4:
    DisplayList_Add(0x80b41b1,1);
  default:
    goto switchD_080b6c10_default;
  }
  DisplayList_Add(arg0_00,1);
switchD_080b6c10_default:
  return;
}


// sub_080B6C74 @ 0x080B6C74

void sub_080B6C74(int arg0)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = sub_080C2340(0x10f);
  uVar1 = 0;
  if (iVar2 != 0) {
    sub_080B4140();
    if (DAT_03004534 == 0xda) {
      sub_080ACFCC(3,0x3002a90,0x3002e90,0x20);
    }
    else {
      sub_080ACFCC(3,0x3002ab0,0x3002eb0,0x100);
    }
    sub_080AABB0();
    sub_080C23BC(0x10f);
    uVar1 = 1;
  }
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
  return;
}


// sub_080B6CE8 @ 0x080B6CE8

void sub_080B6CE8(void)

{
  DAT_03000042 = DAT_03000042 + 0xff;
  return;
}


// sub_080B6CF8 @ 0x080B6CF8

void sub_080B6CF8(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  REG_BG2CNT = 0x840a;
  return;
}


// sub_080B6D2C @ 0x080B6D2C

void sub_080B6D2C(void)

{
  sub_080C1440();
  DisplayList_Add(0x80b6cf9,1);
  return;
}


// sub_080B6D44 @ 0x080B6D44

void sub_080B6D44(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B6D68 @ 0x080B6D68

void sub_080B6D68(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x857d9c0;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  DisplayList_Add(0x80b6d45,1);
  return;
}


// sub_080B6D9C @ 0x080B6D9C

void sub_080B6D9C(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080B38A8();
  *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 == 1);
  return;
}


// sub_080B6DB4 @ 0x080B6DB4

undefined4 sub_080B6DB4(uint arg0)

{
  undefined2 uVar1;
  dword dVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 local_14 [2];
  
  uVar1 = (undefined2)arg0;
  if (DAT_030020e4 != 0x80d977d) {
    if (((DAT_0200ab04 & 0x8000) != 0) && (DAT_03004534 == arg0)) {
      uVar3 = sub_080AD0FC(0x81641a8,0xffff);
      return uVar3;
    }
    if (arg0 == 0x2e) {
      dVar2 = 0x834a01c;
    }
    else if (arg0 == 0x6d) {
      dVar2 = 0x834a0d4;
    }
    else {
      if (arg0 != 0x5d) {
        uVar3 = sub_080AD0FC(0x816417c,0xffff);
        DAT_0300456e = 0;
        if ((DAT_0200ab04 & 0x8000) == 0) {
          DAT_03004534 = uVar1;
          DAT_0300456e = 0;
          return uVar3;
        }
        local_14[0] = 0;
        DAT_03004534 = uVar1;
        CpuSet(local_14,0x3002eb0,0x1000080);
        DAT_03002db0 = 0;
        sub_080AABB0();
        return uVar3;
      }
      dVar2 = 0x834a174;
    }
    uVar3 = sub_080AD0FC(dVar2,0xffff);
    DAT_03004534 = uVar1;
    DAT_0300456e = 0;
    return uVar3;
  }
  if (arg0 == 0x6d) {
    dVar2 = 0x834a0d4;
  }
  else {
    if (arg0 != 0x2e) {
      uVar3 = sub_080AD0FC(0x8164074,0xffff);
      goto LAB_080b6e06;
    }
    dVar2 = 0x834a01c;
  }
  uVar3 = sub_080AD0FC(dVar2,0xffff);
  DAT_0300456e = 0;
LAB_080b6e06:
  DAT_03004534 = uVar1;
  iVar4 = sub_080C2340(0x10f);
  if (iVar4 == 0) {
    local_14[0] = 0;
    CpuSet(local_14,0x3002eb0,0x1000080);
    DAT_03002db0 = 0;
    sub_080AABB0();
  }
  return uVar3;
}


// sub_080B6F28 @ 0x080B6F28

void sub_080B6F28(int arg0)

{
  DAT_03004522 = 0;
  DAT_03004528 = *(undefined2 *)(arg0 + 10);
  DAT_0300452a = *(undefined2 *)(arg0 + 0xe);
  DAT_03004524 = 0;
  DAT_03004526 = 0;
  return;
}


// sub_080B6F40 @ 0x080B6F40

undefined4 sub_080B6F40(undefined4 *arg0)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  byte bVar15;
  ushort uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint local_44;
  
  uVar2 = *(ushort *)(arg0 + 2);
  uVar13 = (uint)DAT_03004528;
  uVar3 = *(ushort *)(arg0 + 3);
  uVar14 = (uint)DAT_0300452a;
  uVar4 = *(ushort *)(arg0 + 4);
  uVar5 = *(ushort *)((int)arg0 + 0x12);
  uVar7 = (uint)*(ushort *)(arg0 + 6);
  uVar8 = (uint)*(ushort *)((int)arg0 + 0x1a);
  iVar9 = *(int *)*arg0;
  iVar6 = arg0[1];
  uVar19 = (uint)DAT_03004524;
  uVar10 = (uint)DAT_03004526;
  uVar16 = 0;
  do {
    if (uVar8 <= DAT_03004522) {
      return 0;
    }
    local_44 = 0;
    uVar12 = uVar14 + 1;
    uVar10 = uVar10 + uVar5;
    uVar16 = uVar16 + 1;
    if (uVar7 != 0) {
      uVar17 = (uint)uVar2;
      uVar18 = (uint)uVar3;
      do {
        pbVar11 = (byte *)(iVar6 + (uVar14 >> 3) * 0x400 + (uVar18 >> 3) * 0x20 + (uVar14 & 7) * 4 +
                          ((uVar18 & 7) >> 1));
        bVar15 = *pbVar11;
        bVar1 = *(byte *)(iVar9 + (uVar13 >> 3) * 0x400 + (uVar17 >> 3) * 0x20 + (uVar13 & 7) * 4 +
                         ((uVar17 & 7) >> 1));
        if ((uVar18 & 1) == 0) {
          if ((uVar17 & 1) == 0) {
            bVar15 = bVar15 | bVar1 & 0xf;
          }
          else {
            bVar15 = bVar15 | bVar1 >> 4;
          }
        }
        else if ((uVar17 & 1) == 0) {
          bVar15 = bVar15 | bVar1 << 4;
        }
        else {
          bVar15 = bVar15 | bVar1 & 0xf0;
        }
        *pbVar11 = bVar15;
        uVar18 = uVar18 + 1 & 0xffff;
        uVar19 = uVar19 + uVar4;
        if (uVar7 <= uVar19) {
          uVar17 = uVar17 + 1 & 0xffff;
          uVar19 = uVar19 - uVar7;
        }
        local_44 = local_44 + 1 & 0xffff;
      } while (local_44 < uVar7);
    }
    uVar14 = uVar12 & 0xffff;
    if (uVar8 <= uVar10) {
      uVar13 = uVar13 + 1 & 0xffff;
      uVar10 = uVar10 - uVar8;
    }
    DAT_03004522 = DAT_03004522 + 1;
  } while (uVar16 < 0x10);
  DAT_0300452a = (short)uVar12;
  DAT_03004528 = (short)uVar13;
  DAT_03004526 = (short)uVar10;
  DAT_03004524 = (short)uVar19;
  return 1;
}


// sub_080B70BC @ 0x080B70BC

void sub_080B70BC(uint arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  undefined2 in_stack_00000000;
  undefined4 in_stack_00000004;
  
  DAT_03004614 = arg0 & 0xffff;
  DAT_03004514 = arg1 & 0xffff;
  DAT_03003fd8 = in_stack_00000000;
  DAT_03003fdc = in_stack_00000004;
  DAT_03004610 = 0;
  DAT_03004544 = 4;
  DAT_03003fd4 = (undefined2)arg2;
  DAT_03003fd6 = (undefined2)arg3;
  sub_080A9AB4(0x80c1561);
  return;
}


// sub_080B710C @ 0x080B710C

void sub_080B710C(uint arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  undefined2 in_stack_00000000;
  undefined4 in_stack_00000004;
  
  DAT_03004614 = arg0 & 0xffff;
  DAT_03004514 = arg1 & 0xffff;
  DAT_03003fd8 = in_stack_00000000;
  DAT_03003fdc = in_stack_00000004;
  DAT_03004610 = 0;
  DAT_03004544 = 6;
  DAT_03003fd4 = (undefined2)arg2;
  DAT_03003fd6 = (undefined2)arg3;
  sub_080A9AB4(0x80c1561);
  return;
}


// sub_080B715C @ 0x080B715C

void sub_080B715C(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x24) = (undefined2)arg1;
  return;
}


// sub_080B7160 @ 0x080B7160

void sub_080B7160(int arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_0813EB78();
  *(ushort *)(arg0 + 0x1c) = (ushort)((uVar1 & 0xffff) == 0);
                    /* WARNING: Could not recover jumptable at 0x080b717a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B717C @ 0x080B717C

void sub_080B717C(void)

{
  ushort uVar1;
  
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 & 0xf7ff;
  return;
}


// sub_080B7190 @ 0x080B7190

void sub_080B7190(void)

{
  ushort uVar1;
  
  REG_BG3CNT = 0x8607;
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 | 0x800;
  return;
}


// sub_080B71B4 @ 0x080B71B4

void sub_080B71B4(undefined4 arg0,int arg1)

{
  dword arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 1) {
    sub_080C14FC();
    arg0_00 = 0x80c153d;
  }
  else {
    if (arg1 == 0) {
      DisplayList_Add(0x80b717d,1);
      DAT_0200ab04 = DAT_0200ab04 & 0xffff7fff;
      goto LAB_080b7212;
    }
    if (arg1 != 2) {
      if (arg1 == 3) {
        DisplayList_Add(0x80b7191,1);
        sub_080C3818(1);
      }
      goto LAB_080b7212;
    }
    arg0_00 = 0x80adf65;
  }
  DisplayList_Add(arg0_00,1);
LAB_080b7212:
                    /* WARNING: Could not recover jumptable at 0x080b7214. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B721C @ 0x080B721C

undefined4 sub_080B721C(int arg0)

{
  short sVar1;
  undefined4 uVar2;
  
  if ((arg0 == 0) ||
     ((((sVar1 = *(short *)(arg0 + 2), sVar1 != 0xe && (sVar1 != 0x24)) && (sVar1 != 0x25)) &&
      (((sVar1 != 0x26 && (sVar1 != 0x27)) && (sVar1 != 0x28)))))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// sub_080B7248 @ 0x080B7248

void sub_080B7248(undefined4 arg0,int arg1)

{
  undefined4 arg0_00;
  int iVar1;
  undefined4 arg0_01;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (arg1 == 0) {
    DAT_03004614 = (uint)DAT_03003fd0;
    DAT_03004514 = (uint)DAT_03003fd2;
    sub_080ADCCC(DAT_03004614,DAT_03004514);
    sub_080AE234();
    sub_080AE2A8((uint)DAT_03003fd4,(uint)DAT_03003fd6);
    DAT_03004552 = DAT_03003fd8;
    sub_080AD7F0();
    DAT_03004584 = 0;
    arg0_00 = sub_080B2EFC(0,1);
    iVar1 = sub_080B3038(arg0_00,4);
    arg0_01 = sub_080B3038(arg0_00,0x23);
    iVar2 = sub_080B3038(arg0_00,1);
    iVar3 = sub_080B3038(arg0_00,2);
    iVar4 = sub_080B3038(arg0_00,0x1b);
    iVar5 = sub_080B3038(arg0_00,0x1c);
    iVar6 = sub_080B3038(arg0_00,0xc);
    if (((((iVar1 != 0) || (iVar2 != 0)) || (iVar3 != 0)) || ((iVar4 != 0 || (iVar5 != 0)))) ||
       ((iVar6 != 0 || (iVar1 = sub_080B721C(arg0_01), iVar1 != 0)))) {
      sub_080AF5B8((uint)DAT_03004562,(uint)DAT_03004564,(uint)DAT_03004552);
    }
    sub_080AF4EC((uint)DAT_03004562,(uint)DAT_03004564);
    if (((DAT_03004614 == 0x4a) && (DAT_03004514 == 3)) &&
       ((DAT_03004562 == 0 && (DAT_03004564 == 1)))) {
      sub_080AF5B8(0,1,(uint)DAT_03004552);
    }
  }
  else {
    DisplayList_Add(0x80adf65,1);
    sub_080B2840(0,0,0);
  }
  return;
}


// sub_080B7368 @ 0x080B7368

void sub_080B7368(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_03003ff8 == 0);
  return;
}


// sub_080B7384 @ 0x080B7384

void sub_080B7384(void)

{
  int iVar1;
  undefined4 arg0;
  
  iVar1 = sub_080B3078(0,0,0x19);
  if (iVar1 == 1) {
    arg0 = sub_080B2EFC(0,0);
    iVar1 = sub_080B3038(arg0,0x19);
    DAT_03004586 = *(undefined2 *)(iVar1 + 2);
    DAT_03004584 = 1;
  }
  return;
}


// sub_080B73B8 @ 0x080B73B8

void sub_080B73B8(int arg0,uint arg1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  DAT_03003ff4 = 1;
  uVar2 = sub_0813EB78();
  if (((uVar2 & 0xffff) == 0) && (iVar3 = sub_080AF8D0(arg1 & 0xffff,arg1 & 0xffff,0), iVar3 != 0))
  {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
  DAT_03003ff4 = 0;
  return;
}


// sub_080B73FC @ 0x080B73FC

void sub_080B73FC(void)

{
  uint uVar1;
  
  uVar1 = sub_0813EB78();
  if ((uVar1 & 0xffff) == 0) {
    Field_SetState(1);
  }
  return;
}


// sub_080B7414 @ 0x080B7414

void sub_080B7414(void)

{
  return;
}


// sub_080B7418 @ 0x080B7418

void sub_080B7418(void)

{
  sub_080C3818(1);
  return;
}


// sub_080B7424 @ 0x080B7424

void sub_080B7424(void)

{
  DAT_0200e808 = 0;
  return;
}


// sub_080B7430 @ 0x080B7430

void sub_080B7430(void)

{
  DAT_030029b0 = 0x7fff;
  sub_080ACFA4(3,0x7fff,&DAT_03002b70,0x40);
  sub_080ACFA4(3,0x7fff,&DAT_03002b50,0x20);
  sub_080AAFBC(0,1,1);
  DAT_0300452c = sub_080AAFBC(0xd0,0x30,1);
  DAT_030045b0 = 0;
  return;
}


// sub_080B7498 @ 0x080B7498

void sub_080B7498(void)

{
  DAT_030029b0 = *DAT_03004630;
  sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
  sub_080ACFCC(3,DAT_03004510,&DAT_03002b50,0x20);
  DAT_0300452c = sub_080AB054(0xd0,0x30,8,0x20);
  DAT_030045b0 = 1;
  return;
}


// sub_080B7500 @ 0x080B7500

void sub_080B7500(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_03002db2 == 0) {
    sub_080B04BC();
    DAT_0300452c = sub_080AAEDC(1);
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080B7530 @ 0x080B7530

void sub_080B7530(void)

{
  dword arg0;
  
  if (DAT_03004534 == 0x2e) {
    arg0 = 0x834a0b0;
  }
  else {
    if (DAT_03004534 != 0x6d) {
      if (DAT_03004534 != 0x5d) {
        return;
      }
      sub_080AD0FC(0x834a1f0,0xffff);
      return;
    }
    arg0 = 0x834a150;
  }
  sub_080AD0FC(arg0,0xffff);
  return;
}


// sub_080B7578 @ 0x080B7578

void sub_080B7578(void)

{
  sub_080AB0F0(0x1d0,0x2e,1);
  return;
}


// sub_080B758C @ 0x080B758C

void sub_080B758C(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined2 in_stack_00000000;
  undefined4 in_stack_00000004;
  
  DAT_03003fd0 = (ushort)arg0;
  DAT_03004614 = (uint)(ushort)arg0;
  DAT_03003fd2 = (ushort)arg1;
  DAT_03004514 = (uint)(ushort)arg1;
  DAT_03003fd4 = (undefined2)arg2;
  DAT_03004562 = (undefined2)arg2;
  DAT_03003fd6 = (undefined2)arg3;
  DAT_03004564 = (undefined2)arg3;
  DAT_03003fd8 = in_stack_00000000;
  DAT_03004552 = in_stack_00000000;
  DAT_03003fdc = in_stack_00000004;
  return;
}


// sub_080B75E8 @ 0x080B75E8

void sub_080B75E8(uint arg0,uint arg1,uint arg2,uint arg3)

{
  sub_080AD0FC(0x81641b4,0xffff);
  sub_080B758C(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  DAT_03003fda = 1;
  return;
}


// sub_080B764C @ 0x080B764C

void sub_080B764C(uint arg0,uint arg1,uint arg2,uint arg3)

{
  sub_080B75E8(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  DAT_03003fda = 1;
  return;
}


// sub_080B7684 @ 0x080B7684

void sub_080B7684(void)

{
  int iVar1;
  
  sub_080C2CD8((int)(char)DAT_030069f8,0,3);
  iVar1 = sub_080C2340(0x108);
  if ((iVar1 != 0) && (DAT_030045a0 != 0)) {
    sub_080B0C7C();
    DAT_030045a0 = 0;
    sub_080C23BC(0x108);
  }
  return;
}


// sub_080B76CC @ 0x080B76CC

void sub_080B76CC(void)

{
  DAT_0200e808 = 1;
  return;
}


// sub_080B76D8 @ 0x080B76D8

void sub_080B76D8(void)

{
  int iVar1;
  dword arg1;
  
  iVar1 = sub_080C2340(0xae);
  if (iVar1 == 0) {
    return;
  }
  iVar1 = sub_080C2340(0x5e);
  if (iVar1 == 0) {
    iVar1 = sub_080C2340(0x5f);
    if (iVar1 == 0) {
      sub_080AF178(0xc,0x804cb9c);
      DAT_03003bb8 = 0;
      DAT_03005180 = 0;
      return;
    }
    arg1 = 0x804c564;
  }
  else {
    arg1 = 0x804c354;
  }
  sub_080AF178(0xc,arg1);
  DAT_03005180 = 0;
  DAT_03003bb8 = 0;
  return;
}


// sub_080B7738 @ 0x080B7738

void sub_080B7738(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  dword arg0_00;
  undefined2 in_stack_00000000;
  
  iVar1 = sub_080C2340(0xae);
  if (iVar1 == 0) {
    arg0_00 = 0x81643d0;
  }
  else {
    arg0_00 = 0x8164460;
  }
  sub_080AD0FC(arg0_00,0xffff);
  DAT_03003fd4 = (ushort)arg2 & 0x7f;
  DAT_03003fd6 = (undefined2)arg3;
  DAT_03003fd8 = in_stack_00000000;
  DAT_03003fda = 1;
  return;
}


// sub_080B778C @ 0x080B778C

void sub_080B778C(uint arg0,uint arg1,uint arg2,uint arg3)

{
  sub_080B7738(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  DAT_03003fda = 1;
  return;
}


// sub_080B77C4 @ 0x080B77C4

void sub_080B77C4(int arg0)

{
  int iVar1;
  
  if (*(short *)(arg0 + 0x28) == 2) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    iVar1 = sub_080B0248(0,0,0);
    if (iVar1 == 0) {
      *(undefined2 *)(arg0 + 0x1e) = 0;
      DAT_03004530 = 0x1a;
    }
    else {
      DAT_0300457e = 0;
      *(undefined2 *)(arg0 + 0x1e) = 1;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_080B7808 @ 0x080B7808

void sub_080B7808(void)

{
  sub_080C3818(1);
  sub_080B1AD8(0xc,(uint)DAT_03004552);
  DAT_03004596 = 1;
  return;
}


// sub_080B782C @ 0x080B782C

void sub_080B782C(void)

{
  sub_080C3818(1);
  sub_080AD0FC(0x816499c,0xffff);
  Field_SetState(0x1a);
  return;
}


// sub_080B7850 @ 0x080B7850

void sub_080B7850(void)

{
  sub_080B2840(1,0,0);
  return;
}


// sub_080B7860 @ 0x080B7860

void sub_080B7860(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_0300455e == 0);
  return;
}


// sub_080B787C @ 0x080B787C

void sub_080B787C(int arg0)

{
  if (DAT_030045ae == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
    DAT_030045ae = 0;
  }
  return;
}


// sub_080B78A4 @ 0x080B78A4

undefined4 sub_080B78A4(void)

{
  short *psVar1;
  dword dVar2;
  
  psVar1 = (short *)0x2009004;
  dVar2 = 0x2009004;
  while ((*psVar1 == 0 || (*(dword *)(psVar1 + 0x10) != 0x80b7415))) {
    psVar1 = psVar1 + 0x32;
    dVar2 = dVar2 + 100;
    if ((short *)0x200a8a0 < psVar1) {
      return 0;
    }
  }
  return dVar2;
}


// sub_080B78DC @ 0x080B78DC

undefined4 sub_080B78DC(void)

{
  short *psVar1;
  dword dVar2;
  
  psVar1 = (short *)0x2009004;
  dVar2 = 0x2009004;
  while ((*psVar1 == 0 || (*(dword *)(psVar1 + 0x10) != 0x80b2ab1))) {
    psVar1 = psVar1 + 0x32;
    dVar2 = dVar2 + 100;
    if ((short *)0x200a8a0 < psVar1) {
      return 0;
    }
  }
  return dVar2;
}


// sub_080B7914 @ 0x080B7914

undefined4 sub_080B7914(ushort *arg0,undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((((ushort)arg1 < *arg0) || ((ushort)arg2 < arg0[1])) || (arg0[2] < (ushort)arg1)) ||
     (arg0[3] < (ushort)arg2)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080b7940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar1;
}


// sub_080B7944 @ 0x080B7944

undefined4 sub_080B7944(int arg0,uint arg1,uint arg2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint arg1_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg1_00 = arg1 & 0xffff;
  uVar3 = arg2 & 0xffff;
  if ((*(int *)(arg0 + 0x14) == 0) ||
     ((uVar1 = sub_080B7914(arg0 + 0x10,arg1_00,uVar3), (uVar1 & 0xffff) != 0 &&
      ((*(int *)(arg0 + 0x1c) == 0 ||
       ((uVar1 = sub_080B7914(arg0 + 0x18,arg1_00,uVar3), (uVar1 & 0xffff) != 0 &&
        ((*(int *)(arg0 + 0x24) == 0 ||
         ((uVar1 = sub_080B7914(arg0 + 0x20,arg1_00,uVar3), (uVar1 & 0xffff) != 0 &&
          ((*(int *)(arg0 + 0x2c) == 0 ||
           ((uVar1 = sub_080B7914(arg0 + 0x28,arg1_00,uVar3), (uVar1 & 0xffff) != 0 &&
            ((*(int *)(arg0 + 0x34) == 0 ||
             ((uVar1 = sub_080B7914(arg0 + 0x30,arg1_00,uVar3), (uVar1 & 0xffff) != 0 &&
              ((*(int *)(arg0 + 0x3c) == 0 ||
               ((uVar1 = sub_080B7914(arg0 + 0x38,arg1_00,uVar3), (uVar1 & 0xffff) != 0 &&
                ((*(int *)(arg0 + 0x44) == 0 ||
                 ((uVar1 = sub_080B7914(arg0 + 0x40,arg1_00,uVar3), (uVar1 & 0xffff) != 0 &&
                  ((*(int *)(arg0 + 0x4c) == 0 ||
                   ((uVar1 = sub_080B7914(arg0 + 0x48,arg1_00,uVar3), (uVar1 & 0xffff) != 0 &&
                    ((*(int *)(arg0 + 0x54) == 0 ||
                     ((uVar1 = sub_080B7914(arg0 + 0x50,arg1_00,uVar3), (uVar1 & 0xffff) != 0 &&
                      ((*(int *)(arg0 + 0x5c) == 0 ||
                       ((uVar1 = sub_080B7914(arg0 + 0x58,arg1_00,uVar3), (uVar1 & 0xffff) != 0 &&
                        ((*(int *)(arg0 + 100) == 0 ||
                         ((uVar1 = sub_080B7914(arg0 + 0x60,arg1_00,uVar3), (uVar1 & 0xffff) != 0 &&
                          ((*(int *)(arg0 + 0x6c) == 0 ||
                           ((uVar1 = sub_080B7914(arg0 + 0x68,arg1_00,uVar3), (uVar1 & 0xffff) != 0
                            && ((*(int *)(arg0 + 0x74) == 0 ||
                                ((uVar1 = sub_080B7914(arg0 + 0x70,arg1_00,uVar3),
                                 (uVar1 & 0xffff) != 0 &&
                                 ((*(int *)(arg0 + 0x7c) == 0 ||
                                  ((uVar1 = sub_080B7914(arg0 + 0x78,arg1_00,uVar3),
                                   (uVar1 & 0xffff) != 0 &&
                                   ((*(int *)(arg0 + 0x84) == 0 ||
                                    ((uVar1 = sub_080B7914(arg0 + 0x80,arg1_00,uVar3),
                                     (uVar1 & 0xffff) != 0 &&
                                     ((*(int *)(arg0 + 0x8c) == 0 ||
                                      (uVar3 = sub_080B7914(arg0 + 0x88,arg1_00,uVar3),
                                      (uVar3 & 0xffff) != 0)))))))))))))))))))))))))))))))))))))))))
               ))))))))))))))))))))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080b7af8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080B7AFC @ 0x080B7AFC

undefined4 sub_080B7AFC(undefined4 arg0,uint arg1,uint arg2,undefined4 arg3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint arg0_00;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint arg0_01;
  code *UNRECOVERED_JUMPTABLE;
  ushort in_stack_00000000;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar1 = DAT_03005180;
  arg0_00 = arg1 & 0xffff;
  uVar6 = arg2 & 0xffff;
  uVar7 = (uint)in_stack_00000000;
  if (DAT_030020e4 == 0x80d977d) {
    sub_080BF300(arg0_00,uVar6);
  }
  else {
    if (DAT_03003bb8 == 1) {
      DAT_03003bb8 = 0;
      sub_080C2CC0();
    }
    if (uVar7 == 1) {
      DAT_03005180 = in_stack_00000000;
      DAT_03003bb8 = uVar7;
      if (uVar1 == 0) {
        sub_080C2230(0);
      }
      if ((short)arg0 == 1) {
        sub_080B7738(0,0,arg0_00,uVar6);
      }
      else {
        sub_080B778C(0,0,arg0_00,uVar6);
      }
    }
    else {
      uVar7 = arg2 & 0x3f;
      arg0_01 = 0;
      uVar6 = arg0_00;
      while( true ) {
        uVar3 = sub_080C8B3C(arg0_01);
        iVar4 = sub_080C8B10(arg0_01,0);
        if (iVar4 == 0) break;
        uVar8 = 0;
        if (uVar3 != 0) {
          do {
            if ((((*(ushort *)(iVar4 + 8) <= uVar6) && (*(ushort *)(iVar4 + 10) <= uVar7)) &&
                (uVar6 <= *(ushort *)(iVar4 + 0xc))) &&
               ((uVar7 <= *(ushort *)(iVar4 + 0xe) &&
                (iVar2 = sub_080B7944(iVar4,uVar6,uVar7), iVar2 == 1)))) {
              uVar6 = uVar6 - *(ushort *)(iVar4 + 8) & 0xffff;
              uVar7 = uVar7 - *(ushort *)(iVar4 + 10) & 0xffff;
              local_2c = arg0_01;
              local_28 = uVar8;
              break;
            }
            uVar8 = uVar8 + 1 & 0xffff;
            iVar4 = iVar4 + 0x268;
          } while (uVar8 < uVar3);
        }
        if (uVar8 != uVar3) break;
        arg0_01 = arg0_01 + 1 & 0xffff;
      }
      sub_080AF4B8(arg0_00,arg2 & 0x3f);
      if ((arg0_00 == 0x14) && ((arg2 & 0x3f) == 0xd)) {
        sub_080AF4B8(0x14,0xe);
      }
      if ((arg0_00 == 0x77) && ((arg2 & 0x3f) == 10)) {
        sub_080AF4B8(0x77,0xb);
      }
      if ((DAT_03005180 == 1) && (iVar4 = sub_080B098C(), iVar4 == 1)) {
        sub_080C1384();
      }
      if (uVar1 == 1) {
        sub_080C2230(0);
      }
      DAT_03004530 = 0x19;
      DAT_03003bb8 = 0;
      DAT_03005180 = 0;
      if (DAT_03004614 != local_2c) {
        sub_080C2CC0();
      }
      if (uVar1 == 1) {
        sub_080B7F2C(local_2c,arg1 & 0xff,arg2 & 0xff);
      }
      sub_080AE294();
      iVar4 = sub_080C8AF8();
      if (iVar4 == 1) {
        sub_080C7C94();
      }
      else {
        sub_080C7C60();
      }
      if ((short)arg0 == 1) {
        sub_080B75E8(local_2c,local_28,uVar6,uVar7);
      }
      else {
        sub_080B764C(local_2c,local_28,uVar6,uVar7);
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080b7d3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*UNRECOVERED_JUMPTABLE)();
  return uVar5;
}


// sub_080B7D40 @ 0x080B7D40

void sub_080B7D40(uint arg0,uint arg1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  ushort uStack_1c;
  ushort uStack_1a;
  
  uVar3 = arg0 & 0xffff;
  uVar2 = arg1 & 0xffff;
  uVar5 = 0xffffffff;
  uVar4 = 0xffffffff;
  sub_080C1F50((uint)DAT_03004562,(uint)DAT_03004564,&uStack_1c,&uStack_1a);
  uVar1 = uVar5;
  if ((DAT_0200ab04 & 0x8000) != 0) goto LAB_080b7dea;
  if (DAT_03004552 == 1) {
LAB_080b7dc2:
    if ((uStack_1c - uVar3 == 1) && (uVar5 = uVar4, uStack_1a == uVar2)) {
      uVar5 = 3;
    }
    uVar1 = uVar5;
    if ((uVar3 - uStack_1c == 1) && (uStack_1a == uVar2)) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = uVar4;
    if (DAT_03004552 < 2) {
      if (DAT_03004552 != 0) goto LAB_080b7dea;
    }
    else if (DAT_03004552 != 2) {
      if (DAT_03004552 != 3) goto LAB_080b7dea;
      goto LAB_080b7dc2;
    }
    if ((uStack_1a - uVar2 == 1) && (uVar5 = uVar4, uStack_1c == uVar3)) {
      uVar5 = 0;
    }
    uVar1 = uVar5;
    if ((uVar2 - uStack_1a == 1) && (uStack_1c == uVar3)) {
      uVar1 = 2;
    }
  }
LAB_080b7dea:
                    /* WARNING: Could not recover jumptable at 0x080b7df6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1);
  return;
}


// sub_080B7DF8 @ 0x080B7DF8

uint sub_080B7DF8(int arg0)

{
  return (uint)(*(short *)(arg0 + 0x24) == 1);
}


// sub_080B7E0C @ 0x080B7E0C

undefined4 sub_080B7E0C(undefined4 arg0)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((short)arg0 == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 0x1a;
    DAT_03004530 = 0x1a;
  }
  iVar1 = sub_080AD0FC(0x81644b4,0xffff);
  *(undefined2 *)(iVar1 + 0x28) = uVar3;
                    /* WARNING: Could not recover jumptable at 0x080b7e2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)();
  return uVar2;
}


// sub_080B7E3C @ 0x080B7E3C

void sub_080B7E3C(undefined4 arg0,uint arg1,uint arg2)

{
  uint arg0_00;
  int iVar1;
  uint uVar2;
  int arg0_01;
  undefined4 uVar3;
  uint arg2_00;
  uint uVar4;
  uint arg1_00;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  arg1_00 = arg1 & 0xffff;
  arg2_00 = arg2 & 0x3f;
  arg0_00 = 0;
  while( true ) {
    uVar2 = sub_080C8B3C(arg0_00);
    arg0_01 = sub_080C8B10(arg0_00,0);
    if (arg0_01 == 0) break;
    uVar4 = 0;
    if (uVar2 != 0) {
      do {
        if ((((*(ushort *)(arg0_01 + 8) <= arg1_00) && (*(ushort *)(arg0_01 + 10) <= arg2_00)) &&
            (arg1_00 <= *(ushort *)(arg0_01 + 0xc))) && (arg2_00 <= *(ushort *)(arg0_01 + 0xe))) {
          iVar1 = sub_080B7944(arg0_01,arg1_00,arg2_00);
          if (iVar1 == 1) {
            arg1_00 = arg1_00 - *(ushort *)(arg0_01 + 8) & 0xffff;
            arg2_00 = arg2_00 - *(ushort *)(arg0_01 + 10) & 0xffff;
            uStack_2c = arg0_00;
            uStack_28 = uVar4;
            break;
          }
        }
        uVar4 = uVar4 + 1 & 0xffff;
        arg0_01 = arg0_01 + 0x268;
      } while (uVar4 < uVar2);
    }
    if (uVar4 != uVar2) break;
    arg0_00 = arg0_00 + 1 & 0xffff;
  }
  sub_080C2CC0();
  uVar3 = sub_080AD0FC(0x8164670,0xffff);
  sub_080B758C(uStack_2c,uStack_28,arg1_00,arg2_00);
  DAT_03003fda = 1;
                    /* WARNING: Could not recover jumptable at 0x080b7f1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar3);
  return;
}


// sub_080B7F2C @ 0x080B7F2C

void sub_080B7F2C(uint arg0,undefined4 arg1,undefined4 arg2)

{
  sub_080C2D48((uint)(ushort)DAT_03003fc4,arg0 & 0xffff);
  DAT_03005f80._2_1_ = (undefined1)arg1;
  DAT_03005f80._3_1_ = (undefined1)arg2;
  return;
}


// sub_080B7F70 @ 0x080B7F70

void sub_080B7F70(void)

{
  DAT_0300003c = 0;
  return;
}


// sub_080B7F7C @ 0x080B7F7C

void sub_080B7F7C(int arg0,int arg1)

{
  short sVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  sVar1 = *(short *)(arg0 + 0x26) + -1;
  *(short *)(arg0 + 0x26) = sVar1;
  if (sVar1 == 0) {
    *(undefined2 *)(arg0 + 0x26) = 3;
    if (*(short *)(arg0 + 0x24) == 0) {
      DAT_0300003c = DAT_0300003c + 0x10;
      if ((uint)(arg1 * 0x10) < (uint)DAT_0300003c) {
        *(undefined2 *)(arg0 + 0x24) = 1;
        sub_080C51D4(0x153);
      }
    }
    else {
      DAT_0300003c = DAT_0300003c - 0x10;
      if (DAT_0300003c == 0) {
        *(undefined2 *)(arg0 + 0x24) = 0;
        *(undefined2 *)(arg0 + 0x1c) = 1;
      }
    }
  }
  sub_080B0AE0();
  return;
}


// sub_080B7FE8 @ 0x080B7FE8

void sub_080B7FE8(void)

{
  sub_080AB008(0x80,0x80,6);
  sub_080AB008(0x1d0,0x30,6);
  return;
}


// sub_080B8004 @ 0x080B8004

void sub_080B8004(void)

{
  sub_080AB0F0(0x80,0x80,6);
  sub_080AB0F0(0x1d0,0x30,6);
  return;
}


// sub_080B8020 @ 0x080B8020

int sub_080B8020(void)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x81646c0,0xffff);
  *(undefined2 *)(iVar1 + 0x26) = 3;
  DAT_03004534 = 0x77;
  return iVar1;
}


// sub_080B8048 @ 0x080B8048

void sub_080B8048(undefined4 arg0,int arg1)

{
  if (arg1 == 0) {
    sub_080ADCCC(DAT_03004614,DAT_03004514);
    sub_080AE234();
    sub_080AD7F0();
    DAT_03004584 = 0;
  }
  else {
    sub_080B2840(0,0,0);
  }
  return;
}


// sub_080B8088 @ 0x080B8088

void sub_080B8088(int arg0,int arg1)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (arg1 == 0) {
    if ((DAT_0200ab04 & 0x8000) == 0) {
      return;
    }
    DAT_03003bbc = 0;
    DAT_0200ab04 = DAT_0200ab04 & 0xffff7fff;
    sub_080C14FC();
    DisplayList_Add(0x80c153d,1);
  }
  else if (DAT_03003bbc != -1) {
    DisplayList_Add(0x80ae0bd,1);
    *(undefined2 *)(arg0 + 0x1c) = 0;
    return;
  }
  *(undefined2 *)(arg0 + 0x1c) = 1;
  return;
}


// sub_080B80F8 @ 0x080B80F8

undefined4 sub_080B80F8(void)

{
  int iVar1;
  undefined4 uVar2;
  dword arg0;
  
  iVar1 = sub_080B78A4();
  if (iVar1 == 0) {
    iVar1 = sub_080B098C();
    if ((iVar1 == 0) && ((DAT_0200ab04 & 0x8000) == 0)) {
      arg0 = 0x8164990;
    }
    else {
      arg0 = 0x81648ac;
    }
    uVar2 = sub_080AD0FC(arg0,0xffff);
  }
  else {
    uVar2 = sub_080AD0FC(0x8164788,0xffff);
    sub_080AD1FC(iVar1);
  }
  return uVar2;
}


// sub_080B8160 @ 0x080B8160

uint sub_080B8160(short *arg0)

{
  return (uint)(*arg0 == 0);
}


// sub_080B8174 @ 0x080B8174

void sub_080B8174(void)

{
  int iVar1;
  undefined4 arg2;
  uint arg1;
  code *UNRECOVERED_JUMPTABLE;
  
  arg1 = (uint)DAT_03004552;
  iVar1 = sub_080B0248(0,0,0);
  if (iVar1 == 3) {
    sub_080B1A30(0xc,arg1);
  }
  else {
    if (iVar1 == 2) {
      arg2 = 3;
    }
    else {
      arg2 = 2;
    }
    DAT_0300455a = 0xc;
    sub_080B2030(0xc,arg1,arg2);
    DAT_03004596 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080b81be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B81C0 @ 0x080B81C0

void sub_080B81C0(int arg0)

{
  if (*(short *)(arg0 + 0x26) == 0x52) {
    if ((*(uint *)(arg0 + 0x28) >> 4 & 1) == 0) {
      sub_080AA1BC(0x800107c,9,0,3);
    }
  }
  else {
    sub_080AA1BC(0x800107c,9,0,3);
  }
  if (*(short *)(arg0 + 0x26) == 0x52) {
    *(int *)(arg0 + 0x28) = *(int *)(arg0 + 0x28) + 1;
  }
  return;
}


// sub_080B822C @ 0x080B822C

void sub_080B822C(int arg0)

{
  *(undefined2 *)(arg0 + 0x1e) = 1;
  if ((*(short *)(arg0 + 0x26) == 0x52) && ((DAT_030031b8 & 2) != 0)) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_0300458e = 1;
  }
  else {
    *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_03004550 != 1);
  }
  if (*(short *)(arg0 + 0x26) != 0x52) {
    *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + -2;
  }
  return;
}


// sub_080B8280 @ 0x080B8280

void sub_080B8280(void)

{
  DAT_03004590 = 0;
  return;
}


// sub_080B828C @ 0x080B828C

int sub_080B828C(void)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x8164a48,0xffff);
  *(undefined2 *)(iVar1 + 0x24) = 0x60;
  *(undefined2 *)(iVar1 + 0x26) = 0x6a;
  sub_080C51D4(0x6a);
  return iVar1;
}


// sub_080B82B4 @ 0x080B82B4

void sub_080B82B4(int arg0)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar3 = *(int *)(arg0 + 0x24);
  if (*(short *)(iVar3 + 4) == 0x11f) {
    iVar3 = sub_080C2414((uint)*(ushort *)(iVar3 + 8));
    if (iVar3 == 0) {
      uVar1 = sub_080C1D9C();
      uVar1 = uVar1 & 0xf0;
      goto joined_r0x080b82f2;
    }
  }
  else {
    uVar1 = sub_080C2414((uint)*(ushort *)(iVar3 + 8));
joined_r0x080b82f2:
    if (uVar1 == 0) {
      uVar1 = (uint)*(ushort *)(*(int *)(arg0 + 0x24) + 2);
      *(undefined2 *)(arg0 + 0x38) = 0;
      goto LAB_080b830a;
    }
  }
  uVar1 = *(ushort *)(*(int *)(arg0 + 0x24) + 2) + 1 & 0xffff;
  *(undefined2 *)(arg0 + 0x38) = 1;
LAB_080b830a:
  uVar2 = sub_080C4618(0,uVar1,0x50,5);
  *(undefined4 *)(arg0 + 0x28) = uVar2;
                    /* WARNING: Could not recover jumptable at 0x080b8320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8324 @ 0x080B8324

void sub_080B8324(int arg0)

{
  *(undefined2 *)(arg0 + 0x1e) = *(undefined2 *)(arg0 + 0x38);
  return;
}


// sub_080B832C @ 0x080B832C

void sub_080B832C(void)

{
  undefined4 in_r1;
  
  sub_080AF1E8(0x20,in_r1);
  return;
}


// sub_080B8338 @ 0x080B8338

void sub_080B8338(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_03004550 == 0x20);
  return;
}


// sub_080B8354 @ 0x080B8354

void sub_080B8354(int arg0)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(arg0 + 0x24) + 4);
  if ((((uVar2 & 0xf0000000) == 0) && (0x11f < uVar2)) && (uVar2 < 300)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
  return;
}


// sub_080B8384 @ 0x080B8384

void sub_080B8384(int arg0)

{
  switch(*(undefined4 *)(*(int *)(arg0 + 0x24) + 4)) {
  case 0x120:
    break;
  case 0x121:
    break;
  case 0x122:
    break;
  case 0x123:
    break;
  case 0x124:
    break;
  case 0x125:
    break;
  case 0x126:
    break;
  case 0x127:
    break;
  case 0x128:
    break;
  case 0x129:
    break;
  case 0x12a:
    break;
  case 299:
  }
  sub_080B832C();
  return;
}


// sub_080B8440 @ 0x080B8440

void sub_080B8440(int arg0)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  *(ushort *)(arg0 + 0x1e) =
       (ushort)((*(uint *)(*(int *)(arg0 + 0x24) + 4) & 0xf0000000) == 0xa0000000);
  uVar1 = sub_080C4618(1,*(ushort *)(*(int *)(arg0 + 0x24) + 2) + 1 & 0xffff,0x50,5);
  *(undefined4 *)(arg0 + 0x2c) = uVar1;
  sub_080C51D4(0x73);
                    /* WARNING: Could not recover jumptable at 0x080b848c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8490 @ 0x080B8490

void sub_080B8490(short *arg0)

{
  short *psVar1;
  
  DAT_0203a454 = *arg0;
  if (DAT_0203a454 != 0x301) {
    psVar1 = (short *)0x203a454;
    do {
      arg0 = arg0 + 1;
      psVar1 = psVar1 + 1;
      *psVar1 = *arg0;
    } while (*arg0 != 0x301);
  }
  return;
}


// sub_080B84C8 @ 0x080B84C8

void sub_080B84C8(int arg0)

{
  uint uVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = *(uint *)(*(int *)(arg0 + 0x24) + 4);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((uVar2 & 0xf0000000) == 0x80000000) {
    sub_080C7430();
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  else if ((uVar2 & 0xf0000000) == 0x90000000) {
    sub_080C7648();
    *(undefined2 *)(arg0 + 0x1e) = 2;
  }
  else {
    uVar1 = sub_080C32FC(uVar2 & 0xffff);
    if ((uVar1 & 0xff) == 1) {
      sub_080B832C();
      DAT_0203db50 = (undefined2)uVar2;
    }
    else {
      sub_080B8490(0x80033a0);
      DAT_0203a456 = (undefined2)*(undefined4 *)(*(int *)(arg0 + 0x24) + 4);
      sub_080B832C();
      if ((0x2d < *(int *)(*(int *)(arg0 + 0x24) + 4) - 300U) &&
         (sub_080C2438((uint)*(ushort *)(*(int *)(arg0 + 0x24) + 8)),
         *(short *)(*(int *)(arg0 + 0x24) + 8) == 0xff)) {
        DAT_03005f94 = 1;
      }
      sub_080C3328((uint)*(ushort *)(*(int *)(arg0 + 0x24) + 4));
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080b856e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8584 @ 0x080B8584

void sub_080B8584(int arg0)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(arg0 + 0x24) + 4);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((uVar1 & 0xf0000000) == 0x80000000) {
    sub_080C3114(uVar1 & 0xfffffff);
  }
  else if ((uVar1 & 0xf0000000) == 0x90000000) {
    sub_080C30AC(uVar1 & 0xfffffff);
  }
  return;
}


// sub_080B85C8 @ 0x080B85C8

void sub_080B85C8(int arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = *(uint *)(*(int *)(arg0 + 0x24) + 4) & 0xf0000000;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (uVar1 == 0x80000000) {
    sub_080C7414();
  }
  else if (uVar1 == 0x90000000) {
    sub_080C762C();
  }
                    /* WARNING: Could not recover jumptable at 0x080b85f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B85F8 @ 0x080B85F8

void sub_080B85F8(int arg0)

{
  dword arg0_00;
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(arg0 + 0x24) + 4);
  uVar1 = uVar2 & 0xf0000000;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (uVar1 == 0x80000000) {
    arg0_00 = 0x80033d6;
  }
  else {
    if (uVar1 != 0x90000000) {
      return;
    }
    arg0_00 = 0x80033ba;
  }
  sub_080B8490(arg0_00);
  sub_080B832C();
  sub_080C2438((uint)*(ushort *)(*(int *)(arg0 + 0x24) + 8));
  DAT_0203db2c = uVar2 & 0xfffffff;
  return;
}


// sub_080B8660 @ 0x080B8660

undefined4 sub_080B8660(void)

{
  short sVar1;
  short *psVar2;
  short local_10;
  short local_e;
  
  psVar2 = (short *)0x8164a7c;
  sub_080C1F50((uint)DAT_03004562,(uint)DAT_03004564,&local_10,&local_e);
  sVar1 = 0x38;
  while ((sVar1 != local_10 || (psVar2[1] != local_e))) {
    psVar2 = psVar2 + 4;
    sVar1 = *psVar2;
    if (sVar1 == 0xff) {
      return 0;
    }
  }
  return (uint)(ushort)psVar2[2];
}


// sub_080B86B0 @ 0x080B86B0

void sub_080B86B0(int arg0,uint arg1)

{
  uint uVar1;
  int iVar2;
  int arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080C2438((uint)*(ushort *)(*(int *)(arg0 + 0x24) + 8));
  *(undefined2 *)(arg0 + 0x1c) = 0;
  arg0_00 = (int)(char)(&DAT_030050e0)[arg1];
  if (arg0_00 == -1) goto LAB_080b87e0;
  uVar1 = sub_080B8660();
  uVar1 = uVar1 & 0xffff;
  if (uVar1 == 1) {
    if (((2 < arg1) || (iVar2 = sub_080C09B0(arg0_00), iVar2 != 1)) ||
       (iVar2 = sub_080C0830(), iVar2 != 0)) goto LAB_080b87e0;
    iVar2 = sub_080F401C(arg0_00);
    iVar2 = iVar2 >> 1;
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    sub_080C0C70(arg0_00,iVar2);
    *(short *)(arg0 + 0x3c + arg1 * 2) = (short)iVar2;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else {
    if (uVar1 < 2) {
      if (((uVar1 != 0) || (iVar2 = sub_080C09B0(arg0_00), iVar2 != 1)) ||
         (iVar2 = sub_080C0830(), iVar2 != 0)) goto LAB_080b87e0;
      iVar2 = sub_080F401C(arg0_00);
      iVar2 = iVar2 >> 2;
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      sub_080C0C70(arg0_00,iVar2);
      *(short *)(arg0 + 0x3c + arg1 * 2) = (short)iVar2;
    }
    else {
      if (uVar1 != 2) {
        if (((uVar1 == 3) && (2 < arg1)) &&
           ((iVar2 = sub_080C09B0(arg0_00), iVar2 == 1 && (iVar2 = sub_080C0830(), iVar2 == 0)))) {
          sub_080C08F8(arg0_00,2);
          *(undefined2 *)(arg0 + 0x1c) = 1;
          sub_080C8490(arg1);
        }
        goto LAB_080b87e0;
      }
      if (2 < arg1) goto LAB_080b87e0;
      iVar2 = sub_080C09B0(arg0_00);
      if ((iVar2 == 1) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
        sub_080C08F8(arg0_00,4);
        *(undefined2 *)(arg0 + 0x1c) = 1;
        sub_080C8490(arg1);
      }
    }
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  sub_080C8490(arg1);
LAB_080b87e0:
                    /* WARNING: Could not recover jumptable at 0x080b87e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B87EC @ 0x080B87EC

void sub_080B87EC(int arg0,uint arg1)

{
  byte bVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080C0148(arg1 & 0xffff);
  bVar1 = *(byte *)(iVar2 + 0xc);
  if (bVar1 != 1) {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
LAB_080b8844:
        sub_080B832C();
        DAT_0203db28 = *(undefined2 *)(iVar2 + 0x12);
        goto LAB_080b8852;
      }
    }
    else if ((bVar1 != 2) && (bVar1 != 3)) goto LAB_080b8844;
  }
  sub_080B832C();
LAB_080b8852:
  DAT_0203db2c = (uint)*(ushort *)(arg0 + 0x3c + arg1 * 2);
                    /* WARNING: Could not recover jumptable at 0x080b8864. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8874 @ 0x080B8874

void sub_080B8874(int arg0,int arg1,uint arg2,uint arg3)

{
  undefined4 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    uVar1 = sub_080B8AE0(arg2 & 0xffff,arg3 & 0xffff);
    *(undefined4 *)(arg0 + 0x30) = uVar1;
  }
  else {
    iVar2 = sub_080B8B08(*(undefined4 *)(arg0 + 0x30));
    *(ushort *)(arg0 + 0x1c) = (ushort)(iVar2 == 1);
  }
                    /* WARNING: Could not recover jumptable at 0x080b88a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B88A4 @ 0x080B88A4

void sub_080B88A4(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080C4618(5,0xf5,0x50,0xffed);
  *(undefined4 *)(arg0 + 0x34) = uVar1;
  return;
}


// sub_080B88CC @ 0x080B88CC

void sub_080B88CC(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(ushort *)(arg0 + 0x1c) = (ushort)(**(short **)(arg0 + 0x34) == 0);
                    /* WARNING: Could not recover jumptable at 0x080b88e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B88E4 @ 0x080B88E4

void sub_080B88E4(int arg0)

{
  if (*(int *)(arg0 + 0x28) != 0) {
    sub_080C48F0(*(int *)(arg0 + 0x28));
    *(undefined4 *)(arg0 + 0x28) = 0;
  }
  return;
}


// sub_080B8900 @ 0x080B8900

void sub_080B8900(int arg0)

{
  if (*(int *)(arg0 + 0x2c) != 0) {
    sub_080C48F0(*(int *)(arg0 + 0x2c));
  }
  sub_080C3818(1);
  Field_SetState(1);
  return;
}


// sub_080B8920 @ 0x080B8920

void sub_080B8920(int arg0)

{
  undefined2 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080B0248(0,0,0);
  if ((((iVar2 == 0) || (iVar2 = sub_080B0248(1,0,0), iVar2 == 0)) ||
      (iVar2 = sub_080B0248(3,0,0), iVar2 == 0)) || (iVar2 = sub_080B0248(2,0,0), iVar2 == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
                    /* WARNING: Could not recover jumptable at 0x080b8968. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B896C @ 0x080B896C

void sub_080B896C(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080B098C();
  *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 == 0);
                    /* WARNING: Could not recover jumptable at 0x080b8984. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8988 @ 0x080B8988

void sub_080B8988(void)

{
  Field_SetState(0x1a);
  return;
}


// sub_080B8994 @ 0x080B8994

int sub_080B8994(undefined4 arg0)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x8164ad4,0xffff);
  *(undefined4 *)(iVar1 + 0x24) = arg0;
  return iVar1;
}


