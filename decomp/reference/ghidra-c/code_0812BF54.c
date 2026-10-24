/* Ghidra decompilation of asm/code_0812BF54.s (reference only; not compiled). */

// sub_0812BF54 @ 0x0812BF54

void sub_0812BF54(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(4);
  sub_08127EAC(6,(uint)*(ushort *)(iVar1 + 0xc));
  return;
}


// sub_0812BF68 @ 0x0812BF68

void sub_0812BF68(int arg0)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = sub_08126D1C(4);
  bVar1 = *(byte *)(iVar3 + 0xc);
  sub_08126A08(4);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_030031b8 & 1) != 0) {
      uVar2 = *(ushort *)(iVar3 + 0x12);
      *(undefined2 *)(arg0 + 0x1e) = (&DAT_0203c4d0)[(uint)uVar2 * 2];
      *(char *)(arg0 + 0x24) = (char)(&DAT_0203c4d0)[(uint)uVar2 * 2];
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  if ((ushort)bVar1 != *(ushort *)(iVar3 + 0xc)) {
    sub_08127EAC(6,(uint)*(ushort *)(iVar3 + 0xc));
  }
  sub_080AA184(0x8000f8c,0,0,1);
  if (5 < *(ushort *)(iVar3 + 10)) {
    if (*(short *)(iVar3 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(iVar3 + 0xc) + 5 != (uint)*(ushort *)(iVar3 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
  return;
}


// sub_0812C054 @ 0x0812C054

void sub_0812C054(void)

{
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  sub_081269B0(4);
  sub_080EA964();
  sub_08128388();
  return;
}


// sub_0812C07C @ 0x0812C07C

void sub_0812C07C(int arg0)

{
  undefined4 arg1;
  
  sub_080EA210();
  DAT_0203d310 = sub_080ABEB4(0);
  arg1 = Battle_BuildItemDropText((uint)*(ushort *)(arg0 + 0x1e),0x8124514);
  BattleMenu_SetMode(3,arg1);
  sub_080EC99C(1);
  return;
}


// sub_0812C0BC @ 0x0812C0BC

void sub_0812C0BC(int arg0)

{
  sub_080C33AC((uint)*(byte *)(arg0 + 0x24));
  sub_080EA964();
  return;
}


// sub_0812C0D0 @ 0x0812C0D0

void sub_0812C0D0(void)

{
  DAT_0203c248 = sub_080AD0FC(0x8779834,0xffff);
  DAT_0203c250 = 0;
  DAT_0203c24c = 0;
  DAT_0203c891 = 1;
  return;
}


// sub_0812C104 @ 0x0812C104

void sub_0812C104(int arg0)

{
  int iVar1;
  dword arg0_00;
  undefined4 uVar2;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  sub_080EA210();
  iVar1 = sub_080F31E0();
  if (iVar1 == 0) {
    iVar1 = sub_080F4444();
    if (iVar1 != 0) {
      uVar2 = Menu_ExpandListTemplate(0x8124f12,0);
      BattleMenu_SetMode(4,uVar2);
      DAT_0203c24c = sub_080C8AAC(0,(uint)DAT_0203c891);
      sub_080C8ADC(DAT_0203c24c,1);
      return;
    }
    arg0_00 = 0x8124efa;
  }
  else {
    arg0_00 = 0x8124f82;
  }
  uVar2 = Menu_ExpandListTemplate(arg0_00,0);
  BattleMenu_SetMode(3,uVar2);
  *(undefined2 *)(arg0 + 0x1e) = 0x100;
  return;
}


// sub_0812C180 @ 0x0812C180

void sub_0812C180(int arg0)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_030031b8 & 1) == 0) {
      if ((DAT_030031b8 & 0xf0) == 0) {
        return;
      }
      sub_080ECF70(100);
      return;
    }
    uVar2 = sub_080C8AF4(DAT_0203c24c);
    sVar1 = (short)(char)(&DAT_030050e0)[uVar2 & 0xffff];
    if ((sVar1 != -1) && (uVar3 = sub_080C0818((int)sVar1), (uVar3 & 0x8000) == 0)) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_080C8ADC(DAT_0203c24c,0);
      DAT_0203c891 = (undefined1)(uVar2 & 0xffff);
      *(ushort *)(arg0 + 0x1e) = (ushort)uVar2 & 0xff;
      DAT_030065c6 = sVar1;
      sub_080ECF70(0x65);
      return;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C8ADC(DAT_0203c24c,0);
  }
  sub_080ECF70(0x66);
  return;
}


// sub_0812C250 @ 0x0812C250

void sub_0812C250(void)

{
  sub_08128B84(1);
  sub_080EA964();
  if (DAT_0203c250 != 0) {
    sub_080AD1FC(DAT_0203c250);
  }
  return;
}


// sub_0812C274 @ 0x0812C274

void sub_0812C274(void)

{
  sub_0812C490(0,0);
  return;
}


// sub_0812C284 @ 0x0812C284

void sub_0812C284(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_0812C4D4();
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (uVar1 != 0xffffffff) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if ((uVar1 & 0xffff0000) == 0xfffe0000) {
      *(undefined2 *)(arg0 + 0x1e) = 0x100;
    }
    else {
      *(short *)(&DAT_0203d130 + DAT_030065c6 * 2) = (short)((uVar1 & 0xffff0000) >> 0x10);
      DAT_030065c2 = (undefined2)uVar1;
      DAT_030065c4 = 7;
    }
  }
  return;
}


// sub_0812C2E4 @ 0x0812C2E4

void sub_0812C2E4(int arg0)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  switch(*(undefined2 *)(arg0 + 0x1e)) {
  case 0:
    uVar3 = (uint)DAT_030065c2;
    sub_080EA210();
    if (1 < (uVar3 - 0x3e & 0xffff)) {
      *(undefined2 *)(arg0 + 0x1e) = 1;
      uVar2 = sub_080F2F64(DAT_030065c6 - 0x8000 & 0xffff);
      uVar2 = sub_080EAF1C(uVar2,uVar3);
      BattleMenu_SetMode(3,uVar2);
      return;
    }
    uVar1 = 6;
    break;
  case 1:
    iVar4 = sub_080EA934();
    if (iVar4 != 1) {
      return;
    }
    sub_080ED6DC((int)(short)DAT_030065c6,(int)(short)DAT_030065c2);
    sub_0812E780((int)(short)DAT_030065c6,&DAT_0203d130,0x8124d5e,0);
    sub_080F4410((int)(short)DAT_030065c6);
    *(undefined2 *)(arg0 + 0x1e) = 4;
    if (DAT_030065c0 == 0) {
      return;
    }
    *(undefined2 *)(arg0 + 0x1c) = 1;
    uVar1 = 0xff;
    break;
  default:
    goto switchD_0812c2fe_caseD_2;
  case 3:
    uVar3 = sub_08129440();
    uVar3 = uVar3 & 0xff;
    if (uVar3 == 0) {
      return;
    }
    if (uVar3 == 1) {
      *(undefined2 *)(arg0 + 0x1e) = 5;
      sub_080ED6DC((int)(short)DAT_030065c6,(int)(short)DAT_030065c2);
      return;
    }
    if (uVar3 != 0xff) {
      return;
    }
    uVar1 = 5;
    break;
  case 4:
    iVar4 = sub_080EA934();
    if (iVar4 != 1) {
      return;
    }
  case 5:
    sub_080EA528();
    if (DAT_030065c2 == 0x38) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined2 *)(arg0 + 0x1e) = 0xfe;
      sub_080C366C();
      Party_BuildMemberNameTiles();
      sub_080C6FD8();
      iVar4 = sub_080F3144();
      if (iVar4 == 0) {
        return;
      }
      sub_080B9058();
      *(undefined2 *)(arg0 + 0x1c) = 0;
      uVar1 = 2;
    }
    else {
      iVar4 = sub_080F3144();
      if (iVar4 == 0) {
        *(undefined2 *)(arg0 + 0x1c) = 1;
        *(undefined2 *)(arg0 + 0x1e) = 0;
        if (1 < (ushort)(DAT_030065c2 - 0x3e)) {
          return;
        }
        uVar1 = 0xfe;
      }
      else {
        sub_080B9058();
        *(undefined2 *)(arg0 + 0x1c) = 0;
        uVar1 = 2;
      }
    }
    break;
  case 6:
    sub_0812931C();
    sub_081293F8(2);
    uVar1 = 3;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar1;
switchD_0812c2fe_caseD_2:
  return;
}


// sub_0812C470 @ 0x0812C470

void sub_0812C470(void)

{
  sub_080EA964();
  if (DAT_0203c250 != 0) {
    sub_080AD1FC(DAT_0203c250);
  }
  sub_081269D0();
  return;
}


// sub_0812C490 @ 0x0812C490

void sub_0812C490(undefined4 arg0,undefined4 arg1)

{
  DAT_0203c248 = sub_080AD0FC(0x87799d0,0xffff);
  *(char *)(DAT_0203c248 + 0x24) = (char)arg0;
  *(undefined4 *)(DAT_0203c248 + 0x28) = 0xffffffff;
  if ((char)arg0 != '\0') {
    DAT_0203c891 = (undefined1)arg1;
  }
  return;
}


// sub_0812C4D4 @ 0x0812C4D4

undefined4 sub_0812C4D4(void)

{
  return *(undefined4 *)(DAT_0203c248 + 0x28);
}


// sub_0812C4E0 @ 0x0812C4E0

undefined4 sub_0812C4E0(undefined4 arg0,uint arg1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    if (*(ushort *)(uVar3 * 2 + 0x87799a8) == (ushort)arg0) {
      return 1;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (*(short *)(uVar3 * 2 + 0x87799a8) != -1);
  if (0x3f < (ushort)arg0) {
    iVar1 = sub_080BF648(arg1 & 0xffff);
    iVar2 = 0;
    do {
      if (((iVar2 == 6) && (*(byte *)(iVar1 + 0x17) == (ushort)arg0)) &&
         (*(char *)(iVar1 + 0x16) == -1)) {
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 7);
  }
  return 0;
}


// sub_0812C550 @ 0x0812C550

uint sub_0812C550(undefined4 arg0,int arg1)

{
  byte bVar1;
  bool bVar2;
  uint arg0_00;
  byte *pbVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  ushort *puVar9;
  uint local_28;
  
  uVar6 = arg1 * 0x10000 + 0x80000000;
  iVar7 = sub_080F2F64(uVar6 >> 0x10);
  puVar9 = &DAT_0203c4d0;
  local_28 = 0;
  bVar4 = 0xc0;
  if ((char)arg0 != '\0') {
    bVar4 = 0x20;
  }
  uVar5 = 0;
  bVar1 = *(byte *)(iVar7 + 0x5d);
  pbVar3 = (byte *)(iVar7 + 0x5e);
  while (arg0_00 = (uint)bVar1, arg0_00 != 0xff) {
    bVar2 = false;
    if ((char)arg0 == '\x02') {
      if (0x3f < arg0_00) {
        iVar7 = sub_080F2F64(uVar6 >> 0x10);
        iVar7 = sub_0812C4E0(arg0_00,(uint)*(ushort *)(iVar7 + 0x12));
        bVar2 = true;
        if (iVar7 == 0) goto LAB_0812c5ce;
      }
      bVar2 = false;
    }
    else if (arg0_00 < 0x40) {
      bVar2 = true;
    }
LAB_0812c5ce:
    pbVar8 = (byte *)sub_080BF5C0(arg0_00);
    if (((*pbVar8 & bVar4) != 0) && (bVar2)) {
      *puVar9 = (ushort)bVar1;
      puVar9 = puVar9 + 1;
      local_28 = local_28 + 1 & 0xffff;
    }
    uVar5 = uVar5 + 1;
    if (0x1f < uVar5) break;
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
  }
  *puVar9 = 0xffff;
  return local_28;
}


// sub_0812C624 @ 0x0812C624

void sub_0812C624(int arg0)

{
  uint uVar1;
  int iVar2;
  dword arg0_00;
  undefined4 uVar3;
  uint arg1;
  code *UNRECOVERED_JUMPTABLE;
  
  arg1 = (int)(char)(&DAT_030050e0)[DAT_0203c891] & 0xffff;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  uVar1 = sub_0812C550((uint)*(byte *)(arg0 + 0x24),arg1);
  uVar1 = uVar1 & 0xffff;
  if (uVar1 == 0) {
LAB_0812c69a:
    arg0_00 = 0x8124f46;
LAB_0812c69c:
    uVar3 = Menu_ExpandListTemplate(arg0_00,0);
    BattleMenu_SetMode(3,uVar3);
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  else {
    if (*(byte *)(arg0 + 0x24) != 2) {
      iVar2 = sub_080F31E0();
      if (iVar2 != 0) {
        arg0_00 = 0x8124f82;
        goto LAB_0812c69c;
      }
      iVar2 = sub_080F4410(arg1);
      if (iVar2 == 0) goto LAB_0812c69a;
      if (iVar2 == 1) {
        uVar3 = Menu_ExpandListTemplate(0x8124f60,arg1);
        BattleMenu_SetMode(3,uVar3);
        *(undefined2 *)(arg0 + 0x1e) = 1;
        goto LAB_0812c71a;
      }
    }
    DAT_0203c24c = sub_080ABC40(1,0,0x13,10);
    DAT_0203c250 = sub_080AB890(2,0xd,0x1a,6);
    sub_081272AC();
    if (uVar1 < 5) {
      sub_08126928(4,0,1,uVar1);
    }
    else {
      sub_08126928(4,0x10,1,uVar1);
    }
  }
LAB_0812c71a:
                    /* WARNING: Could not recover jumptable at 0x0812c724. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812C728 @ 0x0812C728

void sub_0812C728(int arg0)

{
  undefined4 uVar1;
  
  if (*(char *)(arg0 + 0x24) == '\x02') {
    uVar1 = Menu_ExpandListTemplate(0x8124570,0);
    BattleMenu_SetMode(4,uVar1);
  }
  else {
    uVar1 = Menu_ExpandListTemplate(0x8124f2c,0);
    BattleMenu_SetMode(4,uVar1);
  }
  return;
}


// sub_0812C760 @ 0x0812C760

void sub_0812C760(int arg0)

{
  byte bVar1;
  int iVar2;
  undefined4 arg1;
  
  iVar2 = sub_08126D1C(4);
  bVar1 = *(byte *)((int)&DAT_0203c4d0 + (uint)*(ushort *)(iVar2 + 0x12));
  if (*(char *)(arg0 + 0x24) == '\x02') {
    sub_08127EAC(8,(uint)*(ushort *)(iVar2 + 0xc));
  }
  else {
    sub_08127EAC(7,(uint)*(ushort *)(iVar2 + 0xc));
  }
  iVar2 = sub_080BF5C0((uint)bVar1);
  arg1 = Menu_ExpandListTemplate(*(undefined4 *)(iVar2 + 0x18),0);
  BattleMenu_SetMode(8,arg1);
  return;
}


// sub_0812C7B4 @ 0x0812C7B4

void sub_0812C7B4(int arg0)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 arg1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar5 = sub_08126D1C(4);
  bVar1 = *(byte *)(iVar5 + 0xc);
  bVar2 = *(byte *)(iVar5 + 0x12);
  sub_08126A08(4);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_030031b8 & 1) != 0) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      cVar4 = (&DAT_030050e0)[DAT_0203c891];
      uVar3 = *(ushort *)((uint)*(ushort *)(iVar5 + 0x12) * 2 + 0x203c4d0);
      iVar6 = (int)(short)uVar3;
      sub_080ED6CC(iVar6);
      sub_080F4070((int)cVar4 & 0xffffU);
      sub_080ED694(iVar6);
      iVar6 = sub_080ED744((int)cVar4 & 0xffffU,iVar6);
      if (iVar6 == 1) {
        *(char *)(arg0 + 0x2c) = (char)uVar3;
      }
      else {
        iVar6 = sub_08127E98((uint)uVar3);
        if (iVar6 == 1) {
          *(undefined2 *)(arg0 + 0x1e) = 2;
        }
        else {
          *(undefined2 *)(arg0 + 0x1e) = 1;
        }
      }
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  if ((ushort)bVar1 != *(ushort *)(iVar5 + 0xc)) {
    if (*(char *)(arg0 + 0x24) == '\x02') {
      sub_08127EAC(8,(uint)*(ushort *)(iVar5 + 0xc));
    }
    else {
      sub_08127EAC(7,(uint)*(ushort *)(iVar5 + 0xc));
    }
  }
  if ((ushort)bVar2 != *(ushort *)(iVar5 + 0x12)) {
    iVar6 = sub_080BF5C0((uint)*(ushort *)((uint)*(ushort *)(iVar5 + 0x12) * 2 + 0x203c4d0));
    arg1 = Menu_ExpandListTemplate(*(undefined4 *)(iVar6 + 0x18),0);
    BattleMenu_SetMode(8,arg1);
  }
  sub_080AA184(0x8000f8c,0,0,1);
  if (5 < *(ushort *)(iVar5 + 10)) {
    if (*(short *)(iVar5 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(iVar5 + 0xc) + 5 != (uint)*(ushort *)(iVar5 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0812c946. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812C958 @ 0x0812C958

void sub_0812C958(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080EC038(0x97);
  uVar1 = Menu_ExpandListTemplate(uVar1,0);
  BattleMenu_SetMode(3,uVar1);
  return;
}


// sub_0812C974 @ 0x0812C974

void sub_0812C974(void)

{
  BattleMenu_SetMode(3,0x81241e0);
  return;
}


// sub_0812C988 @ 0x0812C988

void sub_0812C988(void)

{
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  if (DAT_0203c250 != 0) {
    sub_080AB91C(DAT_0203c250,0);
  }
  sub_081269B0(4);
  sub_080EA528();
  sub_08128388();
  return;
}


// sub_0812C9BC @ 0x0812C9BC

void sub_0812C9BC(int arg0)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar3 = sub_080BF5C0((uint)*(byte *)(arg0 + 0x2c));
  *(undefined2 *)(arg0 + 0x1e) = 0;
  cVar1 = *(char *)(iVar3 + 2);
  if (((cVar1 == -0x80) || (cVar1 == -0x7e)) || (cVar1 == -0x7d)) {
    uVar2 = 1;
  }
  else {
    if ((cVar1 == '\x0f') || (cVar1 == -1)) goto LAB_0812c9ea;
    uVar2 = 2;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar2;
LAB_0812c9ea:
                    /* WARNING: Could not recover jumptable at 0x0812c9ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812C9F0 @ 0x0812C9F0

void sub_0812C9F0(int arg0)

{
  *(uint *)(arg0 + 0x28) = (uint)*(ushort *)(arg0 + 0x1e) * 0x10000 + (uint)*(byte *)(arg0 + 0x2c);
  return;
}


// sub_0812CA00 @ 0x0812CA00

void sub_0812CA00(int arg0)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080BF5C0((uint)*(byte *)(arg0 + 0x2c));
  uVar4 = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  bVar1 = *(byte *)(iVar2 + 2);
  if (bVar1 == 0x82) {
    if (*(char *)(DAT_0203c248 + 0x24) == '\x01') {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else if (bVar1 < 0x83) {
    if (bVar1 != 0x80) goto LAB_0812ca5c;
    if (*(char *)(DAT_0203c248 + 0x24) == '\x01') {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (bVar1 != 0x83) goto LAB_0812ca5c;
    uVar3 = 6;
  }
  uVar4 = sub_08127A98(uVar3);
  uVar4 = uVar4 & 0xffff;
LAB_0812ca5c:
  if (uVar4 != 0) {
    sub_080AD1FC(DAT_0203c24c);
    sub_080AD1FC(DAT_0203c250);
    DAT_0203c24c = sub_080ABC40(1,0,0xf,10);
    DAT_0203c250 = sub_080ABC40(0x11,0,0xc,6);
    sub_081272AC();
    if (uVar4 < 5) {
      sub_08126928(4,0,1,uVar4);
    }
    else {
      sub_08126928(4,0x10,1,uVar4);
    }
    *(undefined2 *)(arg0 + 0x1e) = 1;
    sub_080EA210();
    uVar3 = Menu_ExpandListTemplate(0x8124d72,0);
    BattleMenu_SetMode(4,uVar3);
  }
                    /* WARNING: Could not recover jumptable at 0x0812cad4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812CADC @ 0x0812CADC

void sub_0812CADC(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(4);
  sub_08127EAC(0,(uint)*(ushort *)(iVar1 + 0xc));
  sub_081283C4(0,(uint)*(ushort *)(iVar1 + 0x12));
  return;
}


// sub_0812CAFC @ 0x0812CAFC

void sub_0812CAFC(int arg0)

{
  byte bVar1;
  undefined2 uVar2;
  char *pcVar3;
  
  pcVar3 = (char *)sub_08126D1C(4);
  bVar1 = pcVar3[0x12];
  sub_08126A08(4);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if (*pcVar3 != '\x03') goto LAB_0812cb4e;
    uVar2 = (&DAT_0203c4d0)[*(ushort *)(pcVar3 + 0x12)];
  }
  else {
    uVar2 = 0x100;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar2;
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_0812cb4e:
  sub_080AA184(0x8000ea4,0,0,1);
  if (5 < *(ushort *)(pcVar3 + 10)) {
    if (*(short *)(pcVar3 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(pcVar3 + 0xc) + 5 != (uint)*(ushort *)(pcVar3 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
  if ((ushort)bVar1 != *(ushort *)(pcVar3 + 0x12)) {
    sub_08127EAC(0,(uint)*(ushort *)(pcVar3 + 0xc));
    sub_081283C4(0,(uint)*(ushort *)(pcVar3 + 0x12));
  }
  return;
}


// sub_0812CBDC @ 0x0812CBDC

void sub_0812CBDC(void)

{
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  if (DAT_0203c250 != 0) {
    sub_080ABD30(DAT_0203c250,0);
  }
  sub_081269B0(4);
  sub_080EA528();
  sub_08128388();
  return;
}


// sub_0812CC10 @ 0x0812CC10

void sub_0812CC10(int arg0)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = sub_080E6E08();
  cVar1 = (&DAT_030050e0)[DAT_0203c891];
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((short)uVar2 == 2) {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else if ((short)uVar2 == 3) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    uVar2 = sub_080EDA64((int)cVar1 & 0xffff);
    *(short *)(arg0 + 0x1e) = (short)uVar2;
  }
  return;
}


// sub_0812CC70 @ 0x0812CC70

void sub_0812CC70(undefined4 arg0)

{
  DAT_0203c248 = sub_080AD0FC(0x8779ca4,0xffff);
  DAT_0203c894 = (undefined1)arg0;
  return;
}


// sub_0812CCA0 @ 0x0812CCA0

void sub_0812CCA0(void)

{
  uint uVar1;
  
  DAT_0203c24c = sub_080ABC40(1,0,0xf,10);
  DAT_0203c250 = sub_080ABC40(0x11,0,0xc,6);
  sub_081272AC();
  uVar1 = sub_08127A98(0);
  uVar1 = uVar1 & 0xffff;
  if (uVar1 < 5) {
    sub_08126928(2,0,1,uVar1);
  }
  else {
    sub_08126928(2,0x10,1,uVar1);
  }
  sub_08127960(2,(uint)DAT_0203c894);
  sub_080EA210();
  BattleMenu_SetMode(4,0x8123df0);
  return;
}


// sub_0812CD24 @ 0x0812CD24

void sub_0812CD24(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(2);
  sub_08127EAC(0,(uint)*(ushort *)(iVar1 + 0xc));
  sub_081283C4(0,(uint)*(ushort *)(iVar1 + 0x12));
  return;
}


// sub_0812CD44 @ 0x0812CD44

void sub_0812CD44(int arg0)

{
  byte bVar1;
  char *pcVar2;
  
  pcVar2 = (char *)sub_08126D1C(2);
  bVar1 = pcVar2[0x12];
  sub_08126A08(2);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if (*pcVar2 != '\x03') goto LAB_0812cd88;
    *(ushort *)(arg0 + 0x1e) = DAT_030031b8 & 2;
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
  }
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_0812cd88:
  sub_080AA184(0x8000ea4,0,0,1);
  if (5 < *(ushort *)(pcVar2 + 10)) {
    if (*(short *)(pcVar2 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(pcVar2 + 0xc) + 5 != (uint)*(ushort *)(pcVar2 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
  if ((ushort)bVar1 != *(ushort *)(pcVar2 + 0x12)) {
    sub_08127EAC(0,(uint)*(ushort *)(pcVar2 + 0xc));
    sub_081283C4(0,(uint)*(ushort *)(pcVar2 + 0x12));
  }
  return;
}


// sub_0812CE18 @ 0x0812CE18

void sub_0812CE18(void)

{
  sub_08128B84(1);
  sub_081269B0(2);
  return;
}


// sub_0812CE2C @ 0x0812CE2C

void sub_0812CE2C(void)

{
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  if (DAT_0203c250 != 0) {
    sub_080ABD30(DAT_0203c250,0);
  }
  sub_08128388();
  sub_080EA964();
  return;
}


// sub_0812CE5C @ 0x0812CE5C

void sub_0812CE5C(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(2);
  sub_080CAFD0(0,(uint)*(ushort *)(iVar1 + 0x12));
  sub_081269B0(2);
  return;
}


// sub_0812CE78 @ 0x0812CE78

void sub_0812CE78(void)

{
  DAT_0203c248 = sub_080AD0FC(0x8779db8,0xffff);
  DAT_0203c250 = 0;
  DAT_0203c24c = 0;
  DAT_0203c891 = 1;
  return;
}


// sub_0812CEAC @ 0x0812CEAC

void sub_0812CEAC(void)

{
  BattleMenu_SetMode(4,0x8124198);
  DAT_0203c24c = sub_080C8AAC(0,(uint)DAT_0203c891);
  sub_080C8ADC(DAT_0203c24c,1);
  DAT_0203c250 = 0;
  return;
}


// sub_0812CEE4 @ 0x0812CEE4

void sub_0812CEE4(void)

{
  sub_080EA210();
  return;
}


// sub_0812CEF0 @ 0x0812CEF0

void sub_0812CEF0(void)

{
  DAT_0203c24c = sub_080C8AAC(0,(uint)DAT_0203c891);
  DAT_0203c250 = sub_080C8AC4(1,(uint)DAT_0203c891);
  sub_080C8ADC(DAT_0203c24c,1);
  sub_080C8ADC(DAT_0203c250,1);
  return;
}


// sub_0812CF2C @ 0x0812CF2C

void sub_0812CF2C(int arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_030031b8 & 1) == 0) {
      if ((DAT_030031b8 & 0xf0) != 0) {
        sub_080ECF70(100);
      }
      goto LAB_0812cfca;
    }
    uVar1 = sub_080C8AF4(DAT_0203c24c);
    if ((&DAT_030050e0)[uVar1 & 0xffff] != -1) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_080C8ADC(DAT_0203c24c,0);
      DAT_0203c891 = (undefined1)(uVar1 & 0xffff);
      *(ushort *)(arg0 + 0x1e) = (ushort)uVar1 & 0xff;
      sub_080ECF70(0x65);
      goto LAB_0812cfca;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C8ADC(DAT_0203c24c,0);
  }
  sub_080ECF70(0x66);
LAB_0812cfca:
                    /* WARNING: Could not recover jumptable at 0x0812cfce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812CFD0 @ 0x0812CFD0

void sub_0812CFD0(int arg0)

{
  undefined4 uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_030031b8 & 1) == 0) {
      if ((DAT_030031b8 & 0xf0) != 0) {
        sub_080ECF70(100);
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_080C8ADC(DAT_0203c24c,0);
      sub_080C8ADC(DAT_0203c250,0);
      uVar1 = sub_080C8AF4(DAT_0203c24c);
      *(short *)(arg0 + 0x1e) = (short)uVar1;
      DAT_0203c892 = (undefined1)uVar1;
      sub_080ECF70(0x65);
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C8ADC(DAT_0203c24c,0);
    sub_080C8ADC(DAT_0203c250,0);
    sub_080ECF70(0x66);
  }
  return;
}


// sub_0812D064 @ 0x0812D064

void sub_0812D064(void)

{
  if (DAT_0203c24c != 0) {
    sub_080AD1FC(DAT_0203c24c);
    DAT_0203c24c = 0;
  }
  if (DAT_0203c250 != 0) {
    sub_080AD1FC(DAT_0203c250);
    DAT_0203c250 = 0;
  }
  sub_08128B84(1);
  sub_080EA964();
  return;
}


// sub_0812D098 @ 0x0812D098

void sub_0812D098(void)

{
  if (DAT_0203c250 != 0) {
    sub_080AD1FC(DAT_0203c250);
    DAT_0203c250 = 0;
  }
  return;
}


// sub_0812D0B4 @ 0x0812D0B4

void sub_0812D0B4(void)

{
  if (DAT_0203c24c != 0) {
    sub_080AD1FC(DAT_0203c24c);
    DAT_0203c24c = 0;
  }
  if (DAT_0203c250 != 0) {
    sub_080AD1FC(DAT_0203c250);
    DAT_0203c250 = 0;
  }
  sub_080C363C((uint)DAT_0203c891,(uint)DAT_0203c892);
  sub_080C366C();
  return;
}


// sub_0812D0FC @ 0x0812D0FC

void sub_0812D0FC(undefined4 arg0)

{
  if ((char)arg0 == '\0') {
    sub_080C6FF0();
    sub_080C7414();
    sub_080C7218();
  }
  DAT_0203c240 = sub_080AD0FC(0x8779ec4,0xffff);
  return;
}


// sub_0812D130 @ 0x0812D130

void sub_0812D130(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x840000c0;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_0812D168 @ 0x0812D168

void sub_0812D168(void)

{
  DAT_0203c24c = sub_080ABC40(0xb,1,8,6);
  sub_080C7E24(0x30000b4,0x8779e9c);
  DisplayList_Add(0x812d131,1);
  sub_08126928(0,1,1,3);
  return;
}


// sub_0812D1B8 @ 0x0812D1B8

void sub_0812D1B8(int arg0)

{
  short sVar1;
  undefined2 uVar2;
  char *pcVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar3 = (char *)sub_08126D1C(0);
  sVar1 = *(short *)(pcVar3 + 0x18);
  sub_08126A08(0);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if (*pcVar3 == '\x06') {
        if (DAT_0203c9e0 == '\x04') {
          sub_080EA528();
          sub_080EA964();
        }
        else {
          sub_080EA210();
          BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar3 + 0x18) * 4 + 0x8779eb8));
        }
      }
      else if ((sVar1 != *(short *)(pcVar3 + 0x18)) && (DAT_0203c9e0 == '\x04')) {
        BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar3 + 0x18) * 4 + 0x8779eb8));
      }
      goto LAB_0812d262;
    }
    uVar2 = 0xff;
  }
  else {
    uVar2 = *(undefined2 *)(pcVar3 + 0x18);
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar2;
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_0812d262:
  sub_080AA184(0x8000f28,0,0,0);
  uVar4 = 0;
  do {
    sub_080AA1F4(uVar4 * 0x10 + 0x8777f60,0,0,0);
    sub_080AA1F4(&DAT_08777f68 + uVar4 * 0x10,0,0,0);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 3);
                    /* WARNING: Could not recover jumptable at 0x0812d2e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812D2F8 @ 0x0812D2F8

void sub_0812D2F8(void)

{
  sub_081269B0(0);
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  if (DAT_0203c9e0 == '\x04') {
    sub_080EA964();
  }
  return;
}


// sub_0812D328 @ 0x0812D328

void sub_0812D328(void)

{
  sub_081279D4();
  if (DAT_03004550 == 0x1b) {
    Field_SetState(0x1e);
    DAT_0300456e = 0;
  }
  else {
    Field_SetState(1);
  }
  sub_080C700C();
  sub_080C7430();
  sub_080C7234();
  return;
}


// sub_0812D360 @ 0x0812D360

void sub_0812D360(int arg0)

{
  ushort uVar1;
  undefined4 arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = *(ushort *)(arg0 + 0x1e);
  if (uVar1 == 1) {
    arg0_00 = 0;
  }
  else {
    if (1 < uVar1) {
      if (uVar1 == 2) {
        sub_080CFFE0(1);
      }
      goto LAB_0812d38c;
    }
    if (uVar1 != 0) goto LAB_0812d38c;
    arg0_00 = 2;
  }
  sub_080D110C(arg0_00,1);
LAB_0812d38c:
                    /* WARNING: Could not recover jumptable at 0x0812d38e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812D390 @ 0x0812D390

void sub_0812D390(void)

{
  DAT_0203c248 = sub_080AD0FC(0x877a078,0xffff);
  *(undefined1 *)(DAT_0203c248 + 0x24) = 0;
  return;
}


// sub_0812D3B8 @ 0x0812D3B8

void sub_0812D3B8(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000180;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_0812D3F0 @ 0x0812D3F0

void sub_0812D3F0(void)

{
  DAT_0203c24c = sub_080ABC40(8,1,0xe,6);
  sub_080C7E24(0x30000b4,0x8779fd0);
  DisplayList_Add(0x812d3b9,1);
  sub_08126928(3,1,1,3);
  BattleMenu_SetMode(3,0x81232ae);
  sub_080EC99C(1);
  return;
}


// sub_0812D450 @ 0x0812D450

void sub_0812D450(int arg0)

{
  short sVar1;
  undefined2 uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar3 = (char *)sub_08126D1C(3);
  sVar1 = *(short *)(pcVar3 + 0x18);
  sub_08126A08(3);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if (*pcVar3 == '\x06') {
        if (DAT_0203c9e0 == '\x04') {
          BattleMenu_SetMode(3,0x81232ae);
        }
        else {
          BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar3 + 0x18) * 4 + 0x877a004));
        }
      }
      else if ((sVar1 != *(short *)(pcVar3 + 0x18)) && (DAT_0203c9e0 == '\x04')) {
        BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar3 + 0x18) * 4 + 0x877a004));
      }
      goto LAB_0812d4fe;
    }
    uVar2 = 0xff;
  }
  else {
    uVar2 = *(undefined2 *)(pcVar3 + 0x18);
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar2;
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_0812d4fe:
  sub_080AA184(0x8000e28,0,0,0);
  uVar5 = 0;
  do {
    iVar4 = uVar5 * 0x20;
    sub_080AA1F4(iVar4 + 0x8777f60,0,0,0);
    sub_080AA1F4(&DAT_08777f68 + iVar4,0,0,0);
    sub_080AA1F4(&DAT_08777f70 + iVar4,0,0,0);
    sub_080AA1F4(&DAT_08777f78 + iVar4,0,0,0);
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 3);
                    /* WARNING: Could not recover jumptable at 0x0812d5ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812D5C8 @ 0x0812D5C8

void sub_0812D5C8(void)

{
  sub_081269B0(3);
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  sub_080EA528();
  return;
}


// sub_0812D5EC @ 0x0812D5EC

void sub_0812D5EC(void)

{
  *(undefined1 *)(DAT_0203c248 + 0x24) = 1;
  return;
}


// sub_0812D5FC @ 0x0812D5FC

uint sub_0812D5FC(void)

{
  return (uint)*(byte *)(DAT_0203c248 + 0x24);
}


// sub_0812D60C @ 0x0812D60C

void sub_0812D60C(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000040;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_0812D644 @ 0x0812D644

void sub_0812D644(void)

{
  uint uVar1;
  
  DAT_0203c24c = sub_080ABC40(0xc,1,6,4);
  sub_080C7E24(0x30000b4,0x877a010);
  DisplayList_Add(0x812d60d,1);
  sub_08126928(3,1,1,2);
  uVar1 = sub_080C2B6C();
  sub_08127960(3,uVar1 & 0xffff);
  BattleMenu_SetMode(3,0x8123374);
  sub_080EC99C(1);
  return;
}


// sub_0812D6B8 @ 0x0812D6B8

void sub_0812D6B8(int arg0)

{
  short sVar1;
  char *pcVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar2 = (char *)sub_08126D1C(3);
  sVar1 = *(short *)(pcVar2 + 0x18);
  sub_08126A08(3);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if (*pcVar2 == '\x06') {
        if (DAT_0203c9e0 == '\x04') {
          BattleMenu_SetMode(3,0x8123374);
          sub_080EC99C(1);
        }
        else {
          BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar2 + 0x18) * 4 + 0x877a01c));
        }
      }
      else if ((sVar1 != *(short *)(pcVar2 + 0x18)) && (DAT_0203c9e0 == '\x04')) {
        BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar2 + 0x18) * 4 + 0x877a01c));
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 0xff;
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = *(undefined2 *)(pcVar2 + 0x18);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C2B84((uint)*(ushort *)((uint)*(ushort *)(pcVar2 + 0x18) * 2 + 0x877a024));
  }
  sub_080AA184(0x8000f00,0,0,0);
  sub_080AA1F4(0x8777f60,0,0,0);
  sub_080AA1F4(&DAT_08777f68,0,0,0);
                    /* WARNING: Could not recover jumptable at 0x0812d7d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812D7E4 @ 0x0812D7E4

void sub_0812D7E4(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000080;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_0812D81C @ 0x0812D81C

void sub_0812D81C(void)

{
  uint uVar1;
  
  DAT_0203c24c = sub_080ABC40(0xb,1,8,4);
  sub_080C7E24(0x30000b4,0x877a028);
  DisplayList_Add(0x812d7e5,1);
  sub_08126928(3,1,1,2);
  uVar1 = Settings_GetBattleMsgSpeed();
  sub_08127960(3,uVar1 & 0xffff);
  BattleMenu_SetMode(3,0x81233d2);
  sub_080EC99C(1);
  return;
}


// sub_0812D890 @ 0x0812D890

void sub_0812D890(int arg0)

{
  short sVar1;
  char *pcVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar2 = (char *)sub_08126D1C(3);
  sVar1 = *(short *)(pcVar2 + 0x18);
  sub_08126A08(3);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if (*pcVar2 == '\x06') {
        if (DAT_0203c9e0 == '\x04') {
          BattleMenu_SetMode(3,0x81233d2);
          sub_080EC99C(1);
        }
        else {
          BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar2 + 0x18) * 4 + 0x877a03c));
        }
      }
      else if ((sVar1 != *(short *)(pcVar2 + 0x18)) && (DAT_0203c9e0 == '\x04')) {
        BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar2 + 0x18) * 4 + 0x877a03c));
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 0xff;
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = *(undefined2 *)(pcVar2 + 0x18);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C2B4C((uint)*(ushort *)((uint)*(ushort *)(pcVar2 + 0x18) * 2 + 0x877a044));
  }
  sub_080AA184(0x8000f28,0,0,0);
  uVar3 = 0;
  do {
    sub_080AA1F4(uVar3 * 0x10 + 0x8777f60,0,0,0);
    sub_080AA1F4(&DAT_08777f68 + uVar3 * 0x10,0,0,0);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 2);
                    /* WARNING: Could not recover jumptable at 0x0812d9dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812D9EC @ 0x0812D9EC

void sub_0812D9EC(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x840000c0;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_0812DA24 @ 0x0812DA24

void sub_0812DA24(void)

{
  uint uVar1;
  
  DAT_0203c24c = sub_080ABC40(0xb,1,8,6);
  sub_080C7E24(0x30000b4,0x877a048);
  DisplayList_Add(0x812d9ed,1);
  sub_08126928(3,1,1,3);
  uVar1 = sub_080C2BA4();
  sub_08127960(3,uVar1 & 0xffff);
  BattleMenu_SetMode(3,0x8123444);
  sub_080EC99C(1);
  return;
}


// sub_0812DA94 @ 0x0812DA94

void sub_0812DA94(int arg0)

{
  short sVar1;
  char *pcVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar2 = (char *)sub_08126D1C(3);
  sVar1 = *(short *)(pcVar2 + 0x18);
  sub_08126A08(3);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if (*pcVar2 == '\x06') {
        if (DAT_0203c9e0 == '\x04') {
          BattleMenu_SetMode(3,0x8123444);
          sub_080EC99C(1);
        }
        else {
          BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar2 + 0x18) * 4 + 0x877a064));
        }
      }
      else if ((sVar1 != *(short *)(pcVar2 + 0x18)) && (DAT_0203c9e0 == '\x04')) {
        BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar2 + 0x18) * 4 + 0x877a064));
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 0xff;
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = *(undefined2 *)(pcVar2 + 0x18);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C2BCC((uint)*(ushort *)((uint)*(ushort *)(pcVar2 + 0x18) * 2 + 0x877a070));
  }
  sub_080AA184(0x8000f28,0,0,0);
  uVar3 = 0;
  do {
    sub_080AA1F4(uVar3 * 0x10 + 0x8777f60,0,0,0);
    sub_080AA1F4(&DAT_08777f68 + uVar3 * 0x10,0,0,0);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 3);
                    /* WARNING: Could not recover jumptable at 0x0812dbe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812DBF0 @ 0x0812DBF0

undefined2 * sub_0812DBF0(void)

{
  return &DAT_0203c4d0;
}


// sub_0812DC00 @ 0x0812DC00

undefined * sub_0812DC00(void)

{
  return &DAT_0203c4ec;
}


// sub_0812DC10 @ 0x0812DC10

uint sub_0812DC10(void)

{
  return (uint)DAT_0203c892;
}


// sub_0812DC24 @ 0x0812DC24

void sub_0812DC24(void)

{
  DAT_0203c248 = sub_080AD0FC(0x877a310,0xffff);
  DAT_0203c892 = 0xfe;
  return;
}


// sub_0812DC50 @ 0x0812DC50

void sub_0812DC50(void)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  uint arg3;
  
  DAT_0203c24c = sub_080ABC40(1,0,0xf,10);
  DAT_0203c250 = sub_080ABC40(0x11,0,0xc,6);
  sub_081272AC();
  arg3 = 0;
  psVar2 = &DAT_0203c4d2;
  sVar1 = DAT_0203c4d0;
  while (sVar1 != -1) {
    arg3 = arg3 + 1 & 0xffff;
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  }
  if (arg3 < 5) {
    sub_08126928(2,0,1,arg3);
  }
  else {
    sub_08126928(2,0x10,1,arg3);
  }
  iVar3 = sub_08126D1C(2);
  *(undefined2 *)(iVar3 + 0x1e) = 0xffff;
  return;
}


// sub_0812DCE0 @ 0x0812DCE0

void sub_0812DCE0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = sub_08126D1C(2);
  sub_08127EAC(0,(uint)*(ushort *)(iVar1 + 0xc));
  sub_081283C4(0,(uint)*(ushort *)(iVar1 + 0x12));
  puVar2 = (undefined4 *)sub_0812DC00();
  sub_080D3654(2,*puVar2);
  return;
}


// sub_0812DD0C @ 0x0812DD0C

void sub_0812DD0C(int arg0)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar4 = (char *)sub_08126D1C(2);
  bVar1 = pcVar4[0x12];
  sub_08126A08(2);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if (*pcVar4 != '\x03') goto LAB_0812dd70;
    iVar6 = sub_0812DC00();
    uVar2 = *(ushort *)(pcVar4 + 0x12);
    uVar5 = sub_080C3100();
    if (uVar5 < *(uint *)((uint)uVar2 * 4 + iVar6)) {
      sub_080ECF70(0x66);
    }
    else {
      sub_080ECF70(0xe7);
    }
    uVar3 = *(undefined2 *)(pcVar4 + 0x12);
  }
  else {
    uVar3 = 0x100;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar3;
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_0812dd70:
  sub_080AA184(0x8000ea4,0,0,1);
  if (5 < *(ushort *)(pcVar4 + 10)) {
    if (*(short *)(pcVar4 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(pcVar4 + 0xc) + 5 != (uint)*(ushort *)(pcVar4 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
  if ((ushort)bVar1 != *(ushort *)(pcVar4 + 0x12)) {
    iVar6 = sub_0812DC00();
    sub_080D367C(*(undefined4 *)((uint)*(ushort *)(pcVar4 + 0x12) * 4 + iVar6));
    sub_08127EAC(0,(uint)*(ushort *)(pcVar4 + 0xc));
    sub_081283C4(0,(uint)*(ushort *)(pcVar4 + 0x12));
  }
                    /* WARNING: Could not recover jumptable at 0x0812de00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812DE10 @ 0x0812DE10

void sub_0812DE10(void)

{
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  if (DAT_0203c250 != 0) {
    sub_080ABD30(DAT_0203c250,0);
  }
  sub_08128388();
  sub_080D3688();
  return;
}


// sub_0812DE40 @ 0x0812DE40

void sub_0812DE40(int arg0)

{
  if (*(short *)(arg0 + 0x1e) == 0x100) {
    DAT_0203c892 = 0xff;
  }
  else {
    DAT_0203c892 = (undefined1)(&DAT_0203c4d0)[*(ushort *)(arg0 + 0x1e)];
  }
  sub_081269B0(2);
  return;
}


// sub_0812DE88 @ 0x0812DE88

void sub_0812DE88(void)

{
  DAT_0203c248 = sub_080AD0FC(0x877a3b4,0xffff);
  DAT_0203c892 = 0xfe;
  return;
}


// sub_0812DEB4 @ 0x0812DEB4

void sub_0812DEB4(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(2);
  sub_08127EAC(0,(uint)*(ushort *)(iVar1 + 0xc));
  sub_081283C4(0,(uint)*(ushort *)(iVar1 + 0x12));
  return;
}


// sub_0812DED4 @ 0x0812DED4

void sub_0812DED4(int arg0)

{
  byte bVar1;
  undefined2 uVar2;
  char *pcVar3;
  
  pcVar3 = (char *)sub_08126D1C(2);
  bVar1 = pcVar3[0x12];
  sub_08126A08(2);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if (*pcVar3 != '\x03') goto LAB_0812df16;
    uVar2 = *(undefined2 *)(pcVar3 + 0x12);
  }
  else {
    uVar2 = 0x100;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar2;
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_0812df16:
  sub_080AA184(0x8000ea4,0,0,1);
  if (5 < *(ushort *)(pcVar3 + 10)) {
    if (*(short *)(pcVar3 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(pcVar3 + 0xc) + 5 != (uint)*(ushort *)(pcVar3 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
  if ((ushort)bVar1 != *(ushort *)(pcVar3 + 0x12)) {
    sub_0812DC00();
    sub_08127EAC(0,(uint)*(ushort *)(pcVar3 + 0xc));
    sub_081283C4(0,(uint)*(ushort *)(pcVar3 + 0x12));
  }
  return;
}


// sub_0812DFA8 @ 0x0812DFA8

void sub_0812DFA8(void)

{
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  if (DAT_0203c250 != 0) {
    sub_080ABD30(DAT_0203c250,0);
  }
  sub_08128388();
  return;
}


// sub_0812DFD4 @ 0x0812DFD4

void sub_0812DFD4(void)

{
  short sVar1;
  short *psVar2;
  uint arg3;
  
  DAT_0203c24c = sub_080ABC40(1,0,0xf,10);
  DAT_0203c250 = sub_080ABC40(0x11,0,0xc,6);
  sub_081272AC();
  arg3 = 0;
  psVar2 = &DAT_0203c4d2;
  sVar1 = DAT_0203c4d0;
  while (sVar1 != -1) {
    arg3 = arg3 + 1 & 0xffff;
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  }
  if (arg3 < 5) {
    sub_08126928(2,0,1,arg3);
  }
  else {
    sub_08126928(2,0x10,1,arg3);
  }
  sub_08126D1C(2);
  return;
}


// sub_0812E05C @ 0x0812E05C

void sub_0812E05C(void)

{
  DAT_0203c248 = sub_080AD0FC(0x877a458,0xffff);
  DAT_0203c892 = 0xfe;
  return;
}


// sub_0812E088 @ 0x0812E088

void sub_0812E088(void)

{
  return;
}


// sub_0812E0BC @ 0x0812E0BC

void sub_0812E0BC(void)

{
  short sVar1;
  short *psVar2;
  uint arg3;
  
  DAT_0203c24c = sub_080ABC40(1,0,0xf,10);
  DAT_0203c250 = 0;
  sub_081272AC();
  arg3 = 0;
  psVar2 = &DAT_0203c4d2;
  sVar1 = DAT_0203c4d0;
  while (sVar1 != -1) {
    arg3 = arg3 + 1 & 0xffff;
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  }
  if (arg3 < 5) {
    sub_08126928(2,0,1,arg3);
  }
  else {
    sub_08126928(2,0x10,1,arg3);
  }
  return;
}


// sub_0812E134 @ 0x0812E134

void sub_0812E134(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(2);
  sub_08127EAC(1,(uint)*(ushort *)(iVar1 + 0xc));
  return;
}


// sub_0812E148 @ 0x0812E148

void sub_0812E148(int arg0)

{
  byte bVar1;
  undefined2 uVar2;
  char *pcVar3;
  
  pcVar3 = (char *)sub_08126D1C(2);
  bVar1 = pcVar3[0x12];
  sub_08126A08(2);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if (*pcVar3 != '\x03') goto LAB_0812e18a;
    uVar2 = *(undefined2 *)(pcVar3 + 0x12);
  }
  else {
    uVar2 = 0x100;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar2;
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_0812e18a:
  sub_080AA184(0x8000ea4,0,0,1);
  if (5 < *(ushort *)(pcVar3 + 10)) {
    if (*(short *)(pcVar3 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(pcVar3 + 0xc) + 5 != (uint)*(ushort *)(pcVar3 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
  if ((ushort)bVar1 != *(ushort *)(pcVar3 + 0x12)) {
    sub_08127EAC(1,(uint)*(ushort *)(pcVar3 + 0xc));
  }
  return;
}


// sub_0812E210 @ 0x0812E210

void sub_0812E210(int arg0)

{
  if (*(short *)(arg0 + 0x1e) == 0x100) {
    DAT_0203c892 = 0xff;
  }
  else {
    DAT_0203c892 = (undefined1)*(short *)(arg0 + 0x1e);
  }
  sub_081269B0(2);
  return;
}


// sub_0812E244 @ 0x0812E244

void sub_0812E244(int arg0)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_030065cd == 1) {
    uVar3 = sub_0812E2FC();
    if ((uVar3 & 0xffff) == 0) {
      uVar2 = Menu_ExpandListTemplate(0x8124534,0);
      BattleMenu_SetMode(3,uVar2);
    }
    else {
      sub_080C84A0();
      uVar2 = sub_080EC038(0xd7);
      uVar2 = Menu_ExpandListTemplate(uVar2,0);
      BattleMenu_SetMode(3,uVar2);
      sub_080ECF70(0xe7);
    }
    DAT_030065cd = 2;
  }
  else if (DAT_030065cd < 2) {
    if (DAT_030065cd == 0) {
      uVar3 = 0;
      do {
        arg0_00 = (int)(short)uVar3;
        iVar1 = sub_080C09B0(arg0_00);
        if (iVar1 != 0) {
          sub_080F4260(arg0_00);
        }
        uVar3 = arg0_00 + 1U & 0xffff;
      } while ((int)((arg0_00 + 1U) * 0x10000) >> 0x10 < 4);
      DAT_030065cd = 1;
    }
  }
  else if (DAT_030065cd == 2) {
    iVar1 = sub_080EA934();
    if (iVar1 == 1) {
      sub_080EA528();
      sub_080EA964();
      DAT_030065cd = 3;
    }
  }
  else if (DAT_030065cd == 3) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0812e2fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812E2FC @ 0x0812E2FC

int sub_0812E2FC(void)

{
  int iVar1;
  
  DAT_030020b4 = 0;
  do {
    iVar1 = sub_0812E3C4();
    if (iVar1 < 0) break;
    iVar1 = sub_0812E4C0(iVar1);
  } while (iVar1 != 0);
  do {
    iVar1 = sub_0812E334();
    if (iVar1 < 0) break;
    iVar1 = sub_0812E400(iVar1);
  } while (iVar1 != 0);
  return (int)DAT_030020b4;
}


// sub_0812E334 @ 0x0812E334

undefined4 sub_0812E334(void)

{
  int iVar1;
  dword dVar2;
  int arg0;
  
  dVar2 = 0x30046c0;
  arg0 = 0;
  while (((iVar1 = sub_080F3EC8(arg0), iVar1 == 0 || ((*(ushort *)(dVar2 + 0x10) & 0x8000) != 0)) ||
         (*(short *)(dVar2 + 0x1a) <= *(short *)(dVar2 + 0x18)))) {
    arg0 = arg0 + 1;
    dVar2 = dVar2 + 0x80;
    if (0xf < arg0) {
      return 0xffffffff;
    }
  }
  return arg0;
}


// sub_0812E37C @ 0x0812E37C

void sub_0812E37C(void)

{
  int iVar1;
  dword dVar2;
  int arg0;
  
  dVar2 = 0x30046c0;
  arg0 = 0;
  while (((iVar1 = sub_080F3EC8(arg0), iVar1 == 0 || ((*(ushort *)(dVar2 + 0x10) & 0x8000) != 0)) ||
         (*(short *)(dVar2 + 0x1e) <= *(short *)(dVar2 + 0x1c)))) {
    arg0 = arg0 + 1;
    dVar2 = dVar2 + 0x80;
    if (0xf < arg0) {
      return;
    }
  }
  return;
}


// sub_0812E3C4 @ 0x0812E3C4

undefined4 sub_0812E3C4(void)

{
  int iVar1;
  int arg0;
  dword dVar2;
  
  dVar2 = 0x30046c0;
  arg0 = 0;
  while ((iVar1 = sub_080F3EC8(arg0), iVar1 == 0 ||
         ((*(ushort *)(dVar2 + 0x10) & (ushort)0xb3fe) == 0))) {
    arg0 = arg0 + 1;
    dVar2 = dVar2 + 0x80;
    if (0xf < arg0) {
      return 0xffffffff;
    }
  }
  return arg0;
}


// sub_0812E400 @ 0x0812E400

undefined4 sub_0812E400(undefined4 arg0)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2C30();
  if ((uVar1 & 0xffff) == 0) {
    for (pbVar4 = (byte *)0x877a4fc; *pbVar4 != 0xff; pbVar4 = pbVar4 + 1) {
      iVar2 = sub_080C10B4((uint)*pbVar4);
      if (iVar2 != 0) {
        sub_0812E6C4((int)(short)arg0,0,(uint)*pbVar4);
        uVar3 = 1;
        goto LAB_0812e476;
      }
    }
  }
  iVar2 = sub_080F31E0();
  if (iVar2 == 0) {
    for (pbVar4 = (byte *)0x877a502; *pbVar4 != 0xff; pbVar4 = pbVar4 + 1) {
      iVar2 = sub_0812E558((uint)*pbVar4);
      if (-1 < iVar2) {
        sub_0812E688((int)(short)arg0,(int)(short)iVar2,(uint)*pbVar4);
        uVar3 = 1;
        goto LAB_0812e476;
      }
    }
  }
  uVar3 = 0;
LAB_0812e476:
                    /* WARNING: Could not recover jumptable at 0x0812e47a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar3);
  return uVar3;
}


