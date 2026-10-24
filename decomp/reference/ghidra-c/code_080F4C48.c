/* Ghidra decompilation of asm/code_080F4C48.s (reference only; not compiled). */

// sub_080F4C48 @ 0x080F4C48

void sub_080F4C48(undefined4 *arg0)

{
  undefined4 arg0_00;
  
  arg0_00 = *arg0;
  sub_080EFD5C(arg0_00,1);
  sub_080F49D4(arg0_00,arg0);
  return;
}


// sub_080F4C60 @ 0x080F4C60

void sub_080F4C60(undefined4 *arg0)

{
  undefined4 arg0_00;
  
  arg0_00 = *arg0;
  sub_080EFDA4(arg0_00,1);
  sub_080F49D4(arg0_00,arg0);
  return;
}


// sub_080F4C78 @ 0x080F4C78

void sub_080F4C78(undefined4 *arg0)

{
  undefined4 arg0_00;
  
  arg0_00 = *arg0;
  sub_080EFDEC(arg0_00,1);
  sub_080F49D4(arg0_00,arg0);
  return;
}


// sub_080F4C90 @ 0x080F4C90

void sub_080F4C90(int *arg0,uint arg1,int arg2)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080EFAB0();
  if ((arg1 & uVar1 & 0xffff) == 0) {
    sub_080EFAD0(*arg0,(int)(short)arg1);
    if ((-1 < arg2) && (arg0[2] = arg2, 0xf < *arg0)) {
      arg0[2] = arg2 + 1;
    }
  }
  else {
    arg0[2] = 0x96;
    arg0[3] = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080f4cd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F4CD4 @ 0x080F4CD4

void sub_080F4CD4(int *arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080F3F44();
  if ((uVar1 & 0x800) == 0) {
    sub_080F3F74(0x800);
    arg0[2] = 0xcb;
    if (0xf < *arg0) {
      arg0[2] = 0xcc;
    }
  }
  else {
    arg0[2] = 0x96;
    arg0[3] = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080f4d08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F4D0C @ 0x080F4D0C

void sub_080F4D0C(void)

{
  undefined4 in_r0;
  
  sub_080F4C90(in_r0,1,0xcd);
  return;
}


// sub_080F4D1C @ 0x080F4D1C

void sub_080F4D1C(void)

{
  undefined4 in_r0;
  
  sub_080F4C90(in_r0,2,0xcf);
  return;
}


// sub_080F4D2C @ 0x080F4D2C

void sub_080F4D2C(int arg0,undefined4 arg1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  sVar1 = *(short *)(iVar2 + 0x18) + (short)arg1;
  *(short *)(iVar2 + 0x18) = sVar1;
  if (*(short *)(iVar2 + 0x1a) < sVar1) {
    *(undefined2 *)(iVar2 + 0x18) = *(undefined2 *)(iVar2 + 0x1a);
  }
  return;
}


// sub_080F4D64 @ 0x080F4D64

undefined4 sub_080F4D64(undefined4 *arg0,uint arg1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  dword dVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0xffffffff) {
    dVar6 = 999;
  }
  else {
    uVar5 = *arg0;
    uVar1 = sub_080C0E20(arg0[1]);
    uVar2 = sub_080C0D90(uVar5);
    iVar3 = sub_080C1F94(uVar2 & 0xffff,2);
    uVar2 = sub_080C0DB4(uVar5);
    uVar4 = sub_080C2244();
    dVar6 = (((uVar1 & 0xffff) >> 1) + iVar3 + (uVar2 & 0xffff) << (arg1 & 0xff)) + (uVar4 & 7);
  }
                    /* WARNING: Could not recover jumptable at 0x080f4db4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*UNRECOVERED_JUMPTABLE)(dVar6);
  return uVar5;
}


// sub_080F4DBC @ 0x080F4DBC

void sub_080F4DBC(int arg0,undefined4 arg1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = *(uint *)(arg0 + 4);
  iVar1 = sub_080C0830();
  if (iVar1 == 0) {
    uVar2 = sub_080C07E0(arg0_00);
    sub_080F40C4((int)(short)uVar2);
    uVar3 = sub_080C0818(arg0_00);
    if ((uVar3 & 0x4000) == 0) {
      iVar1 = sub_080C0A24(arg0_00);
      if (iVar1 == 0) {
        uVar2 = sub_080F4D64(arg0,arg1);
        sub_080F4D2C(arg0_00,uVar2);
        uVar2 = 1;
        goto LAB_080f4e16;
      }
    }
    else {
      sub_080C0290(arg0_00 & 0xffff,0);
    }
  }
  uVar2 = 0;
LAB_080f4e16:
  *(undefined4 *)(arg0 + 0xc) = uVar2;
                    /* WARNING: Could not recover jumptable at 0x080f4e1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F4E20 @ 0x080F4E20

void sub_080F4E20(void)

{
  undefined4 in_r0;
  
  sub_080F4DBC(in_r0,0);
  return;
}


// sub_080F4E2C @ 0x080F4E2C

void sub_080F4E2C(void)

{
  undefined4 in_r0;
  
  sub_080F4DBC(in_r0,2);
  return;
}


// sub_080F4E38 @ 0x080F4E38

void sub_080F4E38(void)

{
  undefined4 in_r0;
  
  sub_080F4DBC(in_r0,0xffffffff);
  return;
}


// sub_080F4E48 @ 0x080F4E48

void sub_080F4E48(int *arg0,undefined4 arg1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  int local_34;
  int local_30;
  int iStack_2c;
  int local_28;
  int iStack_24;
  int iStack_20;
  int local_1c;
  int iStack_18;
  
  iVar3 = 0;
  local_34 = *arg0;
  local_30 = arg0[1];
  iStack_2c = arg0[2];
  local_28 = arg0[3];
  iStack_24 = arg0[4];
  iStack_20 = arg0[5];
  local_1c = arg0[6];
  iStack_18 = arg0[7];
  if (*arg0 < 0x10) {
    iVar2 = 0;
    do {
      local_30 = sub_080F40EC(iVar2);
      if ((-1 < local_30) && (sub_080F4DBC(&local_34,arg1), local_28 != 0)) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 6);
  }
  else {
    iVar2 = 0x10;
    do {
      iVar1 = sub_080C09B0(iVar2);
      if ((iVar1 != 0) && (local_30 = iVar2, sub_080F4DBC(&local_34,arg1), local_28 != 0)) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x18);
  }
  if (iVar3 == 0) {
    arg0[3] = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080f4ebe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F4EC0 @ 0x080F4EC0

void sub_080F4EC0(void)

{
  undefined4 in_r0;
  
  sub_080F4E48(in_r0,0);
  return;
}


// sub_080F4ECC @ 0x080F4ECC

void sub_080F4ECC(void)

{
  undefined4 in_r0;
  
  sub_080F4E48(in_r0,2);
  return;
}


// sub_080F4ED8 @ 0x080F4ED8

void sub_080F4ED8(void)

{
  undefined4 in_r0;
  
  sub_080F4E48(in_r0,0xffffffff);
  return;
}


// sub_080F4EE8 @ 0x080F4EE8

void sub_080F4EE8(int arg0,undefined4 arg1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080ED794(arg1);
  uVar5 = *(undefined4 *)(arg0 + 4);
  iVar2 = sub_080C0830();
  if (iVar2 == 0) {
    uVar3 = sub_080C07E0(uVar5);
    sub_080F40C4((int)(short)uVar3);
    uVar4 = sub_080C0818(uVar5);
    if ((uVar1 & 0xffff & uVar4) != 0) {
      sub_080C08BC(uVar5,~(uVar1 & 0xffff) & 0xffff);
      uVar5 = 1;
      goto LAB_080f4f30;
    }
  }
  uVar5 = 0;
LAB_080f4f30:
  *(undefined4 *)(arg0 + 0xc) = uVar5;
                    /* WARNING: Could not recover jumptable at 0x080f4f36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F4F38 @ 0x080F4F38

void sub_080F4F38(void)

{
  undefined4 in_r0;
  
  sub_080F4EE8(in_r0,0x31);
  return;
}


// sub_080F4F44 @ 0x080F4F44

void sub_080F4F44(void)

{
  undefined4 in_r0;
  
  sub_080F4EE8(in_r0,0x33);
  return;
}


// sub_080F4F50 @ 0x080F4F50

void sub_080F4F50(void)

{
  undefined4 in_r0;
  
  sub_080F4EE8(in_r0,0x34);
  return;
}


// sub_080F4F5C @ 0x080F4F5C

void sub_080F4F5C(void)

{
  undefined4 in_r0;
  
  sub_080F4EE8(in_r0,0x35);
  return;
}


// sub_080F4F68 @ 0x080F4F68

void sub_080F4F68(int *arg0)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  int local_30;
  int local_2c;
  int iStack_28;
  int local_24;
  int iStack_20;
  int iStack_1c;
  int local_18;
  int iStack_14;
  
  iVar3 = 0;
  local_30 = *arg0;
  local_2c = arg0[1];
  iStack_28 = arg0[2];
  local_24 = arg0[3];
  iStack_20 = arg0[4];
  iStack_1c = arg0[5];
  local_18 = arg0[6];
  iStack_14 = arg0[7];
  if (*arg0 < 0x10) {
    iVar2 = 0;
    do {
      local_2c = sub_080F40EC(iVar2);
      if ((-1 < local_2c) && (sub_080F4EE8(&local_30,0x31), local_24 != 0)) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 6);
  }
  else {
    iVar2 = 0x10;
    do {
      iVar1 = sub_080C09B0(iVar2);
      if ((iVar1 != 0) && (local_2c = iVar2, sub_080F4EE8(&local_30,0x31), local_24 != 0)) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x18);
  }
  if (iVar3 == 0) {
    arg0[3] = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080f4fdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F4FE0 @ 0x080F4FE0

void sub_080F4FE0(int arg0)

{
  uint uVar1;
  undefined4 uVar2;
  int arg0_00;
  
  arg0_00 = *(int *)(arg0 + 4);
  uVar1 = sub_080C0818(arg0_00);
  uVar2 = 0;
  if ((uVar1 & 0x8000) != 0) {
    sub_080C08BC(arg0_00,1);
    sub_080C0A7C(arg0_00);
    sub_080C0B8C(arg0_00,0xffffffb5);
    uVar2 = sub_080C07E0(arg0_00);
    sub_080F40C4((int)(short)uVar2);
    *(undefined4 *)(arg0 + 8) = 0xe5;
    if (0xf < arg0_00) {
      *(undefined4 *)(arg0 + 8) = 0xe6;
    }
    uVar2 = 1;
  }
  *(undefined4 *)(arg0 + 0xc) = uVar2;
  return;
}


// sub_080F503C @ 0x080F503C

void sub_080F503C(int arg0)

{
  uint uVar1;
  undefined4 uVar2;
  int arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = *(int *)(arg0 + 4);
  uVar1 = sub_080C0818(arg0_00);
  if ((uVar1 & 0x8000) == 0) {
    *(undefined4 *)(arg0 + 0xc) = 0;
  }
  else {
    *(undefined4 *)(arg0 + 0xc) = 1;
    sub_080C08BC(arg0_00,1);
    sub_080C0A7C(arg0_00);
    uVar2 = sub_080C07E0(arg0_00);
    sub_080F40C4((int)(short)uVar2);
    *(undefined4 *)(arg0 + 8) = 0xe5;
    if (0xf < arg0_00) {
      *(undefined4 *)(arg0 + 8) = 0xe6;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080f508e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5090 @ 0x080F5090

void sub_080F5090(int *arg0)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int arg0_00;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar5 = 0;
  arg0_00 = *arg0;
  if (arg0_00 < 0x10) {
    iVar4 = 0;
    do {
      iVar1 = sub_080F40EC(iVar4);
      if ((((-1 < iVar1) && (iVar2 = sub_080C0830(), iVar2 == 0)) && (iVar1 != arg0_00)) &&
         (iVar2 = sub_080C0A24(iVar1), iVar2 == 0)) {
        sub_080C0A7C(iVar1);
        iVar5 = iVar5 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 6);
  }
  else {
    iVar4 = 0x10;
    do {
      iVar1 = sub_080C0A00(iVar4);
      if (((iVar1 != 0) && (iVar4 != arg0_00)) && (iVar1 = sub_080C0A24(iVar4), iVar1 == 0)) {
        sub_080C0A7C(iVar4);
        iVar5 = iVar5 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x18);
  }
  if (iVar5 == 0) {
    arg0[3] = 0;
  }
  else {
    arg0[2] = 0xd9;
    if (0xf < arg0_00) {
      arg0[2] = 0xda;
    }
    sub_080C08E8(arg0_00,0x8000);
    sub_080F4054(arg0_00,0);
    uVar3 = sub_080C07E0(arg0_00);
    sub_080F40C4((int)(short)uVar3);
    if (arg0_00 - 4U < 0xc) {
      sub_080F4190(arg0_00);
    }
    sub_080C366C();
    arg0[3] = 1;
    sub_080E760C();
  }
                    /* WARNING: Could not recover jumptable at 0x080f5156. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5158 @ 0x080F5158

void sub_080F5158(int arg0)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((DAT_03005180 == 1) || (iVar1 = sub_080F3DD8(), iVar1 == 0)) {
    *(undefined4 *)(arg0 + 8) = 0xffffffff;
    uVar2 = 0;
  }
  else {
    sub_080F3F74(0x100);
    uVar2 = 1;
  }
  *(undefined4 *)(arg0 + 0xc) = uVar2;
  return;
}


// sub_080F5194 @ 0x080F5194

void sub_080F5194(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C5240();
  if (iVar1 == 1) {
    sub_080C5224();
    *(undefined4 *)(arg0 + 0xc) = 1;
  }
  else {
    *(undefined4 *)(arg0 + 0xc) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080f51b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F51B4 @ 0x080F51B4

void sub_080F51B4(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C5320();
  if (iVar1 == 1) {
    sub_080C5304();
    *(undefined4 *)(arg0 + 0xc) = 1;
  }
  else {
    *(undefined4 *)(arg0 + 0xc) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080f51d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F51D4 @ 0x080F51D4

void sub_080F51D4(int arg0)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080ED8F4();
  if (((uVar1 & 0x100) == 0) && (iVar2 = sub_080C2340(0x166), iVar2 == 0)) {
    sub_080ED90C(0x2000);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  *(undefined4 *)(arg0 + 0xc) = uVar3;
                    /* WARNING: Could not recover jumptable at 0x080f5206. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5208 @ 0x080F5208

void sub_080F5208(int arg0)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080F3F44();
  if ((uVar1 & 0x80) == 0) {
    sub_080F3F74(0x80);
    uVar2 = sub_080C1D9C();
    DAT_03005f7b = ((byte)uVar2 & 0xf0) + 1;
  }
  else {
    *(undefined4 *)(arg0 + 8) = 0x96;
  }
  *(undefined4 *)(arg0 + 0xc) = 1;
                    /* WARNING: Could not recover jumptable at 0x080f523e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5248 @ 0x080F5248

void sub_080F5248(void)

{
  return;
}


// sub_080F524C @ 0x080F524C

void sub_080F524C(void)

{
  return;
}


// sub_080F5250 @ 0x080F5250

void sub_080F5250(void)

{
  return;
}


// sub_080F5254 @ 0x080F5254

void sub_080F5254(undefined4 *arg0)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080F3F14(*arg0);
  arg0_00 = arg0[1];
  arg0[3] = 0;
  arg0[2] = 0xffffffff;
  sub_080EFAB0();
  arg0[3] = 0;
  if ((((short)uVar1 == 0x54) && (1 < arg0_00 - 1U)) || (((short)uVar1 == 0x5e && (arg0_00 != 0))))
  goto LAB_080f53e0;
  uVar2 = sub_080C0818(arg0_00);
  if ((uVar2 & 0x1000) == 0) {
    arg0[2] = 0x39a;
    sub_080C08E8(arg0_00,0x1000);
  }
  else {
    if (3 < arg0_00) goto LAB_080f53e0;
    uVar2 = sub_080F3F44();
    if ((uVar2 & 0xc) != 0) {
      iVar3 = sub_080C06BC(arg0_00);
      iVar5 = -1;
      if (((uVar2 & 4) != 0) && (iVar5 = -1, iVar3 == 2)) {
        sub_080F3F58(0xfffffffb);
        iVar5 = 0xe0;
      }
      if ((uVar2 & 8) == 0) {
LAB_080f5302:
        if (iVar5 < 0) goto LAB_080f5316;
      }
      else if (iVar5 < 0) {
        if (iVar3 == 0) {
          sub_080F3F58(0xfffffff7);
          iVar5 = 0xf4;
        }
        goto LAB_080f5302;
      }
      sub_080F3E38(iVar5);
      arg0[2] = 0x138;
      goto LAB_080f53e0;
    }
LAB_080f5316:
    uVar2 = sub_080F3F44();
    if ((uVar2 & 0x800) != 0) {
      arg0[2] = 0x153;
      if (arg0_00 < 0x10) {
        arg0[2] = 0x154;
      }
      sub_080F3F58(0xfffff7ff);
      goto LAB_080f53e0;
    }
    uVar1 = sub_080C0F8C(arg0_00);
    iVar5 = (short)uVar1 + -1;
    if (iVar5 < 1) goto LAB_080f53e0;
    sub_080C0FA4(arg0_00,iVar5);
    uVar1 = sub_080C1098(iVar5);
    sub_080C0F70(arg0_00,uVar1);
    iVar3 = 0;
    iVar5 = 0;
    iVar6 = 0;
    do {
      iVar4 = sub_080C0F64();
      if (iVar5 < iVar4) {
        iVar5 = iVar4;
        iVar3 = iVar6;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 6);
    sub_080C0EC0(arg0_00,iVar3,0xffffffff);
    uVar1 = sub_080C07E0(arg0_00);
    sub_080F40C4((int)(short)uVar1);
    arg0[2] = 0x119;
    sub_080EDA7C(0xffff);
    sub_080C08BC(arg0_00,0xefff);
  }
  sub_080C6FD8();
  arg0[3] = 1;
LAB_080f53e0:
                    /* WARNING: Could not recover jumptable at 0x080f53ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F53F0 @ 0x080F53F0

void sub_080F53F0(int arg0)

{
  sub_080EFDA4(*(undefined4 *)(arg0 + 4),0xffffffff);
  return;
}


// sub_080F5400 @ 0x080F5400

void sub_080F5400(undefined4 *arg0)

{
  uint uVar1;
  
  sub_080EFAB0();
  uVar1 = sub_080C0818(*arg0);
  if ((uVar1 & 0x4000) == 0) {
    sub_080F4D2C(*arg0,arg0[6]);
  }
  return;
}


// sub_080F5428 @ 0x080F5428

void sub_080F5428(void)

{
  undefined4 in_r0;
  
  sub_080F4C90(in_r0,8,0xffffffff);
  return;
}


// sub_080F5438 @ 0x080F5438

void sub_080F5438(void)

{
  undefined4 in_r0;
  
  sub_080F4C90(in_r0,0x10,0xffffffff);
  return;
}


// sub_080F5448 @ 0x080F5448

void sub_080F5448(undefined4 *arg0)

{
  sub_080C35C4(*arg0,9);
  return;
}


// sub_080F5458 @ 0x080F5458

void sub_080F5458(undefined4 *arg0)

{
  int iVar1;
  undefined4 arg0_00;
  
  arg0_00 = *arg0;
  sub_080F4104(arg0_00);
  sub_080C08F8(arg0_00,0x8000);
  sub_08126834(0xffffffff);
  iVar1 = sub_080ED9F4();
  if (iVar1 == 0) {
    sub_080ED90C(0x200);
  }
  sub_080E760C();
  return;
}


// sub_080F5490 @ 0x080F5490

void sub_080F5490(int *arg0)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  dword dVar5;
  int iVar6;
  
  if ((0xf < *arg0) && (uVar1 = sub_080C2244(), (uVar1 & 7) != 0)) {
    iVar2 = sub_080EDA24((uint)(0x13 < *arg0));
    iVar3 = sub_080ED954();
    iVar6 = 8;
    if (iVar3 != 0) {
      iVar6 = 4;
    }
    if ((iVar2 < iVar6) && (iVar2 = sub_080EF224(*arg0,1), iVar2 != 0)) {
      uVar4 = sub_080C07E0(*arg0);
      sub_080F40C4((int)(short)uVar4);
      dVar5 = 0x139;
      goto LAB_080f54f4;
    }
  }
  arg0[3] = 0;
  dVar5 = 0x11c;
LAB_080f54f4:
  arg0[2] = dVar5;
  return;
}


// sub_080F54FC @ 0x080F54FC

void sub_080F54FC(undefined4 *arg0)

{
  int iVar1;
  int iVar2;
  
  iVar1 = sub_080EFC1C(1,*arg0,1);
  iVar2 = sub_080EFC1C(3,*arg0,1);
  if ((iVar1 != 0) && (iVar2 != 0)) {
    arg0[2] = 0x96;
    arg0[3] = 0;
  }
  return;
}


// sub_080F552C @ 0x080F552C

void sub_080F552C(undefined4 *arg0)

{
  int iVar1;
  int iVar2;
  
  iVar1 = sub_080EFC1C(2,*arg0,1);
  iVar2 = sub_080EFC1C(4,*arg0,1);
  if ((iVar1 != 0) && (iVar2 != 0)) {
    arg0[2] = 0x96;
    arg0[3] = 0;
  }
  return;
}


// sub_080F555C @ 0x080F555C

void sub_080F555C(int *arg0)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2244();
  arg0[6] = 0xffff;
  arg0[3] = 0;
  if ((uVar1 & 0xf0) == 0) {
    sub_080C08F8(*arg0,0x10);
  }
  else if (*arg0 < 0x10) {
    uVar1 = 0x10;
    do {
      iVar2 = sub_080C0A00(uVar1);
      if (iVar2 != 0) {
        sub_080C08F8(uVar1,0x10);
        uVar4 = sub_080C0818(uVar1);
        if ((uVar4 & 0x10) != 0) {
          arg0[3] = 1;
        }
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x18);
  }
  else {
    uVar1 = 0;
    do {
      iVar2 = sub_080F40EC(uVar1);
      if ((-1 < iVar2) && (iVar3 = sub_080C0830(), iVar3 == 0)) {
        sub_080C08F8(iVar2,0x10);
        uVar4 = sub_080C0818(iVar2);
        if ((uVar4 & 0x10) != 0) {
          arg0[3] = 1;
        }
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 6);
  }
                    /* WARNING: Could not recover jumptable at 0x080f55f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F55F4 @ 0x080F55F4

undefined4 sub_080F55F4(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = sub_080C06BC(arg0);
  iVar2 = sub_080C06BC(arg1);
  uVar3 = 0;
  if ((iVar2 == 1) || (iVar2 == iVar1)) {
    uVar3 = 1;
  }
  return uVar3;
}


// sub_080F5618 @ 0x080F5618

void sub_080F5618(int *arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080F55F4(*arg0,arg0[1]);
  if (iVar1 == 1) {
    iVar1 = 0;
    goto LAB_080f565a;
  }
  if (*arg0 < 0x10) {
    iVar1 = arg0[1];
    if (iVar1 < 0x10) {
LAB_080f5640:
      iVar1 = sub_080F401C(iVar1);
      if (iVar1 < 0) {
        iVar1 = iVar1 + 7;
      }
      iVar1 = iVar1 >> 3;
      goto LAB_080f565a;
    }
  }
  else {
    iVar1 = arg0[1];
    if (0xf < iVar1) goto LAB_080f5640;
  }
  iVar1 = sub_080F401C(iVar1);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 3;
  }
  iVar1 = iVar1 >> 2;
LAB_080f565a:
  arg0[6] = iVar1;
                    /* WARNING: Could not recover jumptable at 0x080f5660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5664 @ 0x080F5664

void sub_080F5664(int arg0)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_080EDAD0();
  if (iVar1 == 0) {
    uVar2 = sub_080C2244();
    if ((uVar2 & 3) == 0) {
      sub_080C1D00(0x40);
      *(undefined4 *)(arg0 + 0x18) = 0;
      *(undefined4 *)(arg0 + 0xc) = 0;
    }
  }
  return;
}


// sub_080F5690 @ 0x080F5690

void sub_080F5690(int *arg0)

{
  int iVar1;
  int iVar2;
  int arg0_00;
  
  arg0_00 = *arg0;
  iVar1 = sub_080F2F64(arg0_00 - 0x8000U & 0xffff);
  iVar2 = sub_080BF648((uint)*(ushort *)(iVar1 + 0x12));
  *(undefined2 *)(iVar1 + 0x18) = *(undefined2 *)(iVar2 + 2);
  *(undefined2 *)(iVar1 + 0x1a) = *(undefined2 *)(iVar2 + 2);
  *(undefined2 *)(iVar1 + 0x1c) = *(undefined2 *)(iVar2 + 4);
  *(undefined2 *)(iVar1 + 0x1e) = *(undefined2 *)(iVar2 + 4);
  *(undefined2 *)(iVar1 + 0x10) = 0;
  sub_080E760C();
  iVar1 = sub_080EFBFC();
  if (iVar1 != 0) {
    sub_080EFD14(arg0_00,-iVar1);
  }
  iVar1 = sub_080EFD3C();
  if (iVar1 != 0) {
    sub_080EFD5C(arg0_00,-iVar1);
  }
  iVar1 = sub_080EFD84();
  if (iVar1 != 0) {
    sub_080EFDA4(arg0_00,-iVar1);
  }
  iVar1 = sub_080EFDCC();
  if (iVar1 != 0) {
    sub_080EFDEC(arg0_00,-iVar1);
  }
  return;
}


// sub_080F5714 @ 0x080F5714

void sub_080F5714(int arg0)

{
  undefined4 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (*(int *)(arg0 + 4) < 4) {
    uVar1 = 0;
  }
  else {
    iVar2 = sub_080BFFF0();
    if (iVar2 == 0) {
      iVar2 = sub_080F401C(*(undefined4 *)(arg0 + 4));
      iVar2 = iVar2 / 2;
    }
    else {
      iVar2 = sub_080F401C(*(undefined4 *)(arg0 + 4));
      if (iVar2 < 0) {
        iVar2 = iVar2 + 3;
      }
      iVar2 = iVar2 >> 2;
    }
    *(int *)(arg0 + 0x18) = iVar2;
    if (*(int *)(arg0 + 0x18) != 0) goto LAB_080f5752;
    uVar1 = 1;
  }
  *(undefined4 *)(arg0 + 0x18) = uVar1;
LAB_080f5752:
                    /* WARNING: Could not recover jumptable at 0x080f5756. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5758 @ 0x080F5758

void sub_080F5758(int arg0)

{
  int arg0_00;
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint arg0_01;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined4 *)(arg0 + 0xc) = 0;
  arg0_01 = 0;
  do {
    arg0_00 = sub_080F40EC(arg0_01);
    if (((-1 < arg0_00) && (iVar1 = sub_080C0830(), iVar1 == 0)) &&
       (iVar1 = sub_080C0E44(arg0_00,1), iVar1 < 0x14)) {
      if (iVar1 < 10) {
        uVar2 = sub_080C2244();
        if ((uVar2 & 0xe0) == 0) {
          uVar3 = sub_080C0818(arg0_00);
          uVar2 = 0x1000;
          uVar3 = uVar3 & 0x1000;
          goto joined_r0x080f57c4;
        }
      }
      else {
        uVar2 = sub_080C2244();
        if ((uVar2 & 0xf0) == 0) {
          uVar3 = sub_080C0818(arg0_00);
          uVar2 = 0x20;
          uVar3 = uVar3 & 0x20;
joined_r0x080f57c4:
          if (uVar3 == 0) {
            sub_080C08F8(arg0_00,uVar2);
            uVar3 = sub_080C0818(arg0_00);
            if ((uVar2 & uVar3) != 0) {
              *(undefined4 *)(arg0 + 0xc) = 1;
            }
          }
        }
      }
    }
    arg0_01 = arg0_01 + 1;
    if (5 < arg0_01) {
      *(dword *)(arg0 + 0x18) = 0xffff;
                    /* WARNING: Could not recover jumptable at 0x080f57ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  } while( true );
}


// sub_080F57F4 @ 0x080F57F4

int sub_080F57F4(undefined4 arg0,uint arg1)

{
  int arg0_00;
  int iVar1;
  int iVar2;
  uint arg0_01;
  int iVar3;
  int iVar4;
  
  iVar3 = 100;
  iVar4 = -1;
  arg0_01 = 0;
  do {
    arg0_00 = sub_080F40EC(arg0_01);
    if ((((-1 < arg0_00) && (iVar1 = sub_080C0830(), iVar1 == 0)) &&
        (iVar1 = sub_080C0E44(arg0_00,arg0), iVar1 < iVar3)) &&
       (iVar2 = sub_080F3214(arg0_00,arg1 & 0xffff), iVar2 == 1)) {
      iVar3 = iVar1;
      iVar4 = arg0_00;
    }
    arg0_01 = arg0_01 + 1;
  } while (arg0_01 < 6);
  return iVar4;
}


// sub_080F5858 @ 0x080F5858

void sub_080F5858(int arg0)

{
  int arg0_00;
  uint uVar1;
  
  arg0_00 = sub_080F57F4(0,0x20);
  *(undefined4 *)(arg0 + 0xc) = 0;
  if ((arg0_00 == -1) || (uVar1 = sub_080C0818(arg0_00), (uVar1 & 0x20) != 0)) {
    *(undefined4 *)(arg0 + 0x18) = 0;
  }
  else {
    sub_080EDA7C(0x20);
    *(int *)(arg0 + 4) = arg0_00;
    *(dword *)(arg0 + 0x18) = 0xffff;
    *(undefined4 *)(arg0 + 0xc) = 1;
  }
  return;
}


// sub_080F58A0 @ 0x080F58A0

void sub_080F58A0(int arg0)

{
  int arg0_00;
  uint uVar1;
  
  arg0_00 = sub_080F57F4(4,0x1000);
  *(undefined4 *)(arg0 + 0xc) = 0;
  if ((arg0_00 == -1) || (uVar1 = sub_080C0818(arg0_00), (uVar1 & 0x1000) != 0)) {
    *(undefined4 *)(arg0 + 0x18) = 0;
  }
  else {
    sub_080EDA7C(0x1000);
    *(int *)(arg0 + 4) = arg0_00;
    *(dword *)(arg0 + 0x18) = 0xffff;
    *(undefined4 *)(arg0 + 0xc) = 1;
  }
  return;
}


// sub_080F58EC @ 0x080F58EC

void sub_080F58EC(int arg0)

{
  int arg0_00;
  uint uVar1;
  
  arg0_00 = sub_080F57F4(5,0x2000);
  *(undefined4 *)(arg0 + 0xc) = 0;
  if ((arg0_00 == -1) || (uVar1 = sub_080C0818(arg0_00), (uVar1 & 0x2000) != 0)) {
    *(undefined4 *)(arg0 + 0x18) = 0;
  }
  else {
    sub_080EDA7C(0x2000);
    *(int *)(arg0 + 4) = arg0_00;
    *(dword *)(arg0 + 0x18) = 0xffff;
    *(undefined4 *)(arg0 + 0xc) = 1;
  }
  return;
}


// sub_080F5938 @ 0x080F5938

undefined4 sub_080F5938(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080F57F4(2,0x8000);
  return uVar1;
}


// sub_080F5948 @ 0x080F5948

void sub_080F5948(int arg0)

{
  int arg0_00;
  uint uVar1;
  
  arg0_00 = sub_080F5938();
  *(undefined4 *)(arg0 + 0xc) = 0;
  if ((arg0_00 != -1) && (uVar1 = sub_080C0818(arg0_00), (uVar1 & 0x8000) == 0)) {
    sub_080EDA7C(0x8000);
    *(int *)(arg0 + 4) = arg0_00;
    *(undefined4 *)(arg0 + 0xc) = 1;
  }
  *(dword *)(arg0 + 0x18) = 0xffff;
  return;
}


// sub_080F5988 @ 0x080F5988

void sub_080F5988(int arg0)

{
  int arg0_00;
  uint uVar1;
  
  arg0_00 = sub_080F57F4(1,0x8000);
  *(undefined4 *)(arg0 + 0xc) = 0;
  if ((arg0_00 != -1) && (uVar1 = sub_080C0818(arg0_00), (uVar1 & 0x8000) == 0)) {
    sub_080EDA7C(0x8000);
    *(int *)(arg0 + 4) = arg0_00;
    *(undefined4 *)(arg0 + 0xc) = 1;
  }
  *(dword *)(arg0 + 0x18) = 0xffff;
  return;
}


// sub_080F59CC @ 0x080F59CC

void sub_080F59CC(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C3168();
  if (iVar1 == 0) {
    *(undefined4 *)(arg0 + 0xc) = 0;
  }
  else {
    iVar1 = iVar1 / 2;
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    sub_080C3114(-iVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x080f59f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F59F8 @ 0x080F59F8

void sub_080F59F8(int *arg0)

{
  dword dVar1;
  
  if (*arg0 < 0x10) {
    dVar1 = 0x11ac;
  }
  else {
    dVar1 = 0x11ae;
  }
  if (*(short *)(dVar1 + 0x203c200) == -1) {
    *(short *)(dVar1 + 0x203c200) = (short)*arg0;
  }
  else {
    arg0[2] = 0x7e;
    arg0[3] = 0;
  }
  return;
}


// sub_080F5A38 @ 0x080F5A38

void sub_080F5A38(int *arg0)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  short sVar7;
  short sVar8;
  int arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = *arg0;
  uVar1 = sub_080C2244();
  iVar2 = sub_080ED9F4();
  if ((iVar2 < 2) || ((uVar1 & 7) != 0)) {
    arg0[2] = 0x7e;
    arg0[3] = 0;
  }
  else {
    iVar2 = 0x10;
    do {
      if ((iVar2 != arg0_00) && (iVar3 = sub_080C0A00(iVar2), iVar3 != 0)) {
        iVar3 = sub_080C07E0(arg0_00);
        iVar4 = sub_080C07E0(iVar2);
        if (iVar3 * 0x10000 + iVar4 * -0x10000 == 0) {
          uVar5 = sub_080F401C(arg0_00);
          uVar6 = sub_080F401C(iVar2);
          sVar7 = (short)uVar5 + (short)uVar6;
          uVar5 = sub_080F4070(arg0_00);
          uVar6 = sub_080F4070(iVar2);
          sVar8 = (short)uVar5 + (short)uVar6;
          iVar3 = sub_080F4038(arg0_00);
          if (iVar3 < sVar7) {
            uVar5 = sub_080F4038(arg0_00);
            sVar7 = (short)uVar5;
          }
          iVar3 = sub_080F40A8(arg0_00);
          if (iVar3 < sVar8) {
            uVar5 = sub_080F40A8(arg0_00);
            sVar8 = (short)uVar5;
          }
          sub_080F4054(arg0_00,(int)sVar7);
          sub_080F408C(arg0_00,(int)sVar8);
          sub_080F4104(iVar2);
          sub_080C08F8(iVar2,0x8000);
          sub_08126834(0xffffffff);
          sub_080E760C();
          goto LAB_080f5b26;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x18);
    arg0[3] = 0;
    arg0[2] = 0x7e;
  }
LAB_080f5b26:
                    /* WARNING: Could not recover jumptable at 0x080f5b2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5B30 @ 0x080F5B30

void sub_080F5B30(int *arg0)

{
  int arg0_00;
  
  sub_080F51D4(arg0);
  if (arg0[3] == 1) {
    arg0[2] = 0x389;
  }
  arg0_00 = *arg0;
  sub_080C08F8(arg0_00,0x8000);
  sub_080F4054(arg0_00,0);
  if (arg0_00 - 4U < 0xc) {
    sub_080F4190(arg0_00);
  }
  return;
}


// sub_080F5B6C @ 0x080F5B6C

void sub_080F5B6C(undefined4 *arg0)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = arg0[6];
  uVar2 = sub_080C0818(*arg0);
  if ((uVar2 & 0x4000) == 0) {
    sub_080F4D2C(*arg0,iVar1 / 2);
  }
  return;
}


// sub_080F5B98 @ 0x080F5B98

void sub_080F5B98(int arg0)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080ED8F4();
  if ((((uVar1 & 0x100) == 0) && (iVar3 = *(int *)(arg0 + 4), 3 < iVar3)) &&
     (iVar2 = sub_080C0830(), iVar2 == 0)) {
    if (iVar3 - 4U < 0xc) {
      sub_080F4190(iVar3);
      sub_080C366C();
    }
    else {
      sub_080F4104(iVar3);
      sub_080C08F8(iVar3,0x8000);
      sub_08126834(0xffffffff);
      iVar3 = sub_080ED9F4();
      if (iVar3 == 0) {
        sub_080ED90C(0x200);
      }
      sub_080E760C();
    }
  }
  else {
    *(undefined4 *)(arg0 + 0xc) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080f5c02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5C04 @ 0x080F5C04

void sub_080F5C04(undefined4 *arg0)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar5 = *arg0;
  uVar1 = sub_080F3F14(uVar5);
  uVar2 = sub_080C2244();
  if ((uVar2 & 0xf) == 0) {
    sub_080C08E8(uVar5,0x40);
  }
  else {
    uVar3 = sub_080C07E0(uVar5);
    sub_080F40C4((int)(short)uVar3);
    iVar4 = sub_080C0A24(uVar5);
    if ((iVar4 == 0) && (uVar2 = sub_080C0818(uVar5), (uVar2 & 0x4000) == 0)) {
      iVar4 = sub_080BF5C0(uVar1 & 0xffff);
      sub_080F4D2C(uVar5,(uint)*(byte *)(iVar4 + 3) * 3);
      uVar5 = 1;
      goto LAB_080f5c68;
    }
  }
  uVar5 = 0;
LAB_080f5c68:
  arg0[3] = uVar5;
                    /* WARNING: Could not recover jumptable at 0x080f5c6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5C70 @ 0x080F5C70

void sub_080F5C70(int arg0)

{
  sub_080C0C14(*(undefined4 *)(arg0 + 4),-(*(int *)(arg0 + 0x18) >> 1));
  *(undefined4 *)(arg0 + 0xc) = 0;
  return;
}


// sub_080F5C8C @ 0x080F5C8C

void sub_080F5C8C(void)

{
  return;
}


// sub_080F5C90 @ 0x080F5C90

void sub_080F5C90(int arg0,undefined4 arg1)

{
  int local_c;
  
  sub_080BF468(arg1,0xc,&local_c);
  local_c = local_c + -0x80;
  if (-1 < local_c) {
    *(undefined4 *)(arg0 + 8) = 0xffffffff;
    *(undefined4 *)(arg0 + 0xc) = 1;
    *(int *)(arg0 + 0x10) = local_c;
    _call_via_r1(arg0,*(undefined4 *)(local_c * 4 + 0x876fa58));
  }
  return;
}


// sub_080F5CD0 @ 0x080F5CD0

void sub_080F5CD0(int arg0)

{
  uint uVar1;
  int iVar2;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = *(uint *)(arg0 + 4);
  uVar1 = sub_080C0818(arg0_00);
  if ((uVar1 & 0x4000) == 0) {
    iVar2 = sub_080C0830();
    if ((iVar2 == 0) && (iVar2 = sub_080C0A24(arg0_00), iVar2 == 0)) {
      iVar2 = sub_080F4038(arg0_00);
      if (iVar2 < 0) {
        iVar2 = iVar2 + 3;
      }
      sub_080C0B30(arg0_00,iVar2 >> 2);
      goto LAB_080f5d20;
    }
  }
  else {
    sub_080C0290(arg0_00 & 0xffff,0);
  }
  *(undefined4 *)(arg0 + 0xc) = 0;
LAB_080f5d20:
                    /* WARNING: Could not recover jumptable at 0x080f5d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5D28 @ 0x080F5D28

void sub_080F5D28(int arg0,uint arg1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = *(uint *)(arg0 + 4);
  iVar1 = sub_080F4038(arg0_00);
  uVar2 = sub_080C0818(arg0_00);
  if ((uVar2 & 0x4000) == 0) {
    iVar3 = sub_080C0830();
    if (iVar3 == 0) {
      if ((arg1 & 0xffff) == 4) {
        uVar2 = sub_080C2244();
        iVar3 = sub_080F401C(arg0_00);
        uVar4 = sub_080C0F8C(arg0_00);
        iVar5 = sub_080C1F94((int)(short)uVar4,2);
        iVar6 = ((uVar2 & 7) + 1) * 4;
      }
      else {
        uVar2 = sub_080C2244();
        iVar3 = sub_080F401C(arg0_00);
        uVar4 = sub_080C0F8C(arg0_00);
        iVar5 = sub_080C1F94((int)(short)uVar4,2);
        iVar6 = ((uVar2 & 7) + 1) * 6;
      }
      iVar5 = iVar6 + iVar3 + iVar5;
      if ((0x3e6 < iVar5) || (iVar1 * 2 < iVar5)) {
        iVar5 = iVar1 / 2;
        sub_080C08E8(arg0_00,arg1 & 0xffff);
      }
      sub_080F4054(arg0_00,iVar5);
    }
    else {
      *(undefined4 *)(arg0 + 0xc) = 0;
    }
  }
  else {
    sub_080C0290(arg0_00 & 0xffff,0);
    *(undefined4 *)(arg0 + 0xc) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080f5dfe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5E00 @ 0x080F5E00

void sub_080F5E00(void)

{
  undefined4 in_r0;
  
  sub_080F5D28(in_r0,4);
  return;
}


// sub_080F5E0C @ 0x080F5E0C

void sub_080F5E0C(void)

{
  return;
}


// sub_080F5E10 @ 0x080F5E10

void sub_080F5E10(int arg0)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint arg0_00;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = *(uint *)(arg0 + 4);
  iVar4 = 0;
  uVar1 = sub_080C0818(arg0_00);
  if ((uVar1 & 0x4000) == 0) {
    iVar2 = sub_080C0830();
    if (iVar2 == 0) {
      iVar2 = sub_080C0A24(arg0_00);
      if (iVar2 == 0) {
        uVar1 = sub_080C2244();
        uVar3 = sub_080F4038(arg0_00);
        iVar2 = sub_080C1F94(uVar3,8);
        iVar4 = sub_080F401C(arg0_00);
        iVar4 = (uVar1 & 7) + iVar2 + iVar4;
        iVar2 = sub_080F4038(arg0_00);
        if (iVar2 < iVar4) {
          iVar4 = sub_080F4038(arg0_00);
        }
        sub_080F4054(arg0_00,iVar4);
      }
      iVar2 = sub_080C0A50(arg0_00);
      if (iVar2 == 0) {
        uVar1 = sub_080C2244();
        uVar3 = sub_080C0F8C(arg0_00);
        iVar2 = sub_080C1F94((int)(short)uVar3,4);
        iVar4 = sub_080F4070(arg0_00);
        iVar4 = (uVar1 & 0xe) + iVar2 + iVar4;
        iVar2 = sub_080F40A8(arg0_00);
        if (iVar2 < iVar4) {
          iVar4 = sub_080F40A8(arg0_00);
        }
        sub_080F408C(arg0_00,iVar4);
      }
    }
    if (iVar4 != 0) goto LAB_080f5ed0;
  }
  else {
    sub_080C0290(arg0_00 & 0xffff,0);
  }
  *(undefined4 *)(arg0 + 0xc) = 0;
LAB_080f5ed0:
                    /* WARNING: Could not recover jumptable at 0x080f5ed4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5ED8 @ 0x080F5ED8

void sub_080F5ED8(int arg0)

{
  uint uVar1;
  int iVar2;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  char cVar3;
  
  arg0_00 = *(uint *)(arg0 + 4);
  cVar3 = '\0';
  uVar1 = sub_080C0818(arg0_00);
  if ((uVar1 & 0x4000) == 0) {
    iVar2 = sub_080C0830();
    if (iVar2 == 0) {
      iVar2 = sub_080C0A24(arg0_00);
      cVar3 = iVar2 == 0;
      if ((bool)cVar3) {
        sub_080C0A7C(arg0_00);
      }
      iVar2 = sub_080C0A50(arg0_00);
      if (iVar2 == 0) {
        sub_080C0AA8(arg0_00);
        cVar3 = cVar3 + '\x01';
      }
      uVar1 = sub_080C0818(arg0_00);
      if ((uVar1 & 0x73fe) != 0) {
        sub_080C08BC(arg0_00,0x8c01);
        cVar3 = cVar3 + '\x01';
      }
    }
    if (cVar3 != '\0') goto LAB_080f5f4a;
  }
  else {
    sub_080C0290(arg0_00 & 0xffff,0);
  }
  *(undefined4 *)(arg0 + 0xc) = 0;
LAB_080f5f4a:
                    /* WARNING: Could not recover jumptable at 0x080f5f4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5F58 @ 0x080F5F58

void sub_080F5F58(int arg0)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = *(undefined4 *)(arg0 + 4);
  uVar1 = sub_080C0818(uVar3);
  if ((uVar1 & 0x8000) == 0) {
    *(undefined4 *)(arg0 + 0xc) = 0;
  }
  else {
    uVar1 = sub_080C2244();
    if ((uVar1 & 0x3f) == 0) {
      sub_080C08E8(uVar3,0x8000);
      *(undefined4 *)(arg0 + 8) = 0x95;
    }
    else {
      sub_080C08BC(uVar3,1);
      iVar2 = sub_080F4038(uVar3);
      if (iVar2 < 0) {
        iVar2 = iVar2 + 7;
      }
      iVar2 = iVar2 >> 3;
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      sub_080F4054(uVar3,iVar2);
      uVar3 = sub_080C07E0(uVar3);
      sub_080F40C4((int)(short)uVar3);
      *(undefined4 *)(arg0 + 8) = 0x124;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080f5fce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F5FD0 @ 0x080F5FD0

void sub_080F5FD0(int arg0)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(arg0 + 4);
  iVar1 = sub_080C0830();
  if (iVar1 == 0) {
    *(undefined4 *)(arg0 + 0xc) = 0;
  }
  else {
    sub_080C08BC(uVar2,1);
    sub_080C0A7C(uVar2);
    uVar2 = sub_080C07E0(uVar2);
    sub_080F40C4((int)(short)uVar2);
    *(dword *)(arg0 + 8) = 0x125;
  }
  return;
}


// sub_080F6010 @ 0x080F6010

void sub_080F6010(void)

{
  return;
}


// sub_080F6014 @ 0x080F6014

void sub_080F6014(int arg0)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 arg1;
  bool bVar4;
  
  uVar3 = *(undefined4 *)(arg0 + 4);
  bVar4 = false;
  bVar1 = false;
  iVar2 = sub_080C0830();
  if (iVar2 == 0) {
    arg1 = *(undefined4 *)((*(int *)(arg0 + 0x10) + -8) * 4 + 0x876fb2c);
    iVar2 = sub_080C0F64();
    if (iVar2 < 0x28) {
      sub_080C0EC0(uVar3,arg1,1);
      sub_080BFD94(uVar3);
    }
    bVar1 = iVar2 < 0x28;
    iVar2 = sub_080C0A24(uVar3);
    if (iVar2 == 0) {
      sub_080C0A7C(uVar3);
      uVar3 = sub_080C07E0(uVar3);
      sub_080F40C4((int)(short)uVar3);
      bVar4 = true;
    }
  }
  if (!bVar1) {
    if (bVar4) {
      *(dword *)(arg0 + 8) = 0x11f;
    }
    else {
      *(undefined4 *)(arg0 + 0xc) = 0;
    }
  }
  sub_080C65C8();
  return;
}


// sub_080F60A4 @ 0x080F60A4

void sub_080F60A4(int arg0,int arg1)

{
  uint uVar1;
  int iVar2;
  undefined4 arg0_00;
  int iVar3;
  undefined4 arg1_00;
  undefined4 arg0_01;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_01 = *(undefined4 *)(arg0 + 4);
  *(undefined4 *)(arg0 + 0xc) = 0;
  uVar1 = sub_080C0818(arg0_01);
  if ((uVar1 & 0x4000) == 0) {
    iVar2 = sub_080C0830();
    if (iVar2 == 0) {
      iVar2 = sub_080C06BC(arg0_01);
      if (iVar2 == arg1) {
        iVar2 = sub_080C0A24(arg0_01);
        if (iVar2 == 0) {
          sub_080C0A7C(arg0_01);
        }
        uVar1 = sub_080C0818(arg0_01);
        if ((uVar1 & 0x33fe) != 0) {
          sub_080C08BC(arg0_01,0xcc01);
        }
        *(undefined4 *)(arg0 + 0xc) = 1;
      }
      else {
        iVar2 = sub_080C06BC(arg0_01);
        if (iVar2 == 1) {
          arg0_00 = sub_080F401C(arg0_01);
          arg1_00 = 8;
        }
        else {
          arg0_00 = sub_080F401C(arg0_01);
          arg1_00 = 2;
        }
        iVar2 = sub_080C1F94(arg0_00,arg1_00);
        *(int *)(arg0 + 0x18) = iVar2;
        iVar3 = sub_080F401C(arg0_01);
        if (iVar3 - iVar2 < 1) {
          *(undefined4 *)(arg0 + 0x18) = 0;
        }
        else {
          sub_080F4054(arg0_01,iVar3 - iVar2);
        }
        *(undefined4 *)(arg0 + 0xc) = 2;
      }
    }
    else {
      *(undefined4 *)(arg0 + 0xc) = 0;
    }
  }
  else {
    *(undefined4 *)(arg0 + 0xc) = 3;
  }
                    /* WARNING: Could not recover jumptable at 0x080f615e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F6160 @ 0x080F6160

void sub_080F6160(void)

{
  undefined4 in_r0;
  
  sub_080F60A4(in_r0,0);
  return;
}


// sub_080F616C @ 0x080F616C

void sub_080F616C(void)

{
  undefined4 in_r0;
  
  sub_080F60A4(in_r0,2);
  return;
}


// sub_080F6178 @ 0x080F6178

void sub_080F6178(int arg0,uint arg1,undefined4 arg2)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080F3F44();
  if ((uVar1 & arg1 & 0xffff) == 0) {
    sub_080F3F74(arg1 & 0xffff);
    *(undefined4 *)(arg0 + 8) = arg2;
  }
  else {
    *(undefined4 *)(arg0 + 8) = 0x96;
  }
                    /* WARNING: Could not recover jumptable at 0x080f619e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F61A0 @ 0x080F61A0

void sub_080F61A0(void)

{
  return;
}


// sub_080F61A4 @ 0x080F61A4

void sub_080F61A4(void)

{
  undefined4 in_r0;
  
  sub_080F6178(in_r0,2,0x130);
  return;
}


// sub_080F61B4 @ 0x080F61B4

void sub_080F61B4(void)

{
  return;
}


// sub_080F61B8 @ 0x080F61B8

void sub_080F61B8(void)

{
  undefined4 in_r0;
  
  sub_080F6178(in_r0,8,0x132);
  return;
}


// sub_080F61C8 @ 0x080F61C8

void sub_080F61C8(void)

{
  undefined4 in_r0;
  
  sub_080F6178(in_r0,0x10,0x133);
  return;
}


// sub_080F61DC @ 0x080F61DC

void sub_080F61DC(void)

{
  return;
}


// sub_080F61E0 @ 0x080F61E0

void sub_080F61E0(void)

{
  undefined4 in_r0;
  
  sub_080F6178(in_r0,0x40,0x135);
  return;
}


// sub_080F61F4 @ 0x080F61F4

void sub_080F61F4(void)

{
  return;
}


// sub_080F61F8 @ 0x080F61F8

void sub_080F61F8(void)

{
  return;
}


// sub_080F61FC @ 0x080F61FC

void sub_080F61FC(undefined4 *arg0)

{
  int iVar1;
  uint uVar2;
  undefined4 arg0_00;
  
  iVar1 = sub_080EDAD0();
  if ((iVar1 == 0) && (uVar2 = sub_080ED8F4(), (uVar2 & 0x100) == 0)) {
    arg0_00 = sub_080EFFF8(*arg0,(int)DAT_0203d166);
    sub_080F4104(arg0_00);
    sub_080C08F8(arg0_00,0x8000);
    sub_08126834(0xffffffff);
    iVar1 = sub_080ED9F4();
    if (iVar1 == 0) {
      sub_080ED90C(0x200);
    }
    sub_080E760C();
    arg0[1] = arg0_00;
    arg0[2] = 0xffffffff;
  }
  else {
    arg0[3] = 0;
  }
  return;
}


// sub_080F6270 @ 0x080F6270

void sub_080F6270(int arg0)

{
  *(undefined4 *)(arg0 + 0xc) = 0;
  return;
}


// sub_080F6278 @ 0x080F6278

void sub_080F6278(void)

{
  sub_080C2244();
  return;
}


// sub_080F6294 @ 0x080F6294

void sub_080F6294(int arg0)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = sub_080EDAD0();
  if (((iVar1 == 0) && (uVar2 = sub_080ED8F4(), (uVar2 & 0x100) == 0)) &&
     (uVar2 = sub_080C2244(), (uVar2 & 3) == 0)) {
    iVar1 = 0x10;
    do {
      iVar3 = sub_080C0A00(iVar1);
      if (iVar3 != 0) {
        DAT_0203cb90 = 0xfb;
        DAT_0203cb94 = 0xfb;
        sub_080F0200(iVar1 + -0x10,0xfb);
        uVar4 = sub_080F4038(iVar1);
        sub_080F4054(iVar1,uVar4);
        uVar4 = sub_080F40A8(iVar1);
        sub_080F408C(iVar1,uVar4);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x18);
    iVar1 = sub_080ED954();
    if (iVar1 != 0) {
      DAT_0203cb98 = DAT_0203cb9a + DAT_0203cb98;
      sub_080ED938(0);
    }
    iVar1 = sub_080BF648(DAT_0203cb90 & 0xffff);
    sub_080EF8F8((uint)*(byte *)(iVar1 + 0x21));
    sub_080AD1FC(DAT_0203c204);
    sub_080E8C58(DAT_0203cb90 & 0xffff,0xffff,1);
    sub_080E760C();
    *(undefined4 *)(arg0 + 8) = 0x324;
  }
  else {
    *(undefined4 *)(arg0 + 8) = 0x7e;
    *(undefined4 *)(arg0 + 0xc) = 0;
  }
  return;
}


// sub_080F6378 @ 0x080F6378

void sub_080F6378(void)

{
  undefined4 in_r0;
  
  sub_080F5D28(in_r0,0x1000);
  return;
}


