/* Ghidra decompilation of asm/code_080D38D0.s (reference only; not compiled). */

// sub_080D38D0 @ 0x080D38D0

void sub_080D38D0(int arg0)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar5 = (uint)*(ushort *)(arg0 + 0x2c);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  uVar6 = uVar5;
  if (5 < uVar5) {
    uVar6 = 6;
  }
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) == 0) {
          if (((DAT_03003964 & 0x200) == 0) || (uVar5 < 7)) {
            if (((DAT_03003964 & 0x100) != 0) && (6 < uVar5)) {
              sVar2 = *(short *)(arg0 + 0x28);
              uVar1 = *(ushort *)(arg0 + 0x2a);
              if (sVar2 == 5) {
                if ((int)(uVar1 + 0xb) < (int)(uVar5 - 1)) {
                  sVar3 = uVar1 + 6;
                }
                else {
                  sVar3 = *(ushort *)(arg0 + 0x2c) - 6;
                }
                *(short *)(arg0 + 0x2a) = sVar3;
              }
              else {
                *(undefined2 *)(arg0 + 0x28) = 5;
              }
              if ((sVar2 != *(short *)(arg0 + 0x28)) ||
                 ((uint)uVar1 != (uint)*(ushort *)(arg0 + 0x2a))) {
                sub_080C51D4(100);
              }
            }
            goto LAB_080d3a42;
          }
          sVar2 = *(short *)(arg0 + 0x28);
          uVar1 = *(ushort *)(arg0 + 0x2a);
          if (sVar2 == 0) {
            sVar3 = 0;
            if (4 < uVar1) {
              sVar3 = uVar1 - 5;
            }
            *(short *)(arg0 + 0x2a) = sVar3;
          }
          else {
            *(ushort *)(arg0 + 0x28) = DAT_03003964 & 0x80;
          }
          if ((sVar2 == *(short *)(arg0 + 0x28)) && (uVar1 == *(ushort *)(arg0 + 0x2a)))
          goto LAB_080d3a42;
        }
        else {
          uVar1 = *(ushort *)(arg0 + 0x28);
          if ((uint)uVar1 == uVar6 - 1) {
            if ((uVar1 != 5) || ((int)(uVar5 - 1) < (int)(*(ushort *)(arg0 + 0x2a) + 6)))
            goto LAB_080d3a42;
            *(ushort *)(arg0 + 0x2a) = *(ushort *)(arg0 + 0x2a) + 1;
          }
          else {
            *(ushort *)(arg0 + 0x28) = uVar1 + 1;
          }
        }
      }
      else if (*(short *)(arg0 + 0x28) == 0) {
        if (*(short *)(arg0 + 0x2a) == 0) goto LAB_080d3a42;
        *(short *)(arg0 + 0x2a) = *(short *)(arg0 + 0x2a) + -1;
      }
      else {
        *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) + -1;
      }
      sub_080C51D4(100);
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1c) = 1;
      *(undefined2 *)(arg0 + 0x1e) = 0xffff;
      DAT_030031cc = 1;
    }
  }
  else {
    uVar1 = *(ushort *)
             (((uint)*(ushort *)(arg0 + 0x28) + (uint)*(ushort *)(arg0 + 0x2a)) * 2 + 0x203b454);
    iVar4 = sub_080C5B10((uint)uVar1);
    if (iVar4 == 0) {
      sub_080C51D4(0x65);
      *(undefined2 *)(arg0 + 0x1e) = 1;
      *(undefined2 *)(arg0 + 0x1c) = 1;
      DAT_0203db2c = 10000;
      DAT_030031cc = 0;
      DAT_0203db50 = uVar1;
    }
    else {
      sub_080C51D4(0x66);
    }
  }
LAB_080d3a42:
                    /* WARNING: Could not recover jumptable at 0x080d3a46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D3A48 @ 0x080D3A48

void sub_080D3A48(int arg0)

{
  sub_080AB438(0,0x200dfd4,0x15,0);
  sub_080ABD30(*(undefined4 *)(arg0 + 0x24),1);
  return;
}


// sub_080D3A78 @ 0x080D3A78

void sub_080D3A78(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)*(byte *)(arg0 + 6);
  return;
}


// sub_080D3A80 @ 0x080D3A80

void sub_080D3A80(void)

{
  DAT_03003fec = sub_080AD0FC(0x84f3228,0xffff);
  return;
}


// sub_080D3AA0 @ 0x080D3AA0

undefined4 sub_080D3AA0(int arg0)

{
  int iVar1;
  
  if (arg0 == 0) {
    Font_ResetGlyphSpriteCache(0x180);
    if (*(short *)(DAT_03003fec + 0x1e) != 0) {
      return 1;
    }
  }
  else if (arg0 == 1) {
    sub_080AD348(DAT_03003fec);
    iVar1 = DAT_03003fec;
    *(undefined2 *)(DAT_03003fec + 0x1e) = 0;
    *(undefined1 *)(iVar1 + 6) = 1;
  }
  else {
    sub_080AD348(DAT_03003fec);
    iVar1 = DAT_03003fec;
    *(undefined2 *)(DAT_03003fec + 0x1e) = 0;
    *(undefined1 *)(iVar1 + 6) = 0;
  }
  return 0;
}


// sub_080D3B00 @ 0x080D3B00

void sub_080D3B00(void)

{
  DAT_03003fec = 0;
  return;
}


// sub_080D3B0C @ 0x080D3B0C

void sub_080D3B0C(undefined4 arg0,undefined4 arg1)

{
  DAT_030031cc = arg1;
  return;
}


// sub_080D3B18 @ 0x080D3B18

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D3B18(void)

{
  undefined4 local_18;
  undefined4 local_14;
  
  _DAT_0203a454 = 0x13240800;
  local_18 = 0;
  CpuSet(&local_18,&DAT_0203a458,0x5000002);
  _DAT_0203a488 = 0;
  local_14 = 0;
  CpuSet(&local_14,&DAT_0203a48c,0x5000002);
  return;
}


// sub_080D3B58 @ 0x080D3B58

uint sub_080D3B58(uint arg0,uint arg1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = (arg0 & 0xffff) - 0x100;
  bVar2 = ((int)(uint)*(byte *)((int)&DAT_0203a48c + (uVar1 >> 3)) >> (uVar1 & 7) & 1U) == 0;
  if (!bVar2) {
    sub_080C2364(arg1 & 0xffff);
  }
  return (uint)bVar2;
}


// sub_080D3B94 @ 0x080D3B94

void sub_080D3B94(void)

{
  dword arg0;
  dword arg1;
  short *psVar1;
  int iVar2;
  
  iVar2 = 1;
  switch(DAT_0203db50) {
  case 0x13d:
    arg0 = 0x117;
    arg1 = 0x131;
    break;
  default:
    goto switchD_080d3bac_caseD_13e;
  case 0x146:
    arg0 = 0x11e;
    arg1 = 0x13a;
    break;
  case 0x147:
    arg0 = 0x10f;
    arg1 = 0x13b;
    break;
  case 0x14a:
    arg0 = 0x101;
    arg1 = 0x13e;
    break;
  case 0x14b:
    arg0 = 0x116;
    arg1 = 0x13f;
    break;
  case 0x14d:
    arg0 = 0x115;
    arg1 = 0x141;
    break;
  case 0x14f:
    arg0 = 0x11b;
    arg1 = 0x143;
  }
  iVar2 = sub_080D3B58(arg0,arg1);
switchD_080d3bac_caseD_13e:
  DAT_030031cc = iVar2;
  if (iVar2 == 1) {
    psVar1 = (short *)0x2009004;
    do {
      if ((*psVar1 != 0) && (*(dword *)(psVar1 + 0x10) == 0x80da5dd)) {
        *(dword *)(psVar1 + 0x10) = 0x80da609;
      }
      psVar1 = psVar1 + 0x32;
    } while (psVar1 < (short *)0x200a8a1);
  }
  return;
}


// sub_080D3CAC @ 0x080D3CAC

void sub_080D3CAC(void)

{
  DAT_03003fec = sub_080AD0FC(0x84f32b4,0xffff);
  return;
}


// sub_080D3CCC @ 0x080D3CCC

uint sub_080D3CCC(void)

{
  return (uint)(DAT_03003fec == 0);
}


// sub_080D3CE4 @ 0x080D3CE4

undefined4 sub_080D3CE4(void)

{
  return DAT_030031cc;
}


// sub_080D3CF0 @ 0x080D3CF0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D3CF0(void)

{
  undefined4 local_18;
  undefined4 local_14;
  
  _DAT_0203a454 = 0x10570010;
  local_18 = 0;
  CpuSet(&local_18,&DAT_0203a458,0x500000a);
  _DAT_0203a488 = 0;
  local_14 = 0;
  CpuSet(&local_14,&DAT_0203a48c,0x500000a);
  return;
}


// sub_080D3D30 @ 0x080D3D30

void sub_080D3D30(void)

{
  sub_080DF954(0x2c,0x203a454,&DAT_0203a488);
  return;
}


// sub_080D3D48 @ 0x080D3D48

void sub_080D3D48(void)

{
  ushort uVar1;
  int iVar2;
  short *psVar3;
  uint arg0;
  undefined4 uVar4;
  
  uVar4 = 1;
  arg0 = 0;
  sub_080C32D4(0x11f);
  psVar3 = (short *)0x84f3754;
  do {
    iVar2 = sub_080C3560((uint)(ushort)psVar3[1]);
    if (((iVar2 == 0) &&
        (((ushort)psVar3[2] == 0 || (iVar2 = sub_080C3560((uint)(ushort)psVar3[2]), iVar2 == 0))))
       && (((ushort)psVar3[3] == 0 || (iVar2 = sub_080C3560((uint)(ushort)psVar3[3]), iVar2 == 0))))
    {
      uVar1 = psVar3[4];
      if ((uVar1 != 0) &&
         (((int)(uint)*(byte *)((int)&DAT_0203a48c + (uint)(uVar1 >> 3)) >> (uVar1 & 7) & 1U) != 0))
      {
        sub_080D3E24(arg0);
        uVar4 = 0;
        sub_080C2364(0x162);
      }
    }
    arg0 = arg0 + 1 & 0xffff;
    psVar3 = psVar3 + 6;
  } while (*psVar3 != -1);
  DAT_030031cc = uVar4;
  return;
}


// sub_080D3DF0 @ 0x080D3DF0

void sub_080D3DF0(void)

{
  DAT_03003fec = sub_080AD0FC(0x84f3498,0xffff);
  return;
}


// sub_080D3E10 @ 0x080D3E10

void sub_080D3E10(void)

{
  DAT_0203bb6f = 0;
  DAT_0203bb6e = 0;
  DAT_0203bb6d = 0;
  DAT_0203bb6c = 0;
  return;
}


// sub_080D3E24 @ 0x080D3E24

void sub_080D3E24(uint arg0)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(((arg0 & 0xffff) >> 3) + 0x203bb6c);
  *pbVar1 = (byte)(1 << (arg0 & 7)) | *pbVar1;
  return;
}


// sub_080D3E44 @ 0x080D3E44

uint sub_080D3E44(uint arg0)

{
  return (int)(uint)*(byte *)(((arg0 & 0xffff) >> 3) + 0x203bb6c) >> (arg0 & 7) & 1;
}


// sub_080D3E64 @ 0x080D3E64

void sub_080D3E64(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6006000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x81b5810;
  REG_DMA3DAD = 0x6012f00;
  REG_DMA3CNT = 0x84000018;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D3EA0 @ 0x080D3EA0

void sub_080D3EA0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000800;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000060;
  uVar1 = REG_DMA3CNT;
  sub_080D3E64();
  return;
}


// sub_080D3EC8 @ 0x080D3EC8

void sub_080D3EC8(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85000060;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6006000;
  REG_DMA3CNT = 0x85000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D3F04 @ 0x080D3F04

void sub_080D3F04(undefined4 arg0,uint arg1,int arg2)

{
  char *pcVar1;
  int iVar2;
  undefined4 arg0_00;
  dword dVar3;
  undefined4 uVar4;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  local_24 = arg2;
  pcVar1 = (char *)sub_080BF648(arg1 & 0xffff);
  iVar2 = sub_0815B864();
  arg0_00 = sub_080D45B8(arg1 & 0xffff);
  local_2c = 0;
  CpuSet(&local_2c,0x200f874,0x5000800);
  local_28 = 0;
  CpuSet(&local_28,0x2000800,0x5000200);
  sub_080AB250(0x81b93b0,0x2000800,0x100,0);
  sub_080CCE5C(0x84f367c,0x8a,0xd,4);
  if ((byte)pcVar1[1] < 10) {
    sub_080CCF44((uint)(byte)pcVar1[1],0xdc,0xd,0);
  }
  else {
    sub_080CCF44((uint)(byte)pcVar1[1],0xdc,0xd,0);
  }
  sub_080CCE5C(0x84f3680,0x8a,0x17,4);
  if (*pcVar1 < '\r') {
    dVar3 = 0x84f3684;
    uVar4 = 0xbc;
LAB_080d3fe6:
    sub_080CCE5C(dVar3,uVar4,0x17,0);
  }
  else {
    if (*pcVar1 < '\x1b') {
      dVar3 = 0x84f368c;
      uVar4 = 0xac;
      goto LAB_080d3fe6;
    }
    sub_080CCE5C(0x84f3694,0xc4,0x17,0);
  }
  if (iVar2 == 0) {
    dVar3 = 0x84f369c;
    uVar4 = 0xcc;
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        sub_080CCE5C(0x84f36a0,0xbc,0x21,0);
      }
      goto LAB_080d4050;
    }
    dVar3 = 0x84f368c;
    uVar4 = 0xac;
  }
  sub_080CCE5C(dVar3,uVar4,0x21,0);
LAB_080d4050:
  sub_080CCE5C(0x84f36a8,0x8a,0x2b,4);
  sub_080CCF44(arg0_00,0xdc,0x2b,0);
  if (local_24 == 0) {
    DisplayList_Add(0x80d3ea1,1);
  }
  else {
    DisplayList_Add(0x80d3e65,1);
  }
  return;
}


// sub_080D40AC @ 0x080D40AC

void sub_080D40AC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x81b5810;
  REG_DMA3DAD = 0x6012f00;
  REG_DMA3CNT = 0x84000018;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D40E8 @ 0x080D40E8

void sub_080D40E8(int arg0)

{
  undefined4 uVar1;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_1c = 0;
  CpuSet(&local_1c,0x203b454,0x5000040);
  uVar1 = sub_080D45F0(0x203b454,(uint)*(ushort *)(arg0 + 0x32));
  *(short *)(arg0 + 0x30) = (short)uVar1;
  local_18 = 0;
  CpuSet(&local_18,0x2000000,0x5000200);
  sub_080AB390(0x8770a24,0x2000000,0,0);
  sub_080AB250(0x81b8170,0x2000000,0,0);
  DisplayList_Add(0x80d40ad,1);
  sub_080D3F04(arg0,(uint)DAT_0203b454,0);
  return;
}


// sub_080D4190 @ 0x080D4190

void sub_080D4190(int arg0)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  
  uVar1 = *(ushort *)(arg0 + 0x30);
  sub_080C49EC(0xb,0,0,0xc);
  uVar4 = 0;
  do {
    uVar2 = (uint)*(ushort *)((*(ushort *)(arg0 + 0x2e) + uVar4) * 2 + 0x203b454);
    uVar4 = uVar4 + 1;
    if (uVar2 != 0) {
      iVar3 = sub_080BF648(uVar2);
      uVar6 = 0;
      uVar2 = 0xc0000;
      puVar5 = (ushort *)(iVar3 + 0x22);
      do {
        FontSprite_DrawGlyph((uint)*puVar5,0,0,uVar2 >> 0x10);
        uVar2 = uVar2 + 0xc0000;
        puVar5 = puVar5 + 1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 8);
    }
  } while (uVar4 < 6);
  sub_080AA184(0x8002a94,0,0,0);
  uVar4 = sub_080C32D4(0x11f);
  sub_080C8048(uVar4 & 0xff,0xb8,0x35,0);
  if (*(short *)(arg0 + 0x2e) != 0) {
    sub_080C4A4C(0,0,0x7a,4);
  }
  if ((int)(*(ushort *)(arg0 + 0x2e) + 6) <= (int)(uVar1 - 1)) {
    sub_080C4AB0(0,0,0x7a,0x46);
  }
  return;
}


// sub_080D429C @ 0x080D429C

void sub_080D429C(int arg0)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = *(ushort *)(arg0 + 0x30);
  uVar6 = (uint)uVar1;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  uVar7 = uVar6;
  if (5 < uVar6) {
    uVar7 = 6;
  }
  uVar4 = sub_080AB184();
  if (((uVar4 & 0xffff) == 0) || (iVar5 = sub_080B098C(), iVar5 == 1)) goto LAB_080d4492;
  if ((DAT_030031b8 & 1) != 0) {
    uVar2 = *(undefined2 *)
             (((uint)*(ushort *)(arg0 + 0x2c) + (uint)*(ushort *)(arg0 + 0x2e)) * 2 + 0x203b454);
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1e) = 1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_030031cc = 0;
    DAT_0203db28 = uVar2;
    goto LAB_080d4492;
  }
  if ((DAT_030031b8 & 2) != 0) {
    sub_080C51D4(0x66);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    *(undefined2 *)(arg0 + 0x1e) = 0xffff;
    DAT_030031cc = 1;
    sub_080C23BC(0x162);
    goto LAB_080d4492;
  }
  if ((DAT_03003964 & 0x40) == 0) {
    if ((DAT_03003964 & 0x80) == 0) {
      if (((DAT_03003964 & 0x200) == 0) || (uVar6 < 7)) {
        if (((DAT_03003964 & 0x100) == 0) || (uVar6 < 7)) goto LAB_080d4492;
        sVar3 = *(short *)(arg0 + 0x2c);
        uVar7 = (uint)*(ushort *)(arg0 + 0x2e);
        if (sVar3 == 5) {
          if ((int)(uVar7 + 0xb) < (int)(uVar6 - 1)) {
            *(ushort *)(arg0 + 0x2e) = *(ushort *)(arg0 + 0x2e) + 6;
            uVar6 = (uint)*(ushort *)(arg0 + 0x2e);
            goto LAB_080d445a;
          }
          *(ushort *)(arg0 + 0x2e) = uVar1 - 6;
          sub_080D3F04(arg0,(uint)*(ushort *)((*(ushort *)(arg0 + 0x2e) + 5) * 2 + 0x203b454),0);
        }
        else {
          *(undefined2 *)(arg0 + 0x2c) = 5;
          uVar6 = uVar7;
LAB_080d445a:
          sub_080D3F04(arg0,(uint)*(ushort *)((uVar6 + 5) * 2 + 0x203b454),0);
        }
        if ((sVar3 != *(short *)(arg0 + 0x2c)) || (uVar7 != *(ushort *)(arg0 + 0x2e))) {
          sub_080C51D4(100);
        }
        goto LAB_080d4492;
      }
      sVar3 = *(short *)(arg0 + 0x2c);
      uVar7 = (uint)*(ushort *)(arg0 + 0x2e);
      if (sVar3 == 0) {
        if (4 < uVar7) {
          *(ushort *)(arg0 + 0x2e) = *(ushort *)(arg0 + 0x2e) - 5;
          uVar6 = (uint)*(ushort *)(arg0 + 0x2e);
          goto LAB_080d43ec;
        }
        *(undefined2 *)(arg0 + 0x2e) = 0;
        sub_080D3F04(arg0,(uint)DAT_0203b454,0);
      }
      else {
        *(ushort *)(arg0 + 0x2c) = DAT_03003964 & 0x80;
        uVar6 = uVar7;
LAB_080d43ec:
        sub_080D3F04(arg0,(uint)*(ushort *)(uVar6 * 2 + 0x203b454),0);
      }
      if ((sVar3 != *(short *)(arg0 + 0x2c)) || (uVar7 != *(ushort *)(arg0 + 0x2e))) {
        sub_080C51D4(100);
      }
      goto LAB_080d4492;
    }
    uVar1 = *(ushort *)(arg0 + 0x2c);
    if ((uint)uVar1 != uVar7 - 1) {
      sVar3 = uVar1 + 1;
      goto LAB_080d4386;
    }
    if ((uVar1 == 5) && ((int)(*(ushort *)(arg0 + 0x2e) + 6) <= (int)(uVar6 - 1))) {
      sVar3 = *(ushort *)(arg0 + 0x2e) + 1;
      goto LAB_080d43a2;
    }
  }
  else if (*(short *)(arg0 + 0x2c) == 0) {
    if (*(short *)(arg0 + 0x2e) != 0) {
      sVar3 = *(short *)(arg0 + 0x2e) + -1;
LAB_080d43a2:
      *(short *)(arg0 + 0x2e) = sVar3;
      sub_080C51D4(100);
    }
  }
  else {
    sVar3 = *(short *)(arg0 + 0x2c) + -1;
LAB_080d4386:
    *(short *)(arg0 + 0x2c) = sVar3;
    sub_080C51D4(100);
  }
  sub_080D3F04(arg0,(uint)*(ushort *)
                           (((uint)*(ushort *)(arg0 + 0x2c) + (uint)*(ushort *)(arg0 + 0x2e)) * 2 +
                           0x203b454),0);
LAB_080d4492:
                    /* WARNING: Could not recover jumptable at 0x080d449e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D44A0 @ 0x080D44A0

void sub_080D44A0(int arg0)

{
  undefined4 uVar1;
  undefined4 local_14;
  
  uVar1 = sub_080AD0FC(0x84f1514,0xffff);
  local_14 = 0;
  CpuSet(&local_14,0x203a454,0x5000200);
  DAT_0203a456 = *(short *)(arg0 + 0x2e) + *(short *)(arg0 + 0x2c);
  if (*(short *)(arg0 + 0x32) == 0) {
    DAT_0203a454 = 0xb;
  }
  else {
    DAT_0203a454 = 0xc;
  }
  DAT_0203a476 = 0;
  *(undefined4 *)(arg0 + 0x28) = uVar1;
  DAT_03003bb4 = 0;
  return;
}


// sub_080D4500 @ 0x080D4500

void sub_080D4500(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(ushort *)(arg0 + 0x1c) = (ushort)(**(short **)(arg0 + 0x28) == 0);
                    /* WARNING: Could not recover jumptable at 0x080d4516. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D4518 @ 0x080D4518

void sub_080D4518(void)

{
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  CpuSet(local_8,0x2000000,0x5000200);
  DisplayList_Add(0x80d40ad,1);
  DisplayList_Add(0x80d3ec9,1);
  sub_080C6558();
  sub_080C6764();
  return;
}


// sub_080D4558 @ 0x080D4558

void sub_080D4558(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)*(byte *)(arg0 + 6);
  return;
}


// sub_080D4560 @ 0x080D4560

void sub_080D4560(undefined4 arg0)

{
  DAT_03003fec = sub_080AD0FC(0x84f36b0,0xffff);
  *(undefined2 *)(DAT_03003fec + 0x32) = (undefined2)arg0;
  DAT_03003bb4 = 0;
  return;
}


// sub_080D4594 @ 0x080D4594

uint sub_080D4594(void)

{
  Font_ResetGlyphSpriteCache(0x180);
  return (uint)(*DAT_03003fec == 0);
}


// sub_080D45B8 @ 0x080D45B8

int sub_080D45B8(uint arg0)

{
  int iVar1;
  
  if (arg0 * 0x10000 + 0xfe960000 >> 0x10 < 0x12) {
    iVar1 = (int)*(short *)(((arg0 & 0xffff) - 0x16a) * 0xc + 0x84f3754);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


// sub_080D45F0 @ 0x080D45F0

undefined4 sub_080D45F0(int arg0,undefined4 arg1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_r2;
  short *psVar3;
  uint uVar4;
  uint arg0_00;
  undefined4 unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar4 = 0;
  arg0_00 = 0;
  psVar3 = (short *)0x84f3754;
  if ((short)arg1 == 0) {
    sub_080C32D4(0x11f);
    iVar1 = sub_080C2340(0x162);
    if (iVar1 == 0) {
      do {
        iVar1 = sub_080C3560((uint)(ushort)psVar3[1]);
        if (((iVar1 == 0) && (psVar3[4] == 0)) &&
           ((((ushort)psVar3[2] == 0 || (iVar1 = sub_080C3560((uint)(ushort)psVar3[2]), iVar1 == 0))
            && (((ushort)psVar3[3] == 0 ||
                (iVar1 = sub_080C3560((uint)(ushort)psVar3[3]), iVar1 == 0)))))) {
          *(short *)(uVar4 * 2 + arg0) = psVar3[1];
          uVar4 = uVar4 + 1 & 0xffff;
        }
        psVar3 = psVar3 + 6;
      } while (*psVar3 != -1);
    }
    else {
      do {
        iVar1 = sub_080C3560((uint)(ushort)psVar3[1]);
        if ((((iVar1 == 0) && (psVar3[4] != 0)) &&
            (((ushort)psVar3[2] == 0 || (iVar1 = sub_080C3560((uint)(ushort)psVar3[2]), iVar1 == 0))
            )) && ((((ushort)psVar3[3] == 0 ||
                    (iVar1 = sub_080C3560((uint)(ushort)psVar3[3]), iVar1 == 0)) &&
                   (iVar1 = sub_080D3E44(arg0_00), iVar1 != 0)))) {
          *(short *)(uVar4 * 2 + arg0) = psVar3[1];
          uVar4 = uVar4 + 1 & 0xffff;
        }
        arg0_00 = arg0_00 + 1 & 0xffff;
        psVar3 = psVar3 + 6;
      } while (*psVar3 != -1);
    }
  }
  else {
    do {
      iVar1 = sub_080C3560((uint)(ushort)psVar3[1]);
      if (iVar1 != 0) {
        *(short *)(uVar4 * 2 + arg0) = psVar3[1];
        uVar4 = uVar4 + 1 & 0xffff;
      }
      psVar3 = psVar3 + 6;
    } while (*psVar3 != -1);
  }
                    /* WARNING: Could not recover jumptable at 0x080d4712. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar4,UNRECOVERED_JUMPTABLE,in_r2,unaff_r8);
  return uVar2;
}


// sub_080D4714 @ 0x080D4714

void sub_080D4714(int arg0)

{
  uint uVar1;
  int iVar2;
  
  *(undefined2 *)(arg0 + 0x24) = *(undefined2 *)(arg0 + 0x1e);
  *(undefined2 *)(arg0 + 0x26) = 0;
  uVar1 = sub_080C2244();
  if (((uVar1 & 0xff) == 0) && (iVar2 = sub_080C3560(0xfb), iVar2 == 0)) {
    *(undefined2 *)(arg0 + 0x26) = 0xfb;
  }
  return;
}


// sub_080D4744 @ 0x080D4744

void sub_080D4744(int arg0)

{
  short *psVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  psVar1 = (short *)sub_080AD364(arg0);
  *(ushort *)(arg0 + 0x1c) = (ushort)(*psVar1 == 0);
                    /* WARNING: Could not recover jumptable at 0x080d475e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D4760 @ 0x080D4760

void sub_080D4760(void)

{
  sub_080ECA60(0xd1,0,0x81);
  return;
}


// sub_080D4774 @ 0x080D4774

void sub_080D4774(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080ECB10();
  *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 == 1);
  return;
}


// sub_080D478C @ 0x080D478C

void sub_080D478C(int arg0)

{
  undefined4 uVar1;
  
  sub_080C2364(0x10c);
  DAT_0203db28 = *(short *)(arg0 + 0x26);
  if (DAT_0203db28 == 0) {
    DAT_0203db28 = *(short *)(arg0 + 0x24);
  }
  uVar1 = sub_080C4618(0,0x1c1,0x50,4);
  *(undefined4 *)(arg0 + 0x2c) = uVar1;
  return;
}


// sub_080D47D8 @ 0x080D47D8

void sub_080D47D8(void)

{
  sub_080AB0F0(0x1e0,0x10,1);
  return;
}


// sub_080D47EC @ 0x080D47EC

void sub_080D47EC(int arg0)

{
  if (*(short *)(arg0 + 0x26) == 0) {
    sub_080AF178(0x1a,*(undefined4 *)((*(ushort *)(arg0 + 0x24) - 0x16a) * 4 + 0x84f3838));
  }
  else {
    sub_080AF178(0x1a,0x815c090);
  }
  return;
}


// sub_080D4824 @ 0x080D4824

void sub_080D4824(void)

{
  sub_080C6558();
  sub_080C6764();
  return;
}


// sub_080D4834 @ 0x080D4834

void sub_080D4834(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_03004550 == 0x1a);
  return;
}


// sub_080D4850 @ 0x080D4850

void sub_080D4850(int arg0)

{
  int iVar1;
  int iVar2;
  
  iVar1 = sub_080D45B8((uint)*(ushort *)(arg0 + 0x24));
  iVar2 = sub_081571DC((uint)*(ushort *)(arg0 + 0x24));
  sub_080C30AC(-iVar2);
  if (0 < iVar1) {
    do {
      sub_080C33AC(0x11f);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  if (*(short *)(arg0 + 0x26) == 0) {
    sub_080C062C((uint)*(ushort *)(arg0 + 0x24));
  }
  else {
    sub_080C062C((uint)*(ushort *)(arg0 + 0x26));
  }
  return;
}


// sub_080D489C @ 0x080D489C

void sub_080D489C(int arg0)

{
  if (*(int *)(arg0 + 0x2c) != 0) {
    sub_080C48F0(*(int *)(arg0 + 0x2c));
  }
  sub_080AF178(0xc,0x805c3d0);
  return;
}


// sub_080D48BC @ 0x080D48BC

void sub_080D48BC(void)

{
  sub_080C51BC(1);
  return;
}


// sub_080D48C8 @ 0x080D48C8

void sub_080D48C8(int arg0)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = sub_080D45B8((uint)*(ushort *)(arg0 + 0x24));
  iVar2 = sub_080C3560((uint)*(ushort *)(arg0 + 0x24));
  iVar3 = sub_081571DC((uint)*(ushort *)(arg0 + 0x24));
  sub_080C30AC(-iVar3);
  if ((*(short *)(arg0 + 0x26) == 0) && (0 < iVar1)) {
    do {
      sub_080C3328(0x11f);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  sub_080C0290((uint)*(byte *)(iVar2 + 0xc),1);
  return;
}


// sub_080D4918 @ 0x080D4918

void sub_080D4918(int arg0)

{
  if (*(short *)(arg0 + 0x26) == 0) {
    sub_080AF178(0x1a,0x815c0de);
    DAT_0203db2c = sub_080D45B8((uint)*(ushort *)(arg0 + 0x24));
  }
  else {
    sub_080AF178(0x1a,0x815c110);
  }
  return;
}


// sub_080D4954 @ 0x080D4954

void sub_080D4954(int arg0)

{
  undefined4 uVar1;
  
  sub_080C2364(0x10c);
  DAT_0203db28 = *(undefined2 *)(arg0 + 0x24);
  uVar1 = sub_080C4618(0,0x1c1,0x50,4);
  *(undefined4 *)(arg0 + 0x2c) = uVar1;
  return;
}


// sub_080D4990 @ 0x080D4990

void sub_080D4990(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x6016000;
  REG_DMA3DAD = 0x2001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D49B4 @ 0x080D49B4

void sub_080D49B4(void)

{
  DisplayList_Add(0x80d4991,1);
  return;
}


// sub_080D49C8 @ 0x080D49C8

void sub_080D49C8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D49EC @ 0x080D49EC

void sub_080D49EC(int arg0)

{
  ushort uVar1;
  uint *puVar2;
  uint *puVar3;
  
  if (*(ushort *)(arg0 + 0x28) < 4) {
    puVar3 = (uint *)0x2001000;
    uVar1 = 0;
    do {
      puVar2 = *(uint **)((uint)*(ushort *)(arg0 + 0x28) * 4 + 0x87f02b8);
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
    DisplayList_Add(0x80d49c9,1);
    *(short *)(arg0 + 0x28) = *(short *)(arg0 + 0x28) + 1;
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080D4A84 @ 0x080D4A84

void sub_080D4A84(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D4AA8 @ 0x080D4AA8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D4AA8(void)

{
  undefined4 uVar1;
  undefined4 in_r2;
  
  LZ77UnCompWram(0x84f3af0,0x200afc8,in_r2);
  REG_DMA3SAD = 0x81b5710;
  REG_DMA3DAD = 0x200bec8;
  REG_DMA3CNT = 0x84000040;
  uVar1 = REG_DMA3CNT;
  sub_080ACFCC(3,0x84f3f30,0x3003110,0x60);
  sub_080ACFCC(3,&DAT_084f3f90,&DAT_03003190,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80d4a85,1);
  _DAT_0203a468 = sub_080AB7D4(2,0xb,0x1a,2);
  return;
}


// sub_080D4B48 @ 0x080D4B48

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D4B48(void)

{
  if ((short)DAT_0203a460 == 1) {
    DAT_0203a47c = sub_080ABCD4(0x17,0,6,3);
    _DAT_0203a480 = sub_080ABCD4(0x17,6,6,5);
  }
  return;
}


// sub_080D4B80 @ 0x080D4B80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 sub_080D4B80(undefined4 arg0)

{
  undefined4 uVar1;
  
  uVar1 = 0xc;
  if (DAT_0203a45e != 0) {
    uVar1 = 0xd;
  }
  switch((undefined2)arg0) {
  case 0:
    if (DAT_0203a460._2_2_ != 0) {
      return 0xb;
    }
    goto LAB_080d4c4a;
  case 1:
    if (DAT_0203a460._2_2_ != 0) {
      return 0xb;
    }
    break;
  case 2:
    if (DAT_0203a460._2_2_ != 1) {
      return 0xb;
    }
    break;
  case 3:
    if (DAT_0203a460._2_2_ != 2) {
      return 0xb;
    }
    break;
  case 4:
    if (DAT_0203a460._2_2_ != 0) {
      return 0xb;
    }
    goto LAB_080d4c12;
  case 5:
    if (DAT_0203a460._2_2_ != 1) {
      return 0xb;
    }
    goto LAB_080d4c12;
  case 6:
    if (DAT_0203a460._2_2_ != 2) {
      return 0xb;
    }
LAB_080d4c12:
    if (_DAT_0203a464 != 1) {
      return 0xb;
    }
    return uVar1;
  case 7:
    if (DAT_0203a460._2_2_ != 0) {
      return 0xb;
    }
    goto LAB_080d4c30;
  case 8:
    if (DAT_0203a460._2_2_ != 1) {
      return 0xb;
    }
    goto LAB_080d4c30;
  case 9:
    if (DAT_0203a460._2_2_ != 2) {
      return 0xb;
    }
LAB_080d4c30:
    if (_DAT_0203a464 != 0) {
      return 0xb;
    }
    return uVar1;
  case 10:
    if ((DAT_0203a460._2_2_ == 1) && (_DAT_0203a464 == 3)) {
      return uVar1;
    }
    if (DAT_0203a460._2_2_ != 2) {
      return 0xb;
    }
LAB_080d4c4a:
    if (_DAT_0203a464 == 3) {
      return uVar1;
    }
  default:
    goto LAB_080d4c52;
  }
  if (_DAT_0203a464 == 2) {
    return uVar1;
  }
LAB_080d4c52:
  return 0xb;
}


// sub_080D4C58 @ 0x080D4C58

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D4C58(void)

{
  undefined4 arg0;
  
  sub_080AA184(0x8002a4c,0,0,0);
  arg0 = sub_080C31F0();
  sub_080C8048(arg0,0xb8,0xb,0);
  sub_080AA184(0x8002a64,0,0,0);
  sub_080AA184(0x800080c,0,0,0);
  sub_080C8048(DAT_03005198,0xb8,0x3b,0);
  sub_080AA184(0x8002a7c,0,0,0);
  sub_080C8048(DAT_030037f0 * _DAT_0203a46c,0xb8,0x4b,0);
  return;
}


// sub_080D4D14 @ 0x080D4D14

void sub_080D4D14(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = 0;
  do {
    uVar5 = 0;
    iVar3 = uVar1 * 2;
    uVar1 = uVar1 + 1;
    uVar4 = iVar3 + uVar1;
    do {
      uVar2 = sub_080D4B80(uVar4 & 0xffff);
      sub_080AA184(*(undefined4 *)(uVar4 * 4 + 0x84f3fb0),0,uVar2 & 0xffff,0);
      uVar4 = uVar4 + 1;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 3);
  } while (uVar1 < 3);
  uVar1 = sub_080D4B80(0);
  sub_080AA184(&DAT_080027dc,0,uVar1 & 0xffff,0);
  uVar1 = sub_080D4B80(10);
  sub_080AA184(&DAT_0800287c,0,uVar1 & 0xffff,0);
  sub_080AA184(0x8002a3c,1,0xc,0);
  return;
}


// sub_080D4DF4 @ 0x080D4DF4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D4DF4(int arg0)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  
  puVar2 = (ushort *)0x203a454;
  Font_ResetGlyphSpriteCache(0x180);
  if ((short)DAT_0203a460 == 0) {
    if (*(int *)(arg0 + 0xc) != -1) {
      sub_080D4D14();
    }
    Text_DrawSpriteString(0x84f3fdc,0,0,0x10);
    uVar1 = 0;
    uVar3 = 0x7c0000;
    do {
      if (*puVar2 != 0xffff) {
        FontSprite_DrawGlyph((uint)*(ushort *)((uint)*puVar2 * 2 + 0x84f4014),0,0,uVar3 >> 0x10);
      }
      uVar3 = uVar3 + 0xc0000;
      puVar2 = puVar2 + 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 4);
  }
  else {
    sub_080D4D14();
    if (_DAT_0203a470 == 0) {
      Text_DrawSpriteString(0x84f3ff0,0,0,0x10);
      uVar1 = 0;
      uVar3 = 0x4c0000;
      do {
        if ((byte)(&DAT_0203a474)[uVar1] != 0xff) {
          FontSprite_DrawGlyph
                    ((uint)*(ushort *)((uint)(byte)(&DAT_0203a474)[uVar1] * 2 + 0x84f4014),0,0,
                     uVar3 >> 0x10);
        }
        uVar3 = uVar3 + 0xc0000;
        uVar1 = uVar1 + 1;
      } while (uVar1 < 8);
    }
    else {
      Text_DrawSpriteString(0x84f3ffc,0,0,0x10);
      if ((DAT_030031bc >> 4 & 1) == 0) {
        sub_080C4AB0(0,0,0xd6,0x61);
      }
    }
    sub_080D4C58();
  }
  return;
}


// sub_080D4F20 @ 0x080D4F20

undefined4 sub_080D4F20(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if ((&DAT_0203a474)[uVar1] == -1) {
      return uVar1 & 0xffff;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  return 0;
}


// sub_080D4F48 @ 0x080D4F48

int sub_080D4F48(void)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = 1;
  iVar4 = 0;
  uVar3 = 0;
  pbVar1 = (byte *)((int)&DAT_0203a478 + 3);
  do {
    if (*pbVar1 != 0xff) {
      iVar4 = iVar4 + iVar2 * (uint)*pbVar1;
      iVar2 = iVar2 * 10;
    }
    pbVar1 = pbVar1 + -1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  return iVar4;
}


// sub_080D4F7C @ 0x080D4F7C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint sub_080D4F7C(int arg0)

{
  return (uint)((uint)(arg0 * _DAT_0203a46c) <= DAT_03005198);
}


// sub_080D4FA8 @ 0x080D4FA8

undefined4 sub_080D4FA8(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint arg0;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = 0;
  do {
    arg0 = uVar3 & 0xffff;
    uVar1 = sub_080D4B80(arg0);
    if ((uVar1 & 0xffff) != 0xb) goto LAB_080d4fca;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0xb);
  arg0 = 10;
LAB_080d4fca:
                    /* WARNING: Could not recover jumptable at 0x080d4fce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(arg0);
  return uVar2;
}


// sub_080D4FD0 @ 0x080D4FD0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D4FD0(int arg0)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((short)DAT_0203a460 == 0) {
    if (DAT_0203a45e != 0) {
      DAT_0203a45e = DAT_0203a45e + -1;
      if (DAT_0203a45e == 0) {
        if (_DAT_0203a45c == 3) {
          *(undefined2 *)(arg0 + 0x1c) = 1;
          iVar2 = sub_080AD364(arg0);
          *(undefined4 *)(iVar2 + 0xc) = 1;
        }
        else {
          _DAT_0203a45c = _DAT_0203a45c + 1;
        }
      }
      goto LAB_080d5270;
    }
    if ((DAT_030031b8 & 1) == 0) {
      if ((DAT_030031b8 & 2) != 0) {
        if (_DAT_0203a45c != 0) {
          _DAT_0203a45c = _DAT_0203a45c - 1;
        }
        *(undefined2 *)((uint)_DAT_0203a45c * 2 + 0x203a454) = 0xffff;
LAB_080d51b8:
        sub_080C51D4(0x66);
        goto LAB_080d5270;
      }
LAB_080d51c4:
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          uVar1 = DAT_03003964 & 0x40;
          if (_DAT_0203a464 != 3) {
            uVar1 = _DAT_0203a464 + 1;
          }
          _DAT_0203a464 = uVar1;
          sub_080C51D4(100);
        }
      }
      else {
        if (_DAT_0203a464 == 0) {
          _DAT_0203a464 = 3;
        }
        else {
          _DAT_0203a464 = _DAT_0203a464 - 1;
        }
        sub_080C51D4(100);
      }
      if ((DAT_03003964 & 0x20) == 0) {
        if ((DAT_03003964 & 0x10) != 0) {
          if ((DAT_0203a460._2_2_ == 2) ||
             ((uVar1 = DAT_0203a460._2_2_ + 1, _DAT_0203a464 == 3 && (DAT_0203a460._2_2_ == 1)))) {
            uVar1 = DAT_03003964 & 0x20;
          }
          DAT_0203a460._2_2_ = uVar1;
          sub_080C51D4(100);
        }
      }
      else {
        if (DAT_0203a460._2_2_ == 0) {
          uVar1 = 2;
        }
        else {
          uVar1 = DAT_0203a460._2_2_ - 1;
          if ((_DAT_0203a464 == 3) && (DAT_0203a460._2_2_ == 2)) {
            uVar1 = 0;
          }
        }
        DAT_0203a460._2_2_ = uVar1;
        sub_080C51D4(100);
      }
      goto LAB_080d5270;
    }
    uVar3 = sub_080D4FA8();
    if ((uVar3 & 0xffff) == 10) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      iVar2 = sub_080AD364(arg0);
      *(undefined4 *)(iVar2 + 0xc) = 1;
    }
    else {
      uVar4 = sub_080D4FA8();
      *(short *)((uint)_DAT_0203a45c * 2 + 0x203a454) = (short)uVar4;
      DAT_0203a45e = 10;
    }
  }
  else if (_DAT_0203a470 == 0) {
    if ((DAT_0203a45e != 0) && (DAT_0203a45e = DAT_0203a45e + -1, DAT_0203a45e != 0))
    goto LAB_080d5270;
    if ((DAT_030031b8 & 1) == 0) {
      if ((DAT_030031b8 & 2) != 0) {
        uVar5 = sub_080D4F20();
        uVar3 = 0;
        if ((uVar5 & 0xffff) != 0) {
          uVar3 = (uVar5 & 0xffff) - 1 & 0xffff;
        }
        iVar2 = sub_080D4F48();
        sub_080C30AC(_DAT_0203a46c * iVar2);
        (&DAT_0203a474)[uVar3] = 0xff;
        iVar2 = sub_080D4F48();
        sub_080C30AC(-(_DAT_0203a46c * iVar2));
        DAT_030037f0 = sub_080D4F48();
        goto LAB_080d51b8;
      }
      goto LAB_080d51c4;
    }
    uVar3 = sub_080D4FA8();
    if ((uVar3 & 0xffff) == 10) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    else {
      uVar3 = sub_080D4F20();
      uVar5 = sub_080D4FA8();
      if (((uVar3 & 0xffff) != 0) || ((uVar5 & 0xffff) != 0)) {
        iVar2 = sub_080D4F48();
        sub_080C30AC(_DAT_0203a46c * iVar2);
        (&DAT_0203a474)[uVar3 & 0xffff] = (char)(uVar5 & 0xffff);
        uVar4 = sub_080D4F48();
        iVar2 = sub_080D4F7C(uVar4);
        if (iVar2 == 0) {
          (&DAT_0203a474)[uVar3 & 0xffff] = 0xff;
          _DAT_0203a470 = 1;
        }
        else {
          DAT_0203a45e = 10;
          DAT_030037f0 = sub_080D4F48();
          if (49999 < DAT_030037f0) {
            *(undefined2 *)(arg0 + 0x1c) = 1;
          }
        }
        iVar2 = sub_080D4F48();
        sub_080C30AC(-(_DAT_0203a46c * iVar2));
      }
    }
  }
  else {
    if ((DAT_030031b8 & 1) == 0) goto LAB_080d5270;
    iVar2 = sub_080D4F48();
    sub_080C30AC(_DAT_0203a46c * iVar2);
    uVar3 = 0;
    do {
      (&DAT_0203a474)[uVar3] = 0xff;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 8);
    DAT_030037f0 = 0;
    _DAT_0203a470 = 0;
  }
  sub_080C51D4(0x65);
LAB_080d5270:
                    /* WARNING: Could not recover jumptable at 0x080d5278. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D527C @ 0x080D527C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D527C(void)

{
  sub_080ABD30(DAT_0203a47c,1);
  sub_080ABD30(_DAT_0203a480,1);
  return;
}


// sub_080D529C @ 0x080D529C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D529C(undefined4 arg0,int arg1)

{
  uint uVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    sub_080AB91C(_DAT_0203a468,0);
  }
  if ((short)DAT_0203a460 == 0) {
    uVar2 = 0;
    DAT_030031cc = 0;
    do {
      uVar1 = (uint)*(ushort *)(uVar2 * 2 + 0x203a454);
      if (uVar1 == 0xffff) {
        DAT_030031cc = 0xffff;
        break;
      }
      DAT_030031cc = DAT_030031cc + *(ushort *)(uVar2 * 2 + 0x84f404c) * uVar1;
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < 4);
  }
  else {
    DAT_030037f0 = sub_080D4F48();
    DAT_03003ff0 = sub_080AD0FC(0x84f4028,0xffff);
  }
                    /* WARNING: Could not recover jumptable at 0x080d5312. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// Door_KeypadInitInputState @ 0x080D5324

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Door_KeypadInitInputState(int arg0)

{
  undefined4 uVar1;
  undefined4 uStack_14;
  
  uVar1 = sub_080AD0FC(0x84f4054,(uint)*(ushort *)(arg0 + 2));
  uStack_14 = 0;
  CpuSet(&uStack_14,0x203a454,0x5000200);
  DAT_0203a460._0_2_ = 0;
  DAT_0203a454 = 0xffff;
  DAT_0203a456 = 0xffff;
  DAT_0203a458 = 0xffff;
  DAT_0203a45a = 0xffff;
  DAT_0203a460._2_2_ = 1;
  _DAT_0203a464 = 1;
  return uVar1;
}


// sub_080D5374 @ 0x080D5374

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D5374(undefined4 arg0)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_14;
  
  uVar1 = sub_080AD0FC(0x84f40d8,0xffff);
  local_14 = 0;
  CpuSet(&local_14,0x203a454,0x5000200);
  DAT_0203a460._0_2_ = 1;
  uVar2 = 0;
  _DAT_0203a46c = arg0;
  do {
    (&DAT_0203a474)[uVar2] = 0xff;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  DAT_0203a460._2_2_ = 1;
  _DAT_0203a464 = 1;
  DAT_030037f0 = 0;
  DAT_03003fec = uVar1;
  return;
}


// sub_080D53E0 @ 0x080D53E0

uint sub_080D53E0(void)

{
  return (uint)(*DAT_03003fec == 0);
}


// sub_080D53FC @ 0x080D53FC

void sub_080D53FC(void)

{
  *(undefined4 *)(DAT_03003ff0 + 0xc) = 1;
  return;
}


// sub_080D540C @ 0x080D540C

void sub_080D540C(void)

{
  ushort uVar1;
  undefined4 uVar2;
  
  sub_080C1450();
  DAT_03000040 = 0;
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 & 0xfeff;
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 & 0xfbff;
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 & 0xf7ff;
  uVar1 = REG_BG1CNT;
  REG_BG1CNT = uVar1 & 0xffbf;
  DAT_0300003c = 0;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84001000;
  uVar2 = REG_DMA3CNT;
  REG_IE._0_2_ = 0x2003;
  REG_DISPSTAT = 0x18;
  REG_IME = 1;
  Font_ResetGlyphSpriteCache(0x180);
  sub_080ACFF4();
  sub_080A9AC0();
  sub_080AD0FC(0x84f9a28,0xffff);
  sub_080C5170(0x1c);
  DAT_0203db6a = 0;
  sub_080A9AB4(0x80d54f1);
  return;
}


// sub_080D54E0 @ 0x080D54E0

void sub_080D54E0(void)

{
  sub_080A9AB4(0x80d540d);
  return;
}


// sub_080D54F0 @ 0x080D54F0

void sub_080D54F0(void)

{
  sub_080AD01C();
  return;
}


// sub_080D54FC @ 0x080D54FC

void sub_080D54FC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6008000;
  REG_DMA3CNT = 0x840012c0;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2014874;
  REG_DMA3DAD = 0x6010000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D5554 @ 0x080D5554

void sub_080D5554(undefined4 arg0,undefined4 arg1)

{
  byte bVar1;
  uint uVar2;
  undefined4 in_r2;
  ushort *puVar3;
  uint uVar4;
  byte *pbVar5;
  
  switch(arg1) {
  case 0:
    LZ77UnCompWram(0x84f4140,0x200f874,in_r2);
    break;
  case 1:
    LZ77UnCompWram(0x84f5214,0x2010874,in_r2);
    break;
  case 2:
    LZ77UnCompWram(0x84f6108,0x2011874,in_r2);
    break;
  case 3:
    LZ77UnCompWram(0x84f6f7c,0x2012874,in_r2);
    break;
  case 4:
    LZ77UnCompWram(0x84f7c5c,0x2013874,in_r2);
    break;
  case 5:
    LZ77UnCompWram(0x84f89e0,0x2014874,in_r2);
    LZ77UnCompWram(0x84f8ff0,&DAT_02015874,in_r2);
    break;
  case 6:
    pbVar5 = (byte *)0x84f8760;
    sub_080AB250(0x84f9528,0x2000000,0,0);
    uVar2 = 0;
    do {
      uVar4 = 0;
      do {
        puVar3 = (ushort *)((uVar2 * 0x20 + uVar4) * 2 + 0x2000000);
        bVar1 = *pbVar5;
        pbVar5 = pbVar5 + 1;
        *puVar3 = *puVar3 & 0xfff | (ushort)bVar1 << 0xc;
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 < 0x1e);
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < 0x14);
    sub_080ACFCC(3,0x84f93e8,0x30029b0,0x100);
    DisplayList_Add(0x80d54fd,1);
    break;
  case 7:
    sub_080AAEDC(4);
    break;
  case 8:
    sub_080AAF48(4);
  }
  return;
}


// sub_080D56DC @ 0x080D56DC

void sub_080D56DC(int arg0)

{
  if (*(short *)(arg0 + 0x24) == 1) {
    sub_080AA184(0x8002ab0,0,0,0);
  }
  if (*(short *)(arg0 + 0x26) == 1) {
    sub_080AA184(0x8002af8,0,0,0);
  }
  return;
}


// sub_080D5730 @ 0x080D5730

void sub_080D5730(void)

{
  sub_080D5B8C(0);
  return;
}


// sub_080D573C @ 0x080D573C

void sub_080D573C(int arg0,undefined4 arg1)

{
  undefined2 uVar1;
  undefined4 arg0_00;
  
  switch(arg1) {
  case 0:
    sub_080ACFA4(3,0x7fff,0x3002fb0,0x20);
    sub_080AABB0();
    uVar1 = 1;
    goto LAB_080d584a;
  case 1:
    sub_080ACFCC(3,0x84f94e8,0x3002bb0,0x20);
    goto LAB_080d582e;
  case 2:
    sub_080ACFA4(3,0x7fff,0x3002fd0,0x20);
    sub_080AABB0();
    *(undefined2 *)(arg0 + 0x26) = 1;
    break;
  case 3:
    sub_080ACFCC(3,0x84f9508,0x3002bd0,0x20);
    arg0_00 = 0x110;
    goto LAB_080d5832;
  case 4:
    sub_080ACFA4(3,0x7fff,0x3002bd0,0x20);
    arg0_00 = 0x110;
    goto LAB_080d5832;
  case 5:
    *(undefined2 *)(arg0 + 0x26) = 0;
    break;
  case 6:
    sub_080ACFA4(3,0x7fff,0x3002bb0,0x20);
LAB_080d582e:
    arg0_00 = 0x100;
LAB_080d5832:
    sub_080AB054(arg0_00,0x10,6,0x20);
    break;
  case 7:
    uVar1 = 0;
LAB_080d584a:
    *(undefined2 *)(arg0 + 0x24) = uVar1;
  }
  return;
}


// sub_080D5854 @ 0x080D5854

void sub_080D5854(undefined4 arg0,int arg1)

{
  ushort uVar1;
  
  if (arg1 == 0) {
    uVar1 = REG_BG1CNT;
    REG_BG1CNT = uVar1 | 0x40;
    DAT_0300003c = 0;
  }
  else {
    sub_080ACFA4(3,0x7fff,0x30029b0,0x100);
    sub_080AB054(0,0x80,0x10,0x20);
  }
  return;
}


// sub_080D58A4 @ 0x080D58A4

void sub_080D58A4(void)

{
  if (((DAT_030031bc & 0x1f) == 0) && ((DAT_0300003c & 0xf) != 0xf)) {
    DAT_0300003c = DAT_0300003c + 0x11;
  }
  return;
}


// sub_080D58D0 @ 0x080D58D0

void sub_080D58D0(void)

{
  sub_080AAF48(4);
  DAT_0200e808 = 1;
  return;
}


// sub_080D58E8 @ 0x080D58E8

void sub_080D58E8(void)

{
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  CpuSet(local_8,0x203a454,0x5000200);
  sub_080AD0FC(0x84f9c94,0xffff);
  return;
}


// sub_080D5918 @ 0x080D5918

void sub_080D5918(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  DAT_03005183 = 0xc;
  uVar1 = 0;
  do {
    sub_080C0074(0,uVar1,(uint)*(byte *)(uVar1 + 0x8509640));
    sub_080BF938(0);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 7);
  DAT_030046cd = 0x32;
  DAT_030046c8 = 0x32d7a;
  uVar1 = 0;
  do {
    uVar2 = 0;
    uVar3 = uVar1 + 1;
    do {
      sub_080C3328(uVar1 & 0xffff);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x32);
    uVar1 = uVar3;
  } while (uVar3 < 0xff);
  sub_080C062C(0x6e);
  sub_080C062C(0x71);
  sub_080C062C(0x40);
  sub_080C062C(100);
  sub_080C062C(0xae);
  sub_080C062C(0x7d);
  sub_080C062C(0x59);
  sub_080C062C(0xb);
  sub_080C062C(0x4d);
  sub_080C062C(0x9c);
  sub_080C062C(0x6b);
  sub_080C062C(0x76);
  DAT_0300519c = 10000;
  DAT_03005198 = 10000;
  DAT_030051a0 = 10000;
  return;
}


// sub_080D59E8 @ 0x080D59E8

void sub_080D59E8(void)

{
  DAT_03000000 = 0;
  DAT_03000002 = 0xffff;
  DAT_03000004 = 0xffe0;
  DAT_03000006 = 0xffe8;
  DAT_03000008 = 0xffe0;
  DAT_0300000a = 0xffe8;
  DAT_0300000c = 0;
  DAT_0300000e = 0;
  return;
}


// sub_080D5A48 @ 0x080D5A48

void sub_080D5A48(void)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  REG_DISPCNT = 0x7f00;
  REG_BG0CNT = 0x8004;
  REG_BG1CNT = 0x820d;
  REG_BG2CNT = 0x840e;
  REG_BG3CNT = 0x4607;
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x3f;
  sub_080D59E8();
  sub_080C1440();
  sub_080AABD4(0);
  local_18 = 0;
  CpuSet(&local_18,0x20381dc,0x5000400);
  local_14 = 0;
  CpuSet(&local_14,0x200dfd4,0x5000200);
  REG_IE._0_2_ = 0x2003;
  REG_DISPSTAT = 0x18;
  REG_IME = 1;
  sub_080C5170(0);
  DAT_0203db6a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  sub_080ACFF4();
  local_10 = 0;
  CpuSet(&local_10,0x203a454,0x5000200);
  sub_080AD0FC(0x8509cf8,0xffff);
  DAT_030069e4 = sub_080AD0FC(0x8509cd0,0xffff);
  sub_080A9AB4(0x80d5be5);
  return;
}


// sub_080D5B64 @ 0x080D5B64

void sub_080D5B64(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x81002000;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D5B8C @ 0x080D5B8C

void sub_080D5B8C(uint arg0)

{
  int iVar1;
  undefined4 local_10;
  
  DAT_0203bb68 = arg0 & 0xffff;
  iVar1 = sub_080D6A34();
  if ((iVar1 == 0) && ((arg0 & 0xffff) == 4)) {
    DAT_0203bb68 = 3;
  }
  sub_080A9AB4(0x80d5a49);
  local_10 = 0;
  CpuSet(&local_10,0x3002db0,0x5000100);
  sub_080AABB0();
  DisplayList_Add(0x80d5b65,1);
  return;
}


// sub_080D5BE4 @ 0x080D5BE4

void sub_080D5BE4(void)

{
  sub_080AD01C();
  return;
}


// sub_080D5BF0 @ 0x080D5BF0

void sub_080D5BF0(int arg0)

{
  *(short *)(arg0 + 0x1e) = (short)DAT_0203bb68;
  return;
}


// sub_080D5BFC @ 0x080D5BFC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D5BFC(void)

{
  int iVar1;
  
  iVar1 = sub_080D1430();
  if (iVar1 == 1) {
    _DAT_0203a45c = 1;
  }
  iVar1 = sub_080D13D0(3);
  if (iVar1 == 1) {
    DAT_0203a45e = 1;
  }
  return;
}


// sub_080D5C20 @ 0x080D5C20

void sub_080D5C20(void)

{
  undefined4 uVar1;
  dword dVar2;
  undefined1 local_8 [8];
  
  switch(DAT_0203a454) {
  case 0:
    REG_DMA3SAD = 0x200f874;
    REG_DMA3DAD = 0x6008000;
    dVar2 = 0x84002000;
    break;
  case 1:
    REG_DMA3SAD = 0x200f874;
    REG_DMA3DAD = 0x6010000;
    dVar2 = 0x84002000;
    break;
  case 2:
    REG_DMA3SAD = 0x81b9bb0;
    dVar2 = 0x6001000;
    goto LAB_080d622c;
  case 3:
    REG_DMA3SAD = 0x81ba3b0;
    dVar2 = 0x6002000;
LAB_080d622c:
    REG_DMA3DAD = dVar2;
    dVar2 = 0x84000200;
    break;
  default:
    goto switchD_080d5c36_caseD_4;
  case 100:
    REG_DMA3SAD = 0x200f874;
    REG_DMA3DAD = 0x6004000;
    dVar2 = 0x84002000;
    break;
  case 0x65:
    REG_DMA3SAD = 0x200f874;
    REG_DMA3DAD = 0x6010000;
    REG_DMA3CNT = 0x84002000;
    uVar1 = REG_DMA3CNT;
    sub_080D59E8();
    REG_BG1CNT = 0x820d;
    REG_BG2CNT = 0x840e;
    sub_080C1440();
    return;
  case 0x66:
    REG_DMA3SAD = 0x84f9fe0;
    REG_DMA3DAD = 0x6000000;
    dVar2 = 0x84000140;
    break;
  case 0x68:
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x6000000;
    dVar2 = 0x85000140;
    break;
  case 0x69:
    REG_DMA3SAD = 0x200f874;
    REG_DMA3DAD = 0x6004000;
    dVar2 = 0x84002000;
    break;
  case 0x6a:
    REG_DMA3SAD = 0x84fa860;
    REG_DMA3DAD = 0x6003000;
    dVar2 = 0x84000140;
    break;
  case 0x6c:
    REG_DMA3SAD = 0x200f874;
    REG_DMA3DAD = 0x600c000;
    dVar2 = 0x84001000;
    break;
  case 0x6d:
    REG_DMA3SAD = 0x84fb260;
    REG_DMA3DAD = 0x6001000;
    dVar2 = 0x84000140;
    break;
  case 0x6e:
    REG_DMA3SAD = 0x200f874;
    REG_DMA3DAD = 0x6010000;
    dVar2 = 0x84002000;
    break;
  case 0x6f:
    REG_DMA3SAD = 0x84fcb60;
    REG_DMA3DAD = 0x6000000;
    dVar2 = 0x84000140;
    break;
  case 0x71:
    REG_DMA3SAD = 0x84fb760;
    REG_DMA3DAD = 0x6001000;
    dVar2 = 0x84000140;
    break;
  case 0x73:
    REG_DMA3SAD = 0x84fb760;
    REG_DMA3DAD = 0x6002000;
    dVar2 = 0x84000140;
    break;
  case 0x74:
    REG_DMA3SAD = 0x84fbc60;
    REG_DMA3DAD = 0x6001000;
    dVar2 = 0x84000140;
    break;
  case 0x75:
    REG_DMA3SAD = 0x84fb260;
    REG_DMA3DAD = 0x6002000;
    dVar2 = 0x84000140;
    break;
  case 0x76:
    REG_DMA3SAD = 0x84fbc60;
    REG_DMA3DAD = 0x6002000;
    dVar2 = 0x84000140;
    break;
  case 0x77:
    REG_DMA3SAD = 0x84fc160;
    REG_DMA3DAD = 0x6001000;
    dVar2 = 0x84000140;
    break;
  case 0x78:
    Font_ResetGlyphSpriteCache(0x180);
    return;
  case 0x79:
    REG_DMA3SAD = 0x84fc160;
    REG_DMA3DAD = 0x6002000;
    dVar2 = 0x84000140;
    break;
  case 0x7a:
    REG_BG1CNT = 0x8205;
    DAT_03000006 = 0;
    DAT_03000004 = 0;
    REG_DMA3SAD = 0x84fc660;
    REG_DMA3DAD = 0x6001000;
    dVar2 = 0x84000140;
    break;
  case 0x7b:
    REG_BG2CNT = 0x8406;
    DAT_0300000a = 0;
    DAT_03000008 = 0;
    REG_DMA3SAD = 0x84fc660;
    REG_DMA3DAD = 0x6002000;
    dVar2 = 0x84000140;
    break;
  case 0x7c:
    REG_DMA3SAD = 0x84fcb60;
    REG_DMA3DAD = 0x6001000;
    dVar2 = 0x84000140;
    break;
  case 0x7d:
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x6003000;
    dVar2 = 0x85000140;
    break;
  case 0x7e:
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x6002000;
    dVar2 = 0x85000140;
    break;
  case 0x80:
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x6000000;
    dVar2 = 0x85001000;
    break;
  case 0x81:
    REG_DMA3SAD = 0x84fad60;
    REG_DMA3DAD = 0x6003800;
    REG_DMA3CNT = 0x84000140;
    uVar1 = REG_DMA3CNT;
    DAT_0300000c = 0x18;
    DAT_03000008 = 0xfff8;
    DAT_03000004 = 0xfff8;
    goto switchD_080d5c36_caseD_4;
  }
  REG_DMA3CNT = dVar2;
switchD_080d5c36_caseD_4:
  return;
}


// sub_080D624C @ 0x080D624C

void sub_080D624C(int arg0,int arg1,undefined4 arg2)

{
  *(undefined1 *)(arg0 + 0x24 + arg1) = (undefined1)arg2;
  return;
}


// sub_080D6254 @ 0x080D6254

void sub_080D6254(undefined4 arg0,int arg1,undefined4 arg2)

{
  *(undefined2 *)((int)&DAT_0203a460 + arg1 * 2 + 2) = (undefined2)arg2;
  return;
}


