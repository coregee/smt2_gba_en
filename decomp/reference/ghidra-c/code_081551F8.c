/* Ghidra decompilation of asm/code_081551F8.s (reference only; not compiled). */

// sub_081551F8 @ 0x081551F8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081551F8(void)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  char local_1a;
  char local_19;
  
  if (_DAT_0203a464 == 0) {
    _DAT_0203a464 = sub_080AB860(3,0,0x12,2);
  }
  if (_DAT_0203a468 == 0) {
    _DAT_0203a468 = sub_080AB860(0x15,0,9,3);
  }
  local_20 = 0;
  REG_DMA3SAD = &local_20;
  REG_DMA3DAD = 0x200f874;
  REG_DMA3CNT = 0x85002000;
  uVar1 = REG_DMA3CNT;
  memset(&local_1c,0,8);
  sub_080A9CC0((uint)DAT_030046cd);
  local_1c = 0x4c;
  local_1b = 0x56;
  if (DAT_030046cd < 10) {
    local_19 = ' ';
    local_1a = DAT_030020e8;
  }
  else {
    local_19 = DAT_030020e8 + '0';
    local_1a = DAT_030020e9;
  }
  local_1a = local_1a + '0';
  sub_080C06BC(0);
  sub_080ACAB0(&local_1c,0x2016874,0,0);
  sub_08154F4C();
  sub_081551A8((uint)DAT_0203a45a);
                    /* WARNING: Could not recover jumptable at 0x081552e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081552E8 @ 0x081552E8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081552E8(int arg0,int arg1)

{
  undefined4 in_r2;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (arg1 == 0) {
    _DAT_0203a46c = sub_080AB860(2,0xb,0x1a,7);
    Font_ResetGlyphSpriteCache(0x180);
  }
  else if ((DAT_030031b8 & 1) == 0) {
    Text_DrawSpriteString(in_r2,0,0,0x12);
    if ((DAT_030031bc >> 4 & 1) == 0) {
      sub_080C4AB0(0,0,0xd5,0x8d);
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080AB91C(_DAT_0203a46c,1);
    sub_0815565C(1);
  }
  return;
}


// sub_08155374 @ 0x08155374

void sub_08155374(void)

{
  ushort uVar1;
  uint uVar2;
  dword arg0;
  undefined2 *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_08153F3C();
  for (uVar4 = 0; uVar4 < 6; uVar4 = uVar4 + 1 & 0xffff) {
    if (*(char *)(uVar4 + 0x30050e0) == '\0') {
      sub_080AA184(*(undefined4 *)(uVar4 * 4 + 0x834a23c),0,0,0);
      break;
    }
  }
  sub_080AA1F4(0x87e1c68,0,0,0);
  puVar3 = (undefined2 *)0x3002e50;
  puVar5 = &DAT_03003110;
  uVar1 = 0;
  do {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x10);
  puVar3 = (undefined2 *)0x3002a50;
  puVar5 = &DAT_03002d10;
  uVar1 = 0;
  do {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x10);
  sub_080AABB0();
  if (DAT_0203a456 == 2) {
    if ((ushort)(DAT_0203a454 - 2U) < 2) {
      arg0 = 0x815be68;
    }
    else if ((ushort)(DAT_0203a454 - 4U) < 2) {
      arg0 = 0x815bea6;
    }
    else {
      arg0 = 0x815bebe;
    }
  }
  else if (DAT_0203a456 < 3) {
    if (DAT_0203a456 != 1) goto LAB_081554cc;
    if ((ushort)(DAT_0203a454 - 2U) < 2) {
      arg0 = 0x815be50;
    }
    else {
      arg0 = 0x815be92;
    }
  }
  else {
    if (DAT_0203a456 != 3) goto LAB_081554cc;
    if (DAT_0203a454 != 3) {
      Text_DrawSpriteString(0x815bebe,0,0,0x1a);
      goto LAB_081554cc;
    }
    arg0 = 0x815be7e;
  }
  Text_DrawSpriteString(arg0,0,0,0x1a);
LAB_081554cc:
  sub_080C49EC(0x1a,4,2,0);
  if (DAT_0203a45a != 0) {
    sub_080C4A4C(4,2,0xe0,0x34);
  }
  if ((int)(DAT_0203a45a + 6) <= (int)((uVar2 & 0xffff) - 1)) {
    sub_080C4AB0(4,2,0xe0,0x92);
  }
                    /* WARNING: Could not recover jumptable at 0x08155506. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815550C @ 0x0815550C

void sub_0815550C(int arg0)

{
  *(undefined2 *)(arg0 + 0x1e) = DAT_0203a45e;
  return;
}


// sub_08155518 @ 0x08155518

uint sub_08155518(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  puVar1 = &DAT_0203a4b0;
  uVar3 = 0;
  do {
    if ((*(short *)(puVar1 + 0xe) != 0) && (puVar1 != DAT_0203a4a0)) {
      *(undefined **)(&DAT_0203a470 + uVar2 * 4) = puVar1;
      uVar2 = uVar2 + 1 & 0xffff;
    }
    uVar3 = uVar3 + 1;
    puVar1 = puVar1 + 0x80;
  } while (uVar3 < 0xc);
  return uVar2;
}


// sub_08155554 @ 0x08155554

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08155554(void)

{
  int iVar1;
  dword dVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar8 = 0xffff;
  if (DAT_0203a4a0 != 0) {
    uVar8 = (uint)*(ushort *)(DAT_0203a4a0 + 0x12);
  }
  uVar7 = 0xffff;
  if (DAT_0203a4a4 != 0) {
    uVar7 = (uint)*(ushort *)(DAT_0203a4a4 + 0x12);
  }
  uVar6 = 0xffff;
  if (_DAT_0203a4a8 != 0) {
    uVar6 = (uint)*(ushort *)(_DAT_0203a4a8 + 0x12);
  }
  sub_08153E9C();
  uVar4 = 0;
  if ((ushort)(DAT_0203a454 - 2U) < 2) {
    uVar5 = 0;
    do {
      iVar1 = sub_080C09B0(uVar5 + 4);
      if ((((iVar1 != 0) && (iVar1 = sub_080C0830(), iVar1 == 0)) &&
          (dVar2 = (dword)(short)(&DAT_030048d2)[uVar5 * 0x40], dVar2 != uVar8)) &&
         ((dVar2 != uVar7 && (dVar2 != uVar6)))) {
        *(uint *)(&DAT_0203a470 + uVar4 * 4) = uVar5 * 0x80 + 0x30048c0;
        uVar4 = uVar4 + 1 & 0xffff;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0xc);
    goto LAB_0815564c;
  }
  if (DAT_0203a454 != 4) {
    if (DAT_0203a454 != 5) goto LAB_0815564c;
    if (_DAT_0203a45c != 0) {
      if (_DAT_0203a45c == 1) {
        sub_08155518();
      }
      goto LAB_0815564c;
    }
  }
  puVar3 = &DAT_0203a4b0;
  uVar5 = 0;
  do {
    if (((*(short *)(puVar3 + 0xe) != 0) &&
        (dVar2 = (dword)*(short *)(puVar3 + 0x12), dVar2 != uVar8)) &&
       ((dVar2 != uVar7 && (dVar2 != uVar6)))) {
      *(undefined **)(&DAT_0203a470 + uVar4 * 4) = puVar3;
      uVar4 = uVar4 + 1 & 0xffff;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar3 + 0x80;
  } while (uVar5 < 0xc);
LAB_0815564c:
                    /* WARNING: Could not recover jumptable at 0x0815565a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815565C @ 0x0815565C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0815565C(uint arg0)

{
  uint uVar1;
  undefined4 unaff_r8;
  undefined4 arg2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = arg0 & 0xffff;
  (&DAT_0203a4a0)[uVar1 - 1] = 0;
  _DAT_0203a45c = (undefined2)(uVar1 - 1);
  sub_08155554();
  DAT_0203a458 = 0;
  DAT_0203a45a = 0;
  if (uVar1 == 1) {
    unaff_r8 = 0x24;
    arg2 = 0;
  }
  else {
    arg2 = unaff_r8;
    if (uVar1 == 2) {
      unaff_r8 = 0x32;
      arg2 = 0;
    }
  }
  sub_080AC7CC(0,0x200f874,arg2,unaff_r8);
                    /* WARNING: Could not recover jumptable at 0x081556bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081556C4 @ 0x081556C4

void sub_081556C4(void)

{
  undefined4 local_c;
  
  local_c = 0;
  CpuSet(&local_c,0x2011874,0x5000c00);
  sub_08154F4C();
  sub_081551A8((uint)DAT_0203a45a);
  return;
}


// sub_081556F8 @ 0x081556F8

void sub_081556F8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x81b4f10;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_0815571C @ 0x0815571C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0815571C(int arg0,uint arg1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_08153F3C();
  uVar2 = uVar2 & 0xffff;
  bVar1 = false;
  uVar6 = uVar2;
  if (5 < uVar2) {
    uVar6 = 6;
  }
  _DAT_0203a45c = (short)arg1;
  DAT_0203a456 = _DAT_0203a45c + 1;
  DAT_0203aab4 = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) != 0) {
      if (arg1 == 0) {
        DAT_030031cc = 1;
        *(undefined2 *)(arg0 + 0x1e) = 1;
        DAT_0203aab4 = 1;
      }
      else {
        sub_0815565C(arg1 & 0xffff);
        *(undefined2 *)(arg0 + 0x1e) = 1;
      }
      bVar1 = arg1 != 0;
      sub_080C51D4(0x66);
      goto LAB_0815590c;
    }
    if ((DAT_030031b8 & 0x200) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) == 0) goto LAB_0815590c;
        if ((uint)DAT_0203a458 == uVar6 - 1) {
          if ((DAT_0203a458 == 5) && ((int)(DAT_0203a45a + 6) <= (int)(uVar2 - 1))) {
            DAT_0203a45a = DAT_0203a45a + 1;
            bVar1 = true;
            sub_080C51D4(100);
          }
          goto LAB_0815590c;
        }
        DAT_0203a458 = DAT_0203a458 + 1;
      }
      else if (DAT_0203a458 == 0) {
        if (DAT_0203a45a == 0) goto LAB_0815590c;
        DAT_0203a45a = DAT_0203a45a - 1;
        bVar1 = true;
      }
      else {
        DAT_0203a458 = DAT_0203a458 - 1;
      }
      sub_080C51D4(100);
      goto LAB_0815590c;
    }
    *(undefined2 *)(arg0 + 0x1e) = 2;
  }
  else {
    uVar6 = (uint)DAT_0203a45a + (uint)DAT_0203a458 & 0xffff;
    iVar3 = *(int *)(&DAT_0203a470 + uVar6 * 4);
    iVar4 = sub_081544AC((uint)*(ushort *)(iVar3 + 0x12));
    if (iVar4 == 1) {
      iVar4 = arg1 << 1;
      if (arg1 == 0) {
        uVar2 = 0;
        do {
          iVar4 = *(int *)(uVar2 * 4 + 0x203a470);
          if (iVar4 == 0) {
            (&DAT_0203aac0)[uVar2 * 2] = 0xffff;
            (&DAT_0203aac2)[uVar2 * 2] = 0;
          }
          else {
            (&DAT_0203aac0)[uVar2 * 2] = *(undefined2 *)(iVar4 + 0x12);
            uVar5 = sub_080C2244();
            (&DAT_0203aac2)[uVar2 * 2] = (short)uVar5;
          }
          uVar2 = uVar2 + 1 & 0xffff;
          iVar4 = 0;
        } while (uVar2 < 0xc);
      }
      *(undefined2 *)(iVar4 + 0x203b854) = *(undefined2 *)(iVar3 + 0x12);
      sub_08153F6C(uVar6);
      uVar6 = 0;
      do {
        if (*(int *)(uVar6 * 4 + 0x203a4a0) != 0) {
          sub_081562EC(uVar6,(uint)*(ushort *)(uVar6 * 2 + 0x203b854),arg0);
        }
        uVar6 = uVar6 + 1 & 0xffff;
      } while (uVar6 < 3);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      DAT_030031cc = 0;
    }
  }
  sub_080C51D4(0x65);
LAB_0815590c:
  if ((DAT_030031bc >> 3 & 1) == 0) {
    sub_080AA184(0x80018c0,0,0xc,0);
  }
  else {
    sub_080AA184(0x80018d8,0,0xc,0);
  }
  sub_080ACFCC(3,0x81b6e50,0x3003150,0x20);
  sub_080AABB0();
  DisplayList_Add(0x81556f9,1);
  if (bVar1) {
    sub_081556C4();
  }
                    /* WARNING: Could not recover jumptable at 0x0815598a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// Fusion_DrawMaterialHeader @ 0x08155998

void Fusion_DrawMaterialHeader(undefined4 arg0,int arg1)

{
  char *pcVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char local_34;
  char local_33;
  undefined1 local_32;
  int local_30;
  uint local_2c;
  ushort *local_28;
  uint local_24;
  
  pcVar1 = (char *)sub_080BF648((uint)*(ushort *)((&DAT_0203a4a0)[arg1] + 0x12));
  puVar2 = (ushort *)Race_GetName((int)*pcVar1 & 0xffff);
  if (arg1 == 0) {
    local_30 = 0x24;
    sub_080ACBC8(0x87e1c70,0x200f874,6,0x26);
    sub_080ACAB0(0x87e1c74,0x200f874,0xe,0x28);
  }
  else if (arg1 == 1) {
    local_30 = 0x32;
    sub_080ACBC8(0x87e1c78,0x200f874,6,0x34);
    sub_080ACAB0(0x87e1c7c,0x200f874,0xe,0x36);
  }
  uVar5 = 0;
  local_28 = (ushort *)(pcVar1 + 0x22);
  uVar3 = 0x1e0000;
  do {
    Font_DrawGlyphTinted((uint)*puVar2,0x200f874,uVar3 >> 0x10,local_30);
    uVar3 = uVar3 + 0xc0000;
    puVar2 = puVar2 + 1;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 3);
  uVar3 = 0;
  if (*(short *)(pcVar1 + 0x22) != 0) {
    local_24 = 0x46;
    iVar4 = 0;
    uVar5 = 0x420000;
    local_2c = (local_30 + -2) * 0x10000;
    puVar2 = local_28;
    do {
      if (*pcVar1 == ',') {
        Font_DrawGlyphTinted((uint)*puVar2,0x200f874,local_24 & 0xffff,local_30);
      }
      else {
        sub_08153FC8((uint)*(ushort *)((int)local_28 + iVar4),0x200f874,uVar5 >> 0x10,
                     local_2c >> 0x10);
      }
      local_24 = local_24 + 0xc;
      puVar2 = puVar2 + 1;
      iVar4 = iVar4 + 2;
      uVar5 = uVar5 + 0xc0000;
      uVar3 = uVar3 + 1;
    } while ((uVar3 < 8) && (*(short *)((int)local_28 + iVar4) != 0));
  }
  if ((DAT_0203a454 != 1) && ((DAT_0203a454 != 4 && (DAT_0203a454 != 5)))) {
    uVar3 = local_30 + 2;
    sub_080ACBC8(0x87e1c44,0x200f874,0xa4,uVar3 & 0xffff);
    sub_080A9CC0((uint)(byte)pcVar1[1]);
    if ((byte)pcVar1[1] < 10) {
      local_33 = '\0';
      local_34 = DAT_030020e8;
    }
    else {
      local_33 = DAT_030020e8 + '0';
      local_32 = 0;
      local_34 = DAT_030020e9;
    }
    local_34 = local_34 + '0';
    sub_080ACBC8(&local_34,0x200f874,0xb4,uVar3 & 0xffff);
  }
  return;
}


// sub_08155BB8 @ 0x08155BB8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08155BB8(undefined4 arg0,uint arg1,int arg2)

{
  int local_10;
  
  if ((((((DAT_0203a454 != 2) || (arg1 != 1)) && ((DAT_0203a454 != 1 || (arg1 != 1)))) &&
       ((DAT_0203a454 != 4 || (arg1 != 1)))) && ((DAT_0203a454 != 3 || (arg1 != 2)))) &&
     ((DAT_0203a454 != 5 || (arg1 != 2)))) {
    if (arg2 == 0) {
      DAT_0203a458 = 0;
      DAT_0203a45a = 0;
    }
    if (arg1 < 2) {
      Fusion_DrawMaterialHeader(arg0,arg1);
    }
    if (arg2 == 0) {
      sub_08155554();
      _DAT_0203a45c = _DAT_0203a45c + 1;
      if (((DAT_0203a454 != 1) && (DAT_0203a454 != 4)) && (DAT_0203a454 != 5)) {
        local_10 = arg2;
        CpuSet(&local_10,0x2011874,0x5000c00);
        sub_08154F4C();
        sub_081551A8((uint)DAT_0203a45a);
      }
    }
  }
  return;
}


// sub_08155C40 @ 0x08155C40

void sub_08155C40(int arg0)

{
  undefined2 uVar1;
  
  switch(DAT_0203a454) {
  case 1:
  case 2:
  case 4:
    uVar1 = 2;
    break;
  case 3:
  case 5:
    uVar1 = 3;
    break;
  default:
    goto switchD_08155c56_default;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar1;
switchD_08155c56_default:
  return;
}


// sub_08155C80 @ 0x08155C80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08155C80(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  dword arg1;
  dword arg2;
  uint uVar4;
  ushort local_14 [2];
  
  if (_DAT_0203a464 != 0) {
    sub_080AB91C(_DAT_0203a464,1);
    _DAT_0203a464 = 0;
  }
  if (_DAT_0203a468 != 0) {
    sub_080AB91C(_DAT_0203a468,1);
    _DAT_0203a468 = 0;
  }
  if (DAT_0203a454 == 1) {
    arg1 = 0xffff;
    arg2 = (dword)DAT_0203b856;
  }
  else if (DAT_0203a454 == 4) {
    arg1 = (dword)DAT_0203b856;
    arg2 = 0xffff;
  }
  else {
    if (DAT_0203a454 != 5) {
      if ((ushort)(DAT_0203a454 - 2U) < 2) {
        sub_0815B260();
        uVar2 = sub_081572AC();
        DAT_0203b85a = (ushort)uVar2;
        if (0xfe < (uVar2 & 0xffff)) {
          DAT_0203b85a = 0xfb;
        }
        uVar2 = 0;
        do {
          *(undefined1 *)(uVar2 + 0x203b860) = *(undefined1 *)(uVar2 + 0x203b918);
          uVar2 = uVar2 + 1;
        } while (uVar2 < 7);
      }
      else if (DAT_0203a454 == 6) {
        uVar4 = 0;
        DAT_0203b85a = *(ushort *)(((uint)DAT_0203aaba + (uint)DAT_0203aabe) * 2 + 0x203b554) &
                       0x7fff;
        uVar2 = 0;
        do {
          *(undefined1 *)(uVar2 + 0x203b860) = 0xff;
          uVar2 = uVar2 + 1;
        } while (uVar2 < 7);
        uVar2 = 0;
        do {
          iVar3 = sub_080BF648((uint)DAT_0203b85a);
          cVar1 = *(char *)(iVar3 + 0x11 + uVar2);
          if (cVar1 != -1) {
            *(char *)(uVar4 + 0x203b860) = cVar1;
            uVar4 = uVar4 + 1 & 0xffff;
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < 7);
      }
      goto LAB_08155da2;
    }
    arg1 = (dword)DAT_0203b856;
    arg2 = (dword)DAT_0203b858;
  }
  sub_0815B884((uint)DAT_0203b854,arg1,arg2,local_14);
  DAT_0203b85a = local_14[0];
LAB_08155da2:
  CpuSet(0x203a454,0x203ac54,0x4000200);
  if (DAT_0203aab4 == 1) {
    *(undefined4 *)(DAT_0203a460 + 0xc) = 1;
  }
  else {
    sub_080AAF48(1);
  }
  return;
}


// sub_08155DF4 @ 0x08155DF4

void sub_08155DF4(void)

{
  if (DAT_0203b2b4 == 0) {
    DAT_030068e0 = sub_080CED00();
    DAT_0203a48c = DAT_0203ac60;
  }
  return;
}


// sub_08155E24 @ 0x08155E24

void sub_08155E24(int arg0)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  bVar1 = false;
  uVar2 = sub_08153F3C();
  uVar2 = uVar2 & 0xffff;
  uVar4 = uVar2;
  if (5 < uVar2) {
    uVar4 = 6;
  }
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar3 = (uint)DAT_0203a458;
  if ((int)*(short *)(*(int *)(&DAT_0203a470 + (uVar3 + DAT_0203a45a) * 4) + 0x12) ==
      (uint)DAT_0203aab0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else if (uVar3 == uVar4 - 1) {
    if ((uVar3 == 5) && ((int)(uVar3 + DAT_0203a45a + 1) <= (int)(uVar2 - 1))) {
      DAT_0203a45a = DAT_0203a45a + 1;
      bVar1 = true;
      sub_080C51D4(100);
    }
  }
  else {
    DAT_0203a458 = DAT_0203a458 + 1;
    sub_080C51D4(100);
  }
  if (bVar1) {
    sub_081556C4();
  }
                    /* WARNING: Could not recover jumptable at 0x08155ebe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08155EC0 @ 0x08155EC0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08155EC0(undefined4 arg0)

{
  sub_080AB91C(_DAT_0203a464,1);
  sub_080AB91C(_DAT_0203a468,1);
  sub_08157EB0(1,arg0,DAT_0203a460);
  DAT_030031cc = 1;
  return;
}


// sub_08155EF4 @ 0x08155EF4

void sub_08155EF4(void)

{
  undefined4 uVar1;
  undefined1 local_8 [8];
  
  sub_080C98A0();
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_08155F44 @ 0x08155F44

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08155F44(void)

{
  sub_080AB91C(_DAT_0203a464,1);
  sub_080AB91C(_DAT_0203a468,1);
  _DAT_0203a464 = 0;
  _DAT_0203a468 = 0;
  DisplayList_Add(0x8155ef5,1);
  return;
}


// sub_08155F74 @ 0x08155F74

void sub_08155F74(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_0203aab4 == 1);
  return;
}


// sub_08155F94 @ 0x08155F94

undefined4 sub_08155F94(undefined4 arg0)

{
  dword arg0_00;
  undefined4 uVar1;
  undefined4 uStack_14;
  
  if ((((short)arg0 == 1) || ((short)arg0 == 4)) || ((short)arg0 == 5)) {
    arg0_00 = 0x87e24cc;
  }
  else if ((short)arg0 == 6) {
    arg0_00 = 0x87e3360;
  }
  else {
    arg0_00 = 0x87e1c80;
  }
  uVar1 = sub_080AD0FC(arg0_00,0xffff);
  uStack_14 = 0;
  CpuSet(&uStack_14,0x203a454,0x5000200);
  DAT_0203a454 = (short)arg0;
  DAT_0203b85c = (short)arg0;
  return uVar1;
}


// sub_08156000 @ 0x08156000

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 sub_08156000(void)

{
  dword arg0;
  undefined4 uVar1;
  
  if (((DAT_0203b85c == 1) || (DAT_0203b85c == 4)) || (DAT_0203b85c == 5)) {
    arg0 = 0x87e2974;
  }
  else if (DAT_0203b85c == 6) {
    arg0 = 0x87e35f4;
  }
  else {
    arg0 = 0x87e2094;
  }
  uVar1 = sub_080AD0FC(arg0,0xffff);
  CpuSet(0x203ac54,0x203a454,0x4000200);
  if (((ushort)(DAT_0203a454 - 1U) < 2) || (DAT_0203a454 == 4)) {
    DAT_0203a4a4 = 0;
  }
  else if ((DAT_0203a454 == 3) || (DAT_0203a454 == 5)) {
    _DAT_0203a4a8 = 0;
  }
  return uVar1;
}


// sub_08156088 @ 0x08156088

undefined4 sub_08156088(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint arg2;
  uint arg0;
  int unaff_r10;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar4 = 0;
  arg0 = 0x40;
  arg2 = 0x156;
  if (DAT_0203a454 == 4) {
    unaff_r10 = 2;
  }
  else if (DAT_0203a454 < 5) {
    if (DAT_0203a454 == 1) {
      unaff_r10 = 0;
    }
  }
  else if (DAT_0203a454 == 5) {
    unaff_r10 = 1;
  }
  uVar3 = 0;
  do {
    uVar1 = sub_080C32D4(arg0);
    if (((uVar1 & 0xff) != 0) && (*(char *)(uVar3 * 4 + unaff_r10 + 0x87e248c) != '\0')) {
      sub_080C0444(&DAT_0203a4b0 + uVar4 * 0x80,1,arg2);
      *(undefined **)(&DAT_0203a470 + uVar4 * 4) = &DAT_0203a4b0 + uVar4 * 0x80;
      uVar4 = uVar4 + 1 & 0xffff;
    }
    uVar3 = uVar3 + 1 & 0xffff;
    arg0 = arg0 + 1 & 0xffff;
    arg2 = arg2 + 1 & 0xffff;
  } while (uVar3 < 0x10);
                    /* WARNING: Could not recover jumptable at 0x0815612c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar4);
  return uVar2;
}


// sub_08156134 @ 0x08156134

void sub_08156134(void)

{
  undefined4 uVar1;
  
  sub_08153E9C();
  uVar1 = sub_08156088();
  DAT_0203a456 = 1;
  DAT_0203aab2 = (undefined2)uVar1;
  sub_0815B880();
  DAT_03003bb4 = 0;
  return;
}


// sub_08156170 @ 0x08156170

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08156170(int arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203a454 == 1) {
    sub_08153E9C();
    uVar1 = sub_08153EB8();
LAB_081561aa:
    if ((uVar1 & 0xffff) != 0) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    if (DAT_0203a454 != 4) {
      if (DAT_0203a454 != 5) goto LAB_081561ca;
      if (_DAT_0203a45c != 0) {
        if (_DAT_0203a45c == 1) {
          sub_08153E9C();
          uVar1 = sub_08155518();
          goto LAB_081561aa;
        }
        if (_DAT_0203a45c != 2) goto LAB_081561ca;
        sub_08153E9C();
        uVar1 = sub_08153EB8();
        if ((uVar1 & 0xffff) == 0) goto LAB_081561ca;
      }
    }
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
LAB_081561ca:
                    /* WARNING: Could not recover jumptable at 0x081561ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081561D0 @ 0x081561D0

void sub_081561D0(int arg0)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 in_r1;
  undefined4 in_r2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = *(ushort *)(arg0 + 0x26);
  if (uVar1 == 1) {
    in_r2 = 0x14;
    in_r1 = 8;
  }
  else if (uVar1 < 2) {
    if (uVar1 == 0) {
      in_r2 = 0;
      in_r1 = 8;
    }
  }
  else if (uVar1 == 2) {
    in_r2 = 10;
    in_r1 = 2;
  }
  uVar2 = sub_080AB860(in_r2,in_r1,10,0xb);
  *(undefined4 *)(arg0 + 0x28) = uVar2;
                    /* WARNING: Could not recover jumptable at 0x08156214. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08156218 @ 0x08156218

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08156218(int arg0)

{
  ushort uVar1;
  undefined4 arg0_00;
  undefined4 in_r2;
  undefined4 in_r3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = *(ushort *)(arg0 + 0x26);
  if (uVar1 == 1) {
    in_r2 = 0xa0;
    in_r3 = 0x40;
  }
  else if (uVar1 < 2) {
    if (uVar1 == 0) {
      in_r2 = 0;
      in_r3 = 0x40;
    }
  }
  else if (uVar1 == 2) {
    in_r2 = 0x50;
    in_r3 = 0x10;
  }
  arg0_00 = sub_080C3D84(0,(uint)*(ushort *)(arg0 + 0x24),in_r2,in_r3);
  *(undefined4 *)(arg0 + 0x2c) = arg0_00;
  sub_080C3E40(arg0_00,0);
  _DAT_03002f50 = 0x10;
  DAT_03002f52 = 0x10;
                    /* WARNING: Could not recover jumptable at 0x08156274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815627C @ 0x0815627C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0815627C(int arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = (uint)DAT_030031b8;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      *(ushort *)(arg0 + 0x1c) = DAT_030031b8 & 2;
    }
    else {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      if (_DAT_0203a45c == *(short *)(arg0 + 0x26)) {
        DAT_0203a45e = 1;
        (&DAT_0203a4a0)[*(ushort *)(arg0 + 0x26)] = uVar1 & 1;
      }
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x081562ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081562D0 @ 0x081562D0

void sub_081562D0(int arg0)

{
  sub_080AB91C(*(undefined4 *)(arg0 + 0x28),1);
  sub_080C3E80(*(undefined4 *)(arg0 + 0x2c));
  return;
}


// sub_081562EC @ 0x081562EC

void sub_081562EC(undefined4 arg0,undefined4 arg1,int arg2)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x87e2e3c,(uint)*(ushort *)(arg2 + 2));
  *(undefined2 *)(iVar1 + 0x24) = (undefined2)arg1;
  *(undefined2 *)(iVar1 + 0x26) = (undefined2)arg0;
  DAT_0203a45e = 0;
  return;
}


// sub_0815631C @ 0x0815631C

void sub_0815631C(int arg0)

{
  undefined2 uVar1;
  undefined4 local_14;
  
  uVar1 = *(undefined2 *)
           (*(int *)(&DAT_0203a470 + ((uint)DAT_0203a458 + (uint)DAT_0203a45a) * 4) + 0x12);
  sub_080AD0FC(0x84f1368,(uint)*(ushort *)(arg0 + 2));
  CpuSet(0x203a454,0x203ac54,0x4000200);
  local_14 = 0;
  CpuSet(&local_14,0x203a454,0x5000200);
  DAT_0203a456 = uVar1;
  DAT_0203a454 = 7;
  DAT_0203a476 = 0;
  return;
}


// sub_0815637C @ 0x0815637C

void sub_0815637C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x81b93b0;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84001f00;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_081563B8 @ 0x081563B8

void sub_081563B8(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x85001f00;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_081563F4 @ 0x081563F4

void sub_081563F4(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 arg0;
  dword dVar3;
  undefined4 uVar4;
  uint arg0_00;
  undefined4 local_1c;
  
  arg0_00 = *(ushort *)(((uint)DAT_0203aabe + (uint)DAT_0203aaba) * 2 + 0x203b554) & 0x7fff;
  pcVar1 = (char *)sub_080BF648(arg0_00);
  iVar2 = sub_0815B864();
  arg0 = sub_081571DC(arg0_00);
  local_1c = 0;
  CpuSet(&local_1c,0x200f874,0x5002000);
  sub_080CCE5C(0x87e1c44,0x82,0x45,4);
  if ((byte)pcVar1[1] < 10) {
    sub_080CCF44((uint)(byte)pcVar1[1],0xd4,0x45,0);
  }
  else {
    sub_080CCF44((uint)(byte)pcVar1[1],0xd4,0x45,0);
  }
  sub_080CCE5C(0x87e3250,0x82,0x4f,4);
  if (*pcVar1 < '\r') {
    dVar3 = 0x87e3254;
    uVar4 = 0xb4;
LAB_081564be:
    sub_080CCE5C(dVar3,uVar4,0x4f,0);
  }
  else {
    if (*pcVar1 < '\x1b') {
      dVar3 = 0x87e325c;
      uVar4 = 0xa4;
      goto LAB_081564be;
    }
    sub_080CCE5C(0x87e3264,0xbc,0x4f,0);
  }
  if (iVar2 == 0) {
    dVar3 = 0x87e326c;
    uVar4 = 0xc4;
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        sub_080CCE5C(0x87e3270,0xb4,0x59,0);
      }
      goto LAB_08156528;
    }
    dVar3 = 0x87e325c;
    uVar4 = 0xa4;
  }
  sub_080CCE5C(dVar3,uVar4,0x59,0);
LAB_08156528:
  sub_080CCE5C(0x87e3278,0x82,99,4);
  sub_080CCF44(arg0,0xd4,99,0);
  DisplayList_Add(0x815637d,1);
  return;
}


// sub_0815656C @ 0x0815656C

void sub_0815656C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  REG_BG1CNT = 0x8209;
  return;
}


// sub_0815659C @ 0x0815659C

void sub_0815659C(void)

{
  DisplayList_Add(0x815656d,1);
  sub_080C1440();
  return;
}


// sub_081565B4 @ 0x081565B4

void sub_081565B4(undefined4 arg0,undefined4 arg1)

{
  dword arg0_00;
  undefined4 local_24;
  
  switch(arg1) {
  case 0:
    local_24 = 0;
    CpuSet(&local_24,0x2000000,0x5000400);
    DisplayList_Add(0x81563b9,1);
    break;
  case 1:
    arg0_00 = 0x87e2e84;
    goto LAB_08156632;
  case 2:
    arg0_00 = 0x87e3044;
LAB_08156632:
    sub_080AB250(arg0_00,0x2000000,0,0);
    break;
  case 4:
    sub_080AB390(0x8770a24,0x2000000,0,0);
    sub_080AB250(0x81b8170,0x2000000,0,0);
    sub_080AB250(0x81b8170,0x2000000,0,0);
    sub_081563F4();
  }
  return;
}


// sub_081566C4 @ 0x081566C4

void sub_081566C4(void)

{
  DAT_0203a460 = sub_080B6B58(0x815468d,1);
  return;
}


// sub_081566E0 @ 0x081566E0

uint sub_081566E0(void)

{
  return (uint)DAT_0203aab8;
}


// sub_081566F4 @ 0x081566F4

undefined4 sub_081566F4(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_081566E0();
  uVar3 = uVar1 & 0xff;
  if (uVar3 == 1) {
    uVar1 = 10;
  }
  else if (uVar3 < 2) {
    if (uVar3 == 0) {
      uVar1 = 0x25;
    }
  }
  else if (uVar3 == 2) {
    uVar1 = 8;
  }
                    /* WARNING: Could not recover jumptable at 0x08156720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar2;
}


// sub_08156724 @ 0x08156724

void sub_08156724(void)

{
  sub_080AA184(0x8002164,0,0,0);
  Text_DrawSpriteString(0x87e327e,0,0,8);
  Text_DrawSpriteString(0x87e3288,0,0,8);
  Text_DrawSpriteString(0x87e3292,0,0,8);
  return;
}


// sub_081567A4 @ 0x081567A4

void sub_081567A4(undefined4 arg0)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_081566E0();
  uVar1 = uVar1 & 0xff;
  uVar2 = (uint)DAT_0203aabd;
  sub_08156724();
  sub_080AA184(0x8002198,0,0,0);
  if (uVar1 == 1) {
    uVar1 = 0;
    do {
      Text_DrawSpriteString(*(undefined4 *)((uVar2 + uVar1) * 4 + 0x87e32a0),0,0,0x58);
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 3);
  }
  else if (uVar1 < 2) {
    if (uVar1 == 0) {
      uVar1 = 0;
      do {
        iVar3 = Race_GetName((uint)*(ushort *)((uVar2 + uVar1) * 2 + 0x87e3204));
        uVar4 = 0;
        do {
          FontSprite_DrawGlyph((uint)*(ushort *)(uVar4 * 2 + iVar3),0,0,uVar4 * 0xc + 0x58);
          uVar4 = uVar4 + 1 & 0xff;
        } while (uVar4 < 8);
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 3);
    }
  }
  else if (uVar1 == 2) {
    uVar1 = 0;
    do {
      Text_DrawSpriteString(*(undefined4 *)((uVar2 + uVar1) * 4 + 0x87e3340),0,0,0x58);
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 3);
  }
  if (DAT_0203aabd != 0) {
    sub_080C4A4C(0,0,0xa0,4);
  }
  uVar2 = (uint)DAT_0203aabd;
  uVar1 = sub_081566F4();
  if ((int)(uVar2 + 3) <= (int)((uVar1 & 0xffff) - 1)) {
    sub_080C4AB0(0,0,0xa0,0x2c);
  }
                    /* WARNING: Could not recover jumptable at 0x08156914. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08156924 @ 0x08156924

void sub_08156924(undefined4 arg0)

{
  undefined4 arg0_00;
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  sub_08156724();
  sub_081567A4(arg0);
  sub_080AA184(0x80021e4,0,0,0);
  sub_080C7664(0x16,2,DAT_03005198);
  sub_080AA184(0x80007fc,0,0,0);
  arg0_00 = sub_080C3168();
  sub_080C7FD0(arg0_00,0xb8,5,0);
  uVar3 = 0;
  do {
    uVar4 = (uint)*(ushort *)((DAT_0203aabe + uVar3) * 2 + 0x203b554);
    if (uVar4 != 0xffff) {
      uVar4 = uVar4 & 0x7fff;
      iVar1 = sub_080BF648(uVar4);
      uVar2 = 0;
      do {
        sub_081571F0(uVar4);
        sub_080AC2A0((uint)*(ushort *)(uVar2 * 2 + iVar1 + 0x22),0,0,uVar2 * 0xc + 8 & 0xffff);
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < 8);
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 6);
  if (DAT_0203aabe != 0) {
    sub_080C4A4C(0,0,0x72,0x3c);
  }
  uVar3 = (uint)DAT_0203aabe;
  iVar1 = sub_081571AC();
  if (uVar3 + 6 <= iVar1 - 1U) {
    sub_080C4AB0(0,0,0x72,0x7e);
  }
  return;
}


// sub_08156AB0 @ 0x08156AB0

void sub_08156AB0(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0203aab4 = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          if (DAT_0203aab8 == '\x02') {
            DAT_0203aab8 = '\0';
          }
          else {
            DAT_0203aab8 = DAT_0203aab8 + '\x01';
          }
          sub_080C51D4(100);
        }
      }
      else {
        if (DAT_0203aab8 == '\0') {
          DAT_0203aab8 = '\x02';
        }
        else {
          DAT_0203aab8 = DAT_0203aab8 + -1;
        }
        sub_080C51D4(100);
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined2 *)(arg0 + 0x1e) = 1;
      sub_080C51D4(0x66);
      DAT_0203aab4 = 1;
    }
  }
  else {
    DAT_0203aab9 = 0;
    DAT_0203aabd = 0;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    *(undefined2 *)(arg0 + 0x1e) = 0;
    sub_080C51D4(0x65);
  }
                    /* WARNING: Could not recover jumptable at 0x08156b72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08156B74 @ 0x08156B74

void sub_08156B74(int arg0,uint arg1,uint arg2,byte *arg3)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  byte *in_stack_00000000;
  int in_stack_00000004;
  uint local_28;
  
  uVar6 = arg2 & 0xffff;
  uVar7 = arg1 & 0xffff;
  local_28 = uVar7;
  if (uVar6 <= uVar7) {
    local_28 = uVar6;
  }
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) != 0) {
    if ((in_stack_00000004 == 0) ||
       (iVar4 = sub_081571F0(*(ushort *)(((uint)*arg3 + (uint)*in_stack_00000000) * 2 + 0x203b554) &
                             0x7fff), iVar4 != 0)) {
      *(undefined2 *)(arg0 + 0x1e) = 0;
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_080C51D4(0x65);
    }
    else {
      sub_080C51D4(0x66);
    }
    goto LAB_08156da4;
  }
  if ((DAT_030031b8 & 2) != 0) {
    *(undefined2 *)(arg0 + 0x1e) = 1;
    sub_080C51D4(0x66);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    goto LAB_08156da4;
  }
  if ((DAT_03003964 & 0x40) == 0) {
    if ((DAT_03003964 & 0x80) == 0) {
      cVar2 = (char)uVar6;
      if (((DAT_03003964 & 0x200) == 0) || (uVar7 <= uVar6)) {
        if (((DAT_03003964 & 0x100) == 0) || (uVar7 <= uVar6)) goto LAB_08156da4;
        bVar3 = *arg3;
        bVar1 = *in_stack_00000000;
        Font_ResetGlyphSpriteCache(0x180);
        if ((uint)*arg3 == uVar6 - 1) {
          if ((int)((uint)*arg3 + (uint)*in_stack_00000000 + uVar6) < (int)(uVar7 - 1)) {
            *in_stack_00000000 = *in_stack_00000000 + cVar2;
            goto joined_r0x08156d72;
          }
          *in_stack_00000000 = (char)uVar7 - cVar2;
          if (in_stack_00000004 == 1) {
            sub_081563F4();
          }
        }
        else {
          *arg3 = (byte)(uVar6 - 1);
joined_r0x08156d72:
          if (in_stack_00000004 == 1) {
            sub_081563F4();
          }
        }
        if ((bVar3 != *arg3) || (bVar1 != *in_stack_00000000)) {
          sub_080C51D4(100);
        }
        goto LAB_08156da4;
      }
      bVar3 = *arg3;
      bVar1 = *in_stack_00000000;
      Font_ResetGlyphSpriteCache(0x180);
      if (*arg3 == 0) {
        if ((int)(uVar6 - 1) <= (int)(uint)*in_stack_00000000) {
          *in_stack_00000000 = (*in_stack_00000000 + 1) - cVar2;
          goto joined_r0x08156cf6;
        }
        *in_stack_00000000 = 0;
        if (in_stack_00000004 == 1) {
          sub_081563F4();
        }
      }
      else {
        *arg3 = 0;
joined_r0x08156cf6:
        if (in_stack_00000004 == 1) {
          sub_081563F4();
        }
      }
      if ((bVar3 != *arg3) || (bVar1 != *in_stack_00000000)) {
        sub_080C51D4(100);
      }
      goto LAB_08156da4;
    }
    Font_ResetGlyphSpriteCache(0x180);
    uVar5 = (uint)*arg3;
    if (uVar5 == local_28 - 1) {
      if ((uVar5 != uVar6 - 1) || ((int)(uVar7 - 1) < (int)(uVar5 + *in_stack_00000000 + 1)))
      goto LAB_08156da4;
      bVar3 = *in_stack_00000000 + 1;
      goto LAB_08156c9a;
    }
    *arg3 = *arg3 + 1;
    sub_080C51D4(100);
  }
  else {
    Font_ResetGlyphSpriteCache(0x180);
    if (*arg3 == 0) {
      if (*in_stack_00000000 == 0) goto LAB_08156da4;
      bVar3 = *in_stack_00000000 - 1;
LAB_08156c9a:
      *in_stack_00000000 = bVar3;
      sub_080C51D4(100);
    }
    else {
      *arg3 = *arg3 - 1;
      sub_080C51D4(100);
    }
  }
  if (in_stack_00000004 == 1) {
    sub_081563F4();
  }
LAB_08156da4:
                    /* WARNING: Could not recover jumptable at 0x08156db2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08156DB4 @ 0x08156DB4

void sub_08156DB4(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_081566F4();
  sub_08156B74(arg0,uVar1 & 0xffff,3,&DAT_0203aab9);
  if (*(short *)(arg0 + 0x1c) != 0) {
    DAT_0203aaba = 0;
    DAT_0203aabe = 0;
    sub_08156ECC(arg0,DAT_0203aab8 + 1,(uint)DAT_0203aab9 + (uint)DAT_0203aabd,1);
  }
  return;
}


// sub_08156E2C @ 0x08156E2C

void sub_08156E2C(undefined4 arg0)

{
  uint uVar1;
  
  uVar1 = sub_081571AC();
  sub_08156B74(arg0,uVar1 & 0xffff,6,&DAT_0203aaba);
  return;
}


// sub_08156E64 @ 0x08156E64

void sub_08156E64(void)

{
  undefined4 local_8 [2];
  
  DAT_03003bb4 = 0;
  local_8[0] = 0;
  CpuSet(local_8,0x200f874,0x5002000);
  DisplayList_Add(0x81563b9,1);
  return;
}


// sub_08156E98 @ 0x08156E98

void sub_08156E98(void)

{
  undefined4 in_r0;
  
  sub_08156ECC(in_r0,DAT_0203aab8 + 1,(uint)DAT_0203aab9 + (uint)DAT_0203aabd,0);
  return;
}


// sub_08156ECC @ 0x08156ECC

/* WARNING: Removing unreachable block (ram,0x08156f98) */

void sub_08156ECC(undefined4 arg0,int arg1,uint arg2,int arg3)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 local_30 [2];
  int local_2c;
  uint local_28;
  ushort *puStack_24;
  
  puVar10 = (ushort *)0x203b554;
  local_28 = 0;
  bVar1 = false;
  local_30[0] = 0xffff;
  local_2c = arg3;
  CpuSet(local_30,0x203b554,0x1000180);
  if (arg1 == 0) {
    uVar7 = 0;
    do {
      iVar3 = sub_080C28CC(uVar7);
      if (iVar3 != 0) {
        *puVar10 = (ushort)uVar7;
        puVar10 = puVar10 + 1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x17c);
  }
  else if (arg1 == 1) {
    uVar7 = 0;
    uVar8 = 0;
    do {
      iVar3 = sub_080C28CC(uVar8);
      if (iVar3 != 0) {
        pcVar4 = (char *)sub_080BF648(uVar8 & 0xffff);
        if ((int)*pcVar4 == (uint)*(ushort *)(arg2 * 2 + 0x87e3204)) {
          *(short *)(uVar7 * 2 + 0x203b554) = (short)uVar8;
          if (!bVar1) {
            bVar1 = true;
            local_28 = uVar7;
          }
        }
        else {
          *(short *)(uVar7 * 2 + 0x203b554) = (short)uVar8 + -0x8000;
        }
        uVar7 = uVar7 + 1 & 0xffff;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0xff);
  }
  else if (arg1 == 2) {
    puVar6 = (ushort *)0x0;
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0x58;
    do {
      puStack_24 = puVar6;
      iVar3 = sub_080C28CC(uVar7);
      puVar6 = puStack_24;
      if (iVar3 != 0) {
        *puVar10 = (ushort)uVar7;
        uVar5 = (uint)*(ushort *)(uVar8 * 4 + 0x8585c36);
        if (uVar5 != arg2) {
          *puVar10 = (ushort)uVar7 | 0x8000;
        }
        puVar10 = puVar10 + 1;
        if ((puStack_24 == (ushort *)0x0) && (uVar5 == arg2)) {
          puVar6 = (ushort *)0x1;
          local_28 = uVar9;
        }
        uVar9 = uVar9 + 1 & 0xffff;
      }
      uVar8 = uVar8 + 1 & 0xffff;
    } while ((uVar8 < 0x17c) && (uVar7 = (uint)*(ushort *)(uVar8 * 4 + 0x8585c34), uVar7 != 0xffff))
    ;
  }
  else if (arg1 == 3) {
    puVar6 = (ushort *)sub_080C9210(2);
    uVar2 = *puVar6;
    while (uVar2 != 0xffff) {
      iVar3 = sub_080C28CC((uint)*puVar6);
      if (iVar3 != 0) {
        *puVar10 = *puVar6;
        puVar10 = puVar10 + 1;
      }
      puVar6 = puVar6 + 2;
      uVar2 = *puVar6;
    }
    uVar7 = 0;
    puVar10 = (ushort *)0x203b554;
    do {
      if (*puVar10 == 0xffff) {
        local_28 = 0;
        break;
      }
      uVar8 = (arg2 + 1) * 0xa0000 - 0x10000 >> 0x10;
      puStack_24 = puVar10;
      iVar3 = sub_080BF648(*puVar10 & 0x7fff);
      if (arg2 == 0) {
        uVar9 = 1;
      }
      else {
        uVar9 = arg2 * 0xa0000 >> 0x10;
      }
      if (100 < uVar8) {
        uVar8 = 200;
      }
      if ((uVar9 <= *(byte *)(iVar3 + 1)) && (*(byte *)(iVar3 + 1) <= uVar8)) {
        local_28 = uVar7 & 0xffff;
        break;
      }
      puVar10 = puStack_24 + 1;
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x17c);
    uVar7 = 0;
    if (DAT_0203b554 != -1) {
      puVar10 = (ushort *)0x203b554;
      do {
        uVar8 = ((arg2 + 1) * 5 & 0x7fff) << 1;
        if (100 < uVar8) {
          uVar8 = 200;
        }
        iVar3 = sub_080BF648(*puVar10 & 0x7fff);
        if (*(byte *)(iVar3 + 1) < uVar8) {
          if ((arg2 != 0) &&
             (iVar3 = sub_080BF648(*puVar10 & 0x7fff), (uint)*(byte *)(iVar3 + 1) < arg2 * 10)) {
            uVar2 = *puVar10;
            goto LAB_08157124;
          }
        }
        else {
          uVar2 = *puVar10;
LAB_08157124:
          *puVar10 = uVar2 | 0x8000;
        }
        puVar10 = puVar10 + 1;
        uVar7 = uVar7 + 1;
      } while ((uVar7 < 0x17c) && (*puVar10 != 0xffff));
    }
  }
  if (local_2c == 1) {
    uVar7 = sub_081571AC();
    uVar7 = uVar7 & 0xffff;
    DAT_0203aabe = '\0';
    DAT_0203aaba = '\0';
    if (uVar7 < 7) {
      DAT_0203aaba = (char)local_28;
    }
    else {
      DAT_0203aabe = (char)local_28;
      if ((int)(uVar7 - 7) < (int)local_28) {
        DAT_0203aaba = ((char)local_28 + '\x06') - (char)uVar7;
        DAT_0203aabe = (char)local_28 - DAT_0203aaba;
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x081571aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081571AC @ 0x081571AC

int sub_081571AC(void)

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


// sub_081571DC @ 0x081571DC

int sub_081571DC(undefined4 arg0)

{
  int iVar1;
  
  iVar1 = sub_080C10A8();
  return iVar1 * 5;
}


// sub_081571F0 @ 0x081571F0

undefined4 sub_081571F0(uint arg0)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar5 = arg0 & 0xffff;
  iVar1 = sub_080BF648(uVar5);
  iVar2 = sub_080C0148(0x8000);
  uVar3 = sub_081571DC(uVar5);
  if (((*(byte *)(iVar2 + 0xd) < *(byte *)(iVar1 + 1)) || (iVar1 = sub_0815BA28(uVar5), iVar1 == 0))
     || (uVar5 = sub_080C3100(), uVar5 < uVar3)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x08157234. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar4);
  return uVar4;
}


// sub_08157238 @ 0x08157238

undefined4 sub_08157238(undefined4 arg0)

{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 in_r2;
  uint uVar4;
  uint arg0_00;
  int iVar5;
  int unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = 0x40;
  sVar1 = 0;
  if ((ushort)arg0 == 3) {
    iVar5 = 2;
  }
  else {
    iVar5 = unaff_r8;
    if ((ushort)arg0 < 4) {
      if ((ushort)arg0 == 2) {
        iVar5 = 0;
      }
    }
    else if ((ushort)arg0 == 4) {
      iVar5 = 1;
    }
  }
  uVar4 = 0;
  do {
    uVar2 = sub_080C32D4(arg0_00);
    if (((uVar2 & 0xff) != 0) && (*(char *)(iVar5 + uVar4 * 4 + 0x87e248c) != '\0')) {
      sVar1 = sVar1 + 1;
    }
    uVar4 = uVar4 + 1 & 0xffff;
    arg0_00 = arg0_00 + 1 & 0xffff;
  } while (uVar4 < 0x10);
                    /* WARNING: Could not recover jumptable at 0x081572a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(sVar1,UNRECOVERED_JUMPTABLE,in_r2,unaff_r8);
  return uVar3;
}


// sub_081572AC @ 0x081572AC

undefined4 sub_081572AC(void)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined1 auStack_c [4];
  
  if (DAT_0203b85c == 2) {
    DAT_0203b8f8 = DAT_0203b854;
    DAT_0203b8fa = DAT_0203b856;
    DAT_0203b8fc = 0xffff;
    sub_0815B4B4();
    sub_08158970();
    sub_0815B260();
  }
  else if (DAT_0203b85c == 3) {
    DAT_0203b8f8 = DAT_0203b854;
    DAT_0203b8fa = DAT_0203b856;
    DAT_0203b8fc = DAT_0203b858;
    sub_08154074();
    sub_0815B4B4();
    sub_081596F0();
    sub_0815B260();
  }
  else if (DAT_0203b85c == 1) {
    sub_0815B884((uint)DAT_0203b854,0xffff,(uint)DAT_0203b856,auStack_c);
  }
  else if (DAT_0203b85c == 4) {
    sub_0815B884((uint)DAT_0203b854,(uint)DAT_0203b856,0xffff,auStack_c);
  }
  else if (DAT_0203b85c == 5) {
    sub_0815B884((uint)DAT_0203b854,(uint)DAT_0203b856,(uint)DAT_0203b858,auStack_c);
  }
                    /* WARNING: Could not recover jumptable at 0x08157398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)();
  return uVar1;
}


// sub_0815739C @ 0x0815739C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0815739C(void)

{
  short sVar1;
  uint uVar2;
  
  sVar1 = DAT_0203b85c;
  if (((DAT_0203a454 == 0) && ((ushort)(DAT_0203b85c - 2U) < 2)) &&
     (uVar2 = sub_0815B11C(), (uVar2 & 0xffff) != 0xffff)) {
    DAT_0203a4d6 = DAT_0203b85a;
    DAT_0203b85a = (undefined2)uVar2;
    _DAT_0203a4d4 = 1;
  }
  if ((((ushort)(sVar1 - 1U) < 2) || (sVar1 == 4)) || (sVar1 == 6)) {
    _DAT_0203a45c = 0x87f01ac;
  }
  else if ((sVar1 == 3) || (sVar1 == 5)) {
    _DAT_0203a45c = 0x87f01dc;
  }
  _DAT_0203a468 = DAT_02036094;
  DAT_02036094 = 0;
  _DAT_0203a46c = DAT_02036074;
  DAT_0203a46e = DAT_02036076;
  DAT_02036074 = 0;
  DAT_02036076 = 0;
  sub_080C5170(0x10);
  return;
}


// sub_08157434 @ 0x08157434

void sub_08157434(void)

{
  Field_SetState(0x19);
  return;
}


// sub_08157440 @ 0x08157440

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08157440(void)

{
  _DAT_0203a464 = sub_080B6BB0(0x8157435);
  return;
}


// sub_0815745C @ 0x0815745C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0815745C(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(*(int *)(_DAT_0203a464 + 0xc) == -1);
  return;
}


// sub_08157480 @ 0x08157480

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08157480(void)

{
  *(undefined4 *)(_DAT_0203a464 + 0xc) = 1;
  return;
}


// sub_08157490 @ 0x08157490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08157490(undefined4 arg0,uint arg1)

{
  if (arg1 < 6) {
    LZ77UnCompWram(*(undefined4 *)(arg1 * 4 + 0x87e5d3c),arg1 * 0x1000 + 0x2001000,0x2001000);
  }
  else {
    LZ77UnCompWram(*_DAT_0203a45c,0x2003920,arg1);
  }
  return;
}


// sub_081574D0 @ 0x081574D0

void sub_081574D0(void)

{
  dword arg0;
  undefined4 in_r2;
  
  if ((((ushort)(DAT_0203b85c - 1U) < 2) || (DAT_0203b85c == 4)) || (DAT_0203b85c == 6)) {
    arg0 = 0x87ef03c;
  }
  else {
    arg0 = 0x87ef5a0;
  }
  LZ77UnCompWram(arg0,0x2000800,in_r2);
  sub_080AB250(0x2000800,0x2000000,0,6);
  return;
}


// sub_08157534 @ 0x08157534

void sub_08157534(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84001b00;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  sub_081574D0();
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  REG_BG1CNT = 0x8205;
  REG_BG2CNT = 0x8406;
  REG_BG3CNT = 0x8607;
  DAT_03000040 = 0x3c42;
  DAT_03000042 = 0x808;
  DAT_03000044 = 0x10;
  return;
}


// sub_081575D8 @ 0x081575D8

void sub_081575D8(void)

{
  short sVar1;
  dword arg0;
  undefined4 in_r2;
  
  sVar1 = DAT_0203b85c;
  LZ77UnCompWram(0x87e5d48,0x2006800,in_r2);
  if ((((ushort)(sVar1 - 1U) < 2) || (sVar1 == 4)) || (sVar1 == 6)) {
    arg0 = 0x87efb04;
  }
  else {
    arg0 = 0x87efcd8;
  }
  LZ77UnCompWram(arg0,0x2000800,in_r2);
  sub_080AB250(0x2000800,0x2000000,0x2c0,2);
  return;
}


// sub_0815764C @ 0x0815764C

void sub_0815764C(void)

{
  sub_080C1384();
  sub_080ACFCC(3,0x87eff4c,0x30029f0,0x40);
  sub_080ACFCC(3,0x87effcc,&DAT_03002a70,0x140);
  DisplayList_Add(0x8157535,1);
  return;
}


// sub_08157698 @ 0x08157698

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08157698(void)

{
  _DAT_0203a470 = sub_080AB090(0,0x1d0,1,0x8001);
  return;
}


// sub_081576BC @ 0x081576BC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081576BC(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_080AB178(_DAT_0203a470);
  *(ushort *)(arg0 + 0x1c) = (ushort)((uVar1 & 0xffff) == 0);
  return;
}


// sub_081576E4 @ 0x081576E4

void sub_081576E4(undefined4 arg0,int arg1)

{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  dword in_r3;
  uint unaff_r6;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((arg1 == 2) && (((ushort)(DAT_0203b85c - 1U) < 2 || (DAT_0203b85c == 4)))) goto LAB_08157790;
  if (arg1 == 1) {
    in_r3 = 0x82;
    unaff_r6 = 0x4a;
  }
  else if (arg1 == 0) {
    in_r3 = 0xfff5;
    unaff_r6 = 0x4a;
  }
  else if (arg1 == 2) {
    in_r3 = 0x46;
    unaff_r6 = 0x21;
  }
  else if (arg1 == 3) {
    in_r3 = 0x3b;
    unaff_r6 = 0x2e;
  }
  sVar1 = *(short *)(arg1 * 2 + 0x203b854);
  if (sVar1 == 0x13b) {
    unaff_r6 = unaff_r6 - 3 & 0xffff;
  }
  else {
    if (sVar1 == 0x13c) {
      uVar2 = in_r3 + 1;
    }
    else {
      if (sVar1 != 0x13f) goto LAB_08157774;
      uVar2 = in_r3 - 1;
    }
    in_r3 = uVar2 & 0xffff;
  }
LAB_08157774:
  uVar3 = sub_080C3D84(0,(uint)*(ushort *)(arg1 * 2 + 0x203b854),in_r3,unaff_r6);
  *(undefined4 *)(&DAT_0203a474 + arg1 * 4) = uVar3;
LAB_08157790:
                    /* WARNING: Could not recover jumptable at 0x0815779a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081577A0 @ 0x081577A0

void sub_081577A0(undefined4 arg0,int arg1)

{
  int arg0_00;
  
  arg0_00 = *(int *)(&DAT_0203a474 + arg1 * 4);
  if ((arg1 != 2) || ((1 < (ushort)(DAT_0203b85c - 1U) && (DAT_0203b85c != 4)))) {
    if (arg0_00 != 0) {
      *(dword *)(arg0_00 + 0x20) = 0x80c3c69;
    }
    if (arg1 == 3) {
      sub_080C3E40(arg0_00,0);
    }
  }
  return;
}


// sub_081577E8 @ 0x081577E8

void sub_081577E8(undefined4 arg0,int arg1,int arg2)

{
  if (arg1 == 0) {
    sub_080ACFCC(3,0x87effac,arg2 * 0x20 + 0x30029f0,0x20);
    sub_080AB054(arg2 * 0x100000 + 0x500000U >> 0x10,0x10,1,0x20);
  }
  else {
    sub_080ACFCC(3,0x87eff4c,(uint)DAT_0203a486 * 0x20 + 0x30029f0,0x20);
    sub_080AB054((uint)DAT_0203a486 * 0x100000 + 0x500000 >> 0x10,0x10,1,0x20);
  }
  return;
}


// sub_08157868 @ 0x08157868

void sub_08157868(undefined4 arg0,int arg1)

{
  sub_080C3E64(*(undefined4 *)(&DAT_0203a474 + arg1 * 4));
  DAT_0203a45a = 0;
  return;
}


// sub_08157888 @ 0x08157888

void sub_08157888(int arg0,int arg1)

{
  ushort uVar1;
  dword arg0_00;
  uint *puVar2;
  uint *puVar3;
  
  if (3 < DAT_0203a45a) {
    sub_080C3E80(*(undefined4 *)(&DAT_0203a474 + arg1 * 4));
    *(undefined2 *)(arg0 + 0x1c) = 1;
    return;
  }
  puVar3 = (uint *)(arg1 * 0x1000 + 0x2001000);
  uVar1 = 0;
  do {
    puVar2 = *(uint **)((uint)DAT_0203a45a * 4 + 0x87f02b8);
    *puVar3 = *puVar3 & *puVar2;
    puVar3[1] = puVar3[1] & puVar2[1];
    puVar3[2] = puVar3[2] & puVar2[2];
    puVar3[3] = puVar3[3] & puVar2[3];
    puVar3[4] = puVar3[4] & puVar2[4];
    puVar3[5] = puVar3[5] & puVar2[5];
    puVar3[6] = puVar3[6] & puVar2[6];
    puVar3[7] = puVar3[7] & puVar2[7];
    puVar3 = puVar3 + 8;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x78);
  if (arg1 == 1) {
    arg0_00 = 0x80c3ee1;
  }
  else {
    if (arg1 != 0) {
      if (arg1 == 2) {
        DisplayList_Add(0x80c3f05,1);
      }
      goto LAB_08157930;
    }
    arg0_00 = 0x80c3ebd;
  }
  DisplayList_Add(arg0_00,1);
LAB_08157930:
  DAT_0203a45a = DAT_0203a45a + 1;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  return;
}


// sub_0815795C @ 0x0815795C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0815795C(int arg0,undefined4 arg1)

{
  sub_080AD0FC(0x87f0f94,(uint)*(ushort *)(arg0 + 2));
  _DAT_0203a484 = 0;
  DAT_0203a486 = (undefined2)arg1;
  return;
}


// sub_08157980 @ 0x08157980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08157980(void)

{
  _DAT_0203a488 = sub_080AB860(2,0xe,0x1a,6);
  return;
}


// sub_081579A4 @ 0x081579A4

undefined4 sub_081579A4(uint arg0)

{
  uint uVar1;
  
  uVar1 = sub_0815B824(arg0 & 0xffff);
  uVar1 = uVar1 & 0xffff;
  if ((arg0 & 0xffff) == 0x13e) {
    uVar1 = 0xe;
  }
  return *(undefined4 *)(uVar1 * 4 + 0x87f02c8);
}


// sub_081579D4 @ 0x081579D4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081579D4(int arg0)

{
  short sVar1;
  ushort uVar2;
  char *pcVar3;
  ushort *puVar4;
  short *psVar5;
  ushort *puVar6;
  uint uVar7;
  uint arg3;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((DAT_030031b8 & 1) == 0) {
    *(ushort *)(arg0 + 0x1c) = DAT_030031b8 & 1;
  }
  else {
    sub_080C51D4(0x65);
    sub_080AB91C(_DAT_0203a488,1);
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  sVar1 = DAT_0203b85c;
  if (_DAT_0203a4d4 == 0) {
    uVar7 = (uint)DAT_0203b85a;
    pcVar3 = (char *)sub_080BF648(uVar7);
    arg3 = 0x12;
    if (((sVar1 == 1) || (sVar1 == 4)) || (sVar1 == 5)) {
      puVar4 = (ushort *)0x815bf92;
    }
    else {
      puVar4 = (ushort *)sub_081579A4(uVar7);
    }
LAB_08157b40:
    puVar6 = puVar4;
    uVar2 = *puVar6;
    if (uVar2 != 0x301) {
      puVar4 = puVar6 + 1;
      if (uVar2 != 0x316) {
        if (uVar2 == 799) {
          psVar5 = (short *)Race_GetName((int)*pcVar3 & 0xffff);
          uVar7 = 0;
          sVar1 = *psVar5;
          while (sVar1 != 0) {
            FontSprite_DrawGlyph((uint)(ushort)psVar5[uVar7],0,0,arg3);
            arg3 = arg3 + 0xc & 0xffff;
            uVar7 = uVar7 + 1 & 0xffff;
            if (7 < uVar7) break;
            sVar1 = psVar5[uVar7];
          }
        }
        else if (uVar2 == 0x31e) {
          uVar7 = 0;
          sVar1 = *(short *)(pcVar3 + 0x22);
          while (sVar1 != 0) {
            FontSprite_DrawGlyph((uint)*(ushort *)(pcVar3 + uVar7 * 2 + 0x22),0,0,arg3);
            arg3 = arg3 + 0xc & 0xffff;
            uVar7 = uVar7 + 1 & 0xffff;
            if (7 < uVar7) break;
            sVar1 = *(short *)(pcVar3 + uVar7 * 2 + 0x22);
          }
        }
        else if (uVar2 == 0x300) {
          arg3 = 0x12;
        }
        else {
          FontSprite_DrawGlyph((uint)*puVar6,0,0,arg3);
          arg3 = arg3 + 0xc & 0xffff;
        }
      }
      goto LAB_08157b40;
    }
  }
  else {
    Text_DrawSpriteString(0x815bb90,0,0,0x12);
  }
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_080C4AB0(0,0,0xd6,0x95);
  }
                    /* WARNING: Could not recover jumptable at 0x08157b6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08157B78 @ 0x08157B78

void sub_08157B78(int arg0)

{
  undefined2 uVar1;
  
  switch(DAT_0203b85c) {
  case 1:
  case 2:
  case 4:
    uVar1 = 2;
    break;
  case 3:
  case 5:
    uVar1 = 3;
    break;
  default:
    goto switchD_08157b8e_default;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar1;
switchD_08157b8e_default:
  return;
}


// sub_08157BB8 @ 0x08157BB8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08157BB8(undefined4 arg0,int arg1)

{
  int iVar1;
  int arg0_00;
  
  if (arg1 == 0) {
    sub_080C3E80(_DAT_0203a480);
    DAT_02036094 = _DAT_0203a468;
    DAT_02036074 = _DAT_0203a46c;
    DAT_02036076 = DAT_0203a46e;
    if (_DAT_0203a468 != 0) {
      sub_080CE580(_DAT_0203a468,1);
    }
  }
  else if (DAT_02036094 != 0) {
    arg0_00 = DAT_02036094 + 0x24;
    iVar1 = sub_080D95F4((uint)*(ushort *)(DAT_02036094 + 0x2a));
    sub_080C4080(arg0_00,*(undefined4 *)(iVar1 + 4 + (arg1 + -1) * 4),0,arg1 + -1);
  }
  return;
}


// sub_08157C2C @ 0x08157C2C

uint sub_08157C2C(void)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar4 = sub_080C0198((uint)DAT_0203b854);
  iVar5 = sub_080C0198((uint)DAT_0203b856);
  if (DAT_0203b854 == 0xfb) {
    bVar1 = *(short *)(iVar5 + 0x18) < *(short *)(iVar5 + 0x1a);
    sVar2 = *(short *)(iVar5 + 0x1c);
    sVar3 = *(short *)(iVar5 + 0x1e);
  }
  else {
    if (DAT_0203b856 != 0xfb) {
      return 0;
    }
    bVar1 = *(short *)(iVar4 + 0x18) < *(short *)(iVar4 + 0x1a);
    sVar2 = *(short *)(iVar4 + 0x1c);
    sVar3 = *(short *)(iVar4 + 0x1e);
  }
  uVar6 = (uint)!bVar1;
  if (sVar3 <= sVar2) {
    uVar6 = uVar6 | 2;
  }
  return uVar6;
}


// sub_08157C90 @ 0x08157C90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08157C90(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a454 == 1) {
    sub_080C33AC(0x10a);
    sub_080C33AC(0x10b);
    sub_080C33AC(0x10c);
    sub_080C33AC(0x10d);
    sub_080C33AC(0x10e);
    sub_080C33AC(0x10f);
    goto LAB_08157e6e;
  }
  if (DAT_0203a454 == 3) {
    sub_080C062C((uint)DAT_0203b85a);
    iVar2 = sub_081571DC((uint)DAT_0203b85a);
    sub_080C30AC(-iVar2);
  }
  else {
    if (DAT_0203b85c == 1) {
      uVar3 = sub_08154968((uint)DAT_0203b854);
      sub_080C33AC(uVar3 & 0xffff);
      uVar1 = DAT_0203b856;
LAB_08157d5c:
      iVar2 = sub_080C0198((uint)uVar1);
      sub_080C0290((uint)*(byte *)(iVar2 + 0xc),1);
    }
    else {
      if (DAT_0203b85c != 4) {
        if (DAT_0203b85c != 5) {
          uVar3 = 0;
          if (DAT_0203b85c == 2) {
            iVar2 = sub_080C0198((uint)DAT_0203b854);
            iVar4 = sub_080C0198((uint)DAT_0203b856);
            uVar3 = sub_08157C2C();
            uVar3 = uVar3 & 0xffff;
            sub_080C0290((uint)*(byte *)(iVar2 + 0xc),1);
            sub_080C0290((uint)*(byte *)(iVar4 + 0xc),1);
          }
          else if (DAT_0203b85c == 3) {
            iVar2 = sub_080C0198((uint)DAT_0203b854);
            sub_080C0290((uint)*(byte *)(iVar2 + 0xc),1);
            iVar2 = sub_080C0198((uint)DAT_0203b856);
            sub_080C0290((uint)*(byte *)(iVar2 + 0xc),1);
            iVar2 = sub_080C0198((uint)DAT_0203b858);
            sub_080C0290((uint)*(byte *)(iVar2 + 0xc),1);
          }
          sub_080C062C((uint)DAT_0203b85a);
          iVar2 = sub_080C3560((uint)DAT_0203b85a);
          if (_DAT_0203a4d4 == 0) {
            uVar5 = 0;
            do {
              *(undefined1 *)(iVar2 + 0x5d + uVar5) = *(undefined1 *)(uVar5 + 0x203b860);
              uVar5 = uVar5 + 1 & 0xffff;
            } while (uVar5 < 6);
          }
          if (uVar3 != 0) {
            if ((uVar3 & 1) != 0) {
              iVar4 = (int)*(short *)(iVar2 + 0x1a);
              if (iVar4 < 0) {
                iVar4 = iVar4 + 3;
              }
              iVar4 = (iVar4 >> 2) + (uint)*(ushort *)(iVar2 + 0x18);
              *(short *)(iVar2 + 0x18) = (short)iVar4;
              if ((int)999 < iVar4 * 0x10000 >> 0x10) {
                *(undefined2 *)(iVar2 + 0x18) = 999;
              }
            }
            if ((uVar3 & 2) != 0) {
              iVar4 = (int)*(short *)(iVar2 + 0x1e);
              if (iVar4 < 0) {
                iVar4 = iVar4 + 3;
              }
              iVar4 = (iVar4 >> 2) + (uint)*(ushort *)(iVar2 + 0x1c);
              *(short *)(iVar2 + 0x1c) = (short)iVar4;
              if ((int)999 < iVar4 * 0x10000 >> 0x10) {
                *(undefined2 *)(iVar2 + 0x1c) = 999;
              }
            }
          }
          sub_080E5DA0();
          sub_0815B3F4();
          sub_080C5170(0xf);
          goto LAB_08157e6e;
        }
        uVar3 = sub_08154968((uint)DAT_0203b854);
        sub_080C33AC(uVar3 & 0xffff);
        uVar3 = sub_08154968((uint)DAT_0203b856);
        sub_080C33AC(uVar3 & 0xffff);
        uVar1 = DAT_0203b858;
        goto LAB_08157d5c;
      }
      uVar3 = sub_08154968((uint)DAT_0203b854);
      sub_080C33AC(uVar3 & 0xffff);
      uVar3 = sub_08154968((uint)DAT_0203b856);
      sub_080C33AC(uVar3 & 0xffff);
    }
    uVar3 = sub_08154968((uint)DAT_0203b85a);
    sub_080C3328(uVar3 & 0xffff);
  }
  sub_080C5170(0xf);
LAB_08157e6e:
  sub_080C366C();
  *(undefined4 *)(_DAT_0203a464 + 0xc) = 1;
                    /* WARNING: Could not recover jumptable at 0x08157e7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08157E8C @ 0x08157E8C

void sub_08157E8C(void)

{
  *(undefined4 *)(DAT_0203a460 + 0xc) = 1;
  DAT_03003bb4 = 0;
  return;
}


// sub_08157EA4 @ 0x08157EA4

void sub_08157EA4(void)

{
  sub_080CED00();
  return;
}


// sub_08157EB0 @ 0x08157EB0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08157EB0(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  undefined4 uStack_1c;
  
  uStack_1c = 0;
  CpuSet(&uStack_1c,0x203a454,0x5000200);
  if ((short)arg0 == 0) {
    sub_080AD0FC(0x87f0308,0xffff);
  }
  else if ((short)arg0 == 1) {
    sub_080AD0FC(0x87f106c,0xffff);
    DAT_0203b854 = 0x13c;
    DAT_0203b856 = 0x13f;
    DAT_0203b858 = 0x13b;
    DAT_0203b85a = 0x13e;
    DAT_0203b85c = 3;
  }
  else if ((short)arg0 != 2) {
    sub_080AD0FC(0x87f06d8,0xffff);
    DAT_0203b85c = 2;
  }
  DAT_0203a454 = (short)arg0;
  DAT_0203a460 = arg1;
  _DAT_0203a464 = arg2;
  return;
}


// sub_08157F5C @ 0x08157F5C

void sub_08157F5C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2005800;
  REG_DMA3DAD = 0x6006920;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_08157F94 @ 0x08157F94

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08157F94(undefined4 arg0,int arg1)

{
  byte bVar1;
  uint uVar2;
  undefined4 in_r2;
  ushort *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  byte *pbVar6;
  
  puVar4 = (undefined4 *)(arg1 * 8 + _DAT_0203a45c);
  LZ77UnCompWram(*puVar4,0x2005800,in_r2);
  pbVar6 = (byte *)puVar4[1];
  sub_081574D0();
  uVar2 = 0;
  do {
    uVar5 = 0;
    do {
      puVar3 = (ushort *)((uVar2 * 0x20 + uVar5 + 0x189) * 2 + 0x2000000);
      bVar1 = *pbVar6;
      pbVar6 = pbVar6 + 1;
      *puVar3 = *puVar3 & 0xfff | ((bVar1 & 0xf) + 6) * 0x1000;
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 0xc);
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 4);
  DisplayList_Add(0x8157f5d,1);
  return;
}


// sub_08158030 @ 0x08158030

undefined4 sub_08158030(void)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((ushort)(DAT_0203b85c - 2U) < 2) {
    if (DAT_0203b85a != 0x13e) {
      uVar2 = sub_0815B958((uint)DAT_0203b85a);
      uVar2 = uVar2 & 0xff;
      if (uVar2 != 1) {
        if (uVar2 < 2) {
          if (uVar2 == 0) goto LAB_08158090;
        }
        else if (uVar2 == 2) goto LAB_0815809c;
        uVar3 = 3;
        goto LAB_081580a2;
      }
    }
  }
  else {
    uVar2 = sub_08154968((uint)DAT_0203b85a);
    pbVar4 = (byte *)sub_080BF32C(uVar2 & 0xffff);
    bVar1 = *pbVar4;
    if (((bVar1 & 7) == 7) || ((bVar1 & 1) != 0)) {
LAB_08158090:
      uVar3 = 0;
      goto LAB_081580a2;
    }
    if ((bVar1 & 2) == 0) {
LAB_0815809c:
      uVar3 = 2;
      goto LAB_081580a2;
    }
  }
  uVar3 = 1;
LAB_081580a2:
                    /* WARNING: Could not recover jumptable at 0x081580a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar3);
  return uVar3;
}


// sub_081580A8 @ 0x081580A8

void sub_081580A8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6013800;
  REG_DMA3CNT = 0x84000900;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_081580CC @ 0x081580CC

void sub_081580CC(undefined4 arg0,int arg1)

{
  int iVar1;
  undefined4 in_r2;
  
  iVar1 = sub_08158030();
  HuffUnComp(*(undefined4 *)((iVar1 * 4 + arg1) * 4 + 0x87f0954),0x200afc8,in_r2);
  LZ77UnCompWram(0x200afc8,arg1 * 0x1000 + 0x2001000,in_r2);
  if (arg1 == 2) {
    iVar1 = sub_08158030();
    sub_080ACFCC(3,*(undefined4 *)(&DAT_087f0960 + iVar1 * 0x10),0x3003150,0x20);
    sub_080AABB0();
    DisplayList_Add(0x81580a9,1);
    iVar1 = sub_0815814C();
    DAT_0203a4d8._0_2_ = (undefined2)*(undefined4 *)(iVar1 + 4);
  }
  return;
}


// sub_0815814C @ 0x0815814C

int sub_0815814C(void)

{
  int iVar1;
  
  iVar1 = sub_08158030();
  if (iVar1 == 1) {
    iVar1 = (uint)DAT_0203a4cc._2_2_ * 8 + 0x87f0a9c;
  }
  else if (iVar1 == 0) {
    iVar1 = (uint)DAT_0203a4cc._2_2_ * 8 + 0x87f09e4;
  }
  else if (iVar1 == 2) {
    iVar1 = (uint)DAT_0203a4cc._2_2_ * 8 + 0x87f0b6c;
  }
  else if (iVar1 == 3) {
    iVar1 = (uint)DAT_0203a4cc._2_2_ * 8 + 0x87f0994;
  }
  return iVar1;
}


// sub_081581C0 @ 0x081581C0

void sub_081581C0(void)

{
  undefined4 *puVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)sub_0815814C();
  iVar2 = sub_08158030();
  if (((iVar2 == 1) || (iVar2 == 0)) || (iVar2 == 2)) {
    sub_080AA184(*puVar1,0,0xd,0);
  }
  else if (iVar2 == 3) {
    sub_080AA184(*puVar1,0,0xd,0);
  }
                    /* WARNING: Could not recover jumptable at 0x0815821c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08158220 @ 0x08158220

void sub_08158220(int arg0)

{
  int *piVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0203a4d8._0_2_ = (short)DAT_0203a4d8 + -1;
  if ((short)DAT_0203a4d8 == 0) {
    DAT_0203a4cc._2_2_ = DAT_0203a4cc._2_2_ + 1;
    piVar1 = (int *)sub_0815814C();
    DAT_0203a4d8._0_2_ = (short)piVar1[1];
    if (*piVar1 == 0) {
      DAT_0203a4cc._2_2_ = DAT_0203a4cc._2_2_ + -1;
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  return;
}


// sub_08158268 @ 0x08158268

void sub_08158268(undefined4 arg0)

{
  if ((DAT_030031bc & 3) == 0) {
    if ((ushort)DAT_0203a4cc == 0) {
      sub_08157F94(arg0,5);
    }
    else {
      sub_08157F94(arg0,0);
      sub_080C51D4(0x153);
    }
    DAT_0203a4cc._0_2_ = (ushort)DAT_0203a4cc + 1 & 1;
  }
  return;
}


// sub_081582BC @ 0x081582BC

void sub_081582BC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2008000;
  REG_DMA3DAD = 0x6013800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_081582E0 @ 0x081582E0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081582E0(void)

{
  undefined4 in_r2;
  
  HuffUnComp(*(undefined4 *)((uint)_DAT_0203a484 * 4 + 0x87f020c),0x200afc8,in_r2);
  LZ77UnCompWram(0x200afc8,0x2008000,in_r2);
  DisplayList_Add(0x81582bd,1);
  if (_DAT_0203a484 == 0) {
    sub_080ACFCC(3,0x87f012c,0x3003130,0x20);
    sub_080AABB0();
  }
  _DAT_0203a484 = _DAT_0203a484 + 1;
  return;
}


// sub_0815834C @ 0x0815834C

void sub_0815834C(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080AA184(0x8002134,1,0xc,2);
                    /* WARNING: Could not recover jumptable at 0x08158398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081583A0 @ 0x081583A0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081583A0(undefined4 arg0,int arg1)

{
  if (arg1 == 0) {
    _DAT_0203a4d0 = *(undefined4 *)(_DAT_0203a468 + 0x20);
    *(undefined4 *)(_DAT_0203a468 + 0x20) = 0;
    sub_080AB91C(DAT_03006968,1);
  }
  else {
    *(undefined4 *)(DAT_02036094 + 0x20) = _DAT_0203a4d0;
    DAT_03006968 = sub_080AB7D4(2,0xb,0x1a,8);
  }
  return;
}


