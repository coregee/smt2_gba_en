/* Ghidra decompilation of asm/code_080E8D88.s (reference only; not compiled). */

// sub_080E8D88 @ 0x080E8D88

void sub_080E8D88(undefined4 arg0)

{
  DAT_0203d0c3 = (undefined1)arg0;
  return;
}


// sub_080E8D9C @ 0x080E8D9C

void sub_080E8D9C(void)

{
  sub_080E8D88(1);
  return;
}


// sub_080E8DA8 @ 0x080E8DA8

void sub_080E8DA8(void)

{
  sub_080E8D88(0);
  return;
}


// sub_080E8DB4 @ 0x080E8DB4

void sub_080E8DB4(uint arg0)

{
  if ((&DAT_0203cb90)[arg0 & 0xffff] != 0xffff) {
    (&DAT_0203cfa4)[(arg0 & 0xffff) * 0x40] = 1;
  }
  return;
}


// sub_080E8DEC @ 0x080E8DEC

void sub_080E8DEC(void)

{
  sub_080E8DB4(0);
  sub_080E8DB4(1);
  return;
}


// sub_080E8E00 @ 0x080E8E00

undefined4 sub_080E8E00(uint arg0,uint arg1)

{
  undefined4 uVar1;
  uint arg1_00;
  int iVar2;
  int iVar3;
  uint arg0_00;
  
  arg1_00 = arg1 & 0xffff;
  arg0_00 = arg0 & 0xf;
  DAT_03006434 = &DAT_0203d16c;
  if (arg0_00 < 3) {
    sub_080C45C0(arg0_00,arg1_00);
    DAT_0203d38c = 0;
    iVar3 = arg0_00 * 4;
    if ((arg1_00 != 0xffff) && ((&DAT_0203cb90)[arg0_00] != arg1_00)) {
      (&DAT_0203cb90)[arg0_00] = arg1_00;
      if (arg0_00 == 0) {
        sub_080F0200(0,DAT_0203cb90);
        sub_080ED938(0);
        DAT_0203d318 = sub_080A9C0C(0x80e55bd);
        sub_080E5668();
        DAT_0203cfa3 = 0;
        DAT_0203c204 = sub_080AD0FC(0x86bea18,0xffff);
        iVar2 = 0;
        if ((arg0 & 0xf0) != 0) {
          sub_080E845C(0,0,0x10);
          DAT_0203cfa4 = 2;
          iVar2 = 0;
        }
      }
      else {
        sub_080F0200(4,arg1_00);
        sub_080ED938(1);
        uVar1 = sub_080A9C0C(0x80e5611);
        (&DAT_0203d318)[arg0_00] = uVar1;
        iVar2 = arg0_00 * 0x40;
        (&DAT_0203cfa3)[iVar2] = 0;
        uVar1 = sub_080AD0FC(0x86beb18,0xffff);
        *(undefined4 *)(iVar3 + 0x203c204) = uVar1;
      }
      *(undefined2 *)((int)&DAT_0203cfa8 + iVar2) = 0x7fff;
      *(undefined2 *)((int)&DAT_0203cfaa + iVar2) = 0x7fff;
      sub_080BDE1C(arg1_00);
      *(undefined4 *)((arg0_00 + 6) * 4 + 0x2036094) = *(undefined4 *)(iVar3 + 0x203c204);
      sub_080C08F8(iVar3 + 0x10,0);
    }
    uVar1 = *(undefined4 *)(iVar3 + 0x203c204);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080E8F80 @ 0x080E8F80

void sub_080E8F80(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xff;
  (&DAT_0203cfa8)[uVar1 * 0x20] = (undefined2)arg1;
  (&DAT_0203cfaa)[uVar1 * 0x20] = (undefined2)arg2;
  (&DAT_0203cfb0)[uVar1 * 0x40] = (undefined1)arg3;
  return;
}


// sub_080E8FA0 @ 0x080E8FA0

void sub_080E8FA0(undefined4 arg0,undefined2 *arg1,undefined2 *arg2)

{
  undefined2 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((byte)arg0 == 1) {
    *arg1 = 0xa1;
    uVar1 = 0x56;
  }
  else if ((byte)arg0 < 2) {
    if ((byte)arg0 != 0) goto LAB_080e8fe2;
    iVar2 = sub_080ED954();
    if (iVar2 == 0) {
      uVar1 = 0x78;
    }
    else {
      uVar1 = 0x50;
    }
    *arg1 = uVar1;
    uVar1 = 0x56;
  }
  else {
    if ((byte)arg0 != 2) goto LAB_080e8fe2;
    uVar1 = 0;
    *arg1 = 0;
  }
  *arg2 = uVar1;
LAB_080e8fe2:
                    /* WARNING: Could not recover jumptable at 0x080e8fe6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E8FE8 @ 0x080E8FE8

void sub_080E8FE8(uint arg0)

{
  (&DAT_0203cfa8)[(arg0 & 0xff) * 0x20] = 0x7fff;
  (&DAT_0203cfaa)[(arg0 & 0xff) * 0x20] = 0x7fff;
  return;
}


// sub_080E9008 @ 0x080E9008

void sub_080E9008(void)

{
  sub_080AD1FC(DAT_0203c204);
  DAT_0203c204 = 0;
  *(undefined2 *)(DAT_0203d314 + 2) = 1;
  DAT_0203cb94 = 0xffff;
  DAT_0203cb90 = 0xffff;
  return;
}


// sub_080E9044 @ 0x080E9044

void sub_080E9044(int arg0,uint arg1)

{
  uint uVar1;
  
  uVar1 = arg1 & 0xffff;
  if (arg0 != 0) {
    sub_080C37EC(arg0);
    sub_080AD1FC(arg0);
  }
  (&DAT_0203c204)[uVar1] = 0;
  *(undefined2 *)((&DAT_0203d318)[uVar1] + 2) = 1;
  (&DAT_0203cb90)[uVar1] = 0xffff;
  (&DAT_0203cfa3)[uVar1 * 0x40] = 0;
  (&DAT_0203cfa4)[uVar1 * 0x40] = 0;
  return;
}


// sub_080E90AC @ 0x080E90AC

void sub_080E90AC(int arg0)

{
  undefined4 uVar1;
  int iVar2;
  int arg0_00;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203cb7a == 1) {
    if ((DAT_030031d0 & 2) != 0) {
      sub_080F00FC(0x4000);
      DAT_0203cb78 = 6;
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    DAT_03000052 = DAT_03000052 + 1;
    if (10 < DAT_03000052) {
      DAT_0203cb7a = 2;
    }
  }
  else if (DAT_0203cb7a < 2) {
    if (DAT_0203cb7a == 0) {
      DAT_03000052 = 0;
      uVar1 = Menu_ExpandListTemplate(0x8126368,0);
      BattleMenu_SetMode(3,uVar1);
      sub_080EC99C(1);
      uVar1 = sub_080C2BA4();
      sRam0203d160 = (short)uVar1;
      DAT_0203cb7a = 2;
      sub_080EA9E8(1);
    }
  }
  else if (DAT_0203cb7a == 2) {
    DAT_03000052 = 0;
    sub_080ED90C(0x4000);
    arg0_00 = 0;
    iVar3 = 0;
    do {
      iVar2 = sub_080F3EC8(arg0_00);
      if ((iVar2 != 0) && (iVar2 = sub_080F3040(), iVar2 != 0)) {
        if (sRam0203d160 == 0) {
          sub_080E91F0(iVar3 >> 0x10);
        }
        else {
          sub_080E926C(iVar3 >> 0x10,(int)*(short *)(&DAT_0203d130 + arg0_00 * 2),(int)sRam0203d160)
          ;
        }
      }
      iVar3 = iVar3 + 0x10000;
      arg0_00 = arg0_00 + 1;
    } while (arg0_00 < 0x10);
    sub_080C84C0();
    DAT_0203cb78 = 10;
    DAT_0203cb7a = 0;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080e91e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E91F0 @ 0x080E91F0

void sub_080E91F0(undefined4 arg0)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  undefined1 auStack_10 [4];
  
  uVar1 = sub_080C2244();
  iVar4 = (int)(short)arg0;
  sub_080EDA4C(iVar4,(uVar1 & 1) * 4 + 0x10);
  if (iVar4 < 4) {
    uVar2 = sub_080C3620(iVar4);
    if (((short)uVar2 == 5) && (iVar3 = sub_080EF740(iVar4,5,auStack_10), iVar3 != 0)) {
      sub_080C35C4(iVar4,5);
    }
    else {
      iVar3 = (int)(short)arg0;
      iVar4 = sub_080C00DC(iVar3,0);
      if (iVar4 == 0xff) {
        sub_080C35C4(iVar3,9);
      }
      else {
        sub_080C35C4(iVar3,4);
      }
    }
  }
  else {
    sub_080C35C4(iVar4,10);
  }
                    /* WARNING: Could not recover jumptable at 0x080e926a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E926C @ 0x080E926C

void sub_080E926C(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar10 = (int)(short)arg0;
  iVar2 = sub_080F3F14(iVar10);
  uVar3 = sub_080C3620(iVar10);
  uVar4 = sub_080C2244();
  sub_080EDA4C(iVar10,(uVar4 & 1) * 4 + 0x10);
  sVar1 = (short)uVar3;
  iVar11 = (int)sVar1;
  if ((iVar11 == 8) && (iVar5 = sub_0812B37C(), iVar5 != 0)) goto LAB_080e93ec;
  if (((iVar11 - 4U & 0xffff) < 2) || (iVar11 == 10)) {
    sub_080E91F0(iVar10);
    goto LAB_080e940a;
  }
  if (iVar11 == 7) {
    uVar6 = sub_080F4070(iVar10);
    iVar10 = (int)(short)iVar2;
    uVar7 = sub_080ED6CC(iVar10);
    uVar8 = sub_080ED694(iVar10);
    if (((iVar10 != 0x3e) && (iVar10 != 0x3f)) &&
       (-1 < ((int)(short)uVar6 - (int)(short)uVar7) * 0x10000)) {
      if (((short)uVar8 != 0x80) && ((short)uVar8 != 0x82)) goto LAB_080e9348;
      if ((ushort)arg1 < 0x10) {
        iVar10 = sub_080F3EC8((int)(short)(ushort)arg1);
        if ((iVar10 != 0) && (iVar10 = sub_080C0A00((int)(short)(ushort)arg1), iVar10 != 0))
        goto LAB_080e9348;
      }
    }
  }
  else {
LAB_080e9348:
    if (sVar1 == 8) {
      uVar4 = 0;
      iVar10 = Action_GetRecord(iVar2 * 0x10000 - 0xd00000U >> 0x10);
      uVar9 = 0;
      do {
        if ((int)*(char *)(uVar9 + 0x30050e0) == (int)(short)arg0) {
          uVar4 = uVar9;
        }
        uVar9 = uVar9 + 1 & 0xff;
      } while (uVar9 < 6);
      iVar11 = iVar2 * 0x10000 >> 0x10;
      iVar2 = sub_080C10B4(iVar11);
      iVar11 = sub_0812B1E0(iVar11,uVar4);
      if (0 < (iVar2 - iVar11) * 0x10000) {
        if ((*(char *)(iVar10 + 3) != -0x80) && (*(char *)(iVar10 + 3) != -0x7e)) goto LAB_080e93ce;
        if ((ushort)arg1 < 0x10) {
          iVar2 = sub_080F3EC8((int)(short)(ushort)arg1);
          if ((iVar2 != 0) && (iVar2 = sub_080C0A00((int)(short)(ushort)arg1), iVar2 != 0))
          goto LAB_080e93ce;
        }
      }
    }
    else {
LAB_080e93ce:
      if (sVar1 != 6) {
        sub_080C35C4((int)(short)arg0,uVar3 & 0xffff);
        goto LAB_080e940a;
      }
    }
  }
LAB_080e93ec:
  if ((short)arg2 == 1) {
    sub_080E91F0((int)(short)arg0);
  }
  else {
    sub_080C35C4((int)(short)arg0,9);
  }
LAB_080e940a:
                    /* WARNING: Could not recover jumptable at 0x080e9418. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E941C @ 0x080E941C

void sub_080E941C(int arg0)

{
  char cVar1;
  ushort *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar7;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  switch(DAT_0203cb7a) {
  case 0:
    DAT_0203d0ce = 0;
    sub_080F3120();
    sub_080F2D4C();
    sub_080EDD8C();
    uVar3 = sub_080F2F14();
    sRam0203d0cc = (short)uVar3;
    DAT_0203cb7a = 1;
    sub_080F3F58(0xfffffbff);
  case 1:
    iVar4 = sub_080EFFC4((int)DAT_0203d0ce);
    iVar4 = sub_080F2F64(iVar4 * 0x10000 + 0x80000000U >> 0x10);
    if ((*(ushort *)(iVar4 + 0x10) & (ushort)0xb1e0) == 0) {
      DAT_0203cb7a = 2;
      DAT_0203cb7c = *(ushort *)(iVar4 + 0x10) & 0xb1e0;
    }
    else {
      DAT_0203cb7a = 3;
    }
    break;
  case 2:
    uVar3 = sub_080EFFC4((int)DAT_0203d0ce);
    iVar4 = sub_080F0434((int)(short)uVar3);
    if (iVar4 != 0) {
      DAT_0203cb7a = 3;
    }
    break;
  case 3:
    sub_080C366C();
    Party_BuildMemberNameTiles();
    sub_080C6FD8();
    uVar6 = 0;
    do {
      sub_080BFD94((int)(short)uVar6);
      uVar5 = (int)(short)uVar6 + 1;
      uVar6 = uVar5 & 0xffff;
    } while ((int)(uVar5 * 0x10000) >> 0x10 < 4);
    uVar3 = sub_080EFFC4((int)DAT_0203d0ce);
    if ((short)uVar3 < 0x10) {
      uVar6 = 0;
      cVar1 = DAT_030050e0;
      while ((int)cVar1 != (int)(short)uVar3) {
        uVar6 = uVar6 + 1 & 0xff;
        if (5 < uVar6) goto LAB_080e957a;
        cVar1 = (&DAT_030050e0)[uVar6];
      }
      if (uVar6 < 6) {
        sub_080C8490(uVar6);
      }
    }
LAB_080e957a:
    iVar4 = sub_080ED9F4();
    if (iVar4 == 0) {
      sub_080C84A0();
      DAT_0203cb7a = 0;
      DAT_0203cb78 = 0xe;
      DAT_030063a0 = 4;
      *(undefined2 *)(arg0 + 0x1c) = 1;
      if (DAT_0203d16a != 0) {
        DAT_030063aa = 0;
      }
    }
    else {
      iVar4 = sub_080F3144();
      if (iVar4 == 0) {
        uVar6 = sub_080ED8F4();
        if ((uVar6 & 0x2200) == 0) {
          DAT_0203d0ce = DAT_0203d0ce + 1;
          if (sRam0203d0cc < DAT_0203d0ce) {
            DAT_0203d0ce = 0;
            DAT_0203d0c0 = 1;
            DAT_0203d3ac = 0xffff;
            DAT_0203d3ae = 0xffff;
            sub_080EF2A0();
            sub_080C84A0();
            puVar2 = DAT_03006434;
            DAT_0203d3a4 = DAT_0203d3a4 + 1;
            if (DAT_0203d3a4 == 4) {
              DAT_0203d3a4 = 0;
            }
            DAT_03006434[1] = 0;
            *puVar2 = *puVar2 & 0xff7f;
            uVar6 = sub_080ED8F4();
            bVar7 = (uVar6 & 0x4000) == 0;
            if (bVar7) {
              DAT_0203cb78 = 6;
            }
            else {
              DAT_0203cb78 = 0xd;
            }
            DAT_0203cb7a = (ushort)!bVar7;
            *(undefined2 *)(arg0 + 0x1c) = 1;
            if (DAT_0203d16a != 0) {
              DAT_030063aa = 0;
            }
          }
          else {
            DAT_0203cb7a = 1;
          }
        }
        else {
          uVar6 = sub_080ED8F4();
          if (((uVar6 & 0x2000) != 0) && (DAT_030063ac == 2)) {
            DAT_030063b4 = 1;
          }
          *(undefined2 *)(arg0 + 0x1c) = 1;
          DAT_0203cb7a = 0;
          DAT_0203cb78 = 0xe;
          uVar6 = 0;
          do {
            sub_080E7538(uVar6 & 0xff,0,0);
            uVar5 = uVar6 * 0x10000 + 0x10000;
            uVar6 = uVar5 >> 0x10;
          } while ((int)uVar5 >> 0x10 < 8);
        }
      }
      else {
        sub_080ED90C(0x2000);
        DAT_0203cb7a = 0;
        DAT_0203cb78 = 0xe;
        *(undefined2 *)(arg0 + 0x1c) = 1;
        sub_080C84A0();
        DAT_030063a0 = 3;
        DAT_0203cb78 = 0xf;
        if (DAT_0203d16a != 0) {
          DAT_030063aa = 0;
        }
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080e9770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E9778 @ 0x080E9778

void sub_080E9778(void)

{
  DAT_0203cb78 = 10;
  DAT_0203cb7a = 0;
  return;
}


// sub_080E9798 @ 0x080E9798

void sub_080E9798(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_030063aa == 1) {
    if (DAT_030063a6 == 5) {
      DAT_0203cb78 = 0x10;
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_030063aa = 0;
  }
  else if (DAT_030063aa < 2) {
    if (DAT_030063aa == 0) {
      if (DAT_0203d16a == 0) {
        *(undefined2 *)(arg0 + 0x1c) = 1;
      }
      else {
        if (DAT_030063a0 == 1) {
          DAT_030063a6 = 5;
        }
        DAT_030063aa = 2;
      }
    }
  }
  else if (DAT_030063aa == 2) {
    DAT_030063aa = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080e9808. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E980C @ 0x080E980C

uint sub_080E980C(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  sVar1 = DAT_0203cb9c;
  uVar2 = sub_080F0168();
  uVar4 = (-uVar2 | uVar2) >> 0x1f;
  uVar2 = 0;
  if ((int)sVar1 != 0) {
    do {
      iVar3 = sub_080F01EC(uVar2);
      if (iVar3 != -1) {
        uVar4 = 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(int)sVar1);
  }
  uVar2 = 0;
  do {
    iVar3 = sub_080F0194(uVar2);
    if (iVar3 != 0) {
      uVar4 = 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  iVar3 = sub_080F0168();
  if (iVar3 != 0) {
    uVar4 = 1;
  }
  return uVar4;
}


// sub_080E9870 @ 0x080E9870

dword sub_080E9870(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  dword arg1;
  
  arg1 = 0;
  uVar1 = sub_080ED8F4();
  if ((uVar1 & 0x200) == 0) {
    iVar2 = sub_080ED954();
    if (iVar2 == 1) {
      uVar3 = sub_080E980C();
      if (((short)uVar3 == 1) || (iVar2 = sub_080C2340(0xd5), iVar2 != 0)) {
        arg1 = 0x86bec18;
      }
    }
    else {
      uVar3 = sub_080E980C();
      if (((short)uVar3 == 1) || (iVar2 = sub_080C2340(0xd5), iVar2 != 0)) {
        arg1 = MessageBox_ComposeRaceNameText(DAT_0203cb90,0x8124284);
      }
    }
    if (arg1 != 0) {
      BattleMenu_SetMode(3,arg1);
    }
  }
  else {
    sub_080EA528();
    arg1 = 0;
  }
  return arg1;
}


// sub_080E98F8 @ 0x080E98F8

void sub_080E98F8(int arg0)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  dword arg1;
  uint uVar9;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar10;
  
  uVar9 = (uint)DAT_0203cb9c;
  bVar10 = false;
  uVar2 = sub_080C2340(0xe5);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  switch(DAT_0203cb7a) {
  case 0:
    sub_080F00FC(0x4000);
    sub_080EA9E8(0);
    sub_080E51FC();
    sub_080C23BC(0x166);
    uVar9 = sub_080ED8F4();
    if ((uVar9 & 0x2000) == 0) {
      iVar4 = sub_080ED954();
      if (iVar4 == 0) {
        uVar9 = sub_080ED8F4();
        if ((uVar9 & 0x200) == 0) {
          if ((uVar2 & 0xffff) != 0) {
            sub_080C2584(DAT_0203cb90);
          }
          uVar5 = Battle_BuildRaceCountText(DAT_0203cb90 & 0xffff,(uint)DAT_0203cb98,0x8124270);
          BattleMenu_SetMode(3,uVar5);
          bVar10 = true;
        }
      }
      else {
        uVar9 = sub_080ED8F4();
        if (((uVar9 & 0x200) == 0) && ((uVar2 & 0xffff) != 0)) {
          sub_080C2584(DAT_0203cb90);
          sub_080C2584(DAT_0203cb94);
          DAT_0203c9e4 = 1;
        }
      }
      uVar2 = sub_080ED8F4();
      if ((uVar2 & 0x200) == 0) {
        iVar4 = sub_080EF3C8(DAT_0203cb90);
        if ((iVar4 != -1) && (iVar8 = sub_080C10B4(iVar4), 0x62 < iVar8)) {
          iVar4 = -1;
        }
        sub_080F01D8((short)DAT_0203cb9e + -1,(int)(short)iVar4);
        iVar4 = sub_080EF434(DAT_0203cb90);
        if (iVar4 != 0) {
          sub_080F0150(1);
        }
      }
      DAT_0203cb7a = 1;
      if (bVar10) {
        sub_080E5A18(0x14);
      }
    }
    else {
      sub_080EF364();
      DAT_0203cb78 = 0x10;
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    goto LAB_080e9b06;
  case 1:
    uVar2 = (uint)DAT_0203cb9e;
    DAT_0203cb9e = (ushort)(uVar2 - 1);
    if ((int)((uVar2 - 1) * 0x10000) < 1) {
      uVar2 = sub_080ED8F4();
      if ((uVar2 & 0x200) != 0) {
        uVar2 = 0x10;
        do {
          iVar8 = (int)(short)uVar2;
          iVar4 = sub_080C0A00(iVar8);
          if (iVar4 != 0) {
            sub_080C0818(iVar8);
            sub_080C08F8(iVar8,0x8000);
            sub_080F4054(iVar8,0);
            sub_080F408C(iVar8,0);
            sub_080E7538(uVar2 - 0x10 & 0xff,0,0);
          }
          uVar2 = iVar8 + 1U & 0xffff;
        } while ((int)((iVar8 + 1U) * 0x10000) >> 0x10 < 0x18);
        uVar5 = sub_080E980C();
        if (((short)uVar5 == 1) && (DAT_0203cb74 == 0)) {
          DAT_0203cb74 = sub_080AB890(2,0xb,0x1a,2);
        }
      }
      sub_080EF364();
      sub_080C84A0();
      if (DAT_0203d16a == 0) {
        sub_080ECF60(9);
      }
      DAT_030063b0 = 9;
      DAT_0203cb7a = 4;
      break;
    }
    DAT_0203cb7a = 2;
    uVar5 = sub_080C2244();
    DAT_0203a450 = (undefined2)uVar5;
    uVar5 = sub_080C2244();
    DAT_0203a452 = (undefined2)uVar5;
    sub_080EF364();
LAB_080e9b06:
    sub_080C84A0();
    break;
  case 2:
    DAT_0203d168 = 0;
    sub_080C51BC(4);
    DAT_030031b4 = 0;
    sub_080EA528();
    sub_080EA964();
    sub_080E9008();
    DAT_030063a0 = 1;
    sub_080C7C60();
    DAT_0203cb7a = 3;
    break;
  case 3:
    if (((DAT_0203d16a == 0) && (DAT_0200e7d4 != 0)) && (DAT_0200e7d4 != 2)) {
      sub_080C700C();
    }
    DAT_0203cb78 = 0;
    goto LAB_080ea138;
  case 4:
    iVar4 = sub_080E9870();
    bVar10 = iVar4 != 0;
    DAT_0203d0ce = 0;
    DAT_0203cb7a = 5;
    goto LAB_080e9f66;
  case 5:
    uVar2 = sub_080F01EC((int)(short)DAT_0203d0ce);
    if (uVar2 == 0xffffffff) {
      DAT_0203d0ce = DAT_0203d0ce + 1;
      if ((int)(uVar9 * 0x10000) <= (int)((uint)DAT_0203d0ce * 0x10000)) {
        DAT_0203cb7a = 6;
      }
    }
    else {
      sub_080F3E54(uVar2,1);
      uVar5 = Battle_BuildItemDropText(uVar2 & 0xffff,0x8124452);
      BattleMenu_SetMode(7,uVar5);
      DAT_0203cb7a = 0x11;
    }
    break;
  case 6:
    uVar2 = sub_080F0168();
    DAT_0203cb7a = 7;
    if (uVar2 != 0) {
      uVar9 = sub_080C2244();
      iVar4 = 0xdb;
      if ((uVar9 & 7) != 0) {
        iVar4 = 0xe5;
      }
      arg1 = 0x812443c;
      if (iVar4 == 0xe5) {
        arg1 = 0x8124426;
      }
      sub_080F3E54(iVar4,uVar2);
      uVar5 = Battle_BuildValueRewardText(uVar2 & 0xffff,arg1);
      BattleMenu_SetMode(7,uVar5);
      DAT_0203cb7a = 0xe;
    }
    break;
  case 7:
    uVar2 = sub_080F0124();
    DAT_0203cb7a = 8;
    if (uVar2 != 0) {
      sub_080F3E20();
      uVar5 = Battle_BuildValueRewardText(uVar2 & 0xffff,0x81243ee);
      BattleMenu_SetMode(7,uVar5);
      DAT_0203cb7a = 0xf;
    }
    break;
  case 8:
    uVar2 = sub_080F0144();
    DAT_0203cb7a = 9;
    if (uVar2 != 0) {
      sub_080F3E2C();
      uVar5 = Battle_BuildValueRewardText(uVar2 & 0xffff,0x812440a);
      BattleMenu_SetMode(7,uVar5);
      DAT_0203cb7a = 0x10;
    }
    DAT_03000056 = 0;
    DAT_0203d0ce = 0;
    break;
  case 9:
    iVar4 = sub_080F3EC8((int)(short)DAT_0203d0ce);
    if ((iVar4 == 0) || (iVar4 = sub_080C0A00((int)(short)DAT_0203d0ce), iVar4 == 0))
    goto LAB_080ea0f6;
    iVar4 = sub_080F2F64(DAT_0203d0ce - 0x8000 & 0xffff);
    iVar8 = sub_080F0194((int)(short)DAT_0203d0ce);
    iVar3 = sub_080C1070(*(undefined4 *)(iVar4 + 8));
    DAT_0300005c = 0;
    uVar2 = 0;
    do {
      iVar7 = (int)(short)uVar2;
      cVar1 = *(char *)(iVar4 + 0x5d + iVar7);
      if (cVar1 != -1) {
        *(char *)(iVar7 + 0x3000060) = cVar1;
        DAT_0300005c = DAT_0300005c + 1;
      }
      uVar2 = iVar7 + 1U & 0xffff;
    } while ((int)((iVar7 + 1U) * 0x10000) >> 0x10 < 0x20);
    if (iVar8 != 0) {
      iVar7 = *(int *)(iVar4 + 8) + iVar8;
      *(int *)(iVar4 + 8) = iVar7;
      if ((int)0x98967e < iVar7) {
        *(dword *)(iVar4 + 8) = 9999999;
      }
      uVar5 = Battle_BuildRewardText(iVar4,iVar8,0x812428e);
      BattleMenu_SetMode(7,uVar5);
      bVar10 = true;
    }
    iVar4 = sub_080C1070(*(undefined4 *)(iVar4 + 8));
    sub_080C0FA4((int)(short)DAT_0203d0ce,iVar4);
    DAT_03000054 = (ushort)(iVar4 - iVar3);
    if ((iVar4 - iVar3 & 0xffffU) != 0) {
      DAT_03000056 = 1;
      DAT_0203cb7c = 0;
      DAT_0203cb7a = 10;
      uRam0203d378 = DAT_03000054;
      sub_080BF938((int)(short)DAT_0203d0ce);
      break;
    }
    DAT_0203cb7a = 0xb;
LAB_080e9f66:
    if (bVar10) {
      sub_080E5A18(0x14);
    }
    break;
  case 10:
    uVar2 = sub_080EA934();
    if ((uVar2 & 0xff) == 1) {
      DAT_0203cb7a = 0xc;
      uVar5 = Battle_BuildNamePrefixText(DAT_0203d0ce - 0x8000 & 0xffff,0x812434a);
      BattleMenu_SetMode(7,uVar5);
      sub_080ECF60(0xb);
      sub_080ECF70(0x67);
    }
    break;
  case 0xb:
  case 0x13:
    DAT_0203d0ce = DAT_0203d0ce + 1;
    if ((short)DAT_0203d0ce < 4) goto LAB_080ea14c;
    DAT_0203cb78 = 0x10;
LAB_080ea138:
    *(undefined2 *)(arg0 + 0x1c) = 1;
    break;
  case 0xc:
    uVar2 = sub_080EA934();
    if ((uVar2 & 0xff) == 1) {
      iVar4 = sub_080F2F64(DAT_0203d0ce - 0x8000 & 0xffff);
      sub_080CE62C((uint)*(byte *)(iVar4 + 0xc),(uint)uRam0203d378);
      sub_080EA964();
      DAT_0203cb7a = 0xd;
    }
    break;
  case 0xd:
    uVar2 = sub_080EA934();
    if ((uVar2 & 0xff) != 1) break;
    sub_080F4260((int)(short)DAT_0203d0ce);
    iVar8 = (int)DAT_0300005c;
    iVar4 = sub_080F41F4((int)(short)DAT_0203d0ce);
    if (iVar8 < iVar4) {
      iVar4 = sub_080F2F64(DAT_0203d0ce - 0x8000 & 0xffff);
      DAT_0300005e = 0;
      uVar5 = sub_080EB008((uint)*(byte *)(iVar4 + 0x5d + (int)DAT_0300005c));
      BattleMenu_SetMode(3,uVar5);
      DAT_0203cb7a = 0x12;
      break;
    }
    goto LAB_080ea0f6;
  case 0xe:
    uVar2 = sub_080EA934();
    if ((uVar2 & 0xff) == 1) {
      DAT_0203cb7a = 7;
    }
    break;
  case 0xf:
    uVar2 = sub_080EA934();
    if ((uVar2 & 0xff) == 1) {
      DAT_0203cb7a = 8;
    }
    break;
  case 0x10:
    uVar2 = sub_080EA934();
    if ((uVar2 & 0xff) != 1) break;
LAB_080ea14c:
    DAT_0203cb7a = 9;
    break;
  case 0x11:
    uVar2 = sub_080EA934();
    if ((uVar2 & 0xff) == 1) {
      DAT_0203cb7a = 5;
      DAT_0203d0ce = DAT_0203d0ce + 1;
      if ((int)(uVar9 * 0x10000) <= (int)((uint)DAT_0203d0ce * 0x10000)) {
        DAT_0203cb7a = 6;
      }
    }
    break;
  case 0x12:
    uVar2 = sub_080EA934();
    if ((uVar2 & 0xff) != 1) break;
    iVar4 = sub_080F2F64(DAT_0203d0ce - 0x8000 & 0xffff);
    DAT_0300005e = DAT_0300005e + 1;
    pbVar6 = (byte *)(iVar4 + 0x5d + (int)DAT_0300005c + (int)DAT_0300005e);
    if (*pbVar6 != 0xff) {
      uVar5 = sub_080EB008((uint)*pbVar6);
      BattleMenu_SetMode(3,uVar5);
      break;
    }
    sub_080EA528();
LAB_080ea0f6:
    DAT_0203cb7a = 0xb;
    break;
  case 0x14:
    uVar2 = sub_080EA934();
    if ((uVar2 & 0xff) == 1) {
      sub_080E5A3C();
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080ea176. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_080ea168 @ 0x080EA168

void FUN_080ea168(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x080ea176. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EA178 @ 0x080EA178

void sub_080EA178(void)

{
  bool bVar1;
  int arg0;
  int iVar2;
  int iVar3;
  
  arg0 = (int)DAT_0203d0ce;
  bVar1 = false;
  iVar3 = (int)DAT_0300005c;
  iVar2 = sub_080F41F4(arg0);
  if (iVar2 <= iVar3) {
    while (arg0 = arg0 + 1, arg0 < 4) {
      iVar2 = sub_080F3EC8(arg0);
      if ((iVar2 != 0) && (iVar2 = sub_080C0A00(arg0), iVar2 != 0)) {
        bVar1 = true;
      }
    }
    if (!bVar1) {
      DAT_0203c9e0 = 1;
      DAT_0203c9e4 = 1;
      DAT_0203cb7a = 0x13;
      return;
    }
  }
  sub_080EA210();
  sub_080E9870();
  DAT_0203cb7a = 0xd;
  DAT_0203c9e4 = 1;
  DAT_0203c9e0 = 1;
  return;
}


// sub_080EA210 @ 0x080EA210

void sub_080EA210(void)

{
  undefined4 local_18;
  
  local_18 = 0;
  CpuSet(&local_18,&DAT_0203c9e0,0x5000064);
  if (DAT_0203cb70 == 0) {
    DAT_0203cb70 = sub_080AD0FC(0x86bf708,0xffff);
  }
  if (DAT_0203cb74 == 0) {
    DAT_0203cb74 = sub_080AB890(2,0xb,0x1a,2);
  }
  DAT_0203c9e5 = 0;
  Font_ResetGlyphSpriteCache(0x180);
  return;
}


// sub_080EA280 @ 0x080EA280

void sub_080EA280(void)

{
  undefined4 local_10;
  
  local_10 = 0;
  CpuSet(&local_10,&DAT_0203c9e0,0x5000066);
  DAT_0203c9e5 = 0;
  return;
}


// sub_080EA2AC @ 0x080EA2AC

void sub_080EA2AC(void)

{
  undefined4 local_14;
  
  local_14 = 0;
  CpuSet(&local_14,&DAT_0203c9e0,0x5000066);
  DAT_0203cb70 = sub_080AD0FC(0x86bf708,0xffff);
  DAT_0203cb74 = sub_080AB890(2,0xd,0x1a,2);
  DAT_0203c9e5 = 1;
  Font_ResetGlyphSpriteCache(0x180);
  return;
}


// sub_080EA314 @ 0x080EA314

uint sub_080EA314(short *arg0)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = 1;
  sVar1 = *arg0;
  while ((sVar1 != 0 && (sVar1 != 0x301))) {
    if (sVar1 == 0x300) {
      uVar2 = uVar2 + 1 & 0xff;
    }
    arg0 = arg0 + 1;
    sVar1 = *arg0;
  }
  if (uVar2 == 4) {
    sub_080AB98C(DAT_0203cb74,7);
  }
  else {
    sub_080AB98C(DAT_0203cb74,uVar2 << 1);
  }
  return uVar2;
}


// BattleMenu_SetMode @ 0x080EA37C

void BattleMenu_SetMode(undefined4 arg0,short *arg1)

{
  short sVar1;
  undefined4 uVar2;
  short *psVar3;
  undefined4 local_18;
  
  if (DAT_0203c9e7 != '\x01') {
    DAT_0203c9e0 = (char)arg0;
    DAT_0203c9e8 = arg1;
    if ((byte)((char)arg0 - 7U) < 2) {
      local_18 = 0;
      CpuSet(&local_18,&DAT_0203ca6c,0x5000020);
    }
    else {
      local_18 = 0;
      CpuSet(&local_18,&DAT_0203c9ec,0x5000020);
    }
    DAT_0203cb6c = 0;
    DAT_0203cb6e = 0;
    switch((char)arg0) {
    case '\0':
      DAT_0203c9e3 = 0;
      DAT_0203c9e2 = 0;
      break;
    case '\x03':
      Font_ResetGlyphSpriteCache(0x180);
      DAT_0203c9e2 = 1;
      DAT_0203c9e3 = 0;
      DAT_0203c9e4 = 0;
      DAT_0203c9e0 = '\x02';
      uVar2 = sub_080EA314(arg1);
      DAT_0203c9e6 = (undefined1)uVar2;
      break;
    case '\x04':
      Font_ResetGlyphSpriteCache(0x180);
      DAT_0203c9e3 = 0;
      DAT_0203c9e2 = 0;
      psVar3 = &DAT_0203c9ec;
      uVar2 = sub_080EA314(arg1);
      DAT_0203c9e6 = (undefined1)uVar2;
      sVar1 = *arg1;
      while (sVar1 != 0) {
        *psVar3 = sVar1;
        arg1 = arg1 + 1;
        psVar3 = psVar3 + 1;
        sVar1 = *arg1;
      }
      break;
    case '\a':
      DAT_0203c9e2 = 1;
      DAT_0203c9e3 = 0;
      DAT_0203c9e4 = 0;
      DAT_0203c9e0 = '\x06';
      DAT_0203c9e6 = 4;
      sub_080AB98C(DAT_0203cb74,7);
      break;
    case '\b':
      Font_ResetGlyphSpriteCache(0x180);
      DAT_0203c9e3 = 0;
      DAT_0203c9e2 = 0;
      psVar3 = &DAT_0203ca6c;
      sVar1 = *arg1;
      while (sVar1 != 0) {
        *psVar3 = sVar1;
        arg1 = arg1 + 1;
        psVar3 = psVar3 + 1;
        sVar1 = *arg1;
      }
      break;
    case '\t':
      Font_ResetGlyphSpriteCache(0x180);
      DAT_0203c9e3 = 0;
      DAT_0203c9e2 = 0;
      psVar3 = &DAT_0203c9ec;
      for (; *arg1 != 0; arg1 = arg1 + 1) {
        *psVar3 = *arg1;
        psVar3 = psVar3 + 1;
      }
      DAT_0203c9e0 = '\x04';
    }
  }
  return;
}


// sub_080EA4F8 @ 0x080EA4F8

void sub_080EA4F8(uint arg0)

{
  undefined4 in_r1;
  
  BattleMenu_SetMode(arg0 & 0xff,in_r1);
  DAT_0203cb6c = 1;
  DAT_0203cb6e = 0x4b;
  return;
}


// sub_080EA528 @ 0x080EA528

void sub_080EA528(void)

{
  BattleMenu_SetMode(0,0);
  return;
}


// sub_080EA538 @ 0x080EA538

void sub_080EA538(void)

{
  short sVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  short *psVar5;
  undefined2 *arg0;
  short *psVar6;
  short *arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar7;
  
  switch(DAT_0203c9e0) {
  default:
    goto switchD_080ea554_caseD_0;
  case 1:
    if ((DAT_030031b8 & 0xf3) != 0) {
      DAT_0203c9e4 = '\x01';
    }
    if ((DAT_0203cb6c == 1) && (DAT_0203cb6e = DAT_0203cb6e + -1, DAT_0203cb6e == 0)) {
      DAT_0203c9e4 = '\x01';
    }
    Text_DrawSpriteString(&DAT_0203c9ec,0,0,0x10);
    if (DAT_0203c9e4 == '\x01') goto switchD_080ea554_caseD_0;
    goto joined_r0x080ea7a4;
  case 2:
    if ((DAT_030031d0 & 1) != 0) {
      DAT_0203c9e2 = '\x01';
    }
    DAT_0203c9e2 = DAT_0203c9e2 + -1;
    arg0_00 = &DAT_0203c9ec;
    if (DAT_0203c9e2 == '\0') {
      uVar4 = Settings_GetBattleMsgSpeed();
      DAT_0203c9e2 = *(char *)((uVar4 & 0xffff) + 0x86bec94);
      bVar2 = DAT_0203c9e3 + 1;
      if (DAT_0203c9e8[(byte)(DAT_0203c9e3 + 1)] == 0x315) {
        DAT_0203c9e2 = '\x0f';
        bVar2 = DAT_0203c9e3 + 2;
      }
      DAT_0203c9e3 = bVar2;
      psVar5 = DAT_0203c9e8;
      psVar6 = arg0_00;
      for (bVar2 = 0; bVar2 < DAT_0203c9e3; bVar2 = bVar2 + 1) {
        if (*psVar5 != 0x315) {
          *psVar6 = *psVar5;
          psVar6 = psVar6 + 1;
        }
        psVar5 = psVar5 + 1;
      }
      if (psVar5[-1] == 0) {
        DAT_0203c9e0 = 1;
        DAT_0203c9e3 = 0;
        DAT_0203c9e2 = '\0';
      }
    }
    break;
  case 4:
    arg0_00 = &DAT_0203c9ec;
    break;
  case 5:
    if ((DAT_030031b8 & 0xf3) != 0) {
      DAT_0203c9e4 = '\x01';
    }
    if (DAT_0203c9ec == 0) {
      arg0 = &DAT_0203ca6c;
      if (DAT_0203ca6c == 0x300) {
        arg0 = &DAT_0203ca6e;
      }
      Text_DrawSpriteString(arg0,0,0,0x10);
    }
    else {
      Text_DrawSpriteString(&DAT_0203c9ec,0,0,0x10);
      uVar4 = 0;
      sVar1 = DAT_0203c9ec;
      while (sVar1 != 0) {
        uVar4 = uVar4 + 1 & 0xff;
        sVar1 = (&DAT_0203c9ec)[uVar4];
      }
      Text_DrawSpriteString(&DAT_0203ca6c,0,0,0x10);
    }
joined_r0x080ea7a4:
    if ((DAT_030031bc >> 4 & 1) == 0) {
      sub_080AA184(0x8001000,0,0,0);
    }
    goto switchD_080ea554_caseD_0;
  case 6:
    if ((DAT_030031d0 & 1) != 0) {
      DAT_0203c9e2 = '\x01';
    }
    DAT_0203c9e2 = DAT_0203c9e2 + -1;
    arg0_00 = &DAT_0203ca6c;
    if (DAT_0203c9e2 == '\0') {
      uVar4 = Settings_GetBattleMsgSpeed();
      DAT_0203c9e2 = *(char *)((uVar4 & 0xffff) + 0x86bec94);
      bVar2 = DAT_0203c9e3 + 1;
      bVar3 = 0;
      bVar7 = DAT_0203c9e3 != 0xff;
      psVar5 = DAT_0203c9e8;
      psVar6 = arg0_00;
      DAT_0203c9e3 = bVar2;
      if (bVar7) {
        do {
          *psVar6 = *psVar5;
          psVar5 = psVar5 + 1;
          psVar6 = psVar6 + 1;
          bVar3 = bVar3 + 1;
        } while (bVar3 < DAT_0203c9e3);
      }
      if (psVar5[-1] == 0) {
        DAT_0203c9e0 = 5;
        DAT_0203c9e3 = 0;
        DAT_0203c9e2 = '\0';
      }
    }
    if (DAT_0203c9ec == 0) {
      if (DAT_0203ca6c == 0x300) {
        arg0_00 = &DAT_0203ca6e;
      }
    }
    else {
      Text_DrawSpriteString(&DAT_0203c9ec,0,0,0x10);
      uVar4 = 0;
      sVar1 = DAT_0203c9ec;
      while (sVar1 != 0) {
        uVar4 = uVar4 + 1 & 0xff;
        sVar1 = (&DAT_0203c9ec)[uVar4];
      }
    }
    break;
  case 8:
    Text_DrawSpriteString(&DAT_0203c9ec,0,0,0x10);
    Text_DrawSpriteString(&DAT_0203ca6c,0,0,0x10);
    goto switchD_080ea554_caseD_0;
  }
  Text_DrawSpriteString(arg0_00,0,0,0x10);
switchD_080ea554_caseD_0:
                    /* WARNING: Could not recover jumptable at 0x080ea932. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EA934 @ 0x080EA934

undefined4 sub_080EA934(void)

{
  undefined4 uVar1;
  
  if ((DAT_0203c9e7 == '\x01') ||
     (((DAT_0203c9e0 == '\x01' || (DAT_0203c9e0 == '\x05')) && (DAT_0203c9e4 == '\x01')))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080EA964 @ 0x080EA964

void sub_080EA964(void)

{
  DAT_0203c9e0 = 0;
  if (DAT_0203cb74 != 0) {
    sub_080AB91C(DAT_0203cb74,1);
    DAT_0203cb74 = 0;
  }
  if (DAT_0203cb70 != 0) {
    sub_080AD1FC(DAT_0203cb70);
    DAT_0203cb70 = 0;
  }
  return;
}


// sub_080EA9A4 @ 0x080EA9A4

void sub_080EA9A4(void)

{
  DAT_0203c9e0 = 0;
  if (DAT_0203cb74 != 0) {
    sub_080AB91C(DAT_0203cb74,0);
    DAT_0203cb74 = 0;
  }
  if (DAT_0203cb70 != 0) {
    sub_080AD1FC(DAT_0203cb70);
    DAT_0203cb70 = 0;
  }
  return;
}


// sub_080EA9E8 @ 0x080EA9E8

void sub_080EA9E8(undefined4 arg0)

{
  DAT_0203c9e7 = (undefined1)arg0;
  return;
}


// sub_080EA9F8 @ 0x080EA9F8

undefined4 sub_080EA9F8(uint arg0)

{
  return *(undefined4 *)((arg0 & 0xff) * 4 + 0x86bec98);
}


// MessageBox_ComposeRaceNameText @ 0x080EAA08

undefined2 * MessageBox_ComposeRaceNameText(uint arg0,short *arg1)

{
  short sVar1;
  byte bVar2;
  char *pcVar3;
  short *psVar4;
  short *psVar5;
  undefined4 local_14;
  
  if (DAT_0203c9e7 != '\x01') {
    pcVar3 = (char *)sub_080BF648(arg0 & 0xffff);
    local_14 = 0;
    psVar5 = &DAT_0203caec;
    CpuSet(&local_14,&DAT_0203caec,0x5000020);
    for (psVar4 = (short *)Race_GetName((int)*pcVar3 & 0xffff); *psVar4 != 0; psVar4 = psVar4 + 1) {
      *psVar5 = *psVar4;
      psVar5 = psVar5 + 1;
    }
    psVar4 = (short *)(pcVar3 + 0x22);
    bVar2 = 0;
    sVar1 = *(short *)(pcVar3 + 0x22);
    while (sVar1 != 0) {
      *psVar5 = *psVar4;
      psVar4 = psVar4 + 1;
      psVar5 = psVar5 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar4;
    }
    for (; *arg1 != 0; arg1 = arg1 + 1) {
      *psVar5 = *arg1;
      psVar5 = psVar5 + 1;
    }
  }
  return &DAT_0203caec;
}


// MessageBox_ComposeNameText @ 0x080EAAB0

undefined2 * MessageBox_ComposeNameText(uint arg0,short *arg1)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  undefined4 local_14;
  
  if (DAT_0203c9e7 != '\x01') {
    iVar3 = sub_080BF648(arg0 & 0xffff);
    local_14 = 0;
    psVar5 = &DAT_0203caec;
    CpuSet(&local_14,&DAT_0203caec,0x5000020);
    psVar4 = (short *)(iVar3 + 0x22);
    bVar2 = 0;
    sVar1 = *(short *)(iVar3 + 0x22);
    while (sVar1 != 0) {
      *psVar5 = *psVar4;
      psVar4 = psVar4 + 1;
      psVar5 = psVar5 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar4;
    }
    for (; *arg1 != 0; arg1 = arg1 + 1) {
      *psVar5 = *arg1;
      psVar5 = psVar5 + 1;
    }
  }
  return &DAT_0203caec;
}


// sub_080EAB3C @ 0x080EAB3C

void sub_080EAB3C(uint arg0,uint arg1,short *arg2)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  undefined4 local_18;
  
  if (DAT_0203c9e7 != '\x01') {
    local_18 = 0;
    psVar5 = &DAT_0203caec;
    CpuSet(&local_18,&DAT_0203caec,0x5000020);
    iVar3 = sub_080BF648(arg0 & 0xffff);
    psVar4 = (short *)(iVar3 + 0x22);
    bVar2 = 0;
    sVar1 = *(short *)(iVar3 + 0x22);
    while (sVar1 != 0) {
      *psVar5 = *psVar4;
      psVar4 = psVar4 + 1;
      psVar5 = psVar5 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar4;
    }
    *psVar5 = 0x143;
    psVar5[1] = 0x300;
    psVar5 = psVar5 + 2;
    iVar3 = sub_080BF648(arg1 & 0xffff);
    psVar4 = (short *)(iVar3 + 0x22);
    bVar2 = 0;
    sVar1 = *(short *)(iVar3 + 0x22);
    while (sVar1 != 0) {
      *psVar5 = *psVar4;
      psVar4 = psVar4 + 1;
      psVar5 = psVar5 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar4;
    }
    for (; *arg2 != 0; arg2 = arg2 + 1) {
      *psVar5 = *arg2;
      psVar5 = psVar5 + 1;
    }
  }
  return;
}


// MessageBox_ComposeSpeciesText @ 0x080EAC0C

undefined4 MessageBox_ComposeSpeciesText(uint arg0,uint arg1,int arg2,int arg3)

{
  ushort uVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  ushort *puVar8;
  ushort *arg1_00;
  short sVar9;
  code *UNRECOVERED_JUMPTABLE;
  ushort *in_stack_00000000;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  sVar9 = 0;
  sVar3 = 0;
  sVar4 = 0;
  local_28 = arg2;
  local_24 = arg3;
  if (DAT_0203c9e7 != '\x01') {
    local_2c = 0;
    arg1_00 = &DAT_0203caec;
    CpuSet(&local_2c,&DAT_0203caec,0x5000020);
    for (; (*in_stack_00000000 != 0x301 && (*in_stack_00000000 != 0));
        in_stack_00000000 = in_stack_00000000 + 1) {
      uVar1 = *in_stack_00000000;
      if (uVar1 == 799) {
        if (sVar3 == 0) {
          pcVar5 = (char *)sub_080BF648(arg0 & 0xffff);
        }
        else {
          pcVar5 = (char *)sub_080BF648(arg1 & 0xffff);
        }
        puVar8 = (ushort *)Race_GetName((int)*pcVar5 & 0xffff);
        sVar3 = sVar3 + 1;
        uVar1 = *puVar8;
        while (uVar1 != 0) {
          *arg1_00 = uVar1;
          puVar8 = puVar8 + 1;
          arg1_00 = arg1_00 + 1;
          uVar1 = *puVar8;
        }
      }
      else if (uVar1 < 800) {
        if (uVar1 == 0x31e) {
          if (sVar9 == 0) {
            iVar6 = sub_080BF648(arg0 & 0xffff);
          }
          else {
            iVar6 = sub_080BF648(arg1 & 0xffff);
          }
          puVar8 = (ushort *)(iVar6 + 0x22);
          bVar2 = 0;
          sVar9 = sVar9 + 1;
          uVar1 = *(ushort *)(iVar6 + 0x22);
          while (uVar1 != 0) {
            *arg1_00 = *puVar8;
            puVar8 = puVar8 + 1;
            arg1_00 = arg1_00 + 1;
            bVar2 = bVar2 + 1;
            if (7 < bVar2) break;
            uVar1 = *puVar8;
          }
        }
        else {
LAB_080ead48:
          *arg1_00 = *in_stack_00000000;
LAB_080ead4c:
          arg1_00 = arg1_00 + 1;
        }
      }
      else {
        if (uVar1 == 0x323) {
          iVar6 = local_24;
          if (sVar4 == 0) {
            iVar6 = local_28;
          }
          *arg1_00 = *(ushort *)(iVar6 * 2 + 0x86bed48);
          sVar4 = sVar4 + 1;
          goto LAB_080ead4c;
        }
        if (uVar1 != 0x324) goto LAB_080ead48;
        arg1_00 = (ushort *)sub_080EBE7C(0,arg1_00);
      }
    }
    *arg1_00 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080ead74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar7 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return uVar7;
}


// Battle_BuildActorPrompt @ 0x080EAD80

undefined2 * Battle_BuildActorPrompt(uint arg0)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  short local_24 [8];
  undefined4 local_14;
  
  psVar4 = local_24;
  iVar3 = sub_080F2F64(arg0 & 0xff);
  if (DAT_0203c9e7 != '\x01') {
    local_14 = 0;
    psVar5 = &DAT_0203caec;
    CpuSet(&local_14,&DAT_0203caec,0x5000020);
    if (*(byte *)(iVar3 + 0xc) < 4) {
      Combatant_DecodeName(iVar3,local_24);
    }
    else {
      iVar3 = sub_080BF648((uint)*(ushort *)(iVar3 + 0x12));
      psVar4 = (short *)(iVar3 + 0x22);
    }
    bVar2 = 0;
    sVar1 = *psVar4;
    while (sVar1 != 0) {
      *psVar5 = sVar1;
      psVar4 = psVar4 + 1;
      psVar5 = psVar5 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar4;
    }
    do {
      psVar4 = psVar5;
      psVar5 = psVar4 + -1;
    } while (psVar4[-1] == 0x70);
    for (psVar5 = (short *)0x81236bc; *psVar5 != 0; psVar5 = psVar5 + 1) {
      *psVar4 = *psVar5;
      psVar4 = psVar4 + 1;
    }
  }
  return &DAT_0203caec;
}


// sub_080EAE30 @ 0x080EAE30

undefined4 sub_080EAE30(int arg0)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  short *psVar6;
  short *psVar7;
  code *UNRECOVERED_JUMPTABLE;
  short local_24 [8];
  undefined4 local_14;
  
  psVar6 = local_24;
  if (DAT_0203c9e7 != '\x01') {
    local_14 = 0;
    psVar5 = &DAT_0203caec;
    CpuSet(&local_14,&DAT_0203caec,0x5000020);
    if (*(byte *)(arg0 + 0xc) < 4) {
      Combatant_DecodeName(arg0,local_24);
    }
    else {
      iVar3 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
      psVar6 = (short *)(iVar3 + 0x22);
    }
    bVar2 = 0;
    sVar1 = *psVar6;
    while (sVar1 != 0) {
      *psVar5 = sVar1;
      psVar6 = psVar6 + 1;
      psVar5 = psVar5 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar6;
    }
    do {
      psVar6 = psVar5;
      psVar5 = psVar6 + -1;
    } while (psVar6[-1] == 0x70);
    *psVar6 = 0x14a;
    psVar7 = (short *)&UNK_0812370a;
    psVar6[1] = 0x300;
    psVar6 = psVar6 + 2;
    iVar3 = sub_080BF5C0((uint)*(byte *)(arg0 + 0x5c));
    psVar5 = (short *)(iVar3 + 6);
    bVar2 = 0;
    sVar1 = *(short *)(iVar3 + 6);
    while (sVar1 != 0) {
      *psVar6 = *psVar5;
      psVar5 = psVar5 + 1;
      psVar6 = psVar6 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar5;
    }
    for (; *psVar7 != 0; psVar7 = psVar7 + 1) {
      *psVar6 = *psVar7;
      psVar6 = psVar6 + 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080eaf14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return uVar4;
}


// sub_080EAF1C @ 0x080EAF1C

undefined4 sub_080EAF1C(int arg0,uint arg1)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  short *psVar6;
  short *psVar7;
  code *UNRECOVERED_JUMPTABLE;
  short local_28 [8];
  undefined4 local_18;
  
  psVar6 = local_28;
  if (DAT_0203c9e7 != '\x01') {
    local_18 = 0;
    psVar5 = &DAT_0203caec;
    CpuSet(&local_18,&DAT_0203caec,0x5000020);
    if (*(byte *)(arg0 + 0xc) < 4) {
      Combatant_DecodeName(arg0,local_28);
    }
    else {
      iVar3 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
      psVar6 = (short *)(iVar3 + 0x22);
    }
    bVar2 = 0;
    sVar1 = *psVar6;
    while (sVar1 != 0) {
      *psVar5 = sVar1;
      psVar6 = psVar6 + 1;
      psVar5 = psVar5 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar6;
    }
    do {
      psVar6 = psVar5;
      psVar5 = psVar6 + -1;
    } while (psVar6[-1] == 0x70);
    *psVar6 = 0x14a;
    psVar7 = (short *)&UNK_0812370a;
    psVar6[1] = 0x300;
    psVar6 = psVar6 + 2;
    iVar3 = sub_080BF5C0(arg1 & 0xffff);
    psVar5 = (short *)(iVar3 + 6);
    bVar2 = 0;
    sVar1 = *(short *)(iVar3 + 6);
    while (sVar1 != 0) {
      *psVar6 = *psVar5;
      psVar5 = psVar5 + 1;
      psVar6 = psVar6 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar5;
    }
    for (; *psVar7 != 0; psVar7 = psVar7 + 1) {
      *psVar6 = *psVar7;
      psVar6 = psVar6 + 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080eb000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return uVar4;
}


// sub_080EB008 @ 0x080EB008

dword sub_080EB008(uint arg0)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  undefined4 uStack_10;
  
  uStack_10 = 0;
  psVar5 = &DAT_0203caec;
  CpuSet(&uStack_10,&DAT_0203caec,0x5000020);
  iVar3 = sub_080BF5C0(arg0 & 0xffff);
  psVar4 = (short *)(iVar3 + 6);
  bVar2 = 0;
  sVar1 = *(short *)(iVar3 + 6);
  while (sVar1 != 0) {
    *psVar5 = *psVar4;
    psVar4 = psVar4 + 1;
    psVar5 = psVar5 + 1;
    bVar2 = bVar2 + 1;
    if (7 < bVar2) break;
    sVar1 = *psVar4;
  }
  for (psVar4 = (short *)0x812430c; *psVar4 != 0; psVar4 = psVar4 + 1) {
    *psVar5 = *psVar4;
    psVar5 = psVar5 + 1;
  }
  return 0x203caec;
}


// sub_080EB080 @ 0x080EB080

undefined4 sub_080EB080(int arg0)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  short *psVar6;
  short *psVar7;
  code *UNRECOVERED_JUMPTABLE;
  short local_24 [8];
  undefined4 local_14;
  
  psVar6 = local_24;
  if (DAT_0203c9e7 != '\x01') {
    local_14 = 0;
    psVar5 = &DAT_0203caec;
    CpuSet(&local_14,&DAT_0203caec,0x5000020);
    if (*(byte *)(arg0 + 0xc) < 4) {
      Combatant_DecodeName(arg0,local_24);
    }
    else {
      iVar3 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
      psVar6 = (short *)(iVar3 + 0x22);
    }
    bVar2 = 0;
    sVar1 = *psVar6;
    while (sVar1 != 0) {
      *psVar5 = sVar1;
      psVar6 = psVar6 + 1;
      psVar5 = psVar5 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar6;
    }
    do {
      psVar6 = psVar5;
      psVar5 = psVar6 + -1;
    } while (psVar6[-1] == 0x70);
    *psVar6 = 0x14a;
    psVar7 = (short *)&UNK_081236fe;
    psVar6[1] = 0x300;
    psVar6 = psVar6 + 2;
    iVar3 = Action_GetRecord((uint)*(byte *)(arg0 + 0x5c));
    psVar5 = (short *)(iVar3 + 0xc);
    bVar2 = 0;
    sVar1 = *(short *)(iVar3 + 0xc);
    while (sVar1 != 0) {
      *psVar6 = *psVar5;
      psVar5 = psVar5 + 1;
      psVar6 = psVar6 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar5;
    }
    for (; *psVar7 != 0; psVar7 = psVar7 + 1) {
      *psVar6 = *psVar7;
      psVar6 = psVar6 + 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080eb166. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return uVar4;
}


// Battle_BuildStatusResultText @ 0x080EB16C

void Battle_BuildStatusResultText(int arg0)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  code *UNRECOVERED_JUMPTABLE;
  short local_24 [8];
  undefined4 local_14;
  
  psVar4 = local_24;
  if (DAT_0203c9e7 != '\x01') {
    local_14 = 0;
    psVar5 = &DAT_0203caec;
    CpuSet(&local_14,&DAT_0203caec,0x5000020);
    if (*(byte *)(arg0 + 0xc) < 4) {
      Combatant_DecodeName(arg0,local_24);
    }
    else {
      iVar3 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
      psVar4 = (short *)(iVar3 + 0x22);
    }
    bVar2 = 0;
    sVar1 = *psVar4;
    while (sVar1 != 0) {
      *psVar5 = sVar1;
      psVar4 = psVar4 + 1;
      psVar5 = psVar5 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar4;
    }
    do {
      psVar4 = psVar5;
      psVar5 = psVar4 + -1;
    } while (psVar4[-1] == 0x70);
    for (psVar5 = *(short **)((*(byte *)(arg0 + 0x5c) - 0x40) * 4 + 0x86bed5c); *psVar5 != 0;
        psVar5 = psVar5 + 1) {
      *psVar4 = *psVar5;
      psVar4 = psVar4 + 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080eb21a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return;
}


// Battle_BuildCombatActionList @ 0x080EB220

undefined4 Battle_BuildCombatActionList(int arg0,uint arg1)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  short *psVar6;
  code *UNRECOVERED_JUMPTABLE;
  short local_24 [8];
  undefined4 local_14;
  
  psVar5 = local_24;
  if (DAT_0203c9e7 != '\x01') {
    local_14 = 0;
    psVar6 = &DAT_0203caec;
    CpuSet(&local_14,&DAT_0203caec,0x5000020);
    if (*(byte *)(arg0 + 0xc) < 4) {
      Combatant_DecodeName(arg0,local_24);
    }
    else {
      iVar3 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
      psVar5 = (short *)(iVar3 + 0x22);
    }
    bVar2 = 0;
    sVar1 = *psVar5;
    while (sVar1 != 0) {
      *psVar6 = sVar1;
      psVar5 = psVar5 + 1;
      psVar6 = psVar6 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar5;
    }
    do {
      psVar5 = psVar6;
      psVar6 = psVar5 + -1;
    } while (psVar5[-1] == 0x70);
    for (psVar6 = *(short **)((arg1 & 0xff) * 4 + 0x86bef5c); *psVar6 != 0; psVar6 = psVar6 + 1) {
      *psVar5 = *psVar6;
      psVar5 = psVar5 + 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080eb2cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return uVar4;
}


// Battle_BuildNamePrependText @ 0x080EB2D4

undefined4 Battle_BuildNamePrependText(uint arg0,short *arg1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  short *psVar4;
  short *psVar5;
  code *UNRECOVERED_JUMPTABLE;
  short asStack_28 [8];
  undefined4 local_18;
  
  psVar4 = asStack_28;
  iVar2 = sub_080F2F64(arg0 & 0xffff);
  if (DAT_0203c9e7 != '\x01') {
    local_18 = 0;
    psVar5 = &DAT_0203caec;
    CpuSet(&local_18,&DAT_0203caec,0x5000020);
    if (*(byte *)(iVar2 + 0xc) < 4) {
      Combatant_DecodeName(iVar2,asStack_28);
    }
    else {
      iVar2 = sub_080BF648((uint)*(ushort *)(iVar2 + 0x12));
      psVar4 = (short *)(iVar2 + 0x22);
    }
    bVar1 = 0;
    do {
      if (*psVar4 == 0) break;
      *psVar5 = *psVar4;
      psVar4 = psVar4 + 1;
      psVar5 = psVar5 + 1;
      bVar1 = bVar1 + 1;
    } while (bVar1 < 8);
    do {
      psVar4 = psVar5;
      psVar5 = psVar4 + -1;
    } while (psVar4[-1] == 0x70);
    for (; *arg1 != 0; arg1 = arg1 + 1) {
      *psVar4 = *arg1;
      psVar4 = psVar4 + 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080eb374. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return uVar3;
}


// Battle_BuildNamePrefixText @ 0x080EB37C

undefined4 Battle_BuildNamePrefixText(uint arg0,short *arg1)

{
  short sVar1;
  short *psVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  short *psVar8;
  code *UNRECOVERED_JUMPTABLE;
  short asStack_28 [8];
  undefined4 uStack_18;
  
  psVar7 = asStack_28;
  if ((DAT_0203c9e7 != '\x01') && (iVar5 = sub_080F2F64(arg0 & 0xffff), DAT_0203c9e7 != '\x01')) {
    uStack_18 = 0;
    psVar8 = &DAT_0203caec;
    CpuSet(&uStack_18,&DAT_0203caec,0x5000020);
    for (sVar4 = *arg1; arg1 = arg1 + 1, sVar4 != 0; sVar4 = sVar4 + -1) {
      *psVar8 = *arg1;
      psVar8 = psVar8 + 1;
    }
    if (*(byte *)(iVar5 + 0xc) < 4) {
      Combatant_DecodeName(iVar5,asStack_28);
    }
    else {
      iVar5 = sub_080BF648((uint)*(ushort *)(iVar5 + 0x12));
      psVar7 = (short *)(iVar5 + 0x22);
    }
    bVar3 = 0;
    do {
      if (*psVar7 == 0) break;
      *psVar8 = *psVar7;
      psVar7 = psVar7 + 1;
      psVar8 = psVar8 + 1;
      bVar3 = bVar3 + 1;
    } while (bVar3 < 8);
    sVar1 = *arg1;
    sVar4 = psVar8[-1];
    psVar7 = psVar8 + -1;
    while (psVar2 = psVar7, sVar4 == 0x70) {
      psVar7 = psVar2 + -1;
      sVar4 = *psVar7;
      psVar8 = psVar2;
    }
    while (sVar1 != 0) {
      *psVar8 = sVar1;
      arg1 = arg1 + 1;
      psVar8 = psVar8 + 1;
      sVar1 = *arg1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080eb44e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar6 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return uVar6;
}


// Battle_BuildDamageDealtText @ 0x080EB454

undefined4 Battle_BuildDamageDealtText(int arg0,undefined4 arg1,short *arg2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  ushort *puVar5;
  uint uVar6;
  short *psVar7;
  short *psVar8;
  undefined4 unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  ushort auStack_2c [8];
  undefined4 local_1c;
  
  puVar5 = auStack_2c;
  if (DAT_0203c9e7 != '\x01') {
    local_1c = 0;
    psVar7 = &DAT_0203caec;
    CpuSet(&local_1c,&DAT_0203caec,0x5000020);
    if (*(byte *)(arg0 + 0xc) < 4) {
      Combatant_DecodeName(arg0,auStack_2c);
    }
    else {
      iVar2 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
      puVar5 = (ushort *)(iVar2 + 0x22);
    }
    bVar1 = 0;
    do {
      if (*puVar5 == 0) break;
      *psVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      psVar7 = psVar7 + 1;
      bVar1 = bVar1 + 1;
    } while (bVar1 < 8);
    do {
      psVar8 = psVar7;
      psVar7 = psVar8 + -1;
    } while (psVar8[-1] == 0x70);
    *psVar8 = *arg2;
    psVar8[1] = arg2[1];
    psVar7 = arg2 + 2;
    psVar8 = psVar8 + 2;
    pbVar3 = (byte *)sub_080A9CC0(arg1);
    uVar6 = 0;
    do {
      auStack_2c[uVar6] = (ushort)*pbVar3;
      uVar6 = uVar6 + 1 & 0xff;
      pbVar3 = pbVar3 + 1;
    } while (uVar6 < 8);
    arg2 = (short *)&SupervisorCall;
    do {
      if (auStack_2c[(int)arg2 + -1] != 0) break;
      arg2 = (short *)((uint)((int)arg2 + -1) & 0xff);
    } while (arg2 != (short *)0x1);
    if (arg2 != (short *)0x0) {
      do {
        *psVar8 = *(short *)((uint)auStack_2c[(int)arg2 + -1] * 2 + 0x86bef74);
        psVar8 = psVar8 + 1;
        arg2 = (short *)((uint)((int)arg2 + -1) & 0xff);
      } while (arg2 != (short *)0x0);
      arg2 = (short *)0x0;
    }
    for (; *psVar7 != 0; psVar7 = psVar7 + 1) {
      *psVar8 = *psVar7;
      psVar8 = psVar8 + 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080eb568. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec,UNRECOVERED_JUMPTABLE,arg2,unaff_r8);
  return uVar4;
}


// Battle_BuildDefeatedTargetText @ 0x080EB570

undefined4 Battle_BuildDefeatedTargetText(int arg0)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  short *psVar6;
  code *UNRECOVERED_JUMPTABLE;
  short local_20 [8];
  undefined4 local_10;
  
  psVar5 = local_20;
  if (DAT_0203c9e7 != '\x01') {
    local_10 = 0;
    psVar6 = &DAT_0203caec;
    CpuSet(&local_10,&DAT_0203caec,0x5000020);
    if (*(byte *)(arg0 + 0xc) < 4) {
      Combatant_DecodeName(arg0,local_20);
    }
    else {
      iVar3 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
      psVar5 = (short *)(iVar3 + 0x22);
    }
    bVar2 = 0;
    sVar1 = *psVar5;
    while (sVar1 != 0) {
      *psVar6 = sVar1;
      psVar5 = psVar5 + 1;
      psVar6 = psVar6 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar5;
    }
    do {
      psVar5 = psVar6;
      psVar6 = psVar5 + -1;
    } while (psVar5[-1] == 0x70);
    for (psVar6 = (short *)0x8123bc2; *psVar6 != 0; psVar6 = psVar6 + 1) {
      *psVar5 = *psVar6;
      psVar5 = psVar5 + 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080eb612. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return uVar4;
}


// Battle_BuildDodgeText @ 0x080EB618

undefined2 * Battle_BuildDodgeText(int arg0)

{
  short sVar1;
  short *psVar2;
  byte bVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  short local_28 [8];
  undefined4 local_18;
  
  psVar5 = local_28;
  if (DAT_0203c9e7 != '\x01') {
    local_18 = 0;
    CpuSet(&local_18,&DAT_0203caec,0x5000020);
    DAT_0203caec = 0x15f;
    DAT_0203caee = 0x13e;
    DAT_0203caf0 = 0x13a;
    DAT_0203caf2 = 9;
    DAT_0203caf4 = 0x300;
    psVar6 = &DAT_0203caf6;
    if (*(byte *)(arg0 + 0xc) < 4) {
      Combatant_DecodeName(arg0,local_28);
    }
    else {
      iVar4 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
      psVar5 = (short *)(iVar4 + 0x22);
    }
    bVar3 = 0;
    sVar1 = *psVar5;
    while (sVar1 != 0) {
      *psVar6 = sVar1;
      psVar5 = psVar5 + 1;
      psVar6 = psVar6 + 1;
      bVar3 = bVar3 + 1;
      if (7 < bVar3) break;
      sVar1 = *psVar5;
    }
    sVar1 = psVar6[-1];
    psVar5 = psVar6 + -1;
    while (psVar2 = psVar5, sVar1 == 0x70) {
      psVar5 = psVar2 + -1;
      sVar1 = *psVar5;
      psVar6 = psVar2;
    }
    *psVar6 = 0x14a;
    psVar6[1] = 0x126;
    psVar6[2] = 0x16a;
    psVar6[3] = 0x132;
    psVar6[4] = 0x13a;
  }
  return &DAT_0203caec;
}


// Battle_BuildActorStatusText @ 0x080EB71C

undefined2 * Battle_BuildActorStatusText(int arg0,undefined2 *arg1)

{
  short sVar1;
  short *psVar2;
  byte bVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  short local_28 [8];
  undefined4 local_18;
  
  psVar5 = local_28;
  if (DAT_0203c9e7 != '\x01') {
    local_18 = 0;
    CpuSet(&local_18,&DAT_0203caec,0x5000020);
    DAT_0203caec = *arg1;
    DAT_0203caee = arg1[1];
    DAT_0203caf0 = arg1[2];
    DAT_0203caf2 = arg1[3];
    DAT_0203caf4 = arg1[4];
    psVar6 = &DAT_0203caf6;
    if (*(byte *)(arg0 + 0xc) < 4) {
      Combatant_DecodeName(arg0,local_28);
    }
    else {
      iVar4 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
      psVar5 = (short *)(iVar4 + 0x22);
    }
    bVar3 = 0;
    sVar1 = *psVar5;
    while (sVar1 != 0) {
      *psVar6 = sVar1;
      psVar5 = psVar5 + 1;
      psVar6 = psVar6 + 1;
      bVar3 = bVar3 + 1;
      if (7 < bVar3) break;
      sVar1 = *psVar5;
    }
    sVar1 = psVar6[-1];
    psVar5 = psVar6 + -1;
    while (psVar2 = psVar5, sVar1 == 0x70) {
      psVar5 = psVar2 + -1;
      sVar1 = *psVar5;
      psVar6 = psVar2;
    }
    *psVar6 = arg1[5];
    psVar6[1] = arg1[6];
    psVar6[2] = arg1[7];
    psVar6[3] = arg1[8];
  }
  return &DAT_0203caec;
}


// sub_080EB810 @ 0x080EB810

void sub_080EB810(int arg0,short *arg1)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  byte bVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  code *UNRECOVERED_JUMPTABLE;
  short asStack_28 [8];
  undefined4 local_18;
  
  psVar6 = asStack_28;
  if (DAT_0203c9e7 != '\x01') {
    local_18 = 0;
    psVar7 = &DAT_0203caec;
    CpuSet(&local_18,&DAT_0203caec,0x5000020);
    sVar1 = *arg1;
    while (sVar1 != 0x300) {
      *psVar7 = sVar1;
      arg1 = arg1 + 1;
      psVar7 = psVar7 + 1;
      sVar1 = *arg1;
    }
    *psVar7 = *arg1;
    psVar8 = arg1 + 1;
    psVar7 = psVar7 + 1;
    if (*(byte *)(arg0 + 0xc) < 4) {
      Combatant_DecodeName(arg0,asStack_28);
    }
    else {
      iVar5 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
      psVar6 = (short *)(iVar5 + 0x22);
    }
    bVar4 = 0;
    do {
      if (*psVar6 == 0) break;
      *psVar7 = *psVar6;
      psVar6 = psVar6 + 1;
      psVar7 = psVar7 + 1;
      bVar4 = bVar4 + 1;
    } while (bVar4 < 8);
    sVar2 = *psVar8;
    sVar1 = psVar7[-1];
    psVar6 = psVar7 + -1;
    while (psVar3 = psVar6, sVar1 == 0x70) {
      psVar6 = psVar3 + -1;
      sVar1 = *psVar6;
      psVar7 = psVar3;
    }
    while (sVar2 != 0) {
      *psVar7 = sVar2;
      psVar8 = psVar8 + 1;
      psVar7 = psVar7 + 1;
      sVar2 = *psVar8;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080eb8d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return;
}


// Battle_BuildRaceCountText @ 0x080EB8DC

undefined2 * Battle_BuildRaceCountText(uint arg0,uint arg1,int arg2)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  ushort auStack_2c [8];
  undefined4 uStack_1c;
  
  if (DAT_0203c9e7 != '\x01') {
    uStack_1c = 0;
    psVar6 = &DAT_0203caec;
    CpuSet(&uStack_1c,&DAT_0203caec,0x5000020);
    iVar3 = sub_080BF648(arg0 & 0xffff);
    psVar7 = (short *)(iVar3 + 0x22);
    bVar2 = 0;
    sVar1 = *(short *)(iVar3 + 0x22);
    while (sVar1 != 0) {
      *psVar6 = *psVar7;
      psVar7 = psVar7 + 1;
      psVar6 = psVar6 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar7;
    }
    pbVar4 = (byte *)sub_080A9CC0(arg1 & 0xffff);
    uVar5 = 0;
    do {
      auStack_2c[uVar5] = (ushort)*pbVar4;
      uVar5 = uVar5 + 1 & 0xff;
      pbVar4 = pbVar4 + 1;
    } while (uVar5 < 8);
    uVar5 = 8;
    psVar7 = (short *)(arg2 + 8);
    do {
      if (auStack_2c[uVar5 - 1] != 0) break;
      uVar5 = uVar5 - 1 & 0xff;
    } while (uVar5 != 1);
    for (; uVar5 != 0; uVar5 = uVar5 - 1 & 0xff) {
      *psVar6 = *(short *)((uint)auStack_2c[uVar5 - 1] * 2 + 0x86bef74);
      psVar6 = psVar6 + 1;
    }
    *psVar6 = *(short *)(arg2 + 6);
    psVar6[1] = *psVar7;
    psVar6 = psVar6 + 2;
    *psVar6 = 0x300;
    while( true ) {
      psVar7 = psVar7 + 1;
      psVar6 = psVar6 + 1;
      if (*psVar7 == 0) break;
      *psVar6 = *psVar7;
    }
  }
  return &DAT_0203caec;
}


// Battle_BuildRewardText @ 0x080EB9EC

undefined4 Battle_BuildRewardText(int arg0,undefined4 arg1,short *arg2)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 uVar7;
  short *psVar8;
  ushort *puVar9;
  uint uVar10;
  short *psVar11;
  short *psVar12;
  undefined4 unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  ushort auStack_2c [8];
  undefined4 uStack_1c;
  
  puVar9 = auStack_2c;
  if (DAT_0203c9e7 != '\x01') {
    uStack_1c = 0;
    psVar11 = &DAT_0203caec;
    CpuSet(&uStack_1c,&DAT_0203caec,0x5000020);
    for (; *arg2 != 0; arg2 = arg2 + 1) {
      *psVar11 = *arg2;
      psVar11 = psVar11 + 1;
    }
    psVar12 = arg2 + 1;
    if (*(byte *)(arg0 + 0xc) < 4) {
      Combatant_DecodeName(arg0,auStack_2c);
    }
    else {
      iVar5 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
      puVar9 = (ushort *)(iVar5 + 0x22);
    }
    bVar4 = 0;
    do {
      if (*puVar9 == 0) break;
      *psVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      psVar11 = psVar11 + 1;
      bVar4 = bVar4 + 1;
    } while (bVar4 < 8);
    sVar2 = *psVar12;
    sVar1 = psVar11[-1];
    psVar8 = psVar11 + -1;
    while (psVar3 = psVar8, sVar1 == 0x70) {
      psVar8 = psVar3 + -1;
      sVar1 = *psVar8;
      psVar11 = psVar3;
    }
    while (sVar2 != 0) {
      *psVar11 = sVar2;
      psVar12 = psVar12 + 1;
      psVar11 = psVar11 + 1;
      sVar2 = *psVar12;
    }
    psVar12 = psVar12 + 1;
    pbVar6 = (byte *)sub_080A9CC0(arg1);
    uVar10 = 0;
    do {
      auStack_2c[uVar10] = (ushort)*pbVar6;
      uVar10 = uVar10 + 1 & 0xff;
      pbVar6 = pbVar6 + 1;
    } while (uVar10 < 8);
    arg2 = (short *)&SupervisorCall;
    do {
      if (auStack_2c[(int)arg2 + -1] != 0) break;
      arg2 = (short *)((uint)((int)arg2 + -1) & 0xff);
    } while (arg2 != (short *)0x1);
    if (arg2 != (short *)0x0) {
      do {
        *psVar11 = *(short *)((uint)auStack_2c[(int)arg2 + -1] * 2 + 0x86bef74);
        psVar11 = psVar11 + 1;
        arg2 = (short *)((uint)((int)arg2 + -1) & 0xff);
      } while (arg2 != (short *)0x0);
      arg2 = (short *)0x0;
    }
    for (; *psVar12 != 0; psVar12 = psVar12 + 1) {
      *psVar11 = *psVar12;
      psVar11 = psVar11 + 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080ebb18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar7 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec,UNRECOVERED_JUMPTABLE,arg2,unaff_r8);
  return uVar7;
}


// Battle_BuildValueRewardText @ 0x080EBB20

undefined2 * Battle_BuildValueRewardText(uint arg0,short *arg1)

{
  byte *pbVar1;
  uint uVar2;
  short *psVar3;
  ushort auStack_28 [8];
  undefined4 uStack_18;
  
  if (DAT_0203c9e7 != '\x01') {
    uStack_18 = 0;
    psVar3 = &DAT_0203caec;
    CpuSet(&uStack_18,&DAT_0203caec,0x5000020);
    for (; *arg1 != 0; arg1 = arg1 + 1) {
      *psVar3 = *arg1;
      psVar3 = psVar3 + 1;
    }
    pbVar1 = (byte *)sub_080A9CC0(arg0 & 0xffff);
    uVar2 = 0;
    do {
      auStack_28[uVar2] = (ushort)*pbVar1;
      uVar2 = uVar2 + 1 & 0xff;
      pbVar1 = pbVar1 + 1;
    } while (uVar2 < 8);
    uVar2 = 8;
    do {
      if (auStack_28[uVar2 - 1] != 0) break;
      uVar2 = uVar2 - 1 & 0xff;
    } while (uVar2 != 1);
    for (; uVar2 != 0; uVar2 = uVar2 - 1 & 0xff) {
      *psVar3 = *(short *)((uint)auStack_28[uVar2 - 1] * 2 + 0x86bef74);
      psVar3 = psVar3 + 1;
    }
    while( true ) {
      arg1 = arg1 + 1;
      if (*arg1 == 0) break;
      *psVar3 = *arg1;
      psVar3 = psVar3 + 1;
    }
  }
  return &DAT_0203caec;
}


// Battle_BuildItemDropText @ 0x080EBBF0

undefined4 Battle_BuildItemDropText(uint arg0,short *arg1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_18;
  
  arg0_00 = arg0 & 0xffff;
  if (DAT_0203c9e7 == '\x01') goto LAB_080ebc96;
  local_18 = 0;
  psVar5 = &DAT_0203caec;
  CpuSet(&local_18,&DAT_0203caec,0x5000020);
  for (; *arg1 != 0; arg1 = arg1 + 1) {
    *psVar5 = *arg1;
    psVar5 = psVar5 + 1;
  }
  psVar6 = arg1 + 1;
  if (arg0_00 < 0x80) {
    iVar2 = sub_080BF32C(arg0_00);
LAB_080ebc5c:
    psVar4 = (short *)(iVar2 + 0x14);
  }
  else {
    if (arg0_00 < 0xd0) {
      iVar2 = Equipment_GetRecord36_MidRange(arg0_00);
      goto LAB_080ebc5c;
    }
    iVar2 = Action_GetRecord(arg0_00);
    psVar4 = (short *)(iVar2 + 0xc);
  }
  bVar1 = 0;
  do {
    if (*psVar4 == 0) break;
    *psVar5 = *psVar4;
    psVar4 = psVar4 + 1;
    psVar5 = psVar5 + 1;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 8);
  for (; *psVar6 != 0; psVar6 = psVar6 + 1) {
    *psVar5 = *psVar6;
    psVar5 = psVar5 + 1;
  }
LAB_080ebc96:
                    /* WARNING: Could not recover jumptable at 0x080ebc9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return uVar3;
}


// Menu_ExpandListTemplate @ 0x080EBCA4

undefined2 * Menu_ExpandListTemplate(short *arg0,uint arg1)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  short *psVar6;
  short *arg1_00;
  short *unaff_r8;
  undefined4 local_24;
  
  if (DAT_0203c9e7 == '\x01') {
LAB_080ebe64:
    return &DAT_0203caec;
  }
  arg1_00 = &DAT_0203caec;
  if (arg0 == (short *)0x0) {
    arg0 = arg1_00;
  }
  local_24 = 0;
  CpuSet(&local_24,&DAT_0203caec,0x5000020);
switchD_080ebd14_caseD_31f:
  if (*arg0 == 0x301) goto LAB_080ebe64;
  switch(*arg0) {
  case 0x316:
  case 0x317:
    goto switchD_080ebd14_caseD_316;
  default:
    *arg1_00 = *arg0;
    arg0 = arg0 + 1;
    arg1_00 = arg1_00 + 1;
    goto switchD_080ebd14_caseD_31f;
  case 0x31a:
    uVar4 = 0;
    break;
  case 0x31b:
    uVar4 = 2;
    break;
  case 0x31c:
    uVar4 = 3;
    break;
  case 0x31d:
    uVar4 = 1;
    break;
  case 0x31e:
  case 0x325:
    uVar4 = 0x10;
    break;
  case 799:
  case 0x322:
  case 0x323:
  case 0x326:
  case 0x327:
  case 0x328:
  case 0x329:
    goto switchD_080ebd14_caseD_31f;
  case 800:
    for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1 & 0xffff) {
      iVar5 = sub_080F3EC8(uVar4);
      if ((iVar5 != 0) && (iVar5 = sub_080C0A00(uVar4), iVar5 != 0)) goto LAB_080ebdac;
    }
    uVar4 = 0;
LAB_080ebdac:
    arg1_00 = (short *)sub_080EBE7C(uVar4,arg1_00);
    iVar5 = sub_080F4968();
    uVar4 = 4;
    do {
      iVar3 = sub_080F3EC8(uVar4);
      if ((iVar3 != 0) && (iVar3 = sub_080C0A00(uVar4), iVar3 != 0)) {
        iVar5 = iVar5 + 1;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < 0x10);
    if (1 < iVar5) {
      *arg1_00 = 0xc8f;
      arg1_00 = arg1_00 + 1;
    }
    goto LAB_080ebe4c;
  case 0x321:
    uVar4 = arg1 >> 0x10;
    if (uVar4 < 0x80) {
      iVar5 = sub_080BF32C(uVar4);
      unaff_r8 = (short *)(iVar5 + 0x14);
    }
    else if (uVar4 < 0xd0) {
      iVar5 = Equipment_GetRecord36_MidRange(uVar4);
      unaff_r8 = (short *)(iVar5 + 0x14);
    }
    else if (uVar4 < 0xff) {
      iVar5 = Action_GetRecord(uVar4);
      unaff_r8 = (short *)(iVar5 + 0xc);
    }
    bVar2 = 0;
    sVar1 = *unaff_r8;
    psVar6 = unaff_r8;
    while (sVar1 != 0) {
      *arg1_00 = sVar1;
      psVar6 = psVar6 + 1;
      arg1_00 = arg1_00 + 1;
      bVar2 = bVar2 + 1;
      if (7 < bVar2) break;
      sVar1 = *psVar6;
    }
LAB_080ebe4c:
    arg0 = arg0 + 1;
    goto switchD_080ebd14_caseD_31f;
  case 0x324:
    uVar4 = arg1 & 0xffff;
  }
  arg1_00 = (short *)sub_080EBE7C(uVar4,arg1_00);
switchD_080ebd14_caseD_316:
  arg0 = arg0 + 1;
  goto switchD_080ebd14_caseD_31f;
}


// sub_080EBE7C @ 0x080EBE7C

short * sub_080EBE7C(int arg0,short *arg1)

{
  byte bVar1;
  int iVar2;
  short *psVar3;
  short local_18 [8];
  
  psVar3 = local_18;
  iVar2 = sub_080F2F64(arg0 * 0x10000 + 0x80000000U >> 0x10);
  if (*(byte *)(iVar2 + 0xc) < 4) {
    Combatant_DecodeName(iVar2,local_18);
  }
  else {
    iVar2 = sub_080BF648((uint)*(ushort *)(iVar2 + 0x12));
    psVar3 = (short *)(iVar2 + 0x22);
  }
  bVar1 = 0;
  do {
    if (*psVar3 == 0) {
      return arg1;
    }
    *arg1 = *psVar3;
    psVar3 = psVar3 + 1;
    arg1 = arg1 + 1;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 8);
  return arg1;
}


// MessageBox_ComposeWrappedText @ 0x080EBED4

undefined4 MessageBox_ComposeWrappedText(short *arg0,int arg1)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  undefined4 uVar4;
  short *psVar5;
  uint uVar6;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  short local_34 [10];
  undefined4 local_20;
  
  arg0_00 = 0;
  memset(local_34,0,0x12);
  if (DAT_0203c9e7 != '\x01') {
    local_20 = 0;
    psVar5 = &DAT_0203caec;
    CpuSet(&local_20,&DAT_0203caec,0x5000020);
    while (sVar1 = *arg0, sVar1 != 0x301) {
      if (sVar1 == 800) {
        sub_080F2F64(arg1 + 0x8000U & 0xffff);
        uVar6 = 0;
        arg0 = arg0 + 1;
        while ((uVar6 < 4 &&
               ((iVar2 = sub_080F3EC8(uVar6), iVar2 == 0 ||
                (iVar2 = sub_080C0A00(uVar6), iVar2 == 0))))) {
          uVar6 = uVar6 + 1 & 0xff;
        }
        uVar4 = sub_080F2F64(uVar6 + 0x8000);
        Combatant_DecodeName(uVar4,local_34);
        uVar6 = 0;
        psVar3 = local_34;
        while (*psVar3 != 0) {
          *psVar5 = local_34[uVar6];
          psVar5 = psVar5 + 1;
          arg0_00 = arg0_00 + 1 & 0xffff;
          uVar6 = uVar6 + 1 & 0xff;
          if (7 < uVar6) break;
          psVar3 = local_34 + uVar6;
        }
        iVar2 = sub_080F4968();
        if (1 < iVar2) {
          *psVar5 = 0xc8f;
          psVar5 = psVar5 + 1;
          arg0_00 = arg0_00 + 1 & 0xffff;
        }
      }
      else {
        psVar3 = psVar5;
        if ((1 < (ushort)(sVar1 - 0x316U)) && (sVar1 != 0x300)) {
          *psVar5 = sVar1;
          psVar3 = psVar5 + 1;
          if (*arg0 != 0x315) {
            arg0_00 = arg0_00 + 1 & 0xffff;
            uVar6 = __umodsi3(arg0_00,0x11);
            if ((uVar6 & 0xffff) == 0) {
              *psVar3 = 0x300;
              psVar3 = psVar5 + 2;
            }
          }
        }
        psVar5 = psVar3;
        arg0 = arg0 + 1;
      }
    }
    if (psVar5[-1] == 0x300) {
      psVar5[-1] = 0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080ec024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(&DAT_0203caec);
  return uVar4;
}


// sub_080EC038 @ 0x080EC038

undefined4 sub_080EC038(uint arg0)

{
  return *(undefined4 *)((arg0 & 0xffff) * 4 + 0x876fb54);
}


// sub_080EC048 @ 0x080EC048

void sub_080EC048(void)

{
  sub_080EA210();
  if (DAT_030063ac == 0) {
    sub_080EC948();
  }
  else {
    DAT_030063b0 = 9;
    sub_080ECF60(9);
  }
  DAT_0203cb78 = 2;
  if (DAT_0203d389 == '\x01') {
    DAT_0203cb78 = 3;
  }
  return;
}


// sub_080EC094 @ 0x080EC094

void sub_080EC094(void)

{
  int iVar1;
  undefined4 arg2;
  undefined4 arg3;
  undefined4 arg1;
  
  iVar1 = sub_080C2340(0x166);
  if (iVar1 == 0) {
    iVar1 = sub_080ED954();
    if (iVar1 == 1) {
      arg2 = sub_080EDA24(0);
      arg3 = sub_080EDA24(1);
      arg1 = DAT_0203cb94;
    }
    else {
      arg2 = sub_080ED9F4();
      arg3 = sub_080ED9F4();
      arg1 = DAT_0203cb90;
    }
  }
  else {
    arg2 = sub_080ED9F4();
    arg3 = sub_080ED9F4();
    arg1 = DAT_0203cb90;
  }
  MessageBox_ComposeSpeciesText(DAT_0203cb90,arg1,arg2,arg3);
  sub_080EA4F8(3);
  DAT_0203cb78 = 3;
  DAT_0203cb7a = 0;
  return;
}


// sub_080EC144 @ 0x080EC144

void sub_080EC144(int arg0)

{
  undefined4 uVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080C84A0();
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203cb7a == 1) {
    uVar2 = sub_080EA934();
    if ((uVar2 & 0xff) == 1) {
      if (DAT_030063b6 == 0xc000) {
        sub_080EC948();
        uVar1 = sub_080EC038(0x167);
        Menu_ExpandListTemplate(uVar1,0);
        sub_080EA4F8(3);
        DAT_0203cb78 = 10;
      }
      else if (DAT_030063b6 == 0x8000) {
        uVar1 = sub_080EC038(0x166);
        Menu_ExpandListTemplate(uVar1,0);
        sub_080EA4F8(3);
        DAT_0203cb78 = 5;
      }
      DAT_0203cb7a = 2;
    }
    goto LAB_080ec250;
  }
  if (DAT_0203cb7a < 2) {
    if (DAT_0203cb7a != 0) goto LAB_080ec250;
    if (DAT_0203d16a < 2) {
      uVar1 = sub_080EDE70();
      DAT_030063b6 = (ushort)uVar1;
    }
    sub_080ED920((uint)DAT_030063b6);
    if (DAT_030063b6 != 0) {
      DAT_0203cb7a = 1;
      goto LAB_080ec250;
    }
    DAT_0203cb78 = 5;
  }
  else if ((DAT_0203cb7a != 2) || (uVar2 = sub_080EA934(), (uVar2 & 0xff) != 1)) goto LAB_080ec250;
  DAT_0203cb7a = 0;
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_080ec250:
                    /* WARNING: Could not recover jumptable at 0x080ec258. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EC25C @ 0x080EC25C

void sub_080EC25C(void)

{
  BattleMenu_SetMode(3,0x86be5da);
  sub_080EC99C(1);
  DAT_0203cb78 = 7;
  return;
}


// sub_080EC288 @ 0x080EC288

void sub_080EC288(void)

{
  uint uVar1;
  
  sub_080EA9E8(0);
  BattleMenu_SetMode(3,0x86be5da);
  sub_080EC99C(1);
  DAT_0203cb78 = 7;
  uVar1 = sub_080ED8F4();
  if ((uVar1 & 0x100) == 0) {
    if ((DAT_0200e7d4 != 0) && (DAT_0200e7d4 != 2)) {
      sub_080C700C();
    }
  }
  else {
    sub_080C7054();
  }
  return;
}


// sub_080EC2E4 @ 0x080EC2E4

void sub_080EC2E4(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080EFA9C();
  DAT_0203d3a8 = 0;
  switch(uVar1) {
  case 1:
  case 8:
    DAT_0203d3a8 = 1;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 9:
  case 10:
  case 0xb:
    DAT_0203d3a8 = 2;
  }
  return;
}


// sub_080EC35C @ 0x080EC35C

void sub_080EC35C(int arg0)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  dword dVar4;
  uint uVar5;
  ushort *puVar6;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  switch(DAT_0203cb7a) {
  case 0:
    DAT_0203d3a8 = 0;
    iVar2 = sub_080C2340(1);
    if ((iVar2 == 0) && (iVar2 = sub_080C2340(0xd5), iVar2 == 0)) {
      iVar2 = sub_080C2340(3);
      if (iVar2 == 0) {
        dVar4 = 0x812490c;
        goto LAB_080ec782;
      }
      if ((DAT_0203d16a != 0) || (uVar5 = sub_080C0818(0), (uVar5 & 0xb160) != 0)) {
        uVar5 = sub_080C0818(0);
        uVar3 = 0x160;
        if ((uVar5 & 0xb160) != 0) {
          uVar3 = 0x161;
        }
        goto LAB_080ec77e;
      }
      uVar5 = sub_080ED8F4();
      if ((uVar5 & 0x80) == 0) {
        uVar3 = Menu_ExpandListTemplate(0x812634e,0);
        BattleMenu_SetMode(3,uVar3);
        DAT_0203cb7a = 1;
        sub_080E5A18(8);
        DAT_0203d3a8 = 1;
        return;
      }
      iVar2 = sub_080EF99C();
      uVar3 = MessageBox_ComposeNameText
                        (*(undefined4 *)((int)&DAT_0203cb90 + ((iVar2 << 0x10) >> 0xe)),0x812466c);
LAB_080ec788:
      BattleMenu_SetMode(3,uVar3);
    }
    else {
      uVar3 = Menu_ExpandListTemplate(0x81265be,0);
      BattleMenu_SetMode(3,uVar3);
    }
    DAT_0203cb78 = 6;
    DAT_0203cb7a = 9;
    break;
  case 1:
    DAT_0203cb7a = 3;
    *(undefined2 *)(DAT_03006434 + 0x122) = 0;
    iVar2 = sub_080ED954();
    if (iVar2 == 1) {
      iVar2 = sub_080EDA24(0);
      if ((iVar2 != 0) && (iVar2 = sub_080EDA24(1), iVar2 != 0)) {
        DAT_0203cb7a = 2;
        DAT_0203cb7e = 0;
        return;
      }
      iVar2 = sub_080EDA24(0);
      if (iVar2 == 0) {
        *(undefined2 *)(DAT_03006434 + 0x122) = 1;
        puVar6 = (ushort *)&DAT_0203cb94;
      }
      else {
        *(undefined2 *)(DAT_03006434 + 0x122) = 0;
        puVar6 = (ushort *)&DAT_0203cb90;
      }
    }
    else {
      puVar6 = (ushort *)&DAT_0203cb90;
    }
    sub_0813EB84((uint)*puVar6,0xffff);
    break;
  case 2:
    uVar5 = sub_080E6FA0();
    if ((uVar5 & 0xffff) == 3) {
      puVar6 = (ushort *)(DAT_03006434 + 0x122);
      *puVar6 = (ushort)DAT_0203c895;
      DAT_0203cb7a = (undefined2)uVar5;
      if (*puVar6 == 0) {
        dVar4 = 0x994;
        uVar1 = (ushort)DAT_0203cb90;
      }
      else {
        dVar4 = 0x990;
        uVar1 = (ushort)DAT_0203cb94;
      }
      sub_0813EB84((uint)uVar1,(uint)*(ushort *)(dVar4 + 0x203c200));
      return;
    }
    if ((uVar5 & 0xffff) != 2) {
      return;
    }
    sub_080EA528();
    DAT_0203d3a8 = 0;
    goto LAB_080ec7c0;
  case 3:
    sub_080EA528();
    sub_080AB98C(DAT_0203cb74,8);
    DAT_0203d38e = 0xffff;
    sub_0813E914();
    sub_080C7430();
    sub_080C7648();
    DAT_0203d3b2 = 10;
    DAT_0203cb7a = 4;
  case 4:
    DAT_0203d3b2 = DAT_0203d3b2 + -1;
    if (DAT_0203d3b2 == 0) {
      DAT_0203cb7a = 5;
    }
    break;
  case 5:
    dVar4 = sub_0813EB60();
    if (dVar4 != 0xffff) {
      sub_080EEF98();
      sub_080C7414();
      sub_080C762C();
      DAT_0203cb7a = 6;
    }
    break;
  case 6:
    uVar5 = sub_080ED8F4();
    if ((uVar5 & 0x80) != 0) {
      sub_080EC948();
    }
    iVar2 = sub_080EFA9C();
    sub_080EC2E4();
    if ((((iVar2 == 6) || (iVar2 == 8)) || (iVar2 == 0xc)) || (iVar2 == 5)) {
      DAT_0203d0c0 = 1;
    }
    if (iVar2 == 4) {
      uVar3 = 0x2000;
    }
    else {
      if (((2 < iVar2 - 9U) && (1 < iVar2 - 6U)) && (iVar2 != 0xc)) {
        sub_080AB98C(DAT_0203cb74,2);
        DAT_0203cb7a = 7;
        return;
      }
      uVar3 = 0x200;
    }
    sub_080ED90C(uVar3);
    DAT_0203cb7a = 0;
    DAT_0203cb78 = 0xe;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if (DAT_0203cb74 != 0) {
      sub_080AB91C(DAT_0203cb74,0);
      DAT_0203cb74 = 0;
    }
    break;
  case 7:
    iVar2 = sub_080EFA9C();
    if (iVar2 == 3) {
      uVar3 = 0x166;
LAB_080ec77e:
      dVar4 = sub_080EC038(uVar3);
LAB_080ec782:
      uVar3 = Menu_ExpandListTemplate(dVar4,0);
      goto LAB_080ec788;
    }
    if ((iVar2 < 4) && (iVar2 == 2)) {
      sub_080EC948();
      uVar3 = sub_080EC038(0x167);
      uVar3 = Menu_ExpandListTemplate(uVar3,0);
      BattleMenu_SetMode(3,uVar3);
      DAT_0203cb7a = 9;
      DAT_0203cb78 = 10;
      if (DAT_0203d16a == 0) {
        sub_080C6FF0();
        return;
      }
      sub_080C7038();
      return;
    }
LAB_080ec7c0:
    DAT_0203cb78 = 6;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    break;
  case 8:
    uVar5 = sub_080EA934();
    if ((uVar5 & 0xff) == 1) {
      sub_080E5A3C();
    }
    break;
  case 9:
    uVar5 = sub_080EA934();
    if ((uVar5 & 0xff) == 1) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      DAT_0203cb7a = 0;
    }
  }
  return;
}


// sub_080EC800 @ 0x080EC800

void sub_080EC800(int arg0)

{
  dword dVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203cb7a != 0) {
    if ((DAT_0203cb7a == 1) && (uVar3 = sub_080EA934(), (uVar3 & 0xff) == 1)) {
      if (*(int *)(arg0 + 0x24) == 0x144) {
        sub_080ED90C(0x2000);
        if (DAT_030063ac == 2) {
          DAT_030063b4 = 1;
        }
        DAT_0203cb7a = 0;
        DAT_0203cb78 = 0xe;
        *(undefined2 *)(arg0 + 0x1c) = 1;
      }
      else {
        sub_080EC948();
        sub_080ED920(0xc000);
        DAT_0203cb7a = 0;
        DAT_0203cb78 = 10;
        DAT_0203d322 = DAT_0203d322 + '\x01';
        *(undefined2 *)(arg0 + 0x1c) = 1;
        if (DAT_0203d16a == 0) {
          sub_080C6FF0();
        }
        else {
          sub_080C7038();
        }
      }
    }
    goto LAB_080ec918;
  }
  dVar1 = sub_080EDF0C();
  *(dword *)(arg0 + 0x24) = dVar1;
  if (dVar1 == 0x145) {
    dVar1 = 0x81262be;
LAB_080ec862:
    uVar2 = MessageBox_ComposeWrappedText(dVar1,0);
    BattleMenu_SetMode(3,uVar2);
  }
  else if ((int)dVar1 < 0x146) {
    if (dVar1 == 0x144) {
      dVar1 = 0x8126254;
      goto LAB_080ec862;
    }
  }
  else if (dVar1 == 0x146) {
    uVar2 = sub_080EC038(0x146);
    uVar2 = Menu_ExpandListTemplate(uVar2,0);
    BattleMenu_SetMode(3,uVar2);
  }
  DAT_0203cb7a = 1;
LAB_080ec918:
                    /* WARNING: Could not recover jumptable at 0x080ec920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EC92C @ 0x080EC92C

void sub_080EC92C(int arg0)

{
  uint uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar1 = sub_080EA934();
  if ((uVar1 & 0xff) == 1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080EC948 @ 0x080EC948

void sub_080EC948(void)

{
  uint uVar1;
  
  if (DAT_0203d168 == 0) {
    DAT_0203d168 = 1;
    uVar1 = sub_080EFEDC();
    DAT_030063b0 = (undefined2)uVar1;
    sub_080ECF60(uVar1 & 0xffff);
  }
  return;
}


// sub_080EC97C @ 0x080EC97C

void sub_080EC97C(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080F3144();
  if (iVar1 == 1) {
    sub_080B9058();
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080ec99a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EC99C @ 0x080EC99C

void sub_080EC99C(undefined4 arg0)

{
  DAT_0203c9e4 = (undefined1)arg0;
  return;
}


// sub_080EC9AC @ 0x080EC9AC

void sub_080EC9AC(undefined4 arg0,uint arg1,undefined4 arg2)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = arg1 & 0xff;
  DAT_0203d374 = sub_080AD0FC(0x86bf734,0xffff);
  DAT_0203d360 = 1;
  DAT_0203d361 = 0;
  DAT_0203d364 = 0;
  DAT_0203d365 = 0;
  if ((byte)arg0 < 200) {
    DAT_0203d36e = 0x30;
  }
  else {
    DAT_0203d36e = 0x38;
  }
  DAT_0203d36c = *(short *)(uVar2 * 2 + 0x86bf72c);
  sVar1 = DAT_0203d38c;
  if (uVar2 != 1) {
    if (uVar2 != 2) goto LAB_080eca2e;
    sVar1 = -DAT_0203d38c;
  }
  DAT_0203d36c = DAT_0203d36c + sVar1;
LAB_080eca2e:
  DAT_0203d370 = *(undefined4 *)(*(int *)((uint)(byte)arg0 * 0x18 + 0x876ce10) + 4);
  DAT_0203d362 = (byte)arg0;
  DAT_0203d366 = (undefined2)arg2;
  if ((byte)arg0 < 200) {
    sub_080C140C(8,0x10);
  }
  return;
}


// sub_080ECA60 @ 0x080ECA60

void sub_080ECA60(undefined4 arg0,uint arg1,undefined4 arg2)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = arg1 & 0xff;
  DAT_0203d374 = sub_080AD0FC(0x86bf734,0xffff);
  DAT_0203d360 = 1;
  DAT_0203d364 = 0;
  DAT_0203d365 = 0;
  if ((byte)arg0 < 200) {
    DAT_0203d36e = 0x32;
  }
  else {
    DAT_0203d36e = 0x3a;
  }
  DAT_0203d36c = *(short *)(uVar2 * 2 + 0x86bf72c);
  sVar1 = DAT_0203d38c;
  if (uVar2 != 1) {
    if (uVar2 != 2) goto LAB_080ecade;
    sVar1 = -DAT_0203d38c;
  }
  DAT_0203d36c = DAT_0203d36c + sVar1;
LAB_080ecade:
  DAT_0203d370 = *(undefined4 *)(*(int *)((uint)(byte)arg0 * 0x18 + 0x876ce10) + 4);
  DAT_0203d362 = (byte)arg0;
  DAT_0203d366 = (undefined2)arg2;
  if ((byte)arg0 < 200) {
    sub_080C140C(8,0x10);
  }
  return;
}


// sub_080ECB10 @ 0x080ECB10

uint sub_080ECB10(void)

{
  bool bVar1;
  
  bVar1 = DAT_0203d360 == '\x03';
  if (bVar1) {
    DAT_0203d360 = '\0';
    sub_080C1440();
  }
  return (uint)bVar1;
}


// sub_080ECB38 @ 0x080ECB38

void sub_080ECB38(void)

{
  sub_080AD1FC(DAT_0203d374);
  DAT_0203d360 = 0;
  sub_080C1440();
  return;
}


// sub_080ECB5C @ 0x080ECB5C

void sub_080ECB5C(undefined4 arg0)

{
  DAT_0203d360 = (undefined1)arg0;
  return;
}


// sub_080ECB6C @ 0x080ECB6C

void sub_080ECB6C(uint arg0,uint arg1)

{
  HuffUnComp(*(undefined4 *)(&UNK_0876ce18 + (arg1 & 0xff) * 4 + (arg0 & 0xffff) * 0x18),0x200afc8,
             &UNK_0876ce18 + (arg1 & 0xff) * 4 + (arg0 & 0xffff) * 0x18);
  return;
}


// sub_080ECB98 @ 0x080ECB98

void sub_080ECB98(uint arg0,uint arg1)

{
  LZ77UnCompWram(0x200afc8,(arg1 & 0xff) * 0x800 + 0x30000b4,0x30000b4);
  if ((arg1 & 0xff) == 0) {
    sub_080ACFCC(3,*(undefined4 *)(&DAT_0876ce14 + (arg0 & 0xffff) * 0x18),0x3003130,0x40);
    sub_080AABB0();
  }
  return;
}


// sub_080ECBF0 @ 0x080ECBF0

void sub_080ECBF0(undefined4 arg0,uint arg1)

{
  if (DAT_0203d362 < 0xd3) {
    sub_080ECB98((uint)DAT_0203d362,arg1 & 0xff);
  }
  return;
}


// sub_080ECC10 @ 0x080ECC10

void sub_080ECC10(undefined4 arg0,uint arg1)

{
  if (DAT_0203d362 < 0xd3) {
    sub_080ECB6C((uint)DAT_0203d362,arg1 & 0xff);
  }
  return;
}


// sub_080ECC30 @ 0x080ECC30

void sub_080ECC30(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6014000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080ECC54 @ 0x080ECC54

void sub_080ECC54(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x30010b4;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080ECC78 @ 0x080ECC78

void sub_080ECC78(undefined4 arg0,int arg1)

{
  if (DAT_0203d362 < 0xd3) {
    if (arg1 == 0) {
      DisplayList_Add(0x80ecc31,1);
    }
    else {
      DisplayList_Add(0x80ecc55,1);
    }
  }
  return;
}


// sub_080ECCB0 @ 0x080ECCB0

undefined4 sub_080ECCB0(int arg0)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  int *piVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar5 = *(int *)(arg0 + 0x10);
  piVar6 = (int *)(iVar5 + (uint)*(byte *)(arg0 + 4) * 8);
  if ((uint)*(byte *)(arg0 + 5) == (uint)*(ushort *)(piVar6 + 1) + (uint)*(byte *)(arg0 + 1)) {
    *(byte *)(arg0 + 4) = *(byte *)(arg0 + 4) + 1;
    *(undefined1 *)(arg0 + 5) = 0;
    piVar6 = (int *)(iVar5 + (uint)*(byte *)(arg0 + 4) * 8);
    if (*piVar6 == -1) {
      if (*(char *)(arg0 + 2) != -0x2e) {
        uVar2 = 0;
        goto LAB_080ecd92;
      }
      *(byte *)(arg0 + 4) = *(byte *)(arg0 + 4) - 1;
      *(undefined1 *)(arg0 + 5) = 1;
      piVar6 = (int *)(iVar5 + (uint)*(byte *)(arg0 + 4) * 8);
    }
    if ((short)piVar6[1] == 0x100) {
      *(char *)(arg0 + 4) = *(char *)(arg0 + 4) - *(char *)((int)piVar6 + 6);
      piVar6 = (int *)(*(int *)(arg0 + 0x10) + (uint)*(byte *)(arg0 + 4) * 8);
    }
  }
  if (*(char *)(arg0 + 2) == -0x2e) {
    uVar3 = *(byte *)(arg0 + 8) + 1 & 0x1f;
    *(char *)(arg0 + 8) = (char)uVar3;
    uVar3 = uVar3 >> 1;
    puVar4 = (undefined2 *)0x3003132;
    bVar1 = 0;
    do {
      if (uVar3 == 0) {
        uVar3 = 1;
      }
      uVar2 = sub_080ACC54((uint)*(ushort *)(&UNK_0872f83c + uVar3 * 2));
      *puVar4 = (short)uVar2;
      puVar4 = puVar4 + 1;
      uVar3 = ((uVar3 + 1) * 0x1000000 & 0xf000000) >> 0x18;
      bVar1 = bVar1 + 1;
    } while (bVar1 < 0xf);
    sub_080AABB0();
  }
  sub_080AA2DC(*piVar6,0,0xc,2);
  *(char *)(arg0 + 5) = *(char *)(arg0 + 5) + '\x01';
  uVar2 = 1;
LAB_080ecd92:
                    /* WARNING: Could not recover jumptable at 0x080ecd9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080ECDA8 @ 0x080ECDA8

void sub_080ECDA8(int arg0)

{
  uint uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203d362 < 0xd3) {
    DAT_0203d360 = 2;
    uVar1 = sub_080ECCB0(&DAT_0203d360);
    if ((uVar1 & 0xff) != 0) {
      return;
    }
  }
  *(undefined2 *)(arg0 + 0x1c) = 1;
  return;
}


// sub_080ECDDC @ 0x080ECDDC

void sub_080ECDDC(void)

{
  DAT_0203d360 = 3;
  return;
}


// sub_080ECDF0 @ 0x080ECDF0

void sub_080ECDF0(void)

{
  sub_08126D34((uint)DAT_0203d366);
  return;
}


// sub_080ECE08 @ 0x080ECE08

void sub_080ECE08(undefined4 arg0)

{
  DAT_0203d374 = sub_080AD0FC(0x86bf840,0xffff);
  DAT_0203d360 = (undefined1)arg0;
  return;
}


// sub_080ECE38 @ 0x080ECE38

void sub_080ECE38(undefined4 arg0,uint arg1,undefined4 arg2)

{
  uint arg0_00;
  uint arg1_00;
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  arg1_00 = arg1 & 0xff;
  if (DAT_0203d360 == '\x04') {
    DAT_0203d363 = (undefined1)(ushort)arg0;
  }
  if ((byte)arg2 == 1) {
    arg0_00 = (uint)(ushort)arg0;
    iVar1 = arg0_00 << 0x10;
    sub_080C88A8(arg0_00,arg1_00);
  }
  else if ((byte)arg2 < 2) {
    if ((byte)arg2 != 0) goto LAB_080ecea6;
    arg0_00 = (uint)(ushort)arg0;
    iVar1 = arg0_00 << 0x10;
    sub_080C88C0(arg0_00,arg1_00);
  }
  else if ((byte)arg2 == 3) {
    arg0_00 = (uint)(ushort)arg0;
    iVar1 = arg0_00 << 0x10;
    sub_080C8890(arg0_00,arg1_00);
  }
  else {
    if ((byte)arg2 != 5) goto LAB_080ecea6;
    iVar1 = (uint)(ushort)arg0 << 0x10;
    arg0_00 = sub_080C88D8((uint)(ushort)arg0,arg1_00);
  }
  *(uint *)((int)&DAT_0203c210 + (iVar1 >> 0xe)) = arg0_00;
LAB_080ecea6:
                    /* WARNING: Could not recover jumptable at 0x080eceaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080ECEAC @ 0x080ECEAC

void sub_080ECEAC(int arg0)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  if (DAT_0203d360 == '\x04') {
    iVar2 = sub_080C88F0((&DAT_0203c210)[DAT_0203d363]);
    if (iVar2 != 1) {
      return;
    }
  }
  else if (DAT_0203d360 == '\x05') {
    cVar1 = '\0';
    uVar3 = 0;
    do {
      iVar2 = sub_080C88F0((&DAT_0203c210)[uVar3]);
      if (iVar2 == 1) {
        cVar1 = cVar1 + '\x01';
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 6);
    if (cVar1 != '\x06') {
      return;
    }
  }
  *(undefined2 *)(arg0 + 0x1c) = 1;
  return;
}


// sub_080ECF10 @ 0x080ECF10

void sub_080ECF10(void)

{
  uint uVar1;
  
  if (DAT_0203d360 == '\x04') {
    (&DAT_0203c210)[DAT_0203d363] = 0;
  }
  else if (DAT_0203d360 == '\x05') {
    uVar1 = 0;
    do {
      (&DAT_0203c210)[uVar1] = 0;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 6);
  }
  DAT_0203d360 = 3;
  DAT_0203d363 = 0;
  return;
}


// sub_080ECF60 @ 0x080ECF60

void sub_080ECF60(uint arg0)

{
  sub_080C5170(arg0 & 0xffff);
  return;
}


// sub_080ECF70 @ 0x080ECF70

void sub_080ECF70(uint arg0)

{
  sub_08126D34(arg0 & 0xffff);
  return;
}


// sub_080ECF80 @ 0x080ECF80

void sub_080ECF80(void)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x86bf86c,0xffff);
  DAT_0203c22c = iVar1;
  *(undefined1 *)(iVar1 + 0x24) = 0;
  *(undefined1 *)(iVar1 + 0x25) = 0;
  *(undefined1 *)(iVar1 + 0x26) = 0x10;
  *(undefined1 *)(iVar1 + 0x28) = 0x10;
  *(undefined1 *)(iVar1 + 0x27) = 0;
  return;
}


// sub_080ECFB0 @ 0x080ECFB0

void sub_080ECFB0(int arg0)

{
  undefined1 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (*(char *)(arg0 + 0x27) == '\x01') {
    *(undefined1 *)(arg0 + 0x27) = 0;
    iVar2 = *(byte *)(arg0 + 0x28) - 1;
    uVar1 = (undefined1)iVar2;
    *(undefined1 *)(arg0 + 0x28) = uVar1;
    if (iVar2 * 0x1000000 < 1) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(byte *)(arg0 + 0x24) = 0;
      *(undefined1 *)(arg0 + 0x25) = 0;
      *(undefined1 *)(arg0 + 0x26) = 0;
      *(undefined1 *)(arg0 + 0x28) = 0;
    }
    else {
      *(undefined1 *)(arg0 + 0x26) = uVar1;
    }
  }
  else {
    *(char *)(arg0 + 0x27) = *(char *)(arg0 + 0x27) + '\x01';
  }
  sub_080E845C((uint)*(byte *)(arg0 + 0x24),(int)*(char *)(arg0 + 0x25),(int)*(char *)(arg0 + 0x26))
  ;
                    /* WARNING: Could not recover jumptable at 0x080ecffc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


