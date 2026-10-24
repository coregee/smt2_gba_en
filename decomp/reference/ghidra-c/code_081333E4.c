/* Ghidra decompilation of asm/code_081333E4.s (reference only; not compiled). */

// ScriptOp_336 @ 0x081333E4

void ScriptOp_336(void)

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
  uVar5 = sub_080C3100();
  if (uVar5 < uVar1) {
    DAT_030068e4 = CONCAT22(uVar3,uVar2);
  }
  return;
}


// ScriptOp_337 @ 0x08133434

void ScriptOp_337(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_080C3114((uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  return;
}


// ScriptOp_338 @ 0x0813345C

void ScriptOp_338(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_030065f8 = 1;
  DAT_0203db5a = 0x12;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_080AD0FC(*(undefined4 *)((uint)*(ushort *)(uVar1 * 2 + DAT_03006950) * 4 + 0x8790330),0xffff);
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_32C @ 0x081334B4

void ScriptOp_32C(void)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = DAT_0203db40 + 1;
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 2;
  DAT_0203db62 = *(ushort *)((uint)uVar2 * 2 + DAT_03006950);
  if (*(short *)(uVar1 * 2 + DAT_03006950) == 0) {
    sub_080C30AC((uint)DAT_0203db62);
  }
  else {
    sub_080C30AC(-(uint)DAT_0203db62);
  }
  return;
}


// ScriptOp_32D @ 0x08133500

void ScriptOp_32D(void)

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
  uVar5 = sub_080C2244();
  if ((uVar5 & 0xffff) < (0x80 >> (uVar1 & 0xff) & 0xffffU)) {
    DAT_030068e4 = CONCAT22(uVar3,uVar2);
  }
  return;
}


// ScriptOp_333 @ 0x0813355C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScriptOp_333(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = DAT_0203db40 + 2;
  DAT_0203dacc = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950));
  uVar1 = DAT_0203db40 + 3;
  DAT_0203db40 = DAT_0203db40 + 4;
  DAT_0203dad0 = CONCAT22(*(undefined2 *)((uint)uVar1 * 2 + DAT_03006950),
                          *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950));
  uVar5 = 0;
  do {
    *(undefined2 *)(uVar5 * 2 + 0x203bb74) = 0xffff;
    *(undefined4 *)(uVar5 * 4 + 0x203bd74) = 0xffffffff;
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 0x100);
  uVar6 = 0;
  uVar5 = 0;
  do {
    uVar2 = sub_080C32D4(uVar5);
    if ((uVar2 & 0xff) != 0) {
      *(short *)(uVar6 * 2 + 0x203bb74) = (short)uVar5;
      uVar3 = sub_080C4C7C(uVar5);
      *(undefined4 *)(uVar6 * 4 + 0x203bd74) = uVar3;
      uVar6 = uVar6 + 1 & 0xffff;
    }
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 0x100);
  DAT_03006688 = (undefined2)uVar6;
  DAT_0203db5a = 0x28;
  uVar5 = 0;
  do {
    *(undefined2 *)(uVar5 * 2 + 0x3006820) = *(undefined2 *)(uVar5 * 8 + 0x203d800);
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 0xf);
  DAT_03006940 = 0;
  DAT_0300696c = 0;
  DAT_030065e4 = 0;
  Shop_InitItemList(0,0);
  DAT_030068a4 = sub_080D3400(1,0,(uint)_DAT_0203bb74);
  sub_080AD0FC(0x878fd58,0xffff);
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_334 @ 0x081336A4

void ScriptOp_334(void)

{
  short sVar1;
  
  DAT_03006914 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  sVar1 = *(short *)((uint)DAT_03006914 * 2 + 0x8790130);
  if (sVar1 == 1) {
    DAT_030068e4 = 0x807ded2;
  }
  else if (sVar1 == 2) {
    DAT_030068e4 = 0x807e088;
  }
  else if ((sVar1 == 3) || (sVar1 != 4)) {
    DAT_030068e4 = 0x807d984;
  }
  else {
    DAT_030068e4 = 0x807d988;
  }
  return;
}


// sub_08133724 @ 0x08133724

void sub_08133724(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((arg3 & 0xffff) != 0) {
    do {
      *(undefined2 *)(DAT_0300669c * 8 + 0x203da00) = *(undefined2 *)(uVar1 * 2 + 0x203db08);
      *(short *)((DAT_0300669c * 4 + 1) * 2 + 0x203da00) = (short)arg0;
      *(undefined2 *)((DAT_0300669c * 4 + 2) * 2 + 0x203da00) = (undefined2)arg1;
      *(undefined2 *)((DAT_0300669c * 4 + 3) * 2 + 0x203da00) = (undefined2)arg2;
      DAT_0300669c = DAT_0300669c + 1;
      arg0._0_2_ = (short)arg0 + 0xd;
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < (arg3 & 0xffff));
  }
  return;
}


// sub_081337B4 @ 0x081337B4

void sub_081337B4(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  if ((arg3 & 0xffff) != 0) {
    do {
      uVar1 = DAT_0203db3e;
      uVar4 = (uint)DAT_0203db3e;
      uVar2 = uVar4 & 0x3fff;
      uVar3 = uVar2 << 2 | 1;
      *(undefined2 *)(uVar2 * 8 + 0x203d800) = *(undefined2 *)(uVar5 * 2 + 0x203db08);
      uVar2 = uVar3 + 1;
      *(short *)(uVar3 * 2 + 0x203d800) = (short)arg0;
      *(undefined2 *)((uVar2 & 0xffff) * 2 + 0x203d800) = (undefined2)arg1;
      *(undefined2 *)((uVar2 * 0x10000 + 0x10000 >> 0xf) + 0x203d800) = (undefined2)arg2;
      if (uVar4 < 0x3f) {
        DAT_0203db3e = uVar1 + 1;
      }
      arg0._0_2_ = (short)arg0 + 0xd;
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < (arg3 & 0xffff));
  }
  return;
}


// sub_08133854 @ 0x08133854

void sub_08133854(uint arg0,undefined4 arg1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  undefined4 arg2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = arg0 & 0xffff;
  uVar8 = 0;
  uVar9 = 0;
  DAT_0300669c = 0;
  uVar6 = 0;
  do {
    *(undefined2 *)((short)uVar6 * 2 + 0x203da00) = 0;
    uVar5 = (int)(short)uVar6 + 1;
    uVar6 = uVar5 & 0xffff;
  } while ((int)(uVar5 * 0x10000) >> 0x10 < 100);
  DAT_030069d0 = 0;
  sVar1 = (&DAT_030046ce)[uVar2 * 0x40];
  uVar6 = uVar2;
  do {
    if (sVar1 == 0) {
      uVar8 = uVar8 + 1 & 0xffff;
      if (2 < uVar8) goto LAB_081339d0;
    }
    else {
      if ((short)arg1 == 1) {
        if (((&DAT_030046d0)[uVar6 * 0x40] & 0xa000) != 0) {
          uVar8 = uVar8 + 1 & 0xffff;
          if (uVar8 < 3) goto LAB_081339b0;
LAB_081339d0:
                    /* WARNING: Could not recover jumptable at 0x081339de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE)();
          return;
        }
      }
      else {
        DAT_030069d0 = DAT_030069d0 + 1;
      }
      puVar7 = (ushort *)(uVar9 * 2 + 0x30069d8);
      *puVar7 = (ushort)uVar6;
      if (((&DAT_030046d0)[uVar6 * 0x40] & 0xa000) == 0) {
        arg2 = 0;
      }
      else {
        arg2 = 4;
        *puVar7 = (ushort)uVar6 | 0xf0;
      }
      uVar5 = 0;
      do {
        *(undefined2 *)((short)uVar5 * 2 + 0x203db08) = 0;
        uVar3 = (int)(short)uVar5 + 1;
        uVar5 = uVar3 & 0xffff;
      } while ((int)(uVar3 * 0x10000) >> 0x10 < 0x10);
      Combatant_DecodeName(uVar6 * 0x80 + 0x30046c0,0x203db08);
      DAT_0203db18 = 0;
      uVar6 = 0xe;
      do {
        if (*(short *)((short)uVar6 * 2 + 0x203db08) != 0) {
          psVar4 = (short *)(((short)uVar6 + 1) * 2 + 0x203db08);
          sVar1 = *psVar4;
          if ((sVar1 == 0) || (sVar1 == 0x318)) {
            *psVar4 = 0x318;
            break;
          }
        }
        uVar5 = uVar6 * 0x10000 - 0x10000;
        uVar6 = uVar5 >> 0x10;
      } while (-1 < (int)uVar5);
      sub_081337B4(0x27,(uint)*(ushort *)(uVar9 * 2 + 0x879038a),arg2,
                   uVar6 * 0x10000 + 0x10000 >> 0x10);
      uVar8 = uVar8 + 1 & 0xffff;
      uVar9 = uVar9 + 1 & 0xffff;
      if (3 < uVar8) goto LAB_081339d0;
    }
LAB_081339b0:
    uVar6 = uVar8 + uVar2;
    sVar1 = (&DAT_030046ce)[uVar6 * 0x40];
  } while( true );
}


// ScriptOp_33A @ 0x081339EC

void ScriptOp_33A(void)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar3 = DAT_0203db40 + 1;
  uVar1 = (uint)DAT_0203db40;
  uVar2 = DAT_0203db40 + 2;
  DAT_0203db40 = DAT_0203db40 + 3;
  DAT_0203dac8 = CONCAT22(*(undefined2 *)((uint)uVar2 * 2 + DAT_03006950),
                          *(undefined2 *)((uint)uVar3 * 2 + DAT_03006950));
  sub_08133854(0,(uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  DAT_0203db5a = 0x1f;
  sub_080AD0FC(0x878fcd0,0xffff);
  DAT_0203db6e = 1;
  return;
}


// sub_08133A60 @ 0x08133A60

undefined4 sub_08133A60(uint arg0)

{
  uint uVar1;
  dword dVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((arg0 & 0xffff) < 0xd0) {
    uVar1 = sub_080D2268(arg0 & 0xffff);
    dVar2 = uVar1 & 0xffff;
  }
  else {
    dVar2 = 0xffff;
  }
                    /* WARNING: Could not recover jumptable at 0x08133a78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(dVar2);
  return uVar3;
}


// sub_08133A80 @ 0x08133A80

void sub_08133A80(uint arg0,undefined4 arg1)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  
  sVar5 = 0x27;
  uVar2 = (arg0 & 0x7ff) << 5;
  uVar4 = 0;
  uVar1 = *(undefined2 *)((arg0 & 0xffff) * 2 + 0x879038a);
  do {
    uVar3 = uVar2 + 1 & 0xffff;
    *(undefined2 *)(uVar2 * 2 + 0x203da00) = *(undefined2 *)(uVar4 * 2 + 0x203db08);
    uVar2 = uVar3 + 1 & 0xffff;
    *(short *)(uVar3 * 2 + 0x203da00) = sVar5;
    uVar3 = uVar2 + 1 & 0xffff;
    *(undefined2 *)(uVar2 * 2 + 0x203da00) = uVar1;
    uVar2 = uVar3 + 1 & 0xffff;
    *(undefined2 *)(uVar3 * 2 + 0x203da00) = (undefined2)arg1;
    sVar5 = sVar5 + 0xd;
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 8);
  return;
}


// Shop_InitItemList @ 0x08133B18

void Shop_InitItemList(uint arg0,undefined4 arg1)

{
  ushort uVar1;
  uint arg0_00;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  uint arg0_01;
  uint uVar7;
  int iVar8;
  undefined4 arg1_00;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = arg0 & 0xffff;
  uVar3 = sub_080C3100();
  Font_ResetGlyphSpriteCache(0x180);
  if ((short)arg1 == 0) {
    uVar7 = 0;
    do {
      *(undefined2 *)(uVar7 * 8 + 0x203d800) = *(undefined2 *)(uVar7 * 2 + 0x3006820);
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 0xf);
  }
  else {
    DAT_0203d800 = 0xbd9;
    DAT_0203d808 = 0xc80;
    DAT_0203d810 = 0xcd3;
    DAT_0203d818 = 0x149;
    DAT_0203d820 = 0x17b;
    DAT_0203d828 = 0x17d;
    DAT_0203d830 = 0x19f;
    DAT_0203d838 = 0x1ba;
    DAT_0203d840 = 0x149;
    DAT_0203d848 = 0xaa0;
    DAT_0203d850 = 0x9f6;
    DAT_0203d858 = 0xb67;
    DAT_0203d860 = 0x70;
    sub_08130578((uint)*(ushort *)((uVar2 + (int)DAT_0300696c) * 2 + 0x203bb74));
  }
  arg1_00 = 0;
  DAT_0300669c = 0x18;
  DAT_0300699c = 1;
  if (uVar2 == 0) {
    DAT_03006848 = 0;
    if (DAT_03006688 < 4) {
      DAT_03006680 = 0;
      goto LAB_08133c50;
    }
  }
  else {
    if (uVar2 == (int)DAT_03006688 - 3U) {
      DAT_03006848 = 1;
      DAT_03006680 = 0;
      goto LAB_08133c50;
    }
    DAT_03006848 = 1;
  }
  DAT_03006680 = 1;
LAB_08133c50:
  uVar7 = 0x20;
  do {
    *(undefined2 *)(uVar7 * 2 + 0x203da00) = 0;
    uVar7 = uVar7 + 1 & 0xffff;
  } while (uVar7 < 100);
  if (uVar2 < uVar2 + 3) {
    uVar5 = *(uint *)(uVar2 * 4 + 0x203bd74);
    uVar1 = *(ushort *)(uVar2 * 2 + 0x203bb74);
    uVar7 = uVar2;
    while (arg0_00 = (uint)uVar1, arg0_00 != 0xffff) {
      if ((DAT_0203db5a == 0x22) || (DAT_0203db5a == 0x25)) {
        if (uVar3 < uVar5) {
          arg1_00 = 4;
          iVar8 = uVar7 << 2;
          goto LAB_08133d30;
        }
        uVar5 = sub_080C32D4(arg0_00);
        iVar4 = sub_08131AB0(0xff,arg0_00);
        arg1_00 = 4;
        iVar8 = uVar7 << 2;
        if (0x62 < ((uVar5 & 0xff) + iVar4 & 0xffff)) goto LAB_08133d30;
        arg1_00 = 0;
        if (arg0_00 < 0xd0) {
          iVar4 = sub_080CDB74((int)DAT_03006898,arg0_00 & 0xff);
          arg1_00 = 4;
          if (iVar4 != 0) {
            arg1_00 = 0;
          }
          goto LAB_08133d30;
        }
LAB_08133d34:
        iVar4 = Action_GetRecord(arg0_00);
        puVar6 = (undefined2 *)(iVar4 + 0xc);
      }
      else {
        if ((DAT_0203db5a == 0x28) || (iVar8 = uVar7 << 2, DAT_0203db5a == 0x2a)) {
          iVar8 = uVar7 * 4;
          arg1_00 = 0;
          if (999999 < uVar3 + *(int *)(iVar8 + 0x203bd74)) {
            arg1_00 = 4;
          }
        }
LAB_08133d30:
        if (0xcf < arg0_00) goto LAB_08133d34;
        if (arg0_00 < 0x80) {
          iVar4 = sub_080BF32C(arg0_00);
        }
        else {
          iVar4 = Equipment_GetRecord36_MidRange(arg0_00);
        }
        puVar6 = (undefined2 *)(iVar4 + 0x14);
      }
      uVar5 = 0;
      do {
        *(undefined2 *)(uVar5 * 2 + 0x203db08) = *puVar6;
        puVar6 = puVar6 + 1;
        uVar5 = uVar5 + 1 & 0xffff;
      } while (uVar5 < 8);
      arg0_01 = uVar7 - uVar2 & 0xffff;
      sub_08133A80(arg0_01,arg1_00);
      *(undefined2 *)(arg0_01 * 0x10 + 0x3006620) = 1;
      (&DAT_03006624)[arg0_01 * 4] = *(undefined4 *)(iVar8 + 0x203bd74);
      (&DAT_03006628)[arg0_01 * 8] = 0x80;
      (&DAT_0300662a)[arg0_01 * 8] = *(undefined2 *)(arg0_01 * 2 + 0x878fc64);
      (&DAT_0300662c)[arg0_01 * 8] = (short)arg1_00;
      uVar5 = sub_08133A60(arg0_00);
      if ((uVar5 & 0xffff) == 0xffff) {
        *(undefined2 *)(arg0_01 * 8 + 0x3006920) = 0;
      }
      else {
        (&DAT_03006922)[arg0_01 * 4] = (short)uVar5;
        *(undefined2 *)(arg0_01 * 8 + 0x3006920) = 1;
        (&DAT_03006924)[arg0_01 * 4] = 0;
      }
      if (((DAT_0203db5a == 0x22) || (DAT_0203db5a == 0x25)) &&
         (uVar5 = sub_08131AB0((int)DAT_03006898,arg0_00), (uVar5 & 0xffff) != 0)) {
        (&DAT_03006924)[arg0_01 * 4] = 1;
      }
      uVar7 = uVar7 + 1 & 0xffff;
      if (uVar2 + 3 <= uVar7) break;
      uVar5 = *(uint *)(uVar7 * 4 + 0x203bd74);
      uVar1 = *(ushort *)(uVar7 * 2 + 0x203bb74);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08133e54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08133E70 @ 0x08133E70

void sub_08133E70(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  if ((arg3 & 0xffff) != 0) {
    do {
      uVar1 = DAT_0203db3e & 0x3fff;
      uVar2 = uVar1 << 2 | 1;
      *(undefined2 *)(uVar1 * 8 + 0x203d800) = *(undefined2 *)(uVar3 * 2 + 0x203db08);
      uVar1 = uVar2 + 1;
      *(short *)(uVar2 * 2 + 0x203d800) = (short)arg0;
      *(undefined2 *)((uVar1 & 0xffff) * 2 + 0x203d800) = (undefined2)arg1;
      *(undefined2 *)((uVar1 * 0x10000 + 0x10000 >> 0xf) + 0x203d800) = (undefined2)arg2;
      uVar1 = DAT_0203db3e + 1;
      DAT_0203db3e = (ushort)uVar1;
      if (0x3f < (uVar1 & 0xffff)) {
        DAT_0203db3e = 0x3f;
      }
      arg0._0_2_ = (short)arg0 + 0xd;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < (arg3 & 0xffff));
  }
  return;
}


// sub_08133F14 @ 0x08133F14

void sub_08133F14(uint arg0)

{
  ushort uVar1;
  uint arg0_00;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined2 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = arg0 & 0xffff;
  uVar1 = DAT_03006844 & 0xf;
  uVar5 = DAT_03006844 & 0xf;
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  DAT_03006678 = 0;
  if (uVar5 == 1) {
    sub_0812F1E4();
  }
  if (uVar2 == 0) {
    DAT_03006848 = 0;
    DAT_03006680 = 1;
  }
  else if (uVar2 == uVar5 + 8) {
    DAT_03006848 = 1;
    DAT_03006680 = 0;
  }
  else {
    DAT_03006848 = 1;
    DAT_03006680 = 1;
  }
  iVar3 = 3;
  if (uVar1 == 0) {
    iVar3 = 4;
  }
  if (uVar2 < uVar2 + iVar3) {
    uVar1 = *(ushort *)(uVar2 * 2 + 0x203db88);
    uVar8 = uVar2;
    while (arg0_00 = (uint)uVar1, arg0_00 != 0xffff) {
      iVar4 = Action_GetRecord(arg0_00);
      puVar7 = (undefined2 *)(iVar4 + 0xc);
      uVar6 = 0;
      do {
        *(undefined2 *)(uVar6 * 2 + 0x203db08) = 0;
        uVar6 = uVar6 + 1 & 0xffff;
      } while (uVar6 < 0x10);
      uVar6 = 0;
      do {
        *(undefined2 *)(uVar6 * 2 + 0x203db08) = *puVar7;
        puVar7 = puVar7 + 1;
        uVar6 = uVar6 + 1 & 0xffff;
      } while (uVar6 < 8);
      uVar1 = *(ushort *)(((uVar8 - uVar2) + uVar5) * 2 + 0x8790390);
      sub_08133E70(0x27,(uint)uVar1,0,8);
      uVar6 = DAT_0203db3e & 0x3fff;
      uVar10 = uVar6 * 4 | 1;
      *(undefined2 *)(uVar6 * 8 + 0x203d800) = 0x115;
      uVar6 = uVar10 + 1 & 0xffff;
      *(undefined2 *)(uVar10 * 2 + 0x203d800) = 0x9a;
      *(ushort *)(uVar6 * 2 + 0x203d800) = uVar1;
      *(undefined2 *)((uVar6 + 1 & 0xffff) * 2 + 0x203d800) = 0;
      uVar6 = DAT_0203db3e + 1;
      DAT_0203db3e = (ushort)uVar6;
      if (0x3f < (uVar6 & 0xffff)) {
        DAT_0203db3e = 0x3f;
      }
      uVar6 = sub_080C32D4((uint)*(ushort *)(uVar8 * 2 + 0x203db88));
      uVar6 = uVar6 & 0xff;
      if (uVar6 < 10) {
        uVar10 = DAT_0203db3e & 0x3fff;
        uVar9 = uVar10 * 4 | 1;
        *(undefined2 *)(uVar10 * 8 + 0x203d800) = *(undefined2 *)(uVar6 * 2 + 0x878f9b8);
        uVar6 = uVar9 + 1 & 0xffff;
        *(undefined2 *)(uVar9 * 2 + 0x203d800) = 0xb4;
        *(ushort *)(uVar6 * 2 + 0x203d800) = uVar1;
        *(undefined2 *)((uVar6 + 1 & 0xffff) * 2 + 0x203d800) = 0;
        uVar6 = DAT_0203db3e + 1;
        DAT_0203db3e = (ushort)uVar6;
        if (0x3f < (uVar6 & 0xffff)) {
          DAT_0203db3e = 0x3f;
        }
      }
      else {
        uVar9 = (uint)DAT_0203db3e;
        uVar10 = uVar9 & 0x3fff;
        uVar11 = uVar10 * 4 | 1;
        iVar4 = __udivsi3(uVar6,10);
        *(undefined2 *)(uVar10 * 8 + 0x203d800) = *(undefined2 *)(iVar4 * 2 + 0x878f9b8);
        uVar10 = uVar11 + 1 & 0xffff;
        *(undefined2 *)(uVar11 * 2 + 0x203d800) = 0xa7;
        *(ushort *)(uVar10 * 2 + 0x203d800) = uVar1;
        *(undefined2 *)((uVar10 + 1 & 0xffff) * 2 + 0x203d800) = 0;
        uVar9 = uVar9 + 1;
        DAT_0203db3e = (ushort)uVar9;
        if (0x3f < (uVar9 & 0xffff)) {
          DAT_0203db3e = 0x3f;
        }
        uVar9 = (uint)DAT_0203db3e;
        uVar10 = uVar9 & 0x3fff;
        uVar11 = uVar10 * 4 | 1;
        iVar4 = __umodsi3(uVar6,10);
        *(undefined2 *)(uVar10 * 8 + 0x203d800) = *(undefined2 *)(iVar4 * 2 + 0x878f9b8);
        uVar6 = uVar11 + 1 & 0xffff;
        *(undefined2 *)(uVar11 * 2 + 0x203d800) = 0xb4;
        *(ushort *)(uVar6 * 2 + 0x203d800) = uVar1;
        *(undefined2 *)((uVar6 + 1 & 0xffff) * 2 + 0x203d800) = 0;
        uVar9 = uVar9 + 1;
        DAT_0203db3e = (ushort)uVar9;
        if (0x3f < (uVar9 & 0xffff)) {
          DAT_0203db3e = 0x3f;
        }
      }
      if (DAT_030068d8 == arg0_00) {
        DAT_03006678 = 1;
        DAT_0300667a = *(undefined2 *)(((uVar8 - uVar2) + uVar5) * 2 + 0x8790390);
      }
      uVar8 = uVar8 + 1 & 0xffff;
      if (uVar2 + iVar3 <= uVar8) break;
      uVar1 = *(ushort *)(uVar8 * 2 + 0x203db88);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08134234. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08134250 @ 0x08134250

void sub_08134250(uint arg0)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  undefined4 arg2;
  
  uVar1 = arg0 & 0xffff;
  DAT_0300669c = 0;
  DAT_0300699c = 1;
  if (uVar1 == 0) {
    DAT_03006848 = 0;
  }
  else {
    if (uVar1 == 9) {
      DAT_03006848 = 1;
      DAT_03006680 = 0;
      goto LAB_081342a8;
    }
    DAT_03006848 = 1;
  }
  DAT_03006680 = 1;
LAB_081342a8:
  uVar5 = 0;
  do {
    *(undefined2 *)(uVar5 * 2 + 0x203da00) = 0;
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 100);
  uVar5 = uVar1;
  if (uVar1 < uVar1 + 3) {
    do {
      uVar3 = (uint)*(ushort *)(uVar5 * 2 + 0x203bb74);
      if (uVar3 == 0xffff) {
        return;
      }
      arg2 = 4;
      if (*(int *)(uVar5 * 4 + 0x203bd74) != 0) {
        arg2 = 0;
      }
      iVar2 = Action_GetRecord(uVar3);
      puVar4 = (undefined2 *)(iVar2 + 0xc);
      uVar3 = 0;
      iVar2 = uVar5 - uVar1;
      do {
        *(undefined2 *)(uVar3 * 2 + 0x203db08) = 0;
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < 0x10);
      uVar3 = 0;
      do {
        *(undefined2 *)(uVar3 * 2 + 0x203db08) = *puVar4;
        puVar4 = puVar4 + 1;
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < 8);
      sub_08133724(0x27,(uint)*(ushort *)(iVar2 * 2 + 0x879038a),arg2,8);
      *(undefined2 *)(iVar2 * 0x10 + 0x3006620) = 1;
      *(undefined4 *)(iVar2 * 0x10 + 0x3006624) = *(undefined4 *)(uVar5 * 4 + 0x203bd74);
      (&DAT_03006628)[iVar2 * 8] = 0x80;
      (&DAT_0300662a)[iVar2 * 8] = *(undefined2 *)(iVar2 * 2 + 0x878fc64);
      (&DAT_0300662c)[iVar2 * 8] = (short)arg2;
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < uVar1 + 3);
  }
  return;
}


// ScriptOp_33B @ 0x081343AC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScriptOp_33B(void)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort uVar3;
  ushort *puVar4;
  uint uVar5;
  
  DAT_0203dac8 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950));
  DAT_0203dacc = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 3) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 2) * 2 + DAT_03006950));
  uVar3 = DAT_0203db40 + 6;
  DAT_0203dad0 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 5) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 4) * 2 + DAT_03006950));
  uVar1 = DAT_0203db40 + 7;
  DAT_0203db40 = DAT_0203db40 + 8;
  DAT_0203dad4 = CONCAT22(*(undefined2 *)((uint)uVar1 * 2 + DAT_03006950),
                          *(undefined2 *)((uint)uVar3 * 2 + DAT_03006950));
  DAT_0203dad8 = 0;
  uVar5 = 0;
  do {
    *(undefined2 *)(uVar5 * 2 + 0x203bb74) = 0xffff;
    *(undefined4 *)(uVar5 * 4 + 0x203bd74) = 0xffffffff;
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 0x100);
  DAT_03006688 = *(short *)((uint)DAT_03006914 * 0x40 + 0x878efb8) + 1;
  uVar5 = 0;
  if (0 < DAT_03006688) {
    do {
      puVar4 = (ushort *)(uVar5 * 2 + 0x203bb74);
      *puVar4 = *(ushort *)((uVar5 + 1) * 2 + (uint)DAT_03006914 * 0x40 + 0x878efb8);
      uVar2 = sub_080C4C60((uint)*puVar4);
      *(undefined4 *)(uVar5 * 4 + 0x203bd74) = uVar2;
      uVar5 = uVar5 + 1 & 0xffff;
    } while ((int)uVar5 < (int)DAT_03006688);
  }
  DAT_0203db5a = 0x22;
  uVar5 = 0;
  do {
    *(undefined2 *)(uVar5 * 2 + 0x3006820) = *(undefined2 *)(uVar5 * 8 + 0x203d800);
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 0xf);
  DAT_03006940 = 0;
  DAT_0300696c = 0;
  DAT_030065e4 = 0;
  Shop_InitItemList(0,0);
  DAT_030068a4 = sub_080D3400(1,(uint)DAT_03006898,(uint)_DAT_0203bb74);
  sub_080AD0FC(0x878fd58,0xffff);
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_33C @ 0x08134568

void ScriptOp_33C(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  ushort uVar4;
  
  uVar4 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  if (((short)DAT_030069a8 < 0xd0) &&
     (iVar3 = sub_080CDB74((int)DAT_03006898,DAT_030069a8 & 0xff), iVar3 == 0)) {
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// ScriptOp_33D @ 0x081345CC

void ScriptOp_33D(void)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = 0;
  do {
    *(undefined2 *)(uVar4 * 2 + 0x3006820) = *(undefined2 *)(uVar4 * 8 + 0x203d800);
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 0xf);
  DAT_030065fc = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  bVar5 = DAT_030065fc == 0xff;
  if (bVar5) {
    DAT_030065fc = 1;
  }
  DAT_0203db5a = 0x25;
  if (bVar5) {
    DAT_0203db5a = 0x2a;
  }
  DAT_0203db40 = DAT_0203db40 + 1;
  Shop_InitItemList((uint)DAT_03006940,(uint)DAT_030065e4);
  DAT_0203dac8 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950));
  uVar3 = DAT_0203db40 + 4;
  DAT_0203dacc = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 3) * 2 + DAT_03006950),
                          *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 2) * 2 + DAT_03006950));
  uVar1 = DAT_0203db40 + 5;
  DAT_0203db40 = DAT_0203db40 + 6;
  DAT_0203dad0 = CONCAT22(*(undefined2 *)((uint)uVar1 * 2 + DAT_03006950),
                          *(undefined2 *)((uint)uVar3 * 2 + DAT_03006950));
  *(undefined2 *)(DAT_0300669c * 8 + 0x203da00) = 0x3e;
  *(undefined2 *)((DAT_0300669c * 4 + 1) * 2 + 0x203da00) = 0xbc;
  *(undefined2 *)((DAT_0300669c * 4 + 2) * 2 + 0x203da00) =
       *(undefined2 *)(DAT_0300696c * 2 + 0x879038a);
  *(undefined2 *)((DAT_0300669c * 4 + 3) * 2 + 0x203da00) = 0;
  DAT_0300669c = 0x19;
  DAT_03006650 = 1;
  uVar2 = __modsi3((int)DAT_030065fc,10);
  DAT_03006654 = (int)(short)uVar2;
  DAT_03006658 = 0x98;
  DAT_0300665a = *(undefined2 *)(DAT_0300696c * 2 + 0x878fc64);
  DAT_0300665c = 0;
  DAT_03006660 = 1;
  uVar2 = __divsi3((int)DAT_030065fc,10);
  DAT_03006664 = (int)(short)uVar2;
  DAT_03006668 = 0x90;
  DAT_0300666a = *(undefined2 *)(DAT_0300696c * 2 + 0x878fc64);
  DAT_0300666c = 0;
  DAT_030068a4 = sub_080D3400(2,(uint)DAT_03006898,
                              (uint)*(ushort *)
                                     (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x203bb74
                                     ));
  DAT_03006694 = sub_080C4C60((uint)*(ushort *)
                                     (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x203bb74
                                     ));
  DAT_0203db5a = 0x25;
  if (bVar5) {
    DAT_0203db5a = 0x2a;
    DAT_03006694 = sub_080C4C7C((uint)*(ushort *)
                                       (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 +
                                       0x203bb74));
  }
  DAT_0203db2c = DAT_03006694 * DAT_030065fc;
  if (999999 < DAT_0203db2c) {
    DAT_0203db2c = 999999;
  }
  sub_080AD0FC(0x878ff8c,0xffff);
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_33E @ 0x08134854

void ScriptOp_33E(void)

{
  uint uVar1;
  int iVar2;
  ushort uVar3;
  undefined4 uVar4;
  
  uVar3 = DAT_0203db40 + 1;
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar4 = CONCAT22(*(undefined2 *)((uint)uVar3 * 2 + DAT_03006950),
                   *(undefined2 *)(uVar1 * 2 + DAT_03006950));
  if (0xcf < DAT_030069a8) {
    DAT_030068e4 = uVar4;
  }
  iVar2 = sub_080CDB74((int)DAT_03006898,(uint)(byte)DAT_030069a8);
  if (iVar2 == 0) {
    DAT_030068e4 = uVar4;
  }
  return;
}


// ScriptOp_33F @ 0x081348B8

void ScriptOp_33F(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (0 < DAT_030065fc) {
    do {
      sub_080C3328((uint)DAT_0203db50);
      uVar1 = uVar1 + 1 & 0xffff;
    } while ((int)uVar1 < (int)DAT_030065fc);
  }
  sub_080CDFBC((uint)DAT_03006898,(uint)DAT_0203db50);
  return;
}


// ScriptOp_340 @ 0x081348FC

void ScriptOp_340(void)

{
  return;
}


// ScriptOp_Choice @ 0x08134900

void ScriptOp_Choice(void)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  ushort uVar6;
  int iVar7;
  
  DAT_030065e0 = 0xffff;
  uVar3 = DAT_0203db40 + 1;
  uVar4 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar6 = uVar4 >> 8;
  DAT_03006844 = uVar4 & 0xff;
  if (3 < DAT_03006844) {
    DAT_03006844 = 0;
  }
  DAT_0203db40 = uVar3;
  if ((DAT_03006844 == 1) || (DAT_03006844 == 3)) {
    sub_0812F198();
  }
  uVar5 = 0;
  do {
    *(undefined2 *)((short)uVar5 * 2 + 0x203db88) = 0xffff;
    uVar2 = (int)(short)uVar5 + 1;
    uVar5 = uVar2 & 0xffff;
  } while ((int)(uVar2 * 0x10000) >> 0x10 < 0x14);
  uVar5 = 0;
  DAT_03006604 = uVar6;
  if (uVar6 != 0xffff) {
    do {
      iVar1 = DAT_03006950;
      iVar7 = (int)(short)uVar5;
      uVar6 = DAT_0203db40 + 1;
      *(undefined2 *)(iVar7 * 2 + 0x203db88) =
           *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
      uVar4 = DAT_0203db40 + 2;
      DAT_0203db40 = DAT_0203db40 + 3;
      *(uint *)(iVar7 * 4 + 0x203dac8) =
           CONCAT22(*(undefined2 *)((uint)uVar4 * 2 + iVar1),
                    *(undefined2 *)((uint)uVar6 * 2 + iVar1));
      uVar5 = iVar7 + 1U & 0xffff;
    } while ((int)((iVar7 + 1U) * 0x10000) >> 0x10 < (short)DAT_03006604 + 1);
  }
  DAT_03006940 = 0;
  DAT_0300696c = 0;
  sub_0812F2B4((uint)DAT_03006844);
  DAT_0203db6e = 1;
  sub_080AD0FC(0x878fc80,0xffff);
  DAT_0203db5a = 0xd;
  return;
}


// ScriptOp_352 @ 0x08134A48

void ScriptOp_352(void)

{
  uint arg0;
  
  arg0 = (uint)*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  if (arg0 < 100) {
    DAT_0203db40 = DAT_0203db40 + 1;
    sub_080C5170(arg0);
  }
  else {
    DAT_0203db40 = DAT_0203db40 + 1;
    sub_080C51D4(arg0);
  }
  return;
}


// ScriptOp_353 @ 0x08134A78

void ScriptOp_353(void)

{
  uint arg1;
  
  arg1 = (uint)*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950) * 0x100;
  if (0x7fff < arg1) {
    arg1 = arg1 | 0xffff0000;
  }
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_080C06EC(0,arg1);
  sub_080C06EC(1,arg1);
  return;
}


// ScriptOp_354 @ 0x08134AC0

void ScriptOp_354(void)

{
  return;
}


// ScriptOp_355 @ 0x08134AC4

void ScriptOp_355(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = sub_080C06BC(0);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
    uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
    DAT_0203db40 = DAT_0203db40 + 1;
  }
  else {
    if (iVar3 != 2) {
      DAT_0203db40 = DAT_0203db40 + 4;
      return;
    }
    iVar3 = (uint)DAT_0203db40 * 2 + DAT_03006950;
    uVar1 = *(undefined2 *)(iVar3 + 4);
    uVar2 = *(undefined2 *)(iVar3 + 6);
  }
  DAT_030068e4 = CONCAT22(uVar2,uVar1);
  return;
}


// ScriptOp_356 @ 0x08134B34

void ScriptOp_356(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 1;
  uVar3 = sub_080C0794(0);
  uVar4 = DAT_0203db40 + 1;
  uVar2 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 2;
  if (((uint)(uVar1 >> 8) <= uVar3 >> 8) && (uVar3 >> 8 < (uVar1 & 0xff) + 1)) {
    DAT_030068e4 = CONCAT22(*(undefined2 *)((uint)uVar4 * 2 + DAT_03006950),
                            *(undefined2 *)(uVar2 * 2 + DAT_03006950));
  }
  return;
}


// ScriptOp_357 @ 0x08134BA8

void ScriptOp_357(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  undefined4 uVar5;
  
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar4 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar3 = *(undefined2 *)((uint)uVar4 * 2 + DAT_03006950);
  uVar5 = sub_080C0F8C(0);
  if ((int)(short)uVar5 <= (int)(uint)uVar1) {
    DAT_030068e4 = CONCAT22(uVar3,uVar2);
  }
  return;
}


// ScriptOp_358 @ 0x08134C00

void ScriptOp_358(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_0203db5c = *(undefined2 *)((uint)uVar1 * 2 + DAT_03006950);
  DAT_0203db5a = 0xf;
  DAT_0203db6e = 1;
  return;
}


// sub_08134C3C @ 0x08134C3C

undefined4 sub_08134C3C(void)

{
  return 0;
}


// ScriptOp_359 @ 0x08134C40

void ScriptOp_359(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint arg0;
  int iVar5;
  
  iVar5 = 0;
  uVar1 = *(ushort *)((*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950) - 1) * 2 + 0x203db28);
  DAT_0203db40 = DAT_0203db40 + 1;
  iVar2 = sub_080C104C();
  for (arg0 = 4; arg0 < iVar2 + 4U; arg0 = arg0 + 1) {
    iVar3 = sub_080C09B0(arg0);
    if ((iVar3 != 0) && (uVar4 = sub_080C07E0(arg0), (int)(short)uVar4 == (uint)uVar1)) {
      iVar5 = iVar5 + 1;
    }
  }
  if (iVar5 == 0) {
    DAT_030068e4 = CONCAT22(*(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950),
                            *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950));
    DAT_0203db40 = DAT_0203db40 + 1;
  }
  else {
    DAT_0203db40 = DAT_0203db40 + 2;
  }
  return;
}


// ScriptOp_35A @ 0x08134CE4

void ScriptOp_35A(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  
  uVar5 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar5 * 2 + DAT_03006950);
  uVar3 = sub_080C104C();
  uVar6 = 0;
  if (uVar3 != 0) {
    do {
      iVar4 = sub_080C09B0(uVar6 + 4);
      if (iVar4 == 0) {
        return;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar3);
  }
  DAT_030068e4 = CONCAT22(uVar2,uVar1);
  return;
}


// ScriptOp_35B @ 0x08134D3C

void ScriptOp_35B(void)

{
  return;
}


// ScriptOp_35C @ 0x08134D40

void ScriptOp_35C(void)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = sub_080C104C();
  uVar3 = DAT_0203db40 + 1;
  uVar4 = (uint)*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar5 = (uint)*(ushort *)((uint)uVar3 * 2 + DAT_03006950);
  if (uVar4 == 0xff) {
    uVar4 = 0;
    if (0 < iVar1 + 4) {
      do {
        iVar2 = sub_080C09B0(uVar4);
        if (((iVar2 != 0) && (iVar2 = sub_080C0830(), iVar2 == 0)) &&
           (iVar2 = sub_080F3EC8(uVar4), iVar2 != 0)) {
          sub_080C0B8C(uVar4,-uVar5);
        }
        uVar4 = uVar4 + 1 & 0xffff;
      } while ((int)uVar4 < iVar1 + 4);
    }
  }
  else {
    sub_080C0B8C(uVar4,-uVar5);
  }
  sub_080C84A0();
  return;
}


// ScriptOp_35D @ 0x08134DC4

void ScriptOp_35D(void)

{
  return;
}


// sub_08134DC8 @ 0x08134DC8

int sub_08134DC8(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 * 0x10000 + 0x80000000U >> 0x10);
  return (int)*(short *)(iVar1 + 0x18);
}


// sub_08134DE0 @ 0x08134DE0

int sub_08134DE0(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 * 0x10000 + 0x80000000U >> 0x10);
  return (int)*(short *)(iVar1 + 0x1a);
}


// sub_08134DF8 @ 0x08134DF8

int sub_08134DF8(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 * 0x10000 + 0x80000000U >> 0x10);
  return (int)*(short *)(iVar1 + 0x1c);
}


// sub_08134E10 @ 0x08134E10

int sub_08134E10(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 * 0x10000 + 0x80000000U >> 0x10);
  return (int)*(short *)(iVar1 + 0x1e);
}


// ScriptOp_35E @ 0x08134E28

void ScriptOp_35E(void)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar3 = sub_080C104C();
  sVar7 = DAT_0203db40 + 1;
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar2 = uVar1 >> 8;
  uVar9 = (uint)*(ushort *)((uVar1 & 0xff) * 2 + 0x8790398);
  DAT_0203db40 = sVar7;
  if (uVar2 == 1) {
LAB_08134eec:
    iVar3 = sub_080C0A00(1);
    if (iVar3 != 0) {
      sub_080C08E8(1,uVar9);
      uVar8 = sub_080C0818(1);
      if ((uVar8 & 0x8000) != 0) {
        uVar6 = sub_08134DC8(1);
        sub_080C0AD4(1,-(int)(short)uVar6);
      }
    }
    iVar3 = sub_080C0A00(2);
    if (iVar3 != 0) {
      sub_080C08E8(2,uVar9);
      uVar9 = sub_080C0818(2);
      if ((uVar9 & 0x8000) != 0) {
        uVar6 = sub_08134DC8(2);
        sub_080C0AD4(2,-(int)(short)uVar6);
      }
    }
  }
  else {
    if (uVar2 < 2) {
      if (uVar2 == 0) {
        iVar3 = sub_080C0A00(0);
        if (iVar3 != 0) {
          sub_080C08E8(0,uVar9);
          uVar9 = sub_080C0818(0);
          if ((uVar9 & 0x8000) != 0) {
            uVar6 = sub_08134DC8(0);
            sub_080C0AD4(0,-(int)(short)uVar6);
          }
        }
        goto LAB_08134fae;
      }
    }
    else if (uVar2 == 2) {
      iVar3 = sub_080C0A00(0);
      if (iVar3 != 0) {
        sub_080C08E8(0,uVar9);
        uVar8 = sub_080C0818(0);
        if ((uVar8 & 0x8000) != 0) {
          uVar6 = sub_08134DC8(0);
          sub_080C0AD4(0,-(int)(short)uVar6);
        }
      }
      goto LAB_08134eec;
    }
    uVar8 = 0;
    if (0 < iVar3 + 4) {
      do {
        iVar4 = sub_080C0A00(uVar8);
        if ((iVar4 != 0) && (iVar4 = sub_080F3EC8(uVar8), iVar4 != 0)) {
          sub_080C08E8(uVar8,uVar9);
          uVar5 = sub_080C0818(uVar8);
          if ((uVar5 & 0x8000) != 0) {
            uVar6 = sub_08134DC8(uVar8);
            sub_080C0AD4(uVar8,-(int)(short)uVar6);
          }
        }
        uVar8 = uVar8 + 1 & 0xffff;
      } while ((int)uVar8 < iVar3 + 4);
    }
  }
LAB_08134fae:
  sub_080C84A0();
                    /* WARNING: Could not recover jumptable at 0x08134fb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_35F @ 0x08134FB8

void ScriptOp_35F(void)

{
  undefined4 arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  if (DAT_0203db6c != 0) {
    sub_080AB91C(DAT_03006968,1);
    DAT_0203db6c = 0;
  }
  Font_ResetGlyphSpriteCache(0x180);
  DAT_0203db40 = DAT_0203db40 + 1;
  if (DAT_030068a8 == 2) {
    arg0 = 2;
  }
  else if (DAT_030068a8 == 3) {
    arg0 = 3;
  }
  else if (DAT_030068a8 == 1) {
    arg0 = 4;
  }
  else if (DAT_030068a8 == 4) {
    arg0 = 1;
  }
  else if (DAT_030068a8 == 5) {
    arg0 = 5;
  }
  else {
    if (DAT_030068a8 != 6) goto LAB_08135046;
    arg0 = 6;
  }
  DAT_030068e0 = sub_08155F94(arg0);
LAB_08135046:
  DAT_0203db5a = 0x2c;
  DAT_0203db6e = 1;
                    /* WARNING: Could not recover jumptable at 0x08135056. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08135064 @ 0x08135064

int sub_08135064(uint arg0,undefined4 arg1)

{
  int iVar1;
  int iVar2;
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  iVar2 = 0;
  if (((ushort)arg1 < 2) && (((&DAT_030046d0)[arg0_00 * 0x40] & 0x8000) == 0)) {
    iVar2 = sub_08135200(arg0_00);
  }
  if (((ushort)arg1 == 2) || ((ushort)arg1 == 0)) {
    iVar1 = sub_081352F8(arg0_00);
    iVar2 = iVar2 + iVar1;
  }
  if (((ushort)arg1 == 3) || ((ushort)arg1 == 0)) {
    iVar1 = sub_08135320(arg0_00);
    iVar2 = iVar2 + iVar1;
  }
  if (((ushort)arg1 == 4) || ((ushort)arg1 == 0)) {
    iVar1 = sub_08135348(arg0_00);
    iVar2 = iVar2 + iVar1;
  }
  return iVar2;
}


// sub_081350CC @ 0x081350CC

void sub_081350CC(uint arg0,undefined4 arg1)

{
  uint uVar1;
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  switch((undefined2)arg1) {
  case 0:
    uVar1 = sub_080C0818(arg0_00);
    if ((uVar1 & 0xc01) != 0) {
      sub_080C08BC(arg0_00,0xf3fe);
      sub_081360D4(arg0_00);
    }
    sub_080C08BC(arg0_00,0);
    sub_080C0A7C(arg0_00);
    sub_080C0AA8(arg0_00);
    break;
  case 2:
    sub_080C08BC(arg0_00,0x8c01);
    break;
  case 3:
    sub_080C08BC(arg0_00,0x7fff);
  case 1:
    sub_080C0A7C(arg0_00);
    sub_080C0AA8(arg0_00);
    break;
  case 4:
    sub_080C08BC(arg0_00,0xf3fe);
    sub_081360D4(arg0_00);
  }
  return;
}


// sub_08135180 @ 0x08135180

void sub_08135180(undefined4 arg0)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint arg0_00;
  uint uVar5;
  
  uVar5 = 0;
  puVar1 = (undefined2 *)sub_0812DBF0();
  iVar2 = sub_080C104C();
  if ((short)arg0 == 0) {
    arg0_00 = 4;
    if (4 < iVar2 + 4) {
      do {
        iVar3 = sub_080C09B0(arg0_00);
        if ((iVar3 != 0) && (uVar4 = sub_080C0818(arg0_00), (uVar4 & 0xb160) == 0)) {
          puVar1[uVar5] = (short)arg0_00;
          uVar5 = uVar5 + 1 & 0xffff;
        }
        arg0_00 = arg0_00 + 1 & 0xffff;
      } while ((int)arg0_00 < iVar2 + 4);
    }
    puVar1[uVar5] = 0xffff;
  }
  else if ((short)arg0 == 1) {
    *puVar1 = 0xffff;
  }
  return;
}


// sub_08135200 @ 0x08135200

undefined4 sub_08135200(uint arg0)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar7 = arg0 & 0xffff;
  uVar1 = sub_08134DE0(uVar7);
  uVar2 = sub_08134DC8(uVar7);
  uVar3 = sub_08134E10(uVar7);
  uVar4 = sub_08134DF8(uVar7);
  if ((int)(short)uVar1 < (int)(short)uVar2) {
    uVar7 = 0;
  }
  else {
    uVar7 = (int)(short)uVar1 - (int)(short)uVar2 & 0xffff;
  }
  if ((int)(short)uVar3 < (int)(short)uVar4) {
    uVar6 = 0;
  }
  else {
    uVar6 = (int)(short)uVar3 - (int)(short)uVar4 & 0xffff;
  }
  iVar5 = (DAT_0203db72 & 3) * 2;
                    /* WARNING: Could not recover jumptable at 0x08135282. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)
                    (uVar7 * *(ushort *)(iVar5 + 0x87903b8) + uVar6 * *(ushort *)(iVar5 + 0x87903be)
                     >> 8);
  return uVar1;
}


// sub_08135290 @ 0x08135290

void sub_08135290(undefined4 arg0,uint arg1)

{
  ushort uVar1;
  
  uVar1 = 0;
  do {
    if (((ushort)arg0 & 0x8000) != 0) {
      sub_080C0F8C(arg1 & 0xffff);
    }
    arg0._0_2_ = (ushort)arg0 << 1;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x10);
  return;
}


// sub_081352F8 @ 0x081352F8

uint sub_081352F8(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C0818(arg0 & 0xffff);
  uVar1 = uVar1 & 0x33fe;
  sub_08135290(uVar1,arg0 & 0xffff);
  return uVar1;
}


// sub_08135320 @ 0x08135320

uint sub_08135320(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C0818(arg0 & 0xffff);
  uVar1 = uVar1 & 0x8000;
  sub_08135290(uVar1,arg0 & 0xffff);
  return uVar1;
}


// sub_08135348 @ 0x08135348

uint sub_08135348(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_080C0818(arg0 & 0xffff);
  uVar1 = uVar1 & 0xc01;
  sub_08135290(uVar1,arg0 & 0xffff);
  return uVar1;
}


// sub_08135370 @ 0x08135370

uint sub_08135370(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint arg0;
  uint uVar7;
  
  uVar7 = 0;
  iVar1 = sub_0812DBF0();
  iVar2 = sub_0812DC00();
  iVar3 = sub_080C104C();
  arg0 = 0;
  if (0 < iVar3 + 4) {
    do {
      iVar4 = sub_080C0A00(arg0);
      if (iVar4 != 0) {
        iVar4 = sub_08134DE0(arg0);
        iVar5 = sub_08134DC8(arg0);
        if (iVar4 * 0x10000 + iVar5 * -0x10000 == 0 || iVar4 * 0x10000 < iVar5 * 0x10000) {
          iVar4 = sub_08134E10(arg0);
          iVar5 = sub_08134DF8(arg0);
          if (iVar4 * 0x10000 + iVar5 * -0x10000 == 0 || iVar4 * 0x10000 < iVar5 * 0x10000)
          goto LAB_081353e2;
        }
        *(short *)(uVar7 * 2 + iVar1) = (short)arg0;
        uVar6 = sub_08135200(arg0);
        *(undefined4 *)(uVar7 * 4 + iVar2) = uVar6;
        uVar7 = uVar7 + 1 & 0xffff;
      }
LAB_081353e2:
      arg0 = arg0 + 1 & 0xffff;
    } while ((int)arg0 < iVar3 + 4);
  }
  *(undefined2 *)(uVar7 * 2 + iVar1) = 0xffff;
  *(undefined4 *)(uVar7 * 4 + iVar2) = 0xffffffff;
  return (uint)(uVar7 == 0);
}


// sub_08135420 @ 0x08135420

uint sub_08135420(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint arg0;
  uint uVar7;
  
  uVar7 = 0;
  iVar1 = sub_0812DBF0();
  iVar2 = sub_0812DC00();
  iVar3 = sub_080C104C();
  arg0 = 0;
  if (0 < iVar3 + 4) {
    do {
      iVar4 = sub_080C0A00(arg0);
      if ((iVar4 != 0) && (uVar5 = sub_080C0818(arg0), (uVar5 & 0x33fe) != 0)) {
        *(short *)(uVar7 * 2 + iVar1) = (short)arg0;
        uVar6 = sub_081352F8(arg0);
        *(undefined4 *)(uVar7 * 4 + iVar2) = uVar6;
        uVar7 = uVar7 + 1 & 0xffff;
      }
      arg0 = arg0 + 1 & 0xffff;
    } while ((int)arg0 < iVar3 + 4);
  }
  *(undefined2 *)(uVar7 * 2 + iVar1) = 0xffff;
  *(undefined4 *)(uVar7 * 4 + iVar2) = 0xffffffff;
  return (uint)(uVar7 == 0);
}


// sub_081354B0 @ 0x081354B0

uint sub_081354B0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint arg0;
  uint uVar7;
  
  uVar7 = 0;
  iVar1 = sub_0812DBF0();
  iVar2 = sub_0812DC00();
  iVar3 = sub_080C104C();
  arg0 = 0;
  if (0 < iVar3 + 4) {
    do {
      iVar4 = sub_080C09B0(arg0);
      if ((iVar4 != 0) && (uVar5 = sub_080C0818(arg0), (uVar5 & 0x8000) != 0)) {
        *(short *)(uVar7 * 2 + iVar1) = (short)arg0;
        uVar6 = sub_08135320(arg0);
        *(undefined4 *)(uVar7 * 4 + iVar2) = uVar6;
        uVar7 = uVar7 + 1 & 0xffff;
      }
      arg0 = arg0 + 1 & 0xffff;
    } while ((int)arg0 < iVar3 + 4);
  }
  *(undefined2 *)(uVar7 * 2 + iVar1) = 0xffff;
  *(undefined4 *)(uVar7 * 4 + iVar2) = 0xffffffff;
  return (uint)(uVar7 == 0);
}


// sub_08135540 @ 0x08135540

uint sub_08135540(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint arg0;
  uint uVar7;
  
  uVar7 = 0;
  iVar1 = sub_0812DBF0();
  iVar2 = sub_0812DC00();
  iVar3 = sub_080C104C();
  arg0 = 0;
  if (0 < iVar3 + 4) {
    do {
      iVar4 = sub_080C0A00(arg0);
      if ((iVar4 != 0) && (uVar5 = sub_080C0818(arg0), (uVar5 & 0xc01) != 0)) {
        *(short *)(uVar7 * 2 + iVar1) = (short)arg0;
        uVar6 = sub_08135348(arg0);
        *(undefined4 *)(uVar7 * 4 + iVar2) = uVar6;
        uVar7 = uVar7 + 1 & 0xffff;
      }
      arg0 = arg0 + 1 & 0xffff;
    } while ((int)arg0 < iVar3 + 4);
  }
  *(undefined2 *)(uVar7 * 2 + iVar1) = 0xffff;
  *(undefined4 *)(uVar7 * 4 + iVar2) = 0xffffffff;
  return (uint)(uVar7 == 0);
}


// sub_081355D0 @ 0x081355D0

int sub_081355D0(uint arg0)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  iVar1 = sub_08135200(arg0_00);
  iVar2 = sub_081352F8(arg0_00);
  iVar3 = sub_08135320(arg0_00);
  iVar4 = sub_08135348(arg0_00);
  return iVar1 + iVar2 + iVar3 + iVar4;
}


// sub_0813560C @ 0x0813560C

uint sub_0813560C(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint arg0;
  uint uVar8;
  
  uVar8 = 0;
  iVar1 = sub_0812DBF0();
  iVar2 = sub_0812DC00();
  iVar3 = sub_080C104C();
  arg0 = 0;
  if (0 < iVar3 + 4) {
    do {
      iVar4 = sub_080C09B0(arg0);
      if (iVar4 != 0) {
        uVar5 = sub_080C0818(arg0);
        if ((uVar5 & 0xffff) == 0) {
          iVar4 = sub_08134DE0(arg0);
          iVar6 = sub_08134DC8(arg0);
          if (iVar4 * 0x10000 + iVar6 * -0x10000 == 0 || iVar4 * 0x10000 < iVar6 * 0x10000) {
            iVar4 = sub_08134E10(arg0);
            iVar6 = sub_08134DF8(arg0);
            if (iVar4 * 0x10000 + iVar6 * -0x10000 == 0 || iVar4 * 0x10000 < iVar6 * 0x10000)
            goto LAB_0813568a;
          }
        }
        *(short *)(uVar8 * 2 + iVar1) = (short)arg0;
        uVar7 = sub_081355D0(arg0);
        *(undefined4 *)(uVar8 * 4 + iVar2) = uVar7;
        uVar8 = uVar8 + 1 & 0xffff;
      }
LAB_0813568a:
      arg0 = arg0 + 1 & 0xffff;
    } while ((int)arg0 < iVar3 + 4);
  }
  *(undefined2 *)(uVar8 * 2 + iVar1) = 0xffff;
  *(undefined4 *)(uVar8 * 4 + iVar2) = 0xffffffff;
  return (uint)(uVar8 == 0);
}


// ScriptOp_360 @ 0x081356C8

void ScriptOp_360(void)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = DAT_0203db40 + 1;
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 2;
  DAT_0203dac8 = CONCAT22(*(undefined2 *)((uint)uVar2 * 2 + DAT_03006950),
                          *(undefined2 *)(uVar1 * 2 + DAT_03006950));
  DAT_0300668c = 1;
  sub_0812DC24();
  DAT_0203db5a = 0x1e;
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_361 @ 0x08135724

void ScriptOp_361(void)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = DAT_0203db40 + 1;
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 2;
  DAT_0203dac8 = CONCAT22(*(undefined2 *)((uint)uVar2 * 2 + DAT_03006950),
                          *(undefined2 *)(uVar1 * 2 + DAT_03006950));
  DAT_0300668c = 2;
  sub_0812DC24();
  DAT_0203db5a = 0x1e;
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_362 @ 0x08135784

void ScriptOp_362(void)

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
  DAT_0300668c = 3;
  sub_0812DC24();
  DAT_0203db5a = 0x1e;
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_363 @ 0x08135820

void ScriptOp_363(void)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = DAT_0203db40 + 1;
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 2;
  DAT_0203dac8 = CONCAT22(*(undefined2 *)((uint)uVar2 * 2 + DAT_03006950),
                          *(undefined2 *)(uVar1 * 2 + DAT_03006950));
  DAT_0300668c = 4;
  sub_0812DC24();
  DAT_0203db5a = 0x1e;
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_364 @ 0x08135880

void ScriptOp_364(void)

{
  return;
}


// ScriptOp_365 @ 0x08135884

void ScriptOp_365(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_370_371 @ 0x08135894

void ScriptOp_370_371(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  return;
}


// ScriptOp_366 @ 0x081358A4

void ScriptOp_366(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar4 = (uint)DAT_0203db40;
  uVar3 = DAT_0203db40 + 2;
  uVar1 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar2 = *(undefined2 *)((uint)uVar3 * 2 + DAT_03006950);
  uVar3 = *(ushort *)((uint)*(ushort *)(uVar4 * 2 + DAT_03006950) * 2 + 0x8790398);
  uVar4 = sub_080C0818(0);
  if ((uVar3 & uVar4) != 0) {
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
  return;
}


// ScriptOp_367 @ 0x08135904

void ScriptOp_367(void)

{
  return;
}


// ScriptOp_368 @ 0x08135908

void ScriptOp_368(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_0203db72 = *(undefined2 *)((uint)uVar1 * 2 + DAT_03006950);
  DAT_0203db74 = DAT_0203db72;
  return;
}


// ScriptOp_369 @ 0x0813593C

void ScriptOp_369(void)

{
  return;
}


// ScriptOp_36B @ 0x08135940

void ScriptOp_36B(void)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  DAT_0203db5a = 0x14;
  DAT_03006954 = sub_080B7AFC(0,(uint)(uVar1 >> 8),uVar1 & 0xff,0);
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_36C @ 0x08135998

void ScriptOp_36C(void)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  DAT_03006954 = sub_080B7AFC(0,(uint)(uVar1 >> 8),uVar1 & 0xff,0);
  return;
}


// ScriptOp_36D @ 0x081359DC

void ScriptOp_36D(void)

{
  ushort uVar1;
  int iVar2;
  short sVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar3 = DAT_0203db40 + 1;
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db5a = 0x32;
  DAT_0203db40 = sVar3;
  if (uVar1 == 1) {
    if ((DAT_0200ab04 & 0x8000) == 0) {
      sub_080B0620();
    }
    else {
      sub_080B0820();
    }
  }
  else {
    if (uVar1 < 2) {
      if (uVar1 != 0) goto LAB_08135a7a;
    }
    else if (uVar1 != 2) {
      if (uVar1 == 3) {
        DAT_03006964 = sub_080B8AE0(0xffff,1);
        DAT_0203db5a = 0x33;
      }
      goto LAB_08135a7a;
    }
    if ((DAT_0200ab04 & 0x8000) == 0) {
      iVar2 = sub_080B78A4();
      if (iVar2 == 0) {
        sub_080B05A4();
      }
    }
    else {
      sub_080B4140();
      sub_080B0778();
    }
  }
LAB_08135a7a:
  DAT_0203db6e = 1;
                    /* WARNING: Could not recover jumptable at 0x08135a84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08135A94 @ 0x08135A94

uint sub_08135A94(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_08157238(arg0 & 0xff);
  return uVar1 & 0xffff;
}


// ScriptOp_36F @ 0x08135AA8

void ScriptOp_36F(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 arg0;
  uint uVar9;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar6 = sub_080C104C();
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  uVar5 = DAT_0203db40 + 3;
  uVar3 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 2) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 4;
  uVar4 = *(undefined2 *)((uint)uVar5 * 2 + DAT_03006950);
  uVar5 = 0;
  uVar9 = 4;
  if (4 < iVar6 + 4) {
    do {
      iVar7 = sub_080C09B0(uVar9);
      if ((iVar7 != 0) && (uVar8 = sub_080C0818(uVar9), (uVar8 & 0xb160) == 0)) {
        uVar5 = uVar5 + 1;
      }
      uVar9 = uVar9 + 1 & 0xffff;
    } while ((int)uVar9 < iVar6 + 4);
  }
  if (DAT_030068a8 == 1) {
    arg0 = 3;
LAB_08135b70:
    uVar9 = sub_08135A94(arg0);
    if (1 < (uVar9 & 0xffff)) goto LAB_08135b90;
LAB_08135b7c:
    DAT_030068e4 = CONCAT22(uVar4,uVar3);
  }
  else {
    if (DAT_030068a8 == 4) {
      if (uVar5 != 0) {
        uVar9 = sub_08135A94(2);
        if ((uVar9 & 0xffff) != 0) goto LAB_08135b90;
        goto LAB_08135b7c;
      }
    }
    else if (DAT_030068a8 == 5) {
      if (uVar5 != 0) {
        arg0 = 4;
        goto LAB_08135b70;
      }
    }
    else if (DAT_030068a8 <= uVar5) goto LAB_08135b90;
    DAT_030068e4 = CONCAT22(uVar2,uVar1);
  }
LAB_08135b90:
                    /* WARNING: Could not recover jumptable at 0x08135b9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_372 @ 0x08135BA0

void ScriptOp_372(void)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  if (sVar1 == 0) {
    DAT_0203db5a = 0x14;
    DAT_03006954 = sub_080B7E0C(1);
    puVar6 = (undefined2 *)0x203db6e;
    uVar2 = 1;
  }
  else {
    if (sVar1 == 1) {
      DAT_0203db5a = 0x14;
      DAT_03006954 = sub_080B7E0C(0);
      DAT_0203db6e = 1;
      goto LAB_08135dfc;
    }
    if (sVar1 == 9) {
      sub_080B08AC();
      DAT_0203db5a = 0x44;
      puVar6 = (undefined2 *)0x203db6e;
      uVar2 = 1;
    }
    else if (sVar1 == 10) {
      sub_080B0888();
      DAT_0203db5a = 0x45;
      puVar6 = (undefined2 *)0x203db6e;
      uVar2 = 1;
    }
    else if (sVar1 == 0xb) {
      DAT_03006954 = sub_080B9510();
      DAT_0203db5a = 0x46;
      puVar6 = (undefined2 *)0x203db6e;
      uVar2 = 1;
    }
    else if (sVar1 == 0xc) {
      DAT_030068a4 = sub_080D3400(2,(uint)DAT_03006898,
                                  (uint)*(ushort *)
                                         (((int)DAT_0300696c + (int)DAT_03006940) * 2 + 0x203bb74));
      DAT_0203db5a = 0;
      puVar6 = (undefined2 *)0x203db6e;
      uVar2 = 1;
    }
    else if (sVar1 == 0xd) {
      if (DAT_030068a4 != 0) goto LAB_08135dfc;
      DAT_030068a4 = sub_080D3400(0,0,0);
      DAT_0203db5a = 0;
      puVar6 = (undefined2 *)0x203db6e;
      uVar2 = 1;
    }
    else {
      if (sVar1 != 0xe) {
        if (sVar1 == 0xf) {
          iVar3 = sub_080C4C7C((uint)DAT_0203db50);
          uVar4 = sub_080C32D4((uint)DAT_0203db50);
          iVar3 = (uVar4 & 0xff) * iVar3 + iVar3;
          while (uVar4 = sub_080C32D4((uint)DAT_0203db50), (uVar4 & 0xff) != 0) {
            sub_080C33AC((uint)DAT_0203db50);
          }
          uVar4 = sub_080D2268((uint)DAT_0203db50);
          uVar4 = uVar4 & 0xffff;
          puVar5 = (ushort *)0x3006898;
        }
        else {
          if (sVar1 != 0x10) {
            if (sVar1 == 0x11) {
              puVar6 = (undefined2 *)0x300699c;
              uVar2 = 0;
            }
            else {
              if (sVar1 != 0x12) goto LAB_08135dfc;
              DAT_03006958 = 0;
              DAT_0300699c = 0;
              puVar6 = (undefined2 *)0x3006678;
              uVar2 = 0;
            }
            goto LAB_08135dfa;
          }
          iVar3 = sub_080C4C7C((uint)DAT_0203db50);
          uVar4 = sub_080C32D4((uint)DAT_0203db50);
          iVar3 = (uVar4 & 0xff) * iVar3 + iVar3 * 2;
          while (uVar4 = sub_080C32D4((uint)DAT_0203db50), (uVar4 & 0xff) != 0) {
            sub_080C33AC((uint)DAT_0203db50);
          }
          uVar4 = sub_080D2268((uint)DAT_0203db50);
          uVar4 = uVar4 & 0xffff;
          sub_080CDFF8((uint)DAT_03006898,uVar4);
          puVar5 = (ushort *)0x3006940;
        }
        sub_080CDFF8((uint)*puVar5,uVar4);
        sub_080C30AC(iVar3);
        goto LAB_08135dfc;
      }
      if (DAT_030068a4 != 0) {
        sub_080D34F0(DAT_030068a4);
        DAT_030068a4 = 0;
      }
      DAT_0203db5a = 0;
      puVar6 = (undefined2 *)0x203db6e;
      uVar2 = 1;
    }
  }
LAB_08135dfa:
  *puVar6 = uVar2;
LAB_08135dfc:
                    /* WARNING: Could not recover jumptable at 0x08135e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_373 @ 0x08135E10

void ScriptOp_373(void)

{
  return;
}


// ScriptOp_374 @ 0x08135E14

void ScriptOp_374(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  uint arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080C104C();
  sVar4 = DAT_0203db40 + 1;
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = sVar4;
  if (sVar1 == 0) {
    iVar2 = sub_080C09B0(0);
    if ((iVar2 != 0) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
      sub_080C0A7C(0);
    }
  }
  else {
    if (sVar1 != 1) {
      if (sVar1 != 2) {
        arg0 = 0;
        if (0 < iVar2 + 4) {
          do {
            iVar3 = sub_080C09B0(arg0);
            if ((iVar3 != 0) && (iVar3 = sub_080C0830(), iVar3 == 0)) {
              sub_080C0A7C(arg0);
            }
            arg0 = arg0 + 1 & 0xffff;
          } while ((int)arg0 < iVar2 + 4);
        }
        goto LAB_08135ee0;
      }
      iVar2 = sub_080C09B0(0);
      if ((iVar2 != 0) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
        sub_080C0A7C(0);
      }
    }
    iVar2 = sub_080C09B0(1);
    if ((iVar2 != 0) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
      sub_080C0A7C(1);
    }
    iVar2 = sub_080C09B0(2);
    if ((iVar2 != 0) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
      sub_080C0A7C(2);
    }
  }
LAB_08135ee0:
  sub_080C84A0();
                    /* WARNING: Could not recover jumptable at 0x08135ee8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_375 @ 0x08135EEC

void ScriptOp_375(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  uint arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080C104C();
  sVar4 = DAT_0203db40 + 1;
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = sVar4;
  if (sVar1 == 0) {
    iVar2 = sub_080C09B0(0);
    if ((iVar2 != 0) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
      sub_080C0AA8(0);
    }
  }
  else {
    if (sVar1 != 1) {
      if (sVar1 != 2) {
        arg0 = 0;
        if (0 < iVar2 + 4) {
          do {
            iVar3 = sub_080C09B0(arg0);
            if ((iVar3 != 0) && (iVar3 = sub_080C0830(), iVar3 == 0)) {
              sub_080C0AA8(arg0);
            }
            arg0 = arg0 + 1 & 0xffff;
          } while ((int)arg0 < iVar2 + 4);
        }
        goto LAB_08135fb8;
      }
      iVar2 = sub_080C09B0(0);
      if ((iVar2 != 0) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
        sub_080C0AA8(0);
      }
    }
    iVar2 = sub_080C09B0(1);
    if ((iVar2 != 0) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
      sub_080C0AA8(1);
    }
    iVar2 = sub_080C09B0(2);
    if ((iVar2 != 0) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
      sub_080C0AA8(2);
    }
  }
LAB_08135fb8:
  sub_080C84A0();
                    /* WARNING: Could not recover jumptable at 0x08135fc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08135FC4 @ 0x08135FC4

void sub_08135FC4(undefined4 arg0)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  uint uStack_c;
  
  iVar1 = sub_080C00DC(arg0,0);
  if (((((iVar1 == 0xff) || (iVar1 == -1)) || (sub_080BF468(iVar1,6,&uStack_c), (uStack_c & 1) == 0)
       ) && ((((((iVar1 = sub_080C00DC(arg0,1), iVar1 == 0xff || (iVar1 == -1)) ||
                (sub_080BF468(iVar1,6,&uStack_c), (uStack_c & 1) == 0)) &&
               (((iVar1 = sub_080C00DC(arg0,2), iVar1 == 0xff || (iVar1 == -1)) ||
                (sub_080BF468(iVar1,6,&uStack_c), (uStack_c & 1) == 0)))) &&
              (((iVar1 = sub_080C00DC(arg0,3), iVar1 == 0xff || (iVar1 == -1)) ||
               (sub_080BF468(iVar1,6,&uStack_c), (uStack_c & 1) == 0)))) &&
             (((iVar1 = sub_080C00DC(arg0,4), iVar1 == 0xff || (iVar1 == -1)) ||
              (sub_080BF468(iVar1,6,&uStack_c), (uStack_c & 1) == 0)))))) &&
     (((iVar1 = sub_080C00DC(arg0,5), iVar1 == 0xff || (iVar1 == -1)) ||
      (sub_080BF468(iVar1,6,&uStack_c), (uStack_c & 1) == 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x081360d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}


// sub_081360D4 @ 0x081360D4

void sub_081360D4(uint arg0)

{
  int arg0_00;
  uint local_c;
  
  arg0_00 = sub_080C00DC(arg0,0);
  if (((arg0_00 != 0xff) && (arg0_00 != -1)) &&
     (sub_080BF468(arg0_00,6,&local_c), (local_c & 1) != 0)) {
    sub_080CDFF8(arg0 & 0xffff,0);
  }
  return;
}


// sub_08136114 @ 0x08136114

void sub_08136114(void)

{
  uint arg0;
  uint local_c;
  
  arg0 = sub_080C00DC(1,0);
  if (((arg0 != 0xff) && (arg0 != 0xffffffff)) &&
     (sub_080BF468(arg0,6,&local_c), (local_c & 1) != 0)) {
    sub_080CDFF8(1,0);
    sub_080C3328(arg0 & 0xffff);
  }
  return;
}


// ScriptOp_376 @ 0x0813615C

void ScriptOp_376(void)

{
  short sVar1;
  int iVar2;
  undefined4 arg0;
  int iVar3;
  short sVar4;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080C104C();
  sVar4 = DAT_0203db40 + 1;
  sVar1 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = sVar4;
  if (sVar1 == 0) {
    iVar2 = sub_080C09B0(0);
    if (iVar2 == 0) goto LAB_081361f8;
    arg0 = 0;
  }
  else {
    if (sVar1 != 1) {
      if (sVar1 != 2) {
        arg0_00 = 0;
        if (0 < iVar2 + 4) {
          do {
            iVar3 = sub_080C09B0(arg0_00);
            if (iVar3 != 0) {
              sub_080C08BC(arg0_00,1);
            }
            arg0_00 = arg0_00 + 1 & 0xffff;
          } while ((int)arg0_00 < iVar2 + 4);
        }
        goto LAB_081361f8;
      }
      iVar2 = sub_080C09B0(0);
      if (iVar2 != 0) {
        sub_080C08BC(0,1);
      }
    }
    iVar2 = sub_080C09B0(1);
    if (iVar2 != 0) {
      sub_080C08BC(1,1);
    }
    iVar2 = sub_080C09B0(2);
    if (iVar2 == 0) goto LAB_081361f8;
    arg0 = 2;
  }
  sub_080C08BC(arg0,1);
LAB_081361f8:
  sub_080C84A0();
                    /* WARNING: Could not recover jumptable at 0x08136200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08136204 @ 0x08136204

void sub_08136204(int arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  switch(arg1) {
  case 0:
    *(undefined1 *)(iVar1 + 0x28) = (undefined1)arg2;
    break;
  case 1:
    *(undefined1 *)(iVar1 + 0x29) = (undefined1)arg2;
    break;
  case 2:
    *(undefined1 *)(iVar1 + 0x2a) = (undefined1)arg2;
    break;
  case 3:
    *(undefined1 *)(iVar1 + 0x2b) = (undefined1)arg2;
    break;
  case 4:
    *(undefined1 *)(iVar1 + 0x2c) = (undefined1)arg2;
    break;
  case 5:
    *(undefined1 *)(iVar1 + 0x2d) = (undefined1)arg2;
  }
  return;
}


// sub_08136270 @ 0x08136270

void sub_08136270(int arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  switch(arg1) {
  case 0:
    *(undefined1 *)(iVar1 + 0x38) = (undefined1)arg2;
    break;
  case 1:
    *(undefined1 *)(iVar1 + 0x39) = (undefined1)arg2;
    break;
  case 2:
    *(undefined1 *)(iVar1 + 0x3a) = (undefined1)arg2;
    break;
  case 3:
    *(undefined1 *)(iVar1 + 0x3b) = (undefined1)arg2;
    break;
  case 4:
    *(undefined1 *)(iVar1 + 0x3c) = (undefined1)arg2;
    break;
  case 5:
    *(undefined1 *)(iVar1 + 0x3d) = (undefined1)arg2;
  }
  return;
}


// sub_081362DC @ 0x081362DC

void sub_081362DC(int arg0)

{
  uint uVar1;
  int iVar2;
  
  sub_080F2F64(0x8002);
  sub_080F2F64(0x8001);
  if (arg0 == 0) {
    sub_080C0FA4(1,0x12);
    sub_080C0F70(1,0x25da);
    sub_080C0074(1,0,6);
    sub_080C0074(1,1,0x58);
    sub_080C0074(1,6,0x70);
    sub_080C0074(1,2,0x81);
    sub_080C0074(1,3,0x96);
    sub_080C0074(1,4,0xaa);
    sub_080C0074(1,5,0xbf);
    uVar1 = sub_080C2244();
    iVar2 = (uVar1 & 3) * 6;
    sub_08136204(1,0,(int)*(char *)(iVar2 + 0x87903ee));
    sub_08136204(1,1,(int)(char)(&DAT_087903ef)[iVar2]);
    sub_08136204(1,2,(int)(char)(&DAT_087903f0)[iVar2]);
    sub_08136204(1,3,(int)(char)(&DAT_087903f1)[iVar2]);
    sub_08136204(1,4,(int)(char)(&DAT_087903f2)[iVar2]);
    sub_08136204(1,5,(int)(char)(&DAT_087903f3)[iVar2]);
    sub_08136270(1,0,0);
    sub_08136270(1,1,0);
    sub_08136270(1,2,0);
    sub_08136270(1,3,0);
    sub_08136270(1,4,0);
    sub_08136270(1,5,0);
    sub_080BF938(1);
    sub_080CDC34();
    DAT_03004758 = DAT_0300475a;
    DAT_0300475c = DAT_0300475e;
    sub_080F4260(1);
  }
  else if (arg0 == 1) {
    sub_080C0FA4(2,0x18);
    sub_080C0F70(2,23000);
    sub_080C0074(2,0,2);
    sub_080C0074(2,1,0x58);
    sub_080C0074(2,6,0x70);
    sub_080C0074(2,2,0x82);
    sub_080C0074(2,3,0x98);
    sub_080C0074(2,4,0xac);
    sub_080C0074(2,5,0xbf);
    uVar1 = sub_080C2244();
    uVar1 = (uVar1 & 3) * 0x60000 + 0x180000 >> 0x10;
    sub_08136204(2,0,(int)*(char *)(uVar1 + 0x87903ee));
    sub_08136204(2,1,(int)(char)(&DAT_087903ef)[uVar1]);
    sub_08136204(2,2,(int)(char)(&DAT_087903f0)[uVar1]);
    sub_08136204(2,3,(int)(char)(&DAT_087903f1)[uVar1]);
    sub_08136204(2,4,(int)(char)(&DAT_087903f2)[uVar1]);
    sub_08136204(2,5,(int)(char)(&DAT_087903f3)[uVar1]);
    sub_08136270(2,0,0);
    sub_08136270(2,1,0);
    sub_08136270(2,2,0);
    sub_08136270(2,3,0);
    sub_08136270(2,4,0);
    sub_08136270(2,5,0);
    sub_080BF938(2);
    sub_080CDC34();
    DAT_030047d8 = DAT_030047da;
    DAT_030047dc = DAT_030047de;
    sub_080F4260(2);
  }
  else {
    uVar1 = sub_080C0818(1);
    if ((uVar1 & 0xc01) != 0) {
      sub_080C08BC(1,0xf3fe);
      sub_081360D4(1);
    }
    sub_080C08BC(1,0);
    sub_08136114();
    DAT_03004758 = DAT_0300475a;
    DAT_0300475c = DAT_0300475e;
    sub_080F4260(1);
  }
  return;
}


// ScriptOp_377 @ 0x081365D0

void ScriptOp_377(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int arg0;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar5 = (uint)*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  if (uVar5 < 4) {
    if (uVar5 == 1) {
      uVar5 = 2;
    }
    else if (uVar5 == 0) {
      uVar5 = 1;
    }
    DAT_0203db40 = DAT_0203db40 + 1;
    uVar1 = sub_080C01DC(uVar5);
    if ((uVar1 & 0xffff) == 0) {
      iVar4 = 5;
      do {
        if (3 < (char)(&DAT_030050e0)[iVar4]) {
          sub_080C0290((int)(char)(&DAT_030050e0)[iVar4] & 0xffff,0);
          sub_080C01DC(uVar5);
          goto LAB_081366f8;
        }
        iVar4 = iVar4 + -1;
      } while (-1 < iVar4);
    }
    else {
      Party_BuildMemberNameTiles();
      sub_080C6FD8();
    }
    if (uVar5 == 1) {
      iVar4 = sub_080C2340(0xf);
      if (iVar4 == 0) {
        sub_081362DC(0);
      }
      else {
        sub_081362DC(2);
      }
    }
    else {
      sub_081362DC(1);
    }
    sub_080C23BC(0xe3);
    iVar4 = sub_080C2340(0xe2);
    if (iVar4 == 0) {
      sub_080C23BC(0xcf);
    }
  }
  else {
    DAT_0203db40 = DAT_0203db40 + 1;
    iVar4 = sub_080C104C();
    arg0 = 4;
    if (4 < iVar4 + 4) {
      uVar5 = 0x40000;
      do {
        iVar2 = sub_080C0A00(arg0);
        if ((iVar2 != 0) && (uVar3 = sub_080C07E0(arg0), (int)(short)uVar3 == (uint)DAT_0203db28)) {
          uVar1 = sub_080C01DC(uVar5 >> 0x10);
          if ((uVar1 & 0xffff) != 0) goto LAB_081366f8;
          iVar4 = 5;
          goto LAB_081366d6;
        }
        uVar5 = uVar5 + 0x10000;
        arg0 = arg0 + 1;
      } while (arg0 < iVar4 + 4);
    }
  }
LAB_08136710:
                    /* WARNING: Could not recover jumptable at 0x08136714. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
  while (iVar4 = iVar4 + -1, -1 < iVar4) {
LAB_081366d6:
    if (3 < (char)(&DAT_030050e0)[iVar4]) {
      sub_080C0290((int)(char)(&DAT_030050e0)[iVar4] & 0xffff,0);
      sub_080C01DC(uVar5 >> 0x10);
      break;
    }
  }
LAB_081366f8:
  Party_BuildMemberNameTiles();
  sub_080C6FD8();
  goto LAB_08136710;
}


// ScriptOp_378 @ 0x08136718

void ScriptOp_378(void)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = (uint)*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  if (uVar2 < 4) {
    DAT_0203db40 = DAT_0203db40 + 1;
    iVar1 = sub_080C09B0(1);
    if (iVar1 == 0) {
      iVar1 = sub_080C09B0(2);
      if (iVar1 != 0) {
        uVar2 = 2;
      }
    }
    else {
      uVar2 = 1;
    }
    sub_080C0290(uVar2,0);
  }
  else {
    DAT_0203db40 = DAT_0203db40 + 1;
    uVar2 = sub_080C0FE8((uint)*(ushort *)((uVar2 & 1) * 2 + 0x203db28));
    if (-1 < (int)uVar2) {
      sub_080C0290(uVar2 & 0xffff,1);
    }
  }
  sub_080C366C();
                    /* WARNING: Could not recover jumptable at 0x08136788. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_379 @ 0x08136790

void ScriptOp_379(void)

{
  uint uVar1;
  
  DAT_030068a0 = 0;
  if (DAT_030065fc == 0) {
    sub_080C3328((uint)DAT_0203db50);
  }
  else {
    uVar1 = 0;
    if (0 < DAT_030065fc) {
      do {
        sub_080C3328((uint)DAT_0203db50);
        uVar1 = uVar1 + 1 & 0xffff;
      } while ((int)uVar1 < (int)DAT_030065fc);
    }
  }
  return;
}


// ScriptOp_37A @ 0x081367E4

void ScriptOp_37A(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint arg0;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  DAT_030068a0 = 0;
  if (DAT_030065fc < 1) {
    sub_080C33AC((uint)DAT_0203db50);
  }
  else {
    uVar4 = 0;
    if (0 < DAT_030065fc) {
      do {
        uVar1 = sub_080C32D4((uint)DAT_0203db50);
        if ((uVar1 & 0xff) == 0) {
          uVar1 = sub_080D2268((uint)DAT_0203db50);
          for (arg0 = 0; arg0 < 4; arg0 = arg0 + 1 & 0xffff) {
            iVar2 = sub_080C09B0(arg0);
            if ((iVar2 != 0) &&
               (uVar3 = sub_080C00DC(arg0,uVar1 & 0xffff), (uVar3 & 0xffff) == (uint)DAT_0203db50))
            {
              sub_080CDFF8(arg0,uVar1 & 0xffff);
              break;
            }
          }
        }
        else {
          sub_080C33AC((uint)DAT_0203db50);
        }
        uVar4 = uVar4 + 1 & 0xffff;
      } while ((int)uVar4 < (int)DAT_030065fc);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08136880. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_37B @ 0x08136888

void ScriptOp_37B(void)

{
  DAT_030068b0 = sub_080B6DB4((uint)DAT_03004534);
  DAT_0203db5a = 2;
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_37D @ 0x081368B8

void ScriptOp_37D(void)

{
  dword arg0;
  
  arg0 = (dword)*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  if (arg0 == 3) {
    arg0 = 0x8000;
  }
  else if (arg0 == 4) {
    arg0 = 0x8001;
  }
  else if (arg0 == 5) {
    arg0 = 0x8002;
  }
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_030068e0 = sub_080D1E48(arg0);
  DAT_0203db5a = 0x17;
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  if (DAT_0203db6c != 0) {
    sub_080AB91C(DAT_03006968,1);
    DAT_0203db6c = 0;
  }
  Font_ResetGlyphSpriteCache(0x180);
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_37F @ 0x0813695C

void ScriptOp_37F(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint uVar4;
  ushort uVar5;
  
  uVar4 = (uint)DAT_0203db40;
  uVar1 = *(ushort *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  uVar5 = DAT_0203db40 + 3;
  uVar2 = *(undefined2 *)((uint)(ushort)(DAT_0203db40 + 2) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 4;
  uVar3 = *(undefined2 *)((uint)uVar5 * 2 + DAT_03006950);
  uVar4 = sub_080C0818((uint)*(ushort *)(uVar4 * 2 + DAT_03006950));
  if ((uVar1 & uVar4) != 0) {
    DAT_030068e4 = CONCAT22(uVar3,uVar2);
  }
  return;
}


// ScriptOp_380 @ 0x081369BC

void ScriptOp_380(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  return;
}


// ScriptOp_381 @ 0x081369CC

void ScriptOp_381(void)

{
  short sVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar4 = sub_080C104C();
  uVar5 = (uint)DAT_0203db40;
  sVar3 = *(short *)(uVar5 * 2 + DAT_03006950);
  sVar1 = *(short *)((uVar5 + 1 & 0xffff) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 4;
  uVar6 = CONCAT22(*(undefined2 *)((uVar5 + 3 & 0xffff) * 2 + DAT_03006950),
                   *(undefined2 *)((uVar5 + 2 & 0xffff) * 2 + DAT_03006950));
  if (sVar3 == 1) {
    if (sVar1 != 0) {
      uVar2 = uVar6;
      if (sVar1 != 3) goto LAB_08136bbe;
      sVar3 = 0;
      uVar5 = 4;
      if (4 < iVar4 + 4) {
        do {
          iVar10 = (int)(uVar5 * 0x10000) >> 0x10;
          iVar7 = sub_080C09B0(iVar10);
          if ((iVar7 != 0) && (uVar8 = sub_080C0818(iVar10), (uVar8 & 0xb160) == 0)) {
            sVar3 = sVar3 + 1;
          }
          uVar8 = uVar5 * 0x10000 + 0x10000;
          uVar5 = uVar8 >> 0x10;
        } while ((int)uVar8 >> 0x10 < iVar4 + 4);
      }
      uVar2 = DAT_030068e4;
      if (sVar3 != 0) goto LAB_08136bbe;
    }
LAB_08136bb8:
    uVar2 = uVar6;
  }
  else {
    if (sVar3 == 2) {
      DAT_030065e8 = sVar1;
      if (sVar1 == 0) {
        sub_08135180(0);
        DAT_0203db5a = 0x40;
      }
      else {
        if (sVar1 == 1) {
          sub_08135180(1);
        }
        else {
          DAT_030065e8 = sVar3;
          sub_08135180(1);
        }
        DAT_0203db5a = 0x40;
      }
    }
    else {
      if (sVar3 != 3) {
        if (sVar1 == 0) {
          uVar5 = 4;
          if (4 < iVar4 + 4) {
            do {
              iVar10 = (int)(uVar5 * 0x10000) >> 0x10;
              iVar7 = sub_080C09B0(iVar10);
              if (iVar7 != 0) {
                iVar7 = sub_080C07E0(iVar10);
                iVar9 = sub_080C07E0((uint)DAT_03006944);
                if (iVar7 * 0x10000 + iVar9 * -0x10000 == 0) {
                  sub_080C0290(uVar5,1);
                  break;
                }
              }
              uVar5 = iVar10 + 1U & 0xffff;
            } while ((int)((iVar10 + 1U) * 0x10000) >> 0x10 < iVar4 + 4);
          }
        }
        sub_080C84A0();
        goto LAB_08136bb8;
      }
      DAT_0203db3e = 0;
      DAT_0203db38 = 0;
      DAT_0203db3a = 0;
      DAT_0203db4a = 0;
      if (DAT_0203db6c != 0) {
        sub_080AB91C(DAT_03006968,1);
        DAT_0203db6c = 0;
      }
      Font_ResetGlyphSpriteCache(0x180);
      DAT_0203db5a = 0x41;
    }
    DAT_0203db6e = 1;
    DAT_0203dac8 = uVar6;
    uVar2 = DAT_030068e4;
  }
LAB_08136bbe:
  DAT_030068e4 = uVar2;
                    /* WARNING: Could not recover jumptable at 0x08136bc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ScriptOp_382 @ 0x08136BD4

void ScriptOp_382(void)

{
  ushort uVar1;
  short sVar2;
  short *psVar3;
  
  DAT_0203db4a = 0;
  DAT_0203db3a = 0;
  DAT_0203db38 = 0;
  DAT_0203db3e = 0;
  Font_ResetGlyphSpriteCache(0x180);
  uVar1 = DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  psVar3 = (short *)((uint)uVar1 * 2 + DAT_03006950);
  DAT_030068d0 = DAT_03006950;
  DAT_03006610 = DAT_0203db40;
  DAT_03006910 = 1;
  if (DAT_03006914 < 0x100) {
    DAT_03006950 = 0x803534c;
    sVar2 = DAT_03006914 * 0x1c;
  }
  else {
    DAT_03006950 = 0x8035abc;
    sVar2 = (DAT_03006914 & 0xff) * 0xe;
  }
  DAT_030068e4 = *(undefined4 *)((uint)(ushort)(*psVar3 * 2 + sVar2) * 2 + DAT_03006950);
  return;
}


// ScriptOp_388 @ 0x08136C94

void ScriptOp_388(void)

{
  DAT_03006938 = sub_080B80F8();
  DAT_0203db5a = 0x15;
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_389 @ 0x08136CBC

void ScriptOp_389(void)

{
  switch(DAT_03006914) {
  case 0x1c:
    DAT_030068e4 = 0x8073c5e;
    break;
  case 0x1d:
    DAT_030068e4 = 0x8074c28;
    break;
  case 0x1e:
    DAT_030068e4 = 0x8075be8;
    break;
  case 0x1f:
    DAT_030068e4 = 0x8076c3c;
    break;
  case 0x20:
    DAT_030068e4 = 0x8076f80;
    break;
  case 0x21:
    DAT_030068e4 = 0x8077338;
  }
  return;
}


