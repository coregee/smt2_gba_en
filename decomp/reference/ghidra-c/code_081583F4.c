/* Ghidra decompilation of asm/code_081583F4.s (reference only; not compiled). */

// sub_081583F4 @ 0x081583F4

void sub_081583F4(undefined4 *arg0)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ushort *puVar9;
  ushort *puVar10;
  uint uVar11;
  
  puVar10 = (ushort *)*arg0;
  uVar1 = *puVar10;
  ObjAffineSet(arg0[1] + 2,0x3006a30,1);
  uVar11 = 0;
  DAT_03003800 = uVar1;
  if (uVar1 != 0) {
    do {
      iVar3 = uVar11 * 6;
      puVar4 = (ushort *)(iVar3 + 0x3003802);
      *puVar4 = puVar10[1];
      (&DAT_03003804)[uVar11 * 3] = puVar10[2];
      puVar10 = puVar10 + 3;
      (&DAT_03003806)[uVar11 * 3] = *puVar10;
      puVar9 = (ushort *)
               ((uint)(*(byte *)((int)&DAT_03003802 + iVar3 + 1) >> 6) * 0x10 +
               (uint)(*(byte *)((int)&DAT_03003804 + iVar3 + 1) >> 6) * 4 + 0x87f1494);
      uVar5 = ((ushort)(&DAT_03003804)[uVar11 * 3] & 0x1ff) - 0x80;
      uVar2 = (&DAT_03003804)[uVar11 * 3] & 0xfe00;
      (&DAT_03003804)[uVar11 * 3] = uVar2 | (ushort)uVar5 & 0x1ff;
      iVar7 = (uVar5 & 0x1ff) + (uint)(*puVar9 >> 1);
      iVar8 = (uint)(puVar9[1] >> 1) + (uint)*(byte *)puVar4;
      iVar3 = (int)DAT_03006a34;
      iVar6 = (int)DAT_03006a36;
      (&DAT_03003804)[uVar11 * 3] =
           uVar2 | ((ushort)((uint)(iVar7 * DAT_03006a30 + iVar8 * DAT_03006a32) >> 8) & 0x1ff) -
                   (*puVar9 >> 1) & 0x1ff;
      *(char *)puVar4 = (char)((uint)(iVar3 * iVar7 + iVar8 * iVar6) >> 8) - (char)(puVar9[1] >> 1);
      uVar11 = uVar11 + 1 & 0xffff;
    } while (uVar11 < uVar1);
  }
  return;
}


// sub_0815851C @ 0x0815851C

void sub_0815851C(undefined4 *arg0)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint uVar9;
  
  puVar8 = (ushort *)*arg0;
  uVar1 = *puVar8;
  ObjAffineSet(arg0[1] + 2,0x3006a30,1);
  uVar9 = 0;
  DAT_03003800 = uVar1;
  if (uVar1 != 0) {
    do {
      iVar2 = uVar9 * 6;
      puVar3 = (ushort *)(iVar2 + 0x3003802);
      *puVar3 = puVar8[1];
      (&DAT_03003804)[uVar9 * 3] = puVar8[2];
      puVar8 = puVar8 + 3;
      (&DAT_03003806)[uVar9 * 3] = *puVar8;
      puVar7 = (ushort *)
               ((uint)(*(byte *)((int)&DAT_03003802 + iVar2 + 1) >> 6) * 0x10 +
               (uint)(*(byte *)((int)&DAT_03003804 + iVar2 + 1) >> 6) * 4 + 0x87f1494);
      iVar5 = ((ushort)(&DAT_03003804)[uVar9 * 3] & 0x1ff) + (uint)(*puVar7 >> 1);
      iVar6 = (uint)(puVar7[1] >> 1) + (uint)*(byte *)puVar3;
      iVar2 = (int)DAT_03006a34;
      iVar4 = (int)DAT_03006a36;
      (&DAT_03003804)[uVar9 * 3] =
           (&DAT_03003804)[uVar9 * 3] & 0xfe00 |
           ((ushort)((uint)(iVar5 * DAT_03006a30 + iVar6 * DAT_03006a32) >> 8) & 0xff) -
           (*puVar7 >> 1) & 0x1ff;
      *(char *)puVar3 = (char)((uint)(iVar2 * iVar5 + iVar6 * iVar4) >> 8) - (char)(puVar7[1] >> 1);
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < uVar1);
  }
  return;
}


// sub_0815862C @ 0x0815862C

void sub_0815862C(undefined4 *arg0,uint arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ushort uVar10;
  ushort *puVar11;
  uint arg1_00;
  ushort *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint arg1_01;
  ushort *puVar18;
  code *UNRECOVERED_JUMPTABLE;
  uint uStack_2c;
  undefined4 uVar9;
  
  arg1_00 = arg3 & 0xffff;
  puVar11 = (ushort *)*arg0;
  uVar1 = *puVar11;
  ObjAffineSet(arg0[1] + 2,0x3006a30,1);
  uStack_2c = 0;
  DAT_03003800 = uVar1;
  if (uVar1 != 0) {
    do {
      iVar6 = uStack_2c * 6;
      puVar18 = (ushort *)(iVar6 + 0x3003802);
      *puVar18 = puVar11[1];
      (&DAT_03003804)[uStack_2c * 3] = puVar11[2];
      puVar11 = puVar11 + 3;
      (&DAT_03003806)[uStack_2c * 3] = *puVar11;
      bVar4 = *(byte *)((int)&DAT_03003802 + iVar6 + 1);
      puVar12 = (ushort *)
                ((uint)(bVar4 >> 6) * 0x10 +
                (uint)(*(byte *)((int)&DAT_03003804 + iVar6 + 1) >> 6) * 4 + 0x87f1494);
      uVar10 = *puVar12;
      uVar2 = puVar12[1];
      if ((bVar4 & 2) == 0) {
        uVar10 = uVar10 >> 1;
        uVar2 = uVar2 >> 1;
      }
      arg1_01 = (uint)uVar10;
      uVar13 = (uint)uVar2;
      uVar3 = (&DAT_03003804)[uStack_2c * 3];
      uVar14 = arg1_01 + (uVar3 & 0x1ff);
      uVar15 = uVar14 & 0x1ff;
      bVar4 = *(byte *)puVar18;
      uVar16 = uVar13 + bVar4;
      uVar17 = uVar16 & 0xff;
      if (arg1_00 == 0) {
        uVar7 = arg1_01 * (arg1 & 0xffff);
        uVar8 = uVar13;
        if ((int)uVar7 < 0) {
          uVar7 = uVar7 + 0xff;
        }
      }
      else {
        uVar7 = arg1_00 * (arg1 & 0xffff);
        uVar8 = arg1_00;
        if ((int)uVar7 < 0) {
          uVar7 = uVar7 + 0xff;
        }
      }
      uVar8 = uVar8 * (arg2 & 0xffff);
      uVar7 = (uVar7 & 0xffffff) >> 8;
      if ((int)uVar8 < 0) {
        uVar8 = uVar8 + 0xff;
      }
      if ((uVar14 & 0x100) != 0) {
        uVar15 = -uVar15 & 0x7f;
      }
      if ((uVar16 & 0x80) != 0) {
        uVar17 = -uVar17 & 0x7f;
      }
      if (arg1_00 == 0) {
        uVar9 = __divsi3(uVar15 * uVar7,arg1_01);
        uVar5 = (ushort)uVar9;
        uVar14 = uVar13;
      }
      else {
        uVar9 = __divsi3(uVar15 * uVar7,arg1_00);
        uVar5 = (ushort)uVar9;
        uVar14 = arg1_00;
      }
      uVar9 = __divsi3(uVar17 * ((uVar8 & 0xffffff) >> 8),uVar14);
      if (((uVar3 & 0x1ff) + arg1_01 & 0x100) == 0) {
        uVar10 = (uVar5 & 0x1ff) - uVar10;
      }
      else {
        uVar10 = (-(uVar5 & 0x1ff) & 0x1ff) - uVar10;
      }
      (&DAT_03003804)[uStack_2c * 3] = uVar3 & 0xfe00 | uVar10 & 0x1ff;
      if ((bVar4 + uVar13 & 0x80) == 0) {
        bVar4 = (char)uVar9 - (char)uVar2;
      }
      else {
        bVar4 = -(char)uVar2 - (char)uVar9;
      }
      *(byte *)puVar18 = bVar4;
      uStack_2c = uStack_2c + 1 & 0xffff;
    } while (uStack_2c < uVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x08158820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08158824 @ 0x08158824

void sub_08158824(undefined4 *arg0)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  ushort *puVar11;
  uint uVar12;
  uint uStack_30;
  
  puVar11 = (ushort *)*arg0;
  uVar2 = *puVar11;
  ObjAffineSet(arg0[1] + 2,0x3006a30,1);
  uVar12 = 0;
  DAT_03003800 = uVar2;
  if (uVar2 != 0) {
    do {
      iVar5 = uVar12 * 6;
      puVar10 = (ushort *)(iVar5 + 0x3003802);
      *puVar10 = puVar11[1];
      (&DAT_03003804)[uVar12 * 3] = puVar11[2];
      puVar11 = puVar11 + 3;
      (&DAT_03003806)[uVar12 * 3] = *puVar11;
      bVar1 = *(byte *)((int)&DAT_03003802 + iVar5 + 1);
      puVar7 = (ushort *)
               ((uint)(bVar1 >> 6) * 0x10 +
               (uint)(*(byte *)((int)&DAT_03003804 + iVar5 + 1) >> 6) * 4 + 0x87f1494);
      uVar3 = *puVar7;
      uVar4 = puVar7[1];
      if ((bVar1 & 2) == 0) {
        uVar3 = uVar3 >> 1;
        uVar4 = uVar4 >> 1;
      }
      uStack_30 = (uint)uVar4;
      uVar8 = ((ushort)(&DAT_03003804)[uVar12 * 3] & 0x1ff) + (uint)uVar3;
      uVar9 = uVar8 & 0x1ff;
      if ((uVar8 & 0x100) != 0) {
        uVar9 = uVar9 | 0xffffff00;
      }
      uVar8 = *(byte *)puVar10 + uStack_30 & 0xff;
      if ((*(byte *)puVar10 + uStack_30 & 0x80) != 0) {
        uVar8 = uVar8 | 0xffffff00;
      }
      iVar5 = (int)DAT_03006a34;
      iVar6 = (int)DAT_03006a36;
      (&DAT_03003804)[uVar12 * 3] =
           (&DAT_03003804)[uVar12 * 3] & 0xfe00 |
           (short)(uVar9 * (int)DAT_03006a30 + uVar8 * (int)DAT_03006a32 >> 8) - uVar3 & 0x1ff;
      *(char *)puVar10 = (char)(iVar5 * uVar9 + uVar8 * iVar6 >> 8) - (char)uVar4;
      uVar12 = uVar12 + 1 & 0xffff;
    } while (uVar12 < uVar2);
  }
  return;
}


// sub_08158970 @ 0x08158970

void sub_08158970(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0203b8f8;
  DAT_0203b8f2 = DAT_0203b8f8;
  DAT_0203b8f4 = DAT_0203b8fa;
  DAT_0203b8f6 = DAT_0203b8fc;
  DAT_0203b90c = 0;
  DAT_0203b90e = 0;
  if ((uint)DAT_0203b8fa * 0x10000 <= (uint)DAT_0203b8f8 * 0x10000 &&
      (uint)DAT_0203b8f8 * 0x10000 + (uint)DAT_0203b8fa * -0x10000 != 0) {
    DAT_0203b8f8 = DAT_0203b8fa;
    DAT_0203b8fa = uVar1;
  }
  sub_08158A40();
  DAT_0203b8f8 = DAT_0203b8f2;
  DAT_0203b8fa = DAT_0203b8f4;
  DAT_0203b8fc = DAT_0203b8f6;
  if (((DAT_0203b90e & 0x30) != 0x30) && ((DAT_0203b90e & 0x40) == 0)) {
    if ((ushort)(DAT_0203b908 - 0x32U) < 8) {
      DAT_0203b90e = DAT_0203b90e & 3 | 0x10;
    }
    if (0x1a < DAT_0203b90a) {
      DAT_0203b90e = DAT_0203b90e & 3 | 0x20;
    }
  }
  return;
}


// sub_08158A34 @ 0x08158A34

undefined4 sub_08158A34(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_08158A40();
  return uVar1;
}


// sub_08158A40 @ 0x08158A40

undefined4 sub_08158A40(void)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  DAT_0203b8ec = DAT_0203b8f8;
  DAT_0203b8ee = DAT_0203b8fa;
  DAT_0203b8f0 = DAT_0203b8fc;
  if ((((DAT_0203b8f8 == 0xff) || (DAT_0203b8fa == 0xff)) ||
      (iVar1 = sub_0815B8F8((uint)DAT_0203b8f8,0), iVar1 == 0)) ||
     (iVar1 = sub_0815B8F8((uint)DAT_0203b8fa,0), iVar1 == 0)) {
    DAT_0203b908 = 0xff;
    DAT_0203b90a = 0xff;
    DAT_0203b90b = 0xff;
    DAT_0203b90e = 0x40;
  }
  else {
    sub_0815B9B8((uint)DAT_0203b8f8,&DAT_0203b901,&DAT_0203b8fe);
    sub_0815B9B8((uint)DAT_0203b8fa,&DAT_0203b902,&DAT_0203b8ff);
    uVar2 = sub_0815B9A0((uint)DAT_0203b8f8);
    DAT_0203b904 = (undefined1)uVar2;
    uVar2 = sub_0815B9A0((uint)DAT_0203b8fa);
    DAT_0203b905 = (undefined1)uVar2;
    iVar1 = sub_08158B9C();
    if (iVar1 == 0) {
      if ((DAT_0203b8f8 == 0xfb) || (DAT_0203b8fa == 0xfb)) {
        sub_081593EC();
      }
      else if (DAT_0203b8fe == DAT_0203b8ff) {
        sub_08158E78();
      }
      else if (DAT_0203b901 == DAT_0203b902) {
        sub_081590CC();
      }
      else if ((DAT_0203b901 == '\v') || (DAT_0203b902 == '\v')) {
        sub_0815915C();
      }
      else if ((DAT_0203b8fe == 8) || (DAT_0203b8ff == 8)) {
        DAT_0203b90e = DAT_0203b90e & 3;
        sub_081592AC();
      }
      else if ((DAT_0203b8fe < 0x1b) && (DAT_0203b8ff < 0x1b)) {
        DAT_0203b90e = DAT_0203b90e & 3;
        sub_0815937C();
      }
      else {
        DAT_0203b90e = DAT_0203b90e & 3;
        sub_08158FA4();
      }
    }
    else {
      sub_08158D08();
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08158b98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)();
  return uVar2;
}


// sub_08158B9C @ 0x08158B9C

undefined4 sub_08158B9C(void)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = 0x3a;
  iVar2 = 0;
  while (((uVar1 != DAT_0203b8f8 && (uVar1 != DAT_0203b8fa)) ||
         (((byte)(&DAT_087f1ad4)[iVar2] != DAT_0203b8f8 &&
          ((byte)(&DAT_087f1ad4)[iVar2] != DAT_0203b8fa))))) {
    uVar1 = (ushort)(byte)(&DAT_087f1ad6)[iVar2];
    iVar2 = iVar2 + 3;
    if (uVar1 == 0xff) {
      return 0;
    }
  }
  DAT_0203b908 = (ushort)(byte)(&DAT_087f1ad5)[iVar2];
  return 1;
}


// sub_08158BF8 @ 0x08158BF8

undefined4 sub_08158BF8(void)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = 0x16;
  while (((((uVar1 != DAT_0203b8f8 && (uVar1 != DAT_0203b8fa)) && (uVar1 != DAT_0203b8fc)) ||
          (((uVar1 = (ushort)(byte)(&DAT_087f1af3)[uVar2], uVar1 != DAT_0203b8f8 &&
            (uVar1 != DAT_0203b8fa)) && (uVar1 != DAT_0203b8fc)))) ||
         (((uVar1 = (ushort)(byte)(&DAT_087f1af4)[uVar2], uVar1 != DAT_0203b8f8 &&
           (uVar1 != DAT_0203b8fa)) && (uVar1 != DAT_0203b8fc))))) {
    uVar2 = uVar2 + 4 & 0xff;
    uVar1 = (ushort)*(byte *)(uVar2 + 0x87f1af2);
    if (uVar1 == 0xff) {
      DAT_0203b90e = 0x40;
      return 0;
    }
  }
  DAT_0203b908 = (ushort)(byte)(&DAT_087f1af5)[uVar2];
  return 1;
}


// sub_08158CA4 @ 0x08158CA4

void sub_08158CA4(void)

{
  DAT_0203b908 = 0xfb;
  sub_08158CBC();
  return;
}


// sub_08158CBC @ 0x08158CBC

undefined4 sub_08158CBC(void)

{
  undefined4 uVar1;
  
  if (DAT_0203b908 == -1) {
    DAT_0203b90c = DAT_0203b90c & 0xfc;
    sub_08158E00();
    DAT_0203b90e = 0x40;
    uVar1 = 0;
  }
  else {
    DAT_0203b90c = DAT_0203b90c & 0x7c;
    DAT_0203b910 = 1;
    uVar1 = 1;
    sub_08158D20();
  }
  return uVar1;
}


// sub_08158D08 @ 0x08158D08

void sub_08158D08(void)

{
  DAT_0203b910 = 0;
  sub_08158D20();
  return;
}


// sub_08158D20 @ 0x08158D20

void sub_08158D20(void)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  DAT_0203b908 = (ushort)(byte)DAT_0203b908;
  sub_0815B9B8((uint)DAT_0203b908,&DAT_0203b90b,&DAT_0203b90a);
  iVar1 = sub_0815BA28((uint)DAT_0203b908);
  if (iVar1 != 0) {
    DAT_0203b8f8 = DAT_0203b8f2;
    DAT_0203b8fa = DAT_0203b8f4;
    DAT_0203b8fc = DAT_0203b8f6;
    if (((DAT_0203b90c & 0x80) != 0) ||
       ((((DAT_0203b910 == 0 || (DAT_0203b908 != DAT_0203b8f6)) && (DAT_0203b908 != DAT_0203b8f4))
        && (DAT_0203b908 != DAT_0203b8f2)))) {
      uVar2 = 1;
      goto LAB_08158df6;
    }
  }
  DAT_0203b90b = 0xff;
  DAT_0203b90a = 0xff;
  DAT_0203b908 = 0xff;
  DAT_0203b90e = 0x40;
  uVar2 = 0;
LAB_08158df6:
                    /* WARNING: Could not recover jumptable at 0x08158dfe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}


// sub_08158E00 @ 0x08158E00

void sub_08158E00(void)

{
  if ((DAT_0203b90c & 8) == 0) {
    DAT_0203b908 = 0xff;
    DAT_0203b90a = 0xff;
    DAT_0203b90b = 0xff;
    DAT_0203b90e = 0x40;
  }
  else {
    DAT_0203b908 = 0xfb;
    DAT_0203b90c = DAT_0203b90c & 0x7f;
    DAT_0203b910 = 1;
    sub_08158D20();
  }
  return;
}


// sub_08158E54 @ 0x08158E54

void sub_08158E54(void)

{
  DAT_0203b908 = 0xff;
  DAT_0203b90a = 0xff;
  DAT_0203b90b = 0xff;
  DAT_0203b90e = 0x40;
  return;
}


// sub_08158E78 @ 0x08158E78

void sub_08158E78(void)

{
  byte bVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203b8fe < 0x1b) {
    bVar1 = *(byte *)(DAT_0203b8fe + 0x87f15e0);
    if (bVar1 == 0) {
      sub_08158ED0();
    }
    else if (bVar1 == 0xff) {
      sub_08158E54();
      DAT_0203b90e = 0x40;
    }
    else {
      DAT_0203b908 = (ushort)*(byte *)(DAT_0203b8fe + 0x87f15e0);
      sub_08158D08();
    }
  }
  else {
    sub_08158F48((uint)DAT_0203b8fe);
  }
                    /* WARNING: Could not recover jumptable at 0x08158ecc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08158ED0 @ 0x08158ED0

void sub_08158ED0(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  cVar1 = *(char *)((DAT_0203b8f8 - 0x32 & 0xffff) * 8 + (DAT_0203b8fa - 0x32 & 0xffff) + 0x87f15a0)
  ;
  if (cVar1 == -1) {
    sub_08158E54();
    DAT_0203b90e = 0x40;
  }
  else {
    uVar3 = (uint)DAT_030046cd;
    DAT_0203b90a = cVar1;
    while ((0 < (int)uVar3 && (iVar2 = sub_08159438(uVar3 & 0xffff), iVar2 * 0x10000 < 0))) {
      uVar3 = uVar3 - 1;
    }
    if (uVar3 == 0) {
      sub_08158CA4();
    }
    else {
      sub_08158D08();
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08158f46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08158F48 @ 0x08158F48

void sub_08158F48(int arg0)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  DAT_0203b90a = *(undefined1 *)(arg0 + 0x87f15e0);
  for (uVar3 = ((int)((uint)DAT_0203b904 + (uint)DAT_0203b905) >> 1) + 2; sVar1 = DAT_0203b908,
      (int)uVar3 < 99; uVar3 = uVar3 + 1) {
    uVar2 = sub_08159438(uVar3 & 0xffff);
    sVar1 = (short)uVar2;
    if (-1 < (short)uVar2) break;
  }
  DAT_0203b908 = sVar1;
  if (uVar3 == 99) {
    sub_08158CA4();
  }
  else {
    sub_08158D08();
  }
                    /* WARNING: Could not recover jumptable at 0x08158fa2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08158FA4 @ 0x08158FA4

void sub_08158FA4(void)

{
  byte bVar1;
  byte *pbVar4;
  int iVar5;
  uint arg0;
  code *UNRECOVERED_JUMPTABLE;
  byte bVar2;
  byte bVar3;
  
  if (DAT_0203b8fe < 0x1b) {
    pbVar4 = &DAT_0203b905;
    bVar1 = DAT_0203b904;
    bVar2 = (byte)DAT_0203b8f8;
    bVar3 = (byte)DAT_0203b8fa;
  }
  else {
    if (0x1a < DAT_0203b8ff) {
      sub_08159098();
      goto LAB_08159090;
    }
    pbVar4 = &DAT_0203b904;
    bVar1 = DAT_0203b905;
    bVar2 = (byte)DAT_0203b8fa;
    bVar3 = (byte)DAT_0203b8f8;
  }
  if (bVar1 < *pbVar4) {
    if ((DAT_0203b904 + DAT_0203b905 & 1) == 0) {
      sub_08159634((uint)bVar3,1);
      sub_08158D08();
      goto LAB_08159090;
    }
  }
  else {
    DAT_0203b908 = (ushort)bVar2;
    arg0 = (uint)DAT_0203b904 + (uint)DAT_0203b905;
    iVar5 = __modsi3(arg0,7);
    if (iVar5 == 0) {
      sub_08159634((uint)DAT_0203b908,2);
      sub_08158D08();
      goto LAB_08159090;
    }
    iVar5 = __modsi3(arg0,5);
    if (iVar5 == 0) {
      sub_08159634((uint)DAT_0203b908,1);
      sub_08158D08();
      goto LAB_08159090;
    }
    iVar5 = __modsi3(arg0,3);
    if (iVar5 == 0) {
      sub_08159690((uint)DAT_0203b908,1);
      sub_08158D08();
      goto LAB_08159090;
    }
    if ((arg0 & 1) == 0) {
      sub_08159634((uint)bVar3,1);
      sub_08158D08();
      goto LAB_08159090;
    }
  }
  sub_08158CA4();
LAB_08159090:
                    /* WARNING: Could not recover jumptable at 0x08159094. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08159098 @ 0x08159098

void sub_08159098(void)

{
  ushort *puVar1;
  
  if (DAT_0203b904 < DAT_0203b905) {
    puVar1 = &DAT_0203b8fa;
  }
  else {
    puVar1 = &DAT_0203b8f8;
  }
  sub_08159634((uint)*puVar1,1);
  sub_08158D08();
  return;
}


// sub_081590CC @ 0x081590CC

void sub_081590CC(void)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((DAT_0203b8fe < 0x1b) && (DAT_0203b8ff < 0x1b)) {
    DAT_0203b90b = DAT_0203b901;
    uVar2 = ((int)((uint)DAT_0203b904 + (uint)DAT_0203b905) >> 1) + 3;
    if (uVar2 < 99) {
      do {
        iVar1 = sub_081594B4(uVar2 & 0xffff);
        if (-1 < iVar1 * 0x10000) {
          sub_08158D08();
          goto LAB_08159138;
        }
        uVar2 = uVar2 + 1;
      } while ((int)uVar2 < 99);
    }
    sub_08158E54();
    DAT_0203b90e = 0x40;
  }
  else {
    sub_08158FA4();
  }
LAB_08159138:
                    /* WARNING: Could not recover jumptable at 0x0815913c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08159144 @ 0x08159144

uint sub_08159144(void)

{
  uint uVar1;
  
  uVar1 = sub_080C2244();
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0xff) {
    uVar1 = 0xfb;
  }
  return uVar1;
}


// sub_0815915C @ 0x0815915C

void sub_0815915C(void)

{
  byte bVar1;
  ushort uVar2;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  code *UNRECOVERED_JUMPTABLE;
  ushort uVar3;
  
  DAT_03006a38 = 1;
  DAT_0203b90c = DAT_0203b90c | 8;
  DAT_0203b90e = DAT_0203b90e & 3 | 0x30;
  iVar4 = __divsi3((uint)DAT_0203b904 + (uint)DAT_0203b905 + (uint)DAT_030046cd,3);
  if (DAT_0203b901 == '\v') {
    puVar5 = &DAT_0203b8fa;
    uVar3 = DAT_0203b8f8;
  }
  else {
    puVar5 = &DAT_0203b8f8;
    uVar3 = DAT_0203b8fa;
  }
  uVar2 = *puVar5;
  uVar6 = sub_0815B958((uint)uVar3);
  uVar7 = sub_0815B958((uint)uVar2);
  bVar1 = *(byte *)((uVar7 & 3) + ((uint)((uVar6 & 3) != 0) * 0x30000 >> 0x10) + 0x87f160b);
  iVar10 = 0;
  do {
    iVar9 = 0;
    do {
      uVar6 = sub_08159144();
      if (uVar6 != 0xff) {
        DAT_0203b908 = (ushort)uVar6;
        iVar8 = sub_0815BA28(uVar6 & 0xffff);
        if (((iVar8 != 0) && (DAT_0203b908 != DAT_0203b8f8)) && (DAT_0203b908 != DAT_0203b8fa))
        break;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)1000);
    uVar6 = sub_0815B9A0((uint)DAT_0203b908);
    if ((((int)(uVar6 & 0xff) < iVar4 + 4) &&
        (uVar6 = sub_0815B958((uint)DAT_0203b908), (uVar6 & 3) == (bVar1 & 3))) &&
       ((DAT_0203b908 != DAT_0203b8f8 && (DAT_0203b908 != DAT_0203b8fa)))) {
      sub_08158D08();
      goto LAB_0815928c;
    }
    iVar10 = iVar10 + 1;
    if (0x1f < iVar10) {
      sub_08158CA4();
LAB_0815928c:
                    /* WARNING: Could not recover jumptable at 0x08159298. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  } while( true );
}


// sub_081592AC @ 0x081592AC

void sub_081592AC(void)

{
  ushort uVar1;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  ushort uVar2;
  
  bVar3 = DAT_0203b8fe;
  uVar1 = DAT_0203b8fa;
  uVar2 = DAT_0203b8f8;
  if (DAT_0203b8fe == 8) {
    bVar3 = DAT_0203b8ff;
    uVar1 = DAT_0203b8f8;
    uVar2 = DAT_0203b8fa;
  }
  pbVar4 = (byte *)((uint)bVar3 * 4 + ((int)(uVar1 - 0x32) >> 1) + 0x87f1611);
  if (*pbVar4 == 0xff) {
    sub_08158E54();
    DAT_0203b90e = 0x40;
  }
  else {
    uVar5 = (uint)*pbVar4;
    if ((uVar1 & 1) == 0) {
      uVar5 = (int)uVar5 >> 4;
    }
    if ((uVar5 & 3) == 0) {
      sub_08159690((uint)uVar2,(uVar5 & 0xf) + 1);
      DAT_0203b90c = DAT_0203b90c | 1;
      DAT_0203b90e = DAT_0203b90e & 0xf0 | 1;
    }
    else {
      sub_08159634((uint)uVar2,uVar5 & 3);
      bVar3 = (char)(uVar5 & 3) + 1;
      DAT_0203b90c = bVar3 | DAT_0203b90c;
      DAT_0203b90e = DAT_0203b90e & 0xf0 | bVar3;
    }
    sub_08158D08();
  }
  return;
}


// sub_0815937C @ 0x0815937C

void sub_0815937C(void)

{
  char cVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  cVar1 = *(char *)((uint)DAT_0203b8fe * 0x1a + (uint)DAT_0203b8ff + 0x87f16bd);
  if (cVar1 == -1) {
    sub_08158E54();
    DAT_0203b90e = 0x40;
  }
  else {
    DAT_0203b904 = (char)((int)((uint)DAT_0203b904 + (uint)DAT_0203b905) >> 1) + 3;
    DAT_0203b90a = cVar1;
    while (iVar2 = sub_08159438((uint)DAT_0203b904), iVar2 * 0x10000 < 0) {
      DAT_0203b904 = DAT_0203b904 + 1;
    }
    sub_08158D08();
  }
                    /* WARNING: Could not recover jumptable at 0x081593ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081593EC @ 0x081593EC

void sub_081593EC(void)

{
  ushort uVar1;
  
  uVar1 = DAT_0203b8f8;
  if (DAT_0203b8f8 == 0xfb) {
    uVar1 = DAT_0203b8fa;
  }
  DAT_0203b908 = uVar1 & 0xff;
  DAT_0203b90d = (undefined1)uVar1;
  DAT_0203b90c = DAT_0203b90c | 0x80;
  sub_08158D08();
  return;
}


// sub_08159438 @ 0x08159438

int sub_08159438(undefined4 arg0)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  
  uVar3 = (uint)DAT_0203b90a;
  bVar1 = *(byte *)(uVar3 + 0x87f1514);
  uVar5 = (uint)(byte)(&DAT_087f1513)[uVar3];
  if ((uVar3 == 1) || (uVar3 == 0x23)) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = (ushort)uVar5;
  uVar3 = uVar5 & 0xff;
  iVar2 = sub_080BF648(uVar3);
  if ((ushort)arg0 <= *(byte *)(iVar2 + 1)) {
    do {
      iVar2 = sub_080BF648(uVar3);
      if (*(byte *)(iVar2 + 1) == (ushort)arg0) break;
      uVar3 = uVar5 + 1;
      uVar5 = uVar3 & 0xffff;
      uVar3 = uVar3 & 0xff;
    } while (uVar5 != bVar1);
    uVar4 = (ushort)uVar5;
    if (uVar5 == bVar1) {
      return 0xffffffff;
    }
  }
  DAT_0203b908 = uVar4 & 0xff;
  return (int)(short)(uVar4 & 0xff);
}


// sub_081594B4 @ 0x081594B4

int sub_081594B4(uint arg0)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint arg0_00;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  DAT_0203b868 = -1;
  DAT_0203b869 = 0xff;
  DAT_0203b86a = 0xff;
  DAT_0203b878 = 0xff;
  DAT_0203b879 = 0xff;
  DAT_0203b87a = 0xff;
  iVar4 = 0;
  cVar1 = *(char *)((uint)DAT_0203b90b * 3 + 0x87f1961);
  iVar2 = (uint)DAT_0203b90b * 3;
  while (cVar1 != -1) {
    DAT_0203b90a = *(undefined1 *)(iVar2 + 0x87f1961);
    iVar4 = iVar4 + 1;
    arg0_00 = arg0 & 0xffff;
    do {
      uVar3 = sub_08159438(arg0_00);
      if (-1 < (short)uVar3) {
        *(char *)(iVar5 + 0x203b868) = (char)uVar3;
        iVar5 = iVar5 + 1;
        break;
      }
      arg0_00 = arg0_00 + 1 & 0xffff;
    } while (arg0_00 < 99);
    if (2 < iVar4) break;
    cVar1 = (&DAT_087f1962)[iVar2];
    iVar2 = iVar2 + 1;
  }
  if (DAT_0203b868 == -1) {
    iVar5 = -1;
  }
  else {
    uVar3 = sub_08159568(arg0 & 0xffff);
    iVar5 = (int)(short)uVar3;
  }
  return iVar5;
}


// sub_08159568 @ 0x08159568

int sub_08159568(undefined4 arg0)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = sub_0815B9A0((uint)DAT_0203b868);
  DAT_0203b878 = (byte)uVar1;
  if (DAT_0203b869 != 0xff) {
    uVar1 = sub_0815B9A0((uint)DAT_0203b869);
    DAT_0203b879 = (byte)uVar1;
    if (DAT_0203b86a != 0xff) {
      uVar1 = sub_0815B9A0((uint)DAT_0203b86a);
      DAT_0203b87a = (byte)uVar1;
    }
  }
  if (DAT_0203b879 < DAT_0203b878) {
    sub_08159604(1,0);
  }
  if (DAT_0203b87a < DAT_0203b879) {
    sub_08159604(2,1);
  }
  if (DAT_0203b879 < DAT_0203b878) {
    sub_08159604(1,0);
  }
  iVar2 = 0;
  if ((((DAT_0203b878 < (ushort)arg0) && (DAT_0203b879 != 0xff)) &&
      (iVar2 = 1, DAT_0203b879 < (ushort)arg0)) &&
     ((DAT_0203b87a != 0xff && (iVar2 = 2, DAT_0203b87a < (ushort)arg0)))) {
    iVar2 = -1;
  }
  else {
    DAT_0203b908 = (ushort)*(byte *)(iVar2 + 0x203b868);
    iVar2 = (int)(short)DAT_0203b908;
  }
  return iVar2;
}


// sub_08159604 @ 0x08159604

void sub_08159604(int arg0,int arg1)

{
  undefined1 uVar1;
  
  uVar1 = (&DAT_0203b878)[arg1];
  (&DAT_0203b878)[arg1] = (&DAT_0203b878)[arg0];
  (&DAT_0203b878)[arg0] = uVar1;
  uVar1 = *(undefined1 *)(arg1 + 0x203b868U);
  *(undefined1 *)(arg1 + 0x203b868U) = *(undefined1 *)(arg0 + 0x203b868U);
  *(undefined1 *)(arg0 + 0x203b868U) = uVar1;
  return;
}


// sub_08159634 @ 0x08159634

void sub_08159634(undefined4 arg0,undefined4 arg1)

{
  uint uVar1;
  
  DAT_0203b908 = (ushort)arg0 & 0xff;
  uVar1 = sub_0815B9DC((uint)DAT_0203b908);
  for (; ((short)arg1 != 0 && (DAT_0203b908 != (byte)(&DAT_087f1513)[uVar1 & 0xffff]));
      DAT_0203b908 = DAT_0203b908 - 1) {
    arg1._0_2_ = (short)arg1 + -1;
  }
  return;
}


// sub_08159690 @ 0x08159690

void sub_08159690(undefined4 arg0,undefined4 arg1)

{
  uint uVar1;
  
  DAT_0203b908 = (ushort)arg0 & 0xff;
  uVar1 = sub_0815B9DC((uint)DAT_0203b908);
  for (; ((short)arg1 != 0 && (DAT_0203b908 != (*(byte *)((uVar1 & 0xffff) + 0x87f1514) - 1 & 0xff))
         ); DAT_0203b908 = DAT_0203b908 + 1) {
    arg1._0_2_ = (short)arg1 + -1;
  }
  return;
}


// sub_081596F0 @ 0x081596F0

void sub_081596F0(void)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined4 unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = DAT_0203b8f8;
  DAT_0203b8f2 = DAT_0203b8f8;
  DAT_0203b8f4 = DAT_0203b8fa;
  DAT_0203b8f6 = DAT_0203b8fc;
  DAT_0203b8ec = DAT_0203b8f8;
  DAT_0203b8ee = DAT_0203b8fa;
  DAT_0203b8f0 = DAT_0203b8fc;
  DAT_0203b90c = 0;
  DAT_0203b90e = 0;
  if ((uint)DAT_0203b8fa * 0x10000 <= (uint)DAT_0203b8f8 * 0x10000 &&
      (uint)DAT_0203b8f8 * 0x10000 + (uint)DAT_0203b8fa * -0x10000 != 0) {
    DAT_0203b8f8 = DAT_0203b8fa;
    DAT_0203b8fa = uVar1;
  }
  uVar2 = DAT_0203b8fa;
  uVar1 = DAT_0203b8f8;
  if (DAT_0203b8fc < DAT_0203b8f8) {
    DAT_0203b8f8 = DAT_0203b8fc;
    DAT_0203b8fc = uVar1;
  }
  if (DAT_0203b8fc < DAT_0203b8fa) {
    DAT_0203b8fa = DAT_0203b8fc;
    DAT_0203b8fc = uVar2;
  }
  iVar3 = sub_0815B8F8((uint)DAT_0203b8f8,0);
  if (((iVar3 == 0) || (iVar3 = sub_0815B8F8((uint)DAT_0203b8fa,0), iVar3 == 0)) ||
     (iVar3 = sub_0815B8F8((uint)DAT_0203b8fc,0), iVar3 == 0)) {
    puVar5 = (undefined1 *)0x0;
    sub_08158E00();
  }
  else {
    sub_0815B9B8((uint)DAT_0203b8f8,0x203b901,0x203b8fe);
    sub_0815B9B8((uint)DAT_0203b8fa,0x203b902,&DAT_0203b8ff);
    sub_0815B9B8((uint)DAT_0203b8fc,0x203b903,&DAT_0203b900);
    uVar4 = sub_0815B9A0((uint)DAT_0203b8f8);
    DAT_0203b904 = (undefined1)uVar4;
    uVar4 = sub_0815B9A0((uint)DAT_0203b8fa);
    DAT_0203b905 = (undefined1)uVar4;
    uVar4 = sub_0815B9A0((uint)DAT_0203b8fc);
    DAT_0203b906 = (undefined1)uVar4;
    puVar5 = (undefined1 *)sub_08158BF8();
    if (puVar5 == (undefined1 *)0x0) {
      if (((DAT_0203b8fe == 8) || (DAT_0203b8ff == 8)) || (DAT_0203b900 == 8)) {
        puVar5 = &DAT_0203b90e;
        DAT_0203b90e = DAT_0203b90e & 3;
        sub_0815993C();
      }
      else if (DAT_0203b8fe < 0x1b) {
        if (DAT_0203b8ff < 0x1b) {
          if (DAT_0203b900 < 0x1b) {
            puVar5 = (undefined1 *)(uint)DAT_0203b901;
            if (((puVar5 == (undefined1 *)0xb) ||
                (puVar5 = (undefined1 *)(uint)DAT_0203b902, puVar5 == (undefined1 *)0xb)) ||
               (puVar5 = (undefined1 *)(uint)DAT_0203b903, puVar5 == (undefined1 *)0xb)) {
              sub_08159F18();
            }
            else if (((DAT_0203b8fe == 0x16) || (DAT_0203b8ff == 0x16)) || (DAT_0203b900 == 0x16)) {
              sub_0815A150();
            }
            else {
              DAT_0203b90e = DAT_0203b90e & 3;
              puVar5 = (undefined1 *)sub_0815A30C();
            }
          }
          else {
            puVar5 = (undefined1 *)(DAT_0203b90e & 3);
            DAT_0203b90e = (byte)puVar5;
            sub_08159D50();
          }
        }
        else {
          puVar5 = (undefined1 *)(DAT_0203b90e & 3);
          DAT_0203b90e = (byte)puVar5;
          sub_08159DF0();
        }
      }
      else {
        puVar5 = (undefined1 *)(DAT_0203b90e & 3);
        DAT_0203b90e = (byte)puVar5;
        sub_08159E9C();
      }
    }
    else {
      sub_08158D08();
    }
  }
  DAT_0203b8f8 = DAT_0203b8f2;
  DAT_0203b8fa = DAT_0203b8f4;
  DAT_0203b8fc = DAT_0203b8f6;
  if ((DAT_0203b908 != 0xff) && ((DAT_0203b90e & 0x30) != 0x30)) {
    if ((ushort)(DAT_0203b908 - 0x32U) < 8) {
      DAT_0203b90e = DAT_0203b90e & 3 | 0x10;
    }
    if (0x1a < DAT_0203b90a) {
      DAT_0203b90e = DAT_0203b90e & 3 | 0x20;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08159934. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(puVar5,UNRECOVERED_JUMPTABLE,0x203b868,unaff_r8);
  return;
}


// sub_0815993C @ 0x0815993C

void sub_0815993C(void)

{
  code *UNRECOVERED_JUMPTABLE;
  byte bVar1;
  
  bVar1 = DAT_0203b8fe == '\b';
  if (DAT_0203b8ff == '\b') {
    bVar1 = bVar1 + 1;
  }
  if (DAT_0203b900 == '\b') {
    bVar1 = bVar1 + 1;
  }
  if (bVar1 == 2) {
    sub_08159A60();
  }
  else if (bVar1 < 3) {
    if (bVar1 == 1) {
      sub_0815999C();
    }
  }
  else if (bVar1 == 3) {
    sub_08159BFC();
  }
                    /* WARNING: Could not recover jumptable at 0x08159998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815999C @ 0x0815999C

void sub_0815999C(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = DAT_0203b8fc;
  puVar5 = &DAT_0203b8fe;
  if (DAT_0203b8fe == '\b') {
    DAT_0203b8fc = DAT_0203b8f8;
    DAT_0203b8f8 = uVar1 & 0xff;
LAB_081599ec:
    uVar4 = 8;
    *puVar5 = DAT_0203b900;
    DAT_0203b900 = uVar4;
  }
  else {
    puVar5 = &DAT_0203b8ff;
    if (DAT_0203b8ff == '\b') {
      DAT_0203b8fc = DAT_0203b8fa;
      DAT_0203b8fa = uVar1 & 0xff;
      goto LAB_081599ec;
    }
  }
  uVar3 = DAT_0203b8fc;
  uVar2 = DAT_0203b8fa;
  uVar1 = DAT_0203b8f8;
  sub_08158A34();
  DAT_0203b8f8 = uVar1;
  DAT_0203b8fa = uVar2;
  DAT_0203b8fc = uVar3;
  if (DAT_0203b90a != -1) {
    sub_08159634((uint)DAT_0203b908,1);
    DAT_0203b8f8 = DAT_0203b908;
    DAT_0203b8fa = DAT_0203b8fc;
    sub_08158A34();
    if (DAT_0203b90a != -1) {
      sub_08158CBC();
      goto LAB_08159a52;
    }
  }
  sub_08158E00();
LAB_08159a52:
                    /* WARNING: Could not recover jumptable at 0x08159a5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08159A60 @ 0x08159A60

void sub_08159A60(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  byte *pbVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = DAT_0203b8f8;
  pbVar7 = &DAT_0203b8ff;
  if (DAT_0203b8ff == 8) {
    pbVar7 = &DAT_0203b900;
    if (DAT_0203b900 != 8) {
      DAT_0203b8f8 = DAT_0203b8fc;
      DAT_0203b8fc = uVar2 & 0xff;
      bVar6 = DAT_0203b900;
      goto LAB_08159aaa;
    }
  }
  else {
    DAT_0203b8f8 = DAT_0203b8fa;
    DAT_0203b8fa = uVar2 & 0xff;
    bVar6 = DAT_0203b8ff;
LAB_08159aaa:
    *pbVar7 = DAT_0203b8fe;
    DAT_0203b8fe = bVar6;
  }
  uVar1 = DAT_0203b8fc;
  uVar3 = DAT_0203b8fa;
  uVar2 = DAT_0203b8f8;
  if ((DAT_0203b8fa - 0x32 & 3) == (DAT_0203b8fc - 0x32 & 3)) {
    iVar4 = (DAT_0203b8fa - 0x32) * 0x10000;
    uVar5 = iVar4 >> 0x10;
    bVar6 = *(byte *)(((int)(uVar5 - (iVar4 >> 0x1f)) >> 1) + (uint)DAT_0203b8fe * 4 + 0x87f1611);
    if ((uVar5 & 1) == 0) {
      bVar6 = bVar6 >> 4;
    }
    uVar2 = bVar6 & 0xf;
    if ((bVar6 & 0xf) == 0) {
      uVar2 = uVar2 - 1;
    }
    iVar4 = (DAT_0203b8fc - 0x32) * 0x10000;
    uVar5 = iVar4 >> 0x10;
    bVar6 = *(byte *)(((int)(uVar5 - (iVar4 >> 0x1f)) >> 1) + (uint)DAT_0203b8fe * 4 + 0x87f1611);
    if ((uVar5 & 1) == 0) {
      bVar6 = bVar6 >> 4;
    }
    uVar3 = bVar6 & 0xf;
    if ((bVar6 & 0xf) == 0) {
      uVar3 = uVar3 - 1;
    }
    uVar5 = (int)(short)uVar2 + (int)(short)uVar3 + 1;
    iVar4 = (int)(uVar5 * 0x10000) >> 0x10;
    if (iVar4 < 0) {
      sub_08159690((uint)DAT_0203b8f8,-iVar4 & 0xffff);
      sub_08158CBC();
    }
    else if (iVar4 < 1) {
      DAT_0203b908 = DAT_0203b8f8;
      sub_08158CBC();
    }
    else {
      sub_08159634((uint)DAT_0203b8f8,uVar5 & 0xffff);
      sub_08158CBC();
    }
  }
  else {
    DAT_0203b8f8 = DAT_0203b8fc;
    uVar2 = uVar2 & 0xff;
    DAT_0203b8fc = uVar2;
    sub_08158A34();
    DAT_0203b8f8 = uVar1;
    DAT_0203b8fa = uVar3;
    DAT_0203b8fc = uVar2;
    if (DAT_0203b90a != -1) {
      sub_08159634((uint)DAT_0203b908,1);
      DAT_0203b8f8 = DAT_0203b908;
      DAT_0203b8fa = DAT_0203b8fc;
      sub_08158A34();
      if (DAT_0203b90a != -1) {
        sub_08158CBC();
        goto LAB_08159bec;
      }
    }
    sub_08158E00();
  }
LAB_08159bec:
                    /* WARNING: Could not recover jumptable at 0x08159bf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08159BFC @ 0x08159BFC

void sub_08159BFC(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = DAT_0203b8fc;
  uVar2 = DAT_0203b8fa;
  uVar1 = DAT_0203b8f8;
  if (DAT_0203b8f8 < 0x36) {
    if (DAT_0203b8fa < 0x36) {
      if (DAT_0203b8fc < 0x36) {
        uVar7 = 0x32;
        goto LAB_08159cee;
      }
      sub_08158A34();
      DAT_0203b8fc = uVar3;
      if (DAT_0203b90a == -1) {
        DAT_0203b8f8 = uVar1;
        DAT_0203b8fa = uVar2;
        sub_08158E00();
        goto LAB_08159d38;
      }
      DAT_0203b8f8 = DAT_0203b908;
      DAT_0203b8fa = uVar3;
      sub_08158A34();
      if (DAT_0203b90a == -1) {
        sub_08158E00();
        goto LAB_08159d38;
      }
      sub_08159634((uint)DAT_0203b908,1);
    }
    else {
      uVar1 = DAT_0203b8f8 & 0xff;
      DAT_0203b8f8 = DAT_0203b8fc;
      DAT_0203b8fc = uVar1;
      sub_08158A34();
      DAT_0203b8f8 = uVar3;
      if (DAT_0203b90a == -1) {
        DAT_0203b8fa = uVar2;
        DAT_0203b8fc = uVar1;
        sub_08158E00();
        goto LAB_08159d38;
      }
      DAT_0203b8f8 = DAT_0203b908;
      DAT_0203b8fa = uVar1;
      DAT_0203b8fc = uVar1;
      sub_08158A34();
      if (DAT_0203b90a == -1) {
        sub_08158E00();
        goto LAB_08159d38;
      }
      uVar7 = (uint)DAT_0203b908;
      sub_08159634(uVar7,1);
      if (DAT_0203b908 == uVar7) {
        DAT_0203b908 = 0xffff;
      }
    }
  }
  else {
    uVar7 = 0x36;
LAB_08159cee:
    sVar6 = (short)uVar7;
    iVar4 = uVar7 << 0x10;
    if ((uint)(iVar4 >> 0x10) < 0x3a) {
      do {
        sVar6 = (short)uVar7;
        uVar5 = iVar4 >> 0x10;
        if (((DAT_0203b8f8 != uVar5) && (DAT_0203b8fa != uVar5)) && (DAT_0203b8fc != uVar5)) break;
        uVar5 = uVar7 * 0x10000 + 0x10000;
        uVar7 = uVar5 >> 0x10;
        sVar6 = (short)(uVar5 >> 0x10);
        iVar4 = uVar7 << 0x10;
      } while (iVar4 >> 0x10 < 0x3a);
    }
    DAT_0203b908 = (ushort)(byte)(&UNK_087f1959)[sVar6];
  }
  sub_08158CBC();
LAB_08159d38:
                    /* WARNING: Could not recover jumptable at 0x08159d44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08159D50 @ 0x08159D50

void sub_08159D50(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  
  while( true ) {
    uVar3 = DAT_0203b8fc;
    uVar2 = DAT_0203b8fa;
    uVar1 = DAT_0203b8f8;
    DAT_03006a38 = 0;
    sub_08158A34();
    DAT_0203b8f8 = uVar1;
    DAT_0203b8fa = uVar2;
    DAT_0203b8fc = uVar3;
    if (DAT_0203b90a == -1) break;
    sub_08159634((uint)DAT_0203b908,1);
    DAT_0203b8f8 = DAT_0203b908;
    DAT_0203b8fa = DAT_0203b8fc;
    sub_08158A34();
    if (DAT_0203b90a == -1) break;
    iVar4 = sub_08158CBC();
    if (DAT_03006a38 == 0) {
      return;
    }
    if (iVar4 != 0) {
      return;
    }
  }
  sub_08158E00();
  return;
}


// sub_08159DF0 @ 0x08159DF0

void sub_08159DF0(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  
  while( true ) {
    uVar3 = DAT_0203b8fc;
    uVar2 = DAT_0203b8fa;
    uVar1 = DAT_0203b8f8;
    DAT_03006a38 = 0;
    DAT_0203b8f8 = DAT_0203b8fc;
    DAT_0203b8fc = uVar1;
    sub_08158A34();
    DAT_0203b8f8 = uVar3;
    DAT_0203b8fc = uVar1;
    DAT_0203b8fa = uVar2;
    if (DAT_0203b90a == -1) break;
    sub_08159634((uint)DAT_0203b908,1);
    DAT_0203b8f8 = DAT_0203b908;
    DAT_0203b8fa = DAT_0203b8fc;
    sub_08158A34();
    if (DAT_0203b90a == -1) break;
    iVar4 = sub_08158CBC();
    if (DAT_03006a38 == 0) {
      return;
    }
    if (iVar4 != 0) {
      return;
    }
  }
  sub_08158E00();
  return;
}


// sub_08159E9C @ 0x08159E9C

void sub_08159E9C(void)

{
  ushort *puVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  while( true ) {
    DAT_03006a38 = 0;
    DAT_0203b90c = DAT_0203b90c | 0x40;
    if (DAT_0203b904 < DAT_0203b905) break;
    if (DAT_0203b904 < DAT_0203b906) {
LAB_08159ee2:
      puVar1 = &DAT_0203b8fc;
      goto LAB_08159ee6;
    }
    sub_08159634((uint)DAT_0203b8f8,3);
    iVar2 = sub_08158CBC();
    if ((DAT_03006a38 == 0) || (iVar2 != 0)) goto LAB_08159f12;
  }
  if (DAT_0203b905 < DAT_0203b906) goto LAB_08159ee2;
  puVar1 = &DAT_0203b8fa;
LAB_08159ee6:
  sub_08159634((uint)*puVar1,3);
  iVar2 = sub_08158CBC();
LAB_08159f12:
                    /* WARNING: Could not recover jumptable at 0x08159f16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(iVar2);
  return;
}


// sub_08159F18 @ 0x08159F18

/* WARNING: Restarted to delay deadcode elimination for space: ram */

void sub_08159F18(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  byte bVar5;
  
  bVar5 = DAT_0203b901 == '\v';
  if (DAT_0203b902 == '\v') {
    bVar5 = bVar5 + 1;
  }
  if (DAT_0203b903 == '\v') {
    bVar5 = bVar5 + 1;
  }
  if (bVar5 < 2) {
    DAT_0203b90c = DAT_0203b90c | 8;
    DAT_0203b90e = DAT_0203b90e & 3 | 0x30;
    if (DAT_0203b901 != '\v') {
      if (DAT_0203b902 == '\v') {
        sub_0815A060(1,0);
      }
      else if (DAT_0203b903 == '\v') {
        sub_0815A060(2,0);
      }
    }
    if (DAT_0203b906 <= DAT_0203b905) {
      sub_0815A060(1,2);
    }
    do {
      uVar3 = DAT_0203b8fc;
      uVar2 = DAT_0203b8fa;
      uVar1 = DAT_0203b8f8;
      iVar4 = sub_08158A34();
      DAT_0203b8fc = uVar3;
      DAT_0203b8fa = uVar2;
      DAT_0203b8f8 = uVar1;
    } while (iVar4 == 0);
    DAT_0203b8f8 = DAT_0203b908;
    DAT_0203b8fa = uVar3;
    iVar4 = sub_08158A34();
    if ((((iVar4 != 0) && (sub_08159634((uint)DAT_0203b908,1), DAT_0203b908 != DAT_0203b8f2)) &&
        (DAT_0203b908 != DAT_0203b8f4)) && (DAT_0203b908 != DAT_0203b8f6)) {
      DAT_0203b90e = 0x30;
      iVar4 = sub_0815BA28((uint)DAT_0203b908);
      if (iVar4 != 0) {
        sub_08158CBC();
        goto LAB_0815a050;
      }
    }
    DAT_0203b90e = 0x30;
    sub_08158CA4();
  }
  else {
    sub_08158E00();
  }
LAB_0815a050:
                    /* WARNING: Could not recover jumptable at 0x0815a05a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815A060 @ 0x0815A060

void sub_0815A060(undefined4 arg0,undefined4 arg1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined1 *unaff_r4;
  undefined1 *unaff_r5;
  undefined2 *unaff_r6;
  undefined2 *unaff_r7;
  
  if ((short)arg0 == 0) {
    unaff_r5 = (undefined1 *)0x203b901;
  }
  if ((short)arg0 == 1) {
    unaff_r5 = (undefined1 *)0x203b902;
  }
  if ((short)arg0 == 2) {
    unaff_r5 = (undefined1 *)0x203b903;
  }
  if ((short)arg1 == 0) {
    unaff_r4 = (undefined1 *)0x203b901;
  }
  if ((short)arg1 == 1) {
    unaff_r4 = (undefined1 *)0x203b902;
  }
  if ((short)arg1 == 2) {
    unaff_r4 = (undefined1 *)0x203b903;
  }
  uVar1 = *unaff_r4;
  *unaff_r4 = *unaff_r5;
  *unaff_r5 = uVar1;
  if ((short)arg0 == 0) {
    unaff_r5 = (undefined1 *)0x203b8fe;
  }
  if ((short)arg0 == 1) {
    unaff_r5 = (undefined1 *)0x203b8ff;
  }
  if ((short)arg0 == 2) {
    unaff_r5 = (undefined1 *)0x203b900;
  }
  if ((short)arg1 == 0) {
    unaff_r4 = (undefined1 *)0x203b8fe;
  }
  if ((short)arg1 == 1) {
    unaff_r4 = (undefined1 *)0x203b8ff;
  }
  if ((short)arg1 == 2) {
    unaff_r4 = (undefined1 *)0x203b900;
  }
  uVar1 = *unaff_r4;
  *unaff_r4 = *unaff_r5;
  *unaff_r5 = uVar1;
  if ((short)arg0 == 0) {
    unaff_r5 = (undefined1 *)0x203b904;
  }
  if ((short)arg0 == 1) {
    unaff_r5 = (undefined1 *)0x203b905;
  }
  if ((short)arg0 == 2) {
    unaff_r5 = (undefined1 *)0x203b906;
  }
  if ((short)arg1 == 0) {
    unaff_r4 = (undefined1 *)0x203b904;
  }
  if ((short)arg1 == 1) {
    unaff_r4 = (undefined1 *)0x203b905;
  }
  if ((short)arg1 == 2) {
    unaff_r4 = (undefined1 *)0x203b906;
  }
  uVar1 = *unaff_r4;
  *unaff_r4 = *unaff_r5;
  *unaff_r5 = uVar1;
  if ((short)arg0 == 0) {
    unaff_r7 = (undefined2 *)0x203b8f8;
  }
  if ((short)arg0 == 1) {
    unaff_r7 = (undefined2 *)0x203b8fa;
  }
  if ((short)arg0 == 2) {
    unaff_r7 = (undefined2 *)0x203b8fc;
  }
  if ((short)arg1 == 0) {
    unaff_r6 = (undefined2 *)0x203b8f8;
  }
  if ((short)arg1 == 1) {
    unaff_r6 = (undefined2 *)0x203b8fa;
  }
  if ((short)arg1 == 2) {
    unaff_r6 = (undefined2 *)0x203b8fc;
  }
  uVar2 = *unaff_r6;
  *unaff_r6 = *unaff_r7;
  *unaff_r7 = uVar2;
  return;
}


// sub_0815A150 @ 0x0815A150

void sub_0815A150(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  char cVar4;
  
  cVar4 = DAT_0203b8fe == '\x16';
  if (DAT_0203b8ff == '\x16') {
    cVar4 = cVar4 + '\x01';
  }
  if (DAT_0203b900 == '\x16') {
    cVar4 = cVar4 + '\x01';
  }
  if (cVar4 == '\x03') {
    sub_0815A2F4();
  }
  else if (cVar4 == '\x02') {
    sub_0815A230();
  }
  else {
    if (DAT_0203b8fe == '\x16') {
      sub_0815A060(0,2);
    }
    else if (DAT_0203b8ff == '\x16') {
      sub_0815A060(1,2);
    }
    uVar3 = DAT_0203b8fc;
    uVar2 = DAT_0203b8fa;
    uVar1 = DAT_0203b8f8;
    sub_08158A34();
    DAT_0203b8f8 = uVar1;
    DAT_0203b8fa = uVar2;
    DAT_0203b8fc = uVar3;
    if (DAT_0203b90a != -1) {
      DAT_0203b8f8 = DAT_0203b908;
      DAT_0203b8fa = uVar3;
      sub_08158A34();
      if (DAT_0203b90a != -1) {
        sub_08159634((uint)DAT_0203b908,1);
        sub_08158CBC();
        goto LAB_0815a220;
      }
    }
    sub_08158E00();
  }
LAB_0815a220:
                    /* WARNING: Could not recover jumptable at 0x0815a22c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815A230 @ 0x0815A230

void sub_0815A230(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  if (DAT_0203b8fe == '\x16') {
    if (DAT_0203b8ff == '\x16') {
      sub_0815A060(0,2);
    }
    else {
      sub_0815A060(0,1);
    }
  }
  if (DAT_0203b905 < DAT_0203b906) {
    sub_0815A060(1,2);
  }
  uVar3 = DAT_0203b8fc;
  uVar2 = DAT_0203b8fa;
  uVar1 = DAT_0203b8f8;
  sub_08158A34();
  DAT_0203b8f8 = uVar1;
  DAT_0203b8fa = uVar2;
  DAT_0203b8fc = uVar3;
  if (DAT_0203b90a != -1) {
    DAT_0203b8f8 = DAT_0203b908;
    DAT_0203b8fa = uVar3;
    sub_08158A34();
    if (DAT_0203b90a != -1) {
      sub_08159634((uint)DAT_0203b908,1);
      sub_08158CBC();
      return;
    }
  }
  sub_08158E00();
  return;
}


// sub_0815A2F4 @ 0x0815A2F4

void sub_0815A2F4(void)

{
  DAT_0203b908 = 0x35;
  sub_08158CBC();
  return;
}


// sub_0815A30C @ 0x0815A30C

/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 sub_0815A30C(void)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  code *UNRECOVERED_JUMPTABLE;
  uint uStack_28;
  
  bVar3 = DAT_0203b8ff;
  uVar13 = (uint)(DAT_0203b8fe < 0xd);
  if (DAT_0203b8ff < 0xd) {
    uVar13 = uVar13 * 0x10000 + 0x10000 >> 0x10;
  }
  if (DAT_0203b900 < 0xd) {
    uVar13 = uVar13 * 0x10000 + 0x10000 >> 0x10;
  }
  uVar12 = (uint)DAT_0203b905;
  uVar11 = (uint)DAT_0203b906;
  uVar9 = __divsi3(DAT_0203b904 + uVar12 + uVar11,3);
  bVar5 = DAT_0203b906;
  bVar4 = DAT_0203b903;
  uVar1 = DAT_0203b8fc;
  uStack_28 = (int)(short)uVar9 + ((int)(uVar13 * 0x40000 - 0x40000) >> 0x10) & 0xffff;
  if (uVar12 < uVar11) {
    DAT_0203b8ff = DAT_0203b900;
    DAT_0203b900 = bVar3;
    DAT_0203b903 = DAT_0203b902;
    DAT_0203b902 = bVar4;
    DAT_0203b906 = DAT_0203b905;
    DAT_0203b905 = bVar5;
    DAT_0203b8fc = DAT_0203b8fa;
    DAT_0203b8fa = uVar1;
  }
  else if ((uVar11 == uVar12) && (DAT_0203b8fc < DAT_0203b8fa)) {
    DAT_0203b8ff = DAT_0203b900;
    DAT_0203b900 = bVar3;
    DAT_0203b903 = DAT_0203b902;
    DAT_0203b902 = bVar4;
    DAT_0203b906 = DAT_0203b905;
    DAT_0203b905 = bVar5;
    DAT_0203b8fc = DAT_0203b8fa;
    DAT_0203b8fa = uVar1;
  }
  bVar8 = DAT_0203b906;
  bVar7 = DAT_0203b905;
  bVar6 = DAT_0203b903;
  bVar5 = DAT_0203b902;
  bVar4 = DAT_0203b900;
  bVar3 = DAT_0203b8ff;
  uVar2 = DAT_0203b8fc;
  uVar1 = DAT_0203b8fa;
  if (DAT_0203b904 < DAT_0203b905) {
    DAT_0203b8ff = DAT_0203b8fe;
    DAT_0203b8fe = bVar3;
    DAT_0203b902 = DAT_0203b901;
    DAT_0203b901 = bVar5;
    DAT_0203b905 = DAT_0203b904;
    DAT_0203b904 = bVar7;
    DAT_0203b8fa = DAT_0203b8f8;
    DAT_0203b8f8 = uVar1;
  }
  else if ((DAT_0203b905 == DAT_0203b904) && (DAT_0203b8fa < DAT_0203b8f8)) {
    DAT_0203b8ff = DAT_0203b8fe;
    DAT_0203b8fe = bVar3;
    DAT_0203b902 = DAT_0203b901;
    DAT_0203b901 = bVar5;
    DAT_0203b905 = DAT_0203b904;
    DAT_0203b904 = bVar7;
    DAT_0203b8fa = DAT_0203b8f8;
    DAT_0203b8f8 = uVar1;
  }
  if (DAT_0203b905 < DAT_0203b906) {
    DAT_0203b900 = DAT_0203b8ff;
    DAT_0203b8ff = bVar4;
    DAT_0203b903 = DAT_0203b902;
    DAT_0203b902 = bVar6;
    DAT_0203b906 = DAT_0203b905;
    DAT_0203b905 = bVar8;
    DAT_0203b8fc = DAT_0203b8fa;
    DAT_0203b8fa = uVar2;
  }
  else if ((DAT_0203b906 == DAT_0203b905) && (DAT_0203b8fc < DAT_0203b8fa)) {
    DAT_0203b900 = DAT_0203b8ff;
    DAT_0203b8ff = bVar4;
    DAT_0203b903 = DAT_0203b902;
    DAT_0203b902 = bVar6;
    DAT_0203b906 = DAT_0203b905;
    DAT_0203b905 = bVar8;
    DAT_0203b8fc = DAT_0203b8fa;
    DAT_0203b8fa = uVar2;
  }
  if ((DAT_0203b901 != DAT_0203b902) || (DAT_0203b901 != DAT_0203b903)) {
    sub_0815B9B8((uint)DAT_0203b8fa,&DAT_0203b902,&DAT_0203b8ff);
    sub_0815B9B8((uint)DAT_0203b8fc,&DAT_0203b903,&DAT_0203b900);
    uVar13 = (uint)*(byte *)((uint)DAT_0203b902 * 0xc + (uint)DAT_0203b903 + 0x87f1993);
    if (uVar13 != 0xff) {
      sub_0815B9B8((uint)DAT_0203b8f8,&DAT_0203b901,&DAT_0203b8fe);
      DAT_0203b90a = *(char *)(uVar13 + (uint)DAT_0203b901 * 0x16 + 0x87f1a23);
      if (DAT_0203b90a == -1) {
        DAT_0203b90c = DAT_0203b90c | 8;
        DAT_0203b90e = DAT_0203b90e & 3 | 0x30;
        do {
          do {
            uVar13 = sub_08159144();
          } while ((uVar13 & 0xffff) == 0xff);
          DAT_0203b908 = (ushort)uVar13;
          iVar10 = sub_0815BA28(uVar13 & 0xffff);
        } while ((((iVar10 == 0) ||
                  (uVar13 = sub_0815B9A0((uint)DAT_0203b908), (uint)DAT_030046cd <= (uVar13 & 0xff))
                  ) || (iVar10 = sub_08158CBC(), iVar10 == 0)) || (0xfe < DAT_0203b908));
      }
      else {
        while( true ) {
          iVar10 = sub_08159438(uStack_28);
          if (-1 < iVar10 * 0x10000) break;
          uStack_28 = uStack_28 * 0x10000 + 0x10000 >> 0x10;
        }
        sub_08158CBC();
      }
      goto LAB_0815a658;
    }
  }
  sub_0815A670();
LAB_0815a658:
                    /* WARNING: Could not recover jumptable at 0x0815a666. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar9 = (*UNRECOVERED_JUMPTABLE)();
  return uVar9;
}


// sub_0815A670 @ 0x0815A670

void sub_0815A670(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  uVar3 = DAT_0203b8fc;
  uVar2 = DAT_0203b8fa;
  uVar1 = DAT_0203b8f8;
  DAT_0203b8fc = DAT_0203b8f8;
  DAT_0203b8f8 = uVar3;
  sub_08158A34();
  DAT_0203b8f8 = uVar3;
  DAT_0203b8fc = uVar1;
  DAT_0203b8fa = uVar2;
  if (DAT_0203b90a != -1) {
    DAT_0203b8f8 = DAT_0203b908;
    DAT_0203b8fa = uVar1;
    sub_08158A34();
    if (DAT_0203b90a != -1) {
      sub_08159634((uint)DAT_0203b908,1);
      sub_08158CBC();
      return;
    }
  }
  sub_08158E00();
  return;
}


// sub_0815A6F0 @ 0x0815A6F0

/* WARNING: Restarted to delay deadcode elimination for space: ram */

void sub_0815A6F0(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar5 = (uint)DAT_0203b908;
  iVar2 = sub_080BF648(uVar5);
  DAT_0203b8e8 = *(byte *)(iVar2 + 0x1e) & 0xf;
  DAT_0203bab8 = -1;
  DAT_0203bab9 = 0xff;
  DAT_0203bad8 = -1;
  DAT_0203bad9 = 0xff;
  DAT_0203b8e9 = '\0';
  DAT_0203b8ea = '\0';
  uVar4 = 0;
  do {
    iVar2 = sub_080BF648(uVar5);
    DAT_0203b8eb = *(byte *)(iVar2 + 0x11 + uVar4);
    if (DAT_0203b8eb != 0xff) {
      if (DAT_0203b8eb < 0x40) {
        uVar3 = sub_0815AE68((uint)DAT_0203b8eb);
        if (((uVar3 & 0xffff) != 0xf) && ((uVar3 & 0xffff) == (uint)DAT_0203b8e8)) {
          (&DAT_0203bab8)[DAT_0203b8e9] = DAT_0203b8eb;
          (&DAT_0203bab9)[DAT_0203b8e9] = 0xff;
          DAT_0203b8e9 = DAT_0203b8e9 + '\x01';
          goto LAB_0815a7e6;
        }
      }
      (&DAT_0203bad8)[DAT_0203b8ea] = DAT_0203b8eb;
      (&DAT_0203bad9)[DAT_0203b8ea] = 0xff;
      DAT_0203b8ea = DAT_0203b8ea + '\x01';
    }
LAB_0815a7e6:
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 6);
  DAT_0203b8e9 = '\0';
  DAT_0203b8ea = '\0';
  DAT_0203b918 = -1;
  DAT_0203b919 = 0xff;
  DAT_0203b9e8 = 0xff;
  DAT_0203b9e9 = 0xff;
  DAT_0203baf8 = 0xff;
  DAT_0203baf9 = 0xff;
  sub_0815ABA8((uint)DAT_0203b8fc);
  sub_0815ABA8((uint)DAT_0203b8fa);
  sub_0815ABA8((uint)DAT_0203b8f8);
  if (DAT_0203b8e9 == '\0') {
    sub_0815A99C();
  }
  else {
    uVar4 = 0;
    cVar1 = DAT_0203bab8;
    while (cVar1 != -1) {
      (&DAT_0203b9e8)[DAT_0203b8e9] = (&DAT_0203bab8)[uVar4];
      (&DAT_0203b9e9)[DAT_0203b8e9] = 0xff;
      DAT_0203b8e9 = DAT_0203b8e9 + '\x01';
      uVar4 = uVar4 + 1 & 0xffff;
      cVar1 = (&DAT_0203bab8)[uVar4];
    }
    sub_0815AB38(&DAT_0203b9e8);
    uVar4 = 0;
    uVar5 = 0;
    cVar1 = DAT_0203bad8;
    while (cVar1 != -1) {
      (&DAT_0203b918)[uVar5] = (&DAT_0203bad8)[uVar4];
      (&DAT_0203b919)[uVar5] = 0xff;
      uVar4 = uVar4 + 1 & 0xffff;
      uVar5 = uVar5 + 1 & 0xffff;
      cVar1 = (&DAT_0203bad8)[uVar4];
    }
    uVar4 = 0;
    cVar1 = DAT_0203b918;
    while (cVar1 != -1) {
      uVar4 = uVar4 + 1 & 0xffff;
      cVar1 = (&DAT_0203b918)[uVar4];
    }
    uVar5 = 0;
    while (uVar4 != 6) {
      if ((&DAT_0203b9e8)[uVar5] == -1) {
        sub_0815AA30();
        goto LAB_0815a984;
      }
      *(undefined1 *)(uVar4 + 0x203b918) = (&DAT_0203b9e8)[uVar5];
      (&DAT_0203b919)[uVar4] = 0xff;
      uVar5 = uVar5 + 1 & 0xffff;
      sub_0815AAC8(0x203b918);
      uVar4 = 0;
      cVar1 = DAT_0203b918;
      while (cVar1 != -1) {
        uVar4 = uVar4 + 1 & 0xffff;
        cVar1 = *(char *)(uVar4 + 0x203b918);
      }
    }
    uRam0203b91e = 0xff;
    sub_0815AAC4();
  }
LAB_0815a984:
                    /* WARNING: Could not recover jumptable at 0x0815a992. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815A99C @ 0x0815A99C

void sub_0815A99C(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  sub_0815AB38(&DAT_0203baf8);
  uVar3 = 0;
  uVar2 = 0;
  cVar1 = DAT_0203bad8;
  while (cVar1 != -1) {
    (&DAT_0203b918)[uVar2] = *(undefined1 *)(uVar3 + 0x203bad8);
    (&DAT_0203b919)[uVar2] = 0xff;
    uVar3 = uVar3 + 1 & 0xff;
    uVar2 = uVar2 + 1 & 0xff;
    cVar1 = *(char *)(uVar3 + 0x203bad8);
  }
  uVar3 = 0;
  cVar1 = DAT_0203bab8;
  while (cVar1 != -1) {
    (&DAT_0203b918)[uVar2] = (&DAT_0203bab8)[uVar3];
    (&DAT_0203b919)[uVar2] = 0xff;
    uVar3 = uVar3 + 1 & 0xff;
    uVar2 = uVar2 + 1 & 0xff;
    cVar1 = (&DAT_0203bab8)[uVar3];
  }
  sub_0815AA30();
  return;
}


// sub_0815AA30 @ 0x0815AA30

void sub_0815AA30(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  sub_0815AB38(&DAT_0203baf8);
  sub_0815AAC8(&DAT_0203b918);
  uVar3 = 0;
  cVar1 = DAT_0203b918;
  while (cVar1 != -1) {
    uVar3 = uVar3 + 1 & 0xff;
    cVar1 = (&DAT_0203b918)[uVar3];
  }
  if (uVar3 < 6) {
    iVar2 = 0x20;
    cVar1 = DAT_0203baf8;
    while (cVar1 != -1) {
      (&DAT_0203b918)[uVar3] = (&DAT_0203bad8)[iVar2];
      uVar4 = uVar4 + 1 & 0xff;
      uVar3 = uVar3 + 1 & 0xff;
      if (5 < uVar3) break;
      iVar2 = uVar4 + 0x20;
      cVar1 = (&DAT_0203baf8)[uVar4];
    }
  }
  (&DAT_0203b918)[uVar3] = 0xff;
  sub_0815AAC4();
  return;
}


// sub_0815AAC4 @ 0x0815AAC4

void sub_0815AAC4(void)

{
  return;
}


// sub_0815AAC8 @ 0x0815AAC8

void sub_0815AAC8(char *arg0)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((*arg0 != -1) && (arg0[1] != -1)) {
    uVar7 = 0;
    uVar8 = 0;
LAB_0815aadc:
    do {
      cVar1 = arg0[uVar7 + 1];
      while (cVar1 != -1) {
        pbVar5 = (byte *)(arg0 + uVar8);
        bVar2 = arg0[uVar7 + 1];
        uVar6 = uVar7;
        if (*pbVar5 == bVar2) goto LAB_0815aaf8;
        if (bVar2 < *pbVar5) {
          bVar3 = *pbVar5;
          *pbVar5 = bVar2;
          arg0[uVar7 + 1] = bVar3;
        }
        uVar7 = uVar7 + 1 & 0xff;
        cVar1 = arg0[uVar7 + 1];
      }
      uVar7 = uVar8 + 1 & 0xff;
      uVar8 = uVar7;
    } while (arg0[uVar7 + 1] != -1);
  }
                    /* WARNING: Could not recover jumptable at 0x0815ab36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
LAB_0815aaf8:
  do {
    iVar4 = uVar6 + 2;
    arg0[uVar6 + 1] = arg0[iVar4];
    uVar6 = uVar6 + 1 & 0xff;
  } while (arg0[iVar4] != -1);
  goto LAB_0815aadc;
}


// sub_0815AB38 @ 0x0815AB38

void sub_0815AB38(char *arg0)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((*arg0 != -1) && (arg0[1] != -1)) {
    uVar6 = 0;
    uVar7 = 0;
LAB_0815ab4c:
    do {
      cVar1 = arg0[uVar6 + 1];
      while (cVar1 != -1) {
        bVar2 = arg0[uVar6 + 1];
        bVar3 = arg0[uVar7];
        uVar5 = uVar6;
        if (bVar3 == bVar2) goto LAB_0815ab90;
        if (bVar3 < bVar2) {
          arg0[uVar7] = bVar2;
          arg0[uVar6 + 1] = bVar3;
        }
        uVar6 = uVar6 + 1 & 0xff;
        cVar1 = arg0[uVar6 + 1];
      }
      uVar6 = uVar7 + 1 & 0xff;
      uVar7 = uVar6;
    } while (arg0[uVar6 + 1] != -1);
  }
                    /* WARNING: Could not recover jumptable at 0x0815aba6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
LAB_0815ab90:
  do {
    iVar4 = uVar5 + 2;
    arg0[uVar5 + 1] = arg0[iVar4];
    uVar5 = uVar5 + 1 & 0xff;
  } while (arg0[iVar4] != -1);
  goto LAB_0815ab4c;
}


// sub_0815ABA8 @ 0x0815ABA8

void sub_0815ABA8(uint arg0)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  
  if (((arg0 & 0xffff) != 0xffff) && (iVar2 = sub_080C3560(arg0 & 0xffff), iVar2 != 0)) {
    iVar3 = sub_080BF648(arg0 & 0xff);
    if (*(byte *)(iVar3 + 0x1e) == DAT_0203b8e8) {
      uVar1 = 0;
      do {
        switch(uVar1) {
        default:
          pbVar5 = (byte *)(iVar2 + 0x5d);
          break;
        case 1:
          pbVar5 = (byte *)(iVar2 + 0x5e);
          break;
        case 2:
          pbVar5 = (byte *)(iVar2 + 0x5f);
          break;
        case 3:
          pbVar5 = (byte *)(iVar2 + 0x60);
          break;
        case 4:
          pbVar5 = (byte *)(iVar2 + 0x61);
          break;
        case 5:
          pbVar5 = (byte *)(iVar2 + 0x62);
        }
        DAT_0203b8eb = *pbVar5;
        if (((DAT_0203b8eb < 0x40) &&
            (uVar4 = sub_0815AE68((uint)DAT_0203b8eb), (uVar4 & 0xffff) == (uint)DAT_0203b8e8)) &&
           (iVar3 = sub_0815ADCC(), iVar3 == 0)) {
          (&DAT_0203b9e8)[DAT_0203b8e9] = DAT_0203b8eb;
          (&DAT_0203b9e9)[DAT_0203b8e9] = 0xff;
          DAT_0203b8e9 = DAT_0203b8e9 + '\x01';
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 6);
    }
    uVar1 = 0;
    do {
      switch(uVar1) {
      default:
        pbVar5 = (byte *)(iVar2 + 0x5d);
        break;
      case 1:
        pbVar5 = (byte *)(iVar2 + 0x5e);
        break;
      case 2:
        pbVar5 = (byte *)(iVar2 + 0x5f);
        break;
      case 3:
        DAT_0203b8eb = *(byte *)(iVar2 + 0x60);
        goto LAB_0815ad2c;
      case 4:
        pbVar5 = (byte *)(iVar2 + 0x61);
        break;
      case 5:
        pbVar5 = (byte *)(iVar2 + 0x62);
      }
      DAT_0203b8eb = *pbVar5;
LAB_0815ad2c:
      if ((((byte)(DAT_0203b8eb - 0x24) < 0x16) &&
          (iVar3 = sub_0815AD8C((uint)DAT_0203b8eb), iVar3 == 0)) &&
         (iVar3 = sub_0815AE18(), iVar3 == 0)) {
        (&DAT_0203baf8)[DAT_0203b8ea] = DAT_0203b8eb;
        (&DAT_0203baf9)[DAT_0203b8ea] = 0xff;
        DAT_0203b8ea = DAT_0203b8ea + '\x01';
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 6);
  }
  return;
}


// sub_0815AD8C @ 0x0815AD8C

undefined4 sub_0815AD8C(undefined4 arg0)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  cVar1 = DAT_0203bad8;
  while( true ) {
    if (cVar1 == -1) {
      return 0;
    }
    if (cVar1 == (char)arg0) break;
    uVar2 = uVar2 + 1 & 0xff;
    if (5 < uVar2) {
      return 0;
    }
    cVar1 = (&DAT_0203bad8)[uVar2];
  }
  return 1;
}


// sub_0815ADCC @ 0x0815ADCC

undefined4 sub_0815ADCC(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = (uint)DAT_0203b8e9;
  if (DAT_0203b8e9 == 0) {
LAB_0815ae12:
    uVar2 = 0;
  }
  else {
    do {
      iVar1 = (uVar3 - 1) * 0x1000000;
      if (iVar1 < 0) goto LAB_0815ae12;
      uVar3 = iVar1 >> 0x18;
    } while ((&DAT_0203b9e8)[uVar3] != DAT_0203b8eb);
    uVar2 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0815ae16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_0815AE18 @ 0x0815AE18

undefined4 sub_0815AE18(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = (uint)DAT_0203b8ea;
  if (DAT_0203b8ea == 0) {
LAB_0815ae62:
    uVar2 = 0;
  }
  else {
    do {
      iVar1 = (uVar3 - 1) * 0x1000000;
      if (iVar1 < 0) goto LAB_0815ae62;
      uVar3 = iVar1 >> 0x18;
    } while ((&DAT_0203baf8)[uVar3] != DAT_0203b8eb);
    uVar2 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0815ae66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_0815AE68 @ 0x0815AE68

uint sub_0815AE68(uint arg0)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)sub_080BF5C0(arg0 & 0xff);
  return *pbVar1 & 0xf;
}


// sub_0815AE84 @ 0x0815AE84

undefined4 sub_0815AE84(void)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  DAT_0203b8f2 = DAT_0203b8f8;
  DAT_0203b8f4 = DAT_0203b8fa;
  DAT_0203b8f6 = DAT_0203b8fc;
  uVar1 = (uint)DAT_0203b8fc;
  if (uVar1 == 0xffff) {
    sub_0815B08C();
  }
  else {
    uVar1 = (uint)DAT_0203b8fa;
    if (uVar1 == 0xffff) {
      sub_0815AFB0();
    }
    else {
      uVar1 = sub_0815AF00();
    }
  }
  DAT_0203b8f8 = DAT_0203b8f2;
  DAT_0203b8fa = DAT_0203b8f4;
  DAT_0203b8fc = DAT_0203b8f6;
                    /* WARNING: Could not recover jumptable at 0x0815aef8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar2;
}


// sub_0815AF00 @ 0x0815AF00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 sub_0815AF00(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if ((byte)(&DAT_087f1c55)[uVar1] == DAT_0203b8fc) {
      if (((*(byte *)(uVar1 + 0x87f1c53) == DAT_0203b8f8) &&
          ((byte)(&DAT_087f1c54)[uVar1] == DAT_0203b8fa)) ||
         ((*(byte *)(uVar1 + 0x87f1c53) == DAT_0203b8fa &&
          ((byte)(&DAT_087f1c54)[uVar1] == DAT_0203b8f8)))) {
        DAT_0203b908 = (ushort)(byte)(&DAT_087f1c56)[uVar1];
        _DAT_0203baf8 = (ushort)(byte)(&DAT_087f1c56)[uVar1];
        return 1;
      }
    }
    uVar1 = uVar1 + 4 & 0xffff;
    if (0x77 < uVar1) {
      _DAT_0203baf8 = 0xff;
      DAT_0203b908 = _DAT_0203baf8;
      return 0;
    }
  } while( true );
}


// sub_0815AFB0 @ 0x0815AFB0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0815AFB0(void)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (DAT_0203b8f8 - 0x40) * 0xa0000;
  uVar2 = 0;
  do {
    uVar4 = uVar3 >> 0x10;
    bVar1 = *(byte *)(uVar4 + 0x87f1b13);
    if ((bVar1 & 0x80) == 0) {
      if (bVar1 == DAT_0203b8fc) {
        bVar1 = *(byte *)(uVar4 + 0x87f1bb3);
        goto LAB_0815b044;
      }
    }
    else {
      _DAT_0203baf8 = (ushort)(uVar3 >> 0x10);
      DAT_0203b90a = bVar1 & 0x3f;
      uVar3 = sub_0815B9DC((uint)DAT_0203b8fc);
      if ((uVar3 & 0xffff) == (uint)DAT_0203b90a) {
        bVar1 = *(byte *)(_DAT_0203baf8 + 0x87f1bb3);
LAB_0815b044:
        _DAT_0203baf8 = (ushort)bVar1;
        DAT_0203b908 = (ushort)bVar1;
        return;
      }
      uVar4 = (uint)_DAT_0203baf8;
    }
    uVar3 = (uVar4 + 1) * 0x10000;
    uVar2 = uVar2 + 1;
    if (4 < uVar2) {
      _DAT_0203baf8 = 0xff;
      DAT_0203b90e = 0x40;
      DAT_0203b908 = 0xff;
      return;
    }
  } while( true );
}


// sub_0815B08C @ 0x0815B08C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0815B08C(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 5;
  do {
    iVar1 = ((DAT_0203b8f8 - 0x40) * 0xa0000 >> 0x10) + uVar2;
    if (*(byte *)(iVar1 + 0x87f1b13) == DAT_0203b8fa) {
      DAT_0203b908 = (ushort)*(byte *)(iVar1 + 0x87f1bb3);
      _DAT_0203baf8 = DAT_0203b908;
      return;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 10);
  _DAT_0203baf8 = 0xff;
  DAT_0203b90e = 0x40;
  DAT_0203b908 = _DAT_0203baf8;
  return;
}


// sub_0815B11C @ 0x0815B11C

undefined4 sub_0815B11C(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  ushort uVar6;
  uint unaff_r6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_080C2244();
  iVar3 = sub_080C2340(0xd8);
  if ((iVar3 == 0) && ((uVar2 & 0xff) != 0)) {
    uVar1 = 0xffff;
    goto LAB_0815b23c;
  }
  DAT_0203b90c = DAT_0203b90c | 4;
  if (DAT_0203b8f6 == -1) {
    if (DAT_030046cd < 0x3b) {
      DAT_0203b904 = DAT_030046cd + 0x10;
    }
    else {
      DAT_0203b904 = 0x4b;
    }
    if (DAT_0203b904 < 0x1a) {
LAB_0815b1c2:
      DAT_0203b905 = 0;
    }
    else {
      DAT_0203b905 = DAT_0203b904 - 0x19;
    }
  }
  else {
    if (DAT_030046cd < 0x31) {
      DAT_0203b904 = DAT_030046cd + 0x1a;
    }
    else {
      DAT_0203b904 = 0x4b;
    }
    if (DAT_0203b904 < 0x29) goto LAB_0815b1c2;
    DAT_0203b905 = DAT_0203b904 - 0x28;
  }
  do {
    uVar1 = 0;
    do {
      uVar2 = sub_08159144();
      uVar2 = uVar2 & 0xffff;
      if ((uVar2 != 0xff) && (iVar3 = sub_0815BA28(uVar2), unaff_r6 = uVar2, iVar3 != 0)) {
        uVar4 = sub_0815B9A0(uVar2);
        if (((uVar4 & 0xff) < (uint)DAT_0203b904) &&
           (((uint)DAT_0203b905 <= (uVar4 & 0xff) && (iVar3 = sub_080C3560(uVar2), iVar3 == 0))))
        break;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x20);
    uVar6 = (ushort)unaff_r6;
    if (uVar1 != 0x20) break;
    unaff_r6 = 0xfb;
    uVar6 = 0xfb;
    iVar3 = sub_080C3560(0xfb);
  } while (iVar3 != 0);
  DAT_0203b908 = uVar6;
  uVar5 = sub_0815B9DC((uint)uVar6);
  DAT_0203b90a = (undefined1)uVar5;
  uVar1 = DAT_0203b908;
LAB_0815b23c:
                    /* WARNING: Could not recover jumptable at 0x0815b240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar5;
}


// sub_0815B248 @ 0x0815B248

void sub_0815B248(void)

{
  return;
}


// sub_0815B24C @ 0x0815B24C

void sub_0815B24C(void)

{
  sub_080C3560((uint)DAT_0203b90d);
  return;
}


// sub_0815B260 @ 0x0815B260

void sub_0815B260(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar5 = DAT_0203b8fc;
  uVar3 = DAT_0203b8fa;
  uVar1 = DAT_0203b8f8;
  DAT_0203b8f2 = DAT_0203b8f8;
  DAT_0203b8f4 = DAT_0203b8fa;
  DAT_0203b8f6 = DAT_0203b8fc;
  if ((uint)DAT_0203b8fa * 0x10000 <= (uint)DAT_0203b8f8 * 0x10000 &&
      (uint)DAT_0203b8f8 * 0x10000 + (uint)DAT_0203b8fa * -0x10000 != 0) {
    DAT_0203b8f8 = DAT_0203b8fa;
    DAT_0203b8fa = uVar1;
  }
  uVar4 = DAT_0203b8fa;
  uVar2 = DAT_0203b8f8;
  if (DAT_0203b8fc < DAT_0203b8f8) {
    DAT_0203b8f8 = DAT_0203b8fc;
    DAT_0203b8fc = uVar2;
  }
  if (DAT_0203b8fc < DAT_0203b8fa) {
    DAT_0203b8fa = DAT_0203b8fc;
    DAT_0203b8fc = uVar4;
  }
  if (DAT_0203b908 == 0xffff) {
    uVar8 = 0;
    DAT_0203b8f8 = uVar1;
    DAT_0203b8fa = uVar3;
    DAT_0203b8fc = uVar5;
  }
  else {
    sub_0815A6F0();
    sub_0815B248();
    iVar6 = sub_080C3560((uint)DAT_0203b908);
    if (iVar6 == 0) {
      iVar6 = sub_080BF648((uint)DAT_0203b908);
      uVar9 = (uint)DAT_030046cd;
      if ((DAT_0203b90c & 0x40) != 0) {
        uVar9 = uVar9 + 9;
      }
      if (uVar9 < *(byte *)(iVar6 + 1)) {
        DAT_0203b8f8 = DAT_0203b8f2;
        DAT_0203b8fa = DAT_0203b8f4;
        DAT_0203b8fc = DAT_0203b8f6;
        uVar8 = 3;
      }
      else {
        uVar9 = sub_0815B958((uint)DAT_0203b908);
        uVar7 = sub_0815B970((uint)(DAT_03004718 >> 8));
        if ((((uVar9 & 0xff) == 1) || ((uVar7 & 0xff) == 1)) || ((uVar7 & 0xff) == (uVar9 & 0xff)))
        {
          DAT_0203b8f8 = DAT_0203b8f2;
          DAT_0203b8fa = DAT_0203b8f4;
          DAT_0203b8fc = DAT_0203b8f6;
          uVar8 = 1;
        }
        else {
          DAT_0203b8f8 = DAT_0203b8f2;
          DAT_0203b8fa = DAT_0203b8f4;
          DAT_0203b8fc = DAT_0203b8f6;
          uVar8 = 2;
        }
      }
    }
    else {
      uVar8 = 4;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0815b3e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar8);
  return;
}


// sub_0815B3F4 @ 0x0815B3F4

void sub_0815B3F4(void)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203b8f8 != 0xffff) {
    sub_0815BB18((uint)DAT_0203b8f8,2);
  }
  if (DAT_0203b8fa != 0xffff) {
    sub_0815BB18((uint)DAT_0203b8fa,2);
  }
  if (DAT_0203b8fc != 0xffff) {
    sub_0815BB18((uint)DAT_0203b8fc,2);
  }
  sub_0815BAC8((uint)DAT_0203b908,4);
  iVar1 = sub_080C2340(0xe0);
  if (iVar1 == 0) {
    uVar2 = sub_0815B958((uint)DAT_0203b908);
    if ((uVar2 & 3) == 0) {
      if (DAT_03004718 < 0x1a) {
        DAT_03004718 = 0;
      }
      else {
        DAT_03004718 = DAT_03004718 - 0x1a;
      }
    }
    else if ((uVar2 & 3) == 2) {
      if (DAT_03004718 < 0xffe7) {
        DAT_03004718 = DAT_03004718 + 0x1a;
      }
      else {
        DAT_03004718 = 0xffff;
      }
    }
    DAT_03004798 = DAT_03004718;
    DAT_03004818 = DAT_03004718;
  }
                    /* WARNING: Could not recover jumptable at 0x0815b4b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0815B4B4 @ 0x0815B4B4

undefined4 sub_0815B4B4(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  dword dVar6;
  byte *pbVar7;
  undefined4 uVar8;
  dword dVar9;
  dword unaff_r8;
  uint unaff_r10;
  code *UNRECOVERED_JUMPTABLE;
  dword dStack_24;
  
  uVar1 = DAT_0203b8f8;
  DAT_0203b8f2 = DAT_0203b8f8;
  DAT_0203b8f4 = DAT_0203b8fa;
  DAT_0203b8f6 = DAT_0203b8fc;
  if ((uint)DAT_0203b8fa * 0x10000 <= (uint)DAT_0203b8f8 * 0x10000 &&
      (uint)DAT_0203b8f8 * 0x10000 + (uint)DAT_0203b8fa * -0x10000 != 0) {
    DAT_0203b8f8 = DAT_0203b8fa;
    DAT_0203b8fa = uVar1;
  }
  uVar2 = DAT_0203b8fa;
  uVar1 = DAT_0203b8f8;
  if (DAT_0203b8fc < DAT_0203b8f8) {
    DAT_0203b8f8 = DAT_0203b8fc;
    DAT_0203b8fc = uVar1;
  }
  if (DAT_0203b8fc < DAT_0203b8fa) {
    DAT_0203b8fa = DAT_0203b8fc;
    DAT_0203b8fc = uVar2;
  }
  sub_0815B9B8((uint)DAT_0203b8f8,0x203b901,&DAT_0203b8fe);
  sub_0815B9B8((uint)DAT_0203b8fa,&DAT_0203b902,&DAT_0203b8ff);
  if (DAT_0203b8fc == 0xffff) {
    if ((DAT_0203b8f8 == 0xfb) || (DAT_0203b8fa == 0xfb)) {
      DAT_0203b8f8 = DAT_0203b8f2;
      DAT_0203b8fa = DAT_0203b8f4;
      dVar9 = 0x203b8f6;
    }
    else {
      if (DAT_0203b901 == 0xb) {
        if (DAT_0203b902 != 0xb) {
LAB_0815b7c4:
          dVar9 = 0x203b868;
          DAT_0203b8f8 = DAT_0203b8f2;
          DAT_0203b8fa = DAT_0203b8f4;
          goto LAB_0815b7dc;
        }
      }
      else if (DAT_0203b902 == 0xb) goto LAB_0815b7c4;
      dVar9 = 0x203b868;
      DAT_0203b8f8 = DAT_0203b8f2;
      DAT_0203b8fa = DAT_0203b8f4;
    }
LAB_0815b80c:
    uVar8 = 0;
    DAT_0203b8fc = DAT_0203b8f6;
  }
  else {
    sub_0815B9B8((uint)DAT_0203b8fc,&DAT_0203b903,&DAT_0203b900);
    dVar9 = 0x203b901;
    if (DAT_0203b901 == 0xb) {
      if (DAT_0203b902 == 0xb) goto LAB_0815b566;
      if (DAT_0203b903 == 0xb) goto LAB_0815b55c;
LAB_0815b59c:
      DAT_0203b8f8 = DAT_0203b8f2;
      DAT_0203b8fa = DAT_0203b8f4;
    }
    else {
LAB_0815b55c:
      if (DAT_0203b902 == 0xb) {
LAB_0815b566:
        if (DAT_0203b903 != 0xb) {
          if (DAT_0203b901 != 0xb) goto LAB_0815b59c;
          goto LAB_0815b57e;
        }
LAB_0815b588:
        if ((DAT_0203b901 != 0xb) && (DAT_0203b902 != 0xb)) goto LAB_0815b59c;
      }
      else {
LAB_0815b57e:
        if (DAT_0203b903 == 0xb) goto LAB_0815b588;
      }
      if ((0x1a < DAT_0203b8fe) || ((0x1a < DAT_0203b8ff || (0x1a < DAT_0203b900)))) {
        DAT_0203b8f8 = DAT_0203b8f2;
        DAT_0203b8fa = DAT_0203b8f4;
        goto LAB_0815b80c;
      }
      uVar3 = sub_0815B9A0((uint)DAT_0203b8f8);
      uVar3 = uVar3 & 0xff;
      uVar4 = sub_0815B9A0((uint)DAT_0203b8fa);
      uVar4 = uVar4 & 0xff;
      uVar5 = sub_0815B9A0((uint)DAT_0203b8fc);
      uVar5 = uVar5 & 0xff;
      if ((uVar3 < uVar4) || (uVar3 < uVar5)) {
        if ((uVar3 <= uVar4) && (uVar5 <= uVar4)) {
          dStack_24 = (dword)DAT_0203b902;
          if (uVar3 < uVar5) {
            pbVar7 = &DAT_0203b903;
LAB_0815b6bc:
            dVar6 = (dword)*pbVar7;
            pbVar7 = &DAT_0203b901;
          }
          else {
            dVar6 = (dword)DAT_0203b901;
            pbVar7 = &DAT_0203b903;
          }
          goto LAB_0815b6c4;
        }
        dVar6 = unaff_r8;
        if ((uVar3 <= uVar5) && (uVar4 <= uVar5)) {
          dStack_24 = (dword)DAT_0203b903;
          if (uVar3 < uVar4) {
            pbVar7 = &DAT_0203b902;
            goto LAB_0815b6bc;
          }
          dVar6 = (dword)DAT_0203b901;
          pbVar7 = &DAT_0203b902;
          goto LAB_0815b6c4;
        }
      }
      else {
        dStack_24 = (dword)DAT_0203b901;
        if (uVar4 < uVar5) {
          dVar6 = (dword)DAT_0203b903;
          pbVar7 = &DAT_0203b902;
        }
        else {
          dVar6 = (dword)DAT_0203b902;
          pbVar7 = &DAT_0203b903;
        }
LAB_0815b6c4:
        unaff_r10 = (uint)*pbVar7;
      }
      dVar9 = dStack_24;
      if (((((dStack_24 != 3) ||
            (((dVar6 != 3 || (unaff_r10 != 2)) && ((dVar6 != 2 || (unaff_r10 != 3)))))) &&
           ((dVar9 = dVar6, dStack_24 != 7 ||
            ((((dVar6 != 7 || (unaff_r10 != 5)) &&
              (((dVar6 != 5 || (unaff_r10 != 7)) && ((dVar6 != 1 || (unaff_r10 != 5)))))) &&
             ((dVar6 != 5 || (unaff_r10 != 1)))))))) &&
          ((dStack_24 != 6 ||
           (((dVar6 != 1 || (dVar9 = dStack_24, unaff_r10 != 7)) &&
            ((dVar6 != 7 || (dVar9 = dStack_24, unaff_r10 != 1)))))))) &&
         ((dVar9 = dStack_24, dStack_24 != 5 ||
          (((dVar6 != 5 || (dVar9 = dVar6, unaff_r10 != 3)) &&
           ((dVar9 = dVar6, dVar6 != 3 || (unaff_r10 != 5)))))))) {
        DAT_0203b8f8 = DAT_0203b8f2;
        DAT_0203b8fa = DAT_0203b8f4;
        goto LAB_0815b80c;
      }
      DAT_0203b8f8 = DAT_0203b8f2;
      DAT_0203b8fa = DAT_0203b8f4;
    }
LAB_0815b7dc:
    DAT_0203b8fc = DAT_0203b8f6;
    uVar8 = 1;
  }
  DAT_0203b8f2 = DAT_0203b8f8;
  DAT_0203b8f4 = DAT_0203b8fa;
  DAT_0203b8f6 = DAT_0203b8fc;
                    /* WARNING: Could not recover jumptable at 0x0815b81c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar8 = (*UNRECOVERED_JUMPTABLE)(uVar8,UNRECOVERED_JUMPTABLE,dVar9,unaff_r8);
  return uVar8;
}


// sub_0815B824 @ 0x0815B824

uint sub_0815B824(uint arg0)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  uVar2 = (*(byte *)(iVar1 + 0x21) & 0xf0) >> 2;
  DAT_0203bafa = (short)uVar2;
  uVar2 = (uint)*(byte *)(uVar2 + (*(byte *)(iVar1 + 0x21) & 0xf) + 0x87f1ccc);
  if (uVar2 == 0xff) {
    uVar2 = 0xf;
  }
  return uVar2;
}


// sub_0815B864 @ 0x0815B864

undefined4 sub_0815B864(void)

{
  undefined4 in_r0;
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = sub_080ED550(in_r0);
  if (uVar1 < 0x70) {
    uVar2 = 0;
  }
  else if (uVar1 < 0x90) {
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


// sub_0815B880 @ 0x0815B880

void sub_0815B880(void)

{
  return;
}


// sub_0815B884 @ 0x0815B884

void sub_0815B884(uint arg0,undefined4 arg1,undefined4 arg2,ushort *arg3)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort *in_stack_00000000;
  
  uVar2 = sub_08154968(arg0 & 0xffff);
  DAT_0203b8f8 = (undefined2)uVar2;
  if ((ushort)arg1 == 0xffff) {
    DAT_0203b8fa = (ushort)arg1 | DAT_0203b8fa;
  }
  else {
    uVar2 = sub_08154968((uint)(ushort)arg1);
    DAT_0203b8fa = (ushort)uVar2;
  }
  DAT_0203b8fc = (undefined2)arg2;
  sub_0815AE84();
  uVar1 = DAT_0203b908;
  if (DAT_0203b908 != 0xff) {
    uVar2 = sub_08154980((uint)DAT_0203b908);
    uVar1 = (ushort)uVar2;
  }
  *arg3 = uVar1;
  *in_stack_00000000 = DAT_0203b908;
  return;
}


// sub_0815B8F8 @ 0x0815B8F8

undefined4 sub_0815B8F8(uint arg0,undefined4 arg1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = 0;
  do {
    if ((arg0 & 0xffff) == (uint)*(byte *)(uVar3 + 0x87f1d01)) {
      if (((byte)(&UNK_087f1d02)[uVar3] == 0) ||
         (iVar1 = sub_080C2340((uint)(byte)(&UNK_087f1d02)[uVar3]), iVar1 == 0)) goto LAB_0815b93e;
      goto LAB_0815b950;
    }
    uVar3 = uVar3 + 2 & 0xffff;
  } while (*(char *)(uVar3 + 0x87f1d01) != -1);
  if (((short)arg1 == 0) && (iVar1 = sub_0815BA7C(arg0 & 0xffff), iVar1 == 0)) {
LAB_0815b93e:
    uVar2 = 0;
  }
  else {
LAB_0815b950:
    uVar2 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x0815b956. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_0815B958 @ 0x0815B958

uint sub_0815B958(uint arg0)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  uVar2 = sub_0815B970((uint)*(byte *)(iVar1 + 0xc));
  return uVar2 & 0xffff;
}


// sub_0815B970 @ 0x0815B970

undefined4 sub_0815B970(uint arg0)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = arg0 & 0xff;
  if (uVar1 < 0x70) {
    uVar1 = uVar1 << 8;
  }
  else if (uVar1 < 0x90) {
    uVar1 = uVar1 * 0x100 + 1;
  }
  else {
    uVar1 = uVar1 << 8 | 2;
  }
                    /* WARNING: Could not recover jumptable at 0x0815b99c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar2;
}


// sub_0815B9A0 @ 0x0815B9A0

uint sub_0815B9A0(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF648(arg0 & 0xff);
  return (uint)*(byte *)(iVar1 + 1);
}


// sub_0815B9B8 @ 0x0815B9B8

void sub_0815B9B8(uint arg0,undefined1 *arg1,byte *arg2)

{
  undefined4 uVar1;
  
  uVar1 = sub_0815B9DC(arg0 & 0xffff);
  *arg2 = (byte)uVar1;
  *arg1 = *(undefined1 *)(*arg2 + 0x87f153d);
  return;
}


// sub_0815B9DC @ 0x0815B9DC

undefined4 sub_0815B9DC(uint arg0)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((arg0 & 0xff00) == 0) {
    if ((arg0 & 0xffff) == 0xff) {
      uVar1 = 0xff;
    }
    else {
      uVar1 = 0;
      do {
        uVar1 = uVar1 + 1 & 0xffff;
      } while ((uint)*(byte *)(uVar1 + 0x87f1514) <= (arg0 & 0xffff));
    }
  }
  else {
    uVar1 = (uint)*(byte *)((arg0 & 0xff) + 0x87f1569);
  }
                    /* WARNING: Could not recover jumptable at 0x0815ba22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar2;
}


// sub_0815BA28 @ 0x0815BA28

undefined4 sub_0815BA28(undefined4 arg0)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = 0;
  if ((ushort)arg0 < 0xff) {
    do {
      if ((ushort)arg0 == *(byte *)(uVar3 + 0x87f1d22)) {
        if (((byte)(&UNK_087f1d23)[uVar3] == 0) ||
           (iVar1 = sub_080C2340((uint)(byte)(&UNK_087f1d23)[uVar3]), iVar1 == 0))
        goto LAB_0815ba6e;
        break;
      }
      uVar3 = uVar3 + 2 & 0xffff;
    } while (*(char *)(uVar3 + 0x87f1d22) != -1);
    uVar2 = 1;
  }
  else {
LAB_0815ba6e:
    uVar2 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0815ba78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_0815BA7C @ 0x0815BA7C

undefined4 sub_0815BA7C(undefined4 arg0)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(short *)(uVar1 * 2 + 0x87f1d72) == (short)arg0) {
      return 0;
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (*(short *)(uVar1 * 2 + 0x87f1d72) != -1);
  return 1;
}


// sub_0815BAC4 @ 0x0815BAC4

undefined4 sub_0815BAC4(void)

{
  return 1;
}


// sub_0815BAC8 @ 0x0815BAC8

void sub_0815BAC8(uint arg0,undefined4 arg1)

{
  ushort uVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = sub_0815BB70(arg0 & 0xffff);
  if ((uVar2 & 0xffff) != 0xffff) {
    uVar1 = (ushort)(byte)(&DAT_03005734)[uVar2 & 0xffff] + (short)arg1;
    bVar3 = (byte)uVar1;
    if ((uVar1 & 0xff00) != 0) {
      bVar3 = 0xff;
    }
    (&DAT_03005734)[uVar2 & 0xffff] = bVar3;
  }
  return;
}


// sub_0815BB18 @ 0x0815BB18

void sub_0815BB18(uint arg0,undefined4 arg1)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = sub_0815BB70(arg0 & 0xffff);
  uVar1 = uVar1 & 0xffff;
  if (uVar1 != 0xffff) {
    if ((ushort)arg1 < (byte)(&DAT_03005734)[uVar1]) {
      cVar2 = (&DAT_03005734)[uVar1] - (char)(ushort)arg1;
    }
    else {
      cVar2 = '\0';
    }
    (&DAT_03005734)[uVar1] = cVar2;
  }
  return;
}


// sub_0815BB70 @ 0x0815BB70

dword sub_0815BB70(undefined4 arg0)

{
  dword dVar1;
  
  if (((ushort)arg0 < 0x54) || (0xb1 < (ushort)arg0)) {
    dVar1 = 0xffff;
  }
  else {
    dVar1 = (dword)(ushort)((ushort)arg0 - 0x54);
  }
  return dVar1;
}


