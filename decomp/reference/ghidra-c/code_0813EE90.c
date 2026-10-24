/* Ghidra decompilation of asm/code_0813EE90.s (reference only; not compiled). */

// sub_0813EE90 @ 0x0813EE90

void sub_0813EE90(undefined4 arg0,undefined4 arg1)

{
  undefined4 uStack_14;
  
  uStack_14 = 0;
  CpuSet(&uStack_14,0x203b554,0x50000c0);
  DAT_0203b554 = (undefined2)arg0;
  DAT_0203b556 = (undefined2)arg1;
  sub_080A9AB4(0x813eed1);
  return;
}


// sub_0813EED0 @ 0x0813EED0

void sub_0813EED0(void)

{
  undefined4 uVar1;
  undefined4 local_c;
  
  sub_080C1450();
  REG_DMA3SAD = &local_c;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  local_c = 0;
  REG_DMA3SAD = &local_c;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85001000;
  uVar1 = REG_DMA3CNT;
  Font_ResetGlyphSpriteCache(0x180);
  _call_via_r0(*(undefined4 *)((uint)DAT_0203b554 * 4 + 0x879241c));
  sub_080A9AB4(0x813ef41);
  return;
}


// sub_0813EF40 @ 0x0813EF40

void sub_0813EF40(void)

{
  sub_080AD01C();
  _call_via_r0(*(undefined4 *)((uint)DAT_0203b554 * 4 + 0x879243c));
  return;
}


// sub_0813EF64 @ 0x0813EF64

void sub_0813EF64(undefined4 arg0,undefined4 arg1,int arg2)

{
  int arg2_00;
  
  arg2_00 = arg2;
  HuffUnComp(arg1,0x200afc8,arg2);
  LZ77UnCompWram(0x200afc8,arg2 * 0x1000 + 0x2001000,arg2_00);
  return;
}


// sub_0813EF90 @ 0x0813EF90

void sub_0813EF90(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6008000;
  REG_DMA3CNT = 0x84002000;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_0813EFB4 @ 0x0813EFB4

void sub_0813EFB4(void)

{
  DisplayList_Add(0x813ef91,1);
  return;
}


// sub_0813EFC8 @ 0x0813EFC8

void sub_0813EFC8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6010000;
  REG_DMA3CNT = 0x84002000;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_0813EFEC @ 0x0813EFEC

void sub_0813EFEC(void)

{
  DisplayList_Add(0x813efc9,1);
  return;
}


// sub_0813F000 @ 0x0813F000

void sub_0813F000(undefined4 arg0,undefined4 arg1)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(arg1,0x200afc8,in_r2);
  sub_080ACFCC(3,0x200afc8,0x30029b0,0x200);
  return;
}


// sub_0813F030 @ 0x0813F030

void sub_0813F030(undefined4 arg0,undefined4 arg1)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(arg1,0x200afc8,in_r2);
  sub_080ACFCC(3,0x200afc8,0x3002bb0,0x200);
  return;
}


// sub_0813F060 @ 0x0813F060

void sub_0813F060(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_0813F080 @ 0x0813F080

void sub_0813F080(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_0813F0A4 @ 0x0813F0A4

void sub_0813F0A4(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_0813F0C8 @ 0x0813F0C8

void sub_0813F0C8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_0813F0EC @ 0x0813F0EC

void sub_0813F0EC(undefined4 arg0,undefined4 arg1,int arg2)

{
  dword arg0_00;
  
  LZ77UnCompWram(arg1,0x2000000,arg2);
  if (arg2 == 1) {
    arg0_00 = 0x813f081;
  }
  else if (arg2 == 0) {
    arg0_00 = 0x813f061;
  }
  else {
    if (arg2 != 2) {
      if (arg2 != 3) {
        return;
      }
      DisplayList_Add(0x813f0c9,1);
      return;
    }
    arg0_00 = 0x813f0a5;
  }
  DisplayList_Add(arg0_00,1);
  return;
}


// sub_0813F144 @ 0x0813F144

void sub_0813F144(void)

{
  sub_080AAEDC(1);
  return;
}


// sub_0813F150 @ 0x0813F150

void sub_0813F150(void)

{
  sub_080AAF48(1);
  return;
}


// sub_0813F15C @ 0x0813F15C

void sub_0813F15C(void)

{
  undefined4 in_r0;
  
  sub_080AB1A8(in_r0);
  return;
}


// sub_0813F168 @ 0x0813F168

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0813F168(void)

{
  undefined4 uStack_14;
  
  uStack_14 = 0;
  CpuSet(&uStack_14,0x203a454,0x5000200);
  REG_BG0CNT = 0x4008;
  DAT_03000002 = 0;
  DAT_03000040 = 0;
  DAT_0203a454 = 1;
  DAT_0203a47c._0_2_ = 0x111;
  DAT_0203a490 = sub_080C31F0();
  _DAT_0203a4b2 = 0;
  DAT_0203a4a4._2_2_ = 0;
  DAT_0203a498._2_2_ = 0;
  _DAT_0203a4b4 = 1;
  _DAT_0203a4a8 = 1;
  DAT_0203a49c._0_2_ = 1;
  DAT_0203a4b6 = 2;
  DAT_0203a4aa = 2;
  DAT_0203a49c._2_2_ = 2;
  DAT_0203a4b8 = 3;
  DAT_0203a4ac = 3;
  DAT_0203a4a0._0_2_ = 3;
  DAT_0203a4ba = 4;
  DAT_0203a4ae = 4;
  DAT_0203a4a0._2_2_ = 4;
  DAT_0203a4bc = 5;
  _DAT_0203a4b0 = 5;
  DAT_0203a4a4._0_2_ = 5;
  _DAT_0203a510 = 0x44;
  DAT_0203a51c = 0x69;
  _DAT_0203a528 = 0x8e;
  return;
}


// sub_0813F22C @ 0x0813F22C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0813F22C(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a454 == 1) {
    sub_080AD0FC(0x8794e24,0xffff);
    DAT_0203a454 = 0;
  }
  if ((char)DAT_0203a52c == '\x01') {
    if ((((DAT_030031b8 & 0x100) != 0) && (DAT_0203a458 == 0)) && (DAT_0203a490 != 0)) {
      if ((DAT_0203a478._2_2_ == 1) || (DAT_0203a472 == 1)) {
        if (DAT_0203a478._2_2_ == 0) {
          if (_DAT_0203a474 == 1) {
            DAT_0203a458 = 6;
          }
          else {
            if (_DAT_0203a474 != 2) goto LAB_0813f2c2;
            DAT_0203a458 = DAT_0203a478._2_2_;
            _DAT_0203a474 = DAT_0203a478._2_2_;
            DAT_0203a472 = DAT_0203a478._2_2_;
            sub_08141F04();
            DAT_0203a490 = DAT_0203a490 + _DAT_0203a484;
            _DAT_0203a484 = 0;
          }
        }
        else {
LAB_0813f2c2:
          if ((DAT_0203a478._2_2_ == 1) && (_DAT_0203a474 == 2)) {
            DAT_0203a458 = 6;
            DAT_0203a490 = DAT_0203a490 + _DAT_0203a484;
            _DAT_0203a484 = 0;
          }
          else {
            sub_080C51D4(0x15a);
            DAT_0203a458 = 2;
            DAT_0203a472 = 0;
            _DAT_0203a474 = 0;
            _DAT_0203a484 = _DAT_0203a484 + -5;
          }
        }
      }
      else {
        DAT_0203a458 = 1;
        DAT_0203a490 = DAT_0203a490 + -1;
      }
    }
    if (((((DAT_030031b8 & 0x200) != 0) && (DAT_0203a458 == 0)) && (DAT_0203a478._2_2_ == 0)) &&
       (_DAT_0203a474 == 0)) {
      sub_080C51D4(0x158);
      DAT_0203a458 = 9;
    }
  }
  if (DAT_0203a458 == 1) {
    if (DAT_0203a46a < 4) {
      sub_080AA184(0x814ee00,0,0,0);
    }
    if ((ushort)(DAT_0203a46a - 4) < 3) {
      sub_080AA184(0x814ede8,0,0,0);
    }
    if ((ushort)(DAT_0203a46a - 7) < 3) {
      sub_080AA184(0x814edd0,0,0,0);
    }
    if (9 < DAT_0203a46a) {
      sub_080AA184(0x814edb8,0,0,0);
      sub_080C51D4(0x15a);
      DAT_0203a458 = 2;
      DAT_0203a46a = 0;
    }
    sub_081403C0();
    sub_08141FE0(_DAT_0203a484,0xe4,0x21,2);
    sub_08141FE0(DAT_0203a490,0xe4,0x4a,2);
FUN_0813fca2:
    DAT_0203a46a = DAT_0203a46a + 1;
    goto FUN_081400f6;
  }
  if (DAT_0203a458 == 6) {
    if (((ushort)DAT_0203a478 == 0) && (DAT_0203a476 < 0xf0)) {
      DAT_0203a478._0_2_ = 1;
    }
    else if (((ushort)DAT_0203a478 == 1) && (0xef < DAT_0203a476)) {
      DAT_0203a478._0_2_ = 2;
      DAT_0203a476 = 0xf0;
      if (DAT_0203a478._2_2_ == 0) {
        sub_0813F0EC(0,0x87a4fa8,0);
        uVar4 = 0;
        do {
          uVar2 = sub_080C2244();
          (&DAT_0203a4d8)[uVar4 * 2] = uVar2 & 0xff;
          uVar2 = __udivsi3((uVar2 & 0xff) << 3,0xff);
          (&DAT_0203a4d8)[uVar4 * 2] = uVar2;
          *(undefined2 *)(&DAT_0203a4dc + uVar4 * 8) = 0;
          uVar4 = uVar4 + 1 & 0xffff;
        } while (uVar4 < 6);
      }
      else {
        sub_0813F0EC(0,0x87a51ac,0);
      }
    }
    else if (((ushort)DAT_0203a478 == 2) && (DAT_0203a476 == 0)) {
      DAT_0203a478._0_2_ = DAT_0203a476;
      _DAT_0203a474 = DAT_0203a476;
      DAT_0203a472 = DAT_0203a476;
      DAT_0203a458 = DAT_0203a476;
      if (DAT_0203a478._2_2_ == 0) {
        DAT_0203a478._2_2_ = 1;
      }
      else {
        DAT_0203a478._2_2_ = DAT_0203a476;
        DAT_0203a498._0_2_ = DAT_0203a476;
      }
    }
    DAT_03000000 = -DAT_0203a476;
    sub_080C51D4(0x15f);
    sub_080AA184(0x814edb8,0,0,0);
    sub_081403C0();
    sub_08141FE0(_DAT_0203a484,0xe4,0x21,2);
    sub_08141FE0(DAT_0203a490,0xe4,0x4a,2);
    if (DAT_0203a472 == 1) {
      sub_08141B08();
    }
    if (_DAT_0203a474 == 1) {
      sub_080AA184(0x814ec40,0,0,0);
    }
    else if (_DAT_0203a474 == 2) {
      sub_080AA184(0x814ec58,0,0,0);
    }
    if (0x14 < DAT_0203a466) {
      sub_080AA184(0x814ec90,0,0,0);
      sub_080AA184(0x814ec80,0,0,0);
    }
    if (0x28 < DAT_0203a466) {
      DAT_0203a466 = 0;
    }
    if ((ushort)DAT_0203a478 == 1) {
      if (DAT_0203a478._2_2_ == 1) {
        sub_08140914();
        sub_08141D90();
      }
      DAT_0203a476 = DAT_0203a476 + 2;
    }
    else if ((ushort)DAT_0203a478 == 2) {
      if (DAT_0203a478._2_2_ == 0) {
        sub_08140914();
      }
      DAT_0203a476 = DAT_0203a476 - 2;
    }
  }
  else {
    if (DAT_0203a458 == 2) {
      sub_08140104();
      sub_080AA184(0x814edb8,0,0,0);
      sub_081403C0();
      sub_08141FE0(_DAT_0203a484,0xe4,0x21,2);
      sub_08141FE0(DAT_0203a490,0xe4,0x4a,2);
      if (DAT_0203a478._2_2_ == 1) {
        sub_08140914();
        sub_08141D90();
      }
      if (_DAT_0203a45c == 0) {
        if (DAT_0203a4be == 0) {
          _DAT_0203a4d0 = _DAT_0203a4d0 + 2;
        }
        if (DAT_0203a4c0 == 0) {
          _DAT_0203a4d2 = _DAT_0203a4d2 + 2;
        }
        if (DAT_0203a4c2 == 0) {
          _DAT_0203a4d4 = _DAT_0203a4d4 + 2;
        }
        _DAT_0203a464 = _DAT_0203a464 + 4;
      }
      else if (_DAT_0203a45c == 1) {
        if (DAT_0203a4be == 0) {
          DAT_0203a45e = DAT_0203a45e + 9;
          uVar3 = sub_080C2244();
          DAT_0203a494._2_2_ = (ushort)uVar3 & 0xff;
          uVar3 = __divsi3((uint)DAT_0203a494._2_2_ * 0x3b,0xff);
          DAT_0203a45e = DAT_0203a45e + (short)uVar3;
        }
        if (DAT_0203a4c0 == 0) {
          DAT_0203a460._0_2_ = (ushort)DAT_0203a460 + 9;
          uVar3 = sub_080C2244();
          DAT_0203a494._2_2_ = (ushort)uVar3 & 0xff;
          uVar3 = __divsi3((uint)DAT_0203a494._2_2_ * 0x3b,0xff);
          DAT_0203a460._0_2_ = (ushort)DAT_0203a460 + (short)uVar3;
        }
        if (DAT_0203a4c2 == 0) {
          DAT_0203a460._2_2_ = DAT_0203a460._2_2_ + 9;
          uVar3 = sub_080C2244();
          DAT_0203a494._2_2_ = (ushort)uVar3 & 0xff;
          uVar3 = __divsi3((uint)DAT_0203a494._2_2_ * 0x3b,0xff);
          DAT_0203a460._2_2_ = DAT_0203a460._2_2_ + (short)uVar3;
        }
        _DAT_0203a464 = _DAT_0203a464 + 0x12;
      }
      else {
        if (_DAT_0203a45c == 2) {
          if (DAT_0203a4be == 0) {
            _DAT_0203a4d0 = _DAT_0203a4d0 + 2;
          }
          if (DAT_0203a4c0 == 0) {
            DAT_0203a460._0_2_ = (ushort)DAT_0203a460 + 9;
          }
        }
        else {
          if (_DAT_0203a45c != 3) {
            if ((_DAT_0203a45c == 4) && (DAT_0203a4c2 == 0)) {
              _DAT_0203a4d4 = _DAT_0203a4d4 + 2;
            }
            goto LAB_0813f76c;
          }
          if (DAT_0203a4c0 == 0) {
            _DAT_0203a4d2 = _DAT_0203a4d2 + 2;
          }
        }
        if (DAT_0203a4c2 == 0) {
          DAT_0203a460._2_2_ = DAT_0203a460._2_2_ + 9;
        }
      }
LAB_0813f76c:
      if ((_DAT_0203a45c == 0) &&
         (((_DAT_0203a4d0 == 0x28 || (_DAT_0203a4d2 == 0x28)) || (_DAT_0203a4d4 == 0x28)))) {
        _DAT_0203a45c = 1;
        _DAT_0203a4d4 = 0;
        _DAT_0203a4d2 = 0;
        _DAT_0203a4d0 = 0;
      }
      if (((_DAT_0203a45c == 1) && (DAT_0203a45a == 5)) && (0x27 < _DAT_0203a464)) {
        _DAT_0203a45c = 2;
        _DAT_0203a464 = 0;
      }
      if ((_DAT_0203a45c == 2) && ((_DAT_0203a4d0 == 0x3c || (DAT_0203a4be == 1)))) {
        if (DAT_0203a4be == 0) {
          sub_080C51D4(0x15b);
        }
        _DAT_0203a45c = 3;
      }
      if ((_DAT_0203a45c == 3) && ((_DAT_0203a4d2 == 0x3c || (DAT_0203a4c0 == 1)))) {
        if (DAT_0203a4c0 == 0) {
          sub_080C51D4(0x15b);
        }
        _DAT_0203a45c = 4;
      }
      if (DAT_0203a478._2_2_ == 1) {
        sub_080AA184(0x814ec40,0,0,0);
        if (0x14 < DAT_0203a466) {
          sub_080AA184(0x814ec90,0,0,0);
          sub_080AA184(0x814ec80,0,0,0);
        }
        if (0x28 < DAT_0203a466) {
          DAT_0203a466 = 0;
        }
        DAT_0203a466 = DAT_0203a466 + 1;
      }
      if (0x1de < DAT_0203a45e) {
        DAT_0203a45e = 0;
      }
      if (0x1de < (ushort)DAT_0203a460) {
        DAT_0203a460._0_2_ = 0;
      }
      if (0x1de < DAT_0203a460._2_2_) {
        DAT_0203a460._2_2_ = 0;
      }
      if (0x114 < _DAT_0203a464) {
        _DAT_0203a464 = 0;
        DAT_0203a45a = DAT_0203a45a + 1;
      }
      if (((DAT_0203a45a == 5) && (0x3b < _DAT_0203a4d4)) ||
         ((_DAT_0203a45c == 4 && (DAT_0203a4c2 == 1)))) {
        if (DAT_0203a4c2 == 0) {
          sub_080C51D4(0x15b);
        }
        DAT_0203a458 = 4;
        _DAT_0203a474 = 0;
        DAT_0203a45a = 0;
        _DAT_0203a464 = 0;
        if (DAT_0203a4be == 0) {
          DAT_0203a498._2_2_ = (ushort)DAT_0203a4a0;
          DAT_0203a49c._0_2_ = DAT_0203a4a0._2_2_;
          DAT_0203a49c._2_2_ = (ushort)DAT_0203a4a4;
        }
        if (DAT_0203a4c0 == 0) {
          DAT_0203a4a4._2_2_ = DAT_0203a4ac;
          _DAT_0203a4a8 = DAT_0203a4ae;
          DAT_0203a4aa = _DAT_0203a4b0;
        }
        if (DAT_0203a4c2 == 0) {
          _DAT_0203a4b2 = DAT_0203a4b8;
          _DAT_0203a4b4 = DAT_0203a4ba;
          DAT_0203a4b6 = DAT_0203a4bc;
        }
        _DAT_0203a4d4 = 0;
        _DAT_0203a4d2 = 0;
        _DAT_0203a4d0 = 0;
        if (DAT_0203a478._2_2_ == 0) {
          if (_DAT_0203a46c == 0) {
            _DAT_0203a46c = 1;
          }
          else if (DAT_0203a46e != 0) {
            _DAT_0203a46c = DAT_0203a478._2_2_;
            DAT_0203a46e = DAT_0203a478._2_2_;
            DAT_0203a4c2 = DAT_0203a478._2_2_;
            DAT_0203a4c0 = DAT_0203a478._2_2_;
            DAT_0203a4be = DAT_0203a478._2_2_;
          }
        }
      }
      goto FUN_081400f6;
    }
    if (DAT_0203a458 == 4) {
      if (DAT_0203a478._2_2_ == 1) {
        sub_08140AD8();
        sub_080AA184(0x814ec40,0,0,0);
      }
      else {
        if (*(int *)((uint)DAT_0203a498._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x879245c) == 8)
        {
          DAT_0203a482 = 3;
          sub_08140AD8();
        }
        if (*(int *)((uint)(ushort)DAT_0203a49c * 0xc + (uint)DAT_0203b556 * 0x120 + 0x879245c) == 8
           ) {
          DAT_0203a482 = 2;
          sub_08140AD8();
        }
        else if (DAT_0203a472 == 0) {
          sub_08140A24();
        }
        if (*(int *)((uint)DAT_0203a49c._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x879245c) == 8)
        {
          DAT_0203a482 = 1;
          sub_08140AD8();
        }
      }
      sub_080AA184(0x814edb8,0,0,0);
      sub_081403C0();
      sub_08141FE0(_DAT_0203a484,0xe4,0x21,2);
      sub_08141FE0(DAT_0203a490,0xe4,0x4a,2);
      if (DAT_0203a478._2_2_ == 1) {
        sub_08140914();
        sub_08141D90();
      }
      if (DAT_0203a47c._2_2_ == 1) {
        DAT_0203a458 = 7;
        goto FUN_081400f6;
      }
      if (DAT_0203a478._2_2_ == 0) {
        _DAT_0203a480 = 0;
        DAT_0203a482 = 0;
        if (DAT_0203a472 == 0) {
          DAT_0203a458 = 3;
          goto FUN_081400f6;
        }
      }
      else {
        sub_08141F04();
        _DAT_0203a480 = 0;
        DAT_0203a482 = 0;
        if (_DAT_0203a484 == 0) {
          DAT_0203a458 = 6;
          goto FUN_081400f6;
        }
        if ((ushort)DAT_0203a498 == 6) {
          DAT_0203a458 = (ushort)DAT_0203a498;
          DAT_0203a490 = DAT_0203a490 + _DAT_0203a484;
          _DAT_0203a484 = 0;
          goto FUN_081400f6;
        }
      }
      DAT_0203a482 = 0;
      _DAT_0203a480 = 0;
      DAT_0203a458 = 0;
      goto FUN_081400f6;
    }
    if (DAT_0203a458 == 7) {
      sub_080AA184(0x814edb8,0,0,0);
      sub_081403C0();
      sub_08141FE0(_DAT_0203a484,0xe4,0x21,2);
      sub_08141FE0(DAT_0203a490,0xe4,0x4a,2);
      if (DAT_0203a478._2_2_ == 1) {
        sub_080AA184(0x814ec40,0,0,0);
        sub_08140914();
        sub_08141D90();
      }
      if (2 < _DAT_0203a468) {
        _DAT_0203a468 = 0;
        DAT_0203a47c._2_2_ = 0;
        DAT_0203a466 = 0;
        sub_08141B08();
        sub_08141F04();
        if (DAT_0203a478._2_2_ == 1) {
          sub_08141C08();
        }
        DAT_0203a458 = 8;
        goto FUN_081400f6;
      }
      if (5 < DAT_0203a466) {
        sub_08141B08();
        if (DAT_0203a478._2_2_ == 1) {
          sub_080AA184(0x814ecd8,0,0,0);
        }
        switch(DAT_0203a508) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
          sub_080C51D4(0x15d);
          break;
        case 6:
        case 7:
          sub_080C51D4(0x15e);
          break;
        case 8:
          sub_080C51D4(0x15e);
        }
      }
      if (10 < DAT_0203a466) {
LAB_081400d6:
        DAT_0203a466 = 0;
        _DAT_0203a468 = _DAT_0203a468 + 1;
      }
    }
    else {
      if (DAT_0203a458 == 3) {
        if (DAT_0203a46a < 4) {
          sub_080AA184(0x814edd0,0,0,0);
        }
        if ((ushort)(DAT_0203a46a - 4) < 3) {
          sub_080AA184(0x814ede8,0,0,0);
        }
        if ((ushort)(DAT_0203a46a - 7) < 3) {
          sub_080AA184(0x814ee00,0,0,0);
        }
        if (9 < DAT_0203a46a) {
          DAT_0203a458 = 0;
          DAT_0203a46a = 0;
        }
        sub_081403C0();
        sub_08141FE0(_DAT_0203a484,0xe4,0x21,2);
        sub_08141FE0(DAT_0203a490,0xe4,0x4a,2);
        _DAT_0203a45c = 0;
        goto FUN_0813fca2;
      }
      if (DAT_0203a458 == 8) {
        sub_080AA184(0x814edb8,0,0,0);
        sub_081403C0();
        sub_08141B08();
        if (DAT_0203a478._2_2_ == 1) {
          sub_080AA184(0x814ec40,0,0,0);
          sub_08140914();
          sub_08141D90();
        }
        sub_08141FE0(_DAT_0203a484,0xe4,0x21,2);
        sub_08141FE0(DAT_0203a490,0xe4,0x4a,2);
        sub_081420E0();
        goto FUN_081400f6;
      }
      if (DAT_0203a458 == 0) {
        if (0x14 < DAT_0203a466) {
          sub_080AA184(0x814ec10,0,0,0);
          if (DAT_0203a478._2_2_ == 0) {
            sub_080AA184(0x814ece8,0,0,0);
          }
          else {
            sub_080AA184(0x814ed00,0,0,0);
          }
          if ((0x28 < DAT_0203a466) && (DAT_0203a466 = 0, (char)DAT_0203a52c == '\0')) {
            DAT_0203a52c._0_1_ = '\x01';
          }
        }
        uVar1 = _DAT_0203a46c;
        if (_DAT_0203a46c == 1) {
          sub_080AA184(0x814ec70,0,0,0);
          if ((((DAT_030031b8 & 0x20) == 0) || (DAT_0203a4be != 0)) || (1 < DAT_0203a46e)) {
            if (((DAT_030031b8 & 0x20) != 0) && (DAT_0203a4be == 1)) {
              DAT_0203a4be = 0;
              DAT_0203a46e = DAT_0203a46e - 1;
            }
          }
          else {
            sub_080C51D4(0x15c);
            DAT_0203a4be = uVar1;
            DAT_0203a46e = DAT_0203a46e + 1;
          }
          if ((((DAT_030031b8 & 0x40) == 0) || (DAT_0203a4c0 != 0)) || (1 < DAT_0203a46e)) {
            if (((DAT_030031b8 & 0x40) != 0) && (DAT_0203a4c0 == 1)) {
              DAT_0203a4c0 = 0;
              DAT_0203a46e = DAT_0203a46e - 1;
            }
          }
          else {
            sub_080C51D4(0x15c);
            DAT_0203a4c0 = 1;
            DAT_0203a46e = DAT_0203a46e + 1;
          }
          if ((((DAT_030031b8 & 0x10) == 0) || (DAT_0203a4c2 != 0)) || (1 < DAT_0203a46e)) {
            if (((DAT_030031b8 & 0x10) != 0) && (DAT_0203a4c2 == 1)) {
              DAT_0203a4c2 = 0;
              DAT_0203a46e = DAT_0203a46e - 1;
            }
          }
          else {
            sub_080C51D4(0x15c);
            DAT_0203a4c2 = 1;
            DAT_0203a46e = DAT_0203a46e + 1;
          }
          sub_08140810();
        }
        sub_081403C0();
        sub_08141FE0(_DAT_0203a484,0xe4,0x21,2);
        sub_08141FE0(DAT_0203a490,0xe4,0x4a,2);
        uVar1 = DAT_0203a478._2_2_;
        if (DAT_0203a478._2_2_ == 1) {
          sub_080AA184(0x814edb8,0,0,0);
          sub_08140914();
          sub_08141D90();
          if ((_DAT_0203a474 == 0) || ((DAT_030031b8 & 0x40) != 0)) {
            _DAT_0203a474 = uVar1;
          }
          if ((DAT_030031b8 & 0x80) != 0) {
            _DAT_0203a474 = 2;
          }
          if (_DAT_0203a474 == 1) {
            sub_080AA184(0x814ec40,0,0,0);
          }
          else if (_DAT_0203a474 == 2) {
            sub_080AA184(0x814ec58,0,0,0);
          }
          if (0x14 < DAT_0203a466) {
            sub_080AA184(0x814ec90,0,0,0);
            sub_080AA184(0x814ec80,0,0,0);
          }
          if (0x28 < DAT_0203a466) {
            DAT_0203a466 = 0;
          }
        }
        uVar1 = DAT_0203a472;
        if (DAT_0203a472 == 1) {
          sub_080AA184(0x814edb8,0,0,0);
          sub_08141B08();
          if ((_DAT_0203a474 == 0) || ((DAT_030031b8 & 0x40) != 0)) {
            _DAT_0203a474 = uVar1;
          }
          if ((DAT_030031b8 & 0x80) != 0) {
            _DAT_0203a474 = 2;
          }
          if (_DAT_0203a474 == 1) {
            sub_080AA184(0x814ec40,0,0,0);
          }
          else if (_DAT_0203a474 == 2) {
            sub_080AA184(0x814ec58,0,0,0);
          }
          if (0x14 < DAT_0203a466) {
            sub_080AA184(0x814ec90,0,0,0);
            sub_080AA184(0x814ec80,0,0,0);
          }
          if (0x28 < DAT_0203a466) {
            DAT_0203a466 = 0;
          }
        }
      }
      else {
        if (DAT_0203a458 != 9) goto FUN_081400f6;
        sub_081403C0();
        sub_08141FE0(_DAT_0203a484,0xe4,0x21,2);
        sub_08141FE0(DAT_0203a490,0xe4,0x4a,2);
        if (5 < _DAT_0203a468) {
          sub_080C31FC(DAT_0203a490);
          sub_080BE4C4();
          goto FUN_081400f6;
        }
        if (3 < DAT_0203a466) {
          sub_080AA184(0x814ec28,0,0,0);
        }
        if (6 < DAT_0203a466) goto LAB_081400d6;
      }
    }
  }
  DAT_0203a466 = DAT_0203a466 + 1;
FUN_081400f6:
                    /* WARNING: Could not recover jumptable at 0x08140100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_0813fca2 @ 0x0813FCA2

void FUN_0813fca2(void)

{
  int unaff_r6;
  code *UNRECOVERED_JUMPTABLE;
  
  *(short *)(unaff_r6 + 0x16) = *(short *)(unaff_r6 + 0x16) + 1;
                    /* WARNING: Could not recover jumptable at 0x08140100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_081400e0 @ 0x081400E0

void FUN_081400e0(void)

{
  int unaff_r6;
  code *UNRECOVERED_JUMPTABLE;
  
  *(short *)(unaff_r6 + 0x12) = *(short *)(unaff_r6 + 0x12) + 1;
                    /* WARNING: Could not recover jumptable at 0x08140100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_081400f6 @ 0x081400F6

void FUN_081400f6(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x08140100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08140104 @ 0x08140104

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08140104(void)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (_DAT_0203a45c != 0) {
    if (DAT_0203a4be == 0) {
      uVar1 = __udivsi3((uint)DAT_0203a45e,0x14);
      DAT_0203a498._2_2_ = (undefined2)uVar1;
      uVar1 = __udivsi3((uint)DAT_0203a45e,0x14);
      DAT_0203a49c._0_2_ = (short)uVar1 + 1;
      uVar1 = __udivsi3((uint)DAT_0203a45e,0x14);
      DAT_0203a49c._2_2_ = (short)uVar1 + 2;
      uVar1 = __udivsi3((uint)DAT_0203a45e,0x14);
      DAT_0203a4a0._0_2_ = (short)uVar1 + 3;
      uVar1 = __udivsi3((uint)DAT_0203a45e,0x14);
      DAT_0203a4a0._2_2_ = (short)uVar1 + 4;
      uVar1 = __udivsi3((uint)DAT_0203a45e,0x14);
      DAT_0203a4a4._0_2_ = (short)uVar1 + 5;
    }
    if (_DAT_0203a45c != 0) {
      if (DAT_0203a4c0 == 0) {
        uVar1 = __udivsi3((uint)(ushort)DAT_0203a460,0x14);
        DAT_0203a4a4._2_2_ = (undefined2)uVar1;
        uVar1 = __udivsi3((uint)(ushort)DAT_0203a460,0x14);
        _DAT_0203a4a8 = (short)uVar1 + 1;
        uVar1 = __udivsi3((uint)(ushort)DAT_0203a460,0x14);
        DAT_0203a4aa = (short)uVar1 + 2;
        uVar1 = __udivsi3((uint)(ushort)DAT_0203a460,0x14);
        DAT_0203a4ac = (short)uVar1 + 3;
        uVar1 = __udivsi3((uint)(ushort)DAT_0203a460,0x14);
        DAT_0203a4ae = (short)uVar1 + 4;
        uVar1 = __udivsi3((uint)(ushort)DAT_0203a460,0x14);
        _DAT_0203a4b0 = (short)uVar1 + 5;
      }
      if (DAT_0203a4c2 == 0) {
        uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
        _DAT_0203a4b2 = (undefined2)uVar1;
        uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
        _DAT_0203a4b4 = (short)uVar1 + 1;
        uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
        DAT_0203a4b6 = (short)uVar1 + 2;
        uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
        DAT_0203a4b8 = (short)uVar1 + 3;
        uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
        DAT_0203a4ba = (short)uVar1 + 4;
        uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
        DAT_0203a4bc = (short)uVar1 + 5;
      }
    }
  }
  if ((short)DAT_0203a4a4 == 0x18) {
    DAT_0203a4a4._0_2_ = 0;
  }
  if (DAT_0203a4a0._2_2_ == 0x18) {
    DAT_0203a4a0._2_2_ = 0;
    DAT_0203a4a4._0_2_ = 1;
  }
  if ((short)DAT_0203a4a0 == 0x18) {
    DAT_0203a4a0._0_2_ = 0;
    DAT_0203a4a0._2_2_ = 1;
    DAT_0203a4a4._0_2_ = 2;
  }
  if (DAT_0203a49c._2_2_ == 0x18) {
    DAT_0203a49c._2_2_ = 0;
    DAT_0203a4a0._0_2_ = 1;
    DAT_0203a4a0._2_2_ = 2;
    DAT_0203a4a4._0_2_ = 3;
  }
  if ((short)DAT_0203a49c == 0x18) {
    DAT_0203a49c._0_2_ = 0;
    DAT_0203a49c._2_2_ = 1;
    DAT_0203a4a0._0_2_ = 2;
    DAT_0203a4a0._2_2_ = 3;
    DAT_0203a4a4._0_2_ = 4;
  }
  if (_DAT_0203a4b0 == 0x18) {
    _DAT_0203a4b0 = 0;
  }
  if (DAT_0203a4ae == 0x18) {
    DAT_0203a4ae = 0;
    _DAT_0203a4b0 = 1;
  }
  if (DAT_0203a4ac == 0x18) {
    DAT_0203a4ac = 0;
    DAT_0203a4ae = 1;
    _DAT_0203a4b0 = 2;
  }
  if (DAT_0203a4aa == 0x18) {
    DAT_0203a4aa = 0;
    DAT_0203a4ac = 1;
    DAT_0203a4ae = 2;
    _DAT_0203a4b0 = 3;
  }
  if (_DAT_0203a4a8 == 0x18) {
    _DAT_0203a4a8 = 0;
    DAT_0203a4aa = 1;
    DAT_0203a4ac = 2;
    DAT_0203a4ae = 3;
    _DAT_0203a4b0 = 4;
  }
  if (DAT_0203a4bc == 0x18) {
    DAT_0203a4bc = 0;
  }
  if (DAT_0203a4ba == 0x18) {
    DAT_0203a4ba = 0;
    DAT_0203a4bc = 1;
  }
  if (DAT_0203a4b8 == 0x18) {
    DAT_0203a4b8 = 0;
    DAT_0203a4ba = 1;
    DAT_0203a4bc = 2;
  }
  if (DAT_0203a4b6 == 0x18) {
    DAT_0203a4b6 = 0;
    DAT_0203a4b8 = 1;
    DAT_0203a4ba = 2;
    DAT_0203a4bc = 3;
  }
  if (_DAT_0203a4b4 == 0x18) {
    _DAT_0203a4b4 = 0;
    DAT_0203a4b6 = 1;
    DAT_0203a4b8 = 2;
    DAT_0203a4ba = 3;
    DAT_0203a4bc = 4;
  }
                    /* WARNING: Could not recover jumptable at 0x081403ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081403C0 @ 0x081403C0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081403C0(void)

{
  sub_080AA184(*(undefined4 *)
                (&DAT_08792460 + (uint)(ushort)DAT_0203a4a4 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,
               3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08792460 + (uint)DAT_0203a4a0._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3)
  ;
  sub_080AA184(*(undefined4 *)
                (&DAT_08792460 + (uint)(ushort)DAT_0203a4a0 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,
               3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08792460 + (uint)DAT_0203a49c._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3)
  ;
  sub_080AA184(*(undefined4 *)
                (&DAT_08792460 + (uint)(ushort)DAT_0203a49c * 0xc + (uint)DAT_0203b556 * 0x120),1,0,
               3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08792460 + (uint)DAT_0203a498._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3)
  ;
  sub_080AA184(*(undefined4 *)
                (&DAT_087931e0 + (uint)_DAT_0203a4b0 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_087931e0 + (uint)DAT_0203a4ae * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_087931e0 + (uint)DAT_0203a4ac * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_087931e0 + (uint)DAT_0203a4aa * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_087931e0 + (uint)_DAT_0203a4a8 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_087931e0 + (uint)DAT_0203a4a4._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3)
  ;
  sub_080AA184(*(undefined4 *)
                (&DAT_08793f60 + (uint)DAT_0203a4bc * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08793f60 + (uint)DAT_0203a4ba * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08793f60 + (uint)DAT_0203a4b8 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08793f60 + (uint)DAT_0203a4b6 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08793f60 + (uint)_DAT_0203a4b4 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08793f60 + (uint)_DAT_0203a4b2 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  return;
}


// sub_08140810 @ 0x08140810

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08140810(void)

{
  if (DAT_0203a4be == 1) {
    sub_080AA184(0x814eca0,0,0,0);
  }
  if (DAT_0203a4c0 == 1) {
    sub_080AA184(0x814ecb0,0,0,0);
  }
  if (DAT_0203a4c2 == 1) {
    sub_080AA184(0x814ecc0,0,0,0);
  }
  if (DAT_0203a46e < 2) {
    if ((DAT_0203a4be == 0) && (10 < _DAT_0203a470)) {
      sub_080AA184(0x814eca0,0,0,0);
    }
    if ((DAT_0203a4c0 == 0) && (10 < _DAT_0203a470)) {
      sub_080AA184(0x814ecb0,0,0,0);
    }
    if ((DAT_0203a4c2 == 0) && (10 < _DAT_0203a470)) {
      sub_080AA184(0x814ecc0,0,0,0);
    }
    if (0x14 < _DAT_0203a470) {
      _DAT_0203a470 = 0;
    }
    _DAT_0203a470 = _DAT_0203a470 + 1;
  }
  return;
}


// sub_08140914 @ 0x08140914

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08140914(void)

{
  sub_080AA184(*(undefined4 *)(&DAT_08794d94 + DAT_0203a4d8 * 0xc),1,0,0);
  sub_080AA184(*(undefined4 *)(&DAT_08794d94 + DAT_0203a4e0 * 0xc),1,0,0);
  sub_080AA184(*(undefined4 *)(&DAT_08794d94 + _DAT_0203a4e8 * 0xc),1,0,0);
  sub_080AA184(*(undefined4 *)(&DAT_08794d94 + _DAT_0203a4f0 * 0xc),1,0,0);
  sub_080AA184(*(undefined4 *)(&DAT_08794d94 + DAT_0203a4f8 * 0xc),1,0,0);
  sub_080AA184(*(undefined4 *)(&DAT_08794d94 + DAT_0203a500 * 0xc),1,0,0);
  return;
}


// sub_08140A24 @ 0x08140A24

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08140A24(void)

{
  DAT_0203a4c8 = *(int *)((uint)(ushort)DAT_0203a49c * 0xc + (uint)DAT_0203b556 * 0x120 + 0x879245c)
  ;
  if ((DAT_0203a4c8 == *(int *)((uint)_DAT_0203a4a8 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc))
     && (DAT_0203a4c8 ==
         *(int *)((uint)_DAT_0203a4b4 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
    DAT_0203a50c = (uint)(ushort)DAT_0203a49c;
    DAT_0203a518 = (uint)_DAT_0203a4a8;
    _DAT_0203a524 = (uint)_DAT_0203a4b4;
    DAT_0203a52a = 0x2c;
    DAT_0203a51e = 0x2c;
    DAT_0203a512 = 0x2c;
    DAT_0203a47c._2_2_ = 1;
    DAT_0203a472 = 1;
    DAT_0203a48c._0_2_ = 2;
    DAT_0203a508 = DAT_0203a4c8;
    sub_08141F24();
  }
  return;
}


// sub_08140AD8 @ 0x08140AD8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08140AD8(void)

{
  _DAT_0203a4c4 = *(int *)((uint)DAT_0203a498._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x879245c);
  DAT_0203a4c8 = *(int *)((uint)(ushort)DAT_0203a49c * 0xc + (uint)DAT_0203b556 * 0x120 + 0x879245c)
  ;
  DAT_0203a4cc = *(int *)((uint)DAT_0203a49c._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x879245c);
  DAT_0203a494._0_2_ = 0;
  if ((_DAT_0203a480 == 0) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 < 2) &&
       ((DAT_0203a4cc == *(int *)((uint)DAT_0203a4aa * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)
        && (DAT_0203a4cc ==
            *(int *)((uint)DAT_0203a4b6 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))))) {
      DAT_0203a50c = (uint)DAT_0203a49c._2_2_;
      DAT_0203a518 = (uint)DAT_0203a4aa;
      _DAT_0203a524 = (uint)DAT_0203a4b6;
      DAT_0203a52a = 0x18;
      DAT_0203a51e = 0x18;
      DAT_0203a512 = 0x18;
      DAT_0203a47c._2_2_ = 1;
      DAT_0203a472 = 1;
      DAT_0203a48c._0_2_ = 1;
      DAT_0203a508 = DAT_0203a4cc;
      sub_08141F24();
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 1) && (DAT_0203a47c._2_2_ == 0)) {
    if (DAT_0203a482 < 2) {
      if ((DAT_0203a4cc ==
           *(int *)((uint)DAT_0203a4aa * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4cc ==
          *(int *)((uint)_DAT_0203a4b4 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a49c._2_2_;
        DAT_0203a518 = (uint)DAT_0203a4aa;
        _DAT_0203a524 = (uint)_DAT_0203a4b4;
        DAT_0203a508 = DAT_0203a4cc;
        DAT_0203a51e = 0x18;
        DAT_0203a512 = 0x18;
        DAT_0203a52a = 0x2c;
        DAT_0203a47c._2_2_ = _DAT_0203a480;
        DAT_0203a472 = _DAT_0203a480;
        DAT_0203a48c._0_2_ = _DAT_0203a480;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 2) && (DAT_0203a47c._2_2_ == 0)) {
    if (DAT_0203a482 < 2) {
      if ((DAT_0203a4cc ==
           *(int *)((uint)DAT_0203a4aa * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4cc ==
          *(int *)((uint)_DAT_0203a4b2 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a49c._2_2_;
        DAT_0203a518 = (uint)DAT_0203a4aa;
        _DAT_0203a524 = (uint)_DAT_0203a4b2;
        DAT_0203a508 = DAT_0203a4cc;
        DAT_0203a51e = 0x18;
        DAT_0203a512 = 0x18;
        DAT_0203a52a = 0x40;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 1;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 3) && (DAT_0203a47c._2_2_ == 0)) {
    if (DAT_0203a482 < 2) {
      if ((DAT_0203a4cc ==
           *(int *)((uint)_DAT_0203a4a8 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4cc ==
          *(int *)((uint)DAT_0203a4b6 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a49c._2_2_;
        DAT_0203a518 = (uint)_DAT_0203a4a8;
        _DAT_0203a524 = (uint)DAT_0203a4b6;
        DAT_0203a508 = DAT_0203a4cc;
        DAT_0203a52a = 0x18;
        DAT_0203a512 = 0x18;
        DAT_0203a51e = 0x2c;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 1;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 4) && (DAT_0203a47c._2_2_ == 0)) {
    if (DAT_0203a482 < 2) {
      if ((DAT_0203a4cc ==
           *(int *)((uint)_DAT_0203a4a8 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4cc ==
          *(int *)((uint)_DAT_0203a4b4 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a49c._2_2_;
        DAT_0203a518 = (uint)_DAT_0203a4a8;
        _DAT_0203a524 = (uint)_DAT_0203a4b4;
        DAT_0203a508 = DAT_0203a4cc;
        DAT_0203a52a = 0x2c;
        DAT_0203a51e = 0x2c;
        DAT_0203a512 = 0x18;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 1;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 5) && (DAT_0203a47c._2_2_ == 0)) {
    if (DAT_0203a482 < 2) {
      if ((DAT_0203a4cc ==
           *(int *)((uint)_DAT_0203a4a8 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4cc ==
          *(int *)((uint)_DAT_0203a4b2 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a49c._2_2_;
        DAT_0203a518 = (uint)_DAT_0203a4a8;
        _DAT_0203a524 = (uint)_DAT_0203a4b2;
        DAT_0203a508 = DAT_0203a4cc;
        DAT_0203a512 = 0x18;
        DAT_0203a51e = 0x2c;
        DAT_0203a52a = 0x40;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 1;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 6) && (DAT_0203a47c._2_2_ == 0)) {
    if (DAT_0203a482 < 2) {
      if ((DAT_0203a4cc ==
           *(int *)((uint)DAT_0203a4a4._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4cc ==
          *(int *)((uint)DAT_0203a4b6 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a49c._2_2_;
        DAT_0203a518 = (uint)DAT_0203a4a4._2_2_;
        _DAT_0203a524 = (uint)DAT_0203a4b6;
        DAT_0203a508 = DAT_0203a4cc;
        DAT_0203a52a = 0x18;
        DAT_0203a512 = 0x18;
        DAT_0203a51e = 0x40;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 1;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 7) && (DAT_0203a47c._2_2_ == 0)) {
    if (DAT_0203a482 < 2) {
      if ((DAT_0203a4cc ==
           *(int *)((uint)DAT_0203a4a4._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4cc ==
          *(int *)((uint)_DAT_0203a4b4 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a49c._2_2_;
        DAT_0203a518 = (uint)DAT_0203a4a4._2_2_;
        _DAT_0203a524 = (uint)_DAT_0203a4b4;
        DAT_0203a508 = DAT_0203a4cc;
        DAT_0203a512 = 0x18;
        DAT_0203a51e = 0x40;
        DAT_0203a52a = 0x2c;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 1;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 8) && (DAT_0203a47c._2_2_ == 0)) {
    if (DAT_0203a482 < 2) {
      if ((DAT_0203a4cc ==
           *(int *)((uint)DAT_0203a4a4._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4cc ==
          *(int *)((uint)_DAT_0203a4b2 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a49c._2_2_;
        DAT_0203a518 = (uint)DAT_0203a4a4._2_2_;
        _DAT_0203a524 = (uint)_DAT_0203a4b2;
        DAT_0203a508 = DAT_0203a4cc;
        DAT_0203a52a = 0x40;
        DAT_0203a51e = 0x40;
        DAT_0203a512 = 0x18;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 1;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 9) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 2)) {
      if ((DAT_0203a4c8 ==
           *(int *)((uint)DAT_0203a4aa * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4c8 ==
          *(int *)((uint)DAT_0203a4b6 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)(ushort)DAT_0203a49c;
        DAT_0203a518 = (uint)DAT_0203a4aa;
        _DAT_0203a524 = (uint)DAT_0203a4b6;
        DAT_0203a508 = DAT_0203a4c8;
        DAT_0203a512 = 0x2c;
        DAT_0203a52a = 0x18;
        DAT_0203a51e = 0x18;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 2;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 10) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 2)) {
      if ((DAT_0203a4c8 ==
           *(int *)((uint)DAT_0203a4aa * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4c8 ==
          *(int *)((uint)_DAT_0203a4b4 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)(ushort)DAT_0203a49c;
        DAT_0203a518 = (uint)DAT_0203a4aa;
        _DAT_0203a524 = (uint)_DAT_0203a4b4;
        DAT_0203a508 = DAT_0203a4c8;
        DAT_0203a52a = 0x2c;
        DAT_0203a512 = 0x2c;
        DAT_0203a51e = 0x18;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 2;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0xb) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 2)) {
      if ((DAT_0203a4c8 ==
           *(int *)((uint)DAT_0203a4aa * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4c8 ==
          *(int *)((uint)_DAT_0203a4b2 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)(ushort)DAT_0203a49c;
        DAT_0203a518 = (uint)DAT_0203a4aa;
        _DAT_0203a524 = (uint)_DAT_0203a4b2;
        DAT_0203a508 = DAT_0203a4c8;
        DAT_0203a512 = 0x2c;
        DAT_0203a51e = 0x18;
        DAT_0203a52a = 0x40;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 2;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0xc) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 2)) {
      if ((DAT_0203a4c8 ==
           *(int *)((uint)_DAT_0203a4a8 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4c8 ==
          *(int *)((uint)DAT_0203a4b6 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)(ushort)DAT_0203a49c;
        DAT_0203a518 = (uint)_DAT_0203a4a8;
        _DAT_0203a524 = (uint)DAT_0203a4b6;
        DAT_0203a508 = DAT_0203a4c8;
        DAT_0203a51e = 0x2c;
        DAT_0203a512 = 0x2c;
        DAT_0203a52a = 0x18;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 2;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0xd) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 2)) {
      if ((DAT_0203a4c8 ==
           *(int *)((uint)_DAT_0203a4a8 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4c8 ==
          *(int *)((uint)_DAT_0203a4b4 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)(ushort)DAT_0203a49c;
        DAT_0203a518 = (uint)_DAT_0203a4a8;
        _DAT_0203a524 = (uint)_DAT_0203a4b4;
        DAT_0203a508 = DAT_0203a4c8;
        DAT_0203a52a = 0x2c;
        DAT_0203a51e = 0x2c;
        DAT_0203a512 = 0x2c;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 2;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0xe) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 2)) {
      if ((DAT_0203a4c8 ==
           *(int *)((uint)_DAT_0203a4a8 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4c8 ==
          *(int *)((uint)_DAT_0203a4b2 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)(ushort)DAT_0203a49c;
        DAT_0203a518 = (uint)_DAT_0203a4a8;
        _DAT_0203a524 = (uint)_DAT_0203a4b2;
        DAT_0203a508 = DAT_0203a4c8;
        DAT_0203a51e = 0x2c;
        DAT_0203a512 = 0x2c;
        DAT_0203a52a = 0x40;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 2;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0xf) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 2)) {
      if ((DAT_0203a4c8 ==
           *(int *)((uint)DAT_0203a4a4._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4c8 ==
          *(int *)((uint)DAT_0203a4b6 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)(ushort)DAT_0203a49c;
        DAT_0203a518 = (uint)DAT_0203a4a4._2_2_;
        _DAT_0203a524 = (uint)DAT_0203a4b6;
        DAT_0203a508 = DAT_0203a4c8;
        DAT_0203a512 = 0x2c;
        DAT_0203a51e = 0x40;
        DAT_0203a52a = 0x18;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 2;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0x10) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 2)) {
      if ((DAT_0203a4c8 ==
           *(int *)((uint)DAT_0203a4a4._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4c8 ==
          *(int *)((uint)_DAT_0203a4b4 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)(ushort)DAT_0203a49c;
        DAT_0203a518 = (uint)DAT_0203a4a4._2_2_;
        _DAT_0203a524 = (uint)_DAT_0203a4b4;
        DAT_0203a508 = DAT_0203a4c8;
        DAT_0203a52a = 0x2c;
        DAT_0203a512 = 0x2c;
        DAT_0203a51e = 0x40;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 2;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0x11) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 2)) {
      if ((DAT_0203a4c8 ==
           *(int *)((uint)DAT_0203a4a4._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (DAT_0203a4c8 ==
          *(int *)((uint)_DAT_0203a4b2 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)(ushort)DAT_0203a49c;
        DAT_0203a518 = (uint)DAT_0203a4a4._2_2_;
        _DAT_0203a524 = (uint)_DAT_0203a4b2;
        DAT_0203a508 = DAT_0203a4c8;
        DAT_0203a512 = 0x2c;
        DAT_0203a52a = 0x40;
        DAT_0203a51e = 0x40;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 2;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0x12) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 3)) {
      if ((_DAT_0203a4c4 ==
           *(int *)((uint)DAT_0203a4aa * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (_DAT_0203a4c4 ==
          *(int *)((uint)DAT_0203a4b6 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a498._2_2_;
        DAT_0203a518 = (uint)DAT_0203a4aa;
        _DAT_0203a524 = (uint)DAT_0203a4b6;
        DAT_0203a508 = _DAT_0203a4c4;
        DAT_0203a512 = 0x40;
        DAT_0203a52a = 0x18;
        DAT_0203a51e = 0x18;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 3;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0x13) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 3)) {
      if ((_DAT_0203a4c4 ==
           *(int *)((uint)DAT_0203a4aa * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (_DAT_0203a4c4 ==
          *(int *)((uint)_DAT_0203a4b4 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a498._2_2_;
        DAT_0203a518 = (uint)DAT_0203a4aa;
        _DAT_0203a524 = (uint)_DAT_0203a4b4;
        DAT_0203a508 = _DAT_0203a4c4;
        DAT_0203a512 = 0x40;
        DAT_0203a51e = 0x18;
        DAT_0203a52a = 0x2c;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 3;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0x14) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 3)) {
      if ((_DAT_0203a4c4 ==
           *(int *)((uint)DAT_0203a4aa * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (_DAT_0203a4c4 ==
          *(int *)((uint)_DAT_0203a4b2 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a498._2_2_;
        DAT_0203a518 = (uint)DAT_0203a4aa;
        _DAT_0203a524 = (uint)_DAT_0203a4b2;
        DAT_0203a508 = _DAT_0203a4c4;
        DAT_0203a52a = 0x40;
        DAT_0203a512 = 0x40;
        DAT_0203a51e = 0x18;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 3;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0x15) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 3)) {
      if ((_DAT_0203a4c4 ==
           *(int *)((uint)_DAT_0203a4a8 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (_DAT_0203a4c4 ==
          *(int *)((uint)DAT_0203a4b6 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a498._2_2_;
        DAT_0203a518 = (uint)_DAT_0203a4a8;
        _DAT_0203a524 = (uint)DAT_0203a4b6;
        DAT_0203a508 = _DAT_0203a4c4;
        DAT_0203a512 = 0x40;
        DAT_0203a51e = 0x2c;
        DAT_0203a52a = 0x18;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 3;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0x16) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 3)) {
      if ((_DAT_0203a4c4 ==
           *(int *)((uint)_DAT_0203a4a8 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (_DAT_0203a4c4 ==
          *(int *)((uint)_DAT_0203a4b4 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a498._2_2_;
        DAT_0203a518 = (uint)_DAT_0203a4a8;
        _DAT_0203a524 = (uint)_DAT_0203a4b4;
        DAT_0203a508 = _DAT_0203a4c4;
        DAT_0203a512 = 0x40;
        DAT_0203a52a = 0x2c;
        DAT_0203a51e = 0x2c;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 3;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0x17) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 3)) {
      if ((_DAT_0203a4c4 ==
           *(int *)((uint)_DAT_0203a4a8 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (_DAT_0203a4c4 ==
          *(int *)((uint)_DAT_0203a4b2 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a498._2_2_;
        DAT_0203a518 = (uint)_DAT_0203a4a8;
        _DAT_0203a524 = (uint)_DAT_0203a4b2;
        DAT_0203a508 = _DAT_0203a4c4;
        DAT_0203a52a = 0x40;
        DAT_0203a512 = 0x40;
        DAT_0203a51e = 0x2c;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 3;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0x18) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 3)) {
      if ((_DAT_0203a4c4 ==
           *(int *)((uint)DAT_0203a4a4._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (_DAT_0203a4c4 ==
          *(int *)((uint)DAT_0203a4b6 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a498._2_2_;
        DAT_0203a518 = (uint)DAT_0203a4a4._2_2_;
        _DAT_0203a524 = (uint)DAT_0203a4b6;
        DAT_0203a508 = _DAT_0203a4c4;
        DAT_0203a51e = 0x40;
        DAT_0203a512 = 0x40;
        DAT_0203a52a = _DAT_0203a480;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 3;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0x19) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 3)) {
      if ((_DAT_0203a4c4 ==
           *(int *)((uint)DAT_0203a4a4._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (_DAT_0203a4c4 ==
          *(int *)((uint)_DAT_0203a4b4 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a498._2_2_;
        DAT_0203a518 = (uint)DAT_0203a4a4._2_2_;
        _DAT_0203a524 = (uint)_DAT_0203a4b4;
        DAT_0203a508 = _DAT_0203a4c4;
        DAT_0203a51e = 0x40;
        DAT_0203a512 = 0x40;
        DAT_0203a52a = 0x2c;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 3;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if ((_DAT_0203a480 == 0x1a) && (DAT_0203a47c._2_2_ == 0)) {
    if ((DAT_0203a482 == 0) || (DAT_0203a482 == 3)) {
      if ((_DAT_0203a4c4 ==
           *(int *)((uint)DAT_0203a4a4._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87931dc)) &&
         (_DAT_0203a4c4 ==
          *(int *)((uint)_DAT_0203a4b2 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8793f5c))) {
        DAT_0203a50c = (uint)DAT_0203a498._2_2_;
        DAT_0203a518 = (uint)DAT_0203a4a4._2_2_;
        _DAT_0203a524 = (uint)_DAT_0203a4b2;
        DAT_0203a508 = _DAT_0203a4c4;
        DAT_0203a52a = 0x40;
        DAT_0203a51e = 0x40;
        DAT_0203a512 = 0x40;
        _DAT_0203a480 = 0x1b;
        DAT_0203a47c._2_2_ = 1;
        DAT_0203a472 = 1;
        DAT_0203a48c._0_2_ = 3;
        sub_08141F24();
      }
    }
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  return;
}


// sub_08141B08 @ 0x08141B08

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08141B08(void)

{
  sub_080AA184(*(undefined4 *)(&DAT_08792464 + DAT_0203a50c * 0xc + (uint)DAT_0203b556 * 0x120),0,0,
               3);
  sub_080AA184(*(undefined4 *)(&DAT_087931e4 + DAT_0203a518 * 0xc + (uint)DAT_0203b556 * 0x120),0,0,
               3);
  sub_080AA184(*(undefined4 *)(&DAT_08793f64 + _DAT_0203a524 * 0xc + (uint)DAT_0203b556 * 0x120),0,0
               ,3);
  sub_080AA184(*(undefined4 *)(DAT_0203a508 * 0x14 + 0x8794cdc),0,0,0);
  return;
}


// sub_08141C08 @ 0x08141C08

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08141C08(void)

{
  if (((_DAT_0203a4dc == 0) && ((short)DAT_0203a494 == 0)) &&
     (*(int *)(DAT_0203a4d8 * 0xc + 0x8794d90) == DAT_0203a508)) {
    _DAT_0203a4dc = 1;
    DAT_0203a494._0_2_ = 1;
    DAT_0203a498._0_2_ = (short)DAT_0203a498 + 1;
  }
  if (((_DAT_0203a4e4 == 0) && ((short)DAT_0203a494 == 0)) &&
     (*(int *)(DAT_0203a4e0 * 0xc + 0x8794d90) == DAT_0203a508)) {
    _DAT_0203a4e4 = 1;
    DAT_0203a494._0_2_ = 1;
    DAT_0203a498._0_2_ = (short)DAT_0203a498 + 1;
  }
  if (((_DAT_0203a4ec == 0) && ((short)DAT_0203a494 == 0)) &&
     (*(int *)(_DAT_0203a4e8 * 0xc + 0x8794d90) == DAT_0203a508)) {
    _DAT_0203a4ec = 1;
    DAT_0203a494._0_2_ = 1;
    DAT_0203a498._0_2_ = (short)DAT_0203a498 + 1;
  }
  if (((_DAT_0203a4f4 == 0) && ((short)DAT_0203a494 == 0)) &&
     (*(int *)(_DAT_0203a4f0 * 0xc + 0x8794d90) == DAT_0203a508)) {
    _DAT_0203a4f4 = 1;
    DAT_0203a494._0_2_ = 1;
    DAT_0203a498._0_2_ = (short)DAT_0203a498 + 1;
  }
  if (((DAT_0203a4fc == 0) && ((short)DAT_0203a494 == 0)) &&
     (*(int *)(DAT_0203a4f8 * 0xc + 0x8794d90) == DAT_0203a508)) {
    DAT_0203a4fc = 1;
    DAT_0203a494._0_2_ = 1;
    DAT_0203a498._0_2_ = (short)DAT_0203a498 + 1;
  }
  if ((((short)DAT_0203a504 == 0) && ((short)DAT_0203a494 == 0)) &&
     (*(int *)(DAT_0203a500 * 0xc + 0x8794d90) == DAT_0203a508)) {
    DAT_0203a504._0_2_ = 1;
    DAT_0203a494._0_2_ = 1;
    DAT_0203a498._0_2_ = (short)DAT_0203a498 + 1;
  }
  return;
}


// sub_08141D90 @ 0x08141D90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08141D90(void)

{
  if (_DAT_0203a4dc == 1) {
    sub_080AA184(*(undefined4 *)(&DAT_08794d98 + DAT_0203a4d8 * 0xc),0,0,0);
  }
  if (_DAT_0203a4e4 == 1) {
    sub_080AA184(*(undefined4 *)(&DAT_08794d98 + DAT_0203a4e0 * 0xc),0,0,0);
  }
  if (_DAT_0203a4ec == 1) {
    sub_080AA184(*(undefined4 *)(&DAT_08794d98 + _DAT_0203a4e8 * 0xc),0,0,0);
  }
  if (_DAT_0203a4f4 == 1) {
    sub_080AA184(*(undefined4 *)(&DAT_08794d98 + _DAT_0203a4f0 * 0xc),0,0,0);
  }
  if (DAT_0203a4fc == 1) {
    sub_080AA184(*(undefined4 *)(&DAT_08794d98 + DAT_0203a4f8 * 0xc),0,0,0);
  }
  if ((short)DAT_0203a504 == 1) {
    sub_080AA184(*(undefined4 *)(&DAT_08794d98 + DAT_0203a500 * 0xc),0,0,0);
  }
  return;
}


// sub_08141F04 @ 0x08141F04

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08141F04(void)

{
  _DAT_0203a46c = 0;
  DAT_0203a46e = 0;
  DAT_0203a4c2 = 0;
  DAT_0203a4c0 = 0;
  DAT_0203a4be = 0;
  _DAT_0203a45c = 0;
  return;
}


// sub_08141F24 @ 0x08141F24

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08141F24(void)

{
  uint uVar1;
  int iVar2;
  
  _DAT_0203a488 = _DAT_0203a484;
  if ((short)DAT_0203a48c == 1) {
    iVar2 = DAT_0203a4cc;
    if (DAT_0203a4cc == 8) {
      uVar1 = sub_080C2244();
      _DAT_0203a488 = _DAT_0203a488 + *(ushort *)(&DAT_08794d84 + (uVar1 & 4) * 2);
      goto LAB_08141fc4;
    }
  }
  else if ((short)DAT_0203a48c == 2) {
    iVar2 = DAT_0203a4c8;
    if (DAT_0203a4c8 == 8) {
      uVar1 = sub_080C2244();
      _DAT_0203a488 = _DAT_0203a488 + *(ushort *)(&DAT_08794d84 + (uVar1 & 4) * 2);
      goto LAB_08141fc4;
    }
  }
  else {
    if ((short)DAT_0203a48c != 3) goto LAB_08141fc4;
    iVar2 = _DAT_0203a4c4;
    if (_DAT_0203a4c4 == 8) {
      uVar1 = sub_080C2244();
      _DAT_0203a488 = _DAT_0203a488 + *(ushort *)(&DAT_08794d84 + (uVar1 & 4) * 2);
      goto LAB_08141fc4;
    }
  }
  _DAT_0203a488 = _DAT_0203a484 + *(ushort *)(&DAT_08794ce4 + iVar2 * 0x14);
LAB_08141fc4:
  if (999 < _DAT_0203a488) {
    _DAT_0203a488 = 1000;
  }
  return;
}


// sub_08141FE0 @ 0x08141FE0

void sub_08141FE0(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  byte *pbVar1;
  uint arg3_00;
  
  arg3_00 = arg3 & 0xffff;
  pbVar1 = (byte *)sub_080A9CC0(arg0);
  sub_080AA184(*(undefined4 *)((uint)*pbVar1 * 4 + 0x8794dfc),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[1] * 4 + 0x8794dfc),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[2] * 4 + 0x8794dfc),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[3] * 4 + 0x8794dfc),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[4] * 4 + 0x8794dfc),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[5] * 4 + 0x8794dfc),0,0,arg3_00);
  return;
}


// sub_081420E0 @ 0x081420E0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081420E0(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if ((DAT_030031bc & 3) == 0) {
    if (_DAT_0203a484 == _DAT_0203a488) {
      if (_DAT_0203a484 == 1000) {
        DAT_0203a490 = DAT_0203a490 + 1000;
        DAT_0203a458 = 6;
        _DAT_0203a484 = 0;
      }
      else {
        DAT_0203a458 = 4;
      }
    }
    else {
      sub_080C51D4(0x159);
      _DAT_0203a484 = _DAT_0203a484 + 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08142130. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08142134 @ 0x08142134

void sub_08142134(undefined4 arg0,undefined4 arg1)

{
  DAT_0203a454 = (undefined2)arg1;
  return;
}


// sub_08142140 @ 0x08142140

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08142140(void)

{
  undefined4 local_14;
  
  local_14 = 0;
  CpuSet(&local_14,0x203a454,0x5000200);
  REG_BG0CNT = 0x4008;
  DAT_03000002 = 0;
  DAT_03000040 = 0;
  DAT_0203a454 = 1;
  DAT_0203a490 = sub_080C31F0();
  DAT_0203a48a = 2;
  DAT_0203a4e0._0_2_ = 0;
  _DAT_0203a4d4 = 0;
  DAT_0203a4c8._0_2_ = 0;
  DAT_0203a4bc = 0;
  DAT_0203a4e0._2_2_ = 1;
  DAT_0203a4d6 = 1;
  DAT_0203a4c8._2_2_ = 1;
  DAT_0203a4be = 1;
  _DAT_0203a4e4 = 2;
  DAT_0203a4d8._0_2_ = 2;
  DAT_0203a4cc._0_2_ = 2;
  DAT_0203a4c0 = 2;
  DAT_0203a4e6 = 3;
  DAT_0203a4d8._2_2_ = 3;
  DAT_0203a4cc._2_2_ = 3;
  DAT_0203a4c2 = 3;
  _DAT_0203a4e8 = 4;
  _DAT_0203a4dc = 4;
  _DAT_0203a4d0 = 4;
  _DAT_0203a4c4 = 4;
  _DAT_0203a4ea = 5;
  DAT_0203a4de = 5;
  _DAT_0203a4d2 = 5;
  DAT_0203a4c6 = 5;
  return;
}


// sub_08142200 @ 0x08142200

void sub_08142200(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  dword arg0;
  
  if (DAT_0203a454 == 1) {
    sub_080AD0FC(0x879874c,0xffff);
    DAT_0203a454 = 0;
  }
  sub_081429B4();
  sub_08142F08(DAT_0203a494,0x2f,0x20,0);
  sub_08142F08(DAT_0203a490,0xe5,0x20,0);
  sub_080AA184(0x814f508,0,0,0);
  if (DAT_0203a482._1_1_ == 1) {
    sub_08143BF8();
  }
  if (DAT_0203a486 == 1) {
    sub_080AA184(0x814f29c,0,0,0);
  }
  if ((char)DAT_0203a47c == '\x01') {
    sub_08143ED0();
  }
  sub_08144270();
  if (DAT_0203a48a == 3) {
    arg0 = 0x814f2fc;
LAB_081422d6:
    sub_080AA184(arg0,0,0,0);
  }
  else if (DAT_0203a48a < 4) {
    if (DAT_0203a48a == 2) {
      arg0 = 0x814f2cc;
      goto LAB_081422d6;
    }
  }
  else {
    if (DAT_0203a48a == 4) {
      arg0 = 0x814f32c;
      goto LAB_081422d6;
    }
    if (DAT_0203a48a == 5) {
      sub_080AA184(0x814f35c,0,0,0);
    }
  }
  bVar3 = DAT_0203a53c;
  bVar1 = (byte)DAT_0203a458;
  if (DAT_0203a53c == 1) {
    if ((((DAT_030031b8 & 0x100) != 0) && ((byte)DAT_0203a458 == 0)) && (DAT_0203a490 != 0)) {
      sub_080C51D4(0x15a);
      DAT_0203a458._0_1_ = bVar3;
      DAT_0203a4f8._3_1_ = bVar1;
      DAT_0203a4aa._0_1_ = bVar1;
      DAT_0203a485 = bVar1;
      DAT_0203a4a8 = bVar1;
      DAT_0203a484 = bVar1;
      DAT_0203a482._1_1_ = bVar1;
      DAT_0203a4a4._2_1_ = bVar1;
      DAT_0203a47c._3_1_ = bVar1;
      DAT_0203a4a4._0_1_ = bVar3;
      DAT_0203a490 = DAT_0203a490 + -1;
    }
    if ((DAT_030031b8 & 0x200) == 0) goto LAB_08142386;
    if ((byte)DAT_0203a458 == 0) {
      sub_080C51D4(0x158);
      DAT_0203a458._0_1_ = 10;
      goto LAB_08142386;
    }
  }
  else {
LAB_08142386:
    cVar2 = (char)DAT_0203a47c;
    if (((byte)DAT_0203a458 == 0) && ((char)DAT_0203a47c == '\x01')) {
      if (((DAT_030031b8 & 0x20) == 0) || ((DAT_0203a45d != '\0' || (2 < DAT_0203a47c._1_1_)))) {
        if (((DAT_030031b8 & 0x20) != 0) && (DAT_0203a45d == '\x01')) {
          DAT_0203a45d = '\0';
          DAT_0203a47c._1_1_ = DAT_0203a47c._1_1_ - 1;
        }
      }
      else {
        sub_080C51D4(0x15c);
        DAT_0203a45d = cVar2;
        DAT_0203a47c._1_1_ = DAT_0203a47c._1_1_ + 1;
      }
      if ((((DAT_030031b8 & 0x40) == 0) || ((char)DAT_0203a45e != '\0')) || (2 < DAT_0203a47c._1_1_)
         ) {
        if (((DAT_030031b8 & 0x40) != 0) && ((char)DAT_0203a45e == '\x01')) {
          DAT_0203a45e._0_1_ = '\0';
          DAT_0203a47c._1_1_ = DAT_0203a47c._1_1_ - 1;
        }
      }
      else {
        sub_080C51D4(0x15c);
        DAT_0203a45e._0_1_ = '\x01';
        DAT_0203a47c._1_1_ = DAT_0203a47c._1_1_ + 1;
      }
      if ((((DAT_030031b8 & 0x10) == 0) || (DAT_0203a45e._1_1_ != '\0')) || (2 < DAT_0203a47c._1_1_)
         ) {
        if (((DAT_030031b8 & 0x10) != 0) && (DAT_0203a45e._1_1_ == '\x01')) {
          DAT_0203a45e._1_1_ = '\0';
          DAT_0203a47c._1_1_ = DAT_0203a47c._1_1_ - 1;
        }
      }
      else {
        sub_080C51D4(0x15c);
        DAT_0203a45e._1_1_ = '\x01';
        DAT_0203a47c._1_1_ = DAT_0203a47c._1_1_ + 1;
      }
      if ((((DAT_030031b8 & 0x80) == 0) || ((char)DAT_0203a460 != '\0')) || (2 < DAT_0203a47c._1_1_)
         ) {
        if (((DAT_030031b8 & 0x80) != 0) && ((char)DAT_0203a460 == '\x01')) {
          DAT_0203a460._0_1_ = '\0';
          DAT_0203a47c._1_1_ = DAT_0203a47c._1_1_ - 1;
        }
      }
      else {
        sub_080C51D4(0x15c);
        DAT_0203a460._0_1_ = '\x01';
        DAT_0203a47c._1_1_ = DAT_0203a47c._1_1_ + 1;
      }
    }
  }
  switch((byte)DAT_0203a458) {
  case 0:
    if (((0x14 < DAT_0203a4a9) && (sub_080AA184(0x814f1cc,0,0,0), 0x28 < DAT_0203a4a9)) &&
       (DAT_0203a4a9 = 0, DAT_0203a53c == 0)) {
      DAT_0203a53c = 1;
    }
    goto LAB_081425f2;
  case 1:
    sub_08142618();
    sub_0814328C();
    break;
  case 2:
    if (DAT_0203a482._1_1_ == 0) {
      sub_08143A68();
    }
    if (DAT_0203a4f8._3_1_ == 1) {
      sub_08143CB8();
    }
    if (DAT_0203a485 == 1) {
      sub_081437E4();
    }
    break;
  case 3:
    if ((byte)DAT_0203a4a4 == 1) {
      sub_08143044();
    }
    else {
      sub_081431F8();
    }
    sub_081445C4();
    break;
  case 10:
    if (5 < DAT_0203a4a8) {
      sub_080C31FC(DAT_0203a490);
      sub_080BE4C4();
      return;
    }
    if (3 < DAT_0203a4a9) {
      sub_080AA184(0x814f1e4,0,0,0);
    }
    if (6 < DAT_0203a4a9) {
      DAT_0203a4a9 = 0;
      DAT_0203a4a8 = DAT_0203a4a8 + 1;
    }
LAB_081425f2:
    DAT_0203a4a9 = DAT_0203a4a9 + 1;
  }
  return;
}


// sub_08142618 @ 0x08142618

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08142618(void)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a47c._3_1_ != '\0') {
    if (DAT_0203a45d == '\0') {
      uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
      DAT_0203a4bc = (undefined2)uVar1;
      uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
      DAT_0203a4be = (short)uVar1 + 1;
      uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
      DAT_0203a4c0 = (short)uVar1 + 2;
      uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
      DAT_0203a4c2 = (short)uVar1 + 3;
      uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
      _DAT_0203a4c4 = (short)uVar1 + 4;
      uVar1 = __udivsi3((uint)DAT_0203a460._2_2_,0x14);
      DAT_0203a4c6 = (short)uVar1 + 5;
    }
    if (DAT_0203a47c._3_1_ != '\0') {
      if ((char)DAT_0203a45e == '\0') {
        uVar1 = __udivsi3((uint)_DAT_0203a464,0x14);
        DAT_0203a4c8._0_2_ = (undefined2)uVar1;
        uVar1 = __udivsi3((uint)_DAT_0203a464,0x14);
        DAT_0203a4c8._2_2_ = (short)uVar1 + 1;
        uVar1 = __udivsi3((uint)_DAT_0203a464,0x14);
        DAT_0203a4cc._0_2_ = (short)uVar1 + 2;
        uVar1 = __udivsi3((uint)_DAT_0203a464,0x14);
        DAT_0203a4cc._2_2_ = (short)uVar1 + 3;
        uVar1 = __udivsi3((uint)_DAT_0203a464,0x14);
        _DAT_0203a4d0 = (short)uVar1 + 4;
        uVar1 = __udivsi3((uint)_DAT_0203a464,0x14);
        _DAT_0203a4d2 = (short)uVar1 + 5;
      }
      if (DAT_0203a45e._1_1_ == '\0') {
        uVar1 = __udivsi3((uint)DAT_0203a466,0x14);
        _DAT_0203a4d4 = (undefined2)uVar1;
        uVar1 = __udivsi3((uint)DAT_0203a466,0x14);
        DAT_0203a4d6 = (short)uVar1 + 1;
        uVar1 = __udivsi3((uint)DAT_0203a466,0x14);
        DAT_0203a4d8._0_2_ = (short)uVar1 + 2;
        uVar1 = __udivsi3((uint)DAT_0203a466,0x14);
        DAT_0203a4d8._2_2_ = (short)uVar1 + 3;
        uVar1 = __udivsi3((uint)DAT_0203a466,0x14);
        _DAT_0203a4dc = (short)uVar1 + 4;
        uVar1 = __udivsi3((uint)DAT_0203a466,0x14);
        DAT_0203a4de = (short)uVar1 + 5;
      }
      if ((char)DAT_0203a460 == '\0') {
        uVar1 = __udivsi3((uint)_DAT_0203a468,0x14);
        DAT_0203a4e0._0_2_ = (undefined2)uVar1;
        uVar1 = __udivsi3((uint)_DAT_0203a468,0x14);
        DAT_0203a4e0._2_2_ = (short)uVar1 + 1;
        uVar1 = __udivsi3((uint)_DAT_0203a468,0x14);
        _DAT_0203a4e4 = (short)uVar1 + 2;
        uVar1 = __udivsi3((uint)_DAT_0203a468,0x14);
        DAT_0203a4e6 = (short)uVar1 + 3;
        uVar1 = __udivsi3((uint)_DAT_0203a468,0x14);
        _DAT_0203a4e8 = (short)uVar1 + 4;
        uVar1 = __udivsi3((uint)_DAT_0203a468,0x14);
        _DAT_0203a4ea = (short)uVar1 + 5;
      }
    }
  }
  if (DAT_0203a4c6 == 0x18) {
    DAT_0203a4c6 = 0;
  }
  if (_DAT_0203a4c4 == 0x18) {
    _DAT_0203a4c4 = 0;
    DAT_0203a4c6 = 1;
  }
  if (DAT_0203a4c2 == 0x18) {
    DAT_0203a4c2 = 0;
    _DAT_0203a4c4 = 1;
    DAT_0203a4c6 = 2;
  }
  if (DAT_0203a4c0 == 0x18) {
    DAT_0203a4c0 = 0;
    DAT_0203a4c2 = 1;
    _DAT_0203a4c4 = 2;
    DAT_0203a4c6 = 3;
  }
  if (DAT_0203a4be == 0x18) {
    DAT_0203a4be = 0;
    DAT_0203a4c0 = 1;
    DAT_0203a4c2 = 2;
    _DAT_0203a4c4 = 3;
    DAT_0203a4c6 = 4;
  }
  if (_DAT_0203a4d2 == 0x18) {
    _DAT_0203a4d2 = 0;
  }
  if (_DAT_0203a4d0 == 0x18) {
    _DAT_0203a4d0 = 0;
    _DAT_0203a4d2 = 1;
  }
  if (DAT_0203a4cc._2_2_ == 0x18) {
    DAT_0203a4cc._2_2_ = 0;
    _DAT_0203a4d0 = 1;
    _DAT_0203a4d2 = 2;
  }
  if ((short)DAT_0203a4cc == 0x18) {
    DAT_0203a4cc._0_2_ = 0;
    DAT_0203a4cc._2_2_ = 1;
    _DAT_0203a4d0 = 2;
    _DAT_0203a4d2 = 3;
  }
  if (DAT_0203a4c8._2_2_ == 0x18) {
    DAT_0203a4c8._2_2_ = 0;
    DAT_0203a4cc._0_2_ = 1;
    DAT_0203a4cc._2_2_ = 2;
    _DAT_0203a4d0 = 3;
    _DAT_0203a4d2 = 4;
  }
  if (DAT_0203a4de == 0x18) {
    DAT_0203a4de = 0;
  }
  if (_DAT_0203a4dc == 0x18) {
    _DAT_0203a4dc = 0;
    DAT_0203a4de = 1;
  }
  if (DAT_0203a4d8._2_2_ == 0x18) {
    DAT_0203a4d8._2_2_ = 0;
    _DAT_0203a4dc = 1;
    DAT_0203a4de = 2;
  }
  if ((short)DAT_0203a4d8 == 0x18) {
    DAT_0203a4d8._0_2_ = 0;
    DAT_0203a4d8._2_2_ = 1;
    _DAT_0203a4dc = 2;
    DAT_0203a4de = 3;
  }
  if (DAT_0203a4d6 == 0x18) {
    DAT_0203a4d6 = 0;
    DAT_0203a4d8._0_2_ = 1;
    DAT_0203a4d8._2_2_ = 2;
    _DAT_0203a4dc = 3;
    DAT_0203a4de = 4;
  }
  if (_DAT_0203a4ea == 0x18) {
    _DAT_0203a4ea = 0;
  }
  if (_DAT_0203a4e8 == 0x18) {
    _DAT_0203a4e8 = 0;
    _DAT_0203a4ea = 1;
  }
  if (DAT_0203a4e6 == 0x18) {
    DAT_0203a4e6 = 0;
    _DAT_0203a4e8 = 1;
    _DAT_0203a4ea = 2;
  }
  if (_DAT_0203a4e4 == 0x18) {
    _DAT_0203a4e4 = 0;
    DAT_0203a4e6 = 1;
    _DAT_0203a4e8 = 2;
    _DAT_0203a4ea = 3;
  }
  if (DAT_0203a4e0._2_2_ == 0x18) {
    DAT_0203a4e0._2_2_ = 0;
    _DAT_0203a4e4 = 1;
    DAT_0203a4e6 = 2;
    _DAT_0203a4e8 = 3;
    _DAT_0203a4ea = 4;
  }
                    /* WARNING: Could not recover jumptable at 0x081429b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081429B4 @ 0x081429B4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081429B4(void)

{
  sub_080AA184(*(undefined4 *)
                (&DAT_08795060 + (uint)DAT_0203a4c6 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08795060 + (uint)_DAT_0203a4c4 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08795060 + (uint)DAT_0203a4c2 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08795060 + (uint)DAT_0203a4c0 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08795060 + (uint)DAT_0203a4be * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08795060 + (uint)DAT_0203a4bc * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08795de0 + (uint)_DAT_0203a4d2 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08795de0 + (uint)_DAT_0203a4d0 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08795de0 + (uint)DAT_0203a4cc._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3)
  ;
  sub_080AA184(*(undefined4 *)
                (&DAT_08795de0 + (uint)(ushort)DAT_0203a4cc * 0xc + (uint)DAT_0203b556 * 0x120),1,0,
               3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08795de0 + (uint)DAT_0203a4c8._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3)
  ;
  sub_080AA184(*(undefined4 *)
                (&DAT_08795de0 + (uint)(ushort)DAT_0203a4c8 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,
               3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08796b60 + (uint)DAT_0203a4de * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08796b60 + (uint)_DAT_0203a4dc * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08796b60 + (uint)DAT_0203a4d8._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3)
  ;
  sub_080AA184(*(undefined4 *)
                (&DAT_08796b60 + (uint)(ushort)DAT_0203a4d8 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,
               3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08796b60 + (uint)DAT_0203a4d6 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_08796b60 + (uint)_DAT_0203a4d4 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_087978e0 + (uint)_DAT_0203a4ea * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_087978e0 + (uint)_DAT_0203a4e8 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_087978e0 + (uint)DAT_0203a4e6 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_087978e0 + (uint)_DAT_0203a4e4 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3);
  sub_080AA184(*(undefined4 *)
                (&DAT_087978e0 + (uint)DAT_0203a4e0._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120),1,0,3)
  ;
  sub_080AA184(*(undefined4 *)
                (&DAT_087978e0 + (uint)(ushort)DAT_0203a4e0 * 0xc + (uint)DAT_0203b556 * 0x120),1,0,
               3);
  return;
}


// sub_08142F08 @ 0x08142F08

void sub_08142F08(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  byte *pbVar1;
  uint arg3_00;
  
  arg3_00 = arg3 & 0xffff;
  pbVar1 = (byte *)sub_080A9CC0(arg0);
  sub_080AA184(*(undefined4 *)((uint)*pbVar1 * 4 + 0x87986bc),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[1] * 4 + 0x87986bc),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[2] * 4 + 0x87986bc),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[3] * 4 + 0x87986bc),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[4] * 4 + 0x87986bc),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[5] * 4 + 0x87986bc),0,0,arg3_00);
  return;
}


// sub_08143008 @ 0x08143008

dword sub_08143008(int arg0)

{
  int iVar1;
  dword arg1;
  uint uVar2;
  
  arg1 = 10000;
  if (arg0 == 0) {
    arg1 = 0;
  }
  else {
    uVar2 = 0;
    do {
      iVar1 = __udivsi3(arg0,arg1);
      if (iVar1 != 0) {
        return arg1;
      }
      arg1 = __udivsi3(arg1,10);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 5);
  }
  return arg1;
}


// sub_08143044 @ 0x08143044

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08143044(void)

{
  if ((DAT_030031bc & 3) != 0) goto LAB_081431c6;
  if ((DAT_03003964 & 1) == 0) {
    DAT_0203a4a0 = 1;
  }
  else {
    DAT_0203a4a0 = sub_08143008(DAT_0203a494);
  }
  DAT_0203a494 = DAT_0203a494 + DAT_0203a4a0;
  if (DAT_0203a494 < DAT_0203a498) goto LAB_081431c6;
  DAT_0203a494 = DAT_0203a498;
  DAT_0203a49c = DAT_0203a490;
  if (DAT_0203a4a4._2_1_ != '\x01') {
    DAT_0203a4a4._0_1_ = '\0';
    DAT_0203a4a4._1_1_ = '\0';
    goto LAB_081431c6;
  }
  switch(_DAT_0203a530) {
  case 0:
    if (DAT_0203a4ba._1_1_ == '\x01') {
      DAT_0203a4ba._1_1_ = '\0';
LAB_0814318a:
      DAT_0203a48c._1_1_ = '\x01';
      DAT_0203a48c._0_1_ = 0;
    }
    break;
  case 1:
    if ((char)DAT_0203a4ba == '\x01') {
      DAT_0203a4ba._0_1_ = '\0';
      goto LAB_0814318a;
    }
    break;
  case 2:
    if (DAT_0203a4b8._1_1_ == '\x01') {
      DAT_0203a4b8._1_1_ = '\0';
      goto LAB_0814318a;
    }
    break;
  case 3:
    if ((char)DAT_0203a4b8 == '\x01') {
      DAT_0203a4b8._0_1_ = '\0';
      goto LAB_0814318a;
    }
    break;
  case 4:
    if (DAT_0203a4b6._1_1_ == '\x01') {
      DAT_0203a4b6._1_1_ = '\0';
      goto LAB_0814318a;
    }
    break;
  case 5:
    if ((char)DAT_0203a4b6 == '\x01') {
      DAT_0203a4b6._0_1_ = '\0';
      goto LAB_0814318a;
    }
    break;
  case 6:
    if (DAT_0203a4b5 == '\x01') {
      DAT_0203a4b5 = '\0';
      goto LAB_0814318a;
    }
    break;
  case 7:
    if (DAT_0203a4b4 == '\x01') {
      DAT_0203a4b4 = '\0';
      goto LAB_0814318a;
    }
  }
  if (DAT_0203a48c._1_1_ == '\0') {
    if ((char)DAT_0203a486 == '\0') {
      DAT_0203a4a4._0_1_ = DAT_0203a48c._1_1_;
      DAT_0203a4a4._1_1_ = DAT_0203a48c._1_1_;
    }
    else {
      DAT_0203a486._1_1_ = 1;
      DAT_0203a4a4._1_1_ = DAT_0203a48c._1_1_;
    }
  }
LAB_081431c6:
  if (99 < DAT_0203a494) {
    DAT_0203a4b4 = '\0';
    DAT_0203a4b5 = '\0';
    DAT_0203a4b6._0_1_ = '\0';
    DAT_0203a4b6._1_1_ = '\0';
    DAT_0203a4b8._0_1_ = '\0';
    DAT_0203a4b8._1_1_ = '\0';
    DAT_0203a4ba._0_1_ = '\0';
    DAT_0203a4ba._1_1_ = '\0';
  }
  return;
}


// sub_081431F8 @ 0x081431F8

void sub_081431F8(void)

{
  if (((DAT_030031bc & 3) == 0) && (100 < DAT_0203a4a4._1_1_)) {
    sub_080C51D4(0x159);
    if ((DAT_03003964 & 1) == 0) {
      DAT_0203a4a0 = 1;
    }
    else {
      DAT_0203a4a0 = sub_08143008(DAT_0203a494);
    }
    DAT_0203a494 = DAT_0203a494 - DAT_0203a4a0;
    DAT_0203a490 = DAT_0203a490 + DAT_0203a4a0;
    if (0 < DAT_0203a494) goto LAB_0814327a;
    DAT_0203a490 = DAT_0203a49c + DAT_0203a498;
    DAT_0203a494 = 0;
  }
  if (DAT_0203a494 == 0) {
    DAT_0203a490 = DAT_0203a49c + DAT_0203a498;
    DAT_0203a498 = DAT_0203a494;
    DAT_0203a458._0_1_ = 0;
  }
LAB_0814327a:
  if (DAT_0203a4a4._1_1_ < 0x6f) {
    DAT_0203a4a4._1_1_ = DAT_0203a4a4._1_1_ + 1;
  }
  return;
}


// sub_0814328C @ 0x0814328C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814328C(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  switch(DAT_0203a47c._3_1_) {
  case '\0':
    if (DAT_0203a45d == '\0') {
      DAT_0203a458._1_1_ = DAT_0203a458._1_1_ + '\x02';
    }
    if ((char)DAT_0203a45e == '\0') {
      DAT_0203a45a._0_1_ = (char)DAT_0203a45a + '\x02';
    }
    if (DAT_0203a45e._1_1_ == '\0') {
      DAT_0203a45a._1_1_ = DAT_0203a45a._1_1_ + '\x02';
    }
    if ((char)DAT_0203a460 == '\0') {
      DAT_0203a45c = DAT_0203a45c + 2;
    }
    if ((((DAT_0203a458._1_1_ == '(') || ((char)DAT_0203a45a == '(')) || (DAT_0203a45a._1_1_ == '(')
        ) || (DAT_0203a45c == 0x28)) {
      DAT_0203a47c._3_1_ = '\x01';
      DAT_0203a45c = 0;
      DAT_0203a45a._1_1_ = '\0';
      DAT_0203a45a._0_1_ = '\0';
      DAT_0203a458._1_1_ = '\0';
    }
    break;
  case '\x01':
    if (DAT_0203a45d == '\0') {
      DAT_0203a460._2_2_ = DAT_0203a460._2_2_ + 9;
      uVar1 = sub_080C2244();
      DAT_0203a488 = (undefined1)uVar1;
      uVar2 = __divsi3((uVar1 & 0xff) * 0x3b,0xff);
      DAT_0203a460._2_2_ = DAT_0203a460._2_2_ + (short)uVar2;
    }
    if ((char)DAT_0203a45e == '\0') {
      _DAT_0203a464 = _DAT_0203a464 + 9;
      uVar1 = sub_080C2244();
      DAT_0203a488 = (undefined1)uVar1;
      uVar2 = __divsi3((uVar1 & 0xff) * 0x3b,0xff);
      _DAT_0203a464 = _DAT_0203a464 + (short)uVar2;
    }
    if (DAT_0203a45e._1_1_ == '\0') {
      DAT_0203a466 = DAT_0203a466 + 9;
      uVar1 = sub_080C2244();
      DAT_0203a488 = (undefined1)uVar1;
      uVar2 = __divsi3((uVar1 & 0xff) * 0x3b,0xff);
      DAT_0203a466 = DAT_0203a466 + (short)uVar2;
    }
    if ((char)DAT_0203a460 == '\0') {
      _DAT_0203a468 = _DAT_0203a468 + 9;
      uVar1 = sub_080C2244();
      DAT_0203a488 = (undefined1)uVar1;
      uVar2 = __divsi3((uVar1 & 0xff) * 0x3b,0xff);
      _DAT_0203a468 = _DAT_0203a468 + (short)uVar2;
    }
    if (((char)DAT_0203a482 == '\x05') && (0x27 < _DAT_0203a480)) {
      DAT_0203a47c._3_1_ = '\x02';
      _DAT_0203a480 = 0;
    }
    _DAT_0203a480 = _DAT_0203a480 + 0x12;
    break;
  case '\x02':
    if (DAT_0203a45d == '\0') {
      DAT_0203a458._1_1_ = DAT_0203a458._1_1_ + '\x02';
    }
    if ((char)DAT_0203a45e == '\0') {
      _DAT_0203a464 = _DAT_0203a464 + 9;
    }
    if (DAT_0203a45e._1_1_ == '\0') {
      DAT_0203a466 = DAT_0203a466 + 9;
    }
    if ((char)DAT_0203a460 == '\0') {
      _DAT_0203a468 = _DAT_0203a468 + 9;
    }
    if ((DAT_0203a458._1_1_ == '<') || (DAT_0203a45d == '\x01')) {
      if (DAT_0203a45d == '\0') {
        sub_080C51D4(0x15b);
      }
      DAT_0203a47c._3_1_ = '\x03';
    }
    break;
  case '\x03':
    if ((char)DAT_0203a45e == '\0') {
      DAT_0203a45a._0_1_ = (char)DAT_0203a45a + '\x02';
    }
    if (DAT_0203a45e._1_1_ == '\0') {
      DAT_0203a466 = DAT_0203a466 + 9;
    }
    if ((char)DAT_0203a460 == '\0') {
      _DAT_0203a468 = _DAT_0203a468 + 9;
    }
    if (((char)DAT_0203a45a == '<') || ((char)DAT_0203a45e == '\x01')) {
      if ((char)DAT_0203a45e == '\0') {
        sub_080C51D4(0x15b);
      }
      DAT_0203a47c._3_1_ = '\x04';
    }
    break;
  case '\x04':
    if (DAT_0203a45e._1_1_ == '\0') {
      DAT_0203a45a._1_1_ = DAT_0203a45a._1_1_ + '\x02';
    }
    if ((char)DAT_0203a460 == '\0') {
      _DAT_0203a468 = _DAT_0203a468 + 9;
    }
    if ((DAT_0203a45a._1_1_ == '<') || (DAT_0203a45e._1_1_ == '\x01')) {
      if (DAT_0203a45e._1_1_ == '\0') {
        sub_080C51D4(0x15b);
      }
      DAT_0203a47c._3_1_ = '\x05';
    }
    break;
  case '\x05':
    if ((char)DAT_0203a460 == '\0') {
      DAT_0203a45c = DAT_0203a45c + 2;
    }
  }
  if (0x1de < DAT_0203a460._2_2_) {
    DAT_0203a460._2_2_ = 0;
  }
  if (0x1de < _DAT_0203a464) {
    _DAT_0203a464 = 0;
  }
  if (0x1de < DAT_0203a466) {
    DAT_0203a466 = 0;
  }
  if (0x1de < _DAT_0203a468) {
    _DAT_0203a468 = 0;
  }
  if (0x114 < _DAT_0203a480) {
    _DAT_0203a480 = 0;
    DAT_0203a482._0_1_ = (char)DAT_0203a482 + '\x01';
  }
  if ((DAT_0203a47c._3_1_ == '\x05') && ((0x3b < DAT_0203a45c || ((char)DAT_0203a460 == '\x01')))) {
    if ((char)DAT_0203a460 == '\0') {
      sub_080C51D4(0x15b);
    }
    DAT_0203a458._0_1_ = 2;
    _DAT_0203a480 = 0;
    DAT_0203a482._0_1_ = '\0';
    if (DAT_0203a45d == '\0') {
      DAT_0203a4bc = DAT_0203a4c2;
      DAT_0203a4be = _DAT_0203a4c4;
      DAT_0203a4c0 = DAT_0203a4c6;
    }
    if ((char)DAT_0203a45e == '\0') {
      DAT_0203a4c8._0_2_ = DAT_0203a4cc._2_2_;
      DAT_0203a4c8._2_2_ = _DAT_0203a4d0;
      DAT_0203a4cc._0_2_ = _DAT_0203a4d2;
    }
    if (DAT_0203a45e._1_1_ == '\0') {
      _DAT_0203a4d4 = DAT_0203a4d8._2_2_;
      DAT_0203a4d6 = _DAT_0203a4dc;
      DAT_0203a4d8._0_2_ = DAT_0203a4de;
    }
    if ((char)DAT_0203a460 == '\0') {
      DAT_0203a4e0._0_2_ = DAT_0203a4e6;
      DAT_0203a4e0._2_2_ = _DAT_0203a4e8;
      _DAT_0203a4e4 = _DAT_0203a4ea;
    }
    DAT_0203a45c = 0;
    DAT_0203a45a._1_1_ = '\0';
    DAT_0203a45a._0_1_ = '\0';
    DAT_0203a458._1_1_ = '\0';
    if ((char)DAT_0203a47c == '\x01') {
      DAT_0203a47c._0_1_ = '\0';
      DAT_0203a47c._1_1_ = 0;
      DAT_0203a460._0_1_ = '\0';
      DAT_0203a45e._1_1_ = '\0';
      DAT_0203a45e._0_1_ = '\0';
      DAT_0203a45d = '\0';
    }
  }
  return;
}


// sub_08143610 @ 0x08143610

void sub_08143610(void)

{
  if (DAT_0203a4a8 < 3) {
    if (7 < DAT_0203a4a9) {
      sub_08143668();
    }
    if (10 < DAT_0203a4a9) {
      DAT_0203a4a9 = 0;
      DAT_0203a4a8 = DAT_0203a4a8 + 1;
    }
    DAT_0203a4a9 = DAT_0203a4a9 + 1;
  }
  else {
    DAT_0203a4a9 = '\0';
    DAT_0203a4a4._3_1_ = 0;
    DAT_0203a4a8 = 0;
    DAT_0203a4a4._2_1_ = 1;
    DAT_0203a458._0_1_ = 3;
  }
  return;
}


// sub_08143668 @ 0x08143668

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08143668(void)

{
  sub_080AA184(*(undefined4 *)(&DAT_08795064 + DAT_0203a504 * 0xc + (uint)DAT_0203b556 * 0x120),
               (uint)(byte)DAT_0203a508,0,3);
  sub_080AA184(*(undefined4 *)(&DAT_08795de4 + _DAT_0203a510 * 0xc + (uint)DAT_0203b556 * 0x120),
               (uint)(byte)DAT_0203a514,0,3);
  sub_080AA184(*(undefined4 *)(&DAT_08796b64 + _DAT_0203a51c * 0xc + (uint)DAT_0203b556 * 0x120),
               (uint)(byte)DAT_0203a520,0,3);
  sub_080AA184(*(undefined4 *)(&DAT_087978e4 + _DAT_0203a528 * 0xc + (uint)DAT_0203b556 * 0x120),
               (uint)(byte)DAT_0203a52c,0,3);
  sub_080AA184(*(undefined4 *)(_DAT_0203a530 * 0xc + 0x879865c),0,0,0);
  switch(_DAT_0203a530) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    sub_080C51D4(0x15d);
    break;
  case 6:
    sub_080C51D4(0x15e);
    break;
  case 7:
    sub_080C51D4(0x15e);
  }
  return;
}


// sub_081437E4 @ 0x081437E4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081437E4(void)

{
  undefined4 arg0;
  
  _DAT_0203a46c = *(int *)((uint)DAT_0203a4be * 0xc + (uint)DAT_0203b556 * 0x120 + 0x879505c);
  _DAT_0203a470 = *(int *)((uint)DAT_0203a4c8._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8795ddc);
  _DAT_0203a474 = *(int *)((uint)DAT_0203a4d6 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8796b5c);
  DAT_0203a478 = *(int *)((uint)DAT_0203a4e0._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87978dc);
  if (_DAT_0203a46c == _DAT_0203a470) {
    if ((_DAT_0203a46c == _DAT_0203a474) && (_DAT_0203a46c == DAT_0203a478)) {
      if (_DAT_0203a46c - 8U < 3) {
        DAT_0203a458._0_1_ = 3;
        return;
      }
      DAT_0203a504 = (uint)DAT_0203a4be;
      _DAT_0203a510 = (uint)DAT_0203a4c8._2_2_;
      _DAT_0203a51c = (uint)DAT_0203a4d6;
      _DAT_0203a528 = (uint)DAT_0203a4e0._2_2_;
      DAT_0203a508._0_1_ = 0;
      DAT_0203a514._0_1_ = 0;
      DAT_0203a520._0_1_ = 0;
      DAT_0203a52c._0_1_ = 0;
      arg0 = 1;
      _DAT_0203a530 = _DAT_0203a46c;
      goto LAB_08143a42;
    }
    if (_DAT_0203a46c != _DAT_0203a470) goto LAB_08143992;
    if (_DAT_0203a46c == _DAT_0203a474) {
      if (_DAT_0203a46c - 8U < 3) {
        DAT_0203a458._0_1_ = 3;
        return;
      }
      DAT_0203a504 = (uint)DAT_0203a4be;
      _DAT_0203a510 = (uint)DAT_0203a4c8._2_2_;
      _DAT_0203a51c = (uint)DAT_0203a4d6;
      DAT_0203a508._0_1_ = 0;
      DAT_0203a514._0_1_ = 0;
      DAT_0203a520._0_1_ = 0;
      DAT_0203a52c._0_1_ = 2;
      _DAT_0203a530 = _DAT_0203a46c;
    }
    else {
      if (_DAT_0203a46c != DAT_0203a478) goto LAB_08143992;
      if (_DAT_0203a46c - 8U < 3) {
        DAT_0203a458._0_1_ = 3;
        return;
      }
      DAT_0203a504 = (uint)DAT_0203a4be;
      _DAT_0203a510 = (uint)DAT_0203a4c8._2_2_;
      _DAT_0203a528 = (uint)DAT_0203a4e0._2_2_;
      DAT_0203a508._0_1_ = 0;
      DAT_0203a514._0_1_ = 0;
      DAT_0203a52c._0_1_ = 0;
      DAT_0203a520._0_1_ = 2;
      _DAT_0203a530 = _DAT_0203a46c;
    }
  }
  else {
LAB_08143992:
    if ((_DAT_0203a46c == _DAT_0203a474) && (_DAT_0203a474 == DAT_0203a478)) {
      if (_DAT_0203a474 - 8U < 3) {
        DAT_0203a458._0_1_ = 3;
        return;
      }
      DAT_0203a504 = (uint)DAT_0203a4be;
      _DAT_0203a51c = (uint)DAT_0203a4d6;
      _DAT_0203a528 = (uint)DAT_0203a4e0._2_2_;
      DAT_0203a508._0_1_ = 0;
      DAT_0203a520._0_1_ = 0;
      DAT_0203a52c._0_1_ = 0;
      DAT_0203a514._0_1_ = 2;
      _DAT_0203a530 = _DAT_0203a46c;
    }
    else {
      if ((_DAT_0203a470 != _DAT_0203a474) || (_DAT_0203a470 != DAT_0203a478)) {
        DAT_0203a458._0_1_ = 3;
        return;
      }
      if (_DAT_0203a470 - 8U < 3) {
        DAT_0203a458._0_1_ = 3;
        return;
      }
      _DAT_0203a510 = (uint)DAT_0203a4c8._2_2_;
      _DAT_0203a51c = (uint)DAT_0203a4d6;
      _DAT_0203a528 = (uint)DAT_0203a4e0._2_2_;
      DAT_0203a514._0_1_ = 0;
      DAT_0203a520._0_1_ = 0;
      DAT_0203a52c._0_1_ = 0;
      DAT_0203a508._0_1_ = 2;
      _DAT_0203a530 = _DAT_0203a470;
    }
  }
  arg0 = 0;
LAB_08143a42:
  sub_08143EA0(arg0);
  sub_08143610();
  return;
}


// sub_08143A68 @ 0x08143A68

void sub_08143A68(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  DAT_0203a482._1_1_ = 1;
  uVar3 = 0;
  do {
    iVar2 = uVar3 * 2;
    uVar1 = *(uint *)((uint)(ushort)(&DAT_0203a4bc)[uVar3] * 0xc + (uint)DAT_0203b556 * 0x120 +
                     0x879505c);
    if (uVar1 == 9) {
      DAT_0203a484 = DAT_0203a484 + '\x02';
    }
    else if (uVar1 < 10) {
      if (uVar1 == 8) {
        DAT_0203a484 = DAT_0203a484 + '\x01';
      }
    }
    else if (uVar1 == 10) {
      DAT_0203a484 = DAT_0203a484 + '\x03';
    }
    uVar1 = *(uint *)((uint)*(ushort *)((int)&DAT_0203a4c8 + iVar2) * 0xc +
                      (uint)DAT_0203b556 * 0x120 + 0x8795ddc);
    if (uVar1 == 9) {
      DAT_0203a484 = DAT_0203a484 + '\x02';
    }
    else if (uVar1 < 10) {
      if (uVar1 == 8) {
        DAT_0203a484 = DAT_0203a484 + '\x01';
      }
    }
    else if (uVar1 == 10) {
      DAT_0203a484 = DAT_0203a484 + '\x03';
    }
    uVar1 = *(uint *)((uint)*(ushort *)(&DAT_0203a4d4 + iVar2) * 0xc + (uint)DAT_0203b556 * 0x120 +
                     0x8796b5c);
    if (uVar1 == 9) {
      DAT_0203a484 = DAT_0203a484 + '\x02';
    }
    else if (uVar1 < 10) {
      if (uVar1 == 8) {
        DAT_0203a484 = DAT_0203a484 + '\x01';
      }
    }
    else if (uVar1 == 10) {
      DAT_0203a484 = DAT_0203a484 + '\x03';
    }
    uVar1 = *(uint *)((uint)*(ushort *)((int)&DAT_0203a4e0 + iVar2) * 0xc +
                      (uint)DAT_0203b556 * 0x120 + 0x87978dc);
    if (uVar1 == 9) {
      DAT_0203a484 = DAT_0203a484 + '\x02';
    }
    else if (uVar1 < 10) {
      if (uVar1 == 8) {
        DAT_0203a484 = DAT_0203a484 + '\x01';
      }
    }
    else if (uVar1 == 10) {
      DAT_0203a484 = DAT_0203a484 + '\x03';
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 3);
  uVar3 = 0;
  do {
    (&DAT_0203a4ec)[uVar3] = 0;
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 0xd);
  DAT_0203a4f8._1_1_ = DAT_0203a484;
  return;
}


// sub_08143BF8 @ 0x08143BF8

void sub_08143BF8(void)

{
  uint uVar1;
  
  if (DAT_0203a4f8._3_1_ == '\0') {
    if (7 < DAT_0203a4fc) {
      (&DAT_0203a4ec)[DAT_0203a4f8._2_1_] = 1;
      DAT_0203a4fc = 0;
      DAT_0203a4f8._2_1_ = DAT_0203a4f8._2_1_ + 1;
      if (DAT_0203a4f8._1_1_ == '\0') {
        sub_080C51D4(0x16b);
        DAT_0203a4f8._2_1_ = 0;
        DAT_0203a4f8._3_1_ = '\x01';
      }
      else {
        sub_080C51D4(0x16b);
        DAT_0203a4f8._1_1_ = DAT_0203a4f8._1_1_ + -1;
      }
    }
    DAT_0203a4fc = DAT_0203a4fc + 1;
  }
  uVar1 = 0;
  do {
    if ((&DAT_0203a4ec)[uVar1] == '\x01') {
      sub_080AA184(*(undefined4 *)(uVar1 * 8 + 0x87986e4),0,0,0);
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0xd);
  return;
}


// sub_08143CB8 @ 0x08143CB8

void sub_08143CB8(void)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  
  bVar2 = (byte)DAT_0203a48c;
  bVar1 = (byte)DAT_0203a486;
  switch(DAT_0203a484) {
  case 0:
  case 1:
  case 2:
    break;
  case 3:
    if (DAT_0203a48a == 2) {
      if (DAT_0203a4a8 < 4) {
        if (7 < DAT_0203a4a9) {
          sub_080AA184(0x814f314,0,0,0);
        }
        if (DAT_0203a4a9 < 0xb) goto LAB_08143e50;
        DAT_0203a4a9 = 0;
        goto LAB_08143dea;
      }
      DAT_0203a4a8 = 0;
      DAT_0203a48a = 3;
    }
    else if (DAT_0203a48a == 3) {
      if (DAT_0203a4a8 < 4) {
        if (7 < DAT_0203a4a9) {
          sub_080AA184(0x814f344,0,0,0);
        }
        if (DAT_0203a4a9 < 0xb) goto LAB_08143e50;
        DAT_0203a4a9 = 0;
LAB_08143dea:
        DAT_0203a4a8 = DAT_0203a4a8 + 1;
LAB_08143e50:
        DAT_0203a4a9 = DAT_0203a4a9 + 1;
        return;
      }
      DAT_0203a4a8 = 0;
      DAT_0203a48a = 4;
    }
    else {
      puVar3 = &DAT_0203a48c;
      if (((byte)DAT_0203a48c == 0) && (DAT_0203a48a == 4)) {
        if (3 < DAT_0203a4a8) {
          DAT_0203a4a8 = (byte)DAT_0203a48c;
          DAT_0203a48a = 5;
          goto LAB_08143e5e;
        }
        if (7 < DAT_0203a4a9) {
          sub_080AA184(0x814f374,0,0,0);
        }
        if (DAT_0203a4a9 < 0xb) goto LAB_08143e50;
        DAT_0203a4a9 = bVar2;
        goto LAB_08143dea;
      }
    }
    break;
  case 4:
  case 5:
    DAT_0203a47c._0_1_ = 1;
    DAT_0203a485 = 1;
    return;
  case 6:
    puVar3 = (undefined4 *)&DAT_0203a486;
    if ((byte)DAT_0203a486 == 0) {
      if (3 < DAT_0203a4a8) {
        DAT_0203a4a8 = (byte)DAT_0203a486;
LAB_08143e5e:
        *(undefined1 *)puVar3 = 1;
        DAT_0203a485 = 1;
        return;
      }
      if (7 < DAT_0203a4a9) {
        sub_080AA184(0x814f29c,0,0,0);
      }
      if (10 < DAT_0203a4a9) {
        DAT_0203a4a9 = bVar1;
        DAT_0203a4a8 = DAT_0203a4a8 + 1;
      }
      goto LAB_08143e50;
    }
    break;
  case 7:
  case 8:
    if ((char)DAT_0203a4aa == '\0') {
      sub_08144018();
    }
    sub_081443F0();
    return;
  case 9:
    DAT_0203a498 = 5;
    break;
  case 10:
    DAT_0203a498 = 10;
    break;
  case 0xb:
    DAT_0203a498 = 0x14;
    break;
  case 0xc:
    DAT_0203a498 = 100;
    break;
  default:
    goto switchD_08143cd2_default;
  }
  DAT_0203a485 = 1;
switchD_08143cd2_default:
  return;
}


// sub_08143EA0 @ 0x08143EA0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08143EA0(uint arg0)

{
  DAT_0203a498 = (uint)*(ushort *)(&DAT_08798664 + (arg0 & 0xffff) * 2 + _DAT_0203a530 * 0xc);
  return;
}


// sub_08143ED0 @ 0x08143ED0

void sub_08143ED0(void)

{
  if (DAT_0203a45d == '\x01') {
    sub_080AA184(0x814f1f4,0,0,0);
  }
  if ((char)DAT_0203a45e == '\x01') {
    sub_080AA184(0x814f204,0,0,0);
  }
  if (DAT_0203a45e._1_1_ == '\x01') {
    sub_080AA184(0x814f214,0,0,0);
  }
  if ((char)DAT_0203a460 == '\x01') {
    sub_080AA184(0x814f224,0,0,0);
  }
  if (((char)DAT_0203a458 == '\0') && (DAT_0203a47c._1_1_ < 3)) {
    if ((DAT_0203a45d == '\0') && (10 < DAT_0203a47c._2_1_)) {
      sub_080AA184(0x814f1f4,0,0,0);
    }
    if (((char)DAT_0203a45e == '\0') && (10 < DAT_0203a47c._2_1_)) {
      sub_080AA184(0x814f204,0,0,0);
    }
    if ((DAT_0203a45e._1_1_ == '\0') && (10 < DAT_0203a47c._2_1_)) {
      sub_080AA184(0x814f214,0,0,0);
    }
    if (((char)DAT_0203a460 == '\0') && (10 < DAT_0203a47c._2_1_)) {
      sub_080AA184(0x814f224,0,0,0);
    }
    if (0x14 < DAT_0203a47c._2_1_) {
      DAT_0203a47c._2_1_ = 0;
    }
    DAT_0203a47c._2_1_ = DAT_0203a47c._2_1_ + 1;
  }
  return;
}


// sub_08144018 @ 0x08144018

void sub_08144018(void)

{
  undefined2 *puVar1;
  
  DAT_0203a4aa._0_1_ = 1;
  switch(*(undefined4 *)((uint)DAT_0203a4be * 0xc + (uint)DAT_0203b556 * 0x120 + 0x879505c)) {
  case 0:
    puVar1 = (undefined2 *)((int)&DAT_0203a4ba + 1);
    break;
  case 1:
    puVar1 = &DAT_0203a4ba;
    break;
  case 2:
    puVar1 = (undefined2 *)((int)&DAT_0203a4b8 + 1);
    break;
  case 3:
    puVar1 = &DAT_0203a4b8;
    goto LAB_081440ba;
  case 4:
    puVar1 = (undefined2 *)((int)&DAT_0203a4b6 + 1);
    break;
  case 5:
    puVar1 = &DAT_0203a4b6;
    break;
  case 6:
    puVar1 = (undefined2 *)&DAT_0203a4b5;
    break;
  case 7:
    puVar1 = (undefined2 *)&DAT_0203a4b4;
LAB_081440ba:
    *(undefined1 *)puVar1 = 1;
    *(undefined1 *)(puVar1 + -4) = 1;
  default:
    goto switchD_08144050_default;
  }
  *(undefined1 *)puVar1 = 1;
  *(undefined1 *)(puVar1 + -4) = 1;
switchD_08144050_default:
  switch(*(undefined4 *)((uint)DAT_0203a4c8._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8795ddc)) {
  case 0:
    puVar1 = (undefined2 *)((int)&DAT_0203a4ba + 1);
    break;
  case 1:
    puVar1 = &DAT_0203a4ba;
    break;
  case 2:
    puVar1 = (undefined2 *)((int)&DAT_0203a4b8 + 1);
    break;
  case 3:
    puVar1 = &DAT_0203a4b8;
    goto LAB_0814414a;
  case 4:
    puVar1 = (undefined2 *)((int)&DAT_0203a4b6 + 1);
    break;
  case 5:
    puVar1 = &DAT_0203a4b6;
    break;
  case 6:
    puVar1 = (undefined2 *)&DAT_0203a4b5;
    break;
  case 7:
    puVar1 = (undefined2 *)&DAT_0203a4b4;
LAB_0814414a:
    *(undefined1 *)puVar1 = 1;
    *(undefined1 *)(puVar1 + -4) = 1;
  default:
    goto switchD_081440ea_default;
  }
  *(undefined1 *)puVar1 = 1;
  *(undefined1 *)(puVar1 + -4) = 1;
switchD_081440ea_default:
  switch(*(undefined4 *)((uint)DAT_0203a4d6 * 0xc + (uint)DAT_0203b556 * 0x120 + 0x8796b5c)) {
  case 0:
    puVar1 = (undefined2 *)((int)&DAT_0203a4ba + 1);
    break;
  case 1:
    puVar1 = &DAT_0203a4ba;
    break;
  case 2:
    puVar1 = (undefined2 *)((int)&DAT_0203a4b8 + 1);
    break;
  case 3:
    puVar1 = &DAT_0203a4b8;
    goto LAB_081441da;
  case 4:
    puVar1 = (undefined2 *)((int)&DAT_0203a4b6 + 1);
    break;
  case 5:
    puVar1 = &DAT_0203a4b6;
    break;
  case 6:
    puVar1 = (undefined2 *)&DAT_0203a4b5;
    break;
  case 7:
    puVar1 = (undefined2 *)&DAT_0203a4b4;
LAB_081441da:
    *(undefined1 *)puVar1 = 1;
    *(undefined1 *)(puVar1 + -4) = 1;
  default:
    goto switchD_0814417a_default;
  }
  *(undefined1 *)puVar1 = 1;
  *(undefined1 *)(puVar1 + -4) = 1;
switchD_0814417a_default:
  switch(*(undefined4 *)((uint)DAT_0203a4e0._2_2_ * 0xc + (uint)DAT_0203b556 * 0x120 + 0x87978dc)) {
  case 0:
    puVar1 = (undefined2 *)((int)&DAT_0203a4ba + 1);
    break;
  case 1:
    puVar1 = &DAT_0203a4ba;
    break;
  case 2:
    puVar1 = (undefined2 *)((int)&DAT_0203a4b8 + 1);
    break;
  case 3:
    puVar1 = &DAT_0203a4b8;
    break;
  case 4:
    puVar1 = (undefined2 *)((int)&DAT_0203a4b6 + 1);
    break;
  case 5:
    puVar1 = &DAT_0203a4b6;
    break;
  case 6:
    puVar1 = (undefined2 *)&DAT_0203a4b5;
    break;
  case 7:
    puVar1 = (undefined2 *)&DAT_0203a4b4;
    break;
  default:
    goto switchD_0814420a_default;
  }
  *(undefined1 *)puVar1 = 1;
  *(undefined1 *)(puVar1 + -4) = 1;
switchD_0814420a_default:
  return;
}


// sub_08144270 @ 0x08144270

void sub_08144270(void)

{
  if ((DAT_0203a4b4 == '\x01') && ((char)DAT_0203a4ac == '\0')) {
    sub_080AA184(0x814f10c,0,0,0);
  }
  if ((DAT_0203a4b5 == '\x01') && (DAT_0203a4ac._1_1_ == '\0')) {
    sub_080AA184(0x814f124,0,0,0);
  }
  if (((char)DAT_0203a4b6 == '\x01') && ((char)DAT_0203a4ae == '\0')) {
    sub_080AA184(0x814f13c,0,0,0);
  }
  if ((DAT_0203a4b6._1_1_ == '\x01') && (DAT_0203a4ae._1_1_ == '\0')) {
    sub_080AA184(0x814f154,0,0,0);
  }
  if (((char)DAT_0203a4b8 == '\x01') && (DAT_0203a4b0 == '\0')) {
    sub_080AA184(0x814f16c,0,0,0);
  }
  if ((DAT_0203a4b8._1_1_ == '\x01') && (DAT_0203a4b1 == '\0')) {
    sub_080AA184(0x814f184,0,0,0);
  }
  if (((char)DAT_0203a4ba == '\x01') && (DAT_0203a4b2 == '\0')) {
    sub_080AA184(0x814f19c,0,0,0);
  }
  if ((DAT_0203a4ba._1_1_ == '\x01') && (DAT_0203a4b3 == '\0')) {
    sub_080AA184(0x814f1b4,0,0,0);
  }
  return;
}


// sub_081443F0 @ 0x081443F0

void sub_081443F0(void)

{
  if (DAT_0203a4a8 < 4) {
    if (((char)DAT_0203a4ac == '\x01') && (7 < DAT_0203a4a9)) {
      sub_080AA184(0x814f10c,0,0,0);
    }
    if ((DAT_0203a4ac._1_1_ == '\x01') && (7 < DAT_0203a4a9)) {
      sub_080AA184(0x814f124,0,0,0);
    }
    if (((char)DAT_0203a4ae == '\x01') && (7 < DAT_0203a4a9)) {
      sub_080AA184(0x814f13c,0,0,0);
    }
    if ((DAT_0203a4ae._1_1_ == '\x01') && (7 < DAT_0203a4a9)) {
      sub_080AA184(0x814f154,0,0,0);
    }
    if ((DAT_0203a4b0 == '\x01') && (7 < DAT_0203a4a9)) {
      sub_080AA184(0x814f16c,0,0,0);
    }
    if ((DAT_0203a4b1 == '\x01') && (7 < DAT_0203a4a9)) {
      sub_080AA184(0x814f184,0,0,0);
    }
    if ((DAT_0203a4b2 == '\x01') && (7 < DAT_0203a4a9)) {
      sub_080AA184(0x814f19c,0,0,0);
    }
    if ((DAT_0203a4b3 == '\x01') && (7 < DAT_0203a4a9)) {
      sub_080AA184(0x814f1b4,0,0,0);
    }
    if (10 < DAT_0203a4a9) {
      DAT_0203a4a9 = 0;
      DAT_0203a4a8 = DAT_0203a4a8 + 1;
    }
    DAT_0203a4a9 = DAT_0203a4a9 + 1;
  }
  else {
    sub_080C51D4(0x15d);
    DAT_0203a4b3 = '\0';
    DAT_0203a4b2 = '\0';
    DAT_0203a4b1 = '\0';
    DAT_0203a4b0 = '\0';
    DAT_0203a4ae._1_1_ = '\0';
    DAT_0203a4ae._0_1_ = '\0';
    DAT_0203a4ac._1_1_ = '\0';
    DAT_0203a4ac._0_1_ = '\0';
    DAT_0203a4a8 = 0;
    DAT_0203a485 = 1;
  }
  return;
}


// sub_081445C4 @ 0x081445C4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081445C4(void)

{
  dword dVar1;
  
  if (DAT_0203a48c._1_1_ != '\x01') goto LAB_0814476a;
  if (3 < DAT_0203a4a8) {
    DAT_0203a498 = (uint)DAT_0203a48a * DAT_0203a498;
    DAT_0203a48a = 2;
    DAT_0203a48c._1_1_ = '\0';
    DAT_0203a4a8 = 0;
    goto LAB_0814476a;
  }
  if (DAT_0203a4a9 < 8) goto LAB_08144738;
  switch(_DAT_0203a530) {
  case 0:
    dVar1 = 0x814f1b4;
    break;
  case 1:
    dVar1 = 0x814f19c;
    break;
  case 2:
    dVar1 = 0x814f184;
    break;
  case 3:
    dVar1 = 0x814f16c;
    break;
  case 4:
    dVar1 = 0x814f154;
    break;
  case 5:
    dVar1 = 0x814f13c;
    break;
  case 6:
    dVar1 = 0x814f124;
    break;
  case 7:
    sub_080AA184(0x814f10c,0,0,0);
  default:
    goto switchD_08144602_default;
  }
  sub_080AA184(dVar1,0,0,0);
switchD_08144602_default:
  if (DAT_0203a48a == 3) {
    dVar1 = 0x814f314;
LAB_08144702:
    sub_080AA184(dVar1,0,0,0);
  }
  else if (DAT_0203a48a < 4) {
    if (DAT_0203a48a == 2) {
      dVar1 = 0x814f2e4;
      goto LAB_08144702;
    }
  }
  else {
    if (DAT_0203a48a == 4) {
      dVar1 = 0x814f344;
      goto LAB_08144702;
    }
    if (DAT_0203a48a == 5) {
      sub_080AA184(0x814f374,0,0,0);
    }
  }
LAB_08144738:
  if (10 < DAT_0203a4a9) {
    DAT_0203a4a9 = 0;
    DAT_0203a4a8 = DAT_0203a4a8 + 1;
  }
  DAT_0203a4a9 = DAT_0203a4a9 + 1;
LAB_0814476a:
  if (DAT_0203a486._1_1_ == '\x01') {
    if (DAT_0203a4a8 < 4) {
      if (7 < DAT_0203a4a9) {
        sub_080AA184(0x814f29c,0,0,0);
      }
      if (10 < DAT_0203a4a9) {
        DAT_0203a4a9 = 0;
        DAT_0203a4a8 = DAT_0203a4a8 + 1;
      }
      DAT_0203a4a9 = DAT_0203a4a9 + 1;
    }
    else {
      DAT_0203a486._1_1_ = '\0';
      DAT_0203a486._0_1_ = 0;
      DAT_0203a498 = DAT_0203a498 << 1;
      DAT_0203a4a8 = 0;
    }
  }
  return;
}


// sub_081447D8 @ 0x081447D8

void sub_081447D8(undefined4 arg0,undefined4 arg1)

{
  DAT_0203a454 = (undefined2)arg1;
  return;
}


// sub_081447E4 @ 0x081447E4

void sub_081447E4(uint arg0,undefined4 arg1,undefined4 arg2)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xffff;
  if (*(short *)(&DAT_0203a540 + uVar1 * 2) != 0) {
    sub_080AA184(*(undefined4 *)
                  ((uint)*(ushort *)(&DAT_0203a540 + uVar1 * 2) * 4 +
                  *(int *)(uVar1 * 4 + 0x879a264)),1,0,0);
  }
  return;
}


// sub_08144868 @ 0x08144868

void sub_08144868(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  
  iVar1 = (arg0 & 0xffff) * 2;
  *(undefined2 *)(&DAT_0203a540 + iVar1) = (undefined2)arg1;
  if ((short)arg2 != 0) {
    *(short *)(&DAT_0203a568 + iVar1) = (short)arg2;
  }
  if ((short)arg3 != 0) {
    *(short *)(&DAT_0203a590 + iVar1) = (short)arg3;
  }
  return;
}


// sub_081448A8 @ 0x081448A8

void sub_081448A8(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  
  iVar1 = (arg0 & 0xffff) * 2;
  *(undefined2 *)(&DAT_0203a540 + iVar1) = (undefined2)arg1;
  *(undefined2 *)(&DAT_0203a568 + iVar1) = (undefined2)arg2;
  *(undefined2 *)(&DAT_0203a590 + iVar1) = (undefined2)arg3;
  return;
}


// sub_081448D8 @ 0x081448D8

void sub_081448D8(undefined4 arg0,uint arg1,uint arg2,uint arg3)

{
  uint in_stack_00000000;
  
  sub_08144868(arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff,in_stack_00000000 & 0xffff);
  return;
}


// sub_081448FC @ 0x081448FC

void sub_081448FC(undefined4 arg0,uint arg1,uint arg2,uint arg3)

{
  uint in_stack_00000000;
  
  sub_081448A8(arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff,in_stack_00000000 & 0xffff);
  return;
}


// sub_08144920 @ 0x08144920

void sub_08144920(undefined4 arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = arg1 & 0xffff;
  iVar1 = sub_080A9CC0(arg0);
  uVar3 = 0;
  uVar2 = uVar4;
  if (uVar4 != 0) {
    do {
      uVar2 = uVar2 - 1 & 0xff;
      sub_080AA184(*(undefined4 *)((uint)*(byte *)(iVar1 + uVar2) * 4 + 0x879a29c),1,0,0);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  return;
}


// sub_08144998 @ 0x08144998

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08144998(void)

{
  undefined4 arg0;
  uint uVar1;
  undefined4 *puVar2;
  
  if ((_DAT_0203a4ec != 0) &&
     (((_DAT_0203a4ea == 0 || ((DAT_030031bc >> 4 & 1) == 0)) && (uVar1 = 0, _DAT_0203a4ec != 0))))
  {
    puVar2 = (undefined4 *)0x879a2e4;
    do {
      arg0 = *puVar2;
      puVar2 = puVar2 + 1;
      sub_080AA184(arg0,1,0,0);
      uVar1 = uVar1 + 1;
    } while (uVar1 < _DAT_0203a4ec);
  }
  return;
}


// sub_08144A08 @ 0x08144A08

void sub_08144A08(uint arg0)

{
  int iVar1;
  
  iVar1 = (arg0 & 0xffff) * 4;
  *(undefined4 *)(&DAT_0203a4c4 + iVar1) =
       *(undefined4 *)(iVar1 + (uint)DAT_0203b556 * 0x24 + 0x879c6a4);
  iVar1 = sub_080C2244();
  *(uint *)(&DAT_0203a458 + (arg0 & 0xffff) * 2) = ((uint)(iVar1 * 0x18) >> 8) * 0x140000;
  return;
}


// sub_08144A58 @ 0x08144A58

void sub_08144A58(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_14;
  undefined4 local_10;
  
  uVar2 = 0;
  local_14 = 0;
  CpuSet(&local_14,0x203a454,0x5000200);
  REG_BG0CNT = 0x4008;
  DAT_03000002 = 0;
  DAT_03000040 = 0;
  local_10 = 0;
  REG_DMA3SAD = &local_10;
  REG_DMA3DAD = 0x2005004;
  REG_DMA3CNT = 0x85000800;
  uVar1 = REG_DMA3CNT;
  DAT_0203a454 = 1;
  sub_08144868(0,0,0,0);
  sub_08144868(1,0,0,0);
  sub_08144868(2,1,0,0);
  sub_08144868(3,1,0,0);
  sub_08144868(5,0,0,0);
  sub_08144868(6,0,0,0);
  sub_08144868(7,0,0,0);
  sub_08144868(8,0,0,0);
  sub_08144868(4,0,0,0);
  sub_08144868(10,0,0,0);
  sub_08144868(0xb,0,0,0);
  sub_08144868(0xc,0,0,0);
  sub_08144868(0xd,0,0,0);
  sub_08144868(9,0,0,0);
  do {
    sub_08144A08(uVar2 & 0xffff);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 9);
  return;
}


// sub_08144B70 @ 0x08144B70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08144B70(void)

{
  sub_08144FF0(0,(int)DAT_0203a45a,_DAT_0203a4c4);
  sub_08144FF0(1,(int)DAT_0203a45e,DAT_0203a4c8);
  sub_08144FF0(2,(int)DAT_0203a460._2_2_,DAT_0203a4cc);
  sub_08144FF0(3,(int)DAT_0203a466,_DAT_0203a4d0);
  sub_08144FF0(4,(int)DAT_0203a46a,_DAT_0203a4d4);
  sub_08144FF0(5,(int)DAT_0203a46e,DAT_0203a4d8);
  sub_08144FF0(6,(int)DAT_0203a472,_DAT_0203a4dc);
  sub_08144FF0(7,(int)DAT_0203a476,DAT_0203a4e0);
  sub_08144FF0(8,(int)DAT_0203a478._2_2_,_DAT_0203a4e4);
  return;
}


// sub_08144C00 @ 0x08144C00

void sub_08144C00(void)

{
  sub_08144B70();
  return;
}


// sub_08144C0C @ 0x08144C0C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08144C0C(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = _DAT_0203a4e8;
  if (DAT_0203a454 == 1) {
    sub_080AD0FC(0x879a304,0xffff);
    DAT_0203a454 = 0;
  }
  else if ((1 < DAT_0203a454) && (DAT_0203a454 == 2)) {
    if (((DAT_03003964 & 1) == 0) || (_DAT_0203a4e8 != 0)) {
      if (((DAT_03003964 & 2) == 0) || (_DAT_0203a4e8 != 0)) {
        if ((DAT_030031b8 & 0x100) == 0) {
          if (((DAT_030031b8 & 0x200) != 0) && (_DAT_0203a540 == 0)) {
            sub_080C51D4(0x158);
            sub_08145260();
          }
        }
        else if (_DAT_0203a4e8 == 0) {
          if ((_DAT_0203a4ec != 0) && (uVar4 = sub_080C31F0(), _DAT_0203a4ec <= uVar4)) {
            sub_080C51D4(0x15a);
            sub_081457FC();
            DAT_0203a4f8._0_2_ = sVar1;
            _DAT_0203a4ea = sVar1;
            sub_080C31B4(-_DAT_0203a4ec);
            sub_08144868(3,1,0,0);
          }
        }
        else {
          sub_080C51D4(0x15a);
          sub_081457FC();
          DAT_0203a4f8._0_2_ = 0;
          _DAT_0203a4ea = 0;
          sub_08144868(3,3,0,0);
        }
      }
      else {
        if (_DAT_0203a4ec != 0) {
          _DAT_0203a4ec = _DAT_0203a4ec - 1;
          _DAT_0203a4ea = _DAT_0203a4e8;
        }
        sub_080C51D4(0x160);
      }
    }
    else {
      iVar3 = 1;
      if ((DAT_030031d0 & 4) != 0) {
        iVar3 = 8;
      }
      if (_DAT_0203a4ec != 8) {
        _DAT_0203a4ec = _DAT_0203a4ec + iVar3;
        if (8 < _DAT_0203a4ec) {
          _DAT_0203a4ec = 8;
        }
        _DAT_0203a4ea = _DAT_0203a4e8;
      }
      sub_080C51D4(0x160);
    }
    if (DAT_0203a454 == 2) {
      if (_DAT_0203a4e8 == 0) {
        if (((_DAT_0203a4ec == 0) || (uVar4 = sub_080C31F0(), uVar4 < _DAT_0203a4ec)) ||
           (DAT_0203a542 != 0)) {
          uVar2 = 1;
        }
        else {
          uVar2 = 1;
          if ((DAT_030031bc >> 4 & 1) != 0) {
            uVar2 = 2;
          }
        }
      }
      else {
        if (DAT_0203a542 != 0) {
          sub_08144868(3,3,0,0);
          goto LAB_08144e1e;
        }
        if ((DAT_030031bc >> 4 & 1) == 0) {
          uVar2 = 3;
        }
        else {
          uVar2 = 4;
        }
      }
      sub_08144868(3,uVar2,0,0);
    }
  }
LAB_08144e1e:
  if ((1 < DAT_0203a454) && (DAT_0203a454 != 3)) {
    sub_08144B70();
  }
  uVar4 = 0;
  puVar5 = (undefined4 *)0x879a16c;
  do {
    uVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    sub_080AA184(uVar2,0,0,2);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 9);
  if ((_DAT_0203a540 != 1) && (sub_081447E4(2,8,6), DAT_0203a454 == 3)) {
    if ((DAT_030031bc >> 3 & 1) == 0) {
      sub_08144868(2,1,0,0);
    }
    else {
      sub_08144868(2,2,0,0);
    }
  }
  if ((DAT_030031bc & 3) == 0) {
    if (_DAT_0203a4ec == 0) {
      if (_DAT_0203a540 != 0) {
        if (_DAT_0203a540 == 4) {
          _DAT_0203a540 = 0;
        }
        else {
          _DAT_0203a540 = _DAT_0203a540 + 1;
        }
      }
    }
    else if (_DAT_0203a540 == 0) {
      _DAT_0203a540 = 4;
    }
    else if (_DAT_0203a540 != 1) {
      _DAT_0203a540 = _DAT_0203a540 + -1;
    }
  }
  sub_081447E4(0,7,4);
  sub_081447E4(3,0xba,6);
  sub_081447E4(1,0xbb,4);
  sub_081447E4(5,7,0x29);
  sub_081447E4(6,7,0x36);
  sub_081447E4(7,7,0x43);
  sub_081447E4(8,7,0x50);
  sub_081447E4(4,7,0x5d);
  sub_081447E4(10,6,0x87);
  sub_081447E4(0xb,6,0x93);
  sub_081447E4(0xc,0x87,0x7b);
  sub_081447E4(0xd,0x87,0x87);
  sub_081447E4(9,0x87,0x93);
  sub_08144920(_DAT_0203a4f4,6,0xe,0x1d);
  uVar2 = sub_080C31F0();
  sub_08144920(uVar2,6,0xc4,0x1d);
  sub_08144998();
  sub_08145194();
  sub_081451FC();
                    /* WARNING: Could not recover jumptable at 0x08144fa6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08144FA8 @ 0x08144FA8

void sub_08144FA8(undefined4 arg0,undefined4 arg1)

{
  DAT_0203a454 = (undefined2)arg1;
  return;
}


// sub_08144FB4 @ 0x08144FB4

void sub_08144FB4(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2005004;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_08144FD8 @ 0x08144FD8

void sub_08144FD8(undefined4 *arg0,undefined4 *arg1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    *arg1 = *arg0;
    arg0 = arg0 + 8;
    arg1 = arg1 + 8;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 4);
  return;
}


// sub_08144FF0 @ 0x08144FF0

void sub_08144FF0(uint arg0,int arg1,int arg2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  uint arg0_00;
  uint uVar6;
  int *piStack_24;
  
  uVar1 = *(ushort *)((int)&DAT_0203a4a0 + (arg0 & 0xffff) * 2);
  iVar4 = arg1 * 0x10000 - 0x20000;
  sVar5 = (short)((uint)iVar4 >> 0x10);
  if (iVar4 >> 0x10 < 0) {
    sVar5 = sVar5 + 0x1e0;
  }
  uVar6 = 0;
  piStack_24 = (int *)0x879a56c;
  do {
    arg0_00 = (int)sVar5 + uVar6;
    if (0x1df < arg0_00) {
      arg0_00 = arg0_00 - 0x1e0;
    }
    iVar4 = __udivsi3(arg0_00,0x14);
    uVar2 = *(ushort *)(arg2 + iVar4 * 2);
    iVar4 = __umodsi3(arg0_00,0x14);
    iVar3 = *piStack_24;
    piStack_24 = piStack_24 + 1;
    sub_08144FD8(*(int *)((uint)uVar2 * 4 + 0x879a52c) + *(int *)(iVar4 * 4 + 0x879a56c) +
                 (uint)uVar1 * 0xc00 + 0x879896c,
                 *(int *)((arg0 & 0xffff) * 4 + 0x879a548) + iVar3 + 0x2005004);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x19);
  DisplayList_Add(0x8144fb5,1);
  return;
}


// sub_081450D8 @ 0x081450D8

void sub_081450D8(uint arg0,int arg1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(&DAT_0203a458 + (arg0 & 0xffff) * 2);
  uVar2 = *puVar3 + arg1;
  *puVar3 = uVar2;
  iVar1 = (int)uVar2 >> 0x10;
  if (-1 < iVar1) {
    if (iVar1 < (int)0x1e0) {
      return;
    }
    iVar1 = -iVar1;
  }
  *puVar3 = uVar2 & 0xffff | (iVar1 + 0x1e0) * 0x10000;
  return;
}


// sub_08145124 @ 0x08145124

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08145124(undefined4 arg0,undefined4 arg1,uint arg2,int arg3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  uVar3 = arg2 & 0xffff;
  piVar4 = (int *)(arg3 + uVar3 * _DAT_0203a4ec * 4);
  uVar2 = 0;
  if (uVar3 != 0) {
    do {
      iVar1 = *piVar4;
      piVar4 = piVar4 + 1;
      sub_080AA184(*(undefined4 *)(iVar1 * 4 + 0x879a928),0,0,0);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar3);
  }
  return;
}


// sub_08145194 @ 0x08145194

void sub_08145194(void)

{
  sub_08145124(0x38,0x78,1,0x879a5ec);
  sub_08145124(0xb,0x8b,5,0x879a610);
  sub_08145124(0xb,0x97,5,0x879a6c4);
  sub_08145124(0x8c,0x7f,4,0x879a778);
  sub_08145124(0x8c,0x8b,4,0x879a808);
  sub_08145124(0x8c,0x97,4,0x879a898);
  return;
}


// sub_081451FC @ 0x081451FC

void sub_081451FC(void)

{
  undefined4 arg0;
  uint uVar1;
  undefined4 *puVar2;
  
  if (((ushort)DAT_0203a4f8 != 0) && (uVar1 = 0, (ushort)DAT_0203a4f8 != 0)) {
    puVar2 = (undefined4 *)0x879aa24;
    do {
      arg0 = *puVar2;
      puVar2 = puVar2 + 1;
      sub_080AA184(arg0,0,0,0);
      uVar1 = uVar1 + 1;
    } while (uVar1 < (ushort)DAT_0203a4f8);
  }
  return;
}


// sub_08145260 @ 0x08145260

void sub_08145260(void)

{
  sub_080AD0FC(0x879aa3c,0xffff);
  DAT_0203a454 = 3;
  return;
}


// sub_08145284 @ 0x08145284

void sub_08145284(int arg0)

{
  undefined4 in_r1;
  
  sub_081450D8((uint)*(ushort *)(arg0 + 0x24),in_r1);
  return;
}


// sub_08145290 @ 0x08145290

uint sub_08145290(uint arg0)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(&DAT_0203a4c4 + (arg0 & 0xffff) * 4);
  iVar1 = __udivsi3((uint)(ushort)(&DAT_0203a45a)[(arg0 & 0xffff) * 2],0x14);
  return (uint)*(ushort *)(iVar1 * 2 + iVar2);
}


// sub_081452BC @ 0x081452BC

void sub_081452BC(int arg0)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  dword dVar5;
  
  iVar2 = sub_080C2244();
  uVar4 = (uint)(iVar2 * 0x18) >> 8;
  dVar5 = *(dword *)(&DAT_0203a4c4 + (uint)*(ushort *)(arg0 + 0x24) * 4);
  uVar3 = sub_08145290((uint)*(ushort *)(arg0 + 0x24));
  if (dVar5 == 0x879c7c4) {
    sub_08144A08((uint)*(ushort *)(arg0 + 0x24));
    uVar3 = sub_08145290((uint)*(ushort *)(arg0 + 0x24));
  }
  uVar1 = *(ushort *)(uVar4 * 2 + dVar5);
  while ((uint)uVar1 == (uVar3 & 0xffff)) {
    uVar4 = uVar4 + 1;
    if (uVar4 == 0x18) {
      uVar4 = 0;
    }
    uVar1 = *(ushort *)(uVar4 * 2 + dVar5);
  }
  *(uint *)(&DAT_0203a458 + (uint)*(ushort *)(arg0 + 0x24) * 2) = uVar4 * 0x140000;
  return;
}


// sub_08145334 @ 0x08145334

void sub_08145334(int arg0)

{
  (&DAT_0203a47c)[*(ushort *)(arg0 + 0x24)] = 0;
  return;
}


// sub_08145348 @ 0x08145348

void sub_08145348(int arg0)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(arg0 + 0x24);
  if (*(short *)(arg0 + 0x26) == 5) {
    *(undefined4 *)(&DAT_0203a458 + (uint)uVar1 * 2) = 0x280000;
    *(dword *)(&DAT_0203a4c4 + (uint)uVar1 * 4) = 0x879c7c4;
  }
  return;
}


// sub_08145378 @ 0x08145378

void sub_08145378(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x879aa94,0xffff);
  *(ushort *)(iVar1 + 0x24) = (ushort)arg0;
  *(undefined2 *)(iVar1 + 0x26) = (undefined2)arg1;
  (&DAT_0203a47c)[(ushort)arg0] = iVar1;
  return;
}


// sub_081453B0 @ 0x081453B0

void sub_081453B0(int arg0,uint arg1)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (*(short *)(&DAT_0203a4b2 + arg1 * 2) == 0) {
    sub_08145378(arg1 & 0xffff,0xffffffff);
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_081453E4 @ 0x081453E4

void sub_081453E4(int arg0,int arg1)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (*(short *)(&DAT_0203a4b2 + arg1 * 2) == 0) {
    *(undefined4 *)((&DAT_0203a47c)[arg1] + 0xc) = 1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_08145418 @ 0x08145418

void sub_08145418(int arg0)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar2 = 0;
  piVar1 = &DAT_0203a47c;
  do {
    if (*piVar1 != 0) {
      return;
    }
    piVar1 = piVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 9);
  *(undefined2 *)(arg0 + 0x1c) = 1;
  return;
}


// sub_08145440 @ 0x08145440

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08145440(int arg0,uint arg1)

{
  int iVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (arg1 <= _DAT_0203a4ec) {
    iVar1 = arg1 * 0xc;
    iVar1 = sub_08145CC8(*(undefined4 *)(iVar1 + 0x879ac18),*(undefined4 *)(&DAT_0879ac1c + iVar1),
                         *(undefined4 *)(&DAT_0879ac20 + iVar1));
    if (-1 < iVar1) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  return;
}


// sub_08145488 @ 0x08145488

void sub_08145488(undefined4 arg0,int arg1,undefined4 arg2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = arg1 * 0xc;
  iVar2 = *(int *)(&DAT_0879ac1c + iVar3);
  iVar1 = *(int *)(&DAT_0879ac20 + iVar3);
  *(undefined2 *)((int)&DAT_0203a4a0 + (*(int *)(iVar3 + 0x879ac18) + -1) * 2) = (undefined2)arg2;
  *(undefined2 *)((int)&DAT_0203a4a0 + (iVar2 + -1) * 2) = (undefined2)arg2;
  *(undefined2 *)((int)&DAT_0203a4a0 + (iVar1 + -1) * 2) = (undefined2)arg2;
  return;
}


// sub_081454CC @ 0x081454CC

int sub_081454CC(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  do {
    uVar1 = sub_08145290(uVar2 & 0xffff);
    if ((uVar1 & 0xffff) == 6) {
      iVar3 = iVar3 + 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 9);
  return iVar3;
}


// sub_081454F4 @ 0x081454F4

void sub_081454F4(int arg0)

{
  uint uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar1 = sub_081454CC();
  if (3 < uVar1) {
    DAT_0203a4f8._2_2_ = (undefined2)uVar1;
    DAT_0203a4f8._0_2_ = 0;
    DAT_0203a4fc = DAT_0203a4f8._2_2_;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_0814552C @ 0x0814552C

void sub_0814552C(int arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_081454CC();
  *(ushort *)(arg0 + 0x1c) = (ushort)(3 < uVar1);
                    /* WARNING: Could not recover jumptable at 0x08145544. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08145548 @ 0x08145548

void sub_08145548(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0203a4f8._0_2_ = (short)DAT_0203a4f8 + 1;
  DAT_0203a4f8._2_2_ = DAT_0203a4f8._2_2_ - 1;
  if (DAT_0203a4f8._2_2_ < 4) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_08145578 @ 0x08145578

void sub_08145578(void)

{
  undefined2 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = (undefined2 *)&DAT_0203a4b2;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 9);
  return;
}


// sub_08145594 @ 0x08145594

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08145594(int arg0,uint arg1)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (_DAT_0203a4e8 != arg1) {
    _DAT_0203a4e8 = (ushort)arg1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if (arg1 == 0) {
      sub_08145578();
    }
  }
  return;
}


// sub_081455C0 @ 0x081455C0

void sub_081455C0(uint arg0)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = sub_08145290(uVar2 & 0xffff);
    if ((uVar1 & 0xffff) == (arg0 & 0xffff)) {
      *(undefined2 *)(&DAT_0203a4b2 + uVar2 * 2) = 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 9);
  return;
}


// sub_081455F8 @ 0x081455F8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081455F8(int arg0,int arg1)

{
  undefined4 arg0_00;
  undefined2 *puVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  sub_08145578();
  switch(DAT_0203a4fc) {
  case 4:
    sub_081455C0(6);
    return;
  case 5:
    sub_081455C0(1);
    return;
  case 6:
    if (arg1 != 0) {
      if (arg1 == 1) {
        sub_081453E4(arg0,4);
        return;
      }
      DAT_0203a4ba = 1;
      return;
    }
    DAT_0203a4b6 = 1;
    _DAT_0203a4b4 = 1;
    _DAT_0203a4b2 = 1;
    DAT_0203a4bc = 1;
    DAT_0203a4b8 = 1;
    DAT_0203a4c2 = 1;
    DAT_0203a4c0 = 1;
    DAT_0203a4be = 1;
    arg0_00 = 4;
    break;
  case 7:
    if (arg1 != 0) {
      if (arg1 == 1) {
        sub_081453E4(arg0,1);
        sub_081453E4(arg0,3);
        sub_081453E4(arg0,5);
        sub_081453E4(arg0,7);
        return;
      }
      _DAT_0203a4b4 = 1;
      DAT_0203a4b8 = 1;
      puVar1 = &DAT_0203a4bc;
LAB_08145776:
      *puVar1 = 1;
      puVar1[2] = 1;
      return;
    }
    DAT_0203a4b6 = 1;
    _DAT_0203a4b2 = 1;
    DAT_0203a4ba = 1;
    DAT_0203a4c2 = 1;
    DAT_0203a4be = 1;
    sub_08145378(1,5);
    sub_08145378(3,5);
    sub_08145378(5,5);
    arg0_00 = 7;
    break;
  case 8:
    if (arg1 != 0) {
      if (arg1 == 1) {
        sub_081453E4(arg0,0);
        sub_081453E4(arg0,2);
        sub_081453E4(arg0,6);
        sub_081453E4(arg0,8);
        return;
      }
      _DAT_0203a4b2 = 1;
      DAT_0203a4b6 = 1;
      puVar1 = &DAT_0203a4be;
      goto LAB_08145776;
    }
    _DAT_0203a4b4 = 1;
    DAT_0203a4bc = 1;
    DAT_0203a4ba = 1;
    DAT_0203a4b8 = 1;
    DAT_0203a4c0 = 1;
    sub_08145378(0,5);
    sub_08145378(2,5);
    sub_08145378(6,5);
    arg0_00 = 8;
    break;
  default:
    goto switchD_0814561e_caseD_9;
  }
  sub_08145378(arg0_00,5);
  *(undefined2 *)(arg0 + 0x1c) = 1;
switchD_0814561e_caseD_9:
  return;
}


