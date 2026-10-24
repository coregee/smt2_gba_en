/* Ghidra decompilation of asm/code_080B04BC.s (reference only; not compiled). */

// sub_080B04BC @ 0x080B04BC

void sub_080B04BC(void)

{
  int iVar1;
  
  iVar1 = sub_080B3078(0,0,6);
  if (iVar1 == 0) {
    DAT_030029b0 = *DAT_03004630;
    sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
    sub_080ACFCC(3,DAT_03004510,&DAT_03002b50,0x20);
    if (DAT_030020e4 != 0x80d977d) {
      sub_080ACFCC(3,DAT_03003fc8,&DAT_03002d50,0x20);
    }
  }
  else {
    DAT_030029b0 = DAT_0200f814;
    sub_080ACFCC(3,0x200f814,&DAT_03002b70,0x40);
    sub_080ACFCC(3,0x200f7f4,&DAT_03002b50,0x20);
    if (DAT_030020e4 != 0x80d977d) {
      sub_080ACFCC(3,0x200f854,&DAT_03002d50,0x20);
    }
  }
  return;
}


// sub_080B05A4 @ 0x080B05A4

void sub_080B05A4(void)

{
  int iVar1;
  undefined4 arg2;
  
  arg2 = 1;
  iVar1 = sub_080B098C();
  if (iVar1 == 0) {
    DAT_0300452c = 0;
  }
  else {
    sub_080B04BC();
    iVar1 = sub_080C2340(0x105);
    if (iVar1 != 0) {
      sub_080C2364(0x102);
      sub_080C2364(0x106);
      arg2 = 4;
    }
    DAT_0300452c = sub_080AB090(0xd0,0x30,arg2,0x8001);
    sub_080AAFBC(0x1d0,0x10,arg2);
    if (DAT_030029b0 != 0) {
      sub_080AAFBC(0,1,arg2);
    }
  }
  return;
}


// sub_080B0620 @ 0x080B0620

void sub_080B0620(void)

{
  int iVar1;
  
  iVar1 = sub_080B098C();
  if (iVar1 == 1) {
    DAT_0300452c = 0;
  }
  else {
    DAT_0300452c = sub_080AB158(0xd0,0x30,1,0x8001);
    sub_080AB0F0(0x1d0,0x10,1);
    if (DAT_03002db0 != 0) {
      sub_080AB0F0(0,1,1);
    }
  }
  return;
}


// sub_080B0678 @ 0x080B0678

/* WARNING: Control flow encountered bad instruction data */

void sub_080B0678(void)

{
  undefined4 *in_r0;
  undefined4 *in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 unaff_r4;
  uint unaff_r5;
  undefined4 unaff_r6;
  undefined4 *unaff_r8;
  undefined4 *unaff_r10;
  int unaff_r11;
  undefined4 in_lr;
  char in_NG;
  bool in_ZR;
  bool in_CY;
  bool in_OV;
  
  if ((bool)in_NG != in_OV) {
    unaff_r11 = (int)in_r1 + ((uint)in_r0 >> (unaff_r5 & 0xff));
  }
  if (in_OV) {
    *in_r1 = in_lr;
    in_r1[-1] = unaff_r11;
    in_r1[-2] = unaff_r4;
    in_r1[-3] = in_r3;
    in_r1[-4] = in_r1;
  }
  if (in_CY && !in_ZR) {
    *unaff_r8 = in_lr;
    unaff_r8[-1] = unaff_r11;
    unaff_r8[-2] = unaff_r10;
    unaff_r8[-3] = unaff_r8;
    unaff_r8[-4] = unaff_r4;
    unaff_r8[-5] = in_r3;
    unaff_r8[-6] = in_r1;
  }
  if (!in_ZR) {
    *unaff_r10 = unaff_r6;
  }
  if (!in_CY || in_ZR) {
    *in_r0 = in_r2;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// sub_080B06FC @ 0x080B06FC

/* WARNING: Control flow encountered bad instruction data */

void sub_080B06FC(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// sub_080B0778 @ 0x080B0778

void sub_080B0778(void)

{
  int iVar1;
  undefined4 arg0;
  int iVar2;
  undefined4 arg1;
  undefined4 arg2;
  
  arg2 = 1;
  iVar1 = sub_080B098C();
  if (iVar1 == 0) {
    DAT_0300452c = 0;
  }
  else {
    iVar1 = sub_080C2340(0x105);
    if (iVar1 != 0) {
      sub_080C2364(0x102);
      sub_080C2364(0x106);
      arg2 = 4;
    }
    if (DAT_03004534 == 0xda) {
      arg0 = 0x70;
      arg1 = 0x10;
    }
    else {
      arg0 = 0x80;
      arg1 = 0x80;
    }
    DAT_0300452c = sub_080AB090(arg0,arg1,arg2,0x8001);
    iVar1 = sub_080C2340(0x10d);
    if (iVar1 != 0) {
      *(undefined2 *)(DAT_0300452c + 2) = 8;
      sub_080C23BC(0x10d);
    }
    iVar2 = sub_080C2340(0xfd);
    iVar1 = DAT_0300452c;
    if (iVar2 != 0) {
      *(undefined2 *)(DAT_0300452c + 4) = 10;
      *(undefined2 *)(iVar1 + 6) = 10;
      sub_080C23BC(0xfd);
    }
  }
  return;
}


// sub_080B0820 @ 0x080B0820

void sub_080B0820(void)

{
  int iVar1;
  undefined4 arg0;
  undefined4 arg1;
  
  iVar1 = sub_080B098C();
  if (iVar1 == 1) {
    DAT_0300452c = 0;
  }
  else {
    if (DAT_03004534 == 0xda) {
      arg0 = 0x70;
      arg1 = 0x10;
    }
    else {
      arg0 = 0x80;
      arg1 = 0x80;
    }
    DAT_0300452c = sub_080AB158(arg0,arg1,1,0x8001);
    sub_080C3818(0);
    if (DAT_03002db0 != 0) {
      sub_080AB0F0(0,1,1);
    }
  }
  return;
}


// sub_080B0888 @ 0x080B0888

void sub_080B0888(void)

{
  if ((DAT_0200ab04 & 0x8000) == 0) {
    sub_080AB138(0xd0,0x30,1,6);
  }
  return;
}


// sub_080B08AC @ 0x080B08AC

void sub_080B08AC(void)

{
  undefined4 uVar1;
  undefined4 arg1;
  
  if ((DAT_0200ab04 & 0x8000) == 0) {
    sub_080B04BC();
    sub_080AB054(0xd0,0x30,1,0x10);
  }
  else {
    uVar1 = sub_080C5F60((uint)DAT_03004534);
    if (DAT_03004534 == 0xda) {
      sub_080ACFCC(3,uVar1,0x3002a90,0x20);
      uVar1 = 0x70;
      arg1 = 0x10;
    }
    else {
      sub_080ACFCC(3,uVar1,0x3002ab0,0x100);
      uVar1 = 0x80;
      arg1 = 0x80;
    }
    sub_080AB054(uVar1,arg1,1,0x10);
  }
  return;
}


// sub_080B092C @ 0x080B092C

uint sub_080B092C(void)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_0300452c == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = sub_080AB178(DAT_0300452c);
    uVar1 = uVar1 & 0xffff;
    if ((uVar1 == 0) && (iVar2 = sub_080C2340(0x105), iVar2 != 0)) {
      sub_080C23BC(0x102);
      sub_080C23BC(0x106);
      sub_080C23BC(0x105);
    }
  }
  return uVar1;
}


// sub_080B097C @ 0x080B097C

void sub_080B097C(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B092C();
  *(short *)(arg0 + 0x1e) = (short)uVar1;
  return;
}


// sub_080B098C @ 0x080B098C

undefined4 sub_080B098C(void)

{
  ushort uVar1;
  char *pcVar2;
  
  pcVar2 = (char *)0x3002f50;
  uVar1 = 0;
  do {
    if (*pcVar2 != '\0') {
      return 0;
    }
    uVar1 = uVar1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar1 < 0x20);
  return 1;
}


// sub_080B09B4 @ 0x080B09B4

void sub_080B09B4(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B098C();
  *(short *)(arg0 + 0x1e) = (short)uVar1;
  return;
}


// sub_080B09C4 @ 0x080B09C4

/* WARNING: Control flow encountered bad instruction data */

void sub_080B09C4(undefined4 *arg0,undefined4 arg1)

{
  int *unaff_r9;
  undefined4 unaff_r11;
  bool in_ZR;
  
  if (in_ZR) {
    *arg0 = unaff_r11;
    *unaff_r9 = (int)(arg0 + -0x14c);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// sub_080B0A08 @ 0x080B0A08

void sub_080B0A08(undefined4 arg0)

{
  int iVar1;
  
  iVar1 = sub_080B092C();
  if (iVar1 == 0) {
    DAT_0300457e = 0;
    DAT_03003ff4 = 1;
    iVar1 = sub_080AF8D0(2,2,0);
    if (iVar1 == 0) {
      if (DAT_03004596 == 1) {
        Field_SetState(1);
      }
      else {
        sub_080B03BC(1);
      }
    }
    DAT_03004596 = 0;
    DAT_03003ff4 = 0;
    if ((short)arg0 == 1) {
      sub_080AF5B8((uint)DAT_03004562,(uint)DAT_03004564,(uint)DAT_03004552);
    }
  }
  return;
}


// sub_080B0A78 @ 0x080B0A78

void sub_080B0A78(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 | 4;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 & 0xff;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 | 0x6724;
  uVar1 = REG_BG2CNT;
  REG_BG2CNT = uVar1 | 0x40;
  uVar1 = REG_BG3CNT;
  REG_BG3CNT = uVar1 | 0x40;
  return;
}


// sub_080B0ABC @ 0x080B0ABC

void sub_080B0ABC(void)

{
  ushort uVar1;
  
  uVar1 = REG_BG2CNT;
  REG_BG2CNT = uVar1 & 0xffbf;
  uVar1 = REG_BG3CNT;
  REG_BG3CNT = uVar1 & 0xffbf;
  return;
}


// sub_080B0AE0 @ 0x080B0AE0

void sub_080B0AE0(void)

{
  DAT_030020f8 = 0x80b0abd;
  sub_080A9C64(0x80b0a79,1);
  return;
}


// sub_080B0B00 @ 0x080B0B00

void sub_080B0B00(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 & 0xfffb;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 & 0xffdb;
  uVar1 = REG_BG2CNT;
  REG_BG2CNT = uVar1 & 0xffbf;
  uVar1 = REG_BG3CNT;
  REG_BG3CNT = uVar1 & 0xffbf;
  DAT_030020f8 = 0x80a9971;
  return;
}


// sub_080B0B54 @ 0x080B0B54

void sub_080B0B54(void)

{
  sub_080A9C64(0x80b0b01,1);
  return;
}


// sub_080B0B68 @ 0x080B0B68

void sub_080B0B68(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 | 2;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 | 0x10;
  return;
}


// sub_080B0B88 @ 0x080B0B88

void sub_080B0B88(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE._0_2_;
  REG_IE._0_2_ = uVar1 & 0xfffd;
  uVar1 = REG_DISPSTAT;
  REG_DISPSTAT = uVar1 & 0xffef;
  DAT_030020f4 = 0x80a9971;
  return;
}


// sub_080B0BBC @ 0x080B0BBC

void sub_080B0BBC(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = REG_VCOUNT._0_1_;
  uVar3 = (uint)bVar1;
  if (uVar3 < 100) {
    iVar2 = (int)*(short *)((DAT_030045a2 + uVar3 & 0xff) * 2 + 0x815e828);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 3;
    }
    REG_BG2VOFS = (ushort)(iVar2 >> 2) & 3;
    iVar2 = (int)*(short *)((DAT_030045a2 + uVar3 & 0xff) * 2 + 0x815e828);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 3;
    }
    REG_BG3VOFS = (ushort)(iVar2 >> 2) & 3;
  }
  else {
    REG_BG2VOFS = 0;
    REG_BG3VOFS = 0;
  }
  return;
}


// sub_080B0C38 @ 0x080B0C38

void sub_080B0C38(void)

{
  DAT_030020f4 = 0x80b0bbd;
  if ((DAT_030031bc & 7) == 0) {
    DAT_030045a2 = DAT_030045a2 + 1 & 0xff;
  }
  sub_080A9C64(0x80b0b69,1);
  return;
}


// sub_080B0C7C @ 0x080B0C7C

void sub_080B0C7C(void)

{
  sub_080A9C64(0x80b0b89,1);
  return;
}


// sub_080B0C90 @ 0x080B0C90

void sub_080B0C90(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  dword dVar9;
  uint uVar10;
  uint uVar11;
  int arg1;
  int arg0;
  code *UNRECOVERED_JUMPTABLE;
  ushort uStack_28;
  ushort uStack_26;
  ushort auStack_24 [2];
  
  DAT_03004588 = DAT_030031d0;
  DAT_0300458a = DAT_030031b8;
  DAT_0300458c = DAT_03003964;
  if (DAT_03003ff8 != 0) {
    sub_080AD824(DAT_03004614 & 0xffff,DAT_03004514 & 0xffff,0x3003ff8);
    goto FUN_080b1a0a;
  }
  if (-1 < (int)DAT_03004514) {
    iVar4 = sub_080C8B10(DAT_03004614 & 0xffff,DAT_03004514 & 0xffff);
    iVar4 = *(int *)(iVar4 + 0x17c + (uint)DAT_030050f8 * 0xe8);
    if (iVar4 == 0) {
      sub_080C23BC(0x108);
    }
    else {
      _call_via_r0(iVar4);
    }
  }
  iVar4 = sub_080C2340(0x102);
  if (iVar4 == 0) {
    if (DAT_03004598 != 0) {
      sub_080B0B54();
      DAT_03004598 = 0;
    }
  }
  else {
    if (DAT_03004598 == 0) {
      DAT_03004598 = 1;
    }
    if (DAT_03004598 == 1) {
      if ((DAT_030031bc & 0xf) == 0) {
        if (DAT_0300459a == 0) {
          DAT_0300003c = DAT_0300003c + 0x10;
          if (0x20 < DAT_0300003c) {
            DAT_0300459a = DAT_03004598;
          }
        }
        else {
          DAT_0300003c = DAT_0300003c - 0x10;
          if (DAT_0300003c == 0x10) {
            DAT_0300459a = 0;
          }
        }
      }
      sub_080B0AE0();
    }
    else {
      sub_080A9C64(0x80b0abd,1);
    }
  }
  iVar4 = sub_080C2340(0x106);
  if (iVar4 == 0) {
    DAT_0300459c = 0;
  }
  else {
    if (DAT_0300459c == 0) {
      DAT_0300459c = 1;
    }
    if ((DAT_0300459c == 1) && ((DAT_030031bc & 0xf) == 0)) {
      if (DAT_0300459e == 0) {
        DAT_0300003d = DAT_0300003d + 0x10;
        if (0x20 < DAT_0300003d) {
          DAT_0300459e = DAT_0300459c;
        }
      }
      else {
        DAT_0300003d = DAT_0300003d - 0x10;
        if (DAT_0300003d == 0x10) {
          DAT_0300459e = 0;
        }
      }
    }
  }
  iVar4 = sub_080C2340(0x108);
  if (iVar4 == 0) {
    if (DAT_030045a0 != 0) {
      sub_080B0C7C();
      DAT_030045a0 = 0;
    }
  }
  else {
    if (DAT_030045a0 == 0) {
      DAT_030045a0 = 1;
    }
    if (DAT_030045a0 == 1) {
      sub_080B0C38();
    }
    else {
      sub_080B0C7C();
    }
  }
  sVar1 = DAT_0300455e;
  uVar2 = DAT_0300456e;
  switch(DAT_03004550) {
  case 1:
    if (DAT_03004584 == 1) {
      if (DAT_03004586 != 0) {
        uVar2 = DAT_03004586 - 1;
        DAT_03004586 = 0;
        sub_080B2064((uint)uVar2,
                     (uint)*(ushort *)((uint)uVar2 * 2 + (uint)DAT_03004552 * 8 + 0x8163258));
        Field_SetState(6);
        goto FUN_080b1a0a;
      }
      DAT_0300458a = DAT_03004586;
      DAT_03004588 = 0x40;
      DAT_0300458c = DAT_03004586;
    }
    sub_080B1C18((uint)DAT_03004588);
    uVar2 = DAT_0300456e;
    break;
  case 2:
    uVar10 = DAT_0300456e - 1;
    uVar3 = (ushort)uVar10;
    if ((uVar10 & 0xffff) == (uint)(DAT_0300455a >> 1)) {
      if (DAT_0300455e == 0) {
        DAT_0300456e = uVar3;
        sub_080AE494();
        iVar4 = sub_080B0204(0);
        if (iVar4 == 1) {
          sub_080B09C4(0,0xffff);
                    /* WARNING: Subroutine does not return */
          FUN_080b1a06();
        }
                    /* WARNING: Subroutine does not return */
        FUN_080b1a06();
      }
code_r0x080b10c4:
                    /* WARNING: Subroutine does not return */
      FUN_080b1a06();
    }
    uVar10 = uVar10 & 0xffff;
    if (uVar10 == (DAT_0300455a >> 1) - 1) {
      DAT_0300456e = uVar3;
      iVar4 = sub_080B0204(0);
      if (iVar4 == 1) {
        sub_080B02A0((uint)DAT_03004552);
        uVar3 = DAT_0300456e;
      }
      else {
        sub_080C51D4(0x69);
        uVar3 = DAT_0300456e;
      }
      goto LAB_080b16ac;
    }
    if (uVar10 != 0) {
      if (uVar10 != 0xffff) {
        DAT_0300456e = uVar3;
                    /* WARNING: Subroutine does not return */
        FUN_080b1a06();
      }
      DAT_0300456e = uVar3;
      uVar10 = sub_080AB184();
      if ((uVar10 & 0xffff) != 1) {
        FUN_080b19f8();
      }
      iVar4 = sub_080AF8D0(1,2,0);
      if (iVar4 == 0) {
        if (DAT_03004596 == 1) {
          Field_SetState(1);
        }
        else {
          sub_080B03BC(1);
        }
        uVar10 = sub_080AD608();
        sub_080C5170(uVar10 & 0xffff);
      }
      puVar5 = &DAT_03004596;
      goto code_r0x080b1116;
    }
    if (DAT_0300455e != 0) {
      DAT_0300456e = 1;
                    /* WARNING: Subroutine does not return */
      FUN_080b1a06();
    }
code_r0x080b10b4:
    DAT_0300456e = uVar3;
    sub_080AE494();
    uVar2 = DAT_0300456e;
    break;
  case 4:
    sub_080B0A08(1);
    uVar2 = DAT_0300456e;
    break;
  case 5:
    uVar3 = DAT_0300456e - 1;
    if (DAT_0300456e == 7) {
      if (DAT_0300455e != 0) goto code_r0x080b10c4;
      if (DAT_03004558 != 1) {
        DAT_0300456e = uVar3;
                    /* WARNING: Subroutine does not return */
        FUN_080b1a06();
      }
code_r0x080b169a:
      DAT_0300456e = DAT_0300456e - 1;
      sub_080AE494();
      uVar2 = DAT_0300456e;
    }
    else {
      if (DAT_0300456e == 6) goto LAB_080b16ac;
      if (DAT_0300456e == 1) {
        if (DAT_0300455e != 0) goto code_r0x080b10c4;
        goto code_r0x080b10b4;
      }
      if (DAT_0300456e != 0) {
        DAT_0300456e = uVar3;
                    /* WARNING: Subroutine does not return */
        FUN_080b1a06();
      }
      DAT_0300456e = uVar3;
      uVar10 = sub_080AB184();
      if ((uVar10 & 0xffff) != 1) {
        FUN_080b19f8();
      }
      iVar4 = sub_080AF8D0(1,2,1);
      if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_080b1a06();
      }
      if (DAT_03004594 == 1) {
        Field_SetState(1);
      }
      else {
        sub_080B03BC(1);
      }
      puVar5 = &DAT_03004594;
code_r0x080b1116:
      *puVar5 = 0;
      uVar2 = DAT_0300456e;
    }
    break;
  case 6:
    iVar4 = sub_080B2090();
    if (iVar4 == 1) {
      uVar8 = sub_080B2EFC(0,0);
      iVar4 = sub_080B3038(uVar8,0x1d);
      iVar6 = sub_080C9084((uint)DAT_03004562,(uint)DAT_03004564,(uint)DAT_03004552,&uStack_28);
      arg1 = 0;
      arg0 = 0;
      if (iVar4 == 0) {
        if (((iVar6 != 0) && (uStack_28 != 0xffff)) &&
           (iVar4 = sub_080C2480((uint)uStack_28), iVar4 != 1)) {
          if (*(dword *)(iVar6 + 4) == 0x8073a00) {
            arg0 = sub_080C9100();
            if (arg0 != 0) {
              arg1 = sub_080AF85C(arg0,iVar6);
            }
          }
          else {
            uVar10 = sub_080AF0AC(*(dword *)(iVar6 + 4));
            if ((uVar10 & 0xffff) != 0) {
              arg1 = *(int *)(iVar6 + 4);
              sub_080C24B8((uint)uStack_28);
              DAT_0300458e = 1;
              uVar8 = ScriptVM_RunAlt(*(undefined4 *)(iVar6 + 4));
              if ((short)uVar8 == 2) {
                sub_080C2364(0x10b);
              }
            }
          }
        }
      }
      else {
        arg1 = *(int *)(iVar4 + 4 + (uint)DAT_03004552 * 4);
        iVar4 = sub_080B3038(uVar8,0x1a);
        if (iVar4 != 0) {
          sub_080B011C((uint)*(ushort *)(iVar4 + 2));
        }
      }
      if (arg1 == 0) {
        Field_SetState(1);
        iVar4 = sub_080BE76C();
        uVar2 = DAT_0300456e;
        if (iVar4 == 1) {
          Field_SetState(0x1a);
          uVar2 = DAT_0300456e;
        }
      }
      else {
        uVar2 = DAT_0300456e;
        if (arg0 == 0) {
          sub_080AF178(0xc,arg1);
          uVar2 = DAT_0300456e;
        }
      }
    }
    else {
      uVar2 = DAT_0300456e;
      if (iVar4 == 7) {
        Field_SetState(7);
        uVar2 = DAT_0300456e;
      }
    }
    break;
  case 7:
    sub_080B2064((uint)DAT_03004556,(uint)DAT_03004558);
    Field_SetState(6);
    uVar2 = DAT_0300456e;
    break;
  case 8:
    uVar3 = DAT_0300456e - 1;
    if (uVar3 == 6) {
      if (DAT_0300455e == 0) {
        DAT_0300456e = uVar3;
        sub_080AE494();
        if (DAT_03004558 == 1) {
          DAT_0300000c = DAT_0300000c - DAT_03004540;
          iVar4 = sub_080B0204(1);
          uVar2 = DAT_0300456e;
          if (iVar4 == 1) {
            dVar9 = 1;
LAB_080b12ba:
            sub_080B09C4(dVar9,0);
            uVar2 = DAT_0300456e;
          }
        }
        else {
          DAT_0300000c = DAT_0300000c - DAT_03004540;
          iVar4 = sub_080B0204(3);
          uVar2 = DAT_0300456e;
          if (iVar4 == 1) {
            dVar9 = 0xffff;
            goto LAB_080b12ba;
          }
        }
      }
    }
    else if (uVar3 == 5) {
      if (DAT_03004558 == 1) {
        DAT_0300456e = uVar3;
        iVar4 = sub_080B0204(1);
        if (iVar4 == 1) {
LAB_080b12f8:
          sub_080B02A0((uint)DAT_03004556);
          uVar3 = DAT_0300456e;
        }
        else {
          sub_080C51D4(0x69);
          uVar3 = DAT_0300456e;
        }
      }
      else {
        DAT_0300456e = uVar3;
        iVar4 = sub_080B0204(3);
        if (iVar4 == 1) goto LAB_080b12f8;
        sub_080C51D4(0x69);
        uVar3 = DAT_0300456e;
      }
LAB_080b16ac:
      DAT_0300456e = uVar3;
      sub_080B2840(0,0,0);
      uVar2 = DAT_0300456e;
    }
    else if (uVar3 == 0) {
      if (DAT_0300455e == 0) {
        DAT_0300456e = uVar3;
        sub_080AE494();
        DAT_0300000c = 0;
        uVar2 = DAT_0300456e;
      }
    }
    else {
      uVar2 = uVar3;
      if (uVar3 == 0xffff) {
        DAT_0300456e = uVar3;
        uVar10 = sub_080AB184();
        if ((uVar10 & 0xffff) != 1) goto code_r0x080b19f8;
        iVar4 = sub_080AF8D0(1,2,1);
        uVar2 = DAT_0300456e;
        if (iVar4 == 0) goto LAB_080b16f6;
      }
    }
    break;
  case 0xb:
    iVar6 = sub_080C2340(0xae);
    iVar4 = DAT_03004000;
    if (iVar6 == 0) {
      sub_080C2230(0);
      sub_080C2CD8((int)*(char *)(iVar4 + 4),(int)*(char *)(iVar4 + 6),0);
      uVar11 = (uint)DAT_03004562;
      uVar10 = DAT_03004564 & 0x3f;
      if (DAT_03004552 == 1) {
        uVar11 = uVar11 - 1;
LAB_080b13ec:
        uVar11 = uVar11 & 0xffff;
      }
      else if (DAT_03004552 < 2) {
        if (DAT_03004552 == 0) {
          uVar10 = uVar10 + 1;
LAB_080b13e4:
          uVar10 = uVar10 & 0xffff;
        }
      }
      else {
        if (DAT_03004552 == 2) {
          uVar10 = uVar10 - 1;
          goto LAB_080b13e4;
        }
        if (DAT_03004552 == 3) {
          uVar11 = uVar11 + 1;
          goto LAB_080b13ec;
        }
      }
      sub_080C1F50(uVar11,uVar10,&uStack_26,auStack_24);
      puVar7 = (undefined4 *)sub_0815341C((uint)uStack_26,(uint)auStack_24[0]);
      DAT_03005f84 = puVar7[1];
      DAT_03005f80 = *puVar7;
      uVar2 = DAT_0300456e;
    }
    else {
      iVar4 = sub_080C2340(0x5e);
      if (iVar4 == 0) {
        iVar4 = sub_080C2340(0x5f);
        if (iVar4 == 0) {
          dVar9 = 0x804cb9c;
        }
        else {
          dVar9 = 0x804c564;
        }
      }
      else {
        dVar9 = 0x804c354;
      }
      sub_080AF178(0xc,dVar9);
      uVar2 = DAT_0300456e;
    }
    break;
  case 0xc:
    sub_080B38A8();
    uVar2 = DAT_0300456e;
    break;
  case 0xd:
  case 0x21:
    if ((DAT_03004534 == 0x97) && (iVar4 = sub_080C2340(0x11), iVar4 != 0)) {
      DAT_03004534 = DAT_03004534 + 2;
    }
    iVar4 = sub_080B38A8();
    uVar10 = 0xffffffff;
    uVar2 = DAT_0300456e;
    if (iVar4 == -1) {
      if (DAT_0300460c != 0) {
        DAT_03004514 = DAT_03004514 + 1;
LAB_080b1528:
        DAT_0300456e = 0;
        uVar8 = sub_080B1A1C((uint)DAT_03004552);
        DAT_03004552 = (ushort)uVar8;
        sub_080AE234();
        sub_080AE294();
        sub_080B31C4(DAT_03004614 & 0xffff,(uint)DAT_0300460c,(uint)DAT_03003ba8);
        uVar2 = DAT_0300456e;
      }
    }
    else if (iVar4 == 1) {
      if (DAT_03003b98 == 0) {
        if (DAT_03004584 == 0) {
          sub_080AF178((uint)DAT_03004550,0x8124dbc);
        }
        else {
LAB_080b1590:
          DAT_030031cc = 0;
        }
LAB_080b1594:
        DAT_03003b98 = 1;
        uVar2 = DAT_0300456e;
      }
      else if (DAT_030031cc == 0) {
        sub_080B0820();
        sub_080C51D4(0x6e);
        if (DAT_03004550 != 0xd) {
          DAT_0300460c = 0x1c;
          goto LAB_080b15f2;
        }
        DAT_0300460c = 2;
LAB_080b15c8:
        DAT_0300456e = DAT_0300456e + 1;
        DAT_03003ba8 = *(ushort *)(DAT_03004000 + 4);
        uVar2 = DAT_0300456e;
      }
      else {
LAB_080b1628:
        sub_080B0820();
        DAT_0300460c = 0;
        uVar2 = DAT_0300456e + 1;
      }
    }
    break;
  case 0xe:
  case 0x22:
    if ((DAT_03004534 == 0x98) && (iVar4 = sub_080C2340(0x11), iVar4 != 0)) {
      DAT_03004534 = DAT_03004534 + 2;
    }
    iVar4 = sub_080B38A8();
    uVar2 = DAT_0300456e;
    if (iVar4 == -1) {
      if (DAT_0300460c != 0) {
        DAT_03004514 = DAT_03004514 - 1;
        goto LAB_080b1528;
      }
    }
    else if (iVar4 == 1) {
      if (DAT_03003b98 == 0) {
        if (DAT_03004584 != 0) goto LAB_080b1590;
        sub_080AF178((uint)DAT_03004550,0x8124dd8);
        goto LAB_080b1594;
      }
      if (DAT_030031cc != 0) goto LAB_080b1628;
      sub_080B0820();
      sub_080C51D4(0x6e);
      if (DAT_03004550 == 0xe) {
        DAT_0300460c = 1;
        goto LAB_080b15c8;
      }
      DAT_0300460c = 0x1b;
      uVar10 = 1;
LAB_080b15f2:
      DAT_0300456e = DAT_0300456e + 1;
      DAT_03003ba8 = *(ushort *)(DAT_03004000 + 6);
      DAT_03004614 = (uint)*(ushort *)(DAT_03004000 + 4);
      DAT_03004514 = uVar10;
      uVar8 = sub_080B1A1C((uint)*(ushort *)(DAT_03004000 + 8));
      DAT_03004552 = (ushort)uVar8;
      uVar2 = DAT_0300456e;
    }
    break;
  case 0xf:
    iVar4 = sub_080B092C();
    uVar2 = DAT_0300456e;
    if (iVar4 == 0) {
      sub_080AE234();
      sub_080B31C4(DAT_03004614 & 0xffff,(uint)DAT_0300460c,(uint)DAT_03003ba8);
      sub_080B2030((uint)DAT_0300455a,(uint)DAT_03004552,3);
      uVar2 = DAT_0300456e;
    }
    break;
  case 0x10:
    sub_080B4C48();
    uVar2 = DAT_0300456e;
    break;
  case 0x11:
    uVar3 = DAT_0300456e - 1;
    if (uVar3 == 4) {
      if (DAT_0300455e == 0) goto code_r0x080b169a;
    }
    else {
      if (uVar3 == 3) goto LAB_080b16ac;
      uVar2 = uVar3;
      if ((uVar3 == 0) && (uVar2 = DAT_0300456e, DAT_0300455e == 0)) {
        DAT_0300456e = uVar3;
        sub_080AE494();
        sub_080B05A4();
        DAT_0300457e = sVar1;
        Field_SetState(0x12);
        uVar2 = DAT_0300456e;
      }
    }
    break;
  case 0x12:
    iVar4 = sub_080B092C();
    uVar2 = DAT_0300456e;
    if (iVar4 == 0) {
      DAT_0300457e = 0;
      if (DAT_03004582 == 0) {
LAB_080b16f6:
        sub_080B03BC(1);
        uVar2 = DAT_0300456e;
      }
      else {
        sub_08128B84(4);
        Field_SetState(10);
        uVar2 = DAT_0300456e;
      }
    }
    break;
  case 0x13:
    iVar4 = sub_080B3078(0,0,6);
    if (iVar4 != 1) {
      if (DAT_0300456e == 0) {
        DAT_0300452c = sub_080AB138(0xd0,0x30,4,4);
        if (DAT_03002db0 != 0) {
          sub_080AB138(0,1,4,4);
        }
        DAT_0300456e = DAT_0300456e + 1;
      }
      else {
        iVar4 = sub_080B092C();
        if (iVar4 == 0) {
          DAT_03003bb8 = iVar4;
          sub_080E4554();
          Field_SetState(0x15);
        }
      }
      goto LAB_080b17b4;
    }
    DAT_03003bb8 = 0;
    sub_080E4554();
    Field_SetState(0x15);
    uVar2 = DAT_0300456e;
    break;
  case 0x14:
    DAT_03003bb8 = 1;
    sub_080E4554();
    sub_080B0888();
    Field_SetState(0x15);
    sub_080C7218();
    sub_080C7414();
LAB_080b17b4:
    sub_080C51BC(1);
    uVar2 = DAT_0300456e;
    break;
  case 0x16:
    if (DAT_03003bb8 == 0) {
      uVar3 = *(ushort *)((uint)DAT_03004552 * 2 + 0x815f31c);
      iVar4 = sub_080B3078(0,0,6);
      if (iVar4 != 1) {
        if (DAT_0300456e == 0) {
          DAT_030029b0 = *DAT_03004630;
          sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
          sub_080ACFCC(3,DAT_03004510,&DAT_03002b50,0x20);
          sub_080ACFCC(3,DAT_03003fc8,&DAT_03002d50,0x20);
          DAT_0300452c = sub_080AB054(0xd0,0x30,1,0x10);
          if (DAT_030029b0 != 0) {
            sub_080AB054(0,1,1,0x10);
          }
          goto code_r0x080b19f8;
        }
        iVar4 = sub_080B092C();
        uVar2 = DAT_0300456e;
        if (iVar4 != 0) break;
      }
      if (DAT_03004594 == 1) {
        sub_080B1A4C((uint)uVar3,1);
        uVar2 = DAT_0300456e;
      }
      else {
        Field_SetState(1);
        uVar2 = DAT_0300456e;
      }
    }
    else {
      if (DAT_0300456e != 0) {
        iVar4 = sub_080B092C();
        goto joined_r0x080b19aa;
      }
      DAT_0200e808 = 1;
      DAT_0300452c = sub_080AAF48(1);
code_r0x080b19f8:
      uVar2 = DAT_0300456e + 1;
    }
    break;
  case 0x18:
    iVar4 = sub_080B38A8();
    uVar2 = DAT_0300456e;
    if (((iVar4 == 1) && ((DAT_0300458a & 1) == 0)) && ((DAT_0300458a & 2) != 0)) {
      sub_080B0820();
      DAT_0300460c = 0;
      uVar2 = DAT_0300456e + 1;
    }
    break;
  case 0x1b:
    if (DAT_0300456e == 0) {
      if (DAT_03004628 == 0) {
        sub_08128B84(0);
      }
      else if (DAT_03004628 == 1) {
        sub_0812D0FC(0);
      }
      else {
        sub_0812A730();
      }
      uVar2 = DAT_0300456e + 1;
    }
    break;
  case 0x1c:
    DAT_03003bb8 = 1;
    sub_080AF280();
    sub_080C7218();
    sub_080C7414();
    uVar2 = DAT_0300456e;
    break;
  case 0x1d:
  case 0x1e:
    if (DAT_0300456e == 0) {
      DAT_0200e808 = 1;
      DAT_0300452c = sub_080AAF48(1);
      goto code_r0x080b19f8;
    }
    iVar4 = sub_080B092C();
joined_r0x080b19aa:
    uVar2 = DAT_0300456e;
    if (iVar4 == 0) {
      sub_080C2CD8((int)(char)DAT_03003fc4,(int)(char)DAT_03004618,1);
      uVar2 = DAT_0300456e;
    }
    break;
  case 0x1f:
    if (DAT_0300456e == 0) {
      if (DAT_0300455e == 0) {
        sub_080AE494();
        uVar2 = DAT_0300456e + 1;
      }
    }
    else {
      if (DAT_0300456e == 1) {
        sub_080B05A4();
        goto code_r0x080b19f8;
      }
      sub_080B0A08(0);
      uVar2 = DAT_0300456e;
    }
    break;
  case 0x25:
    if (DAT_0300456e == 0) {
      sub_080AD0FC(DAT_03004628,0xffff);
      DAT_0300456e = 1;
      uVar2 = DAT_0300456e;
    }
  }
  DAT_0300456e = uVar2;
  sub_080B2CC0();
FUN_080b1a0a:
                    /* WARNING: Could not recover jumptable at 0x080b1a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_080b19f8 @ 0x080B19F8

void FUN_080b19f8(void)

{
  int unaff_r5;
  code *UNRECOVERED_JUMPTABLE;
  
  *(short *)(unaff_r5 + 0x1e) = *(short *)(unaff_r5 + 0x1e) + 1;
  sub_080B2CC0();
                    /* WARNING: Could not recover jumptable at 0x080b1a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_080b1a06 @ 0x080B1A06

void FUN_080b1a06(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080B2CC0();
                    /* WARNING: Could not recover jumptable at 0x080b1a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// FUN_080b1a0a @ 0x080B1A0A

void FUN_080b1a0a(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x080b1a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B1A1C @ 0x080B1A1C

uint sub_080B1A1C(uint arg0)

{
  return (uint)*(ushort *)(&DAT_0815f2fe + (arg0 & 0xffff) * 8);
}


// sub_080B1A30 @ 0x080B1A30

void sub_080B1A30(undefined4 arg0,uint arg1)

{
  DAT_0300455a = (ushort)arg0;
  sub_080B2030((uint)(ushort)arg0,arg1 & 0xffff,3);
  return;
}


// sub_080B1A4C @ 0x080B1A4C

void sub_080B1A4C(undefined4 arg0,undefined4 arg1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = sub_080B0204(2);
  if (iVar2 == 1) {
    sub_080B09C4(0,1);
    sub_080B02A0((uint)(ushort)arg0);
    sub_080B2840(1,0,0);
    DAT_03004558 = 1;
    DAT_0300458e = 0;
  }
  else {
    if ((short)arg1 == 1) {
      sub_080AD0FC(0x8165380,0xffff);
      Field_SetState(0x1a);
      return;
    }
    DAT_03004558 = 0;
    sub_080C51D4(0x69);
    DAT_0300458e = 1;
  }
  uVar1 = DAT_03003ff4;
  DAT_0300456e = 0xc;
  DAT_03004556 = (ushort)arg0;
  Field_SetState(5);
  DAT_03003ff4 = uVar1;
  return;
}


// sub_080B1AD8 @ 0x080B1AD8

void sub_080B1AD8(undefined4 arg0,uint arg1)

{
  int iVar1;
  uint arg0_00;
  uint arg1_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = (uint)(ushort)arg0;
  arg1_00 = arg1 & 0xffff;
  iVar1 = sub_080B0248(0,0,0);
  if (iVar1 == 3) {
    sub_080B1A30(arg0_00,arg1_00);
  }
  else {
    DAT_0300455a = (ushort)arg0;
    if (iVar1 == 2) {
      sub_080B2030(arg0_00,arg1_00,3);
    }
    else {
      sub_080B2030(arg0_00,arg1_00,2);
    }
  }
  DAT_0300458e = (ushort)(iVar1 == 1);
                    /* WARNING: Could not recover jumptable at 0x080b1b52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B1B58 @ 0x080B1B58

undefined4 sub_080B1B58(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_080C8AF8();
  if ((((iVar1 != 1) || (DAT_0200e7d8 == 0)) &&
      ((iVar1 = sub_080C8AF8(), iVar1 != 1 || (DAT_0200e7d4 == 0)))) &&
     ((((iVar1 = sub_080C8AF8(), iVar1 != 1 || (DAT_0200e7da == 0)) &&
       (iVar1 = sub_080B78A4(), iVar1 == 0)) &&
      ((iVar1 = sub_080B098C(), iVar1 != 1 && (uVar2 = sub_080AB184(), (uVar2 & 0xffff) != 0)))))) {
    return 1;
  }
  return 0;
}


// sub_080B1BC4 @ 0x080B1BC4

void sub_080B1BC4(void)

{
  Field_SetState(10);
  DAT_03003bb8 = 0;
  return;
}


// sub_080B1BDC @ 0x080B1BDC

void sub_080B1BDC(void)

{
  int iVar1;
  
  iVar1 = sub_080B953C();
  if (iVar1 == 1) {
    sub_080AD6E4(0);
    DAT_0300456e = 0;
    DAT_0300457e = 0x22;
    sub_080C7218();
    sub_080C6FF0();
    sub_080C7414();
  }
  else {
    iVar1 = sub_080F3190();
    if (iVar1 != 0) {
      sub_0812A730();
    }
  }
  return;
}


// sub_080B1C18 @ 0x080B1C18

void sub_080B1C18(undefined4 arg0)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 arg0_00;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  dword arg1;
  code *UNRECOVERED_JUMPTABLE;
  ushort local_26;
  undefined1 auStack_24 [4];
  
  uVar7 = 0xffff;
  uVar6 = (uint)DAT_03004552;
  sVar8 = 0;
  bVar1 = false;
  sub_080AF4EC((uint)DAT_03004562,(uint)DAT_03004564);
  if (((((DAT_03004590 == 0) && (DAT_0300458e == 0)) &&
       (iVar2 = sub_080C9084((uint)DAT_03004562,(uint)DAT_03004564,(uint)DAT_03004552,&local_26),
       iVar2 != 0)) && ((local_26 != 0xffff && (iVar3 = sub_080C2480((uint)local_26), iVar3 == 1))))
     && (uVar4 = sub_080AF0AC(*(undefined4 *)(iVar2 + 4)), (uVar4 & 0xffff) != 0)) {
    DAT_03004590 = sub_080B828C();
    goto LAB_080b1ffc;
  }
  iVar2 = sub_080B1B58();
  if (iVar2 == 1) {
    uVar4 = (uint)DAT_0300458a;
    if ((DAT_0300458a & 1) != 0) {
      if (DAT_03004590 == 0) {
        iVar2 = sub_080C2340(0xae);
        if (iVar2 == 0) {
          sub_08128B84(0);
          Field_SetState(10);
        }
      }
      else if (*(short *)(DAT_03004590 + 0x1e) != 0) {
        arg0_00 = sub_080C9084((uint)DAT_03004562,(uint)DAT_03004564,(uint)DAT_03004552,auStack_24);
        sub_080AF7E8(arg0_00,arg0_00,0);
      }
      goto LAB_080b1ffc;
    }
    if (((DAT_0300458a & 8) != 0) && (iVar2 = sub_080B9568(), iVar2 == 1)) {
      sub_080C51D4(0x67);
      sub_0812D0FC(0);
      Field_SetState(10);
      DAT_03003bb8 = uVar4 & 1;
      iVar2 = sub_080B3078(0,0,6);
      if ((iVar2 != 1) && (DAT_0300452c = sub_080AB138(0xd0,0x30,4,4), DAT_03002db0 != 0)) {
        sub_080AB138(0,1,4,4);
      }
      goto LAB_080b1ffc;
    }
    if ((DAT_0300458a & 0x100) != 0) {
      uVar7 = sub_0812A730();
      if ((uVar7 & 0xffff) != 0) {
        iVar2 = sub_080F3190();
        if (iVar2 == 0) {
          sub_080C51D4(0x65);
        }
        sub_080B1BC4();
      }
      goto LAB_080b1ffc;
    }
  }
  uVar4 = sub_080F3F44();
  if (((uVar4 & 0x100) != 0) && (DAT_030045a8 == 0)) {
    DAT_030045a8 = sub_080C57B4();
  }
  iVar2 = sub_080B1B58();
  if (iVar2 == 1) {
    if (((ushort)arg0 & 2) == 0) {
      if (((ushort)arg0 & 0x10) == 0) {
        if (((ushort)arg0 & 0x20) == 0) {
          if (((ushort)arg0 & 0x80) == 0) {
            if (((ushort)arg0 & 0x40) == 0) {
              if (((ushort)arg0 & 0x200) != 0) {
                sub_080B1BDC();
              }
            }
            else {
              uVar7 = (uint)*(ushort *)(uVar6 * 8 + 0x815f2fc);
              DAT_0300455a = 0xc;
            }
            goto LAB_080b1eea;
          }
          puVar5 = &DAT_0815f2fe;
        }
        else {
          puVar5 = &DAT_0815f300;
        }
      }
      else {
        puVar5 = &DAT_0815f302;
      }
      uVar7 = (uint)*(ushort *)(puVar5 + uVar6 * 8);
    }
    else if (((ushort)arg0 & 0x10) == 0) {
      if (((ushort)arg0 & 0x20) == 0) {
        if (((ushort)arg0 & 0x80) == 0) {
          if (((ushort)arg0 & 0x40) == 0) {
            if (((ushort)arg0 & 0x200) != 0) {
              sub_080B1BDC();
            }
          }
          else {
            uVar7 = (uint)*(ushort *)(uVar6 * 8 + 0x815f2fc);
            DAT_0300455a = 8;
          }
        }
        else {
          uVar7 = (uint)*(ushort *)(uVar6 * 2 + 0x815f31c);
          bVar1 = true;
        }
      }
      else {
        uVar7 = (uint)*(ushort *)(&DAT_0815f326 + uVar6 * 4);
        sVar8 = 2;
      }
    }
    else {
      uVar7 = (uint)*(ushort *)(uVar6 * 4 + 0x815f324);
      sVar8 = 1;
    }
  }
LAB_080b1eea:
  if (uVar7 != 0xffff) {
    if (sVar8 == 0) {
      if (bVar1) {
        sub_080B1A4C(uVar7,0);
      }
      else if (uVar7 == DAT_03004552) {
        sub_080B1AD8((uint)DAT_0300455a,(uint)DAT_03004552);
      }
      else {
        if (((ushort)arg0 & 0x10) == 0) {
          if (((ushort)arg0 & 0x20) == 0) {
            arg1 = 0;
            if (((ushort)arg0 & 0x80) != 0) {
              arg1 = 1;
            }
          }
          else {
            arg1 = 0xffff;
          }
        }
        else {
          arg1 = 1;
        }
        sub_080B2064(uVar7,arg1);
        Field_SetState(6);
        DAT_0300458e = 0;
      }
    }
    else {
      DAT_0300456e = 0xc;
      DAT_03004556 = (undefined2)uVar7;
      DAT_03004558 = sVar8;
      Field_SetState(8);
      sVar8 = DAT_03004558;
      DAT_0300458e = 0;
      if (DAT_03004558 == 1) {
        iVar2 = sub_080B0204(1);
        if (iVar2 == 1) {
          DAT_03004540 = 0xfff0;
        }
        else {
          DAT_03004540 = 0xfff8;
          DAT_0300458e = sVar8;
        }
      }
      else {
        iVar2 = sub_080B0204(3);
        if (iVar2 == 1) {
          DAT_03004540 = 0x10;
        }
        else {
          DAT_03004540 = 8;
          DAT_0300458e = 1;
        }
      }
      sub_080B2840(3,(uint)DAT_03004540,0);
    }
  }
LAB_080b1ffc:
                    /* WARNING: Could not recover jumptable at 0x080b200a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B200C @ 0x080B200C

void sub_080B200C(undefined4 arg0)

{
  if ((short)arg0 != DAT_03004552) {
    DAT_03004554 = DAT_03004552;
    DAT_03004552 = (short)arg0;
  }
  return;
}


// sub_080B2030 @ 0x080B2030

void sub_080B2030(undefined4 arg0,undefined4 arg1,uint arg2)

{
  sub_080B2840(1,0,0);
  DAT_03004556 = (undefined2)arg1;
  DAT_0300456e = (undefined2)arg0;
  Field_SetState(arg2 & 0xffff);
  return;
}


// sub_080B2064 @ 0x080B2064

void sub_080B2064(undefined4 arg0,undefined4 arg1)

{
  sub_080B2840(2,0,0);
  DAT_0300456e = 0x10;
  DAT_03004558 = (undefined2)arg1;
  DAT_03004556 = (undefined2)arg0;
  return;
}


// sub_080B2090 @ 0x080B2090

undefined4 sub_080B2090(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = DAT_0300455e;
  sVar3 = DAT_0300456e + -1;
  if (sVar3 == 8) {
    sVar2 = DAT_0300456e;
    if (DAT_0300455e == 0) {
      DAT_0300456e = sVar3;
      sub_080AE494();
      DAT_0300457e = 0x22;
      sVar2 = DAT_0300456e;
    }
  }
  else if (sVar3 == 7) {
    DAT_0300456e = sVar3;
    sub_080B200C((uint)DAT_03004558 + (uint)DAT_03004552 & 3);
    sub_080B2840(0,0,0);
    sVar2 = DAT_0300456e;
  }
  else {
    sVar2 = sVar3;
    if ((sVar3 == 0) && (sVar2 = DAT_0300456e, DAT_0300455e == 0)) {
      DAT_0300456e = sVar3;
      sub_080AE494();
      DAT_0300457e = sVar1;
      if (DAT_03004552 == DAT_03004556) {
        uVar4 = 1;
      }
      else {
        uVar4 = 7;
      }
      goto LAB_080b2106;
    }
  }
  DAT_0300456e = sVar2;
  uVar4 = 0xffffffff;
LAB_080b2106:
                    /* WARNING: Could not recover jumptable at 0x080b210a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(uVar4);
  return uVar4;
}


// sub_080B210C @ 0x080B210C

void sub_080B210C(undefined4 *arg0)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar12;
  byte bVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  
  uStack_54 = (uint)*(ushort *)(arg0 + 2);
  uStack_50 = (uint)*(ushort *)((int)arg0 + 10);
  uStack_4c = (uint)*(ushort *)(arg0 + 3);
  uStack_48 = (uint)*(ushort *)((int)arg0 + 0xe);
  uVar10 = (uint)*(ushort *)(arg0 + 4);
  uVar2 = *(ushort *)((int)arg0 + 0x12);
  uVar14 = (uint)*(ushort *)(arg0 + 5);
  iVar11 = *(int *)*arg0;
  iVar4 = arg0[1];
  DAT_030045f4 = 1;
  if ((DAT_03004614 != 0x4a) || (DAT_03004514 != 4)) {
    uVar5 = uStack_4c + DAT_03004578;
    uStack_4c = uVar5 & 0xffff;
    if (uVar14 == 1) {
      if ((short)uVar5 < 8) {
        uVar5 = 8 - uStack_4c & 0xffff;
        uStack_4c = uStack_4c + uVar5 & 0xffff;
        uStack_54 = uStack_54 + uVar5 & 0xffff;
        uVar10 = uVar10 - uVar5;
      }
      else {
        if (uStack_4c + uVar10 < 0xe9) goto LAB_080b21fc;
        uVar10 = uVar10 - ((uStack_4c + uVar10) - 0xe8 & 0xffff);
      }
    }
    else if ((int)((uStack_4c - uVar10) * 0x10000) >> 0x10 < 8) {
      uVar10 = uVar10 - (8 - (uStack_4c - uVar10) & 0xffff);
    }
    else {
      if (uStack_4c < 0xe9) goto LAB_080b21fc;
      uVar5 = uStack_4c - 0xe8 & 0xffff;
      uStack_4c = uStack_4c - uVar5 & 0xffff;
      uStack_54 = uStack_54 + uVar5 & 0xffff;
      uVar10 = uVar10 - uVar5;
    }
    uVar10 = uVar10 & 0xffff;
  }
LAB_080b21fc:
  if (uVar10 != 0 && -1 < (int)(uVar10 * 0x10000)) {
    uVar3 = 0;
    if (uVar2 != 0) {
      do {
        uVar5 = 0;
        uVar3 = uVar3 + 1;
        if (uVar10 != 0) {
          iVar6 = iVar11 + (uStack_50 >> 3) * 0x400;
          iVar7 = (uStack_48 >> 3) * 0x400;
          uVar9 = uStack_4c;
          uVar17 = uStack_54;
          do {
            if ((uVar9 & 1) == 0) {
              bVar1 = *(byte *)(iVar6 + (uVar17 >> 3) * 0x20 + (uStack_50 & 7) * 4 +
                               ((uVar17 & 7) >> 1));
              iVar8 = iVar4 + iVar7;
              iVar16 = (uStack_48 & 7) * 4;
              pbVar12 = (byte *)((uVar9 >> 3) * 0x20 + iVar8 + iVar16 + ((uVar9 & 7) >> 1));
              bVar13 = *pbVar12;
              if ((bVar13 & 0xf) == 0) {
                bVar13 = bVar13 | bVar1 & 0xf;
                DAT_030045f4 = 1;
              }
              *pbVar12 = bVar13;
              uVar9 = uVar9 + uVar14;
              uVar15 = uVar9 & 0xffff;
              pbVar12 = (byte *)(((uVar9 & 0xffff) >> 3) * 0x20 + iVar8 + iVar16 +
                                ((uVar9 & 7) >> 1));
              bVar13 = *pbVar12;
              if ((bVar13 & 0xf0) == 0) {
                bVar13 = bVar13 | bVar1 & 0xf0;
LAB_080b235e:
                DAT_030045f4 = 1;
              }
            }
            else {
              bVar1 = *(byte *)(iVar6 + (uVar17 >> 3) * 0x20 + (uStack_50 & 7) * 4 +
                               ((uVar17 & 7) >> 1));
              iVar8 = iVar4 + iVar7;
              iVar16 = (uStack_48 & 7) * 4;
              pbVar12 = (byte *)((uVar9 >> 3) * 0x20 + iVar8 + iVar16 + ((uVar9 & 7) >> 1));
              bVar13 = *pbVar12;
              if ((bVar13 & 0xf0) == 0) {
                bVar13 = bVar13 | bVar1 << 4;
                DAT_030045f4 = 1;
              }
              *pbVar12 = bVar13;
              uVar9 = uVar9 + uVar14;
              uVar15 = uVar9 & 0xffff;
              pbVar12 = (byte *)(((uVar9 & 0xffff) >> 3) * 0x20 + iVar8 + iVar16 +
                                ((uVar9 & 7) >> 1));
              bVar13 = *pbVar12;
              if ((bVar13 & 0xf) == 0) {
                bVar13 = bVar13 | bVar1 >> 4;
                goto LAB_080b235e;
              }
            }
            *pbVar12 = bVar13;
            uVar17 = (uVar17 + 1 & 0xffff) + 1 & 0xffff;
            uVar9 = uVar15 + uVar14 & 0xffff;
            uVar5 = (uVar5 + 1 & 0xffff) + 1 & 0xffff;
          } while (uVar5 < uVar10);
        }
        uStack_50 = uStack_50 + 1 & 0xffff;
        uStack_48 = uStack_48 + 1 & 0xffff;
      } while (uVar3 < uVar2);
    }
    DAT_0300457c = 0;
  }
  return;
}


// sub_080B23D0 @ 0x080B23D0

void sub_080B23D0(undefined4 *arg0)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  undefined4 *puVar13;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  uVar1 = *(ushort *)(arg0 + 4);
  local_40 = (uint)(uVar1 >> 3);
  local_3c = (uint)(*(ushort *)((int)arg0 + 0x12) >> 3);
  uVar4 = DAT_03004578 + *(short *)(arg0 + 3);
  uVar11 = (uint)uVar4;
  local_34 = (*(ushort *)(arg0 + 2) >> 3 & 0x7ff) * 0x20;
  local_30 = (uVar4 >> 3 & 0x7ff) * 0x20;
  iVar2 = *(int *)*arg0;
  iVar3 = arg0[1];
  if ((uVar1 & 7) != 0) {
    local_40 = local_40 + 1;
  }
  if ((*(ushort *)((int)arg0 + 0x12) & 7) != 0) {
    local_3c = local_3c + 1;
  }
  if (*(short *)(arg0 + 5) == 1) {
    if ((short)uVar4 < 8) {
      iVar5 = (int)((8 - uVar11) * 0x10000) >> 0x10;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 7;
      }
      iVar7 = (iVar5 >> 3) * 0x20;
      local_30 = local_30 + iVar7 & 0xffff;
      local_34 = local_34 + iVar7 & 0xffff;
      local_40 = local_40 - (iVar5 >> 3);
    }
    else {
      uVar11 = uVar11 + uVar1;
      if (uVar11 < 0xe9) goto LAB_080b24f0;
      iVar5 = (int)((uVar11 - 0xe8) * 0x10000) >> 0x10;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 7;
      }
      local_40 = local_40 - (iVar5 >> 3);
    }
  }
  else {
    iVar5 = uVar11 - uVar1;
    if (iVar5 * 0x10000 >> 0x10 < 8) {
      iVar5 = (8 - iVar5) * 0x10000 >> 0x10;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 7;
      }
      local_40 = local_40 - (iVar5 >> 3);
    }
    else {
      if (uVar11 < 0xe9) goto LAB_080b24f0;
      iVar5 = (int)((uVar11 - 0xe8) * 0x10000) >> 0x10;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 7;
      }
      iVar5 = iVar5 >> 3;
      local_30 = local_30 + iVar5 * -0x20 & 0xffff;
      local_34 = local_34 + iVar5 * 0x20 & 0xffff;
      local_40 = local_40 - iVar5;
    }
  }
  local_40 = local_40 & 0xffff;
LAB_080b24f0:
  if (0 < (int)(local_40 * 0x10000)) {
    if (*(short *)(arg0 + 5) == 1) {
      uVar11 = 0;
      if (local_3c != 0) {
        do {
          puVar9 = (undefined4 *)
                   (iVar2 + ((int)((uint)*(ushort *)((int)arg0 + 10) + uVar11 * 8) >> 3) * 0x400 +
                   local_34);
          puVar6 = (undefined4 *)
                   (iVar3 + ((int)((uint)*(ushort *)((int)arg0 + 0xe) + uVar11 * 8) >> 3) * 0x400 +
                   local_30);
          local_38 = 0;
          if (local_40 != 0) {
            do {
              *puVar6 = *puVar9;
              puVar6[1] = puVar9[1];
              puVar6[2] = puVar9[2];
              puVar6[3] = puVar9[3];
              puVar6[4] = puVar9[4];
              puVar6[5] = puVar9[5];
              puVar13 = puVar9 + 7;
              puVar6[6] = puVar9[6];
              puVar9 = puVar9 + 8;
              puVar6[7] = *puVar13;
              puVar6 = puVar6 + 8;
              local_38 = local_38 + 1 & 0xffff;
            } while (local_38 < local_40);
          }
          uVar11 = uVar11 + 1 & 0xffff;
        } while (uVar11 < local_3c);
      }
    }
    else {
      uVar11 = 0;
      if (local_3c != 0) {
        do {
          puVar12 = (uint *)(iVar2 + ((int)((uint)*(ushort *)((int)arg0 + 10) + uVar11 * 8) >> 3) *
                                     0x400 + local_34);
          puVar8 = (uint *)(iVar3 + ((int)((uint)*(ushort *)((int)arg0 + 0xe) + uVar11 * 8) >> 3) *
                                    0x400 + local_30);
          local_38 = 0;
          if (local_40 != 0) {
            do {
              uVar10 = *puVar12;
              *puVar8 = uVar10 << 0x1c | (uVar10 & 0xf0) << 0x14 | (uVar10 & 0xf00) << 0xc |
                        (uVar10 & 0xf000) << 4 | uVar10 >> 4 & 0xf000 | uVar10 >> 0xc & 0xf00 |
                        uVar10 >> 0x14 & 0xf0 | uVar10 >> 0x1c;
              uVar10 = puVar12[1];
              puVar8[1] = uVar10 << 0x1c | (uVar10 & 0xf0) << 0x14 | (uVar10 & 0xf00) << 0xc |
                          (uVar10 & 0xf000) << 4 | uVar10 >> 4 & 0xf000 | uVar10 >> 0xc & 0xf00 |
                          uVar10 >> 0x14 & 0xf0 | uVar10 >> 0x1c;
              uVar10 = puVar12[2];
              puVar8[2] = uVar10 << 0x1c | (uVar10 & 0xf0) << 0x14 | (uVar10 & 0xf00) << 0xc |
                          (uVar10 & 0xf000) << 4 | uVar10 >> 4 & 0xf000 | uVar10 >> 0xc & 0xf00 |
                          uVar10 >> 0x14 & 0xf0 | uVar10 >> 0x1c;
              uVar10 = puVar12[3];
              puVar8[3] = uVar10 << 0x1c | (uVar10 & 0xf0) << 0x14 | (uVar10 & 0xf00) << 0xc |
                          (uVar10 & 0xf000) << 4 | uVar10 >> 4 & 0xf000 | uVar10 >> 0xc & 0xf00 |
                          uVar10 >> 0x14 & 0xf0 | uVar10 >> 0x1c;
              uVar10 = puVar12[4];
              puVar8[4] = uVar10 << 0x1c | (uVar10 & 0xf0) << 0x14 | (uVar10 & 0xf00) << 0xc |
                          (uVar10 & 0xf000) << 4 | uVar10 >> 4 & 0xf000 | uVar10 >> 0xc & 0xf00 |
                          uVar10 >> 0x14 & 0xf0 | uVar10 >> 0x1c;
              uVar10 = puVar12[5];
              puVar8[5] = uVar10 << 0x1c | (uVar10 & 0xf0) << 0x14 | (uVar10 & 0xf00) << 0xc |
                          (uVar10 & 0xf000) << 4 | uVar10 >> 4 & 0xf000 | uVar10 >> 0xc & 0xf00 |
                          uVar10 >> 0x14 & 0xf0 | uVar10 >> 0x1c;
              uVar10 = puVar12[6];
              puVar8[6] = uVar10 << 0x1c | (uVar10 & 0xf0) << 0x14 | (uVar10 & 0xf00) << 0xc |
                          (uVar10 & 0xf000) << 4 | uVar10 >> 4 & 0xf000 | uVar10 >> 0xc & 0xf00 |
                          uVar10 >> 0x14 & 0xf0 | uVar10 >> 0x1c;
              uVar10 = puVar12[7];
              puVar12 = puVar12 + 8;
              puVar8[7] = uVar10 << 0x1c | (uVar10 & 0xf0) << 0x14 | (uVar10 & 0xf00) << 0xc |
                          (uVar10 & 0xf000) << 4 | uVar10 >> 4 & 0xf000 | uVar10 >> 0xc & 0xf00 |
                          uVar10 >> 0x14 & 0xf0 | uVar10 >> 0x1c;
              puVar8 = puVar8 + -8;
              local_38 = local_38 + 1 & 0xffff;
            } while (local_38 < local_40);
          }
          uVar11 = uVar11 + 1 & 0xffff;
        } while (uVar11 < local_3c);
      }
    }
    if (DAT_0300457c == 0) {
      DAT_0300457c = 1;
    }
    else if (DAT_0300457c < 3) {
      DAT_0300457c = DAT_0300457c + 1;
    }
    else {
      DAT_0300457c = 0;
    }
  }
  return;
}


// sub_080B2840 @ 0x080B2840

void sub_080B2840(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  undefined1 local_c [4];
  
  DAT_03004574 = arg0;
  DAT_03004578 = (undefined2)arg1;
  DAT_0300457a = (undefined2)arg2;
  REG_DMA3SAD = local_c;
  REG_DMA3DAD = 0x2005004;
  REG_DMA3CNT = 0x85001000;
  uVar1 = REG_DMA3CNT;
  DAT_0300455e = 1;
  DAT_0300457c = 0;
  DAT_0300455c = 0;
  return;
}


// sub_080B2880 @ 0x080B2880

void sub_080B2880(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_8 [8];
  
  iVar2 = sub_080ADF40();
  if (iVar2 != 0) {
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x6003000;
    REG_DMA3CNT = 0x85000400;
    uVar1 = REG_DMA3CNT;
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x6004000;
    REG_DMA3CNT = 0x85001000;
    uVar1 = REG_DMA3CNT;
  }
  REG_DMA3SAD = 0x2005004;
  REG_DMA3DAD = 0x6008800;
  REG_DMA3CNT = 0x84000d00;
  DAT_0300455c = 0;
  return;
}


// sub_080B28F8 @ 0x080B28F8

void sub_080B28F8(int arg0,int arg1)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  do {
    iVar1 = sub_080B2D94(arg0,arg1);
    if (iVar1 == -1) {
      DAT_0300455e = 0;
LAB_080b2930:
                    /* WARNING: Could not recover jumptable at 0x080b2936. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    if (iVar1 == 1) {
      DAT_0300455e = DAT_0300455e + 1;
      goto LAB_080b2930;
    }
    DAT_0300455e = DAT_0300455e + 1;
    arg0 = arg0 + 0x20;
    arg1 = arg1 + 0x20;
  } while( true );
}


// sub_080B2938 @ 0x080B2938

undefined4 sub_080B2938(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  iVar2 = sub_080B9750();
  if (iVar2 == 0) {
    uVar3 = *(undefined4 *)(iVar1 + 0x168 + (uint)DAT_030050f8 * 0xe8);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// sub_080B2980 @ 0x080B2980

uint sub_080B2980(uint arg0,uint arg1)

{
  int iVar1;
  
  iVar1 = sub_080B0248(0,arg0 & 0xffff,arg1 & 0xffff);
  return (uint)(iVar1 - 2U < 2);
}


// sub_080B29A8 @ 0x080B29A8

void sub_080B29A8(undefined4 arg0)

{
  if (((short)arg0 == 0) || ((short)arg0 == 2)) {
    DAT_03000030 = 0x5a;
    DAT_03000031 = 0x38;
    DAT_03000034 = 0x58;
    DAT_03000035 = 0x18;
    DAT_03000038 = 0x2f;
    DAT_03000032 = 0xb8;
    DAT_03000033 = 0x96;
    DAT_03000036 = 0x58;
    DAT_03000037 = 0x18;
    DAT_03000039 = 0x2f;
    DAT_0300003a = 0x3f;
  }
  else if ((short)arg0 == 1) {
    DAT_03000030 = 0x98;
    DAT_03000031 = 0x58;
    DAT_03000034 = 0x18;
    DAT_03000035 = 0;
    DAT_03000038 = 0x2f;
    DAT_03000032 = 0x98;
    DAT_03000033 = 0x58;
    DAT_03000036 = 0x18;
    DAT_03000037 = 0;
    DAT_03000039 = 0x2f;
    DAT_0300003a = 0x3f;
  }
  else if ((short)arg0 == 3) {
    DAT_03000038 = 0x3f;
    DAT_03000039 = 0x3f;
    DAT_0300003a = 0x3f;
  }
  return;
}


// sub_080B2AB0 @ 0x080B2AB0

void sub_080B2AB0(void)

{
  uint uVar1;
  int iVar2;
  dword arg1;
  code *UNRECOVERED_JUMPTABLE;
  
  arg1 = 0;
  uVar1 = sub_080AD7E4();
  if ((((uVar1 & 0xffff) == 5) && (DAT_03004574 == 1)) && (DAT_0300455c == 0)) {
    arg1 = 0xffff;
  }
  iVar2 = sub_080B2980(0,arg1);
  if (iVar2 != 1) goto LAB_080b2ca8;
  if ((DAT_0300457e < 0x22) && (DAT_0300461c != 0)) {
    sub_080AA184(0x8002cac,1,0xd,0);
  }
  if (0x20 < DAT_0300457e) goto LAB_080b2ca8;
  uVar1 = sub_080B2938();
  if (DAT_0300457e != 0) {
    sub_080B29A8(uVar1 & 0xffff);
  }
  if (DAT_0300461c == 0) goto LAB_080b2ca8;
  if (uVar1 == 0) {
LAB_080b2c04:
    sub_080AA184(0x8002c88,1,0xd,0);
  }
  else {
    if (uVar1 != 1) {
      if (uVar1 != 2) {
        if (uVar1 == 3) {
          sub_080AA184(0x8002c88,1,0xd,0);
          sub_080AA184(0x8002c70,1,0xd,0);
          sub_080AA184(0x8002de8,1,0xd,0);
          sub_080AA184(0x8002e24,1,0xd,0);
        }
        goto LAB_080b2ca8;
      }
      sub_080AA184(0x8002d78,1,0xd,0);
      sub_080AA184(0x8002dac,1,0xd,0);
      goto LAB_080b2c04;
    }
    sub_080AA184(0x8002c88,1,0xd,0);
  }
  sub_080AA184(0x8002c70,1,0xd,0);
LAB_080b2ca8:
                    /* WARNING: Could not recover jumptable at 0x080b2cae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B2CC0 @ 0x080B2CC0

void sub_080B2CC0(void)

{
  uint uVar1;
  int iVar2;
  dword dVar3;
  
  uVar1 = DAT_03004574;
  sub_080AE574((uint)DAT_03004552,0);
  if (DAT_03004550 == 3) {
    sub_080B2AB0();
  }
  if (DAT_0300455e != 0) {
    iVar2 = sub_080ADF40();
    if (iVar2 == 0) {
      if (uVar1 == 0) {
        iVar2 = (uint)DAT_0300455e * 0x20 + 0x8160a0c;
        sub_080B28F8(iVar2,iVar2);
      }
      else if (uVar1 == 1) {
        sub_080B28F8((uint)DAT_0300455e * 0x20 + 0x8160e0c,(uint)DAT_0300455e * 0x20 + 0x8160a0c);
      }
      else {
        if (uVar1 == 2) {
          if (DAT_03004558 == -1) {
            iVar2 = (uint)DAT_0300455e << 5;
            dVar3 = 0x816120c;
          }
          else {
            iVar2 = (uint)DAT_0300455e << 5;
            dVar3 = 0x816160c;
          }
        }
        else {
          if (uVar1 != 3) {
            return;
          }
          if (DAT_03004558 == 1) {
            iVar2 = (uint)DAT_0300455e << 5;
            dVar3 = 0x8161e0c;
          }
          else {
            iVar2 = (uint)DAT_0300455e << 5;
            dVar3 = 0x8161a0c;
          }
        }
        sub_080B28F8(iVar2 + dVar3,iVar2 + 0x8160a0c);
      }
    }
    else {
      do {
        iVar2 = sub_080BA6B4(uVar1 & 0xffff);
      } while (iVar2 != 1);
    }
  }
  return;
}


// sub_080B2D94 @ 0x080B2D94

undefined4 sub_080B2D94(int *arg0,int arg1)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 in_r2;
  undefined *arg0_00;
  int unaff_r8;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  if (*arg0 == -1) {
    uVar2 = 0xffffffff;
    goto LAB_080b2ef2;
  }
  if ((((*arg0 != 0) &&
       ((*(short **)(arg1 + 0x14) == (short *)0x0 || (**(short **)(arg1 + 0x14) == 0)))) &&
      ((*(short **)(arg1 + 0x18) == (short *)0x0 || (**(short **)(arg1 + 0x18) == 0)))) &&
     (((*(short **)(arg1 + 0x1c) == (short *)0x0 || (**(short **)(arg1 + 0x1c) == 0)) &&
      (sVar1 = **(short **)(arg1 + 0x10), sVar1 != 0)))) {
    if (((DAT_03003fe8 != 0) && ((sVar1 == 3 || (unaff_r8 == 3)))) && (arg0[3] == 0)) {
      _call_via_r5();
    }
    if (((sVar1 == 3) || (unaff_r8 == 3)) || ((sVar1 == 2 || (unaff_r8 == 2)))) {
      arg0_00 = (undefined *)arg0[1];
    }
    else {
      arg0_00 = (undefined *)*arg0;
    }
    if (arg0[3] == 0) {
      _call_via_r5();
      if (DAT_030045f4 == 0) goto LAB_080b2ef0;
    }
    else if (arg0[3] == 1) {
      _call_via_r5();
      if (arg0_00 == (undefined *)0x815fd7c) {
        _call_via_r5();
      }
      else if (arg0_00 == &UNK_0815fd98) {
        _call_via_r5();
      }
      else if (arg0_00 == &UNK_0815fdb4) {
        _call_via_r5();
      }
    }
    else {
      sub_080B6F40(arg0_00);
    }
    if ((DAT_03003fe8 != 0) && (((sVar1 == 3 || (unaff_r8 == 3)) && (arg0[3] == 1)))) {
      _call_via_r5();
    }
    if (DAT_0300457c == 0) {
      uVar2 = 1;
      goto LAB_080b2ef2;
    }
  }
LAB_080b2ef0:
  uVar2 = 0;
LAB_080b2ef2:
                    /* WARNING: Could not recover jumptable at 0x080b2efa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar2,UNRECOVERED_JUMPTABLE,in_r2,unaff_r8);
  return uVar2;
}


// sub_080B2EFC @ 0x080B2EFC

undefined4 sub_080B2EFC(uint arg0,uint arg1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = arg0 & 0xffff;
  uVar5 = arg1 & 0xffff;
  iVar1 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  puVar3 = *(uint **)(iVar1 + 0x94);
  uVar4 = (uint)DAT_03004562;
  uVar2 = (uint)DAT_03004564;
  if (DAT_03004552 == 1) {
    uVar4 = uVar4 - uVar5 & 0xffff;
    uVar2 = uVar2 + uVar6;
  }
  else if (DAT_03004552 < 2) {
    if (DAT_03004552 != 0) goto LAB_080b2f6c;
    uVar4 = uVar4 + uVar6 & 0xffff;
    uVar2 = uVar2 + uVar5;
  }
  else if (DAT_03004552 == 2) {
    uVar4 = uVar4 - uVar6 & 0xffff;
    uVar2 = uVar2 - uVar5;
  }
  else {
    if (DAT_03004552 != 3) goto LAB_080b2f6c;
    uVar4 = uVar4 + uVar5 & 0xffff;
    uVar2 = uVar2 - uVar6;
  }
  uVar2 = uVar2 & 0xffff;
LAB_080b2f6c:
  if ((((-1 < (int)(uVar4 * 0x10000)) && (-1 < (int)(uVar2 * 0x10000))) && (uVar4 < DAT_0300456a))
     && (uVar2 < DAT_0300456c)) {
    for (; *puVar3 != 0xffffffff; puVar3 = puVar3 + 1) {
      if ((*puVar3 == uVar4) && (puVar3[1] == uVar2)) {
        return puVar3 + 2;
      }
      puVar3 = puVar3 + 2;
      do {
        puVar3 = puVar3 + *(int *)((*puVar3 & 0xffff) * 4 + 0x816222c);
      } while (*puVar3 != 0xfffffffe);
    }
  }
  return 0;
}


// sub_080B2FDC @ 0x080B2FDC

void sub_080B2FDC(uint arg0,uint arg1)

{
  undefined2 uVar1;
  
  uVar1 = DAT_03004552;
  DAT_03004552 = 0;
  sub_080B2EFC(arg0 & 0xffff,arg1 & 0xffff);
  DAT_03004552 = uVar1;
  return;
}


// sub_080B3000 @ 0x080B3000

undefined4 sub_080B3000(undefined4 arg0,undefined4 arg1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  
  uVar3 = DAT_03004564;
  uVar2 = DAT_03004562;
  uVar1 = DAT_03004552;
  DAT_03004552 = 0;
  DAT_03004562 = (undefined2)arg0;
  DAT_03004564 = (undefined2)arg1;
  uVar4 = sub_080B2EFC(0,0);
  DAT_03004552 = uVar1;
  DAT_03004562 = uVar2;
  DAT_03004564 = uVar3;
  return uVar4;
}


// sub_080B3038 @ 0x080B3038

undefined4 sub_080B3038(uint *arg0,uint arg1)

{
  undefined4 uVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg0 != (uint *)0x0) {
    for (; *arg0 != 0xfffffffe; arg0 = arg0 + *(int *)(uVar2 * 4 + 0x816222c)) {
      uVar2 = *arg0 & 0xffff;
      if (uVar2 == (arg1 & 0xffff)) goto LAB_080b3072;
    }
  }
  arg0 = (uint *)0x0;
LAB_080b3072:
                    /* WARNING: Could not recover jumptable at 0x080b3076. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(arg0);
  return uVar1;
}


// sub_080B3078 @ 0x080B3078

uint sub_080B3078(uint arg0,uint arg1,uint arg2)

{
  undefined4 arg0_00;
  int iVar1;
  
  arg0_00 = sub_080B2EFC(arg0 & 0xffff,arg1 & 0xffff);
  iVar1 = sub_080B3038(arg0_00,arg2 & 0xffff);
  return (uint)(iVar1 != 0);
}


// sub_080B30A0 @ 0x080B30A0

void sub_080B30A0(void)

{
  byte bVar1;
  uint uVar2;
  int arg0;
  int iVar3;
  uint arg1;
  uint arg2;
  uint uVar4;
  
  uVar2 = sub_080C8B3C((uint)(ushort)DAT_03004614);
  bVar1 = DAT_03005f80._2_1_;
  uVar2 = uVar2 & 0xffff;
  arg1 = (uint)DAT_03005f80._2_1_;
  arg2 = DAT_03005f80._3_1_ & 0x3f;
  arg0 = sub_080C8B10((uint)(ushort)DAT_03004614,0);
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      if ((((*(ushort *)(arg0 + 8) <= arg1) && (*(ushort *)(arg0 + 10) <= arg2)) &&
          (arg1 <= *(ushort *)(arg0 + 0xc))) &&
         ((arg2 <= *(ushort *)(arg0 + 0xe) && (iVar3 = sub_080B7944(arg0,arg1,arg2), iVar3 == 1))))
      {
        DAT_03004562 = (ushort)bVar1 - *(short *)(arg0 + 8);
        DAT_03004564 = (short)arg2 - *(short *)(arg0 + 10);
        DAT_03004552 = (ushort)(DAT_03005f80._3_1_ >> 6);
        DAT_03004554 = DAT_03004552;
        sub_080AE2C0();
        DAT_030029b0 = *DAT_03004630;
        sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
        sub_080ACFCC(3,DAT_03004510,&DAT_03002b50,0x20);
        return;
      }
      if (uVar2 - 1 == DAT_03004514) {
        return;
      }
      DAT_03004514 = DAT_03004514 + 1;
      sub_080ADFEC((uint)(ushort)DAT_03004544);
      sub_080AE234();
      uVar4 = uVar4 + 1 & 0xffff;
      arg0 = arg0 + 0x268;
    } while (uVar4 < uVar2);
  }
  return;
}


// sub_080B31C4 @ 0x080B31C4

/* WARNING: Restarted to delay deadcode elimination for space: ram */

void sub_080B31C4(undefined4 arg0,uint arg1,undefined4 arg2)

{
  short sVar1;
  uint arg0_00;
  int iVar2;
  undefined4 uVar3;
  uint arg1_00;
  uint arg0_01;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  uint local_28;
  
  arg1_00 = arg1 & 0xffff;
  local_28 = 0;
  do {
    DAT_03004562 = 0;
    DAT_03004564 = 0;
    uVar4 = 0;
    if (DAT_0300456c != 0) {
      do {
        arg0_01 = 0;
        if (DAT_0300456a != 0) {
          do {
            arg0_00 = arg0_01;
            sub_080B2FDC(arg0_01,uVar4);
            iVar2 = sub_080B3038(arg0_00,arg1_00);
            if (iVar2 != 0) {
              if ((arg1_00 == 1) || (arg1_00 == 2)) {
LAB_080b3240:
                sVar1 = *(short *)(iVar2 + 4);
LAB_080b3242:
                if (sVar1 != (short)arg2) goto LAB_080b3258;
              }
              else {
                if (arg1_00 == 0x1b) {
                  sVar1 = *(short *)(iVar2 + 6);
                  goto LAB_080b3242;
                }
                if (arg1_00 == 0x1c) {
                  sVar1 = *(short *)(iVar2 + 6);
                  goto LAB_080b3242;
                }
                if (arg1_00 == 3) goto LAB_080b3240;
                if ((arg1_00 == 10) && (*(short *)(iVar2 + 2) != (short)arg2)) {
                  iVar2 = 0;
                }
              }
              if (iVar2 != 0) {
                DAT_03004562 = (short)arg0_01 + DAT_03004562;
                DAT_03004564 = (short)uVar4 + DAT_03004564;
                sub_080AE2C0();
                DAT_030050f8 = 0;
                uVar3 = 1;
                goto LAB_080b3336;
              }
            }
LAB_080b3258:
            arg0_01 = arg0_01 + 1 & 0xffff;
          } while (arg0_01 < DAT_0300456a);
        }
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 < DAT_0300456c);
    }
    if (arg1_00 == 1) {
      DAT_03004514 = DAT_03004514 - 1;
    }
    else if ((arg1_00 == 2) || ((arg1_00 - 0x1b & 0xffff) < 2)) {
      DAT_03004514 = DAT_03004514 + 1;
    }
    else if (arg1_00 == 3) {
      if (DAT_03004634 < DAT_03004514) {
        DAT_03004514 = DAT_03004514 + 1;
      }
      else {
        DAT_03004514 = DAT_03004514 - 1;
      }
    }
    else {
      if (arg1_00 != 10) {
        uVar3 = 0;
LAB_080b3336:
                    /* WARNING: Could not recover jumptable at 0x080b3344. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(uVar3);
        return;
      }
      if (local_28 == 0) {
        DAT_03004514 = local_28;
        local_28 = 1;
      }
      else {
        DAT_03004514 = DAT_03004514 + 1;
        uVar4 = sub_080C8B3C(DAT_03004614 & 0xffff);
        if (uVar4 == DAT_03004514) {
          if (DAT_03004614 == 0x4f) {
            DAT_03004614 = 0;
            DAT_03004514 = 0;
          }
          else {
            DAT_03004614 = DAT_03004614 + 1;
            DAT_03004514 = 0;
          }
        }
      }
    }
    sub_080AE234();
  } while( true );
}


// sub_080B3348 @ 0x080B3348

void sub_080B3348(uint arg0,uint arg1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint arg0_00;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint arg0_01;
  int iVar6;
  uint arg0_02;
  uint arg1_00;
  uint arg1_01;
  
  uVar2 = DAT_03004564;
  uVar1 = DAT_03004562;
  arg0_00 = arg0 & 0xffff;
  uVar3 = DAT_03004614 & 0xffff;
  uVar4 = DAT_03004514 & 0xffff;
  uVar5 = sub_080C8B3C(arg0_00);
  arg1_01 = 0;
  if ((uVar5 & 0xffff) != 0) {
    do {
      sub_080C8B10(arg0_00,arg1_01);
      DAT_03004514 = arg1_01;
      DAT_03004614 = arg0_00;
      sub_080AE234();
      DAT_03004562 = 0;
      DAT_03004564 = 0;
      arg1_00 = 0;
      if (DAT_0300456c != 0) {
        do {
          arg0_02 = 0;
          if (DAT_0300456a != 0) {
            do {
              arg0_01 = arg0_02;
              sub_080B2FDC(arg0_02,arg1_00);
              iVar6 = sub_080B3038(arg0_01,arg1 & 0xffff);
              if (iVar6 != 0) goto LAB_080b3400;
              arg0_02 = arg0_02 + 1 & 0xffff;
            } while (arg0_02 < DAT_0300456a);
          }
          arg1_00 = arg1_00 + 1 & 0xffff;
        } while (arg1_00 < DAT_0300456c);
      }
      arg1_01 = arg1_01 + 1 & 0xffff;
    } while (arg1_01 < (uVar5 & 0xffff));
  }
LAB_080b3400:
  DAT_03004514 = uVar4;
  DAT_03004562 = uVar1;
  DAT_03004564 = uVar2;
  DAT_03004614 = uVar3;
  sub_080AE234();
  return;
}


// sub_080B343C @ 0x080B343C

void sub_080B343C(uint arg0)

{
  int iVar1;
  uint uVar2;
  
  if ((int)(arg0 * 0x10000) < 0) {
    iVar1 = (uint)DAT_0300457e + (arg0 & 0xffff);
    DAT_0300457e = (ushort)iVar1;
    if (iVar1 * 0x10000 < 0) {
      DAT_0300457e = 0;
    }
  }
  else {
    uVar2 = (uint)DAT_0300457e + (arg0 & 0xffff);
    DAT_0300457e = (ushort)uVar2;
    if (0x21 < (uVar2 & 0xffff)) {
      DAT_0300457e = 0x21;
    }
  }
  return;
}


// sub_080B3478 @ 0x080B3478

void sub_080B3478(int arg0,int arg1)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    iVar1 = sub_080B0248(0,0,0);
    if (iVar1 == 2) {
      sub_080B343C(2);
    }
    else if ((DAT_030031bc & 3) == 0) {
      sub_080B343C(1);
    }
    if (DAT_0300457e < 0x21) {
      *(undefined2 *)(arg0 + 0x1c) = 0;
    }
    else {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    DAT_03000038 = 0x3f;
    DAT_03000039 = 0x3f;
    DAT_0300003a = 0x3f;
  }
                    /* WARNING: Could not recover jumptable at 0x080b34d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B34E8 @ 0x080B34E8

void sub_080B34E8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x81622d0;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000070;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B350C @ 0x080B350C

void sub_080B350C(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
  REG_DMA3SAD = *(undefined4 *)(iVar2 + 0x170 + (uint)DAT_030050f8 * 0xe8);
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000100;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B3560 @ 0x080B3560

void sub_080B3560(void)

{
  if (DAT_03004614 == 0x42) {
    sub_080C51D4(0x6c);
  }
  else {
    sub_080C51D4(0x6b);
  }
  return;
}


// sub_080B3584 @ 0x080B3584

void sub_080B3584(undefined4 arg0)

{
  int iVar1;
  int iVar2;
  dword dVar3;
  
  iVar1 = sub_080B0248(0,0,0);
  iVar2 = sub_080B2938();
  if (iVar1 == 2) {
    DisplayList_Add(0x80ae1c5,1);
    sub_080B3560();
    if (iVar2 == 2) {
      dVar3 = 0x80b34e9;
    }
    else {
      if (iVar2 != 3) goto LAB_080b35e2;
      dVar3 = 0x80b350d;
    }
    DisplayList_Add(dVar3,1);
  }
  else {
    DisplayList_Add(0x80ae1fd,1);
    sub_080C51D4(0x6d);
  }
LAB_080b35e2:
  iVar1 = sub_080B098C();
  if (iVar1 == 0) {
    iVar1 = sub_080B3078(0,0,6);
    dVar3 = DAT_03003fc8;
    if (iVar1 != 0) {
      dVar3 = 0x200f854;
    }
    sub_080ACFCC(3,dVar3,0x3003150,0x20);
  }
  else {
    sub_080ACFA4(3,0,0x3003150,0x20);
  }
  sub_080AABB0();
  return;
}


// sub_080B3644 @ 0x080B3644

void sub_080B3644(undefined4 arg0,undefined4 arg1)

{
  sub_080AE494();
  return;
}


// sub_080B3650 @ 0x080B3650

void sub_080B3650(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_0300455e == 0);
  return;
}


// sub_080B366C @ 0x080B366C

void sub_080B366C(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080B3078(0,0xffff,4);
  if (iVar1 == 1) {
    iVar1 = sub_080C2340(0xae);
    if (iVar1 == 0) {
      DAT_0300452c = sub_080AAF48(1);
      DAT_0200e808 = 1;
    }
    else {
      sub_080B0620();
    }
  }
  else {
    sub_080B0620();
  }
                    /* WARNING: Could not recover jumptable at 0x080b36b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B36B4 @ 0x080B36B4

void sub_080B36B4(int arg0)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 arg0_00;
  int iVar3;
  
  iVar2 = sub_080C8B10(DAT_03004614 & 0xffff,DAT_03004514 & 0xffff);
  DAT_0300000e = 0;
  arg0_00 = sub_080B2EFC(0,0xffff);
  iVar3 = sub_080B3038(arg0_00,0x20);
  if (iVar3 != 0) {
    DAT_030050f8 = *(ushort *)(iVar3 + 2);
    DAT_03003bb4 = 0;
  }
  if ((DAT_03003bb4 == *(int *)(iVar2 + 0xd8 + (uint)DAT_030050f8 * 0xe8)) &&
     (DAT_0300462c == *(int *)(iVar2 + 0x138 + (uint)DAT_030050f8 * 0xe8))) {
    sub_080ADCCC(DAT_03004614,DAT_03004514);
    sub_080AE234();
    DAT_030029b0 = *DAT_03004630;
    sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
    sub_080ACFCC(3,DAT_03004510,&DAT_03002b50,0x20);
    uVar1 = 1;
  }
  else {
    sub_080ADCCC(DAT_03004614,DAT_03004514);
    sub_080AE234();
    sub_080AD7F0();
    uVar1 = 0;
  }
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
  return;
}


// sub_080B37AC @ 0x080B37AC

void sub_080B37AC(int arg0,int arg1)

{
  bool bVar1;
  
  if (arg1 == 0) {
    DAT_03003bbc = 0;
  }
  else {
    bVar1 = DAT_03003bbc != -1;
    if (bVar1) {
      DisplayList_Add(0x80ae0bd,1);
    }
    *(ushort *)(arg0 + 0x1c) = (ushort)!bVar1;
  }
  return;
}


// sub_080B37F0 @ 0x080B37F0

void sub_080B37F0(undefined4 arg0,int arg1)

{
  sub_080B02A0((uint)DAT_03004552);
  if (arg1 == 0) {
    sub_080B2840(0,0,0);
  }
  return;
}


// sub_080B3814 @ 0x080B3814

void sub_080B3814(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AF8D0(1,1,0);
  if (iVar1 == 0) {
    sub_080AE494();
    sub_080B05A4();
    DAT_0300457e = 0;
    Field_SetState(4);
    iVar1 = sub_080B2EFC(0,1);
    DAT_03004596 = (undefined2)arg1;
    if (iVar1 != 0) {
      DAT_03004596 = 1;
    }
  }
  return;
}


// sub_080B3868 @ 0x080B3868

void sub_080B3868(void)

{
  DAT_030045ae = 0;
  return;
}


// sub_080B3878 @ 0x080B3878

void sub_080B3878(undefined4 arg0)

{
  dword arg0_00;
  
  arg0_00 = 0x81625d0;
  if ((short)arg0 == 0) {
    arg0_00 = 0x8162490;
  }
  sub_080AD0FC(arg0_00,0xffff);
  DAT_0300457e = 0;
  return;
}


// sub_080B38A8 @ 0x080B38A8

undefined4 sub_080B38A8(void)

{
  undefined4 uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined2 local_10 [2];
  
  uVar6 = 0;
  switch(DAT_0300456e) {
  case 0:
    sub_080C14FC();
    sub_080AB438(0,0x2000000,1,0);
    local_10[0] = 0;
    REG_DMA3SAD = local_10;
    REG_DMA3DAD = 0x3002eb0;
    REG_DMA3CNT = 0x81000080;
    uVar1 = REG_DMA3CNT;
    DisplayList_Add(0x80b41f9,1);
    break;
  default:
    DisplayList_Add(0x80b41f9,1);
    break;
  case 2:
    iVar3 = sub_080B3EA4(0);
    if (iVar3 == 1) {
      DAT_0300456e = DAT_0300456e + 1;
    }
    break;
  case 6:
    sub_080B0778();
    DAT_0300456e = DAT_0300456e + 1;
    pcVar5 = (char *)0x3002db0;
    uVar2 = 0;
    do {
      if (*pcVar5 != '\0') break;
      uVar2 = uVar2 + 1;
      pcVar5 = pcVar5 + 1;
    } while (uVar2 < 0x20);
    if (uVar2 == 0x20) {
      sub_080AAFBC(0,0x80,1);
      sub_080AAFBC(0x100,0xd0,1);
    }
    break;
  case 7:
    uVar4 = sub_080AB184();
    if ((uVar4 & 0xffff) == 1) {
      DAT_0300456e = DAT_0300456e + 1;
      DAT_0200e808 = 0;
      iVar3 = sub_080C2340(0x105);
      if (iVar3 != 0) {
        sub_080C23BC(0x102);
        sub_080C23BC(0x106);
        sub_080C23BC(0x105);
      }
    }
    break;
  case 8:
    uVar6 = 1;
    break;
  case 9:
    iVar3 = sub_080B092C();
    if (iVar3 == 0) {
      sub_080C14FC();
      DAT_0300456e = 0x14;
      sub_080B7530();
    }
    break;
  case 0x1c:
    sub_080C3818(1);
    iVar3 = sub_080B0204(0);
    if (((iVar3 == 0) && (iVar3 = sub_080B0204(1), iVar3 == 0)) &&
       (iVar3 = sub_080B0204(3), iVar3 == 0)) {
      uVar4 = sub_080B1A1C((uint)DAT_03004552);
      DAT_03004552 = (ushort)uVar4;
      sub_080B2030((uint)DAT_0300455a,uVar4 & 0xffff,3);
    }
    else {
      sub_080B05A4();
      Field_SetState(0x1f);
      sub_080B2840(0,0,0);
      DAT_0300456e = 0;
    }
    uVar6 = 0xffffffff;
  }
  return uVar6;
}


// sub_080B3ADC @ 0x080B3ADC

void sub_080B3ADC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6004040;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B3B00 @ 0x080B3B00

void sub_080B3B00(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6005040;
  REG_DMA3CNT = 0x840003f0;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x200bf88;
  REG_DMA3DAD = 0x6008040;
  REG_DMA3CNT = 0x84000010;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B3B3C @ 0x080B3B3C

void sub_080B3B3C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6008080;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B3B60 @ 0x080B3B60

void sub_080B3B60(void)

{
  dword dVar1;
  
  if (DAT_03003ba0 == 0) {
    REG_DMA3SAD = 0x200afc8;
    dVar1 = 0x6009080;
  }
  else {
    REG_DMA3SAD = 0x200afc8;
    dVar1 = 0x6008e00;
  }
  REG_DMA3DAD = dVar1;
  REG_DMA3CNT = 0x84000400;
  return;
}


// sub_080B3BA4 @ 0x080B3BA4

void sub_080B3BA4(void)

{
  dword dVar1;
  
  if (DAT_03003ba0 == 0) {
    REG_DMA3SAD = 0x200afc8;
    dVar1 = 0x600a080;
  }
  else {
    REG_DMA3SAD = 0x200afc8;
    dVar1 = 0x6009e00;
  }
  REG_DMA3DAD = dVar1;
  REG_DMA3CNT = 0x84000400;
  return;
}


// sub_080B3BE8 @ 0x080B3BE8

void sub_080B3BE8(void)

{
  dword dVar1;
  
  if (DAT_03003ba0 == 0) {
    REG_DMA3SAD = 0x200afc8;
    REG_DMA3DAD = 0x600b080;
    dVar1 = 0x840002c0;
  }
  else {
    REG_DMA3SAD = 0x200afc8;
    REG_DMA3DAD = 0x600ae00;
    dVar1 = 0x84000360;
  }
  REG_DMA3CNT = dVar1;
  return;
}


// sub_080B3C34 @ 0x080B3C34

void sub_080B3C34(int arg0,int arg1)

{
  int arg0_00;
  
  arg0_00 = *(int *)(arg0 * 4 + 0x81625d4);
  if (arg0_00 != 0) {
    if (arg1 == 0) {
      DisplayList_Add(arg0_00,1);
    }
    else {
      _call_via_r0(arg0_00);
    }
  }
  return;
}


// sub_080B3C5C @ 0x080B3C5C

void sub_080B3C5C(undefined4 arg0)

{
  ushort uVar1;
  int *piVar2;
  dword dVar3;
  int arg0_00;
  dword arg2;
  code *UNRECOVERED_JUMPTABLE;
  uint local_24;
  
  piVar2 = (int *)sub_080C5EF0((uint)DAT_03004534);
  if (DAT_03003ba0 != 0) {
    uVar1 = DAT_03003bac & 0x8000;
    if (uVar1 == 0) {
      arg0_00 = sub_080C5F04((uint)DAT_03004534,(uint)DAT_03003bac);
      if (arg0_00 == 0) {
        if (DAT_03003bac < 8) {
          DAT_03003bac = 8;
        }
        else {
          DAT_03003bac = 0xffff;
        }
      }
      else {
        dVar3 = 0x1000400;
        local_24 = (uint)uVar1;
        CpuFastSet(&local_24,0x200afc8,0x1000400);
        if (DAT_03003bac < 8) {
          if (*piVar2 == 1) {
            LZ77UnCompWram(arg0_00,0x200afc8,dVar3);
            sub_080B3C34((uint)DAT_03003bac,arg0);
            DAT_03003bac = DAT_03003bac + 1;
          }
          else if (*piVar2 == 2) {
            HuffUnComp(arg0_00,&DAT_0200bfc8,0x1000);
            DAT_03003bac = DAT_03003bac | 0x8000;
          }
        }
        else if (*piVar2 == 1) {
          LZ77UnCompWram(arg0_00,0x200afc8,dVar3);
          sub_080B3C34(DAT_03003bac - 5,arg0);
          DAT_03003bac = DAT_03003bac + 1;
        }
        else if (*piVar2 == 2) {
          HuffUnComp(arg0_00,&DAT_0200bfc8,0x1000);
          DAT_03003bac = DAT_03003bac | 0x8000;
        }
      }
    }
    else {
      DAT_03003bac = DAT_03003bac & 0x7fff;
      LZ77UnCompWram(0x200bfc8,&DAT_0200afc8,0xfffff000);
      if (DAT_03003bac < 8) {
        sub_080B3C34((uint)DAT_03003bac,arg0);
      }
      else {
        sub_080B3C34(DAT_03003bac - 5,arg0);
      }
      DAT_03003bac = DAT_03003bac + 1;
    }
    goto LAB_080b3e28;
  }
  uVar1 = DAT_03003bac & 0x8000;
  if (uVar1 == 0) {
    dVar3 = sub_080C5F04((uint)DAT_03004534,(uint)DAT_03003bac);
    if (dVar3 == 0) {
      DAT_03003bac = 0xffff;
      goto LAB_080b3e28;
    }
    arg2 = 0x1000400;
    local_24 = (uint)uVar1;
    CpuFastSet(&local_24,0x200afc8,0x1000400);
    if (*piVar2 != 1) {
      if (*piVar2 == 2) {
        HuffUnComp(dVar3,&DAT_0200bfc8,0x1000);
        DAT_03003bac = DAT_03003bac | 0x8000;
      }
      goto LAB_080b3e28;
    }
  }
  else {
    DAT_03003bac = DAT_03003bac & 0x7fff;
    dVar3 = 0x200bfc8;
    arg2 = 0xfffff000;
  }
  LZ77UnCompWram(dVar3,&DAT_0200afc8,arg2);
  sub_080B3C34((uint)DAT_03003bac,arg0);
  DAT_03003bac = DAT_03003bac + 1;
LAB_080b3e28:
                    /* WARNING: Could not recover jumptable at 0x080b3e36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B3E3C @ 0x080B3E3C

void sub_080B3E3C(void)

{
  int iVar1;
  
  DAT_0200ab04 = DAT_0200ab04 | 0x8000;
  DAT_03003bac = 0;
  DAT_03003ba0 = 0;
  iVar1 = sub_080C5F04((uint)DAT_03004534,8);
  if (iVar1 != 0) {
    DAT_03003ba0 = 1;
  }
  return;
}


// sub_080B3E7C @ 0x080B3E7C

void sub_080B3E7C(void)

{
  sub_080C153C();
  sub_080B3E3C();
  return;
}


// sub_080B3E8C @ 0x080B3E8C

void sub_080B3E8C(void)

{
  ushort uVar1;
  
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 & 0xf7ff;
  return;
}


// sub_080B3EA0 @ 0x080B3EA0

void sub_080B3EA0(void)

{
  return;
}


// sub_080B3EA4 @ 0x080B3EA4

uint sub_080B3EA4(undefined4 arg0)

{
  bool bVar1;
  
  bVar1 = DAT_03003bac != -1;
  if (bVar1) {
    sub_080B3C5C(arg0);
  }
  else {
    sub_080B3EA0();
  }
  return (uint)!bVar1;
}


// sub_080B3ED0 @ 0x080B3ED0

void sub_080B3ED0(void)

{
  int iVar1;
  int iVar2;
  undefined4 arg2;
  
  iVar1 = sub_080C5EF0((uint)DAT_03004534);
  if (*(int *)(iVar1 + 0x4c) != 0) {
    arg2 = 0x50;
    if ((*(int *)(iVar1 + 0x4c) == 0x194) && (iVar2 = sub_080C2340(0x37), iVar2 != 0)) {
      arg2 = 0x20;
    }
    sub_080C4618(0,*(uint *)(iVar1 + 0x4c) & 0xffff,arg2,5);
  }
  return;
}


// sub_080B3F1C @ 0x080B3F1C

void sub_080B3F1C(void)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int *piVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  short *psVar8;
  uint uVar9;
  short *psVar10;
  uint uVar11;
  short sVar12;
  
  piVar4 = (int *)sub_080C5EF0((uint)DAT_03004534);
  if (*piVar4 == 0) {
    if (DAT_03003ba0 == 0) {
      REG_DMA3SAD = 0x81c25f0;
    }
    else {
      REG_DMA3SAD = 0x81c32f4;
    }
  }
  else if (DAT_03003ba0 == 0) {
    pbVar5 = (byte *)sub_080C5F40((uint)DAT_03004534,0);
    if ((ushort)(DAT_03004534 - 0xd9) < 2) {
      sVar12 = 8;
      if (DAT_03004534 == 0xda) {
        sVar12 = 7;
      }
      REG_DMA3SAD = 0x81c2c74;
      REG_DMA3DAD = 0x2000000;
      REG_DMA3CNT = 0x84000400;
      uVar3 = REG_DMA3CNT;
      uVar6 = 0;
      do {
        uVar9 = 0;
        uVar11 = uVar6 + 1;
        psVar8 = (short *)(uVar6 * 0x40 + 0x2000000);
        do {
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 1;
          *psVar8 = ((bVar1 & 0xf) + sVar12) * 0x1000 + *psVar8;
          psVar8 = psVar8 + 1;
          uVar9 = uVar9 + 1;
        } while (uVar9 < 0x1e);
        uVar6 = uVar11;
      } while (uVar11 < 0x1a);
    }
    else {
      REG_DMA3SAD = 0x81c25f4;
      REG_DMA3DAD = 0x2000000;
      REG_DMA3CNT = 0x84000400;
      uVar3 = REG_DMA3CNT;
      uVar6 = 0;
      do {
        uVar9 = 0;
        uVar11 = uVar6 + 1;
        psVar8 = &DAT_02000002 + uVar6 * 0x20;
        do {
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 1;
          *psVar8 = ((bVar1 & 0xf) + 8) * 0x1000 + *psVar8;
          psVar8 = psVar8 + 1;
          uVar9 = uVar9 + 1;
        } while (uVar9 < 0x1c);
        uVar6 = uVar11;
      } while (uVar11 < 0x1a);
    }
    REG_DMA3SAD = 0x2000000;
  }
  else {
    pbVar5 = (byte *)sub_080C5F40((uint)DAT_03004534,0);
    pbVar7 = (byte *)sub_080C5F40((uint)DAT_03004534,1);
    REG_DMA3SAD = 0x81c32f8;
    REG_DMA3DAD = 0x2000000;
    REG_DMA3CNT = 0x84000400;
    uVar3 = REG_DMA3CNT;
    uVar6 = 0;
    do {
      uVar11 = 0;
      uVar9 = uVar6 + 1;
      psVar8 = &DAT_02000002 + uVar6 * 0x20;
      psVar10 = (short *)((uVar6 * 0x20 + 0x1c) * 2 + 0x2000000);
      do {
        bVar1 = *pbVar5;
        pbVar5 = pbVar5 + 1;
        bVar2 = *pbVar7;
        pbVar7 = pbVar7 + 1;
        *psVar8 = ((bVar1 & 0xf) + 8) * 0x1000 + *psVar8;
        *psVar10 = ((bVar2 & 0xf) + 8) * 0x1000 + *psVar10;
        psVar10 = psVar10 + -1;
        psVar8 = psVar8 + 1;
        uVar11 = uVar11 + 1;
      } while (uVar11 < 0xe);
      uVar6 = uVar9;
    } while (uVar9 < 0x1a);
    REG_DMA3SAD = 0x2000000;
  }
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000400;
  if (DAT_03004608 == 1) {
    DAT_0300000e = DAT_03004600;
    DAT_03004608 = 0;
  }
  else if (DAT_030020e4 == 0x815c381) {
    DAT_0300000e = 0x50;
  }
  else {
    DAT_0300000e = (undefined2)piVar4[0x16];
  }
  sub_080BDF3C((uint)DAT_03004534);
  return;
}


// sub_080B4140 @ 0x080B4140

void sub_080B4140(void)

{
  undefined4 uVar1;
  undefined1 local_c [4];
  
  uVar1 = sub_080C5F60((uint)DAT_03004534);
  if (DAT_03004534 == 0x77) {
    REG_DMA3SAD = local_c;
    REG_DMA3DAD = 0x3002ab0;
    REG_DMA3CNT = 0x85000040;
    uVar1 = REG_DMA3CNT;
  }
  else if (DAT_03004534 == 0xda) {
    sub_080ACFCC(3,uVar1,0x3002a90,0x20);
  }
  else {
    sub_080ACFCC(3,uVar1,0x3002ab0,0x100);
  }
  return;
}


// sub_080B41B0 @ 0x080B41B0

void sub_080B41B0(void)

{
  ushort uVar1;
  
  sub_080B4140();
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 | 0x800;
  return;
}


// sub_080B41CC @ 0x080B41CC

void sub_080B41CC(void)

{
  ushort uVar1;
  
  REG_BG3CNT = 0x8607;
  uVar1 = REG_DISPCNT;
  REG_DISPCNT = uVar1 & 0xf7ff;
  DAT_0300000e = 0;
  return;
}


// sub_080B41F8 @ 0x080B41F8

void sub_080B41F8(void)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined1 local_8 [8];
  
  sub_080C5EF0((uint)DAT_03004534);
  switch(DAT_0300456e) {
  case 0:
    sub_080B3E7C();
    break;
  case 1:
    sub_080B3E8C();
    break;
  case 3:
    sub_080B3ED0();
    break;
  case 4:
    sub_080B3F1C();
    break;
  case 5:
    sub_080B41B0();
    break;
  case 0x14:
  case 0x1a:
    sub_080C153C();
    break;
  case 0x15:
    sub_080B41CC();
    break;
  case 0x16:
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x2028074;
    REG_DMA3CNT = 0x85000008;
    uVar2 = REG_DMA3CNT;
    REG_DMA3SAD = DAT_03003b94;
    REG_DMA3DAD = 0x6004000;
    REG_DMA3CNT = 0x84000800;
    uVar2 = REG_DMA3CNT;
    break;
  case 0x17:
    DAT_030029b0 = *DAT_03004630;
    sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
    break;
  case 0x18:
    sub_080ACFCC(3,DAT_03004510,0x3002b50,0x20);
    break;
  case 0x19:
    sub_080ADF64();
    break;
  case 0x1b:
    uVar1 = REG_DISPCNT;
    REG_DISPCNT = uVar1 | 0x800;
    DAT_0200ab04 = DAT_0200ab04 & 0xffff7fff;
  }
  DAT_0300456e = DAT_0300456e + 1;
  return;
}


// sub_080B437C @ 0x080B437C

void sub_080B437C(void)

{
  int iVar1;
  
  sub_080C14FC();
  sub_080AB438(0,0x2000000,1,0);
  sub_080B3E7C();
  sub_080B3E8C();
  do {
    iVar1 = sub_080B3EA4(1);
  } while (iVar1 != 1);
  sub_080B3ED0();
  sub_080B3F1C();
  sub_080B41B0();
  return;
}


// sub_080B43C0 @ 0x080B43C0

void sub_080B43C0(int arg0)

{
  bool bVar1;
  
  bVar1 = false;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031bc & 1) == 0) {
    if (*(short *)(arg0 + 0x24) == 0) {
      bVar1 = true;
    }
    else {
      if (*(short *)(arg0 + 0x26) == 1) {
        if (DAT_0300000e != 0) {
          DAT_0300000e = DAT_0300000e + -1;
        }
      }
      else {
        DAT_0300000e = DAT_0300000e + 1;
      }
      *(short *)(arg0 + 0x24) = *(short *)(arg0 + 0x24) + -1;
    }
  }
  if (bVar1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080B4420 @ 0x080B4420

int sub_080B4420(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x81625f4,0xffff);
  *(undefined2 *)(iVar1 + 0x24) = (undefined2)arg0;
  *(undefined2 *)(iVar1 + 0x26) = (undefined2)arg1;
  return iVar1;
}


// sub_080B4448 @ 0x080B4448

undefined4 sub_080B4448(int arg0)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = (int *)0x8162618;
  uVar2 = 0;
  while ((*(int *)(arg0 + 4) != *piVar1 || (*(int *)(arg0 + 8) != piVar1[1]))) {
    piVar1 = piVar1 + 3;
    uVar2 = uVar2 + 1;
    if (0x50 < uVar2) {
      return 0x3b4;
    }
  }
  return (uint)*(ushort *)(piVar1 + 2);
}


