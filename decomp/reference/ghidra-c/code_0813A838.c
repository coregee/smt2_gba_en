/* Ghidra decompilation of asm/code_0813A838.s (reference only; not compiled). */

// ScriptOpAlt_438 @ 0x0813A838

void ScriptOpAlt_438(void)

{
  DAT_0203db40 = DAT_0203db40 + 3;
  return;
}


// ScriptOp_439 @ 0x0813A848

void ScriptOp_439(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  DAT_03006964 = sub_080B4420(0x60,1);
  DAT_0203db6e = 1;
  DAT_0203db5a = 0x34;
  return;
}


// ScriptOpAlt_439 @ 0x0813A888

void ScriptOpAlt_439(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  return;
}


// ScriptOp_43A @ 0x0813A898

void ScriptOp_43A(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOpAlt_43A @ 0x0813A8A8

void ScriptOpAlt_43A(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_43B @ 0x0813A8B8

void ScriptOp_43B(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_080BA8D8(1,1);
  DAT_0203db5a = 0x4a;
  DAT_0203db6e = 1;
  return;
}


// ScriptOpAlt_43B @ 0x0813A8E8

void ScriptOpAlt_43B(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_43C @ 0x0813A8F8

void ScriptOp_43C(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOpAlt_43C @ 0x0813A908

void ScriptOpAlt_43C(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_43D @ 0x0813A918

void ScriptOp_43D(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint arg0;
  uint uVar8;
  
  uVar7 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar7 * 2 + DAT_03006950);
  uVar8 = (uint)DAT_0203db28;
  iVar4 = sub_080C104C();
  arg0 = 4;
  while ((uVar3 = CONCAT22(uVar2,uVar1), arg0 < iVar4 + 4U &&
         ((iVar5 = sub_080C09B0(arg0), iVar5 == 0 ||
          (uVar6 = sub_080C07E0(arg0), uVar3 = DAT_030068e4, (int)(short)uVar6 != uVar8))))) {
    arg0 = arg0 + 1;
  }
  DAT_030068e4 = uVar3;
  return;
}


// ScriptOpAlt_43D @ 0x0813A988

void ScriptOpAlt_43D(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  return;
}


// ScriptOp_43E @ 0x0813A998

void ScriptOp_43E(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  uint arg0;
  
  uVar7 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar7 * 2 + DAT_03006950);
  iVar3 = sub_080C104C();
  arg0 = 4;
  do {
    if (iVar3 + 4U <= arg0) {
      DAT_030068e4 = CONCAT22(uVar2,uVar1);
      return;
    }
    iVar4 = sub_080C09B0(arg0);
    if (iVar4 != 0) {
      uVar5 = sub_080C07E0(arg0);
      uVar5 = uVar5 & 0xffff;
      uVar6 = sub_080C0818(arg0);
      if (((uVar5 != 0) && (uVar5 != 0xde)) && ((uVar6 & 0xa000) == 0)) {
        if (uVar5 != 0x8b) {
          return;
        }
        iVar4 = sub_080C2340(0x23);
        if (iVar4 != 0) {
          return;
        }
      }
    }
    arg0 = arg0 + 1;
  } while( true );
}


// ScriptOpAlt_43E @ 0x0813AA28

void ScriptOpAlt_43E(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  return;
}


// ScriptOp_43F @ 0x0813AA38

void ScriptOp_43F(void)

{
  ushort uVar1;
  ushort uVar2;
  
  DAT_0203dac8 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950));
  DAT_0203dacc = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 3) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 2) * 2 + DAT_03006950));
  uVar2 = DAT_0203db40 + 6;
  DAT_0203dad0 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 5) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 4) * 2 + DAT_03006950));
  uVar1 = DAT_0203db40 + 7;
  DAT_0203db40 = DAT_0203db40 + 8;
  DAT_0203dad4 = CONCAT22(*(undefined2 *)((uint)uVar1 * 2 + DAT_03006950),
                          *(undefined2 *)((uint)uVar2 * 2 + DAT_03006950));
  sub_0812F198();
  DAT_03006844 = 3;
  DAT_03006940 = 0;
  DAT_0300696c = 0;
  sub_0812F2B4(3);
  DAT_0203db6e = 1;
  sub_080AD0FC(0x878fc80,0xffff);
  DAT_0203db5a = 0x18;
  return;
}


// ScriptOpAlt_43F @ 0x0813AB18

void ScriptOpAlt_43F(void)

{
  DAT_0203db40 = DAT_0203db40 + 8;
  return;
}


// ScriptOp_440 @ 0x0813AB28

void ScriptOp_440(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  ushort uVar4;
  
  uVar4 = DAT_0203db40 + 2;
  uVar1 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar2 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  iVar3 = sub_080F4360(0x35);
  if (iVar3 == 0) {
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// ScriptOpAlt_440 @ 0x0813AB70

void ScriptOpAlt_440(void)

{
  DAT_0203db40 = DAT_0203db40 + 3;
  return;
}


// ScriptOp_441 @ 0x0813AB80

void ScriptOp_441(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = DAT_0203db40 + 2;
  DAT_0203db00 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950));
  uVar1 = DAT_0203db40 + 3;
  DAT_0203db40 = DAT_0203db40 + 4;
  DAT_0203db04 = CONCAT22(*(undefined2 *)((uint)uVar1 * 2 + DAT_03006950),
                          *(undefined2 *)((uint)uVar2 * 2 + DAT_03006950));
  DAT_030069cc = 1;
  sub_0812F198();
  uVar4 = 0;
  uVar3 = 0;
  do {
    if ((*(ushort *)(uVar3 * 2 + 0x3006990) & 0xff) != 0xff) {
      uVar4 = uVar4 * 0x10000 + 0x10000 >> 0x10;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 5);
  DAT_03006604 = (short)uVar4 + -1;
  uVar3 = 0;
  do {
    *(undefined2 *)(uVar3 * 2 + 0x203db88) = *(undefined2 *)(uVar3 * 2 + 0x3006990);
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 5);
  DAT_03006940 = 0;
  DAT_0300696c = 0;
  DAT_03006844 = 1;
  sub_0812F2B4(1);
  DAT_0203db6e = 1;
  sub_080AD0FC(0x878fc80,0xffff);
  DAT_0203db5a = 0xd;
  return;
}


// ScriptOpAlt_441 @ 0x0813AC88

void ScriptOpAlt_441(void)

{
  DAT_0203db40 = DAT_0203db40 + 4;
  return;
}


// sub_0813AC98 @ 0x0813AC98

undefined4 sub_0813AC98(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_080C1D9C();
  uVar3 = sub_0813E60C((uint)DAT_0203db7c,0xc);
  bVar1 = *(byte *)(((uVar2 & 0xff) >> 4) + ((uVar3 & 0xf) >> 3) + 0x8790cf0);
  if (bVar1 < 0x13) {
    if (bVar1 < 0xe) {
      uVar4 = 2;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0813acda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar4);
  return uVar4;
}


// ScriptOp_442 @ 0x0813ACDC

void ScriptOp_442(void)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  short *psVar8;
  ushort uVar9;
  uint uVar10;
  undefined4 uVar11;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar9 = DAT_0203db40 + 3;
  uVar3 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 2) * 2 + DAT_03006950),
                   *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950));
  uVar2 = DAT_0203db40 + 4;
  DAT_0203db40 = DAT_0203db40 + 5;
  uVar11 = CONCAT22(*(undefined2 *)((uint)uVar2 * 2 + DAT_03006950),
                    *(undefined2 *)((uint)uVar9 * 2 + DAT_03006950));
  if (sVar1 == 0) {
    iVar4 = sub_080C104C();
    for (uVar10 = 4; (int)uVar10 < iVar4 + 4; uVar10 = uVar10 + 1 & 0xffff) {
      iVar5 = sub_080C09B0(uVar10);
      if ((iVar5 != 0) && (uVar6 = sub_080C07E0(uVar10), (int)(short)uVar6 == (uint)DAT_0203db7c)) {
        if ((int)uVar10 < iVar4 + 4) {
          uVar7 = sub_080C0818(uVar10);
          if ((uVar7 & 0x8000) != 0) goto LAB_0813b0d2;
          if (((uVar7 & 0xffff) != 0) ||
             ((int)(short)(&DAT_030046d8)[uVar10 * 0x40] <=
              (int)(((int)(short)(&DAT_030046da)[uVar10 * 0x40] -
                     ((int)(short)(&DAT_030046da)[uVar10 * 0x40] >> 0x1f) & 0x1ffffU) >> 1)))
          goto LAB_0813b0ba;
        }
        break;
      }
    }
    goto LAB_0813b118;
  }
  if (sVar1 == 1) {
    uVar10 = sub_0813E60C((uint)DAT_0203db7c,0xb);
    if ((uVar10 & 0xff) < 0x70) {
LAB_0813b0ba:
      DAT_030068e4 = uVar3;
      goto LAB_0813b118;
    }
    if ((uVar10 & 0xff) < 0x90) goto LAB_0813b118;
  }
  else if (sVar1 == 2) {
    uVar10 = sub_0813AC98();
    uVar10 = uVar10 & 0xffff;
    if (uVar10 == 0) goto LAB_0813b118;
    if (uVar10 == 1) goto LAB_0813b0ba;
    if (uVar10 != 2) goto LAB_0813b118;
  }
  else {
    if (sVar1 != 3) {
      if ((ushort)(sVar1 - 4U) < 2) {
        DAT_030068d8 = 0xff;
        if (sVar1 == 4) {
          DAT_0203dac8 = uVar3;
          DAT_0203dacc = uVar11;
          sub_0813BECC(0);
          DAT_030068a4 = sub_080D3400(3,0,0xe2);
          sub_080D347C(0xe2,0xffff,0xffff,0xffff);
        }
        else {
          DAT_0203dac8 = uVar3;
          DAT_0203dacc = uVar11;
          sub_0813BECC(0x10);
          sub_08130C6C();
          DAT_030068a4 = sub_080D3400(4,0,0);
          sub_080D347C((uint)DAT_03006980,(uint)DAT_03006982,(uint)DAT_03006984,(uint)DAT_03006986);
        }
      }
      else {
        if (sVar1 != 6) {
          if (sVar1 == 7) {
            uVar10 = sub_0813E804((uint)DAT_0203db28);
            if ((uVar10 & 0xffff) == 0) {
              iVar4 = sub_080C104C();
              uVar10 = 0;
              if (0 < iVar4) {
                do {
                  iVar5 = sub_080C09B0(uVar10 + 4);
                  if (iVar5 == 0) {
                    sub_080C33AC((uint)DAT_0203db50);
                    sub_080C33AC((uint)DAT_030068d8);
                    sub_080C062C((uint)DAT_0203db28);
                    goto LAB_0813b118;
                  }
                  uVar10 = uVar10 + 1 & 0xffff;
                } while ((int)uVar10 < iVar4);
              }
              goto LAB_0813b0ba;
            }
          }
          else {
            if (sVar1 == 8) {
              uVar10 = 0;
              DAT_0203dac8 = uVar3;
              DAT_0203dacc = uVar11;
              do {
                *(undefined2 *)(uVar10 * 2 + 0x203db08) = 0;
                uVar10 = uVar10 + 1 & 0xffff;
              } while (uVar10 < 0x10);
              Combatant_DecodeName(0x30046c0,0x203db08);
              uVar10 = 0xe;
              do {
                if (*(short *)(uVar10 * 2 + 0x203db08) != 0) {
                  psVar8 = (short *)((uVar10 + 1) * 2 + 0x203db08);
                  sVar1 = *psVar8;
                  if ((sVar1 == 0) || (sVar1 == 0x318)) {
                    *psVar8 = 0x318;
                    break;
                  }
                }
                uVar10 = uVar10 - 1 & 0xffff;
              } while (uVar10 != 0);
              sub_08133E70(0x27,0x68,0,uVar10 + 1 & 0xffff);
              uVar10 = 0;
              do {
                *(undefined2 *)(uVar10 * 2 + 0x203db08) = 0;
                uVar10 = uVar10 + 1 & 0xffff;
              } while (uVar10 < 0x10);
              iVar4 = sub_080C09B0(1);
              if (iVar4 == 0) {
                Combatant_DecodeName(0x30047c0,0x203db08);
              }
              else {
                Combatant_DecodeName(0x3004740,0x203db08);
              }
              uVar10 = 0xe;
              do {
                if (*(short *)(uVar10 * 2 + 0x203db08) != 0) {
                  psVar8 = (short *)((uVar10 + 1) * 2 + 0x203db08);
                  sVar1 = *psVar8;
                  if ((sVar1 == 0) || (sVar1 == 0x318)) {
                    *psVar8 = 0x318;
                    break;
                  }
                }
                uVar10 = uVar10 - 1 & 0xffff;
              } while (uVar10 != 0);
              sub_08133E70(0x27,0x76,0,uVar10 + 1 & 0xffff);
              DAT_0203db5a = 0x48;
              DAT_03006688 = 2;
              sub_080AD0FC(0x878fd14,0xffff);
              goto LAB_0813b07a;
            }
            if (sVar1 != 9) goto LAB_0813b118;
            sub_08132350(0x3a);
            uVar10 = sub_080C0818(0);
            if ((uVar10 & 0x200) != 0) goto LAB_0813b0ba;
            if ((uVar10 & 0xfe00) == 0) {
              sub_080C08F8(0,uVar10 & 0xfc07 | 0x200);
              goto LAB_0813b118;
            }
          }
          goto LAB_0813b0d2;
        }
        DAT_030068d8 = DAT_0203db50;
        DAT_0203dac8 = uVar3;
        DAT_0203dacc = uVar11;
        sub_0813BECC(0xf0);
        sub_08130C6C();
        DAT_030068a4 = sub_080D3400(4,0,0);
        sub_080D347C((uint)DAT_03006980,(uint)DAT_03006982,(uint)DAT_03006984,(uint)DAT_03006986);
      }
LAB_0813b07a:
      DAT_0203db6e = 1;
      goto LAB_0813b118;
    }
    uVar10 = sub_080C0794(0);
    if ((uVar10 & 0xff00) < 0x7000) goto LAB_0813b0ba;
    if ((uVar10 & 0xff00) < 0x9000) goto LAB_0813b118;
  }
LAB_0813b0d2:
  DAT_030068e4 = uVar11;
LAB_0813b118:
                    /* WARNING: Could not recover jumptable at 0x0813b122. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOpAlt_442 @ 0x0813B128

void ScriptOpAlt_442(void)

{
  DAT_0203db40 = DAT_0203db40 + 5;
  return;
}


// ScriptOp_443 @ 0x0813B138

void ScriptOp_443(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  
  uVar1 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 2) * 2 + DAT_03006950);
  uVar9 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 4) * 2 + DAT_03006950),
                   *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 3) * 2 + DAT_03006950));
  uVar6 = DAT_0203db40 + 6;
  uVar3 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 5) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 7;
  uVar4 = *(undefined2 *)((uint)uVar6 * 2 + DAT_03006950);
  uVar7 = sub_0815B9DC((uint)DAT_0203db7c);
  if ((uVar7 & 0xffff) == 0x22) {
    uVar7 = sub_0813E60C((uint)DAT_0203db7c,0);
    DAT_0203db2c = (uVar7 & 0xff) << 1;
    uVar5 = CONCAT22(uVar2,uVar1);
  }
  else {
    uVar7 = sub_080C2244();
    uVar5 = CONCAT22(uVar4,uVar3);
    if ((uVar7 & 7) == 0) {
      uVar7 = sub_0813E60C((uint)DAT_0203db7c,0);
      DAT_0203db2c = uVar7 & 0xff;
      iVar8 = sub_080F2F64(0x8000);
      uVar5 = uVar9;
      if (DAT_0203db2c < *(uint *)(iVar8 + 8)) {
        iVar8 = sub_080F2F64(0x8000);
        *(uint *)(iVar8 + 8) = *(int *)(iVar8 + 8) - DAT_0203db2c;
      }
      else {
        iVar8 = sub_080F2F64(0x8000);
        *(undefined4 *)(iVar8 + 8) = 0;
      }
    }
  }
  DAT_030068e4 = uVar5;
  return;
}


// ScriptOpAlt_443 @ 0x0813B254

void ScriptOpAlt_443(void)

{
  DAT_0203db40 = DAT_0203db40 + 7;
  return;
}


// sub_0813B264 @ 0x0813B264

void sub_0813B264(void)

{
  return;
}


// sub_0813B268 @ 0x0813B268

undefined4 sub_0813B268(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = sub_0813756C(DAT_0203db50 - 0x120 & 0xffff);
  if ((uVar1 & 0xff) < 99) {
    sub_08137518(DAT_0203db50 - 0x120 & 0xffff,1);
    uVar1 = sub_0813756C(DAT_0203db50 - 0x120 & 0xffff);
    if ((uVar1 & 0xff) == 9) {
      sub_0813B264();
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ScriptOp_444 @ 0x0813B2C0

void ScriptOp_444(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  ushort uVar4;
  
  uVar4 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  DAT_0203db50 = 0x127;
  iVar3 = sub_0813B268();
  if (iVar3 != 0) {
    DAT_030068e4 = 0x80a0bc6;
    DAT_03006840 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// ScriptOpAlt_444 @ 0x0813B324

void ScriptOpAlt_444(void)

{
  return;
}


// sub_0813B328 @ 0x0813B328

void sub_0813B328(uint arg0)

{
  DAT_03006950 = 0x8032bbc;
  DAT_030068e4 = *(undefined4 *)((arg0 & 0x7fff) * 4 + 0x8032bbc);
  return;
}


// sub_0813B350 @ 0x0813B350

void sub_0813B350(uint arg0,uint arg1)

{
  uint uVar1;
  uint uVar2;
  dword dVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = arg0 & 0xffff;
  arg0_00 = arg1 & 0xffff;
  iVar6 = 0xf;
  uVar5 = uVar1;
  do {
    if ((uVar5 & 1) == 0) goto LAB_0813b3ee;
    uVar2 = sub_080C0818(arg0_00);
    uVar2 = uVar2 & 0xffff;
    if ((uVar2 & uVar1) == 0) {
      iVar4 = iVar6 * 2;
      if ((*(ushort *)(iVar4 + 0x8790d80) & uVar2) != 0) {
        uVar2 = 1;
        goto LAB_0813b3de;
      }
      sub_080C08F8(arg0_00,uVar2 & *(ushort *)(iVar4 + 0x8790da0) | uVar1);
      if (iVar6 == 0) {
        iVar4 = sub_080F2F64(arg0_00 + 0x8000 & 0xffff);
        *(undefined2 *)(iVar4 + 0x18) = 0;
      }
      else if (iVar6 < 0xf) {
        if (arg0_00 < 0x10) {
          dVar3 = 0x8790dde;
        }
        else {
          dVar3 = 0x8790dc0;
        }
        uVar2 = (uint)*(ushort *)(iVar4 + dVar3);
        goto LAB_0813b3de;
      }
    }
    else {
      uVar2 = 0;
LAB_0813b3de:
      if (iVar6 != 1) {
        sub_0813B328(uVar2);
      }
    }
LAB_0813b3ee:
    uVar5 = uVar5 >> 1;
    iVar6 = iVar6 + -1;
    if (iVar6 < 0) {
                    /* WARNING: Could not recover jumptable at 0x0813b3fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  } while( true );
}


// sub_0813B400 @ 0x0813B400

void sub_0813B400(void)

{
  uint uVar1;
  uint arg0;
  
  arg0 = DAT_0203db50 - 0x120 & 0xffff;
  uVar1 = sub_0813756C(arg0);
  if ((uVar1 & 0xff) != 0) {
    sub_08137518(arg0,0xffffffff);
    sub_0813B264();
  }
  return;
}


// sub_0813B438 @ 0x0813B438

void sub_0813B438(uint arg0)

{
  int iVar1;
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  iVar1 = sub_080F2F64(arg0 * 0x10000 + 0x80000000 >> 0x10);
  switch(DAT_030065e0) {
  case 0x9d:
  case 0xa3:
    sub_08136270(arg0_00,0,(int)*(char *)(iVar1 + 0x28) / 2);
    break;
  case 0x9e:
  case 0xa4:
    sub_08136270(arg0_00,1,(int)*(char *)(iVar1 + 0x29) / 2);
    break;
  case 0x9f:
  case 0xa5:
    sub_08136270(arg0_00,2,(int)*(char *)(iVar1 + 0x2a) / 2);
    break;
  case 0xa0:
    sub_08136270(arg0_00,3,(int)*(char *)(iVar1 + 0x2b) / 2);
    break;
  case 0xa1:
    sub_08136270(arg0_00,4,(int)*(char *)(iVar1 + 0x2c) / 2);
    break;
  case 0xa2:
    sub_08136270(arg0_00,5,(int)*(char *)(iVar1 + 0x2d) / 2);
  }
  sub_080BF938(arg0_00);
  sub_080CDC34();
  return;
}


// ScriptOp_445 @ 0x0813B524

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScriptOp_445(int arg0)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  short sVar11;
  uint uVar12;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar11 = DAT_0203db40 + 1;
  sVar2 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = sVar11;
  if (sVar2 == 3) {
    iVar5 = sub_080C104C();
    uVar12 = 4;
    if (4 < iVar5 + 4) {
      do {
        iVar6 = sub_080C09B0(uVar12);
        if ((iVar6 != 0) && (uVar7 = sub_080C07E0(uVar12), (int)(short)uVar7 == (uint)DAT_0203db7c))
        {
          uVar8 = sub_080C0818(uVar12);
          if ((uVar8 & 0x8000) != 0) {
            sub_080C08BC(uVar12,1);
            (&DAT_030046d8)[uVar12 * 0x40] = (&DAT_030046da)[uVar12 * 0x40];
            goto LAB_0813b5a6;
          }
          if ((int)(&DAT_030046da)[uVar12 * 0x40] / 2 < (int)(&DAT_030046d8)[uVar12 * 0x40]) {
            sub_080C08BC(uVar12,1);
            (&DAT_030046d8)[uVar12 * 0x40] = (&DAT_030046da)[uVar12 * 0x40];
            goto LAB_0813b5a6;
          }
          break;
        }
        uVar12 = uVar12 + 1 & 0xffff;
      } while ((int)uVar12 < iVar5 + 4);
    }
    goto LAB_0813bc20;
  }
  if (sVar2 == 4) {
    DAT_030068e0 = sub_0812EE8C(0,0);
    DAT_0203db5a = 0x4f;
    goto LAB_0813ba10;
  }
  if (sVar2 != 5) {
    if (sVar2 != 6) {
      if (sVar2 == 7) {
        uVar7 = sub_080EF954();
        sub_080EF930(uVar7);
        DAT_030068b4 = DAT_030069e8;
        goto LAB_0813bc20;
      }
      if (sVar2 == 8) {
        uVar7 = sub_0813E60C((uint)DAT_0203db7c,0);
        DAT_030046d8 = DAT_030046d8 - ((ushort)uVar7 & 0xff);
        if ((DAT_030046d8 + -1) * 0x10000 < 1) {
          DAT_030046d8 = 1;
        }
        goto LAB_0813bc20;
      }
      if (sVar2 == 9) {
        uVar12 = sub_080C2244();
        iVar5 = sub_0813E60C((uint)DAT_0203db7c,0);
        DAT_030046d8 = DAT_030046d8 -
                       ((ushort)(((uVar12 & 7) + 1 + iVar5) * 0x10000 >> 0x10) & 0xff);
      }
      else {
        if (sVar2 != 10) {
          if (sVar2 == 0xb) {
            uVar12 = sub_0813E60C((uint)DAT_0203db7c,0);
            iVar5 = sub_080C09B0(1);
            if (iVar5 == 0) {
              iVar5 = sub_080C09B0(2);
              if (iVar5 == 0) goto LAB_0813bc20;
              iVar5 = 2;
            }
            else {
              iVar5 = 1;
            }
            (&DAT_030046dc)[iVar5 * 0x40] =
                 (&DAT_030046dc)[iVar5 * 0x40] - ((short)((uVar12 & 0xff) >> 2) + 1);
            if ((short)(&DAT_030046dc)[iVar5 * 0x40] < 1) {
              (&DAT_030046dc)[iVar5 * 0x40] = 0;
            }
            goto LAB_0813b5a6;
          }
          if (sVar2 == 0xc) {
            if ((DAT_0300684c & 8) == 0) {
              bVar3 = 8;
LAB_0813b75e:
              DAT_0300684c = bVar3 | DAT_0300684c;
              goto LAB_0813bc20;
            }
            bVar3 = 0xf7;
          }
          else {
            if (sVar2 != 0xd) {
              if (sVar2 == 0xe) {
                bVar3 = 1;
              }
              else if (sVar2 == 0xf) {
                bVar3 = 4;
              }
              else {
                if (sVar2 != 0x10) {
                  if (sVar2 == 0x11) {
                    iVar5 = sub_080C104C();
                    uVar12 = 0;
                    if (0 < iVar5 + 4) {
                      do {
                        iVar6 = sub_080C0A00(uVar12);
                        if (iVar6 == 1) {
                          uVar8 = uVar12 + 0x8000 & 0xffff;
                          iVar6 = sub_080F2F64(uVar8);
                          iVar9 = sub_080F2F64(uVar8);
                          if (*(short *)(iVar6 + 0x18) < *(short *)(iVar9 + 0x1a)) {
                            sub_080C0A7C(uVar12);
                            break;
                          }
                        }
                        uVar12 = uVar12 + 1 & 0xffff;
                      } while ((int)uVar12 < iVar5 + 4);
                    }
                    goto LAB_0813bc20;
                  }
                  if (sVar2 == 0x12) {
                    uVar12 = sub_0813E60C((uint)DAT_0203db7c,5);
                    DAT_0203db2c = uVar12 & 0xff;
                    sub_08132350(0x41);
                    uVar12 = 0;
                    cVar1 = DAT_030050e0;
                    while ((cVar1 != '\0' && (uVar12 = uVar12 + 1 & 0xffff, uVar12 < 5))) {
                      cVar1 = (&DAT_030050e0)[uVar12];
                    }
                    sub_080C8890(uVar12,1);
                  }
                  else {
                    if (sVar2 != 0x13) {
                      if (sVar2 == 0x14) {
                        sub_08132350(0x39);
                        goto LAB_0813bc20;
                      }
                      if (sVar2 == 0x15) {
                        sub_08132350(0x40);
                        iVar5 = sub_080F2F64(0x8000);
                        if ((uint)(int)*(short *)(iVar5 + 0x18) < DAT_0203db2c) {
                          iVar5 = sub_080F2F64(0x8000);
                          *(short *)(iVar5 + 0x18) = *(short *)(iVar5 + 0x18) - (short)DAT_0203db2c;
                        }
                        iVar5 = sub_080F2F64(0x8000);
                        if ((((int)*(short *)(iVar5 + 0x18) & 0x8000U) == 0) &&
                           (iVar5 = sub_080F2F64(0x8000), 0 < *(short *)(iVar5 + 0x18)))
                        goto LAB_0813bc20;
                        iVar5 = sub_080F2F64(0x8000);
                        *(undefined2 *)(iVar5 + 0x18) = 0;
                        sub_080C08BC(0,1);
                        sub_080C08E8(0,0x8000);
                      }
                      else {
                        if (sVar2 == 0x17) {
                          sub_0813B400();
                          sub_0813BE70();
                          DAT_0300684c = DAT_0300684c | 0x40;
                          DAT_0203db3e = 0;
                          DAT_0203db38 = 0;
                          DAT_0203db3a = 0;
                          DAT_0203db4a = 0;
                          Font_ResetGlyphSpriteCache(0x180);
                          goto LAB_0813bc20;
                        }
                        if (sVar2 == 0x18) {
                          iVar5 = sub_0812F188(DAT_030065e0 - 0x9d & 0xffff);
                          sub_080C30AC(-iVar5);
                          uVar12 = sub_080C1D9C();
                          if ((uVar12 & 0xf0) != 0x80) {
                            sub_080C2364(0xcf);
                          }
                          uVar12 = (uint)DAT_03006898;
                          sub_0813B438(uVar12);
                          if (uVar12 == 0) {
                            sub_080C2364(0xe2);
                          }
                          else {
                            sub_080C2364(0xe3);
                          }
                          goto LAB_0813bc20;
                        }
                        if (sVar2 != 0x19) {
                          if (sVar2 == 0x1a) {
                            iVar5 = sub_080F2F64(0x8000);
                            if (DAT_0203db2c < (uint)(int)*(short *)(iVar5 + 0x18)) {
                              iVar5 = sub_080F2F64(0x8000);
                              *(short *)(iVar5 + 0x18) =
                                   *(short *)(iVar5 + 0x18) - (short)DAT_0203db2c;
                            }
                            else {
                              iVar5 = sub_080F2F64(0x8000);
                              *(undefined2 *)(iVar5 + 0x18) = 0;
                              sub_080C08E8(0,0x8000);
                            }
                            goto LAB_0813b5a6;
                          }
                          if (sVar2 == 0x1b) {
                            DAT_0203db7c = DAT_0203db80;
                            goto LAB_0813bc20;
                          }
                          if (sVar2 == 0x1c) {
                            sub_080D3AA0(1);
                            goto LAB_0813bc20;
                          }
                          if (sVar2 == 0x1d) {
                            uVar7 = 0;
                          }
                          else {
                            if (sVar2 != 0x1e) {
                              if (sVar2 == 0x1f) {
                                DAT_0203bb76 = 0;
                              }
                              else if (sVar2 == 0x20) {
                                DAT_0203bb76 = 1;
                              }
                              else if (sVar2 == 0x21) {
                                DAT_0203bb76 = 2;
                              }
                              else if (sVar2 == 0x22) {
                                _DAT_0203bb74 = 0;
                              }
                              else if (sVar2 == 0x23) {
                                _DAT_0203bb74 = 1;
                              }
                              else if (sVar2 == 0x24) {
                                _DAT_0203bb74 = 2;
                              }
                              else if (sVar2 == 0x25) {
                                DAT_0203bb78 = 0;
                                DAT_0203bb7a = 0xff;
                                if (_DAT_0203bb74 == 1) {
                                  sub_080C5B3C();
                                }
                              }
                              else if (sVar2 == 0x26) {
                                DAT_0203bb78 = DAT_0203bb78 + 1;
                                DAT_0203db2c = (uint)DAT_0203bb78;
                              }
                              else if (sVar2 == 0x27) {
                                if (_DAT_0203bb74 == 1) {
                                  sub_080C5BCC();
                                }
                              }
                              else if (sVar2 == 0x28) {
                                uVar12 = sub_080C0F8C(0);
                                if (6 < (uVar12 & 0xffff)) {
                                  uVar12 = (uVar12 & 0xffff) - 1 & 0xffff;
                                  sub_080C0FA4(0,uVar12);
                                  uVar7 = sub_080C1098(uVar12);
                                  sub_080C0F70(0,uVar7);
                                  uVar12 = sub_080C2244();
                                  uVar8 = sub_080C2244();
                                  uVar10 = sub_080C2244();
                                  iVar5 = (uVar12 & 3) + (uVar8 & 1) + (uVar10 & 1);
                                  uVar4 = 0;
                                  do {
                                    if (iVar5 == 0) {
                                      iVar5 = sub_080C0F64();
                                      if (6 < iVar5) {
                                        sub_08136204(0,0,iVar5 + -1);
                                        goto LAB_0813bc16;
                                      }
                                      iVar5 = 1;
                                    }
                                    else if (iVar5 == 1) {
                                      iVar5 = sub_080C0F64();
                                      if (5 < iVar5) {
                                        sub_08136204(0,1,iVar5 + -1);
                                        goto LAB_0813bc16;
                                      }
                                      iVar5 = 2;
                                    }
                                    else if (iVar5 == 2) {
                                      iVar5 = sub_080C0F64();
                                      if (4 < iVar5) {
                                        sub_08136204(0,2,iVar5 + -1);
                                        goto LAB_0813bc16;
                                      }
                                      iVar5 = 3;
                                    }
                                    else if (iVar5 == 3) {
                                      iVar5 = sub_080C0F64();
                                      if (6 < iVar5) {
                                        sub_08136204(0,3,iVar5 + -1);
                                        goto LAB_0813bc16;
                                      }
                                      iVar5 = 4;
                                    }
                                    else if (iVar5 == 4) {
                                      iVar5 = sub_080C0F64();
                                      if (6 < iVar5) {
                                        sub_08136204(0,4,iVar5 + -1);
LAB_0813bc16:
                                        DAT_030046d8 = DAT_030046da;
                                        sub_080CDC34();
                                        break;
                                      }
                                      iVar5 = 5;
                                    }
                                    else {
                                      iVar5 = sub_080C0F64();
                                      if (3 < iVar5) {
                                        sub_08136204(0,5,iVar5 + -1);
                                        goto LAB_0813bc16;
                                      }
                                      iVar5 = 0;
                                    }
                                    uVar4 = uVar4 + 1;
                                  } while (uVar4 < 6);
                                }
                              }
                              goto LAB_0813bc20;
                            }
                            uVar7 = 1;
                          }
                          sub_080D4560(uVar7);
                          DAT_0203db5a = 0x52;
                          goto LAB_0813ba10;
                        }
                      }
                      uVar12 = sub_08138CE8();
                      if ((uVar12 & 0xffff) != 0) {
                        *(undefined2 *)(arg0 + 0x1c) = 1;
                      }
                      goto LAB_0813bc20;
                    }
                    sub_08132350(0x16);
                    DAT_03006964 = sub_080B8AE0(0x1f,1);
                    DAT_0203db5a = 0x4c;
                  }
LAB_0813ba10:
                  DAT_0203db6e = 1;
                  goto LAB_0813bc20;
                }
                bVar3 = 2;
              }
              DAT_0300684c = DAT_0300684c | bVar3;
              goto LAB_0813bc20;
            }
            if ((DAT_0300684c & 0x10) == 0) {
              bVar3 = 0x10;
              goto LAB_0813b75e;
            }
            bVar3 = 0xef;
          }
          DAT_0300684c = bVar3 & DAT_0300684c;
          goto LAB_0813bc20;
        }
        uVar7 = sub_0813E60C((uint)DAT_0203db7c,0);
        DAT_030046d8 = DAT_030046d8 + ((ushort)uVar7 & 0xff) * -2;
      }
      if ((DAT_030046d8 + -1) * 0x10000 < 1) {
        DAT_030046d8 = 1;
      }
      goto LAB_0813bc20;
    }
    sub_080C08BC(0,1);
    sub_080C0A7C(0);
  }
LAB_0813b5a6:
  sub_080C84A0();
LAB_0813bc20:
                    /* WARNING: Could not recover jumptable at 0x0813bc24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOpAlt_445 @ 0x0813BC2C

void ScriptOpAlt_445(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_446 @ 0x0813BC3C

void ScriptOp_446(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  ushort *puVar6;
  uint uVar7;
  uint arg1;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar3 = DAT_0203db40 + 1;
  puVar6 = (ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  cVar1 = (char)*puVar6;
  uVar2 = *(ushort *)((uint)(*puVar6 >> 8) * 2 + 0x8790dfc);
  arg1 = (uint)uVar2;
  DAT_0203db40 = sVar3;
  if (cVar1 == '\0') {
    sub_080C08E8(0,arg1);
    if ((uVar2 & 0x8000) != 0) {
      iVar4 = sub_080F2F64(0x8000);
      *(undefined2 *)(iVar4 + 0x18) = 0;
    }
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x03') {
        uVar7 = 0x10;
        do {
          iVar4 = sub_080C0A00(uVar7);
          if (((iVar4 != 0) &&
              (uVar5 = sub_080C07E0(uVar7), (int)(short)uVar5 == (uint)DAT_0203db7c)) &&
             (sub_080C08E8(uVar7,arg1), (uVar2 & 0x8000) != 0)) {
            sub_080C84A0();
          }
          uVar7 = uVar7 + 1 & 0xffff;
        } while (uVar7 < 0x18);
        sub_080C84A0();
      }
      goto LAB_0813bd3c;
    }
    uVar7 = 0x10;
    while ((uVar7 < 0x18 &&
           ((iVar4 = sub_080C0A00(uVar7), iVar4 == 0 ||
            (uVar5 = sub_080C07E0(uVar7), (int)(short)uVar5 != (uint)DAT_0203db7c))))) {
      uVar7 = uVar7 + 1 & 0xffff;
    }
    if ((uVar2 & 0x8000) != 0) {
      sub_080EF20C();
      goto LAB_0813bd3c;
    }
    sub_080C08E8(uVar7,arg1);
    iVar4 = sub_080F2F64(uVar7 + 0x8000 & 0xffff);
    *(ushort *)(iVar4 + 0x18) = uVar2 & 0x8000;
  }
  sub_080C84A0();
LAB_0813bd3c:
                    /* WARNING: Could not recover jumptable at 0x0813bd40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOpAlt_446 @ 0x0813BD48

void ScriptOpAlt_446(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// sub_0813BD58 @ 0x0813BD58

uint sub_0813BD58(void)

{
  uint uVar1;
  uint uVar2;
  byte local_10;
  undefined1 auStack_f [3];
  
  sub_0815B9B8((uint)DAT_0203db7c,&local_10,auStack_f);
  uVar2 = 0;
  while (uVar1 = sub_080C2244(),
        (uint)*(byte *)((local_10 & 0x3f) * 4 + uVar2 + 0x8790e1c) < (uVar1 & 0xff)) {
    uVar2 = uVar2 + 1 & 0xff;
  }
  return uVar2;
}


// sub_0813BDA4 @ 0x0813BDA4

void sub_0813BDA4(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080C2244();
  DAT_03006690 = (ushort)uVar1 & 0xf;
  uVar1 = sub_080C2244();
  DAT_03006690 = ((ushort)uVar1 & 0xf) + DAT_03006690 + 8;
  return;
}


// sub_0813BDCC @ 0x0813BDCC

uint sub_0813BDCC(void)

{
  uint uVar1;
  int arg0;
  uint uVar2;
  
  uVar1 = sub_0813E60C((uint)DAT_0203db7c,0x1a);
  uVar2 = (uVar1 & 0xf0) >> 4;
  uVar1 = sub_0813E60C((uint)DAT_0203db7c,0);
  arg0 = (uVar1 & 0xff) * 8;
  if (uVar2 < 8) {
    uVar2 = uVar2 * arg0;
  }
  else {
    uVar2 = sub_08137B78(arg0,uVar2);
    uVar2 = uVar2 & 0xffff;
  }
  return uVar2;
}


// sub_0813BE08 @ 0x0813BE08

uint sub_0813BE08(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = sub_080C3168();
  bVar2 = DAT_0203db2c <= uVar1;
  if (bVar2) {
    sub_080C3114(-DAT_0203db2c);
  }
  return (uint)!bVar2;
}


// sub_0813BE2C @ 0x0813BE2C

uint sub_0813BE2C(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = sub_080C3100();
  bVar2 = DAT_0203db2c <= uVar1;
  if (bVar2) {
    sub_080C30AC(-DAT_0203db2c);
  }
  return (uint)!bVar2;
}


// sub_0813BE50 @ 0x0813BE50

void sub_0813BE50(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080EF90C();
  iVar1 = iVar1 + (arg0 & 0xffff);
  if (0x1f < iVar1) {
    iVar1 = 0x1f;
  }
  sub_080EF930(iVar1);
  return;
}


// sub_0813BE70 @ 0x0813BE70

void sub_0813BE70(void)

{
  sub_0813BE50((uint)*(byte *)((DAT_0203db50 - 0x120 & 0x3fff) * 4 + 0x81a6ed4));
  return;
}


// sub_0813BE98 @ 0x0813BE98

void sub_0813BE98(void)

{
  uint uVar1;
  
  uVar1 = __divsi3(0x28,(byte)DAT_03006690 + 2);
  sub_0813BE50(uVar1 & 0xffff);
  return;
}


// sub_0813BEB8 @ 0x0813BEB8

void sub_0813BEB8(void)

{
  uint uVar1;
  
  uVar1 = sub_080C2244();
  sub_0813BE50((uVar1 & 3) + 1);
  return;
}


// sub_0813BECC @ 0x0813BECC

void sub_0813BECC(undefined4 arg0)

{
  ushort uVar1;
  uint uVar2;
  
  DAT_03006844 = (undefined2)arg0;
  sub_0812F198();
  uVar2 = 0;
  do {
    *(undefined2 *)(uVar2 * 2 + 0x203db88) = 0xffff;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0x14);
  uVar1 = 0x120;
  uVar2 = 0;
  do {
    *(ushort *)(uVar2 * 2 + 0x203db88) = uVar1;
    uVar1 = uVar1 + 1;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar1 < 300);
  DAT_0203db5a = 0x48;
  DAT_03006940 = 0;
  DAT_0300696c = 0;
  sub_08133F14(0);
  sub_080AD0FC(0x878fe64,0xffff);
  return;
}


// sub_0813BF58 @ 0x0813BF58

uint sub_0813BF58(void)

{
  return (uint)((DAT_0300684c & 1) != 0);
}


// sub_0813BF78 @ 0x0813BF78

uint sub_0813BF78(void)

{
  return (uint)((DAT_0300684c & 2) != 0);
}


// ScriptOp_447 @ 0x0813BF98

void ScriptOp_447(void)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  ushort uVar10;
  int iVar11;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar10 = DAT_0203db40 + 1;
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar2 = DAT_0203db40 + 2;
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar3 = CONCAT22(*(undefined2 *)((uint)uVar2 * 2 + DAT_03006950),
                   *(undefined2 *)((uint)uVar10 * 2 + DAT_03006950));
  if (sVar1 == 0) {
    if (DAT_0203db7c == DAT_0203db7e) goto LAB_0813c4de;
LAB_0813c4c0:
    DAT_030068e4 = uVar3;
  }
  else {
    if (sVar1 == 1) {
      uVar4 = sub_0815B9DC((uint)DAT_0203db7c);
      if ((uVar4 & 0xffff) < 0x1b) {
        uVar4 = sub_0813E60C((uint)DAT_0203db7c,0xb);
        if ((uVar4 & 0xff) < 0x70) {
          uVar4 = sub_080C0794(0);
          if (((uVar4 & 0xffffff) >> 8 & 0xff) < 0x90) goto LAB_0813c4de;
        }
        else if (((uVar4 & 0xff) < 0x90) ||
                (uVar4 = sub_080C0794(0), 0x6f < ((uVar4 & 0xffffff) >> 8 & 0xff)))
        goto LAB_0813c4de;
      }
    }
    else {
      if (sVar1 == 2) {
        iVar5 = sub_080C104C();
        if (DAT_0203db86 != 0) goto LAB_0813c4de;
        iVar11 = 0;
        if (0 < iVar5) {
          do {
            iVar6 = sub_080C09B0(iVar11 + 4);
            if (iVar6 == 0) goto LAB_0813c4de;
            iVar11 = iVar11 + 1;
          } while (iVar11 < iVar5);
        }
        goto LAB_0813c4c0;
      }
      if (sVar1 == 3) {
        if ((0x8f < DAT_0300685c) ||
           (uVar4 = sub_0813E804((uint)DAT_0203db7c), (uVar4 & 0xffff) == 0)) goto LAB_0813c4de;
      }
      else {
        if (sVar1 == 4) {
          iVar5 = 0x10;
          do {
            iVar11 = sub_080C09B0(iVar5);
            if ((iVar11 != 0) &&
               (uVar7 = sub_080C07E0(iVar5), (int)(short)uVar7 == (uint)DAT_0203db7c)) {
              uVar4 = iVar5 - 0x8000U & 0xffff;
              iVar11 = sub_080F2F64(uVar4);
              uVar2 = *(ushort *)(iVar11 + 0x1a);
              iVar11 = sub_080F2F64(uVar4);
              if ((int)*(short *)(iVar11 + 0x18) <=
                  (int)((int)((uint)uVar2 << 0x10) >> 0x12 & 0xffffU)) goto LAB_0813c4c0;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < 0x18);
          goto LAB_0813c4de;
        }
        if (sVar1 == 5) {
          iVar5 = 0x10;
          do {
            iVar11 = sub_080C09B0(iVar5);
            if (((iVar11 != 0) &&
                (uVar7 = sub_080C07E0(iVar5), (int)(short)uVar7 == (uint)DAT_0203db7c)) &&
               (uVar4 = sub_080C0818(iVar5), (uVar4 & 0x200) != 0)) goto LAB_0813c4cc;
            iVar5 = iVar5 + 1;
          } while (iVar5 < 0x18);
          goto LAB_0813c4de;
        }
        if (sVar1 == 6) {
          iVar5 = sub_080C09B0(1);
          if (iVar5 != 0) {
            uVar4 = sub_080C0818(1);
            uVar4 = uVar4 & 0xa000;
joined_r0x0813c1b8:
            if (uVar4 != 0) goto LAB_0813c4de;
            goto LAB_0813c4c0;
          }
          iVar5 = sub_080C09B0(2);
          if (iVar5 == 0) goto LAB_0813c4c0;
          uVar4 = sub_080C0818(2);
          uVar4 = uVar4 & 0xa000;
        }
        else {
          if (sVar1 != 7) {
            if (sVar1 == 8) {
              uVar4 = sub_0813BF78();
              uVar4 = uVar4 & 0xffff;
              goto joined_r0x0813c1b8;
            }
            if (sVar1 == 9) {
              iVar5 = sub_080C09B0(1);
              if (iVar5 == 0) {
                iVar5 = sub_080C09B0(2);
                if (iVar5 == 0) goto LAB_0813c4de;
                uVar7 = 2;
              }
              else {
                uVar7 = 1;
              }
              uVar4 = sub_080C0818(uVar7);
              if ((uVar4 & 0x800) == 0) {
                uVar4 = sub_080C0E44(uVar7,2);
                uVar4 = uVar4 & 0xff;
              }
              else {
                uVar4 = 1;
              }
              uVar8 = sub_080C2244();
              uVar9 = sub_0813E60C((uint)DAT_0203db7c,7);
              if ((uVar8 & 0xf) + (uVar9 & 0xff) < uVar4) goto LAB_0813c4de;
              goto LAB_0813c4cc;
            }
            if (sVar1 == 10) {
              DAT_030068e0 = sub_0812A640();
              DAT_0203db5a = 0x4e;
              DAT_0203dac8 = uVar3;
LAB_0813c32e:
              DAT_0203db6e = 1;
              goto LAB_0813c4de;
            }
            if (sVar1 == 0xb) {
              iVar5 = sub_080C09B0(1);
              if (iVar5 == 0) {
                iVar5 = sub_080C09B0(2);
                if (iVar5 == 0) goto LAB_0813c4c0;
                uVar7 = 2;
              }
              else {
                uVar7 = 1;
              }
              uVar4 = sub_080C0818(uVar7);
              if ((uVar4 & 0xc000) == 0) {
                uVar4 = 0x10;
LAB_0813c288:
                iVar5 = sub_080C09B0(uVar4);
                if ((iVar5 == 0) ||
                   (uVar8 = (uint)DAT_0203db7c, uVar7 = sub_080C07E0(uVar4),
                   uVar8 != (int)(short)uVar7)) goto LAB_0813c2d0;
                uVar9 = uVar4 + 0x8000 & 0xffff;
                iVar5 = sub_080F2F64(uVar9);
                uVar8 = (uint)*(short *)(iVar5 + 0x1a);
                if ((int)uVar8 < 0) {
                  uVar8 = uVar8 + 3;
                }
                iVar5 = sub_080F2F64(uVar9);
                if ((int)((uVar8 & 0x3ffff) >> 2) < (int)*(short *)(iVar5 + 0x18))
                goto LAB_0813c2d0;
                uVar4 = sub_080C2244();
                uVar4 = uVar4 & 3;
LAB_0813c316:
                if (uVar4 == 0) goto LAB_0813c4de;
              }
            }
            else if (sVar1 == 0xc) {
              uVar4 = 0xb;
              do {
                uVar8 = sub_0813756C(uVar4);
                if ((uVar8 & 0xff) != 0) {
                  iVar5 = sub_0813BD58();
                  uVar4 = iVar5 << 0x10;
                  goto LAB_0813c316;
                }
                uVar8 = uVar4 * 0x10000 - 0x10000;
                uVar4 = uVar8 >> 0x10;
              } while (-1 < (int)uVar8);
            }
            else {
              if (sVar1 == 0xd) {
                DAT_0203dac8 = uVar3;
                sub_0813BECC(1);
                goto LAB_0813c32e;
              }
              if (sVar1 == 0xe) {
                uVar4 = sub_0813BD58();
                if ((uVar4 & 0xffff) == 1) {
                  sub_0813BDA4();
                  uVar4 = sub_0813BDCC();
                  uVar2 = DAT_03006690;
                  uVar4 = __divsi3((uVar4 & 0xffff) << 4,(uint)DAT_03006690);
                  uVar4 = (uVar4 & 0xffff) + (uint)(uVar2 >> 2);
joined_r0x0813c3da:
                  DAT_0203db2c = uVar4 & 0xffff;
                  if ((DAT_0300684c & 1) != 0) {
                    DAT_0203db2c = (uVar4 & 0x7fff) << 1;
                  }
                  goto LAB_0813c4de;
                }
              }
              else {
                if (sVar1 == 0xf) {
                  uVar4 = sub_0813BE2C();
joined_r0x0813c398:
                  if ((uVar4 & 0xffff) == 0) {
                    DAT_0300684c = DAT_0300684c | 0x40;
                    sub_0813BE98();
                    goto LAB_0813c4de;
                  }
                  goto LAB_0813c4cc;
                }
                if (sVar1 == 0x10) {
                  uVar4 = sub_0813BD58();
                  if ((uVar4 & 0xffff) == 2) {
                    sub_0813BDA4();
                    uVar4 = sub_08137BB8();
                    uVar2 = DAT_03006690;
                    uVar4 = __divsi3((uVar4 & 0xffff) << 4,(uint)DAT_03006690);
                    uVar4 = (uVar4 & 0xffff) + (uint)(uVar2 >> 2);
                    goto joined_r0x0813c3da;
                  }
                }
                else {
                  if (sVar1 == 0x11) {
                    uVar4 = sub_0813BE08();
                    goto joined_r0x0813c398;
                  }
                  if (sVar1 == 0x12) {
                    DAT_0203db50 = 0xe5;
                    uVar4 = sub_080C32D4(0xe5);
                    if ((uVar4 & 0xff) != 0) {
                      sub_080C33AC((uint)DAT_0203db50);
                      sub_0813BEB8();
                      goto LAB_0813c4de;
                    }
                  }
                  else {
                    if (sVar1 == 0x13) {
                      uVar4 = sub_0813E60C((uint)DAT_0203db7c,0x1b);
                      uVar8 = ((uVar4 & 0xff) >> 1) + 1;
                      uVar4 = sub_080C3168();
                      if (uVar8 <= uVar4) {
                        sub_080C3114(-uVar8);
                        goto LAB_0813c4de;
                      }
                      goto LAB_0813c4cc;
                    }
                    if (sVar1 != 0x14) {
                      if (sVar1 == 0x15) {
                        DAT_03006840 = uVar3;
                        iVar5 = sub_080C2340(0xe5);
                        if ((iVar5 == 0) || (uVar4 = sub_0812A668(0), (uVar4 & 0xffff) == 0)) {
                          sub_0813B328(0x2e);
                        }
                        else {
                          sub_0813B328(0x2d);
                        }
                      }
                      goto LAB_0813c4de;
                    }
                    uVar4 = sub_080C00DC(0,1);
                    if (((uVar4 & 0xffff) != 0xff) &&
                       (uVar4 = sub_080C00DC(0,6), (uVar4 & 0xffff) != 0xff)) goto LAB_0813c4de;
                  }
                }
              }
            }
            goto LAB_0813c4c0;
          }
          uVar4 = sub_0813BF58();
          uVar4 = uVar4 & 0xffff;
        }
        if (uVar4 != 0) goto LAB_0813c4de;
      }
    }
LAB_0813c4cc:
    DAT_030068e4 = uVar3;
  }
LAB_0813c4de:
                    /* WARNING: Could not recover jumptable at 0x0813c4e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
LAB_0813c2d0:
  uVar4 = uVar4 + 1 & 0xffff;
  if (0x17 < uVar4) goto LAB_0813c4c0;
  goto LAB_0813c288;
}


// ScriptOpAlt_447 @ 0x0813C4E8

void ScriptOpAlt_447(void)

{
  DAT_0203db40 = DAT_0203db40 + 3;
  return;
}


// sub_0813C4F8 @ 0x0813C4F8

void sub_0813C4F8(void)

{
  return;
}


// sub_0813C4FC @ 0x0813C4FC

undefined4 sub_0813C4FC(undefined4 arg0)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((short)arg0 == 1) {
    uVar1 = sub_080C2244();
    uVar1 = (uVar1 & 0x1f) + 0x3b;
  }
  else if ((short)arg0 == 2) {
    uVar1 = sub_080C2244();
    uVar1 = (uVar1 & 0x1f) + 0x54;
  }
  else {
    uVar1 = sub_080C2244();
    uVar1 = (uVar1 & 0xf) + 0x77;
  }
  uVar2 = sub_0813E854((uint)DAT_0203db7c);
                    /* WARNING: Could not recover jumptable at 0x0813c552. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)((uVar2 & 0xffff) < uVar1);
  return uVar3;
}


// ScriptOp_448 @ 0x0813C554

void ScriptOp_448(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar5 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar3 = *(undefined2 *)((uint)uVar5 * 2 + DAT_03006950);
  uVar5 = uVar1 >> 8;
  uVar11 = uVar1 & 0xff;
  if (uVar5 == 0) {
    if (DAT_0300685c == uVar11) goto LAB_0813c7da;
LAB_0813c7d6:
    puVar10 = (undefined4 *)0x30068e4;
  }
  else {
    if (uVar5 == 1) {
      sub_080C0E44(0,1);
      if (uVar11 == 1) {
        iVar6 = sub_0813E60C((uint)DAT_0203db7c,6);
        uVar11 = sub_080C2244();
        uVar11 = (iVar6 + (uVar11 & 3)) - 1;
      }
      else if (uVar11 == 2) {
        uVar11 = sub_080C2244();
        iVar6 = sub_0813E60C((uint)DAT_0203db7c,6);
        uVar7 = sub_080C2244();
        uVar11 = (uVar11 & 7) + (iVar6 - (uVar7 & 3));
      }
      else {
        uVar11 = sub_080C2244();
        iVar6 = sub_0813E60C((uint)DAT_0203db7c,6);
        uVar11 = (uVar11 & 7) + iVar6;
      }
      iVar6 = sub_080C0E44(0,1);
      if ((int)(uVar11 & 0xff) < iVar6) goto LAB_0813c7da;
      goto LAB_0813c7d6;
    }
    if (uVar5 == 2) {
      uVar7 = sub_080C0E44(0,2);
      uVar8 = sub_0813E60C((uint)DAT_0203db7c,7);
      uVar8 = uVar8 & 0xffff;
      if (uVar11 == 1) {
        uVar11 = sub_080C2244();
        uVar8 = (uVar11 & 3) + uVar8;
        uVar11 = uVar8 & 0xffff;
        if (2 < uVar11) {
          uVar11 = uVar8 * 0x10000 - 0x20000 >> 0x10;
        }
      }
      else if (uVar11 == 2) {
        uVar11 = sub_080C2244();
        uVar9 = sub_080C2244();
        uVar11 = (uVar11 & 7) + (uVar8 - (uVar9 & 7));
        uVar8 = uVar11 & 0xffff;
        if ((uVar11 & 0x8000) != 0) goto LAB_0813c7da;
        uVar11 = 0;
        if (uVar8 != 0) {
          uVar11 = uVar8 - 1 & 0xffff;
        }
      }
      else {
        if (uVar11 != 3) goto LAB_0813c7da;
        uVar11 = sub_080C2244();
        uVar11 = (uVar11 & 7) + uVar8 & 0xffff;
      }
      if (uVar11 < (uVar7 & 0xffff)) goto LAB_0813c7da;
      goto LAB_0813c7d6;
    }
    if (uVar5 == 3) {
      uVar11 = sub_0813C4FC(uVar11);
      if ((uVar11 & 0xffff) == 0) goto LAB_0813c7da;
      goto LAB_0813c7d6;
    }
    if (uVar5 == 4) {
      if (DAT_03006690 < 0xc) {
        if ((uVar1 & 0xff) == 0) {
          uVar11 = sub_0813BDCC();
        }
        else {
          uVar11 = sub_08137BB8();
        }
        uVar11 = uVar11 & 0xffff;
        if (DAT_03006690 != 0) {
          uVar11 = __udivsi3(uVar11,(uint)DAT_03006690);
          uVar11 = uVar11 & 0xffff;
        }
        if (2 < uVar11) goto LAB_0813c7da;
      }
      goto LAB_0813c7d6;
    }
    if (uVar5 == 5) {
      if (uVar11 == 1) {
        bVar4 = DAT_0300684c & 8;
      }
      else {
        if (uVar11 != 2) goto LAB_0813c7da;
        bVar4 = DAT_0300684c & 0x10;
      }
      if (bVar4 == 0) goto LAB_0813c7da;
      goto LAB_0813c7d6;
    }
    if (uVar5 != 6) {
      if (uVar5 != 7) goto LAB_0813c7da;
      DAT_0203db50 = (undefined2)(uVar11 | 0x100);
      iVar6 = sub_080C5C14(uVar11 | 0x100);
      if (iVar6 != 0) goto LAB_0813c7da;
      goto LAB_0813c7d6;
    }
    DAT_0203db50 = (undefined2)uVar11;
    uVar7 = sub_080C32FC(uVar11);
    if ((uVar7 & 0xff) == 0) {
      sub_080C3328(uVar11);
      DAT_030068e4 = 0x80a0bc6;
      puVar10 = (undefined4 *)0x3006840;
    }
    else {
      DAT_030068e4 = 0x80a0c0a;
      puVar10 = (undefined4 *)0x3006840;
    }
  }
  *puVar10 = CONCAT22(uVar3,uVar2);
LAB_0813c7da:
                    /* WARNING: Could not recover jumptable at 0x0813c7e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_44A @ 0x0813C7EC

void ScriptOp_44A(void)

{
  uint arg1;
  
  arg1 = (uint)*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  if (arg1 < 0xf0) {
    DAT_0203db40 = DAT_0203db40 + 1;
    sub_0815BAC8((uint)DAT_0203db7c,arg1);
  }
  else {
    DAT_0203db40 = DAT_0203db40 + 1;
    sub_0815BB18((uint)DAT_0203db7c,0x100 - arg1 & 0xffff);
  }
  return;
}


// ScriptOpAlt_44A @ 0x0813C838

void ScriptOpAlt_44A(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_44B @ 0x0813C848

void ScriptOp_44B(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  dword arg1;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 1;
  iVar2 = sub_080C2340(0xe0);
  if (iVar2 == 0) {
    if (((sVar1 - 1U & 0x8000) == 0) &&
       (((sVar1 - 2U & 0x8000) == 0 || (uVar3 = sub_080C0794(0), (uVar3 & 0x8000) == 0)))) {
      uVar3 = sub_080C0794(0);
      if ((uVar3 & 0xff00) == 0xff00) goto LAB_0813c8da;
      arg1 = 0x100;
    }
    else {
      uVar3 = sub_080C0794(0);
      if ((uVar3 & 0xff00) == 0) goto LAB_0813c8da;
      arg1 = 0xffffff00;
    }
    sub_080C06EC(0,arg1);
  }
LAB_0813c8da:
                    /* WARNING: Could not recover jumptable at 0x0813c8de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOpAlt_44B @ 0x0813C8E0

void ScriptOpAlt_44B(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// sub_0813C8F0 @ 0x0813C8F0

void sub_0813C8F0(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOpAlt_44C @ 0x0813C900

void ScriptOpAlt_44C(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// sub_0813C910 @ 0x0813C910

void sub_0813C910(void)

{
  DAT_03006858 = 0;
  return;
}


// sub_0813C91C @ 0x0813C91C

void sub_0813C91C(void)

{
  int iVar1;
  
  iVar1 = sub_080AB994(DAT_03006968);
  if (iVar1 != 0) {
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 0);
  return;
}


// sub_0813C954 @ 0x0813C954

void sub_0813C954(void)

{
  int iVar1;
  
  iVar1 = sub_080AD20C(DAT_030068b0);
  if (iVar1 == 0) {
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 != 0);
  return;
}


// sub_0813C988 @ 0x0813C988

void sub_0813C988(void)

{
  DAT_030068e4 = DAT_0203dac8;
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813C9AC @ 0x0813C9AC

void sub_0813C9AC(void)

{
  DAT_0203db56 = 0;
  DAT_0203db52 = 0;
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813C9D0 @ 0x0813C9D0

void sub_0813C9D0(void)

{
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813C9E4 @ 0x0813C9E4

void sub_0813C9E4(void)

{
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813C9F8 @ 0x0813C9F8

void sub_0813C9F8(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_080ABF04(DAT_030068e0);
  if (iVar1 == 0) {
    DAT_03006858 = 1;
    return;
  }
  DAT_0203db5a = 0;
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  uVar2 = sub_0813E408();
  DAT_0203db48 = (undefined2)uVar2;
  if (DAT_03006670 == 0) {
    if (DAT_030031cc == 0) {
      DAT_03006858 = 0;
      return;
    }
  }
  else if (DAT_030031cc != 0) {
    DAT_03006858 = 0;
    return;
  }
  DAT_030068e4 = DAT_0203dac8;
  DAT_03006858 = 0;
  return;
}


// sub_0813CA98 @ 0x0813CA98

void sub_0813CA98(void)

{
  DAT_0203db5c = DAT_0203db5c + -1;
  if (DAT_0203db5c == 0) {
    DAT_0203db5c = (short)DAT_030068c8;
    DAT_0203db5a = 0x39;
  }
  DAT_03006858 = 1;
  return;
}


// sub_0813CAD0 @ 0x0813CAD0

void sub_0813CAD0(void)

{
  int iVar1;
  
  DAT_0203db5c = DAT_0203db5c + -1;
  sub_080C30AC(0xfffffc18);
  if (DAT_0203db5c == 0) {
    iVar1 = sub_080C3100();
    if (iVar1 == 0) {
      DAT_0203db5a = 0x3a;
      DAT_0203db5c = 0x3c;
    }
    else {
      DAT_0203db5c = 1;
    }
  }
  DAT_03006858 = 1;
  return;
}


// sub_0813CB28 @ 0x0813CB28

void sub_0813CB28(void)

{
  DAT_0203db5c = DAT_0203db5c + -1;
  if (DAT_0203db5c == 0) {
    sub_080C762C();
    DAT_0203db5a = 0xf;
    DAT_0203db5c = 0x3c;
  }
  DAT_03006858 = 1;
  return;
}


// sub_0813CB60 @ 0x0813CB60

void sub_0813CB60(void)

{
  DAT_0203db5c = DAT_0203db5c + -1;
  if (DAT_0203db5c == 0) {
    DAT_0203db5a = 0x11;
    sub_080C30AC((int)DAT_0203db62);
    DAT_0203db5c = 0x1e;
  }
  DAT_03006858 = 1;
  return;
}


// sub_0813CBA0 @ 0x0813CBA0

void sub_0813CBA0(void)

{
  DAT_0203db5c = DAT_0203db5c + -1;
  if (DAT_0203db5c == 0) {
    sub_080C762C();
    DAT_0203db5a = 0xf;
    DAT_0203db5c = 0x3c;
  }
  DAT_03006858 = 1;
  return;
}


// sub_0813CBD8 @ 0x0813CBD8

void sub_0813CBD8(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)DAT_0203db5c;
  DAT_0203db5c = (short)(uVar1 - 1);
  iVar2 = (uVar1 - 1) * 0x10000;
  if (iVar2 >> 0x10 == 0) {
    DAT_0203db5a = (undefined2)((uint)iVar2 >> 0x10);
  }
  DAT_03006858 = 1;
  return;
}


// sub_0813CC08 @ 0x0813CC08

void sub_0813CC08(void)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_0812685C();
  if ((uVar1 & 0xffff) == 4) {
    DAT_0203db5a = 0;
    DAT_03006858 = 0;
  }
  else {
    if ((uVar1 & 0xffff) == 5) {
      sub_08132890();
    }
    DAT_03006858 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0813cc3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0813CC44 @ 0x0813CC44

void sub_0813CC44(void)

{
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813CC58 @ 0x0813CC58

void sub_0813CC58(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  if (DAT_03006844 == 4) {
    uVar1 = sub_080C3100();
    uVar2 = sub_0812F188(DAT_030065e0 - 0x9d & 0xffff);
    if (uVar1 < uVar2) {
      DAT_030068e4 = DAT_0203dac8;
    }
  }
  else {
    if (DAT_030069cc == 0) {
      iVar3 = (int)DAT_03006940 + (int)DAT_0300696c;
    }
    else {
      iVar3 = (int)DAT_03006940 + (int)DAT_0300696c + 10;
    }
    DAT_030068e4 = *(undefined4 *)(iVar3 * 4 + 0x203dac8);
  }
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813CD38 @ 0x0813CD38

void sub_0813CD38(void)

{
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  if (DAT_03006844 == 4) {
    DAT_030068e4 = DAT_0203dacc;
  }
  else if (DAT_030069cc != 0) {
    DAT_030068e4 = DAT_0203db00;
    DAT_030069cc = 0;
  }
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813CDBC @ 0x0813CDBC

void sub_0813CDBC(void)

{
  uint uVar1;
  
  uVar1 = sub_0813DA6C();
  DAT_03006858 = (ushort)((uVar1 & 0xffff) == 0);
  return;
}


// sub_0813CDE4 @ 0x0813CDE4

void sub_0813CDE4(void)

{
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813CDF8 @ 0x0813CDF8

void sub_0813CDF8(void)

{
  DAT_0203db5a = 0;
  if (DAT_0203dad8 != 0) {
    DAT_030068e4 = DAT_0203dad8;
    DAT_03006930 = 0;
    DAT_03006928 = 0;
    DAT_03006920 = 0;
    DAT_03006660 = 0;
    DAT_03006650 = 0;
    DAT_03006640 = 0;
    DAT_03006630 = 0;
    DAT_03006620 = 0;
    DAT_0300699c = 0;
    DAT_0300669c = 0;
    sub_080D34F0(DAT_030068a4);
  }
  DAT_03006858 = 0;
  return;
}


// sub_0813CE64 @ 0x0813CE64

void sub_0813CE64(void)

{
  int iVar1;
  char cVar2;
  
  DAT_0203db5a = 0;
  iVar1 = sub_080C0A00(0);
  cVar2 = iVar1 == 1;
  iVar1 = sub_080C0A00(1);
  if (iVar1 == 1) {
    cVar2 = cVar2 + '\x01';
  }
  iVar1 = sub_080C0A00(2);
  if (iVar1 == 1) {
    cVar2 = cVar2 + '\x01';
  }
  DAT_030068e4 = DAT_0203dacc;
  if (cVar2 == '\x01') {
    DAT_030068e4 = DAT_0203dad4;
  }
  DAT_03006858 = 0;
  return;
}


// sub_0813CED4 @ 0x0813CED4

void sub_0813CED4(void)

{
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813CEE8 @ 0x0813CEE8

void sub_0813CEE8(void)

{
  DAT_0203db5a = 0;
  DAT_030068e4 = DAT_0203dacc;
  DAT_03006858 = 0;
  return;
}


// sub_0813CF0C @ 0x0813CF0C

void sub_0813CF0C(void)

{
  DAT_0203db5a = 0;
  DAT_030068e4 = DAT_0203dac8;
  DAT_03006858 = 0;
  return;
}


// sub_0813CF30 @ 0x0813CF30

void sub_0813CF30(void)

{
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813CF44 @ 0x0813CF44

void sub_0813CF44(void)

{
  DAT_0203db5a = 0;
  DAT_030068e4 = DAT_0203dac8;
  DAT_03006858 = 0;
  return;
}


// sub_0813CF68 @ 0x0813CF68

void sub_0813CF68(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813CF74 @ 0x0813CF74

void sub_0813CF74(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813CF80 @ 0x0813CF80

void sub_0813CF80(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_0300685c;
  DAT_03006858 = 1;
  DAT_0203db7e = 0xffff;
  uVar2 = sub_0813E60C(0xffff,0x1f);
  DAT_0300685c = (undefined1)uVar2;
  sub_08138390(0);
  DAT_0300685c = uVar1;
  DAT_0203db5a = 0;
  DAT_03006858 = 1;
  return;
}


// sub_0813CFD0 @ 0x0813CFD0

void sub_0813CFD0(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813CFDC @ 0x0813CFDC

void sub_0813CFDC(void)

{
  int iVar1;
  
  iVar1 = sub_080CE74C(DAT_030068e0);
  if (iVar1 != 0) {
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 0);
  return;
}


// sub_0813D014 @ 0x0813D014

void sub_0813D014(void)

{
  int iVar1;
  
  iVar1 = sub_080CE74C(DAT_030068e0);
  if (iVar1 != 0) {
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 0);
  return;
}


// sub_0813D04C @ 0x0813D04C

void sub_0813D04C(void)

{
  int iVar1;
  
  iVar1 = sub_080CE74C(DAT_03006964);
  if (iVar1 != 0) {
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 0);
  return;
}


// sub_0813D084 @ 0x0813D084

void sub_0813D084(void)

{
  int iVar1;
  
  iVar1 = sub_080CE74C(DAT_03006964);
  if (iVar1 != 0) {
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 0);
  return;
}


// sub_0813D0BC @ 0x0813D0BC

void sub_0813D0BC(void)

{
  int iVar1;
  
  iVar1 = sub_080CE74C(DAT_03006964);
  if (iVar1 != 0) {
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 0);
  return;
}


// sub_0813D0F4 @ 0x0813D0F4

void sub_0813D0F4(void)

{
  int iVar1;
  
  iVar1 = sub_080B092C();
  if (iVar1 != 1) {
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 1);
  return;
}


