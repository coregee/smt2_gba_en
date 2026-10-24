/* Ghidra decompilation of asm/code_080D6264.s (reference only; not compiled). */

// sub_080D6264 @ 0x080D6264

void sub_080D6264(undefined4 arg0,uint arg1)

{
  sub_080C5170(arg1 & 0xffff);
  return;
}


// sub_080D6274 @ 0x080D6274

void sub_080D6274(int arg0,undefined4 arg1)

{
  dword arg0_00;
  uint uVar1;
  dword dVar2;
  undefined4 arg3;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack_14;
  
  dVar2 = 0x203a454;
  DAT_0203a458 = 0x14;
  DAT_0203a456 = (undefined2)DAT_0203bb68;
  DAT_0203a454 = (undefined2)arg1;
  switch((undefined2)arg1) {
  case 0:
    uStack_14 = 0;
    CpuSet(&uStack_14,0x200f874,0x5002000);
    break;
  case 1:
    dVar2 = 0x81b5dd4;
    goto LAB_080d66ba;
  case 3:
    DAT_03000040 = 0;
    DAT_03000004 = 0xffe8;
    DAT_03000006 = 0xfff0;
    if (DAT_0203bb68 == 0) {
      DAT_03000030 = 0xf0;
      DAT_03000031 = 0;
      DAT_03000034 = 0x3c;
      DAT_03000035 = 0;
      DAT_03000038 = 0x3d;
    }
    break;
  case 4:
    sub_080ACFCC(3,0x81b7110,0x30029b0,0x20);
    dVar2 = 0x81b7130;
    goto LAB_080d6748;
  case 5:
    uVar1 = sub_080AB184();
    if ((uVar1 & 0xffff) == 1) {
      *(short *)(arg0 + 0x1c) = (short)uVar1;
    }
    else {
      *(undefined2 *)(arg0 + 0x1c) = 0;
    }
    break;
  case 6:
    sub_080AAF48(1);
    break;
  case 100:
    dVar2 = 0x84f9cd0;
LAB_080d66ba:
    LZ77UnCompWram(dVar2,0x200f874,0x203a454);
    break;
  case 0x65:
    arg0_00 = 0x850485c;
    goto LAB_080d654e;
  case 0x67:
    sub_080ACFCC(3,0x84fa4e0,0x30029b0,0x20);
    dVar2 = 0x84fa500;
    arg3 = 0x120;
    goto LAB_080d674a;
  case 0x69:
    HuffUnComp(0x84fd060,0x2001000,0x203a454);
    goto LAB_080d6556;
  case 0x6b:
    sub_080ACFCC(3,0x84fa660,0x30029b0,0x200);
    dVar2 = 0x84fa500;
    arg3 = 0x200;
    goto LAB_080d674a;
  case 0x6c:
    HuffUnComp(0x85029cc,0x2001000,0x203a454);
    goto LAB_080d6556;
  case 0x6e:
    arg0_00 = 0x8508ac0;
LAB_080d654e:
    LZ77UnCompWram(arg0_00,0x2001000,0x203a454);
LAB_080d6556:
    RLUnCompWram(0x2001000,0x200f874,dVar2);
    break;
  case 0x6f:
    DAT_03000030 = 0xf0;
    DAT_03000031 = 0;
    DAT_03000034 = 0x96;
    DAT_03000035 = 0;
    DAT_03000038 = 0x3f;
    DAT_0300003a = 0x3f;
    break;
  case 0x70:
    arg3 = 0x200;
    sub_080ACFCC(3,0x84fa660,0x30029b0,0x200);
    dVar2 = 0x84fa620;
    goto LAB_080d674a;
  case 0x72:
    DAT_03000042._0_1_ = 0;
    DAT_03000042._1_1_ = 0x10;
    break;
  case 0x78:
    dVar2 = 0x81b6c30;
LAB_080d6748:
    arg3 = 0x40;
LAB_080d674a:
    sub_080ACFCC(3,dVar2,0x3002bb0,arg3);
    sub_080AAEDC(1);
    break;
  case 0x7f:
    DAT_0300003a = 0x3f;
    DAT_03000030 = 0xf0;
    DAT_03000031 = 0;
    DAT_03000035 = 0x78;
    DAT_03000034 = 0x9f;
    DAT_03000038 = 0x2f;
    sub_080ACFCC(3,0x84fa620,0x3002fb0,0x200);
    sub_080AABB0();
    DAT_03000040 = 0x2e50;
    DAT_03000042._0_1_ = 0;
    DAT_03000042._1_1_ = 0x10;
    break;
  case 0x80:
    DAT_03000040 = 0x3c42;
  }
  DisplayList_Add(0x80d5c21,1);
                    /* WARNING: Could not recover jumptable at 0x080d678e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D6794 @ 0x080D6794

void sub_080D6794(void)

{
  sub_080AA184(0x813ebd4,0,0,0);
  return;
}


// Intro_DrawDisclaimer @ 0x080D67BC

void Intro_DrawDisclaimer(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar1 = 0;
  uVar3 = 0;
  do {
    uVar4 = uVar3 + 1 & 0xffff;
    FontSprite_DrawGlyph((uint)*(ushort *)(uVar3 * 2 + 0x85096c4),0,0,uVar2);
    uVar2 = uVar2 + 0xd & 0xffff;
    uVar1 = uVar1 + 1;
    uVar3 = uVar4;
  } while (uVar1 < 0x11);
  uVar3 = 0xd;
  uVar1 = 0;
  do {
    uVar2 = uVar4 + 1 & 0xffff;
    FontSprite_DrawGlyph((uint)*(ushort *)(uVar4 * 2 + 0x85096c4),0,0,uVar3);
    uVar3 = uVar3 + 0xd & 0xffff;
    uVar1 = uVar1 + 1;
    uVar4 = uVar2;
  } while (uVar1 < 0x10);
  uVar3 = 8;
  uVar1 = 0;
  do {
    FontSprite_DrawGlyph((uint)*(ushort *)(uVar2 * 2 + 0x85096c4),0,0,uVar3);
    uVar3 = uVar3 + 0xd & 0xffff;
    uVar1 = uVar1 + 1;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar1 < 0x11);
  return;
}


// sub_080D686C @ 0x080D686C

void sub_080D686C(void)

{
  sub_080AA184(0x813ee88,0,0,0);
  sub_080AA184(0x813ee20,0,0,0);
  sub_080AA184(0x813ee3c,0,0,0);
  return;
}


// sub_080D68C8 @ 0x080D68C8

void sub_080D68C8(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  return;
}


// sub_080D68D0 @ 0x080D68D0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D68D0(int arg0)

{
  char cVar1;
  
  cVar1 = *(char *)(arg0 + 0x42) + -1;
  *(char *)(arg0 + 0x42) = cVar1;
  if (cVar1 == '\0') {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  if (_DAT_0203a464 == 1) {
    _DAT_0203a464 = 0;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080D6900 @ 0x080D6900

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D6900(int arg0)

{
  char cVar1;
  
  cVar1 = *(char *)(arg0 + 0x42) + -1;
  *(char *)(arg0 + 0x42) = cVar1;
  if (cVar1 == '\0') {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  if (_DAT_0203a464 == 1) {
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  return;
}


// sub_080D692C @ 0x080D692C

void sub_080D692C(undefined4 arg0,undefined4 arg1)

{
  DAT_03000034 = DAT_03000034 - (char)arg1;
  return;
}


// sub_080D693C @ 0x080D693C

void sub_080D693C(void)

{
  sub_080AA184(0x813ee88,0,0,0);
  DAT_0203a458 = DAT_0203a458 + -1;
  if (DAT_0203a458 == 0) {
    DAT_0203a458 = 0x14;
    DAT_0203a45a = DAT_0203a45a + 1 & 1;
  }
  if (DAT_0203a45a == 0) {
    sub_080AA184(0x80017a4,0,0,0);
  }
  sub_080AA184(0x813ee20,0,0,0);
  sub_080AA184(0x813ee3c,0,0,0);
  return;
}


// sub_080D69D8 @ 0x080D69D8

void sub_080D69D8(void)

{
  sub_080AA184(0x813ee88,0,0,0);
  sub_080AA184(0x813ee20,0,0,0);
  sub_080AA184(0x813ee3c,0,0,0);
  return;
}


// sub_080D6A34 @ 0x080D6A34

undefined4 sub_080D6A34(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = sub_080C2A84(0);
  if ((((uVar1 & 0xffff) == 1) || (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 1)) ||
     (uVar1 = sub_080C2A84(2), (uVar1 & 0xffff) == 1)) {
LAB_080d6a60:
    uVar2 = 1;
  }
  else {
    uVar1 = 0;
    do {
      iVar3 = sub_080C2644(uVar1);
      if (iVar3 != 0) goto LAB_080d6a60;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x17c);
    uVar1 = 0;
    do {
      iVar3 = sub_080C2734(uVar1 + 300);
      if (iVar3 != 0) goto LAB_080d6a60;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x40);
    uVar2 = 0;
  }
  return uVar2;
}


// sub_080D6A9C @ 0x080D6A9C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D6A9C(void)

{
  int iVar1;
  
  sub_080AA184(0x813ee88,0,0,0);
  sub_080AA184(0x813ed6c,0,0,0);
  if (_DAT_0203a45c == 1) {
    sub_080AA184(0x813ed84,0,0,0);
  }
  else {
    sub_080AA184(0x813edf0,0,0,0);
  }
  if (DAT_0203a45e == 1) {
    sub_080AA184(0x813ed9c,0,0,0);
  }
  else {
    sub_080AA184(0x813ee08,0,0,0);
  }
  iVar1 = sub_080D6A34();
  if (iVar1 == 1) {
    sub_080AA184(0x813edc0,0,0,0);
    sub_080AA184(0x813edd8,0,0,0);
  }
  else {
    sub_080AA184(0x813edd8,0,0,0);
  }
  sub_080AA184(0x813ee20,0,0,0);
  sub_080AA184(0x813ee3c,0,0,0);
  switch(DAT_0203a456) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    sub_080AA184(0x813ee58,1,0,0);
  default:
    goto switchD_080d6be6_default;
  }
  sub_080AA184(0x813ee58,1,0,0);
switchD_080d6be6_default:
  return;
}


// sub_080D6C8C @ 0x080D6C8C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D6C8C(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  DAT_0203a460._0_2_ = (short)DAT_0203a460 + -1;
  if ((short)DAT_0203a460 == 0) {
    *(undefined2 *)(arg0 + 0x1e) = 2;
  }
  else if ((DAT_030031b8 & (ushort)0x3ff) != 0) {
    *(undefined2 *)(arg0 + 0x1e) = 1;
    sub_080C51D4(0x65);
    if (DAT_0203a45e == 1) {
      DAT_0203a456 = 2;
    }
    else if (_DAT_0203a45c == 1) {
      DAT_0203a456 = _DAT_0203a45c;
    }
    else {
      DAT_0203a456 = 0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080d6ce8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D6CEC @ 0x080D6CEC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D6CEC(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar4 = 5;
  iVar3 = sub_080D6A34();
  if (iVar3 == 0) {
    iVar4 = 4;
  }
  *(undefined2 *)(arg0 + 0x1e) = 0;
  DAT_0203a460._0_2_ = (short)DAT_0203a460 + -1;
  if ((short)DAT_0203a460 == 0) {
    *(undefined2 *)(arg0 + 0x1e) = 0x80;
    uVar2 = DAT_0203a456;
  }
  else {
    uVar2 = DAT_0203a456;
    if ((DAT_030031b8 & 1) == 0) {
      if ((DAT_030031b8 & 2) == 0) {
        uVar1 = DAT_030031b8 & 0x40;
        if ((DAT_030031b8 & 0x40) == 0) {
          if ((DAT_030031b8 & 0x80) != 0) {
            DAT_0203a460._0_2_ = 900;
            sub_080C51D4(100);
            uVar2 = uVar1;
            if ((uint)DAT_0203a456 != iVar4 - 1U) {
              uVar2 = DAT_0203a456 + 1;
            }
          }
        }
        else {
          DAT_0203a460._0_2_ = 900;
          sub_080C51D4(100);
          if (DAT_0203a456 == 0) {
            uVar2 = (short)iVar4 - 1;
          }
          else {
            uVar2 = DAT_0203a456 - 1;
          }
        }
      }
      else {
        *(undefined2 *)(arg0 + 0x1e) = 10;
        sub_080C51D4(0x66);
        uVar2 = DAT_0203a456;
      }
    }
    else if (((DAT_0203a456 != 2) || (DAT_0203a45e != 0)) &&
            ((DAT_0203a456 != 1 || (_DAT_0203a45c != 0)))) {
      *(ushort *)(arg0 + 0x1e) = DAT_0203a456 + 1;
      iVar3 = sub_080D6A34();
      if ((iVar3 == 0) && (*(short *)(arg0 + 0x1e) == 4)) {
        *(undefined2 *)(arg0 + 0x1e) = 5;
      }
      sub_080C51D4(0x65);
      uVar2 = DAT_0203a456;
    }
  }
  DAT_0203a456 = uVar2;
                    /* WARNING: Could not recover jumptable at 0x080d6dcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D6DD0 @ 0x080D6DD0

void sub_080D6DD0(void)

{
  sub_080C10F4();
  sub_080B70BC(0,0,2,6);
  return;
}


// sub_080D6DF0 @ 0x080D6DF0

void sub_080D6DF0(void)

{
  sub_080D110C(0,0);
  return;
}


// sub_080D6E00 @ 0x080D6E00

void sub_080D6E00(void)

{
  sub_080D110C(1,0);
  return;
}


// sub_080D6E10 @ 0x080D6E10

void sub_080D6E10(void)

{
  sub_080A9AB4(0x80ddedd);
  return;
}


// sub_080D6E20 @ 0x080D6E20

void sub_080D6E20(void)

{
  sub_080CFFE0(0);
  return;
}


// sub_080D6E2C @ 0x080D6E2C

void sub_080D6E2C(void)

{
  DAT_0203bb68 = (uint)DAT_0203a456;
  return;
}


// sub_080D6E40 @ 0x080D6E40

void sub_080D6E40(void)

{
  sub_080C51BC(8);
  return;
}


// sub_080D6E4C @ 0x080D6E4C

void sub_080D6E4C(undefined4 arg0,int arg1)

{
  dword arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 1) {
    arg0_00 = 0x80c1329;
  }
  else {
    if (arg1 != 0) {
      if (arg1 == 2) {
        sub_080C1384();
      }
      goto LAB_080d6e78;
    }
    arg0_00 = 0x80c1451;
  }
  DisplayList_Add(arg0_00,1);
LAB_080d6e78:
                    /* WARNING: Could not recover jumptable at 0x080d6e7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D6E7C @ 0x080D6E7C

void sub_080D6E7C(void)

{
  DAT_0203a460._0_2_ = 900;
  return;
}


// sub_080D6E8C @ 0x080D6E8C

void sub_080D6E8C(void)

{
  return;
}


// sub_080D6E90 @ 0x080D6E90

void sub_080D6E90(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  DAT_0203a460._2_2_ = 0;
  return;
}


// sub_080D6EA0 @ 0x080D6EA0

void sub_080D6EA0(int arg0)

{
  char cVar1;
  char *pcVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  cVar1 = *(char *)(arg0 + 0x25);
  if (cVar1 == '\0') {
    if ((DAT_030031b8 & 8) == 0) {
      pcVar2 = (char *)(arg0 + 0x26);
      if (*pcVar2 == '\0') {
        *pcVar2 = '\x03';
        *(char *)(arg0 + 0x24) = *(char *)(arg0 + 0x24) + -1;
      }
      else {
        *pcVar2 = *pcVar2 + -1;
      }
      if (*(char *)(arg0 + 0x24) == '\0') {
        *(undefined2 *)(arg0 + 0x1c) = 1;
      }
      else {
        sub_080AA184(0x813ec98,0,0,0);
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 1;
    }
  }
  else {
    *(char *)(arg0 + 0x25) = cVar1 + -1;
  }
                    /* WARNING: Could not recover jumptable at 0x080d6f20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D6F2C @ 0x080D6F2C

void sub_080D6F2C(int arg0)

{
  DAT_03000030 = 0xf0;
  DAT_03000031 = 0;
  DAT_03000034 = 0x96;
  DAT_03000035 = 0x70;
  DAT_0300003a = DAT_0300003a & 0xef;
  *(undefined1 *)(arg0 + 0x24) = 0xa0;
  *(undefined1 *)(arg0 + 0x26) = 3;
  *(undefined1 *)(arg0 + 0x25) = 8;
  *(undefined1 *)(arg0 + 0x27) = 1;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined1 *)(arg0 + 0x28) = 0;
  *(undefined1 *)(arg0 + 0x29) = 0;
  return;
}


// sub_080D6F90 @ 0x080D6F90

void sub_080D6F90(int arg0)

{
  char cVar1;
  char *pcVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((DAT_030031b8 & 8) == 0) {
    cVar1 = *(char *)(arg0 + 0x25);
    if (cVar1 == '\0') {
      pcVar2 = (char *)(arg0 + 0x26);
      if (*pcVar2 == '\0') {
        *pcVar2 = '\x03';
        *(char *)(arg0 + 0x24) = *(char *)(arg0 + 0x24) + -1;
        cVar1 = *(char *)(arg0 + 0x28);
        if (cVar1 == -1) {
          cVar1 = *(char *)(arg0 + 0x29) + '\x01';
          *(char *)(arg0 + 0x29) = cVar1;
          if (cVar1 == '@') {
            *(undefined2 *)(arg0 + 0x1c) = 1;
            goto LAB_080d7096;
          }
        }
        else {
          *(char *)(arg0 + 0x28) = cVar1 + '\x01';
        }
      }
      else {
        *pcVar2 = *pcVar2 + -1;
      }
      if (-1 < (char)*(byte *)(arg0 + 0x28)) {
        sub_080AA184(0x813ecb4,0,0,0);
      }
      sub_080AA184(0x813ecd0,0,0,0);
      if (0x40 < *(byte *)(arg0 + 0x28)) {
        sub_080AA184(0x813ecec,0,0,0);
        sub_080AA184(0x813ed2c,0,0,0);
      }
    }
    else {
      *(char *)(arg0 + 0x25) = cVar1 + -1;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
LAB_080d7096:
                    /* WARNING: Could not recover jumptable at 0x080d70a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D70B4 @ 0x080D70B4

void sub_080D70B4(int arg0)

{
  DAT_03000004 = 0;
  DAT_03000008 = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  return;
}


// sub_080D70CC @ 0x080D70CC

void sub_080D70CC(int arg0)

{
  if ((DAT_030031b8 & 1) != 0) {
    DAT_03000042._0_1_ = (byte)DAT_03000042 + 1 & 0x1f;
  }
  if ((DAT_030031b8 & 2) != 0) {
    DAT_03000042._0_1_ = (byte)DAT_03000042 - 1 & 0x1f;
  }
  if ((DAT_030031b8 & 0x100) != 0) {
    DAT_03000042._1_1_ = DAT_03000042._1_1_ + 1 & 0x1f;
  }
  if ((DAT_030031b8 & 0x200) != 0) {
    DAT_03000042._1_1_ = DAT_03000042._1_1_ - 1 & 0x1f;
  }
  if ((DAT_030031d0 & 0x20) != 0) {
    DAT_03000004 = DAT_03000004 + 1 & 0xff;
  }
  if ((DAT_030031d0 & 0x10) != 0) {
    DAT_03000004 = DAT_03000004 - 1 & 0xff;
  }
  if ((DAT_030031b8 & 8) != 0) {
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  return;
}


// sub_080D7184 @ 0x080D7184

void sub_080D7184(void)

{
  DAT_03000030 = 0xf0;
  DAT_03000031 = 0;
  DAT_03000034 = 0xa0;
  DAT_03000035 = 0;
  DAT_0300003a = 0x3f;
  DAT_0300000c = 0;
  DAT_03000008 = 0;
  DAT_03000004 = 0;
  if (*DAT_03006968 != 0) {
    sub_080AD1FC(DAT_03006968);
  }
  if (*DAT_03006954 != 0) {
    sub_080AD1FC(DAT_03006954);
  }
  if (*DAT_03006938 != 0) {
    sub_080AD1FC(DAT_03006938);
  }
  DAT_0203a460._2_2_ = 1;
  return;
}


// sub_080D721C @ 0x080D721C

void sub_080D721C(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined1 *)(arg0 + 0x25) = 0;
  *(undefined1 *)(arg0 + 0x26) = 0;
  return;
}


// sub_080D7230 @ 0x080D7230

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D7230(int arg0)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  char *pcVar4;
  
  pcVar4 = (char *)(arg0 + 0x25);
  cVar1 = *pcVar4;
  *pcVar4 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x1e') {
    *pcVar4 = '\0';
    pbVar3 = (byte *)(arg0 + 0x26);
    bVar2 = *pbVar3;
    *pbVar3 = bVar2 + 1;
    DAT_03000042._0_1_ = (undefined1)*(undefined2 *)((uint)*pbVar3 * 4 + 0x8509680);
    DAT_03000042._1_1_ = (undefined1)*(undefined2 *)(((uint)*pbVar3 * 2 + 1) * 2 + 0x8509680);
    if ((byte)(bVar2 + 1) == 0x10) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  if (_DAT_0203a464 == 1) {
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  return;
}


// sub_080D72A4 @ 0x080D72A4

void sub_080D72A4(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined1 *)(arg0 + 0x25) = 0;
  *(undefined1 *)(arg0 + 0x26) = 0;
  *(undefined1 *)(arg0 + 0x27) = 0;
  *(undefined1 *)(arg0 + 0x28) = 0;
  return;
}


// sub_080D72C0 @ 0x080D72C0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D72C0(int arg0)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  char *pcVar4;
  
  pcVar4 = (char *)(arg0 + 0x25);
  cVar1 = *pcVar4;
  *pcVar4 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x10') {
    *pcVar4 = '\0';
    pbVar3 = (byte *)(arg0 + 0x26);
    bVar2 = *pbVar3;
    *pbVar3 = bVar2 + 1;
    DAT_03000042._0_1_ = (undefined1)*(undefined2 *)((uint)*pbVar3 * 4 + 0x8509680);
    DAT_03000042._1_1_ = (undefined1)*(undefined2 *)(((uint)*pbVar3 * 2 + 1) * 2 + 0x8509680);
    if ((byte)(bVar2 + 1) == 0x10) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  if (_DAT_0203a464 == 1) {
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  return;
}


// sub_080D7334 @ 0x080D7334

void sub_080D7334(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined1 *)(arg0 + 0x24) = 0;
  *(undefined1 *)(arg0 + 0x25) = 0;
  return;
}


// sub_080D7348 @ 0x080D7348

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D7348(int arg0)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(arg0 + 0x25);
  cVar1 = *pcVar2;
  *pcVar2 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\n') {
    *pcVar2 = '\0';
    cVar1 = *(char *)(arg0 + 0x24) + '\x01';
    *(char *)(arg0 + 0x24) = cVar1;
    DAT_03000034 = -0x61 - cVar1;
    if (cVar1 == '\x10') {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  if (_DAT_0203a464 == 1) {
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  return;
}


// sub_080D739C @ 0x080D739C

void sub_080D739C(int arg0)

{
  DAT_03000032 = 100;
  DAT_03000033 = 0;
  DAT_03000036 = 0x6c;
  DAT_03000037 = 0;
  DAT_03000039 = 0x3f;
  *(undefined1 *)(arg0 + 0x24) = 100;
  *(undefined1 *)(arg0 + 0x26) = 5;
  *(undefined1 *)(arg0 + 0x25) = 8;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  return;
}


// sub_080D73EC @ 0x080D73EC

void sub_080D73EC(int arg0)

{
  char cVar1;
  char *pcVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  cVar1 = *(char *)(arg0 + 0x25);
  if (cVar1 == '\0') {
    pcVar2 = (char *)(arg0 + 0x26);
    if (*pcVar2 == '\0') {
      *pcVar2 = '\x05';
      *(char *)(arg0 + 0x24) = *(char *)(arg0 + 0x24) + -1;
      DAT_03000032 = DAT_03000032 + -1;
    }
    else {
      *pcVar2 = *pcVar2 + -1;
    }
    if (*(char *)(arg0 + 0x24) == '\0') {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      goto LAB_080d7466;
    }
  }
  else {
    *(char *)(arg0 + 0x25) = cVar1 + -1;
  }
  sub_080AA184(0x813ec98,0,0,0);
LAB_080d7466:
                    /* WARNING: Could not recover jumptable at 0x080d746a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D7474 @ 0x080D7474

void sub_080D7474(int arg0)

{
  DAT_03000030 = 0xf0;
  DAT_03000031 = 0;
  DAT_03000034 = 0x96;
  DAT_03000035 = 0x70;
  DAT_0300003a = DAT_0300003a & 0xef;
  *(undefined1 *)(arg0 + 0x24) = 0xa0;
  *(undefined1 *)(arg0 + 0x26) = 6;
  *(undefined1 *)(arg0 + 0x25) = 0xf0;
  *(undefined1 *)(arg0 + 0x27) = 0x78;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined1 *)(arg0 + 0x30) = 0;
  *(undefined1 *)(arg0 + 0x31) = 0;
  return;
}


// sub_080D74D8 @ 0x080D74D8

void sub_080D74D8(int arg0)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = (uint)CONCAT11(*(undefined1 *)(arg0 + 0x30),*(undefined1 *)(arg0 + 0x31));
  pcVar2 = (char *)(arg0 + 0x25);
  cVar1 = *pcVar2;
  if (cVar1 == '\0') {
    pcVar2 = (char *)(arg0 + 0x27);
    cVar1 = *pcVar2;
    if (cVar1 == '\0') {
      pcVar2 = (char *)(arg0 + 0x26);
      if (*pcVar2 == '\0') {
        *pcVar2 = '\x06';
        uVar3 = uVar3 + 1 & 0xffff;
      }
      else {
        *pcVar2 = *pcVar2 + -1;
      }
      if (uVar3 < 0x80) {
        sub_080AA184(0x813ecb4,0,0,0);
      }
      if ((uVar3 - 0x40 & 0xffff) < 0x80) {
        sub_080AA184(0x813ecd0,0,0,0);
      }
      if ((uVar3 - 0x80 & 0xffff) < 0x80) {
        sub_080AA184(0x813ecec,0,0,0);
      }
      if ((uVar3 - 0xc0 & 0xffff) < 0x76) {
        sub_080AA184(0x813ed2c,0,0,0);
      }
      *(char *)(arg0 + 0x30) = (char)(uVar3 >> 8);
      *(char *)(arg0 + 0x31) = (char)uVar3;
      goto LAB_080d75d2;
    }
  }
  *pcVar2 = cVar1 + -1;
LAB_080d75d2:
                    /* WARNING: Could not recover jumptable at 0x080d75d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D75EC @ 0x080D75EC

void sub_080D75EC(int arg0)

{
  *(undefined1 *)(arg0 + 0x24) = 0x20;
  *(undefined1 *)(arg0 + 0x25) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  return;
}


// sub_080D7600 @ 0x080D7600

void sub_080D7600(int arg0)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(arg0 + 0x24);
  cVar1 = *pcVar2;
  *pcVar2 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    *pcVar2 = ' ';
    cVar1 = *(char *)(arg0 + 0x25) + '\x01';
    *(char *)(arg0 + 0x25) = cVar1;
    if (cVar1 == '\x18') {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    else {
      DAT_0300000c = DAT_0300000c + -1;
      DAT_03000008 = DAT_03000008 + -1;
      DAT_03000004 = DAT_03000004 + -1;
    }
  }
  return;
}


// sub_080D7658 @ 0x080D7658

void sub_080D7658(void)

{
  DAT_0203a460._2_2_ = 0;
  DAT_03006968 = sub_080AD0FC(0x8509764,0xffff);
  DAT_03006938 = sub_080AD0FC(0x85097a0,0xffff);
  DAT_03006954 = sub_080AD0FC(0x8509728,0xffff);
  sub_080AD0FC(0x85097dc,0xffff);
  return;
}


// sub_080D76B8 @ 0x080D76B8

void sub_080D76B8(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  return;
}


// sub_080D76C0 @ 0x080D76C0

void sub_080D76C0(int arg0)

{
  if (DAT_0203a460._2_2_ == 1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080D76D8 @ 0x080D76D8

void sub_080D76D8(void)

{
  if (*DAT_030069e4 != 0) {
    sub_080AD1FC(DAT_030069e4);
  }
  return;
}


// sub_080D76F4 @ 0x080D76F4

void sub_080D76F4(void)

{
  if (*DAT_030069e4 == 0) {
    DAT_030069e4 = (short *)sub_080AD0FC(0x8509cd0,0xffff);
  }
  return;
}


// sub_080D771C @ 0x080D771C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D771C(void)

{
  _DAT_0203a464 = 0;
  return;
}


// sub_080D7728 @ 0x080D7728

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D7728(void)

{
  if ((DAT_030031b8 & 8) != 0) {
    _DAT_0203a464 = 1;
  }
  return;
}


// sub_080D7748 @ 0x080D7748

void sub_080D7748(undefined4 arg0,int arg1)

{
  if (arg1 == 1) {
    sub_080AD150(DAT_030065f4);
  }
  else {
    sub_080AD174(DAT_030065f4);
  }
  return;
}


// sub_080D7764 @ 0x080D7764

void sub_080D7764(int arg0,int arg1,int arg2)

{
  int iVar1;
  int arg2_00;
  
  arg2_00 = arg2;
  iVar1 = sub_080D95F4((uint)*(ushort *)(arg0 + 0x2a));
  LZ77UnCompWram(*(undefined4 *)(iVar1 + 4 + arg2 * 4 + arg1 * 8),arg2 * 0x1000 + 0x2001000,arg2_00)
  ;
  return;
}


// sub_080D7794 @ 0x080D7794

void sub_080D7794(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D77B8 @ 0x080D77B8

void sub_080D77B8(void)

{
  DisplayList_Add(0x80d7795,1);
  return;
}


// sub_080D77CC @ 0x080D77CC

void sub_080D77CC(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080D95F4((uint)*(ushort *)(arg0 + 0x2a));
  sub_080C3F4C(arg0 + 0x24,*(undefined4 *)(iVar1 + 0x24),arg1,0x20);
  return;
}


// sub_080D77F4 @ 0x080D77F4

void sub_080D77F4(int arg0)

{
  *(undefined2 *)(arg0 + 0x28) = 1;
  return;
}


// sub_080D77FC @ 0x080D77FC

void sub_080D77FC(int arg0,int arg1,undefined4 arg2,int arg3)

{
  int in_stack_00000000;
  
  sub_080D95F4((uint)*(ushort *)(arg0 + 0x2a));
  sub_080C4080(arg0 + 0x24,*(undefined4 *)((arg3 * 2 + in_stack_00000000) * 4 + arg1),arg2,
               in_stack_00000000);
  return;
}


// sub_080D7840 @ 0x080D7840

void sub_080D7840(void)

{
  int arg0;
  int *piVar1;
  uint uVar2;
  uint unaff_r6;
  
  uVar2 = 0;
  piVar1 = (int *)0x2036094;
  do {
    arg0 = *piVar1;
    if ((arg0 != 0) && (*(ushort *)(arg0 + 0x2a) == unaff_r6)) {
      sub_080AD348(arg0);
    }
    piVar1 = piVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 6);
  return;
}


// sub_080D786C @ 0x080D786C

void sub_080D786C(void)

{
  undefined4 in_r0;
  
  sub_080C48F0(in_r0);
  return;
}


// sub_080D7878 @ 0x080D7878

void sub_080D7878(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D789C @ 0x080D789C

void sub_080D789C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001800;
  REG_DMA3DAD = 0x6016800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D78C0 @ 0x080D78C0

void sub_080D78C0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2002000;
  REG_DMA3DAD = 0x6017000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D78E4 @ 0x080D78E4

void sub_080D78E4(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2002800;
  REG_DMA3DAD = 0x6017800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D7908 @ 0x080D7908

void sub_080D7908(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2003000;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D792C @ 0x080D792C

void sub_080D792C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2003800;
  REG_DMA3DAD = 0x6015800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D7950 @ 0x080D7950

void sub_080D7950(int arg0,undefined4 arg1,int arg2)

{
  int iVar1;
  int arg2_00;
  undefined4 arg2_01;
  int iVar2;
  
  arg2_00 = arg2;
  iVar1 = sub_080D95F4((uint)*(ushort *)(arg0 + 6));
  if (*(short *)(arg0 + 4) != 0) {
    iVar2 = (uint)*(ushort *)(arg0 + 2) * 4;
    arg2_01 = *(undefined4 *)(iVar2 + 0x855fa84);
    LZ77UnCompWram(arg1,(uint)*(ushort *)(arg0 + 2) * 0x800 + 0x2001000,arg2_00);
    if (arg2 == 0) {
      sub_080C3F4C(arg0,*(undefined4 *)(iVar1 + 0x24),arg2_01,0x20);
    }
    DisplayList_Add(*(undefined4 *)(iVar2 + 0x855fa9c),1);
  }
  return;
}


// sub_080D79C0 @ 0x080D79C0

void sub_080D79C0(undefined4 arg0,undefined4 arg1,int arg2,int arg3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = sub_080AD364(arg0);
  iVar2 = sub_080D95F4((uint)*(ushort *)(iVar1 + 0x2a));
  sub_080D7950(iVar1 + 0x24,*(undefined4 *)(iVar2 + 4 + arg3 * 4 + arg2 * 8),arg1);
  return;
}


// sub_080D7A04 @ 0x080D7A04

void sub_080D7A04(int arg0)

{
  undefined2 uVar1;
  undefined4 arg0_00;
  int iVar2;
  
  arg0_00 = sub_080B2EFC(0,0);
  iVar2 = sub_080B3038(arg0_00,0x23);
  if (((DAT_03005180 == 1) || (iVar2 == 0)) || (*(short *)(iVar2 + 2) != 4)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
  return;
}


// sub_080D7A44 @ 0x080D7A44

void sub_080D7A44(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080D7A04(arg0);
  if (*(short *)(arg0 + 0x1c) == 0) {
    sub_080C41F4(arg0);
  }
  else if (*(short *)(arg0 + 0x28) != 0) {
    sub_080AB158((uint)*(ushort *)((uint)*(ushort *)(arg0 + 0x26) * 4 + 0x855fa84),0x10,1,1);
  }
                    /* WARNING: Could not recover jumptable at 0x080d7a7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D7A84 @ 0x080D7A84

void sub_080D7A84(int arg0,undefined4 arg1)

{
  short sVar1;
  uint uVar2;
  int arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg0 + 0x24;
  sVar1 = *(short *)(arg0 + 0x26);
  uVar2 = sub_080C4388(arg0_00);
  uVar2 = uVar2 & 0xffff;
  sub_080D7A04(arg0);
  if (*(short *)(arg0 + 0x1c) == 0) {
    if (sVar1 == 0) {
LAB_080d7af2:
      sub_080C44CC(arg0_00,arg1,uVar2,0xe);
      goto LAB_080d7ba2;
    }
    if (sVar1 != 1) {
LAB_080d7b36:
      sub_080C44CC(arg0_00,arg1,uVar2,0xd);
      goto LAB_080d7ba2;
    }
  }
  else {
    if (sVar1 == 0) goto LAB_080d7af2;
    if (sVar1 != 1) {
      if (sVar1 != 2) {
        if (sVar1 == 3) {
          sub_080C44CC(arg0_00,arg1,uVar2,0xc);
        }
        else if (sVar1 == 4) {
          sub_080C44CC(arg0_00,arg1,uVar2,0xb);
        }
        else {
          sub_080C44CC(arg0_00,arg1,uVar2,10);
        }
        goto LAB_080d7ba2;
      }
      goto LAB_080d7b36;
    }
  }
  sub_080C44CC(arg0_00,arg1,uVar2,0xf);
LAB_080d7ba2:
                    /* WARNING: Could not recover jumptable at 0x080d7bb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D7BB4 @ 0x080D7BB4

void sub_080D7BB4(void)

{
  undefined4 in_r0;
  
  sub_080D7A84(in_r0,0x80050c4);
  return;
}


// sub_080D7BC4 @ 0x080D7BC4

void sub_080D7BC4(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x2e) = (undefined2)arg1;
  return;
}


// sub_080D7BC8 @ 0x080D7BC8

void sub_080D7BC8(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080AD0FC(0x855fab4,(uint)*(ushort *)(arg0 + 2));
  *(undefined4 *)(arg0 + 0x44) = uVar1;
  return;
}


// sub_080D7BE4 @ 0x080D7BE4

void sub_080D7BE4(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080D95F4((uint)*(ushort *)(arg0 + 0x2a));
  iVar1 = *(int *)(iVar1 + 0x28);
  *(undefined2 *)(arg0 + 0x3e) = *(undefined2 *)(iVar1 + 0xc);
  if (*(short *)(iVar1 + 0x14) == 1) {
    sub_080D77FC(arg0,iVar1,0,0);
    sub_080D77FC(arg0,iVar1,0,0);
    if (*(ushort *)(iVar1 + 0x16) != 0) {
      sub_080C51D4((uint)*(ushort *)(iVar1 + 0x16));
    }
  }
  return;
}


// sub_080D7C30 @ 0x080D7C30

void sub_080D7C30(int arg0,int arg1)

{
  short sVar1;
  dword arg1_00;
  uint arg2;
  uint arg3;
  
  sVar1 = *(short *)(arg0 + 0x26);
  arg2 = (uint)*(ushort *)(arg1 + 0x10);
  arg3 = (uint)*(ushort *)(arg1 + 0x12);
  if (((arg2 == 0xffff) && (arg2 = 0x300, sVar1 != 0)) && (arg2 = 0x280, sVar1 == 1)) {
    arg2 = 0x380;
  }
  if (((arg3 == 0xffff) && (arg3 = 0xe, sVar1 != 0)) && (arg3 = 0xd, sVar1 == 1)) {
    arg3 = 0xf;
  }
  arg1_00 = *(dword *)(arg1 + 8);
  if (arg1_00 == 0x8004ff8) {
    arg1_00 = sub_080C43B4(arg0 + 0x24);
  }
  if (((ushort)(*(short *)(arg0 + 0x2a) - 0xaaU) < 2) || (*(short *)(arg0 + 0x2a) == 0xf5)) {
    *(undefined2 *)(arg0 + 0x34) = 1;
  }
  sub_080C43F8(arg0,arg1_00,arg2,arg3);
  return;
}


// sub_080D7CA8 @ 0x080D7CA8

void sub_080D7CA8(int arg0)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *arg1;
  
  iVar2 = sub_080D95F4((uint)*(ushort *)(arg0 + 0x2a));
  iVar3 = *(int *)(iVar2 + 0x28);
  sVar1 = *(short *)(arg0 + 0x3e) + -1;
  *(short *)(arg0 + 0x3e) = sVar1;
  if (sVar1 == 0) {
    *(short *)(arg0 + 0x3c) = *(short *)(arg0 + 0x3c) + 1;
    arg1 = (int *)(iVar3 + (uint)*(ushort *)(arg0 + 0x3c) * 0x18);
    if ((short)arg1[3] == -1) {
      sub_080C48F0(arg0);
    }
    else {
      if ((short)arg1[3] == -2) {
        *(undefined2 *)(arg0 + 0x3c) = 0;
        arg1 = *(int **)(iVar2 + 0x28);
      }
      *(short *)(arg0 + 0x3e) = (short)arg1[3];
      if ((*arg1 != 0) && ((short)arg1[5] == 1)) {
        sub_080D77FC(arg0,arg1,1,0);
        sub_080D77FC(arg0,arg1,1,0);
        if (*(ushort *)((int)arg1 + 0x16) != 0) {
          sub_080C51D4((uint)*(ushort *)((int)arg1 + 0x16));
        }
      }
      sub_080D7C30(arg0,arg1);
    }
  }
  else {
    sub_080D7C30(arg0,iVar3 + (uint)*(ushort *)(arg0 + 0x3c) * 0x18);
  }
  return;
}


// sub_080D7D60 @ 0x080D7D60

void sub_080D7D60(int arg0)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = arg0;
  REG_DMA3DAD = 0x6005c40;
  REG_DMA3CNT = 0x840000f0;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = arg0 + 0x3c0;
  REG_DMA3DAD = 0x6008040;
  REG_DMA3CNT = 0x84000370;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D7D98 @ 0x080D7D98

void sub_080D7D98(byte *arg0)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  REG_DMA3SAD = 0x81c25f4;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x84000400;
  uVar2 = REG_DMA3CNT;
  uVar3 = 0;
  do {
    uVar5 = 0;
    uVar6 = uVar3 + 1;
    iVar4 = uVar3 * 0x40 + 0x2000000;
    do {
      bVar1 = *arg0;
      arg0 = arg0 + 1;
      *(short *)(iVar4 + 0x202U) = ((bVar1 & 0xf) + 8) * 0x1000 + *(short *)(iVar4 + 0x202U);
      iVar4 = iVar4 + 2;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x1c);
    uVar3 = uVar6;
  } while (uVar6 < 5);
  REG_DMA3SAD = 0x2000200;
  REG_DMA3DAD = 0x6003200;
  REG_DMA3CNT = 0x84000050;
  uVar2 = REG_DMA3CNT;
  return;
}


// sub_080D7E2C @ 0x080D7E2C

void sub_080D7E2C(void)

{
  sub_080D7D60(0x855fba4);
  sub_080D7D98(0x8563024);
  return;
}


// sub_080D7E48 @ 0x080D7E48

void sub_080D7E48(void)

{
  sub_080D7D60(0x8560d24);
  sub_080D7D98(0x85630b0);
  return;
}


// sub_080D7E64 @ 0x080D7E64

void sub_080D7E64(void)

{
  sub_080D7D60(0x8561ea4);
  sub_080D7D98(0x856313c);
  return;
}


// sub_080D7E80 @ 0x080D7E80

void sub_080D7E80(int arg0)

{
  *(undefined4 *)(arg0 + 0x48) = 0;
  *(undefined4 *)(arg0 + 0x4c) = 8;
  return;
}


// sub_080D7E8C @ 0x080D7E8C

void sub_080D7E8C(int arg0)

{
  uint uVar1;
  int iVar2;
  dword arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080AB184();
  if ((((uVar1 & 0xffff) == 0) || (iVar2 = sub_080B098C(), iVar2 == 1)) ||
     (iVar2 = *(int *)(arg0 + 0x4c) + -1, *(int *)(arg0 + 0x4c) = iVar2, iVar2 != 0))
  goto LAB_080d7ef2;
  *(undefined4 *)(arg0 + 0x4c) = 8;
  iVar2 = *(int *)(arg0 + 0x48);
  if (iVar2 == 1) {
    arg0_00 = 0x80d7e49;
LAB_080d7ece:
    DisplayList_Add(arg0_00,1);
  }
  else {
    if (iVar2 == 0) {
      arg0_00 = 0x80d7e2d;
      goto LAB_080d7ece;
    }
    if (iVar2 == 2) {
      DisplayList_Add(0x80d7e65,1);
    }
  }
  uVar1 = *(int *)(arg0 + 0x48) + 1;
  *(uint *)(arg0 + 0x48) = uVar1;
  if (2 < uVar1) {
    *(undefined4 *)(arg0 + 0x48) = 0;
  }
LAB_080d7ef2:
                    /* WARNING: Could not recover jumptable at 0x080d7ef6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D7EFC @ 0x080D7EFC

void sub_080D7EFC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D7F20 @ 0x080D7F20

void sub_080D7F20(int arg0)

{
  undefined4 uVar1;
  undefined4 in_r2;
  
  LZ77UnCompWram(0x85632f4,0x2001000,in_r2);
  REG_DMA3SAD = 0x8563a5c;
  REG_DMA3DAD = 0x2001fc0;
  REG_DMA3CNT = 0x84000010;
  uVar1 = REG_DMA3CNT;
  sub_080ACFCC(3,0x8563ac0,0x3002d50,0x20);
  sub_080AB090(0x1d0,0x10,1,1);
  DisplayList_Add(0x80d7efd,1);
  *(undefined2 *)(arg0 + 0x2c) = 0;
  *(undefined2 *)(arg0 + 0x2e) = 0x18;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  return;
}


// sub_080D7FA0 @ 0x080D7FA0

void sub_080D7FA0(int arg0)

{
  sub_080AA184(0x8002c88,1,0xd,0);
  sub_080AA184(0x8002c70,1,0xd,0);
  if ((*(short *)(arg0 + 0x1e) != 0) && ((DAT_030031bc >> 4 & 1) == 0)) {
    if (*(short *)(arg0 + 0x1e) == 1) {
      sub_080AA184(0x8002cbc,1,0xd,0);
    }
    else {
      sub_080AA184(0x8002ccc,1,0xd,0);
    }
  }
  return;
}


// sub_080D8064 @ 0x080D8064

void sub_080D8064(int arg0,undefined4 arg1)

{
  *(short *)(arg0 + 0x2e) = *(short *)(arg0 + 0x2e) + (short)arg1;
  DAT_0300000e = DAT_0300000e - (short)arg1;
  return;
}


// sub_080D807C @ 0x080D807C

void sub_080D807C(int arg0)

{
  sub_080B29A8(0);
  *(undefined2 *)(arg0 + 0x2c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  return;
}


// sub_080D8098 @ 0x080D8098

void sub_080D8098(int arg0)

{
  *(short *)(arg0 + 0x2c) = *(short *)(arg0 + 0x2c) + 1;
  return;
}


// sub_080D80A4 @ 0x080D80A4

void sub_080D80A4(int arg0)

{
  *(undefined2 *)(arg0 + 0x1e) = 0;
  return;
}


// sub_080D80AC @ 0x080D80AC

void sub_080D80AC(void)

{
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x3f;
  return;
}


// sub_080D80C8 @ 0x080D80C8

void sub_080D80C8(int arg0)

{
  undefined4 uVar1;
  undefined4 in_r2;
  
  LZ77UnCompWram(0x8563bd8,0x2001000,in_r2);
  REG_DMA3SAD = 0x8564358;
  REG_DMA3DAD = 0x2001fc0;
  REG_DMA3CNT = 0x84000010;
  uVar1 = REG_DMA3CNT;
  sub_080ACFCC(3,0x85643bc,0x3002d50,0x20);
  sub_080AB090(0x1d0,0x10,1,1);
  DisplayList_Add(0x80d7efd,1);
  *(undefined2 *)(arg0 + 0x2c) = 0;
  *(undefined2 *)(arg0 + 0x2e) = 0x18;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  return;
}


// sub_080D8148 @ 0x080D8148

void sub_080D8148(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D816C @ 0x080D816C

void sub_080D816C(void)

{
  undefined4 in_r2;
  
  HuffUnComp(0x86bf890,0x200afc8,in_r2);
  LZ77UnCompWram(0x200afc8,0x2001000,in_r2);
  sub_080ACFA4(3,0x7fff,0x3003170,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80d8149,1);
  return;
}


// sub_080D81C0 @ 0x080D81C0

void sub_080D81C0(int arg0)

{
  uint uVar1;
  int arg0_00;
  
  arg0_00 = arg0 + 0x24;
  uVar1 = sub_080C4388(arg0_00);
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_080C44CC(arg0_00,0x8118cc4,uVar1 & 0xffff,0xe);
  }
  else {
    sub_080C44CC(arg0_00,0x8118ce0,uVar1 & 0xffff,0xe);
  }
  return;
}


