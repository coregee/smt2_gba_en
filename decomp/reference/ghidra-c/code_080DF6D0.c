/* Ghidra decompilation of asm/code_080DF6D0.s (reference only; not compiled). */

// sub_080DF6D0 @ 0x080DF6D0

uint sub_080DF6D0(undefined4 arg0,byte *arg1)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = 0;
  if ((ushort)arg0 != 0) {
    do {
      uVar2 = uVar2 + *arg1 & 0xffff;
      arg1 = arg1 + 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < (ushort)arg0);
  }
  return uVar2;
}


// sub_080DF6FC @ 0x080DF6FC

undefined4 sub_080DF6FC(undefined4 arg0)

{
  undefined4 uVar1;
  uint uVar2;
  char local_14 [4];
  
  uVar2 = 0;
  do {
    if ((uVar2 < 2) && (*(short *)(uVar2 * 0x10 + 0x3006340) != (short)arg0)) {
      local_14[uVar2] = '\0';
    }
    else {
      local_14[uVar2] = '\x01';
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  if ((local_14[0] == '\x01') && (local_14[1] == '\x01')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080DF760 @ 0x080DF760

void sub_080DF760(void)

{
  byte bVar1;
  undefined1 *puVar2;
  
  DAT_03006380 = (byte)DAT_03006302 + 0xe300;
  puVar2 = &DAT_03006382;
  bVar1 = 0;
  do {
    if (DAT_03006308 < DAT_03006306) {
      *puVar2 = *DAT_03006318;
      DAT_03006318 = DAT_03006318 + 1;
      DAT_03006308 = DAT_03006308 + 1;
    }
    else {
      *puVar2 = 0;
    }
    puVar2 = puVar2 + 1;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0xc);
  return;
}


// sub_080DF7B8 @ 0x080DF7B8

int sub_080DF7B8(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  ushort local_24 [2];
  
  uVar2 = sub_080DF6FC(DAT_03006302 + 0xe300 & 0xffff);
  if ((uVar2 & 0xff) == 1) {
    iVar3 = 1;
    uVar2 = 0;
    do {
      puVar6 = (undefined1 *)(uVar2 * 0x10 + 0x3006342);
      puVar5 = (undefined1 *)(&DAT_0300631c)[uVar2];
      puVar4 = local_24 + uVar2;
      *puVar4 = DAT_0300630a;
      bVar1 = 0;
      do {
        if (*puVar4 < DAT_03006306) {
          *puVar5 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar5 = puVar5 + 1;
          *puVar4 = *puVar4 + 1;
        }
        else {
          iVar3 = 0xff;
        }
        bVar1 = bVar1 + 1;
      } while (bVar1 < 0xc);
      (&DAT_0300631c)[uVar2] = puVar5;
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 2);
    DAT_0300630a = local_24[0];
    if (iVar3 == 1) {
      DAT_03006302 = DAT_03006302 + 1;
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


// sub_080DF878 @ 0x080DF878

void sub_080DF878(undefined4 arg0,undefined1 *arg1,int arg2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  puVar3 = (undefined1 *)0x203bb74;
  puVar5 = (undefined4 *)0x203bd74;
  uVar1 = 0;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  DAT_03006300 = DAT_03006300 + 1;
  DAT_03006308 = 0;
  DAT_0300630a = 0;
  puVar3 = (undefined1 *)0x203bb74;
  uVar1 = 0;
  DAT_03006306 = (ushort)arg0;
  if ((ushort)arg0 != 0) {
    do {
      *puVar3 = *arg1;
      arg1 = arg1 + 1;
      puVar3 = puVar3 + 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < DAT_03006306);
  }
  uVar2 = sub_080DF6D0((uint)DAT_03006306,0x203bb74);
  DAT_0300630c = (undefined2)uVar2;
  DAT_03006304 = 0;
  DAT_03006302 = 0;
  uVar4 = 0;
  do {
    (&DAT_0300630e)[uVar4] = 0;
    (&DAT_0300631c)[uVar4] = uVar4 * 0x100 + 0x203bd74;
    (&DAT_0300632c)[uVar4] = *(undefined4 *)(uVar4 * 4 + arg2);
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 2);
  DAT_03006318 = 0x203bb74;
  DAT_0300636c = 1;
  return;
}


// sub_080DF954 @ 0x080DF954

void sub_080DF954(uint arg0,undefined4 arg1,dword arg2)

{
  uint uVar1;
  dword local_c;
  dword local_8;
  
  uVar1 = REG_SIOCNT;
  if ((uVar1 & 0x3f) >> 4 == 0) {
    local_c = 0x203bc74;
    local_8 = arg2;
  }
  else {
    local_8 = 0x203bc74;
    local_c = arg2;
  }
  sub_080DF878(arg0 & 0xffff,arg1,&local_c);
  return;
}


// sub_080DF990 @ 0x080DF990

undefined4 sub_080DF990(void)

{
  ushort uVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined1 *arg1;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  uVar4 = 0;
  do {
    arg1 = (undefined1 *)(uVar4 * 0x100 + 0x203bd74);
    uVar2 = sub_080DF6D0((uint)DAT_03006306,arg1);
    if ((uint)(ushort)(&DAT_0300630e)[uVar4] == (uVar2 & 0xffff)) {
      puVar3 = (undefined1 *)(&DAT_0300632c)[uVar4];
      uVar1 = 0;
      if (DAT_03006306 != 0) {
        do {
          *puVar3 = *arg1;
          arg1 = arg1 + 1;
          puVar3 = puVar3 + 1;
          uVar1 = uVar1 + 1;
        } while (uVar1 < DAT_03006306);
      }
    }
    else {
      uVar5 = 0xff;
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  return uVar5;
}


// sub_080DFA00 @ 0x080DFA00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 sub_080DFA00(void)

{
  uint uVar1;
  bool bVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar2 = false;
  switch(DAT_0300636c) {
  case 0:
    break;
  case 1:
    DAT_03006380 = 0xe100;
    _DAT_03006382 = DAT_0300630c;
    DAT_0300636c = 2;
    break;
  case 2:
    bVar2 = true;
    uVar1 = sub_080DF6FC(0xe100);
    if ((uVar1 & 0xff) != 1) goto switchD_080dfa1c_default;
    uVar1 = 0;
    do {
      (&DAT_0300630e)[uVar1] = *(undefined2 *)(uVar1 * 0x10 + 0x3006342);
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 2);
    DAT_0300636c = 3;
    sub_080DF760();
    break;
  case 3:
    bVar2 = true;
    uVar1 = sub_080DF7B8();
    if ((uVar1 & 0xff) == 0xff) {
      DAT_03006380 = 0xe400;
      DAT_0300636c = 4;
    }
    else {
      if ((uVar1 & 0xff) != 1) goto switchD_080dfa1c_default;
      sub_080DF760();
    }
    break;
  case 4:
    bVar2 = true;
    uVar1 = sub_080DF6FC(0xe400);
    if ((uVar1 & 0xff) == 1) {
      uVar1 = sub_080DF990();
      if ((uVar1 & 0xff) == 0) {
        DAT_0300636c = (undefined1)uVar1;
        uVar3 = 1;
        DAT_03006380 = 0;
      }
      else {
        DAT_0300636c = 5;
        DAT_03006380 = 0xe500;
      }
    }
    goto switchD_080dfa1c_default;
  case 5:
    bVar2 = true;
    uVar1 = sub_080DF6FC(0xe500);
    if ((uVar1 & 0xff) != 1) goto switchD_080dfa1c_default;
    DAT_03006380 = 0xe100;
    _DAT_03006382 = DAT_0300630c;
    DAT_0300636c = 2;
    break;
  default:
    goto switchD_080dfa1c_default;
  }
  bVar2 = false;
switchD_080dfa1c_default:
  uVar1 = sub_080DFB98();
  if ((uVar1 & 0xff) != 0) {
    bVar2 = true;
  }
  if (bVar2) {
    DAT_03006390 = DAT_03006390 + 1;
  }
  else {
    DAT_03006390 = 0;
  }
  if (599 < DAT_03006390) {
    uVar3 = 0xff;
  }
  return uVar3;
}


// sub_080DFB88 @ 0x080DFB88

void sub_080DFB88(void)

{
  undefined4 uVar1;
  
  uVar1 = REG_SIOCNT;
  return;
}


// sub_080DFB98 @ 0x080DFB98

undefined4 sub_080DFB98(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((DAT_03006360 & 0x1000) == 0) {
    if ((DAT_03006360 & 0x2000) == 0) {
      if (((DAT_03006360 & 0x8000) != 0) && ((DAT_03006360 & 0xf) != (DAT_03006360 & 0xfff) >> 8)) {
        uVar1 = 0xff;
      }
    }
    else {
      uVar1 = 0x20;
    }
  }
  else {
    uVar1 = 0x10;
  }
  return uVar1;
}


// sub_080DFBE0 @ 0x080DFBE0

void sub_080DFBE0(void)

{
  return;
}


// sub_080DFBFC @ 0x080DFBFC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DFBFC(void)

{
  undefined4 uStack_10;
  
  uStack_10 = 0;
  CpuSet(&uStack_10,0x203b554,0x5000034);
  _DAT_0203b554 = 0x15273950;
  DAT_0203b55c = 0;
  DAT_0203b558 = 0;
  DAT_0203b568 = 0;
  sub_080E0DC8(0x203b554);
  sub_080E1610(0x203b554);
  DAT_0203b560 = 0;
  DAT_0203b564 = sub_080C3100();
  DAT_0203b56c = sub_080C3168();
  DAT_0203b570 = 0;
  DAT_0203b574 = 0xff;
  DAT_0203b5a8 = 0;
  DAT_0203b5aa = 0;
  return;
}


// sub_080DFC58 @ 0x080DFC58

void sub_080DFC58(void)

{
  sub_080ACBC8(0x8589c94,0x2001000,0,0);
  sub_080ACBC8(0x8589c94,0x2001000,0x50,0);
  sub_080ACBC8(0x8589ca0,0x2001000,0xa0,0);
  return;
}


// sub_080DFCB4 @ 0x080DFCB4

void sub_080DFCB4(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080DFCD8 @ 0x080DFCD8

void sub_080DFCD8(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      uVar1 = DAT_03003964 & 0x40;
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          uVar2 = *(short *)(arg0 + 0x24) + 1;
          *(ushort *)(arg0 + 0x24) = uVar2;
          if (4 < uVar2) {
            *(ushort *)(arg0 + 0x24) = uVar1;
          }
          sub_080C51D4(100);
        }
      }
      else {
        if (*(short *)(arg0 + 0x24) == 0) {
          *(undefined2 *)(arg0 + 0x24) = 5;
        }
        *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
        sub_080C51D4(100);
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 0xff;
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_080C51D4(0x66);
    }
  }
  else {
    *(short *)(arg0 + 0x1e) = *(short *)(arg0 + 0x24) + 1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C51D4(0x65);
  }
                    /* WARNING: Could not recover jumptable at 0x080dfd6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DFD6C @ 0x080DFD6C

void sub_080DFD6C(void)

{
  undefined4 in_r0;
  int iVar1;
  
  iVar1 = sub_080AD364(in_r0);
  Text_DrawSpriteString(*(undefined4 *)((uint)*(ushort *)(iVar1 + 0x24) * 4 + 0x8589ca8),0,0,0x14);
  return;
}


// sub_080DFD9C @ 0x080DFD9C

void sub_080DFD9C(void)

{
  sub_080ACFCC(3,0x8580f80,0x30030f0,0xc0);
  sub_080AABB0();
  return;
}


// sub_080DFDC4 @ 0x080DFDC4

void sub_080DFDC4(int arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  if (arg0 * 0x10000 - 0x200000U >> 0x10 < 0x40) {
    sub_080AA184(0x80087c8,0,arg1 & 0xffff,0);
  }
  return;
}


// sub_080DFE14 @ 0x080DFE14

void sub_080DFE14(void)

{
  undefined4 arg0;
  undefined4 uVar1;
  undefined4 uVar2;
  
  arg0 = DAT_0203b55c;
  uVar2 = DAT_0203b558;
  DAT_0203b604 = 5;
  DAT_0203b614 = DAT_0203b558;
  DAT_0203b618 = DAT_0203b55c;
  DAT_0203b61c = DAT_0203b560;
  DAT_0203b620 = DAT_0203b564;
  uVar1 = __udivsi3(DAT_0203b558,100000);
  DAT_0203b605 = (undefined1)uVar1;
  uVar1 = __udivsi3(uVar2,10000);
  uVar1 = __umodsi3(uVar1,10);
  DAT_0203b606 = (undefined1)uVar1;
  uVar1 = __udivsi3(uVar2,1000);
  uVar1 = __umodsi3(uVar1,10);
  DAT_0203b607 = (undefined1)uVar1;
  uVar1 = __udivsi3(uVar2,100);
  uVar1 = __umodsi3(uVar1,10);
  DAT_0203b608 = (undefined1)uVar1;
  uVar1 = __udivsi3(uVar2,10);
  uVar1 = __umodsi3(uVar1,10);
  DAT_0203b609 = (undefined1)uVar1;
  uVar2 = __umodsi3(uVar2,10);
  DAT_0203b60a = (undefined1)uVar2;
  uVar2 = __udivsi3(arg0,100000);
  DAT_0203b60b = (undefined1)uVar2;
  uVar2 = __udivsi3(arg0,10000);
  uVar2 = __umodsi3(uVar2,10);
  DAT_0203b60c = (undefined1)uVar2;
  uVar2 = __udivsi3(arg0,1000);
  uVar2 = __umodsi3(uVar2,10);
  DAT_0203b60d = (undefined1)uVar2;
  uVar2 = __udivsi3(arg0,100);
  uVar2 = __umodsi3(uVar2,10);
  DAT_0203b60e = (undefined1)uVar2;
  uVar2 = __udivsi3(arg0,10);
  uVar2 = __umodsi3(uVar2,10);
  DAT_0203b60f = (undefined1)uVar2;
  uVar2 = __umodsi3(arg0,10);
  DAT_0203b610 = (char)uVar2;
  return;
}


// sub_080DFF08 @ 0x080DFF08

void sub_080DFF08(int arg0)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    uVar2 = (uint)DAT_030031b8;
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_030031b8 & 4) == 0) {
        if ((DAT_03003964 & 0x220) == 0) {
          if ((DAT_03003964 & 0x110) == 0) {
            if ((DAT_03003964 & 0x40) == 0) {
              if ((DAT_03003964 & 0x80) != 0) {
                (&DAT_0203b60b)[(char)DAT_0203b604] = (&DAT_0203b60b)[(char)DAT_0203b604] + -1;
                if ((&DAT_0203b60b)[(char)DAT_0203b604] < '\0') {
                  (&DAT_0203b60b)[(char)DAT_0203b604] = '\t';
                }
                sub_080C51D4(100);
              }
              goto LAB_080e0118;
            }
            (&DAT_0203b60b)[(char)DAT_0203b604] = (&DAT_0203b60b)[(char)DAT_0203b604] + '\x01';
            if ('\t' < (&DAT_0203b60b)[(char)DAT_0203b604]) {
              (&DAT_0203b60b)[(char)DAT_0203b604] = '\0';
            }
          }
          else {
            DAT_0203b604 = DAT_0203b604 + 1;
            if ('\x05' < (char)DAT_0203b604) {
              DAT_0203b604 = 0;
            }
          }
        }
        else {
          uVar2 = (uint)DAT_0203b604;
          DAT_0203b604 = (byte)(uVar2 - 1);
          if ((int)((uVar2 - 1) * 0x1000000) < 0) {
            DAT_0203b604 = 5;
          }
        }
        sub_080C51D4(100);
      }
      else {
        sub_080C51D4(0x66);
        uVar3 = 0;
        DAT_0203b558 = uVar2 & 2;
        DAT_0203b55c = uVar2 & 2;
        do {
          (&DAT_0203b605)[uVar3] = 0;
          (&DAT_0203b60b)[uVar3] = 0;
          uVar3 = uVar3 + 1 & 0xff;
        } while (uVar3 < 6);
      }
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined2 *)(arg0 + 0x1e) = 0xff;
    }
  }
  else {
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if (DAT_0203b61c < DAT_0203b614) {
      DAT_0203b614 = DAT_0203b61c;
    }
    uVar2 = DAT_0203b614;
    DAT_0203b558 = DAT_0203b614;
    if (DAT_0203b620 < DAT_0203b618) {
      DAT_0203b618 = DAT_0203b620;
    }
    uVar3 = DAT_0203b618;
    DAT_0203b55c = DAT_0203b618;
    uVar1 = __udivsi3(DAT_0203b614,100000);
    DAT_0203b605 = (char)uVar1;
    uVar1 = __udivsi3(uVar2,10000);
    uVar1 = __umodsi3(uVar1,10);
    DAT_0203b606 = (char)uVar1;
    uVar1 = __udivsi3(uVar2,1000);
    uVar1 = __umodsi3(uVar1,10);
    DAT_0203b607 = (char)uVar1;
    uVar1 = __udivsi3(uVar2,100);
    uVar1 = __umodsi3(uVar1,10);
    DAT_0203b608 = (char)uVar1;
    uVar1 = __udivsi3(uVar2,10);
    uVar1 = __umodsi3(uVar1,10);
    DAT_0203b609 = (char)uVar1;
    uVar1 = __umodsi3(uVar2,10);
    DAT_0203b60a = (char)uVar1;
    uVar1 = __udivsi3(uVar3,100000);
    DAT_0203b60b = (char)uVar1;
    uVar1 = __udivsi3(uVar3,10000);
    uVar1 = __umodsi3(uVar1,10);
    DAT_0203b60c = (char)uVar1;
    uVar1 = __udivsi3(uVar3,1000);
    uVar1 = __umodsi3(uVar1,10);
    DAT_0203b60d = (char)uVar1;
    uVar1 = __udivsi3(uVar3,100);
    uVar1 = __umodsi3(uVar1,10);
    DAT_0203b60e = (char)uVar1;
    uVar1 = __udivsi3(uVar3,10);
    uVar1 = __umodsi3(uVar1,10);
    DAT_0203b60f = (char)uVar1;
    uVar1 = __umodsi3(uVar3,10);
    DAT_0203b610 = (char)uVar1;
  }
LAB_080e0118:
  DAT_0203b614 = (int)DAT_0203b605 * 100000U + (int)DAT_0203b606 * 10000U + DAT_0203b607 * 1000 +
                 DAT_0203b608 * 100 + DAT_0203b609 * 10 + (int)DAT_0203b60a;
  DAT_0203b618 = (int)DAT_0203b60b * 100000U + (int)DAT_0203b60c * 10000U + DAT_0203b60d * 1000 +
                 DAT_0203b60e * 100 + DAT_0203b60f * 10 + (int)DAT_0203b610;
                    /* WARNING: Could not recover jumptable at 0x080e01a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E01AC @ 0x080E01AC

void sub_080E01AC(void)

{
  undefined4 in_r0;
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  sub_080AD364(in_r0);
  sub_080DFDC4(0x5e,10,0x58,0xe);
  pbVar1 = (byte *)sub_080A9CC0(DAT_0203b618);
  uVar4 = 5;
  do {
    iVar2 = (int)(char)uVar4;
    if (DAT_0203b604 == iVar2) {
      uVar3 = iVar2 * 0x80000 + 0x620000U >> 0x10;
      sub_080DFDC4(*pbVar1 + 0x30,0xc,uVar3,0xe);
      sub_080DFDC4(0x3e,10,uVar3,3);
      sub_080DFDC4(0x3c,10,uVar3,0x15);
    }
    else {
      sub_080DFDC4(*pbVar1 + 0x30,10,iVar2 * 0x80000 + 0x620000U >> 0x10,0xe);
    }
    pbVar1 = pbVar1 + 1;
    uVar3 = uVar4 * 0x1000000 - 0x1000000;
    uVar4 = uVar3 >> 0x18;
  } while (-1 < (int)uVar3);
  sub_080DFDC4(0x54,0xc,0x56,0x25);
  sub_080DFDC4(0x4f,0xc,0x5e,0x25);
  sub_080DFDC4(0x54,0xc,0x66,0x25);
  sub_080DFDC4(0x41,0xc,0x6e,0x25);
  sub_080DFDC4(0x4c,0xc,0x76,0x25);
  sub_080DFDC4(0x5e,10,0x58,0x31);
  pbVar1 = (byte *)sub_080A9CC0(DAT_0203b620);
  uVar4 = 5;
  do {
    sub_080DFDC4(*pbVar1 + 0x30,10,(char)uVar4 * 0x80000 + 0x620000U >> 0x10,0x31);
    pbVar1 = pbVar1 + 1;
    uVar3 = (int)(char)uVar4 - 1;
    uVar4 = uVar3 & 0xff;
  } while (-1 < (int)(uVar3 * 0x1000000));
  return;
}


// sub_080E02B0 @ 0x080E02B0

void sub_080E02B0(int arg0,undefined1 *arg1)

{
  undefined4 uVar1;
  undefined4 arg0_00;
  undefined4 arg0_01;
  
  *arg1 = 0xff;
  arg0_00 = *(undefined4 *)(arg0 + 4);
  *(undefined4 *)(arg1 + 0x10) = arg0_00;
  arg0_01 = *(undefined4 *)(arg0 + 8);
  *(undefined4 *)(arg1 + 0x14) = arg0_01;
  *(undefined4 *)(arg1 + 0x18) = *(undefined4 *)(arg0 + 0xc);
  *(undefined4 *)(arg1 + 0x1c) = *(undefined4 *)(arg0 + 0x10);
  uVar1 = __udivsi3(arg0_00,100000);
  arg1[1] = (char)uVar1;
  uVar1 = __udivsi3(arg0_00,10000);
  uVar1 = __umodsi3(uVar1,10);
  arg1[2] = (char)uVar1;
  uVar1 = __udivsi3(arg0_00,1000);
  uVar1 = __umodsi3(uVar1,10);
  arg1[3] = (char)uVar1;
  uVar1 = __udivsi3(arg0_00,100);
  uVar1 = __umodsi3(uVar1,10);
  arg1[4] = (char)uVar1;
  uVar1 = __udivsi3(arg0_00,10);
  uVar1 = __umodsi3(uVar1,10);
  arg1[5] = (char)uVar1;
  uVar1 = __umodsi3(arg0_00,10);
  arg1[6] = (char)uVar1;
  uVar1 = __udivsi3(arg0_01,100000);
  arg1[7] = (char)uVar1;
  uVar1 = __udivsi3(arg0_01,10000);
  uVar1 = __umodsi3(uVar1,10);
  arg1[8] = (char)uVar1;
  uVar1 = __udivsi3(arg0_01,1000);
  uVar1 = __umodsi3(uVar1,10);
  arg1[9] = (char)uVar1;
  uVar1 = __udivsi3(arg0_01,100);
  uVar1 = __umodsi3(uVar1,10);
  arg1[10] = (char)uVar1;
  uVar1 = __udivsi3(arg0_01,10);
  uVar1 = __umodsi3(uVar1,10);
  arg1[0xb] = (char)uVar1;
  uVar1 = __umodsi3(arg0_01,10);
  arg1[0xc] = (char)uVar1;
  return;
}


// sub_080E039C @ 0x080E039C

void sub_080E039C(void)

{
  sub_080E02B0(0x203b554,&DAT_0203b604);
  return;
}


// sub_080E03B0 @ 0x080E03B0

void sub_080E03B0(void)

{
  sub_080E02B0(0x203b5ac,&DAT_0203b604);
  return;
}


// sub_080E03C4 @ 0x080E03C4

void sub_080E03C4(int arg0)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *(undefined1 *)(arg0 + 0x50) = 4;
  uVar2 = DAT_0203b568;
  *(undefined4 *)(arg0 + 0x58) = DAT_0203b568;
  *(undefined4 *)(arg0 + 0x5c) = DAT_0203b56c;
  uVar1 = __udivsi3(uVar2,10000);
  uVar1 = __umodsi3(uVar1,10);
  *(char *)(arg0 + 0x51) = (char)uVar1;
  uVar1 = __udivsi3(uVar2,1000);
  uVar1 = __umodsi3(uVar1,10);
  *(char *)(arg0 + 0x52) = (char)uVar1;
  uVar1 = __udivsi3(uVar2,100);
  uVar1 = __umodsi3(uVar1,10);
  *(char *)(arg0 + 0x53) = (char)uVar1;
  uVar1 = __udivsi3(uVar2,10);
  uVar1 = __umodsi3(uVar1,10);
  *(char *)(arg0 + 0x54) = (char)uVar1;
  uVar2 = __umodsi3(uVar2,10);
  *(char *)(arg0 + 0x55) = (char)uVar2;
  return;
}


// sub_080E0434 @ 0x080E0434

void sub_080E0434(int arg0)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  byte *pbVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  pbVar6 = (byte *)(arg0 + 0x50);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    uVar5 = (uint)DAT_030031b8;
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_030031b8 & 4) == 0) {
        if ((DAT_03003964 & 0x220) == 0) {
          if ((DAT_03003964 & 0x110) == 0) {
            if ((DAT_03003964 & 0x40) == 0) {
              if ((DAT_03003964 & 0x80) != 0) {
                pcVar4 = (char *)(arg0 + 0x51 + (int)(char)*pbVar6);
                *pcVar4 = *pcVar4 + -1;
                pcVar4 = (char *)(arg0 + 0x51 + (int)(char)*pbVar6);
                if (*pcVar4 < '\0') {
                  *pcVar4 = '\t';
                }
                sub_080C51D4(100);
              }
              goto LAB_080e05b8;
            }
            pcVar4 = (char *)(arg0 + 0x51 + (int)(char)*pbVar6);
            *pcVar4 = *pcVar4 + '\x01';
            pcVar4 = (char *)(arg0 + 0x51 + (int)(char)*pbVar6);
            if ('\t' < *pcVar4) {
              *pcVar4 = '\0';
            }
          }
          else {
            bVar1 = *pbVar6;
            *pbVar6 = bVar1 + 1;
            if ('\x04' < (char)(bVar1 + 1)) {
              *pbVar6 = 0;
            }
          }
        }
        else {
          bVar1 = *pbVar6;
          *pbVar6 = (byte)(bVar1 - 1);
          if ((int)((bVar1 - 1) * 0x1000000) < 0) {
            *pbVar6 = 4;
          }
        }
        sub_080C51D4(100);
      }
      else {
        sub_080C51D4(0x66);
        *(uint *)(arg0 + 0x58) = uVar5 & 2;
        uVar3 = 0;
        DAT_0203b568 = uVar5 & 2;
        do {
          *(undefined1 *)(arg0 + 0x51 + uVar3) = 0;
          uVar3 = uVar3 + 1 & 0xff;
        } while (uVar3 < 5);
      }
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined2 *)(arg0 + 0x1e) = 0xff;
    }
  }
  else {
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if (*(uint *)(arg0 + 0x5c) < *(uint *)(arg0 + 0x58)) {
      *(uint *)(arg0 + 0x58) = *(uint *)(arg0 + 0x5c);
    }
    uVar5 = *(uint *)(arg0 + 0x58);
    DAT_0203b568 = uVar5;
    uVar2 = __udivsi3(uVar5,10000);
    uVar2 = __umodsi3(uVar2,10);
    *(char *)(arg0 + 0x51) = (char)uVar2;
    uVar2 = __udivsi3(uVar5,1000);
    uVar2 = __umodsi3(uVar2,10);
    *(char *)(arg0 + 0x52) = (char)uVar2;
    uVar2 = __udivsi3(uVar5,100);
    uVar2 = __umodsi3(uVar2,10);
    *(char *)(arg0 + 0x53) = (char)uVar2;
    uVar2 = __udivsi3(uVar5,10);
    uVar2 = __umodsi3(uVar2,10);
    *(char *)(arg0 + 0x54) = (char)uVar2;
    uVar2 = __umodsi3(uVar5,10);
    *(char *)(arg0 + 0x55) = (char)uVar2;
  }
LAB_080e05b8:
  *(dword *)(arg0 + 0x58) =
       (int)*(char *)(arg0 + 0x51) * 10000U + *(char *)(arg0 + 0x52) * 1000 +
       *(char *)(arg0 + 0x53) * 100 + *(char *)(arg0 + 0x54) * 10 + (int)*(char *)(arg0 + 0x55);
                    /* WARNING: Could not recover jumptable at 0x080e05f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E0600 @ 0x080E0600

void sub_080E0600(int arg0)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080AD364(arg0);
  pbVar1 = (byte *)sub_080A9CC0(*(undefined4 *)(arg0 + 0x58));
  uVar4 = 4;
  do {
    iVar2 = (int)(char)uVar4;
    if (*(char *)(arg0 + 0x50) == iVar2) {
      uVar3 = iVar2 * 0x80000 + 0x620000U >> 0x10;
      sub_080DFDC4(*pbVar1 + 0x30,0xc,uVar3,0xe);
      sub_080DFDC4(0x3e,10,uVar3,3);
      sub_080DFDC4(0x3c,10,uVar3,0x15);
    }
    else {
      sub_080DFDC4(*pbVar1 + 0x30,10,iVar2 * 0x80000 + 0x620000U >> 0x10,0xe);
    }
    pbVar1 = pbVar1 + 1;
    uVar3 = uVar4 * 0x1000000 - 0x1000000;
    uVar4 = uVar3 >> 0x18;
  } while (-1 < (int)uVar3);
  sub_080DFDC4(0x54,0xc,0x56,0x25);
  sub_080DFDC4(0x4f,0xc,0x5e,0x25);
  sub_080DFDC4(0x54,0xc,0x66,0x25);
  sub_080DFDC4(0x41,0xc,0x6e,0x25);
  sub_080DFDC4(0x4c,0xc,0x76,0x25);
  pbVar1 = (byte *)sub_080A9CC0(*(undefined4 *)(arg0 + 0x5c));
  uVar4 = 4;
  do {
    sub_080DFDC4(*pbVar1 + 0x30,10,(char)uVar4 * 0x80000 + 0x620000U >> 0x10,0x31);
    pbVar1 = pbVar1 + 1;
    uVar3 = (int)(char)uVar4 - 1;
    uVar4 = uVar3 & 0xff;
  } while (-1 < (int)(uVar3 * 0x1000000));
                    /* WARNING: Could not recover jumptable at 0x080e06ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E06EC @ 0x080E06EC

void sub_080E06EC(int arg0,undefined1 *arg1)

{
  undefined4 uVar1;
  undefined4 arg0_00;
  
  *arg1 = 0xff;
  arg0_00 = *(undefined4 *)(arg0 + 0x14);
  *(undefined4 *)(arg1 + 8) = arg0_00;
  *(undefined4 *)(arg1 + 0xc) = *(undefined4 *)(arg0 + 0x18);
  uVar1 = __udivsi3(arg0_00,10000);
  uVar1 = __umodsi3(uVar1,10);
  arg1[1] = (char)uVar1;
  uVar1 = __udivsi3(arg0_00,1000);
  uVar1 = __umodsi3(uVar1,10);
  arg1[2] = (char)uVar1;
  uVar1 = __udivsi3(arg0_00,100);
  uVar1 = __umodsi3(uVar1,10);
  arg1[3] = (char)uVar1;
  uVar1 = __udivsi3(arg0_00,10);
  uVar1 = __umodsi3(uVar1,10);
  arg1[4] = (char)uVar1;
  uVar1 = __umodsi3(arg0_00,10);
  arg1[5] = (char)uVar1;
  return;
}


// sub_080E0754 @ 0x080E0754

void sub_080E0754(int arg0)

{
  sub_080E06EC(0x203b554,arg0 + 0x50);
  return;
}


// sub_080E0768 @ 0x080E0768

void sub_080E0768(int arg0)

{
  sub_080E06EC(0x203b5ac,arg0 + 0x50);
  return;
}


// sub_080E077C @ 0x080E077C

void sub_080E077C(int arg0)

{
  uint uVar1;
  
  *(undefined1 *)(arg0 + 0x50) = 1;
  *(undefined2 *)(arg0 + 0x56) = 0xffff;
  *(undefined2 *)(arg0 + 0x54) = 0xffff;
  uVar1 = 0;
  do {
    ((undefined1 *)(arg0 + 0x50))[uVar1 + 1] = 0;
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  DAT_0203b5a8 = 0;
  DAT_0203b5aa = 0;
  DAT_0203b600 = 0;
  DAT_0203b602 = 0;
  return;
}


// sub_080E07D0 @ 0x080E07D0

void sub_080E07D0(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      uVar1 = DAT_03003964 & 0x40;
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          uVar2 = *(short *)(arg0 + 0x24) + 1;
          *(ushort *)(arg0 + 0x24) = uVar2;
          if (5 < uVar2) {
            *(ushort *)(arg0 + 0x24) = uVar1;
          }
          sub_080C51D4(100);
        }
      }
      else {
        if (*(short *)(arg0 + 0x24) == 0) {
          *(undefined2 *)(arg0 + 0x24) = 6;
        }
        *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
        sub_080C51D4(100);
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 0xff;
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_080C51D4(0x66);
    }
  }
  else {
    *(short *)(arg0 + 0x1e) = *(short *)(arg0 + 0x24) + 1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C51D4(0x65);
  }
                    /* WARNING: Could not recover jumptable at 0x080e0862. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E0864 @ 0x080E0864

uint sub_080E0864(uint arg0)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint arg0_00;
  ushort *puVar6;
  
  puVar6 = &DAT_0203c4d0;
  uVar5 = 0;
  uVar4 = 0;
  do {
    uVar1 = *(ushort *)(uVar4 * 4 + 0x30051ac);
    arg0_00 = (uint)uVar1;
    uVar2 = (&DAT_030051ae)[uVar4 * 2];
    if (uVar2 != 0) {
      if (arg0 == 0x80) {
        uVar3 = sub_080F4548(arg0_00);
        if (((uVar3 & 0x80) != 0) && ((arg0_00 - 0x120 & 0xffff) < 0xc)) {
          *puVar6 = uVar1;
          puVar6[1] = uVar2;
LAB_080e08f4:
          puVar6 = puVar6 + 2;
          uVar5 = uVar5 + 1 & 0xffff;
        }
      }
      else {
        uVar3 = sub_080F4548(arg0_00);
        if (((uVar3 & arg0) != 0) && (arg0_00 < 0xff)) {
          *puVar6 = uVar1;
          puVar6[1] = uVar2;
          goto LAB_080e08f4;
        }
      }
    }
    uVar4 = uVar4 + 1 & 0xffff;
    if (0x159 < uVar4) {
      *puVar6 = 0xffff;
      puVar6[1] = 0xffff;
      return uVar5;
    }
  } while( true );
}


// sub_080E0928 @ 0x080E0928

void sub_080E0928(int arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  uVar1 = sub_080E0864(*(undefined4 *)((uint)*(ushort *)(arg0 + 0x24) * 4 + 0x858a818));
  uVar1 = uVar1 & 0xffff;
  if (uVar1 == 0) {
    *(undefined2 *)(arg0 + 0x1e) = 0xff;
  }
  else if (uVar1 < 5) {
    sub_08126928(1,0,1,uVar1);
  }
  else {
    sub_08126928(1,0x10,1,uVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x080e097c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E0980 @ 0x080E0980

void sub_080E0980(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) != 0) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_080C51D4(0x66);
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C51D4(0x65);
  }
  sub_080DFDC4(0x4e,0xf,0x7c,0x28);
  sub_080DFDC4(0x4f,0xf,0x84,0x28);
  sub_080DFDC4(0x54,0xf,0x8c,0x28);
  sub_080DFDC4(0x48,0xf,0x94,0x28);
  sub_080DFDC4(0x49,0xf,0x9c,0x28);
  sub_080DFDC4(0x4e,0xf,0xa4,0x28);
  sub_080DFDC4(0x47,0xf,0xac,0x28);
  sub_080DFDC4(0x21,0xf,0xb4,0x28);
  return;
}


// Battle_DrawItemListPage @ 0x080E0A1C

void Battle_DrawItemListPage(int arg0)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint uVar6;
  int arg3;
  uint uVar7;
  uint uVar8;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 auStack_34 [10];
  
  memset(auStack_34,0,0x12);
  sub_080AA184(*(undefined4 *)(arg0 + 0x3c),0,7,0);
  sub_080AA184(*(undefined4 *)(arg0 + 0x38),0,7,0);
  iVar2 = sub_08126D1C(1);
  sub_080AA184(0x800853c,0,7,0);
  if (5 < *(ushort *)(iVar2 + 10)) {
    if (*(short *)(iVar2 + 0xc) != 0) {
      sub_080DFDC4(0x3c,10,0xd9,0xb);
    }
    if (*(ushort *)(iVar2 + 0xc) + 5 != (uint)*(ushort *)(iVar2 + 10)) {
      sub_080DFDC4(0x3e,10,0xd9,0x49);
    }
    if (5 < *(ushort *)(iVar2 + 10)) {
      uVar8 = 5;
      goto LAB_080e0ae4;
    }
  }
  uVar8 = (uint)*(byte *)(iVar2 + 10);
LAB_080e0ae4:
  uVar6 = 0;
  if (uVar8 != 0) {
    do {
      iVar3 = uVar6 + *(ushort *)(iVar2 + 0xc);
      uVar7 = (uint)*(ushort *)(iVar3 * 4 + 0x203c4d0);
      uVar1 = (&DAT_0203c4d2)[iVar3 * 2];
      if (uVar7 < 0x80) {
        iVar3 = sub_080BF32C(uVar7);
LAB_080e0b12:
        puVar5 = (undefined2 *)(iVar3 + 0x14);
      }
      else {
        if (uVar7 < 0xd0) {
          iVar3 = Equipment_GetRecord36_MidRange(uVar7);
          goto LAB_080e0b12;
        }
        iVar3 = Action_GetRecord(uVar7);
        puVar5 = (undefined2 *)(iVar3 + 0xc);
      }
      uVar4 = 0;
      do {
        auStack_34[uVar4] = *puVar5;
        puVar5 = puVar5 + 1;
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 8);
      auStack_34[uVar4] = 0;
      uVar7 = sub_080E0CDC(0x203b554,uVar7);
      if ((uVar7 & 0xff) == 0) {
        Text_DrawSpriteString(auStack_34,0,0,0x52);
      }
      else {
        Text_DrawSpriteStringTinted(auStack_34,0,0,0x52);
      }
      FontSprite_DrawGlyph(0x3e,0,0,0xb9);
      iVar3 = __udivsi3((uint)uVar1,10);
      arg3 = uVar6 * 0xd + 0x12;
      sub_080DFDC4(iVar3 + 0x30U & 0xffff,10,0xc6,arg3);
      iVar3 = __umodsi3((uint)uVar1,10);
      sub_080DFDC4(iVar3 + 0x30U & 0xffff,10,0xce,arg3);
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < uVar8);
  }
                    /* WARNING: Could not recover jumptable at 0x080e0bf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E0BF4 @ 0x080E0BF4

void sub_080E0BF4(int arg0)

{
  ushort uVar1;
  char *pcVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar2 = (char *)sub_08126D1C(1);
  sub_08126A08(1);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar1 = DAT_030031b8 & 2;
  if ((DAT_030031b8 & 2) == 0) {
    if (*pcVar2 == '\x03') {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined2 *)(arg0 + 0x54) = (&DAT_0203c4d0)[(uint)*(ushort *)(pcVar2 + 0x12) * 2];
      uVar3 = sub_080E0CDC(0x203b554,(uint)*(ushort *)(arg0 + 0x54));
      if ((uVar3 & 0xff) == 0) {
        uVar3 = sub_080E0D08(0x203b554);
        if ((uVar3 & 0xff) == 0) {
          *(undefined2 *)(arg0 + 0x56) = 0;
          uVar3 = 0;
          do {
            *(undefined1 *)(arg0 + uVar3 + 0x51) = 0;
            uVar3 = uVar3 + 1 & 0xff;
          } while (uVar3 < 2);
        }
        else {
          sub_080C51D4(0x66);
          *(undefined2 *)(arg0 + 0x1c) = 0;
        }
      }
      else {
        sub_080E0D74(0x203b554,(uint)*(ushort *)(arg0 + 0x54));
        *(ushort *)(arg0 + 0x1c) = uVar1;
      }
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0xff;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080e0cac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E0CB0 @ 0x080E0CB0

void sub_080E0CB0(int arg0)

{
  *(dword *)(arg0 + 0x20) = 0x80d9b65;
  sub_081269B0(1);
  return;
}


// sub_080E0CC4 @ 0x080E0CC4

void sub_080E0CC4(int arg0)

{
  sub_080E0D1C(0x203b554,(uint)*(ushort *)(arg0 + 0x54),(uint)*(ushort *)(arg0 + 0x56));
  return;
}


// sub_080E0CDC @ 0x080E0CDC

undefined4 sub_080E0CDC(int arg0,undefined4 arg1)

{
  undefined4 uVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = 0;
  do {
    if (*(short *)(arg0 + uVar2 * 4 + 0x40) == (short)arg1) {
      uVar1 = 1;
      goto LAB_080e0d02;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 5);
  uVar1 = 0;
LAB_080e0d02:
                    /* WARNING: Could not recover jumptable at 0x080e0d04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar1;
}


// sub_080E0D08 @ 0x080E0D08

undefined4 sub_080E0D08(int arg0)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x080e0d1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(4 < *(byte *)(arg0 + 0x25));
  return uVar1;
}


// sub_080E0D1C @ 0x080E0D1C

void sub_080E0D1C(int arg0,undefined4 arg1,undefined4 arg2)

{
  uint uVar1;
  undefined4 uVar2;
  short *psVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080E0D08(arg0);
  if ((uVar1 & 0xff) == 0) {
    uVar1 = 0;
    do {
      iVar4 = arg0 + uVar1 * 4;
      psVar3 = (short *)(iVar4 + 0x40);
      if (*psVar3 == -1) {
        *psVar3 = (short)arg1;
        *(undefined2 *)(iVar4 + 0x42) = (undefined2)arg2;
        *(char *)(arg0 + 0x25) = *(char *)(arg0 + 0x25) + '\x01';
        uVar2 = 1;
        goto LAB_080e0d68;
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < 5);
  }
  uVar2 = 0;
LAB_080e0d68:
                    /* WARNING: Could not recover jumptable at 0x080e0d6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}


// sub_080E0D74 @ 0x080E0D74

void sub_080E0D74(int arg0,undefined4 arg1)

{
  int iVar1;
  short *psVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    iVar1 = arg0 + uVar3 * 4;
    psVar2 = (short *)(iVar1 + 0x40);
    if (*psVar2 == (short)arg1) {
      *(undefined2 *)(iVar1 + 0x42) = 0xffff;
      *psVar2 = -1;
      *(char *)(arg0 + 0x25) = *(char *)(arg0 + 0x25) + -1;
      return;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 5);
  return;
}


// sub_080E0DC8 @ 0x080E0DC8

void sub_080E0DC8(int arg0)

{
  int iVar1;
  uint uVar2;
  
  *(undefined1 *)(arg0 + 0x25) = 0;
  uVar2 = 0;
  do {
    iVar1 = arg0 + uVar2 * 4;
    *(undefined2 *)(iVar1 + 0x42) = 0xffff;
    *(undefined2 *)(iVar1 + 0x40) = 0xffff;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 5);
  return;
}


// sub_080E0E04 @ 0x080E0E04

undefined4 sub_080E0E04(int arg0,undefined4 arg1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = 0;
  do {
    if (*(short *)(arg0 + uVar3 * 4 + 0x40) == (short)arg1) {
      iVar1 = arg0 + uVar3 * 4 + 0x40;
      goto LAB_080e0e2e;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 5);
  iVar1 = 0;
LAB_080e0e2e:
                    /* WARNING: Could not recover jumptable at 0x080e0e32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(iVar1);
  return uVar2;
}


// sub_080E0E34 @ 0x080E0E34

void sub_080E0E34(int arg0)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080AD364(arg0);
  pbVar5 = (byte *)(iVar2 + 0x50);
  iVar3 = sub_08126D1C(1);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(iVar2 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x220) == 0) {
        if ((DAT_03003964 & 0x110) == 0) {
          if ((DAT_03003964 & 0x40) == 0) {
            if ((DAT_03003964 & 0x80) != 0) {
              pbVar5[(char)*pbVar5 + 1] = pbVar5[(char)*pbVar5 + 1] - 1;
              if ((char)pbVar5[(char)*pbVar5 + 1] < '\0') {
                pbVar5[(char)*pbVar5 + 1] = 9;
              }
              sub_080C51D4(100);
            }
            goto LAB_080e0f80;
          }
          pbVar5[(char)*pbVar5 + 1] = pbVar5[(char)*pbVar5 + 1] + 1;
          if ('\t' < (char)pbVar5[(char)*pbVar5 + 1]) {
            pbVar5[(char)*pbVar5 + 1] = 0;
          }
        }
        else {
          bVar1 = *pbVar5;
          *pbVar5 = bVar1 + 1;
          if ('\x01' < (char)(bVar1 + 1)) {
            *pbVar5 = 0;
          }
        }
      }
      else {
        bVar1 = *pbVar5;
        *pbVar5 = (byte)(bVar1 - 1);
        if ((int)((bVar1 - 1) * 0x1000000) < 0) {
          *pbVar5 = 1;
        }
      }
      sub_080C51D4(100);
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined2 *)(iVar2 + 0x1e) = 0xff;
      *(undefined2 *)(arg0 + 0x1e) = 0xff;
      *(undefined2 *)(iVar2 + 0x54) = 0xffff;
    }
  }
  else if (*(short *)(iVar2 + 0x56) == 0) {
    sub_080C51D4(0x66);
  }
  else {
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if ((ushort)(&DAT_0203c4d2)[(uint)*(ushort *)(iVar3 + 0x12) * 2] < *(ushort *)(iVar2 + 0x56)) {
      *(undefined2 *)(iVar2 + 0x56) = (&DAT_0203c4d2)[(uint)*(ushort *)(iVar3 + 0x12) * 2];
      uVar4 = __udivsi3((uint)*(ushort *)(iVar2 + 0x56),10);
      *(char *)(iVar2 + 0x51) = (char)uVar4;
      uVar4 = __umodsi3((uint)*(ushort *)(iVar2 + 0x56),10);
      *(char *)(iVar2 + 0x52) = (char)uVar4;
    }
    *(undefined2 *)(iVar2 + 0x1e) = 0;
  }
LAB_080e0f80:
  *(short *)(iVar2 + 0x56) = (short)*(char *)(iVar2 + 0x52) + *(char *)(iVar2 + 0x51) * 10;
                    /* WARNING: Could not recover jumptable at 0x080e0f9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E0FA0 @ 0x080E0FA0

void sub_080E0FA0(void)

{
  undefined4 in_r0;
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080AD364(in_r0);
  pcVar5 = (char *)(iVar1 + 0x50);
  uVar2 = 0;
  do {
    iVar1 = -((int)(uVar2 * 0x1000000) >> 0x18);
    iVar3 = iVar1 + 1;
    if (*pcVar5 == iVar3) {
      uVar4 = iVar3 * 0x80000 + 0xd20000U >> 0x10;
      sub_080DFDC4((int)pcVar5[iVar1 + 2] + 0x30U & 0xffff,0xc,uVar4,0x61);
      sub_080DFDC4(0x3e,10,uVar4,0x56);
      sub_080DFDC4(0x3c,10,uVar4,0x68);
    }
    else {
      sub_080DFDC4((int)pcVar5[iVar1 + 2] + 0x30U & 0xffff,10,iVar3 * 0x80000 + 0xd20000U >> 0x10,
                   0x61);
    }
    uVar4 = uVar2 * 0x1000000 + 0x1000000;
    uVar2 = uVar4 >> 0x18;
  } while ((int)uVar4 >> 0x18 < 2);
                    /* WARNING: Could not recover jumptable at 0x080e102c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E1030 @ 0x080E1030

void sub_080E1030(int arg0,int arg1)

{
  int iVar1;
  uint arg0_00;
  uint uVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  undefined2 local_38 [10];
  int local_24;
  
  local_24 = arg1;
  memset(local_38,0,0x12);
  uVar6 = 0;
  if (*(char *)(arg0 + 0x25) == '\0') {
    sub_080DFDC4(0x4e,0xf,0x7c,0x28);
    sub_080DFDC4(0x4f,0xf,0x84,0x28);
    sub_080DFDC4(0x54,0xf,0x8c,0x28);
    sub_080DFDC4(0x48,0xf,0x94,0x28);
    sub_080DFDC4(0x49,0xf,0x9c,0x28);
    sub_080DFDC4(0x4e,0xf,0xa4,0x28);
    sub_080DFDC4(0x47,0xf,0xac,0x28);
    sub_080DFDC4(0x21,0xf,0xb4,0x28);
  }
  else {
    uVar5 = 0;
    do {
      iVar1 = uVar5 * 4 + arg0;
      uVar2 = (uint)*(ushort *)(iVar1 + 0x40);
      arg0_00 = (uint)*(ushort *)(iVar1 + 0x42);
      if (uVar2 != 0xffff) {
        if (uVar2 < 0x80) {
          iVar1 = sub_080BF32C(uVar2);
LAB_080e10f2:
          puVar3 = (undefined2 *)(iVar1 + 0x14);
        }
        else {
          if (uVar2 < 0xd0) {
            iVar1 = Equipment_GetRecord36_MidRange(uVar2);
            goto LAB_080e10f2;
          }
          iVar1 = Action_GetRecord(uVar2);
          puVar3 = (undefined2 *)(iVar1 + 0xc);
        }
        uVar2 = 0;
        puVar4 = (ushort *)(local_24 + 0x54);
        do {
          local_38[uVar2] = *puVar3;
          puVar3 = puVar3 + 1;
          uVar2 = uVar2 + 1 & 0xffff;
        } while (uVar2 < 8);
        local_38[uVar2] = 0;
        if (((int)(uint)*puVar4 >> (uVar5 & 0xff) & 1U) == 0) {
          Text_DrawSpriteString(local_38,0,0,0x52);
        }
        else {
          Text_DrawSpriteStringTinted(local_38,0,0,0x52);
        }
        FontSprite_DrawGlyph(0x3e,0,0,0xb9);
        iVar1 = __udivsi3(arg0_00,10);
        uVar2 = uVar6 * 0xd + 0x12 & 0xffff;
        sub_080DFDC4(iVar1 + 0x30U & 0xffff,10,0xc6,uVar2);
        iVar1 = __umodsi3(arg0_00,10);
        sub_080DFDC4(iVar1 + 0x30U & 0xffff,10,0xce,uVar2);
        uVar6 = uVar6 + 1 & 0xffff;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 5);
  }
  return;
}


// sub_080E11F0 @ 0x080E11F0

void sub_080E11F0(void)

{
  sub_080E1030(0x203b554,&DAT_0203b5ac);
  return;
}


// sub_080E1204 @ 0x080E1204

void sub_080E1204(void)

{
  sub_080E1030(0x203b5ac,&DAT_0203b554);
  return;
}


// sub_080E1218 @ 0x080E1218

void sub_080E1218(int arg0)

{
  *(undefined1 *)(arg0 + 0x24) = 0;
  *(undefined2 *)(arg0 + 0x26) = 0xffff;
  return;
}


// sub_080E1228 @ 0x080E1228

void sub_080E1228(int arg0)

{
  uint uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  uVar1 = sub_08127A98(8);
  uVar1 = uVar1 & 0xffff;
  if (uVar1 == 0) {
    *(undefined2 *)(arg0 + 0x1e) = 0xff;
  }
  else {
    if (uVar1 < 5) {
      sub_08126928(1,0,1,uVar1);
    }
    else {
      sub_08126928(1,0x10,1,uVar1);
    }
    iVar2 = sub_08126D1C(1);
    *(undefined2 *)(iVar2 + 0x1e) = 0xffff;
  }
                    /* WARNING: Could not recover jumptable at 0x080e127a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E1280 @ 0x080E1280

void sub_080E1280(int arg0)

{
  undefined2 uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar2 = (char *)sub_08126D1C(1);
  sub_08126A08(1);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if (*pcVar2 == '\x03') {
      iVar3 = sub_080F2F64((ushort)(&DAT_0203c4d0)[*(ushort *)(pcVar2 + 0x12)] + 0x8000 & 0xffff);
      uVar1 = *(undefined2 *)(iVar3 + 0x12);
      uVar4 = sub_0815B8F8((int)*(short *)(iVar3 + 0x12),0);
      if ((int)(-uVar4 | uVar4) < 0) {
        *(undefined2 *)(arg0 + 0x26) = uVar1;
        uVar4 = sub_080E1540(0x203b554,(uint)*(ushort *)(arg0 + 0x26));
        if ((uVar4 & 0xff) == 0) {
          uVar4 = sub_080E156C(0x203b554);
          if ((uVar4 & 0xff) != 0) {
            sub_080C51D4(0x66);
            goto LAB_080e1342;
          }
          sub_080E1580(0x203b554,(uint)*(ushort *)(arg0 + 0x26));
        }
        else {
          sub_080E15CC(0x203b554,(uint)*(ushort *)(arg0 + 0x26));
        }
        sub_080C51D4(0x65);
      }
      else {
        sub_080C51D4(0x66);
      }
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0xff;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
LAB_080e1342:
                    /* WARNING: Could not recover jumptable at 0x080e1346. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E1348 @ 0x080E1348

void sub_080E1348(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) != 0) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_080C51D4(0x66);
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C51D4(0x65);
  }
  sub_080DFDC4(0x4e,0xf,0x6c,0x2a);
  sub_080DFDC4(0x4f,0xf,0x74,0x2a);
  sub_080DFDC4(0x54,0xf,0x7c,0x2a);
  sub_080DFDC4(0x48,0xf,0x84,0x2a);
  sub_080DFDC4(0x49,0xf,0x8c,0x2a);
  sub_080DFDC4(0x4e,0xf,0x94,0x2a);
  sub_080DFDC4(0x47,0xf,0x9c,0x2a);
  sub_080DFDC4(0x21,0xf,0xa4,0x2a);
  return;
}


// sub_080E13E4 @ 0x080E13E4

void sub_080E13E4(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint uVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 local_34 [10];
  
  memset(local_34,0,0x12);
  iVar2 = sub_08126D1C(1);
  sub_080AA184(0x800853c,0,7,0);
  if (5 < *(ushort *)(iVar2 + 10)) {
    if (*(short *)(iVar2 + 0xc) != 0) {
      sub_080DFDC4(0x3c,10,0xb9,0xb);
    }
    if (*(ushort *)(iVar2 + 0xc) + 5 != (uint)*(ushort *)(iVar2 + 10)) {
      sub_080DFDC4(0x3e,10,0xb9,0x49);
    }
  }
  if (*(ushort *)(iVar2 + 10) < 5) {
    uVar7 = *(ushort *)(iVar2 + 10) & 0xff;
  }
  else {
    uVar7 = 5;
  }
  uVar6 = 0;
  if (uVar7 != 0) {
    do {
      iVar3 = sub_080F2F64((ushort)(&DAT_0203c4d0)[uVar6 + *(ushort *)(iVar2 + 0xc)] + 0x8000 &
                           0xffff);
      uVar1 = *(ushort *)(iVar3 + 0x12);
      iVar3 = sub_080BF648((uint)uVar1);
      puVar5 = (undefined2 *)(iVar3 + 0x22);
      uVar4 = 0;
      do {
        local_34[uVar4] = *puVar5;
        puVar5 = puVar5 + 1;
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 8);
      local_34[uVar4] = 0;
      uVar4 = sub_080E1540(0x203b554,(uint)uVar1);
      if ((uVar4 & 0xff) == 0) {
        Text_DrawSpriteString(local_34,0,0,0x51);
      }
      else {
        Text_DrawSpriteStringTinted(local_34,0,0,0x51);
      }
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < uVar7);
  }
                    /* WARNING: Could not recover jumptable at 0x080e1530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E1534 @ 0x080E1534

void sub_080E1534(void)

{
  sub_081269B0(1);
  return;
}


// sub_080E1540 @ 0x080E1540

undefined4 sub_080E1540(int arg0,undefined4 arg1)

{
  undefined4 uVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = 0;
  do {
    if (*(short *)(arg0 + 0x26 + uVar2 * 2) == (short)arg1) {
      uVar1 = 1;
      goto LAB_080e1566;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0xc);
  uVar1 = 0;
LAB_080e1566:
                    /* WARNING: Could not recover jumptable at 0x080e1568. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar1;
}


// sub_080E156C @ 0x080E156C

undefined4 sub_080E156C(int arg0)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x080e157e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(0xb < *(byte *)(arg0 + 0x24));
  return uVar1;
}


// sub_080E1580 @ 0x080E1580

void sub_080E1580(int arg0,undefined4 arg1)

{
  uint uVar1;
  undefined4 uVar2;
  short *psVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080E156C(arg0);
  if ((uVar1 & 0xff) == 0) {
    uVar1 = 0;
    do {
      psVar3 = (short *)(arg0 + 0x26 + uVar1 * 2);
      if (*psVar3 == -1) {
        *psVar3 = (short)arg1;
        *(char *)(arg0 + 0x24) = *(char *)(arg0 + 0x24) + '\x01';
        uVar2 = 1;
        goto LAB_080e15c2;
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < 0xc);
  }
  uVar2 = 0;
LAB_080e15c2:
                    /* WARNING: Could not recover jumptable at 0x080e15c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}


// sub_080E15CC @ 0x080E15CC

void sub_080E15CC(int arg0,undefined4 arg1)

{
  short *psVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    psVar1 = (short *)(arg0 + 0x26 + uVar2 * 2);
    if (*psVar1 == (short)arg1) {
      *psVar1 = -1;
      *(char *)(arg0 + 0x24) = *(char *)(arg0 + 0x24) + -1;
      return;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0xc);
  return;
}


// sub_080E1610 @ 0x080E1610

void sub_080E1610(int arg0)

{
  uint uVar1;
  
  *(undefined1 *)(arg0 + 0x24) = 0;
  uVar1 = 0;
  do {
    *(undefined2 *)(arg0 + 0x26 + uVar1 * 2) = 0xffff;
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0xc);
  return;
}


// sub_080E1644 @ 0x080E1644

void sub_080E1644(int arg0,int arg1)

{
  int iVar1;
  int iVar2;
  uint arg0_00;
  undefined2 *puVar3;
  uint uVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 auStack_34 [10];
  
  memset(auStack_34,0,0x12);
  if (*(char *)(arg0 + 0x24) == '\0') {
    sub_080DFDC4(0x4e,0xf,0x6c,0x2a);
    sub_080DFDC4(0x4f,0xf,0x74,0x2a);
    sub_080DFDC4(0x54,0xf,0x7c,0x2a);
    sub_080DFDC4(0x48,0xf,0x84,0x2a);
    sub_080DFDC4(0x49,0xf,0x8c,0x2a);
    sub_080DFDC4(0x4e,0xf,0x94,0x2a);
    sub_080DFDC4(0x47,0xf,0x9c,0x2a);
    sub_080DFDC4(0x21,0xf,0xa4,0x2a);
  }
  else {
    iVar1 = sub_08126D1C(1);
    sub_080AA184(0x800853c,0,7,0);
    if (5 < *(ushort *)(iVar1 + 10)) {
      if (*(short *)(iVar1 + 0xc) != 0) {
        sub_080DFDC4(0x3c,10,0xb9,0xb);
      }
      if (*(ushort *)(iVar1 + 0xc) + 5 != (uint)*(ushort *)(iVar1 + 10)) {
        sub_080DFDC4(0x3e,10,0xb9,0x49);
      }
    }
    uVar4 = (uint)*(ushort *)(iVar1 + 0xc);
    uVar5 = uVar4;
    if (uVar4 < uVar4 + 5) {
      do {
        arg0_00 = (uint)*(ushort *)(arg0 + 0x26 + uVar5 * 2);
        if (arg0_00 != 0xffff) {
          iVar2 = sub_080BF648(arg0_00);
          puVar3 = (undefined2 *)(iVar2 + 0x22);
          uVar4 = 0;
          do {
            auStack_34[uVar4] = *puVar3;
            puVar3 = puVar3 + 1;
            uVar4 = uVar4 + 1 & 0xffff;
          } while (uVar4 < 8);
          auStack_34[uVar4] = 0;
          if (((int)(uint)*(ushort *)(arg1 + 0x56) >> (uVar5 & 0xff) & 1U) == 0) {
            Text_DrawSpriteString(auStack_34,0,0,0x51);
          }
          else {
            Text_DrawSpriteStringTinted(auStack_34,0,0,0x51);
          }
          uVar4 = (uint)*(ushort *)(iVar1 + 0xc);
        }
        uVar5 = uVar5 + 1 & 0xffff;
      } while (uVar5 < uVar4 + 5);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080e17f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E17F4 @ 0x080E17F4

void sub_080E17F4(void)

{
  sub_080E1644(0x203b554,&DAT_0203b5ac);
  return;
}


// sub_080E1808 @ 0x080E1808

void sub_080E1808(void)

{
  sub_080E1644(0x203b5ac,&DAT_0203b554);
  return;
}


// sub_080E181C @ 0x080E181C

void sub_080E181C(int arg0)

{
  sub_08126D1C(1);
  sub_08126A08(1);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) != 0) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_080C51D4(0x66);
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C51D4(0x65);
  }
  return;
}


// sub_080E1864 @ 0x080E1864

void sub_080E1864(int arg0)

{
  int iVar1;
  uint arg3;
  code *UNRECOVERED_JUMPTABLE;
  
  arg3 = (uint)*(byte *)(arg0 + 0x24);
  if (arg3 != 0) {
    if (arg3 < 5) {
      sub_08126928(1,0,1,arg3);
    }
    else {
      sub_08126928(1,0x10,1,arg3);
    }
    iVar1 = sub_08126D1C(1);
    *(undefined2 *)(iVar1 + 0x1e) = 0xffff;
  }
                    /* WARNING: Could not recover jumptable at 0x080e18a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E18AC @ 0x080E18AC

void sub_080E18AC(void)

{
  sub_080E1864(0x203b554);
  return;
}


// sub_080E18BC @ 0x080E18BC

void sub_080E18BC(void)

{
  sub_080E1864(0x203b5ac);
  return;
}


// sub_080E18CC @ 0x080E18CC

void sub_080E18CC(void)

{
  sub_081269B0(1);
  return;
}


// sub_080E18D8 @ 0x080E18D8

void sub_080E18D8(void)

{
  DAT_0203b5ac = 0;
  DAT_0203b5b4 = 0;
  DAT_0203b5b0 = 0;
  DAT_0203b5c0 = 0;
  DAT_0203b5b8 = 0;
  DAT_0203b5bc = 0;
  DAT_0203b5c4 = 0;
  DAT_0203b5c8 = 0;
  DAT_0203b5cc = 0x1bf;
  DAT_0203b574 = 0x1bf;
  sub_080E0DC8(&DAT_0203b5ac);
  sub_080E1610(&DAT_0203b5ac);
  return;
}


// sub_080E1914 @ 0x080E1914

void sub_080E1914(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      uVar1 = DAT_03003964 & 0x40;
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          uVar2 = *(short *)(arg0 + 0x24) + 1;
          *(ushort *)(arg0 + 0x24) = uVar2;
          if (4 < uVar2) {
            *(ushort *)(arg0 + 0x24) = uVar1;
          }
          sub_080C51D4(100);
        }
      }
      else {
        if (*(short *)(arg0 + 0x24) == 0) {
          *(undefined2 *)(arg0 + 0x24) = 5;
        }
        *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
        sub_080C51D4(100);
      }
    }
  }
  else {
    *(short *)(arg0 + 0x1e) = *(short *)(arg0 + 0x24) + 1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C51D4(0x65);
  }
  return;
}


// sub_080E199C @ 0x080E199C

void sub_080E199C(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      uVar1 = DAT_03003964 & 0x40;
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          uVar2 = *(short *)(arg0 + 0x24) + 1;
          *(ushort *)(arg0 + 0x24) = uVar2;
          if (5 < uVar2) {
            *(ushort *)(arg0 + 0x24) = uVar1;
          }
          sub_080C51D4(100);
        }
      }
      else {
        if (*(short *)(arg0 + 0x24) == 0) {
          *(undefined2 *)(arg0 + 0x24) = 6;
        }
        *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
        sub_080C51D4(100);
      }
    }
  }
  else {
    *(short *)(arg0 + 0x1e) = *(short *)(arg0 + 0x24) + 1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C51D4(0x65);
  }
  return;
}


// sub_080E1A24 @ 0x080E1A24

void sub_080E1A24(int arg0,undefined4 arg1)

{
  uint uVar1;
  int iVar2;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar1 = sub_080DF388(arg1);
  if ((uVar1 & 0xff) == 1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_03006394 = 1;
  }
  else {
    iVar2 = *(ushort *)(arg0 + 0x24) - 1;
    *(short *)(arg0 + 0x24) = (short)iVar2;
    if (iVar2 * 0x10000 < 0) {
      *(undefined2 *)(arg0 + 0x1e) = 0xff;
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined2 *)(arg0 + 0x24) = 0;
      DAT_03006394 = 0;
    }
  }
  return;
}


// sub_080E1A6C @ 0x080E1A6C

void sub_080E1A6C(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x858b180,(uint)*(ushort *)(arg0 + 2));
  *(undefined2 *)(iVar1 + 0x24) = (undefined2)arg1;
  return;
}


// sub_080E1A88 @ 0x080E1A88

void sub_080E1A88(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x858b1bc,(uint)*(ushort *)(arg0 + 2));
  *(undefined2 *)(iVar1 + 0x24) = (undefined2)arg1;
  return;
}


// sub_080E1AA4 @ 0x080E1AA4

void sub_080E1AA4(int arg0)

{
  *(undefined2 *)(arg0 + 0x1e) = DAT_03006394;
  return;
}


// sub_080E1AB0 @ 0x080E1AB0

void sub_080E1AB0(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_080DF4B8();
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((uVar1 & 0xff) == 1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_03006394 = 1;
  }
  else if ((uVar1 & 0xff) == 0xff) {
    *(undefined2 *)(arg0 + 0x1e) = 0xff;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_03006394 = 0;
  }
  return;
}


// sub_080E1AEC @ 0x080E1AEC

void sub_080E1AEC(int arg0)

{
  sub_080AD0FC(0x858b1f8,(uint)*(ushort *)(arg0 + 2));
  return;
}


// sub_080E1B00 @ 0x080E1B00

void sub_080E1B00(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_080DFA00();
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((uVar1 & 0xff) == 1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_03006394 = 1;
  }
  else if ((uVar1 & 0xff) == 0xff) {
    *(undefined2 *)(arg0 + 0x1e) = 0xff;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_03006394 = 0;
  }
  return;
}


// sub_080E1B3C @ 0x080E1B3C

void sub_080E1B3C(int arg0)

{
  sub_080AD0FC(0x858b228,(uint)*(ushort *)(arg0 + 2));
  return;
}


// sub_080E1B50 @ 0x080E1B50

void sub_080E1B50(void)

{
  sub_080DF954(0x58,0x203b554,&DAT_0203b5ac);
  return;
}


// sub_080E1B68 @ 0x080E1B68

void sub_080E1B68(void)

{
  Text_DrawSpriteString(0x800980c,0,0,0x14);
  return;
}


// sub_080E1B8C @ 0x080E1B8C

void sub_080E1B8C(void)

{
  Text_DrawSpriteString(*(undefined4 *)((uint)DAT_03006398 * 4 + 0x858b250),0,0,0x14);
  return;
}


// sub_080E1BBC @ 0x080E1BBC

void sub_080E1BBC(undefined4 arg0,undefined4 arg1)

{
  DAT_03006398 = (undefined1)arg1;
  return;
}


// sub_080E1BC8 @ 0x080E1BC8

void sub_080E1BC8(int arg0)

{
  DAT_0203b570 = *(short *)(arg0 + 0x1e) != 0;
  return;
}


// sub_080E1BE0 @ 0x080E1BE0

void sub_080E1BE0(int arg0)

{
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (DAT_0203b570 == '\0') {
    if (DAT_0203b5c8 == '\0') {
      *(undefined2 *)(arg0 + 0x1e) = 1;
    }
    else {
      DAT_03006398 = 3;
    }
  }
  else {
    DAT_03006398 = 10;
  }
  return;
}


// sub_080E1C20 @ 0x080E1C20

void sub_080E1C20(int arg0)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 arg1;
  undefined4 extraout_r1;
  undefined4 arg1_00;
  uint uVar9;
  short sVar10;
  uint uVar11;
  uint uVar12;
  uint local_34;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (DAT_0203b5ac == 0x15273950) {
    DAT_0203b574 = 0;
    iVar3 = sub_080C3168();
    if ((uint)((iVar3 - DAT_0203b568) + DAT_0203b5c0) < 100000) {
      DAT_0203b574 = DAT_0203b574 | 4;
    }
    DAT_0203b5a8 = 0;
    if (DAT_0203b5d1 == '\0') {
      DAT_0203b574 = DAT_0203b574 | 8;
    }
    else {
      uVar4 = 0;
      do {
        uVar11 = (uint)(ushort)(&DAT_0203b5ec)[uVar4 * 2];
        if (uVar11 != 0xffff) {
          sVar10 = (&DAT_0203b5ee)[uVar4 * 2];
          iVar3 = sub_080E0E04(0x203b554,uVar11);
          if (iVar3 != 0) {
            sVar10 = sVar10 - *(short *)(iVar3 + 2);
          }
          uVar12 = sub_080C32D4(uVar11);
          iVar3 = sub_08131AB0(0xff,uVar11);
          if (99 < (((int)((iVar3 + (uVar12 & 0xff)) * 0x10000) >> 0x10) + (int)sVar10) * 0x10000 >>
                   0x10) {
            DAT_0203b5a8 = (short)(1 << (uVar4 & 0xff)) + DAT_0203b5a8;
          }
        }
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 < 5);
      if (DAT_0203b5a8 == 0) {
        DAT_0203b574 = DAT_0203b574 | 8;
      }
    }
    DAT_0203b5aa = 0;
    if (DAT_0203b5d0 == 0) {
      DAT_0203b574 = DAT_0203b574 | 0x1b0;
    }
    else {
      uVar4 = (uint)DAT_03005183;
      uVar12 = (uint)DAT_0203b5d0;
      bVar2 = true;
      uVar11 = 0;
      do {
        if (((ushort)(&DAT_0203b5d2)[uVar11] != 0xffff) &&
           (uVar5 = sub_080E1540(0x203b554,(uint)(ushort)(&DAT_0203b5d2)[uVar11]),
           (uVar5 & 0xff) != 0)) {
          uVar12 = uVar12 * 0x10000 - 0x10000 >> 0x10;
        }
        uVar11 = uVar11 + 1 & 0xff;
      } while (uVar11 < 0xc);
      uVar5 = 4;
      uVar11 = uVar4 + 4;
      if (4 < uVar11) {
        do {
          iVar3 = sub_080F2F64(uVar5 + 0x8000);
          if ((*(ushort *)(iVar3 + 0xe) & 0x8000) != 0) {
            uVar12 = uVar12 * 0x10000 + 0x10000 >> 0x10;
          }
          uVar5 = uVar5 + 1 & 0xff;
        } while (uVar5 < uVar11);
      }
      if ((int)(short)uVar12 <= (int)uVar4) {
        DAT_0203b574 = DAT_0203b574 | 0x20;
      }
      local_34 = uVar12 - DAT_0203b5d0 & 0xff;
      uVar12 = 0;
      do {
        uVar5 = (uint)(ushort)(&DAT_0203b5d2)[uVar12];
        if (uVar5 != 0xffff) {
          uVar9 = 4;
          if (4 < uVar11) {
            do {
              iVar3 = sub_080F2F64(uVar9 + 0x8000);
              if ((((*(ushort *)(iVar3 + 0xe) & 0x8000) != 0) &&
                  ((int)*(short *)(iVar3 + 0x12) == uVar5)) &&
                 (uVar6 = sub_080E1540(0x203b554,uVar5), (uVar6 & 0xff) != 1)) {
                DAT_0203b5aa = DAT_0203b5aa + (short)(1 << uVar12);
              }
              uVar9 = uVar9 + 1 & 0xff;
            } while (uVar9 < uVar11);
          }
          uVar7 = sub_08134C3C();
          if ((short)uVar7 == 1) {
            DAT_0203b5aa = (short)(1 << uVar12) + DAT_0203b5aa;
          }
          iVar3 = sub_0815BA28(uVar5);
          if (iVar3 == 0) {
            DAT_0203b5aa = (short)(1 << uVar12) + DAT_0203b5aa;
            bVar2 = false;
          }
        }
        uVar12 = uVar12 + 1 & 0xff;
      } while (uVar12 < 0xc);
      if (DAT_0203b5aa == 0) {
        DAT_0203b574 = DAT_0203b574 | 0x10;
      }
      if (bVar2) {
        DAT_0203b574 = DAT_0203b574 | 0x100;
      }
      uVar11 = 0;
      do {
        if ((&DAT_0203b5d2)[uVar11] != -1) {
          if (uVar4 < local_34) {
            DAT_0203b5aa = (ushort)(1 << uVar11) | DAT_0203b5aa;
          }
          local_34 = local_34 + 1 & 0xff;
        }
        uVar11 = uVar11 + 1 & 0xff;
      } while (uVar11 < 0xc);
      bVar2 = false;
      uVar4 = 0;
      do {
        uVar1 = (&DAT_0203b5d2)[uVar4];
        if (uVar1 != 0xffff) {
          uVar7 = sub_080C0F8C(0);
          iVar3 = sub_080BF648((uint)uVar1);
          if ((short)uVar7 < (short)(ushort)*(byte *)(iVar3 + 1)) {
            bVar2 = true;
            DAT_0203b5aa = (ushort)(1 << uVar4) | DAT_0203b5aa;
          }
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 0xc);
      if (!bVar2) {
        DAT_0203b574 = DAT_0203b574 | 0x80;
      }
    }
    iVar3 = DAT_0203b5b0;
    iVar8 = DAT_0203b5b4;
    if (DAT_0203b5b0 != 0) {
      DAT_0203b574 = DAT_0203b574 | 0x40;
      iVar8 = DAT_0203b5b0;
      sub_0815DBB4(DAT_0203b5b0);
      uVar7 = arg1;
      if (iVar3 < 0) {
        sub_0815D428(iVar8,arg1,0x41f00000,0);
        uVar7 = extraout_r1;
      }
      sub_0815D490(iVar8,uVar7,0x3fb47ae1,0x47ae147b);
      sub_0815DCF4(iVar8,arg1_00);
      iVar8 = sub_0815E5B4(iVar8);
    }
    iVar3 = sub_080C3100();
    if ((iVar3 - DAT_0203b55c) + iVar8 < 1000000) {
      DAT_0203b574 = DAT_0203b574 | 2;
    }
    DAT_0203b574 = DAT_0203b574 | 1;
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0xff;
  }
  return;
}


// sub_080E2010 @ 0x080E2010

void sub_080E2010(int arg0,uint arg1,int arg2)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0203b5ac;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (arg2 == 0) {
    puVar1 = (undefined4 *)0x203b554;
  }
  else if (arg2 != 1) {
    return;
  }
  if ((puVar1[8] & arg1) != 0) {
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  return;
}


// sub_080E2044 @ 0x080E2044

void sub_080E2044(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) != 0) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_080C51D4(0x66);
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C51D4(0x65);
  }
  return;
}


// sub_080E2080 @ 0x080E2080

void sub_080E2080(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  char local_28 [8];
  
  pcVar4 = local_28;
  uVar5 = 0;
  do {
    local_28[uVar5] = -1;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 6);
  uVar5 = 0;
  do {
    local_28[uVar5] = *(char *)(uVar5 + 0x30050e0);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 6);
  uVar5 = 0;
  do {
    cVar1 = *pcVar4;
    cVar2 = pcVar4[3];
    if (cVar1 == -1) {
      if (cVar2 != -1) {
        *pcVar4 = cVar2;
        pcVar4[3] = -1;
      }
    }
    else if (((-1 < cVar2) && (uVar3 = sub_080C0818((int)cVar1), (uVar3 & 0xa000) != 0)) &&
            (uVar3 = sub_080C0818((int)cVar2), (uVar3 & 0xa000) == 0)) {
      *pcVar4 = cVar2;
      pcVar4[3] = cVar1;
    }
    pcVar4 = pcVar4 + 1;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 3);
  uVar5 = 0;
  do {
    *(char *)(uVar5 + 0x30050e0) = local_28[uVar5];
    uVar5 = uVar5 + 1;
  } while (uVar5 < 6);
  return;
}


// sub_080E2148 @ 0x080E2148

void sub_080E2148(void)

{
  ushort uVar1;
  ushort uVar2;
  int arg0;
  undefined4 uVar3;
  int iVar4;
  undefined4 arg1;
  undefined4 extraout_r1;
  undefined4 arg1_00;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  
  if (((DAT_0203b574 & 3) == 3) && ((DAT_0203b5cc & 3) == 3)) {
    sub_080C30AC(-DAT_0203b55c);
    iVar4 = DAT_0203b5b0;
    uVar3 = DAT_0203b5b4;
    if (DAT_0203b5b0 != 0) {
      arg0 = DAT_0203b5b0;
      sub_0815DBB4(DAT_0203b5b0);
      uVar3 = arg1;
      if (iVar4 < 0) {
        sub_0815D428(arg0,arg1,0x41f00000,0);
        uVar3 = extraout_r1;
      }
      sub_0815D490(arg0,uVar3,0x3fb47ae1,0x47ae147b);
      sub_0815DCF4(arg0,arg1_00);
      uVar3 = sub_0815E5B4(arg0);
    }
    sub_080C30AC(uVar3);
  }
  if (((DAT_0203b574 & 4) != 0) && ((DAT_0203b5cc & 4) != 0)) {
    sub_080C3114(-DAT_0203b568);
    sub_080C3114(DAT_0203b5c0);
  }
  if (((DAT_0203b574 & 8) != 0) && ((DAT_0203b5cc & 8) != 0)) {
    uVar7 = 0;
    do {
      uVar1 = (&DAT_0203b594)[uVar7 * 2];
      uVar2 = (&DAT_0203b596)[uVar7 * 2];
      if ((uVar1 != 0xffff) && (uVar5 = 0, uVar2 != 0)) {
        do {
          sub_080C33AC((uint)uVar1);
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar2);
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 5);
    uVar7 = 0;
    do {
      uVar1 = (&DAT_0203b5ec)[uVar7 * 2];
      uVar2 = (&DAT_0203b5ee)[uVar7 * 2];
      if ((uVar1 != 0xffff) && (uVar5 = 0, uVar2 != 0)) {
        do {
          sub_080C3328((uint)uVar1);
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar2);
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 5);
  }
  if ((((((DAT_0203b574 & 0x10) != 0) && ((DAT_0203b5cc & 0x10) != 0)) &&
       ((DAT_0203b574 & 0x20) != 0)) &&
      (((DAT_0203b5cc & 0x20) != 0 && ((DAT_0203b574 & 0x80) != 0)))) &&
     (((DAT_0203b5cc & 0x80) != 0 &&
      (((DAT_0203b574 & 0x100) != 0 && ((DAT_0203b5cc & 0x100) != 0)))))) {
    uVar7 = 0;
    do {
      uVar1 = (&DAT_0203b57a)[uVar7];
      if (uVar1 != 0xffff) {
        uVar6 = 4;
        while ((uVar6 < 0x10 &&
               (iVar4 = sub_080F2F64(uVar6 + 0x8000 & 0xffff),
               (int)*(short *)(iVar4 + 0x12) != (uint)uVar1))) {
          uVar6 = uVar6 + 1 & 0xffff;
        }
        sub_080C0290(uVar6,1);
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 0xc);
    uVar7 = 0;
    do {
      uVar6 = (uint)(ushort)(&DAT_0203b5d2)[uVar7];
      if (uVar6 != 0xffff) {
        sub_080C062C(uVar6);
        sub_080C29E8(uVar6);
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 0xc);
    sub_080E2080();
  }
  sub_080D1264(DAT_03005f70,0x30046c0);
  return;
}


// umul3232H32 @ 0x080E2364

undefined4 umul3232H32(void)

{
  uint in_r0;
  uint in_r1;
  
  return (int)((ulonglong)in_r1 * (ulonglong)in_r0 >> 0x20);
}


// SoundMain @ 0x080E2374

void SoundMain(void)

{
  byte bVar1;
  dword *arg0;
  uint arg1;
  uint extraout_r1;
  uint unaff_r9;
  
  arg0 = DAT_03007ff0;
  if (*DAT_03007ff0 != 0x68736d53) {
    return;
  }
  *DAT_03007ff0 = 0x68736d54;
  arg1 = (uint)(byte)arg0[3];
  if (arg1 != 0) {
    bVar1 = REG_VCOUNT._0_1_;
    unaff_r9 = (uint)bVar1;
    if (unaff_r9 < 0xa0) {
      unaff_r9 = unaff_r9 + 0xe4;
    }
    arg1 = arg1 + unaff_r9;
  }
  if (arg0[8] != 0) {
    sub_080E2722(arg0[9],arg1,unaff_r9,arg0[8]);
    arg1 = extraout_r1;
  }
  sub_080E2722(arg0,arg1,unaff_r9,arg0[10]);
  (*(code *)0x3007001)();
  return;
}


// SoundMainRAM @ 0x080E23F8

void SoundMainRAM(int arg0)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  dword dVar4;
  int iVar5;
  dword dVar6;
  uint uVar7;
  uint uVar8;
  dword dVar9;
  dword dVar10;
  dword dVar11;
  char *pcVar12;
  char *pcVar13;
  int unaff_r4;
  dword *pdVar14;
  char *unaff_r5;
  uint *puVar15;
  uint *puVar16;
  uint unaff_r8;
  int iVar17;
  int iVar18;
  dword dVar19;
  bool bVar20;
  bool bVar21;
  uint uStack00000004;
  uint *in_stack_00000008;
  char *in_stack_0000000c;
  uint uStack00000010;
  uint in_stack_00000014;
  dword *in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  code *UNRECOVERED_JUMPTABLE;
  
  bVar2 = *(byte *)(arg0 + 5);
  if (bVar2 == 0) {
    if ((unaff_r8 >> 2 & 1) != 0) {
      unaff_r5[0] = '\0';
      unaff_r5[1] = '\0';
      unaff_r5[2] = '\0';
      unaff_r5[3] = '\0';
      unaff_r5 = unaff_r5 + 4;
    }
    uVar8 = unaff_r8 >> 4;
    if ((unaff_r8 >> 3 & 1) != 0) {
      unaff_r5[0] = '\0';
      unaff_r5[1] = '\0';
      unaff_r5[2] = '\0';
      unaff_r5[3] = '\0';
      unaff_r5[4] = '\0';
      unaff_r5[5] = '\0';
      unaff_r5[6] = '\0';
      unaff_r5[7] = '\0';
      unaff_r5 = unaff_r5 + 8;
    }
    do {
      unaff_r5[0] = '\0';
      unaff_r5[1] = '\0';
      unaff_r5[2] = '\0';
      unaff_r5[3] = '\0';
      unaff_r5[4] = '\0';
      unaff_r5[5] = '\0';
      unaff_r5[6] = '\0';
      unaff_r5[7] = '\0';
      unaff_r5[8] = '\0';
      unaff_r5[9] = '\0';
      unaff_r5[10] = '\0';
      unaff_r5[0xb] = '\0';
      unaff_r5[0xc] = '\0';
      unaff_r5[0xd] = '\0';
      unaff_r5[0xe] = '\0';
      unaff_r5[0xf] = '\0';
      unaff_r5 = unaff_r5 + 0x10;
      uVar7 = uVar8 - 1;
      bVar20 = 0 < (int)uVar8;
      uVar8 = uVar7;
    } while (uVar7 != 0 && bVar20);
  }
  else {
    uVar8 = unaff_r8;
    if (unaff_r4 == 2) {
      pcVar12 = (char *)(arg0 + 0x350);
    }
    else {
      pcVar12 = unaff_r5 + unaff_r8;
    }
    do {
      iVar5 = ((int)*unaff_r5 + (int)*pcVar12) * (uint)bVar2;
      cVar3 = (char)((uint)iVar5 >> 8);
      if ((iVar5 >> 8 & 0x80U) != 0) {
        cVar3 = cVar3 + '\x01';
      }
      *unaff_r5 = cVar3;
      uVar7 = uVar8 - 1;
      bVar20 = 0 < (int)uVar8;
      uVar8 = uVar7;
      unaff_r5 = unaff_r5 + 1;
      pcVar12 = pcVar12 + 1;
    } while (uVar7 != 0 && bVar20);
  }
  dVar4 = in_stack_00000018[6];
  pdVar14 = in_stack_00000018 + 0x14;
  uStack00000004 = (uint)*(byte *)((int)in_stack_00000018 + 6);
LAB_080e246c:
  dVar11 = pdVar14[9];
  if (in_stack_00000014 != 0) {
    bVar2 = REG_VCOUNT._0_1_;
    uVar8 = (uint)bVar2;
    if (uVar8 < 0xa0) {
      uVar8 = uVar8 + 0xe4;
    }
    if (in_stack_00000014 <= uVar8) {
LAB_080e270e:
      *in_stack_00000018 = 0x68736d53;
                    /* WARNING: Could not recover jumptable at 0x080e2722. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(in_stack_0000001c,in_stack_00000020,in_stack_00000024);
      return;
    }
  }
  bVar2 = (byte)*pdVar14;
  uStack00000010 = (uint)bVar2;
  if ((bVar2 & 199) != 0) {
    if ((bVar2 & 0x80) == 0) {
      uVar8 = (uint)*(byte *)((int)pdVar14 + 9);
      if ((bVar2 & 4) == 0) {
        if ((bVar2 & 0x40) == 0) {
          if ((uStack00000010 & 3) == 2) {
            uVar8 = *(byte *)((int)pdVar14 + 5) * uVar8 >> 8;
            uVar7 = (uint)*(byte *)((int)pdVar14 + 6);
            if (uVar8 <= uVar7) {
              if (uVar7 == 0) goto LAB_080e24ee;
              uStack00000010 = uStack00000010 - 1;
              *(char *)pdVar14 = (char)uStack00000010;
              uVar8 = uVar7;
            }
          }
          else if ((uStack00000010 & 3) == 3) goto LAB_080e251e;
        }
        else {
          uVar8 = *(byte *)((int)pdVar14 + 7) * uVar8 >> 8;
          if (uVar8 <= (byte)pdVar14[3]) {
LAB_080e24ee:
            if ((byte)pdVar14[3] == 0) goto LAB_080e24d6;
            uStack00000010 = uStack00000010 | 4;
            *(char *)pdVar14 = (char)uStack00000010;
            uVar8 = (uint)(byte)pdVar14[3];
          }
        }
      }
      else {
        bVar2 = *(byte *)((int)pdVar14 + 0xd);
        iVar5 = bVar2 - 1;
        *(char *)((int)pdVar14 + 0xd) = (char)iVar5;
        if (bVar2 == 0 || iVar5 == 0) goto LAB_080e24d6;
      }
    }
    else {
      if ((bVar2 & 0x40) != 0) {
LAB_080e24d6:
        *(undefined1 *)pdVar14 = 0;
        goto LAB_080e2704;
      }
      uStack00000010 = 3;
      *(undefined1 *)pdVar14 = 3;
      pdVar14[10] = dVar11 + 0x10;
      pdVar14[6] = *(dword *)(dVar11 + 0xc);
      uVar8 = 0;
      *(undefined1 *)((int)pdVar14 + 9) = 0;
      pdVar14[7] = 0;
      if ((*(byte *)(dVar11 + 3) & 0xc0) != 0) {
        uStack00000010 = 0x13;
        *(undefined1 *)pdVar14 = 0x13;
      }
LAB_080e251e:
      uVar8 = uVar8 + (byte)pdVar14[1];
      if (0xfe < uVar8) {
        uStack00000010 = uStack00000010 - 1;
        *(char *)pdVar14 = (char)uStack00000010;
        uVar8 = 0xff;
      }
    }
    *(char *)((int)pdVar14 + 9) = (char)uVar8;
    *(char *)((int)pdVar14 + 10) =
         (char)((uVar8 * (*(byte *)((int)in_stack_00000018 + 7) + 1) >> 4) *
                ((uint)*(byte *)((int)pdVar14 + 2) + (uint)*(byte *)((int)pdVar14 + 3)) >> 9);
    uStack00000010 = uStack00000010 & 0x10;
    if (uStack00000010 != 0) {
      in_stack_0000000c = (char *)(dVar11 + 0x10 + *(int *)(dVar11 + 8));
      uStack00000010 = *(int *)(dVar11 + 0xc) - *(int *)(dVar11 + 8);
    }
    dVar11 = pdVar14[6];
    pcVar12 = (char *)pdVar14[10];
    iVar5 = (uint)*(byte *)((int)pdVar14 + 10) * 0x10000;
    dVar6 = dVar11;
    puVar15 = in_stack_00000008;
    uVar8 = unaff_r8;
    if ((*pdVar14 & 0x800) == 0) {
      dVar19 = pdVar14[7];
      dVar9 = pdVar14[8];
      dVar6 = (dword)*pcVar12;
      pcVar12 = pcVar12 + 1;
      iVar18 = (int)*pcVar12 - dVar6;
      do {
        uVar7 = *puVar15;
        dVar10 = dVar11;
        do {
          puVar16 = puVar15;
          uVar7 = (iVar5 * (dVar6 + ((int)(dVar19 * iVar18) >> 0x17)) & 0xff00ffff) +
                  (uVar7 >> 8 | uVar7 << 0x18);
          dVar19 = dVar19 + dVar4 * dVar9;
          uVar1 = dVar19 >> 0x17;
          dVar11 = dVar10;
          if (uVar1 != 0) {
            dVar19 = dVar19 & 0xc07fffff;
            dVar11 = dVar10 - uVar1;
            if (dVar11 == 0 || (int)dVar10 < (int)uVar1) {
              if (uStack00000010 == 0) goto LAB_080e2650;
              iVar17 = -dVar11;
              while( true ) {
                bVar21 = SCARRY4(uStack00000010,dVar11);
                dVar11 = uStack00000010 + dVar11;
                bVar20 = dVar11 == 0;
                dVar6 = uStack00000010;
                pcVar12 = in_stack_0000000c;
                if (!bVar20 && (int)dVar11 < 0 == bVar21) break;
                iVar17 = iVar17 - uStack00000010;
              }
            }
            else {
              iVar17 = uVar1 - 1;
              bVar20 = iVar17 == 0;
              if (bVar20) {
                dVar6 = dVar6 + iVar18;
              }
            }
            if (!bVar20) {
              pcVar12 = pcVar12 + iVar17;
              dVar6 = (dword)*pcVar12;
            }
            pcVar12 = pcVar12 + 1;
            iVar18 = (int)*pcVar12 - dVar6;
          }
          dVar10 = dVar11;
          puVar15 = puVar16 + 0x10000000;
        } while (puVar16 < (uint *)0xc0000000);
        puVar15 = puVar16 + 0x10000001;
        puVar16[0x10000000] = uVar7;
        uVar7 = uVar8 - 4;
        bVar20 = 3 < (int)uVar8;
        uVar8 = uVar7;
      } while (uVar7 != 0 && bVar20);
      pcVar12 = pcVar12 + -1;
      pdVar14[7] = dVar19;
    }
    else {
      do {
        dVar11 = dVar6;
        if (4 < (int)dVar6) {
          dVar11 = dVar6 - uVar8;
          if (dVar11 == 0 || (int)dVar6 < (int)uVar8) {
            uVar7 = (dVar11 + uVar8) - 4;
            iVar18 = uVar8 - uVar7;
            dVar11 = dVar11 + uVar8 & 3;
            uVar8 = uVar7;
            if (dVar11 == 0) {
              dVar11 = 4;
            }
          }
          else {
            iVar18 = 0;
          }
          do {
            uVar7 = *puVar15;
            pcVar13 = pcVar12;
            do {
              puVar16 = puVar15;
              pcVar12 = pcVar13 + 1;
              uVar7 = (iVar5 * *pcVar13 & 0xff00ffffU) + (uVar7 >> 8 | uVar7 << 0x18);
              pcVar13 = pcVar12;
              puVar15 = puVar16 + 0x10000000;
            } while (puVar16 < (uint *)0xc0000000);
            puVar15 = puVar16 + 0x10000001;
            puVar16[0x10000000] = uVar7;
            uVar7 = uVar8 - 4;
            bVar20 = 3 < (int)uVar8;
            uVar8 = uVar7;
          } while (uVar7 != 0 && bVar20);
          uVar8 = uVar7 + iVar18;
          if (uVar8 == 0) break;
        }
        uVar7 = *puVar15;
        do {
          puVar16 = puVar15;
          uVar7 = (iVar5 * *pcVar12 & 0xff00ffffU) + (uVar7 >> 8 | uVar7 << 0x18);
          dVar11 = dVar11 - 1;
          pcVar12 = pcVar12 + 1;
          if ((dVar11 == 0) &&
             (dVar11 = uStack00000010, pcVar12 = in_stack_0000000c, uStack00000010 == 0))
          goto LAB_080e2650;
          puVar15 = puVar16 + 0x10000000;
        } while (puVar16 < (uint *)0xc0000000);
        puVar15 = puVar16 + 0x10000001;
        puVar16[0x10000000] = uVar7;
        uVar7 = uVar8 - 4;
        bVar20 = 3 < (int)uVar8;
        dVar6 = dVar11;
        uVar8 = uVar7;
      } while (uVar7 != 0 && bVar20);
    }
    pdVar14[6] = dVar11;
    pdVar14[10] = (dword)pcVar12;
  }
  goto LAB_080e2704;
LAB_080e2650:
  *(undefined1 *)pdVar14 = 0;
  uVar8 = (3 - ((uint)puVar16 >> 0x1e)) * 8 & 0x1f;
  *(uint *)((uint)puVar16 & 0x3fffffff) = uVar7 >> uVar8 | uVar7 << 0x20 - uVar8;
LAB_080e2704:
  if (uStack00000004 - 1 == 0 || (int)uStack00000004 < 1) goto LAB_080e270e;
  pdVar14 = pdVar14 + 0x10;
  uStack00000004 = uStack00000004 - 1;
  goto LAB_080e246c;
}


// sub_080E2722 @ 0x080E2722

void sub_080E2722(undefined4 arg0,undefined4 arg1,undefined4 arg2,code *arg3)

{
                    /* WARNING: Could not recover jumptable at 0x080e2722. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*arg3)();
  return;
}


// SoundMainBTM @ 0x080E2728

void SoundMainBTM(undefined4 *arg0)

{
  *arg0 = 0;
  arg0[1] = 0;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
  arg0[6] = 0;
  arg0[7] = 0;
  arg0[8] = 0;
  arg0[9] = 0;
  arg0[10] = 0;
  arg0[0xb] = 0;
  arg0[0xc] = 0;
  arg0[0xd] = 0;
  arg0[0xe] = 0;
  arg0[0xf] = 0;
  return;
}


