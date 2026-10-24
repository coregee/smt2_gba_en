/* Ghidra decompilation of asm/code_080EF218.s (reference only; not compiled). */

// sub_080EF218 @ 0x080EF218

void sub_080EF218(void)

{
  undefined4 in_r0;
  
  sub_080EF148(in_r0,1);
  return;
}


// sub_080EF224 @ 0x080EF224

int sub_080EF224(int arg0,int arg1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int arg0_00;
  
  iVar3 = 0;
  arg0_00 = 0x10;
  if (-1 < arg1) {
    sub_08126834(arg1);
  }
  iVar1 = sub_080ED954();
  if ((iVar1 != 0) && (0x13 < arg0)) {
    arg0_00 = 0x14;
  }
  for (iVar1 = arg0_00; iVar1 < arg0_00 + 8; iVar1 = iVar1 + 1) {
    iVar2 = sub_080C0A00(iVar1);
    if (iVar2 == 0) {
      sub_080F44D8(arg0_00,iVar1);
      sub_080C08F8(iVar1,0);
      sub_080C0A7C(iVar1);
      sub_080C0AA8(iVar1);
      iVar3 = 1;
      arg1 = arg1 + -1;
      if (arg1 == 0) break;
    }
  }
  if (iVar3 == 1) {
    sub_080E760C();
  }
  return iVar3;
}


// sub_080EF2A0 @ 0x080EF2A0

void sub_080EF2A0(void)

{
  char cVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    cVar1 = *(char *)(iVar5 + 0x30050e0);
    if (-1 < cVar1) {
      iVar4 = 0;
      puVar3 = (ushort *)0x876f7c6;
      do {
        uVar2 = sub_080C2244();
        if (uVar2 < *puVar3) {
          sub_080C08BC((int)cVar1,(uint)*(ushort *)(iVar4 * 2 + 0x876f7be));
        }
        puVar3 = puVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 6);
  sub_080C08BC(0,0xffbf);
  sub_080C08BC(1,0xffbf);
  iVar5 = 0;
  do {
    iVar4 = 0;
    puVar3 = (ushort *)0x876f7c6;
    do {
      uVar2 = sub_080C2244();
      if (uVar2 < *puVar3) {
        sub_080C08BC(iVar5 + 0x10,(uint)*(ushort *)(iVar4 * 2 + 0x876f7be));
      }
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 8);
  iVar5 = 0;
  do {
    puVar3 = (ushort *)(DAT_03006434 + 0x78 + iVar5 * 2);
    *puVar3 = *puVar3 & 0xffdc;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xe);
  return;
}


// sub_080EF364 @ 0x080EF364

void sub_080EF364(void)

{
  uint uVar1;
  int arg0;
  int iVar2;
  
  iVar2 = 0;
  do {
    arg0 = (int)*(char *)(iVar2 + 0x30050e0);
    if (-1 < arg0) {
      uVar1 = 0x398;
      if (arg0 < 4) {
        uVar1 = 0x3d8;
      }
      sub_080C08BC(arg0,uVar1 ^ 0xffff);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  return;
}


// sub_080EF3A0 @ 0x080EF3A0

void sub_080EF3A0(int arg0)

{
  int iVar1;
  int in_r1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg0 == 0) {
    iVar1 = 0;
  }
  else if (arg0 < 8) {
    iVar1 = arg0 * in_r1;
  }
  else {
    if (in_r1 < 0) {
      in_r1 = in_r1 + 7;
    }
    iVar1 = (arg0 + -7) * (in_r1 >> 3);
  }
                    /* WARNING: Could not recover jumptable at 0x080ef3c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(iVar1);
  return;
}


// sub_080EF3C8 @ 0x080EF3C8

undefined4 sub_080EF3C8(uint arg0)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  iVar2 = sub_080C2340(1);
  if ((((iVar2 == 0) && (iVar2 = sub_080C2340(0xd5), iVar2 == 0)) &&
      (iVar2 = sub_080C2340(0xb7), iVar2 == 0)) &&
     (uVar5 = *(byte *)(iVar1 + 0x19) & 0xf, (*(byte *)(iVar1 + 0x19) & 0xf) != 0)) {
    uVar5 = uVar5 * uVar5 >> 1;
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    uVar3 = sub_080C2244();
    if ((uVar3 & 0xff) < uVar5) {
      uVar5 = (uint)*(byte *)(iVar1 + 0x1a) | (*(byte *)(iVar1 + 0x1f) & 1) << 8;
      goto LAB_080ef42e;
    }
  }
  uVar5 = 0xffffffff;
LAB_080ef42e:
                    /* WARNING: Could not recover jumptable at 0x080ef432. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar5);
  return uVar4;
}


// sub_080EF434 @ 0x080EF434

undefined4 sub_080EF434(uint arg0)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  iVar2 = sub_080C2340(1);
  if ((((iVar2 == 0) && (iVar2 = sub_080C2340(0xd5), iVar2 == 0)) &&
      (iVar2 = sub_080C2340(0xb7), iVar2 == 0)) && ((*(byte *)(iVar1 + 0x1f) & 0xf0) != 0)) {
    uVar3 = (uint)(*(byte *)(iVar1 + 0x1f) >> 4);
    uVar4 = rand();
    uVar4 = __umodsi3(uVar4 & 0xff,0xc0);
    if ((uVar4 & 0xffff) < uVar3 * uVar3 >> 1) {
      uVar5 = 1;
      goto LAB_080ef48e;
    }
  }
  uVar5 = 0;
LAB_080ef48e:
                    /* WARNING: Could not recover jumptable at 0x080ef492. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*UNRECOVERED_JUMPTABLE)(uVar5);
  return uVar5;
}


// sub_080EF494 @ 0x080EF494

undefined4 sub_080EF494(uint arg0,uint arg1)

{
  uint uVar1;
  int iVar2;
  dword dVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar6 = arg0 & 0xffff;
  uVar1 = sub_080ED560(arg1);
  uVar1 = uVar1 & 0xffff;
  iVar2 = sub_080BF648(arg1 & 0xffff);
  uVar5 = (uint)(*(byte *)(iVar2 + 0x19) >> 4);
  if (uVar5 == 0) {
    uVar5 = 0;
    dVar3 = 0;
  }
  else {
    uVar5 = sub_080F030C(uVar5 + uVar1 * 0x100 & 0xffff,(uint)*(byte *)(iVar2 + 0x19));
    uVar5 = uVar5 & 0xffff;
    if (uVar6 < uVar1) {
      for (uVar1 = (uVar1 - uVar6 & 0xffff) >> 2; dVar3 = uVar5, uVar1 != 0;
          uVar1 = uVar1 - 1 & 0xffff) {
        if ((uVar5 & 0x8000) != 0) {
          dVar3 = 0xffff;
          break;
        }
        uVar5 = (uVar5 & 0x7fff) << 1;
      }
    }
    else {
      uVar1 = (uVar6 - uVar1 & 0xffff) >> 2;
      dVar3 = uVar5;
      if (uVar1 != 0) {
        if (0xff < uVar1) {
          uVar1 = 0xff;
        }
        uVar5 = __udivsi3(uVar5,uVar1);
        uVar5 = uVar5 & 0xffff;
        dVar3 = uVar5;
        if (uVar5 == 0) {
          dVar3 = 1;
        }
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080ef536. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(dVar3,UNRECOVERED_JUMPTABLE,uVar5,unaff_r8);
  return uVar4;
}


// sub_080EF538 @ 0x080EF538

undefined4 sub_080EF538(uint arg0)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  iVar2 = sub_080C2340(1);
  if (((iVar2 == 0) && (iVar2 = sub_080C2340(0xd5), iVar2 == 0)) &&
     (iVar2 = sub_080C2340(0xb7), iVar2 == 0)) {
    uVar3 = sub_080F030C((uint)CONCAT11(*(undefined1 *)(iVar1 + 1),*(byte *)(iVar1 + 0x1c) >> 4),
                         (uint)*(byte *)(iVar1 + 0x1c));
    iVar1 = (uVar3 & 0xffff) << 1;
  }
  else {
    iVar1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080ef57c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(iVar1);
  return uVar4;
}


// sub_080EF580 @ 0x080EF580

undefined4 sub_080EF580(uint arg0)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  iVar2 = sub_080C2340(1);
  if ((((iVar2 == 0) && (iVar2 = sub_080C2340(0xd5), iVar2 == 0)) &&
      (iVar2 = sub_080C2340(0xb7), iVar2 == 0)) && (0xb1 < (int)arg0)) {
    uVar3 = sub_080F030C((uint)*(byte *)(iVar1 + 1) << 8 | *(byte *)(iVar1 + 0x1c) & 0xf,
                         (uint)*(byte *)(iVar1 + 0x1c) << 4);
    uVar3 = uVar3 & 0xffff;
  }
  else {
    uVar3 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080ef5ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar3);
  return uVar4;
}


// sub_080EF5D0 @ 0x080EF5D0

void sub_080EF5D0(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg0 != 0xf) {
    sub_080ED3FC(2,arg0);
  }
                    /* WARNING: Could not recover jumptable at 0x080ef5e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EF5E8 @ 0x080EF5E8

void sub_080EF5E8(void)

{
  undefined4 in_r0;
  uint uVar1;
  
  uVar1 = sub_080ED4A8(in_r0);
  sub_080EF5D0(uVar1 & 0xf);
  return;
}


// sub_080EF5FC @ 0x080EF5FC

uint sub_080EF5FC(int arg0,undefined4 arg1)

{
  uint arg0_00;
  uint local_c;
  
  local_c = (uint)*(byte *)(arg0 + 0x5c);
  switch((int)*(char *)(arg0 + 0x17)) {
  case 4:
  case 5:
    local_c = (uint)(*(char *)(arg0 + 0x17) != 4);
    local_c = sub_080C00DC(arg1,local_c);
    sub_080BF468(local_c,4,&local_c);
    arg0_00 = local_c;
    goto LAB_080ef668;
  case 6:
  case 9:
  case 0xc:
switchD_080ef61c_caseD_6:
    arg0_00 = 0xffffffff;
    break;
  case 7:
  case 0xb:
switchD_080ef61c_caseD_7:
    arg0_00 = sub_080ED694(local_c);
    if (0x7f < arg0_00) goto switchD_080ef61c_caseD_6;
LAB_080ef668:
    sub_080EF5D0(arg0_00);
    break;
  case 8:
    if (0x57 < local_c) {
      sub_080BF468(local_c,0xc,&local_c);
      if ((int)local_c < 0) goto switchD_080ef61c_caseD_6;
      if ((local_c == 0x50) || ((int)local_c < 0x40)) goto switchD_080ef61c_caseD_7;
    }
    arg0_00 = 1;
    break;
  case 10:
    arg0_00 = (uint)*(short *)(arg0 + 0x12);
    sub_080EF5E8();
    break;
  default:
    arg0_00 = 0;
  }
  return arg0_00;
}


// sub_080EF6B4 @ 0x080EF6B4

void sub_080EF6B4(int arg0)

{
  int iVar1;
  undefined4 uVar2;
  int arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = 4;
  while ((iVar1 = sub_080C09B0(arg0_00), iVar1 == 0 ||
         (uVar2 = sub_080C07E0(arg0_00), (short)uVar2 != arg0))) {
    arg0_00 = arg0_00 + 1;
    if (0xf < arg0_00) {
LAB_080ef6e2:
                    /* WARNING: Could not recover jumptable at 0x080ef6e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  }
  sub_080C06EC(0,0x19);
  goto LAB_080ef6e2;
}


// sub_080EF6E8 @ 0x080EF6E8

undefined4 sub_080EF6E8(void)

{
  undefined4 in_r0;
  uint uVar1;
  undefined4 uVar2;
  undefined4 in_r1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080F42E0(in_r0,in_r1);
  uVar1 = uVar1 & 0xff;
  if ((uVar1 == 0xff) || (0x5e < (uVar1 - 0x40 & 0xff))) {
    uVar1 = 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x080ef70c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar2;
}


// sub_080EF710 @ 0x080EF710

int sub_080EF710(int arg0)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (arg0 < 4) {
    iVar3 = -1;
  }
  else {
    iVar2 = 0;
    do {
      iVar1 = sub_080EF6E8();
      if (-1 < iVar1) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 7);
  }
  return iVar3;
}


// sub_080EF740 @ 0x080EF740

undefined4 sub_080EF740(undefined4 arg0,undefined4 arg1,dword *arg2)

{
  int iVar1;
  int iVar2;
  dword dVar3;
  uint uVar4;
  
  *arg2 = 0xffffffff;
  switch(arg1) {
  case 4:
    iVar2 = sub_080C00DC(arg0,0);
    if (iVar2 != 0xff) {
      return 1;
    }
    dVar3 = 0x162;
    break;
  case 5:
    iVar2 = sub_080C00DC(arg0,1);
    if (iVar2 != 0xff) {
      iVar1 = sub_080C00DC(arg0,6);
      if (iVar1 != 0xff) {
        return 1;
      }
      if (iVar2 - 0x6dU < 2) {
        return 1;
      }
    }
    dVar3 = 0x162;
    break;
  case 6:
    iVar2 = sub_080C2340(3);
    if (iVar2 != 0) {
      dVar3 = sub_080F3190();
      if (dVar3 == 0) {
        return 1;
      }
      *arg2 = dVar3;
      return 0;
    }
    dVar3 = 0x393;
    break;
  case 7:
    iVar2 = sub_080F4300(arg0,0x20);
    if (iVar2 == 0) {
      dVar3 = 0x8f;
    }
    else {
      uVar4 = sub_080C0818(arg0);
      if ((uVar4 & 0xb063) == 0) {
        return 1;
      }
      dVar3 = 0x90;
    }
    break;
  default:
    return 1;
  case 0xb:
    iVar2 = sub_080EF710(arg0);
    if (iVar2 != 0) {
      return 1;
    }
    dVar3 = 0x165;
  }
  *arg2 = dVar3;
  return 0;
}


// sub_080EF828 @ 0x080EF828

undefined4 sub_080EF828(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = sub_080EF99C();
  if ((uVar1 & 0xffff) == 0) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = 0x14;
  }
  return uVar2;
}


// sub_080EF840 @ 0x080EF840

void sub_080EF840(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080EF828();
  iVar2 = sub_080ED954();
  iVar5 = 8;
  if (iVar2 != 0) {
    iVar5 = 4;
  }
  iVar4 = 0;
  iVar2 = iVar1;
  if (iVar5 != 0) {
    do {
      iVar2 = iVar1 + iVar4;
      iVar3 = sub_080C09B0(iVar2);
      if (iVar3 != 0) break;
      iVar4 = iVar4 + 1;
      iVar2 = iVar1;
    } while (iVar4 < iVar5);
  }
                    /* WARNING: Could not recover jumptable at 0x080ef876. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(iVar2);
  return;
}


// sub_080EF878 @ 0x080EF878

int sub_080EF878(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = sub_080EF828();
  iVar2 = sub_080ED954();
  iVar4 = 8;
  if (iVar2 != 0) {
    iVar4 = 4;
  }
  iVar2 = 0;
  if (iVar4 != 0) {
    do {
      iVar3 = sub_080C09B0(iVar1 + iVar2);
      if ((iVar3 != 0) && (iVar3 = sub_080C0830(), iVar3 == 0)) {
        return iVar1 + iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar4);
  }
  return iVar1;
}


// sub_080EF8BC @ 0x080EF8BC

void sub_080EF8BC(undefined4 arg0)

{
  *(undefined2 *)(DAT_03006434 + 0x120) = (undefined2)arg0;
  return;
}


// sub_080EF8D0 @ 0x080EF8D0

int sub_080EF8D0(void)

{
  return (int)*(short *)(DAT_03006434 + 0x120);
}


// sub_080EF8E4 @ 0x080EF8E4

void sub_080EF8E4(void)

{
  return;
}


// sub_080EF8F8 @ 0x080EF8F8

void sub_080EF8F8(undefined4 arg0)

{
  *(undefined2 *)(DAT_03006434 + 0x124) = (undefined2)arg0;
  return;
}


// sub_080EF90C @ 0x080EF90C

int sub_080EF90C(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_03006434;
  iVar2 = sub_080EF99C();
  return (int)*(short *)(iVar1 + 0x128 + ((iVar2 << 0x10) >> 0xf));
}


// sub_080EF930 @ 0x080EF930

void sub_080EF930(undefined4 arg0)

{
  int iVar1;
  
  iVar1 = sub_080EF99C();
  *(undefined2 *)(DAT_03006434 + 0x128 + ((iVar1 << 0x10) >> 0xf)) = (undefined2)arg0;
  return;
}


// sub_080EF954 @ 0x080EF954

int sub_080EF954(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_03006434;
  iVar2 = sub_080EF99C();
  return (int)*(short *)(iVar1 + 300 + ((iVar2 << 0x10) >> 0xf));
}


// sub_080EF978 @ 0x080EF978

void sub_080EF978(undefined4 arg0)

{
  int iVar1;
  
  iVar1 = sub_080EF99C();
  *(undefined2 *)(DAT_03006434 + 300 + ((iVar1 << 0x10) >> 0xf)) = (undefined2)arg0;
  return;
}


// sub_080EF99C @ 0x080EF99C

int sub_080EF99C(void)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = sub_080ED954();
  if (iVar2 != 0) {
    if ((*(short *)(DAT_03006434 + 0x122) == 0) && (DAT_0203cb90 != DAT_0203db7c)) {
      uVar1 = 1;
    }
    else {
      if ((*(short *)(DAT_03006434 + 0x122) != 1) || (DAT_0203cb94 == DAT_0203db7c))
      goto LAB_080efa00;
      uVar1 = 0;
    }
    *(undefined2 *)(DAT_03006434 + 0x122) = uVar1;
  }
LAB_080efa00:
  return (int)*(short *)(DAT_03006434 + 0x122);
}


// sub_080EFA20 @ 0x080EFA20

void sub_080EFA20(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080EF90C();
  iVar1 = iVar1 + arg0;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0x1f < iVar1) {
    iVar1 = 0x1f;
  }
  sub_080EF930(iVar1);
                    /* WARNING: Could not recover jumptable at 0x080efa40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EFA44 @ 0x080EFA44

void sub_080EFA44(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080EF954();
  iVar1 = iVar1 + arg0;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0x1f < iVar1) {
    iVar1 = 0x1f;
  }
  sub_080EF978(iVar1);
                    /* WARNING: Could not recover jumptable at 0x080efa64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EFA68 @ 0x080EFA68

void sub_080EFA68(undefined4 arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080EF8D0();
  if (iVar1 == 0) {
    sub_080EFA20(arg0);
  }
  else {
    sub_080EFA44(arg0);
  }
                    /* WARNING: Could not recover jumptable at 0x080efa86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080EFA88 @ 0x080EFA88

void sub_080EFA88(undefined4 arg0)

{
  *(undefined2 *)(DAT_03006434 + 0x126) = (undefined2)arg0;
  return;
}


// sub_080EFA9C @ 0x080EFA9C

int sub_080EFA9C(void)

{
  return (int)*(short *)(DAT_03006434 + 0x126);
}


// sub_080EFAB0 @ 0x080EFAB0

int sub_080EFAB0(void)

{
  int iVar1;
  undefined4 in_r0;
  int iVar2;
  
  iVar1 = DAT_03006434;
  iVar2 = sub_080ED8C0(in_r0);
  return (int)*(short *)(iVar1 + 0x78 + iVar2 * 2);
}


// sub_080EFAD0 @ 0x080EFAD0

void sub_080EFAD0(int arg0,undefined4 arg1)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = DAT_03006434;
  if (arg0 < 0x10) {
    *(ushort *)(DAT_03006434 + 0x78) = (ushort)arg1 | *(ushort *)(DAT_03006434 + 0x78);
    *(ushort *)(iVar1 + 0x7a) = (ushort)arg1 | *(ushort *)(iVar1 + 0x7a);
    *(ushort *)(iVar1 + 0x7c) = (ushort)arg1 | *(ushort *)(iVar1 + 0x7c);
    *(ushort *)(iVar1 + 0x7e) = (ushort)arg1 | *(ushort *)(iVar1 + 0x7e);
    *(ushort *)(iVar1 + 0x80) = (ushort)arg1 | *(ushort *)(iVar1 + 0x80);
    puVar2 = (ushort *)(iVar1 + 0x82);
  }
  else {
    *(ushort *)(DAT_03006434 + 0x84) = (ushort)arg1 | *(ushort *)(DAT_03006434 + 0x84);
    *(ushort *)(iVar1 + 0x86) = (ushort)arg1 | *(ushort *)(iVar1 + 0x86);
    *(ushort *)(iVar1 + 0x88) = (ushort)arg1 | *(ushort *)(iVar1 + 0x88);
    *(ushort *)(iVar1 + 0x8a) = (ushort)arg1 | *(ushort *)(iVar1 + 0x8a);
    *(ushort *)(iVar1 + 0x8c) = (ushort)arg1 | *(ushort *)(iVar1 + 0x8c);
    *(ushort *)(iVar1 + 0x8e) = (ushort)arg1 | *(ushort *)(iVar1 + 0x8e);
    *(ushort *)(iVar1 + 0x90) = (ushort)arg1 | *(ushort *)(iVar1 + 0x90);
    puVar2 = (ushort *)(iVar1 + 0x92);
  }
  *puVar2 = (ushort)arg1 | *puVar2;
  return;
}


// sub_080EFB8C @ 0x080EFB8C

void sub_080EFB8C(int arg0,undefined4 arg1)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = DAT_03006434;
  if (arg0 < 0x10) {
    puVar2 = (ushort *)(DAT_03006434 + 0x78);
  }
  else {
    *(ushort *)(DAT_03006434 + 0x84) = *(ushort *)(DAT_03006434 + 0x84) & (ushort)arg1;
    puVar2 = (ushort *)(iVar1 + 0x86);
    *puVar2 = *puVar2 & (ushort)arg1;
    puVar2 = (ushort *)(iVar1 + 0x88);
  }
  *puVar2 = *puVar2 & (ushort)arg1;
  puVar2[1] = puVar2[1] & (ushort)arg1;
  puVar2[2] = puVar2[2] & (ushort)arg1;
  puVar2[3] = puVar2[3] & (ushort)arg1;
  puVar2[4] = puVar2[4] & (ushort)arg1;
  puVar2[5] = puVar2[5] & (ushort)arg1;
  return;
}


// sub_080EFBFC @ 0x080EFBFC

int sub_080EFBFC(void)

{
  int iVar1;
  undefined4 in_r0;
  int iVar2;
  
  iVar1 = DAT_03006434;
  iVar2 = sub_080ED8C0(in_r0);
  return (int)*(short *)(iVar1 + 0x94 + iVar2 * 2);
}


// sub_080EFC1C @ 0x080EFC1C

uint sub_080EFC1C(int arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = sub_080ED8C0(arg1);
  psVar4 = (short *)(DAT_03006434 + 0x78 + iVar1 * 2 + arg0 * 0x1c);
  *psVar4 = *psVar4 + (short)arg2;
  iVar3 = (int)*(char *)(arg0 * 2 + 0x876f7ce);
  iVar2 = (int)(char)(&DAT_0876f7cf)[arg0 * 2];
  iVar5 = (int)*psVar4;
  if (iVar5 < iVar3) {
    uVar6 = 1;
  }
  else {
    iVar3 = iVar5;
    if (iVar2 < iVar5) {
      iVar3 = iVar2;
    }
    uVar6 = (uint)(iVar2 < iVar5);
    if (uVar6 == 0) {
      return 0;
    }
  }
  *(short *)(DAT_03006434 + 0x78 + iVar1 * 2 + arg0 * 0x1c) = (short)iVar3;
  return uVar6;
}


// sub_080EFC9C @ 0x080EFC9C

void sub_080EFC9C(undefined4 arg0,int arg1,undefined4 arg2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  bVar1 = false;
  if (arg1 < 0x10) {
    iVar3 = 0;
    do {
      if ((*(char *)(iVar3 + 0x30050e0) != -1) &&
         (iVar2 = sub_080EFC1C(arg0,(int)*(char *)(iVar3 + 0x30050e0),arg2), iVar2 == 0)) {
        bVar1 = true;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
  }
  else {
    iVar3 = 0;
    do {
      iVar2 = sub_080EFC1C(arg0,iVar3 + 0x10,arg2);
      if (iVar2 == 0) {
        bVar1 = true;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
  }
                    /* WARNING: Could not recover jumptable at 0x080efd12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(!bVar1);
  return;
}


// sub_080EFD14 @ 0x080EFD14

void sub_080EFD14(undefined4 arg0,undefined4 arg1)

{
  sub_080EFC9C(1,arg0,arg1);
  return;
}


// sub_080EFD28 @ 0x080EFD28

void sub_080EFD28(undefined4 arg0,undefined4 arg1)

{
  sub_080EFC1C(1,arg0,arg1);
  return;
}


// sub_080EFD3C @ 0x080EFD3C

int sub_080EFD3C(void)

{
  int iVar1;
  undefined4 in_r0;
  int iVar2;
  
  iVar1 = DAT_03006434;
  iVar2 = sub_080ED8C0(in_r0);
  return (int)*(short *)(iVar1 + 0xb0 + iVar2 * 2);
}


// sub_080EFD5C @ 0x080EFD5C

void sub_080EFD5C(undefined4 arg0,undefined4 arg1)

{
  sub_080EFC9C(2,arg0,arg1);
  return;
}


// sub_080EFD70 @ 0x080EFD70

void sub_080EFD70(undefined4 arg0,undefined4 arg1)

{
  sub_080EFC1C(2,arg0,arg1);
  return;
}


// sub_080EFD84 @ 0x080EFD84

int sub_080EFD84(void)

{
  int iVar1;
  undefined4 in_r0;
  int iVar2;
  
  iVar1 = DAT_03006434;
  iVar2 = sub_080ED8C0(in_r0);
  return (int)*(short *)(iVar1 + 0xcc + iVar2 * 2);
}


// sub_080EFDA4 @ 0x080EFDA4

void sub_080EFDA4(undefined4 arg0,undefined4 arg1)

{
  sub_080EFC9C(3,arg0,arg1);
  return;
}


// sub_080EFDB8 @ 0x080EFDB8

void sub_080EFDB8(undefined4 arg0,undefined4 arg1)

{
  sub_080EFC1C(3,arg0,arg1);
  return;
}


// sub_080EFDCC @ 0x080EFDCC

int sub_080EFDCC(void)

{
  int iVar1;
  undefined4 in_r0;
  int iVar2;
  
  iVar1 = DAT_03006434;
  iVar2 = sub_080ED8C0(in_r0);
  return (int)*(short *)(iVar1 + 0xe8 + iVar2 * 2);
}


// sub_080EFDEC @ 0x080EFDEC

void sub_080EFDEC(undefined4 arg0,undefined4 arg1)

{
  sub_080EFC9C(4,arg0,arg1);
  return;
}


// sub_080EFE00 @ 0x080EFE00

void sub_080EFE00(undefined4 arg0,undefined4 arg1)

{
  sub_080EFC1C(4,arg0,arg1);
  return;
}


// sub_080EFE14 @ 0x080EFE14

void sub_080EFE14(void)

{
  undefined4 in_r0;
  
  sub_080ED8C0(in_r0);
  return;
}


// sub_080EFE38 @ 0x080EFE38

void sub_080EFE38(undefined4 arg0,undefined4 arg1)

{
  sub_080EFC9C(5,arg0,arg1);
  return;
}


// sub_080EFE4C @ 0x080EFE4C

void sub_080EFE4C(undefined4 arg0,undefined4 arg1)

{
  sub_080EFC1C(5,arg0,arg1);
  return;
}


// sub_080EFE60 @ 0x080EFE60

dword sub_080EFE60(undefined4 arg0)

{
  undefined4 uVar1;
  dword dVar2;
  int local_c;
  
  uVar1 = sub_080C35E4(arg0);
  switch(uVar1) {
  default:
    dVar2 = 0;
    break;
  case 5:
    dVar2 = 1;
    break;
  case 7:
  case 0xb:
    local_c = sub_080F3F14(arg0);
LAB_080efeae:
    dVar2 = sub_080ED6A4(local_c);
    break;
  case 8:
    uVar1 = sub_080F3F14(arg0);
    sub_080BF468(uVar1,0xc,&local_c);
    if (local_c < 0x80) goto LAB_080efeae;
  case 6:
  case 9:
  case 0xc:
    dVar2 = 0xffff;
  }
  return dVar2;
}


// sub_080EFEDC @ 0x080EFEDC

undefined4 sub_080EFEDC(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = sub_080C07E0(0x10);
  if ((((((uVar1 & 0xffff) == 0x12d) || (uVar1 = sub_080C07E0(0x10), (uVar1 & 0xffff) == 0x10f)) ||
       (uVar1 = sub_080C07E0(0x10), (uVar1 & 0xffff) == 0x110)) ||
      ((((uVar1 = sub_080C07E0(0x10), (uVar1 & 0xffff) == 0x111 ||
         (uVar1 = sub_080C07E0(0x10), (uVar1 & 0xffff) == 0x12e)) ||
        ((uVar1 = sub_080C07E0(0x10), (uVar1 & 0xffff) == 0x12f ||
         ((uVar1 = sub_080C07E0(0x10), (uVar1 & 0xffff) == 0x127 ||
          (uVar1 = sub_080C07E0(0x10), (uVar1 & 0xffff) == 0x128)))))) ||
       (uVar1 = sub_080C07E0(0x10), (uVar1 & 0xffff) == 300)))) ||
     (((uVar1 = sub_080C07E0(0x10), (uVar1 & 0xffff) == 0x129 ||
       (uVar1 = sub_080C07E0(0x10), (uVar1 & 0xffff) == 0x12a)) ||
      (uVar1 = sub_080C07E0(0x10), (uVar1 & 0xffff) == 299)))) {
    uVar2 = 0x1b;
  }
  else {
    iVar3 = sub_080EDAD0();
    if (iVar3 == 0) {
      uVar2 = 10;
    }
    else {
      uVar2 = 0x13;
    }
  }
  return uVar2;
}


// sub_080EFFC4 @ 0x080EFFC4

int sub_080EFFC4(int arg0)

{
  return (int)*(short *)(DAT_03006434 + ((arg0 << 0x10) >> 0xe) + 0xc);
}


// sub_080EFFD8 @ 0x080EFFD8

undefined4 sub_080EFFD8(undefined4 arg0,int arg1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((((short)arg0 == 7) || ((short)arg0 == 8)) || (((short)arg0 == 0xb && (arg1 < 0x68)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080efff6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar1;
}


// sub_080EFFF8 @ 0x080EFFF8

int sub_080EFFF8(int arg0,int arg1)

{
  undefined4 uVar1;
  undefined4 arg1_00;
  int iVar2;
  
  if (*(short *)(DAT_03006434 + ((arg1 << 0x10) >> 0xe) + 0x130) != -1) {
    uVar1 = sub_080C35E4(arg0);
    arg1_00 = sub_080F3F14(arg0);
    iVar2 = sub_080EFFD8((int)(short)uVar1,arg1_00);
    if (iVar2 == 1) {
      if (arg0 < 0x10) {
        if ((DAT_0203d3ae != -1) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
          return (int)DAT_0203d3ae;
        }
      }
      else if (((DAT_0203d3ac != 0xffff) && (iVar2 = sub_080C0830(), iVar2 == 0)) &&
              (iVar2 = sub_080C0148(DAT_0203d3ac + 0x8000 & 0xffff),
              *(short *)(iVar2 + 0xe) == -0x4000)) {
        return (int)(short)DAT_0203d3ac;
      }
    }
  }
  return (int)*(short *)(DAT_03006434 + ((arg1 << 0x10) >> 0xe) + 0x130);
}


// sub_080F00D4 @ 0x080F00D4

void sub_080F00D4(void)

{
  return;
}


// sub_080F00E8 @ 0x080F00E8

void sub_080F00E8(undefined4 arg0)

{
  *(undefined4 *)(DAT_03006434 + 0x15c) = arg0;
  return;
}


// sub_080F00FC @ 0x080F00FC

void sub_080F00FC(undefined4 arg0)

{
  *DAT_03006434 = *DAT_03006434 & ~(ushort)arg0;
  return;
}


// sub_080F0110 @ 0x080F0110

void sub_080F0110(undefined4 arg0)

{
  *(int *)(DAT_03006434 + 0x4c) = *(int *)(DAT_03006434 + 0x4c) + (int)(short)arg0;
  return;
}


// sub_080F0124 @ 0x080F0124

undefined4 sub_080F0124(void)

{
  return *(undefined4 *)(DAT_03006434 + 0x4c);
}


// sub_080F0130 @ 0x080F0130

void sub_080F0130(undefined4 arg0)

{
  *(int *)(DAT_03006434 + 0x50) = *(int *)(DAT_03006434 + 0x50) + (int)(short)arg0;
  return;
}


// sub_080F0144 @ 0x080F0144

undefined4 sub_080F0144(void)

{
  return *(undefined4 *)(DAT_03006434 + 0x50);
}


// sub_080F0150 @ 0x080F0150

void sub_080F0150(undefined4 arg0)

{
  *(short *)(DAT_03006434 + 0x54) = (short)arg0 + *(short *)(DAT_03006434 + 0x54);
  return;
}


// sub_080F0168 @ 0x080F0168

int sub_080F0168(void)

{
  return (int)*(short *)(DAT_03006434 + 0x54);
}


// sub_080F0178 @ 0x080F0178

void sub_080F0178(int arg0,undefined4 arg1)

{
  int *piVar1;
  
  piVar1 = (int *)(DAT_03006434 + 0x68 + arg0 * 4);
  *piVar1 = *piVar1 + (int)(short)arg1;
  return;
}


// sub_080F0194 @ 0x080F0194

undefined4 sub_080F0194(int arg0)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = sub_080C2340(0xd5);
  if (((iVar1 == 0) && (iVar1 = sub_080C2340(0xb7), iVar1 == 0)) &&
     (uVar2 = sub_080C0818(arg0), (uVar2 & 0x800) == 0)) {
    uVar3 = *(undefined4 *)(DAT_03006434 + 0x68 + arg0 * 4);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// sub_080F01D8 @ 0x080F01D8

void sub_080F01D8(int arg0,undefined4 arg1)

{
  *(undefined2 *)(DAT_03006434 + 0x56 + arg0 * 2) = (undefined2)arg1;
  return;
}


// sub_080F01EC @ 0x080F01EC

int sub_080F01EC(int arg0)

{
  return (int)*(short *)(DAT_03006434 + 0x56 + arg0 * 2);
}


// sub_080F0200 @ 0x080F0200

void sub_080F0200(int arg0,undefined4 arg1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 local_20;
  
  iVar1 = arg0 * 0x80;
  pcVar2 = (char *)sub_080BF648((uint)(ushort)arg1);
  local_20 = 0;
  CpuSet(&local_20,&DAT_0203cba0 + iVar1,0x5000020);
  (&DAT_0203cbac)[iVar1] = (char)arg0 + '\x10';
  *(ushort *)(&DAT_0203cbb2 + iVar1) = (ushort)arg1;
  (&DAT_0203cbae)[arg0 * 0x40] = 0x8000;
  *(short *)(&DAT_0203cbb4 + iVar1) = (short)*pcVar2;
  (&DAT_0203cbb8)[arg0 * 0x40] = *(undefined2 *)(pcVar2 + 2);
  *(undefined2 *)(&DAT_0203cbba + iVar1) = *(undefined2 *)(pcVar2 + 2);
  *(undefined2 *)(&DAT_0203cbbc + iVar1) = *(undefined2 *)(pcVar2 + 4);
  *(undefined2 *)(&DAT_0203cbbe + iVar1) = *(undefined2 *)(pcVar2 + 4);
  (&DAT_0203cbad)[iVar1] = pcVar2[1];
  *(ushort *)(&DAT_0203cbf8 + iVar1) = (ushort)(byte)pcVar2[0xc] << 8;
  (&DAT_0203cbb7)[iVar1] = 10;
  (&DAT_0203cbb6)[iVar1] = 10;
  (&DAT_0203cbe0)[iVar1] = pcVar2[6];
  (&DAT_0203cbe1)[iVar1] = pcVar2[7];
  (&DAT_0203cbe2)[iVar1] = pcVar2[8];
  (&DAT_0203cbe3)[iVar1] = pcVar2[9];
  (&DAT_0203cbe4)[iVar1] = pcVar2[10];
  (&DAT_0203cbe5)[iVar1] = pcVar2[0xb];
  *(undefined4 *)(&DAT_0203cbc8 + iVar1) = *(undefined4 *)(&DAT_0203cbe0 + iVar1);
  *(undefined4 *)(&DAT_0203cbcc + iVar1) = *(undefined4 *)(&DAT_0203cbe4 + iVar1);
  *(ushort *)(&DAT_0203cbf8 + iVar1) = (ushort)(byte)pcVar2[0xc] << 8;
  iVar3 = 0;
  do {
    (&DAT_0203cbfd)[iVar3 + iVar1] = 0xff;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x20);
  iVar4 = 0;
  iVar3 = 0;
  do {
    (&DAT_0203cbfd)[iVar4 + iVar1] = pcVar2[iVar3 + 0x11];
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 7);
  sub_080C0574((uint)(byte)(&DAT_0203cbad)[iVar1],&DAT_0203cbe0 + iVar1,iVar1 + 0x203cbe8);
  sub_080C0420(pcVar2 + 0x22,&DAT_0203cba0 + iVar1);
  return;
}


// sub_080F030C @ 0x080F030C

int sub_080F030C(uint arg0,uint arg1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = arg0 & 0xf;
  if (7 < uVar2) {
    uVar2 = (arg0 & 7) + 1;
  }
  iVar1 = ((arg0 & 0xffff) >> 8) * uVar2;
  if ((arg1 & 0x80) == 0) {
    iVar1 = iVar1 * 8;
  }
  return iVar1;
}


// sub_080F0344 @ 0x080F0344

void sub_080F0344(undefined4 arg0,undefined4 arg1)

{
  dword dVar1;
  
  if ((ushort)arg0 == 3) {
    dVar1 = 0x97c;
  }
  else {
    if ((ushort)arg0 < 4) {
      return;
    }
    if ((ushort)arg0 != 4) {
      return;
    }
    dVar1 = 0x97e;
  }
  DAT_030000ac = *(undefined2 *)(dVar1 + 0x203c200);
  *(undefined2 *)(dVar1 + 0x203c200) = (undefined2)arg1;
  return;
}


// sub_080F038C @ 0x080F038C

undefined4 sub_080F038C(undefined4 arg0,int arg1)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080F3110((int)(short)arg0);
  uVar1 = uVar1 & 0xffff;
  if ((*(ushort *)(arg1 + 0x10) & 0x200) != 0) {
    uVar1 = (uint)(uVar1 == 0);
  }
  if (uVar1 == 0) {
    sub_080EE2E8((int)(short)arg0);
  }
  else {
    sub_080EE10C((int)(short)arg0);
  }
                    /* WARNING: Could not recover jumptable at 0x080f03d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)((int)(uVar1 * 0x10000) >> 0x10);
  return uVar2;
}


// sub_080F03D8 @ 0x080F03D8

undefined4 sub_080F03D8(undefined4 arg0,int arg1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((char)arg0 == '\v') &&
     (((((((arg1 - 0x4bU < 2 || (arg1 == 0x6d)) || (arg1 == 0x6e)) ||
         ((arg1 == 0x6f || (arg1 == 0x4e)))) ||
        ((arg1 == 0x4f || ((arg1 == 0x71 || (arg1 == 0x74)))))) || (arg1 == 0x7c)) ||
      ((((arg1 == 0x84 || (arg1 == 0x88)) || (arg1 == 0x8a)) ||
       (((arg1 == 0x8d || (arg1 == 0x8e)) || ((arg1 == 0x90 || ((arg1 == 0x91 || (arg1 == 0x92))))))
       )))))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x080f0432. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar1;
}


// sub_080F0434 @ 0x080F0434

undefined4 sub_080F0434(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  dword arg0_00;
  int iVar8;
  uint local_2c;
  
  iVar8 = arg0 * 0x10000 >> 0x10;
  iVar4 = sub_080F2F64(arg0 * 0x10000 + 0x80000000U >> 0x10);
  if (iVar8 < 0x10) {
    local_2c = sub_080C35E4(iVar8);
    local_2c = local_2c & 0xff;
  }
  else {
    local_2c = (uint)*(byte *)(iVar4 + 0x17);
  }
  uVar2 = (ushort)DAT_0300008c;
  sVar3 = (short)arg0;
  switch(DAT_0203cb7c) {
  case 0:
    DAT_0203d166 = 0;
    DAT_0203d3aa = 0;
    DAT_03000080 = 0;
    iVar8 = (int)sVar3;
    uVar5 = sub_080F0C18(iVar4,iVar8);
    if ((short)uVar5 == 1) {
      return 0;
    }
    uVar5 = sub_080EF5FC(iVar4,iVar8);
    *(undefined4 *)(DAT_03006434 + 0x15c) = uVar5;
    uVar5 = sub_080F038C(iVar8,iVar4);
    if (*(char *)(iVar4 + 0x17) != '\t') {
      sub_080F108C(iVar4,iVar8,(int)(short)uVar5);
      return 0;
    }
    goto LAB_080f0a78;
  case 1:
    uVar7 = sub_080EA934();
    if ((uVar7 & 0xff) != 1) {
      return 0;
    }
    if ((DAT_030000aa != 0xff) && (uVar7 = sub_080C2B6C(), (uVar7 & 0xffff) != 1)) {
      sub_080F4608((int)DAT_030000aa,0);
    }
    if (DAT_0203d0c6 == 0xff) {
LAB_080f0760:
      if (DAT_0203d0ca != 0xff) {
        sub_080ECF70((int)DAT_0203d0ca);
      }
    }
    else {
      if ((short)DAT_0203d0c6 < 0xd3) {
        if (DAT_0203d0c6 != 0xff) {
          sub_080F3110((int)sVar3);
          sub_080EC9AC((int)(short)DAT_0203d0c6,(int)DAT_030000a8,(int)DAT_0203d0ca);
          DAT_0203cb7c = 2;
          return 0;
        }
        goto LAB_080f0760;
      }
      uVar5 = sub_080F4490((int)*(short *)(&DAT_0203d130 + ((arg0 << 0x10) >> 0xf)));
      sVar3 = (short)uVar5;
      if (DAT_0203d0ca != 0xff) {
        sub_080ECF70((int)DAT_0203d0ca);
      }
      if ((sVar3 != -1) || (3 < (ushort)(DAT_0203d0c6 - 0xf0))) {
        iVar4 = (arg0 << 0x10) >> 0x10;
        if (*(short *)(&DAT_0203d130 + iVar4 * 2) == -1) {
          uVar5 = sub_080F4490(iVar4);
          sVar3 = (short)uVar5;
        }
        switch((int)((DAT_0203d0c6 - 0xf0) * 0x10000) >> 0x10) {
        case 0:
          sub_080ECE08(4);
          sub_080ECE38((int)sVar3,0,3);
          break;
        case 1:
          sub_080ECE08(4);
          sub_080ECE38((int)sVar3,0,0);
          break;
        case 2:
          sub_080ECE08(4);
          sub_080ECE38((int)sVar3,0,5);
          break;
        case 3:
          sub_080ECE08(4);
          sub_080ECE38((int)sVar3,0,1);
          break;
        case 4:
          sub_080ECE08(5);
          uVar7 = 0;
          do {
            iVar4 = (int)(short)uVar7;
            sub_080ECE38(iVar4,iVar4 << 3,3);
            uVar7 = iVar4 + 1U & 0xffff;
          } while ((int)((iVar4 + 1U) * 0x10000) >> 0x10 < 6);
          break;
        case 5:
          sub_080ECE08(5);
          uVar7 = 0;
          do {
            iVar4 = (int)(short)uVar7;
            sub_080ECE38(iVar4,iVar4 << 3,0);
            uVar7 = iVar4 + 1U & 0xffff;
          } while ((int)((iVar4 + 1U) * 0x10000) >> 0x10 < 6);
          break;
        case 6:
          sub_080ECE08(5);
          uVar7 = 0;
          do {
            iVar4 = (int)(short)uVar7;
            sub_080ECE38(iVar4,iVar4 << 3,5);
            uVar7 = iVar4 + 1U & 0xffff;
          } while ((int)((iVar4 + 1U) * 0x10000) >> 0x10 < 6);
          break;
        case 7:
          sub_080ECE08(5);
          uVar7 = 0;
          do {
            iVar4 = (int)(short)uVar7;
            sub_080ECE38(iVar4,iVar4 << 3,1);
            uVar7 = iVar4 + 1U & 0xffff;
          } while ((int)((iVar4 + 1U) * 0x10000) >> 0x10 < 6);
        }
        DAT_0203cb7c = 2;
        return 0;
      }
    }
    DAT_0203cb7c = 3;
    break;
  case 2:
    iVar4 = sub_080ECB10();
    if (iVar4 != 0) {
      DAT_0203cb7c = 4;
    }
    break;
  case 3:
  case 4:
    sub_080F0CFC(iVar4,(int)sVar3);
    break;
  case 5:
    sub_080F17C0(iVar4,(int)sVar3);
    break;
  case 7:
    sub_080F2514(iVar4,(int)sVar3);
    break;
  case 8:
    sub_080F27CC(iVar4,(int)sVar3);
    break;
  case 9:
    iVar8 = (int)(short)(ushort)DAT_0300008c;
    iVar4 = sub_080EF0E4(iVar8);
    if (iVar4 == 0) {
      iVar4 = sub_080F3110(iVar8);
      if (iVar4 == 1) {
        uVar5 = sub_080F2F64(iVar8 - 0x8000U & 0xffff);
        Battle_BuildDefeatedTargetText(uVar5);
        sub_080EA4F8(3);
        sub_080ECF70(0x12f);
      }
      else {
        arg0_00 = 0x12e;
        if (iVar8 < 4) {
          arg0_00 = 0x12d;
        }
        iVar4 = sub_080F2F64(iVar8 - 0x8000U & 0xffff);
        uVar1 = *(ushort *)(iVar4 + 0x10);
        *(ushort *)(iVar4 + 0x10) = uVar1 | 0x8000;
        uVar7 = sub_080F3144();
        if ((uVar7 & 0xff) == 1) {
          sub_080EA9E8(0);
        }
        *(ushort *)(iVar4 + 0x10) = uVar1;
        Battle_BuildNamePrependText(iVar8 + 0x8000,0x8124264);
        sub_080EA4F8(3);
        sub_080ECF70(arg0_00);
      }
      sub_080EF218();
      if (0xf < (short)uVar2) {
        DAT_0203cb7c = 0xd;
        return 0;
      }
    }
    else {
      sub_080C08BC(iVar8,0x7fff);
      sub_080C0AD4(iVar8,DAT_030000a0);
      uVar5 = sub_080EC038(0x171);
      iVar4 = sub_080F3E44();
      Menu_ExpandListTemplate(uVar5,iVar4 << 0x10);
      sub_080EA4F8(3);
    }
    goto LAB_080f0b48;
  case 10:
    iVar8 = sub_080ED9F4();
    if ((iVar8 != 0) && (uVar7 = sub_080F3144(), (uVar7 & 0xff) != 1)) {
      DAT_03000080 = DAT_03000080 + 1;
      DAT_0203d166 = DAT_0203d166 + 1;
      DAT_0203d3aa = DAT_0203d3aa + 1;
      DAT_0203cb7c = 3;
      iVar8 = (int)sVar3;
      uVar7 = sub_080C0818(iVar8);
      if ((uVar7 & 0x8000) != 0) {
        DAT_0203cb7c = 0xb;
        return 0;
      }
      iVar6 = sub_080ED954();
      if ((((iVar6 != 0) && ((int)DAT_03000080 < *(int *)(DAT_03006434 + 0x15c))) &&
          (iVar6 = sub_080EFFF8(iVar8,(int)DAT_0203d166), iVar6 == -1)) &&
         (*(int *)(DAT_03006434 + 0x15c) != 0x8000)) {
        DAT_0203d166 = 0;
        sub_080F038C(iVar8,iVar4);
        if (*(int *)(DAT_03006434 + 0x15c) <= (int)DAT_03000080) {
          DAT_0203cb7c = 0xb;
          return 0;
        }
        return 0;
      }
      iVar6 = (int)(local_2c * 0x1000000) >> 0x18;
      if ((((local_2c * 0x1000000 + 0xfc000000 >> 0x18 < 2) || (iVar6 == 10)) ||
          (iVar4 = sub_080F03D8(iVar6,(uint)*(byte *)(iVar4 + 0x5c)), iVar4 == 1)) &&
         (*(int *)(DAT_03006434 + 0x15c) != 0x8000)) {
        iVar4 = sub_080EFFF8(iVar8,(int)DAT_0203d166);
        if (iVar4 == -1) {
          DAT_0203d166 = 0;
        }
      }
      else {
        if (*(int *)(DAT_03006434 + 0x15c) <= (int)DAT_0203d166) {
          DAT_0203cb7c = 0xb;
        }
        iVar4 = sub_080EFFF8(iVar8,(int)DAT_0203d166);
        if (iVar4 == -1) {
          DAT_0203cb7c = 0xb;
        }
      }
      if ((int)DAT_03000080 < *(int *)(DAT_03006434 + 0x15c)) {
        return 0;
      }
    }
LAB_080f0a78:
    DAT_0203cb7c = 0xb;
    break;
  case 0xb:
    uVar7 = sub_080EA934();
    if ((uVar7 & 0xff) != 1) {
      return 0;
    }
    iVar4 = sub_080ED954();
    if (((iVar4 == 0) || (DAT_0203d38c != 0)) ||
       ((iVar4 = sub_080EDA24(0), iVar4 != 0 && (iVar4 = sub_080EDA24(1), iVar4 != 0)))) {
      return 1;
    }
    DAT_0203cb7c = 0xe;
    goto LAB_080f0b4e;
  case 0xc:
    uVar7 = sub_080EA934();
    if ((uVar7 & 0xff) == 1) {
      DAT_0203cb7c = DAT_030000ac;
    }
    break;
  case 0xd:
    iVar4 = sub_080EDAD0();
    if ((iVar4 == 0) || (iVar4 = sub_080EDAEC(DAT_0203cb90), iVar4 != 0)) {
      uVar2 = (ushort)DAT_0300008c;
      uVar7 = sub_080E75DC((ushort)DAT_0300008c - 0x10 & 0xff,2);
      if ((uVar7 & 0xff) != 0) {
        return 0;
      }
      iVar4 = sub_080F0B78((int)(short)uVar2);
      if (iVar4 == 1) {
        DAT_0203cb7c = 0xe;
        goto LAB_080f0b4e;
      }
    }
LAB_080f0b48:
    DAT_0203cb7c = 10;
LAB_080f0b4e:
    sub_080F0344(3,0xc);
    break;
  case 0xe:
    sub_080F0BEC();
  }
  return 0;
}


// sub_080F0B78 @ 0x080F0B78

undefined4 sub_080F0B78(int arg0)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_080ED954();
  if (((iVar1 == 0) || (DAT_0203d38c != 0)) ||
     (iVar1 = sub_080EDA24((uint)(3 < arg0 * 0x1000000 + 0xf0000000U >> 0x18)), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// sub_080F0BC0 @ 0x080F0BC0

void sub_080F0BC0(void)

{
  DAT_0203d38c = DAT_0203d38c + 2;
  return;
}


// sub_080F0BD8 @ 0x080F0BD8

void sub_080F0BD8(void)

{
  DAT_0203cb7c = 10;
  return;
}


// sub_080F0BEC @ 0x080F0BEC

void sub_080F0BEC(void)

{
  sub_080AD0FC(0x876f7dc,0xffff);
  DAT_0203cb7c = 0xf;
  return;
}


// sub_080F0C18 @ 0x080F0C18

undefined4 sub_080F0C18(int arg0,int arg1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = *(ushort *)(arg0 + 0x10);
  if ((uVar1 & 0x200) == 0) {
    if ((uVar1 & 8) != 0) {
      uVar4 = sub_080C2244();
      uVar3 = __umodsi3(uVar4,0x28);
      if (uVar3 < 0x14) {
        uVar4 = sub_080EC038(0x172);
        Menu_ExpandListTemplate(uVar4,(int)(short)arg1);
        sub_080EA4F8(3);
        DAT_0203cb7c = 0xb;
        sub_080F0344(3,0xc);
        uVar4 = 1;
        goto LAB_080f0cf6;
      }
    }
    if (((uVar1 & 0x10) != 0) && (uVar3 = sub_080C2244(), (uVar3 & 2) != 0)) {
      iVar5 = arg1 * 0x10000 >> 0x10;
      if (iVar5 < 0x10) {
        if ((iVar5 < 4) || ((uVar3 & 1) != 0)) {
          sub_080C35C4(iVar5,9);
        }
        else {
          sub_080C35C4(iVar5,0xc);
        }
      }
      else {
        *(undefined1 *)(arg0 + 0x17) = 9;
      }
    }
  }
  else {
    iVar5 = (int)(short)arg1;
    if (iVar5 < 4) {
      iVar2 = sub_080C00DC(iVar5,0);
      if (iVar2 == 0xff) {
        sub_080C35C4(iVar5,9);
      }
      else {
        sub_080C35C4(iVar5,4);
      }
    }
    else {
      sub_080C35C4(iVar5,10);
    }
  }
  uVar4 = 0;
LAB_080f0cf6:
                    /* WARNING: Could not recover jumptable at 0x080f0cfa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar4);
  return uVar4;
}


// sub_080F0CFC @ 0x080F0CFC

void sub_080F0CFC(int arg0,undefined4 arg1)

{
  ushort uVar1;
  char cVar2;
  undefined2 uVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int arg0_00;
  int iVar9;
  uint local_28;
  uint local_24;
  
  local_28 = (uint)*(byte *)(arg0 + 0x5c);
  cVar2 = *(char *)(arg0 + 0x17);
  uVar1 = *(ushort *)(arg0 + 0x10);
  if (*(short *)(DAT_03006434 + 0x15c) == 0) {
    local_24 = (uint)(short)arg1;
    sub_080F2C9C(local_24);
  }
  else {
    local_24 = sub_080EFFF8((int)(short)arg1,(int)DAT_0203d166);
  }
  local_24 = local_24 & 0xffff;
  iVar5 = cVar2 * 0x10000;
  iVar9 = iVar5 >> 0x10;
  uVar3 = (undefined2)((uint)iVar5 >> 0x10);
  arg0_00 = (int)(short)arg1;
  if (iVar9 == 8) {
    if (DAT_0203d166 == 0) {
      sub_080F3E54(local_28,0xffffffff);
    }
LAB_080f0e54:
    if ((iVar9 == 0xb) && (local_28 - 0x54 < 0x14)) goto LAB_080f0ec8;
  }
  else {
    if (iVar9 == 7) {
      if ((int)local_28 < 0x40) {
        iVar6 = 0;
        sVar4 = *(short *)(arg0 + 0x1c);
        uVar7 = sub_080ED6CC(local_28);
        if ((DAT_0203d3aa == 0) && (arg0_00 < 0x10)) {
          iVar8 = (int)sVar4 - (int)(short)uVar7;
          if (iVar8 * 0x10000 < 0) {
            iVar6 = 1;
          }
          else {
            *(short *)(arg0 + 0x1c) = (short)iVar8;
          }
        }
        if ((uVar1 & 2) != 0) {
          iVar6 = 2;
        }
        if (iVar6 != 0) {
          if (iVar6 == 2) {
            sub_080EA4F8(3);
          }
          else {
            sub_080EA4F8(3);
          }
          DAT_0203cb7c = 0xb;
          return;
        }
      }
      goto LAB_080f0e54;
    }
    if (iVar9 == 0xb) {
      if ((DAT_0203d3aa == 0) && (arg0_00 < 0x10)) {
        iVar6 = sub_080ED744(arg0_00,local_28);
        if (iVar6 != 1) {
          sub_080EA4F8(3);
          DAT_0203cb7c = uVar3;
          return;
        }
        sub_080ED6DC(arg0_00,local_28);
      }
      goto LAB_080f0e54;
    }
  }
  sVar4 = (short)local_24;
  iVar6 = sub_080EE028(arg0_00,(int)sVar4);
  if (iVar6 == 0) {
    iVar5 = sub_080F3110(arg0_00);
    if (iVar5 == 0) {
      sub_080EA4F8(3);
    }
    else {
      uVar7 = sub_080F2F64((int)sVar4 - 0x8000U & 0xffff);
      Battle_BuildDodgeText(uVar7);
      sub_080EA4F8(3);
    }
    DAT_0203cb7c = 10;
    sub_080F0344(3,0xc);
    return;
  }
LAB_080f0ec8:
  if ((1 < iVar5 - 0x40000U >> 0x10) && (iVar9 != 10)) {
    if (iVar9 == 8) {
      sub_080BF468(local_28,0xc,&local_28);
      if (0x7f < (int)local_28) {
        DAT_0203cb7c = uVar3;
        return;
      }
      if (local_28 - 0x1d < 0x23) {
        DAT_0203cb7c = 7;
        return;
      }
    }
    else if (local_28 - 0x1d < 0x23) {
      DAT_0203cb7c = 7;
      return;
    }
  }
  DAT_0203cb7e = 0;
  DAT_0203cb7c = 5;
  return;
}


// sub_080F0F68 @ 0x080F0F68

uint sub_080F0F68(uint arg0,uint arg1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)((arg1 & 0xffff) + (arg0 & 0xffff) * 4 + 0x876e1d8);
  switch(uVar1) {
  case 0xdc:
  case 0xe0:
  case 0xe3:
  case 0xe6:
    uVar1 = 0xff;
    break;
  case 0xdd:
    uVar1 = 0x34;
    break;
  case 0xde:
    uVar1 = 100;
    break;
  case 0xdf:
    uVar1 = 0x70;
    break;
  case 0xe1:
    uVar1 = 0x37;
    break;
  case 0xe2:
    uVar1 = 0x67;
    break;
  case 0xe4:
    uVar1 = 0x36;
    break;
  case 0xe5:
    uVar1 = 0x66;
    break;
  case 0xe7:
    uVar1 = 0x35;
    break;
  case 0xe8:
    uVar1 = 0x65;
  }
  return uVar1;
}


// sub_080F104C @ 0x080F104C

uint sub_080F104C(uint arg0,uint arg1)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = (arg0 & 0xffff) * 4;
  pbVar2 = (byte *)((arg1 & 0xffff) + iVar3 + 0x876e1d8);
  if (*pbVar2 < 0xd2) {
    uVar1 = (uint)*pbVar2;
  }
  else {
    uVar1 = sub_080F0F68(arg0 & 0xffff,arg1 & 0xffff);
    uVar1 = uVar1 & 0xff;
    if (0xdb < uVar1) {
      return (uint)*(ushort *)(&DAT_0876e1da + iVar3);
    }
  }
  uVar1 = sub_080ED32C(uVar1);
  return uVar1 & 0xffff;
}


// sub_080F108C @ 0x080F108C

void sub_080F108C(int arg0,undefined4 arg1,uint arg2)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  undefined4 uVar9;
  undefined2 *puVar10;
  short sVar11;
  uint uVar12;
  int iVar13;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  
  local_2c = arg2 & 0xffff;
  local_30 = (uint)(ushort)arg1;
  uVar3 = sub_080F3F14((int)(short)(ushort)arg1);
  local_28 = sub_080C0818((int)(short)(ushort)arg1);
  local_28 = local_28 & 0xffff;
  local_24 = 0;
  DAT_0203d0ca = 0xff;
  DAT_0203d0c6 = 0xff;
  DAT_0203d0c8 = 0xff;
  DAT_030000aa = 0xff;
  DAT_030000a8 = -1;
  DAT_0203cb7c = 1;
  iVar6 = arg0;
  switch((int)((*(byte *)(arg0 + 0x17) - 4) * 0x1000000) >> 0x18) {
  case 0:
    Battle_BuildCombatActionList(arg0,0);
    sub_080EA4F8(3);
    sVar11 = (short)local_30;
    iVar6 = sub_080C00DC((int)sVar11,0);
    DAT_0203d0c6 = (ushort)*(byte *)(iVar6 * 4 + 0x876e458);
    uVar9 = sub_080ED32C((uint)DAT_0203d0c6);
    DAT_0203d0ca = (undefined2)uVar9;
    iVar6 = sub_080EF5FC(arg0,(int)sVar11);
    if (iVar6 == 0x8000) {
      local_24 = 1;
    }
    break;
  case 1:
    Battle_BuildCombatActionList(arg0,1);
    sub_080EA4F8(3);
    sVar11 = (short)local_30;
    iVar6 = sub_080C00DC((int)sVar11,1);
    DAT_0203d0c6 = (ushort)*(byte *)(iVar6 * 4 + 0x876e458);
    uVar9 = sub_080ED32C((uint)DAT_0203d0c6);
    DAT_0203d0ca = (undefined2)uVar9;
    iVar6 = sub_080EF5FC(arg0,(int)sVar11);
    if (iVar6 == 0x8000) {
      local_24 = 1;
    }
    break;
  case 2:
    uVar3 = sub_080F1678((int)(short)local_30,0);
    iVar6 = sub_080C0148(uVar3 & 0xffff);
    uVar9 = 3;
    goto LAB_080f14aa;
  case 3:
  case 7:
    iVar6 = (int)(local_30 * 0x10000) >> 0x10;
    if (iVar6 < 0x10) {
      iVar7 = sub_080BF5C0(uVar3 & 0xffff);
      if ((*(char *)(iVar7 + 2) == '\x0f') || (*(char *)(iVar7 + 2) == -1)) {
        local_24 = 1;
      }
    }
    iVar7 = (int)(short)uVar3;
    if (iVar7 < 0x40) {
      uVar12 = iVar7 - 0x20U & 0xffff;
      if (uVar12 < 0x18) {
        local_2c = sub_080F3110(iVar6);
        local_2c = local_2c & 0xffff;
      }
      if (uVar12 < 3) {
        DAT_030000a8 = 0;
      }
      sub_080EAE30(arg0);
      sub_080EA4F8(3);
      if ((local_28 & 2) == 0) {
        uVar12 = local_2c << 0x10;
        uVar9 = sub_080F0F68(uVar3 & 0xffff,local_2c & 0xffff);
        DAT_0203d0c6 = (ushort)uVar9 & 0xff;
        sub_080F157C(iVar7,(int)uVar12 >> 0x10);
      }
      else {
        DAT_0203d0c6 = 0xff;
        uVar12 = local_2c << 0x10;
      }
    }
    else {
      iVar13 = (int)*(short *)((iVar7 + -0x40) * 2 + 0x876e878);
      if (iVar7 == 0x66) {
        iVar6 = sub_080F5938();
        if (iVar6 == -1) {
          iVar6 = 0;
        }
        uVar9 = sub_080EC038(iVar13);
        Menu_ExpandListTemplate(uVar9,iVar6);
        sub_080EA4F8(3);
      }
      else {
        uVar9 = sub_080EC038(iVar13);
        iVar13 = sub_080F3F14(iVar6);
        Menu_ExpandListTemplate(uVar9,iVar6 + iVar13 * 0x10000);
        sub_080EA4F8(3);
      }
      uVar12 = local_2c << 0x10;
      uVar9 = sub_080F0F68(uVar3 & 0xffff,local_2c & 0xffff);
      DAT_0203d0c6 = (ushort)uVar9 & 0xff;
      sub_080F157C(iVar7,(int)uVar12 >> 0x10);
    }
    uVar9 = sub_080F104C(uVar3 & 0xffff,uVar12 >> 0x10);
    uVar2 = (undefined2)uVar9;
    puVar10 = &DAT_0203d0ca;
    goto LAB_080f14bc;
  case 4:
    iVar6 = (int)(short)uVar3;
    sub_080BF468(iVar6,0xc,&local_34);
    iVar7 = local_30 * 0x10000;
    iVar13 = iVar7 >> 0x10;
    if ((iVar13 < 0x10) && (iVar4 = Action_GetRecord(uVar3 & 0xffff), *(char *)(iVar4 + 3) == -1)) {
      local_24 = 1;
    }
    if (iVar6 == 0xf0) {
      puVar5 = (ushort *)(&DAT_0203d130 + (iVar7 >> 0xf));
      uVar8 = (ushort)*(byte *)(arg0 + 0xc);
      DAT_0203d392 = (ushort)local_34;
LAB_080f127e:
      *puVar5 = uVar8;
    }
    else if (iVar6 == 0xf8) {
      puVar5 = &DAT_0203d394;
      uVar8 = (ushort)local_34;
      goto LAB_080f127e;
    }
    if ((iVar6 < 0xbd) || (local_34 - 0x20 < 0x18)) {
      local_2c = sub_080F3110(iVar13);
      local_2c = local_2c & 0xffff;
    }
    if ((iVar6 == 0xf8) || (iVar6 == 0xf0)) {
      sVar11 = (short)local_2c;
      uVar3 = local_2c & 0xffff;
      uVar9 = sub_080F0F68(local_34 & 0xffff,uVar3);
      DAT_0203d0c6 = (ushort)uVar9 & 0xff;
      uVar9 = sub_080F104C(local_34 & 0xffff,uVar3);
      DAT_0203d0ca = (undefined2)uVar9;
      sub_080F157C((int)(short)local_34,(int)sVar11);
    }
    else {
      iVar6 = (iVar6 + -0xd0) * 4;
      bVar1 = *(byte *)(iVar6 + 0x876e618);
      DAT_0203d0c6 = (ushort)bVar1;
      if (bVar1 < 0xc9) {
        uVar9 = sub_080ED32C((uint)DAT_0203d0c6);
        DAT_0203d0ca = (undefined2)uVar9;
      }
      else {
        DAT_0203d0ca = *(undefined2 *)(&DAT_0876e61a + iVar6);
      }
    }
    sub_080EB080(arg0);
    goto LAB_080f1332;
  case 5:
    uVar9 = 4;
    goto LAB_080f14aa;
  case 6:
    uVar9 = sub_080ED32C(0);
    DAT_0203d0ca = (undefined2)uVar9;
    Battle_BuildCombatActionList(arg0,2);
LAB_080f1332:
    sub_080EA4F8(3);
    break;
  case 8:
    sub_080C0290(local_30,0);
    uVar9 = 5;
LAB_080f14aa:
    Battle_BuildCombatActionList(iVar6,uVar9);
    sub_080EA4F8(3);
    puVar10 = &DAT_0203cb7c;
    uVar2 = 0xb;
LAB_080f14bc:
    *puVar10 = uVar2;
  }
  if ((DAT_0203d0c6 == 0x88) && (*(char *)(arg0 + 0x17) == '\b')) {
    local_24 = 1;
  }
  iVar6 = sub_080ED954();
  if ((iVar6 == 0) || (local_24 == 1)) {
    uVar2 = 0;
    goto LAB_080f154c;
  }
  iVar6 = (int)(local_30 * 0x10000) >> 0x10;
  if (iVar6 < 0x10) {
    iVar7 = sub_080EDA24(0);
    if (((iVar7 != 0) && (iVar7 = sub_080EDA24(1), iVar7 != 0)) && (uVar2 = 0, DAT_030000a8 == 0))
    goto LAB_080f154c;
    uVar3 = sub_080F1788(iVar6);
    if ((uVar3 & 0xffff) == 0) {
      uVar2 = 1;
      goto LAB_080f154c;
    }
  }
  else if (iVar6 < 0x14) {
    uVar2 = 1;
    goto LAB_080f154c;
  }
  uVar2 = 2;
LAB_080f154c:
  DAT_030000a8 = uVar2;
  uVar3 = sub_080C2B6C();
  if ((uVar3 & 0xffff) == 1) {
    DAT_0203d0c6 = 0xff;
  }
  return;
}


// sub_080F157C @ 0x080F157C

void sub_080F157C(int arg0,undefined4 arg1)

{
  DAT_030000aa = 0xff;
  switch(*(undefined1 *)((int)(short)arg1 + ((arg0 << 0x10) >> 0xe) + 0x876e1d8)) {
  case 0xdc:
    DAT_030000aa = 4;
    break;
  case 0xdd:
    DAT_030000aa = 4;
    break;
  case 0xde:
    DAT_030000aa = 4;
    break;
  case 0xdf:
    DAT_030000aa = 4;
    break;
  case 0xe0:
    DAT_030000aa = 7;
    break;
  case 0xe1:
    DAT_030000aa = 7;
    break;
  case 0xe2:
    DAT_030000aa = 7;
    break;
  case 0xe3:
    DAT_030000aa = 8;
    break;
  case 0xe4:
    DAT_030000aa = 8;
    break;
  case 0xe5:
    DAT_030000aa = 8;
    break;
  case 0xe6:
  case 0xe7:
  case 0xe8:
    DAT_030000aa = 5;
  }
  return;
}


// sub_080F1678 @ 0x080F1678

uint sub_080F1678(int arg0,undefined4 arg1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  ushort *puVar8;
  
  iVar3 = (arg0 << 0x10) >> 0xf;
  puVar8 = (ushort *)((int)&DAT_0203d110 + iVar3);
  uVar1 = *puVar8;
  puVar7 = (ushort *)((int)&DAT_0203d0f0 + iVar3);
  uVar2 = *puVar7;
  if ((short)arg1 == 2) {
    if ((int)(char)(&DAT_030050e0)[(short)uVar1] != 0xffffffff) {
      sub_080C0290((int)(char)(&DAT_030050e0)[(short)uVar1] & 0xffff,0);
    }
    *puVar7 = 0xffff;
    *puVar8 = 0xffff;
  }
  iVar3 = sub_080F30CC((int)(short)uVar1);
  uVar6 = (uint)uVar1;
  if (iVar3 != -1) {
    uVar4 = 0;
    while ((iVar3 = (int)(short)uVar4, uVar6 = (uint)uVar1, iVar3 < 6 &&
           (iVar5 = sub_080F30CC(iVar3), uVar6 = uVar4, iVar5 != -1))) {
      uVar4 = iVar3 + 1U & 0xffff;
    }
  }
  sub_080C0248((uint)uVar2,uVar6);
  if ((short)arg1 == 0) {
    sub_0812839C((uint)uVar2);
    sub_080F3E20();
  }
  if ((short)arg1 == 3) {
    sub_080C08F8((int)(char)(&DAT_030050e0)[(short)uVar6],0x4000);
    sub_080F4054((int)(char)(&DAT_030050e0)[(short)uVar6],0);
  }
  sub_080C8490((int)(short)uVar6);
  sub_080C366C();
  Party_BuildMemberNameTiles();
  uVar6 = sub_080BFFC4((int)(short)uVar2);
  return uVar6 & 0xffff;
}


// sub_080F1788 @ 0x080F1788

uint sub_080F1788(undefined4 arg0)

{
  undefined4 arg0_00;
  uint uVar1;
  int iVar2;
  
  arg0_00 = sub_080EDA64((int)(short)arg0);
  uVar1 = sub_080ED974(arg0_00);
  iVar2 = sub_080EDA24((int)(short)uVar1);
  if (iVar2 == 0) {
    uVar1 = (int)(short)uVar1 ^ 1;
  }
  return (uint)((uVar1 & 0xffff) != 0);
}


// sub_080F17C0 @ 0x080F17C0

void sub_080F17C0(int arg0,undefined4 arg1)

{
  char cVar1;
  short sVar2;
  int arg1_00;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined2 *puVar10;
  dword dVar11;
  uint uVar12;
  code *UNRECOVERED_JUMPTABLE;
  uint local_28;
  int iStack_24;
  
  cVar1 = *(char *)(arg0 + 0x17);
  uVar9 = (int)cVar1 & 0xffff;
  local_28 = (uint)*(byte *)(arg0 + 0x5c);
  iVar4 = sub_080EFFF8((int)(short)arg1,(int)DAT_0203d166);
  iVar5 = sub_080F2F64(iVar4 * 0x10000 + 0x80000000U >> 0x10);
  if (uVar9 == 8) {
    if (local_28 == 0xf8) {
      local_28 = (uint)DAT_0203d394;
    }
    else {
      sub_080BF468(local_28,0xc,&local_28);
    }
  }
  arg1_00 = DAT_0300008c;
  switch(DAT_0203cb7e) {
  case 0:
    sub_080EDA7C(0);
    DAT_03000088 = (int)(short)arg1;
    DAT_0300008c = (int)(short)iVar4;
    DAT_030000a0 = 0;
    DAT_03000094 = 1;
    DAT_03000082 = 0;
    iVar4 = cVar1 * 0x10000;
    if ((1 < iVar4 - 0x40000U >> 0x10) && (iVar4 >> 0x10 != 10)) {
      if ((local_28 - 0x13 < 10) ||
         ((0x3f < (int)local_28 &&
          (pbVar6 = (byte *)sub_080BF5C0(local_28 & 0xffff), (*pbVar6 & 0x10) != 0)))) {
        DAT_030000ae = 1;
        DAT_0203cb7e = 3;
      }
      else {
        DAT_030000ae = 0;
        DAT_0203cb7e = 2;
      }
      break;
    }
    DAT_030000ae = 0;
    DAT_0203cb7e = 1;
    iVar4 = sub_080C0830();
    if (iVar4 == 0) break;
    goto FUN_080f20a0;
  case 1:
    DAT_030000a0 = sub_080EE864((int)(short)arg1,(int)(short)iVar4);
joined_r0x080f1b3a:
    if (DAT_030000a0 != 0) {
      DAT_0203cb7e = 4;
      break;
    }
    goto LAB_080f1b40;
  case 2:
    if (uVar9 == 8) {
      uVar9 = (uint)*(byte *)(arg0 + 0x5c);
      if (uVar9 == 0xf8) {
        local_28 = (uint)DAT_0203d394;
      }
      else {
        local_28 = uVar9;
        sub_080BF468(uVar9,0xc,&local_28);
      }
      sub_080F3EF4((int)(short)arg1,local_28 & 0xffff);
      sub_080EE9F8(0x3000088);
      sub_080F3EF4((int)(short)arg1,uVar9);
LAB_080f1ad2:
      if (DAT_030000a0 == 0xffff) {
        if (DAT_03000090 != -1) {
          iVar4 = DAT_0300008c;
          if (DAT_0300008c == -1) {
            iVar4 = DAT_03000088;
          }
          uVar7 = sub_080EC038(DAT_03000090);
          iVar5 = sub_080F3E44();
          Menu_ExpandListTemplate(uVar7,iVar4 + iVar5 * 0x10000);
          sub_080EA4F8(3);
        }
        if ((DAT_03000094 == 1) && (local_28 - 0x9e < 2)) {
          DAT_0203d0c0 = 1;
        }
        dVar11 = 0x97c;
        goto LAB_080f1e74;
      }
      goto joined_r0x080f1b3a;
    }
    sub_080EE9F8(0x3000088);
    cVar1 = *(char *)(arg0 + 0x5c);
    if ((cVar1 != '\\') && (cVar1 != 'a')) {
      if ((byte)(cVar1 + 0x9aU) < 2) {
        DAT_0203cb7e = 7;
        if (DAT_03000094 != 1) break;
        iVar5 = sub_080EF0E4(DAT_0300008c);
        iVar4 = DAT_0300008c;
        if (iVar5 == 0) {
          sub_080C08F8(DAT_0300008c,0x8000);
          sub_080F4054(iVar4,0);
          if (iVar4 - 4U < 0xc) {
            sub_080F4190(iVar4);
          }
          sub_080C366C();
          break;
        }
        uVar7 = sub_080EC038(0x171);
        iVar4 = sub_080F3E44();
        Menu_ExpandListTemplate(uVar7,iVar4 << 0x10);
        sub_080EA4F8(3);
        goto LAB_080f1fa0;
      }
      if ((byte)(cVar1 + 0x9dU) < 3) {
        if (DAT_030000a0 != 0) {
          DAT_030000ae = 1;
          goto LAB_080f1e3e;
        }
      }
      else {
        if ((1 < (byte)(cVar1 + 0xacU)) && (cVar1 != '^')) goto LAB_080f1ad2;
        if (DAT_03000090 != -1) {
          uVar7 = sub_080EC038(DAT_03000090);
          Menu_ExpandListTemplate(uVar7,DAT_0300008c);
          sub_080EA4F8(3);
        }
      }
      goto LAB_080f2040;
    }
    if (DAT_030000a0 != 0) goto LAB_080f1e3e;
LAB_080f1b40:
    DAT_0203cb7e = 8;
    break;
  case 3:
    iStack_24 = sub_080EEB94(0x3000088,local_28);
    DAT_030000ac = -1;
    if (DAT_03000090 != -1) {
      uVar7 = sub_080EC038(DAT_03000090);
      Menu_ExpandListTemplate(uVar7,arg1_00);
      sub_080EA4F8(3);
      DAT_030000ac = 0;
    }
    uVar9 = sub_080EDA90();
    if ((uVar9 & 0xffff) == 0xffff) {
      uVar9 = sub_080C0818(DAT_0300008c);
      if ((uVar9 & 0x8000) == 0) {
        if (iStack_24 != 0) {
          sub_080EA4F8(3);
          DAT_0203cb7e = 7;
          DAT_030000ac = 0;
          goto LAB_080f1c34;
        }
        puVar10 = &DAT_0203cb7e;
        uVar3 = 8;
      }
      else {
        puVar10 = &DAT_0203cb7c;
        uVar3 = 10;
      }
    }
    else if ((uVar9 & 0xffff) == 0) {
      puVar10 = &DAT_0203cb7e;
      uVar3 = 9;
    }
    else if (DAT_03000090 == -1) {
      puVar10 = &DAT_0203cb7e;
      uVar3 = 4;
    }
    else {
      puVar10 = &DAT_0203cb7e;
      uVar3 = 10;
    }
    *puVar10 = uVar3;
    goto LAB_080f1c34;
  case 4:
    iVar4 = sub_080EED88(0x3000088);
    if (iVar4 != 0) {
      if (DAT_03000090 != 0x16e) {
        dVar11 = 0x97e;
        goto LAB_080f2096;
      }
      sub_080F20E0();
      if (DAT_0203cb7e != 9) {
        if (DAT_030000a0 == 0) {
          DAT_0203cb7e = 8;
        }
        else {
          DAT_0203cb7e = 10;
        }
      }
      goto LAB_080f1fa0;
    }
    if (DAT_030000ae != 1) {
      DAT_0203cb7e = 5;
      break;
    }
    puVar10 = &DAT_0203cb7e;
    goto LAB_080f20a4;
  case 5:
    uVar7 = sub_080EFE60(DAT_03000088);
    uVar7 = sub_080F3F90(DAT_0300008c,uVar7);
    if (DAT_0300008c < 0x10) {
      uVar12 = sub_080F3F44();
      if (((uVar12 & 0x400) == 0) || (uVar9 != 10)) {
        if ((0xf < DAT_0300008c) ||
           ((uVar12 = sub_080F3F44(), (uVar12 & 0x400) == 0 ||
            (iVar4 = sub_080EED64(uVar9,local_28 & 0xffff), iVar4 != 1)))) goto LAB_080f1d24;
        sVar2 = *(short *)(arg0 + 0x12);
      }
      else {
        sVar2 = *(short *)(arg0 + 0x12);
      }
      if (0xb1 < sVar2) {
        uVar7 = 0xd;
      }
    }
LAB_080f1d24:
    DAT_030000a0 = sub_080EEEE8(DAT_030000a0,uVar7);
    if ((int)*(short *)(iVar5 + 0x18) < (int)DAT_030000a0) {
      DAT_030000a0 = (int)*(short *)(iVar5 + 0x18);
    }
    DAT_030000ac = -1;
    switch(uVar7) {
    case 0xc:
    case 0xd:
      sub_080F20E0();
      if (DAT_0203cb7e == 9) goto LAB_080f1fa0;
      DAT_030000ac = 0;
    default:
      if (DAT_030000a0 == 0) {
        DAT_0203cb7e = 8;
      }
      else {
        DAT_0203cb7e = 10;
      }
      break;
    case 0xe:
    case 0xf:
      uVar7 = sub_080F401C(DAT_0300008c);
      uVar8 = sub_080F4038(DAT_0300008c);
      if ((int)(short)uVar8 < (int)((int)(short)uVar7 + DAT_030000a0)) {
        DAT_030000a0 = (int)(short)uVar8 - (int)(short)uVar7;
      }
      sub_080C0AD4(DAT_0300008c,DAT_030000a0);
    case 0:
      dVar11 = 0x97e;
LAB_080f2096:
      *(undefined2 *)(dVar11 + 0x203c200) = 9;
      goto FUN_080f20c6;
    }
LAB_080f1c34:
    if (DAT_030000ac != -1) {
LAB_080f1fa0:
      sub_080F0344(4,0xd);
    }
    break;
  case 6:
    sub_080F2AC8();
    goto LAB_080f2040;
  case 7:
    uVar9 = sub_080EA934();
    if ((uVar9 & 0xff) != 1) break;
    uVar9 = sub_080C0818(DAT_0300008c);
    if ((uVar9 & 0x4000) != 0) {
      puVar10 = &DAT_0203cb7c;
      goto LAB_080f20a4;
    }
    iVar4 = sub_080F401C(DAT_0300008c);
    if ((iVar4 < 1) || (uVar9 = sub_080C0818(DAT_0300008c), (uVar9 & 0x8000) != 0)) {
      dVar11 = 0x97c;
      goto LAB_080f2096;
    }
FUN_080f20a0:
    puVar10 = &DAT_0203cb7c;
LAB_080f20a4:
    *puVar10 = 10;
    break;
  case 8:
    iVar4 = sub_080F3110(DAT_0300008c);
    if (iVar4 == 1) {
      sub_080EA4F8(3);
    }
    else {
      uVar7 = sub_080F2F64(DAT_0300008c - 0x8000U & 0xffff);
      Battle_BuildActorStatusText(uVar7,0x8124234);
      sub_080EA4F8(3);
    }
    goto LAB_080f2040;
  case 9:
    iVar4 = sub_080F3110(DAT_0300008c);
    uVar7 = 0x154;
    if (iVar4 == 1) {
      uVar7 = 0x153;
    }
    uVar7 = sub_080EC038(uVar7);
    Menu_ExpandListTemplate(uVar7,DAT_0300008c);
    sub_080EA4F8(3);
LAB_080f2040:
    DAT_0203cb7e = 7;
    break;
  case 10:
    if (DAT_0203d3b0 != 0) {
      sub_080EA4F8(3);
      DAT_0203d3b0 = 0;
      dVar11 = 0x97e;
LAB_080f1e74:
      *(undefined2 *)(dVar11 + 0x203c200) = 0xb;
      break;
    }
  case 0xc:
    iVar4 = sub_080F401C(DAT_0300008c);
    if ((0 < iVar4) && (uVar9 = sub_080C0818(DAT_0300008c), (uVar9 & 0x8000) == 0)) {
      sub_080F22B4();
      uVar9 = sub_080EDA90();
      uVar12 = uVar9 & 0xffff;
      if ((uVar12 == 0) || (uVar12 == 0xffff)) {
LAB_080f1f9c:
        DAT_0203cb7e = 7;
      }
      else {
        iVar4 = sub_080EDAD0();
        if (((iVar4 == 0) || ((uVar9 & 0x3204) == 0)) || (DAT_0300008c < 0x10)) {
          sub_080C08E8(DAT_0300008c,uVar12);
          iVar4 = sub_080F401C(DAT_0300008c);
          if (iVar4 < 1) {
            DAT_0203cb7e = 7;
          }
          else {
            DAT_0203cb7e = 6;
            if (DAT_0300008c < 0x10) {
              uVar7 = sub_080BFFC4(DAT_0300008c);
              uVar8 = sub_080C86B4((int)(short)uVar7);
              if ((short)uVar8 < 0x13) {
                sub_080C8490((int)(short)uVar7);
              }
            }
            else {
              DAT_0203d0c0 = 1;
            }
          }
          if ((uVar12 == 0x2000) && (DAT_0300008c - 4U < 0xc)) {
            sub_080F4190(DAT_0300008c);
            sub_080C366C();
          }
        }
        else {
          if (DAT_030000ae != 1) {
            sub_080F401C(DAT_0300008c);
            goto LAB_080f1f9c;
          }
          DAT_0203cb7e = 9;
        }
      }
      goto LAB_080f1fa0;
    }
    puVar10 = &DAT_0203cb7c;
    goto LAB_080f20a4;
  case 0xb:
    uVar9 = sub_080EA934();
    if ((uVar9 & 0xff) != 1) break;
LAB_080f1e3e:
    DAT_0203cb7e = 0xc;
    break;
  case 0xd:
    uVar9 = sub_080EA934();
    if ((uVar9 & 0xff) == 1) {
      DAT_0203cb7e = DAT_030000ac;
    }
  }
FUN_080f20c6:
                    /* WARNING: Could not recover jumptable at 0x080f20d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_080f20a0 @ 0x080F20A0

void FUN_080f20a0(void)

{
  int unaff_r6;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(unaff_r6 + 0x97c) = 10;
                    /* WARNING: Could not recover jumptable at 0x080f20d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_080f20c6 @ 0x080F20C6

void FUN_080f20c6(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x080f20d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F20E0 @ 0x080F20E0

void sub_080F20E0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint arg1;
  uint local_14;
  
  iVar1 = sub_080F3110(DAT_0300008c);
  if (iVar1 == 0) {
    Battle_BuildNamePrependText(DAT_0300008c + 0x8000,0x81241f0);
    sub_080EA4F8(3);
  }
  else {
    sub_080EA4F8(3);
  }
  DAT_0300008c = DAT_03000088;
  uVar2 = sub_080EDA90();
  arg1 = uVar2 & 0xffff;
  if ((arg1 != 0) && (arg1 != 0xffff)) {
    sub_080EDA7C(0xffff);
    iVar1 = sub_080F3214(DAT_0300008c,arg1);
    if ((iVar1 != 0) &&
       (((uVar2 & 2) == 0 ||
        (iVar1 = sub_080C0148(DAT_0300008c & 0xffff), *(short *)(iVar1 + 0x1e) != 0)))) {
      sub_080EDA7C(arg1);
    }
  }
  iVar1 = sub_080C35E4(DAT_03000088);
  iVar5 = iVar1 * 0x10000 >> 0x10;
  if ((iVar1 * 0x10000 - 0x40000U >> 0x10 < 2) || (iVar5 == 10)) {
    DAT_030000a0 = sub_080EE864(DAT_03000088,DAT_0300008c);
  }
  else if (iVar5 == 8) {
    uVar2 = sub_080F3F14(DAT_03000088);
    local_14 = uVar2;
    sub_080BF468(uVar2,0xc,&local_14);
    sub_080F3EF4(DAT_03000088,local_14 & 0xffff);
    sub_080EE9F8(0x3000088);
    sub_080F3EF4(DAT_03000088,uVar2 & 0xffff);
  }
  else if ((iVar5 == 7) || (iVar5 == 0xb)) {
    sub_080EE9F8(0x3000088);
  }
  if (DAT_030000a0 != 0) {
    uVar3 = sub_080EFE60(DAT_03000088);
    uVar3 = sub_080F3F90(DAT_0300008c,uVar3);
    DAT_030000a0 = sub_080EEEE8(DAT_030000a0,uVar3);
    iVar1 = sub_080F401C(DAT_0300008c);
    if (iVar1 < DAT_030000a0) {
      DAT_030000a0 = sub_080F401C(DAT_0300008c);
    }
    switch(uVar3) {
    case 0xe:
    case 0xf:
      uVar3 = sub_080F401C(DAT_0300008c);
      uVar4 = sub_080F4038(DAT_0300008c);
      if ((int)(short)uVar4 < (short)uVar3 + DAT_030000a0) {
        DAT_030000a0 = (int)(short)uVar4 - (int)(short)uVar3;
      }
      sub_080C0AD4(DAT_0300008c,DAT_030000a0);
    case 0:
      DAT_0203cb7e = 9;
    }
  }
  return;
}


// sub_080F22B4 @ 0x080F22B4

void sub_080F22B4(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar2 = (short)DAT_0300008c;
  if (DAT_030000ae == 1) {
    uVar3 = sub_080EDA90();
    if ((uVar3 & 0xffff) != 0x8000) {
      DAT_030000a0 = 0;
      goto LAB_080f24da;
    }
    iVar4 = sub_080EDAD0();
    if ((iVar4 == 0) || (sVar2 < 0x10)) {
      DAT_030000a0 = sub_080F401C((int)sVar2);
    }
    else {
      iVar4 = sub_080EFE60(DAT_03000088);
      uVar5 = sub_080C07E0(DAT_0300008c);
      iVar6 = sub_080ED494((int)(short)uVar5);
      if ((iVar6 == 0x3f) && (iVar4 == 7)) {
        DAT_030000a0 = sub_080F401C((int)sVar2);
      }
      else {
        if ((iVar6 != 0x3e) || (iVar4 != 8)) goto LAB_080f24da;
        DAT_030000a0 = sub_080F401C((int)sVar2);
      }
      sub_080C08E8(DAT_0300008c,0x8000);
      sub_080EDA7C(0);
    }
  }
  iVar6 = (int)sVar2;
  iVar4 = sub_080F3110(iVar6);
  if (iVar4 == 1) {
    uVar3 = sub_080ED954();
    uVar7 = sub_080ED974(iVar6);
    if (((uVar3 & 0xffff) == 1) && ((uVar7 & 0xffff) == 1)) {
      sub_080E8AFC(1);
    }
    else {
      sub_080E8AFC(0);
    }
    DAT_0203d0ca = 300;
  }
  else {
    sub_080BFFC4(iVar6);
    uVar3 = 0;
    cVar1 = DAT_030050e0;
    while ((cVar1 != iVar6 && (uVar3 = uVar3 + 1 & 0xff, uVar3 < 6))) {
      cVar1 = (&DAT_030050e0)[uVar3];
    }
    if (uVar3 != 6) {
      sub_080C86F4(uVar3);
    }
    DAT_0203d0ca = 299;
  }
  sub_080ECF70((int)DAT_0203d0ca);
  iVar4 = DAT_030000a0;
  iVar8 = sub_080F401C(iVar6);
  iVar9 = sub_080F4038(iVar6);
  sub_080F24F0(iVar6,-DAT_030000a0);
  iVar10 = sub_080F401C(iVar6);
  if (iVar10 < 0) {
    iVar10 = sub_080F401C(iVar6);
    DAT_030000a0 = DAT_030000a0 + iVar10;
    sub_080F4054(iVar6,0);
  }
  if (iVar8 <= iVar9) {
    iVar8 = sub_080F401C(iVar6);
    iVar9 = sub_080F4038(iVar6);
    if (iVar9 < iVar8) {
      uVar5 = sub_080F4038(iVar6);
      sub_080F4054(iVar6,uVar5);
    }
  }
  iVar6 = sub_080F3110(DAT_0300008c);
  if (iVar6 == 1) {
    uVar5 = sub_080F2F64(DAT_0300008c - 0x8000U & 0xffff);
    Battle_BuildDamageDealtText(uVar5,iVar4,0x8123bcc);
    sub_080EA4F8(3);
  }
  else {
    uVar5 = sub_080F2F64(DAT_0300008c - 0x8000U & 0xffff);
    Battle_BuildDamageDealtText(uVar5,iVar4,0x812310c);
    sub_080EA4F8(3);
  }
LAB_080f24da:
                    /* WARNING: Could not recover jumptable at 0x080f24e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F24F0 @ 0x080F24F0

void sub_080F24F0(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  *(short *)(iVar1 + 0x18) = *(short *)(iVar1 + 0x18) + (short)arg1;
  return;
}


// sub_080F2514 @ 0x080F2514

void sub_080F2514(int arg0,undefined4 arg1)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  dword arg0_00;
  int iVar9;
  uint local_24;
  
  iVar9 = (int)(short)arg1;
  local_24 = sub_080F3F14(iVar9);
  uVar4 = sub_080C35E4(iVar9);
  sub_080EFFF8(iVar9,(int)DAT_0203d166);
  uVar5 = sub_080F3110(iVar9);
  if ((uVar4 & 0xffff) == 8) {
    iVar9 = sub_080F3F14(iVar9);
    if (iVar9 == 0xf0) {
      local_24 = (uint)DAT_0203d392;
    }
    else {
      sub_080BF468(local_24,0xc,&local_24);
    }
  }
  iVar9 = sub_080BF5C0(local_24 & 0xffff);
  cVar1 = *(char *)(iVar9 + 2);
  iVar9 = (int)(short)arg1;
  sub_080EFFF8(iVar9,(int)DAT_0203d166);
  sVar3 = (short)uVar5;
  DAT_03000088 = iVar9;
  if ((cVar1 == -0x80) || (cVar1 == -0x7e)) {
    DAT_0300008c = (uint)*(short *)(&DAT_0203d130 + iVar9 * 2);
  }
  else {
    DAT_0300008c = (1 - sVar3) * 0x10;
    if ((local_24 - 0x2b < 0xe) && (sVar3 != 0)) {
      DAT_0300008c = 0x10;
      iVar6 = sub_080ED954();
      if ((iVar6 == 1) && (0x13 < DAT_03000088)) {
        cVar1 = '\0';
        bVar2 = 0x10;
        do {
          iVar6 = sub_080C0830();
          if (iVar6 == 0) {
            cVar1 = cVar1 + '\x01';
          }
          bVar2 = bVar2 + 1;
        } while (bVar2 < 0x14);
        if (cVar1 == '\0') {
          DAT_0300008c = 0x14;
        }
      }
    }
  }
  if ((((short)uVar4 == 8) && (iVar6 = sub_080F3F14(iVar9), iVar6 == 0xf0)) && (local_24 - 0x2b < 2)
     ) {
    DAT_0300008c = (uint)*(byte *)(arg0 + 0xc);
  }
  uVar4 = sub_080C0818(DAT_0300008c);
  sub_080F4988(0x3000088,local_24);
  if (local_24 - 0x3e < 2) {
    if (local_24 == 0x3e) {
      uVar5 = 1;
    }
    else {
      uVar5 = 3;
    }
    uVar4 = sub_080F1678(iVar9,uVar5);
    uVar5 = sub_080EC038(0xe9);
    Menu_ExpandListTemplate(uVar5,(int)(char)(&DAT_030050e0)[uVar4 & 0xffff]);
    sub_080EA4F8(3);
    DAT_0203cb7c = 10;
    sub_080F0344(3,0xc);
    return;
  }
  if (DAT_03000094 != 1) {
    if (DAT_03000090 == 0xffffffff) {
      Menu_ExpandListTemplate(0x8124534,0);
      sub_080EA4F8(3);
    }
    else {
      uVar5 = sub_080EC038(DAT_03000090);
      Menu_ExpandListTemplate(uVar5,0);
      sub_080EA4F8(3);
    }
    DAT_0203cb7c = 10;
    sub_080F0344(3,0xc);
    return;
  }
  if (DAT_03000090 == 0xffffffff) {
    uVar7 = (int)sVar3 + (uint)*(ushort *)(((int)((local_24 - 0x1d) * 0x20000) >> 0xf) + 0x876f9cc);
    if ((uVar7 & 0xffff) == 0xffff) goto LAB_080f272c;
    arg0_00 = uVar7 & 0x7fff;
  }
  else {
    arg0_00 = DAT_03000090 & 0xffff;
  }
  if (arg0_00 != 0xffff) {
    uVar5 = sub_080EC038(arg0_00);
    Menu_ExpandListTemplate(uVar5,DAT_0300008c);
    sub_080EA4F8(3);
    DAT_0203cb7c = 10;
    sub_080F0344(3,0xc);
  }
LAB_080f272c:
  DAT_0203cb7c = 10;
  uVar7 = sub_080C0818(DAT_0300008c);
  if (((uVar4 & 0xffff) != (uVar7 & 0xffff)) && ((int)DAT_0300008c < 0x10)) {
    uVar5 = sub_080BFFC4(DAT_0300008c);
    uVar8 = sub_080C86B4((int)(short)uVar5);
    if ((short)uVar8 < 0x13) {
      sub_080C8490((int)(short)uVar5);
    }
  }
  return;
}


// sub_080F27CC @ 0x080F27CC

void sub_080F27CC(undefined4 arg0,undefined4 arg1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  dword arg0_00;
  int arg0_01;
  uint local_1c;
  
  arg0_01 = (int)(short)arg1;
  local_1c = sub_080F3F14(arg0_01);
  iVar2 = Action_GetRecord(local_1c & 0xffff);
  cVar1 = *(char *)(iVar2 + 3);
  uVar3 = sub_080F3110(arg0_01);
  if (((cVar1 == -0x80) || (cVar1 == -0x7e)) || (cVar1 == -0x7d)) {
    DAT_03000088 = (int)(short)arg1;
    DAT_0300008c = (int)*(short *)(&DAT_0203d130 + DAT_03000088 * 2);
    uVar3 = sub_080C07E0(DAT_0300008c);
    sub_080F40C4((int)(short)uVar3);
  }
  else {
    DAT_0300008c = (1 - (short)uVar3) * 0x10;
    DAT_03000088 = arg0_01;
  }
  uVar4 = sub_080C0818(DAT_0300008c);
  if (local_1c - 0xf1 < 2) {
    DAT_03000088 = (int)(short)arg1;
    DAT_0300008c = (int)*(short *)(DAT_03006434 + DAT_0203d166 * 4 + 0x130);
  }
  sub_080F5C90(0x3000088,local_1c);
  if (local_1c - 0xf1 < 2) {
    if (DAT_03000094 == 1) {
      uVar3 = sub_080EC038(0x123);
      iVar2 = sub_080F3F14((int)(short)arg1);
      Menu_ExpandListTemplate(uVar3,DAT_0300008c + iVar2 * 0x10000);
    }
    else {
      if (DAT_03000094 != 2) {
        DAT_0203cb7c = 10;
        return;
      }
      uVar4 = 0;
      cVar1 = DAT_030050e0;
      while ((cVar1 != DAT_0300008c && (uVar4 = uVar4 + 1 & 0xffff, uVar4 < 6))) {
        cVar1 = (&DAT_030050e0)[uVar4];
      }
      if (uVar4 != 6) {
        sub_080C86F4(uVar4);
      }
      sub_080ECF70(299);
      uVar3 = sub_080F2F64(DAT_0300008c - 0x8000U & 0xffff);
      Battle_BuildDamageDealtText(uVar3,DAT_030000a0,0x812310c);
    }
    sub_080EA4F8(3);
    DAT_0203cb7c = 10;
    sub_080F0344(3,0xc);
    return;
  }
  if (DAT_03000094 != 1) {
    if (DAT_03000090 == 0xffffffff) {
      Menu_ExpandListTemplate(0x8124534,0);
      sub_080EA4F8(3);
    }
    else {
      uVar3 = sub_080EC038(DAT_03000090);
      Menu_ExpandListTemplate(uVar3,0);
      sub_080EA4F8(3);
    }
    DAT_0203cb7c = 10;
    sub_080F0344(3,0xc);
    return;
  }
  sub_080F3E38(local_1c);
  sub_080BF468(local_1c,0xc,&local_1c);
  if (DAT_03000090 == 0xffffffff) {
    arg0_00 = (dword)*(ushort *)(((int)((local_1c - 0x80) * 0x10000) >> 0xf) + 0x876fae4);
    if (arg0_00 == 0x137) {
      iVar2 = sub_080ED9F4();
      if (iVar2 != 0) {
        arg0_00 = 0xffff;
      }
      goto LAB_080f29b4;
    }
  }
  else {
    arg0_00 = DAT_03000090 & 0xffff;
LAB_080f29b4:
    if (arg0_00 == 0x137) {
      uVar3 = sub_080EC038(0x137);
      Menu_ExpandListTemplate(uVar3,DAT_0300008c);
      sub_080EA4F8(3);
      DAT_0203cb7c = 10;
      sub_080F0344(3,0xc);
      goto LAB_080f2a2c;
    }
  }
  if (arg0_00 != 0xffff) {
    uVar3 = sub_080EC038(arg0_00);
    iVar2 = sub_080F3F14((int)(short)arg1);
    Menu_ExpandListTemplate(uVar3,DAT_0300008c + iVar2 * 0x10000);
    sub_080EA4F8(3);
    DAT_0203cb7c = 10;
    sub_080F0344(3,0xc);
  }
LAB_080f2a2c:
  DAT_0203cb7c = 10;
  uVar5 = sub_080C0818(DAT_0300008c);
  if (((uVar4 & 0xffff) != (uVar5 & 0xffff)) && (DAT_0300008c < 0x10)) {
    uVar3 = sub_080BFFC4(DAT_0300008c);
    uVar6 = sub_080C86B4((int)(short)uVar3);
    if ((short)uVar6 < 0x13) {
      sub_080C8490((int)(short)uVar3);
    }
  }
  return;
}


