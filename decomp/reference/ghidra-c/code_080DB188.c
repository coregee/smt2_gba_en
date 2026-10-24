/* Ghidra decompilation of asm/code_080DB188.s (reference only; not compiled). */

// sub_080DB188 @ 0x080DB188

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DB188(void)

{
  *(undefined4 *)(DAT_0203a4cc + 0x20) = _DAT_0203a4d4;
  *(undefined4 *)(_DAT_0203a4d0 + 0x20) = DAT_0203a4d8;
  sub_080AB250(0x857f500,0x2024074,0,0);
  DisplayList_Add(0x80d9bad,1);
  return;
}


// sub_080DB1D8 @ 0x080DB1D8

void sub_080DB1D8(undefined4 arg0,undefined4 arg1)

{
  DAT_0300609c = arg1;
  return;
}


// sub_080DB1E4 @ 0x080DB1E4

void sub_080DB1E4(void)

{
  DAT_02039a28 = 0;
  DAT_02039a24 = 0;
  DAT_02039a26 = 0;
  return;
}


// sub_080DB1FC @ 0x080DB1FC

void sub_080DB1FC(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          if (*(short *)(arg0 + 0x24) == 1) {
            *(ushort *)(arg0 + 0x24) = DAT_03003964 & 0x40;
          }
          else {
            *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + 1;
          }
          sub_080C51D4(100);
        }
      }
      else {
        if (*(short *)(arg0 + 0x24) == 0) {
          *(undefined2 *)(arg0 + 0x24) = 1;
        }
        else {
          *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
        }
        sub_080C51D4(100);
      }
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    *(short *)(arg0 + 0x1e) = *(short *)(arg0 + 0x24) + 1;
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if (*(short *)(arg0 + 0x1e) == 1) {
      Dict_BuildList(arg0,0,0);
      iVar1 = sub_080DB8A4();
      if (iVar1 == 0) {
        *(undefined2 *)(arg0 + 0x1e) = 3;
      }
      else {
        DAT_02039a18 = DAT_0203b554 & 0x7fff;
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080db2be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// DDS_DrawMenuRow @ 0x080DB2C0

void DDS_DrawMenuRow(void)

{
  undefined4 in_r0;
  int iVar1;
  
  iVar1 = sub_080AD364(in_r0);
  Text_DrawSpriteString(*(undefined4 *)((uint)*(ushort *)(iVar1 + 0x24) * 4 + 0x8582d28),0,0,0x14);
  return;
}


// sub_080DB2F0 @ 0x080DB2F0

void sub_080DB2F0(void)

{
  Text_DrawSpriteString(0x80095b4,0,0,0x14);
  return;
}


// sub_080DB314 @ 0x080DB314

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DB314(void)

{
  undefined4 local_c;
  
  _DAT_0203a454 = 0x10570010;
  CpuSet(0x3004690,&DAT_0203a458,0x400000c);
  _DAT_0203a488 = 0;
  local_c = 0;
  CpuSet(&local_c,&DAT_0203a48c,0x500000c);
  return;
}


// sub_080DB358 @ 0x080DB358

void sub_080DB358(void)

{
  sub_080DF954(0x34,0x203a454,&DAT_0203a488);
  return;
}


// sub_080DB370 @ 0x080DB370

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DB370(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(_DAT_0203a488 == 0x10570010);
  return;
}


// sub_080DB394 @ 0x080DB394

void sub_080DB394(void)

{
  uint arg0;
  
  arg0 = 0;
  do {
    if (((int)(uint)*(byte *)((int)&DAT_0203a48c + (arg0 >> 3)) >> (arg0 & 7) & 1U) != 0) {
      sub_080C2674(arg0);
    }
    arg0 = arg0 + 1;
  } while (arg0 < 0x17c);
  sub_080D1264(DAT_03005f70,0x30046c0);
  return;
}


// sub_080DB3E4 @ 0x080DB3E4

undefined4 sub_080DB3E4(undefined4 arg0)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = 0;
  do {
    sVar1 = *(short *)(uVar3 * 2 + 0x8583258);
    if (sVar1 == -1) {
      uVar2 = 0x20;
LAB_080db416:
                    /* WARNING: Could not recover jumptable at 0x080db41a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
      return uVar2;
    }
    if (sVar1 == (short)arg0) {
      uVar2 = 0;
      goto LAB_080db416;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while( true );
}


// sub_080DB41C @ 0x080DB41C

void sub_080DB41C(void)

{
  uint uVar1;
  
  if (DAT_02039a28 == 0) {
    uVar1 = sub_080C263C((uint)(ushort)DAT_02039a18);
    sub_080C3818(1);
    DAT_02039a28 = sub_080E8E00(0,uVar1 & 0xffff);
    uVar1 = sub_080DB3E4(uVar1 & 0xffff);
    sub_080E8F80(0,0x78,(uVar1 & 0xffff) + 0x58,3);
  }
  return;
}


// sub_080DB464 @ 0x080DB464

void sub_080DB464(void)

{
  uint uVar1;
  
  uVar1 = sub_080C263C((uint)(ushort)DAT_02039a18);
  sub_080C3818(1);
  DAT_02039a28 = sub_080E8E00(0,uVar1 & 0xffff);
  uVar1 = sub_080DB3E4(uVar1 & 0xffff);
  sub_080E8F80(0,0x78,(uVar1 & 0xffff) + 0x58,3);
  return;
}


// Dict_BuildList @ 0x080DB4A8

/* WARNING: Removing unreachable block (ram,0x080db656) */

void Dict_BuildList(undefined4 arg0,int arg1,uint arg2)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  short sVar12;
  ushort *puVar13;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 local_2c [2];
  uint local_28;
  int local_24;
  
  puVar13 = (ushort *)0x203b554;
  DAT_02039a20._0_2_ = (undefined2)arg1;
  DAT_02039a20._2_2_ = (undefined2)arg2;
  DAT_02039a1c._0_2_ = 0;
  DAT_02039a1c._2_2_ = 0;
  local_2c[0] = 0xffff;
  CpuSet(local_2c,0x203b554,0x1000180);
  if (arg1 == 0) {
    uVar11 = 0;
    do {
      uVar9 = uVar11 & 0xffff;
      uVar3 = sub_080C2600(uVar9);
      if (((uVar3 & 0xffff) == uVar11) && (iVar4 = sub_080DD248(uVar9), iVar4 != 0)) {
        uVar5 = sub_080C2600(uVar9);
        *puVar13 = (ushort)uVar5;
        puVar13 = puVar13 + 1;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < 0x17c);
    DAT_02039a1c._2_2_ = 1;
  }
  else if (arg1 == 1) {
    uVar11 = 0;
    do {
      uVar9 = 0;
      uVar3 = uVar11 + 1;
      do {
        uVar10 = uVar9 & 0xffff;
        pcVar6 = (char *)sub_080BF648(uVar10);
        if ((((int)*pcVar6 == uVar11) && (uVar7 = sub_080C2600(uVar10), (uVar7 & 0xffff) == uVar9))
           && (iVar4 = sub_080DD248(uVar10), iVar4 != 0)) {
          uVar5 = sub_080C2600(uVar10);
          *puVar13 = (ushort)uVar5;
          puVar13 = puVar13 + 1;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < 0x17c);
      uVar11 = uVar3;
    } while (uVar3 < 0x2d);
    if (0x28 < arg2) {
      arg2 = arg2 + 1;
    }
    uVar11 = 0;
    puVar13 = (ushort *)0x203b554;
    do {
      if (*puVar13 == 0xffff) {
        DAT_02039a1c._0_2_ = 0;
        break;
      }
      pcVar6 = (char *)sub_080BF648(*puVar13 & 0x7fff);
      if ((int)*pcVar6 == arg2) {
        DAT_02039a1c._0_2_ = (short)uVar11;
        DAT_02039a1c._2_2_ = 1;
        break;
      }
      puVar13 = puVar13 + 1;
      uVar11 = uVar11 + 1;
    } while (uVar11 < 0x17c);
    uVar11 = 0;
    if (DAT_0203b554 != -1) {
      puVar13 = (ushort *)0x203b554;
      do {
        pcVar6 = (char *)sub_080BF648(*puVar13 & 0x7fff);
        if ((int)*pcVar6 != arg2) {
          *puVar13 = *puVar13 | 0x8000;
        }
        puVar13 = puVar13 + 1;
        uVar11 = uVar11 + 1;
      } while ((uVar11 < 0x17c) && (*puVar13 != 0xffff));
    }
  }
  else if (arg1 == 2) {
    bVar1 = false;
    sVar12 = 0;
    uVar3 = 0;
    uVar11 = 0x58;
    do {
      uVar9 = sub_080C2600(uVar11);
      if (((uVar9 & 0xffff) == uVar11) && (iVar4 = sub_080DD248(uVar11), iVar4 != 0)) {
        uVar5 = sub_080C2600(uVar11);
        *puVar13 = (ushort)uVar5;
        uVar11 = (uint)*(ushort *)(uVar3 * 4 + 0x8585c36);
        if (uVar11 != arg2) {
          *puVar13 = (ushort)uVar5 | 0x8000;
        }
        puVar13 = puVar13 + 1;
        if ((!bVar1) && (uVar11 == arg2)) {
          DAT_02039a1c._2_2_ = 1;
          bVar1 = true;
          DAT_02039a1c._0_2_ = sVar12;
        }
        sVar12 = sVar12 + 1;
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while ((uVar3 < 0x17c) &&
            (uVar11 = (uint)*(ushort *)(uVar3 * 4 + 0x8585c34), uVar11 != 0xffff));
  }
  else if (arg1 == 3) {
    uVar11 = 0;
    local_24 = arg2 + 1;
    do {
      uVar3 = (0xb - uVar11) * 0xa0000 - 0x10000 >> 0x10;
      if (uVar11 == 10) {
        local_28 = 1;
      }
      else {
        local_28 = (10 - uVar11) * 0xa0000 >> 0x10;
      }
      if (100 < uVar3) {
        uVar3 = 200;
      }
      uVar9 = 0;
      uVar11 = uVar11 + 1;
      do {
        uVar10 = uVar9 & 0xffff;
        iVar4 = sub_080BF648(uVar10);
        if (((local_28 <= *(byte *)(iVar4 + 1)) && (*(byte *)(iVar4 + 1) <= uVar3)) &&
           ((uVar7 = sub_080C2600(uVar10), (uVar7 & 0xffff) == uVar9 &&
            (iVar4 = sub_080DD248(uVar10), iVar4 != 0)))) {
          uVar5 = sub_080C2600(uVar10);
          *puVar13 = (ushort)uVar5;
          puVar13 = puVar13 + 1;
        }
        iVar4 = local_24;
        uVar9 = uVar9 + 1;
      } while (uVar9 < 0x17c);
    } while (uVar11 < 0xb);
    uVar11 = 0;
    puVar13 = (ushort *)0x203b554;
    do {
      if (*puVar13 == 0xffff) {
        DAT_02039a1c._0_2_ = 0;
        break;
      }
      uVar3 = iVar4 * 0xa0000 - 0x10000U >> 0x10;
      iVar8 = sub_080BF648(*puVar13 & 0x7fff);
      if (arg2 == 0) {
        uVar9 = 1;
      }
      else {
        uVar9 = arg2 * 0xa0000 >> 0x10;
      }
      if (100 < uVar3) {
        uVar3 = 200;
      }
      if ((uVar9 <= *(byte *)(iVar8 + 1)) && (*(byte *)(iVar8 + 1) <= uVar3)) {
        DAT_02039a1c._0_2_ = (short)uVar11;
        DAT_02039a1c._2_2_ = 1;
        break;
      }
      puVar13 = puVar13 + 1;
      uVar11 = uVar11 + 1;
    } while (uVar11 < 0x17c);
    iVar4 = local_24;
    uVar11 = 0;
    if (DAT_0203b554 != -1) {
      puVar13 = (ushort *)0x203b554;
      do {
        uVar3 = (uint)(iVar4 * 0xa0000) >> 0x10;
        if (100 < uVar3) {
          uVar3 = 200;
        }
        iVar8 = sub_080BF648(*puVar13 & 0x7fff);
        if (*(byte *)(iVar8 + 1) < uVar3) {
          if ((arg2 != 0) &&
             (iVar8 = sub_080BF648(*puVar13 & 0x7fff), (uint)*(byte *)(iVar8 + 1) < arg2 * 10)) {
            uVar2 = *puVar13;
            goto LAB_080db86c;
          }
        }
        else {
          uVar2 = *puVar13;
LAB_080db86c:
          *puVar13 = uVar2 | 0x8000;
        }
        puVar13 = puVar13 + 1;
        uVar11 = uVar11 + 1;
      } while ((uVar11 < 0x17c) && (*puVar13 != 0xffff));
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080db89a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DB8A4 @ 0x080DB8A4

int sub_080DB8A4(void)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  psVar1 = (short *)0x203b554;
  do {
    if (*psVar1 != -1) {
      iVar3 = iVar3 + 1;
    }
    psVar1 = psVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x17c);
  return iVar3;
}


// sub_080DB8D4 @ 0x080DB8D4

int sub_080DB8D4(void)

{
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar3 = 0;
  puVar2 = (ushort *)0x203b554;
  do {
    if ((*puVar2 != 0xffff) && (iVar1 = sub_080C2644(*puVar2 & 0x7fff), iVar1 != 0)) {
      iVar4 = iVar4 + 1;
    }
    puVar2 = puVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x17c);
  return iVar4;
}


// sub_080DB920 @ 0x080DB920

void sub_080DB920(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080DB8A4();
  *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 != 0);
  return;
}


// sub_080DB938 @ 0x080DB938

void sub_080DB938(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  uint arg3;
  
  iVar2 = sub_080BF648(DAT_02039a18 & 0xffff);
  arg3 = 0x7e;
  iVar3 = sub_080C2644(DAT_02039a18);
  psVar5 = (short *)0x858325a;
  if (iVar3 != 0) {
    psVar5 = (short *)(iVar2 + 0x22);
  }
  uVar4 = 0;
  sVar1 = *psVar5;
  while( true ) {
    if (sVar1 == 0) {
      return;
    }
    FontSprite_DrawGlyph((uint)(ushort)psVar5[uVar4],0,0,arg3);
    arg3 = arg3 + 0xc & 0xffff;
    uVar4 = uVar4 + 1 & 0xffff;
    if (7 < uVar4) break;
    sVar1 = psVar5[uVar4];
  }
  return;
}


// sub_080DB9AC @ 0x080DB9AC

void sub_080DB9AC(void)

{
  sub_080AD0FC(0x858326c,0xffff);
  return;
}


// sub_080DB9C4 @ 0x080DB9C4

void sub_080DB9C4(undefined4 arg0)

{
  short *arg0_00;
  uint uVar1;
  
  uVar1 = 0;
  do {
    arg0_00 = (short *)(uVar1 * 100 + 0x2009004);
    if ((*arg0_00 != 0) && ((&DAT_02009024)[uVar1 * 0x19] == 0x80db939)) {
      sub_080AD1FC(arg0_00);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x40);
  sub_080D9D8C();
  return;
}


// sub_080DBA04 @ 0x080DBA04

void sub_080DBA04(int arg0)

{
  *(undefined2 *)(arg0 + 0x30) = DAT_02039a24;
  *(undefined2 *)(arg0 + 0x32) = DAT_02039a26;
  return;
}


// sub_080DBA1C @ 0x080DBA1C

void sub_080DBA1C(int arg0)

{
  ushort uVar1;
  bool bVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  bVar2 = false;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (*(short *)(arg0 + 0x34) == 0) {
    if ((DAT_030031b8 & 1) != 0) {
      *(short *)(arg0 + 0x1e) = *(short *)(arg0 + 0x24) + 1;
      sub_080C51D4(0x65);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      DAT_02039a24 = *(undefined2 *)(arg0 + 0x30);
      DAT_02039a26 = *(undefined2 *)(arg0 + 0x32);
      goto LAB_080dbc5e;
    }
    if ((DAT_030031b8 & 2) != 0) {
      *(undefined2 *)(arg0 + 0x1e) = 2;
      *(undefined2 *)(arg0 + 0x24) = 1;
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      goto LAB_080dbc5e;
    }
    if ((DAT_03003964 & 0x40) == 0) {
      if ((DAT_030031b8 & 0x10) == 0) {
        if ((DAT_03003964 & 0x80) == 0) goto LAB_080dbc5e;
        if (*(short *)(arg0 + 0x24) == 1) {
          sVar3 = 0;
        }
        else {
          sVar3 = *(short *)(arg0 + 0x24) + 1;
        }
        *(short *)(arg0 + 0x24) = sVar3;
      }
      else {
        *(undefined2 *)(arg0 + 0x34) = 1;
      }
    }
    else if (*(short *)(arg0 + 0x24) == 0) {
      *(undefined2 *)(arg0 + 0x24) = 1;
    }
    else {
      *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
    }
  }
  else {
    uVar5 = sub_080DB8A4();
    uVar5 = uVar5 & 0xffff;
    if (DAT_02039a1c._2_2_ == 0) {
      uVar5 = 1;
    }
    uVar7 = uVar5;
    if (5 < uVar5) {
      uVar7 = 6;
    }
    if (((DAT_030031b8 & 1) != 0) && (DAT_02039a1c._2_2_ == 1)) {
      iVar6 = sub_080C2644(*(ushort *)
                            (((uint)*(ushort *)(arg0 + 0x30) + (uint)*(ushort *)(arg0 + 0x32)) * 2 +
                            0x203b554) & 0x7fff);
      if (iVar6 == 0) {
        sub_080C51D4(0x66);
      }
      else {
        bVar2 = true;
        sub_080C51D4(0x65);
        *(undefined2 *)(arg0 + 0x1e) = 3;
        *(undefined2 *)(arg0 + 0x1c) = 1;
      }
      goto LAB_080dbc5e;
    }
    if ((DAT_030031b8 & 2) != 0) {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1e) = 2;
      *(undefined2 *)(arg0 + 0x1c) = 1;
      goto LAB_080dbc5e;
    }
    if ((DAT_03003964 & 0x40) == 0) {
      if ((DAT_03003964 & 0x80) == 0) {
        if ((DAT_030031b8 & 0x20) != 0) {
          *(ushort *)(arg0 + 0x34) = DAT_03003964 & 0x80;
          goto LAB_080dbc0e;
        }
        if (((DAT_03003964 & 0x200) == 0) || (uVar5 < 7)) {
          if (((DAT_03003964 & 0x100) != 0) && (6 < uVar5)) {
            sVar3 = *(short *)(arg0 + 0x30);
            uVar1 = *(ushort *)(arg0 + 0x32);
            if (sVar3 == 5) {
              if ((int)(uVar1 + 0xb) < (int)(uVar5 - 1)) {
                sVar4 = uVar1 + 6;
              }
              else {
                sVar4 = (short)uVar5 + -6;
              }
              *(short *)(arg0 + 0x32) = sVar4;
            }
            else {
              *(undefined2 *)(arg0 + 0x30) = 5;
            }
            if ((sVar3 != *(short *)(arg0 + 0x30)) ||
               ((uint)uVar1 != (uint)*(ushort *)(arg0 + 0x32))) {
              bVar2 = true;
              sub_080C51D4(100);
            }
          }
          goto LAB_080dbc5e;
        }
        sVar3 = *(short *)(arg0 + 0x30);
        uVar1 = *(ushort *)(arg0 + 0x32);
        if (sVar3 == 0) {
          sVar4 = 0;
          if (4 < uVar1) {
            sVar4 = uVar1 - 5;
          }
          *(short *)(arg0 + 0x32) = sVar4;
        }
        else {
          *(ushort *)(arg0 + 0x30) = DAT_030031b8 & 0x20;
        }
        if ((sVar3 == *(short *)(arg0 + 0x30)) && (uVar1 == *(ushort *)(arg0 + 0x32)))
        goto LAB_080dbc5e;
      }
      else {
        uVar1 = *(ushort *)(arg0 + 0x30);
        if ((uint)uVar1 == uVar7 - 1) {
          if ((uVar1 != 5) || ((int)(uVar5 - 1) < (int)(*(ushort *)(arg0 + 0x32) + 6)))
          goto LAB_080dbc5e;
          *(ushort *)(arg0 + 0x32) = *(ushort *)(arg0 + 0x32) + 1;
        }
        else {
          *(ushort *)(arg0 + 0x30) = uVar1 + 1;
        }
      }
    }
    else if (*(short *)(arg0 + 0x30) == 0) {
      if (*(short *)(arg0 + 0x32) == 0) goto LAB_080dbc5e;
      *(short *)(arg0 + 0x32) = *(short *)(arg0 + 0x32) + -1;
    }
    else {
      *(short *)(arg0 + 0x30) = *(short *)(arg0 + 0x30) + -1;
    }
    bVar2 = true;
  }
LAB_080dbc0e:
  sub_080C51D4(100);
LAB_080dbc5e:
  if (bVar2) {
    iVar6 = (uint)*(ushort *)(arg0 + 0x30) + (uint)*(ushort *)(arg0 + 0x32);
    DAT_02039a18 = *(ushort *)(iVar6 * 2 + 0x203b554) & 0x7fff;
    DAT_02039a1c._0_2_ = (undefined2)iVar6;
    DAT_02039a24 = *(undefined2 *)(arg0 + 0x30);
    DAT_02039a26 = *(undefined2 *)(arg0 + 0x32);
    sub_080DB464();
  }
                    /* WARNING: Could not recover jumptable at 0x080dbc9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DBCAC @ 0x080DBCAC

void sub_080DBCAC(void)

{
  undefined4 in_r0;
  int iVar1;
  
  iVar1 = sub_080AD364(in_r0);
  Text_DrawSpriteString(*(undefined4 *)((uint)*(ushort *)(iVar1 + 0x24) * 4 + 0x858329c),0,0,0x14);
  return;
}


// sub_080DBCDC @ 0x080DBCDC

void sub_080DBCDC(int arg0)

{
  uint uVar1;
  int iVar2;
  undefined4 arg0_00;
  undefined4 arg1;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = sub_080DB8A4();
  if (*(short *)(arg0 + 0x34) != 0) {
    sub_080AA184(0x800853c,0,7,0);
  }
  if (DAT_02039a1c._2_2_ == 1) {
    uVar5 = 0;
    do {
      uVar3 = (uint)*(ushort *)((*(ushort *)(arg0 + 0x32) + uVar5) * 2 + 0x203b554);
      if (uVar3 != 0xffff) {
        uVar3 = uVar3 & 0x7fff;
        iVar2 = sub_080C2644(uVar3);
        if (iVar2 == 0) {
          puVar4 = (ushort *)0x858325a;
        }
        else {
          iVar2 = sub_080BF648(uVar3);
          puVar4 = (ushort *)(iVar2 + 0x22);
        }
        uVar6 = 0;
        uVar3 = 0x5c0000;
        do {
          FontSprite_DrawGlyph((uint)*puVar4,0,0,uVar3 >> 0x10);
          uVar3 = uVar3 + 0xc0000;
          puVar4 = puVar4 + 1;
          uVar6 = uVar6 + 1;
        } while (uVar6 < 8);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 6);
    if (*(short *)(arg0 + 0x32) != 0) {
      sub_080C4A4C(0,0,0xbc,0xc);
    }
    if ((int)(*(ushort *)(arg0 + 0x32) + 6) <= (int)((uVar1 & 0xffff) - 1)) {
      sub_080C4AB0(0,0,0xbc,0x5c);
    }
  }
  else {
    Text_DrawSpriteString(0x800974e,0,0,0x5c);
  }
  arg0_00 = sub_080DB8D4();
  arg1 = sub_080DB8A4();
  sub_080DA764(arg0_00,arg1,0x81,0x6a);
  if (*(short *)(arg0 + 0x34) == 0) {
    sub_080AA184(*(undefined4 *)(arg0 + 0x3c),0,7,0);
  }
  sub_080AA184(*(undefined4 *)(arg0 + 0x38),0,7,0);
  return;
}


// sub_080DBE84 @ 0x080DBE84

void sub_080DBE84(void)

{
  undefined4 in_r0;
  int iVar1;
  
  iVar1 = sub_080AD364(in_r0);
  sub_080C3818(1);
  *(undefined4 *)(iVar1 + 0xc) = 1;
  return;
}


// sub_080DBE9C @ 0x080DBE9C

void sub_080DBE9C(int arg0)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  
  sub_080AA184(0x800853c,0,7,0);
  uVar3 = 0;
  do {
    uVar1 = *(ushort *)(arg0 + 0x26) + uVar3 & 0xffff;
    if (0x28 < uVar1) {
      uVar1 = uVar1 + 1 & 0xffff;
    }
    puVar2 = (ushort *)Race_GetName(uVar1);
    uVar4 = 0;
    uVar3 = uVar3 + 1;
    uVar1 = 0x540000;
    do {
      FontSprite_DrawGlyph((uint)*puVar2,0,0,uVar1 >> 0x10);
      uVar1 = uVar1 + 0xc0000;
      puVar2 = puVar2 + 1;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 8);
  } while (uVar3 < 6);
  if (*(short *)(arg0 + 0x26) != 0) {
    sub_080C4A4C(0,0,0xb4,0xc);
  }
  if (*(ushort *)(arg0 + 0x26) + 6 < 0x2b) {
    sub_080C4AB0(0,0,0xb4,0x5c);
  }
  return;
}


// sub_080DBF7C @ 0x080DBF7C

void sub_080DBF7C(int arg0,undefined4 arg1)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  undefined4 arg0_00;
  short *psVar4;
  uint uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  psVar4 = (short *)(arg0 + 0x24);
  uVar5 = (uint)(ushort)arg1;
  uVar6 = uVar5;
  if (5 < uVar5) {
    uVar6 = 6;
  }
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) == 0) {
          if (((DAT_03003964 & 0x200) == 0) || (uVar5 < 7)) {
            if (((DAT_03003964 & 0x100) != 0) && (6 < uVar5)) {
              sVar2 = *psVar4;
              uVar1 = *(ushort *)(arg0 + 0x26);
              if (sVar2 == 5) {
                if ((int)(uVar1 + 0xb) < (int)(uVar5 - 1)) {
                  sVar3 = uVar1 + 6;
                }
                else {
                  sVar3 = (ushort)arg1 - 6;
                }
                *(short *)(arg0 + 0x26) = sVar3;
              }
              else {
                *psVar4 = 5;
              }
              if ((sVar2 != *psVar4) || ((uint)uVar1 != (uint)*(ushort *)(arg0 + 0x26))) {
                sub_080C51D4(100);
              }
            }
            goto LAB_080dc09a;
          }
          sVar2 = *(short *)(arg0 + 0x24);
          uVar1 = *(ushort *)(arg0 + 0x26);
          if (sVar2 == 0) {
            sVar3 = 0;
            if (4 < uVar1) {
              sVar3 = uVar1 - 5;
            }
            *(short *)(arg0 + 0x26) = sVar3;
          }
          else {
            *(ushort *)(arg0 + 0x24) = DAT_03003964 & 0x80;
          }
          if ((sVar2 == *psVar4) && (uVar1 == *(ushort *)(arg0 + 0x26))) goto LAB_080dc09a;
        }
        else {
          uVar1 = *(ushort *)(arg0 + 0x24);
          if ((uint)uVar1 == uVar6 - 1) {
            if ((uVar1 != 5) || ((int)(uVar5 - 1) < (int)(*(ushort *)(arg0 + 0x26) + 6)))
            goto LAB_080dc09a;
            *(ushort *)(arg0 + 0x26) = *(ushort *)(arg0 + 0x26) + 1;
          }
          else {
            *(ushort *)(arg0 + 0x24) = uVar1 + 1;
          }
        }
      }
      else if (*(short *)(arg0 + 0x24) == 0) {
        if (*(short *)(arg0 + 0x26) == 0) goto LAB_080dc09a;
        *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + -1;
      }
      else {
        *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
      }
      sub_080C51D4(100);
      goto LAB_080dc09a;
    }
    arg0_00 = 0x66;
  }
  else {
    *(short *)(arg0 + 0x1e) = *(short *)(arg0 + 0x24) + 1;
    arg0_00 = 0x65;
  }
  sub_080C51D4(arg0_00);
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_080dc09a:
                    /* WARNING: Could not recover jumptable at 0x080dc09e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DC0A0 @ 0x080DC0A0

void sub_080DC0A0(int arg0)

{
  undefined4 in_r1;
  
  Dict_BuildList(arg0,in_r1,(uint)*(ushort *)(arg0 + 0x24) + (uint)*(ushort *)(arg0 + 0x26));
  return;
}


// sub_080DC0B0 @ 0x080DC0B0

void sub_080DC0B0(int arg0)

{
  undefined4 arg0_00;
  int iVar1;
  bool bVar2;
  
  arg0_00 = sub_080AD364(arg0);
  iVar1 = sub_080AD364(arg0_00);
  bVar2 = *(char *)(arg0 + 6) == '\0';
  if (bVar2) {
    sub_080AD0FC(0x8583ca0,(uint)*(ushort *)(iVar1 + 2));
    sub_080D9B34();
    sub_080AD1FC(arg0_00);
  }
  *(ushort *)(arg0 + 0x1c) = (ushort)bVar2;
  return;
}


// sub_080DC0F0 @ 0x080DC0F0

void sub_080DC0F0(int arg0)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort *puVar4;
  
  sub_080AA184(0x800853c,0,7,0);
  uVar1 = 0;
  do {
    puVar4 = *(ushort **)((*(ushort *)(arg0 + 0x26) + uVar1) * 4 + 0x858367c);
    uVar1 = uVar1 + 1;
    if (*puVar4 != 0x301) {
      uVar3 = 0x540000;
      puVar2 = puVar4;
      do {
        FontSprite_DrawGlyph((uint)*puVar2,0,0,uVar3 >> 0x10);
        puVar2 = puVar2 + 1;
        uVar3 = uVar3 + 0xc0000;
        if (puVar4 + 2 < puVar2) break;
      } while (*puVar2 != 0x301);
    }
    if (5 < uVar1) {
      if (*(short *)(arg0 + 0x26) != 0) {
        sub_080C4A4C(0,0,0xb4,0xc);
      }
      if (*(ushort *)(arg0 + 0x26) + 6 < 10) {
        sub_080C4AB0(0,0,0xb4,0x5c);
      }
      return;
    }
  } while( true );
}


// sub_080DC1D8 @ 0x080DC1D8

void sub_080DC1D8(int arg0)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  
  sub_080AA184(0x800853c,0,7,0);
  uVar2 = 0;
  do {
    iVar1 = *(ushort *)(arg0 + 0x26) + uVar2;
    uVar5 = 0;
    uVar2 = uVar2 + 1;
    uVar4 = 0x540000;
    puVar3 = *(ushort **)(iVar1 * 4 + 0x8583788);
    do {
      FontSprite_DrawGlyph((uint)*puVar3,0,0,uVar4 >> 0x10);
      uVar4 = uVar4 + 0xc0000;
      puVar3 = puVar3 + 1;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 8);
  } while (uVar2 < 6);
  if (*(short *)(arg0 + 0x26) != 0) {
    sub_080C4A4C(0,0,0xb4,0xc);
  }
  if (*(ushort *)(arg0 + 0x26) + 6 < 0xb) {
    sub_080C4AB0(0,0,0xb4,0x5c);
  }
  return;
}


// sub_080DC2B0 @ 0x080DC2B0

void sub_080DC2B0(int arg0)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_080DB8A4();
  sub_080AA184(0x800853c,0,7,0);
  if (DAT_02039a1c._2_2_ == 1) {
    uVar7 = 0;
    do {
      uVar1 = *(ushort *)((*(ushort *)(arg0 + 0x26) + uVar7) * 2 + 0x203b554);
      if (uVar1 != 0xffff) {
        uVar5 = uVar1 & 0x7fff;
        iVar3 = sub_080C2644(uVar5);
        if (iVar3 == 0) {
          puVar4 = (ushort *)0x858325a;
        }
        else {
          iVar3 = sub_080BF648(uVar5);
          puVar4 = (ushort *)(iVar3 + 0x22);
        }
        uVar5 = 0x540000;
        puVar6 = puVar4;
        do {
          if ((uVar1 & 0x8000) == 0) {
            FontSprite_DrawGlyph((uint)*puVar6,0,0,uVar5 >> 0x10);
          }
          else {
            sub_080AC2A0((uint)*puVar6,0,0,uVar5 >> 0x10);
          }
          uVar5 = uVar5 + 0xc0000;
          puVar6 = puVar6 + 1;
        } while (puVar6 <= puVar4 + 7);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 6);
    if (*(short *)(arg0 + 0x26) != 0) {
      sub_080C4A4C(0,0,0xb4,0xc);
    }
    if ((int)(*(ushort *)(arg0 + 0x26) + 6) <= (int)((uVar2 & 0xffff) - 1)) {
      sub_080C4AB0(0,0,0xb4,0x5c);
    }
  }
  else {
    Text_DrawSpriteString(0x800974e,0,0,0x54);
  }
                    /* WARNING: Could not recover jumptable at 0x080dc410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DC418 @ 0x080DC418

void sub_080DC418(int arg0)

{
  DAT_02039a24 = *(short *)(arg0 + 0x24);
  DAT_02039a26 = *(short *)(arg0 + 0x26);
  DAT_02039a1c._0_2_ = DAT_02039a24 + DAT_02039a26;
  DAT_02039a18 = *(ushort *)
                  (((uint)*(ushort *)(arg0 + 0x24) + (uint)*(ushort *)(arg0 + 0x26)) * 2 + 0x203b554
                  ) & 0x7fff;
  sub_080DB464();
  return;
}


// sub_080DC460 @ 0x080DC460

void sub_080DC460(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar7 = (ushort *)(arg0 + 0x24);
  iVar5 = sub_080AD364(arg0);
  uVar6 = sub_080DB8A4();
  sVar4 = DAT_02039a1c._2_2_;
  uVar6 = uVar6 & 0xffff;
  bVar3 = false;
  if (DAT_02039a1c._2_2_ == 0) {
    uVar6 = 1;
  }
  uVar8 = uVar6;
  if (5 < uVar6) {
    uVar8 = 6;
  }
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (((DAT_030031b8 & 1) == 0) || (sVar4 != 1)) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) == 0) {
          if (((DAT_03003964 & 0x200) == 0) || (uVar6 < 7)) {
            if (((DAT_03003964 & 0x100) != 0) && (6 < uVar6)) {
              uVar1 = *puVar7;
              uVar2 = *(ushort *)(arg0 + 0x26);
              if (uVar1 == 5) {
                if ((int)(uVar2 + 0xb) < (int)(uVar6 - 1)) {
                  sVar4 = uVar2 + 6;
                }
                else {
                  sVar4 = (short)uVar6 + -6;
                }
                *(short *)(arg0 + 0x26) = sVar4;
              }
              else {
                *puVar7 = 5;
              }
              if ((uVar1 != *puVar7) || ((uint)uVar2 != (uint)*(ushort *)(arg0 + 0x26))) {
                bVar3 = true;
                sub_080C51D4(100);
              }
            }
            goto LAB_080dc5b4;
          }
          uVar1 = *puVar7;
          uVar2 = *(ushort *)(arg0 + 0x26);
          if (uVar1 == 0) {
            sVar4 = 0;
            if (4 < uVar2) {
              sVar4 = uVar2 - 5;
            }
            *(short *)(arg0 + 0x26) = sVar4;
          }
          else {
            *puVar7 = DAT_03003964 & 0x80;
          }
          if ((uVar1 == *puVar7) && (uVar2 == *(ushort *)(arg0 + 0x26))) goto LAB_080dc5b4;
        }
        else {
          uVar1 = *puVar7;
          if ((uint)uVar1 == uVar8 - 1) {
            if ((uVar1 != 5) || ((int)(uVar6 - 1) < (int)(*(ushort *)(arg0 + 0x26) + 6)))
            goto LAB_080dc5b4;
            *(ushort *)(arg0 + 0x26) = *(ushort *)(arg0 + 0x26) + 1;
          }
          else {
            *puVar7 = uVar1 + 1;
          }
        }
      }
      else if (*puVar7 == 0) {
        if (*(short *)(arg0 + 0x26) == 0) goto LAB_080dc5b4;
        *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + -1;
      }
      else {
        *puVar7 = *puVar7 - 1;
      }
      bVar3 = true;
      sub_080C51D4(100);
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined1 *)(iVar5 + 6) = 1;
    }
  }
  else {
    bVar3 = true;
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    *(undefined1 *)(iVar5 + 6) = 0;
  }
LAB_080dc5b4:
  if (bVar3) {
    sub_080DC418(arg0);
  }
                    /* WARNING: Could not recover jumptable at 0x080dc5c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DC5C8 @ 0x080DC5C8

void sub_080DC5C8(int arg0)

{
  short sVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_02039a1c._2_2_ == 1) {
    uVar2 = sub_080DB8A4();
    if ((uVar2 & 0xffff) < 7) {
      *(ushort *)(arg0 + 0x24) = (ushort)DAT_02039a1c;
    }
    else if ((int)((uVar2 & 0xffff) - 7) < (int)(uint)(ushort)DAT_02039a1c) {
      sVar1 = ((ushort)DAT_02039a1c + 6) - (short)uVar2;
      *(ushort *)(arg0 + 0x26) = (ushort)DAT_02039a1c - sVar1;
      *(short *)(arg0 + 0x24) = sVar1;
    }
    else {
      *(ushort *)(arg0 + 0x26) = (ushort)DAT_02039a1c;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x26) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080dc614. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DC618 @ 0x080DC618

void sub_080DC618(int arg0)

{
  undefined4 arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          if (*(short *)(arg0 + 0x24) == 2) {
            *(ushort *)(arg0 + 0x24) = DAT_03003964 & 0x40;
          }
          else {
            *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + 1;
          }
          sub_080C51D4(100);
        }
      }
      else {
        if (*(short *)(arg0 + 0x24) == 0) {
          *(undefined2 *)(arg0 + 0x24) = 2;
        }
        else {
          *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
        }
        sub_080C51D4(100);
      }
      goto LAB_080dc69e;
    }
    arg0_00 = 0x66;
  }
  else {
    *(short *)(arg0 + 0x1e) = *(short *)(arg0 + 0x24) + 1;
    arg0_00 = 0x65;
  }
  sub_080C51D4(arg0_00);
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_080dc69e:
                    /* WARNING: Could not recover jumptable at 0x080dc6a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DC6A4 @ 0x080DC6A4

void sub_080DC6A4(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6010000;
  REG_DMA3CNT = 0x84001400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080DC6C8 @ 0x080DC6C8

uint sub_080DC6C8(uint arg0)

{
  return arg0 & 0xffff;
}


// sub_080DC6D0 @ 0x080DC6D0

void sub_080DC6D0(undefined4 arg0,int arg1)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  undefined *arg0_00;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_2c;
  char *local_28;
  dword dStack_24;
  
  uVar6 = 0;
  uVar1 = sub_080DC6C8(DAT_02039a18 & 0xffff);
  pcVar2 = (char *)sub_080BF648(uVar1 & 0xffff);
  local_28 = pcVar2 + 0x11;
  DAT_03000038 = DAT_03000038 | 0x3f;
  local_2c = 0;
  CpuSet(&local_2c,0x200f874,0x5002000);
  if (arg1 == 0) {
    sub_080CCE5C(0x8583a58,0,2,4);
    uVar1 = Race_GetParentId((int)*pcVar2);
    iVar3 = ParentRace_GetName(uVar1 & 0xffff);
    if (iVar3 != 0) {
      Text_DrawStringTinted(iVar3,0x200f874,4,0xe);
    }
    iVar3 = Race_GetName((int)*pcVar2 & 0xffff);
    if (iVar3 != 0) {
      Text_DrawStringTinted(iVar3,0x200f874,4,0x1d);
    }
    uVar1 = 0;
    uVar7 = 4;
    puVar4 = (ushort *)(pcVar2 + 0x22);
    do {
      Font_DrawGlyphTinted((uint)*puVar4,0x200f874,uVar7 & 0xffff,0x2c);
      uVar7 = uVar7 + 0xc;
      puVar4 = puVar4 + 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 8);
    if (*pcVar2 < '\r') {
      arg0_00 = (undefined *)0x8583a28;
    }
    else {
      arg0_00 = (undefined *)0x8583a48;
      if (*pcVar2 < '\x1b') {
        arg0_00 = &DAT_08583a38;
      }
    }
    Text_DrawStringTinted(arg0_00,0x200f874,4,0x3b);
    uVar1 = sub_0815B864();
    iVar3 = sub_080C06AC(uVar1 & 0xffff);
    if (iVar3 != 0) {
      Text_DrawStringTinted(iVar3,0x200f874,4,0x4b);
    }
    sub_080CCE5C(0x8583a60,0x6a,2,4);
    uVar1 = 0;
    do {
      if ((byte)local_28[uVar1] != 0xff) {
        sub_080CD1F8((uint)(byte)local_28[uVar1],0x6e,uVar6 + 0xe & 0xffff);
        uVar6 = uVar6 + 0xf & 0xffff;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 7);
    uVar1 = 0;
    do {
      pcVar2 = local_28 + uVar1;
      uVar1 = uVar1 + 1;
      if (*pcVar2 == -1) {
        uVar5 = 0;
        uVar7 = 0x6e0000;
        do {
          Font_DrawGlyphTinted(0x3c,0x200f874,uVar7 >> 0x10,uVar6 + 0xe & 0xffff);
          uVar7 = uVar7 + 0xc0000;
          uVar5 = uVar5 + 1;
        } while (uVar5 < 8);
        uVar6 = uVar6 + 0xf & 0xffff;
      }
    } while (uVar1 < 7);
    sub_080AC4E4(0x81b1db8,0x200f874,0,0);
  }
  else {
    dStack_24 = 0x203a454;
    uVar1 = sub_080DC6C8(DAT_02039a18 & 0xffff);
    sub_080C0444(&DAT_0203a4dc,4,uVar1 & 0xffff);
    sub_080CCE5C(0x8583a68,0,2,4);
    sub_080CCEC8(0x8583a70,4,0x10,4);
    sub_080CCFC4((uint)(byte)pcVar2[1],0x45,0x10,0);
    sub_080CCEC8(0x8583a74,4,0x1f,4);
    sub_080CCFC4((int)*(short *)(pcVar2 + 2),0x45,0x1f,0);
    sub_080CCEC8(0x8583a78,4,0x2e,4);
    sub_080CCFC4((int)*(short *)(pcVar2 + 4),0x45,0x2e,0);
    sub_080CCEC8(0x8583a7c,4,0x3d,4);
    sub_080CCFC4((uint)(byte)pcVar2[0x1d],0x45,0x3d,0);
    Font_DrawGlyphTinted(0x10cb,0x200f874,0x55,0xe);
    sub_080CCFC4((int)pcVar2[6],0x6d,0x11,0);
    Font_DrawGlyphTinted(0xcba,0x200f874,0x7e,0xe);
    sub_080CCFC4((int)pcVar2[7],0x96,0x11,0);
    Font_DrawGlyphTinted(0xfc3,0x200f874,0x55,0x1d);
    sub_080CCFC4((int)pcVar2[8],0x6d,0x20,0);
    Font_DrawGlyphTinted(0xc5c,0x200f874,0x7e,0x1d);
    sub_080CCFC4((int)pcVar2[9],0x96,0x20,0);
    Font_DrawGlyphTinted(0xc3c,0x200f874,0x55,0x2c);
    sub_080CCFC4((int)pcVar2[10],0x6d,0x2f,0);
    Font_DrawGlyphTinted(0x606,0x200f874,0x7e,0x2c);
    sub_080CCFC4((int)pcVar2[0xb],0x96,0x2f,0);
    Font_DrawGlyphTinted(0x8f1,0x200f874,4,0x50);
    Font_DrawGlyphTinted(0x861,0x200f874,0x10,0x50);
    sub_080CCFC4((int)*(short *)(dStack_24 + 0xd0),0x45,0x52,0);
    Font_DrawGlyphTinted(0xffe,0x200f874,4,0x5f);
    Font_DrawGlyphTinted(0xcd3,0x200f874,0x10,0x5f);
    sub_080CCFC4((int)*(short *)(dStack_24 + 0xd2),0x45,0x61,0);
    Font_DrawGlyphTinted(0xfa9,0x200f874,4,0x6e);
    Font_DrawGlyphTinted(0x8c3,0x200f874,0x10,0x6e);
    sub_080CCFC4((int)*(short *)(dStack_24 + 0xd8),0x45,0x70,0);
    Font_DrawGlyphTinted(0x699,0x200f874,4,0x7d);
    Font_DrawGlyphTinted(0xeb7,0x200f874,0x10,0x7d);
    sub_080CCFC4((int)*(short *)(dStack_24 + 0xda),0x45,0x7f,0);
    Font_DrawGlyphTinted(0xfc3,0x200f874,0x55,0x50);
    Font_DrawGlyphTinted(0xf81,0x200f874,0x61,0x50);
    Font_DrawGlyphTinted(0x5bb,0x200f874,0x6d,0x50);
    Font_DrawGlyphTinted(0x10cb,0x200f874,0x79,0x50);
    sub_080CCFC4((int)*(short *)(dStack_24 + 0xdc),0x96,0x52,0);
    Font_DrawGlyphTinted(0xfc3,0x200f874,0x55,0x5f);
    Font_DrawGlyphTinted(0xf81,0x200f874,0x61,0x5f);
    Font_DrawGlyphTinted(0x8d7,0x200f874,0x6d,0x5f);
    Font_DrawGlyphTinted(0x672,0x200f874,0x79,0x5f);
    sub_080CCFC4((int)*(short *)(dStack_24 + 0xde),0x96,0x61,0);
    sub_080AC4E4(0x81b1d98,0x200f874,0,0);
  }
  sub_080ACFCC(3,0x81b6ed0,0x30030b0,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80dc6a5,1);
                    /* WARNING: Could not recover jumptable at 0x080dcb92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DCC04 @ 0x080DCC04

void sub_080DCC04(int arg0,int arg1)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if (((DAT_03003964 & 0x40) == 0) || (arg1 != 1)) {
        if (((DAT_03003964 & 0x80) != 0) && (arg1 == 0)) {
          *(undefined2 *)(arg0 + 0x1c) = 1;
          *(undefined2 *)(arg0 + 0x1e) = 1;
          sub_080C51D4(100);
        }
      }
      else {
        *(undefined2 *)(arg0 + 0x1c) = 1;
        *(undefined2 *)(arg0 + 0x1e) = 1;
        sub_080C51D4(100);
      }
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  return;
}


// sub_080DCC78 @ 0x080DCC78

void sub_080DCC78(void)

{
  sub_080AA184(0x8008c54,0,8,0);
  sub_080AA184(0x8008c64,0,8,0);
  sub_080AA184(0x8008c7c,0,8,0);
  sub_080AA184(0x8008c8c,0,8,0);
  sub_080AA184(0x8008c9c,0,8,0);
  sub_080AA184(0x8008cb4,0,8,0);
  sub_080AA184(0x8008cc4,0,8,0);
  sub_080AA184(0x8008cd4,0,8,0);
  sub_080AA184(0x8008cec,0,8,0);
  return;
}


// sub_080DCD74 @ 0x080DCD74

void sub_080DCD74(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2003000;
  REG_DMA3DAD = 0x600ec00;
  REG_DMA3CNT = 0x84000500;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x857d5c0;
  REG_DMA3DAD = 0x6012f00;
  REG_DMA3CNT = 0x84000020;
  uVar1 = REG_DMA3CNT;
  sub_080D9D24();
  return;
}


// sub_080DCDB8 @ 0x080DCDB8

void sub_080DCDB8(int arg0)

{
  DAT_03000038 = DAT_03000038 | 0x3f;
  sub_080AB2F4(0x85805c0,0x201d874,0x360,7);
  sub_080ACFCC(3,0x8581140,0x3002e90,0x20);
  sub_080ACFCC(3,0x8581240,&DAT_030030d0,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80dcd75,1);
  *(undefined2 *)(arg0 + 0x24) = 0;
  *(undefined2 *)(arg0 + 0x26) = 4;
  return;
}


// sub_080DCE4C @ 0x080DCE4C

void sub_080DCE4C(void)

{
  sub_080AF218(0x24,*(undefined4 *)(DAT_02039a18 * 0x14 + 0x8583e84));
  return;
}


// sub_080DCE70 @ 0x080DCE70

void sub_080DCE70(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_03004550 == 0x24);
  return;
}


// sub_080DCE8C @ 0x080DCE8C

void sub_080DCE8C(int arg0)

{
  short sVar1;
  
  sVar1 = *(short *)(arg0 + 0x26) + -1;
  *(short *)(arg0 + 0x26) = sVar1;
  if (sVar1 == 0) {
    *(undefined2 *)(arg0 + 0x26) = 4;
    sVar1 = *(short *)(arg0 + 0x24);
    *(short *)(arg0 + 0x24) = sVar1 + 1;
    if (sVar1 == 2) {
      *(undefined2 *)(arg0 + 0x24) = 0;
    }
  }
  sub_080AA184(*(undefined4 *)((uint)*(ushort *)(arg0 + 0x24) * 4 + 0x8583bec),0,9,0);
  sub_080AA184(*(undefined4 *)((uint)*(ushort *)(arg0 + 0x24) * 4 + 0x8583bec),0,9,0);
  return;
}


// sub_080DCF20 @ 0x080DCF20

void sub_080DCF20(void)

{
  uint uVar1;
  
  uVar1 = sub_080DB8A4();
  if ((uVar1 & 0xffff) < 7) {
    DAT_02039a24 = (ushort)DAT_02039a1c;
    DAT_02039a26 = 0;
  }
  else if ((int)((uVar1 & 0xffff) - 7) < (int)(uint)(ushort)DAT_02039a1c) {
    DAT_02039a24 = ((ushort)DAT_02039a1c + 6) - (short)uVar1;
    DAT_02039a26 = (ushort)DAT_02039a1c - DAT_02039a24;
  }
  else {
    DAT_02039a26 = (ushort)DAT_02039a1c;
    DAT_02039a24 = 0;
  }
  return;
}


// sub_080DCF80 @ 0x080DCF80

void sub_080DCF80(int arg0)

{
  bool bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  psVar6 = (short *)(arg0 + 0x24);
  uVar3 = sub_080DB8A4();
  bVar1 = false;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (((DAT_030031b8 & 1) != 0) && (*(short *)(arg0 + 0x36) == 0)) {
    iVar4 = sub_080C2644(DAT_02039a18);
    if (iVar4 == 0) {
      sub_080C51D4(0x66);
    }
    else {
      *(short *)(arg0 + 0x1e) = *(short *)(arg0 + 0x24) + 1;
      sub_080C51D4(0x65);
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    goto LAB_080dd0a0;
  }
  if (((DAT_030031b8 & 2) != 0) && (*(short *)(arg0 + 0x36) == 0)) {
    sub_080C51D4(0x66);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    goto LAB_080dd0a0;
  }
  if (((DAT_03003964 & 0x40) == 0) || (*(short *)(arg0 + 0x36) != 0)) {
    if (((DAT_03003964 & 0x80) == 0) || (*(short *)(arg0 + 0x36) != 0)) {
      if (((DAT_03003964 & 0x100) == 0) || (*(short *)(arg0 + 0x36) != 0)) {
        if (((DAT_03003964 & 0x200) == 0) || (*(short *)(arg0 + 0x36) != 0)) goto LAB_080dd0a0;
        uVar5 = (uint)(ushort)DAT_02039a1c;
        if ((ushort)DAT_02039a1c == 0) {
          uVar5 = uVar3 & 0xffff;
        }
        DAT_02039a1c._0_2_ = (short)uVar5 - 1;
      }
      else if ((uint)(ushort)DAT_02039a1c == (uVar3 & 0xffff) - 1) {
        DAT_02039a1c._0_2_ = 0;
      }
      else {
        DAT_02039a1c._0_2_ = (ushort)DAT_02039a1c + 1;
      }
      sub_080DCF20();
      bVar1 = true;
      goto LAB_080dd0a0;
    }
    if (*psVar6 != 1) {
      sVar2 = *psVar6 + 1;
      goto LAB_080dd03c;
    }
    *psVar6 = 0;
  }
  else {
    if (*psVar6 == 0) {
      sVar2 = 1;
    }
    else {
      sVar2 = *psVar6 + -1;
    }
LAB_080dd03c:
    *psVar6 = sVar2;
  }
  sub_080C51D4(100);
LAB_080dd0a0:
  if (bVar1) {
    DAT_02039a18 = *(ushort *)((uint)(ushort)DAT_02039a1c * 2 + 0x203b554) & 0x7fff;
    sub_080DB464();
    *(undefined2 *)(arg0 + 0x36) = 0x1e;
  }
  if (*(short *)(arg0 + 0x36) != 0) {
    *(short *)(arg0 + 0x36) = *(short *)(arg0 + 0x36) + -1;
  }
  if ((DAT_030031bc >> 3 & 1) == 0) {
    sub_080AA184(0x8008784,0,7,0);
    sub_080AA184(0x8008750,0,7,0);
  }
  else {
    sub_080AA184(0x80087a0,0,7,0);
    sub_080AA184(0x800876c,0,7,0);
  }
                    /* WARNING: Could not recover jumptable at 0x080dd154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DD160 @ 0x080DD160

void sub_080DD160(int arg0)

{
  undefined4 arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          if (*(short *)(arg0 + 0x24) == 1) {
            *(ushort *)(arg0 + 0x24) = DAT_03003964 & 0x40;
          }
          else {
            *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + 1;
          }
          sub_080C51D4(100);
        }
      }
      else {
        if (*(short *)(arg0 + 0x24) == 0) {
          *(undefined2 *)(arg0 + 0x24) = 1;
        }
        else {
          *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
        }
        sub_080C51D4(100);
      }
      goto LAB_080dd1de;
    }
    arg0_00 = 0x66;
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = *(undefined2 *)(arg0 + 0x24);
    arg0_00 = 0x65;
  }
  sub_080C51D4(arg0_00);
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_080dd1de:
                    /* WARNING: Could not recover jumptable at 0x080dd1e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DD1E4 @ 0x080DD1E4

void sub_080DD1E4(void)

{
  undefined4 in_r0;
  undefined4 arg0;
  int iVar1;
  
  arg0 = sub_080AD364(in_r0);
  iVar1 = sub_080AD364(arg0);
  sub_080C3818(1);
  sub_080AD1FC(arg0);
  *(undefined4 *)(iVar1 + 0xc) = 1;
  return;
}


// sub_080DD208 @ 0x080DD208

void sub_080DD208(void)

{
  sub_080AB0F0(0x1e0,0x10,1);
  return;
}


// sub_080DD21C @ 0x080DD21C

undefined4 sub_080DD21C(uint arg0)

{
  undefined4 uVar1;
  
  if ((arg0 & 0xffff) < 0x17c) {
    uVar1 = *(undefined4 *)((arg0 & 0xffff) * 0x14 + 0x8583e84);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080DD248 @ 0x080DD248

undefined4 sub_080DD248(uint arg0)

{
  undefined4 uVar1;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((arg0 & 0xffff) < 0x17c) {
    arg0_00 = sub_080C2600(arg0 & 0xffff);
    if (arg0_00 < 0xff) {
      uVar1 = 1;
    }
    else {
      uVar1 = sub_080DD21C(arg0_00);
    }
  }
  else {
    uVar1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080dd274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar1;
}


// sub_080DD278 @ 0x080DD278

void sub_080DD278(int arg0)

{
  *(undefined1 *)(arg0 + 0x24) = 0;
  *(undefined1 *)(arg0 + 0x25) = 1;
  *(undefined1 *)(arg0 + 0x26) = 1;
  *(undefined2 *)(arg0 + 0x36) = 0xff;
  *(undefined1 *)(arg0 + 0x27) = 0;
  *(undefined1 *)(arg0 + 0x28) = 0;
  *(undefined1 *)(arg0 + 0x29) = 0;
  *(undefined1 *)(arg0 + 0x2a) = 0;
  *(undefined1 *)(arg0 + 0x2b) = 0;
  *(undefined1 *)(arg0 + 0x2c) = 0;
  *(undefined1 *)(arg0 + 0x2d) = 0;
  *(undefined1 *)(arg0 + 0x2e) = 0;
  *(undefined1 *)(arg0 + 0x2f) = 0;
  *(undefined1 *)(arg0 + 0x32) = 0;
  *(undefined1 *)(arg0 + 0x31) = 0;
  *(undefined1 *)(arg0 + 0x30) = 0;
  *(undefined2 *)(arg0 + 0x34) = 0;
  *(undefined1 *)(arg0 + 0x54) = 0;
  m4aMPlayAllStop();
  DAT_030031b4 = 0;
  sub_080DDE2C(arg0);
  return;
}


// sub_080DD2C4 @ 0x080DD2C4

void sub_080DD2C4(void)

{
  sub_080ACFCC(3,0x8580e40,0x3002d70,0x40);
  return;
}


// sub_080DD2E8 @ 0x080DD2E8

void sub_080DD2E8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6012800;
  REG_DMA3CNT = 0x84001200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080DD30C @ 0x080DD30C

void sub_080DD30C(int arg0)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  byte *pbVar8;
  char *pcVar9;
  
  pcVar9 = (char *)(arg0 + 0x24);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (*pcVar9 == '\x03') {
    if (*(char *)(arg0 + 0x2f) != '\0') {
      return;
    }
    *(undefined2 *)(arg0 + 0x1c) = 1;
    return;
  }
  if ((*pcVar9 == '\x02') &&
     (sVar4 = *(short *)(arg0 + 0x34) + 1, *(short *)(arg0 + 0x34) = sVar4, 0xb4 < sVar4)) {
    *(undefined2 *)(arg0 + 0x34) = 0;
    *pcVar9 = '\0';
  }
  uVar6 = DAT_030031b8 & 1;
  if ((DAT_030031b8 & 1) == 0) {
    uVar5 = DAT_030031b8 & 2;
    if ((DAT_030031b8 & 2) == 0) {
      bVar3 = (byte)DAT_030031b8;
      if ((DAT_030031b8 & 8) == 0) {
        if ((DAT_030031b8 & 4) == 0) {
          if ((DAT_03003964 & 0x10) == 0) {
            if ((DAT_03003964 & 0x20) == 0) {
              if ((DAT_030031b8 & 0x40) == 0) {
                uVar6 = DAT_030031b8 & 0x80;
                if ((DAT_030031b8 & 0x80) != 0) {
                  if (*(char *)(arg0 + 0x25) == '\x03') {
                    cVar2 = '\x06';
                  }
                  else {
                    if ('\x03' < *(char *)(arg0 + 0x25)) goto switchD_080dd370_default;
                    cVar2 = *(char *)(arg0 + 0x25) + '\x04';
                  }
                  goto LAB_080dd60e;
                }
                uVar5 = DAT_03003964 & 0x100;
                if ((DAT_03003964 & 0x100) != 0) {
                  *(undefined1 *)(arg0 + 0x2c) = 0xf;
                  cVar2 = *(char *)(arg0 + 0x38) + '\x01';
                  *(char *)(arg0 + 0x38) = cVar2;
                  if ('\x1a' < cVar2) {
                    *(char *)(arg0 + 0x38) = (char)uVar6;
                  }
                  *(undefined1 *)(arg0 + 0x26) =
                       *(undefined1 *)(arg0 + 0x39 + (int)*(char *)(arg0 + 0x38));
                  *(undefined2 *)(arg0 + 0x36) =
                       *(undefined2 *)(*(char *)(arg0 + 0x26) * 8 + 0x85861c8);
                  if (*pcVar9 == '\x01') {
                    sub_080C5170((uint)*(ushort *)(arg0 + 0x36));
                    DAT_030031b4 = uVar6;
                    *pcVar9 = '\x01';
                    *(undefined1 *)(arg0 + 0x32) = 0;
                    *(undefined1 *)(arg0 + 0x31) = 0;
                    *(undefined1 *)(arg0 + 0x30) = 0;
                  }
                  goto LAB_080dd672;
                }
                if ((DAT_03003964 & 0x200) != 0) {
                  *(undefined1 *)(arg0 + 0x29) = 0xf;
                  iVar7 = *(byte *)(arg0 + 0x38) - 1;
                  *(char *)(arg0 + 0x38) = (char)iVar7;
                  if (iVar7 * 0x1000000 < 0) {
                    *(undefined1 *)(arg0 + 0x38) = 0x1a;
                  }
                  *(undefined1 *)(arg0 + 0x26) =
                       *(undefined1 *)(arg0 + 0x39 + (int)*(char *)(arg0 + 0x38));
                  *(undefined2 *)(arg0 + 0x36) =
                       *(undefined2 *)(*(char *)(arg0 + 0x26) * 8 + 0x85861c8);
                  if (*pcVar9 == '\x01') {
                    sub_080C5170((uint)*(ushort *)(arg0 + 0x36));
                    DAT_030031b4 = uVar5;
                    *pcVar9 = '\x01';
                    *(undefined1 *)(arg0 + 0x32) = 0;
                    *(undefined1 *)(arg0 + 0x31) = 0;
                    *(undefined1 *)(arg0 + 0x30) = 0;
                  }
                  sub_080C51D4(0x65);
                }
              }
              else if ('\x03' < *(char *)(arg0 + 0x25)) {
                cVar2 = *(char *)(arg0 + 0x25) + -4;
                goto LAB_080dd60e;
              }
              goto switchD_080dd370_default;
            }
            iVar7 = *(byte *)(arg0 + 0x25) - 1;
            *(char *)(arg0 + 0x25) = (char)iVar7;
            iVar7 = iVar7 * 0x1000000 >> 0x18;
            if (iVar7 < 0) {
              cVar2 = '\x03';
            }
            else {
              if (iVar7 != 3) goto LAB_080dd610;
              cVar2 = '\x06';
            }
LAB_080dd60e:
            *(char *)(arg0 + 0x25) = cVar2;
          }
          else {
            cVar2 = *(char *)(arg0 + 0x25) + '\x01';
            *(char *)(arg0 + 0x25) = cVar2;
            if (cVar2 == '\x04') {
              *(byte *)(arg0 + 0x25) = bVar3 & 4;
            }
            else if (cVar2 == '\a') {
              cVar2 = '\x04';
              goto LAB_080dd60e;
            }
          }
        }
        else {
          pbVar8 = (byte *)(arg0 + 0x54);
          bVar1 = *pbVar8;
          *pbVar8 = bVar1 + 1;
          if (2 < (byte)(bVar1 + 1)) {
            *pbVar8 = bVar3 & 8;
          }
        }
LAB_080dd610:
        sub_080C51D4(100);
      }
      else {
        *(undefined1 *)(arg0 + 0x2b) = 0xf;
        *(char *)(arg0 + 0x2a) = (char)uVar5;
        *(undefined2 *)(arg0 + 0x36) = *(undefined2 *)(*(char *)(arg0 + 0x26) * 8 + 0x85861c8);
        sub_080C5170((uint)*(ushort *)(arg0 + 0x36));
        DAT_030031b4 = uVar5;
        *pcVar9 = '\x01';
        *(undefined1 *)(arg0 + 0x32) = 0;
        *(undefined1 *)(arg0 + 0x31) = 0;
        *(undefined1 *)(arg0 + 0x30) = 0;
LAB_080dd672:
        sub_080C51D4(0x65);
      }
    }
    else {
      *(undefined1 *)(arg0 + 0x2a) = 0xf;
      cVar2 = (char)uVar6;
      *(char *)(arg0 + 0x2b) = cVar2;
      if (*pcVar9 == '\x01') {
        *pcVar9 = cVar2;
        m4aSongNumStop((uint)*(ushort *)(arg0 + 0x36));
        *(char *)(arg0 + 0x32) = cVar2;
        *(char *)(arg0 + 0x31) = cVar2;
        *(char *)(arg0 + 0x30) = cVar2;
        DAT_030031b4 = uVar6;
      }
      sub_080C51D4(0x66);
    }
    goto switchD_080dd370_default;
  }
  sub_080C51D4(0x65);
  switch(*(undefined1 *)(arg0 + 0x25)) {
  case 0:
    *(undefined1 *)(arg0 + 0x29) = 0xf;
    iVar7 = *(byte *)(arg0 + 0x38) - 1;
    *(char *)(arg0 + 0x38) = (char)iVar7;
    if (iVar7 * 0x1000000 < 0) {
      *(undefined1 *)(arg0 + 0x38) = 0x1a;
    }
    *(undefined1 *)(arg0 + 0x26) = *(undefined1 *)(arg0 + 0x39 + (int)*(char *)(arg0 + 0x38));
    *(undefined2 *)(arg0 + 0x36) = *(undefined2 *)(*(char *)(arg0 + 0x26) * 8 + 0x85861c8);
    cVar2 = *pcVar9;
    if (cVar2 != '\x01') goto LAB_080dd710;
    sub_080C5170((uint)*(ushort *)(arg0 + 0x36));
    goto LAB_080dd49a;
  case 1:
    *(undefined1 *)(arg0 + 0x2a) = 0xf;
    *(undefined1 *)(arg0 + 0x2b) = 0;
    cVar2 = *pcVar9;
    if (cVar2 != '\x01') goto LAB_080dd710;
    *pcVar9 = '\0';
    m4aSongNumStop((uint)*(ushort *)(arg0 + 0x36));
    *(undefined1 *)(arg0 + 0x32) = 0;
    *(undefined1 *)(arg0 + 0x31) = 0;
    *(undefined1 *)(arg0 + 0x30) = 0;
    DAT_030031b4 = 0;
    break;
  case 2:
    *(undefined1 *)(arg0 + 0x2b) = 0xf;
    *(undefined1 *)(arg0 + 0x2a) = 0;
    *(undefined2 *)(arg0 + 0x36) = *(undefined2 *)(*(char *)(arg0 + 0x26) * 8 + 0x85861c8);
    sub_080C5170((uint)*(ushort *)(arg0 + 0x36));
    DAT_030031b4 = 0;
    *pcVar9 = '\x01';
    *(undefined1 *)(arg0 + 0x32) = 0;
    *(undefined1 *)(arg0 + 0x31) = 0;
    *(undefined1 *)(arg0 + 0x30) = 0;
    break;
  case 3:
    *(undefined1 *)(arg0 + 0x2c) = 0xf;
    cVar2 = *(char *)(arg0 + 0x38) + '\x01';
    *(char *)(arg0 + 0x38) = cVar2;
    if ('\x1a' < cVar2) {
      *(undefined1 *)(arg0 + 0x38) = 0;
    }
    *(undefined1 *)(arg0 + 0x26) = *(undefined1 *)(arg0 + 0x39 + (int)*(char *)(arg0 + 0x38));
    *(undefined2 *)(arg0 + 0x36) = *(undefined2 *)(*(char *)(arg0 + 0x26) * 8 + 0x85861c8);
    cVar2 = *pcVar9;
    if (cVar2 != '\x01') goto LAB_080dd710;
    sub_080C5170((uint)*(ushort *)(arg0 + 0x36));
LAB_080dd49a:
    DAT_030031b4 = 0;
    *pcVar9 = '\x01';
    *(undefined1 *)(arg0 + 0x32) = 0;
    *(undefined1 *)(arg0 + 0x31) = 0;
    *(undefined1 *)(arg0 + 0x30) = 0;
    break;
  case 4:
    *(undefined1 *)(arg0 + 0x2d) = 0xf;
    cVar2 = '\x01' - *(char *)(arg0 + 0x27);
    *(char *)(arg0 + 0x27) = cVar2;
    if (cVar2 == '\x01') goto LAB_080dd4d0;
    break;
  case 5:
    *(undefined1 *)(arg0 + 0x2e) = 0xf;
    *(char *)(arg0 + 0x28) = '\x01' - *(char *)(arg0 + 0x28);
LAB_080dd4d0:
    sub_080DDE2C(arg0);
    break;
  case 6:
    *(undefined1 *)(arg0 + 0x2f) = 0xf;
    *pcVar9 = '\x03';
  }
switchD_080dd370_default:
  cVar2 = *pcVar9;
  if ((cVar2 == '\x01') &&
     (bVar3 = *(char *)(arg0 + 0x32) + 1, *(byte *)(arg0 + 0x32) = bVar3, 0x3b < bVar3)) {
    *(undefined1 *)(arg0 + 0x32) = 0;
    bVar3 = *(char *)(arg0 + 0x31) + 1;
    *(byte *)(arg0 + 0x31) = bVar3;
    if (0x3b < bVar3) {
      *(undefined1 *)(arg0 + 0x31) = 0;
      *(char *)(arg0 + 0x30) = *(char *)(arg0 + 0x30) + '\x01';
    }
  }
LAB_080dd710:
  iVar7 = *(char *)(arg0 + 0x26) * 8;
  if (((*(char *)(arg0 + 0x30) == (&DAT_085861ca)[iVar7]) &&
      ((uint)*(byte *)(arg0 + 0x31) == (byte)(&DAT_085861cb)[iVar7] - 2)) &&
     (*(char *)(arg0 + 0x32) == '\0')) {
    sub_080C51BC(8);
  }
  else if ((*(short *)(arg0 + 0x30) == *(short *)(&DAT_085861ca + iVar7)) &&
          (10 < *(byte *)(arg0 + 0x32))) {
    if (*(char *)(arg0 + 0x27) == '\x01') {
      cVar2 = *(char *)(arg0 + 0x38) + '\x01';
      *(char *)(arg0 + 0x38) = cVar2;
      if ('\x1a' < cVar2) {
        *(undefined1 *)(arg0 + 0x38) = 0;
      }
      *(undefined1 *)(arg0 + 0x26) = *(undefined1 *)(arg0 + 0x39 + (int)*(char *)(arg0 + 0x38));
      *(undefined2 *)(arg0 + 0x36) = *(undefined2 *)(*(char *)(arg0 + 0x26) * 8 + 0x85861c8);
      sub_080C5170((uint)*(ushort *)(arg0 + 0x36));
      DAT_030031b4 = 0;
      *pcVar9 = '\x01';
      *(undefined1 *)(arg0 + 0x32) = 0;
      *(undefined1 *)(arg0 + 0x31) = 0;
      *(undefined1 *)(arg0 + 0x30) = 0;
    }
    else {
      *(undefined1 *)(arg0 + 0x2a) = 0xf;
      *(undefined1 *)(arg0 + 0x2b) = 0;
      if (cVar2 == '\x01') {
        *pcVar9 = '\0';
        m4aSongNumStop((uint)*(ushort *)(arg0 + 0x36));
        *(undefined1 *)(arg0 + 0x32) = 0;
        *(undefined1 *)(arg0 + 0x31) = 0;
        *(undefined1 *)(arg0 + 0x30) = 0;
        DAT_030031b4 = 0;
      }
    }
  }
  return;
}


// sub_080DD7CC @ 0x080DD7CC

void sub_080DD7CC(int arg0)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 arg0_00;
  int iVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  char cVar9;
  uint unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar10;
  
  puVar2 = (uint *)(arg0 + 0x24);
  cVar8 = *(char *)(arg0 + 0x26);
  uVar3 = __divsi3((int)cVar8,10);
  uVar4 = __modsi3((int)cVar8,10);
  sub_080AA184(*(undefined4 *)((uVar3 & 0xff) * 4 + 0x85861a0),0,0xe,0);
  sub_080AA184(*(undefined4 *)((uVar4 & 0xff) * 4 + 0x85861a0),0,0xe,0);
  sub_080AA184(0x80087b8,0,0xe,0);
  Font_ResetGlyphSpriteCache(0x3c0);
  Text_DrawSpriteStringTinted(*(undefined4 *)(&DAT_085861cc + *(char *)(arg0 + 0x26) * 8),0,0,0x15);
  if (*(char *)(arg0 + 0x27) == '\x01') {
    sub_080AA184(0x8008958,0,0xe,0);
    sub_080AA184(0x8008c44,0,0xe,0);
  }
  cVar8 = *(char *)(arg0 + 0x54);
  if (cVar8 == '\0') {
    bVar1 = *(byte *)(arg0 + 0x30);
    uVar3 = __udivsi3((uint)bVar1,10);
    uVar4 = __umodsi3((uint)bVar1,10);
    sub_080AA184(*(undefined4 *)((uVar3 & 0xff) * 4 + 0x85861a0),0,0xe,0);
    sub_080AA184(*(undefined4 *)((uVar4 & 0xff) * 4 + 0x85861a0),0,0xe,0);
    bVar1 = *(byte *)(arg0 + 0x31);
    uVar3 = __udivsi3((uint)bVar1,10);
    uVar4 = __umodsi3((uint)bVar1,10);
    sub_080AA184(*(undefined4 *)((uVar3 & 0xff) * 4 + 0x85861a0),0,0xe,0);
    arg0_00 = *(undefined4 *)((uVar4 & 0xff) * 4 + 0x85861a0);
  }
  else if (cVar8 == '\x01') {
    iVar5 = *(char *)(arg0 + 0x26) * 8;
    iVar6 = (uint)(byte)(&DAT_085861ca)[iVar5] - (uint)*(byte *)(arg0 + 0x30);
    iVar7 = iVar6 * 0x1000000;
    cVar9 = (&DAT_085861cb)[iVar5] - *(char *)(arg0 + 0x31);
    cVar8 = (char)iVar6;
    if ((0 < iVar7 >> 0x18) && (cVar9 < '\0')) {
      cVar8 = (char)((uint)iVar7 >> 0x18) + -1;
      cVar9 = cVar9 + '<';
    }
    uVar3 = __divsi3((int)cVar8,10);
    uVar4 = __modsi3((int)cVar8,10);
    sub_080AA184(*(undefined4 *)((uVar3 & 0xff) * 4 + 0x85861a0),0,0xe,0);
    sub_080AA184(*(undefined4 *)((uVar4 & 0xff) * 4 + 0x85861a0),0,0xe,0);
    uVar3 = __divsi3((int)cVar9,10);
    uVar4 = __modsi3((int)cVar9,10);
    sub_080AA184(*(undefined4 *)((uVar3 & 0xff) * 4 + 0x85861a0),0,0xe,0);
    arg0_00 = *(undefined4 *)((uVar4 & 0xff) * 4 + 0x85861a0);
  }
  else {
    if (cVar8 != '\x02') goto LAB_080ddc24;
    uVar3 = __umodsi3((uint)*(byte *)(arg0 + 0x31),10);
    uVar4 = uVar3 & 0xff;
    uVar3 = uVar3 * 0x1000000 + 0x1000000 >> 0x18;
    if (9 < uVar3) {
      uVar3 = 0;
    }
    bVar1 = *(byte *)(arg0 + 0x32);
    if (bVar1 < 0xc) {
      unaff_r8 = 0;
LAB_080ddaf8:
      sub_080AA184(*(undefined4 *)(uVar4 * 4 + 0x85861a0),0,0xe,0);
    }
    else {
      if ((byte)(bVar1 - 0xc) < 0xc) {
        unaff_r8 = 1;
      }
      else if ((byte)(bVar1 - 0x18) < 0xc) {
        unaff_r8 = 2;
      }
      else if ((byte)(bVar1 - 0x24) < 0xc) {
        unaff_r8 = 3;
      }
      else {
        if ((byte)(bVar1 - 0x30) < 0xc) {
          unaff_r8 = 4;
        }
        if (unaff_r8 == 0) goto LAB_080ddaf8;
      }
      sub_080AA184(*(undefined4 *)(uVar3 * 4 + 0x85861a0),0,0xe,0);
    }
    if (unaff_r8 < 2) {
      sub_080AA184(*(undefined4 *)(uVar4 * 4 + 0x85861a0),0,0xe,0);
    }
    else {
      sub_080AA184(*(undefined4 *)(uVar3 * 4 + 0x85861a0),0,0xe,0);
    }
    if (unaff_r8 < 3) {
      sub_080AA184(*(undefined4 *)(uVar4 * 4 + 0x85861a0),0,0xe,0);
    }
    else {
      sub_080AA184(*(undefined4 *)(uVar3 * 4 + 0x85861a0),0,0xe,0);
    }
    if (3 < unaff_r8) {
      sub_080AA184(*(undefined4 *)(uVar3 * 4 + 0x85861a0),0,0xe,0);
      goto LAB_080ddc24;
    }
    arg0_00 = *(undefined4 *)(uVar4 * 4 + 0x85861a0);
  }
  sub_080AA184(arg0_00,0,0xe,0);
LAB_080ddc24:
  bVar10 = *(short *)puVar2 == 0x100;
  if ((*(short *)puVar2 == 0x201) && (*(byte *)(arg0 + 0x2b) < 0x3c)) {
    bVar10 = true;
  }
  if ((*puVar2 & 0xff00ff00) == 0x1000400) {
    bVar10 = true;
  }
  if ((*(char *)(arg0 + 0x25) == '\x05') && (*(char *)(arg0 + 0x28) == '\x01')) {
    bVar10 = true;
  }
  iVar5 = *(char *)(arg0 + 0x25) * 0xc;
  if (bVar10) {
    sub_080AA184(*(undefined4 *)(&DAT_08586154 + iVar5),0,0xe,0);
  }
  else {
    sub_080AA184(*(undefined4 *)(&DAT_08586150 + iVar5),0,0xe,0);
  }
  if (*(char *)(arg0 + 0x29) != '\0') {
    *(char *)(arg0 + 0x29) = *(char *)(arg0 + 0x29) + -1;
    sub_080AA184(0x8008890,0,0xe,0);
  }
  if (*(char *)(arg0 + 0x2c) != '\0') {
    *(char *)(arg0 + 0x2c) = *(char *)(arg0 + 0x2c) + -1;
    sub_080AA184(0x8008928,0,0xe,0);
  }
  cVar8 = *(char *)(arg0 + 0x2b);
  if (cVar8 == '\0') {
    if (*(char *)puVar2 == '\x01') {
      *(undefined1 *)(arg0 + 0x2b) = 0x5a;
    }
  }
  else {
    *(char *)(arg0 + 0x2b) = cVar8 + -1;
    if ((byte)(cVar8 - 1U) < 0x2d) {
      sub_080AA184(0x80088f0,0,0xe,0);
    }
  }
  if (*(char *)(arg0 + 0x2a) != '\0') {
    sub_080AA184(0x80088c0,0,0xe,0);
  }
  if (*(char *)(arg0 + 0x2f) != '\0') {
    *(char *)(arg0 + 0x2f) = *(char *)(arg0 + 0x2f) + -1;
    sub_080AA184(&DAT_08008998,0,0xe,0);
  }
  if (*(char *)(arg0 + 0x2d) != '\0') {
    *(char *)(arg0 + 0x2d) = *(char *)(arg0 + 0x2d) + -1;
    sub_080AA184(&DAT_08008948,0,0xe,0);
  }
  if (*(char *)(arg0 + 0x2e) != '\0') {
    *(char *)(arg0 + 0x2e) = *(char *)(arg0 + 0x2e) + -1;
    sub_080AA184(&DAT_08008978,0,0xe,0);
  }
                    /* WARNING: Could not recover jumptable at 0x080dde16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DDE2C @ 0x080DDE2C

void sub_080DDE2C(int arg0)

{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  
  if (*(char *)(arg0 + 0x28) == '\x01') {
    uVar4 = 0;
    iVar5 = arg0 + 0x39;
    do {
      *(char *)(iVar5 + uVar4) = (char)(uVar4 + 1);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 0x1b);
    uVar4 = 0;
    do {
      uVar2 = sub_080C2244();
      if ((uVar2 & 1) == 0) {
        uVar2 = sub_080C2244();
        uVar2 = (uVar2 & 0x1f) + 1;
        if (uVar2 < 0x1b) {
          uVar1 = *(undefined1 *)(iVar5 + uVar4);
          puVar3 = (undefined1 *)(iVar5 + uVar2);
          *(undefined1 *)(iVar5 + uVar4) = *puVar3;
          *puVar3 = uVar1;
        }
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 0x1b);
    uVar4 = 0;
    do {
      if ((int)*(char *)(arg0 + 0x26) == (uint)*(byte *)(iVar5 + uVar4)) {
        *(char *)(arg0 + 0x38) = (char)uVar4;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 0x1b);
  }
  else {
    uVar4 = 0;
    do {
      uVar2 = uVar4 + 1;
      *(char *)(arg0 + 0x39 + uVar4) = (char)uVar2;
      if ((int)*(char *)(arg0 + 0x26) == uVar2) {
        *(char *)(arg0 + 0x38) = (char)uVar4;
      }
      uVar4 = uVar2 & 0xff;
    } while (uVar4 < 0x1b);
  }
  return;
}


// sub_080DDEC8 @ 0x080DDEC8

void sub_080DDEC8(int arg0)

{
  *(undefined1 *)(arg0 + 0x2a) = 0xf;
  return;
}


// sub_080DDED0 @ 0x080DDED0

void sub_080DDED0(void)

{
  sub_080C5170(0xd);
  return;
}


// sub_080DDEDC @ 0x080DDEDC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DDEDC(void)

{
  undefined4 uVar1;
  undefined2 auStack_8 [4];
  
  DAT_0200ab04 = 1;
  REG_DISPCNT = 0x6301;
  REG_BG0CNT = 4;
  REG_BG1CNT = 0x8205;
  REG_BG2CNT = 0x48a;
  _DAT_03000030 = 0xf0;
  _DAT_03000032 = 0xf0;
  _DAT_03000034 = 0xa0;
  _DAT_03000036 = 0xa0;
  _DAT_03000038 = 0x404;
  _DAT_0300003a = 0x1f1f;
  auStack_8[0] = 0;
  REG_DMA3SAD = auStack_8;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x81002000;
  uVar1 = REG_DMA3CNT;
  REG_IE._0_2_ = 0x2003;
  REG_DISPSTAT = 0x18;
  REG_IME = 1;
  sub_080ACFF4();
  sub_080DDFAC();
  sub_080A9AB4(0x80de0dd);
  return;
}


// sub_080DDFAC @ 0x080DDFAC

void sub_080DDFAC(void)

{
  undefined4 uVar1;
  
  DAT_03000000 = 0;
  DAT_03000004 = 0;
  DAT_03000008 = 0;
  DAT_0300000c = 0;
  DAT_03000002 = 0;
  DAT_03000006 = 0;
  DAT_0300000a = 0;
  DAT_0300000e = 0;
  memset(0x30029b0,0,0x400);
  sub_08153378(0x8589c3c,0,0x40);
  memset(0x2030c74,0,0x5400);
  memcpy(0x2030c74,0x8589c7c,4);
  REG_DMA3SAD = 0x2030c74;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  memcpy(0x2030c74,0x8587830,0x820);
  REG_DMA3SAD = 0x2030c74;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  memcpy(0x2030c74,0x8589b3c,0x100);
  REG_DMA3SAD = 0x2030c74;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  DAT_020399e4._2_2_ = 4;
  DAT_02039a14._0_2_ = 0;
  DAT_02039a00._2_2_ = 0;
  DAT_020399f0 = 0;
  DAT_020399f4 = 0;
  DAT_020399e8._0_2_ = 0x100;
  DAT_020399e8._2_2_ = 0;
  DAT_020399ec._0_2_ = 0;
  DAT_020399ec._2_2_ = 0x100;
  DAT_020399f8._0_2_ = 0x38;
  DAT_020399f8._2_2_ = 8;
  DAT_020399fc._2_2_ = 8;
  DAT_02039a00._0_2_ = 8;
  DAT_020399fc._0_2_ = 0;
  DAT_02039a04._0_2_ = 0x78;
  DAT_02039a04._2_2_ = 0x48;
  DAT_02039a08._0_2_ = 0;
  DAT_02039a08._2_2_ = 0x80;
  DAT_02039a0c = 0x200;
  DAT_02039a10 = 0x200;
  DAT_02039a14._2_2_ = 0;
  return;
}


// sub_080DE0DC @ 0x080DE0DC

void sub_080DE0DC(void)

{
  uint uVar1;
  
  uVar1 = sub_080DE0F8();
  if ((uVar1 & 0xff) != 0) {
    sub_080DE208();
    sub_080AD01C();
    sub_080C22E4();
  }
  return;
}


// sub_080DE0F8 @ 0x080DE0F8

undefined4 sub_080DE0F8(void)

{
  undefined4 uVar1;
  dword arg0;
  dword arg1;
  undefined4 in_r2;
  
  switch(DAT_02039a14._2_2_) {
  case 0:
    arg0 = 0x8587130;
    arg1 = 0x2001000;
    break;
  case 1:
    LZ77UnCompWram(0x85874ec,0x2002000,in_r2);
    REG_DMA3SAD = 0x2001000;
    REG_DMA3DAD = 0x6004000;
    REG_DMA3CNT = 0x84000800;
    uVar1 = REG_DMA3CNT;
    goto LAB_080de1a0;
  case 2:
    arg0 = 0x8588050;
    arg1 = 0x2001000;
    break;
  case 3:
    arg0 = 0x85887d4;
    arg1 = 0x2002000;
    break;
  case 4:
    arg0 = 0x8588fa4;
    arg1 = 0x2003000;
    break;
  case 5:
    LZ77UnCompWram(0x858979c,0x2004000,in_r2);
    REG_DMA3SAD = 0x2001000;
    REG_DMA3DAD = 0x6008000;
    REG_DMA3CNT = 0x84000e00;
    uVar1 = REG_DMA3CNT;
    DAT_02039a14._2_2_ = DAT_02039a14._2_2_ + 1;
    DAT_020399e0 = sub_080AAEDC(1);
  default:
    return 1;
  }
  LZ77UnCompWram(arg0,arg1,in_r2);
LAB_080de1a0:
  DAT_02039a14._2_2_ = DAT_02039a14._2_2_ + 1;
  return 0;
}


// sub_080DE208 @ 0x080DE208

void sub_080DE208(void)

{
  uint uVar1;
  
  uVar1 = sub_080DE21C();
  if ((uVar1 & 0xff) != 0) {
    sub_080DE258();
  }
  return;
}


// sub_080DE21C @ 0x080DE21C

undefined4 sub_080DE21C(void)

{
  undefined4 uVar1;
  
  if (*DAT_020399e0 == 0) {
    if ((short)DAT_020399e4 == 0) {
      uVar1 = 1;
    }
    else {
      if ((short)DAT_020399e4 == 1) {
        sub_080A9AB4(0x80d9609);
      }
      uVar1 = 0;
      DAT_020399e4._0_2_ = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080DE258 @ 0x080DE258

void sub_080DE258(void)

{
  ushort uVar1;
  
  if ((DAT_030031b8 & 8) == 0) {
    sub_080DE2C0();
    sub_080DE680();
  }
  else {
    uVar1 = REG_DISPCNT;
    REG_DISPCNT = uVar1 & 0xf0ff;
    *DAT_020399e0 = 1;
    DAT_020399e4._0_2_ = 1;
    memset(0x30029b0,0,0x400);
    memset(0x3002db0,0,0x400);
    sub_080AABB0();
  }
  return;
}


// sub_080DE2C0 @ 0x080DE2C0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DE2C0(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  
  switch((short)DAT_02039a14) {
  case 0:
    DAT_03000037 = '\t';
    break;
  default:
    if (((int)((uint)DAT_020399e4._2_2_ << 0x10) >> 0x12 & 1U) == 0) goto LAB_080de5fc;
    goto LAB_080de5ee;
  case 0xb:
    DAT_03000037 = '\x11';
    break;
  case 0x18:
    DAT_03000037 = '\x1f';
    break;
  case 0x22:
    DAT_03000037 = '\'';
    break;
  case 0x2e:
    DAT_03000037 = '.';
    break;
  case 0x37:
    DAT_03000037 = '<';
    break;
  case 0x40:
    DAT_03000037 = 'J';
    break;
  case 0x4f:
    DAT_03000037 = 'Q';
    DAT_02039a08._0_2_ = 2;
    uVar2 = REG_DISPCNT;
    REG_DISPCNT = uVar2 | 0x400;
    DAT_020399e4._2_2_ = 1;
    break;
  case 0x50:
    if (DAT_020399fc._2_2_ < 0x100) {
      DAT_020399e4._2_2_ = 0x50;
      return;
    }
    break;
  case 0x51:
  case 0x5a:
    if (DAT_02039a00._2_2_ == 1) {
      DAT_020399e4._2_2_ = 0x28;
LAB_080de550:
      DAT_02039a00._2_2_ = 0;
    }
    goto LAB_080de552;
  case 0x59:
    DAT_03000037 = '\\';
    break;
  case 0x62:
    if (DAT_03000006 == 0) {
      DAT_03000037 = -0x61;
      DAT_03000035 = 0x9f;
      DAT_03000002 = -0x9f;
    }
    if (DAT_03000006 < 0xa0) {
      if ((ushort)(DAT_03000006 + 0x14) < 0x51) {
        DAT_03000006 = DAT_03000006 + 0x14;
        return;
      }
      DAT_03000006 = DAT_03000006 + 0x14;
      DAT_03000037 = DAT_03000037 + -0x14;
      return;
    }
    break;
  case 99:
    puVar3 = &REG_DISPCNT;
    uVar2 = REG_DISPCNT;
    uVar1 = 0xbfff;
    goto LAB_080de602;
  case 100:
    if (DAT_02039a00._2_2_ == 1) {
      DAT_02039a00._2_2_ = 0;
      DAT_020399e4._2_2_ = 0x50;
    }
    break;
  case 0x6e:
    if (DAT_02039a00._2_2_ == 1) {
      DAT_020399e4._2_2_ = 0x78;
      goto LAB_080de550;
    }
LAB_080de552:
    if (((int)((uint)DAT_020399e4._2_2_ << 0x10) >> 0x12 & 1U) == 0) {
LAB_080de5fc:
      puVar3 = (ushort *)0x3000038;
      uVar1 = 0xfffe;
      uVar2 = _DAT_03000038;
LAB_080de602:
      *puVar3 = uVar1 & uVar2;
    }
    else {
LAB_080de5ee:
      _DAT_03000038 = _DAT_03000038 | 1;
    }
    break;
  case 0x6f:
    DAT_020399e0 = sub_080AAF48(1);
    DAT_020399e4._0_2_ = 1;
    return;
  }
  DAT_020399e4._2_2_ = DAT_020399e4._2_2_ - 1;
  if (DAT_020399e4._2_2_ == 0) {
    DAT_020399e4._2_2_ = 8;
    DAT_02039a00._2_2_ = 1;
    DAT_02039a14._0_2_ = (short)DAT_02039a14 + 1;
    DAT_03000031 = *(undefined1 *)((short)DAT_02039a14 * 4 + 0x85864b0);
    DAT_03000035 = (&DAT_085864b1)[(short)DAT_02039a14 * 4];
    DAT_03000000 = -(ushort)*(byte *)((short)DAT_02039a14 * 4 + 0x85864b0);
    DAT_03000002 = -(ushort)(byte)(&DAT_085864b1)[(short)DAT_02039a14 * 4];
  }
  return;
}


// sub_080DE680 @ 0x080DE680

void sub_080DE680(void)

{
  short sVar1;
  undefined4 uVar2;
  
  DisplayList_Add(0x80dedd9,1);
  DAT_020399fc._2_2_ = (short)DAT_02039a08 + DAT_020399fc._2_2_;
  DAT_02039a00._0_2_ = (short)DAT_02039a08 + (short)DAT_02039a00;
  sVar1 = *(short *)(((ushort)DAT_020399fc + 0x40) * 2 + 0x815e828);
  uVar2 = sub_080A98DC((int)(short)DAT_020399fc._2_2_);
  uVar2 = sub_080A98A8((int)sVar1,(int)(short)uVar2);
  DAT_020399e8._0_2_ = (short)uVar2;
  sVar1 = *(short *)((uint)(ushort)DAT_020399fc * 2 + 0x815e828);
  uVar2 = sub_080A98DC((int)(short)DAT_020399fc._2_2_);
  uVar2 = sub_080A98A8((int)sVar1,(int)(short)uVar2);
  DAT_020399e8._2_2_ = (short)uVar2;
  sVar1 = *(short *)((uint)(ushort)DAT_020399fc * 2 + 0x815e828);
  uVar2 = sub_080A98DC((int)(short)DAT_02039a00);
  uVar2 = sub_080A98A8((int)-sVar1,(int)(short)uVar2);
  DAT_020399ec._0_2_ = (short)uVar2;
  sVar1 = *(short *)(((ushort)DAT_020399fc + 0x40) * 2 + 0x815e828);
  uVar2 = sub_080A98DC((int)(short)DAT_02039a00);
  uVar2 = sub_080A98A8((int)sVar1,(int)(short)uVar2);
  DAT_020399ec._2_2_ = (short)uVar2;
  DAT_020399f0 = (((int)(short)DAT_02039a04 - (int)(short)DAT_020399f8) * 0x100 -
                 (int)(short)DAT_02039a04 * (int)(short)DAT_020399e8) -
                 (int)DAT_020399e8._2_2_ * (int)DAT_02039a04._2_2_;
  DAT_020399f4 = (((int)DAT_02039a04._2_2_ - (int)DAT_020399f8._2_2_) * 0x100 -
                 (int)(short)DAT_020399ec * (int)(short)DAT_02039a04) -
                 (int)DAT_02039a04._2_2_ * (int)(short)uVar2;
  if (0x100 < DAT_020399fc._2_2_) {
    DAT_02039a08._0_2_ = 0;
    DAT_020399fc._2_2_ = 0x100;
    DAT_02039a00._0_2_ = 0x100;
  }
  return;
}


// sub_080DE78C @ 0x080DE78C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DE78C(void)

{
  undefined4 uVar1;
  undefined2 local_8 [4];
  
  DAT_0200ab04 = 1;
  REG_DISPCNT = 0x6701;
  REG_BG0CNT = 4;
  REG_BG1CNT = 0x205;
  REG_BG2CNT = 0x48a;
  _DAT_03000030 = 0xf0;
  _DAT_03000032 = 0xf0;
  _DAT_03000034 = 0xa0;
  _DAT_03000036 = 0xa0;
  _DAT_03000038 = 0x404;
  _DAT_0300003a = 0x1f1f;
  local_8[0] = 0;
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x81002000;
  uVar1 = REG_DMA3CNT;
  REG_IE._0_2_ = 0x2003;
  REG_DISPSTAT = 0x18;
  REG_IME = 1;
  sub_080ACFF4();
  sub_080DE85C();
  sub_080A9AB4(0x80de98d);
  return;
}


// sub_080DE85C @ 0x080DE85C

void sub_080DE85C(void)

{
  undefined4 uVar1;
  
  DAT_03000000 = 0;
  DAT_03000004 = 0;
  DAT_03000008 = 0;
  DAT_0300000c = 0;
  DAT_03000002 = 0;
  DAT_03000006 = 0;
  DAT_0300000a = 0;
  DAT_0300000e = 0;
  memset(0x30029b0,0,0x400);
  sub_08153378(0x8589c3c,0,0x40);
  memset(0x2030c74,0,0x5400);
  memcpy(0x2030c74,0x858712c,4);
  REG_DMA3SAD = 0x2030c74;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  memcpy(0x2030c74,0x8586c2c,0x500);
  REG_DMA3SAD = 0x2030c74;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  memcpy(0x2030c74,0x8589b3c,0x100);
  REG_DMA3SAD = 0x2030c74;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  DAT_020399e4._2_2_ = 4;
  DAT_02039a14._0_2_ = 0;
  DAT_02039a00._2_2_ = 0;
  DAT_020399f0 = 0;
  DAT_020399f4 = 0;
  DAT_020399e8._0_2_ = 0x100;
  DAT_020399e8._2_2_ = 0;
  DAT_020399ec._0_2_ = 0;
  DAT_020399ec._2_2_ = 0x100;
  DAT_020399f8._0_2_ = 0x38;
  DAT_020399f8._2_2_ = 8;
  DAT_020399fc._2_2_ = 0x100;
  DAT_02039a00._0_2_ = 0x100;
  DAT_020399fc._0_2_ = 0;
  DAT_02039a04._0_2_ = 0x78;
  DAT_02039a04._2_2_ = 0x48;
  DAT_02039a08._0_2_ = 0;
  DAT_02039a08._2_2_ = 0x80;
  DAT_02039a0c = 0x200;
  DAT_02039a10 = 0x200;
  DAT_02039a14._2_2_ = 0;
  return;
}


// sub_080DE98C @ 0x080DE98C

void sub_080DE98C(void)

{
  uint uVar1;
  
  uVar1 = sub_080DE9A8();
  if ((uVar1 & 0xff) != 0) {
    sub_080DEA9C();
    sub_080AD01C();
    sub_080C22E4();
  }
  return;
}


// sub_080DE9A8 @ 0x080DE9A8

undefined4 sub_080DE9A8(void)

{
  undefined4 uVar1;
  dword arg0;
  dword arg1;
  undefined4 in_r2;
  
  switch(DAT_02039a14._2_2_) {
  case 0:
    LZ77UnCompWram(0x858689c,0x2001000,in_r2);
    REG_DMA3SAD = 0x2001000;
    REG_DMA3DAD = 0x6004000;
    REG_DMA3CNT = 0x84000400;
    uVar1 = REG_DMA3CNT;
    goto LAB_080dea34;
  case 1:
    arg0 = 0x8588050;
    arg1 = 0x2001000;
    break;
  case 2:
    arg0 = 0x85887d4;
    arg1 = 0x2002000;
    break;
  case 3:
    arg0 = 0x8588fa4;
    arg1 = 0x2003000;
    break;
  case 4:
    LZ77UnCompWram(0x858979c,0x2004000,in_r2);
    REG_DMA3SAD = 0x2001000;
    REG_DMA3DAD = 0x6008000;
    REG_DMA3CNT = 0x84000e00;
    uVar1 = REG_DMA3CNT;
    DAT_02039a14._2_2_ = DAT_02039a14._2_2_ + 1;
    DAT_020399e0 = sub_080AAEDC(1);
  default:
    return 1;
  }
  LZ77UnCompWram(arg0,arg1,in_r2);
LAB_080dea34:
  DAT_02039a14._2_2_ = DAT_02039a14._2_2_ + 1;
  return 0;
}


// sub_080DEA9C @ 0x080DEA9C

void sub_080DEA9C(void)

{
  uint uVar1;
  
  uVar1 = sub_080DEAB0();
  if ((uVar1 & 0xff) != 0) {
    sub_080DEAE4();
  }
  return;
}


// sub_080DEAB0 @ 0x080DEAB0

undefined4 sub_080DEAB0(void)

{
  undefined4 uVar1;
  
  if ((*DAT_020399e0 == 0) && ((short)DAT_020399e4 != 0)) {
    if ((short)DAT_020399e4 == 1) {
      sub_080D5B8C(3);
    }
    uVar1 = 0;
    DAT_020399e4._0_2_ = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// sub_080DEAE4 @ 0x080DEAE4

void sub_080DEAE4(void)

{
  ushort uVar1;
  
  if ((DAT_030031b8 & 8) == 0) {
    sub_080DEB4C();
    sub_080DECEC();
  }
  else {
    uVar1 = REG_DISPCNT;
    REG_DISPCNT = uVar1 & 0xf0ff;
    *DAT_020399e0 = 1;
    DAT_020399e4._0_2_ = 1;
    memset(0x30029b0,0,0x400);
    memset(0x3002db0,0,0x400);
    sub_080AABB0();
  }
  return;
}


// sub_080DEB4C @ 0x080DEB4C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DEB4C(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  
  if ((short)DAT_02039a14 == 0x41) {
    DAT_03000037 = 0x33;
    goto LAB_080dec72;
  }
  if ((short)DAT_02039a14 < 0x42) {
    if ((short)DAT_02039a14 == 0x20) {
      DAT_03000037 = 0x17;
      goto LAB_080dec72;
    }
    if ((short)DAT_02039a14 < 0x21) {
      if ((short)DAT_02039a14 == 0) {
        DAT_03000037 = 9;
        goto LAB_080dec72;
      }
      if ((short)DAT_02039a14 == 0x13) {
        DAT_03000037 = 0x10;
        goto LAB_080dec72;
      }
    }
    else {
      if ((short)DAT_02039a14 == 0x2f) {
        DAT_03000037 = 0x1e;
        goto LAB_080dec72;
      }
      if ((short)DAT_02039a14 == 0x32) {
        DAT_03000037 = 0x2c;
        goto LAB_080dec72;
      }
    }
    goto joined_r0x080dec3a;
  }
  if ((short)DAT_02039a14 == 0x65) {
    DAT_03000037 = 0x4f;
    goto LAB_080dec72;
  }
  if ((short)DAT_02039a14 < 0x66) {
    if ((short)DAT_02039a14 == 0x4e) {
      DAT_03000037 = 0x3a;
      goto LAB_080dec72;
    }
    if ((short)DAT_02039a14 == 0x58) {
      DAT_03000037 = 0x48;
      goto LAB_080dec72;
    }
joined_r0x080dec3a:
    if (((int)((uint)DAT_020399e4._2_2_ << 0x10) >> 0x12 & 1U) != 0) {
      _DAT_03000038 = _DAT_03000038 | 1;
      goto LAB_080dec72;
    }
    puVar3 = (ushort *)0x3000038;
    uVar1 = 0xfffe;
    uVar2 = _DAT_03000038;
  }
  else {
    if ((short)DAT_02039a14 == 0x89) {
      if (DAT_02039a00._2_2_ == 1) {
        DAT_02039a00._2_2_ = 0;
        DAT_020399e4._2_2_ = 0x28;
      }
      goto joined_r0x080dec3a;
    }
    if (0x89 < (short)DAT_02039a14) {
      if ((short)DAT_02039a14 == 0x8a) {
        DAT_020399e0 = sub_080AAF48(1);
        DAT_020399e4._0_2_ = 1;
        return;
      }
      goto joined_r0x080dec3a;
    }
    if ((short)DAT_02039a14 != 0x6e) goto joined_r0x080dec3a;
    puVar3 = &REG_DISPCNT;
    uVar2 = REG_DISPCNT;
    uVar1 = 0xbfff;
  }
  *puVar3 = uVar1 & uVar2;
LAB_080dec72:
  DAT_020399e4._2_2_ = DAT_020399e4._2_2_ - 1;
  if (DAT_020399e4._2_2_ == 0) {
    DAT_020399e4._2_2_ = 8;
    DAT_02039a00._2_2_ = 1;
    DAT_02039a14._0_2_ = (short)DAT_02039a14 + 1;
    DAT_03000031 = *(undefined1 *)((short)DAT_02039a14 * 4 + 0x8586670);
    DAT_03000035 = (&DAT_08586671)[(short)DAT_02039a14 * 4];
    DAT_03000000 = -(ushort)*(byte *)((short)DAT_02039a14 * 4 + 0x8586670);
    DAT_03000002 = -(ushort)(byte)(&DAT_08586671)[(short)DAT_02039a14 * 4];
  }
  return;
}


// sub_080DECEC @ 0x080DECEC

void sub_080DECEC(void)

{
  short sVar1;
  undefined4 uVar2;
  
  DisplayList_Add(0x80dedd9,1);
  sVar1 = *(short *)(((ushort)DAT_020399fc + 0x40) * 2 + 0x815e828);
  uVar2 = sub_080A98DC((int)DAT_020399fc._2_2_);
  uVar2 = sub_080A98A8((int)sVar1,(int)(short)uVar2);
  DAT_020399e8._0_2_ = (short)uVar2;
  sVar1 = *(short *)((uint)(ushort)DAT_020399fc * 2 + 0x815e828);
  uVar2 = sub_080A98DC((int)DAT_020399fc._2_2_);
  uVar2 = sub_080A98A8((int)sVar1,(int)(short)uVar2);
  DAT_020399e8._2_2_ = (short)uVar2;
  sVar1 = *(short *)((uint)(ushort)DAT_020399fc * 2 + 0x815e828);
  uVar2 = sub_080A98DC((int)(short)DAT_02039a00);
  uVar2 = sub_080A98A8((int)-sVar1,(int)(short)uVar2);
  DAT_020399ec._0_2_ = (short)uVar2;
  sVar1 = *(short *)(((ushort)DAT_020399fc + 0x40) * 2 + 0x815e828);
  uVar2 = sub_080A98DC((int)(short)DAT_02039a00);
  uVar2 = sub_080A98A8((int)sVar1,(int)(short)uVar2);
  DAT_020399ec._2_2_ = (short)uVar2;
  DAT_020399f0 = (((int)(short)DAT_02039a04 - (int)(short)DAT_020399f8) * 0x100 -
                 (int)(short)DAT_02039a04 * (int)(short)DAT_020399e8) -
                 (int)DAT_020399e8._2_2_ * (int)DAT_02039a04._2_2_;
  DAT_020399f4 = (((int)DAT_02039a04._2_2_ - (int)DAT_020399f8._2_2_) * 0x100 -
                 (int)(short)DAT_020399ec * (int)(short)DAT_02039a04) -
                 (int)DAT_02039a04._2_2_ * (int)(short)uVar2;
  return;
}


// sub_080DEDD8 @ 0x080DEDD8

void sub_080DEDD8(void)

{
  REG_BG2PA = (undefined2)DAT_020399e8;
  REG_BG2PB = DAT_020399e8._2_2_;
  REG_BG2PC = (undefined2)DAT_020399ec;
  REG_BG2PD = DAT_020399ec._2_2_;
  REG_BG2X = (short)DAT_020399f0;
  DAT_0400002a = (ushort)((uint)DAT_020399f0 >> 0x10) & 0xfff;
  REG_BG2Y = (short)DAT_020399f4;
  DAT_0400002e = (ushort)((uint)DAT_020399f4 >> 0x10) & 0xfff;
  return;
}


// sub_080DEE20 @ 0x080DEE20

void sub_080DEE20(void)

{
  ushort uVar1;
  undefined4 local_1c;
  
  REG_IME = 0;
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 & 0xff3f;
  REG_IME = 1;
  REG_RCNT = 0;
  REG_SIOCNT._0_2_ = 0x2000;
  uVar1 = REG_SIOCNT._0_2_;
  REG_SIOCNT._0_2_ = uVar1 | 0x4003;
  local_1c = 0;
  CpuSet(&local_1c,0x30061c0,0x500003c);
  CpuSet(0x8032b7c,0x30062b0,0x4000010);
  CpuSet(0x80df1ed,0x30060a0,0x4000048);
  DAT_030061d4 = 0xb;
  DAT_030061d8 = 0xb;
  DAT_030061dc = &DAT_030061f0;
  DAT_030061e0 = &DAT_03006208;
  DAT_030061e4 = &DAT_03006220;
  DAT_030061e8 = &DAT_03006250;
  DAT_030061ec = &DAT_03006280;
  REG_IME = 0;
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 | 0x80;
  REG_IME = 1;
  return;
}


// sub_080DEEE8 @ 0x080DEEE8

void sub_080DEEE8(void)

{
  if (DAT_030061c0 != '\0') {
    DAT_030061c6 = 1;
  }
  return;
}


// sub_080DEF00 @ 0x080DEF00

void sub_080DEF00(void)

{
  ushort uVar1;
  
  REG_IME = 0;
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 & 0xff3f;
  REG_IME = 1;
  REG_SIOCNT._0_2_ = 0x2003;
  REG_TM3CNT = 0xabfb;
  REG_IE._2_2_ = 0xc0;
  DAT_030061c6 = 0;
  return;
}


// sub_080DEF50 @ 0x080DEF50

undefined4 sub_080DEF50(undefined4 arg0)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = REG_SIOCNT;
  if (DAT_030061c1 == 1) {
LAB_080defce:
    if (DAT_030061c2 != 0) {
      if (DAT_030061c8 < 8) {
        DAT_030061c8 = DAT_030061c8 + 1;
      }
      else {
        DAT_030061c1 = 2;
      }
    }
  }
  else {
    if (DAT_030061c1 < 2) {
      if (DAT_030061c1 != 0) goto LAB_080df006;
      if (DAT_030061d8 == 0xb) {
        if ((uVar1 & 0x88) != 8) goto LAB_080df006;
        if ((uVar1 & 4) == 0) {
          REG_IME = 0;
          uVar3 = REG_IE._0_2_;
          REG_IE._0_2_ = uVar3 & 0xff7f;
          uVar3 = REG_IE._0_2_;
          REG_IE._0_2_ = uVar3 | 0x40;
          REG_IME = 1;
          bVar2 = REG_SIOCNT._1_1_;
          REG_SIOCNT._1_1_ = bVar2 & 0xbf;
          REG_TM3CNT = 0xabfb;
          REG_IE._2_2_ = 0xc0;
          DAT_030061c0 = '\b';
        }
      }
      DAT_030061c1 = 1;
      goto LAB_080defce;
    }
    if (DAT_030061c1 != 2) goto LAB_080df006;
  }
  sub_080DF0AC(arg0);
LAB_080df006:
  DAT_030061cb = DAT_030061cb + '\x01';
  uVar6 = (uint)DAT_030061c2 << 8;
  if (DAT_030061c0 == '\b') {
    uVar6 = uVar6 | 0x80;
  }
  uVar6 = uVar6 | DAT_030061c3;
  if (DAT_030061c7 != '\0') {
    uVar6 = uVar6 | 0x1000;
  }
  uVar5 = (uint)(DAT_030061c8 >> 3) << 0xf;
  if (1 < (uVar1 & 0x3f) >> 4) {
    uVar5 = uVar5 | 0x2000;
  }
                    /* WARNING: Could not recover jumptable at 0x080df05a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar5 | uVar6);
  return uVar4;
}


// sub_080DF05C @ 0x080DF05C

void sub_080DF05C(void)

{
  undefined4 in_r0;
  short *psVar1;
  uint uVar2;
  ushort uVar3;
  
  uVar3 = 0;
  *(undefined1 *)DAT_030061dc = DAT_030061cb;
  *(byte *)((int)DAT_030061dc + 1) = DAT_030061c2 ^ DAT_030061c3;
  DAT_030061dc[1] = 0;
  CpuSet(in_r0,DAT_030061dc + 2,0x4000004);
  uVar2 = 0;
  psVar1 = DAT_030061dc;
  do {
    uVar3 = uVar3 + *psVar1;
    psVar1 = psVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 10);
  DAT_030061dc[1] = ~uVar3 - 0xc;
  DAT_030061c4 = 1;
  return;
}


// sub_080DF0AC @ 0x080DF0AC

void sub_080DF0AC(int arg0)

{
  uint uVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uStack_24;
  
  uVar1 = _call_via_r0(0x30062b0);
  DAT_030061c3 = 0;
  if ((uVar1 & 0xff) != 0) {
    uVar1 = 0;
    do {
      puVar2 = (ushort *)(DAT_030061ec + uVar1 * 0x18);
      iVar5 = 0;
      uVar4 = 0;
      uVar6 = uVar1 + 1;
      puVar3 = puVar2;
      do {
        iVar5 = iVar5 + (uint)*puVar3;
        puVar3 = puVar3 + 1;
        uVar4 = uVar4 + 1;
      } while (uVar4 < 10);
      puVar2 = puVar2 + 2;
      if (iVar5 * 0x10000 >> 0x10 == -0xd) {
        CpuSet(puVar2,uVar1 * 0x10 + arg0,0x4000004);
        DAT_030061c3 = (byte)(1 << (uVar1 & 0xff)) | DAT_030061c3;
      }
      uStack_24 = 0;
      CpuSet(&uStack_24,puVar2,0x5000004);
      uVar1 = uVar6;
    } while ((int)uVar6 < 2);
  }
  DAT_030061c2 = DAT_030061c2 | DAT_030061c3;
  return;
}


// sub_080DF15C @ 0x080DF15C

void sub_080DF15C(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = DAT_030061e8;
  uVar3 = DAT_030061e0;
  if (DAT_030061c0 == '\0') {
    if (DAT_030061c9 == '\0') {
      REG_IME = 0;
      DAT_03007ff8 = DAT_03007ff8 | 0x80;
      REG_IME = 1;
    }
    DAT_030061c9 = DAT_030061c0;
  }
  else if ((DAT_030061c1 != '\0') && (DAT_030061c6 != '\0')) {
    DAT_030061d8 = 0xffffffff;
    DAT_030061e8 = DAT_030061e4;
    DAT_030061e4 = uVar4;
    if (DAT_030061c4 != '\0') {
      DAT_030061e0 = DAT_030061dc;
      DAT_030061dc = uVar3;
      DAT_030061c4 = '\0';
      DAT_030061d4 = 0;
    }
    uVar2 = REG_SIOCNT;
    DAT_030061c7 = (undefined1)((uVar2 & 0x7f) >> 6);
    REG_SIOCNT._2_2_ = 0xfefe;
    uVar1 = REG_SIOCNT._0_2_;
    REG_SIOCNT._0_2_ = uVar1 | 0x80;
    REG_TM3CNT._2_2_ = 0xc0;
  }
  return;
}


// SerialTimer3Intr @ 0x080DF1EC

void SerialTimer3Intr(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar3 = DAT_030061e8;
  iVar6 = DAT_030061e0;
  puVar5 = &local_14;
  local_10 = DAT_04000124;
  local_14 = REG_SIODATA32;
  uVar2 = REG_SIOCNT;
  DAT_030061c7 = (undefined1)((uVar2 & 0x7f) >> 6);
  if (((short)local_14 == -0x102) && (9 < DAT_030061d8)) {
    DAT_030061d8 = -1;
    DAT_030061e8 = DAT_030061e4;
    DAT_030061e4 = iVar3;
    if (DAT_030061c4 != '\0') {
      DAT_030061e0 = DAT_030061dc;
      DAT_030061dc = iVar6;
      DAT_030061c4 = '\0';
      DAT_030061d4 = 0;
    }
    REG_IME = 0;
    DAT_03007ff8 = DAT_03007ff8 | 0x80;
    REG_IME = 1;
  }
  if (DAT_030061d4 < 10) {
    REG_SIOCNT._2_2_ = *(undefined2 *)(DAT_030061d4 * 2 + DAT_030061e0);
  }
  if (DAT_030061d4 < 0xb) {
    DAT_030061d4 = DAT_030061d4 + 1;
  }
  if (-1 < DAT_030061d8) {
    puVar4 = (undefined2 *)(DAT_030061e4 + DAT_030061d8 * 2);
    iVar6 = 1;
    do {
      *puVar4 = *(undefined2 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 2);
      puVar4 = puVar4 + 0xc;
      iVar6 = iVar6 + -1;
    } while (-1 < iVar6);
    if (DAT_030061d8 == 9) {
      DAT_030061c5 = 1;
    }
  }
  if (DAT_030061d8 < 10) {
    DAT_030061d8 = DAT_030061d8 + 1;
  }
  if (DAT_030061c0 != '\0') {
    REG_TM3CNT._2_2_ = 0;
  }
  if ((DAT_030061d4 < 0xb) && (DAT_030061c0 != '\0')) {
    uVar1 = REG_SIOCNT._0_2_;
    REG_SIOCNT._0_2_ = uVar1 | 0x80;
    REG_TM3CNT._2_2_ = 0xc0;
  }
  DAT_030061c9 = 1;
  return;
}


// sub_080DF2E8 @ 0x080DF2E8

void sub_080DF2E8(void)

{
  sub_080DEE20();
  DAT_03006380 = 200;
  DAT_03006360 = 0;
  DAT_03006368 = 0;
  DAT_030062f0 = 1;
  return;
}


// sub_080DF31C @ 0x080DF31C

void sub_080DF31C(void)

{
  sub_080DEF00();
  DAT_03003970 = 0;
  return;
}


// sub_080DF330 @ 0x080DF330

void sub_080DF330(void)

{
  sub_080DEEE8();
  REG_IME = 0;
  REG_IE._0_2_ = 0x20c3;
  REG_IME = 1;
  DAT_03003970 = 1;
  return;
}


// sub_080DF360 @ 0x080DF360

void sub_080DF360(void)

{
  sub_080DF05C();
  return;
}


// sub_080DF370 @ 0x080DF370

void sub_080DF370(void)

{
  DAT_03006360 = sub_080DEF50(0x3006340);
  return;
}


// sub_080DF388 @ 0x080DF388

undefined4 sub_080DF388(undefined1 *arg0)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  undefined4 uVar5;
  char local_1c [4];
  
  uVar5 = 0;
  if (DAT_030062f0 == 1) {
    if ((DAT_03006360 & 0x2000) == 0) {
      if ((DAT_03006360 & 0x100) != 0) {
        DAT_030062f0 = 2;
        DAT_03006380 = 0xc100;
        puVar4 = &DAT_03006382;
        bVar1 = 0;
        do {
          *puVar4 = *arg0;
          arg0 = arg0 + 1;
          puVar4 = puVar4 + 1;
          bVar1 = bVar1 + 1;
        } while (bVar1 < 8);
      }
    }
    else {
      uVar5 = 0;
    }
  }
  else if (((1 < DAT_030062f0) && (DAT_030062f0 == 2)) &&
          (uVar2 = sub_080DF6FC(0xc100), (uVar2 & 0xff) == 1)) {
    local_1c[1] = '\0';
    local_1c[0] = '\0';
    uVar2 = 0;
    do {
      local_1c[uVar2] = '\0';
      uVar3 = 0;
      do {
        if (arg0[uVar3] != *(char *)(uVar2 * 0x10 + 0x3006342 + uVar3)) {
          local_1c[uVar2] = '\x01';
        }
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 8);
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 2);
    if ((local_1c[0] == '\0') && (local_1c[1] == '\0')) {
      uVar5 = 1;
      DAT_03006380 = 0;
    }
  }
  return uVar5;
}


// sub_080DF498 @ 0x080DF498

void sub_080DF498(void)

{
  DAT_030062f4 = 1;
  DAT_03006364 = 0;
  DAT_03006370 = 0;
  return;
}


// sub_080DF4B8 @ 0x080DF4B8

undefined4 sub_080DF4B8(void)

{
  uint uVar1;
  char local_18 [4];
  
  switch(DAT_030062f4) {
  default:
    goto switchD_080df4d2_caseD_0;
  case '\x01':
    DAT_03006380 = 0xf100;
    DAT_030062f4 = '\x02';
    goto switchD_080df4d2_caseD_0;
  case '\x02':
    uVar1 = 0;
    do {
      if ((uVar1 < 2) && (*(short *)(uVar1 * 0x10 + 0x3006340) != -0xf00)) {
        local_18[uVar1] = '\0';
      }
      else {
        local_18[uVar1] = '\x01';
      }
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
    if ((local_18[0] == '\x01') && (local_18[1] == '\x01')) {
      local_18[2] = local_18[1];
      local_18[3] = local_18[1];
      DAT_03006380 = 0xf200;
      DAT_030062f4 = '\x03';
      goto switchD_080df4d2_caseD_0;
    }
    break;
  case '\x03':
    uVar1 = 0;
    do {
      if ((uVar1 < 2) && (*(short *)(uVar1 * 0x10 + 0x3006340) != -0xe00)) {
        local_18[uVar1] = '\0';
      }
      else {
        local_18[uVar1] = '\x01';
      }
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
    if ((local_18[0] == '\x01') && (local_18[1] == '\x01')) {
      local_18[2] = local_18[1];
      local_18[3] = local_18[1];
      DAT_03006380 = 0xf300;
      DAT_030062f4 = '\x04';
      goto switchD_080df4d2_caseD_0;
    }
    break;
  case '\x04':
    uVar1 = 0;
    do {
      if ((uVar1 < 2) && (*(short *)(uVar1 * 0x10 + 0x3006340) != -0xd00)) {
        local_18[uVar1] = '\0';
      }
      else {
        local_18[uVar1] = '\x01';
      }
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
    if ((local_18[0] == '\x01') && (local_18[1] == '\x01')) {
      local_18[2] = local_18[1];
      local_18[3] = local_18[1];
      DAT_030062f4 = '\x05';
      DAT_03006380 = 0;
      goto switchD_080df4d2_caseD_0;
    }
  }
  DAT_03006364 = DAT_03006364 + 1;
switchD_080df4d2_caseD_0:
  if (0x3c < DAT_03006364) {
    DAT_03006370 = DAT_03006370 + 1;
    if (0x14 < DAT_03006370) {
      return 0xff;
    }
    DAT_030062f4 = '\x01';
    DAT_03006364 = 0;
  }
  uVar1 = sub_080DFB98();
  if ((int)-(uVar1 & 0xff) < 0) {
    DAT_03006390 = DAT_03006390 + 1;
  }
  else {
    DAT_03006390 = (ushort)(-(uVar1 & 0xff) >> 0x1f);
  }
  if (599 < DAT_03006390) {
    return 0xff;
  }
  if (DAT_030062f4 != '\x05') {
    return 0;
  }
  return 1;
}


