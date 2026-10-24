/* Ghidra decompilation of asm/code_08129D08.s (reference only; not compiled). */

// sub_08129D08 @ 0x08129D08

void sub_08129D08(int arg0)

{
  undefined4 uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203c894 == '\x02') {
    uVar1 = sub_080F2F64(DAT_030065c6 - 0x8000 & 0xffff);
    uVar1 = sub_080EAF1C(uVar1,(uint)DAT_030065c2);
    BattleMenu_SetMode(3,uVar1);
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_08129D58 @ 0x08129D58

void sub_08129D58(void)

{
  DAT_0203c248 = sub_080AD0FC(0x87784cc,0xffff);
  return;
}


// sub_08129D78 @ 0x08129D78

void sub_08129D78(int arg0)

{
  uint uVar1;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  sub_080EA210();
  uVar1 = sub_08127A98(3);
  if ((uVar1 & 0xffff) == 0) {
    BattleMenu_SetMode(3,0x812416c);
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  else {
    DAT_0203c24c = sub_080ABC40(1,0,0xf,10);
    DAT_0203c250 = sub_080ABC40(0x11,0,0xc,6);
    sub_081272AC();
    sub_08126928(2,0,1,uVar1 & 0xffff);
    BattleMenu_SetMode(4,0x8124154);
  }
  return;
}


// sub_08129DF4 @ 0x08129DF4

void sub_08129DF4(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(2);
  sub_08127EAC(0,(uint)*(ushort *)(iVar1 + 0xc));
  sub_081283C4(0,(uint)*(ushort *)(iVar1 + 0x12));
  return;
}


// sub_08129E14 @ 0x08129E14

void sub_08129E14(int arg0)

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
    if (*pcVar3 != '\x03') goto LAB_08129e56;
    uVar2 = *(undefined2 *)(pcVar3 + 0x12);
  }
  else {
    uVar2 = 0x100;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar2;
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_08129e56:
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


// sub_08129EE4 @ 0x08129EE4

void sub_08129EE4(int arg0)

{
  int iVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  iVar1 = sub_080EA934();
  if (iVar1 == 1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_08129EFC @ 0x08129EFC

void sub_08129EFC(void)

{
  sub_080EA964();
  sub_08128EB4();
  sub_081269B0(2);
  return;
}


// sub_08129F10 @ 0x08129F10

void sub_08129F10(void)

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


// sub_08129F3C @ 0x08129F3C

void sub_08129F3C(int arg0)

{
  uint uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar1 = sub_08127A98(3);
  if ((uVar1 & 0xffff) != 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_08129F5C @ 0x08129F5C

void sub_08129F5C(int arg0)

{
  ushort uVar1;
  char cVar2;
  undefined4 arg1;
  uint arg0_00;
  
  arg0_00 = 0;
  uVar1 = *(ushort *)(arg0 + 0x1e);
  cVar2 = DAT_030050e0;
  while (((int)cVar2 != (uint)(ushort)(&DAT_0203c4d0)[uVar1] &&
         (arg0_00 = arg0_00 + 1 & 0xffff, arg0_00 < 6))) {
    cVar2 = (&DAT_030050e0)[arg0_00];
    uVar1 = *(ushort *)(arg0 + 0x1e);
  }
  arg1 = Battle_BuildNamePrependText(arg0_00,0x8124182);
  BattleMenu_SetMode(3,arg1);
  sub_080C0290((uint)(ushort)(&DAT_0203c4d0)[*(ushort *)(arg0 + 0x1e)],0);
  sub_080C366C();
  sub_081269B0(2);
  return;
}


// sub_08129FDC @ 0x08129FDC

void sub_08129FDC(void)

{
  DAT_0203c248 = sub_080AD0FC(0x8778614,0xffff);
  return;
}


// sub_08129FFC @ 0x08129FFC

void sub_08129FFC(int arg0,int arg1)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (arg1 == 0) {
    sub_080EA210();
  }
  uVar1 = sub_08127A98(2);
  uVar1 = uVar1 & 0xffff;
  if (uVar1 == 0) {
    BattleMenu_SetMode(3,0x812439a);
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  else {
    DAT_0203c24c = sub_080ABC40(1,0,0xf,10);
    DAT_0203c250 = sub_080ABC40(0x11,0,0xc,6);
    sub_081272AC();
    if (uVar1 < 5) {
      sub_08126928(2,0,1,uVar1);
    }
    else {
      sub_08126928(2,0x10,1,uVar1);
    }
    if (arg1 == 0) {
      BattleMenu_SetMode(4,0x8124364);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0812a094. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812A09C @ 0x0812A09C

void sub_0812A09C(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(2);
  sub_08127EAC(0,(uint)*(ushort *)(iVar1 + 0xc));
  sub_081283C4(0,(uint)*(ushort *)(iVar1 + 0x12));
  return;
}


// sub_0812A0BC @ 0x0812A0BC

void sub_0812A0BC(int arg0,int arg1)

{
  byte bVar1;
  char *pcVar2;
  
  pcVar2 = (char *)sub_08126D1C(2);
  bVar1 = pcVar2[0x12];
  sub_08126A08(2);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined1 *)(arg0 + 0x24) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if (*pcVar2 != '\x03') goto LAB_0812a112;
    *(undefined2 *)(arg0 + 0x1e) = *(undefined2 *)(pcVar2 + 0x12);
    *(undefined1 *)(arg0 + 0x24) = (char)*(undefined2 *)(pcVar2 + 0x12);
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
  }
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_0812a112:
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
  if (arg1 == 1) {
    Text_DrawSpriteString(0x8124364,0,0,0x12);
    *(undefined1 *)(arg0 + 6) = 0;
  }
  return;
}


// sub_0812A1C8 @ 0x0812A1C8

void sub_0812A1C8(int arg0)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  iVar1 = sub_080C0148((ushort)(&DAT_0203c4d0)[*(byte *)(arg0 + 0x24)] + 0x8000 & 0xffff);
  uVar2 = sub_0815B8F8((uint)*(ushort *)(iVar1 + 0x12),1);
  if (-1 < (int)(-uVar2 | uVar2)) {
    uVar3 = sub_080EC038(0x6e);
    uVar3 = Menu_ExpandListTemplate(uVar3,0);
    BattleMenu_SetMode(3,uVar3);
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
  }
  return;
}


// sub_0812A228 @ 0x0812A228

void sub_0812A228(int arg0)

{
  uint uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar1 = sub_08127A98(2);
  if ((uVar1 & 0xffff) != 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_0812A248 @ 0x0812A248

void sub_0812A248(int arg0)

{
  sub_080F41B0((uint)(ushort)(&DAT_0203c4d0)[*(byte *)(arg0 + 0x24)]);
  sub_080C366C();
  sub_081269B0(2);
  return;
}


// sub_0812A274 @ 0x0812A274

void sub_0812A274(void)

{
  sub_080EA964();
  sub_08128EB4();
  sub_081269B0(2);
  return;
}


// sub_0812A288 @ 0x0812A288

void sub_0812A288(void)

{
  sub_080EA528();
  sub_081269B0(2);
  return;
}


// sub_0812A298 @ 0x0812A298

void sub_0812A298(int arg0)

{
  undefined4 arg1;
  
  DAT_0203d310 = sub_080ABEB4(0);
  arg1 = Battle_BuildNamePrependText
                   ((ushort)(&DAT_0203c4d0)[*(byte *)(arg0 + 0x24)] + 0x8000 & 0xffff,0x812437c);
  BattleMenu_SetMode(3,arg1);
  sub_080EC99C(1);
  return;
}


// sub_0812A2EC @ 0x0812A2EC

void sub_0812A2EC(int arg0)

{
  int iVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  iVar1 = sub_080ABF04(DAT_0203d310);
  if (iVar1 == 1) {
    if ((DAT_030031cc == 1) || (DAT_030031cc != 0)) {
      *(undefined2 *)(arg0 + 0x1e) = 0;
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 1;
    }
    sub_080AB91C(DAT_0203d310,0);
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_0812A338 @ 0x0812A338

void sub_0812A338(int arg0)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint arg0_00;
  
  uVar1 = (&DAT_0203c4d0)[*(byte *)(arg0 + 0x24)];
  arg0_00 = uVar1 + 0x8000 & 0xffff;
  sub_080C0148(arg0_00);
  iVar2 = sub_080C0A00((uint)uVar1);
  if (iVar2 == 0) {
    uVar3 = Battle_BuildNamePrependText(arg0_00,0x81243b0);
    BattleMenu_SetMode(3,uVar3);
  }
  else {
    uVar3 = Battle_BuildNamePrependText(arg0_00,0x81243c6);
    BattleMenu_SetMode(3,uVar3);
  }
  return;
}


// sub_0812A39C @ 0x0812A39C

void sub_0812A39C(int arg0)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint arg3;
  
  iVar3 = sub_08126D1C(2);
  bVar1 = *(byte *)(iVar3 + 0x12);
  sub_080AA184(0x8000ea4,0,0,1);
  if (5 < *(ushort *)(iVar3 + 10)) {
    if (*(short *)(iVar3 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(iVar3 + 0xc) + 5 != (uint)*(ushort *)(iVar3 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
  if ((ushort)bVar1 != *(ushort *)(iVar3 + 0x12)) {
    sub_08127EAC(0,(uint)*(ushort *)(iVar3 + 0xc));
    sub_081283C4(0,(uint)*(ushort *)(iVar3 + 0x12));
  }
  if (*(char *)(arg0 + 6) == '\x01') {
    arg3 = 0x12;
    iVar3 = sub_080F2F64((ushort)(&DAT_0203c4d0)[*(byte *)(arg0 + 0x24)] + 0x8000 & 0xffff);
    iVar3 = sub_080BF648((uint)*(ushort *)(iVar3 + 0x12));
    uVar4 = 0;
    sVar2 = *(short *)(iVar3 + 0x22);
    while (sVar2 != 0) {
      FontSprite_DrawGlyph((uint)*(ushort *)(iVar3 + 0x22 + uVar4 * 2),0,0,arg3);
      arg3 = arg3 + 0xc & 0xffff;
      uVar4 = uVar4 + 1 & 0xffff;
      if (7 < uVar4) break;
      sVar2 = *(short *)(iVar3 + 0x22 + uVar4 * 2);
    }
    Text_DrawSpriteString(0x800354a,0,0,arg3);
    Text_DrawSpriteString(0x8003556,0,0,0x12);
  }
  else if (*(char *)(arg0 + 6) == '\x02') {
    Text_DrawSpriteString(0x8003568,0,0,0x12);
  }
  return;
}


// sub_0812A50C @ 0x0812A50C

void sub_0812A50C(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (((DAT_030031b8 & 1) != 0) || ((DAT_030031b8 & 2) != 0)) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    *(undefined1 *)(arg0 + 6) = 0;
  }
  return;
}


// sub_0812A53C @ 0x0812A53C

void sub_0812A53C(void)

{
  DAT_0203d310 = sub_080ABEB4(0);
  return;
}


// sub_0812A55C @ 0x0812A55C

void sub_0812A55C(int arg0)

{
  DAT_0203d38e = (&DAT_0203c4d0)[*(byte *)(arg0 + 0x24)];
  sub_081269B0(2);
  return;
}


// sub_0812A588 @ 0x0812A588

void sub_0812A588(void)

{
  sub_081269B0(2);
  return;
}


// sub_0812A594 @ 0x0812A594

void sub_0812A594(void)

{
  sub_081269B0(2);
  return;
}


// sub_0812A5A0 @ 0x0812A5A0

void sub_0812A5A0(void)

{
  DAT_0203d38e = 0xffff;
  return;
}


// sub_0812A5B8 @ 0x0812A5B8

void sub_0812A5B8(undefined4 arg0,undefined4 arg1)

{
  DAT_030031cc = arg1;
  return;
}


// sub_0812A5C4 @ 0x0812A5C4

void sub_0812A5C4(int arg0)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  iVar2 = sub_080C0148((ushort)(&DAT_0203c4d0)[*(byte *)(arg0 + 0x24)] + 0x8000 & 0xffff);
  uVar3 = sub_0815B8F8((uint)*(ushort *)(iVar2 + 0x12),1);
  if ((int)(-uVar3 | uVar3) < 0) {
    uVar1 = 1;
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    uVar1 = 2;
  }
  *(undefined1 *)(arg0 + 6) = uVar1;
  return;
}


// sub_0812A61C @ 0x0812A61C

void sub_0812A61C(undefined4 arg0,int arg1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    sub_080C6FF0();
    sub_080C7414();
    sub_080C762C();
  }
  else {
    sub_080C700C();
    sub_080C7430();
    sub_080C7648();
  }
                    /* WARNING: Could not recover jumptable at 0x0812a63e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812A640 @ 0x0812A640

undefined4 sub_0812A640(void)

{
  undefined4 uVar1;
  
  DAT_0203d38e = 0xffff;
  uVar1 = sub_080AD0FC(0x87787f8,0xffff);
  return uVar1;
}


// sub_0812A668 @ 0x0812A668

uint sub_0812A668(uint arg0)

{
  ushort uVar1;
  uint arg0_00;
  ushort *puVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  
  puVar4 = &DAT_0203c4d0;
  uVar5 = 0;
  puVar2 = (ushort *)sub_080C9210(arg0 & 0xff);
  uVar1 = *puVar2;
  do {
    arg0_00 = (uint)uVar1;
    if (arg0_00 == 0xffff) {
      *puVar4 = 0xffff;
      return uVar5;
    }
    iVar3 = sub_080C2340(0xb6);
    if (iVar3 == 0) {
      if ((puVar2[1] == 0) && (iVar3 = sub_080C2554(arg0_00), iVar3 != 0)) {
LAB_0812a6c8:
        *puVar4 = uVar1;
        goto LAB_0812a6ca;
      }
    }
    else if (puVar2[1] == 0) {
      iVar3 = sub_080C2554(arg0_00);
      if (iVar3 != 0) goto LAB_0812a6c8;
      *puVar4 = uVar1 + 0x8000;
LAB_0812a6ca:
      puVar4 = puVar4 + 1;
      uVar5 = uVar5 + 1 & 0xffff;
    }
    puVar2 = puVar2 + 2;
    uVar1 = *puVar2;
  } while( true );
}


// sub_0812A6F0 @ 0x0812A6F0

void sub_0812A6F0(void)

{
  DAT_0203c248 = sub_080AD0FC(0x8778adc,0xffff);
  return;
}


// sub_0812A710 @ 0x0812A710

void sub_0812A710(void)

{
  DAT_0203c248 = sub_080AD0FC(0x8778cb4,0xffff);
  return;
}


// sub_0812A730 @ 0x0812A730

undefined4 sub_0812A730(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = sub_080C2340(0xe5);
  if (iVar1 == 1) {
    DAT_0203c896 = 1;
    sub_080EA528();
    uVar2 = sub_080F3190();
    if (uVar2 == 0) {
      DAT_0203c248 = sub_080AD0FC(0x8778adc,0xffff);
      sub_080C6FF0();
      sub_080C7414();
      sub_080C7218();
      sub_080C7C60();
      return 1;
    }
    DAT_0203c244 = sub_080AD0FC(0x877812c,0xffff);
    sub_080EA210();
    uVar3 = sub_080EC038(uVar2 & 0xffff);
    uVar3 = Menu_ExpandListTemplate(uVar3,0);
    BattleMenu_SetMode(3,uVar3);
    sub_080B1BC4();
    sub_080C51D4(0x68);
  }
  return 0;
}


// sub_0812A7C4 @ 0x0812A7C4

undefined4 sub_0812A7C4(void)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C2340(0xe5);
  if ((iVar1 == 1) && (iVar1 = sub_080F3190(), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0812a7e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_0812A7E4 @ 0x0812A7E4

void sub_0812A7E4(int arg0)

{
  uint uVar1;
  undefined4 arg1;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  uVar1 = sub_0812A668(0);
  if ((uVar1 & 0xffff) == 0) {
    sub_080EA210();
    arg1 = Menu_ExpandListTemplate(0x8124a62,0);
    BattleMenu_SetMode(3,arg1);
    sub_080C51D4(0x68);
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  else {
    DAT_0203c24c = sub_080ABC40(9,1,0xc,7);
    sub_080C7E24(0x30000b4,0x8778a9c);
    DisplayList_Add(0x8128f29,1);
    sub_08126928(2,1,1,4);
  }
  return;
}


// sub_0812A86C @ 0x0812A86C

void sub_0812A86C(int arg0,int arg1)

{
  short sVar1;
  char *pcVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar2 = (char *)sub_08126D1C(2);
  sVar1 = *(short *)(pcVar2 + 0x18);
  sub_08126A08(2);
  if ((arg1 == 1) && (*(char *)(arg0 + 6) != '\0')) {
    arg1 = 0;
  }
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (((DAT_030031b8 & 2) == 0) || (arg1 != 0)) {
    if ((DAT_030031b8 & 1) == 0) {
      if (*pcVar2 == '\x06') {
        if (DAT_0203c9e0 == '\x04') {
          sub_080EA528();
          sub_080EA964();
        }
        else {
          sub_080EA210();
          BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar2 + 0x18) * 4 + 0x8778acc));
        }
      }
      else if ((sVar1 != *(short *)(pcVar2 + 0x18)) && (DAT_0203c9e0 == '\x04')) {
        BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar2 + 0x18) * 4 + 0x8778acc));
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = *(undefined2 *)(pcVar2 + 0x18);
      DAT_0203c897 = (undefined1)*(undefined2 *)(pcVar2 + 0x18);
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0xff;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  sub_080AA184(0x8000ee4,0,0,0);
  uVar3 = 0;
  do {
    sub_080AA1F4(uVar3 * 0x10 + 0x8777f60,0,0,0);
    sub_080AA1F4(&DAT_08777f68 + uVar3 * 0x10,0,0,0);
    sub_080AA1F4(0x8778ac4,0,0,0);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 4);
                    /* WARNING: Could not recover jumptable at 0x0812a9d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812A9EC @ 0x0812A9EC

void sub_0812A9EC(void)

{
  if (DAT_0203c896 == '\0') {
    sub_08128EB4();
  }
  else {
    if (DAT_0203c9e0 == '\x04') {
      sub_080EA964();
    }
    sub_081279D4();
    if (DAT_03004550 == 0x1b) {
      Field_SetState(0x1e);
      DAT_0300456e = 0;
    }
    else {
      Field_SetState(1);
    }
    sub_080C7234();
    sub_080C762C();
    sub_080C7C94();
  }
  sub_081269B0(2);
  return;
}


// sub_0812AA54 @ 0x0812AA54

void sub_0812AA54(void)

{
  if (DAT_0203c896 == '\0') {
    sub_08128EB4();
  }
  else {
    sub_081279D4();
    if (DAT_03004550 == 0x1b) {
      Field_SetState(0x1e);
      DAT_0300456e = 0;
    }
    else {
      Field_SetState(1);
    }
    sub_080C7234();
    sub_080C762C();
    sub_080C7C94();
  }
  sub_080EA964();
  sub_081269B0(2);
  return;
}


// sub_0812AAB0 @ 0x0812AAB0

void sub_0812AAB0(undefined4 arg0,int arg1)

{
  uint uVar1;
  
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
  if (arg1 == 1) {
    sub_0812AC68(1);
  }
  sub_080EA210();
  BattleMenu_SetMode(4,0x8123df0);
  return;
}


// sub_0812AB44 @ 0x0812AB44

void sub_0812AB44(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(2);
  sub_08127EAC(1,(uint)*(ushort *)(iVar1 + 0xc));
  sub_081283C4(2,(uint)*(ushort *)(iVar1 + 0x12));
  return;
}


// sub_0812AB64 @ 0x0812AB64

void sub_0812AB64(int arg0)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = sub_08126D1C(2);
  bVar1 = *(byte *)(iVar2 + 0x12);
  sub_08126A08(2);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if (((DAT_030031b8 & 1) != 0) && (((&DAT_0203c4d0)[*(ushort *)(iVar2 + 0x12)] & 0x8000) == 0)) {
      *(ushort *)(arg0 + 0x1e) = *(ushort *)(iVar2 + 0x12);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_0812AC68(0);
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  sub_080AA184(0x8000ea4,0,0,1);
  if (5 < *(ushort *)(iVar2 + 10)) {
    if (*(short *)(iVar2 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(iVar2 + 0xc) + 5 != (uint)*(ushort *)(iVar2 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
  if ((ushort)bVar1 != *(ushort *)(iVar2 + 0x12)) {
    sub_08127EAC(1,(uint)*(ushort *)(iVar2 + 0xc));
    sub_081283C4(2,(uint)*(ushort *)(iVar2 + 0x12));
  }
  return;
}


// sub_0812AC68 @ 0x0812AC68

void sub_0812AC68(undefined4 arg0)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  if ((short)arg0 == 0) {
    puVar1 = (undefined1 *)sub_08126D1C(2);
    puVar2 = (undefined1 *)0x3006450;
  }
  else {
    puVar1 = (undefined1 *)0x3006450;
    puVar2 = (undefined1 *)sub_08126D1C(2);
  }
  uVar3 = 0;
  do {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x28);
  if ((short)arg0 == 1) {
    sub_08127960(2,(uint)DAT_03006462);
  }
  return;
}


// sub_0812ACB8 @ 0x0812ACB8

void sub_0812ACB8(int arg0)

{
  sub_080CB01C(0,(uint)*(ushort *)(arg0 + 0x1e));
  sub_081269B0(2);
  return;
}


// sub_0812ACCC @ 0x0812ACCC

uint sub_0812ACCC(uint arg0)

{
  return (uint)(ushort)(&DAT_0203c4d0)[arg0 & 0xffff];
}


// sub_0812ACE4 @ 0x0812ACE4

void sub_0812ACE4(void)

{
  undefined2 *puVar1;
  int iVar2;
  int *piVar3;
  undefined2 *puVar4;
  undefined4 local_14;
  
  local_14 = 0;
  CpuFastSet(&local_14,0x30000b4,0x100015a);
  piVar3 = (int *)0x30051ac;
  puVar1 = (undefined2 *)0x30000b4;
  iVar2 = 0x15a;
  do {
    if (*piVar3 == 0) {
      *puVar1 = 0;
      puVar1[1] = 0xfff;
    }
    else {
      *puVar1 = *(undefined2 *)((int)piVar3 + 2);
      puVar1[1] = (short)*piVar3;
    }
    piVar3 = piVar3 + 1;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar4 = (undefined2 *)0x30051ac;
  iVar2 = 0x15a;
  sub_080EDB6C(0,0x15a,0x30000b4);
  puVar1 = (undefined2 *)0x30000b4;
  do {
    if (puVar1[1] != -1) {
      *puVar4 = puVar1[1];
      puVar4[1] = *puVar1;
      puVar4 = puVar4 + 2;
    }
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// sub_0812AD70 @ 0x0812AD70

void sub_0812AD70(void)

{
  DAT_0203c244 = sub_080AD0FC(0x8778e04,0xffff);
  return;
}


// sub_0812AD90 @ 0x0812AD90

void sub_0812AD90(void)

{
  DAT_0203c24c = sub_080ABC40(9,1,0xc,7);
  sub_080C7E24(0x30000b4,0x8778dd0);
  DisplayList_Add(0x8128f29,1);
  sub_080EA964();
  sub_08126928(5,1,1,4);
  return;
}


// sub_0812ADE4 @ 0x0812ADE4

void sub_0812ADE4(int arg0)

{
  short sVar1;
  char *pcVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar2 = (char *)sub_08126D1C(5);
  sVar1 = *(short *)(pcVar2 + 0x18);
  sub_08126A08(5);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_030031b8 & 1) == 0) {
      if (*pcVar2 == '\x06') {
        if (DAT_0203c9e0 == '\x04') {
          sub_080EA528();
          sub_080EA964();
        }
        else {
          sub_080EA210();
          BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar2 + 0x18) * 4 + 0x8778df4));
        }
      }
      else if ((sVar1 != *(short *)(pcVar2 + 0x18)) && (DAT_0203c9e0 == '\x04')) {
        BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar2 + 0x18) * 4 + 0x8778df4));
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = *(undefined2 *)(pcVar2 + 0x18);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined1 *)(arg0 + 0x24) = 0;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  sub_080AA184(0x8000ee4,0,0,0);
  uVar3 = 0;
  do {
    sub_080AA1F4(uVar3 * 0x10 + 0x8777f60,0,0,0);
    sub_080AA1F4(&DAT_08777f68 + uVar3 * 0x10,0,0,0);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 4);
                    /* WARNING: Could not recover jumptable at 0x0812af24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812AF34 @ 0x0812AF34

void sub_0812AF34(void)

{
  sub_08128B84(1);
  sub_081269B0(5);
  return;
}


// sub_0812AF48 @ 0x0812AF48

void sub_0812AF48(int arg0)

{
  uint uVar1;
  undefined4 arg1;
  
  sub_080EA210();
  uVar1 = sub_0812B320(0xff);
  if ((uVar1 & 0xffff) == 0) {
    arg1 = Menu_ExpandListTemplate(0x8124c20,0);
    BattleMenu_SetMode(3,arg1);
    *(short *)(arg0 + 0x1c) = (short)uVar1;
  }
  else {
    BattleMenu_SetMode(3,0x81244ba);
    sub_0812ACE4();
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_0812AF94 @ 0x0812AF94

void sub_0812AF94(void)

{
  BattleMenu_SetMode(3,0x81244c4);
  return;
}


// sub_0812AFA8 @ 0x0812AFA8

void sub_0812AFA8(void)

{
  sub_080EA528();
  sub_080EA964();
  return;
}


// sub_0812AFB8 @ 0x0812AFB8

void sub_0812AFB8(undefined4 arg0,uint arg1)

{
  sub_0812B194(0,arg1 & 0xffff);
  return;
}


// sub_0812AFC8 @ 0x0812AFC8

void sub_0812AFC8(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_0812B1D4();
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (uVar1 != 0xffffffff) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if ((uVar1 & 0xffff0000) == 0xfffe0000) {
      *(undefined2 *)(arg0 + 0x1e) = 0x100;
    }
    else {
      DAT_030065c6 = (undefined2)((uVar1 & 0xffff0000) >> 0x10);
      *(undefined2 *)(&DAT_0203d130 + (uVar1 >> 0x10) * 2) = DAT_030065c6;
      DAT_030065c2 = (undefined2)uVar1;
      DAT_030065c4 = 8;
    }
  }
  return;
}


// sub_0812B028 @ 0x0812B028

void sub_0812B028(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  int iStack_18;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar2 = DAT_030065c2;
  uVar1 = *(ushort *)(arg0 + 0x1e);
  if (uVar1 == 1) {
    iVar4 = sub_080EA934();
    if (iVar4 == 1) {
      uVar5 = (uint)DAT_030065c2;
      sub_080F3E54(uVar5,0xffffffff);
      sub_080BF468(uVar5,0xc,&iStack_18);
      if (iStack_18 < 0x80) {
        sub_0812E780((int)DAT_030065c6,&DAT_0203d130,0x8124d5e,1);
        if (iStack_18 - 0x3eU < 2) {
          uVar5 = sub_080F1678(0,2);
          uVar3 = sub_080EC038(0xe9);
          uVar3 = Menu_ExpandListTemplate(uVar3,(int)(char)(&DAT_030050e0)[uVar5 & 0xffff]);
          BattleMenu_SetMode(3,uVar3);
        }
      }
      else {
        sub_0812EA98((int)DAT_030065c6);
      }
      *(undefined2 *)(arg0 + 0x1e) = 2;
    }
  }
  else if (uVar1 < 2) {
    if (uVar1 == 0) {
      DAT_03006440 = DAT_030065c2;
      sub_080EA210();
      uVar3 = sub_0812EA54();
      uVar3 = Menu_ExpandListTemplate(0x8124d5e,(uint)uVar2 * 0x10000 + (int)(short)uVar3);
      BattleMenu_SetMode(3,uVar3);
      *(undefined2 *)(arg0 + 0x1e) = 1;
    }
  }
  else if (uVar1 == 2) {
    iVar4 = sub_080EA934();
    if (iVar4 == 1) {
      sub_080EA528();
      sub_080EA964();
      *(undefined2 *)(arg0 + 0x1e) = 3;
    }
  }
  else if (uVar1 == 3) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0812b136. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812B138 @ 0x0812B138

void sub_0812B138(int arg0)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  
  *(undefined2 *)(arg0 + 0x1c) = 1;
  uVar2 = sub_080C32D4((uint)DAT_03006440);
  if ((uVar2 & 0xff) == 0) {
    uVar2 = sub_0812B260(0);
    uVar3 = uVar2 & 0xffff;
    uVar1 = (undefined2)uVar2;
    if (uVar3 == 0) {
      *(undefined2 *)(arg0 + 0x1c) = uVar1;
    }
    else {
      DAT_03006460 = uVar1;
      if (4 < uVar3) {
        DAT_03006460 = 5;
      }
      DAT_0300645a = uVar1;
      if ((int)(uVar3 - 1) < (int)(uint)DAT_03006462) {
        DAT_03006462 = DAT_03006462 - 1;
      }
    }
  }
  return;
}


// sub_0812B194 @ 0x0812B194

void sub_0812B194(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  DAT_03006478 = (undefined2)arg1;
  DAT_0203c248 = sub_080AD0FC(0x87790c4,0xffff);
  *(undefined1 *)(DAT_0203c248 + 0x24) = (undefined1)arg0;
  iVar1 = DAT_0203c248;
  sub_080EA964();
  *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;
  return;
}


// sub_0812B1D4 @ 0x0812B1D4

undefined4 sub_0812B1D4(void)

{
  return *(undefined4 *)(DAT_0203c248 + 0x28);
}


// sub_0812B1E0 @ 0x0812B1E0

uint sub_0812B1E0(int arg0,uint arg1)

{
  int iVar1;
  uint arg0_00;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = arg1 & 0xff;
  if (uVar3 == 0) {
    uVar4 = 0;
  }
  else {
    if (6 < uVar3) {
      uVar3 = 6;
    }
    uVar2 = 0;
    if (uVar3 != 0) {
      do {
        arg0_00 = (int)*(char *)(uVar2 + 0x30050e0) & 0xffff;
        iVar1 = sub_080F3EC8(arg0_00);
        if ((((iVar1 != 0) && (iVar1 = sub_080F3040(), iVar1 != 0)) &&
            (iVar1 = sub_080C35E4(arg0_00), iVar1 == 8)) &&
           (iVar1 = sub_080F3F14(arg0_00), iVar1 == arg0)) {
          uVar4 = uVar4 + 1 & 0xffff;
        }
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < uVar3);
    }
  }
  return uVar4;
}


// sub_0812B260 @ 0x0812B260

uint sub_0812B260(undefined4 arg0)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  uint arg0_00;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  
  puVar7 = &DAT_0203c4d0;
  uVar8 = 0;
  bVar2 = 0xc0;
  if ((char)arg0 != '\0') {
    bVar2 = 0x20;
  }
  uVar6 = 0;
  do {
    uVar1 = *(ushort *)(uVar6 * 4 + 0x30051ac);
    arg0_00 = (uint)uVar1;
    uVar5 = (uint)(ushort)(&DAT_030051ae)[uVar6 * 2];
    if ((char)arg0 == '\x01') {
      iVar3 = sub_0812B1E0(arg0_00,(uint)(byte)DAT_0203d166);
      uVar5 = uVar5 - iVar3 & 0xffff;
    }
    if ((((arg0_00 - 0xd0 & 0xffff) < 0x2e) && (uVar5 != 0)) &&
       (pbVar4 = (byte *)Action_GetRecord(arg0_00), (*pbVar4 & bVar2) != 0)) {
      *puVar7 = uVar1;
      puVar7[1] = (ushort)uVar5;
      puVar7 = puVar7 + 2;
      uVar8 = uVar8 + 1 & 0xffff;
    }
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 0x15a);
  *puVar7 = 0xffff;
  puVar7[1] = 0xffff;
  return uVar8;
}


// sub_0812B320 @ 0x0812B320

uint sub_0812B320(undefined4 arg0)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar2 = (ushort *)0x30051ac;
  puVar4 = (undefined4 *)&DAT_0203c4d0;
  uVar3 = 0;
  uVar1 = 0;
  do {
    if ((*puVar2 < (ushort)arg0) && (puVar2[1] != 0)) {
      *puVar4 = *(undefined4 *)puVar2;
      puVar4 = puVar4 + 1;
      uVar3 = uVar3 + 1 & 0xffff;
    }
    puVar2 = puVar2 + 2;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x15a);
  *(undefined2 *)puVar4 = 0xffff;
  *(undefined2 *)((int)puVar4 + 2) = 0xffff;
  return uVar3;
}


// sub_0812B37C @ 0x0812B37C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint sub_0812B37C(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = sub_080C2340(0xd5);
  if (iVar1 != 0) {
    uVar2 = -(_DAT_0203bb74 ^ 2) >> 0x1f;
  }
  return uVar2;
}


// sub_0812B3A4 @ 0x0812B3A4

undefined4 sub_0812B3A4(undefined4 arg0)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 uVar5;
  uint arg0_00;
  undefined4 in_r2;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar2 = 0;
  bVar1 = 0xc0;
  if ((char)arg0 != '\0') {
    bVar1 = 0x20;
  }
  iVar3 = sub_0812B37C();
  if (iVar3 == 0) {
    uVar7 = 0;
    do {
      arg0_00 = (uint)*(ushort *)(uVar7 * 4 + 0x30051ac);
      uVar6 = (uint)(ushort)(&DAT_030051ae)[uVar7 * 2];
      if ((arg0_00 - 0xd0 & 0xffff) < 0x2f) {
        if ((char)arg0 == '\x01') {
          iVar3 = sub_0812B1E0(arg0_00,0xff);
          uVar6 = uVar6 - iVar3 & 0xffff;
        }
        if ((uVar6 != 0 && -1 < (int)(uVar6 * 0x10000)) &&
           (pbVar4 = (byte *)Action_GetRecord(arg0_00), (*pbVar4 & bVar1) != 0)) {
          sVar2 = sVar2 + 1;
        }
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 0x15a);
  }
  else {
    sVar2 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0812b434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*UNRECOVERED_JUMPTABLE)(sVar2,UNRECOVERED_JUMPTABLE,in_r2,unaff_r8);
  return uVar5;
}


// sub_0812B440 @ 0x0812B440

void sub_0812B440(undefined4 arg0)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  if ((short)arg0 == 0) {
    puVar1 = (undefined1 *)sub_08126D1C(4);
    puVar2 = (undefined1 *)0x3006450;
  }
  else {
    puVar1 = (undefined1 *)0x3006450;
    puVar2 = (undefined1 *)sub_08126D1C(4);
  }
  uVar3 = 0;
  do {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x28);
  if ((short)arg0 == 1) {
    sub_08127960(4,(uint)DAT_03006462);
  }
  return;
}


// sub_0812B490 @ 0x0812B490

void sub_0812B490(int arg0)

{
  int iVar1;
  undefined4 uVar2;
  dword arg0_00;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  sub_080EA210();
  iVar1 = sub_0812B37C();
  if ((iVar1 == 0) && (uVar2 = sub_0812EA54(), (short)uVar2 != -1)) {
    uVar3 = sub_0812B260((uint)*(byte *)(arg0 + 0x24));
    uVar3 = uVar3 & 0xffff;
    if (uVar3 != 0) {
      DAT_0203c24c = sub_080ABC40(1,0,0x13,10);
      DAT_0203c250 = sub_080AB890(2,0xd,0x1a,6);
      sub_081272AC();
      if (uVar3 < 5) {
        sub_08126928(4,0,1,uVar3);
      }
      else {
        sub_08126928(4,0x10,1,uVar3);
      }
      if (DAT_03006478 != 0) {
        sub_0812B440(1);
      }
      goto LAB_0812b56e;
    }
    arg0_00 = 0x8124bd2;
LAB_0812b4fe:
    uVar2 = Menu_ExpandListTemplate(arg0_00,0);
    BattleMenu_SetMode(3,uVar2);
  }
  else {
    iVar1 = sub_080C2340(0xd5);
    if (iVar1 != 0) {
      arg0_00 = sub_080EC038(0x392);
      goto LAB_0812b4fe;
    }
    uVar2 = sub_080EC038(0x74);
    uVar2 = Menu_ExpandListTemplate(uVar2,0);
    BattleMenu_SetMode(3,uVar2);
  }
  *(undefined2 *)(arg0 + 0x1e) = 1;
LAB_0812b56e:
                    /* WARNING: Could not recover jumptable at 0x0812b574. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812B57C @ 0x0812B57C

void sub_0812B57C(void)

{
  undefined4 arg1;
  
  arg1 = Menu_ExpandListTemplate(0x8124cc8,0);
  BattleMenu_SetMode(4,arg1);
  return;
}


// sub_0812B598 @ 0x0812B598

void sub_0812B598(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 arg1;
  
  iVar2 = sub_08126D1C(4);
  uVar1 = (&DAT_0203c4d0)[(uint)*(ushort *)(iVar2 + 0x12) * 2];
  sub_08127EAC(4,(uint)*(ushort *)(iVar2 + 0xc));
  iVar2 = Action_GetRecord((uint)uVar1);
  arg1 = Menu_ExpandListTemplate(*(undefined4 *)(iVar2 + 0x1c),0);
  BattleMenu_SetMode(8,arg1);
  return;
}


// sub_0812B5D8 @ 0x0812B5D8

void sub_0812B5D8(int arg0)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 arg1;
  
  iVar3 = sub_08126D1C(4);
  bVar1 = *(byte *)(iVar3 + 0xc);
  bVar2 = *(byte *)(iVar3 + 0x12);
  sub_08126A08(4);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_030031b8 & 1) != 0) {
      *(char *)(arg0 + 0x2c) = (char)(&DAT_0203c4d0)[(uint)*(ushort *)(iVar3 + 0x12) * 2];
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_0812B440(0);
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  if ((ushort)bVar1 != *(ushort *)(iVar3 + 0xc)) {
    sub_08127EAC(4,(uint)*(ushort *)(iVar3 + 0xc));
  }
  if ((ushort)bVar2 != *(ushort *)(iVar3 + 0x12)) {
    iVar4 = Action_GetRecord((uint)(ushort)(&DAT_0203c4d0)[(uint)*(ushort *)(iVar3 + 0x12) * 2]);
    arg1 = Menu_ExpandListTemplate(*(undefined4 *)(iVar4 + 0x1c),0);
    BattleMenu_SetMode(8,arg1);
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


// sub_0812B6F4 @ 0x0812B6F4

void sub_0812B6F4(void)

{
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  if (DAT_0203c250 != 0) {
    sub_080AB91C(DAT_0203c250,0);
  }
  if (DAT_0203cb74 != 0) {
    sub_080AB91C(DAT_0203cb74,0);
    DAT_0203cb74 = 0;
  }
  sub_081269B0(4);
  sub_080EA528();
  sub_08128388();
  return;
}


// sub_0812B740 @ 0x0812B740

void sub_0812B740(int arg0)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = (uint)*(byte *)(arg0 + 0x2c);
  iVar3 = Action_GetRecord(arg0_00);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  cVar1 = *(char *)(iVar3 + 3);
  if (((cVar1 == -0x80) || (cVar1 == -0x7e)) || (cVar1 == -0x7d)) {
    uVar2 = 1;
  }
  else if (arg0_00 == 0xfb) {
    uVar2 = 3;
  }
  else if (arg0_00 == 0xe1) {
    uVar2 = 4;
  }
  else {
    if (cVar1 != '\0') goto LAB_0812b77e;
    uVar2 = 2;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar2;
LAB_0812b77e:
                    /* WARNING: Could not recover jumptable at 0x0812b782. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812B784 @ 0x0812B784

void sub_0812B784(int arg0)

{
  *(uint *)(arg0 + 0x28) = (uint)*(ushort *)(arg0 + 0x1e) * 0x10000 + (uint)*(byte *)(arg0 + 0x2c);
  return;
}


// sub_0812B794 @ 0x0812B794

void sub_0812B794(int arg0)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = Action_GetRecord((uint)*(byte *)(arg0 + 0x2c));
  uVar4 = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  bVar1 = *(byte *)(iVar2 + 3);
  if (bVar1 != 0x81) {
    if (bVar1 < 0x82) {
      if ((bVar1 == 0) || (bVar1 != 0x80)) goto LAB_0812b7f8;
      if (*(char *)(DAT_0203c248 + 0x24) == '\x01') {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    else if (bVar1 == 0x83) {
      uVar3 = 6;
    }
    else {
      if (0x82 < bVar1) goto LAB_0812b7f8;
      if (*(char *)(DAT_0203c248 + 0x24) == '\x01') {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    uVar4 = sub_08127A98(uVar3);
    uVar4 = uVar4 & 0xffff;
  }
LAB_0812b7f8:
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
                    /* WARNING: Could not recover jumptable at 0x0812b870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812B878 @ 0x0812B878

void sub_0812B878(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(4);
  sub_08127EAC(0,(uint)*(ushort *)(iVar1 + 0xc));
  sub_081283C4(0,(uint)*(ushort *)(iVar1 + 0x12));
  return;
}


// sub_0812B898 @ 0x0812B898

void sub_0812B898(int arg0)

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
    if (*pcVar3 != '\x03') goto LAB_0812b8ea;
    uVar2 = (&DAT_0203c4d0)[*(ushort *)(pcVar3 + 0x12)];
  }
  else {
    uVar2 = 0x100;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar2;
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_0812b8ea:
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


// sub_0812B978 @ 0x0812B978

void sub_0812B978(void)

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


// sub_0812B9AC @ 0x0812B9AC

void sub_0812B9AC(int arg0)

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


// sub_0812BA0C @ 0x0812BA0C

void sub_0812BA0C(undefined4 arg0)

{
  sub_0812EE8C(1,arg0);
  return;
}


// sub_0812BA1C @ 0x0812BA1C

void sub_0812BA1C(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_030031cc == 0);
  return;
}


// sub_0812BA38 @ 0x0812BA38

void sub_0812BA38(undefined4 arg0,int arg1)

{
  int iVar1;
  uint uVar2;
  
  if (arg1 == 0) {
    sub_080AD1FC(DAT_0203c244);
  }
  else if (arg1 == 1) {
    if ((((DAT_0200ab04 & 0x7fff) != 0) ||
        ((iVar1 = sub_080B3078(0,0,6), iVar1 != 1 &&
         (((DAT_0200ab04 & 0x7fff) != 0 ||
          (((DAT_03004614 != 2 && (DAT_03004614 != 0x27)) && (DAT_03004614 != 0x41)))))))) &&
       (sub_080B0888(), DAT_03002db0 != 0)) {
      sub_080AB138(0,1,1,4);
    }
    sub_080C700C();
  }
  else {
    sub_080C33AC(0xfb);
    DAT_03003bb8 = (uint)(DAT_03005180 != 0);
    sub_080C2364(0x166);
    uVar2 = sub_0812EEC4();
    sub_080E471C(uVar2 & 0xffff,1,0xffff,0);
  }
  return;
}


// sub_0812BB04 @ 0x0812BB04

void sub_0812BB04(void)

{
  undefined4 in_r0;
  
  sub_0812EF8C(in_r0);
  return;
}


// sub_0812BB10 @ 0x0812BB10

void sub_0812BB10(void)

{
  DAT_0203c248 = sub_080AD0FC(0x8779418,0xffff);
  *(undefined1 *)(DAT_0203c248 + 0x24) = 0;
  *(undefined4 *)(DAT_0203c248 + 0x28) = 0xffffffff;
  return;
}


// sub_0812BB40 @ 0x0812BB40

void sub_0812BB40(undefined4 arg0,undefined4 arg1)

{
  undefined4 arg1_00;
  
  arg1_00 = Menu_ExpandListTemplate(arg1,0);
  BattleMenu_SetMode(4,arg1_00);
  return;
}


// sub_0812BB58 @ 0x0812BB58

void sub_0812BB58(undefined4 arg0,undefined4 arg1)

{
  undefined4 arg1_00;
  
  arg1_00 = Menu_ExpandListTemplate(arg1,0);
  BattleMenu_SetMode(9,arg1_00);
  return;
}


// sub_0812BB70 @ 0x0812BB70

void sub_0812BB70(int arg0)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(4);
  sub_08127EAC(5,(uint)*(byte *)(arg0 + 0x2c) * 0x100 + (uint)*(ushort *)(iVar1 + 0xc) & 0xffff);
  return;
}


// sub_0812BB94 @ 0x0812BB94

void sub_0812BB94(int arg0)

{
  ushort uVar1;
  int iVar2;
  undefined4 arg1;
  
  iVar2 = sub_08126D1C(4);
  uVar1 = (&DAT_0203c4d0)[(uint)*(ushort *)(iVar2 + 0x12) * 2];
  sub_08127EAC(5,(uint)*(byte *)(arg0 + 0x2c) * 0x100 + (uint)*(ushort *)(iVar2 + 0xc) & 0xffff);
  iVar2 = Action_GetRecord((uint)uVar1);
  arg1 = Menu_ExpandListTemplate(*(undefined4 *)(iVar2 + 0x1c),0);
  BattleMenu_SetMode(8,arg1);
  return;
}


// sub_0812BBE4 @ 0x0812BBE4

void sub_0812BBE4(int arg0)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = sub_08126D1C(4);
  bVar1 = *(byte *)(iVar2 + 0xc);
  sub_08126A08(4);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_030031b8 & 1) != 0) {
      *(undefined2 *)(arg0 + 0x1e) = (&DAT_0203c4d0)[(uint)*(ushort *)(iVar2 + 0x12) * 2];
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  if ((ushort)bVar1 != *(ushort *)(iVar2 + 0xc)) {
    sub_08127EAC(5,(uint)(ushort)(*(ushort *)(iVar2 + 0xc) + (ushort)*(byte *)(arg0 + 0x2c) * 0x100)
                );
  }
  sub_080AA184(0x8000f8c,0,0,1);
  if (5 < *(ushort *)(iVar2 + 10)) {
    if (*(short *)(iVar2 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(iVar2 + 0xc) + 5 != (uint)*(ushort *)(iVar2 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
  return;
}


// sub_0812BCD4 @ 0x0812BCD4

short * sub_0812BCD4(undefined4 arg0)

{
  short *psVar1;
  
  for (psVar1 = (short *)0x30051ac; *psVar1 != (short)arg0; psVar1 = psVar1 + 2) {
  }
  return psVar1;
}


// sub_0812BCF4 @ 0x0812BCF4

void sub_0812BCF4(int arg0)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)sub_0812BCD4((uint)*(byte *)(arg0 + 0x2c));
  puVar2 = (undefined4 *)sub_0812BCD4((uint)*(ushort *)(arg0 + 0x1e));
  uVar3 = *puVar1;
  *puVar1 = *puVar2;
  *puVar2 = uVar3;
  sub_0812B320(0xff);
  return;
}


// sub_0812BD1C @ 0x0812BD1C

void sub_0812BD1C(int arg0)

{
  uint uVar1;
  undefined4 arg1;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  sub_080EA210();
  uVar1 = sub_0812B320(0xff);
  uVar1 = uVar1 & 0xffff;
  if (uVar1 == 0) {
    arg1 = Menu_ExpandListTemplate(0x8124bf4,0);
    BattleMenu_SetMode(3,arg1);
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  else {
    DAT_0203c24c = sub_080ABC40(1,0,0x13,10);
    sub_081272AC();
    if (uVar1 < 5) {
      sub_08126928(4,0,1,uVar1);
    }
    else {
      sub_08126928(4,0x10,1,uVar1);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0812bd9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812BD9C @ 0x0812BD9C

void sub_0812BD9C(int arg0)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = sub_08126D1C(4);
  bVar1 = *(byte *)(iVar2 + 0xc);
  sub_08126A08(4);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_030031b8 & 1) != 0) {
      *(char *)(arg0 + 0x2c) = (char)(&DAT_0203c4d0)[(uint)*(ushort *)(iVar2 + 0x12) * 2];
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  if ((ushort)bVar1 != *(ushort *)(iVar2 + 0xc)) {
    sub_08127EAC(6,(uint)*(ushort *)(iVar2 + 0xc));
  }
  sub_080AA184(0x8000f8c,0,0,1);
  if (5 < *(ushort *)(iVar2 + 10)) {
    if (*(short *)(iVar2 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(iVar2 + 0xc) + 5 != (uint)*(ushort *)(iVar2 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
  return;
}


// sub_0812BE84 @ 0x0812BE84

void sub_0812BE84(void)

{
  int iVar1;
  
  DAT_0203c248 = sub_080AD0FC(0x87795d8,0xffff);
  *(undefined1 *)(DAT_0203c248 + 0x24) = 0;
  iVar1 = DAT_0203c248;
  sub_080EA964();
  *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;
  return;
}


// sub_0812BEB8 @ 0x0812BEB8

void sub_0812BEB8(int arg0)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  sub_080EA210();
  uVar1 = sub_0812B320(0xff);
  uVar1 = uVar1 & 0xffff;
  if (uVar1 == 0) {
    uVar2 = Menu_ExpandListTemplate(0x8124c38,0);
    BattleMenu_SetMode(3,uVar2);
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  else {
    DAT_0203c24c = sub_080ABC40(1,0,0x13,10);
    sub_081272AC();
    if (uVar1 < 5) {
      sub_08126928(4,0,1,uVar1);
    }
    else {
      sub_08126928(4,0x10,1,uVar1);
    }
    uVar2 = Menu_ExpandListTemplate(0x8124ce6,0);
    BattleMenu_SetMode(3,uVar2);
    sub_080EC99C(1);
  }
                    /* WARNING: Could not recover jumptable at 0x0812bf4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


