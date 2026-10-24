/* Ghidra decompilation of asm/code_08136D5C.s (reference only; not compiled). */

// ScriptOp_38B @ 0x08136D5C

void ScriptOp_38B(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar2 = DAT_0203db40 + 1;
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar3 = (uint)*(ushort *)((uint)uVar2 * 2 + DAT_03006950);
  DAT_03006964 = sub_080B4420((uint)*(ushort *)((uVar3 * 2 + 1) * 2 + 0x879041e),
                              (uint)*(ushort *)(uVar3 * 4 + 0x879041e));
  if ((uVar1 & 0xf0) != 0) {
    sub_080ECF80();
  }
  DAT_0203db6e = 1;
  DAT_0203db5a = 0x34;
  return;
}


// ScriptOp_38C @ 0x08136DD0

void ScriptOp_38C(void)

{
  return;
}


// ScriptOp_38D @ 0x08136DD4

void ScriptOp_38D(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  
  uVar3 = sub_080C32D4((uint)DAT_0203db50);
  uVar5 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar5 * 2 + DAT_03006950);
  uVar4 = sub_08131AB0(0xff,(uint)DAT_0203db50);
  if (0x62 < (uVar3 & 0xff) + (uVar4 & 0xffff)) {
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// ScriptOp_390 @ 0x08136E34

void ScriptOp_390(void)

{
  return;
}


// ScriptOp_391 @ 0x08136E38

void ScriptOp_391(void)

{
  return;
}


// ScriptOp_392 @ 0x08136E3C

void ScriptOp_392(void)

{
  DAT_0203db58 = 0;
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  if (DAT_0203db6c != 0) {
    sub_080AB91C(DAT_03006968,1);
    DAT_0203db6c = 0;
  }
  Font_ResetGlyphSpriteCache(0x180);
  DAT_030068e0 = sub_080D110C(3,1);
  DAT_0203db5a = 0x2b;
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_394 @ 0x08136EB8

void ScriptOp_394(void)

{
  return;
}


// ScriptOp_395 @ 0x08136EBC

void ScriptOp_395(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  sub_080C4580();
  return;
}


// ScriptOp_396 @ 0x08136EF8

void ScriptOp_396(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_398 @ 0x08136F08

void ScriptOp_398(void)

{
  return;
}


// ScriptOp_399 @ 0x08136F0C

void ScriptOp_399(void)

{
  return;
}


// ScriptOp_39A @ 0x08136F10

void ScriptOp_39A(void)

{
  return;
}


// ScriptOp_39B @ 0x08136F14

void ScriptOp_39B(void)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  
  sub_0812F198();
  uVar3 = DAT_0203db40 + 2;
  DAT_0203dac8 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950));
  uVar1 = DAT_0203db40 + 3;
  DAT_0203db40 = DAT_0203db40 + 4;
  DAT_0203dacc = CONCAT22(*(undefined2 *)((uint)uVar1 * 2 + DAT_03006950),
                          *(undefined2 *)((uint)uVar3 * 2 + DAT_03006950));
  uVar4 = 0;
  do {
    *(undefined2 *)(uVar4 * 2 + 0x203db88) = 0xffff;
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 0x14);
  uVar4 = 1;
  iVar2 = (uint)((char)DAT_03006914 == '\x01') * 0x14;
  DAT_03006604 = *(short *)(iVar2 + 0x878eedc);
  uVar5 = 0;
  if (0 < DAT_03006604 + 1) {
    do {
      *(undefined2 *)(uVar5 * 2 + 0x203db88) = *(undefined2 *)(uVar4 * 2 + iVar2 + 0x878eedc);
      uVar5 = uVar5 + 1 & 0xffff;
      uVar4 = uVar4 + 1 & 0xffff;
    } while ((int)uVar5 < DAT_03006604 + 1);
  }
  DAT_03006940 = 0;
  DAT_0300696c = 0;
  DAT_03006844 = 4;
  sub_0812F2B4(4);
  sub_080AD0FC(0x878fc80,0xffff);
  DAT_0203db6e = 1;
  DAT_0203db5a = 0xd;
  return;
}


// ScriptOp_39C @ 0x08137058

void ScriptOp_39C(void)

{
  return;
}


// ScriptOp_39F @ 0x0813705C

void ScriptOp_39F(void)

{
  DAT_03006698 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_03006914 = DAT_03006698 | 0x100;
  DAT_03006674 = DAT_03006950;
  DAT_030069e0 = DAT_0203db40 + 1;
  DAT_03006600 = 1;
  DAT_03006950 = 0x803bad6;
  DAT_0203db40 = 0;
  return;
}


// ScriptOp_3A3 @ 0x081370C0

void ScriptOp_3A3(void)

{
  sub_080C30AC(-DAT_0203db2c);
  return;
}


// ScriptOp_3A4 @ 0x081370D4

void ScriptOp_3A4(void)

{
  DAT_0300699c = 0;
  sub_080C30AC(DAT_0203db2c);
  return;
}


// ScriptOp_3A5 @ 0x081370F0

void ScriptOp_3A5(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  ushort uVar4;
  uint arg0;
  
  uVar4 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  arg0 = 0;
  while ((arg0 < 0x100 && (uVar3 = sub_080C32D4(arg0), (uVar3 & 0xff) == 0))) {
    arg0 = arg0 + 1 & 0xffff;
  }
  if (arg0 == 0x100) {
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// ScriptOp_3A6 @ 0x08137150

void ScriptOp_3A6(void)

{
  return;
}


// ScriptOp_3A8 @ 0x08137154

void ScriptOp_3A8(void)

{
  return;
}


// ScriptOp_3A9 @ 0x08137158

void ScriptOp_3A9(void)

{
  return;
}


// ScriptOp_3AB @ 0x0813715C

void ScriptOp_3AB(void)

{
  return;
}


// ScriptOp_3AC @ 0x08137160

void ScriptOp_3AC(void)

{
  DAT_03006964 = sub_080B8020();
  DAT_0203db5a = 0x36;
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_3AE @ 0x08137188

void ScriptOp_3AE(void)

{
  return;
}


// ScriptOp_3B1 @ 0x0813718C

void ScriptOp_3B1(void)

{
  return;
}


// ScriptOp_3B2 @ 0x08137190

void ScriptOp_3B2(void)

{
  return;
}


// ScriptOp_3B3 @ 0x08137194

void ScriptOp_3B3(void)

{
  return;
}


// ScriptOp_3B6 @ 0x08137198

void ScriptOp_3B6(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  uint arg0;
  
  uVar5 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar5 * 2 + DAT_03006950);
  sVar3 = 0;
  arg0 = 0x40;
  do {
    uVar4 = sub_080C32D4(arg0);
    if ((uVar4 & 0xff) != 0) {
      sVar3 = sVar3 + 1;
    }
    arg0 = arg0 + 1 & 0xffff;
  } while (arg0 < 0x50);
  if (sVar3 != 0) {
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// ScriptOp_3B9 @ 0x081371F8

void ScriptOp_3B9(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  uint arg0;
  uint uVar7;
  uint uVar8;
  
  uVar6 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar6 * 2 + DAT_03006950);
  uVar7 = 0;
  do {
    *(undefined2 *)(uVar7 * 2 + 0x203db88) = 0xffff;
    uVar7 = uVar7 + 1 & 0xffff;
  } while (uVar7 < 0x14);
  uVar4 = (uint)DAT_0203db72;
  arg0 = 0xf0;
  uVar7 = 0;
  do {
    iVar5 = sub_080C2340(arg0);
    uVar8 = uVar7;
    if ((iVar5 != 0) && (arg0 != (uVar4 & 0xf | 0xf0))) {
      uVar8 = uVar7 + 1 & 0xffff;
      *(short *)(uVar7 * 2 + 0x203db88) = (short)arg0 + -0x60;
    }
    arg0 = arg0 + 1 & 0xffff;
    uVar7 = uVar8;
  } while (arg0 < 0xfd);
  uVar3 = CONCAT22(uVar2,uVar1);
  if (DAT_0203db88 != -1) {
    DAT_03006604 = (short)uVar8 + -1;
    uVar3 = DAT_030068e4;
  }
  DAT_030068e4 = uVar3;
  return;
}


// ScriptOp_3BA @ 0x081372BC

void ScriptOp_3BA(void)

{
  return;
}


// ScriptOp_3BB @ 0x081372C0

void ScriptOp_3BB(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_0203db6e = 1;
  DAT_0203db5a = 0x3f;
  return;
}


// ScriptOp_3BD @ 0x081372E4

void ScriptOp_3BD(void)

{
  return;
}


// ScriptOp_3BE @ 0x081372E8

void ScriptOp_3BE(void)

{
  return;
}


// ScriptOp_3BF @ 0x081372EC

void ScriptOp_3BF(void)

{
  return;
}


// ScriptOp_3C0 @ 0x081372F0

void ScriptOp_3C0(void)

{
  int iVar1;
  
  iVar1 = sub_080C2340(0x23);
  if ((iVar1 == 0) || ((char)DAT_0203db72 != '\0')) {
    sub_080C2364((DAT_0203db72 & 0xf) + 0xf0);
  }
  return;
}


// ScriptOp_3C2 @ 0x0813731C

void ScriptOp_3C2(void)

{
  return;
}


// ScriptOp_3C4 @ 0x08137320

void ScriptOp_3C4(void)

{
  return;
}


// ScriptOp_3C5 @ 0x08137324

void ScriptOp_3C5(void)

{
  ushort uVar1;
  ushort uVar2;
  
  DAT_0203dac8 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950));
  uVar2 = DAT_0203db40 + 4;
  DAT_0203dacc = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 3) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 2) * 2 + DAT_03006950));
  uVar1 = DAT_0203db40 + 5;
  DAT_0203db40 = DAT_0203db40 + 6;
  DAT_0203dad0 = CONCAT22(*(undefined2 *)((uint)uVar1 * 2 + DAT_03006950),
                          *(undefined2 *)((uint)uVar2 * 2 + DAT_03006950));
  DAT_0300668c = 0;
  sub_0812DC24();
  DAT_0203db5a = 0x1e;
  DAT_0203db6e = 1;
  return;
}


// sub_081373C0 @ 0x081373C0

uint sub_081373C0(int arg0)

{
  uint uVar1;
  
  uVar1 = arg0 * 0x100;
  if (0x7fff < uVar1) {
    uVar1 = uVar1 | 0xffff0000;
  }
  return uVar1;
}


// ScriptOp_3C7 @ 0x081373E0

void ScriptOp_3C7(void)

{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  short sVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar5 = DAT_0203db40 + 1;
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = sVar5;
  if (sVar1 == 0) {
    DAT_0203db34 = 0;
  }
  else if (DAT_0203db34 != 0) {
    if (sVar1 == 1) {
      uVar4 = 0xffffffff;
      uVar3 = uVar4;
    }
    else if (sVar1 == 2) {
      uVar4 = 1;
      uVar3 = 1;
    }
    else {
      uVar2 = sub_080C0794(0);
      uVar3 = 1;
      if (0x7f < uVar2 >> 8) {
        uVar3 = 0xffffffff;
      }
      uVar2 = sub_080C0794(1);
      uVar4 = 1;
      if (0x7f < uVar2 >> 8) {
        uVar4 = 0xffffffff;
      }
    }
    uVar3 = sub_081373C0(uVar3);
    uVar4 = sub_081373C0(uVar4);
    sub_080C06EC(0,uVar3);
    sub_080C06EC(1,uVar4);
  }
                    /* WARNING: Could not recover jumptable at 0x08137476. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_3C6 @ 0x08137478

void ScriptOp_3C6(void)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  uint uVar5;
  uint local_14;
  
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar4 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar3 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  if (sVar1 == 0x65) {
    uVar5 = sub_080D2268((uint)DAT_030069a8);
    if ((uVar5 & 0xffff) == 6) {
      return;
    }
    uVar5 = sub_080C00DC((int)DAT_03006898,uVar5 & 0xffff);
    if ((uVar5 & 0xff) == 0xff) {
      return;
    }
    sub_080BF468(uVar5 & 0xff,6,&local_14);
    if ((local_14 & 1) == 0) {
      return;
    }
  }
  else if (DAT_03004552 != sVar1) {
    return;
  }
  DAT_030068e4 = CONCAT22(uVar3,uVar2);
  return;
}


// sub_08137518 @ 0x08137518

void sub_08137518(int arg0,undefined4 arg1)

{
  int iVar1;
  uint uVar2;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg0 * 0x10000 + 0x1200000U >> 0x10;
  iVar1 = (int)(short)arg1;
  if (iVar1 < 0) {
    uVar2 = 0;
    if (0 < -(short)arg1) {
      do {
        sub_080C33AC(arg0_00);
        uVar2 = uVar2 + 1 & 0xffff;
      } while ((int)uVar2 < (int)-(short)arg1);
    }
  }
  else {
    uVar2 = 0;
    if (0 < iVar1) {
      do {
        sub_080C3328(arg0_00);
        uVar2 = uVar2 + 1 & 0xffff;
      } while ((int)uVar2 < iVar1);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08137568. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0813756C @ 0x0813756C

uint sub_0813756C(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C32D4(arg0 * 0x10000 + 0x1200000U >> 0x10);
  return uVar1 & 0xff;
}


// ScriptOp_3CA @ 0x08137584

void ScriptOp_3CA(void)

{
  return;
}


// ScriptOp_3CB @ 0x08137588

void ScriptOp_3CB(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar4 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  uVar3 = sub_080C1D9C();
  if ((uVar3 & 0xf0) == 0x80) {
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// ScriptOp_3CC @ 0x081375D0

void ScriptOp_3CC(void)

{
  return;
}


// ScriptOp_3CD @ 0x081375D4

void ScriptOp_3CD(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  
  sVar4 = DAT_0203db40 + 1;
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = sVar4;
  if (DAT_0300685c < 0x40) {
    uVar2 = sub_0813E60C((uint)DAT_0203db7c,0xb);
    uVar2 = sub_0815B958(uVar2 & 0xffff);
    uVar3 = sub_080C0794(0);
    uVar3 = sub_0815B970((uVar3 & 0xff00) >> 8);
    if ((uVar3 & 0xff) != 1) {
      if ((uVar3 & 0xff) == 0) {
        if ((uVar2 & 0xff) != 2) goto LAB_08137654;
      }
      else if ((uVar2 & 0xff) != 0) goto LAB_08137654;
      DAT_0300685c = DAT_0300685c + 0x40;
    }
  }
LAB_08137654:
  uVar2 = (uint)(DAT_0300685c >> 4) << 1;
  if (sVar1 == 0) {
    sub_0815BAC8((uint)DAT_0203db7c,1);
  }
  else {
    uVar2 = uVar2 | 1;
  }
  DAT_03006950 = 0x8032d7c;
  DAT_030068e4 = *(undefined4 *)(uVar2 * 4 + 0x8032d7c);
  return;
}


// sub_081376AC @ 0x081376AC

undefined4 sub_081376AC(uint arg0)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2244();
                    /* WARNING: Could not recover jumptable at 0x081376ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)((uVar1 & 0xffff) < (arg0 & 0xffff));
  return uVar2;
}


// ScriptOp_3CE @ 0x081376CC

void ScriptOp_3CE(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar3 = (uint)DAT_0203db40;
  uVar4 = DAT_0203db40 + 2;
  uVar1 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar2 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  uVar3 = sub_081376AC((uint)*(ushort *)(uVar3 * 2 + DAT_03006950));
  if ((uVar3 & 0xffff) != 0) {
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// sub_08137720 @ 0x08137720

undefined4 sub_08137720(undefined4 arg0)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = sub_080C0F8C(0);
  if ((ushort)arg0 == 2) {
    uVar2 = sub_0813E60C((uint)DAT_0203db7c,0);
    uVar3 = sub_080C2244();
    uVar2 = (uVar2 & 0xffff) + (uVar3 & 3) + 1;
  }
  else {
    if ((ushort)arg0 < 3) {
      uVar2 = sub_0813E60C((uint)DAT_0203db7c,0);
      if ((int)(short)uVar1 < (int)(uVar2 & 0xff)) {
        return 1;
      }
      return 0;
    }
    if ((ushort)arg0 == 3) {
      uVar2 = sub_0813E60C((uint)DAT_0203db7c,0);
      uVar3 = sub_080C2244();
      uVar2 = (uVar2 & 0xffff) + (uVar3 & 3) + 6;
    }
    else {
      uVar2 = sub_0813E60C((uint)DAT_0203db7c,0);
      uVar3 = sub_080C2244();
      uVar2 = ((uVar2 & 0xffff) + (uVar3 & 3)) - 1;
    }
  }
  if ((int)(short)uVar1 <= (int)(uVar2 & 0xff)) {
    return 1;
  }
  return 0;
}


// ScriptOp_3CF @ 0x081377D0

void ScriptOp_3CF(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar3 = (uint)DAT_0203db40;
  uVar4 = DAT_0203db40 + 2;
  uVar1 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar2 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  uVar3 = sub_08137720((uint)*(ushort *)(uVar3 * 2 + DAT_03006950));
  if ((uVar3 & 0xffff) != 0) {
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// ScriptOp_3D0 @ 0x08137824

void ScriptOp_3D0(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  uint uVar5;
  
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar4 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar3 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  uVar5 = sub_080C0E44(0,1);
  if (uVar5 <= uVar1) {
    DAT_030068e4 = CONCAT22(uVar3,uVar2);
  }
  return;
}


// ScriptOp_3D1 @ 0x08137878

void ScriptOp_3D1(void)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar4 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar3 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  if (sVar1 == 1) {
    uVar5 = sub_080C2244();
    uVar6 = 0;
    if ((uVar5 & 7) != 0) {
      uVar6 = (uVar5 & 7) - 1 & 0xffff;
    }
  }
  else if (sVar1 == 2) {
    uVar6 = sub_080C2244();
    uVar6 = (uVar6 & 7) + 3;
  }
  else {
    uVar6 = sub_080C2244();
    uVar6 = uVar6 & 0xf;
  }
  uVar5 = sub_080C0E20(0);
  if ((uVar5 & 0xffff) <= (uVar6 & 0xff)) {
    DAT_030068e4 = CONCAT22(uVar3,uVar2);
  }
                    /* WARNING: Could not recover jumptable at 0x08137900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_3D2 @ 0x08137908

void ScriptOp_3D2(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  uint uVar5;
  
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar4 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar3 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  uVar5 = sub_080C0E44(0,2);
  if (uVar5 <= uVar1) {
    DAT_030068e4 = CONCAT22(uVar3,uVar2);
  }
  return;
}


// ScriptOp_3D3 @ 0x0813795C

void ScriptOp_3D3(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  
  uVar7 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar7 * 2 + DAT_03006950);
  uVar3 = sub_080C2244();
  uVar4 = sub_080C2244();
  uVar5 = sub_080C2244();
  uVar6 = sub_080C0D6C(0);
  if ((uVar6 & 0xffff) <= (((uVar3 & 7) + (uVar4 & 7) + (uVar5 & 7)) - 1 & 0xffff)) {
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// ScriptOp_3D4 @ 0x081379C8

void ScriptOp_3D4(void)

{
  return;
}


// sub_081379CC @ 0x081379CC

undefined4 sub_081379CC(undefined4 arg0)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = sub_080EF90C();
  if ((short)arg0 == 1) {
    uVar2 = sub_080C2244();
    iVar3 = (uVar2 & 3) + 6;
  }
  else {
    if ((short)arg0 != 2) {
      if ((short)arg0 != 3) {
        return iVar1;
      }
      uVar2 = sub_080C2244();
      if ((int)((uVar2 & 7) + 10) < iVar1) {
        return 0;
      }
      return 1;
    }
    uVar2 = sub_080C2244();
    iVar3 = (uVar2 & 7) + 5;
  }
  if (iVar3 < iVar1) {
    return 0;
  }
  return 1;
}


// ScriptOp_3D5 @ 0x08137A20

void ScriptOp_3D5(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar3 = (uint)DAT_0203db40;
  uVar4 = DAT_0203db40 + 2;
  uVar1 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar2 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  uVar3 = sub_081379CC((uint)*(ushort *)(uVar3 * 2 + DAT_03006950));
  if ((uVar3 & 0xffff) != 0) {
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// ScriptOp_3D6 @ 0x08137A74

void ScriptOp_3D6(void)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar5 = sub_080EF954();
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar4 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar3 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  if (sVar1 == 1) {
    uVar6 = sub_080C2244();
    iVar7 = (uVar6 & 3) + 6;
  }
  else if (sVar1 == 2) {
    uVar6 = sub_080C2244();
    iVar7 = (uVar6 & 7) + 5;
  }
  else {
    uVar6 = sub_080C2244();
    iVar7 = (uVar6 & 7) + 9;
  }
  if (iVar5 <= iVar7) {
    DAT_030068e4 = CONCAT22(uVar3,uVar2);
  }
                    /* WARNING: Could not recover jumptable at 0x08137af2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08137AF8 @ 0x08137AF8

void sub_08137AF8(int arg0)

{
  sub_080C2244();
  return;
}


// sub_08137B1C @ 0x08137B1C

uint sub_08137B1C(uint arg0)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = sub_080C2244();
  iVar2 = __udivsi3((arg0 & 0xffff) * ((uVar1 & 0xf) + 1) & 0xffff,0xc);
  return iVar2 * 0x10000 + 0xa0000U >> 0x10;
}


// sub_08137B4C @ 0x08137B4C

void sub_08137B4C(void)

{
  uint uVar1;
  
  uVar1 = sub_0813BDCC();
  uVar1 = sub_08137B1C(uVar1 & 0xffff);
  DAT_0203db2c = uVar1 & 0xffff;
  sub_080C30AC(DAT_0203db2c);
  sub_0813B328(0x23);
  return;
}


// sub_08137B78 @ 0x08137B78

uint sub_08137B78(uint arg0,undefined4 arg1)

{
  uint uVar1;
  
  uVar1 = 0;
  for (; 6 < (ushort)arg1; arg1._0_2_ = (ushort)arg1 - 1) {
    uVar1 = uVar1 + ((arg0 & 0xffff) >> 3) & 0xffff;
  }
  return uVar1;
}


// sub_08137BA0 @ 0x08137BA0

uint sub_08137BA0(uint arg0,uint arg1)

{
  uint uVar1;
  
  uVar1 = sub_08137B78(arg0 & 0xffff,arg1 & 0xffff);
  return uVar1 & 0xffff;
}


// sub_08137BB8 @ 0x08137BB8

uint sub_08137BB8(void)

{
  uint uVar1;
  uint uVar2;
  int arg0;
  
  uVar1 = sub_0813E60C((uint)DAT_0203db7c,0x1a);
  uVar1 = uVar1 & 0xf;
  uVar2 = sub_0813E60C((uint)DAT_0203db7c,0);
  arg0 = (uVar2 & 0xff) * 4;
  if (uVar1 < 8) {
    uVar1 = uVar1 * arg0;
  }
  else {
    uVar1 = sub_08137BA0(arg0,uVar1);
    uVar1 = uVar1 & 0xffff;
  }
  return uVar1;
}


// sub_08137BF4 @ 0x08137BF4

void sub_08137BF4(void)

{
  uint uVar1;
  
  uVar1 = sub_08137BB8();
  uVar1 = sub_08137B1C(uVar1 & 0xffff);
  DAT_0203db2c = uVar1 & 0xffff;
  sub_080C3114(DAT_0203db2c);
  sub_0813B328(0x24);
  return;
}


// sub_08137C20 @ 0x08137C20

void sub_08137C20(void)

{
  DAT_0203db50 = 0xdb;
  sub_0813B328(0x25);
  return;
}


// sub_08137C38 @ 0x08137C38

void sub_08137C38(void)

{
  sub_0813B328(0x27);
  return;
}


// sub_08137C44 @ 0x08137C44

void sub_08137C44(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = sub_0813E60C((uint)DAT_0203db7c,0x19);
  if ((uVar1 & 0xff) != 0xff) {
    DAT_0203db50 = (ushort)(uVar1 & 0xff);
    uVar1 = sub_0813E60C((uint)DAT_0203db7c,0x1d);
    uVar1 = (uVar1 & 1) * 0x100 + (uint)DAT_0203db50;
    DAT_0203db50 = (ushort)uVar1;
    if (uVar1 * 0x10000 < 0x11f0001) {
      uVar1 = sub_080C32FC(uVar1 & 0xffff);
      if ((uVar1 & 0xff) != 1) {
        sub_080C3328((uint)DAT_0203db50);
        goto LAB_08137ca8;
      }
    }
    else {
      iVar2 = sub_0813B268();
      if (iVar2 != 0) {
LAB_08137ca8:
        sub_0813B328(0x26);
        return;
      }
    }
  }
  sub_08137C38();
  return;
}


// sub_08137CB4 @ 0x08137CB4

void sub_08137CB4(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = sub_080C2244();
  uVar1 = __umodsi3(uVar1,0xc);
  DAT_0203db50 = (short)uVar1 + 0x120;
  iVar2 = sub_0813B268();
  if (iVar2 == 0) {
    sub_08137C44();
  }
  else {
    sub_0813B328(0x26);
  }
  return;
}


// sub_08137CEC @ 0x08137CEC

void sub_08137CEC(void)

{
  uint uVar1;
  
  DAT_0203db50 = 0xe5;
  uVar1 = sub_080C32FC(0xe5);
  if ((uVar1 & 0xff) == 0) {
    sub_080C3328((uint)DAT_0203db50);
    sub_0813B328(0x26);
  }
  else {
    sub_08137CB4();
  }
  return;
}


// sub_08137D20 @ 0x08137D20

void sub_08137D20(void)

{
  sub_0813B328(0x28);
  return;
}


// sub_08137D2C @ 0x08137D2C

uint sub_08137D2C(void)

{
  uint uVar1;
  uint arg0;
  uint uVar2;
  
  arg0 = 0;
  uVar1 = sub_0813E60C((uint)DAT_0203db7c,0x18);
  uVar2 = (uVar1 & 0xf0) >> 4;
  uVar1 = sub_0813E60C((uint)DAT_0203db7c,0);
  uVar1 = uVar1 & 0xff;
  if (7 < uVar2) {
    arg0 = (uVar2 - 7) * (uVar1 >> 1);
  }
  uVar2 = sub_080C0F8C(0);
  if ((int)(short)uVar2 < (int)uVar1) {
    uVar1 = uVar1 - (uVar2 & 0xffff);
    if (3 < (uVar1 & 0xffff)) {
      uVar1 = (uVar1 & 0xffff) >> 2;
      if (5 < uVar1) {
        uVar1 = 5;
      }
      uVar2 = 0;
      if (uVar1 != 0) {
        do {
          arg0 = arg0 << 1;
          if ((arg0 & 0x8000) != 0) {
            return arg0;
          }
          uVar2 = uVar2 + 1 & 0xffff;
        } while (uVar2 < uVar1);
      }
    }
  }
  else {
    uVar1 = (uVar2 & 0xffff) - uVar1;
    if (3 < (uVar1 & 0xffff)) {
      arg0 = __udivsi3(arg0,(uVar1 & 0xffff) >> 2);
    }
  }
  return arg0;
}


// sub_08137DC8 @ 0x08137DC8

void sub_08137DC8(void)

{
  uint uVar1;
  int iVar2;
  dword dVar3;
  
  uVar1 = sub_08137D2C();
  uVar1 = sub_08137B1C(uVar1 & 0xffff);
  DAT_0203db2c = (uVar1 & 0xffff) >> 1;
  iVar2 = sub_080F2F64(0x8000);
  dVar3 = *(int *)(iVar2 + 8) + DAT_0203db2c;
  if (0x1994d4 < dVar3) {
    dVar3 = 0x1994d4;
  }
  iVar2 = sub_080F2F64(0x8000);
  *(dword *)(iVar2 + 8) = dVar3;
  sub_0813B328(0x2b);
  return;
}


// sub_08137E14 @ 0x08137E14

void sub_08137E14(void)

{
  uint uVar1;
  int iVar2;
  undefined4 arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_0813E60C((uint)DAT_0203db7c,0x1f);
  if (((uVar1 & 0xf0) == 0x20) || ((uVar1 & 0xf0) == 0x60)) {
    sub_0813B328(0x2a);
  }
  else {
    iVar2 = sub_080C09B0(1);
    if ((iVar2 != 0) || (iVar2 = sub_080C09B0(2), iVar2 != 0)) {
      iVar2 = sub_080C09B0(1);
      if (iVar2 == 0) {
        arg0 = 2;
      }
      else {
        arg0 = 1;
      }
      uVar1 = sub_080C0818(arg0);
      if ((uVar1 & 0xb000) == 0) {
        sub_0813B328(0x29);
        goto LAB_08137e78;
      }
    }
    sub_08137DC8();
  }
LAB_08137e78:
                    /* WARNING: Could not recover jumptable at 0x08137e7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08137E7C @ 0x08137E7C

void sub_08137E7C(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = sub_080C104C();
  for (uVar5 = 0; (int)uVar5 < iVar2 + 4; uVar5 = uVar5 + 1 & 0xffff) {
    iVar3 = sub_080C09B0(uVar5);
    if ((iVar3 != 0) && (uVar4 = sub_080C0818(uVar5), (uVar4 & 0x8000) == 0)) {
      uVar4 = uVar5 + 0x8000 & 0xffff;
      iVar3 = sub_080F2F64(uVar4);
      uVar1 = *(ushort *)(iVar3 + 0x1a);
      iVar3 = sub_080F2F64(uVar4);
      if ((int)*(short *)(iVar3 + 0x18) <= (int)((int)((uint)uVar1 << 0x10) >> 0x11 & 0xffffU)) {
        iVar2 = sub_080F2F64(uVar4);
        iVar3 = sub_080F2F64(uVar4);
        *(undefined2 *)(iVar2 + 0x18) = *(undefined2 *)(iVar3 + 0x1a);
        goto LAB_08137fbe;
      }
    }
  }
  uVar5 = 0;
  iVar2 = iVar2 + 4;
  if (0 < iVar2) {
    do {
      iVar3 = sub_080C09B0(uVar5);
      if (((iVar3 != 0) && (uVar4 = sub_080C0818(uVar5), (uVar4 & 0xc000) == 0)) &&
         ((uVar4 & 0x3ffe) != 0)) {
        iVar2 = sub_080F2F64(uVar5 + 0x8000 & 0xffff);
        *(ushort *)(iVar2 + 0x10) = *(ushort *)(iVar2 + 0x10) & 0xc001;
        goto LAB_08137fbe;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while ((int)uVar5 < iVar2);
  }
  uVar5 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = sub_080C09B0(uVar5);
      if ((iVar3 != 0) && (uVar4 = sub_080C0818(uVar5), (uVar4 & 0x8000) == 0)) {
        uVar4 = uVar5 + 0x8000 & 0xffff;
        iVar3 = sub_080F2F64(uVar4);
        if (*(short *)(iVar3 + 0x1e) != 0) {
          iVar3 = sub_080F2F64(uVar4);
          uVar1 = *(ushort *)(iVar3 + 0x1e);
          iVar3 = sub_080F2F64(uVar4);
          if ((int)*(short *)(iVar3 + 0x1c) <= (int)((int)((uint)uVar1 << 0x10) >> 0x11 & 0xffffU))
          {
            iVar2 = sub_080F2F64(uVar4);
            iVar3 = sub_080F2F64(uVar4);
            *(undefined2 *)(iVar2 + 0x1c) = *(undefined2 *)(iVar3 + 0x1e);
LAB_08137fbe:
            sub_0813B328(0x2c);
            return;
          }
        }
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while ((int)uVar5 < iVar2);
  }
  sub_08137B4C();
  return;
}


// sub_08137FCC @ 0x08137FCC

void sub_08137FCC(undefined4 arg0)

{
  undefined1 uVar1;
  
  uVar1 = DAT_0300685c;
  switch((undefined2)arg0) {
  case 0:
    sub_08137E7C();
    break;
  case 1:
    sub_08137B4C();
    break;
  case 2:
    sub_08137BF4();
    break;
  case 3:
    sub_08137C20();
    break;
  case 4:
    sub_08137CEC();
    break;
  case 5:
    sub_08137CB4();
    break;
  case 6:
    sub_08137C44();
    break;
  case 7:
    sub_08137C38();
    break;
  case 8:
    sub_08137D20();
    break;
  case 9:
    sub_08137E14();
    break;
  case 10:
    sub_08137DC8();
  }
  DAT_0300685c = uVar1;
  sub_0815BAC8((uint)DAT_0203db7c,1);
  return;
}


// sub_08138074 @ 0x08138074

void sub_08138074(void)

{
  uint uVar1;
  uint arg0;
  byte local_c;
  undefined1 auStack_b [3];
  
  sub_0815B9B8((uint)DAT_0203db7c,&local_c,auStack_b);
  uVar1 = sub_080C2244();
  for (arg0 = (uint)local_c * 0xb; (uint)*(byte *)(arg0 + 0x8790458) < (uVar1 & 0xff);
      arg0 = arg0 + 1 & 0xffff) {
  }
  uVar1 = __umodsi3(arg0,0xb);
  sub_08137FCC(uVar1 & 0xffff);
  return;
}


// sub_081380CC @ 0x081380CC

void sub_081380CC(uint arg0)

{
  sub_08137FCC(arg0 & 0xffff);
  return;
}


// ScriptOp_3D7 @ 0x081380DC

void ScriptOp_3D7(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = DAT_0203db40 + 1;
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar2 = DAT_0203db40 + 2;
  DAT_0203db40 = DAT_0203db40 + 3;
  DAT_03006840 = CONCAT22(*(undefined2 *)((uint)uVar2 * 2 + DAT_03006950),
                          *(undefined2 *)((uint)uVar3 * 2 + DAT_03006950));
  if (sVar1 == 0) {
    sub_08138074();
  }
  else if (sVar1 == 1) {
    sub_081380CC(1);
  }
  else if (sVar1 == 2) {
    sub_081380CC(2);
  }
  else if (sVar1 == 6) {
    sub_081380CC(6);
  }
                    /* WARNING: Could not recover jumptable at 0x08138152. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_3D8 @ 0x08138154

void ScriptOp_3D8(void)

{
  return;
}


// ScriptOp_3D9 @ 0x08138158

void ScriptOp_3D9(void)

{
  return;
}


// ScriptOp_3DA @ 0x0813815C

void ScriptOp_3DA(void)

{
  return;
}


// ScriptOp_3DB @ 0x08138160

void ScriptOp_3DB(void)

{
  return;
}


// ScriptOp_3DC @ 0x08138164

void ScriptOp_3DC(void)

{
  return;
}


// ScriptOp_3DD @ 0x08138168

void ScriptOp_3DD(void)

{
  return;
}


// ScriptOp_3DE @ 0x0813816C

void ScriptOp_3DE(void)

{
  return;
}


// ScriptOp_3DF @ 0x08138170

void ScriptOp_3DF(void)

{
  short sVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  if (sVar1 == 0xff) {
    sVar1 = -1;
    if (DAT_030068b4 < 2) {
      DAT_030068b4 = 0;
    }
    else {
      DAT_030068b4 = DAT_030068b4 - 1;
    }
  }
  else if (sVar1 == 0xfe) {
    sVar1 = -2;
    if (DAT_030068b4 < 3) {
      DAT_030068b4 = 0;
    }
    else {
      DAT_030068b4 = DAT_030068b4 - 2;
    }
  }
  else if (sVar1 == 0xfd) {
    sVar1 = -3;
    if (DAT_030068b4 < 4) {
      DAT_030068b4 = 0;
    }
    else {
      DAT_030068b4 = DAT_030068b4 - 3;
    }
  }
  else {
    DAT_030068b4 = DAT_030068b4 + (char)sVar1;
  }
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_080EFA20((int)sVar1);
  if ((DAT_030068b4 & 0x80) != 0) {
    DAT_030068b4 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x08138214. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0813821C @ 0x0813821C

void sub_0813821C(undefined4 arg0)

{
  if ((short)arg0 == 0xff) {
    arg0._0_2_ = -1;
    if (DAT_030069e8 < 2) {
      DAT_030069e8 = 0;
    }
    else {
      DAT_030069e8 = DAT_030069e8 - 1;
    }
  }
  else if ((short)arg0 == 0xfe) {
    arg0._0_2_ = -2;
    if (DAT_030069e8 < 3) {
      DAT_030069e8 = 0;
    }
    else {
      DAT_030069e8 = DAT_030069e8 - 2;
    }
  }
  else if ((short)arg0 == 0xfd) {
    arg0._0_2_ = -3;
    if (DAT_030069e8 < 4) {
      DAT_030069e8 = 0;
    }
    else {
      DAT_030069e8 = DAT_030069e8 - 3;
    }
  }
  else if ((short)arg0 == 0xfc) {
    arg0._0_2_ = -4;
    if (DAT_030069e8 < 5) {
      DAT_030069e8 = 0;
    }
    else {
      DAT_030069e8 = DAT_030069e8 - 4;
    }
  }
  else if ((short)arg0 == 0xfb) {
    arg0._0_2_ = -5;
    if (DAT_030069e8 < 6) {
      DAT_030069e8 = 0;
    }
    else {
      DAT_030069e8 = DAT_030069e8 - 5;
    }
  }
  else if ((short)arg0 == 0xfa) {
    arg0._0_2_ = -6;
    if (DAT_030069e8 < 7) {
      DAT_030069e8 = 0;
    }
    else {
      DAT_030069e8 = DAT_030069e8 - 6;
    }
  }
  else {
    DAT_030069e8 = DAT_030069e8 + (char)(short)arg0;
  }
  sub_080EFA44((int)(short)arg0);
  if ((DAT_030069e8 & 0x80) != 0) {
    DAT_030069e8 = 0;
  }
  return;
}


// ScriptOp_3E0 @ 0x08138310

void ScriptOp_3E0(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_0813821C((uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  return;
}


// sub_08138338 @ 0x08138338

uint sub_08138338(void)

{
  uint uVar1;
  
  uVar1 = sub_080C2244();
  return uVar1 & 3;
}


// ScriptOp_3E1 @ 0x08138350

void ScriptOp_3E1(void)

{
  uint uVar1;
  
  uVar1 = sub_08138338();
  uVar1 = (uVar1 & 0x7fff) * 2 + (uint)DAT_0203db40;
  DAT_0203db40 = (short)uVar1 + 1;
  DAT_030068e4 = CONCAT22(*(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950),
                          *(undefined2 *)((uVar1 & 0xffff) * 2 + DAT_03006950));
  return;
}


// sub_08138390 @ 0x08138390

void sub_08138390(uint arg0)

{
  uint uVar1;
  
  DAT_030068c4 = DAT_03006950;
  DAT_03006818 = DAT_0203db40;
  DAT_0203db64 = 1;
  uVar1 = (uint)(DAT_0300685c >> 4);
  if (uVar1 == 0) {
    DAT_03006950 = 0x803473c;
  }
  else if (uVar1 == 1) {
    DAT_03006950 = 0x8033560;
  }
  else if (uVar1 == 2) {
    DAT_03006950 = 0x8032de0;
  }
  else if (uVar1 == 3) {
    DAT_03006950 = 0x80341ec;
  }
  else if (uVar1 == 4) {
    DAT_03006950 = 0x803473c;
  }
  else if (uVar1 == 5) {
    DAT_03006950 = 0x8033560;
  }
  else if (uVar1 == 6) {
    DAT_03006950 = 0x8032de0;
  }
  else if (uVar1 == 7) {
    DAT_03006950 = 0x80341ec;
  }
  else if (uVar1 == 8) {
    DAT_03006950 = 0x8034094;
  }
  else if (uVar1 == 9) {
    DAT_03006950 = 0x803526c;
  }
  else if (uVar1 == 10) {
    DAT_03006950 = 0x80340b8;
  }
  else {
    DAT_03006950 = 0x8034138;
  }
  DAT_030068e4 = *(undefined4 *)
                  (((DAT_0300685c & 0xf) +
                    (uint)*(ushort *)(uVar1 * 2 + 0x87904f2) * (arg0 & 0xffff) & 0x7fff) * 4 +
                  DAT_03006950);
  return;
}


// sub_0813848C @ 0x0813848C

void sub_0813848C(uint arg0)

{
  uint uVar1;
  
  DAT_030068c4 = DAT_03006950;
  DAT_03006818 = DAT_0203db40;
  DAT_0203db64 = 1;
  uVar1 = (uint)(DAT_0300685c >> 4);
  if (uVar1 == 0) {
    DAT_03006950 = 0x80367f2;
  }
  else if (uVar1 == 1) {
    DAT_03006950 = 0x80366c2;
  }
  else if (uVar1 == 2) {
    DAT_03006950 = 0x80366c2;
  }
  else if (uVar1 == 3) {
    DAT_03006950 = 0x80367e2;
  }
  else if (uVar1 == 4) {
    DAT_03006950 = 0x80367f2;
  }
  else if (uVar1 == 5) {
    DAT_03006950 = 0x80366c2;
  }
  else if (uVar1 == 6) {
    DAT_03006950 = 0x80366c2;
  }
  else if (uVar1 == 7) {
    DAT_03006950 = 0x80367e2;
  }
  else if (uVar1 == 8) {
    DAT_03006950 = 0x80367e2;
  }
  else if (uVar1 == 9) {
    DAT_03006950 = 0x8037322;
  }
  else if (uVar1 == 10) {
    DAT_03006950 = 0x80367e2;
  }
  else {
    DAT_03006950 = 0x80367e2;
  }
  DAT_030068e4 = *(undefined4 *)
                  (((DAT_0300685c & 0xf) +
                    (uint)*(ushort *)(uVar1 * 2 + 0x87904f2) * (arg0 & 0xffff) & 0x7fff) * 4 +
                  DAT_03006950);
  return;
}


// ScriptOp_3E2_40F @ 0x08138588

void ScriptOp_3E2_40F(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_08138390((uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  return;
}


// ScriptOp_44C @ 0x081385D0

void ScriptOp_44C(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_08138390((uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  return;
}


