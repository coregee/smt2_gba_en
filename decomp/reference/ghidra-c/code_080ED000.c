/* Ghidra decompilation of asm/code_080ED000.s (reference only; not compiled). */

// sub_080ED000 @ 0x080ED000

void sub_080ED000(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203d3a8 != 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080ED024 @ 0x080ED024

void sub_080ED024(void)

{
  int iVar1;
  undefined4 uVar2;
  uint arg0;
  dword arg1;
  
  sub_080EA210();
  switch((int)((*(ushort *)(DAT_03006434 + 0x126) - 1) * 0x10000) >> 0x10) {
  case 0:
    iVar1 = sub_080EF99C();
    uVar2 = *(undefined4 *)((int)&DAT_0203cb90 + ((iVar1 << 0x10) >> 0xe));
    arg1 = 0x812466c;
    break;
  case 1:
    iVar1 = sub_080EF99C();
    uVar2 = *(undefined4 *)((int)&DAT_0203cb90 + ((iVar1 << 0x10) >> 0xe));
    arg1 = 0x812463a;
    break;
  case 2:
    uVar2 = Menu_ExpandListTemplate(0x812464e,0);
    goto LAB_080ed180;
  case 3:
    iVar1 = sub_080EF99C();
    arg0 = (uint)*(ushort *)((int)&DAT_0203cb90 + ((iVar1 << 0x10) >> 0xe));
    uVar2 = MessageBox_ComposeSpeciesText(arg0,arg0,1,1);
    goto LAB_080ed180;
  case 4:
    iVar1 = sub_080EF99C();
    uVar2 = *(undefined4 *)((int)&DAT_0203cb90 + ((iVar1 << 0x10) >> 0xe));
    arg1 = 0x81245f6;
    break;
  case 5:
    iVar1 = sub_080EF99C();
    uVar2 = *(undefined4 *)((int)&DAT_0203cb90 + ((iVar1 << 0x10) >> 0xe));
    arg1 = 0x81245d2;
    break;
  case 6:
    iVar1 = sub_080EF99C();
    uVar2 = *(undefined4 *)((int)&DAT_0203cb90 + ((iVar1 << 0x10) >> 0xe));
    arg1 = 0x81245f6;
    break;
  case 7:
    iVar1 = sub_080EF99C();
    uVar2 = *(undefined4 *)((int)&DAT_0203cb90 + ((iVar1 << 0x10) >> 0xe));
    arg1 = 0x8124608;
    break;
  case 8:
  case 9:
    iVar1 = sub_080EF99C();
    uVar2 = *(undefined4 *)((int)&DAT_0203cb90 + ((iVar1 << 0x10) >> 0xe));
    arg1 = 0x812461a;
    break;
  case 10:
    iVar1 = sub_080EF99C();
    uVar2 = MessageBox_ComposeNameText
                      (*(undefined4 *)((int)&DAT_0203cb90 + ((iVar1 << 0x10) >> 0xe)),0x812461a);
    BattleMenu_SetMode(3,uVar2);
  default:
    goto switchD_080ed04e_default;
  }
  uVar2 = MessageBox_ComposeNameText(uVar2,arg1);
LAB_080ed180:
  BattleMenu_SetMode(3,uVar2);
switchD_080ed04e_default:
  DAT_0203d3a8 = 0;
  return;
}


// sub_080ED1C8 @ 0x080ED1C8

void sub_080ED1C8(int arg0,int arg1)

{
  uint uVar1;
  int iVar2;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar1 = sub_080EA934();
  if ((uVar1 & 0xff) != 1) {
    return;
  }
  if (arg1 == 0) {
    switch((int)((*(ushort *)(DAT_03006434 + 0x126) - 4) * 0x10000) >> 0x10) {
    case 1:
      iVar2 = sub_080ED9F4();
      if (iVar2 != 0) break;
    case 0:
    case 2:
    case 3:
    case 5:
    case 6:
    case 7:
      sub_080EA528();
      if (DAT_0203cb74 != 0) {
        sub_080AB91C(DAT_0203cb74,0);
        DAT_0203cb74 = 0;
      }
    }
  }
  *(undefined2 *)(arg0 + 0x1c) = 1;
  return;
}


// sub_080ED260 @ 0x080ED260

void sub_080ED260(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint arg0;
  
  bVar1 = false;
  arg0 = 0;
  do {
    if (*(char *)(arg0 + 0x30050e0) != -1) {
      iVar2 = sub_080C0148(arg0);
      uVar3 = sub_080C0818((uint)*(byte *)(iVar2 + 0xc));
      if ((uVar3 & 0x4000) != 0) {
        sub_080C0290((int)*(char *)(arg0 + 0x30050e0) & 0xffff,0);
        bVar1 = true;
      }
    }
    arg0 = arg0 + 1 & 0xffff;
  } while (arg0 < 6);
  if (bVar1) {
    sub_080C366C();
    Party_BuildMemberNameTiles();
    sub_080C6FD8();
  }
  return;
}


// sub_080ED2D0 @ 0x080ED2D0

void sub_080ED2D0(int arg0)

{
  int iVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  iVar1 = sub_080ED954();
  if (((iVar1 != 0) && (DAT_0203d38c == 0)) &&
     ((iVar1 = sub_080EDA24(0), iVar1 == 0 || (iVar1 = sub_080EDA24(1), iVar1 == 0)))) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080ED314 @ 0x080ED314

void sub_080ED314(void)

{
  DAT_0203d38c = DAT_0203d38c + 2;
  return;
}


// sub_080ED32C @ 0x080ED32C

uint sub_080ED32C(uint arg0)

{
  return (uint)*(ushort *)((arg0 & 0xffff) * 2 + 0x876e6d4);
}


// sub_080ED33C @ 0x080ED33C

void sub_080ED33C(void)

{
  uint uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = 1;
  while ((iVar2 < 5 && (uVar1 = sub_080C2244(), (uVar1 & 0xf) == 0))) {
    iVar2 = iVar2 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080ed35a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(iVar2);
  return;
}


// sub_080ED35C @ 0x080ED35C

void sub_080ED35C(uint *arg0,int *arg1,uint arg2)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = (arg2 & 0xff) * 4;
  pbVar2 = (byte *)(iVar1 + 0x876e978);
  *arg0 = (uint)(byte)(&LAB_0876e978_1)[iVar1];
  iVar1 = sub_080ED600(*pbVar2 & 0xf);
  *arg1 = iVar1 + 1;
  DAT_0203cb84 = (uint)*pbVar2;
  return;
}


// sub_080ED398 @ 0x080ED398

void sub_080ED398(undefined4 arg0,undefined4 arg1,uint arg2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  iVar1 = sub_080C5D48(arg2 & 0xffff);
  cVar3 = *(char *)(iVar1 + 2);
  if ((*(byte *)(iVar1 + 1) != 0) && (iVar2 = sub_080C2340((uint)*(byte *)(iVar1 + 1)), iVar2 == 0))
  {
    cVar3 = *(char *)(iVar1 + 3);
  }
  if (cVar3 != -1) {
    sub_080ED35C(arg0,arg1,(int)cVar3);
  }
  return;
}


// sub_080ED3D0 @ 0x080ED3D0

uint sub_080ED3D0(int arg0,uint arg1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(arg0 * 8 + (int)arg1 / 2 + 0x872f234);
  if ((arg1 & 1) == 0) {
    bVar1 = bVar1 >> 4;
  }
  return bVar1 & 0xf;
}


// sub_080ED3FC @ 0x080ED3FC

void sub_080ED3FC(int arg0,int arg1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar3 = *(int *)(&DAT_0876f664 + arg0 * 8);
  iVar1 = *(int *)(arg0 * 8 + 0x876f660);
  iVar5 = 0;
  uVar2 = sub_080C2244();
  for (pbVar4 = (byte *)(iVar1 + arg1 * iVar3); (*pbVar4 == 0 || (*pbVar4 < uVar2));
      pbVar4 = pbVar4 + 1) {
    iVar5 = iVar5 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080ed43a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(iVar5);
  return;
}


// sub_080ED43C @ 0x080ED43C

void sub_080ED43C(uint arg0)

{
  sub_080BF648(arg0 & 0xffff);
  return;
}


// sub_080ED450 @ 0x080ED450

void sub_080ED450(uint arg0)

{
  sub_080BF648(arg0 & 0xffff);
  return;
}


// sub_080ED464 @ 0x080ED464

int sub_080ED464(uint arg0)

{
  char *pcVar1;
  int iVar2;
  
  if ((int)arg0 < 0) {
    iVar2 = -1;
  }
  else {
    pcVar1 = (char *)sub_080BF648(arg0 & 0xffff);
    iVar2 = (int)*pcVar1;
  }
  return iVar2;
}


// sub_080ED484 @ 0x080ED484

void sub_080ED484(void)

{
  undefined4 in_r0;
  undefined4 arg0;
  
  arg0 = sub_080ED464(in_r0);
  Race_GetParentId(arg0);
  return;
}


// sub_080ED494 @ 0x080ED494

int sub_080ED494(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  return (int)*(char *)(iVar1 + 0xe);
}


// sub_080ED4A8 @ 0x080ED4A8

int sub_080ED4A8(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  return (int)*(char *)(iVar1 + 0xf);
}


// sub_080ED4BC @ 0x080ED4BC

void sub_080ED4BC(uint arg0)

{
  sub_080BF648(arg0 & 0xffff);
  return;
}


// sub_080ED4D0 @ 0x080ED4D0

void sub_080ED4D0(uint arg0)

{
  sub_080BF648(arg0 & 0xffff);
  return;
}


// sub_080ED4E4 @ 0x080ED4E4

void sub_080ED4E4(uint arg0)

{
  sub_080BF648(arg0 & 0xffff);
  return;
}


// sub_080ED4F8 @ 0x080ED4F8

void sub_080ED4F8(uint arg0)

{
  sub_080BF648(arg0 & 0xffff);
  return;
}


// sub_080ED50C @ 0x080ED50C

void sub_080ED50C(uint arg0)

{
  sub_080BF648(arg0 & 0xffff);
  return;
}


// sub_080ED520 @ 0x080ED520

void sub_080ED520(uint arg0)

{
  sub_080BF648(arg0 & 0xffff);
  return;
}


// sub_080ED534 @ 0x080ED534

void sub_080ED534(void)

{
  undefined4 in_r0;
  
  sub_080ED520(in_r0);
  return;
}


// sub_080ED540 @ 0x080ED540

void sub_080ED540(uint arg0)

{
  sub_080BF648(arg0 & 0xffff);
  return;
}


// sub_080ED550 @ 0x080ED550

uint sub_080ED550(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  return (uint)*(byte *)(iVar1 + 0xc);
}


// sub_080ED560 @ 0x080ED560

uint sub_080ED560(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  return (uint)*(byte *)(iVar1 + 1);
}


// sub_080ED570 @ 0x080ED570

void sub_080ED570(uint arg0)

{
  sub_080BF648(arg0 & 0xffff);
  return;
}


// sub_080ED584 @ 0x080ED584

uint sub_080ED584(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  return (uint)*(byte *)(iVar1 + 0x1d);
}


// sub_080ED594 @ 0x080ED594

void sub_080ED594(void)

{
  undefined4 in_r0;
  
  sub_080ED560(in_r0);
  return;
}


// sub_080ED5A8 @ 0x080ED5A8

void sub_080ED5A8(void)

{
  undefined4 in_r0;
  
  sub_080ED560(in_r0);
  return;
}


// sub_080ED5B4 @ 0x080ED5B4

uint sub_080ED5B4(int arg0,int arg1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint unaff_r4;
  uint uVar4;
  
  pbVar3 = (byte *)(arg0 * 0x18 + 0x876eba8);
  bVar1 = *(byte *)(arg1 * 2 + 0x203a450);
  uVar2 = 0;
  if (*pbVar3 < bVar1) {
    do {
      uVar2 = uVar2 + 1 & 0xff;
      uVar4 = unaff_r4;
      if (7 < uVar2) break;
      uVar4 = uVar2;
    } while (pbVar3[uVar2] < bVar1);
  }
  else {
    uVar4 = 0;
  }
  return (uint)*(ushort *)(&DAT_0876ebb0 + uVar4 * 2 + arg0 * 0x18);
}


// sub_080ED600 @ 0x080ED600

undefined4 sub_080ED600(undefined4 arg0)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  sub_080ED3FC(0,arg0);
  return uVar1;
}


// sub_080ED610 @ 0x080ED610

undefined4 sub_080ED610(uint arg0)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar4 = sub_080BF648(arg0 & 0xffff);
  uVar1 = (ushort)(*(byte *)(iVar4 + 0xd) >> 4);
  if (uVar1 < 8) {
    uVar5 = sub_080C2244();
    iVar4 = (uVar5 & 3) - 1;
    sVar3 = (short)iVar4;
    iVar4 = iVar4 * 0x10000;
    if (-1 < iVar4) {
      sVar3 = (short)(iVar4 >> 0x11);
    }
    uVar2 = (ushort)((int)sVar3 + (int)(short)uVar1);
    iVar4 = ((int)sVar3 + (int)(short)uVar1) * 0x10000 >> 0x10;
    if (iVar4 < 0) {
      uVar2 = 0;
      goto LAB_080ed664;
    }
    if (iVar4 < 8) goto LAB_080ed664;
  }
  else {
    uVar2 = uVar1 & 7;
LAB_080ed664:
    iVar4 = (int)(short)uVar2;
    if (iVar4 == 0) {
      iVar4 = 1;
      goto LAB_080ed676;
    }
    if (iVar4 < 9) goto LAB_080ed676;
  }
  iVar4 = 7;
LAB_080ed676:
                    /* WARNING: Could not recover jumptable at 0x080ed67a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar6 = (*UNRECOVERED_JUMPTABLE)(iVar4);
  return uVar6;
}


// sub_080ED67C @ 0x080ED67C

uint sub_080ED67C(void)

{
  undefined4 in_r0;
  int iVar1;
  
  iVar1 = sub_080ED464(in_r0);
  return (uint)*(byte *)(iVar1 + 0x876f688);
}


// sub_080ED694 @ 0x080ED694

uint sub_080ED694(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF5C0(arg0 & 0xffff);
  return (uint)*(byte *)(iVar1 + 2);
}


// sub_080ED6A4 @ 0x080ED6A4

uint sub_080ED6A4(uint arg0)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)sub_080BF5C0(arg0 & 0xffff);
  return *pbVar1 & 0xf;
}


// sub_080ED6B8 @ 0x080ED6B8

uint sub_080ED6B8(uint arg0)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)sub_080BF5C0(arg0 & 0xffff);
  return *pbVar1 & 0xf0;
}


// sub_080ED6CC @ 0x080ED6CC

uint sub_080ED6CC(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF5C0(arg0 & 0xffff);
  return (uint)*(byte *)(iVar1 + 3);
}


// sub_080ED6DC @ 0x080ED6DC

void sub_080ED6DC(undefined4 arg0,int arg1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 < 0x68) {
    iVar1 = sub_080F4070(arg0);
    iVar2 = sub_080ED6CC(arg1);
    sVar4 = (short)(iVar1 - iVar2);
    if ((iVar1 - iVar2) * 0x10000 < 0) {
      sVar4 = 0;
    }
    sub_080F408C(arg0,(int)sVar4);
  }
  else {
    iVar1 = sub_080F401C(arg0);
    iVar2 = sub_080F4038(arg0);
    iVar3 = sub_080ED6CC(arg1);
    iVar2 = __udivsi3(iVar2 * iVar3,100);
    sVar4 = (short)(iVar1 - iVar2);
    if ((iVar1 - iVar2) * 0x10000 < 0) {
      sVar4 = 0;
    }
    sub_080F4054(arg0,(int)sVar4);
  }
                    /* WARNING: Could not recover jumptable at 0x080ed742. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080ED744 @ 0x080ED744

undefined4 sub_080ED744(undefined4 arg0,int arg1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 < 0x68) {
    iVar1 = sub_080F4070(arg0);
    iVar2 = sub_080ED6CC(arg1);
    if ((iVar1 - iVar2) * 0x10000 < 0) {
LAB_080ed78c:
      uVar3 = 0;
      goto LAB_080ed78e;
    }
  }
  else {
    iVar1 = sub_080F401C(arg0);
    iVar2 = sub_080F4038(arg0);
    iVar4 = sub_080ED6CC(arg1);
    iVar2 = __udivsi3(iVar2 * iVar4,100);
    if ((iVar1 - iVar2) * 0x10000 < 1) goto LAB_080ed78c;
  }
  uVar3 = 1;
LAB_080ed78e:
                    /* WARNING: Could not recover jumptable at 0x080ed792. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar3);
  return uVar3;
}


// sub_080ED794 @ 0x080ED794

uint sub_080ED794(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF5C0(arg0 & 0xffff);
  return (uint)*(ushort *)(iVar1 + 4);
}


// sub_080ED7A4 @ 0x080ED7A4

uint sub_080ED7A4(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF5C0(arg0 & 0xffff);
  return (uint)*(byte *)(iVar1 + 1);
}


// sub_080ED7B4 @ 0x080ED7B4

void sub_080ED7B4(void)

{
  return;
}


// sub_080ED7B8 @ 0x080ED7B8

void sub_080ED7B8(void)

{
  return;
}


// sub_080ED7BC @ 0x080ED7BC

void sub_080ED7BC(void)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uStack_18;
  
  DAT_03006434 = &DAT_0203d16c;
  DAT_03006438 = &DAT_0203d328;
  uStack_18 = 0;
  CpuSet(&uStack_18,&DAT_0203d16c,0x5000068);
  iVar2 = 0;
  do {
    puVar1 = (undefined2 *)(DAT_03006434 + iVar2 * 2 + 0x128);
    *(undefined2 *)(DAT_03006434 + iVar2 * 2 + 300) = 8;
    *puVar1 = 8;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  iVar2 = 0;
  do {
    *(undefined2 *)(DAT_03006434 + iVar2 * 2 + 0x56) = 0xffff;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return;
}


// sub_080ED844 @ 0x080ED844

void sub_080ED844(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = DAT_03006434 + 0x128;
    *(undefined2 *)(DAT_03006434 + 300 + iVar2 * 2) = 8;
    *(undefined2 *)(iVar1 + iVar2 * 2) = 8;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  return;
}


// sub_080ED874 @ 0x080ED874

void sub_080ED874(void)

{
  return;
}


// sub_080ED878 @ 0x080ED878

void sub_080ED878(void)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = DAT_03006434;
  DAT_03006434[2] = 0;
  *puVar1 = *puVar1 & 0xff7f;
  iVar2 = 0;
  do {
    iVar4 = iVar2 + 1;
    iVar2 = iVar2 * 0x1c;
    iVar3 = 0xd;
    do {
      *(undefined2 *)((int)DAT_03006434 + iVar2 + 0x78) = 0;
      iVar2 = iVar2 + 2;
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
    iVar2 = iVar4;
  } while (iVar4 < 6);
  return;
}


// sub_080ED8C0 @ 0x080ED8C0

undefined4 sub_080ED8C0(int arg0)

{
  undefined4 uVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg0 < 0x10) {
    uVar2 = 0;
    do {
      if (arg0 == *(char *)(uVar2 + 0x30050e0)) goto LAB_080ed8f0;
      uVar2 = uVar2 + 1;
    } while (uVar2 < 6);
    uVar2 = 0;
  }
  else {
    uVar2 = arg0 - 10;
  }
LAB_080ed8f0:
                    /* WARNING: Could not recover jumptable at 0x080ed8f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar1;
}


// sub_080ED8F4 @ 0x080ED8F4

uint sub_080ED8F4(void)

{
  return (uint)*DAT_03006434;
}


// sub_080ED900 @ 0x080ED900

void sub_080ED900(undefined4 arg0)

{
  *DAT_03006434 = (undefined2)arg0;
  return;
}


// sub_080ED90C @ 0x080ED90C

void sub_080ED90C(undefined4 arg0)

{
  *DAT_03006434 = (ushort)arg0 | *DAT_03006434;
  return;
}


// sub_080ED920 @ 0x080ED920

void sub_080ED920(undefined4 arg0)

{
  *(undefined2 *)(DAT_03006434 + 2) = (undefined2)arg0;
  return;
}


// sub_080ED92C @ 0x080ED92C

uint sub_080ED92C(void)

{
  return (uint)*(ushort *)(DAT_03006434 + 2);
}


// sub_080ED938 @ 0x080ED938

void sub_080ED938(undefined4 arg0)

{
  *(undefined2 *)(DAT_03006434 + 6) = (undefined2)arg0;
  return;
}


// sub_080ED944 @ 0x080ED944

void sub_080ED944(void)

{
  return;
}


// sub_080ED954 @ 0x080ED954

uint sub_080ED954(void)

{
  return (uint)(*(short *)(DAT_03006434 + 6) != 0);
}


// sub_080ED974 @ 0x080ED974

undefined4 sub_080ED974(int arg0)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080ED954();
  if ((iVar1 == 0) || (arg0 < 0x14)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080ed98e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080ED990 @ 0x080ED990

undefined4 sub_080ED990(int arg0)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080ED954();
  if ((iVar1 == 0) || (arg0 != 1)) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = 0x14;
  }
                    /* WARNING: Could not recover jumptable at 0x080ed9aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080ED9AC @ 0x080ED9AC

void sub_080ED9AC(int arg0,int arg1)

{
  int iVar1;
  
  if (arg0 < arg0 + arg1) {
    iVar1 = (arg0 + arg1) - arg0;
    do {
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// sub_080ED9F4 @ 0x080ED9F4

undefined4 sub_080ED9F4(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  sub_080ED9AC(0,8);
  return uVar1;
}


// sub_080EDA04 @ 0x080EDA04

void sub_080EDA04(void)

{
  int arg0;
  
  arg0 = 0x10;
  do {
    sub_080C08F8(arg0,0x8000);
    sub_080F4104(arg0);
    arg0 = arg0 + 1;
  } while (arg0 < 0x18);
  return;
}


// sub_080EDA24 @ 0x080EDA24

undefined4 sub_080EDA24(int arg0)

{
  int iVar1;
  undefined4 arg1;
  undefined4 arg0_00;
  
  arg0_00 = 0;
  iVar1 = sub_080ED954();
  if (iVar1 == 0) {
    arg1 = 8;
  }
  else {
    arg1 = 4;
    if (arg0 == 1) {
      arg0_00 = 4;
    }
  }
  sub_080ED9AC(arg0_00,arg1);
  return arg0_00;
}


// sub_080EDA4C @ 0x080EDA4C

void sub_080EDA4C(int arg0,undefined4 arg1)

{
  *(undefined4 *)(DAT_03006434 + 0x160 + arg0 * 4) = arg1;
  return;
}


// sub_080EDA64 @ 0x080EDA64

undefined4 sub_080EDA64(int arg0)

{
  return *(undefined4 *)(DAT_03006434 + 0x160 + arg0 * 4);
}


// sub_080EDA7C @ 0x080EDA7C

void sub_080EDA7C(undefined4 arg0)

{
  *(undefined2 *)(DAT_03006434 + 0x158) = (undefined2)arg0;
  return;
}


// sub_080EDA90 @ 0x080EDA90

uint sub_080EDA90(void)

{
  return (uint)*(ushort *)(DAT_03006434 + 0x158);
}


// sub_080EDAA4 @ 0x080EDAA4

void sub_080EDAA4(undefined4 arg0)

{
  *(undefined2 *)(DAT_03006434 + 0x15a) = (undefined2)arg0;
  return;
}


// sub_080EDAB8 @ 0x080EDAB8

void sub_080EDAB8(undefined4 arg0)

{
  *(int *)(DAT_03006434 + 0x15c) = (int)(short)arg0;
  return;
}


// sub_080EDAD0 @ 0x080EDAD0

uint sub_080EDAD0(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080C07E0(0x10);
  return (uint)(0xff < (short)uVar1);
}


// sub_080EDAEC @ 0x080EDAEC

uint sub_080EDAEC(int arg0)

{
  return (uint)(arg0 - 0x130U < 5);
}


// sub_080EDB04 @ 0x080EDB04

uint sub_080EDB04(void)

{
  uint uVar1;
  byte abStack_14 [20];
  
  memcpy(abStack_14,0x876f6b4,0x10);
  uVar1 = sub_080C1D9C();
  return (uint)abStack_14[uVar1 >> 4 & 0xf];
}


// sub_080EDB2C @ 0x080EDB2C

void sub_080EDB2C(uint arg0,uint arg1)

{
  uint uVar1;
  int in_r2;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((arg0 & ~(1 << (arg1 & 0xff))) != 0) {
    for (uVar1 = 1; uVar1 < 0x20; uVar1 = uVar1 + 1) {
      arg1 = arg1 + in_r2;
      if ((int)arg1 < 0x20) {
        if ((int)arg1 < 0) {
          arg1 = 0x1f;
        }
      }
      else {
        arg1 = 0;
      }
      if ((1 << (arg1 & 0xff) & arg0) != 0) break;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080edb68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(arg1);
  return;
}


// sub_080EDB6C @ 0x080EDB6C

void sub_080EDB6C(uint arg0,uint arg1,int arg2)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar6 = arg0 & 0xffff;
  uVar5 = uVar6 + 1;
  if (uVar5 < (arg1 & 0xffff)) {
    do {
      puVar2 = (undefined4 *)(uVar5 * 4 + arg2);
      uVar3 = *puVar2;
      sVar1 = *(short *)((int)puVar2 + 2);
      iVar4 = uVar5 - 1;
      uVar5 = uVar5 + 1;
      if ((int)uVar6 <= iVar4) {
        puVar2 = (undefined4 *)(iVar4 * 4 + arg2);
        do {
          if (*(short *)((int)puVar2 + 2) <= sVar1) break;
          puVar2[1] = *puVar2;
          puVar2 = puVar2 + -1;
          iVar4 = iVar4 + -1;
        } while ((int)uVar6 <= iVar4);
      }
      *(undefined4 *)(iVar4 * 4 + arg2 + 4) = uVar3;
    } while ((int)uVar5 < (int)(arg1 & 0xffff));
  }
                    /* WARNING: Could not recover jumptable at 0x080edbc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EDBCC @ 0x080EDBCC

void sub_080EDBCC(undefined4 arg0,uint arg1,int arg2)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  ushort uVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  code *UNRECOVERED_JUMPTABLE;
  ushort auStack_a8 [32];
  ushort auStack_68 [32];
  uint uStack_28;
  uint uStack_24;
  
  uStack_28 = (uint)(ushort)arg0;
  uStack_24 = uStack_28;
  uVar3 = (uStack_28 + (arg1 & 0xffff)) - 1;
  iVar14 = 0;
  uVar7 = uVar3 & 0xffff;
  if (10 < ((int)(uVar3 * 0x10000) >> 0x10) - (int)(short)(ushort)arg0) {
    while( true ) {
      do {
        uVar10 = (ushort)uStack_24;
        uVar6 = (ushort)uVar7;
        sVar2 = *(short *)((((int)(short)uVar10 + (int)(short)uVar6) / 2) * 4 + arg2 + 2);
        uVar12 = (int)(short)uVar10 - 1;
        uVar3 = (int)(short)uVar6 + 1;
        puVar11 = (undefined4 *)(uVar3 * 4 + arg2);
        puVar8 = (undefined4 *)(uVar12 * 4 + arg2);
        while( true ) {
          puVar9 = puVar8 + 1;
          uVar12 = uVar12 + 1;
          if (sVar2 < *(short *)((int)puVar8 + 6)) {
            iVar5 = uVar12 * 4 + arg2;
            do {
              puVar9 = puVar9 + 1;
              uVar12 = uVar12 + 1;
              psVar1 = (short *)(iVar5 + 6);
              iVar5 = iVar5 + 4;
            } while (sVar2 < *psVar1);
          }
          iVar5 = uVar3 * 4 + arg2;
          do {
            uVar13 = uVar3;
            puVar11 = puVar11 + -1;
            uVar3 = uVar13 - 1;
            psVar1 = (short *)(iVar5 + -2);
            iVar5 = iVar5 + -4;
          } while (*psVar1 < sVar2);
          if (uVar3 <= uVar12) break;
          uVar4 = *puVar9;
          *puVar9 = *puVar11;
          *puVar11 = uVar4;
          puVar8 = puVar9;
        }
        if ((int)(short)uVar6 - uVar3 < uVar12 - (int)(short)uVar10) {
          if (10 < uVar12 - (int)(short)uVar10) {
            auStack_68[iVar14] = uVar10;
            auStack_a8[iVar14] = (short)uVar12 - 1;
            iVar14 = iVar14 + 1;
          }
          uStack_24 = uVar13 & 0xffff;
        }
        else {
          if (10 < (int)(short)uVar6 - uVar3) {
            auStack_68[iVar14] = (short)uVar3 + 1;
            auStack_a8[iVar14] = uVar6;
            iVar14 = iVar14 + 1;
          }
          uVar7 = uVar12 - 1 & 0xffff;
        }
      } while (10 < (int)(short)uVar7 - (int)(short)uStack_24);
      if (iVar14 == 0) break;
      iVar14 = iVar14 + -1;
      uStack_24 = (uint)auStack_68[iVar14];
      uVar7 = (uint)auStack_a8[iVar14];
    }
  }
  sub_080EDB6C(uStack_28,arg1 & 0xffff,arg2);
                    /* WARNING: Could not recover jumptable at 0x080edd18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EDD1C @ 0x080EDD1C

int sub_080EDD1C(int arg0)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int arg0_00;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  iVar2 = sub_080C35E4(arg0);
  arg0_00 = (int)*(char *)(iVar1 + 0x44);
  if ((*(ushort *)(iVar1 + 0x10) & 0x800) != 0) {
    arg0_00 = 0x3c;
  }
  iVar1 = 0;
  if ((arg0 < 0x10) && (iVar3 = sub_080BFFF0(), iVar3 == 0)) {
    iVar1 = sub_080C1F94(arg0_00,2);
  }
  uVar4 = sub_080C2244();
  iVar1 = arg0_00 * 2 + iVar1 + (uVar4 & 0xf);
  if (iVar2 == 7) {
    uVar4 = sub_080EDB04();
    iVar1 = iVar1 + (uVar4 >> 1);
  }
  return iVar1;
}


// sub_080EDD8C @ 0x080EDD8C

void sub_080EDD8C(void)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  ushort *arg2;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  
  pcVar5 = &DAT_030050e0;
  arg2 = DAT_03006434 + 6;
  uVar1 = DAT_03006434[1];
  uVar9 = 0;
  puVar7 = arg2;
  if (((*DAT_03006434 & 0x2000) == 0) && (uVar1 != 0xc000)) {
    iVar8 = 5;
    do {
      cVar2 = *pcVar5;
      iVar6 = (int)cVar2;
      pcVar5 = pcVar5 + 1;
      if ((iVar6 != -1) &&
         (iVar3 = sub_080C0148(iVar6 - 0x8000U & 0xffff),
         (*(ushort *)(iVar3 + 0x10) & (ushort)0xb160) == 0)) {
        *puVar7 = (short)cVar2;
        uVar4 = sub_080EDD1C(iVar6);
        puVar7[1] = -(short)uVar4;
        puVar7 = puVar7 + 2;
        uVar9 = uVar9 + 1;
      }
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
  }
  if (uVar1 != 0x8000) {
    iVar8 = 0x10;
    do {
      iVar6 = sub_080F2F64(iVar8 - 0x8000U & 0xffff);
      if (*(short *)(iVar6 + 0xe) != 0) {
        sub_080EDD1C(iVar8);
        *puVar7 = (ushort)iVar8;
        uVar4 = sub_080EDD1C(iVar8);
        puVar7[1] = -(short)uVar4;
        puVar7 = puVar7 + 2;
        uVar9 = uVar9 + 1;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0x18);
  }
  *puVar7 = 0xffff;
  sub_080EDB6C(0,uVar9 & 0xffff,arg2);
  return;
}


// sub_080EDE70 @ 0x080EDE70

undefined4 sub_080EDE70(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080F3F44();
  if ((uVar1 & 0x20) == 0) {
    uVar2 = sub_080EDB04();
    iVar3 = sub_080F43A4(5);
    iVar4 = sub_080F43A4(4);
    iVar5 = sub_080F43E0(5);
    iVar6 = sub_080F43E0(4);
    uVar1 = (iVar3 / 2 + iVar4 + (int)(short)uVar2) -
            (iVar5 / 2 + iVar6 + (((int)(short)uVar2 ^ 0xfU) - 7 & 0xff));
    iVar3 = (int)(uVar1 * 0x10000) >> 0x10;
    uVar1 = uVar1 & 0x7fff;
    uVar7 = (ushort)uVar1;
    if (uVar1 != 0) {
      if (iVar3 < 0) {
        uVar7 = (uVar7 ^ 0x7fff) + 1;
      }
      uVar1 = sub_080C2244();
      if ((uVar1 & 0x3f) < (uint)(int)(short)uVar7) {
        if (iVar3 < 0) {
          uVar2 = 0xc000;
          goto LAB_080edf06;
        }
        goto LAB_080edf02;
      }
    }
    uVar2 = 0;
  }
  else {
LAB_080edf02:
    uVar2 = 0x8000;
  }
LAB_080edf06:
                    /* WARNING: Could not recover jumptable at 0x080edf0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080EDF0C @ 0x080EDF0C

dword sub_080EDF0C(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  dword dVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_r10;
  
  iVar1 = sub_080EDAD0();
  if (((iVar1 == 0) && (uVar2 = sub_080ED8F4(), (uVar2 & 0x100) == 0)) &&
     (iVar1 = sub_080C2340(0x166), iVar1 == 0)) {
    if ((DAT_03005180 != 1) && (iVar1 = sub_080B0248(2,0,0), iVar1 == 1)) {
      return 0x146;
    }
    iVar1 = sub_080ED92C();
    if (iVar1 != 0x8000) {
      iVar7 = 0;
      iVar8 = 0;
      iVar1 = 0;
      do {
        iVar6 = (int)*(char *)(iVar1 + 0x30050e0);
        if ((-1 < iVar6) && (iVar3 = sub_080C0830(), iVar3 == 0)) {
          iVar7 = iVar7 + 1;
          uVar2 = sub_080C0DFC(iVar6);
          uVar4 = sub_080C0E20(iVar6);
          iVar8 = iVar8 + (uVar2 & 0xffff) + (uVar4 & 0xffff);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 6);
      for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
        iVar3 = iVar1 + 0x10;
        iVar6 = sub_080C09B0(iVar3);
        if (iVar6 != 0) {
          uVar2 = sub_080C0DFC(iVar3);
          uVar4 = sub_080C0E20(iVar3);
          unaff_r10 = (uVar2 & 0xffff) + (uVar4 & 0xffff);
          break;
        }
      }
      uVar2 = sub_080C2244();
      if ((iVar8 <= (int)(unaff_r10 * iVar7 + (uVar2 & 7))) &&
         (uVar2 = sub_080C2244(), (uVar2 & 0xf) != 0)) goto LAB_080ee00a;
    }
    dVar5 = 0x144;
  }
  else {
LAB_080ee00a:
    dVar5 = 0x145;
  }
  return dVar5;
}


// sub_080EE028 @ 0x080EE028

undefined4 sub_080EE028(int arg0,int arg1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  if (*(int *)(DAT_03006434 + 0x15c) == 0) {
LAB_080ee104:
    uVar5 = 0;
  }
  else {
    if ((*(int *)(DAT_03006434 + 0x15c) != -1) &&
       (iVar3 = sub_080F2F64(arg1 - 0x8000U & 0xffff),
       (*(ushort *)(iVar3 + 0x10) & (ushort)0x3160) == 0)) {
      iVar4 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
      cVar1 = *(char *)(iVar4 + 0x17);
      if (cVar1 != '\b') {
        if ((cVar1 == '\v') || (cVar1 == '\a')) {
          iVar3 = ((*(char *)(iVar3 + 0x41) * 2 - (int)*(short *)(iVar4 + 0x56)) + 0xf) * 2;
          if (iVar3 < 0x100) goto LAB_080ee0f2;
        }
        else {
          if ((cVar1 == '\x04') || (cVar1 == '\n')) {
            sVar2 = *(short *)(iVar4 + 0x4a);
          }
          else {
            sVar2 = *(short *)(iVar4 + 0x4e);
          }
          iVar3 = ((int)*(short *)(iVar3 + 0x52) - (int)sVar2) + 0x10;
          if (-1 < iVar3) {
            iVar4 = sub_080EFD84();
            iVar3 = __divsi3((iVar3 * iVar3 >> 5) * 8,(uint)(byte)(&DAT_0876f792)[iVar4]);
LAB_080ee0f2:
            iVar4 = sub_080C2244();
            if (iVar4 <= iVar3) goto LAB_080ee104;
          }
        }
      }
    }
    uVar5 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080ee10a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*UNRECOVERED_JUMPTABLE)(uVar5);
  return uVar5;
}


// sub_080EE10C @ 0x080EE10C

void sub_080EE10C(int arg0)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(DAT_03006434 + 0x15c);
  iVar5 = 0;
  *(undefined2 *)(DAT_03006434 + 0x130) = 0xffff;
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  if ((*(char *)(iVar1 + 0x17) == '\v') && (*(char *)(iVar1 + 0x5c) == '\\')) {
    uVar3 = 0;
    do {
      iVar1 = sub_080C0148(uVar3 & 0xffff);
      if (((iVar1 != 0) && (iVar2 = sub_080C0830(), iVar2 == 0)) &&
         (iVar2 = sub_080F55F4(arg0,(uint)*(byte *)(iVar1 + 0xc)), iVar2 == 0)) {
        *(ushort *)(DAT_03006434 + iVar5 * 4 + 0x130) = (ushort)*(byte *)(iVar1 + 0xc);
        iVar5 = iVar5 + 1;
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 6);
    iVar1 = 0x10;
    do {
      sub_080C0148(iVar1 - 0x8000U & 0xffff);
      iVar2 = sub_080C09B0(iVar1);
      if (((iVar2 == 1) && (iVar2 = sub_080C0830(), iVar2 == 0)) &&
         (iVar2 = sub_080F55F4(arg0,iVar1), iVar2 == 0)) {
        *(short *)(DAT_03006434 + iVar5 * 4 + 0x130) = (short)iVar1;
        iVar5 = iVar5 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x18);
    *(undefined2 *)(DAT_03006434 + iVar5 * 4 + 0x130) = 0xffff;
    if (iVar5 != 0) {
      return;
    }
  }
  uVar3 = 0;
  if (1 < iVar4 + 1U) {
    if (iVar4 == 0x8000) {
      iVar1 = 0;
      do {
        iVar4 = sub_080F40EC(iVar1);
        if ((-1 < iVar4) && (iVar5 = sub_080C0830(), iVar5 == 0)) {
          *(short *)(DAT_03006434 + uVar3 * 4 + 0x130) = (short)iVar4;
          uVar3 = uVar3 + 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 6);
    }
    else {
      iVar1 = 0;
      do {
        iVar4 = sub_080F40EC(iVar1);
        if ((-1 < iVar4) && (iVar5 = sub_080C0830(), iVar5 == 0)) {
          *(short *)(DAT_03006434 + uVar3 * 4 + 0x130) = (short)iVar4;
          iVar4 = sub_080C2244();
          iVar5 = sub_080BFFF0();
          if (iVar5 == 1) {
            iVar4 = __divsi3(iVar4 * 0x4b,100);
          }
          *(short *)(DAT_03006434 + uVar3 * 4 + 0x132) = -(short)iVar4;
          uVar3 = uVar3 + 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 6);
      sub_080EDB6C(0,uVar3 & 0xffff,DAT_03006434 + 0x130);
    }
    *(undefined2 *)(DAT_03006434 + uVar3 * 4 + 0x130) = 0xffff;
  }
  return;
}


// sub_080EE2E8 @ 0x080EE2E8

void sub_080EE2E8(int arg0)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  short sVar8;
  undefined *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  code *UNRECOVERED_JUMPTABLE;
  int iStack_24;
  
  iVar11 = *(int *)(DAT_03006434 + 0x15c);
  iVar12 = 0;
  *(undefined2 *)(DAT_03006434 + 0x130) = 0xffff;
  iVar3 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  if ((*(char *)(iVar3 + 0x17) == '\v') && (*(char *)(iVar3 + 0x5c) == '\\')) {
    uVar10 = 0;
    do {
      iVar3 = sub_080C0148(uVar10 & 0xffff);
      if (((iVar3 != 0) && (iVar4 = sub_080C0830(), iVar4 == 0)) &&
         (iVar4 = sub_080F55F4(arg0,(uint)*(byte *)(iVar3 + 0xc)), iVar4 == 0)) {
        *(ushort *)(DAT_03006434 + iVar12 * 4 + 0x130) = (ushort)*(byte *)(iVar3 + 0xc);
        iVar12 = iVar12 + 1;
      }
      uVar10 = uVar10 + 1;
    } while ((int)uVar10 < 6);
    iVar4 = 0x10;
    do {
      iVar3 = sub_080C0148(iVar4 - 0x8000U & 0xffff);
      iVar5 = sub_080C09B0(iVar4);
      if (((iVar5 == 1) && (iVar5 = sub_080C0830(), iVar5 == 0)) &&
         (iVar5 = sub_080F55F4(arg0,iVar4), iVar5 == 0)) {
        *(short *)(DAT_03006434 + iVar12 * 4 + 0x130) = (short)iVar4;
        iVar12 = iVar12 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x18);
    *(undefined2 *)(DAT_03006434 + iVar12 * 4 + 0x130) = 0xffff;
    if (iVar12 != 0) goto LAB_080ee69e;
  }
  iVar12 = 0;
  if ((*(char *)(iVar3 + 0x17) == '\b') && ((byte)(*(char *)(iVar3 + 0x5c) + 0xfU) < 2)) {
    uVar10 = 0;
    do {
      iVar3 = sub_080C0148(uVar10 & 0xffff);
      if (((iVar3 != 0) && (iVar4 = sub_080C0830(), iVar4 == 0)) &&
         ((*(ushort *)(iVar3 + 0x10) & 0x4000) == 0)) {
        *(ushort *)(DAT_03006434 + iVar12 * 4 + 0x130) = (ushort)*(byte *)(iVar3 + 0xc);
        iVar12 = iVar12 + 1;
      }
      iVar3 = DAT_03006434;
      uVar10 = uVar10 + 1;
    } while ((int)uVar10 < 6);
    *(int *)(DAT_03006434 + 0x15c) = iVar12;
    *(undefined2 *)(iVar3 + iVar12 * 4 + 0x130) = 0xffff;
    if (iVar12 != 0) goto LAB_080ee69e;
  }
  uVar10 = 0;
  if (1 < iVar11 + 1U) {
    uVar6 = sub_080ED974(*(undefined4 *)(DAT_03006434 + 0x160 + arg0 * 4));
    iVar3 = sub_080EDA24(uVar6);
    if (iVar3 == 0) {
      uVar6 = uVar6 ^ 1;
    }
    iVar3 = sub_080ED990(uVar6);
    iVar12 = sub_080ED954();
    iStack_24 = 8;
    if (iVar12 != 0) {
      iStack_24 = 4;
    }
    sub_080EDA24(uVar6);
    if (iVar11 == 0x8000) {
      iVar3 = 0x10;
      puVar9 = &DAT_0203cba0;
      do {
        if ((*(ushort *)(puVar9 + 0x10) & 0x8000) == 0) {
          *(short *)(DAT_03006434 + uVar10 * 4 + 0x130) = (short)iVar3;
          uVar10 = uVar10 + 1;
        }
        puVar9 = puVar9 + 0x80;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x18);
    }
    else {
      iVar11 = sub_080C0148(arg0 - 0x8000U & 0xffff);
      iVar5 = (iVar3 + -0x10) * 0x80;
      iVar12 = sub_080C1F94((int)*(char *)(iVar11 + 0x44),2);
      iVar4 = sub_080C1F94((int)*(char *)(iVar11 + 0x45),4);
      iVar4 = *(char *)(iVar11 + 0x41) * 2 + iVar12 + iVar4;
      if (arg0 < 4) {
        uVar6 = sub_080C2244();
        iVar11 = (uint)((byte)(&DAT_0203cbad)[iVar5] >> 1) + (uVar6 & 0xf) + 0xe;
      }
      else {
        uVar6 = sub_080C2244();
        iVar4 = iVar4 + (uVar6 & 7);
        iVar11 = sub_080C1F94((int)(char)(&DAT_0203cbe4)[iVar5],2);
        iVar12 = sub_080C1F94((int)(char)(&DAT_0203cbe5)[iVar5],4);
        uVar6 = sub_080C2244();
        iVar11 = (char)(&DAT_0203cbe1)[iVar5] * 2 + iVar11 + iVar12 + (uVar6 & 7);
      }
      if (iVar11 < iVar4) {
        iVar11 = iVar3;
        if (iVar3 < iVar3 + iStack_24) {
          do {
            uVar1 = *(ushort *)(&DAT_0203c3b0 + iVar11 * 0x80);
            if (uVar1 == 0) {
              sVar8 = 0;
LAB_080ee5ee:
              sVar2 = *(short *)(&DAT_0203c3b8 + iVar11 * 0x80);
              iVar12 = DAT_03006434 + uVar10 * 4;
              *(short *)(iVar12 + 0x130) = (short)iVar11;
              *(short *)(iVar12 + 0x132) = sVar8 + sVar2;
              uVar10 = uVar10 + 1;
            }
            else {
              if ((uVar1 & 0xb160) == 0) {
                sVar8 = 0x2706;
                goto LAB_080ee5ee;
              }
              if ((uVar1 & 0x8000) == 0) {
                sVar8 = 0x4e0c;
                goto LAB_080ee5ee;
              }
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 < iStack_24 + iVar3);
        }
      }
      else if (iVar3 < iVar3 + iStack_24) {
        iVar12 = iVar3 * 0x80 + 0x203c3a0;
        iVar11 = iVar3;
        do {
          if ((*(ushort *)(iVar12 + 0x10) & 0x8000) == 0) {
            *(short *)(DAT_03006434 + uVar10 * 4 + 0x130) = (short)iVar11;
            sub_080C2244();
            uVar7 = sub_080C2244();
            *(short *)(DAT_03006434 + uVar10 * 4 + 0x132) = (short)uVar7;
            uVar10 = uVar10 + 1;
          }
          iVar12 = iVar12 + 0x80;
          iVar11 = iVar11 + 1;
        } while (iVar11 < iStack_24 + iVar3);
      }
      sub_080EDB6C(0,uVar10 & 0xffff,DAT_03006434 + 0x130);
    }
    *(undefined2 *)(DAT_03006434 + uVar10 * 4 + 0x130) = 0xffff;
  }
LAB_080ee69e:
                    /* WARNING: Could not recover jumptable at 0x080ee6ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EE6BC @ 0x080EE6BC

uint sub_080EE6BC(int arg0,int arg1,int arg2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = sub_080EDB04();
  DAT_0203d3b0 = 0;
  if (((int)*(short *)(arg0 + 0x12) & 0x8000U) == 0) {
    iVar4 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
    uVar6 = *(byte *)(iVar4 + 0xd) & 0xf;
  }
  else {
    uVar6 = 0;
  }
  uVar6 = (arg2 * (uint)*(byte *)(uVar6 * 9 + iVar3 + 0x876f6ca) & 0xfffff) >> 4;
  uVar7 = (int)*(short *)(arg0 + 0x12) & 0x8000;
  if (uVar7 == 0) {
    iVar3 = 8 - iVar3;
  }
  cVar1 = *(char *)(arg0 + 0x45);
  cVar2 = *(char *)(arg0 + 0x44);
  if (uVar7 == 0) {
    iVar4 = sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
    uVar7 = (uint)*(byte *)(iVar4 + 0x18);
  }
  else {
    uVar7 = 0;
  }
  if (((((byte)(*(char *)(arg0 + 0x17) - 4U) < 2) || (*(char *)(arg0 + 0x17) == '\n')) ||
      (iVar4 = sub_080EED64((int)*(char *)(arg0 + 0x17) & 0xffff,(uint)*(byte *)(arg0 + 0x5c)),
      iVar4 == 1)) &&
     (uVar5 = sub_080C2244(), iVar3 * 2 + (int)cVar1 + (int)cVar2 + uVar7 * 8 <= uVar5)) {
    uVar7 = sub_080C2244();
    if (uVar7 < 4) {
      uVar6 = uVar6 * 3;
      DAT_0203d3b0 = 1;
    }
    else if (uVar7 < 0x10) {
      uVar6 = uVar6 << 1;
      DAT_0203d3b0 = 2;
    }
  }
  if (*(char *)(arg1 + 0x17) == '\t') {
    uVar6 = uVar6 / 2;
  }
  uVar7 = sub_080C2244();
  uVar6 = uVar6 - (uVar6 * (uVar7 & 0x1f) >> 7);
  if ((uVar6 == 0) || ((uVar6 & 0x8000) != 0)) {
    uVar6 = sub_080C2244();
    uVar6 = uVar6 & 1;
  }
  if ((int)uVar6 < 1) {
    uVar6 = 1;
  }
  if ((*(ushort *)(arg1 + 0x10) & 0x4000) != 0) {
    uVar6 = 0;
  }
  return uVar6;
}


// sub_080EE810 @ 0x080EE810

undefined4 sub_080EE810(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while (*(short *)(uVar2 * 4 + 0x876f75a) != (short)arg0) {
    uVar2 = uVar2 + 1 & 0xffff;
    if (0xb < uVar2) {
      return 0;
    }
  }
  iVar1 = sub_080F3F90(arg1,(uint)(ushort)(&DAT_0876f75c)[uVar2 * 2]);
  if (iVar1 - 0xcU < 2) {
    return 0;
  }
  if (iVar1 - 0xeU < 2) {
    return 0;
  }
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}


// sub_080EE864 @ 0x080EE864

undefined4 sub_080EE864(int arg0,int arg1)

{
  char cVar1;
  short sVar2;
  int arg0_00;
  int arg1_00;
  short *psVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  uint local_24;
  
  arg0_00 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  arg1_00 = sub_080F2F64(arg1 - 0x8000U & 0xffff);
  cVar1 = *(char *)(arg0_00 + 0x17);
  if (arg0 < 4) {
    if (cVar1 == '\x04') {
      uVar7 = sub_080C2244();
      if (uVar7 < 0x40) {
        local_24 = sub_080C00DC(arg0,0);
        if (local_24 != 0xff) {
          sub_080BF468(local_24,6,&local_24);
          uVar7 = local_24 & 0xfffe;
          if (((uVar7 != 0) && (uVar4 = sub_080F3214(arg1,uVar7), (uVar4 & 0xff) != 0)) &&
             (uVar4 = sub_080EE810(uVar7,arg1), (uVar4 & 0xffff) != 0)) {
            sub_080EDA7C(uVar7);
          }
        }
      }
      sVar2 = *(short *)(arg0_00 + 0x48);
      goto LAB_080ee95e;
    }
    uVar7 = sub_080C2244();
    if (uVar7 < 0x40) {
      local_24 = sub_080C00DC(arg0,6);
      if (local_24 != 0xff) {
        sub_080BF468(local_24,6,&local_24);
        uVar4 = local_24 & 0xffff;
        uVar7 = sub_080F3214(arg1,uVar4);
        if (((uVar7 & 0xff) != 0) && (uVar7 = sub_080EE810(uVar4,arg1), (uVar7 & 0xffff) != 0)) {
          sub_080EDA7C(uVar4);
        }
      }
    }
    psVar3 = (short *)(arg0_00 + 0x4c);
  }
  else {
    psVar3 = (short *)(arg0_00 + 0x48);
  }
  sVar2 = *psVar3;
LAB_080ee95e:
  iVar9 = (int)sVar2;
  if ((*(ushort *)(arg0_00 + 0x10) & 4) != 0) {
    iVar9 = iVar9 >> 1;
  }
  iVar5 = sub_080EFBFC();
  iVar9 = iVar9 * (uint)(byte)(&DAT_0876f792)[iVar5];
  if (iVar9 < 0) {
    iVar9 = iVar9 + 7;
  }
  iVar5 = sub_080EFD3C();
  iVar5 = (int)*(short *)(arg1_00 + 0x50) * (uint)(byte)(&DAT_0876f792)[iVar5];
  if (iVar5 < 0) {
    iVar5 = iVar5 + 7;
  }
  iVar6 = sub_080C1F94(iVar9 >> 3,4);
  iVar9 = __divsi3((iVar6 + 4) * (iVar9 >> 3),iVar5 >> 3);
  if (cVar1 == '\v') {
    uVar7 = sub_080F3F14(arg0);
    iVar5 = sub_080BF5C0(uVar7 & 0xffff);
    iVar5 = __divsi3(iVar9 * (uint)*(byte *)(iVar5 + 1),100);
    iVar9 = iVar9 + iVar5;
  }
  uVar8 = sub_080EE6BC(arg0_00,arg1_00,iVar9);
  return uVar8;
}


// sub_080EE9F8 @ 0x080EE9F8

void sub_080EE9F8(int *arg0)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint arg0_00;
  uint uVar5;
  int arg0_01;
  int arg1;
  ushort *puVar6;
  dword dVar7;
  int arg1_00;
  uint arg2;
  uint uVar8;
  
  iVar4 = *arg0;
  arg1_00 = arg0[1];
  arg0_00 = sub_080F3F14(iVar4);
  uVar5 = sub_080ED794(arg0_00);
  uVar5 = uVar5 & 0xffff;
  arg0_01 = sub_080F2F64(iVar4 - 0x8000U & 0xffff);
  arg1 = sub_080F2F64(arg1_00 - 0x8000U & 0xffff);
  if ((arg0_00 - 0x9b < 2) || ((int)arg0_00 < 0x68)) {
    uVar2 = *(ushort *)(arg1 + 0x54);
    iVar4 = sub_080EFDCC();
    bVar1 = (&DAT_0876f792)[iVar4];
    uVar3 = *(ushort *)(arg1 + 0x50);
    iVar4 = sub_080EFD3C();
    uVar8 = (((uint)uVar2 * (uint)bVar1 & 0x7ffff) >> 3) +
            (((uint)uVar3 * (uint)(byte)(&DAT_0876f792)[iVar4] & 0x7ffff) >> 5) & 0xffff;
    if (arg0_00 - 0x9b < 2) {
      puVar6 = (ushort *)(arg0_01 + 0x48);
    }
    else {
      puVar6 = (ushort *)(arg0_01 + 0x54);
    }
    uVar2 = *puVar6;
    iVar4 = sub_080EFDCC();
    bVar1 = (&DAT_0876f792)[iVar4];
    iVar4 = sub_080BF5C0(arg0_00 & 0xffff);
    if (0xff < uVar8) {
      uVar8 = 0xff;
    }
    uVar8 = __udivsi3((((uint)uVar2 * (uint)bVar1 & 0x7ffff) >> 3) * (uint)*(byte *)(iVar4 + 1) &
                      0xffff,uVar8);
    arg2 = uVar8 & 0xffff;
    if ((uVar8 & 0x8000) != 0) {
      arg2 = 0;
    }
    dVar7 = sub_080EE6BC(arg0_01,arg1,arg2);
  }
  else {
    dVar7 = sub_080EE864(iVar4,arg1_00);
  }
  uVar8 = sub_080C2244();
  if (((uVar8 < 0x40) && (uVar8 = sub_080F3214(arg1_00,uVar5), (uVar8 & 0xff) != 0)) &&
     (uVar8 = sub_080EE810(uVar5,arg1_00), (uVar8 & 0xffff) != 0)) {
    sub_080EDA7C(uVar5);
  }
  uVar5 = 0;
  do {
    if (arg0_00 == *(byte *)(uVar5 + 0x876f79e)) {
      arg0[6] = dVar7;
      sub_080F49B4(arg0,uVar5);
      dVar7 = arg0[6];
      if (((((1 < (arg0_00 - 0x5c & 0xff)) && (uVar8 = arg0_00 & 0xff, uVar8 != 0x54)) &&
           ((uVar8 != 0x55 && ((uVar8 != 0x5e && (uVar8 != 0x61)))))) && (uVar8 != 0x98)) &&
         ((uVar8 != 0x9b && (uVar8 != 0x9c)))) {
        dVar7 = 0xffff;
      }
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x20);
  arg0[6] = dVar7;
  return;
}


// sub_080EEB94 @ 0x080EEB94

uint sub_080EEB94(int *arg0,undefined4 arg1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint local_24;
  
  iVar1 = *arg0;
  iVar9 = arg0[1];
  arg0[2] = -1;
  uVar2 = sub_080C0D90(iVar1);
  iVar3 = sub_080ED7A4(arg1);
  uVar4 = sub_080C0D90(iVar9);
  uVar4 = uVar4 & 0xffff;
  if (uVar4 == 0) {
    uVar4 = 1;
  }
  uVar5 = __divsi3(iVar3 * (uVar2 & 0xffff),uVar4);
  sub_080EDA7C(0xffff);
  uVar6 = sub_080EFE60(iVar1);
  iVar3 = sub_080F3F90(iVar9,uVar6);
  uVar2 = sub_080EEEE8(uVar5,iVar3);
  if (1 < iVar3 - 0xcU) {
    if ((1 < iVar3 - 0xeU) && (iVar3 != 0)) goto LAB_080eece4;
    iVar3 = sub_080C35E4(iVar1);
    iVar7 = sub_080F3F14(iVar1);
    uVar4 = sub_080EFAB0();
    if (((iVar3 != 7) || ((uVar4 & 1) == 0)) &&
       ((((iVar3 != 0xb || (iVar7 < 0x40)) || (0x67 < iVar7)) || ((uVar4 & 1) == 0)))) {
      uVar2 = 0;
      sub_080EDA7C(0);
      goto LAB_080eece4;
    }
  }
  arg0[1] = *arg0;
  arg0[2] = 0x16e;
  if (iVar1 < 0x10) {
    arg0[2] = 0x16f;
  }
  uVar4 = sub_080ED794(arg1);
  iVar9 = iVar1;
  if ((uVar4 & 0x8000) != 0) {
    uVar2 = sub_080C0D90(iVar1);
    iVar3 = sub_080ED7A4(arg1);
    uVar4 = sub_080C0D90(iVar1);
    uVar4 = uVar4 & 0xffff;
    if (uVar4 == 0) {
      uVar4 = 1;
    }
    uVar5 = __divsi3(iVar3 * (uVar2 & 0xffff),uVar4);
    uVar6 = sub_080EFE60(iVar1);
    iVar1 = sub_080F3F90(iVar1,uVar6);
    uVar2 = sub_080EEEE8(uVar5,iVar1);
    if (((iVar1 - 0xcU < 2) || (iVar1 == 0xf)) || ((iVar1 == 0xe || (iVar1 == 0)))) {
      uVar2 = 0;
      sub_080EDA7C(0);
    }
  }
LAB_080eece4:
  uVar4 = sub_080C0818(iVar9);
  uVar8 = sub_080ED794(arg1);
  local_24 = (uint)((uVar4 & 0xffff & uVar8) != 0);
  if (((uVar2 != 0) && (uVar4 = sub_080C2244(), (uVar4 & 0x1f) < uVar2)) &&
     ((iVar1 = sub_080ED6A4(arg1), iVar1 != 7 || (2 < iVar9)))) {
    uVar2 = sub_080ED794(arg1);
    uVar4 = sub_080F3214(iVar9,uVar2 & 0xffff);
    if (((uVar4 & 0xff) != 0) && (((uVar2 & 2) == 0 || (iVar9 = sub_080F40A8(iVar9), iVar9 != 0))))
    {
      sub_080EDA7C(uVar2 & 0xffff);
    }
  }
  return local_24;
}


// sub_080EED64 @ 0x080EED64

undefined4 sub_080EED64(undefined4 arg0,undefined4 arg1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((short)arg0 == 0xb) && ((ushort)((short)arg1 - 0x68U) < 0x2c)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080eed86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar1;
}


// sub_080EED88 @ 0x080EED88

undefined4 sub_080EED88(undefined4 *arg0)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int arg0_00;
  int iVar6;
  code *UNRECOVERED_JUMPTABLE;
  uint local_24;
  
  uVar2 = *arg0;
  arg0_00 = arg0[1];
  iVar6 = arg0[6];
  sVar1 = *(short *)(DAT_03006434 + 0x158);
  arg0[2] = 0xffffffff;
  uVar3 = sub_080EFAB0();
  uVar4 = sub_080C35E4(uVar2);
  if ((iVar6 < 0) || (sVar1 == -1)) goto LAB_080eee7c;
  local_24 = sub_080F3F14(uVar2);
  if (((uVar4 == 7) || (uVar4 == 0xb)) && ((uVar3 & 0x20) != 0)) {
LAB_080eeec0:
    arg0[6] = 0;
    *(undefined2 *)(DAT_03006434 + 0x158) = 0;
  }
  else {
    if (uVar4 == 7) {
      uVar5 = 1;
LAB_080eee08:
      if ((uVar5 & uVar3 & 0xffff) == 0) goto LAB_080eee0e;
    }
    else {
      if ((uVar4 - 4 < 2) || (uVar4 == 10)) {
        uVar5 = 2;
        goto LAB_080eee08;
      }
LAB_080eee0e:
      if (((((uVar4 != 0xb) || ((int)local_24 < 0x40)) || (0x67 < (int)local_24)) ||
          ((uVar3 & 1) == 0)) &&
         ((iVar6 = sub_080EED64(uVar4 & 0xffff,local_24 & 0xffff), iVar6 != 1 || ((uVar3 & 2) == 0))
         )) {
        if ((arg0_00 < 0x10) && (uVar5 = sub_080F3F44(), (uVar5 & 1) != 0)) {
          if (uVar4 == 7) {
            sub_080F3F58(0xfffffffe);
            goto LAB_080eeeb6;
          }
LAB_080eee60:
          if ((uVar4 != 0xb) && (uVar4 != 8)) goto LAB_080eee7c;
        }
        else if (uVar4 != 7) goto LAB_080eee60;
        if (uVar4 == 8) {
          sub_080BF468(local_24,0xc,&local_24);
        }
        if (0x7f < (int)local_24) {
LAB_080eee7c:
          uVar2 = 0;
          goto LAB_080eeed4;
        }
        if (((uVar3 & 8) == 0) || (iVar6 = sub_080ED6A4(local_24), iVar6 != 2)) {
          if (((uVar3 & 0x10) == 0) || (iVar6 = sub_080ED6A4(local_24), iVar6 != 3))
          goto LAB_080eee7c;
          uVar2 = 0xffffffef;
        }
        else {
          uVar2 = 0xfffffff7;
        }
        sub_080EFB8C(arg0_00,uVar2);
        goto LAB_080eeec0;
      }
    }
LAB_080eeeb6:
    arg0[2] = 0x16e;
  }
  uVar2 = 1;
LAB_080eeed4:
                    /* WARNING: Could not recover jumptable at 0x080eeee2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080EEEE8 @ 0x080EEEE8

int sub_080EEEE8(int arg0,uint arg1)

{
  int iVar1;
  
  if (arg1 != 0xc) {
    if (arg1 == 0xd) {
      return arg0;
    }
    if (arg1 != 0xe) {
      if (arg1 == 0xf) {
        return arg0;
      }
      if ((int)arg1 < 9) {
        iVar1 = arg1 * arg0;
        if (iVar1 < 0) {
          iVar1 = iVar1 + 7;
        }
        return iVar1 >> 3;
      }
      if (0xc < arg1) {
        return 0;
      }
      iVar1 = arg0;
      switch(arg1) {
      case 9:
        iVar1 = arg0 >> 1;
        break;
      case 0xb:
        iVar1 = (arg0 >> 1) + arg0;
        break;
      case 0xc:
        goto switchD_080eef20_caseD_c;
      }
      return iVar1 + arg0;
    }
  }
switchD_080eef20_caseD_c:
  return arg0 / 2;
}


// sub_080EEF98 @ 0x080EEF98

void sub_080EEF98(void)

{
  int iVar1;
  undefined4 uVar2;
  
  switch(*(undefined2 *)(DAT_03006434 + 0x126)) {
  case 1:
    sub_080ED90C(0x80);
    break;
  case 2:
    sub_080ED920(0xc000);
    break;
  case 3:
    sub_080ED920(0x8000);
    break;
  case 4:
    sub_080ED90C(0x2000);
    goto LAB_080ef064;
  case 5:
    uVar2 = sub_080EF878();
    sub_080C08F8(uVar2,0x8000);
    sub_080F4104(uVar2);
    sub_08126834(0xffffffff);
    sub_080E760C();
    iVar1 = sub_080ED9F4();
    if (iVar1 != 0) {
      return;
    }
    *(undefined2 *)(DAT_03006434 + 0x126) = 7;
  case 6:
  case 7:
  case 0xc:
    sub_080ED90C(0x200);
    sub_080EDA04();
    sub_080E74DC();
LAB_080ef064:
    *(undefined2 *)(DAT_03006434 + 4) = 0xffff;
    break;
  case 8:
    iVar1 = sub_080ED9F4();
    if (iVar1 < 8) {
      uVar2 = sub_080EF828();
      sub_080EF224(uVar2,1);
    }
    break;
  case 9:
  case 10:
  case 0xb:
    sub_080ED90C(0x400);
    if (DAT_0203d38e != 0xffff) {
      sub_080F41B0((uint)DAT_0203d38e);
      sub_080C366C();
      DAT_0203d38e = 0xffff;
    }
    sub_080C062C((uint)DAT_0203db7c);
    sub_080C101C();
    *(undefined2 *)(DAT_03006434 + 4) = 0xffff;
  }
  return;
}


// sub_080EF0E4 @ 0x080EF0E4

undefined4 sub_080EF0E4(int arg0)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg0 < 0x10) {
    uVar2 = sub_080F3F44();
    iVar3 = sub_080C06BC(arg0);
    sub_080EDA90();
    if (((uVar2 & 2) == 0) || (1 < iVar3 - 1U)) {
      if (((uVar2 & 8) == 0) || (iVar3 != 0)) goto LAB_080ef0ec;
      uVar2 = uVar2 & 0xfff7;
      uVar1 = 0xf4;
    }
    else {
      uVar2 = uVar2 & 0xfffd;
      uVar1 = 0xf3;
    }
    sub_080F3E38(uVar1);
    sub_080F3F30(uVar2);
    uVar1 = 1;
  }
  else {
LAB_080ef0ec:
    uVar1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080ef142. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar1;
}


// sub_080EF148 @ 0x080EF148

void sub_080EF148(int arg0,int arg1)

{
  undefined4 uVar1;
  uint arg0_00;
  int iVar2;
  int in_r2;
  int *piVar3;
  int iVar4;
  int arg0_01;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg0 < 0) {
    arg0 = 0;
  }
  sub_080C0818(arg0);
  sub_080C08F8(arg0,0x8000);
  uVar1 = sub_080C07E0(arg0);
  arg0_01 = (int)(short)uVar1;
  sub_080F4054(arg0,0);
  sub_080F40C4(arg0_01);
  if (arg0 < 0x10) {
    if (arg0 < 4) {
      uVar1 = sub_080BFFC4(arg0);
      sub_080C8490(uVar1);
    }
    else {
      sub_080F4190(arg0);
    }
  }
  else {
    if (arg1 == 1) {
      iVar4 = 0;
      do {
        arg0_00 = sub_080F40EC(iVar4);
        if (arg0_00 < 4) {
          uVar1 = sub_080C0F8C(arg0_00);
          iVar2 = sub_080EF494((int)(short)uVar1,arg0_01);
          piVar3 = (int *)(DAT_03006434 + 0x68 + arg0_00 * 4);
          *piVar3 = *piVar3 + iVar2;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 6);
      iVar4 = sub_080EF538(arg0_01);
      *(int *)(DAT_03006434 + 0x4c) = *(int *)(DAT_03006434 + 0x4c) + iVar4;
      iVar4 = sub_080EF580(arg0_01);
      in_r2 = DAT_03006434;
      *(int *)(DAT_03006434 + 0x50) = *(int *)(DAT_03006434 + 0x50) + iVar4;
    }
    sub_080EF6B4(arg0_01);
    sub_080ED8F4();
    sub_080E7538(arg0 + -0x10,2,in_r2);
  }
                    /* WARNING: Could not recover jumptable at 0x080ef20a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EF20C @ 0x080EF20C

void sub_080EF20C(void)

{
  undefined4 in_r0;
  
  sub_080EF148(in_r0,0);
  return;
}


