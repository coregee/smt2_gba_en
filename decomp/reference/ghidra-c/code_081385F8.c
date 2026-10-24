/* Ghidra decompilation of asm/code_081385F8.s (reference only; not compiled). */

// ScriptOp_412 @ 0x081385F8

void ScriptOp_412(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_0813848C((uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  return;
}


// sub_08138640 @ 0x08138640

undefined4 sub_08138640(void)

{
  uint uVar1;
  uint arg0;
  
  arg0 = 300;
  do {
    uVar1 = sub_080C32D4(arg0);
    if ((uVar1 & 0xff) != 0) {
      return 1;
    }
    arg0 = arg0 + 1 & 0xffff;
  } while (arg0 < 0x15a);
  return 0;
}


// sub_08138670 @ 0x08138670

uint sub_08138670(void)

{
  uint uVar1;
  
  uVar1 = sub_080C32D4(0x11f);
  return (uint)((uVar1 & 0xff) != 0);
}


// sub_08138690 @ 0x08138690

undefined4 sub_08138690(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int arg0;
  
  iVar1 = sub_080C104C();
  arg0 = 4;
  if (4 < iVar1 + 4) {
    do {
      iVar2 = sub_080C0A00(arg0);
      if ((iVar2 != 0) && (uVar3 = sub_080C07E0(arg0), (ushort)((short)uVar3 - 0x16aU) < 0x12)) {
        return 1;
      }
      arg0 = arg0 + 1;
    } while (arg0 < iVar1 + 4);
  }
  return 0;
}


// Negotiate_SelectResponse @ 0x081386DC

void Negotiate_SelectResponse(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  uint uVar6;
  ushort uVar7;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_94 [4];
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  
  uVar5 = DAT_0203db40 + 1;
  uVar7 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar2 = (uint)(uVar7 >> 8);
  uVar7 = uVar7 & 0xff;
  uVar6 = 0;
  DAT_0203db40 = uVar5;
  if (uVar2 != 0xffffffff) {
    do {
      uVar5 = DAT_0203db40 + 1;
      uVar1 = (uint)DAT_0203db40;
      DAT_0203db40 = DAT_0203db40 + 2;
      local_94[uVar6] =
           CONCAT22(*(undefined2 *)((uint)uVar5 * 2 + DAT_03006950),
                    *(undefined2 *)(uVar1 * 2 + DAT_03006950));
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < uVar2 + 1);
  }
  if (uVar7 == 1) {
    uVar2 = sub_081376AC(0x40);
    if ((uVar2 & 0xffff) != 0) {
      uVar2 = sub_081376AC(0x40);
      uVar4 = local_94[1];
      if ((uVar2 & 0xffff) != 0) {
        uVar4 = local_94[2];
      }
      goto LAB_08138b8e;
    }
  }
  else if (uVar7 == 2) {
    uVar2 = sub_08137720(1);
    if ((uVar2 & 0xffff) == 0) {
      iVar3 = sub_080C2340(9);
      if (((iVar3 != 0) || (uVar2 = sub_081379CC(1), uVar4 = local_94[3], (uVar2 & 0xffff) != 0)) &&
         ((uVar2 = sub_0813C4FC(1), uVar4 = uStack_84, (uVar2 & 0xffff) != 0 &&
          (uVar2 = sub_081376AC(0x80), uVar4 = local_94[2], (uVar2 & 0xffff) != 0)))) {
        uVar4 = local_94[1];
      }
      goto LAB_08138b8e;
    }
  }
  else if (uVar7 == 3) {
    uVar2 = sub_08137720(1);
    if ((uVar2 & 0xffff) == 0) {
      uVar2 = sub_0813C4FC(1);
      uVar4 = local_94[1];
      if ((((uVar2 & 0xffff) == 0) &&
          (uVar2 = sub_081376AC(0x40), uVar4 = local_94[2], (uVar2 & 0xffff) == 0)) &&
         (uVar2 = sub_081376AC(0x80), uVar4 = uStack_84, (uVar2 & 0xffff) != 0)) {
        uVar4 = local_94[3];
      }
      goto LAB_08138b8e;
    }
  }
  else if (uVar7 == 4) {
    uVar2 = sub_08137720(1);
    if ((uVar2 & 0xffff) == 0) {
      uVar2 = sub_08137720(2);
      uVar4 = local_94[1];
      if ((uVar2 & 0xffff) == 0) {
        sub_0813821C(2);
        uVar2 = sub_081376AC(0x80);
        uVar4 = local_94[2];
        if (((uVar2 & 0xffff) == 0) &&
           (uVar2 = sub_081376AC(0x40), uVar4 = uStack_84, (uVar2 & 0xffff) != 0)) {
          uVar4 = local_94[3];
        }
      }
      goto LAB_08138b8e;
    }
  }
  else if (uVar7 == 5) {
    uVar2 = sub_08137720(1);
    if ((uVar2 & 0xffff) == 0) {
      uVar2 = sub_08137720(2);
      uVar4 = local_94[1];
      if ((uVar2 & 0xffff) == 0) {
        sub_0813821C(2);
        uVar2 = sub_081376AC(0x80);
        uVar4 = local_94[2];
        if (((uVar2 & 0xffff) == 0) &&
           (uVar2 = sub_081376AC(0x80), uVar4 = uStack_84, (uVar2 & 0xffff) != 0)) {
          uVar4 = local_94[3];
        }
      }
      goto LAB_08138b8e;
    }
  }
  else if (uVar7 == 6) {
    uVar2 = sub_08137720(1);
    if ((uVar2 & 0xffff) == 0) {
      uVar2 = sub_0813C4FC(2);
      uVar4 = local_94[1];
      if (((uVar2 & 0xffff) == 0) &&
         (uVar2 = sub_0813C4FC(3), uVar4 = local_94[2], (uVar2 & 0xffff) == 0)) {
        uVar2 = sub_0813AC98();
        uVar4 = local_94[3];
        if (((uVar2 & 0xffff) != 1) && (uVar4 = uStack_80, (uVar2 & 0xffff) == 2)) {
          uVar4 = uStack_84;
        }
      }
      goto LAB_08138b8e;
    }
  }
  else if (uVar7 == 7) {
    uVar2 = sub_08137720(1);
    if ((uVar2 & 0xffff) == 0) {
      uVar2 = sub_08137720(2);
      if ((uVar2 & 0xffff) == 0) {
        sub_0813821C(2);
        uVar2 = sub_081376AC(0x40);
        uVar4 = local_94[2];
        if ((uVar2 & 0xffff) != 0) {
          uVar4 = local_94[1];
        }
      }
      else {
        uVar2 = sub_081376AC(0x80);
        uVar4 = uStack_84;
        if ((uVar2 & 0xffff) != 0) {
          uVar4 = local_94[3];
        }
      }
      goto LAB_08138b8e;
    }
  }
  else {
    if (uVar7 == 8) {
      uVar2 = sub_08137720(1);
      if ((uVar2 & 0xffff) != 0) {
        uVar2 = sub_08138338();
        uVar2 = uVar2 & 0xffff;
        if (uVar2 == 0) goto LAB_08138b88;
        uVar4 = local_94[1];
        if ((uVar2 == 1) || (uVar4 = local_94[2], uVar2 == 2)) goto LAB_08138b8e;
        if (uVar2 == 3) {
          uVar2 = sub_0813BF78();
          uVar4 = local_94[3];
          if (((uVar2 & 0xffff) == 0) &&
             (uVar2 = sub_0813BF58(), uVar4 = uStack_84, (uVar2 & 0xffff) != 0)) {
            uVar4 = uStack_80;
          }
          goto LAB_08138b8e;
        }
      }
      uVar2 = sub_0813C4FC(2);
      uVar4 = uStack_7c;
      if ((uVar2 & 0xffff) == 0) {
        uVar2 = sub_0813AC98();
        uVar4 = uStack_78;
        if (((uVar2 & 0xffff) != 1) && (uVar4 = uStack_70, (uVar2 & 0xffff) == 2)) {
          uVar4 = uStack_74;
        }
      }
      goto LAB_08138b8e;
    }
    if (uVar7 == 10) {
      uVar4 = local_94[DAT_0203db72];
      goto LAB_08138b8e;
    }
    uVar4 = DAT_030068e4;
    if (uVar7 != 0xb) goto LAB_08138b8e;
    uVar4 = sub_080C0F8C(0);
    if ((short)uVar4 < 0x15) {
      uVar2 = sub_08138640();
      local_94[3] = local_94[1];
    }
    else {
      uVar2 = sub_08138640();
      if ((uVar2 & 0xffff) != 0) {
        uVar2 = sub_08138670();
        if ((uVar2 & 0xffff) == 0) {
          uVar2 = sub_08138690();
          uVar4 = local_94[1];
          if ((uVar2 & 0xffff) != 0) {
            uVar4 = uStack_78;
          }
        }
        else {
          uVar2 = sub_08138690();
          uVar4 = uStack_7c;
          if ((uVar2 & 0xffff) != 0) {
            uVar4 = uStack_80;
          }
        }
        goto LAB_08138b8e;
      }
      uVar2 = sub_08138670();
      if ((uVar2 & 0xffff) != 0) {
        uVar2 = sub_08138690();
        uVar4 = local_94[2];
        if ((uVar2 & 0xffff) != 0) {
          uVar4 = uStack_84;
        }
        goto LAB_08138b8e;
      }
      uVar2 = sub_08138690();
    }
    uVar4 = local_94[3];
    if ((uVar2 & 0xffff) != 0) goto LAB_08138b8e;
  }
LAB_08138b88:
  uVar4 = local_94[0];
LAB_08138b8e:
  DAT_030068e4 = uVar4;
                    /* WARNING: Could not recover jumptable at 0x08138b94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_3E3 @ 0x08138B9C

void ScriptOp_3E3(void)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar4 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar3 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  uVar5 = sub_0813E60C((uint)DAT_0203db7c,9);
  uVar5 = uVar5 & 0xffff;
  if (sVar1 == 1) {
    uVar6 = sub_080C2244();
    uVar5 = ((uVar6 & 3) + uVar5) * 0x10000;
  }
  else if (sVar1 == 2) {
    uVar6 = sub_080C2244();
    uVar5 = ((uVar6 & 7) + uVar5) * 0x10000;
  }
  else {
    uVar6 = sub_080C2244();
    uVar5 = ((uVar6 & 7) + uVar5) * 0x10000 + 0x30000;
  }
  uVar6 = 0;
  if (uVar5 >> 0x10 != 0) {
    uVar6 = (uVar5 >> 0x10) - 1 & 0xffff;
  }
  iVar7 = sub_080C0E44(0,4);
  if (iVar7 <= (int)uVar6) {
    DAT_030068e4 = CONCAT22(uVar3,uVar2);
  }
                    /* WARNING: Could not recover jumptable at 0x08138c40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_3E4 @ 0x08138C48

void ScriptOp_3E4(void)

{
  return;
}


// ScriptOp_3E5 @ 0x08138C4C

void ScriptOp_3E5(void)

{
  return;
}


// sub_08138C50 @ 0x08138C50

void sub_08138C50(undefined4 arg0)

{
  uint arg0_00;
  
  arg0_00 = (uint)(ushort)arg0;
  DAT_03006670 = 0;
  DAT_0203db70 = (ushort)arg0;
  sub_080EFA88(arg0_00);
  if (arg0_00 == 1) {
    sub_080EFA20(0xfffffffe);
  }
  else if (arg0_00 == 2) {
    sub_080EFA44(0xfffffffe);
  }
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db40 = 0;
  DAT_0203db46 = 1;
  sub_0813EB6C(0);
  DAT_0203db5a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  sub_080AD1FC(DAT_030069e4);
  DAT_0203db6e = 1;
  return;
}


// sub_08138CE8 @ 0x08138CE8

undefined4 sub_08138CE8(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080F3144();
  if ((uVar1 & 0xff) == 1) {
    sub_08138C50(7);
    uVar2 = 2;
  }
  else {
    iVar3 = sub_080ED9F4();
    if (iVar3 == 0) {
      sub_08138C50(0xc);
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08138d16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// ScriptOp_3E6 @ 0x08138D18

void ScriptOp_3E6(int arg0)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_08138C50((uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  DAT_0203db86 = 0;
  *(undefined2 *)(arg0 + 0x1c) = 1;
  return;
}


// ScriptOp_401 @ 0x08138D50

void ScriptOp_401(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_0203db28 = *(ushort *)((uint)uVar1 * 2 + DAT_03006950) | 0x100;
  DAT_03006970 = 1;
  DAT_0203db66 = 1;
  if (DAT_0203db28 == 0x110) {
    DAT_0203db2a = 0x10f;
    DAT_03006972 = 1;
  }
  DAT_0203db68 = (ushort)(DAT_0203db28 == 0x110);
  return;
}


// sub_08138DB8 @ 0x08138DB8

void sub_08138DB8(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_402 @ 0x08138DC8

void ScriptOp_402(void)

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
  sub_080D5374((uint)DAT_0203db84);
  DAT_0203db5a = 0x4d;
  DAT_0203db6e = 1;
  return;
}


// ScriptOpAlt_402 @ 0x08138E60

void ScriptOpAlt_402(void)

{
  return;
}


// ScriptOp_403 @ 0x08138E64

void ScriptOp_403(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_080BE6E0((uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  DAT_0203db5a = 0x4a;
  DAT_0203db6e = 1;
  return;
}


// ScriptOpAlt_403 @ 0x08138EA0

void ScriptOpAlt_403(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_404 @ 0x08138EB0

void ScriptOp_404(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar4 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar3 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  uVar5 = sub_080C104C();
  uVar7 = 0;
  if (uVar5 != 0) {
    do {
      iVar6 = sub_080C09B0(uVar7 + 4);
      if (iVar6 == 0) {
        sub_080C062C((uint)*(ushort *)((uVar1 - 1) * 2 + 0x203db28));
        return;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar5);
  }
  DAT_030068e4 = CONCAT22(uVar3,uVar2);
  return;
}


// ScriptOpAlt_404 @ 0x08138F28

void ScriptOpAlt_404(void)

{
  DAT_0203db40 = DAT_0203db40 + 3;
  return;
}


// ScriptOp_405 @ 0x08138F38

void ScriptOp_405(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint arg0;
  
  uVar1 = *(ushort *)((*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950) - 1) * 2 + 0x203db28);
  DAT_0203db40 = DAT_0203db40 + 1;
  iVar2 = sub_080C104C();
  arg0 = 4;
  do {
    if (iVar2 + 4 <= (int)arg0) {
LAB_08138f9c:
      sub_080C366C();
      return;
    }
    iVar3 = sub_080C09B0(arg0);
    if ((iVar3 != 0) && (uVar4 = sub_080C07E0(arg0), (int)(short)uVar4 == (uint)uVar1)) {
      sub_080C0290(arg0,1);
      goto LAB_08138f9c;
    }
    arg0 = arg0 + 1 & 0xffff;
  } while( true );
}


// ScriptOpAlt_405 @ 0x08138FA8

void ScriptOpAlt_405(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_406 @ 0x08138FB8

void ScriptOp_406(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_080BA8D8(0,(uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  DAT_0203db6e = 1;
  return;
}


// ScriptOpAlt_406 @ 0x08138FEC

void ScriptOpAlt_406(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_407 @ 0x08138FFC

void ScriptOp_407(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_080BA958(0,(uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  DAT_0203db6e = 1;
  return;
}


// ScriptOpAlt_407 @ 0x08139030

void ScriptOpAlt_407(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_408 @ 0x08139040

void ScriptOp_408(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_080BA8D8(1,(uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  DAT_0203db5a = 0x4a;
  DAT_0203db6e = 1;
  return;
}


// ScriptOpAlt_408 @ 0x0813907C

void ScriptOpAlt_408(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_409 @ 0x0813908C

void ScriptOp_409(void)

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
  DAT_0203db5a = 0x48;
  sub_0812F198();
  DAT_03006940 = 0;
  DAT_0300696c = 0;
  DAT_03006844 = 1;
  CasinoPrize_DrawList(0);
  sub_080AD0FC(0x878ff48,0xffff);
  DAT_0203db6e = 1;
  return;
}


// CasinoPrize_DrawList @ 0x0813914C

void CasinoPrize_DrawList(uint arg0)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  dword arg0_00;
  uint uVar7;
  short sVar8;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 auStack_5c [8];
  undefined1 auStack_4c [16];
  uint local_3c;
  int local_38;
  int iStack_34;
  int iStack_30;
  undefined1 *puStack_2c;
  uint uStack_28;
  undefined2 *puStack_24;
  
  local_3c = arg0 & 0xffff;
  uVar2 = sub_081394B4();
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  if (DAT_03006844 == 1) {
    sub_0812F1E4();
  }
  if (local_3c == 0) {
    DAT_03006848 = 0;
    DAT_03006680 = 1;
  }
  else if (local_3c == (*(ushort *)((uVar2 & 0xffff) * 0x20 + 0x878fea8) - 3) + (int)DAT_03006844) {
    DAT_03006848 = 1;
    DAT_03006680 = 0;
  }
  else {
    DAT_03006848 = 1;
    DAT_03006680 = 1;
  }
  local_38 = 3;
  if (DAT_03006844 == 0) {
    local_38 = 4;
  }
  if ((int)local_3c < (int)(local_3c + local_38)) {
    iStack_34 = (uVar2 & 0xffff) * 0x20;
    uVar1 = *(ushort *)((local_3c * 2 + 1) * 2 + iStack_34 + 0x878fea8);
    uVar2 = local_3c;
    while (uVar7 = (uint)uVar1, uVar7 != 0xffff) {
      if (uVar7 < 0xd0) {
        if (uVar7 < 0x80) {
          iVar3 = sub_080BF32C(uVar7);
        }
        else {
          iVar3 = Equipment_GetRecord36_MidRange(uVar7);
        }
        puVar6 = (undefined2 *)(iVar3 + 0x14);
      }
      else {
        iVar3 = Action_GetRecord(uVar7);
        puVar6 = (undefined2 *)(iVar3 + 0xc);
      }
      uVar7 = 0;
      iVar3 = uVar2 - local_3c;
      puStack_2c = auStack_4c;
      uStack_28 = uVar2 + 1;
      iStack_30 = local_3c + local_38;
      do {
        *(undefined2 *)(uVar7 * 2 + 0x203db08) = 0;
        uVar7 = uVar7 + 1 & 0xffff;
      } while (uVar7 < 0x10);
      uVar7 = 0;
      do {
        *(undefined2 *)(uVar7 * 2 + 0x203db08) = *puVar6;
        puVar6 = puVar6 + 1;
        uVar7 = uVar7 + 1 & 0xffff;
      } while (uVar7 < 8);
      sub_08133E70(0x1a,(uint)*(ushort *)((DAT_03006844 + iVar3) * 2 + 0x8790390),0,8);
      arg0_00 = (dword)*(ushort *)((uVar2 * 2 + 2) * 2 + iStack_34 + 0x878fea8);
      if (arg0_00 == 0xffff) {
        arg0_00 = 100000;
      }
      uVar2 = 0;
      do {
        auStack_5c[uVar2] = 0xffff;
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < 8);
      uVar2 = 0;
      do {
        if (arg0_00 == 0) break;
        iVar4 = __umodsi3(arg0_00,10);
        auStack_5c[uVar2] = *(undefined2 *)(iVar4 * 2 + 0x878f9b8);
        arg0_00 = __udivsi3(arg0_00,10);
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < 8);
      uVar7 = 0;
      uVar2 = 7;
      do {
        *(undefined2 *)(puStack_2c + uVar7 * 2) = auStack_5c[(short)uVar2];
        uVar7 = uVar7 + 1 & 0xffff;
        uVar5 = (int)(short)uVar2 - 1;
        uVar2 = uVar5 & 0xffff;
      } while (-1 < (int)(uVar5 * 0x10000));
      sVar8 = 0;
      uVar2 = 0;
      do {
        if (*(short *)(puStack_2c + uVar2 * 2) != -1) {
          uVar7 = DAT_0203db3e & 0x3fff;
          uVar5 = uVar7 * 4 | 1;
          *(short *)(uVar7 * 8 + 0x203d800) = *(short *)(puStack_2c + uVar2 * 2);
          uVar7 = uVar5 + 1 & 0xffff;
          *(short *)(uVar5 * 2 + 0x203d800) = sVar8 * 10 + 0x8d;
          puStack_24 = (undefined2 *)(uVar7 * 2 + 0x203d800);
          *puStack_24 = *(undefined2 *)((DAT_03006844 + iVar3) * 2 + 0x8790390);
          *(undefined2 *)((uVar7 + 1 & 0xffff) * 2 + 0x203d800) = 0;
          uVar7 = DAT_0203db3e + 1;
          DAT_0203db3e = (ushort)uVar7;
          sVar8 = sVar8 + 1;
          if (0x3f < (uVar7 & 0xffff)) {
            DAT_0203db3e = 0x3f;
          }
        }
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < 8);
      uVar2 = DAT_0203db3e & 0x3fff;
      uVar7 = uVar2 * 4 | 1;
      *(undefined2 *)(uVar2 * 8 + 0x203d800) = 0xfc8;
      uVar2 = uVar7 + 1 & 0xffff;
      *(short *)(uVar7 * 2 + 0x203d800) = sVar8 * 10 + 0x8f;
      *(undefined2 *)(uVar2 * 2 + 0x203d800) =
           *(undefined2 *)((DAT_03006844 + iVar3) * 2 + 0x8790390);
      *(undefined2 *)((uVar2 + 1 & 0xffff) * 2 + 0x203d800) = 0;
      uVar2 = DAT_0203db3e + 1;
      DAT_0203db3e = (ushort)uVar2;
      if (0x3f < (uVar2 & 0xffff)) {
        DAT_0203db3e = 0x3f;
      }
      uVar2 = uStack_28 & 0xffff;
      if (iStack_30 <= (int)uVar2) break;
      uVar1 = *(ushort *)((uVar2 * 2 + 1) * 2 + iStack_34 + 0x878fea8);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08139488. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081394B4 @ 0x081394B4

undefined4 sub_081394B4(void)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C2340(0xb9);
  if (iVar1 == 1) {
    iVar1 = sub_080C57CC(0x157);
    if (iVar1 == 1) {
      uVar2 = 4;
      goto LAB_08139500;
    }
  }
  else {
    iVar1 = sub_080C2340(199);
    if (iVar1 == 1) {
      uVar2 = 1;
      goto LAB_08139500;
    }
    iVar1 = sub_080C2340(0xbc);
    if (iVar1 == 1) {
      uVar2 = 2;
      goto LAB_08139500;
    }
    iVar1 = sub_080C2340(200);
    if (iVar1 == 1) {
      uVar2 = 3;
      goto LAB_08139500;
    }
  }
  uVar2 = 0;
LAB_08139500:
                    /* WARNING: Could not recover jumptable at 0x08139502. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// ScriptOpAlt_409 @ 0x08139504

void ScriptOpAlt_409(void)

{
  DAT_0203db40 = DAT_0203db40 + 6;
  return;
}


// ScriptOp_40A @ 0x08139514

void ScriptOp_40A(void)

{
  char cVar1;
  ushort *puVar2;
  short sVar3;
  
  sVar3 = DAT_0203db40 + 1;
  puVar2 = (ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  cVar1 = (char)*puVar2;
  DAT_0203db40 = sVar3;
  if (*puVar2 >> 8 == 0) {
    if (cVar1 == '\0') {
      sub_080C700C();
      DAT_0203db5c = 0x5a;
      DAT_0203db5a = 0xf;
      DAT_0203db6e = 1;
    }
    else if (cVar1 == '\x01') {
      DAT_03006954 = sub_080D3740();
      DAT_0203db5c = 2;
      DAT_0203db5a = 0xf;
      DAT_0203db6e = 1;
    }
    if (cVar1 != '\x06') {
      return;
    }
    sub_080C7648();
  }
  else {
    if (cVar1 == '\0') {
      sub_080C6FF0();
      DAT_0203db5c = 0x5a;
      DAT_0203db5a = 0xf;
      DAT_0203db6e = 1;
    }
    else if (cVar1 == '\x01') {
      sub_080D3758(DAT_03006954);
      DAT_0203db5c = 2;
      DAT_0203db5a = 0xf;
      DAT_0203db6e = 1;
    }
    if (cVar1 != '\x06') {
      return;
    }
    sub_080C762C();
  }
  DAT_0203db6e = 1;
  DAT_0203db5c = 2;
  DAT_0203db5a = 0xf;
  return;
}


// ScriptOpAlt_40A @ 0x08139610

void ScriptOpAlt_40A(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  return;
}


// ScriptOp_40C @ 0x08139620

void ScriptOp_40C(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_0203db50 = *(ushort *)((uint)uVar1 * 2 + DAT_03006950) | 0x100;
  return;
}


// ScriptOp_40B @ 0x08139650

void ScriptOp_40B(void)

{
  uint uVar1;
  undefined4 uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar4 = DAT_0203db40 + 1;
  uVar1 = (uint)DAT_0203db40;
  uVar5 = DAT_0203db40 + 2;
  uVar3 = DAT_0203db40 + 3;
  DAT_0203db40 = DAT_0203db40 + 4;
  uVar2 = CONCAT22(*(undefined2 *)((uint)uVar4 * 2 + DAT_03006950),
                   *(undefined2 *)(uVar1 * 2 + DAT_03006950));
  if ((DAT_03006990 != -1) && (uVar2 = DAT_030068e4, DAT_03006992 == -1)) {
    DAT_030069cc = 1;
    DAT_030068e4 = DAT_0203daf0;
    DAT_0203db04 = CONCAT22(*(undefined2 *)((uint)uVar3 * 2 + DAT_03006950),
                            *(undefined2 *)((uint)uVar5 * 2 + DAT_03006950));
    uVar2 = DAT_030068e4;
  }
  DAT_030068e4 = uVar2;
  return;
}


// ScriptOpAlt_40B @ 0x081396E0

void ScriptOpAlt_40B(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  return;
}


// ScriptOp_40D @ 0x081396F0

void ScriptOp_40D(void)

{
  ushort uVar1;
  int iVar2;
  short sVar3;
  uint arg0;
  
  sVar3 = DAT_0203db40 + 1;
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  arg0 = uVar1 & 0xff;
  DAT_0203db40 = sVar3;
  if ((arg0 == 1) && (iVar2 = sub_080C09B0(1), iVar2 == 0)) {
    iVar2 = sub_080C09B0(1);
    if (iVar2 == 0) {
      return;
    }
    arg0 = 2;
  }
  sub_080C0EC0(arg0,(uint)(uVar1 >> 8),1);
  sub_080BF938(arg0);
  if (arg0 == 1) {
    sub_080C0A7C(1);
    sub_080C0AA8(1);
  }
  sub_080CDC34();
  return;
}


// ScriptOpAlt_40D @ 0x08139758

void ScriptOpAlt_40D(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_40E @ 0x08139768

void ScriptOp_40E(void)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = DAT_0203db40 + 1;
  uVar2 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950) & 0xf;
  DAT_0203db40 = sVar1;
  if (uVar2 == 2) {
    sub_080C2364(0x10b);
  }
  else if (uVar2 == 4) {
    sub_080C2364(0x10c);
  }
  return;
}


// ScriptOpAlt_40E @ 0x081397A8

void ScriptOpAlt_40E(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// sub_081397B8 @ 0x081397B8

void sub_081397B8(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOpAlt_40F @ 0x081397C8

void ScriptOpAlt_40F(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// sub_081397D8 @ 0x081397D8

uint sub_081397D8(void)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  
  uVar1 = sub_080C2244();
  sVar2 = *(short *)((uVar1 & 0x1f) * 2 + 0x8790ae6);
  if (DAT_0203bb7a == sVar2) {
    if (sVar2 == 9) {
      sVar2 = 0;
    }
    else {
      sVar2 = sVar2 + 1;
    }
  }
  DAT_0203bb7a = sVar2;
  sVar4 = 0;
  if ((DAT_0203bb76 != 0) && (sVar4 = 100, DAT_0203bb76 == 1)) {
    sVar4 = 0x32;
  }
  uVar5 = (uint)(ushort)(sVar4 + sVar2 * 5);
  iVar3 = ((DAT_0203bb78 - 1 & 0xffff) >> 1) * 0x96;
  uVar1 = (uint)*(byte *)(uVar5 + iVar3 + 0x879050a);
  DAT_0203db28 = (ushort)(byte)(&DAT_0879050b)[uVar5 + iVar3];
  DAT_03006970 = (ushort)(byte)(&UNK_0879050c)[uVar5 + iVar3];
  DAT_0203db2c = (uint)(byte)(&UNK_0879050c)[uVar5 + iVar3];
  DAT_0203db66 = 1;
  if (uVar1 == 2) {
    DAT_0203db2a = (ushort)(byte)(&UNK_0879050d)[uVar5 + iVar3];
    DAT_0203db30 = (uint)(byte)(&UNK_0879050e)[uVar5 + iVar3];
    DAT_03006972 = (ushort)(byte)(&UNK_0879050e)[uVar5 + iVar3];
    DAT_0203db68 = 1;
  }
  return uVar1;
}


// sub_081398C8 @ 0x081398C8

uint sub_081398C8(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = sub_080C2244();
  iVar2 = 0;
  if ((DAT_0203bb76 != 0) && (iVar2 = 100, DAT_0203bb76 == 1)) {
    iVar2 = 0x32;
  }
  uVar3 = iVar2 + ((uint)*(ushort *)((uVar1 & 0x1f) * 2 + 0x8790ae6) * 0x50000 >> 0x10) & 0xffff;
  iVar2 = (DAT_0203bb78 - 1 & 0xffff) * 0x96;
  uVar1 = (uint)*(byte *)(uVar3 + iVar2 + 0x87907f8);
  DAT_0203db28 = (ushort)(byte)(&UNK_087907f9)[uVar3 + iVar2];
  DAT_03006970 = (ushort)(byte)(&UNK_087907fa)[uVar3 + iVar2];
  DAT_0203db2c = (uint)(byte)(&UNK_087907fa)[uVar3 + iVar2];
  DAT_0203db66 = 1;
  if (uVar1 == 2) {
    DAT_0203db2a = (ushort)(byte)(&UNK_087907fb)[uVar3 + iVar2];
    DAT_0203db30 = (uint)(byte)(&UNK_087907fc)[uVar3 + iVar2];
    DAT_03006972 = (ushort)(byte)(&UNK_087907fc)[uVar3 + iVar2];
    DAT_0203db68 = 1;
  }
  return uVar1;
}


// sub_0813999C @ 0x0813999C

void sub_0813999C(undefined4 arg0)

{
  if ((short)arg0 == 3) {
    DAT_0203db28 = (ushort)*(byte *)(DAT_0203bb78 + 0x8790b26);
    DAT_0203db2c = 8;
    if ((DAT_0203bb76 != 0) && (DAT_0203db2c = 2, DAT_0203bb76 == 1)) {
      DAT_0203db2c = 4;
    }
    DAT_03006970 = (undefined2)DAT_0203db2c;
    DAT_0203db66 = 1;
  }
  return;
}


// ScriptOp_410 @ 0x081399F0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScriptOp_410(void)

{
  short sVar1;
  ushort uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar7 = DAT_0203db40 + 3;
  uVar8 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 2) * 2 + DAT_03006950),
                   *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950));
  uVar2 = DAT_0203db40 + 4;
  DAT_0203db40 = DAT_0203db40 + 5;
  uVar9 = CONCAT22(*(undefined2 *)((uint)uVar2 * 2 + DAT_03006950),
                   *(undefined2 *)((uint)uVar7 * 2 + DAT_03006950));
  if (sVar1 == 1) {
    if (4 < *(ushort *)((uint)DAT_03006914 * 2 + 0x8790c1c)) {
      puVar3 = (undefined4 *)0x30068e4;
      goto LAB_08139dca;
    }
  }
  else if (sVar1 == 2) {
    if (*(short *)((uint)DAT_03006914 * 2 + 0x8790c1c) != 2) goto LAB_08139dcc;
  }
  else if (sVar1 == 3) {
    if (*(short *)((uint)DAT_03006914 * 2 + 0x8790c1c) != 3) goto LAB_08139dcc;
  }
  else if (sVar1 == 4) {
    if (*(short *)((uint)DAT_03006914 * 2 + 0x8790c1c) != 4) goto LAB_08139dcc;
  }
  else if (sVar1 == 5) {
    uVar2 = *(ushort *)((uint)DAT_03006914 * 2 + 0x8790c1c);
joined_r0x08139cae:
    if (uVar2 != 5) goto LAB_08139dcc;
  }
  else if (sVar1 == 6) {
    if (*(short *)((uint)DAT_03006914 * 2 + 0x8790c1c) != 6) goto LAB_08139dcc;
  }
  else if (sVar1 == 7) {
    if (*(short *)((uint)DAT_03006914 * 2 + 0x8790c1c) != 7) goto LAB_08139dcc;
  }
  else {
    if (sVar1 != 8) {
      if (sVar1 == 9) {
        sub_080D3A80();
        DAT_0203db5a = 0x50;
        DAT_0203dac8 = uVar8;
      }
      else if (sVar1 == 10) {
        DAT_0203dac8 = uVar8;
        sub_080D3AA0(2);
        DAT_0203db5a = 0x50;
      }
      else {
        if (sVar1 != 0xb) {
          if (sVar1 == 0xc) {
            uVar4 = 300;
            do {
              uVar5 = sub_080C32D4(uVar4);
              if ((uVar5 & 0xff) != 0) goto LAB_08139dcc;
              uVar4 = uVar4 + 1 & 0xffff;
            } while (uVar4 < 0x15a);
          }
          else if (sVar1 == 0xd) {
            uVar4 = sub_080C3100();
            if (DAT_0203db2c <= uVar4) goto LAB_08139dcc;
          }
          else if (sVar1 == 0xe) {
            uVar9 = sub_080C0F8C(0);
            if (((short)uVar9 < 0x15) || (uVar4 = sub_080C32D4(0x11f), (uVar4 & 0xff) == 0))
            goto LAB_08139dcc;
          }
          else {
            if (sVar1 == 0xf) {
              DAT_0203dac8 = uVar8;
              DAT_0203dacc = uVar9;
              sub_080D3DF0();
              DAT_0203db5a = 0x51;
              goto LAB_08139d84;
            }
            if (sVar1 == 0x10) {
              if (_DAT_0203bb74 == 2) {
                sub_0813999C(3);
                goto LAB_08139dcc;
              }
              if (_DAT_0203bb74 == 1) {
                uVar4 = sub_081398C8();
              }
              else {
                uVar4 = sub_081397D8();
              }
              goto joined_r0x08139c7e;
            }
            if (sVar1 != 0x11) {
              if (sVar1 == 0x12) {
                if (_DAT_0203bb74 == 0) goto LAB_08139da8;
                if (_DAT_0203bb74 != 1) goto LAB_08139dcc;
                puVar3 = (undefined4 *)0x30068e4;
              }
              else if (sVar1 == 0x13) {
                if (DAT_0203bb76 == 0) goto LAB_08139da8;
                if (DAT_0203bb76 != 1) goto LAB_08139dcc;
                puVar3 = (undefined4 *)0x30068e4;
              }
              else if (sVar1 == 0x14) {
                uVar4 = __umodsi3((uint)DAT_0203bb78,10);
                if ((uVar4 & 0xffff) != 0) goto LAB_08139dcc;
                puVar3 = (undefined4 *)0x30068e4;
              }
              else if (sVar1 == 0x15) {
                uVar4 = sub_080C32D4(0x11f);
                if ((((uVar4 & 0xff) == 0) || (iVar6 = sub_080C0A00(0), iVar6 != 1)) ||
                   (uVar8 = sub_080C0F8C(0), (short)uVar8 < 0x15)) goto LAB_08139dcc;
                uVar4 = 0;
                do {
                  sub_080C09B0(uVar4 + 4);
                  uVar4 = uVar4 + 1 & 0xffff;
                } while (uVar4 < 0xc);
                iVar6 = sub_080C2340(0xd4);
                if (iVar6 == 1) goto LAB_08139dcc;
                sub_080C2364(0xd4);
                puVar3 = (undefined4 *)0x30068e4;
              }
              else {
                if (sVar1 == 0x16) {
                  DAT_0203db5a = 10;
                  DAT_0203dac8 = uVar8;
                  DAT_030068e0 = sub_080ABEB4(1);
                  goto LAB_08139d84;
                }
                if (sVar1 == 0x17) {
                  iVar6 = sub_080C5C50();
                  if (iVar6 == 0) goto LAB_08139da8;
                  uVar4 = sub_080C5C7C();
                  if (uVar4 < 3) goto LAB_08139dcc;
                  puVar3 = (undefined4 *)0x30068e4;
                }
                else {
                  puVar3 = (undefined4 *)0x3006840;
                  DAT_030068e4 = uVar8;
                }
              }
LAB_08139dca:
              *puVar3 = uVar9;
              goto LAB_08139dcc;
            }
            if (_DAT_0203bb74 == 2) {
              if (DAT_0203bb78 != 0xf3) goto LAB_08139dcc;
            }
            else {
              uVar2 = DAT_0203bb78;
              if (_DAT_0203bb74 != 0) goto joined_r0x08139cae;
              if (DAT_0203bb78 != 10) goto LAB_08139dcc;
            }
          }
          goto LAB_08139da8;
        }
        DAT_0203dac8 = uVar8;
        DAT_0203dacc = uVar9;
        sub_080D3CAC();
        DAT_0203db5a = 0x51;
      }
LAB_08139d84:
      DAT_0203db6e = 1;
      goto LAB_08139dcc;
    }
    uVar4 = sub_080C2A84(0);
    if (((uVar4 & 0xffff) != 1) && (uVar4 = sub_080C2A84(1), (uVar4 & 0xffff) != 1)) {
      uVar4 = sub_080C2A84(2);
joined_r0x08139c7e:
      if ((uVar4 & 0xffff) != 1) goto LAB_08139dcc;
    }
  }
LAB_08139da8:
  DAT_030068e4 = uVar8;
LAB_08139dcc:
                    /* WARNING: Could not recover jumptable at 0x08139dd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOpAlt_410 @ 0x08139DDC

void ScriptOpAlt_410(void)

{
  DAT_0203db40 = DAT_0203db40 + 5;
  return;
}


// ScriptOp_411 @ 0x08139DEC

void ScriptOp_411(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_030068e4 = DAT_03006840;
  return;
}


// ScriptOpAlt_411 @ 0x08139E0C

void ScriptOpAlt_411(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_421 @ 0x08139E1C

void ScriptOp_421(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  uVar1 = *(ushort *)((uint)uVar1 * 2 + DAT_03006950);
  if (uVar1 == 3) {
    DAT_0203db82 = 2;
  }
  else if (uVar1 < 3) {
    DAT_0203db82 = 1;
  }
  else {
    DAT_0203db82 = uVar1 - 2;
  }
  return;
}


// ScriptOpAlt_421 @ 0x08139E6C

void ScriptOpAlt_421(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_422 @ 0x08139E7C

void ScriptOp_422(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar4 = DAT_0203db40 + 1;
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar6 = uVar1 & 0xff;
  uVar5 = (uint)(uVar1 >> 8);
  DAT_0203db6e = 1;
  DAT_0203db40 = sVar4;
  if (uVar5 == 0x10) {
    iVar2 = sub_080C0A00(0);
    if (iVar2 == 1) {
      uVar5 = sub_08134DE0(0);
      uVar5 = __udivsi3(uVar6 * (uVar5 & 0xffff) & 0xffff,100);
      sub_080C0AD4(0,-(uVar5 & 0xffff));
    }
  }
  else if (uVar5 == 0xff) {
    sub_080C366C();
  }
  else {
    iVar2 = sub_080C0A00(uVar5);
    if (iVar2 == 1) {
      uVar3 = sub_08134DE0(uVar5);
      uVar6 = __udivsi3(uVar6 * (uVar3 & 0xffff) & 0xffff,100);
      sub_080C0AD4(uVar5,-(uVar6 & 0xffff));
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08139f1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOpAlt_422 @ 0x08139F20

void ScriptOpAlt_422(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  return;
}


// ScriptOp_423 @ 0x08139F30

void ScriptOp_423(void)

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
  uVar5 = sub_080C1D9C();
  uVar5 = uVar5 & 0xf0;
  if (0x8f < uVar5) {
    uVar5 = 0x80 - (uVar5 - 0x80 & 0xffff) & 0xffff;
  }
  if (uVar5 != (uVar1 & 0xfff) * 0x10) {
    DAT_030068e4 = CONCAT22(uVar3,uVar2);
  }
  return;
}


// ScriptOpAlt_423 @ 0x08139FA0

void ScriptOpAlt_423(void)

{
  DAT_0203db40 = DAT_0203db40 + 3;
  return;
}


// ScriptOp_424 @ 0x08139FB0

void ScriptOp_424(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_03005f76 = (undefined1)uVar1;
  DAT_03005f75 = (undefined1)((ushort)uVar1 >> 8);
  DAT_0203db40 = DAT_0203db40 + 1;
  uVar2 = sub_080C1D9C();
  DAT_03005f74 = (char)uVar2;
  return;
}


// ScriptOpAlt_424 @ 0x0813A008

void ScriptOpAlt_424(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_425 @ 0x0813A018

void ScriptOp_425(void)

{
  return;
}


// ScriptOpAlt_425 @ 0x0813A01C

void ScriptOpAlt_425(void)

{
  return;
}


// ScriptOp_426 @ 0x0813A020

void ScriptOp_426(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar5 = 0;
  do {
    *(undefined4 *)(uVar5 * 4 + 0x203dac8) = 0;
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 0x10);
  if ((DAT_03006914 & 0xff00) != 0) {
    if (DAT_03006914 == 0x104) {
      uVar9 = 0x15;
    }
    else if (DAT_03006914 < 0x105) {
      uVar9 = 10;
    }
    else {
      uVar9 = 0xef;
    }
    DAT_030068f0 = sub_080C4618(0,uVar9,0x50,3);
    DAT_03006998 = 0xffff;
    DAT_03006996 = 0xffff;
    DAT_03006994 = 0xffff;
    DAT_03006992 = 0xffff;
    DAT_03006990 = 0xffff;
    iVar2 = *(int *)((uint)(byte)DAT_03006914 * 4 + 0x8035bb8);
    uVar5 = 0;
    while( true ) {
      puVar4 = *(ushort **)(uVar5 * 4 + iVar2);
      uVar1 = *puVar4;
      iVar3 = sub_080C2340((uint)uVar1);
      if ((iVar3 == 1) || (uVar1 == 0xff)) break;
      uVar5 = uVar5 + 1 & 0xffff;
    }
    uVar5 = 1;
    uVar6 = 0;
    uVar1 = puVar4[1];
    while (uVar1 != 0xff) {
      uVar7 = uVar5 + 1 & 0xffff;
      *(ushort *)(uVar6 * 2 + 0x3006990) = puVar4[uVar5];
      uVar8 = uVar7 + 1 & 0xffff;
      uVar5 = uVar8 + 1 & 0xffff;
      *(uint *)((uVar6 + 10) * 4 + 0x203dac8) = CONCAT22(puVar4[uVar8],puVar4[uVar7]);
      uVar6 = uVar6 + 1 & 0xffff;
      uVar1 = puVar4[uVar5];
    }
    uVar5 = 0;
    if ((char)DAT_03006990 != -1) {
      do {
        uVar5 = uVar5 + 1 & 0xffff;
        if (3 < uVar5) break;
      } while ((*(ushort *)(uVar5 * 2 + 0x3006990) & 0xff) != 0xff);
    }
    uVar6 = 0;
    do {
      puVar4 = (ushort *)(uVar6 * 2 + 0x3006990);
      uVar7 = uVar6 + 1;
      if (*(char *)puVar4 != -1) {
        uVar9 = sub_080C4618(uVar7 & 0xffff,(uint)*(ushort *)((uint)*puVar4 * 2 + 0x8790c9a),
                             (uint)*(byte *)((uVar5 - 1) * 4 + uVar6 + 0x8790c8a),0);
        *(undefined4 *)(uVar7 * 4 + 0x30068f0) = uVar9;
      }
      uVar6 = uVar7 & 0xffff;
    } while (uVar6 < 4);
  }
  if (DAT_03006914 < 0x104) {
    uVar9 = 8;
  }
  else {
    uVar9 = 0x57;
    if (DAT_03006914 == 0x104) {
      uVar9 = 0x12;
    }
  }
  DAT_030068b0 = sub_080B6DB4(uVar9);
  DAT_0203db5a = 2;
  DAT_0203db6e = 1;
                    /* WARNING: Could not recover jumptable at 0x0813a214. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0813A224 @ 0x0813A224

void sub_0813A224(void)

{
  return;
}


// ScriptOp_427 @ 0x0813A228

void ScriptOp_427(void)

{
  return;
}


// ScriptOpAlt_427 @ 0x0813A22C

void ScriptOpAlt_427(void)

{
  return;
}


// ScriptOp_428 @ 0x0813A230

void ScriptOp_428(void)

{
  return;
}


// ScriptOpAlt_428 @ 0x0813A234

void ScriptOpAlt_428(void)

{
  return;
}


// ScriptOp_429 @ 0x0813A238

void ScriptOp_429(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = DAT_0203db40 + 1;
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  DAT_0203db5a = 0x14;
  DAT_03006954 = sub_080B7AFC(0,(uint)(uVar1 >> 8),uVar1 & 0xff,
                              (uint)*(ushort *)((uint)uVar2 * 2 + DAT_03006950));
  DAT_0203db6e = 1;
  return;
}


// sub_0813A298 @ 0x0813A298

void sub_0813A298(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  return;
}


// ScriptOp_42A @ 0x0813A2A8

void ScriptOp_42A(void)

{
  return;
}


// ScriptOpAlt_42A @ 0x0813A2AC

void ScriptOpAlt_42A(void)

{
  return;
}


// ScriptOp_42B @ 0x0813A2B0

void ScriptOp_42B(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_0203db6e = 1;
  return;
}


// ScriptOpAlt_42B @ 0x0813A2C8

void ScriptOpAlt_42B(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_42C @ 0x0813A2D8

void ScriptOp_42C(void)

{
  return;
}


// ScriptOpAlt_42C @ 0x0813A2DC

void ScriptOpAlt_42C(void)

{
  return;
}


// ScriptOp_42D @ 0x0813A2E0

void ScriptOp_42D(void)

{
  return;
}


// ScriptOpAlt_42D @ 0x0813A2E4

void ScriptOpAlt_42D(void)

{
  return;
}


// ScriptOp_42E @ 0x0813A2E8

void ScriptOp_42E(void)

{
  return;
}


// ScriptOpAlt_42E @ 0x0813A2EC

void ScriptOpAlt_42E(void)

{
  return;
}


// ScriptOp_42F @ 0x0813A2F0

void ScriptOp_42F(void)

{
  return;
}


// ScriptOpAlt_42F @ 0x0813A2F4

void ScriptOpAlt_42F(void)

{
  return;
}


// ScriptOp_430 @ 0x0813A2F8

void ScriptOp_430(void)

{
  sub_080C5DE0();
  return;
}


// ScriptOpAlt_430 @ 0x0813A304

void ScriptOpAlt_430(void)

{
  return;
}


// ScriptOp_431 @ 0x0813A308

void ScriptOp_431(void)

{
  return;
}


// ScriptOpAlt_431 @ 0x0813A30C

void ScriptOpAlt_431(void)

{
  return;
}


// ScriptOp_432 @ 0x0813A310

void ScriptOp_432(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  DAT_0203db40 = DAT_0203db40 + 1;
  puVar1 = (undefined1 *)sub_080F2F64(0x8000);
  *puVar1 = 0x31;
  iVar2 = sub_080F2F64(0x8000);
  *(undefined1 *)(iVar2 + 1) = 0x7c;
  iVar2 = sub_080F2F64(0x8000);
  *(undefined1 *)(iVar2 + 2) = 0x65;
  iVar2 = sub_080F2F64(0x8000);
  *(undefined1 *)(iVar2 + 3) = 0xff;
  iVar2 = sub_080F2F64(0x8000);
  *(undefined1 *)(iVar2 + 4) = 0xff;
  iVar2 = sub_080F2F64(0x8000);
  *(undefined1 *)(iVar2 + 5) = 0xff;
  iVar2 = sub_080F2F64(0x8000);
  *(undefined1 *)(iVar2 + 6) = 0xff;
  iVar2 = sub_080F2F64(0x8000);
  *(undefined1 *)(iVar2 + 7) = 0xff;
  sub_080C366C();
  return;
}


// ScriptOpAlt_432 @ 0x0813A384

void ScriptOpAlt_432(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_433 @ 0x0813A394

void ScriptOp_433(void)

{
  sub_080C5DB0();
  return;
}


// ScriptOpAlt_433 @ 0x0813A3A0

void ScriptOpAlt_433(void)

{
  return;
}


// sub_0813A3A4 @ 0x0813A3A4

void sub_0813A3A4(undefined4 arg0)

{
  if (DAT_030065f0 == 0) {
    sub_080C30AC(arg0);
  }
  return;
}


// ScriptOp_434 @ 0x0813A3C0

void ScriptOp_434(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  
  uVar5 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar5 * 2 + DAT_03006950);
  uVar6 = (uint)*(ushort *)((DAT_030065e0 - 0x61) * 2 + 0x8790cc8);
  DAT_0203db2c = uVar6;
  uVar4 = sub_080C3100();
  uVar3 = CONCAT22(uVar2,uVar1);
  if (uVar6 <= uVar4) {
    sub_0813A3A4(-uVar6);
    uVar3 = DAT_030068e4;
  }
  DAT_030068e4 = uVar3;
  return;
}


// ScriptOp_435 @ 0x0813A42C

void ScriptOp_435(void)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar3 = DAT_0203db40 + 1;
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = sVar3;
  if (sVar1 == 1) {
    DAT_0203db50 = *(ushort *)((DAT_0203db50 - 0x120) * 2 + 0x878fdb4);
  }
  else if (sVar1 == 2) {
    uVar2 = (DAT_0203db50 + DAT_030068d8) - 0x240;
    uVar4 = 0;
    if (2 < uVar2) {
      do {
        uVar4 = uVar4 + 2 & 0xffff;
      } while (*(ushort *)(uVar4 * 2 + 0x878fdcc) <= uVar2);
    }
    DAT_0203db28 = *(undefined2 *)((uVar4 + 1) * 2 + 0x878fdcc);
  }
  else if (sVar1 == 3) {
    DAT_0203db84 = 100;
  }
  else if (sVar1 == 4) {
    DAT_0203db84 = 10;
  }
  else if (sVar1 == 5) {
    sub_080C31B4(DAT_030037f0);
  }
  else if (sVar1 == 6) {
    sub_080D53FC();
  }
  else if (sVar1 == 7) {
    DAT_0203db3e = 0;
    DAT_0203db38 = 0;
    DAT_0203db3a = 0;
    DAT_0203db4a = 0;
    if (DAT_0203db6c != 0) {
      sub_080AB91C(DAT_03006968,1);
      DAT_0203db6c = 0;
    }
  }
  else if (sVar1 == 8) {
    sub_080C30AC((uint)DAT_0203db84 * DAT_030037f0);
  }
                    /* WARNING: Could not recover jumptable at 0x0813a566. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOpAlt_435 @ 0x0813A570

void ScriptOpAlt_435(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_436 @ 0x0813A580

void ScriptOp_436(void)

{
  return;
}


// ScriptOpAlt_436 @ 0x0813A584

void ScriptOpAlt_436(void)

{
  return;
}


// ScriptOp_437 @ 0x0813A588

void ScriptOp_437(void)

{
  return;
}


// ScriptOpAlt_437 @ 0x0813A58C

void ScriptOpAlt_437(void)

{
  return;
}


// ScriptOp_438 @ 0x0813A590

void ScriptOp_438(void)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  code *UNRECOVERED_JUMPTABLE;
  byte bVar12;
  
  uVar11 = 0;
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar4 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar3 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  if (sVar1 == 1) {
    uVar11 = sub_081354B0();
joined_r0x0813a62e:
    if ((uVar11 & 0xffff) != 1) goto LAB_0813a828;
  }
  else {
    if (sVar1 == 2) {
      uVar11 = sub_08135370();
      goto joined_r0x0813a62e;
    }
    if (sVar1 == 3) {
      uVar11 = sub_08135420();
      goto joined_r0x0813a62e;
    }
    if (sVar1 == 4) {
      uVar11 = sub_08135540();
      goto joined_r0x0813a62e;
    }
    if (sVar1 == 5) {
      uVar11 = sub_0813560C();
      goto joined_r0x0813a62e;
    }
    if (sVar1 == 6) {
      iVar10 = sub_080C0A00(0);
      if (iVar10 != 0) {
        uVar11 = sub_08130364(0,0x9d);
        iVar10 = sub_08130364(0,0x9e);
        iVar5 = sub_08130364(0,0xa5);
        iVar6 = sub_08130364(0,0xa0);
        iVar7 = sub_08130364(0,0xa1);
        iVar8 = sub_08130364(0,0xa2);
        uVar11 = (((((uVar11 & 0xffff) + iVar10 & 0xffff) + iVar5 & 0xffff) + iVar6 & 0xffff) +
                  iVar7 & 0xffff) + iVar8 & 0xffff;
      }
      iVar10 = sub_080C0A00(1);
      if (iVar10 != 0) {
        iVar10 = sub_08130364(1,0x9d);
        iVar5 = sub_08130364(1,0x9e);
        iVar6 = sub_08130364(1,0xa5);
        iVar7 = sub_08130364(1,0xa0);
        iVar8 = sub_08130364(1,0xa1);
        iVar9 = sub_08130364(1,0xa2);
        uVar11 = (((((uVar11 + iVar10 & 0xffff) + iVar5 & 0xffff) + iVar6 & 0xffff) + iVar7 & 0xffff
                  ) + iVar8 & 0xffff) + iVar9 & 0xffff;
      }
      iVar10 = sub_080C0A00(2);
      if (iVar10 != 0) {
        iVar10 = sub_08130364(2,0x9d);
        iVar5 = sub_08130364(2,0x9e);
        iVar6 = sub_08130364(2,0xa5);
        iVar7 = sub_08130364(2,0xa0);
        iVar8 = sub_08130364(2,0xa1);
        iVar9 = sub_08130364(2,0xa2);
        uVar11 = (((((uVar11 + iVar10 & 0xffff) + iVar5 & 0xffff) + iVar6 & 0xffff) + iVar7 & 0xffff
                  ) + iVar8 & 0xffff) + iVar9 & 0xffff;
      }
      if (uVar11 == 0) goto LAB_0813a828;
    }
    else if (sVar1 == 7) {
      iVar10 = sub_080C0A00(0);
      bVar12 = iVar10 == 1;
      if ((bool)bVar12) {
        DAT_03006898 = 0;
      }
      iVar10 = sub_080C0A00(1);
      if (iVar10 == 1) {
        DAT_03006898 = 1;
        bVar12 = bVar12 + 1;
      }
      iVar10 = sub_080C0A00(2);
      if (iVar10 == 1) {
        DAT_03006898 = 2;
        bVar12 = bVar12 + 1;
      }
      if (1 < bVar12) goto LAB_0813a828;
    }
    else if (sVar1 == 8) {
      uVar11 = sub_080C32FC((uint)DAT_0203db50);
      if ((uVar11 & 0xff) == 0) {
        sub_080C3328((uint)DAT_0203db50);
        sub_080C33AC((uint)*(ushort *)(((int)DAT_0300696c + (int)DAT_03006940) * 2 + 0x203db88));
        goto LAB_0813a828;
      }
    }
    else {
      if (sVar1 != 9) goto LAB_0813a828;
      sub_080C0A00(0);
      iVar10 = sub_080C0A00(1);
      uVar4 = (ushort)(iVar10 != 0);
      iVar10 = sub_080C0A00(2);
      if (iVar10 != 0) {
        uVar4 = 2;
      }
      uVar11 = sub_08130364((int)(short)uVar4,(uint)DAT_030065e0);
      if ((uVar11 & 0xffff) == 0) goto LAB_0813a828;
      sub_080C51D4(0x68);
    }
  }
  DAT_030068e4 = CONCAT22(uVar3,uVar2);
LAB_0813a828:
                    /* WARNING: Could not recover jumptable at 0x0813a82c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


