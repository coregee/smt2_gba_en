/* Ghidra decompilation of asm/code_080C140C.s (reference only; not compiled). */

// sub_080C140C @ 0x080C140C

void sub_080C140C(undefined4 arg0,int arg1)

{
  DAT_03000040 = 0x3c42;
  DAT_03000042 = (ushort)arg0 | (ushort)((uint)(arg1 << 0x10) >> 8);
  DAT_03000044 = 0x10;
  return;
}


// sub_080C1440 @ 0x080C1440

void sub_080C1440(void)

{
  sub_080C140C(0xc,6);
  return;
}


// sub_080C1450 @ 0x080C1450

void sub_080C1450(void)

{
  REG_DISPCNT = 0x7f00;
  REG_BG0CNT = 0x8004;
  REG_BG1CNT = 0x8209;
  REG_BG2CNT = 0x840a;
  REG_BG3CNT = 0x8607;
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x3f;
  DAT_03000000 = 0;
  DAT_03000002 = 0xffff;
  DAT_03000004 = 0;
  DAT_03000006 = 0;
  DAT_03000008 = 0;
  DAT_0300000a = 0;
  DAT_0300000c = 0;
  DAT_0300000e = 0;
  sub_080C1440();
  return;
}


// sub_080C14FC @ 0x080C14FC

void sub_080C14FC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x81b8370;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  sub_080AB1C4(0x2000000,1,0xd,1);
  return;
}


// sub_080C153C @ 0x080C153C

void sub_080C153C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C1560 @ 0x080C1560

void sub_080C1560(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  
  DAT_0200ab04 = 0;
  sub_080C1450();
  sub_080A9AC0();
  local_c = 0;
  REG_DMA3SAD = &local_c;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85001000;
  uVar1 = REG_DMA3CNT;
  sub_080AB78C();
  sub_080C1328();
  DAT_0200e806 = 0;
  sub_080C1384();
  Font_ResetGlyphSpriteCache(0x180);
  sub_080C14FC();
  sub_080C153C();
  sub_080C65E8();
  sub_080C6734();
  sub_080AD7F0();
  iVar2 = DAT_03004544;
  if (DAT_03004544 == 0) {
    sub_080AE234();
    sub_080AE2A8(0,0);
    DAT_03004552 = 0;
    DAT_03004554 = 0;
    DAT_03004514 = iVar2;
    sub_080B30A0();
  }
  sub_080A9AB4(0x80c1631);
  REG_IE._0_2_ = 0x2003;
  REG_DISPSTAT = 0x18;
  REG_IME = 1;
  return;
}


// sub_080C1630 @ 0x080C1630

void sub_080C1630(void)

{
  if (((DAT_03004544 < 2) || (DAT_03004544 == 4)) || (DAT_03004544 == 6)) {
    sub_080AD824((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514,0x3003ff8);
    if (DAT_03003ff8 == 0) {
      sub_080A9AB4(0x80c1685);
    }
  }
  else {
    sub_080A9AB4(0x80c1685);
  }
  return;
}


// sub_080C1684 @ 0x080C1684

void sub_080C1684(void)

{
  int iVar1;
  uint uVar2;
  int local_10;
  
  if (DAT_03004544 == 0) {
    DAT_03004514 = DAT_03004544;
  }
  sub_080ADFEC(DAT_03004544 & 0xffff);
  sub_080ACFF4();
  sub_080AE364(DAT_03004544 & 0xffff);
  DAT_0200e808 = 1;
  if (((DAT_03004544 == 4) &&
      (((iVar1 = sub_080B3078(0,0,0x12), iVar1 == 1 || (iVar1 = sub_080B3078(0,0,0x13), iVar1 == 1))
       || (iVar1 = sub_080B3078(0,0,0x1e), iVar1 == 1)))) &&
     (iVar1 = sub_080AF8D0(1,1,0), iVar1 != 0)) {
    DAT_030029b0 = 0;
    sub_080ACFA4(3,0,&DAT_03002b70,0x40);
    sub_080ACFA4(3,0,&DAT_03002b50,0x20);
  }
  if (DAT_03005180 == 0) {
    iVar1 = sub_080D0E74();
    if (iVar1 == 1) {
      sub_080C5170(0);
    }
    else {
      uVar2 = sub_080AD608();
      sub_080C5170(uVar2 & 0xffff);
    }
  }
  else {
    uVar2 = sub_080AD67C((uint)DAT_030069f8);
    sub_080C5170(uVar2 & 0xffff);
  }
  sub_080E44A4();
  if (DAT_03004544 == 5) {
    Field_SetState((uint)(ushort)DAT_030045fc);
    sub_080A9AB4(0x80c1851);
  }
  else {
    sub_080AAEDC(1);
    if (((DAT_03004614 == 0) && (DAT_03004562 == 2)) && (DAT_03004564 == 6)) {
      local_10 = DAT_03004614;
      CpuSet(&local_10,0x3002b50,0x5000018);
    }
    sub_080A9AB4(0x80c17f1);
  }
  return;
}


// sub_080C17F0 @ 0x080C17F0

void sub_080C17F0(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = sub_080AB184();
  if ((uVar1 & 0xffff) == 1) {
    DAT_0200e808 = 0;
    Field_SetState((uint)(ushort)DAT_030045fc);
    sub_080A9AB4(0x80c1851);
    if ((DAT_03004544 == 4) || (iVar2 = sub_080D0E74(), iVar2 == 1)) {
      DAT_03003ff4 = (undefined2)uVar1;
      sub_080AF8D0(1,2,0);
      DAT_03003ff4 = 0;
    }
  }
  sub_080C1850();
  return;
}


// sub_080C1850 @ 0x080C1850

void sub_080C1850(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080C104C();
  DAT_03005183 = (undefined1)uVar1;
  sub_080E5220();
  sub_080B0C90();
  sub_080AD01C();
  sub_080C6804();
  sub_080C22E4();
  return;
}


// sub_080C1880 @ 0x080C1880

void sub_080C1880(void)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined2 local_1c [2];
  
  DAT_0200ab04 = 1;
  sub_080C1450();
  sub_080A9AC0();
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 & 0xfeff;
  REG_BG1CNT = 0x209;
  REG_BG2CNT = 0x406;
  REG_BG3CNT = 0x607;
  DAT_03000002 = 0;
  DAT_03000040 = 0x3c46;
  DAT_03000030 = 0x88;
  DAT_03000031 = 0x68;
  DAT_03000034 = 0x60;
  DAT_03000035 = 0x40;
  DAT_03000038 = 0x3f;
  DAT_03000032 = 0x39;
  DAT_03000033 = 10;
  DAT_03000036 = 0x17;
  DAT_03000037 = 3;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x1f;
  local_1c[0] = 0x3b3;
  REG_DMA3SAD = local_1c;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x81000800;
  uVar2 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000400;
  uVar2 = REG_DMA3CNT;
  sub_080AB250(0x81b8270,0x2000000,0,0);
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar2 = REG_DMA3CNT;
  sub_080AB78C();
  sub_080C1328();
  DAT_0200e806 = 0;
  sub_080C1384();
  sub_080C2EFC();
  Font_ResetGlyphSpriteCache(0x100);
  REG_IE._0_2_ = 0x2003;
  REG_DISPSTAT = 0x18;
  REG_IME = 1;
  sub_080ACFF4();
  sub_080C7CC8();
  sub_08151EEC((uint)(ushort)DAT_03003fc4,(uint)(ushort)DAT_03004618,(uint)(ushort)DAT_03004624);
  uVar3 = sub_080AD67C((uint)DAT_030069f8);
  sub_080C5170(uVar3 & 0xffff);
  sub_080A9AB4(0x80c1a59);
  return;
}


// sub_080C1A58 @ 0x080C1A58

void sub_080C1A58(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_080C5108();
  if (iVar1 == 0) {
    sub_080B9058();
    sub_080C1A9C();
    sub_080A9AB4(0x80c1a9d);
  }
  uVar2 = sub_080C104C();
  DAT_03005183 = (undefined1)uVar2;
  sub_080C7CD8();
  sub_0815201C();
  sub_080AD01C();
  sub_080C22E4();
  return;
}


// sub_080C1A9C @ 0x080C1A9C

void sub_080C1A9C(void)

{
  sub_080C7CD8();
  sub_080AD01C();
  sub_080C22E4();
  return;
}


// sub_080C1AB0 @ 0x080C1AB0

void sub_080C1AB0(void)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = DAT_03005f94;
  uVar2 = sub_080C1D9C();
  if (cVar1 == '\x01') {
    if ((uVar2 & 0xf0) != 0) {
      DAT_03005f94 = '\x02';
    }
  }
  else if ((cVar1 == '\x02') && ((uVar2 & 0xf0) == 0)) {
    sub_080C245C(0xff);
    DAT_03005f94 = '\0';
  }
  return;
}


// sub_080C1AF4 @ 0x080C1AF4

void sub_080C1AF4(void)

{
  uint uVar1;
  uint uVar2;
  
  sub_080C1DB0();
  if (DAT_03005180 == 1) {
    uVar1 = sub_080C1D9C();
    sub_080C1AB0();
    uVar2 = sub_080C1D9C();
    if ((uVar2 & 0xf0) == 0) {
      sub_080F3F58(0xfffffeff);
    }
    else if ((uVar1 & 0xff) == 0x80) {
      sub_080F3F58(0xffffffbf);
      sub_080F3F58(0xffffffdf);
    }
  }
  return;
}


// sub_080C1B50 @ 0x080C1B50

undefined4 sub_080C1B50(void)

{
  undefined4 uVar1;
  
  if ((DAT_0300474e & 0x8000) == 0) {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// sub_080C1B74 @ 0x080C1B74

undefined4 sub_080C1B74(undefined2 *arg0,undefined2 *arg1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  byte bVar4;
  
  bVar4 = 0;
  uVar1 = sub_080C1D9C();
  if ((uVar1 & 0xf0) == 0x80) {
    iVar2 = sub_080C2340(0xcf);
    if (iVar2 != 0) {
      iVar2 = sub_080C2340(0xe2);
      bVar4 = iVar2 != 0;
      if ((bool)bVar4) {
        uVar3 = sub_080C1CAC(0);
        *arg0 = (short)uVar3;
      }
      iVar2 = sub_080C2340(0xe3);
      if (iVar2 != 0) {
        uVar1 = sub_080C1B50();
        uVar3 = sub_080C1CAC(uVar1 & 0xffff);
        *arg1 = (short)uVar3;
        bVar4 = bVar4 | 2;
      }
      iVar2 = sub_080F2F64(0x8000);
      *(undefined1 *)(iVar2 + 0x38) = 0;
      *(undefined1 *)(iVar2 + 0x39) = 0;
      *(undefined1 *)(iVar2 + 0x3a) = 0;
      *(undefined1 *)(iVar2 + 0x3b) = 0;
      *(undefined1 *)(iVar2 + 0x3c) = 0;
      *(undefined1 *)(iVar2 + 0x3d) = 0;
      sub_080BF938((uint)*(byte *)(iVar2 + 0xc));
      iVar2 = sub_080C1B50();
      iVar2 = sub_080F2F64(iVar2 + 0x8000U & 0xffff);
      *(undefined1 *)(iVar2 + 0x38) = 0;
      *(undefined1 *)(iVar2 + 0x39) = 0;
      *(undefined1 *)(iVar2 + 0x3a) = 0;
      *(undefined1 *)(iVar2 + 0x3b) = 0;
      *(undefined1 *)(iVar2 + 0x3c) = 0;
      *(undefined1 *)(iVar2 + 0x3d) = 0;
      sub_080BF938((uint)*(byte *)(iVar2 + 0xc));
      sub_080C23BC(0xe2);
      sub_080C23BC(0xe3);
      sub_080C23BC(0xcf);
      sub_080CDC34();
    }
  }
  else {
    iVar2 = sub_080C2340(0xe2);
    if ((iVar2 != 0) || (iVar2 = sub_080C2340(0xe3), iVar2 != 0)) {
      sub_080C2364(0xcf);
    }
  }
  if (DAT_03005f75 != -1) {
    uVar1 = sub_080C1D9C();
    if ((uVar1 & 0xf0) != (uint)DAT_03005f74) {
      DAT_03005f74 = (byte)(uVar1 & 0xf0);
      DAT_03005f75 = DAT_03005f75 + -1;
      if (DAT_03005f75 == '\0') {
        sub_080C2364((uint)*(ushort *)((uint)DAT_03005f76 * 2 + 0x81a6264));
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080c1c96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(bVar4);
  return uVar3;
}


// sub_080C1CAC @ 0x080C1CAC

uint sub_080C1CAC(int arg0)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_080F2F64(arg0 * 0x10000 + 0x80000000U >> 0x10);
  uVar2 = sub_080C2244();
  if ((uVar2 & 7) == 0) {
    uVar2 = 4;
    sub_080C08F8((uint)*(byte *)(iVar1 + 0xc),4);
  }
  else {
    uVar2 = (uint)*(ushort *)((uVar2 & 3) * 2 + 0x81a626a);
    sub_080C08F8((uint)*(byte *)(iVar1 + 0xc),uVar2);
  }
  sub_080C84A0();
  return uVar2;
}


// sub_080C1D00 @ 0x080C1D00

void sub_080C1D00(undefined4 arg0)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  DAT_030050ea = DAT_030050e8;
  DAT_030050e8 = (short)arg0 + DAT_030050e8;
  if (0xff < DAT_030050e8) {
    DAT_030050e8 = DAT_030050e8 & 0xff;
  }
  sub_080C1AF4();
  uVar2 = sub_080F3F44();
  bVar1 = DAT_03005f7b;
  if ((uVar2 & 0x80) != 0) {
    uVar2 = (uint)DAT_03005f7b;
    if ((DAT_03005f7b & 1) == 0) {
      uVar3 = sub_080C1D9C();
      if ((uVar3 & 0xf0) == (uVar2 & 0xf0)) {
        sub_080F3F58(0xffffff7f);
        bVar1 = 0;
      }
    }
    else {
      uVar3 = sub_080C1D9C();
      if ((uVar3 & 0xf0) != (uVar2 & 0xf0)) {
        bVar1 = bVar1 + 1;
      }
    }
  }
  DAT_03005f7b = bVar1;
  return;
}


// sub_080C1D9C @ 0x080C1D9C

uint sub_080C1D9C(void)

{
  return (uint)DAT_030050e8;
}


// sub_080C1DB0 @ 0x080C1DB0

void sub_080C1DB0(void)

{
  sub_080C1D9C();
  return;
}


// sub_080C1DE0 @ 0x080C1DE0

void sub_080C1DE0(void)

{
  uint uVar1;
  
  sub_080C1D00(2);
  uVar1 = sub_080C4F88((uint)DAT_030050fe);
  if ((uVar1 & 0xffff) != 0) {
    sub_080B8B68(0x1f,1);
    sub_080C51D4(299);
  }
  DAT_030050fe = DAT_030050fe + 1;
  return;
}


// sub_080C1E20 @ 0x080C1E20

undefined4 sub_080C1E20(void)

{
  undefined4 uStack_c;
  
  uStack_c = 0;
  sub_080C1D00(1);
  sub_080C1E60(&uStack_c);
  sub_080C4E48((uint)DAT_030050f6,&uStack_c);
  DAT_030050f6 = DAT_030050f6 + 1;
  sub_080C4C98();
  return uStack_c;
}


// sub_080C1E60 @ 0x080C1E60

void sub_080C1E60(uint *arg0)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint arg0_00;
  
  iVar2 = sub_080C3168();
  if (iVar2 == 0) {
    iVar2 = 0;
    do {
      bVar1 = *(byte *)(iVar2 + 0x30050e0);
      iVar5 = (int)(char)bVar1;
      if ((iVar5 != -1) && (3 < iVar5)) {
        iVar4 = sub_080F401C(iVar5);
        if (iVar4 == 1) {
          *arg0 = *arg0 | 1 << (uint)bVar1;
        }
        sub_080C0C70(iVar5,1);
        sub_080C8490(iVar2);
        DAT_0200e844 = 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 6);
    if (DAT_0200e844 != 0) {
      sub_080C51D4(299);
    }
  }
  else {
    arg0_00 = (uint)DAT_03005184;
    iVar2 = 0;
    do {
      iVar5 = (int)(char)(&DAT_030050e0)[iVar2];
      if ((iVar5 != -1) && (3 < iVar5)) {
        uVar3 = sub_080C07E0(iVar5);
        iVar5 = sub_080ED584((int)(short)uVar3);
        arg0_00 = arg0_00 + iVar5;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 6);
    uVar3 = __modsi3(arg0_00,10);
    DAT_03005184 = (ushort)uVar3;
    iVar2 = __divsi3(arg0_00,10);
    iVar2 = sub_080C3114(-iVar2);
    if (iVar2 == 0) {
      DAT_03005184 = 0;
    }
  }
  return;
}


// sub_080C1F50 @ 0x080C1F50

void sub_080C1F50(undefined4 arg0,undefined4 arg1,short *arg2,short *arg3)

{
  int iVar1;
  
  iVar1 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  *arg2 = (short)arg0 + *(short *)(iVar1 + 8);
  *arg3 = (short)arg1 + *(short *)(iVar1 + 10);
  return;
}


// sub_080C1F94 @ 0x080C1F94

int sub_080C1F94(undefined4 arg0,int arg1)

{
  int iVar1;
  int iVar2;
  
  if (arg1 == 0) {
    arg1 = 1;
  }
  iVar1 = __modsi3(arg0,arg1);
  iVar2 = __divsi3(arg0,arg1);
  return iVar2 + (uint)(arg1 / 2 <= iVar1);
}


// sub_080C1FC8 @ 0x080C1FC8

void sub_080C1FC8(undefined2 *arg0)

{
  undefined2 *in_r1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_03003fc4 == 1) {
    *in_r1 = 0;
    *arg0 = 0x48;
  }
  else if (DAT_03003fc4 == 0) {
    *in_r1 = 0;
    *arg0 = 0x28;
  }
  else if ((DAT_03003fc4 == 2) || (DAT_03003fc4 == 3)) {
    *arg0 = 0;
    *in_r1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080c1ffe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C2000 @ 0x080C2000

undefined4 sub_080C2000(int arg0)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack_18;
  undefined1 auStack_14 [4];
  
  uVar1 = sub_080F3F44();
  if ((uVar1 & 0x80) == 0) {
LAB_080c2084:
    uVar3 = 0;
  }
  else {
    if (arg0 == 0) {
      uVar1 = sub_080C5D0C();
      uVar1 = uVar1 & 0x7f;
      if (0x6b < uVar1) {
        uVar1 = 0x3e;
      }
      sub_080ED398(&uStack_18,auStack_14,uVar1);
    }
    else {
      sub_080F450C(&uStack_18,auStack_14);
    }
    uVar1 = sub_080ED5B4(uStack_18,0);
    uVar2 = sub_080ED5B4(uStack_18,1);
    uVar3 = sub_080C0F8C(0);
    iVar4 = sub_080BF648(uVar1 & 0xffff);
    if ((short)uVar3 <= (short)(ushort)*(byte *)(iVar4 + 1)) {
      uVar3 = sub_080C0F8C(0);
      iVar4 = sub_080BF648(uVar2 & 0xffff);
      if ((short)uVar3 <= (short)(ushort)*(byte *)(iVar4 + 1)) goto LAB_080c2084;
    }
    uVar3 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080c208c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar3);
  return uVar3;
}


// sub_080C2090 @ 0x080C2090

uint sub_080C2090(void)

{
  int iVar1;
  
  iVar1 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  return (uint)*(ushort *)(iVar1 + (uint)DAT_030050f8 * 0xe8 + 0x178);
}


// sub_080C20C8 @ 0x080C20C8

void sub_080C20C8(void)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C2340(0xff);
  if ((iVar1 == 0) && (iVar1 = sub_080C2090(), iVar1 != 1)) {
    uVar2 = 1;
  }
  else {
    sub_080C2230(0);
    uVar2 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080c20ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}


// sub_080C20EC @ 0x080C20EC

void sub_080C20EC(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  int iVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = sub_080C5D0C();
  uVar3 = uVar3 & 0x7f;
  uVar4 = sub_080C2244();
  DAT_0203a450 = (undefined2)uVar4;
  uVar4 = sub_080C2244();
  DAT_0203a452 = (undefined2)uVar4;
  if (0x6b < uVar3) {
    uVar3 = 0x3e;
  }
  pbVar5 = (byte *)sub_080C5D48(uVar3);
  bVar1 = *pbVar5;
  if ((bVar1 == 0) || (iVar6 = sub_080C2340(0xff), iVar6 != 0)) {
LAB_080c2146:
    sub_080C2230(0);
  }
  else {
    if (pbVar5[1] != 0) {
      iVar6 = sub_080C2340((uint)pbVar5[1]);
      if (iVar6 == 0) {
        bVar2 = pbVar5[3];
      }
      else {
        bVar2 = pbVar5[2];
      }
      if (bVar2 == 0xff) goto LAB_080c2146;
    }
    uVar3 = sub_080C221C();
    sub_080C2230((uVar3 & 0xffff) + (uint)bVar1 * 2 & 0xffff);
  }
                    /* WARNING: Could not recover jumptable at 0x080c2164. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C2168 @ 0x080C2168

void sub_080C2168(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  pbVar3 = (byte *)sub_080C5D98();
  bVar1 = *pbVar3;
  uVar4 = sub_080C2244();
  DAT_0203a450 = (undefined2)uVar4;
  uVar4 = sub_080C2244();
  DAT_0203a452 = (undefined2)uVar4;
  if ((bVar1 == 0) || (iVar5 = sub_080C2340(0xff), iVar5 != 0)) {
LAB_080c21ae:
    sub_080C2230(0);
  }
  else {
    if (pbVar3[1] != 0) {
      iVar5 = sub_080C2340((uint)pbVar3[1]);
      if (iVar5 == 0) {
        bVar2 = pbVar3[3];
      }
      else {
        bVar2 = pbVar3[2];
      }
      if (bVar2 == 0xff) goto LAB_080c21ae;
    }
    uVar6 = sub_080C221C();
    sub_080C2230((uVar6 & 0xffff) + (uint)bVar1 * 2 & 0xffff);
  }
                    /* WARNING: Could not recover jumptable at 0x080c21cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C21D0 @ 0x080C21D0

undefined4 sub_080C21D0(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = sub_080C221C();
  uVar1 = uVar1 & 0xffff;
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else if ((uVar1 - 1 & 0xffff) < 0xfa) {
    uVar2 = 1;
  }
  else if ((uVar1 - 0xfb & 0xffff) < 0xfa) {
    uVar2 = 2;
  }
  else {
    uVar2 = 4;
    if ((uVar1 - 0x1f5 & 0xffff) < 0xfa) {
      uVar2 = 3;
    }
  }
  return uVar2;
}


// sub_080C221C @ 0x080C221C

uint sub_080C221C(void)

{
  return (uint)DAT_030051aa;
}


// sub_080C2230 @ 0x080C2230

void sub_080C2230(undefined4 arg0)

{
  DAT_030051aa = (undefined2)arg0;
  return;
}


// sub_080C2244 @ 0x080C2244

uint sub_080C2244(void)

{
  uint uVar1;
  
  uVar1 = sub_080AC468();
  return uVar1 & 0xff;
}


// sub_080C2254 @ 0x080C2254

void sub_080C2254(int arg0,int arg1)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C1F94(arg1 + 3,4);
  uVar2 = sub_080C2244();
                    /* WARNING: Could not recover jumptable at 0x080c227e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0xfe < (int)((uVar2 & 0xf) * (iVar1 + 10) + arg0));
  return;
}


// sub_080C2280 @ 0x080C2280

undefined4 sub_080C2280(undefined4 arg0)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C2340(0xff);
  if ((iVar1 == 0) && (iVar1 = sub_080C2000((uint)((short)arg0 != 0)), iVar1 == 0)) {
    uVar2 = sub_080C221C();
    if ((short)arg0 == 0) {
      sub_080C2244();
    }
    else {
      uVar2 = __divsi3((int)(short)uVar2,10);
      sub_080C2254((int)(short)uVar2,1);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080c22e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)();
  return uVar2;
}


// sub_080C22E4 @ 0x080C22E4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080C22E4(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = _DAT_030051a4;
  bVar2 = DAT_030051a7 + 1;
  _DAT_030051a4 = CONCAT13(bVar2,_DAT_030051a4);
  if (0x3b < bVar2) {
    _DAT_030051a4 = uVar1 & 0xffffff;
    _DAT_030051a4 = CONCAT12(DAT_030051a6 + '\x01',_DAT_030051a4);
    _DAT_030051a4 = (uint)_DAT_030051a4;
  }
  if (0x3b < DAT_030051a6) {
    uVar1 = _DAT_030051a4 >> 0x10;
    _DAT_030051a4 = CONCAT11(DAT_030051a5 + '\x01',DAT_030051a4);
    _DAT_030051a4 = CONCAT22((short)uVar1,_DAT_030051a4) & 0xff00ffff;
  }
  if (0x3b < DAT_030051a5) {
    _DAT_030051a4 = CONCAT31((int3)(_DAT_030051a4 >> 8),DAT_030051a4 + '\x01') & 0xffff00ff;
  }
  if (_DAT_030051a4 == 0) {
    _DAT_030051a4 = 0x3b3b3bff;
  }
  return;
}


// sub_080C2338 @ 0x080C2338

void sub_080C2338(void)

{
  return;
}


// sub_080C2340 @ 0x080C2340

uint sub_080C2340(uint arg0)

{
  return (int)(uint)(byte)(&DAT_03005ca8)[arg0 >> 3] >> (arg0 & 7) & 1;
}


// sub_080C2364 @ 0x080C2364

void sub_080C2364(uint arg0)

{
  byte *pbVar1;
  uint uVar2;
  
  (&DAT_03005ca8)[arg0 >> 3] = (byte)(1 << (arg0 & 7)) | (&DAT_03005ca8)[arg0 >> 3];
  sub_080C90FC();
  uVar2 = arg0 - 0x120;
  if (uVar2 < 0x2e) {
    pbVar1 = (byte *)((uVar2 >> 3) + 0x3004680);
    *pbVar1 = (byte)(1 << (uVar2 & 7)) | *pbVar1;
  }
  return;
}


// sub_080C23BC @ 0x080C23BC

void sub_080C23BC(uint arg0)

{
  byte *pbVar1;
  uint uVar2;
  
  (&DAT_03005ca8)[arg0 >> 3] = (&DAT_03005ca8)[arg0 >> 3] & ~(byte)(1 << (arg0 & 7));
  sub_080C90FC();
  uVar2 = arg0 - 0x120;
  if (uVar2 < 0x2e) {
    pbVar1 = (byte *)((uVar2 >> 3) + 0x3004680);
    *pbVar1 = *pbVar1 & ~(byte)(1 << (uVar2 & 7));
  }
  return;
}


// sub_080C2414 @ 0x080C2414

uint sub_080C2414(uint arg0)

{
  return (int)(uint)(byte)(&DAT_03005e10)[arg0 >> 3] >> (arg0 & 7) & 1;
}


// sub_080C2438 @ 0x080C2438

void sub_080C2438(uint arg0)

{
  (&DAT_03005e10)[arg0 >> 3] = (byte)(1 << (arg0 & 7)) | (&DAT_03005e10)[arg0 >> 3];
  return;
}


// sub_080C245C @ 0x080C245C

void sub_080C245C(uint arg0)

{
  (&DAT_03005e10)[arg0 >> 3] = (&DAT_03005e10)[arg0 >> 3] & ~(byte)(1 << (arg0 & 7));
  return;
}


// sub_080C2480 @ 0x080C2480

uint sub_080C2480(uint arg0)

{
  uint uVar1;
  
  if ((arg0 & 0x8000) == 0) {
    uVar1 = (int)(uint)(byte)(&DAT_03005794)[arg0 >> 3] >> (arg0 & 7) & 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080C24B8 @ 0x080C24B8

void sub_080C24B8(uint arg0)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  if ((arg0 & 0x8000) == 0) {
    iVar2 = sub_080C90F8();
    if (iVar2 == 0) {
      return;
    }
    pbVar3 = &DAT_03005794 + (arg0 >> 3);
    bVar1 = (byte)(1 << (arg0 & 7)) | *pbVar3;
  }
  else {
    pbVar3 = &DAT_03005794 + ((arg0 & 0x7fff) >> 3);
    bVar1 = *pbVar3 & ~(byte)(1 << (arg0 & 7));
  }
  *pbVar3 = bVar1;
  return;
}


// sub_080C2520 @ 0x080C2520

void sub_080C2520(uint arg0)

{
  if ((arg0 & 0x8000) == 0) {
    (&DAT_03005794)[arg0 >> 3] = (&DAT_03005794)[arg0 >> 3] & ~(byte)(1 << (arg0 & 7));
  }
  return;
}


// sub_080C2554 @ 0x080C2554

uint sub_080C2554(uint arg0)

{
  uint uVar1;
  
  if (arg0 < 0x100) {
    uVar1 = (int)(uint)(byte)(&DAT_03005714)[arg0 >> 3] >> (arg0 & 7) & 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080C2584 @ 0x080C2584

void sub_080C2584(uint arg0)

{
  char *pcVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar1 = (char *)sub_080BF648(arg0 & 0xffff);
  if (arg0 < 0x100) {
    if ('\x1a' < *pcVar1) {
      sub_080C2674(arg0);
    }
    (&DAT_03005714)[arg0 >> 3] = (byte)(1 << (arg0 & 7)) | (&DAT_03005714)[arg0 >> 3];
  }
  else {
    sub_080C2674(arg0);
  }
                    /* WARNING: Could not recover jumptable at 0x080c25c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C25D4 @ 0x080C25D4

void sub_080C25D4(uint arg0)

{
  if (arg0 < 0x100) {
    (&DAT_03005714)[arg0 >> 3] = (&DAT_03005714)[arg0 >> 3] & ~(byte)(1 << (arg0 & 7));
  }
  return;
}


// sub_080C2600 @ 0x080C2600

uint sub_080C2600(uint arg0)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    uVar1 = (uint)*(ushort *)(uVar2 * 4 + 0x81a6272);
    if (uVar1 == 0xffff) {
      return arg0 & 0xffff;
    }
    if (uVar1 == (arg0 & 0xffff)) break;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return (uint)(ushort)(&DAT_081a6274)[uVar2 * 2];
}


// sub_080C263C @ 0x080C263C

uint sub_080C263C(uint arg0)

{
  return arg0 & 0xffff;
}


// sub_080C2644 @ 0x080C2644

uint sub_080C2644(uint arg0)

{
  uint uVar1;
  
  if (arg0 < 0x17c) {
    uVar1 = (int)(uint)*(byte *)((arg0 >> 3) + 0x3004690) >> (arg0 & 7) & 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080C2674 @ 0x080C2674

void sub_080C2674(uint arg0)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  
  if (arg0 < 0x17c) {
    uVar1 = sub_080C2600(arg0 & 0xffff);
    iVar2 = sub_080DD21C(uVar1 & 0xffff);
    if (iVar2 != 0) {
      pbVar3 = (byte *)(((uVar1 & 0xffff) >> 3) + 0x3004690);
      *pbVar3 = (byte)(1 << (uVar1 & 7)) | *pbVar3;
    }
  }
  return;
}


// sub_080C26B8 @ 0x080C26B8

void sub_080C26B8(uint arg0)

{
  uint uVar1;
  byte *pbVar2;
  
  if (arg0 < 0x17c) {
    pbVar2 = (byte *)((arg0 >> 3) + 0x3004690);
    *pbVar2 = *pbVar2 & ~(byte)(1 << (arg0 & 7));
    uVar1 = sub_080C2600(arg0 & 0xffff);
    pbVar2 = (byte *)(((uVar1 & 0xffff) >> 3) + 0x3004690);
    *pbVar2 = *pbVar2 & ~(byte)(1 << (uVar1 & 7));
  }
  return;
}


// sub_080C2704 @ 0x080C2704

void sub_080C2704(void)

{
  sub_080D1230(0x3004690,0xe000014,0x30);
  return;
}


// sub_080C271C @ 0x080C271C

void sub_080C271C(void)

{
  sub_080D12F4(0xe000014,0x3004690,0x30);
  return;
}


// sub_080C2734 @ 0x080C2734

uint sub_080C2734(int arg0)

{
  uint uVar1;
  
  uVar1 = arg0 - 300;
  if (uVar1 < 0x40) {
    uVar1 = (int)(uint)*(byte *)((uVar1 >> 3) + 0x3006090) >> (uVar1 & 7) & 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080C2764 @ 0x080C2764

void sub_080C2764(int arg0)

{
  byte *pbVar1;
  uint uVar2;
  
  uVar2 = arg0 - 300;
  if (uVar2 < 0x40) {
    pbVar1 = (byte *)((uVar2 >> 3) + 0x3006090);
    *pbVar1 = (byte)(1 << (uVar2 & 7)) | *pbVar1;
  }
  return;
}


// sub_080C2790 @ 0x080C2790

void sub_080C2790(int arg0)

{
  uint uVar1;
  byte *pbVar2;
  
  uVar1 = arg0 - 300;
  if (uVar1 < 0x40) {
    pbVar2 = (byte *)((uVar1 >> 3) + 0x3006090);
    *pbVar2 = *pbVar2 & ~(byte)(1 << (uVar1 & 7));
  }
  return;
}


// sub_080C27BC @ 0x080C27BC

void sub_080C27BC(void)

{
  sub_080D1230(0x3006090,0xe000044,8);
  sub_080D1230(0x3004680,0xe006cac,8);
  return;
}


// sub_080C27F0 @ 0x080C27F0

void sub_080C27F0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  sub_080D12F4(0xe000044,0x3006090,8);
  uVar3 = 0;
  uVar4 = 0x12c0000;
  do {
    iVar1 = sub_080C2734(uVar3 + 300);
    if (iVar1 != 0) {
      uVar2 = sub_080C32D4(uVar4 >> 0x10);
      if ((uVar2 & 0xff) == 0) {
        sub_080C3328(uVar4 >> 0x10);
      }
    }
    uVar4 = uVar4 + 0x10000;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x40);
  sub_080D12F4(0xe006cac,0x3004680,8);
  uVar3 = 0;
  do {
    if (((int)(uint)*(byte *)((uVar3 >> 3) + 0x3004680) >> (uVar3 & 7) & 1U) != 0) {
      sub_080C2364(uVar3 + 0x120);
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x40);
  return;
}


// sub_080C287C @ 0x080C287C

undefined4 sub_080C287C(uint arg0)

{
  char *pcVar1;
  uint arg0_00;
  
  if (((arg0 < 0xff) && (arg0 != 0)) && (arg0 != 0xde)) {
    arg0_00 = arg0 & 0xffff;
    pcVar1 = (char *)sub_080BF648(arg0_00);
    if (((*pcVar1 != '\x1d') && (pcVar1 = (char *)sub_080BF648(arg0_00), *pcVar1 != '\x1e')) &&
       (pcVar1 = (char *)sub_080BF648(arg0_00), *pcVar1 != '(')) {
      return 1;
    }
  }
  return 0;
}


// sub_080C28CC @ 0x080C28CC

undefined4 sub_080C28CC(uint arg0)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C287C(arg0);
  if (iVar1 == 1) {
    uVar2 = (int)(uint)*(byte *)((arg0 >> 3) + 0x3004650) >> (arg0 & 7) & 1;
  }
  else {
    uVar2 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080c28f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar3;
}


// sub_080C28F8 @ 0x080C28F8

void sub_080C28F8(uint arg0)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = sub_080C287C(arg0);
  if (iVar1 == 1) {
    pbVar2 = (byte *)((arg0 >> 3) + 0x3004650);
    *pbVar2 = (byte)(1 << (arg0 & 7)) | *pbVar2;
  }
  return;
}


// sub_080C2924 @ 0x080C2924

void sub_080C2924(uint arg0)

{
  byte *pbVar1;
  
  if (arg0 < 0x17c) {
    pbVar1 = (byte *)((arg0 >> 3) + 0x3004650);
    *pbVar1 = *pbVar1 & ~(byte)(1 << (arg0 & 7));
  }
  return;
}


// sub_080C2950 @ 0x080C2950

void sub_080C2950(void)

{
  sub_080D1230(0x3004650,0xe00004c,0x30);
  return;
}


// sub_080C2968 @ 0x080C2968

void sub_080C2968(void)

{
  sub_080D12F4(0xe00004c,0x3004650,0x30);
  return;
}


// sub_080C2980 @ 0x080C2980

void sub_080C2980(void)

{
  sub_080D1230(0x3006080,0xe006c9c,0x10);
  return;
}


// sub_080C2998 @ 0x080C2998

void sub_080C2998(void)

{
  sub_080D12F4(0xe006c9c,0x3006080,0x10);
  return;
}


// sub_080C29B0 @ 0x080C29B0

uint sub_080C29B0(uint arg0)

{
  uint uVar1;
  
  if (arg0 < 0x17c) {
    uVar1 = (int)(uint)(byte)(&DAT_030057c6)[arg0 >> 3] >> (arg0 & 7) & 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080C29E8 @ 0x080C29E8

void sub_080C29E8(uint arg0)

{
  if (arg0 < 0x17c) {
    (&DAT_030057c6)[arg0 >> 3] = (byte)(1 << (arg0 & 7)) | (&DAT_030057c6)[arg0 >> 3];
  }
  return;
}


// sub_080C2A1C @ 0x080C2A1C

void sub_080C2A1C(uint arg0)

{
  if (arg0 < 0x17c) {
    (&DAT_030057c6)[arg0 >> 3] = (&DAT_030057c6)[arg0 >> 3] & ~(byte)(1 << (arg0 & 7));
  }
  return;
}


// sub_080C2A50 @ 0x080C2A50

void sub_080C2A50(int arg0,undefined4 arg1)

{
  undefined2 auStack_18 [4];
  
  sub_080D12F4(0xe000008,auStack_18,8);
  auStack_18[arg0] = (undefined2)arg1;
  sub_080D1230(auStack_18,0xe000008,8);
  return;
}


// sub_080C2A84 @ 0x080C2A84

uint sub_080C2A84(int arg0)

{
  ushort auStack_10 [4];
  
  sub_080D12F4(0xe000008,auStack_10,8);
  return (uint)auStack_10[arg0];
}


// sub_080C2AA8 @ 0x080C2AA8

undefined4 sub_080C2AA8(void)

{
  undefined4 local_8 [2];
  
  sub_080D12F4(0xe000010,local_8,4);
  DAT_03004688 = local_8[0];
  return local_8[0];
}


// sub_080C2ACC @ 0x080C2ACC

undefined4 sub_080C2ACC(void)

{
  return DAT_03004688;
}


// sub_080C2AD8 @ 0x080C2AD8

void sub_080C2AD8(undefined4 arg0)

{
  undefined4 local_8 [2];
  
  local_8[0] = arg0;
  sub_080D1230(local_8,0xe000010,4);
  DAT_03004688 = local_8[0];
  return;
}


// sub_080C2AFC @ 0x080C2AFC

undefined4 sub_080C2AFC(void)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2AA8();
                    /* WARNING: Could not recover jumptable at 0x080c2b12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)((uVar1 & 1) == 0);
  return uVar2;
}


// sub_080C2B14 @ 0x080C2B14

void sub_080C2B14(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C2AA8();
  sub_080C2AD8(arg0 & 0xffff | uVar1 & 0xfffffffc);
  return;
}


// Settings_GetBattleMsgSpeed @ 0x080C2B34

undefined4 Settings_GetBattleMsgSpeed(void)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2AA8();
                    /* WARNING: Could not recover jumptable at 0x080c2b4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)((uVar1 & 4) == 0);
  return uVar2;
}


// sub_080C2B4C @ 0x080C2B4C

void sub_080C2B4C(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C2AA8();
  sub_080C2AD8(arg0 & 0xffff | uVar1 & 0xfffffff3);
  return;
}


// sub_080C2B6C @ 0x080C2B6C

undefined4 sub_080C2B6C(void)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2AA8();
                    /* WARNING: Could not recover jumptable at 0x080c2b82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)((uVar1 & 0x10) == 0);
  return uVar2;
}


// sub_080C2B84 @ 0x080C2B84

void sub_080C2B84(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C2AA8();
  sub_080C2AD8(arg0 & 0xffff | uVar1 & 0xffffffcf);
  return;
}


// sub_080C2BA4 @ 0x080C2BA4

undefined4 sub_080C2BA4(void)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2AA8();
  if ((uVar1 & 0x40) == 0) {
    if ((uVar1 & 0x80) == 0) {
      uVar2 = 2;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080c2bc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080C2BCC @ 0x080C2BCC

void sub_080C2BCC(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C2AA8();
  sub_080C2AD8(arg0 & 0xffff | uVar1 & 0xfffffe3f);
  return;
}


// sub_080C2BF0 @ 0x080C2BF0

undefined4 sub_080C2BF0(void)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2AA8();
                    /* WARNING: Could not recover jumptable at 0x080c2c08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)((uVar1 & 0x200) == 0);
  return uVar2;
}


// sub_080C2C0C @ 0x080C2C0C

void sub_080C2C0C(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C2AA8();
  sub_080C2AD8(arg0 & 0xffff | uVar1 & 0xfffff9ff);
  return;
}


// sub_080C2C30 @ 0x080C2C30

undefined4 sub_080C2C30(void)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2AA8();
                    /* WARNING: Could not recover jumptable at 0x080c2c48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)((uVar1 & 0x800) == 0);
  return uVar2;
}


// sub_080C2C4C @ 0x080C2C4C

void sub_080C2C4C(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C2AA8();
  sub_080C2AD8(arg0 & 0xffff | uVar1 & 0xffffe7ff);
  return;
}


// sub_080C2C70 @ 0x080C2C70

undefined4 sub_080C2C70(void)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2ACC();
  if ((uVar1 & 0x2000) == 0) {
    if ((uVar1 & 0x4000) == 0) {
      uVar2 = 2;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080c2c98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080C2C9C @ 0x080C2C9C

void sub_080C2C9C(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C2AA8();
  sub_080C2AD8(arg0 & 0xffff | uVar1 & 0xffff1fff);
  return;
}


// sub_080C2CC0 @ 0x080C2CC0

void sub_080C2CC0(void)

{
  uint uVar1;
  
  uVar1 = sub_080C1D9C();
  if ((uVar1 & 1) != 0) {
    sub_080C1D00(0xff);
  }
  return;
}


// sub_080C2CD8 @ 0x080C2CD8

void sub_080C2CD8(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  undefined4 local_c;
  
  DAT_03003fc4 = (int)(char)arg0;
  DAT_03004618 = (int)(char)arg1;
  DAT_03004624 = (int)(char)arg2;
  sub_080A9AB4(0x80c1881);
  local_c = 0;
  CpuSet(&local_c,0x3002db0,0x5000100);
  sub_080AABB0();
  sub_080C2CC0();
  if ((char)arg2 == 0) {
    DAT_03005180 = 1;
  }
  return;
}


