/* Ghidra decompilation of asm/code_080AB9F4.s (reference only; not compiled). */

// sub_080AB9F4 @ 0x080AB9F4

void sub_080AB9F4(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200dfd4;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080ABA18 @ 0x080ABA18

void sub_080ABA18(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200dfd4;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080ABA3C @ 0x080ABA3C

void sub_080ABA3C(int arg0,uint arg1,uint arg2,uint arg3)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000000;
  
  uVar7 = arg3 & 0xffff;
  uVar1 = in_stack_00000000 & 0xffff;
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      uVar4 = 0;
      if (uVar7 != 0) {
        uVar6 = uVar1 - 1;
        do {
          iVar3 = 4;
          if (uVar4 == 0) {
            if (uVar5 == 0) {
              iVar3 = 0;
            }
            else {
              if (uVar5 != uVar6) goto LAB_080abab0;
              iVar3 = 6;
            }
          }
          else {
LAB_080abab0:
            if (uVar4 == uVar7 - 1) {
              if (uVar5 == 0) {
                iVar3 = 2;
              }
              else {
                if (uVar5 != uVar6) goto LAB_080abac6;
                iVar3 = 8;
              }
            }
            else {
LAB_080abac6:
              if (uVar4 == 0) {
                iVar3 = 3;
              }
              else if (uVar5 == 0) {
                iVar3 = 1;
              }
              else if (uVar4 == uVar7 - 1) {
                iVar3 = 5;
              }
              else if (uVar5 == uVar6) {
                iVar3 = 7;
              }
            }
          }
          if (*(int *)(arg0 + 0x10) == 0) {
            puVar2 = (undefined2 *)(iVar3 * 2 + 0x815ec2c);
          }
          else {
            puVar2 = (undefined2 *)(iVar3 * 2 + *(int *)(arg0 + 0x10));
          }
          *(undefined2 *)
           (((arg2 & 0xffff) + uVar5) * 0x40 + ((arg1 & 0xffff) + uVar4) * 2 + 0x200dfd4) = *puVar2;
          uVar4 = uVar4 + 1 & 0xffff;
        } while (uVar4 < uVar7);
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < uVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x080abb1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080ABB20 @ 0x080ABB20

void sub_080ABB20(int arg0)

{
  dword arg0_00;
  
  if (arg0 == 1) {
    arg0_00 = 0x80ab9d1;
  }
  else if (arg0 == 0) {
    arg0_00 = 0x80ab9b1;
  }
  else {
    if (arg0 != 2) {
      if (arg0 != 3) {
        return;
      }
      DisplayList_Add(0x80aba19,1);
      return;
    }
    arg0_00 = 0x80ab9f5;
  }
  DisplayList_Add(arg0_00,1);
  return;
}


// sub_080ABB64 @ 0x080ABB64

void sub_080ABB64(int arg0)

{
  sub_080AB438(0,0x200dfd4,(uint)*(ushort *)(arg0 + 0x24),(uint)*(ushort *)(arg0 + 0x26));
  sub_080ABB20((uint)*(ushort *)(arg0 + 0x2c));
  DAT_0200e8d4 = DAT_0200e8d4 + -1;
  return;
}


// sub_080ABBA0 @ 0x080ABBA0

void sub_080ABBA0(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x1e) = (undefined2)arg1;
  return;
}


// sub_080ABBA4 @ 0x080ABBA4

void sub_080ABBA4(int arg0,int arg1)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080ABA3C(arg0 + 0x24,(uint)*(ushort *)(arg0 + 0x24),(uint)*(ushort *)(arg0 + 0x26),
               (uint)*(ushort *)(arg0 + 0x28));
  sub_080ABB20((uint)*(ushort *)(arg0 + 0x2c));
  if (arg1 == 0) {
    if (*(short *)(arg0 + 0x2e) != *(short *)(arg0 + 0x2a)) {
      *(undefined2 *)(arg0 + 0x1c) = 0;
      *(short *)(arg0 + 0x2e) = *(short *)(arg0 + 0x2e) + 1;
      goto LAB_080abc36;
    }
    uVar3 = 1;
  }
  else {
    if (arg1 == 1) {
      sub_080AB438(0,0x200dfd4,(uint)*(ushort *)(arg0 + 0x24),
                   (uint)*(ushort *)(arg0 + 0x2e) + (uint)*(ushort *)(arg0 + 0x26) & 0xffff);
      if (*(short *)(arg0 + 0x2e) == 2) {
        *(undefined2 *)(arg0 + 0x1c) = 1;
      }
      else {
        *(undefined2 *)(arg0 + 0x1c) = 0;
        *(short *)(arg0 + 0x2e) = *(short *)(arg0 + 0x2e) + -1;
      }
      goto LAB_080abc36;
    }
    uVar1 = *(ushort *)(arg0 + 0x2e);
    if (uVar1 == *(ushort *)(arg0 + 0x2a)) {
      uVar3 = 1;
    }
    else {
      if (*(ushort *)(arg0 + 0x2a) < uVar1) {
        sVar2 = -1;
      }
      else {
        sVar2 = 1;
      }
      *(ushort *)(arg0 + 0x2e) = uVar1 + sVar2;
      uVar3 = 0;
    }
  }
  *(undefined2 *)(arg0 + 0x1c) = uVar3;
LAB_080abc36:
                    /* WARNING: Could not recover jumptable at 0x080abc3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080ABC40 @ 0x080ABC40

int sub_080ABC40(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  undefined2 in_stack_00000000;
  
  iVar1 = sub_080AD0FC(0x815ec40,0xffff);
  *(undefined2 *)(iVar1 + 0x24) = (undefined2)arg0;
  *(undefined2 *)(iVar1 + 0x26) = (undefined2)arg1;
  *(undefined2 *)(iVar1 + 0x28) = (undefined2)arg2;
  *(undefined2 *)(iVar1 + 0x2a) = (undefined2)arg3;
  *(undefined2 *)(iVar1 + 0x2c) = in_stack_00000000;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined2 *)(iVar1 + 0x2e) = 2;
  DAT_0200e8d4 = DAT_0200e8d4 + 1;
  return iVar1;
}


// sub_080ABCAC @ 0x080ABCAC

void sub_080ABCAC(uint arg0,uint arg1,uint arg2,uint arg3)

{
  int iVar1;
  undefined4 in_stack_00000000;
  
  iVar1 = sub_080ABC40(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  *(undefined4 *)(iVar1 + 0x34) = in_stack_00000000;
  return;
}


// sub_080ABCD4 @ 0x080ABCD4

int sub_080ABCD4(uint arg0,uint arg1,uint arg2,uint arg3)

{
  int iVar1;
  
  iVar1 = sub_080ABC40(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  *(undefined2 *)(iVar1 + 0x2e) = *(undefined2 *)(iVar1 + 0x2a);
  return iVar1;
}


// sub_080ABD04 @ 0x080ABD04

int sub_080ABD04(uint arg0,uint arg1,uint arg2,uint arg3)

{
  int iVar1;
  undefined4 in_stack_00000004;
  
  iVar1 = sub_080ABCD4(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  *(undefined4 *)(iVar1 + 0x34) = in_stack_00000004;
  return iVar1;
}


// sub_080ABD30 @ 0x080ABD30

void sub_080ABD30(int arg0,int arg1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  else {
    sub_080ABB64(arg0);
    sub_080AD1FC(arg0);
  }
                    /* WARNING: Could not recover jumptable at 0x080abd4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080ABD50 @ 0x080ABD50

void sub_080ABD50(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x26) = (undefined2)arg1;
  *(undefined2 *)(arg0 + 0x1e) = 2;
  return;
}


// sub_080ABD58 @ 0x080ABD58

undefined4 sub_080ABD58(short *arg0)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*arg0 == 0) || (arg0[0xf] == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}


// sub_080ABD74 @ 0x080ABD74

void sub_080ABD74(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x203a2e4;
  REG_DMA3DAD = DAT_03000048 * 0x20 + 0x6010000;
  REG_DMA3CNT = 0x84000040;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080ABDA4 @ 0x080ABDA4

void sub_080ABDA4(int arg0,int arg1)

{
  if (arg1 == 0) {
    sub_080C7E24(0x203a2e4,0x815ed28);
    DAT_03000048 = *(undefined4 *)(arg0 + 0x2c);
    DisplayList_Add(0x80abd75,1);
  }
  return;
}


// sub_080ABDDC @ 0x080ABDDC

void sub_080ABDDC(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_03003964 & 0xc0) != 0) {
      *(uint *)(arg0 + 0x28) = *(int *)(arg0 + 0x28) + 1U & 1;
      sub_080C51D4(100);
    }
  }
  else {
    DAT_030031cc = *(int *)(arg0 + 0x28);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if (*(int *)(arg0 + 0x28) == 0) {
      sub_080C51D4(0x65);
    }
    else {
      sub_080C51D4(0x66);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080abe3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080ABE40 @ 0x080ABE40

void sub_080ABE40(void)

{
  return;
}


// sub_080ABE44 @ 0x080ABE44

void sub_080ABE44(int arg0)

{
  undefined4 arg2;
  undefined4 arg2_00;
  
  arg2_00 = 0;
  arg2 = 0;
  sub_080AA184(0x8001058,0,0,0);
  if (*(int *)(arg0 + 0x28) == 0) {
    arg2_00 = 2;
  }
  else {
    arg2 = 2;
  }
  sub_080AA1F4(0x815ed30,0,arg2_00,0);
  sub_080AA1F4(0x815ed38,0,arg2,0);
  return;
}


// sub_080ABEB4 @ 0x080ABEB4

int sub_080ABEB4(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x815ed40,0xffff);
  *(uint *)(iVar1 + 0x28) = arg0 & 0xffff;
  *(undefined4 *)(iVar1 + 0x2c) = 0x178;
  return iVar1;
}


// sub_080ABEE0 @ 0x080ABEE0

int sub_080ABEE0(uint arg0,uint arg1)

{
  int iVar1;
  
  iVar1 = sub_080ABEB4(arg0 & 0xffff);
  *(uint *)(iVar1 + 0x28) = arg0 & 0xffff;
  *(uint *)(iVar1 + 0x2c) = arg1 & 0xffff;
  return iVar1;
}


// sub_080ABF04 @ 0x080ABF04

uint sub_080ABF04(short *arg0)

{
  return (uint)(*arg0 == 0);
}


// sub_080ABF18 @ 0x080ABF18

void sub_080ABF18(int arg0)

{
  *(short *)(arg0 + 0x1e) = (short)DAT_030031cc;
  return;
}


// sub_080ABF24 @ 0x080ABF24

void sub_080ABF24(uint arg0)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint *puVar6;
  uint uVar7;
  
  puVar2 = (uint *)(((arg0 & 0xff) >> 4) * 0x400 + (arg0 & 0xf) * 0x20 +
                   *(int *)(((arg0 & 0xffff) >> 8) * 8 + 0x815ed88));
  pbVar5 = (byte *)0x20391e0;
  uVar7 = 0;
  puVar6 = puVar2;
  do {
    uVar3 = *puVar6;
    *pbVar5 = (byte)((uVar3 & 0xc0) >> 6) | (byte)uVar3 & 0x30;
    pbVar5[1] = (byte)((uVar3 & 0xc) >> 2) | (byte)((uVar3 & 3) << 4);
    uVar4 = uVar3 >> 8;
    pbVar5[2] = (byte)((uVar4 & 0xc0) >> 6) | (byte)(uVar3 >> 8) & 0x30;
    pbVar5[3] = (byte)((uVar4 & 0xc) >> 2) | (byte)((uVar4 & 3) << 4);
    uVar4 = uVar3 >> 0x10;
    pbVar5[4] = (byte)((uVar4 & 0xc0) >> 6) | (byte)(uVar3 >> 0x10) & 0x30;
    pbVar5[5] = (byte)((uVar4 & 0xc) >> 2) | (byte)((uVar4 & 3) << 4);
    bVar1 = (byte)(uVar3 >> 0x18);
    pbVar5[6] = bVar1 >> 6 | bVar1 & 0x30;
    pbVar5[7] = (byte)((uVar3 >> 0x18 & 0xc) >> 2) | (byte)((uVar3 >> 0x18 & 3) << 4);
    pbVar5 = pbVar5 + 8;
    uVar7 = uVar7 + 1;
    puVar6 = puVar6 + 1;
  } while (uVar7 < 8);
  pbVar5 = &DAT_020395e0;
  uVar7 = 0;
  puVar6 = puVar2 + 0x80;
  do {
    uVar3 = *puVar6;
    *pbVar5 = (byte)((uVar3 & 0xc0) >> 6) | (byte)uVar3 & 0x30;
    pbVar5[1] = (byte)((uVar3 & 0xc) >> 2) | (byte)((uVar3 & 3) << 4);
    uVar4 = uVar3 >> 8;
    pbVar5[2] = (byte)((uVar4 & 0xc0) >> 6) | (byte)(uVar3 >> 8) & 0x30;
    pbVar5[3] = (byte)((uVar4 & 0xc) >> 2) | (byte)((uVar4 & 3) << 4);
    uVar4 = uVar3 >> 0x10;
    pbVar5[4] = (byte)((uVar4 & 0xc0) >> 6) | (byte)(uVar3 >> 0x10) & 0x30;
    pbVar5[5] = (byte)((uVar4 & 0xc) >> 2) | (byte)((uVar4 & 3) << 4);
    bVar1 = (byte)(uVar3 >> 0x18);
    pbVar5[6] = bVar1 >> 6 | bVar1 & 0x30;
    pbVar5[7] = (byte)((uVar3 >> 0x18 & 0xc) >> 2) | (byte)((uVar3 >> 0x18 & 3) << 4);
    pbVar5 = pbVar5 + 8;
    uVar7 = uVar7 + 1;
    puVar6 = puVar6 + 1;
  } while (uVar7 < 8);
  return;
}


// sub_080AC0E4 @ 0x080AC0E4

void sub_080AC0E4(undefined4 arg0)

{
  DAT_020360e0 = (undefined2)arg0;
  return;
}


// Font_ResetGlyphSpriteCache @ 0x080AC0F0

void Font_ResetGlyphSpriteCache(undefined4 arg0)

{
  undefined4 uVar1;
  undefined2 local_8 [4];
  
  local_8[0] = 0;
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x20360dc;
  REG_DMA3CNT = 0x81000044;
  uVar1 = REG_DMA3CNT;
  DAT_020360dc = (undefined2)arg0;
  sub_080AC0E4(0x40);
  return;
}


// Font_CacheGlyphSprite @ 0x080AC124

int Font_CacheGlyphSprite(undefined4 arg0)

{
  int iVar1;
  uint arg0_00;
  
  arg0_00 = (uint)(ushort)arg0;
  if (DAT_020360de == DAT_020360e0) {
    iVar1 = -1;
  }
  else {
    sub_080ABF24(arg0_00);
    sub_080AC438(arg0_00,(uint)(DAT_020360de >> 4) * 0x800 + (DAT_020360de & 0xf) * 0x40 + 0x20361dc
                );
    (&DAT_020360e4)[DAT_020360de] = (ushort)arg0;
    DAT_020360de = DAT_020360de + 1;
    if (DAT_020360e2 == 0) {
      DisplayList_Add(0x80ac199,1);
      DAT_020360e2 = 1;
    }
    iVar1 = (int)((DAT_020360de - 1) * 0x10000) >> 0x10;
  }
  return iVar1;
}


// Font_UploadGlyphSpriteTiles @ 0x080AC198

void Font_UploadGlyphSpriteTiles(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x20361dc;
  REG_DMA3DAD = (DAT_020360dc & 0x7ff) * 0x20 + 0x6010000;
  REG_DMA3CNT = ((DAT_020360de >> 4) + 1 & 0x1f) << 9 | 0x84000000;
  uVar1 = REG_DMA3CNT;
  DAT_020360e2 = 0;
  return;
}


// sub_080AC1DC @ 0x080AC1DC

undefined4 sub_080AC1DC(undefined4 arg0)

{
  uint uVar1;
  int iVar2;
  short *psVar3;
  
  uVar1 = (uint)DAT_020360de;
  if ((uVar1 != 0) && (iVar2 = 0, uVar1 != 0)) {
    psVar3 = &DAT_020360e4;
    do {
      if (*psVar3 == (short)arg0) {
        return (int)(short)iVar2;
      }
      psVar3 = psVar3 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)uVar1);
  }
  return 0xffffffff;
}


// FontSprite_DrawGlyph @ 0x080AC218

void FontSprite_DrawGlyph(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  undefined4 uVar1;
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  if ((arg0_00 != 0) && (arg0_00 != 0x3f)) {
    uVar1 = sub_080AC1DC(arg0_00);
    if ((short)uVar1 == -1) {
      Font_CacheGlyphSprite(arg0_00);
    }
    sub_080AA1F4(0x815ee18,arg1 & 0xffff,0,arg2 & 0xffff);
  }
  return;
}


// sub_080AC2A0 @ 0x080AC2A0

void sub_080AC2A0(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  undefined4 uVar1;
  uint arg0_00;
  uint in_stack_00000004;
  
  arg0_00 = arg0 & 0xffff;
  if ((arg0_00 != 0) && (arg0_00 != 0x3f)) {
    uVar1 = sub_080AC1DC(arg0_00);
    if ((short)uVar1 == -1) {
      Font_CacheGlyphSprite(arg0_00);
    }
    sub_080AA1F4(0x815ee18,arg1 & 0xffff,in_stack_00000004 & 0xffff,arg2 & 0xffff);
  }
  return;
}


// Text_DrawSpriteString @ 0x080AC334

void Text_DrawSpriteString(ushort *arg0,uint arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  uint uVar2;
  uint arg3_00;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000004;
  
  arg3_00 = arg3 & 0xffff;
  for (; (uVar1 = *arg0, uVar1 != 0 && (uVar1 != 0x301)); arg0 = arg0 + 1) {
    uVar2 = arg3 & 0xffff;
    if (uVar1 != 0x300) {
      FontSprite_DrawGlyph((uint)*arg0,arg1 & 0xffff,arg2 & 0xffff,arg3_00);
      uVar2 = arg3_00 + (in_stack_00000004 & 0xffff) & 0xffff;
    }
    arg3_00 = uVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x080ac3a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// Text_DrawSpriteStringTinted @ 0x080AC3AC

void Text_DrawSpriteStringTinted(ushort *arg0,uint arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  uint uVar2;
  uint arg3_00;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000004;
  
  arg3_00 = arg3 & 0xffff;
  for (; (uVar1 = *arg0, uVar1 != 0 && (uVar1 != 0x301)); arg0 = arg0 + 1) {
    uVar2 = arg3 & 0xffff;
    if (uVar1 != 0x300) {
      sub_080AC2A0((uint)*arg0,arg1 & 0xffff,arg2 & 0xffff,arg3_00);
      uVar2 = arg3_00 + (in_stack_00000004 & 0xffff) & 0xffff;
    }
    arg3_00 = uVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x080ac432. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AC438 @ 0x080AC438

void sub_080AC438(undefined4 *arg0,undefined4 *arg1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 0xf;
  puVar2 = arg0;
  puVar4 = arg1;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  puVar2 = arg0 + 0x100;
  puVar4 = arg1 + 0x100;
  iVar3 = 0xf;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  return;
}


// sub_080AC468 @ 0x080AC468

int sub_080AC468(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = (DAT_030020e0 >> 0x10) * 0x4e6d;
  uVar4 = DAT_030020e0 & 0xffff;
  uVar2 = iVar5 * uVar4;
  uVar1 = REG_VCOUNT;
  uVar3 = (uint)uVar1 * DAT_030031bc;
  DAT_030020e0 = (uVar2 + iVar5 >> 0x10) +
                 (uVar4 * ((uVar2 & 0xffff0000) - 0xdd3c) >> 0x10) * uVar4 * 0x10000 +
                 uVar3 * 0x20100804 + (uVar3 >> 3) + (uVar3 >> 0xc) + (uVar3 >> 0x15) +
                 (uVar3 >> 0x1e);
  return DAT_030020e0;
}


// sub_080AC4E4 @ 0x080AC4E4

void sub_080AC4E4(int arg0,int arg1,uint arg2,uint arg3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000000;
  uint in_stack_00000004;
  uint in_stack_00000008;
  ushort in_stack_0000000c;
  undefined4 local_34;
  
  uVar3 = 0;
  if (in_stack_0000000c != 0) {
    do {
      local_34 = 0;
      uVar3 = uVar3 + 1;
      if ((in_stack_00000008 & 0xffff) != 0) {
        iVar5 = arg1 + ((in_stack_00000004 & 0xffff) >> 3) * 0x400;
        iVar7 = (in_stack_00000004 & 7) * 4;
        uVar6 = in_stack_00000000;
        uVar4 = arg2;
        do {
          pbVar8 = (byte *)(((uVar6 & 0xffff) >> 3) * 0x20 + iVar5 + iVar7 + ((uVar6 & 7) >> 1));
          bVar1 = *(byte *)(arg0 + ((arg3 & 0xffff) >> 3) * 0x400 + ((uVar4 & 0xffff) >> 3) * 0x20 +
                            (arg3 & 7) * 4 + ((uVar4 & 7) >> 1));
          if ((uVar6 & 1) == 0) {
            bVar2 = bVar1 & 0xf;
          }
          else {
            bVar2 = bVar1 << 4;
          }
          *pbVar8 = *pbVar8 | bVar2;
          uVar6 = (uVar6 & 0xffff) + 1;
          pbVar8 = (byte *)(((uVar6 & 0xffff) >> 3) * 0x20 + iVar5 + iVar7 + ((uVar6 & 7) >> 1));
          if ((uVar6 & 1) == 0) {
            bVar1 = bVar1 >> 4;
          }
          else {
            bVar1 = bVar1 & 0xf0;
          }
          *pbVar8 = *pbVar8 | bVar1;
          uVar4 = ((uVar4 & 0xffff) + 1 & 0xffff) + 1;
          uVar6 = (uVar6 & 0xffff) + 1;
          local_34 = local_34 * 0x10000 + 0x20000 >> 0x10;
        } while (local_34 < (in_stack_00000008 & 0xffff));
      }
      in_stack_00000004 = (in_stack_00000004 & 0xffff) + 1;
      arg3 = (arg3 & 0xffff) + 1;
    } while (uVar3 < in_stack_0000000c);
  }
                    /* WARNING: Could not recover jumptable at 0x080ac628. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AC62C @ 0x080AC62C

void sub_080AC62C(int arg0,int arg1,uint arg2,uint arg3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  byte *pbVar9;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000000;
  uint in_stack_00000004;
  uint in_stack_00000008;
  ushort in_stack_0000000c;
  char in_stack_00000010;
  uint local_38;
  
  uVar3 = 0;
  if (in_stack_0000000c != 0) {
    do {
      local_38 = 0;
      uVar3 = uVar3 + 1;
      if ((in_stack_00000008 & 0xffff) != 0) {
        iVar4 = arg1 + ((in_stack_00000004 & 0xffff) >> 3) * 0x400;
        iVar7 = (in_stack_00000004 & 7) * 4;
        uVar6 = in_stack_00000000;
        uVar5 = arg2;
        do {
          pbVar9 = (byte *)(iVar4 + ((uVar6 & 0xffff) >> 3) * 0x20 + iVar7 + ((uVar6 & 7) >> 1));
          bVar1 = *pbVar9;
          bVar2 = *(byte *)(arg0 + ((arg3 & 0xffff) >> 3) * 0x400 + ((uVar5 & 0xffff) >> 3) * 0x20 +
                            (arg3 & 7) * 4 + ((uVar5 & 7) >> 1));
          if ((uVar6 & 1) == 0) {
            bVar8 = bVar1 | bVar2 & 0xf;
            if ((bVar1 & 0xf) != 0 || (bVar2 & 0xf) != 0) {
              bVar8 = bVar8 + in_stack_00000010;
            }
          }
          else {
            bVar8 = bVar1 | bVar2 << 4;
            if ((bVar1 & 0xf0) != 0 || (bVar2 & 0xf) != 0) {
              bVar8 = bVar8 + in_stack_00000010 * '\x10';
            }
          }
          *pbVar9 = bVar8;
          uVar6 = (uVar6 & 0xffff) + 1;
          pbVar9 = (byte *)(iVar4 + ((uVar6 & 0xffff) >> 3) * 0x20 + iVar7 + ((uVar6 & 7) >> 1));
          bVar1 = *pbVar9;
          if ((uVar6 & 1) == 0) {
            bVar8 = bVar1 | bVar2 >> 4;
            if ((bVar1 & 0xf) != 0 || bVar2 >> 4 != 0) {
              bVar8 = bVar8 + in_stack_00000010;
            }
          }
          else {
            bVar8 = bVar1 | bVar2 & 0xf0;
            if ((bVar1 & 0xf0) != 0 || (bVar2 & 0xf0) != 0) {
              bVar8 = bVar8 + in_stack_00000010 * '\x10';
            }
          }
          *pbVar9 = bVar8;
          uVar5 = ((uVar5 & 0xffff) + 1 & 0xffff) + 1;
          uVar6 = (uVar6 & 0xffff) + 1;
          local_38 = local_38 * 0x10000 + 0x20000 >> 0x10;
        } while (local_38 < (in_stack_00000008 & 0xffff));
      }
      in_stack_00000004 = (in_stack_00000004 & 0xffff) + 1;
      arg3 = (arg3 & 0xffff) + 1;
    } while (uVar3 < in_stack_0000000c);
  }
                    /* WARNING: Could not recover jumptable at 0x080ac7ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AC7CC @ 0x080AC7CC

void sub_080AC7CC(uint arg0,int arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000000;
  ushort in_stack_00000004;
  
  uVar1 = 0;
  if (in_stack_00000004 != 0) {
    do {
      uVar7 = 0;
      uVar1 = uVar1 + 1;
      if ((in_stack_00000000 & 0xffff) != 0) {
        iVar2 = arg1 + ((arg3 & 0xffff) >> 3) * 0x400;
        iVar6 = (arg3 & 7) * 4;
        uVar3 = arg2;
        do {
          pbVar5 = (byte *)(iVar2 + ((uVar3 & 0xffff) >> 3) * 0x20 + iVar6 + ((uVar3 & 7) >> 1));
          bVar4 = *pbVar5;
          if ((uVar3 & 1) == 0) {
            bVar4 = bVar4 & 0xf0 | (byte)arg0;
          }
          else {
            bVar4 = bVar4 & 0xf | (byte)((arg0 & 0xff) << 4);
          }
          *pbVar5 = bVar4;
          uVar3 = (uVar3 & 0xffff) + 1;
          pbVar5 = (byte *)(iVar2 + ((uVar3 & 0xffff) >> 3) * 0x20 + iVar6 + ((uVar3 & 7) >> 1));
          bVar4 = *pbVar5;
          if ((uVar3 & 1) == 0) {
            bVar4 = bVar4 & 0xf0 | (byte)arg0;
          }
          else {
            bVar4 = bVar4 & 0xf | (byte)((arg0 & 0xff) << 4);
          }
          *pbVar5 = bVar4;
          uVar3 = (uVar3 & 0xffff) + 1;
          uVar7 = uVar7 * 0x10000 + 0x20000 >> 0x10;
        } while (uVar7 < (in_stack_00000000 & 0xffff));
      }
      arg3 = (arg3 & 0xffff) + 1;
    } while (uVar1 < in_stack_00000004);
  }
                    /* WARNING: Could not recover jumptable at 0x080ac8ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// Font_DrawGlyph @ 0x080AC8D0

void Font_DrawGlyph(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  sub_080ABF24(arg0_00);
  sub_080AC4E4(arg0_00,arg1,2,2);
  return;
}


// Text_DrawString @ 0x080AC908

void Text_DrawString(ushort *arg0,undefined4 arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  uint arg2_00;
  uint arg3_00;
  uint in_stack_00000000;
  
  arg3_00 = arg3 & 0xffff;
  uVar1 = *arg0;
  arg2_00 = arg2 & 0xffff;
  while ((uVar1 != 0 && (uVar1 != 0x301))) {
    if (uVar1 == 0x300) {
      arg3_00 = arg3_00 + (in_stack_00000000 & 0xffff) & 0xffff;
      arg2_00 = arg2 & 0xffff;
    }
    else {
      Font_DrawGlyph((uint)*arg0,arg1,arg2_00,arg3_00);
      arg2_00 = arg2_00 + (in_stack_00000000 & 0xffff) & 0xffff;
    }
    arg0 = arg0 + 1;
    uVar1 = *arg0;
  }
  return;
}


// Font_DrawGlyphTinted @ 0x080AC980

void Font_DrawGlyphTinted(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  sub_080ABF24(arg0_00);
  sub_080AC62C(arg0_00,arg1,2,2);
  return;
}


// Text_DrawStringTinted @ 0x080AC9C8

void Text_DrawStringTinted(ushort *arg0,undefined4 arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  uint arg2_00;
  uint arg3_00;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000004;
  
  arg3_00 = arg3 & 0xffff;
  arg2_00 = arg2 & 0xffff;
  while ((uVar1 = *arg0, uVar1 != 0 && (uVar1 != 0x301))) {
    if (uVar1 == 0x300) {
      arg3_00 = arg3_00 + (in_stack_00000004 & 0xffff) & 0xffff;
      arg0 = arg0 + 1;
      arg2_00 = arg2 & 0xffff;
    }
    else {
      Font_DrawGlyphTinted((uint)*arg0,arg1,arg2_00,arg3_00);
      arg0 = arg0 + 1;
      arg2_00 = arg2_00 + (in_stack_00000004 & 0xffff) & 0xffff;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080aca3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080ACA40 @ 0x080ACA40

void sub_080ACA40(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  sub_080AC4E4((arg0 & 0xffff) * 0x20 + 0x81ad7b8,arg1,0,0);
  return;
}


// sub_080ACA74 @ 0x080ACA74

void sub_080ACA74(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  sub_080AC62C((arg0 & 0xffff) * 0x20 + 0x81ad7b8,arg1,0,0);
  return;
}


// sub_080ACAB0 @ 0x080ACAB0

void sub_080ACAB0(byte *arg0,undefined4 arg1,uint arg2,uint arg3)

{
  byte bVar1;
  uint arg2_00;
  uint in_stack_00000004;
  
  bVar1 = *arg0;
  while (bVar1 != 0) {
    arg2_00 = arg2 & 0xffff;
    if (bVar1 == 0x2d) {
      sub_080ACA74(6,arg1,arg2_00,arg3 & 0xffff);
    }
    else {
      sub_080ACA74((uint)*(ushort *)((*arg0 - 0x20) * 2 + 0x815ee20),arg1,arg2_00,arg3 & 0xffff);
    }
    arg0 = arg0 + 1;
    arg2 = arg2_00 + (in_stack_00000004 & 0xffff);
    bVar1 = *arg0;
  }
  return;
}


// sub_080ACB30 @ 0x080ACB30

void sub_080ACB30(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  sub_080AC4E4(&UNK_081ae3b8 + ((arg0 & 0xffff) >> 5) * 0x800 + (arg0 & 0x1f) * 0x20,arg1,0,6);
  return;
}


// sub_080ACB78 @ 0x080ACB78

void sub_080ACB78(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  sub_080AC62C(&UNK_081ae3b8 + ((arg0 & 0xffff) >> 5) * 0x800 + (arg0 & 0x1f) * 0x20,arg1,0,6);
  return;
}


// sub_080ACBC8 @ 0x080ACBC8

void sub_080ACBC8(byte *arg0,undefined4 arg1,uint arg2,uint arg3)

{
  byte bVar1;
  uint in_stack_00000004;
  
  bVar1 = *arg0;
  while (bVar1 != 0) {
    sub_080ACB78((uint)*(ushort *)((*arg0 - 0x30) * 2 + 0x815ee96),arg1,arg2 & 0xffff,arg3 & 0xffff)
    ;
    arg0 = arg0 + 1;
    arg2 = (arg2 & 0xffff) + (in_stack_00000004 & 0xffff);
    bVar1 = *arg0;
  }
  return;
}


// sub_080ACC30 @ 0x080ACC30

void sub_080ACC30(void)

{
  if ((DAT_03003970 != '\x01') && (DAT_030031d0 == 0xf)) {
    SoftReset();
  }
  return;
}


// sub_080ACC54 @ 0x080ACC54

undefined4 sub_080ACC54(uint arg0)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar8 = arg0 & 0xffff;
  uVar11 = 0;
  uVar10 = 0;
  uVar12 = 0;
  uVar5 = 0;
  if ((uVar8 == 0) || (uVar2 = sub_080C2C70(), uVar5 = uVar8, (uVar2 & 0xffff) == 0))
  goto LAB_080acf94;
  uVar2 = sub_080C2C70();
  uVar1 = DAT_03006080;
  if ((uVar2 & 0xffff) != 1) {
    if (DAT_03006086 == 0) goto LAB_080acf94;
    uVar10 = arg0 & 0x1f;
    uVar12 = (arg0 & 0x3e0) >> 5;
    uVar8 = (arg0 & 0x7c00) >> 10;
    uVar11 = uVar10;
    if (uVar10 <= uVar12) {
      uVar11 = uVar12;
    }
    if (uVar11 <= uVar8) {
      uVar11 = uVar8;
    }
    uVar2 = 0xffff;
    if (uVar10 < 0x10000) {
      uVar2 = uVar10;
    }
    if (uVar12 <= uVar2) {
      uVar2 = uVar12;
    }
    if (uVar8 <= uVar2) {
      uVar2 = uVar8;
    }
    uVar3 = __divsi3(((int)(uVar11 - uVar2) / 2) * (int)DAT_03006086,100);
    uVar3 = uVar3 & 0xffff;
    if (uVar3 == 0) goto LAB_080acf94;
    if ((uVar10 == uVar11) || (uVar10 != uVar2)) {
      if (uVar10 < uVar3) {
        uVar10 = 0;
      }
      else {
        uVar10 = uVar10 - uVar3;
LAB_080acf30:
        uVar10 = uVar10 & 0xffff;
      }
    }
    else {
      uVar10 = uVar10 + uVar3;
      if (uVar10 < 0x20) goto LAB_080acf30;
      uVar10 = 0x1f;
    }
    if ((uVar12 == uVar11) || (uVar12 != uVar2)) {
      if (uVar12 < uVar3) {
        uVar12 = 0;
      }
      else {
        uVar12 = uVar12 - uVar3;
LAB_080acf56:
        uVar12 = uVar12 & 0xffff;
      }
    }
    else {
      uVar12 = uVar12 + uVar3;
      if (uVar12 < 0x20) goto LAB_080acf56;
      uVar12 = 0x1f;
    }
    if ((uVar8 == uVar11) || (uVar8 != uVar2)) {
      if (uVar8 < uVar3) {
        uVar8 = 0;
      }
      else {
        uVar8 = uVar8 - uVar3;
LAB_080acf7c:
        uVar8 = uVar8 & 0xffff;
      }
    }
    else {
      uVar8 = uVar8 + uVar3;
      if (uVar8 < 0x20) goto LAB_080acf7c;
      uVar8 = 0x1f;
    }
    uVar5 = uVar10 + uVar12 * 0x20 + uVar8 * 0x400 & 0xffff;
    goto LAB_080acf94;
  }
  uVar5 = (uint)DAT_03006082;
  uVar2 = (uint)DAT_03006084;
  uVar3 = (arg0 & 0x3e0) >> 5;
  uVar9 = (arg0 & 0x7c00) >> 10;
  if ((short)DAT_03006080 < 1) {
    if ((short)DAT_03006080 < 0) {
      uVar11 = __divsi3((arg0 & 0x1f) * 0x10000 * (-(uint)DAT_03006080 & 0xffff),0x1f00);
      uVar11 = (uVar11 & 0xffff) * 0x100 + 0x8000 >> 0x10;
    }
  }
  else {
    uVar11 = __divsi3((uint)DAT_03006080 * (0x1f - (arg0 & 0x1f)) * 0x10000,0x1f00);
    uVar11 = (uVar11 & 0xffff) + 0x80 >> 8;
  }
  iVar6 = (int)(uVar5 * 0x10000) >> 0x10;
  if (iVar6 < 1) {
    if (iVar6 < 0) {
      uVar10 = __divsi3(uVar3 * 0x10000 * (-(uint)DAT_03006082 & 0xffff),0x1f00);
      goto LAB_080acd66;
    }
  }
  else {
    uVar10 = __divsi3((0x1f - uVar3) * 0x10000 * (uint)DAT_03006082,0x1f00);
LAB_080acd66:
    uVar10 = ((uVar10 & 0xffff) * 0x100 + 0x8000 >> 0x10) << 5;
  }
  iVar7 = (int)(uVar2 * 0x10000) >> 0x10;
  if (iVar7 < 1) {
    if (iVar7 < 0) {
      uVar12 = __divsi3(uVar9 * 0x10000 * (-(uint)DAT_03006084 & 0xffff),0x1f00);
      goto LAB_080acdce;
    }
  }
  else {
    uVar12 = __divsi3((0x1f - uVar9) * 0x10000 * (uint)DAT_03006084,0x1f00);
LAB_080acdce:
    uVar12 = ((uVar12 & 0xffff) * 0x100 + 0x8000 >> 0x10 & 0x3f) << 10;
  }
  uVar5 = arg0 & 0x1f;
  if (uVar5 != 0) {
    if ((short)uVar1 < 1) {
      if ((short)uVar1 < 0) {
        if (uVar11 < uVar5) {
          uVar11 = -uVar11;
          goto LAB_080ace0a;
        }
        uVar8 = arg0 & 0xffe0;
      }
    }
    else if (uVar5 + uVar11 < 0x1f) {
LAB_080ace0a:
      uVar8 = uVar8 + uVar11 & 0xffff;
    }
    else {
      uVar8 = uVar8 | 0x1f;
    }
  }
  uVar11 = uVar8 & 0x3e0;
  if (uVar11 != 0) {
    if (iVar6 < 1) {
      if (iVar6 < 0) {
        if (uVar10 < uVar11) {
          uVar10 = -uVar10;
          goto LAB_080ace4c;
        }
        uVar8 = uVar8 & 0xfc1f;
      }
    }
    else if (uVar11 + uVar10 < 0x3e0) {
LAB_080ace4c:
      uVar8 = uVar8 + uVar10 & 0xffff;
    }
    else {
      uVar8 = uVar8 | 0x3e0;
    }
  }
  uVar11 = uVar8 & 0x7c00;
  uVar5 = uVar8;
  if (uVar11 == 0) goto LAB_080acf94;
  if (iVar7 < 1) {
    if (-1 < iVar7) goto LAB_080acf94;
    if (uVar11 <= uVar12) {
      uVar5 = uVar8 & 0x83ff;
      goto LAB_080acf94;
    }
    uVar12 = -uVar12;
  }
  else if (0x7bff < uVar11 + uVar12) {
    uVar5 = uVar8 | 0x7c00;
    goto LAB_080acf94;
  }
  uVar5 = uVar8 + uVar12 & 0xffff;
LAB_080acf94:
                    /* WARNING: Could not recover jumptable at 0x080acfa2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar5);
  return uVar4;
}


// sub_080ACFA4 @ 0x080ACFA4

void sub_080ACFA4(undefined4 arg0,uint arg1,undefined2 *arg2,uint arg3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (arg3 >> 1 != 0) {
    do {
      uVar1 = sub_080ACC54(arg1 & 0xffff);
      *arg2 = (short)uVar1;
      arg2 = arg2 + 1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < arg3 >> 1);
  }
  return;
}


// sub_080ACFCC @ 0x080ACFCC

void sub_080ACFCC(undefined4 arg0,ushort *arg1,undefined2 *arg2,uint arg3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (arg3 >> 1 != 0) {
    do {
      uVar1 = sub_080ACC54((uint)*arg1);
      *arg2 = (short)uVar1;
      arg2 = arg2 + 1;
      arg1 = arg1 + 1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < arg3 >> 1);
  }
  return;
}


// sub_080ACFF4 @ 0x080ACFF4

void sub_080ACFF4(void)

{
  undefined4 uVar1;
  undefined1 local_4 [4];
  
  REG_DMA3SAD = local_4;
  REG_DMA3DAD = 0x2009004;
  REG_DMA3CNT = 0x85000640;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080AD01C @ 0x080AD01C

void sub_080AD01C(void)

{
  int iVar1;
  dword *pdVar2;
  uint uVar3;
  dword dVar4;
  short *arg0;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = 0;
  do {
    arg0 = (short *)(uVar3 * 100 + 0x2009004);
    uVar5 = uVar3 + 1;
    if ((*arg0 != 0) && (iVar1 = sub_080AD15C(arg0), iVar1 == 0)) {
      do {
        if ((&DAT_02009010)[uVar3 * 0x19] == 0) {
          iVar1 = (&DAT_02009014)[uVar3 * 0x19];
          pdVar2 = (dword *)((&DAT_02009018)[uVar3 * 0x19] + iVar1 * 4);
          dVar4 = *pdVar2;
          DAT_03003b84 = pdVar2 + 1;
          (&DAT_0200900c)[uVar3 * 0x19] = dVar4;
          (&DAT_02009014)[uVar3 * 0x19] = iVar1 + 1;
          if (dVar4 == 0x10241224) {
            (&DAT_02009014)[uVar3 * 0x19] = iVar1 + 2;
          }
          else {
            _call_via_r1(arg0,*(undefined4 *)(dVar4 * 8 + 0x815eeec));
          }
        }
        else {
          DAT_03003b84 = (dword *)((&DAT_02009018)[uVar3 * 0x19] + (&DAT_02009014)[uVar3 * 0x19] * 4
                                  );
          _call_via_r1(arg0,*(undefined4 *)(&DAT_0815eef0 + (&DAT_0200900c)[uVar3 * 0x19] * 8));
        }
      } while (((&DAT_02009010)[uVar3 * 0x19] == 0) && (*arg0 != 0));
      if ((*arg0 != 0) && ((&DAT_02009024)[uVar3 * 0x19] != 0)) {
        _call_via_r1(arg0,(&DAT_02009024)[uVar3 * 0x19]);
      }
    }
    uVar3 = uVar5;
  } while (uVar5 < 0x40);
                    /* WARNING: Could not recover jumptable at 0x080ad0d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080AD0D4 @ 0x080AD0D4

undefined4 sub_080AD0D4(void)

{
  uint uVar1;
  short *psVar2;
  
  uVar1 = 1;
  psVar2 = &DAT_02009068;
  do {
    if (*psVar2 == 0) {
      return uVar1;
    }
    psVar2 = psVar2 + 0x32;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x40);
  return 0xffffffff;
}


// sub_080AD0FC @ 0x080AD0FC

undefined2 * sub_080AD0FC(undefined4 arg0,undefined4 arg1)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined1 local_10 [4];
  
  iVar2 = sub_080AD0D4();
  if (iVar2 == -1) {
    puVar3 = (undefined2 *)0x0;
  }
  else {
    puVar3 = (undefined2 *)(iVar2 * 100 + 0x2009004);
    REG_DMA3SAD = local_10;
    REG_DMA3DAD = puVar3;
    REG_DMA3CNT = 0x85000019;
    uVar1 = REG_DMA3CNT;
    (&DAT_02009018)[iVar2 * 0x19] = arg0;
    *(short *)(&DAT_02009006 + iVar2 * 100) = (short)iVar2;
    (&DAT_02009008)[iVar2 * 0x32] = (undefined2)arg1;
    *puVar3 = 1;
  }
  return puVar3;
}


// sub_080AD150 @ 0x080AD150

void sub_080AD150(undefined2 *arg0)

{
  *arg0 = 0xffff;
  return;
}


// sub_080AD15C @ 0x080AD15C

uint sub_080AD15C(short *arg0)

{
  return (uint)(*arg0 == -1);
}


// sub_080AD174 @ 0x080AD174

void sub_080AD174(undefined2 *arg0)

{
  *arg0 = 1;
  return;
}


// sub_080AD17C @ 0x080AD17C

void sub_080AD17C(int arg0)

{
  *(undefined4 *)(arg0 + 0xc) = *DAT_03003b84;
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 1;
  return;
}


// sub_080AD190 @ 0x080AD190

void sub_080AD190(int arg0)

{
  if (*(int *)(arg0 + 0xc) != -1) {
    *(int *)(arg0 + 0xc) = *(int *)(arg0 + 0xc) + -1;
  }
  return;
}


// sub_080AD1A8 @ 0x080AD1A8

void sub_080AD1A8(int arg0,dword arg1)

{
  dword *pdVar1;
  dword dVar2;
  dword *pdVar3;
  
  *(undefined4 *)(arg0 + 0x10) = 0;
  pdVar3 = *(dword **)(arg0 + 0x14);
  dVar2 = *pdVar3;
  DAT_03003b84 = pdVar3;
  while ((pdVar1 = DAT_03003b84, dVar2 != 0x10241224 || (arg1 != pdVar3[1]))) {
    pdVar3 = DAT_03003b84 + 1;
    DAT_03003b84 = pdVar3;
    *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 1;
    dVar2 = pdVar1[1];
  }
  return;
}


// sub_080AD1E4 @ 0x080AD1E4

void sub_080AD1E4(void)

{
  undefined4 in_r0;
  
  sub_080AD1A8(in_r0,*DAT_03003b84);
  return;
}


// sub_080AD1F8 @ 0x080AD1F8

void sub_080AD1F8(void)

{
  return;
}


// sub_080AD1FC @ 0x080AD1FC

void sub_080AD1FC(undefined2 *arg0)

{
  if (arg0 != (undefined2 *)0x0) {
    *arg0 = 0;
  }
  return;
}


// sub_080AD20C @ 0x080AD20C

uint sub_080AD20C(ushort *arg0)

{
  return (uint)*arg0;
}


// sub_080AD210 @ 0x080AD210

void sub_080AD210(undefined4 arg0,int arg1)

{
  short *arg0_00;
  
  arg0_00 = (short *)(arg1 * 100 + 0x2009004);
  if (*arg0_00 != 0) {
    sub_080AD1FC(arg0_00);
  }
  return;
}


// sub_080AD230 @ 0x080AD230

void sub_080AD230(short *arg0)

{
  short *arg0_00;
  int iVar1;
  
  iVar1 = 0;
  do {
    arg0_00 = (short *)(iVar1 * 100 + 0x2009004);
    if ((*arg0_00 != 0) && (arg0_00 != arg0)) {
      sub_080AD1FC(arg0_00);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x40);
  return;
}


// sub_080AD260 @ 0x080AD260

void sub_080AD260(short *arg0)

{
  short *arg0_00;
  int iVar1;
  
  iVar1 = 0;
  do {
    arg0_00 = (short *)(iVar1 * 100 + 0x2009004);
    if (((*arg0_00 != 0) && (arg0_00 != arg0)) && ((&DAT_02009008)[iVar1 * 0x32] == arg0[1])) {
      sub_080AD1FC(arg0_00);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x40);
  return;
}


// sub_080AD298 @ 0x080AD298

void sub_080AD298(void)

{
  undefined4 in_r0;
  
  sub_080AD1FC(in_r0);
  return;
}


// sub_080AD2A4 @ 0x080AD2A4

void sub_080AD2A4(void)

{
  return;
}


// sub_080AD2A8 @ 0x080AD2A8

void sub_080AD2A8(int arg0)

{
  int iVar1;
  
  *(short *)(arg0 + 0x18) = (short)*DAT_03003b84;
  iVar1 = *(int *)(arg0 + 0x10) + 1;
  *(int *)(arg0 + 0x10) = iVar1;
  *(short *)(arg0 + 0x1a) = (short)iVar1;
  return;
}


// sub_080AD2C0 @ 0x080AD2C0

void sub_080AD2C0(void)

{
  return;
}


// sub_080AD2C4 @ 0x080AD2C4

void sub_080AD2C4(int arg0)

{
  short sVar1;
  
  sVar1 = *(short *)(arg0 + 0x18) + -1;
  *(short *)(arg0 + 0x18) = sVar1;
  if (sVar1 != 0) {
    *(uint *)(arg0 + 0x10) = (uint)*(ushort *)(arg0 + 0x1a);
  }
  return;
}


// sub_080AD2DC @ 0x080AD2DC

void sub_080AD2DC(void)

{
  return;
}


// sub_080AD2E0 @ 0x080AD2E0

void sub_080AD2E0(void)

{
  return;
}


// sub_080AD2E4 @ 0x080AD2E4

void sub_080AD2E4(void)

{
  return;
}


// sub_080AD2E8 @ 0x080AD2E8

void sub_080AD2E8(void)

{
  return;
}


// sub_080AD2EC @ 0x080AD2EC

void sub_080AD2EC(void)

{
  return;
}


// sub_080AD2F0 @ 0x080AD2F0

void sub_080AD2F0(int arg0)

{
  if (*(short *)(arg0 + 0x1c) == 0) {
    *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 1;
  }
  else {
    sub_080AD1A8(arg0,*DAT_03003b84);
  }
  return;
}


// sub_080AD318 @ 0x080AD318

void sub_080AD318(void)

{
  return;
}


// sub_080AD31C @ 0x080AD31C

void sub_080AD31C(int arg0)

{
  if (*(short *)(arg0 + 0x1c) == 0) {
    sub_080AD1A8(arg0,*DAT_03003b84);
  }
  else {
    *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 1;
  }
  return;
}


// sub_080AD344 @ 0x080AD344

void sub_080AD344(void)

{
  return;
}


// sub_080AD348 @ 0x080AD348

void sub_080AD348(short *arg0)

{
  if ((*arg0 != 0) && (*(int *)(arg0 + 6) == -1)) {
    arg0[6] = 1;
    arg0[7] = 0;
  }
  return;
}


// sub_080AD364 @ 0x080AD364

int sub_080AD364(int arg0)

{
  return (uint)*(ushort *)(arg0 + 4) * 100 + 0x2009004;
}


// sub_080AD374 @ 0x080AD374

void sub_080AD374(void)

{
  undefined4 in_r0;
  undefined4 arg0;
  
  arg0 = sub_080AD364(in_r0);
  sub_080AD348(arg0);
  return;
}


// sub_080AD384 @ 0x080AD384

void sub_080AD384(void)

{
  return;
}


// sub_080AD388 @ 0x080AD388

void sub_080AD388(int arg0)

{
  int arg1;
  undefined4 arg3;
  
  arg3 = *DAT_03003b84;
  DAT_03003b84 = DAT_03003b84 + 1;
  arg1 = *(int *)(arg0 + 0x10) + 1;
  *(int *)(arg0 + 0x10) = arg1;
  _call_via_r3(arg0,arg1,0x3003b84,arg3);
  return;
}


// sub_080AD3A4 @ 0x080AD3A4

void sub_080AD3A4(void)

{
  return;
}


// sub_080AD3A8 @ 0x080AD3A8

void sub_080AD3A8(int arg0)

{
  undefined4 arg3;
  undefined4 *arg2;
  
  arg3 = *DAT_03003b84;
  arg2 = DAT_03003b84 + 1;
  DAT_03003b84 = arg2;
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 2;
  _call_via_r3(arg0,*arg2,arg2,arg3);
  return;
}


// sub_080AD3C8 @ 0x080AD3C8

void sub_080AD3C8(void)

{
  return;
}


// sub_080AD3CC @ 0x080AD3CC

void sub_080AD3CC(int arg0)

{
  undefined4 *puVar1;
  undefined4 arg3;
  undefined4 *puVar2;
  
  puVar1 = DAT_03003b84;
  arg3 = *DAT_03003b84;
  puVar2 = DAT_03003b84 + 1;
  DAT_03003b84 = puVar2;
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 3;
  _call_via_r3(arg0,*puVar2,puVar1[2],arg3);
  return;
}


// sub_080AD3EC @ 0x080AD3EC

void sub_080AD3EC(void)

{
  return;
}


// sub_080AD3F0 @ 0x080AD3F0

void sub_080AD3F0(int arg0)

{
  DAT_03003b84 = DAT_03003b84 + 4;
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 4;
  _call_via_r4();
  return;
}


// sub_080AD414 @ 0x080AD414

void sub_080AD414(void)

{
  return;
}


// sub_080AD418 @ 0x080AD418

void sub_080AD418(int arg0)

{
  DAT_03003b84 = DAT_03003b84 + 4;
  *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0x10) + 5;
  _call_via_r5();
  return;
}


