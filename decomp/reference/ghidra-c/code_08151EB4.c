/* Ghidra decompilation of asm/code_08151EB4.s (reference only; not compiled). */

// sub_08151EB4 @ 0x08151EB4

int sub_08151EB4(uint arg0)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = arg0 & 0xffff;
  if ((uVar2 == 2) && (iVar1 = sub_080C2340(0x11), iVar1 == 0)) {
    uVar2 = 10;
  }
  if ((uVar2 == 5) && (iVar1 = sub_080C2340(0xec), iVar1 == 0)) {
    uVar2 = 0xb;
  }
  return uVar2 * 0xd8 + 0x87de924;
}


// sub_08151EEC @ 0x08151EEC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08151EEC(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uStack_14;
  
  DAT_03004614 = 0;
  if ((ushort)arg2 == 1) goto LAB_08151fba;
  if ((ushort)arg2 < 2) {
    if ((ushort)arg2 != 0) goto LAB_08151fba;
  }
  else {
    if ((ushort)arg2 == 2) {
      DAT_030069fc = DAT_03006a00;
      DAT_030069fe = DAT_03006a02;
      goto LAB_08151fba;
    }
    if ((ushort)arg2 != 3) goto LAB_08151fba;
  }
  uStack_14 = 0;
  CpuSet(&uStack_14,0x30069f0,0x500000f);
  if ((ushort)arg2 == 3) {
    uVar1 = *(ushort *)((uint)(DAT_03003fd8 >> 4) * 2 + 0x87df93c);
    DAT_030069f8 = DAT_03003fd8 >> 4;
    if (uVar1 != 0xffff) {
      DAT_030069f8 = uVar1;
    }
    iVar2 = sub_08151EB4((uint)DAT_030069f8);
    uVar1 = DAT_03003fd4 - *(short *)(iVar2 + 0xcc);
    DAT_030069fe = (DAT_03003fd6 - *(short *)(iVar2 + 0xce)) * 0x10;
  }
  else {
    DAT_030069f8 = (ushort)DAT_03005f84._2_1_;
    uVar1 = (ushort)(byte)DAT_03005f80;
    DAT_030069fe = (ushort)DAT_03005f80._1_1_ << 4;
  }
  DAT_030069fc = uVar1 * 0x10 + 8;
  sub_0815251C(0);
LAB_08151fba:
  _DAT_030069f0 = 0;
  DAT_030069f4 = (ushort)arg2;
  sub_08152EF8();
  sub_08152420();
  return;
}


// sub_08151FD8 @ 0x08151FD8

dword sub_08151FD8(uint arg0)

{
  int iVar1;
  dword dVar2;
  int iVar3;
  
  iVar1 = sub_08151EB4((uint)DAT_030069f8);
  iVar3 = (arg0 & 0xffff) * 0x40;
  if (*(int *)(iVar1 + 0x24 + iVar3) == 0) {
    dVar2 = *(dword *)(iVar1 + 0x20 + iVar3);
  }
  else if ((arg0 & 0xffff) == 0) {
    dVar2 = 0x200f874;
  }
  else {
    dVar2 = 0x201f874;
  }
  return dVar2;
}


// sub_0815201C @ 0x0815201C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0815201C(void)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  dword dVar4;
  uint arg1;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  undefined4 arg2;
  uint local_2c;
  
  iVar3 = sub_08151EB4((uint)DAT_030069f8);
  switch(_DAT_030069f0) {
  case 0:
    dVar4 = 0x87dfba0;
    break;
  case 1:
    sub_08152F80();
    iVar5 = sub_081529E0();
    DAT_03006a16 = (ushort)(*(byte *)(iVar5 + 0x2000 +
                                     (uint)(DAT_030069fc >> 4) + (uint)(DAT_030069fe >> 4) * 0x40)
                           >> 4);
    goto switchD_08152042_caseD_e;
  case 2:
  case 0xd:
    sub_0815300C();
    goto switchD_08152042_caseD_e;
  case 3:
    dVar4 = 0x87dfef0;
    break;
  case 4:
    dVar4 = 0x87dff58;
    break;
  case 5:
    dVar4 = 0x87e0028;
    break;
  case 6:
    dVar4 = 0x87e0090;
    break;
  case 7:
    dVar4 = 0x87e0120;
    break;
  case 8:
    dVar4 = 0x87dffc0;
    break;
  case 9:
    dVar4 = 0x87e0998;
    break;
  case 10:
    dVar4 = 0x87e0da0;
    goto LAB_081520f6;
  case 0xb:
    dVar4 = 0x87e0f54;
LAB_081520f6:
    sub_080AD0FC(dVar4,0xffff);
    _DAT_030069f0 = 0x10;
    DAT_03006a26 = 1;
    goto switchD_08152042_caseD_e;
  case 0xc:
    dVar4 = 0x87e0dd0;
    break;
  default:
    goto switchD_08152042_caseD_e;
  }
  sub_080AD0FC(dVar4,0xffff);
  _DAT_030069f0 = 0x10;
switchD_08152042_caseD_e:
  local_2c = (uint)DAT_030069fc;
  if (0x78 < local_2c) {
    if ((int)(DAT_030069fc - 0x78) < (int)(*(ushort *)(iVar3 + 200) - 0xf0)) {
      local_2c = 0x78;
    }
    else {
      local_2c = (DAT_030069fc + 0xf0) - (uint)*(ushort *)(iVar3 + 200) & 0xffff;
    }
  }
  arg1 = (uint)DAT_030069fe;
  if (0x50 < arg1) {
    if ((int)(DAT_030069fe - 0x50) < (int)(*(ushort *)(iVar3 + 0xca) - 0xa0)) {
      arg1 = 0x50;
    }
    else {
      arg1 = (DAT_030069fe + 0xa0) - (uint)*(ushort *)(iVar3 + 0xca) & 0xffff;
    }
  }
  iVar3 = sub_08151EB4((uint)DAT_030069f8);
  if ((_DAT_030069f0 == 2) || (_DAT_030069f0 == 0xd)) {
    uVar2 = DAT_03006a00 >> 3;
    uVar1 = DAT_03006a02 >> 3;
    iVar5 = sub_08151FD8(0);
    uVar2 = *(ushort *)
             (iVar5 + ((uint)uVar1 * (uint)(*(ushort *)(iVar3 + 200) >> 3) + (uint)uVar2) * 2);
    uVar6 = (uint)(_DAT_03006a04 >> 3);
    uVar8 = (uint)(DAT_03006a06 >> 3);
    iVar5 = sub_08151FD8(0);
    if ((*(ushort *)(iVar5 + (uVar8 * (*(ushort *)(iVar3 + 200) >> 3) + uVar6) * 2) & 0x1ff) !=
        (uVar2 & 0x1ff)) {
      uVar6 = (uint)(DAT_030069fc >> 3);
      uVar8 = (uint)(DAT_030069fe >> 3);
    }
  }
  else {
    uVar6 = (uint)(DAT_030069fc >> 3);
    uVar8 = (uint)(DAT_030069fe >> 3);
  }
  iVar5 = sub_08151FD8(0);
  if (((*(ushort *)(iVar5 + (uVar8 * (*(ushort *)(iVar3 + 200) >> 3) + uVar6) * 2) & (ushort)0x1ff)
       == 0) || (DAT_03006a0c != 0)) {
    DAT_03000030 = 0;
    DAT_03000031 = 0;
    DAT_03000034 = '\0';
    DAT_03000035 = 0;
    arg2 = 2;
    DAT_03006a10 = (short)arg1 + -0x10;
  }
  else {
    DAT_03000030 = 0x88;
    DAT_03000031 = 0x68;
    DAT_03000034 = (char)arg1 + '\x10';
    DAT_03006a10 = (short)(arg1 - 0x10);
    DAT_03000035 = (undefined1)(arg1 - 0x10);
    DAT_03000038 = 0x3f;
    arg2 = 3;
  }
  DAT_03006a0e = (short)local_2c + -0x10;
  if (DAT_030069f8 == 2) {
    puVar7 = (ushort *)0x87df95c;
    uVar2 = 0x298;
    do {
      if ((DAT_030069fc == uVar2) && (DAT_030069fe == puVar7[1])) {
        DAT_03000030 = 0;
        DAT_03000031 = 0;
        DAT_03000034 = '\0';
        DAT_03000035 = 0;
        arg2 = 2;
        break;
      }
      puVar7 = puVar7 + 2;
      uVar2 = *puVar7;
    } while (uVar2 != 0xffff);
  }
  if ((DAT_030069f8 == 8) && (DAT_030069fe < 0x60)) {
    DAT_03000030 = 0;
    DAT_03000031 = 0;
    DAT_03000034 = '\0';
    DAT_03000035 = 0;
    arg2 = 2;
  }
  sub_080C2F44(local_2c,arg1,arg2);
  sub_08153C98();
  sub_08153D88();
  return;
}


// sub_08152384 @ 0x08152384

void sub_08152384(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 | 4;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 & 0xff;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = DAT_03006a10 << 8 | 0x24U | uVar1;
  DAT_03006a0a = 0;
  DAT_03006a12 = DAT_03006a0e;
  DAT_03006a14 = DAT_03006a10;
  return;
}


// sub_081523C8 @ 0x081523C8

void sub_081523C8(void)

{
  ushort uVar1;
  
  if (DAT_03006a0a != 0x20) {
    REG_WIN0H = DAT_03006a12 * 0x101 + *(short *)(&DAT_087dfa5a + (uint)DAT_03006a0a * 4) +
                *(short *)((uint)DAT_03006a0a * 4 + 0x87dfa58) * 0x100;
    DAT_03006a0a = DAT_03006a0a + 1;
    uVar1 = REG_DISPSTAT;
    REG_DISPSTAT = (DAT_03006a14 + DAT_03006a0a) * 0x100 | uVar1 & 0xff;
  }
  return;
}


// sub_08152420 @ 0x08152420

void sub_08152420(void)

{
  DAT_030020f8 = 0x81523c9;
  sub_080A9C30();
  return;
}


// sub_08152440 @ 0x08152440

void sub_08152440(int arg0,int arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000000;
  
  iVar1 = sub_08151EB4((uint)DAT_030069f8);
  if ((ushort)arg2 < 0x79) {
    uVar6 = 0;
  }
  else {
    uVar6 = (uint)(ushort)((ushort)arg2 - 0x78);
  }
  uVar2 = *(ushort *)(iVar1 + 200) - 0xf0;
  if ((int)uVar2 < (int)uVar6) {
    uVar6 = uVar2 & 0xffff;
  }
  if ((ushort)arg3 < 0x51) {
    uVar2 = 0;
  }
  else {
    uVar2 = (uint)(ushort)((ushort)arg3 - 0x50);
  }
  uVar3 = *(ushort *)(iVar1 + 0xca) - 0xa0;
  if ((int)uVar3 < (int)uVar2) {
    uVar2 = uVar3 & 0xffff;
  }
  uVar3 = 0;
  do {
    puVar4 = (undefined2 *)
             (arg0 + (((in_stack_00000000 & 0xffff) >> 3) * ((uVar2 >> 3) + uVar3) + (uVar6 >> 3)) *
                     2);
    uVar5 = 0;
    do {
      *(undefined2 *)
       ((((uVar2 >> 3 & 0x1f) + uVar3 & 0x1f) * 0x20 + ((uVar6 >> 3 & 0x1f) + uVar5 & 0x1f)) * 2 +
       arg1) = *puVar4;
      puVar4 = puVar4 + 1;
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 0x20);
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 0x20);
                    /* WARNING: Could not recover jumptable at 0x0815251a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815251C @ 0x0815251C

void sub_0815251C(uint arg0)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)0x87dfad8;
  pbVar1 = &DAT_087dfade + (arg0 & 0xffff);
  while( true ) {
    if (*pbVar2 == 0xff) {
      return;
    }
    if (((*pbVar2 == DAT_030069f8) && (DAT_030069fc >> 4 == *(ushort *)(pbVar2 + 2))) &&
       (DAT_030069fe >> 4 == *(ushort *)(pbVar2 + 4))) break;
    pbVar1 = pbVar1 + 0x10;
    pbVar2 = pbVar2 + 0x10;
  }
  if (pbVar2[1] == 0) {
    DAT_03006a0c = (ushort)pbVar2[6];
    return;
  }
  DAT_03006a0c = (ushort)*pbVar1;
  return;
}


// sub_08152578 @ 0x08152578

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08152578(undefined4 arg0,undefined4 arg1)

{
  _DAT_030069f0 = arg1;
  return;
}


// sub_08152584 @ 0x08152584

void sub_08152584(undefined4 arg0,int arg1)

{
  int iVar1;
  dword arg2;
  int arg1_00;
  undefined4 local_14;
  
  iVar1 = sub_08151EB4((uint)DAT_030069f8);
  arg1_00 = arg1 * 0x1000 + 0x2001000;
  local_14 = 0;
  arg2 = 0x5000400;
  CpuSet(&local_14,arg1_00,0x5000400);
  HuffUnComp(*(undefined4 *)(iVar1 + arg1 * 4),0x200afc8,arg2);
  LZ77UnCompWram(0x200afc8,arg1_00,arg2);
  return;
}


// sub_081525D8 @ 0x081525D8

void sub_081525D8(undefined4 arg0,uint arg1)

{
  int iVar1;
  undefined4 in_r2;
  
  iVar1 = sub_08151EB4((uint)DAT_030069f8);
  iVar1 = *(int *)(iVar1 + 0xa8 + arg1 * 4);
  if (iVar1 != 0) {
    HuffUnComp(iVar1,0x200afc8,in_r2);
    if (arg1 < 4) {
      LZ77UnCompWram(0x200afc8,arg1 * 0x1000 + 0x2005004,in_r2);
    }
    else {
      LZ77UnCompWram(0x200afc8,(arg1 - 4) * 0x1000 + 0x2030c74,in_r2);
    }
  }
  return;
}


// sub_08152630 @ 0x08152630

void sub_08152630(undefined4 arg0,int arg1)

{
  int iVar1;
  int arg0_00;
  dword dVar2;
  int arg1_00;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = sub_08151EB4((uint)DAT_030069f8);
  arg1_00 = arg1 * 0x1000 + 0x200f874;
  local_1c = 0;
  dVar2 = 0x5000400;
  CpuSet(&local_1c,arg1_00,0x5000400);
  if ((*(int *)(iVar1 + 0x24) != 0) && (arg0_00 = *(int *)(iVar1 + 0x20 + arg1 * 4), arg0_00 != 0))
  {
    HuffUnComp(arg0_00,0x200afc8,dVar2);
    LZ77UnCompWram(0x200afc8,arg1_00,dVar2);
  }
  local_18 = 0;
  dVar2 = 0x5000400;
  CpuSet(&local_18,&DAT_0201f874 + arg1 * 0x1000,0x5000400);
  if ((*(int *)(iVar1 + 100) != 0) && (iVar1 = *(int *)(iVar1 + 0x60 + arg1 * 4), iVar1 != 0)) {
    HuffUnComp(iVar1,0x200afc8,dVar2);
    LZ77UnCompWram(0x200afc8,&DAT_0201f874 + arg1 * 0x1000,dVar2);
  }
  return;
}


// sub_081526D0 @ 0x081526D0

void sub_081526D0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84002000;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_081526F4 @ 0x081526F4

void sub_081526F4(void)

{
  DisplayList_Add(0x81526d1,1);
  return;
}


// sub_08152708 @ 0x08152708

void sub_08152708(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_0815272C @ 0x0815272C

void sub_0815272C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000800;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_08152750 @ 0x08152750

void sub_08152750(undefined4 arg0,uint arg1,int arg2)

{
  undefined4 uVar1;
  
  sub_08151EB4((uint)DAT_030069f8);
  if (arg2 == 2) {
    uVar1 = sub_08151FD8(arg1 & 0xffff);
    sub_08152440(uVar1,0x2000000,(uint)DAT_030069fc,(uint)DAT_030069fe);
    DisplayList_Add(0x8152709,1);
  }
  else if (arg2 == 3) {
    uVar1 = sub_08151FD8(arg1 & 0xffff);
    sub_08152440(uVar1,0x2000800,(uint)DAT_030069fc,(uint)DAT_030069fe);
    DisplayList_Add(0x815272d,1);
  }
  return;
}


// sub_081527E0 @ 0x081527E0

void sub_081527E0(void)

{
  int iVar1;
  
  iVar1 = sub_08151EB4((uint)DAT_030069f8);
  sub_080C67C0(0x30029b0,0xc);
  sub_080ACFCC(3,*(undefined4 *)(iVar1 + 0xa0),&DAT_03002ab0,0x100);
  DAT_030029b2 = 0;
  return;
}


// sub_08152824 @ 0x08152824

void sub_08152824(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_08152848 @ 0x08152848

void sub_08152848(void)

{
  undefined4 in_r2;
  
  HuffUnComp(0x87dde08,0x200afc8,in_r2);
  LZ77UnCompWram(0x200afc8,0x2001000,in_r2);
  HuffUnComp(0x87de4c8,0x200afc8,in_r2);
  LZ77UnCompWram(0x200afc8,&DAT_02002000,in_r2);
  sub_080ACFCC(3,0x87de8c4,0x3002d50,0x60);
  DisplayList_Add(0x8152825,1);
  return;
}


// sub_081528B4 @ 0x081528B4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081528B4(void)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = sub_080C2340(0x69);
  if ((iVar1 != 0) && (iVar1 = sub_080C2340(0x109), iVar1 == 0)) {
    _DAT_030069f0 = 9;
    return;
  }
  if (DAT_030069f8 == 6) {
    iVar1 = sub_080C2340(0x61);
    if ((iVar1 != 0) && (iVar1 = sub_080C2340(0x79), iVar1 == 0)) {
      _DAT_030069f0 = 10;
      return;
    }
    if (DAT_030069f8 == 6) {
      iVar1 = sub_080C2340(0x79);
      if ((iVar1 != 0) && (iVar1 = sub_080C2340(99), iVar1 == 0)) {
        _DAT_030069f0 = 0xb;
        return;
      }
      if (((DAT_030069f8 == 6) && (DAT_030069fc >> 4 == 0x1f)) && (DAT_030069fe >> 4 == 0x47)) {
        _DAT_030069f0 = 0xc;
        return;
      }
    }
  }
  if (DAT_030069f4 == 0) {
    if ((DAT_03005f80._2_1_ == '\x04') && ((DAT_03005f80._3_1_ & 0x3f) == 0x3b)) {
      puVar2 = (ushort *)0x87dfb88;
    }
    else {
      puVar2 = (ushort *)((uint)(DAT_03005f80._3_1_ >> 6) * 2 + 0x87dfb88);
    }
    sub_08152A04((uint)*puVar2);
    DAT_03006a08 = 1;
    _DAT_030069f0 = 0xd;
  }
  else if (DAT_030069f4 == 3) {
    sub_08152A04((uint)*(ushort *)((DAT_03003fd8 & 7) * 2 + 0x87dfb90));
    DAT_03006a08 = 1;
    _DAT_030069f0 = 0xd;
  }
  else {
    _DAT_030069f0 = 1;
  }
  return;
}


// sub_081529E0 @ 0x081529E0

dword sub_081529E0(void)

{
  dword dVar1;
  
  if (DAT_03006a0c == 0) {
    dVar1 = 0x2005004;
  }
  else {
    dVar1 = 0x2030c74;
  }
  return dVar1;
}


// sub_08152A04 @ 0x08152A04

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int sub_08152A04(undefined4 arg0)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  dword dVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  ushort uVar12;
  int iVar13;
  char cVar14;
  ushort uStack_20;
  short sStack_1e;
  
  iVar3 = sub_081529E0();
  iVar13 = 0;
  uVar10 = (uint)(DAT_030069fc >> 4);
  uVar11 = (uint)(DAT_030069fe >> 4);
  _DAT_03006a04 = DAT_030069fc;
  DAT_03006a06 = DAT_030069fe;
  uVar7 = 0;
  if (((ushort)arg0 & 0xf0) != 0x40) {
    do {
      uVar7 = uVar7 + 1 & 0xffff;
      if (7 < uVar7) break;
    } while (*(ushort *)(uVar7 * 2 + 0x87dfb90) != ((ushort)arg0 & 0xf0));
  }
  sub_0815251C(uVar7);
  iVar8 = uVar11 - 1;
  uVar7 = (uint)((*(byte *)(iVar3 + uVar10 + iVar8 * 0x40) & 0xf) == 0);
  uVar4 = (uint)((*(byte *)(iVar3 + uVar10 + uVar11 * 0x40 + 1) & 0xf) == 0);
  iVar9 = uVar11 + 1;
  uVar5 = (uint)((*(byte *)(iVar3 + uVar10 + iVar9 * 0x40) & 0xf) == 0);
  uVar11 = (uint)((*(byte *)(iVar3 + uVar10 + uVar11 * 0x40 + -1) & 0xf) == 0);
  uVar10 = (uint)((*(byte *)(iVar3 + uVar10 + iVar8 * 0x40 + -1) & 0xf) == 0) + uVar7 * 0x10 +
           (uint)((*(byte *)(iVar3 + uVar10 + iVar8 * 0x40 + 1) & 0xf) == 0) * 0x100 +
           uVar4 * 0x1000 +
           (uint)((*(byte *)(iVar3 + uVar10 + iVar9 * 0x40 + 1) & 0xf) == 0) * 0x10000 +
           uVar5 * 0x100000 +
           (uint)((*(byte *)(iVar3 + uVar10 + iVar9 * 0x40 + -1) & 0xf) == 0) * 0x1000000 +
           uVar11 * 0x10000000;
  cVar14 = ((ushort)arg0 & 0x40) != 0;
  if (((ushort)arg0 & 0x80) != 0) {
    cVar14 = cVar14 + '\x02';
  }
  if (((ushort)arg0 & 0x20) != 0) {
    cVar14 = cVar14 + '\x04';
  }
  if (((ushort)arg0 & 0x10) != 0) {
    cVar14 = cVar14 + '\b';
  }
  switch(cVar14) {
  case '\x01':
    uVar10 = uVar10 & 0xf000ffff;
    if (uVar10 != 0x1010) {
      if (uVar10 < 0x1011) {
        if (uVar10 == 0x11) {
LAB_08152c28:
          _DAT_03006a04 = _DAT_03006a04 + 0x10;
          DAT_03006a06 = DAT_03006a06 - 0x10;
          goto LAB_08152e70;
        }
        if (uVar10 != 0x110) {
LAB_08152c3c:
          if (uVar7 != 0) goto switchD_08152ba0_caseD_3;
          DAT_03006a06 = DAT_03006a06 - 0x10;
          break;
        }
      }
      else if (uVar10 != 0x1110) {
        if (((uVar10 < 0x1110) || (0x10000011 < uVar10)) || (uVar10 < 0x10000010))
        goto LAB_08152c3c;
        goto LAB_08152c28;
      }
    }
    _DAT_03006a04 = _DAT_03006a04 - 0x10;
    DAT_03006a06 = DAT_03006a06 - 0x10;
    break;
  case '\x02':
    uVar10 = uVar10 & 0xfffff000;
    if (uVar10 != 0x111000) {
      if (0x111000 < uVar10) {
        if (uVar10 != 0x10100000) {
          if (uVar10 < 0x10100001) {
            dVar6 = 0x1100000;
          }
          else {
            dVar6 = 0x11100000;
          }
          if (uVar10 != dVar6) goto LAB_08152cb4;
        }
        _DAT_03006a04 = _DAT_03006a04 + 0x10;
        goto LAB_08152e30;
      }
      if ((uVar10 != 0x101000) && (uVar10 != 0x110000)) {
LAB_08152cb4:
        if (uVar5 != 0) goto switchD_08152ba0_caseD_3;
        DAT_03006a06 = DAT_03006a06 + 0x10;
        goto LAB_08152e70;
      }
    }
    _DAT_03006a04 = _DAT_03006a04 - 0x10;
    goto LAB_08152e68;
  default:
    goto switchD_08152ba0_caseD_3;
  case '\x04':
    uVar10 = uVar10 & 0xfff000ff;
    if (uVar10 < 0x10000012) {
      if ((uVar10 < 0x10000010) && (uVar10 != 0x10000001)) goto LAB_08152d28;
      _DAT_03006a04 = _DAT_03006a04 - 0x10;
      goto LAB_08152e68;
    }
    if (uVar10 == 0x11000000) {
LAB_08152d06:
      _DAT_03006a04 = _DAT_03006a04 - 0x10;
      DAT_03006a06 = DAT_03006a06 - 0x10;
    }
    else {
      if (uVar10 < 0x11000001) {
        if (uVar10 == 0x10100000) goto LAB_08152d06;
      }
      else if (uVar10 == 0x11100000) goto LAB_08152d06;
LAB_08152d28:
      if (uVar11 != 0) goto switchD_08152ba0_caseD_3;
      _DAT_03006a04 = _DAT_03006a04 - 0x10;
    }
    break;
  case '\x05':
    if (((uVar10 & 0xf) != 0) || (((uVar10 & 0xf0000000) != 0 && ((uVar10 & 0xf0) != 0))))
    goto switchD_08152ba0_caseD_3;
    _DAT_03006a04 = _DAT_03006a04 - 0x10;
    DAT_03006a06 = DAT_03006a06 - 0x10;
    break;
  case '\x06':
    if (((uVar10 & 0xf000000) != 0) || (((uVar10 & 0xf0000000) != 0 && ((uVar10 & 0xf00000) != 0))))
    goto switchD_08152ba0_caseD_3;
    _DAT_03006a04 = _DAT_03006a04 - 0x10;
LAB_08152e30:
    DAT_03006a06 = DAT_03006a06 + 0x10;
    break;
  case '\b':
    uVar10 = uVar10 & 0xfffff0;
    if (uVar10 != 0x1110) {
      if (0x1110 < uVar10) {
        if (uVar10 != 0x101000) {
          if (uVar10 < 0x101001) {
            dVar6 = 0x11000;
          }
          else {
            dVar6 = 0x111000;
          }
          if (uVar10 != dVar6) goto LAB_08152d9c;
        }
        _DAT_03006a04 = _DAT_03006a04 + 0x10;
        DAT_03006a06 = DAT_03006a06 - 0x10;
        break;
      }
      if ((uVar10 != 0x1010) && (uVar10 != 0x1100)) {
LAB_08152d9c:
        if (uVar4 != 0) goto switchD_08152ba0_caseD_3;
        _DAT_03006a04 = _DAT_03006a04 + 0x10;
        goto LAB_08152e70;
      }
    }
    goto LAB_08152e62;
  case '\t':
    if (((uVar10 & 0xf00) != 0) || (((uVar10 & 0xf000) != 0 && ((uVar10 & 0xf0) != 0))))
    goto switchD_08152ba0_caseD_3;
    _DAT_03006a04 = _DAT_03006a04 + 0x10;
    DAT_03006a06 = DAT_03006a06 - 0x10;
    goto LAB_08152e70;
  case '\n':
    if (((uVar10 & 0xf0000) != 0) || (((uVar10 & 0xf000) != 0 && ((uVar10 & 0xf00000) != 0))))
    goto switchD_08152ba0_caseD_3;
LAB_08152e62:
    _DAT_03006a04 = _DAT_03006a04 + 0x10;
LAB_08152e68:
    DAT_03006a06 = DAT_03006a06 + 0x10;
LAB_08152e70:
    iVar13 = 1;
    goto switchD_08152ba0_caseD_3;
  }
  iVar13 = 1;
switchD_08152ba0_caseD_3:
  if (iVar13 == 1) {
    if ((DAT_030069f8 == 2) && (iVar3 = sub_080C2340(0x68), uVar2 = _DAT_03006a04, iVar3 != 0)) {
      uVar12 = DAT_03006a06 - 8;
      sub_08153C14(&uStack_20,&sStack_1e);
      uVar1 = sStack_1e - 0x30;
      if (uVar2 < uStack_20) {
        uVar2 = uStack_20 - uVar2;
      }
      else {
        uVar2 = uVar2 - uStack_20;
      }
      if (uVar12 < uVar1) {
        uVar12 = uVar1 - uVar12;
      }
      else {
        uVar12 = uVar12 - uVar1;
      }
      if ((uVar2 < 0x18) && (uVar12 < 0x28)) {
        return 0;
      }
    }
    DAT_03006a00 = DAT_030069fc;
    DAT_03006a02 = DAT_030069fe;
  }
  return iVar13;
}


// sub_08152EF8 @ 0x08152EF8

void sub_08152EF8(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = sub_08151EB4((uint)DAT_030069f8);
  if (DAT_030069fc < 0x79) {
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)(ushort)(DAT_030069fc - 0x78);
  }
  uVar2 = *(ushort *)(iVar1 + 200) - 0xf0;
  if ((int)uVar2 < (int)uVar3) {
    uVar3 = uVar2 & 0xffff;
  }
  DAT_0300000c = (ushort)uVar3 & 0xff;
  DAT_03000008 = DAT_0300000c;
  if (DAT_030069fe < 0x51) {
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)(ushort)(DAT_030069fe - 0x50);
  }
  uVar2 = *(ushort *)(iVar1 + 0xca) - 0xa0;
  if ((int)uVar2 < (int)uVar3) {
    uVar3 = uVar2 & 0xffff;
  }
  DAT_0300000e = (ushort)uVar3 & 0xff;
  DAT_0300000a = DAT_0300000e;
  return;
}


// sub_08152F80 @ 0x08152F80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08152F80(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_08151EB4((uint)DAT_030069f8);
  sub_081529E0();
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 8) == 0) {
      if (((DAT_030031b8 & 0x100) == 0) || (iVar1 = sub_0812A7C4(), iVar1 != 1)) {
        iVar1 = sub_08152A04((uint)DAT_030031d0);
        if (iVar1 == 1) {
          _DAT_030069f0 = 2;
          if ((DAT_030031d0 & 2) == 0) {
            DAT_03006a08 = 1;
          }
          else {
            DAT_03006a08 = 2;
          }
          sub_0815300C();
        }
        goto LAB_08153006;
      }
      DAT_030069f6 = 2;
    }
    else {
      DAT_030069f6 = 1;
    }
  }
  else {
    DAT_030069f6 = 0;
  }
  _DAT_030069f0 = 5;
LAB_08153006:
                    /* WARNING: Could not recover jumptable at 0x0815300a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815300C @ 0x0815300C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0815300C(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 uStack_24;
  undefined2 uStack_22;
  
  sub_081529E0();
  if ((_DAT_03006a04 & 0xffff) < (_DAT_030069fc & 0xffff)) {
    sVar3 = -DAT_03006a08;
LAB_0815303c:
    _DAT_030069fc = CONCAT22(DAT_030069fe,DAT_030069fc + sVar3);
  }
  else {
    sVar3 = DAT_03006a08;
    if ((_DAT_030069fc & 0xffff) < (_DAT_03006a04 & 0xffff)) goto LAB_0815303c;
  }
  if (DAT_03006a06 < DAT_030069fe) {
    sVar3 = -DAT_03006a08;
LAB_0815305c:
    _DAT_030069fc = CONCAT22(DAT_030069fe + sVar3,DAT_030069fc);
  }
  else {
    sVar3 = DAT_03006a08;
    if (DAT_030069fe < DAT_03006a06) goto LAB_0815305c;
  }
  sub_08152EF8();
  sub_08152750(0,0,2);
  sub_08152750(0,1,3);
  if (((DAT_030069f8 == 6) && (DAT_030069fc >> 4 == 0x1f)) && (DAT_030069fe >> 4 == 0x47)) {
    _DAT_030069f0 = 0xc;
  }
  else if (_DAT_030069fc == _DAT_03006a04) {
    if (_DAT_030069f0 == 0xd) {
      iVar4 = sub_08153458((uint)(DAT_030069fc >> 4),(uint)(DAT_030069fe >> 4),(uint)DAT_030069f8);
      if (iVar4 == 0) {
        _DAT_030069f0 = 1;
      }
      else {
        _DAT_030069f0 = 4;
      }
    }
    else {
      uVar1 = DAT_030069fc >> 4;
      uVar2 = DAT_030069fe >> 4;
      iVar4 = sub_08153458((uint)uVar1,(uint)uVar2,(uint)DAT_030069f8);
      iVar5 = sub_080C1B74(&uStack_24,&uStack_22);
      iVar6 = sub_0815374C();
      if (iVar4 != 0) {
        if ((*(dword *)(iVar4 + 4) == 0x803ae54) &&
           ((iVar7 = sub_080C2340(0x12), iVar7 != 0 || (uVar8 = sub_080C2244(), (uVar8 & 1) != 0))))
        {
          iVar4 = 0;
        }
        if (iVar4 != 0) {
          _DAT_030069f0 = 4;
          goto LAB_081531c2;
        }
      }
      iVar4 = sub_081537C4();
      if (iVar4 == 1) {
        _DAT_030069f0 = 9;
      }
      else if (((DAT_030069f8 == 6) && (DAT_030069fc >> 4 == 0x1f)) && (DAT_030069fe >> 4 == 0x47))
      {
        _DAT_030069f0 = 0xc;
      }
      else {
        iVar4 = sub_081533DC((uint)uVar1,(uint)uVar2,(uint)DAT_030069f8);
        if (iVar4 == 0) {
          if (iVar5 == 0) {
            if (iVar6 == 0) {
              iVar4 = sub_080C2280(1);
              if (iVar4 == 1) {
                _DAT_030069f0 = 6;
              }
              else {
                sub_080C2168();
                sub_080C1DE0();
                _DAT_030069f0 = 1;
              }
            }
            else {
              _DAT_030069f0 = 8;
            }
          }
          else {
            DAT_03006a20 = uStack_24;
            DAT_03006a22 = uStack_22;
            _DAT_030069f0 = 7;
            DAT_03006a1c = iVar5;
          }
        }
        else {
          _DAT_030069f0 = 3;
        }
      }
    }
  }
LAB_081531c2:
                    /* WARNING: Could not recover jumptable at 0x081531d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081531D4 @ 0x081531D4

uint sub_081531D4(void)

{
  uint uVar1;
  int iVar2;
  uint arg1;
  uint arg2;
  uint arg1_00;
  uint arg0;
  
  arg0 = 0;
  arg1_00 = DAT_03005f80._2_1_ & 0x7f;
  arg2 = DAT_03005f80._3_1_ & 0x3f;
  do {
    uVar1 = sub_080C8B3C(arg0);
    arg1 = 0;
    if ((uVar1 & 0xffff) != 0) {
      do {
        iVar2 = sub_080C8B10(arg0,arg1);
        if ((((*(ushort *)(iVar2 + 8) <= arg1_00) && (*(ushort *)(iVar2 + 10) <= arg2)) &&
            (arg1_00 <= *(ushort *)(iVar2 + 0xc))) &&
           ((arg2 <= *(ushort *)(iVar2 + 0xe) &&
            (iVar2 = sub_080B7944(iVar2,arg1_00,arg2), iVar2 == 1)))) {
          return arg0;
        }
        arg1 = arg1 + 1 & 0xffff;
      } while (arg1 < (uVar1 & 0xffff));
    }
    arg0 = arg0 + 1 & 0xffff;
  } while( true );
}


// sub_08153264 @ 0x08153264

void sub_08153264(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)
           sub_081533DC((uint)(DAT_030069fc >> 4),(uint)(DAT_030069fe >> 4),(uint)DAT_030069f8);
  DAT_03005f84 = puVar1[1];
  DAT_03005f80 = *puVar1;
  uVar2 = sub_08153668();
  uVar3 = sub_081531D4();
  sub_080C2D78((int)(char)uVar2,(int)(char)uVar3);
  return;
}


// sub_081532B0 @ 0x081532B0

void sub_081532B0(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_08153458((uint)(DAT_030069fc >> 4),(uint)(DAT_030069fe >> 4),(uint)DAT_030069f8);
  uVar2 = sub_08153668();
  sub_080C2DE0(uVar2 & 0xffff,*(undefined4 *)(iVar1 + 4));
  return;
}


// sub_081532DC @ 0x081532DC

void sub_081532DC(void)

{
  uint uVar1;
  
  uVar1 = sub_08153668();
  sub_080C2DE0(uVar1 & 0xffff,0x804ae3c);
  return;
}


// sub_081532F4 @ 0x081532F4

void sub_081532F4(void)

{
  uint uVar1;
  
  uVar1 = sub_08153668();
  sub_080C2E10(uVar1 & 0xffff,(uint)DAT_030069f6);
  return;
}


// sub_08153310 @ 0x08153310

void sub_08153310(void)

{
  uint uVar1;
  
  uVar1 = sub_08153668();
  sub_080C2DC0(uVar1 & 0xffff);
  return;
}


// sub_08153324 @ 0x08153324

void sub_08153324(void)

{
  int iVar1;
  
  iVar1 = sub_08151EB4((uint)DAT_030069f8);
  sub_080ACFCC(3,*(undefined4 *)(iVar1 + 0xa4),0x3002ab0,0x100);
  sub_080AB054(0x80,0x80,1,0x20);
  return;
}


// sub_08153360 @ 0x08153360

void sub_08153360(void)

{
  uint uVar1;
  
  uVar1 = sub_08153668();
  sub_080C2E44(uVar1 & 0xffff,0x81988dc);
  return;
}


// sub_08153378 @ 0x08153378

void sub_08153378(undefined4 arg0,uint arg1,uint arg2)

{
  sub_080ACFCC(3,arg0,(arg1 & 0xffff) * 0x20 + 0x30029b0,arg2 & 0xffff);
  return;
}


// sub_081533A8 @ 0x081533A8

void sub_081533A8(undefined4 arg0,uint arg1,uint arg2)

{
  sub_080ACFCC(3,arg0,(arg1 & 0xffff) * 0x20 + 0x3002db0,arg2 & 0xffff);
  sub_080AABB0();
  return;
}


// sub_081533DC @ 0x081533DC

undefined4 sub_081533DC(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  byte *pbVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  for (pbVar2 = (byte *)0x87df344; *pbVar2 != 0xff; pbVar2 = pbVar2 + 8) {
    if (((pbVar2[6] == (ushort)arg2) && (*pbVar2 == (ushort)arg0)) && (pbVar2[1] == (ushort)arg1))
    goto LAB_08153416;
  }
  pbVar2 = (byte *)0x0;
LAB_08153416:
                    /* WARNING: Could not recover jumptable at 0x0815341a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(pbVar2);
  return uVar1;
}


// sub_0815341C @ 0x0815341C

undefined4 sub_0815341C(undefined4 arg0,undefined4 arg1)

{
  undefined4 uVar1;
  dword dVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  for (dVar2 = 0x87df344; *(char *)(dVar2 + 2) != -1; dVar2 = dVar2 + 8) {
    if ((*(byte *)(dVar2 + 2) == (ushort)arg0) && ((*(byte *)(dVar2 + 3) & 0x3f) == (ushort)arg1))
    goto LAB_08153450;
  }
  dVar2 = 0;
LAB_08153450:
                    /* WARNING: Could not recover jumptable at 0x08153454. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(dVar2);
  return uVar1;
}


// sub_08153458 @ 0x08153458

undefined4 sub_08153458(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  dword dVar6;
  byte *pbVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  pbVar7 = (byte *)0x87df54c;
  iVar3 = sub_08151EB4((uint)DAT_030069f8);
  sVar1 = *(short *)(iVar3 + 0xcc);
  sVar2 = *(short *)(iVar3 + 0xce);
  do {
    if (*pbVar7 == 0xff) {
LAB_081534fe:
      pbVar7 = (byte *)0x0;
LAB_08153538:
                    /* WARNING: Could not recover jumptable at 0x0815353c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*UNRECOVERED_JUMPTABLE)(pbVar7);
      return uVar5;
    }
    if ((((pbVar7[2] == (ushort)arg2) && ((ushort)(*pbVar7 & 0x7f) == (ushort)((short)arg0 + sVar1))
         ) && ((ushort)pbVar7[1] == (ushort)((short)arg1 + sVar2))) &&
       ((DAT_03006a0c == pbVar7[3] &&
        (uVar4 = ScriptVM_RunAlt(*(undefined4 *)(pbVar7 + 4)), (uVar4 & 0xffff) != 0)))) {
      iVar3 = sub_080C2340(0x69);
      if (((iVar3 == 0) || (iVar3 = sub_080C2340(0x109), iVar3 == 0)) ||
         ((((dVar6 = *(dword *)(pbVar7 + 4), dVar6 != 0x80560b6 && (dVar6 != 0x8056154)) &&
           (dVar6 != 0x80561f2)) &&
          ((((dVar6 != 0x8056290 && (dVar6 != 0x805632e)) && (dVar6 != 0x80563cc)) &&
           ((dVar6 != 0x805646a && (dVar6 != 0x8056508)))))))) goto LAB_08153538;
      goto LAB_081534fe;
    }
    pbVar7 = pbVar7 + 8;
  } while( true );
}


// sub_08153540 @ 0x08153540

undefined4 sub_08153540(void)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x081535a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)();
  return uVar1;
}


// sub_081535A4 @ 0x081535A4

int sub_081535A4(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = sub_081529E0();
  uVar5 = (uint)(DAT_030069fc >> 4);
  uVar3 = (uint)(DAT_030069fe >> 4);
  iVar2 = (uVar3 - 1) * 0x40;
  iVar4 = (uVar3 + 1) * 0x40;
  return (uint)(*(byte *)(iVar1 + uVar5 + iVar2) >> 4) * 0x10 +
         (uint)(*(byte *)(iVar1 + uVar5 + iVar2 + -1) >> 4) +
         (uint)(*(byte *)(iVar1 + uVar5 + iVar2 + 1) >> 4) * 0x100 +
         (uint)(*(byte *)(iVar1 + uVar5 + uVar3 * 0x40 + 1) >> 4) * 0x1000 +
         (uint)(*(byte *)(iVar1 + uVar5 + iVar4 + 1) >> 4) * 0x10000 +
         (uint)(*(byte *)(iVar1 + uVar5 + iVar4) >> 4) * 0x100000 +
         (uint)(*(byte *)(iVar1 + uVar5 + iVar4 + -1) >> 4) * 0x1000000 +
         (uint)(*(byte *)(iVar1 + uVar5 + uVar3 * 0x40 + -1) >> 4) * 0x10000000;
}


// sub_08153668 @ 0x08153668

undefined4 sub_08153668(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint unaff_r5;
  dword dVar6;
  uint unaff_r6;
  char *pcVar7;
  
  iVar3 = sub_08151EB4((uint)DAT_030069f8);
  uVar4 = sub_081535A4();
  pcVar7 = (char *)(iVar3 + 0xd0);
  uVar5 = sub_08153540();
  switch(uVar5 & 0xffff) {
  case 0:
    unaff_r6 = 0;
    unaff_r5 = 8;
    break;
  case 1:
    unaff_r6 = 4;
    unaff_r5 = 0xc;
    break;
  case 2:
    unaff_r6 = 8;
    unaff_r5 = 0x10;
    break;
  case 3:
    unaff_r6 = 0xc;
    unaff_r5 = 0x14;
    break;
  case 4:
    unaff_r6 = 0x10;
    unaff_r5 = 0x18;
    break;
  case 5:
    unaff_r6 = 0x14;
    unaff_r5 = 0x1c;
    break;
  case 6:
    unaff_r6 = 0x18;
    unaff_r5 = 0;
    break;
  case 7:
    unaff_r6 = 0x1c;
    unaff_r5 = 4;
  }
  uVar5 = uVar4 >> (unaff_r6 & 0xff) & 0xf;
  uVar4 = uVar4 >> (unaff_r5 & 0xff) & 0xf;
  if (uVar5 == 0) {
    cVar1 = *pcVar7;
  }
  else {
    cVar1 = pcVar7[uVar5 - 1];
  }
  if (uVar4 == 0) {
    cVar2 = *pcVar7;
  }
  else {
    cVar2 = pcVar7[uVar4 - 1];
  }
  uVar4 = 0;
  pcVar7 = (char *)0x87e0188;
  dVar6 = 0x87e0188;
  while ((*pcVar7 != cVar1 || (pcVar7[1] != cVar2))) {
    pcVar7 = pcVar7 + 4;
    dVar6 = dVar6 + 4;
    uVar4 = uVar4 + 1;
    if (0xab < uVar4) {
      return 0;
    }
  }
  return *(byte *)(dVar6 + 2) + 0xe0;
}


// sub_0815374C @ 0x0815374C

undefined4 sub_0815374C(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  undefined4 arg0;
  short *psVar6;
  uint uVar7;
  
  iVar5 = sub_08151EB4((uint)DAT_030069f8);
  uVar3 = DAT_030069fc >> 4;
  sVar1 = *(short *)(iVar5 + 0xcc);
  uVar4 = DAT_030069fe >> 4;
  sVar2 = *(short *)(iVar5 + 0xce);
  iVar5 = sub_080C2340(2);
  if ((iVar5 != 0) && (iVar5 = sub_080C2340(0x16), iVar5 != 0)) {
    uVar7 = 0;
    psVar6 = (short *)0x87e043c;
    do {
      if (((ushort)(uVar3 + sVar1) == *psVar6) && ((ushort)(uVar4 + sVar2) == psVar6[1])) {
        arg0 = sub_080C2244();
        iVar5 = __umodsi3(arg0,5);
        if (iVar5 == 0) {
          return 1;
        }
      }
      psVar6 = psVar6 + 2;
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x1a);
  }
  return 0;
}


// sub_081537C4 @ 0x081537C4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 sub_081537C4(void)

{
  int iVar1;
  dword dVar2;
  
  iVar1 = sub_080C2340(0x69);
  if ((iVar1 != 0) && (iVar1 = sub_080C2340(0x109), iVar1 != 0)) {
    if (DAT_030069f8 == 5) {
      dVar2 = 0x37001c8;
    }
    else {
      if (DAT_030069f8 != 6) {
        return 0;
      }
      dVar2 = 0x7800238;
    }
    if (_DAT_030069fc == dVar2) {
      return 1;
    }
  }
  return 0;
}


// sub_08153810 @ 0x08153810

void sub_08153810(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_08153834 @ 0x08153834

void sub_08153834(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x600e000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  sub_08153810();
  return;
}


// sub_08153860 @ 0x08153860

void sub_08153860(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x81000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_08153890 @ 0x08153890

void sub_08153890(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x87e04a4,0x2001000,in_r2);
  LZ77UnCompWram(0x87e0788,0x2000000,in_r2);
  sub_080AB1C4(0x2000000,0x300,7,0);
  sub_080ACFCC(3,0x87e0978,0x3002a90,0x20);
  sub_080AAFBC(0x70,0x10,4);
  sub_080AB138(0x80,0x80,4,8);
  sub_080AB138(0x1d0,0x30,4,8);
  DAT_03000004 = 0xffcc;
  DAT_03000006 = 0xfff0;
  DisplayList_Add(0x8153835,1);
  return;
}


// sub_08153938 @ 0x08153938

void sub_08153938(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x81000800;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x81000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_08153974 @ 0x08153974

void sub_08153974(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080C2340(0x109);
  *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 != 0);
  return;
}


// sub_08153990 @ 0x08153990

void sub_08153990(undefined4 arg0,undefined4 arg1)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  switch(arg1) {
  case 0:
    sub_080AB0F0(0x70,0x10,4);
    break;
  case 1:
    DisplayList_Add(0x8153861,1);
    DAT_03000004 = 0;
    DAT_03000006 = 0;
    break;
  case 2:
    sub_080AB0F0(0x80,0x80,4);
    sub_080AB0F0(0x1d0,0x30,4);
    sub_080C51BC(2);
    break;
  case 3:
    if (DAT_030069f8 == 5) {
      DAT_030069f8 = 6;
      DAT_03006a00 = 0x238;
      DAT_030069fc = 0x238;
      DAT_03006a02 = 0x790;
      DAT_030069fe = 0x790;
      sub_08152EF8();
      uVar1 = sub_080AD67C((uint)DAT_030069f8);
      sub_080C5170(uVar1 & 0xffff);
    }
    else {
      DAT_030069f8 = 5;
      DAT_03006a00 = 0x1c8;
      DAT_030069fc = 0x1c8;
      DAT_03006a02 = 0x380;
      DAT_030069fe = 0x380;
      sub_08152EF8();
      uVar1 = sub_080AD67C((uint)DAT_030069f8);
      sub_080C5170(uVar1 & 0xffff);
    }
    DisplayList_Add(0x8153939,1);
    break;
  case 4:
    sub_080AB054(0x80,0x80,4,0x20);
    sub_080AB054(0x1d0,0x30,4,0x20);
  }
                    /* WARNING: Could not recover jumptable at 0x08153a8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08153A90 @ 0x08153A90

void sub_08153A90(undefined4 arg0,int arg1)

{
  undefined4 uVar1;
  undefined2 local_8 [4];
  
  if (arg1 == 0) {
    DAT_03006a24 = 1;
    DisplayList_Add(0x8153861,1);
  }
  else {
    DAT_03006a24 = 0;
    local_8[0] = 0x3b3;
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x2000000;
    REG_DMA3CNT = 0x81000800;
    uVar1 = REG_DMA3CNT;
    sub_080AB250(0x81b8270,0x2000000,0,0);
    DisplayList_Add(0x8153811,1);
  }
  return;
}


// sub_08153B0C @ 0x08153B0C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08153B0C(void)

{
  sub_080C2364(0x109);
  _DAT_030069f0 = 1;
  return;
}


// sub_08153B28 @ 0x08153B28

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08153B28(int arg0,undefined4 arg1,undefined4 arg2,int arg3)

{
  int iVar1;
  
  sub_081529E0();
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_030069fc = DAT_030069fc + (short)arg1;
  DAT_030069fe = DAT_030069fe + (short)arg2;
  sub_08152EF8();
  sub_08152750(0,0,2);
  sub_08152750(0,1,3);
  iVar1 = sub_08153458((uint)(DAT_030069fc >> 4),(uint)(DAT_030069fe >> 4),(uint)DAT_030069f8);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 4) == arg3)) {
    _DAT_030069f0 = 4;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_03006a26 = 0;
  }
  return;
}


// sub_08153BA0 @ 0x08153BA0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08153BA0(int arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  int iVar1;
  uint in_stack_00000000;
  
  sub_081529E0();
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_030069fc = DAT_030069fc + (short)arg1;
  DAT_030069fe = DAT_030069fe + (short)arg2;
  sub_08152EF8();
  sub_08152750(0,0,2);
  sub_08152750(0,1,3);
  if ((DAT_030069fc >> 4 == arg3) && (DAT_030069fe >> 4 == in_stack_00000000)) {
    iVar1 = sub_081533DC((uint)(DAT_030069fc >> 4),(uint)(DAT_030069fe >> 4),(uint)DAT_030069f8);
    if (iVar1 != 0) {
      _DAT_030069f0 = 3;
    }
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_08153C14 @ 0x08153C14

void sub_08153C14(short *arg0,short *arg1)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = (short *)0x87e0f84;
  sVar1 = 5;
  while ((sVar1 != 2 || (psVar2[3] != 0x68))) {
    psVar2 = psVar2 + 8;
    sVar1 = *psVar2;
    if (sVar1 == -1) {
      return;
    }
  }
  *arg0 = psVar2[1];
  *arg1 = psVar2[2];
  return;
}


// sub_08153C50 @ 0x08153C50

void sub_08153C50(undefined4 arg0,undefined4 arg1,short *arg2,short *arg3)

{
  short sVar1;
  
  sVar1 = (short)arg0 - DAT_030069fc;
  *arg2 = sVar1;
  if (0x14c < (ushort)(sVar1 + 0x20U)) {
    *arg2 = 300;
  }
  sVar1 = (short)arg1 - DAT_030069fe;
  *arg3 = sVar1;
  if (0x110 < (ushort)(sVar1 + 0x20U)) {
    *arg3 = 0xf0;
  }
  return;
}


// sub_08153C98 @ 0x08153C98

void sub_08153C98(void)

{
  int iVar1;
  short sVar2;
  dword arg0;
  short *psVar3;
  undefined1 local_1c [2];
  undefined1 local_1a [2];
  
  psVar3 = (short *)0x87e0f84;
  sVar2 = 5;
  do {
    if ((sVar2 == DAT_030069f8) && (iVar1 = sub_080C2340((uint)(ushort)psVar3[3]), iVar1 != 0)) {
      arg0 = *(dword *)(psVar3 + 4);
      if (arg0 == 0x800790c) {
        arg0 = *(dword *)((DAT_030031bc >> 2 & 3) * 4 + 0x87e0fd4);
      }
      sub_08153C50((ushort)psVar3[1] + 0x78 & 0xffff,(ushort)psVar3[2] + 0x50 & 0xffff,local_1c,
                   local_1a);
      sub_080AA184(arg0,4,(uint)(ushort)psVar3[6],2);
    }
    psVar3 = psVar3 + 8;
    sVar2 = *psVar3;
  } while (sVar2 != -1);
  return;
}


// sub_08153D40 @ 0x08153D40

void sub_08153D40(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2034c74;
  REG_DMA3DAD = 0x6008000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_08153D64 @ 0x08153D64

void sub_08153D64(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x202f874;
  REG_DMA3DAD = 0x6008000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_08153D88 @ 0x08153D88

void sub_08153D88(void)

{
  int iVar1;
  
  if (((DAT_030069f8 == 6) && (iVar1 = sub_080C2340(0x65), iVar1 == 0)) &&
     ((DAT_030031bc & 0xf) == 0)) {
    if ((DAT_030031bc >> 4 & 1) == 0) {
      DisplayList_Add(0x8153d65,1);
    }
    else {
      DisplayList_Add(0x8153d41,1);
    }
  }
  return;
}


// sub_08153DD8 @ 0x08153DD8

void sub_08153DD8(void)

{
  undefined4 in_r2;
  
  if (DAT_030069f8 == 6) {
    HuffUnComp(0x87c5e10,0x200afc8,in_r2);
    LZ77UnCompWram(0x200afc8,0x2034c74,in_r2);
    HuffUnComp(0x87c6358,0x200afc8,in_r2);
    LZ77UnCompWram(0x200afc8,0x202f874,in_r2);
  }
  return;
}


// sub_08153E24 @ 0x08153E24

void sub_08153E24(undefined4 arg0)

{
  uint uVar1;
  
  uVar1 = 0;
  while ((*(int *)(&DAT_0203a470 + uVar1 * 4) == 0 || ((&DAT_0203aac0)[uVar1 * 2] != (short)arg0)))
  {
    uVar1 = uVar1 + 1 & 0xffff;
    if (0xb < uVar1) {
      return;
    }
  }
  return;
}


// sub_08153E70 @ 0x08153E70

int sub_08153E70(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = sub_080C09B0(iVar2 + 4);
    if ((iVar1 != 0) && (iVar1 = sub_080C0830(), iVar1 == 0)) {
      iVar3 = iVar3 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xc);
  return iVar3;
}


// sub_08153E9C @ 0x08153E9C

void sub_08153E9C(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = (undefined4 *)&DAT_0203a470;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xc);
  return;
}


// sub_08153EB8 @ 0x08153EB8

uint sub_08153EB8(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  do {
    iVar1 = sub_080C09B0(uVar2 + 4);
    if ((iVar1 != 0) && (iVar1 = sub_080C0830(), iVar1 == 0)) {
      *(uint *)(&DAT_0203a470 + uVar3 * 4) = uVar2 * 0x80 + 0x30048c0;
      uVar3 = uVar3 + 1 & 0xffff;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0xc);
  return uVar3;
}


// sub_08153F08 @ 0x08153F08

void sub_08153F08(void)

{
  undefined4 uVar1;
  
  sub_08153E9C();
  uVar1 = sub_08153EB8();
  DAT_0203a456 = 1;
  DAT_0203aab2 = (undefined2)uVar1;
  sub_0815B880();
  DAT_03003bb4 = 0;
  return;
}


// sub_08153F3C @ 0x08153F3C

uint sub_08153F3C(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = 0;
  do {
    if (*(int *)(&DAT_0203a470 + uVar1 * 4) != 0) {
      uVar2 = uVar2 + 1 & 0xffff;
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0xc);
  return uVar2;
}


// sub_08153F6C @ 0x08153F6C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08153F6C(uint arg0)

{
  (&DAT_0203a4a0)[_DAT_0203a45c] = *(undefined4 *)(&DAT_0203a470 + (arg0 & 0xffff) * 4);
  return;
}


// sub_08153F8C @ 0x08153F8C

void sub_08153F8C(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  sub_080AC62C((arg0 & 0xffff) * 0x20 + 0x87e0fe4,arg1,0,0);
  return;
}


// sub_08153FC8 @ 0x08153FC8

void sub_08153FC8(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint arg0_00;
  
  if ((short)arg0 == 0x1b) {
    arg0._0_2_ = 0x101;
  }
  if ((short)arg0 == 5) {
    arg0._0_2_ = 0x102;
  }
  arg0_00 = (uint)(ushort)((short)arg0 + 0x200);
  sub_080ABF24(arg0_00);
  sub_080AC62C(arg0_00,arg1,2,2);
  return;
}


// sub_08154038 @ 0x08154038

void sub_08154038(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  sub_08153F8C((uint)*(ushort *)((arg0 & 0xffff) * 2 + 0x87e1be4),0x200f874,arg1 & 0xffff,
               arg2 & 0xffff);
  return;
}


// sub_08154074 @ 0x08154074

void sub_08154074(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = DAT_0203b8f8;
  if (DAT_0203b8fa < DAT_0203b8f8) {
    DAT_0203b8f8 = DAT_0203b8fa;
    DAT_0203b8fa = uVar1;
  }
  uVar2 = DAT_0203b8fa;
  uVar1 = DAT_0203b8f8;
  if (DAT_0203b8fc < DAT_0203b8f8) {
    DAT_0203b8f8 = DAT_0203b8fc;
    DAT_0203b8fc = uVar1;
  }
  if (DAT_0203b8fc < DAT_0203b8fa) {
    DAT_0203b8fa = DAT_0203b8fc;
    DAT_0203b8fc = uVar2;
  }
  return;
}


// sub_081540B8 @ 0x081540B8

undefined4 sub_081540B8(undefined4 arg0,uint arg1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  uint uVar5;
  uint arg0_00;
  int iVar6;
  int unaff_r8;
  byte unaff_r10;
  code *UNRECOVERED_JUMPTABLE;
  byte bStack_28;
  
  arg0_00 = (uint)(ushort)arg0;
  uVar5 = arg1 & 0xffff;
  iVar6 = *(int *)(&DAT_0203a470 + uVar5 * 4);
  bVar1 = false;
  if (DAT_0203a454 == 2) {
    DAT_0203b8fa = *(ushort *)(iVar6 + 0x12);
    DAT_0203b8fc = 0xffff;
    DAT_0203b8f8 = (ushort)arg0;
    unaff_r8 = sub_0815B4B4();
    sub_08158970();
    sub_0815B260();
LAB_0815421c:
    if (arg0_00 != (int)*(short *)(iVar6 + 0x12)) {
      if ((DAT_0203b90e == 0x40) || (DAT_0203b908 == 0xff)) {
LAB_0815423c:
        bVar4 = 0x16;
        goto LAB_081542fc;
      }
      if (unaff_r8 != 0) {
        DAT_0203b90e = 0x30;
      }
      uVar5 = sub_0815B958((uint)DAT_0203b908);
      uVar5 = uVar5 & 0xff;
      if (uVar5 == 1) {
        bStack_28 = 0x10;
      }
      else if (uVar5 < 2) {
        if (uVar5 == 0) {
          bStack_28 = 0;
        }
      }
      else if (uVar5 == 2) {
        bStack_28 = 0x20;
      }
      if (DAT_0203a454 == 2) {
        bVar4 = DAT_0203b90e & 0xf;
        if (bVar4 != 2) {
          if (bVar4 < 3) {
            if (bVar4 == 1) {
              unaff_r10 = 4;
              goto LAB_081542f4;
            }
          }
          else if (bVar4 == 3) {
            unaff_r10 = 3;
            bVar1 = true;
          }
          goto LAB_081542b4;
        }
        unaff_r10 = 2;
      }
      else {
LAB_081542b4:
        if (!bVar1) {
          bVar4 = DAT_0203b90e >> 4;
          if (bVar4 == 2) {
            unaff_r10 = 7;
          }
          else {
            if (bVar4 < 3) {
              if (bVar4 == 1) {
                unaff_r10 = 1;
                goto LAB_081542f4;
              }
            }
            else if (bVar4 == 3) {
              unaff_r10 = 5;
              bStack_28 = 0x10;
              bVar1 = true;
            }
            if (!bVar1) {
              unaff_r10 = 0;
            }
          }
        }
      }
LAB_081542f4:
      bVar4 = unaff_r10 | bStack_28;
      goto LAB_081542fc;
    }
  }
  else {
    if (DAT_0203a454 == 3) {
      DAT_0203b8f8 = DAT_0203b854;
      DAT_0203b8fc = *(undefined2 *)(iVar6 + 0x12);
      DAT_0203b8fa = (ushort)arg0;
      sub_08154074();
      unaff_r8 = sub_0815B4B4();
      sub_081596F0();
      sub_0815B260();
      goto LAB_0815421c;
    }
    if (DAT_0203a454 == 1) {
      uVar3 = sub_08154968(arg0_00);
      DAT_0203b8f8 = (ushort)uVar3;
      DAT_0203b8fa = 0xffff;
      DAT_0203b8fc = *(undefined2 *)(&DAT_030046d2 + (uVar5 + 4) * 0x80);
      iVar2 = sub_0815AE84();
joined_r0x0815420a:
      if (iVar2 != 0) {
        bVar4 = 0x10;
        goto LAB_081542fc;
      }
      goto LAB_0815423c;
    }
    if (DAT_0203a454 != 4) {
      if (DAT_0203a454 != 5) goto LAB_0815421c;
      uVar3 = sub_08154968((uint)DAT_0203b854);
      DAT_0203b8f8 = (ushort)uVar3;
      uVar3 = sub_08154968(arg0_00);
      DAT_0203b8fa = (ushort)uVar3;
      DAT_0203b8fc = *(undefined2 *)(&DAT_030046d2 + (uVar5 + 4) * 0x80);
      iVar2 = sub_0815AE84();
      goto joined_r0x0815420a;
    }
    uVar3 = sub_08154968(arg0_00);
    DAT_0203b8f8 = (ushort)uVar3;
    uVar3 = sub_08154968((uint)*(ushort *)(iVar6 + 0x12));
    DAT_0203b8fa = (ushort)uVar3;
    DAT_0203b8fc = 0xffff;
    iVar2 = sub_0815AE84();
    if (arg0_00 != (int)*(short *)(iVar6 + 0x12)) goto joined_r0x0815420a;
  }
  bVar4 = 0x18;
LAB_081542fc:
                    /* WARNING: Could not recover jumptable at 0x0815430a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(bVar4);
  return uVar3;
}


// sub_0815430C @ 0x0815430C

undefined4 sub_0815430C(uint arg0)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = (int *)&DAT_0203a470;
  while ((*piVar2 == 0 || ((int)*(short *)(*piVar2 + 0x12) != (arg0 & 0xffff)))) {
    piVar2 = piVar2 + 1;
    uVar1 = uVar1 + 1;
    if (0xb < uVar1) {
      return 0;
    }
  }
  return uVar1 & 0xffff;
}


// sub_08154344 @ 0x08154344

undefined4 sub_08154344(uint arg0)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while (((iVar1 = sub_080C09B0(uVar2 + 4), iVar1 == 0 || (iVar1 = sub_080C0830(), iVar1 != 0)) ||
         ((int)(short)(&DAT_030048d2)[uVar2 * 0x40] != (arg0 & 0xffff)))) {
    uVar2 = uVar2 + 1;
    if (0xb < uVar2) {
      return 0;
    }
  }
  return uVar2 & 0xffff;
}


// sub_0815438C @ 0x0815438C

void sub_0815438C(uint arg0,uint arg1,uint arg2,uint arg3)

{
  uint uVar1;
  uint arg0_00;
  undefined4 arg3_00;
  
  uVar1 = sub_081540B8(arg0 & 0xffff,arg1 & 0xffff);
  arg0_00 = uVar1 & 0xf;
  arg3_00 = 0;
  uVar1 = (uVar1 & 0xff) >> 4;
  if (uVar1 != 1) {
    if (uVar1 < 2) {
      if (uVar1 == 0) {
        arg3_00 = 8;
      }
    }
    else if (uVar1 == 2) {
      arg3_00 = 10;
    }
  }
  if (((arg0_00 == 6) || (arg0_00 == 8)) || (arg0_00 == 5)) {
    arg3_00 = 0;
  }
  sub_08154038(arg0_00,arg2 & 0xffff,arg3 & 0xffff,arg3_00);
  return;
}


// sub_081543E8 @ 0x081543E8

void sub_081543E8(short *arg0,uint arg1,uint arg2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint arg2_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg2_00 = 0x96;
  uVar2 = sub_08153F3C();
  if ((*arg0 == 1) || ((*arg0 == 5 && (arg0[4] == 1)))) {
    uVar2 = 0;
    do {
      iVar3 = sub_080C09B0(uVar2 + 4);
      if ((iVar3 != 0) && (iVar3 = sub_080C0830(), iVar3 == 0)) {
        sub_0815438C((uint)*(ushort *)(*(int *)(arg0 + (arg1 & 0xffff) * 2 + 0xe) + 0x12),uVar2,
                     arg2_00,arg2 & 0xffff);
        arg2_00 = arg2_00 + 6 & 0xffff;
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < 0xc);
  }
  else {
    uVar5 = 0;
    if ((uVar2 & 0xffff) != 0) {
      do {
        uVar1 = *(ushort *)(*(int *)(arg0 + (arg1 & 0xffff) * 2 + 0xe) + 0x12);
        uVar4 = sub_0815430C((uint)*(ushort *)(*(int *)(arg0 + uVar5 * 2 + 0xe) + 0x12));
        sub_0815438C((uint)uVar1,uVar4 & 0xffff,arg2_00,arg2 & 0xffff);
        uVar5 = uVar5 + 1 & 0xffff;
        arg2_00 = arg2_00 + 6 & 0xffff;
      } while (uVar5 < (uVar2 & 0xffff));
    }
  }
                    /* WARNING: Could not recover jumptable at 0x081544a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081544AC @ 0x081544AC

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 sub_081544AC(undefined4 arg0)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = (uint)(ushort)arg0;
  uVar2 = sub_08153F3C();
  uVar2 = uVar2 & 0xffff;
  if ((DAT_0203a454 == 2) && (_DAT_0203a45c == 0)) {
    uVar6 = 0;
    if (uVar2 != 0) {
      do {
        uVar3 = sub_081540B8(arg0_00,uVar6);
        if (((uVar3 & 0xf) != 6) && ((uVar3 & 0xf) != 8)) goto LAB_08154684;
        uVar6 = uVar6 + 1 & 0xffff;
      } while (uVar6 < uVar2);
    }
  }
  else if (DAT_0203a454 == 3) {
    if (_DAT_0203a45c != 1) {
      if (_DAT_0203a45c != 0) goto LAB_08154554;
      goto LAB_08154684;
    }
    uVar6 = 0;
    if (uVar2 != 0) {
      do {
        uVar3 = sub_0815430C((uint)*(ushort *)(*(int *)(&DAT_0203a470 + uVar6 * 4) + 0x12));
        uVar3 = sub_081540B8(arg0_00,uVar3 & 0xffff);
        if (((uVar3 & 0xf) != 6) && ((uVar3 & 0xf) != 8)) goto LAB_08154684;
        uVar6 = uVar6 + 1 & 0xffff;
      } while (uVar6 < uVar2);
    }
  }
  else {
LAB_08154554:
    if ((DAT_0203a454 == 2) && (_DAT_0203a45c == 1)) {
      uVar1 = *(ushort *)(DAT_0203a4a0 + 0x12);
      uVar2 = sub_0815430C(arg0_00);
      uVar2 = sub_081540B8((uint)uVar1,uVar2 & 0xffff);
    }
    else if ((DAT_0203a454 == 3) && (_DAT_0203a45c == 2)) {
      uVar1 = *(ushort *)(DAT_0203a4a4 + 0x12);
      uVar2 = sub_0815430C(arg0_00);
      uVar2 = sub_081540B8((uint)uVar1,uVar2 & 0xffff);
    }
    else if ((DAT_0203a454 == 4) && (_DAT_0203a45c == 1)) {
      uVar6 = (uint)DAT_0203b854;
      uVar2 = sub_0815430C(arg0_00);
      uVar2 = sub_081540B8(uVar6,uVar2 & 0xffff);
    }
    else {
      if ((DAT_0203a454 != 1) || (_DAT_0203a45c != 1)) {
        if ((DAT_0203a454 == 5) && (_DAT_0203a45c == 2)) {
          uVar5 = sub_08154968((uint)DAT_0203b854);
          DAT_0203b8f8 = (undefined2)uVar5;
          uVar5 = sub_08154968((uint)DAT_0203b856);
          DAT_0203b8fa = (undefined2)uVar5;
          DAT_0203b8fc = (ushort)arg0;
          iVar4 = sub_0815AE84();
          if (iVar4 == 0) goto LAB_08154678;
        }
        goto LAB_08154684;
      }
      uVar6 = (uint)DAT_0203b854;
      uVar2 = sub_08154344(arg0_00);
      uVar2 = sub_081540B8(uVar6,uVar2 & 0xffff);
    }
    if (((uVar2 & 0xf) != 6) && ((uVar2 & 0xf) != 8)) {
LAB_08154684:
      uVar5 = 1;
      goto LAB_08154686;
    }
  }
LAB_08154678:
  uVar5 = 0;
LAB_08154686:
                    /* WARNING: Could not recover jumptable at 0x0815468a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*UNRECOVERED_JUMPTABLE)(uVar5);
  return uVar5;
}


// sub_0815468C @ 0x0815468C

void sub_0815468C(void)

{
  Field_SetState(0x19);
  return;
}


// sub_08154698 @ 0x08154698

void sub_08154698(void)

{
  DAT_0203a460 = sub_080B6B58(0x815468d,0);
  return;
}


// sub_081546B4 @ 0x081546B4

void sub_081546B4(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(*(int *)(DAT_0203a460 + 0xc) == -1);
  return;
}


// sub_081546D8 @ 0x081546D8

void sub_081546D8(void)

{
  *(undefined4 *)(DAT_0203a460 + 0xc) = 1;
  return;
}


// sub_081546E8 @ 0x081546E8

undefined4 sub_081546E8(uint arg0,uint arg1,uint arg2)

{
  char *pcVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080C0148(0x8000);
  pcVar1 = (char *)sub_080BF648(arg0 & 0xffff);
  if (((*pcVar1 < '\x1b') || (pcVar1 = (char *)sub_080BF648(arg1 & 0xffff), *pcVar1 < '\x1b')) ||
     (pcVar1 = (char *)sub_080BF648(arg2 & 0xffff), *pcVar1 < '\x1b')) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0815473a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_0815473C @ 0x0815473C

undefined4 sub_0815473C(uint arg0,uint arg1,uint arg2,uint arg3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint arg0_00;
  
  arg0_00 = arg3 & 0xffff;
  iVar2 = sub_080C0148(0x8000);
  iVar3 = sub_080C3560(arg0_00);
  if (((((iVar3 == 0) || ((arg0 & 0xffff) == arg0_00)) || ((arg1 & 0xffff) == arg0_00)) ||
      ((arg2 & 0xffff) == arg0_00)) && (uVar4 = sub_08134C3C(), (short)uVar4 != 1)) {
    if ((DAT_0203a454 == 3) &&
       (iVar3 = sub_081546E8(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff), iVar3 == 1)) {
      bVar1 = *(byte *)(iVar2 + 0xd);
      iVar2 = sub_080BF648(arg0_00);
      if ((uint)*(byte *)(iVar2 + 1) <= bVar1 + 9) {
        return 1;
      }
    }
    else {
      iVar3 = sub_080BF648(arg0_00);
      if (*(byte *)(iVar3 + 1) <= *(byte *)(iVar2 + 0xd)) {
        return 1;
      }
    }
  }
  return 0;
}


// sub_081547D8 @ 0x081547D8

void sub_081547D8(uint arg0,uint arg1,uint arg2,uint arg3)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint arg0_00;
  uint arg3_00;
  
  arg0_00 = arg0 & 0xffff;
  uVar2 = arg1 & 0xffff;
  arg3_00 = arg2 & 0xffff;
  pcVar1 = (char *)sub_080BF648(arg0_00);
  Race_GetName((int)*pcVar1 & 0xffff);
  uVar3 = 0;
  if (*(short *)(pcVar1 + 0x22) != 0) {
    do {
      if (arg0_00 != 0xff) {
        if (*pcVar1 == ',') {
          if ((((arg0_00 == 0x150) || (arg0_00 == 0x155)) || (arg0_00 == 0x168)) ||
             (arg0_00 == 0x169)) {
            sub_08153FC8((uint)*(ushort *)(pcVar1 + uVar3 * 2 + 0x22),0x200f874,
                         uVar3 * 10 + uVar2 & 0xffff,arg3_00 - 1 & 0xffff);
          }
          else {
            Font_DrawGlyphTinted
                      ((uint)*(ushort *)(pcVar1 + uVar3 * 2 + 0x22),0x200f874,
                       uVar3 * 0xc + uVar2 + 4 & 0xffff,arg3_00);
          }
        }
        else {
          sub_08153FC8((uint)*(ushort *)(pcVar1 + uVar3 * 2 + 0x22),0x200f874,
                       uVar3 * 10 + uVar2 & 0xffff,arg3_00);
          if (uVar3 == 0) {
            sub_081549BC((uint)(byte)pcVar1[1],0xe0,arg3_00 + 5 & 0xffff,arg3 & 0xffff);
          }
        }
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while ((uVar3 < 8) && (*(short *)(pcVar1 + uVar3 * 2 + 0x22) != 0));
  }
  return;
}


// sub_08154900 @ 0x08154900

void sub_08154900(undefined4 arg0,uint arg1)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  uVar1 = (arg1 & 0xffff) + 2;
  do {
    Font_DrawGlyphTinted(8,0x200f874,(uint)(ushort)((short)arg0 + uVar2 * 8 + 3),uVar1 & 0xffff);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  uVar2 = 0;
  do {
    Font_DrawGlyphTinted(8,0x200f874,(uint)(ushort)((short)arg0 + uVar2 * 8 + 0x55),uVar1 & 0xffff);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 2);
  return;
}


// sub_08154968 @ 0x08154968

uint sub_08154968(uint arg0)

{
  return (uint)*(ushort *)(&DAT_087e1956 + (arg0 & 0xffff) * 2);
}


// sub_08154980 @ 0x08154980

dword sub_08154980(undefined4 arg0)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    sVar1 = *(short *)(uVar2 * 2 + 0x87e1bf6);
    if (sVar1 == -1) {
      return 0xffff;
    }
    if (sVar1 == (short)arg0) break;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return uVar2 + 0x150 & 0xffff;
}


// sub_081549BC @ 0x081549BC

void sub_081549BC(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  uint arg2_00;
  char local_18;
  char local_17;
  undefined1 local_16;
  
  arg2_00 = arg1 & 0xffff;
  sub_080A9CC0(arg0 & 0xffff);
  if ((arg0 & 0xffff) < 10) {
    local_17 = '\0';
    arg2_00 = arg2_00 + 8 & 0xffff;
    local_18 = DAT_030020e8;
  }
  else {
    local_17 = DAT_030020e8 + '0';
    local_16 = 0;
    local_18 = DAT_030020e9;
  }
  local_18 = local_18 + '0';
  sub_080ACBC8(&local_18,0x200f874,arg2_00,arg2 & 0xffff);
  return;
}


// sub_08154A38 @ 0x08154A38

void sub_08154A38(short *arg0,uint arg1,uint arg2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  dword arg2_00;
  uint uVar6;
  ushort *arg3;
  undefined4 uVar7;
  ushort *puVar8;
  uint arg3_00;
  code *UNRECOVERED_JUMPTABLE;
  ushort uStack_3c;
  ushort uStack_3a;
  ushort uStack_38;
  ushort uStack_36;
  ushort uStack_34;
  ushort uStack_32;
  uint local_30;
  int iStack_2c;
  uint uStack_28;
  char *pcStack_24;
  
  local_30 = arg1 & 0xffff;
  arg3_00 = arg2 & 0xffff;
  iVar3 = *(int *)(arg0 + local_30 * 2 + 0xe);
  if (iVar3 == 0) goto LAB_08154eb0;
  pcVar4 = (char *)sub_080BF648((uint)*(ushort *)(iVar3 + 0x12));
  iStack_2c = Race_GetName((int)*pcVar4 & 0xffff);
  sub_081544AC((uint)*(ushort *)(iVar3 + 0x12));
  sub_080AC62C(local_30 * 0x20 + 0x87e13e4,0x200f874,0,3);
  uVar6 = 0;
  pcStack_24 = pcVar4 + 0x22;
  do {
    Font_DrawGlyphTinted
              ((uint)*(ushort *)(uVar6 * 2 + iStack_2c),0x200f874,uVar6 * 0xc0000 + 0xa0000 >> 0x10,
               arg3_00);
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 3);
  uVar6 = 0;
  if (*(short *)(pcVar4 + 0x22) != 0) {
    uStack_28 = (arg3_00 - 2) * 0x10000;
    do {
      if (*pcVar4 == ',') {
        iVar5 = sub_0815BAC4();
        if (iVar5 == 1) {
          Font_DrawGlyphTinted
                    ((uint)*(ushort *)(pcStack_24 + uVar6 * 2),0x200f874,
                     uVar6 * 0xc0000 + 0x300000 >> 0x10,arg3_00);
        }
        else {
          Font_DrawGlyphTinted
                    ((uint)*(ushort *)(pcStack_24 + uVar6 * 2),0x200f874,
                     uVar6 * 0xc0000 + 0x300000 >> 0x10,arg3_00);
        }
      }
      else {
        sub_08153FC8((uint)*(ushort *)(pcStack_24 + uVar6 * 2),0x200f874,
                     uVar6 * 0xa0000 + 0x2c0000 >> 0x10,uStack_28 >> 0x10);
      }
      uVar6 = uVar6 + 1 & 0xffff;
    } while ((uVar6 < 8) && (*(short *)(pcStack_24 + uVar6 * 2) != 0));
  }
  sVar1 = *arg0;
  if ((((sVar1 == 1) || ((sVar1 == 4 || (sVar1 == 5)))) &&
      ((arg0[4] == 0 || ((sVar1 == 5 && (arg0[4] == 1)))))) ||
     (((*arg0 == 2 && (arg0[4] == 0)) || ((*arg0 == 3 && (arg0[4] != 2)))))) {
    if (*pcVar4 == ',') {
      uVar6 = sub_08154968((uint)*(ushort *)(iVar3 + 0x12));
      uVar6 = sub_080C32D4(uVar6 & 0xffff);
      uVar6 = uVar6 & 0xff;
      Font_DrawGlyphTinted(0x115,0x200f874,0x76,arg3_00);
    }
    else {
      uVar6 = (uint)(byte)pcVar4[1];
    }
    sub_081549BC(uVar6,0x82,arg3_00 + 3 & 0xffff,0);
  }
  sVar1 = *arg0;
  if (sVar1 == 1) {
    if (arg0[4] != 0) {
      sub_0815B884((uint)DAT_0203b854,0xffff,(uint)*(ushort *)(iVar3 + 0x12),&uStack_3c);
      DAT_0203b85a = uStack_3c;
      sub_081547D8((uint)uStack_3c,0x7c,arg3_00,0);
      if (uStack_3c == 0xff) goto LAB_08154eb0;
      Font_DrawGlyphTinted(0x115,0x200f874,0xce,arg3_00);
LAB_08154cfc:
      uVar6 = sub_080C32D4((uint)uStack_3a);
      sub_081549BC(uVar6 & 0xff,0xda,arg3_00 + 3 & 0xffff,0);
      goto LAB_08154eb0;
    }
  }
  else if (sVar1 == 4) {
    if (arg0[4] != 0) {
      arg2_00 = 0xffff;
      arg3 = &uStack_38;
      puVar8 = &uStack_36;
      uVar2 = *(ushort *)(iVar3 + 0x12);
LAB_08154cca:
      sub_0815B884((uint)DAT_0203b854,(uint)uVar2,arg2_00,arg3);
      DAT_0203b85a = *arg3;
      sub_081547D8((uint)*arg3,0x7c,arg3_00,0);
      if (*arg3 == 0xff) goto LAB_08154eb0;
      Font_DrawGlyphTinted(0x115,0x200f874,0xce,arg3_00);
      uStack_3a = *puVar8;
      goto LAB_08154cfc;
    }
  }
  else if (sVar1 == 5) {
    if (arg0[4] != 1) {
      if (arg0[4] != 2) goto LAB_08154eb0;
      arg2_00 = (dword)*(ushort *)(iVar3 + 0x12);
      arg3 = &uStack_34;
      puVar8 = &uStack_32;
      uVar2 = DAT_0203b856;
      goto LAB_08154cca;
    }
  }
  else if (sVar1 == 2) {
    if (arg0[4] != 0) {
      DAT_0203b8f8 = *(undefined2 *)(*(int *)(arg0 + 0x26) + 0x12);
      DAT_0203b8fa = *(undefined2 *)(iVar3 + 0x12);
      DAT_0203b8fc = 0xffff;
      sub_0815B4B4();
      sub_08158970();
      DAT_0203b85a = DAT_0203b908;
      uVar2 = *(ushort *)(*(int *)(arg0 + 0x26) + 0x12);
      uVar6 = sub_0815430C((uint)*(ushort *)(iVar3 + 0x12));
      sub_0815438C((uint)uVar2,uVar6 & 0xffff,0x82,arg3_00 + 4 & 0xffff);
      uVar2 = *(ushort *)(*(int *)(arg0 + 0x26) + 0x12);
      uVar6 = sub_0815430C((uint)*(ushort *)(iVar3 + 0x12));
      uVar6 = sub_081540B8((uint)uVar2,uVar6 & 0xffff);
      if ((uVar6 & 0xf) != 5) {
        uVar7 = 0;
        uVar6 = sub_0815473C((uint)*(ushort *)(*(int *)(arg0 + 0x26) + 0x12),
                             (uint)*(ushort *)(iVar3 + 0x12),(uint)*(ushort *)(iVar3 + 0x12),
                             (uint)DAT_0203b908);
        if ((uVar6 & 0xffff) == 0) {
          uVar7 = 4;
        }
        sub_081547D8((uint)DAT_0203b908,0x8a,arg3_00 - 2 & 0xffff,uVar7);
        goto LAB_08154eb0;
      }
LAB_08154e6c:
      sub_08154900(0x8a,arg3_00 - 2 & 0xffff);
      goto LAB_08154eb0;
    }
  }
  else {
    if (sVar1 != 3) goto LAB_08154eb0;
    if (arg0[4] != 1) {
      if (arg0[4] != 2) goto LAB_08154eb0;
      uVar6 = sub_0815430C((uint)*(ushort *)(iVar3 + 0x12));
      DAT_0203b8f8 = *(undefined2 *)(*(int *)(arg0 + 0x26) + 0x12);
      DAT_0203b8fa = *(undefined2 *)(*(int *)(arg0 + 0x28) + 0x12);
      DAT_0203b8fc = *(undefined2 *)(iVar3 + 0x12);
      sub_08154074();
      sub_0815B4B4();
      sub_081596F0();
      DAT_0203b85a = DAT_0203b908;
      if (0xfe < DAT_0203b908) {
        DAT_0203b85a = 0xfb;
      }
      sub_0815438C((uint)*(ushort *)(*(int *)(arg0 + 0x28) + 0x12),uVar6 & 0xffff,0x82,
                   arg3_00 + 4 & 0xffff);
      uVar6 = sub_081540B8((uint)*(ushort *)(*(int *)(arg0 + 0x28) + 0x12),uVar6 & 0xffff);
      if ((uVar6 & 0xf) != 5) {
        uVar7 = 0;
        uVar6 = sub_0815473C((uint)*(ushort *)(*(int *)(arg0 + 0x26) + 0x12),
                             (uint)*(ushort *)(*(int *)(arg0 + 0x28) + 0x12),
                             (uint)*(ushort *)(iVar3 + 0x12),(uint)DAT_0203b908);
        if ((uVar6 & 0xffff) == 0) {
          uVar7 = 4;
        }
        sub_081547D8((uint)DAT_0203b908,0x8a,arg3_00 - 2 & 0xffff,uVar7);
        goto LAB_08154eb0;
      }
      goto LAB_08154e6c;
    }
  }
  sub_081543E8(arg0,local_30,arg3_00 + 4 & 0xffff);
LAB_08154eb0:
                    /* WARNING: Could not recover jumptable at 0x08154ebe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08154EC0 @ 0x08154EC0

void sub_08154EC0(void)

{
  ushort uVar1;
  
  REG_BG1CNT = 0x8205;
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 & 0xfbff;
  DAT_03000040 = 0;
  return;
}


// sub_08154EEC @ 0x08154EEC

void sub_08154EEC(void)

{
  undefined4 uVar1;
  
  sub_08154EC0();
  REG_DMA3SAD = 0x81b93b0;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84001800;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2016874;
  REG_DMA3DAD = 0x6012f00;
  REG_DMA3CNT = 0x84000020;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_08154F4C @ 0x08154F4C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08154F4C(void)

{
  uint uVar1;
  dword arg0;
  uint uVar2;
  undefined4 arg2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_08153F3C();
  uVar1 = uVar1 & 0xffff;
  sub_080ACAB0(0x87e1c2c,0x200f874,10,0x44);
  sub_080ACAB0(0x87e1c34,0x200f874,0x32,0x44);
  if (DAT_0203a454 == 1) {
    if (_DAT_0203a45c == 0) {
      uVar2 = sub_08153E70();
      uVar1 = 0;
      if ((uVar2 & 0xffff) != 0) {
        do {
          uVar3 = uVar1 + 1 & 0xffff;
          sub_08153F8C(uVar3,0x200f874,uVar1 * 0x60000 + 0x960000 >> 0x10,0x44);
          uVar1 = uVar3;
        } while (uVar3 < (uVar2 & 0xffff));
      }
      goto LAB_08155194;
    }
    arg0 = 0x87e1c3c;
LAB_08155110:
    arg2 = 0x82;
  }
  else {
    if (DAT_0203a454 == 4) {
      if (_DAT_0203a45c == 0) {
        uVar2 = 0;
        if (uVar1 != 0) {
          do {
            uVar3 = uVar2 + 1 & 0xffff;
            sub_08153F8C(uVar3,0x200f874,uVar2 * 0x60000 + 0x960000 >> 0x10,0x44);
            uVar2 = uVar3;
          } while (uVar3 < uVar1);
        }
        goto LAB_08155194;
      }
      arg0 = 0x87e1c3c;
      goto LAB_08155110;
    }
    if (DAT_0203a454 == 5) {
      if (_DAT_0203a45c != 2) {
        if (_DAT_0203a45c == 1) {
          uVar2 = sub_08153E70();
          uVar1 = 0;
          if ((uVar2 & 0xffff) != 0) {
            do {
              uVar3 = uVar1 + 1 & 0xffff;
              sub_08153F8C(uVar3,0x200f874,uVar1 * 0x60000 + 0x960000 >> 0x10,0x44);
              uVar1 = uVar3;
            } while (uVar3 < (uVar2 & 0xffff));
          }
        }
        goto LAB_08155194;
      }
      arg0 = 0x87e1c3c;
      goto LAB_08155110;
    }
    if (DAT_0203a454 != 2) {
      if (DAT_0203a454 != 3) goto LAB_08155194;
      if (_DAT_0203a45c != 0) {
        if (_DAT_0203a45c == 1) {
          sub_080ACAB0(0x87e1c44,0x200f874,0x82,0x44);
          uVar2 = 0;
          if (uVar1 != 0) {
            do {
              uVar3 = uVar2 + 1 & 0xffff;
              sub_08153F8C(uVar3,0x200f874,uVar2 * 0x60000 + 0x960000 >> 0x10,0x44);
              uVar2 = uVar3;
            } while (uVar3 < uVar1);
          }
        }
        else if (_DAT_0203a45c == 2) {
          sub_080ACAB0(0x87e1c3c,0x200f874,0x82,0x44);
          sub_080ACAB0(0x87e1c44,0x200f874,0xe0,0x44);
        }
        goto LAB_08155194;
      }
      arg0 = 0x87e1c44;
      goto LAB_08155110;
    }
    if (_DAT_0203a45c == 0) {
      sub_080ACAB0(0x87e1c44,0x200f874,0x82,0x44);
      uVar2 = 0;
      if (uVar1 != 0) {
        do {
          uVar3 = uVar2 + 1 & 0xffff;
          sub_08153F8C(uVar3,0x200f874,uVar2 * 0x60000 + 0x960000 >> 0x10,0x44);
          uVar2 = uVar3;
        } while (uVar3 < uVar1);
      }
      goto LAB_08155194;
    }
    sub_080ACAB0(0x87e1c3c,0x200f874,0x82,0x44);
    arg0 = 0x87e1c44;
    arg2 = 0xe0;
  }
  sub_080ACAB0(arg0,0x200f874,arg2,0x44);
LAB_08155194:
                    /* WARNING: Could not recover jumptable at 0x0815519e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081551A8 @ 0x081551A8

void sub_081551A8(undefined4 arg0)

{
  ushort uVar1;
  
  sub_0815B880();
  uVar1 = 0;
  do {
    sub_08154A38(0x203a454,(uint)(ushort)((short)arg0 + uVar1),(uint)(ushort)(uVar1 * 0xd + 0x4c));
    uVar1 = uVar1 + 1;
  } while (uVar1 < 6);
  DisplayList_Add(0x8154eed,1);
  return;
}


