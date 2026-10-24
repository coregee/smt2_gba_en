/* Ghidra decompilation of asm/code_08145784.s (reference only; not compiled). */

// sub_08145784 @ 0x08145784

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08145784(void)

{
  _DAT_0203a4ea = 1;
  return;
}


// sub_08145794 @ 0x08145794

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08145794(int arg0,int arg1)

{
  int arg0_00;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (arg1 == 0) {
    if (_DAT_0203a4f4 != 0) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    arg0_00 = 1;
    if ((DAT_03003964 & 1) != 0) {
      arg0_00 = sub_081493D4(_DAT_0203a4f4);
    }
    sub_080C51D4(0x159);
    _DAT_0203a4f4 = _DAT_0203a4f4 - arg0_00;
    sub_080C31B4(arg0_00);
    if (_DAT_0203a4f4 == 0) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  return;
}


// sub_081457FC @ 0x081457FC

void sub_081457FC(void)

{
  sub_080AD0FC(0x879ac84,0xffff);
  DAT_0203a454 = 4;
  return;
}


// sub_08145820 @ 0x08145820

void sub_08145820(int arg0)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_r6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_08145290(*(int *)((uint)*(ushort *)(arg0 + 0x24) * 0xc + 0x879ac18) - 1U & 0xffff);
  uVar1 = uVar1 & 0xffff;
  uVar2 = sub_08145290(*(int *)(&DAT_0879ac1c + (uint)*(ushort *)(arg0 + 0x24) * 0xc) - 1U & 0xffff)
  ;
  uVar3 = sub_08145290(*(int *)((uint)*(ushort *)(arg0 + 0x24) * 0xc + 0x879ac20) - 1U & 0xffff);
  if (((uVar1 == 5) && (uVar1 = uVar2 & 0xffff, (uVar2 & 0xffff) == 5)) &&
     (uVar1 = unaff_r6, (uVar3 & 0xffff) != 5)) {
    uVar1 = uVar3 & 0xffff;
  }
  *(undefined4 *)(arg0 + 0x2c) = *(undefined4 *)(uVar1 * 4 + 0x879b53c);
  *(short *)(arg0 + 0x26) = (short)uVar1;
                    /* WARNING: Could not recover jumptable at 0x081458b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081458C0 @ 0x081458C0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081458C0(int arg0)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if ((DAT_03003964 & 1) != 0) {
    iVar2 = sub_081493D4(*(undefined4 *)(arg0 + 0x2c));
  }
  iVar1 = *(int *)(arg0 + 0x2c) - iVar2;
  *(int *)(arg0 + 0x2c) = iVar1;
  _DAT_0203a4f4 = _DAT_0203a4f4 + iVar2;
  if (iVar1 == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_0814590C @ 0x0814590C

void sub_0814590C(int arg0)

{
  sub_08145488(arg0,(uint)*(ushort *)(arg0 + 0x24),0);
  sub_08144868(*(ushort *)(arg0 + 0x26) + 4 & 0xffff,0,0,0);
  return;
}


// sub_08145934 @ 0x08145934

void sub_08145934(int arg0)

{
  if ((DAT_030031bc >> 2 & 1) == 0) {
    sub_08145488(arg0,(uint)*(ushort *)(arg0 + 0x24),1);
    sub_080C51D4(0x15e);
    sub_08144868(*(ushort *)(arg0 + 0x26) + 4 & 0xffff,1,0,0);
  }
  else {
    sub_08145488(arg0,(uint)*(ushort *)(arg0 + 0x24),0);
    sub_08144868(*(ushort *)(arg0 + 0x26) + 4 & 0xffff,0,0,0);
  }
  return;
}


// sub_08145998 @ 0x08145998

void sub_08145998(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x879b550,(uint)*(ushort *)(arg0 + 2));
  *(undefined2 *)(iVar1 + 0x24) = (undefined2)arg1;
  return;
}


// sub_081459B4 @ 0x081459B4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081459B4(int arg0)

{
  undefined4 *puVar1;
  undefined4 in_r1;
  dword dVar2;
  
  if (*(short *)(arg0 + 0x24) == 9) {
    puVar1 = (undefined4 *)(_DAT_0203a4ec * 4 + 0x879b5a0);
    goto LAB_08145a50;
  }
  switch(*(undefined2 *)(arg0 + 0x26)) {
  case 0:
    dVar2 = 0x879b804;
    break;
  case 1:
    dVar2 = 0x879b5c4;
    goto LAB_08145a3a;
  case 2:
    dVar2 = 0x879b664;
LAB_08145a3a:
    puVar1 = (undefined4 *)(((_DAT_0203a4ec + -1) * 5 + (*(ushort *)(arg0 + 0x24) - 4)) * 4 + dVar2)
    ;
LAB_08145a50:
    in_r1 = *puVar1;
    goto switchD_081459e6_default;
  case 3:
    dVar2 = 0x879b704;
    break;
  case 4:
    dVar2 = 0x879b784;
    break;
  default:
    goto switchD_081459e6_default;
  }
  in_r1 = *(undefined4 *)((*(ushort *)(arg0 + 0x24) - 5) * 4 + (_DAT_0203a4ec + -1) * 0x10 + dVar2);
switchD_081459e6_default:
  *(undefined4 *)(arg0 + 0x2c) = in_r1;
  return;
}


// sub_08145A60 @ 0x08145A60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08145A60(int arg0)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if ((DAT_03003964 & 1) != 0) {
    iVar2 = sub_081493D4(*(undefined4 *)(arg0 + 0x2c));
  }
  iVar1 = *(int *)(arg0 + 0x2c) - iVar2;
  *(int *)(arg0 + 0x2c) = iVar1;
  _DAT_0203a4f4 = _DAT_0203a4f4 + iVar2;
  if (iVar1 == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_08145AAC @ 0x08145AAC

void sub_08145AAC(int arg0)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = &DAT_0203a4a0;
  do {
    uVar1 = sub_08145290(uVar3 & 0xffff);
    if ((uVar1 & 0xffff) == (uint)*(ushort *)(arg0 + 0x26)) {
      if ((DAT_030031bc >> 2 & 1) == 0) {
        *(undefined2 *)puVar2 = 1;
      }
      else {
        *(undefined2 *)puVar2 = 0;
      }
    }
    puVar2 = (undefined4 *)((int)puVar2 + 2);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 9);
  if ((DAT_030031bc >> 2 & 1) == 0) {
    sub_08144868(*(ushort *)(arg0 + 0x26) + 9 & 0xffff,1,0,0);
  }
  else {
    sub_08144868(*(ushort *)(arg0 + 0x26) + 9 & 0xffff,0,0,0);
  }
  return;
}


// sub_08145B30 @ 0x08145B30

void sub_08145B30(int arg0)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = &DAT_0203a4a0;
  do {
    *(undefined2 *)puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 2);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 9);
  sub_08144868(*(ushort *)(arg0 + 0x26) + 9 & 0xffff,0,0,0);
  return;
}


// sub_08145B60 @ 0x08145B60

void sub_08145B60(int arg0,uint arg1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar3 = 0;
  do {
    uVar1 = sub_08145290(uVar3 & 0xffff);
    if ((uVar1 & 0xffff) == arg1) {
      uVar4 = uVar4 + 1;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 9);
  switch(arg1) {
  case 0:
  case 3:
  case 4:
    if (uVar4 < 5) goto switchD_08145b90_default;
    break;
  case 1:
  case 2:
    if (uVar4 < 4) goto switchD_08145b90_default;
    break;
  default:
    goto switchD_08145b90_default;
  }
  *(undefined2 *)(arg0 + 0x1c) = 1;
switchD_08145b90_default:
  if (*(short *)(arg0 + 0x1c) == 1) {
    iVar2 = sub_080AD0FC(0x879b884,(uint)*(ushort *)(arg0 + 2));
    *(short *)(iVar2 + 0x26) = (short)arg1;
    *(short *)(iVar2 + 0x24) = (short)uVar4;
  }
  return;
}


// sub_08145BD8 @ 0x08145BD8

void sub_08145BD8(int arg0)

{
  *(undefined4 *)(arg0 + 0x2c) = 200;
  return;
}


// sub_08145BE0 @ 0x08145BE0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08145BE0(int arg0)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if ((DAT_03003964 & 1) != 0) {
    iVar2 = sub_081493D4(*(undefined4 *)(arg0 + 0x2c));
  }
  iVar1 = *(int *)(arg0 + 0x2c) - iVar2;
  *(int *)(arg0 + 0x2c) = iVar1;
  _DAT_0203a4f4 = _DAT_0203a4f4 + iVar2;
  if (iVar1 == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_08145C2C @ 0x08145C2C

void sub_08145C2C(int arg0)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = &DAT_0203a4a0;
  do {
    uVar1 = sub_08145290(uVar3 & 0xffff);
    if ((uVar1 & 0xffff) == (uint)*(ushort *)(arg0 + 0x26)) {
      if ((DAT_030031bc >> 2 & 1) == 0) {
        *(undefined2 *)puVar2 = 1;
      }
      else {
        *(undefined2 *)puVar2 = 0;
      }
    }
    puVar2 = (undefined4 *)((int)puVar2 + 2);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 9);
  return;
}


// sub_08145C7C @ 0x08145C7C

void sub_08145C7C(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = &DAT_0203a4a0;
  do {
    *(undefined2 *)puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 2);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 9);
  return;
}


// sub_08145C98 @ 0x08145C98

void sub_08145C98(int arg0)

{
  int iVar1;
  
  iVar1 = sub_081454CC();
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (iVar1 == 9) {
    iVar1 = sub_080AD0FC(0x879b8d4,(uint)*(ushort *)(arg0 + 2));
    *(undefined2 *)(iVar1 + 0x26) = 6;
    *(undefined2 *)(iVar1 + 0x24) = 9;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_08145CC8 @ 0x08145CC8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 sub_08145CC8(int arg0,int arg1,int arg2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_08145290(arg0 - 1U & 0xffff);
  DAT_0203a500 = (undefined4 *)(uVar1 & 0xffff);
  DAT_0203a50c = DAT_0203a500;
  uVar1 = sub_08145290(arg1 - 1U & 0xffff);
  DAT_0203a504 = (undefined4 *)(uVar1 & 0xffff);
  _DAT_0203a510 = DAT_0203a504;
  uVar1 = sub_08145290(arg2 - 1U & 0xffff);
  puVar4 = &DAT_0203a514;
  DAT_0203a514 = (undefined4 *)(uVar1 & 0xffff);
  puVar2 = DAT_0203a514;
  DAT_0203a508 = DAT_0203a514;
  if (((DAT_0203a500 != (undefined4 *)0x6) && (DAT_0203a504 != (undefined4 *)0x6)) &&
     (DAT_0203a514 != (undefined4 *)0x6)) {
    if (DAT_0203a500 == (undefined4 *)0x5) {
      if (DAT_0203a504 == (undefined4 *)0x5) {
        if (DAT_0203a514 != (undefined4 *)0x5) {
          DAT_0203a518 = DAT_0203a514;
        }
      }
      else {
        DAT_0203a518 = DAT_0203a504;
      }
    }
    else {
      if ((DAT_0203a504 != (undefined4 *)0x5) && (DAT_0203a514 != (undefined4 *)0x5)) {
        if ((DAT_0203a500 == DAT_0203a504) && (DAT_0203a504 == DAT_0203a514)) {
          *(undefined4 **)(&DAT_0203a51c + (arg0 - 1U) * 2) = DAT_0203a50c;
          *(undefined4 **)(&DAT_0203a51c + (arg1 - 1U) * 2) = _DAT_0203a510;
          *(undefined4 **)(&DAT_0203a51c + (arg2 - 1U) * 2) = DAT_0203a514;
          puVar2 = DAT_0203a500;
          goto LAB_08145e34;
        }
        goto LAB_08145e30;
      }
      DAT_0203a518 = DAT_0203a500;
    }
    if (DAT_0203a500 == (undefined4 *)0x5) {
      DAT_0203a500 = DAT_0203a518;
    }
    if (DAT_0203a504 == (undefined4 *)0x5) {
      DAT_0203a504 = DAT_0203a518;
    }
    if (DAT_0203a514 == (undefined4 *)0x5) {
      DAT_0203a508 = DAT_0203a518;
    }
    puVar2 = &DAT_0203a504;
    if ((DAT_0203a500 == DAT_0203a504) && (DAT_0203a500 == DAT_0203a508)) {
      *(undefined4 **)(&DAT_0203a51c + (arg0 + -1) * 2) = DAT_0203a50c;
      *(undefined4 **)(&DAT_0203a51c + (arg1 + -1) * 2) = _DAT_0203a510;
      puVar4 = (undefined4 *)(&DAT_0203a51c + (arg2 + -1) * 2);
      *puVar4 = DAT_0203a514;
      puVar2 = DAT_0203a518;
      goto LAB_08145e34;
    }
  }
LAB_08145e30:
  puVar4 = puVar2;
  puVar2 = (undefined4 *)0xffffffff;
LAB_08145e34:
                    /* WARNING: Could not recover jumptable at 0x08145e42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(puVar2,UNRECOVERED_JUMPTABLE,puVar4,unaff_r8);
  return uVar3;
}


// sub_08145E44 @ 0x08145E44

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08145E44(void)

{
  uint uVar1;
  undefined4 local_18;
  
  uVar1 = 0;
  local_18 = 0;
  CpuSet(&local_18,0x203a454,0x5000200);
  REG_BG0CNT = 0x4008;
  DAT_03000002 = 0;
  DAT_03000040 = 0;
  DAT_0203a454 = 1;
  _DAT_0203a45c = sub_080C31F0();
  _DAT_0203a45c = _DAT_0203a45c * 100;
  DAT_0203a470 = 0x1e;
  DAT_0203a490._0_2_ = 0x154;
  DAT_0203a490._2_2_ = 0x40;
  DAT_0203a494._0_2_ = 0x50;
  DAT_0203a6a2 = 0x3a;
  DAT_0203a6a4 = 0x25;
  DAT_0203a6aa = 0x3a;
  DAT_0203a6ac = 0x4b;
  DAT_0203a6b2 = 0x3a;
  DAT_0203a6b4 = 0x4b;
  DAT_0203a460 = _DAT_0203a45c;
  do {
    (&DAT_0203a6ba)[uVar1 * 6] = 0xfc;
    (&DAT_0203a6bc)[uVar1 * 6] = *(undefined2 *)(uVar1 * 8 + 0x879c8ec);
    (&DAT_0203a6be)[uVar1 * 6] = (&DAT_0879c8f0)[uVar1 * 4];
    (&DAT_0203a6c0)[uVar1 * 6] = (&DAT_0879c8ee)[uVar1 * 4];
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 6);
  uVar1 = 0;
  do {
    *(undefined1 *)(&DAT_0203a49c + uVar1 * 2) = 0;
    *(undefined2 *)(&DAT_0203a4a0 + uVar1 * 2) = 0;
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x40);
  return;
}


// sub_08145F44 @ 0x08145F44

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08145F44(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  short *psVar6;
  char *pcVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a454 == 1) {
    sub_080AD0FC(0x879ca1c,0xffff);
    DAT_0203a454 = 0;
  }
  sub_080AA184(0x8150154,1,0,0);
  sub_080AA184(0x8150184,1,0,0);
  sub_08146FC8(_DAT_0203a45c,0x37,0x39,0);
  sub_08147128(_DAT_0203a464,0xd3,0x20,0);
  sub_08147128(_DAT_0203a468,0xd3,0x39,0);
  sub_08147128(_DAT_0203a46c,0xd3,0x52,0);
  sub_080AA184(*(undefined4 *)((char)DAT_0203a6a0 * 4 + 0x879c820),1,0,0);
  sub_080AA184(*(undefined4 *)((char)DAT_0203a6a8 * 4 + 0x879c84c),1,0,0);
  sub_08146F44();
  if ((((byte)DAT_0203a458 < 4) || ((byte)DAT_0203a458 == 0x18)) || ((byte)DAT_0203a458 == 0x19)) {
    sub_080AA184(0x81501c4,1,0,0);
    sub_08146EFC();
  }
  if ((char)DAT_0203a486 == '\x01') {
    sub_080AA184(0x81503fc,1,0,0);
  }
  if (DAT_0203a488 == '\x01') {
    sub_08147508();
  }
  sub_08147970();
  sub_081483B4();
  if ((DAT_0203a70c == '\x01') && ((byte)DAT_0203a458 == 0)) {
    if (((char)DAT_0203a486 == '\0') && ((DAT_030031b8 & 0x200) != 0)) {
      sub_080C51D4(0x158);
      DAT_0203a458._0_1_ = 99;
    }
    if ((DAT_030031b8 & 0x40) != 0) {
      if (DAT_0203a470 == 0x1e) {
        DAT_0203a470 = 0x50;
      }
      else {
        DAT_0203a470 = DAT_0203a470 - 0x19;
      }
    }
    if ((DAT_030031b8 & 0x80) != 0) {
      if (DAT_0203a470 == 0x50) {
        DAT_0203a470 = 0x1e;
      }
      else {
        DAT_0203a470 = DAT_0203a470 + 0x19;
      }
    }
    if (_DAT_0203a45c != 0) {
      if (DAT_0203a6ba == DAT_0203a6bc) {
        if ((DAT_030031d0 & 4) == 0) {
          if ((DAT_03003964 & 1) != 0) {
            sub_080C51D4(0x160);
            DAT_0203a458._0_1_ = 0x18;
            goto LAB_081461cc;
          }
        }
        else if ((DAT_03003964 & 1) != 0) {
          sub_080C51D4(0x160);
          DAT_0203a458._0_1_ = 0x18;
          uVar2 = (uint)DAT_0203a470;
          uVar4 = 10;
          goto LAB_081461d2;
        }
      }
      else if ((DAT_030031d0 & 4) == 0) {
        if ((DAT_03003964 & 1) != 0) {
          sub_080C51D4(0x160);
          DAT_0203a458._0_1_ = 1;
LAB_081461cc:
          uVar2 = (uint)DAT_0203a470;
          uVar4 = 1;
          goto LAB_081461d2;
        }
      }
      else if ((DAT_03003964 & 1) != 0) {
        sub_080C51D4(0x160);
        DAT_0203a458._0_1_ = 1;
        uVar2 = (uint)DAT_0203a470;
        uVar4 = 10;
LAB_081461d2:
        sub_08147240(uVar2,uVar4,0);
      }
    }
  }
  else if ((byte)DAT_0203a458 == 3) {
    if (((DAT_030031b8 & 0x100) != 0) && (5 < DAT_0203a48a._1_1_)) {
      DAT_0203a458._0_1_ = 4;
    }
    if ((DAT_030031b8 & 0x40) != 0) {
      if (DAT_0203a470 == 0x1e) {
        DAT_0203a470 = 0x50;
      }
      else {
        DAT_0203a470 = DAT_0203a470 - 0x19;
      }
    }
    if ((DAT_030031b8 & 0x80) != 0) {
      if (DAT_0203a470 == 0x50) {
        DAT_0203a470 = 0x1e;
      }
      else {
        DAT_0203a470 = DAT_0203a470 + 0x19;
      }
    }
    if ((DAT_030031d0 & 4) == 0) {
      if ((99 < _DAT_0203a45c) && ((DAT_03003964 & 1) != 0)) {
        sub_080C51D4(0x160);
        sub_08147240((uint)DAT_0203a470,1,0);
      }
      if ((DAT_03003964 & 2) != 0) {
        sub_080C51D4(0x160);
        uVar4 = 1;
        goto LAB_081462cc;
      }
    }
    else {
      if ((999 < _DAT_0203a45c) && ((DAT_03003964 & 1) != 0)) {
        sub_080C51D4(0x160);
        sub_08147240((uint)DAT_0203a470,10,0);
      }
      if ((DAT_03003964 & 2) != 0) {
        sub_080C51D4(0x160);
        uVar4 = 10;
LAB_081462cc:
        sub_08147240((uint)DAT_0203a470,uVar4,1);
        if (((_DAT_0203a464 == 0) && (_DAT_0203a46c == 0)) && (_DAT_0203a468 == 0)) {
          DAT_0203a458._0_1_ = 2;
        }
      }
    }
  }
  switch((byte)DAT_0203a458) {
  case 0:
    if (DAT_0203a70d < 0x29) {
      DAT_0203a70d = DAT_0203a70d + 1;
    }
    else {
      DAT_0203a70c = '\x01';
    }
    break;
  case 1:
    sub_0814746C();
    break;
  case 2:
    sub_081473DC();
    break;
  case 3:
    if (0xc < (byte)DAT_0203a478) {
      sub_080AA184(0x815016c,0,0,0);
    }
    if (0x18 < (byte)DAT_0203a478) {
      DAT_0203a478._0_1_ = 0;
    }
    DAT_0203a478._0_1_ = (byte)DAT_0203a478 + 1;
    if (DAT_0203a48a._1_1_ < 7) {
      uVar2 = 0;
      do {
        (&DAT_0203a6c2)[uVar2 * 0xc] = 1;
        (&DAT_0203a6c3)[uVar2 * 0xc] = 0;
        (&DAT_0203a6ba)[uVar2 * 6] = 0xfc;
        DAT_0203a48a._1_1_ = DAT_0203a48a._1_1_ + 1;
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 6);
    }
    break;
  case 4:
    DAT_0203a6a8 = 0;
    DAT_0203a6a0 = 0;
    DAT_0203a6a9 = 0;
    DAT_0203a6a1 = 0;
    DAT_0203a488 = '\x01';
    DAT_0203a458._0_1_ = 5;
    sub_080C51D4(0x15a);
    break;
  case 5:
    if (DAT_0203a6de == DAT_0203a6e0) {
      DAT_0203a489 = 0;
      sub_080C51D4(0x17c);
      DAT_0203a458._0_1_ = 6;
      break;
    }
    pcVar7 = (char *)&DAT_0203a489;
    (&DAT_0203a6c2)[(uint)DAT_0203a489 * 0xc] = 1;
    psVar6 = &DAT_0203a6ba + (uint)DAT_0203a489 * 6;
    if (*psVar6 < (&DAT_0203a6bc)[(uint)DAT_0203a489 * 6]) break;
    *psVar6 = *psVar6 + -6;
    if ((&DAT_0203a6bc)[(uint)DAT_0203a489 * 6] < (&DAT_0203a6ba)[(uint)DAT_0203a489 * 6]) break;
    (&DAT_0203a6ba)[(uint)DAT_0203a489 * 6] = (&DAT_0203a6bc)[(uint)DAT_0203a489 * 6];
    sub_080C51D4(0x17c);
    goto FUN_08146ed0;
  case 6:
    sub_0814789C();
    break;
  case 7:
    if (_DAT_0203a464 == 0) {
      if (_DAT_0203a468 == 0) {
        if (_DAT_0203a46c == 0) break;
      }
      else if (_DAT_0203a46c == 0) {
        DAT_0203a482._1_1_ = '\x02';
        DAT_0203a458._0_1_ = 9;
        break;
      }
      if (_DAT_0203a468 != 0) {
        DAT_0203a474 = 1;
      }
      DAT_0203a482._1_1_ = '\x01';
      DAT_0203a458._0_1_ = 10;
    }
    else {
      if (_DAT_0203a468 != 0) {
        DAT_0203a474 = 1;
      }
      DAT_0203a482._1_1_ = '\0';
      DAT_0203a458._0_1_ = 8;
    }
    break;
  case 8:
    if (DAT_0203a489 == 3) {
      sub_08147820();
      if (((DAT_030031b8 & 1) != 0) || ((DAT_030031b8 & 0x100) != 0)) {
        DAT_0203a458._0_1_ = 0xb;
      }
      uVar4 = __modsi3((uint)*(byte *)(DAT_0203a6b9 + 0x879c91c) +
                       (uint)*(byte *)(DAT_0203a6d1 + 0x879c91c),10);
      DAT_0203a6a8 = (char)uVar4 + 1;
      break;
    }
    goto LAB_08146b52;
  case 9:
    if (DAT_0203a489 == 4) {
      DAT_0203a458._0_1_ = 0xc;
    }
    else {
      sub_0814760C();
    }
    if (DAT_0203a489 == 3) {
      uVar4 = __modsi3((uint)*(byte *)(DAT_0203a6b9 + 0x879c91c) +
                       (uint)*(byte *)(DAT_0203a6d1 + 0x879c91c),10);
      DAT_0203a6a8 = (char)uVar4 + 1;
    }
    break;
  case 10:
    if (DAT_0203a489 == 2) {
      sub_08147820();
      if (((DAT_030031b8 & 1) != 0) || ((DAT_030031b8 & 0x100) != 0)) {
        DAT_0203a458._0_1_ = 0xb;
      }
      break;
    }
    goto LAB_08146b52;
  case 0xb:
    if (DAT_0203a489 == 4) {
      DAT_0203a458._0_1_ = 0xc;
    }
    else {
      sub_0814760C();
    }
    if (DAT_0203a489 == 3) {
      uVar4 = __modsi3((uint)*(byte *)(DAT_0203a6b9 + 0x879c91c) +
                       (uint)*(byte *)(DAT_0203a6d1 + 0x879c91c),10);
      DAT_0203a6a8 = (char)uVar4 + 1;
    }
    break;
  case 0xc:
    iVar3 = __modsi3((uint)*(byte *)(DAT_0203a6c5 + 0x879c91c) +
                     (uint)*(byte *)(DAT_0203a6dd + 0x879c91c),10);
    iVar3 = iVar3 + 1;
    DAT_0203a6a0 = (byte)iVar3;
    iVar5 = (int)(char)DAT_0203a6a8;
    if ((8 < iVar5) || (8 < iVar3 * 0x1000000 >> 0x18)) {
      if (iVar3 * 0x1000000 >> 0x18 != iVar5) goto switchD_0814696c_caseD_8;
      goto LAB_08146d16;
    }
    if (iVar5 < 7) {
      if (-1 < iVar5) {
        DAT_0203a6a9 = 4;
        DAT_0203a458._0_1_ = 0xd;
      }
      break;
    }
    DAT_0203a489 = 5;
    DAT_0203a6a9 = 5;
    goto LAB_08146a56;
  case 0xd:
    if (DAT_0203a6ea == DAT_0203a6ec) {
      DAT_0203a458._0_1_ = 0xe;
      break;
    }
    (&DAT_0203a6c2)[(uint)DAT_0203a489 * 0xc] = 1;
    goto LAB_08146ad2;
  case 0xe:
    sub_08147820();
    if (((DAT_030031b8 & 1) != 0) || ((DAT_030031b8 & 0x100) != 0)) {
      DAT_0203a458._0_1_ = 0xf;
    }
    break;
  case 0xf:
    if (DAT_0203a489 != 4) {
      DAT_0203a458._0_1_ = 0x10;
      break;
    }
    goto LAB_08146b52;
  case 0x10:
    uVar4 = __modsi3((uint)*(byte *)(DAT_0203a6b9 + 0x879c91c) +
                     (uint)*(byte *)(DAT_0203a6d1 + 0x879c91c) +
                     (uint)*(byte *)(DAT_0203a6e9 + 0x879c91c),10);
    cVar1 = (char)uVar4;
    DAT_0203a6a8 = cVar1 + 1;
    switch((int)((DAT_0203a6a0 - 1) * 0x1000000) >> 0x18) {
    case 0:
switchD_0814696c_caseD_0:
      goto LAB_08146a52;
    case 1:
      goto LAB_08146a52;
    case 2:
LAB_08146a52:
      DAT_0203a6a1 = 4;
LAB_08146a56:
      DAT_0203a458._0_1_ = 0x11;
      goto switchD_081462fa_caseD_1a;
    case 3:
      if ((char)DAT_0203a6a8 < '\t') goto LAB_08146a52;
      DAT_0203a6a1 = 5;
      break;
    case 4:
      if ((byte)(cVar1 - 2U) < 6) goto LAB_08146a52;
      break;
    case 5:
      if ((byte)(cVar1 - 4U) < 4) goto LAB_08146a52;
      DAT_0203a6a1 = 5;
      break;
    case 6:
      if ((byte)(cVar1 - 6U) < 2) goto switchD_0814696c_caseD_0;
      DAT_0203a6a1 = 5;
      break;
    case 7:
      DAT_0203a6a1 = 5;
      break;
    case 8:
    case 9:
switchD_0814696c_caseD_8:
      DAT_0203a458._0_1_ = 0x15;
    default:
      goto switchD_081462fa_caseD_1a;
    }
LAB_08146d16:
    DAT_0203a458._0_1_ = 0x14;
    break;
  case 0x11:
    if (DAT_0203a6f6 == DAT_0203a6f8) {
      DAT_0203a458._0_1_ = 0x12;
      break;
    }
    (&DAT_0203a6c2)[(uint)DAT_0203a489 * 0xc] = 1;
LAB_08146ad2:
    psVar6 = &DAT_0203a6ba + (uint)DAT_0203a489 * 6;
    if ((&DAT_0203a6bc)[(uint)DAT_0203a489 * 6] <= *psVar6) {
      *psVar6 = *psVar6 + -6;
      if ((&DAT_0203a6ba)[(uint)DAT_0203a489 * 6] <= (&DAT_0203a6bc)[(uint)DAT_0203a489 * 6]) {
        (&DAT_0203a6ba)[(uint)DAT_0203a489 * 6] = (&DAT_0203a6bc)[(uint)DAT_0203a489 * 6];
        sub_080C51D4(0x17c);
      }
    }
    break;
  case 0x12:
    sub_08147820();
    if (((DAT_030031b8 & 1) != 0) || ((DAT_030031b8 & 0x100) != 0)) {
      DAT_0203a458._0_1_ = 0x13;
    }
    break;
  case 0x13:
    if (DAT_0203a489 != 5) {
      uVar4 = __modsi3((uint)*(byte *)(DAT_0203a6c5 + 0x879c91c) +
                       (uint)*(byte *)(DAT_0203a6dd + 0x879c91c) +
                       (uint)*(byte *)(DAT_0203a6f5 + 0x879c91c),10);
      DAT_0203a6a0 = (char)uVar4 + 1;
      goto LAB_08146d16;
    }
LAB_08146b52:
    sub_0814760C();
    break;
  case 0x14:
    sub_08148030();
    if ((char)DAT_0203a6a8 < (char)DAT_0203a6a0) {
      DAT_0203a6a1 = 1;
      DAT_0203a484 = 2;
      DAT_0203a6a9 = 2;
      if (DAT_0203a482._1_1_ == '\0') {
        DAT_0203a484 = 1;
      }
    }
    else if ((char)DAT_0203a6a0 < (char)DAT_0203a6a8) {
      DAT_0203a6a1 = 2;
      DAT_0203a6a9 = 1;
      if (DAT_0203a482._1_1_ == '\x01') {
        DAT_0203a484 = 1;
      }
      else {
        DAT_0203a484 = 2;
      }
    }
    else {
      if (DAT_0203a6a0 != DAT_0203a6a8) break;
      DAT_0203a484 = 3;
      DAT_0203a6a9 = 3;
      DAT_0203a6a1 = 3;
    }
    DAT_0203a458._0_1_ = 0x16;
    break;
  case 0x15:
    if ('\b' < (char)DAT_0203a6a0) {
      if (DAT_0203a494._2_1_ < 0xc) {
        sub_080AA184(0x8150254,0,0,0);
      }
      else {
        sub_080AA184(0x81502e4,0,0,0);
      }
      if (0x18 < DAT_0203a494._2_1_) {
        DAT_0203a494._2_1_ = 0;
      }
    }
    if ('\b' < (char)DAT_0203a6a8) {
      if (DAT_0203a494._2_1_ < 0xc) {
        sub_080AA184(0x8150254,0,0,0);
      }
      else {
        sub_080AA184(0x81502e4,0,0,0);
      }
      if (0x18 < DAT_0203a494._2_1_) {
        DAT_0203a494._2_1_ = 0;
      }
    }
    pcVar7 = (char *)((int)&DAT_0203a494 + 3);
    if (DAT_0203a494._3_1_ == 'T') {
      DAT_0203a494._3_1_ = '\0';
      sub_080C51D4(0x181);
      goto LAB_08146d16;
    }
    DAT_0203a494._2_1_ = DAT_0203a494._2_1_ + 1;
    goto LAB_08146e7a;
  case 0x16:
    sub_08147A90();
    break;
  case 0x17:
    sub_081471CC();
    break;
  case 0x18:
    uVar2 = 2;
    do {
      if ((&DAT_0203a6c3)[uVar2 * 0xc] == '\x01') {
        psVar6 = &DAT_0203a6ba + uVar2 * 6;
        if (*psVar6 != (&DAT_0203a6be)[uVar2 * 6]) {
          *psVar6 = *psVar6 + -2;
        }
        if ((&DAT_0203a6ba)[(DAT_0203a489 - 1) * 6] == (&DAT_0203a6be)[uVar2 * 6]) {
          DAT_0203a458._0_1_ = 0x19;
        }
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 6);
    if (0xc < (byte)DAT_0203a478) {
      sub_080AA184(0x815016c,0,0,0);
    }
    if (0x18 < (byte)DAT_0203a478) {
      DAT_0203a478._0_1_ = 0;
    }
    DAT_0203a478._0_1_ = (byte)DAT_0203a478 + 1;
    break;
  case 0x19:
    uVar2 = 0;
    pcVar7 = (char *)&DAT_0203a478;
    do {
      if ((&DAT_0203a6c3)[uVar2 * 0xc] == '\x01') {
        psVar6 = &DAT_0203a6ba + uVar2 * 6;
        if (-0x1f < *psVar6) {
          *psVar6 = *psVar6 + -4;
        }
        if ((&DAT_0203a6ba)[(DAT_0203a489 - 1) * 6] < -0x1d) {
          DAT_0203a489 = 0;
          DAT_0203a48a._1_1_ = 0;
          DAT_0203a458._0_1_ = 1;
        }
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 6);
    if (0xc < (byte)DAT_0203a478) {
      sub_080AA184(0x815016c,0,0,0);
    }
    if (0x18 < (byte)DAT_0203a478) {
      DAT_0203a478._0_1_ = 0;
    }
LAB_08146e7a:
    *pcVar7 = *pcVar7 + '\x01';
    break;
  case 99:
    if (5 < DAT_0203a476._1_1_) {
      uVar4 = __udivsi3(_DAT_0203a45c,100);
      sub_080C31FC(uVar4);
      sub_080BE4C4();
      break;
    }
    pcVar7 = (char *)&DAT_0203a478;
    if (3 < (byte)DAT_0203a478) {
      sub_080AA184(0x815019c,0,0,0);
    }
    if (6 < (byte)DAT_0203a478) {
      DAT_0203a478._0_1_ = 0;
      DAT_0203a476._1_1_ = DAT_0203a476._1_1_ + 1;
    }
FUN_08146ed0:
    *pcVar7 = *pcVar7 + '\x01';
  }
switchD_081462fa_caseD_1a:
                    /* WARNING: Could not recover jumptable at 0x08146efa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_08146ed0 @ 0x08146ED0

void FUN_08146ed0(void)

{
  char *unaff_r4;
  code *UNRECOVERED_JUMPTABLE;
  
  *unaff_r4 = *unaff_r4 + '\x01';
                    /* WARNING: Could not recover jumptable at 0x08146efa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// caseD_1a @ 0x08146EEC

void switchD_081462fa::caseD_1a(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x08146efa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08146EFC @ 0x08146EFC

void sub_08146EFC(void)

{
  if (0xc < DAT_0203a478._1_1_) {
    sub_080AA184(0x81501dc,0,0,0);
  }
  if (0x18 < DAT_0203a478._1_1_) {
    DAT_0203a478._1_1_ = 0;
  }
  DAT_0203a478._1_1_ = DAT_0203a478._1_1_ + 1;
  return;
}


// sub_08146F44 @ 0x08146F44

void sub_08146F44(void)

{
  dword arg0;
  
  if (DAT_0203a478._2_1_ < 0xd) {
    arg0 = 0x81501ac;
  }
  else {
    if (0xb < (byte)(DAT_0203a478._2_1_ - 0xd)) {
      if ((byte)(DAT_0203a478._2_1_ - 0x19) < 8) {
        sub_080AA184(0x8150464,1,0,0);
        DAT_0203a478._2_1_ = 0;
      }
      goto LAB_08146fb2;
    }
    arg0 = 0x8150454;
  }
  sub_080AA184(arg0,1,0,0);
LAB_08146fb2:
  DAT_0203a478._2_1_ = DAT_0203a478._2_1_ + 1;
  return;
}


// sub_08146FC8 @ 0x08146FC8

void sub_08146FC8(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  byte *pbVar1;
  uint arg3_00;
  
  arg3_00 = arg3 & 0xffff;
  pbVar1 = (byte *)sub_080A9CC0(arg0);
  sub_080AA184(*(undefined4 *)((uint)*pbVar1 * 4 + 0x879c7f4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[1] * 4 + 0x879c7f4),0,0,arg3_00);
  sub_080AA184(&DAT_0814ffbc,0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[2] * 4 + 0x879c7f4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[3] * 4 + 0x879c7f4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[4] * 4 + 0x879c7f4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[5] * 4 + 0x879c7f4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[6] * 4 + 0x879c7f4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[7] * 4 + 0x879c7f4),0,0,arg3_00);
  return;
}


// sub_08147128 @ 0x08147128

void sub_08147128(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  byte *pbVar1;
  uint arg3_00;
  
  arg3_00 = arg3 & 0xffff;
  pbVar1 = (byte *)sub_080A9CC0(arg0);
  sub_080AA184(*(undefined4 *)((uint)*pbVar1 * 4 + 0x879c7f4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[1] * 4 + 0x879c7f4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[2] * 4 + 0x879c7f4),0,0,arg3_00);
  return;
}


// sub_081471CC @ 0x081471CC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081471CC(void)

{
  if ((DAT_030031bc & 3) == 0) {
    if (DAT_0203a460 == _DAT_0203a45c) {
      DAT_0203a458._0_1_ = 2;
    }
    else if (_DAT_0203a45c < 0x5f5e09c) {
      if (DAT_0203a482._1_1_ == '\0') {
        _DAT_0203a45c = _DAT_0203a45c + 0x37;
      }
      else {
        _DAT_0203a45c = _DAT_0203a45c + 500;
      }
      if (DAT_0203a460 <= _DAT_0203a45c) {
        _DAT_0203a45c = DAT_0203a460;
      }
    }
    else {
      sub_080C51D4(0x159);
      _DAT_0203a45c = 0x5f5e09c;
      DAT_0203a458._0_1_ = 99;
    }
  }
  return;
}


// sub_08147240 @ 0x08147240

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08147240(undefined4 arg0,uint arg1,undefined4 arg2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = arg1 & 0xffff;
  if ((byte)arg0 == 0x37) {
    if (((char)arg2 == '\0') && (_DAT_0203a468 < 100)) {
      if ((_DAT_0203a468 < 0x5a) || (uVar3 != 10)) {
        iVar4 = uVar3 * -100;
        uVar1 = uVar3;
LAB_08147350:
        _DAT_0203a468 = _DAT_0203a468 + uVar1;
        _DAT_0203a45c = _DAT_0203a45c + iVar4;
      }
      else {
        _DAT_0203a45c = _DAT_0203a45c + (100 - _DAT_0203a468) * -100;
        _DAT_0203a468 = 100;
      }
    }
    else if (((char)arg2 == '\x01') && (_DAT_0203a468 != 0)) {
      if ((10 < _DAT_0203a468) || (uVar3 != 10)) {
        uVar1 = -uVar3;
        iVar4 = uVar3 * 100;
        goto LAB_08147350;
      }
      _DAT_0203a45c = _DAT_0203a45c + _DAT_0203a468 * 100;
      _DAT_0203a468 = 0;
    }
    goto LAB_081473d0;
  }
  if (0x37 < (byte)arg0) {
    if ((byte)arg0 != 0x50) goto LAB_081473d4;
    if ((((char)arg2 == '\0') && (_DAT_0203a46c < 100)) && ((char)DAT_0203a472 == '\0')) {
      if ((_DAT_0203a46c < 0x5a) || (uVar3 != 10)) {
        _DAT_0203a46c = _DAT_0203a46c + uVar3;
      }
      else {
        uVar3 = 100 - _DAT_0203a46c;
        _DAT_0203a46c = 100;
      }
      _DAT_0203a45c = _DAT_0203a45c + uVar3 * -100;
      cVar2 = '\x01';
LAB_081473ce:
      DAT_0203a472._1_1_ = cVar2;
    }
    else if ((((char)arg2 == '\x01') && (_DAT_0203a46c != 0)) && ((char)DAT_0203a472 == '\0')) {
      if ((_DAT_0203a46c < 0xb) && (uVar3 == 10)) {
        uVar1 = 0;
        uVar3 = _DAT_0203a46c;
      }
      else {
        uVar1 = _DAT_0203a46c - uVar3;
      }
      _DAT_0203a46c = uVar1;
      _DAT_0203a45c = _DAT_0203a45c + uVar3 * 100;
      cVar2 = '\0';
      if (_DAT_0203a46c == 0) goto LAB_081473ce;
    }
    goto LAB_081473d0;
  }
  if ((byte)arg0 != 0x1e) goto LAB_081473d4;
  if ((((char)arg2 == '\0') && (_DAT_0203a464 < 100)) && (DAT_0203a472._1_1_ == '\0')) {
    if ((_DAT_0203a464 < 0x5a) || (uVar3 != 10)) {
      _DAT_0203a464 = _DAT_0203a464 + uVar3;
    }
    else {
      uVar3 = 100 - _DAT_0203a464;
      _DAT_0203a464 = 100;
    }
    _DAT_0203a45c = _DAT_0203a45c + uVar3 * -100;
    cVar2 = '\x01';
LAB_081472ea:
    DAT_0203a472._0_1_ = cVar2;
  }
  else if ((((char)arg2 == '\x01') && (_DAT_0203a464 != 0)) && (DAT_0203a472._1_1_ == '\0')) {
    if ((_DAT_0203a464 < 0xb) && (uVar3 == 10)) {
      uVar1 = 0;
      uVar3 = _DAT_0203a464;
    }
    else {
      uVar1 = _DAT_0203a464 - uVar3;
    }
    _DAT_0203a464 = uVar1;
    _DAT_0203a45c = _DAT_0203a45c + uVar3 * 100;
    cVar2 = '\0';
    if (_DAT_0203a464 == 0) goto LAB_081472ea;
  }
LAB_081473d0:
  DAT_0203a460 = _DAT_0203a45c;
LAB_081473d4:
                    /* WARNING: Could not recover jumptable at 0x081473d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081473DC @ 0x081473DC

void sub_081473DC(void)

{
  dword arg0;
  
  DAT_0203a486._0_1_ = 0;
  if (DAT_0203a485 < 4) {
    arg0 = 0x8150414;
  }
  else if ((byte)(DAT_0203a485 - 4) < 3) {
    arg0 = 0x815042c;
  }
  else {
    if (2 < (byte)(DAT_0203a485 - 7)) {
      if (9 < DAT_0203a485) {
        DAT_0203a485 = 0;
        DAT_0203a486._0_1_ = 0;
        DAT_0203a458._0_1_ = 0;
      }
      goto LAB_08147458;
    }
    arg0 = 0x8150444;
  }
  sub_080AA184(arg0,1,0,0);
LAB_08147458:
  DAT_0203a485 = DAT_0203a485 + 1;
  return;
}


// sub_0814746C @ 0x0814746C

void sub_0814746C(void)

{
  dword arg0;
  
  if (DAT_0203a485 < 4) {
    arg0 = 0x8150444;
  }
  else if ((byte)(DAT_0203a485 - 4) < 3) {
    arg0 = 0x815042c;
  }
  else {
    if (2 < (byte)(DAT_0203a485 - 7)) {
      if (9 < DAT_0203a485) {
        sub_080AA184(0x81503fc,1,0,0);
        DAT_0203a485 = 0;
        DAT_0203a486._0_1_ = 1;
        DAT_0203a458._0_1_ = 3;
      }
      goto LAB_081474f2;
    }
    arg0 = 0x8150414;
  }
  sub_080AA184(arg0,1,0,0);
LAB_081474f2:
  DAT_0203a485 = DAT_0203a485 + 1;
  return;
}


// sub_08147508 @ 0x08147508

void sub_08147508(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = uVar2 * 0xc;
    if ((&DAT_0203a6c2)[iVar1] == '\x01') {
      sub_080AA184(0x8150348,0,0,0);
    }
    if ((&DAT_0203a6c3)[iVar1] == '\x01') {
      if (((&DAT_0203a6b8)[iVar1] == '\x01') || ((&DAT_0203a6b8)[iVar1] == '\x03')) {
        sub_080AA184(*(undefined4 *)(uVar2 * 4 + 0x879c8d4),0,0,0);
      }
      if (((&DAT_0203a6b8)[uVar2 * 0xc] == '\0') || ((&DAT_0203a6b8)[uVar2 * 0xc] == '\x02')) {
        sub_080AA184(*(undefined4 *)(uVar2 * 4 + 0x879c8d4),0,1,0);
      }
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 6);
  return;
}


// sub_0814760C @ 0x0814760C

void sub_0814760C(void)

{
  dword arg0;
  
  (&DAT_0203a6c2)[(uint)DAT_0203a489 * 0xc] = 0;
  if ((byte)DAT_0203a48a < 7) {
    arg0 = 0x8150348;
  }
  else if ((byte)((byte)DAT_0203a48a - 7) < 6) {
    arg0 = 0x8150384;
  }
  else if ((byte)((byte)DAT_0203a48a - 0xd) < 6) {
    arg0 = 0x815039c;
  }
  else if ((byte)((byte)DAT_0203a48a - 0x13) < 6) {
    arg0 = 0x81503b4;
  }
  else if ((byte)((byte)DAT_0203a48a - 0x19) < 6) {
    arg0 = 0x81503cc;
  }
  else {
    if (5 < (byte)((byte)DAT_0203a48a - 0x1f)) {
      if (0x24 < (byte)DAT_0203a48a) {
        sub_080C51D4(0x17c);
        DAT_0203a48a._0_1_ = 0;
        (&DAT_0203a6c3)[(uint)DAT_0203a489 * 0xc] = 1;
        DAT_0203a489 = DAT_0203a489 + 1;
      }
      goto LAB_0814780a;
    }
    arg0 = 0x81503e4;
  }
  sub_080AA184(arg0,0,0,0);
LAB_0814780a:
  DAT_0203a48a._0_1_ = (byte)DAT_0203a48a + 1;
  return;
}


// sub_08147820 @ 0x08147820

void sub_08147820(void)

{
  if (0xc < (byte)DAT_0203a478) {
    sub_080AA184(0x8150360,0,0,0);
    sub_080C51D4(0x17e);
  }
  if (0x18 < (byte)DAT_0203a478) {
    DAT_0203a478._0_1_ = 0;
  }
  DAT_0203a478._0_1_ = (byte)DAT_0203a478 + 1;
  return;
}


// sub_0814789C @ 0x0814789C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814789C(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  DAT_0203a482._0_1_ = '\0';
  uVar1 = sub_080C2244();
  DAT_0203a47c._0_2_ = (ushort)uVar1 & 0xff;
  uVar1 = __divsi3((uint)(ushort)DAT_0203a47c,0x55);
  DAT_0203a47c._0_2_ = (ushort)uVar1;
  uVar1 = sub_080C2244();
  DAT_0203a47c._2_2_ = (ushort)uVar1 & 0xff;
  uVar2 = __divsi3((uint)DAT_0203a47c._2_2_ * 0xc,0xff);
  DAT_0203a47c._2_2_ = (ushort)uVar2;
  uVar3 = 0;
  do {
    if (((byte)(&DAT_0203a6b8)[uVar3 * 0xc] == (ushort)DAT_0203a47c) &&
       ((uint)(byte)(&DAT_0203a6b9)[uVar3 * 0xc] == (uVar2 & 0xffff))) {
      DAT_0203a482._0_1_ = '\x01';
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 6);
  if ((char)DAT_0203a482 == '\0') {
    (&DAT_0203a6b8)[(uint)_DAT_0203a480 * 0xc] = (char)(ushort)DAT_0203a47c;
    (&DAT_0203a6b9)[(uint)_DAT_0203a480 * 0xc] = (char)DAT_0203a47c._2_2_;
    iVar4 = (uint)_DAT_0203a480 * 0xc;
    sub_08148510((uint)_DAT_0203a480,(uint)(byte)(&DAT_0203a6b8)[iVar4],
                 (uint)(byte)(&DAT_0203a6b9)[iVar4]);
    _DAT_0203a480 = _DAT_0203a480 + 1;
  }
  if (_DAT_0203a480 == 6) {
    _DAT_0203a480 = 0;
    DAT_0203a458._0_1_ = 7;
  }
  return;
}


// sub_08147970 @ 0x08147970

void sub_08147970(void)

{
  dword dVar1;
  
  switch(DAT_0203a6a1) {
  case 1:
    dVar1 = 0x8150284;
    break;
  case 2:
    dVar1 = 0x815029c;
    break;
  case 3:
    dVar1 = 0x81502cc;
    break;
  case 4:
    dVar1 = 0x81502b4;
    break;
  case 5:
    sub_080AA184(0x81502fc,1,0,0);
  default:
    goto switchD_0814798a_default;
  }
  sub_080AA184(dVar1,1,0,0);
switchD_0814798a_default:
  switch(DAT_0203a6a9) {
  case 1:
    dVar1 = 0x8150284;
    break;
  case 2:
    dVar1 = 0x815029c;
    break;
  case 3:
    dVar1 = 0x81502cc;
    break;
  case 4:
    dVar1 = 0x81502b4;
    break;
  case 5:
    sub_080AA184(0x81502fc,1,0,0);
  default:
    goto LAB_08147a84;
  }
  sub_080AA184(dVar1,1,0,0);
LAB_08147a84:
  return;
}


// sub_08147A90 @ 0x08147A90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08147A90(void)

{
  ushort uVar1;
  
  if ((DAT_0203a48c._2_2_ == 0) && ((ushort)DAT_0203a490 < 0xa3)) {
    DAT_0203a48c._1_1_ = '\x01';
    if ((DAT_0203a484 == '\x01') || ((DAT_0203a484 == '\x03' && (DAT_0203a474 == '\x01')))) {
      sub_080C51D4(0x15e);
    }
    else {
      sub_080C51D4(0x163);
    }
  }
  if ((DAT_0203a48c._1_1_ == '\x01') &&
     (DAT_0203a48c._2_2_ = DAT_0203a48c._2_2_ + 1, DAT_0203a48c._2_2_ == 0x14)) {
    DAT_0203a48c._1_1_ = '\0';
  }
  if ((DAT_0203a484 == '\x01') || ((DAT_0203a484 == '\x03' && (DAT_0203a474 == '\x01')))) {
    sub_080AA184(0x8150314,0,0,0);
  }
  else {
    sub_080AA184(0x8150330,0,0,0);
  }
  if (DAT_0203a484 == '\x01') {
    if (0xc < DAT_0203a494._2_1_) {
      if (DAT_0203a6a1 == '\x01') {
        sub_080AA184(0x81501f4,1,0,0);
      }
      else if (DAT_0203a6a9 == '\x01') {
        sub_080AA184(0x81501f4,1,0,0);
      }
    }
    if (0x18 < DAT_0203a494._2_1_) {
      DAT_0203a494._2_1_ = 0;
    }
  }
  else if (DAT_0203a484 == '\x03') {
    if (0xc < DAT_0203a494._2_1_) {
      sub_080AA184(0x815023c,1,0,0);
      sub_080AA184(0x815023c,1,0,0);
    }
    if (0x18 < DAT_0203a494._2_1_) {
      DAT_0203a494._2_1_ = 0;
    }
  }
  if ((short)DAT_0203a498 == 0x3d) {
    DAT_0300000c = DAT_0203a69c;
    if (DAT_0203a69c == 0xf) {
      sub_0814837C();
      DAT_0300000c = DAT_0300000c - DAT_0203a69c;
      DAT_0203a69c = 0;
      DAT_0203a498._0_2_ = (short)DAT_0203a498 + -4;
    }
    else {
      DAT_0203a69c = DAT_0203a69c + 1;
    }
  }
  else if (DAT_0203a6a0 == DAT_0203a6a8) {
    sub_08147F68();
  }
  else if (DAT_0203a6a8 < DAT_0203a6a0) {
    sub_08147DB8();
  }
  else if (DAT_0203a6a0 < DAT_0203a6a8) {
    sub_08147E90();
  }
  uVar1 = (ushort)DAT_0203a490;
  if (((ushort)DAT_0203a490 != 0) || ((char)DAT_0203a48c != '\x01')) goto LAB_08147d8e;
  DAT_0203a490._0_2_ = 0x154;
  DAT_0203a48c._2_2_ = uVar1;
  DAT_0203a6a2 = 0x3a;
  DAT_0203a6a4 = 0x25;
  DAT_0203a6aa = 0x3a;
  DAT_0203a6ac = 0x4b;
  DAT_0203a6b2 = 0x3a;
  DAT_0203a6b4 = 0x4b;
  DAT_0203a472._1_1_ = 0;
  DAT_0203a472._0_1_ = 0;
  DAT_0203a48c._0_1_ = '\0';
  if (DAT_0203a484 == '\x01') {
    if (DAT_0203a482._1_1_ == '\0') {
      _DAT_0203a46c = _DAT_0203a464 * 0xc3;
LAB_08147d1e:
      DAT_0203a460 = DAT_0203a460 + _DAT_0203a46c;
    }
    else if (DAT_0203a482._1_1_ == '\x01') {
      _DAT_0203a46c = _DAT_0203a46c * 200;
      goto LAB_08147d1e;
    }
    DAT_0203a458._0_1_ = 0x17;
  }
  else if (DAT_0203a484 == '\x03') {
    if ((DAT_0203a482._1_1_ == '\x02') || (DAT_0203a474 == '\x01')) {
      DAT_0203a460 = DAT_0203a460 + _DAT_0203a468 * 900 + (_DAT_0203a464 + _DAT_0203a46c) * 100;
    }
    DAT_0203a458._0_1_ = 0x17;
  }
  else {
    DAT_0203a460 = _DAT_0203a45c;
    DAT_0203a458._0_1_ = 2;
  }
  _DAT_0203a46c = 0;
  DAT_0203a474 = '\0';
  _DAT_0203a464 = _DAT_0203a46c;
  _DAT_0203a468 = _DAT_0203a46c;
LAB_08147d8e:
  if ((DAT_0203a48c._1_1_ == '\0') && ((ushort)DAT_0203a490 != 0)) {
    DAT_0203a490._0_2_ = (ushort)DAT_0203a490 - 4;
  }
  DAT_0203a494._2_1_ = DAT_0203a494._2_1_ + 1;
  return;
}


// sub_08147DB8 @ 0x08147DB8

void sub_08147DB8(void)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  
  sub_080AA184(*(undefined4 *)(DAT_0203a6a0 * 4 + 0x879c820),0,0,0);
  iVar1 = ((ushort)DAT_0203a498 - 1) * 4;
  uVar2 = (uint)*(short *)(iVar1 + 0x879c92c);
  if (uVar2 == DAT_0203a6a2) {
    if ((int)(uint)DAT_0203a6a4 <= (int)*(short *)(&DAT_0879c92e + iVar1)) {
      DAT_0203a6a4 = DAT_0203a6a4 + 3;
      iVar1 = ((ushort)DAT_0203a498 - 1) * 4;
      if ((int)*(short *)(&DAT_0879c92e + iVar1) <= (int)(uint)DAT_0203a6a4) {
        DAT_0203a6a4 = *(ushort *)(&DAT_0879c92e + iVar1);
        *(undefined1 *)(&DAT_0203a49c + ((ushort)DAT_0203a498 - 1) * 2) = 1;
        DAT_0203a48c._0_1_ = 1;
      }
    }
  }
  else {
    if ((int)(uint)DAT_0203a6a2 < (int)uVar2) {
      puVar3 = (ushort *)(((ushort)DAT_0203a498 - 1) * 4 + 0x879c92c);
      if ((int)(uint)(ushort)(DAT_0203a6a2 + 3) < (int)(short)*puVar3) {
        DAT_0203a6a2 = DAT_0203a6a2 + 3;
        return;
      }
    }
    else {
      puVar3 = (ushort *)(((ushort)DAT_0203a498 - 1) * 4 + 0x879c92c);
      if ((int)(short)*puVar3 < (int)(uint)(ushort)(DAT_0203a6a2 - 3)) {
        DAT_0203a6a2 = DAT_0203a6a2 - 3;
        return;
      }
    }
    DAT_0203a6a2 = *puVar3;
  }
  return;
}


// sub_08147E90 @ 0x08147E90

void sub_08147E90(void)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  
  sub_080AA184(*(undefined4 *)(DAT_0203a6a8 * 4 + 0x879c84c),0,0,0);
  iVar1 = ((ushort)DAT_0203a498 - 1) * 4;
  uVar2 = (uint)*(short *)(iVar1 + 0x879c92c);
  if (uVar2 == DAT_0203a6aa) {
    if ((int)(uint)DAT_0203a6ac <= (int)*(short *)(&DAT_0879c92e + iVar1)) {
      DAT_0203a6ac = DAT_0203a6ac + 3;
      iVar1 = ((ushort)DAT_0203a498 - 1) * 4;
      if ((int)*(short *)(&DAT_0879c92e + iVar1) <= (int)(uint)DAT_0203a6ac) {
        DAT_0203a6ac = *(ushort *)(&DAT_0879c92e + iVar1);
        *(undefined1 *)(&DAT_0203a49c + ((ushort)DAT_0203a498 - 1) * 2) = 1;
        DAT_0203a48c._0_1_ = 1;
      }
    }
  }
  else {
    if ((int)(uint)DAT_0203a6aa < (int)uVar2) {
      puVar3 = (ushort *)(((ushort)DAT_0203a498 - 1) * 4 + 0x879c92c);
      if ((int)(uint)(ushort)(DAT_0203a6aa + 3) < (int)(short)*puVar3) {
        DAT_0203a6aa = DAT_0203a6aa + 3;
        return;
      }
    }
    else {
      puVar3 = (ushort *)(((ushort)DAT_0203a498 - 1) * 4 + 0x879c92c);
      if ((int)(short)*puVar3 < (int)(uint)(ushort)(DAT_0203a6aa - 3)) {
        DAT_0203a6aa = DAT_0203a6aa - 3;
        return;
      }
    }
    DAT_0203a6aa = *puVar3;
  }
  return;
}


// sub_08147F68 @ 0x08147F68

void sub_08147F68(void)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  
  sub_080AA184(&DAT_0815012c,0,0,0);
  iVar1 = ((ushort)DAT_0203a498 - 1) * 4;
  uVar2 = (uint)*(short *)(iVar1 + 0x879c92c);
  if (uVar2 == DAT_0203a6b2) {
    if ((int)(uint)DAT_0203a6b4 <= (int)*(short *)(&DAT_0879c92e + iVar1)) {
      DAT_0203a6b4 = DAT_0203a6b4 + 3;
      iVar1 = ((ushort)DAT_0203a498 - 1) * 4;
      if ((int)*(short *)(&DAT_0879c92e + iVar1) <= (int)(uint)DAT_0203a6b4) {
        DAT_0203a6b4 = *(ushort *)(&DAT_0879c92e + iVar1);
        *(undefined1 *)(&DAT_0203a49c + ((ushort)DAT_0203a498 - 1) * 2) = 1;
        DAT_0203a48c._0_1_ = 1;
      }
    }
  }
  else {
    if ((int)(uint)DAT_0203a6b2 < (int)uVar2) {
      puVar3 = (ushort *)(((ushort)DAT_0203a498 - 1) * 4 + 0x879c92c);
      if ((int)(uint)(ushort)(DAT_0203a6b2 + 3) < (int)(short)*puVar3) {
        DAT_0203a6b2 = DAT_0203a6b2 + 3;
        return;
      }
    }
    else {
      puVar3 = (ushort *)(((ushort)DAT_0203a498 - 1) * 4 + 0x879c92c);
      if ((int)(short)*puVar3 < (int)(uint)(ushort)(DAT_0203a6b2 - 3)) {
        DAT_0203a6b2 = DAT_0203a6b2 - 3;
        return;
      }
    }
    DAT_0203a6b2 = *puVar3;
  }
  return;
}


// sub_08148030 @ 0x08148030

void sub_08148030(void)

{
  ushort uVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  
  if ((ushort)DAT_0203a498 == 0) {
    if (DAT_0203a6a0 == DAT_0203a6a8) {
      DAT_0203a4a0._0_2_ = 0x16;
    }
    else if (DAT_0203a6a8 < DAT_0203a6a0) {
      DAT_0203a4a0._0_2_ = (short)DAT_0203a6a0;
    }
    else if (DAT_0203a6a0 < DAT_0203a6a8) {
      DAT_0203a4a0._0_2_ = DAT_0203a6a8 + 0xb;
    }
    DAT_0203a498._0_2_ = 1;
    DAT_0203a498._2_2_ = 1;
    return;
  }
  if (DAT_0203a6a8 == DAT_0203a6a0) {
    *(undefined2 *)(&DAT_0203a4a0 + (uint)(ushort)DAT_0203a498 * 2) = 0x16;
    DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 1;
    DAT_0203a498._2_2_ = 1;
    return;
  }
  uVar4 = (uint)(ushort)DAT_0203a498;
  uVar1 = *(ushort *)(&DAT_0203a4a0 + (uVar4 - DAT_0203a498._2_2_) * 2);
  if (uVar1 == 0x16) {
    iVar2 = (uVar4 - DAT_0203a498._2_2_) + -1;
    if (iVar2 < 0) {
      if (DAT_0203a6a8 < DAT_0203a6a0) {
        *(short *)(&DAT_0203a4a0 + uVar4 * 2) = (short)DAT_0203a6a0;
      }
      else if (DAT_0203a6a0 < DAT_0203a6a8) {
        *(short *)(&DAT_0203a4a0 + uVar4 * 2) = DAT_0203a6a8 + 0xb;
      }
      else if (DAT_0203a6a0 == DAT_0203a6a8) {
        *(undefined2 *)(&DAT_0203a4a0 + uVar4 * 2) = 0x16;
      }
      DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 1;
      DAT_0203a498._2_2_ = 1;
      return;
    }
    if (0xb < *(ushort *)(&DAT_0203a4a0 + iVar2 * 2)) {
      if (DAT_0203a6a0 < DAT_0203a6a8) {
        *(short *)(&DAT_0203a4a0 + uVar4 * 2) = DAT_0203a6a8 + 0xb;
        DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 1;
        DAT_0203a498._2_2_ = 1;
        return;
      }
      uVar5 = uVar4 & 3;
      if (uVar5 == 1) {
        iVar2 = (uVar4 + 3) * 8 + 0x203a454;
        sVar3 = (short)DAT_0203a6a0;
        goto LAB_08148320;
      }
      if (uVar5 == 1 || ((ushort)DAT_0203a498 & 3) == 0) {
        if (((ushort)DAT_0203a498 & 3) == 0) {
          *(short *)(&DAT_0203a4a0 + uVar4 * 2) = (short)DAT_0203a6a0;
          DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 1;
          DAT_0203a498._2_2_ = 1;
          return;
        }
        return;
      }
      if (uVar5 != 2) {
        if (uVar5 == 3) {
          *(short *)(&DAT_0203a4a0 + ((ushort)DAT_0203a498 + 1) * 2) = (short)DAT_0203a6a0;
          DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 2;
          DAT_0203a498._2_2_ = 1;
          return;
        }
        return;
      }
      iVar2 = (uVar4 + 2) * 8 + 0x203a454;
      sVar3 = (short)DAT_0203a6a0;
      goto LAB_0814833e;
    }
    if (10 < *(ushort *)(&DAT_0203a4a0 + iVar2 * 2)) {
      return;
    }
    if (DAT_0203a6a8 < DAT_0203a6a0) {
      *(short *)(&DAT_0203a4a0 + uVar4 * 2) = (short)DAT_0203a6a0;
      DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 1;
      DAT_0203a498._2_2_ = 1;
      return;
    }
    uVar5 = uVar4 & 3;
    if (uVar5 == 1) {
LAB_08148312:
      iVar2 = (uVar4 + 3) * 8 + 0x203a454;
      sVar3 = DAT_0203a6a8 + 0xb;
LAB_08148320:
      DAT_0203a498._2_2_ = (ushort)DAT_0203a498 & 3;
      *(short *)(iVar2 + 0x4c) = sVar3;
      DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 4;
      return;
    }
    if (uVar5 == 1 || ((ushort)DAT_0203a498 & 3) == 0) {
      if (((ushort)DAT_0203a498 & 3) == 0) {
        *(short *)(&DAT_0203a4a0 + uVar4 * 2) = DAT_0203a6a8 + 0xb;
        DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 1;
        DAT_0203a498._2_2_ = 1;
        return;
      }
      return;
    }
    if (uVar5 != 2) {
      if (uVar5 == 3) {
        *(short *)(&DAT_0203a4a0 + ((ushort)DAT_0203a498 + 1) * 2) = DAT_0203a6a8 + 0xb;
        DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 2;
        DAT_0203a498._2_2_ = 1;
        return;
      }
      return;
    }
  }
  else {
    if (0xb < uVar1) {
      if (DAT_0203a6a0 < DAT_0203a6a8) {
        *(short *)(&DAT_0203a4a0 + uVar4 * 2) = DAT_0203a6a8 + 0xb;
        DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 1;
        DAT_0203a498._2_2_ = 1;
        return;
      }
      uVar5 = uVar4 & 3;
      if (uVar5 == 1) {
        iVar2 = (uVar4 + 3) * 8 + 0x203a454;
        sVar3 = (short)DAT_0203a6a0;
        goto LAB_08148320;
      }
      if (uVar5 == 1 || ((ushort)DAT_0203a498 & 3) == 0) {
        if (((ushort)DAT_0203a498 & 3) == 0) {
          *(short *)(&DAT_0203a4a0 + uVar4 * 2) = (short)DAT_0203a6a0;
          DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 1;
          DAT_0203a498._2_2_ = 1;
          return;
        }
        return;
      }
      if (uVar5 == 2) {
        iVar2 = (uVar4 + 2) * 8 + 0x203a454;
        sVar3 = (short)DAT_0203a6a0;
        goto LAB_0814833e;
      }
      if (uVar5 != 3) {
        return;
      }
      sVar3 = (short)DAT_0203a6a0;
LAB_0814835e:
      *(short *)(&DAT_0203a4a0 + (uVar4 + 1) * 2) = sVar3;
      DAT_0203a498._2_2_ = 1;
      DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 2;
      return;
    }
    if (10 < uVar1) {
      return;
    }
    if (DAT_0203a6a8 < DAT_0203a6a0) {
      *(short *)(&DAT_0203a4a0 + uVar4 * 2) = (short)DAT_0203a6a0;
      DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 1;
      DAT_0203a498._2_2_ = 1;
      return;
    }
    uVar5 = uVar4 & 3;
    if (uVar5 == 1) goto LAB_08148312;
    if (uVar5 == 1 || ((ushort)DAT_0203a498 & 3) == 0) {
      if (((ushort)DAT_0203a498 & 3) == 0) {
        *(short *)(&DAT_0203a4a0 + uVar4 * 2) = DAT_0203a6a8 + 0xb;
        DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 1;
        DAT_0203a498._2_2_ = 1;
        return;
      }
      return;
    }
    if (uVar5 != 2) {
      if (uVar5 != 3) {
        return;
      }
      sVar3 = DAT_0203a6a8 + 0xb;
      goto LAB_0814835e;
    }
  }
  iVar2 = (uVar4 + 2) * 8 + 0x203a454;
  sVar3 = DAT_0203a6a8 + 0xb;
LAB_0814833e:
  *(short *)(iVar2 + 0x4c) = sVar3;
  DAT_0203a498._0_2_ = (ushort)DAT_0203a498 + 3;
  DAT_0203a498._2_2_ = 1;
  return;
}


// sub_0814837C @ 0x0814837C

void sub_0814837C(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    *(undefined1 *)(&DAT_0203a49c + uVar1 * 2) = *(undefined1 *)(&DAT_0203a49c + (uVar1 + 4) * 2);
    *(undefined2 *)(&DAT_0203a4a0 + uVar1 * 2) = *(undefined2 *)(&DAT_0203a4a0 + (uVar1 + 4) * 2);
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x3c);
  return;
}


// sub_081483B4 @ 0x081483B4

void sub_081483B4(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(char *)(&DAT_0203a49c + uVar1 * 2) == '\x01') {
      sub_080AA184(*(undefined4 *)((uint)*(ushort *)(&DAT_0203a4a0 + uVar1 * 2) * 4 + 0x879c878),0,0
                   ,2);
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x3c);
  return;
}


// sub_08148420 @ 0x08148420

void sub_08148420(undefined4 arg0,undefined4 arg1)

{
  DAT_0203a454 = (undefined2)arg1;
  return;
}


// sub_0814842C @ 0x0814842C

void sub_0814842C(undefined4 arg0,int arg1)

{
  undefined4 in_r2;
  
  HuffUnComp(*(undefined4 *)(arg1 * 4 + 0x879ccf4),0x200afc8,in_r2);
  LZ77UnCompWram(0x200afc8,arg1 * 0x1200 + 0x200f874,in_r2);
  DAT_03003bb4 = 0;
  return;
}


// sub_0814846C @ 0x0814846C

void sub_0814846C(uint arg0)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = arg0 & 0xffff;
  REG_DMA3SAD = (uint)(byte)(&DAT_0203a700)[uVar2] * 0x2400 +
                (uint)(byte)(&DAT_0203a706)[uVar2] * 0x280 + 0x200f874;
  REG_DMA3DAD = uVar2 * 0x400 + 0x6014c00;
  REG_DMA3CNT = 0x840000a0;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_081484C8 @ 0x081484C8

void sub_081484C8(void)

{
  sub_0814846C(0);
  return;
}


// sub_081484D4 @ 0x081484D4

void sub_081484D4(void)

{
  sub_0814846C(1);
  return;
}


// sub_081484E0 @ 0x081484E0

void sub_081484E0(void)

{
  sub_0814846C(2);
  return;
}


// sub_081484EC @ 0x081484EC

void sub_081484EC(void)

{
  sub_0814846C(3);
  return;
}


// sub_081484F8 @ 0x081484F8

void sub_081484F8(void)

{
  sub_0814846C(4);
  return;
}


// sub_08148504 @ 0x08148504

void sub_08148504(void)

{
  sub_0814846C(5);
  return;
}


// sub_08148510 @ 0x08148510

void sub_08148510(uint arg0,undefined4 arg1,undefined4 arg2)

{
  dword arg0_00;
  uint uVar1;
  
  uVar1 = arg0 & 0xffff;
  (&DAT_0203a700)[uVar1] = (undefined1)arg1;
  (&DAT_0203a706)[uVar1] = (undefined1)arg2;
  switch(uVar1) {
  case 0:
    arg0_00 = 0x81484c9;
    break;
  case 1:
    arg0_00 = 0x81484d5;
    break;
  case 2:
    arg0_00 = 0x81484e1;
    break;
  case 3:
    arg0_00 = 0x81484ed;
    break;
  case 4:
    arg0_00 = 0x81484f9;
    break;
  case 5:
    DisplayList_Add(0x8148505,1);
  default:
    goto switchD_08148536_default;
  }
  DisplayList_Add(arg0_00,1);
switchD_08148536_default:
  return;
}


// sub_081485A0 @ 0x081485A0

void sub_081485A0(undefined4 arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = arg1 & 0xffff;
  iVar1 = sub_080A9CC0(arg0);
  uVar3 = 0;
  uVar2 = uVar4;
  if (uVar4 != 0) {
    do {
      uVar2 = uVar2 - 1 & 0xff;
      sub_080AA184(*(undefined4 *)((uint)*(byte *)(iVar1 + uVar2) * 4 + 0x879ce24),1,0,0);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  return;
}


// sub_08148618 @ 0x08148618

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08148618(void)

{
  if ((DAT_0203a454 == 3) &&
     (sub_080AA184(*(undefined4 *)((uint)_DAT_0203a554 * 4 + 0x879ce58),1,0,0),
     (DAT_030031bc & 7) == 0)) {
    _DAT_0203a554 = _DAT_0203a554 + 1 & 3;
  }
  return;
}


// sub_0814869C @ 0x0814869C

void sub_0814869C(uint arg0,undefined4 arg1,undefined4 arg2)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xffff;
  if (*(short *)((int)&DAT_0203a4d8 + uVar1 * 2) != 0) {
    sub_080AA184(*(undefined4 *)
                  ((uint)*(ushort *)((int)&DAT_0203a4d8 + uVar1 * 2) * 4 +
                  *(int *)(uVar1 * 4 + 0x879cea8)),1,0,0);
  }
  return;
}


// sub_08148718 @ 0x08148718

void sub_08148718(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  
  iVar1 = (arg0 & 0xffff) * 2;
  *(undefined2 *)((int)&DAT_0203a4d8 + iVar1) = (undefined2)arg1;
  if ((short)arg2 != 0) {
    *(short *)((int)&DAT_0203a500 + iVar1) = (short)arg2;
  }
  if ((short)arg3 != 0) {
    *(short *)(&DAT_0203a528 + iVar1) = (short)arg3;
  }
  return;
}


// sub_08148754 @ 0x08148754

void sub_08148754(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int iVar1;
  
  iVar1 = (arg0 & 0xffff) * 2;
  *(undefined2 *)((int)&DAT_0203a4d8 + iVar1) = (undefined2)arg1;
  *(undefined2 *)((int)&DAT_0203a500 + iVar1) = (undefined2)arg2;
  *(undefined2 *)(&DAT_0203a528 + iVar1) = (undefined2)arg3;
  return;
}


// sub_08148780 @ 0x08148780

void sub_08148780(undefined4 arg0,uint arg1,uint arg2,uint arg3)

{
  uint in_stack_00000000;
  
  sub_08148718(arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff,in_stack_00000000 & 0xffff);
  return;
}


// sub_081487A4 @ 0x081487A4

void sub_081487A4(undefined4 arg0,uint arg1,uint arg2,uint arg3)

{
  uint in_stack_00000000;
  
  sub_08148754(arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff,in_stack_00000000 & 0xffff);
  return;
}


// sub_081487C8 @ 0x081487C8

void sub_081487C8(void)

{
  DAT_03000040 = 0x2e40;
  return;
}


// sub_081487D8 @ 0x081487D8

void sub_081487D8(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  undefined4 local_24;
  undefined4 local_20;
  
  local_24 = 0;
  CpuSet(&local_24,0x203a454,0x5000200);
  local_20 = 0;
  REG_DMA3SAD = &local_20;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85001000;
  uVar1 = REG_DMA3CNT;
  REG_BG0CNT = 0x4008;
  DAT_03000002 = 0;
  DAT_03000000 = 0xf0;
  sub_081487C8();
  DAT_0203a5ec = 8;
  DAT_0203a5ee = 8;
  DAT_0203a5f0 = 0x10;
  DAT_0203a5f2 = 0;
  DAT_03000042 = 0x808;
  DAT_03000044 = 0x10;
  DAT_0203a454 = 1;
  uVar2 = 0;
  do {
    uVar5 = 0;
    uVar2 = uVar2 + 1;
    do {
      do {
        uVar3 = sub_080C2244();
        puVar4 = &DAT_0203a556;
      } while ((&DAT_0203a556)[uVar3 & 0x3f] != 0);
      (&DAT_0203a556)[uVar3 & 0x3f] = 1;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x10);
    sub_08149B38();
    uVar5 = 0;
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x40);
  } while (uVar2 < 0x10);
  sub_08148718(0,0,0,0);
  sub_08148718(1,0,0,0);
  sub_08148718(2,0,0,0);
  sub_08148718(3,1,0,0);
  sub_08148718(4,1,0,0);
  DAT_0203a508._0_2_ = 0x87;
  DAT_0203a530 = 0xa0;
  DAT_0203a5e8 = sub_080C31F0();
  return;
}


// sub_08148928 @ 0x08148928

uint sub_08148928(void)

{
  uint uVar1;
  
  if ((ushort)(DAT_0203a454 - 2U) < 2) {
    uVar1 = 0;
    if (DAT_0203a5e4 != 0) {
      uVar1 = (-DAT_0203a5d8 | DAT_0203a5d8) >> 0x1f;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_08148964 @ 0x08148964

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08148964(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  undefined4 arg0;
  int iVar5;
  short *psVar6;
  uint uVar7;
  ushort *puVar8;
  uint uVar9;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((DAT_030031bc & 3) == 0) {
    if (DAT_0203a5f2 == 0) {
      DAT_0203a5ee = DAT_0203a5ee + 1;
      if (DAT_0203a5ee == 0xc) {
        DAT_0203a5f2 = 1;
      }
    }
    else {
      uVar9 = (uint)DAT_0203a5ee;
      DAT_0203a5ee = (ushort)(uVar9 - 1);
      if ((int)((uVar9 - 1) * 0x10000) >> 0x10 == 4) {
        DAT_0203a5f2 = 0;
      }
    }
    DAT_03000042 = DAT_0203a5ee << 8 | DAT_0203a5ec;
    DAT_03000044 = DAT_0203a5f0;
  }
  if (DAT_0203a454 == 1) {
    sub_080AD0FC(0x879d100,0xffff);
    DAT_0203a454 = 0;
    uVar1 = DAT_0203a456;
    uVar2 = _DAT_0203a550;
    uVar3 = _DAT_0203a552;
  }
  else {
    uVar1 = DAT_0203a456;
    uVar2 = _DAT_0203a550;
    uVar3 = _DAT_0203a552;
    if (1 < DAT_0203a454) {
      if (DAT_0203a454 == 2) {
        if (((DAT_03003964 & 1) == 0) || (DAT_0203a456 != 1)) {
          if ((DAT_030031b8 & 1) != 0) {
            if (DAT_0203a456 == 2) {
              uVar1 = DAT_0203a458 & 0x7fff;
              if ((DAT_0203a458 & (ushort)0x7fff) == 0) {
                sub_080AD0FC(0x879d910,0xffff);
                DAT_0203a454 = uVar1;
              }
              else {
                sub_080AD0FC(0x879d9b0,0xffff);
                DAT_0203a454 = 0;
              }
              sub_080C51D4(0x164);
              uVar1 = DAT_0203a456;
              uVar2 = _DAT_0203a550;
              uVar3 = _DAT_0203a552;
            }
            else if (DAT_0203a456 < 3) {
              if (DAT_0203a456 == 0) {
                _DAT_0203a550 = DAT_0203a456;
                _DAT_0203a552 = DAT_0203a456;
                DAT_0203a454 = 3;
                DAT_0203a456 = 0x8000;
                uVar9 = 0;
                do {
                  (&DAT_0203a556)[uVar9] = 0;
                  uVar9 = uVar9 + 1 & 0xffff;
                } while (uVar9 < 0x40);
                DAT_03000000 = 0xf0;
                uVar1 = DAT_0203a456;
                uVar2 = _DAT_0203a550;
                uVar3 = _DAT_0203a552;
              }
            }
            else if (DAT_0203a456 == 3) {
              uVar9 = 0;
              do {
                (&DAT_0203a458)[uVar9] = (&DAT_0203a458)[uVar9] & 0x7fff;
                uVar9 = uVar9 + 1 & 0xffff;
              } while (uVar9 < 0x40);
              DAT_0203a5d8 = 0;
              sub_080C51D4(0x163);
              uVar1 = DAT_0203a456;
              uVar2 = _DAT_0203a550;
              uVar3 = _DAT_0203a552;
            }
            goto LAB_08148df6;
          }
          if (((DAT_030031b8 & 0x100) != 0) && (iVar5 = sub_08148928(), iVar5 == 1)) {
            sub_08149510();
            uVar1 = DAT_0203a456;
            uVar2 = _DAT_0203a550;
            uVar3 = _DAT_0203a552;
            goto LAB_08148df6;
          }
          if (((DAT_030031b8 & 0x200) != 0) && ((short)DAT_0203a4d8 == 0)) {
            sub_08149640();
            uVar1 = DAT_0203a456;
            uVar2 = _DAT_0203a550;
            uVar3 = _DAT_0203a552;
            goto LAB_08148df6;
          }
          uVar1 = DAT_0203a456;
          uVar2 = _DAT_0203a550;
          uVar3 = _DAT_0203a552;
          if (((DAT_03003964 & 2) == 0) || (DAT_0203a456 != 1)) {
            if ((DAT_030031b8 & 2) == 0) {
              if ((DAT_03003964 & 0x20) == 0) {
                if (((DAT_03003964 & 0x10) != 0) && (uVar1 = DAT_03003964 & 0x20, DAT_0203a456 != 3)
                   ) {
                  uVar1 = DAT_0203a456 + 1;
                }
              }
              else if (DAT_0203a456 == 0) {
                DAT_0203a456 = 3;
                uVar1 = DAT_0203a456;
              }
              else {
                uVar1 = DAT_0203a456 - 1;
              }
            }
            goto LAB_08148df6;
          }
          if (DAT_0203a5e4 == 0) goto LAB_08148df6;
          uVar9 = 1;
          if ((DAT_030031d0 & 4) != 0) {
            uVar9 = 10;
          }
          if (DAT_0203a5e4 < uVar9) {
            uVar9 = DAT_0203a5e4;
          }
          DAT_0203a5e4 = DAT_0203a5e4 - uVar9;
          DAT_0203a5e8 = DAT_0203a5e8 + uVar9;
        }
        else {
          if (DAT_0203a5e8 == 0) goto LAB_08148df6;
          uVar9 = 1;
          if ((DAT_030031d0 & 4) != 0) {
            uVar9 = 10;
          }
          if (DAT_0203a5e8 < uVar9) {
            uVar9 = DAT_0203a5e8;
          }
          if (100 < DAT_0203a5e4 + uVar9) {
            uVar9 = 100 - DAT_0203a5e4;
          }
          DAT_0203a5e4 = DAT_0203a5e4 + uVar9;
          DAT_0203a5e8 = DAT_0203a5e8 - uVar9;
        }
        sub_080C51D4(0x160);
        uVar1 = DAT_0203a456;
        uVar2 = _DAT_0203a550;
        uVar3 = _DAT_0203a552;
      }
      else if ((DAT_0203a454 == 3) &&
              (iVar5 = sub_081490E4(2,0xa0), uVar1 = DAT_0203a456, uVar2 = _DAT_0203a550,
              uVar3 = _DAT_0203a552, iVar5 != 0)) {
        if ((DAT_030031b8 & 1) == 0) {
          if ((DAT_030031b8 & 2) == 0) {
            if (((DAT_030031b8 & 0x100) == 0) || (iVar5 = sub_08148928(), iVar5 != 1)) {
              if (((DAT_030031b8 & 0x200) == 0) || ((short)DAT_0203a4d8 != 0)) {
                uVar1 = DAT_0203a456;
                uVar2 = _DAT_0203a550;
                if ((DAT_03003964 & 0x40) == 0) {
                  if ((DAT_03003964 & 0x80) != 0) {
                    uVar3 = DAT_03003964 & 0x40;
                    if (_DAT_0203a552 != 7) {
                      uVar3 = _DAT_0203a552 + 1;
                    }
                    goto LAB_08148df6;
                  }
                  uVar3 = _DAT_0203a552;
                  if ((DAT_03003964 & 0x20) == 0) {
                    if (((DAT_03003964 & 0x10) != 0) &&
                       (uVar2 = DAT_03003964 & 0x20, _DAT_0203a550 != 7)) {
                      uVar2 = _DAT_0203a550 + 1;
                    }
                    goto LAB_08148df6;
                  }
                  psVar6 = (short *)&DAT_0203a550;
                  if (_DAT_0203a550 != 0) {
                    uVar2 = _DAT_0203a550 - 1;
                    goto LAB_08148df6;
                  }
                  sVar4 = 7;
                }
                else {
                  psVar6 = (short *)&DAT_0203a552;
                  if (_DAT_0203a552 == 0) {
                    _DAT_0203a552 = 7;
                    uVar3 = _DAT_0203a552;
                    goto LAB_08148df6;
                  }
                  sVar4 = _DAT_0203a552 - 1;
                }
                *psVar6 = sVar4;
                uVar1 = DAT_0203a456;
                uVar2 = _DAT_0203a550;
                uVar3 = _DAT_0203a552;
              }
              else {
                sub_08149640();
                uVar1 = DAT_0203a456;
                uVar2 = _DAT_0203a550;
                uVar3 = _DAT_0203a552;
              }
            }
            else {
              sub_080C51D4(0x158);
              sub_08149510();
              uVar1 = DAT_0203a456;
              uVar2 = _DAT_0203a550;
              uVar3 = _DAT_0203a552;
            }
          }
          else {
            DAT_0203a454 = 2;
            DAT_0203a456 = 1;
            uVar1 = DAT_0203a456;
          }
        }
        else {
          puVar8 = &DAT_0203a458 + (uint)_DAT_0203a552 * 8 + (uint)_DAT_0203a550;
          uVar1 = *puVar8;
          if ((uVar1 & 0x8000) == 0) {
            if (DAT_0203a5d8 != 0x10) {
              *puVar8 = uVar1 | 0x8000;
              DAT_0203a5d8 = DAT_0203a5d8 + 1;
            }
          }
          else {
            *puVar8 = uVar1 & 0x7fff;
            DAT_0203a5d8 = DAT_0203a5d8 + -1;
          }
          sub_080C51D4(0x164);
          uVar1 = DAT_0203a456;
          uVar2 = _DAT_0203a550;
          uVar3 = _DAT_0203a552;
        }
      }
    }
  }
LAB_08148df6:
  _DAT_0203a552 = uVar3;
  _DAT_0203a550 = uVar2;
  DAT_0203a456 = uVar1;
  uVar9 = 0;
  do {
    if ((&DAT_0203a556)[uVar9] == 0) {
      uVar1 = (&DAT_0203a458)[uVar9];
      if ((uVar1 & 0x8000) == 0) {
        uVar7 = 5;
        if ((uVar1 & 0x7fff) != 0) {
          uVar7 = (uint)*(ushort *)(((uVar1 & 0x7fff) - 1) * 2 + 0x879ddc4);
        }
        arg0 = *(undefined4 *)(uVar9 * 4 + 0x879cd14);
        goto LAB_08148ebe;
      }
      uVar7 = 0xb;
      if ((uVar1 & (ushort)0x7fff) != 0) {
        uVar7 = (uint)*(ushort *)(((uVar1 & 0x7fff) - 1) * 2 + 0x879ddc4);
      }
      sub_080AA1BC(*(undefined4 *)(uVar9 * 4 + 0x879cd14),1,uVar7,0);
    }
    else if (((&DAT_0203a458)[uVar9] & 0x8000) == 0) {
      arg0 = *(undefined4 *)(uVar9 * 4 + 0x879cd14);
      uVar7 = 9;
LAB_08148ebe:
      sub_080AA184(arg0,1,uVar7,0);
    }
    else {
      sub_080AA1BC(*(undefined4 *)(uVar9 * 4 + 0x879cd14),1,9,0);
    }
    uVar9 = uVar9 + 1 & 0xffff;
    if (0x3f < uVar9) {
      sub_08148618();
      sub_081485A0(DAT_0203a5d8,2,0xf,0x5e);
      sub_081485A0(DAT_0203a5dc,2,0x3d,0x5e);
      sub_081485A0(DAT_0203a5e0,2,0x6a,0x5e);
      sub_081485A0(DAT_0203a5e4,3,0x93,0x1c);
      sub_081485A0(DAT_0203a5e8,6,0xba,0x1c);
      if ((DAT_0203a456 & 0x8000) == 0) {
        sub_080AA184(*(undefined4 *)((uint)DAT_0203a456 * 4 + 0x879ce14),1,0,0);
      }
      sub_0814971C();
      if (((short)DAT_0203a4d8 != 1) && (sub_0814869C(2,8,6), DAT_0203a454 == 4)) {
        uVar9 = __udivsi3(DAT_030031bc,7);
        if ((uVar9 & 1) == 0) {
          sub_08148718(2,1,0,0);
        }
        else {
          sub_08148718(2,0,0,0);
        }
      }
      if ((DAT_030031bc & 3) == 0) {
        if (DAT_0203a5e4 == 0) {
          if ((short)DAT_0203a4d8 != 0) {
            if ((short)DAT_0203a4d8 == 4) {
              DAT_0203a4d8._0_2_ = 0;
            }
            else {
              DAT_0203a4d8._0_2_ = (short)DAT_0203a4d8 + 1;
            }
          }
        }
        else if ((short)DAT_0203a4d8 == 0) {
          DAT_0203a4d8._0_2_ = 4;
        }
        else if ((short)DAT_0203a4d8 != 1) {
          DAT_0203a4d8._0_2_ = (short)DAT_0203a4d8 + -1;
        }
      }
      sub_0814869C(0,7,4);
      sub_0814869C(3,0xba,6);
      iVar5 = sub_08148928();
      if (iVar5 == 1) {
        sub_08148718(3,(uint)((DAT_030031bc >> 4 & 1) == 0),0,0);
      }
      else {
        sub_08148718(3,0,0,0);
      }
      sub_0814869C(1,0xbb,4);
      if ((DAT_0203a454 != 5) && (sub_0814869C(4,0xbb,4), (DAT_030031bc & 3) == 0)) {
        if ((short)DAT_0203a4e0 == 6) {
          DAT_0203a4e0._0_2_ = 1;
        }
        else {
          DAT_0203a4e0._0_2_ = (short)DAT_0203a4e0 + 1;
        }
      }
                    /* WARNING: Could not recover jumptable at 0x081490e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  } while( true );
}


// sub_081490E4 @ 0x081490E4

undefined4 sub_081490E4(undefined4 arg0,uint arg1)

{
  if (arg1 < DAT_0203a530) {
    if (arg1 < (ushort)(DAT_0203a530 - (short)arg0)) {
      DAT_0203a530 = DAT_0203a530 - (short)arg0;
      return 0;
    }
  }
  else if ((ushort)(DAT_0203a530 + (short)arg0) < arg1) {
    DAT_0203a530 = DAT_0203a530 + (short)arg0;
    return 0;
  }
  DAT_0203a530 = (short)arg1;
  return 1;
}


// sub_08149120 @ 0x08149120

void sub_08149120(int arg0,undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  uVar1 = sub_081490E4(arg1,arg2);
  *(short *)(arg0 + 0x1c) = (short)uVar1;
  return;
}


// sub_08149134 @ 0x08149134

void sub_08149134(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  
  sub_08149120(in_r0,in_r1,(uint)*(ushort *)(DAT_0203a5d8 * 0x22 + DAT_0203a5e0 * 2 + 0x879cebcU));
  return;
}


// sub_0814916C @ 0x0814916C

void sub_0814916C(undefined4 arg0,int arg1)

{
  DAT_0203a454 = (short)arg1;
  if (arg1 == 2) {
    DAT_0203a456 = DAT_0203a456 & 0x7fff;
  }
  return;
}


// sub_0814918C @ 0x0814918C

void sub_0814918C(undefined4 arg0,undefined4 arg1)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(arg1,0x200afc8,in_r2);
  sub_080ACFCC(3,0x200afc8,0x3002bb0,0x200);
  return;
}


// sub_081491BC @ 0x081491BC

void sub_081491BC(int arg0)

{
  uint uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  do {
    uVar1 = sub_080C2244();
    uVar1 = uVar1 & 0x3f;
  } while ((&DAT_0203a556)[uVar1] != 0);
  (&DAT_0203a556)[uVar1] = 1;
  if (((&DAT_0203a458)[uVar1] & 0x8000) != 0) {
    DAT_0203a5e0 = DAT_0203a5e0 + 1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_0203a675 = (undefined1)uVar1;
    sub_080C51D4(0x15d);
  }
  DAT_0203a5dc = DAT_0203a5dc + 1;
  return;
}


// sub_08149230 @ 0x08149230

void sub_08149230(void)

{
  sub_080AA184(0x81513a4,0,0,0);
  return;
}


// sub_08149280 @ 0x08149280

void sub_08149280(int arg0)

{
  int *piVar1;
  
  piVar1 = (int *)(DAT_0203a5e0 * 4 + DAT_0203a5d8 * 0x34 + 0x879d338U);
  DAT_0203a678 = DAT_0203a5e4 * *piVar1;
  *(ushort *)(arg0 + 0x1c) = (ushort)(*piVar1 != 0);
  *(undefined2 *)(arg0 + 0x24) = 0xf0;
  *(undefined2 *)(arg0 + 0x26) = 0x5a;
  return;
}


// sub_081492DC @ 0x081492DC

void sub_081492DC(undefined4 arg0)

{
  sub_080AA184(0x81519e8,0,0,0);
  return;
}


// sub_08149304 @ 0x08149304

void sub_08149304(undefined4 arg0)

{
  sub_080AA184(0x81519d0,0,0,0);
  return;
}


// sub_0814932C @ 0x0814932C

void sub_0814932C(int arg0,undefined4 arg1)

{
  *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) - (short)arg1;
  return;
}


// sub_08149334 @ 0x08149334

void sub_08149334(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  sub_080AA184(0x81519b4,0,0,0);
  iVar1 = sub_080A9CC0(DAT_0203a678);
  uVar2 = 5;
  uVar3 = 0;
  do {
    sub_080AA184(*(undefined4 *)((uint)*(byte *)(iVar1 + uVar2) * 4 + 0x879ce24),0,0,0);
    uVar2 = uVar2 - 1 & 0xff;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 6);
  DAT_0203a454 = 5;
  return;
}


// sub_081493D4 @ 0x081493D4

undefined4 sub_081493D4(int arg0)

{
  int iVar1;
  undefined4 uVar2;
  dword arg1;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  arg1 = 10000000;
  if (arg0 == 0) {
    arg1 = 0;
  }
  else {
    uVar3 = 0;
    do {
      iVar1 = __udivsi3(arg0,arg1);
      if (iVar1 != 0) break;
      arg1 = __udivsi3(arg1,10);
      uVar3 = uVar3 + 1;
    } while (uVar3 < 8);
  }
                    /* WARNING: Could not recover jumptable at 0x0814940e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(arg1);
  return uVar2;
}


// sub_08149410 @ 0x08149410

void sub_08149410(int arg0)

{
  uint uVar1;
  
  uVar1 = 1;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203a5e8 == 999999) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else {
    if ((DAT_03003964 & 1) != 0) {
      uVar1 = sub_081493D4(DAT_0203a678);
    }
    if (DAT_0203a678 < uVar1) {
      uVar1 = DAT_0203a678;
    }
    DAT_0203a678 = DAT_0203a678 - uVar1;
    DAT_0203a5e8 = DAT_0203a5e8 + uVar1;
    if (999999 < DAT_0203a5e8) {
      DAT_0203a5e8 = 999999;
    }
    if ((DAT_0203a678 == 0) || (DAT_0203a5e8 == 999999)) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  return;
}


// sub_08149494 @ 0x08149494

void sub_08149494(void)

{
  DAT_0203a5e4 = 0;
  sub_080C31FC(DAT_0203a5e8);
  return;
}


// sub_081494B8 @ 0x081494B8

void sub_081494B8(void)

{
  DAT_0203a67c = 0x1e;
  return;
}


// sub_081494CC @ 0x081494CC

void sub_081494CC(int arg0)

{
  uint uVar1;
  
  uVar1 = 1;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031d0 & 1) != 0) {
    uVar1 = 3;
  }
  if (DAT_0203a67c < uVar1) {
    uVar1 = DAT_0203a67c;
  }
  DAT_0203a67c = DAT_0203a67c - uVar1;
  if (DAT_0203a67c == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_08149510 @ 0x08149510

void sub_08149510(void)

{
  ushort *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  
  sub_080AD0FC(0x879d6ac,0xffff);
  DAT_0203a454 = 0;
  uVar3 = 0;
  puVar1 = &DAT_0203a458;
  puVar2 = &DAT_0203a556;
  do {
    *puVar2 = 0;
    *puVar1 = *puVar1 & 0x8000;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x40);
  DAT_0203a5dc = 0;
  DAT_0203a5e0 = 0;
  DAT_03000000 = 0xf0;
  DAT_0203a456 = DAT_0203a456 | 0x8000;
  return;
}


// sub_08149580 @ 0x08149580

void sub_08149580(void)

{
  DAT_0203a680 = sub_080AB008(0x140,0x80,2);
  DAT_03000040 = 0;
  return;
}


// sub_081495AC @ 0x081495AC

void sub_081495AC(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x87b59dc,0x200afc8,in_r2);
  sub_080ACFCC(3,&DAT_0200b048,0x3002c30,0x100);
  DAT_0203a680 = sub_080AB054(0x140,0x80,2,0x20);
  DAT_03000040 = 0;
  return;
}


// sub_08149608 @ 0x08149608

void sub_08149608(int arg0)

{
  uint uVar1;
  
  uVar1 = sub_080AB178(DAT_0203a680);
  *(ushort *)(arg0 + 0x1c) = (ushort)((uVar1 & 0xffff) == 0);
  return;
}


// sub_08149634 @ 0x08149634

void sub_08149634(void)

{
  DAT_03000000 = 0;
  return;
}


// sub_08149640 @ 0x08149640

void sub_08149640(void)

{
  sub_080C51D4(0x158);
  sub_080AD0FC(0x879da00,0xffff);
  DAT_0203a454 = 4;
  return;
}


// sub_0814966C @ 0x0814966C

undefined4 sub_0814966C(uint arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xf;
  switch(uVar1) {
  case 10:
  case 0xc:
    sub_080AA184(*(undefined4 *)(uVar1 * 4 + 0x879ce24),1,0,0);
    break;
  case 0xb:
    sub_080AA184(*(undefined4 *)((arg1 & 0xffff) * 4 + 0x879ddac),1,0,0);
    return 1;
  case 0xd:
  case 0xe:
    break;
  default:
    sub_080AA184(*(undefined4 *)(uVar1 * 4 + 0x879ce24),1,0,0);
  }
  return 0;
}


// sub_0814971C @ 0x0814971C

void sub_0814971C(void)

{
  ushort uVar1;
  ushort uVar2;
  uint *puVar3;
  int iVar4;
  dword arg0;
  ushort *puVar5;
  uint uVar6;
  uint arg3;
  uint unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((DAT_0203a5d8 != 0) && (DAT_03000000 != 0)) {
    arg3 = 0x34;
    puVar5 = (ushort *)(DAT_0203a5d8 * 0x12 + 0x879da14);
    puVar3 = (uint *)(DAT_0203a5d8 * 0x24 + 0x879db48);
    uVar2 = 0;
    uVar1 = *puVar5;
    while (uVar1 != 0) {
      uVar6 = (uint)*puVar5;
      sub_0814966C((uint)(*puVar5 >> 0xc),0,0x8c,arg3);
      sub_0814966C((uVar6 & 0xf00) >> 8,0,0x94,arg3);
      sub_0814966C((uVar6 & 0xf0) >> 4,0,0x9c,arg3);
      sub_0814966C(uVar6 & 0xf,0,0xa4,arg3);
      uVar6 = *puVar3;
      if ((uVar6 & 0xf0000000) == 0xb0000000) {
        unaff_r8 = (uVar6 & 0xf000000) >> 0x18;
      }
      if ((uVar6 & 0xf000000) == 0xb000000) {
        unaff_r8 = (uVar6 & 0xf00000) >> 0x14;
      }
      if ((uVar6 & 0xf00000) == 0xb00000) {
        unaff_r8 = (uVar6 & 0xf0000) >> 0x10;
      }
      if ((uVar6 & 0xf0000) == 0xb0000) {
        unaff_r8 = (uVar6 & 0xf000) >> 0xc;
      }
      if ((uVar6 & 0xf000) == 0xb000) {
        unaff_r8 = (uVar6 & 0xf00) >> 8;
      }
      if ((uVar6 & 0xf00) == 0xb00) {
        unaff_r8 = (uVar6 & 0xf0) >> 4;
      }
      if ((uVar6 & 0xf0) == 0xb0) {
        unaff_r8 = uVar6 & 0xf;
      }
      iVar4 = sub_0814966C(uVar6 >> 0x1c,unaff_r8,0xac,arg3);
      if (iVar4 == 0) {
        iVar4 = sub_0814966C((uVar6 & 0xf000000) >> 0x18,unaff_r8,0xb4,arg3);
      }
      else {
        iVar4 = 0;
      }
      if (iVar4 == 0) {
        iVar4 = sub_0814966C((uVar6 & 0xf00000) >> 0x14,unaff_r8,0xbc,arg3);
      }
      else {
        iVar4 = 0;
      }
      if ((uVar6 & 0xfffff) == 0) {
        arg0 = 0x8151b68;
LAB_0814998a:
        sub_080AA184(arg0,1,0,0);
      }
      else {
        if (iVar4 == 0) {
          iVar4 = sub_0814966C((uVar6 & 0xf0000) >> 0x10,unaff_r8,0xc4,arg3);
        }
        else {
          iVar4 = 0;
        }
        if ((uVar6 & 0xffff) == 0) {
          arg0 = 0x8151b50;
          goto LAB_0814998a;
        }
        if (iVar4 == 0) {
          iVar4 = sub_0814966C((uVar6 & 0xf000) >> 0xc,unaff_r8,0xcc,arg3);
        }
        else {
          iVar4 = 0;
        }
        if ((uVar6 & 0xfff) == 0) {
          arg0 = 0x8151b40;
          goto LAB_0814998a;
        }
        if (iVar4 == 0) {
          iVar4 = sub_0814966C((uVar6 & 0xf00) >> 8,unaff_r8,0xd4,arg3);
        }
        else {
          iVar4 = 0;
        }
        if ((uVar6 & 0xff) == 0) {
          arg0 = 0x8151b28;
          goto LAB_0814998a;
        }
        if (iVar4 == 0) {
          iVar4 = sub_0814966C((uVar6 & 0xf0) >> 4,unaff_r8,0xdc,arg3);
        }
        else {
          iVar4 = 0;
        }
        if (iVar4 == 0) {
          sub_0814966C(uVar6 & 0xf,unaff_r8,0xe4,arg3);
        }
      }
      puVar5 = puVar5 + 1;
      puVar3 = puVar3 + 1;
      arg3 = arg3 + 0xb & 0xffff;
      uVar2 = uVar2 + 1;
      if (8 < uVar2) break;
      uVar1 = *puVar5;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x08149a0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08149A10 @ 0x08149A10

void sub_08149A10(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    (&DAT_0203a458)[uVar1] = (&DAT_0203a458)[uVar1] & 0x8000;
    (&DAT_0203a556)[uVar1] = 0;
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x40);
  return;
}


// sub_08149A4C @ 0x08149A4C

void sub_08149A4C(void)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  
  sub_08149A10();
  uVar3 = 0;
  do {
    sVar1 = 0;
    uVar5 = 0;
    do {
      if (((int)(uint)(byte)(&DAT_0203a5f4)[uVar5 * 8 + (uVar3 >> 3)] >> (uVar3 & 7) & 1U) != 0) {
        sVar1 = sVar1 + 1;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 0x10);
    switch(sVar1) {
    case 0:
      uVar4 = (&DAT_0203a458)[uVar3];
      uVar2 = 1;
      break;
    case 1:
      uVar4 = (&DAT_0203a458)[uVar3];
      uVar2 = 2;
      break;
    case 2:
      uVar4 = (&DAT_0203a458)[uVar3];
      uVar2 = 3;
      break;
    case 3:
    case 4:
    case 5:
      uVar4 = (&DAT_0203a458)[uVar3];
      uVar2 = 4;
      break;
    case 6:
      uVar4 = (&DAT_0203a458)[uVar3];
      uVar2 = 5;
      break;
    case 7:
      uVar4 = (&DAT_0203a458)[uVar3];
      uVar2 = 6;
      break;
    case 8:
      uVar4 = (&DAT_0203a458)[uVar3];
      uVar2 = 7;
      break;
    default:
      uVar4 = (&DAT_0203a458)[uVar3];
      uVar2 = 8;
    }
    (&DAT_0203a458)[uVar3] = uVar2 | uVar4;
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 0x40);
  return;
}


// sub_08149B38 @ 0x08149B38

void sub_08149B38(void)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  
  uVar2 = (uint)DAT_0203a674;
  uVar4 = 0;
  do {
    if ((&DAT_0203a556)[uVar4] == 0) {
      pbVar3 = &DAT_0203a5f4 + (uVar4 >> 3) + uVar2 * 8;
      bVar1 = *pbVar3 & ~(byte)(1 << (uVar4 & 7));
    }
    else {
      pbVar3 = &DAT_0203a5f4 + (uVar4 >> 3) + uVar2 * 8;
      bVar1 = (byte)(1 << (uVar4 & 7)) | *pbVar3;
    }
    *pbVar3 = bVar1;
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 0x40);
  DAT_0203a674 = DAT_0203a674 + 1 & 0xf;
  return;
}


// sub_08149BBC @ 0x08149BBC

void sub_08149BBC(void)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_18;
  
  local_18 = 0;
  CpuSet(&local_18,0x203a454,0x5000200);
  REG_BG0CNT = 0x4008;
  DAT_03000002 = 0;
  DAT_03000040 = 0;
  DAT_0203a454 = 1;
  DAT_0203a47c = sub_080C31F0();
  DAT_0203a460._3_1_ = 8;
  DAT_0203a46c = 1;
  DAT_0203a46a._0_1_ = 1;
  DAT_0203a494._0_2_ = 0x154;
  DAT_0203a494._2_2_ = 0x40;
  DAT_0203a498._0_2_ = 0x50;
  if (DAT_03004614 == 0x26) {
    DAT_0203a6b6 = 1;
  }
  else if (DAT_03004614 < 0x27) {
    if (DAT_03004614 == 3) {
      DAT_0203a6b6 = 0;
    }
  }
  else if (DAT_03004614 == 0x30) {
    DAT_0203a6b6 = 2;
  }
  else if (DAT_03004614 == 0x40) {
    DAT_0203a6b6 = 3;
  }
                    /* WARNING: Could not recover jumptable at 0x08149c76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08149C7C @ 0x08149C7C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08149C7C(void)

{
  byte bVar1;
  char cVar2;
  dword arg0;
  uint uVar3;
  
  if (DAT_0203a454 == 1) {
    sub_080AD0FC(0x879e354,0xffff);
    DAT_0203a454 = 0;
  }
  if (DAT_0203a46e._1_1_ == '\0') {
    sub_080AA184(0x814f824,1,0,0);
    sub_080AA184(0x814f7f4,1,0,0);
  }
  else {
    sub_080AA184(0x814f888,1,0,0);
    sub_080AA184(0x814f858,1,0,0);
  }
  sub_0814A26C(_DAT_0203a480,0x30,0x21,0);
  sub_0814A26C(DAT_0203a47c,0xe3,0x21,0);
  sub_080AA184(*(undefined4 *)((uint)DAT_0203a466 * 4 + 0x879ddfc),0,0,0);
  if ((DAT_0203a46c == '\x01') || (DAT_0203a46d == '\x01')) {
    sub_0814A1FC();
  }
  if (DAT_0203a46c == '\x02') {
    sub_080AA184(0x814f790,0,0,0);
  }
  else if (DAT_0203a46d == '\x02') {
    sub_080AA184(0x814f7a8,0,0,0);
  }
  if (DAT_0203a478._2_1_ == '\x01') {
    sub_080AA184(0x814f958,0,0,0);
  }
  if (DAT_0203a478._3_1_ == '\x01') {
    sub_080AA184(0x814f958,0,0,0);
  }
  sub_0814A8B0();
  sub_0814AA04();
  if ((DAT_0203a6b8 == '\x01') && ((byte)DAT_0203a458 == '\0')) {
    if ((DAT_030031b8 & 0x100) != 0) {
      DAT_0203a460._0_2_ = 0;
      _DAT_0203a4b0 = 0;
      DAT_0203a4ae = 0;
      if ((DAT_0203a46e._1_1_ == '\0') && (9 < DAT_0203a47c)) {
        DAT_0203a458._0_1_ = '\x04';
        DAT_0203a47c = DAT_0203a47c - 10;
        _DAT_0203a484 = 10;
        _DAT_0203a480 = 10;
      }
      else if (DAT_0203a46e._1_1_ == '\x01') {
        DAT_0203a458._0_1_ = '\x04';
      }
      if ((char)DAT_0203a46a == '\x01') {
        DAT_0203a46c = '\x02';
      }
      else if (DAT_0203a46a._1_1_ == '\x01') {
        DAT_0203a46d = '\x02';
      }
    }
    if ((DAT_030031b8 & 0x200) != 0) {
      if (DAT_0203a46e._1_1_ == '\0') {
        sub_080C51D4(0x158);
        DAT_0203a458._0_1_ = '\n';
      }
      else {
        DAT_0203a458._0_1_ = '\t';
      }
    }
    cVar2 = (char)DAT_0203a46a;
    if (((DAT_030031b8 & 0x40) != 0) && ((char)DAT_0203a46a == '\0')) {
      DAT_0203a46a._0_1_ = '\x01';
      DAT_0203a46c = '\x02';
      DAT_0203a46a._1_1_ = cVar2;
      DAT_0203a46d = cVar2;
    }
    cVar2 = DAT_0203a46a._1_1_;
    if (((DAT_030031b8 & 0x80) != 0) && (DAT_0203a46a._1_1_ == '\0')) {
      DAT_0203a46a._1_1_ = '\x01';
      DAT_0203a46d = '\x02';
      DAT_0203a46a._0_1_ = cVar2;
      DAT_0203a46c = cVar2;
    }
  }
  bVar1 = DAT_0203a464;
  switch((byte)DAT_0203a458) {
  case 0:
    if (DAT_0203a46e._1_1_ == '\0') {
      if (((0x14 < DAT_0203a45e) && (sub_080AA184(0x814f83c,0,0,0), 0x28 < DAT_0203a45e)) &&
         (DAT_0203a45e = 0, DAT_0203a6b8 == '\0')) {
        DAT_0203a6b8 = '\x01';
      }
    }
    else if ((0x14 < DAT_0203a45e) && (sub_080AA184(0x814f8a0,0,0,0), 0x28 < DAT_0203a45e)) {
      DAT_0203a45e = 0;
    }
    if (10 < _DAT_0203a468) {
      sub_080AA184(0x814f768,0,0,0);
      sub_080AA184(0x814f778,0,0,0);
      if (0x14 < _DAT_0203a468) {
        _DAT_0203a468 = 0;
      }
    }
    DAT_0203a45e = DAT_0203a45e + 1;
    _DAT_0203a468 = _DAT_0203a468 + 1;
    break;
  case 1:
    if (DAT_0203a464 == 1) {
      if (0x50 < DAT_0203a45a) {
        DAT_0203a464 = 2;
        return;
      }
      if (1 < DAT_0203a460._2_1_) {
        sub_0814A4AC();
        DAT_0203a460._2_1_ = 0;
        goto LAB_0814a0f6;
      }
    }
    else if (DAT_0203a464 < 2) {
      if (DAT_0203a464 != 0) {
        return;
      }
      if (5 < DAT_0203a45a) {
        DAT_0203a464 = 1;
        return;
      }
      if (DAT_0203a460._3_1_ < DAT_0203a460._2_1_) {
        sub_0814A4AC();
        DAT_0203a460._2_1_ = bVar1;
        DAT_0203a460._3_1_ = DAT_0203a460._3_1_ - 1;
LAB_0814a0f6:
        sub_080C51D4(0x15a);
      }
    }
    else {
      if (DAT_0203a464 != 2) {
        return;
      }
      if (0x5a < DAT_0203a45a) {
        sub_0814AC48();
        DAT_0203a458._0_1_ = bVar1;
        DAT_0203a45a = 0;
        DAT_0203a460._3_1_ = 8;
        return;
      }
      if (DAT_0203a460._3_1_ < DAT_0203a460._2_1_) {
        sub_0814A4AC();
        DAT_0203a460._2_1_ = 0;
        DAT_0203a460._3_1_ = DAT_0203a460._3_1_ + 1;
        goto LAB_0814a0f6;
      }
    }
    DAT_0203a460._2_1_ = DAT_0203a460._2_1_ + 1;
    break;
  case 2:
    DAT_0203a464 = 0;
    DAT_0203a458._0_1_ = '\x05';
    if (DAT_0203a466 < 5) {
      if (DAT_0203a46a._1_1_ == '\x01') {
        DAT_0203a46e._0_1_ = (char)DAT_0203a46e + '\x01';
        _DAT_0203a484 = _DAT_0203a484 << 1;
      }
      else {
        DAT_0203a46e._0_1_ = DAT_0203a46e._1_1_;
        if (DAT_0203a46e._1_1_ != '\0') {
          DAT_0203a46e._0_1_ = 'c';
        }
      }
    }
    else if ((char)DAT_0203a46a == '\x01') {
      DAT_0203a46e._0_1_ = (char)DAT_0203a46e + '\x01';
      _DAT_0203a484 = _DAT_0203a484 << 1;
    }
    else if (DAT_0203a46e._1_1_ == '\0') {
      DAT_0203a46e._0_1_ = DAT_0203a46e._1_1_;
    }
    else {
      DAT_0203a46e._0_1_ = 'c';
    }
    if ((char)DAT_0203a46a == '\x01') {
      DAT_0203a46c = '\x01';
    }
    else if (DAT_0203a46a._1_1_ == '\x01') {
      DAT_0203a46d = DAT_0203a46a._1_1_;
    }
    break;
  case 3:
    sub_0814A3A8();
    break;
  case 4:
    if (DAT_0203a478._3_1_ == '\0') {
      sub_0814A684();
    }
    else {
      DAT_0203a458._0_1_ = '\x01';
      DAT_0203a476 = 0;
    }
    break;
  case 5:
    if (DAT_0203a478._1_1_ == '\0') {
      sub_0814A568();
    }
    else {
      DAT_0203a458._0_1_ = '\b';
      DAT_0203a472 = 0;
    }
    break;
  case 6:
    if (((char)DAT_0203a46e == 'c') || ((char)DAT_0203a46e == '\x01')) {
      if (DAT_0203a478._1_1_ == '\0') {
        sub_0814A568();
        sub_0814A4DC();
      }
      else {
        DAT_0203a458._0_1_ = '\0';
        DAT_0203a472 = 0;
        if ((char)DAT_0203a46e != '\x01') {
          DAT_0203a46e._0_1_ = '\0';
        }
      }
    }
    else {
      DAT_0203a458._0_1_ = '\0';
    }
    break;
  case 7:
    if (((char)DAT_0203a46e == 'c') || ((char)DAT_0203a46e == '\x01')) {
      if (DAT_0203a478._3_1_ == '\0') {
        sub_0814A684();
        sub_0814A5F0();
      }
      else {
        DAT_0203a458._0_1_ = '\x06';
        DAT_0203a476 = 0;
        DAT_0203a46e._1_1_ = DAT_0203a46e._1_1_ == '\0';
        if ((char)DAT_0203a46e == 'c') {
          uVar3 = 0;
          do {
            *(undefined1 *)((int)&DAT_0203a49c + uVar3 + 2) = 0;
            uVar3 = uVar3 + 1 & 0xffff;
          } while (uVar3 < 10);
        }
      }
    }
    else {
      DAT_0203a458._0_1_ = '\x06';
    }
    break;
  case 8:
    sub_0814A718();
    break;
  case 9:
    if (5 < (ushort)DAT_0203a460) {
      sub_0814A414();
      return;
    }
    if (3 < DAT_0203a45e) {
      arg0 = 0x814f870;
LAB_0814a1b4:
      sub_080AA184(arg0,0,0,0);
    }
    goto LAB_0814a1ca;
  case 10:
    if (5 < (ushort)DAT_0203a460) {
      sub_080C31FC(DAT_0203a47c);
      sub_080BE4C4();
      return;
    }
    if (3 < DAT_0203a45e) {
      arg0 = 0x814f80c;
      goto LAB_0814a1b4;
    }
LAB_0814a1ca:
    if (6 < DAT_0203a45e) {
      DAT_0203a45e = 0;
      DAT_0203a460._0_2_ = (ushort)DAT_0203a460 + 1;
    }
    DAT_0203a45e = DAT_0203a45e + 1;
  }
  return;
}


// sub_0814A1FC @ 0x0814A1FC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814A1FC(void)

{
  if (0x14 < _DAT_0203a45c) {
    if (DAT_0203a46c == '\x01') {
      sub_080AA184(0x814f790,0,0,0);
    }
    else if (DAT_0203a46d == '\x01') {
      sub_080AA184(0x814f7a8,0,0,0);
    }
    if (0x28 < _DAT_0203a45c) {
      _DAT_0203a45c = 0;
    }
  }
  _DAT_0203a45c = _DAT_0203a45c + 1;
  return;
}


// sub_0814A26C @ 0x0814A26C

void sub_0814A26C(undefined4 arg0,undefined4 arg1,undefined4 arg2,uint arg3)

{
  byte *pbVar1;
  uint arg3_00;
  
  arg3_00 = arg3 & 0xffff;
  pbVar1 = (byte *)sub_080A9CC0(arg0);
  sub_080AA184(*(undefined4 *)((uint)*pbVar1 * 4 + 0x879ddd4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[1] * 4 + 0x879ddd4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[2] * 4 + 0x879ddd4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[3] * 4 + 0x879ddd4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[4] * 4 + 0x879ddd4),0,0,arg3_00);
  sub_080AA184(*(undefined4 *)((uint)pbVar1[5] * 4 + 0x879ddd4),0,0,arg3_00);
  return;
}


// sub_0814A36C @ 0x0814A36C

void sub_0814A36C(int arg0)

{
  int iVar1;
  dword arg1;
  uint uVar2;
  
  arg1 = 10000;
  if (arg0 != 0) {
    uVar2 = 0;
    do {
      iVar1 = __udivsi3(arg0,arg1);
      if (iVar1 != 0) {
        return;
      }
      arg1 = __udivsi3(arg1,10);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 5);
  }
  return;
}


// sub_0814A3A8 @ 0x0814A3A8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0814A3A8(void)

{
  int iVar1;
  
  if ((DAT_030031bc & 3) == 0) {
    sub_080C51D4(0x159);
    if ((DAT_03003964 & 1) == 0) {
      iVar1 = 5;
    }
    else {
      iVar1 = _DAT_0203a480;
      sub_0814A36C(_DAT_0203a480);
    }
    _DAT_0203a480 = _DAT_0203a480 + iVar1;
    DAT_0203a48c = iVar1;
    if (_DAT_0203a484 <= _DAT_0203a480) {
      _DAT_0203a480 = _DAT_0203a484;
      _DAT_0203a488 = DAT_0203a47c;
      if (_DAT_0203a484 == 0x2800) {
        DAT_0203a458._0_1_ = 9;
      }
      else {
        DAT_0203a458._0_1_ = 7;
      }
    }
  }
  return;
}


