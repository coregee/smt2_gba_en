/* Ghidra decompilation of asm/code_080BF908.s (reference only; not compiled). */

// sub_080BF908 @ 0x080BF908

void sub_080BF908(undefined4 arg0,short *arg1,short *arg2)

{
  int iVar1;
  
  if ((int)(char)arg0 != 0xffffffff) {
    iVar1 = Equipment_GetRecord36_MidRange((int)(char)arg0 & 0xffff);
    *arg1 = *arg1 + (ushort)*(byte *)(iVar1 + 1);
    *arg2 = *arg2 + (ushort)*(byte *)(iVar1 + 2);
  }
  return;
}


// sub_080BF938 @ 0x080BF938

void sub_080BF938(int arg0)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  int arg0_00;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  undefined4 uVar9;
  ushort uVar10;
  uint uVar11;
  byte *pbVar12;
  short *psVar13;
  uint uVar14;
  short *psVar15;
  ushort *puVar16;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  undefined1 *local_34;
  undefined1 *local_30;
  undefined1 *local_2c;
  undefined1 *local_28;
  undefined1 *local_24;
  
  arg0_00 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  sub_080BFDC4(arg0_00 + 0x20,(byte *)(arg0_00 + 0x30));
  sub_080BFEA8(arg0_00);
  sub_080BFF0C(arg0_00);
  uVar4 = sub_080C0818((uint)*(byte *)(arg0_00 + 0xc));
  uVar4 = -((int)-(uVar4 & 0x800) >> 0x1f);
  if (uVar4 == 0) {
    local_44 = (uint)*(byte *)(arg0_00 + 0x28) + (uint)*(byte *)(arg0_00 + 0x30) +
               (uint)*(byte *)(arg0_00 + 0x38);
    uVar4 = (uint)*(byte *)(arg0_00 + 0x39) +
            (uint)*(byte *)(arg0_00 + 0x29) + (uint)*(byte *)(arg0_00 + 0x31);
    local_40 = (uint)*(byte *)(arg0_00 + 0x2a) + (uint)*(byte *)(arg0_00 + 0x32) +
               (uint)*(byte *)(arg0_00 + 0x3a);
    local_3c = (uint)*(byte *)(arg0_00 + 0x2b) + (uint)*(byte *)(arg0_00 + 0x33) +
               (uint)*(byte *)(arg0_00 + 0x3b);
    local_38 = (uint)*(byte *)(arg0_00 + 0x2c) + (uint)*(byte *)(arg0_00 + 0x34) +
               (uint)*(byte *)(arg0_00 + 0x3c);
    uVar11 = (uint)*(byte *)(arg0_00 + 0x3d) +
             (uint)*(byte *)(arg0_00 + 0x2d) + (uint)*(byte *)(arg0_00 + 0x35);
    if (*(char *)(arg0_00 + 0xc) == '\0') {
      uVar14 = 0;
      pbVar12 = &DAT_081a6ed5;
      do {
        uVar5 = sub_080C32D4(uVar14 + 0x120 & 0xffff);
        if (8 < (uVar5 & 0xff)) {
          local_44 = local_44 + (*pbVar12 >> 4) & 0xffff;
          uVar4 = (*pbVar12 & 0xf) + uVar4 & 0xffff;
          local_40 = local_40 + (pbVar12[1] >> 4) & 0xffff;
          local_3c = local_3c + (pbVar12[1] & 0xf) & 0xffff;
          local_38 = local_38 + (pbVar12[2] >> 4) & 0xffff;
          uVar11 = (pbVar12[2] & 0xf) + uVar11 & 0xffff;
        }
        pbVar12 = pbVar12 + 4;
        uVar14 = uVar14 + 1;
      } while (uVar14 < 0xc);
    }
  }
  else {
    local_38 = 0x28;
    uVar11 = uVar4;
    local_44 = uVar4;
    local_40 = uVar4;
    local_3c = uVar4;
  }
  local_24 = (undefined1 *)(arg0_00 + 0x44);
  local_28 = (undefined1 *)(arg0_00 + 0x43);
  local_2c = (undefined1 *)(arg0_00 + 0x42);
  local_30 = (undefined1 *)(arg0_00 + 0x41);
  local_34 = (undefined1 *)(arg0_00 + 0x40);
  *local_34 = (undefined1)local_44;
  *local_30 = (char)uVar4;
  *local_2c = (undefined1)local_40;
  *local_28 = (undefined1)local_3c;
  *local_24 = (undefined1)local_38;
  *(char *)(arg0_00 + 0x45) = (char)uVar11;
  if (*(byte *)(arg0_00 + 0xc) < 4) {
    psVar15 = (short *)(arg0_00 + 0x4a);
    *psVar15 = 0;
    psVar13 = (short *)(arg0_00 + 0x48);
    *psVar13 = 0;
    sVar3 = (short)local_38;
    if ((int)*(char *)(arg0_00 + 0x20) != 0xffffffff) {
      iVar6 = sub_080BF32C((int)*(char *)(arg0_00 + 0x20) & 0xffff);
      sVar2 = (short)local_44 + (ushort)*(byte *)(iVar6 + 1);
      *psVar13 = sVar2;
      *psVar13 = sVar2 + (ushort)(*(byte *)(arg0_00 + 0xd) >> 1);
      sVar2 = sVar3 + (short)((int)(local_44 + uVar11) >> 2) + (ushort)*(byte *)(iVar6 + 2);
      *psVar15 = sVar2;
      *psVar15 = sVar2 + (ushort)*(byte *)(arg0_00 + 0xd);
    }
    puVar7 = (ushort *)(arg0_00 + 0x4e);
    *puVar7 = 0;
    puVar16 = (ushort *)(arg0_00 + 0x4c);
    *puVar16 = 0;
    if ((*(char *)(arg0_00 + 0x21) != -1) && (*(char *)(arg0_00 + 0x26) != -1)) {
      iVar6 = sub_080BF32C((int)*(char *)(arg0_00 + 0x21) & 0xffff);
      iVar8 = sub_080BF32C((int)*(char *)(arg0_00 + 0x26) & 0xffff);
      bVar1 = *(byte *)(iVar6 + 1);
      *puVar16 = (ushort)bVar1;
      uVar10 = (ushort)bVar1 + (ushort)*(byte *)(iVar8 + 1);
      *puVar16 = uVar10;
      *puVar16 = uVar10 + (*(byte *)(arg0_00 + 0xd) >> 1);
      bVar1 = *(byte *)(iVar6 + 2);
      *puVar7 = (ushort)bVar1;
      uVar10 = (ushort)bVar1 + (ushort)*(byte *)(iVar8 + 2);
      *puVar7 = uVar10;
      uVar10 = uVar10 + sVar3 + (short)((int)(local_44 + uVar11) >> 2);
      *puVar7 = uVar10;
      *puVar7 = uVar10 + *(byte *)(arg0_00 + 0xd);
    }
    psVar13 = (short *)(arg0_00 + 0x50);
    *psVar13 = 0;
    psVar15 = (short *)(arg0_00 + 0x52);
    *psVar15 = 0;
    sub_080BF908((int)*(char *)(arg0_00 + 0x22),psVar13,psVar15);
    sub_080BF908((int)*(char *)(arg0_00 + 0x23),psVar13,psVar15);
    sub_080BF908((int)*(char *)(arg0_00 + 0x24),psVar13,psVar15);
    sub_080BF908((int)*(char *)(arg0_00 + 0x25),psVar13,psVar15);
    *psVar13 = (ushort)(*(byte *)(arg0_00 + 0xd) >> 2) + (short)((int)(local_38 + local_3c) / 2) +
               *psVar13;
    *psVar15 = *psVar15 +
               sVar3 + (short)((int)(uVar4 + uVar11) >> 2) + (ushort)*(byte *)(arg0_00 + 0xd);
    if (*(char *)(arg0_00 + 0xc) == '\0') {
      iVar6 = (local_44 + local_3c) * (*(byte *)(arg0_00 + 0xd) + 1);
      if (iVar6 < 0) {
        iVar6 = iVar6 + 3;
      }
      *(short *)(arg0_00 + 0x1a) = (short)(iVar6 >> 2) + 0xe;
      *(undefined2 *)(arg0_00 + 0x1e) = 0;
    }
    else {
      uVar9 = __divsi3((local_44 + local_3c) * (*(byte *)(arg0_00 + 0xd) + 1),5);
      *(short *)(arg0_00 + 0x1a) = (short)uVar9 + 10;
      iVar6 = (local_40 + uVar4) * (*(byte *)(arg0_00 + 0xd) + 4);
      if (iVar6 < 0) {
        iVar6 = iVar6 + 7;
      }
      *(short *)(arg0_00 + 0x1e) = (short)(iVar6 >> 3) + 4;
    }
    if (0x3e6 < *(short *)(arg0_00 + 0x1a)) {
      *(undefined2 *)(arg0_00 + 0x1a) = 999;
    }
    if (0x3e6 < *(short *)(arg0_00 + 0x1e)) {
      *(undefined2 *)(arg0_00 + 0x1e) = 999;
    }
    if (0x3e6 < *(short *)(arg0_00 + 0x18)) {
      *(undefined2 *)(arg0_00 + 0x18) = 999;
    }
    if (0x3e6 < *(short *)(arg0_00 + 0x1c)) {
      *(undefined2 *)(arg0_00 + 0x1c) = 999;
    }
    *(short *)(arg0_00 + 0x54) = (short)local_40 + (short)(uVar4 >> 2);
    *(short *)(arg0_00 + 0x56) = (short)(local_40 >> 2) + (short)uVar4;
  }
  return;
}


// sub_080BFD1C @ 0x080BFD1C

void sub_080BFD1C(int arg0,int arg1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  if (arg1 == 1) {
    iVar2 = *(short *)(iVar1 + 0x4a) * 7;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    *(short *)(iVar1 + 0x4a) = (short)(iVar2 >> 3);
    iVar2 = *(short *)(iVar1 + 0x4e) * 7;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    *(short *)(iVar1 + 0x4e) = (short)(iVar2 >> 3);
    iVar2 = *(short *)(iVar1 + 0x50) * 9;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    *(short *)(iVar1 + 0x50) = (short)(iVar2 >> 3);
    iVar2 = *(short *)(iVar1 + 0x52) * 9;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    *(short *)(iVar1 + 0x52) = (short)(iVar2 >> 3);
  }
  return;
}


// sub_080BFD94 @ 0x080BFD94

void sub_080BFD94(int arg0)

{
  undefined4 arg1;
  
  sub_080F2F64(arg0 - 0x8000U & 0xffff);
  sub_080BF938(arg0);
  arg1 = sub_080BFFF0();
  sub_080BFD1C(arg0,arg1);
  return;
}


// sub_080BFDC4 @ 0x080BFDC4

void sub_080BFDC4(byte *arg0,undefined4 arg1)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  ushort local_34 [4];
  ushort local_2c;
  ushort local_2a;
  ushort local_28;
  undefined2 local_24 [2];
  undefined1 auStack_20 [8];
  
  puVar2 = local_34;
  local_24[0] = 0;
  REG_DMA3SAD = local_24;
  REG_DMA3DAD = arg1;
  REG_DMA3CNT = 0x81000004;
  uVar1 = REG_DMA3CNT;
  local_34[0] = (ushort)*arg0;
  local_34[1] = (ushort)arg0[1];
  local_34[2] = (ushort)arg0[2];
  local_34[3] = (ushort)arg0[3];
  local_2c = (ushort)arg0[4];
  local_2a = (ushort)arg0[5];
  local_28 = (ushort)arg0[6];
  iVar3 = 6;
  do {
    if ((short)*puVar2 != 0xff) {
      sub_080BF468((int)(short)*puVar2,5,auStack_20);
      sub_080BFF8C(arg1,auStack_20,arg1);
    }
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  return;
}


// sub_080BFE84 @ 0x080BFE84

int sub_080BFE84(int arg0,int arg1)

{
  int iVar1;
  
  iVar1 = arg0 + arg1 + -0x46;
  if (0 < iVar1) {
    arg1 = arg1 - iVar1;
  }
  return arg1;
}


// sub_080BFE98 @ 0x080BFE98

undefined4 sub_080BFE98(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  return arg2;
}


// sub_080BFEA8 @ 0x080BFEA8

void sub_080BFEA8(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080BFE84((int)*(char *)(arg0 + 0x28),(int)*(char *)(arg0 + 0x30));
  *(char *)(arg0 + 0x30) = (char)uVar1;
  uVar1 = sub_080BFE84((int)*(char *)(arg0 + 0x29),(int)*(char *)(arg0 + 0x31));
  *(char *)(arg0 + 0x31) = (char)uVar1;
  uVar1 = sub_080BFE84((int)*(char *)(arg0 + 0x2a),(int)*(char *)(arg0 + 0x32));
  *(char *)(arg0 + 0x32) = (char)uVar1;
  uVar1 = sub_080BFE84((int)*(char *)(arg0 + 0x2b),(int)*(char *)(arg0 + 0x33));
  *(char *)(arg0 + 0x33) = (char)uVar1;
  uVar1 = sub_080BFE84((int)*(char *)(arg0 + 0x2c),(int)*(char *)(arg0 + 0x34));
  *(char *)(arg0 + 0x34) = (char)uVar1;
  uVar1 = sub_080BFE84((int)*(char *)(arg0 + 0x2d),(int)*(char *)(arg0 + 0x35));
  *(char *)(arg0 + 0x35) = (char)uVar1;
  return;
}


// sub_080BFF0C @ 0x080BFF0C

void sub_080BFF0C(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080BFE98((int)*(char *)(arg0 + 0x28),(int)*(char *)(arg0 + 0x30),
                       (int)*(char *)(arg0 + 0x38));
  *(char *)(arg0 + 0x38) = (char)uVar1;
  uVar1 = sub_080BFE98((int)*(char *)(arg0 + 0x29),(int)*(char *)(arg0 + 0x31),
                       (int)*(char *)(arg0 + 0x39));
  *(char *)(arg0 + 0x39) = (char)uVar1;
  uVar1 = sub_080BFE98((int)*(char *)(arg0 + 0x2a),(int)*(char *)(arg0 + 0x32),
                       (int)*(char *)(arg0 + 0x3a));
  *(char *)(arg0 + 0x3a) = (char)uVar1;
  uVar1 = sub_080BFE98((int)*(char *)(arg0 + 0x2b),(int)*(char *)(arg0 + 0x33),
                       (int)*(char *)(arg0 + 0x3b));
  *(char *)(arg0 + 0x3b) = (char)uVar1;
  uVar1 = sub_080BFE98((int)*(char *)(arg0 + 0x2c),(int)*(char *)(arg0 + 0x34),
                       (int)*(char *)(arg0 + 0x3c));
  *(char *)(arg0 + 0x3c) = (char)uVar1;
  uVar1 = sub_080BFE98((int)*(char *)(arg0 + 0x2d),(int)*(char *)(arg0 + 0x35),
                       (int)*(char *)(arg0 + 0x3d));
  *(char *)(arg0 + 0x3d) = (char)uVar1;
  return;
}


// sub_080BFF8C @ 0x080BFF8C

void sub_080BFF8C(char *arg0,char *arg1,char *arg2)

{
  *arg2 = *arg1 + *arg0;
  arg2[1] = arg1[1] + arg0[1];
  arg2[2] = arg1[2] + arg0[2];
  arg2[3] = arg1[3] + arg0[3];
  arg2[4] = arg1[4] + arg0[4];
  arg2[5] = arg1[5] + arg0[5];
  return;
}


// sub_080BFFC4 @ 0x080BFFC4

undefined4 sub_080BFFC4(int arg0)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)(iVar1 + 0x30050e0) == arg0) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  return 0xffffffff;
}


// sub_080BFFF0 @ 0x080BFFF0

undefined4 sub_080BFFF0(void)

{
  undefined4 in_r0;
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080BFFC4(in_r0);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else if (iVar1 < 3) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080c000c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080C0010 @ 0x080C0010

void sub_080C0010(undefined4 arg0,undefined2 *arg1)

{
  int arg0_00;
  uint arg1_00;
  uint uStack_1c;
  
  *(undefined1 *)arg1 = 0xff;
  *(undefined1 *)((int)arg1 + 1) = 0xff;
  *(undefined1 *)(arg1 + 1) = 0xff;
  *(undefined1 *)((int)arg1 + 3) = 0xff;
  *(undefined1 *)(arg1 + 2) = 0xff;
  *(undefined1 *)((int)arg1 + 5) = 0xff;
  *(undefined1 *)(arg1 + 3) = 0xff;
  *(undefined1 *)((int)arg1 + 7) = 0xff;
  arg1_00 = 0;
  do {
    arg0_00 = sub_080C00DC(arg0,arg1_00);
    if (((arg0_00 != 0xff) && (arg1_00 != 6)) &&
       (sub_080BF468(arg0_00,6,&uStack_1c), (uStack_1c & 1) != 0)) {
      *arg1 = (short)arg0_00;
    }
    arg1 = arg1 + 1;
    arg1_00 = arg1_00 + 1;
  } while (arg1_00 < 7);
  return;
}


// sub_080C0074 @ 0x080C0074

void sub_080C0074(int arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  switch(arg1) {
  case 0:
    *(undefined1 *)(iVar1 + 0x20) = (undefined1)arg2;
    break;
  case 1:
    *(undefined1 *)(iVar1 + 0x21) = (undefined1)arg2;
    break;
  case 2:
    *(undefined1 *)(iVar1 + 0x22) = (undefined1)arg2;
    break;
  case 3:
    *(undefined1 *)(iVar1 + 0x23) = (undefined1)arg2;
    break;
  case 4:
    *(undefined1 *)(iVar1 + 0x24) = (undefined1)arg2;
    break;
  case 5:
    *(undefined1 *)(iVar1 + 0x25) = (undefined1)arg2;
    break;
  case 6:
    *(undefined1 *)(iVar1 + 0x26) = (undefined1)arg2;
  }
  return;
}


// sub_080C00DC @ 0x080C00DC

uint sub_080C00DC(int arg0,undefined4 arg1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  switch(arg1) {
  case 0:
    uVar2 = (uint)*(byte *)(iVar1 + 0x20);
    break;
  case 1:
    uVar2 = (uint)*(byte *)(iVar1 + 0x21);
    break;
  case 2:
    uVar2 = (uint)*(byte *)(iVar1 + 0x22);
    break;
  case 3:
    uVar2 = (uint)*(byte *)(iVar1 + 0x23);
    break;
  case 4:
    uVar2 = (uint)*(byte *)(iVar1 + 0x24);
    break;
  case 5:
    uVar2 = (uint)*(byte *)(iVar1 + 0x25);
    break;
  case 6:
    uVar2 = (uint)*(byte *)(iVar1 + 0x26);
    break;
  default:
    uVar2 = 0;
  }
  return uVar2;
}


// sub_080C0148 @ 0x080C0148

int sub_080C0148(uint arg0)

{
  int iVar1;
  
  if ((arg0 & 0x8000) == 0) {
    if ((&DAT_030050e0)[arg0 & 0xffff] == -1) {
      iVar1 = 0;
    }
    else {
      iVar1 = (char)(&DAT_030050e0)[arg0 & 0xffff] * 0x80 + 0x30046c0;
    }
  }
  else {
    iVar1 = (arg0 & 0x7fff) * 0x80 + 0x30046c0;
  }
  return iVar1;
}


// sub_080C0198 @ 0x080C0198

undefined4 sub_080C0198(uint arg0)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = sub_080C09B0((uint)(ushort)(uVar1 + 4));
    if ((iVar2 == 1) &&
       (iVar2 = (uint)(ushort)(uVar1 + 4) * 0x80,
       (int)*(short *)(&DAT_030046d2 + iVar2) == (arg0 & 0xffff))) break;
    uVar1 = uVar1 + 1;
    if (0xb < uVar1) {
      return 0;
    }
  }
  return iVar2 + 0x30046c0;
}


// sub_080C01DC @ 0x080C01DC

undefined4 sub_080C01DC(uint arg0)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = arg0 & 0xffff;
  iVar1 = sub_080C0148(arg0 * 0x10000 + 0x80000000 >> 0x10);
  uVar2 = 0;
  do {
    if (*(char *)(uVar2 + 0x30050e0) == -1) {
      *(char *)(uVar2 + 0x30050e0) = (char)uVar3;
      *(undefined2 *)(iVar1 + 0xe) = 0xc000;
      if ((uVar3 < 4) && (*(undefined2 *)(iVar1 + 0x10) = 0, uVar3 != 0)) {
        *(undefined2 *)(iVar1 + 0x58) = DAT_03004718;
      }
      return 1;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 6);
  return 0;
}


// sub_080C0248 @ 0x080C0248

void sub_080C0248(int arg0,uint arg1)

{
  int iVar1;
  
  iVar1 = sub_080C0148(arg0 * 0x10000 + 0x80000000U >> 0x10);
  if ((&DAT_030050e0)[arg1 & 0xffff] == -1) {
    (&DAT_030050e0)[arg1 & 0xffff] = (char)arg0;
    *(undefined2 *)(iVar1 + 0xe) = 0xc000;
  }
  return;
}


// sub_080C0290 @ 0x080C0290

void sub_080C0290(uint arg0,undefined4 arg1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = arg0 & 0xffff;
  iVar1 = sub_080C0148(arg0 * 0x10000 + 0x80000000 >> 0x10);
  uVar2 = 0;
  do {
    if ((int)*(char *)(uVar2 + 0x30050e0) == uVar3) {
      *(char *)(uVar2 + 0x30050e0) = -1;
      if ((short)arg1 == 0) {
        if (uVar3 < 4) goto LAB_080c0320;
        *(undefined2 *)(iVar1 + 0xe) = 0x8000;
        uVar2 = sub_080C0818((uint)*(byte *)(iVar1 + 0xc));
        if ((uVar2 & 0x4000) != 0) {
          sub_080C08F8((uint)*(byte *)(iVar1 + 0xc),0);
          sub_080C08F8((uint)*(byte *)(iVar1 + 0xc),0x8000);
        }
        sub_080C08BC((uint)*(byte *)(iVar1 + 0xc),0xb000);
      }
      else {
        *(undefined2 *)(iVar1 + 0xe) = 0;
        if (3 < uVar3) {
          sub_080C2A1C((int)*(short *)(iVar1 + 0x12));
        }
      }
      goto LAB_080c033c;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 6);
  if ((short)arg1 == 0) {
    if (uVar3 < 4) {
LAB_080c0320:
      *(short *)(iVar1 + 0xe) = (short)arg1;
    }
    else {
      *(undefined2 *)(iVar1 + 0xe) = 0x8000;
    }
  }
  else {
    *(undefined2 *)(iVar1 + 0xe) = 0;
    if (3 < uVar3) {
      sub_080C2A1C((int)*(short *)(iVar1 + 0x12));
    }
  }
LAB_080c033c:
                    /* WARNING: Could not recover jumptable at 0x080c0340. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// Combatant_DecodeName @ 0x080C0344

void Combatant_DecodeName(byte *arg0,undefined2 *arg1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*arg0 == 0xff) {
      *arg1 = 0;
    }
    else {
      *arg1 = *(undefined2 *)((uint)*arg0 * 2 + 0x81a5a6c);
    }
    uVar1 = uVar1 + 1;
    arg1 = arg1 + 1;
    arg0 = arg0 + 1;
  } while (uVar1 < 8);
  return;
}


// sub_080C0378 @ 0x080C0378

void sub_080C0378(byte *arg0,undefined2 *arg1)

{
  byte bVar1;
  
  bVar1 = *arg0;
  while ((bVar1 != 0 && (bVar1 != 0xff))) {
    *arg1 = *(undefined2 *)((uint)*arg0 * 2 + 0x81a5a6c);
    arg1 = arg1 + 1;
    arg0 = arg0 + 1;
    bVar1 = *arg0;
  }
  return;
}


// sub_080C03A8 @ 0x080C03A8

undefined4 sub_080C03A8(undefined4 arg0)

{
  uint uVar1;
  
  uVar1 = 1;
  do {
    if (*(short *)(uVar1 * 2 + 0x81a5a6c) == (short)arg0) {
      return uVar1 & 0xff;
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (*(short *)(uVar1 * 2 + 0x81a5a6c) != 0);
  return 0;
}


// sub_080C03E8 @ 0x080C03E8

uint sub_080C03E8(undefined4 arg0)

{
  uint uVar1;
  
  if ((short)arg0 == 0) {
    uVar1 = 0xff;
  }
  else {
    uVar1 = 0;
    if ((short)arg0 != 0x3f) {
      do {
        uVar1 = uVar1 + 1 & 0xff;
        if (0xdf < uVar1) {
          return uVar1;
        }
      } while (*(short *)(uVar1 * 2 + 0x81a5a6c) != (short)arg0);
    }
  }
  return uVar1;
}


// sub_080C0420 @ 0x080C0420

void sub_080C0420(ushort *arg0,undefined1 *arg1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = 0;
  do {
    uVar2 = sub_080C03E8((uint)*arg0);
    *arg1 = (char)uVar2;
    uVar1 = uVar1 + 1;
    arg0 = arg0 + 1;
    arg1 = arg1 + 1;
  } while (uVar1 < 8);
  return;
}


// sub_080C0444 @ 0x080C0444

void sub_080C0444(int arg0,undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 local_1c;
  
  pcVar2 = (char *)sub_080BF648((uint)(ushort)arg2);
  local_1c = 0;
  REG_DMA3SAD = &local_1c;
  REG_DMA3DAD = arg0;
  REG_DMA3CNT = 0x85000020;
  uVar1 = REG_DMA3CNT;
  *(char *)(arg0 + 0xc) = (char)arg1;
  *(ushort *)(arg0 + 0x12) = (ushort)arg2;
  *(undefined2 *)(arg0 + 0xe) = 0x8000;
  *(short *)(arg0 + 0x14) = (short)*pcVar2;
  *(undefined2 *)(arg0 + 0x18) = *(undefined2 *)(pcVar2 + 2);
  *(undefined2 *)(arg0 + 0x1a) = *(undefined2 *)(pcVar2 + 2);
  *(undefined2 *)(arg0 + 0x1c) = *(undefined2 *)(pcVar2 + 4);
  *(undefined2 *)(arg0 + 0x1e) = *(undefined2 *)(pcVar2 + 4);
  *(char *)(arg0 + 0xd) = pcVar2[1];
  *(short *)(arg0 + 0x58) = (ushort)(byte)pcVar2[0xc] << 8;
  sub_080C0420(pcVar2 + 0x22,arg0);
  sub_080C35C4(arg1,10);
  sub_080C3600(arg1,10);
  *(char *)(arg0 + 0x40) = pcVar2[6];
  *(char *)(arg0 + 0x41) = pcVar2[7];
  *(char *)(arg0 + 0x42) = pcVar2[8];
  *(char *)(arg0 + 0x43) = pcVar2[9];
  *(char *)(arg0 + 0x44) = pcVar2[10];
  *(char *)(arg0 + 0x45) = pcVar2[0xb];
  *(undefined4 *)(arg0 + 0x28) = *(undefined4 *)(arg0 + 0x40);
  *(undefined4 *)(arg0 + 0x2c) = *(undefined4 *)(arg0 + 0x44);
  *(short *)(arg0 + 0x58) = (ushort)(byte)pcVar2[0xc] << 8;
  iVar3 = 0;
  do {
    *(undefined1 *)(arg0 + 0x5d + iVar3) = 0xff;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x20);
  iVar4 = 0;
  iVar3 = 0;
  do {
    if (pcVar2[iVar3 + 0x11] != -1) {
      *(char *)(arg0 + 0x5d + iVar4) = pcVar2[iVar3 + 0x11];
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 7);
  sub_080C0574((uint)*(byte *)(arg0 + 0xd),arg0 + 0x40,arg0 + 0x48);
  return;
}


// sub_080C0550 @ 0x080C0550

void sub_080C0550(int arg0,undefined4 arg1)

{
  undefined4 arg0_00;
  
  arg0_00 = sub_080C0148(arg0 - 0x8000U & 0xffff);
  sub_080C0444(arg0_00,arg0,arg1);
  return;
}


// sub_080C0574 @ 0x080C0574

void sub_080C0574(int arg0,char *arg1,short *arg2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  sVar1 = (short)arg0;
  *arg2 = (sVar1 + *arg1) * 2;
  sVar2 = sVar1 + (short)(arg0 / 2);
  iVar3 = (int)*arg1 + (int)arg1[5];
  if (iVar3 < 0) {
    iVar3 = iVar3 + 3;
  }
  arg2[1] = arg1[4] + sVar2 + (short)(iVar3 >> 2);
  arg2[4] = (sVar1 + arg1[3]) * 2;
  iVar3 = (int)arg1[1] + (int)arg1[5];
  if (iVar3 < 0) {
    iVar3 = iVar3 + 3;
  }
  arg2[5] = arg1[4] + sVar2 + (short)(iVar3 >> 2);
  iVar3 = (int)arg1[1];
  if (iVar3 < 0) {
    iVar3 = iVar3 + 3;
  }
  arg2[6] = (short)(iVar3 >> 2) + (short)arg1[2];
  iVar3 = (int)arg1[2];
  if (iVar3 < 0) {
    iVar3 = iVar3 + 3;
  }
  arg2[7] = (short)(iVar3 >> 2) + (short)arg1[1];
  return;
}


// sub_080C05FC @ 0x080C05FC

void sub_080C05FC(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if ((*(ushort *)(arg0 + 0x10) & 0x800) == 0) {
    sub_080C0574((uint)*(byte *)(arg0 + 0xd),arg0 + 0x40,arg0 + 0x48);
  }
  else {
    sub_080C0574((uint)*(byte *)(arg0 + 0xd),0x81a5c2c,arg0 + 0x48);
  }
                    /* WARNING: Could not recover jumptable at 0x080c0626. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C062C @ 0x080C062C

void sub_080C062C(uint arg0)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg0 & 0xffff;
  iVar1 = sub_080C351C(arg0_00);
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    uVar3 = 0;
    while ((uVar3 < 0xc &&
           (iVar1 = sub_080C0148(uVar3 + 0x8004 & 0xffff), *(short *)(iVar1 + 0xe) != 0))) {
      uVar3 = uVar3 + 1;
    }
    iVar1 = uVar3 + 4;
    sub_080C0550(iVar1,arg0_00);
    iVar2 = sub_080C2340(0xe5);
    if (iVar2 != 0) {
      sub_080C2674(arg0_00);
    }
    sub_080C28F8(arg0_00);
  }
                    /* WARNING: Could not recover jumptable at 0x080c0684. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(iVar1);
  return;
}


// Race_GetName @ 0x080C068C

int Race_GetName(uint arg0)

{
  return (arg0 & 0xffff) * 0x10 + 0x81a5c34;
}


// ParentRace_GetName @ 0x080C069C

int ParentRace_GetName(uint arg0)

{
  return (arg0 & 0xffff) * 0x10 + 0x81a5f24;
}


// sub_080C06AC @ 0x080C06AC

int sub_080C06AC(uint arg0)

{
  return (arg0 & 0xffff) * 0x10 + 0x81a6014;
}


// sub_080C06BC @ 0x080C06BC

undefined4 sub_080C06BC(int arg0)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  uVar1 = *(ushort *)(iVar2 + 0x58) >> 8;
  if (uVar1 < 0x70) {
    uVar3 = 0;
  }
  else if (uVar1 < 0x90) {
    uVar3 = 1;
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}


// sub_080C06EC @ 0x080C06EC

void sub_080C06EC(int arg0,int arg1)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  dword dVar5;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  iVar2 = sub_080C2340(0xe0);
  if (iVar2 == 0) {
    dVar5 = (uint)*(ushort *)(iVar1 + 0x58) + arg1;
    if ((int)dVar5 < 0) {
      dVar5 = 0;
    }
    else if ((int)0xffff < (int)dVar5) {
      dVar5 = 0xffff;
    }
    *(ushort *)(iVar1 + 0x58) = (ushort)dVar5;
  }
  if (arg0 == 0) {
    DAT_03004798 = *(undefined2 *)(iVar1 + 0x58);
    puVar3 = &DAT_03004818;
    uVar4 = *(undefined2 *)(iVar1 + 0x58);
  }
  else {
    if (1 < arg0 - 1U) goto LAB_080c0762;
    puVar3 = (undefined2 *)(iVar1 + 0x58);
    uVar4 = DAT_03004718;
  }
  *puVar3 = uVar4;
LAB_080c0762:
  sub_080C06BC(arg0);
  return;
}


// sub_080C0774 @ 0x080C0774

void sub_080C0774(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  *(undefined2 *)(iVar1 + 0x58) = (undefined2)arg1;
  return;
}


// sub_080C0794 @ 0x080C0794

uint sub_080C0794(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (uint)*(ushort *)(iVar1 + 0x58);
}


// sub_080C07B0 @ 0x080C07B0

undefined4 sub_080C07B0(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C06BC(arg0);
  iVar2 = sub_080C06BC(arg1);
  if (iVar1 == 0) {
    if (iVar2 == 2) {
      uVar3 = 0;
      goto LAB_080c07da;
    }
  }
  else if ((iVar1 == 2) && (iVar2 == 0)) {
    uVar3 = 0;
    goto LAB_080c07da;
  }
  uVar3 = 1;
LAB_080c07da:
                    /* WARNING: Could not recover jumptable at 0x080c07de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar3);
  return uVar3;
}


// sub_080C07E0 @ 0x080C07E0

int sub_080C07E0(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(short *)(iVar1 + 0x12);
}


// sub_080C07FC @ 0x080C07FC

int sub_080C07FC(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(short *)(iVar1 + 0x14);
}


// sub_080C0818 @ 0x080C0818

uint sub_080C0818(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (uint)*(ushort *)(iVar1 + 0x10);
}


// sub_080C0830 @ 0x080C0830

undefined4 sub_080C0830(void)

{
  undefined4 in_r0;
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C0818(in_r0);
                    /* WARNING: Could not recover jumptable at 0x080c0848. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)((uVar1 & 0x8000) != 0);
  return uVar2;
}


// sub_080C084C @ 0x080C084C

void sub_080C084C(int arg0,uint arg1,uint arg2)

{
  int arg0_00;
  
  arg0_00 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  if ((arg1 & 0x800) == 0) {
    if ((arg2 & 0x800) == 0) {
      return;
    }
  }
  else if ((arg2 & 0x800) != 0) {
    return;
  }
  if (arg0 < 4) {
    sub_080BF938(arg0);
  }
  else {
    sub_080C05FC(arg0_00);
  }
  if (((arg1 & 0x8000) == 0) && (arg0 < 4)) {
    *(undefined2 *)(arg0_00 + 0x18) = *(undefined2 *)(arg0_00 + 0x1a);
    *(undefined2 *)(arg0_00 + 0x1c) = *(undefined2 *)(arg0_00 + 0x1e);
  }
  sub_080C65C8();
  return;
}


// sub_080C08BC @ 0x080C08BC

void sub_080C08BC(int arg0,undefined4 arg1)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  uVar1 = *(ushort *)(iVar2 + 0x10);
  *(ushort *)(iVar2 + 0x10) = (ushort)arg1 & uVar1;
  sub_080C084C(arg0,(uint)*(ushort *)(iVar2 + 0x10),(uint)uVar1);
  return;
}


// sub_080C08E8 @ 0x080C08E8

void sub_080C08E8(undefined4 arg0,uint arg1)

{
  sub_080C08F8(arg0,arg1 & 0xffff);
  return;
}


// sub_080C08F8 @ 0x080C08F8

undefined4 sub_080C08F8(int arg0,uint arg1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint arg1_00;
  uint uVar6;
  uint uVar7;
  int iVar8;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar5 = arg1 & 0xffff;
  iVar3 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  uVar7 = 0;
  uVar1 = *(ushort *)(iVar3 + 0x10);
  if (uVar5 == 0) {
    *(undefined2 *)(iVar3 + 0x10) = 0;
    uVar7 = 0;
  }
  else {
    iVar8 = 0xf;
    uVar6 = uVar5;
    do {
      if ((uVar6 & 1) != 0) {
        uVar2 = *(ushort *)(iVar3 + 0x10);
        if ((uVar2 & uVar5) == 0) {
          if ((*(ushort *)(iVar8 * 2 + 0x81a6044) & uVar2) == 0) {
            arg1_00 = uVar2 & *(ushort *)(iVar8 * 2 + 0x81a6064) | uVar5;
            *(short *)(iVar3 + 0x10) = (short)arg1_00;
            sub_080C084C(arg0,arg1_00,(uint)uVar1);
          }
          else {
            uVar7 = uVar7 | 2;
          }
        }
        else {
          uVar7 = uVar7 | 1;
        }
      }
      uVar6 = uVar6 >> 1;
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
  }
                    /* WARNING: Could not recover jumptable at 0x080c09a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar7);
  return uVar4;
}


// Race_GetParentId @ 0x080C09A4

uint Race_GetParentId(int arg0)

{
  return (uint)*(byte *)(arg0 + 0x81a6084);
}


// sub_080C09B0 @ 0x080C09B0

uint sub_080C09B0(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (uint)(*(short *)(iVar1 + 0xe) != 0);
}


// sub_080C09D4 @ 0x080C09D4

void sub_080C09D4(undefined4 arg0)

{
  int iVar1;
  
  iVar1 = sub_080C09B0(arg0);
  if (iVar1 != 0) {
    sub_080C0818(arg0);
  }
  return;
}


// sub_080C0A00 @ 0x080C0A00

undefined4 sub_080C0A00(undefined4 arg0)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C09B0(arg0);
  if ((iVar1 == 0) || (iVar1 = sub_080C0830(), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080c0a20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080C0A24 @ 0x080C0A24

uint sub_080C0A24(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (uint)(*(short *)(iVar1 + 0x1a) <= *(short *)(iVar1 + 0x18));
}


// sub_080C0A50 @ 0x080C0A50

uint sub_080C0A50(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (uint)(*(short *)(iVar1 + 0x1e) <= *(short *)(iVar1 + 0x1c));
}


// sub_080C0A7C @ 0x080C0A7C

void sub_080C0A7C(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  if (*(short *)(iVar1 + 0x18) < *(short *)(iVar1 + 0x1a)) {
    *(undefined2 *)(iVar1 + 0x18) = *(undefined2 *)(iVar1 + 0x1a);
  }
  return;
}


// sub_080C0AA8 @ 0x080C0AA8

void sub_080C0AA8(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  if (*(short *)(iVar1 + 0x1c) < *(short *)(iVar1 + 0x1e)) {
    *(undefined2 *)(iVar1 + 0x1c) = *(undefined2 *)(iVar1 + 0x1e);
  }
  return;
}


// sub_080C0AD4 @ 0x080C0AD4

undefined4 sub_080C0AD4(int arg0,int arg1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  if ((arg1 < 1) || (iVar3 = (int)*(short *)(iVar1 + 0x18), iVar3 <= *(short *)(iVar1 + 0x1a))) {
    iVar3 = (uint)*(ushort *)(iVar1 + 0x18) + arg1;
    *(short *)(iVar1 + 0x18) = (short)iVar3;
    iVar3 = iVar3 * 0x10000 >> 0x10;
    if (iVar3 < 0) {
      *(undefined2 *)(iVar1 + 0x18) = 0;
    }
    else if ((arg0 < 0x10) && ((int)999 < iVar3)) {
      *(undefined2 *)(iVar1 + 0x18) = 999;
    }
    iVar3 = (int)*(short *)(iVar1 + 0x18);
  }
                    /* WARNING: Could not recover jumptable at 0x080c0b28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(iVar3);
  return uVar2;
}


// sub_080C0B30 @ 0x080C0B30

void sub_080C0B30(int arg0,undefined4 arg1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  sVar1 = *(short *)(iVar3 + 0x18);
  sVar2 = *(short *)(iVar3 + 0x1a);
  sub_080C0AD4(arg0,arg1);
  if (*(short *)(iVar3 + 0x18) < 0) {
    *(undefined2 *)(iVar3 + 0x18) = 0;
  }
  else if ((*(short *)(iVar3 + 0x1a) < *(short *)(iVar3 + 0x18)) && (sVar1 <= sVar2)) {
    *(undefined2 *)(iVar3 + 0x18) = *(undefined2 *)(iVar3 + 0x1a);
  }
  return;
}


// sub_080C0B8C @ 0x080C0B8C

void sub_080C0B8C(int arg0,int arg1)

{
  int iVar1;
  undefined4 arg1_00;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  arg1_00 = __divsi3(arg1 * *(short *)(iVar1 + 0x18),100);
  sub_080C0AD4(arg0,arg1_00);
  return;
}


// sub_080C0BBC @ 0x080C0BBC

void sub_080C0BBC(int arg0,int arg1)

{
  int iVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  if ((arg1 < 1) || (iVar2 = (int)*(short *)(iVar1 + 0x1c), iVar2 <= *(short *)(iVar1 + 0x1e))) {
    iVar2 = (uint)*(ushort *)(iVar1 + 0x1c) + arg1;
    *(short *)(iVar1 + 0x1c) = (short)iVar2;
    iVar2 = iVar2 * 0x10000 >> 0x10;
    if (iVar2 < 0) {
      *(undefined2 *)(iVar1 + 0x1c) = 0;
    }
    else if ((int)999 < iVar2) {
      *(undefined2 *)(iVar1 + 0x1c) = 999;
    }
    iVar2 = (int)*(short *)(iVar1 + 0x1c);
  }
                    /* WARNING: Could not recover jumptable at 0x080c0c0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(iVar2);
  return;
}


// sub_080C0C14 @ 0x080C0C14

void sub_080C0C14(int arg0,undefined4 arg1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  sVar1 = *(short *)(iVar3 + 0x1c);
  sVar2 = *(short *)(iVar3 + 0x1e);
  sub_080C0BBC(arg0,arg1);
  if (*(short *)(iVar3 + 0x1c) < 0) {
    *(undefined2 *)(iVar3 + 0x1c) = 0;
  }
  else if ((*(short *)(iVar3 + 0x1e) < *(short *)(iVar3 + 0x1c)) && (sVar1 <= sVar2)) {
    *(undefined2 *)(iVar3 + 0x1c) = *(undefined2 *)(iVar3 + 0x1e);
  }
  return;
}


// sub_080C0C70 @ 0x080C0C70

void sub_080C0C70(int arg0,int arg1)

{
  int iVar1;
  
  sub_080F401C(arg0);
  iVar1 = sub_080C0AD4(arg0,-arg1);
  if (iVar1 < 1) {
    sub_080C0818(arg0);
    sub_080C08F8(arg0,0x8000);
    if (3 < arg0) {
      sub_080F4190(arg0);
    }
    sub_080C366C();
  }
  return;
}


// sub_080C0CAC @ 0x080C0CAC

void sub_080C0CAC(int arg0,int arg1)

{
  sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return;
}


// sub_080C0CD4 @ 0x080C0CD4

void sub_080C0CD4(int arg0,int arg1)

{
  sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return;
}


// sub_080C0CFC @ 0x080C0CFC

void sub_080C0CFC(int arg0)

{
  sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return;
}


// sub_080C0D18 @ 0x080C0D18

void sub_080C0D18(int arg0)

{
  sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return;
}


// sub_080C0D34 @ 0x080C0D34

void sub_080C0D34(int arg0)

{
  sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return;
}


// sub_080C0D50 @ 0x080C0D50

void sub_080C0D50(int arg0)

{
  sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return;
}


// sub_080C0D6C @ 0x080C0D6C

uint sub_080C0D6C(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(char *)(iVar1 + 0x40) & 0xffff;
}


// sub_080C0D90 @ 0x080C0D90

uint sub_080C0D90(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(char *)(iVar1 + 0x41) & 0xffff;
}


// sub_080C0DB4 @ 0x080C0DB4

uint sub_080C0DB4(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(char *)(iVar1 + 0x42) & 0xffff;
}


// sub_080C0DD8 @ 0x080C0DD8

void sub_080C0DD8(int arg0)

{
  sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return;
}


// sub_080C0DFC @ 0x080C0DFC

uint sub_080C0DFC(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(char *)(iVar1 + 0x44) & 0xffff;
}


// sub_080C0E20 @ 0x080C0E20

uint sub_080C0E20(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(char *)(iVar1 + 0x45) & 0xffff;
}


// sub_080C0E44 @ 0x080C0E44

uint sub_080C0E44(uint arg0,undefined4 arg1)

{
  uint in_r3;
  
  switch(arg1) {
  case 0:
    arg0 = sub_080C0D6C(arg0);
    break;
  case 1:
    arg0 = sub_080C0D90(arg0);
    break;
  case 2:
    arg0 = sub_080C0DB4(arg0);
    break;
  case 3:
    sub_080C0DD8(arg0);
    break;
  case 4:
    arg0 = sub_080C0DFC(arg0);
    break;
  case 5:
    arg0 = sub_080C0E20(arg0);
    break;
  default:
    goto switchD_080c0e54_default;
  }
  in_r3 = arg0 & 0xffff;
switchD_080c0e54_default:
  return in_r3;
}


// sub_080C0EAC @ 0x080C0EAC

undefined4 sub_080C0EAC(int arg0)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg0 < 0) {
    arg0 = 0;
  }
  else if (0x28 < arg0) {
    arg0 = 0x28;
  }
                    /* WARNING: Could not recover jumptable at 0x080c0ebe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(arg0);
  return uVar1;
}


// sub_080C0EC0 @ 0x080C0EC0

void sub_080C0EC0(int arg0,undefined4 arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  switch(arg1) {
  case 0:
    uVar2 = sub_080C0EAC(*(char *)(iVar1 + 0x28) + arg2);
    *(char *)(iVar1 + 0x28) = (char)uVar2;
    break;
  case 1:
    uVar2 = sub_080C0EAC(*(char *)(iVar1 + 0x29) + arg2);
    *(char *)(iVar1 + 0x29) = (char)uVar2;
    break;
  case 2:
    uVar2 = sub_080C0EAC(*(char *)(iVar1 + 0x2a) + arg2);
    *(char *)(iVar1 + 0x2a) = (char)uVar2;
    break;
  case 3:
    uVar2 = sub_080C0EAC(*(char *)(iVar1 + 0x2b) + arg2);
    *(char *)(iVar1 + 0x2b) = (char)uVar2;
    break;
  case 4:
    uVar2 = sub_080C0EAC(*(char *)(iVar1 + 0x2c) + arg2);
    *(char *)(iVar1 + 0x2c) = (char)uVar2;
    break;
  case 5:
    uVar2 = sub_080C0EAC(*(char *)(iVar1 + 0x2d) + arg2);
    *(char *)(iVar1 + 0x2d) = (char)uVar2;
  }
  return;
}


// sub_080C0F64 @ 0x080C0F64

undefined4 sub_080C0F64(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  
  sub_080C0EC0(in_r0,in_r1,0);
  return in_r0;
}


// sub_080C0F70 @ 0x080C0F70

void sub_080C0F70(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  *(undefined4 *)(iVar1 + 8) = arg1;
  return;
}


// sub_080C0F8C @ 0x080C0F8C

uint sub_080C0F8C(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (uint)*(byte *)(iVar1 + 0xd);
}


// sub_080C0FA4 @ 0x080C0FA4

void sub_080C0FA4(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  *(undefined1 *)(iVar1 + 0xd) = (undefined1)arg1;
  return;
}


// sub_080C0FC0 @ 0x080C0FC0

int sub_080C0FC0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    if (-1 < *(char *)(iVar1 + 0x30050e0)) {
      iVar2 = iVar2 + 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  return iVar2;
}


// sub_080C0FE8 @ 0x080C0FE8

undefined4 sub_080C0FE8(int arg0)

{
  int iVar1;
  undefined4 uVar2;
  int arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = 4;
  do {
    iVar1 = sub_080C09B0(arg0_00);
    if ((iVar1 != 0) && (uVar2 = sub_080C07E0(arg0_00), (short)uVar2 == arg0)) goto LAB_080c1014;
    arg0_00 = arg0_00 + 1;
  } while (arg0_00 < 0x10);
  arg0_00 = -1;
LAB_080c1014:
                    /* WARNING: Could not recover jumptable at 0x080c1018. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(arg0_00);
  return uVar2;
}


// sub_080C101C @ 0x080C101C

void sub_080C101C(void)

{
  int iVar1;
  int iVar2;
  int arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C104C();
  arg0 = 4;
  if (4 < iVar1 + 4) {
    do {
      iVar2 = sub_080C09B0(arg0);
      if (iVar2 == 0) goto LAB_080c1044;
      arg0 = arg0 + 1;
    } while (arg0 < iVar1 + 4);
  }
  arg0 = -1;
LAB_080c1044:
                    /* WARNING: Could not recover jumptable at 0x080c1048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(arg0);
  return;
}


// sub_080C104C @ 0x080C104C

int sub_080C104C(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 6;
  iVar1 = sub_080C2340(0xe6);
  if (iVar1 != 0) {
    iVar2 = 9;
  }
  iVar1 = sub_080C2340(0xe7);
  if (iVar1 != 0) {
    iVar2 = iVar2 + 3;
  }
  return iVar2;
}


// sub_080C1070 @ 0x080C1070

undefined4 sub_080C1070(int arg0)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  piVar2 = &DAT_081a60b8;
  do {
    if (arg0 < *piVar2) {
      return iVar1;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 100);
  return 99;
}


// sub_080C1098 @ 0x080C1098

undefined4 sub_080C1098(int arg0)

{
  return *(undefined4 *)((arg0 + -1) * 4 + 0x81a60b4);
}


// sub_080C10A8 @ 0x080C10A8

int sub_080C10A8(void)

{
  undefined4 in_r0;
  int iVar1;
  
  iVar1 = sub_080ED560(in_r0);
  return iVar1 << 5;
}


// sub_080C10B4 @ 0x080C10B4

int sub_080C10B4(uint arg0)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = sub_080C32D4(arg0 & 0xffff);
  uVar2 = sub_08131AB0(0xff,arg0 & 0xff);
  return (uVar1 & 0xff) + (uVar2 & 0xffff);
}


// sub_080C10E0 @ 0x080C10E0

void sub_080C10E0(void)

{
  return;
}


// sub_080C10E4 @ 0x080C10E4

void sub_080C10E4(undefined4 arg0)

{
  return;
}


// sub_080C10F4 @ 0x080C10F4

void sub_080C10F4(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  dword arg0;
  uint uVar4;
  undefined2 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_18;
  
  local_18 = 0;
  REG_DMA3SAD = &local_18;
  REG_DMA3DAD = 0x30046c0;
  REG_DMA3CNT = 0x8500063e;
  uVar1 = REG_DMA3CNT;
  uVar6 = 0;
  arg0 = 0x30046c0;
  do {
    sub_080BF748(arg0,uVar6);
    arg0 = arg0 + 0x80;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 4);
  sub_080BF938(0);
  uVar1 = sub_080C104C();
  DAT_03005183 = (undefined1)uVar1;
  uVar6 = 0;
  do {
    uVar4 = 0;
    puVar3 = (undefined1 *)(uVar6 * 8 + 0x81a6244);
    puVar2 = &DAT_030050c0 + uVar6 * 8;
    do {
      *puVar2 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar2 = puVar2 + 1;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 8);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 4);
  DAT_030050e0 = 0xff;
  DAT_030050e1 = 0xff;
  DAT_030050e2 = 0xff;
  DAT_030050e3 = 0xff;
  DAT_030050e4 = 0xff;
  DAT_030050e5 = 0xff;
  uVar6 = 0;
  puVar5 = &DAT_030046d8;
  do {
    sub_080BF8D8(uVar6);
    *puVar5 = puVar5[1];
    puVar5[2] = puVar5[3];
    puVar5 = puVar5 + 0x40;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 4);
  sub_080C01DC(0);
  DAT_0300580c = 0xff;
  DAT_03005814 = 0xff;
  DAT_0300581c = 0xff;
  DAT_03005824 = 0xff;
  DAT_0300582c = 0xff;
  DAT_03005834 = 0xff;
  DAT_0300583c = 0xff;
  DAT_03005844 = 0xff;
  uVar6 = 0;
  do {
    uVar4 = 0xc;
    uVar7 = uVar6 + 1;
    do {
      sub_080AF4B8(uVar4 & 0xffff,uVar6 & 0xffff);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
    uVar6 = uVar7;
  } while (uVar7 < 0xc);
  sub_080AF538(0xd,1);
  sub_080AF538(0xd,5);
  sub_080AF538(0xc,10);
  sub_080AF538(0xc,0xb);
  sub_080AF538(0xd,0xb);
  DAT_030050e8 = 0x80;
  DAT_03005f74 = 0;
  DAT_03005f75 = 0xff;
  DAT_03005f76 = 0;
  sub_080E4520();
  sub_080C271C();
  sub_080C27F0();
  sub_080C2968();
  sub_080D3E10();
  DAT_03005f66 = 0xffff;
  DAT_03005180 = 0;
  return;
}


// sub_080C12BC @ 0x080C12BC

void sub_080C12BC(void)

{
  return;
}


// sub_080C12C0 @ 0x080C12C0

void sub_080C12C0(uint arg0,uint arg1,uint arg2)

{
  DAT_03004610 = arg0 & 0xffff;
  DAT_03004514 = arg1 & 0xffff;
  DAT_03004614 = arg2 & 0xffff;
  DAT_03004544 = 0;
  sub_080A9AB4(0x80c1561);
  return;
}


// sub_080C1300 @ 0x080C1300

void sub_080C1300(uint arg0)

{
  DAT_030045fc = arg0 & 0xffff;
  DAT_03004544 = 2;
  sub_080A9AB4(0x80c1561);
  return;
}


// sub_080C1328 @ 0x080C1328

void sub_080C1328(void)

{
  undefined4 uVar1;
  undefined1 local_4 [4];
  
  REG_DMA3SAD = local_4;
  REG_DMA3DAD = 0x6008000;
  REG_DMA3CNT = 0x85000f00;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x81a91b8;
  REG_DMA3DAD = 0x600bc00;
  REG_DMA3CNT = 0x84001100;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x81b13b8;
  REG_DMA3DAD = 0x6010000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C1384 @ 0x080C1384

void sub_080C1384(void)

{
  sub_080ACFCC(3,0x81b6e30,0x30029b0,0x200);
  DAT_030029b0 = 0;
  sub_080ACFCC(3,0x81b6c30,&DAT_03002bb0,0x200);
  DAT_03002bb0 = 0;
  if ((DAT_0200ab04 & 0x7fff) == 0) {
    sub_080C67C0(0x30029b0,7);
  }
  else {
    sub_080C67C0(0x30029b0,0xc);
  }
  return;
}


// sub_080C13FC @ 0x080C13FC

void sub_080C13FC(ushort *arg0)

{
  *arg0 = *arg0 & 0xffbf;
  return;
}


