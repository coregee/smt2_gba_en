/* Ghidra decompilation of asm/code_080C4C18.s (reference only; not compiled). */

// sub_080C4C18 @ 0x080C4C18

void sub_080C4C18(undefined4 arg0)

{
  return;
}


// sub_080C4C3C @ 0x080C4C3C

void sub_080C4C3C(uint arg0)

{
  (&DAT_0300518a)[arg0 >> 3] = (byte)(1 << (arg0 & 7)) | (&DAT_0300518a)[arg0 >> 3];
  return;
}


// sub_080C4C60 @ 0x080C4C60

undefined4 sub_080C4C60(uint arg0)

{
  uint arg0_00;
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg0 & 0xffff;
  if (arg0_00 < 0xd0) {
    iVar1 = sub_080BF32C(arg0_00);
    uVar2 = *(undefined4 *)(iVar1 + 0xc);
  }
  else {
    iVar1 = Action_GetRecord(arg0_00);
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
                    /* WARNING: Could not recover jumptable at 0x080c4c7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080C4C7C @ 0x080C4C7C

undefined4 sub_080C4C7C(uint arg0)

{
  uint arg0_00;
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg0 & 0xffff;
  if (arg0_00 < 0xd0) {
    iVar1 = sub_080BF32C(arg0_00);
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
  }
  else {
    iVar1 = Action_GetRecord(arg0_00);
    uVar2 = *(undefined4 *)(iVar1 + 8);
  }
                    /* WARNING: Could not recover jumptable at 0x080c4c96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080C4C98 @ 0x080C4C98

void sub_080C4C98(void)

{
  int iVar1;
  undefined4 uVar2;
  int arg0;
  
  arg0 = 4;
  do {
    iVar1 = sub_080F3EC8(arg0);
    if ((iVar1 == 0) && (iVar1 = sub_080C0830(), iVar1 == 0)) {
      sub_080F2F64(arg0 - 0x8000U & 0xffff);
      uVar2 = sub_080C0F8C(arg0);
      iVar1 = (int)(short)uVar2;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 3;
      }
      sub_080C0B30(arg0,(iVar1 >> 2) + 1);
    }
    arg0 = arg0 + 1;
  } while (arg0 < 0x10);
  return;
}


// sub_080C4CE8 @ 0x080C4CE8

dword sub_080C4CE8(undefined4 arg0)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint arg0_00;
  uint uVar4;
  uint arg0_01;
  
  uVar4 = 0;
  arg0_01 = 0xffff;
  arg0_00 = 0;
  do {
    iVar2 = sub_080C0148(arg0_00);
    if ((((iVar2 != 0) && (*(byte *)(iVar2 + 0xc) != (ushort)arg0)) &&
        (iVar3 = sub_080C0830(), iVar3 == 0)) && ((int)uVar4 < (int)*(short *)(iVar2 + 0x18))) {
      uVar4 = (uint)*(ushort *)(iVar2 + 0x18);
      arg0_01 = (uint)*(byte *)(iVar2 + 0xc);
    }
    arg0_00 = arg0_00 + 1 & 0xffff;
  } while (arg0_00 < 6);
  if (arg0_01 != 0xffff) {
    iVar2 = sub_080C0148((uint)(ushort)((ushort)arg0 + 0x8000));
    sVar1 = *(short *)(iVar2 + 0x18) + 1;
    *(short *)(iVar2 + 0x18) = sVar1;
    if (*(short *)(iVar2 + 0x1a) < sVar1) {
      *(undefined2 *)(iVar2 + 0x18) = *(undefined2 *)(iVar2 + 0x1a);
    }
    sub_080C0C70(arg0_01,1);
    sub_080C84A0();
  }
  return arg0_01;
}


// sub_080C4D74 @ 0x080C4D74

void sub_080C4D74(uint arg0)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  iVar1 = sub_080C0148(arg0 * 0x10000 + 0x80000000 >> 0x10);
  uVar2 = sub_080C0818(arg0_00);
  if ((uVar2 & 0x40) != 0) {
    iVar1 = (int)*(char *)(iVar1 + 0x41);
    if (iVar1 < 0) {
      iVar1 = iVar1 + 3;
    }
    uVar3 = sub_080C4E00((iVar1 >> 2) + 2U & 0xffff);
    if ((uVar3 & 0xffff) != 0) {
      sub_080C08BC(arg0_00,0xffbf);
      sub_080C84A0();
    }
  }
  if ((uVar2 & 0x20) != 0) {
    iVar1 = sub_080C4E24();
    uVar2 = sub_080C4E00(0xcU - iVar1 & 0xffff);
    if ((uVar2 & 0xffff) != 0) {
      sub_080C08BC(arg0_00,0xffdf);
      sub_080C84A0();
    }
  }
  return;
}


// sub_080C4E00 @ 0x080C4E00

undefined4 sub_080C4E00(uint arg0)

{
  uint uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((arg0 & 0xffff) < 0xf) && (uVar1 = sub_080C2244(), (arg0 & 0xffff) < (uVar1 & 0xf))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080c4e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2);
  return uVar2;
}


// sub_080C4E24 @ 0x080C4E24

uint sub_080C4E24(void)

{
  uint uVar1;
  
  uVar1 = sub_080C1D9C();
  uVar1 = (uVar1 & 0xff) >> 4;
  if (8 < uVar1) {
    uVar1 = 0x10 - uVar1 & 0xffff;
  }
  return uVar1;
}


// sub_080C4E48 @ 0x080C4E48

void sub_080C4E48(uint arg0,uint *arg1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint arg0_00;
  uint arg0_01;
  
  bVar1 = false;
  arg0_01 = 0;
  do {
    iVar2 = sub_080C0148(arg0_01 & 0xffff);
    if (iVar2 != 0) {
      arg0_00 = (uint)*(byte *)(iVar2 + 0xc);
      iVar2 = sub_080C09B0(arg0_00);
      if (((iVar2 == 1) && (iVar2 = sub_080C0830(), iVar2 == 0)) &&
         (uVar3 = sub_080C0818(arg0_00), (uVar3 & 0x8000) == 0)) {
        if ((uVar3 & 0x400) == 0) {
          if (((((uVar3 & 0x1000) != 0) && ((arg0 & 1) != 0)) ||
              (((uVar3 & 4) != 0 && ((arg0 & 3) == 3)))) ||
             (((uVar3 & 1) != 0 && ((arg0 & 3) == 3)))) {
            iVar2 = sub_080F401C(arg0_00);
            if (iVar2 == 1) {
              *arg1 = *arg1 | 1 << arg0_00;
            }
            sub_080C0C70(arg0_00,1);
            sub_080C8490(arg0_01);
            bVar1 = true;
          }
        }
        else {
          uVar3 = sub_080C4CE8(arg0_00);
          if ((uVar3 & 0xffff) != 0xffff) {
            iVar2 = sub_080F401C(uVar3 & 0xffff);
            if (iVar2 == 0) {
              *arg1 = *arg1 | 1 << (uVar3 & 0xff);
            }
            bVar1 = true;
          }
        }
        iVar2 = sub_080F401C(arg0_00);
        if (iVar2 != 0) {
          sub_080C4D74(arg0_00);
        }
      }
    }
    arg0_01 = arg0_01 + 1;
  } while ((int)arg0_01 < 6);
  if (bVar1) {
    sub_080B8AE0(0x7c1f,1);
    sub_080C51D4(299);
  }
  return;
}


// sub_080C4F88 @ 0x080C4F88

undefined4 sub_080C4F88(uint arg0)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint arg0_00;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar7 = 0;
  uVar5 = 0;
  uVar6 = 0;
  do {
    iVar2 = sub_080C0148(uVar6 & 0xffff);
    if (iVar2 != 0) {
      arg0_00 = (uint)*(byte *)(iVar2 + 0xc);
      iVar2 = sub_080C09B0(arg0_00);
      if (((iVar2 == 1) && (iVar2 = sub_080C0830(), iVar2 == 0)) &&
         (uVar3 = sub_080C0818(arg0_00), (uVar3 & 0x8000) == 0)) {
        if ((uVar3 & 0x400) == 0) {
          if (((uVar3 & 0x1000) != 0) && ((arg0 & 1) != 0)) {
            sub_080C0AD4(arg0_00,0xffffffff);
            goto LAB_080c503c;
          }
          if (((uVar3 & 5) != 0) && ((arg0 & 3) == 3)) {
            sub_080C0AD4(arg0_00,0xffffffff);
            uVar5 = uVar5 | 1;
          }
        }
        else {
          uVar3 = sub_080C4CE8(arg0_00);
          if ((uVar3 & 0xffff) != 0xffff) {
            iVar2 = sub_080F401C(uVar3 & 0xffff);
            if (iVar2 == 0) {
              uVar7 = uVar7 | 1 << (uVar3 & 0xff);
            }
LAB_080c503c:
            uVar5 = uVar5 | 1;
          }
        }
        iVar2 = sub_080F401C(arg0_00);
        if (iVar2 < 1) {
          sub_080C0818(arg0_00);
          sub_080C08F8(arg0_00,0x8000);
          if (arg0_00 < 4) {
            uVar5 = uVar5 | 4;
          }
          else {
            sub_080F4190(arg0_00);
            sub_080C366C();
            uVar5 = uVar5 | 2;
          }
        }
        else {
          sub_080C4D74(arg0_00);
        }
      }
    }
    uVar6 = uVar6 + 1;
    if (5 < (int)uVar6) {
      uVar6 = 0;
      do {
        iVar2 = sub_080C0148(uVar6 - 0x8000 & 0xffff);
        if ((1 << (uVar6 & 0xff) & uVar7) != 0) {
          sub_080C08F8((uint)*(byte *)(iVar2 + 0xc),0x8000);
          if (*(byte *)(iVar2 + 0xc) < 4) {
            uVar1 = 4;
          }
          else {
            sub_080F4190((uint)*(byte *)(iVar2 + 0xc));
            sub_080C366C();
            uVar1 = 2;
          }
          uVar5 = uVar5 | uVar1;
        }
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < 0x10);
                    /* WARNING: Could not recover jumptable at 0x080c5106. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar5);
      return uVar4;
    }
  } while( true );
}


// sub_080C5108 @ 0x080C5108

undefined4 sub_080C5108(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  bVar1 = false;
  iVar4 = 0;
  do {
    iVar2 = sub_080C0148(iVar4 - 0x8000U & 0xffff);
    if ((iVar2 != 0) && (*(short *)(iVar2 + 0xe) != 0)) {
      if (((*(ushort *)(iVar2 + 0x10) & 0xa000) == 0) && (*(short *)(iVar2 + 0x18) != 0))
      goto LAB_080c5150;
      bVar1 = true;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  if (bVar1) {
    uVar3 = 0;
  }
  else {
LAB_080c5150:
    uVar3 = 1;
  }
  return uVar3;
}


// sub_080C5158 @ 0x080C5158

void sub_080C5158(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080C5108();
  *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 == 1);
  return;
}


// sub_080C5170 @ 0x080C5170

void sub_080C5170(undefined4 arg0)

{
  if ((uint)(ushort)arg0 != (uint)DAT_030031b4) {
    DAT_030031ec = DAT_030031b4;
    DAT_030031b4 = (ushort)arg0;
    m4aSongNumStart((uint)(ushort)arg0);
  }
  return;
}


// sub_080C5198 @ 0x080C5198

void sub_080C5198(void)

{
  m4aSongNumStop((uint)DAT_030031b4);
  DAT_030031ec = DAT_030031b4;
  DAT_030031b4 = 0;
  return;
}


// sub_080C51BC @ 0x080C51BC

void sub_080C51BC(uint arg0)

{
  m4aMPlayFadeOut(0x203f2e0,arg0 & 0xffff);
  return;
}


// sub_080C51D4 @ 0x080C51D4

void sub_080C51D4(uint arg0)

{
  m4aSongNumStart(arg0 & 0xffff);
  return;
}


// sub_080C51E4 @ 0x080C51E4

void sub_080C51E4(void)

{
  DAT_0200e808 = 1;
  return;
}


// sub_080C51F0 @ 0x080C51F0

void sub_080C51F0(void)

{
  DAT_030050f8 = 0;
  sub_080C2D78((int)(char)DAT_03005f6c,(int)(char)DAT_03005f6e);
  return;
}


// sub_080C5224 @ 0x080C5224

void sub_080C5224(void)

{
  sub_080AD0FC(0x81a65f4,0xffff);
  Field_SetState(0x1a);
  return;
}


// sub_080C5240 @ 0x080C5240

undefined4 sub_080C5240(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_080C2340(1);
  if ((((iVar1 == 0) && (iVar1 = sub_080C2340(0xae), iVar1 == 0)) && (DAT_03004614 != 0x42)) &&
     (((DAT_03004614 != 0x4a && (DAT_03004614 != 0x4b)) &&
      ((DAT_03004614 != 0xf && (DAT_03005180 != 1)))))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// sub_080C528C @ 0x080C528C

void sub_080C528C(void)

{
  DAT_0200e808 = 1;
  return;
}


// sub_080C5298 @ 0x080C5298

void sub_080C5298(void)

{
  DAT_030050f8 = DAT_03005f6a;
  if (DAT_03005182 == '\0') {
    sub_080B710C((uint)DAT_03005f66,(uint)DAT_03005f68,(uint)DAT_03005f62,(uint)DAT_03005f64);
  }
  else {
    sub_080D0BA0();
  }
  return;
}


// sub_080C5304 @ 0x080C5304

void sub_080C5304(void)

{
  sub_080AD0FC(0x81a6634,0xffff);
  Field_SetState(0x1a);
  return;
}


// sub_080C5320 @ 0x080C5320

undefined4 sub_080C5320(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_080C2340(0xcb);
  if ((((((((iVar1 == 0) || (iVar1 = sub_080C2340(0x163), iVar1 == 0)) || (DAT_03005f66 == -1)) ||
         (((iVar1 = sub_080C2340(1), iVar1 != 0 || (iVar1 = sub_080C3560(0x52), iVar1 != 0)) ||
          ((iVar1 = sub_080C3560(0x53), iVar1 != 0 ||
           ((iVar1 = sub_080C2340(0xae), iVar1 != 0 || (DAT_03004614 == 0x42)))))))) ||
        (DAT_03004614 == 0x4a)) ||
       (((DAT_03004614 == 0x4b || (DAT_03004614 == 0xf)) ||
        ((iVar1 = sub_080C2340(0xd0), iVar1 != 0 && ((DAT_03005f66 == 0 || (DAT_03005f66 == 0x10))))
        )))) || ((iVar1 = sub_080C2340(0xd1), iVar1 != 0 && (DAT_03005f66 == 0x14)))) ||
     (((iVar1 = sub_080C2340(0x50), iVar1 != 0 && (DAT_03005f66 == 0x22)) || (DAT_03005180 == 1))))
  {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// sub_080C53F0 @ 0x080C53F0

void sub_080C53F0(void)

{
  return;
}


// sub_080C53F4 @ 0x080C53F4

void sub_080C53F4(uint arg0,uint arg1,uint arg2,uint arg3)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 *puVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = arg0 & 0xffff;
  uVar8 = arg1 & 0xffff;
  iVar3 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  puVar4 = (undefined2 *)((arg3 & 0xffff) * 0x24 + (arg2 & 0xffff) * 0xc + 0x200af08);
  if (((((int)(arg0 * 0x10000) < 0) || (DAT_0300456a <= uVar7)) || ((int)(arg1 * 0x10000) < 0)) ||
     (DAT_0300456c <= uVar8)) {
    uVar2 = 0;
  }
  else {
    iVar3 = sub_080B7944(iVar3,uVar7 + *(ushort *)(iVar3 + 8) & 0xffff,
                         uVar8 + *(ushort *)(iVar3 + 10) & 0xffff);
    uVar2 = 0;
    if (iVar3 != 0) {
      uVar5 = (uint)DAT_03004552;
      uVar1 = *(ushort *)((DAT_0300456a * uVar8 + uVar7) * 2 + DAT_03004570);
      uVar7 = 0;
      puVar6 = puVar4 + 2;
      do {
        *puVar6 = (ushort)((int)(uint)uVar1 >> (*(ushort *)(uVar5 * 2 + 0x815f2e6) & 0xff)) & 3;
        uVar5 = uVar5 + 1 & 3;
        puVar6 = puVar6 + 1;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 4);
      uVar2 = 1;
    }
  }
  *puVar4 = uVar2;
  return;
}


// sub_080C54D4 @ 0x080C54D4

void sub_080C54D4(int arg0)

{
  undefined4 uVar1;
  uint arg0_00;
  uint arg1;
  uint arg2;
  uint arg3;
  uint uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_28;
  uint uStack_24;
  
  uVar3 = (uint)DAT_03004562;
  uVar2 = (uint)DAT_03004564;
  local_28 = 0;
  REG_DMA3SAD = &local_28;
  REG_DMA3DAD = 0x200af08;
  REG_DMA3CNT = 0x8500002d;
  uVar1 = REG_DMA3CNT;
  if (arg0 == 1) {
    uVar3 = uVar3 + 2 & 0xffff;
    uVar2 = uVar2 - 1;
  }
  else if (arg0 == 0) {
    uVar3 = uVar3 - 1 & 0xffff;
    uVar2 = uVar2 - 2;
  }
  else if (arg0 == 2) {
    uVar3 = uVar3 + 1 & 0xffff;
    uVar2 = uVar2 + 2;
  }
  else {
    if (arg0 != 3) goto LAB_080c554a;
    uVar3 = uVar3 - 2 & 0xffff;
    uVar2 = uVar2 + 1;
  }
  uVar2 = uVar2 & 0xffff;
LAB_080c554a:
  arg3 = 0;
  do {
    arg2 = 0;
    uStack_24 = arg3 + 1;
    do {
      if (arg0 == 1) {
        arg1 = uVar2 + arg2 & 0xffff;
        arg0_00 = uVar3 - arg3 & 0xffff;
LAB_080c559e:
        sub_080C53F4(arg0_00,arg1,arg2,arg3);
      }
      else {
        if (arg0 == 0) {
          arg0_00 = uVar3 + arg2 & 0xffff;
          arg1 = uVar2 + arg3 & 0xffff;
          goto LAB_080c559e;
        }
        if (arg0 == 2) {
          arg0_00 = uVar3 - arg2 & 0xffff;
          arg1 = uVar2 - arg3 & 0xffff;
          goto LAB_080c559e;
        }
        if (arg0 == 3) {
          sub_080C53F4(uVar3 + arg3 & 0xffff,uVar2 - arg2 & 0xffff,arg2,arg3);
        }
      }
      arg2 = arg2 + 1 & 0xffff;
    } while (arg2 < 3);
    arg3 = uStack_24 & 0xffff;
    if (4 < arg3) {
                    /* WARNING: Could not recover jumptable at 0x080c55de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  } while( true );
}


// sub_080C55E0 @ 0x080C55E0

void sub_080C55E0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200dfd4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C5604 @ 0x080C5604

void sub_080C5604(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  short *arg0;
  undefined2 *puVar5;
  
  sub_080C54D4((uint)DAT_03004552);
  uVar2 = 0;
  do {
    uVar4 = 0;
    do {
      arg0 = (short *)(uVar2 * 0x24 + uVar4 * 0xc + 0x200af08);
      puVar5 = (undefined2 *)((uVar2 + 6) * 0x40 + uVar4 * 2 + 0x200e006);
      if (*arg0 == 1) {
        uVar3 = 0;
        do {
          if (arg0[uVar3 + 2] == 3) {
            arg0[uVar3 + 2] = 2;
          }
          uVar3 = uVar3 + 1 & 0xffff;
        } while (uVar3 < 4);
        uVar1 = sub_080B4448(arg0);
        *puVar5 = (short)uVar1;
      }
      else {
        *puVar5 = 0x3b4;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < 3);
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 5);
  sub_080AA184(0x80008c0,0,0,0);
  DAT_03000030 = 0xe0;
  DAT_03000031 = 200;
  DAT_03000034 = 0x58;
  DAT_03000035 = 0x30;
  DAT_03000038 = 0x1f;
  DisplayList_Add(0x80c55e1,1);
  return;
}


// sub_080C5708 @ 0x080C5708

void sub_080C5708(void)

{
  uint uVar1;
  uint uVar2;
  
  sub_080AE574((uint)DAT_03004552,1);
  uVar2 = 0;
  do {
    uVar1 = 0;
    do {
      *(undefined2 *)((uVar2 + 6) * 0x40 + uVar1 * 2 + 0x200e006) = 0;
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < 3);
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 5);
  DAT_03000038 = 0x3f;
  DisplayList_Add(0x80c55e1,1);
  DAT_030045a8 = 0;
  return;
}


// sub_080C576C @ 0x080C576C

void sub_080C576C(int arg0)

{
  uint uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 1;
  uVar1 = sub_080F3F44();
  if (((uVar1 & 0x100) != 0) &&
     (((((ushort)(DAT_03004550 - 1U) < 2 || (DAT_03004550 == 5)) || (DAT_03004550 == 6)) ||
      ((DAT_03004550 == 7 || (DAT_03004550 == 8)))))) {
    sub_080C5604();
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_080C57B4 @ 0x080C57B4

undefined4 sub_080C57B4(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080AD0FC(0x81a6674,0xffff);
  return uVar1;
}


// sub_080C57CC @ 0x080C57CC

undefined4 sub_080C57CC(uint arg0)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = sub_080C32D4(arg0 & 0xffff);
  if ((uVar1 & 0xff) != 0) goto LAB_080c5988;
  switch(arg0 & 0xffff) {
  case 300:
    iVar3 = sub_080C2340(0x5d);
    break;
  case 0x12d:
    uVar2 = 0;
    goto LAB_080c5afc;
  case 0x12e:
    uVar1 = sub_080C2A84(0);
    if ((((uVar1 & 0xffff) == 0) && (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 0)) &&
       (uVar1 = sub_080C2A84(2), (uVar1 & 0xffff) == 0)) goto LAB_080c5988;
    iVar3 = sub_080C2340(0x23);
    break;
  case 0x12f:
    uVar1 = sub_080C2A84(0);
    if (((uVar1 & 0xffff) == 0) || (iVar3 = sub_080C06BC(0), iVar3 != 2)) goto LAB_080c5988;
    iVar3 = sub_080C2340(0x4e);
    break;
  case 0x130:
  case 0x133:
switchD_080c57f2_caseD_130:
    uVar2 = 2;
    goto LAB_080c5afc;
  case 0x131:
    uVar2 = 0;
    goto LAB_080c5afc;
  case 0x132:
    uVar1 = sub_080C2A84(0);
    if ((((uVar1 & 0xffff) == 0) && (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 0)) &&
       (uVar1 = sub_080C2A84(2), (uVar1 & 0xffff) == 0)) goto LAB_080c5988;
    iVar3 = sub_080C2340(0x1e);
    break;
  case 0x134:
    uVar1 = sub_080C2A84(2);
    if (((uVar1 & 0xffff) == 0) || (iVar3 = sub_080C06BC(0), iVar3 != 0)) goto LAB_080c5988;
    iVar3 = sub_080C2340(0x71);
    break;
  default:
    goto switchD_080c57f2_caseD_135;
  case 0x137:
    uVar1 = sub_080C2A84(0);
    if (((((uVar1 & 0xffff) == 0) && (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 0)) &&
        (uVar1 = sub_080C2A84(2), (uVar1 & 0xffff) == 0)) || (iVar3 = sub_080C06BC(0), iVar3 != 0))
    goto LAB_080c5988;
    goto switchD_080c57f2_caseD_135;
  case 0x138:
    uVar1 = sub_080C2A84(0);
    if (((((uVar1 & 0xffff) == 0) && (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 0)) &&
        (uVar1 = sub_080C2A84(2), (uVar1 & 0xffff) == 0)) || (iVar3 = sub_080C06BC(0), iVar3 != 2))
    goto LAB_080c5988;
    iVar3 = sub_080C2340(0x5d);
    break;
  case 0x139:
    uVar1 = sub_080C2A84(1);
    if ((uVar1 & 0xffff) == 0) goto LAB_080c5988;
    iVar3 = sub_080C2340(0x23);
    break;
  case 0x13a:
    uVar1 = sub_080C2A84(0);
    if (((((uVar1 & 0xffff) == 0) && (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 0)) &&
        (uVar1 = sub_080C2A84(2), (uVar1 & 0xffff) == 0)) || (iVar3 = sub_080C06BC(0), iVar3 != 0))
    goto LAB_080c5988;
    iVar3 = sub_080C2340(0x5d);
    break;
  case 0x13b:
    uVar1 = sub_080C2A84(0);
    if (((((uVar1 & 0xffff) == 0) && (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 0)) &&
        (uVar1 = sub_080C2A84(2), (uVar1 & 0xffff) == 0)) || (iVar3 = sub_080C06BC(0), iVar3 != 1))
    goto LAB_080c5988;
    iVar3 = sub_080C2340(0x5d);
    break;
  case 0x13d:
    iVar3 = sub_080C2340(0xe7);
    break;
  case 0x13e:
  case 0x14b:
  case 0x14e:
  case 0x151:
  case 0x158:
    uVar1 = sub_080C2A84(0);
    if (((uVar1 & 0xffff) == 0) && (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 0))
    goto switchD_080c57f2_caseD_130;
    goto switchD_080c57f2_caseD_135;
  case 0x13f:
    iVar3 = sub_080C2340(0x1d);
    break;
  case 0x140:
    iVar3 = sub_080C2340(0xc);
    break;
  case 0x143:
    iVar3 = sub_080C2340(0x2d);
    break;
  case 0x144:
    iVar3 = sub_080C2340(0x48);
    break;
  case 0x145:
    iVar3 = sub_080C2340(0x49);
    break;
  case 0x149:
    iVar3 = sub_080C2340(0x2e);
    break;
  case 0x14c:
    uVar1 = sub_080C2A84(0);
    if ((((uVar1 & 0xffff) == 0) && (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 0)) &&
       (uVar1 = sub_080C2A84(2), (uVar1 & 0xffff) == 0)) goto LAB_080c5988;
    iVar3 = sub_080C2340(0x55);
    break;
  case 0x14d:
    uVar1 = sub_080C2A84(0);
    if ((((uVar1 & 0xffff) == 0) && (uVar1 = sub_080C2A84(1), (uVar1 & 0xffff) == 0)) &&
       (uVar1 = sub_080C2A84(2), (uVar1 & 0xffff) == 0)) goto LAB_080c5988;
    iVar3 = sub_080C2340(0xc9);
    break;
  case 0x153:
    iVar3 = sub_080C2340(0x36);
    break;
  case 0x154:
    uVar2 = 0;
LAB_080c5afc:
    iVar3 = sub_080C2A84(uVar2);
    iVar3 = iVar3 << 0x10;
  }
  if (iVar3 == 0) {
LAB_080c5988:
    uVar2 = 0;
  }
  else {
switchD_080c57f2_caseD_135:
    uVar2 = 1;
  }
  return uVar2;
}


// sub_080C5B10 @ 0x080C5B10

undefined4 sub_080C5B10(uint arg0)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Action_GetRecord(arg0 & 0xffff);
  if (*(int *)(iVar1 + 4) == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = sub_080C2340((arg0 & 0xffff) + 0xfff4 & 0xffff);
  }
  return uVar2;
}


// sub_080C5B3C @ 0x080C5B3C

void sub_080C5B3C(void)

{
  uint arg0;
  uint uVar1;
  
  uVar1 = 0;
  do {
    arg0 = (uint)*(byte *)(uVar1 + 0x30050e0);
    *(byte *)(uVar1 + 0x20360d4) = *(byte *)(uVar1 + 0x30050e0);
    if ((arg0 != 0) && (arg0 != 0xff)) {
      sub_080C0290(arg0,0);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 6);
  DAT_030050e0 = 0;
  DAT_030050e1 = 0xff;
  DAT_030050e2 = 0xff;
  DAT_030050e3 = 0xff;
  DAT_030050e4 = 0xff;
  DAT_030050e5 = 0xff;
  Party_BuildMemberNameTiles();
  sub_080C6FD8();
  return;
}


// sub_080C5BCC @ 0x080C5BCC

void sub_080C5BCC(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    bVar1 = *(byte *)(uVar3 + 0x20360d4);
    *(byte *)(uVar3 + 0x30050e0) = bVar1;
    if (bVar1 != 0xff) {
      iVar2 = sub_080C0148(bVar1 + 0x8000);
      *(undefined2 *)(iVar2 + 0xe) = 0xc000;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 6);
  Party_BuildMemberNameTiles();
  sub_080C6FD8();
  return;
}


// sub_080C5C14 @ 0x080C5C14

undefined4 sub_080C5C14(uint arg0)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = sub_080C32D4(arg0 & 0xffff);
  if (((uVar1 & 0xff) == 0) &&
     (iVar2 = sub_080C2340((uint)*(ushort *)(((arg0 & 0xffff) - 0x110) * 2 + 0x81a66a0)), iVar2 == 0
     )) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


// sub_080C5C50 @ 0x080C5C50

undefined4 sub_080C5C50(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar4 = 0;
  uVar3 = 0;
  do {
    iVar1 = sub_080C09B0(uVar3 + 4);
    if (iVar1 != 0) {
      uVar4 = uVar4 + 1;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0xc);
  uVar3 = sub_080C104C();
                    /* WARNING: Could not recover jumptable at 0x080c5c7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar4 < uVar3);
  return uVar2;
}


// sub_080C5C7C @ 0x080C5C7C

int sub_080C5C7C(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  do {
    iVar1 = sub_080C09B0(uVar2 + 4);
    if ((iVar1 != 0) &&
       (iVar1 = sub_080C0148(uVar2 + 0x8004 & 0xffff),
       (ushort)(*(short *)(iVar1 + 0x12) - 0x16aU) < 0x12)) {
      iVar3 = iVar3 + 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xc);
  return iVar3;
}


// sub_080C5CC0 @ 0x080C5CC0

int sub_080C5CC0(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  do {
    if ((*(char *)(uVar2 + 0x30050e0) != -1) &&
       (iVar1 = sub_080C0148((int)*(char *)(uVar2 + 0x30050e0) + 0x8000U & 0xffff),
       (ushort)(*(short *)(iVar1 + 0x12) - 0x16aU) < 0x12)) {
      iVar3 = iVar3 + 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 6);
  return iVar3;
}


// sub_080C5D0C @ 0x080C5D0C

uint sub_080C5D0C(void)

{
  ushort local_c;
  ushort local_a;
  
  sub_080C1F50((uint)DAT_03004562,(uint)DAT_03004564,&local_c,&local_a);
  return (uint)*(ushort *)((uint)(local_c >> 2) * 2 + (uint)(local_a >> 2) * 0x40 + 0x81a66b0);
}


// sub_080C5D48 @ 0x080C5D48

int sub_080C5D48(uint arg0)

{
  return (arg0 & 0xffff) * 4 + 0x81a6ab0;
}


// sub_080C5D58 @ 0x080C5D58

uint sub_080C5D58(void)

{
  int iVar1;
  
  iVar1 = sub_08151EB4((uint)DAT_030069f8);
  return (uint)*(byte *)((((uint)(DAT_030069fc >> 4) + (uint)*(ushort *)(iVar1 + 0xcc) & 0xffff) >>
                         3) + (((uint)(DAT_030069fe >> 4) + (uint)*(ushort *)(iVar1 + 0xce) & 0xffff
                               ) >> 3) * 0x10 + 0x81a6cd4);
}


// sub_080C5D98 @ 0x080C5D98

int sub_080C5D98(void)

{
  uint uVar1;
  
  uVar1 = sub_080C5D58();
  return (uVar1 & 0xffff) * 4 + 0x81a6c60;
}


// sub_080C5DB0 @ 0x080C5DB0

void sub_080C5DB0(void)

{
  dword arg0;
  undefined *arg1;
  uint uVar1;
  
  uVar1 = 0;
  arg1 = &DAT_03004ec0;
  arg0 = 0x30046c0;
  do {
    CpuSet(arg0,arg1,0x4000020);
    arg1 = arg1 + 0x80;
    arg0 = arg0 + 0x80;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 4);
  return;
}


// sub_080C5DE0 @ 0x080C5DE0

void sub_080C5DE0(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  dword dVar4;
  uint uVar5;
  
  uVar5 = 0;
  puVar3 = &DAT_030046d0;
  dVar4 = 0x30046c0;
  do {
    puVar3[4] = *(ushort *)(dVar4 + 0x818);
    puVar3[6] = *(ushort *)(dVar4 + 0x81c);
    uVar1 = *puVar3;
    uVar2 = *(ushort *)(dVar4 + 0x810);
    *puVar3 = uVar2;
    if ((uVar1 & 1) != 0) {
      *puVar3 = uVar2 | 1;
    }
    puVar3 = puVar3 + 0x40;
    dVar4 = dVar4 + 0x80;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 4);
  sub_080C6FD8();
  sub_080C2230(0);
  sub_080C23BC(0xdf);
  return;
}


// sub_080C5E44 @ 0x080C5E44

uint sub_080C5E44(uint arg0)

{
  return (uint)*(ushort *)(&DAT_081a6e4a + (arg0 & 0xffff) * 2);
}


// sub_080C5E58 @ 0x080C5E58

dword sub_080C5E58(void)

{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  short sStack_10;
  ushort uStack_e;
  
  sub_080C1F50((uint)DAT_03004562,(uint)DAT_03004564,&sStack_10,&uStack_e);
  uVar1 = 0;
  puVar3 = (uint *)0x81a6f68;
  while ((((short)*puVar3 != sStack_10 || ((*(ushort *)((int)puVar3 + 2) & 0x3f) != uStack_e)) ||
         ((uint)DAT_03004552 != (uVar1 >> 5 & 6) >> 1))) {
    puVar4 = puVar3 + 2;
    uVar1 = *(ushort *)((int)puVar3 + 10);
    puVar3 = puVar4;
    if ((short)*puVar4 == -1) {
      return 0xffff;
    }
  }
  if (((*puVar3 & 0x3fffff) == 0x6002d) && (iVar2 = sub_080C2340(0x15), iVar2 == 0)) {
    return 0xffff;
  }
  return (uint)(ushort)puVar3[1];
}


// sub_080C5EF0 @ 0x080C5EF0

int sub_080C5EF0(uint arg0)

{
  return (arg0 & 0xffff) * 0x5c + 0x8341170;
}


// sub_080C5F04 @ 0x080C5F04

undefined4 sub_080C5F04(uint arg0,uint arg1)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  
  uVar1 = arg1 & 0xffff;
  if (uVar1 < 8) {
    iVar2 = uVar1 * 4 + (arg0 & 0xffff) * 0x5c;
    puVar3 = &DAT_08341174;
  }
  else {
    iVar2 = (uVar1 - 8) * 4 + (arg0 & 0xffff) * 0x5c;
    puVar3 = &DAT_08341194;
  }
  return *(undefined4 *)(puVar3 + iVar2);
}


// sub_080C5F40 @ 0x080C5F40

undefined4 sub_080C5F40(uint arg0,undefined4 arg1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_080C5EF0(arg0 & 0xffff);
  if ((short)arg1 == 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x50);
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x54);
  }
  return uVar2;
}


// sub_080C5F60 @ 0x080C5F60

undefined4 sub_080C5F60(uint arg0)

{
  return *(undefined4 *)(&DAT_083411b8 + (arg0 & 0xffff) * 0x5c);
}


// sub_080C5F78 @ 0x080C5F78

void sub_080C5F78(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x600e400;
  REG_DMA3CNT = 0x84000300;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C5FB4 @ 0x080C5FB4

void sub_080C5FB4(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x822e194,0x2001000,in_r2);
  sub_080C7C60();
  DAT_03000040 = 0x3c40;
  return;
}


// sub_080C5FDC @ 0x080C5FDC

void sub_080C5FDC(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  sub_080AB250(0x822e52c,0x2000000,800,8);
  DisplayList_Add(0x80c5f79,1);
  return;
}


// sub_080C6030 @ 0x080C6030

void sub_080C6030(void)

{
  sub_080ACFCC(3,0x822e174,0x3002ab0,0x20);
  sub_080B04BC();
  sub_080B2840(0,0,0);
  return;
}


// sub_080C6060 @ 0x080C6060

void sub_080C6060(void)

{
  DAT_0300456e = 8;
  return;
}


// sub_080C606C @ 0x080C606C

void sub_080C606C(int arg0)

{
  if (DAT_0300455e == 0) {
    DisplayList_Add(0x80b0159,1);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_0200ab04 = DAT_0200ab04 | 0x8000;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_080C60AC @ 0x080C60AC

void sub_080C60AC(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x85000200;
  uVar1 = REG_DMA3CNT;
  REG_BG1CNT = 0x8209;
  return;
}


// sub_080C60E0 @ 0x080C60E0

void sub_080C60E0(void)

{
  sub_080C1440();
  DAT_0300000e = 0;
  DAT_0300000c = 0;
  DAT_03000006 = 0;
  DAT_03000004 = 0;
  DisplayList_Add(0x80c60ad,1);
  return;
}


// sub_080C6118 @ 0x080C6118

void sub_080C6118(void)

{
  sub_080C7C94();
  return;
}


// sub_080C6124 @ 0x080C6124

void sub_080C6124(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84000600;
  uVar1 = REG_DMA3CNT;
  REG_BG1CNT = 0x8205;
  return;
}


// sub_080C6154 @ 0x080C6154

void sub_080C6154(void)

{
  undefined4 in_r2;
  
  LZ77UnCompWram(0x824d1e4,0x2001000,in_r2);
  LZ77UnCompWram(0x824df94,&DAT_02002000,in_r2);
  DisplayList_Add(0x80c6125,1);
  return;
}


// sub_080C618C @ 0x080C618C

void sub_080C618C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C61B0 @ 0x080C61B0

void sub_080C61B0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C61D4 @ 0x080C61D4

void sub_080C61D4(undefined4 arg0,int arg1)

{
  undefined4 uVar1;
  undefined4 local_c;
  
  local_c = 0;
  REG_DMA3SAD = &local_c;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  if (arg1 == 0) {
    sub_080AB250(0x824e75c,0x2000000,0,8);
    DisplayList_Add(0x80c618d,1);
    DAT_0300000e = 0;
    DAT_03000006 = 0;
  }
  else {
    sub_080AB250(0x824ea9c,0x2000000,0,8);
    DisplayList_Add(0x80c61b1,1);
    DAT_03000040 = 0x3c40;
  }
  return;
}


// sub_080C6278 @ 0x080C6278

undefined4 sub_080C6278(undefined4 arg0)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  piVar2 = (int *)0x2036094;
  while ((iVar1 = *piVar2, iVar1 == 0 || (*(short *)(iVar1 + 0x2a) != (short)arg0))) {
    piVar2 = piVar2 + 1;
    uVar3 = uVar3 + 1;
    if (5 < uVar3) {
      return 0;
    }
  }
  return iVar1;
}


// sub_080C62A8 @ 0x080C62A8

void sub_080C62A8(void)

{
  int iVar1;
  
  sub_080ACFCC(3,0x824eddc,0x3002ab0,0x100);
  iVar1 = sub_080C6278(0xd8);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 0;
  }
  iVar1 = sub_080C6278(0x1bc);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x34) = 1;
  }
  return;
}


// sub_080C62F0 @ 0x080C62F0

void sub_080C62F0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84000b00;
  uVar1 = REG_DMA3CNT;
  REG_BG1CNT = 0x4207;
  REG_BG3CNT = 0x8606;
  sub_080C153C();
  return;
}


// sub_080C6334 @ 0x080C6334

void sub_080C6334(void)

{
  undefined4 in_r2;
  undefined4 uVar1;
  undefined2 local_c [2];
  
  LZ77UnCompWram(0x8245b80,0x2001000,in_r2);
  uVar1 = 0x1000;
  LZ77UnCompWram(0x8245e28,&DAT_02002000,0x1000);
  LZ77UnCompWram(0x824696c,&DAT_02003000,uVar1);
  sub_080C14FC();
  sub_080AB438(0,0x2000000,1,0);
  local_c[0] = 0;
  REG_DMA3SAD = local_c;
  REG_DMA3DAD = 0x3002eb0;
  REG_DMA3CNT = 0x81000080;
  uVar1 = REG_DMA3CNT;
  DAT_0200ab04 = DAT_0200ab04 | 0x8000;
  DisplayList_Add(0x80c62f1,1);
  return;
}


// sub_080C63D0 @ 0x080C63D0

void sub_080C63D0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C63F4 @ 0x080C63F4

void sub_080C63F4(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C6418 @ 0x080C6418

void sub_080C6418(undefined4 arg0,int arg1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined4 local_c;
  
  local_c = 0;
  REG_DMA3SAD = &local_c;
  REG_DMA3DAD = 0x2000000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  if (arg1 == 0) {
    sub_080AB250(0x82483cc,0x2000000,0,8);
    DisplayList_Add(0x80c63d1,1);
    puVar3 = (undefined2 *)0x300000e;
    uVar2 = 0x40;
  }
  else {
    sub_080AB250(0x82473cc,0x2000000,0,8);
    DisplayList_Add(0x80c63f5,1);
    DAT_03000006 = 0x68;
    puVar3 = (undefined2 *)0x3000040;
    uVar2 = 0x3c40;
  }
  *puVar3 = uVar2;
  return;
}


// sub_080C64BC @ 0x080C64BC

void sub_080C64BC(void)

{
  sub_080ACFCC(3,0x82472cc,0x3002ab0,0x100);
  return;
}


// sub_080C64E0 @ 0x080C64E0

void sub_080C64E0(void)

{
  undefined4 uVar1;
  undefined1 auStack_4 [4];
  
  REG_DMA3SAD = auStack_4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x85000400;
  uVar1 = REG_DMA3CNT;
  REG_BG1CNT = 0x8209;
  REG_BG3CNT = 0x8607;
  return;
}


// sub_080C6520 @ 0x080C6520

void sub_080C6520(void)

{
  sub_080C1440();
  DisplayList_Add(0x80c64e1,1);
  DAT_03000006 = 0;
  DAT_03000004 = 0;
  DAT_0300000e = 0;
  DAT_0300000c = 0;
  return;
}


// sub_080C6558 @ 0x080C6558

void sub_080C6558(void)

{
  int iVar1;
  
  iVar1 = sub_080C2340(0xc6);
  if ((iVar1 == 0) && (DAT_030020e4 != 0x80d977d)) {
    sub_080AB250(0x81b90b0,0x200dfd4,0,0);
  }
  return;
}


// sub_080C65A4 @ 0x080C65A4

void sub_080C65A4(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x81a7db8;
  REG_DMA3DAD = 0x6011500;
  REG_DMA3CNT = 0x84000100;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C65C8 @ 0x080C65C8

void sub_080C65C8(void)

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


// sub_080C65E8 @ 0x080C65E8

void sub_080C65E8(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 local_24 [2];
  undefined4 local_20;
  
  REG_DMA3SAD = local_24;
  REG_DMA3DAD = 0x200e7d4;
  REG_DMA3CNT = 0x8100003a;
  uVar1 = REG_DMA3CNT;
  DAT_0200e7ec = 8;
  DAT_0200e7dc = 3;
  DAT_0200e7f0 = 7;
  DAT_0200e7e0 = 3;
  DAT_0200e7f2 = 7;
  DAT_0200e7e2 = 3;
  DAT_0200e7e6 = 9;
  DAT_0200e7d6 = 3;
  local_24[0] = 0;
  REG_DMA3SAD = local_24;
  REG_DMA3DAD = 0x200dfd4;
  REG_DMA3CNT = 0x81000400;
  uVar1 = REG_DMA3CNT;
  iVar2 = sub_080C8AF8();
  if (iVar2 == 1) {
    sub_080AB250(0x81b8270,0x200dfd4,0,0);
    if (DAT_03005180 == 1) {
      DAT_0200e7e8 = 3;
      DAT_0200e7d8 = 3;
    }
    else {
      sub_080AB250(0x81b92b0,0x200dfd4,0,0);
    }
    sub_080AB250(0x81b8170,0x200dfd4,0,0);
    sub_080C6558();
  }
  else {
    DAT_0200e7e4 = 9;
    DAT_0200e7d4 = 3;
    DAT_0200e7e8 = 3;
    DAT_0200e7d8 = 3;
    DAT_0200e7ea = 9;
    DAT_0200e7da = 3;
    DAT_0200e804 = 1;
  }
  sub_080C65A4();
  sub_080C7EFC();
  Party_BuildMemberNameTiles();
  sub_080C6FD8();
  local_20 = 0;
  REG_DMA3SAD = &local_20;
  REG_DMA3DAD = 0x200e8d8;
  REG_DMA3CNT = 0x850003c0;
  uVar1 = REG_DMA3CNT;
  sub_080C8440();
  sub_080C65C8();
  return;
}


// sub_080C6734 @ 0x080C6734

void sub_080C6734(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200dfd4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x80000400;
  uVar1 = REG_DMA3CNT;
  DAT_0200e840 = 0;
  return;
}


// sub_080C6764 @ 0x080C6764

void sub_080C6764(void)

{
  if ((DAT_030020e4 != 0x80d977d) && (DAT_0200e840 == 0)) {
    DisplayList_Add(0x80c6735,1);
    DAT_0200e840 = 1;
  }
  return;
}


// sub_080C67A0 @ 0x080C67A0

void sub_080C67A0(void)

{
  uint uVar1;
  
  uVar1 = sub_080C21D0();
  DAT_0200e80c = *(undefined2 *)((uVar1 & 0xffff) * 2 + 0x834a230);
  return;
}


// sub_080C67C0 @ 0x080C67C0

void sub_080C67C0(int arg0,uint arg1)

{
  uint uVar1;
  
  uVar1 = sub_080C21D0();
  sub_080C7EB4(*(ushort *)((uVar1 & 0xffff) * 2 + 0x834a224) + 0x81b7030,
               (arg1 & 0xfff) * 0x20 + arg0 + 0x21e);
  sub_080C67A0();
  return;
}


// sub_080C6804 @ 0x080C6804

void sub_080C6804(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (DAT_0200e80a == 1) {
    return;
  }
  if (DAT_03004550 == 1) {
    sub_080C700C();
    sub_080C7234();
    sub_080C7430();
  }
  else if (DAT_03004550 == 0x19) {
    sub_080C6FF0();
    sub_080C7218();
    sub_080C7414();
  }
  sub_080C726C();
  sub_080C7880();
  sub_080C7AFC();
  sub_080C71EC();
  if ((DAT_030031bc & 0xf) == 0) {
    DAT_030050e7 = DAT_030050e7 + 1 & 7;
    DisplayList_Add(0x80c7efd,1);
  }
  sub_080C745C();
  sub_080C76B4();
  iVar2 = sub_080C2340(0xc6);
  if ((iVar2 == 0) && (DAT_030020e4 != 0x80d977d)) {
    if (DAT_0200e804 == 0) {
      sub_080AA184(0x80005dc,1,0,1);
    }
    uVar1 = DAT_0200e808;
    if (((DAT_0200e80c == 0) || (DAT_0200e80c = DAT_0200e80c + -1, DAT_0200e80c == 0)) &&
       (DAT_0200e808 == 0)) {
      sub_080C67C0(0x3002db0,7);
      uVar3 = sub_080C7E90();
      DAT_0200e806 = DAT_0200e806 + 1;
      if ((uint)DAT_0200e806 == (uVar3 & 0xffff)) {
        DAT_0200e806 = uVar1;
      }
      sub_080AABB0();
    }
  }
  DAT_0200f7f0 = 0;
  DAT_0200e846 = DAT_0200e846 + 1;
  if (5 < DAT_0200e846) {
    DAT_0200e846 = 0;
  }
  switch(DAT_0200e846) {
  case 0:
    sub_080C6BE0(0,0xc,0x6b);
    sub_080C6BE0(1,0x59,0x6b);
    sub_080C6BE0(2,0xa6,0x6b);
    sub_080C6BE0(3,0xc,0x87);
    sub_080C6BE0(4,0x59,0x87);
    uVar4 = 5;
    uVar5 = 0xa6;
    goto LAB_080c6a74;
  case 1:
    sub_080C6BE0(1,0x59,0x6b);
    sub_080C6BE0(2,0xa6,0x6b);
    sub_080C6BE0(3,0xc,0x87);
    sub_080C6BE0(4,0x59,0x87);
    sub_080C6BE0(5,0xa6,0x87);
    uVar4 = 0;
    uVar5 = 0xc;
    break;
  case 2:
    sub_080C6BE0(2,0xa6,0x6b);
    sub_080C6BE0(3,0xc,0x87);
    sub_080C6BE0(4,0x59,0x87);
    sub_080C6BE0(5,0xa6,0x87);
    sub_080C6BE0(0,0xc,0x6b);
    uVar4 = 1;
    uVar5 = 0x59;
    break;
  case 3:
    sub_080C6BE0(3,0xc,0x87);
    sub_080C6BE0(4,0x59,0x87);
    sub_080C6BE0(5,0xa6,0x87);
    sub_080C6BE0(0,0xc,0x6b);
    sub_080C6BE0(1,0x59,0x6b);
    uVar4 = 2;
    uVar5 = 0xa6;
    break;
  case 4:
    sub_080C6BE0(4,0x59,0x87);
    sub_080C6BE0(5,0xa6,0x87);
    sub_080C6BE0(0,0xc,0x6b);
    sub_080C6BE0(1,0x59,0x6b);
    sub_080C6BE0(2,0xa6,0x6b);
    uVar4 = 3;
    uVar5 = 0xc;
LAB_080c6a74:
    sub_080C6BE0(uVar4,uVar5,0x87);
    goto switchD_080c6912_default;
  case 5:
    sub_080C6BE0(5,0xa6,0x87);
    sub_080C6BE0(0,0xc,0x6b);
    sub_080C6BE0(1,0x59,0x6b);
    sub_080C6BE0(2,0xa6,0x6b);
    sub_080C6BE0(3,0xc,0x87);
    sub_080C6BE0(4,0x59,0x87);
  default:
    goto switchD_080c6912_default;
  }
  sub_080C6BE0(uVar4,uVar5,0x6b);
switchD_080c6912_default:
  if (DAT_0200f7f0 == 1) {
    DisplayList_Add(0x80c8441,1);
  }
  return;
}


// sub_080C6AD8 @ 0x080C6AD8

void sub_080C6AD8(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  int iVar1;
  
  iVar1 = sub_080C6FB8(arg0 & 0xffff);
  sub_080AA184(*(undefined4 *)((arg0 & 0xffff) * 4 + 0x834a254),arg1 & 0xffff,iVar1 - 1U & 0xffff,
               arg2 & 0xffff);
  return;
}


// sub_080C6B40 @ 0x080C6B40

void sub_080C6B40(uint arg0,uint arg1,uint arg2,uint arg3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  cVar1 = DAT_030050e0;
  while ((uVar3 = uVar2, (int)cVar1 != (arg0 & 0xf) && (uVar3 = uVar2 + 1, uVar3 < 6))) {
    cVar1 = (&DAT_030050e1)[uVar2];
    uVar2 = uVar3;
  }
  if (uVar3 != 6) {
    sub_080C6AD8(uVar3 & 0xffff,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  }
  return;
}


// sub_080C6BA8 @ 0x080C6BA8

undefined4 sub_080C6BA8(void)

{
  short *psVar1;
  dword dVar2;
  
  psVar1 = (short *)0x2009004;
  dVar2 = 0x2009004;
  while ((*psVar1 == 0 || (*(dword *)(psVar1 + 0x10) != 0x80d2f61))) {
    psVar1 = psVar1 + 0x32;
    dVar2 = dVar2 + 100;
    if ((short *)0x200a8a0 < psVar1) {
      return 0;
    }
  }
  return dVar2;
}


// sub_080C6BE0 @ 0x080C6BE0

void sub_080C6BE0(uint arg0,undefined4 arg1,undefined4 arg2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint arg0_00;
  ushort *puVar4;
  short *psVar5;
  uint uVar6;
  
  arg0_00 = arg0 & 0xffff;
  psVar5 = (short *)(arg0_00 * 2 + 0x200e81c);
  puVar4 = (ushort *)(&DAT_0200e828 + arg0_00 * 2);
  if ((&DAT_0200e810)[arg0_00] != 1) {
    if ((&DAT_030050e0)[arg0_00] == -1) {
      sub_080AA184(0x800082c,7,0,1);
      *psVar5 = 0;
    }
    else {
      iVar2 = sub_080C0148(arg0_00);
      uVar6 = 0;
      if (*psVar5 != 0) {
        if ((DAT_030031bc & 3) == 0) {
          *puVar4 = -*puVar4;
          sVar1 = *psVar5;
          *psVar5 = sVar1 + -1;
          if ((short)(sVar1 + -1) == 0) {
            *puVar4 = 0;
          }
        }
        uVar6 = (uint)*puVar4;
      }
      if ((DAT_0200e812 != 1) || (iVar3 = sub_080C6BA8(), iVar3 == 0)) {
        sub_080AA184(*(undefined4 *)(arg0_00 * 4 + 0x834a23c),7,0,1);
      }
      if ((DAT_0200e812 != 1) || (arg0_00 != 2)) {
        sub_080C6AD8(arg0_00,7,1,(uint)*(ushort *)(arg0_00 * 4 + 0x834a28c));
      }
      if ((DAT_0200e812 != 1) || (((arg0_00 != 0 && (arg0_00 != 3)) && (arg0_00 != 4)))) {
        sub_080C8214(arg0_00,0,(uint)*(ushort *)(arg0_00 * 4 + 0x834a2bc),
                     uVar6 + *(ushort *)(&DAT_0834a2be + arg0_00 * 4) & 0xffff);
      }
      if (*(short *)(iVar2 + 0x1e) != 0) {
        sub_080C8214(arg0_00,1,(uint)*(ushort *)(arg0_00 * 4 + 0x834a2d4),
                     uVar6 + *(ushort *)(&DAT_0834a2d6 + arg0_00 * 4) & 0xffff);
      }
      if ((DAT_0200e812 != 1) || ((arg0_00 != 0 && (arg0_00 != 2)))) {
        if (*(short *)(iVar2 + 0x1e) == 0) {
          sub_080AA1F4(0x834a26c,7,0,1);
        }
        else {
          sub_080AA184(0x80005ec,7,0,1);
        }
      }
    }
  }
  return;
}


// sub_080C6E30 @ 0x080C6E30

void sub_080C6E30(undefined4 arg0)

{
  DAT_0200e810 = (undefined2)arg0;
  DAT_0200e812 = (undefined2)arg0;
  DAT_0200e814 = (undefined2)arg0;
  DAT_0200e816 = (undefined2)arg0;
  DAT_0200e818 = (undefined2)arg0;
  DAT_0200e81a = (undefined2)arg0;
  return;
}


// sub_080C6E54 @ 0x080C6E54

void sub_080C6E54(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x20399e4;
  REG_DMA3DAD = 0x6010c00;
  REG_DMA3CNT = 0x84000180;
  uVar1 = REG_DMA3CNT;
  return;
}


// Party_BuildMemberNameTiles @ 0x080C6E78

void Party_BuildMemberNameTiles(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar4 = 0;
  do {
    iVar1 = sub_080C0148(uVar4 & 0xffff);
    uVar6 = uVar4 + 1;
    if (iVar1 != 0) {
      puVar3 = (undefined4 *)(uVar4 * 0x100 + 0x20399e4);
      iVar5 = 0;
      do {
        if (*(byte *)(iVar1 + iVar5) == 0xff) {
          *puVar3 = 0;
          puVar3[1] = 0;
          puVar3[2] = 0;
          puVar3[3] = 0;
          puVar3[4] = 0;
          puVar3[5] = 0;
          puVar3[6] = 0;
          puVar3[7] = 0;
        }
        else {
          iVar2 = (uint)*(byte *)(iVar1 + iVar5) * 0x20;
          *puVar3 = *(undefined4 *)(iVar2 + 0x81af7b8);
          puVar3[1] = *(undefined4 *)(&DAT_081af7bc + iVar2);
          puVar3[2] = *(undefined4 *)(&DAT_081af7c0 + iVar2);
          puVar3[3] = *(undefined4 *)(&DAT_081af7c4 + iVar2);
          puVar3[4] = *(undefined4 *)(&DAT_081af7c8 + iVar2);
          puVar3[5] = *(undefined4 *)(&DAT_081af7cc + iVar2);
          puVar3[6] = *(undefined4 *)(&DAT_081af7d0 + iVar2);
          puVar3[7] = *(undefined4 *)(&DAT_081af7d4 + iVar2);
        }
        puVar3 = puVar3 + 8;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
    }
    uVar4 = uVar6;
  } while ((int)uVar6 < 6);
  DisplayList_Add(0x80c6e55,1);
  return;
}


// sub_080C6F00 @ 0x080C6F00

void sub_080C6F00(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2039fe4;
  REG_DMA3DAD = 0x6011200;
  REG_DMA3CNT = 0x840000c0;
  uVar1 = REG_DMA3CNT;
  DAT_0200e842 = 0;
  return;
}


// sub_080C6F30 @ 0x080C6F30

void sub_080C6F30(undefined4 arg0)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar1 = sub_080C0148((uint)(ushort)arg0);
  if (iVar1 != 0) {
    puVar3 = (undefined4 *)((uint)(ushort)arg0 * 0x80 + 0x2039fe4);
    iVar1 = sub_080C86B4((int)(short)(ushort)arg0);
    puVar4 = (undefined4 *)(*(int *)(((iVar1 << 0x10) >> 0xd) + 0x834a2ec) * 4 + 0x81a81b8);
    uVar2 = 0;
    do {
      *puVar3 = *puVar4;
      puVar3[1] = puVar4[1];
      puVar3[2] = puVar4[2];
      puVar3[3] = puVar4[3];
      puVar3[4] = puVar4[4];
      puVar3[5] = puVar4[5];
      puVar5 = puVar4 + 7;
      puVar3[6] = puVar4[6];
      puVar4 = puVar4 + 8;
      puVar3[7] = *puVar5;
      puVar3 = puVar3 + 8;
      uVar2 = uVar2 + 1;
    } while (uVar2 < 4);
    if (DAT_0200e842 == 0) {
      DisplayList_Add(0x80c6f01,1);
      DAT_0200e842 = 1;
    }
  }
  return;
}


// sub_080C6FB8 @ 0x080C6FB8

undefined4 sub_080C6FB8(undefined4 arg0)

{
  int iVar1;
  
  iVar1 = sub_080C86B4((int)(short)arg0);
  return *(undefined4 *)(&DAT_0834a2f0 + ((iVar1 << 0x10) >> 0xd));
}


