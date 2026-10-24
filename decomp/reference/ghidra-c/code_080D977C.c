/* Ghidra decompilation of asm/code_080D977C.s (reference only; not compiled). */

// sub_080D977C @ 0x080D977C

void sub_080D977C(void)

{
  if (DAT_0300609c == 0) {
    Font_ResetGlyphSpriteCache(0x180);
  }
  sub_080BDB58();
  sub_080AD01C();
  return;
}


// sub_080D97A0 @ 0x080D97A0

void sub_080D97A0(undefined4 arg0,undefined4 arg1,int arg2)

{
  int arg1_00;
  
  arg1_00 = arg2 + 0x2001000;
  HuffUnComp(arg1,0x200afc8,arg2);
  LZ77UnCompWram(0x200afc8,arg1_00,arg2);
  return;
}


// sub_080D97C8 @ 0x080D97C8

void sub_080D97C8(undefined4 arg0,undefined4 arg1)

{
  DisplayList_Add(arg1,1);
  return;
}


// sub_080D97D8 @ 0x080D97D8

void sub_080D97D8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6004040;
  REG_DMA3CNT = 0x840007f0;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D97FC @ 0x080D97FC

void sub_080D97FC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2002fc0;
  REG_DMA3DAD = 0x6008040;
  REG_DMA3CNT = 0x84000ed0;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D9824 @ 0x080D9824

void sub_080D9824(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2002fc0;
  REG_DMA3DAD = 0x6008040;
  REG_DMA3CNT = 0x84000370;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2005000;
  REG_DMA3DAD = 0x6008e00;
  REG_DMA3CNT = 0x84000b60;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D9868 @ 0x080D9868

void sub_080D9868(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6003040;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D988C @ 0x080D988C

void sub_080D988C(undefined4 arg0,undefined4 arg1,byte *arg2)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  short *psVar4;
  uint uVar5;
  uint uVar6;
  
  REG_DMA3SAD = arg1;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x84000400;
  uVar2 = REG_DMA3CNT;
  uVar3 = 0;
  do {
    uVar5 = 0;
    uVar6 = uVar3 + 1;
    psVar4 = &DAT_02000002 + uVar3 * 0x20;
    do {
      bVar1 = *arg2;
      arg2 = arg2 + 1;
      *psVar4 = ((bVar1 & 0xf) + 8) * 0x1000 + *psVar4;
      psVar4 = psVar4 + 1;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x1c);
    uVar3 = uVar6;
  } while (uVar6 < 0x1a);
  DisplayList_Add(0x80d9869,1);
  return;
}


// sub_080D98EC @ 0x080D98EC

void sub_080D98EC(undefined4 arg0,undefined4 arg1,byte *arg2)

{
  byte bVar1;
  undefined4 uVar2;
  short sVar3;
  uint uVar4;
  short *psVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  
  REG_DMA3SAD = arg1;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x84000400;
  uVar2 = REG_DMA3CNT;
  uVar4 = 0;
  do {
    uVar7 = 0;
    uVar8 = uVar4 + 1;
    psVar5 = &DAT_02000002 + uVar4 * 0x20;
    psVar6 = (short *)((uVar4 * 0x20 + 0x1c) * 2 + 0x2000000);
    do {
      bVar1 = *arg2;
      arg2 = arg2 + 1;
      sVar3 = ((bVar1 & 0xf) + 8) * 0x1000;
      *psVar5 = *psVar5 + sVar3;
      *psVar6 = *psVar6 + sVar3;
      psVar6 = psVar6 + -1;
      psVar5 = psVar5 + 1;
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0xe);
    uVar4 = uVar8;
  } while (uVar8 < 0x1a);
  DisplayList_Add(0x80d9869,1);
  return;
}


// sub_080D9968 @ 0x080D9968

void sub_080D9968(void)

{
  undefined4 in_r1;
  
  sub_080ACFCC(3,in_r1,0x3002ab0,0x100);
  return;
}


// sub_080D9988 @ 0x080D9988

void sub_080D9988(void)

{
  sub_080AB090(0x80,0x80,1,0x8001);
  return;
}


// sub_080D99A0 @ 0x080D99A0

void sub_080D99A0(void)

{
  sub_080AB158(0x80,0x80,1,0x8001);
  return;
}


// sub_080D99B8 @ 0x080D99B8

void sub_080D99B8(void)

{
  sub_080ACFCC(3,0x81b6c30,0x3002bb0,0x100);
  sub_080ACFCC(3,0x8580a60,&DAT_03002c90,0x20);
  sub_080AAFBC(0x80,0x180,1);
  return;
}


// sub_080D9A00 @ 0x080D9A00

void sub_080D9A00(void)

{
  sub_080AB0F0(0x80,0x180,1);
  return;
}


// sub_080D9A14 @ 0x080D9A14

void sub_080D9A14(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2024074;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D9A38 @ 0x080D9A38

void sub_080D9A38(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2006000;
  REG_DMA3DAD = 0x6010000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D9A5C @ 0x080D9A5C

void sub_080D9A5C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x8573af4;
  REG_DMA3DAD = 0x6012000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D9A80 @ 0x080D9A80

void sub_080D9A80(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x600bc00;
  REG_DMA3CNT = 0x84001100;
  uVar1 = REG_DMA3CNT;
  sub_080D9A14();
  sub_080D9A38();
  sub_080D9A5C();
  return;
}


// sub_080D9AB4 @ 0x080D9AB4

void sub_080D9AB4(void)

{
  undefined4 uVar1;
  
  sub_080ACFCC(3,0x8580880,0x30029b0,0x20);
  sub_080ACFCC(3,0x81b6c30,&DAT_03002bb0,0x100);
  sub_080ACFCC(3,0x8580a60,&DAT_03002c90,0x20);
  DAT_03002db0 = 0;
  DAT_030029b0 = 0;
  REG_DMA3SAD = 0x857d9c0;
  REG_DMA3DAD = 0x2024074;
  REG_DMA3CNT = 0x84000140;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D9B34 @ 0x080D9B34

void sub_080D9B34(void)

{
  sub_080AB438(0,0x2024074,1,1);
  DisplayList_Add(0x80d9a15,1);
  return;
}


// sub_080D9B64 @ 0x080D9B64

void sub_080D9B64(int arg0)

{
  sub_080AA184(*(undefined4 *)(arg0 + 0x3c),0,7,0);
  sub_080AA184(*(undefined4 *)(arg0 + 0x38),0,7,0);
  return;
}


// sub_080D9BAC @ 0x080D9BAC

void sub_080D9BAC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2024074;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D9BD0 @ 0x080D9BD0

void sub_080D9BD0(int arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined4 in_stack_00000000;
  undefined4 in_stack_00000004;
  undefined2 in_stack_00000008;
  
  sub_080AB250(arg1,0x2024074,0,0);
  DisplayList_Add(0x80d9bad,1);
  *(dword *)(arg0 + 0x20) = 0x80d9b65;
  *(undefined2 *)(arg0 + 0x24) = in_stack_00000008;
  *(undefined4 *)(arg0 + 0x38) = in_stack_00000000;
  *(undefined4 *)(arg0 + 0x3c) = in_stack_00000004;
  return;
}


// sub_080D9C24 @ 0x080D9C24

void sub_080D9C24(int arg0)

{
  uint uVar1;
  
  sub_080AA184(*(undefined4 *)(arg0 + 0x3c),0,7,0);
  uVar1 = 0;
  if (*(char *)(arg0 + 0x4f) != '\0') {
    do {
      sub_080AA184(*(undefined4 *)(uVar1 * 4 + 0x85814a0),0,7,0);
      sub_080AA184(*(undefined4 *)((*(byte *)(arg0 + 0x48 + uVar1) - 1) * 4 + 0x85814b4),0,7,0);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(byte *)(arg0 + 0x4f));
  }
  return;
}


// sub_080D9CD0 @ 0x080D9CD0

void sub_080D9CD0(int arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined4 in_stack_00000000;
  undefined4 in_stack_00000004;
  undefined2 in_stack_00000008;
  
  sub_080AB250(arg1,0x2024074,0,0);
  DisplayList_Add(0x80d9bad,1);
  *(dword *)(arg0 + 0x20) = 0x80d9c25;
  *(undefined2 *)(arg0 + 0x24) = in_stack_00000008;
  *(undefined4 *)(arg0 + 0x38) = in_stack_00000000;
  *(undefined4 *)(arg0 + 0x3c) = in_stack_00000004;
  return;
}


// sub_080D9D24 @ 0x080D9D24

void sub_080D9D24(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x201d874;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080D9D48 @ 0x080D9D48

void sub_080D9D48(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  sub_080AB250(arg1,0x201d874,0,0);
  DisplayList_Add(0x80d9d25,1);
  return;
}


// sub_080D9D8C @ 0x080D9D8C

void sub_080D9D8C(void)

{
  sub_080AB438(0,0x201d874,1,1);
  DisplayList_Add(0x80d9d25,1);
  return;
}


// sub_080D9DBC @ 0x080D9DBC

void sub_080D9DBC(undefined4 arg0,uint arg1,uint arg2,undefined4 arg3)

{
  sub_080AB438(0,0x201d874,arg1 & 0xffff,arg2 & 0xffff);
  DisplayList_Add(0x80d9d25,1);
  return;
}


// sub_080D9E00 @ 0x080D9E00

void sub_080D9E00(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  DAT_03000030 = (undefined1)arg2;
  DAT_03000031 = (undefined1)arg1;
  DAT_03000034 = 0x58;
  DAT_03000035 = 8;
  DAT_03000038 = 0x2b;
  return;
}


// sub_080D9E30 @ 0x080D9E30

void sub_080D9E30(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  DAT_03000030 = (undefined1)arg2;
  DAT_03000031 = (undefined1)arg1;
  DAT_03000034 = 0x58;
  DAT_03000035 = 0x58;
  DAT_03000038 = 0x2b;
  return;
}


// sub_080D9E60 @ 0x080D9E60

void sub_080D9E60(undefined4 arg0,undefined4 arg1)

{
  DAT_03000035 = DAT_03000035 + (char)arg1;
  return;
}


// sub_080D9E70 @ 0x080D9E70

void sub_080D9E70(void)

{
  DAT_03000030 = 0xe8;
  DAT_03000031 = 8;
  DAT_03000034 = 0x98;
  DAT_03000035 = 8;
  DAT_03000038 = 0x29;
  return;
}


// sub_080D9EA4 @ 0x080D9EA4

void sub_080D9EA4(void)

{
  DAT_03000030 = 0xe8;
  DAT_03000031 = 8;
  DAT_03000034 = 0x98;
  DAT_03000035 = 0x98;
  DAT_03000038 = 0x29;
  return;
}


// sub_080D9ED8 @ 0x080D9ED8

void sub_080D9ED8(undefined4 arg0,undefined4 arg1)

{
  DAT_03000035 = DAT_03000035 + (char)arg1;
  return;
}


// sub_080D9EE8 @ 0x080D9EE8

void sub_080D9EE8(int arg0)

{
  int iVar1;
  
  if (*(int *)(arg0 + 0x40) == 0) {
    iVar1 = sub_080AB7D4(2,0xc,0x1a,6);
    *(int *)(arg0 + 0x40) = iVar1;
    *(undefined2 *)(iVar1 + 4) = *(undefined2 *)(arg0 + 2);
  }
  return;
}


// sub_080D9F14 @ 0x080D9F14

void sub_080D9F14(int arg0)

{
  int iVar1;
  
  if (*(int *)(arg0 + 0x40) == 0) {
    iVar1 = sub_080AB860(2,0xc,0x1a,6);
    *(int *)(arg0 + 0x40) = iVar1;
    *(undefined2 *)(iVar1 + 4) = *(undefined2 *)(arg0 + 2);
  }
  return;
}


// sub_080D9F40 @ 0x080D9F40

void sub_080D9F40(int arg0)

{
  int arg0_00;
  undefined4 in_r1;
  
  arg0_00 = *(int *)(arg0 + 0x40);
  if (arg0_00 != 0) {
    *(undefined4 *)(arg0_00 + 0x20) = 0;
    sub_080AB91C(arg0_00,in_r1);
    *(undefined4 *)(arg0 + 0x40) = 0;
  }
  return;
}


// sub_080D9F5C @ 0x080D9F5C

void sub_080D9F5C(int arg0)

{
  if (*(int *)(arg0 + 0x40) != 0) {
    *(undefined4 *)(*(int *)(arg0 + 0x40) + 0x20) = 0;
  }
  return;
}


// sub_080D9F6C @ 0x080D9F6C

void sub_080D9F6C(int arg0,undefined4 arg1)

{
  if (*(int *)(arg0 + 0x40) != 0) {
    *(undefined4 *)(*(int *)(arg0 + 0x40) + 0x20) = arg1;
  }
  return;
}


// sub_080D9F7C @ 0x080D9F7C

void sub_080D9F7C(int arg0)

{
  sub_080AA184(*(undefined4 *)(arg0 + 0x28),0,7,0);
  sub_080AA184(0x80083dc,0,7,0);
  if (*(dword *)(arg0 + 0x2c) == 0x80083c4) {
    sub_080AA184(0x80083c4,0,7,0);
  }
  else {
    sub_080AA184(*(dword *)(arg0 + 0x2c),0,7,0);
  }
  return;
}


// sub_080DA00C @ 0x080DA00C

void sub_080DA00C(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0xc0) == 0) {
        return;
      }
      *(ushort *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + 1U & 1;
      sub_080C51D4(100);
      return;
    }
    DAT_030031cc = 1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else {
    DAT_030031cc = (uint)*(ushort *)(arg0 + 0x24);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if (*(ushort *)(arg0 + 0x24) == 0) {
      sub_080C51D4(0x65);
      return;
    }
  }
  sub_080C51D4(0x66);
  return;
}


// sub_080DA084 @ 0x080DA084

void sub_080DA084(int arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x8581568,(uint)*(ushort *)(arg0 + 2));
  *(undefined4 *)(iVar1 + 0x28) = arg1;
  *(undefined4 *)(iVar1 + 0x2c) = arg2;
  return;
}


// sub_080DA0A4 @ 0x080DA0A4

void sub_080DA0A4(int arg0)

{
  *(short *)(arg0 + 0x1e) = (short)DAT_030031cc;
  return;
}


// sub_080DA0B0 @ 0x080DA0B0

void sub_080DA0B0(int arg0)

{
  byte bVar1;
  ushort uVar2;
  undefined4 arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  bVar1 = *(byte *)(arg0 + 0x4f);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) != 0) {
          if ((uint)*(ushort *)(arg0 + 0x24) == bVar1 - 1) {
            *(ushort *)(arg0 + 0x24) = DAT_03003964 & 0x40;
          }
          else {
            *(ushort *)(arg0 + 0x24) = *(ushort *)(arg0 + 0x24) + 1;
          }
          sub_080C51D4(100);
        }
      }
      else {
        uVar2 = *(ushort *)(arg0 + 0x24);
        if (uVar2 == 0) {
          uVar2 = (ushort)bVar1;
        }
        *(ushort *)(arg0 + 0x24) = uVar2 - 1;
        sub_080C51D4(100);
      }
      goto LAB_080da14a;
    }
    *(ushort *)(arg0 + 0x24) = *(byte *)(arg0 + 0x4f) - 1;
    *(undefined2 *)(arg0 + 0x1e) = 5;
    arg0_00 = 0x66;
  }
  else {
    *(ushort *)(arg0 + 0x1e) = (ushort)*(byte *)(arg0 + 0x48 + (uint)*(ushort *)(arg0 + 0x24));
    arg0_00 = 0x65;
  }
  sub_080C51D4(arg0_00);
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_080da14a:
                    /* WARNING: Could not recover jumptable at 0x080da14e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DA150 @ 0x080DA150

void sub_080DA150(void)

{
  undefined4 in_r0;
  int iVar1;
  
  iVar1 = sub_080AD364(in_r0);
  Text_DrawSpriteString
            (*(undefined4 *)
              (((*(byte *)(iVar1 + 0x48 + (uint)*(ushort *)(iVar1 + 0x24)) - 1 & 0xffff) * 5 +
               (uint)*(ushort *)(iVar1 + 0x24)) * 4 + 0x8581598),0,0,0x14);
  return;
}


// sub_080DA190 @ 0x080DA190

void sub_080DA190(void)

{
  sub_080D1264(DAT_03005f70,0x30046c0);
  sub_080A9AB4(0x80de78d);
  return;
}


// sub_080DA1B4 @ 0x080DA1B4

void sub_080DA1B4(int arg0)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar3 = 0;
  uVar1 = sub_080C2A84(0);
  if ((((uVar1 & 0xffff) == 1) || (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 1)) ||
     (uVar1 = sub_080C2A84(2), (uVar1 & 0xffff) == 1)) {
    *(undefined1 *)(arg0 + 0x48) = 1;
    iVar3 = 1;
  }
  iVar4 = arg0 + 0x48;
  for (uVar1 = 0; uVar1 < 0x17c; uVar1 = uVar1 + 1) {
    iVar2 = sub_080C2644(uVar1);
    if (iVar2 != 0) {
      *(undefined1 *)(iVar4 + iVar3) = 2;
      iVar3 = iVar3 + 1;
      break;
    }
  }
  uVar1 = 0;
  do {
    if (0x3f < uVar1) {
LAB_080da246:
      uVar1 = sub_080C2A84(0);
      if ((((uVar1 & 0xffff) == 1) || (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 1)) ||
         (uVar1 = sub_080C2A84(2), (uVar1 & 0xffff) == 1)) {
        *(undefined1 *)(iVar4 + iVar3) = 4;
        iVar3 = iVar3 + 1;
      }
      *(undefined1 *)(iVar4 + iVar3) = 5;
      *(char *)(arg0 + 0x4f) = (char)iVar3 + '\x01';
                    /* WARNING: Could not recover jumptable at 0x080da28c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    iVar2 = sub_080C2734(uVar1 + 300);
    if (iVar2 != 0) {
      *(undefined1 *)(iVar4 + iVar3) = 3;
      iVar3 = iVar3 + 1;
      goto LAB_080da246;
    }
    uVar1 = uVar1 + 1;
  } while( true );
}


// sub_080DA290 @ 0x080DA290

void sub_080DA290(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x600cc00;
  REG_DMA3DAD = 0x6012800;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080DA2B4 @ 0x080DA2B4

void sub_080DA2B4(void)

{
  sub_080ACFCC(3,0x8580880,0x30030f0,0x20);
  sub_080AABB0();
  DisplayList_Add(0x80da291,1);
  return;
}


// sub_080DA2E8 @ 0x080DA2E8

void sub_080DA2E8(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined1 in_stack_00000000;
  
  DAT_03000030 = in_stack_00000000;
  DAT_03000031 = (undefined1)arg3;
  DAT_03000034 = (undefined1)arg2;
  DAT_03000035 = (undefined1)arg1;
  DAT_03000038 = 0x2f;
  return;
}


// sub_080DA31C @ 0x080DA31C

void sub_080DA31C(void)

{
  DAT_03000038 = 0x3f;
  return;
}


// sub_080DA328 @ 0x080DA328

void sub_080DA328(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined1 in_stack_00000000;
  
  DAT_03000032 = in_stack_00000000;
  DAT_03000033 = (undefined1)arg3;
  DAT_03000036 = (undefined1)arg2;
  DAT_03000037 = (undefined1)arg1;
  DAT_03000039 = 0x2f;
  return;
}


// sub_080DA35C @ 0x080DA35C

void sub_080DA35C(void)

{
  DAT_03000039 = 0x3f;
  return;
}


// sub_080DA368 @ 0x080DA368

void sub_080DA368(void)

{
  DAT_03006098 = 0;
  return;
}


// sub_080DA374 @ 0x080DA374

void sub_080DA374(int arg0,undefined4 arg1)

{
  DAT_03006098 = sub_080AD0FC(arg1,(uint)*(ushort *)(arg0 + 2));
  return;
}


// sub_080DA38C @ 0x080DA38C

void sub_080DA38C(int arg0)

{
  undefined2 uVar1;
  
  if ((DAT_03006098 == 0) || (*(int *)(DAT_03006098 + 0xc) != -1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
  return;
}


// sub_080DA3B4 @ 0x080DA3B4

void sub_080DA3B4(void)

{
  if ((DAT_03006098 != 0) && (*(int *)(DAT_03006098 + 0xc) == -1)) {
    *(undefined4 *)(DAT_03006098 + 0xc) = 1;
  }
  return;
}


// sub_080DA3D4 @ 0x080DA3D4

void sub_080DA3D4(void)

{
  if (DAT_03006098 != 0) {
    sub_080AD1FC(DAT_03006098);
    DAT_03006098 = 0;
    DAT_03000038 = 0x3f;
    DAT_03000039 = 0x3f;
  }
  return;
}


// sub_080DA404 @ 0x080DA404

void sub_080DA404(void)

{
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_080AA184(0x8008d28,0,10,0);
  }
  else {
    sub_080AA184(0x8008e20,0,10,0);
  }
  return;
}


// sub_080DA460 @ 0x080DA460

void sub_080DA460(void)

{
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_080AA184(0x8008da4,0,10,0);
  }
  else {
    sub_080AA184(0x8008ec8,0,10,0);
  }
  return;
}


// sub_080DA4BC @ 0x080DA4BC

void sub_080DA4BC(void)

{
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_080AA184(0x8008dd8,0,10,0);
  }
  else {
    sub_080AA184(0x8008f10,0,10,0);
  }
  return;
}


// sub_080DA518 @ 0x080DA518

void sub_080DA518(void)

{
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_080AA184(0x8008d7c,0,10,0);
  }
  else {
    sub_080AA184(0x8008e8c,0,10,0);
  }
  return;
}


// sub_080DA574 @ 0x080DA574

void sub_080DA574(void)

{
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_080AA184(0x8002be8,0,0,0);
    sub_080AA184(0x8002be8,0,0,0);
    sub_080AA184(0x8002be8,0,0,0);
  }
  return;
}


// sub_080DA5DC @ 0x080DA5DC

void sub_080DA5DC(void)

{
  sub_080AA184(0x8002b34,0,0,0);
  sub_080DA574();
  return;
}


// sub_080DA608 @ 0x080DA608

void sub_080DA608(void)

{
  sub_080AA184(0x8002b68,0,0,0);
  sub_080DA574();
  return;
}


// sub_080DA634 @ 0x080DA634

void sub_080DA634(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080DA658 @ 0x080DA658

void sub_080DA658(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x81b6a64,0x200afc8,in_r2);
  DisplayList_Add(0x80da635,1);
  return;
}


// sub_080DA67C @ 0x080DA67C

void sub_080DA67C(void)

{
  sub_080AA184(0x8002ba4,0,0,0);
  sub_080DA574();
  return;
}


// sub_080DA6A8 @ 0x080DA6A8

void sub_080DA6A8(void)

{
  sub_080AA184(0x8002bd8,0,0,0);
  sub_080DA574();
  return;
}


// sub_080DA6D4 @ 0x080DA6D4

void sub_080DA6D4(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080DA6F8 @ 0x080DA6F8

void sub_080DA6F8(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x81b6a64,0x200afc8,in_r2);
  DisplayList_Add(0x80da6d5,1);
  return;
}


// sub_080DA71C @ 0x080DA71C

void sub_080DA71C(int arg0)

{
  if ((DAT_030031b8 & (ushort)0x3ff) == 0) {
    *(ushort *)(arg0 + 0x1c) = DAT_030031b8 & 0x3ff;
    if ((DAT_030031bc >> 3 & 1) == 0) {
      sub_080C4AB0(0,0,0xd5,0x85);
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C51D4(0x65);
  }
  return;
}


// sub_080DA764 @ 0x080DA764

void sub_080DA764(uint arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  byte *pbVar1;
  undefined4 arg0_00;
  
  sub_080AA184(0x8008f58,6,7,1);
  pbVar1 = (byte *)sub_080A9CC0(arg0);
  if (arg0 < 100) {
    if (arg0 < 10) {
      sub_080AA184(*(undefined4 *)((uint)*pbVar1 * 4 + 0x8582410),6,7,1);
      goto LAB_080da840;
    }
  }
  else {
    sub_080AA184(*(undefined4 *)((uint)pbVar1[2] * 4 + 0x8582410),6,7,1);
  }
  sub_080AA184(*(undefined4 *)((uint)pbVar1[1] * 4 + 0x8582410),6,7,1);
  sub_080AA184(*(undefined4 *)((uint)*pbVar1 * 4 + 0x8582410),6,7,1);
LAB_080da840:
  sub_080AA184(0x8008f68,6,7,1);
  pbVar1 = (byte *)sub_080A9CC0(arg1);
  if (arg1 < 100) {
    if (arg1 < 10) {
      sub_080AA184(*(undefined4 *)((uint)*pbVar1 * 4 + 0x8582410),6,7,1);
      return;
    }
    sub_080AA184(*(undefined4 *)((uint)pbVar1[1] * 4 + 0x8582410),6,7,1);
    arg0_00 = *(undefined4 *)((uint)*pbVar1 * 4 + 0x8582410);
  }
  else {
    sub_080AA184(*(undefined4 *)((uint)pbVar1[2] * 4 + 0x8582410),6,7,1);
    sub_080AA184(*(undefined4 *)((uint)pbVar1[1] * 4 + 0x8582410),6,7,1);
    arg0_00 = *(undefined4 *)((uint)*pbVar1 * 4 + 0x8582410);
  }
  sub_080AA184(arg0_00,6,7,1);
  return;
}


// sub_080DA958 @ 0x080DA958

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DA958(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  _DAT_0203a4d4 = *(undefined4 *)(arg0 + 0x20);
  DAT_0203a4cc = arg0;
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
      sub_080DABCC(1);
      iVar1 = sub_080DAC4C();
      if (iVar1 == 0) {
        *(undefined2 *)(arg0 + 0x1e) = 3;
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080daa0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080DAA0C @ 0x080DAA0C

void sub_080DAA0C(void)

{
  undefined4 in_r0;
  int iVar1;
  
  iVar1 = sub_080AD364(in_r0);
  Text_DrawSpriteString(*(undefined4 *)((uint)*(ushort *)(iVar1 + 0x24) * 4 + 0x8582438),0,0,0x14);
  return;
}


// sub_080DAA3C @ 0x080DAA3C

void sub_080DAA3C(void)

{
  Text_DrawSpriteString(0x8009550,0,0,0x14);
  return;
}


// sub_080DAA60 @ 0x080DAA60

void sub_080DAA60(void)

{
  REG_BG3CNT = 0x8607;
  return;
}


// sub_080DAA74 @ 0x080DAA74

void sub_080DAA74(void)

{
  ushort uVar1;
  
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 & 0xf7ff;
  return;
}


// sub_080DAA88 @ 0x080DAA88

void sub_080DAA88(void)

{
  ushort uVar1;
  
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 | 0x800;
  return;
}


// sub_080DAA9C @ 0x080DAA9C

void sub_080DAA9C(void)

{
  DAT_03000038 = 0x3f;
  return;
}


// sub_080DAAA8 @ 0x080DAAA8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DAAA8(void)

{
  undefined4 local_c;
  
  _DAT_0203a454 = 0x13240800;
  CpuSet(0x3006090,&DAT_0203a458,0x4000002);
  _DAT_0203a488 = 0;
  local_c = 0;
  CpuSet(&local_c,&DAT_0203a48c,0x5000002);
  return;
}


// sub_080DAAEC @ 0x080DAAEC

void sub_080DAAEC(void)

{
  sub_080DF954(0xc,0x203a454,&DAT_0203a488);
  return;
}


// sub_080DAB04 @ 0x080DAB04

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DAB04(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(_DAT_0203a488 == 0x13240800);
  return;
}


// sub_080DAB28 @ 0x080DAB28

void sub_080DAB28(void)

{
  uint uVar1;
  uint arg0;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (((int)(uint)*(byte *)((int)&DAT_0203a48c + (uVar2 >> 3)) >> (uVar2 & 7) & 1U) != 0) {
      arg0 = uVar2 + 300 & 0xffff;
      uVar1 = sub_080C32D4(arg0);
      if ((uVar1 & 0xff) == 0) {
        sub_080C3328(arg0);
      }
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x40);
  sub_080D1264(DAT_03005f70,0x30046c0);
  return;
}


// sub_080DAB88 @ 0x080DAB88

void sub_080DAB88(void)

{
  sub_080DABCC(1);
  sub_080AE2D0();
  if ((DAT_03004740 == 0) && (DAT_03004744 == 0)) {
    DAT_03004740 = -0x7fcc829e;
    DAT_03004744 = -1;
  }
  return;
}


// sub_080DABCC @ 0x080DABCC

uint sub_080DABCC(int arg0)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined4 local_18;
  
  puVar3 = (undefined2 *)0x203b454;
  uVar4 = 0;
  local_18 = 0;
  CpuSet(&local_18,0x203b454,0x5000040);
  if (arg0 == 0) {
    uVar2 = 0;
    do {
      iVar1 = sub_080C2734(uVar2 + 300);
      if (iVar1 != 0) {
        *puVar3 = (short)(uVar2 + 300);
        puVar3 = puVar3 + 1;
        uVar4 = uVar4 + 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x40);
  }
  else {
    uVar2 = 0;
    do {
      iVar1 = uVar2 + 300;
      if (((iVar1 != 0x136) && (iVar1 != 0x152)) && (iVar1 != 0x156)) {
        *puVar3 = (short)iVar1;
        puVar3 = puVar3 + 1;
        uVar4 = uVar4 + 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x2e);
  }
  return uVar4 & 0xffff;
}


// sub_080DAC4C @ 0x080DAC4C

int sub_080DAC4C(void)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  psVar1 = (short *)0x203b454;
  do {
    if (*psVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
    psVar1 = psVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x40);
  return iVar3;
}


// sub_080DAC70 @ 0x080DAC70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DAC70(int arg0)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  undefined4 arg0_00;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  code *UNRECOVERED_JUMPTABLE;
  
  psVar6 = (short *)(arg0 + 0x24);
  uVar4 = sub_080DAC4C();
  uVar7 = uVar4 & 0xffff;
  DAT_0203a4d8 = *(undefined4 *)(arg0 + 0x20);
  _DAT_0203a4d0 = arg0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  uVar8 = uVar7;
  if (5 < uVar7) {
    uVar8 = 6;
  }
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) == 0) {
          if (((DAT_03003964 & 0x200) == 0) || (uVar7 < 7)) {
            if (((DAT_03003964 & 0x100) != 0) && (6 < uVar7)) {
              sVar2 = *psVar6;
              uVar1 = *(ushort *)(arg0 + 0x26);
              if (sVar2 == 5) {
                if ((int)(uVar1 + 0xb) < (int)(uVar7 - 1)) {
                  sVar3 = uVar1 + 6;
                }
                else {
                  sVar3 = (short)uVar4 + -6;
                }
                *(short *)(arg0 + 0x26) = sVar3;
              }
              else {
                *psVar6 = 5;
              }
              if ((sVar2 != *psVar6) || ((uint)uVar1 != (uint)*(ushort *)(arg0 + 0x26))) {
                sub_080C51D4(100);
              }
              Font_ResetGlyphSpriteCache(0x180);
            }
            goto LAB_080dadee;
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
          if ((sVar2 != *psVar6) || (uVar1 != *(ushort *)(arg0 + 0x26))) goto LAB_080dad94;
        }
        else {
          uVar1 = *(ushort *)(arg0 + 0x24);
          if ((uint)uVar1 != uVar8 - 1) {
            sVar2 = uVar1 + 1;
            goto LAB_080dad18;
          }
          if ((uVar1 == 5) && ((int)(*(ushort *)(arg0 + 0x26) + 6) <= (int)(uVar7 - 1))) {
            *(ushort *)(arg0 + 0x26) = *(ushort *)(arg0 + 0x26) + 1;
LAB_080dad94:
            sub_080C51D4(100);
          }
        }
      }
      else if (*(short *)(arg0 + 0x24) == 0) {
        if (*(short *)(arg0 + 0x26) != 0) {
          *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + -1;
          goto LAB_080dad94;
        }
      }
      else {
        sVar2 = *(short *)(arg0 + 0x24) + -1;
LAB_080dad18:
        *(short *)(arg0 + 0x24) = sVar2;
        sub_080C51D4(100);
      }
      Font_ResetGlyphSpriteCache(0x180);
      goto LAB_080dadee;
    }
    arg0_00 = 0x66;
  }
  else {
    iVar5 = sub_080C2734((uint)*(ushort *)
                                (((uint)*(ushort *)(arg0 + 0x24) + (uint)*(ushort *)(arg0 + 0x26)) *
                                 2 + 0x203b454));
    if (iVar5 == 0) {
      sub_080C51D4(0x66);
      goto LAB_080dadee;
    }
    Font_ResetGlyphSpriteCache(0x180);
    *(short *)(arg0 + 0x1e) = *(short *)(arg0 + 0x26) + *(short *)(arg0 + 0x24) + 1;
    arg0_00 = 0x65;
  }
  sub_080C51D4(arg0_00);
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_080dadee:
                    /* WARNING: Could not recover jumptable at 0x080dadf6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// Vision_DrawItemList @ 0x080DADF8

void Vision_DrawItemList(int arg0)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int local_28;
  
  uVar1 = sub_080DAC4C();
  sub_080AA184(0x800853c,0,7,0);
  uVar7 = 0;
  do {
    uVar5 = (uint)*(ushort *)((*(ushort *)(arg0 + 0x26) + uVar7) * 2 + 0x203b454);
    if (uVar5 != 0) {
      iVar2 = sub_080C2734(uVar5);
      if (iVar2 == 0) {
        puVar3 = (ushort *)0x85829bc;
      }
      else {
        iVar2 = Action_GetRecord(uVar5);
        puVar3 = (ushort *)(iVar2 + 0xc);
      }
      uVar6 = 0;
      uVar5 = 0x6c0000;
      do {
        FontSprite_DrawGlyph((uint)*puVar3,0,0,uVar5 >> 0x10);
        uVar5 = uVar5 + 0xc0000;
        puVar3 = puVar3 + 1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 8);
    }
    local_28 = (uVar1 & 0xffff) - 1;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 6);
  iVar2 = 0;
  uVar1 = 0;
  do {
    iVar4 = sub_080C2734(uVar1 + 300);
    if (iVar4 != 0) {
      iVar2 = iVar2 + 1;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x2e);
  sub_080DA764(iVar2,0x2b,0x91,0x6a);
  if (*(short *)(arg0 + 0x26) != 0) {
    sub_080C4A4C(6,1,0xcc,0xc);
  }
  if ((int)(*(ushort *)(arg0 + 0x26) + 6) <= local_28) {
    sub_080C4AB0(6,1,0xcc,0x5c);
  }
  return;
}


// Vision_ComposePrompt @ 0x080DAF50

void Vision_ComposePrompt(void)

{
  short sVar1;
  undefined4 in_r0;
  int iVar2;
  uint uVar3;
  uint arg3;
  
  iVar2 = sub_080AD364(in_r0);
  arg3 = 0x14;
  iVar2 = Action_GetRecord((uint)*(ushort *)
                                  (((uint)*(ushort *)(iVar2 + 0x24) +
                                   (uint)*(ushort *)(iVar2 + 0x26)) * 2 + 0x203b454));
  uVar3 = 0;
  sVar1 = *(short *)(iVar2 + 0xc);
  while (sVar1 != 0) {
    sub_080AC2A0((uint)*(ushort *)(uVar3 * 2 + iVar2 + 0xc),0,0,arg3);
    arg3 = arg3 + 0xc & 0xffff;
    uVar3 = uVar3 + 1 & 0xffff;
    if (7 < uVar3) break;
    sVar1 = *(short *)(uVar3 * 2 + iVar2 + 0xc);
  }
  Text_DrawSpriteString(0x8009534,0,0,arg3);
  Text_DrawSpriteString(0x8009540,0,0,0x14);
  return;
}


// sub_080DAFEC @ 0x080DAFEC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080DAFEC(void)

{
  *(undefined4 *)(DAT_0203a4cc + 0x20) = 0;
  *(undefined4 *)(_DAT_0203a4d0 + 0x20) = 0;
  return;
}


// sub_080DB000 @ 0x080DB000

void sub_080DB000(int arg0)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x3004550;
  REG_DMA3CNT = 0x85000029;
  uVar1 = REG_DMA3CNT;
  DAT_03000039 = 0x3f;
  DAT_03000030 = 0xe8;
  DAT_03000031 = 8;
  DAT_03000034 = 0x98;
  DAT_03000035 = 0x60;
  DAT_03000038 = 0x37;
  sub_080AF218(0x24,*(undefined4 *)
                     ((*(ushort *)
                        (((uint)*(ushort *)(arg0 + 0x24) + (uint)*(ushort *)(arg0 + 0x26)) * 2 +
                        0x203b454) - 300) * 4 + 0x85829cc));
  return;
}


// sub_080DB094 @ 0x080DB094

void sub_080DB094(int arg0)

{
  if (DAT_03004550 == 0x24) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C3818(1);
    sub_080AE2D0();
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_080DB0BC @ 0x080DB0BC

void sub_080DB0BC(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080DB0F4 @ 0x080DB0F4

void sub_080DB0F4(void)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined2 local_c [2];
  
  REG_DMA3SAD = &local_10;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = &local_10;
  REG_DMA3DAD = 0x3002eb0;
  REG_DMA3CNT = 0x85000040;
  uVar1 = REG_DMA3CNT;
  local_c[0] = 0;
  REG_DMA3SAD = local_c;
  REG_DMA3DAD = 0x200dfd4;
  REG_DMA3CNT = 0x81000400;
  uVar1 = REG_DMA3CNT;
  local_10 = 0;
  REG_DMA3SAD = &local_10;
  REG_DMA3DAD = 0x201d874;
  REG_DMA3CNT = 0x85001a00;
  uVar1 = REG_DMA3CNT;
  sub_080AABB0();
  DAT_0300000e = 0;
  DAT_03000006 = 0;
  DisplayList_Add(0x80db0bd,1);
  return;
}


