/* Ghidra decompilation of asm/code_080C6FD8.s (reference only; not compiled). */

// sub_080C6FD8 @ 0x080C6FD8

void sub_080C6FD8(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    sub_080C6F30(uVar1 & 0xffff);
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 6);
  return;
}


// sub_080C6FF0 @ 0x080C6FF0

void sub_080C6FF0(void)

{
  short sVar1;
  
  sVar1 = DAT_0200e7d4;
  if (DAT_0200e7d4 == 0) {
    DAT_0200e7d4 = 1;
    DAT_0200e7e4 = sVar1;
    DAT_0200e7f4 = 1;
  }
  return;
}


// sub_080C700C @ 0x080C700C

void sub_080C700C(void)

{
  int iVar1;
  
  iVar1 = sub_080C8AF8();
  if ((iVar1 != 0) && (DAT_0200e7d4 == 3)) {
    DAT_0200e7d4 = 2;
    DAT_0200e7f4 = 1;
  }
  return;
}


// sub_080C7038 @ 0x080C7038

void sub_080C7038(void)

{
  short sVar1;
  
  sVar1 = DAT_0200e7d6;
  if (DAT_0200e7d6 == 0) {
    DAT_0200e7d6 = 1;
    DAT_0200e7e6 = sVar1;
    DAT_0200e7f6 = 1;
  }
  return;
}


// sub_080C7054 @ 0x080C7054

void sub_080C7054(void)

{
  if (DAT_0200e7d6 == 3) {
    DAT_0200e7d6 = 2;
    DAT_0200e7f6 = 1;
  }
  return;
}


// sub_080C7070 @ 0x080C7070

void sub_080C7070(short *arg0,short *arg1,ushort *arg2)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = 7;
  if (*arg0 == 1) {
    sub_080AB438(0,0x200dfd4,0,0);
    if (1 < *arg2) {
      uVar4 = *arg2 - 1;
      uVar3 = 7 - uVar4 & 0xffff;
      uVar4 = uVar4 & 0xffff;
    }
    if (uVar3 == 0) {
      *arg0 = 3;
    }
    else {
      sub_080AB250(uVar4 * 2 + 0x81b8270,0x200dfd4,0,0);
    }
    sub_080C6764();
    sVar1 = *arg1;
    *arg1 = sVar1 + -1;
    if ((short)(sVar1 + -1) != 0) goto LAB_080c71aa;
    *arg1 = 1;
    uVar2 = *arg2 + 1;
  }
  else {
    if (*arg0 != 2) goto LAB_080c71aa;
    sub_080AB438(0,0x200dfd4,0,0);
    if (1 < *arg2) {
      uVar4 = *arg2 - 1;
      uVar3 = 7 - uVar4 & 0xffff;
      uVar4 = uVar4 & 0xffff;
    }
    if ((uVar3 != 0 && -1 < (int)(uVar3 * 0x10000)) &&
       (sub_080AB250(uVar4 * 2 + 0x81b8270,0x200dfd4,0,0), *arg2 == 0)) {
      *arg0 = 0;
    }
    sub_080C6764();
    sVar1 = *arg1;
    *arg1 = sVar1 + -1;
    if ((short)(sVar1 + -1) != 0) goto LAB_080c71aa;
    *arg1 = 1;
    uVar2 = *arg2 - 1;
  }
  *arg2 = uVar2;
LAB_080c71aa:
  if (*arg0 != 3) {
    sub_080AA184(0x80005a0,0,0,0);
  }
  return;
}


// sub_080C71EC @ 0x080C71EC

void sub_080C71EC(void)

{
  sub_080C7070(0x200e7d4,&DAT_0200e7f4,&DAT_0200e7e4);
  sub_080C7070(&DAT_0200e7d6,&DAT_0200e7f6,&DAT_0200e7e6);
  return;
}


// sub_080C7218 @ 0x080C7218

void sub_080C7218(void)

{
  short sVar1;
  
  sVar1 = DAT_0200e7d8;
  if (DAT_0200e7d8 == 0) {
    DAT_0200e7d8 = 1;
    DAT_0200e7e8 = sVar1;
    DAT_0200e7f8 = 1;
  }
  return;
}


// sub_080C7234 @ 0x080C7234

void sub_080C7234(void)

{
  int iVar1;
  
  iVar1 = sub_080C8AF8();
  if ((iVar1 != 0) && (DAT_0200e7d8 == 3)) {
    DAT_0200e7d8 = 2;
    DAT_0200e7f8 = 1;
    DisplayList_Add(0x80c65a5,1);
  }
  return;
}


// sub_080C726C @ 0x080C726C

void sub_080C726C(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 2;
  if (DAT_0200e7d8 == 1) {
    sub_080AB438(0,0x200dfd4,0xd,0);
    uVar1 = (uint)DAT_0200e7e8;
    uVar3 = 0;
    if (uVar1 != 0) {
      uVar2 = 2 - uVar1 & 0xffff;
      uVar3 = uVar1;
    }
    if (uVar2 == 0) {
      DAT_0200e7d8 = 3;
    }
    else {
      sub_080AB250(uVar3 * 0x40 + 0x81b92b0,0x200dfd4,0,0);
    }
    sub_080C6764();
    DAT_0200e7f8 = DAT_0200e7f8 + -1;
    if (DAT_0200e7f8 != 0) goto LAB_080c73b2;
    DAT_0200e7e8 = DAT_0200e7e8 + 1;
  }
  else {
    if (DAT_0200e7d8 != 2) goto LAB_080c73b2;
    if (DAT_03005180 == 1) {
      return;
    }
    sub_080AB438(0,0x200dfd4,0xd,0);
    uVar1 = (uint)DAT_0200e7e8;
    uVar3 = 0;
    if (uVar1 != 0) {
      uVar2 = 2 - uVar1 & 0xffff;
      uVar3 = uVar1;
    }
    if ((uVar2 != 0 && -1 < (int)(uVar2 * 0x10000)) &&
       (sub_080AB250(uVar3 * 0x40 + 0x81b92b0,0x200dfd4,0,0), DAT_0200e7e8 == 0)) {
      DAT_0200e7d8 = DAT_0200e7e8;
    }
    sub_080C6764();
    DAT_0200e7f8 = DAT_0200e7f8 + -1;
    if (DAT_0200e7f8 != 0) goto LAB_080c73b2;
    DAT_0200e7e8 = DAT_0200e7e8 - 1;
  }
  DAT_0200e7f8 = 1;
LAB_080c73b2:
  if (DAT_0200e7d8 != 3) {
    sub_080AA184(*(undefined4 *)((uint)DAT_03004552 * 4 + 0x834a214),0,0,0);
  }
  return;
}


// sub_080C7414 @ 0x080C7414

void sub_080C7414(void)

{
  short sVar1;
  
  sVar1 = DAT_0200e7da;
  if (DAT_0200e7da == 0) {
    DAT_0200e7da = 1;
    DAT_0200e7ea = sVar1;
    DAT_0200e7fa = 1;
  }
  return;
}


// sub_080C7430 @ 0x080C7430

void sub_080C7430(void)

{
  int iVar1;
  
  iVar1 = sub_080C8AF8();
  if ((iVar1 != 0) && (DAT_0200e7da == 3)) {
    DAT_0200e7da = 2;
    DAT_0200e7fa = 1;
  }
  return;
}


// sub_080C745C @ 0x080C745C

void sub_080C745C(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar3 = 0;
  uVar5 = 0x15;
  uVar2 = 8;
  if (DAT_0200e7da == 1) {
    sub_080AB438(0,0x200dfd4,0x15,0);
    uVar5 = (uint)DAT_0200e7ea;
    if (0x1e < uVar5 + 0x1d) {
      uVar2 = 8 - uVar5 & 0xffff;
      uVar3 = uVar5;
    }
    uVar5 = uVar5 + 0x15 & 0xffff;
    if (uVar2 == 0) {
      DAT_0200e7da = 3;
    }
    else {
      sub_080AB250(uVar3 * 2 + 0x81b8170,0x200dfd4,0,0);
    }
    sub_080C6764();
    DAT_0200e7fa = DAT_0200e7fa + -1;
    if (DAT_0200e7fa != 0) goto LAB_080c75b2;
    DAT_0200e7ea = DAT_0200e7ea + 1;
  }
  else {
    if (DAT_0200e7da != 2) goto LAB_080c75b2;
    sub_080AB438(0,0x200dfd4,0x15,0);
    uVar5 = (uint)DAT_0200e7ea;
    if (0x1e < uVar5 + 0x1d) {
      uVar2 = 8 - uVar5 & 0xffff;
      uVar3 = uVar5;
    }
    uVar5 = uVar5 + 0x15 & 0xffff;
    if ((uVar2 != 0 && -1 < (int)(uVar2 * 0x10000)) &&
       (sub_080AB250(uVar3 * 2 + 0x81b8170,0x200dfd4,0,0), DAT_0200e7ea == 0)) {
      DAT_0200e7da = DAT_0200e7ea;
    }
    sub_080C6764();
    DAT_0200e7fa = DAT_0200e7fa + -1;
    if (DAT_0200e7fa != 0) goto LAB_080c75b2;
    DAT_0200e7ea = DAT_0200e7ea - 1;
  }
  DAT_0200e7fa = 1;
LAB_080c75b2:
  if (DAT_0200e7da != 3) {
    uVar4 = 0;
    if (DAT_0200e844 != 0) {
      uVar4 = 2;
      uVar1 = DAT_0200e844 + 1;
      DAT_0200e844 = DAT_0200e844 + 1;
      if (3 < uVar1) {
        DAT_0200e844 = 0;
      }
    }
    sub_080AA184(0x80007fc,0,uVar4,0);
    uVar4 = sub_080C3168();
    sub_080C7FD0(uVar4,uVar5 * 8 + 8 & 0xffff,5,0);
  }
  return;
}


// sub_080C762C @ 0x080C762C

void sub_080C762C(void)

{
  short sVar1;
  
  sVar1 = DAT_0200e7dc;
  if (DAT_0200e7dc == 0) {
    DAT_0200e7dc = 1;
    DAT_0200e7ec = sVar1;
    DAT_0200e7fc = 1;
  }
  return;
}


// sub_080C7648 @ 0x080C7648

void sub_080C7648(void)

{
  if (DAT_0200e7dc == 3) {
    DAT_0200e7dc = 2;
    DAT_0200e7fc = 1;
  }
  return;
}


// sub_080C7664 @ 0x080C7664

void sub_080C7664(uint arg0,uint arg1,undefined4 arg2)

{
  sub_080AA184(0x800080c,0,0,0);
  sub_080C8048(arg2,(arg0 & 0xffff) * 8 + 8 & 0xffff,(arg1 & 0xffff) * 8 + 5 & 0xffff,0);
  return;
}


// sub_080C76B4 @ 0x080C76B4

void sub_080C76B4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0x15;
  uVar1 = 8;
  if (DAT_0200e7dc == 1) {
    sub_080AB438(0,0x200dfd4,0x15,2);
    uVar3 = (uint)DAT_0200e7ec;
    if (0x1e < uVar3 + 0x1c) {
      uVar1 = 8 - uVar3 & 0xffff;
      uVar2 = uVar3;
    }
    uVar3 = uVar3 + 0x15 & 0xffff;
    if (uVar1 == 0) {
      DAT_0200e7dc = 3;
    }
    else {
      sub_080AB250(uVar2 * 2 + 0x81b8170,0x200dfd4,0,0);
    }
    sub_080C6764();
    DAT_0200e7fc = DAT_0200e7fc + -1;
    if (DAT_0200e7fc != 0) goto LAB_080c780a;
    DAT_0200e7ec = DAT_0200e7ec + 1;
  }
  else {
    if (DAT_0200e7dc != 2) goto LAB_080c780a;
    sub_080AB438(0,0x200dfd4,0x15,2);
    uVar3 = (uint)DAT_0200e7ec;
    if (0x1e < uVar3 + 0x1d) {
      uVar1 = 8 - uVar3 & 0xffff;
      uVar2 = uVar3;
    }
    uVar3 = uVar3 + 0x15 & 0xffff;
    if ((uVar1 != 0 && -1 < (int)(uVar1 * 0x10000)) &&
       (sub_080AB250(uVar2 * 2 + 0x81b8170,0x200dfd4,0,0), DAT_0200e7ec == 0)) {
      DAT_0200e7dc = DAT_0200e7ec;
    }
    sub_080C6764();
    DAT_0200e7fc = DAT_0200e7fc + -1;
    if (DAT_0200e7fc != 0) goto LAB_080c780a;
    DAT_0200e7ec = DAT_0200e7ec - 1;
  }
  DAT_0200e7fc = 1;
LAB_080c780a:
  if (DAT_0200e7dc != 3) {
    sub_080C7664(uVar3,2,DAT_03005198);
  }
  return;
}


// sub_080C7848 @ 0x080C7848

void sub_080C7848(void)

{
  short sVar1;
  
  sVar1 = DAT_0200e7e0;
  if (DAT_0200e7e0 == 0) {
    DAT_0200e7e0 = 1;
    DAT_0200e7f0 = sVar1;
    DAT_0200e800 = 1;
  }
  return;
}


// sub_080C7864 @ 0x080C7864

void sub_080C7864(void)

{
  if (DAT_0200e7e0 == 3) {
    DAT_0200e7e0 = 2;
    DAT_0200e800 = 1;
  }
  return;
}


// sub_080C7880 @ 0x080C7880

void sub_080C7880(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 6;
  if (DAT_0200e7e0 == 1) {
    sub_080AB438(0,0x200dfd4,0x16,0);
    uVar1 = (uint)DAT_0200e7f0;
    if (0x1e < uVar1 + 0x1c) {
      uVar3 = 6 - uVar1 & 0xffff;
      uVar2 = uVar1;
    }
    if (uVar3 == 0) {
      DAT_0200e7e0 = 3;
    }
    else {
      sub_080AB250(uVar2 * 2 + 0x81b7170,0x200dfd4,0,0);
    }
    sub_080C6764();
    DAT_0200e800 = DAT_0200e800 + -1;
    if (DAT_0200e800 != 0) goto LAB_080c79da;
    DAT_0200e7f0 = DAT_0200e7f0 + 1;
  }
  else {
    if (DAT_0200e7e0 != 2) goto LAB_080c79da;
    sub_080AB438(0,0x200dfd4,0x16,0);
    uVar1 = (uint)DAT_0200e7f0;
    if (0x1e < uVar1 + 0x1c) {
      uVar3 = 6 - uVar1 & 0xffff;
      uVar2 = uVar1;
    }
    if ((uVar3 != 0 && -1 < (int)(uVar3 * 0x10000)) &&
       (sub_080AB250(uVar2 * 2 + 0x81b7170,0x200dfd4,0,0), DAT_0200e7f0 == 0)) {
      DAT_0200e7e0 = DAT_0200e7f0;
    }
    sub_080C6764();
    DAT_0200e800 = DAT_0200e800 + -1;
    if (DAT_0200e800 != 0) goto LAB_080c79da;
    DAT_0200e7f0 = DAT_0200e7f0 - 1;
  }
  DAT_0200e800 = 1;
LAB_080c79da:
  if (DAT_0200e7e0 != 3) {
    uVar2 = sub_080B447C();
    uVar3 = uVar2 & 0xffff;
    sub_080AA184(0x8000a74,1,0,1);
    sub_080AA184(*(undefined4 *)((uVar2 & 3) * 4 + 0x834a3cc),1,0,1);
    sub_080AA184(*(undefined4 *)((uVar3 + 1 & 3) * 4 + 0x834a3cc),1,0,1);
    sub_080AA184(*(undefined4 *)((uVar3 + 2 & 3) * 4 + 0x834a3cc),1,0,1);
    sub_080AA184(*(undefined4 *)((uVar3 + 3 & 3) * 4 + 0x834a3cc),1,0,1);
  }
  return;
}


// sub_080C7ACC @ 0x080C7ACC

void sub_080C7ACC(void)

{
  DAT_0200e7e2 = 1;
  DAT_0200e7f2 = 0;
  DAT_0200e802 = 1;
  return;
}


// sub_080C7AE0 @ 0x080C7AE0

void sub_080C7AE0(void)

{
  DAT_0200e7e2 = 2;
  DAT_0200e802 = 1;
  return;
}


// sub_080C7AF0 @ 0x080C7AF0

uint sub_080C7AF0(void)

{
  return (uint)DAT_0200e7e2;
}


// sub_080C7AFC @ 0x080C7AFC

void sub_080C7AFC(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = 6;
  if (DAT_0200e7e2 == 1) {
    sub_080AB438(0,0x200dfd4,0x17,3);
    uVar1 = (uint)DAT_0200e7f2;
    if (0x1e < uVar1 + 0x1d) {
      uVar2 = 6 - uVar1 & 0xffff;
      uVar3 = uVar1;
    }
    if (uVar2 == 0) {
      DAT_0200e7e2 = 3;
    }
    else {
      sub_080AB250(uVar3 * 2 + 0x834a3dc,0x200dfd4,0,0);
    }
    sub_080C6764();
    if ((short)(DAT_0200e802 + -1) != 0) {
      DAT_0200e802 = DAT_0200e802 + -1;
      return;
    }
    DAT_0200e7f2 = DAT_0200e7f2 + 1;
  }
  else {
    if (DAT_0200e7e2 != 2) {
      return;
    }
    sub_080AB438(0,0x200dfd4,0x17,3);
    uVar1 = (uint)DAT_0200e7f2;
    if (0x1e < uVar1 + 0x1d) {
      uVar2 = 6 - uVar1 & 0xffff;
      uVar3 = uVar1;
    }
    if ((uVar2 != 0 && -1 < (int)(uVar2 * 0x10000)) &&
       (sub_080AB250(uVar3 * 2 + 0x834a3dc,0x200dfd4,0,0), DAT_0200e7f2 == 0)) {
      DAT_0200e7e2 = DAT_0200e7f2;
    }
    sub_080C6764();
    if ((short)(DAT_0200e802 + -1) != 0) {
      DAT_0200e802 = DAT_0200e802 + -1;
      return;
    }
    DAT_0200e7f2 = DAT_0200e7f2 - 1;
  }
  DAT_0200e802 = 1;
  return;
}


// sub_080C7C60 @ 0x080C7C60

void sub_080C7C60(void)

{
  DAT_0200e804 = 1;
  DAT_0200e7de = 3;
  sub_080AB438(0,0x200dfd4,3,0xc);
  sub_080C6764();
  return;
}


// sub_080C7C94 @ 0x080C7C94

void sub_080C7C94(void)

{
  DAT_0200e804 = 0;
  DAT_0200e7de = 0;
  sub_080C6558();
  sub_080C6764();
  return;
}


// sub_080C7CB0 @ 0x080C7CB0

void sub_080C7CB0(void)

{
  DAT_0203a44e = 0;
  return;
}


// sub_080C7CBC @ 0x080C7CBC

void sub_080C7CBC(void)

{
  DAT_0203a44e = 1;
  return;
}


// sub_080C7CC8 @ 0x080C7CC8

void sub_080C7CC8(void)

{
  sub_080C7CBC();
  sub_080C7EFC();
  return;
}


// sub_080C7CD8 @ 0x080C7CD8

void sub_080C7CD8(void)

{
  ushort uVar1;
  uint uVar2;
  
  if (DAT_03006a24 == 0) {
    sub_080AA184(0x80005a0,0,0,0);
    if ((DAT_030031bc & 0xf) == 0) {
      DAT_030050e7 = DAT_030050e7 + 1 & 7;
      DisplayList_Add(0x80c7efd,1);
    }
    sub_080AA184(0x80019d4,0,0xc,0);
    uVar2 = sub_080AB184();
    uVar1 = DAT_0203a44e;
    if ((((uVar2 & 0xffff) == 1) && (DAT_0203a44e == 0)) &&
       ((DAT_0200e80c == 0 || (DAT_0200e80c = DAT_0200e80c + -1, DAT_0200e80c == 0)))) {
      sub_080C67C0(0x3002db0,0xc);
      uVar2 = sub_080C7E90();
      DAT_0200e806 = DAT_0200e806 + 1;
      if ((uVar2 & 0xffff) <= (uint)DAT_0200e806) {
        DAT_0200e806 = uVar1;
      }
      sub_080AABB0();
    }
  }
  return;
}


// sub_080C7DAC @ 0x080C7DAC

void sub_080C7DAC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200e8d8;
  REG_DMA3DAD = 0x6016040;
  REG_DMA3CNT = 0x84000060;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C7DD0 @ 0x080C7DD0

void sub_080C7DD0(char *arg0)

{
  undefined4 uVar1;
  undefined4 local_10;
  
  local_10 = 0;
  REG_DMA3SAD = &local_10;
  REG_DMA3DAD = 0x200e8d8;
  REG_DMA3CNT = 0x85000060;
  uVar1 = REG_DMA3CNT;
  sub_080C7E24(0x200e8d8,arg0);
  DisplayList_Add(0x80c7dad,1);
  for (; *arg0 != '\0'; arg0 = arg0 + 1) {
  }
  return;
}


// sub_080C7E24 @ 0x080C7E24

void sub_080C7E24(undefined4 *arg0,byte *arg1)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  bVar1 = *arg1;
  while (bVar1 != 0) {
    if (bVar1 == 0x2e) {
      puVar4 = (undefined4 *)0x81ad898;
      uVar3 = 0;
      do {
        uVar2 = *puVar4;
        puVar4 = puVar4 + 1;
        *arg0 = uVar2;
        arg0 = arg0 + 1;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 8);
    }
    else if (bVar1 == 0x20) {
      uVar3 = 0;
      do {
        *arg0 = 0;
        arg0 = arg0 + 1;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 8);
    }
    else {
      puVar4 = (undefined4 *)
               (&UNK_081ad7b8 + (uint)*(ushort *)((*arg1 - 0x2f) * 2 + 0x834a5dc) * 0x20);
      uVar3 = 0;
      do {
        uVar2 = *puVar4;
        puVar4 = puVar4 + 1;
        *arg0 = uVar2;
        arg0 = arg0 + 1;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 8);
    }
    arg1 = arg1 + 1;
    bVar1 = *arg1;
  }
                    /* WARNING: Could not recover jumptable at 0x080c7e8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C7E90 @ 0x080C7E90

undefined4 sub_080C7E90(void)

{
  undefined4 uVar1;
  
  if ((DAT_0200ab04 & 0x7fff) == 0) {
    uVar1 = 0xe;
  }
  else {
    uVar1 = 0xb;
  }
  return uVar1;
}


// sub_080C7EB4 @ 0x080C7EB4

void sub_080C7EB4(int arg0,undefined2 *arg1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)DAT_0200e806;
  uVar1 = sub_080C7E90();
  uVar1 = uVar1 & 0xffff;
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      uVar2 = sub_080ACC54((uint)*(ushort *)(arg0 + uVar3 * -2));
      *arg1 = (short)uVar2;
      uVar3 = uVar3 + 1;
      if (uVar3 == uVar1) {
        uVar3 = 0;
      }
      arg1 = arg1 + -1;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return;
}


// sub_080C7EFC @ 0x080C7EFC

void sub_080C7EFC(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = sub_080C1D9C();
  uVar2 = (uVar2 >> 4) * 8 + (uint)DAT_030050e7;
  REG_DMA3SAD = uVar2 * 0x80 + 0x81bba70;
  REG_DMA3DAD = 0x6010120;
  REG_DMA3CNT = 0x84000020;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = *(int *)((uVar2 >> 3) * 4 + 0x834a634) + 0x81bba70;
  REG_DMA3DAD = 0x6010020;
  REG_DMA3CNT = 0x84000020;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C7F64 @ 0x080C7F64

void sub_080C7F64(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = sub_080A9CC0(arg0);
  bVar1 = false;
  uVar4 = 0;
  do {
    uVar3 = (uint)*(byte *)((iVar2 + 7) - uVar4);
    if (((uVar4 == 7) || (bVar1)) || (uVar3 != 0)) {
      sub_080AA184(*(undefined4 *)(uVar3 * 4 + 0x834a674),arg3 & 0xffff,0,1);
      bVar1 = true;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 8);
  return;
}


// sub_080C7FD0 @ 0x080C7FD0

void sub_080C7FD0(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint in_stack_00000000;
  
  iVar2 = sub_080A9CC0(arg0);
  bVar1 = false;
  uVar4 = 0;
  do {
    uVar3 = (uint)*(byte *)((iVar2 + 7) - uVar4);
    if (((uVar4 == 7) || (bVar1)) || (uVar3 != 0)) {
      sub_080AA184(*(undefined4 *)(uVar3 * 4 + 0x834a69c),arg3 & 0xffff,in_stack_00000000 & 0xffff,1
                  );
      bVar1 = true;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 8);
  return;
}


// sub_080C8048 @ 0x080C8048

void sub_080C8048(undefined4 arg0,uint arg1,uint arg2,uint arg3)

{
  sub_080C7FD0(arg0,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  return;
}


// sub_080C8068 @ 0x080C8068

void sub_080C8068(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  uint arg1_00;
  uint arg2_00;
  uint arg3_00;
  
  arg1_00 = arg0 & 0xffff;
  arg2_00 = arg1 & 0xffff;
  arg3_00 = arg2 & 0xffff;
  if ((short)arg3 == 0x1e) {
    sub_080AA1F4(0x834a6d4,arg1_00,arg2_00,arg3_00);
    sub_080AA1F4(&DAT_0834a6dc,arg1_00,arg2_00,arg3_00);
  }
  else {
    sub_080AA1F4(0x834a6c4,arg1_00,arg2_00,arg3_00);
    sub_080AA1F4(&DAT_0834a6cc,arg1_00,arg2_00,arg3_00);
  }
  return;
}


// sub_080C8104 @ 0x080C8104

void sub_080C8104(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  sub_080AA1F4(0x834a6e4,arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff);
  return;
}


// sub_080C8148 @ 0x080C8148

undefined4 * sub_080C8148(int arg0,undefined4 *arg1)

{
  *arg1 = *(undefined4 *)(arg0 + 0x81ad5b8);
  arg1[1] = *(undefined4 *)(&DAT_081ad5bc + arg0);
  arg1[2] = *(undefined4 *)(&DAT_081ad5c0 + arg0);
  arg1[3] = *(undefined4 *)(&DAT_081ad5c4 + arg0);
  arg1[4] = *(undefined4 *)(&DAT_081ad5c8 + arg0);
  arg1[5] = *(undefined4 *)(&DAT_081ad5cc + arg0);
  arg1[6] = *(undefined4 *)(&DAT_081ad5d0 + arg0);
  arg1[7] = *(undefined4 *)(&DAT_081ad5d4 + arg0);
  return arg1 + 8;
}


// sub_080C8174 @ 0x080C8174

void sub_080C8174(uint arg0,uint arg1,undefined4 arg2)

{
  byte *pbVar1;
  
  if (arg0 < 1000) {
    arg1 = arg0;
  }
  pbVar1 = (byte *)sub_080A9CC0(arg1);
  if (pbVar1[2] == 0) {
    if (pbVar1[1] == 0) goto LAB_080c81e6;
  }
  else {
    sub_080AC4E4((uint)pbVar1[2] * 0x20 + 0x81b17b8,arg2,0,0);
  }
  sub_080AC4E4((uint)pbVar1[1] * 0x20 + 0x81b17b8,arg2,0,0);
LAB_080c81e6:
  sub_080AC4E4((uint)*pbVar1 * 0x20 + 0x81b17b8,arg2,0,0);
  return;
}


// sub_080C8214 @ 0x080C8214

void sub_080C8214(uint arg0,uint arg1,uint arg2,uint arg3)

{
  uint uVar1;
  dword dVar2;
  undefined4 uVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  uint arg0_00;
  uint uVar9;
  uint in_stack_00000000;
  ushort in_stack_00000004;
  undefined4 local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  uVar9 = arg0 & 0xffff;
  local_40 = arg1 & 0xffff;
  local_3c = arg2 & 0xffff;
  local_38 = arg3 & 0xffff;
  local_34 = in_stack_00000000 & 0xffff;
  arg0_00 = (uint)in_stack_00000004;
  if (local_34 < arg0_00) {
    uVar1 = 0x2e;
  }
  else {
    uVar1 = __divsi3(arg0_00 * 0x2e,local_34);
    uVar1 = uVar1 & 0xffff;
  }
  if (local_40 == 0) {
    iVar7 = uVar9 * 0x180 + 0x200e8d8;
    dVar2 = 0x200f7d8;
  }
  else {
    iVar7 = uVar9 * 0x180 + 0x200e998;
    dVar2 = 0x200f7da;
  }
  puVar4 = (ushort *)(uVar9 * 4 + dVar2);
  local_2c = uVar9 << 3;
  local_24 = local_3c + 0x1d;
  local_30 = local_38 - 3;
  if (*puVar4 != arg0_00) {
    *puVar4 = in_stack_00000004;
    uVar5 = uVar1;
    if (7 < uVar1) {
      uVar5 = 7;
    }
    uVar3 = sub_080C8148(*(undefined4 *)(uVar5 * 4 + 0x834a6ec),iVar7);
    uVar5 = 0xf;
    uVar8 = 0;
    local_28 = uVar9 << 8;
    do {
      if (uVar5 < uVar1) {
        uVar6 = 8;
      }
      else if ((int)(uVar5 - 8) < (int)uVar1) {
        uVar6 = uVar1 & 7;
      }
      else {
        uVar6 = 0;
      }
      uVar8 = uVar8 + 1;
      uVar3 = sub_080C8148(*(undefined4 *)(uVar6 * 4 + 0x834a70c),uVar3);
      uVar5 = uVar5 + 8 & 0xffff;
    } while (uVar8 < 4);
    if (uVar1 == 0x2e) {
      uVar1 = 7;
    }
    else if (uVar1 < 0x27) {
      uVar1 = 0;
    }
    else {
      uVar1 = uVar1 - 0x27 & 0xffff;
    }
    sub_080C8148(*(undefined4 *)(uVar1 * 4 + 0x834a730),uVar3);
    if (local_40 == 0) {
      iVar7 = local_28 + 0x200f1d8;
    }
    else {
      iVar7 = local_28 + 0x200f258;
    }
    local_44 = 0;
    REG_DMA3SAD = &local_44;
    REG_DMA3DAD = iVar7;
    REG_DMA3CNT = 0x85000020;
    uVar3 = REG_DMA3CNT;
    sub_080C8174(arg0_00,local_34,iVar7);
    DAT_0200f7f0 = 1;
  }
  if (local_40 == 0) {
    sub_080C8068(7,1,1,(uVar9 * 3 & 0x3fff) << 2);
    sub_080C8104(7,0,1,(arg0 & 0x1fff) << 3);
  }
  else {
    sub_080C8068(7,2,1,arg0 * 0xc0000 + 0x60000 >> 0x10);
    sub_080C8104(7,0,1,local_2c + 4U & 0xffff);
  }
  return;
}


// sub_080C8440 @ 0x080C8440

void sub_080C8440(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200e8d8;
  REG_DMA3DAD = 0x6012000;
  REG_DMA3CNT = 0x840003c0;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C8464 @ 0x080C8464

void sub_080C8464(uint arg0,undefined4 arg1)

{
  *(undefined2 *)(&DAT_0200e834 + ((int)(arg0 << 0x10) >> 0xf)) = (undefined2)arg1;
  sub_080C6F30(arg0 & 0xffff);
  return;
}


// sub_080C8480 @ 0x080C8480

void sub_080C8480(undefined4 arg0)

{
  sub_080C8464((int)(short)arg0,1);
  return;
}


// sub_080C8490 @ 0x080C8490

void sub_080C8490(undefined4 arg0)

{
  sub_080C8464((int)(short)arg0,0);
  return;
}


// sub_080C84A0 @ 0x080C84A0

void sub_080C84A0(void)

{
  ushort uVar1;
  
  uVar1 = 0;
  do {
    sub_080C8464((int)(short)uVar1,0);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 6);
  return;
}


// sub_080C84C0 @ 0x080C84C0

void sub_080C84C0(void)

{
  ushort uVar1;
  
  uVar1 = 0;
  do {
    sub_080C8464((int)(short)uVar1,1);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 6);
  return;
}


// sub_080C84E0 @ 0x080C84E0

undefined4 sub_080C84E0(undefined4 arg0)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = sub_080C0148((uint)(ushort)arg0);
  if (iVar2 == 0) {
LAB_080c861c:
    uVar3 = 0;
  }
  else {
    uVar1 = *(ushort *)(iVar2 + 0x10);
    if ((char)(&DAT_030050e0)[(short)(ushort)arg0] < '\x10') {
      if ((uVar1 & 0x8000) != 0) {
        return 1;
      }
LAB_080c852e:
      iVar4 = (char)(&DAT_030050e0)[(short)(ushort)arg0] * 0x10000 >> 0x10;
      if ((iVar4 < 0x10) ||
         ((int)((uint)*(ushort *)(iVar2 + 0x1a) << 0x10) >> 0x12 <= (int)*(short *)(iVar2 + 0x18)))
      {
        if ((uVar1 & 0x2000) != 0) {
          return 4;
        }
        if ((uVar1 & 0x1000) != 0) {
          return 5;
        }
        if ((uVar1 & 4) != 0) {
          return 0x10;
        }
        if ((uVar1 & 0x800) != 0) {
          return 6;
        }
        if ((uVar1 & 0x400) != 0) {
          return 8;
        }
        if ((uVar1 & 0x4000) != 0) {
          return 3;
        }
        if ((uVar1 & 1) != 0) {
          return 0x12;
        }
        if ((uVar1 & 0x200) != 0) {
          return 9;
        }
        if ((uVar1 & 0x40) != 0) {
          return 0xc;
        }
        if ((uVar1 & 0x20) != 0) {
          return 0xd;
        }
        if ((uVar1 & 0x100) != 0) {
          return 10;
        }
        if ((uVar1 & 0x80) != 0) {
          return 0xb;
        }
        if ((uVar1 & 2) != 0) {
          return 0x11;
        }
        if ((uVar1 & 0x10) != 0) {
          return 0xe;
        }
        if ((uVar1 & 8) != 0) {
          return 0xf;
        }
        if ((0xf < iVar4) ||
           ((int)((uint)*(ushort *)(iVar2 + 0x1a) << 0x10) >> 0x12 <= (int)*(short *)(iVar2 + 0x18))
           ) goto LAB_080c861c;
      }
    }
    else if ((uVar1 & 0x8000) == 0) goto LAB_080c852e;
    uVar3 = 2;
  }
  return uVar3;
}


// sub_080C8624 @ 0x080C8624

undefined4 sub_080C8624(undefined4 arg0)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = sub_080C0148((uint)(ushort)arg0);
  if ((iVar3 != 0) &&
     (uVar1 = *(ushort *)(iVar3 + 0x10),
     uVar4 = sub_080C35E4((int)(char)(&DAT_030050e0)[(short)(ushort)arg0]),
     (uVar1 & (ushort)0xb1e0) == 0)) {
    sVar2 = (short)uVar4;
    if (sVar2 == 4) {
      return 0x13;
    }
    if (sVar2 == 5) {
      return 0x14;
    }
    if (sVar2 == 10) {
      return 0x15;
    }
    if (sVar2 == 6) {
      return 0x1a;
    }
    if (sVar2 == 7) {
      return 0x16;
    }
    if (sVar2 == 8) {
      return 0x1b;
    }
    if (sVar2 == 9) {
      return 0x18;
    }
    if (sVar2 == 0xb) {
      return 0x17;
    }
    if (sVar2 == 0xc) {
      return 0x19;
    }
  }
  return 0xffffffff;
}


// sub_080C86B4 @ 0x080C86B4

int sub_080C86B4(undefined4 arg0)

{
  short sVar1;
  undefined4 uVar2;
  int arg0_00;
  
  arg0_00 = (int)(short)arg0;
  if (*(short *)(&DAT_0200e834 + arg0_00 * 2) != 0) {
    uVar2 = sub_080C8624(arg0_00);
    sVar1 = (short)uVar2;
    if (sVar1 != -1) goto LAB_080c86e6;
  }
  uVar2 = sub_080C84E0(arg0_00);
  sVar1 = (short)uVar2;
LAB_080c86e6:
  return (int)sVar1;
}


// sub_080C86F4 @ 0x080C86F4

void sub_080C86F4(uint arg0)

{
  int iVar1;
  
  iVar1 = (arg0 & 0xffff) * 2;
  *(undefined2 *)(&DAT_0200e81c + iVar1) = 8;
  *(undefined2 *)(&DAT_0200e828 + iVar1) = 0xfffe;
  return;
}


// sub_080C8718 @ 0x080C8718

void sub_080C8718(int arg0)

{
  ushort uVar1;
  
  sub_080ACFA4(3,(uint)*(ushort *)
                        ((uint)*(ushort *)(arg0 + 0x26) * 0x20 + (*(ushort *)(arg0 + 0x28) + 1) * 2
                        + 0x81b70d0),0x3002fd2,2);
  sub_080AABB0();
  uVar1 = *(short *)(arg0 + 0x28) + 2;
  *(ushort *)(arg0 + 0x28) = uVar1;
  *(ushort *)(arg0 + 0x1c) = (ushort)(0xe < uVar1);
  return;
}


// sub_080C876C @ 0x080C876C

void sub_080C876C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x81b3f10;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C8790 @ 0x080C8790

void sub_080C8790(undefined4 arg0)

{
  DisplayList_Add(0x80c876d,1);
  sub_080C8718(arg0);
  return;
}


// sub_080C87AC @ 0x080C87AC

void sub_080C87AC(int arg0)

{
  short sVar1;
  dword arg0_00;
  
  sVar1 = *(short *)(arg0 + 0x26);
  if (sVar1 == 0) {
    arg0_00 = 0x80013dc;
  }
  else if (sVar1 == 1) {
    arg0_00 = 0x800143c;
  }
  else {
    if (sVar1 != 2) {
      if (sVar1 != 3) {
        return;
      }
      sub_080AA184(0x8001454,9,0,1);
      return;
    }
    arg0_00 = 0x8001424;
  }
  sub_080AA184(arg0_00,9,0,1);
  return;
}


// sub_080C882C @ 0x080C882C

void sub_080C882C(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (*(byte *)(arg0 + 0x2d) < *(byte *)(arg0 + 0x2c)) {
    *(byte *)(arg0 + 0x2d) = *(byte *)(arg0 + 0x2d) + 1;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    *(undefined1 *)(arg0 + 0x2d) = 0;
    *(undefined1 *)(arg0 + 0x2c) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080c8854. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C8858 @ 0x080C8858

void sub_080C8858(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x834a768,0xffff);
  *(undefined2 *)(iVar1 + 0x24) = (undefined2)arg0;
  *(undefined2 *)(iVar1 + 0x26) = (undefined2)arg1;
  *(undefined1 *)(iVar1 + 0x2c) = (undefined1)arg2;
  *(undefined1 *)(iVar1 + 0x2d) = 0;
  return;
}


// sub_080C8890 @ 0x080C8890

void sub_080C8890(uint arg0,uint arg1)

{
  sub_080C8858(arg0 & 0xffff,0,arg1 & 0xff);
  return;
}


// sub_080C88A8 @ 0x080C88A8

void sub_080C88A8(uint arg0,uint arg1)

{
  sub_080C8858(arg0 & 0xffff,1,arg1 & 0xff);
  return;
}


// sub_080C88C0 @ 0x080C88C0

void sub_080C88C0(uint arg0,uint arg1)

{
  sub_080C8858(arg0 & 0xffff,2,arg1 & 0xff);
  return;
}


// sub_080C88D8 @ 0x080C88D8

uint sub_080C88D8(uint arg0,uint arg1)

{
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  sub_080C8858(arg0_00,3,arg1 & 0xff);
  return arg0_00;
}


// sub_080C88F0 @ 0x080C88F0

uint sub_080C88F0(short *arg0)

{
  return (uint)(*arg0 == 0);
}


// sub_080C8904 @ 0x080C8904

void sub_080C8904(int arg0)

{
  if (*(short *)(arg0 + 0x26) == 0) {
    sub_080AA184(0x80013f4,9,0,1);
    sub_080AA184(0x80013dc,9,2,1);
  }
  else {
    sub_080AA184(0x800140c,9,0,1);
    sub_080AA184(0x80013dc,9,4,1);
  }
  return;
}


// sub_080C89A0 @ 0x080C89A0

void sub_080C89A0(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = DAT_030031b8;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (*(short *)(arg0 + 0x2a) != 0) goto LAB_080c8a70;
  if ((uVar2 & 1) != 0) {
    DAT_030037f0 = (uint)*(ushort *)(arg0 + 0x24);
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  uVar1 = 2;
  if ((uVar2 & 2) != 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    goto LAB_080c8a70;
  }
  if ((uVar2 & 0x10) == 0) {
    uVar1 = 0x20;
    if ((uVar2 & 0x20) == 0) {
      if ((uVar2 & 0x80) == 0) {
        if ((uVar2 & 0x40) == 0) goto LAB_080c8a70;
        sVar3 = *(short *)(arg0 + 0x24);
        if (sVar3 == 0) {
          sVar3 = 3;
        }
        else if (sVar3 == 1) {
          sVar3 = 4;
        }
        else if (sVar3 == 2) {
          sVar3 = 5;
        }
        else {
          sVar3 = sVar3 + -3;
        }
      }
      else {
        sVar3 = *(short *)(arg0 + 0x24);
        if (sVar3 == 3) goto LAB_080c8a30;
        if (sVar3 == 4) {
          *(undefined2 *)(arg0 + 0x24) = 1;
          goto LAB_080c8a70;
        }
        if (sVar3 == 5) goto LAB_080c8a40;
        sVar3 = sVar3 + 3;
      }
    }
    else {
      sVar3 = *(short *)(arg0 + 0x24);
      if (sVar3 == 0) {
LAB_080c8a40:
        *(undefined2 *)(arg0 + 0x24) = 2;
        goto LAB_080c8a70;
      }
      if (sVar3 == 3) {
        sVar3 = 5;
      }
      else {
        sVar3 = sVar3 + -1;
      }
    }
  }
  else {
    sVar3 = *(short *)(arg0 + 0x24);
    if (sVar3 == 2) {
LAB_080c8a30:
      *(ushort *)(arg0 + 0x24) = uVar2 & uVar1;
      goto LAB_080c8a70;
    }
    if (sVar3 == 5) {
      sVar3 = 3;
    }
    else {
      sVar3 = sVar3 + 1;
    }
  }
  *(short *)(arg0 + 0x24) = sVar3;
LAB_080c8a70:
                    /* WARNING: Could not recover jumptable at 0x080c8a74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C8A78 @ 0x080C8A78

void sub_080C8A78(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x834a7c4,0xffff);
  *(undefined2 *)(iVar1 + 0x26) = (undefined2)arg1;
  *(undefined2 *)(iVar1 + 0x24) = (undefined2)arg2;
  *(undefined2 *)(iVar1 + 0x2a) = (undefined2)arg0;
  return;
}


// sub_080C8AAC @ 0x080C8AAC

uint sub_080C8AAC(uint arg0,uint arg1)

{
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  sub_080C8A78(arg0_00,0,arg1 & 0xffff);
  return arg0_00;
}


// sub_080C8AC4 @ 0x080C8AC4

uint sub_080C8AC4(uint arg0,uint arg1)

{
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  sub_080C8A78(arg0_00,1,arg1 & 0xffff);
  return arg0_00;
}


// sub_080C8ADC @ 0x080C8ADC

void sub_080C8ADC(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x1e) = (undefined2)arg1;
  return;
}


// sub_080C8AE0 @ 0x080C8AE0

void sub_080C8AE0(short *arg0)

{
  return;
}


// sub_080C8AF4 @ 0x080C8AF4

uint sub_080C8AF4(int arg0)

{
  return (uint)*(ushort *)(arg0 + 0x24);
}


// sub_080C8AF8 @ 0x080C8AF8

undefined4 sub_080C8AF8(void)

{
  return 1;
}


// sub_080C8B10 @ 0x080C8B10

int sub_080C8B10(uint arg0,uint arg1)

{
  int iVar1;
  
  iVar1 = *(int *)((arg0 & 0xffff) * 0x18 + 0x84ed59c);
  if (iVar1 != 0) {
    iVar1 = iVar1 + (arg1 & 0xffff) * 0x268;
  }
  return iVar1;
}


// sub_080C8B3C @ 0x080C8B3C

undefined4 sub_080C8B3C(uint arg0)

{
  return *(undefined4 *)(&DAT_084ed5a0 + (arg0 & 0xffff) * 0x18);
}


// sub_080C8B54 @ 0x080C8B54

short * sub_080C8B54(uint arg0)

{
  short *psVar1;
  
  psVar1 = (short *)((arg0 & 0xffff) * 0x18 + 0x84ed5a4);
  if (*psVar1 == 0) {
    psVar1 = (short *)0x0;
  }
  return psVar1;
}


// MarkerHeader_DrawLocationName @ 0x080C8B7C

void MarkerHeader_DrawLocationName(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  ushort *puVar1;
  uint uVar2;
  uint in_stack_00000000;
  
  puVar1 = (ushort *)
           Location_GetNameCellFromCoords
                     ((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514,(uint)DAT_03004562,
                      (uint)DAT_03004564);
  uVar2 = 0;
  do {
    if (*puVar1 == 0x57) {
      return;
    }
    FontSprite_DrawGlyph((uint)*puVar1,arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff);
    puVar1 = puVar1 + 1;
    arg2 = (arg2 & 0xffff) + (in_stack_00000000 & 0xffff);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x10);
  return;
}


// MarkerList_DrawLocationName @ 0x080C8BFC

void MarkerList_DrawLocationName(uint arg0,uint arg1,uint arg2,uint arg3)

{
  ushort *puVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000000;
  uint in_stack_00000004;
  uint in_stack_00000008;
  
  puVar1 = (ushort *)
           Location_GetNameCellFromCoords(arg0 & 0xffff,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  uVar2 = 0;
  do {
    if (*puVar1 == 0x57) break;
    FontSprite_DrawGlyph
              ((uint)*puVar1,in_stack_00000000 & 0xffff,in_stack_00000004 & 0xffff,
               in_stack_00000008 & 0xffff);
    puVar1 = puVar1 + 1;
    in_stack_00000008 = (in_stack_00000008 & 0xffff) + 0xc;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x10);
                    /* WARNING: Could not recover jumptable at 0x080c8c74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C8C78 @ 0x080C8C78

void sub_080C8C78(void)

{
  DAT_030029b0 = *DAT_03004630;
  sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
  sub_080ACFCC(3,DAT_03004510,&DAT_03002b50,0x20);
  sub_080AAE9C(0x203a3e8,0xd0,0x30,3);
  DAT_0203a3ea = 0x20;
  return;
}


// sub_080C8CD4 @ 0x080C8CD4

void sub_080C8CD4(int arg0)

{
  int arg1;
  
  arg1 = DAT_03004630 + arg0 * 0x40;
  sub_080ACFCC(3,DAT_03004510 + arg0 * 0x20,0x3002b50,0x20);
  sub_080ACFCC(3,arg1,&DAT_03002b70,0x40);
  sub_080AAE9C(0x203a3e8,0xd0,0x30,3);
  DAT_0203a3ea = 0x20;
  return;
}


// sub_080C8D30 @ 0x080C8D30

void sub_080C8D30(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = sub_080AB184();
  if ((((uVar1 & 0xffff) != 0) && ((DAT_0200ab04 & 0x8000) == 0)) &&
     (iVar2 = sub_080B098C(), iVar2 != 1)) {
    if (DAT_0203a3e8 == 0) {
      switch(DAT_030045b4) {
      case 0:
        sub_080C8C78();
        DAT_030045b4 = DAT_030045b4 + 1;
        break;
      case 1:
        sub_080C8CD4(0);
        DAT_030045b4 = DAT_030045b4 + 1;
        break;
      case 2:
        sub_080C8C78();
        DAT_030045b4 = DAT_030045b4 + 1;
        break;
      case 3:
        sub_080C8CD4(1);
        DAT_030045b4 = DAT_030045b4 + 1;
        break;
      case 4:
        sub_080C8C78();
        DAT_030045b4 = DAT_030045b4 + 1;
        break;
      case 5:
        sub_080C8CD4(2);
        DAT_030045b4 = DAT_030045b4 + 1;
        break;
      case 6:
        sub_080C8C78();
        DAT_030045b4 = DAT_030045b4 + 1;
        break;
      case 7:
        sub_080C8CD4(3);
        DAT_030045b4 = 0;
      }
    }
    else {
      sub_080AAD1C(0x203a3e8);
    }
  }
  return;
}


// sub_080C8E00 @ 0x080C8E00

void sub_080C8E00(void)

{
  sub_080C2364(0x108);
  return;
}


// sub_080C8E10 @ 0x080C8E10

void sub_080C8E10(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 | 2;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 | 0x10;
  return;
}


// sub_080C8E30 @ 0x080C8E30

void sub_080C8E30(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 & 0xfffd;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 & 0xffef;
  DAT_030020f4 = 0x80a9971;
  return;
}


// sub_080C8E64 @ 0x080C8E64

void sub_080C8E64(void)

{
  uint uVar1;
  
  uVar1 = sub_080C2244();
  if ((uVar1 & 1) == 0) {
    DAT_050001a2 = DAT_03002f52;
    DAT_050001a4 = DAT_03002f54;
    DAT_050001a6 = DAT_03002f56;
    DAT_050001a8 = DAT_03002f58;
    DAT_050001aa = DAT_03002f5a;
    DAT_050001ac = DAT_03002f5c;
    DAT_050001ae = DAT_03002f5e;
    DAT_050001b0 = DAT_03002f60;
    DAT_050001b2 = DAT_03002f62;
    DAT_050001b4 = DAT_03002f64;
    DAT_050001b6 = DAT_03002f66;
    DAT_050001b8 = DAT_03002f68;
    DAT_050001ba = DAT_03002f6a;
    DAT_050001bc = DAT_03002f6c;
    DAT_050001be = DAT_03002f6e;
    DAT_050001c0 = DAT_03002f70;
  }
  else {
    DAT_050001a2 = 0;
    DAT_050001a4 = 0x7fff;
    DAT_050001a6 = 0x7fdd;
    DAT_050001a8 = 0x7b9a;
    DAT_050001aa = 0x7779;
    DAT_050001ac = 0x6b36;
    DAT_050001ae = 0x62b3;
    DAT_050001b0 = 0x5671;
    DAT_050001b2 = 0x49ee;
    DAT_050001b4 = 0x398b;
    DAT_050001b6 = 0x6b16;
    DAT_050001b8 = 0x5ed3;
    DAT_050001ba = 0x4e4f;
    DAT_050001bc = 0x460d;
    DAT_050001be = 0x39cc;
    DAT_050001c0 = 0x318a;
  }
  return;
}


// sub_080C8F84 @ 0x080C8F84

void sub_080C8F84(void)

{
  DAT_030020f4 = 0x80c8e65;
  sub_080A9C64(0x80c8e11,1);
  sub_080AABB0();
  return;
}


// sub_080C8FA8 @ 0x080C8FA8

void sub_080C8FA8(void)

{
  sub_080A9C64(0x80c8e31,1);
  sub_080AABB0();
  return;
}


// sub_080C8FC0 @ 0x080C8FC0

void sub_080C8FC0(void)

{
  DAT_030029b0 = *DAT_03004630;
  sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
  sub_080ACFCC(3,DAT_03004510,&DAT_03002b50,0x20);
  sub_080AAE9C(0x203a3e8,0xd0,0x30,8);
  DAT_0203a3ea = 0x20;
  return;
}


// sub_080C901C @ 0x080C901C

void sub_080C901C(uint arg0)

{
  int arg1;
  
  arg1 = DAT_03004630 + (arg0 & 0xffff) * 0x40;
  sub_080ACFCC(3,DAT_03004510 + (arg0 & 0xffff) * 0x20,0x3002b50,0x20);
  sub_080ACFCC(3,arg1,&DAT_03002b70,0x40);
  sub_080AAE9C(0x203a3e8,0xd0,0x30,3);
  DAT_0203a3ea = 0x20;
  return;
}


// sub_080C907C @ 0x080C907C

void sub_080C907C(void)

{
  return;
}


// sub_080C9080 @ 0x080C9080

void sub_080C9080(void)

{
  return;
}


// sub_080C9084 @ 0x080C9084

undefined4 sub_080C9084(uint arg0,uint arg1,uint arg2,short *arg3)

{
  short *psVar1;
  short local_18;
  ushort local_16;
  
  psVar1 = (short *)0x84ede54;
  sub_080C1F50(arg0 & 0xffff,arg1 & 0xffff,&local_18,&local_16);
  while( true ) {
    if (*psVar1 == -1) {
      *arg3 = -1;
      return 0;
    }
    if (((*psVar1 == local_18) && ((psVar1[1] & 0x3fU) == local_16)) &&
       (((ushort)psVar1[1] >> 5 & 6) >> 1 == (arg2 & 0xffff))) break;
    psVar1 = psVar1 + 6;
  }
  *arg3 = psVar1[4];
  return psVar1;
}


// sub_080C90F4 @ 0x080C90F4

void sub_080C90F4(void)

{
  return;
}


// sub_080C90F8 @ 0x080C90F8

undefined4 sub_080C90F8(void)

{
  return 1;
}


// sub_080C90FC @ 0x080C90FC

void sub_080C90FC(void)

{
  return;
}


