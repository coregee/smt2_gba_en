/* Ghidra decompilation of asm/code_080AD444.s (reference only; not compiled). */

// sub_080AD444 @ 0x080AD444

void sub_080AD444(void)

{
  return;
}


// sub_080AD448 @ 0x080AD448

void sub_080AD448(int arg0)

{
  DAT_03003b84 = DAT_03003b84 + 4;
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 6;
  _call_via_r6();
  return;
}


// sub_080AD478 @ 0x080AD478

void sub_080AD478(void)

{
  return;
}


// sub_080AD47C @ 0x080AD47C

void sub_080AD47C(int arg0)

{
  DAT_03003b84 = DAT_03003b84 + 4;
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 7;
  _call_via_r6();
  return;
}


// sub_080AD4B0 @ 0x080AD4B0

void sub_080AD4B0(void)

{
  return;
}


// sub_080AD4B4 @ 0x080AD4B4

void sub_080AD4B4(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = *DAT_03003b84;
  DAT_03003b84 = DAT_03003b84 + 1;
  *(short *)(arg0 + 0x1e) = (short)uVar1;
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 1;
  return;
}


// sub_080AD4CC @ 0x080AD4CC

void sub_080AD4CC(void)

{
  return;
}


// sub_080AD4D0 @ 0x080AD4D0

void sub_080AD4D0(int arg0)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = *DAT_03003b84;
  uVar3 = DAT_03003b84[1];
  if (iVar2 == 1) {
    if ((uint)*(ushort *)(arg0 + 0x1e) != (uVar3 & 0xffff)) goto LAB_080ad526;
  }
  else if (iVar2 == 0) {
    if ((uint)*(ushort *)(arg0 + 0x1e) == (uVar3 & 0xffff)) goto LAB_080ad526;
  }
  else if (iVar2 == 2) {
    if ((uVar3 & 0xffff) <= (uint)*(ushort *)(arg0 + 0x1e)) goto LAB_080ad526;
  }
  else if ((iVar2 == 3) && ((uint)*(ushort *)(arg0 + 0x1e) < (uVar3 & 0xffff))) {
LAB_080ad526:
    piVar1 = DAT_03003b84 + 2;
    DAT_03003b84 = DAT_03003b84 + 2;
    sub_080AD1A8(arg0,*piVar1);
    goto LAB_080ad536;
  }
  DAT_03003b84 = DAT_03003b84 + 2;
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 3;
LAB_080ad536:
                    /* WARNING: Could not recover jumptable at 0x080ad53a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AD53C @ 0x080AD53C

void sub_080AD53C(void)

{
  return;
}


// sub_080AD540 @ 0x080AD540

void sub_080AD540(int arg0)

{
  *(undefined4 *)(arg0 + 0x20) = *DAT_03003b84;
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 1;
  return;
}


// sub_080AD554 @ 0x080AD554

void sub_080AD554(void)

{
  return;
}


// sub_080AD558 @ 0x080AD558

void sub_080AD558(int arg0)

{
  int arg1;
  undefined4 arg3;
  
  arg3 = *DAT_03003b84;
  DAT_03003b84 = DAT_03003b84 + 1;
  arg1 = *(int *)(arg0 + 0x10) + 1;
  *(int *)(arg0 + 0x10) = arg1;
  _call_via_r3(arg0,arg1,0x3003b84,arg3);
  return;
}


// sub_080AD574 @ 0x080AD574

void sub_080AD574(void)

{
  return;
}


// sub_080AD578 @ 0x080AD578

void sub_080AD578(int arg0)

{
  sub_080AD0FC(*DAT_03003b84,(uint)*(ushort *)(arg0 + 2));
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 1;
  return;
}


// sub_080AD598 @ 0x080AD598

void sub_080AD598(void)

{
  return;
}


// sub_080AD59C @ 0x080AD59C

void sub_080AD59C(int arg0)

{
  sub_080C5170((uint)*DAT_03003b84);
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 1;
  return;
}


// sub_080AD5BC @ 0x080AD5BC

void sub_080AD5BC(void)

{
  return;
}


// sub_080AD5C0 @ 0x080AD5C0

void sub_080AD5C0(int arg0)

{
  sub_080C51D4((uint)*DAT_03003b84);
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 1;
  return;
}


// sub_080AD5E0 @ 0x080AD5E0

void sub_080AD5E0(void)

{
  return;
}


// sub_080AD5E4 @ 0x080AD5E4

void sub_080AD5E4(int arg0)

{
  m4aSongNumStop((uint)*DAT_03003b84);
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 1;
  return;
}


// sub_080AD604 @ 0x080AD604

void sub_080AD604(void)

{
  return;
}


// sub_080AD608 @ 0x080AD608

uint sub_080AD608(void)

{
  uint uVar1;
  ushort local_c;
  ushort local_a;
  
  sub_080C1F50((uint)DAT_03004562,(uint)DAT_03004564,&local_c,&local_a);
  uVar1 = sub_080C5E44((uint)*(ushort *)
                              ((uint)*(byte *)((uint)(local_c >> 2) + (uint)(local_a >> 2) * 0x20 +
                                              0x815efb4) * 2 + 0x815f1b4));
  return uVar1 & 0xffff;
}


// sub_080AD658 @ 0x080AD658

void sub_080AD658(void)

{
  uint uVar1;
  
  uVar1 = sub_080AD608();
  sub_080C5170(uVar1 & 0xffff);
  return;
}


// sub_080AD67C @ 0x080AD67C

uint sub_080AD67C(undefined4 arg0)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if ((short)arg0 != 0) {
    do {
      uVar4 = uVar4 + 1 & 0xffff;
    } while (*(short *)(uVar4 * 2 + 0x87df93c) != (short)arg0);
  }
  iVar2 = uVar4 * 8;
  iVar3 = sub_080C2340((uint)*(ushort *)(iVar2 + 0x815f214));
  if (iVar3 == 0) {
    uVar1 = *(ushort *)(&UNK_0815f216 + iVar2);
  }
  else {
    uVar1 = *(ushort *)(&UNK_0815f218 + iVar2);
  }
  uVar4 = sub_080C5E44((uint)uVar1);
  return uVar4 & 0xffff;
}


// sub_080AD6C8 @ 0x080AD6C8

void sub_080AD6C8(void)

{
  uint uVar1;
  
  uVar1 = sub_080AD67C((uint)DAT_030069f8);
  sub_080C5170(uVar1 & 0xffff);
  return;
}


// sub_080AD6E4 @ 0x080AD6E4

void sub_080AD6E4(undefined4 arg0)

{
  undefined4 arg0_00;
  int iVar1;
  
  arg0_00 = sub_080B2EFC(0,0);
  iVar1 = sub_080B3038(arg0_00,0x21);
  DAT_03004582 = (short)arg0;
  if (iVar1 == 0) {
    Field_SetState(0x10);
    DAT_0300456e = 0;
    if (DAT_030045a0 == 1) {
      DAT_030045a0 = 2;
    }
    if ((short)arg0 == 0) {
      sub_080C51D4(0x65);
    }
  }
  else {
    sub_080AD0FC(0x8165598,0xffff);
    Field_SetState(0x1a);
    DAT_0300456e = 0;
  }
  return;
}


// sub_080AD750 @ 0x080AD750

uint sub_080AD750(void)

{
  int iVar1;
  
  iVar1 = sub_080B0248(0,0,0);
  return (uint)(iVar1 - 2U < 2);
}


// sub_080AD76C @ 0x080AD76C

void sub_080AD76C(void)

{
  uint uVar1;
  
  uVar1 = sub_080C5E58();
  if ((uVar1 & 0xffff) != 0xffff) {
    sub_080B6568(uVar1 & 0xffff);
  }
  return;
}


// Field_SetState @ 0x080AD78C

void Field_SetState(undefined4 arg0)

{
  int iVar1;
  
  DAT_03004550 = (short)arg0;
  if (((short)arg0 == 1) && (iVar1 = sub_080AD750(), iVar1 == 1)) {
    sub_080AD76C();
  }
  if ((short)arg0 == 0x10) {
    DAT_0200dfcc = 0;
    DAT_0200dfce = 0;
    DAT_0200dfd0 = 0;
  }
  if ((short)arg0 == 3) {
    sub_080B3878(0);
  }
  DAT_03003ff4 = 0;
  return;
}


// sub_080AD7E4 @ 0x080AD7E4

uint sub_080AD7E4(void)

{
  return (uint)DAT_03004550;
}


// sub_080AD7F0 @ 0x080AD7F0

void sub_080AD7F0(void)

{
  DAT_03003ff8 = 1;
  return;
}


// sub_080AD7FC @ 0x080AD7FC

undefined4 sub_080AD7FC(void)

{
  return DAT_03003ff8;
}


// sub_080AD808 @ 0x080AD808

void sub_080AD808(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080AD7FC();
  *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 == 0);
                    /* WARNING: Could not recover jumptable at 0x080ad820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AD824 @ 0x080AD824

void sub_080AD824(uint arg0,uint arg1,int *arg2)

{
  undefined4 uVar1;
  int iVar2;
  uint arg2_00;
  int *piVar3;
  dword dVar4;
  dword arg1_00;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = sub_080C8B10(arg0 & 0xffff,arg1 & 0xffff);
  arg2_00 = (uint)DAT_030050f8;
  piVar3 = (int *)(iVar2 + arg2_00 * 0xe8 + 0x98);
  if (*arg2 == 0) goto LAB_080adcc2;
  switch(*arg2) {
  case 1:
    local_2c = 0;
    arg1_00 = 0x200f874;
    dVar4 = 0x5002000;
    CpuSet(&local_2c,0x200f874,0x5002000);
    iVar2 = piVar3[0x18];
    goto LAB_080adbde;
  case 2:
    if (piVar3[0x19] != 0) {
      LZ77UnCompWram(piVar3[0x19],0x2010874,arg2_00);
    }
    break;
  case 3:
    if (piVar3[0x1a] != 0) {
      LZ77UnCompWram(piVar3[0x1a],0x2011874,arg2_00);
    }
    break;
  case 4:
    if (piVar3[0x1b] != 0) {
      LZ77UnCompWram(piVar3[0x1b],0x2012874,arg2_00);
    }
    break;
  case 5:
    if (piVar3[0x1c] != 0) {
      LZ77UnCompWram(piVar3[0x1c],0x2013874,arg2_00);
    }
    break;
  case 6:
    if (piVar3[0x1d] != 0) {
      LZ77UnCompWram(piVar3[0x1d],0x2014874,arg2_00);
    }
    break;
  case 7:
    if (piVar3[0x1e] != 0) {
      LZ77UnCompWram(piVar3[0x1e],0x2015874,arg2_00);
    }
    break;
  case 8:
    if (piVar3[0x1f] != 0) {
      LZ77UnCompWram(piVar3[0x1f],0x2016874,arg2_00);
    }
    break;
  case 9:
    local_28 = 0;
    arg1_00 = 0x2017874;
    dVar4 = 0x5001800;
    CpuSet(&local_28,0x2017874,0x5001800);
    iVar2 = piVar3[0x20];
    goto LAB_080adbde;
  case 10:
    if (piVar3[0x21] != 0) {
      LZ77UnCompWram(piVar3[0x21],0x2018874,arg2_00);
    }
    break;
  case 0xb:
    if (piVar3[0x22] != 0) {
      LZ77UnCompWram(piVar3[0x22],0x2019874,arg2_00);
    }
    break;
  case 0xc:
    if (piVar3[0x23] != 0) {
      LZ77UnCompWram(piVar3[0x23],0x201a874,arg2_00);
    }
    break;
  case 0xd:
    if (piVar3[0x24] != 0) {
      LZ77UnCompWram(piVar3[0x24],0x201b874,arg2_00);
    }
    break;
  case 0xe:
    if (piVar3[0x25] != 0) {
      LZ77UnCompWram(piVar3[0x25],0x201c874,arg2_00);
    }
    break;
  case 0xf:
    local_24 = 0;
    arg1_00 = 0x201d874;
    dVar4 = 0x5001a00;
    CpuSet(&local_24,0x201d874,0x5001a00);
    iVar2 = *piVar3;
    goto LAB_080adbde;
  case 0x10:
    if (piVar3[1] != 0) {
      LZ77UnCompWram(piVar3[1],0x201e874,arg2_00);
    }
    break;
  case 0x11:
    if (piVar3[2] != 0) {
      LZ77UnCompWram(piVar3[2],0x201f874,arg2_00);
    }
    break;
  case 0x12:
    if (piVar3[3] != 0) {
      LZ77UnCompWram(piVar3[3],0x2020874,arg2_00);
    }
    break;
  case 0x13:
    if (piVar3[4] != 0) {
      LZ77UnCompWram(piVar3[4],0x2021874,arg2_00);
    }
    break;
  case 0x14:
    if (piVar3[5] != 0) {
      LZ77UnCompWram(piVar3[5],0x2022874,arg2_00);
    }
    break;
  case 0x15:
    if (piVar3[6] != 0) {
      LZ77UnCompWram(piVar3[6],0x2023874,arg2_00);
    }
    break;
  case 0x16:
    local_20 = 0;
    arg1_00 = 0x2024074;
    dVar4 = 0x5001000;
    CpuSet(&local_20,0x2024074,0x5001000);
    iVar2 = piVar3[8];
    goto LAB_080adbde;
  case 0x17:
    if (piVar3[9] != 0) {
      LZ77UnCompWram(piVar3[9],0x2025074,arg2_00);
    }
    break;
  case 0x18:
    if (piVar3[10] != 0) {
      LZ77UnCompWram(piVar3[10],0x2026074,arg2_00);
    }
    break;
  case 0x19:
    if (piVar3[0xb] != 0) {
      LZ77UnCompWram(piVar3[0xb],0x2027074,arg2_00);
    }
    break;
  case 0x1a:
    local_1c = 0;
    arg1_00 = 0x2028074;
    dVar4 = 0x5001600;
    CpuSet(&local_1c,0x2028074,0x5001600);
    iVar2 = piVar3[0x28];
    goto LAB_080adbde;
  case 0x1b:
    if (piVar3[0x29] != 0) {
      LZ77UnCompWram(piVar3[0x29],0x2029074,arg2_00);
    }
    break;
  case 0x1c:
    if (piVar3[0x2a] != 0) {
      LZ77UnCompWram(piVar3[0x2a],0x202a074,arg2_00);
    }
    break;
  case 0x1d:
    if (piVar3[0x2b] != 0) {
      LZ77UnCompWram(piVar3[0x2b],0x202b074,arg2_00);
    }
    break;
  case 0x1e:
    if (piVar3[0x2c] != 0) {
      LZ77UnCompWram(piVar3[0x2c],0x202c074,arg2_00);
    }
    break;
  case 0x1f:
    if (piVar3[0x2d] != 0) {
      LZ77UnCompWram(piVar3[0x2d],0x202d074,arg2_00);
    }
    break;
  case 0x20:
    local_18 = 0;
    arg1_00 = 0x202d874;
    dVar4 = 0x5000d00;
    CpuSet(&local_18,0x202d874,0x5000d00);
    iVar2 = piVar3[0x10];
LAB_080adbde:
    if (iVar2 != 0) {
      LZ77UnCompWram(iVar2,arg1_00,dVar4);
    }
    break;
  case 0x21:
    if (piVar3[0x11] != 0) {
      LZ77UnCompWram(piVar3[0x11],0x202e874,arg2_00);
    }
    break;
  case 0x22:
    if (piVar3[0x12] != 0) {
      LZ77UnCompWram(piVar3[0x12],0x202f874,arg2_00);
    }
    break;
  case 0x23:
    if (piVar3[0x13] != 0) {
      LZ77UnCompWram(piVar3[0x13],0x2030874,arg2_00);
    }
    break;
  case 0x24:
    local_14 = 0;
    REG_DMA3SAD = &local_14;
    REG_DMA3DAD = 0x2030c74;
    REG_DMA3CNT = 0x85001500;
    uVar1 = REG_DMA3CNT;
    DAT_03004604 = 0x202d874;
    sub_080B6F28(0x815f264);
    break;
  case 0x25:
    dVar4 = 0x815f264;
    goto LAB_080adc76;
  case 0x26:
    dVar4 = 0x815f280;
LAB_080adc76:
    iVar2 = sub_080B6F40(dVar4);
    if (iVar2 == 1) {
LAB_080adc9a:
      *arg2 = *arg2 + -1;
    }
    else {
      sub_080B6F28(dVar4 + 0x1c);
    }
    break;
  case 0x27:
    iVar2 = sub_080B6F40(0x815f29c);
    if (iVar2 != 1) {
      DAT_03003fcc = 0x2030c74;
      break;
    }
    goto LAB_080adc9a;
  default:
    iVar2 = 0;
    goto LAB_080adcc0;
  }
  iVar2 = *arg2 + 1;
LAB_080adcc0:
  *arg2 = iVar2;
LAB_080adcc2:
                    /* WARNING: Could not recover jumptable at 0x080adcc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080ADCCC @ 0x080ADCCC

void sub_080ADCCC(uint arg0,uint arg1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = sub_080C8B10(arg0 & 0xffff,arg1 & 0xffff);
  iVar1 = iVar1 + (uint)DAT_030050f8 * 0xe8 + 0x98;
  DAT_03003fc0 = 0x201d874;
  DAT_03003bb0 = 0x2024074;
  DAT_03004604 = 0x202d874;
  DAT_03003bb4 = *(undefined4 *)(iVar1 + 0x40);
  DAT_03003b90 = 0x200f874;
  DAT_03004620 = 0x2017874;
  if ((arg0 == 0x1a) && (iVar2 = sub_080C2340(0x11), iVar2 == 0)) {
    DAT_03004510 = *(int *)(iVar1 + 0xc0) + 0x80;
  }
  else {
    DAT_03004510 = *(int *)(iVar1 + 0xc0);
  }
  DAT_03003b94 = 0x2028074;
  DAT_0300462c = *(undefined4 *)(iVar1 + 0xa0);
  if ((arg0 == 0x1a) && (iVar2 = sub_080C2340(0x11), iVar2 == 0)) {
    DAT_03004630 = *(int *)(iVar1 + 0xc4) + 0x100;
  }
  else {
    DAT_03004630 = *(int *)(iVar1 + 0xc4);
  }
  DAT_0300461c = *(undefined4 *)(iVar1 + 0xcc);
  DAT_03003fe4 = *(undefined4 *)(iVar1 + 0xd4);
  DAT_03003fe8 = *(undefined4 *)(iVar1 + 0xdc);
  if ((arg0 == 0x1a) && (iVar2 = sub_080C2340(0x11), iVar2 == 0)) {
    DAT_03003fc8 = *(int *)(iVar1 + 200) + 0x80;
  }
  else {
    DAT_03003fc8 = *(int *)(iVar1 + 200);
  }
  sub_080ADE54(DAT_03004510,0x200f7f4,0x10);
  sub_080ADE54(DAT_03004630,0x200f814,0x20);
  sub_080ADE54(DAT_03003fc8,0x200f854,0x10);
  return;
}


// sub_080ADE54 @ 0x080ADE54

void sub_080ADE54(undefined4 arg0,ushort *arg1,uint arg2)

{
  undefined4 uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar5 = arg2 & 0xffff;
  uVar4 = 0x12;
  REG_DMA3SAD = arg0;
  REG_DMA3DAD = arg1;
  REG_DMA3CNT = (int)(uVar5 << 1) >> 2 | 0x84000000;
  uVar1 = REG_DMA3CNT;
  if (DAT_03004614 == 0x4d) {
    uVar4 = 0x17;
  }
  uVar3 = 0;
  if (uVar5 != 0) {
    do {
      uVar2 = *arg1;
      if ((uVar2 & 0x1f) < uVar4) {
        uVar2 = uVar2 & 0xffe0;
      }
      else {
        uVar2 = uVar2 - uVar4;
      }
      if ((ushort)(uVar2 & 0x3e0) < (ushort)(uVar4 * 0x20)) {
        uVar2 = uVar2 & 0xfc1f;
      }
      else {
        uVar2 = uVar2 + uVar4 * -0x20;
      }
      if ((ushort)(uVar2 & 0x7c00) < (ushort)(uVar4 * 0x400)) {
        uVar2 = uVar2 & 0x83ff;
      }
      else {
        uVar2 = uVar2 + uVar4 * -0x400;
      }
      *arg1 = uVar2;
      uVar3 = uVar3 + 1;
      arg1 = arg1 + 1;
    } while (uVar3 < uVar5);
  }
                    /* WARNING: Could not recover jumptable at 0x080adf10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080ADF14 @ 0x080ADF14

undefined4 sub_080ADF14(undefined4 arg0)

{
  short *psVar1;
  
  psVar1 = (short *)0x815f2b8;
  while( true ) {
    if (*psVar1 == -1) {
      return 0;
    }
    if (*psVar1 == (short)arg0) break;
    psVar1 = psVar1 + 1;
  }
  return 1;
}


// sub_080ADF40 @ 0x080ADF40

undefined4 sub_080ADF40(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((DAT_03004614 == 0x4a) && (DAT_03004514 == 4)) {
    uVar1 = 1;
  }
  return uVar1;
}


// sub_080ADF64 @ 0x080ADF64

void sub_080ADF64(void)

{
  int iVar1;
  dword dVar2;
  
  iVar1 = sub_080ADF14((uint)(ushort)DAT_03004614);
  if (iVar1 == 1) {
    REG_DMA3SAD = 0x81c2270;
    REG_DMA3DAD = 0x6003000;
    dVar2 = 0x84000140;
  }
  else {
    iVar1 = sub_080ADF40();
    if (iVar1 == 1) {
      REG_DMA3SAD = 0x848de60;
      REG_DMA3DAD = 0x6003000;
      dVar2 = 0x84000140;
    }
    else {
      REG_DMA3SAD = 0x81c0a70;
      REG_DMA3DAD = 0x6003000;
      dVar2 = 0x84000200;
    }
  }
  REG_DMA3CNT = dVar2;
  DAT_0300000e = 0;
  return;
}


// sub_080ADFEC @ 0x080ADFEC

void sub_080ADFEC(undefined4 arg0)

{
  undefined4 uVar1;
  undefined4 local_14;
  
  sub_080ADCCC(DAT_03004614,DAT_03004514);
  local_14 = 0;
  REG_DMA3SAD = &local_14;
  REG_DMA3DAD = 0x2028074;
  REG_DMA3CNT = 0x85000008;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = DAT_03003b94;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  DAT_030029b0 = *DAT_03004630;
  sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
  sub_080ACFCC(3,DAT_03004510,&DAT_03002b50,0x20);
  sub_080ADF64();
  sub_080AE1C4();
  sub_080ACFCC(3,DAT_03003fc8,&DAT_03002d50,0x20);
  if ((ushort)((short)arg0 - 2U) < 2) {
    sub_080B437C();
  }
  return;
}


// sub_080AE0BC @ 0x080AE0BC

void sub_080AE0BC(void)

{
  undefined4 uVar1;
  undefined1 local_8 [8];
  
  switch(DAT_03003bbc) {
  case 0:
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x2028074;
    REG_DMA3CNT = 0x85000008;
    uVar1 = REG_DMA3CNT;
    REG_DMA3SAD = DAT_03003b94;
    REG_DMA3DAD = 0x6004000;
    REG_DMA3CNT = 0x84000800;
    uVar1 = REG_DMA3CNT;
    break;
  case 1:
    DAT_030029b0 = *DAT_03004630;
    sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
    break;
  case 2:
    sub_080ACFCC(3,DAT_03004510,0x3002b50,0x20);
    break;
  case 3:
    sub_080ADF64();
    break;
  case 4:
    sub_080AE1C4();
    break;
  case 5:
    sub_080ACFCC(3,DAT_03003fc8,0x3002d50,0x20);
  default:
    DAT_03003bbc = 0xffff;
    return;
  }
  DAT_03003bbc = DAT_03003bbc + 1;
  return;
}


// sub_080AE1C4 @ 0x080AE1C4

void sub_080AE1C4(void)

{
  undefined4 uVar1;
  undefined4 in_r2;
  
  if (DAT_0300461c != 0) {
    LZ77UnCompWram(DAT_0300461c,0x200afc8,in_r2);
  }
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080AE1FC @ 0x080AE1FC

void sub_080AE1FC(void)

{
  undefined4 uVar1;
  undefined4 in_r2;
  
  if (DAT_03003fe4 != 0) {
    LZ77UnCompWram(DAT_03003fe4,0x200afc8,in_r2);
  }
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080AE234 @ 0x080AE234

void sub_080AE234(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  puVar2 = *(undefined2 **)(iVar1 + 0x90);
  DAT_0300456a = *puVar2;
  DAT_0300456c = puVar2[1];
  DAT_03004570 = puVar2 + 2;
  local_10 = 0;
  CpuSet(&local_10,&DAT_030045b4,0x5000010);
  local_c = 0;
  CpuSet(&local_c,0x203a3e8,0x5000014);
  return;
}


// sub_080AE294 @ 0x080AE294

void sub_080AE294(void)

{
  sub_080F3F58(0xffffffef);
  sub_080C2230(0);
  return;
}


// sub_080AE2A8 @ 0x080AE2A8

void sub_080AE2A8(undefined4 arg0,undefined4 arg1)

{
  DAT_03004562 = (undefined2)arg0;
  DAT_03004566 = (undefined2)arg0;
  DAT_03004564 = (undefined2)arg1;
  DAT_03004568 = (undefined2)arg1;
  return;
}


// sub_080AE2C0 @ 0x080AE2C0

/* WARNING: Control flow encountered bad instruction data */

void sub_080AE2C0(void)

{
  bool in_ZR;
  bool in_CY;
  
  if (in_CY && !in_ZR) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!in_CY || in_ZR) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// sub_080AE2D0 @ 0x080AE2D0

void sub_080AE2D0(void)

{
  undefined4 local_14;
  undefined4 local_10;
  
  local_14 = 0;
  CpuSet(&local_14,0x2036074,0x5000008);
  local_10 = 0;
  CpuSet(&local_10,0x2036094,0x5000008);
  return;
}


// sub_080AE304 @ 0x080AE304

void sub_080AE304(void)

{
  sub_080B2840(0,0,0);
  do {
    sub_080B2CC0();
  } while (DAT_0300455e != 0);
  sub_080AE494();
  return;
}


// sub_080AE330 @ 0x080AE330

void sub_080AE330(void)

{
  CpuSet(0x80b210d,0x3003bc0,0x4000100);
  CpuSet(0x80b23d1,0x3004010,0x4000140);
  return;
}


// sub_080AE364 @ 0x080AE364

void sub_080AE364(undefined4 arg0)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  
  DAT_03003b9c = 0;
  DAT_03004608 = 0;
  sub_080AE2D0();
  sub_080AE330();
  if ((((ushort)arg0 == 0) || ((ushort)arg0 == 4)) || ((ushort)arg0 == 6)) {
    local_10 = 0;
    REG_DMA3SAD = &local_10;
    REG_DMA3DAD = 0x3004550;
    REG_DMA3CNT = 0x85000029;
    uVar1 = REG_DMA3CNT;
    sub_080AE234();
    if ((ushort)arg0 == 0) {
      sub_080AE2A8(0,0);
      DAT_03004552 = (ushort)arg0;
      DAT_03004554 = (ushort)arg0;
      sub_080B30A0();
    }
    else {
      sub_080AE2A8((uint)DAT_03003fd4,(uint)DAT_03003fd6);
      DAT_03004552 = DAT_03003fd8;
      DAT_03004554 = DAT_03003fd8;
    }
    iVar2 = sub_080B3078(0,0,6);
    if (iVar2 == 1) {
      DAT_030029b0 = DAT_0200f814;
      sub_080ACFCC(3,0x200f814,&DAT_03002b70,0x40);
      sub_080ACFCC(3,0x200f7f4,&DAT_03002b50,0x20);
      sub_080ACFCC(3,0x200f854,&DAT_03002d50,0x20);
    }
    sub_080AF4EC((uint)DAT_03004562,(uint)DAT_03004564);
    sub_080AF5B8((uint)DAT_03004562,(uint)DAT_03004564,(uint)DAT_03004552);
    DAT_030045fc = 1;
    DAT_03004550 = 10;
    sub_080AE304();
    sub_080C20C8();
    sub_080C67C0(0x30029b0,7);
  }
  else {
    DAT_03004550 = 10;
  }
  return;
}


// sub_080AE494 @ 0x080AE494

void sub_080AE494(void)

{
  undefined4 in_r0;
  
  DisplayList_Add(in_r0,1);
  DAT_0300455c = 1;
  return;
}


// sub_080AE4AC @ 0x080AE4AC

void sub_080AE4AC(uint arg0,uint arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = arg2 & 0xffff;
  uVar8 = arg3 & 0xffff;
  if (((((int)(arg0 * 0x10000) < 0) || ((uint)DAT_0300456a <= (arg0 & 0xffff))) ||
      ((int)(arg1 * 0x10000) < 0)) || ((uint)DAT_0300456c <= (arg1 & 0xffff))) {
    iVar2 = uVar7 * 0xc + uVar8 * 0x6c;
    uVar3 = 0;
  }
  else {
    uVar4 = (uint)DAT_03004552;
    uVar1 = *(ushort *)(((arg1 & 0xffff) * (uint)DAT_0300456a + (arg0 & 0xffff)) * 2 + DAT_03004570)
    ;
    uVar6 = 0;
    puVar5 = (ushort *)(uVar7 * 0xc + uVar8 * 0x6c + 0x200ab0c);
    do {
      *puVar5 = (ushort)((int)(uint)uVar1 >> (*(ushort *)(uVar4 * 2 + 0x815f2e6) & 0xff)) & 3;
      uVar4 = uVar4 + 1 & 3;
      puVar5 = puVar5 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 4);
    iVar2 = uVar7 * 0xc + uVar8 * 0x6c;
    uVar3 = 1;
  }
  *(undefined2 *)(iVar2 + 0x200ab08) = uVar3;
  return;
}


// sub_080AE574 @ 0x080AE574

void sub_080AE574(int arg0,int arg1)

{
  undefined4 uVar1;
  uint arg0_00;
  int iVar2;
  uint arg1_00;
  uint arg2;
  uint arg3;
  uint uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_2c;
  int local_28;
  uint uStack_24;
  
  uVar4 = (uint)DAT_03004562;
  uVar3 = (uint)DAT_03004564;
  local_2c = 0;
  REG_DMA3SAD = &local_2c;
  REG_DMA3DAD = 0x200ab08;
  REG_DMA3CNT = 0x850000f3;
  uVar1 = REG_DMA3CNT;
  if (arg0 == 1) {
    uVar4 = uVar4 + 5 & 0xffff;
    uVar3 = uVar3 - 4;
  }
  else if (arg0 == 0) {
    uVar4 = uVar4 - 4 & 0xffff;
    uVar3 = uVar3 - 5;
  }
  else if (arg0 == 2) {
    uVar4 = uVar4 + 4 & 0xffff;
    uVar3 = uVar3 + 5;
  }
  else {
    if (arg0 != 3) goto LAB_080ae5ee;
    uVar4 = uVar4 - 5 & 0xffff;
    uVar3 = uVar3 + 4;
  }
  uVar3 = uVar3 & 0xffff;
LAB_080ae5ee:
  arg3 = 0;
  local_28 = arg1;
  do {
    arg2 = 0;
    uStack_24 = arg3 + 1;
    do {
      if (arg0 == 1) {
        arg1_00 = uVar3 + arg2 & 0xffff;
        arg0_00 = uVar4 - arg3 & 0xffff;
LAB_080ae642:
        sub_080AE4AC(arg0_00,arg1_00,arg2,arg3);
      }
      else {
        if (arg0 == 0) {
          arg0_00 = uVar4 + arg2 & 0xffff;
          arg1_00 = uVar3 + arg3 & 0xffff;
          goto LAB_080ae642;
        }
        if (arg0 == 2) {
          arg0_00 = uVar4 - arg2 & 0xffff;
          arg1_00 = uVar3 - arg3 & 0xffff;
          goto LAB_080ae642;
        }
        if (arg0 == 3) {
          sub_080AE4AC(uVar4 + arg3 & 0xffff,uVar3 - arg2 & 0xffff,arg2,arg3);
        }
      }
      arg2 = arg2 + 1 & 0xffff;
    } while (arg2 < 9);
    arg3 = uStack_24 & 0xffff;
    if (8 < arg3) {
      if ((local_28 == 0) && (iVar2 = sub_080ADF40(), iVar2 == 0)) {
        iVar2 = sub_080B0248(3,0,0);
        if ((((iVar2 != 0) && (iVar2 = sub_080B0248(3,0,0xffff), iVar2 != 0)) ||
            ((iVar2 = sub_080B0248(0,0xffff,0), iVar2 != 0 &&
             (iVar2 = sub_080B0248(3,0,0xffff), iVar2 != 0)))) ||
           (((iVar2 = sub_080B0248(0,0,0), iVar2 != 0 && (iVar2 = sub_080B0248(3,0,0), iVar2 != 0))
            || ((iVar2 = sub_080B0248(0,0,0), iVar2 != 0 &&
                (iVar2 = sub_080B0248(0,0xffff,0), iVar2 != 0)))))) {
          DAT_0200ace0 = 0;
          DAT_0200ac78 = 0;
        }
        iVar2 = sub_080B0248(1,0,0);
        if ((((iVar2 != 0) && (iVar2 = sub_080B0248(1,0,0xffff), iVar2 != 0)) ||
            ((iVar2 = sub_080B0248(0,1,0), iVar2 != 0 &&
             (iVar2 = sub_080B0248(1,0,0xffff), iVar2 != 0)))) ||
           (((iVar2 = sub_080B0248(0,0,0), iVar2 != 0 && (iVar2 = sub_080B0248(1,0,0), iVar2 != 0))
            || ((iVar2 = sub_080B0248(0,0,0), iVar2 != 0 &&
                (iVar2 = sub_080B0248(0,1,0), iVar2 != 0)))))) {
          DAT_0200acf8 = 0;
          DAT_0200ac90 = 0;
        }
        iVar2 = sub_080B0248(3,0,0xffff);
        if (((((iVar2 != 0) && (iVar2 = sub_080B0248(3,0,0xfffe), iVar2 != 0)) ||
             ((iVar2 = sub_080B0248(3,0,0xffff), iVar2 != 0 &&
              (iVar2 = sub_080B0248(0,0,0xffff), iVar2 != 0)))) ||
            ((iVar2 = sub_080B0248(0,0,0xffff), iVar2 != 0 &&
             (iVar2 = sub_080B0248(0,0xffff,0xffff), iVar2 != 0)))) ||
           ((iVar2 = sub_080B0248(0,0xffff,0xffff), iVar2 != 0 &&
            (iVar2 = sub_080B0248(3,0,0xfffe), iVar2 != 0)))) {
          DAT_0200ac74 = 0;
          DAT_0200ac0c = 0;
        }
        iVar2 = sub_080B0248(3,0,0);
        if (((((iVar2 != 0) && (iVar2 = sub_080B0248(3,0,0xffff), iVar2 != 0)) ||
             ((iVar2 = sub_080B0248(0,0xffff,0xffff), iVar2 != 0 &&
              (iVar2 = sub_080B0248(3,0,0xffff), iVar2 != 0)))) ||
            (((iVar2 = sub_080B0248(3,0,0), iVar2 != 0 &&
              (iVar2 = sub_080B0248(3,0,0xffff), iVar2 != 0)) ||
             ((iVar2 = sub_080B0248(0,0xffff,0), iVar2 != 0 &&
              (iVar2 = sub_080B0248(3,0,0xffff), iVar2 != 0)))))) ||
           ((iVar2 = sub_080B0248(0,0,0), iVar2 != 0 &&
            (iVar2 = sub_080B0248(0,0xffff,0), iVar2 != 0)))) {
          DAT_0200ac68 = 0;
          DAT_0200ac00 = 0;
        }
        iVar2 = sub_080B0248(1,0,0xffff);
        if ((((iVar2 != 0) && (iVar2 = sub_080B0248(1,0,0xfffe), iVar2 != 0)) ||
            ((iVar2 = sub_080B0248(1,0,0xffff), iVar2 != 0 &&
             (iVar2 = sub_080B0248(0,0,0xffff), iVar2 != 0)))) ||
           (((iVar2 = sub_080B0248(0,0,0xffff), iVar2 != 0 &&
             (iVar2 = sub_080B0248(0,1,0xffff), iVar2 != 0)) ||
            ((iVar2 = sub_080B0248(0,1,0xffff), iVar2 != 0 &&
             (iVar2 = sub_080B0248(1,0,0xfffe), iVar2 != 0)))))) {
          DAT_0200ac8c = 0;
          DAT_0200ac24 = 0;
        }
        iVar2 = sub_080B0248(1,0,0);
        if (((((iVar2 != 0) && (iVar2 = sub_080B0248(1,0,0xffff), iVar2 != 0)) ||
             ((iVar2 = sub_080B0248(0,1,0xffff), iVar2 != 0 &&
              (iVar2 = sub_080B0248(1,0,0xffff), iVar2 != 0)))) ||
            ((iVar2 = sub_080B0248(1,0,0), iVar2 != 0 &&
             (iVar2 = sub_080B0248(1,0,0xffff), iVar2 != 0)))) ||
           (((iVar2 = sub_080B0248(0,1,0), iVar2 != 0 &&
             (iVar2 = sub_080B0248(1,0,0xffff), iVar2 != 0)) ||
            ((iVar2 = sub_080B0248(0,0,0), iVar2 != 0 && (iVar2 = sub_080B0248(0,1,0), iVar2 != 0)))
            ))) {
          DAT_0200ac98 = 0;
          DAT_0200ac30 = 0;
        }
        iVar2 = sub_080B0248(0,0,0);
        if ((((iVar2 != 0) && (iVar2 = sub_080B0248(0,0xffff,0), iVar2 != 0)) ||
            ((iVar2 = sub_080B0248(0,0xffff,0), iVar2 != 0 &&
             (iVar2 = sub_080B0248(3,0,0xffff), iVar2 != 0)))) ||
           ((iVar2 = sub_080B0248(3,0,0), iVar2 != 0 &&
            (iVar2 = sub_080B0248(3,0,0xffff), iVar2 != 0)))) {
          DAT_0200ac7a = 0;
          DAT_0200ac6a = 0;
        }
        iVar2 = sub_080B0248(0,0,0);
        if ((((iVar2 != 0) && (iVar2 = sub_080B0248(0,1,0), iVar2 != 0)) ||
            ((iVar2 = sub_080B0248(0,1,0), iVar2 != 0 &&
             (iVar2 = sub_080B0248(1,0,0xffff), iVar2 != 0)))) ||
           ((iVar2 = sub_080B0248(1,0,0), iVar2 != 0 &&
            (iVar2 = sub_080B0248(1,0,0xffff), iVar2 != 0)))) {
          DAT_0200ac8e = 0;
          DAT_0200ac9e = 0;
        }
        iVar2 = sub_080B0248(0,0,0xffff);
        if ((((iVar2 != 0) && (iVar2 = sub_080B0248(0,0xffff,0xffff), iVar2 != 0)) ||
            ((iVar2 = sub_080B0248(0,0xffff,0xffff), iVar2 != 0 &&
             (iVar2 = sub_080B0248(3,0,0xfffe), iVar2 != 0)))) ||
           (((iVar2 = sub_080B0248(3,0,0xffff), iVar2 != 0 &&
             (iVar2 = sub_080B0248(3,0,0xfffe), iVar2 != 0)) ||
            (iVar2 = sub_080B0248(0,0xffff,0xfffe), iVar2 != 0)))) {
          DAT_0200ac0e = 0;
          DAT_0200abfe = 0;
        }
        iVar2 = sub_080B0248(0,0,0xffff);
        if ((((iVar2 != 0) && (iVar2 = sub_080B0248(0,1,0xffff), iVar2 != 0)) ||
            ((iVar2 = sub_080B0248(0,1,0xffff), iVar2 != 0 &&
             (iVar2 = sub_080B0248(1,0,0xfffe), iVar2 != 0)))) ||
           (((iVar2 = sub_080B0248(1,0,0xffff), iVar2 != 0 &&
             (iVar2 = sub_080B0248(1,0,0xfffe), iVar2 != 0)) ||
            (iVar2 = sub_080B0248(0,1,0xfffe), iVar2 != 0)))) {
          DAT_0200ac22 = 0;
          DAT_0200ac32 = 0;
        }
        iVar2 = sub_080B0248(0,0,0);
        if ((iVar2 != 0) && (iVar2 = sub_080B0248(3,0,0), iVar2 != 0)) {
          DAT_0200ac7a = 0;
          DAT_0200ac6a = 0;
          DAT_0200ac68 = 0;
          DAT_0200ac00 = 0;
        }
        iVar2 = sub_080B0248(0,0,0);
        if ((iVar2 != 0) && (iVar2 = sub_080B0248(1,0,0), iVar2 != 0)) {
          DAT_0200ac8e = 0;
          DAT_0200ac9e = 0;
          DAT_0200ac98 = 0;
          DAT_0200ac30 = 0;
        }
        iVar2 = sub_080B0248(3,0,0);
        if (iVar2 != 0) {
          DAT_0200ad52 = 0;
          DAT_0200ad40 = 0;
        }
        iVar2 = sub_080B0248(1,0,0);
        if (iVar2 != 0) {
          DAT_0200ad66 = 0;
          DAT_0200ad70 = 0;
        }
        iVar2 = sub_080B0248(0,0,0xffff);
        if ((iVar2 != 0) && (iVar2 = sub_080B0248(3,0,0xffff), iVar2 != 0)) {
          DAT_0200ac0e = 0;
        }
        iVar2 = sub_080B0248(0,0,0xffff);
        if ((iVar2 != 0) && (iVar2 = sub_080B0248(1,0,0xffff), iVar2 != 0)) {
          DAT_0200ac22 = 0;
        }
      }
                    /* WARNING: Could not recover jumptable at 0x080aecbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  } while( true );
}


// sub_080AECD4 @ 0x080AECD4

void sub_080AECD4(uint arg0,uint arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  uint uVar2;
  undefined4 arg0_00;
  int iVar3;
  uint arg0_01;
  ushort *puVar4;
  ushort *puVar5;
  uint arg1_00;
  uint uVar6;
  
  arg1_00 = arg1 & 0xffff;
  puVar5 = (ushort *)((arg3 & 0xffff) * 0x150 + (arg2 & 0xffff) * 0xc + 0x2005000);
  arg0_01 = arg0 & 0xffff;
  if (((((int)(arg0 * 0x10000) < 0) || (DAT_0300456a <= arg0_01)) || ((int)(arg1 * 0x10000) < 0)) ||
     (DAT_0300456c <= arg1_00)) {
    uVar1 = 0;
  }
  else {
    uVar2 = sub_080AF620(arg0_01,arg1_00);
    if ((uVar2 & 0xffff) == 0) {
      return;
    }
    uVar2 = sub_080B447C();
    uVar2 = uVar2 & 0xffff;
    uVar1 = *(ushort *)((arg1_00 * DAT_0300456a + arg0_01) * 2 + DAT_03004570);
    uVar6 = 0;
    puVar4 = puVar5 + 2;
    do {
      *puVar4 = (ushort)((int)(uint)uVar1 >> (*(ushort *)(uVar2 * 2 + 0x815f2e6) & 0xff)) & 3;
      *(char *)(puVar5 + 1) = (char)arg0_01;
      *(char *)((int)puVar5 + 3) = (char)arg1_00;
      if (*puVar4 == 3) {
        *puVar4 = 2;
      }
      uVar2 = uVar2 + 1 & 3;
      puVar4 = puVar4 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 4);
    *puVar5 = 1;
    arg0_00 = sub_080B3000(arg0_01,arg1_00);
    iVar3 = sub_080B3038(arg0_00,6);
    if (iVar3 == 0) {
      return;
    }
    uVar1 = *puVar5 | 0x8000;
  }
  *puVar5 = uVar1;
  return;
}


// sub_080AEDB4 @ 0x080AEDB4

void sub_080AEDB4(int arg0,int arg1,int arg2)

{
  ushort uVar1;
  undefined4 uVar2;
  uint arg0_00;
  int iVar3;
  uint uVar4;
  uint arg2_00;
  uint arg3;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_24;
  
  DAT_0200dfc8 = 0;
  DAT_0200dfca = 0;
  local_24 = 0;
  REG_DMA3SAD = &local_24;
  REG_DMA3DAD = 0x2005000;
  REG_DMA3CNT = 0x8500039c;
  uVar2 = REG_DMA3CNT;
  if (arg0 == 1) {
    arg1 = arg1 + 5;
    arg2 = arg2 + -0xd;
  }
  else if (arg0 == 0) {
    arg1 = arg1 + -0xd;
    arg2 = arg2 + -5;
  }
  else if (arg0 == 2) {
    arg1 = arg1 + 0xd;
    arg2 = arg2 + 5;
  }
  else if (arg0 == 3) {
    arg1 = arg1 + -5;
    arg2 = arg2 + 0xd;
  }
  arg3 = 0;
  do {
    arg2_00 = 0;
    do {
      if (arg0 == 1) {
        arg0_00 = (arg1 - arg3) + (uint)DAT_0200dfcc & 0xffff;
        uVar4 = arg2_00 + arg2;
LAB_080aee7e:
        sub_080AECD4(arg0_00,uVar4 & 0xffff,arg2_00,arg3);
      }
      else {
        if (arg0 == 0) {
          arg0_00 = arg2_00 + arg1 & 0xffff;
          uVar4 = (arg3 + arg2) - (uint)DAT_0200dfcc;
          goto LAB_080aee7e;
        }
        if (arg0 == 2) {
          arg0_00 = arg1 - arg2_00 & 0xffff;
          uVar4 = (arg2 - arg3) + (uint)DAT_0200dfcc;
          goto LAB_080aee7e;
        }
        if (arg0 == 3) {
          sub_080AECD4((arg3 + arg1) - (uint)DAT_0200dfcc & 0xffff,arg2 - arg2_00 & 0xffff,arg2_00,
                       arg3);
        }
      }
      arg2_00 = arg2_00 + 1 & 0xffff;
    } while (arg2_00 < 0x1c);
    arg3 = arg3 + 1 & 0xffff;
  } while (arg3 < 0xb);
  if (arg0 == 1) {
    if (0xb < DAT_0300456a) {
      iVar3 = (int)(((uint)DAT_0200dfcc + arg1) * 0x10000) >> 0x10;
      if (8 < iVar3) {
        DAT_0200dfc8 = 1;
      }
      if (iVar3 < (int)(DAT_0300456a + 1)) {
        DAT_0200dfca = 1;
      }
    }
    goto LAB_080aef8a;
  }
  if (arg0 == 0) {
    if (DAT_0300456c < 0xc) goto LAB_080aef8a;
    iVar3 = arg2 - (uint)DAT_0200dfcc;
    uVar1 = DAT_0300456c;
LAB_080aef70:
    iVar3 = iVar3 * 0x10000 >> 0x10;
    if (iVar3 < (int)(uVar1 - 9)) {
      DAT_0200dfc8 = 1;
    }
    if (iVar3 < -1) goto LAB_080aef8a;
  }
  else {
    if (arg0 != 2) {
      if ((arg0 != 3) || (DAT_0300456a < 0xc)) goto LAB_080aef8a;
      iVar3 = arg1 - (uint)DAT_0200dfcc;
      uVar1 = DAT_0300456a;
      goto LAB_080aef70;
    }
    if (DAT_0300456c < 0xc) goto LAB_080aef8a;
    iVar3 = (int)(((uint)DAT_0200dfcc + arg2) * 0x10000) >> 0x10;
    if (8 < iVar3) {
      DAT_0200dfc8 = 1;
    }
    if ((int)(DAT_0300456c + 1) <= iVar3) goto LAB_080aef8a;
  }
  DAT_0200dfca = 1;
LAB_080aef8a:
                    /* WARNING: Could not recover jumptable at 0x080aef98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AEFAC @ 0x080AEFAC

void sub_080AEFAC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x81b28b8;
  REG_DMA3DAD = 0x6011500;
  REG_DMA3CNT = 0x84000100;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080AEFD0 @ 0x080AEFD0

void sub_080AEFD0(void)

{
  Field_SetState(0x16);
  DAT_0300456e = 0;
  sub_080C7234();
  sub_080C7430();
  DisplayList_Add(0x80aefad,1);
  return;
}


// sub_080AEFFC @ 0x080AEFFC

void sub_080AEFFC(void)

{
  sub_080C2230(0);
  sub_080AEFD0();
  DAT_03004594 = 0;
  return;
}


// sub_080AF018 @ 0x080AF018

void sub_080AF018(void)

{
  sub_080C2230(0);
  sub_080AEFD0();
  DAT_03004594 = 1;
  return;
}


// sub_080AF034 @ 0x080AF034

void sub_080AF034(void)

{
  DAT_03003bb8 = 0;
  sub_080B628C();
  return;
}


// sub_080AF048 @ 0x080AF048

void sub_080AF048(void)

{
  Field_SetState(0x14);
  DAT_0300456e = 0;
  return;
}


// sub_080AF060 @ 0x080AF060

void sub_080AF060(dword arg0)

{
  int iVar1;
  
  if (arg0 == 0x8072766) {
    iVar1 = sub_080C2340(0x100);
    if (iVar1 == 0) {
      sub_080C2364(0x100);
    }
    else {
      arg0 = 0x8072b3a;
    }
  }
  if (arg0 == 0) {
    sub_0813E184(0x815f2ee,0);
  }
  else {
    sub_0813E184(arg0,0);
  }
  return;
}


// sub_080AF0AC @ 0x080AF0AC

undefined4 sub_080AF0AC(dword arg0)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080B2EFC(0,0);
  uVar1 = sub_080B3038(uVar1,0x23);
  iVar2 = sub_080B721C(uVar1);
  if (iVar2 == 0) {
    if ((arg0 == 0x8072766) && (iVar2 = sub_080C2340(0x100), iVar2 != 0)) {
      arg0 = 0x8072b3a;
    }
    if (arg0 == 0x80775a6) {
      iVar5 = 0;
      iVar2 = 4;
      do {
        iVar3 = sub_080C09B0(iVar2);
        if (iVar3 != 0) {
          iVar5 = iVar5 + 1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x10);
      if (((iVar5 != 0) && (iVar2 = sub_0814E8B0(), iVar2 != 0)) &&
         (iVar2 = sub_080C2340(0xca), iVar2 == 0)) {
        sub_080C2364(0xca);
        uVar4 = sub_080C2244();
        if ((uVar4 & 0xff) < 8) {
          iVar2 = 2;
          goto LAB_080af172;
        }
      }
    }
    else if (((arg0 != 0x8052210) || (uVar4 = sub_080C2244(), (uVar4 & 1) == 0)) &&
            ((arg0 != 0x80522f8 || (uVar4 = sub_080C2244(), (uVar4 & 3) == 0)))) {
      if (arg0 != 0) {
        uVar1 = ScriptVM_RunAlt(arg0);
        iVar2 = (int)(short)uVar1;
        goto LAB_080af172;
      }
      goto LAB_080af170;
    }
    iVar2 = 0;
  }
  else {
LAB_080af170:
    iVar2 = 1;
  }
LAB_080af172:
                    /* WARNING: Could not recover jumptable at 0x080af176. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(iVar2);
  return uVar1;
}


// sub_080AF178 @ 0x080AF178

void sub_080AF178(uint arg0,undefined4 arg1)

{
  uint uVar1;
  uint local_14;
  
  uVar1 = sub_0813EB78();
  local_14 = uVar1 & 0xffff;
  if (local_14 == 0) {
    DAT_03003bb8 = local_14;
    DAT_03004530 = arg0 & 0xffff;
    CpuSet(&local_14,0x2036094,0x5000008);
    DAT_0203db7a = (undefined2)uVar1;
    sub_080AF060(arg1);
    Field_SetState(0x19);
  }
  return;
}


// sub_080AF1D0 @ 0x080AF1D0

void sub_080AF1D0(uint arg0)

{
  undefined4 in_r1;
  
  DAT_03003bb8 = 0;
  sub_080B6308(arg0 & 0xffff,in_r1);
  return;
}


// sub_080AF1E8 @ 0x080AF1E8

void sub_080AF1E8(uint arg0,undefined4 arg1)

{
  DAT_03004530 = arg0 & 0xffff;
  DAT_03003bb8 = 0;
  DAT_0203db7a = 0;
  sub_080AF060(arg1);
  Field_SetState(0x19);
  return;
}


// sub_080AF218 @ 0x080AF218

void sub_080AF218(uint arg0,undefined4 arg1)

{
  DAT_03004530 = arg0 & 0xffff;
  DAT_03003bb8 = 0;
  DAT_0203db7a = 1;
  sub_080AF060(arg1);
  Field_SetState(0x19);
  return;
}


// sub_080AF24C @ 0x080AF24C

void sub_080AF24C(uint arg0,undefined4 arg1)

{
  DAT_03004530 = arg0 & 0xffff;
  DAT_03003bb8 = 0;
  DAT_0203db7a = 2;
  sub_080AF060(arg1);
  Field_SetState(0x19);
  return;
}


// sub_080AF280 @ 0x080AF280

void sub_080AF280(void)

{
  undefined4 local_c;
  
  local_c = 0;
  CpuSet(&local_c,0x2036094,0x5000008);
  DAT_0203db7a = 0;
  sub_080AF060(DAT_0300453c);
  Field_SetState(0x19);
  return;
}


// sub_080AF2BC @ 0x080AF2BC

undefined4 sub_080AF2BC(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = sub_080B3078(0,0,0x13);
  if ((iVar1 == 1) || (iVar1 = sub_080B3078(0,0,0x1e), iVar1 == 1)) {
    uVar2 = 1;
  }
  return uVar2;
}


// sub_080AF2E8 @ 0x080AF2E8

void sub_080AF2E8(void)

{
  sub_080C23BC(0x101);
  Field_SetState(1);
  return;
}


// sub_080AF300 @ 0x080AF300

void sub_080AF300(void)

{
  uint uVar1;
  int iVar2;
  
  sub_080C3818(1);
  uVar1 = sub_080AD608();
  sub_080C5170(uVar1 & 0xffff);
  sub_080AE234();
  sub_080AE574((uint)DAT_03004552,0);
  iVar2 = sub_080B098C();
  if (iVar2 == 1) goto LAB_080af332;
  iVar2 = sub_080B0248(0,0,0);
  if (((iVar2 == 1) && (iVar2 = sub_080B0248(1,0,0), iVar2 == 1)) &&
     (iVar2 = sub_080B0248(3,0,0), iVar2 == 1)) {
    iVar2 = sub_080C2340(0x101);
  }
  else {
    iVar2 = sub_080B0248(0,0,0);
    if (iVar2 == 3) {
      iVar2 = sub_080AF2BC();
      if ((iVar2 != 1) || (iVar2 = sub_080B78DC(), iVar2 != 0)) goto LAB_080af332;
      iVar2 = sub_080C2340(0x101);
    }
    else {
      iVar2 = sub_080B0248(0,0,0);
      if ((iVar2 != 2) || (iVar2 = sub_080B78DC(), iVar2 != 0)) {
        sub_080AF2E8();
        return;
      }
      iVar2 = sub_080AF2BC();
      if (iVar2 != 1) goto LAB_080af332;
      iVar2 = sub_080C2340(0x101);
    }
  }
  if (iVar2 == 0) {
    sub_080AD0FC(0x816499c,0xffff);
    Field_SetState(0x1a);
    return;
  }
LAB_080af332:
  sub_080AF2E8();
  return;
}


// sub_080AF3FC @ 0x080AF3FC

void sub_080AF3FC(void)

{
  int iVar1;
  
  DAT_0203db6a = 0;
  if (DAT_03003bb8 == 1) {
    iVar1 = sub_080E54D4();
    if (iVar1 == 0) {
      sub_080C3818(1);
      iVar1 = sub_080B78A4();
      if (iVar1 == 0) {
        Field_SetState(0x1d);
      }
      else {
        Field_SetState(10);
      }
      DAT_0300456e = 0;
    }
    else {
      Field_SetState(DAT_03004530 & 0xffff);
    }
  }
  else if (DAT_03004530 == 0x19) {
    DAT_03004530 = 1;
    sub_080AF300();
  }
  else {
    Field_SetState(DAT_03004530 & 0xffff);
    if (DAT_03004530 == 0xc) {
      if ((DAT_0200ab04 & 0x8000) == 0) {
        sub_080AF300();
      }
      else {
        sub_080B0820();
        DAT_0300456e = DAT_0300456e + 1;
        DAT_0300460c = 0;
      }
    }
  }
  return;
}


// sub_080AF4B8 @ 0x080AF4B8

void sub_080AF4B8(uint arg0,uint arg1)

{
  (&DAT_03005848)[((arg0 & 0xffff) >> 3) + (arg1 & 0xffff) * 0x10] =
       (byte)(1 << (arg0 & 7)) | (&DAT_03005848)[((arg0 & 0xffff) >> 3) + (arg1 & 0xffff) * 0x10];
  return;
}


// sub_080AF4EC @ 0x080AF4EC

void sub_080AF4EC(uint arg0,uint arg1)

{
  int iVar1;
  uint arg1_00;
  uint arg2;
  
  iVar1 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  arg1_00 = (arg0 & 0xffff) + (uint)*(ushort *)(iVar1 + 8) & 0xffff;
  arg2 = (arg1 & 0xffff) + (uint)*(ushort *)(iVar1 + 10) & 0xffff;
  iVar1 = sub_080B7944(iVar1,arg1_00,arg2);
  if (iVar1 != 0) {
    sub_080AF4B8(arg1_00,arg2);
  }
  return;
}


// sub_080AF538 @ 0x080AF538

void sub_080AF538(uint arg0,uint arg1)

{
  (&DAT_03005848)[((arg0 & 0xffff) >> 3) + (arg1 & 0xffff) * 0x10] =
       (&DAT_03005848)[((arg0 & 0xffff) >> 3) + (arg1 & 0xffff) * 0x10] & ~(byte)(1 << (arg0 & 7));
  return;
}


// sub_080AF56C @ 0x080AF56C

void sub_080AF56C(uint arg0,uint arg1)

{
  int iVar1;
  uint arg1_00;
  uint arg2;
  
  iVar1 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  arg1_00 = (arg0 & 0xffff) + (uint)*(ushort *)(iVar1 + 8) & 0xffff;
  arg2 = (arg1 & 0xffff) + (uint)*(ushort *)(iVar1 + 10) & 0xffff;
  iVar1 = sub_080B7944(iVar1,arg1_00,arg2);
  if (iVar1 != 0) {
    sub_080AF538(arg1_00,arg2);
  }
  return;
}


// sub_080AF5B8 @ 0x080AF5B8

void sub_080AF5B8(uint arg0,uint arg1,undefined4 arg2)

{
  uint uVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = arg0 & 0xffff;
  uVar1 = arg1 & 0xffff;
  if ((ushort)arg2 == 1) {
    uVar2 = uVar2 - 1;
LAB_080af5f2:
    uVar2 = uVar2 & 0xffff;
  }
  else {
    if ((ushort)arg2 < 2) {
      if ((ushort)arg2 != 0) goto LAB_080af5f6;
      uVar1 = uVar1 + 1;
    }
    else {
      if ((ushort)arg2 != 2) {
        if ((ushort)arg2 != 3) goto LAB_080af5f6;
        uVar2 = uVar2 + 1;
        goto LAB_080af5f2;
      }
      uVar1 = uVar1 - 1;
    }
    uVar1 = uVar1 & 0xffff;
  }
LAB_080af5f6:
  if ((((-1 < (int)(uVar2 * 0x10000)) && (-1 < (int)(uVar1 * 0x10000))) && (uVar2 < DAT_0300456a))
     && (uVar1 < DAT_0300456c)) {
    sub_080AF4EC(uVar2,uVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x080af618. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AF620 @ 0x080AF620

uint sub_080AF620(undefined4 arg0,uint arg1)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  
  iVar1 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  uVar2 = (short)arg0 + *(short *)(iVar1 + 8);
  uVar3 = (arg1 & 0xffff) + (uint)*(ushort *)(iVar1 + 10) & 0xffff;
  iVar1 = sub_080B7944(iVar1,(uint)uVar2,uVar3);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)(byte)(&DAT_03005848)[(uint)(uVar2 >> 3) + uVar3 * 0x10] & 1 << (uVar2 & 7);
  }
  return uVar3;
}


// sub_080AF68C @ 0x080AF68C

uint sub_080AF68C(undefined4 arg0,uint arg1)

{
  int iVar1;
  ushort uVar2;
  
  iVar1 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  uVar2 = (short)arg0 + *(short *)(iVar1 + 8);
  return (uint)(byte)(&DAT_03005848)
                     [(uint)(uVar2 >> 3) +
                      ((arg1 & 0xffff) + (uint)*(ushort *)(iVar1 + 10) & 0xffff) * 0x10] &
         1 << (uVar2 & 7);
}


// sub_080AF6E4 @ 0x080AF6E4

void sub_080AF6E4(undefined4 arg0,undefined4 arg1)

{
  DAT_03004538 = arg0;
  DAT_03004000 = arg1;
  return;
}


// sub_080AF6F8 @ 0x080AF6F8

void sub_080AF6F8(undefined4 arg0,int arg1,int arg2)

{
  undefined4 arg1_00;
  
  arg1_00 = *(undefined4 *)(arg1 + 4);
  sub_080AF6E4(arg0,arg1);
  DAT_0300456e = 0;
  if (arg2 == 0) {
    sub_080AF178(0xc,arg1_00);
  }
  else {
    sub_080AF1D0(0xc);
  }
  return;
}


// sub_080AF72C @ 0x080AF72C

void sub_080AF72C(int arg0)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  ushort uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_080B2EFC(0,0);
  iVar3 = sub_080B3038(uVar2,0x24);
  if (iVar3 != 0) {
    uVar4 = *(ushort *)(arg0 + 8);
    if ((((((uVar4 & 0xf000) != 0) && (DAT_03004552 == 0)) ||
         (((uVar4 & 0xf00) != 0 && (DAT_03004552 == 1)))) ||
        (((uVar4 & 0xf0) != 0 && (DAT_03004552 == 2)))) ||
       (((uVar4 & 0xf) != 0 && (DAT_03004552 == 3)))) {
      uVar2 = 2;
      goto LAB_080af7de;
    }
    if (DAT_03004562 == DAT_03004566) {
      if (DAT_03004564 < DAT_03004568) {
        uVar4 = *(ushort *)(iVar3 + 2);
        uVar1 = 0x1000;
      }
      else {
        if (DAT_03004564 <= DAT_03004568) goto LAB_080af7b6;
        uVar4 = *(ushort *)(iVar3 + 2);
        uVar1 = 0x10;
      }
    }
    else {
LAB_080af7b6:
      if ((DAT_03004562 < DAT_03004566) && (DAT_03004564 == DAT_03004568)) {
        uVar4 = *(ushort *)(iVar3 + 2);
        uVar1 = 1;
      }
      else {
        if ((DAT_03004562 <= DAT_03004566) || (DAT_03004564 != DAT_03004568)) goto LAB_080af7dc;
        uVar4 = *(ushort *)(iVar3 + 2);
        uVar1 = 0x100;
      }
    }
    if ((uVar1 & uVar4) != 0) {
      uVar2 = 0;
      goto LAB_080af7de;
    }
  }
LAB_080af7dc:
  uVar2 = 1;
LAB_080af7de:
                    /* WARNING: Could not recover jumptable at 0x080af7e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}


// sub_080AF7E8 @ 0x080AF7E8

void sub_080AF7E8(undefined4 arg0,undefined4 arg1,int arg2)

{
  int iVar1;
  ushort local_1c [2];
  
  iVar1 = sub_080C9084((uint)DAT_03004562,(uint)DAT_03004564,(uint)DAT_03004552,local_1c);
  sub_080AF6E4(arg0,arg1);
  DAT_0300456e = 0;
  if (arg2 == 0) {
    sub_080AF178(0xc,*(undefined4 *)(iVar1 + 4));
  }
  else {
    sub_080AF1D0(0xc);
  }
  if (local_1c[0] != 0xffff) {
    sub_080C24B8((uint)local_1c[0]);
  }
  DAT_0300458e = 1;
  return;
}


// sub_080AF85C @ 0x080AF85C

dword sub_080AF85C(undefined4 arg0,undefined4 arg1)

{
  dword unaff_r4;
  
  switch(arg0) {
  case 0x30:
    unaff_r4 = 0x8073ad0;
    break;
  case 0x31:
    unaff_r4 = 0x8073ab2;
    break;
  case 0x32:
    unaff_r4 = 0x8073abc;
    break;
  case 0x33:
    unaff_r4 = 0x8073ac6;
    break;
  case 0x34:
    unaff_r4 = 0x8073aa8;
  }
  sub_080AF6E4(arg1,arg1);
  DAT_0300456e = 0;
  sub_080AF178(0xc,unaff_r4);
  return unaff_r4;
}


// sub_080AF8D0 @ 0x080AF8D0

undefined4 sub_080AF8D0(uint arg0,uint arg1,uint arg2)

{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  int arg1_00;
  int arg0_00;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  undefined2 *puVar11;
  dword arg1_01;
  undefined4 arg0_01;
  code *UNRECOVERED_JUMPTABLE;
  ushort auStack_90 [2];
  uint local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  uVar2 = arg0 & 0xffff;
  uVar10 = arg1 & 0xffff;
  local_8c = arg2 & 0xffff;
  uVar3 = sub_080B2EFC(0,0);
  local_88 = sub_080B3038(uVar3,4);
  local_84 = sub_080B3038(uVar3,0x15);
  local_80 = sub_080B3038(uVar3,1);
  local_7c = sub_080B3038(uVar3,2);
  local_78 = sub_080B3038(uVar3,0x1b);
  local_74 = sub_080B3038(uVar3,0x1c);
  local_70 = sub_080B3038(uVar3,0x10);
  arg1_00 = sub_080B3038(uVar3,0x13);
  local_6c = sub_080B3038(uVar3,0x1d);
  local_68 = sub_080B3038(uVar3,0x1e);
  local_64 = sub_080B3038(uVar3,3);
  local_60 = sub_080B3038(uVar3,9);
  local_5c = sub_080B3038(uVar3,8);
  local_58 = sub_080B3038(uVar3,0x19);
  local_54 = sub_080B3038(uVar3,5);
  local_50 = sub_080B3038(uVar3,0xb);
  local_4c = sub_080B3038(uVar3,0xc);
  local_48 = sub_080B3038(uVar3,0xd);
  local_44 = sub_080B3038(uVar3,0xe);
  local_40 = sub_080B3038(uVar3,0xf);
  local_3c = sub_080B3038(uVar3,0x25);
  local_38 = sub_080B3038(uVar3,0x26);
  local_34 = sub_080B3038(uVar3,0x27);
  arg0_00 = sub_080C9084((uint)DAT_03004562,(uint)DAT_03004564,(uint)DAT_03004552,auStack_90);
  local_30 = sub_080B3038(uVar3,0x14);
  iVar4 = sub_080B3038(uVar3,0x1f);
  iVar5 = sub_080B3038(uVar3,0x16);
  local_2c = sub_080B3038(uVar3,0x17);
  local_28 = sub_080B3038(uVar3,0x18);
  local_24 = sub_080B3038(uVar3,0x1a);
  DAT_03004538 = 0;
  if (DAT_03003ff4 != 1) goto LAB_080b0102;
  if ((iVar4 != 0) && (iVar6 = sub_080C57CC((uint)*(ushort *)(iVar4 + 4)), iVar6 == 1)) {
    if (uVar2 == 1) {
      if (uVar10 == 1) {
LAB_080b0080:
        DAT_03003fec = sub_080B8994(iVar4);
        goto LAB_080b0102;
      }
      if (uVar10 == 2) {
        sub_080AF6E4(uVar3,iVar4);
LAB_080b00da:
        DAT_03003fec = sub_080B8994(iVar4);
        Field_SetState(0x1a);
        goto LAB_080b0102;
      }
    }
joined_r0x080afa7a:
    if ((uVar2 != 2) || (uVar10 != 2)) goto LAB_080b0102;
LAB_080b00a0:
    sub_080AF6E4(uVar3,iVar4);
    DAT_0300456e = 0;
    Field_SetState(0x20);
    *(undefined4 *)(DAT_03003fec + 0xc) = 1;
    goto LAB_080b0102;
  }
  if (local_88 != 0) {
    sub_080AF6E4(uVar3,local_88);
    Field_SetState(0xb);
    DAT_0300456e = 0;
    goto LAB_080b0102;
  }
  if (local_84 != 0) {
    sub_080AF6E4(uVar3,local_84);
    Field_SetState(0xc);
    DAT_0300456e = (short)local_88;
    puVar11 = (undefined2 *)0x3004534;
    iVar5 = local_84;
LAB_080afe6c:
    *puVar11 = *(undefined2 *)(iVar5 + 2);
    goto LAB_080b0102;
  }
  if ((local_80 != 0) && (*(short *)(local_80 + 2) != 0)) {
    sub_080AF6E4(uVar3,local_80);
    Field_SetState(0xd);
    DAT_0300456e = (short)local_84;
    DAT_03004534 = *(undefined2 *)(local_80 + 2);
    piVar7 = (int *)0x3003b98;
    iVar5 = local_84;
LAB_080b0100:
    *piVar7 = iVar5;
    goto LAB_080b0102;
  }
  if ((local_78 == 0) || (arg1_00 != 0)) {
    if (local_7c != 0) {
      if (*(short *)(local_7c + 2) == 0) {
        sub_080AF6E4(uVar3,local_7c);
        sub_080B5FD8();
      }
      else {
        sub_080AF6E4(uVar3,local_7c);
        Field_SetState(0xe);
        DAT_0300456e = 0;
        DAT_03004534 = *(undefined2 *)(local_7c + 2);
        DAT_03003b98 = 0;
      }
      goto LAB_080b0102;
    }
    if ((local_74 == 0) || (arg1_00 != 0)) {
      if (local_70 != 0) {
        sub_080AF6E4(uVar3,local_70);
        DAT_0300456e = 0;
        arg1_01 = 0x805a65e;
LAB_080b005e:
        sub_080AF178(0xc,arg1_01);
        goto LAB_080b0102;
      }
      if (arg1_00 != 0) {
        uVar8 = sub_080AF0AC(*(undefined4 *)(arg1_00 + 4));
        if (((int)(short)uVar8 == uVar2) ||
           (uVar8 = sub_080AF0AC(*(undefined4 *)(arg1_00 + 4)), (int)(short)uVar8 == uVar10)) {
          sub_080AF6E4(uVar3,arg1_00);
          DAT_0300456e = (short)local_70;
          if (local_8c == 0) {
            iVar5 = sub_080B3078(0,0,0x28);
            if (iVar5 == 1) {
              sub_080AF1D0(0xc);
            }
            else {
              sub_080AF178(0xc,*(undefined4 *)(arg1_00 + 4));
            }
          }
          else {
            sub_080AF1D0(0xc);
          }
          if (local_24 != 0) {
            sub_080B011C((uint)*(ushort *)(local_24 + 2));
          }
        }
        goto LAB_080b0102;
      }
      if ((local_6c != 0) && (sVar1 = *(short *)(local_6c + 2), sVar1 == 0)) {
        uVar9 = sub_080B6170();
        uVar9 = uVar9 & 0xffff;
        if (uVar9 == 0xffff) {
          uVar9 = (uint)DAT_03004552;
        }
        iVar5 = *(int *)(local_6c + 4 + uVar9 * 4);
        if ((iVar5 != 0) &&
           ((uVar8 = sub_080AF0AC(iVar5), (int)(short)uVar8 == uVar2 ||
            (uVar8 = sub_080AF0AC(iVar5), (int)(short)uVar8 == uVar10)))) {
          sub_080AF6E4(uVar3,local_6c);
          DAT_0300456e = sVar1;
          if (local_8c == 0) {
            sub_080AF178(0xc,iVar5);
          }
          else {
            sub_080AF1D0(0xc);
          }
          if (local_24 != 0) {
            sub_080B011C((uint)*(ushort *)(local_24 + 2));
          }
        }
        goto LAB_080b0102;
      }
      if (local_68 != 0) {
        iVar5 = sub_080C06BC(0);
        arg0_01 = *(undefined4 *)(local_68 + 4 + iVar5 * 4);
        uVar8 = sub_080AF0AC(arg0_01);
        if (((int)(short)uVar8 == uVar2) ||
           (uVar8 = sub_080AF0AC(arg0_01), (int)(short)uVar8 == uVar10)) {
          sub_080AF6E4(uVar3,local_68);
          DAT_0300456e = 0;
          if (local_8c == 0) {
            sub_080AF178(0xc,arg0_01);
          }
          else {
            sub_080AF1D0(0xc);
          }
        }
        goto LAB_080b0102;
      }
      if (arg0_00 != 0) {
        if ((*(dword *)(arg0_00 + 4) == 0x8073a00) && (iVar5 = sub_080B098C(), iVar5 == 0)) {
          iVar5 = sub_080C9100();
          if (iVar5 != 0) {
            sub_080AF85C(iVar5,arg0_00);
          }
        }
        else {
          uVar3 = sub_080AF0AC(*(undefined4 *)(arg0_00 + 4));
          if ((((int)(short)uVar3 == uVar2) ||
              (uVar3 = sub_080AF0AC(*(undefined4 *)(arg0_00 + 4)), (int)(short)uVar3 == uVar10)) &&
             ((auStack_90[0] != 0xffff && (iVar5 = sub_080C2480((uint)auStack_90[0]), iVar5 != 1))))
          {
            sub_080AF7E8(arg0_00,arg0_00,0);
          }
        }
        goto LAB_080b0102;
      }
      if ((iVar5 == 0) || (*(int *)(iVar5 + 4) == 0)) {
        if ((local_2c == 0) || (*(int *)(local_2c + 4) == 0)) {
          if ((local_28 == 0) || (*(int *)(local_28 + 4) == 0)) {
            if (local_64 != 0) {
              sub_080AF6E4(uVar3,local_64);
              sub_080BA070();
              puVar11 = (undefined2 *)0x3003b9c;
              iVar5 = local_64;
              goto LAB_080afe6c;
            }
            if (local_60 != 0) {
              sub_080AF6E4(uVar3,local_60);
              sub_080B5E50();
              goto LAB_080b0102;
            }
            if ((local_5c != 0) &&
               ((*(short *)(local_5c + 2) == 0 ||
                (*(ushort *)(local_5c + 2) - 1 != (uint)DAT_03004552)))) {
              sub_080AF6E4(uVar3,local_5c);
              sub_080B614C();
              goto LAB_080b0102;
            }
            if (local_58 != 0) {
              if (((uVar2 - 1 & 0xffff) < 2) && (uVar10 == 2)) {
                DAT_0300458a = 0;
                DAT_03004588 = 0x40;
                DAT_0300458c = 0;
                sub_080B1C18(0x40);
                sub_080AF6E4(uVar3,local_58);
              }
              goto LAB_080b0102;
            }
            if (local_54 != 0) {
              uVar9 = sub_080F3F44();
              if ((uVar9 & 0x50) != 0) goto LAB_080b0102;
              iVar4 = local_54;
              if (uVar2 == 1) {
                if (uVar10 == 2) {
                  sub_080AF6E4(uVar3,local_54);
                  sub_080B8FF0(local_54,0);
                  Field_SetState(0x20);
                  goto LAB_080b0102;
                }
                if (uVar10 == 1) {
                  iVar5 = local_54;
                  sub_080B8FF0(local_54,1);
                  DAT_03003fec = iVar5;
                  goto LAB_080b0102;
                }
              }
              goto joined_r0x080afa7a;
            }
            if (local_50 == 0) {
              if (local_4c == 0) {
                if (local_48 == 0) {
                  if (local_44 == 0) {
                    if (local_40 == 0) {
                      if (local_3c == 0) {
                        if (local_38 == 0) {
                          if (local_34 == 0) {
                            if (local_30 == 0) {
                              if (local_24 == 0) goto LAB_080b0102;
                              sub_080B011C((uint)*(ushort *)(local_24 + 2));
                              piVar7 = (int *)0x3004538;
                              iVar5 = local_30;
                              goto LAB_080b0100;
                            }
                            iVar4 = local_30;
                            if ((uVar2 == 1) && (uVar10 == 1)) goto LAB_080b0080;
                            if ((uVar2 != 2) || (uVar10 != 2)) {
                              if ((uVar2 != 1) || (uVar10 != 2)) goto LAB_080b0102;
                              sub_080AF6E4(uVar3,local_30);
                              iVar4 = local_30;
                              goto LAB_080b00da;
                            }
                            goto LAB_080b00a0;
                          }
                          sub_080AF6E4(uVar3,local_34);
                          DAT_0300456e = (short)local_38;
                          iVar5 = local_34;
                        }
                        else {
                          sub_080AF6E4(uVar3,local_38);
                          DAT_0300456e = (short)local_3c;
                          iVar5 = local_38;
                        }
                      }
                      else {
                        sub_080AF6E4(uVar3,local_3c);
                        DAT_0300456e = (short)local_40;
                        iVar5 = local_3c;
                      }
                    }
                    else {
                      sub_080AF6E4(uVar3,local_40);
                      DAT_0300456e = (short)local_44;
                      iVar5 = local_40;
                    }
                  }
                  else {
                    sub_080AF6E4(uVar3,local_44);
                    DAT_0300456e = (short)local_48;
                    iVar5 = local_44;
                  }
                }
                else {
                  sub_080AF6E4(uVar3,local_48);
                  DAT_0300456e = (short)local_4c;
                  iVar5 = local_48;
                }
                arg1_01 = *(dword *)(iVar5 + 4);
              }
              else {
                if (*(int *)(local_4c + 4) == 0) goto LAB_080b0102;
                sub_080AF6E4(uVar3,local_4c);
                DAT_0300456e = (short)local_50;
                arg1_01 = *(dword *)(local_4c + 4);
              }
            }
            else {
              sub_080AF6E4(uVar3,local_50);
              DAT_0300456e = (short)local_54;
              arg1_01 = *(dword *)(local_50 + 4);
            }
            goto LAB_080b005e;
          }
          uVar8 = sub_080AF0AC(*(int *)(local_28 + 4));
          iVar5 = local_28;
          if ((int)(short)uVar8 != uVar2) {
            uVar8 = sub_080AF0AC(*(undefined4 *)(local_28 + 4));
            sVar1 = (short)uVar8;
            iVar5 = local_28;
            goto joined_r0x080afe46;
          }
        }
        else {
          uVar8 = sub_080AF0AC(*(int *)(local_2c + 4));
          iVar5 = local_2c;
          if ((int)(short)uVar8 != uVar2) {
            uVar8 = sub_080AF0AC(*(undefined4 *)(local_2c + 4));
            sVar1 = (short)uVar8;
            iVar5 = local_2c;
            goto joined_r0x080afe46;
          }
        }
      }
      else {
        uVar8 = sub_080AF0AC(*(int *)(iVar5 + 4));
        if ((int)(short)uVar8 != uVar2) {
          uVar8 = sub_080AF0AC(*(undefined4 *)(iVar5 + 4));
          sVar1 = (short)uVar8;
joined_r0x080afe46:
          if ((int)sVar1 != uVar10) goto LAB_080b0102;
        }
      }
      sub_080AF6F8(uVar3,iVar5,local_8c);
      goto LAB_080b0102;
    }
    sub_080AF6E4(uVar3,local_74);
    Field_SetState(0x22);
    iVar5 = local_74;
  }
  else {
    sub_080AF6E4(uVar3,local_78);
    Field_SetState(0x21);
    iVar5 = local_78;
  }
  DAT_03004534 = *(undefined2 *)(iVar5 + 2);
  DAT_03003b98 = arg1_00;
  DAT_0300456e = (short)arg1_00;
LAB_080b0102:
                    /* WARNING: Could not recover jumptable at 0x080b0114. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(DAT_03004538);
  return uVar3;
}


// sub_080B011C @ 0x080B011C

void sub_080B011C(undefined4 arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if ((ushort)arg0 == 1) {
    sub_080C23BC(0xed);
  }
  else if ((ushort)arg0 < 2) {
    if ((ushort)arg0 == 0) {
      sub_080C2364(0xec);
    }
  }
  else if ((ushort)arg0 == 2) {
    sub_080C2364(0x101);
  }
                    /* WARNING: Could not recover jumptable at 0x080b0150. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B0158 @ 0x080B0158

void sub_080B0158(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = sub_080ADF40();
  if (iVar2 == 0) {
    REG_DMA3SAD = DAT_03003b94;
    REG_DMA3DAD = 0x6004000;
    REG_DMA3CNT = 0x84000800;
    uVar1 = REG_DMA3CNT;
  }
  sub_080B2880();
  return;
}


// sub_080B018C @ 0x080B018C

void sub_080B018C(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = sub_080ADF40();
  if (iVar2 == 0) {
    REG_DMA3SAD = DAT_03003b94 + 0x2000;
    REG_DMA3DAD = 0x6004400;
    REG_DMA3CNT = 0x84000700;
    uVar1 = REG_DMA3CNT;
  }
  sub_080B2880();
  return;
}


// sub_080B01C8 @ 0x080B01C8

void sub_080B01C8(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = sub_080ADF40();
  if (iVar2 == 0) {
    REG_DMA3SAD = DAT_03003b94 + 0x3c00;
    REG_DMA3DAD = 0x6004400;
    REG_DMA3CNT = 0x84000700;
    uVar1 = REG_DMA3CNT;
  }
  sub_080B2880();
  return;
}


// sub_080B0204 @ 0x080B0204

undefined4 sub_080B0204(undefined4 arg0)

{
  short sVar1;
  
  sVar1 = DAT_0200ad5a;
  if ((ushort)arg0 != 1) {
    if ((ushort)arg0 < 2) {
      sVar1 = DAT_0200ad58;
      if ((ushort)arg0 != 0) {
        return 0;
      }
    }
    else {
      sVar1 = DAT_0200ad5c;
      if (((ushort)arg0 != 2) && (sVar1 = DAT_0200ad5e, (ushort)arg0 != 3)) {
        return 0;
      }
    }
  }
  if (sVar1 != 0) {
    return 0;
  }
  return 1;
}


// sub_080B0248 @ 0x080B0248

undefined4 sub_080B0248(undefined4 arg0,uint arg1,uint arg2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar3 = (arg2 & 0xffff) * 0x6c + 0x200ad54 + (arg1 & 0xffff) * 0xc;
  if ((ushort)arg0 == 1) {
    sVar1 = *(short *)(iVar3 + 6);
LAB_080b0294:
    if (sVar1 != 0) goto LAB_080b029a;
  }
  else {
    if (1 < (ushort)arg0) {
      if ((ushort)arg0 == 2) {
        sVar1 = *(short *)(iVar3 + 8);
      }
      else {
        if ((ushort)arg0 != 3) goto LAB_080b0298;
        sVar1 = *(short *)(iVar3 + 10);
      }
      goto LAB_080b0294;
    }
    if ((ushort)arg0 == 0) {
      sVar1 = *(short *)(iVar3 + 4);
      goto LAB_080b0294;
    }
  }
LAB_080b0298:
  sVar1 = 0;
LAB_080b029a:
                    /* WARNING: Could not recover jumptable at 0x080b029e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(sVar1);
  return uVar2;
}


// sub_080B02A0 @ 0x080B02A0

/* WARNING: Control flow encountered bad instruction data */

void sub_080B02A0(undefined4 *arg0)

{
  undefined4 unaff_r5;
  undefined4 unaff_r11;
  bool in_ZR;
  undefined4 in_cr0;
  
  if (in_ZR) {
    *arg0 = unaff_r11;
  }
  else {
    coprocessor_store(0xc,in_cr0,unaff_r5);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// sub_080B0350 @ 0x080B0350

undefined4 sub_080B0350(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = sub_080C1D9C();
  uVar2 = sub_080C1D9C();
  if ((uVar1 & 0xf0) == 0) {
    uVar1 = sub_080F3F44();
    if ((uVar1 & 0x100) != 0) {
      sub_080F3F58(0xfffffeff);
    }
  }
  else if ((uVar2 & 0xff) == 0x80) {
    uVar1 = sub_080F3F44();
    if ((uVar1 & 0x20) != 0) {
      sub_080F3F58(0xffffffdf);
    }
    uVar1 = sub_080F3F44();
    if ((uVar1 & 0x40) != 0) {
      sub_080F3F58(0xffffffbf);
    }
  }
  sub_080C1AB0();
  return 0;
}


// sub_080B03BC @ 0x080B03BC

void sub_080B03BC(uint arg0)

{
  uint uVar1;
  int iVar2;
  int arg0_00;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  ushort uStack_1c;
  ushort uStack_1a;
  
  uVar1 = sub_080C221C();
  iVar2 = sub_080C1B74(&uStack_1c,&uStack_1a);
  if (DAT_03003ff4 == 0) {
LAB_080b04a8:
    Field_SetState(arg0 & 0xffff);
  }
  else {
    arg0_00 = sub_080C1E20();
    sub_080C20EC();
    if (((arg0 & 0xffff) != 1) || (iVar3 = sub_080BE76C(), iVar3 != 1)) {
      if (arg0_00 == 0) {
        if (iVar2 == 0) {
          iVar2 = sub_080B0350();
          if ((iVar2 == 0) && (DAT_030045ac == 0)) {
            iVar2 = sub_080BEE24();
            if (iVar2 != 0) {
              uVar5 = 1;
              goto LAB_080b04b0;
            }
            iVar2 = sub_080C2280(0);
            if (iVar2 == 1) {
              iVar2 = sub_080B0248(0,0,1);
              uVar4 = sub_080B6170();
              if ((((uVar4 & 0xffff) != 0xffff) || (1 < iVar2 - 2U)) ||
                 (iVar2 = sub_080B2EFC(0,1), iVar2 == 0)) {
                sub_080AF034();
                uVar5 = 1;
                goto LAB_080b04b0;
              }
              sub_080C2230(uVar1 & 0xffff);
            }
            goto LAB_080b04a8;
          }
          sub_080B90F4();
        }
        else {
          sub_080BEC3C(iVar2,(uint)uStack_1c,(uint)uStack_1a);
        }
      }
      else {
        sub_080B9274(arg0_00);
      }
      Field_SetState(0x1a);
      uVar5 = 1;
      goto LAB_080b04b0;
    }
    DAT_03004550 = 0x1a;
  }
  uVar5 = 0;
LAB_080b04b0:
                    /* WARNING: Could not recover jumptable at 0x080b04ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar5);
  return;
}


