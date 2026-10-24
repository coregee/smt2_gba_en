/* Ghidra decompilation of asm/code_080E2740.s (reference only; not compiled). */

// RealClearChain @ 0x080E2740

void RealClearChain(int arg0)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(arg0 + 0x2c) != 0) {
    iVar1 = *(int *)(arg0 + 0x34);
    iVar2 = *(int *)(arg0 + 0x30);
    if (iVar2 == 0) {
      *(int *)(*(int *)(arg0 + 0x2c) + 0x20) = iVar1;
    }
    else {
      *(int *)(iVar2 + 0x34) = iVar1;
    }
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x30) = iVar2;
    }
    *(undefined4 *)(arg0 + 0x2c) = 0;
  }
  return;
}


// FUN_080e2760 @ 0x080E2760

undefined4 FUN_080e2760(undefined4 param_1,undefined1 *param_2)

{
  byte *arg0;
  undefined4 in_lr;
  
  for (arg0 = *(byte **)(param_2 + 0x20); arg0 != (byte *)0x0; arg0 = *(byte **)(arg0 + 0x34)) {
    if ((*arg0 & 199) != 0) {
      *arg0 = *arg0 | 0x40;
    }
    RealClearChain(arg0);
  }
  *param_2 = 0;
  return in_lr;
}


// MPlayJumpTableCopy @ 0x080E2790

void MPlayJumpTableCopy(void)

{
  undefined4 *in_r0;
  undefined4 *puVar1;
  int arg1;
  int extraout_r1;
  undefined4 *arg2;
  undefined4 uVar2;
  
  arg1 = 0x24;
  arg2 = (undefined4 *)0x858bbbc;
  do {
    uVar2 = *arg2;
    puVar1 = (undefined4 *)chk_adr_r2(in_r0,arg1,arg2);
    *puVar1 = uVar2;
    in_r0 = puVar1 + 1;
    arg2 = arg2 + 1;
    arg1 = extraout_r1 + -1;
  } while (arg1 != 0 && 0 < extraout_r1);
  return;
}


// ldrb_r3_r2 @ 0x080E27A8

undefined4 ldrb_r3_r2(undefined4 arg0,undefined4 arg1,uint arg2)

{
  return arg0;
}


// chk_adr_r2 @ 0x080E27AA

undefined4 chk_adr_r2(undefined4 arg0,undefined4 arg1,uint arg2)

{
  return arg0;
}


// ld_r3_tp_adr_i @ 0x080E27C4

undefined4 ld_r3_tp_adr_i(undefined4 arg0,int arg1)

{
  *(int *)(arg1 + 0x40) = *(int *)(arg1 + 0x40) + 1;
  return arg0;
}


// sub_080E27C6 @ 0x080E27C6

undefined4 sub_080E27C6(undefined4 arg0,int arg1,int arg2)

{
  *(int *)(arg1 + 0x40) = arg2 + 1;
  return arg0;
}


// ply_patt @ 0x080E27F0

void ply_patt(undefined4 arg0,undefined1 *arg1)

{
  uint3 *puVar1;
  uint uVar2;
  int extraout_r1;
  uint uVar3;
  byte *arg0_00;
  
  if (2 < (byte)arg1[2]) {
    for (arg0_00 = *(byte **)(arg1 + 0x20); arg0_00 != (byte *)0x0;
        arg0_00 = *(byte **)(arg0_00 + 0x34)) {
      if ((*arg0_00 & 199) != 0) {
        *arg0_00 = *arg0_00 | 0x40;
      }
      RealClearChain(arg0_00);
    }
    *arg1 = 0;
    return;
  }
  *(int *)(arg1 + (uint)(byte)arg1[2] * 4 + 0x44) = *(int *)(arg1 + 0x40) + 4;
  arg1[2] = arg1[2] + '\x01';
  puVar1 = (uint3 *)(*(int *)(arg1 + 0x40) + 1);
  uVar3 = (uint)*(byte *)puVar1;
  uVar2 = ldrb_r3_r2((uint)*puVar1 << 8,arg1,*(int *)(arg1 + 0x40));
  *(uint *)(extraout_r1 + 0x40) = uVar2 | uVar3;
  return;
}


// ply_pend @ 0x080E280C

void ply_pend(undefined4 arg0,int arg1)

{
  int iVar1;
  
  if (*(byte *)(arg1 + 2) != 0) {
    iVar1 = *(byte *)(arg1 + 2) - 1;
    *(char *)(arg1 + 2) = (char)iVar1;
    *(undefined4 *)(arg1 + 0x40) = *(undefined4 *)(arg1 + iVar1 * 4 + 0x44);
  }
  return;
}


// ply_rept @ 0x080E2820

void ply_rept(undefined4 arg0,int arg1)

{
  uint3 *puVar1;
  uint uVar2;
  int extraout_r1;
  int extraout_r1_00;
  char *pcVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar3 = *(char **)(arg1 + 0x40);
  if (*pcVar3 == '\0') {
    *(char **)(arg1 + 0x40) = pcVar3 + 1;
  }
  else {
    uVar4 = *(byte *)(arg1 + 3) + 1;
    *(char *)(arg1 + 3) = (char)uVar4;
    uVar2 = uVar4;
    ld_r3_tp_adr_i(arg0,arg1);
    arg1 = extraout_r1_00;
    if (uVar4 <= uVar2) {
      *(undefined1 *)(extraout_r1_00 + 3) = 0;
      *(char **)(extraout_r1_00 + 0x40) = pcVar3 + 5;
                    /* WARNING: Could not recover jumptable at 0x080e284c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  }
  puVar1 = (uint3 *)(*(int *)(arg1 + 0x40) + 1);
  uVar4 = (uint)*(byte *)puVar1;
  uVar2 = ldrb_r3_r2((uint)*puVar1 << 8,arg1,*(int *)(arg1 + 0x40));
  *(uint *)(extraout_r1 + 0x40) = uVar2 | uVar4;
  return;
}


// ply_prio @ 0x080E2850

void ply_prio(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  int extraout_r1;
  undefined1 in_r3;
  
  ld_r3_tp_adr_i(in_r0,in_r1);
  *(undefined1 *)(extraout_r1 + 0x1d) = in_r3;
  return;
}


// ply_tempo @ 0x080E285C

void ply_tempo(void)

{
  undefined4 in_r0;
  int iVar1;
  undefined4 in_r1;
  int in_r3;
  
  iVar1 = ld_r3_tp_adr_i(in_r0,in_r1);
  *(short *)(iVar1 + 0x1c) = (short)(in_r3 * 2);
  *(short *)(iVar1 + 0x20) = (short)((uint)*(ushort *)(iVar1 + 0x1e) * in_r3 * 2 >> 8);
  return;
}


// ply_keysh @ 0x080E2870

void ply_keysh(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  byte *extraout_r1;
  byte in_r3;
  
  ld_r3_tp_adr_i(in_r0,in_r1);
  extraout_r1[10] = in_r3;
  *extraout_r1 = *extraout_r1 | 0xc;
  return;
}


// ply_voice @ 0x080E2884

void ply_voice(int arg0,int arg1)

{
  byte bVar1;
  undefined4 uVar2;
  int arg1_00;
  int arg1_01;
  int extraout_r1;
  undefined4 *arg2;
  undefined4 uVar3;
  
  bVar1 = **(byte **)(arg1 + 0x40);
  *(byte **)(arg1 + 0x40) = *(byte **)(arg1 + 0x40) + 1;
  arg2 = (undefined4 *)((uint)bVar1 * 0xc + *(int *)(arg0 + 0x30));
  uVar3 = *arg2;
  uVar2 = chk_adr_r2(arg0,arg1,arg2);
  *(undefined4 *)(arg1_00 + 0x24) = uVar3;
  uVar3 = arg2[1];
  uVar2 = chk_adr_r2(uVar2,arg1_00,arg2);
  *(undefined4 *)(arg1_01 + 0x28) = uVar3;
  uVar3 = arg2[2];
  chk_adr_r2(uVar2,arg1_01,arg2);
  *(undefined4 *)(extraout_r1 + 0x2c) = uVar3;
  return;
}


// ply_vol @ 0x080E28B4

void ply_vol(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  byte *extraout_r1;
  byte in_r3;
  
  ld_r3_tp_adr_i(in_r0,in_r1);
  extraout_r1[0x12] = in_r3;
  *extraout_r1 = *extraout_r1 | 3;
  return;
}


// ply_pan @ 0x080E28C8

void ply_pan(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  byte *extraout_r1;
  char in_r3;
  
  ld_r3_tp_adr_i(in_r0,in_r1);
  extraout_r1[0x14] = in_r3 - 0x40;
  *extraout_r1 = *extraout_r1 | 3;
  return;
}


// ply_bend @ 0x080E28DC

void ply_bend(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  byte *extraout_r1;
  char in_r3;
  
  ld_r3_tp_adr_i(in_r0,in_r1);
  extraout_r1[0xe] = in_r3 - 0x40;
  *extraout_r1 = *extraout_r1 | 0xc;
  return;
}


// ply_bendr @ 0x080E28F0

void ply_bendr(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  byte *extraout_r1;
  byte in_r3;
  
  ld_r3_tp_adr_i(in_r0,in_r1);
  extraout_r1[0xf] = in_r3;
  *extraout_r1 = *extraout_r1 | 0xc;
  return;
}


// ply_lfodl @ 0x080E2904

void ply_lfodl(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  int extraout_r1;
  undefined1 in_r3;
  
  ld_r3_tp_adr_i(in_r0,in_r1);
  *(undefined1 *)(extraout_r1 + 0x1b) = in_r3;
  return;
}


// ply_modt @ 0x080E2910

void ply_modt(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  byte *extraout_r1;
  uint in_r3;
  
  ld_r3_tp_adr_i(in_r0,in_r1);
  if (extraout_r1[0x18] != in_r3) {
    extraout_r1[0x18] = (byte)in_r3;
    *extraout_r1 = *extraout_r1 | 0xf;
  }
  return;
}


// ply_tune @ 0x080E2928

void ply_tune(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  byte *extraout_r1;
  char in_r3;
  
  ld_r3_tp_adr_i(in_r0,in_r1);
  extraout_r1[0xc] = in_r3 - 0x40;
  *extraout_r1 = *extraout_r1 | 0xc;
  return;
}


// ply_port @ 0x080E293C

void ply_port(undefined4 arg0,int arg1)

{
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = (uint)**(byte **)(arg1 + 0x40);
  puVar1 = (undefined1 *)sub_080E27C6(uVar2 + 0x4000060,arg1,*(byte **)(arg1 + 0x40) + 1);
  *puVar1 = (char)uVar2;
  return;
}


// m4aSoundVSync @ 0x080E2954

void m4aSoundVSync(void)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = DAT_03007ff0;
  if ((*DAT_03007ff0 + 0x978c92adU < 2) &&
     (bVar1 = *(byte *)(DAT_03007ff0 + 1), iVar4 = bVar1 - 1,
     *(char *)(DAT_03007ff0 + 1) = (char)iVar4, iVar4 == 0 || bVar1 == 0)) {
    *(undefined1 *)(piVar3 + 1) = *(undefined1 *)((int)piVar3 + 0xb);
    uVar2 = REG_DMA1CNT;
    if ((uVar2 & 0x2000000) != 0) {
      REG_DMA1CNT = 0x84400004;
    }
    REG_DMA1CNT._2_2_ = 0x400;
    REG_DMA1CNT._2_2_ = 0xb600;
  }
  return;
}


// MPlayMain @ 0x080E2990

void MPlayMain(int arg0)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  byte bVar6;
  undefined4 in_r1;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  code *UNRECOVERED_JUMPTABLE;
  
  if (*(dword *)(arg0 + 0x34) != 0x68736d53) {
    return;
  }
  *(undefined4 *)(arg0 + 0x34) = 0x68736d54;
  if (*(int *)(arg0 + 0x38) != 0) {
    sub_080E2BE8(*(undefined4 *)(arg0 + 0x3c),in_r1,0x68736d53,*(int *)(arg0 + 0x38));
  }
  iVar2 = DAT_03007ff0;
  if ((*(int *)(arg0 + 4) < 0) || (FadeOutBody(arg0), *(int *)(arg0 + 4) < 0)) {
LAB_080e2bd8:
    *(dword *)(arg0 + 0x34) = 0x68736d53;
                    /* WARNING: Could not recover jumptable at 0x080e2be8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(unaff_r8,unaff_r9,unaff_r10);
    return;
  }
  uVar3 = (uint)*(ushort *)(arg0 + 0x22) + (uint)*(ushort *)(arg0 + 0x20);
LAB_080e2b28:
  *(short *)(arg0 + 0x22) = (short)uVar3;
  if (0x95 < uVar3) {
    pbVar11 = *(byte **)(arg0 + 0x2c);
    uVar8 = 1;
    uVar9 = 0;
    uVar3 = (uint)*(byte *)(arg0 + 8);
    do {
      if ((*pbVar11 & 0x80) != 0) {
        uVar9 = uVar9 | uVar8;
        for (pbVar10 = *(byte **)(pbVar11 + 0x20); pbVar10 != (byte *)0x0;
            pbVar10 = *(byte **)(pbVar10 + 0x34)) {
          if ((*pbVar10 & 199) == 0) {
            ClearChain();
          }
          else if ((pbVar10[0x10] != 0) &&
                  (iVar4 = pbVar10[0x10] - 1, pbVar10[0x10] = (byte)iVar4, iVar4 == 0)) {
            *pbVar10 = *pbVar10 | 0x40;
          }
        }
        if ((*pbVar11 & 0x40) != 0) {
          Clear64byte();
          *pbVar11 = 0x80;
          pbVar11[0xf] = 2;
          pbVar11[0x13] = 0x40;
          pbVar11[0x19] = 0x16;
          pbVar11[0x24] = 1;
        }
        do {
          while( true ) {
            while( true ) {
              if (pbVar11[1] != 0) {
                pbVar11[1] = pbVar11[1] - 1;
                if ((pbVar11[0x19] != 0) && (pbVar11[0x17] != 0)) {
                  if (pbVar11[0x1c] == 0) {
                    iVar4 = (uint)pbVar11[0x1a] + (uint)pbVar11[0x19];
                    pbVar11[0x1a] = (byte)iVar4;
                    if ((iVar4 + -0x40) * 0x1000000 < 0) {
                      iVar4 = (int)(char)(byte)iVar4;
                    }
                    else {
                      iVar4 = 0x80 - iVar4;
                    }
                    uVar7 = (int)(iVar4 * (uint)pbVar11[0x17]) >> 6;
                    if (((pbVar11[0x16] ^ uVar7) & 0xff) != 0) {
                      pbVar11[0x16] = (byte)uVar7;
                      if (pbVar11[0x18] == 0) {
                        bVar6 = 0xc;
                      }
                      else {
                        bVar6 = 3;
                      }
                      *pbVar11 = *pbVar11 | bVar6;
                    }
                  }
                  else {
                    pbVar11[0x1c] = pbVar11[0x1c] - 1;
                  }
                }
                goto LAB_080e2b04;
              }
              pbVar10 = *(byte **)(pbVar11 + 0x40);
              bVar6 = *pbVar10;
              uVar7 = (uint)bVar6;
              if (uVar7 < 0x80) {
                uVar7 = (uint)pbVar11[7];
              }
              else {
                pbVar10 = pbVar10 + 1;
                *(byte **)(pbVar11 + 0x40) = pbVar10;
                if (0xbc < uVar7) {
                  pbVar11[7] = bVar6;
                }
              }
              if (uVar7 < 0xcf) break;
              sub_080E2BE8(uVar7 - 0xcf,arg0,pbVar11,*(undefined4 *)(iVar2 + 0x38));
            }
            if (0xb0 < uVar7) break;
            pbVar11[1] = (&DAT_0858bdb0)[uVar7];
          }
          *(char *)(arg0 + 10) = (char)(uVar7 - 0xb1);
          sub_080E2BE8(arg0,pbVar11,pbVar10,
                       *(undefined4 *)(*(int *)(iVar2 + 0x34) + (uVar7 - 0xb1) * 4));
        } while (*pbVar11 != 0);
      }
LAB_080e2b04:
      if (uVar3 - 1 == 0 || (int)uVar3 < 1) goto LAB_080e2b10;
      pbVar11 = pbVar11 + 0x50;
      uVar8 = uVar8 << 1;
      uVar3 = uVar3 - 1;
    } while( true );
  }
  uVar3 = (uint)*(byte *)(arg0 + 8);
  pbVar11 = *(byte **)(arg0 + 0x2c);
  do {
    if (((*pbVar11 & 0x80) != 0) && ((*pbVar11 & 0xf) != 0)) {
      TrkVolPitSet(arg0,pbVar11);
      for (pbVar10 = *(byte **)(pbVar11 + 0x20); pbVar10 != (byte *)0x0;
          pbVar10 = *(byte **)(pbVar10 + 0x34)) {
        if ((*pbVar10 & 199) == 0) {
          ClearChain();
        }
        else {
          bVar6 = pbVar10[1];
          if (((*pbVar11 & 3) != 0) && (ChnVolSetAsm(), (bVar6 & 7) != 0)) {
            pbVar10[0x1d] = pbVar10[0x1d] | 1;
          }
          if ((*pbVar11 & 0xc) != 0) {
            iVar4 = (uint)pbVar10[8] + (int)(char)pbVar11[8];
            if (iVar4 < 0) {
              iVar4 = 0;
            }
            if ((bVar6 & 7) == 0) {
              uVar5 = MidiKeyToFreq(*(undefined4 *)(pbVar10 + 0x24),iVar4,(uint)pbVar11[9]);
              *(undefined4 *)(pbVar10 + 0x20) = uVar5;
            }
            else {
              uVar5 = sub_080E2BE8(bVar6 & 7,iVar4,(uint)pbVar11[9],*(undefined4 *)(iVar2 + 0x30));
              *(undefined4 *)(pbVar10 + 0x20) = uVar5;
              pbVar10[0x1d] = pbVar10[0x1d] | 2;
            }
          }
        }
      }
      *pbVar11 = *pbVar11 & 0xf0;
    }
  } while ((uVar3 - 1 != 0 && 0 < (int)uVar3) &&
          (pbVar10 = pbVar11 + 0x50, bVar1 = -0x51 < (int)pbVar11, uVar3 = uVar3 - 1,
          pbVar11 = pbVar10, pbVar10 != (byte *)0x0 && bVar1));
  goto LAB_080e2bd8;
LAB_080e2b10:
  *(int *)(arg0 + 0xc) = *(int *)(arg0 + 0xc) + 1;
  if (uVar9 == 0) {
    *(undefined4 *)(arg0 + 4) = 0x80000000;
    goto LAB_080e2bd8;
  }
  *(uint *)(arg0 + 4) = uVar9;
  uVar3 = *(ushort *)(arg0 + 0x22) - 0x96;
  goto LAB_080e2b28;
}


// sub_080E2BE8 @ 0x080E2BE8

undefined4 sub_080E2BE8(undefined4 arg0,undefined4 arg1,undefined4 arg2,code *arg3)

{
  undefined4 uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x080e2be8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*arg3)();
  return uVar1;
}


// TrackStop @ 0x080E2BF8

void TrackStop(undefined4 arg0,byte *arg1)

{
  uint arg1_00;
  uint extraout_r1;
  undefined4 in_r2;
  char *pcVar1;
  
  arg1_00 = (uint)*arg1;
  if ((*arg1 & 0x80) != 0) {
    for (pcVar1 = *(char **)(arg1 + 0x20); pcVar1 != (char *)0x0; pcVar1 = *(char **)(pcVar1 + 0x34)
        ) {
      if (*pcVar1 != '\0') {
        if ((pcVar1[1] & 7U) != 0) {
          sub_080E2BE8((byte)pcVar1[1] & 7,arg1_00,in_r2,*(undefined4 *)(DAT_03007ff0 + 0x2c));
          arg1_00 = extraout_r1;
        }
        *pcVar1 = '\0';
      }
      pcVar1[0x2c] = '\0';
      pcVar1[0x2d] = '\0';
      pcVar1[0x2e] = '\0';
      pcVar1[0x2f] = '\0';
    }
    arg1[0x20] = 0;
    arg1[0x21] = 0;
    arg1[0x22] = 0;
    arg1[0x23] = 0;
  }
  return;
}


// ChnVolSetAsm @ 0x080E2C3C

void ChnVolSetAsm(void)

{
  uint uVar1;
  int unaff_r4;
  int unaff_r5;
  
  uVar1 = (int)((uint)*(byte *)(unaff_r4 + 0x12) * (*(char *)(unaff_r4 + 0x14) + 0x80) *
               (uint)*(byte *)(unaff_r5 + 0x10)) >> 0xe;
  if (0xff < uVar1) {
    uVar1 = 0xff;
  }
  *(char *)(unaff_r4 + 2) = (char)uVar1;
  uVar1 = (int)((uint)*(byte *)(unaff_r4 + 0x12) * (0x7f - *(char *)(unaff_r4 + 0x14)) *
               (uint)*(byte *)(unaff_r5 + 0x11)) >> 0xe;
  if (0xff < uVar1) {
    uVar1 = 0xff;
  }
  *(char *)(unaff_r4 + 3) = (char)uVar1;
  return;
}


// ply_note @ 0x080E2C6C

void ply_note(int arg0,int arg1,byte *arg2)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  byte *pbVar5;
  byte bVar6;
  byte bVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  byte *pbVar14;
  byte *pbVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar18;
  
  iVar4 = DAT_03007ff0;
  arg2[4] = *(byte *)(arg0 + 0x858be30);
  pbVar8 = *(byte **)(arg2 + 0x40);
  if (*pbVar8 < 0x80) {
    arg2[5] = *pbVar8;
    pbVar9 = pbVar8 + 1;
    if (*pbVar9 < 0x80) {
      arg2[6] = *pbVar9;
      pbVar9 = pbVar8 + 2;
      if (*pbVar9 < 0x80) {
        arg2[4] = arg2[4] + *pbVar9;
        pbVar9 = pbVar8 + 3;
      }
    }
    *(byte **)(arg2 + 0x40) = pbVar9;
  }
  bVar6 = 0;
  pbVar8 = arg2 + 0x24;
  bVar1 = *pbVar8;
  if ((bVar1 & 0xc0) == 0) {
    bVar7 = arg2[5];
  }
  else {
    bVar7 = arg2[5];
    uVar10 = (uint)bVar7;
    if ((bVar1 & 0x40) != 0) {
      uVar10 = (uint)*(byte *)(*(int *)(arg2 + 0x2c) + uVar10);
    }
    pbVar8 = (byte *)(uVar10 * 0xc + *(int *)(arg2 + 0x28));
    if ((*pbVar8 & 0xc0) != 0) goto LAB_080e2e52;
    if ((bVar1 & 0x80) != 0) {
      if ((pbVar8[3] & 0x80) != 0) {
        bVar6 = (pbVar8[3] + 0x40) * '\x02';
      }
      bVar7 = pbVar8[1];
    }
  }
  uVar10 = (uint)arg2[0x1d] + (uint)*(byte *)(arg1 + 9);
  if (0xff < uVar10) {
    uVar10 = 0xff;
  }
  bVar1 = *pbVar8;
  if ((bVar1 & 7) == 0) {
    bVar3 = false;
    pbVar15 = (byte *)(iVar4 + 0x50);
    uVar11 = (uint)*(byte *)(iVar4 + 6);
    uVar16 = uVar10;
    pbVar9 = arg2;
    pbVar5 = (byte *)0x0;
    do {
      pbVar14 = pbVar15;
      if ((*pbVar15 & 199) == 0) goto LAB_080e2dac;
      pbVar14 = pbVar5;
      if ((*pbVar15 & 0x40) == 0) {
        if (!bVar3) goto LAB_080e2d84;
        goto LAB_080e2da0;
      }
      if (bVar3) {
LAB_080e2d84:
        uVar12 = (uint)pbVar15[0x13];
        if (uVar12 < uVar16) {
          uVar16 = uVar12;
          pbVar5 = *(byte **)(pbVar15 + 0x2c);
          goto LAB_080e2d9e;
        }
        if (uVar12 <= uVar16) {
          pbVar5 = *(byte **)(pbVar15 + 0x2c);
          bVar18 = pbVar9 <= pbVar5;
          if ((pbVar9 < pbVar5) || (pbVar5 = pbVar9, bVar18)) goto LAB_080e2d9e;
        }
      }
      else {
        bVar3 = true;
        uVar16 = (uint)pbVar15[0x13];
        pbVar5 = *(byte **)(pbVar15 + 0x2c);
LAB_080e2d9e:
        pbVar9 = pbVar5;
        pbVar14 = pbVar15;
      }
LAB_080e2da0:
      pbVar15 = pbVar15 + 0x40;
      uVar12 = uVar11 - 1;
      bVar18 = 0 < (int)uVar11;
      uVar11 = uVar12;
      pbVar5 = pbVar14;
    } while (uVar12 != 0 && bVar18);
    if (pbVar14 == (byte *)0x0) goto LAB_080e2e52;
  }
  else {
    if (*(int *)(iVar4 + 0x1c) == 0) goto LAB_080e2e52;
    pbVar14 = (byte *)(*(int *)(iVar4 + 0x1c) + ((bVar1 & 7) - 1) * 0x40);
    if (((((*pbVar14 & 199) != 0) && ((*pbVar14 & 0x40) == 0)) && (uVar10 <= pbVar14[0x13])) &&
       ((pbVar14[0x13] != uVar10 || (*(byte **)(pbVar14 + 0x2c) < arg2)))) goto LAB_080e2e52;
  }
LAB_080e2dac:
  ClearChain();
  pbVar14[0x30] = 0;
  pbVar14[0x31] = 0;
  pbVar14[0x32] = 0;
  pbVar14[0x33] = 0;
  iVar13 = *(int *)(arg2 + 0x20);
  *(int *)(pbVar14 + 0x34) = iVar13;
  if (iVar13 != 0) {
    *(byte **)(iVar13 + 0x30) = pbVar14;
  }
  *(byte **)(arg2 + 0x20) = pbVar14;
  *(byte **)(pbVar14 + 0x2c) = arg2;
  bVar2 = arg2[0x1b];
  arg2[0x1c] = bVar2;
  if (bVar2 != 0) {
    clear_modM((uint)bVar2,arg2);
  }
  TrkVolPitSet(arg1,arg2);
  *(undefined4 *)(pbVar14 + 0x10) = *(undefined4 *)(arg2 + 4);
  pbVar14[0x13] = (byte)uVar10;
  pbVar14[8] = bVar7;
  pbVar14[0x14] = bVar6;
  pbVar14[1] = *pbVar8;
  uVar17 = *(undefined4 *)(pbVar8 + 4);
  *(undefined4 *)(pbVar14 + 0x24) = uVar17;
  *(undefined4 *)(pbVar14 + 4) = *(undefined4 *)(pbVar8 + 8);
  *(undefined2 *)(pbVar14 + 0xc) = *(undefined2 *)(arg2 + 0x1e);
  ChnVolSetAsm();
  iVar13 = (uint)pbVar14[8] + (int)(char)arg2[8];
  if (iVar13 < 0) {
    iVar13 = 0;
  }
  if ((bVar1 & 7) == 0) {
    uVar17 = MidiKeyToFreq(uVar17,iVar13,(uint)arg2[9]);
  }
  else {
    pbVar14[0x1e] = pbVar8[2];
    bVar6 = pbVar8[3];
    if (((bVar6 & 0x80) != 0) || ((bVar6 & 0x70) == 0)) {
      bVar6 = 8;
    }
    pbVar14[0x1f] = bVar6;
    uVar17 = sub_080E2BE8(bVar1 & 7,iVar13,(uint)arg2[9],*(undefined4 *)(iVar4 + 0x30));
  }
  *(undefined4 *)(pbVar14 + 0x20) = uVar17;
  *pbVar14 = 0x80;
  *arg2 = *arg2 & 0xf0;
LAB_080e2e52:
                    /* WARNING: Could not recover jumptable at 0x080e2e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE,unaff_r9,unaff_r10,unaff_r11);
  return;
}


// ply_endtie @ 0x080E2E6C

void ply_endtie(undefined4 arg0,int arg1)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  
  bVar3 = **(byte **)(arg1 + 0x40);
  if (bVar3 < 0x80) {
    *(byte *)(arg1 + 5) = bVar3;
    *(byte **)(arg1 + 0x40) = *(byte **)(arg1 + 0x40) + 1;
  }
  else {
    bVar3 = *(byte *)(arg1 + 5);
  }
  pbVar2 = *(byte **)(arg1 + 0x20);
  while( true ) {
    if (pbVar2 == (byte *)0x0) {
      return;
    }
    bVar1 = *pbVar2;
    if ((((bVar1 & 0x83) != 0) && ((bVar1 & 0x40) == 0)) && (pbVar2[0x11] == bVar3)) break;
    pbVar2 = *(byte **)(pbVar2 + 0x34);
  }
  *pbVar2 = bVar1 | 0x40;
  return;
}


// clear_modM @ 0x080E2EAC

void clear_modM(undefined4 arg0,byte *arg1)

{
  byte bVar1;
  
  arg1[0x16] = 0;
  arg1[0x1a] = 0;
  if (arg1[0x18] == 0) {
    bVar1 = 0xc;
  }
  else {
    bVar1 = 3;
  }
  *arg1 = *arg1 | bVar1;
  return;
}


// ld_r3_tp_adr_i_2 @ 0x080E2EC8

void ld_r3_tp_adr_i_2(undefined4 arg0,int arg1)

{
  *(int *)(arg1 + 0x40) = *(int *)(arg1 + 0x40) + 1;
  return;
}


// ply_lfos @ 0x080E2ED4

void ply_lfos(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  int arg1;
  int in_r3;
  
  ld_r3_tp_adr_i_2(in_r0,in_r1);
  *(char *)(arg1 + 0x19) = (char)in_r3;
  if (in_r3 == 0) {
    clear_modM(in_r0,arg1);
  }
  return;
}


// ply_mod @ 0x080E2EE8

void ply_mod(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  int arg1;
  int in_r3;
  
  ld_r3_tp_adr_i_2(in_r0,in_r1);
  *(char *)(arg1 + 0x17) = (char)in_r3;
  if (in_r3 == 0) {
    clear_modM(in_r0,arg1);
  }
  return;
}


// MidiKeyToFreq @ 0x080E2EFC

undefined4 MidiKeyToFreq(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  
  umul3232H32();
  uVar1 = umul3232H32();
  return uVar1;
}


// UnusedDummyFunc @ 0x080E2F60

void UnusedDummyFunc(void)

{
  return;
}


// MPlayContinue @ 0x080E2F64

void MPlayContinue(int arg0)

{
  if (*(dword *)(arg0 + 0x34) == 0x68736d53) {
    *(uint *)(arg0 + 4) = *(uint *)(arg0 + 4) & 0x7fffffff;
  }
  return;
}


// MPlayFadeOut @ 0x080E2F80

void MPlayFadeOut(int arg0,undefined4 arg1)

{
  if (*(dword *)(arg0 + 0x34) == 0x68736d53) {
    *(undefined2 *)(arg0 + 0x26) = (undefined2)arg1;
    *(undefined2 *)(arg0 + 0x24) = (undefined2)arg1;
    *(undefined2 *)(arg0 + 0x28) = 0x100;
  }
  return;
}


// m4aSoundInit @ 0x080E2FA0

void m4aSoundInit(void)

{
  int arg0;
  int *piVar1;
  dword dVar2;
  
  CpuSet(SoundMainRAM,0x3007000,0x40000e0);
  SoundInit(0x203e7d0);
  MPlayExtender(0x203f1e0);
  m4aSoundMode(0x95fb00);
  piVar1 = (int *)0x858d354;
  dVar2 = 4;
  do {
    arg0 = *piVar1;
    MPlayOpen(arg0,piVar1[1],(uint)*(byte *)(piVar1 + 2));
    *(char *)(arg0 + 0xb) = (char)*(undefined2 *)((int)piVar1 + 10);
    *(dword *)(arg0 + 0x18) = 0x203f3a0;
    piVar1 = piVar1 + 3;
    dVar2 = dVar2 - 1;
  } while (dVar2 != 0);
  return;
}


// m4aSoundMain @ 0x080E3018

void m4aSoundMain(void)

{
  SoundMain();
  return;
}


// m4aSongNumStart @ 0x080E3024

void m4aSongNumStart(uint arg0)

{
  int iVar1;
  
  iVar1 = (arg0 & 0xffff) * 8;
  MPlayStart(*(undefined4 *)((uint)*(ushort *)(&DAT_0858d388 + iVar1) * 0xc + 0x858d354),
             *(undefined4 *)(iVar1 + 0x858d384));
  return;
}


// m4aSongNumStartOrChange @ 0x080E3050

void m4aSongNumStartOrChange(uint arg0)

{
  int iVar1;
  int *arg0_00;
  
  iVar1 = (arg0 & 0xffff) * 8;
  arg0_00 = *(int **)((uint)*(ushort *)(&DAT_0858d388 + iVar1) * 0xc + 0x858d354);
  iVar1 = *(int *)(iVar1 + 0x858d384);
  if (*arg0_00 == iVar1) {
    if (((short)arg0_00[1] == 0) || (arg0_00[1] < 0)) {
      MPlayStart(arg0_00,*arg0_00);
    }
  }
  else {
    MPlayStart(arg0_00,iVar1);
  }
  return;
}


// m4aSongNumStartOrContinue @ 0x080E309C

void m4aSongNumStartOrContinue(uint arg0)

{
  int iVar1;
  int *arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = (arg0 & 0xffff) * 8;
  arg0_00 = *(int **)((uint)*(ushort *)(&DAT_0858d388 + iVar1) * 0xc + 0x858d354);
  iVar1 = *(int *)(iVar1 + 0x858d384);
  if (*arg0_00 == iVar1) {
    if ((short)arg0_00[1] == 0) {
      MPlayStart(arg0_00,*arg0_00);
    }
    else if (arg0_00[1] < 0) {
      MPlayContinue(arg0_00);
    }
  }
  else {
    MPlayStart(arg0_00,iVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x080e30ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// m4aSongNumStop @ 0x080E30F0

void m4aSongNumStop(uint arg0)

{
  int iVar1;
  int *arg0_00;
  
  iVar1 = (arg0 & 0xffff) * 8;
  arg0_00 = *(int **)((uint)*(ushort *)(&DAT_0858d388 + iVar1) * 0xc + 0x858d354);
  if (*arg0_00 == *(int *)(iVar1 + 0x858d384)) {
    m4aMPlayStop(arg0_00);
  }
  return;
}


// m4aSongNumContinue @ 0x080E3124

void m4aSongNumContinue(uint arg0)

{
  int iVar1;
  int *arg0_00;
  
  iVar1 = (arg0 & 0xffff) * 8;
  arg0_00 = *(int **)((uint)*(ushort *)(&DAT_0858d388 + iVar1) * 0xc + 0x858d354);
  if (*arg0_00 == *(int *)(iVar1 + 0x858d384)) {
    MPlayContinue(arg0_00);
  }
  return;
}


// m4aMPlayAllStop @ 0x080E3158

void m4aMPlayAllStop(void)

{
  dword dVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0x858d354;
  dVar1 = 4;
  do {
    m4aMPlayStop(*puVar2);
    puVar2 = puVar2 + 3;
    dVar1 = dVar1 - 1;
  } while (dVar1 != 0);
  return;
}


// m4aMPlayContinue @ 0x080E3184

void m4aMPlayContinue(void)

{
  undefined4 in_r0;
  
  MPlayContinue(in_r0);
  return;
}


// m4aMPlayAllContinue @ 0x080E3190

void m4aMPlayAllContinue(void)

{
  dword dVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0x858d354;
  dVar1 = 4;
  do {
    MPlayContinue(*puVar2);
    puVar2 = puVar2 + 3;
    dVar1 = dVar1 - 1;
  } while (dVar1 != 0);
  return;
}


// m4aMPlayFadeOut @ 0x080E31BC

void m4aMPlayFadeOut(undefined4 arg0,uint arg1)

{
  MPlayFadeOut(arg0,arg1 & 0xffff);
  return;
}


// m4aMPlayFadeOutTemporarily @ 0x080E31CC

void m4aMPlayFadeOutTemporarily(int arg0,undefined4 arg1)

{
  if (*(dword *)(arg0 + 0x34) == 0x68736d53) {
    *(undefined2 *)(arg0 + 0x26) = (undefined2)arg1;
    *(undefined2 *)(arg0 + 0x24) = (undefined2)arg1;
    *(undefined2 *)(arg0 + 0x28) = 0x101;
  }
  return;
}


// m4aMPlayFadeIn @ 0x080E31EC

void m4aMPlayFadeIn(int arg0,undefined4 arg1)

{
  if (*(dword *)(arg0 + 0x34) == 0x68736d53) {
    *(undefined2 *)(arg0 + 0x26) = (undefined2)arg1;
    *(undefined2 *)(arg0 + 0x24) = (undefined2)arg1;
    *(undefined2 *)(arg0 + 0x28) = 2;
    *(uint *)(arg0 + 4) = *(uint *)(arg0 + 4) & 0x7fffffff;
  }
  return;
}


// m4aMPlayImmInit @ 0x080E3214

void m4aMPlayImmInit(int arg0)

{
  byte *pbVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(arg0 + 8);
  pbVar1 = *(byte **)(arg0 + 0x2c);
  if (uVar2 != 0) {
    do {
      if (((*pbVar1 & 0x80) != 0) && ((*pbVar1 & 0x40) != 0)) {
        Clear64byte();
        *pbVar1 = 0x80;
        pbVar1[0xf] = 2;
        pbVar1[0x13] = 0x40;
        pbVar1[0x19] = 0x16;
        pbVar1[0x24] = 1;
      }
      uVar2 = uVar2 - 1;
      pbVar1 = pbVar1 + 0x50;
    } while (0 < (int)uVar2);
  }
  return;
}


// MPlayExtender @ 0x080E325C

void MPlayExtender(dword arg0)

{
  dword *pdVar1;
  undefined4 uStack_14;
  
  pdVar1 = DAT_03007ff0;
  REG_SOUNDCNT_X = 0x8f;
  REG_SOUNDCNT_L = 0;
  DAT_04000063 = 8;
  DAT_04000069 = 8;
  DAT_04000079 = 8;
  DAT_04000065 = 0x80;
  DAT_0400006d = 0x80;
  DAT_0400007d = 0x80;
  REG_SOUND3CNT_L = 0;
  REG_SOUNDCNT_L._0_1_ = 0x77;
  if (*DAT_03007ff0 == 0x68736d53) {
    *DAT_03007ff0 = 0x68736d54;
    DAT_0203f170 = 0x80e41d1;
    DAT_0203f194 = 0x80e2ed5;
    DAT_0203f19c = 0x80e2ee9;
    DAT_0203f1c0 = 0x80e4329;
    DAT_0203f1c4 = 0x80e2e6d;
    DAT_0203f1c8 = 0x80e346d;
    DAT_0203f1cc = 0x80e2bf9;
    DAT_0203f1d0 = 0x80e3835;
    DAT_0203f1d4 = 0x80e38fd;
    pdVar1[7] = arg0;
    pdVar1[10] = 0x80e3b11;
    pdVar1[0xb] = 0x80e3a59;
    pdVar1[0xc] = 0x80e39b1;
    *(undefined1 *)(pdVar1 + 3) = 0;
    uStack_14 = 0;
    CpuSet(&uStack_14,arg0,0x5000040);
    *(undefined1 *)(arg0 + 1) = 1;
    *(undefined1 *)(arg0 + 0x1c) = 0x11;
    *(undefined1 *)(arg0 + 0x41) = 2;
    *(undefined1 *)(arg0 + 0x5c) = 0x22;
    *(undefined1 *)(arg0 + 0x81) = 3;
    *(undefined1 *)(arg0 + 0x9c) = 0x44;
    *(undefined1 *)(arg0 + 0xc1) = 4;
    *(undefined1 *)(arg0 + 0xdc) = 0x88;
    *pdVar1 = 0x68736d53;
  }
  return;
}


// MusicPlayerJumpTableCopy @ 0x080E3374

void MusicPlayerJumpTableCopy(undefined4 arg0,undefined4 arg1,undefined4 arg2)

{
  software_interrupt(0x2a);
  return;
}


// ClearChain @ 0x080E3378

void ClearChain(void)

{
  undefined4 in_r0;
  
  _call_via_r1(in_r0,DAT_0203f1d8);
  return;
}


// Clear64byte @ 0x080E338C

void Clear64byte(void)

{
  undefined4 in_r0;
  
  _call_via_r1(in_r0,DAT_0203f1dc);
  return;
}


// SoundInit @ 0x080E33A0

void SoundInit(dword *arg0)

{
  byte bVar1;
  uint uVar2;
  undefined4 uStack_10;
  
  *arg0 = 0;
  uVar2 = REG_DMA1CNT;
  if ((uVar2 & 0x2000000) != 0) {
    REG_DMA1CNT = 0x84400004;
  }
  REG_DMA1CNT._2_2_ = 0x400;
  REG_SOUNDCNT_X = 0x8f;
  REG_SOUNDCNT_H = 0xb0e;
  bVar1 = DAT_04000089;
  DAT_04000089 = bVar1 & 0x3f | 0x40;
  REG_DMA1SAD = arg0 + 0xd4;
  REG_DMA1DAD = 0x40000a0;
  uStack_10 = 0;
  DAT_03007ff0 = arg0;
  CpuSet(&uStack_10,arg0,0x5000260);
  *(undefined1 *)((int)arg0 + 6) = 8;
  *(undefined1 *)((int)arg0 + 7) = 0xf;
  arg0[0xe] = 0x80e2c6d;
  arg0[10] = 0x80e4449;
  arg0[0xb] = 0x80e4449;
  arg0[0xc] = 0x80e4449;
  arg0[0xf] = 0x80e4449;
  MPlayJumpTableCopy();
  arg0[0xd] = 0x203f150;
  SampleFreqSet(0x40000);
  *arg0 = 0x68736d53;
  return;
}


// SampleFreqSet @ 0x080E346C

void SampleFreqSet(uint arg0)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint arg1;
  
  iVar2 = DAT_03007ff0;
  *(char *)(DAT_03007ff0 + 8) = (char)((arg0 & 0xf0000) >> 0x10);
  arg1 = (uint)*(ushort *)((((arg0 & 0xf0000) >> 0x10) - 1) * 2 + 0x858bd30);
  *(uint *)(iVar2 + 0x10) = arg1;
  uVar3 = __divsi3(0x630,arg1);
  *(char *)(iVar2 + 0xb) = (char)uVar3;
  uVar3 = __divsi3(arg1 * 0x91d1b + 5000,10000);
  *(undefined4 *)(iVar2 + 0x14) = uVar3;
  iVar4 = __divsi3(0x1000000,uVar3);
  *(int *)(iVar2 + 0x18) = iVar4 + 1 >> 1;
  DAT_04000102 = 0;
  uVar3 = __divsi3(0x44940,arg1);
  REG_TM0CNT = -(short)uVar3;
  m4aSoundVSyncOn();
  do {
    cVar1 = REG_VCOUNT._0_1_;
  } while (cVar1 == -0x61);
  do {
    cVar1 = REG_VCOUNT._0_1_;
  } while (cVar1 != -0x61);
  DAT_04000102 = 0x80;
  return;
}


// m4aSoundMode @ 0x080E3510

void m4aSoundMode(uint arg0)

{
  byte bVar1;
  dword *pdVar2;
  dword *pdVar3;
  int iVar4;
  
  pdVar2 = DAT_03007ff0;
  if (*DAT_03007ff0 == 0x68736d53) {
    *DAT_03007ff0 = 0x68736d54;
    if ((arg0 & 0xff) != 0) {
      *(byte *)((int)pdVar2 + 5) = (byte)arg0 & 0x7f;
    }
    if ((arg0 & 0xf00) != 0) {
      *(char *)((int)pdVar2 + 6) = (char)((arg0 & 0xf00) >> 8);
      iVar4 = 0xc;
      pdVar3 = pdVar2 + 0x14;
      do {
        *(undefined1 *)pdVar3 = 0;
        iVar4 = iVar4 + -1;
        pdVar3 = pdVar3 + 0x10;
      } while (iVar4 != 0);
    }
    if ((arg0 & 0xf000) != 0) {
      *(char *)((int)pdVar2 + 7) = (char)((arg0 & 0xf000) >> 0xc);
    }
    if ((arg0 & 0xb00000) != 0) {
      bVar1 = DAT_04000089;
      DAT_04000089 = bVar1 & 0x3f | (byte)((arg0 & 0x300000) >> 0xe);
    }
    if ((arg0 & 0xf0000) != 0) {
      m4aSoundVSyncOff();
      SampleFreqSet(arg0 & 0xf0000);
    }
    *pdVar2 = 0x68736d53;
  }
  return;
}


// SoundClear @ 0x080E35A8

void SoundClear(void)

{
  dword *pdVar1;
  dword *pdVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  
  pdVar1 = DAT_03007ff0;
  if (*DAT_03007ff0 == 0x68736d53) {
    *DAT_03007ff0 = 0x68736d54;
    iVar4 = 0xc;
    pdVar2 = pdVar1 + 0x14;
    do {
      *(undefined1 *)pdVar2 = 0;
      iVar4 = iVar4 + -1;
      pdVar2 = pdVar2 + 0x10;
    } while (0 < iVar4);
    puVar3 = (undefined1 *)pdVar1[7];
    if (puVar3 != (undefined1 *)0x0) {
      uVar5 = 1;
      do {
        _call_via_r1(uVar5 & 0xff,pdVar1[0xb]);
        *puVar3 = 0;
        uVar5 = uVar5 + 1;
        puVar3 = puVar3 + 0x40;
      } while ((int)uVar5 < 5);
    }
    *pdVar1 = 0x68736d53;
  }
  return;
}


// m4aSoundVSyncOff @ 0x080E35FC

void m4aSoundVSyncOff(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 local_8 [2];
  
  piVar2 = DAT_03007ff0;
  if (*DAT_03007ff0 + 0x978c92adU < 2) {
    *DAT_03007ff0 = *DAT_03007ff0 + 10;
    uVar1 = REG_DMA1CNT;
    if ((uVar1 & 0x2000000) != 0) {
      REG_DMA1CNT = 0x84400004;
    }
    REG_DMA1CNT._2_2_ = 0x400;
    local_8[0] = 0;
    CpuSet(local_8,piVar2 + 0xd4,0x500018c);
  }
  return;
}


// m4aSoundVSyncOn @ 0x080E3660

void m4aSoundVSyncOn(void)

{
  dword *pdVar1;
  dword dVar2;
  
  pdVar1 = DAT_03007ff0;
  dVar2 = *DAT_03007ff0;
  if (dVar2 != 0x68736d53) {
    REG_DMA1CNT._2_2_ = 0xb600;
    *(undefined1 *)(DAT_03007ff0 + 1) = 0;
    *pdVar1 = dVar2 - 10;
  }
  return;
}


// MPlayOpen @ 0x080E3698

void MPlayOpen(dword arg0,undefined1 *arg1,undefined4 arg2)

{
  dword *pdVar1;
  
  pdVar1 = DAT_03007ff0;
  if ((byte)arg2 != 0) {
    if (0x10 < (byte)arg2) {
      arg2._0_1_ = 0x10;
    }
    if (*DAT_03007ff0 == 0x68736d53) {
      *DAT_03007ff0 = 0x68736d54;
      Clear64byte();
      *(undefined1 **)(arg0 + 0x2c) = arg1;
      *(byte *)(arg0 + 8) = (byte)arg2;
      *(undefined4 *)(arg0 + 4) = 0x80000000;
      for (; (byte)arg2 != 0; arg2._0_1_ = (byte)arg2 - 1) {
        *arg1 = 0;
        arg1 = arg1 + 0x50;
      }
      if (pdVar1[8] != 0) {
        *(dword *)(arg0 + 0x38) = pdVar1[8];
        *(dword *)(arg0 + 0x3c) = pdVar1[9];
        pdVar1[8] = 0;
      }
      pdVar1[9] = arg0;
      pdVar1[8] = 0x80e2991;
      *pdVar1 = 0x68736d53;
      *(dword *)(arg0 + 0x34) = 0x68736d53;
    }
  }
  return;
}


// MPlayStart @ 0x080E3710

void MPlayStart(int *arg0,byte *arg1)

{
  byte bVar1;
  undefined1 *arg1_00;
  int iVar2;
  
  if (arg0[0xd] != 0x68736d53) {
    return;
  }
  bVar1 = arg1[2];
  if (((*(char *)((int)arg0 + 0xb) != '\0') &&
      (((*arg0 != 0 && ((*(byte *)arg0[0xb] & 0x40) != 0)) ||
       (((short)arg0[1] != 0 && (-1 < arg0[1])))))) &&
     (bVar1 = arg1[2], bVar1 < *(byte *)((int)arg0 + 9))) {
    return;
  }
  arg0[0xd] = arg0[0xd] + 1;
  arg0[1] = 0;
  *arg0 = (int)arg1;
  arg0[0xc] = *(int *)(arg1 + 4);
  *(byte *)((int)arg0 + 9) = bVar1;
  arg0[3] = 0;
  *(undefined2 *)(arg0 + 7) = 0x96;
  *(undefined2 *)(arg0 + 8) = 0x96;
  *(undefined2 *)((int)arg0 + 0x1e) = 0x100;
  *(undefined2 *)((int)arg0 + 0x22) = 0;
  *(undefined2 *)(arg0 + 9) = 0;
  iVar2 = 0;
  arg1_00 = (undefined1 *)arg0[0xb];
  if (*arg1 != 0) {
    if ((char)arg0[2] == '\0') goto LAB_080e37d2;
    do {
      TrackStop(arg0,arg1_00);
      *arg1_00 = 0xc0;
      *(undefined4 *)(arg1_00 + 0x20) = 0;
      *(undefined4 *)(arg1_00 + 0x40) = *(undefined4 *)(arg1 + iVar2 * 4 + 8);
      iVar2 = iVar2 + 1;
      arg1_00 = arg1_00 + 0x50;
      if ((int)(uint)*arg1 <= iVar2) break;
    } while (iVar2 < (int)(uint)*(byte *)(arg0 + 2));
  }
  if (iVar2 < (int)(uint)*(byte *)(arg0 + 2)) {
    do {
      TrackStop(arg0,arg1_00);
      *arg1_00 = 0;
      iVar2 = iVar2 + 1;
      arg1_00 = arg1_00 + 0x50;
    } while (iVar2 < (int)(uint)*(byte *)(arg0 + 2));
  }
LAB_080e37d2:
  if ((arg1[3] & 0x80) != 0) {
    m4aSoundMode((uint)arg1[3]);
  }
  arg0[0xd] = 0x68736d53;
  return;
}


// m4aMPlayStop @ 0x080E37F4

void m4aMPlayStop(int arg0)

{
  uint uVar1;
  int arg1;
  
  if (*(dword *)(arg0 + 0x34) == 0x68736d53) {
    *(undefined4 *)(arg0 + 0x34) = 0x68736d54;
    *(uint *)(arg0 + 4) = *(uint *)(arg0 + 4) | 0x80000000;
    uVar1 = (uint)*(byte *)(arg0 + 8);
    arg1 = *(int *)(arg0 + 0x2c);
    if (uVar1 != 0) {
      do {
        TrackStop(arg0,arg1);
        uVar1 = uVar1 - 1;
        arg1 = arg1 + 0x50;
      } while (0 < (int)uVar1);
    }
    *(dword *)(arg0 + 0x34) = 0x68736d53;
  }
  return;
}


// FadeOutBody @ 0x080E3834

void FadeOutBody(int arg0)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  
  if ((*(short *)(arg0 + 0x24) != 0) &&
     (sVar2 = *(short *)(arg0 + 0x26) + -1, *(short *)(arg0 + 0x26) = sVar2, sVar2 == 0)) {
    *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x24);
    uVar1 = *(ushort *)(arg0 + 0x28);
    if ((uVar1 & 2) == 0) {
      iVar4 = uVar1 - 0x10;
      *(short *)(arg0 + 0x28) = (short)iVar4;
      if (iVar4 * 0x10000 < 1) {
        uVar3 = (uint)*(byte *)(arg0 + 8);
        pbVar5 = *(byte **)(arg0 + 0x2c);
        if (uVar3 != 0) {
          do {
            TrackStop(arg0,pbVar5);
            if ((*(ushort *)(arg0 + 0x28) & 1) == 0) {
              *pbVar5 = (byte)*(ushort *)(arg0 + 0x28) & 1;
            }
            uVar3 = uVar3 - 1;
            pbVar5 = pbVar5 + 0x50;
          } while (0 < (int)uVar3);
        }
        if ((*(ushort *)(arg0 + 0x28) & 1) == 0) {
          uVar3 = 0x80000000;
        }
        else {
          uVar3 = *(uint *)(arg0 + 4) | 0x80000000;
        }
        *(uint *)(arg0 + 4) = uVar3;
        *(undefined2 *)(arg0 + 0x24) = 0;
        return;
      }
    }
    else {
      uVar3 = uVar1 + 0x10;
      *(short *)(arg0 + 0x28) = (short)uVar3;
      if (0xff < (uVar3 & 0xffff)) {
        *(undefined2 *)(arg0 + 0x28) = 0x100;
        *(undefined2 *)(arg0 + 0x24) = 0;
      }
    }
    uVar3 = (uint)*(byte *)(arg0 + 8);
    pbVar5 = *(byte **)(arg0 + 0x2c);
    if (uVar3 != 0) {
      do {
        if ((*pbVar5 & 0x80) != 0) {
          pbVar5[0x13] = (byte)(*(ushort *)(arg0 + 0x28) >> 2);
          *pbVar5 = *pbVar5 | 3;
        }
        uVar3 = uVar3 - 1;
        pbVar5 = pbVar5 + 0x50;
      } while (0 < (int)uVar3);
    }
  }
  return;
}


// TrkVolPitSet @ 0x080E38FC

void TrkVolPitSet(undefined4 arg0,byte *arg1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if ((*arg1 & 1) != 0) {
    uVar4 = (uint)arg1[0x12] * (uint)arg1[0x13] >> 5;
    if (arg1[0x18] == 1) {
      uVar4 = uVar4 * ((char)arg1[0x16] + 0x80) >> 7;
    }
    iVar2 = (char)arg1[0x14] * 2 + (int)(char)arg1[0x15];
    if (arg1[0x18] == 2) {
      iVar2 = iVar2 + (char)arg1[0x16];
    }
    iVar3 = -0x80;
    if ((-0x81 < iVar2) && (iVar3 = iVar2, 0x7f < iVar2)) {
      iVar3 = 0x7f;
    }
    arg1[0x10] = (byte)(uVar4 * (iVar3 + 0x80) >> 8);
    arg1[0x11] = (byte)(uVar4 * (0x7f - iVar3) >> 8);
  }
  if ((*arg1 & 4) != 0) {
    sVar1 = (ushort)arg1[0xd] +
            ((short)(char)arg1[0xc] + (ushort)arg1[0xf] * (short)(char)arg1[0xe]) * 4 +
            (char)arg1[10] * 0x100 + (char)arg1[0xb] * 0x100;
    if (arg1[0x18] == 0) {
      sVar1 = sVar1 + (char)arg1[0x16] * 0x10;
    }
    arg1[8] = (byte)((ushort)sVar1 >> 8);
    arg1[9] = (byte)sVar1;
  }
  *arg1 = *arg1 & 0xfa;
  return;
}


// MidiKeyToCgbFreq @ 0x080E39B0

void MidiKeyToCgbFreq(undefined4 arg0,undefined4 arg1,uint arg2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = arg2 & 0xff;
  if ((char)arg0 == '\x04') {
    if ((byte)arg1 < 0x15) {
      uVar1 = 0;
    }
    else {
      uVar1 = (uint)(byte)((byte)arg1 - 0x15);
      if (0x3b < uVar1) {
        uVar1 = 0x3b;
      }
    }
    uVar1 = (uint)*(byte *)(uVar1 + 0x858bde4);
  }
  else {
    if ((byte)arg1 < 0x24) {
      uVar1 = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = (uint)(byte)((byte)arg1 - 0x24);
      if (0x82 < uVar2) {
        uVar2 = 0x82;
        uVar1 = 0xff;
      }
    }
    iVar3 = (int)*(short *)((*(byte *)(uVar2 + 0x858bd48) & 0xf) * 2 + 0x858bdcc) >>
            ((int)(uint)*(byte *)(uVar2 + 0x858bd48) >> 4);
    uVar1 = iVar3 + ((int)((((int)*(short *)(((byte)(&DAT_0858bd49)[uVar2] & 0xf) * 2 + 0x858bdcc)
                            >> ((int)(uint)(byte)(&DAT_0858bd49)[uVar2] >> 4)) - iVar3) * uVar1) >>
                    8) + 0x800;
  }
                    /* WARNING: Could not recover jumptable at 0x080e3a4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1);
  return;
}


// CgbOscOff @ 0x080E3A58

void CgbOscOff(undefined4 arg0)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  if ((byte)arg0 == 2) {
    puVar2 = (undefined1 *)0x4000069;
LAB_080e3a96:
    *puVar2 = 8;
    puVar2 = puVar2 + 4;
  }
  else {
    if (2 < (byte)arg0) {
      if ((byte)arg0 == 3) {
        puVar2 = (undefined1 *)0x4000070;
        uVar1 = 0;
        goto LAB_080e3a9e;
      }
LAB_080e3a94:
      puVar2 = (undefined1 *)0x4000079;
      goto LAB_080e3a96;
    }
    if ((byte)arg0 != 1) goto LAB_080e3a94;
    DAT_04000063 = 8;
    puVar2 = &DAT_04000065;
  }
  uVar1 = 0x80;
LAB_080e3a9e:
  *puVar2 = uVar1;
  return;
}


// CgbModVol @ 0x080E3AA8

void CgbModVol(int arg0)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  
  bVar1 = *(byte *)(arg0 + 2);
  bVar2 = *(byte *)(arg0 + 3);
  if (bVar1 < bVar2) {
    if (bVar2 >> 1 < bVar1) goto LAB_080e3ad4;
    *(undefined1 *)(arg0 + 0x1b) = 0xf0;
LAB_080e3ae2:
    uVar4 = (uint)*(byte *)(arg0 + 3) + (uint)*(byte *)(arg0 + 2) >> 4;
    *(char *)(arg0 + 10) = (char)uVar4;
    if (uVar4 < 0x10) goto LAB_080e3af4;
    uVar3 = 0xf;
  }
  else {
    if (bVar2 <= bVar1 >> 1) {
      *(undefined1 *)(arg0 + 0x1b) = 0xf;
      goto LAB_080e3ae2;
    }
LAB_080e3ad4:
    *(undefined1 *)(arg0 + 0x1b) = 0xff;
    uVar3 = (undefined1)((uint)*(byte *)(arg0 + 3) + (uint)*(byte *)(arg0 + 2) >> 4);
  }
  *(undefined1 *)(arg0 + 10) = uVar3;
LAB_080e3af4:
  *(char *)(arg0 + 0x19) =
       (char)((int)((uint)*(byte *)(arg0 + 10) * (uint)*(byte *)(arg0 + 6) + 0xf) >> 4);
  *(byte *)(arg0 + 0x1b) = *(byte *)(arg0 + 0x1c) & *(byte *)(arg0 + 0x1b);
  return;
}


// CgbSound @ 0x080E3B10

void CgbSound(void)

{
  int iVar1;
  byte bVar2;
  dword dVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  byte *arg0;
  uint uVar9;
  byte *pbVar10;
  byte bVar11;
  uint local_3c;
  byte *local_34;
  byte *local_30;
  byte *local_2c;
  
  iVar1 = DAT_03007ff0;
  if (*(char *)(DAT_03007ff0 + 10) == '\0') {
    *(undefined1 *)(DAT_03007ff0 + 10) = 0xe;
  }
  else {
    *(char *)(DAT_03007ff0 + 10) = *(char *)(DAT_03007ff0 + 10) + -1;
  }
  uVar9 = 1;
  arg0 = *(byte **)(iVar1 + 0x1c);
  do {
    bVar2 = *arg0;
    if ((bVar2 & 199) != 0) {
      if (uVar9 == 2) {
        dVar3 = 0x4000061;
        local_34 = (byte *)0x4000061;
        pbVar10 = (byte *)0x4000068;
        local_30 = (byte *)0x4000069;
LAB_080e3bc8:
        local_2c = (byte *)(dVar3 + 0xb);
        pbVar7 = local_30 + 4;
      }
      else if ((int)uVar9 < 3) {
        if (uVar9 != 1) {
LAB_080e3bc0:
          dVar3 = 0x4000071;
          local_34 = (byte *)0x4000071;
          pbVar10 = (byte *)0x4000078;
          local_30 = (byte *)0x4000079;
          goto LAB_080e3bc8;
        }
        local_34 = (byte *)0x4000060;
        pbVar10 = (byte *)0x4000062;
        local_30 = (byte *)0x4000063;
        local_2c = &REG_SOUND1CNT_X;
        pbVar7 = &DAT_04000065;
      }
      else {
        if (uVar9 != 3) goto LAB_080e3bc0;
        local_34 = (byte *)0x4000070;
        pbVar10 = (byte *)0x4000072;
        local_30 = (byte *)0x4000073;
        local_2c = &REG_SOUND3CNT_X;
        pbVar7 = &DAT_04000075;
      }
      local_3c = (uint)*(byte *)(iVar1 + 10);
      bVar11 = *local_30;
      if ((bVar2 & 0x80) == 0) {
        if ((bVar2 & 4) == 0) {
          if ((bVar2 & 0x40) == 0) goto LAB_080e3d38;
          if ((bVar2 & 3) == 0) goto LAB_080e3d38;
          *arg0 = bVar2 & 0xfc;
          arg0[0xb] = arg0[7];
          if (arg0[7] == 0) {
LAB_080e3d6a:
            iVar4 = (uint)arg0[10] * (uint)arg0[0xc] + 0xff;
            arg0[9] = (byte)((uint)iVar4 >> 8);
            if ((iVar4 >> 8 & 0xffU) != 0) {
              *arg0 = *arg0 | 4;
              arg0[0x1d] = arg0[0x1d] | 1;
              if (uVar9 != 3) {
                bVar11 = 8;
              }
              goto LAB_080e3e3e;
            }
            goto LAB_080e3cea;
          }
          arg0[0x1d] = arg0[0x1d] | 1;
          if (uVar9 != 3) {
            bVar11 = arg0[7];
          }
          goto LAB_080e3e2c;
        }
        bVar2 = arg0[0xd];
        arg0[0xd] = (byte)(bVar2 - 1);
        if (0 < (int)((bVar2 - 1) * 0x1000000)) goto LAB_080e3e3e;
LAB_080e3cea:
        CgbOscOff(uVar9 & 0xff);
        *arg0 = 0;
      }
      else {
        if ((bVar2 & 0x40) != 0) goto LAB_080e3cea;
        *arg0 = 3;
        arg0[0x1d] = 3;
        CgbModVol(arg0);
        if (uVar9 == 2) {
LAB_080e3c38:
          *pbVar10 = arg0[0x1e] + (char)*(undefined4 *)(arg0 + 0x24) * '@';
LAB_080e3c98:
          bVar11 = arg0[4] + 8;
          bVar2 = 0;
          if (arg0[0x1e] != 0) {
            bVar2 = 0x40;
          }
LAB_080e3ca6:
          arg0[0x1a] = bVar2;
        }
        else {
          if ((int)uVar9 < 3) {
            if (uVar9 == 1) {
              *local_34 = arg0[0x1f];
              goto LAB_080e3c38;
            }
LAB_080e3c8c:
            *pbVar10 = arg0[0x1e];
            *local_2c = (byte)(*(int *)(arg0 + 0x24) << 3);
            goto LAB_080e3c98;
          }
          if (uVar9 != 3) goto LAB_080e3c8c;
          if (*(int *)(arg0 + 0x24) != *(int *)(arg0 + 0x28)) {
            *local_34 = 0x40;
            puVar8 = *(undefined4 **)(arg0 + 0x24);
            REG_WAVE_RAM = *puVar8;
            DAT_04000094 = puVar8[1];
            DAT_04000098 = puVar8[2];
            DAT_0400009c = puVar8[3];
            *(undefined4 **)(arg0 + 0x28) = puVar8;
          }
          *local_34 = bVar2 & 0x40;
          *pbVar10 = arg0[0x1e];
          if (arg0[0x1e] != 0) {
            bVar2 = 0xc0;
            goto LAB_080e3ca6;
          }
          arg0[0x1a] = 0x80;
        }
        arg0[0xb] = arg0[4];
        if (arg0[4] == 0) goto LAB_080e3dfe;
        arg0[9] = 0;
LAB_080e3e2c:
        arg0[0xb] = arg0[0xb] - 1;
        if (local_3c == 0) {
          local_3c = 0xffffffff;
LAB_080e3d38:
          if (arg0[0xb] == 0) {
            if (uVar9 == 3) {
              arg0[0x1d] = arg0[0x1d] | 1;
            }
            CgbModVol(arg0);
            bVar2 = *arg0 & 3;
            if ((*arg0 & 3) == 0) {
              bVar2 = arg0[9];
              arg0[9] = (byte)(bVar2 - 1);
              if (0 < (int)((bVar2 - 1) * 0x1000000)) {
                bVar2 = arg0[7];
                goto LAB_080e3e2a;
              }
              goto LAB_080e3d6a;
            }
            if (bVar2 == 1) {
LAB_080e3da2:
              arg0[9] = arg0[0x19];
              bVar2 = 7;
            }
            else if (bVar2 == 2) {
              bVar2 = arg0[9];
              arg0[9] = (byte)(bVar2 - 1);
              iVar4 = (bVar2 - 1) * 0x1000000;
              if (iVar4 + (uint)arg0[0x19] * -0x1000000 == 0 ||
                  iVar4 < (int)((uint)arg0[0x19] * 0x1000000)) {
LAB_080e3dc2:
                if (arg0[6] != 0) {
                  *arg0 = *arg0 - 1;
                  arg0[0x1d] = arg0[0x1d] | 1;
                  if (uVar9 != 3) {
                    bVar11 = 8;
                  }
                  goto LAB_080e3da2;
                }
                *arg0 = *arg0 & 0xfc;
                goto LAB_080e3d6a;
              }
              bVar2 = arg0[5];
            }
            else {
              bVar2 = arg0[9];
              arg0[9] = bVar2 + 1;
              if (arg0[10] <= (byte)(bVar2 + 1)) {
LAB_080e3dfe:
                *arg0 = *arg0 - 1;
                arg0[0xb] = arg0[5];
                if (arg0[5] == 0) goto LAB_080e3dc2;
                arg0[0x1d] = arg0[0x1d] | 1;
                arg0[9] = arg0[10];
                if (uVar9 != 3) {
                  bVar11 = arg0[5];
                }
                goto LAB_080e3e2c;
              }
              bVar2 = arg0[4];
            }
LAB_080e3e2a:
            arg0[0xb] = bVar2;
          }
          goto LAB_080e3e2c;
        }
LAB_080e3e3e:
        if ((arg0[0x1d] & 2) != 0) {
          if (((int)uVar9 < 4) && ((arg0[1] & 8) != 0)) {
            bVar2 = DAT_04000089;
            if (bVar2 < 0x40) {
              uVar5 = *(int *)(arg0 + 0x20) + 2;
              uVar6 = 0x7fc;
            }
            else {
              if (0x7f < bVar2) goto LAB_080e3e7e;
              uVar5 = *(int *)(arg0 + 0x20) + 1;
              uVar6 = 0x7fe;
            }
            *(uint *)(arg0 + 0x20) = uVar5 & uVar6;
          }
LAB_080e3e7e:
          if (uVar9 == 4) {
            *local_2c = (byte)*(undefined4 *)(arg0 + 0x20) | *local_2c & 8;
          }
          else {
            *local_2c = (byte)*(undefined4 *)(arg0 + 0x20);
          }
          bVar2 = arg0[0x21] + (arg0[0x1a] & 0xc0);
          arg0[0x1a] = bVar2;
          *pbVar7 = bVar2;
        }
        if ((arg0[0x1d] & 1) != 0) {
          bVar2 = REG_SOUNDCNT_L._1_1_;
          REG_SOUNDCNT_L._1_1_ = bVar2 & ~arg0[0x1c] | arg0[0x1b];
          if (uVar9 == 3) {
            *local_30 = *(byte *)(arg0[9] + 0x858be20);
            if ((arg0[0x1a] & 0x80) != 0) {
              *local_34 = 0x80;
              *pbVar7 = arg0[0x1a];
              arg0[0x1a] = arg0[0x1a] & 0x7f;
            }
          }
          else {
            *local_30 = arg0[9] * '\x10' + (bVar11 & 0xf);
            *pbVar7 = arg0[0x1a] | 0x80;
            if ((uVar9 == 1) && ((*local_34 & 8) == 0)) {
              *pbVar7 = arg0[0x1a] | 0x80;
            }
          }
        }
      }
      arg0[0x1d] = 0;
    }
    uVar9 = uVar9 + 1;
    arg0 = arg0 + 0x40;
    if (4 < (int)uVar9) {
      return;
    }
  } while( true );
}


// m4aMPlayTempoControl @ 0x080E3F5C

void m4aMPlayTempoControl(int arg0,undefined4 arg1)

{
  if (*(dword *)(arg0 + 0x34) == 0x68736d53) {
    *(ushort *)(arg0 + 0x1e) = (ushort)arg1;
    *(short *)(arg0 + 0x20) = (short)((uint)*(ushort *)(arg0 + 0x1c) * (uint)(ushort)arg1 >> 8);
  }
  return;
}


// m4aMPlayVolumeControl @ 0x080E3F84

void m4aMPlayVolumeControl(int arg0,undefined4 arg1,uint arg2)

{
  byte *pbVar1;
  uint uVar2;
  ushort uVar3;
  
  if (*(dword *)(arg0 + 0x34) == 0x68736d53) {
    *(undefined4 *)(arg0 + 0x34) = 0x68736d54;
    uVar2 = (uint)*(byte *)(arg0 + 8);
    pbVar1 = *(byte **)(arg0 + 0x2c);
    uVar3 = 1;
    if (uVar2 != 0) {
      do {
        if ((((ushort)arg1 & uVar3) != 0) && ((*pbVar1 & 0x80) != 0)) {
          pbVar1[0x13] = (byte)((arg2 & 0xffff) >> 2);
          *pbVar1 = *pbVar1 | 3;
        }
        uVar2 = uVar2 - 1;
        pbVar1 = pbVar1 + 0x50;
        uVar3 = uVar3 << 1;
      } while (0 < (int)uVar2);
    }
    *(dword *)(arg0 + 0x34) = 0x68736d53;
  }
  return;
}


// m4aMPlayPitchControl @ 0x080E3FEC

void m4aMPlayPitchControl(int arg0,undefined4 arg1,undefined4 arg2)

{
  uint uVar1;
  byte *pbVar2;
  ushort uVar3;
  
  if (*(dword *)(arg0 + 0x34) == 0x68736d53) {
    *(undefined4 *)(arg0 + 0x34) = 0x68736d54;
    uVar1 = (uint)*(byte *)(arg0 + 8);
    pbVar2 = *(byte **)(arg0 + 0x2c);
    uVar3 = 1;
    if (uVar1 != 0) {
      do {
        if ((((ushort)arg1 & uVar3) != 0) && ((*pbVar2 & 0x80) != 0)) {
          pbVar2[0xb] = (byte)((ushort)(undefined2)arg2 >> 8);
          pbVar2[0xd] = (byte)(undefined2)arg2;
          *pbVar2 = *pbVar2 | 0xc;
        }
        uVar1 = uVar1 - 1;
        pbVar2 = pbVar2 + 0x50;
        uVar3 = uVar3 << 1;
      } while (0 < (int)uVar1);
    }
    *(dword *)(arg0 + 0x34) = 0x68736d53;
  }
  return;
}


// m4aMPlayPanpotControl @ 0x080E4060

void m4aMPlayPanpotControl(int arg0,undefined4 arg1,undefined4 arg2)

{
  byte *pbVar1;
  uint uVar2;
  ushort uVar3;
  
  if (*(dword *)(arg0 + 0x34) == 0x68736d53) {
    *(undefined4 *)(arg0 + 0x34) = 0x68736d54;
    uVar2 = (uint)*(byte *)(arg0 + 8);
    pbVar1 = *(byte **)(arg0 + 0x2c);
    uVar3 = 1;
    if (uVar2 != 0) {
      do {
        if ((((ushort)arg1 & uVar3) != 0) && ((*pbVar1 & 0x80) != 0)) {
          pbVar1[0x15] = (byte)arg2;
          *pbVar1 = *pbVar1 | 3;
        }
        uVar2 = uVar2 - 1;
        pbVar1 = pbVar1 + 0x50;
        uVar3 = uVar3 << 1;
      } while (0 < (int)uVar2);
    }
    *(dword *)(arg0 + 0x34) = 0x68736d53;
  }
  return;
}


// ClearModM @ 0x080E40C8

void ClearModM(byte *arg0)

{
  byte bVar1;
  
  arg0[0x1a] = 0;
  arg0[0x16] = 0;
  if (arg0[0x18] == 0) {
    bVar1 = 0xc;
  }
  else {
    bVar1 = 3;
  }
  *arg0 = bVar1 | *arg0;
  return;
}


// m4aMPlayModDepthSet @ 0x080E40E8

void m4aMPlayModDepthSet(int arg0,undefined4 arg1,undefined4 arg2)

{
  byte *arg0_00;
  uint uVar1;
  ushort uVar2;
  
  if (*(dword *)(arg0 + 0x34) == 0x68736d53) {
    *(undefined4 *)(arg0 + 0x34) = 0x68736d54;
    uVar1 = (uint)*(byte *)(arg0 + 8);
    arg0_00 = *(byte **)(arg0 + 0x2c);
    uVar2 = 1;
    if (uVar1 != 0) {
      do {
        if (((((ushort)arg1 & uVar2) != 0) && ((*arg0_00 & 0x80) != 0)) &&
           (arg0_00[0x17] = (byte)arg2, (byte)arg2 == 0)) {
          ClearModM(arg0_00);
        }
        uVar1 = uVar1 - 1;
        arg0_00 = arg0_00 + 0x50;
        uVar2 = uVar2 << 1;
      } while (0 < (int)uVar1);
    }
    *(dword *)(arg0 + 0x34) = 0x68736d53;
  }
  return;
}


// m4aMPlayLFOSpeedSet @ 0x080E415C

void m4aMPlayLFOSpeedSet(int arg0,undefined4 arg1,undefined4 arg2)

{
  byte *arg0_00;
  uint uVar1;
  ushort uVar2;
  
  if (*(dword *)(arg0 + 0x34) == 0x68736d53) {
    *(undefined4 *)(arg0 + 0x34) = 0x68736d54;
    uVar1 = (uint)*(byte *)(arg0 + 8);
    arg0_00 = *(byte **)(arg0 + 0x2c);
    uVar2 = 1;
    if (uVar1 != 0) {
      do {
        if (((((ushort)arg1 & uVar2) != 0) && ((*arg0_00 & 0x80) != 0)) &&
           (arg0_00[0x19] = (byte)arg2, (byte)arg2 == 0)) {
          ClearModM(arg0_00);
        }
        uVar1 = uVar1 - 1;
        arg0_00 = arg0_00 + 0x50;
        uVar2 = uVar2 << 1;
      } while (0 < (int)uVar1);
    }
    *(dword *)(arg0 + 0x34) = 0x68736d53;
  }
  return;
}


// ply_memacc @ 0x080E41D0

void ply_memacc(int arg0,int arg1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 *puVar3;
  uint uVar4;
  byte *pbVar5;
  
  puVar3 = *(undefined1 **)(arg1 + 0x40);
  uVar1 = *puVar3;
  *(undefined1 **)(arg1 + 0x40) = puVar3 + 1;
  pbVar5 = (byte *)((uint)(byte)puVar3[1] + *(int *)(arg0 + 0x18));
  *(undefined1 **)(arg1 + 0x40) = puVar3 + 2;
  bVar2 = puVar3[2];
  uVar4 = (uint)bVar2;
  *(undefined1 **)(arg1 + 0x40) = puVar3 + 3;
  switch(uVar1) {
  case 0:
    *pbVar5 = bVar2;
    return;
  case 1:
    *pbVar5 = *pbVar5 + bVar2;
    return;
  case 2:
    *pbVar5 = *pbVar5 - bVar2;
    return;
  case 3:
    *pbVar5 = *(byte *)(*(int *)(arg0 + 0x18) + uVar4);
    return;
  case 4:
    *pbVar5 = *pbVar5 + *(char *)(*(int *)(arg0 + 0x18) + uVar4);
    return;
  case 5:
    *pbVar5 = *pbVar5 - *(char *)(*(int *)(arg0 + 0x18) + uVar4);
    return;
  case 6:
    if (*pbVar5 == uVar4) {
LAB_080e4308:
      _call_via_r2(arg0,arg1,DAT_0203f154);
      return;
    }
    break;
  case 7:
    if (*pbVar5 != uVar4) goto LAB_080e4308;
    break;
  case 8:
    if (uVar4 < *pbVar5) goto LAB_080e4308;
    break;
  case 9:
    if (uVar4 <= *pbVar5) goto LAB_080e4308;
    break;
  case 10:
    if (*pbVar5 <= uVar4) goto LAB_080e4308;
    break;
  case 0xb:
    if (*pbVar5 < uVar4) goto LAB_080e4308;
    break;
  case 0xc:
    if (*pbVar5 == *(byte *)(*(int *)(arg0 + 0x18) + uVar4)) goto LAB_080e4308;
    break;
  case 0xd:
    if (*pbVar5 != *(byte *)(*(int *)(arg0 + 0x18) + uVar4)) goto LAB_080e4308;
    break;
  case 0xe:
    if (*(byte *)(*(int *)(arg0 + 0x18) + uVar4) < *pbVar5) goto LAB_080e4308;
    break;
  case 0xf:
    if (*(byte *)(*(int *)(arg0 + 0x18) + uVar4) <= *pbVar5) goto LAB_080e4308;
    break;
  case 0x10:
    if (*pbVar5 <= *(byte *)(*(int *)(arg0 + 0x18) + uVar4)) goto LAB_080e4308;
    break;
  case 0x11:
    if (*pbVar5 < *(byte *)(*(int *)(arg0 + 0x18) + uVar4)) goto LAB_080e4308;
    break;
  default:
    goto switchD_080e41fc_default;
  }
  *(int *)(arg1 + 0x40) = *(int *)(arg1 + 0x40) + 4;
switchD_080e41fc_default:
  return;
}


// ply_xcmd @ 0x080E4328

void ply_xcmd(undefined4 arg0,int arg1)

{
  byte bVar1;
  
  bVar1 = **(byte **)(arg1 + 0x40);
  *(byte **)(arg1 + 0x40) = *(byte **)(arg1 + 0x40) + 1;
  _call_via_r2(arg0,arg1,*(undefined4 *)((uint)bVar1 * 4 + 0x858be64));
  return;
}


// ply_xxx @ 0x080E4348

void ply_xxx(void)

{
  undefined4 in_r0;
  undefined4 in_r1;
  
  _call_via_r2(in_r0,in_r1,DAT_0203f150);
  return;
}


// ply_xwave @ 0x080E435C

void ply_xwave(undefined4 arg0,int arg1)

{
  *(undefined4 *)(arg1 + 0x28) = **(undefined4 **)(arg1 + 0x40);
  *(undefined4 **)(arg1 + 0x40) = *(undefined4 **)(arg1 + 0x40) + 1;
  return;
}


// ply_xtype @ 0x080E43A4

void ply_xtype(undefined4 arg0,int arg1)

{
  *(undefined1 *)(arg1 + 0x24) = **(undefined1 **)(arg1 + 0x40);
  *(int *)(arg1 + 0x40) = *(int *)(arg1 + 0x40) + 1;
  return;
}


// ply_xatta @ 0x080E43B8

void ply_xatta(undefined4 arg0,int arg1)

{
  *(undefined1 *)(arg1 + 0x2c) = **(undefined1 **)(arg1 + 0x40);
  *(int *)(arg1 + 0x40) = *(int *)(arg1 + 0x40) + 1;
  return;
}


// ply_xdeca @ 0x080E43CC

void ply_xdeca(undefined4 arg0,int arg1)

{
  *(undefined1 *)(arg1 + 0x2d) = **(undefined1 **)(arg1 + 0x40);
  *(int *)(arg1 + 0x40) = *(int *)(arg1 + 0x40) + 1;
  return;
}


// ply_xsust @ 0x080E43E0

void ply_xsust(undefined4 arg0,int arg1)

{
  *(undefined1 *)(arg1 + 0x2e) = **(undefined1 **)(arg1 + 0x40);
  *(int *)(arg1 + 0x40) = *(int *)(arg1 + 0x40) + 1;
  return;
}


// ply_xrele @ 0x080E43F4

void ply_xrele(undefined4 arg0,int arg1)

{
  *(undefined1 *)(arg1 + 0x2f) = **(undefined1 **)(arg1 + 0x40);
  *(int *)(arg1 + 0x40) = *(int *)(arg1 + 0x40) + 1;
  return;
}


// ply_xiecv @ 0x080E4408

void ply_xiecv(undefined4 arg0,int arg1)

{
  *(undefined1 *)(arg1 + 0x1e) = **(undefined1 **)(arg1 + 0x40);
  *(undefined1 **)(arg1 + 0x40) = *(undefined1 **)(arg1 + 0x40) + 1;
  return;
}


// ply_xiecl @ 0x080E4414

void ply_xiecl(undefined4 arg0,int arg1)

{
  *(undefined1 *)(arg1 + 0x1f) = **(undefined1 **)(arg1 + 0x40);
  *(undefined1 **)(arg1 + 0x40) = *(undefined1 **)(arg1 + 0x40) + 1;
  return;
}


// ply_xleng @ 0x080E4420

void ply_xleng(undefined4 arg0,int arg1)

{
  *(undefined1 *)(arg1 + 0x26) = **(undefined1 **)(arg1 + 0x40);
  *(int *)(arg1 + 0x40) = *(int *)(arg1 + 0x40) + 1;
  return;
}


// ply_xswee @ 0x080E4434

void ply_xswee(undefined4 arg0,int arg1)

{
  *(undefined1 *)(arg1 + 0x27) = **(undefined1 **)(arg1 + 0x40);
  *(int *)(arg1 + 0x40) = *(int *)(arg1 + 0x40) + 1;
  return;
}


// DummyFunc @ 0x080E4448

void DummyFunc(void)

{
  return;
}


// sub_080E444C @ 0x080E444C

dword sub_080E444C(uint arg0)

{
  uint uVar1;
  dword dVar2;
  
  uVar1 = arg0 & 0xffff;
  if (uVar1 == 0x12d) {
    dVar2 = (uint)DAT_0203d3a4 * 0x1c + 0x872f104;
  }
  else if (uVar1 == 0x12e) {
    dVar2 = 0x872f174;
  }
  else {
    dVar2 = uVar1 * 0x1c + 0x872c774;
  }
  return dVar2;
}


// sub_080E44A4 @ 0x080E44A4

void sub_080E44A4(void)

{
  undefined4 local_10;
  
  local_10 = 0;
  CpuSet(&local_10,0x30063a0,0x5000007);
  DAT_0203cb94 = 0xffff;
  DAT_0203cb90 = 0xffff;
  sub_080EA9E8(0);
  sub_080E44F8();
  sub_080EA280();
  DAT_0203d388 = 0;
  return;
}


// sub_080E44F8 @ 0x080E44F8

void sub_080E44F8(void)

{
  DAT_0203c20c = 0;
  DAT_0203c208 = 0;
  DAT_0203c204 = 0;
  DAT_0203c224 = 0;
  DAT_0203c220 = 0;
  DAT_0203c21c = 0;
  DAT_0203c218 = 0;
  DAT_0203c214 = 0;
  DAT_0203c210 = 0;
  DAT_0203d39e = 0;
  return;
}


// sub_080E4520 @ 0x080E4520

void sub_080E4520(void)

{
  uint uVar1;
  undefined4 arg1;
  int arg0;
  
  uVar1 = 0;
  do {
    arg0 = (int)(short)uVar1;
    arg1 = 10;
    if (arg0 < 4) {
      arg1 = 4;
    }
    sub_080C35C4(arg0,arg1);
    sub_080C3600(arg0,arg1);
    uVar1 = arg0 + 1U & 0xffff;
  } while ((int)((arg0 + 1U) * 0x10000) >> 0x10 < 0x10);
  return;
}


// sub_080E4554 @ 0x080E4554

void sub_080E4554(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_20;
  short local_1c [2];
  
  sub_080E44F8();
  DAT_0203d38c = 0;
  DAT_0203d3ac = 0xffff;
  DAT_0203d3ae = 0xffff;
  DAT_0203d3a8 = 0;
  DAT_030063b4 = 0;
  if (DAT_03005180 == 0) {
    DAT_030063ac = 2;
    DAT_030063b4 = DAT_03005180;
    uVar1 = sub_080C5D0C();
    uVar1 = uVar1 & 0x7f;
    if (0x6b < uVar1) {
      uVar1 = 0x3e;
    }
    sub_080ED398(&local_20,local_1c,uVar1);
  }
  else {
    if (DAT_03005180 != 1) goto LAB_080e45f8;
    DAT_030063ac = DAT_03005180;
    sub_080F450C(&local_20,local_1c);
  }
  DAT_0203cb80 = local_20;
  DAT_0203cb9c = local_1c[0];
LAB_080e45f8:
  DAT_0203c200 = 0;
  DAT_0203cb74 = 0;
  DAT_0203cb70 = 0;
  DAT_0203d168 = 0;
  DAT_0203cb78 = 0;
  DAT_0203cb7a = 0;
  DAT_0203cb7c = 0;
  DAT_0203cb7e = 0;
  sub_080ED7BC();
  DAT_0203d0ce = 0;
  DAT_0203d16a = 0;
  sub_080ED938(0);
  if (0 < DAT_0203d16a) {
    DAT_0203cb9c = 1;
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
  DAT_0203d16a = 0;
  DAT_0203d322 = 0;
  sub_080C7C60();
  sub_080EA9E8(0);
  DAT_0203d323 = 0;
  DAT_030063a6 = 1;
  DAT_030063aa = 0;
  sub_080E5668();
  DAT_030063b8 = sub_080AD0FC(0x86bef88,0xffff);
  Font_ResetGlyphSpriteCache(0x180);
  DAT_0203d38a = DAT_030031b4;
  return;
}


// sub_080E471C @ 0x080E471C

void sub_080E471C(uint arg0,undefined4 arg1,uint arg2,undefined4 arg3)

{
  uint uVar1;
  
  uVar1 = arg2 & 0xffff;
  sub_080E4554();
  DAT_0203cb80 = 0;
  DAT_0203cb9c = 1;
  DAT_0203cb9e = 1;
  DAT_0203cb90 = arg0 & 0xffff;
  DAT_0203cb94 = uVar1;
  DAT_0203cb98 = (undefined2)arg1;
  DAT_0203cb9a = (undefined2)arg3;
  if (uVar1 == 0xffff) {
    sub_080ED938(0);
  }
  else {
    sub_080ED938(0xffff);
  }
  DAT_0203d323 = 1;
  return;
}


