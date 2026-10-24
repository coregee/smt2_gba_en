/* Ghidra decompilation of asm/code_080C2D48.s (reference only; not compiled). */

// sub_080C2D48 @ 0x080C2D48

void sub_080C2D48(undefined4 arg0,undefined4 arg1)

{
  DAT_03005f6c = (ushort)arg0 & 0xff;
  DAT_03005f6e = (ushort)arg1 & 0xff;
  return;
}


// sub_080C2D78 @ 0x080C2D78

void sub_080C2D78(int arg0,int arg1)

{
  uint arg2;
  
  arg2 = (uint)((arg1 << 0x18) >> 8) >> 0x10;
  sub_080C12C0((uint)((arg0 << 0x18) >> 8) >> 0x10,0,arg2);
  DAT_03005180 = 0;
  sub_080C2230(0);
  sub_080C2D48((uint)(ushort)DAT_03003fc4,arg2);
  sub_080C2CC0();
  return;
}


// sub_080C2DC0 @ 0x080C2DC0

void sub_080C2DC0(undefined4 arg0)

{
  DAT_03004534 = (undefined2)arg0;
  sub_080C1300(0x14);
  DAT_0300456e = 0;
  return;
}


// sub_080C2DE0 @ 0x080C2DE0

void sub_080C2DE0(undefined4 arg0,undefined4 arg1)

{
  DAT_03004534 = (undefined2)arg0;
  DAT_0300453c = arg1;
  sub_080C1300(0x1c);
  DAT_03004544 = 5;
  DAT_0300456e = 0;
  return;
}


// sub_080C2E10 @ 0x080C2E10

void sub_080C2E10(undefined4 arg0,uint arg1)

{
  DAT_03004628 = arg1 & 0xffff;
  DAT_03004534 = (undefined2)arg0;
  sub_080C1300(0x1b);
  DAT_0300456e = 0;
  DAT_03003bb8 = 1;
  return;
}


// sub_080C2E44 @ 0x080C2E44

void sub_080C2E44(undefined4 arg0,undefined4 arg1)

{
  DAT_03004534 = (undefined2)arg0;
  DAT_03004628 = arg1;
  sub_080C1300(0x25);
  DAT_0300456e = 0;
  DAT_03003bb8 = 1;
  return;
}


// sub_080C2E74 @ 0x080C2E74

void sub_080C2E74(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x81babb0;
  REG_DMA3DAD = 0x6011c00;
  REG_DMA3CNT = 0x84000300;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x81bb850;
  REG_DMA3DAD = 0x6012400;
  REG_DMA3CNT = 0x84000080;
  uVar1 = REG_DMA3CNT;
  sub_080ACFCC(3,0x81bb7b0,0x3002d10,0x20);
  sub_080ACFCC(3,0x81bb7d0,&DAT_03002d30,0x20);
  sub_080ACFCC(3,0x81bba50,&DAT_03002cf0,0x20);
  return;
}


// sub_080C2EFC @ 0x080C2EFC

void sub_080C2EFC(void)

{
  int iVar1;
  
  DAT_0203a448 = 0;
  DAT_0203a44a = 0;
  iVar1 = sub_080C06BC(0);
  if (iVar1 == 1) {
    DAT_0203a448 = 4;
  }
  DAT_0203a44c = 9;
  sub_080C2E74();
  return;
}


// sub_080C2F34 @ 0x080C2F34

void sub_080C2F34(undefined4 arg0,undefined4 arg1)

{
  DAT_0203a44c = DAT_0203a44c + (short)arg1;
  return;
}


// sub_080C2F44 @ 0x080C2F44

void sub_080C2F44(undefined4 arg0,undefined4 arg1,uint arg2)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_03006a26 == 0) {
    if (DAT_0203a44c != 9) {
      sub_080AA184(*(undefined4 *)((uint)DAT_0203a44c * 4 + 0x81a62b0),0,0xb,arg2 & 0xffff);
    }
    if ((DAT_030031bc & 3) == 0) {
      iVar1 = sub_080C06BC(0);
      if (iVar1 == 1) {
        if (DAT_0203a44a == 0) {
          DAT_0203a448 = DAT_0203a448 + 1;
          if (0xb < DAT_0203a448) {
            DAT_0203a448 = 10;
            DAT_0203a44a = 1;
          }
        }
        else {
          DAT_0203a448 = DAT_0203a448 - 1;
          if (DAT_0203a448 < 8) {
            DAT_0203a448 = 8;
            DAT_0203a44a = 0;
          }
        }
      }
      else if (iVar1 < 2) {
        if ((iVar1 == 0) &&
           (uVar2 = (uint)DAT_0203a448, DAT_0203a448 = (ushort)(uVar2 - 1),
           (int)((uVar2 - 1) * 0x10000) < 0)) {
          DAT_0203a448 = 10;
        }
      }
      else if ((iVar1 == 2) && (DAT_0203a448 = DAT_0203a448 + 1, 0xb < DAT_0203a448)) {
        DAT_0203a448 = 0;
      }
    }
  }
  else {
    sub_080AA184(*(undefined4 *)((DAT_030031bc >> 3 & 7) * 4 + 0x81a62d4),0,10,0);
  }
                    /* WARNING: Could not recover jumptable at 0x080c3088. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C3098 @ 0x080C3098

void sub_080C3098(void)

{
  undefined4 in_r0;
  
  ScriptVM_RunAlt(in_r0);
  return;
}


// sub_080C30A8 @ 0x080C30A8

void sub_080C30A8(void)

{
  return;
}


// sub_080C30AC @ 0x080C30AC

void sub_080C30AC(int arg0)

{
  if (arg0 < 1) {
    DAT_03005198 = DAT_03005198 + arg0;
    if ((int)DAT_03005198 < 0) {
      DAT_03005198 = 0;
    }
  }
  else {
    DAT_03005198 = DAT_03005198 + arg0;
    if (999999 < DAT_03005198) {
      DAT_03005198 = 999999;
    }
  }
  return;
}


// sub_080C3100 @ 0x080C3100

undefined4 sub_080C3100(void)

{
  return DAT_03005198;
}


// sub_080C3114 @ 0x080C3114

dword sub_080C3114(int arg0)

{
  if (arg0 < 1) {
    DAT_0300519c = DAT_0300519c + arg0;
    if ((int)DAT_0300519c < 0) {
      DAT_0300519c = 0;
    }
  }
  else {
    DAT_0300519c = DAT_0300519c + arg0;
    if (99999 < DAT_0300519c) {
      DAT_0300519c = 99999;
    }
  }
  return DAT_0300519c;
}


// sub_080C3168 @ 0x080C3168

undefined4 sub_080C3168(void)

{
  return DAT_0300519c;
}


// sub_080C317C @ 0x080C317C

dword sub_080C317C(void)

{
  if ((DAT_03004614 != 0x26) && (0x26 < DAT_03004614)) {
    if (DAT_03004614 == 0x30) {
      return 0x3005f8c;
    }
    if (DAT_03004614 == 0x40) {
      return 0x3005f90;
    }
  }
  return 0x3005f88;
}


// sub_080C31B4 @ 0x080C31B4

void sub_080C31B4(int arg0)

{
  dword *pdVar1;
  dword dVar2;
  
  pdVar1 = (dword *)sub_080C317C();
  if (arg0 < 1) {
    dVar2 = *pdVar1;
    *pdVar1 = dVar2 + arg0;
    if ((int)(dVar2 + arg0) < 0) {
      *pdVar1 = 0;
    }
  }
  else {
    dVar2 = *pdVar1;
    *pdVar1 = dVar2 + arg0;
    if (999999 < dVar2 + arg0) {
      *pdVar1 = 999999;
    }
  }
  return;
}


// sub_080C31F0 @ 0x080C31F0

undefined4 sub_080C31F0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)sub_080C317C();
  return *puVar1;
}


// sub_080C31FC @ 0x080C31FC

void sub_080C31FC(undefined4 arg0)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)sub_080C317C();
  *puVar1 = arg0;
  return;
}


// sub_080C320C @ 0x080C320C

undefined4 sub_080C320C(undefined4 arg0)

{
  ushort *puVar1;
  uint uVar2;
  
  puVar1 = (ushort *)0x30051ac;
  if (((ushort)arg0 & 0x8000) != 0) {
    arg0._0_2_ = (ushort)arg0 & 0xff;
  }
  uVar2 = 0;
  while ((puVar1[1] == 0 || (*puVar1 != (ushort)arg0))) {
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 2;
    if (0x159 < uVar2) {
      return 0;
    }
  }
  return puVar1;
}


// sub_080C3250 @ 0x080C3250

undefined4 sub_080C3250(undefined4 arg0)

{
  uint uVar1;
  dword dVar2;
  ushort *puVar3;
  
  if (((ushort)arg0 & 0x8000) != 0) {
    arg0._0_2_ = (ushort)arg0 & 0xff;
  }
  uVar1 = 0;
  puVar3 = &DAT_030051ac;
  dVar2 = 0x30046c0;
  while ((*puVar3 != (ushort)arg0 || (*(short *)(dVar2 + 0xaee) == 0))) {
    puVar3 = puVar3 + 2;
    dVar2 = dVar2 + 4;
    uVar1 = uVar1 + 1;
    if (0x159 < uVar1) {
      return 0;
    }
  }
  return uVar1;
}


// sub_080C32A8 @ 0x080C32A8

undefined4 sub_080C32A8(void)

{
  dword dVar1;
  uint uVar2;
  
  dVar1 = 0x30051ac;
  uVar2 = 0;
  do {
    if (*(short *)(dVar1 + 2) == 0) {
      return dVar1;
    }
    uVar2 = uVar2 + 1;
    dVar1 = dVar1 + 4;
  } while (uVar2 < 0x15a);
  return 0;
}


// sub_080C32D4 @ 0x080C32D4

uint sub_080C32D4(uint arg0)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = arg0 & 0xffff;
  if ((arg0 & 0x8000) != 0) {
    uVar2 = arg0 & 0xff;
  }
  iVar1 = sub_080C320C(uVar2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (uint)*(byte *)(iVar1 + 2);
  }
  return uVar2;
}


// sub_080C32FC @ 0x080C32FC

uint sub_080C32FC(uint arg0)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xffff;
  if ((arg0 & 0x8000) != 0) {
    uVar1 = arg0 & 0xff;
  }
  uVar1 = sub_080C32D4(uVar1);
  return (uint)((uVar1 & 0xff) == 99);
}


// sub_080C3328 @ 0x080C3328

void sub_080C3328(uint arg0)

{
  ushort uVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  arg0_00 = arg0 & 0xffff;
  if ((arg0 & 0x8000) != 0) {
    arg0_00 = arg0 & 0xff;
  }
  puVar2 = (undefined2 *)sub_080C320C(arg0_00);
  if (puVar2 == (undefined2 *)0x0) {
    puVar2 = (undefined2 *)sub_080C32A8();
    *puVar2 = (short)arg0_00;
    uVar1 = puVar2[1];
  }
  else if (arg0_00 < 0xd0) {
    uVar3 = sub_08131AB0(0xff,arg0_00);
    uVar1 = puVar2[1];
    if (0x62 < (uint)uVar1 + (uVar3 & 0xffff)) goto LAB_080c337a;
  }
  else {
    uVar1 = puVar2[1];
    if (uVar1 == 99) goto LAB_080c337a;
  }
  puVar2[1] = uVar1 + 1;
LAB_080c337a:
  if ((arg0_00 - 300 & 0xffff) < 0x2e) {
    sub_080C2764(arg0_00);
  }
  if ((arg0_00 - 0x120 & 0xffff) < 0xc) {
    sub_080BF938(0);
  }
                    /* WARNING: Could not recover jumptable at 0x080c33a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C33AC @ 0x080C33AC

void sub_080C33AC(uint arg0)

{
  short sVar1;
  undefined2 *puVar2;
  dword dVar3;
  uint uVar4;
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  if ((arg0 & 0x8000) != 0) {
    arg0_00 = arg0 & 0xff;
  }
  puVar2 = (undefined2 *)sub_080C320C(arg0_00);
  dVar3 = sub_080C3250(arg0_00);
  if (puVar2 != (undefined2 *)0x0) {
    sVar1 = puVar2[1];
    puVar2[1] = sVar1 + -1;
    if ((short)(sVar1 + -1) == 0) {
      uVar4 = 0;
      if (dVar3 != 0x159) {
        do {
          *puVar2 = puVar2[2];
          puVar2[1] = puVar2[3];
          puVar2 = puVar2 + 2;
          uVar4 = uVar4 + 1;
        } while (uVar4 < 0x159 - dVar3);
      }
      *puVar2 = 0;
      puVar2[1] = 0;
    }
    if (puVar2 != (undefined2 *)0x0) goto LAB_080c3416;
  }
  if ((arg0_00 - 300 & 0xffff) < 0x2e) {
    sub_080C2790(arg0_00);
  }
LAB_080c3416:
  if ((arg0_00 - 0x120 & 0xffff) < 0xc) {
    sub_080BF938(0);
  }
  return;
}


// sub_080C343C @ 0x080C343C

uint sub_080C343C(uint arg0,undefined4 arg1)

{
  switch((undefined2)arg1) {
  case 0:
    arg0 = (uint)*(byte *)(arg0 + 0x20);
    break;
  case 1:
    arg0 = (uint)*(byte *)(arg0 + 0x21);
    break;
  case 2:
    arg0 = (uint)*(byte *)(arg0 + 0x22);
    break;
  case 3:
    arg0 = (uint)*(byte *)(arg0 + 0x23);
    break;
  case 4:
    arg0 = (uint)*(byte *)(arg0 + 0x24);
    break;
  case 5:
    arg0 = (uint)*(byte *)(arg0 + 0x25);
    break;
  case 6:
    arg0 = (uint)*(byte *)(arg0 + 0x26);
  }
  return arg0;
}


// sub_080C34B0 @ 0x080C34B0

void sub_080C34B0(int arg0,undefined4 arg1,undefined4 arg2)

{
  undefined1 *puVar1;
  
  switch((undefined2)arg1) {
  case 0:
    puVar1 = (undefined1 *)(arg0 + 0x20);
    break;
  case 1:
    puVar1 = (undefined1 *)(arg0 + 0x21);
    break;
  case 2:
    puVar1 = (undefined1 *)(arg0 + 0x22);
    break;
  case 3:
    puVar1 = (undefined1 *)(arg0 + 0x23);
    break;
  case 4:
    puVar1 = (undefined1 *)(arg0 + 0x24);
    break;
  case 5:
    puVar1 = (undefined1 *)(arg0 + 0x25);
    break;
  case 6:
    puVar1 = (undefined1 *)(arg0 + 0x26);
    break;
  default:
    goto switchD_080c34c8_default;
  }
  *puVar1 = (undefined1)arg2;
switchD_080c34c8_default:
  return;
}


// sub_080C351C @ 0x080C351C

undefined4 sub_080C351C(uint arg0)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = sub_080C0148(0x8004);
  iVar4 = 0;
  iVar5 = 0;
  uVar3 = 0;
  do {
    if ((*(short *)(iVar1 + 0xe) != 0) &&
       (iVar4 = iVar4 + 1, (int)*(short *)(iVar1 + 0x12) == (arg0 & 0xffff))) {
      iVar5 = iVar5 + 1;
    }
    uVar3 = uVar3 + 1;
    iVar1 = iVar1 + 0x80;
  } while (uVar3 < 0xc);
  uVar2 = 0;
  if ((iVar4 != 0xc) && (iVar5 == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}


// sub_080C3560 @ 0x080C3560

undefined4 sub_080C3560(uint arg0)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_080C0148(0x8004);
  uVar2 = 0;
  while ((*(short *)(iVar1 + 0xe) == 0 || ((int)*(short *)(iVar1 + 0x12) != (arg0 & 0xffff)))) {
    uVar2 = uVar2 + 1;
    iVar1 = iVar1 + 0x80;
    if (0xb < uVar2) {
      return 0;
    }
  }
  return iVar1;
}


// sub_080C3598 @ 0x080C3598

void sub_080C3598(undefined4 arg0)

{
  DAT_03005183 = (char)arg0 + DAT_03005183;
  if (0xc < DAT_03005183) {
    DAT_03005183 = 0xc;
  }
  return;
}


// sub_080C35C4 @ 0x080C35C4

void sub_080C35C4(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  *(undefined1 *)(iVar1 + 0x17) = (undefined1)arg1;
  return;
}


// sub_080C35E4 @ 0x080C35E4

int sub_080C35E4(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(char *)(iVar1 + 0x17);
}


// sub_080C3600 @ 0x080C3600

void sub_080C3600(int arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  *(undefined1 *)(iVar1 + 0x16) = (undefined1)arg1;
  return;
}


// sub_080C3620 @ 0x080C3620

int sub_080C3620(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080F2F64(arg0 - 0x8000U & 0xffff);
  return (int)*(char *)(iVar1 + 0x16);
}


// sub_080C363C @ 0x080C363C

void sub_080C363C(uint arg0,uint arg1)

{
  undefined1 uVar1;
  
  uVar1 = (&DAT_030050e0)[arg1 & 0xffff];
  (&DAT_030050e0)[arg1 & 0xffff] = (&DAT_030050e0)[arg0 & 0xffff];
  (&DAT_030050e0)[arg0 & 0xffff] = uVar1;
  Party_BuildMemberNameTiles();
  sub_080C6FD8();
  return;
}


// sub_080C366C @ 0x080C366C

void sub_080C366C(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  char local_28 [8];
  
  pcVar4 = local_28;
  uVar5 = 0;
  do {
    local_28[uVar5] = -1;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 6);
  uVar5 = 0;
  do {
    local_28[uVar5] = *(char *)(uVar5 + 0x30050e0);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 6);
  uVar5 = 0;
  do {
    cVar1 = *pcVar4;
    cVar2 = pcVar4[3];
    if (cVar1 == -1) {
      if (cVar2 != -1) {
        *pcVar4 = cVar2;
        pcVar4[3] = -1;
      }
    }
    else if (((-1 < cVar2) && (uVar3 = sub_080C0818((int)cVar1), (uVar3 & 0xa000) != 0)) &&
            (uVar3 = sub_080C0818((int)cVar2), (uVar3 & 0xa000) == 0)) {
      *pcVar4 = cVar2;
      pcVar4[3] = cVar1;
    }
    pcVar4 = pcVar4 + 1;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 3);
  uVar5 = 0;
  do {
    *(char *)(uVar5 + 0x30050e0) = local_28[uVar5];
    uVar5 = uVar5 + 1;
  } while (uVar5 < 6);
  Party_BuildMemberNameTiles();
  sub_080C6FD8();
  return;
}


// sub_080C373C @ 0x080C373C

undefined4 sub_080C373C(undefined4 arg0,undefined4 arg1)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    psVar2 = (short *)(uVar3 * 4 + 0x2036074);
    sVar1 = *psVar2;
    if ((sVar1 != 0) && ((&DAT_02036076)[uVar3 * 2] == (short)arg1)) break;
    uVar3 = uVar3 + 1 & 0xffff;
    if (7 < uVar3) {
      uVar3 = -((int)(-DAT_020360ac | DAT_020360ac) >> 0x1f);
      if (DAT_020360b0 != 0) {
        uVar3 = uVar3 + 1;
      }
      while( true ) {
        if (5 < uVar3) {
          return 0;
        }
        psVar2 = (short *)(uVar3 * 4 + 0x2036074);
        if (*psVar2 == 0) break;
        uVar3 = uVar3 + 1 & 0xffff;
      }
      *psVar2 = 1;
      (&DAT_02036076)[uVar3 * 2] = (short)arg1;
      return uVar3;
    }
  }
  *psVar2 = sVar1 + 1;
  return uVar3;
}


// sub_080C37C0 @ 0x080C37C0

void sub_080C37C0(int arg0)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    piVar1 = (int *)(uVar2 * 4 + 0x2036094);
    if (*piVar1 == 0) {
      *piVar1 = arg0;
      return;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 8);
  return;
}


// sub_080C37EC @ 0x080C37EC

void sub_080C37EC(int arg0)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    piVar1 = (int *)(uVar2 * 4 + 0x2036094);
    if (*piVar1 == arg0) {
      *piVar1 = 0;
      return;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 8);
  return;
}


// sub_080C3818 @ 0x080C3818

void sub_080C3818(undefined4 arg0)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  if ((short)arg0 == 0) {
    uVar4 = 0;
    piVar5 = (int *)0x2036094;
    do {
      uVar3 = uVar4 - 6;
      if (uVar3 < 2) {
        if (*piVar5 != 0) {
          sub_080E9044(*piVar5,uVar3 & 0xffff);
          piVar1 = (int *)(uVar3 * 4 + 0x30069c0);
          if (*piVar1 != 0) {
            *piVar1 = 0;
          }
          *piVar5 = 0;
        }
      }
      else {
        iVar2 = *piVar5;
        if ((ushort)(*(short *)(iVar2 + 0x2a) - 0x1c2U) < 2) {
          sub_080AB158(0x1d0,0x10,1,1);
        }
        else if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 0xc) = 1;
        }
      }
      piVar5 = piVar5 + 1;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 8);
  }
  else {
    uVar4 = 0;
    piVar5 = (int *)0x2036094;
    uVar3 = 0xfffa0000;
    do {
      if (uVar4 - 6 < 2) {
        if (*piVar5 != 0) {
          sub_080E9044(*piVar5,uVar3 >> 0x10);
          *piVar5 = 0;
        }
      }
      else if (*piVar5 != 0) {
        sub_080C48F0(*piVar5);
      }
      piVar5 = piVar5 + 1;
      uVar3 = uVar3 + 0x10000;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 8);
  }
  return;
}


// sub_080C38D4 @ 0x080C38D4

dword sub_080C38D4(undefined4 arg0)

{
  uint uVar1;
  ushort *puVar2;
  short *psVar3;
  
  uVar1 = 0;
  psVar3 = &DAT_02036076;
  puVar2 = (ushort *)0x2036074;
  while ((*puVar2 < 2 || (*psVar3 != (short)arg0))) {
    psVar3 = psVar3 + 2;
    puVar2 = puVar2 + 2;
    uVar1 = uVar1 + 1;
    if (7 < uVar1) {
      return 0xffff;
    }
  }
  return uVar1 & 0xffff;
}


// sub_080C3910 @ 0x080C3910

void sub_080C3910(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C3934 @ 0x080C3934

void sub_080C3934(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2002000;
  REG_DMA3DAD = 0x6017000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C3958 @ 0x080C3958

void sub_080C3958(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2003000;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C397C @ 0x080C397C

void sub_080C397C(undefined4 arg0,int arg1,int arg2,int arg3)

{
  short sVar1;
  int iVar2;
  dword arg0_00;
  int iVar3;
  undefined4 arg2_00;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080AD364(arg0);
  iVar3 = (uint)*(ushort *)(iVar2 + 0x2a) * 0x1c;
  arg2_00 = *(undefined4 *)(&UNK_0872c780 + arg3 * 4 + arg2 * 8 + iVar3);
  sVar1 = *(short *)(iVar2 + 0x26);
  if (*(short *)(iVar2 + 0x28) == 0) goto LAB_080c3b6e;
  if ((sVar1 == 0) || (sVar1 == 3)) {
    if (arg3 == 0) {
      HuffUnComp(arg2_00,0x200afc8,arg2_00);
    }
    else {
      LZ77UnCompWram(0x200afc8,0x2001000,arg2_00);
    }
    if (arg3 != 1) goto LAB_080c3b6e;
    if (arg1 == 0) {
      iVar2 = sub_080B098C();
      if (iVar2 == 0) {
        sub_080ACFCC(3,*(undefined4 *)(&UNK_0872c778 + iVar3),0x3002d70,0x20);
        sub_080ACFCC(3,*(undefined4 *)(&UNK_0872c778 + iVar3),0x3003170,0x20);
        sub_080AABB0();
      }
      else {
        sub_080ACFCC(3,*(undefined4 *)(&UNK_0872c778 + iVar3),0x3002d70,0x20);
        sub_080AB090(0x1e0,0x10,1,1);
      }
    }
    arg0_00 = 0x80c3911;
  }
  else {
    if (sVar1 != 1) {
      if (sVar1 == 2) {
        if (arg3 == 0) {
          HuffUnComp(arg2_00,0x200cfc8,arg2_00);
        }
        else {
          LZ77UnCompWram(0x200cfc8,0x2003000,arg2_00);
        }
        if (arg3 == 1) {
          if (arg1 == 0) {
            iVar2 = sub_080B098C();
            if (iVar2 == 0) {
              sub_080ACFCC(3,*(undefined4 *)(&UNK_0872c778 + iVar3),0x3002d50,0x20);
              sub_080ACFCC(3,*(undefined4 *)(&UNK_0872c778 + iVar3),0x3003150,0x20);
              sub_080AABB0();
            }
            else {
              sub_080ACFCC(3,*(undefined4 *)(&UNK_0872c778 + iVar3),0x3002d50,0x20);
              sub_080AB090(0x1d0,0x10,1,1);
            }
          }
          DisplayList_Add(0x80c3959,1);
        }
      }
      goto LAB_080c3b6e;
    }
    if (arg3 == 0) {
      HuffUnComp(arg2_00,0x200bfc8,arg2_00);
    }
    else {
      LZ77UnCompWram(0x200bfc8,0x2002000,arg2_00);
    }
    if (arg3 != 1) goto LAB_080c3b6e;
    if (arg1 == 0) {
      iVar2 = sub_080B098C();
      if (iVar2 == 0) {
        sub_080ACFCC(3,*(undefined4 *)(&UNK_0872c778 + iVar3),0x3002d90,0x20);
        sub_080ACFCC(3,*(undefined4 *)(&UNK_0872c778 + iVar3),0x3003190,0x20);
        sub_080AABB0();
      }
      else {
        sub_080ACFCC(3,*(undefined4 *)(&UNK_0872c778 + iVar3),0x3002d90,0x20);
        sub_080AB090(0x1f0,0x10,1,1);
      }
    }
    arg0_00 = 0x80c3935;
  }
  DisplayList_Add(arg0_00,1);
LAB_080c3b6e:
                    /* WARNING: Could not recover jumptable at 0x080c3b74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C3B80 @ 0x080C3B80

void sub_080C3B80(int arg0)

{
  short sVar1;
  undefined4 arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = *(short *)(arg0 + 0x26);
  if (*(short *)(arg0 + 0x28) != 0) {
    if ((sVar1 == 0) || (sVar1 == 3)) {
      arg0_00 = 0x1e0;
    }
    else {
      if (sVar1 != 1) {
        if (sVar1 == 2) {
          sub_080AB158(0x1d0,0x10,1,1);
        }
        goto LAB_080c3bc0;
      }
      arg0_00 = 0x1f0;
    }
    sub_080AB158(arg0_00,0x10,1,1);
  }
LAB_080c3bc0:
                    /* WARNING: Could not recover jumptable at 0x080c3bc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C3BC4 @ 0x080C3BC4

void sub_080C3BC4(int arg0)

{
  short sVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = *(short *)(arg0 + 0x26);
  iVar2 = sub_080E8AA0((uint)*(byte *)(arg0 + 0x26));
  iVar2 = *(int *)(iVar2 + 0xc);
  if (iVar2 != 0) {
    if ((sVar1 == 0) || (sVar1 == 3)) {
      sub_080AA184(iVar2,1,0xe,(uint)*(ushort *)(arg0 + 0x34));
    }
    else if (sVar1 == 1) {
      sub_080AA184(iVar2,1,0xf,(uint)*(ushort *)(arg0 + 0x34));
    }
    else if (sVar1 == 2) {
      sub_080AA184(iVar2,1,0xd,(uint)*(ushort *)(arg0 + 0x34));
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080c3c66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C3C68 @ 0x080C3C68

void sub_080C3C68(int arg0)

{
  int iVar1;
  int iVar2;
  dword *pdVar3;
  dword dVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  dword local_1c;
  undefined4 local_18;
  
  uVar5 = (uint)*(ushort *)(arg0 + 0x26);
  iVar1 = sub_080E8AA0(uVar5 & 0xff);
  if (*(int *)(iVar1 + 0xc) != 0) {
    iVar2 = sub_080E444C((uint)*(ushort *)(iVar1 + 0x12));
    *(undefined1 *)(iVar1 + 1) = 1;
    *(undefined1 *)(iVar1 + 2) = 0;
    pdVar3 = (dword *)**(undefined4 **)(*(int *)(iVar2 + 8) + 4);
    *(dword **)(iVar1 + 0xc) = pdVar3;
    dVar4 = 0x8002c20;
    if (uVar5 == 2) {
      dVar4 = 0x8002c58;
    }
    local_1c = *pdVar3;
    local_18 = *(undefined4 *)(dVar4 + 4);
    sub_081583F4(&local_1c);
    dVar4 = 0x8002c20;
    if (uVar5 == 2) {
      dVar4 = 0x8002c58;
    }
    local_1c = 0x3003800;
    local_18 = *(undefined4 *)(dVar4 + 4);
    if (uVar5 == 0) {
      sub_080AA790(&local_1c,1,0xe,(uint)*(ushort *)(arg0 + 0x34));
    }
    else if (uVar5 == 1) {
      sub_080AA790(&local_1c,1,0xf,(uint)*(ushort *)(arg0 + 0x34));
    }
    else {
      sub_080AA790(&local_1c,1,0xd,(uint)*(ushort *)(arg0 + 0x34));
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080c3d5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C3D5C @ 0x080C3D5C

void sub_080C3D5C(int arg0)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = sub_080AD364(arg0);
  uVar1 = *(ushort *)(iVar2 + 0x26);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar3 = sub_080E88C0(uVar1 & 0xff);
  if ((uVar3 & 0xff) != 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080C3D84 @ 0x080C3D84

int sub_080C3D84(undefined4 arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int arg0_00;
  undefined4 uVar1;
  dword dVar2;
  uint arg1_00;
  undefined2 in_stack_00000000;
  undefined2 in_stack_00000004;
  
  arg1_00 = (uint)(ushort)arg1;
  arg0_00 = sub_080AD0FC(0x81a647c,0xffff);
  uVar1 = sub_080C373C(arg0_00,arg1_00);
  *(short *)(arg0_00 + 0x26) = (short)uVar1;
  sub_080C37C0(arg0_00);
  *(undefined2 *)(arg0_00 + 0x24) = (undefined2)arg0;
  *(ushort *)(arg0_00 + 0x2a) = (ushort)arg1;
  *(undefined2 *)(arg0_00 + 0x2c) = (undefined2)arg2;
  *(undefined2 *)(arg0_00 + 0x2e) = (undefined2)arg3;
  *(undefined2 *)(arg0_00 + 0x30) = in_stack_00000000;
  *(undefined2 *)(arg0_00 + 0x32) = in_stack_00000004;
  *(undefined2 *)(arg0_00 + 0x34) = 2;
  *(undefined2 *)(arg0_00 + 0x28) = 1;
  dVar2 = sub_080E8AC0(arg1_00);
  if (dVar2 == 0xffff) {
    dVar2 = 0x81a631c;
  }
  else {
    dVar2 = 0x81a6420;
  }
  uVar1 = sub_080AD0FC(dVar2,(uint)*(ushort *)(arg0_00 + 2));
  *(undefined4 *)(arg0_00 + 0x38) = uVar1;
  sub_080E8A28((uint)*(byte *)(arg0_00 + 0x26),arg1_00);
  return arg0_00;
}


// sub_080C3E40 @ 0x080C3E40

void sub_080C3E40(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x34) = (undefined2)arg1;
  return;
}


// sub_080C3E44 @ 0x080C3E44

void sub_080C3E44(int arg0,undefined4 arg1,undefined4 arg2)

{
  *(short *)(arg0 + 0x2c) = (short)arg1 + *(short *)(arg0 + 0x2c);
  *(short *)(arg0 + 0x2e) = (short)arg2 + *(short *)(arg0 + 0x2e);
  return;
}


// sub_080C3E5C @ 0x080C3E5C

void sub_080C3E5C(int arg0,undefined4 arg1,undefined4 arg2)

{
  *(undefined2 *)(arg0 + 0x2c) = (undefined2)arg1;
  *(undefined2 *)(arg0 + 0x2e) = (undefined2)arg2;
  return;
}


// sub_080C3E64 @ 0x080C3E64

void sub_080C3E64(int arg0)

{
  if (*(int *)(arg0 + 0x38) != 0) {
    sub_080AD1FC(*(int *)(arg0 + 0x38));
    *(undefined4 *)(arg0 + 0x38) = 0;
  }
  return;
}


// sub_080C3E80 @ 0x080C3E80

void sub_080C3E80(int arg0)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = (short *)((uint)*(ushort *)(arg0 + 0x26) * 4 + 0x2036074);
  sVar1 = *psVar2;
  if (sVar1 != 0) {
    *psVar2 = sVar1 + -1;
  }
  sub_080C37EC(arg0);
  if (*(int *)(arg0 + 0x38) != 0) {
    sub_080AD1FC(*(int *)(arg0 + 0x38));
  }
  sub_080AD1FC(arg0);
  return;
}


// sub_080C3EBC @ 0x080C3EBC

void sub_080C3EBC(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2001000;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C3EE0 @ 0x080C3EE0

void sub_080C3EE0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2002000;
  REG_DMA3DAD = 0x6017000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C3F04 @ 0x080C3F04

void sub_080C3F04(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2003000;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C3F28 @ 0x080C3F28

void sub_080C3F28(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2004000;
  REG_DMA3DAD = 0x6012000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080C3F4C @ 0x080C3F4C

void sub_080C3F4C(int arg0,undefined4 arg1,uint arg2,uint arg3)

{
  int iVar1;
  int iVar2;
  int in_stack_00000000;
  
  iVar2 = 0;
  iVar1 = sub_080B098C();
  if (iVar1 == 0) {
    if (*(short *)(arg0 + 0x1c) == 0) {
      if (*(short *)(arg0 + 0x1e) == 0) {
        sub_080ACFCC(3,arg1,arg2 * 2 + 0x3002db0,arg3);
        sub_080AABB0();
      }
      else {
        sub_080ACFCC(3,arg1,arg2 * 2 + 0x30029b0,arg3);
        if (in_stack_00000000 == 1) {
          iVar2 = sub_080AAFBC(arg2 & 0xffff,(arg3 & 0x1ffff) >> 1,3);
          sub_080ACFA4(3,0x7fff,arg2 * 2 + 0x3002db0,arg3);
          sub_080AABB0();
        }
      }
    }
    else {
      sub_080ACFCC(3,arg1,arg2 * 2 + 0x30029b0,arg3);
      if (in_stack_00000000 == 1) {
        iVar2 = sub_080AAFBC(arg2 & 0xffff,(arg3 & 0x1ffff) >> 1,3);
      }
    }
  }
  else {
    sub_080ACFCC(3,arg1,arg2 * 2 + 0x30029b0,arg3);
    if (in_stack_00000000 == 1) {
      iVar2 = sub_080AB090(arg2 & 0xffff,(arg3 & 0x1ffff) >> 1,1,1);
    }
  }
  if ((iVar2 != 0) && (iVar1 = sub_080C2340(0x10e), iVar1 != 0)) {
    *(undefined2 *)(iVar2 + 2) = 8;
    sub_080C23BC(0x10e);
  }
  iVar1 = sub_080C2340(0xfd);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar2 + 4) = 10;
    *(undefined2 *)(iVar2 + 6) = 10;
  }
  return;
}


// sub_080C4080 @ 0x080C4080

void sub_080C4080(int arg0,undefined4 arg1,int arg2,int arg3)

{
  int iVar1;
  dword arg0_00;
  uint arg2_00;
  
  iVar1 = sub_080D95F4((uint)*(ushort *)(arg0 + 6));
  arg2_00 = (uint)*(ushort *)(arg0 + 2);
  if (*(short *)(arg0 + 4) == 0) {
    return;
  }
  if (arg2_00 == 0) {
    LZ77UnCompWram(arg1,arg3 * 0x800 + 0x2001000,0);
    if (arg3 != 1) {
      return;
    }
    if (arg2 == 0) {
      sub_080C3F4C(arg0,*(undefined4 *)(iVar1 + 0x24),0x1e0,0x20);
    }
    arg0_00 = 0x80c3ebd;
  }
  else if (arg2_00 == 1) {
    LZ77UnCompWram(arg1,arg3 * 0x800 + 0x2002000,1);
    if (arg3 != 1) {
      return;
    }
    if (arg2 == 0) {
      sub_080C3F4C(arg0,*(undefined4 *)(iVar1 + 0x24),0x1f0,0x20);
    }
    arg0_00 = 0x80c3ee1;
  }
  else {
    if (arg2_00 != 2) {
      LZ77UnCompWram(arg1,arg3 * 0x800 + 0x2004000,arg2_00);
      if (arg3 != 1) {
        return;
      }
      if (arg2 == 0) {
        sub_080C3F4C(arg0,*(undefined4 *)(iVar1 + 0x24),0x1c0,0x20);
      }
      if ((DAT_030020e4 == 0x80d977d) && (*(short *)(arg0 + 6) == 0x2a)) {
        return;
      }
      DisplayList_Add(0x80c3f29,1);
      return;
    }
    LZ77UnCompWram(arg1,arg3 * 0x800 + 0x2003000,2);
    if (arg3 != 1) {
      return;
    }
    if (arg2 == 0) {
      sub_080C3F4C(arg0,*(undefined4 *)(iVar1 + 0x24),0x1d0,0x20);
    }
    arg0_00 = 0x80c3f05;
  }
  DisplayList_Add(arg0_00,1);
  return;
}


// sub_080C41B0 @ 0x080C41B0

void sub_080C41B0(undefined4 arg0,undefined4 arg1,int arg2,int arg3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = sub_080AD364(arg0);
  iVar2 = sub_080D95F4((uint)*(ushort *)(iVar1 + 0x2a));
  sub_080C4080(iVar1 + 0x24,*(undefined4 *)(iVar2 + 4 + arg3 * 4 + arg2 * 8),arg1,arg3);
  return;
}


// sub_080C41F4 @ 0x080C41F4

void sub_080C41F4(int arg0)

{
  short sVar1;
  undefined4 arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = *(short *)(arg0 + 0x26);
  if (*(short *)(arg0 + 0x28) != 0) {
    if (sVar1 == 0) {
      arg0_00 = 0x1e0;
    }
    else if (sVar1 == 1) {
      arg0_00 = 0x1f0;
    }
    else {
      if (sVar1 != 2) {
        sub_080AB158(0x1c0,0x10,1,1);
        goto LAB_080c4238;
      }
      arg0_00 = 0x1d0;
    }
    sub_080AB158(arg0_00,0x10,1,1);
  }
LAB_080c4238:
                    /* WARNING: Could not recover jumptable at 0x080c423a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C423C @ 0x080C423C

undefined4 sub_080C423C(void)

{
  return 0;
}


// sub_080C4240 @ 0x080C4240

uint sub_080C4240(uint arg0,uint arg1,undefined4 arg2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = arg0 & 0xffff;
  uVar2 = arg1 & 0xffff;
  if ((short)arg2 == 0) {
    if (uVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = uVar1 - 1 & 0xffff;
    }
  }
  else if (uVar1 < uVar2) {
    uVar2 = uVar1 + 1 & 0xffff;
  }
  return uVar2;
}


// sub_080C4274 @ 0x080C4274

void sub_080C4274(int arg0,uint arg1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  ushort *arg2;
  uint uVar7;
  
  if (((*(short *)(arg0 + 0x12) == 1) && ((DAT_030031bc & 7) == 0)) &&
     (uVar2 = sub_080AB184(), (uVar2 & 0xffff) == 1)) {
    iVar3 = sub_080D95F4((uint)*(ushort *)(arg0 + 6));
    arg2 = (ushort *)((arg1 & 0xffff) * 0x20 + 0x3002fb2);
    puVar4 = *(ushort **)(iVar3 + 0x24);
    uVar1 = 0;
    do {
      puVar4 = puVar4 + 1;
      uVar6 = (uint)*arg2;
      uVar7 = (uint)*puVar4;
      uVar2 = sub_080C4240(uVar6 & 0x1f,uVar7 & 0x1f,(uint)*(ushort *)(arg0 + 0x14));
      uVar5 = sub_080C4240((uVar6 & 0x3e0) >> 5,(uVar7 & 0x3e0) >> 5,(uint)*(ushort *)(arg0 + 0x14))
      ;
      uVar6 = sub_080C4240((uVar6 & 0x7c00) >> 10,(uVar7 & 0x7c00) >> 10,
                           (uint)*(ushort *)(arg0 + 0x14));
      sub_080ACFA4(3,(uVar2 & 0xffff | (uVar5 & 0xffff) << 5 | (uVar6 & 0xffff) << 10) & 0xffff,arg2
                   ,2);
      uVar1 = uVar1 + 1;
      arg2 = arg2 + 1;
    } while (uVar1 < 0xf);
    sub_080AABB0();
    uVar1 = *(short *)(arg0 + 0x16) + 1;
    *(ushort *)(arg0 + 0x16) = uVar1;
    if (6 < uVar1) {
      *(undefined2 *)(arg0 + 0x16) = 0;
      *(ushort *)(arg0 + 0x14) = *(short *)(arg0 + 0x14) + 1U & 1;
    }
  }
  return;
}


// sub_080C4388 @ 0x080C4388

undefined4 sub_080C4388(ushort *arg0)

{
  short sVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ushort)(arg0[3] - 0xaa) < 2) || (arg0[3] == 0xf5)) {
    sVar1 = 0;
  }
  else {
    sVar1 = 8 - (*arg0 & 7);
  }
                    /* WARNING: Could not recover jumptable at 0x080c43b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(sVar1);
  return uVar2;
}


// sub_080C43B4 @ 0x080C43B4

dword sub_080C43B4(ushort *arg0)

{
  int iVar1;
  dword dVar2;
  
  iVar1 = sub_080D95F4((uint)arg0[3]);
  if ((((*arg0 & 0x10) == 0) && (*(short *)(iVar1 + 2) != 0)) && ((DAT_030031bc >> 4 & 1) != 0)) {
    dVar2 = 0x8005028;
  }
  else {
    dVar2 = 0x8004ff8;
  }
  return dVar2;
}


// sub_080C43F8 @ 0x080C43F8

void sub_080C43F8(int arg0,undefined4 arg1,int arg2,uint arg3)

{
  short sVar1;
  uint uVar2;
  uint arg3_00;
  
  sVar1 = *(short *)(arg0 + 0x26);
  uVar2 = sub_080C4388(arg0 + 0x24);
  if (arg3 == 0) {
    arg3_00 = 0xe;
    if (((sVar1 != 0) && (arg3_00 = 0xf, sVar1 != 1)) && (arg3_00 = 0xc, sVar1 == 2)) {
      arg3_00 = 0xd;
    }
  }
  else {
    arg3_00 = arg3 & 0xffff;
  }
  sub_080C44CC(arg0 + 0x24,arg1,uVar2 & 0xffff,arg3_00);
  return;
}


// sub_080C44B0 @ 0x080C44B0

void sub_080C44B0(int arg0)

{
  undefined4 arg1;
  
  arg1 = sub_080C43B4(arg0 + 0x24);
  sub_080C43F8(arg0,arg1,0,0);
  return;
}


// sub_080C44CC @ 0x080C44CC

void sub_080C44CC(ushort *arg0,undefined4 arg1,uint arg2,uint arg3)

{
  int iVar1;
  uint arg1_00;
  code *UNRECOVERED_JUMPTABLE;
  uint in_stack_00000000;
  
  arg1_00 = arg3 & 0xffff;
  iVar1 = sub_080C423C();
  if (iVar1 != 1) {
    sub_080C4274(arg0,arg1_00);
    sub_080C2340(0x106);
    if ((*arg0 & 0x20) == 0) {
      sub_080AA184(arg1,arg2 & 0xffff,arg1_00,in_stack_00000000 & 0xffff);
    }
    else {
      sub_080AA1BC(arg1,arg2 & 0xffff,arg1_00,in_stack_00000000 & 0xffff);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080c4578. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080C457C @ 0x080C457C

void sub_080C457C(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x36) = (undefined2)arg1;
  return;
}


// sub_080C4580 @ 0x080C4580

void sub_080C4580(void)

{
  undefined4 in_r0;
  
  sub_080C457C(in_r0,1);
  return;
}


// sub_080C458C @ 0x080C458C

void sub_080C458C(void)

{
  undefined4 in_r0;
  
  sub_080C457C(in_r0,0);
  return;
}


// sub_080C4598 @ 0x080C4598

void sub_080C4598(int arg0)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  piVar1 = (int *)0x30068f0;
  do {
    if (*piVar1 == arg0) {
      *piVar1 = 0;
      return;
    }
    piVar1 = piVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  return;
}


// sub_080C45C0 @ 0x080C45C0

undefined4 sub_080C45C0(undefined4 arg0,undefined4 arg1)

{
  int arg0_00;
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  piVar1 = (int *)0x2036094;
  while ((arg0_00 = *piVar1, arg0_00 == 0 ||
         ((*(ushort *)(arg0_00 + 0x24) & 7) != ((ushort)arg0 & 7)))) {
    piVar1 = piVar1 + 1;
    uVar2 = uVar2 + 1;
    if (5 < uVar2) {
      return 0;
    }
  }
  if (*(short *)(arg0_00 + 0x2a) != (short)arg1) {
    sub_080C48F0(arg0_00);
    return 0;
  }
  return arg0_00;
}


// sub_080C4614 @ 0x080C4614

void sub_080C4614(void)

{
  return;
}


// sub_080C4618 @ 0x080C4618

int sub_080C4618(undefined4 arg0,undefined4 arg1,uint arg2,undefined4 arg3)

{
  ushort uVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  dword dVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  ushort *unaff_r9;
  uint in_stack_00000000;
  ushort in_stack_00000004;
  undefined1 auStack_2c [4];
  uint local_28;
  uint local_24;
  
  uVar8 = (uint)(ushort)arg1;
  local_28 = arg2 & 0xffff;
  local_24 = in_stack_00000000 & 0xffff;
  psVar3 = (short *)sub_080D95F4(uVar8);
  iVar4 = sub_080C45C0((uint)(ushort)arg0,uVar8);
  if (iVar4 != 0) {
    if (((ushort)arg0 & 0x40) == 0) {
      iVar7 = sub_080D95F4(uVar8);
      uVar6 = *(undefined4 *)(iVar7 + 0x24);
      uVar1 = DAT_0203db28;
      if ((uVar8 == 0x1c1) || (uVar1 = DAT_0203db2a, uVar8 == 0x1c0)) {
        iVar7 = sub_080D8248((uint)uVar1);
        uVar6 = *(undefined4 *)(iVar7 + 4);
      }
      sVar2 = *(short *)(iVar4 + 0x26);
      if (sVar2 == 0) {
        sub_080ACFCC(3,uVar6,0x3003170,0x20);
        dVar5 = 0x3002d70;
      }
      else if (sVar2 == 1) {
        sub_080ACFCC(3,uVar6,0x3003190,0x20);
        dVar5 = 0x3002d90;
      }
      else if (sVar2 == 2) {
        sub_080ACFCC(3,uVar6,0x3003150,0x20);
        dVar5 = 0x3002d50;
      }
      else {
        sub_080ACFCC(3,uVar6,0x3003130,0x20);
        dVar5 = 0x3002d30;
      }
      sub_080ACFCC(3,uVar6,dVar5,0x20);
      sub_080AABB0();
      return iVar4;
    }
    sVar2 = *(short *)(iVar4 + 0x26);
    if (sVar2 == 0) {
      uVar6 = 0x1e0;
    }
    else if (sVar2 == 1) {
      uVar6 = 0x1f0;
    }
    else {
      if (sVar2 != 2) {
        sub_080AB138(0x1c0,0x10,1,3);
        return iVar4;
      }
      uVar6 = 0x1d0;
    }
    sub_080AB138(uVar6,0x10,1,3);
    return iVar4;
  }
  sub_080C4614();
  sVar2 = *psVar3;
  if (sVar2 == 0) {
    iVar4 = sub_080AD0FC(0x81a65b8,0xffff);
    dVar5 = 0x81a64a8;
  }
  else {
    if (sVar2 != 1) {
      if (sVar2 == 2) {
        dVar5 = *(dword *)(psVar3 + 0x14);
      }
      else {
        iVar4 = 0;
        if (sVar2 != 3) goto LAB_080c47da;
        dVar5 = 0x855fb78;
      }
      iVar4 = sub_080AD0FC(dVar5,0xffff);
      unaff_r9 = (ushort *)(iVar4 + 0x24);
      goto LAB_080c47da;
    }
    iVar4 = sub_080AD0FC(0x81a65b8,0xffff);
    dVar5 = 0x81a64f8;
  }
  unaff_r9 = (ushort *)(iVar4 + 0x24);
  uVar6 = sub_080AD0FC(dVar5,(uint)*(ushort *)(iVar4 + 2));
  *(undefined4 *)(iVar4 + 0x44) = uVar6;
LAB_080c47da:
  *unaff_r9 = (ushort)arg0;
  uVar6 = sub_080C373C(iVar4,uVar8);
  unaff_r9[1] = (ushort)uVar6;
  iVar7 = sub_080C2340(0x10b);
  if (iVar7 == 0) {
    iVar7 = sub_080C2340(0x10c);
    if (iVar7 != 0) {
      unaff_r9[0xf] = 1;
      sub_080C23BC(0x10c);
    }
  }
  else {
    unaff_r9[0xe] = 1;
    sub_080C23BC(0x10b);
  }
  if ((((*(int *)(unaff_r9 + 0xe) == 0) && (iVar7 = sub_080C2340(0xc6), iVar7 == 0)) &&
      (iVar7 = sub_080C9084((uint)DAT_03004562,(uint)DAT_03004564,(uint)DAT_03004552,auStack_2c),
      iVar7 != 0)) && (uVar6 = ScriptVM_RunAlt(*(undefined4 *)(iVar7 + 4)), (short)uVar6 == 2)) {
    unaff_r9[0xe] = 1;
  }
  sub_080C37C0(iVar4);
  unaff_r9[3] = (ushort)arg1;
  unaff_r9[4] = (ushort)local_28;
  unaff_r9[5] = (ushort)arg3;
  unaff_r9[6] = (ushort)local_24;
  unaff_r9[7] = in_stack_00000004;
  unaff_r9[8] = 2;
  if (0x3f < (ushort)arg3) {
    unaff_r9[8] = 3;
  }
  uVar8 = sub_080C38D4(uVar8);
  if ((uVar8 & 0xffff) == 0xffff) {
    unaff_r9[2] = 1;
  }
  return iVar4;
}


// sub_080C48B0 @ 0x080C48B0

void sub_080C48B0(int arg0,undefined4 arg1)

{
  *(undefined2 *)(arg0 + 0x34) = (undefined2)arg1;
  return;
}


// sub_080C48B4 @ 0x080C48B4

void sub_080C48B4(int arg0,undefined4 arg1,undefined4 arg2)

{
  *(short *)(arg0 + 0x2c) = (short)arg1 + *(short *)(arg0 + 0x2c);
  *(short *)(arg0 + 0x2e) = (short)arg2 + *(short *)(arg0 + 0x2e);
  return;
}


// sub_080C48CC @ 0x080C48CC

void sub_080C48CC(int arg0,undefined4 arg1,undefined4 arg2)

{
  *(undefined2 *)(arg0 + 0x2c) = (undefined2)arg1;
  *(undefined2 *)(arg0 + 0x2e) = (undefined2)arg2;
  return;
}


// sub_080C48D4 @ 0x080C48D4

void sub_080C48D4(int arg0)

{
  if (*(int *)(arg0 + 0x44) != 0) {
    sub_080AD1FC(*(int *)(arg0 + 0x44));
    *(undefined4 *)(arg0 + 0x44) = 0;
  }
  return;
}


// sub_080C48F0 @ 0x080C48F0

void sub_080C48F0(short *arg0)

{
  short *psVar1;
  
  if ((arg0 != (short *)0x0) && (*arg0 != 0)) {
    psVar1 = (short *)((uint)(ushort)arg0[0x13] * 4 + 0x2036074);
    *psVar1 = *psVar1 + -1;
    sub_080C37EC(arg0);
    sub_080C4598(arg0);
    if (*(int *)(arg0 + 0x22) != 0) {
      sub_080AD1FC(*(int *)(arg0 + 0x22));
    }
    sub_080AD1FC(arg0);
  }
  return;
}


// sub_080C4938 @ 0x080C4938

void sub_080C4938(uint arg0,uint arg1,uint arg2,uint arg3)

{
  uint uVar1;
  uint arg1_00;
  uint arg2_00;
  uint uVar2;
  uint arg3_00;
  
  uVar1 = arg0 & 0xffff;
  arg1_00 = arg1 & 0xffff;
  arg2_00 = arg2 & 0xffff;
  arg3_00 = arg3 & 0xffff;
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      if (uVar2 == 0) {
        sub_080AA1F4(0x81a65dc,arg1_00,arg2_00,arg3_00);
      }
      else if (uVar2 == uVar1 - 1) {
        sub_080AA1F4(0x81a65ec,arg1_00,arg2_00,arg3_00);
      }
      else {
        sub_080AA1F4(0x81a65e4,arg1_00,arg2_00,arg3_00);
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < uVar1);
  }
  return;
}


// sub_080C49EC @ 0x080C49EC

void sub_080C49EC(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  sub_080C4938(arg0 & 0xffff,arg1 & 0xffff,3,arg2 & 0xffff);
  return;
}


// sub_080C4A1C @ 0x080C4A1C

void sub_080C4A1C(uint arg0,uint arg1,uint arg2,undefined4 arg3)

{
  sub_080C4938(arg0 & 0xffff,arg1 & 0xffff,6,arg2 & 0xffff);
  return;
}


// sub_080C4A4C @ 0x080C4A4C

void sub_080C4A4C(uint arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  if (DAT_030020e4 == 0x80d977d) {
    sub_080AA184(0x8008660,arg0 & 0xffff,0,arg1 & 0xffff);
  }
  else {
    sub_080AA184(0x8000ff0,arg0 & 0xffff,0,arg1 & 0xffff);
  }
  return;
}


// sub_080C4AB0 @ 0x080C4AB0

void sub_080C4AB0(uint arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  if (DAT_030020e4 == 0x80d977d) {
    sub_080AA184(0x8008670,arg0 & 0xffff,0,arg1 & 0xffff);
  }
  else {
    sub_080AA184(0x8001000,arg0 & 0xffff,0,arg1 & 0xffff);
  }
  return;
}


// sub_080C4B14 @ 0x080C4B14

void sub_080C4B14(uint arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  if (DAT_030020e4 == 0x80d977d) {
    sub_080AA184(0x800876c,arg0 & 0xffff,0,arg1 & 0xffff);
  }
  else {
    sub_080AA184(0x800108c,arg0 & 0xffff,0,arg1 & 0xffff);
  }
  return;
}


// sub_080C4B78 @ 0x080C4B78

void sub_080C4B78(uint arg0,uint arg1,undefined4 arg2,undefined4 arg3)

{
  if (DAT_030020e4 == 0x80d977d) {
    sub_080AA184(0x8008750,arg0 & 0xffff,0,arg1 & 0xffff);
  }
  else {
    sub_080AA184(0x800109c,arg0 & 0xffff,0,arg1 & 0xffff);
  }
  return;
}


// sub_080C4BDC @ 0x080C4BDC

void sub_080C4BDC(void)

{
  return;
}


// sub_080C4BE0 @ 0x080C4BE0

void sub_080C4BE0(void)

{
  return;
}


// sub_080C4BE4 @ 0x080C4BE4

void sub_080C4BE4(uint arg0)

{
  DAT_03005188 = (ushort)(1 << (arg0 & 0xff)) | DAT_03005188;
  return;
}


// sub_080C4C00 @ 0x080C4C00

void sub_080C4C00(undefined4 arg0)

{
  return;
}


