/* Ghidra decompilation of asm/code_080D0674.s (reference only; not compiled). */

// sub_080D0674 @ 0x080D0674

void sub_080D0674(void)

{
  undefined4 uVar1;
  
  REG_BG1CNT = 0x8205;
  REG_BG2CNT = 0x8406;
  DAT_03000040 = 0;
  REG_DMA3SAD = 0x81b93b0;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D06BC @ 0x080D06BC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D06BC(undefined4 arg0,int arg1)

{
  dword arg0_00;
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_10;
  
  if (arg1 == 1) {
    if (_DAT_0203a468 == 0) {
      _DAT_0203a468 = sub_080ABD04(1,2,0x1c,5);
    }
    sub_080D0498(arg0,0);
    goto LAB_080d0784;
  }
  if (arg1 != 0) {
    if (arg1 != 2) {
      if (arg1 == 3) {
        if (_DAT_0203a470 == 0) {
          _DAT_0203a470 = sub_080ABD04(1,0xc,0x1c,5);
        }
        sub_080D0498(arg0,2);
        sub_080D0264();
      }
      goto LAB_080d0826;
    }
    if (_DAT_0203a46c == 0) {
      _DAT_0203a46c = sub_080ABD04(1,7,0x1c,5);
    }
    if ((ushort)(DAT_0203a454 - 1U) < 2) {
      sub_080D0498(arg0,3);
    }
    else {
      sub_080D0498(arg0,1);
    }
    goto LAB_080d0784;
  }
  local_10 = 0;
  REG_DMA3SAD = &local_10;
  REG_DMA3DAD = 0x200f874;
  REG_DMA3CNT = 0x85002000;
  uVar1 = REG_DMA3CNT;
  if (_DAT_0203a464 == 0) {
    _DAT_0203a464 = sub_080ABD04(1,0,0x1c,2);
  }
  switch(DAT_0203a454) {
  case 0:
  case 4:
    arg0_00 = 0x84f2110;
    goto LAB_080d075e;
  case 1:
    arg0_00 = 0x84f2118;
    uVar1 = 0x58;
    goto LAB_080d0760;
  case 2:
    arg0_00 = 0x84f2124;
LAB_080d075e:
    uVar1 = 0x68;
LAB_080d0760:
    sub_080CCEC8(arg0_00,uVar1,0xc,4);
    break;
  case 3:
    sub_080CCEC8(0x84f212c,0x68,0xc,4);
  }
  DisplayList_Add(0x80d0675,1);
LAB_080d0784:
  sub_080D0264();
LAB_080d0826:
                    /* WARNING: Could not recover jumptable at 0x080d082c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D0834 @ 0x080D0834

void sub_080D0834(int arg0,undefined4 arg1,uint arg2,uint arg3)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  uint in_stack_00000000;
  uint in_stack_00000004;
  
  uVar1 = 0;
  if ((in_stack_00000004 & 0xffff) != 0) {
    do {
      uVar3 = 0;
      if ((in_stack_00000000 & 0xffff) != 0) {
        do {
          puVar2 = (ushort *)
                   (arg0 + (uVar1 + (arg3 & 0xffff)) * 0x40 + (uVar3 + (arg2 & 0xffff)) * 2);
          *puVar2 = *puVar2 & 0xfff | (short)arg1 << 0xc;
          uVar3 = uVar3 + 1 & 0xffff;
        } while (uVar3 < (in_stack_00000000 & 0xffff));
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < (in_stack_00000004 & 0xffff));
  }
  return;
}


// sub_080D08B8 @ 0x080D08B8

void sub_080D08B8(void)

{
  sub_080D0834(0x6002000,0,1,2);
  sub_080D0834(0x6002000,4,1,2);
  return;
}


// sub_080D08F0 @ 0x080D08F0

void sub_080D08F0(void)

{
  sub_080D0834(0x6002000,0,1,2);
  sub_080D0834(0x6002000,4,1,7);
  return;
}


// sub_080D0928 @ 0x080D0928

void sub_080D0928(void)

{
  sub_080D0834(0x6002000,0,1,2);
  sub_080D0834(0x6002000,4,1,0xc);
  return;
}


// sub_080D0960 @ 0x080D0960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D0960(void)

{
  dword arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a47c == 2) {
    Text_DrawSpriteString(_DAT_0203a480,0,0,10);
  }
  if (DAT_0203a47c == 1) {
    DAT_0203a47c = 2;
  }
  if (_DAT_0203a45c != 1) goto LAB_080d09cc;
  if (DAT_0203a45a == 1) {
    arg0 = 0x80d08f1;
  }
  else {
    if (1 < DAT_0203a45a) {
      if (DAT_0203a45a == 2) {
        DisplayList_Add(0x80d0929,1);
      }
      goto LAB_080d09cc;
    }
    if (DAT_0203a45a != 0) goto LAB_080d09cc;
    arg0 = 0x80d08b9;
  }
  DisplayList_Add(arg0,1);
LAB_080d09cc:
                    /* WARNING: Could not recover jumptable at 0x080d09d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D09D8 @ 0x080D09D8

void sub_080D09D8(int arg0,undefined4 arg1)

{
  if (((ushort)arg1 & DAT_030031b8) == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C51D4(0x65);
  }
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_080AA184(0x8001000,0,0,0);
  }
  return;
}


// sub_080D0A2C @ 0x080D0A2C

void sub_080D0A2C(undefined4 arg0)

{
  dword in_r1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a45a == 1) {
    in_r1 = 0x84f1fa8;
  }
  else if (DAT_0203a45a < 2) {
    if (DAT_0203a45a == 0) {
      in_r1 = 0x84f1f7c;
    }
  }
  else if (DAT_0203a45a == 2) {
    in_r1 = 0x84f1fd4;
  }
  sub_080D0084(arg0,in_r1,1);
                    /* WARNING: Could not recover jumptable at 0x080d0a6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D0A74 @ 0x080D0A74

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D0A74(int arg0)

{
  ushort uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          uVar1 = DAT_03003964 & 0x40;
          if (DAT_0203a45a != 2) {
            uVar1 = DAT_0203a45a + 1;
          }
          DAT_0203a45a = uVar1;
          sub_080C51D4(100);
        }
      }
      else {
        if (DAT_0203a45a == 0) {
          DAT_0203a45a = 2;
        }
        else {
          DAT_0203a45a = DAT_0203a45a - 1;
        }
        sub_080C51D4(100);
      }
      goto LAB_080d0b0e;
    }
    *(undefined2 *)(arg0 + 0x1c) = 1;
    *(undefined2 *)(arg0 + 0x1e) = 0x80;
  }
  else {
    iVar2 = sub_080D13D0((uint)DAT_0203a45a);
    if (iVar2 == 1) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined2 *)(arg0 + 0x1e) = 1;
      sub_080C51D4(0x65);
      goto LAB_080d0b0e;
    }
  }
  sub_080C51D4(0x66);
LAB_080d0b0e:
  _DAT_0203a45c = 1;
                    /* WARNING: Could not recover jumptable at 0x080d0b16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D0B18 @ 0x080D0B18

void sub_080D0B18(int arg0,int arg1)

{
  undefined4 uVar1;
  
  if (arg1 == 0) {
    uVar1 = sub_080D1328((uint)DAT_0203a45a,0x30046c0,0);
    *(short *)(arg0 + 0x1e) = (short)uVar1;
    if (DAT_0203a454 == 4) {
      sub_080C23BC(0x108);
    }
  }
  else if (DAT_0203a454 == 4) {
    sub_080A9AB4(0x80d96bd);
  }
  else {
    sub_080B710C((uint)DAT_030050f2,(uint)DAT_030050f4,(uint)DAT_030050ee,(uint)DAT_030050f0);
  }
  return;
}


// sub_080D0BA0 @ 0x080D0BA0

void sub_080D0BA0(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    *(undefined1 *)(uVar1 + 0x30069f0) = *(undefined1 *)(uVar1 + 0x3005100);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x3c);
  sub_080C2CD8((int)(char)DAT_030050fa,(int)(char)DAT_030050fc,1);
  return;
}


// sub_080D0BF0 @ 0x080D0BF0

void sub_080D0BF0(int arg0,int arg1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (arg1 == 0) {
    sub_080C10F4();
    uVar1 = sub_080D1328(3,0x30046c0,0);
    *(short *)(arg0 + 0x1e) = (short)uVar1;
    if ((uVar1 & 0xffff) == 1) {
      uVar2 = sub_080D13A8();
      *(short *)(arg0 + 0x1e) = (short)uVar2;
    }
  }
  else if (DAT_03005180 == 0) {
    sub_080B710C((uint)DAT_030050f2,(uint)DAT_030050f4,(uint)DAT_030050ee,(uint)DAT_030050f0);
  }
  else {
    sub_080D0BA0();
  }
  return;
}


// sub_080D0C74 @ 0x080D0C74

void sub_080D0C74(int arg0)

{
  int iVar1;
  uint uVar2;
  
  DAT_030050ec = DAT_03004552;
  DAT_030050ee = DAT_03004562;
  DAT_030050f0 = DAT_03004564;
  DAT_030050f2 = (undefined2)DAT_03004614;
  DAT_030050f4 = (undefined2)DAT_03004514;
  uVar2 = 0;
  do {
    (&DAT_03005100)[uVar2] = *(undefined1 *)(uVar2 + 0x30069f0);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x3c);
  DAT_030050fa = (undefined2)DAT_03003fc4;
  DAT_030050fc = (undefined2)DAT_03004618;
  if (arg0 != 3) {
    DAT_03005f60 = DAT_03004552;
    DAT_03005f62 = DAT_03004562;
    DAT_03005f64 = DAT_03004564;
    DAT_03005f66 = (undefined2)DAT_03004614;
    DAT_03005f68 = (undefined2)DAT_03004514;
    DAT_03005f6a = DAT_030050f8;
    DAT_03005182 = (undefined1)DAT_03005180;
    DAT_03005f70 = arg0;
  }
  iVar1 = sub_080C2340(0xe5);
  if (iVar1 != 0) {
    sub_080C2A50(3,1);
  }
  return;
}


// sub_080D0DA0 @ 0x080D0DA0

void sub_080D0DA0(int arg0)

{
  uint uVar1;
  
  sub_080D0C74(3);
  uVar1 = sub_080D1264(3,0x30046c0);
  *(short *)(arg0 + 0x1e) = (short)uVar1;
  if ((uVar1 & 0xffff) == 1) {
    DAT_0203a456 = 0;
  }
  return;
}


// sub_080D0DD0 @ 0x080D0DD0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D0DD0(int arg0)

{
  ushort uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          uVar1 = DAT_03003964 & 0x40;
          if (DAT_0203a45a != 2) {
            uVar1 = DAT_0203a45a + 1;
          }
          DAT_0203a45a = uVar1;
          sub_080C51D4(100);
        }
      }
      else {
        if (DAT_0203a45a == 0) {
          DAT_0203a45a = 2;
        }
        else {
          DAT_0203a45a = DAT_0203a45a - 1;
        }
        sub_080C51D4(100);
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined2 *)(arg0 + 0x1e) = 0x80;
      sub_080C51D4(0x66);
      DAT_030031cc = 1;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    *(undefined2 *)(arg0 + 0x1e) = 1;
    sub_080C51D4(0x65);
  }
  _DAT_0203a45c = 1;
                    /* WARNING: Could not recover jumptable at 0x080d0e72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D0E74 @ 0x080D0E74

undefined4 sub_080D0E74(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((DAT_03004614 == 0) && (DAT_03004562 == 2)) && (DAT_03004564 == 6)) {
    uVar1 = 1;
  }
  return uVar1;
}


// sub_080D0EA0 @ 0x080D0EA0

void sub_080D0EA0(int arg0)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (DAT_0203a456 != 2) {
    iVar1 = sub_080D0E74();
    if (iVar1 == 1) {
      iVar1 = sub_080C2340(2);
      if (iVar1 == 0) goto LAB_080d0ee8;
      uVar2 = 3;
      DAT_03004552 = 3;
    }
    else {
      uVar2 = (uint)DAT_03004552;
    }
    uVar2 = sub_080B1A1C(uVar2);
    sub_080B02A0(uVar2 & 0xffff);
    uVar3 = sub_080B1A1C((uint)DAT_03004552);
    DAT_03004552 = (ushort)uVar3;
  }
LAB_080d0ee8:
  if (DAT_0203a456 != 4) {
    sub_080C2364(0xcb);
    sub_080C2364(0x163);
  }
  sub_080D0C74((uint)DAT_0203a45a);
  uVar3 = sub_080D1264((uint)DAT_0203a45a,0x30046c0);
  *(short *)(arg0 + 0x1e) = (short)uVar3;
  if (DAT_0203a456 != 2) {
    uVar2 = sub_080B1A1C((uint)DAT_03004552);
    sub_080B02A0(uVar2 & 0xffff);
    uVar3 = sub_080B1A1C((uint)DAT_03004552);
    DAT_03004552 = (ushort)uVar3;
  }
  DAT_03003bb4 = 0;
  DAT_030031cc = 0;
  if (DAT_0203a456 != 4) {
    DAT_0203a456 = 0;
  }
  return;
}


// sub_080D0F54 @ 0x080D0F54

void sub_080D0F54(void)

{
  DAT_03003bb4 = 0;
  return;
}


// sub_080D0F60 @ 0x080D0F60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D0F60(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (_DAT_0203a464 != 0) {
    sub_080ABD30(_DAT_0203a464,1);
  }
  if (_DAT_0203a468 != 0) {
    sub_080ABD30(_DAT_0203a468,1);
  }
  if (_DAT_0203a46c != 0) {
    sub_080ABD30(_DAT_0203a46c,1);
  }
  if (_DAT_0203a470 != 0) {
    sub_080ABD30(_DAT_0203a470,1);
  }
  if (_DAT_0203a474 != 0) {
    sub_080AB91C(_DAT_0203a474,1);
  }
  if ((DAT_0203a456 == 0) && (sub_080C5170((uint)DAT_0203a45e), DAT_0203a456 == 0)) {
    if (DAT_0203a454 == 0) {
      sub_080D5B8C(1);
      goto LAB_080d101c;
    }
    if (DAT_0203a454 == 1) {
      sub_080D5B8C(2);
      goto LAB_080d101c;
    }
    if (DAT_0203a454 == 2) {
      sub_080D5B8C(0);
      goto LAB_080d101c;
    }
    if (DAT_0203a454 != 3) goto LAB_080d101c;
  }
  else {
    if (DAT_0203a456 == 1) {
      *(undefined4 *)(DAT_0203a460 + 0xc) = 1;
      if (DAT_0203a454 == 2) {
        sub_080C5170((uint)DAT_0203a45e);
      }
      goto LAB_080d101c;
    }
    if (DAT_0203a456 != 2) {
      if (DAT_0203a456 == 3) {
        sub_080D5B8C(3);
      }
      else if (DAT_0203a456 == 4) {
        sub_080D5B8C(0);
      }
      goto LAB_080d101c;
    }
  }
  *(undefined4 *)(DAT_0203a460 + 0xc) = 1;
LAB_080d101c:
                    /* WARNING: Could not recover jumptable at 0x080d1020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D1024 @ 0x080D1024

void sub_080D1024(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x81000800;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x81000800;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x81000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D106C @ 0x080D106C

void sub_080D106C(void)

{
  sub_080C6558();
  CpuSet(0x200dfd4,0x2018874,0x4000200);
  DisplayList_Add(0x80d1025,1);
  return;
}


// sub_080D1098 @ 0x080D1098

void sub_080D1098(void)

{
  if ((DAT_0203a456 == 0) || (DAT_0203a454 == 2)) {
    sub_080C51BC(4);
  }
  return;
}


// sub_080D10B8 @ 0x080D10B8

void sub_080D10B8(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a456 == 0) {
    sub_080C5170(0x16);
  }
  else if (DAT_0203a454 == 2) {
    iVar1 = sub_080C06BC(0);
    if (iVar1 == 1) {
      sub_080C5170(7);
    }
    else if (iVar1 < 2) {
      if (iVar1 == 0) {
        sub_080C5170(0xe);
      }
    }
    else if (iVar1 == 2) {
      sub_080C5170(0x14);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080d1108. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D110C @ 0x080D110C

undefined4 sub_080D110C(undefined4 arg0,undefined4 arg1)

{
  undefined4 uVar1;
  undefined4 local_18;
  
  uVar1 = sub_080AD0FC(0x84f2134,0xffff);
  local_18 = 0;
  CpuSet(&local_18,0x203a454,0x5000200);
  DAT_0203a45e = DAT_030031b4;
  DAT_0203a454 = (short)arg0;
  DAT_0203a456 = (undefined2)arg1;
  if ((short)arg0 == 3) {
    DAT_0203a45a = (undefined2)DAT_03005f70;
    sub_080C23BC(0xc4);
    sub_080C23BC(0xca);
  }
  return uVar1;
}


// sub_080D1180 @ 0x080D1180

void sub_080D1180(void)

{
  int iVar1;
  uint uVar2;
  dword dStack_38;
  int iStack_34;
  undefined4 uStack_18;
  
  iVar1 = sub_080D12F4(0xe000000,&dStack_38,0x20);
  if ((iVar1 != 0) && ((dStack_38 != 0x10241179 || (iStack_34 != 0x11)))) {
    uStack_18 = 0;
    CpuSet(&uStack_18,0x200f874,0x5002000);
    DAT_0200f874 = 0x10241179;
    DAT_0200f878 = 0x11;
    DAT_0200f884 = 0x2a95;
    DAT_02016510 = 0xffff;
    DAT_02016512 = 0xffff;
    DAT_02016514 = 0;
    DAT_02016516 = 0x17;
    for (uVar2 = 0; uVar2 < 3; uVar2 = uVar2 + 1) {
      sub_0815CBB4(0x200f874,0xe000000,0x8000);
      iVar1 = sub_0815CC24(0x200f874,0xe000000,0x8000);
      if (iVar1 == 0) {
        return;
      }
    }
  }
  return;
}


// sub_080D1230 @ 0x080D1230

undefined4 sub_080D1230(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = 0;
  do {
    sub_0815CBB4(arg0,arg1,arg2);
    iVar1 = sub_0815CC24(arg0,arg1,arg2);
    if (iVar1 == 0) {
      uVar2 = 1;
      goto LAB_080d125e;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 3);
  uVar2 = 0;
LAB_080d125e:
                    /* WARNING: Could not recover jumptable at 0x080d1262. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080D1264 @ 0x080D1264

undefined4 sub_080D1264(int arg0,int arg1)

{
  int iVar1;
  uint uVar2;
  int local_18;
  
  iVar1 = sub_080D1230(arg1,arg0 * 0x1b00 + 0xe00009c,0x18f8);
  if (iVar1 != 0) {
    local_18 = 0;
    uVar2 = 0;
    do {
      local_18 = local_18 + (uint)*(byte *)(arg1 + uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x18f8);
    iVar1 = sub_080D1230(&local_18,arg0 * 4 + 0xe00008c,4);
    if (iVar1 != 0) {
      local_18 = 1;
      iVar1 = sub_080D1230(&local_18,arg0 * 4 + 0xe00007c,4);
      if (iVar1 != 0) {
        sub_080C2704();
        sub_080C27BC();
        sub_080C2950();
        sub_080C2980();
        return 1;
      }
    }
  }
  return 0;
}


// sub_080D12F4 @ 0x080D12F4

undefined4 sub_080D12F4(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = 0;
  do {
    sub_0815CB50(arg0,arg1,arg2);
    iVar1 = sub_0815CC24(arg0,arg1,arg2);
    if (iVar1 == 0) {
      uVar2 = 1;
      goto LAB_080d1322;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 3);
  uVar2 = 0;
LAB_080d1322:
                    /* WARNING: Could not recover jumptable at 0x080d1326. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080D1328 @ 0x080D1328

undefined4 sub_080D1328(int arg0,int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  int iStack_18;
  
  iVar1 = sub_080D12F4(arg0 * 0x1b00 + 0xe00009c,arg1,0x18f8);
  if ((iVar1 != 0) && (iVar1 = sub_080D12F4(arg0 * 4 + 0xe00008c,&iStack_18,4), iVar1 != 0)) {
    iVar1 = 0;
    uVar2 = 0;
    do {
      iVar1 = iVar1 + (uint)*(byte *)(arg1 + uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x18f8);
    if (iVar1 == iStack_18) {
      if (arg2 == 0) {
        sub_080C271C();
        sub_080C27F0();
        sub_080C2968();
        sub_080D3E10();
      }
      return 1;
    }
  }
  return 0;
}


// sub_080D13A8 @ 0x080D13A8

uint sub_080D13A8(void)

{
  int iVar1;
  undefined4 auStack_8 [2];
  
  auStack_8[0] = 0;
  iVar1 = sub_080D1230(auStack_8,0xe000088,4);
  return (uint)(iVar1 != 0);
}


// sub_080D13D0 @ 0x080D13D0

uint sub_080D13D0(int arg0)

{
  int iVar1;
  uint uVar2;
  int local_8 [2];
  
  iVar1 = sub_080D12F4(arg0 * 4 + 0xe00007c,local_8,4);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (uint)(local_8[0] == 1);
  }
  return uVar2;
}


// sub_080D1404 @ 0x080D1404

void sub_080D1404(int arg0)

{
  uint arg0_00;
  undefined4 uVar1;
  
  if ((ushort)(DAT_0203a454 - 1U) < 2) {
    arg0_00 = 3;
  }
  else {
    arg0_00 = (uint)DAT_0203a45a;
  }
  uVar1 = sub_080D13D0(arg0_00);
  *(short *)(arg0 + 0x1e) = (short)uVar1;
  return;
}


// sub_080D1430 @ 0x080D1430

undefined4 sub_080D1430(void)

{
  int iVar1;
  undefined4 uVar2;
  uint arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0 = 0;
  do {
    iVar1 = sub_080D13D0(arg0);
    if (iVar1 == 1) {
      uVar2 = 1;
      goto LAB_080d144a;
    }
    arg0 = arg0 + 1;
  } while (arg0 < 3);
  uVar2 = 0;
LAB_080d144a:
                    /* WARNING: Could not recover jumptable at 0x080d144e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080D1450 @ 0x080D1450

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D1450(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x84f2bfc;
  REG_DMA3DAD = 0x6001340;
  REG_DMA3CNT = 0x84000070;
  uVar1 = REG_DMA3CNT;
  _DAT_0203a46c = 0;
  return;
}


// sub_080D1498 @ 0x080D1498

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D1498(void)

{
  if (_DAT_0203a46c == 0) {
    DisplayList_Add(0x80d1451,1);
    _DAT_0203a46c = 1;
  }
  return;
}


// sub_080D14BC @ 0x080D14BC

void sub_080D14BC(undefined4 arg0,int arg1)

{
  undefined4 in_r2;
  
  if (arg1 == 0) {
    LZ77UnCompWram(0x84f2974,0x200afc8,in_r2);
    sub_080ACFCC(3,0x84f2dbc,0x3003150,0x20);
    sub_080ACFCC(3,0x81b6e90,&DAT_03002e10,0x20);
    sub_080AABB0();
    sub_080C6E30(1);
    DAT_03000004 = 0xfff8;
    DAT_03000040 = 0;
    sub_080D1498();
  }
  return;
}


// sub_080D1538 @ 0x080D1538

void sub_080D1538(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6011800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D155C @ 0x080D155C

void sub_080D155C(void)

{
  uint arg0;
  ushort *puVar1;
  uint uVar2;
  ushort local_1c [8];
  
  puVar1 = local_1c;
  Combatant_DecodeName(&DAT_0203a46e,local_1c);
  uVar2 = 0;
  do {
    arg0 = (uint)*puVar1;
    sub_080ABF24(arg0);
    sub_080AC438(arg0,uVar2 * 0x40 + 0x2000000);
    puVar1 = puVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  DisplayList_Add(0x80d1539,1);
  DAT_0200e812 = 1;
  DAT_0200e814 = 1;
  return;
}


// sub_080D15B0 @ 0x080D15B0

void sub_080D15B0(void)

{
  Font_ResetGlyphSpriteCache(0x180);
  DAT_0203a478 = sub_080AB7D4(2,0xb,0x1a,2);
  return;
}


// NameEntry_DrawGrid @ 0x080D15DC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NameEntry_DrawGrid(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (DAT_0203a456 == 0) {
    sub_080AA184(*(undefined4 *)((uint)DAT_0203a460._2_2_ * 4 + 0x84f3040),1,0xd,0);
  }
  else {
    sub_080AA184(0x800276c,1,0xd,0);
  }
  uVar3 = 0;
  do {
    sub_080AA184(0x80027cc,1,0xd,0);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 2);
  uVar3 = 0;
  do {
    sub_080AA184(0x80027bc,1,0xd,0);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 7);
  Font_ResetGlyphSpriteCache(0x180);
  uVar3 = 0;
  do {
    uVar2 = 0;
    uVar1 = uVar3 + 1;
    uVar4 = 0xc0000;
    do {
      FontSprite_DrawGlyph
                ((uint)*(ushort *)(((uVar3 + _DAT_0203a45c) * 0xb + uVar2) * 2 + 0x84f2ddc),0,0,
                 uVar4 >> 0x10);
      uVar4 = uVar4 + 0xc0000;
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0xb);
    uVar3 = uVar1;
  } while (uVar1 < 4);
  Text_DrawSpriteString(0x84f3002,0,0,0xb0);
  Text_DrawSpriteString(0x84f302a,0,0,0x10);
  uVar3 = 0;
  do {
    sub_080AA1F4(0x84f3038,0,0,0);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  if (_DAT_0203a45c != 0) {
    sub_080C4A4C(0,0,0x96,0x6a);
  }
  if (_DAT_0203a45c + 4 < 0x19) {
    sub_080C4AB0(0,0,0x96,0x96);
  }
  return;
}


// sub_080D17CC @ 0x080D17CC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D17CC(undefined4 arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080C51D4(0x66);
  if (_DAT_0203a468 == 7) {
    if (DAT_0203a475 != -1) {
      DAT_0203a475 = -1;
      goto LAB_080d181c;
    }
    _DAT_0203a468 = 6;
  }
  else if (_DAT_0203a468 != 0) {
    _DAT_0203a468 = _DAT_0203a468 - 1;
  }
  *(undefined1 *)((int)&DAT_0203a46e + (uint)_DAT_0203a468) = 0xff;
LAB_080d181c:
  sub_080D155C();
                    /* WARNING: Could not recover jumptable at 0x080d1826. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// NameEntry_HandleInput @ 0x080D1828

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NameEntry_HandleInput(int arg0)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar2;
  bool bVar3;
  
  bVar3 = false;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203a460._2_2_ != 0) {
    DAT_0203a460._2_2_ = DAT_0203a460._2_2_ + -1;
    if ((DAT_0203a460._2_2_ == 0) && (_DAT_0203a464 == 1)) {
      DAT_0203a45e = 0;
      DAT_0203a460._0_2_ = 3;
      DAT_0203a456 = _DAT_0203a464;
      _DAT_0203a464 = 0;
    }
    goto LAB_080d1ad0;
  }
  if (DAT_0203a456 == 0) {
    if ((DAT_030031b8 & 1) == 0) {
      if ((DAT_030031b8 & 2) != 0) goto LAB_080d1a4a;
      if ((DAT_030031b8 & 8) == 0) {
        if ((DAT_03003964 & 0x40) == 0) {
          if ((DAT_03003964 & 0x80) == 0) {
            if ((DAT_03003964 & 0x20) == 0) {
              if ((DAT_03003964 & 0x10) == 0) {
                if ((DAT_03003964 & 0x200) == 0) {
                  if ((DAT_03003964 & 0x100) == 0) goto LAB_080d1ac6;
                  if (DAT_0203a45a == 3) {
                    if (0x17 < _DAT_0203a45c + 7) {
                      bVar3 = _DAT_0203a45c != 0x15;
                      _DAT_0203a45c = 0x15;
                      goto LAB_080d1ac6;
                    }
                    _DAT_0203a45c = _DAT_0203a45c + 4;
                  }
                  else {
                    DAT_0203a45a = 3;
                  }
                }
                else if (DAT_0203a45a == 0) {
                  if (_DAT_0203a45c < 3) {
                    bVar3 = _DAT_0203a45c != 0;
                    _DAT_0203a45c = DAT_0203a45a;
                    goto LAB_080d1ac6;
                  }
                  _DAT_0203a45c = _DAT_0203a45c - 3;
                }
                else {
                  DAT_0203a45a = 0;
                }
              }
              else if (DAT_0203a458 == 10) {
                DAT_0203a460._0_2_ = DAT_0203a45a;
                DAT_0203a456 = 1;
                DAT_0203a45e = DAT_03003964 & 0x20;
              }
              else {
                bVar3 = DAT_0203a458 == 4;
                DAT_0203a458 = DAT_0203a458 + 1;
                if (bVar3) {
                  DAT_0203a458 = 6;
                }
              }
            }
            else {
              if (DAT_0203a458 != 0) {
                bVar3 = true;
                bVar2 = DAT_0203a458 == 6;
                DAT_0203a458 = DAT_0203a458 - 1;
                if (bVar2) {
                  DAT_0203a458 = 4;
                }
                goto LAB_080d1ac6;
              }
              DAT_0203a45e = 0;
              DAT_0203a460._0_2_ = DAT_0203a45a;
              DAT_0203a456 = 1;
            }
          }
          else if (DAT_0203a45a == 3) {
            if (0x18 < _DAT_0203a45c + 4) goto LAB_080d1ac6;
            _DAT_0203a45c = _DAT_0203a45c + 1;
          }
          else {
            DAT_0203a45a = DAT_0203a45a + 1;
          }
        }
        else if (DAT_0203a45a == 0) {
          if (_DAT_0203a45c == 0) goto LAB_080d1ac6;
          _DAT_0203a45c = _DAT_0203a45c - 1;
        }
        else {
          DAT_0203a45a = DAT_0203a45a - 1;
        }
LAB_080d1ac4:
        bVar3 = true;
      }
      else {
        sub_080C51D4(0x65);
        DAT_0203a45e = 0;
        DAT_0203a460._0_2_ = 3;
        DAT_0203a456 = 1;
      }
    }
    else {
      sub_080C51D4(0x65);
      uVar1 = sub_080C03A8((uint)*(ushort *)
                                  ((((uint)DAT_0203a45a + (uint)_DAT_0203a45c) * 0xb +
                                   (uint)DAT_0203a458) * 2 + 0x84f2ddc));
      *(char *)((int)&DAT_0203a46e + (uint)_DAT_0203a468) = (char)uVar1;
      sub_080D155C();
      if (_DAT_0203a468 == 7) {
        _DAT_0203a464 = 1;
      }
      else {
        _DAT_0203a468 = _DAT_0203a468 + 1;
      }
      DAT_0203a460._2_2_ = 7;
    }
  }
  else if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_030031b8 & 8) == 0) {
        if ((DAT_03003964 & 0x40) == 0) {
          if ((DAT_03003964 & 0x80) == 0) {
            if ((DAT_03003964 & 0x20) == 0) {
              if ((DAT_03003964 & 0x10) == 0) goto LAB_080d1ac6;
              DAT_0203a458 = 0;
            }
            else {
              DAT_0203a458 = 10;
            }
            DAT_0203a45a = (ushort)DAT_0203a460;
            DAT_0203a456 = 0;
          }
          else if ((ushort)DAT_0203a460 == 3) {
            DAT_0203a460._0_2_ = 0;
          }
          else {
            DAT_0203a460._0_2_ = (ushort)DAT_0203a460 + 1;
          }
        }
        else if ((ushort)DAT_0203a460 == 0) {
          DAT_0203a460._0_2_ = 3;
        }
        else {
          DAT_0203a460._0_2_ = (ushort)DAT_0203a460 - 1;
        }
        goto LAB_080d1ac4;
      }
      sub_080C51D4(0x65);
      DAT_0203a45e = 0;
      DAT_0203a460._0_2_ = 3;
    }
    else {
LAB_080d1a4a:
      sub_080D17CC(arg0);
    }
  }
  else {
    sub_080C51D4(0x65);
    if (DAT_0203a45e == 0) {
      if ((ushort)DAT_0203a460 == 0) {
        _DAT_0203a45c = 0;
      }
      else if ((ushort)DAT_0203a460 == 1) {
        _DAT_0203a45c = 10;
      }
      else if ((ushort)DAT_0203a460 == 2) {
        _DAT_0203a45c = 0x14;
      }
      else if ((ushort)DAT_0203a460 == 3) {
        *(undefined2 *)(arg0 + 0x1c) = 1;
      }
    }
  }
LAB_080d1ac6:
  if (bVar3) {
    sub_080C51D4(100);
  }
LAB_080d1ad0:
                    /* WARNING: Could not recover jumptable at 0x080d1ad4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D1AD8 @ 0x080D1AD8

undefined4 sub_080D1AD8(char *arg0,char *arg1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((((*arg0 == *arg1) && (arg0[1] == arg1[1])) && (arg0[2] == arg1[2])) &&
      ((arg0[3] == arg1[3] && (arg0[4] == arg1[4])))) &&
     ((arg0[5] == arg1[5] && ((arg0[6] == arg1[6] && (arg0[7] == arg1[7])))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080d1b24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar1;
}


// sub_080D1B28 @ 0x080D1B28

void sub_080D1B28(int arg0)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  sub_080C2364(0x164);
  if ((char)DAT_0203a46e == -1) goto LAB_080d1c70;
  bVar1 = false;
  uVar5 = 0;
  do {
    if ((*(char *)((int)&DAT_0203a46e + uVar5) != '\0') &&
       (*(char *)((int)&DAT_0203a46e + uVar5) != -1)) {
      bVar1 = true;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 8);
  if (!bVar1) goto LAB_080d1c70;
  if ((DAT_0203a454 & 0x8000) == 0) {
    iVar2 = sub_080C0148(DAT_0203a454 + 0x8000 & 0xffff);
    uVar5 = 0;
    do {
      uVar3 = sub_080C0148(uVar5 + 0x8000 & 0xffff);
      if ((*(byte *)(iVar2 + 0xc) != uVar5) &&
         (iVar4 = sub_080D1AD8(&DAT_0203a46e,uVar3), iVar4 == 0)) goto LAB_080d1c70;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 3);
    iVar4 = sub_080D1AD8(&DAT_0203a46e,0x30050c0);
    if (((iVar4 == 0) || (iVar4 = sub_080D1AD8(&DAT_0203a46e,&DAT_030050c8), iVar4 == 0)) ||
       (iVar4 = sub_080D1AD8(&DAT_0203a46e,&DAT_030050d0), iVar4 == 0)) goto LAB_080d1c70;
    if (*(char *)(iVar2 + 0xc) != '\0') {
LAB_080d1c58:
      iVar2 = sub_080D1AD8(&DAT_0203a46e,&DAT_030050d8);
      if (iVar2 == 0) goto LAB_080d1c70;
    }
  }
  else {
    uVar5 = 0;
    do {
      uVar3 = sub_080C0148(uVar5 + 0x8000 & 0xffff);
      iVar2 = sub_080D1AD8(&DAT_0203a46e,uVar3);
      if (iVar2 == 0) goto LAB_080d1c70;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 3);
    if ((((DAT_0203a454 != 0x8000) && (iVar2 = sub_080D1AD8(&DAT_0203a46e,0x30050c0), iVar2 == 0))
        || ((DAT_0203a454 != 0x8001 && (iVar2 = sub_080D1AD8(&DAT_0203a46e,0x30050c8), iVar2 == 0)))
        ) || ((DAT_0203a454 != 0x8002 && (iVar2 = sub_080D1AD8(&DAT_0203a46e,0x30050d0), iVar2 == 0)
              ))) goto LAB_080d1c70;
    if (DAT_0203a454 != 0x8003) goto LAB_080d1c58;
  }
  sub_080C23BC(0x164);
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_080d1c70:
                    /* WARNING: Could not recover jumptable at 0x080d1c78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D1C98 @ 0x080D1C98

void sub_080D1C98(void)

{
  uint arg0;
  uint uVar1;
  ushort *puVar2;
  
  uVar1 = 0;
  puVar2 = (ushort *)0x84f3060;
  do {
    arg0 = (uint)*puVar2;
    sub_080ABF24(arg0);
    sub_080AC438(arg0,uVar1 * 0x40 + 0x2000000);
    puVar2 = puVar2 + 1;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 9);
  DAT_0203a46a = 1;
  DisplayList_Add(0x80d1539,1);
  return;
}


// sub_080D1CE0 @ 0x080D1CE0

void sub_080D1CE0(int arg0)

{
  if ((DAT_030031b8 & 1) == 0) {
    *(ushort *)(arg0 + 0x1c) = DAT_030031b8 & 1;
  }
  else {
    DAT_0203a46a = 0;
    sub_080D155C();
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080D1D14 @ 0x080D1D14

void sub_080D1D14(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  
  sub_080AB91C(DAT_0203a478,0);
  iVar3 = sub_080C2340(0x164);
  if (iVar3 == 0) {
    bVar1 = false;
    bVar2 = false;
    if ((DAT_0203a454 & 0x8000) == 0) {
      iVar3 = sub_080C0148(DAT_0203a454 + 0x8000 & 0xffff);
      if (*(char *)(iVar3 + 0xc) == '\0') {
        bVar2 = true;
      }
    }
    else {
      iVar3 = (DAT_0203a454 & 0x7fff) * 8 + 0x30050c0;
    }
    uVar5 = 0;
    pcVar7 = &DAT_030050df;
    iVar6 = 7;
    do {
      cVar4 = *(char *)((int)&DAT_0203a46e + iVar6);
      if (cVar4 == -1) {
        if (bVar1) {
          cVar4 = '\0';
        }
      }
      else {
        bVar1 = true;
      }
      *(char *)((iVar3 + 7) - uVar5) = cVar4;
      if (bVar2) {
        *pcVar7 = cVar4;
      }
      pcVar7 = pcVar7 + -1;
      iVar6 = iVar6 + -1;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 8);
  }
  sub_080C1440();
  DAT_03000004 = 0;
  sub_080C6E30(0);
  DAT_0200f7dc = 0x5000;
  DAT_0200f7de = 0x5000;
  DAT_0200f7e0 = 0x5000;
  DAT_0200f7e2 = 0x5000;
  Party_BuildMemberNameTiles();
  sub_080C6FD8();
  Font_ResetGlyphSpriteCache(0x180);
  return;
}


// sub_080D1DF4 @ 0x080D1DF4

void sub_080D1DF4(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = 0x81b13b8;
  REG_DMA3DAD = 0x6010000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6001340;
  REG_DMA3CNT = 0x85000070;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D1E34 @ 0x080D1E34

void sub_080D1E34(void)

{
  DisplayList_Add(0x80d1df5,1);
  return;
}


// sub_080D1E48 @ 0x080D1E48

undefined4 sub_080D1E48(undefined4 arg0)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_14;
  
  uVar1 = sub_080AD0FC(0x84f3074,0xffff);
  local_14 = 0;
  CpuSet(&local_14,0x203a454,0x5000200);
  DAT_0203a466 = 4;
  DAT_0203a454 = (undefined2)arg0;
  sub_080C23BC(0x164);
  uVar2 = 0;
  do {
    *(undefined1 *)((int)&DAT_0203a46e + uVar2) = 0xff;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  return uVar1;
}


// sub_080D1EA8 @ 0x080D1EA8

uint sub_080D1EA8(short *arg0)

{
  return (uint)(*arg0 == 0);
}


// sub_080D1EBC @ 0x080D1EBC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D1EBC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  _DAT_0203a45c = 0;
  return;
}


// sub_080D1EE8 @ 0x080D1EE8

void sub_080D1EE8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6014800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D1F0C @ 0x080D1F0C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D1F0C(void)

{
  if ((DAT_0203a454 != 0) && (_DAT_0203a45c == 0)) {
    DisplayList_Add(0x80d1ebd,1);
    _DAT_0203a45c = 1;
  }
  return;
}


// sub_080D1F38 @ 0x080D1F38

void sub_080D1F38(void)

{
  undefined4 uVar1;
  undefined4 in_r2;
  
  LZ77UnCompWram(0x81b5870,0x200f874,in_r2);
  REG_DMA3SAD = 0x20101f4;
  REG_DMA3DAD = 0x200fb14;
  REG_DMA3CNT = 0x84000008;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x81ae5b8;
  REG_DMA3DAD = 0x200fb34;
  REG_DMA3CNT = 0x84000050;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x81ae9b8;
  REG_DMA3DAD = 0x200ff34;
  REG_DMA3CNT = 0x84000050;
  uVar1 = REG_DMA3CNT;
  DisplayList_Add(0x80d1ee9,1);
  return;
}


// sub_080D1FAC @ 0x080D1FAC

void sub_080D1FAC(void)

{
  undefined4 local_c;
  
  local_c = 0;
  CpuSet(&local_c,0x200f874,0x5000400);
  if (DAT_0203a454 != 0) {
    sub_080ACFCC(3,0x81b6ed0,0x3003150,0x20);
    sub_080AABB0();
  }
  sub_080D1F0C();
  return;
}


// sub_080D1FFC @ 0x080D1FFC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D1FFC(void)

{
  if (_DAT_0203a468 != 0) {
    sub_080AB91C(_DAT_0203a468,1);
  }
  if (_DAT_0203a46c != 0) {
    sub_080AB91C(_DAT_0203a46c,1);
  }
  _DAT_0203a468 = 0;
  _DAT_0203a46c = 0;
  return;
}


// sub_080D2028 @ 0x080D2028

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D2028(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a454 == 0) {
    sub_080AB438(0,0x200dfd4,1,7);
  }
  else if (DAT_0203a454 == 1) {
    if (_DAT_0203a46c != 0) {
      sub_080AB438(0,0x200dfd4,0x13,7);
      sub_080AB91C(_DAT_0203a46c,1);
      _DAT_0203a46c = 0;
    }
    if (_DAT_0203a468 == 0) {
      _DAT_0203a468 = sub_080ABD04(1,7,0x1c,4);
      sub_080ABA3C(_DAT_0203a468 + 0x24,1,7,0x1c);
    }
  }
  else if (DAT_0203a454 == 2) {
    if (_DAT_0203a468 != 0) {
      sub_080AB438(0,0x200dfd4,1,7);
      sub_080AB91C(_DAT_0203a468,1);
      _DAT_0203a468 = 0;
    }
    if (_DAT_0203a46c == 0) {
      _DAT_0203a46c = sub_080ABD04(0x13,7,10,4);
      sub_080ABA3C(_DAT_0203a46c + 0x24,0x13,7,10);
    }
  }
  else if ((ushort)(DAT_0203a454 - 3U) < 2) {
    if (_DAT_0203a46c != 0) {
      sub_080AB438(0,0x200dfd4,0x13,7);
      sub_080AB91C(_DAT_0203a46c,1);
      _DAT_0203a46c = 0;
    }
    if (_DAT_0203a468 == 0) {
      if (DAT_0203a454 == 3) {
        _DAT_0203a468 = sub_080ABD04(0xe,4,0xf,4);
        sub_080ABA3C(_DAT_0203a468 + 0x24,0xe,4,0xf);
      }
      else {
        _DAT_0203a468 = sub_080ABD04(0xe,0,0xf,0xb);
        sub_080ABA3C(_DAT_0203a468 + 0x24,0xe,1,0xf);
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080d21bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D21C4 @ 0x080D21C4

void sub_080D21C4(undefined2 *arg0)

{
  undefined2 uVar1;
  undefined2 *in_r1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a454 == 1) {
    *arg0 = 1;
    uVar1 = 5;
  }
  else {
    if (DAT_0203a454 < 2) {
      if (DAT_0203a454 != 0) goto LAB_080d21f2;
    }
    else if (DAT_0203a454 != 2) goto LAB_080d21f2;
    *arg0 = 1;
    uVar1 = 9;
  }
  *in_r1 = uVar1;
LAB_080d21f2:
                    /* WARNING: Could not recover jumptable at 0x080d21f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D21F8 @ 0x080D21F8

void sub_080D21F8(void)

{
  undefined1 local_18 [4];
  
  if (1 < (ushort)(DAT_0203a454 - 3U)) {
    sub_080AB438(0,0x200dfd4,1,5);
    sub_080D21C4(local_18);
    sub_080AB250(0x81b8170,0x200dfd4,0,0);
    sub_080C6764();
  }
  return;
}


// sub_080D2268 @ 0x080D2268

undefined4 sub_080D2268(undefined4 arg0)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((0x57 < (ushort)arg0) && (uVar1 = 1, 0x6f < (ushort)arg0)) &&
      (uVar1 = 6, 0x7f < (ushort)arg0)) &&
     (((uVar1 = 2, 0x93 < (ushort)arg0 && (uVar1 = 3, 0xa7 < (ushort)arg0)) &&
      (uVar1 = 5, (ushort)arg0 < 0xbc)))) {
    uVar1 = 4;
  }
  return uVar1;
}


// sub_080D229C @ 0x080D229C

void sub_080D229C(uint arg0,int arg1)

{
  uint uVar1;
  
  uVar1 = sub_080D2268(arg0 & 0xffff);
  sub_080C00DC((uint)*(byte *)(arg1 + 0xc),uVar1 & 0xffff);
  return;
}


// StatsPage_DrawLabelGrid @ 0x080D22C0

void StatsPage_DrawLabelGrid(void)

{
  undefined4 arg1;
  uint arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  arg1 = sub_080C0148(DAT_0203a45a + 0x8000 & 0xffff);
  arg0 = (uint)DAT_0203a458;
  sub_080D229C(arg0,arg1);
  if (arg0 < 0x80) {
    Font_DrawGlyph(0x8f1,0x200f874,0xf,0);
    Font_DrawGlyph(0x861,0x200f874,0x1b,0);
    sub_080CD330(arg0,0x2b,3,4);
    Font_DrawGlyph(0xffe,0x200f874,0x51,0);
    Font_DrawGlyph(0xcd3,0x200f874,0x5d,0);
    sub_080CD38C(arg0,0x6f,3,4);
    Font_DrawGlyph(0x8f1,0x200f874,0x95,0);
    Font_DrawGlyph(0x861,0x200f874,0xa1,0);
    Font_DrawGlyph(0x699,0x200f874,0xad,0);
    Font_DrawGlyph(0xb67,0x200f874,0xb9,0);
    sub_080CD3E8(arg0,0xcb,3,4);
    Font_DrawGlyph(0xd14,0x200f874,0xf,0xd);
    Font_DrawGlyph(0x669,0x200f874,0x1b,0xd);
    Font_DrawGlyph(0x8d7,0x200f874,0x27,0xd);
    Font_DrawGlyph(0x672,0x200f874,0x33,0xd);
    sub_080CD50C(arg0,0x50,0x10);
    Font_DrawGlyph(0xc3e,0x200f874,0x94,0xd);
    Font_DrawGlyph(0xb7e,0x200f874,0xa0,0xd);
    sub_080CD45C(arg0,0xb0,0x10);
  }
  else {
    Font_DrawGlyph(0xfa9,0x200f874,0xf,0);
    Font_DrawGlyph(0x8c3,0x200f874,0x1b,0);
    sub_080CD668(arg0,0x2b,3,4);
    Font_DrawGlyph(0x699,0x200f874,0x51,0);
    Font_DrawGlyph(0xeb7,0x200f874,0x5d,0);
    sub_080CD6C4(arg0,0x6f,3,4);
    Font_DrawGlyph(0xc1a,0x200f874,0x94,0);
    Font_DrawGlyph(0xb7e,0x200f874,0xa0,0);
    sub_080CD8C4(arg0,0xb4,0);
    Font_DrawGlyph(0xd14,0x200f874,0xf,0xd);
    Font_DrawGlyph(0x669,0x200f874,0x1b,0xd);
    Font_DrawGlyph(0x8d7,0x200f874,0x27,0xd);
    Font_DrawGlyph(0x672,0x200f874,0x33,0xd);
    sub_080CD720(arg0,0x50,0x10);
    Font_DrawGlyph(0xc3e,0x200f874,0x94,0xd);
    Font_DrawGlyph(0xb7e,0x200f874,0xa0,0xd);
    sub_080CD45C(arg0,0xb4,0x10);
  }
                    /* WARNING: Could not recover jumptable at 0x080d24d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D2508 @ 0x080D2508

void sub_080D2508(int arg0,uint arg1)

{
  uint uVar1;
  
  uVar1 = sub_080D2268(arg1 & 0xffff);
  CpuSet(arg0,&DAT_0203a470,0x4000020);
  sub_080C0074((uint)*(byte *)(arg0 + 0xc),uVar1 & 0xffff,arg1 & 0xffff);
  sub_080BF938((uint)*(byte *)(arg0 + 0xc));
  return;
}


// sub_080D2554 @ 0x080D2554

void sub_080D2554(undefined4 arg0)

{
  CpuSet(&DAT_0203a470,arg0,0x4000020);
  return;
}


// StatsPage_DrawBaseStats @ 0x080D2570

void StatsPage_DrawBaseStats(void)

{
  char cVar1;
  int arg1;
  undefined4 uVar2;
  uint arg0;
  
  arg1 = sub_080C0148(DAT_0203a45a + 0x8000 & 0xffff);
  arg0 = (uint)DAT_0203a458;
  sub_080D229C(arg0,arg1);
  sub_080D2508(arg1,arg0);
  Font_DrawGlyph(0x10cb,0x200f874,0xf,1);
  uVar2 = 4;
  if (DAT_0203a4b0 < *(char *)(arg1 + 0x40)) {
    uVar2 = 8;
  }
  else if (*(char *)(arg1 + 0x40) < DAT_0203a4b0) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(char *)(arg1 + 0x40),0x24,3,uVar2);
  Font_DrawGlyph(0xcba,0x200f874,0x33,1);
  uVar2 = 4;
  cVar1 = *(char *)(arg1 + 0x41);
  if (DAT_0203a4b1 < cVar1) {
    uVar2 = 8;
  }
  else if (cVar1 < DAT_0203a4b1) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(char *)(arg1 + 0x41),0x48,3,uVar2);
  Font_DrawGlyph(0xfc3,0x200f874,0x57,1);
  uVar2 = 4;
  cVar1 = *(char *)(arg1 + 0x42);
  if (DAT_0203a4b2 < cVar1) {
    uVar2 = 8;
  }
  else if (cVar1 < DAT_0203a4b2) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(char *)(arg1 + 0x42),0x6c,3,uVar2);
  Font_DrawGlyph(0xc5c,0x200f874,0x7e,1);
  uVar2 = 4;
  cVar1 = *(char *)(arg1 + 0x43);
  if (DAT_0203a4b3 < cVar1) {
    uVar2 = 8;
  }
  else if (cVar1 < DAT_0203a4b3) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(char *)(arg1 + 0x43),0x93,3,uVar2);
  Font_DrawGlyph(0xc3c,0x200f874,0xa2,1);
  uVar2 = 4;
  cVar1 = *(char *)(arg1 + 0x44);
  if (DAT_0203a4b4 < cVar1) {
    uVar2 = 8;
  }
  else if (cVar1 < DAT_0203a4b4) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(char *)(arg1 + 0x44),0xb7,3,uVar2);
  Font_DrawGlyph(0x606,0x200f874,0xc6,1);
  uVar2 = 4;
  cVar1 = *(char *)(arg1 + 0x45);
  if (DAT_0203a4b5 < cVar1) {
    uVar2 = 8;
  }
  else if (cVar1 < DAT_0203a4b5) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(char *)(arg1 + 0x45),0xdb,3,uVar2);
  sub_080D2554(arg1);
  return;
}


// StatsPage_DrawDerivedStats @ 0x080D2788

void StatsPage_DrawDerivedStats(void)

{
  short sVar1;
  int arg1;
  undefined4 uVar2;
  uint arg0;
  
  arg1 = sub_080C0148(DAT_0203a45a + 0x8000 & 0xffff);
  arg0 = (uint)DAT_0203a458;
  sub_080D229C(arg0,arg1);
  sub_080D2508(arg1,arg0);
  Font_DrawGlyph(0x8f1,0x200f874,0x1d,1);
  Font_DrawGlyph(0x861,0x200f874,0x29,1);
  uVar2 = 4;
  if (DAT_0203a4b8 < *(short *)(arg1 + 0x48)) {
    uVar2 = 8;
  }
  else if (*(short *)(arg1 + 0x48) < DAT_0203a4b8) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(short *)(arg1 + 0x48),0x47,3,uVar2);
  Font_DrawGlyph(0xffe,0x200f874,0x1d,0xd);
  Font_DrawGlyph(0xcd3,0x200f874,0x29,0xd);
  uVar2 = 4;
  sVar1 = *(short *)(arg1 + 0x4a);
  if (DAT_0203a4ba < sVar1) {
    uVar2 = 8;
  }
  else if (sVar1 < DAT_0203a4ba) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(short *)(arg1 + 0x4a),0x47,0xf,uVar2);
  Font_DrawGlyph(0x8f1,0x200f874,0x68,1);
  Font_DrawGlyph(0x861,0x200f874,0x74,1);
  uVar2 = 4;
  sVar1 = *(short *)(arg1 + 0x4c);
  if (DAT_0203a4bc < sVar1) {
    uVar2 = 8;
  }
  else if (sVar1 < DAT_0203a4bc) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(short *)(arg1 + 0x4c),0x92,3,uVar2);
  Font_DrawGlyph(0xffe,0x200f874,0x68,0xd);
  Font_DrawGlyph(0xcd3,0x200f874,0x74,0xd);
  uVar2 = 4;
  sVar1 = *(short *)(arg1 + 0x4e);
  if (DAT_0203a4be < sVar1) {
    uVar2 = 8;
  }
  else if (sVar1 < DAT_0203a4be) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(short *)(arg1 + 0x4e),0x92,0xf,uVar2);
  sub_080D2554(arg1);
  return;
}


// StatsPage_DrawDerivedStats2 @ 0x080D295C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StatsPage_DrawDerivedStats2(void)

{
  short sVar1;
  int arg1;
  undefined4 uVar2;
  uint arg0;
  
  arg1 = sub_080C0148(DAT_0203a45a + 0x8000 & 0xffff);
  arg0 = (uint)DAT_0203a458;
  sub_080D229C(arg0,arg1);
  sub_080D2508(arg1,arg0);
  Font_DrawGlyph(0xfc3,0x200f874,0xf,1);
  Font_DrawGlyph(0xf81,0x200f874,0x1b,1);
  Font_DrawGlyph(0x5bb,0x200f874,0x27,1);
  Font_DrawGlyph(0x10cb,0x200f874,0x33,1);
  uVar2 = 4;
  if (_DAT_0203a4c4 < *(short *)(arg1 + 0x54)) {
    uVar2 = 8;
  }
  else if (*(short *)(arg1 + 0x54) < _DAT_0203a4c4) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(short *)(arg1 + 0x54),0x51,3,uVar2);
  Font_DrawGlyph(0xfc3,0x200f874,0xf,0xd);
  Font_DrawGlyph(0xf81,0x200f874,0x1b,0xd);
  Font_DrawGlyph(0x8d7,0x200f874,0x27,0xd);
  Font_DrawGlyph(0x672,0x200f874,0x33,0xd);
  uVar2 = 4;
  sVar1 = *(short *)(arg1 + 0x56);
  if (DAT_0203a4c6 < sVar1) {
    uVar2 = 8;
  }
  else if (sVar1 < DAT_0203a4c6) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(short *)(arg1 + 0x56),0x51,0xf,uVar2);
  Font_DrawGlyph(0xfa9,0x200f874,0x68,1);
  Font_DrawGlyph(0x8c3,0x200f874,0x74,1);
  uVar2 = 4;
  sVar1 = *(short *)(arg1 + 0x50);
  if (DAT_0203a4c0 < sVar1) {
    uVar2 = 8;
  }
  else if (sVar1 < DAT_0203a4c0) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(short *)(arg1 + 0x50),0x92,3,uVar2);
  Font_DrawGlyph(0x699,0x200f874,0x68,0xd);
  Font_DrawGlyph(0xeb7,0x200f874,0x74,0xd);
  uVar2 = 4;
  sVar1 = *(short *)(arg1 + 0x52);
  if (DAT_0203a4c2 < sVar1) {
    uVar2 = 8;
  }
  else if (sVar1 < DAT_0203a4c2) {
    uVar2 = 10;
  }
  sub_080CCFC4((int)*(short *)(arg1 + 0x52),0x92,0xf,uVar2);
  sub_080D2554(arg1);
  return;
}


// Menu_DrawItemNameTriple @ 0x080D2B70

void Menu_DrawItemNameTriple(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_r8;
  int unaff_r9;
  code *UNRECOVERED_JUMPTABLE;
  
  Text_DrawStringTinted(0x84f311e,0x200f874,0,1);
  uVar3 = 0;
  do {
    uVar2 = (uint)*(ushort *)(&DAT_0203a4f0 + uVar3 * 2);
    if (uVar2 != 0xffff) {
      if (uVar2 < 0xd0) {
        iVar1 = sub_080BF32C(uVar2);
        iVar1 = iVar1 + 0x14;
      }
      else {
        iVar1 = Action_GetRecord(uVar2);
        iVar1 = iVar1 + 0xc;
      }
      if (uVar3 == 1) {
        unaff_r9 = 0x80;
        unaff_r8 = 0;
      }
      else if (uVar3 < 2) {
        if (uVar3 == 0) {
          unaff_r9 = 0;
LAB_080d2bf8:
          unaff_r8 = 0xd;
        }
      }
      else if (uVar3 == 2) {
        unaff_r9 = 0x80;
        goto LAB_080d2bf8;
      }
      uVar2 = 0;
      do {
        Font_DrawGlyphTinted
                  ((uint)*(ushort *)(uVar2 * 2 + iVar1),0x200f874,uVar2 * 0xc + unaff_r9 & 0xffff,
                   unaff_r8);
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < 8);
    }
    uVar3 = uVar3 + 1 & 0xffff;
    if (2 < uVar3) {
                    /* WARNING: Could not recover jumptable at 0x080d2c3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  } while( true );
}


// Menu_DrawSkillRowTriple @ 0x080D2C44

void Menu_DrawSkillRowTriple(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_r8;
  int unaff_r9;
  code *UNRECOVERED_JUMPTABLE;
  
  Text_DrawStringTinted(0x84f312c,0x200f874,0,1);
  uVar3 = 0;
  do {
    if (*(ushort *)(&DAT_0203a4f0 + uVar3 * 2) != 0xffff) {
      iVar1 = sub_080BF648((uint)*(ushort *)(&DAT_0203a4f0 + uVar3 * 2));
      if (uVar3 == 1) {
        unaff_r9 = 0x80;
        unaff_r8 = 0;
      }
      else if (uVar3 < 2) {
        if (uVar3 == 0) {
          unaff_r9 = 0;
LAB_080d2cb8:
          unaff_r8 = 0xd;
        }
      }
      else if (uVar3 == 2) {
        unaff_r9 = 0x80;
        goto LAB_080d2cb8;
      }
      uVar2 = 0;
      do {
        Font_DrawGlyphTinted
                  ((uint)*(ushort *)(uVar2 * 2 + iVar1 + 0x22),0x200f874,
                   uVar2 * 0xc + unaff_r9 & 0xffff,unaff_r8);
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < 8);
    }
    uVar3 = uVar3 + 1 & 0xffff;
    if (2 < uVar3) {
                    /* WARNING: Could not recover jumptable at 0x080d2cfe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  } while( true );
}


// sub_080D2D04 @ 0x080D2D04

undefined4 sub_080D2D04(uint arg0)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar3 = Action_GetRecord(arg0 & 0xffff);
  psVar5 = *(short **)(iVar3 + 0x1c);
  sVar2 = 0;
  if (0xd0 < (arg0 & 0xffff)) {
    if (psVar5 == (short *)0x0) {
      sVar2 = 0;
    }
    else {
      sVar1 = *psVar5;
      while ((sVar1 != 0 && (sVar1 != 0x301))) {
        if (sVar1 == 0x300) {
          sVar2 = sVar2 + 1;
        }
        psVar5 = psVar5 + 1;
        sVar1 = *psVar5;
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080d2d50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(sVar2);
  return uVar4;
}


// sub_080D2D58 @ 0x080D2D58

void sub_080D2D58(void)

{
  sub_080CCEC8(0x84f313c,0x9e,0xe,0);
  sub_080CCFC4(DAT_0203db2c,0xde,0xe,0);
  return;
}


// Item_RenderDescription @ 0x080D2D80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Item_RenderDescription(undefined4 arg0)

{
  short sVar1;
  int iVar2;
  ushort *arg0_00;
  ushort *puVar3;
  uint arg2;
  uint arg3;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_20;
  
  local_20 = 0;
  CpuSet(&local_20,0x200f874,0x5000400);
  sub_080D1F0C();
  DAT_03003bb4 = 0;
  if (DAT_0203a454 != 0) {
    if (DAT_0203a454 == 2) {
      sub_080CCE5C(0x84f3140,0x99,2,0);
      sub_080D2D58();
      sub_080D1F0C();
    }
    else if (DAT_0203a454 == 3) {
      Menu_DrawItemNameTriple();
      sub_080D1F0C();
    }
    else if (DAT_0203a454 == 4) {
      Menu_DrawSkillRowTriple();
      sub_080D1F0C();
    }
    else {
      if (DAT_0203a458 < 0xd0) {
        if (DAT_0203a456 == 1) {
          StatsPage_DrawBaseStats();
        }
        else if (DAT_0203a456 < 2) {
          if (DAT_0203a456 == 0) {
            StatsPage_DrawLabelGrid();
          }
        }
        else if (DAT_0203a456 == 2) {
          StatsPage_DrawDerivedStats();
        }
        else if (DAT_0203a456 == 3) {
          StatsPage_DrawDerivedStats2();
        }
      }
      else {
        iVar2 = Action_GetRecord((uint)DAT_0203a458);
        arg0_00 = *(ushort **)(iVar2 + 0x1c);
        arg2 = 9;
        arg3 = 0;
        if (arg0_00 != (ushort *)0x0) {
          if (DAT_0203a466 < 2) {
            Text_DrawString(arg0_00,0x200f874,9,0);
          }
          else if (_DAT_0203a464 == 0) {
            sVar1 = 0;
            if (*arg0_00 != 0x300) goto LAB_080d2e88;
            sVar1 = 1;
            do {
              arg2 = 9;
              arg3 = arg3 + 0xc & 0xffff;
              while (arg0_00 = arg0_00 + 1, *arg0_00 != 0x300) {
LAB_080d2e88:
                Font_DrawGlyph((uint)*arg0_00,0x200f874,arg2,arg3);
                arg2 = arg2 + 0xc & 0xffff;
              }
              sVar1 = sVar1 + 1;
            } while (sVar1 != 2);
          }
          else {
            sVar1 = 0;
            if (*arg0_00 == 0x300) {
              sVar1 = 1;
            }
            do {
              do {
                puVar3 = arg0_00;
                arg0_00 = puVar3 + 1;
              } while (*arg0_00 != 0x300);
              sVar1 = sVar1 + 1;
            } while (sVar1 != 2);
            Text_DrawString(puVar3 + 2,0x200f874,9,0);
          }
        }
      }
      sub_080D1F0C();
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080d2f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D2F04 @ 0x080D2F04

void sub_080D2F04(uint arg0,int arg1,undefined4 arg2)

{
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  
  if ((arg0 & 0xffff) != 0xffff) {
    iVar1 = sub_080BF648(arg0 & 0xffff);
    uVar4 = 0;
    puVar2 = (ushort *)(iVar1 + 0x22);
    if (*(short *)(iVar1 + 0x22) != 0) {
      uVar3 = arg1 << 0x10;
      do {
        FontSprite_DrawGlyph((uint)*puVar2,0,0,uVar3 >> 0x10);
        puVar2 = puVar2 + 1;
        uVar3 = uVar3 + 0xc0000;
        uVar4 = uVar4 + 1;
        if (7 < uVar4) {
          return;
        }
      } while (*puVar2 != 0);
    }
  }
  return;
}


// sub_080D2F60 @ 0x080D2F60

void sub_080D2F60(void)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  ushort local_10;
  ushort local_e;
  
  local_10 = 0;
  local_e = 0x3b;
  if ((ushort)(DAT_0203a454 - 3U) < 2) {
    local_10 = 0x72;
    if (DAT_0203a454 == 3) {
      local_e = 0x22;
    }
    else {
      local_e = 2;
      sub_080D2F04((uint)DAT_0203a4f6,0x70,0x35);
      sub_080D2F04((uint)(ushort)DAT_0203a4f8,local_10 - 2 & 0xffff,local_e + 0x40 & 0xffff);
    }
    sub_080AA1F4(0x84f3148,0,0,0);
    sub_080AA1F4(0x84f3148,0,0,0);
    sub_080AA1F4(0x84f3148,0,0,0);
    sub_080AA1F4(0x84f3148,0,0,0);
    sub_080AA1F4(0x84f3148,0,0,0);
    sub_080AA1F4(0x84f3148,0,0,0);
    sub_080AA1F4(0x84f3148,0,0,0);
    sub_080AA1F4(0x84f3148,0,0,0);
  }
  else {
    if (DAT_0203a454 == 2) {
      sub_080AC7CC(0,0x200f874,0x9e,0xc);
      sub_080D2D58();
      sub_080D1F0C();
    }
    if (DAT_0203a454 != 0) {
      uVar1 = 0;
      do {
        sub_080AA1F4(0x84f3148,0,0,0);
        uVar1 = uVar1 + 1;
      } while (uVar1 < 8);
    }
    sub_080D21C4(&local_10);
    sub_080C7664((uint)local_10,(uint)local_e,DAT_03005198);
  }
                    /* WARNING: Could not recover jumptable at 0x080d315e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D3170 @ 0x080D3170

void sub_080D3170(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  if ((short)arg3 == 1) {
    sub_080AA184(*(undefined4 *)((arg0 & 0xffff) * 4 + 0x84f3150),0,0,0);
    sub_080AA1F4(0x84f316c,0,0,0);
  }
  else {
    sub_080AA184(*(undefined4 *)((arg0 & 0xffff) * 4 + 0x84f3150),0,0,0);
  }
  return;
}


// sub_080D31F8 @ 0x080D31F8

void sub_080D31F8(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = sub_080A9CC0(arg0);
  bVar1 = false;
  uVar3 = 0;
  do {
    if (((bVar1) || (*(char *)((iVar2 + 7) - uVar3) != '\0')) || (uVar3 == 7)) {
      sub_080AA1F4(0x84f3174,0,arg3 & 0xffff,0);
      bVar1 = true;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  return;
}


// sub_080D3264 @ 0x080D3264

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D3264(undefined4 arg0)

{
  bool bVar1;
  dword arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  int iStack_10;
  
  if (DAT_0203a454 != 1) goto LAB_080d33f8;
  if (0xcf < DAT_0203a458) {
    if (1 < DAT_0203a466) {
      if ((_DAT_0203a464 == 0) && ((DAT_030031b8 & 0x10) != 0)) {
        _DAT_0203a464 = 1;
        sub_080C51D4(100);
        Item_RenderDescription(arg0);
      }
      else if ((_DAT_0203a464 == 1) && ((DAT_030031b8 & 0x20) != 0)) {
        _DAT_0203a464 = 0;
        sub_080C51D4(100);
        Item_RenderDescription(arg0);
      }
      if ((_DAT_0203a464 != 0) || (sub_080C4B78(0,0,0xe6,0x46), _DAT_0203a464 != 0)) {
        sub_080C4B14(0,0,2,0x46);
      }
    }
    goto LAB_080d33f8;
  }
  bVar1 = false;
  if ((DAT_030031b8 & 0x20) == 0) {
    if (((DAT_030031b8 & 0x10) != 0) && (DAT_0203a456 != 3)) {
      DAT_0203a456 = DAT_0203a456 + 1;
      goto LAB_080d332e;
    }
  }
  else if (DAT_0203a456 != 0) {
    DAT_0203a456 = DAT_0203a456 + -1;
LAB_080d332e:
    bVar1 = true;
  }
  if (bVar1) {
    sub_080C51D4(100);
    Item_RenderDescription(arg0);
  }
  DAT_0203a460._0_2_ = (short)DAT_0203a460 + -1;
  if ((short)DAT_0203a460 == 0) {
    DAT_0203a460._0_2_ = 8;
    DAT_0203a45e = DAT_0203a45e + 1 & 1;
  }
  if (DAT_0203a45e == 0) {
    if (DAT_0203a456 != 0) {
      sub_080C4B14(0,0,2,0x46);
    }
    if (DAT_0203a456 != 3) {
      sub_080C4B78(0,0,0xe6,0x46);
    }
  }
  if (DAT_0203a456 != 0) {
    if (DAT_0203a456 == 2) {
      sub_080D3170(0,10,0x3e,0);
      sub_080D3170(1,0x55,0x3e,0);
    }
    goto LAB_080d33f8;
  }
  sub_080BF468((uint)DAT_0203a458,0,&iStack_10);
  if (iStack_10 == 0x80) {
    arg0_00 = 0x80014b0;
  }
  else if (iStack_10 < 0x81) {
    if (iStack_10 != 0x40) goto LAB_080d33f8;
    arg0_00 = 0x80014c0;
  }
  else {
    if (iStack_10 != 0xc0) goto LAB_080d33f8;
    arg0_00 = 0x80014d8;
  }
  sub_080AA184(arg0_00,0,0,0);
LAB_080d33f8:
                    /* WARNING: Could not recover jumptable at 0x080d33fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D3400 @ 0x080D3400

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 sub_080D3400(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 local_20;
  
  uVar1 = sub_080AD0FC(0x84f317c,0xffff);
  local_20 = 0;
  CpuSet(&local_20,0x203a454,0x5000200);
  DAT_0203a456 = 0;
  _DAT_0203a464 = 0;
  DAT_0203a454 = (undefined2)arg0;
  DAT_0203a458 = (ushort)arg2;
  DAT_0203a45a = (undefined2)arg1;
  uVar2 = sub_080D2D04((uint)(ushort)arg2);
  DAT_0203a466 = (short)uVar2;
  DAT_0203a460._0_2_ = 8;
  return uVar1;
}


// sub_080D347C @ 0x080D347C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D347C(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined2 in_stack_00000000;
  
  _DAT_0203a4f0 = (undefined2)arg0;
  DAT_0203a4f2 = (undefined2)arg1;
  _DAT_0203a4f4 = (undefined2)arg2;
  DAT_0203a4f6 = (undefined2)arg3;
  DAT_0203a4f8._0_2_ = in_stack_00000000;
  return;
}


// sub_080D34A4 @ 0x080D34A4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D34A4(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined4 uVar1;
  
  _DAT_0203a464 = 0;
  DAT_0203a458 = (ushort)arg3;
  DAT_0203a45a = (undefined2)arg2;
  uVar1 = sub_080D2D04((uint)(ushort)arg3);
  DAT_0203a466 = (undefined2)uVar1;
  DAT_0203a456 = 0;
  DAT_0203a460._0_2_ = 8;
  DAT_0203a454 = (undefined2)arg1;
  sub_080D2028();
  Item_RenderDescription(arg0);
  sub_080D21F8();
  return;
}


// sub_080D34F0 @ 0x080D34F0

void sub_080D34F0(undefined4 arg0)

{
  sub_080D1FFC();
  if ((ushort)(DAT_0203a454 - 3U) < 2) {
    sub_080AB438(0,0x200dfd4,1,0);
  }
  else {
    sub_080AB438(0,0x200dfd4,1,5);
  }
  sub_080C6558();
  sub_080C6764();
  if (DAT_0203a454 != 0) {
    sub_080ACFA4(3,0,0x3003150,0x20);
    sub_080AABB0();
  }
  sub_080AD1FC(arg0);
  return;
}


// sub_080D3574 @ 0x080D3574

void sub_080D3574(void)

{
  int iVar1;
  
  iVar1 = DAT_03003fec;
  sub_080AB250(0x81b8170,0x200dfd4,0,0);
  if (*(int *)(iVar1 + 0x24) == 2) {
    sub_080AB250(0x81b8170,0x200dfd4,0,0);
  }
  sub_080C6764();
  return;
}


// sub_080D35DC @ 0x080D35DC

void sub_080D35DC(void)

{
  sub_080AB438(0,0x200dfd4,0x15,7);
  sub_080AB438(0,0x200dfd4,0x15,9);
  sub_080C6764();
  return;
}


// sub_080D3618 @ 0x080D3618

void sub_080D3618(void)

{
  int iVar1;
  
  iVar1 = DAT_03003fec;
  sub_080C7664(0x15,7,DAT_03005198);
  if (*(int *)(iVar1 + 0x24) == 2) {
    sub_080C7664(0x15,9,*(undefined4 *)(iVar1 + 0x28));
  }
  return;
}


// sub_080D3654 @ 0x080D3654

void sub_080D3654(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x84f31e0,0xffff);
  DAT_03003fec = iVar1;
  *(undefined4 *)(iVar1 + 0x24) = arg0;
  *(undefined4 *)(iVar1 + 0x28) = arg1;
  return;
}


// sub_080D367C @ 0x080D367C

void sub_080D367C(undefined4 arg0)

{
  *(undefined4 *)(DAT_03003fec + 0x28) = arg0;
  return;
}


// sub_080D3688 @ 0x080D3688

void sub_080D3688(void)

{
  *(undefined4 *)(DAT_03003fec + 0xc) = 1;
  return;
}


// sub_080D3698 @ 0x080D3698

void sub_080D3698(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D36BC @ 0x080D36BC

void sub_080D36BC(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080ABCD4(0x17,0,6,3);
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  REG_DMA3SAD = 0x81b5710;
  REG_DMA3DAD = 0x200bec8;
  REG_DMA3CNT = 0x84000040;
  uVar1 = REG_DMA3CNT;
  DisplayList_Add(0x80d3699,1);
  return;
}


// sub_080D3708 @ 0x080D3708

void sub_080D3708(void)

{
  undefined4 arg0;
  
  sub_080AA184(0x8002a4c,0,0,0);
  arg0 = sub_080C31F0();
  sub_080C8048(arg0,0xb8,0xb,0);
  return;
}


// sub_080D3740 @ 0x080D3740

undefined4 sub_080D3740(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080AD0FC(0x84f3204,0xffff);
  return uVar1;
}


// sub_080D3758 @ 0x080D3758

void sub_080D3758(int arg0)

{
  sub_080ABD30(*(undefined4 *)(arg0 + 0x24),1);
  sub_080AD1FC(arg0);
  return;
}


// sub_080D3770 @ 0x080D3770

void sub_080D3770(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080DABCC(0);
  *(short *)(arg0 + 0x2c) = (short)uVar1;
  sub_080AB250(0x81b8170,0x200dfd4,0,0);
  uVar1 = sub_080ABCD4(1,0,0xe,0xb);
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  return;
}


// CasinoPrize_DrawRows @ 0x080D37BC

void CasinoPrize_DrawRows(int arg0)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint arg0_00;
  
  uVar1 = *(ushort *)(arg0 + 0x2c);
  sub_080C49EC(0xb,0,0,0xc);
  uVar5 = 0;
  do {
    arg0_00 = (uint)*(ushort *)((*(ushort *)(arg0 + 0x2a) + uVar5) * 2 + 0x203b454);
    uVar5 = uVar5 + 1;
    if (arg0_00 != 0) {
      iVar2 = Action_GetRecord(arg0_00);
      puVar3 = (ushort *)(iVar2 + 0xc);
      uVar6 = 0xc0000;
      do {
        iVar4 = sub_080C5B10(arg0_00);
        if (iVar4 == 0) {
          sub_080AC2A0((uint)*puVar3,0,0,uVar6 >> 0x10);
        }
        else {
          FontSprite_DrawGlyph((uint)*puVar3,0,0,uVar6 >> 0x10);
        }
        uVar6 = uVar6 + 0xc0000;
        puVar3 = puVar3 + 1;
      } while (puVar3 <= (ushort *)(iVar2 + 0x1a));
    }
  } while (uVar5 < 6);
  sub_080C7664(0x15,0,DAT_03005198);
  if (*(short *)(arg0 + 0x2a) != 0) {
    sub_080C4A4C(0,0,0x6c,0);
  }
  if ((int)(*(ushort *)(arg0 + 0x2a) + 6) <= (int)(uVar1 - 1)) {
    sub_080C4AB0(0,0,0x6c,0x50);
  }
  return;
}


