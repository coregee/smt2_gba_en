/* Ghidra decompilation of asm/code_080C9100.s (reference only; not compiled). */

// sub_080C9100 @ 0x080C9100

undefined4 sub_080C9100(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C1D9C();
  uVar1 = uVar1 & 0xf0;
  if (0x8f < uVar1) {
    uVar1 = 0x80 - (uVar1 + 0x80 & 0xff) & 0xff;
  }
  iVar2 = sub_080C2340(0xd8);
  if (iVar2 == 0) {
    iVar2 = sub_080C2340(0xc4);
    if (iVar2 == 0) {
      sub_080C2364(0xc4);
      uVar3 = sub_080C2244();
      if ((uVar3 & 0xff) < 0x80) {
        uVar3 = sub_080C2244();
        if ((uVar3 & 0xff) < 0x80) {
          uVar3 = sub_080C2244();
          if ((uVar3 & 0xff) < 0x80) {
            if (uVar1 != 0x70) goto LAB_080c91ac;
          }
          else if (uVar1 != 0x60) goto LAB_080c91ac;
        }
        else {
          uVar3 = sub_080C2244();
          if (0x7f < (uVar3 & 0xff)) goto LAB_080c918c;
          if (uVar1 != 0x50) goto LAB_080c91ac;
        }
      }
      else {
        uVar3 = sub_080C2244();
        if ((uVar3 & 0xff) < 0x80) {
          uVar3 = sub_080C2244();
          if ((uVar3 & 0xff) < 0x80) {
            if (uVar1 != 0x30) goto LAB_080c91ac;
          }
          else if (uVar1 != 0x20) {
LAB_080c91ac:
            uVar1 = sub_080C2244();
            if ((uVar1 & 0xff) < 0x20) goto LAB_080c91b8;
          }
        }
        else {
          uVar3 = sub_080C2244();
          if ((uVar3 & 0xff) < 0x80) {
            if (uVar1 != 0x10) goto LAB_080c91ac;
          }
          else {
LAB_080c918c:
            if (uVar1 != 0) goto LAB_080c91ac;
          }
        }
      }
    }
  }
  else {
LAB_080c91b8:
    uVar1 = sub_080C2244();
    if (0x7f < (uVar1 & 0xff)) {
      uVar1 = sub_080C2244();
      if ((uVar1 & 0xff) < 0x80) {
        uVar1 = sub_080C2244();
        if ((uVar1 & 0xff) < 0x80) {
          uVar4 = 0x33;
        }
        else {
          uVar4 = 0x32;
        }
      }
      else {
        uVar1 = sub_080C2244();
        if ((uVar1 & 0xff) < 0x80) {
          uVar4 = 0x31;
        }
        else {
          uVar4 = 0x34;
        }
      }
      goto LAB_080c9208;
    }
    iVar2 = sub_080C2340(0xd8);
    if ((iVar2 != 0) || (uVar1 = sub_080C2244(), 0x3f < (uVar1 & 0xff))) {
      uVar4 = 0x30;
      goto LAB_080c9208;
    }
  }
  uVar4 = 0;
LAB_080c9208:
                    /* WARNING: Could not recover jumptable at 0x080c920c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar4);
  return uVar4;
}


// sub_080C9210 @ 0x080C9210

dword sub_080C9210(undefined4 arg0)

{
  dword dVar1;
  
  if ((short)arg0 == 1) {
    dVar1 = 0x84eeae4;
  }
  else if ((short)arg0 == 2) {
    dVar1 = 0x84eef28;
  }
  else if ((short)arg0 == 3) {
    dVar1 = 0x84ef368;
  }
  else {
    dVar1 = 0x84ef7b0;
  }
  return dVar1;
}


// sub_080C9248 @ 0x080C9248

void sub_080C9248(uint arg0,undefined4 arg1)

{
  short *psVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  for (psVar1 = (short *)sub_080C9210(arg0 & 0xffff); *psVar1 != -1; psVar1 = psVar1 + 2) {
    if (*psVar1 == (short)arg1) goto LAB_080c9270;
  }
  psVar1 = (short *)0x0;
LAB_080c9270:
                    /* WARNING: Could not recover jumptable at 0x080c9274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(psVar1);
  return;
}


// sub_080C9278 @ 0x080C9278

uint sub_080C9278(uint arg0)

{
  return *(ushort *)((arg0 & 0xffff) * 2 + 0x203b554) & 0x7fff;
}


// sub_080C9290 @ 0x080C9290

uint sub_080C9290(uint arg0)

{
  return *(ushort *)((arg0 & 0xffff) * 2 + 0x203b554) & 0x8000;
}


// sub_080C92AC @ 0x080C92AC

uint sub_080C92AC(int arg0)

{
  return (uint)(arg0 * 0x10000 + 0xfeb00000U >> 0x10 < 0x1a);
}


// sub_080C92C8 @ 0x080C92C8

undefined * sub_080C92C8(uint arg0)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  
  uVar1 = sub_080C9290(arg0 & 0xffff);
  if ((uVar1 & 0xffff) == 0) {
    uVar1 = sub_080C9278(arg0 & 0xffff);
    puVar2 = (undefined *)((uVar1 & 0xffff) * 0x80 + 0x30046c0);
  }
  else {
    puVar2 = &DAT_0203a4a8;
    uVar1 = sub_080C9278((uint)DAT_0203a456);
    sub_080C0444(&DAT_0203a4a8,4,uVar1 & 0xffff);
    iVar3 = sub_080C92AC((uint)DAT_0203a4ba);
    if (iVar3 == 1) {
      uVar1 = sub_08154968((uint)DAT_0203a4ba);
      sub_080BF468(uVar1 & 0xffff,5,&local_18);
      DAT_0203a4e8 = local_18;
      DAT_0203a4e9 = local_17;
      DAT_0203a4ea = local_16;
      DAT_0203a4eb = local_15;
      DAT_0203a4ec = local_14;
      DAT_0203a4ed = local_13;
      DAT_0203a4d0 = 0;
      DAT_0203a4d1 = 0;
      DAT_0203a4d2 = 0;
      DAT_0203a4d3 = 0;
      DAT_0203a4d4 = 0;
      DAT_0203a4d5 = 0;
    }
  }
  return puVar2;
}


// sub_080C9388 @ 0x080C9388

undefined4 sub_080C9388(uint arg0)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = sub_080C9290(arg0 & 0xffff);
  if (((uVar1 & 0xffff) == 0) && (uVar1 = sub_080C9278(arg0 & 0xffff), (uVar1 & 0xffff) < 4)) {
    uVar2 = 1;
  }
  return uVar2;
}


// sub_080C93B4 @ 0x080C93B4

undefined4 sub_080C93B4(uint arg0)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = sub_080C9290(arg0 & 0xffff);
  if (((uVar1 & 0xffff) == 0) && (uVar1 = sub_080C9278(arg0 & 0xffff), (uVar1 & 0xffff) == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}


// sub_080C93E0 @ 0x080C93E0

void sub_080C93E0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6014000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C9404 @ 0x080C9404

void sub_080C9404(void)

{
  Font_ResetGlyphSpriteCache(0x180);
  return;
}


// sub_080C9414 @ 0x080C9414

void sub_080C9414(void)

{
  int arg0;
  
  if (DAT_0203a454 == 5) {
    arg0 = sub_080C92C8((uint)DAT_0203a456);
    CpuSet(arg0,&DAT_0203a4a8,0x4000020);
    *(undefined1 *)(arg0 + 0x20) = 0xff;
    *(undefined1 *)(arg0 + 0x21) = 0xff;
    *(undefined1 *)(arg0 + 0x22) = 0xff;
    *(undefined1 *)(arg0 + 0x23) = 0xff;
    *(undefined1 *)(arg0 + 0x24) = 0xff;
    *(undefined1 *)(arg0 + 0x25) = 0xff;
    *(undefined1 *)(arg0 + 0x26) = 0xff;
    *(undefined1 *)(arg0 + 0x27) = 0xff;
    sub_080BF938((uint)*(byte *)(arg0 + 0xc));
    CpuSet(arg0,&DAT_0203a5a8,0x4000020);
  }
  return;
}


// sub_080C947C @ 0x080C947C

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080C947C(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 in_r2;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  sVar1 = 0;
  LZ77UnCompWram(0x81b5870,0x200f874,in_r2);
  DisplayList_Add(0x80c93e1,1);
  switch(DAT_0203a454) {
  case 0:
    uVar5 = 0;
    do {
      if ((&DAT_030046ce)[uVar5 * 0x40] != 0) {
        *(short *)(uVar4 * 2 + 0x203b554) = (short)uVar5;
        uVar4 = uVar4 + 1 & 0xffff;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 0x10);
    DAT_0203a478._0_2_ = (undefined2)uVar4;
    break;
  case 1:
    uVar5 = 0;
    while ((uVar5 < 0x100 && (uVar2 = sub_0812ACCC(uVar5), (uVar2 & 0xffff) != 0xffff))) {
      iVar3 = sub_080C2340(0xb6);
      if (iVar3 == 0) {
        if ((uVar2 & 0x8000) == 0) {
LAB_080c9548:
          *(ushort *)(uVar4 * 2 + 0x203b554) = (ushort)uVar2 + 0x8000;
          uVar4 = uVar4 + 1 & 0xffff;
          sVar1 = sVar1 + 1;
        }
      }
      else {
        if ((uVar2 & 0x8000) == 0) goto LAB_080c9548;
        *(ushort *)(uVar4 * 2 + 0x203b554) = (ushort)uVar2 | 0x8000;
        uVar4 = uVar4 + 1 & 0xffff;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    }
    DAT_0203a478._0_2_ = (undefined2)uVar4;
    DAT_0203a478._2_2_ = sVar1;
    break;
  case 3:
    uVar5 = 0;
    do {
      if ((&DAT_030046ce)[uVar5 * 0x40] != 0) {
        *(short *)(uVar4 * 2 + 0x203b554) = (short)uVar5;
        uVar4 = uVar4 + 1 & 0xffff;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 4);
    DAT_0203a478._0_2_ = (undefined2)uVar4;
    break;
  case 4:
  case 5:
    CpuSet((uint)DAT_0203a456 * 0x80 + 0x30046c0,&DAT_0203a528,0x4000020);
    DAT_0203b554 = DAT_0203a456;
    DAT_0203a478._0_2_ = 1;
    DAT_0203a456 = 0;
    sub_080C9414();
    break;
  case 6:
    DAT_0203a456 = DAT_0203b85a;
    goto LAB_080c961a;
  case 8:
  case 9:
  case 10:
LAB_080c961a:
    DAT_0203b554 = DAT_0203a456 + 0x8000;
    DAT_0203a478._0_2_ = 1;
    DAT_0203a456 = 0;
  }
  _DAT_0203a464 = 0;
  iVar3 = sub_080C9388((uint)DAT_0203a456);
  DAT_0203a46a = (ushort)(iVar3 == 1);
  _DAT_0203a46c = 1;
  _DAT_0203a470 = 0;
  DAT_0203a472 = 0;
  return;
}


// sub_080C964C @ 0x080C964C

undefined4 sub_080C964C(undefined4 arg0)

{
  undefined2 uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = (undefined2)DAT_0203a478;
  if (((short)arg0 != 0) && (uVar1 = DAT_0203a478._2_2_, DAT_0203a454 != 1)) {
    uVar1 = (undefined2)DAT_0203a478;
  }
                    /* WARNING: Could not recover jumptable at 0x080c966e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar2;
}


// sub_080C9670 @ 0x080C9670

void sub_080C9670(void)

{
  sub_0812CC70(0);
  return;
}


// sub_080C967C @ 0x080C967C

void sub_080C967C(void)

{
  sub_08128B84(1);
  return;
}


// sub_080C9688 @ 0x080C9688

void sub_080C9688(void)

{
  sub_08128B84(2);
  return;
}


// sub_080C9694 @ 0x080C9694

void sub_080C9694(void)

{
  return;
}


// sub_080C9698 @ 0x080C9698

void sub_080C9698(void)

{
  Field_SetState(0x19);
  return;
}


// sub_080C96A4 @ 0x080C96A4

void sub_080C96A4(void)

{
  return;
}


// sub_080C96A8 @ 0x080C96A8

void sub_080C96A8(void)

{
  dword arg0;
  
  switch(DAT_0203a454) {
  case 0:
    arg0 = 0x80c9671;
    break;
  case 1:
    arg0 = 0x80c9689;
    break;
  default:
    goto switchD_080c96ba_caseD_2;
  case 3:
    arg0 = 0x80c967d;
    break;
  case 4:
    arg0 = 0x80ea179;
    break;
  case 5:
    arg0 = 0x80c9695;
    break;
  case 6:
    arg0 = 0x80c9699;
    break;
  case 8:
  case 9:
  case 10:
    arg0 = 0x80c9699;
    break;
  case 0xb:
  case 0xc:
    arg0 = 0x80c96a5;
  }
  DAT_0203a48c = sub_080B6B58(arg0,0);
switchD_080c96ba_caseD_2:
  return;
}


// sub_080C9744 @ 0x080C9744

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080C9744(int arg0)

{
  int iVar1;
  
  sub_080C92C8((uint)DAT_0203a456);
  if (*(int *)(DAT_0203a48c + 0xc) == -1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    iVar1 = sub_080C9388((uint)DAT_0203a456);
    if (iVar1 != 1) {
      _DAT_03002f50 = 0x10;
      DAT_03002f52 = 0x10;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_080C9794 @ 0x080C9794

void sub_080C9794(void)

{
  *(undefined4 *)(DAT_0203a48c + 0xc) = 1;
  return;
}


// sub_080C97A4 @ 0x080C97A4

void sub_080C97A4(undefined4 *arg0,undefined4 *arg1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = *arg0;
    arg0 = arg0 + 1;
    *arg1 = uVar1;
    arg1 = arg1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x18);
  return;
}


// sub_080C97B8 @ 0x080C97B8

void sub_080C97B8(int arg0)

{
  sub_080C97A4(arg0 * 0x60 + 0x81b4f10,0x200fc74);
  sub_080C97A4(&UNK_081b5310 + arg0 * 0x60,&DAT_02010074);
  return;
}


// sub_080C97F0 @ 0x080C97F0

void sub_080C97F0(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  if ((DAT_0203a476 != 1) && (iVar1 = sub_080C964C(1), iVar1 != 1)) {
    sub_080C97B8(arg1);
    sub_080C9994();
  }
  return;
}


// sub_080C981C @ 0x080C981C

void sub_080C981C(int arg0)

{
  sub_080C97A4(arg0 * 0x60 + 0x81b4fd0,0x200ffd4);
  sub_080C97A4(&UNK_081b53d0 + arg0 * 0x60,&DAT_020103d4);
  return;
}


// sub_080C9854 @ 0x080C9854

void sub_080C9854(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  if ((DAT_0203a476 != 1) && (iVar1 = sub_080C964C(1), iVar1 != 1)) {
    sub_080C981C(arg1);
    sub_080C9994();
  }
  return;
}


// sub_080C9880 @ 0x080C9880

void sub_080C9880(uint arg0)

{
  ushort *puVar1;
  
  puVar1 = (ushort *)((arg0 & 0xffff) * 2 + 0x6001000);
  *puVar1 = *puVar1 & 0xfff | 0x1000;
  return;
}


// sub_080C98A0 @ 0x080C98A0

void sub_080C98A0(void)

{
  ushort uVar1;
  
  uVar1 = REG_BG2CNT;
  REG_BG2CNT = uVar1 & 0x3fff;
  uVar1 = REG_BG2CNT;
  REG_BG2CNT = uVar1 | 0x4000;
  REG_BG1CNT = 0x4205;
  DAT_03000040 = 0x3844;
  return;
}


// sub_080C98E0 @ 0x080C98E0

void sub_080C98E0(void)

{
  undefined4 uVar1;
  undefined4 local_10;
  
  sub_080C98A0();
  REG_DMA3SAD = 0x81b93b0;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  local_10 = 0;
  REG_DMA3SAD = &local_10;
  REG_DMA3DAD = 0x6001800;
  REG_DMA3CNT = 0x85000200;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x200f874;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84001f00;
  uVar1 = REG_DMA3CNT;
  sub_080C9880(0);
  sub_080C9880(1);
  sub_080C9880(2);
  sub_080C9880(0x20);
  sub_080C9880(0x21);
  sub_080C9880(0x22);
  sub_080C9880(0x1b);
  sub_080C9880(0x1c);
  sub_080C9880(0x1d);
  sub_080C9880(0x3b);
  sub_080C9880(0x3c);
  sub_080C9880(0x3d);
  DAT_0203a460._0_2_ = 0;
  return;
}


// sub_080C9994 @ 0x080C9994

void sub_080C9994(void)

{
  if ((short)DAT_0203a460 == 0) {
    DisplayList_Add(0x80c98e1,1);
    DAT_0203a460._0_2_ = 1;
  }
  return;
}


// sub_080C99B8 @ 0x080C99B8

undefined4 sub_080C99B8(undefined4 arg0)

{
  return 0;
}


// Status_DrawDemonInfo @ 0x080C99C4

void Status_DrawDemonInfo(void)

{
  int arg0;
  char *pcVar1;
  undefined4 arg0_00;
  int iVar2;
  uint uVar3;
  dword dVar4;
  ushort *puVar5;
  uint uVar6;
  ushort local_48 [16];
  undefined4 local_28;
  undefined4 local_24;
  
  arg0 = sub_080C92C8((uint)DAT_0203a456);
  pcVar1 = (char *)sub_080BF648((uint)*(ushort *)(arg0 + 0x12));
  arg0_00 = Race_GetName((int)*pcVar1 & 0xffff);
  local_28 = 0;
  CpuSet(&local_28,0x200f874,0x5002000);
  local_24 = 0;
  CpuSet(&local_24,local_48,0x5000008);
  iVar2 = sub_080C9388((uint)DAT_0203a456);
  if (iVar2 == 0) {
    uVar3 = sub_08154968((uint)*(ushort *)(arg0 + 0x12));
    uVar3 = uVar3 & 0xffff;
    if (uVar3 == 0x6f) {
      Font_DrawGlyphTinted(0x923,0x200f874,0x18,8);
      Font_DrawGlyphTinted(0xc5c,0x200f874,0x24,8);
      dVar4 = 0xa7b;
    }
    else {
      if (uVar3 == 0x93) {
        dVar4 = 0xdb4;
      }
      else if (uVar3 == 0xa7) {
        dVar4 = 0xdc1;
      }
      else if (uVar3 == 0xbb) {
        dVar4 = 0x112d;
      }
      else {
        if (uVar3 != 0xcf) {
          Text_DrawStringTinted(arg0_00,0x200f874,0x18,8);
          goto LAB_080c9ae4;
        }
        dVar4 = 0x794;
      }
      Font_DrawGlyphTinted(dVar4,0x200f874,0x18,8);
      Font_DrawGlyphTinted(0xfa9,0x200f874,0x24,8);
      dVar4 = 0x811;
    }
    Font_DrawGlyphTinted(dVar4,0x200f874,0x30,8);
  }
LAB_080c9ae4:
  iVar2 = sub_080C92AC((uint)*(ushort *)(arg0 + 0x12));
  if (iVar2 != 1) {
    iVar2 = sub_080C99B8(arg0);
    if (iVar2 == 1) {
      sub_080CCEC8(0x84efad4,0x54,10,0);
      sub_080CCEC8(0x84efad8,100,10,4);
    }
    else {
      sub_080CCEC8(0x84efad4,0x54,10,0);
      if (*(byte *)(arg0 + 0xd) < 10) {
        sub_080CCFC4((uint)*(byte *)(arg0 + 0xd),100,10,4);
      }
      else {
        sub_080CCFC4((uint)*(byte *)(arg0 + 0xd),0x6c,10,4);
      }
    }
  }
  if (*(byte *)(arg0 + 0xc) < 4) {
    Combatant_DecodeName(arg0,local_48);
    uVar6 = 0;
    uVar3 = 0x780000;
    puVar5 = local_48;
    do {
      Font_DrawGlyphTinted((uint)*puVar5,0x200f874,uVar3 >> 0x10,8);
      uVar3 = uVar3 + 0xc0000;
      puVar5 = puVar5 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 8);
  }
  else {
    uVar6 = 0;
    uVar3 = 0x780000;
    puVar5 = (ushort *)(pcVar1 + 0x22);
    do {
      Font_DrawGlyphTinted((uint)*puVar5,0x200f874,uVar3 >> 0x10,8);
      uVar3 = uVar3 + 0xc0000;
      puVar5 = puVar5 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 8);
  }
  return;
}


// sub_080C9BCC @ 0x080C9BCC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080C9BCC(undefined4 arg0)

{
  _DAT_0203a464 = 0;
  _DAT_0203a470 = 0;
  DAT_0203a472 = 0;
  sub_080C97F0(arg0,0);
  sub_080C9854(arg0,0);
  switch(DAT_0203a458) {
  case 0:
    sub_080CB0B8();
    if (DAT_0203a490 != 0) {
      sub_080C3E5C(DAT_0203a490,-(uint)DAT_03000004 & 0xffff,0x18);
    }
    break;
  case 1:
    sub_080CB71C();
    _DAT_0203a464 = 1;
    break;
  case 2:
    sub_080CB7A0();
    break;
  case 3:
    sub_080CB8C8();
    break;
  case 4:
    sub_080CB928();
    if (DAT_0203a490 != 0) {
      sub_080C3E5C(DAT_0203a490,-(uint)DAT_03000004 - 0x100 & 0xffff,0x18);
    }
    DAT_0203a472 = 1;
    _DAT_0203a464 = 1;
    break;
  case 5:
    Status_DrawDropItem();
    if (DAT_0203a490 != 0) {
      sub_080C3E5C(DAT_0203a490,-(uint)DAT_03000004 - 0x100 & 0xffff,0x18);
    }
    _DAT_0203a470 = 1;
  }
  sub_080C9994();
  return;
}


// sub_080C9CD8 @ 0x080C9CD8

void sub_080C9CD8(void)

{
  sub_080AC7CC(0,0x200f874,0,0x1c);
  sub_080C9994();
  return;
}


// sub_080C9D00 @ 0x080C9D00

void sub_080C9D00(undefined4 arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080C92C8((uint)DAT_0203a456);
  if (DAT_0203a45a == 1) {
    sub_080CC630();
  }
  else if (DAT_0203a45a < 2) {
    if (DAT_0203a45a == 0) {
      sub_080CBC8C();
    }
  }
  else if (DAT_0203a45a == 2) {
    sub_080CC694();
  }
  iVar1 = sub_080C9388((uint)DAT_0203a456);
  DAT_0203a46a = (ushort)(iVar1 == 1);
  sub_080C9994();
                    /* WARNING: Could not recover jumptable at 0x080c9d58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C9D5C @ 0x080C9D5C

void sub_080C9D5C(void)

{
  sub_080AC7CC(0,0x200f874,0xd4,0x1c);
  sub_080C9994();
  return;
}


// sub_080C9D84 @ 0x080C9D84

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080C9D84(undefined4 arg0)

{
  ushort uVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 auStack_10 [2];
  
  uVar1 = *(ushort *)(((uint)_DAT_0203a480 + (uint)DAT_0203a482) * 2 + 0x203b454);
  DAT_0203a486 = 0;
  _DAT_0203a46c = 0;
  if (_DAT_0203a45c == 1) {
    sub_080CCA10();
    goto LAB_080c9dfa;
  }
  if (_DAT_0203a45c < 2) {
    if (_DAT_0203a45c != 0) goto LAB_080c9dfa;
    sub_080CC844();
  }
  else {
    if (_DAT_0203a45c == 2) {
      sub_080CCAB4();
      sub_080BF468((uint)uVar1,0,auStack_10);
      DAT_0203a486 = auStack_10[0];
      goto LAB_080c9dfa;
    }
    if (_DAT_0203a45c != 3) goto LAB_080c9dfa;
    sub_080CCD5C();
  }
  _DAT_0203a46c = 1;
LAB_080c9dfa:
  sub_080C9994();
                    /* WARNING: Could not recover jumptable at 0x080c9e04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C9E08 @ 0x080C9E08

void sub_080C9E08(void)

{
  sub_080AC7CC(0,0x200f874,0,0x88);
  sub_080C9994();
  return;
}


// sub_080C9E30 @ 0x080C9E30

void sub_080C9E30(undefined4 arg0)

{
  undefined4 local_14;
  
  local_14 = 0;
  CpuSet(&local_14,0x200dfd4,0x5000200);
  DAT_0203a494 = sub_080ABD04(0,2,0x14,0xe);
  DAT_0203a498 = sub_080ABD04(0x14,2,10,0xe);
  DAT_0203a49c = sub_080ABD04(0,0x10,0x1e,4);
  Status_DrawDemonInfo();
  sub_080C9BCC(arg0);
  sub_080C9D00(arg0);
  sub_080C9D84(arg0);
  return;
}


// sub_080C9EBC @ 0x080C9EBC

void sub_080C9EBC(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 | 4;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 & 0xff;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 | 0x8024;
  REG_BG1HOFS = 0;
  REG_BG2HOFS = 0;
  return;
}


// sub_080C9EF8 @ 0x080C9EF8

void sub_080C9EF8(void)

{
  REG_BG1HOFS = DAT_0203a46e;
  REG_BG2HOFS = DAT_0203a46e;
  return;
}


// sub_080C9F14 @ 0x080C9F14

void sub_080C9F14(undefined4 arg0,undefined4 arg1)

{
  DAT_030020f8 = 0x80c9ef9;
  DAT_0203a46e = DAT_0203a46e + (short)arg1;
  sub_080A9C64(0x80c9ebd,1);
  return;
}


// sub_080C9F40 @ 0x080C9F40

void sub_080C9F40(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 & 0xfffb;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 & 0xffdb;
  REG_BG1HOFS = 0;
  REG_BG2HOFS = 0;
  DAT_030020f8 = 0x80a9971;
  return;
}


// sub_080C9F84 @ 0x080C9F84

void sub_080C9F84(void)

{
  sub_080A9C64(0x80c9f41,1);
  return;
}


// sub_080C9F98 @ 0x080C9F98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080C9F98(undefined4 arg0)

{
  ushort uVar1;
  int arg0_00;
  int iVar2;
  uint uVar3;
  dword dVar4;
  uint uVar5;
  uint uVar6;
  int iStack_70;
  undefined4 local_6c;
  uint uStack_68;
  uint uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  char *pcStack_4c;
  char *pcStack_48;
  char *pcStack_44;
  char *pcStack_40;
  char *pcStack_3c;
  char *pcStack_38;
  char *pcStack_34;
  char *pcStack_30;
  char *pcStack_2c;
  char *pcStack_28;
  char *pcStack_24;
  
  local_6c = arg0;
  arg0_00 = sub_080C92C8((uint)DAT_0203a456);
  if (DAT_0203a46a == 1) {
    sub_080AA184(0x800146c,0,0,1);
  }
  if (_DAT_0203a470 == 1) {
    sub_080C4A4C(0,0,0x92,0x14);
  }
  if (DAT_0203a472 == 1) {
    sub_080C4AB0(0,0,0x92,0x76);
  }
  iVar2 = sub_080C9388((uint)DAT_0203a456);
  if (iVar2 == 1) {
    if (_DAT_0203a464 == 1) {
      sub_080AA184(0x80014a0,1,0,2);
    }
  }
  else if (_DAT_0203a464 == 1) {
    if (DAT_0203a466 != 0) {
      sub_080AA184(0x8001630,0,0,1);
    }
    if (_DAT_0203a468 != 0) {
      sub_080AA184(0x8001780,0,0,1);
    }
  }
  if (_DAT_0203a46c == 1) {
    sub_080AA184(0x8001620,3,0,2);
    iVar2 = sub_080C92AC((uint)*(ushort *)(arg0_00 + 0x12));
    if (iVar2 == 1) {
      sub_080CD9C8(0,(int)*(char *)(arg0_00 + 0x40) & 0xffff,0,0);
      sub_080CD9C8(0,(int)*(char *)(arg0_00 + 0x41) & 0xffff,0,0);
      sub_080CD9C8(0,(int)*(char *)(arg0_00 + 0x42) & 0xffff,0,0);
      sub_080CD9C8(0,(int)*(char *)(arg0_00 + 0x43) & 0xffff,0,0);
      sub_080CD9C8(0,(int)*(char *)(arg0_00 + 0x44) & 0xffff,0,0);
      sub_080CD9C8(0,(int)*(char *)(arg0_00 + 0x45) & 0xffff,0,0);
      uVar6 = sub_08154968((uint)*(ushort *)(arg0_00 + 0x12));
      sub_080BF468(uVar6 & 0xffff,0,&iStack_70);
      if (iStack_70 == 0x80) {
        dVar4 = 0x80014b0;
LAB_080ca1fe:
        sub_080AA184(dVar4,0,0,1);
      }
      else if (iStack_70 < 0x81) {
        if (iStack_70 == 0x40) {
          dVar4 = 0x80014c0;
          goto LAB_080ca1fe;
        }
      }
      else if (iStack_70 == 0xc0) {
        dVar4 = 0x80014d8;
        goto LAB_080ca1fe;
      }
    }
    else {
      iVar2 = sub_080C99B8(arg0_00);
      if (iVar2 != 1) {
        uVar6 = 0;
        uStack_68 = 0;
        uStack_64 = 0;
        uStack_60 = 0;
        uStack_5c = 0;
        uStack_58 = 0;
        pcStack_38 = (char *)(arg0_00 + 0x38);
        pcStack_4c = (char *)(arg0_00 + 0x31);
        pcStack_34 = (char *)(arg0_00 + 0x39);
        pcStack_48 = (char *)(arg0_00 + 0x32);
        pcStack_30 = (char *)(arg0_00 + 0x3a);
        pcStack_44 = (char *)(arg0_00 + 0x33);
        pcStack_2c = (char *)(arg0_00 + 0x3b);
        pcStack_40 = (char *)(arg0_00 + 0x34);
        pcStack_28 = (char *)(arg0_00 + 0x3c);
        pcStack_3c = (char *)(arg0_00 + 0x35);
        pcStack_24 = (char *)(arg0_00 + 0x3d);
        if (((DAT_03000004 & (ushort)0x1ff) == 0) && (*(char *)(arg0_00 + 0xc) == '\0')) {
          uVar5 = 0;
          do {
            uVar3 = sub_080C32D4(uVar5 + 0x120 & 0xffff);
            if (8 < (uVar3 & 0xff)) {
              iVar2 = uVar5 * 4;
              uVar6 = ((byte)(&DAT_081a6ed5)[iVar2] >> 4) + uVar6 & 0xffff;
              uStack_68 = uStack_68 + ((byte)(&DAT_081a6ed5)[iVar2] & 0xf) & 0xffff;
              uStack_64 = uStack_64 + ((byte)(&DAT_081a6ed6)[iVar2] >> 4) & 0xffff;
              uStack_60 = uStack_60 + ((byte)(&DAT_081a6ed6)[iVar2] & 0xf) & 0xffff;
              uStack_5c = uStack_5c + ((byte)(&DAT_081a6ed7)[iVar2] >> 4) & 0xffff;
              uStack_58 = uStack_58 + ((byte)(&DAT_081a6ed7)[iVar2] & 0xf) & 0xffff;
            }
            uVar5 = uVar5 + 1 & 0xffff;
          } while (uVar5 < 0xc);
        }
        uVar1 = *(ushort *)(arg0_00 + 0x10);
        if (DAT_0203a454 == 7) {
          iVar2 = sub_080C3560((uint)*(ushort *)(arg0_00 + 0x12));
          uVar1 = *(ushort *)(iVar2 + 0x10);
        }
        if ((uVar1 & 0x800) == 0) {
          sub_080CD9C8((int)*(char *)(arg0_00 + 0x28) & 0xffff,
                       (int)*(char *)(arg0_00 + 0x30) & 0xffff,(int)*pcStack_38 & 0xffff,uVar6);
          sub_080CD9C8((int)*(char *)(arg0_00 + 0x29) & 0xffff,(int)*pcStack_4c & 0xffff,
                       (int)*pcStack_34 & 0xffff,uStack_68);
          sub_080CD9C8((int)*(char *)(arg0_00 + 0x2a) & 0xffff,(int)*pcStack_48 & 0xffff,
                       (int)*pcStack_30 & 0xffff,uStack_64);
          sub_080CD9C8((int)*(char *)(arg0_00 + 0x2b) & 0xffff,(int)*pcStack_44 & 0xffff,
                       (int)*pcStack_2c & 0xffff,uStack_60);
          sub_080CD9C8((int)*(char *)(arg0_00 + 0x2c) & 0xffff,(int)*pcStack_40 & 0xffff,
                       (int)*pcStack_28 & 0xffff,uStack_5c);
          sub_080CD9C8((int)*(char *)(arg0_00 + 0x2d) & 0xffff,(int)*pcStack_3c & 0xffff,
                       (int)*pcStack_24 & 0xffff,uStack_58);
        }
        else {
          sub_080CD9C8(1,(int)*(char *)(arg0_00 + 0x30) & 0xffff,(int)*pcStack_38 & 0xffff,uVar6);
          sub_080CD9C8(1,(int)*pcStack_4c & 0xffff,(int)*pcStack_34 & 0xffff,uStack_68);
          sub_080CD9C8(1,(int)*pcStack_48 & 0xffff,(int)*pcStack_30 & 0xffff,uStack_64);
          sub_080CD9C8(1,(int)*pcStack_44 & 0xffff,(int)*pcStack_2c & 0xffff,uStack_60);
          sub_080CD9C8(0x28,(int)*pcStack_40 & 0xffff,(int)*pcStack_28 & 0xffff,uStack_5c);
          sub_080CD9C8(1,(int)*pcStack_3c & 0xffff,(int)*pcStack_24 & 0xffff,uStack_58);
        }
      }
    }
  }
  if (DAT_0203a486 == 0x80) {
    dVar4 = 0x80014b0;
LAB_080ca53e:
    sub_080AA184(dVar4,0,0,1);
  }
  else if (DAT_0203a486 < 0x81) {
    if (DAT_0203a486 == 0x40) {
      sub_080AA184(0x80014c0,0,0,1);
    }
  }
  else if (DAT_0203a486 == 0xc0) {
    dVar4 = 0x80014d8;
    goto LAB_080ca53e;
  }
  if ((DAT_030031bc & 7) == 0) {
    if (DAT_0203a454 == 3) {
      if (DAT_0203a458 != 1) goto LAB_080ca5d8;
      uVar6 = (uint)_DAT_0203a474;
      _DAT_0203a474 = _DAT_0203a474 + 1 & 1;
    }
    else if (DAT_0203a458 == 0) {
      uVar6 = (uint)_DAT_0203a474;
      _DAT_0203a474 = _DAT_0203a474 + 1 & 1;
    }
    else {
LAB_080ca5d8:
      uVar6 = 0;
    }
    sub_080C97F0(local_6c,uVar6);
    sub_080C9854(local_6c,uVar6);
  }
  if (1 < (ushort)(DAT_0203a454 - 4U)) {
    return;
  }
  switch(_DAT_0203a480) {
  case 0:
    uStack_54 = 5;
    goto LAB_080ca632;
  case 1:
    uStack_54 = 0x52;
    uStack_50 = 0x82;
    break;
  case 2:
    uStack_54 = 0x9f;
LAB_080ca632:
    uStack_50 = 0x82;
    break;
  case 3:
    uStack_54 = 5;
    goto LAB_080ca64a;
  case 4:
    uStack_54 = 0x52;
    uStack_50 = 0x8f;
    break;
  case 5:
    uStack_54 = 0x9f;
LAB_080ca64a:
    uStack_50 = 0x8f;
  }
  sub_080AA184(0x8001770,2,0,2);
  return;
}


// sub_080CA684 @ 0x080CA684

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CA684(void)

{
  DAT_0203a458 = 0;
  DAT_0203a45a = 0;
  _DAT_0203a45c = 0;
  return;
}


// sub_080CA694 @ 0x080CA694

void sub_080CA694(int arg0,int arg1)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg0 * 0x10000 < 1) {
    do {
      if (DAT_0203a456 == 0) {
        DAT_0203a456 = (ushort)arg1;
      }
      DAT_0203a456 = DAT_0203a456 - 1;
      if (DAT_0203a454 != 1) goto LAB_080ca70e;
      iVar1 = sub_080C2340(0xb6);
      if (iVar1 == 0) break;
      iVar1 = sub_080C92C8((uint)DAT_0203a456);
      iVar1 = sub_080C2554((int)*(short *)(iVar1 + 0x12));
    } while (iVar1 == 0);
  }
  else {
    do {
      if ((uint)DAT_0203a456 == arg1 - 1U) {
        DAT_0203a456 = 0;
      }
      else {
        DAT_0203a456 = DAT_0203a456 + 1;
      }
      if (DAT_0203a454 != 1) goto LAB_080ca70e;
      iVar1 = sub_080C2340(0xb6);
      if (iVar1 == 0) break;
      iVar1 = sub_080C92C8((uint)DAT_0203a456);
      iVar1 = sub_080C2554((int)*(short *)(iVar1 + 0x12));
    } while (iVar1 == 0);
  }
  DAT_03006462 = DAT_0203a456;
LAB_080ca70e:
                    /* WARNING: Could not recover jumptable at 0x080ca712. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CA718 @ 0x080CA718

void sub_080CA718(int arg0)

{
  undefined4 arg1;
  int iVar1;
  int iVar2;
  ushort uVar3;
  undefined4 arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080C92C8((uint)DAT_0203a456);
  arg1 = sub_080C964C(0);
  iVar1 = sub_080C964C(1);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  iVar2 = sub_080C9388((uint)DAT_0203a456);
  if (iVar2 == 1) {
    uVar3 = 1;
    arg0_00 = 0x65;
  }
  else {
    uVar3 = 0x80;
    arg0_00 = 100;
    sub_080C4AB0(0,0,0x92,0x76);
  }
  if ((uVar3 & DAT_030031b8) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((((DAT_030031b8 & 0x200) == 0) || (DAT_0203a476 != 0)) || (iVar1 == 1)) {
        if ((((DAT_030031b8 & 0x100) != 0) && (DAT_0203a476 == 0)) && (iVar1 != 1)) {
          sub_080C51D4(100);
          sub_080CA694(1,arg1);
          DAT_0203a45e = 0x10;
          *(undefined2 *)(arg0 + 0x1e) = 2;
          sub_080CA684();
        }
      }
      else {
        sub_080C51D4(100);
        sub_080CA694(0xffffffff,arg1);
        DAT_0203a45e = 0xfff0;
        *(undefined2 *)(arg0 + 0x1e) = 2;
        sub_080CA684();
      }
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1e) = 3;
    }
  }
  else {
    iVar1 = sub_080C93B4((uint)DAT_0203a456);
    if (iVar1 == 1) {
      sub_080C51D4(arg0_00);
      *(undefined2 *)(arg0 + 0x1e) = 0x8001;
    }
    else {
      iVar1 = sub_080C9388((uint)DAT_0203a456);
      if (iVar1 == 1) {
        sub_080C51D4(arg0_00);
        *(undefined2 *)(arg0 + 0x1e) = 0x8002;
      }
      else {
        sub_080C51D4(arg0_00);
        *(undefined2 *)(arg0 + 0x1e) = 0x8003;
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080ca848. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CA84C @ 0x080CA84C

uint sub_080CA84C(undefined4 arg0,undefined4 arg1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  do {
    if ((&DAT_030051ae)[uVar3 * 2] != 0) {
      uVar1 = *(ushort *)(uVar3 * 4 + 0x30051ac);
      if (((ushort)arg0 <= uVar1) && (uVar1 <= (ushort)arg1)) {
        *(ushort *)(uVar2 * 2 + 0x203b454) = uVar1;
        uVar2 = uVar2 + 1 & 0xffff;
      }
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 0x15a);
  return uVar2;
}


// sub_080CA8A4 @ 0x080CA8A4

void sub_080CA8A4(uint arg0,uint arg1)

{
  undefined4 uVar1;
  undefined2 local_14 [2];
  
  local_14[0] = 0xffff;
  CpuSet(local_14,0x203b454,0x1000080);
  uVar1 = sub_080CA84C(arg0 & 0xffff,arg1 & 0xffff);
  DAT_0203a47c._0_2_ = (short)uVar1;
  return;
}


// sub_080CA8EC @ 0x080CA8EC

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CA8EC(int arg0)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) != 0) {
    if (_DAT_0203a480 == 1) {
      sub_080CA8A4(0x100,0x11f);
    }
    else if (_DAT_0203a480 < 2) {
      if (_DAT_0203a480 == 0) {
        sub_080CA8A4(0x120,299);
      }
    }
    else if (_DAT_0203a480 == 2) {
      sub_080CA8A4(0xd0,0xff);
    }
    else if (_DAT_0203a480 == 3) {
      sub_080CA8A4(300,0x159);
    }
    if ((short)DAT_0203a47c == 0) {
      sub_080C51D4(0x68);
    }
    else {
      sub_080C51D4(0x65);
      *(undefined2 *)(arg0 + 0x1e) = 1;
      DAT_0203a482 = 0;
      _DAT_0203a480 = 0;
    }
    goto LAB_080caa68;
  }
  uVar2 = DAT_030031b8 & 2;
  if ((DAT_030031b8 & 2) == 0) {
    if (((DAT_030031b8 & 0x40) == 0) && ((DAT_030031b8 & 0x80) == 0)) {
      uVar2 = DAT_030031b8 & 0x20;
      if ((DAT_030031b8 & 0x20) == 0) {
        uVar1 = _DAT_0203a480;
        if (((DAT_030031b8 & 0x10) != 0) && (sub_080C51D4(100), uVar1 = uVar2, _DAT_0203a480 != 3))
        {
          uVar1 = _DAT_0203a480 + 1;
        }
      }
      else {
        sub_080C51D4(100);
        if (_DAT_0203a480 == 0) {
LAB_080ca9fe:
          _DAT_0203a480 = 3;
          uVar1 = _DAT_0203a480;
        }
        else {
          uVar1 = _DAT_0203a480 - 1;
        }
      }
    }
    else {
      sub_080C51D4(100);
      uVar1 = 2;
      if (_DAT_0203a480 != 0) {
        if (_DAT_0203a480 == 1) goto LAB_080ca9fe;
        uVar1 = uVar2;
        if ((_DAT_0203a480 != 2) && (uVar1 = _DAT_0203a480, _DAT_0203a480 == 3)) {
          _DAT_0203a480 = 1;
          uVar1 = _DAT_0203a480;
        }
      }
    }
  }
  else {
    sub_080C51D4(0x66);
    *(undefined2 *)(arg0 + 0x1e) = 2;
    uVar1 = _DAT_0203a480;
  }
  _DAT_0203a480 = uVar1;
  if (_DAT_0203a480 == 1) {
    unaff_r8 = 0x84;
  }
  else if (_DAT_0203a480 < 2) {
    if (_DAT_0203a480 == 0) {
      unaff_r8 = 6;
    }
  }
  else if (_DAT_0203a480 == 2) {
    unaff_r8 = 6;
  }
  else if (_DAT_0203a480 == 3) {
    unaff_r8 = 0x84;
  }
  sub_080C49EC(10,0,2,unaff_r8);
LAB_080caa68:
                    /* WARNING: Could not recover jumptable at 0x080caa76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CAA78 @ 0x080CAA78

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CAA78(int arg0)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = (ushort)DAT_0203a47c;
  uVar3 = (uint)(ushort)DAT_0203a47c;
  bVar1 = false;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  uVar4 = uVar3;
  if (6 < uVar3) {
    uVar4 = 7;
  }
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) == 0) {
          if (((DAT_03003964 & 0x200) == 0) || (uVar3 < 8)) {
            if (((DAT_03003964 & 0x100) != 0) && (7 < uVar3)) {
              sub_080C51D4(100);
              if (_DAT_0203a480 == 6) {
                bVar1 = true;
                if ((int)(DAT_0203a482 + 0xd) < (int)(uVar3 - 1)) {
                  DAT_0203a482 = DAT_0203a482 + 7;
                }
                else {
                  DAT_0203a482 = uVar2 - 7;
                }
              }
              else {
                _DAT_0203a480 = 6;
              }
            }
          }
          else {
            sub_080C51D4(100);
            if (_DAT_0203a480 == 0) {
              bVar1 = true;
              if (DAT_0203a482 < 6) {
                DAT_0203a482 = _DAT_0203a480;
              }
              else {
                DAT_0203a482 = DAT_0203a482 - 6;
              }
            }
            else {
              _DAT_0203a480 = 0;
            }
          }
          goto LAB_080cabb0;
        }
        sub_080C51D4(100);
        if ((uint)_DAT_0203a480 != uVar4 - 1) {
          _DAT_0203a480 = _DAT_0203a480 + 1;
          goto LAB_080cabb0;
        }
        if ((_DAT_0203a480 != 6) || ((int)(uVar3 - 1) < (int)(DAT_0203a482 + 7))) goto LAB_080cabb0;
        DAT_0203a482 = DAT_0203a482 + 1;
      }
      else {
        sub_080C51D4(100);
        if (_DAT_0203a480 != 0) {
          _DAT_0203a480 = _DAT_0203a480 - 1;
          goto LAB_080cabb0;
        }
        if (DAT_0203a482 == 0) goto LAB_080cabb0;
        DAT_0203a482 = DAT_0203a482 - 1;
      }
      bVar1 = true;
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1e) = 2;
    }
  }
  else {
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1e) = 1;
    _DAT_0203a470 = 0;
    DAT_0203a472 = 0;
  }
LAB_080cabb0:
  if (bVar1) {
    sub_080C9CD8();
    sub_080C9BCC(arg0);
  }
  sub_080C49EC(0xf,0,2,10);
  if (DAT_0203a482 != 0) {
    _DAT_0203a470 = 1;
  }
  if ((int)(DAT_0203a482 + 7) <= (int)(uVar3 - 1)) {
    DAT_0203a472 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080cabfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CAC00 @ 0x080CAC00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CAC00(int arg0)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 auStack_1c [2];
  
  iVar2 = sub_080C92C8((uint)DAT_0203a456);
  uVar6 = 0;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) != 0) {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1e) = 2;
    }
    sub_080C49EC(10,0,2,6);
  }
  else {
    auStack_1c[0] = 0xffff;
    CpuSet(auStack_1c,0x203b454,0x1000080);
    uVar5 = 0;
    pcVar3 = (char *)(iVar2 + 0x5d);
    cVar1 = *pcVar3;
    while (cVar1 != -1) {
      *(ushort *)(uVar6 * 2 + 0x203b454) = (ushort)(byte)pcVar3[uVar5];
      uVar4 = uVar6 + 1;
      uVar6 = uVar4 & 0xffff;
      DAT_0203a47c._0_2_ = (short)uVar4;
      uVar5 = uVar5 + 1 & 0xffff;
      if (0x1f < uVar5) break;
      cVar1 = pcVar3[uVar5];
    }
    if ((short)DAT_0203a47c != 0) {
      sub_080C51D4(0x65);
      *(undefined2 *)(arg0 + 0x1e) = 1;
      DAT_0203a482 = 0;
      _DAT_0203a480 = 0;
    }
  }
  return;
}


// sub_080CACD4 @ 0x080CACD4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CACD4(int arg0)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = (ushort)DAT_0203a47c;
  uVar3 = (uint)(ushort)DAT_0203a47c;
  bVar1 = false;
  *(undefined2 *)(arg0 + 0x1e) = 0;
  uVar4 = uVar3;
  if (6 < uVar3) {
    uVar4 = 7;
  }
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_03003964 & 0x40) == 0) {
        if ((DAT_03003964 & 0x80) == 0) {
          if (((DAT_03003964 & 0x200) == 0) || (uVar3 < 8)) {
            if (((DAT_03003964 & 0x100) != 0) && (7 < uVar3)) {
              sub_080C51D4(100);
              if (_DAT_0203a480 == 6) {
                bVar1 = true;
                if ((int)(DAT_0203a482 + 0xd) < (int)(uVar3 - 1)) {
                  DAT_0203a482 = DAT_0203a482 + 7;
                }
                else {
                  DAT_0203a482 = uVar2 - 7;
                }
              }
              else {
                _DAT_0203a480 = 6;
              }
            }
          }
          else {
            sub_080C51D4(100);
            if (_DAT_0203a480 == 0) {
              bVar1 = true;
              if (DAT_0203a482 < 6) {
                DAT_0203a482 = _DAT_0203a480;
              }
              else {
                DAT_0203a482 = DAT_0203a482 - 6;
              }
            }
            else {
              _DAT_0203a480 = 0;
            }
          }
        }
        else {
          sub_080C51D4(100);
          if ((uint)_DAT_0203a480 == uVar4 - 1) {
            if ((_DAT_0203a480 == 6) && ((int)(DAT_0203a482 + 7) <= (int)(uVar3 - 1))) {
              DAT_0203a482 = DAT_0203a482 + 1;
              bVar1 = true;
            }
          }
          else {
            _DAT_0203a480 = _DAT_0203a480 + 1;
          }
        }
      }
      else {
        sub_080C51D4(100);
        if (_DAT_0203a480 == 0) {
          if (DAT_0203a482 != 0) {
            DAT_0203a482 = DAT_0203a482 - 1;
            bVar1 = true;
          }
        }
        else {
          _DAT_0203a480 = _DAT_0203a480 - 1;
        }
      }
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1e) = 2;
    }
  }
  else {
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  if (bVar1) {
    sub_080C9CD8();
    sub_080C9BCC(arg0);
  }
  sub_080C49EC(0xf,0,2,10);
  if (DAT_0203a482 != 0) {
    _DAT_0203a470 = 1;
  }
  if ((int)(DAT_0203a482 + 7) <= (int)(uVar3 - 1)) {
    DAT_0203a472 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080cae66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CAE68 @ 0x080CAE68

void sub_080CAE68(int arg0)

{
  undefined4 arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 0x80) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_030031b8 & 0x40) == 0) goto LAB_080caeae;
      arg0_00 = 100;
    }
    else {
      arg0_00 = 0x66;
    }
    sub_080C51D4(arg0_00);
    *(undefined2 *)(arg0 + 0x1e) = 2;
  }
  else {
    sub_080C51D4(100);
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
LAB_080caeae:
  sub_080C4A4C(0,0,0x92,0x14);
                    /* WARNING: Could not recover jumptable at 0x080caebe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CAEC0 @ 0x080CAEC0

void sub_080CAEC0(int arg0)

{
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_030031b8 & 1) == 0) {
    if ((DAT_030031b8 & 2) == 0) {
      if ((DAT_030031b8 & 0x40) != 0) {
        sub_080C51D4(100);
        *(undefined2 *)(arg0 + 0x1e) = 3;
      }
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1e) = 2;
    }
  }
  return;
}


// sub_080CAF0C @ 0x080CAF0C

void sub_080CAF0C(void)

{
  DAT_03000004 = DAT_0203a45e + DAT_03000004;
  DAT_03000008 = DAT_0203a45e + DAT_03000008;
  if (DAT_0203a490 != 0) {
    sub_080C3E5C(DAT_0203a490,(uint)(ushort)-DAT_03000004,0x18);
  }
  return;
}


// sub_080CAF48 @ 0x080CAF48

void sub_080CAF48(undefined4 arg0,undefined4 arg1)

{
  DAT_0203a458 = (undefined2)arg1;
  return;
}


// sub_080CAF54 @ 0x080CAF54

void sub_080CAF54(undefined4 arg0,undefined4 arg1)

{
  DAT_0203a45a = (undefined2)arg1;
  return;
}


// sub_080CAF60 @ 0x080CAF60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CAF60(undefined4 arg0,undefined4 arg1)

{
  _DAT_0203a45c = (undefined2)arg1;
  return;
}


// sub_080CAF6C @ 0x080CAF6C

void sub_080CAF6C(void)

{
  if (DAT_0203a490 != 0) {
    sub_080C3E80(DAT_0203a490);
    DAT_0203a490 = 0;
  }
  sub_080ABD30(DAT_0203a494,1);
  sub_080ABD30(DAT_0203a498,1);
  sub_080ABD30(DAT_0203a49c,1);
  *(undefined4 *)(DAT_0203a48c + 0xc) = 1;
  Font_ResetGlyphSpriteCache(0x180);
  return;
}


// sub_080CAFB0 @ 0x080CAFB0

void sub_080CAFB0(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(*DAT_0203a48c == 0);
  return;
}


// sub_080CAFD0 @ 0x080CAFD0

void sub_080CAFD0(undefined4 arg0,undefined4 arg1)

{
  undefined4 local_18;
  
  sub_080AD0FC(0x84efb44,0xffff);
  local_18 = 0;
  CpuSet(&local_18,0x203a454,0x5000200);
  DAT_0203a456 = (undefined2)arg1;
  DAT_0203a454 = 0;
  DAT_0203a476 = 0;
  return;
}


// sub_080CB01C @ 0x080CB01C

void sub_080CB01C(undefined4 arg0,undefined4 arg1)

{
  undefined4 local_18;
  
  sub_080AD0FC(0x84efb44,0xffff);
  local_18 = 0;
  CpuSet(&local_18,0x203a454,0x5000200);
  DAT_0203a456 = (undefined2)arg1;
  DAT_0203a454 = 1;
  DAT_0203a476 = 0;
  return;
}


// sub_080CB068 @ 0x080CB068

void sub_080CB068(void)

{
  sub_080AC7CC(0,0x200f874,0x30,0x74);
  Text_DrawString(0x84f00c8,0x200f874,0x30,0x74);
  sub_080CCFC4((uint)DAT_0203a48a,0x88,0x77,0);
  sub_080C9994();
  return;
}


// sub_080CB0B8 @ 0x080CB0B8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CB0B8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  dword dVar7;
  dword arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080C92C8((uint)DAT_0203a456);
  if (DAT_0203a490 != 0) {
    sub_080C3E80(DAT_0203a490);
    DAT_0203a490 = 0;
  }
  iVar2 = sub_080C9388((uint)DAT_0203a456);
  if (iVar2 != 1) {
    iVar2 = sub_080C92AC((uint)*(ushort *)(iVar1 + 0x12));
    if (iVar2 != 1) {
      iVar2 = sub_080C99B8(iVar1);
      if (iVar2 == 1) {
        sub_080CCE5C(0x84f0178,0x56,0x1e,0);
        sub_080CCE5C(0x84f017c,0x60,0x28,4);
        sub_080CCE5C(0x84f00d8,0x56,0x32,0);
        sub_080CCE5C(0x84f0184,0x62,0x3c,4);
        sub_080CCE5C(0x84f00dc,0x78,0x3c,4);
        sub_080CCE5C(0x84f0184,0x80,0x3c,4);
        sub_080CCE5C(0x84f00e0,0x56,0x46,0);
        sub_080CCE5C(0x84f0184,0x62,0x50,4);
        sub_080CCE5C(0x84f00dc,0x78,0x50,4);
        sub_080CCE5C(0x84f0184,0x80,0x50,4);
        sub_080CCE5C(0x84f00e4,0x56,0x5a,0);
        sub_080CCE5C(0x84f0188,0x78,100,4);
        sub_080CCE5C(0x84f0190,0x56,0x6e,0);
        sub_080CCE5C(0x84f0188,0x78,0x78,4);
      }
      else {
        iVar2 = sub_080C3560((uint)*(ushort *)(iVar1 + 0x12));
        if (iVar2 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = sub_080C0818((uint)*(byte *)(iVar2 + 0xc));
          uVar4 = uVar4 & 0xffff;
        }
        sub_080CCE5C(0x84f0178,0x56,0x1e,0);
        sub_080CD044((uint)*(ushort *)(iVar1 + 0x12),0x60,0x28);
        dVar7 = (dword)*(ushort *)(iVar1 + 0x18);
        arg0 = (dword)*(ushort *)(iVar1 + 0x1c);
        if (DAT_0203a454 == 7) {
          iVar2 = sub_080C3560((uint)*(ushort *)(iVar1 + 0x12));
          dVar7 = (dword)*(ushort *)(iVar2 + 0x18);
          iVar2 = sub_080C3560((uint)*(ushort *)(iVar1 + 0x12));
          arg0 = (dword)*(ushort *)(iVar2 + 0x1c);
        }
        else if (((DAT_0203a454 == 6) && (DAT_0203b85c == 2)) &&
                (uVar5 = sub_08157C2C(), (uVar5 & 0xffff) != 0)) {
          if ((uVar5 & 1) != 0) {
            iVar2 = (int)*(short *)(iVar1 + 0x1a);
            if (iVar2 < 0) {
              iVar2 = iVar2 + 3;
            }
            dVar7 = dVar7 + (iVar2 >> 2) & 0xffff;
            if (999 < dVar7) {
              dVar7 = 999;
            }
          }
          if ((uVar5 & 2) != 0) {
            iVar2 = (int)*(short *)(iVar1 + 0x1e);
            if (iVar2 < 0) {
              iVar2 = iVar2 + 3;
            }
            arg0 = arg0 + (iVar2 >> 2) & 0xffff;
            if (999 < arg0) {
              arg0 = 999;
            }
          }
        }
        sub_080CCE5C(0x84f00d8,0x56,0x32,0);
        sub_080CCF44(dVar7,0x70,0x3c,4);
        sub_080CCE5C(0x84f00dc,0x78,0x3c,4);
        sub_080CCF44((int)*(short *)(iVar1 + 0x1a),0x90,0x3c,4);
        sub_080CCE5C(0x84f00e0,0x56,0x46,0);
        sub_080CCF44(arg0,0x70,0x50,4);
        sub_080CCE5C(0x84f00dc,0x78,0x50,4);
        sub_080CCF44((int)*(short *)(iVar1 + 0x1e),0x90,0x50,4);
        sub_080CCE5C(0x84f00e4,0x56,0x5a,0);
        if ((uVar4 & 0x8000) != 0) {
          dVar7 = 0x84f0194;
          uVar6 = 0x78;
          goto LAB_080cb69c;
        }
        if ((uVar4 & 0x2000) != 0) {
          dVar7 = 0x84f00f0;
          goto LAB_080cb69a;
        }
        if ((uVar4 & 0x1000) == 0) {
          if ((uVar4 & 4) != 0) {
            dVar7 = 0x84f0100;
            uVar6 = 0x68;
            goto LAB_080cb69c;
          }
          if ((uVar4 & 0x800) != 0) {
            dVar7 = 0x84f0108;
            uVar6 = 0x80;
            goto LAB_080cb69c;
          }
          if ((uVar4 & 0x4000) != 0) {
            dVar7 = 0x84f010c;
            uVar6 = 0x68;
            goto LAB_080cb69c;
          }
          if ((uVar4 & 1) != 0) {
            dVar7 = 0x84f0114;
LAB_080cb69a:
            uVar6 = 0x70;
            goto LAB_080cb69c;
          }
          if ((uVar4 & 0x200) != 0) {
            dVar7 = 0x84f011c;
            goto LAB_080cb69a;
          }
          if ((uVar4 & 0x40) != 0) {
            dVar7 = 0x84f0124;
            goto LAB_080cb69a;
          }
          if ((uVar4 & 0x20) != 0) {
            dVar7 = 0x84f012c;
            uVar6 = 0x78;
            goto LAB_080cb69c;
          }
          if ((uVar4 & 0x100) != 0) {
            dVar7 = 0x84f0134;
            uVar6 = 0x68;
            goto LAB_080cb69c;
          }
          if ((uVar4 & 0x80) != 0) {
            dVar7 = 0x84f013c;
            goto LAB_080cb69a;
          }
          if ((uVar4 & 2) != 0) {
            dVar7 = 0x84f0144;
            goto LAB_080cb69a;
          }
          if ((uVar4 & 0x10) != 0) {
            dVar7 = 0x84f014c;
            goto LAB_080cb69a;
          }
          if ((uVar4 & 8) != 0) {
            dVar7 = 0x84f0154;
            goto LAB_080cb69a;
          }
          sub_080CCE5C(0x84f015c,0x78,100,4);
        }
        else {
          dVar7 = 0x84f00f8;
          uVar6 = 0x68;
LAB_080cb69c:
          sub_080CCE5C(dVar7,uVar6,100,4);
        }
        sub_080CCE5C(0x84f0190,0x56,0x6e,0);
        sub_080CD0E4((uint)*(ushort *)(iVar1 + 0x12));
      }
    }
    DAT_0203a490 = sub_080C3D84(0,(uint)*(ushort *)(iVar1 + 0x12),-(uint)DAT_03000004 & 0xffff,0x18)
    ;
    sub_080C3E40(DAT_0203a490,1);
    _DAT_03002f50 = 0x10;
    DAT_03002f52 = 0x10;
    goto LAB_080cb700;
  }
  uVar4 = sub_080C0818((uint)*(byte *)(iVar1 + 0xc));
  sub_080CCE5C(0x84f00d8,10,0x20,0);
  sub_080CCF44((int)*(short *)(iVar1 + 0x18),0x60,0x20,4);
  sub_080CCE5C(0x84f00dc,0x68,0x20,4);
  sub_080CCF44((int)*(short *)(iVar1 + 0x1a),0x80,0x20,4);
  sub_080CCE5C(0x84f00e0,10,0x2c,0);
  sub_080CCF44((int)*(short *)(iVar1 + 0x1c),0x60,0x2c,4);
  sub_080CCE5C(0x84f00dc,0x68,0x2c,4);
  sub_080CCF44((int)*(short *)(iVar1 + 0x1e),0x80,0x2c,4);
  sub_080CCE5C(0x84f00e4,10,0x38,0);
  if ((uVar4 & 0x8000) == 0) {
    if ((uVar4 & 0x2000) != 0) {
      dVar7 = 0x84f00f0;
      goto LAB_080cb292;
    }
    if ((uVar4 & 0x1000) != 0) {
      dVar7 = 0x84f00f8;
      uVar6 = 0x58;
      goto LAB_080cb294;
    }
    if ((uVar4 & 4) != 0) {
      dVar7 = 0x84f0100;
      uVar6 = 0x58;
      goto LAB_080cb294;
    }
    if ((uVar4 & 0x800) != 0) {
      dVar7 = 0x84f0108;
      uVar6 = 0x70;
      goto LAB_080cb294;
    }
    if ((uVar4 & 0x4000) != 0) {
      dVar7 = 0x84f010c;
      uVar6 = 0x58;
      goto LAB_080cb294;
    }
    if ((uVar4 & 1) != 0) {
      dVar7 = 0x84f0114;
      goto LAB_080cb292;
    }
    if ((uVar4 & 0x200) != 0) {
      dVar7 = 0x84f011c;
      goto LAB_080cb292;
    }
    if ((uVar4 & 0x40) != 0) {
      dVar7 = 0x84f0124;
      goto LAB_080cb292;
    }
    if ((uVar4 & 0x20) != 0) {
      dVar7 = 0x84f012c;
      uVar6 = 0x68;
      goto LAB_080cb294;
    }
    if ((uVar4 & 0x100) != 0) {
      dVar7 = 0x84f0134;
      uVar6 = 0x58;
      goto LAB_080cb294;
    }
    if ((uVar4 & 0x80) != 0) {
      dVar7 = 0x84f013c;
      goto LAB_080cb292;
    }
    if ((uVar4 & 2) != 0) {
      dVar7 = 0x84f0144;
      goto LAB_080cb292;
    }
    if ((uVar4 & 0x10) != 0) {
      dVar7 = 0x84f014c;
      goto LAB_080cb292;
    }
    if ((uVar4 & 8) != 0) {
      dVar7 = 0x84f0154;
      goto LAB_080cb292;
    }
    sub_080CCE5C(0x84f015c,0x68,0x38,4);
  }
  else {
    dVar7 = 0x84f00e8;
LAB_080cb292:
    uVar6 = 0x60;
LAB_080cb294:
    sub_080CCE5C(dVar7,uVar6,0x38,4);
  }
  sub_080CCE5C(0x84f0164,10,0x44,0);
  sub_080CCF44(*(undefined4 *)(iVar1 + 8),0x80,0x44,4);
  sub_080CCE5C(0x84f0168,10,0x50,0);
  if (*(byte *)(iVar1 + 0xd) != 99) {
    iVar2 = sub_080C1098(*(byte *)(iVar1 + 0xd) + 1);
    sub_080CCF44(iVar2 - *(int *)(iVar1 + 8),0x80,0x50,4);
  }
  iVar1 = sub_080C93B4((uint)DAT_0203a456);
  if (iVar1 == 1) {
    sub_080CCE5C(0x84f0170,10,0x5c,0);
    sub_080CCF44((uint)DAT_03005183,0x80,0x5c,4);
    sub_080CCE5C(0x84f00dc,0x70,0x5c,4);
    iVar2 = 0;
    iVar1 = 4;
    do {
      iVar3 = sub_080C09B0(iVar1);
      if (iVar3 != 0) {
        iVar2 = iVar2 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
    sub_080CCF44(iVar2,0x68,0x5c,4);
  }
LAB_080cb700:
                    /* WARNING: Could not recover jumptable at 0x080cb70a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CB71C @ 0x080CB71C

void sub_080CB71C(void)

{
  int iVar1;
  
  iVar1 = sub_080C92C8((uint)DAT_0203a456);
  sub_080CD100((uint)*(byte *)(iVar1 + 0x20),0x24,0x1c,0);
  sub_080CD100((uint)*(byte *)(iVar1 + 0x21),0x24,0x2b,0);
  sub_080CD100((uint)*(byte *)(iVar1 + 0x22),0x24,0x3a,0);
  sub_080CD100((uint)*(byte *)(iVar1 + 0x23),0x24,0x49,0);
  sub_080CD100((uint)*(byte *)(iVar1 + 0x24),0x24,0x58,0);
  sub_080CD100((uint)*(byte *)(iVar1 + 0x25),0x24,0x67,0);
  sub_080CD100((uint)*(byte *)(iVar1 + 0x26),0x24,0x76,0);
  return;
}


// sub_080CB7A0 @ 0x080CB7A0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CB7A0(void)

{
  int arg0;
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 arg3;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0x1c;
  arg0 = sub_080C92C8((uint)DAT_0203a456);
  uVar6 = 0;
  uVar1 = 0x1f0000;
  do {
    arg3 = 0;
    uVar4 = (uint)*(ushort *)((DAT_0203a482 + uVar6) * 2 + 0x203b454);
    if (uVar4 != 0xffff) {
      if (uVar4 < 0xd0) {
        uVar2 = sub_080C343C(arg0,(uint)_DAT_0203a484);
        if ((uVar2 & 0xffff) == uVar4) {
          arg3 = 6;
          sub_080CCE5C(0x84f019c,2,uVar5 + 2 & 0xffff,6);
        }
        else {
          iVar3 = sub_080CDB74((uint)*(byte *)(arg0 + 0xc),uVar4 & 0xff);
          if (iVar3 != 1) {
            arg3 = 2;
          }
        }
        sub_080CD100(uVar4 & 0x7fff,10,uVar5 & 0xffff,arg3);
      }
      else {
        sub_080CD1A0(uVar4,10,uVar5 & 0xffff,0);
      }
      uVar4 = sub_080C32D4(uVar4);
      if ((uVar4 & 0xff) < 100) {
        sub_080CCE5C(0x84f01a0,0x75,uVar1 >> 0x10,arg3);
      }
      else {
        sub_080CCE5C(0x84f01a0,0x6d,uVar1 >> 0x10,arg3);
      }
      sub_080CCFC4(uVar4 & 0xff,0x87,uVar5 + 2 & 0xffff,arg3);
      uVar1 = uVar1 + 0xf0000;
      uVar5 = uVar5 + 0xf;
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 7);
  return;
}


// sub_080CB8C8 @ 0x080CB8C8

void sub_080CB8C8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0x1c;
  uVar2 = 0;
  do {
    uVar1 = (uint)*(ushort *)((uVar2 + DAT_0203a482) * 2 + 0x203b454);
    if (uVar1 != 0xffff) {
      uVar1 = uVar1 & 0xff;
      sub_080CD1F8(uVar1,10,uVar3 & 0xffff);
      sub_080CD260(uVar1,0x6c,0x87,uVar3 + 3 & 0xffff);
    }
    uVar3 = uVar3 + 0xf;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 7);
  return;
}


// sub_080CB928 @ 0x080CB928

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CB928(void)

{
  byte bVar1;
  bool bVar2;
  uint arg0;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  
  iVar3 = sub_080C92C8((uint)DAT_0203a456);
  iVar9 = 0;
  uVar6 = 0x1e;
  bVar2 = false;
  if (DAT_0203a454 == 7) {
    iVar4 = sub_080C3560((uint)*(ushort *)(iVar3 + 0x12));
    pbVar8 = (byte *)(iVar4 + 0x5d);
  }
  else {
    if (DAT_0203a454 != 6) {
      pbVar8 = (byte *)(iVar3 + 0x5d);
      if (DAT_0203a454 != 1) {
        bVar2 = true;
      }
      goto LAB_080cb980;
    }
    pbVar8 = (byte *)0x203b860;
  }
  bVar2 = true;
LAB_080cb980:
  DAT_0203a466 = 0;
  _DAT_0203a468 = 0;
  uVar5 = 0;
  bVar1 = *pbVar8;
  while (uVar7 = (uint)bVar1, uVar7 != 0xff) {
    if (uVar7 < 0x40) {
      sub_080CD1F8(uVar7,0x24,uVar6 & 0xffff);
      uVar6 = uVar6 + 0xe;
      iVar9 = iVar9 + 1;
    }
    uVar5 = uVar5 + 1;
    if (6 < uVar5) break;
    bVar1 = pbVar8[uVar5];
  }
  if (uVar6 != 0x1e) {
    DAT_0203a466 = 0x16;
  }
  uVar5 = 0;
  bVar1 = *pbVar8;
  uVar7 = uVar6;
  while (arg0 = (uint)bVar1, arg0 != 0xff) {
    if (bVar2) {
      if ((0x3f < arg0) && (iVar4 = sub_0812C4E0(arg0,(uint)*(ushort *)(iVar3 + 0x12)), iVar4 == 0))
      {
        sub_080CD1F8(arg0,0x24,uVar7 & 0xffff);
        uVar7 = uVar7 + 0xe;
        iVar9 = iVar9 + 1;
      }
    }
    else if (0x3f < arg0) {
      sub_080CD1F8(arg0,0x24,uVar7 & 0xffff);
      uVar7 = uVar7 + 0xe;
      iVar9 = iVar9 + 1;
    }
    uVar5 = uVar5 + 1;
    if (6 < uVar5) break;
    bVar1 = pbVar8[uVar5];
  }
  if (uVar7 != uVar6) {
    _DAT_0203a468 = (short)uVar6 + -8;
  }
  iVar9 = -iVar9;
  if ((iVar9 != -7) && (uVar6 = 0, iVar9 != -7)) {
    do {
      Text_DrawStringTinted(0x84f01a2,0x200f874,0x24,uVar7 & 0xffff);
      uVar7 = uVar7 + 0xe;
      uVar6 = uVar6 + 1;
    } while (uVar6 < iVar9 + 7U);
  }
  return;
}


// Status_DrawDropItem @ 0x080CBA7C

void Status_DrawDropItem(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = sub_080C92C8((uint)DAT_0203a456);
  iVar2 = sub_080BF648((uint)*(ushort *)(iVar1 + 0x12));
  uVar3 = (uint)*(ushort *)(iVar2 + 0x1a);
  sub_080CD2A0((uint)*(ushort *)(iVar1 + 0x12),0xc,0x1c);
  if ((uVar3 & 0xff) == 0xff) {
    Font_DrawGlyphTinted(0xea,0x200f874,0xc,0x49);
    Font_DrawGlyphTinted(0xeb,0x200f874,0x18,0x49);
    Font_DrawGlyphTinted(0xe5,0x200f874,0x30,0x49);
    Font_DrawGlyphTinted(0xf0,0x200f874,0x3c,0x49);
    Font_DrawGlyphTinted(0xe1,0x200f874,0x48,0x49);
    Font_DrawGlyphTinted(0xe9,0x200f874,0x54,0x49);
  }
  else if (uVar3 < 0xd0) {
    sub_080CD100(uVar3 & 0xff,0xc,0x49,6);
  }
  else {
    sub_080CD1A0(uVar3 & 0x1ff,0xc,0x49,6);
  }
  return;
}


// sub_080CBB34 @ 0x080CBB34

void sub_080CBB34(void)

{
  sub_080C92C8((uint)DAT_0203a456);
  Font_DrawGlyph(0x8f1,0x200f874,0xb2,0x1c);
  Font_DrawGlyph(0x861,0x200f874,0xbe,0x1c);
  Font_DrawGlyph(0xffe,0x200f874,0xb2,0x29);
  Font_DrawGlyph(0xcd3,0x200f874,0xbe,0x29);
  Font_DrawGlyph(0x8f1,0x200f874,0xb2,0x36);
  Font_DrawGlyph(0x861,0x200f874,0xbe,0x36);
  Font_DrawGlyph(0xffe,0x200f874,0xb2,0x43);
  Font_DrawGlyph(0xcd3,0x200f874,0xbe,0x43);
  Font_DrawGlyph(0xfa9,0x200f874,0xa4,0x50);
  Font_DrawGlyph(0x8c3,0x200f874,0xb0,0x50);
  Font_DrawGlyph(0x699,0x200f874,0xa4,0x5d);
  Font_DrawGlyph(0xeb7,0x200f874,0xb0,0x5d);
  Font_DrawGlyph(0xfc3,0x200f874,0xa4,0x6a);
  Font_DrawGlyph(0xf81,0x200f874,0xb0,0x6a);
  Font_DrawGlyph(0x5bb,0x200f874,0xbc,0x6a);
  Font_DrawGlyph(0x10cb,0x200f874,200,0x6a);
  Font_DrawGlyph(0xfc3,0x200f874,0xa4,0x77);
  Font_DrawGlyph(0xf81,0x200f874,0xb0,0x77);
  Font_DrawGlyph(0x8d7,0x200f874,0xbc,0x77);
  Font_DrawGlyph(0x672,0x200f874,200,0x77);
  return;
}


// sub_080CBC8C @ 0x080CBC8C

void sub_080CBC8C(void)

{
  int arg0;
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0 = sub_080C92C8((uint)DAT_0203a456);
  iVar1 = sub_080C9388((uint)DAT_0203a456);
  if (iVar1 == 1) {
    sub_080CBB34();
    sub_080CCFC4((int)*(short *)(arg0 + 0x48),0xe6,0x1f,4);
    sub_080CCFC4((int)*(short *)(arg0 + 0x4a),0xe6,0x2c,4);
    sub_080CCFC4((int)*(short *)(arg0 + 0x4c),0xe6,0x39,4);
    sub_080CCFC4((int)*(short *)(arg0 + 0x4e),0xe6,0x46,4);
    sub_080CCFC4((int)*(short *)(arg0 + 0x50),0xe6,0x53,4);
    sub_080CCFC4((int)*(short *)(arg0 + 0x52),0xe6,0x60,4);
    sub_080CCFC4((int)*(short *)(arg0 + 0x54),0xe6,0x6d,4);
    sub_080CCFC4((int)*(short *)(arg0 + 0x56),0xe6,0x7a,4);
  }
  else {
    uVar2 = sub_08154968((uint)*(ushort *)(arg0 + 0x12));
    uVar2 = uVar2 & 0xffff;
    if (uVar2 == 0x93) {
      Font_DrawGlyph(0xfa9,0x200f874,0xa4,0x1c);
      Font_DrawGlyph(0x8c3,0x200f874,0xb0,0x1c);
      sub_080CD668(0x93,0xce,0x1f,4);
      Font_DrawGlyph(0x699,0x200f874,0xa4,0x29);
      Font_DrawGlyph(0xeb7,0x200f874,0xb0,0x29);
      sub_080CD6C4(0x93,0xce,0x2c,4);
      Font_DrawGlyph(0xc1a,0x200f874,0xa4,0x36);
      Font_DrawGlyph(0xb7e,0x200f874,0xb0,0x36);
      Font_DrawGlyphTinted(0xb32,0x200f874,0xbe,0x36);
      Font_DrawGlyphTinted(0xb8c,0x200f874,0xca,0x36);
      Font_DrawGlyphTinted(0xfa9,0x200f874,0xd6,0x36);
      Font_DrawGlyphTinted(0x811,0x200f874,0xe2,0x36);
      Font_DrawGlyph(0xc3e,0x200f874,0xa4,0x43);
      Font_DrawGlyph(0xb7e,0x200f874,0xb0,0x43);
      uVar2 = 0x93;
    }
    else if (uVar2 == 0xa7) {
      Font_DrawGlyph(0xfa9,0x200f874,0xa4,0x1c);
      Font_DrawGlyph(0x8c3,0x200f874,0xb0,0x1c);
      sub_080CD668(0xa7,0xce,0x1f,4);
      Font_DrawGlyph(0x699,0x200f874,0xa4,0x29);
      Font_DrawGlyph(0xeb7,0x200f874,0xb0,0x29);
      sub_080CD6C4(0xa7,0xce,0x2c,4);
      Font_DrawGlyph(0xc1a,0x200f874,0xa4,0x36);
      Font_DrawGlyph(0xb7e,0x200f874,0xb0,0x36);
      Font_DrawGlyphTinted(0xc5e,0x200f874,0xbe,0x36);
      Font_DrawGlyphTinted(0xd6e,0x200f874,0xca,0x36);
      Font_DrawGlyphTinted(5,0x200f874,0xd6,0x36);
      Font_DrawGlyphTinted(0xaeb,0x200f874,0xe2,0x36);
      Font_DrawGlyph(0xc3e,0x200f874,0xa4,0x43);
      Font_DrawGlyph(0xb7e,0x200f874,0xb0,0x43);
      uVar2 = 0xa7;
    }
    else if (uVar2 == 0xbb) {
      Font_DrawGlyph(0xfa9,0x200f874,0xa4,0x1c);
      Font_DrawGlyph(0x8c3,0x200f874,0xb0,0x1c);
      sub_080CD668(0xbb,0xce,0x1f,4);
      Font_DrawGlyph(0x699,0x200f874,0xa4,0x29);
      Font_DrawGlyph(0xeb7,0x200f874,0xb0,0x29);
      sub_080CD6C4(0xbb,0xce,0x2c,4);
      Font_DrawGlyph(0xc1a,0x200f874,0xa4,0x36);
      Font_DrawGlyph(0xb7e,0x200f874,0xb0,0x36);
      Font_DrawGlyphTinted(0xc5e,0x200f874,0xca,0x36);
      Font_DrawGlyphTinted(0xedc,0x200f874,0xd6,0x36);
      Font_DrawGlyphTinted(0x86a,0x200f874,0xe2,0x36);
      Font_DrawGlyph(0xc3e,0x200f874,0xa4,0x43);
      Font_DrawGlyph(0xb7e,0x200f874,0xb0,0x43);
      uVar2 = 0xbb;
    }
    else if (uVar2 == 0xcf) {
      Font_DrawGlyph(0xfa9,0x200f874,0xa4,0x1c);
      Font_DrawGlyph(0x8c3,0x200f874,0xb0,0x1c);
      sub_080CD668(0xcf,0xce,0x1f,4);
      Font_DrawGlyph(0x699,0x200f874,0xa4,0x29);
      Font_DrawGlyph(0xeb7,0x200f874,0xb0,0x29);
      sub_080CD6C4(0xcf,0xce,0x2c,4);
      Font_DrawGlyph(0xc1a,0x200f874,0xa4,0x36);
      Font_DrawGlyph(0xb7e,0x200f874,0xb0,0x36);
      Font_DrawGlyphTinted(0xc5e,0x200f874,0xca,0x36);
      Font_DrawGlyphTinted(0x676,0x200f874,0xd6,0x36);
      Font_DrawGlyphTinted(0x632,0x200f874,0xe2,0x36);
      Font_DrawGlyph(0xc3e,0x200f874,0xa4,0x43);
      Font_DrawGlyph(0xb7e,0x200f874,0xb0,0x43);
      uVar2 = 0xcf;
    }
    else {
      iVar1 = sub_080C92AC((uint)*(ushort *)(arg0 + 0x12));
      if (iVar1 != 1) {
        iVar1 = sub_080C99B8(arg0);
        if (iVar1 == 1) {
          Font_DrawGlyph(0x8f1,0x200f874,0xa4,0x1c);
          Font_DrawGlyph(0x861,0x200f874,0xb0,0x1c);
          sub_080CCEC8(0x84f01b4,0xd6,0x1f,4);
          Font_DrawGlyph(0xffe,0x200f874,0xa4,0x29);
          Font_DrawGlyph(0xcd3,0x200f874,0xb0,0x29);
          sub_080CCEC8(0x84f01b4,0xd6,0x2c,4);
          Font_DrawGlyph(0xfa9,0x200f874,0xa4,0x36);
          Font_DrawGlyph(0x8c3,0x200f874,0xb0,0x36);
          sub_080CCEC8(0x84f01b4,0xd6,0x39,4);
          Font_DrawGlyph(0x699,0x200f874,0xa4,0x43);
          Font_DrawGlyph(0xeb7,0x200f874,0xb0,0x43);
          sub_080CCEC8(0x84f01b4,0xd6,0x46,4);
          Font_DrawGlyph(0xfc3,0x200f874,0xa4,0x50);
          Font_DrawGlyph(0xf81,0x200f874,0xb0,0x50);
          Font_DrawGlyph(0x5bb,0x200f874,0xbc,0x50);
          Font_DrawGlyph(0x10cb,0x200f874,200,0x50);
          sub_080CCEC8(0x84f01b4,0xd6,0x53,4);
          Font_DrawGlyph(0xfc3,0x200f874,0xa4,0x5d);
          Font_DrawGlyph(0xf81,0x200f874,0xb0,0x5d);
          Font_DrawGlyph(0x8d7,0x200f874,0xbc,0x5d);
          Font_DrawGlyph(0x672,0x200f874,200,0x5d);
          sub_080CCEC8(0x84f01b4,0xd6,0x60,4);
        }
        else {
          if (DAT_0203a454 == 7) {
            arg0 = sub_080C3560((uint)*(ushort *)(arg0 + 0x12));
          }
          Font_DrawGlyph(0x8f1,0x200f874,0xa4,0x1c);
          Font_DrawGlyph(0x861,0x200f874,0xb0,0x1c);
          sub_080CCFC4((int)*(short *)(arg0 + 0x48),0xe6,0x1f,4);
          Font_DrawGlyph(0xffe,0x200f874,0xa4,0x29);
          Font_DrawGlyph(0xcd3,0x200f874,0xb0,0x29);
          sub_080CCFC4((int)*(short *)(arg0 + 0x4a),0xe6,0x2c,4);
          Font_DrawGlyph(0xfa9,0x200f874,0xa4,0x36);
          Font_DrawGlyph(0x8c3,0x200f874,0xb0,0x36);
          sub_080CCFC4((int)*(short *)(arg0 + 0x50),0xe6,0x39,4);
          Font_DrawGlyph(0x699,0x200f874,0xa4,0x43);
          Font_DrawGlyph(0xeb7,0x200f874,0xb0,0x43);
          sub_080CCFC4((int)*(short *)(arg0 + 0x52),0xe6,0x46,4);
          Font_DrawGlyph(0xfc3,0x200f874,0xa4,0x50);
          Font_DrawGlyph(0xf81,0x200f874,0xb0,0x50);
          Font_DrawGlyph(0x5bb,0x200f874,0xbc,0x50);
          Font_DrawGlyph(0x10cb,0x200f874,200,0x50);
          sub_080CCFC4((int)*(short *)(arg0 + 0x54),0xe6,0x53,4);
          Font_DrawGlyph(0xfc3,0x200f874,0xa4,0x5d);
          Font_DrawGlyph(0xf81,0x200f874,0xb0,0x5d);
          Font_DrawGlyph(0x8d7,0x200f874,0xbc,0x5d);
          Font_DrawGlyph(0x672,0x200f874,200,0x5d);
          sub_080CCFC4((int)*(short *)(arg0 + 0x56),0xe6,0x60,4);
        }
        goto LAB_080cc46a;
      }
      uVar2 = sub_08154968((uint)*(ushort *)(arg0 + 0x12));
      uVar2 = uVar2 & 0xffff;
      Font_DrawGlyph(0x8f1,0x200f874,0xa4,0x1c);
      Font_DrawGlyph(0x861,0x200f874,0xb0,0x1c);
      sub_080CD330(uVar2,0xce,0x1f,4);
      Font_DrawGlyph(0xffe,0x200f874,0xa4,0x29);
      Font_DrawGlyph(0xcd3,0x200f874,0xb0,0x29);
      sub_080CD38C(uVar2,0xce,0x2c,4);
      Font_DrawGlyph(0x8f1,0x200f874,0xa4,0x36);
      Font_DrawGlyph(0x861,0x200f874,0xb0,0x36);
      Font_DrawGlyph(0x699,0x200f874,0xbc,0x36);
      Font_DrawGlyph(0xb67,0x200f874,200,0x36);
      sub_080CD3E8(uVar2,0xd6,0x39,4);
      Font_DrawGlyph(0xc3e,0x200f874,0xa4,0x43);
      Font_DrawGlyph(0xb7e,0x200f874,0xb0,0x43);
    }
    sub_080CD45C(uVar2,0xd6,0x46);
  }
LAB_080cc46a:
                    /* WARNING: Could not recover jumptable at 0x080cc474. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CC4B4 @ 0x080CC4B4

void sub_080CC4B4(int arg0)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080C92C8((uint)DAT_0203a456);
  uVar3 = 4;
  if (*(short *)(arg0 + 0x48) < *(short *)(iVar2 + 0x48)) {
    uVar3 = 8;
  }
  else if (*(short *)(iVar2 + 0x48) < *(short *)(arg0 + 0x48)) {
    uVar3 = 10;
  }
  sub_080CCFC4((int)*(short *)(iVar2 + 0x48),0xe6,0x1f,uVar3);
  uVar3 = 4;
  sVar1 = *(short *)(iVar2 + 0x4a);
  if (*(short *)(arg0 + 0x4a) < sVar1) {
    uVar3 = 8;
  }
  else if (sVar1 < *(short *)(arg0 + 0x4a)) {
    uVar3 = 10;
  }
  sub_080CCFC4((int)*(short *)(iVar2 + 0x4a),0xe6,0x2c,uVar3);
  uVar3 = 4;
  sVar1 = *(short *)(iVar2 + 0x4c);
  if (*(short *)(arg0 + 0x4c) < sVar1) {
    uVar3 = 8;
  }
  else if (sVar1 < *(short *)(arg0 + 0x4c)) {
    uVar3 = 10;
  }
  sub_080CCFC4((int)*(short *)(iVar2 + 0x4c),0xe6,0x39,uVar3);
  uVar3 = 4;
  sVar1 = *(short *)(iVar2 + 0x4e);
  if (*(short *)(arg0 + 0x4e) < sVar1) {
    uVar3 = 8;
  }
  else if (sVar1 < *(short *)(arg0 + 0x4e)) {
    uVar3 = 10;
  }
  sub_080CCFC4((int)*(short *)(iVar2 + 0x4e),0xe6,0x46,uVar3);
  uVar3 = 4;
  sVar1 = *(short *)(iVar2 + 0x50);
  if (*(short *)(arg0 + 0x50) < sVar1) {
    uVar3 = 8;
  }
  else if (sVar1 < *(short *)(arg0 + 0x50)) {
    uVar3 = 10;
  }
  sub_080CCFC4((int)*(short *)(iVar2 + 0x50),0xe6,0x53,uVar3);
  uVar3 = 4;
  sVar1 = *(short *)(iVar2 + 0x52);
  if (*(short *)(arg0 + 0x52) < sVar1) {
    uVar3 = 8;
  }
  else if (sVar1 < *(short *)(arg0 + 0x52)) {
    uVar3 = 10;
  }
  sub_080CCFC4((int)*(short *)(iVar2 + 0x52),0xe6,0x60,uVar3);
  uVar3 = 4;
  sVar1 = *(short *)(iVar2 + 0x54);
  if (*(short *)(arg0 + 0x54) < sVar1) {
    uVar3 = 8;
  }
  else if (sVar1 < *(short *)(arg0 + 0x54)) {
    uVar3 = 10;
  }
  sub_080CCFC4((int)*(short *)(iVar2 + 0x54),0xe6,0x6d,uVar3);
  uVar3 = 4;
  sVar1 = *(short *)(iVar2 + 0x56);
  if (*(short *)(arg0 + 0x56) < sVar1) {
    uVar3 = 8;
  }
  else if (sVar1 < *(short *)(arg0 + 0x56)) {
    uVar3 = 10;
  }
  sub_080CCFC4((int)*(short *)(iVar2 + 0x56),0xe6,0x7a,uVar3);
                    /* WARNING: Could not recover jumptable at 0x080cc62e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CC630 @ 0x080CC630

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CC630(void)

{
  int arg0;
  
  arg0 = sub_080C92C8((uint)DAT_0203a456);
  CpuSet(arg0,&DAT_0203a528,0x4000020);
  sub_080C0074((uint)*(byte *)(arg0 + 0xc),(uint)_DAT_0203a484,
               (uint)*(ushort *)(((uint)_DAT_0203a480 + (uint)DAT_0203a482) * 2 + 0x203b454));
  sub_080BF938((uint)*(byte *)(arg0 + 0xc));
  sub_080CC4B4(&DAT_0203a528);
  CpuSet(&DAT_0203a528,arg0,0x4000020);
  return;
}


// sub_080CC694 @ 0x080CC694

void sub_080CC694(void)

{
  int arg0;
  undefined4 uVar1;
  
  arg0 = sub_080C92C8((uint)DAT_0203a456);
  sub_080BF938((uint)*(byte *)(arg0 + 0xc));
  *(undefined2 *)(arg0 + 0x18) = *(undefined2 *)(arg0 + 0x1a);
  *(undefined2 *)(arg0 + 0x1c) = *(undefined2 *)(arg0 + 0x1e);
  if (DAT_0203a454 == 5) {
    CpuSet(arg0,&DAT_0203a4a8,0x4000020);
    *(undefined1 *)(arg0 + 0x20) = 0xff;
    *(undefined1 *)(arg0 + 0x21) = 0xff;
    *(undefined1 *)(arg0 + 0x22) = 0xff;
    *(undefined1 *)(arg0 + 0x23) = 0xff;
    *(undefined1 *)(arg0 + 0x24) = 0xff;
    *(undefined1 *)(arg0 + 0x25) = 0xff;
    *(undefined1 *)(arg0 + 0x26) = 0xff;
    *(undefined1 *)(arg0 + 0x27) = 0xff;
    sub_080BF938((uint)*(byte *)(arg0 + 0xc));
    sub_080CC4B4(&DAT_0203a5a8);
  }
  else {
    sub_080CC4B4(&DAT_0203a528);
  }
  sub_080AC7CC(0,0x200f874,0x40,0x1c);
  uVar1 = 4;
  if (DAT_0203a542 < *(short *)(arg0 + 0x1a)) {
    uVar1 = 8;
  }
  else if (*(short *)(arg0 + 0x1a) < DAT_0203a542) {
    uVar1 = 10;
  }
  sub_080CCF44((int)*(short *)(arg0 + 0x18),0x60,0x20,uVar1);
  sub_080CCE5C(0x84f00dc,0x68,0x20,uVar1);
  sub_080CCF44((int)*(short *)(arg0 + 0x1a),0x80,0x20,uVar1);
  uVar1 = 4;
  if (DAT_0203a546 < *(short *)(arg0 + 0x1e)) {
    uVar1 = 8;
  }
  else if (*(short *)(arg0 + 0x1e) < DAT_0203a546) {
    uVar1 = 10;
  }
  sub_080CCF44((int)*(short *)(arg0 + 0x1c),0x60,0x2c,uVar1);
  sub_080CCE5C(0x84f00dc,0x68,0x2c,uVar1);
  sub_080CCF44((int)*(short *)(arg0 + 0x1e),0x80,0x2c,uVar1);
  if (DAT_0203a454 == 5) {
    CpuSet(&DAT_0203a4a8,arg0,0x4000020);
  }
  return;
}


// sub_080CC7D4 @ 0x080CC7D4

void sub_080CC7D4(void)

{
  Font_DrawGlyph(0x10cb,0x200f874,8,0x8a);
  Font_DrawGlyph(0xcba,0x200f874,0x55,0x8a);
  Font_DrawGlyph(0xfc3,0x200f874,0xa2,0x8a);
  Font_DrawGlyph(0xc5c,0x200f874,8,0x98);
  Font_DrawGlyph(0xc3c,0x200f874,0x55,0x98);
  Font_DrawGlyph(0x606,0x200f874,0xa2,0x98);
  return;
}


// sub_080CC844 @ 0x080CC844

void sub_080CC844(void)

{
  ushort uVar1;
  int arg0;
  int iVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0 = sub_080C92C8((uint)DAT_0203a456);
  sub_080CC7D4();
  iVar2 = sub_080C92AC((uint)*(ushort *)(arg0 + 0x12));
  if ((iVar2 == 1) || (iVar2 = sub_080C99B8(arg0), iVar2 == 0)) {
    uVar1 = *(ushort *)(arg0 + 0x10);
    if (DAT_0203a454 == 7) {
      iVar2 = sub_080C3560((uint)*(ushort *)(arg0 + 0x12));
      uVar1 = *(ushort *)(iVar2 + 0x10);
    }
    if ((uVar1 & 0x800) == 0) {
      uVar3 = (uint)(char)(*(byte *)(arg0 + 0x28) ^ *(byte *)(arg0 + 0x40));
      sub_080CCFC4((int)(char)*(byte *)(arg0 + 0x40),0x48,0x8d,(int)(-uVar3 | uVar3) >> 0x1f & 8);
      uVar3 = (uint)(char)(*(byte *)(arg0 + 0x29) ^ *(byte *)(arg0 + 0x41));
      sub_080CCFC4((int)(char)*(byte *)(arg0 + 0x41),0x95,0x8d,(int)(-uVar3 | uVar3) >> 0x1f & 8);
      uVar3 = (uint)(char)(*(byte *)(arg0 + 0x2a) ^ *(byte *)(arg0 + 0x42));
      sub_080CCFC4((int)(char)*(byte *)(arg0 + 0x42),0xe2,0x8d,(int)(-uVar3 | uVar3) >> 0x1f & 8);
      uVar3 = (uint)(char)(*(byte *)(arg0 + 0x2b) ^ *(byte *)(arg0 + 0x43));
      sub_080CCFC4((int)(char)*(byte *)(arg0 + 0x43),0x48,0x9a,(int)(-uVar3 | uVar3) >> 0x1f & 8);
      uVar3 = (uint)(char)(*(byte *)(arg0 + 0x2c) ^ *(byte *)(arg0 + 0x44));
      sub_080CCFC4((int)(char)*(byte *)(arg0 + 0x44),0x95,0x9a,(int)(-uVar3 | uVar3) >> 0x1f & 8);
      uVar3 = (uint)(char)(*(byte *)(arg0 + 0x2d) ^ *(byte *)(arg0 + 0x45));
      sub_080CCFC4((int)(char)*(byte *)(arg0 + 0x45),0xe2,0x9a,(int)(-uVar3 | uVar3) >> 0x1f & 8);
    }
    else {
      sub_080CCFC4(1,0x48,0x8d,0);
      sub_080CCFC4(1,0x95,0x8d,0);
      sub_080CCFC4(1,0xe2,0x8d,0);
      sub_080CCFC4(1,0x48,0x9a,0);
      sub_080CCFC4(0x28,0x95,0x9a,0);
      sub_080CCFC4(1,0xe2,0x9a,0);
    }
  }
  else {
    sub_080CCEC8(0x84efad8,0x3f,0x8d,0);
    sub_080CCEC8(0x84efad8,0x8c,0x8d,0);
    sub_080CCEC8(0x84efad8,0xd9,0x8d,0);
    sub_080CCEC8(0x84efad8,0x3f,0x9a,0);
    sub_080CCEC8(0x84efad8,0x8c,0x9a,0);
    sub_080CCEC8(0x84efad8,0xd9,0x9a,0);
  }
                    /* WARNING: Could not recover jumptable at 0x080cca0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CCA10 @ 0x080CCA10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CCA10(void)

{
  int iVar1;
  dword arg0;
  undefined4 arg1;
  undefined4 arg2;
  
  sub_080C92C8((uint)DAT_0203a456);
  iVar1 = sub_080C93B4((uint)DAT_0203a456);
  if (iVar1 == 1) {
    sub_080CCE5C(0x84f01b8,10,0x8e,0);
    sub_080CCE5C(0x84f01c0,0x42,0x8e,0);
    sub_080CCE5C(0x84f01c8,10,0x9a,0);
    sub_080CCE5C(0x84f01c0,0x42,0x9a,0);
    sub_080CCE5C(0x84f01d0,0x88,0x8e,0);
    sub_080CCE5C(0x84f01c0,0xc0,0x8e,0);
    arg0 = 0x84f01d8;
    arg1 = 0x88;
    arg2 = 0x9a;
  }
  else {
    iVar1 = sub_080C9388((uint)DAT_0203a456);
    if (iVar1 != 1) {
      return;
    }
    arg0 = 0x84f01e4;
    arg1 = 10;
    arg2 = 0x8e;
  }
  sub_080CCE5C(arg0,arg1,arg2,0);
  _DAT_0203a480 = 0;
  return;
}


// sub_080CCAB4 @ 0x080CCAB4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080CCAB4(void)

{
  uint arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080C92C8((uint)DAT_0203a456);
  arg0 = (uint)*(ushort *)(((uint)_DAT_0203a480 + (uint)DAT_0203a482) * 2 + 0x203b454);
  if (arg0 < 0x80) {
    Font_DrawGlyph(0x8f1,0x200f874,9,0x8b);
    Font_DrawGlyph(0x861,0x200f874,0x15,0x8b);
    sub_080CD330(arg0,0x24,0x8e,4);
    Font_DrawGlyph(0xffe,0x200f874,9,0x98);
    Font_DrawGlyph(0xcd3,0x200f874,0x15,0x98);
    sub_080CD38C(arg0,0x24,0x9b,4);
    Font_DrawGlyph(0x8f1,0x200f874,0x49,0x8b);
    Font_DrawGlyph(0x861,0x200f874,0x55,0x8b);
    Font_DrawGlyph(0x699,0x200f874,0x61,0x8b);
    Font_DrawGlyph(0xb67,0x200f874,0x6d,0x8b);
    sub_080CD3E8(arg0,0x95,0x8e,4);
    if ((arg0 - 0x58 & 0xffff) < 0x18) {
      Font_DrawGlyph(0xd14,0x200f874,0x49,0x98);
      Font_DrawGlyph(0x669,0x200f874,0x55,0x98);
      Font_DrawGlyph(0x8d7,0x200f874,0x61,0x98);
      Font_DrawGlyph(0x672,0x200f874,0x6d,0x98);
      sub_080CCEC8(0x84f01ec,0x7e,0x9b,4);
    }
    else {
      Font_DrawGlyph(0xd14,0x200f874,0x49,0x98);
      Font_DrawGlyph(0x669,0x200f874,0x55,0x98);
      Font_DrawGlyph(0x8d7,0x200f874,0x61,0x98);
      Font_DrawGlyph(0x672,0x200f874,0x6d,0x98);
      sub_080CD50C(arg0,0x7e,0x9b);
    }
    Font_DrawGlyph(0xc3e,0x200f874,0xb2,0x8b);
    Font_DrawGlyph(0xb7e,0x200f874,0xbe,0x8b);
    sub_080CD45C(arg0,0xcc,0x8e);
  }
  else {
    Font_DrawGlyph(0xfa9,0x200f874,9,0x8b);
    Font_DrawGlyph(0x8c3,0x200f874,0x15,0x8b);
    sub_080CD668(arg0,0x24,0x8e,4);
    Font_DrawGlyph(0x699,0x200f874,9,0x98);
    Font_DrawGlyph(0xeb7,0x200f874,0x15,0x98);
    sub_080CD6C4(arg0,0x24,0x9b,4);
    Font_DrawGlyph(0xc1a,0x200f874,0x49,0x8b);
    Font_DrawGlyph(0xb7e,0x200f874,0x55,0x8b);
    sub_080CD87C(arg0,0x65,0x8b);
    Font_DrawGlyph(0xd14,0x200f874,0x49,0x98);
    Font_DrawGlyph(0x669,0x200f874,0x55,0x98);
    Font_DrawGlyph(0x8d7,0x200f874,0x61,0x98);
    Font_DrawGlyph(0x672,0x200f874,0x6d,0x98);
    sub_080CD720(arg0,0x7e,0x9b);
    Font_DrawGlyph(0xc3e,0x200f874,0xb3,0x8b);
    Font_DrawGlyph(0xb7e,0x200f874,0xbe,0x8b);
    sub_080CD45C(arg0,0xcc,0x8e);
  }
                    /* WARNING: Could not recover jumptable at 0x080ccd2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080CCD5C @ 0x080CCD5C

void sub_080CCD5C(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_080C92C8((uint)DAT_0203a456);
  sub_080CC7D4();
  uVar2 = (uint)(char)(*(byte *)(iVar1 + 0x28) ^ *(byte *)(iVar1 + 0x40));
  sub_080CCFC4((int)(char)*(byte *)(iVar1 + 0x40),0x48,0x8d,(int)(-uVar2 | uVar2) >> 0x1f & 8);
  uVar2 = (uint)(char)(*(byte *)(iVar1 + 0x29) ^ *(byte *)(iVar1 + 0x41));
  sub_080CCFC4((int)(char)*(byte *)(iVar1 + 0x41),0x95,0x8d,(int)(-uVar2 | uVar2) >> 0x1f & 8);
  uVar2 = (uint)(char)(*(byte *)(iVar1 + 0x2a) ^ *(byte *)(iVar1 + 0x42));
  sub_080CCFC4((int)(char)*(byte *)(iVar1 + 0x42),0xe2,0x8d,(int)(-uVar2 | uVar2) >> 0x1f & 8);
  uVar2 = (uint)(char)(*(byte *)(iVar1 + 0x2b) ^ *(byte *)(iVar1 + 0x43));
  sub_080CCFC4((int)(char)*(byte *)(iVar1 + 0x43),0x48,0x9a,(int)(-uVar2 | uVar2) >> 0x1f & 8);
  uVar2 = (uint)(char)(*(byte *)(iVar1 + 0x2c) ^ *(byte *)(iVar1 + 0x44));
  sub_080CCFC4((int)(char)*(byte *)(iVar1 + 0x44),0x95,0x9a,(int)(-uVar2 | uVar2) >> 0x1f & 8);
  uVar2 = (uint)(char)(*(byte *)(iVar1 + 0x2d) ^ *(byte *)(iVar1 + 0x45));
  sub_080CCFC4((int)(char)*(byte *)(iVar1 + 0x45),0xe2,0x9a,(int)(-uVar2 | uVar2) >> 0x1f & 8);
  return;
}


// sub_080CCE5C @ 0x080CCE5C

void sub_080CCE5C(byte *arg0,int arg1,uint arg2,undefined4 arg3)

{
  uint arg0_00;
  uint uVar1;
  uint uVar2;
  
  if (*arg0 != 0) {
    uVar2 = arg1 << 0x10;
    do {
      uVar1 = (uint)*arg0;
      arg0_00 = (uint)*(ushort *)((uVar1 - 0x2b) * 2 + 0x84f01f4);
      if (uVar1 == 0x3f) {
        arg0_00 = 0x13;
      }
      if (uVar1 == 0x2d) {
        arg0_00 = 6;
      }
      sub_080ACA74(arg0_00,0x200f874,uVar2 >> 0x10,arg2 & 0xffff);
      uVar2 = uVar2 + 0x80000;
      arg0 = arg0 + 1;
    } while (*arg0 != 0);
  }
  return;
}


// sub_080CCEC8 @ 0x080CCEC8

void sub_080CCEC8(byte *arg0,uint arg1,uint arg2,undefined4 arg3)

{
  byte bVar1;
  uint arg0_00;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar1 = *arg0;
  while (bVar1 != 0) {
    uVar2 = (uint)*arg0;
    arg0_00 = (uint)*(ushort *)((uVar2 - 0x2b) * 2 + 0x84f0254);
    if (uVar2 == 0x3f) {
      arg0_00 = 0x1f;
    }
    if (uVar2 == 0x2d) {
      arg0_00 = 0xd;
    }
    if (uVar2 == 0x5c) {
      arg0_00 = 0x3e;
    }
    sub_080ACB78(arg0_00,0x200f874,(arg1 & 0xffff) + iVar3 & 0xffff,arg2 & 0xffff);
    iVar3 = iVar3 + 8;
    arg0 = arg0 + 1;
    bVar1 = *arg0;
  }
  return;
}


// sub_080CCF44 @ 0x080CCF44

void sub_080CCF44(undefined4 arg0,uint arg1,uint arg2,undefined4 arg3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = sub_080A9CC0(arg0);
  bVar1 = false;
  uVar4 = (arg1 & 0xffff) - 0x38;
  uVar5 = 0;
  do {
    uVar3 = (uint)*(byte *)((iVar2 + 7) - uVar5);
    if (((uVar5 == 7) || (bVar1)) || (uVar3 != 0)) {
      sub_080ACA74((uint)*(ushort *)((uVar3 + 5) * 2 + 0x84f01f4),0x200f874,uVar4 & 0xffff,
                   arg2 & 0xffff);
      bVar1 = true;
    }
    uVar4 = (uVar4 & 0xffff) + 8;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 8);
  return;
}


// sub_080CCFC4 @ 0x080CCFC4

void sub_080CCFC4(undefined4 arg0,uint arg1,uint arg2,undefined4 arg3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = sub_080A9CC0(arg0);
  bVar1 = false;
  uVar4 = (arg1 & 0xffff) - 0x38;
  uVar5 = 0;
  do {
    uVar3 = (uint)*(byte *)((iVar2 + 7) - uVar5);
    if (((uVar5 == 7) || (bVar1)) || (uVar3 != 0)) {
      sub_080ACB78((uint)*(ushort *)((uVar3 + 5) * 2 + 0x84f0254),0x200f874,uVar4 & 0xffff,
                   arg2 & 0xffff);
      bVar1 = true;
    }
    uVar4 = (uVar4 & 0xffff) + 8;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 8);
  return;
}


// sub_080CD044 @ 0x080CD044

void sub_080CD044(uint arg0,uint arg1,uint arg2)

{
  char *pcVar1;
  int iVar2;
  dword dVar3;
  uint uVar4;
  uint arg2_00;
  
  arg2_00 = arg2 & 0xffff;
  uVar4 = (arg1 & 0xffff) + 0x20;
  pcVar1 = (char *)sub_080BF648(arg0 & 0xffff);
  iVar2 = sub_0815B864();
  if (*pcVar1 < '\r') {
    dVar3 = 0x84f02b4;
  }
  else {
    if ('\x1a' < *pcVar1) {
      sub_080CCE5C(0x84f02bc,uVar4 & 0xffff,arg2_00,4);
      goto LAB_080cd09e;
    }
    dVar3 = 0x84f02b8;
  }
  sub_080CCE5C(dVar3,uVar4 & 0xffff,arg2_00,4);
LAB_080cd09e:
  uVar4 = (arg1 & 0xffff) + 0x30;
  if (iVar2 == 0) {
    dVar3 = 0x84f02c0;
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 != 2) {
        return;
      }
      sub_080CCE5C(0x84f02c8,uVar4 & 0xffff,arg2_00,4);
      return;
    }
    dVar3 = 0x84f02c4;
  }
  sub_080CCE5C(dVar3,uVar4 & 0xffff,arg2_00,4);
  return;
}


// sub_080CD0E4 @ 0x080CD0E4

void sub_080CD0E4(uint arg0)

{
  int iVar1;
  
  iVar1 = sub_080BF648(arg0 & 0xffff);
  sub_080CCF44((uint)*(byte *)(iVar1 + 0x1d),0x90,0x78,4);
  return;
}


// sub_080CD100 @ 0x080CD100

void sub_080CD100(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  int iVar1;
  uint arg2_00;
  ushort *puVar2;
  uint arg3_00;
  
  arg3_00 = arg2 & 0xffff;
  arg2_00 = arg1 & 0xffff;
  if ((arg0 & 0xffff) == 0xff) {
    Text_DrawStringTinted(0x84f02ca,0x200f874,arg2_00,arg3_00);
  }
  else {
    iVar1 = Equipment_GetRecord36_MidRange(arg0 & 0xffff);
    puVar2 = (ushort *)(iVar1 + 0x14);
    if (*(short *)(iVar1 + 0x14) == 0) {
      iVar1 = 7;
      do {
        Font_DrawGlyphTinted(0x3c,0x200f874,arg2_00 & 0xffff,arg3_00);
        arg2_00 = arg2_00 + 0xc;
        iVar1 = iVar1 + -1;
      } while (-1 < iVar1);
    }
    else {
      iVar1 = 7;
      do {
        Font_DrawGlyphTinted((uint)*puVar2,0x200f874,arg2_00 & 0xffff,arg3_00);
        arg2_00 = arg2_00 + 0xc;
        puVar2 = puVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (-1 < iVar1);
    }
  }
  return;
}


// sub_080CD1A0 @ 0x080CD1A0

void sub_080CD1A0(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  
  uVar3 = arg1 & 0xffff;
  iVar1 = Action_GetRecord(arg0 & 0xffff);
  puVar2 = (ushort *)(iVar1 + 0xc);
  if (*(short *)(iVar1 + 0xc) != 0) {
    iVar1 = 7;
    do {
      Font_DrawGlyphTinted((uint)*puVar2,0x200f874,uVar3 & 0xffff,arg2 & 0xffff);
      uVar3 = uVar3 + 0xc;
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (-1 < iVar1);
  }
  return;
}


// sub_080CD1F8 @ 0x080CD1F8

void sub_080CD1F8(uint arg0,uint arg1,uint arg2)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  
  uVar2 = arg1 & 0xffff;
  iVar1 = sub_080BF5C0(arg0 & 0xffff);
  puVar3 = (ushort *)(iVar1 + 6);
  if (*(short *)(iVar1 + 6) == 0) {
    iVar1 = 7;
    do {
      Font_DrawGlyphTinted(0x3c,0x200f874,uVar2 & 0xffff,arg2 & 0xffff);
      uVar2 = uVar2 + 0xc;
      iVar1 = iVar1 + -1;
    } while (-1 < iVar1);
  }
  else {
    iVar1 = 7;
    do {
      Font_DrawGlyph((uint)*puVar3,0x200f874,uVar2 & 0xffff,arg2 & 0xffff);
      uVar2 = uVar2 + 0xc;
      puVar3 = puVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (-1 < iVar1);
  }
  return;
}


// sub_080CD260 @ 0x080CD260

void sub_080CD260(uint arg0,uint arg1,uint arg2,uint arg3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = sub_080BF5C0(arg0 & 0xffff);
  bVar1 = *(byte *)(iVar2 + 3);
  if (bVar1 != 0) {
    sub_080CCEC8(0x84f00e0,arg1 & 0xffff,arg3 & 0xffff,0);
    sub_080CCFC4((uint)bVar1,arg2 & 0xffff,arg3 & 0xffff,0);
  }
  return;
}


// sub_080CD2A0 @ 0x080CD2A0

void sub_080CD2A0(uint arg0,uint arg1,uint arg2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  ushort *puVar6;
  
  uVar3 = arg1 & 0xffff;
  iVar2 = sub_080BF648(arg0 & 0xffff);
  puVar6 = (ushort *)(iVar2 + 0x32);
  iVar2 = sub_080BF648(arg0 & 0xffff);
  puVar4 = (ushort *)(iVar2 + 0x48);
  iVar2 = 10;
  uVar5 = uVar3;
  do {
    Font_DrawGlyph((uint)*puVar6,0x200f874,uVar5 & 0xffff,arg2 & 0xffff);
    uVar5 = uVar5 + 0xc;
    puVar6 = puVar6 + 1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  iVar2 = 0;
  uVar1 = *puVar4;
  while( true ) {
    if (uVar1 == 0) {
      return;
    }
    Font_DrawGlyph((uint)*puVar4,0x200f874,uVar3 & 0xffff,(arg2 & 0xffff) + 0xf & 0xffff);
    uVar3 = uVar3 + 0xc;
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + 1;
    if (10 < iVar2) break;
    uVar1 = *puVar4;
  }
  return;
}


// sub_080CD330 @ 0x080CD330

void sub_080CD330(uint arg0,uint arg1,uint arg2,uint arg3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = sub_080BF32C(arg0 & 0xffff);
  bVar1 = *(byte *)(iVar2 + 1);
  sub_080CCEC8(0x84f02dc,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  sub_080CCFC4((uint)bVar1,(arg1 & 0xffff) + 0x18 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  return;
}


// sub_080CD38C @ 0x080CD38C

void sub_080CD38C(uint arg0,uint arg1,uint arg2,uint arg3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = sub_080BF32C(arg0 & 0xffff);
  bVar1 = *(byte *)(iVar2 + 2);
  sub_080CCEC8(0x84f02dc,arg1 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  sub_080CCFC4((uint)bVar1,(arg1 & 0xffff) + 0x18 & 0xffff,arg2 & 0xffff,arg3 & 0xffff);
  return;
}


