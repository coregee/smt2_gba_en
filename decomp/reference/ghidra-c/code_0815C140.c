/* Ghidra decompilation of asm/code_0815C140.s (reference only; not compiled). */

// sub_0815C140 @ 0x0815C140

void sub_0815C140(void)

{
  undefined4 auStack_8 [2];
  
  auStack_8[0] = 0;
  CpuSet(auStack_8,0x203b454,0x5000040);
  sub_080A9AB4(0x815c1a9);
  return;
}


// sub_0815C16C @ 0x0815C16C

void sub_0815C16C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6008000;
  REG_DMA3CNT = 0x84002000;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_0815C1A8 @ 0x0815C1A8

void sub_0815C1A8(void)

{
  undefined4 uVar1;
  int iVar2;
  dword arg2;
  uint uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  CpuSet(&local_20,0x203b454,0x5000040);
  sub_080C1450();
  arg2 = 0x209;
  REG_BG1CNT = 0x209;
  sub_080C1384();
  REG_DMA3SAD = 0x30029b0;
  REG_DMA3DAD = 0x3002db0;
  REG_DMA3CNT = 0x84000100;
  uVar1 = REG_DMA3CNT;
  sub_080AABB0();
  local_1c = 0;
  REG_DMA3SAD = &local_1c;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85001000;
  uVar1 = REG_DMA3CNT;
  LZ77UnCompWram(0x81b6270,0x200f874,arg2);
  LZ77UnCompWram(0x81b6594,&DAT_02010874,0x1000);
  LZ77UnCompWram(0x81b68bc,&DAT_02011874,0x2000);
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6010400;
  REG_DMA3CNT = 0x84000a00;
  uVar1 = REG_DMA3CNT;
  local_1c = 0;
  REG_DMA3SAD = &local_1c;
  REG_DMA3DAD = 0x200f874;
  REG_DMA3CNT = 0x85002000;
  uVar1 = REG_DMA3CNT;
  uVar3 = 0;
  do {
    *(short *)(uVar3 * 2 + 0x2000000) = (short)uVar3 + 0x5000;
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 0x400);
  DAT_0203b458 = 1;
  sub_0815C16C();
  DAT_03000006 = (short)DAT_0203b458 - 0xa0U & 0xff;
  DAT_03000040 = 0;
  DAT_0203db6a = 0;
  sub_080ACFF4();
  sub_080AB78C();
  uVar3 = 0;
  do {
    iVar2 = uVar3 * 0x20;
    (&DAT_0203b480)[uVar3 * 8] = (short)*(undefined4 *)(iVar2 + 0x87f2c50);
    (&DAT_0203b482)[uVar3 * 8] = (short)*(undefined4 *)(iVar2 + 0x87f2c54);
    (&DAT_0203b484)[uVar3 * 8] = (short)*(undefined4 *)(iVar2 + 0x87f2c58);
    (&DAT_0203b486)[uVar3 * 8] = (short)*(undefined4 *)(iVar2 + 0x87f2c5c);
    (&DAT_0203b488)[uVar3 * 8] = (short)*(undefined4 *)(iVar2 + 0x87f2c60);
    (&DAT_0203b48a)[uVar3 * 8] = (short)*(undefined4 *)(iVar2 + 0x87f2c64);
    (&DAT_0203b48c)[uVar3 * 8] = (short)*(undefined4 *)(iVar2 + 0x87f2c68);
    (&DAT_0203b48e)[uVar3 * 8] = (short)*(undefined4 *)(iVar2 + 0x87f2c6c);
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 9);
  sub_0815C75C((uint)DAT_0203b480,(uint)DAT_0203b482,(uint)DAT_0203b484,(uint)DAT_0203b486);
  DAT_0203b47a = DAT_0203b48c;
  sub_080A9AB4(0x815c381);
  REG_IE._0_2_ = 0x2003;
  REG_DISPSTAT = 0x18;
  REG_IME = 1;
  return;
}


// sub_0815C380 @ 0x0815C380

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0815C380(void)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack_20;
  
  iVar5 = DAT_0203b500;
  sub_080AD01C();
  if (DAT_0203b47c < 7) {
    uVar10 = (uint)DAT_0203b47c;
    if (iRam0203b468 == 0) {
      sVar2 = (short)((uint)(ushort)(&DAT_0203b488)[uVar10 * 8] -
                     (uint)(ushort)(&DAT_0203b482)[uVar10 * 8]);
      sVar1 = (&DAT_0203b48a)[uVar10 * 8] - (&DAT_0203b484)[uVar10 * 8];
      if ((int)(((uint)(ushort)(&DAT_0203b488)[uVar10 * 8] -
                (uint)(ushort)(&DAT_0203b482)[uVar10 * 8]) * 0x10000) < 0) {
        uRam0203b470 = 0xffff;
        sVar2 = -sVar2;
      }
      else {
        uRam0203b470 = 1;
      }
      iRam0203b468 = CONCAT22(sVar1,sVar2);
      if (sVar1 < 0) {
        uRam0203b472 = 0xffff;
        iRam0203b468 = CONCAT22(-sVar1,sVar2);
      }
      else {
        uRam0203b472 = 1;
      }
    }
    if ((short)iRam0203b468 < iRam0203b468._2_2_) {
      if ((*(short *)(iVar5 + 0x2c) == (&DAT_0203b488)[uVar10 * 8]) &&
         (*(short *)(iVar5 + 0x2e) == (&DAT_0203b48a)[uVar10 * 8])) {
        if (uVar10 == 0) {
          uRam0203b46e = DAT_0203b47c;
          uRam0203b46c = DAT_0203b47c;
          uRam0203b474 = DAT_0203b47c;
          iRam0203b468 = CONCAT22(DAT_0203b47c,DAT_0203b47c);
          DAT_0203b476 = DAT_0203b47c;
          DAT_0203b47c = DAT_0203b47c + 1;
        }
        else if (uVar10 == 6) {
          DAT_0203b47c = DAT_0203b47c + 1;
          sub_0815C7CC();
          DAT_0203b478 = 0;
          uRam0203b46e = 0;
          uRam0203b46c = 0;
          uRam0203b474 = 0;
          iRam0203b468 = 0;
          uVar10 = (uint)DAT_0203b47c;
          sub_0815C75C((uint)(ushort)(&DAT_0203b480)[uVar10 * 8],
                       (uint)(ushort)(&DAT_0203b482)[uVar10 * 8],
                       (uint)(ushort)(&DAT_0203b484)[uVar10 * 8],
                       (uint)(ushort)(&DAT_0203b486)[uVar10 * 8]);
          sub_080AD0FC(0x87f2dd4,0xffff);
        }
        else {
          if (DAT_0203b476 == 0) goto LAB_0815c532;
LAB_0815c53c:
          DAT_0203b476 = 0;
          DAT_0203b47c = DAT_0203b47c + 1;
          if (DAT_0203b47c < 7) {
            DAT_0203b47a = (&DAT_0203b48c)[(uint)DAT_0203b47c * 8];
            goto LAB_0815c564;
          }
        }
      }
      else {
        sub_0815C7E0((uint)uRam0203b46c,(uint)uRam0203b46e,(uint)DAT_0203b47a);
        uRam0203b46e = uRam0203b472;
        uRam0203b46c = 0;
        uRam0203b474 = (short)iRam0203b468 + uRam0203b474;
        iVar5 = __umodsi3(uRam0203b464,3);
        if (iVar5 == 0) {
          DAT_0203b47a = (&DAT_0203b48e)[(uint)DAT_0203b47c * 8] + DAT_0203b47a;
        }
        if ((int)iRam0203b468._2_2_ <= (int)(uint)uRam0203b474) {
          uRam0203b46c = uRam0203b470;
          sVar1 = iRam0203b468._2_2_;
          goto LAB_0815c5c2;
        }
      }
    }
    else if ((*(short *)(iVar5 + 0x2c) == (&DAT_0203b488)[uVar10 * 8]) &&
            (*(short *)(iVar5 + 0x2e) == (&DAT_0203b48a)[uVar10 * 8])) {
      if (uVar10 == 0) {
        uRam0203b46e = DAT_0203b47c;
        uRam0203b46c = DAT_0203b47c;
        uRam0203b474 = DAT_0203b47c;
        iRam0203b468 = CONCAT22(DAT_0203b47c,DAT_0203b47c);
        DAT_0203b47c = DAT_0203b47c + 1;
      }
      else if (uVar10 == 6) {
        DAT_0203b47c = DAT_0203b47c + 1;
        sub_0815C7CC();
LAB_0815c564:
        DAT_0203b478 = 0;
        uRam0203b474 = 0;
        uRam0203b46e = 0;
        uRam0203b46c = 0;
        iRam0203b468 = 0;
        uVar10 = (uint)DAT_0203b47c;
        sub_0815C75C((uint)(ushort)(&DAT_0203b480)[uVar10 * 8],
                     (uint)(ushort)(&DAT_0203b482)[uVar10 * 8],
                     (uint)(ushort)(&DAT_0203b484)[uVar10 * 8],
                     (uint)(ushort)(&DAT_0203b486)[uVar10 * 8]);
      }
      else {
        if (DAT_0203b476 != 0) goto LAB_0815c53c;
LAB_0815c532:
        sub_0815C7CC();
        sub_0815C828();
      }
    }
    else {
      sub_0815C7E0((uint)uRam0203b46c,(uint)uRam0203b46e,(uint)DAT_0203b47a);
      uRam0203b46c = uRam0203b470;
      uRam0203b46e = 0;
      uRam0203b474 = iRam0203b468._2_2_ + uRam0203b474;
      iVar5 = __umodsi3(uRam0203b464,3);
      if (iVar5 == 0) {
        DAT_0203b47a = (&DAT_0203b48e)[(uint)DAT_0203b47c * 8] + DAT_0203b47a;
      }
      if ((int)(short)iRam0203b468 <= (int)(uint)uRam0203b474) {
        uRam0203b46e = uRam0203b472;
        sVar1 = (short)iRam0203b468;
LAB_0815c5c2:
        uRam0203b474 = uRam0203b474 - sVar1;
      }
    }
  }
  if ((uRam0203b464 & 1) == 0) {
    if (*(int *)((DAT_0203b458 >> 4) * 8 + 0x87f28b0) == -2) goto LAB_0815c748;
    uVar10 = DAT_0203b458 + 1;
    DAT_03000006 = (short)DAT_0203b458 - 0x9fU & 0xff;
    DAT_0203b458 = uVar10;
    if ((uVar10 & 0xf) == 0) {
      if (_DAT_0203b454 == 0) {
        iVar5 = (uVar10 >> 4) * 8;
        iVar6 = *(int *)(iVar5 + 0x87f28b0);
        if (iVar6 == 0) {
          puVar7 = *(ushort **)(&DAT_087f28b4 + iVar5);
          uVar8 = 0;
          uVar4 = *puVar7;
          while (uVar4 != 0) {
            Font_DrawGlyphTinted((uint)*puVar7,0x200f874,uVar8,uVar10 & 0xff);
            puVar7 = puVar7 + 1;
            uVar8 = uVar8 + 0xc & 0xffff;
            uVar4 = *puVar7;
          }
        }
        else if (iVar6 < 0) {
          _DAT_0203b454 = 1;
        }
      }
      if (0xaf < DAT_0203b458) {
        uStack_20 = 0;
        REG_DMA3SAD = &uStack_20;
        REG_DMA3DAD = ((DAT_0203b458 - 0xb0 & 0xff) >> 3) * 0x400 + 0x200f874;
        REG_DMA3CNT = 0x85000200;
        uVar3 = REG_DMA3CNT;
        iRam0203b45c = iRam0203b45c + 1;
      }
      DisplayList_Add(0x815c16d,1);
    }
  }
  piVar9 = (int *)(iRam0203b45c * 8 + 0x87f28b0);
  uVar8 = (iRam0203b45c * 0x10 + 0xa0) - (DAT_0203b458 & 0xff) & 0xff;
  uVar4 = 0;
  uVar10 = uVar8;
  if (*piVar9 != -2) {
    do {
      iVar5 = *piVar9;
      if (iVar5 == 1) {
        iVar5 = piVar9[1];
LAB_0815c6e2:
        sub_080AA184(iVar5,0,0,0);
      }
      else {
        if (iVar5 == 2) {
          iVar5 = piVar9[1];
          goto LAB_0815c6e2;
        }
        if (iVar5 == 3) {
          sub_080AA184(piVar9[1],0,0,0);
        }
      }
      uVar10 = uVar10 + 0x10 & 0x1ff;
      if ((uVar8 < 0xa0) && (0x9f < uVar10)) break;
      piVar9 = piVar9 + 2;
      uVar4 = uVar4 + 1;
      if ((10 < uVar4) || (*piVar9 == -2)) break;
    } while( true );
  }
  uRam0203b464 = uRam0203b464 + 1;
LAB_0815c748:
                    /* WARNING: Could not recover jumptable at 0x0815c754. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815C75C @ 0x0815C75C

void sub_0815C75C(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  int iVar1;
  ushort in_stack_00000000;
  
  iVar1 = sub_080C4618(0,arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff);
  if (0x100 < in_stack_00000000) {
    in_stack_00000000 = 0x100;
  }
  DAT_0203b500 = iVar1;
  *(undefined2 *)(iVar1 + 0x48) = 1;
  *(ushort *)(iVar1 + 0x4a) = in_stack_00000000;
  *(ushort *)(iVar1 + 0x4c) = in_stack_00000000;
  *(undefined2 *)(iVar1 + 0x4e) = 0;
  return;
}


// sub_0815C7CC @ 0x0815C7CC

void sub_0815C7CC(void)

{
  sub_080AD1FC(DAT_0203b500);
  return;
}


// sub_0815C7E0 @ 0x0815C7E0

void sub_0815C7E0(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = DAT_0203b500;
  puVar2 = (undefined2 *)(DAT_0203b500 + 0x48);
  *(short *)(DAT_0203b500 + 0x2c) = (short)arg0 + *(short *)(DAT_0203b500 + 0x2c);
  *(short *)(iVar1 + 0x2e) = (short)arg1 + *(short *)(iVar1 + 0x2e);
  if (0x100 < (ushort)arg2) {
    arg2._0_2_ = 0x100;
  }
  *puVar2 = 1;
  *(ushort *)(iVar1 + 0x4a) = (ushort)arg2;
  *(ushort *)(iVar1 + 0x4c) = (ushort)arg2;
  *(undefined2 *)(iVar1 + 0x4e) = 0;
  return;
}


// sub_0815C828 @ 0x0815C828

void sub_0815C828(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203b47c == 5) {
    if (DAT_0203b478 == 600) {
LAB_0815c852:
      DAT_0203b476 = 1;
      goto LAB_0815c85c;
    }
  }
  else if ((DAT_0203b47c == 6) || (DAT_0203b478 == 0x15e)) goto LAB_0815c852;
  DAT_0203b478 = DAT_0203b478 + 1;
LAB_0815c85c:
                    /* WARNING: Could not recover jumptable at 0x0815c85e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815C860 @ 0x0815C860

void sub_0815C860(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85001000;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_0815C884 @ 0x0815C884

void sub_0815C884(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B6DB4(0x3a);
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  DAT_03000030 = 0xe8;
  DAT_03000031 = 8;
  DAT_03000034 = 0x80;
  DAT_03000035 = 0x18;
  DAT_03000032 = 0xe8;
  DAT_03000033 = 8;
  DAT_03000036 = 0x80;
  DAT_03000037 = 0x18;
  DAT_0300003a = 0;
  DAT_03000039 = 0x18;
  DAT_03000038 = 0x18;
  DisplayList_Add(0x815c861,1);
  return;
}


// sub_0815C904 @ 0x0815C904

void sub_0815C904(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(ushort *)(arg0 + 0x1c) = (ushort)(**(short **)(arg0 + 0x24) == 0);
                    /* WARNING: Could not recover jumptable at 0x0815c91a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815C91C @ 0x0815C91C

void sub_0815C91C(void)

{
  sub_080ACFCC(3,0x85426e0,0x3002d50,0x40);
  sub_080AB054(0x1d0,0x10,8,0x20);
  return;
}


// sub_0815C94C @ 0x0815C94C

void sub_0815C94C(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080AB860(1,8,0x1c,8);
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  Font_ResetGlyphSpriteCache(0x180);
  uVar1 = sub_080ABEB4(0);
  *(undefined4 *)(arg0 + 0x28) = uVar1;
  sub_080ACFCC(3,0x30029b0,0x3002db0,0x400);
  sub_080AABB0();
  return;
}


// sub_0815C9A0 @ 0x0815C9A0

void sub_0815C9A0(int arg0)

{
  sub_080AB91C(*(undefined4 *)(arg0 + 0x24),1);
  return;
}


// sub_0815C9B0 @ 0x0815C9B0

void sub_0815C9B0(void)

{
  int iVar1;
  undefined4 arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C2340(0x5e);
  if (iVar1 == 0) {
    iVar1 = sub_080C2340(0x5f);
    if (iVar1 == 0) {
      sub_080C2A50(1,1);
      goto LAB_0815c9dc;
    }
    arg0 = 2;
  }
  else {
    arg0 = 0;
  }
  sub_080C2A50(arg0,1);
LAB_0815c9dc:
                    /* WARNING: Could not recover jumptable at 0x0815c9de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815C9E0 @ 0x0815C9E0

void sub_0815C9E0(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080ABF04(*(undefined4 *)(arg0 + 0x28));
  if (iVar1 == 1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    *(short *)(arg0 + 0x1e) = (short)DAT_030031cc;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_0815CA08 @ 0x0815CA08

void sub_0815CA08(void)

{
  sub_080C10F4();
  sub_080C2364(0xee);
  sub_080C2364(2);
  sub_080C2364(0x100);
  DAT_03004614 = 0;
  DAT_03004514 = 0;
  DAT_03004562 = 2;
  DAT_03004564 = 6;
  sub_080D110C(3,4);
  sub_080A9AB4(0x815cab5);
  return;
}


// sub_0815CA58 @ 0x0815CA58

void sub_0815CA58(void)

{
  Text_DrawSpriteString(0x87f2d50,0,0,0xc);
  return;
}


// sub_0815CA7C @ 0x0815CA7C

void sub_0815CA7C(void)

{
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x3f;
  DisplayList_Add(0x815c861,1);
  return;
}


// sub_0815CAA8 @ 0x0815CAA8

void sub_0815CAA8(void)

{
  sub_080D5B8C(0);
  return;
}


// sub_0815CAB4 @ 0x0815CAB4

void sub_0815CAB4(void)

{
  DAT_0200ab04 = 0;
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x3f;
  sub_080A9AB4(0x815cae9);
  return;
}


// sub_0815CAE8 @ 0x0815CAE8

void sub_0815CAE8(void)

{
  sub_080AD01C();
  return;
}


// CpuFastSet @ 0x0815CAF4

void CpuFastSet(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  software_interrupt(0xc);
  return;
}


// CpuSet @ 0x0815CAF8

void CpuSet(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  software_interrupt(0xb);
  return;
}


// HuffUnComp @ 0x0815CAFC

void HuffUnComp(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  software_interrupt(0x13);
  return;
}


// LZ77UnCompWram @ 0x0815CB00

void LZ77UnCompWram(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  software_interrupt(0x11);
  return;
}


// ObjAffineSet @ 0x0815CB04

void ObjAffineSet(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  software_interrupt(0xf);
  return;
}


// RLUnCompWram @ 0x0815CB08

void RLUnCompWram(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  software_interrupt(0x14);
  return;
}


// SoftReset @ 0x0815CB0C

void SoftReset(void)

{
  REG_IME._0_1_ = 0;
  software_interrupt(1);
  software_interrupt(0);
  software_interrupt(5);
  return;
}


// VBlankIntrWait @ 0x0815CB24

void VBlankIntrWait(void)

{
  software_interrupt(5);
  return;
}


// sub_0815CB2C @ 0x0815CB2C

void sub_0815CB2C(undefined1 *arg0,undefined1 *arg1,int arg2)

{
  int iVar1;
  
  iVar1 = arg2 + -1;
  if (arg2 != 0) {
    do {
      *arg1 = *arg0;
      arg0 = arg0 + 1;
      arg1 = arg1 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != -1);
  }
  return;
}


// sub_0815CB50 @ 0x0815CB50

void sub_0815CB50(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  ushort uVar1;
  uint uVar2;
  undefined2 *puVar3;
  code *pcVar4;
  undefined2 uStack_90;
  
  puVar3 = &uStack_90;
  uVar1 = REG_WAITCNT;
  REG_WAITCNT = uVar1 & 0xfffc | 3;
  pcVar4 = sub_0815CB2C;
  for (uVar2 = 0x120000; uVar2 >> 0x10 != 0; uVar2 = ((uVar2 >> 0x10) - 1) * 0x10000) {
    *puVar3 = *(undefined2 *)pcVar4;
    pcVar4 = pcVar4 + 2;
    puVar3 = puVar3 + 1;
  }
  _call_via_r3(arg0,arg1,arg2,(int)&uStack_90 + 1);
  return;
}


// sub_0815CBB4 @ 0x0815CBB4

void sub_0815CBB4(undefined1 *arg0,undefined1 *arg1,int arg2)

{
  ushort uVar1;
  
  uVar1 = REG_WAITCNT;
  REG_WAITCNT = uVar1 & 0xfffc | 3;
  while (arg2 = arg2 + -1, arg2 != -1) {
    *arg1 = *arg0;
    arg0 = arg0 + 1;
    arg1 = arg1 + 1;
  }
  return;
}


// sub_0815CBF4 @ 0x0815CBF4

void sub_0815CBF4(char *arg0,char *arg1,int arg2)

{
  char cVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = arg2 + -1;
  if (arg2 != 0) {
    do {
      cVar1 = *arg0;
      arg0 = arg0 + 1;
      if (*arg1 != cVar1) goto LAB_0815cc1c;
      iVar2 = iVar2 + -1;
      arg1 = arg1 + 1;
    } while (iVar2 != -1);
  }
  arg1 = (char *)0x0;
LAB_0815cc1c:
                    /* WARNING: Could not recover jumptable at 0x0815cc20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(arg1);
  return;
}


// sub_0815CC24 @ 0x0815CC24

undefined4 sub_0815CC24(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  ushort uVar1;
  uint uVar2;
  undefined2 *puVar3;
  code *pcVar4;
  undefined2 local_d0;
  
  puVar3 = &local_d0;
  uVar1 = REG_WAITCNT;
  REG_WAITCNT = uVar1 & 0xfffc | 3;
  pcVar4 = sub_0815CBF4;
  for (uVar2 = 0x180000; uVar2 >> 0x10 != 0; uVar2 = ((uVar2 >> 0x10) - 1) * 0x10000) {
    *puVar3 = *(undefined2 *)pcVar4;
    pcVar4 = pcVar4 + 2;
    puVar3 = puVar3 + 1;
  }
  _call_via_r3(arg0,arg1,arg2,(int)&local_d0 + 1);
  return arg0;
}


// sub_0815CC88 @ 0x0815CC88

void sub_0815CC88(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  byte bVar1;
  int in_r3;
  code *UNRECOVERED_JUMPTABLE;
  
  for (bVar1 = 0; bVar1 < 3; bVar1 = bVar1 + 1) {
    sub_0815CBB4(arg0,arg1,arg2);
    in_r3 = sub_0815CC24(arg0,arg1,arg2);
    if (in_r3 == 0) break;
  }
                    /* WARNING: Could not recover jumptable at 0x0815ccbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_r3);
  return;
}


// _call_via_r0 @ 0x0815CCC0

undefined4 _call_via_r0(code *arg0)

{
  undefined4 uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0815ccc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*arg0)();
  return uVar1;
}


// _call_via_r1 @ 0x0815CCC4

void _call_via_r1(undefined4 arg0,code *arg1)

{
                    /* WARNING: Could not recover jumptable at 0x0815ccc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*arg1)();
  return;
}


// _call_via_r2 @ 0x0815CCC8

void _call_via_r2(undefined4 arg0,undefined4 arg1,code *arg2)

{
                    /* WARNING: Could not recover jumptable at 0x0815ccc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*arg2)();
  return;
}


// _call_via_r3 @ 0x0815CCCC

void _call_via_r3(undefined4 arg0,undefined4 arg1,undefined4 arg2,code *arg3)

{
                    /* WARNING: Could not recover jumptable at 0x0815cccc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*arg3)();
  return;
}


// _call_via_r4 @ 0x0815CCD0

void _call_via_r4(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0815ccd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// _call_via_r5 @ 0x0815CCD4

void _call_via_r5(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0815ccd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// _call_via_r6 @ 0x0815CCD8

void _call_via_r6(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0815ccd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// _call_via_r7 @ 0x0815CCDC

void _call_via_r7(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0815ccdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// _call_via_r8 @ 0x0815CCE0

void _call_via_r8(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0815cce0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// _call_via_sb @ 0x0815CCE4

void _call_via_sb(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0815cce4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// _call_via_sl @ 0x0815CCE8

void _call_via_sl(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0815cce8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// _call_via_fp @ 0x0815CCEC

void _call_via_fp(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0815ccec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// _call_via_ip @ 0x0815CCF0

void _call_via_ip(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0815ccf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// _call_via_sp @ 0x0815CCF4

void _call_via_sp(void)

{
                    /* WARNING: Could not recover jumptable at 0x0815ccf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)&stack0x00000000)();
  return;
}


// _call_via_lr @ 0x0815CCF8

void _call_via_lr(void)

{
  return;
}


// __divsi3 @ 0x0815CCFC

uint __divsi3(uint arg0,uint arg1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (arg1 == 0) {
    __div0();
    return 0;
  }
  uVar3 = arg0 ^ arg1;
  uVar2 = 1;
  uVar1 = 0;
  if ((int)arg1 < 0) {
    arg1 = -arg1;
  }
  if ((int)arg0 < 0) {
    arg0 = -arg0;
  }
  if (arg1 <= arg0) {
    for (; (arg1 < 0x10000000 && (arg1 < arg0)); arg1 = arg1 << 4) {
      uVar2 = uVar2 << 4;
    }
    for (; (arg1 < 0x80000000 && (arg1 < arg0)); arg1 = arg1 << 1) {
      uVar2 = uVar2 << 1;
    }
    while( true ) {
      if (arg1 <= arg0) {
        arg0 = arg0 - arg1;
        uVar1 = uVar1 | uVar2;
      }
      if (arg1 >> 1 <= arg0) {
        arg0 = arg0 - (arg1 >> 1);
        uVar1 = uVar1 | uVar2 >> 1;
      }
      if (arg1 >> 2 <= arg0) {
        arg0 = arg0 - (arg1 >> 2);
        uVar1 = uVar1 | uVar2 >> 2;
      }
      if (arg1 >> 3 <= arg0) {
        arg0 = arg0 - (arg1 >> 3);
        uVar1 = uVar1 | uVar2 >> 3;
      }
      if ((arg0 == 0) || (uVar2 = uVar2 >> 4, uVar2 == 0)) break;
      arg1 = arg1 >> 4;
    }
  }
  if ((int)uVar3 < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}


// __div0 @ 0x0815CD90

void __div0(void)

{
  return;
}


// __modsi3 @ 0x0815CD94

uint __modsi3(uint arg0,uint arg1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 1;
  if (arg1 == 0) {
    __div0();
    return 0;
  }
  if ((int)arg1 < 0) {
    arg1 = -arg1;
  }
  uVar1 = arg0;
  if ((int)arg0 < 0) {
    uVar1 = -arg0;
  }
  if (arg1 <= uVar1) {
    for (; (arg1 < 0x10000000 && (arg1 < uVar1)); arg1 = arg1 << 4) {
      uVar3 = uVar3 << 4;
    }
    for (; (arg1 < 0x80000000 && (arg1 < uVar1)); arg1 = arg1 << 1) {
      uVar3 = uVar3 << 1;
    }
    while( true ) {
      uVar2 = 0;
      if (arg1 <= uVar1) {
        uVar1 = uVar1 - arg1;
      }
      if (arg1 >> 1 <= uVar1) {
        uVar1 = uVar1 - (arg1 >> 1);
        uVar2 = uVar3 >> 1 | uVar3 << 0x1f;
      }
      if (arg1 >> 2 <= uVar1) {
        uVar1 = uVar1 - (arg1 >> 2);
        uVar2 = uVar2 | uVar3 >> 2 | uVar3 << 0x1e;
      }
      if (arg1 >> 3 <= uVar1) {
        uVar1 = uVar1 - (arg1 >> 3);
        uVar2 = uVar2 | uVar3 << 0x1d;
      }
      if ((uVar1 == 0) || (uVar3 >> 4 == 0)) break;
      arg1 = arg1 >> 4;
      uVar3 = uVar3 >> 4;
    }
    uVar2 = uVar2 & 0xe0000000;
    if (uVar2 != 0) {
      if ((uVar2 & uVar3 << 0x1d) != 0) {
        uVar1 = uVar1 + (arg1 >> 3);
      }
      if ((uVar2 & (uVar3 >> 2 | uVar3 << 0x1e)) != 0) {
        uVar1 = uVar1 + (arg1 >> 2);
      }
      if ((uVar2 & (uVar3 >> 1 | uVar3 << 0x1f)) != 0) {
        uVar1 = uVar1 + (arg1 >> 1);
      }
    }
  }
  if ((int)arg0 < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}


// __udivsi3 @ 0x0815CE64

uint __udivsi3(uint arg0,uint arg1)

{
  uint uVar1;
  uint uVar2;
  
  if (arg1 == 0) {
    __div0();
    return 0;
  }
  uVar2 = 1;
  uVar1 = 0;
  if (arg1 <= arg0) {
    for (; (arg1 < 0x10000000 && (arg1 < arg0)); arg1 = arg1 << 4) {
      uVar2 = uVar2 << 4;
    }
    for (; (arg1 < 0x80000000 && (arg1 < arg0)); arg1 = arg1 << 1) {
      uVar2 = uVar2 << 1;
    }
    while( true ) {
      if (arg1 <= arg0) {
        arg0 = arg0 - arg1;
        uVar1 = uVar1 | uVar2;
      }
      if (arg1 >> 1 <= arg0) {
        arg0 = arg0 - (arg1 >> 1);
        uVar1 = uVar1 | uVar2 >> 1;
      }
      if (arg1 >> 2 <= arg0) {
        arg0 = arg0 - (arg1 >> 2);
        uVar1 = uVar1 | uVar2 >> 2;
      }
      if (arg1 >> 3 <= arg0) {
        arg0 = arg0 - (arg1 >> 3);
        uVar1 = uVar1 | uVar2 >> 3;
      }
      if ((arg0 == 0) || (uVar2 = uVar2 >> 4, uVar2 == 0)) break;
      arg1 = arg1 >> 4;
    }
  }
  return uVar1;
}


// __umodsi3 @ 0x0815CEDC

uint __umodsi3(uint arg0,uint arg1)

{
  uint uVar1;
  uint uVar2;
  
  if (arg1 == 0) {
    __div0();
    return 0;
  }
  uVar2 = 1;
  if (arg1 <= arg0) {
    for (; (arg1 < 0x10000000 && (arg1 < arg0)); arg1 = arg1 << 4) {
      uVar2 = uVar2 << 4;
    }
    for (; (arg1 < 0x80000000 && (arg1 < arg0)); arg1 = arg1 << 1) {
      uVar2 = uVar2 << 1;
    }
    while( true ) {
      uVar1 = 0;
      if (arg1 <= arg0) {
        arg0 = arg0 - arg1;
      }
      if (arg1 >> 1 <= arg0) {
        arg0 = arg0 - (arg1 >> 1);
        uVar1 = uVar2 >> 1 | uVar2 << 0x1f;
      }
      if (arg1 >> 2 <= arg0) {
        arg0 = arg0 - (arg1 >> 2);
        uVar1 = uVar1 | uVar2 >> 2 | uVar2 << 0x1e;
      }
      if (arg1 >> 3 <= arg0) {
        arg0 = arg0 - (arg1 >> 3);
        uVar1 = uVar1 | uVar2 << 0x1d;
      }
      if ((arg0 == 0) || (uVar2 >> 4 == 0)) break;
      arg1 = arg1 >> 4;
      uVar2 = uVar2 >> 4;
    }
    uVar1 = uVar1 & 0xe0000000;
    if (uVar1 != 0) {
      if ((uVar1 & uVar2 << 0x1d) != 0) {
        arg0 = arg0 + (arg1 >> 3);
      }
      if ((uVar1 & (uVar2 >> 2 | uVar2 << 0x1e)) != 0) {
        arg0 = arg0 + (arg1 >> 2);
      }
      if ((uVar1 & (uVar2 >> 1 | uVar2 << 0x1f)) != 0) {
        arg0 = arg0 + (arg1 >> 1);
      }
      return arg0;
    }
    return arg0;
  }
  return arg0;
}


// sub_0815CF9C @ 0x0815CF9C

void sub_0815CF9C(uint *arg0)

{
  uint uVar1;
  int arg2;
  
  uVar1 = *arg0;
  if ((((1 < uVar1) && (uVar1 != 4)) && (uVar1 != 2)) &&
     (((arg0[4] != 0 || arg0[3] != 0 && ((int)arg0[2] < (int)0xfffffc02)) &&
      (arg2 = -arg0[2] - 0x3fe, arg2 < 0x39)))) {
    sub_0815E684(arg0[3],arg0[4],arg2);
  }
  return;
}


// sub_0815D0E4 @ 0x0815D0E4

void sub_0815D0E4(uint *arg0,undefined4 *arg1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = arg0[1];
  uVar2 = *arg0;
  uVar5 = uVar2 & 0xfffff;
  uVar4 = (uVar2 >> 0x10 & 0x7fff) >> 4;
  arg1[1] = uVar2 >> 0x1f;
  if (uVar4 == 0) {
    if (uVar3 == 0 && uVar5 == 0) {
      *arg1 = 2;
      return;
    }
    arg1[2] = 0xfffffc02;
    uVar2 = uVar3 >> 0x18;
    uVar3 = uVar3 * 0x100;
    *arg1 = 3;
    for (uVar5 = uVar2 | uVar5 << 8; uVar5 < 0x10000000; uVar5 = -iVar1 | uVar5 << 1) {
      iVar1 = (int)uVar3 >> 0x1f;
      uVar3 = uVar3 * 2;
      arg1[2] = arg1[2] + -1;
    }
  }
  else {
    if (uVar4 != 0x7ff) {
      arg1[2] = uVar4 - 0x3ff;
      *arg1 = 3;
      arg1[3] = uVar3 << 8;
      arg1[4] = uVar3 >> 0x18 | uVar5 << 8 | 0x10000000;
      return;
    }
    if (uVar3 == 0 && uVar5 == 0) {
      *arg1 = 4;
      return;
    }
    if ((uVar2 & 0x80000) == 0) {
      *arg1 = 0;
    }
    else {
      *arg1 = 1;
    }
  }
  arg1[3] = uVar3;
  arg1[4] = uVar5;
  return;
}


// sub_0815D1BC @ 0x0815D1BC

void sub_0815D1BC(uint *arg0,uint *arg1,uint *arg2)

{
  uint uVar1;
  int iVar2;
  int extraout_r1;
  uint extraout_r1_00;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  uVar3 = *arg0;
  if ((((1 < uVar3) && (uVar1 = *arg1, 1 < uVar1)) && (uVar3 != 4)) && (uVar1 != 4)) {
    if (uVar1 == 2) {
      if (uVar3 == 2) {
        uVar3 = arg0[1];
        uVar1 = arg0[2];
        *arg2 = *arg0;
        arg2[1] = uVar3;
        arg2[2] = uVar1;
        uVar3 = arg0[4];
        arg2[3] = arg0[3];
        arg2[4] = uVar3;
        arg2[1] = arg0[1] & arg1[1];
      }
    }
    else if (*arg0 != 2) {
      uVar1 = arg0[2];
      uVar3 = arg1[2];
      uVar5 = arg0[3];
      uVar6 = arg0[4];
      uStack_2c = arg1[3];
      uStack_28 = arg1[4];
      iVar2 = uVar1 - uVar3;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if (iVar2 < 0x40) {
        uVar4 = arg0[1];
        uStack_24 = arg1[1];
        uVar7 = uVar3;
        if ((int)uVar3 < (int)uVar1) {
          iVar2 = uVar1 - uVar3;
          do {
            iVar2 = iVar2 + -1;
            uVar3 = uStack_28 * -0x80000000;
            uStack_28 = uStack_28 >> 1;
            uStack_2c = uStack_2c & 1 | uVar3 | uStack_2c >> 1;
            uVar7 = uVar1;
          } while (iVar2 != 0);
        }
        uVar3 = uVar1;
        if ((int)uVar1 < (int)uVar7) {
          iVar2 = uVar7 - uVar1;
          do {
            iVar2 = iVar2 + -1;
            uVar3 = uVar6 * -0x80000000;
            uVar6 = uVar6 >> 1;
            uVar5 = uVar5 & 1 | uVar3 | uVar5 >> 1;
            uVar3 = uVar7;
          } while (iVar2 != 0);
        }
      }
      else {
        if ((int)uVar3 < (int)uVar1) {
          uStack_2c = 0;
          uStack_28 = 0;
          uVar3 = uVar1;
        }
        else {
          uVar5 = 0;
          uVar6 = 0;
        }
        uVar4 = arg0[1];
        uStack_24 = arg1[1];
      }
      if (uVar4 == uStack_24) {
        arg2[1] = uVar4;
        arg2[2] = uVar3;
        arg2[3] = uVar5 + uStack_2c;
        arg2[4] = uVar6 + uStack_28 + (uint)CARRY4(uVar5,uStack_2c);
      }
      else {
        if (uVar4 == 0) {
          uVar1 = uVar5 - uStack_2c;
          uVar6 = (uVar6 - uStack_28) - (uint)(uVar5 < uStack_2c);
        }
        else {
          uVar6 = sub_0815E728(uVar5,uVar6);
          uVar1 = uVar6 + uStack_2c;
          uVar6 = extraout_r1 + uStack_28 + (uint)CARRY4(uVar6,uStack_2c);
        }
        if ((int)uVar6 < 0) {
          arg2[1] = 1;
          arg2[2] = uVar3;
          uVar3 = sub_0815E728(uVar1,uVar6);
          arg2[3] = uVar3;
          arg2[4] = extraout_r1_00;
        }
        else {
          arg2[1] = 0;
          arg2[2] = uVar3;
          arg2[3] = uVar1;
          arg2[4] = uVar6;
        }
        uVar1 = arg2[3];
        uVar5 = arg2[4];
        uVar3 = 0xffffffff;
        uVar6 = 0xffffffff;
        while( true ) {
          uVar6 = uVar5 + uVar6 + (uint)CARRY4(uVar1,uVar3);
          if ((0xfffffff < uVar6) || ((uVar6 == 0xfffffff && (0xfffffffe < uVar1 + uVar3)))) break;
          uVar6 = -((int)arg2[3] >> 0x1f) | arg2[4] << 1;
          uVar3 = arg2[3] << 1;
          arg2[3] = uVar3;
          arg2[4] = uVar6;
          arg2[2] = arg2[2] - 1;
          uVar1 = 0xffffffff;
          uVar5 = 0xffffffff;
        }
      }
      *arg2 = 3;
      if (0x1fffffff < arg2[4]) {
        arg2[3] = arg2[3] & 1 | arg2[4] << 0x1f | arg2[3] >> 1;
        arg2[4] = arg2[4] >> 1;
        arg2[2] = arg2[2] + 1;
      }
    }
  }
  return;
}


// sub_0815D428 @ 0x0815D428

void sub_0815D428(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined1 *arg0_00;
  undefined1 auStack_54 [20];
  undefined1 auStack_40 [20];
  undefined1 auStack_2c [20];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  arg0_00 = auStack_54;
  uStack_18 = arg0;
  uStack_14 = arg1;
  uStack_10 = arg2;
  uStack_c = arg3;
  sub_0815D0E4(&uStack_18,auStack_54);
  sub_0815D0E4(&uStack_10,auStack_40);
  sub_0815D1BC(auStack_54,auStack_40,auStack_2c);
  sub_0815CF9C(arg0_00);
  return;
}


// sub_0815D458 @ 0x0815D458

void sub_0815D458(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined1 *arg0_00;
  undefined1 auStack_54 [20];
  undefined1 auStack_40 [4];
  uint local_3c;
  undefined1 auStack_2c [20];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  arg0_00 = auStack_54;
  local_18 = arg0;
  local_14 = arg1;
  local_10 = arg2;
  local_c = arg3;
  sub_0815D0E4(&local_18,auStack_54);
  sub_0815D0E4(&local_10,auStack_40);
  local_3c = local_3c ^ 1;
  sub_0815D1BC(auStack_54,auStack_40,auStack_2c);
  sub_0815CF9C(arg0_00);
  return;
}


// sub_0815D490 @ 0x0815D490

void sub_0815D490(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint *arg0_00;
  uint uVar1;
  uint uVar2;
  uint extraout_r1;
  uint extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  uint uVar3;
  bool bVar4;
  uint uStack_94;
  uint uStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  uint uStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  uint uStack_6c;
  uint uStack_68;
  int iStack_64;
  uint uStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_28;
  dword dStack_24;
  
  arg0_00 = &uStack_94;
  uStack_58 = arg0;
  uStack_54 = arg1;
  uStack_50 = arg2;
  uStack_4c = arg3;
  sub_0815D0E4(&uStack_58,&uStack_94);
  sub_0815D0E4(&uStack_50,&uStack_80);
  if (uStack_94 < 2) {
LAB_0815d52a:
    uStack_90 = (-(uStack_90 ^ uStack_7c) | uStack_90 ^ uStack_7c) >> 0x1f;
  }
  else {
    if (1 < uStack_80) {
      if (uStack_94 == 4) {
        if (uStack_80 == 2) {
LAB_0815d50e:
          arg0_00 = (uint *)0x30020b8;
          goto LAB_0815d716;
        }
        goto LAB_0815d52a;
      }
      if (uStack_80 == 4) {
        if (uStack_94 == 2) goto LAB_0815d50e;
      }
      else {
        if (uStack_94 == 2) goto LAB_0815d52a;
        if (uStack_80 != 2) {
          uStack_48 = uStack_84;
          uStack_44 = 0;
          uStack_40 = uStack_70;
          uStack_3c = 0;
          uStack_38 = sub_0815E6B8(uStack_74,0,uStack_88,0);
          uStack_34 = extraout_r1;
          uVar1 = sub_0815E6B8(uStack_40,uStack_3c,uStack_88,0);
          uVar2 = sub_0815E6B8(uStack_74,0,uStack_48,uStack_44);
          uStack_30 = sub_0815E6B8(uStack_40,uStack_3c,uStack_48,uStack_44);
          dStack_24 = 0;
          uVar3 = extraout_r1_00 + extraout_r1_01 + (uint)CARRY4(uVar1,uVar2);
          if ((uVar3 < extraout_r1_00) || ((extraout_r1_00 == uVar3 && (uVar1 + uVar2 < uVar1)))) {
            dStack_24 = 1;
          }
          uVar1 = uVar1 + uVar2 + uStack_34;
          uStack_28 = (uint)(uVar1 < uStack_34);
          uStack_60 = uVar3 + uStack_30 + uStack_28;
          uStack_68 = (-(uStack_90 ^ uStack_7c) | uStack_90 ^ uStack_7c) >> 0x1f;
          iStack_64 = iStack_8c + iStack_78 + 4;
          uVar2 = uStack_38;
          for (uStack_5c = extraout_r1_02 + (uint)CARRY4(uVar3,uStack_30) + dStack_24 +
                           (uint)CARRY4(uVar3 + uStack_30,uStack_28); 0x1fffffff < uStack_5c;
              uStack_5c = uStack_5c >> 1) {
            iStack_64 = iStack_64 + 1;
            if ((uStack_60 & 1) != 0) {
              uVar2 = uVar1 * -0x80000000 | uVar2 >> 1;
              uVar1 = uVar1 >> 1 | 0x80000000;
            }
            uStack_60 = uStack_5c * -0x80000000 | uStack_60 >> 1;
          }
          while (uStack_5c < 0x10000000) {
            iStack_64 = iStack_64 + -1;
            uStack_5c = -((int)uStack_60 >> 0x1f) | uStack_5c << 1;
            uStack_60 = uStack_60 * 2;
            if ((uVar1 & 0x80000000) != 0) {
              uStack_60 = uStack_60 | 1;
            }
            uVar1 = -((int)uVar2 >> 0x1f) | uVar1 << 1;
            uVar2 = uVar2 * 2;
          }
          if (((uStack_60 & 0xff) == 0x80) &&
             (((uStack_60 & 0x100) != 0 || (uVar1 != 0 || uVar2 != 0)))) {
            bVar4 = 0xffffff7f < uStack_60;
            uStack_60 = uStack_60 + 0x80;
            uStack_5c = uStack_5c + bVar4;
          }
          uStack_6c = 3;
          arg0_00 = &uStack_6c;
          goto LAB_0815d716;
        }
      }
    }
    uStack_7c = (-(uStack_90 ^ uStack_7c) | uStack_90 ^ uStack_7c) >> 0x1f;
    arg0_00 = &uStack_80;
  }
LAB_0815d716:
  sub_0815CF9C(arg0_00);
  return;
}


// sub_0815D738 @ 0x0815D738

void sub_0815D738(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint *arg0_00;
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint local_5c;
  uint uStack_58;
  int iStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  int iStack_40;
  uint uStack_3c;
  uint uStack_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  
  local_34 = arg0;
  local_30 = arg1;
  local_2c = arg2;
  local_28 = arg3;
  sub_0815D0E4(&local_34,&local_5c);
  sub_0815D0E4(&local_2c,&uStack_48);
  arg0_00 = &local_5c;
  if ((1 < local_5c) && (arg0_00 = &uStack_48, 1 < uStack_48)) {
    uStack_58 = uStack_58 ^ uStack_44;
    if ((local_5c == 4) || (local_5c == 2)) {
      arg0_00 = &local_5c;
      if (local_5c == uStack_48) {
        arg0_00 = (uint *)0x30020b8;
      }
    }
    else if (uStack_48 == 4) {
      uStack_50 = 0;
      uStack_4c = 0;
      iStack_54 = 0;
      arg0_00 = &local_5c;
    }
    else if (uStack_48 == 2) {
      local_5c = 4;
      arg0_00 = &local_5c;
    }
    else {
      iStack_54 = iStack_54 - iStack_40;
      uStack_24 = uStack_3c;
      uStack_20 = uStack_38;
      if ((uStack_4c < uStack_38) || ((uStack_38 == uStack_4c && (uStack_50 < uStack_3c)))) {
        uStack_4c = -((int)uStack_50 >> 0x1f) | uStack_4c << 1;
        uStack_50 = uStack_50 * 2;
        iStack_54 = iStack_54 + -1;
      }
      uVar2 = 0x10000000;
      uVar1 = 0;
      uStack_1c = 0;
      uStack_18 = 0;
      do {
        if ((uStack_38 <= uStack_4c) && ((uStack_38 != uStack_4c || (uStack_3c <= uStack_50)))) {
          uStack_1c = uStack_1c | uVar1;
          uStack_18 = uStack_18 | uVar2;
          bVar3 = uStack_50 < uStack_3c;
          uStack_50 = uStack_50 - uStack_3c;
          uStack_4c = (uStack_4c - uStack_38) - (uint)bVar3;
        }
        uVar1 = uVar2 * -0x80000000 | uVar1 >> 1;
        uVar2 = uVar2 >> 1;
        uStack_4c = -((int)uStack_50 >> 0x1f) | uStack_4c << 1;
        uStack_50 = uStack_50 * 2;
      } while (uVar2 != 0 || uVar1 != 0);
      if (((uStack_1c & 0xff) == 0x80) &&
         (((uStack_1c & 0x100) != 0 || (uStack_4c != 0 || uStack_50 != 0)))) {
        bVar3 = 0xffffff7f < uStack_1c;
        uStack_1c = uStack_1c + 0x80;
        uStack_18 = uStack_18 + bVar3;
      }
      uStack_50 = uStack_1c;
      uStack_4c = uStack_18;
      arg0_00 = &local_5c;
    }
  }
  sub_0815CF9C(arg0_00);
  return;
}


// sub_0815D8C0 @ 0x0815D8C0

void sub_0815D8C0(uint *arg0,uint *arg1)

{
  return;
}


// sub_0815D9C0 @ 0x0815D9C0

void sub_0815D9C0(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined1 auStack_40 [20];
  undefined1 auStack_2c [20];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = arg0;
  local_14 = arg1;
  local_10 = arg2;
  local_c = arg3;
  sub_0815D0E4(&local_18,auStack_40);
  sub_0815D0E4(&local_10,auStack_2c);
  sub_0815D8C0(auStack_40,auStack_2c);
  return;
}


// sub_0815D9EC @ 0x0815D9EC

void sub_0815D9EC(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint local_40 [5];
  uint local_2c [5];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = arg0;
  local_14 = arg1;
  local_10 = arg2;
  local_c = arg3;
  sub_0815D0E4(&local_18,local_40);
  sub_0815D0E4(&local_10,local_2c);
  if ((1 < local_40[0]) && (1 < local_2c[0])) {
    sub_0815D8C0(local_40,local_2c);
  }
  return;
}


// sub_0815DA38 @ 0x0815DA38

void sub_0815DA38(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint local_40 [5];
  uint local_2c [5];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = arg0;
  local_14 = arg1;
  local_10 = arg2;
  local_c = arg3;
  sub_0815D0E4(&local_18,local_40);
  sub_0815D0E4(&local_10,local_2c);
  if ((1 < local_40[0]) && (1 < local_2c[0])) {
    sub_0815D8C0(local_40,local_2c);
  }
  return;
}


// sub_0815DA84 @ 0x0815DA84

void sub_0815DA84(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint local_40 [5];
  uint local_2c [5];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = arg0;
  local_14 = arg1;
  local_10 = arg2;
  local_c = arg3;
  sub_0815D0E4(&local_18,local_40);
  sub_0815D0E4(&local_10,local_2c);
  if ((1 < local_40[0]) && (1 < local_2c[0])) {
    sub_0815D8C0(local_40,local_2c);
  }
  return;
}


// sub_0815DAD0 @ 0x0815DAD0

void sub_0815DAD0(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint local_40 [5];
  uint local_2c [5];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = arg0;
  local_14 = arg1;
  local_10 = arg2;
  local_c = arg3;
  sub_0815D0E4(&local_18,local_40);
  sub_0815D0E4(&local_10,local_2c);
  if ((1 < local_40[0]) && (1 < local_2c[0])) {
    sub_0815D8C0(local_40,local_2c);
  }
  return;
}


// sub_0815DB1C @ 0x0815DB1C

void sub_0815DB1C(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint local_40 [5];
  uint local_2c [5];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = arg0;
  local_14 = arg1;
  local_10 = arg2;
  local_c = arg3;
  sub_0815D0E4(&local_18,local_40);
  sub_0815D0E4(&local_10,local_2c);
  if ((1 < local_40[0]) && (1 < local_2c[0])) {
    sub_0815D8C0(local_40,local_2c);
  }
  return;
}


// sub_0815DB68 @ 0x0815DB68

void sub_0815DB68(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint local_40 [5];
  uint local_2c [5];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = arg0;
  local_14 = arg1;
  local_10 = arg2;
  local_c = arg3;
  sub_0815D0E4(&local_18,local_40);
  sub_0815D0E4(&local_10,local_2c);
  if ((1 < local_40[0]) && (1 < local_2c[0])) {
    sub_0815D8C0(local_40,local_2c);
  }
  return;
}


// sub_0815DBB4 @ 0x0815DBB4

void sub_0815DBB4(int arg0)

{
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  uint uStack_10;
  
  uStack_20 = 3;
  iStack_1c = -(arg0 >> 0x1f);
  if (arg0 == 0) {
    uStack_20 = 2;
  }
  else {
    iStack_18 = 0x3c;
    if (iStack_1c != 0) {
      if (arg0 == -0x80000000) {
        return;
      }
      arg0 = -arg0;
    }
    uStack_10 = arg0 >> 0x1f;
    iStack_14 = arg0;
    if (uStack_10 < 0x10000000) {
      iStack_18 = 0x3c;
      do {
        uStack_10 = -(iStack_14 >> 0x1f) | uStack_10 << 1;
        iStack_14 = iStack_14 << 1;
        iStack_18 = iStack_18 + -1;
      } while (uStack_10 < 0x10000000);
    }
  }
  sub_0815CF9C(&uStack_20);
  return;
}


// sub_0815DC30 @ 0x0815DC30

void sub_0815DC30(undefined4 arg0,undefined4 arg1)

{
  uint local_20 [2];
  int local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = arg0;
  local_8 = arg1;
  sub_0815D0E4(&local_c,local_20);
  if ((((local_20[0] != 2) && (1 < local_20[0])) && (local_20[0] != 4)) &&
     ((-1 < local_18 && (local_18 < 0x1f)))) {
    sub_0815E684(uStack_14,uStack_10,0x3c - local_18);
  }
  return;
}


// sub_0815DCA4 @ 0x0815DCA4

void sub_0815DCA4(undefined4 arg0,undefined4 arg1)

{
  undefined1 auStack_20 [4];
  uint local_1c;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = arg0;
  local_8 = arg1;
  sub_0815D0E4(&local_c,auStack_20);
  local_1c = (uint)(local_1c == 0);
  sub_0815CF9C(auStack_20);
  return;
}


// sub_0815DCCC @ 0x0815DCCC

void sub_0815DCCC(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_20 = arg0;
  local_1c = arg1;
  local_18 = arg2;
  local_14 = arg3;
  sub_0815CF9C(&local_20);
  return;
}


// sub_0815DCF4 @ 0x0815DCF4

void sub_0815DCF4(undefined4 arg0,undefined4 arg1)

{
  uint arg3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = arg0;
  uStack_10 = arg1;
  sub_0815D0E4(&uStack_14,&uStack_28);
  arg3 = iStack_18 * 4 | uStack_1c >> 0x1e;
  if ((uStack_1c & 0x3fffffff) != 0) {
    arg3 = arg3 | 1;
  }
  sub_0815E640(uStack_28,uStack_24,uStack_20,arg3);
  return;
}


// sub_0815DD38 @ 0x0815DD38

void sub_0815DD38(uint *arg0)

{
  return;
}


// sub_0815DDF0 @ 0x0815DDF0

void sub_0815DDF0(uint *arg0,uint *arg1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *arg0;
  uVar3 = uVar1 & 0x7fffff;
  uVar2 = (uVar1 & 0x7fffffff) >> 0x17;
  arg1[1] = uVar1 >> 0x1f;
  if (uVar2 == 0) {
    if (uVar3 == 0) {
      *arg1 = 2;
      return;
    }
    uVar1 = 0xffffff82;
    arg1[2] = 0xffffff82;
    uVar3 = uVar3 * 0x80;
    *arg1 = 3;
    if (uVar3 < 0x40000000) {
      do {
        uVar3 = uVar3 * 2;
        uVar1 = uVar1 - 1;
      } while (uVar3 < 0x40000000);
      arg1[2] = uVar1;
    }
  }
  else {
    if (uVar2 != 0xff) {
      arg1[2] = uVar2 - 0x7f;
      *arg1 = 3;
      arg1[3] = uVar3 << 7 | 0x40000000;
      return;
    }
    if (uVar3 == 0) {
      *arg1 = 4;
      return;
    }
    *arg1 = (uint)((uVar1 & 0x100000) != 0);
  }
  arg1[3] = uVar3;
  return;
}


// sub_0815DE6C @ 0x0815DE6C

void sub_0815DE6C(uint *arg0,uint *arg1,uint *arg2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar3 = *arg0;
  if ((((1 < uVar3) && (uVar1 = *arg1, 1 < uVar1)) && (uVar3 != 4)) && (uVar1 != 4)) {
    if (uVar1 == 2) {
      if (uVar3 == 2) {
        uVar3 = arg0[1];
        uVar1 = arg0[2];
        *arg2 = *arg0;
        arg2[1] = uVar3;
        arg2[2] = uVar1;
        arg2[3] = arg0[3];
        arg2[1] = arg0[1] & arg1[1];
      }
    }
    else if (*arg0 != 2) {
      uVar1 = arg0[2];
      uVar3 = arg1[2];
      uVar4 = arg0[3];
      uVar6 = arg1[3];
      iVar2 = uVar1 - uVar3;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if (iVar2 < 0x20) {
        uVar7 = arg0[1];
        uVar8 = arg1[1];
        uVar5 = uVar3;
        if ((int)uVar3 < (int)uVar1) {
          iVar2 = uVar1 - uVar3;
          do {
            iVar2 = iVar2 + -1;
            uVar6 = uVar6 >> 1 | uVar6 & 1;
            uVar5 = uVar1;
          } while (iVar2 != 0);
        }
        uVar3 = uVar1;
        if ((int)uVar1 < (int)uVar5) {
          iVar2 = uVar5 - uVar1;
          do {
            iVar2 = iVar2 + -1;
            uVar4 = uVar4 >> 1 | uVar4 & 1;
            uVar3 = uVar5;
          } while (iVar2 != 0);
        }
      }
      else {
        if ((int)uVar3 < (int)uVar1) {
          uVar6 = 0;
          uVar3 = uVar1;
        }
        else {
          uVar4 = 0;
        }
        uVar7 = arg0[1];
        uVar8 = arg1[1];
      }
      if (uVar7 == uVar8) {
        arg2[1] = uVar7;
        arg2[2] = uVar3;
        arg2[3] = uVar4 + uVar6;
      }
      else {
        if (uVar7 == 0) {
          uVar6 = uVar4 - uVar6;
        }
        else {
          uVar6 = uVar6 - uVar4;
        }
        if ((int)uVar6 < 0) {
          arg2[1] = 1;
          arg2[2] = uVar3;
          arg2[3] = -uVar6;
        }
        else {
          arg2[1] = 0;
          arg2[2] = uVar3;
          arg2[3] = uVar6;
        }
        uVar3 = arg2[3];
        while (uVar3 - 1 < 0x3fffffff) {
          uVar3 = uVar3 * 2;
          arg2[3] = uVar3;
          arg2[2] = arg2[2] - 1;
        }
      }
      *arg2 = 3;
      uVar3 = arg2[3];
      if ((int)uVar3 < 0) {
        arg2[3] = uVar3 & 1 | uVar3 >> 1;
        arg2[2] = arg2[2] + 1;
      }
    }
  }
  return;
}


// sub_0815DFE8 @ 0x0815DFE8

void sub_0815DFE8(undefined4 arg0,undefined4 arg1)

{
  undefined1 *arg0_00;
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [16];
  undefined4 local_10;
  undefined4 local_c;
  
  arg0_00 = auStack_40;
  local_10 = arg0;
  local_c = arg1;
  sub_0815DDF0(&local_10,auStack_40);
  sub_0815DDF0(&local_c,auStack_30);
  sub_0815DE6C(auStack_40,auStack_30,auStack_20);
  sub_0815DD38(arg0_00);
  return;
}


// sub_0815E014 @ 0x0815E014

void sub_0815E014(undefined4 arg0,undefined4 arg1)

{
  undefined1 *arg0_00;
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [4];
  uint local_2c;
  undefined1 auStack_20 [16];
  undefined4 local_10;
  undefined4 local_c;
  
  arg0_00 = auStack_40;
  local_10 = arg0;
  local_c = arg1;
  sub_0815DDF0(&local_10,auStack_40);
  sub_0815DDF0(&local_c,auStack_30);
  local_2c = local_2c ^ 1;
  sub_0815DE6C(auStack_40,auStack_30,auStack_20);
  sub_0815DD38(arg0_00);
  return;
}


// sub_0815E048 @ 0x0815E048

void sub_0815E048(undefined4 arg0,undefined4 arg1)

{
  uint *arg0_00;
  uint uVar1;
  uint extraout_r1;
  uint local_54;
  uint local_50;
  int iStack_4c;
  undefined4 uStack_48;
  uint local_44;
  uint uStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  uint uStack_30;
  int iStack_2c;
  uint uStack_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_24 = arg0;
  local_20 = arg1;
  sub_0815DDF0(&local_24,&local_54);
  sub_0815DDF0(&local_20,&local_44);
  arg0_00 = &uStack_34;
  if (local_54 < 2) {
LAB_0815e0d8:
    local_50 = (-(local_50 ^ uStack_40) | local_50 ^ uStack_40) >> 0x1f;
    arg0_00 = &local_54;
  }
  else {
    if (1 < local_44) {
      if (local_54 == 4) {
        if (local_44 == 2) {
LAB_0815e0c2:
          arg0_00 = (uint *)0x30020d0;
          goto LAB_0815e19a;
        }
        goto LAB_0815e0d8;
      }
      if (local_44 == 4) {
        if (local_54 == 2) goto LAB_0815e0c2;
      }
      else {
        if (local_54 == 2) goto LAB_0815e0d8;
        if (local_44 != 2) {
          uVar1 = sub_0815E6B8(uStack_48,0,uStack_38,0);
          uStack_30 = (-(local_50 ^ uStack_40) | local_50 ^ uStack_40) >> 0x1f;
          iStack_2c = iStack_4c + iStack_3c + 2;
          uStack_28 = extraout_r1;
          if ((int)extraout_r1 < 0) {
            iStack_2c = iStack_4c + iStack_3c + 3;
            if ((extraout_r1 & 1) != 0) {
              uVar1 = uVar1 >> 1 | 0x80000000;
            }
            uStack_28 = extraout_r1 >> 1;
          }
          while (uStack_28 < 0x40000000) {
            iStack_2c = iStack_2c + -1;
            uStack_28 = uStack_28 << 1;
            if ((uVar1 & 0x80000000) != 0) {
              uStack_28 = uStack_28 | 1;
            }
            uVar1 = uVar1 << 1;
          }
          if (((uStack_28 & 0x7f) == 0x40) && (((uStack_28 & 0x80) != 0 || (uVar1 != 0)))) {
            uStack_28 = uStack_28 + 0x40;
          }
          uStack_34 = 3;
          goto LAB_0815e19a;
        }
      }
    }
    uStack_40 = (-(local_50 ^ uStack_40) | local_50 ^ uStack_40) >> 0x1f;
    arg0_00 = &local_44;
  }
LAB_0815e19a:
  sub_0815DD38(arg0_00);
  return;
}


// sub_0815E1AC @ 0x0815E1AC

void sub_0815E1AC(undefined4 arg0,undefined4 arg1)

{
  uint uVar1;
  uint uVar2;
  uint *arg0_00;
  uint local_38;
  uint uStack_34;
  int iStack_30;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  int iStack_20;
  uint uStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = arg0;
  local_14 = arg1;
  sub_0815DDF0(&local_18,&local_38);
  sub_0815DDF0(&local_14,&uStack_28);
  arg0_00 = &local_38;
  uVar2 = uStack_2c;
  if ((1 < local_38) && (arg0_00 = &uStack_28, 1 < uStack_28)) {
    uStack_34 = uStack_34 ^ uStack_24;
    if ((local_38 == 4) || (local_38 == 2)) {
      arg0_00 = &local_38;
      if (local_38 == uStack_28) {
        arg0_00 = (uint *)0x30020d0;
      }
    }
    else if (uStack_28 == 4) {
      iStack_30 = 0;
      arg0_00 = &local_38;
      uVar2 = 0;
    }
    else if (uStack_28 == 2) {
      local_38 = 4;
      arg0_00 = &local_38;
    }
    else {
      iStack_30 = iStack_30 - iStack_20;
      if (uStack_2c < uStack_1c) {
        uStack_2c = uStack_2c << 1;
        iStack_30 = iStack_30 + -1;
      }
      uVar1 = 0x40000000;
      uVar2 = 0;
      do {
        if (uStack_1c <= uStack_2c) {
          uVar2 = uVar2 | uVar1;
          uStack_2c = uStack_2c - uStack_1c;
        }
        uVar1 = uVar1 >> 1;
        uStack_2c = uStack_2c * 2;
      } while (uVar1 != 0);
      arg0_00 = &local_38;
      if (((uVar2 & 0x7f) == 0x40) &&
         (((uVar2 & 0x80) != 0 || (arg0_00 = &local_38, uStack_2c != 0)))) {
        arg0_00 = &local_38;
        uVar2 = uVar2 + 0x40;
      }
    }
  }
  uStack_2c = uVar2;
  sub_0815DD38(arg0_00);
  return;
}


// sub_0815E298 @ 0x0815E298

void sub_0815E298(uint *arg0,uint *arg1)

{
  return;
}


// sub_0815E37C @ 0x0815E37C

void sub_0815E37C(undefined4 arg0,undefined4 arg1)

{
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [16];
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = arg0;
  local_c = arg1;
  sub_0815DDF0(&local_10,auStack_30);
  sub_0815DDF0(&local_c,auStack_20);
  sub_0815E298(auStack_30,auStack_20);
  return;
}


// sub_0815E3A4 @ 0x0815E3A4

void sub_0815E3A4(undefined4 arg0,undefined4 arg1)

{
  uint local_30 [4];
  uint local_20 [4];
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = arg0;
  local_c = arg1;
  sub_0815DDF0(&local_10,local_30);
  sub_0815DDF0(&local_c,local_20);
  if ((1 < local_30[0]) && (1 < local_20[0])) {
    sub_0815E298(local_30,local_20);
  }
  return;
}


// sub_0815E3EC @ 0x0815E3EC

void sub_0815E3EC(undefined4 arg0,undefined4 arg1)

{
  uint local_30 [4];
  uint local_20 [4];
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = arg0;
  local_c = arg1;
  sub_0815DDF0(&local_10,local_30);
  sub_0815DDF0(&local_c,local_20);
  if ((1 < local_30[0]) && (1 < local_20[0])) {
    sub_0815E298(local_30,local_20);
  }
  return;
}


// sub_0815E434 @ 0x0815E434

void sub_0815E434(undefined4 arg0,undefined4 arg1)

{
  uint local_30 [4];
  uint local_20 [4];
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = arg0;
  local_c = arg1;
  sub_0815DDF0(&local_10,local_30);
  sub_0815DDF0(&local_c,local_20);
  if ((1 < local_30[0]) && (1 < local_20[0])) {
    sub_0815E298(local_30,local_20);
  }
  return;
}


// sub_0815E47C @ 0x0815E47C

void sub_0815E47C(undefined4 arg0,undefined4 arg1)

{
  uint local_30 [4];
  uint local_20 [4];
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = arg0;
  local_c = arg1;
  sub_0815DDF0(&local_10,local_30);
  sub_0815DDF0(&local_c,local_20);
  if ((1 < local_30[0]) && (1 < local_20[0])) {
    sub_0815E298(local_30,local_20);
  }
  return;
}


// sub_0815E4C4 @ 0x0815E4C4

void sub_0815E4C4(undefined4 arg0,undefined4 arg1)

{
  uint local_30 [4];
  uint local_20 [4];
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = arg0;
  local_c = arg1;
  sub_0815DDF0(&local_10,local_30);
  sub_0815DDF0(&local_c,local_20);
  if ((1 < local_30[0]) && (1 < local_20[0])) {
    sub_0815E298(local_30,local_20);
  }
  return;
}


// sub_0815E50C @ 0x0815E50C

void sub_0815E50C(undefined4 arg0,undefined4 arg1)

{
  uint local_30 [4];
  uint local_20 [4];
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = arg0;
  local_c = arg1;
  sub_0815DDF0(&local_10,local_30);
  sub_0815DDF0(&local_c,local_20);
  if ((1 < local_30[0]) && (1 < local_20[0])) {
    sub_0815E298(local_30,local_20);
  }
  return;
}


// sub_0815E554 @ 0x0815E554

void sub_0815E554(uint arg0)

{
  undefined4 local_14;
  int local_10;
  int iStack_c;
  uint uStack_8;
  
  local_14 = 3;
  local_10 = -((int)arg0 >> 0x1f);
  if (arg0 == 0) {
    local_14 = 2;
  }
  else {
    iStack_c = 0x1e;
    uStack_8 = arg0;
    if (local_10 != 0) {
      if (arg0 == 0x80000000) {
        return;
      }
      uStack_8 = -arg0;
    }
    if (uStack_8 < 0x40000000) {
      iStack_c = 0x1e;
      do {
        uStack_8 = uStack_8 * 2;
        iStack_c = iStack_c + -1;
      } while (uStack_8 < 0x40000000);
    }
  }
  sub_0815DD38(&local_14);
  return;
}


// sub_0815E5B4 @ 0x0815E5B4

dword sub_0815E5B4(undefined4 arg0)

{
  dword dVar1;
  uint uStack_18;
  int iStack_14;
  int iStack_10;
  uint uStack_c;
  undefined4 auStack_8 [2];
  
  auStack_8[0] = arg0;
  sub_0815DDF0(auStack_8,&uStack_18);
  if ((uStack_18 == 2) || (uStack_18 < 2)) {
LAB_0815e5fe:
    dVar1 = 0;
  }
  else {
    if (uStack_18 != 4) {
      if (iStack_10 < 0) goto LAB_0815e5fe;
      if (iStack_10 < 0x1f) {
        uStack_c = uStack_c >> (0x1eU - iStack_10 & 0xff);
        if (iStack_14 == 0) {
          return uStack_c;
        }
        return -uStack_c;
      }
    }
    dVar1 = 0x7fffffff;
    if (iStack_14 != 0) {
      dVar1 = 0x80000000;
    }
  }
  return dVar1;
}


// sub_0815E61C @ 0x0815E61C

void sub_0815E61C(undefined4 arg0)

{
  undefined1 auStack_18 [4];
  uint local_14;
  undefined4 local_8 [2];
  
  local_8[0] = arg0;
  sub_0815DDF0(local_8,auStack_18);
  local_14 = (uint)(local_14 == 0);
  sub_0815DD38(auStack_18);
  return;
}


// sub_0815E640 @ 0x0815E640

void sub_0815E640(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_14 = arg0;
  uStack_10 = arg1;
  uStack_c = arg2;
  uStack_8 = arg3;
  sub_0815DD38(&uStack_14);
  return;
}


// sub_0815E658 @ 0x0815E658

void sub_0815E658(undefined4 arg0)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  local_14 = arg0;
  sub_0815DDF0(&local_14,&local_24);
  sub_0815DCCC(local_24,local_20,local_1c,local_18 << 0x1e);
  return;
}


