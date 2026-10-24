/* Ghidra decompilation of asm/code_080CD3E8.s (reference only; not compiled). */

// sub_080CD3E8 @ 0x080CD3E8

void sub_080CD3E8(uint arg0,uint arg1,uint arg2,uint arg3)

{
  int iVar1;
  uint uVar2;
  dword arg0_00;
  uint arg1_00;
  
  arg1_00 = arg1 & 0xffff;
  iVar1 = sub_080BF32C(arg0 & 0xffff);
  uVar2 = (uint)*(byte *)(iVar1 + 3);
  if (uVar2 == 0xf) {
    arg0_00 = 0x84f0320;
  }
  else {
    if (1 < uVar2) {
      sub_080CCEC8(uVar2 * 4 + 0x84f02de,arg1_00,arg2 & 0xffff,arg3 & 0xffff);
      return;
    }
    arg0_00 = uVar2 * 4 + 0x84f02de;
    arg1_00 = arg1_00 + 0x10 & 0xffff;
  }
  sub_080CCEC8(arg0_00,arg1_00,arg2 & 0xffff,arg3 & 0xffff);
  return;
}


// sub_080CD45C @ 0x080CD45C

void sub_080CD45C(uint arg0,uint arg1,uint arg2)

{
  dword arg0_00;
  int iVar1;
  uint uVar2;
  uint local_1c;
  
  uVar2 = arg1 & 0xffff;
  iVar1 = uVar2 + 0x10;
  sub_080BF468(arg0 & 0xffff,1,&local_1c);
  local_1c = local_1c & 7;
  if (local_1c == 1) {
    arg0_00 = 0x84f02c0;
    uVar2 = iVar1 * 0x10000;
  }
  else if (local_1c == 2) {
    arg0_00 = 0x84f02c4;
    uVar2 = iVar1 * 0x10000;
  }
  else if (local_1c == 4) {
    arg0_00 = 0x84f02c8;
    uVar2 = iVar1 * 0x10000;
  }
  else {
    if (local_1c == 7) {
      arg0_00 = 0x84f0320;
      goto LAB_080cd4d6;
    }
    if (local_1c != 3) {
      if (local_1c != 6) {
        return;
      }
      sub_080CCEC8(0x84f0328,uVar2 + 8 & 0xffff,arg2 & 0xffff,4);
      return;
    }
    arg0_00 = 0x84f0324;
    uVar2 = (uVar2 + 8) * 0x10000;
  }
  uVar2 = uVar2 >> 0x10;
LAB_080cd4d6:
  sub_080CCEC8(arg0_00,uVar2,arg2 & 0xffff,4);
  return;
}


// sub_080CD50C @ 0x080CD50C

void sub_080CD50C(uint arg0,uint arg1,uint arg2)

{
  ushort uVar1;
  int iVar2;
  dword arg0_00;
  uint uVar3;
  
  uVar3 = arg1 & 0xffff;
  iVar2 = sub_080BF32C(arg0 & 0xffff);
  uVar1 = *(ushort *)(iVar2 + 8);
  if ((uVar1 & 0x8000) == 0) {
    if ((uVar1 & 0x2000) != 0) {
      arg0_00 = 0x84f00f0;
      goto LAB_080cd63a;
    }
    if ((uVar1 & 0x1000) != 0) {
      arg0_00 = 0x84f00f8;
      goto LAB_080cd63e;
    }
    if ((uVar1 & 4) != 0) {
      arg0_00 = 0x84f0100;
      goto LAB_080cd63e;
    }
    if ((uVar1 & 0x800) == 0) {
      if ((uVar1 & 0x4000) != 0) {
        arg0_00 = 0x84f010c;
        goto LAB_080cd63e;
      }
      if ((uVar1 & 0x200) == 0) {
        if ((uVar1 & 0x40) == 0) {
          if ((uVar1 & 0x20) != 0) {
            arg0_00 = 0x84f012c;
            uVar3 = (uVar3 + 0x10) * 0x10000;
            goto LAB_080cd63c;
          }
          if ((uVar1 & 0x100) != 0) {
            arg0_00 = 0x84f0134;
            goto LAB_080cd63e;
          }
          uVar1 = *(ushort *)(iVar2 + 8);
          if ((uVar1 & 0x80) == 0) {
            if ((uVar1 & 2) == 0) {
              if ((uVar1 & 0x10) == 0) {
                if ((uVar1 & 8) == 0) {
                  sub_080CCEC8(0x84f01ec,uVar3,arg2 & 0xffff,4);
                  return;
                }
                arg0_00 = 0x84f0154;
              }
              else {
                arg0_00 = 0x84f014c;
              }
            }
            else {
              arg0_00 = 0x84f0144;
            }
          }
          else {
            arg0_00 = 0x84f013c;
          }
        }
        else {
          arg0_00 = 0x84f0124;
        }
      }
      else {
        arg0_00 = 0x84f011c;
      }
LAB_080cd63a:
      uVar3 = (uVar3 + 8) * 0x10000;
    }
    else {
      arg0_00 = 0x84f0108;
      uVar3 = (uVar3 + 0x18) * 0x10000;
    }
  }
  else {
    arg0_00 = 0x84f0194;
    uVar3 = (uVar3 + 0x10) * 0x10000;
  }
LAB_080cd63c:
  uVar3 = uVar3 >> 0x10;
LAB_080cd63e:
  sub_080CCEC8(arg0_00,uVar3,arg2 & 0xffff,4);
  return;
}


// sub_080CD668 @ 0x080CD668

void sub_080CD668(uint arg0,uint arg1,uint arg2,uint arg3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = Equipment_GetRecord36_MidRange(arg0 & 0xffff);
  bVar1 = *(byte *)(iVar2 + 1);
  sub_080CCEC8(0x84f02dc,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  sub_080CCFC4((uint)bVar1,(arg1 & 0xffff) + 0x18 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  return;
}


// sub_080CD6C4 @ 0x080CD6C4

void sub_080CD6C4(uint arg0,uint arg1,uint arg2,uint arg3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = Equipment_GetRecord36_MidRange(arg0 & 0xffff);
  bVar1 = *(byte *)(iVar2 + 2);
  sub_080CCEC8(0x84f02dc,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  sub_080CCFC4((uint)bVar1,(arg1 & 0xffff) + 0x18 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  return;
}


// sub_080CD720 @ 0x080CD720

void sub_080CD720(uint arg0,uint arg1,uint arg2)

{
  ushort uVar1;
  int iVar2;
  dword arg0_00;
  uint uVar3;
  
  uVar3 = arg1 & 0xffff;
  iVar2 = Equipment_GetRecord36_MidRange(arg0 & 0xffff);
  uVar1 = *(ushort *)(iVar2 + 8);
  if ((uVar1 & 0x8000) == 0) {
    if ((uVar1 & 0x2000) != 0) {
      arg0_00 = 0x84f00f0;
      goto LAB_080cd84e;
    }
    if ((uVar1 & 0x1000) != 0) {
      arg0_00 = 0x84f00f8;
      goto LAB_080cd852;
    }
    if ((uVar1 & 4) != 0) {
      arg0_00 = 0x84f0100;
      goto LAB_080cd852;
    }
    if ((uVar1 & 0x800) == 0) {
      if ((uVar1 & 0x4000) != 0) {
        arg0_00 = 0x84f010c;
        goto LAB_080cd852;
      }
      if ((uVar1 & 0x200) == 0) {
        if ((uVar1 & 0x40) == 0) {
          if ((uVar1 & 0x20) != 0) {
            arg0_00 = 0x84f012c;
            uVar3 = (uVar3 + 0x10) * 0x10000;
            goto LAB_080cd850;
          }
          if ((uVar1 & 0x100) != 0) {
            arg0_00 = 0x84f0134;
            goto LAB_080cd852;
          }
          uVar1 = *(ushort *)(iVar2 + 8);
          if ((uVar1 & 0x80) == 0) {
            if ((uVar1 & 2) == 0) {
              if ((uVar1 & 0x10) == 0) {
                if ((uVar1 & 8) == 0) {
                  sub_080CCEC8(0x84f01ec,uVar3,arg2 & 0xffff,4);
                  return;
                }
                arg0_00 = 0x84f0154;
              }
              else {
                arg0_00 = 0x84f014c;
              }
            }
            else {
              arg0_00 = 0x84f0144;
            }
          }
          else {
            arg0_00 = 0x84f013c;
          }
        }
        else {
          arg0_00 = 0x84f0124;
        }
      }
      else {
        arg0_00 = 0x84f011c;
      }
LAB_080cd84e:
      uVar3 = (uVar3 + 8) * 0x10000;
    }
    else {
      arg0_00 = 0x84f0108;
      uVar3 = (uVar3 + 0x18) * 0x10000;
    }
  }
  else {
    arg0_00 = 0x84f0194;
    uVar3 = (uVar3 + 0x10) * 0x10000;
  }
LAB_080cd850:
  uVar3 = uVar3 >> 0x10;
LAB_080cd852:
  sub_080CCEC8(arg0_00,uVar3,arg2 & 0xffff,4);
  return;
}


// sub_080CD87C @ 0x080CD87C

void sub_080CD87C(uint arg0,uint arg1,uint arg2)

{
  int iVar1;
  
  iVar1 = Equipment_GetRecord36_MidRange(arg0 & 0xffff);
  Text_DrawStringTinted
            ((uint)*(byte *)(iVar1 + 3) * 0xe + 0x84f032c,0x200f874,arg1 & 0xffff,arg2 & 0xffff);
  return;
}


// sub_080CD8C4 @ 0x080CD8C4

void sub_080CD8C4(uint arg0,uint arg1,uint arg2)

{
  int iVar1;
  
  iVar1 = Equipment_GetRecord36_MidRange(arg0 & 0xffff);
  Text_DrawStringTinted
            ((uint)*(byte *)(iVar1 + 3) * 10 + 0x84f06d6,0x200f874,arg1 & 0xffff,arg2 & 0xffff);
  return;
}


// sub_080CD90C @ 0x080CD90C

void sub_080CD90C(uint arg0,undefined4 arg1,uint arg2,undefined4 arg3)

{
  uint uVar1;
  uint uVar2;
  
  if ((arg0 & 0xffff) != 0) {
    uVar2 = (arg0 & 0xffff) >> 3;
    if ((uVar2 != 0) && (uVar1 = 0, uVar2 != 0)) {
      do {
        sub_080AA184(&DAT_08001558,1,arg2 & 0xffff,1);
        uVar1 = uVar1 + 1 & 0xffff;
      } while (uVar1 < uVar2);
    }
    if ((arg0 & 7) != 0) {
      sub_080AA184(*(undefined4 *)(((arg0 & 7) - 1) * 4 + 0x84f0974),1,arg2 & 0xffff,1);
    }
  }
  return;
}


// sub_080CD9C8 @ 0x080CD9C8

void sub_080CD9C8(uint arg0,uint arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  uint uVar2;
  uint arg0_00;
  uint uVar3;
  uint arg0_01;
  uint arg0_02;
  uint uVar4;
  uint in_stack_00000000;
  
  uVar2 = arg0 & 0xff;
  arg0_01 = arg1 & 0xff;
  arg0_02 = arg2 & 0xff;
  arg0_00 = arg3 & 0xff;
  uVar1 = DAT_0203a46e;
  if (DAT_0203a46e == 0) {
    uVar1 = DAT_03000004;
  }
  uVar4 = (uint)uVar1;
  sub_080CD90C(uVar2,0,0,(in_stack_00000000 & 0xffff) - uVar4 & 0xffff);
  uVar3 = (in_stack_00000000 & 0xffff) + uVar2 & 0xffff;
  if (0x28 < uVar2 + arg0_01) {
    arg0_01 = 0x28 - uVar2 & 0xffff;
  }
  sub_080CD90C(arg0_01,0,0xfff9,uVar3 - uVar4 & 0xffff);
  uVar3 = uVar3 + arg0_01 & 0xffff;
  uVar2 = uVar2 + arg0_01 & 0xffff;
  if (0x28 < uVar2 + arg0_02) {
    arg0_02 = 0x28 - uVar2 & 0xffff;
  }
  sub_080CD90C(arg0_02,0,0xfff8,uVar3 - uVar4 & 0xffff);
  uVar2 = uVar2 + arg0_02 & 0xffff;
  if (0x28 < uVar2 + arg0_00) {
    arg0_00 = 0x28 - uVar2 & 0xffff;
  }
  sub_080CD90C(arg0_00,0x20,0xfff9,(uVar3 + arg0_02 & 0xffff) - uVar4 & 0xffff);
  return;
}


// sub_080CDAE4 @ 0x080CDAE4

undefined4 sub_080CDAE4(undefined4 arg0,int arg1)

{
  if (arg1 == 0x80) {
    if ((short)arg0 == 0) {
      return 1;
    }
  }
  else if (arg1 < 0x81) {
    if ((arg1 == 0x40) && ((short)arg0 == 1)) {
      return 1;
    }
  }
  else if (arg1 == 0xc0) {
    return 1;
  }
  return 0;
}


// sub_080CDB18 @ 0x080CDB18

undefined4 sub_080CDB18(uint arg0,undefined4 arg1)

{
  switch(arg1) {
  case 1:
    if (arg0 != 0) {
      return 0;
    }
    break;
  case 2:
    if (arg0 != 1) {
      return 0;
    }
    break;
  case 3:
    goto joined_r0x080cdb6a;
  case 4:
    if (arg0 != 2) {
      return 0;
    }
    break;
  default:
    goto LAB_080cdb6e;
  case 6:
    arg0 = arg0 - 1;
joined_r0x080cdb6a:
    if (1 < arg0) {
LAB_080cdb6e:
      return 0;
    }
    break;
  case 7:
    break;
  }
  return 1;
}


// sub_080CDB74 @ 0x080CDB74

undefined4 sub_080CDB74(undefined4 arg0,uint arg1)

{
  undefined4 uVar1;
  undefined4 arg0_00;
  int iVar2;
  undefined4 local_14;
  uint local_10;
  
  sub_080BF468(arg1 & 0xff,0,&local_14);
  sub_080BF468(arg1 & 0xff,1,&local_10);
  uVar1 = sub_080C07FC(arg0);
  arg0_00 = sub_080C06BC(arg0);
  iVar2 = sub_080CDAE4((int)(short)uVar1,local_14);
  if ((iVar2 == 1) && (iVar2 = sub_080CDB18(arg0_00,local_10 & 7), iVar2 == 1)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_080CDBD4 @ 0x080CDBD4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CDBD4(void)

{
  DAT_0203a458 = 1;
  DAT_0203a45a = 0;
  _DAT_0203a45c = 0;
  _DAT_0203a484 = 0;
  return;
}


// sub_080CDBE8 @ 0x080CDBE8

void sub_080CDBE8(uint arg0,uint arg1)

{
  undefined4 uVar1;
  undefined2 local_14 [2];
  
  sub_080C92C8((uint)DAT_0203a456);
  local_14[0] = 0xffff;
  CpuSet(local_14,0x203b454,0x1000080);
  uVar1 = sub_080CA84C(arg0 & 0xffff,arg1 & 0xffff);
  DAT_0203a47c._0_2_ = (short)uVar1;
  return;
}


// sub_080CDC34 @ 0x080CDC34

void sub_080CDC34(void)

{
  undefined2 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = (undefined2 *)0x200f7d8;
  do {
    *puVar1 = 0x5000;
    puVar1[1] = 0x5000;
    puVar1 = puVar1 + 2;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 6);
  return;
}


// sub_080CDC54 @ 0x080CDC54

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CDC54(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint arg0_00;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  uint local_24;
  
  iVar3 = sub_080C92C8((uint)DAT_0203a456);
  iVar4 = sub_080C964C(0);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((((DAT_030031b8 & 0x200) == 0) || (DAT_0203a476 != 0)) ||
         (iVar3 = sub_080C964C(0), iVar3 == 1)) {
        uVar1 = DAT_0203a476;
        if ((((DAT_030031b8 & 0x100) == 0) || (DAT_0203a476 != 0)) ||
           (iVar3 = sub_080C964C(0), iVar3 == 1)) {
          uVar1 = DAT_03003964 & 0x40;
          if ((DAT_03003964 & 0x40) == 0) {
            uVar2 = _DAT_0203a484;
            if (((DAT_03003964 & 0x80) != 0) &&
               (sub_080C51D4(100), uVar2 = uVar1, _DAT_0203a484 != 6)) {
              uVar2 = _DAT_0203a484 + 1;
            }
          }
          else {
            sub_080C51D4(100);
            if (_DAT_0203a484 == 0) {
              _DAT_0203a484 = 6;
              uVar2 = _DAT_0203a484;
            }
            else {
              uVar2 = _DAT_0203a484 - 1;
            }
          }
          goto LAB_080cde5a;
        }
        sub_080C51D4(100);
        if ((uint)DAT_0203a456 == iVar4 - 1U) {
          DAT_0203a456 = uVar1;
        }
        else {
          DAT_0203a456 = DAT_0203a456 + 1;
        }
        DAT_0203a45e = 0x10;
      }
      else {
        sub_080C51D4(100);
        if (DAT_0203a456 == 0) {
          DAT_0203a456 = (ushort)iVar4;
        }
        DAT_0203a456 = DAT_0203a456 - 1;
        DAT_0203a45e = 0xfff0;
      }
      *(undefined2 *)(arg0 + 0x1e) = 2;
      sub_080CDBD4();
      uVar2 = _DAT_0203a484;
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1e) = 3;
      uVar2 = _DAT_0203a484;
    }
  }
  else {
    uVar5 = sub_080C343C(iVar3,(uint)_DAT_0203a484);
    arg0_00 = uVar5 & 0xffff;
    sub_080C51D4(0x65);
    _DAT_0203a480 = 0;
    DAT_0203a482 = 0;
    sub_080CDBE8((uint)*(ushort *)((uint)_DAT_0203a484 * 4 + 0x84f0994),
                 (uint)*(ushort *)(&DAT_084f0996 + (uint)_DAT_0203a484 * 4));
    if (arg0_00 != 0xff) {
      uVar6 = sub_080D2268(arg0_00);
      sub_080BF468(arg0_00,6,&local_24);
      if (((local_24 & 1) != 0) && ((uVar6 & 0xffff) != 6)) {
        *(undefined2 *)(arg0 + 0x1e) = 4;
        DAT_0203a4a4 = sub_080AB860(2,0xb,0x1a,7);
        Font_ResetGlyphSpriteCache(0x180);
        goto LAB_080cde74;
      }
    }
    if ((short)DAT_0203a47c != 0) {
      *(undefined2 *)(arg0 + 0x1e) = 0x8001;
      goto LAB_080cde74;
    }
    sub_080CDFD0((uint)*(byte *)(iVar3 + 0xc),(uint)_DAT_0203a484);
    sub_080CDC34();
    sub_080BF938((uint)*(byte *)(iVar3 + 0xc));
    if (*(short *)(iVar3 + 0x1a) < *(short *)(iVar3 + 0x18)) {
      *(undefined2 *)(iVar3 + 0x18) = *(undefined2 *)(iVar3 + 0x1a);
    }
    if ((uVar5 & 0xff) != 0xff) {
      sub_080C3328(arg0_00);
    }
    sub_080C9CD8();
    sub_080C9BCC(arg0);
    sub_080C9D5C();
    sub_080C9D00(arg0);
    sub_080C9E08();
    sub_080C9D84(arg0);
    uVar2 = _DAT_0203a484;
  }
LAB_080cde5a:
  _DAT_0203a484 = uVar2;
  sub_080C49EC(0xf,3,2,10);
LAB_080cde74:
                    /* WARNING: Could not recover jumptable at 0x080cde82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CDE84 @ 0x080CDE84

void sub_080CDE84(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) != 0) {
    sub_080AB91C(DAT_0203a4a4,1);
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  Text_DrawSpriteString(0x84f09b0,0,0,0x12);
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_080C4AB0(0,0,0xd5,0x85);
  }
  return;
}


// sub_080CDEEC @ 0x080CDEEC

void sub_080CDEEC(uint arg0,uint arg1,undefined4 arg2)

{
  int arg0_00;
  uint uVar1;
  uint uVar2;
  uint arg0_01;
  uint arg0_02;
  code *UNRECOVERED_JUMPTABLE;
  uint local_1c;
  
  arg0_01 = arg1 & 0xffff;
  arg0_00 = sub_080C0148((arg0 & 0xffff) + 0x8000 & 0xffff);
  if ((arg1 & 0x8000) != 0) {
    arg0_01 = arg1 & 0xff;
  }
  uVar1 = sub_080D2268(arg0_01);
  uVar1 = uVar1 & 0xffff;
  uVar2 = sub_080C343C(arg0_00,uVar1);
  arg0_02 = uVar2 & 0xffff;
  sub_080BF468(arg0_01,6,&local_1c);
  if (((local_1c & 1) != 0) && (uVar1 != 6)) {
    sub_080C08E8((uint)*(byte *)(arg0_00 + 0xc),1);
    sub_080C84A0();
  }
  if ((arg0_01 == arg0_02) && ((short)arg2 == 0)) {
    sub_080CDFD0((uint)*(byte *)(arg0_00 + 0xc),uVar1);
    if ((uVar2 & 0xff) != 0xff) {
      sub_080C3328(arg0_02);
    }
  }
  else {
    sub_080C34B0(arg0_00,uVar1,arg0_01);
    sub_080C33AC(arg0_01);
    if ((uVar2 & 0xff) != 0xff) {
      sub_080C3328(arg0_02);
    }
  }
  sub_080BF938((uint)*(byte *)(arg0_00 + 0xc));
  if (*(short *)(arg0_00 + 0x1a) < *(short *)(arg0_00 + 0x18)) {
    *(undefined2 *)(arg0_00 + 0x18) = *(undefined2 *)(arg0_00 + 0x1a);
  }
                    /* WARNING: Could not recover jumptable at 0x080cdfb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CDFBC @ 0x080CDFBC

void sub_080CDFBC(uint arg0,uint arg1)

{
  sub_080CDEEC(arg0 & 0xffff,arg1 & 0xffff,1);
  return;
}


// sub_080CDFD0 @ 0x080CDFD0

void sub_080CDFD0(int arg0,uint arg1)

{
  undefined4 arg0_00;
  
  arg0_00 = sub_080C0148(arg0 * 0x10000 + 0x80000000U >> 0x10);
  sub_080C34B0(arg0_00,arg1 & 0xffff,0xffff);
  return;
}


// sub_080CDFF8 @ 0x080CDFF8

void sub_080CDFF8(int arg0,uint arg1)

{
  int iVar1;
  
  iVar1 = sub_080C0148(arg0 * 0x10000 + 0x80000000U >> 0x10);
  sub_080CDFD0((uint)*(byte *)(iVar1 + 0xc),arg1 & 0xffff);
  sub_080BF938((uint)*(byte *)(iVar1 + 0xc));
  if (*(short *)(iVar1 + 0x1a) < *(short *)(iVar1 + 0x18)) {
    *(undefined2 *)(iVar1 + 0x18) = *(undefined2 *)(iVar1 + 0x1a);
  }
  sub_080CDC34();
  return;
}


// sub_080CE038 @ 0x080CE038

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CE038(int arg0)

{
  ushort uVar1;
  bool bVar2;
  ushort uVar3;
  int arg0_00;
  int iVar4;
  uint uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = sub_080C92C8((uint)DAT_0203a456);
  uVar3 = (ushort)DAT_0203a47c;
  uVar5 = (uint)(ushort)DAT_0203a47c;
  bVar2 = false;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  uVar6 = uVar5;
  if (6 < uVar5) {
    uVar6 = 7;
  }
  if ((DAT_030031b8 & 1) != 0) {
    sub_080C343C(arg0_00,(uint)_DAT_0203a484);
    uVar5 = (uint)*(ushort *)(((uint)_DAT_0203a480 + (uint)DAT_0203a482) * 2 + 0x203b454);
    uVar6 = sub_080C343C(arg0_00,(uint)_DAT_0203a484);
    if ((uVar5 == (uVar6 & 0xffff)) ||
       (iVar4 = sub_080CDB74((uint)*(byte *)(arg0_00 + 0xc),uVar5 & 0xff), iVar4 == 1)) {
      sub_080C51D4(0x65);
      sub_080CDEEC((uint)*(byte *)(arg0_00 + 0xc),uVar5,0);
      sub_080CDC34();
      *(undefined2 *)(arg0 + 0x1e) = 2;
    }
    else {
      sub_080C51D4(0x66);
    }
    goto LAB_080ce246;
  }
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_03003964 & 0x40) == 0) {
      uVar1 = DAT_03003964 & 0x80;
      if ((DAT_03003964 & 0x80) == 0) {
        if (((DAT_03003964 & 0x200) == 0) || (uVar5 < 8)) {
          uVar1 = _DAT_0203a480;
          if (((DAT_03003964 & 0x100) != 0) && (7 < uVar5)) {
            sub_080C51D4(100);
            bVar2 = true;
            if (_DAT_0203a480 == 6) {
              uVar1 = _DAT_0203a480;
              if ((int)(DAT_0203a482 + 0xd) < (int)(uVar5 - 1)) {
                DAT_0203a482 = DAT_0203a482 + 7;
              }
              else {
                DAT_0203a482 = uVar3 - 7;
              }
            }
            else {
              _DAT_0203a480 = 6;
              uVar1 = _DAT_0203a480;
            }
          }
        }
        else {
          sub_080C51D4(100);
          bVar2 = true;
          if (_DAT_0203a480 == 0) {
            uVar1 = _DAT_0203a480;
            if (DAT_0203a482 < 6) {
              DAT_0203a482 = _DAT_0203a480;
            }
            else {
              DAT_0203a482 = DAT_0203a482 - 6;
            }
          }
        }
      }
      else {
        sub_080C51D4(100);
        if ((uint)_DAT_0203a480 != uVar6 - 1) {
          _DAT_0203a480 = _DAT_0203a480 + 1;
          goto LAB_080ce140;
        }
        uVar1 = _DAT_0203a480;
        if ((_DAT_0203a480 == 6) && ((int)(DAT_0203a482 + 7) <= (int)(uVar5 - 1))) {
          DAT_0203a482 = DAT_0203a482 + 1;
          bVar2 = true;
        }
      }
    }
    else {
      sub_080C51D4(100);
      if (_DAT_0203a480 == 0) {
        uVar1 = _DAT_0203a480;
        if (DAT_0203a482 != 0) {
          DAT_0203a482 = DAT_0203a482 - 1;
          bVar2 = true;
        }
      }
      else {
        _DAT_0203a480 = _DAT_0203a480 - 1;
LAB_080ce140:
        sub_080C9D5C();
        sub_080C9D00(arg0);
        sub_080C9E08();
        sub_080C9D84(arg0);
        uVar1 = _DAT_0203a480;
      }
    }
  }
  else {
    sub_080C51D4(0x66);
    *(undefined2 *)(arg0 + 0x1e) = 2;
    uVar1 = _DAT_0203a480;
  }
  _DAT_0203a480 = uVar1;
  if (bVar2) {
    sub_080C9CD8();
    sub_080C9BCC(arg0);
    sub_080C9D5C();
    sub_080C9D00(arg0);
    sub_080C9E08();
    sub_080C9D84(arg0);
  }
  sub_080C49EC(0xf,0,2,10);
  if (DAT_0203a482 != 0) {
    _DAT_0203a470 = 1;
  }
  if ((int)(DAT_0203a482 + 7) <= (int)(uVar5 - 1)) {
    DAT_0203a472 = 1;
  }
LAB_080ce246:
                    /* WARNING: Could not recover jumptable at 0x080ce254. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CE258 @ 0x080CE258

void sub_080CE258(undefined4 arg0,undefined4 arg1)

{
  undefined4 local_18;
  
  sub_080AD0FC(0x84f09c8,0xffff);
  local_18 = 0;
  CpuSet(&local_18,0x203a454,0x5000200);
  DAT_0203a456 = (undefined2)arg1;
  DAT_0203a458 = 1;
  DAT_0203a454 = 3;
  DAT_0203a476 = 0;
  return;
}


// sub_080CE2A8 @ 0x080CE2A8

undefined4 sub_080CE2A8(undefined4 arg0)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C0F64();
  if ((((iVar1 == 0x28) && (iVar1 = sub_080C0F64(), iVar1 == 0x28)) &&
      (iVar1 = sub_080C0F64(), iVar1 == 0x28)) &&
     (((iVar1 = sub_080C0F64(), iVar1 == 0x28 && (iVar1 = sub_080C0F64(), iVar1 == 0x28)) &&
      (iVar1 = sub_080C0F64(), iVar1 == 0x28)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080ce2fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080CE300 @ 0x080CE300

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CE300(int arg0)

{
  bool bVar1;
  int arg0_00;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  dword dVar5;
  uint unaff_r5;
  
  arg0_00 = sub_080C92C8((uint)DAT_0203a456);
  bVar1 = false;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_03003964 & 1) != 0) {
    uVar2 = sub_080C0F64();
    iVar3 = sub_080CE2A8(arg0_00);
    if (iVar3 == 0) {
      *(undefined2 *)(arg0 + 0x1e) = 1;
      DAT_0203a4a0 = sub_080ABEB4(0);
LAB_080ce38e:
      DAT_0203a4a4 = sub_080AB860(1,0xc,0x12,4);
    }
    else if ((uVar2 & 0xff) != 0x28) {
      sub_080C0EC0((uint)*(byte *)(arg0_00 + 0xc),(uint)_DAT_0203a480,1);
      DAT_0203a48a = DAT_0203a48a + -1;
      bVar1 = true;
      if (DAT_0203a48a == 0) {
        *(undefined2 *)(arg0 + 0x1e) = 1;
        DAT_0203a4a0 = sub_080ABEB4(0);
        goto LAB_080ce38e;
      }
    }
    sub_080C51D4(0x65);
    goto LAB_080ce4a0;
  }
  if ((DAT_03003964 & 2) == 0) {
    if ((DAT_03003964 & 0x40) == 0) {
      if ((DAT_03003964 & 0x80) == 0) {
        if ((DAT_03003964 & 0x20) == 0) {
          if ((DAT_03003964 & 0x10) != 0) {
            if (_DAT_0203a480 == 5) {
              _DAT_0203a480 = 0;
            }
            else {
              _DAT_0203a480 = _DAT_0203a480 + 1;
            }
            sub_080C51D4(100);
          }
          goto LAB_080ce4a0;
        }
        if (_DAT_0203a480 == 0) {
          _DAT_0203a480 = 5;
        }
        else {
          _DAT_0203a480 = _DAT_0203a480 - 1;
        }
      }
      else if (_DAT_0203a480 < 3) {
        _DAT_0203a480 = _DAT_0203a480 + 3;
      }
      else {
        _DAT_0203a480 = _DAT_0203a480 - 3;
      }
    }
    else if (_DAT_0203a480 < 3) {
      _DAT_0203a480 = _DAT_0203a480 + 3;
    }
    else {
      _DAT_0203a480 = _DAT_0203a480 - 3;
    }
    sub_080C51D4(100);
    goto LAB_080ce4a0;
  }
  uVar2 = sub_080C0F64();
  switch(_DAT_0203a480) {
  case 0:
    pcVar4 = &DAT_0203a550;
    break;
  case 1:
    pcVar4 = &DAT_0203a551;
    break;
  case 2:
    pcVar4 = &DAT_0203a552;
    break;
  case 3:
    pcVar4 = &DAT_0203a553;
    break;
  case 4:
    dVar5 = 0x100;
    goto LAB_080ce404;
  case 5:
    dVar5 = 0x101;
LAB_080ce404:
    pcVar4 = (char *)(dVar5 + 0x203a454);
    break;
  default:
    goto switchD_080ce3c4_default;
  }
  unaff_r5 = (uint)*pcVar4;
switchD_080ce3c4_default:
  if ((unaff_r5 & 0xff) != (uVar2 & 0xff)) {
    sub_080C0EC0((uint)*(byte *)(arg0_00 + 0xc),(uint)_DAT_0203a480,0xffffffff);
    DAT_0203a48a = DAT_0203a48a + 1;
    bVar1 = true;
    sub_080C51D4(0x66);
  }
LAB_080ce4a0:
  if (bVar1) {
    sub_080CB068();
    sub_080C9D5C();
    sub_080C9D00(arg0);
    sub_080C9E08();
    sub_080C9D84(arg0);
  }
  return;
}


// sub_080CE4D0 @ 0x080CE4D0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CE4D0(int arg0)

{
  undefined4 arg1;
  int iVar1;
  
  arg1 = sub_080C92C8((uint)DAT_0203a456);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  iVar1 = sub_080ABF04(DAT_0203a4a0);
  if (iVar1 == 1) {
    if (DAT_030031cc == 0) {
      *(undefined2 *)(arg0 + 0x1e) = 1;
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 2;
      DAT_0203a48a = _DAT_0203a488;
      CpuSet(&DAT_0203a528,arg1,0x4000020);
      sub_080C9414();
      sub_080CB068();
      sub_080C9D5C();
      sub_080C9D00(arg0);
      sub_080C9E08();
      sub_080C9D84(arg0);
    }
    sub_080AB91C(DAT_0203a4a4,1);
  }
  Text_DrawSpriteString(0x84f0ca0,0,0,10);
  return;
}


// sub_080CE564 @ 0x080CE564

void sub_080CE564(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_0203a454 == 4);
  return;
}


// sub_080CE580 @ 0x080CE580

void sub_080CE580(undefined4 arg0,int arg1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = 0;
  puVar2 = (undefined4 *)0x20360b4;
  piVar3 = (int *)0x2036094;
  do {
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      if (arg1 == 0) {
        *puVar2 = *(undefined4 *)(iVar1 + 0x20);
        *(undefined4 *)(iVar1 + 0x20) = 0;
      }
      else {
        *(undefined4 *)(iVar1 + 0x20) = *puVar2;
        *puVar2 = 0;
      }
    }
    puVar2 = puVar2 + 1;
    piVar3 = piVar3 + 1;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 8);
  return;
}


// sub_080CE5BC @ 0x080CE5BC

void sub_080CE5BC(void)

{
  int iVar1;
  
  iVar1 = sub_080C92C8((uint)DAT_0203a456);
  if (DAT_0203a454 == 5) {
    sub_080BF8D8((uint)*(byte *)(iVar1 + 0xc));
  }
  return;
}


// sub_080CE5E0 @ 0x080CE5E0

void sub_080CE5E0(void)

{
  if ((DAT_03005180 == 0) && ((DAT_0200ab04 & 0x8000) != 0)) {
    DAT_03003bb4 = 0;
  }
  return;
}


// sub_080CE614 @ 0x080CE614

void sub_080CE614(void)

{
  DAT_0300000e = 0;
  return;
}


// sub_080CE620 @ 0x080CE620

void sub_080CE620(void)

{
  DAT_03004608 = 1;
  return;
}


// sub_080CE62C @ 0x080CE62C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CE62C(undefined4 arg0,undefined4 arg1)

{
  undefined4 local_20;
  
  sub_080AD0FC(0x84f0cbc,0xffff);
  local_20 = 0;
  CpuSet(&local_20,0x203a454,0x5000200);
  DAT_0203a454 = 4;
  DAT_0203a476 = 0;
  DAT_0203a45a = 2;
  _DAT_0203a45c = 3;
  DAT_03004600 = DAT_0300000e;
  DAT_0203a456 = (ushort)arg0;
  _DAT_0203a488 = (undefined2)arg1;
  DAT_0203a48a = (undefined2)arg1;
  sub_080F4260((uint)(byte)(&DAT_030046cc)[(uint)(ushort)arg0 * 0x80]);
  return;
}


// sub_080CE6C4 @ 0x080CE6C4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CE6C4(undefined4 arg0,undefined4 arg1)

{
  undefined4 local_20;
  
  sub_080AD0FC(0x84f0cbc,0xffff);
  local_20 = 0;
  CpuSet(&local_20,0x203a454,0x5000200);
  DAT_0203a48a = (undefined2)arg1;
  _DAT_0203a488 = (undefined2)arg1;
  DAT_0203a456 = (undefined2)arg0;
  DAT_0203a454 = 5;
  DAT_0203a476 = 0;
  DAT_0203a45a = 2;
  _DAT_0203a45c = 3;
  DAT_03004600 = DAT_0300000e;
  return;
}


// sub_080CE74C @ 0x080CE74C

uint sub_080CE74C(short *arg0)

{
  return (uint)(*arg0 == 0);
}


// sub_080CE760 @ 0x080CE760

void sub_080CE760(int arg0,int arg1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  dword dVar5;
  int iVar6;
  undefined4 arg0_00;
  uint uVar7;
  uint uVar8;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar3 = sub_080C0148(0x8000);
  sVar2 = DAT_0203b85c;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (arg1 == 0) {
    uVar8 = (uint)DAT_0203b85a;
    if (((sVar2 == 1) || (sVar2 == 4)) || (sVar2 == 5)) {
      uVar8 = sub_08154968((uint)DAT_0203b85a);
      uVar4 = sub_080C32D4(uVar8 & 0xffff);
      uVar8 = sub_08131AB0(0xff,uVar8 & 0xffff);
      if (0x62 < (uVar4 & 0xff) + (uVar8 & 0xffff)) {
        *(undefined2 *)(arg0 + 0x1c) = 1;
        *(undefined2 *)(arg0 + 0x1e) = 3;
      }
      goto LAB_080ceab4;
    }
    if (sVar2 == 6) {
      iVar6 = sub_080C3560(uVar8);
      if (iVar6 != 0) {
LAB_080ce832:
        *(undefined2 *)(arg0 + 0x1c) = 1;
        *(undefined2 *)(arg0 + 0x1e) = 1;
        goto LAB_080ceab4;
      }
      uVar7 = 0;
      uVar4 = 0;
      do {
        iVar6 = sub_080C09B0(uVar4 + 4);
        if (iVar6 != 0) {
          uVar7 = uVar7 + 1 & 0xffff;
        }
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 < 0xc);
      iVar6 = sub_080C104C();
      if (iVar6 <= (int)uVar7) {
        *(undefined2 *)(arg0 + 0x1c) = 1;
        *(undefined2 *)(arg0 + 0x1e) = 4;
        goto LAB_080ceab4;
      }
    }
    else {
      iVar6 = sub_080C3560(uVar8);
      if (((iVar6 != 0) && (DAT_0203b854 != uVar8)) &&
         ((DAT_0203b856 != uVar8 && (DAT_0203b858 != uVar8)))) goto LAB_080ce832;
    }
    if ((DAT_0203b85c == 3) &&
       (iVar6 = sub_081546E8((uint)DAT_0203b854,(uint)DAT_0203b856,(uint)DAT_0203b858), iVar6 == 1))
    {
      bVar1 = *(byte *)(iVar3 + 0xd);
      iVar3 = sub_080BF648(uVar8);
      if ((uint)*(byte *)(iVar3 + 1) <= bVar1 + 9) goto LAB_080ceab4;
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    else {
      iVar6 = sub_080BF648(uVar8);
      if (*(byte *)(iVar6 + 1) <= *(byte *)(iVar3 + 0xd)) goto LAB_080ceab4;
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    *(undefined2 *)(arg0 + 0x1e) = 2;
    goto LAB_080ceab4;
  }
  if (arg1 == 1) {
LAB_080ce9cc:
    DAT_0203a4a4 = sub_080AB860(2,0xb,0x1a,7);
  }
  else {
    if (arg1 == 2) {
      if ((DAT_030031b8 & 1) != 0) {
        *(undefined2 *)(arg0 + 0x1c) = 1;
        DAT_030031cc = 1;
        sub_080AB91C(DAT_0203a4a4,1);
        sub_080C51D4(0x65);
        goto LAB_080ceab4;
      }
      sVar2 = *(short *)(arg0 + 0x1e);
      if (sVar2 == 1) {
        dVar5 = 0x815bf4a;
LAB_080ce8e6:
        Text_DrawSpriteString(dVar5,0,0,0x12);
      }
      else {
        if (sVar2 == 2) {
          dVar5 = 0x815bf0e;
          goto LAB_080ce8e6;
        }
        if (sVar2 == 3) {
          dVar5 = 0x815bf62;
          goto LAB_080ce8e6;
        }
        Text_DrawSpriteString(0x815bf7c,0,0,0x12);
      }
LAB_080cea1c:
      if ((DAT_030031bc >> 4 & 1) == 0) {
        sub_080C4AB0(0,0,0xd5,0x85);
      }
      goto LAB_080ceab4;
    }
    if (arg1 != 3) {
      if (arg1 == 4) {
        iVar3 = sub_080ABF04(DAT_0203a4a0);
        if (iVar3 != 1) {
          dVar5 = 0x815bed4;
LAB_080ce9ae:
          Text_DrawSpriteString(dVar5,0,0,0x12);
          goto LAB_080ceab4;
        }
LAB_080cea56:
        *(undefined2 *)(arg0 + 0x1c) = 1;
      }
      else {
        if (arg1 == 5) {
          iVar3 = sub_080C06BC((uint)*(byte *)(iVar3 + 0xc));
          iVar6 = sub_0815B864();
          if ((((DAT_0203b85c == 1) || (DAT_0203b85c == 4)) || (DAT_0203b85c == 5)) ||
             (((iVar3 != 0 || (iVar6 != 2)) && ((iVar3 != 2 || (iVar6 != 0)))))) goto LAB_080ceab4;
LAB_080cea42:
          *(undefined2 *)(arg0 + 0x1c) = 1;
          goto LAB_080ceab4;
        }
        if (arg1 == 6) {
          iVar3 = sub_080ABF04(DAT_0203a4a0);
          if (iVar3 != 1) {
            dVar5 = 0x815bf36;
            goto LAB_080ce9ae;
          }
          goto LAB_080cea56;
        }
        if (arg1 == 7) goto LAB_080ce9cc;
        if (arg1 != 8) {
          if (arg1 == 9) {
            if (DAT_0203b85c != 6) goto LAB_080ceab4;
            goto LAB_080cea42;
          }
          if (arg1 != 10) goto LAB_080ceab4;
          iVar3 = sub_080ABF04(DAT_0203a4a0);
          if (iVar3 != 1) {
            Text_DrawSpriteString(0x815bfbe,0,0,0x12);
            arg0_00 = sub_081571DC((uint)DAT_0203b85a);
            iVar3 = Comp_DrawSummonCost(arg0_00,0x12,0x67);
            Text_DrawSpriteString(0x815bfcc,0,0,iVar3 * 0x10000 + 0xc0000U >> 0x10);
            Text_DrawSpriteString(0x815bfd6,0,0,0x12);
            goto LAB_080ceab4;
          }
          goto LAB_080cea56;
        }
        if ((DAT_030031b8 & 1) == 0) {
          Text_DrawSpriteString(0x815befa,0,0,0x12);
          goto LAB_080cea1c;
        }
        *(undefined2 *)(arg0 + 0x1c) = 1;
      }
      sub_080AB91C(DAT_0203a4a4,1);
      goto LAB_080ceab4;
    }
    DAT_0203a4a4 = sub_080AB860(2,0xb,0x1a,7);
    DAT_0203a4a0 = sub_080ABEB4(0);
  }
  Font_ResetGlyphSpriteCache(0x180);
LAB_080ceab4:
                    /* WARNING: Could not recover jumptable at 0x080ceabe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// Comp_DrawSummonCost @ 0x080CEAD0

uint Comp_DrawSummonCost(undefined4 arg0,uint arg1,undefined4 arg2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint arg3;
  
  iVar2 = sub_080A9CC0(arg0);
  bVar1 = false;
  FontSprite_DrawGlyph(0x52,0,0,arg1 & 0xffff);
  arg3 = (arg1 & 0xffff) + 0xc & 0xffff;
  uVar5 = 0;
  do {
    iVar3 = (int)(uVar5 * 0x1000000) >> 0x18;
    if ((bVar1) || (*(char *)((iVar2 + 7) - iVar3) != '\0')) {
      FontSprite_DrawGlyph
                ((uint)*(ushort *)((uint)*(byte *)((iVar2 + 7) - iVar3) * 2 + 0x84f0eac),0,0,arg3);
      bVar1 = true;
      arg3 = arg3 + 0xc & 0xffff;
    }
    uVar4 = uVar5 * 0x1000000 + 0x1000000;
    uVar5 = uVar4 >> 0x18;
  } while ((int)uVar4 >> 0x18 < 8);
  return arg3;
}


// sub_080CEB60 @ 0x080CEB60

void sub_080CEB60(int arg0)

{
  int iVar1;
  
  sub_080C92C8((uint)DAT_0203a456);
  sub_080C964C(0);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (((((DAT_030031b8 & 0x80) == 0) || (DAT_0203b85c == 1)) || (DAT_0203b85c == 4)) ||
     (DAT_0203b85c == 5)) {
    if ((DAT_030031b8 & 1) == 0) {
      if ((DAT_030031b8 & 2) != 0) {
        sub_080C51D4(0x66);
        *(undefined2 *)(arg0 + 0x1e) = 3;
        DAT_030031cc = 1;
      }
    }
    else {
      sub_080C51D4(0x65);
      *(undefined2 *)(arg0 + 0x1e) = 2;
    }
  }
  else {
    iVar1 = sub_080C93B4((uint)DAT_0203a456);
    if (iVar1 == 1) {
      sub_080C51D4(100);
      *(undefined2 *)(arg0 + 0x1e) = 0x8001;
    }
    else {
      iVar1 = sub_080C9388((uint)DAT_0203a456);
      if (iVar1 == 1) {
        sub_080C51D4(100);
        *(undefined2 *)(arg0 + 0x1e) = 0x8002;
      }
      else {
        sub_080C51D4(100);
        *(undefined2 *)(arg0 + 0x1e) = 0x8003;
      }
    }
  }
  if (((DAT_0203b85c != 1) && (DAT_0203b85c != 4)) && (DAT_0203b85c != 5)) {
    sub_080C4AB0(0,0,0x92,0x76);
  }
  return;
}


// sub_080CEC4C @ 0x080CEC4C

void sub_080CEC4C(undefined4 arg0)

{
  if (DAT_0203a490 != 0) {
    sub_080C3E80(DAT_0203a490);
    DAT_0203a490 = 0;
  }
  sub_080ABD30(DAT_0203a494,1);
  sub_080ABD30(DAT_0203a498,1);
  sub_080ABD30(DAT_0203a49c,1);
  if (DAT_0203b85c == 6) {
    sub_08157EB0(3,arg0,DAT_0203a48c);
  }
  else {
    sub_08157EB0(0,arg0,DAT_0203a48c);
  }
  return;
}


// sub_080CECA8 @ 0x080CECA8

void sub_080CECA8(void)

{
  if (DAT_0203a490 != 0) {
    sub_080C3E80(DAT_0203a490);
    DAT_0203a490 = 0;
  }
  sub_080ABD30(DAT_0203a494,1);
  sub_080ABD30(DAT_0203a498,1);
  sub_080ABD30(DAT_0203a49c,1);
  Font_ResetGlyphSpriteCache(0x180);
  DAT_030068e0 = sub_08156000();
  return;
}


// sub_080CECF4 @ 0x080CECF4

void sub_080CECF4(void)

{
  sub_080C1384();
  return;
}


// sub_080CED00 @ 0x080CED00

undefined4 sub_080CED00(void)

{
  undefined4 uVar1;
  undefined4 local_14;
  
  uVar1 = sub_080AD0FC(0x84f0ec0,0xffff);
  local_14 = 0;
  CpuSet(&local_14,0x203a454,0x5000200);
  DAT_0203a456 = 0;
  DAT_0203a454 = 6;
  DAT_0203a476 = 0;
  return uVar1;
}


// sub_080CED40 @ 0x080CED40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CED40(void)

{
  int iVar1;
  undefined4 in_r2;
  
  LZ77UnCompWram(0x81b5870,0x200f874,in_r2);
  DisplayList_Add(0x80c93e1,1);
  DAT_0203b554 = DAT_0203a456 + -0x8000;
  DAT_0203a478._0_2_ = 1;
  DAT_0203a456 = 0;
  _DAT_0203a464 = 0;
  iVar1 = sub_080C9388(0);
  DAT_0203a46a = (ushort)(iVar1 == 1);
  _DAT_0203a46c = 1;
  _DAT_0203a470 = 0;
  DAT_0203a472 = 0;
  return;
}


// sub_080CEDA4 @ 0x080CEDA4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CEDA4(int arg0)

{
  int iVar1;
  int iVar2;
  uint arg0_00;
  
  iVar1 = sub_080C92C8((uint)DAT_0203a456);
  sub_080C964C(0);
  iVar2 = sub_080C92AC((uint)*(ushort *)(iVar1 + 0x12));
  *(undefined2 *)(arg0 + 0x1e) = 0;
  iVar1 = sub_080C99B8(iVar1);
  if (iVar1 == 1) {
    iVar2 = 1;
  }
  if (((DAT_030031b8 & 0x80) == 0) || (iVar2 != 0)) {
    if (((DAT_030031b8 & 0x100) != 0) || ((DAT_030031b8 & 2) != 0)) {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1e) = 3;
      DAT_030031cc = 1;
    }
  }
  else {
    sub_080C51D4(100);
    *(undefined2 *)(arg0 + 0x1e) = 0x8003;
  }
  arg0_00 = 0;
  if (DAT_0203a458 == 0) {
    arg0_00 = (uint)_DAT_0203a474;
  }
  sub_080C981C(arg0_00);
  sub_080C9994();
  if (iVar2 == 0) {
    sub_080C4AB0(0,0,0x92,0x76);
  }
  return;
}


// sub_080CEE4C @ 0x080CEE4C

void sub_080CEE4C(void)

{
  ushort uVar1;
  
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 | 0x400;
  return;
}


// sub_080CEE60 @ 0x080CEE60

void sub_080CEE60(void)

{
  undefined4 in_r0;
  
  sub_080C9E30(in_r0);
  DisplayList_Add(0x80cee4d,1);
  return;
}


// sub_080CEE78 @ 0x080CEE78

void sub_080CEE78(void)

{
  undefined4 uVar1;
  undefined1 local_8 [8];
  
  sub_08154EC0();
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080CEEC8 @ 0x080CEEC8

void sub_080CEEC8(void)

{
  if (DAT_0203a490 != 0) {
    sub_080C3E80(DAT_0203a490);
    DAT_0203a490 = 0;
  }
  return;
}


// sub_080CEEE8 @ 0x080CEEE8

void sub_080CEEE8(void)

{
  if (DAT_0203a490 != 0) {
    sub_080C3E80(DAT_0203a490);
    DAT_0203a490 = 0;
  }
  sub_080ABD30(DAT_0203a494,1);
  sub_080ABD30(DAT_0203a498,1);
  sub_080ABD30(DAT_0203a49c,1);
  CpuSet(0x203ac54,0x203a454,0x4000200);
  DisplayList_Add(0x80cee79,1);
  return;
}


// sub_080CEF3C @ 0x080CEF3C

void sub_080CEF3C(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x81b5870,0x200f874,in_r2);
  DisplayList_Add(0x80c93e1,1);
  return;
}


// sub_080CEF60 @ 0x080CEF60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CEF60(void)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 in_r1;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a454 == 0xb) {
    in_r1 = 0;
  }
  else if (DAT_0203a454 == 0xc) {
    in_r1 = 1;
  }
  uVar1 = sub_080D45F0(0x203b554,in_r1);
  uVar4 = 0;
  if ((uVar1 & 0xffff) != 0) {
    do {
      puVar2 = (ushort *)(uVar4 * 2 + 0x203b554);
      *puVar2 = *puVar2 | 0x8000;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < (uVar1 & 0xffff));
  }
  DAT_0203a478._0_2_ = (undefined2)uVar1;
  _DAT_0203a464 = 0;
  iVar3 = sub_080C9388((uint)DAT_0203a456);
  DAT_0203a46a = (ushort)(iVar3 == 1);
  _DAT_0203a46c = 1;
  _DAT_0203a470 = 0;
  DAT_0203a472 = 0;
                    /* WARNING: Could not recover jumptable at 0x080cefd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CEFD4 @ 0x080CEFD4

void sub_080CEFD4(short *arg0)

{
  short *arg0_00;
  uint uVar1;
  
  uVar1 = 0;
  do {
    arg0_00 = (short *)(uVar1 * 100 + 0x2009004);
    if (((DAT_0203a48c != arg0_00) && (arg0 != arg0_00)) && (*arg0_00 == 1)) {
      sub_080AD150(arg0_00);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x40);
  return;
}


// sub_080CF010 @ 0x080CF010

void sub_080CF010(short *arg0)

{
  bool bVar1;
  int iVar2;
  short *arg0_00;
  uint uVar3;
  
  iVar2 = sub_080C92C8((uint)DAT_0203a456);
  bVar1 = false;
  uVar3 = 0;
  do {
    arg0_00 = (short *)(uVar3 * 100 + 0x2009004);
    if (((DAT_0203a48c != arg0_00) && (arg0 != arg0_00)) && (*arg0_00 == -1)) {
      sub_080AD174(arg0_00);
      bVar1 = true;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x40);
  if (bVar1) {
    sub_080D3F04(arg0,(int)*(short *)(iVar2 + 0x12),1);
  }
  return;
}


// sub_080CF078 @ 0x080CF078

void sub_080CF078(int arg0)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  undefined4 arg0_00;
  
  sub_080C92C8((uint)DAT_0203a456);
  uVar1 = sub_080C964C(0);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  iVar2 = sub_080C9388((uint)DAT_0203a456);
  if (iVar2 == 1) {
    uVar4 = 1;
    arg0_00 = 0x65;
  }
  else {
    uVar4 = 0x80;
    arg0_00 = 100;
    sub_080C4AB0(0,0,0x92,0x76);
  }
  if ((DAT_030031b8 & 1) == 0) {
    if ((uVar4 & DAT_030031b8) == 0) {
      if ((DAT_030031b8 & 2) == 0) {
        if ((((DAT_030031b8 & 0x200) == 0) || (DAT_0203a476 != 0)) ||
           (iVar2 = sub_080C964C(0), iVar2 == 1)) {
          uVar4 = DAT_0203a476;
          if ((((DAT_030031b8 & 0x100) != 0) && (DAT_0203a476 == 0)) &&
             (iVar2 = sub_080C964C(0), iVar2 != 1)) {
            sub_080C51D4(100);
            if ((uint)DAT_0203a456 == uVar1 - 1) {
              DAT_0203a456 = uVar4;
            }
            else {
              DAT_0203a456 = DAT_0203a456 + 1;
            }
            DAT_0203a45e = 0x10;
            *(undefined2 *)(arg0 + 0x1e) = 2;
            sub_080CA684();
          }
        }
        else {
          sub_080C51D4(100);
          uVar3 = (uint)DAT_0203a456;
          if (DAT_0203a456 == 0) {
            uVar3 = uVar1;
          }
          DAT_0203a456 = (short)uVar3 - 1;
          DAT_0203a45e = 0xfff0;
          *(undefined2 *)(arg0 + 0x1e) = 2;
          sub_080CA684();
        }
      }
      else {
        sub_080C51D4(0x66);
        *(undefined2 *)(arg0 + 0x1e) = 3;
        DAT_030031cc = 1;
      }
    }
    else {
      sub_080C51D4(arg0_00);
      *(undefined2 *)(arg0 + 0x1e) = 0x8003;
    }
  }
  else {
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  return;
}


// sub_080CF1A8 @ 0x080CF1A8

void sub_080CF1A8(void)

{
  DAT_0203a4a4 = sub_080AB860(2,0xb,0x1a,8);
  DAT_0203a4a0 = sub_080ABEB4(0);
  Font_ResetGlyphSpriteCache(0x180);
  return;
}


// sub_080CF1DC @ 0x080CF1DC

void sub_080CF1DC(undefined4 arg0,uint arg1,undefined4 arg2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint arg3;
  
  arg3 = arg1 & 0xffff;
  iVar2 = sub_080A9CC0(arg0);
  bVar1 = false;
  uVar5 = 0;
  do {
    iVar3 = (int)(uVar5 * 0x1000000) >> 0x18;
    if ((bVar1) || (*(char *)((iVar2 + 7) - iVar3) != '\0')) {
      FontSprite_DrawGlyph
                ((uint)*(ushort *)((uint)*(byte *)((iVar2 + 7) - iVar3) * 2 + 0x84f0eac),0,0,arg3);
      bVar1 = true;
      arg3 = arg3 + 0xc & 0xffff;
    }
    uVar4 = uVar5 * 0x1000000 + 0x1000000;
    uVar5 = uVar4 >> 0x18;
  } while ((int)uVar4 >> 0x18 < 8);
  return;
}


// sub_080CF250 @ 0x080CF250

void sub_080CF250(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint arg0_00;
  uint arg3;
  uint arg2;
  ushort *puVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar3 = sub_080C92C8((uint)DAT_0203a456);
  uVar1 = *(ushort *)(iVar3 + 0x12);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  iVar3 = sub_080ABF04(DAT_0203a4a0);
  if ((iVar3 == 1) && (*(undefined2 *)(arg0 + 0x1c) = 1, DAT_030031cc == 1)) {
    sub_080AB91C(DAT_0203a4a4,1);
  }
  puVar4 = (ushort *)0x815c0aa;
  if (DAT_0203a454 == 0xb) {
    puVar4 = (ushort *)0x815bfea;
  }
  arg3 = 0x12;
  arg2 = 0x5b;
  uVar2 = *puVar4;
  while (uVar2 != 0x301) {
    if (uVar2 == 0x300) {
      arg3 = 0x12;
      arg2 = arg2 + 0xc & 0xffff;
    }
    else {
      if (uVar2 == 0xcc) {
        arg0_00 = sub_080D45B8((uint)uVar1);
        sub_080CF1DC(arg0_00,arg3,arg2);
      }
      else if (uVar2 == 0xcd) {
        arg0_00 = sub_081571DC((uint)uVar1);
        sub_080CF1DC(arg0_00,arg3,arg2);
      }
      else {
        FontSprite_DrawGlyph((uint)*puVar4,0,0,arg3);
        arg0_00 = arg3 + 0xc;
      }
      arg3 = arg0_00 & 0xffff;
    }
    puVar4 = puVar4 + 1;
    uVar2 = *puVar4;
  }
                    /* WARNING: Could not recover jumptable at 0x080cf320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CF324 @ 0x080CF324

void sub_080CF324(int arg0)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C0148(0x8000);
  iVar2 = sub_080C92C8((uint)DAT_0203a456);
  uVar7 = (uint)*(ushort *)(iVar2 + 0x12);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (DAT_0203a454 == 0xb) {
    uVar3 = sub_080C32D4(0x11f);
    iVar2 = sub_080D45B8(uVar7);
    if ((int)(uVar3 & 0xff) < iVar2) {
      *(undefined2 *)(arg0 + 0x1e) = 1;
      goto LAB_080cf408;
    }
    uVar3 = sub_080C3100();
    uVar4 = sub_081571DC(uVar7);
    if (uVar3 < uVar4) goto LAB_080cf3f8;
    iVar6 = 0;
    iVar2 = 0;
    do {
      iVar5 = sub_080C09B0(iVar2 + 4);
      if (iVar5 != 0) {
        iVar6 = iVar6 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xc);
    iVar2 = sub_080C104C();
    if (iVar2 <= iVar6) {
      *(undefined2 *)(arg0 + 0x1e) = 3;
      goto LAB_080cf408;
    }
    iVar2 = sub_080BF648(uVar7);
    if (*(byte *)(iVar1 + 0xd) < *(byte *)(iVar2 + 1)) {
      *(undefined2 *)(arg0 + 0x1e) = 4;
      goto LAB_080cf408;
    }
    iVar1 = sub_080C06BC((uint)*(byte *)(iVar1 + 0xc));
    iVar2 = sub_0815B864();
    if (((iVar1 == 0) && (iVar2 == 2)) || ((iVar1 == 2 && (iVar2 == 0)))) {
      *(undefined2 *)(arg0 + 0x1e) = 5;
      goto LAB_080cf408;
    }
  }
  else {
    uVar3 = sub_080C3100();
    uVar7 = sub_081571DC(uVar7);
    if (uVar3 < uVar7) {
LAB_080cf3f8:
      *(undefined2 *)(arg0 + 0x1e) = 2;
      goto LAB_080cf408;
    }
  }
  sub_080AB91C(DAT_0203a4a4,1);
LAB_080cf408:
                    /* WARNING: Could not recover jumptable at 0x080cf412. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CF414 @ 0x080CF414

void sub_080CF414(int arg0)

{
  short sVar1;
  dword arg0_00;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) != 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_030031cc = 1;
    sub_080AB91C(DAT_0203a4a4,1);
    sub_080C51D4(0x65);
    return;
  }
  sVar1 = *(short *)(arg0 + 0x1e);
  if (sVar1 == 1) {
    arg0_00 = 0x815c02c;
  }
  else if (sVar1 == 2) {
    arg0_00 = 0x815c048;
  }
  else if (sVar1 == 3) {
    arg0_00 = 0x815c05a;
  }
  else {
    if (sVar1 != 4) {
      if (sVar1 == 5) {
        Text_DrawSpriteString(0x815c082,0,0,0x12);
      }
      goto LAB_080cf4b0;
    }
    arg0_00 = 0x815c06e;
  }
  Text_DrawSpriteString(arg0_00,0,0,0x12);
LAB_080cf4b0:
  if ((DAT_030031bc >> 4 & 1) == 0) {
    sub_080C4AB0(0,0,0xd5,0x8d);
  }
  return;
}


// sub_080CF4DC @ 0x080CF4DC

void sub_080CF4DC(short *arg0)

{
  short *arg0_00;
  uint uVar1;
  undefined4 local_1c;
  undefined4 local_18;
  
  uVar1 = 0;
  do {
    arg0_00 = (short *)(uVar1 * 100 + 0x2009004);
    if ((arg0 != arg0_00) && (*arg0_00 == -1)) {
      sub_080AD1FC(arg0_00);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x40);
  DAT_0203db6a = 0;
  sub_080AE2D0();
  DAT_020391dc = 0;
  DAT_0200e8d4 = 0;
  sub_080C6E30(0);
  DAT_0200e804 = 1;
  local_1c = 0;
  CpuSet(&local_1c,0x2017874,0x5000200);
  local_18 = 0;
  CpuSet(&local_18,&DAT_02018874,0x5000200);
  DAT_03004534 = 0xbe;
  return;
}


// sub_080CF57C @ 0x080CF57C

void sub_080CF57C(void)

{
  int iVar1;
  dword arg0;
  int iVar2;
  
  iVar1 = sub_080C92C8((uint)DAT_0203a456);
  if (DAT_0203a454 == 0xb) {
    sub_080C23BC(0x162);
    arg0 = 0x84f3880;
  }
  else {
    arg0 = 0x84f39b4;
  }
  iVar2 = sub_080AD0FC(arg0,(uint)*(ushort *)(DAT_0203a48c + 2));
  *(undefined2 *)(iVar2 + 0x1e) = *(undefined2 *)(iVar1 + 0x12);
  return;
}


// sub_080CF5C0 @ 0x080CF5C0

void sub_080CF5C0(void)

{
  sub_0812D0FC(1);
  return;
}


// sub_080CF5CC @ 0x080CF5CC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CF5CC(void)

{
  _DAT_0203a45c = sub_080B6B58(0x80cf5c1,0);
  return;
}


// sub_080CF5E8 @ 0x080CF5E8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CF5E8(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(*(int *)(_DAT_0203a45c + 0xc) == -1);
  return;
}


// sub_080CF60C @ 0x080CF60C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CF60C(void)

{
  *(undefined4 *)(_DAT_0203a45c + 0xc) = 1;
  return;
}


// sub_080CF61C @ 0x080CF61C

void sub_080CF61C(void)

{
  ushort uVar1;
  undefined4 uVar2;
  
  REG_BG1CNT = 0x8205;
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 & 0xfbff;
  DAT_03000040 = 0;
  REG_DMA3SAD = 0x81b93b0;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000200;
  uVar2 = REG_DMA3CNT;
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84001800;
  uVar2 = REG_DMA3CNT;
  return;
}


// sub_080CF680 @ 0x080CF680

uint sub_080CF680(uint arg0)

{
  uint uVar1;
  
  switch(arg0 & 0xffff) {
  case 0:
    uVar1 = sub_080C2AFC();
    arg0 = uVar1 & 0xffff;
    break;
  case 1:
    uVar1 = Settings_GetBattleMsgSpeed();
    arg0 = uVar1 & 0xffff;
    break;
  case 2:
    uVar1 = sub_080C2B6C();
    arg0 = uVar1 & 0xffff;
    break;
  case 3:
    uVar1 = sub_080C2BA4();
    arg0 = uVar1 & 0xffff;
    break;
  case 4:
    uVar1 = sub_080C2BF0();
    arg0 = uVar1 & 0xffff;
    break;
  case 5:
    uVar1 = sub_080C2C30();
    arg0 = uVar1 & 0xffff;
    break;
  case 6:
    uVar1 = sub_080C2C70();
    arg0 = uVar1 & 0xffff;
    break;
  case 7:
    arg0 = 0;
  }
  return arg0;
}


// sub_080CF708 @ 0x080CF708

void sub_080CF708(undefined4 arg0,uint arg1)

{
  uint arg0_00;
  
  arg0_00 = arg1 & 0xffff;
  switch((undefined2)arg0) {
  case 0:
    sub_080C2B14(arg0_00);
    break;
  case 1:
    sub_080C2B4C(arg0_00);
    break;
  case 2:
    sub_080C2B84(arg0_00);
    break;
  case 3:
    sub_080C2BCC(arg0_00);
    break;
  case 4:
    sub_080C2C0C(arg0_00);
    break;
  case 5:
    sub_080C2C4C(arg0_00);
    break;
  case 6:
    sub_080C2C9C(arg0_00);
    sub_080C1384();
    if ((DAT_0200ab04 & 0x8000) == 0) {
      sub_080B04BC();
    }
    else {
      sub_080B4140();
    }
    sub_080ACFCC(3,0x30029b0,0x201b874,0x400);
    sub_080ACFCC(3,0x30029b0,0x3002db0,0x400);
    sub_080AABB0();
  }
  return;
}


// sub_080CF7D8 @ 0x080CF7D8

void sub_080CF7D8(undefined4 arg0,uint arg1)

{
  dword arg0_00;
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort local_1c [4];
  
  uVar3 = 0;
  local_1c[0] = 2;
  local_1c[1] = 2;
  local_1c[2] = 2;
  local_1c[3] = 8;
  if (DAT_0203a454 == arg1) {
    if (DAT_0203a458 == 0) {
      uVar3 = 4;
    }
    local_1c[3] = 4;
    sub_080D0020(arg1 & 0xffff);
  }
  uVar1 = (uint)DAT_0203a456;
  uVar2 = (int)(-uVar1 | uVar1) >> 0x1f & 0x10;
  switch(arg1) {
  case 0:
    if (uVar1 != 0) {
      return;
    }
    sub_080AC7CC(0,0x200f874,0xc,0x1b);
    sub_080CCEC8(0x84f18a0,0xc,0x1b,uVar3);
    sub_080CCEC8(0x84f18a4,0x2a,0x1b,uVar3);
    uVar1 = sub_080CF680(0);
    local_1c[uVar1 & 0xffff] = local_1c[3];
    sub_080CCEC8(0x84f18ac,0x7c,0x1b,(uint)local_1c[0]);
    sub_080CCEC8(0x84f18b4,0xb4,0x1b,(uint)local_1c[1]);
    return;
  case 1:
    uVar2 = 0x2b - uVar2 & 0xffff;
    sub_080AC7CC(0,0x200f874,0xc,uVar2);
    sub_080CCEC8(0x84f18bc,0xc,uVar2,uVar3);
    sub_080CCEC8(0x84f18a0,0x2a,uVar2,uVar3);
    sub_080CCEC8(0x84f18a4,0x48,uVar2,uVar3);
    uVar1 = sub_080CF680(1);
    local_1c[uVar1 & 0xffff] = local_1c[3];
    sub_080CCEC8(0x84f18ac,0x7c,uVar2,(uint)local_1c[0]);
    arg0_00 = 0x84f18b4;
    uVar1 = (uint)local_1c[1];
    uVar3 = 0xb4;
    break;
  case 2:
    uVar2 = 0x3b - uVar2 & 0xffff;
    sub_080AC7CC(0,0x200f874,0xc,uVar2);
    sub_080CCEC8(0x84f18bc,0xc,uVar2,uVar3);
    sub_080CCEC8(0x84f18c0,0x2a,uVar2,uVar3);
    uVar1 = sub_080CF680(2);
    local_1c[uVar1 & 0xffff] = local_1c[3];
    sub_080CCEC8(0x84f18c8,0x8c,uVar2,(uint)local_1c[0]);
    arg0_00 = 0x84f18cc;
    uVar1 = (uint)local_1c[1];
    uVar3 = 0xbc;
    break;
  case 3:
    uVar2 = 0x4b - uVar2 & 0xffff;
    sub_080AC7CC(0,0x200f874,0xc,uVar2);
    sub_080CCEC8(0x84f18d0,0xc,uVar2,uVar3);
    sub_080CCEC8(0x84f18bc,0x32,uVar2,uVar3);
    uVar1 = sub_080CF680(3);
    local_1c[uVar1 & 0xffff] = local_1c[3];
    sub_080CCEC8(0x84f18d8,0x5e,uVar2,(uint)local_1c[0]);
    sub_080CCEC8(0x84f18e0,0x8e,uVar2,(uint)local_1c[1]);
    arg0_00 = 0x84f18e8;
    uVar1 = (uint)local_1c[2];
    uVar3 = 0xbe;
    break;
  case 4:
    uVar2 = 0x5b - uVar2 & 0xffff;
    sub_080AC7CC(0,0x200f874,0xc,uVar2);
    sub_080CCEC8(0x84f18d0,0xc,uVar2,uVar3);
    sub_080CCEC8(0x84f18f0,0x32,uVar2,uVar3);
    uVar1 = sub_080CF680(4);
    local_1c[uVar1 & 0xffff] = local_1c[3];
    sub_080CCEC8(0x84f18f4,0x88,uVar2,(uint)local_1c[0]);
    arg0_00 = 0x84f18f8;
    uVar1 = (uint)local_1c[1];
    uVar3 = 0xb8;
    break;
  case 5:
    uVar2 = 0x6b - uVar2 & 0xffff;
    sub_080AC7CC(0,0x200f874,0xc,uVar2);
    sub_080CCEC8(0x84f18d0,0xc,uVar2,uVar3);
    sub_080CCEC8(0x84f1900,0x32,uVar2,uVar3);
    uVar1 = sub_080CF680(5);
    local_1c[uVar1 & 0xffff] = local_1c[3];
    sub_080CCEC8(0x84f1908,0x84,uVar2,(uint)local_1c[0]);
    arg0_00 = 0x84f1910;
    uVar1 = (uint)local_1c[1];
    uVar3 = 0xb4;
    break;
  case 6:
    uVar2 = 0x7b - uVar2 & 0xffff;
    sub_080AC7CC(0,0x200f874,0xc,uVar2);
    sub_080CCEC8(0x84f1918,0xc,uVar2,uVar3);
    uVar1 = sub_080CF680(6);
    local_1c[uVar1 & 0xffff] = local_1c[3];
    sub_080CCEC8(0x84f18ac,0x5e,uVar2,(uint)local_1c[0]);
    sub_080CCEC8(0x84f1920,0xa2,uVar2,(uint)local_1c[1]);
    arg0_00 = 0x84f1924;
    uVar1 = (uint)local_1c[2];
    uVar3 = 200;
    break;
  case 7:
    if (uVar1 != 0) {
      sub_080AC7CC(0,0x200f874,0xc,0x7b);
      sub_080CCEC8(0x84f1928,0x68,0x7b,uVar3);
    }
  default:
    goto switchD_080cf82c_default;
  }
  sub_080CCEC8(arg0_00,uVar3,uVar2,uVar1);
switchD_080cf82c_default:
  return;
}


// sub_080CFBE8 @ 0x080CFBE8

void sub_080CFBE8(undefined4 arg0)

{
  uint arg1;
  
  arg1 = 0;
  do {
    sub_080CF7D8(arg0,arg1);
    arg1 = arg1 + 1;
  } while (arg1 < 8);
  return;
}


// sub_080CFC04 @ 0x080CFC04

void sub_080CFC04(void)

{
  undefined4 in_r0;
  
  sub_080CFBE8(in_r0);
  return;
}


// sub_080CFC10 @ 0x080CFC10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CFC10(undefined4 arg0)

{
  undefined4 uVar1;
  undefined4 uStack_14;
  
  DAT_0203a460 = sub_080AB860(1,0,0x1c,2);
  _DAT_0203a464 = sub_080AB860(1,2,0x1c,2);
  _DAT_0203a468 = sub_080AB860(1,4,0x1c,2);
  _DAT_0203a46c = sub_080AB860(1,6,0x1c,2);
  _DAT_0203a470 = sub_080AB860(1,8,0x1c,2);
  _DAT_0203a474 = sub_080AB860(1,10,0x1c,2);
  DAT_0203a478 = sub_080AB860(1,0xc,0x1c,2);
  DAT_0203a47c = sub_080AB860(1,0xe,0x1c,2);
  _DAT_0203a480 = sub_080AB860(2,0x10,0x1a,4);
  uStack_14 = 0;
  REG_DMA3SAD = &uStack_14;
  REG_DMA3DAD = 0x200f874;
  REG_DMA3CNT = 0x85002000;
  uVar1 = REG_DMA3CNT;
  sub_080CCEC8(0x84f1930,0x60,0xc,4);
  sub_080CFBE8(arg0);
  sub_080D0020(0);
  DisplayList_Add(0x80cf61d,1);
  return;
}


// sub_080CFD00 @ 0x080CFD00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CFD00(int arg0)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  bVar2 = false;
  puVar6 = (ushort *)((_DAT_0203a454 & 0xffff) * 8 + 0x84f1938);
  uVar5 = (uint)*puVar6;
  uVar3 = sub_080CF680(_DAT_0203a454 & 0xffff);
  uVar3 = uVar3 & 0xffff;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (((DAT_030031b8 & 1) == 0) || (DAT_0203a454 != 7)) {
    if ((DAT_030031b8 & 2) == 0) {
      if (((DAT_03003964 & 0x40) == 0) || (uVar4 = _DAT_0203a454 & 0xffff, uVar4 == 0)) {
        if (((DAT_03003964 & 0x80) == 0) || (DAT_0203a454 == 7)) {
          if (((DAT_030031b8 & 0x20) == 0) || (DAT_0203a454 == 7)) {
            if (((DAT_030031b8 & 0x10) != 0) && (DAT_0203a454 != 7)) {
              if (uVar3 == uVar5 - 1) {
                uVar5 = 0;
              }
              else {
                uVar5 = uVar3 + 1 & 0xffff;
              }
              sub_080CF708(_DAT_0203a454 & 0xffff,(uint)puVar6[uVar5 + 1]);
              bVar2 = true;
              sub_080C51D4(100);
            }
            goto LAB_080cfea4;
          }
          if (uVar3 != 0) {
            uVar5 = uVar3;
          }
          sub_080CF708(_DAT_0203a454 & 0xffff,(uint)puVar6[(uVar5 - 1 & 0xffff) + 1]);
        }
        else if (_DAT_0203a454 == 6) {
          _DAT_0203a454 = 0x10007;
          sub_080CFC04();
        }
        else {
          uVar1 = DAT_0203a454 + 1;
          _DAT_0203a454 = CONCAT22(DAT_0203a456,uVar1);
          sub_080CF7D8(arg0,uVar1 - 1);
        }
        bVar2 = true;
        sub_080C51D4(100);
      }
      else {
        if ((uVar4 == 1) && (DAT_0203a456 != 0)) {
          _DAT_0203a454 = CONCAT22(DAT_030031b8,DAT_030031b8) & 0x20002;
          sub_080CFC04();
        }
        else if (uVar4 == 0) {
          _DAT_0203a454 = CONCAT22(DAT_0203a456,7);
          sub_080CF7D8(arg0,0);
        }
        else {
          uVar1 = DAT_0203a454 - 1;
          _DAT_0203a454 = CONCAT22(DAT_0203a456,uVar1);
          sub_080CF7D8(arg0,uVar1 + 1);
        }
        sub_080C51D4(100);
        bVar2 = true;
      }
    }
    else {
      uVar5 = _DAT_0203a454 & 0xffff;
      _DAT_0203a454 = CONCAT22(DAT_0203a456,7);
      if (DAT_0203a456 == 0) {
        _DAT_0203a454 = 0x10007;
        sub_080CFC04();
      }
      else {
        sub_080CF7D8(arg0,uVar5);
      }
      sub_080C51D4(0x66);
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C51D4(0x65);
  }
LAB_080cfea4:
  if ((DAT_030031bc & 3) == 0) {
    DAT_0203a458 = DAT_0203a458 + 1 & 1;
    bVar2 = true;
  }
  if (bVar2) {
    sub_080CF7D8(arg0,_DAT_0203a454 & 0xffff);
    DisplayList_Add(0x80cf61d,1);
  }
  if ((DAT_030031bc >> 4 & 1) == 0) {
    if (DAT_0203a456 == 0) {
      sub_080C4AB0(0,0,0xe8,0x80);
    }
    else {
      sub_080C4A4C(0,0,0xe8,10);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080cff14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CFF18 @ 0x080CFF18

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CFF18(void)

{
  sub_080AB91C(DAT_0203a460,1);
  sub_080AB91C(_DAT_0203a464,1);
  sub_080AB91C(_DAT_0203a468,1);
  sub_080AB91C(_DAT_0203a46c,1);
  sub_080AB91C(_DAT_0203a470,1);
  sub_080AB91C(_DAT_0203a474,1);
  sub_080AB91C(DAT_0203a478,1);
  sub_080AB91C(DAT_0203a47c,1);
  sub_080AB91C(_DAT_0203a480,1);
  if (DAT_0203a45a == 0) {
    sub_080D5B8C(4);
  }
  else {
    *(undefined4 *)(_DAT_0203a45c + 0xc) = 1;
  }
  return;
}


// sub_080CFF84 @ 0x080CFF84

void sub_080CFF84(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x81000800;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x81000800;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x81000800;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080CFFCC @ 0x080CFFCC

void sub_080CFFCC(void)

{
  DisplayList_Add(0x80cff85,1);
  return;
}


// sub_080CFFE0 @ 0x080CFFE0

void sub_080CFFE0(undefined4 arg0)

{
  undefined4 local_14;
  
  sub_080AD0FC(0x84f1970,0xffff);
  local_14 = 0;
  CpuSet(&local_14,0x203a454,0x5000200);
  DAT_0203a45a = (undefined2)arg0;
  return;
}


// sub_080D0020 @ 0x080D0020

void sub_080D0020(uint arg0)

{
  uint uVar1;
  uint arg0_00;
  undefined *arg0_01;
  undefined4 unaff_r7;
  undefined4 uStack_18;
  
  arg0_00 = arg0 & 0xffff;
  uVar1 = sub_080CF680(arg0_00);
  arg0_01 = *(undefined **)((uVar1 & 0xffff) * 4 + arg0_00 * 0x10 + 0x84f1d5c);
  if ((arg0_00 == 7) && (DAT_0203a45a == 0)) {
    arg0_01 = &DAT_084f1c90;
  }
  uStack_18 = 0;
  CpuSet(&uStack_18,0x2013c74,0x5000400);
  Text_DrawString(arg0_01,unaff_r7,0x12,0x8c);
  return;
}


// sub_080D0084 @ 0x080D0084

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D0084(undefined4 arg0,undefined4 arg1,int arg2)

{
  Font_ResetGlyphSpriteCache(0x180);
  DAT_0203a47c = 1;
  _DAT_0203a480 = arg1;
  if (_DAT_0203a474 == 0) {
    _DAT_0203a474 = sub_080AB860(1,0xd,0x1c,7);
  }
  if (arg2 == 1) {
    DAT_0203a478 = sub_080ABEB4(1);
  }
  return;
}


// sub_080D00CC @ 0x080D00CC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080D00CC(void)

{
  DAT_0203a47c = 0;
  if (_DAT_0203a474 != 0) {
    sub_080AB91C(_DAT_0203a474,1);
    _DAT_0203a474 = 0;
  }
  return;
}


// sub_080D00EC @ 0x080D00EC

void sub_080D00EC(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080ABF04(DAT_0203a478);
  *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 == 1);
  return;
}


// sub_080D010C @ 0x080D010C

void sub_080D010C(int arg0)

{
  *(short *)(arg0 + 0x1e) = (short)DAT_030031cc;
  return;
}


// sub_080D0118 @ 0x080D0118

void sub_080D0118(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0203a456 == 2) {
    Field_SetState(0x1a);
  }
  else if (DAT_0203a454 == 4) {
    sub_080D5B8C(3);
  }
  else if (DAT_0203a454 == 3) {
    Field_SetState(0x19);
  }
  else {
    sub_0812D0FC(1);
  }
                    /* WARNING: Could not recover jumptable at 0x080d0152. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080D0154 @ 0x080D0154

void sub_080D0154(void)

{
  DAT_0203a460 = sub_080B6B58(0x80d0119,0);
  return;
}


// sub_080D0170 @ 0x080D0170

void sub_080D0170(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(*(int *)(DAT_0203a460 + 0xc) == -1);
  return;
}


// sub_080D0194 @ 0x080D0194

void sub_080D0194(void)

{
  *(undefined4 *)(DAT_0203a460 + 0xc) = 1;
  return;
}


// sub_080D01A4 @ 0x080D01A4

void sub_080D01A4(int arg0)

{
  *(undefined2 *)(arg0 + 0x1e) = DAT_0203a454;
  return;
}


// sub_080D01B0 @ 0x080D01B0

void sub_080D01B0(byte *arg0,uint arg1,uint arg2,undefined4 arg3)

{
  char *pcVar1;
  char local_20;
  char local_1f;
  char local_1e;
  undefined1 local_1d;
  char local_1c;
  char local_1b;
  undefined1 local_1a;
  
  pcVar1 = (char *)sub_080A9CC0((uint)*arg0);
  local_20 = pcVar1[2] + '0';
  local_1f = pcVar1[1] + '0';
  local_1e = *pcVar1 + '0';
  local_1d = 0x3a;
  pcVar1 = (char *)sub_080A9CC0((uint)arg0[1]);
  local_1c = pcVar1[1] + '0';
  local_1b = *pcVar1 + '0';
  local_1a = 0;
  sub_080ACAB0(&local_20,0x200f874,arg1 & 0xffff,arg2 & 0xffff);
  return;
}


// sub_080D0238 @ 0x080D0238

void sub_080D0238(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84001800;
  uVar1 = REG_DMA3CNT;
  DAT_0203a458 = 0;
  return;
}


// sub_080D0264 @ 0x080D0264

void sub_080D0264(void)

{
  if (DAT_0203a458 == 0) {
    DisplayList_Add(0x80d0239,1);
    DAT_0203a458 = 1;
  }
  return;
}


// Menu_DrawCombatantName8px @ 0x080D0288

void Menu_DrawCombatantName8px(byte *arg0,uint arg1,uint arg2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  
  uVar2 = arg1 & 0xffff;
  uVar4 = 0;
  bVar1 = *arg0;
  pbVar3 = arg0;
  while (bVar1 != 0xff) {
    sub_080AC4E4((uint)*pbVar3 * 0x20 + 0x81af7b8,0x200f874,0,0);
    pbVar3 = pbVar3 + 1;
    uVar4 = uVar4 + 1;
    if (7 < uVar4) break;
    bVar1 = *pbVar3;
  }
  uVar4 = (arg2 & 0xffff) + 1 & 0xffff;
  sub_080CCE5C(0x84f20a4,uVar2 + 0x48 & 0xffff,uVar4,0);
  if (arg0[0xd] < 10) {
    sub_080CCF44((uint)arg0[0xd],uVar2 + 0x58 & 0xffff,uVar4,0);
  }
  else {
    sub_080CCF44((uint)arg0[0xd],uVar2 + 0x60 & 0xffff,uVar4,0);
  }
  return;
}


// sub_080D0340 @ 0x080D0340

uint sub_080D0340(int arg0,uint arg1)

{
  return (int)(uint)*(byte *)(arg0 + 0x15e8U + (arg1 >> 3)) >> (arg1 & 7) & 1;
}


// SaveScreen_DrawLocationName @ 0x080D035C

void SaveScreen_DrawLocationName(int arg0,undefined4 arg1,uint arg2,int arg3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  
  if ((((short)arg1 == 3) || (iVar3 = sub_080D0340(arg0,0x163), iVar3 != 0)) ||
     (iVar3 = sub_080D0340(arg0,0xee), iVar3 == 0)) {
    puVar4 = (ushort *)
             Location_GetNameCellFromCoords
                       ((uint)*(ushort *)(arg0 + 0xa32),(uint)*(ushort *)(arg0 + 0xa34),
                        (uint)*(ushort *)(arg0 + 0xa2e),(uint)*(ushort *)(arg0 + 0xa30));
  }
  else {
    puVar4 = (ushort *)0x84f20a8;
  }
  uVar2 = 0;
  uVar1 = *puVar4;
  if (((uVar1 != 0) && (uVar1 != 0x301)) && (uVar1 != 0x57)) {
    while( true ) {
      Font_DrawGlyphTinted((uint)*puVar4,0x200f874,arg2 & 0xffff,arg3 * 0x10000 - 0x40000U >> 0x10);
      puVar4 = puVar4 + 1;
      arg2 = (arg2 & 0xffff) + 0xc;
      uVar2 = uVar2 + 1;
      if ((0xf < uVar2) || (uVar1 = *puVar4, uVar1 == 0)) break;
      if (uVar1 == 0x301) {
        return;
      }
      if (uVar1 == 0x57) {
        return;
      }
    }
  }
  return;
}


// SaveScreen_DrawTokenString @ 0x080D042C

void SaveScreen_DrawTokenString(ushort *arg0,int arg1)

{
  ushort uVar1;
  uint arg2;
  
  arg2 = 0x39;
  uVar1 = 0;
  if ((*arg0 != 0) && (*arg0 != 0x301)) {
    while( true ) {
      Font_DrawGlyphTinted((uint)*arg0,0x200f874,arg2,arg1 * 0x10000 - 0x40000U >> 0x10);
      arg0 = arg0 + 1;
      arg2 = arg2 + 0xc & 0xffff;
      uVar1 = uVar1 + 1;
      if (7 < uVar1) break;
      if (*arg0 == 0) {
        return;
      }
      if (*arg0 == 0x301) {
        return;
      }
    }
  }
  return;
}


// sub_080D0498 @ 0x080D0498

void sub_080D0498(undefined4 arg0,uint arg1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 arg2;
  ushort *puVar4;
  dword arg0_00;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar5 = arg1 * 0x280000 + 0x1e0000 >> 0x10;
  if (arg1 == 3) {
    uVar5 = 0x46;
  }
  else {
    sub_080CCE5C(0x84f20ec,0xd,uVar5,4);
    sub_080CCF44(arg1 + 1,0x2d,uVar5,4);
  }
  iVar2 = sub_080D13D0(arg1);
  if ((iVar2 != 1) || (iVar2 = sub_080D1328(arg1,0x2017874,1), iVar2 != 1)) {
    uVar5 = uVar5 + 0xb & 0xffff;
    sub_080CCE5C(0x84f20f4,0xd,uVar5,2);
    sub_080CCE5C(0x84f20f8,0x25,uVar5,2);
    goto LAB_080d065a;
  }
  iVar2 = sub_080D0340(0x2017874,0xee);
  if (iVar2 == 0) {
    sub_080D01B0(0x2018358,0xb4,uVar5 + 0x16 & 0xffff,0);
  }
  else {
    sub_080D01B0(0x2018358,0xb4,uVar5 + 0x16 & 0xffff,10);
  }
  if (sRam02018334 == 0) {
    if (arg1 == 3) {
      uVar3 = 3;
      arg2 = 0x2d;
    }
    else {
      iVar2 = sub_080C8B54((uint)uRam020182a6);
      if (iVar2 != 0) {
        SaveScreen_DrawTokenString(iVar2,uVar5);
        goto LAB_080d05de;
      }
      sub_080C8B10((uint)uRam020182a6,(uint)uRam020182a8);
      uVar3 = arg1 & 0xffff;
      arg2 = 0x39;
    }
    SaveScreen_DrawLocationName(0x2017874,uVar3,arg2,uVar5);
  }
  else {
    puVar4 = (ushort *)((uint)uRam020182da * 0x20 + 0x80a94ac);
    uVar3 = 0x39;
    uVar1 = 0;
    do {
      if (*puVar4 == 0x57) break;
      Font_DrawGlyphTinted((uint)*puVar4,0x200f874,uVar3,uVar5 - 4 & 0xffff);
      puVar4 = puVar4 + 1;
      uVar3 = uVar3 + 0xc & 0xffff;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 9);
  }
LAB_080d05de:
  iVar2 = 0;
  uVar3 = 0;
  arg0_00 = 0x2017874;
  do {
    if (*(short *)(arg0_00 + 0xe) != 0) {
      if (iVar2 == 1) {
        Menu_DrawCombatantName8px(arg0_00,0xd,uVar5 + 0x16 & 0xffff);
      }
      else if (iVar2 == 0) {
        Menu_DrawCombatantName8px(arg0_00,0xd,uVar5 + 0xb & 0xffff);
      }
      else if (iVar2 == 2) {
        Menu_DrawCombatantName8px(arg0_00,0x7c,uVar5 + 0xb & 0xffff);
      }
      iVar2 = iVar2 + 1;
    }
    arg0_00 = arg0_00 + 0x80;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
LAB_080d065a:
                    /* WARNING: Could not recover jumptable at 0x080d0668. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


