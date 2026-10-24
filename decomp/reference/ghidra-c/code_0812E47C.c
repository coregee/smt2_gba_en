/* Ghidra decompilation of asm/code_0812E47C.s (reference only; not compiled). */

// sub_0812E47C @ 0x0812E47C

void sub_0812E47C(undefined4 arg0)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2C30();
  if ((uVar1 & 0xffff) == 0) {
    for (pbVar4 = (byte *)0x877a509; *pbVar4 != 0xff; pbVar4 = pbVar4 + 1) {
      iVar2 = sub_080C10B4((uint)*pbVar4);
      if (iVar2 != 0) {
        sub_0812E6C4((int)(short)arg0,0,(uint)*pbVar4);
        uVar3 = 1;
        goto LAB_0812e4b8;
      }
    }
  }
  uVar3 = 0;
LAB_0812e4b8:
                    /* WARNING: Could not recover jumptable at 0x0812e4bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar3);
  return;
}


// sub_0812E4C0 @ 0x0812E4C0

undefined4 sub_0812E4C0(int arg0)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = (&DAT_030046d0)[arg0 * 0x40];
  uVar2 = sub_080C2C30();
  if ((uVar2 & 0xffff) == 0) {
    for (pbVar5 = (byte *)0x877a50c; *pbVar5 != 0xff; pbVar5 = pbVar5 + 4) {
      iVar3 = sub_080C10B4((uint)*pbVar5);
      if ((iVar3 != 0) && ((*(ushort *)(pbVar5 + 2) & uVar1) != 0)) {
        sub_0812E6C4((int)(short)arg0,0,(uint)*pbVar5);
        uVar4 = 1;
        goto LAB_0812e550;
      }
    }
  }
  iVar3 = sub_080F31E0();
  if (iVar3 == 0) {
    for (pbVar5 = (byte *)0x877a52c; *pbVar5 != 0xff; pbVar5 = pbVar5 + 4) {
      uVar4 = sub_0812E558((uint)*pbVar5);
      if ((-1 < (short)uVar4) && ((*(ushort *)(pbVar5 + 2) & uVar1) != 0)) {
        sub_0812E688((int)(short)arg0,(int)(short)uVar4,(uint)*pbVar5);
        uVar4 = 1;
        goto LAB_0812e550;
      }
    }
  }
  uVar4 = 0;
LAB_0812e550:
                    /* WARNING: Could not recover jumptable at 0x0812e554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar4);
  return uVar4;
}


// sub_0812E558 @ 0x0812E558

undefined4 sub_0812E558(uint arg0)

{
  short sVar1;
  uint arg0_00;
  int *piVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  code *UNRECOVERED_JUMPTABLE;
  int local_34 [6];
  
  piVar9 = local_34;
  piVar11 = local_34;
  arg0_00 = arg0 & 0xffff;
  iVar10 = 0;
  piVar2 = local_34 + 5;
  do {
    *piVar2 = -1;
    piVar2 = piVar2 + -1;
  } while ((int)local_34 <= (int)piVar2);
  iVar8 = 4;
  do {
    iVar3 = sub_080F3EC8(iVar8);
    if ((iVar3 != 0) && (uVar4 = sub_080C0818(iVar8), (uVar4 & 0xb063) == 0)) {
      iVar3 = 0;
      pbVar5 = (byte *)(iVar8 * 0x80 + 0x300471d);
      if (*pbVar5 == 0xff) goto LAB_0812e5bc;
      uVar4 = (uint)*pbVar5;
      while (uVar4 != arg0_00) {
LAB_0812e5bc:
        do {
          iVar3 = iVar3 + 1;
          if (7 < iVar3) goto LAB_0812e5d2;
          uVar4 = (uint)pbVar5[iVar3];
        } while (uVar4 == 0xff);
      }
      *piVar11 = iVar8;
      piVar11 = piVar11 + 1;
      iVar10 = iVar10 + 1;
    }
LAB_0812e5d2:
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x10);
  piVar2 = local_34 + iVar10;
  iVar8 = 1;
  do {
    iVar3 = sub_080F3EC8(iVar8);
    iVar7 = iVar8 + 1;
    if ((iVar3 != 0) && (uVar4 = sub_080C0818(iVar8), (uVar4 & 0xb063) == 0)) {
      iVar3 = 0;
      pbVar5 = (byte *)(iVar8 * 0x80 + 0x300471d);
      if (*pbVar5 == 0xff) goto LAB_0812e620;
      uVar4 = (uint)*pbVar5;
      while (uVar4 != arg0_00) {
LAB_0812e620:
        do {
          iVar3 = iVar3 + 1;
          if (0x1f < iVar3) goto LAB_0812e636;
          uVar4 = (uint)pbVar5[iVar3];
        } while (uVar4 == 0xff);
      }
      *piVar2 = iVar8;
      piVar2 = piVar2 + 1;
      iVar10 = iVar10 + 1;
    }
LAB_0812e636:
    iVar8 = iVar7;
  } while (iVar7 < 4);
  if (iVar10 != 0) {
    iVar10 = 0;
    do {
      if ((*piVar9 != -1) &&
         (sVar1 = (&DAT_030046dc)[*piVar9 * 0x40], uVar4 = sub_080ED6CC(arg0_00),
         uVar4 <= (uint)(int)sVar1)) {
        iVar10 = *piVar9;
        goto LAB_0812e674;
      }
      piVar9 = piVar9 + 1;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 6);
  }
  iVar10 = -1;
LAB_0812e674:
                    /* WARNING: Could not recover jumptable at 0x0812e680. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar6 = (*UNRECOVERED_JUMPTABLE)(iVar10);
  return uVar6;
}


// sub_0812E688 @ 0x0812E688

void sub_0812E688(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  int iStack_2c;
  int iStack_28;
  
  iStack_28 = (int)(short)arg0;
  iStack_2c = (int)(short)arg1;
  sub_080F4988(&iStack_2c,(int)(short)arg2);
  sub_080ED6DC((int)(short)arg1,(int)(short)arg2);
  DAT_030020b4 = 1;
  return;
}


// sub_0812E6C4 @ 0x0812E6C4

void sub_0812E6C4(undefined4 arg0,undefined4 arg1,int arg2)

{
  uint uVar1;
  int arg0_00;
  short sVar2;
  int iStack_34;
  int iStack_30;
  int iStack_14;
  
  sVar2 = -1;
  iStack_34 = (int)(short)arg1;
  iStack_30 = (int)(short)arg0;
  sub_080BF468((int)(short)arg2,0xc,&iStack_14);
  if (iStack_14 < 0x80) {
    sub_080F4988(&iStack_34,iStack_14);
  }
  else {
    sub_080F5C90(&iStack_34,(int)(short)arg2);
  }
  arg0_00 = arg2 * 0x10000 >> 0x10;
  if ((arg0_00 == 0xb5) && (uVar1 = sub_080C2244(), (uVar1 & 7) != 0)) {
    sVar2 = 0;
  }
  sub_080F3E54(arg0_00,(int)sVar2);
  DAT_030020b4 = 1;
  return;
}


// sub_0812E734 @ 0x0812E734

void sub_0812E734(void)

{
  DAT_0203c248 = sub_080AD0FC(0x877a54c,0xffff);
  DAT_0203c892 = 0xfe;
  sub_080EA210();
  DAT_030065cd = 0;
  return;
}


// sub_0812E770 @ 0x0812E770

void sub_0812E770(void)

{
  sub_080EA964();
  sub_08128EB4();
  return;
}


// sub_0812E780 @ 0x0812E780

void sub_0812E780(int arg0,int arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  dword arg0_00;
  uint uVar4;
  int iVar5;
  int local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  uint local_18;
  
  local_18 = (uint)DAT_030065c2;
  if ((char)arg3 == '\x01') {
    sub_080BF468(local_18,0xc,&local_18);
  }
  iVar5 = arg0 << 0x10;
  if (local_18 - 0x2b < 0x15) {
    uVar3 = sub_080F0F68(local_18 & 0xffff,0);
    switch(uVar3 & 0xff) {
    case 0xf0:
      iVar5 = arg0 * 0x10000;
      uVar2 = sub_080F4490((uint)*(ushort *)((iVar5 >> 0xf) + arg1));
      if ((short)uVar2 != -1) {
        sub_080ECE08(4);
        sub_080ECE38((int)(short)uVar2,0,3);
      }
      break;
    case 0xf1:
      iVar5 = arg0 * 0x10000;
      uVar2 = sub_080F4490((uint)*(ushort *)((iVar5 >> 0xf) + arg1));
      if ((short)uVar2 != -1) {
        sub_080ECE08(4);
        sub_080ECE38((int)(short)uVar2,0,0);
      }
      break;
    case 0xf2:
      iVar5 = arg0 * 0x10000;
      uVar2 = sub_080F4490((uint)*(ushort *)((iVar5 >> 0xf) + arg1));
      if ((short)uVar2 != -1) {
        sub_080ECE08(4);
        sub_080ECE38((int)(short)uVar2,0,5);
      }
      break;
    case 0xf3:
      iVar5 = arg0 * 0x10000;
      uVar2 = sub_080F4490((uint)*(ushort *)((iVar5 >> 0xf) + arg1));
      if ((short)uVar2 != -1) {
        sub_080ECE08(4);
        sub_080ECE38((int)(short)uVar2,0,1);
      }
      break;
    case 0xf4:
      uVar3 = 0;
      iVar5 = arg0 << 0x10;
      do {
        sub_080ECE08(5);
        uVar4 = (uint)(short)uVar3;
        sub_080ECE38(uVar4,(uVar4 & 0x3f) << 2,3);
        uVar3 = uVar4 + 1 & 0xffff;
      } while ((int)((uVar4 + 1) * 0x10000) >> 0x10 < 6);
      break;
    case 0xf5:
      uVar3 = 0;
      iVar5 = arg0 << 0x10;
      do {
        sub_080ECE08(5);
        uVar4 = (uint)(short)uVar3;
        sub_080ECE38(uVar4,(uVar4 & 0x3f) << 2,0);
        uVar3 = uVar4 + 1 & 0xffff;
      } while ((int)((uVar4 + 1) * 0x10000) >> 0x10 < 6);
      break;
    case 0xf6:
      uVar3 = 0;
      iVar5 = arg0 << 0x10;
      do {
        sub_080ECE08(5);
        uVar4 = (uint)(short)uVar3;
        sub_080ECE38(uVar4,(uVar4 & 0x3f) << 2,5);
        uVar3 = uVar4 + 1 & 0xffff;
      } while ((int)((uVar4 + 1) * 0x10000) >> 0x10 < 6);
      break;
    case 0xf7:
      uVar3 = 0;
      iVar5 = arg0 << 0x10;
      do {
        sub_080ECE08(5);
        uVar4 = (uint)(short)uVar3;
        sub_080ECE38(uVar4,(uVar4 & 0x3f) << 2,1);
        uVar3 = uVar4 + 1 & 0xffff;
      } while ((int)((uVar4 + 1) * 0x10000) >> 0x10 < 6);
    }
    uVar3 = sub_080F104C(local_18 & 0xffff,0);
    sub_080ECF70(uVar3 & 0xffff);
  }
  iVar1 = sub_080BF5C0(local_18 & 0xffff);
  local_38 = iVar5 >> 0x10;
  if ((*(char *)(iVar1 + 2) == -0x80) || (*(char *)(iVar1 + 2) == -0x7e)) {
    local_34 = (uint)*(ushort *)(local_38 * 2 + arg1);
  }
  else {
    local_34 = 0x10;
  }
  sub_080F4988(&local_38,local_18);
  sub_080C84A0();
  DAT_030065c0 = 0;
  if (local_2c != 1) {
    if (local_30 == 0xffffffff) {
      uVar2 = Menu_ExpandListTemplate(0x8124534,0);
      BattleMenu_SetMode(3,uVar2);
      return;
    }
    uVar2 = sub_080EC038(local_30 & 0xffff);
    uVar2 = Menu_ExpandListTemplate(uVar2,0);
    BattleMenu_SetMode(3,uVar2);
    return;
  }
  if (local_30 == 0xffffffff) {
    uVar3 = (uint)*(ushort *)(((int)((local_18 - 0x1d) * 0x20000) >> 0xf) + 0x876f9cc);
    if (uVar3 == 0xffff) goto LAB_0812e9f2;
    arg0_00 = uVar3 & 0x7fff;
  }
  else {
    arg0_00 = local_30 & 0xffff;
  }
  if (arg0_00 != 0xffff) {
    uVar2 = sub_080EC038(arg0_00);
    uVar2 = Menu_ExpandListTemplate(uVar2,local_34);
    BattleMenu_SetMode(3,uVar2);
  }
LAB_0812e9f2:
  if (local_18 == 0x3a) {
    DAT_030065c0 = 1;
  }
  if (local_18 == 0x3b) {
    DAT_030065c0 = 2;
  }
  return;
}


// sub_0812EA54 @ 0x0812EA54

undefined4 sub_0812EA54(void)

{
  int iVar1;
  uint uVar2;
  int arg0;
  
  arg0 = 0;
  while (((iVar1 = sub_080C0A00(arg0), iVar1 == 0 || (iVar1 = sub_080F3EC8(arg0), iVar1 == 0)) ||
         (uVar2 = sub_080C0818(arg0), (uVar2 & 0xb060) != 0))) {
    arg0 = arg0 + 1;
    if (3 < arg0) {
      return 0xffffffff;
    }
  }
  return (int)(short)arg0;
}


// sub_0812EA98 @ 0x0812EA98

void sub_0812EA98(undefined4 arg0)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  dword dVar5;
  uint uVar6;
  int local_44;
  int local_40;
  uint local_3c;
  int local_38;
  undefined1 auStack_24 [4];
  int local_20;
  
  local_20 = (int)(short)DAT_030065c2;
  iVar2 = Action_GetRecord((uint)DAT_030065c2);
  cVar1 = *(char *)(iVar2 + 3);
  sub_080BF468(local_20,0xc,auStack_24);
  iVar2 = local_20 * 4;
  switch(*(undefined1 *)(iVar2 + 0x876e2d8)) {
  case 0xf0:
    iVar3 = sub_080F4490((int)*(short *)(&DAT_0203d130 + ((int)((uint)(ushort)arg0 << 0x10) >> 0xf))
                        );
    if (iVar3 != -1) {
      sub_080ECE08(4);
      sub_080ECE38((int)(short)iVar3,0,3);
    }
    break;
  case 0xf1:
    iVar3 = sub_080F4490((int)*(short *)(&DAT_0203d130 + ((int)((uint)(ushort)arg0 << 0x10) >> 0xf))
                        );
    if (iVar3 != -1) {
      sub_080ECE08(4);
      sub_080ECE38((int)(short)iVar3,0,0);
    }
    break;
  case 0xf2:
    iVar3 = sub_080F4490((int)*(short *)(&DAT_0203d130 + ((int)((uint)(ushort)arg0 << 0x10) >> 0xf))
                        );
    if (iVar3 != -1) {
      sub_080ECE08(4);
      sub_080ECE38((int)(short)iVar3,0,5);
    }
    break;
  case 0xf3:
    iVar3 = sub_080F4490((int)*(short *)(&DAT_0203d130 + ((int)((uint)(ushort)arg0 << 0x10) >> 0xf))
                        );
    if (iVar3 != -1) {
      sub_080ECE08(4);
      sub_080ECE38((int)(short)iVar3,0,1);
    }
    break;
  case 0xf4:
    uVar6 = 0;
    do {
      sub_080ECE08(5);
      sub_080ECE38((int)(short)uVar6,(uVar6 & 0x3f) << 2,3);
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 6);
    break;
  case 0xf5:
    uVar6 = 0;
    do {
      sub_080ECE08(5);
      sub_080ECE38((int)(short)uVar6,(uVar6 & 0x3f) << 2,0);
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 6);
    break;
  case 0xf6:
    uVar6 = 0;
    do {
      sub_080ECE08(5);
      sub_080ECE38((int)(short)uVar6,(uVar6 & 0x3f) << 2,5);
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 6);
    break;
  case 0xf7:
    uVar6 = 0;
    do {
      sub_080ECE08(5);
      sub_080ECE38((int)(short)uVar6,(uVar6 & 0x3f) << 2,1);
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 6);
  }
  sub_080ECF70((uint)*(ushort *)(&DAT_0876e2da + iVar2));
  if (((cVar1 == -0x80) || (cVar1 == -0x7e)) || (cVar1 == -0x7d)) {
    local_44 = (int)(short)(ushort)arg0;
    local_40 = (int)*(short *)(&DAT_0203d130 + local_44 * 2);
    uVar4 = sub_080C07E0(local_40);
    sub_080F40C4((int)(short)uVar4);
  }
  else {
    local_44 = (int)(short)(ushort)arg0;
    local_40 = 0x10;
  }
  sub_080F5C90(&local_44,local_20);
  sub_080C84A0();
  if (local_38 == 1) {
    sub_080F3E38(local_20);
    sub_080BF468(local_20,0xc,&local_20);
    if (local_3c == 0xffffffff) {
      dVar5 = (dword)*(ushort *)(((local_20 + -0x80) * 0x10000 >> 0xf) + 0x876fae4);
    }
    else {
      dVar5 = local_3c & 0xffff;
    }
    if (dVar5 == 0xffff) {
      return;
    }
    dVar5 = sub_080EC038(dVar5);
    iVar2 = local_40 + (short)DAT_030065c2 * 0x10000;
  }
  else {
    if (local_3c != 0xffffffff) {
      uVar4 = sub_080EC038(local_3c & 0xffff);
      uVar4 = Menu_ExpandListTemplate(uVar4,0);
      BattleMenu_SetMode(3,uVar4);
      return;
    }
    dVar5 = 0x8124534;
    iVar2 = 0;
  }
  uVar4 = Menu_ExpandListTemplate(dVar5,iVar2);
  BattleMenu_SetMode(3,uVar4);
  return;
}


// sub_0812ED54 @ 0x0812ED54

void sub_0812ED54(void)

{
  sub_081269B0(2);
  return;
}


// sub_0812ED60 @ 0x0812ED60

void sub_0812ED60(int arg0)

{
  DAT_0203d3a2 = (&DAT_0203c4d0)[*(ushort *)(arg0 + 0x1e)];
  sub_081269B0(2);
  return;
}


// sub_0812ED8C @ 0x0812ED8C

void sub_0812ED8C(int arg0)

{
  uint uVar1;
  undefined4 arg1;
  
  DAT_0203c24c = sub_080ABC40(1,0,0xf,10);
  DAT_0203c250 = sub_080ABC40(0x11,0,0xc,6);
  sub_081272AC();
  uVar1 = sub_0812A668((uint)DAT_0203c897);
  uVar1 = uVar1 & 0xffff;
  sub_081269B0(2);
  if (uVar1 < 5) {
    sub_08126928(2,0,1,uVar1);
  }
  else {
    sub_08126928(2,0x10,1,uVar1);
  }
  if ((*(char *)(arg0 + 6) != '\0') && (*(char *)(arg0 + 6) == '\x01')) {
    sub_080EA210();
    arg1 = Menu_ExpandListTemplate(0x8124d72,0);
    BattleMenu_SetMode(4,arg1);
  }
  return;
}


// sub_0812EE28 @ 0x0812EE28

void sub_0812EE28(int arg0)

{
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  if (DAT_0203c250 != 0) {
    sub_080ABD30(DAT_0203c250,0);
  }
  sub_08128388();
  if ((*(char *)(arg0 + 6) != '\0') && (*(char *)(arg0 + 6) == '\x01')) {
    sub_080EA964();
  }
  return;
}


// sub_0812EE64 @ 0x0812EE64

void sub_0812EE64(int arg0)

{
  undefined4 arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  if (*(char *)(arg0 + 6) == '\0') {
    sub_080C700C();
    sub_080C7430();
    sub_080C7648();
  }
  else if (*(char *)(arg0 + 6) == '\x01') {
    arg0_00 = sub_080AD364(arg0);
    sub_080AD348(arg0_00);
  }
                    /* WARNING: Could not recover jumptable at 0x0812ee88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812EE8C @ 0x0812EE8C

int sub_0812EE8C(int arg0,int arg1)

{
  int iVar1;
  dword arg1_00;
  
  arg1_00 = 0xffff;
  if (arg1 != 0) {
    arg1_00 = (dword)*(ushort *)(arg1 + 2);
  }
  iVar1 = sub_080AD0FC(0x877a580,arg1_00);
  *(char *)(iVar1 + 6) = (char)arg0;
  if (arg0 == 0) {
    sub_080C6FF0();
    sub_080C7414();
    sub_080C762C();
  }
  return iVar1;
}


// sub_0812EEC4 @ 0x0812EEC4

uint sub_0812EEC4(void)

{
  return (uint)DAT_0203d3a2;
}


// sub_0812EED8 @ 0x0812EED8

void sub_0812EED8(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203c894 == 1) {
LAB_0812ef1c:
    (&DAT_0203d0f0)[(char)(&DAT_030050e0)[DAT_0203d166]] = (ushort)DAT_0203c892;
    (&DAT_0203d110)[(char)(&DAT_030050e0)[DAT_0203d166]] = *(undefined2 *)(arg0 + 0x1e);
  }
  else {
    if (DAT_0203c894 < 2) {
      if (DAT_0203c894 != 0) goto LAB_0812ef76;
    }
    else if (DAT_0203c894 != 2) {
      if (DAT_0203c894 != 3) goto LAB_0812ef76;
      goto LAB_0812ef1c;
    }
    DAT_0203d0f0 = (ushort)DAT_0203c892;
    DAT_0203d110 = *(undefined2 *)(arg0 + 0x1e);
  }
LAB_0812ef76:
  *(undefined2 *)(arg0 + 0x1e) = 0;
                    /* WARNING: Could not recover jumptable at 0x0812ef7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812EF80 @ 0x0812EF80

void sub_0812EF80(void)

{
  sub_081269B0(3);
  return;
}


// sub_0812EF8C @ 0x0812EF8C

void sub_0812EF8C(int arg0)

{
  dword arg1;
  
  arg1 = 0xffff;
  if (arg0 != 0) {
    arg1 = (dword)*(ushort *)(arg0 + 2);
  }
  DAT_0203c894 = *(char *)(DAT_0203c248 + 0x24) != '\0';
  sub_080AD0FC(0x877a774,arg1);
  return;
}


// sub_0812EFD8 @ 0x0812EFD8

void sub_0812EFD8(void)

{
  if ((DAT_0203db56 != 0) && (DAT_0203db54 = DAT_0203db54 + -1, DAT_0203db54 == 0)) {
    DAT_0203db54 = 0x1e;
    DAT_0203db52 = DAT_0203db52 ^ 1;
  }
  return;
}


// sub_0812F010 @ 0x0812F010

void sub_0812F010(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_03006844 == 0) {
    if (DAT_03006940 == 0) {
      DAT_03006848 = DAT_03006844;
    }
    else {
      DAT_03006848 = 1;
    }
    if (*(short *)(((short)DAT_03006940 + 4) * 2 + 0x203db88) != -1) {
      DAT_03006680 = 1;
      goto LAB_0812f16c;
    }
  }
  else if ((DAT_03006844 == 1) || (DAT_03006844 == 4)) {
    if (DAT_03006940 == 0) {
      DAT_03006848 = DAT_03006940;
    }
    else {
      DAT_03006848 = 1;
    }
    if (*(short *)(((short)DAT_03006940 + 3) * 2 + 0x203db88) != -1) {
      DAT_03006680 = 1;
      goto LAB_0812f16c;
    }
  }
  else if (DAT_03006844 == 2) {
    DAT_03006848 = (ushort)(1 < (short)DAT_03006940);
    if (((short)DAT_03006940 + 8 < 0x10) &&
       (*(short *)(((short)DAT_03006940 + 8) * 2 + 0x203db88) != -1)) {
      DAT_03006680 = 1;
      goto LAB_0812f16c;
    }
  }
  else {
    DAT_03006848 = (ushort)(1 < (short)DAT_03006940);
    if (((short)DAT_03006940 + 6 < 0x10) &&
       (*(short *)(((short)DAT_03006940 + 6) * 2 + 0x203db88) != -1)) {
      DAT_03006680 = 1;
      goto LAB_0812f16c;
    }
  }
  DAT_03006680 = 0;
LAB_0812f16c:
                    /* WARNING: Could not recover jumptable at 0x0812f170. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812F178 @ 0x0812F178

void sub_0812F178(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0300696c = 0;
  return;
}


// sub_0812F188 @ 0x0812F188

uint sub_0812F188(uint arg0)

{
  return (uint)*(ushort *)((arg0 & 0xffff) * 2 + 0x878fc6a);
}


// sub_0812F198 @ 0x0812F198

void sub_0812F198(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (DAT_0203db3e != 0) {
    do {
      *(undefined2 *)(uVar1 * 2 + 0x3006870) = *(undefined2 *)(uVar1 * 8 + 0x203d800);
      uVar1 = uVar1 + 1 & 0xffff;
      if (DAT_0203db3e <= uVar1) break;
    } while (uVar1 < 0x10);
  }
  *(undefined2 *)(uVar1 * 2 + 0x3006870) = 0x301;
  return;
}


// sub_0812F1E4 @ 0x0812F1E4

void sub_0812F1E4(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  sVar1 = DAT_03006870;
  while( true ) {
    if (sVar1 == 0x301) {
      return;
    }
    iVar2 = (DAT_0203db3e & 0x3fff) * 4;
    *(short *)((DAT_0203db3e & 0x3fff) * 8 + 0x203d800) = sVar1;
    *(short *)((iVar2 + 1) * 2 + 0x203d800) = DAT_0203db38 * 0xd + 0x11;
    *(short *)((iVar2 + 2) * 2 + 0x203d800) = DAT_0203db3a * 0xd + DAT_03006614;
    *(undefined2 *)((iVar2 + 3) * 2 + 0x203d800) = 0;
    if (DAT_0203db3e < 0x3f) {
      DAT_0203db3e = DAT_0203db3e + 1;
    }
    DAT_0203db38 = DAT_0203db38 + 1;
    uVar3 = uVar3 + 1 & 0xffff;
    if (0xf < uVar3) break;
    sVar1 = *(short *)(uVar3 * 2 + 0x3006870);
  }
  return;
}


// sub_0812F2B4 @ 0x0812F2B4

void sub_0812F2B4(uint arg0)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined2 uVar12;
  uint uVar13;
  code *UNRECOVERED_JUMPTABLE;
  uint local_3c;
  uint local_30;
  
  local_3c = 0;
  local_30 = 0;
  uVar5 = sub_080C3100();
  uVar3 = DAT_03006950;
  DAT_030068b8 = 10;
  uVar10 = (uint)DAT_03006940;
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  if (((DAT_03006844 == 1) || (DAT_03006844 == 3)) || (DAT_03006844 == 4)) {
    sub_0812F1E4();
  }
  uVar13 = 0;
  iVar9 = uVar10 * 2;
  if (*(short *)(iVar9 + 0x203db88) != -1) {
    iVar11 = (arg0 & 0xffff) * 0x20;
    while (*(short *)(local_3c * 2 + iVar11 + 0x878fba4) != -1) {
      uVar6 = local_3c + 1 & 0xffff;
      sVar4 = *(short *)(local_3c * 2 + iVar11 + 0x878fba4);
      local_3c = uVar6 + 1 & 0xffff;
      uVar1 = *(undefined2 *)(uVar6 * 2 + iVar11 + 0x878fba4);
      if (DAT_030069cc == 0) {
        if (DAT_03006670 == 1) {
          DAT_03006950 = (short *)0x8036156;
        }
        else {
          DAT_03006950 = (short *)0x803631e;
        }
      }
      else {
        DAT_03006950 = (short *)0x8036666;
      }
      DAT_03006950 = *(short **)((*(ushort *)(iVar9 + 0x203db88) & 0x7fff) * 4 + (int)DAT_03006950);
      uVar12 = 0;
      if ((DAT_03006844 == 4) &&
         (local_30 = sub_0812F188(*(ushort *)(iVar9 + 0x203db88) - 0x9d & 0xffff), uVar5 < local_30)
         ) {
        uVar12 = 4;
      }
      sVar2 = *DAT_03006950;
      uVar6 = 1;
      while (sVar2 != 0x301) {
        uVar7 = DAT_0203db3e & 0x3fff;
        uVar8 = uVar7 << 2 | 1;
        *(short *)(uVar7 * 8 + 0x203d800) = sVar2;
        uVar7 = uVar8 + 1;
        *(short *)(uVar8 * 2 + 0x203d800) = sVar4;
        *(undefined2 *)((uVar7 & 0xffff) * 2 + 0x203d800) = uVar1;
        *(undefined2 *)((uVar7 * 0x10000 + 0x10000 >> 0xf) + 0x203d800) = uVar12;
        uVar7 = DAT_0203db3e + 1;
        DAT_0203db3e = (ushort)uVar7;
        if (0x3f < (uVar7 & 0xffff)) {
          DAT_0203db3e = 0x3f;
        }
        sVar4 = sVar4 + 0xd;
        sVar2 = DAT_03006950[uVar6];
        uVar6 = uVar6 + 1 & 0xffff;
      }
      if ((DAT_03006844 == 4) && (iVar9 = (int)(uVar13 * 0x10000) >> 0x10, iVar9 < 3)) {
        *(undefined2 *)(iVar9 * 0x10 + 0x3006620) = 1;
        (&DAT_03006624)[iVar9 * 4] = local_30;
        (&DAT_03006628)[iVar9 * 8] = 0x80;
        (&DAT_0300662a)[iVar9 * 8] = *(undefined2 *)(iVar9 * 2 + 0x878fc64);
        (&DAT_0300662c)[iVar9 * 8] = uVar12;
      }
      uVar10 = uVar10 + 1 & 0xffff;
      uVar6 = uVar13 * 0x10000 + 0x10000;
      uVar13 = uVar6 >> 0x10;
      if ((7 < (int)uVar6 >> 0x10) || (iVar9 = uVar10 * 2, *(short *)(iVar9 + 0x203db88) == -1))
      break;
    }
  }
  DAT_03006950 = (short *)uVar3;
                    /* WARNING: Could not recover jumptable at 0x0812f520. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812F54C @ 0x0812F54C

void sub_0812F54C(int arg0)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  DAT_0300689c = *(undefined2 *)((short)DAT_0300696c * 4 + (short)DAT_03006844 * 0x20 + 0x878fba4);
  DAT_0300695c = *(undefined2 *)
                  (((short)DAT_0300696c * 2 + 1) * 2 + (short)DAT_03006844 * 0x20 + 0x878fba4);
  if ((ushort)(DAT_03006844 - 2) < 2) {
    DAT_030066a0 = 10;
  }
  else if (DAT_03006844 == 4) {
    DAT_030066a0 = 0x14;
  }
  else {
    DAT_030066a0 = 0x13;
  }
  DAT_03006958 = 1;
  if ((DAT_03003964 & 0x200) == 0) {
    if ((DAT_03003964 & 0x100) != 0) {
      if (DAT_03006844 == 0) {
        if ((short)DAT_03006604 < 4) goto FUN_08130146;
        if (DAT_0300696c != 3) {
          DAT_0300696c = 3;
          uVar1 = DAT_0300696c;
          goto FUN_0813013a;
        }
        if ((short)DAT_03006940 + 3 == (int)(short)DAT_03006604) goto FUN_08130146;
        if ((short)DAT_03006940 + 3 < (short)DAT_03006604 + -3) {
          DAT_03006940 = DAT_03006940 + 4;
        }
        else {
          DAT_03006940 = DAT_03006604 - 3;
        }
      }
      else if ((DAT_03006844 == 4) || (DAT_03006844 == 1)) {
        if ((short)DAT_03006604 < 3) goto FUN_08130146;
        if (DAT_0300696c != 2) {
          DAT_0300696c = 2;
          uVar1 = DAT_0300696c;
          goto FUN_0813013a;
        }
        if ((short)DAT_03006940 + 2 == (int)(short)DAT_03006604) goto FUN_08130146;
        if ((short)DAT_03006940 + 2 < (short)DAT_03006604 + -2) {
          DAT_03006940 = DAT_03006940 + 3;
        }
        else {
          DAT_03006940 = DAT_03006604 - 2;
        }
      }
      else if (DAT_03006844 == 2) {
        if ((short)DAT_03006604 < 8) goto FUN_08130146;
        if (DAT_0300696c == 7) {
          uVar4 = 2;
          do {
            if (*(short *)(((short)DAT_03006940 + 7 + uVar4) * 2 + 0x203db88) == -1) {
              if ((uVar4 == 2) && (*(short *)(((short)DAT_03006940 + 8) * 2 + 0x203db88) != -1)) {
                DAT_0300696c = 6;
                DAT_03006940 = DAT_03006940 + 2;
                goto FUN_08130136;
              }
              uVar4 = uVar4 - 2 & 0xffff;
              break;
            }
            uVar4 = uVar4 + 2 & 0xffff;
          } while (uVar4 < 8);
          if (uVar4 == 0) goto FUN_08130146;
          DAT_03006940 = (short)uVar4 + DAT_03006940;
        }
        else {
          if (DAT_0300696c != 6) {
            if (((DAT_0300696c == 0) || (DAT_0300696c == 2)) || (DAT_0300696c == 4)) {
              if (*(short *)(((short)DAT_03006940 + 6) * 2 + 0x203db88) == -1) {
                if ((*(short *)(((short)DAT_03006940 + 4) * 2 + 0x203db88) == -1) ||
                   (3 < (short)DAT_0300696c)) {
                  if ((*(short *)(((short)DAT_03006940 + 2) * 2 + 0x203db88) == -1) ||
                     (1 < (short)DAT_0300696c)) goto FUN_08130146;
                  DAT_0300696c = 2;
                  uVar1 = DAT_0300696c;
                }
                else {
                  DAT_0300696c = 4;
                  uVar1 = DAT_0300696c;
                }
              }
              else {
                DAT_0300696c = 6;
                uVar1 = DAT_0300696c;
              }
            }
            else if (*(short *)(((short)DAT_03006940 + 7) * 2 + 0x203db88) == -1) {
              if ((*(short *)(((short)DAT_03006940 + 5) * 2 + 0x203db88) == -1) ||
                 (4 < (short)DAT_0300696c)) {
                if ((*(short *)(((short)DAT_03006940 + 3) * 2 + 0x203db88) == -1) ||
                   (2 < (short)DAT_0300696c)) {
                  if (*(short *)(((int)(short)DAT_03006940 + (int)(short)DAT_0300696c + 1) * 2 +
                                0x203db88) == -1) goto FUN_08130146;
                  uVar1 = DAT_0300696c + 1;
                }
                else {
                  DAT_0300696c = 3;
                  uVar1 = DAT_0300696c;
                }
              }
              else {
                DAT_0300696c = 5;
                uVar1 = DAT_0300696c;
              }
            }
            else {
              DAT_0300696c = 7;
              uVar1 = DAT_0300696c;
            }
            goto FUN_0813013a;
          }
          uVar4 = 2;
          if (*(short *)(((short)DAT_03006940 + 8) * 2 + 0x203db88) == -1) goto FUN_08130146;
          do {
            uVar4 = uVar4 + 2 & 0xffff;
            if (7 < uVar4) goto LAB_0812f932;
          } while (*(short *)(((short)DAT_03006940 + 6 + uVar4) * 2 + 0x203db88) != -1);
          uVar4 = uVar4 - 2 & 0xffff;
LAB_0812f932:
          if (uVar4 == 0) goto FUN_08130146;
          DAT_03006940 = (short)uVar4 + DAT_03006940;
        }
      }
      else {
        if ((DAT_03006844 != 3) || ((short)DAT_03006604 < 6)) goto FUN_08130146;
        if (DAT_0300696c == 5) {
          uVar4 = 2;
          do {
            if (*(short *)(((short)DAT_03006940 + 5 + uVar4) * 2 + 0x203db88) == -1) {
              if ((uVar4 == 2) && (*(short *)(((short)DAT_03006940 + 6) * 2 + 0x203db88) != -1)) {
                DAT_0300696c = 4;
                DAT_03006940 = DAT_03006940 + 2;
                goto FUN_08130136;
              }
              uVar4 = uVar4 - 2 & 0xffff;
              break;
            }
            uVar4 = uVar4 + 2 & 0xffff;
          } while (uVar4 < 8);
          if (uVar4 == 8) {
            uVar4 = 6;
          }
          if (uVar4 == 0) goto FUN_08130146;
          DAT_03006940 = (short)uVar4 + DAT_03006940;
        }
        else {
          if (DAT_0300696c != 4) {
            if ((DAT_0300696c == 0) || (DAT_0300696c == 2)) {
              if (*(short *)(((short)DAT_03006940 + 4) * 2 + 0x203db88) == -1) {
                if ((*(short *)(((short)DAT_03006940 + 2) * 2 + 0x203db88) == -1) ||
                   (1 < (short)DAT_0300696c)) goto FUN_08130146;
                DAT_0300696c = 2;
                uVar1 = DAT_0300696c;
              }
              else {
                DAT_0300696c = 4;
                uVar1 = DAT_0300696c;
              }
            }
            else if (*(short *)(((short)DAT_03006940 + 5) * 2 + 0x203db88) == -1) {
              if ((*(short *)(((short)DAT_03006940 + 3) * 2 + 0x203db88) == -1) ||
                 (2 < (short)DAT_0300696c)) {
                if (*(short *)(((int)(short)DAT_03006940 + (int)(short)DAT_0300696c + 1) * 2 +
                              0x203db88) == -1) goto FUN_08130146;
                uVar1 = DAT_0300696c + 1;
              }
              else {
                DAT_0300696c = DAT_03006844;
                uVar1 = DAT_0300696c;
              }
            }
            else {
              DAT_0300696c = 5;
              uVar1 = DAT_0300696c;
            }
            goto FUN_0813013a;
          }
          uVar4 = 2;
          if (*(short *)(((short)DAT_03006940 + 6) * 2 + 0x203db88) == -1) {
            uVar4 = 0;
          }
          else {
            do {
              uVar4 = uVar4 + 2 & 0xffff;
              if (7 < uVar4) goto LAB_0812fb56;
            } while (*(short *)(((short)DAT_03006940 + 4 + uVar4) * 2 + 0x203db88) != -1);
            uVar4 = uVar4 - 2 & 0xffff;
          }
LAB_0812fb56:
          if (uVar4 == 8) {
            uVar4 = 6;
          }
          if (uVar4 == 0) goto FUN_08130146;
          DAT_03006940 = (short)uVar4 + DAT_03006940;
        }
      }
      goto FUN_08130136;
    }
    if ((DAT_03003964 & 0x40) == 0) {
      if ((DAT_03003964 & 0x80) == 0) {
        if ((DAT_03003964 & 0x20) == 0) {
          if ((DAT_03003964 & 0x10) == 0) {
            if ((DAT_030031c4 & 1) == 0) {
              if (((DAT_030031c4 & 2) != 0) && (DAT_03006670 == 0)) {
                *(undefined2 *)(arg0 + 0x1c) = 1;
                sub_080C51D4(0x66);
                if (DAT_0203db5a == 0x18) {
                  DAT_0203db5a = 0x37;
                }
                else {
                  DAT_0203db5a = 0x1c;
                }
              }
            }
            else {
              *(undefined2 *)(arg0 + 0x1c) = 1;
              sub_080C51D4(0x65);
              DAT_030065e0 = *(undefined2 *)
                              (((int)(short)DAT_03006940 + (int)(short)DAT_0300696c) * 2 + 0x203db88
                              );
              if (DAT_0203db5a == 0x18) {
                DAT_0203db5a = 0x19;
              }
              else {
                DAT_0203db5a = 0xe;
              }
            }
            goto FUN_08130146;
          }
          if (1 < (ushort)(DAT_03006844 - 2)) goto FUN_08130146;
          if ((((DAT_0300696c == 0) || (DAT_0300696c == 2)) || (DAT_0300696c == 4)) ||
             (DAT_0300696c == 6)) {
            if ((int)(short)DAT_03006604 <= (int)(short)DAT_03006940 + (int)(short)DAT_0300696c)
            goto FUN_08130146;
            uVar1 = DAT_0300696c + 1;
          }
          else {
            uVar1 = DAT_0300696c - 1;
          }
        }
        else {
          if (1 < (ushort)(DAT_03006844 - 2)) goto FUN_08130146;
          if (((DAT_0300696c == 1) || (DAT_0300696c == 3)) ||
             ((DAT_0300696c == 5 || (DAT_0300696c == 7)))) {
            uVar1 = DAT_0300696c - 1;
          }
          else {
            if ((int)(short)DAT_03006604 <= (int)(short)DAT_03006940 + (int)(short)DAT_0300696c)
            goto FUN_08130146;
            uVar1 = DAT_0300696c + 1;
          }
        }
      }
      else if (DAT_03006844 == 0) {
        if ((short)DAT_03006604 < 3) {
          if (DAT_0300696c == DAT_03006604) {
            DAT_0300696c = DAT_03006844;
            uVar1 = DAT_0300696c;
          }
          else {
            uVar1 = DAT_0300696c + 1;
          }
        }
        else {
          if (DAT_0300696c == 3) {
            if (*(short *)(((short)DAT_03006940 + 4) * 2 + 0x203db88) == -1) {
              if (DAT_03006604 != 3) goto FUN_08130146;
              DAT_0300696c = DAT_03006844;
            }
            else {
              DAT_03006940 = DAT_03006940 + 1;
            }
            goto FUN_08130136;
          }
          uVar1 = DAT_0300696c + 1;
        }
      }
      else if ((DAT_03006844 == 1) || (DAT_03006844 == 4)) {
        uVar1 = DAT_03003964 & 0x40;
        if ((short)DAT_03006604 < 2) {
          if (DAT_0300696c == DAT_03006604) {
            if (DAT_03006844 != 1) goto FUN_08130146;
          }
          else {
            uVar1 = DAT_0300696c + 1;
          }
        }
        else if (DAT_0300696c == 2) {
          if (*(short *)(((short)DAT_03006940 + 3) * 2 + 0x203db88) != -1) {
            DAT_03006940 = DAT_03006940 + 1;
            goto FUN_08130136;
          }
          if (((DAT_03006844 != 1) && (DAT_03006844 != 4)) || (DAT_03006604 != 2))
          goto FUN_08130146;
        }
        else {
          uVar1 = DAT_0300696c + 1;
        }
      }
      else if (DAT_03006844 == 2) {
        if ((short)DAT_03006604 < 7) {
          if (*(short *)(((int)(short)DAT_03006940 + (int)(short)DAT_0300696c + 2) * 2 + 0x203db88)
              == -1) goto FUN_08130146;
          uVar1 = DAT_0300696c + 2;
        }
        else {
          iVar3 = (int)(short)DAT_0300696c;
          if (5 < iVar3) {
            iVar2 = (short)DAT_03006940 + iVar3;
            if (0xf < iVar2) goto FUN_08130146;
            if (*(short *)((iVar2 + 2) * 2 + 0x203db88) == -1) {
              if ((iVar3 != 7) || (*(short *)((iVar2 + 1) * 2 + 0x203db88) == -1))
              goto FUN_08130146;
              DAT_0300696c = DAT_0300696c - 1;
              DAT_03006940 = DAT_03006940 + 2;
            }
            else {
              DAT_03006940 = DAT_03006940 + 2;
            }
            goto FUN_08130136;
          }
          if (*(short *)(((int)(short)DAT_03006940 + (int)(short)DAT_0300696c + 2) * 2 + 0x203db88)
              == -1) {
            if ((iVar3 != 7) ||
               (*(short *)(((int)(short)DAT_03006940 + (int)(short)DAT_0300696c + 1) * 2 + 0x203db88
                          ) == -1)) goto FUN_08130146;
            uVar1 = DAT_0300696c + 1;
          }
          else {
            uVar1 = DAT_0300696c + 2;
          }
        }
      }
      else {
        if (DAT_03006844 != 3) goto FUN_08130146;
        if ((short)DAT_03006604 < 5) {
          if (*(short *)(((int)(short)DAT_03006940 + (int)(short)DAT_0300696c + 2) * 2 + 0x203db88)
              == -1) goto FUN_08130146;
          uVar1 = DAT_0300696c + 2;
        }
        else {
          iVar3 = (int)(short)DAT_0300696c;
          if (3 < iVar3) {
            iVar2 = (short)DAT_03006940 + iVar3;
            if (0xf < iVar2) goto FUN_08130146;
            if (*(short *)((iVar2 + 2) * 2 + 0x203db88) == -1) {
              if ((iVar3 != 5) || (*(short *)((iVar2 + 1) * 2 + 0x203db88) == -1))
              goto FUN_08130146;
              DAT_0300696c = DAT_0300696c - 1;
              DAT_03006940 = DAT_03006940 + 2;
            }
            else {
              DAT_03006940 = DAT_03006940 + 2;
            }
            goto FUN_08130136;
          }
          if (*(short *)(((int)(short)DAT_03006940 + (int)(short)DAT_0300696c + 2) * 2 + 0x203db88)
              == -1) {
            if ((iVar3 != 5) ||
               (*(short *)(((int)(short)DAT_03006940 + (int)(short)DAT_0300696c + 1) * 2 + 0x203db88
                          ) == -1)) goto FUN_08130146;
            uVar1 = DAT_0300696c + 1;
          }
          else {
            uVar1 = DAT_0300696c + 2;
          }
        }
      }
    }
    else if ((DAT_03006844 < 2) || (DAT_03006844 == 4)) {
      if (DAT_0300696c == 0) {
        if (DAT_03006940 == 0) {
          if (DAT_03006844 == 0) {
            if (3 < (short)DAT_03006604) goto FUN_08130146;
            DAT_0300696c = DAT_03006604;
          }
          else {
            if (((DAT_03006844 != 1) && (DAT_03006844 != 4)) || (2 < (short)DAT_03006604))
            goto FUN_08130146;
            DAT_0300696c = DAT_03006604;
          }
        }
        else {
          DAT_03006940 = DAT_03006940 - 1;
        }
        goto FUN_08130136;
      }
      uVar1 = DAT_0300696c - 1;
    }
    else if (DAT_0300696c < 2) {
      if ((short)DAT_03006940 < 2) goto FUN_08130146;
      DAT_03006940 = DAT_03006940 - 2;
FUN_08130136:
      sub_0812F2B4((uint)DAT_03006844);
      uVar1 = DAT_0300696c;
    }
    else {
      uVar1 = DAT_0300696c - 2;
    }
  }
  else if (DAT_03006844 == 0) {
    if ((short)DAT_03006604 < 4) goto FUN_08130146;
    if (DAT_0300696c == 0) {
      if ((short)DAT_03006940 == 0) goto FUN_08130146;
      if ((short)DAT_03006940 + -4 < 0) {
        DAT_03006940 = DAT_03006844;
      }
      else {
        DAT_03006940 = DAT_03006940 - 4;
      }
      goto FUN_08130136;
    }
    DAT_0300696c = DAT_03006844;
    uVar1 = DAT_0300696c;
  }
  else if ((DAT_03006844 == 4) || (DAT_03006844 == 1)) {
    if ((short)DAT_03006604 < 3) goto FUN_08130146;
    if (DAT_0300696c == 0) {
      if ((short)DAT_03006940 == 0) goto FUN_08130146;
      if ((short)DAT_03006940 + -3 < 0) {
        DAT_03006940 = DAT_0300696c;
      }
      else {
        DAT_03006940 = DAT_03006940 - 3;
      }
      goto FUN_08130136;
    }
    DAT_0300696c = 0;
    uVar1 = DAT_0300696c;
  }
  else if (DAT_03006844 == 2) {
    if ((short)DAT_03006604 < 8) goto FUN_08130146;
    if (DAT_0300696c < 2) {
      if ((short)DAT_03006940 == 0) goto FUN_08130146;
      if ((short)DAT_03006940 + -6 < 0) {
        DAT_03006940 = 0;
      }
      else {
        DAT_03006940 = DAT_03006940 - 6;
      }
      goto FUN_08130136;
    }
    if (((DAT_0300696c == 2) || (DAT_0300696c == 4)) || (DAT_0300696c == 6)) {
      DAT_0300696c = 0;
      uVar1 = DAT_0300696c;
    }
    else {
      DAT_0300696c = 1;
      uVar1 = DAT_0300696c;
    }
  }
  else {
    if ((DAT_03006844 != 3) || ((short)DAT_03006604 < 6)) goto FUN_08130146;
    if (DAT_0300696c < 2) {
      if ((short)DAT_03006940 == 0) goto FUN_08130146;
      if ((short)DAT_03006940 + -6 < 0) {
        DAT_03006940 = 0;
      }
      else {
        DAT_03006940 = DAT_03006940 - 6;
      }
      goto FUN_08130136;
    }
    if ((DAT_0300696c == 2) || (DAT_0300696c == 4)) {
      DAT_0300696c = 0;
      uVar1 = DAT_0300696c;
    }
    else {
      DAT_0300696c = 1;
      uVar1 = DAT_0300696c;
    }
  }
FUN_0813013a:
  DAT_0300696c = uVar1;
  sub_080C51D4(100);
FUN_08130146:
  sub_0812F010();
                    /* WARNING: Could not recover jumptable at 0x08130154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_08130114 @ 0x08130114

void FUN_08130114(void)

{
  short *in_r3;
  short *unaff_r7;
  ushort *in_r12;
  code *UNRECOVERED_JUMPTABLE;
  
  *in_r3 = *in_r3 + -1;
  *unaff_r7 = *unaff_r7 + 2;
  sub_0812F2B4((uint)*in_r12);
  sub_080C51D4(100);
  sub_0812F010();
                    /* WARNING: Could not recover jumptable at 0x08130154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_08130132 @ 0x08130132

void FUN_08130132(void)

{
  ushort *in_r12;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_0812F2B4((uint)*in_r12);
  sub_080C51D4(100);
  sub_0812F010();
                    /* WARNING: Could not recover jumptable at 0x08130154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_08130136 @ 0x08130136

void FUN_08130136(undefined4 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  sub_0812F2B4(param_1);
  sub_080C51D4(100);
  sub_0812F010();
                    /* WARNING: Could not recover jumptable at 0x08130154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_0813013a @ 0x0813013A

void FUN_0813013a(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080C51D4(100);
  sub_0812F010();
                    /* WARNING: Could not recover jumptable at 0x08130154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_08130146 @ 0x08130146

void FUN_08130146(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  sub_0812F010();
                    /* WARNING: Could not recover jumptable at 0x08130154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08130158 @ 0x08130158

void sub_08130158(void)

{
  DAT_03006958 = 0;
  DAT_03006848 = 0;
  DAT_03006680 = 0;
  DAT_03006620 = 0;
  DAT_03006630 = 0;
  DAT_03006640 = 0;
  return;
}


// sub_08130184 @ 0x08130184

void sub_08130184(int arg0)

{
  int iVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0300696c = 0;
  DAT_03006688 = 0;
  DAT_03006940 = 0;
  iVar1 = sub_080C09B0(0);
  if (iVar1 != 0) {
    DAT_03006688 = DAT_03006688 + 1;
  }
  iVar1 = sub_080C09B0(1);
  if (iVar1 != 0) {
    DAT_03006688 = DAT_03006688 + 1;
  }
  iVar1 = sub_080C09B0(2);
  if (iVar1 != 0) {
    DAT_03006688 = DAT_03006688 + 1;
  }
  return;
}


// sub_081301D8 @ 0x081301D8

void sub_081301D8(int arg0)

{
  ushort uVar1;
  
  DAT_0300689c = *(undefined2 *)(DAT_0300696c * 4 + 0x878fcc4);
  DAT_0300695c = *(undefined2 *)((DAT_0300696c * 2 + 1) * 2 + 0x878fcc4);
  DAT_030066a0 = 0x10;
  DAT_03006958 = 1;
  if ((DAT_03003964 & 0x40) == 0) {
    if ((DAT_03003964 & 0x80) == 0) {
      uVar1 = DAT_030031c4 & 1;
      if ((DAT_030031c4 & 1) == 0) {
        if ((DAT_030031c4 & 2) == 0) {
          DAT_030066a0 = 0x10;
          DAT_03006958 = 1;
          return;
        }
        *(undefined2 *)(arg0 + 0x1c) = 1;
        DAT_0203db5a = 0x20;
        DAT_0300699c = uVar1;
        sub_080C51D4(0x66);
        return;
      }
      if ((*(ushort *)(DAT_0300696c * 2 + 0x30069d8) & 0xf0) != 0) {
        sub_080C51D4(0x68);
        return;
      }
      *(undefined2 *)(arg0 + 0x1c) = 1;
      DAT_0203db5a = 0x21;
      DAT_03006850 = *(undefined2 *)(DAT_0300696c * 2 + 0x30069d8);
      DAT_03006898 = DAT_03006850;
      sub_080C51D4(0x65);
      return;
    }
    if ((int)DAT_0300696c == DAT_03006688 + -1) {
      DAT_030066a0 = 0x10;
      DAT_03006958 = 1;
      return;
    }
    DAT_0300696c = DAT_0300696c + 1;
  }
  else {
    if (DAT_0300696c == 0) {
      DAT_030066a0 = 0x10;
      DAT_03006958 = 1;
      return;
    }
    DAT_0300696c = DAT_0300696c + -1;
  }
  sub_080C51D4(100);
  return;
}


// sub_08130300 @ 0x08130300

void sub_08130300(void)

{
  DAT_03006958 = 0;
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  DAT_030069d0 = 0;
  return;
}


// sub_08130344 @ 0x08130344

void sub_08130344(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0300696c = 0;
  DAT_03006688 = 2;
  DAT_03006940 = 0;
  return;
}


// sub_08130364 @ 0x08130364

uint sub_08130364(int arg0,undefined4 arg1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_080F2F64(arg0 * 0x10000 + 0x80000000U >> 0x10);
  switch((undefined2)arg1) {
  case 0x9d:
  case 0xa3:
    uVar2 = (uint)*(char *)(iVar1 + 0x38);
    break;
  case 0x9e:
  case 0xa4:
    uVar2 = (uint)*(char *)(iVar1 + 0x39);
    break;
  case 0x9f:
  case 0xa5:
    uVar2 = (uint)*(char *)(iVar1 + 0x3a);
    break;
  case 0xa0:
    uVar2 = (uint)*(char *)(iVar1 + 0x3b);
    break;
  case 0xa1:
    uVar2 = (uint)*(char *)(iVar1 + 0x3c);
    break;
  case 0xa2:
    uVar2 = (uint)*(char *)(iVar1 + 0x3d);
    break;
  default:
    return 0;
  }
  return uVar2 & 0xffff;
}


// sub_081303E8 @ 0x081303E8

void sub_081303E8(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  DAT_0300689c = *(undefined2 *)((short)DAT_0300696c * 4 + 0x878fcc4);
  DAT_0300695c = *(undefined2 *)(((short)DAT_0300696c * 2 + 1) * 2 + 0x878fcc4);
  DAT_030066a0 = 0x10;
  DAT_03006958 = 1;
  uVar1 = DAT_03003964 & 0xc0;
  if ((DAT_03003964 & 0xc0) == 0) {
    uVar2 = DAT_030031c4 & 1;
    if ((DAT_030031c4 & 1) == 0) {
      if ((DAT_030031c4 & 2) != 0) {
        *(undefined2 *)(arg0 + 0x1c) = 1;
        DAT_030068e4 = DAT_0203dac8;
        DAT_0203db5a = uVar2;
        sub_080C51D4(0x66);
      }
    }
    else {
      DAT_0203db38 = uVar1;
      DAT_0203db3a = uVar1;
      DAT_0203db3e = uVar1;
      DAT_0203db4a = uVar1;
      Font_ResetGlyphSpriteCache(0x180);
      if (DAT_0300696c == 0) {
        DAT_03006898 = DAT_0300696c;
      }
      else {
        iVar3 = sub_080C09B0(1);
        if (iVar3 == 0) {
          DAT_03006898 = 2;
        }
        else {
          DAT_03006898 = 1;
        }
      }
      *(undefined2 *)(arg0 + 0x1c) = 1;
      DAT_0203db5a = 0;
      uVar4 = sub_08130364((int)(short)DAT_03006898,(uint)DAT_030065e0);
      if ((uVar4 & 0xffff) == 0) {
        sub_080C51D4(0x65);
      }
      else {
        sub_080C51D4(0x68);
        DAT_030068e4 = DAT_0203dacc;
      }
    }
  }
  else {
    DAT_0300696c = (ushort)(DAT_0300696c == 0);
    sub_080C51D4(100);
  }
                    /* WARNING: Could not recover jumptable at 0x08130536. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08130544 @ 0x08130544

void sub_08130544(void)

{
  DAT_03006958 = 0;
  return;
}


// sub_08130550 @ 0x08130550

void sub_08130550(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0300696c = 0;
  DAT_03006940 = 0;
  DAT_030065e4 = 0;
  DAT_030068d4 = 10;
  return;
}


// sub_08130578 @ 0x08130578

void sub_08130578(uint arg0)

{
  uint uVar1;
  int iVar2;
  uint arg0_00;
  
  uVar1 = sub_080C32D4(arg0 & 0xffff);
  iVar2 = sub_08131AB0(0xff,arg0 & 0xffff);
  arg0_00 = (uVar1 & 0xff) + iVar2 & 0xffff;
  uVar1 = __udivsi3(arg0_00,10);
  DAT_0203d868 = *(undefined2 *)((uVar1 & 0xffff) * 2 + 0x878f9b8);
  uVar1 = __umodsi3(arg0_00,10);
  DAT_0203d870 = *(undefined2 *)((uVar1 & 0xffff) * 2 + 0x878f9b8);
  return;
}


// sub_081305D8 @ 0x081305D8

void sub_081305D8(uint arg0)

{
  uint uVar1;
  
  if (DAT_030065e4 == 0) {
    uVar1 = 0;
    do {
      *(undefined2 *)(uVar1 * 8 + 0x203d800) = *(undefined2 *)(uVar1 * 2 + 0x3006820);
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < 0xf);
  }
  else {
    uVar1 = 0;
    do {
      *(undefined2 *)(uVar1 * 2 + 0x3006820) = *(undefined2 *)(uVar1 * 8 + 0x203d800);
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < 0xf);
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
    DAT_0203d860 = 0x3f;
    sub_08130578(arg0 & 0xffff);
  }
  return;
}


// sub_08130694 @ 0x08130694

void sub_08130694(int arg0)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  DAT_0300689c = *(short *)((short)DAT_0300696c * 4 + 0x878fcc4) + 0xe;
  DAT_0300695c = *(undefined2 *)(((short)DAT_0300696c * 2 + 1) * 2 + 0x878fcc4);
  DAT_030066a0 = 0x13;
  DAT_03006958 = 1;
  if (DAT_030068d4 != 0) {
    DAT_030068d4 = DAT_030068d4 + -1;
    goto LAB_08130c1a;
  }
  if ((DAT_030031c4 & 4) != 0) {
    DAT_030065e4 = DAT_030065e4 ^ 1;
    Shop_InitItemList((uint)DAT_03006940,(uint)DAT_030065e4);
    DAT_030068d4 = 1;
    goto LAB_08130c1a;
  }
  uVar5 = (uint)DAT_03003964;
  if ((DAT_03003964 & 0x200) == 0) {
    if ((DAT_03003964 & 0x100) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) == 0) {
          uVar1 = DAT_030031c4 & 1;
          if ((DAT_030031c4 & 1) == 0) {
            if ((DAT_030031c4 & 2) != 0) {
              *(undefined2 *)(arg0 + 0x1c) = 1;
              if (DAT_0203db5a == 0x28) {
                DAT_030068e4 = DAT_0203dacc;
                DAT_0203db5a = uVar1;
              }
              else {
                DAT_0203db5a = 0x24;
              }
              DAT_0300699c = 0;
              DAT_03006930 = 0;
              DAT_03006928 = 0;
              DAT_03006920 = 0;
              DAT_03006660 = 0;
              DAT_03006650 = 0;
              DAT_03006640 = 0;
              DAT_03006630 = 0;
              DAT_03006620 = 0;
              DAT_03006958 = 0;
              sub_080D34F0(DAT_030068a4);
              sub_080C51D4(0x66);
            }
            goto LAB_08130c1a;
          }
          *(undefined2 *)(arg0 + 0x1c) = 1;
          sub_080D34F0(DAT_030068a4);
          uVar2 = (undefined2)(uVar5 & 0x80);
          if (DAT_0203db5a == 0x28) {
            DAT_0203db5a = 0x29;
            DAT_030069a8 = *(ushort *)
                            (((int)(short)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x203bb74);
            iVar7 = sub_080C3100();
            if ((uint)(iVar7 + *(int *)(((int)(short)DAT_0300696c + (int)(short)DAT_03006940) * 4 +
                                       0x203bd74)) < 1000000) {
LAB_08130b82:
              sub_080C51D4(0x65);
              goto LAB_08130c1a;
            }
            DAT_0203dad8 = DAT_0203dad0;
            DAT_0203db5a = 0x23;
          }
          else {
            DAT_0203db5a = 0x23;
            uVar1 = *(ushort *)
                     (((int)(short)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x203bb74);
            arg0_00 = (uint)uVar1;
            uVar3 = sub_080C32D4(arg0_00);
            uVar4 = sub_08131AB0(0xff,arg0_00);
            if ((uVar3 & 0xff) + (uVar4 & 0xffff) < 99) {
              uVar3 = sub_080C4C60(arg0_00);
              uVar4 = sub_080C3100();
              if (uVar3 <= uVar4) {
                DAT_030065fc = 1;
                DAT_0203dad8 = uVar5 & 0x80;
                DAT_030069a8 = uVar1;
                DAT_0203db2c = sub_080C4C60((uint)uVar1);
                DAT_0203db50 = DAT_030069a8;
                DAT_03006620 = uVar2;
                DAT_03006630 = uVar2;
                DAT_03006640 = uVar2;
                DAT_03006650 = uVar2;
                DAT_03006660 = uVar2;
                DAT_0300669c = uVar2;
                DAT_03006920 = uVar2;
                DAT_03006928 = uVar2;
                DAT_03006930 = uVar2;
                DAT_0300699c = uVar2;
                sub_080D34F0(DAT_030068a4);
                DAT_03006958 = uVar2;
                goto LAB_08130b82;
              }
              DAT_0203dad8 = DAT_0203dac8;
            }
            else {
              DAT_0203dad8 = DAT_0203dad0;
            }
          }
          DAT_03006958 = uVar2;
          sub_080C51D4(0x66);
          goto LAB_08130c1a;
        }
        if (DAT_0300696c != 2) {
          if ((2 < DAT_03006688) ||
             (uVar1 = DAT_03003964 & 0x40, (int)(short)DAT_0300696c < DAT_03006688 + -1)) {
            uVar1 = DAT_0300696c + 1;
          }
          DAT_0300696c = uVar1;
          iVar7 = (int)(short)DAT_0300696c;
          iVar8 = (int)(short)DAT_03006940;
LAB_081309e6:
          iVar7 = iVar7 + iVar8;
          goto LAB_081309ec;
        }
        if (DAT_03006688 == 3) {
          puVar6 = (ushort *)((short)DAT_03006940 * 2 + 0x203bb74);
          DAT_0300696c = DAT_03003964 & 0x40;
          goto LAB_08130990;
        }
        if (DAT_03006688 + -1 <= (short)DAT_03006940 + 2) goto LAB_081309fa;
        DAT_03006940 = DAT_03006940 + 1;
      }
      else if (DAT_0300696c == 0) {
        if (DAT_03006940 == 0) {
          if (DAT_03006688 < 4) {
            DAT_0300696c = DAT_03006688 - 1;
            iVar7 = (int)(short)DAT_0300696c;
            iVar8 = 0;
            goto LAB_081309e6;
          }
          goto LAB_081309fa;
        }
        DAT_03006940 = DAT_03006940 - 1;
      }
      else {
        DAT_0300696c = DAT_0300696c - 1;
      }
LAB_0813098a:
      puVar6 = (ushort *)(((int)(short)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x203bb74);
      goto LAB_08130990;
    }
    if (DAT_0300696c == 2) {
      if ((short)DAT_03006940 + 2 < DAT_03006688 + -3) {
        DAT_03006940 = DAT_03006940 + 3;
        goto LAB_0813098a;
      }
      if ((int)(short)DAT_03006940 != DAT_03006688 + -3) {
        DAT_03006940 = DAT_03006688 - 3;
        iVar7 = 2;
        iVar8 = (int)(short)DAT_03006940;
        goto LAB_081309e6;
      }
    }
    else {
      if (DAT_03006688 < 3) {
        DAT_0300696c = DAT_03006688 - 1;
      }
      else {
        DAT_0300696c = 2;
      }
      sub_080C51D4(100);
      sub_080D34A4(DAT_030068a4,1,(uint)DAT_03006898,
                   (uint)*(ushort *)
                          (((int)(short)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x203bb74));
    }
  }
  else {
    if (DAT_0300696c == 0) {
      if (-1 < (short)DAT_03006940 + -3) {
        DAT_03006940 = DAT_03006940 - 3;
        goto LAB_0813098a;
      }
      if (DAT_03006940 != 0) {
        DAT_03006940 = DAT_0300696c;
        iVar7 = 0;
LAB_081309ec:
        sub_080D34A4(DAT_030068a4,1,(uint)DAT_03006898,(uint)*(ushort *)(iVar7 * 2 + 0x203bb74));
        sub_080C51D4(100);
      }
      goto LAB_081309fa;
    }
    puVar6 = (ushort *)((short)DAT_03006940 * 2 + 0x203bb74);
    DAT_0300696c = DAT_030031c4 & 4;
LAB_08130990:
    sub_080D34A4(DAT_030068a4,1,(uint)DAT_03006898,(uint)*puVar6);
    sub_080C51D4(100);
  }
LAB_081309fa:
  Shop_InitItemList((uint)DAT_03006940,(uint)DAT_030065e4);
  DAT_030068d4 = 1;
LAB_08130c1a:
                    /* WARNING: Could not recover jumptable at 0x08130c26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08130C38 @ 0x08130C38

void sub_08130C38(void)

{
  DAT_03006848 = 0;
  DAT_03006680 = 0;
  return;
}


// sub_08130C4C @ 0x08130C4C

void sub_08130C4C(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0300696c = 0;
  DAT_03006940 = 0;
  DAT_030068ac = 0;
  return;
}


// sub_08130C6C @ 0x08130C6C

void sub_08130C6C(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  DAT_03006980 = 0xffff;
  DAT_03006982 = 0xffff;
  DAT_03006984 = 0xffff;
  DAT_03006986 = 0xffff;
  DAT_03006988 = 0xffff;
  if (DAT_030068d8 == 0xff) {
    uVar2 = (uint)DAT_03006940;
    uVar3 = (uint)DAT_0300696c;
    uVar4 = 0;
    do {
      *(undefined2 *)(uVar4 * 2 + 0x3006980) =
           *(undefined2 *)(((uVar2 + uVar3 & 0xffff) * 5 + uVar4) * 2 + 0x878fdec);
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < 5);
  }
  else {
    uVar1 = DAT_03006940 + DAT_030068d8 + -0x120 + DAT_0300696c;
    uVar2 = 0;
    if (2 < uVar1) {
      do {
        uVar2 = uVar2 + 2 & 0xffff;
      } while (*(ushort *)(uVar2 * 2 + 0x878fdcc) <= uVar1);
    }
    DAT_03006980 = *(undefined2 *)((uVar2 + 1) * 2 + 0x878fdcc);
  }
  return;
}


// sub_08130D24 @ 0x08130D24

void sub_08130D24(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = DAT_03006844 & 0xf;
  uVar2 = DAT_03006844 & 0xf;
  uVar3 = DAT_03006844 & 0xf;
  uVar6 = DAT_03006844 & 0xf;
  DAT_0300689c = *(short *)(DAT_0300696c * 4 + uVar6 * 0x20 + 0x878fba4) + 8;
  DAT_0300695c = *(undefined2 *)((DAT_0300696c * 2 + 1) * 2 + uVar6 * 0x20 + 0x878fba4);
  DAT_030066a0 = 0x13;
  DAT_03006958 = 1;
  if (DAT_030068ac != 0) {
    DAT_030068ac = DAT_030068ac + -1;
  }
  if ((DAT_03003964 & 0x200) == 0) {
    if ((DAT_03003964 & 0x100) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) == 0) {
          if ((DAT_030031c4 & 1) == 0) {
            if ((DAT_030031c4 & 2) != 0) {
              *(undefined2 *)(arg0 + 0x1c) = 1;
              DAT_0203db5a = 0x2f;
              sub_080C51D4(0x66);
            }
          }
          else if (DAT_030068ac == 0) {
            uVar6 = sub_080C32D4((uint)*(ushort *)
                                        (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 +
                                        0x203db88));
            if ((uVar6 & 0xff) == 0) {
              if (uVar3 == 0) {
                DAT_030068e4 = DAT_0203dacc;
                *(undefined2 *)(arg0 + 0x1c) = 1;
                DAT_0203db5a = 0x30;
                sub_080C51D4(0x66);
              }
              else {
                sub_080C51D4(0x68);
              }
            }
            else {
              *(undefined2 *)(arg0 + 0x1c) = 1;
              DAT_0203db5a = 0x30;
              DAT_0203db50 = *(undefined2 *)
                              (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x203db88);
              sub_080C51D4(0x65);
            }
          }
          goto LAB_0813134e;
        }
        if (((uVar6 == 1) && (DAT_0300696c == 2)) ||
           (((DAT_03006844 & 0xf) == 0 && (DAT_0300696c == 3)))) {
          if (10 < (int)DAT_0300696c + (int)(short)DAT_03006940) goto LAB_0813134e;
          DAT_030068ac = 3;
          DAT_03006940 = DAT_03006940 + 1;
          sub_08133F14((uint)DAT_03006940);
          if (uVar2 == 0) {
            if ((DAT_03006844 & 0xf0) == 0) {
              sub_080D347C((uint)*(ushort *)
                                  (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x878fdb4),
                           0xffff,0xffff,0xffff);
              puVar5 = (ushort *)(((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x878fdb4);
              goto LAB_0813123e;
            }
            goto LAB_0813125c;
          }
        }
        else {
          DAT_0300696c = DAT_0300696c + 1;
          if ((DAT_03006844 & 0xf) == 0) {
            if ((DAT_03006844 & 0xf0) == 0) {
              sub_080D347C((uint)*(ushort *)
                                  (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x878fdb4),
                           0xffff,0xffff,0xffff);
              iVar4 = (int)DAT_0300696c;
              goto LAB_08131234;
            }
            goto LAB_0813125c;
          }
        }
      }
      else if (DAT_0300696c == 0) {
        if (DAT_03006940 == 0) goto LAB_0813134e;
        DAT_030068ac = 3;
        DAT_03006940 = DAT_03006940 - 1;
        sub_08133F14((uint)DAT_03006940);
        if (uVar1 == 0) {
          if ((DAT_03006844 & 0xf0) == 0) {
            sub_080D347C((uint)*(ushort *)
                                (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x878fdb4),
                         0xffff,0xffff,0xffff);
            puVar5 = (ushort *)(((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x878fdb4);
            goto LAB_0813123e;
          }
          goto LAB_0813125c;
        }
      }
      else {
        DAT_0300696c = DAT_0300696c + -1;
        if ((DAT_03006844 & 0xf) == 0) {
          if ((DAT_03006844 & 0xf0) == 0) {
            sub_080D347C((uint)*(ushort *)
                                (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x878fdb4),
                         0xffff,0xffff,0xffff);
            iVar4 = (int)DAT_0300696c;
            goto LAB_08131234;
          }
          goto LAB_0813125c;
        }
      }
    }
    else if (uVar6 == 1) {
      if (DAT_0300696c == 2) {
        if ((short)DAT_03006940 + 5 < 0xb) {
          DAT_03006940 = DAT_03006940 + 3;
        }
        else {
          iVar4 = (0xb - (DAT_03006940 + 2)) * 0x10000;
          if (iVar4 >> 0x10 == 0) goto LAB_0813134e;
          DAT_03006940 = (short)((uint)iVar4 >> 0x10) + DAT_03006940;
        }
        DAT_030068ac = 3;
        sub_08133F14((uint)DAT_03006940);
      }
      else {
        DAT_0300696c = 2;
      }
    }
    else {
      if (DAT_0300696c == 3) {
        if ((short)DAT_03006940 + 7 < 0xb) {
          DAT_030068ac = DAT_0300696c;
          DAT_03006940 = DAT_03006940 + 4;
          sub_08133F14((uint)DAT_03006940);
          if ((DAT_03006844 & 0xf0) == 0) {
            sub_080D347C((uint)*(ushort *)
                                (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x878fdb4),
                         0xffff,0xffff,0xffff);
            puVar5 = (ushort *)(((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x878fdb4);
LAB_0813123e:
            sub_080D34A4(DAT_030068a4,3,0,(uint)*puVar5);
            goto LAB_08131280;
          }
        }
        else {
          iVar4 = (0xb - (DAT_03006940 + 3)) * 0x10000;
          if (iVar4 >> 0x10 == 0) goto LAB_0813134e;
          DAT_030068ac = DAT_0300696c;
          DAT_03006940 = (short)((uint)iVar4 >> 0x10) + DAT_03006940;
          sub_08133F14((uint)DAT_03006940);
          if ((DAT_03006844 & 0xf0) == 0) {
            sub_080D347C((uint)*(ushort *)
                                (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x878fdb4),
                         0xffff,0xffff,0xffff);
            puVar5 = (ushort *)(((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x878fdb4);
            goto LAB_0813123e;
          }
        }
      }
      else {
        DAT_0300696c = 3;
        if ((DAT_03006844 & 0xf0) == 0) {
          sub_080D347C((uint)*(ushort *)(((short)DAT_03006940 + 3) * 2 + 0x878fdb4),0xffff,0xffff,
                       0xffff);
          iVar4 = (int)DAT_0300696c;
          goto LAB_08131234;
        }
      }
LAB_0813125c:
      sub_08130C6C();
      sub_080D347C((uint)DAT_03006980,(uint)DAT_03006982,(uint)DAT_03006984,(uint)DAT_03006986);
      sub_080D34A4(DAT_030068a4,4,0,0);
    }
  }
  else if (DAT_0300696c == 0) {
    if (DAT_03006940 == 0) goto LAB_0813134e;
    DAT_030068ac = 3;
    if (uVar6 == 1) {
      if ((short)DAT_03006940 + -3 < 0) {
        DAT_03006940 = 0;
      }
      else {
        DAT_03006940 = DAT_03006940 - 3;
      }
    }
    else {
      if ((short)DAT_03006940 + -4 < 0) {
        DAT_03006940 = 0;
      }
      else {
        DAT_03006940 = DAT_03006940 - 4;
      }
      if ((DAT_03006844 & 0xf0) == 0) {
        sub_080D347C((uint)*(ushort *)((short)DAT_03006940 * 2 + 0x878fdb4),0xffff,0xffff,0xffff);
        sub_080D34A4(DAT_030068a4,3,0,
                     (uint)*(ushort *)
                            (((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 0x878fdb4));
      }
      else {
        sub_08130C6C();
        sub_080D347C((uint)DAT_03006980,(uint)DAT_03006982,(uint)DAT_03006984,(uint)DAT_03006986);
        sub_080D34A4(DAT_030068a4,4,0,0);
      }
    }
    sub_08133F14((uint)DAT_03006940);
  }
  else {
    DAT_0300696c = 0;
    if ((DAT_03006844 & 0xf) == 0) {
      if ((DAT_03006844 & 0xf0) == 0) {
        sub_080D347C((uint)*(ushort *)((short)DAT_03006940 * 2 + 0x878fdb4),0xffff,0xffff,0xffff);
        iVar4 = (int)DAT_0300696c;
LAB_08131234:
        puVar5 = (ushort *)((iVar4 + (short)DAT_03006940) * 2 + 0x878fdb4);
        goto LAB_0813123e;
      }
      goto LAB_0813125c;
    }
  }
LAB_08131280:
  sub_080C51D4(100);
LAB_0813134e:
                    /* WARNING: Could not recover jumptable at 0x0813135c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08131364 @ 0x08131364

void sub_08131364(void)

{
  DAT_03006848 = 0;
  DAT_03006680 = 0;
  DAT_03006660 = 0;
  DAT_03006650 = 0;
  DAT_03006640 = 0;
  DAT_03006630 = 0;
  DAT_03006620 = 0;
  DAT_03006678 = 0;
  DAT_03006958 = 0;
  if (DAT_03006844 != 1) {
    sub_080D34F0(DAT_030068a4);
  }
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  return;
}


// sub_081313E8 @ 0x081313E8

void sub_081313E8(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0300696c = 0;
  DAT_03006940 = 0;
  return;
}


// sub_08131400 @ 0x08131400

void sub_08131400(int arg0)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = sub_081394B4();
  uVar3 = uVar3 & 0xffff;
  DAT_0300689c = *(short *)(DAT_0300696c * 4 + DAT_03006844 * 0x20 + 0x878fba4) + -2;
  DAT_0300695c = *(undefined2 *)((DAT_0300696c * 2 + 1) * 2 + DAT_03006844 * 0x20 + 0x878fba4);
  DAT_030066a0 = 0x17;
  if (DAT_0300696c == 2) {
    DAT_030066a0 = 0x16;
  }
  DAT_03006958 = 1;
  if ((DAT_03003964 & 0x200) == 0) {
    if ((DAT_03003964 & 0x100) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) == 0) {
          uVar1 = DAT_030031c4 & 1;
          if ((DAT_030031c4 & 1) == 0) {
            if ((DAT_030031c4 & 2) != 0) {
              *(undefined2 *)(arg0 + 0x1c) = 1;
              DAT_0203db5a = uVar1;
              sub_080C51D4(0x66);
            }
          }
          else {
            *(undefined2 *)(arg0 + 0x1c) = 1;
            DAT_0203db5a = 0;
            DAT_0203db50 = *(ushort *)
                            ((((int)DAT_0300696c + (int)(short)DAT_03006940) * 2 + 1) * 2 +
                             uVar3 * 0x20 + 0x878fea8);
            uVar3 = (uint)*(ushort *)
                           (&UNK_0878feac +
                           ((int)DAT_0300696c + (int)(short)DAT_03006940) * 4 + uVar3 * 0x20);
            if (uVar3 == 0xffff) {
              uVar3 = 100000;
            }
            uVar4 = sub_080C31F0();
            uVar6 = DAT_0203dac8;
            if (uVar3 <= uVar4) {
              uVar4 = sub_080C32D4((uint)DAT_0203db50);
              uVar5 = sub_08131AB0(0xff,(uint)DAT_0203db50);
              uVar6 = DAT_0203dacc;
              if ((uVar4 & 0xff) + (uVar5 & 0xffff) < 99) {
                sub_080C3328((uint)DAT_0203db50);
                sub_080C31B4(-uVar3);
                DAT_030068e4 = DAT_0203dad0;
                sub_080C51D4(0x65);
                goto LAB_08131684;
              }
            }
            DAT_030068e4 = uVar6;
            sub_080C51D4(0x66);
          }
          goto LAB_08131684;
        }
        if (DAT_0300696c != 2) {
          sVar2 = 1;
          goto LAB_0813157e;
        }
        if ((int)(uint)*(ushort *)(uVar3 * 0x20 + 0x878fea8) <= (short)DAT_03006940 + 2)
        goto LAB_08131684;
        DAT_03006940 = DAT_03006940 + 1;
        CasinoPrize_DrawList((uint)DAT_03006940);
      }
      else if (DAT_0300696c == 0) {
        if (DAT_03006940 == 0) goto LAB_08131684;
        DAT_03006940 = DAT_03006940 - 1;
        CasinoPrize_DrawList((uint)DAT_03006940);
      }
      else {
        sVar2 = -1;
LAB_0813157e:
        DAT_0300696c = DAT_0300696c + sVar2;
      }
    }
    else {
      if (DAT_0300696c != 2) {
        DAT_0300696c = 2;
        goto LAB_08131684;
      }
      uVar3 = *(ushort *)(uVar3 * 0x20 + 0x878fea8) - 2;
      if ((short)DAT_03006940 + 2 < (int)uVar3) {
        uVar3 = DAT_03006940 + 3;
      }
      DAT_03006940 = (ushort)uVar3;
      CasinoPrize_DrawList(uVar3 & 0xffff);
    }
  }
  else if (DAT_0300696c == 0) {
    if ((short)DAT_03006940 + -3 < 0) {
      DAT_03006940 = 0;
    }
    else {
      DAT_03006940 = DAT_03006940 - 3;
    }
    CasinoPrize_DrawList((uint)DAT_03006940);
  }
  else {
    DAT_0300696c = 0;
  }
  sub_080C51D4(100);
LAB_08131684:
                    /* WARNING: Could not recover jumptable at 0x0813168e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08131694 @ 0x08131694

void sub_08131694(void)

{
  DAT_030068ac = 0;
  DAT_03006848 = 0;
  DAT_03006680 = 0;
  DAT_03006660 = 0;
  DAT_03006650 = 0;
  DAT_03006640 = 0;
  DAT_03006630 = 0;
  DAT_03006620 = 0;
  DAT_03006958 = 0;
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  return;
}


// sub_081316FC @ 0x081316FC

void sub_081316FC(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_080C3100();
  iVar1 = DAT_03006694;
  uVar3 = sub_08131AB0(0xff,(uint)DAT_030069a8);
  uVar4 = sub_080C32D4((uint)DAT_030069a8);
  uVar4 = uVar4 & 0xff;
  if (DAT_0203db5a == 0x2a) {
    if (DAT_030068bc != 1) {
      if (((short)DAT_030065fc < 0x5a) && (uVar3 = (uint)(short)DAT_030065fc, uVar3 != uVar4)) {
        uVar4 = sub_080C32D4((uint)DAT_030069a8);
        uVar5 = sub_08131AB0(0xff,(uint)DAT_030069a8);
        if ((int)(uVar3 + 1) <= (int)((uVar4 & 0xff) + (uVar5 & 0xffff))) {
          if (iVar1 * ((short)DAT_030065fc + 1) + uVar2 < 1000000) {
            DAT_03006848 = DAT_0300696c * 2 + 3;
          }
          else {
            DAT_03006848 = 0;
          }
          DAT_03006680 = DAT_0300696c * 2 + 3;
          goto LAB_08131a5c;
        }
      }
      DAT_03006848 = 0;
      DAT_03006680 = DAT_0300696c * 2 + 3;
      goto LAB_08131a5c;
    }
    if (DAT_030065fc == 99) {
      DAT_03006848 = 0;
      DAT_03006680 = DAT_0300696c * 2 + 2;
      goto LAB_08131a6a;
    }
    if (1 < (short)DAT_030065fc) {
      iVar6 = (int)(short)DAT_030065fc;
      uVar3 = sub_080C32D4((uint)DAT_030069a8);
      if (iVar6 < (int)(uVar3 & 0xff)) {
        if (iVar1 * ((short)DAT_030065fc + 1) + uVar2 < 1000000) {
          DAT_03006848 = DAT_0300696c * 2 + 2;
        }
        else {
          DAT_03006848 = 0;
        }
        DAT_03006680 = DAT_0300696c * 2 + 2;
      }
      else {
        DAT_03006848 = 0;
        DAT_03006680 = DAT_0300696c * 2 + 2;
      }
      goto LAB_08131a6a;
    }
    uVar3 = sub_080C32D4((uint)DAT_030069a8);
    if ((uVar3 & 0xff) < 2) {
      DAT_03006848 = 0;
    }
    else if (iVar1 * ((short)DAT_030065fc + 1) + uVar2 < 1000000) {
      DAT_03006848 = DAT_0300696c * 2 + 2;
    }
    else {
      DAT_03006848 = 0;
    }
  }
  else if (DAT_030068bc == 1) {
    if (DAT_030065fc == 99) {
      DAT_03006848 = 0;
      DAT_03006680 = DAT_0300696c * 2 + 2;
    }
    else if ((uVar3 & 0xffff) + uVar4 + (uint)DAT_030065fc < 99) {
      uVar3 = iVar1 * ((short)DAT_030065fc + 1);
      if (uVar3 < uVar2 || uVar3 - uVar2 == 0) {
        DAT_03006680 = DAT_0300696c * 2 + 2;
        DAT_03006848 = DAT_03006680;
      }
      else {
        DAT_03006848 = 0;
        DAT_03006680 = DAT_0300696c * 2 + 2;
      }
    }
    else {
      DAT_03006848 = 0;
      DAT_03006680 = DAT_0300696c * 2 + 2;
    }
    if (1 < (short)DAT_030065fc) goto LAB_08131a6a;
  }
  else {
    if (DAT_030065fc == 99) {
      DAT_03006848 = 0;
      DAT_03006680 = DAT_0300696c * 2 + 3;
    }
    else {
      uVar5 = iVar1 * ((short)DAT_030065fc + 1);
      if (uVar5 < uVar2 || uVar5 - uVar2 == 0) {
        if ((uVar3 & 0xffff) + uVar4 + (uint)DAT_030065fc < 99) {
          DAT_03006680 = DAT_0300696c * 2 + 3;
          DAT_03006848 = DAT_03006680;
        }
        else {
          DAT_03006848 = 0;
          DAT_03006680 = DAT_0300696c * 2 + 3;
        }
      }
      else {
        DAT_03006848 = 0;
        DAT_03006680 = DAT_0300696c * 2 + 3;
      }
    }
LAB_08131a5c:
    if (DAT_030065fc != 1) goto LAB_08131a6a;
  }
  DAT_03006680 = 0;
LAB_08131a6a:
                    /* WARNING: Could not recover jumptable at 0x08131a74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08131A84 @ 0x08131A84

void sub_08131A84(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_030068bc = 1;
  sub_081316FC();
  DAT_030065e4 = 0;
  DAT_030068d4 = 10;
  return;
}


// sub_08131AB0 @ 0x08131AB0

undefined4 sub_08131AB0(undefined4 arg0,uint arg1)

{
  short sVar1;
  uint arg0_00;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint arg0_01;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg1 & 0xffff;
  sVar1 = 0;
  if (arg0_00 < 0xd0) {
    uVar2 = sub_080D2268(arg0_00);
    if ((short)arg0 == 0xff) {
      arg0_01 = 0;
      do {
        iVar3 = sub_080C09B0(arg0_01);
        if ((iVar3 != 0) &&
           (uVar4 = sub_080C00DC(arg0_01,uVar2 & 0xffff), (uVar4 & 0xffff) == arg0_00)) {
          sVar1 = sVar1 + 1;
        }
        arg0_01 = arg0_01 + 1 & 0xffff;
      } while (arg0_01 < 3);
    }
    else {
      uVar2 = sub_080C00DC((int)(short)arg0,uVar2 & 0xffff);
      if ((uVar2 & 0xffff) == arg0_00) {
        sVar1 = 1;
      }
    }
  }
  else {
    sVar1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x08131b1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*UNRECOVERED_JUMPTABLE)(sVar1);
  return uVar5;
}


// sub_08131B1C @ 0x08131B1C

void sub_08131B1C(int arg0)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = sub_080C3100();
  iVar7 = DAT_03006694;
  uVar4 = sub_08131AB0(0xff,(uint)DAT_030069a8);
  uVar5 = sub_080C32D4((uint)DAT_030069a8);
  uVar5 = uVar5 & 0xff;
  DAT_030066a0 = 0x15;
  DAT_03006958 = 1;
  if (DAT_030068d4 != 0) {
    DAT_030068d4 = DAT_030068d4 + -1;
    goto LAB_0813216e;
  }
  if ((DAT_030031c4 & 4) != 0) {
    DAT_030065e4 = DAT_030065e4 ^ 1;
    sub_081305D8((uint)DAT_030069a8);
    goto LAB_0813216e;
  }
  if ((DAT_03003964 & 0x40) != 0) {
    if (DAT_0203db5a == 0x2a) {
      iVar9 = (int)(short)DAT_030065fc;
      if (iVar9 * iVar7 + uVar3 < 999999) {
        uVar1 = (ushort)uVar5;
        if (DAT_030068bc == 1) {
          if ((int)uVar5 < iVar9 + 1) {
            DAT_030065fc = uVar1;
            uVar6 = __modsi3((int)(short)uVar1,10);
            DAT_03006654 = (uint)(short)uVar6;
            uVar6 = __divsi3((int)(short)DAT_030065fc,10);
            DAT_03006664 = (uint)(short)uVar6;
          }
          else {
            if (999999 < iVar7 * (iVar9 + 1) + uVar3) goto LAB_08131eb4;
            DAT_030065fc = DAT_030065fc + 1;
            if (99 < (short)DAT_030065fc) {
              DAT_030065fc = 99;
            }
            uVar6 = __modsi3((int)(short)DAT_030065fc,10);
            DAT_03006654 = (uint)(short)uVar6;
            uVar6 = __divsi3((int)(short)DAT_030065fc,10);
            DAT_03006664 = (uint)(short)uVar6;
          }
        }
        else if ((int)uVar5 < iVar9 + 10) {
          if (999999 < iVar7 * uVar5 + uVar3) goto LAB_08131cd0;
          DAT_030065fc = uVar1;
          uVar6 = __modsi3((int)(short)uVar1,10);
          DAT_03006654 = (uint)(short)uVar6;
          uVar6 = __divsi3((int)(short)DAT_030065fc,10);
          DAT_03006664 = (uint)(short)uVar6;
        }
        else if (iVar7 * (iVar9 + 10) + uVar3 < 1000000) {
          DAT_030065fc = DAT_030065fc + 10;
          uVar6 = __modsi3((int)(short)DAT_030065fc,10);
          DAT_03006654 = (uint)(short)uVar6;
          uVar6 = __divsi3((int)(short)DAT_030065fc,10);
          DAT_03006664 = (uint)(short)uVar6;
        }
        else {
LAB_08131cd0:
          iVar9 = (short)DAT_030065fc * iVar7;
          uVar4 = 0;
          do {
            if (999999 < iVar9 + uVar3) {
              uVar4 = uVar4 - 1;
              break;
            }
            iVar9 = iVar9 + iVar7;
            uVar4 = uVar4 + 1;
          } while (uVar4 < 10);
          DAT_030065fc = DAT_030065fc + (short)uVar4;
          uVar6 = __modsi3((int)(short)DAT_030065fc,10);
          DAT_03006654 = (uint)(short)uVar6;
          uVar6 = __divsi3((int)(short)DAT_030065fc,10);
          DAT_03006664 = (uint)(short)uVar6;
        }
        goto LAB_08131e54;
      }
    }
    else if (DAT_030065fc != 99) {
      if (DAT_030068bc == 10) {
        iVar9 = uVar5 + (uVar4 & 0xffff);
        if (iVar9 + (short)DAT_030065fc + 10 < 100) {
          uVar4 = iVar7 * ((short)DAT_030065fc + 10);
          if (uVar4 < uVar3 || uVar4 - uVar3 == 0) {
            DAT_030065fc = DAT_030065fc + 10;
            uVar6 = __modsi3((int)(short)DAT_030065fc,10);
            DAT_03006654 = (uint)(short)uVar6;
            uVar6 = __divsi3((int)(short)DAT_030065fc,10);
            DAT_03006664 = (uint)(short)uVar6;
          }
          else {
LAB_08131ddc:
            uVar4 = (short)DAT_030065fc * iVar7;
            sVar2 = 0;
            do {
              sVar8 = sVar2;
              uVar4 = uVar4 + iVar7;
              sVar2 = sVar8 + 1;
            } while (uVar4 <= uVar3);
            DAT_030065fc = sVar8 + DAT_030065fc;
            uVar6 = __modsi3((int)(short)DAT_030065fc,10);
            DAT_03006654 = (uint)(short)uVar6;
            uVar6 = __divsi3((int)(short)DAT_030065fc,10);
            DAT_03006664 = (uint)(short)uVar6;
          }
        }
        else {
          uVar4 = 99 - iVar9;
          uVar5 = uVar4 & 0xffff;
          if (uVar3 <= uVar5 * iVar7 && uVar5 * iVar7 - uVar3 != 0) goto LAB_08131ddc;
          DAT_030065fc = (ushort)uVar4;
          uVar3 = __umodsi3(uVar5,10);
          DAT_03006654 = uVar3 & 0xffff;
          uVar3 = __udivsi3(uVar5,10);
          DAT_03006664 = uVar3 & 0xffff;
        }
LAB_08131e54:
        sub_080C51D4(100);
      }
      else if (((int)((uVar4 & 0xffff) + uVar5 + (int)(short)DAT_030065fc + (int)DAT_030068bc) < 100
               ) && (uVar4 = iVar7 * ((int)(short)DAT_030065fc + (int)DAT_030068bc),
                    uVar4 < uVar3 || uVar4 - uVar3 == 0)) {
        DAT_030065fc = DAT_030065fc + DAT_030068bc;
        uVar6 = __modsi3((int)(short)DAT_030065fc,10);
        DAT_03006654 = (uint)(short)uVar6;
        uVar6 = __divsi3((int)(short)DAT_030065fc,10);
        DAT_03006664 = (uint)(short)uVar6;
        sub_080C51D4(100);
      }
    }
LAB_08131eb4:
    sub_081316FC();
    DAT_0203db2c = iVar7 * (short)DAT_030065fc;
    if ((999999 < DAT_0203db2c) && (DAT_0203db2c = 999999, DAT_0203db5a == 0x2a)) {
      DAT_030068a0 = 0;
      *(undefined2 *)(arg0 + 0x1c) = 1;
      DAT_0203db5a = 0x47;
      DAT_0300699c = 0;
      DAT_0300669c = 0;
      sub_080D34F0(DAT_030068a4);
      DAT_03006930 = 0;
      DAT_03006928 = 0;
      DAT_03006920 = 0;
      DAT_03006660 = 0;
      DAT_03006650 = 0;
      DAT_03006640 = 0;
      DAT_03006630 = 0;
      DAT_03006620 = 0;
      DAT_03006958 = 0;
      sub_080C51D4(0x66);
    }
    goto LAB_0813216e;
  }
  if ((DAT_03003964 & 0x80) == 0) {
    if ((DAT_030031c4 & 0x10) == 0) {
      if ((DAT_030031c4 & 0x20) == 0) {
        uVar1 = DAT_030031c4 & 1;
        if ((DAT_030031c4 & 1) == 0) {
          if ((DAT_030031c4 & 2) != 0) {
            DAT_030068a0 = uVar1;
            *(undefined2 *)(arg0 + 0x1c) = 1;
            DAT_0203db5a = 0x26;
            DAT_0300669c = uVar1;
            DAT_0300699c = uVar1;
            sub_080D34F0(DAT_030068a4);
            DAT_03006620 = uVar1;
            DAT_03006630 = uVar1;
            DAT_03006640 = uVar1;
            DAT_03006650 = uVar1;
            DAT_03006660 = uVar1;
            DAT_03006920 = uVar1;
            DAT_03006928 = uVar1;
            DAT_03006930 = uVar1;
            DAT_03006958 = uVar1;
            sub_080C51D4(0x66);
          }
        }
        else {
          *(undefined2 *)(arg0 + 0x1c) = 1;
          if (DAT_030065fc == 0) {
            DAT_030068a0 = DAT_030065fc;
            DAT_0203db5a = 0x35;
            sub_080C51D4(0x66);
          }
          else {
            if (DAT_0203db5a == 0x2a) {
              iVar7 = sub_080C4C7C((uint)DAT_030069a8);
              DAT_0203db2c = (short)DAT_030065fc * iVar7;
              if (999999 < DAT_0203db2c) {
                DAT_0203db2c = 999999;
              }
            }
            else {
              DAT_0203db2c = iVar7 * (short)DAT_030065fc;
              if (999999 < DAT_0203db2c) {
                DAT_0203db2c = 999999;
              }
            }
            sub_080C51D4(0x65);
            DAT_0203db5a = 0x27;
            DAT_0203db50 = DAT_030069a8;
          }
          DAT_0300699c = 0;
          DAT_0300669c = 0;
          sub_080D34F0(DAT_030068a4);
          DAT_03006930 = 0;
          DAT_03006928 = 0;
          DAT_03006920 = 0;
          DAT_03006660 = 0;
          DAT_03006650 = 0;
          DAT_03006640 = 0;
          DAT_03006630 = 0;
          DAT_03006620 = 0;
          DAT_03006958 = 0;
        }
        goto LAB_0813216e;
      }
      DAT_030068bc = 10;
    }
    else {
      DAT_030068bc = 1;
    }
    sub_081316FC();
    sub_080C51D4(100);
    goto LAB_0813216e;
  }
  if (DAT_030068bc == 10) {
    if ((short)DAT_030065fc < 0xb) {
      DAT_030065fc = 1;
      DAT_03006654 = 1;
      DAT_03006664 = DAT_03003964 & 0x40;
      sub_080C51D4(100);
    }
    else {
LAB_08131f9e:
      DAT_030065fc = DAT_030065fc - DAT_030068bc;
      uVar6 = __modsi3((int)(short)DAT_030065fc,10);
      DAT_03006654 = (uint)(short)uVar6;
      uVar6 = __divsi3((int)(short)DAT_030065fc,10);
      DAT_03006664 = (uint)(short)uVar6;
      sub_080C51D4(100);
    }
  }
  else if (0 < (int)(short)DAT_030065fc - (int)DAT_030068bc) goto LAB_08131f9e;
  sub_081316FC();
  DAT_0203db2c = iVar7 * (short)DAT_030065fc;
  if (999999 < DAT_0203db2c) {
    DAT_0203db2c = 999999;
  }
LAB_0813216e:
                    /* WARNING: Could not recover jumptable at 0x0813217c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081321A0 @ 0x081321A0

void sub_081321A0(void)

{
  DAT_03006848 = 0;
  DAT_03006680 = 0;
  return;
}


// ScriptOp_Shared_081321B4 @ 0x081321B4

void ScriptOp_Shared_081321B4(void)

{
  return;
}


// ScriptOpAlt_Shared_081321B8 @ 0x081321B8

void ScriptOpAlt_Shared_081321B8(void)

{
  DAT_0203db5e = 1;
  return;
}


// ScriptOpAlt_Shared_081321C4 @ 0x081321C4

void ScriptOpAlt_Shared_081321C4(void)

{
  DAT_0203db5e = 1;
  DAT_0203db60 = 1;
  return;
}


// ScriptOpAlt_301 @ 0x081321D8

void ScriptOpAlt_301(void)

{
  DAT_0203db5e = 2;
  return;
}


// ScriptOp_300 @ 0x081321E4

void ScriptOp_300(void)

{
  DAT_0203db38 = 0;
  DAT_0203db3a = DAT_0203db3a + 1;
  DAT_0203db4a = DAT_0203db4a + 1;
  return;
}


// ScriptOp_301 @ 0x08132208

void ScriptOp_301(int arg0)

{
  undefined4 *puVar1;
  
  if (DAT_030069cc == 0) {
    if (DAT_03006910 == 0) {
      if (DAT_030065ec == 0) {
        if (DAT_03006600 == 0) {
          if (DAT_0203db64 == 0) {
            DAT_0203db3e = DAT_0203db64;
            DAT_0203db38 = DAT_0203db64;
            DAT_0203db3a = DAT_0203db64;
            DAT_0203db40 = DAT_0203db64;
            *(undefined2 *)(arg0 + 0x1c) = 1;
            DAT_0203db46 = 1;
            sub_0813EB6C(0);
            Font_ResetGlyphSpriteCache(0x180);
            sub_080AD1FC(DAT_030069e4);
            DAT_0203db6e = 1;
            return;
          }
          DAT_0203db64 = DAT_03006600;
          DAT_0203db40 = DAT_03006818;
          puVar1 = (undefined4 *)0x30068c4;
        }
        else {
          DAT_03006600 = DAT_030065ec;
          DAT_0203db40 = DAT_030069e0;
          puVar1 = (undefined4 *)0x3006674;
        }
      }
      else {
        DAT_030065ec = DAT_03006910;
        DAT_0203db40 = DAT_03006960;
        puVar1 = (undefined4 *)0x3006854;
      }
    }
    else {
      DAT_03006910 = DAT_030069cc;
      DAT_0203db40 = DAT_03006610;
      puVar1 = (undefined4 *)0x30068d0;
    }
    DAT_03006950 = *puVar1;
  }
  else {
    DAT_030069cc = 0;
    DAT_03006950 = DAT_0203db04;
    DAT_0203db40 = 0;
  }
  return;
}


// sub_08132350 @ 0x08132350

void sub_08132350(uint arg0)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xffff;
  if (uVar1 == 0xff) {
    sub_080C5170(0);
  }
  else {
    if (uVar1 == 0xc4) {
      uVar1 = 0x8f;
    }
    if (uVar1 == 0xc5) {
      uVar1 = 0x90;
    }
    if (uVar1 == 0xc0) {
      uVar1 = 0x91;
    }
    if (uVar1 == 0xc2) {
      uVar1 = 0x92;
    }
    if ((uVar1 < 0xc0) && (uVar1 = (uint)*(ushort *)(uVar1 * 2 + 0x8790180), uVar1 != 0xffff)) {
      if (uVar1 < 100) {
        sub_080C5170(uVar1);
      }
      else {
        sub_080C51D4(uVar1);
      }
    }
  }
  return;
}


// ScriptOp_303 @ 0x081323AC

void ScriptOp_303(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_08132350((uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  return;
}


// ScriptOp_304 @ 0x081323D4

void ScriptOp_304(void)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint arg0;
  uint arg1;
  
  arg0 = (uint)*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  uVar1 = DAT_0203db40 + 2;
  arg1 = (uint)*(ushort *)((uint)(ushort)(DAT_0203db40 + 1) * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 3;
  uVar1 = *(ushort *)((uint)uVar1 * 2 + DAT_03006950);
  uVar2 = sub_080C4618(arg0,arg1,(uint)(uVar1 >> 8),uVar1 & 0xff);
  *(undefined4 *)((arg0 & 0xf) * 4 + 0x30068f0) = uVar2;
  iVar3 = sub_080D95F4(arg1);
  if (*(int *)(iVar3 + 0x28) != 0) {
    DAT_0203db6e = 1;
  }
  return;
}


// ScriptOp_305 @ 0x08132464

void ScriptOp_305(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_030068b0 = sub_080B6DB4((uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  DAT_0203db5a = 2;
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_306 @ 0x081324A8

void ScriptOp_306(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_307 @ 0x081324B8

void ScriptOp_307(void)

{
  uint arg1;
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int arg0;
  
  arg1 = (uint)*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  iVar1 = arg1 * 4;
  piVar2 = (int *)(iVar1 + 0x30069c0);
  arg0 = *piVar2;
  if (arg0 == 0) {
    puVar3 = (undefined4 *)(iVar1 + 0x30068f0);
    DAT_0203db40 = DAT_0203db40 + 1;
    sub_080C48F0(*puVar3);
    *puVar3 = 0;
  }
  else {
    DAT_0203db40 = DAT_0203db40 + 1;
    sub_080E9044(arg0,arg1);
    *piVar2 = 0;
  }
  return;
}


// ScriptOp_308 @ 0x0813250C

void ScriptOp_308(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_0203db28 = (ushort)*(byte *)((uint)uVar1 * 2 + DAT_03006950);
  DAT_03006970 = 1;
  DAT_0203db66 = 1;
  return;
}


// ScriptOpAlt_304_32D_336 @ 0x08132544

void ScriptOpAlt_304_32D_336(void)

{
  DAT_0203db40 = DAT_0203db40 + 3;
  return;
}


// ScriptOpAlt_395 @ 0x08132554

void ScriptOpAlt_395(void)

{
  DAT_0203db40 = DAT_0203db40 + 2;
  return;
}


// ScriptOpAlt_Shared_08132564 @ 0x08132564

void ScriptOpAlt_Shared_08132564(void)

{
  DAT_0203db40 = DAT_0203db40 + 1;
  return;
}


// ScriptOp_309 @ 0x08132574

void ScriptOp_309(void)

{
  undefined4 uVar1;
  uint arg0;
  
  arg0 = (uint)*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 1;
  uVar1 = sub_080E8E00(arg0,(uint)*(ushort *)((arg0 & 0xf) * 2 + 0x203db28));
  *(undefined4 *)(arg0 * 4 + 0x30069c0) = uVar1;
  return;
}


// ScriptOp_30A @ 0x081325BC

void ScriptOp_30A(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_0203db50 = *(undefined2 *)((uint)uVar1 * 2 + DAT_03006950);
  return;
}


// ScriptOp_30B @ 0x081325E4

void ScriptOp_30B(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  
  uVar3 = DAT_0203db50;
  uVar6 = (uint)DAT_0203db50;
  uVar5 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar5 * 2 + DAT_03006950);
  if (uVar6 < 300) {
    uVar6 = sub_080C32D4(uVar6);
    if ((uVar6 & 0xff) != 0) {
      return;
    }
  }
  else {
    iVar4 = sub_080C57CC(uVar6);
    if (iVar4 == 1) {
      sub_080C3328(uVar6);
      DAT_0203db50 = uVar3;
      return;
    }
  }
  DAT_030068e4 = CONCAT22(uVar2,uVar1);
  return;
}


// ScriptOpAlt_30B @ 0x08132654

void ScriptOpAlt_30B(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  
  uVar3 = DAT_0203db50;
  uVar6 = (uint)DAT_0203db50;
  uVar5 = DAT_0203db40 + 1;
  uVar1 = *(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar2 = *(undefined2 *)((uint)uVar5 * 2 + DAT_03006950);
  if (uVar6 < 300) {
    uVar6 = sub_080C32D4(uVar6);
    if ((uVar6 & 0xff) != 0) {
      return;
    }
  }
  else {
    iVar4 = sub_080C57CC(uVar6);
    if (iVar4 == 1) {
      DAT_0203db50 = uVar3;
      return;
    }
  }
  DAT_030068e4 = CONCAT22(uVar2,uVar1);
  return;
}


// ScriptOp_30C @ 0x081326C0

void ScriptOp_30C(void)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  if (uVar2 == 0x114) {
    DAT_0203db40 = DAT_0203db40 + 1;
    uVar2 = sub_080C2A84(2);
    uVar2 = uVar2 & 0xffff;
    uVar1 = DAT_0203db40;
  }
  else {
    DAT_0203db40 = DAT_0203db40 + 1;
    uVar2 = sub_080C2340(uVar2);
    uVar1 = DAT_0203db40;
  }
  if (uVar2 == 1) {
    DAT_0203db40 = uVar1 + 1;
    DAT_030068e4 = CONCAT22(*(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950),
                            *(undefined2 *)((uint)uVar1 * 2 + DAT_03006950));
  }
  else {
    DAT_0203db40 = uVar1 + 2;
  }
  return;
}


// ScriptOp_30D @ 0x08132734

void ScriptOp_30D(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  undefined4 uVar7;
  short sVar8;
  
  uVar6 = DAT_0203db40 + 1;
  uVar4 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 2;
  uVar7 = CONCAT22(*(undefined2 *)((uint)uVar6 * 2 + DAT_03006950),
                   *(undefined2 *)(uVar4 * 2 + DAT_03006950));
  iVar3 = sub_080C09B0(1);
  if ((iVar3 != 0) || (iVar3 = sub_080C09B0(2), uVar2 = DAT_030068e4, iVar3 != 0)) {
    sVar1 = DAT_030046d8;
    iVar3 = sub_080C09B0(1);
    sVar8 = 0;
    if (iVar3 != 0) {
      sVar8 = DAT_03004758;
    }
    iVar3 = sub_080C09B0(2);
    if (iVar3 != 0) {
      sVar8 = DAT_030047d8;
    }
    uVar2 = uVar7;
    if ((sVar1 != 0) && (sVar8 != 0)) {
      uVar4 = sub_080C0818(0);
      uVar4 = uVar4 & 0xffff;
      iVar3 = sub_080C09B0(1);
      if (iVar3 == 0) {
        uVar5 = sub_080C0818(1);
        uVar4 = uVar4 | uVar5 & 0xffff;
      }
      iVar3 = sub_080C09B0(2);
      if (iVar3 == 0) {
        uVar5 = sub_080C0818(2);
        uVar4 = uVar4 | uVar5 & 0xffff;
      }
      if ((uVar4 & 0x3000) == 0) {
        return;
      }
    }
  }
  DAT_030068e4 = uVar2;
  return;
}


// ScriptOp_30E @ 0x081327F8

void ScriptOp_30E(void)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = DAT_0203db40 + 1;
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 2;
  DAT_0203dac8 = CONCAT22(*(undefined2 *)((uint)uVar2 * 2 + DAT_03006950),
                          *(undefined2 *)(uVar1 * 2 + DAT_03006950));
  DAT_0203db5a = 10;
  DAT_030068e0 = sub_080ABEB4(0);
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_30F @ 0x08132858

void ScriptOp_30F(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_030068e4 = CONCAT22(*(undefined2 *)((uint)DAT_0203db40 * 2 + DAT_03006950),
                          *(undefined2 *)(uVar1 * 2 + DAT_03006950));
  return;
}


// sub_08132890 @ 0x08132890

void sub_08132890(void)

{
  dword arg2;
  
  if ((DAT_0203db66 & DAT_0203db68) == 0) {
    if ((DAT_0203db66 == 0) || (DAT_0203db68 != 0)) {
      sub_080E47A8(1,0xffff,(uint)DAT_0203db2a,0);
      return;
    }
    arg2 = 0xffff;
  }
  else {
    arg2 = (dword)DAT_0203db2a;
  }
  sub_080E47A8(1,(uint)DAT_0203db28,arg2,(uint)DAT_03006970);
  return;
}


// ScriptOp_310 @ 0x0813291C

void ScriptOp_310(void)

{
  if (*(short *)((uint)DAT_0203db40 * 2 + DAT_03006950) == 0) {
    DAT_0203db40 = DAT_0203db40 + 1;
    sub_080C23BC(0xd5);
  }
  else {
    DAT_0203db40 = DAT_0203db40 + 1;
    sub_080C2364(0xd5);
  }
  DAT_0203db5a = 7;
  sub_08132890();
  DAT_0203db68 = 0;
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  if (DAT_0203db6c != 0) {
    sub_080AB91C(DAT_03006968,1);
    DAT_0203db6c = 0;
  }
  Font_ResetGlyphSpriteCache(0x180);
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_311 @ 0x081329BC

void ScriptOp_311(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_030068a8 = *(undefined2 *)((uint)uVar1 * 2 + DAT_03006950);
  return;
}


// ScriptOp_312 @ 0x081329E4

void ScriptOp_312(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_080C2364((uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  return;
}


// ScriptOp_315 @ 0x08132A0C

void ScriptOp_315(void)

{
  if (DAT_0203db48 == 1) {
    DAT_0203db5c = DAT_0203db48;
    DAT_0203db6e = DAT_0203db48;
  }
  else {
    DAT_0203db5c = 0x14;
    DAT_0203db6e = 1;
  }
  DAT_0203db5a = 0xf;
  return;
}


// ScriptOp_316 @ 0x08132A5C

void ScriptOp_316(void)

{
  DAT_0203db5a = 3;
  sub_080AD0FC(0x87900ec,0xffff);
  DAT_0203db56 = 1;
  DAT_0203db54 = 0x1e;
  DAT_0203db52 = 1;
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_341 @ 0x08132AA0

void ScriptOp_341(void)

{
  DAT_0203db5a = 3;
  sub_080AD0FC(0x87900ec,0xffff);
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_317 @ 0x08132ACC

void ScriptOp_317(void)

{
  DAT_0203db5a = 5;
  sub_080AD0FC(0x87900a0,0xffff);
  DAT_0203db6e = 1;
  return;
}


// ScriptOp_318 @ 0x08132AF8

void ScriptOp_318(void)

{
  DAT_0203db40 = DAT_0203db4e;
  DAT_03006950 = DAT_030068cc;
  return;
}


// ScriptOp_319 @ 0x08132B1C

void ScriptOp_319(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  sub_080C23BC((uint)*(ushort *)(uVar1 * 2 + DAT_03006950));
  return;
}


// ScriptOp_DrawCharOrSubstitute @ 0x08132B40

void ScriptOp_DrawCharOrSubstitute(void)

{
  ushort uVar1;
  dword dVar2;
  ushort *puVar3;
  char *pcVar4;
  undefined2 *puVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  short *psVar9;
  uint uVar10;
  int iVar11;
  short sVar12;
  uint uVar13;
  uint uVar14;
  short local_30 [8];
  
  sVar12 = 0;
  uVar14 = 0;
  uVar13 = 0;
  do {
    *(undefined2 *)((short)uVar13 * 2 + 0x203db08) = 0;
    uVar10 = (int)(short)uVar13 + 1;
    uVar13 = uVar10 & 0xffff;
  } while ((int)(uVar10 * 0x10000) >> 0x10 < 0x10);
  if (DAT_0203db44 == 0x327) {
    sVar12 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
    DAT_0203db40 = DAT_0203db40 + 1;
  }
  DAT_0203db4e = DAT_0203db40;
  DAT_030068cc = DAT_03006950;
  if (DAT_0203db44 == 0x36e) {
    DAT_0203db08 = 0x52;
    DAT_0203db0a = 0x318;
    DAT_0203db40 = 0;
    DAT_03006950 = 0x203db08;
    return;
  }
  switch(DAT_0203db44) {
  case 0x31a:
    dVar2 = 0x30046c0;
    goto LAB_08132cc6;
  case 0x31b:
    dVar2 = 0x8001;
    goto LAB_08132ce4;
  case 0x31c:
    dVar2 = 0x8002;
    sub_080C10E4(0x8002);
    goto LAB_0813311e;
  case 0x31d:
    if (DAT_03006670 == 1) {
      iVar11 = sub_080C09B0(2);
      if (iVar11 == 0) {
        dVar2 = 0x3004740;
      }
      else {
        dVar2 = 0x30047c0;
      }
      Combatant_DecodeName(dVar2,0x203db08);
    }
    else {
      Combatant_DecodeName(0x3004740,0x203db08);
    }
    DAT_0203db18 = 0;
    uVar14 = 1;
    break;
  case 0x31e:
    if (DAT_03006670 == 1) {
      puVar3 = (ushort *)0x203db7c;
    }
    else {
      puVar3 = (ushort *)0x203db28;
    }
    iVar11 = sub_080BF648((uint)*puVar3);
    puVar5 = (undefined2 *)(iVar11 + 0x22);
    uVar13 = 0;
    do {
      *(undefined2 *)((short)uVar13 * 2 + 0x203db08) = *puVar5;
      puVar5 = puVar5 + 1;
      uVar10 = (int)(short)uVar13 + 1;
      uVar13 = uVar10 & 0xffff;
    } while ((int)(uVar10 * 0x10000) >> 0x10 < 8);
    break;
  case 799:
    if (DAT_03006670 == 1) {
      puVar3 = (ushort *)0x203db7c;
    }
    else {
      puVar3 = (ushort *)0x203db28;
    }
    pcVar4 = (char *)sub_080BF648((uint)*puVar3);
    puVar5 = (undefined2 *)Race_GetName((int)*pcVar4 & 0xffff);
    uVar13 = 0;
    do {
      *(undefined2 *)((short)uVar13 * 2 + 0x203db08) = *puVar5;
      puVar5 = puVar5 + 1;
      uVar10 = (int)(short)uVar13 + 1;
      uVar13 = uVar10 & 0xffff;
    } while ((int)(uVar10 * 0x10000) >> 0x10 < 8);
    break;
  case 800:
    uVar13 = 0;
    while ((iVar11 = (int)(short)uVar13, iVar11 < 4 && (iVar7 = sub_080C0A00(iVar11), iVar7 != 1)))
    {
      uVar13 = iVar11 + 1U & 0xffff;
    }
    Combatant_DecodeName(iVar11 * 0x80 + 0x30046c0,0x203db08);
    uVar13 = 8;
    if (DAT_0203db16 == 0) {
      uVar13 = 6;
      do {
        iVar11 = (int)(short)uVar13;
        if ((*(short *)(iVar11 * 2 + 0x203db08) != 0) &&
           (*(short *)((iVar11 + 1) * 2 + 0x203db08) == 0)) break;
        uVar13 = iVar11 - 1U & 0xffff;
      } while (0 < (int)((iVar11 - 1U) * 0x10000));
      uVar13 = uVar13 * 0x10000 + 0x10000 >> 0x10;
    }
    uVar10 = 0;
    uVar14 = 0;
    do {
      iVar11 = sub_080C09B0((int)(short)uVar14);
      if (iVar11 != 0) {
        uVar10 = uVar10 * 0x10000 + 0x10000 >> 0x10;
      }
      uVar8 = (int)(short)uVar14 + 1;
      uVar14 = uVar8 & 0xffff;
    } while ((int)(uVar8 * 0x10000) >> 0x10 < 4);
    uVar14 = uVar13;
    if (1 < (short)uVar10) {
      uVar14 = uVar13 * 0x10000 + 0x10000 >> 0x10;
      *(undefined2 *)(((int)(uVar13 << 0x10) >> 0xf) + 0x203db08) = 0xc8f;
    }
    *(undefined2 *)(((int)(uVar14 << 0x10) >> 0xf) + 0x203db08) = 0x318;
    uVar14 = 2;
    break;
  case 0x321:
    uVar13 = (uint)DAT_0203db50;
    if (uVar13 < 0xd0) {
      if (uVar13 < 0x80) {
        iVar11 = sub_080BF32C((uint)DAT_0203db50);
      }
      else {
        iVar11 = Equipment_GetRecord36_MidRange((uint)DAT_0203db50);
      }
      puVar5 = (undefined2 *)(iVar11 + 0x14);
    }
    else {
      iVar11 = Action_GetRecord(uVar13);
      puVar5 = (undefined2 *)(iVar11 + 0xc);
    }
    uVar13 = 0;
    do {
      *(undefined2 *)((short)uVar13 * 2 + 0x203db08) = *puVar5;
      puVar5 = puVar5 + 1;
      uVar10 = (int)(short)uVar13 + 1;
      uVar13 = uVar10 & 0xffff;
    } while ((int)(uVar10 * 0x10000) >> 0x10 < 8);
    break;
  case 0x322:
    uVar1 = DAT_0203db2a;
    if (DAT_03006670 == 1) {
      uVar1 = DAT_0203db7e;
    }
    iVar11 = sub_080BF648((uint)uVar1);
    puVar5 = (undefined2 *)(iVar11 + 0x22);
    uVar13 = 0;
    do {
      *(undefined2 *)((short)uVar13 * 2 + 0x203db08) = *puVar5;
      puVar5 = puVar5 + 1;
      uVar10 = (int)(short)uVar13 + 1;
      uVar13 = uVar10 & 0xffff;
    } while ((int)(uVar10 * 0x10000) >> 0x10 < 8);
    break;
  case 0x323:
    puVar6 = (uint *)0x203db2c;
LAB_08132fae:
    uVar13 = *puVar6;
    goto LAB_08132fb0;
  case 0x324:
    dVar2 = (uint)DAT_03006850 * 0x80 + 0x30046c0;
LAB_0813311e:
    Combatant_DecodeName(dVar2,0x203db08);
    DAT_0203db18 = 0;
    uVar14 = 1;
    break;
  case 0x325:
    dVar2 = 0x30047c0;
LAB_08132cc6:
    Combatant_DecodeName(dVar2,0x203db08);
    DAT_0203db18 = 0;
    uVar14 = 1;
    break;
  case 0x327:
    if (sVar12 == 0) {
      pcVar4 = (char *)sub_080BF648((uint)DAT_0203db2a);
      puVar5 = (undefined2 *)Race_GetName((int)*pcVar4 & 0xffff);
      uVar13 = 0;
      do {
        *(undefined2 *)((short)uVar13 * 2 + 0x203db08) = *puVar5;
        puVar5 = puVar5 + 1;
        uVar10 = (int)(short)uVar13 + 1;
        uVar13 = uVar10 & 0xffff;
      } while ((int)(uVar10 * 0x10000) >> 0x10 < 8);
      break;
    }
    if (sVar12 == 1) {
      iVar11 = sub_080BF5C0((uint)DAT_0203db80);
      puVar5 = (undefined2 *)(iVar11 + 6);
      uVar13 = 0;
      do {
        *(undefined2 *)((short)uVar13 * 2 + 0x203db08) = *puVar5;
        puVar5 = puVar5 + 1;
        uVar10 = (int)(short)uVar13 + 1;
        uVar13 = uVar10 & 0xffff;
      } while ((int)(uVar10 * 0x10000) >> 0x10 < 8);
      break;
    }
    if (sVar12 == 2) {
      puVar6 = (uint *)0x203db30;
      goto LAB_08132fae;
    }
    if (sVar12 != 3) break;
    uVar13 = sub_080C32D4(0x11f);
    uVar13 = uVar13 & 0xff;
LAB_08132fb0:
    if (uVar13 == 0) {
      local_30[0] = 0xcc;
      uVar13 = 1;
      do {
        local_30[(short)uVar13] = 0;
        uVar10 = (int)(short)uVar13 + 1;
        uVar13 = uVar10 & 0xffff;
      } while ((int)(uVar10 * 0x10000) >> 0x10 < 8);
    }
    else {
      uVar10 = 0;
      do {
        if (uVar13 == 0) {
          *(undefined2 *)((int)local_30 + ((int)(uVar10 << 0x10) >> 0xf)) = 0;
        }
        else {
          iVar11 = __modsi3(uVar13,10);
          *(undefined2 *)((int)local_30 + ((int)(uVar10 << 0x10) >> 0xf)) =
               *(undefined2 *)(iVar11 * 2 + 0x878f9b8);
          uVar13 = __divsi3(uVar13,10);
        }
        uVar8 = uVar10 * 0x10000 + 0x10000;
        uVar10 = uVar8 >> 0x10;
      } while ((int)uVar8 >> 0x10 < 8);
    }
    uVar13 = 0;
    uVar10 = 7;
    do {
      if (local_30[(short)uVar10] != 0) {
        *(short *)((short)uVar13 * 2 + 0x203db08) = local_30[(short)uVar10];
        uVar13 = (int)(short)uVar13 + 1U & 0xffff;
      }
      uVar8 = (int)(short)uVar10 - 1;
      uVar10 = uVar8 & 0xffff;
    } while (-1 < (int)(uVar8 * 0x10000));
    break;
  case 0x328:
    uVar13 = 0;
    sVar12 = *(short *)(&DAT_0878f9ce + (uint)DAT_0203db72 * 0x14);
    while (sVar12 != 0x301) {
      *(short *)((short)uVar13 * 2 + 0x203db08) = sVar12;
      uVar10 = (int)(short)uVar13 + 1;
      uVar13 = uVar10 & 0xffff;
      iVar11 = (int)(uVar10 * 0x10000) >> 0x10;
      if (9 < iVar11) break;
      sVar12 = *(short *)((iVar11 + 1) * 2 + (uint)DAT_0203db72 * 0x14 + 0x878f9cc);
    }
    break;
  case 0x329:
    uVar13 = 0;
    do {
      iVar11 = (short)uVar13 * 2;
      sVar12 = *(short *)(iVar11 + *(short *)(DAT_0300696c * 2 + 0x30069a0) * 0x14 + 0x878ef04);
      if (sVar12 == 0x301) break;
      *(short *)(iVar11 + 0x203db08) = sVar12;
      uVar10 = (int)(short)uVar13 + 1;
      uVar13 = uVar10 & 0xffff;
    } while ((int)(uVar10 * 0x10000) >> 0x10 < 10);
    break;
  case 0x32e:
    dVar2 = 0x8000;
LAB_08132ce4:
    sub_080C10E4(dVar2);
    Combatant_DecodeName(dVar2,0x203db08);
    DAT_0203db18 = 0;
    uVar14 = 1;
    break;
  case 0x32f:
    iVar11 = sub_080C31F0();
    if (iVar11 == 0) {
      local_30[0] = 0xcc;
      uVar13 = 1;
      do {
        local_30[(short)uVar13] = 0;
        uVar10 = (int)(short)uVar13 + 1;
        uVar13 = uVar10 & 0xffff;
      } while ((int)(uVar10 * 0x10000) >> 0x10 < 8);
    }
    else {
      uVar13 = 0;
      do {
        if (iVar11 == 0) {
          *(undefined2 *)((int)local_30 + ((int)(uVar13 << 0x10) >> 0xf)) = 0;
        }
        else {
          iVar7 = __modsi3(iVar11,10);
          *(undefined2 *)((int)local_30 + ((int)(uVar13 << 0x10) >> 0xf)) =
               *(undefined2 *)(iVar7 * 2 + 0x878f9b8);
          iVar11 = __divsi3(iVar11,10);
        }
        uVar10 = uVar13 * 0x10000 + 0x10000;
        uVar13 = uVar10 >> 0x10;
      } while ((int)uVar10 >> 0x10 < 8);
    }
    uVar13 = 0;
    uVar10 = 7;
    do {
      if (local_30[(short)uVar10] != 0) {
        *(short *)((short)uVar13 * 2 + 0x203db08) = local_30[(short)uVar10];
        uVar13 = (int)(short)uVar13 + 1U & 0xffff;
      }
      uVar8 = (int)(short)uVar10 - 1;
      uVar10 = uVar8 & 0xffff;
    } while (-1 < (int)(uVar8 * 0x10000));
  }
  if (uVar14 == 1) {
    uVar13 = 0xe;
    do {
      iVar11 = (int)(uVar13 * 0x10000) >> 0x10;
      if (*(short *)(iVar11 * 2 + 0x203db08) != 0) {
        psVar9 = (short *)((iVar11 + 1) * 2 + 0x203db08);
        if ((*psVar9 == 0) || (*psVar9 == 0x318)) goto LAB_0813327a;
      }
      uVar14 = uVar13 * 0x10000 - 0x10000;
      uVar13 = uVar14 >> 0x10;
    } while (-1 < (int)uVar14);
  }
  else if ((uVar14 < 2) && (uVar14 == 0)) {
    uVar13 = 0xe;
    do {
      iVar11 = (int)(uVar13 * 0x10000) >> 0x10;
      if (*(short *)(iVar11 * 2 + 0x203db08) != 0) {
        psVar9 = (short *)((iVar11 + 1) * 2 + 0x203db08);
        if ((*psVar9 == 0) || (*psVar9 == 0x318)) {
LAB_0813327a:
          *psVar9 = 0x318;
          DAT_0203db40 = 0;
          DAT_03006950 = 0x203db08;
          return;
        }
      }
      uVar14 = uVar13 * 0x10000 - 0x10000;
      uVar13 = uVar14 >> 0x10;
    } while (-1 < (int)uVar14);
  }
  DAT_03006950 = 0x203db08;
  DAT_0203db40 = 0;
  return;
}


// ScriptOp_32A @ 0x081332BC

void ScriptOp_32A(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0203db40;
  DAT_0203db40 = DAT_0203db40 + 1;
  DAT_0203db2a = (ushort)*(byte *)((uint)uVar1 * 2 + DAT_03006950);
  DAT_03006972 = 1;
  DAT_0203db68 = 1;
  return;
}


// ScriptOp_32B @ 0x081332F4

void ScriptOp_32B(void)

{
  ushort uVar1;
  short sVar2;
  uint arg1;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  
  sVar2 = DAT_0203db40 + 1;
  uVar1 = *(ushort *)((uint)DAT_0203db40 * 2 + DAT_03006950);
  DAT_0203db40 = sVar2;
  if (uVar1 == 0xff) {
    sub_080C3818(1);
  }
  else {
    arg1 = uVar1 & 0xf;
    if ((uVar1 & 0xf) == 0 || arg1 == 1) {
      piVar5 = (int *)(arg1 * 4 + 0x30068f0);
      iVar4 = *piVar5;
      if (iVar4 == 0) {
        piVar5 = (int *)(arg1 * 4 + 0x30069c0);
        iVar4 = *piVar5;
        if (iVar4 != 0) {
          sub_080E9044(iVar4,arg1);
          *piVar5 = 0;
        }
      }
      else {
        sub_080C48F0(iVar4);
        *piVar5 = 0;
      }
    }
    else {
      puVar3 = (undefined4 *)(arg1 * 4 + 0x30068f0);
      sub_080C48F0(*puVar3);
      *puVar3 = 0;
    }
  }
  return;
}


// sub_0813337C @ 0x0813337C

void sub_0813337C(void)

{
  DAT_0203db5a = 0x13;
  return;
}


// sub_08133388 @ 0x08133388

void sub_08133388(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  return;
}


// sub_08133390 @ 0x08133390

void sub_08133390(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 1;
  return;
}


// sub_08133398 @ 0x08133398

void sub_08133398(void)

{
  return;
}


// sub_0813339C @ 0x0813339C

void sub_0813339C(int arg0)

{
  *(undefined1 *)(arg0 + 0x25) = 200;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0203db5a = 0x13;
  return;
}


// sub_081333B4 @ 0x081333B4

void sub_081333B4(int arg0)

{
  char cVar1;
  
  cVar1 = *(char *)(arg0 + 0x25);
  if (((cVar1 == '\0') || (cVar1 = cVar1 + -1, *(char *)(arg0 + 0x25) = cVar1, cVar1 == '\0')) &&
     ((DAT_030031c4 & 1) != 0)) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


