/* Ghidra decompilation of asm/code_080F2AC8.s (reference only; not compiled). */

// sub_080F2AC8 @ 0x080F2AC8

void sub_080F2AC8(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 arg0;
  short unaff_r5;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = (short)DAT_0300008c;
  iVar2 = sub_080F3110(DAT_0300008c);
  uVar3 = sub_080EDA90();
  uVar3 = uVar3 & 0xffff;
  if (uVar3 == 0x80) {
    iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x20;
  }
  else if (uVar3 < 0x81) {
    if (uVar3 == 8) {
      iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x30;
    }
    else if (uVar3 < 9) {
      if (uVar3 == 2) {
        iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x38;
      }
      else if (uVar3 < 3) {
        if (uVar3 != 1) goto LAB_080f2c78;
        iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x3c;
      }
      else {
        if (uVar3 != 4) goto LAB_080f2c78;
        iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x34;
      }
    }
    else if (uVar3 == 0x20) {
      iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x28;
    }
    else if (uVar3 < 0x21) {
      if (uVar3 != 0x10) goto LAB_080f2c78;
      iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x2c;
    }
    else {
      if (uVar3 != 0x40) goto LAB_080f2c78;
      iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x24;
    }
  }
  else if (uVar3 == 0x800) {
    iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x10;
  }
  else if (uVar3 < 0x801) {
    if (uVar3 == 0x200) {
      iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x18;
    }
    else if (uVar3 < 0x201) {
      if (uVar3 != 0x100) goto LAB_080f2c78;
      iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x1c;
    }
    else {
      if (uVar3 != 0x400) goto LAB_080f2c78;
      iVar2 = ((iVar2 << 0x10) >> 0xf) + 0x14;
    }
  }
  else if (uVar3 == 0x2000) {
    iVar2 = ((iVar2 << 0x10) >> 0xf) + 8;
  }
  else if (uVar3 < 0x2001) {
    if (uVar3 != 0x1000) goto LAB_080f2c78;
    iVar2 = ((iVar2 << 0x10) >> 0xf) + 0xc;
  }
  else if (uVar3 == 0x4000) {
    iVar2 = ((iVar2 << 0x10) >> 0xf) + 4;
  }
  else {
    if (uVar3 != 0x8000) goto LAB_080f2c78;
    iVar2 = (iVar2 << 0x10) >> 0xf;
  }
  unaff_r5 = *(short *)(iVar2 + 0x876e938);
LAB_080f2c78:
  arg0 = sub_080EC038((int)unaff_r5);
  Menu_ExpandListTemplate(arg0,(int)sVar1);
  sub_080EA4F8(3);
                    /* WARNING: Could not recover jumptable at 0x080f2c94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F2C9C @ 0x080F2C9C

void sub_080F2C9C(undefined4 arg0)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  short local_28 [8];
  
  uVar6 = 0;
  if ((short)arg0 < 0x10) {
    uVar4 = 0x10;
    do {
      iVar1 = sub_080C09B0((int)(uVar4 * 0x10000) >> 0x10);
      if ((iVar1 != 0) && (iVar1 = sub_080C0830(), iVar1 == 0)) {
        local_28[(short)uVar6] = (short)uVar4;
        uVar6 = (int)(short)uVar6 + 1U & 0xffff;
      }
      sVar5 = (short)uVar6;
      uVar2 = uVar4 * 0x10000 + 0x10000;
      uVar4 = uVar2 >> 0x10;
    } while ((int)uVar2 >> 0x10 < 0x18);
  }
  else {
    uVar4 = 0;
    do {
      uVar3 = sub_080F40EC((int)(uVar4 * 0x10000) >> 0x10);
      if (((short)uVar3 != -1) && (iVar1 = sub_080C0830(), iVar1 == 0)) {
        local_28[(short)uVar6] = (short)uVar3;
        uVar6 = (int)(short)uVar6 + 1U & 0xffff;
      }
      sVar5 = (short)uVar6;
      uVar2 = uVar4 * 0x10000 + 0x10000;
      uVar4 = uVar2 >> 0x10;
    } while ((int)uVar2 >> 0x10 < 6);
  }
  uVar3 = sub_080C2244();
  __umodsi3(uVar3,(int)sVar5);
  return;
}


// sub_080F2D4C @ 0x080F2D4C

void sub_080F2D4C(void)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  short sVar10;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar11;
  
  uVar7 = 0;
  do {
    iVar3 = uVar7 * 0x10000;
    iVar8 = iVar3 >> 0x10;
    iVar9 = iVar8 * 0x80;
    if (((&DAT_0203cbae)[iVar8 * 0x40] != 0) &&
       (((&DAT_0203cbb0)[iVar8 * 0x40] & (ushort)0xb1e0) == 0)) {
      uVar2 = *(ushort *)(&DAT_0203cbb2 + iVar9);
      uVar7 = sub_080F30F8();
      if ((uVar7 & 0xffff) != 0) {
        bVar11 = true;
        uVar7 = sub_080C2244();
        sVar10 = (short)(uVar7 & 7);
        if (6 < (uVar7 & 7)) {
          sVar10 = 0;
        }
        iVar4 = sub_080BF648((uint)uVar2);
        bVar1 = *(byte *)(iVar4 + 0x11 + (int)sVar10);
        uVar7 = (uint)bVar1;
        iVar4 = sub_080ED694(uVar7);
        pbVar5 = (byte *)sub_080BF5C0(uVar7);
        if ((((((*pbVar5 & 0x20) != 0) && (uVar7 != 0x3e)) && (uVar7 != 0x3f)) &&
            ((uVar7 != 0x36 && (uVar7 != 0x37)))) &&
           ((uVar7 != 0x3c &&
            ((uVar7 < 0xa0 && (iVar6 = sub_080ED744(iVar8 + 0x10,uVar7), iVar6 != 0)))))) {
          if (uVar7 < 0x40) {
            bVar11 = ((&DAT_0203cbb0)[iVar8 * 0x40] & 2) == 0;
            (&DAT_0203cbb7)[iVar9] = 7;
          }
          else {
            (&DAT_0203cbb7)[iVar9] = 0xb;
          }
          if ((iVar4 == 0x80) || (iVar4 == 0x82)) {
            iVar8 = sub_080F2EAC();
            if (iVar8 == -1) goto LAB_080f2e5a;
            *(short *)(&DAT_0203d150 + (iVar3 >> 0xf)) = (short)iVar8;
          }
          (&DAT_0203cbfc)[iVar9] = bVar1;
          if (bVar11) {
            if (uVar7 == 0x9f) {
              if (DAT_0203c174 != 0) {
                (&DAT_0203cbb7)[iVar9] = 10;
              }
              DAT_0203c174 = DAT_0203c174 + 1;
              if (2 < DAT_0203c174) {
                DAT_0203c174 = 0;
              }
            }
            goto LAB_080f2e88;
          }
        }
      }
LAB_080f2e5a:
      (&DAT_0203cbb7)[iVar9] = 10;
    }
LAB_080f2e88:
    uVar7 = iVar3 + 0x10000U >> 0x10;
    if (7 < (int)(iVar3 + 0x10000U) >> 0x10) {
                    /* WARNING: Could not recover jumptable at 0x080f2ea4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  } while( true );
}


// sub_080F2EAC @ 0x080F2EAC

undefined4 sub_080F2EAC(void)

{
  undefined4 in_r0;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080ED694(in_r0);
  if (iVar1 == 0x80) {
    iVar1 = 0;
  }
  else if (iVar1 == 0x82) {
    iVar1 = 1;
  }
  iVar3 = 0;
  while( true ) {
    if (((&DAT_0203cbae)[iVar3 * 0x40] != 0) && (((&DAT_0203cbb0)[iVar3 * 0x40] & 0x8000) == 0))
    break;
LAB_080f2f04:
    iVar3 = iVar3 + 1;
    if (7 < iVar3) {
      iVar3 = -1;
LAB_080f2f0e:
                    /* WARNING: Could not recover jumptable at 0x080f2f12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(iVar3);
      return uVar2;
    }
  }
  if (iVar1 == 0) {
    if (*(short *)(&DAT_0203cbba + iVar3 * 0x80) <= (short)(&DAT_0203cbb8)[iVar3 * 0x40])
    goto LAB_080f2f04;
  }
  else if ((&DAT_0203cbb0)[iVar3 * 0x40] == 0) goto LAB_080f2f04;
  iVar3 = iVar3 + 0x10;
  goto LAB_080f2f0e;
}


// sub_080F2F14 @ 0x080F2F14

int sub_080F2F14(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  uint uVar6;
  dword dVar5;
  
  dVar5 = 0xffff;
  sVar4 = -1;
  uVar6 = 0;
  sVar1 = *(short *)(DAT_03006434 + 0xc);
  while (sVar1 != -1) {
    uVar2 = dVar5 * 0x10000 + 0x10000;
    dVar5 = uVar2 >> 0x10;
    sVar4 = (short)(uVar2 >> 0x10);
    uVar2 = uVar6 * 0x10000 + 0x10000;
    uVar6 = uVar2 >> 0x10;
    iVar3 = (int)uVar2 >> 0x10;
    if (0xc < iVar3) break;
    sVar1 = *(short *)(DAT_03006434 + iVar3 * 4 + 0xc);
  }
  return (int)sVar4;
}


// sub_080F2F64 @ 0x080F2F64

int sub_080F2F64(uint arg0)

{
  int iVar1;
  
  if ((arg0 & 0x7fff) < 0x10) {
    iVar1 = sub_080C0148(arg0 & 0xffff);
  }
  else {
    iVar1 = (arg0 & 0x7fff) * 0x80 + 0x203c3a0;
  }
  return iVar1;
}


// sub_080F2F94 @ 0x080F2F94

void sub_080F2F94(short *arg0,short *arg1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  sVar1 = *arg1 + 1;
  *arg1 = sVar1;
  while( true ) {
    if (5 < sVar1) {
      return;
    }
    uVar2 = sub_080F30CC((int)*arg1);
    *arg0 = (short)uVar2;
    if ((((short)uVar2 != -1) && (iVar3 = sub_080F3EC8((int)*arg0), iVar3 != 0)) &&
       (uVar4 = sub_080F3040(), (uVar4 & 0xffff) != 0)) break;
    sVar1 = *arg1 + 1;
    *arg1 = sVar1;
  }
  return;
}


// sub_080F2FEC @ 0x080F2FEC

void sub_080F2FEC(short *arg0,ushort *arg1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = *arg1 - 1;
  *arg1 = (ushort)iVar1;
  while( true ) {
    if (iVar1 * 0x10000 < 0) {
      return;
    }
    uVar2 = sub_080F30CC((int)(short)*arg1);
    *arg0 = (short)uVar2;
    if ((((short)uVar2 != -1) && (iVar1 = sub_080F3EC8((int)*arg0), iVar1 != 0)) &&
       (uVar3 = sub_080F3040(), (uVar3 & 0xffff) != 0)) break;
    iVar1 = *arg1 - 1;
    *arg1 = (ushort)iVar1;
  }
  return;
}


// sub_080F3040 @ 0x080F3040

uint sub_080F3040(void)

{
  undefined4 in_r0;
  uint uVar1;
  
  uVar1 = sub_080C0818(in_r0);
  return (uint)((uVar1 & 0xb3f0) == 0);
}


// sub_080F3060 @ 0x080F3060

undefined4 sub_080F3060(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar5 = 0;
  uVar6 = 0;
  uVar4 = 0;
  do {
    iVar1 = sub_080C0A00((short)uVar4 + 0x10);
    if (iVar1 != 0) {
      uVar5 = uVar5 * 0x10000 + 0x10000 >> 0x10;
    }
    uVar2 = (int)(short)uVar4 + 1;
    uVar4 = uVar2 & 0xffff;
  } while ((int)(uVar2 * 0x10000) >> 0x10 < 4);
  uVar4 = 0;
  do {
    iVar1 = sub_080C0A00((short)uVar4 + 0x14);
    if (iVar1 != 0) {
      uVar6 = uVar6 * 0x10000 + 0x10000 >> 0x10;
    }
    uVar2 = (int)(short)uVar4 + 1;
    uVar4 = uVar2 & 0xffff;
  } while ((int)(uVar2 * 0x10000) >> 0x10 < 4);
  if ((uVar5 == 0) || (uVar6 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080f30ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar3);
  return uVar3;
}


// sub_080F30CC @ 0x080F30CC

int sub_080F30CC(int arg0)

{
  return (int)(char)(&DAT_030050e0)[arg0];
}


// sub_080F30E4 @ 0x080F30E4

int sub_080F30E4(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  return (int)*(char *)(iVar1 + 0x10);
}


// sub_080F30F8 @ 0x080F30F8

undefined4 sub_080F30F8(void)

{
  undefined4 in_r0;
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = sub_080F30E4(in_r0);
  uVar2 = 1;
  sub_080ED3FC(1,(int)(short)uVar1);
  return uVar2;
}


// sub_080F3110 @ 0x080F3110

uint sub_080F3110(int arg0)

{
  return (uint)(0xf < arg0);
}


// sub_080F3120 @ 0x080F3120

void sub_080F3120(void)

{
  uint arg0;
  int iVar1;
  uint uVar2;
  
  arg0 = 0;
  do {
    iVar1 = sub_080C0148(arg0);
    *(undefined1 *)(iVar1 + 0x16) = *(undefined1 *)(iVar1 + 0x17);
    uVar2 = arg0 * 0x10000 + 0x10000;
    arg0 = uVar2 >> 0x10;
  } while ((int)uVar2 >> 0x10 < 6);
  return;
}


// sub_080F3144 @ 0x080F3144

undefined4 sub_080F3144(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while (((iVar1 = sub_080C0148(iVar2 - 0x8000U & 0xffff), iVar1 == 0 ||
          ((*(ushort *)(iVar1 + 0xe) & 0xc000) == 0)) || ((*(ushort *)(iVar1 + 0x10) & 0xa000) != 0)
         )) {
    iVar2 = iVar2 + 1;
    if (3 < iVar2) {
      return 1;
    }
  }
  return 0;
}


// sub_080F3190 @ 0x080F3190

undefined4 sub_080F3190(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = sub_080C0148(0x8000);
  if ((DAT_03005180 == 1) || (uVar2 = sub_080C5D0C(), (uVar2 & 0x80) == 0)) {
    if ((*(ushort *)(iVar1 + 0x10) & (ushort)0xb1e0) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0x53;
    }
  }
  else {
    uVar3 = 0x55;
  }
  return uVar3;
}


// sub_080F31E0 @ 0x080F31E0

undefined4 sub_080F31E0(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((DAT_03005180 == 1) || (uVar1 = sub_080C5D0C(), (uVar1 & 0x8000) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// sub_080F3214 @ 0x080F3214

uint sub_080F3214(int arg0,uint arg1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  uVar1 = *(undefined2 *)(iVar2 + 0x10);
  iVar3 = sub_080C08F8(arg0,arg1 & 0xffff);
  *(undefined2 *)(iVar2 + 0x10) = uVar1;
  return (uint)(iVar3 == 0);
}


// Skill_DrawEquippedRow @ 0x080F3254

void Skill_DrawEquippedRow(undefined4 arg0,uint arg1)

{
  uint uVar1;
  ushort local_24 [8];
  undefined4 local_14;
  
  Combatant_DecodeName(arg0,local_24);
  if ((arg1 & 0xff) == 4) {
    CpuFastSet(0x3001cb4,&DAT_030002b4,0x80);
    uVar1 = 0;
    do {
      if (local_24[uVar1] != 0) {
        Font_DrawGlyph((uint)local_24[uVar1],0x30000b4,uVar1 * 0xc0000 + 0x800000 >> 0x10,4);
      }
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 8);
    CpuFastSet(0x30002b4,&DAT_03001cb4,0x80);
    CpuFastSet(&DAT_030006b4,0x30002b4,0x80);
    CpuFastSet(&DAT_03000ab4,&DAT_030006b4,0x80);
    local_14 = 0;
    CpuFastSet(&local_14,&DAT_03000ab4,0x1000080);
  }
  else {
    uVar1 = 0;
    do {
      if (local_24[uVar1] != 0) {
        Font_DrawGlyph((uint)local_24[uVar1],0x30000b4,uVar1 * 0xc,(arg1 & 0xff) * 0xd + 8);
      }
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 8);
  }
  return;
}


// sub_080F332C @ 0x080F332C

undefined4 sub_080F332C(void)

{
  uint uVar1;
  
  if (DAT_0203cb7e == 1) {
    DAT_0203cb7e = 2;
  }
  else if (DAT_0203cb7e < 2) {
    if (DAT_0203cb7e == 0) {
      DAT_0203cb7e = 1;
      sub_081293F8(1);
    }
  }
  else if (DAT_0203cb7e == 2) {
    uVar1 = sub_08129440();
    uVar1 = uVar1 & 0xff;
    if (uVar1 == 1) {
      return 1;
    }
    if (1 < uVar1) {
      if (uVar1 == 2) {
        return 2;
      }
      if (uVar1 == 0xff) {
        return 3;
      }
    }
  }
  else if (DAT_0203cb7e == 3) {
    return 3;
  }
  return 0;
}


// sub_080F3398 @ 0x080F3398

undefined4 sub_080F3398(void)

{
  uint uVar1;
  
  if (DAT_0203cb7e == 1) {
    uVar1 = sub_0812D5FC();
    if ((uVar1 & 0xff) != 0) {
      DAT_0203cb7e = 6;
    }
  }
  else if (DAT_0203cb7e < 2) {
    if (DAT_0203cb7e == 0) {
      sub_0812D390();
      DAT_0203cb7e = 1;
    }
  }
  else if (DAT_0203cb7e == 6) {
    return 1;
  }
  return 0;
}


// sub_080F33E8 @ 0x080F33E8

undefined4 sub_080F33E8(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  switch(DAT_0203cb7e) {
  case 0:
    DAT_0203d390 = 0;
    iVar2 = sub_080EDAD0();
    if (iVar2 == 0) {
      iVar2 = sub_080ED954();
      if (iVar2 != 0) {
        DAT_0203cb7e = 7;
        return 0;
      }
      iVar2 = sub_080C2554((&DAT_0203cb90)[DAT_0203d390]);
      if (iVar2 == 0) goto LAB_080f361a;
      goto LAB_080f3560;
    }
    uVar3 = Menu_ExpandListTemplate(0x8124a62,0);
    BattleMenu_SetMode(3,uVar3);
    goto LAB_080f362e;
  case 1:
    sub_080AB98C(DAT_0203cb74,0);
    sub_080EA528();
    DAT_0203c24c = sub_080ABC40(1,0,0x15,3);
    DAT_0203c250 = sub_080ABC40(1,3,0xb,6);
    DAT_0203c254 = sub_080ABC40(0xf,7,0xe,6);
    DAT_0203cb7e = DAT_0203cb7e + 1;
    iVar2 = sub_080ED954();
    if (((iVar2 == 0) || (iVar2 = sub_080EDA24(0), iVar2 == 0)) ||
       (iVar2 = sub_080EDA24(1), iVar2 == 0)) {
      sub_080E6DBC(0);
    }
    break;
  case 2:
    uVar1 = sub_080F3740(0);
    if ((uVar1 & 0xffff) == 0) {
      return 0;
    }
    DAT_0203c893 = 0;
    sub_080F390C(0);
    goto LAB_080f3560;
  case 3:
    uVar1 = sub_080F3C4C();
    if ((uVar1 & 0xffff) == 0) {
      return 0;
    }
    goto LAB_080f3560;
  case 4:
    sub_080ECB38();
    sub_080F3DA4();
LAB_080f3560:
    DAT_0203cb7e = DAT_0203cb7e + 1;
    break;
  case 5:
    uVar1 = sub_080F3740(1);
    if ((uVar1 & 0xffff) != 0) {
      return 1;
    }
    break;
  case 6:
    iVar2 = sub_080EA934();
    if (iVar2 == 1) {
      return 1;
    }
    break;
  case 7:
    iVar2 = sub_080EDA24(0);
    if ((iVar2 != 0) && (iVar2 = sub_080EDA24(1), iVar2 != 0)) {
      BattleMenu_SetMode(3,0x81242ce);
      sub_080EC99C(1);
      sub_080E6DBC(1);
      DAT_0203c895 = 0;
      DAT_0203cb7e = 8;
      DAT_0203d390 = 0;
      return 0;
    }
    iVar2 = sub_080EDA24(0);
    DAT_0203d390 = (ushort)(iVar2 == 0);
    iVar2 = sub_080C2554((&DAT_0203cb90)[DAT_0203d390]);
    if (iVar2 != 0) {
      DAT_0203cb7e = 1;
      return 0;
    }
LAB_080f361a:
    uVar3 = Menu_ExpandListTemplate(0x8124a50,0);
    BattleMenu_SetMode(3,uVar3);
LAB_080f362e:
    DAT_0203cb7e = 6;
    break;
  case 8:
    if ((DAT_030031b8 & 0x10) == 0) {
      if ((DAT_030031b8 & 0x20) == 0) {
        if ((DAT_030031b8 & 1) == 0) {
          if ((DAT_030031b8 & 2) == 0) {
            return 0;
          }
          sub_080ECF70(0x66);
          sub_080ECB38();
          return 1;
        }
        DAT_0203d390 = (ushort)DAT_0203c895;
        sub_080ECF70(0x65);
        iVar2 = sub_080C2554((&DAT_0203cb90)[DAT_0203d390]);
        if (iVar2 == 0) {
          uVar3 = Menu_ExpandListTemplate(0x8124a50,0);
          BattleMenu_SetMode(3,uVar3);
          DAT_0203cb7e = 6;
          sub_080ECB38();
          return 0;
        }
        DAT_0203cb7e = 1;
        return 0;
      }
      if (DAT_0203c895 == 0) {
        return 0;
      }
      DAT_0203d36c = 0x50;
      DAT_0203c895 = (byte)DAT_030031b8 & 0x10;
    }
    else {
      if (DAT_0203c895 == 1) {
        return 0;
      }
      DAT_0203c895 = 1;
      DAT_0203d36c = 0xa0;
    }
    sub_080ECF70(100);
  }
  return 0;
}


// sub_080F3740 @ 0x080F3740

uint sub_080F3740(undefined4 arg0)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((byte)arg0 == 1) {
    if (*(short *)(DAT_0203c250 + 0x2e) == 2) {
      uVar1 = 1;
    }
  }
  else if (((byte)arg0 < 2) && ((byte)arg0 == 0)) {
    uVar1 = -(*(ushort *)(DAT_0203c250 + 0x1e) ^ 0xff) >> 0x1f;
  }
  return uVar1;
}


// sub_080F3780 @ 0x080F3780

void sub_080F3780(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x200dfd4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = 0x8771f54;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x840000d0;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6006000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_080F3814 @ 0x080F3814

void sub_080F3814(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_8 [8];
  
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x850000d0;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_080F3850 @ 0x080F3850

void sub_080F3850(int arg0,uint arg1,uint arg2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  
  uVar4 = 0;
  if ((arg2 & 0xffff) != 0) {
    do {
      uVar2 = (uint)*(byte *)(uVar4 + (arg1 & 0xffff) + arg0);
      if (uVar2 == 0xff) {
        uVar2 = 0;
        do {
          Font_DrawGlyphTinted
                    (0x3c,0x30002b4,uVar2 * 0xc0000 + 0xc0000 >> 0x10,uVar4 * 0xd + 3 & 0xffff);
          uVar2 = uVar2 + 1 & 0xffff;
        } while (uVar2 < 8);
      }
      else {
        iVar3 = sub_080BF5C0(uVar2);
        puVar5 = (ushort *)(iVar3 + 6);
        uVar2 = 0;
        do {
          uVar1 = *puVar5;
          puVar5 = puVar5 + 1;
          Font_DrawGlyphTinted
                    ((uint)uVar1,0x30002b4,uVar2 * 0xc0000 + 0xc0000 >> 0x10,
                     uVar4 * 0xd + 3 & 0xffff);
          uVar2 = uVar2 + 1 & 0xffff;
        } while (uVar2 < 8);
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < (arg2 & 0xffff));
  }
  return;
}


// sub_080F390C @ 0x080F390C

void sub_080F390C(undefined4 arg0)

{
  ushort uVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  ushort *puVar5;
  undefined4 arg1;
  uint uVar6;
  uint uVar7;
  undefined *arg0_00;
  ushort *puVar8;
  byte local_20 [8];
  
  pbVar2 = (byte *)sub_080BF648((uint)*(ushort *)(&DAT_0203cb90 + DAT_0203d390));
  iVar3 = sub_0815B864();
  sub_081272AC();
  uVar6 = 0;
  do {
    sub_080ACAB0(uVar6 * 8 + 0x876f81c,0x30000b4,3,uVar6 * 9 + 6 & 0xffff);
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 4);
  if ((char)*pbVar2 < '\r') {
    arg0_00 = (undefined *)0x876f83c;
  }
  else {
    arg0_00 = (undefined *)0x876f84c;
    if ((char)*pbVar2 < '\x1b') {
      arg0_00 = &DAT_0876f844;
    }
  }
  sub_080ACAB0(arg0_00,0x30000b4,0x3e,6);
  if (iVar3 == 0) {
    arg0_00 = (undefined *)0x876f854;
  }
  else if (iVar3 == 1) {
    arg0_00 = (undefined *)0x876f85c;
  }
  else if (iVar3 == 2) {
    arg0_00 = (undefined *)0x876f864;
  }
  sub_080ACAB0(arg0_00,0x30000b4,0x4e,6);
  pbVar4 = (byte *)sub_080A9CC0((uint)pbVar2[1]);
  sub_080ACA74(*pbVar4 + 9,0x30000b4,0x4e,0xf);
  if (pbVar4[1] != 0) {
    sub_080ACA74(pbVar4[1] + 9,0x30000b4,0x46,0xf);
  }
  pbVar4 = (byte *)sub_080A9CC0((int)*(short *)(pbVar2 + 2));
  sub_080ACA74(*pbVar4 + 9,0x30000b4,0x4e,0x18);
  if ((pbVar4[1] != 0) || (pbVar4[2] != 0)) {
    sub_080ACA74(pbVar4[1] + 9,0x30000b4,0x46,0x18);
    if (pbVar4[2] != 0) {
      sub_080ACA74(pbVar4[2] + 9,0x30000b4,0x3e,0x18);
    }
  }
  pbVar4 = (byte *)sub_080A9CC0((int)*(short *)(pbVar2 + 4));
  sub_080ACA74(*pbVar4 + 9,0x30000b4,0x4e,0x21);
  if ((pbVar4[1] != 0) || (pbVar4[2] != 0)) {
    sub_080ACA74(pbVar4[1] + 9,0x30000b4,0x46,0x21);
    if (pbVar4[2] != 0) {
      sub_080ACA74(pbVar4[2] + 9,0x30000b4,0x3e,0x21);
    }
  }
  if (2 < (byte)arg0) {
    puVar5 = (ushort *)(pbVar2 + 0x32);
    uVar6 = 0;
    puVar8 = (ushort *)(pbVar2 + 0x48);
    do {
      uVar1 = *puVar5;
      puVar5 = puVar5 + 1;
      Font_DrawGlyphTinted((uint)uVar1,0x30002b4,uVar6 * 0xc0000 + 0xc0000 >> 0x10,3);
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 8);
    uVar6 = 0;
    do {
      uVar1 = *puVar8;
      puVar8 = puVar8 + 1;
      Font_DrawGlyphTinted((uint)uVar1,0x30002b4,uVar6 * 0xc0000 + 0xc0000 >> 0x10,0x10);
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 8);
    if (pbVar2[0x1a] == 0xff) {
      puVar5 = (ushort *)0x876f86c;
    }
    else if (*(ushort *)(pbVar2 + 0x1a) < 0xd0) {
      iVar3 = Equipment_GetRecord36_MidRange((uint)pbVar2[0x1a]);
      puVar5 = (ushort *)(iVar3 + 0x14);
    }
    else {
      iVar3 = Action_GetRecord(*(ushort *)(pbVar2 + 0x1a) & 0x1ff);
      puVar5 = (ushort *)(iVar3 + 0xc);
    }
    uVar6 = 0;
    do {
      uVar1 = *puVar5;
      puVar5 = puVar5 + 1;
      Font_DrawGlyphTinted((uint)uVar1,0x30002b4,uVar6 * 0xc0000 + 0xc0000 >> 0x10,0x1d);
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 8);
    goto LAB_080f3bf0;
  }
  uVar6 = 0;
  uVar7 = 0;
  do {
    local_20[uVar7] = 0xff;
    uVar7 = uVar7 + 1 & 0xffff;
  } while (uVar7 < 7);
  uVar7 = 0;
  do {
    if (pbVar2[uVar7 + 0x11] != 0xff) {
      local_20[uVar6] = pbVar2[uVar7 + 0x11];
      uVar6 = uVar6 + 1 & 0xff;
    }
    uVar7 = uVar7 + 1 & 0xffff;
  } while (uVar7 < 7);
  if ((byte)arg0 == 1) {
    arg1 = 3;
  }
  else {
    if (1 < (byte)arg0) {
      if ((byte)arg0 == 2) {
        sub_080F3850(local_20,6,1);
      }
      goto LAB_080f3bf0;
    }
    if ((byte)arg0 != 0) goto LAB_080f3bf0;
    arg1 = 0;
  }
  sub_080F3850(local_20,arg1,3);
LAB_080f3bf0:
  puVar5 = (ushort *)sub_080EA9F8((uint)*pbVar2);
  uVar6 = 0;
  for (; *puVar5 != 0; puVar5 = puVar5 + 1) {
    Font_DrawGlyphTinted((uint)*puVar5,0x30014b4,uVar6 * 0xc0000 + 0x40000 >> 0x10,4);
    uVar6 = uVar6 + 1 & 0xffff;
  }
  DisplayList_Add(0x80f3781,1);
  return;
}


// sub_080F3C4C @ 0x080F3C4C

undefined4 sub_080F3C4C(void)

{
  int iVar1;
  dword arg0;
  uint uVar2;
  undefined2 local_20 [10];
  
  iVar1 = sub_080BF648((uint)*(ushort *)(&DAT_0203cb90 + DAT_0203d390));
  memset(local_20,0,0x14);
  if ((DAT_030031b8 & 3) != 0) {
    sub_080C51D4(0x66);
    return 1;
  }
  if ((DAT_030031b8 & 0x40) == 0) {
    if (((DAT_030031b8 & 0x80) != 0) && (DAT_0203c893 != 3)) {
      DAT_0203c893 = DAT_0203c893 + 1;
      sub_080F390C((uint)DAT_0203c893);
      sub_080C51D4(100);
    }
  }
  else if (DAT_0203c893 != 0) {
    DAT_0203c893 = DAT_0203c893 - 1;
    sub_080F390C((uint)DAT_0203c893);
    sub_080C51D4(100);
  }
  uVar2 = 0;
  do {
    local_20[uVar2] = *(undefined2 *)(iVar1 + 0x22 + uVar2 * 2);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 8);
  Text_DrawSpriteString(local_20,0,0,0x4a);
  if (DAT_0203c893 == 0) {
    arg0 = 0x8001000;
  }
  else {
    if (1 < (byte)(DAT_0203c893 - 1)) {
      sub_080AA184(0x8000ff0,0,0,1);
      return 0;
    }
    sub_080AA184(0x8001000,0,0,1);
    arg0 = 0x8000ff0;
  }
  sub_080AA184(arg0,0,0,1);
  return 0;
}


// sub_080F3DA4 @ 0x080F3DA4

void sub_080F3DA4(void)

{
  sub_080ABD30(DAT_0203c24c,0);
  sub_080ABD30(DAT_0203c250,0);
  sub_080ABD30(DAT_0203c254,0);
  DisplayList_Add(0x80f3815,1);
  return;
}


// sub_080F3DD8 @ 0x080F3DD8

uint sub_080F3DD8(void)

{
  uint uVar1;
  
  uVar1 = sub_080C1D9C();
  return uVar1 >> 4 & 0xf;
}


// sub_080F3DE8 @ 0x080F3DE8

void sub_080F3DE8(undefined4 arg0)

{
  *(undefined2 *)(DAT_03006438 + 0x1a) = (undefined2)arg0;
  return;
}


// sub_080F3DF4 @ 0x080F3DF4

void sub_080F3DF4(void)

{
  return;
}


// sub_080F3E04 @ 0x080F3E04

void sub_080F3E04(undefined4 arg0)

{
  *(undefined2 *)(DAT_03006438 + 0x1c) = (undefined2)arg0;
  return;
}


// sub_080F3E10 @ 0x080F3E10

void sub_080F3E10(void)

{
  return;
}


// sub_080F3E20 @ 0x080F3E20

void sub_080F3E20(void)

{
  undefined4 in_r0;
  
  sub_080C30AC(in_r0);
  return;
}


// sub_080F3E2C @ 0x080F3E2C

void sub_080F3E2C(void)

{
  undefined4 in_r0;
  
  sub_080C3114(in_r0);
  return;
}


// sub_080F3E38 @ 0x080F3E38

void sub_080F3E38(undefined4 arg0)

{
  *(undefined2 *)(DAT_03006438 + 0x16) = (undefined2)arg0;
  return;
}


// sub_080F3E44 @ 0x080F3E44

int sub_080F3E44(void)

{
  return (int)*(short *)(DAT_03006438 + 0x16);
}


// sub_080F3E54 @ 0x080F3E54

void sub_080F3E54(uint arg0,int arg1)

{
  int iVar1;
  
  if (arg1 != 0) {
    if (arg1 < 1) {
      iVar1 = 0;
      if (arg1 < 0) {
        do {
          sub_080C33AC(arg0 & 0xffff);
          iVar1 = iVar1 + -1;
        } while (arg1 < iVar1);
      }
    }
    else if (0 < arg1) {
      do {
        sub_080C3328(arg0 & 0xffff);
        arg1 = arg1 + -1;
      } while (arg1 != 0);
    }
  }
  return;
}


// sub_080F3E98 @ 0x080F3E98

void sub_080F3E98(uint arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C3100();
                    /* WARNING: Could not recover jumptable at 0x080f3eae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(arg0 <= uVar1);
  return;
}


// sub_080F3EB0 @ 0x080F3EB0

void sub_080F3EB0(uint arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C3168();
                    /* WARNING: Could not recover jumptable at 0x080f3ec6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(arg0 <= uVar1);
  return;
}


// sub_080F3EC8 @ 0x080F3EC8

uint sub_080F3EC8(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (uint)((*(ushort *)(iVar1 + 0xe) & 0x4000) != 0);
}


// sub_080F3EF4 @ 0x080F3EF4

void sub_080F3EF4(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  *(undefined1 *)(iVar1 + 0x5c) = (undefined1)arg1;
  return;
}


// sub_080F3F14 @ 0x080F3F14

uint sub_080F3F14(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (uint)*(byte *)(iVar1 + 0x5c);
}


// sub_080F3F30 @ 0x080F3F30

void sub_080F3F30(undefined4 arg0)

{
  DAT_03005806 = (undefined2)arg0;
  return;
}


// sub_080F3F44 @ 0x080F3F44

uint sub_080F3F44(void)

{
  return (uint)DAT_03005806;
}


// sub_080F3F58 @ 0x080F3F58

void sub_080F3F58(undefined4 arg0)

{
  DAT_03005806 = (ushort)arg0 & DAT_03005806;
  return;
}


// sub_080F3F74 @ 0x080F3F74

void sub_080F3F74(undefined4 arg0)

{
  DAT_03005806 = (ushort)arg0 | DAT_03005806;
  return;
}


// sub_080F3F90 @ 0x080F3F90

undefined4 sub_080F3F90(int arg0,undefined4 arg1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  int iStack_18;
  
  if ((arg0 < 0x10) && (uVar1 = sub_080F3F44(), (uVar1 & 0x200) != 0)) {
    sub_080F3F58(0xfdff);
    iVar2 = 0;
  }
  else if (arg0 < 4) {
    iVar4 = 0;
    iVar5 = 1000;
    do {
      iStack_18 = sub_080C00DC(arg0,iVar4 + 2);
      if (iStack_18 != 0xff) {
        sub_080BF468(iStack_18,7,&iStack_18);
        iVar2 = sub_080ED3D0(iStack_18,arg1);
        if (0xb < iVar2) goto LAB_080f4014;
        if (iVar2 < iVar5) {
          iVar5 = iVar2;
        }
      }
      iVar2 = iVar5;
      iVar4 = iVar4 + 1;
      iVar5 = iVar2;
    } while (iVar4 < 4);
    if (iVar2 == 1000) {
      iVar2 = 8;
    }
  }
  else {
    uVar3 = sub_080C07E0(arg0);
    uVar3 = sub_080ED494((int)(short)uVar3);
    iVar2 = sub_080ED3D0(uVar3,arg1);
  }
LAB_080f4014:
                    /* WARNING: Could not recover jumptable at 0x080f401a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(iVar2);
  return uVar3;
}


// sub_080F401C @ 0x080F401C

int sub_080F401C(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(short *)(iVar1 + 0x18);
}


// sub_080F4038 @ 0x080F4038

int sub_080F4038(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(short *)(iVar1 + 0x1a);
}


// sub_080F4054 @ 0x080F4054

void sub_080F4054(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  *(undefined2 *)(iVar1 + 0x18) = (undefined2)arg1;
  return;
}


// sub_080F4070 @ 0x080F4070

int sub_080F4070(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(short *)(iVar1 + 0x1c);
}


// sub_080F408C @ 0x080F408C

void sub_080F408C(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  *(undefined2 *)(iVar1 + 0x1c) = (undefined2)arg1;
  return;
}


// sub_080F40A8 @ 0x080F40A8

int sub_080F40A8(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(short *)(iVar1 + 0x1e);
}


// sub_080F40C4 @ 0x080F40C4

void sub_080F40C4(undefined4 arg0)

{
  DAT_0203d33c = (undefined2)arg0;
  return;
}


// sub_080F40D8 @ 0x080F40D8

void sub_080F40D8(void)

{
  return;
}


// sub_080F40EC @ 0x080F40EC

int sub_080F40EC(int arg0)

{
  return (int)(char)(&DAT_030050e0)[arg0];
}


// sub_080F4104 @ 0x080F4104

void sub_080F4104(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  *(undefined2 *)(iVar1 + 0xe) = 0;
  return;
}


// sub_080F4120 @ 0x080F4120

void sub_080F4120(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  *(undefined2 *)(iVar1 + 0xe) = 0x8000;
  return;
}


// sub_080F413C @ 0x080F413C

void sub_080F413C(void)

{
  undefined4 in_r0;
  int iVar1;
  undefined4 arg1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C0794(in_r0);
  if (iVar1 == 0) {
    arg1 = 0xffffffe7;
  }
  else {
    if (iVar1 != 2) goto LAB_080f4162;
    arg1 = 0x19;
  }
  sub_080C06EC(0,arg1);
  sub_080C06EC(1,arg1);
LAB_080f4162:
                    /* WARNING: Could not recover jumptable at 0x080f4166. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F4168 @ 0x080F4168

void sub_080F4168(uint arg0,uint arg1)

{
  sub_080F413C();
  sub_080C0248(arg0 & 0xffff,arg1 & 0xffff);
  Party_BuildMemberNameTiles();
  sub_080C6FD8();
  return;
}


// sub_080F4190 @ 0x080F4190

void sub_080F4190(uint arg0)

{
  sub_080C0290(arg0 & 0xffff,0);
  sub_080C08BC(arg0,0xb000);
  return;
}


// sub_080F41B0 @ 0x080F41B0

void sub_080F41B0(uint arg0)

{
  uint uVar1;
  undefined4 arg1;
  
  sub_080C0290(arg0 & 0xffff,1);
  sub_080F4104(arg0);
  uVar1 = sub_080C0818(arg0);
  arg1 = 0x19;
  if ((uVar1 & 0xffff) != 0) {
    arg1 = 100;
  }
  sub_080C06EC(0,arg1);
  sub_080C06EC(1,arg1);
  sub_080C08F8(arg0,0);
  return;
}


// sub_080F41F4 @ 0x080F41F4

uint sub_080F41F4(int arg0)

{
  int iVar1;
  uint uVar2;
  byte abStack_c [4];
  
  memcpy(abStack_c,0x876f87c,4);
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  if (arg0 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = (uint)*(byte *)(iVar1 + 0xd) * 2 + (int)*(char *)(iVar1 + 0x29) +
            (int)*(char *)(iVar1 + 0x2a);
    if (iVar1 < 0) {
      iVar1 = iVar1 + 7;
    }
    uVar2 = iVar1 >> 3;
    if ((int)(uint)abStack_c[arg0] < iVar1 >> 3) {
      uVar2 = (uint)abStack_c[arg0];
    }
  }
  return uVar2;
}


// sub_080F4260 @ 0x080F4260

void sub_080F4260(int arg0)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  uVar3 = 0;
  iVar5 = iVar2 + 0x5d;
  do {
    *(undefined1 *)(iVar5 + uVar3) = 0xff;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x20);
  if (arg0 != 0) {
    iVar2 = (uint)*(byte *)(iVar2 + 0xd) * 2 + (int)*(char *)(iVar2 + 0x29) +
            (int)*(char *)(iVar2 + 0x2a);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    iVar2 = iVar2 >> 3;
    iVar4 = 0;
    do {
      cVar1 = *(char *)(iVar4 + 0x876f880);
      *(char *)(iVar5 + iVar4) = cVar1;
      if (cVar1 == -1) break;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(undefined1 *)(iVar5 + iVar4) = 0xff;
  }
  return;
}


// sub_080F42E0 @ 0x080F42E0

uint sub_080F42E0(int arg0,int arg1)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (uint)*(byte *)(iVar1 + 0x5d + arg1);
}


// sub_080F4300 @ 0x080F4300

int sub_080F4300(int arg0,uint arg1)

{
  uint uVar1;
  int iVar2;
  int arg1_00;
  
  arg1_00 = 0;
  iVar2 = 0;
  if (arg0 < 4) {
    while( true ) {
      uVar1 = sub_080F42E0(arg0,arg1_00);
      if ((uVar1 & 0xff) == 0xff) break;
      uVar1 = sub_080ED6B8(uVar1 & 0xff);
      if ((uVar1 & arg1 & 0xff) != 0) {
        iVar2 = iVar2 + 1;
      }
      arg1_00 = arg1_00 + 1;
    }
  }
  else {
    do {
      uVar1 = sub_080F42E0(arg0,arg1_00);
      uVar1 = uVar1 & 0xff;
      if (((uVar1 != 0xff) && (uVar1 < 0x40)) &&
         (uVar1 = sub_080ED6B8(uVar1), (uVar1 & arg1 & 0xff) != 0)) {
        iVar2 = iVar2 + 1;
      }
      arg1_00 = arg1_00 + 1;
    } while (arg1_00 < 7);
  }
  return iVar2;
}


// sub_080F4360 @ 0x080F4360

undefined4 sub_080F4360(undefined4 arg0)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar4 = 4;
  do {
    iVar1 = sub_080F2F64(uVar4 + 0x8000 & 0xffff);
    if (*(short *)(iVar1 + 0xe) != 0) {
      uVar3 = 0;
      do {
        if (*(char *)(iVar1 + 0x5d + uVar3) == (char)arg0) {
          uVar2 = 1;
          goto LAB_080f439c;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x20);
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0xc);
  uVar2 = 0;
LAB_080f439c:
                    /* WARNING: Could not recover jumptable at 0x080f43a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080F43A4 @ 0x080F43A4

uint sub_080F43A4(undefined4 arg0)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  do {
    if (*(char *)(iVar2 + 0x30050e0) != -1) {
      uVar1 = sub_080C0E44((int)*(char *)(iVar2 + 0x30050e0),arg0);
      if (uVar3 < (uVar1 & 0xffff)) {
        uVar3 = uVar1 & 0xffff;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  return uVar3;
}


// sub_080F43E0 @ 0x080F43E0

uint sub_080F43E0(undefined4 arg0)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = sub_080C0E44(0x10,arg0);
  iVar2 = sub_080ED954();
  if (iVar2 != 0) {
    uVar3 = sub_080C0E44(0x14,arg0);
    if ((int)uVar1 < (int)(uVar3 & 0xffff)) {
      uVar1 = uVar3 & 0xffff;
    }
  }
  return uVar1;
}


// sub_080F4410 @ 0x080F4410

undefined4 sub_080F4410(undefined4 arg0)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080F4300((int)(short)arg0,0xe0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar3 = sub_080C0818((int)(short)arg0);
    if ((uVar3 & 0xb063) == 0) {
      uVar2 = 2;
    }
    else {
      uVar2 = 1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080f4442. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080F4444 @ 0x080F4444

undefined4 sub_080F4444(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int arg0;
  undefined4 uVar4;
  
  uVar4 = 0;
  uVar3 = 0;
  do {
    uVar1 = sub_080F40EC((int)(uVar3 * 0x10000) >> 0x10);
    arg0 = (int)(short)uVar1;
    if (arg0 != -1) {
      if (arg0 < 4) {
        sub_080F4260(arg0);
      }
      uVar1 = sub_080F4410(arg0);
      if ((short)uVar1 == 2) {
        uVar4 = 1;
      }
    }
    uVar2 = uVar3 * 0x10000 + 0x10000;
    uVar3 = uVar2 >> 0x10;
  } while ((int)uVar2 >> 0x10 < 6);
  return uVar4;
}


// sub_080F4490 @ 0x080F4490

undefined4 sub_080F4490(undefined4 arg0)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  do {
    if ((int)*(char *)((int)(short)uVar2 + 0x30050e0) == (int)(short)arg0) {
      return (int)(short)uVar3;
    }
    uVar3 = uVar3 * 0x10000 + 0x10000 >> 0x10;
    uVar1 = (int)(short)uVar2 + 1;
    uVar2 = uVar1 & 0xffff;
  } while ((int)(uVar1 * 0x10000) >> 0x10 < 6);
  return 0xffffffff;
}


// sub_080F44D8 @ 0x080F44D8

void sub_080F44D8(int arg0,int arg1)

{
  memcpy(&DAT_0203cba0 + (arg1 + -0x10) * 0x80,&DAT_0203cba0 + (arg0 + -0x10) * 0x80,0x80);
  return;
}


// sub_080F4504 @ 0x080F4504

undefined4 sub_080F4504(void)

{
  return 5;
}


// sub_080F4508 @ 0x080F4508

void sub_080F4508(void)

{
  return;
}


// sub_080F450C @ 0x080F450C

void sub_080F450C(undefined4 *arg0,undefined4 *arg1)

{
  int iVar1;
  int iVar2;
  uint arg2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C5D98();
  arg2 = (uint)*(byte *)(iVar1 + 2);
  if ((*(byte *)(iVar1 + 1) != 0) && (iVar2 = sub_080C2340((uint)*(byte *)(iVar1 + 1)), iVar2 == 0))
  {
    arg2 = (uint)*(byte *)(iVar1 + 3);
  }
  if (arg2 == 0xff) {
    *arg1 = 0;
    *arg0 = 0;
  }
  else {
    sub_080ED35C(arg0,arg1,arg2);
  }
                    /* WARNING: Could not recover jumptable at 0x080f4544. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F4548 @ 0x080F4548

undefined4 sub_080F4548(int arg0)

{
  uint uVar1;
  undefined4 uVar2;
  code *in_lr;
  uint uStack_8;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = in_lr;
  if (arg0 < 0x58) {
    uVar1 = 1;
  }
  else if (arg0 < 0x70) {
    uVar1 = 2;
  }
  else if (arg0 < 0x80) {
    uVar1 = 4;
  }
  else if (arg0 < 0x94) {
    uVar1 = 8;
  }
  else if (arg0 < 0xa8) {
    uVar1 = 0x10;
  }
  else if (arg0 < 0xbc) {
    uVar1 = 0x20;
  }
  else if (arg0 < 0xd0) {
    uVar1 = 0x40;
  }
  else if (arg0 < 0xff) {
    sub_080BF468(arg0,10,&uStack_8);
    uVar1 = (int)(-(uStack_8 & 0xc0) | uStack_8 & 0xc0) >> 0x1f & 0x200;
    if ((uStack_8 & 0x20) != 0) {
      uVar1 = uVar1 | 0x400;
    }
  }
  else if (arg0 < (int)0x11c) {
    uVar1 = 0x100;
  }
  else {
    uVar1 = 0x80;
  }
                    /* WARNING: Could not recover jumptable at 0x080f45d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar2;
}


// sub_080F45D4 @ 0x080F45D4

int sub_080F45D4(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = 0;
  do {
    iVar1 = sub_080F40EC((int)(short)uVar3);
    if (3 < iVar1) {
      uVar4 = uVar4 * 0x10000 + 0x10000 >> 0x10;
    }
    uVar2 = (int)(short)uVar3 + 1;
    uVar3 = uVar2 & 0xffff;
  } while ((int)(uVar2 * 0x10000) >> 0x10 < 6);
  return (int)(short)uVar4;
}


// sub_080F4608 @ 0x080F4608

void sub_080F4608(undefined4 arg0,undefined4 arg1)

{
  short in_r2;
  short in_r3;
  undefined4 arg3;
  
  arg3 = 5;
  if ((short)arg0 < 4) {
    if ((short)arg0 != 1) {
      if (1 < (short)arg0) {
        if ((short)arg0 == 2) {
          in_r2 = 0x58;
          arg3 = 8;
          in_r3 = 0;
          goto LAB_080f4650;
        }
        if ((short)arg0 != 3) goto LAB_080f4650;
        in_r2 = 0x5a;
        goto LAB_080f464e;
      }
      if ((short)arg0 != 0) goto LAB_080f4650;
    }
    in_r2 = 0x50;
    in_r3 = 0;
  }
  else {
    arg0._0_2_ = (short)arg0 + -4;
    in_r2 = 0x50;
LAB_080f464e:
    in_r3 = 0xf;
  }
LAB_080f4650:
  sub_080F4670((int)(short)arg0,(int)in_r2,(int)in_r3,arg3);
  return;
}


// sub_080F4670 @ 0x080F4670

void sub_080F4670(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  short sVar1;
  int iVar2;
  undefined2 in_stack_00000000;
  
  iVar2 = sub_080AD0FC(0x876f89c,0xffff);
  *(undefined2 *)(iVar2 + 0x26) = in_stack_00000000;
  if ((short)arg0 == 3) {
    sVar1 = (short)arg1 - (short)((int)((uint)(ushort)arg3 << 0x10) >> 0xf);
  }
  else {
    sVar1 = 0;
  }
  *(short *)(iVar2 + 0x28) = sVar1;
  *(ushort *)(iVar2 + 0x24) = (ushort)arg3;
  *(undefined2 *)(iVar2 + 0x2e) = (undefined2)arg2;
  *(short *)(iVar2 + 0x2a) = (short)arg0;
  *(short *)(iVar2 + 0x2c) = (short)arg1;
  CpuFastSet(0x3002db0,0x203d600,0x80);
  return;
}


// sub_080F46E0 @ 0x080F46E0

void sub_080F46E0(ushort *arg0,short *arg1,undefined4 arg2,uint arg3)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  short sVar4;
  ushort uVar6;
  uint in_stack_00000000;
  uint in_stack_00000004;
  uint uVar5;
  
  uVar6 = 0;
  if ((ushort)arg2 != 0) {
    do {
      uVar3 = (uint)*arg0;
      arg0 = arg0 + 1;
      uVar5 = (uVar3 & 0x1f) + ((arg3 & 0xffff) >> 3);
      sVar4 = (short)uVar5;
      if (0x1f < uVar5) {
        sVar4 = 0x1f;
      }
      uVar5 = ((uVar3 & 0x3e0) >> 5) + ((in_stack_00000000 & 0xffff) >> 3);
      sVar1 = (short)uVar5;
      if (0x1f < uVar5) {
        sVar1 = 0x1f;
      }
      uVar3 = ((uVar3 & 0x7c00) >> 10) + ((in_stack_00000004 & 0xffff) >> 3);
      sVar2 = (short)uVar3;
      if (0x1f < uVar3) {
        sVar2 = 0x1f;
      }
      *arg1 = sVar4 + sVar1 * 0x20 + sVar2 * 0x400;
      arg1 = arg1 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < (ushort)arg2);
  }
  return;
}


// sub_080F4784 @ 0x080F4784

void sub_080F4784(int arg0)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  iVar2 = *(ushort *)(arg0 + 0x2e) - 1;
  *(short *)(arg0 + 0x2e) = (short)iVar2;
  if (0 < iVar2 * 0x10000) {
    return;
  }
  sVar1 = *(short *)(arg0 + 0x24) + *(short *)(arg0 + 0x28);
  *(short *)(arg0 + 0x28) = sVar1;
  if (*(short *)(arg0 + 0x2c) <= sVar1) {
    *(short *)(arg0 + 0x24) = -*(short *)(arg0 + 0x24);
  }
  if (*(short *)(arg0 + 0x28) == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    CpuFastSet(0x203d600,0x3002db0,0x80);
    sub_080AABB0();
    return;
  }
  switch(*(undefined2 *)(arg0 + 0x2a)) {
  case 0:
    uVar3 = (uint)(*(short *)(arg0 + 0x28) * 0x30000) >> 0x10;
    break;
  case 1:
    uVar3 = (int)((uint)*(ushort *)(arg0 + 0x28) << 0x10) >> 0x12 & 0xffff;
    break;
  case 2:
    if (*(ushort *)(arg0 + 0x28) == 0x30) {
      sub_080F46E0(0x203d700,0x3002eb0,0x80,0xa0);
    }
    else {
      sVar1 = *(short *)(arg0 + 0x28);
      uVar3 = __divsi3(sVar1 * 0x28,0x34);
      __divsi3(sVar1 * 0x22,0x34);
      sub_080F46E0(0x203d700,0x3002eb0,0x80,(uVar3 & 0x7fff) * 2);
    }
    goto switchD_080f47fa_default;
  case 3:
    uVar3 = ((int)*(short *)(arg0 + 0x28) & 0x7fffU) << 1;
    break;
  case 4:
    iVar2 = __divsi3((int)*(short *)(arg0 + 0x28) << 3,10);
    uVar3 = (uint)(iVar2 * 0x30000) >> 0x10;
    break;
  case 5:
    uVar3 = __divsi3((int)*(short *)(arg0 + 0x28) << 3,10);
    uVar3 = (uVar3 & 0x7fff) << 1;
    break;
  default:
    goto switchD_080f47fa_default;
  }
  sub_080F46E0(0x203d700,0x3002eb0,0x80,uVar3);
switchD_080f47fa_default:
  sub_080AABB0();
  return;
}


// sub_080F4968 @ 0x080F4968

int sub_080F4968(void)

{
  int iVar1;
  int arg0;
  int iVar2;
  
  iVar2 = 0;
  arg0 = 0;
  do {
    iVar1 = sub_080C09B0(arg0);
    if (iVar1 != 0) {
      iVar2 = iVar2 + 1;
    }
    arg0 = arg0 + 1;
  } while (arg0 < 4);
  return iVar2;
}


// sub_080F4988 @ 0x080F4988

void sub_080F4988(int arg0,int arg1)

{
  if (-1 < arg1 + -0x1d) {
    *(undefined4 *)(arg0 + 8) = 0xffffffff;
    *(undefined4 *)(arg0 + 0xc) = 1;
    _call_via_r1(arg0,*(undefined4 *)((arg1 + -0x1d) * 4 + 0x876f940));
  }
  return;
}


// sub_080F49B4 @ 0x080F49B4

void sub_080F49B4(int arg0,int arg1)

{
  *(undefined4 *)(arg0 + 8) = 0xffffffff;
  *(undefined4 *)(arg0 + 0xc) = 1;
  _call_via_r1(arg0,*(undefined4 *)(arg1 * 4 + 0x876f8c0));
  return;
}


// sub_080F49D4 @ 0x080F49D4

void sub_080F49D4(int arg0,int arg1)

{
  if (arg0 != 0) {
    *(undefined4 *)(arg1 + 8) = 0x96;
    *(undefined4 *)(arg1 + 0xc) = 0;
  }
  return;
}


// sub_080F49E8 @ 0x080F49E8

void sub_080F49E8(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080C07E0(*(undefined4 *)(arg0 + 4));
  sub_080F40C4((int)(short)uVar1);
  uVar1 = *(undefined4 *)(arg0 + 4);
  sub_080EFD14(uVar1,0xffffffff);
  sub_080F49D4(uVar1,arg0);
  return;
}


// sub_080F4A10 @ 0x080F4A10

void sub_080F4A10(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080C07E0(*(undefined4 *)(arg0 + 4));
  sub_080F40C4((int)(short)uVar1);
  uVar1 = *(undefined4 *)(arg0 + 4);
  sub_080EFD5C(uVar1,0xffffffff);
  sub_080F49D4(uVar1,arg0);
  return;
}


// sub_080F4A38 @ 0x080F4A38

void sub_080F4A38(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080C07E0(*(undefined4 *)(arg0 + 4));
  sub_080F40C4((int)(short)uVar1);
  uVar1 = *(undefined4 *)(arg0 + 4);
  sub_080EFDA4(uVar1,0xffffffff);
  sub_080F49D4(uVar1,arg0);
  return;
}


// sub_080F4A60 @ 0x080F4A60

void sub_080F4A60(int arg0)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (*(int *)(arg0 + 4) < 0x10) {
    iVar4 = 0;
    do {
      iVar1 = (int)*(char *)(iVar4 + 0x30050e0);
      if (iVar1 != -1) {
        iVar2 = sub_080EFBFC();
        if (0 < iVar2) {
          iVar3 = iVar3 + 1;
          sub_080EFD28(iVar1,-iVar2);
        }
        iVar2 = sub_080EFD3C();
        if (0 < iVar2) {
          iVar3 = iVar3 + 1;
          sub_080EFD70(iVar1,-iVar2);
        }
        iVar2 = sub_080EFD84();
        if (0 < iVar2) {
          iVar3 = iVar3 + 1;
          sub_080EFDB8(iVar1,-iVar2);
        }
        iVar2 = sub_080EFDCC();
        if (0 < iVar2) {
          iVar3 = iVar3 + 1;
          sub_080EFDEC(iVar1,-iVar2);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 6);
  }
  else {
    iVar4 = 0;
    do {
      iVar2 = iVar4 + 0x10;
      iVar1 = sub_080EFBFC();
      if (0 < iVar1) {
        iVar3 = iVar3 + 1;
        sub_080EFD28(iVar2,-iVar1);
      }
      iVar1 = sub_080EFD3C();
      if (0 < iVar1) {
        iVar3 = iVar3 + 1;
        sub_080EFD70(iVar2,-iVar1);
      }
      iVar1 = sub_080EFD84();
      if (0 < iVar1) {
        iVar3 = iVar3 + 1;
        sub_080EFDB8(iVar2,-iVar1);
      }
      iVar1 = sub_080EFDCC();
      if (0 < iVar1) {
        iVar3 = iVar3 + 1;
        sub_080EFE00(iVar2,-iVar1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
  }
  if (iVar3 == 0) {
    *(undefined4 *)(arg0 + 0xc) = 0;
  }
  return;
}


// sub_080F4B54 @ 0x080F4B54

void sub_080F4B54(int *arg0)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (*arg0 < 0x10) {
    iVar4 = 0;
    do {
      iVar1 = (int)*(char *)(iVar4 + 0x30050e0);
      if (iVar1 != -1) {
        iVar2 = sub_080EFBFC();
        if (iVar2 < 0) {
          iVar3 = iVar3 + 1;
          sub_080EFD28(iVar1,-iVar2);
        }
        iVar2 = sub_080EFD3C();
        if (iVar2 < 0) {
          iVar3 = iVar3 + 1;
          sub_080EFD70(iVar1,-iVar2);
        }
        iVar2 = sub_080EFD84();
        if (iVar2 < 0) {
          iVar3 = iVar3 + 1;
          sub_080EFDB8(iVar1,-iVar2);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 6);
  }
  else {
    iVar4 = 0;
    do {
      iVar2 = iVar4 + 0x10;
      iVar1 = sub_080EFBFC();
      if (iVar1 < 0) {
        iVar3 = iVar3 + 1;
        sub_080EFD28(iVar2,-iVar1);
      }
      iVar1 = sub_080EFD3C();
      if (iVar1 < 0) {
        iVar3 = iVar3 + 1;
        sub_080EFD70(iVar2,-iVar1);
      }
      iVar1 = sub_080EFD84();
      if (iVar1 < 0) {
        iVar3 = iVar3 + 1;
        sub_080EFDB8(iVar2,-iVar1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
  }
  if (iVar3 == 0) {
    arg0[3] = 0;
  }
  return;
}


// sub_080F4C20 @ 0x080F4C20

void sub_080F4C20(void)

{
  undefined4 in_r0;
  
  sub_080F4C90(in_r0,0x20,0x330);
  return;
}


// sub_080F4C30 @ 0x080F4C30

void sub_080F4C30(undefined4 *arg0)

{
  undefined4 arg0_00;
  
  arg0_00 = *arg0;
  sub_080EFD14(arg0_00,1);
  sub_080F49D4(arg0_00,arg0);
  return;
}


