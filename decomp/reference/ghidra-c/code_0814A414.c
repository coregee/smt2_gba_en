/* Ghidra decompilation of asm/code_0814A414.s (reference only; not compiled). */

// sub_0814A414 @ 0x0814A414

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814A414(void)

{
  int iVar1;
  
  if ((DAT_030031bc & 3) == 0) {
    sub_080C51D4(0x159);
    if ((DAT_03003964 & 1) == 0) {
      iVar1 = 5;
    }
    else {
      iVar1 = _DAT_0203a480;
      sub_0814A36C(_DAT_0203a480);
    }
    _DAT_0203a480 = _DAT_0203a480 - iVar1;
    DAT_0203a47c = DAT_0203a47c + iVar1;
    DAT_0203a48c = iVar1;
    if (_DAT_0203a480 < 1) {
      DAT_0203a47c = _DAT_0203a488 + _DAT_0203a484;
      _DAT_0203a484 = 0;
      DAT_0203a460._0_2_ = 0;
      sub_080C3328((uint)*(ushort *)
                          ((uint)DAT_0203a498._2_2_ * 4 + (uint)DAT_0203a6b6 * 0x2c + 0x879e2a4));
      DAT_0203a498._2_2_ = 0;
      DAT_0203a46e._0_1_ = 99;
      DAT_0203a458._0_1_ = 7;
    }
  }
  return;
}


// sub_0814A4AC @ 0x0814A4AC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814A4AC(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = sub_080C2244();
  _DAT_0203a4a8 = (ushort)uVar1 & 5;
  uVar2 = (uint)DAT_0203a466 + (uint)_DAT_0203a4a8;
  if (9 < uVar2) {
    uVar2 = uVar2 - 10;
  }
  DAT_0203a466 = (short)uVar2;
  DAT_0203a45a = DAT_0203a45a + 1;
  return;
}


// sub_0814A4DC @ 0x0814A4DC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814A4DC(void)

{
  dword arg0;
  
  DAT_0203a478._2_1_ = 0;
  if (_DAT_0203a470 < 4) {
    sub_080AA184(0x814f970,0,0,0);
  }
  else {
    if ((ushort)(_DAT_0203a474 - 4) < 3) {
      arg0 = 0x814f988;
    }
    else {
      if ((_DAT_0203a470 < 7) || (9 < _DAT_0203a474)) {
        if (9 < _DAT_0203a470) {
          DAT_0203a478._0_1_ = 1;
        }
        goto LAB_0814a55a;
      }
      arg0 = 0x814f9a0;
    }
    sub_080AA184(arg0,0,0,0);
  }
LAB_0814a55a:
  _DAT_0203a474 = _DAT_0203a474 + 1;
  return;
}


// sub_0814A568 @ 0x0814A568

void sub_0814A568(void)

{
  dword arg0;
  
  DAT_0203a478._3_1_ = 0;
  if (DAT_0203a472 < 4) {
    arg0 = 0x814f970;
  }
  else if ((ushort)(DAT_0203a472 - 4) < 3) {
    arg0 = 0x814f988;
  }
  else {
    if (2 < (ushort)(DAT_0203a472 - 7)) {
      if (9 < DAT_0203a472) {
        DAT_0203a478._1_1_ = 1;
      }
      goto LAB_0814a5e0;
    }
    arg0 = 0x814f9a0;
  }
  sub_080AA184(arg0,1,0,0);
LAB_0814a5e0:
  DAT_0203a472 = DAT_0203a472 + 1;
  return;
}


// sub_0814A5F0 @ 0x0814A5F0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814A5F0(void)

{
  dword arg0;
  
  if (_DAT_0203a474 < 4) {
    arg0 = 0x814f9a0;
  }
  else if ((ushort)(_DAT_0203a474 - 4) < 3) {
    arg0 = 0x814f988;
  }
  else {
    if (2 < (ushort)(_DAT_0203a474 - 7)) {
      if (9 < _DAT_0203a474) {
        sub_080AA184(0x814f958,0,0,0);
        DAT_0203a478._2_1_ = 1;
        DAT_0203a478._0_1_ = 0;
      }
      goto LAB_0814a672;
    }
    arg0 = 0x814f970;
  }
  sub_080AA184(arg0,0,0,0);
LAB_0814a672:
  _DAT_0203a474 = _DAT_0203a474 + 1;
  return;
}


// sub_0814A684 @ 0x0814A684

void sub_0814A684(void)

{
  dword arg0;
  
  if (DAT_0203a476 < 4) {
    arg0 = 0x814f9a0;
  }
  else if ((ushort)(DAT_0203a476 - 4) < 3) {
    arg0 = 0x814f988;
  }
  else {
    if (2 < (ushort)(DAT_0203a476 - 7)) {
      if (9 < DAT_0203a476) {
        sub_080AA184(0x814f958,1,0,0);
        DAT_0203a478._3_1_ = 1;
        DAT_0203a478._1_1_ = 0;
      }
      goto LAB_0814a706;
    }
    arg0 = 0x814f970;
  }
  sub_080AA184(arg0,1,0,0);
LAB_0814a706:
  DAT_0203a476 = DAT_0203a476 + 1;
  return;
}


// sub_0814A718 @ 0x0814A718

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814A718(void)

{
  ushort uVar1;
  
  if ((DAT_0203a490._2_2_ == 0) && ((ushort)DAT_0203a494 < 0xa3)) {
    DAT_0203a490._0_1_ = '\x01';
    if (((char)DAT_0203a46e == '\0') || ((char)DAT_0203a46e == 'c')) {
      sub_080C51D4(0x163);
    }
    else {
      sub_080C51D4(0x15e);
    }
  }
  if (((char)DAT_0203a490 == '\x01') &&
     (DAT_0203a490._2_2_ = DAT_0203a490._2_2_ + 1, DAT_0203a490._2_2_ == 0x14)) {
    DAT_0203a490._0_1_ = '\0';
  }
  if (((char)DAT_0203a46e == '\0') || ((char)DAT_0203a46e == 'c')) {
    sub_080AA184(0x814f7dc,0,0,0);
  }
  else {
    sub_080AA184(0x814f7c0,0,0,0);
    sub_0814A9A4();
  }
  if (DAT_0203a4aa == 0x3d) {
    DAT_0300000c = DAT_0203a6b4;
    if (DAT_0203a6b4 == 0xf) {
      sub_0814AD74();
      DAT_0300000c = DAT_0300000c - DAT_0203a6b4;
      DAT_0203a6b4 = 0;
      DAT_0203a4aa = DAT_0203a4aa - 4;
    }
    else {
      DAT_0203a6b4 = DAT_0203a6b4 + 1;
    }
  }
  else if ((ushort)(&DAT_0203a4b8)[((uint)DAT_0203a4aa - (uint)DAT_0203a4ac) * 4] < 5) {
    sub_0814AB5C();
  }
  else {
    sub_0814AA70();
  }
  uVar1 = (ushort)DAT_0203a494;
  if ((ushort)DAT_0203a494 == 0) {
    DAT_0203a494._0_2_ = 0x154;
    DAT_0203a490._2_2_ = uVar1;
    if (((char)DAT_0203a46e == '\0') || ((char)DAT_0203a46e == 'c')) {
      DAT_0203a498._2_2_ = uVar1;
      DAT_0203a458._0_1_ = 7;
      _DAT_0203a480 = 0;
      _DAT_0203a484 = 0;
    }
    else {
      DAT_0203a458._0_1_ = 3;
      *(undefined1 *)((int)&DAT_0203a49c + DAT_0203a498._2_2_ + 2) = 1;
      DAT_0203a498._2_2_ = DAT_0203a498._2_2_ + 1;
    }
  }
  if ((char)DAT_0203a490 == '\0') {
    DAT_0203a494._0_2_ = (ushort)DAT_0203a494 - 4;
  }
  return;
}


// sub_0814A8B0 @ 0x0814A8B0

void sub_0814A8B0(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(char *)((int)&DAT_0203a49c + uVar1 + 2) == '\x01') {
      sub_080AA184(*(undefined4 *)(uVar1 * 8 + 0x879de24),0,0,0);
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 10);
  Font_ResetGlyphSpriteCache(0x3a0);
  if ((DAT_0203a498._2_2_ == 2) || (DAT_0203a498._2_2_ == 7)) {
    sub_0814ADAC((uint)DAT_0203a6b6 * 0xc6 + (uint)DAT_0203a498._2_2_ * 0x12 + 0x879df8c,0,0,
                 *(ushort *)
                  (&DAT_0879e2a6 + (uint)DAT_0203a498._2_2_ * 4 + (uint)DAT_0203a6b6 * 0x2c) + 0x46
                 & 0xffff);
  }
  else {
    sub_0814ADAC((uint)DAT_0203a6b6 * 0xc6 + (uint)DAT_0203a498._2_2_ * 0x12 + 0x879df8c,0,0,
                 *(ushort *)
                  (&DAT_0879e2a6 + (uint)DAT_0203a498._2_2_ * 4 + (uint)DAT_0203a6b6 * 0x2c) + 0x4d
                 & 0xffff);
  }
  return;
}


// sub_0814A9A4 @ 0x0814A9A4

void sub_0814A9A4(void)

{
  if (3 < (ushort)DAT_0203a49c) {
    sub_080AA184(*(undefined4 *)((uint)DAT_0203a498._2_2_ * 8 + 0x879de24),0,0,0);
  }
  if (6 < (ushort)DAT_0203a49c) {
    DAT_0203a49c._0_2_ = 0;
  }
  DAT_0203a49c._0_2_ = (ushort)DAT_0203a49c + 1;
  return;
}


// sub_0814AA04 @ 0x0814AA04

void sub_0814AA04(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if ((&DAT_0203a4b4)[uVar1 * 8] == '\x01') {
      sub_080AA184(*(undefined4 *)((uint)(ushort)(&DAT_0203a4b8)[uVar1 * 4] * 4 + 0x879de74),0,0,2);
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x3c);
  return;
}


// sub_0814AA70 @ 0x0814AA70

void sub_0814AA70(void)

{
  dword arg0;
  
  if (DAT_0203a4ae < 4) {
    arg0 = 0x814f900;
  }
  else if ((ushort)(DAT_0203a4ae - 4) < 3) {
    arg0 = 0x814f910;
  }
  else if ((ushort)(DAT_0203a4ae - 7) < 3) {
    arg0 = 0x814f920;
  }
  else {
    if (2 < (ushort)(DAT_0203a4ae - 10)) {
      if ((ushort)(DAT_0203a4ae - 0xd) < 2) {
        sub_080AA184(0x814f940,0,0,0);
        (&DAT_0203a4b4)[(DAT_0203a4aa - 1) * 8] = 1;
      }
      goto LAB_0814ab40;
    }
    arg0 = 0x814f930;
  }
  sub_080AA184(arg0,0,0,0);
LAB_0814ab40:
  DAT_0203a4ae = DAT_0203a4ae + 1;
  return;
}


// sub_0814AB5C @ 0x0814AB5C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814AB5C(void)

{
  dword arg0;
  
  if (_DAT_0203a4b0 < 4) {
    arg0 = 0x814f8b0;
  }
  else if ((ushort)(_DAT_0203a4b0 - 4) < 3) {
    arg0 = 0x814f8c0;
  }
  else if ((ushort)(_DAT_0203a4b0 - 7) < 3) {
    arg0 = 0x814f8d0;
  }
  else {
    if (2 < (ushort)(_DAT_0203a4b0 - 10)) {
      if ((ushort)(_DAT_0203a4b0 - 0xd) < 2) {
        sub_080AA184(0x814f8f0,0,0,0);
        (&DAT_0203a4b4)[(DAT_0203a4aa - 1) * 8] = 1;
      }
      goto LAB_0814ac2c;
    }
    arg0 = 0x814f8e0;
  }
  sub_080AA184(arg0,0,0,0);
LAB_0814ac2c:
  _DAT_0203a4b0 = _DAT_0203a4b0 + 1;
  return;
}


// sub_0814AC48 @ 0x0814AC48

void sub_0814AC48(void)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_0203a4aa == 0) {
    DAT_0203a4aa = 1;
    DAT_0203a4ac = 1;
    DAT_0203a4b8 = DAT_0203a466;
    return;
  }
  uVar2 = (uint)DAT_0203a4aa;
  if ((&DAT_0203a4b8)[(uVar2 - DAT_0203a4ac) * 4] < 5) {
    if (DAT_0203a466 < 5) {
      (&DAT_0203a4b8)[uVar2 * 4] = DAT_0203a466;
      DAT_0203a4aa = DAT_0203a4aa + 1;
      DAT_0203a4ac = 1;
      return;
    }
    uVar1 = uVar2 & 3;
    if (uVar1 == 1) goto LAB_0814ad2c;
    if (uVar1 == 1 || (DAT_0203a4aa & 3) == 0) {
      if ((DAT_0203a4aa & 3) == 0) {
        (&DAT_0203a4b8)[uVar2 * 4] = DAT_0203a466;
        DAT_0203a4aa = DAT_0203a4aa + 1;
        DAT_0203a4ac = 1;
        return;
      }
      return;
    }
    if (uVar1 == 2) {
      (&DAT_0203a4b8)[(uVar2 + 2) * 4] = DAT_0203a466;
      DAT_0203a4aa = DAT_0203a4aa + 3;
      DAT_0203a4ac = 1;
      return;
    }
  }
  else {
    if (4 < DAT_0203a466) {
      (&DAT_0203a4b8)[uVar2 * 4] = DAT_0203a466;
      DAT_0203a4aa = DAT_0203a4aa + 1;
      DAT_0203a4ac = 1;
      return;
    }
    uVar1 = uVar2 & 3;
    if (uVar1 == 1) {
LAB_0814ad2c:
      DAT_0203a4ac = DAT_0203a4aa & 3;
      (&DAT_0203a4b8)[(uVar2 + 3) * 4] = DAT_0203a466;
      DAT_0203a4aa = DAT_0203a4aa + 4;
      return;
    }
    if (uVar1 == 1 || (DAT_0203a4aa & 3) == 0) {
      if ((DAT_0203a4aa & 3) == 0) {
        (&DAT_0203a4b8)[uVar2 * 4] = DAT_0203a466;
        DAT_0203a4aa = DAT_0203a4aa + 1;
        DAT_0203a4ac = 1;
        return;
      }
      return;
    }
    if (uVar1 == 2) {
      (&DAT_0203a4b8)[(uVar2 + 2) * 4] = DAT_0203a466;
      DAT_0203a4aa = DAT_0203a4aa + 3;
      DAT_0203a4ac = 1;
      return;
    }
  }
  if ((uVar2 & 3) == 3) {
    (&DAT_0203a4b8)[(uVar2 + 1) * 4] = DAT_0203a466;
    DAT_0203a4ac = 1;
    DAT_0203a4aa = DAT_0203a4aa + 2;
    return;
  }
  return;
}


// sub_0814AD74 @ 0x0814AD74

void sub_0814AD74(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    (&DAT_0203a4b4)[uVar1 * 8] = (&DAT_0203a4b4)[(uVar1 + 4) * 8];
    (&DAT_0203a4b8)[uVar1 * 4] = (&DAT_0203a4b8)[(uVar1 + 4) * 4];
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x3c);
  return;
}


// sub_0814ADAC @ 0x0814ADAC

void sub_0814ADAC(ushort *arg0,uint arg1,uint arg2,uint arg3)

{
  uint uVar1;
  uint arg3_00;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000004;
  
  arg3_00 = arg3 & 0xffff;
  for (; *arg0 != 0; arg0 = arg0 + 1) {
    uVar1 = arg3 & 0xffff;
    if (*arg0 != 0x300) {
      sub_080AC2A0((uint)*arg0,arg1 & 0xffff,arg2 & 0xffff,arg3_00);
      uVar1 = arg3_00 + (in_stack_00000004 & 0xffff) & 0xffff;
    }
    arg3_00 = uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x0814ae1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814AE1C @ 0x0814AE1C

void sub_0814AE1C(undefined4 arg0,undefined4 arg1)

{
  DAT_0203a454 = (undefined2)arg1;
  return;
}


// sub_0814AE28 @ 0x0814AE28

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814AE28(void)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_14;
  
  local_14 = 0;
  CpuSet(&local_14,0x203a454,0x5000200);
  REG_BG0CNT = 0x4008;
  DAT_03000002 = 0;
  DAT_03000040 = 0;
  DAT_0203a454 = 1;
  DAT_0203a490._0_2_ = 0x75;
  DAT_0203a48c._2_2_ = 0x50;
  _DAT_0203a488 = 400;
  if (DAT_0203b556 == 1) {
    DAT_0203a458._1_1_ = 1;
    DAT_0203a482._1_1_ = 4;
    DAT_0203a482._0_1_ = 7;
    DAT_0203a472 = 0x14;
    _DAT_0203a474 = 0x41;
  }
  else if (DAT_0203b556 < 2) {
    if (DAT_0203b556 == 0) {
      DAT_0203a458._1_1_ = 0;
      DAT_0203a482._1_1_ = 3;
      DAT_0203a482._0_1_ = 5;
      DAT_0203a472 = 0x14;
      _DAT_0203a474 = 0x32;
    }
  }
  else if ((DAT_0203b556 == 2) || (DAT_0203b556 == 3)) {
    DAT_0203a458._1_1_ = (undefined1)DAT_0203b556;
    DAT_0203a482._1_1_ = 5;
    DAT_0203a482._0_1_ = 8;
    DAT_0203a472 = 0x14;
    _DAT_0203a474 = 0x50;
  }
  uVar1 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      *(char *)(uVar1 * 0x14 + 0x203a5c0) = (char)uVar1;
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < (byte)DAT_0203a482);
  }
                    /* WARNING: Could not recover jumptable at 0x0814af12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814AF14 @ 0x0814AF14

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814AF14(void)

{
  dword arg0;
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (DAT_0203a454 == 1) {
    sub_080AD0FC(0x879f064,0xffff);
    DAT_0203a454 = 0;
  }
  if (DAT_0203a458._1_1_ == 1) {
    arg0 = 0x814fc2c;
LAB_0814af70:
    sub_080AA184(arg0,0,0,0);
  }
  else if (DAT_0203a458._1_1_ < 2) {
    if (DAT_0203a458._1_1_ == 0) {
      arg0 = 0x814fc1c;
      goto LAB_0814af70;
    }
  }
  else {
    if (DAT_0203a458._1_1_ == 2) {
      arg0 = 0x814fc3c;
      goto LAB_0814af70;
    }
    if (DAT_0203a458._1_1_ == 3) {
      sub_080AA184(0x814fc3c,0,0,0);
    }
  }
  if (DAT_0203a46c == '\x01') {
    sub_080AA184(0x814fe04,0,0,0);
  }
  sub_0814B838();
  sub_0814B894();
  sub_0814B8F4();
  if (DAT_0203a470 == '\x01') {
    sub_080AA184(0x814fbec,0,0,0);
  }
  if (DAT_0203a484 == '\x01') {
    sub_0814BE8C();
  }
  sub_0814C318();
  uVar1 = sub_080C32D4(0xfe);
  sub_0814C3FC(uVar1 & 0xff,0xd7,0x27,0);
  if ((DAT_0203a660 == '\x01') && ((char)DAT_0203a458 == '\0')) {
    if (((DAT_030031b8 & 0x100) == 0) || (uVar1 = sub_080C32D4(0xfe), (uVar1 & 0xff) == 0)) {
      if (((DAT_030031b8 & 0x100) != 0) && (uVar1 = sub_080C32D4(0xfe), (uVar1 & 0xff) == 0)) {
        DAT_0203a458._0_1_ = 'c';
      }
    }
    else {
      uVar1 = 0;
      do {
        (&DAT_0203a580)[uVar1 * 4] = 0;
        (&DAT_0203a581)[uVar1 * 4] = 0;
        uVar1 = uVar1 + 1 & 0xffff;
      } while (uVar1 < 8);
      uVar1 = 0;
      if (DAT_0203a482._1_1_ != 0) {
        do {
          (&DAT_0203a56e)[uVar1 * 4] = 0;
          (&DAT_0203a56c)[uVar1 * 4] = 10;
          uVar1 = uVar1 + 1 & 0xffff;
        } while (uVar1 < DAT_0203a482._1_1_);
      }
      uVar1 = 0;
      if ((byte)DAT_0203a482 != 0) {
        do {
          uVar3 = 0;
          if (DAT_0203a482._1_1_ != 0) {
            do {
              iVar2 = uVar3 * 4 + uVar1 * 0x14;
              (&DAT_0203a5c3)[iVar2] = 0;
              (&DAT_0203a5c1)[iVar2] = 0;
              uVar3 = uVar3 + 1 & 0xffff;
            } while (uVar3 < DAT_0203a482._1_1_);
          }
          uVar1 = uVar1 + 1 & 0xffff;
        } while (uVar1 < (byte)DAT_0203a482);
      }
      DAT_0203a498._0_1_ = 0;
      DAT_0203a490._3_1_ = 1;
      sub_080C33AC(0xfe);
      DAT_0203a458._0_1_ = '\x01';
      sub_080C51D4(0x15a);
    }
    if ((DAT_030031b8 & 0x200) != 0) {
      sub_080C51D4(0x158);
      DAT_0203a458._0_1_ = 'c';
    }
  }
  if ((char)DAT_0203a458 == '\x03') {
    if (((DAT_030031b8 & 0x40) != 0) && (DAT_0203a47c._2_1_ == '\0')) {
      DAT_0203a478._0_1_ = '\x01';
      DAT_0203a47c._2_1_ = '\x01';
    }
    if (((DAT_030031b8 & 0x80) != 0) && (DAT_0203a47c._2_1_ == '\0')) {
      DAT_0203a478._1_1_ = '\x01';
      DAT_0203a47c._2_1_ = '\x01';
    }
    if (((DAT_030031b8 & 0x10) != 0) && (DAT_0203a47c._2_1_ == '\0')) {
      if (*(short *)((uint)DAT_0203a46e * 4 + 0x879eb64) == _DAT_0203a474) {
        DAT_0203a46e = (DAT_0203a46e + 1) - (ushort)DAT_0203a482._1_1_;
      }
      else {
        DAT_0203a46e = DAT_0203a46e + 1;
      }
    }
    if (((DAT_030031b8 & 0x20) != 0) && (DAT_0203a47c._2_1_ == '\0')) {
      if (*(short *)((uint)DAT_0203a46e * 4 + 0x879eb64) == DAT_0203a472) {
        DAT_0203a46e = (DAT_0203a46e - 1) + (ushort)DAT_0203a482._1_1_;
      }
      else {
        DAT_0203a46e = DAT_0203a46e - 1;
      }
    }
    if (((DAT_030031b8 & 1) != 0) && (DAT_0203a47c._2_1_ == '\0')) {
      DAT_0203a458._0_1_ = '\x04';
    }
  }
  switch((char)DAT_0203a458) {
  case '\0':
    if ((0x14 < DAT_0203a45a) && (sub_080AA184(0x814fbc4,0,0,0), 0x28 < DAT_0203a45a)) {
      DAT_0203a45a = 0;
      DAT_0203a660 = '\x01';
    }
    goto LAB_0814b4f8;
  case '\x01':
    if (DAT_0203a470 == '\0') {
      DAT_0203a470 = '\x01';
    }
    sub_0814B7AC();
    sub_0814B524();
    if (DAT_0203a460._2_2_ < DAT_0203a482._1_1_) {
      sub_0814B6C4();
    }
    break;
  case '\x02':
    sub_0814C098();
    break;
  case '\x03':
    if ((char)DAT_0203a478 == '\x01') {
      sub_0814BB1C();
    }
    else if (DAT_0203a478._1_1_ == '\x01') {
      sub_0814BC0C();
    }
    break;
  case '\x04':
    sub_0814BCF4();
    break;
  case '\x05':
    sub_0814BF7C();
    break;
  case '\x06':
    sub_0814C130();
    break;
  case '\a':
    sub_0814C230();
    break;
  case '\b':
    sub_080C3328((uint)*(ushort *)
                        ((uint)DAT_0203a490._3_1_ * 4 + (uint)DAT_0203a458._1_1_ * 0x28 + 0x879eee4)
                );
    DAT_0203a458._0_1_ = '\0';
    break;
  case 'c':
    if (5 < _DAT_0203a45c) {
      sub_080BE4C4();
      break;
    }
    if (3 < DAT_0203a45a) {
      sub_080AA184(0x814fbdc,0,0,0);
    }
    if (6 < DAT_0203a45a) {
      DAT_0203a45a = 0;
      _DAT_0203a45c = _DAT_0203a45c + 1;
    }
LAB_0814b4f8:
    DAT_0203a45a = DAT_0203a45a + 1;
  }
  if (DAT_0203a458._1_1_ != 3) {
    sub_0814C47C();
  }
  return;
}


// sub_0814B524 @ 0x0814B524

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814B524(void)

{
  dword arg0;
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a45e < 3) {
    arg0 = 0x814fcec;
  }
  else if ((ushort)(DAT_0203a45e - 3) < 2) {
    arg0 = 0x814fd1c;
  }
  else if ((ushort)(DAT_0203a45e - 5) < 2) {
    arg0 = 0x814fd0c;
  }
  else {
    if (1 < (ushort)(DAT_0203a45e - 7)) {
      if (8 < DAT_0203a45e) {
        sub_080AA184(0x814fcec,0,0,0);
        sub_080C51D4(0x15b);
        if (0xc < DAT_0203a45e) {
          uVar1 = (uint)_DAT_0203a464;
          if ((int)(DAT_0203a482._1_1_ - 1) < (int)uVar1) {
            *(undefined1 *)
             (&DAT_0203a4cc + (byte)(&DAT_0879e5c8)[uVar1 * 8 + (uint)DAT_0203a458._1_1_ * 0x140]) =
                 0;
            *(undefined1 *)
             ((int)&DAT_0203a4cc +
             (uint)(byte)(&DAT_0879e5c8)[(uint)_DAT_0203a464 * 8 + (uint)DAT_0203a458._1_1_ * 0x140]
             * 4 + 2) = 0;
          }
          else {
            *(undefined1 *)
             (&DAT_0203a4cc + (byte)(&DAT_0879e5c8)[uVar1 * 8 + (uint)DAT_0203a458._1_1_ * 0x140]) =
                 0;
            *(undefined1 *)
             ((int)&DAT_0203a4cc +
             (uint)(byte)(&DAT_0879e5c8)[(uint)_DAT_0203a464 * 8 + (uint)DAT_0203a458._1_1_ * 0x140]
             * 4 + 2) = 1;
          }
          if ((&DAT_0879e5c9)[(uint)_DAT_0203a464 * 8 + (uint)DAT_0203a458._1_1_ * 0x140] == '\x01')
          {
            _DAT_0203a464 = 0;
            DAT_0203a460._2_2_ = 0;
            DAT_0203a458._0_1_ = 2;
          }
          else {
            _DAT_0203a464 = _DAT_0203a464 + 1;
          }
          DAT_0203a45e = 0;
        }
      }
      goto LAB_0814b6b6;
    }
    arg0 = 0x814fcfc;
  }
  sub_080AA184(arg0,0,0,0);
LAB_0814b6b6:
  DAT_0203a45e = DAT_0203a45e + 1;
                    /* WARNING: Could not recover jumptable at 0x0814b6c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814B6C4 @ 0x0814B6C4

void sub_0814B6C4(void)

{
  dword arg0;
  
  if ((ushort)DAT_0203a460 < 3) {
    arg0 = 0x814fcec;
  }
  else if ((ushort)((ushort)DAT_0203a460 - 3) < 2) {
    arg0 = 0x814fd1c;
  }
  else if ((ushort)((ushort)DAT_0203a460 - 5) < 2) {
    arg0 = 0x814fd0c;
  }
  else {
    if (1 < (ushort)((ushort)DAT_0203a460 - 7)) {
      if (8 < (ushort)DAT_0203a460) {
        sub_080AA184(0x814fcec,0,0,0);
        sub_080C51D4(0x15b);
        if (0xc < (ushort)DAT_0203a460) {
          (&DAT_0203a56c)[(uint)DAT_0203a460._2_2_ * 4] = 8;
          DAT_0203a460._2_2_ = DAT_0203a460._2_2_ + 1;
          DAT_0203a460._0_2_ = 0;
        }
      }
      goto LAB_0814b792;
    }
    arg0 = 0x814fcfc;
  }
  sub_080AA184(arg0,0,0,0);
LAB_0814b792:
  DAT_0203a460._0_2_ = (ushort)DAT_0203a460 + 1;
  return;
}


// sub_0814B7AC @ 0x0814B7AC

void sub_0814B7AC(void)

{
  dword arg0;
  
  if (DAT_0203a46a < 4) {
    arg0 = 0x814fe4c;
  }
  else if ((ushort)(DAT_0203a46a - 4) < 3) {
    arg0 = 0x814fe34;
  }
  else {
    if (2 < (ushort)(DAT_0203a46a - 7)) {
      if (9 < DAT_0203a46a) {
        sub_080AA184(0x814fe04,1,0,0);
        DAT_0203a46c = 1;
      }
      goto LAB_0814b824;
    }
    arg0 = 0x814fe1c;
  }
  sub_080AA184(arg0,1,0,0);
LAB_0814b824:
  DAT_0203a46a = DAT_0203a46a + 1;
  return;
}


// sub_0814B838 @ 0x0814B838

void sub_0814B838(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(char *)((int)&DAT_0203a4cc + uVar1 * 4 + 2) == '\x01') {
      sub_080AA184(*(undefined4 *)((uint)*(byte *)(&DAT_0203a4cc + uVar1) * 4 + 0x879e58c),0,0,1);
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x28);
  return;
}


// sub_0814B894 @ 0x0814B894

void sub_0814B894(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if ((&DAT_0203a56e)[uVar1 * 4] == '\x01') {
      sub_080AA184(*(undefined4 *)((uint)(byte)(&DAT_0203a56c)[uVar1 * 4] * 4 + 0x879e58c),0,0,1);
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 5);
  return;
}


// sub_0814B8F4 @ 0x0814B8F4

void sub_0814B8F4(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a458._1_1_ == 1) {
    sub_080AA184(0x814fcdc,0,0,0);
    sub_080AA184(0x814feec,0,0,0);
    sub_080AA184(0x814feec,0,0,0);
  }
  else {
    if (1 < DAT_0203a458._1_1_) {
      if ((DAT_0203a458._1_1_ != 2) && (DAT_0203a458._1_1_ == 3)) {
        sub_080AA184(0x814feec,0,0,0);
        sub_080AA184(0x814fec8,0,0,0);
        sub_080AA184(0x814fec8,0,0,0);
        sub_080AA184(0x814fec8,0,0,0);
        sub_080AA184(0x814fec8,0,0,0);
        sub_080AA184(0x814fec8,0,0,0);
        sub_080AA184(0x814fec8,0,0,0);
        sub_080AA184(0x814fec8,0,0,0);
        sub_080AA184(0x814fec8,0,0,0);
      }
      goto LAB_0814bb08;
    }
    if (DAT_0203a458._1_1_ != 0) goto LAB_0814bb08;
    sub_080AA184(0x814fcdc,0,0,0);
    sub_080AA184(0x814fcdc,0,0,0);
    sub_080AA184(0x814feec,0,0,0);
    sub_080AA184(0x814feec,0,0,0);
    sub_080AA184(0x814feec,0,0,0);
    sub_080AA184(0x814feec,0,0,0);
    sub_080AA184(0x814fec8,0,0,0);
    sub_080AA184(0x814fec8,0,0,0);
  }
  sub_080AA184(0x814fec8,0,0,0);
LAB_0814bb08:
                    /* WARNING: Could not recover jumptable at 0x0814bb12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814BB1C @ 0x0814BB1C

void sub_0814BB1C(void)

{
  byte bVar1;
  dword arg0;
  
  if (DAT_0203a478._2_2_ < 5) {
    arg0 = 0x814fcfc;
  }
  else if ((ushort)(DAT_0203a478._2_2_ - 5) < 4) {
    arg0 = 0x814fd0c;
  }
  else if ((ushort)(DAT_0203a478._2_2_ - 9) < 4) {
    arg0 = 0x814fd1c;
  }
  else if ((ushort)(DAT_0203a478._2_2_ - 0xd) < 4) {
    arg0 = 0x814fd2c;
  }
  else if ((ushort)(DAT_0203a478._2_2_ - 0x11) < 4) {
    arg0 = 0x814fd3c;
  }
  else {
    if (3 < (ushort)(DAT_0203a478._2_2_ - 0x15)) {
      sub_080C51D4(0x15b);
      bVar1 = *(byte *)(&DAT_0203a4cc + DAT_0203a46e);
      if ((uint)bVar1 == (byte)DAT_0203a482 - 1) {
        bVar1 = 0;
      }
      else {
        bVar1 = bVar1 + 1;
      }
      *(byte *)(&DAT_0203a4cc + DAT_0203a46e) = bVar1;
      DAT_0203a478._2_2_ = 0;
      DAT_0203a478._0_1_ = 0;
      DAT_0203a47c._2_1_ = 0;
      goto LAB_0814bbfc;
    }
    arg0 = 0x814fd4c;
  }
  sub_080AA184(arg0,0,0,0);
LAB_0814bbfc:
  DAT_0203a478._2_2_ = DAT_0203a478._2_2_ + 1;
  return;
}


// sub_0814BC0C @ 0x0814BC0C

void sub_0814BC0C(void)

{
  char cVar1;
  dword arg0;
  
  if ((ushort)DAT_0203a47c < 5) {
    arg0 = 0x814fd4c;
  }
  else if ((ushort)((ushort)DAT_0203a47c - 5) < 4) {
    arg0 = 0x814fd3c;
  }
  else if ((ushort)((ushort)DAT_0203a47c - 9) < 4) {
    arg0 = 0x814fd2c;
  }
  else if ((ushort)((ushort)DAT_0203a47c - 0xd) < 4) {
    arg0 = 0x814fd1c;
  }
  else if ((ushort)((ushort)DAT_0203a47c - 0x11) < 4) {
    arg0 = 0x814fd0c;
  }
  else {
    if (3 < (ushort)((ushort)DAT_0203a47c - 0x15)) {
      sub_080C51D4(0x15b);
      cVar1 = *(char *)(&DAT_0203a4cc + DAT_0203a46e);
      if (cVar1 == '\0') {
        cVar1 = (char)DAT_0203a482;
      }
      *(char *)(&DAT_0203a4cc + DAT_0203a46e) = cVar1 + -1;
      DAT_0203a47c._0_2_ = 0;
      DAT_0203a478._1_1_ = 0;
      DAT_0203a47c._2_1_ = 0;
      goto LAB_0814bce0;
    }
    arg0 = 0x814fcfc;
  }
  sub_080AA184(arg0,0,0,0);
LAB_0814bce0:
  DAT_0203a47c._0_2_ = (ushort)DAT_0203a47c + 1;
  return;
}


// sub_0814BCF4 @ 0x0814BCF4

void sub_0814BCF4(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (DAT_0203a482._1_1_ != 0) {
    do {
      if (*(char *)(&DAT_0203a4cc + DAT_0203a47c._3_1_ + uVar5) == (&DAT_0203a56c)[uVar5 * 4]) {
        uVar2 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
        (&DAT_0203a580)[(uVar2 & 0xff) * 4] = (&DAT_0203a580)[(uVar2 & 0xff) * 4] + '\x01';
      }
      else {
        uVar2 = 0;
        if (DAT_0203a482._1_1_ != 0) {
          do {
            if ((uVar5 != uVar2) &&
               (*(char *)(&DAT_0203a4cc + DAT_0203a47c._3_1_ + uVar5) == (&DAT_0203a56c)[uVar2 * 4])
               ) {
              uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
              (&DAT_0203a581)[(uVar3 & 0xff) * 4] = (&DAT_0203a581)[(uVar3 & 0xff) * 4] + '\x01';
            }
            uVar2 = uVar2 + 1 & 0xffff;
          } while (uVar2 < DAT_0203a482._1_1_);
        }
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < DAT_0203a482._1_1_);
  }
  uVar5 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  DAT_0203a494._2_1_ = (&DAT_0203a580)[(uVar5 & 0xff) * 4];
  uVar5 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  DAT_0203a494._3_1_ = (&DAT_0203a581)[(uVar5 & 0xff) * 4];
  sub_0814D150();
  bVar1 = DAT_0203a47c._3_1_;
  DAT_0203a484 = 1;
  uVar2 = (uint)DAT_0203a47c._3_1_;
  uVar5 = __udivsi3(uVar2,5);
  if ((&DAT_0203a580)[(uVar5 & 0xff) * 4] == DAT_0203a482._1_1_) {
    DAT_0203a46e = 0;
    DAT_0203a47c._3_1_ = '\0';
    DAT_0203a470 = 0;
    DAT_0203a490._2_1_ = 1;
    DAT_0203a458._0_1_ = 6;
  }
  else if (uVar2 == 0x23) {
    DAT_0203a46e = 0;
    DAT_0203a47c._3_1_ = '\0';
    DAT_0203a470 = 0;
    DAT_0203a46c = 0;
    DAT_0203a490._2_1_ = 0;
    DAT_0203a458._0_1_ = 6;
  }
  else {
    DAT_0203a47c._3_1_ = bVar1 + 5;
    uVar4 = sub_0814C52C((uint)DAT_0203a46e);
    DAT_0203a46e = (short)uVar4 + DAT_0203a46e;
    DAT_0203a490._3_1_ = DAT_0203a490._3_1_ + '\x01';
    DAT_0203a458._0_1_ = 5;
  }
  return;
}


// sub_0814BE8C @ 0x0814BE8C

void sub_0814BE8C(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = 0;
    iVar2 = uVar3 * 4;
    if ((&DAT_0203a580)[iVar2] != '\0') {
      do {
        sub_080AA184(0x814fbfc,0,0,0);
        DAT_0203a486 = DAT_0203a486 + 7;
        uVar1 = uVar1 + 1;
      } while (uVar1 < (byte)(&DAT_0203a580)[iVar2]);
    }
    uVar1 = 0;
    if ((&DAT_0203a581)[iVar2] != '\0') {
      do {
        sub_080AA184(0x814fc0c,0,0,0);
        DAT_0203a486 = DAT_0203a486 + 7;
        uVar1 = uVar1 + 1;
      } while (uVar1 < (byte)(&DAT_0203a581)[iVar2]);
    }
    DAT_0203a486 = 0;
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 8);
  return;
}


// sub_0814BF7C @ 0x0814BF7C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814BF7C(void)

{
  dword arg0;
  
  if (DAT_0203a45e < 3) {
    arg0 = 0x814fcec;
  }
  else if ((ushort)(DAT_0203a45e - 3) < 2) {
    arg0 = 0x814fd1c;
  }
  else if ((ushort)(DAT_0203a45e - 5) < 2) {
    arg0 = 0x814fd0c;
  }
  else {
    if (1 < (ushort)(DAT_0203a45e - 7)) {
      if (8 < DAT_0203a45e) {
        sub_080AA184(0x814fcec,0,0,0);
        sub_080C51D4(0x15b);
        if (0xc < DAT_0203a45e) {
          *(undefined1 *)(&DAT_0203a4cc + (uint)_DAT_0203a464 + (uint)DAT_0203a46e) = 0;
          *(undefined1 *)((int)&DAT_0203a4cc + ((uint)_DAT_0203a464 + (uint)DAT_0203a46e) * 4 + 2) =
               1;
          if ((uint)_DAT_0203a464 == DAT_0203a482._1_1_ - 1) {
            _DAT_0203a464 = 0;
            DAT_0203a458._0_1_ = 3;
          }
          else {
            _DAT_0203a464 = _DAT_0203a464 + 1;
            DAT_0203a45e = 0;
          }
        }
      }
      goto LAB_0814c08a;
    }
    arg0 = 0x814fcfc;
  }
  sub_080AA184(arg0,0,0,0);
LAB_0814c08a:
  DAT_0203a45e = DAT_0203a45e + 1;
  return;
}


// sub_0814C098 @ 0x0814C098

void sub_0814C098(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  while ((char)DAT_0203a458 != '\x03') {
    DAT_0203a468 = '\0';
    uVar1 = sub_080C2244();
    iVar2 = (uint)((ushort)uVar1 & 0xff) * (uint)(byte)DAT_0203a482;
    DAT_0203a476 = (undefined2)((uint)iVar2 >> 8);
    uVar3 = 0;
    if (DAT_0203a482._1_1_ != 0) {
      do {
        if ((uint)(byte)(&DAT_0203a56c)[uVar3 * 4] == iVar2 >> 8) {
          DAT_0203a468 = '\x01';
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < DAT_0203a482._1_1_);
    }
    if (DAT_0203a468 == '\0') {
      (&DAT_0203a56c)[(uint)DAT_0203a466 * 4] = (char)((uint)iVar2 >> 8);
      DAT_0203a466 = DAT_0203a466 + 1;
    }
    if (DAT_0203a466 == DAT_0203a482._1_1_) {
      DAT_0203a466 = 0;
      DAT_0203a458._0_1_ = '\x03';
    }
  }
  DAT_0203a458._0_1_ = 3;
  return;
}


// sub_0814C130 @ 0x0814C130

void sub_0814C130(void)

{
  dword arg0;
  
  if ((ushort)DAT_0203a460 < 3) {
    arg0 = 0x814fcec;
  }
  else if ((ushort)((ushort)DAT_0203a460 - 3) < 2) {
    arg0 = 0x814fd1c;
  }
  else if ((ushort)((ushort)DAT_0203a460 - 5) < 2) {
    arg0 = 0x814fd0c;
  }
  else {
    if (1 < (ushort)((ushort)DAT_0203a460 - 7)) {
      if (8 < (ushort)DAT_0203a460) {
        sub_080AA184(0x814fcec,0,0,0);
        sub_080C51D4(0x15b);
        if (0xc < (ushort)DAT_0203a460) {
          (&DAT_0203a56e)[(uint)DAT_0203a460._2_2_ * 4] = 1;
          if ((uint)DAT_0203a460._2_2_ == DAT_0203a482._1_1_ - 1) {
            DAT_0203a460._2_2_ = 0;
            DAT_0203a460._0_2_ = 0;
            DAT_0203a458._0_1_ = 7;
          }
          else {
            DAT_0203a460._2_2_ = DAT_0203a460._2_2_ + 1;
            DAT_0203a460._0_2_ = 0;
          }
        }
      }
      goto LAB_0814c222;
    }
    arg0 = 0x814fcfc;
  }
  sub_080AA184(arg0,0,0,0);
LAB_0814c222:
  DAT_0203a460._0_2_ = (ushort)DAT_0203a460 + 1;
  return;
}


// sub_0814C230 @ 0x0814C230

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814C230(void)

{
  ushort uVar1;
  
  if ((DAT_0203a48a == 0) && (_DAT_0203a488 < 0xd3)) {
    if (DAT_0203a490._2_1_ == '\0') {
      sub_080C51D4(0x163);
    }
    else {
      sub_080C51D4(0x15e);
    }
    DAT_0203a48c._0_1_ = '\x01';
  }
  if (((char)DAT_0203a48c == '\x01') && (DAT_0203a48a = DAT_0203a48a + 1, DAT_0203a48a == 0x1e)) {
    DAT_0203a48c._0_1_ = '\0';
  }
  if (DAT_0203a490._2_1_ == '\0') {
    sub_080AA184(0x814fc7c,0,0,0);
  }
  else {
    sub_080AA184(0x814fc54,0,0,0);
  }
  uVar1 = _DAT_0203a488;
  if (_DAT_0203a488 == 0) {
    _DAT_0203a488 = 400;
    DAT_0203a48a = uVar1;
    if (DAT_0203a490._2_1_ == '\x01') {
      DAT_0203a46c = 0;
      DAT_0203a458._0_1_ = 8;
    }
    else {
      DAT_0203a46c = 0;
      DAT_0203a458._0_1_ = 0;
    }
  }
  if ((char)DAT_0203a48c == '\0') {
    _DAT_0203a488 = _DAT_0203a488 - 4;
  }
  return;
}


// sub_0814C318 @ 0x0814C318

void sub_0814C318(void)

{
  uint uVar1;
  int arg0;
  int arg3;
  
  Font_ResetGlyphSpriteCache(0x380);
  uVar1 = sub_080C32FC((uint)*(ushort *)
                              ((uint)DAT_0203a490._3_1_ * 4 + (uint)DAT_0203a458._1_1_ * 0x28 +
                              0x879eee4));
  if ((uVar1 & 0xff) == 0) {
    if (1 < (byte)(DAT_0203a490._3_1_ - 1)) {
      sub_0814ADAC((uint)DAT_0203a458._1_1_ * 0xb4 + (uint)DAT_0203a490._3_1_ * 0x12 + 0x879ec14,0,0
                   ,*(ushort *)
                     (&DAT_0879eee6 + (uint)DAT_0203a490._3_1_ * 4 + (uint)DAT_0203a458._1_1_ * 0x28
                     ) + 100);
      return;
    }
    arg0 = (uint)DAT_0203a458._1_1_ * 0xb4 + (uint)DAT_0203a490._3_1_ * 0x12 + 0x879ec14;
    arg3 = *(ushort *)
            (&DAT_0879eee6 + (uint)DAT_0203a490._3_1_ * 4 + (uint)DAT_0203a458._1_1_ * 0x28) + 100;
  }
  else {
    arg0 = (uint)DAT_0203a458._1_1_ * 0xb4 + 0x879ecb6;
    arg3 = *(ushort *)(&DAT_0879ef0a + (uint)DAT_0203a458._1_1_ * 0x28) + 99;
  }
  sub_0814ADAC(arg0,0,0,arg3);
  return;
}


// sub_0814C3FC @ 0x0814C3FC

void sub_0814C3FC(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)sub_080A9CC0(arg0);
  sub_080AA184(*(undefined4 *)((uint)*pbVar1 * 4 + 0x879ef84),0,0,arg3 & 0xffff);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[1] * 4 + 0x879ef84),0,0,arg3 & 0xffff);
  return;
}


// sub_0814C47C @ 0x0814C47C

void sub_0814C47C(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      uVar2 = 0;
      if (DAT_0203a482._1_1_ != 0) {
        do {
          if ((&DAT_0203a5c1)[uVar2 * 4 + uVar1 * 0x14] != '\0') {
            sub_080AA184(*(undefined4 *)
                          ((uint)(byte)((&DAT_0203a5c1)[uVar2 * 4 + uVar1 * 0x14] + 1) * 4 +
                          0x879efac),1,0,0);
          }
          uVar2 = uVar2 + 1 & 0xffff;
        } while (uVar2 < DAT_0203a482._1_1_);
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < (byte)DAT_0203a482);
  }
  return;
}


// sub_0814C52C @ 0x0814C52C

undefined4 sub_0814C52C(uint arg0)

{
  uint uVar1;
  undefined4 unaff_r4;
  
  uVar1 = __umodsi3(arg0 & 0xffff,5);
  switch(uVar1 & 0xffff) {
  case 0:
    unaff_r4 = 5;
    break;
  case 1:
    unaff_r4 = 4;
    break;
  case 2:
    unaff_r4 = 3;
    break;
  case 3:
    unaff_r4 = 2;
    break;
  case 4:
    unaff_r4 = 1;
  }
  return unaff_r4;
}


// sub_0814C580 @ 0x0814C580

void sub_0814C580(void)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = 0;
  if (DAT_0203a482._1_1_ != 0) {
    do {
      uVar4 = uVar4 | *(byte *)(*(byte *)(&DAT_0203a4cc + DAT_0203a47c._3_1_ + uVar3) + 0x879f05c);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < DAT_0203a482._1_1_);
  }
  uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  *(char *)((int)&DAT_0203a4ac + (uVar3 & 0xff)) = (char)uVar4;
  cVar1 = '\0';
  bVar2 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      if ((uVar4 & 1) == 0) {
        uVar4 = uVar4 >> 1;
      }
      else {
        uVar4 = uVar4 >> 1 | 0x80;
        cVar1 = cVar1 + '\x01';
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < (byte)DAT_0203a482);
  }
  uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  *(char *)((int)&DAT_0203a4a4 + (uVar3 & 0xff)) = cVar1;
  return;
}


// sub_0814C624 @ 0x0814C624

void sub_0814C624(uint arg0,undefined4 arg1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = arg0 & 0xff;
  uVar4 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      if ((uVar3 & 1) == 0) {
        uVar3 = uVar3 >> 1;
      }
      else {
        uVar3 = uVar3 >> 1 | 0x80;
        uVar2 = 0;
        if (DAT_0203a482._1_1_ != 0) {
          do {
            cVar1 = (&DAT_0203a5c1)[uVar2 * 4 + uVar4 * 0x14];
            if ((cVar1 != -1) && (cVar1 != '\x02')) {
              (&DAT_0203a5c1)[uVar2 * 4 + uVar4 * 0x14] = (char)arg1;
            }
            uVar2 = uVar2 + 1 & 0xffff;
          } while (uVar2 < DAT_0203a482._1_1_);
        }
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < (byte)DAT_0203a482);
  }
  return;
}


// sub_0814C6C4 @ 0x0814C6C4

void sub_0814C6C4(uint arg0)

{
  uint uVar1;
  
  uVar1 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  sub_0814C624((uint)*(byte *)((int)&DAT_0203a4ac + (uVar1 & 0xff)),arg0 & 0xff);
  return;
}


// sub_0814C6F4 @ 0x0814C6F4

void sub_0814C6F4(undefined4 arg0)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  uVar2 = (uint)*(byte *)((int)&DAT_0203a4ac + (uVar2 & 0xff));
  uVar4 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      if ((uVar2 & 1) == 0) {
        uVar2 = uVar2 >> 1;
        uVar3 = 0;
        if (DAT_0203a482._1_1_ != 0) {
          do {
            cVar1 = (&DAT_0203a5c1)[uVar3 * 4 + uVar4 * 0x14];
            if ((cVar1 != -1) && (cVar1 != '\x02')) {
              (&DAT_0203a5c1)[uVar3 * 4 + uVar4 * 0x14] = (char)arg0;
            }
            uVar3 = uVar3 + 1 & 0xffff;
          } while (uVar3 < DAT_0203a482._1_1_);
        }
      }
      else {
        uVar2 = uVar2 >> 1 | 0x80;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < (byte)DAT_0203a482);
  }
  return;
}


// sub_0814C7A8 @ 0x0814C7A8

void sub_0814C7A8(undefined4 arg0)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  uVar2 = (uint)*(byte *)((int)&DAT_0203a4ac + (uVar2 & 0xff));
  for (uVar4 = 0; uVar4 < (byte)DAT_0203a482; uVar4 = uVar4 + 1 & 0xffff) {
    if ((uVar2 & 1) == 0) {
      uVar2 = uVar2 >> 1;
    }
    else {
      uVar2 = uVar2 >> 1 | 0x80;
      uVar3 = 0;
      if (DAT_0203a482._1_1_ != 0) {
        do {
          cVar1 = (&DAT_0203a5c1)[uVar3 * 4 + uVar4 * 0x14];
          if (((*(byte *)(&DAT_0203a4cc + DAT_0203a47c._3_1_ + uVar3) == uVar4) && (cVar1 != -1)) &&
             (cVar1 != '\x02')) {
            (&DAT_0203a5c1)[uVar3 * 4 + uVar4 * 0x14] = (char)arg0;
          }
          uVar3 = uVar3 + 1 & 0xffff;
        } while (uVar3 < DAT_0203a482._1_1_);
      }
    }
  }
  return;
}


// sub_0814C878 @ 0x0814C878

void sub_0814C878(undefined4 arg0)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  uVar2 = (uint)*(byte *)((int)&DAT_0203a4ac + (uVar2 & 0xff));
  for (uVar4 = 0; uVar4 < (byte)DAT_0203a482; uVar4 = uVar4 + 1 & 0xffff) {
    if ((uVar2 & 1) == 0) {
      uVar2 = uVar2 >> 1;
    }
    else {
      uVar2 = uVar2 >> 1 | 0x80;
      uVar3 = 0;
      if (DAT_0203a482._1_1_ != 0) {
        do {
          cVar1 = (&DAT_0203a5c1)[uVar3 * 4 + uVar4 * 0x14];
          if (((*(byte *)(&DAT_0203a4cc + DAT_0203a47c._3_1_ + uVar3) != uVar4) && (cVar1 != -1)) &&
             (cVar1 != '\x02')) {
            (&DAT_0203a5c1)[uVar3 * 4 + uVar4 * 0x14] = (char)arg0;
          }
          uVar3 = uVar3 + 1 & 0xffff;
        } while (uVar3 < DAT_0203a482._1_1_);
      }
    }
  }
  return;
}


// sub_0814C948 @ 0x0814C948

void sub_0814C948(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  uVar3 = (uint)*(byte *)((int)&DAT_0203a4ac + (uVar2 & 0xff));
  DAT_0203a4b6._0_1_ = 0;
  uVar2 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      if ((uVar3 & 1) == 0) {
        uVar3 = uVar3 >> 1;
      }
      else {
        uVar3 = uVar3 >> 1 | 0x80;
        bVar1 = 0;
        uVar4 = 0;
        if (DAT_0203a482._1_1_ != 0) {
          do {
            if (uVar2 == *(byte *)(&DAT_0203a4cc + DAT_0203a47c._3_1_ + uVar4)) {
              bVar1 = bVar1 + 1;
            }
            uVar4 = uVar4 + 1 & 0xffff;
          } while (uVar4 < DAT_0203a482._1_1_);
        }
        if (1 < bVar1) {
          DAT_0203a4b6._0_1_ = (byte)DAT_0203a4b6 | *(byte *)(uVar2 + 0x879f05c);
        }
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < (byte)DAT_0203a482);
  }
  return;
}


// sub_0814CA18 @ 0x0814CA18

void sub_0814CA18(uint arg0)

{
  sub_0814C624((uint)(byte)DAT_0203a4b6,arg0 & 0xff);
  return;
}


// sub_0814CA34 @ 0x0814CA34

void sub_0814CA34(uint arg0,undefined4 arg1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = arg0 & 0xff;
  uVar4 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      if ((uVar3 & 1) == 0) {
        uVar3 = uVar3 >> 1;
      }
      else {
        uVar3 = uVar3 >> 1 | 0x80;
        uVar2 = 0;
        if (DAT_0203a482._1_1_ != 0) {
          do {
            cVar1 = (&DAT_0203a5c1)[uVar2 * 4 + uVar4 * 0x14];
            if ((cVar1 != -1) && (cVar1 != '\x02')) {
              (&DAT_0203a5c1)[uVar2 * 4 + uVar4 * 0x14] = (char)arg1;
            }
            uVar2 = uVar2 + 1 & 0xffff;
          } while (uVar2 < DAT_0203a482._1_1_);
        }
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < (byte)DAT_0203a482);
  }
  return;
}


// sub_0814CAD4 @ 0x0814CAD4

void sub_0814CAD4(void)

{
  uint uVar1;
  uint uVar2;
  
  DAT_0203a4ba._0_1_ = 0;
  DAT_0203a4b8._1_1_ = '\0';
  uVar2 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      uVar1 = 0;
      if ((DAT_0203a482._1_1_ != 0) && ((&DAT_0203a5c1)[uVar2 * 0x14] == -1)) {
        do {
          uVar1 = uVar1 + 1 & 0xffff;
          if (DAT_0203a482._1_1_ <= uVar1) break;
        } while ((&DAT_0203a5c1)[uVar1 * 4 + uVar2 * 0x14] == -1);
      }
      if (uVar1 == DAT_0203a482._1_1_) {
        DAT_0203a4ba._0_1_ = (byte)DAT_0203a4ba | *(byte *)(uVar2 + 0x879f05c);
        DAT_0203a4b8._1_1_ = DAT_0203a4b8._1_1_ + '\x01';
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < (byte)DAT_0203a482);
  }
  return;
}


// sub_0814CB90 @ 0x0814CB90

void sub_0814CB90(void)

{
  uint uVar1;
  uint uVar2;
  
  DAT_0203a4b8._0_1_ = 0;
  DAT_0203a4b6._1_1_ = '\0';
  uVar2 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      uVar1 = 0;
      if (DAT_0203a482._1_1_ != 0) {
        do {
          if ((byte)((&DAT_0203a5c1)[uVar1 * 4 + uVar2 * 0x14] - 1) < 2) {
            DAT_0203a4b8._0_1_ = (byte)DAT_0203a4b8 | *(byte *)(uVar2 + 0x879f05c);
            DAT_0203a4b6._1_1_ = DAT_0203a4b6._1_1_ + '\x01';
            break;
          }
          uVar1 = uVar1 + 1 & 0xffff;
        } while (uVar1 < DAT_0203a482._1_1_);
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < (byte)DAT_0203a482);
  }
  return;
}


// sub_0814CC38 @ 0x0814CC38

void sub_0814CC38(uint arg0)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  DAT_0203a4b6._1_1_ = '\0';
  DAT_0203a4b8._0_1_ = 0;
  bVar2 = 0;
  uVar4 = 0;
  if (DAT_0203a482._1_1_ != 0) {
    do {
      uVar3 = 0;
      if (DAT_0203a482._1_1_ != 0) {
        do {
          if ((byte)((&DAT_0203a5c1)
                     [uVar3 * 4 + (uint)*(byte *)(&DAT_0203a4cc + (arg0 & 0xff) + uVar4) * 0x14] - 1
                    ) < 2) {
            bVar1 = *(byte *)(*(byte *)(&DAT_0203a4cc + (arg0 & 0xff) + uVar4) + 0x879f05c);
            if ((bVar2 & bVar1) != 0) break;
            bVar2 = bVar2 | bVar1;
            DAT_0203a4b6._1_1_ = DAT_0203a4b6._1_1_ + '\x01';
            DAT_0203a4b8._0_1_ = (byte)DAT_0203a4b8 | *(byte *)(uVar4 + 0x879f05c);
          }
          uVar3 = uVar3 + 1 & 0xffff;
        } while (uVar3 < DAT_0203a482._1_1_);
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < DAT_0203a482._1_1_);
  }
  return;
}


// sub_0814CD10 @ 0x0814CD10

uint sub_0814CD10(uint arg0,uint arg1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = arg0 & 0xff;
  uVar1 = 0;
  uVar3 = 0;
  if (DAT_0203a482._1_1_ != 0) {
    do {
      if ((uVar2 & 1) == 0) {
        uVar2 = uVar2 >> 1;
      }
      else {
        uVar2 = uVar2 >> 1 | 0x80;
        uVar1 = uVar1 | *(byte *)(*(byte *)(&DAT_0203a4cc + (arg1 & 0xff) + uVar3) + 0x879f05c);
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < DAT_0203a482._1_1_);
  }
  return uVar1;
}


// sub_0814CD70 @ 0x0814CD70

void sub_0814CD70(uint arg0,uint arg1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  if (DAT_0203a482._1_1_ != 0) {
    do {
      *(undefined1 *)((int)&DAT_0203a4ba + uVar4 + 1) =
           *(undefined1 *)(&DAT_0203a4cc + (arg0 & 0xff) + uVar4);
      *(undefined1 *)((int)&DAT_0203a4c0 + uVar4) =
           *(undefined1 *)(&DAT_0203a4cc + (arg1 & 0xff) + uVar4);
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < DAT_0203a482._1_1_);
  }
  uVar4 = 0;
  bVar1 = 0;
  bVar3 = 0;
  cVar2 = '\0';
  if (DAT_0203a482._1_1_ != 0) {
    do {
      uVar5 = 0;
      if (DAT_0203a482._1_1_ != 0) {
        do {
          if (((*(byte *)(uVar5 + 0x879f05c) & bVar1) == 0) &&
             (*(char *)((int)&DAT_0203a4c0 + uVar4) == *(char *)((int)&DAT_0203a4ba + uVar5 + 1))) {
            bVar1 = bVar1 | *(byte *)(uVar5 + 0x879f05c);
            bVar3 = bVar3 | *(byte *)(uVar4 + 0x879f05c);
            cVar2 = cVar2 + '\x01';
            break;
          }
          uVar5 = uVar5 + 1 & 0xffff;
        } while (uVar5 < DAT_0203a482._1_1_);
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < DAT_0203a482._1_1_);
  }
  DAT_0203a4b5 = ~bVar1;
  DAT_0203a4c5 = ~bVar1;
  DAT_0203a4c6._0_1_ = ~bVar3;
  DAT_0203a4b4 = DAT_0203a482._1_1_ - cVar2;
  return;
}


// sub_0814CE90 @ 0x0814CE90

void sub_0814CE90(uint arg0,uint arg1)

{
  sub_0814C624(arg0 & 0xff,arg1 & 0xff);
  return;
}


// sub_0814CEA4 @ 0x0814CEA4

void sub_0814CEA4(uint arg0,uint arg1)

{
  sub_0814C624(arg0 & 0xff,arg1 & 0xff);
  return;
}


// sub_0814CEB8 @ 0x0814CEB8

void sub_0814CEB8(uint arg0,uint arg1)

{
  sub_0814C624(arg0 & 0xff,arg1 & 0xff);
  return;
}


// sub_0814CECC @ 0x0814CECC

void sub_0814CECC(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_28;
  
  uVar6 = 0;
  local_28 = 0;
  uVar3 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      cVar2 = '\0';
      uVar7 = 0;
      uVar5 = 0;
      if (DAT_0203a482._1_1_ != 0) {
        do {
          cVar1 = (&DAT_0203a5c1)[uVar5 * 4 + uVar3 * 0x14];
          if (cVar1 == -1) {
            uVar7 = uVar7 + 1 & 0xff;
          }
          else if (cVar1 == '\x01') {
            cVar2 = cVar2 + '\x01';
            uVar6 = uVar3 & 0xff;
            local_28 = uVar5 & 0xff;
          }
          else if (cVar1 == '\x02') {
            uVar4 = 0;
            if (DAT_0203a482._1_1_ != 0) {
              do {
                if ((&DAT_0203a5c1)[uVar4 * 4 + uVar3 * 0x14] != '\x02') {
                  (&DAT_0203a5c1)[uVar4 * 4 + uVar3 * 0x14] = -1;
                }
                uVar4 = uVar4 + 1 & 0xffff;
              } while (uVar4 < DAT_0203a482._1_1_);
            }
            break;
          }
          uVar5 = uVar5 + 1 & 0xffff;
        } while (uVar5 < DAT_0203a482._1_1_);
      }
      if (((uVar5 == DAT_0203a482._1_1_) && (uVar7 == DAT_0203a482._1_1_ - 1)) && (cVar2 == '\x01'))
      {
        (&DAT_0203a5c1)[(uVar6 * 5 + local_28) * 4] = 2;
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < (byte)DAT_0203a482);
  }
  return;
}


// sub_0814CFDC @ 0x0814CFDC

void sub_0814CFDC(uint arg0,undefined4 arg1)

{
  uint uVar1;
  
  DAT_0203a4c6._1_1_ = 0;
  DAT_0203a4c8._0_1_ = '\0';
  uVar1 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      if ((&DAT_0203a5c1)[(arg0 & 0xff) * 4 + uVar1 * 0x14] == (char)arg1) {
        DAT_0203a4c6._1_1_ = DAT_0203a4c6._1_1_ | *(byte *)(uVar1 + 0x879f05c);
        DAT_0203a4c8._0_1_ = (char)DAT_0203a4c8 + '\x01';
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < (byte)DAT_0203a482);
  }
  return;
}


// sub_0814D058 @ 0x0814D058

void sub_0814D058(uint arg0,uint arg1,undefined4 arg2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = arg0 & 0xff;
  uVar2 = 0;
  if ((byte)DAT_0203a482 != 0) {
    do {
      if ((uVar3 & 1) == 0) {
        uVar3 = uVar3 >> 1;
      }
      else {
        uVar3 = uVar3 >> 1 | 0x80;
        cVar1 = (&DAT_0203a5c1)[(arg1 & 0xff) * 4 + uVar2 * 0x14];
        if ((cVar1 != -1) && (cVar1 != '\x02')) {
          (&DAT_0203a5c1)[(arg1 & 0xff) * 4 + uVar2 * 0x14] = (char)arg2;
        }
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < (byte)DAT_0203a482);
  }
  return;
}


// sub_0814D0C4 @ 0x0814D0C4

void sub_0814D0C4(void)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < DAT_0203a482._1_1_; uVar1 = uVar1 + 1 & 0xff) {
    sub_0814CFDC(uVar1,0xff);
    if ((uint)(byte)DAT_0203a4c8 == (byte)DAT_0203a482 - 1) {
      sub_0814D058(~(uint)DAT_0203a4c6._1_1_ & 0xff,uVar1,2);
    }
  }
  for (uVar1 = 0; uVar1 < DAT_0203a482._1_1_; uVar1 = uVar1 + 1 & 0xff) {
    sub_0814CFDC(uVar1,2);
    if ((byte)DAT_0203a4c8 != 0) {
      sub_0814D058(~(uint)DAT_0203a4c6._1_1_ & 0xff,uVar1,0xff);
    }
  }
  return;
}


// sub_0814D150 @ 0x0814D150

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void sub_0814D150(void)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  
  uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  *(char *)((int)&DAT_0203a49c + (uVar3 & 0xff)) = DAT_0203a494._3_1_ + DAT_0203a494._2_1_;
  sub_0814C580();
  uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  uVar3 = uVar3 & 0xff;
  if (*(byte *)((int)&DAT_0203a4a4 + uVar3) == DAT_0203a482._1_1_) {
    bVar2 = *(byte *)((int)&DAT_0203a49c + uVar3);
    if (bVar2 == DAT_0203a482._1_1_) {
      sub_0814C6C4(1);
      sub_0814C6F4(0xff);
    }
    else if (DAT_0203a458._1_1_ == '\x02') {
      if (bVar2 == 2) goto LAB_0814d1d8;
    }
    else if (bVar2 == 1) {
LAB_0814d1d8:
      sub_0814C6F4(1);
    }
  }
  else {
    bVar2 = *(byte *)((int)&DAT_0203a49c + uVar3);
    if (bVar2 == DAT_0203a482._1_1_) {
      sub_0814C6C4(1);
    }
    else if (bVar2 == 0) {
      sub_0814C6C4(0xff);
    }
    else if ((DAT_0203a458._1_1_ == '\x02') &&
            ((uint)*(byte *)((int)&DAT_0203a4a4 + uVar3) -
             (uint)*(byte *)((int)&DAT_0203a49c + uVar3) == 3)) {
      sub_0814C6F4(1);
    }
    uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
    if (*(char *)((int)&DAT_0203a4a4 + (uVar3 & 0xff)) == DAT_0203a494._2_1_) {
      sub_0814C7A8(1);
      sub_0814C878(0xff);
    }
  }
  if (DAT_0203a494._3_1_ == '\0') {
    if (DAT_0203a494._2_1_ != '\0') {
      sub_0814C878(0xff);
      uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
      if (*(byte *)((int)&DAT_0203a4a4 + (uVar3 & 0xff)) != DAT_0203a482._1_1_) {
        sub_0814C948();
        sub_0814CA18(0xff);
      }
    }
    if (DAT_0203a494._3_1_ == '\0') goto LAB_0814d298;
  }
  if (DAT_0203a494._2_1_ == '\0') {
    sub_0814C7A8(0xff);
  }
LAB_0814d298:
  uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
  if ((uVar3 & 0xff) != 0) {
    DAT_0203a498._2_2_ =
         CONCAT11(DAT_0203a498._3_1_,*(undefined1 *)((int)&DAT_0203a49c + (uVar3 & 0xff)));
    if (DAT_0203a47c._3_1_ != 0) {
      _DAT_0203a480 = DAT_0203a47c._3_1_ - 5;
    }
    uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
    iVar4 = (uVar3 & 0xff) * 0x10000;
    while (iVar4 = iVar4 - 0x10000, -1 < iVar4) {
      sub_0814CC38((uint)DAT_0203a47c._3_1_);
      uVar7 = (uint)DAT_0203a47c._3_1_;
      uVar3 = __udivsi3(uVar7,5);
      if (DAT_0203a4b6._1_1_ == *(byte *)((int)&DAT_0203a49c + (uVar3 & 0xff))) {
        iVar5 = sub_0814CD10((uint)(byte)DAT_0203a4b8,uVar7);
        uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
        sub_0814CA34((iVar5 << 0x18 ^ 0xff000000U) >> 0x18 &
                     (uint)*(byte *)((int)&DAT_0203a4ac + (uVar3 & 0xff)),0xff);
      }
      sub_0814CC38(_DAT_0203a480 & 0xff);
      iVar5 = iVar4 >> 0x10;
      pbVar6 = (byte *)((int)&DAT_0203a49c + iVar5);
      if (DAT_0203a4b6._1_1_ == *pbVar6) {
        uVar3 = sub_0814CD10((uint)(byte)DAT_0203a4b8,_DAT_0203a480 & 0xff);
        sub_0814CA34((uint)*(byte *)((int)&DAT_0203a4ac + iVar5) & ~(uVar3 & 0xff),0xff);
      }
      DAT_0203a498._2_2_ = CONCAT11(*pbVar6,DAT_0203a498._2_1_);
      sub_0814CD70((uint)DAT_0203a47c._3_1_,_DAT_0203a480 & 0xff);
      if ((uint)DAT_0203a498._2_1_ - (uint)DAT_0203a498._3_1_ == (uint)DAT_0203a4b4) {
        uVar3 = sub_0814CD10((uint)DAT_0203a4c5,(uint)DAT_0203a47c._3_1_);
        sub_0814CE90(uVar3 & 0xff,1);
        uVar3 = sub_0814CD10((uint)(byte)DAT_0203a4c6,_DAT_0203a480 & 0xff);
        sub_0814CEA4(uVar3 & 0xff,0xff);
      }
      if ((uint)DAT_0203a498._3_1_ - (uint)DAT_0203a498._2_1_ == (uint)DAT_0203a4b4) {
        uVar3 = sub_0814CD10((uint)DAT_0203a4c5,(uint)DAT_0203a47c._3_1_);
        sub_0814CE90(uVar3 & 0xff,0xff);
        uVar3 = sub_0814CD10((uint)(byte)DAT_0203a4c6,_DAT_0203a480 & 0xff);
        sub_0814CEA4(uVar3 & 0xff,1);
      }
      uVar7 = (uint)DAT_0203a47c._3_1_;
      uVar3 = __udivsi3(uVar7,5);
      bVar2 = *(byte *)((int)&DAT_0203a4a4 + (uVar3 & 0xff));
      if (((bVar2 == DAT_0203a482._1_1_) && (*(byte *)((int)&DAT_0203a4a4 + iVar5) == bVar2)) &&
         (DAT_0203a458._1_1_ != '\0')) {
        if (DAT_0203a458._1_1_ == '\x01') {
          if ((DAT_0203a4b4 == 2) && (DAT_0203a498._2_2_ == 0x303)) {
            uVar3 = sub_0814CD10(~(uint)DAT_0203a4b5 & 0xff,uVar7);
            sub_0814CEB8(uVar3 & 0xff,1);
            uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
            sub_0814CA34(~(uint)(*(byte *)((int)&DAT_0203a4ac + (uVar3 & 0xff)) |
                                *(byte *)((int)&DAT_0203a4ac + iVar5)) & 0xff,0xff);
          }
          if (DAT_0203a4b4 == 3) {
            if (DAT_0203a498._2_2_ == 0x202) {
              uVar3 = sub_0814CD10(~(uint)DAT_0203a4b5 & 0xff,(uint)DAT_0203a47c._3_1_);
              sub_0814CEB8(uVar3 & 0xff,0xff);
            }
            if ((DAT_0203a4b4 == 3) && (DAT_0203a498._2_2_ == 0x203)) {
              uVar3 = sub_0814CD10(~(uint)DAT_0203a4b5 & 0xff,(uint)DAT_0203a47c._3_1_);
              sub_0814CEB8(uVar3 & 0xff,1);
            }
          }
        }
        else {
          if ((DAT_0203a4b4 == 3) &&
             (((cVar1 = *(char *)((int)&DAT_0203a49c + (uVar3 & 0xff)), cVar1 == '\x03' &&
               (*pbVar6 == 4)) || ((cVar1 == '\x04' && (*pbVar6 == 3)))))) {
            uVar3 = sub_0814CD10(~(uint)DAT_0203a4b5 & 0xff,(uint)DAT_0203a47c._3_1_);
            sub_0814CEB8(uVar3 & 0xff,1);
          }
          if ((DAT_0203a4b4 == 2) && (DAT_0203a498._2_2_ == 0x404)) {
            uVar3 = sub_0814CD10(~(uint)DAT_0203a4b5 & 0xff,(uint)DAT_0203a47c._3_1_);
            sub_0814CEB8(uVar3 & 0xff,1);
            uVar3 = __udivsi3((uint)DAT_0203a47c._3_1_,5);
            sub_0814CA34(~(uint)(*(byte *)((int)&DAT_0203a4ac + (uVar3 & 0xff)) |
                                *(byte *)((int)&DAT_0203a4ac + iVar5)) & 0xff,0xff);
          }
        }
      }
      _DAT_0203a480 = _DAT_0203a480 - 5;
    }
    sub_0814CB90();
    if (DAT_0203a4b6._1_1_ == DAT_0203a482._1_1_) {
      sub_0814CA34(~(uint)(byte)DAT_0203a4b8 & 0xff,0xff);
    }
    sub_0814CAD4();
    if ((uint)DAT_0203a4b8._1_1_ == (uint)(byte)DAT_0203a482 - (uint)DAT_0203a482._1_1_) {
      sub_0814CA34(~(uint)(byte)DAT_0203a4ba & 0xff,1);
    }
  }
  bVar2 = 0;
  do {
    sub_0814CECC();
    sub_0814D0C4();
    bVar2 = bVar2 + 1;
  } while (bVar2 < 3);
  return;
}


// sub_0814D688 @ 0x0814D688

void sub_0814D688(undefined4 arg0,undefined4 arg1)

{
  DAT_0203a454 = (undefined2)arg1;
  return;
}


// sub_0814D694 @ 0x0814D694

void sub_0814D694(uint arg0,undefined4 arg1,undefined4 arg2)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xffff;
  if (*(short *)(&DAT_0203a45c + uVar1 * 2) != 0) {
    sub_080AA184(*(undefined4 *)
                  ((uint)*(ushort *)(&DAT_0203a45c + uVar1 * 2) * 4 +
                  *(int *)(uVar1 * 4 + 0x879f334)),0,0,0);
  }
  return;
}


// sub_0814D70C @ 0x0814D70C

void sub_0814D70C(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  
  iVar1 = (arg0 & 0xffff) * 2;
  *(undefined2 *)(&DAT_0203a45c + iVar1) = (undefined2)arg1;
  if ((short)arg2 != 0) {
    *(short *)(&DAT_0203a484 + iVar1) = (short)arg2;
  }
  if ((short)arg3 != 0) {
    (&DAT_0203a4ac)[arg0 & 0xffff] = (short)arg3;
  }
  return;
}


// sub_0814D748 @ 0x0814D748

void sub_0814D748(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  
  iVar1 = (arg0 & 0xffff) * 2;
  *(undefined2 *)(&DAT_0203a45c + iVar1) = (undefined2)arg1;
  *(undefined2 *)(&DAT_0203a484 + iVar1) = (undefined2)arg2;
  (&DAT_0203a4ac)[arg0 & 0xffff] = (undefined2)arg3;
  return;
}


// sub_0814D774 @ 0x0814D774

void sub_0814D774(undefined4 arg0,uint arg1,uint arg2,uint arg3)

{
  uint in_stack_00000000;
  
  sub_0814D70C(arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff,in_stack_00000000 & 0xffff);
  return;
}


// sub_0814D798 @ 0x0814D798

void sub_0814D798(undefined4 arg0,uint arg1,uint arg2,uint arg3)

{
  uint in_stack_00000000;
  
  sub_0814D748(arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff,in_stack_00000000 & 0xffff);
  return;
}


// sub_0814D7BC @ 0x0814D7BC

void sub_0814D7BC(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined2 *puVar6;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uVar3 = 0;
  uStack_20 = 0;
  CpuSet(&uStack_20,0x203a454,0x5000200);
  uStack_1c = 0;
  REG_DMA3SAD = &uStack_1c;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85001000;
  uVar1 = REG_DMA3CNT;
  REG_BG0CNT = 0x4008;
  DAT_03000002 = 0;
  DAT_03000040 = 0;
  DAT_0203a454 = 1;
  sub_0814D70C(0,1,0,0);
  sub_0814D70C(1,0,0,0);
  sub_0814D70C(2,1,0,0);
  sub_0814D70C(3,1,0,0);
  sub_0814D70C(4,0,0,0);
  sub_0814D70C(5,0,0,0);
  sub_0814D70C(6,0,0,0);
  sub_0814D70C(7,0,0,0);
  sub_0814D70C(8,0,0,0);
  sub_0814D70C(9,0,0,0);
  sub_0814D70C(10,1,0,0);
  sub_0814D70C(0xb,0,0,0);
  sub_0814D70C(0xc,1,0,0);
  sub_0814D70C(0xd,1,0,0);
  sub_0814D70C(0xe,1,0,0);
  sub_0814D70C(0xf,0,0,0);
  sub_0814D70C(0x10,0,0,0);
  sub_0814D70C(0x11,0,0,0);
  puVar6 = (undefined2 *)&DAT_0203a4d4;
  do {
    *puVar6 = 0xffff;
    puVar6[0xc] = 0xffff;
    puVar6 = puVar6 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0xc);
  uVar4 = 0;
  uVar3 = 4;
  puVar5 = &DAT_030048c0;
  do {
    iVar2 = sub_080C09B0(uVar3);
    if (iVar2 != 0) {
      *(undefined2 *)(&DAT_0203a4d4 + uVar4 * 2) = *(undefined2 *)(puVar5 + 0x12);
      uVar4 = uVar4 + 1 & 0xffff;
    }
    puVar5 = puVar5 + 0x80;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x10);
  DAT_0203a456 = (short)uVar4;
  return;
}


// sub_0814D958 @ 0x0814D958

void sub_0814D958(void)

{
  if (DAT_0203a454 == 1) {
    sub_080AD0FC(0x879f3c4,0xffff);
  }
  else {
    if ((DAT_0203a454 < 2) || (DAT_0203a454 != 2)) goto LAB_0814d98c;
    sub_080BE4C4();
  }
  DAT_0203a454 = 0;
LAB_0814d98c:
  sub_0814D694(2,0x10,5);
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_0814D70C(2,1,0,0);
  }
  else {
    sub_0814D70C(2,2,0,0);
  }
  sub_0814D694(0,7,4);
  sub_0814D694(3,0xbb,5);
  sub_0814D694(1,0xbb,4);
  sub_0814D694(4,0x4f,10);
  sub_0814D694(5,0x5e,10);
  sub_0814D694(6,0x6d,10);
  sub_0814D694(7,0x7c,10);
  sub_0814D694(8,0x8b,10);
  sub_0814D694(9,0x9a,10);
  sub_0814D694(10,0,0x20);
  sub_0814D694(0xb,0,0x25);
  sub_0814D694(0xe,0xcf,0x48);
  sub_0814D694(0xd,0xac,0x6c);
  sub_0814D694(0x11,0xf0,100);
  sub_0814D694(0xc,0xa6,0x50);
  sub_0814D694(0xf,0x5e,0x1c);
  sub_0814D694(0x10,0x5e,100);
  return;
}


// sub_0814DA70 @ 0x0814DA70

void sub_0814DA70(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  sub_080AA1F4(0x879f394,0,arg3 & 0xffff,0);
  return;
}


// sub_0814DAAC @ 0x0814DAAC

void sub_0814DAAC(byte *arg0,uint arg1,uint arg2,undefined4 arg3)

{
  uint arg0_00;
  ushort uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000000;
  
  uVar1 = 0;
  for (; ((uVar1 < (ushort)arg3 && (arg0_00 = (uint)*arg0, arg0_00 != 0xff)) && (arg0_00 != 0));
      arg0 = arg0 + 1) {
    sub_0814DA70(arg0_00,arg1 & 0xffff,arg2 & 0xffff,in_stack_00000000 & 0xffff);
    uVar1 = uVar1 + 1;
    arg1 = (arg1 & 0xffff) + 8;
  }
                    /* WARNING: Could not recover jumptable at 0x0814db02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814DB04 @ 0x0814DB04

void sub_0814DB04(undefined4 arg0,undefined4 arg1)

{
  DAT_0203a454 = (undefined2)arg1;
  return;
}


// sub_0814DB10 @ 0x0814DB10

void sub_0814DB10(int arg0)

{
  bool bVar1;
  
  bVar1 = (DAT_030031b8 & 0x100) != 0;
  if (bVar1) {
    sub_080C51D4(0x15a);
  }
  *(ushort *)(arg0 + 0x1c) = (ushort)bVar1;
  return;
}


// sub_0814DB3C @ 0x0814DB3C

void sub_0814DB3C(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if ((DAT_030031bc & 0xf) == 0) {
    if (DAT_0203a460._2_2_ == 1) {
      DAT_0203a460._2_2_ = 2;
    }
    else if (DAT_0203a460._2_2_ == 2) {
      DAT_0203a460._2_2_ = 1;
    }
    else if (DAT_0203a460._2_2_ == 3) {
      DAT_0203a460._2_2_ = 4;
    }
    else if (DAT_0203a460._2_2_ == 4) {
      DAT_0203a460._2_2_ = 3;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0814db7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814DB7C @ 0x0814DB7C

void sub_0814DB7C(void)

{
  int iVar1;
  uint arg0;
  uint uVar2;
  uint arg2;
  undefined1 auStack_24 [8];
  
  sub_0814DAAC(0x30046c0,8,0x1a,8);
  arg2 = 0x28;
  uVar2 = 0;
  do {
    arg0 = (uint)*(ushort *)(&DAT_0203a4d4 + uVar2 * 2);
    if (arg0 != 0xffff) {
      iVar1 = sub_080BF648(arg0);
      sub_080C0420(iVar1 + 0x22,auStack_24);
      iVar1 = sub_080C0198(arg0);
      iVar1 = sub_0814E844((uint)*(byte *)(iVar1 + 0xc));
      if (iVar1 == 1) {
        sub_0814DAAC(auStack_24,8,arg2,8);
      }
      else {
        sub_0814DAAC(auStack_24,8,arg2,8);
      }
    }
    arg2 = arg2 + 9 & 0xffff;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0xc);
  return;
}


// sub_0814DC20 @ 0x0814DC20

void sub_0814DC20(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = DAT_0203a456;
  uVar4 = (uint)DAT_0203a456;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    uVar1 = DAT_03003964 & 0x40;
    if ((DAT_03003964 & 0x40) == 0) {
      uVar2 = DAT_0203a51c;
      if (((DAT_03003964 & 0x80) != 0) &&
         (sub_080C51D4(100), uVar2 = uVar1, (uint)DAT_0203a51c != uVar4 - 1)) {
        uVar2 = DAT_0203a51c + 1;
      }
    }
    else {
      sub_080C51D4(100);
      if (DAT_0203a51c == 0) {
        uVar2 = uVar2 - 1;
      }
      else {
        uVar2 = DAT_0203a51c - 1;
      }
    }
  }
  else {
    iVar3 = sub_080C0198((uint)*(ushort *)(&DAT_0203a4d4 + (uint)DAT_0203a51c * 2));
    iVar3 = sub_0814E844((uint)*(byte *)(iVar3 + 0xc));
    if (iVar3 == 1) {
      sub_080C51D4(0x65);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      uVar2 = DAT_0203a51c;
    }
    else {
      sub_080C51D4(0x66);
      uVar2 = DAT_0203a51c;
    }
  }
  DAT_0203a51c = uVar2;
  sub_0814D70C(0xb,1,0,(uint)DAT_0203a51c * 9 + 0x25 & 0xffff);
                    /* WARNING: Could not recover jumptable at 0x0814dcf6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814DCF8 @ 0x0814DCF8

void sub_0814DCF8(void)

{
  sub_0814DAAC(0x879f39c,8,0x59,8);
  sub_0814DAAC(0x879f3a1,8,0x65,8);
  return;
}


// sub_0814DD2C @ 0x0814DD2C

void sub_0814DD2C(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    uVar1 = DAT_03003964 & 0x40;
    if ((DAT_03003964 & 0x40) == 0) {
      uVar2 = DAT_0203a520;
      if (((DAT_03003964 & 0x80) != 0) && (sub_080C51D4(100), uVar2 = uVar1, DAT_0203a520 != 1)) {
        uVar2 = DAT_0203a520 + 1;
      }
    }
    else {
      sub_080C51D4(100);
      if (DAT_0203a520 == 0) {
        DAT_0203a520 = 1;
        uVar2 = DAT_0203a520;
      }
      else {
        uVar2 = DAT_0203a520 - 1;
      }
    }
  }
  else {
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    uVar2 = DAT_0203a520;
  }
  DAT_0203a520 = uVar2;
  sub_0814D70C(0xb,1,0,(uint)DAT_0203a520 * 0xc0000 + 0x560000 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x0814ddc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814DDC8 @ 0x0814DDC8

void sub_0814DDC8(void)

{
  int iVar1;
  uint uVar2;
  uint arg2;
  undefined1 auStack_20 [8];
  
  if (DAT_0203db72 == 3) {
    sub_0814DAAC(0x30050c8,8,0x1a,8);
  }
  else {
    sub_0814DAAC((uint)DAT_0203db72 * 8 + 0x879f37c,8,0x1a,8);
  }
  arg2 = 0x28;
  uVar2 = 0;
  do {
    if (*(ushort *)(&DAT_0203a4ec + uVar2 * 2) != 0xffff) {
      iVar1 = sub_080BF648((uint)*(ushort *)(&DAT_0203a4ec + uVar2 * 2));
      sub_080C0420(iVar1 + 0x22,auStack_20);
      sub_0814DAAC(auStack_20,8,arg2,8);
      arg2 = arg2 + 9 & 0xffff;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0xc);
  return;
}


// sub_0814DE64 @ 0x0814DE64

void sub_0814DE64(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203a51c == DAT_0203a51e) {
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else {
    sub_080C51D4(100);
    DAT_0203a51e = DAT_0203a51e + 1;
  }
  sub_0814D70C(0xb,1,0,(uint)DAT_0203a51e * 9 + 0x25 & 0xffff);
  return;
}


// sub_0814DEBC @ 0x0814DEBC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814DEBC(undefined4 arg0,int arg1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    sub_0814D70C(0xc,1,0xa6,0x50);
  }
  else if (arg1 == 1) {
    _DAT_0203a4c4 = _DAT_0203a4c4 + 1;
  }
  else {
    _DAT_0203a4c4 = _DAT_0203a4c4 + -1;
  }
                    /* WARNING: Could not recover jumptable at 0x0814def2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814DEF4 @ 0x0814DEF4

void sub_0814DEF4(undefined4 arg0,int arg1)

{
  if (arg1 == 0) {
    sub_0814D70C(0x11,1,0xf0,100);
  }
  else {
    DAT_0203a4a4._2_2_ = DAT_0203a4a4._2_2_ + -2;
  }
  return;
}


// sub_0814DF20 @ 0x0814DF20

void sub_0814DF20(undefined4 arg0,int arg1,undefined4 arg2,undefined4 arg3)

{
  if (arg1 == 0) {
    sub_0814D748(10,1,0,0x20);
  }
  else {
    DAT_0203a498._0_2_ = (short)DAT_0203a498 + (short)arg2;
    DAT_0203a4c0 = DAT_0203a4c0 + (short)arg3;
  }
  return;
}


// sub_0814DF54 @ 0x0814DF54

void sub_0814DF54(void)

{
  int iVar1;
  undefined4 arg2;
  undefined4 arg2_00;
  undefined4 arg2_01;
  undefined4 arg2_02;
  undefined1 auStack_28 [8];
  
  if (DAT_0203a520 == 0) {
    arg2 = 0x38;
    arg2_01 = 0x4c;
    arg2_00 = 0x78;
    arg2_02 = 0x94;
  }
  else {
    arg2 = 0x78;
    arg2_01 = 0x94;
    arg2_00 = 0x38;
    arg2_02 = 0x4c;
  }
  sub_0814DAAC(0x30046c0,8,arg2,8);
  iVar1 = sub_080BF648((uint)*(ushort *)(&DAT_0203a4d4 + (uint)DAT_0203a51c * 2));
  sub_080C0420(iVar1 + 0x22,auStack_28);
  sub_0814DAAC(auStack_28,0x5c,arg2_01,8);
  if (DAT_0203db72 == 3) {
    sub_0814DAAC(&DAT_030050c8,8,arg2_00,8);
  }
  else {
    sub_0814DAAC((uint)DAT_0203db72 * 8 + 0x879f37c,8,arg2_00,8);
  }
  iVar1 = sub_080BF648((uint)*(ushort *)(&DAT_0203a4ec + (uint)DAT_0203a51e * 2));
  sub_080C0420(iVar1 + 0x22,auStack_28);
  sub_0814DAAC(auStack_28,0x5c,arg2_02,8);
  return;
}


// sub_0814E044 @ 0x0814E044

void sub_0814E044(void)

{
  uint uVar1;
  
  uVar1 = sub_080C2244();
  DAT_0203a458 = (short)((uVar1 & 7) * 3 >> 2);
  return;
}


// sub_0814E064 @ 0x0814E064

void sub_0814E064(int arg0,uint arg1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (DAT_0203a458 == arg1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if ((arg1 & 1) == 0) {
      sub_0814D70C(0xf,4,0,0);
      sub_080C51D4(0x18c);
    }
    else {
      sub_0814D70C(0x10,4,0,0);
      sub_080C51D4(0x18c);
    }
    if ((arg1 & 1) == (uint)DAT_0203a520) {
      *(undefined2 *)(arg0 + 0x1e) = 2;
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0814e0ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814E0CC @ 0x0814E0CC

void sub_0814E0CC(int arg0,int arg1)

{
  undefined4 arg1_00;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203a520 == 0) {
    if (((arg1 == 0) || (arg1 == 2)) || (arg1 == 4)) {
LAB_0814e100:
      if ((DAT_030031b8 & 0x100) == 0) {
        if ((DAT_030031bc >> 4 & 1) == 0) {
          arg1_00 = 3;
        }
        else {
          arg1_00 = 4;
        }
        sub_0814D70C(3,arg1_00,0,0);
      }
      else {
        *(undefined2 *)(arg0 + 0x1c) = 1;
      }
      goto LAB_0814e14e;
    }
  }
  else if (((arg1 != 0) && (arg1 != 2)) && (arg1 != 4)) goto LAB_0814e100;
  *(undefined2 *)(arg0 + 0x1c) = 1;
  sub_0814D70C(3,1,0,0);
LAB_0814e14e:
  if (*(short *)(arg0 + 0x1c) == 1) {
    sub_0814D70C(0xd,3,0,0);
    sub_0814D70C(3,3,0,0);
  }
                    /* WARNING: Could not recover jumptable at 0x0814e170. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814E174 @ 0x0814E174

void sub_0814E174(int arg0,int arg1)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (arg1 == 0) {
    DAT_0203a51e = 0;
  }
  else if (arg1 == 1) {
    if (DAT_0203a51e == DAT_0203a51c) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    else {
      DAT_0203a51e = DAT_0203a51e + 1;
    }
  }
  else {
    iVar1 = sub_080C0198((uint)*(ushort *)(&DAT_0203a4d4 + (uint)DAT_0203a51c * 2));
    sub_080C0290((uint)*(byte *)(iVar1 + 0xc),1);
    *(undefined2 *)(&DAT_0203a4d4 + (uint)DAT_0203a51c * 2) = 0xffff;
  }
  sub_0814D70C(0xb,1,0,(uint)DAT_0203a51e * 9 + 0x25 & 0xffff);
                    /* WARNING: Could not recover jumptable at 0x0814e1f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814E1FC @ 0x0814E1FC

void sub_0814E1FC(int arg0,int arg1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (arg1 == 0) {
    DAT_0203a51c = 0;
  }
  else if (arg1 == 1) {
    if (DAT_0203a51c == DAT_0203a456) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    else {
      DAT_0203a51c = DAT_0203a51c + 1;
    }
  }
  sub_0814D70C(0xb,1,0,(uint)DAT_0203a51c * 9 + 0x25 & 0xffff);
                    /* WARNING: Could not recover jumptable at 0x0814e24a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814E24C @ 0x0814E24C

void sub_0814E24C(int arg0)

{
  ushort uVar1;
  
  uVar1 = DAT_0203a456;
  if (DAT_0203a456 < DAT_03005183) {
    *(undefined2 *)(arg0 + 0x1c) = 0;
    DAT_0203a51c = uVar1;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_0814E284 @ 0x0814E284

void sub_0814E284(void)

{
  sub_0814DAAC(0x879f3a6,8,0x1a,8);
  sub_0814DAAC(0x879f3ae,8,0x22,8);
  sub_0814DAAC(0x879f3b6,8,0x59,8);
  sub_0814DAAC(0x879f3bc,8,0x65,8);
  return;
}


// sub_0814E2DC @ 0x0814E2DC

/* WARNING: Restarted to delay deadcode elimination for space: ram */

void sub_0814E2DC(int arg0,int arg1)

{
  ushort uVar1;
  ushort uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (arg1 == 0) {
    DAT_0203a520 = 0;
  }
  else {
    if ((DAT_030031b8 & 1) == 0) {
      uVar1 = DAT_03003964 & 0x40;
      if ((DAT_03003964 & 0x40) == 0) {
        uVar2 = DAT_0203a520;
        if (((DAT_03003964 & 0x80) != 0) && (sub_080C51D4(100), uVar2 = uVar1, DAT_0203a520 != 1)) {
          uVar2 = DAT_0203a520 + 1;
        }
      }
      else {
        sub_080C51D4(100);
        if (DAT_0203a520 == 0) {
          DAT_0203a520 = 1;
          uVar2 = DAT_0203a520;
        }
        else {
          uVar2 = DAT_0203a520 - 1;
        }
      }
    }
    else {
      sub_080C51D4(0x65);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      uVar1 = DAT_0203a520;
      *(ushort *)(arg0 + 0x1e) = DAT_0203a520;
      uVar2 = DAT_0203a520;
      if (uVar1 == 1) {
        DAT_0203a51c = 0;
      }
    }
    DAT_0203a520 = uVar2;
    sub_0814D70C(0xb,1,0,(uint)DAT_0203a520 * 0xc0000 + 0x560000 >> 0x10);
  }
                    /* WARNING: Could not recover jumptable at 0x0814e3a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0814E3A8 @ 0x0814E3A8

void sub_0814E3A8(void)

{
  int iVar1;
  uint uVar2;
  uint arg2;
  undefined1 auStack_20 [8];
  
  iVar1 = sub_080BF648((uint)*(ushort *)(&DAT_0203a4ec + (uint)DAT_0203a51e * 2));
  sub_080C0420(iVar1 + 0x22,auStack_20);
  sub_0814DAAC(auStack_20,8,0x1a,8);
  arg2 = 0x28;
  uVar2 = 0;
  do {
    if (*(ushort *)(&DAT_0203a4d4 + uVar2 * 2) != 0xffff) {
      iVar1 = sub_080BF648((uint)*(ushort *)(&DAT_0203a4d4 + uVar2 * 2));
      sub_080C0420(iVar1 + 0x22,auStack_20);
      sub_0814DAAC(auStack_20,8,arg2,8);
    }
    arg2 = arg2 + 9 & 0xffff;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0xc);
  return;
}


// sub_0814E438 @ 0x0814E438

void sub_0814E438(undefined4 arg0,int arg1)

{
  ushort uVar1;
  int iVar2;
  
  if (arg1 == 0) {
    iVar2 = sub_080C0198((uint)*(ushort *)(&DAT_0203a4d4 + (uint)DAT_0203a51c * 2));
    sub_080C0290((uint)*(byte *)(iVar2 + 0xc),1);
    *(undefined2 *)(&DAT_0203a4d4 + (uint)DAT_0203a51c * 2) = 0xffff;
  }
  else {
    uVar1 = *(ushort *)(&DAT_0203a4ec + (uint)DAT_0203a51e * 2);
    sub_080C062C((uint)uVar1);
    *(ushort *)(&DAT_0203a4d4 + (uint)DAT_0203a51c * 2) = uVar1;
    iVar2 = sub_080C3560((uint)uVar1);
    *(undefined2 *)(iVar2 + 0x18) = 0;
    *(undefined2 *)(iVar2 + 0x10) = 0x8000;
  }
  return;
}


// sub_0814E4AC @ 0x0814E4AC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814E4AC(int arg0)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    bVar1 = false;
    uVar3 = 0;
    uVar2 = uVar4 + 1;
    if (DAT_0203a456 == 0) {
LAB_0814e508:
      if (!bVar1) {
        *(undefined2 *)(&DAT_0203a4ec + arg0 * 2) = *(undefined2 *)(uVar4 * 2 + 0x87a075a);
      }
    }
    else if (*(short *)(uVar4 * 2 + 0x87a075a) != _DAT_0203a4d4) {
      do {
        uVar3 = uVar3 + 1;
        if (DAT_0203a456 <= uVar3) goto LAB_0814e508;
      } while (*(short *)(uVar4 * 2 + 0x87a075a) != *(short *)(&DAT_0203a4d4 + uVar3 * 2));
      bVar1 = true;
      goto LAB_0814e508;
    }
    uVar4 = uVar2;
    if (0xb < uVar2) {
      return;
    }
  } while( true );
}


// sub_0814E538 @ 0x0814E538

undefined4 sub_0814E538(uint arg0)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = (ushort *)0x87a0772;
  while ((*puVar2 != arg0 || (iVar1 = sub_080C2340((uint)puVar2[1]), iVar1 != 0))) {
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
    if (0x19 < iVar3) {
      return 0;
    }
  }
  return 1;
}


// sub_0814E568 @ 0x0814E568

void sub_0814E568(int arg0)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  uint local_34;
  
  local_34 = 0;
  if (DAT_0203a456 != 0) {
    do {
      iVar5 = arg0 * 2;
      if (local_34 == 0) {
        *(undefined2 *)((int)&DAT_0203a504 + iVar5) = 0;
      }
      if ((((uint)*(byte *)(*(ushort *)(&DAT_0203a4d4 + iVar5) + 0x87a045c) ==
            (uint)*(ushort *)(&DAT_0203a4d4 + local_34 * 2)) ||
          (uVar1 = sub_0814E538((uint)*(byte *)(*(ushort *)(&DAT_0203a4d4 + iVar5) + 0x87a045c)),
          (uVar1 & 0xff) == 1)) && (uVar1 = 0, DAT_0203a456 != 0)) {
        do {
          if (uVar1 == 0) {
            *(undefined2 *)((int)&DAT_0203a504 + iVar5) = 10;
          }
          if (((ushort)*(byte *)(*(ushort *)(&DAT_0203a4d4 + iVar5) + 0x87a055b) ==
               *(ushort *)(&DAT_0203a4d4 + uVar1 * 2)) && (uVar4 = 0, DAT_0203a456 != 0)) {
            puVar3 = (ushort *)&DAT_0203a4d4;
            do {
              if (uVar4 == 0) {
                *(undefined2 *)((int)&DAT_0203a504 + iVar5) = 0x14;
              }
              if (((uint)*(byte *)(*(ushort *)(&DAT_0203a4d4 + iVar5) + 0x87a065a) == (uint)*puVar3)
                 || (uVar2 = sub_0814E538((uint)*(byte *)(*(ushort *)(&DAT_0203a4d4 + iVar5) +
                                                         0x87a065a)), (uVar2 & 0xff) == 1))
              goto LAB_0814e6a0;
              puVar3 = puVar3 + 1;
              uVar4 = uVar4 + 1;
            } while (uVar4 < DAT_0203a456);
          }
          uVar4 = sub_0814E538((uint)*(byte *)(*(ushort *)(&DAT_0203a4d4 + iVar5) + 0x87a055b));
          if (((uVar4 & 0xff) == 1) && (uVar4 = 0, DAT_0203a456 != 0)) {
            puVar3 = (ushort *)&DAT_0203a4d4;
            do {
              if (uVar4 == 0) {
                *(undefined2 *)((int)&DAT_0203a504 + iVar5) = 0x1e;
              }
              uVar2 = (uint)*(byte *)(*(byte *)(*(ushort *)(&DAT_0203a4d4 + iVar5) + 0x87a065a) +
                                     0x87a045c);
              if ((uVar2 == *puVar3) || (uVar2 = sub_0814E538(uVar2), (uVar2 & 0xff) == 1))
              goto LAB_0814e6a0;
              puVar3 = puVar3 + 1;
              uVar4 = uVar4 + 1;
            } while (uVar4 < DAT_0203a456);
          }
          uVar1 = uVar1 + 1;
        } while (uVar1 < DAT_0203a456);
      }
      local_34 = local_34 + 1;
    } while (local_34 < DAT_0203a456);
  }
LAB_0814e6dc:
                    /* WARNING: Could not recover jumptable at 0x0814e6ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
LAB_0814e6a0:
  *(undefined2 *)((int)&DAT_0203a504 + iVar5) = 2;
  goto LAB_0814e6dc;
}


// sub_0814E6EC @ 0x0814E6EC

void sub_0814E6EC(uint arg0)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  if ((arg0 & 0xffff) != (uint)DAT_0203a51c) {
    iVar3 = (arg0 & 0xffff) * 2;
    *(undefined2 *)((int)&DAT_0203a504 + iVar3) = 0;
    if (((ushort)*(byte *)(*(ushort *)(&DAT_0203a4d4 + (uint)DAT_0203a51c * 2) + 0x87a045c) ==
         *(ushort *)(&DAT_0203a4d4 + iVar3)) &&
       (*(short *)((int)&DAT_0203a504 + (uint)DAT_0203a51c * 2) == 10)) {
      *(undefined2 *)((int)&DAT_0203a504 + iVar3) = 10;
    }
    uVar2 = sub_0814E538((uint)*(byte *)(*(ushort *)(&DAT_0203a4d4 + iVar3) + 0x87a045c));
    if ((uVar2 & 0xff) == 1) {
      if ((ushort)*(byte *)(*(ushort *)(&DAT_0203a4d4 + (uint)DAT_0203a51c * 2) + 0x87a045c) ==
          *(ushort *)(&DAT_0203a4d4 + iVar3)) {
        uVar1 = 0x14;
      }
      else {
        uVar1 = 10;
      }
      *(undefined2 *)((int)&DAT_0203a504 + iVar3) = uVar1;
    }
  }
  return;
}


// sub_0814E798 @ 0x0814E798

void sub_0814E798(void)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  byte *pbVar4;
  ushort *puVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_0814E568((uint)DAT_0203a51c);
  for (uVar6 = 0; uVar6 < DAT_0203a456; uVar6 = uVar6 + 1) {
    sub_0814E6EC(uVar6 & 0xffff);
  }
  uVar6 = 0;
  if (DAT_0203a456 != 0) {
    puVar5 = (ushort *)&DAT_0203a4d4;
    do {
      sVar1 = *(short *)((int)&DAT_0203a504 + uVar6 * 2);
      if (sVar1 == 2) {
        sub_0814E4AC(uVar6);
      }
      else {
        if (sVar1 == 1) {
          uVar2 = *puVar5;
        }
        else {
          if (sVar1 == 0) {
            uVar3 = (uint)*puVar5;
LAB_0814e82c:
            pbVar4 = (byte *)(uVar3 + 0x87a045c);
          }
          else {
            if (sVar1 == 10) {
              uVar2 = (ushort)*(byte *)(*puVar5 + 0x87a055b);
              goto LAB_0814e830;
            }
            if (sVar1 != 0x14) {
              if (sVar1 != 0x1e) goto LAB_0814e832;
              uVar3 = (uint)*(byte *)(*puVar5 + 0x87a065a);
              goto LAB_0814e82c;
            }
            pbVar4 = (byte *)(*puVar5 + 0x87a065a);
          }
          uVar2 = (ushort)*pbVar4;
        }
LAB_0814e830:
        puVar5[0xc] = uVar2;
      }
LAB_0814e832:
      puVar5 = puVar5 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < DAT_0203a456);
  }
                    /* WARNING: Could not recover jumptable at 0x0814e842. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


