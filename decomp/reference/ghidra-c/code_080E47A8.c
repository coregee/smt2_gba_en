/* Ghidra decompilation of asm/code_080E47A8.s (reference only; not compiled). */

// sub_080E47A8 @ 0x080E47A8

void sub_080E47A8(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 in_stack_00000000;
  
  uVar3 = (ushort)arg0 & 0xf;
  DAT_0203d389 = (undefined1)((int)((uint)((ushort)arg0 & 0x10) << 0x10) >> 0x14);
  sub_080E44F8();
  DAT_030063b4 = 0;
  DAT_0203d16a = uVar3;
  DAT_0203d356 = uVar3;
  if (DAT_030063a0 == 1) {
    DAT_030063a6 = DAT_030063a0;
    if (uVar3 == 0) {
      DAT_0203d356 = DAT_030063a0;
      DAT_0203d16a = DAT_030063a0;
    }
    goto LAB_080e4a00;
  }
  DAT_0203d35e = in_stack_00000000;
  DAT_0203cb9a = in_stack_00000000;
  DAT_0203d3a4 = 0;
  DAT_0203d3a6 = 0;
  DAT_0300003d = 0;
  DAT_0203d38c = 0;
  DAT_0203d3ac = 0xffff;
  DAT_0203d3ae = 0xffff;
  DAT_0203d3a8 = 0;
  if (uVar3 == 2) {
    DAT_030063b6 = 0xc000;
  }
  else if (uVar3 < 3) {
    if (uVar3 == 1) {
      DAT_030063b6 = 0;
    }
    else {
LAB_080e48e6:
      DAT_030063b6 = 0;
    }
  }
  else {
    if (uVar3 != 3) goto LAB_080e48e6;
    DAT_030063b6 = 0x8000;
  }
  DAT_0203c200 = 0;
  DAT_0203cb74 = 0;
  DAT_0203cb70 = 0;
  DAT_0203d168 = 0;
  DAT_0203cb78 = 0;
  DAT_0203cb7a = 0;
  DAT_0203cb7c = 0;
  DAT_0203cb7e = 0;
  DAT_0203d0ce = 0;
  DAT_0203cb90 = (uint)(ushort)arg1;
  DAT_0203cb94 = (uint)(ushort)arg2;
  DAT_0203cb98 = (undefined2)arg3;
  DAT_0203d358 = (ushort)arg1;
  DAT_0203d35a = (ushort)arg2;
  DAT_0203d35c = (undefined2)arg3;
  sub_080ED7BC();
  if ((ushort)arg2 == 0xffff) {
    sub_080ED938(0);
  }
  else {
    sub_080ED938(0xffff);
  }
  if (0 < (short)DAT_0203d16a) {
    DAT_0203cb9c = 1;
    sub_080ED90C(0x100);
  }
  if (DAT_0203cb9c == 0) {
    DAT_0203cb9c = 1;
  }
  DAT_0203cb9e = DAT_0203cb9c;
  sub_080E74DC();
  uVar1 = 0;
  do {
    sub_080BFD94((int)(short)uVar1);
    uVar2 = (int)(short)uVar1 + 1;
    uVar1 = uVar2 & 0xffff;
  } while ((int)(uVar2 * 0x10000) >> 0x10 < 4);
  DAT_030063a0 = 1;
  DAT_0203d322 = 0;
  DAT_030063ac = 0;
  sub_080C7C60();
  sub_080EA9E8(0);
  DAT_0203d323 = 0;
  DAT_030063a6 = 1;
  DAT_030063aa = 0;
  sub_080E5668();
  DAT_030063b8 = sub_080AD0FC(0x86bef88,0xffff);
  Font_ResetGlyphSpriteCache(0x180);
  DAT_0203d38a = DAT_030031b4;
  if (DAT_030031b4 == 9) {
    DAT_0203d38a = DAT_030031ec;
  }
  sub_080B0888();
  sub_080C7054();
LAB_080e4a00:
                    /* WARNING: Could not recover jumptable at 0x080e4a0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E4A40 @ 0x080E4A40

void sub_080E4A40(uint arg0)

{
  int iVar1;
  dword arg1;
  
  iVar1 = sub_080E444C((uint)*(ushort *)(&DAT_0203cb90 + (arg0 & 0xffff)));
  arg1 = *(dword *)(iVar1 + 4);
  if ((DAT_030020e4 == 0x80d977d) &&
     (iVar1 = sub_080C2644((&DAT_0203cb90)[arg0 & 0xffff]), iVar1 == 0)) {
    arg1 = 0x86be584;
  }
  if ((arg0 & 0xffff) == 0) {
    sub_080ACFCC(3,arg1,0x3002d70,0x20);
    sub_080AAFBC(0x1e0,0x10,2);
  }
  else {
    sub_080ACFCC(3,arg1,0x3002d90,0x20);
    sub_080AAFBC(0x1f0,0x10,2);
  }
  return;
}


// sub_080E4AD0 @ 0x080E4AD0

void sub_080E4AD0(int arg0)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  short *psVar8;
  dword dVar9;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  switch(DAT_0203cb78) {
  case 0:
    uVar6 = 0;
    do {
      iVar7 = (int)(short)uVar6;
      (&DAT_0203cbae)[iVar7 * 0x40] = 0;
      (&DAT_0203cbb0)[iVar7 * 0x40] = 0x8000;
      (&DAT_0203cbb8)[iVar7 * 0x40] = 0;
      uVar6 = iVar7 + 1U & 0xffff;
    } while ((int)((iVar7 + 1U) * 0x10000) >> 0x10 < 8);
    sub_080ED878();
    sub_080ED900(0);
    sub_080F3F58(0xfffffffd);
    sub_080F3F58(0xfffffffb);
    sub_080F3F58(0xfffffff7);
    sub_080F3F58(0xfffffdff);
    sub_080F3F58(0xfffffbff);
    sub_080F3F58(0xfffff7ff);
    uVar1 = DAT_0203d16a;
    if (DAT_0203d16a == 0) {
      DAT_030063b2 = 999;
      DAT_0203d38c = DAT_0203d16a;
      DAT_0203d39e = DAT_0203d16a;
      DAT_0203d39c = DAT_0203d16a;
      if (DAT_0203d323 == '\x01') {
        iVar7 = sub_080ED954();
        if (iVar7 == 0) {
          DAT_0203cb78 = 1;
        }
        else {
          DAT_0203d398 = uVar1;
          DAT_0203cb78 = 5;
          DAT_0203d39c = 1;
        }
        DAT_0203d323 = '\0';
      }
      else {
        uVar6 = DAT_0203cb84 & 0xf0;
        if (uVar6 != 0) {
          dRam0203cb88 = sub_080ED5B4(DAT_0203cb80,0);
          dRam0203cb8c = sub_080ED5B4(DAT_0203cb80,1);
          if ((dRam0203cb88 != dRam0203cb8c) && (uVar5 = sub_080C2244(), uVar6 <= (uVar5 & 0xf0))) {
            sub_080ED938(0xffff);
          }
        }
        iVar7 = sub_080ED954();
        if ((iVar7 != 0) && (dRam0203cb88 == dRam0203cb8c)) {
          sub_080ED938(0);
        }
        iVar7 = sub_080ED954();
        if (iVar7 == 0) {
          DAT_0203cb90 = sub_080ED5B4(DAT_0203cb80,0);
          DAT_0203cb94 = 0xffff;
          dVar9 = 0x978;
        }
        else {
          DAT_0203cb90 = dRam0203cb88;
          DAT_0203cb94 = dRam0203cb8c;
          DAT_0203d398 = 0;
          DAT_0203cb78 = 5;
          dVar9 = 0x119c;
        }
        *(undefined2 *)(dVar9 + 0x203c200) = 1;
        uVar3 = sub_080ED610(DAT_0203cb90);
        DAT_0203cb98 = (short)uVar3;
        uVar3 = sub_080ED610(DAT_0203cb94);
        DAT_0203cb9a = (short)uVar3;
      }
      sub_0813E908(DAT_0203cb90 & 0xffff,DAT_0203cb94 & 0xffff);
    }
    else {
      sub_080ED67C();
      DAT_030063b2 = 0;
      sub_080ED90C(0x100);
      DAT_0203cb78 = 4;
    }
    iVar7 = sub_080ED954();
    if (iVar7 == 0) {
      uVar6 = 0;
      if (0 < DAT_0203cb98) {
        do {
          sub_080F0200((int)(short)uVar6,DAT_0203cb90);
          uVar5 = (int)(short)uVar6 + 1;
          uVar6 = uVar5 & 0xffff;
        } while ((int)(uVar5 * 0x10000) >> 0x10 < (int)DAT_0203cb98);
      }
    }
    else {
      uVar6 = 0;
      if (0 < DAT_0203cb98) {
        do {
          sub_080F0200((int)(short)uVar6,DAT_0203cb90);
          uVar5 = (int)(short)uVar6 + 1;
          uVar6 = uVar5 & 0xffff;
        } while ((int)(uVar5 * 0x10000) >> 0x10 < (int)DAT_0203cb98);
      }
      uVar6 = 0;
      if (0 < DAT_0203cb9a) {
        do {
          sub_080F0200((short)uVar6 + 4,DAT_0203cb94);
          uVar5 = (int)(short)uVar6 + 1;
          uVar6 = uVar5 & 0xffff;
        } while ((int)(uVar5 * 0x10000) >> 0x10 < (int)DAT_0203cb9a);
      }
    }
    iVar7 = sub_080BF648(DAT_0203cb90 & 0xffff);
    sub_080EF8F8((uint)*(byte *)(iVar7 + 0x21));
    if (DAT_0203d16a != 0) {
      return;
    }
    sub_080E8C58(DAT_0203cb90 & 0xffff,DAT_0203cb94 & 0xffff,0);
    return;
  case 1:
    uVar6 = sub_080E8D64();
    if ((uVar6 & 0xff) == 0) {
      return;
    }
    uVar6 = sub_080ED67C();
    if (1 < uVar6) {
      uVar5 = sub_080ED32C(uVar6 & 0xffff);
      sub_080EC9AC(uVar6 & 0xff,0,uVar5 & 0xffff);
      uVar6 = sub_080ED32C(uVar6 & 0xffff);
      sub_080ECF70(uVar6 & 0xffff);
    }
    psVar8 = &DAT_0203cb78;
    sVar2 = 2;
    break;
  case 2:
    iVar7 = sub_080ED67C();
    if ((DAT_0203cb90 < 0x100) && (iVar7 != 1)) {
      if (iVar7 == 0) {
        DAT_0203d3a0 = 0;
        DAT_0203cb78 = 3;
        sub_080E4A40(0);
        return;
      }
      uVar6 = sub_080ECB10();
      if ((uVar6 & 0xff) == 0) {
        return;
      }
      psVar8 = &DAT_0203cb78;
      sVar2 = 4;
    }
    else {
      psVar8 = &DAT_0203cb78;
      sVar2 = 4;
    }
    break;
  case 3:
    if ((short)DAT_0203d3a0 < 8) {
      sub_080E8DEC();
      sub_080E845C(0,0,(int)*(char *)(((int)((uint)DAT_0203d3a0 << 0x10) >> 0x11) * 2 + 0x86be5a4));
      DAT_0203d3a0 = DAT_0203d3a0 + 1;
      return;
    }
    psVar8 = &DAT_0203cb78;
    sVar2 = 4;
    break;
  case 4:
    iVar7 = sub_080ED67C();
    sub_080E8DEC();
    iVar4 = sub_080EDAD0();
    if ((iVar4 == 0) || (iVar4 = sub_080EDAEC(DAT_0203cb90), iVar4 == 1)) {
      if (iVar7 != 0) {
        sub_080E4A40(0);
      }
      sub_080E760C();
      sub_080E7C98();
      DAT_0203c20c = sub_080AD0FC(0x86be738,0xffff);
    }
LAB_080e5152:
    DAT_0203cb78 = 0;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    return;
  case 5:
    if ((DAT_0203d398 == 0) && (uVar6 = sub_080E8D64(), (uVar6 & 0xff) == 0)) {
      return;
    }
    uVar6 = sub_080ED67C();
    if (1 < uVar6) {
      uVar5 = sub_080ED32C(uVar6 & 0xffff);
      sub_080EC9AC(uVar6 & 0xff,0,uVar5 & 0xffff);
      DAT_0203d36c = *(undefined2 *)((DAT_0203d398 + 1) * 2 + 0x86bf72c);
      uVar6 = sub_080ED32C(uVar6 & 0xffff);
      sub_080ECF70(uVar6 & 0xffff);
    }
    psVar8 = &DAT_0203cb78;
    sVar2 = 6;
    break;
  case 6:
    iVar7 = sub_080ED67C();
    if (((&DAT_0203cb90)[DAT_0203d398] < 0x100) && (iVar7 != 1)) {
      if (iVar7 == 0) {
        DAT_0203d3a0 = 0;
        DAT_0203cb78 = 7;
        sub_080E4A40((uint)DAT_0203d398);
        return;
      }
      uVar6 = sub_080ECB10();
      if ((uVar6 & 0xff) == 0) {
        return;
      }
      psVar8 = &DAT_0203cb78;
      sVar2 = 8;
    }
    else {
      psVar8 = &DAT_0203cb78;
      sVar2 = 8;
    }
    break;
  case 7:
    if ((short)DAT_0203d3a0 < 8) {
      sub_080E8DB4((uint)DAT_0203d398);
      sub_080E845C((uint)(byte)DAT_0203d398,0,
                   (int)*(char *)(((int)((uint)DAT_0203d3a0 << 0x10) >> 0x11) * 2 + 0x86be5a4));
      DAT_0203d3a0 = DAT_0203d3a0 + 1;
      return;
    }
    psVar8 = &DAT_0203cb78;
    sVar2 = 8;
    break;
  case 8:
    iVar7 = sub_080ED67C();
    sub_080E8DB4((uint)DAT_0203d398);
    if (iVar7 != 0) {
      sub_080E4A40((uint)DAT_0203d398);
    }
    if (DAT_0203d398 == 0) {
      iVar7 = sub_080EDAD0();
      if ((iVar7 == 0) || (iVar7 = sub_080EDAEC(DAT_0203cb90), iVar7 == 1)) {
        sub_080E760C();
        sub_080E7C98();
        DAT_0203c20c = sub_080AD0FC(0x86be738,0xffff);
      }
    }
    else {
      DAT_0203d39c = 0;
    }
    if (DAT_0203d398 != 0) goto LAB_080e5152;
    DAT_0203cb78 = 9;
    psVar8 = &DAT_0203d39a;
    sVar2 = 0x1e;
    break;
  case 9:
    if ((short)(DAT_0203d39a + -1) != 0) {
      DAT_0203d39a = DAT_0203d39a + -1;
      return;
    }
    DAT_0203cb78 = 5;
    psVar8 = (short *)&DAT_0203d398;
    sVar2 = DAT_0203d398 + 1;
    DAT_0203d39a = 0;
    break;
  default:
    goto switchD_080e4af6_default;
  }
  *psVar8 = sVar2;
switchD_080e4af6_default:
  return;
}


// sub_080E51BC @ 0x080E51BC

void sub_080E51BC(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x203c97a;
  REG_DMA3DAD = 0x6000300;
  REG_DMA3CNT = 0x84000010;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_080E51FC @ 0x080E51FC

void sub_080E51FC(void)

{
  if (DAT_0203c20c == 0) {
    sub_080E7484();
  }
  else {
    sub_080AD1FC(DAT_0203c20c);
    DAT_0203c20c = 0;
  }
  return;
}


// sub_080E5220 @ 0x080E5220

void sub_080E5220(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  switch(DAT_030063a0) {
  case 1:
    if (DAT_0203d388 == '\x01') {
      uVar1 = sub_080EF90C();
      sub_080C8048(uVar1,0x10,0x30,0);
      uVar1 = sub_080EF954();
      sub_080C8048(uVar1,0x10,0x3c,0);
    }
    break;
  case 2:
    DAT_030063a0 = 0;
    sub_080AD1FC(DAT_030063b8);
    sub_080E51FC();
    sub_08126F14();
    uVar3 = 0;
    do {
      sub_080BF938(uVar3);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 4);
    if (DAT_030063b4 == 1) {
      sub_080AF018();
    }
    else if (DAT_0203d16a == 0) {
      iVar2 = sub_080C2340(0xdf);
      if (iVar2 == 0) {
        sub_080AEFFC();
      }
      else {
        sub_080B9080();
      }
    }
    else {
      iVar2 = sub_080C2340(0xdf);
      if (iVar2 == 0) {
        sub_080B08AC();
      }
      else {
        DAT_0203d16a = 0;
        DAT_0203db6a = 0;
        sub_080ACFF4();
        sub_080B9080();
      }
    }
    if (DAT_0203d16a == 0) {
      if (((DAT_0200e7d4 != 0) && (DAT_0200e7d4 != 2)) && (iVar2 = sub_080C2340(0xdf), iVar2 == 0))
      {
        sub_080C700C();
      }
      if (DAT_0203d16a != 0) goto LAB_080e5352;
      sub_080E9008();
    }
    else {
LAB_080e5352:
      DAT_030063a0 = 6;
      iVar2 = sub_080C2340(0x14f);
      if (iVar2 != 0) {
        DAT_030063a0 = 8;
      }
    }
    sub_080C7C94();
    if (((DAT_0203cb90 != 0x106) && (DAT_0203cb90 != 0x116)) && (DAT_0203cb90 != 0x113)) {
      if (DAT_0203cb90 == 0x109) {
        sub_080C5170(0x14);
      }
      else if (DAT_03005180 == 0) {
        uVar3 = sub_080AD608();
        if (((uint)DAT_0203d38a == (uVar3 & 0xffff)) || (iVar2 = sub_080C2340(0xd5), iVar2 != 0)) {
          sub_080C5170((uint)DAT_0203d38a);
        }
        else {
          sub_080C51BC(4);
        }
      }
      else {
        uVar3 = sub_080AD67C((uint)DAT_030069f8);
        if ((uint)DAT_0203d38a == (uVar3 & 0xffff)) {
          sub_080C5170((uint)DAT_0203d38a);
        }
      }
    }
    break;
  case 3:
    iVar2 = sub_080C2340(1);
    if (iVar2 == 0) {
      iVar2 = sub_080C2340(0xd5);
      if (iVar2 == 0) {
        sub_080B9058();
      }
      else {
        DAT_030063a0 = 7;
        sub_080C2364(0x14f);
      }
    }
    else {
      DAT_030063a0 = 7;
      sub_080C2364(0xdf);
    }
    break;
  case 6:
    uVar3 = sub_080AB184();
    if ((uVar3 & 0xffff) != 1) {
      return;
    }
    iVar2 = sub_080C2340(1);
    if (((iVar2 != 0) && (iVar2 = sub_080C2340(0xdf), iVar2 != 0)) ||
       ((iVar2 = sub_080C2340(0xd5), iVar2 != 0 && (iVar2 = sub_080C2340(0x14f), iVar2 != 0)))) {
      DAT_030063a0 = 2;
      return;
    }
    goto LAB_080e54c0;
  case 8:
    uVar3 = sub_080AB184();
    if ((uVar3 & 0xffff) != 1) {
      return;
    }
LAB_080e54c0:
    DAT_030063a6 = 4;
    DAT_030063a0 = 0;
  }
  return;
}


// sub_080E54D4 @ 0x080E54D4

uint sub_080E54D4(void)

{
  return (uint)(DAT_030063a0 != 0);
}


// sub_080E54F0 @ 0x080E54F0

void sub_080E54F0(undefined4 arg0)

{
  DAT_0203d38a = (undefined2)arg0;
  return;
}


// sub_080E5504 @ 0x080E5504

void sub_080E5504(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080E5528 @ 0x080E5528

void sub_080E5528(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (DAT_0203cfa3 == '\x01') {
    REG_DMA3SAD = (uint)DAT_0203cfa2 * 0x1000 + 0x2001000;
    REG_DMA3DAD = 0x6016000;
    REG_DMA3CNT = 0x84000400;
    uVar1 = REG_DMA3CNT;
    iVar2 = REG_DMA3CNT;
    if (iVar2 < 0) {
      do {
        uVar3 = REG_DMA3CNT;
      } while ((uVar3 & 0x80000000) != 0);
    }
    DAT_0203cfa3 = '\0';
  }
  if (DAT_0203cfe3 == '\x01') {
    REG_DMA3SAD = (DAT_0203cfe2 + 2) * 0x1000 + 0x2001000;
    REG_DMA3DAD = 0x6017000;
    REG_DMA3CNT = 0x84000400;
    uVar1 = REG_DMA3CNT;
    iVar2 = REG_DMA3CNT;
    if (iVar2 < 0) {
      do {
        uVar3 = REG_DMA3CNT;
      } while ((uVar3 & 0x80000000) != 0);
    }
    DAT_0203cfe3 = '\0';
  }
  return;
}


// sub_080E55BC @ 0x080E55BC

void sub_080E55BC(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (DAT_0203cfa3 == '\x01') {
    REG_DMA3SAD = (uint)DAT_0203cfa2 * 0x1000 + 0x2001000;
    REG_DMA3DAD = 0x6016000;
    REG_DMA3CNT = 0x84000400;
    uVar1 = REG_DMA3CNT;
    iVar2 = REG_DMA3CNT;
    if (iVar2 < 0) {
      do {
        uVar3 = REG_DMA3CNT;
      } while ((uVar3 & 0x80000000) != 0);
    }
    DAT_0203cfa3 = '\0';
  }
  return;
}


// sub_080E5610 @ 0x080E5610

void sub_080E5610(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (DAT_0203cfe3 == '\x01') {
    REG_DMA3SAD = (DAT_0203cfe2 + 2) * 0x1000 + 0x2001000;
    REG_DMA3DAD = 0x6017000;
    REG_DMA3CNT = 0x84000400;
    uVar1 = REG_DMA3CNT;
    iVar2 = REG_DMA3CNT;
    if (iVar2 < 0) {
      do {
        uVar3 = REG_DMA3CNT;
      } while ((uVar3 & 0x80000000) != 0);
    }
    DAT_0203cfe3 = '\0';
  }
  return;
}


// sub_080E5668 @ 0x080E5668

void sub_080E5668(void)

{
  undefined4 in_r0;
  
  DisplayList_Add(in_r0,1);
  return;
}


// sub_080E5674 @ 0x080E5674

void sub_080E5674(void)

{
  return;
}


// sub_080E5678 @ 0x080E5678

void sub_080E5678(uint arg0,uint arg1,uint arg2,uint arg3)

{
  uint arg0_00;
  undefined4 uVar1;
  int iVar2;
  int arg0_01;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  dword arg1_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg0 & 0xffff;
  uVar5 = arg1 & 0xff;
  uVar4 = arg2 & 0xff;
  uVar3 = arg3 & 0xff;
  if (0x17b < arg0_00) {
    uVar1 = 0xff;
    goto LAB_080e57ae;
  }
  iVar2 = sub_080E444C(arg0_00);
  arg1_00 = *(dword *)(iVar2 + 4);
  if (uVar5 == 0) {
    if (uVar4 == 0) {
      arg0_01 = *(int *)(iVar2 + 0xc);
LAB_080e56ea:
      if (arg0_01 != 0) {
        HuffUnComp(arg0_01,0x200afc8,iVar2);
      }
    }
    else {
      LZ77UnCompWram(0x200afc8,(uVar4 - 1) * 0x800 + 0x30000b4,0x30000b4);
    }
  }
  else {
    if (uVar4 == 0) {
      arg0_01 = *(int *)(iVar2 + 0xc + uVar5 * 8);
      goto LAB_080e56ea;
    }
    if (*(int *)(iVar2 + 0xc + (uVar4 - 1) * 4 + uVar5 * 8) != 0) {
      LZ77UnCompWram(0x200afc8,(uVar4 - 1) * 0x800 + 0x30000b4,0x30000b4);
    }
  }
  if (uVar3 != 0xff) {
    if ((DAT_030020e4 == 0x80d977d) && (iVar2 = sub_080C2644(arg0_00), iVar2 == 0)) {
      arg1_00 = 0x86be584;
    }
    else {
      iVar2 = sub_080B098C();
      if (iVar2 != 0) {
        sub_080ACFCC(3,arg1_00,uVar3 * 0x20 + 0x3002bb0,0x20);
        sub_080AB090(uVar3 * 0x100000 + 0x1000000 >> 0x10,0x10,1,1);
        goto LAB_080e57a2;
      }
    }
    sub_080ACFCC(3,arg1_00,uVar3 * 0x20 + 0x3002fb0,0x20);
    sub_080AABB0();
  }
LAB_080e57a2:
  DAT_0203d3a4 = 0;
  uVar1 = 0;
LAB_080e57ae:
                    /* WARNING: Could not recover jumptable at 0x080e57bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1);
  return;
}


// sub_080E57CC @ 0x080E57CC

void sub_080E57CC(uint arg0)

{
  int iVar1;
  
  iVar1 = (arg0 & 0xff) * 0x40;
  if ((&DAT_0203cfa1)[iVar1] != '\0') {
    (&DAT_0203cfa1)[iVar1] = (&DAT_0203cfa1)[iVar1] + -1;
  }
  return;
}


// sub_080E57F0 @ 0x080E57F0

void sub_080E57F0(void)

{
  uint arg0;
  
  DAT_0203cfa2 = 0;
  DAT_0203cfa1 = 0;
  DAT_0203cfa5 = 0;
  if (DAT_0203cfa4 != '\x02') {
    DAT_0203cfa7 = 0;
    DAT_0203cfa6 = 0;
  }
  DAT_0203cfa4 = 0;
  arg0 = DAT_0203cb90 & 0xffff;
  sub_080E5678(arg0,0,0,0xe);
  sub_080E444C(arg0);
  sub_080E86B4(0x3003170,&DAT_0203cfb4,arg0);
  return;
}


// sub_080E584C @ 0x080E584C

void sub_080E584C(void)

{
  sub_080E5678((uint)(ushort)DAT_0203cb90,0,1,0xff);
  return;
}


// sub_080E586C @ 0x080E586C

void sub_080E586C(void)

{
  uint arg0;
  
  if (DAT_0203cb94 != 0xff) {
    DAT_0203cfe2 = 0;
    DAT_0203cfe1 = 0;
    DAT_0203cfe4 = 0;
    DAT_0203cfe7 = 0;
    DAT_0203cfe6 = 0;
    DAT_0203cfe5 = 0;
    arg0 = DAT_0203cb94 & 0xffff;
    sub_080E5678(arg0,0,0,0xf);
    sub_080E444C(arg0);
    sub_080E86B4(0x3003190,&DAT_0203cff4,arg0);
  }
  return;
}


// sub_080E58C8 @ 0x080E58C8

void sub_080E58C8(void)

{
  if (DAT_0203cb94 != 0xff) {
    sub_080E5678(DAT_0203cb94 & 0xffff,0,1,0xff);
  }
  return;
}


// sub_080E58F0 @ 0x080E58F0

void sub_080E58F0(undefined4 arg0,uint arg1)

{
  CpuFastSet(0x30000b4,(arg1 & 0xff) * 0x1000 + 0x2001000,0x400);
  return;
}


// sub_080E5910 @ 0x080E5910

void sub_080E5910(undefined4 arg0,uint arg1,uint arg2,uint arg3)

{
  sub_080E5678((uint)*(ushort *)(&DAT_0203cb90 + (arg1 & 0xff)),arg2 & 0xff,arg3 & 0xff,0xff);
  return;
}


// sub_080E5940 @ 0x080E5940

void sub_080E5940(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2003000;
  REG_DMA3DAD = 0x6017000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_080E5990 @ 0x080E5990

void sub_080E5990(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000800;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_080E59C8 @ 0x080E59C8

void sub_080E59C8(undefined4 arg0,int arg1)

{
  int iVar1;
  
  if ((*(ushort *)(&DAT_0203cb90 + arg1) != 0xffff) && (arg1 == 0)) {
    iVar1 = sub_080E444C((uint)*(ushort *)(&DAT_0203cb90 + arg1));
    if (*(int *)(iVar1 + 0x14) == 0) {
      DisplayList_Add(0x80e5941,1);
    }
    else {
      DisplayList_Add(0x80e5991,1);
    }
  }
  return;
}


// sub_080E5A18 @ 0x080E5A18

void sub_080E5A18(undefined4 arg0)

{
  DAT_03000058 = (int)DAT_0203cb7a;
  DAT_0203cb7a = (undefined2)arg0;
  return;
}


// sub_080E5A3C @ 0x080E5A3C

void sub_080E5A3C(void)

{
  DAT_0203cb7a = (short)DAT_03000058;
  return;
}


// sub_080E5A58 @ 0x080E5A58

void sub_080E5A58(undefined4 arg0,int arg1)

{
  int iVar1;
  uint uVar2;
  uint arg1_00;
  undefined4 arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 1) {
    uVar2 = (uint)(byte)(&DAT_030050e0)[DAT_0203d166];
    iVar1 = sub_080F3040();
    if (iVar1 == 0) {
      DAT_0203cb7a = 3;
      goto LAB_080e5bd4;
    }
    if (uVar2 == 0) {
      arg0_00 = 2;
      iVar1 = sub_080C00DC(0,0);
      arg1_00 = (uint)(iVar1 == 0xff);
      iVar1 = sub_080C00DC(0,1);
      if ((iVar1 == 0xff) || (iVar1 = sub_080C00DC(0,6), iVar1 == 0xff)) {
        arg1_00 = arg1_00 | 2;
      }
      iVar1 = sub_080C2340(3);
      if (iVar1 == 0) {
LAB_080e5b34:
        arg1_00 = arg1_00 | 4;
      }
      else {
        iVar1 = sub_080F3190();
LAB_080e5b30:
        if (iVar1 != 0) goto LAB_080e5b34;
      }
      uVar2 = sub_0812B3A4(1);
      if ((uVar2 & 0xffff) == 0) {
        arg1_00 = arg1_00 | 8;
      }
    }
    else {
      if (uVar2 < 4) {
        arg0_00 = 3;
        iVar1 = sub_080C00DC(uVar2,0);
        arg1_00 = (uint)(iVar1 == 0xff);
        iVar1 = sub_080C00DC(uVar2,1);
        if ((iVar1 == 0xff) || (iVar1 = sub_080C00DC(uVar2,6), iVar1 == 0xff)) {
          arg1_00 = arg1_00 | 2;
        }
        iVar1 = sub_080F4410(uVar2);
        if (iVar1 == 2) {
          iVar1 = sub_080F31E0();
          goto LAB_080e5b30;
        }
        goto LAB_080e5b34;
      }
      arg0_00 = 4;
      arg1_00 = 0;
      iVar1 = sub_0812C550(2,uVar2);
      if (iVar1 == 0) {
        arg1_00 = 2;
      }
      iVar1 = sub_080F4410(uVar2);
      if ((iVar1 != 2) || (iVar1 = sub_080F31E0(), iVar1 != 0)) {
        arg1_00 = arg1_00 | 4;
      }
    }
    sub_08126D50(arg0_00,arg1_00);
    DAT_0203d321 = (undefined1)arg1_00;
    sub_080C7AE0();
  }
  else {
    if (arg1 != 2) goto LAB_080e5bd4;
    arg0_00 = 5;
    sub_08126D50(5,0);
    DAT_0203d321 = 0;
    sub_080C7AE0();
  }
  DAT_0203c893 = (undefined1)arg0_00;
  DAT_03000030 = 0xf0;
  DAT_03000031 = 0xb0;
  DAT_03000035 = 0x18;
  DAT_03000034 = 0x58;
  DAT_03000038 = 0x1f;
  DAT_0300003a = 0x3f;
LAB_080e5bd4:
                    /* WARNING: Could not recover jumptable at 0x080e5bd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E5BFC @ 0x080E5BFC

void sub_080E5BFC(void)

{
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined4 local_10;
  
  sub_08126D50(1,0);
  sub_080C7AE0();
  sub_08126870();
  local_10 = 0;
  CpuSet(&local_10,&local_38,0x500000a);
  local_38 = 1;
  local_37 = 0;
  local_36 = 0;
  local_35 = 1;
  local_32 = 1;
  local_30 = 4;
  local_2e = 4;
  local_2c = 0;
  local_2a = 0;
  local_28 = 4;
  local_26 = 0;
  local_24 = 0;
  local_22 = 0;
  local_20 = 0;
  local_1c = 100;
  local_1e = 100;
  local_1a = 0x65;
  local_18 = 0x66;
  local_12 = 0xffff;
  local_14 = 0xffff;
  local_16 = 0xffff;
  sub_081268E4(0,&local_38);
  DAT_03000030 = 0xf0;
  DAT_03000031 = 0xb0;
  DAT_03000035 = 0x18;
  DAT_03000034 = 0x58;
  DAT_03000038 = 0x1f;
  DAT_0300003a = 0x3f;
  DAT_0203c890 = 0xff;
  return;
}


// sub_080E5CC4 @ 0x080E5CC4

void sub_080E5CC4(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_03000031 = DAT_03000031 + 8;
  DAT_03000030 = DAT_03000030 + -8;
  if (0x77 < DAT_03000031) {
    DAT_03000038 = 0x1f;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080ECF70(0x67);
  }
  return;
}


// sub_080E5D04 @ 0x080E5D04

void sub_080E5D04(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_03000034 = DAT_03000034 - 2;
  if (DAT_03000034 < 0x49) {
    DAT_03000038 = 0x1f;
    DAT_03000034 = 0x58;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080E5D38 @ 0x080E5D38

void sub_080E5D38(void)

{
  sub_080C7ACC();
  DAT_03000030 = 0xf0;
  DAT_03000031 = 0xf0;
  DAT_03000034 = 0x48;
  DAT_03000035 = 0x48;
  return;
}


// sub_080E5D68 @ 0x080E5D68

void sub_080E5D68(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_03000034 = DAT_03000034 + 8;
  if (0x57 < DAT_03000034) {
    DAT_03000038 = 0x3f;
    sub_08126F14();
    DAT_03000034 = 0x58;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080E5DA0 @ 0x080E5DA0

void sub_080E5DA0(void)

{
  undefined2 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = &DAT_0203d0f0;
  do {
    *puVar1 = 0xffff;
    puVar1[0x10] = 0xffff;
    puVar1 = puVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x10);
  return;
}


// sub_080E5DD4 @ 0x080E5DD4

void sub_080E5DD4(int arg0)

{
  short sVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar3 = (char *)sub_08126D1C(0);
  sVar1 = *(short *)(pcVar3 + 0x18);
  sub_08126A08(0);
  sub_080AA184(0x80008b0,0,0,0);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0203d164 = *(undefined2 *)(pcVar3 + 0x18);
  DAT_0203d162 = 0;
  if ((sVar1 != *(short *)(pcVar3 + 0x18)) && (DAT_0203c9e0 == '\x04')) {
    BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar3 + 0x18) * 4 + 0x86be5ec));
  }
  if ((DAT_030031b8 & 8) != 0) {
    *pcVar3 = '\x03';
    pcVar3[0x18] = '\x03';
    pcVar3[0x19] = '\0';
  }
  if (*pcVar3 == '\x03') {
    uVar2 = *(ushort *)(pcVar3 + 0x18);
    if (uVar2 == 1) {
      DAT_0203cb78 = 0xb;
    }
    else if (uVar2 < 2) {
      if (uVar2 == 0) {
        sub_080E5DA0();
        DAT_0203cb78 = 9;
        arg0_00 = 0;
        DAT_0203cb7a = 0;
        DAT_0203d166 = 0;
        DAT_0203d3aa = 0;
        while ((arg0_00 < 6 && (iVar4 = sub_080F30CC(arg0_00), iVar4 == -1))) {
          DAT_0203d166 = DAT_0203d166 + 1;
          DAT_0203d3aa = DAT_0203d3aa + 1;
          arg0_00 = arg0_00 + 1 & 0xff;
        }
        uVar5 = sub_080F30CC((int)DAT_0203d166);
        DAT_0203d0ce = (undefined2)uVar5;
        if (DAT_0203d16a == 0) {
          sub_080C6FF0();
        }
        else {
          sub_080C7038();
        }
        sub_080EC948();
      }
    }
    else if (uVar2 == 2) {
      DAT_0203cb78 = 0xc;
    }
    else if (uVar2 == 3) {
      if (DAT_0203d16a == 0) {
        sub_080C6FF0();
      }
      else {
        sub_080C7038();
      }
      sub_080EC948();
      DAT_0203cb78 = 0xd;
    }
    DAT_0203cb7a = 0;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_0203c890 = (undefined1)*(undefined2 *)(pcVar3 + 0x18);
    sub_081269B0(0);
    sub_080EA528();
  }
  else if (*pcVar3 == '\x06') {
    if (DAT_0203c9e0 == '\x04') {
      BattleMenu_SetMode(3,0x86be5da);
      sub_080EC99C(1);
    }
    else {
      BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar3 + 0x18) * 4 + 0x86be5ec));
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080e5fea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E5FF0 @ 0x080E5FF0

void sub_080E5FF0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 arg1;
  uint arg1_00;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined2 local_36;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  
  local_14 = 0;
  CpuSet(&local_14,&local_3c,0x500000a);
  local_3c = 1;
  local_3b = 0;
  local_3a = 0;
  local_39 = 1;
  local_36 = 1;
  local_34 = 5;
  local_32 = 5;
  local_30 = 0;
  local_2e = 0;
  local_2c = 5;
  local_2a = 0;
  local_28 = 0;
  local_26 = 0;
  local_24 = 0;
  local_20 = 100;
  local_22 = 100;
  local_1e = 0x65;
  local_1c = 0x66;
  local_16 = 0xffff;
  local_18 = 0xffff;
  local_1a = 0xffff;
  sub_081268E4(0,&local_3c);
  uVar2 = sub_080C3620((int)(char)(&DAT_030050e0)[DAT_0203d166]);
  uVar3 = sub_080E6130((uint)(byte)DAT_0203d166);
  arg1_00 = 0;
  iVar1 = (uVar3 & 0xff) * 5;
  iVar4 = iVar1;
  while (((uVar2 & 0xff) != (uint)*(byte *)(iVar4 + 0x86be610) &&
         (arg1_00 = arg1_00 + 1 & 0xff, arg1_00 < 5))) {
    iVar4 = arg1_00 + iVar1;
  }
  if (arg1_00 == 5) {
    arg1_00 = 0;
  }
  sub_08127960(0,arg1_00);
  arg1 = Battle_BuildActorPrompt((uint)(byte)DAT_0203d166);
  BattleMenu_SetMode(3,arg1);
  sub_080EC99C(1);
  sub_080C8490((int)DAT_0203d166);
  (&DAT_0203d0f0)[(char)(&DAT_030050e0)[DAT_0203d166]] = 0xffff;
  (&DAT_0203d110)[(char)(&DAT_030050e0)[DAT_0203d166]] = 0xffff;
  return;
}


// sub_080E6130 @ 0x080E6130

undefined4 sub_080E6130(uint arg0)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 2;
  cVar1 = (&DAT_030050e0)[arg0 & 0xff];
  if (cVar1 == '\0') {
    uVar2 = 0;
  }
  else if ((-1 < cVar1) && (cVar1 < '\x04')) {
    uVar2 = 1;
  }
  return uVar2;
}


// sub_080E6164 @ 0x080E6164

void sub_080E6164(int arg0)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 arg1;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar3 = (char *)sub_08126D1C(0);
  sVar2 = *(short *)(pcVar3 + 0x18);
  sub_08126A08(0);
  uVar4 = sub_080E6130((uint)(byte)DAT_0203d166);
  uVar4 = (uint)*(byte *)((uVar4 & 0xff) * 5 + (uint)*(ushort *)(pcVar3 + 0x18) + 0x86be610);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_0203d162 = 0;
  cVar1 = *pcVar3;
  if (cVar1 == '\x04') {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080F2FEC(&DAT_0203d0ce,&DAT_0203d166);
    if ((DAT_0203d166 < 0) || (DAT_0203d162 != 0)) {
      DAT_0203cb78 = 6;
    }
    else {
      DAT_0203cb7a = DAT_0203d162;
    }
  }
  else if (cVar1 == '\x03') {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_0203c890 = (undefined1)*(undefined2 *)(pcVar3 + 0x18);
    sub_080C35C4((int)(char)(&DAT_030050e0)[DAT_0203d166],uVar4);
    sub_080C8480((int)DAT_0203d166);
    DAT_0203cb7a = 2;
  }
  else if (cVar1 == '\x06') {
    if (DAT_0203c9e0 == '\x04') {
      arg1 = Battle_BuildActorPrompt((uint)(byte)DAT_0203d166);
      BattleMenu_SetMode(3,arg1);
      sub_080EC99C(1);
    }
    else {
      BattleMenu_SetMode(4,*(undefined4 *)(uVar4 * 4 + 0x86be620));
    }
  }
  else if ((sVar2 != *(short *)(pcVar3 + 0x18)) && (DAT_0203c9e0 == '\x04')) {
    BattleMenu_SetMode(4,*(undefined4 *)(uVar4 * 4 + 0x86be620));
  }
  sub_080AA184(0x80008b0,0,0,0);
                    /* WARNING: Could not recover jumptable at 0x080e62d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E62E8 @ 0x080E62E8

void sub_080E62E8(void)

{
  DAT_0203d310 = sub_080ABEB4(0);
  BattleMenu_SetMode(3,0x81230dc);
  sub_080EC99C(1);
  return;
}


// sub_080E6318 @ 0x080E6318

void sub_080E6318(int arg0)

{
  ushort uVar1;
  int iVar2;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar1 = DAT_030031b8 & 2;
  if ((DAT_030031b8 & 2) == 0) {
    iVar2 = sub_080ABF04(DAT_0203d310);
    if (iVar2 == 1) {
      if ((DAT_030031cc == 1) || (DAT_030031cc != 0)) {
        sub_080F2FEC(&DAT_0203d0ce,&DAT_0203d166);
        if (DAT_0203d166 < 0) {
          DAT_0203cb78 = 6;
        }
      }
      else {
        DAT_0203cb78 = 10;
        DAT_0203d0ce = uVar1;
      }
      DAT_0203cb7a = uVar1;
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    sub_080F2FEC(&DAT_0203d0ce,&DAT_0203d166);
    if (DAT_0203d166 < 0) {
      DAT_0203cb78 = 6;
    }
    DAT_0203cb7a = 0;
    sub_080AD1FC(DAT_0203d310);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080ECF70(0x66);
  }
  return;
}


// sub_080E6408 @ 0x080E6408

void sub_080E6408(int arg0)

{
  char *pcVar1;
  
  sub_08126A08(0);
  pcVar1 = (char *)sub_08126D1C(0);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (*pcVar1 == '\x03') {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_0203c890 = (undefined1)*(undefined2 *)(pcVar1 + 0x16);
  }
  sub_080AA184(0x8000868,0,0,0);
  return;
}


// sub_080E6468 @ 0x080E6468

void sub_080E6468(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_1c;
  
  DAT_0203d320 = 0;
  DAT_0203cb7c = 0;
  DAT_0203cb7e = 0;
  uVar1 = sub_080C35E4((int)(char)(&DAT_030050e0)[DAT_0203d166]);
  iVar2 = sub_080EF740((int)(char)(&DAT_030050e0)[DAT_0203d166],uVar1 & 0xff,&local_1c);
  if (iVar2 == 0) {
    DAT_0203d320 = 1;
    uVar3 = sub_080EC038(local_1c & 0xffff);
    uVar3 = Menu_ExpandListTemplate(uVar3,(int)(char)(&DAT_030050e0)[DAT_0203d166]);
    BattleMenu_SetMode(3,uVar3);
  }
  else {
    switch(uVar1 & 0xff) {
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10:
    case 0xb:
      break;
    default:
      DAT_0203cb7a = 3;
    }
  }
  return;
}


// sub_080E6550 @ 0x080E6550

void sub_080E6550(int arg0)

{
  uint uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (DAT_0203cb7a == 3) {
    sub_080F2F94(&DAT_0203d0ce,&DAT_0203d166);
    if (DAT_0203d166 < 6) {
      DAT_0203cb7a = 0;
    }
    else {
      DAT_0203d164 = 0;
      DAT_0203cb7a = 4;
    }
  }
  else {
    uVar1 = sub_080C35E4((int)(char)(&DAT_030050e0)[DAT_0203d166]);
    uVar1 = uVar1 & 0xff;
    if (DAT_0203d320 == '\x01') {
      uVar1 = 0xd;
    }
    _call_via_r0(*(undefined4 *)((uVar1 - 4 & 0xff) * 4 + 0x86be654));
    if (DAT_0203cb7a != 0) {
      return;
    }
  }
  *(undefined2 *)(arg0 + 0x1c) = 1;
  return;
}


// sub_080E6610 @ 0x080E6610

void sub_080E6610(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = sub_080C0148((uint)DAT_0203d166);
  iVar3 = sub_080EF5FC(uVar2,(int)(char)(&DAT_030050e0)[(short)DAT_0203d166]);
  if (iVar3 == 0x8000) {
    sVar1 = 3;
  }
  else {
    uVar2 = sub_080E6E08();
    sVar1 = (short)uVar2;
  }
  if (sVar1 == 3) {
    DAT_0203cb7a = 3;
  }
  if (sVar1 == 2) {
    DAT_0203cb7a = 0;
  }
  return;
}


// sub_080E6678 @ 0x080E6678

void sub_080E6678(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = sub_080C0148((uint)DAT_0203d166);
  iVar3 = sub_080EF5FC(uVar2,(int)(char)(&DAT_030050e0)[(short)DAT_0203d166]);
  if (iVar3 == 0x8000) {
    sVar1 = 3;
  }
  else {
    uVar2 = sub_080E6E08();
    sVar1 = (short)uVar2;
  }
  if (sVar1 == 3) {
    DAT_0203cb7a = 3;
  }
  if (sVar1 == 2) {
    DAT_0203cb7a = 0;
  }
  return;
}


// sub_080E66E0 @ 0x080E66E0

void sub_080E66E0(void)

{
  DAT_0203cb7a = 3;
  return;
}


// sub_080E66F4 @ 0x080E66F4

void sub_080E66F4(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080E6E08();
  if ((short)uVar1 == 3) {
    DAT_0203cb7a = 3;
  }
  if ((short)uVar1 == 2) {
    DAT_0203cb7a = 0;
  }
  return;
}


// sub_080E6724 @ 0x080E6724

void sub_080E6724(void)

{
  DAT_0203cb7a = 3;
  return;
}


// sub_080E6738 @ 0x080E6738

void sub_080E6738(void)

{
  uint uVar1;
  
  uVar1 = sub_080EA934();
  if ((uVar1 & 0xff) == 1) {
    DAT_0203cb7a = 0;
  }
  return;
}


// sub_080E6760 @ 0x080E6760

void sub_080E6760(void)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  char *pcVar4;
  undefined4 arg1;
  uint uVar5;
  int iVar6;
  
  switch(DAT_0203cb7c) {
  case 0:
    iVar6 = sub_080C2340(0xe5);
    if (iVar6 == 0) {
      sub_08126D50(6,0);
      sub_08126928(2,1,1,2);
    }
    else {
      sub_08126D50(5,0);
      sub_08126928(2,1,1,3);
    }
    DAT_0203c892 = iVar6 != 0;
    DAT_0203d321 = 0;
    DAT_03000030 = 0xf0;
    DAT_03000031 = 0xb0;
    DAT_03000035 = 0x18;
    DAT_03000034 = 0x58;
    sub_080C7AE0();
    BattleMenu_SetMode(3,0x812326a);
    sub_080EC99C(1);
    DAT_0203cb7c = 1;
    break;
  case 1:
    iVar6 = sub_080C7AF0();
    if (iVar6 != 2) {
      DAT_0203cb7c = 2;
    }
    break;
  case 2:
    pcVar4 = (char *)sub_08126D1C(2);
    sVar3 = *(short *)(pcVar4 + 0x18);
    sub_08126A08(2);
    bVar1 = *(byte *)((uint)DAT_0203c892 * 3 + (uint)*(ushort *)(pcVar4 + 0x18) + 0x86be67c);
    DAT_0203d162 = 0;
    cVar2 = *pcVar4;
    if (cVar2 == '\x04') {
      DAT_0203cb7c = 6;
      sub_080C7ACC();
    }
    else if (cVar2 == '\x03') {
      DAT_0203cb7c = (ushort)bVar1;
      DAT_0203cb7e = 0;
      DAT_03000031 = 0xf0;
      sub_080C7ACC();
    }
    else if (cVar2 == '\x06') {
      if (DAT_0203c9e0 == '\x04') {
        arg1 = Battle_BuildActorPrompt((uint)(byte)DAT_0203d166);
        BattleMenu_SetMode(3,arg1);
        sub_080EC99C(1);
      }
      else {
        BattleMenu_SetMode(4,*(undefined4 *)((uint)bVar1 * 4 + 0x86be684));
      }
    }
    else if ((sVar3 != *(short *)(pcVar4 + 0x18)) && (DAT_0203c9e0 == '\x04')) {
      BattleMenu_SetMode(4,*(undefined4 *)((uint)bVar1 * 4 + 0x86be684));
    }
    sub_080AA184(0x80008b0,0,0,0);
    break;
  case 3:
    iVar6 = sub_080C7AF0();
    if (iVar6 == 1) {
      return;
    }
    uVar5 = sub_080F332C();
    uVar5 = uVar5 & 0xff;
    if (uVar5 != 2) {
      if (uVar5 < 3) {
        if (uVar5 != 1) {
          return;
        }
        DAT_0203cb7c = 8;
        sub_080C7ACC();
        return;
      }
      if (uVar5 != 3) {
        return;
      }
    }
    goto LAB_080e69f6;
  case 4:
    uVar5 = sub_080F33E8();
    goto joined_r0x080e69f0;
  case 5:
    iVar6 = sub_080C7AF0();
    if (iVar6 == 1) {
      return;
    }
    uVar5 = sub_080F3398();
    uVar5 = uVar5 & 0xffff;
joined_r0x080e69f0:
    if (uVar5 != 0) {
LAB_080e69f6:
      DAT_0203cb7c = 0;
    }
    break;
  case 6:
    sub_081269B0(2);
    DAT_0203cb7c = 7;
    goto LAB_080e6a40;
  case 7:
    iVar6 = sub_080C7AF0();
    if (iVar6 != 1) {
      DAT_0203cb7a = 0;
      DAT_0203cb7c = 0;
    }
    break;
  case 8:
    sub_081269B0(2);
    DAT_0203cb7c = 9;
LAB_080e6a40:
    DAT_03000031 = 0xf0;
    break;
  case 9:
    iVar6 = sub_080C7AF0();
    if (iVar6 != 1) {
      DAT_0203cb7a = 3;
      DAT_0203cb7c = 0;
    }
  }
  return;
}


// sub_080E6A7C @ 0x080E6A7C

void sub_080E6A7C(void)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  dword dVar4;
  uint arg1;
  
  switch(DAT_0203cb7c) {
  case 0:
    sub_0812C490(1,(uint)(byte)DAT_0203d166);
    puVar3 = &DAT_0203cb7c;
    uVar1 = 1;
    break;
  case 1:
    uVar2 = sub_0812C4D4();
    if (uVar2 == 0xffffffff) {
      return;
    }
    if ((uVar2 & 0xffff0000) == 0xfffe0000) {
      dVar4 = 0x97c;
      goto LAB_080e6bb8;
    }
    arg1 = uVar2 & 0xff;
    sub_080F3EF4((int)(char)(&DAT_030050e0)[DAT_0203d166],arg1);
    *(short *)(&DAT_0203d130 + (char)(&DAT_030050e0)[DAT_0203d166] * 2) =
         (short)((uVar2 & 0xffff0000) >> 0x10);
    puVar3 = &DAT_0203cb7c;
    uVar1 = 2;
    DAT_0203cb7c = 2;
    if (arg1 == 0x3e) {
      DAT_0203cb7c = 5;
      sub_081293F8(3);
      return;
    }
    if (arg1 == 0x3f) {
      DAT_0203cb7c = 5;
      sub_081293F8(7);
      return;
    }
    break;
  case 2:
    DAT_0203cb7c = 0;
    dVar4 = 0x97a;
LAB_080e6bb8:
    puVar3 = (undefined2 *)(dVar4 + 0x203c200);
    uVar1 = 3;
    break;
  case 3:
    DAT_0203cb7a = 0;
    DAT_0203cb7c = 0;
    return;
  default:
    goto switchD_080e6a98_caseD_4;
  case 5:
    uVar2 = sub_08129440();
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 0) {
      return;
    }
    if (uVar2 != 1) {
      if (uVar2 != 0xff) {
        return;
      }
      dVar4 = 0x97c;
      goto LAB_080e6bb8;
    }
    puVar3 = &DAT_0203cb7c;
    uVar1 = 2;
  }
  *puVar3 = uVar1;
switchD_080e6a98_caseD_4:
  return;
}


// sub_080E6BE4 @ 0x080E6BE4

void sub_080E6BE4(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar2 = &DAT_0203cb7c;
  if (DAT_0203cb7c == 1) {
    uVar3 = sub_0812B1D4();
    if (uVar3 != 0xffffffff) {
      if ((uVar3 & 0xffff0000) == 0xfffe0000) {
        DAT_0203cb7c = 3;
      }
      else {
        sub_080F3EF4((int)(char)(&DAT_030050e0)[DAT_0203d166],uVar3 & 0xff);
        *(short *)(&DAT_0203d130 + (char)(&DAT_030050e0)[DAT_0203d166] * 2) =
             (short)((uVar3 & 0xffff0000) >> 0x10);
        DAT_0203cb7c = 2;
      }
      sub_080EA210();
    }
  }
  else if (DAT_0203cb7c < 2) {
    if (DAT_0203cb7c == 0) {
      sub_0812B194(1,0);
      DAT_0203cb7c = 1;
    }
  }
  else {
    if (DAT_0203cb7c == 2) {
      DAT_0203cb7c = 0;
      puVar2 = &DAT_0203cb7a;
      uVar1 = 3;
    }
    else {
      if (DAT_0203cb7c != 3) goto LAB_080e6cbc;
      uVar1 = 0;
      DAT_0203cb7a = 0;
    }
    *puVar2 = uVar1;
  }
LAB_080e6cbc:
                    /* WARNING: Could not recover jumptable at 0x080e6cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E6CCC @ 0x080E6CCC

void sub_080E6CCC(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar2 = &DAT_0203cb7c;
  if (DAT_0203cb7c == 1) {
    uVar3 = sub_0812C4D4();
    if (uVar3 != 0xffffffff) {
      if ((uVar3 & 0xffff0000) == 0xfffe0000) {
        DAT_0203cb7c = 3;
      }
      else {
        sub_080F3EF4((int)(char)(&DAT_030050e0)[DAT_0203d166],uVar3 & 0xff);
        *(short *)(&DAT_0203d130 + (char)(&DAT_030050e0)[DAT_0203d166] * 2) =
             (short)((uVar3 & 0xffff0000) >> 0x10);
        DAT_0203cb7c = 2;
      }
      sub_080EA210();
    }
  }
  else {
    if (DAT_0203cb7c < 2) {
      if (DAT_0203cb7c != 0) goto LAB_080e6dac;
      sub_0812C490(2,(uint)(byte)DAT_0203d166);
      uVar1 = 1;
    }
    else if (DAT_0203cb7c == 2) {
      DAT_0203cb7c = 0;
      puVar2 = &DAT_0203cb7a;
      uVar1 = 3;
    }
    else {
      if (DAT_0203cb7c != 3) goto LAB_080e6dac;
      uVar1 = 0;
      DAT_0203cb7a = 0;
    }
    *puVar2 = uVar1;
  }
LAB_080e6dac:
                    /* WARNING: Could not recover jumptable at 0x080e6db4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E6DBC @ 0x080E6DBC

void sub_080E6DBC(uint arg0)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xffff;
  sub_080EC9AC(0xd2,0,0xffff);
  if (uVar1 != 0) {
    DAT_0203c895 = (char)uVar1 + -1;
  }
  DAT_0203d36e = 0x30;
  DAT_0203d36c = *(undefined2 *)(uVar1 * 2 + 0x86bf72c);
  return;
}


// sub_080E6E08 @ 0x080E6E08

undefined4 sub_080E6E08(void)

{
  int iVar1;
  undefined4 uVar2;
  
  switch(DAT_0203cb7e) {
  case 0:
    iVar1 = sub_080F3060();
    if ((iVar1 == 0) || (iVar1 = sub_080ED954(), iVar1 == 0)) {
      DAT_0203cb7e = 3;
      return 0;
    }
    uVar2 = sub_080EC038(0x149);
    uVar2 = Menu_ExpandListTemplate(uVar2,0);
    BattleMenu_SetMode(3,uVar2);
    sub_080EC99C(1);
    sub_080E6DBC(1);
    DAT_03000050 = '\x14';
    break;
  case 1:
    if ((DAT_030031b8 & 0x10) == 0) {
      if ((DAT_030031b8 & 0x20) == 0) {
        if ((DAT_030031b8 & 1) != 0) {
          sub_080EDA4C((int)DAT_0203d0ce,(int)((uint)DAT_0203c895 * 0x40000 + 0x100000) >> 0x10);
          sub_080ECF70(0x65);
          sub_080ECB38();
          DAT_0203cb7e = 3;
          return 0;
        }
        if ((DAT_030031b8 & 2) != 0) {
          sub_080ECF70(0x66);
          sub_080ECB38();
          DAT_0203cb7e = 2;
          return 0;
        }
        return 0;
      }
      if (DAT_0203c895 == 0) {
        return 0;
      }
      DAT_0203d36c = 0x50;
      DAT_0203c895 = (byte)DAT_030031b8 & 0x10;
    }
    else {
      if (DAT_0203c895 == 1) {
        return 0;
      }
      DAT_0203c895 = 1;
      DAT_0203d36c = 0xa0;
    }
    sub_080ECF70(100);
    return 0;
  case 2:
    DAT_0203cb7e = 0;
    return 2;
  case 3:
    DAT_0203cb7e = 0;
    return 3;
  case 4:
    if (DAT_03000050 != '\0') {
      DAT_03000050 = DAT_03000050 + -1;
      return 0;
    }
    break;
  default:
    goto switchD_080e6e2e_default;
  }
  DAT_0203cb7e = 1;
switchD_080e6e2e_default:
  return 0;
}


// sub_080E6FA0 @ 0x080E6FA0

undefined4 sub_080E6FA0(void)

{
  int iVar1;
  
  switch(DAT_0203cb7e) {
  case 0:
    iVar1 = sub_080F3060();
    if ((iVar1 == 0) || (iVar1 = sub_080ED954(), iVar1 == 0)) {
      DAT_0203cb7e = 3;
      return 0;
    }
    sub_080E6DBC(1);
    DAT_03000051 = '\x14';
    break;
  case 1:
    if ((DAT_030031b8 & 0x10) == 0) {
      if ((DAT_030031b8 & 0x20) == 0) {
        if ((DAT_030031b8 & 1) != 0) {
          sub_080EDA4C((int)DAT_0203d0ce,(int)((uint)DAT_0203c895 * 0x40000 + 0x100000) >> 0x10);
          sub_080ECF70(0x65);
          sub_080ECB38();
          DAT_0203cb7e = 3;
          return 0;
        }
        if ((DAT_030031b8 & 2) != 0) {
          sub_080ECF70(0x66);
          sub_080ECB38();
          DAT_0203cb7e = 2;
          return 0;
        }
        return 0;
      }
      if (DAT_0203c895 == 0) {
        return 0;
      }
      DAT_0203d36c = 0x50;
      DAT_0203c895 = (byte)DAT_030031b8 & 0x10;
    }
    else {
      if (DAT_0203c895 == 1) {
        return 0;
      }
      DAT_0203c895 = 1;
      DAT_0203d36c = 0xa0;
    }
    sub_080ECF70(100);
    return 0;
  case 2:
    DAT_0203cb7e = 0;
    return 2;
  case 3:
    DAT_0203cb7e = 0;
    return 3;
  case 4:
    if (DAT_03000051 != '\0') {
      DAT_03000051 = DAT_03000051 + -1;
      return 0;
    }
    break;
  default:
    goto switchD_080e6fc6_default;
  }
  DAT_0203cb7e = 1;
switchD_080e6fc6_default:
  return 0;
}


// sub_080E711C @ 0x080E711C

void sub_080E711C(int arg0,undefined4 arg1,int arg2)

{
  dword dVar1;
  ushort in_r3;
  
  switch(arg1) {
  case 0:
    in_r3 = (ushort)DAT_0203c890;
    goto switchD_080e7130_default;
  case 1:
    dVar1 = 0x978;
    break;
  case 2:
    dVar1 = 0x97a;
    break;
  case 3:
    dVar1 = 0x97c;
    break;
  case 4:
    dVar1 = 0x97e;
    break;
  default:
    goto switchD_080e7130_default;
  }
  in_r3 = *(ushort *)(dVar1 + 0x203c200);
switchD_080e7130_default:
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((short)in_r3 == arg2) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080E7194 @ 0x080E7194

void sub_080E7194(void)

{
  if (DAT_030063a0 != 3) {
    DAT_030063a0 = 2;
  }
  sub_080EA964();
  sub_080EA9E8(0);
  Font_ResetGlyphSpriteCache(0x180);
  sub_080C84A0();
  sub_081269D0();
  return;
}


// sub_080E71C4 @ 0x080E71C4

void sub_080E71C4(void)

{
  if (DAT_030063a0 != 3) {
    DAT_030063a0 = 2;
  }
  return;
}


// sub_080E71DC @ 0x080E71DC

void sub_080E71DC(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = (uint)(byte)arg1 * 4;
  pbVar3 = (byte *)(iVar2 + 0x86be6a4);
  iVar1 = (uint)(byte)arg0 * 0xc;
  if ((uint)(byte)(&DAT_0203d061)[iVar1] != (uint)(byte)arg1) {
    CpuFastSet((uint)*pbVar3 * 0x80 + 0x81a81b8,(uint)(byte)arg0 * 0x80 + 0x30010b4,0x20);
    (&DAT_0203d061)[iVar1] = (byte)arg1;
    (&DAT_0203d062)[iVar1] = *pbVar3;
    (&DAT_0203d063)[iVar1] = (&DAT_086be6a5)[iVar2];
    DAT_030063c0 = (byte)arg0;
    sub_080E5668();
  }
  return;
}


// sub_080E724C @ 0x080E724C

void sub_080E724C(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 local_24;
  
  local_24 = 0;
  CpuFastSet(&local_24,0x30010b4,0x1000100);
  uVar5 = 0;
  do {
    if (((&DAT_0203cbae)[uVar5 * 0x40] == -0x8000) &&
       (((&DAT_0203cbb0)[uVar5 * 0x40] & 0x8000) == 0)) {
      uVar1 = sub_080E739C((uint)(ushort)(&DAT_0203cbb0)[uVar5 * 0x40]);
      iVar3 = (uVar1 & 0xff) * 4;
      pbVar4 = (byte *)(iVar3 + 0x86be6a4);
      CpuFastSet((uint)*pbVar4 * 0x80 + 0x81a81b8,uVar5 * 0x80 + 0x30010b4,0x20);
      iVar2 = uVar5 * 0xc;
      (&DAT_0203d060)[iVar2] = (char)uVar5;
      (&DAT_0203d061)[iVar2] = (char)uVar1;
      (&DAT_0203d062)[iVar2] = *pbVar4;
      (&DAT_0203d063)[iVar2] = (&DAT_086be6a5)[iVar3];
      (&DAT_0203d068)[iVar2] = 1;
      (&DAT_0203d069)[iVar2] = 0;
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 8);
  DisplayList_Add(0x80e7365,1);
  DAT_0203d0c0 = 0;
  return;
}


// sub_080E7318 @ 0x080E7318

void sub_080E7318(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = (uint)DAT_030063c0 * 0x80 + 0x30010b4;
  REG_DMA3DAD = (uint)DAT_030063c0 * 0x80 + 0x6011500;
  REG_DMA3CNT = 0x84000020;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_080E7364 @ 0x080E7364

void sub_080E7364(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x30010b4;
  REG_DMA3DAD = 0x6011500;
  REG_DMA3CNT = 0x84000100;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_080E739C @ 0x080E739C

uint sub_080E739C(uint arg0)

{
  uint uVar1;
  
  uVar1 = -(arg0 & 8) >> 0x1f;
  if ((arg0 & 0x10) != 0) {
    uVar1 = 2;
  }
  if ((arg0 & 2) != 0) {
    uVar1 = 3;
  }
  if ((arg0 & 0x80) != 0) {
    uVar1 = 4;
  }
  if ((arg0 & 0x100) != 0) {
    uVar1 = 5;
  }
  if ((arg0 & 0x20) != 0) {
    uVar1 = 6;
  }
  if ((arg0 & 0x40) != 0) {
    uVar1 = 7;
  }
  if ((arg0 & 0x200) != 0) {
    uVar1 = 8;
  }
  if ((arg0 & 1) != 0) {
    uVar1 = 9;
  }
  if ((arg0 & 0x800) != 0) {
    uVar1 = 0xb;
  }
  if ((arg0 & 4) != 0) {
    uVar1 = 0xc;
  }
  if ((arg0 & 0x1000) != 0) {
    uVar1 = 0xd;
  }
  if ((arg0 & 0x2000) != 0) {
    uVar1 = 0xe;
  }
  if ((arg0 & 0x8000) != 0) {
    uVar1 = 0x10;
  }
  return uVar1;
}


// sub_080E7444 @ 0x080E7444

void sub_080E7444(void)

{
  byte bVar1;
  undefined1 *puVar2;
  
  puVar2 = &DAT_0203d060;
  bVar1 = 0;
  do {
    puVar2[1] = 0xff;
    *puVar2 = 0xff;
    puVar2[3] = 0;
    puVar2[2] = 0;
    *(undefined2 *)(puVar2 + 6) = 0;
    *(undefined2 *)(puVar2 + 4) = 0;
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2 = puVar2 + 0xc;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 8);
  return;
}


// sub_080E7484 @ 0x080E7484

void sub_080E7484(void)

{
  short *arg0;
  uint uVar1;
  
  uVar1 = 0;
  do {
    arg0 = (short *)(uVar1 * 100 + 0x2009004);
    if ((*arg0 != 0) && ((&DAT_02009024)[uVar1 * 0x19] == 0x80e7a45)) {
      sub_080AD1FC(arg0);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x40);
  return;
}


// sub_080E74BC @ 0x080E74BC

void sub_080E74BC(void)

{
  DAT_0203c20c = sub_080AD0FC(0x86be738,0xffff);
  return;
}


// sub_080E74DC @ 0x080E74DC

void sub_080E74DC(void)

{
  byte bVar1;
  undefined1 *puVar2;
  
  puVar2 = &DAT_0203d060;
  bVar1 = 0;
  do {
    puVar2[1] = 0xff;
    *puVar2 = 0xff;
    puVar2[3] = 0;
    puVar2[2] = 0;
    *(undefined2 *)(puVar2 + 4) = 0;
    *(undefined2 *)(puVar2 + 6) = 0xfffc;
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2 = puVar2 + 0xc;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 8);
  DAT_0203d0c4 = 0;
  DAT_0203d0c5 = 0;
  return;
}


// sub_080E7538 @ 0x080E7538

void sub_080E7538(uint arg0,undefined4 arg1,undefined4 arg2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = arg0 & 0xff;
  iVar2 = uVar1 * 0xc;
  switch((undefined1)arg1) {
  case 0:
    (&DAT_0203d068)[iVar2] = 0;
    (&DAT_0203d06a)[iVar2] = 0;
    break;
  case 1:
    (&DAT_0203d066)[uVar1 * 6] = 0xfffc;
    (&DAT_0203d068)[iVar2] = 1;
    (&DAT_0203d06a)[iVar2] = 0;
    break;
  case 2:
    (&DAT_0203d068)[iVar2] = 2;
    DAT_0203d0c0 = 1;
    (&DAT_0203d06a)[iVar2] = 0;
    (&DAT_0203d06b)[iVar2] = 0;
    break;
  case 3:
    (&DAT_0203d068)[iVar2] = 3;
    (&DAT_0203d061)[iVar2] = 0xff;
    (&DAT_0203d066)[uVar1 * 6] = 4;
    DAT_0203d0c0 = 1;
    (&DAT_0203d06a)[iVar2] = (undefined1)arg2;
    break;
  case 4:
    (&DAT_0203d068)[iVar2] = 4;
    (&DAT_0203d06a)[iVar2] = 0;
  }
  return;
}


// sub_080E75DC @ 0x080E75DC

uint sub_080E75DC(uint arg0,undefined4 arg1)

{
  return (uint)((&DAT_0203d068)[(arg0 & 0xff) * 0xc] == (char)arg1);
}


// sub_080E760C @ 0x080E760C

void sub_080E760C(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  
  sub_080E74DC();
  uVar4 = 0;
  do {
    uVar1 = sub_080C0830();
    if (((uVar1 & 0xffff) == 0) && (iVar2 = sub_080C09B0(uVar4 + 0x10), iVar2 != 0)) {
      sub_080E7538(uVar4,3,uVar4 * 0x3000000 >> 0x18);
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 8);
  iVar2 = sub_080ED954();
  if (iVar2 == 0) {
    DAT_0203d0c4 = 0;
    uVar1 = 0;
    uVar4 = 0;
    do {
      uVar3 = sub_080C0830();
      if (((uVar3 & 0xffff) == 0) && (iVar2 = sub_080C09B0(uVar4 + 0x10), iVar2 != 0)) {
        sub_080E7538(uVar4,3,uVar1 * 0x3000000 >> 0x18);
        DAT_0203d0c4 = DAT_0203d0c4 + 1;
        uVar1 = uVar1 + 1 & 0xff;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 8);
    uVar5 = 0;
    uVar4 = (uint)DAT_0203d0c4;
    uVar1 = 0;
    do {
      if ((&DAT_0203d068)[uVar1 * 0xc] != '\0') {
        (&DAT_0203d060)[uVar1 * 0xc] = (char)uVar1;
        (&DAT_0203d064)[uVar1 * 6] = uVar5 * 0xe + (ushort)*(byte *)(uVar4 + 0x86be707);
        uVar5 = uVar5 + 1 & 0xff;
      }
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 8);
  }
  else {
    DAT_0203d0c4 = 0;
    DAT_0203d0c5 = 0;
    uVar1 = 0;
    uVar4 = 0;
    do {
      uVar3 = sub_080C0830();
      if (((uVar3 & 0xffff) == 0) && (iVar2 = sub_080C09B0(uVar4 + 0x10), iVar2 != 0)) {
        sub_080E7538(uVar4,3,uVar1 * 0x3000000 >> 0x18);
        DAT_0203d0c4 = DAT_0203d0c4 + 1;
        uVar1 = uVar1 + 1 & 0xff;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 4);
    uVar5 = 0;
    uVar4 = (uint)DAT_0203d0c4;
    uVar1 = 0;
    do {
      if ((&DAT_0203d068)[uVar1 * 0xc] != '\0') {
        (&DAT_0203d060)[uVar1 * 0xc] = (char)uVar1;
        (&DAT_0203d064)[uVar1 * 6] = uVar5 * 0xe + (ushort)*(byte *)(uVar4 + 0x86be70f);
        uVar5 = uVar5 + 1 & 0xff;
      }
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
    uVar1 = 0;
    uVar4 = 4;
    do {
      uVar3 = sub_080C0830();
      if (((uVar3 & 0xffff) == 0) && (iVar2 = sub_080C09B0(uVar4 + 0x10), iVar2 != 0)) {
        sub_080E7538(uVar4,3,uVar1 * 0x3000000 >> 0x18);
        DAT_0203d0c5 = DAT_0203d0c5 + 1;
        uVar1 = uVar1 + 1 & 0xff;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 8);
    uVar5 = 0;
    uVar4 = (uint)DAT_0203d0c5;
    uVar1 = 4;
    do {
      if ((&DAT_0203d068)[uVar1 * 0xc] != '\0') {
        (&DAT_0203d060)[uVar1 * 0xc] = (char)uVar1;
        (&DAT_0203d064)[uVar1 * 6] = uVar5 * 0xe + (ushort)*(byte *)(uVar4 + 0x86be713);
        uVar5 = uVar5 + 1 & 0xff;
      }
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 8);
  }
  return;
}


// sub_080E7834 @ 0x080E7834

uint sub_080E7834(uint arg0)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  uVar1 = sub_080C0818(arg0_00);
  uVar2 = sub_080F401C(arg0_00);
  iVar3 = sub_080F4038(arg0_00);
  if (*(char *)(&DAT_0203cfa8 + arg0_00 * 6) == '\x02') {
    uVar1 = *(byte *)((int)&DAT_0203cfaa + arg0_00 * 0xc + 1) + 0x13 & 0xff;
  }
  else if ((uVar1 & 0x8000) == 0) {
    if ((int)(short)uVar2 < (iVar3 << 0x10) >> 0x12) {
      uVar1 = 2;
    }
    else if ((uVar1 & 0x4000) == 0) {
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x1000) == 0) {
          if ((uVar1 & 0x800) == 0) {
            if ((uVar1 & 0x400) == 0) {
              if ((uVar1 & 0x200) == 0) {
                if ((uVar1 & 0x100) == 0) {
                  if ((uVar1 & 0x80) == 0) {
                    if ((uVar1 & 0x40) == 0) {
                      if ((uVar1 & 0x20) == 0) {
                        if ((uVar1 & 0x10) == 0) {
                          if ((uVar1 & 8) == 0) {
                            if ((uVar1 & 4) == 0) {
                              if ((uVar1 & 2) == 0) {
                                if ((uVar1 & 1) == 0) {
                                  uVar1 = 0;
                                }
                                else {
                                  uVar1 = 0x12;
                                }
                              }
                              else {
                                uVar1 = 0x11;
                              }
                            }
                            else {
                              uVar1 = 0x10;
                            }
                          }
                          else {
                            uVar1 = 0xf;
                          }
                        }
                        else {
                          uVar1 = 0xe;
                        }
                      }
                      else {
                        uVar1 = 0xd;
                      }
                    }
                    else {
                      uVar1 = 0xc;
                    }
                  }
                  else {
                    uVar1 = 0xb;
                  }
                }
                else {
                  uVar1 = 10;
                }
              }
              else {
                uVar1 = 9;
              }
            }
            else {
              uVar1 = 8;
            }
          }
          else {
            uVar1 = 6;
          }
        }
        else {
          uVar1 = 5;
        }
      }
      else {
        uVar1 = 4;
      }
    }
    else {
      uVar1 = 3;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// sub_080E7968 @ 0x080E7968

void sub_080E7968(void)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint arg0;
  
  arg0 = 0x10;
  do {
    iVar4 = arg0 * 0xc;
    sub_080F2F64(arg0);
    switch(*(undefined1 *)(&DAT_0203cfa8 + arg0 * 6)) {
    case 1:
      uVar5 = sub_080E7834(arg0);
      if ((uVar5 & 0xff) != (uint)(byte)(&DAT_0203cfa1)[iVar4]) {
        DAT_0203d0c0 = 1;
      }
      break;
    case 2:
      if (*(byte *)(&DAT_0203cfaa + arg0 * 6) < 10) {
        *(byte *)(&DAT_0203cfaa + arg0 * 6) = *(byte *)(&DAT_0203cfaa + arg0 * 6) + 1;
      }
      else {
        *(undefined1 *)(&DAT_0203cfaa + arg0 * 6) = 0;
        DAT_0203d0c0 = 1;
        bVar3 = *(char *)((int)&DAT_0203cfaa + iVar4 + 1) + 1;
        *(byte *)((int)&DAT_0203cfaa + iVar4 + 1) = bVar3;
        if (4 < bVar3) {
          *(undefined1 *)(&DAT_0203cfa8 + arg0 * 6) = 0;
          *(undefined1 *)((int)&DAT_0203cfaa + iVar4 + 1) = 0;
        }
      }
      break;
    case 3:
      if (*(char *)(&DAT_0203cfaa + arg0 * 6) == '\0') {
        uVar1 = *(ushort *)(&DAT_0203cfa6 + iVar4);
        *(short *)(&DAT_0203cfa6 + iVar4) = (short)(uVar1 - 2);
        if ((int)((uVar1 - 2) * 0x10000) >> 0x10 < -4) {
          *(undefined2 *)(&DAT_0203cfa6 + iVar4) = 0xfffc;
          *(undefined1 *)(&DAT_0203cfa8 + arg0 * 6) = 1;
        }
      }
      else {
        *(char *)(&DAT_0203cfaa + arg0 * 6) = *(char *)(&DAT_0203cfaa + arg0 * 6) + -1;
      }
      break;
    case 4:
      sVar2 = *(short *)(&DAT_0203cfa6 + iVar4);
      *(short *)(&DAT_0203cfa6 + iVar4) = sVar2 + 2;
      if (0xc < (short)(sVar2 + 2)) {
        *(undefined1 *)(&DAT_0203cfa8 + arg0 * 6) = 0;
      }
    }
    arg0 = arg0 + 1 & 0xff;
  } while (arg0 < 0x18);
  return;
}


// sub_080E7A44 @ 0x080E7A44

void sub_080E7A44(int arg0)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  char cStack_2c;
  char cStack_2b;
  undefined1 auStack_28 [16];
  
  iVar3 = 0;
  memset(&cStack_2c,0,2);
  memset(auStack_28,0,0x10);
  sub_080E7968();
  iVar1 = sub_080ED954();
  if (iVar1 == 0) {
    cStack_2c = '\0';
    uVar2 = 0;
    do {
      if ((&DAT_0203d068)[uVar2 * 0xc] != '\0') {
        cStack_2c = cStack_2c + '\x01';
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 8);
    if (cStack_2c != '\0') {
      uVar2 = 0;
      do {
        iVar1 = uVar2 * 0xc;
        if (((&DAT_0203d068)[iVar1] != '\0') &&
           (((&DAT_0203d068)[iVar1] != '\x03' || ((&DAT_0203d06a)[iVar1] == '\0')))) {
          sub_080AA184(*(undefined4 *)(uVar2 * 4 + 0x86be718),1,
                       (int)(char)(&DAT_0203d063)[iVar1] & 0xffff,2);
        }
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 8);
      goto LAB_080e7c6a;
    }
LAB_080e7c64:
    iVar3 = 1;
  }
  else {
    cStack_2c = '\0';
    uVar2 = 0;
    do {
      if ((&DAT_0203d068)[uVar2 * 0xc] != '\0') {
        cStack_2c = cStack_2c + '\x01';
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 4);
    if (cStack_2c == '\0') {
      iVar3 = 2;
    }
    else {
      uVar2 = 0;
      do {
        iVar1 = uVar2 * 0xc;
        if (((&DAT_0203d068)[iVar1] != '\0') &&
           (((&DAT_0203d068)[iVar1] != '\x03' || ((&DAT_0203d06a)[iVar1] == '\0')))) {
          sub_080AA184(*(undefined4 *)(uVar2 * 4 + 0x86be718),1,
                       (int)(char)(&DAT_0203d063)[iVar1] & 0xffff,2);
        }
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 4);
    }
    cStack_2b = '\0';
    uVar2 = 4;
    do {
      if ((&DAT_0203d068)[uVar2 * 0xc] != '\0') {
        cStack_2b = cStack_2b + '\x01';
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 8);
    if (DAT_0203d39c != 0) {
      cStack_2b = '\0';
    }
    if (cStack_2b == '\0') {
      if (iVar3 == 2) goto LAB_080e7c64;
    }
    else {
      uVar2 = 4;
      do {
        iVar1 = uVar2 * 0xc;
        if (((&DAT_0203d068)[iVar1] != '\0') &&
           (((&DAT_0203d068)[iVar1] != '\x03' || ((&DAT_0203d06a)[iVar1] == '\0')))) {
          sub_080AA184(*(undefined4 *)(uVar2 * 4 + 0x86be718),1,
                       (int)(char)(&DAT_0203d063)[iVar1] & 0xffff,2);
        }
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 8);
    }
    iVar3 = 0;
  }
LAB_080e7c6a:
  if (DAT_0203d0c0 == '\x01') {
    sub_080E7C98();
    DAT_0203d0c0 = '\0';
  }
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (iVar3 == 1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080e7c94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E7C98 @ 0x080E7C98

void sub_080E7C98(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 local_18;
  
  local_18 = 0;
  CpuFastSet(&local_18,0x30010b4,0x1000100);
  uVar5 = 0;
  do {
    iVar2 = uVar5 * 0xc;
    if ((&DAT_0203d068)[iVar2] != '\0') {
      uVar3 = sub_080E7834(uVar5 + 0x10);
      (&DAT_0203d061)[iVar2] = (char)uVar3;
      bVar1 = (&DAT_0203d061)[iVar2];
      pbVar4 = (byte *)((uint)bVar1 * 4 + 0x86be6a4);
      CpuFastSet((uint)*pbVar4 * 0x80 + 0x81a81b8,uVar5 * 0x80 + 0x30010b4,0x20);
      (&DAT_0203d060)[iVar2] = (char)uVar5;
      (&DAT_0203d062)[iVar2] = *pbVar4;
      (&DAT_0203d063)[iVar2] = (&DAT_086be6a5)[(uint)bVar1 * 4];
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 8);
  DisplayList_Add(0x80e7365,1);
  DAT_0203d0c0 = 0;
  return;
}


// sub_080E7D30 @ 0x080E7D30

uint sub_080E7D30(uint arg0)

{
  ushort *puVar1;
  
  puVar1 = (ushort *)sub_080E444C(arg0 & 0xffff);
  return (uint)((*puVar1 & 0x80ff) == 0x8000);
}


// sub_080E7D58 @ 0x080E7D58

void sub_080E7D58(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080ED954();
  if (iVar2 == 0) {
    cVar1 = '\0';
    uVar5 = 0;
    do {
      uVar3 = sub_080C0830();
      uVar4 = uVar3 & 0xffff;
      if (((short)uVar3 == 1) && ((&DAT_0203d068)[uVar5 * 0xc] != '\0')) {
        uVar4 = 0;
      }
      if ((uVar4 == 0) && (iVar2 = sub_080C09B0(uVar5 + 0x10), iVar2 != 0)) {
        cVar1 = cVar1 + '\x01';
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 8);
    if ((cVar1 != '\0') && (uVar5 = sub_080E8738(0), (uVar5 & 0xff) != 0)) {
      sub_080E7D30((uint)(ushort)DAT_0203cb90);
      sub_080AA514(DAT_0203cfac,(uint)bRam0203cfb1,0xe,(uint)DAT_0203cfb0);
    }
  }
  else {
    cVar1 = '\0';
    uVar5 = 0;
    do {
      uVar3 = sub_080C0830();
      uVar4 = uVar3 & 0xffff;
      if (((short)uVar3 == 1) && ((&DAT_0203d068)[uVar5 * 0xc] != '\0')) {
        uVar4 = 0;
      }
      if ((uVar4 == 0) && (iVar2 = sub_080C09B0(uVar5 + 0x10), iVar2 != 0)) {
        cVar1 = cVar1 + '\x01';
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 4);
    if ((cVar1 != '\0') && (uVar5 = sub_080E8738(0), (uVar5 & 0xff) != 0)) {
      sub_080E7D30((uint)(ushort)DAT_0203cb90);
      sub_080AA514(DAT_0203cfac,(uint)bRam0203cfb1,0xe,(uint)DAT_0203cfb0);
    }
    uVar5 = 4;
    cVar1 = '\0';
    do {
      uVar3 = sub_080C0830();
      uVar4 = uVar3 & 0xffff;
      if (((short)uVar3 == 1) && ((&DAT_0203d068)[uVar5 * 0xc] != '\0')) {
        uVar4 = 0;
      }
      if ((uVar4 == 0) && (iVar2 = sub_080C09B0(uVar5 + 0x10), iVar2 != 0)) {
        cVar1 = cVar1 + '\x01';
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 8);
    if ((cVar1 != '\0') && (uVar5 = sub_080E8738(1), (uVar5 & 0xff) != 0)) {
      sub_080E7D30((uint)DAT_0203cb98);
      sub_080AA514(DAT_0203cfec,(uint)DAT_0203cff1,0xf,(uint)DAT_0203cff0);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080e8024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E8034 @ 0x080E8034

void sub_080E8034(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080ED954();
  if (iVar2 != 0) {
    cVar1 = '\0';
    uVar5 = 0;
    do {
      uVar3 = sub_080C0830();
      uVar4 = uVar3 & 0xffff;
      if (((short)uVar3 == 1) && ((&DAT_0203d068)[uVar5 * 0xc] != '\0')) {
        uVar4 = 0;
      }
      if ((uVar4 == 0) && (iVar2 = sub_080C09B0(uVar5 + 0x10), iVar2 != 0)) {
        cVar1 = cVar1 + '\x01';
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 4);
    if ((DAT_0203cb90 == 0x110) && (iVar2 = sub_080EDA24(0), iVar2 == 0)) {
      cVar1 = '\0';
    }
    if ((cVar1 != '\0') && (uVar5 = sub_080E8738(0), (uVar5 & 0xff) != 0)) {
      sub_080E7D30(DAT_0203cb90 & 0xffff);
      sub_080AA514(DAT_0203cfac,(uint)bRam0203cfb1,0xe,(uint)DAT_0203cfb0);
    }
    goto LAB_080e8318;
  }
  cVar1 = '\0';
  uVar5 = 0;
  do {
    uVar3 = sub_080C0830();
    uVar4 = uVar3 & 0xffff;
    if (((short)uVar3 == 1) && ((&DAT_0203d068)[uVar5 * 0xc] != '\0')) {
      uVar4 = 0;
    }
    if ((uVar4 == 0) && (iVar2 = sub_080C09B0(uVar5 + 0x10), iVar2 != 0)) {
      cVar1 = cVar1 + '\x01';
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 8);
  if (DAT_0203d16a == 0) {
LAB_080e80a8:
    if (cVar1 == '\0') goto LAB_080e8318;
  }
  else if (cVar1 == '\0') {
    cVar1 = '\x01';
    goto LAB_080e80a8;
  }
  uVar5 = sub_080E8738(0);
  if ((uVar5 & 0xff) != 0) {
    if (DAT_0203cb90 == 0x12e) {
      sub_080E7D30(0x12e);
      sub_080AA514(DAT_0203cfac,(uint)bRam0203cfb1,0xe,(uint)DAT_0203cfb0);
      if ((DAT_030031bc & 7) == 0) {
        if (DAT_0203d3a6 == 0) {
          DAT_0300003d = DAT_0300003d + 0x10;
          if (0x20 < DAT_0300003d) {
            DAT_0203d3a6 = 1;
          }
        }
        else {
          DAT_0300003d = DAT_0300003d - 0x10;
          if (DAT_0300003d == 0) {
            DAT_0203d3a6 = 0;
          }
        }
      }
    }
    else {
      sub_080E7D30(DAT_0203cb90 & 0xffff);
      sub_080AA514(DAT_0203cfac,(uint)bRam0203cfb1,0xe,(uint)DAT_0203cfb0);
    }
  }
LAB_080e8318:
                    /* WARNING: Could not recover jumptable at 0x080e8322. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E832C @ 0x080E832C

void sub_080E832C(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 4;
  cVar1 = '\0';
  do {
    uVar2 = sub_080C0830();
    uVar4 = uVar2 & 0xffff;
    if (((short)uVar2 == 1) && ((&DAT_0203d068)[uVar5 * 0xc] != '\0')) {
      uVar4 = 0;
    }
    if ((uVar4 == 0) && (iVar3 = sub_080C09B0(uVar5 + 0x10), iVar3 != 0)) {
      cVar1 = cVar1 + '\x01';
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 8);
  if ((DAT_0203cb94 == 0x10f) && (iVar3 = sub_080EDA24(1), iVar3 == 0)) {
    cVar1 = '\0';
  }
  if ((cVar1 != '\0') && (uVar5 = sub_080E8738(1), (uVar5 & 0xff) != 0)) {
    sub_080E7D30(DAT_0203cb94 & 0xffff);
    sub_080AA514(DAT_0203cfec,(uint)DAT_0203cff1,0xf,(uint)DAT_0203cff0);
  }
  return;
}


// sub_080E845C @ 0x080E845C

void sub_080E845C(uint arg0,undefined4 arg1,undefined4 arg2)

{
  int iVar1;
  
  iVar1 = (arg0 & 0xff) * 0x40;
  (&DAT_0203cfa6)[iVar1] = (undefined1)arg1;
  (&DAT_0203cfa7)[iVar1] = (undefined1)arg2;
  return;
}


// sub_080E847C @ 0x080E847C

void sub_080E847C(byte *arg0)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  short sVar9;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_080AB184();
  if (((uVar2 & 0xffff) != 1) || (iVar3 = sub_080B098C(), iVar3 == 1)) goto LAB_080e8580;
  if (arg0[5] == 1) {
    arg0[4] = arg0[4] + 1;
    if ((int)(char)arg0[4] == (uint)arg0[3]) {
LAB_080e84c4:
      arg0[5] = 1 - arg0[5];
    }
  }
  else {
    bVar1 = arg0[4];
    arg0[4] = bVar1 - 1;
    if ((byte)(bVar1 - 1) == 0) goto LAB_080e84c4;
  }
  uVar2 = 0;
  iVar3 = *(int *)(arg0 + 0x28);
  do {
    iVar7 = (int)(char)arg0[4];
    iVar6 = uVar2 * 2;
    uVar8 = (iVar7 * (uint)*arg0 + 0xc0 & 0xffff) * (*(ushort *)(arg0 + iVar6 + 8) & 0x1f) & 0xffff;
    if (0x1f00 < uVar8) {
      uVar8 = 0x1f00;
    }
    sVar5 = 0x3e0;
    uVar4 = (iVar7 * (uint)arg0[1] + 0xc0 & 0xffff) * ((*(ushort *)(arg0 + iVar6 + 8) & 0x3e0) >> 5)
    ;
    if ((uVar4 & 0xffff) < 0x1f01) {
      sVar5 = (short)((uVar4 & 0x1f00) >> 3);
    }
    sVar9 = 0x7c00;
    uVar4 = (iVar7 * (uint)arg0[2] + 0xc0 & 0xffff) *
            ((*(ushort *)(arg0 + iVar6 + 8) & 0x7c00) >> 10);
    if ((uVar4 & 0xffff) < 0x1f01) {
      sVar9 = (short)((uVar4 & 0x1f00) << 2);
    }
    *(short *)(iVar6 + iVar3) = sVar9 + (short)(uVar8 >> 8) + sVar5;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x10);
  sub_080AABB0();
LAB_080e8580:
                    /* WARNING: Could not recover jumptable at 0x080e858c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E8590 @ 0x080E8590

void sub_080E8590(byte *arg0,uint arg1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_080AB184();
  if (((uVar2 & 0xffff) != 1) || (iVar3 = sub_080B098C(), iVar3 == 1)) goto LAB_080e86a4;
  if (arg0[5] == 1) {
    arg0[4] = arg0[4] + 1;
    if ((int)(char)arg0[4] == (uint)arg0[3]) {
LAB_080e85e0:
      arg0[5] = 1 - arg0[5];
    }
  }
  else {
    bVar1 = arg0[4];
    arg0[4] = bVar1 - 1;
    if ((byte)(bVar1 - 1) == 0) goto LAB_080e85e0;
  }
  uVar2 = 0;
  do {
    if (((int)(arg1 & 0xffff) >> uVar2 & 1U) != 0) {
      iVar6 = (int)(char)arg0[4];
      iVar3 = uVar2 * 2;
      uVar7 = (iVar6 * (uint)*arg0 + 0xc0 & 0xffff) * (*(ushort *)(arg0 + iVar3 + 8) & 0x1f) &
              0xffff;
      if (0x1f00 < uVar7) {
        uVar7 = 0x1f00;
      }
      sVar5 = 0x3e0;
      uVar4 = (iVar6 * (uint)arg0[1] + 0xc0 & 0xffff) *
              ((*(ushort *)(arg0 + iVar3 + 8) & 0x3e0) >> 5);
      if ((uVar4 & 0xffff) < 0x1f01) {
        sVar5 = (short)((uVar4 & 0x1f00) >> 3);
      }
      sVar8 = 0x7c00;
      uVar4 = (iVar6 * (uint)arg0[2] + 0xc0 & 0xffff) *
              ((*(ushort *)(arg0 + iVar3 + 8) & 0x7c00) >> 10);
      if ((uVar4 & 0xffff) < 0x1f01) {
        sVar8 = (short)((uVar4 & 0x1f00) << 2);
      }
      *(short *)(*(int *)(arg0 + 0x28) + iVar3) = sVar8 + (short)(uVar7 >> 8) + sVar5;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x10);
  sub_080AABB0();
LAB_080e86a4:
                    /* WARNING: Could not recover jumptable at 0x080e86b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E86B4 @ 0x080E86B4

void sub_080E86B4(undefined4 arg0,undefined1 *arg1,uint arg2)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  dword arg1_00;
  
  iVar3 = sub_080E444C(arg2 & 0xffff);
  if ((*(byte *)(iVar3 + 1) & 0x80) != 0) {
    cVar2 = (*(byte *)(iVar3 + 1) & 0x3f) << 1;
    arg1[4] = cVar2;
    arg1[3] = cVar2;
    arg1[5] = 0;
    arg1[6] = 0xff;
    arg1[7] = 0x80;
    uVar4 = __divsi3(0x80,(uint)(byte)arg1[3]);
    uVar1 = (undefined1)uVar4;
    arg1[2] = uVar1;
    arg1[1] = uVar1;
    *arg1 = uVar1;
    *(undefined4 *)(arg1 + 0x28) = arg0;
    arg1_00 = *(dword *)(iVar3 + 4);
    if ((DAT_030020e4 == 0x80d977d) && (iVar3 = sub_080C2644(arg2 & 0xffff), iVar3 == 0)) {
      arg1_00 = 0x86be584;
    }
    sub_080ACFCC(3,arg1_00,arg1 + 8,0x20);
  }
  return;
}


// sub_080E8738 @ 0x080E8738

undefined4 sub_080E8738(uint arg0)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  dword dVar6;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined4 *puVar10;
  uint arg0_00;
  dword *pdVar11;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg0 & 0xff;
  iVar3 = arg0_00 * 0x40;
  bVar1 = (&DAT_0203cfa4)[iVar3];
  if (bVar1 == 2) {
LAB_080e876a:
    (&DAT_0203cfa4)[iVar3] = 1;
  }
  else if (((2 < bVar1) && (bVar1 == 3)) &&
          (iVar4 = sub_080E8B20(&DAT_0203cfa0 + iVar3), iVar4 != 0)) {
    sub_080E8B78(arg0_00,0);
    goto LAB_080e876a;
  }
  if ((&DAT_0203cfa4)[iVar3] == '\0') goto LAB_080e88b2;
  pcVar5 = (char *)sub_080E444C((uint)*(ushort *)(&DAT_0203cb90 + arg0_00));
  if (*pcVar5 != '\0') {
    if ((&DAT_0203cfa1)[iVar3] == '\0') {
      uVar7 = sub_080E8AC0((uint)*(ushort *)(&DAT_0203cb90 + arg0_00));
      if ((uVar7 & 0xffff) < 2) {
        (&DAT_0203cfb0)[iVar3] = 2;
        uVar2 = 1;
      }
      else {
        (&DAT_0203cfb0)[iVar3] = 3;
        uVar2 = 9;
      }
      *(undefined1 *)(iVar3 + 0x203cfb1) = uVar2;
      (&DAT_0203cfa2)[iVar3] = (&DAT_0203cfa2)[iVar3] + '\x01';
      puVar10 = (undefined4 *)
                (*(int *)(*(int *)(pcVar5 + 8) + 4) + (uint)(byte)(&DAT_0203cfa2)[iVar3] * 8);
      if (*(short *)(puVar10 + 1) == -1) {
        (&DAT_0203cfa2)[iVar3] = 0;
        puVar10 = *(undefined4 **)(*(int *)(pcVar5 + 8) + 4);
      }
      (&DAT_0203cfa1)[iVar3] = (char)*(undefined2 *)(puVar10 + 1) << 1;
      (&DAT_0203cfa3)[iVar3] = 0;
      (&DAT_0203cfac)[arg0_00 * 0x10] = *puVar10;
    }
    else {
      (&DAT_0203cfa1)[iVar3] = (&DAT_0203cfa1)[iVar3] + -1;
    }
    goto LAB_080e88b2;
  }
  if ((pcVar5[1] & 0x80U) == 0) {
    if ((&DAT_0203cfa1)[iVar3] == '\0') {
      (&DAT_0203cfa2)[iVar3] = (&DAT_0203cfa2)[iVar3] + '\x01';
      pcVar9 = (char *)((uint)(byte)pcVar5[1] * 5 + (byte)(&DAT_0203cfa2)[iVar3] + 0x86be75c);
      if (*pcVar9 == -1) {
        (&DAT_0203cfa2)[iVar3] = 0;
        pcVar9 = (char *)((uint)(byte)pcVar5[1] * 5 + 0x86be75c);
      }
      (&DAT_0203cfa1)[iVar3] = *pcVar9;
      (&DAT_0203cfa3)[iVar3] = 1;
    }
    else {
      (&DAT_0203cfa1)[iVar3] = (&DAT_0203cfa1)[iVar3] + -1;
    }
    dVar6 = 0x80f649c;
LAB_080e8846:
    (&DAT_0203cfac)[arg0_00 * 0x10] = dVar6;
  }
  else {
    pdVar11 = (dword *)(*(int *)(*(int *)(pcVar5 + 8) + 4) + (uint)(byte)(&DAT_0203cfa2)[iVar3] * 8)
    ;
    if ((&DAT_0203cfa1)[iVar3] == '\0') {
      (&DAT_0203cfa2)[iVar3] = (&DAT_0203cfa2)[iVar3] + 1;
      pdVar11 = (dword *)(*(int *)(*(int *)(pcVar5 + 8) + 4) +
                         (uint)(byte)(&DAT_0203cfa2)[iVar3] * 8);
      if ((short)pdVar11[1] == -1) {
        (&DAT_0203cfa2)[iVar3] = 0;
        pdVar11 = *(dword **)(*(int *)(pcVar5 + 8) + 4);
      }
      (&DAT_0203cfa1)[iVar3] = (char)(short)pdVar11[1] << 1;
      (&DAT_0203cfa3)[iVar3] = 0;
    }
    else {
      (&DAT_0203cfa1)[iVar3] = (&DAT_0203cfa1)[iVar3] + -1;
    }
    (&DAT_0203cfac)[arg0_00 * 0x10] = *pdVar11;
    if ((&DAT_0203cfa4)[iVar3] != '\x03') {
      if ((pcVar5[1] & 0xc0U) == 0xc0) {
        sub_080E8590(&DAT_0203cfb4 + iVar3,0);
        dVar6 = *pdVar11;
        goto LAB_080e8846;
      }
      sub_080E847C(&DAT_0203cfb4 + iVar3);
    }
  }
  (&DAT_0203cfb0)[iVar3] = 2;
  *(undefined1 *)(iVar3 + 0x203cfb1) = 1;
LAB_080e88b2:
                    /* WARNING: Could not recover jumptable at 0x080e88b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar8 = (*UNRECOVERED_JUMPTABLE)((&DAT_0203cfa4)[iVar3]);
  return uVar8;
}


// sub_080E88C0 @ 0x080E88C0

undefined4 sub_080E88C0(uint arg0)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  dword dVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 *puVar8;
  dword *pdVar9;
  undefined4 uVar10;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar10 = 0;
  uVar2 = arg0 & 0xff;
  if (uVar2 == 3) {
    uVar2 = 0;
  }
  iVar3 = uVar2 * 0x40;
  if ((&DAT_0203cfa4)[iVar3] == '\0') goto LAB_080e8a1c;
  pcVar4 = (char *)sub_080E444C((uint)(ushort)(&DAT_0203cfb2)[uVar2 * 0x20]);
  if (*pcVar4 != '\0') {
    if ((&DAT_0203cfa1)[iVar3] == '\0') {
      uVar6 = sub_080E8AC0((uint)(ushort)(&DAT_0203cfb2)[uVar2 * 0x20]);
      if ((uVar6 & 0xffff) < 2) {
        (&DAT_0203cfb0)[iVar3] = 2;
        uVar1 = 1;
      }
      else {
        (&DAT_0203cfb0)[iVar3] = 3;
        uVar1 = 9;
      }
      *(undefined1 *)(iVar3 + 0x203cfb1) = uVar1;
      (&DAT_0203cfa2)[iVar3] = (&DAT_0203cfa2)[iVar3] + '\x01';
      puVar8 = (undefined4 *)
               (*(int *)(*(int *)(pcVar4 + 8) + 4) + (uint)(byte)(&DAT_0203cfa2)[iVar3] * 8);
      if (*(short *)(puVar8 + 1) == -1) {
        (&DAT_0203cfa2)[iVar3] = 0;
        puVar8 = *(undefined4 **)(*(int *)(pcVar4 + 8) + 4);
      }
      (&DAT_0203cfa1)[iVar3] = (char)*(undefined2 *)(puVar8 + 1) << 1;
      (&DAT_0203cfa3)[iVar3] = 0;
      (&DAT_0203cfac)[uVar2 * 0x10] = *puVar8;
      uVar10 = 1;
    }
    else {
      (&DAT_0203cfa1)[iVar3] = (&DAT_0203cfa1)[iVar3] + -1;
    }
    goto LAB_080e8a1c;
  }
  if ((pcVar4[1] & 0x80U) == 0) {
    if ((&DAT_0203cfa1)[iVar3] == '\0') {
      (&DAT_0203cfa2)[iVar3] = (&DAT_0203cfa2)[iVar3] + '\x01';
      pcVar7 = (char *)((uint)(byte)pcVar4[1] * 5 + (byte)(&DAT_0203cfa2)[iVar3] + 0x86be75c);
      if (*pcVar7 == -1) {
        (&DAT_0203cfa2)[iVar3] = 0;
        pcVar7 = (char *)((uint)(byte)pcVar4[1] * 5 + 0x86be75c);
      }
      (&DAT_0203cfa1)[iVar3] = *pcVar7;
      (&DAT_0203cfa3)[iVar3] = 1;
      uVar10 = 1;
    }
    else {
      (&DAT_0203cfa1)[iVar3] = (&DAT_0203cfa1)[iVar3] + -1;
    }
    dVar5 = 0x80f649c;
LAB_080e89ae:
    (&DAT_0203cfac)[uVar2 * 0x10] = dVar5;
  }
  else {
    pdVar9 = (dword *)(*(int *)(*(int *)(pcVar4 + 8) + 4) + (uint)(byte)(&DAT_0203cfa2)[iVar3] * 8);
    (&DAT_0203cfac)[uVar2 * 0x10] = *pdVar9;
    if ((&DAT_0203cfa1)[iVar3] == '\0') {
      (&DAT_0203cfa2)[iVar3] = (&DAT_0203cfa2)[iVar3] + '\x01';
      pdVar9 = (dword *)(*(int *)(*(int *)(pcVar4 + 8) + 4) + (uint)(byte)(&DAT_0203cfa2)[iVar3] * 8
                        );
      if ((short)pdVar9[1] == -1) {
        (&DAT_0203cfa2)[iVar3] = 0;
        pdVar9 = *(dword **)(*(int *)(pcVar4 + 8) + 4);
      }
      (&DAT_0203cfa1)[iVar3] = (char)(short)pdVar9[1] << 1;
      (&DAT_0203cfa3)[iVar3] = 0;
      uVar10 = 1;
      (&DAT_0203cfac)[uVar2 * 0x10] = *pdVar9;
    }
    else {
      (&DAT_0203cfa1)[iVar3] = (&DAT_0203cfa1)[iVar3] + -1;
    }
    if ((&DAT_0203cfa4)[iVar3] != '\x03') {
      if ((pcVar4[1] & 0xc0U) == 0xc0) {
        sub_080E8590(&DAT_0203cfb4 + iVar3,0);
        dVar5 = *pdVar9;
        goto LAB_080e89ae;
      }
      sub_080E847C(&DAT_0203cfb4 + iVar3);
    }
  }
  (&DAT_0203cfb0)[iVar3] = 2;
  *(undefined1 *)(iVar3 + 0x203cfb1) = 1;
LAB_080e8a1c:
                    /* WARNING: Could not recover jumptable at 0x080e8a22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar10 = (*UNRECOVERED_JUMPTABLE)(uVar10);
  return uVar10;
}


// sub_080E8A28 @ 0x080E8A28

void sub_080E8A28(uint arg0,undefined4 arg1)

{
  int iVar1;
  uint uVar2;
  dword unaff_r6;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = arg0 & 0xff;
  if (uVar2 == 3) {
    uVar2 = 0;
  }
  iVar1 = uVar2 * 0x40;
  (&DAT_0203cfa2)[iVar1] = 0;
  (&DAT_0203cfa1)[iVar1] = 0;
  (&DAT_0203cfa4)[iVar1] = 1;
  (&DAT_0203cfa7)[iVar1] = 0;
  (&DAT_0203cfa6)[iVar1] = 0;
  (&DAT_0203cfa5)[iVar1] = 0;
  (&DAT_0203cfb2)[uVar2 * 0x20] = (undefined2)arg1;
  (&DAT_0203cfac)[uVar2 * 0x10] = 0;
  sub_080E444C((uint)(ushort)(&DAT_0203cfb2)[uVar2 * 0x20]);
  if (uVar2 == 1) {
    unaff_r6 = 0x3003190;
  }
  else if (uVar2 < 2) {
    if (uVar2 == 0) {
      unaff_r6 = 0x3003170;
    }
  }
  else if (uVar2 == 2) {
    unaff_r6 = 0x3003150;
  }
  sub_080E86B4(unaff_r6,&DAT_0203cfb4 + iVar1,(uint)(ushort)(&DAT_0203cfb2)[uVar2 * 0x20]);
                    /* WARNING: Could not recover jumptable at 0x080e8a9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080E8AA0 @ 0x080E8AA0

undefined1 * sub_080E8AA0(uint arg0)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xff;
  if (uVar1 == 3) {
    uVar1 = 0;
  }
  return &DAT_0203cfa0 + uVar1 * 0x40;
}


// sub_080E8AC0 @ 0x080E8AC0

undefined4 sub_080E8AC0(undefined4 arg0)

{
  undefined4 uVar1;
  
  if ((DAT_030020e4 == 0x80d977d) || (((DAT_0200ab04 & 0x8000) != 0 && (0xff < (ushort)arg0)))) {
    uVar1 = 3;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080E8AFC @ 0x080E8AFC

void sub_080E8AFC(uint arg0)

{
  (&DAT_0203cfa4)[(arg0 & 0xff) * 0x40] = 3;
  sub_080E8B78(arg0 & 0xff,1);
  return;
}


// sub_080E8B20 @ 0x080E8B20

uint sub_080E8B20(int arg0)

{
  int iVar1;
  undefined2 auStack_234 [256];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_34 = 0xffff0007;
  uStack_30 = 0x2fff7;
  uStack_2c = 0xffff0006;
  uStack_28 = 0xfffffffb;
  uStack_24 = 0x10003;
  uStack_20 = 0x1fffc;
  uStack_1c = 0xffff0002;
  uStack_18 = 0xfffffffe;
  uStack_14 = 0x10001;
  uStack_10 = 0x1ffff;
  iVar1 = (int)*(char *)(arg0 + 5);
  if (9 < iVar1) {
    *(undefined1 *)(arg0 + 6) = 0;
    *(undefined1 *)(arg0 + 7) = 0;
    *(undefined1 *)(arg0 + 5) = 0;
  }
  else {
    *(char *)(arg0 + 6) = (char)*(undefined2 *)(&uStack_34 + iVar1);
    *(char *)(arg0 + 7) = (char)*(undefined2 *)((int)&uStack_34 + *(char *)(arg0 + 5) * 4 + 2);
    *(char *)(arg0 + 5) = *(char *)(arg0 + 5) + '\x01';
  }
  return (uint)(9 < iVar1);
}


// sub_080E8B78 @ 0x080E8B78

void sub_080E8B78(uint arg0,uint arg1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  dword unaff_r5;
  
  uVar3 = arg0 & 0xff;
  uVar2 = arg1 & 0xff;
  if (uVar2 == 0) {
    iVar1 = sub_080E444C((uint)*(ushort *)(&DAT_0203cb90 + uVar3));
    unaff_r5 = *(dword *)(iVar1 + 4);
  }
  else if (uVar2 < 6) {
    unaff_r5 = *(dword *)(uVar2 * 4 + 0x86be884);
  }
  if ((DAT_030020e4 == 0x80d977d) && (iVar1 = sub_080C2644((&DAT_0203cb90)[uVar3]), iVar1 == 0)) {
    unaff_r5 = 0x86be584;
  }
  sub_080ACFCC(3,unaff_r5,(uVar3 + 0xe) * 0x20 + 0x3002fb0,0x20);
  sub_080AABB0();
  return;
}


// sub_080E8C10 @ 0x080E8C10

void sub_080E8C10(int arg0)

{
  ushort uVar1;
  
  uVar1 = (ushort)*(byte *)(arg0 + 6);
  if (*(byte *)(arg0 + 6) != 0) {
    uVar1 = 1;
  }
  *(ushort *)(arg0 + 0x1c) = uVar1;
  return;
}


// sub_080E8C24 @ 0x080E8C24

void sub_080E8C24(int arg0)

{
  if (*(char *)(arg0 + 6) != '\0') {
    sub_080E8DB4(0);
  }
  return;
}


// sub_080E8C38 @ 0x080E8C38

void sub_080E8C38(void)

{
  DAT_0203c204 = sub_080AD0FC(0x86be89c,0xffff);
  return;
}


// sub_080E8C58 @ 0x080E8C58

void sub_080E8C58(uint arg0,uint arg1,undefined4 arg2)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = arg1 & 0xffff;
  DAT_03006434 = &DAT_0203d16c;
  if (DAT_0203d16a == 0) {
    cVar2 = (arg0 & 0xffff) == 0xffff;
    if (!(bool)cVar2) {
      DAT_0203cfa8 = 0x7fff;
      DAT_0203cfaa = 0x7fff;
      DAT_0203cb90 = arg0 & 0xffff;
    }
    DAT_0203cfa0 = !(bool)cVar2;
    if (uVar1 == 0xffff) {
      cVar2 = cVar2 + '\x01';
    }
    else {
      DAT_0203cfe8 = 0x7fff;
      DAT_0203cfea = 0x7fff;
      DAT_0203cb94 = uVar1;
    }
    DAT_0203cfe0 = uVar1 != 0xffff;
    if (cVar2 != '\x02') {
      DAT_0203d314 = sub_080A9C0C(0x80e5529);
      DAT_0203cfa3 = 0;
      DAT_0203cfe3 = 0;
      sub_080E5668();
      DAT_0203c204 = sub_080AD0FC(0x86be89c,0xffff);
      *(undefined1 *)(DAT_0203c204 + 6) = (undefined1)arg2;
    }
  }
  return;
}


// sub_080E8D64 @ 0x080E8D64

uint sub_080E8D64(void)

{
  return (uint)(DAT_0203d0c3 == '\0');
}


