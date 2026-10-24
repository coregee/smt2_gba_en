/* Ghidra decompilation of asm/code_081267F4.s (reference only; not compiled). */

// sub_081267F4 @ 0x081267F4

void sub_081267F4(void)

{
  sub_08126850();
  return;
}


// sub_08126800 @ 0x08126800

void sub_08126800(undefined4 arg0)

{
  DAT_030063a6 = 1;
  DAT_030063a2 = 1;
  DAT_030063a0 = 1;
  DAT_030063a4 = 0;
  DAT_030063b4 = 0;
  DAT_030063ac = (undefined2)arg0;
  DAT_030063ae = 0;
  return;
}


// sub_0812681C @ 0x0812681C

void sub_0812681C(void)

{
  return;
}


// sub_08126828 @ 0x08126828

void sub_08126828(void)

{
  return;
}


// sub_0812682C @ 0x0812682C

void sub_0812682C(void)

{
  return;
}


// sub_08126830 @ 0x08126830

void sub_08126830(void)

{
  return;
}


// sub_08126834 @ 0x08126834

void sub_08126834(undefined4 arg0)

{
  DAT_0203cb98 = (short)arg0 + DAT_0203cb98;
  return;
}


// sub_08126850 @ 0x08126850

void sub_08126850(void)

{
  sub_08126800(2);
  return;
}


// sub_0812685C @ 0x0812685C

uint sub_0812685C(void)

{
  return (uint)DAT_030063a6;
}


// sub_08126868 @ 0x08126868

void sub_08126868(void)

{
  return;
}


// sub_0812686C @ 0x0812686C

void sub_0812686C(void)

{
  return;
}


// sub_08126870 @ 0x08126870

void sub_08126870(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    sub_08126898(uVar1 * 0x28 + 0x3006480);
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 8);
  return;
}


// sub_08126898 @ 0x08126898

void sub_08126898(undefined1 *arg0)

{
  undefined4 local_10;
  
  local_10 = 0;
  CpuSet(&local_10,arg0,0x500000a);
  *arg0 = 0;
  *(undefined2 *)(arg0 + 0x14) = 1;
  *(undefined2 *)(arg0 + 0x12) = 1;
  *(undefined2 *)(arg0 + 0x10) = 1;
  *(undefined2 *)(arg0 + 0xc) = 1;
  *(undefined2 *)(arg0 + 10) = 1;
  *(undefined2 *)(arg0 + 8) = 1;
  *(undefined2 *)(arg0 + 6) = 1;
  *(undefined2 *)(arg0 + 0x26) = 0xffff;
  *(undefined2 *)(arg0 + 0x24) = 0xffff;
  *(undefined2 *)(arg0 + 0x22) = 0xffff;
  *(undefined2 *)(arg0 + 0x20) = 0xffff;
  *(undefined2 *)(arg0 + 0x1e) = 0xffff;
  *(undefined2 *)(arg0 + 0x1c) = 0xffff;
  *(undefined2 *)(arg0 + 0x1a) = 0xffff;
  return;
}


// sub_081268E4 @ 0x081268E4

void sub_081268E4(uint arg0,undefined4 *arg1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((arg0 & 0xff) < 9) {
    iVar1 = (arg0 & 0xff) * 0x28;
    if (*(char *)(iVar1 + 0x3006480U) == '\0') {
      uVar2 = arg1[1];
      uVar3 = arg1[2];
      *(undefined4 *)(iVar1 + 0x3006480U) = *arg1;
      *(undefined4 *)(&DAT_03006484 + iVar1) = uVar2;
      *(undefined4 *)(&DAT_03006488 + iVar1) = uVar3;
      uVar2 = arg1[4];
      uVar3 = arg1[5];
      *(undefined4 *)(&DAT_0300648c + iVar1) = arg1[3];
      *(undefined4 *)(&DAT_03006490 + iVar1) = uVar2;
      *(undefined4 *)(&DAT_03006494 + iVar1) = uVar3;
      uVar2 = arg1[7];
      uVar3 = arg1[8];
      *(undefined4 *)(&DAT_03006498 + iVar1) = arg1[6];
      *(undefined4 *)(&DAT_0300649c + iVar1) = uVar2;
      *(undefined4 *)(&DAT_030064a0 + iVar1) = uVar3;
      *(undefined4 *)(&DAT_030064a4 + iVar1) = arg1[9];
    }
  }
  return;
}


// sub_08126928 @ 0x08126928

void sub_08126928(uint arg0,undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined1 local_3c;
  undefined1 local_3b;
  byte local_3a;
  byte local_39;
  short local_36;
  short local_34;
  short local_32;
  undefined2 local_30;
  undefined2 local_2e;
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
  
  local_3c = 1;
  local_3b = 0;
  local_3a = (byte)arg1 >> 4;
  local_39 = (byte)arg1 & 0xf;
  local_32 = (short)arg3 * (short)arg2;
  local_30 = 0;
  local_2e = 0;
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
  local_36 = (short)arg2;
  local_34 = (short)arg3;
  sub_081268E4(arg0 & 0xff,&local_3c);
  return;
}


// sub_081269B0 @ 0x081269B0

void sub_081269B0(uint arg0)

{
  if ((arg0 & 0xff) < 9) {
    sub_08126898((arg0 & 0xff) * 0x28 + 0x3006480);
  }
  return;
}


// sub_081269D0 @ 0x081269D0

void sub_081269D0(void)

{
  uint arg0;
  
  arg0 = 0;
  do {
    sub_081269B0(arg0);
    arg0 = arg0 + 1 & 0xff;
  } while (arg0 < 8);
  return;
}


// sub_081269EC @ 0x081269EC

void sub_081269EC(void)

{
  uint arg0;
  
  arg0 = 0;
  do {
    sub_08126A08(arg0);
    arg0 = arg0 + 1 & 0xff;
  } while (arg0 < 8);
  return;
}


// sub_08126A08 @ 0x08126A08

void sub_08126A08(uint arg0)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 uVar3;
  short sVar4;
  undefined4 uVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  
  uVar1 = DAT_03003964;
  iVar7 = (arg0 & 0xff) * 0x28;
  puVar9 = (undefined1 *)(iVar7 + 0x3006480);
  switch(*puVar9) {
  case 0:
    goto switchD_08126a2a_caseD_0;
  case 2:
    if ((&DAT_03006481)[iVar7] != '\0') {
      (&DAT_03006481)[iVar7] = (&DAT_03006481)[iVar7] + -1;
      return;
    }
  case 1:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
    *puVar9 = 1;
  }
  *(ushort *)(&DAT_03006484 + iVar7) = uVar1;
  if ((DAT_030031b8 & 8) != 0) {
    *puVar9 = 5;
    sub_08126D34((uint)*(ushort *)(&DAT_030064a4 + iVar7));
    return;
  }
  if ((DAT_030031b8 & 4) != 0) {
    *puVar9 = 6;
    sub_08126D34((uint)*(ushort *)(&DAT_030064a6 + iVar7));
    return;
  }
  if ((DAT_030031b8 & 1) != 0) {
    *puVar9 = 3;
    sub_08126D34((uint)*(ushort *)(&DAT_0300649e + iVar7));
    return;
  }
  if ((DAT_030031b8 & 2) != 0) {
    *puVar9 = 4;
    sub_08126D34((uint)*(ushort *)(&DAT_030064a0 + iVar7));
    return;
  }
  if ((&DAT_03006482)[iVar7] == '\0') {
    if ((DAT_030031b8 & 0x200) != 0) {
      uVar3 = 7;
LAB_08126b02:
      *puVar9 = uVar3;
      sub_08126D34((uint)*(ushort *)(&DAT_030064a2 + iVar7));
      return;
    }
    if ((DAT_030031b8 & 0x100) != 0) {
      uVar3 = 8;
      goto LAB_08126b02;
    }
  }
  if ((uVar1 & 0x40) == 0) {
    if ((uVar1 & 0x80) == 0) {
      if ((uVar1 & 0x10) == 0) {
        if (((uVar1 & 0x20) != 0) && (*(short *)(&DAT_03006486 + iVar7) != 1)) {
          if (*(ushort *)(&DAT_03006496 + iVar7) < *(ushort *)(&DAT_03006490 + iVar7)) {
            if (((&DAT_03006483)[iVar7] | 2) != 0) {
              sVar4 = *(short *)(&DAT_03006486 + iVar7) + -1;
              goto LAB_08126c0e;
            }
          }
          else {
            sVar4 = *(ushort *)(&DAT_03006496 + iVar7) - *(ushort *)(&DAT_03006490 + iVar7);
LAB_08126c0e:
            *(short *)(&DAT_03006496 + iVar7) = sVar4;
          }
          *puVar9 = 0xd;
          sub_08126D34((uint)*(ushort *)(&DAT_0300649c + iVar7));
        }
      }
      else if (*(ushort *)(&DAT_03006486 + iVar7) != 1) {
        sVar4 = *(short *)(&DAT_03006496 + iVar7);
        *(short *)(&DAT_03006496 + iVar7) = *(short *)(&DAT_03006490 + iVar7) + sVar4;
        if ((*(ushort *)(&DAT_03006486 + iVar7) <=
             (ushort)(*(short *)(&DAT_03006490 + iVar7) + sVar4)) &&
           (((&DAT_03006483)[iVar7] | 2) != 0)) {
          *(ushort *)(&DAT_03006496 + iVar7) = uVar1 & 0x80;
        }
        *puVar9 = 0xd;
        sub_08126D34((uint)*(ushort *)(&DAT_0300649c + iVar7));
      }
    }
    else if (*(ushort *)(&DAT_03006488 + iVar7) != 1) {
      if ((uint)*(ushort *)(&DAT_03006498 + iVar7) == *(ushort *)(&DAT_03006488 + iVar7) - 1) {
        if (((&DAT_03006483)[iVar7] & 1) == 0) {
          if ((uint)*(ushort *)(&DAT_03006496 + iVar7) == *(ushort *)(&DAT_03006486 + iVar7) - 1)
          goto LAB_08126bac;
          *(ushort *)(&DAT_03006496 + iVar7) = *(ushort *)(&DAT_03006496 + iVar7) + 1;
          *(ushort *)(&DAT_03006498 + iVar7) = (byte)(&DAT_03006483)[iVar7] & 1;
        }
        else {
          *(ushort *)(&DAT_03006498 + iVar7) = uVar1 & 0x40;
        }
LAB_08126b82:
        sub_08126D34((uint)*(ushort *)(&DAT_0300649a + iVar7));
      }
      else {
        iVar8 = *(ushort *)(&DAT_03006498 + iVar7) + 1;
        *(short *)(&DAT_03006498 + iVar7) = (short)iVar8;
        if ((int)(iVar8 + (uint)*(ushort *)(&DAT_03006490 + iVar7) *
                          (uint)*(ushort *)(&DAT_03006496 + iVar7) & 0xffff) <=
            (int)(*(ushort *)(&DAT_0300648a + iVar7) - 1)) goto LAB_08126ba6;
      }
LAB_08126bac:
      *puVar9 = 0xd;
    }
  }
  else {
    sVar4 = *(short *)(&DAT_03006488 + iVar7);
    if (sVar4 != 1) {
      if (*(short *)(&DAT_03006498 + iVar7) == 0) {
        if (((&DAT_03006483)[iVar7] & 1) == 0) {
          if (*(short *)(&DAT_03006496 + iVar7) == 0) goto LAB_08126bac;
          *(short *)(&DAT_03006496 + iVar7) = *(short *)(&DAT_03006496 + iVar7) + -1;
          sVar4 = *(short *)(&DAT_03006490 + iVar7);
        }
        *(short *)(&DAT_03006498 + iVar7) = sVar4 + -1;
        goto LAB_08126b82;
      }
      *(short *)(&DAT_03006498 + iVar7) = *(short *)(&DAT_03006498 + iVar7) + -1;
LAB_08126ba6:
      sub_08126D34((uint)*(ushort *)(&DAT_0300649a + iVar7));
      goto LAB_08126bac;
    }
  }
  uVar6 = *(ushort *)(&DAT_03006490 + iVar7);
  if ((&DAT_03006482)[iVar7] == '\x01') {
    if ((uVar1 & 0x200) == 0) {
      if (((uVar1 & 0x100) != 0) && (*(short *)(&DAT_03006486 + iVar7) == 1)) {
        if ((int)(uint)(ushort)(*(short *)(&DAT_03006496 + iVar7) * uVar6 +
                               *(short *)(&DAT_03006498 + iVar7)) <
            (int)(*(ushort *)(&DAT_0300648a + iVar7) - 1)) {
          sub_08126D34((uint)*(ushort *)(&DAT_0300649a + iVar7));
        }
        uVar6 = *(ushort *)(&DAT_03006490 + iVar7);
        *(ushort *)(&DAT_0300648c + iVar7) = uVar6 + *(short *)(&DAT_0300648c + iVar7);
        *(short *)(&DAT_03006496 + iVar7) = *(short *)(&DAT_03006496 + iVar7) + 1;
        *puVar9 = 0xd;
      }
    }
    else if (*(short *)(&DAT_03006486 + iVar7) == 1) {
      if (*(ushort *)(&DAT_03006492 + iVar7) < uVar6) {
        if (((*(short *)(&DAT_03006496 + iVar7) != 0) || (*(short *)(&DAT_03006498 + iVar7) != 0))
           || (*(short *)(&DAT_0300648c + iVar7) != 0)) {
          sub_08126D34((uint)*(ushort *)(&DAT_0300649c + iVar7));
        }
        *(undefined2 *)(&DAT_03006496 + iVar7) = 0;
        *(undefined2 *)(&DAT_03006498 + iVar7) = 0;
        *(undefined2 *)(&DAT_0300648c + iVar7) = 0;
      }
      else {
        *(short *)(&DAT_03006496 + iVar7) = *(short *)(&DAT_03006496 + iVar7) + -1;
        *(ushort *)(&DAT_0300648c + iVar7) = *(short *)(&DAT_0300648c + iVar7) - uVar6;
        sub_08126D34((uint)*(ushort *)(&DAT_0300649c + iVar7));
      }
      *puVar9 = 0xd;
      uVar6 = *(ushort *)(&DAT_03006490 + iVar7);
    }
  }
  *(ushort *)(&DAT_03006492 + iVar7) =
       *(short *)(&DAT_03006496 + iVar7) * uVar6 + *(short *)(&DAT_03006498 + iVar7);
  uVar1 = *(ushort *)(&DAT_0300648a + iVar7);
  iVar8 = uVar1 - 1;
  if (iVar8 < (int)(uint)*(ushort *)(&DAT_03006492 + iVar7)) {
    *(short *)(&DAT_03006492 + iVar7) = (short)iVar8;
  }
  uVar5 = __udivsi3((uint)*(ushort *)(&DAT_03006492 + iVar7),
                    (uint)*(ushort *)(&DAT_03006490 + iVar7));
  *(short *)(&DAT_03006496 + iVar7) = (short)uVar5;
  uVar5 = __umodsi3((uint)*(ushort *)(&DAT_03006492 + iVar7),
                    (uint)*(ushort *)(&DAT_03006490 + iVar7));
  *(short *)(&DAT_03006498 + iVar7) = (short)uVar5;
  uVar6 = *(ushort *)(&DAT_03006492 + iVar7);
  uVar2 = *(ushort *)(&DAT_03006490 + iVar7);
  if (uVar6 < *(ushort *)(&DAT_0300648c + iVar7)) {
    *(ushort *)(&DAT_0300648c + iVar7) = uVar6;
  }
  else if ((int)((uint)*(ushort *)(&DAT_0300648c + iVar7) + (uint)uVar2 + -1) <
           (int)(uint)*(ushort *)(&DAT_03006492 + iVar7)) {
    *(ushort *)(&DAT_0300648c + iVar7) = (*(ushort *)(&DAT_03006492 + iVar7) + 1) - uVar2;
  }
  iVar8 = (uint)uVar1 - (uint)uVar2;
  if (iVar8 < (int)(uint)*(ushort *)(&DAT_0300648c + iVar7)) {
    *(short *)(&DAT_0300648c + iVar7) = (short)iVar8;
  }
  *(ushort *)(&DAT_0300648e + iVar7) = uVar6 - *(short *)(&DAT_0300648c + iVar7);
switchD_08126a2a_caseD_0:
  return;
}


// sub_08126D1C @ 0x08126D1C

int sub_08126D1C(uint arg0)

{
  return (arg0 & 0xff) * 0x28 + 0x3006480;
}


// sub_08126D34 @ 0x08126D34

void sub_08126D34(uint arg0)

{
  if ((arg0 & 0xffff) != 0xffff) {
    m4aSongNumStart(arg0 & 0xffff);
  }
  return;
}


// sub_08126D50 @ 0x08126D50

void sub_08126D50(uint arg0,uint arg1)

{
  int iVar1;
  
  if (arg0 * 0x1000000 - 0x1000000 >> 0x18 < 6) {
    iVar1 = (uint)*(ushort *)((arg0 & 0xff) * 2 + 0x8777d34) * 4;
    CpuFastSet(iVar1 + 0x8772534,0x30012b4,0x200);
    if ((arg1 & 1) != 0) {
      CpuFastSet(&UNK_08772d34 + iVar1,0x30012b4,0x30);
    }
    if ((arg1 & 2) != 0) {
      CpuFastSet(&UNK_08772df4 + iVar1,&DAT_03001374,0x60);
    }
    if ((arg1 & 4) != 0) {
      CpuFastSet(&UNK_08772f74 + iVar1,&DAT_030014f4,0x30);
    }
    if ((arg1 & 8) != 0) {
      CpuFastSet(&UNK_08773034 + iVar1,&DAT_030015b4,0x60);
    }
    if ((arg1 & 0x10) != 0) {
      CpuFastSet(&UNK_087731b4 + iVar1,&DAT_03001734,0x30);
    }
    sub_080ACFCC(3,0x8772514,0x3002e10,0x20);
    sub_080AABB0();
    sub_080E5668();
  }
  return;
}


// sub_08126E4C @ 0x08126E4C

void sub_08126E4C(undefined4 arg0,uint arg1)

{
  undefined2 uVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  puVar3 = (undefined2 *)0x3001ab4;
  puVar5 = (undefined2 *)0x200e294;
  puVar4 = (undefined2 *)0x8771ed4;
  CpuFastSet(0x8770ed4,&DAT_030012b4,0x200);
  if ((arg1 & 2) != 0) {
    CpuFastSet(&DAT_08771874,&DAT_03000194,0x20);
  }
  if ((arg1 & 4) != 0) {
    CpuFastSet(&DAT_08771914,&DAT_03000234,0x20);
  }
  bVar2 = 0;
  do {
    uVar1 = *puVar4;
    *puVar5 = uVar1;
    *puVar3 = uVar1;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
    puVar3 = puVar3 + 1;
    bVar2 = bVar2 + 1;
  } while (bVar2 < 0x40);
  sub_080ACFCC(3,0x8772514,0x3002e10,0x20);
  sub_080AABB0();
  DisplayList_Add(0x8126fed,1);
  return;
}


// sub_08126F14 @ 0x08126F14

void sub_08126F14(void)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)0x3001ab4;
  puVar2 = (undefined2 *)0x200e214;
  bVar1 = 0;
  do {
    *puVar2 = 0;
    *puVar3 = 0;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x40);
  DisplayList_Add(0x8127091,1);
  return;
}


// sub_08126F4C @ 0x08126F4C

void sub_08126F4C(void)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)0x3001ab4;
  puVar2 = (undefined2 *)0x200e294;
  bVar1 = 0;
  do {
    *puVar2 = 0;
    *puVar3 = 0;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0x40);
  DisplayList_Add(0x8127055,1);
  return;
}


// sub_08126F84 @ 0x08126F84

void sub_08126F84(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x30012b4;
  REG_DMA3DAD = 0x600d800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = 0x3001ab4;
  REG_DMA3DAD = 0x60010c0;
  REG_DMA3CNT = 0x84000080;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_08126FEC @ 0x08126FEC

void sub_08126FEC(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x30012b4;
  REG_DMA3DAD = 0x600d800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = 0x3001ab4;
  REG_DMA3DAD = 0x60012c0;
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


// sub_08127054 @ 0x08127054

void sub_08127054(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_8 [8];
  
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x60012c0;
  REG_DMA3CNT = 0x85000020;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_08127090 @ 0x08127090

void sub_08127090(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_8 [8];
  
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x60010c0;
  REG_DMA3CNT = 0x85000020;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_081270CC @ 0x081270CC

void sub_081270CC(uint arg0,uint arg1,undefined4 arg2,uint arg3)

{
  undefined2 *puVar1;
  byte bVar2;
  uint uVar3;
  undefined2 *in_stack_00000000;
  
  uVar3 = 0;
  if ((arg3 & 0xff) != 0) {
    do {
      puVar1 = (undefined2 *)((((arg1 & 0xff) + uVar3) * 0x20 + (arg0 & 0xff)) * 2 + 0x200dfd4);
      bVar2 = 0;
      if ((byte)arg2 != 0) {
        do {
          *puVar1 = *in_stack_00000000;
          in_stack_00000000 = in_stack_00000000 + 1;
          puVar1 = puVar1 + 1;
          bVar2 = bVar2 + 1;
        } while (bVar2 < (byte)arg2);
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < (arg3 & 0xff));
  }
  return;
}


// sub_0812712C @ 0x0812712C

void sub_0812712C(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x200dfd4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = 0x8770c54;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x840000a0;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6006000;
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


// sub_081271C0 @ 0x081271C0

void sub_081271C0(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_8 [8];
  
  REG_DMA3SAD = 0x200dfd4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x850000a0;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6006000;
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


// sub_08127258 @ 0x08127258

void sub_08127258(void)

{
  sub_081270CC(1,0,0x1c,10);
  sub_080E5668();
  return;
}


// sub_08127280 @ 0x08127280

void sub_08127280(void)

{
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  CpuFastSet(local_8,0x200dfd4,0x10000a0);
  sub_080E5668();
  return;
}


// sub_081272AC @ 0x081272AC

void sub_081272AC(void)

{
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  CpuFastSet(local_8,0x30000b4,0x1000800);
  return;
}


// sub_081272CC @ 0x081272CC

void sub_081272CC(int arg0,uint arg1)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_14;
  
  if ((arg1 & 0xff) == 4) {
    CpuFastSet(0x3001cb4,&DAT_030002b4,0x80);
    uVar2 = 0;
    do {
      uVar1 = (uint)*(ushort *)(uVar2 * 2 + arg0);
      if (uVar1 != 0) {
        Font_DrawGlyphTinted(uVar1,0x30000b4,uVar2 * 0xc0000 + 0x800000 >> 0x10,2);
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 8);
    CpuFastSet(0x30002b4,&DAT_03001cb4,0x80);
    CpuFastSet(&DAT_030006b4,0x30002b4,0x80);
    local_14 = 0;
    CpuFastSet(&local_14,&DAT_030006b4,0x1000080);
  }
  else {
    uVar2 = 0;
    do {
      uVar1 = (uint)*(ushort *)(uVar2 * 2 + arg0);
      if (uVar1 != 0) {
        Font_DrawGlyphTinted(uVar1,0x30000b4,uVar2 * 0xc,(arg1 & 0xff) * 0xd + 6);
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 8);
  }
  return;
}


// sub_08127394 @ 0x08127394

void sub_08127394(int arg0,uint arg1,undefined4 arg2)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_18;
  
  if ((arg1 & 0xff) == 4) {
    CpuFastSet(0x3001cb4,&DAT_030002b4,0x80);
    uVar2 = 0;
    do {
      uVar1 = (uint)*(ushort *)(uVar2 * 2 + arg0);
      if (uVar1 != 0) {
        Font_DrawGlyphTinted(uVar1,0x30000b4,uVar2 * 0xc0000 + 0x800000 >> 0x10,2);
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 8);
    CpuFastSet(0x30002b4,&DAT_03001cb4,0x80);
    CpuFastSet(&DAT_030006b4,0x30002b4,0x80);
    local_18 = 0;
    CpuFastSet(&local_18,&DAT_030006b4,0x1000080);
  }
  else {
    uVar2 = 0;
    do {
      uVar1 = (uint)*(ushort *)(uVar2 * 2 + arg0);
      if (uVar1 != 0) {
        Font_DrawGlyphTinted(uVar1,0x30000b4,uVar2 * 0xc,(arg1 & 0xff) * 0xd + 6);
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 8);
  }
  return;
}


// sub_0812745C @ 0x0812745C

void sub_0812745C(uint arg0,uint arg1)

{
  byte *pbVar1;
  int arg3;
  int iVar2;
  undefined4 local_24;
  
  pbVar1 = (byte *)sub_080A9CC0(arg0 & 0xffff);
  if ((arg1 & 0xff) == 4) {
    CpuFastSet(0x3001cb4,&DAT_03000ab4,0x80);
    CpuFastSet(&DAT_030002b4,&DAT_03000eb4,0x80);
    sub_080ACB78(*pbVar1 + 0x10,&DAT_030000b4,0xf7,0x14);
    sub_080ACB78(pbVar1[1] + 0x10,&DAT_030000b4,0xef,0x14);
    Font_DrawGlyphTinted(0x3e,&DAT_030000b4,0xe3,0x13);
    CpuFastSet(&DAT_03000ab4,0x3001cb4,0x80);
    CpuFastSet(&DAT_03000eb4,&DAT_030002b4,0x80);
    local_24 = 0;
    CpuFastSet(&local_24,&DAT_030006b4,0x1000080);
  }
  else {
    iVar2 = (arg1 & 0xff) * 0xd;
    arg3 = iVar2 + 8;
    sub_080ACB78(*pbVar1 + 0x10,0x30000b4,0x77,arg3);
    sub_080ACB78(pbVar1[1] + 0x10,0x30000b4,0x6f,arg3);
    Font_DrawGlyphTinted(0x3e,0x30000b4,99,iVar2 + 7);
  }
  return;
}


// sub_0812756C @ 0x0812756C

void sub_0812756C(uint arg0,uint arg1,undefined4 arg2)

{
  byte *pbVar1;
  int iVar2;
  int arg3;
  undefined4 local_24;
  
  pbVar1 = (byte *)sub_080A9CC0(arg0 & 0xffff);
  if ((arg1 & 0xff) == 4) {
    CpuFastSet(0x3001cb4,&DAT_03000ab4,0x80);
    CpuFastSet(&DAT_030002b4,&DAT_03000eb4,0x80);
    sub_080ACB78(*pbVar1 + 0x10,0x30000b4,0xf7,0x14);
    sub_080ACB78(pbVar1[1] + 0x10,0x30000b4,0xef,0x14);
    Font_DrawGlyphTinted(0x3e,0x30000b4,0xe3,0x13);
    CpuFastSet(&DAT_03000ab4,0x3001cb4,0x80);
    CpuFastSet(&DAT_03000eb4,&DAT_030002b4,0x80);
    local_24 = 0;
    CpuFastSet(&local_24,&DAT_030006b4,0x1000080);
  }
  else {
    iVar2 = (arg1 & 0xff) * 0xd;
    arg3 = iVar2 + 8;
    sub_080ACB78(*pbVar1 + 0x10,0x30000b4,0x77,arg3);
    sub_080ACB78(pbVar1[1] + 0x10,0x30000b4,0x6f,arg3);
    Font_DrawGlyphTinted(0x3e,0x30000b4,99,iVar2 + 7);
  }
  return;
}


// sub_08127678 @ 0x08127678

void sub_08127678(uint arg0,uint arg1)

{
  byte *pbVar1;
  int arg3;
  undefined4 local_24;
  
  pbVar1 = (byte *)sub_080A9CC0(arg0 & 0xffff);
  if ((arg1 & 0xff) == 4) {
    CpuFastSet(0x3001cb4,&DAT_03000ab4,0x80);
    CpuFastSet(&DAT_030002b4,&DAT_03000eb4,0x80);
    sub_080ACB78(*pbVar1 + 0x10,&DAT_030000b4,0xf7,0x14);
    if (pbVar1[1] != 0) {
      sub_080ACB78(pbVar1[1] + 0x10,&DAT_030000b4,0xef,0x14);
    }
    sub_080ACB78(0x2d,&DAT_030000b4,0xdf,0x14);
    sub_080ACB78(0x30,&DAT_030000b4,0xe7,0x14);
    CpuFastSet(&DAT_03000ab4,0x3001cb4,0x80);
    CpuFastSet(&DAT_03000eb4,&DAT_030002b4,0x80);
    local_24 = 0;
    CpuFastSet(&local_24,&DAT_030006b4,0x1000080);
  }
  else {
    arg3 = (arg1 & 0xff) * 0xd + 8;
    sub_080ACB78(*pbVar1 + 0x10,0x30000b4,0x77,arg3);
    if (pbVar1[1] != 0) {
      sub_080ACB78(pbVar1[1] + 0x10,0x30000b4,0x6f,arg3);
    }
    sub_080ACB78(0x2d,0x30000b4,0x5f,arg3);
    sub_080ACB78(0x30,0x30000b4,0x67,arg3);
  }
  return;
}


// sub_081277AC @ 0x081277AC

void sub_081277AC(uint arg0,uint arg1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_20;
  
  uVar3 = arg1 & 0xff;
  iVar4 = 0;
  pbVar1 = (byte *)sub_080A9CC0(arg0 & 0xffff);
  if (99 < (arg0 & 0xffff)) {
    iVar4 = 8;
  }
  if (uVar3 == 4) {
    CpuFastSet(0x3001cb4,&DAT_03000ab4,0x80);
    CpuFastSet(&DAT_030002b4,&DAT_03000eb4,0x80);
    sub_080ACB78(*pbVar1 + 0x10,&DAT_030000b4,0xf7,0x14);
    if ((pbVar1[2] != 0) || (pbVar1[1] != 0)) {
      sub_080ACB78(pbVar1[1] + 0x10,&DAT_030000b4,0xef,0x14);
    }
    if (pbVar1[2] != 0) {
      sub_080ACB78(pbVar1[2] + 0x10,0x30000b4,0xe7,0x14);
    }
    sub_080ACB78(0x28,0x30000b4,0xdfU - iVar4 & 0xffff,0x14);
    sub_080ACB78(0x30,0x30000b4,0xe7U - iVar4 & 0xffff,0x14);
    CpuFastSet(&DAT_03000ab4,&DAT_03001cb4,0x80);
    CpuFastSet(&DAT_03000eb4,&DAT_030002b4,0x80);
    local_20 = 0;
    CpuFastSet(&local_20,&DAT_030006b4,0x1000080);
  }
  else {
    iVar2 = uVar3 * 0xd + 8;
    sub_080ACB78(*pbVar1 + 0x10,0x30000b4,0x77,iVar2);
    if ((pbVar1[2] != 0) || (pbVar1[1] != 0)) {
      sub_080ACB78(pbVar1[1] + 0x10,0x30000b4,0x6f,iVar2);
    }
    if (pbVar1[2] != 0) {
      sub_080ACB78(pbVar1[2] + 0x10,0x30000b4,0x67,uVar3 * 0xd + 8);
    }
    iVar2 = uVar3 * 0xd + 8;
    sub_080ACB78(0x28,0x30000b4,0x5fU - iVar4 & 0xffff,iVar2);
    sub_080ACB78(0x30,0x30000b4,0x67U - iVar4 & 0xffff,iVar2);
  }
  return;
}


// sub_08127960 @ 0x08127960

void sub_08127960(uint arg0,undefined4 arg1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar4 = sub_08126D1C(arg0 & 0xff);
  *(undefined2 *)(iVar4 + 0xc) = 0;
  *(undefined2 *)(iVar4 + 0xe) = 0;
  *(undefined2 *)(iVar4 + 0x16) = 0;
  *(undefined2 *)(iVar4 + 0x18) = 0;
  *(undefined2 *)(iVar4 + 0x12) = (undefined2)arg1;
  iVar5 = *(ushort *)(iVar4 + 10) - 1;
  if (iVar5 < (int)(uint)*(ushort *)(iVar4 + 0x12)) {
    *(short *)(iVar4 + 0x12) = (short)iVar5;
  }
  uVar6 = __udivsi3((uint)*(ushort *)(iVar4 + 0x12),(uint)*(ushort *)(iVar4 + 0x10));
  *(short *)(iVar4 + 0x16) = (short)uVar6;
  uVar6 = __umodsi3((uint)*(ushort *)(iVar4 + 0x12),(uint)*(ushort *)(iVar4 + 0x10));
  *(short *)(iVar4 + 0x18) = (short)uVar6;
  uVar3 = *(ushort *)(iVar4 + 0x12);
  uVar1 = *(ushort *)(iVar4 + 0x12);
  uVar2 = *(ushort *)(iVar4 + 0x10);
  if (*(ushort *)(iVar4 + 0xc) <= uVar3) {
    if ((int)(uint)uVar1 <= (int)((uint)*(ushort *)(iVar4 + 0xc) + (uint)uVar2 + -1))
    goto LAB_081279bc;
    uVar3 = (uVar1 + 1) - uVar2;
  }
  *(ushort *)(iVar4 + 0xc) = uVar3;
LAB_081279bc:
  iVar5 = (uint)*(ushort *)(iVar4 + 10) - (uint)uVar2;
  if (iVar5 < (int)(uint)*(ushort *)(iVar4 + 0xc)) {
    *(short *)(iVar4 + 0xc) = (short)iVar5;
  }
  *(ushort *)(iVar4 + 0xe) = uVar1 - *(short *)(iVar4 + 0xc);
  return;
}


// sub_081279D4 @ 0x081279D4

void sub_081279D4(void)

{
  DAT_03000034 = 0;
  DAT_03000035 = 0;
  DAT_03000031 = 0;
  DAT_03000030 = 0;
  DAT_03000038 = 0x3f;
  DAT_03000036 = 0;
  DAT_03000037 = 0;
  DAT_03000033 = 0;
  DAT_03000032 = 0;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x3f;
  return;
}


// sub_08127A38 @ 0x08127A38

void sub_08127A38(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((((1 < (ushort)(DAT_0200e7d4 - 1U)) && (1 < (ushort)(DAT_0200e7d8 - 1U))) &&
      (1 < (ushort)(DAT_0200e7da - 1U))) &&
     (((1 < (ushort)(DAT_0200e7dc - 1U) && (1 < (ushort)(DAT_0200e7de - 1U))) &&
      (1 < (ushort)(DAT_0200e7e0 - 1U))))) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_08127A98 @ 0x08127A98

uint sub_08127A98(undefined4 arg0)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  
  puVar6 = &DAT_0203c4d0;
  uVar7 = 0;
  switch((undefined1)arg0) {
  case 0:
    uVar4 = 0;
    do {
      iVar2 = sub_080C0148((uint)(ushort)(uVar4 + 0x8000));
      if (*(short *)(iVar2 + 0xe) != 0) {
        *puVar6 = uVar4;
        puVar6 = puVar6 + 1;
        uVar7 = uVar7 + 1 & 0xffff;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
    break;
  case 1:
    uVar4 = 0;
    do {
      iVar2 = sub_080C0148((uint)(ushort)(uVar4 + 0x8000));
      if (*(short *)(iVar2 + 0xe) == -0x4000) {
        *puVar6 = uVar4;
        puVar6 = puVar6 + 1;
        uVar7 = uVar7 + 1 & 0xffff;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
    break;
  case 2:
    uVar4 = 4;
    do {
      iVar2 = sub_080C0148((uint)(ushort)(uVar4 + 0x8000));
      if (*(short *)(iVar2 + 0xe) != 0) {
        *puVar6 = uVar4;
        puVar6 = puVar6 + 1;
        uVar7 = uVar7 + 1 & 0xffff;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
    break;
  case 3:
    uVar4 = 4;
    do {
      iVar2 = sub_080C0148((uint)(ushort)(uVar4 + 0x8000));
      if (*(short *)(iVar2 + 0xe) == -0x4000) {
        *puVar6 = uVar4;
        puVar6 = puVar6 + 1;
        uVar7 = uVar7 + 1 & 0xffff;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
    break;
  case 4:
    uVar4 = 4;
    do {
      iVar2 = sub_080C0148((uint)(ushort)(uVar4 + 0x8000));
      if (*(short *)(iVar2 + 0xe) == -0x8000) {
        *puVar6 = uVar4;
        puVar6 = puVar6 + 1;
        uVar7 = uVar7 + 1 & 0xffff;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
    break;
  case 5:
    uVar4 = 0;
    do {
      *puVar6 = uVar4;
      puVar6 = puVar6 + 1;
      uVar7 = uVar7 + 1 & 0xffff;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x100);
    break;
  case 6:
    uVar4 = 0;
    do {
      iVar2 = sub_080C0148((uint)(ushort)(uVar4 + 0x8000));
      if (*(short *)(iVar2 + 0xe) == -0x4000) {
        *puVar6 = uVar4;
        puVar6 = puVar6 + 1;
        uVar7 = uVar7 + 1 & 0xffff;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 4);
    break;
  case 7:
    uVar5 = 4;
    do {
      iVar2 = sub_080C0148(uVar5 + 0x8000 & 0xffff);
      if (((*(short *)(iVar2 + 0xe) == -0x8000) && (iVar2 = sub_080C0830(), iVar2 == 0)) &&
         (iVar2 = sub_080F3EC8(uVar5), iVar2 == 0)) {
        bVar1 = false;
        uVar3 = 0;
        do {
          if ((int)(short)(&DAT_0203d0f0)[uVar3] == uVar5) {
            bVar1 = true;
          }
          uVar3 = uVar3 + 1 & 0xffff;
        } while (uVar3 < 0x10);
        if (!bVar1) {
          *puVar6 = (ushort)uVar5;
          puVar6 = puVar6 + 1;
          uVar7 = uVar7 + 1 & 0xffff;
        }
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 0x10);
    break;
  case 8:
    uVar4 = 4;
    do {
      iVar2 = sub_080C0148((uint)(ushort)(uVar4 + 0x8000));
      if ((*(short *)(iVar2 + 0xe) != 0) && (*(short *)(iVar2 + 0x10) == 0)) {
        *puVar6 = uVar4;
        puVar6 = puVar6 + 1;
        uVar7 = uVar7 + 1 & 0xffff;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
    break;
  case 9:
    uVar5 = 4;
    do {
      iVar2 = sub_080C0148(uVar5 + 0x8000 & 0xffff);
      if ((*(short *)(iVar2 + 0xe) == -0x8000) && (iVar2 = sub_080C0830(), iVar2 == 1)) {
        bVar1 = false;
        uVar3 = 0;
        do {
          if ((int)(short)(&DAT_0203d0f0)[uVar3] == uVar5) {
            bVar1 = true;
          }
          uVar3 = uVar3 + 1 & 0xffff;
        } while (uVar3 < 0x10);
        if (!bVar1) {
          *puVar6 = (ushort)uVar5;
          puVar6 = puVar6 + 1;
          uVar7 = uVar7 + 1 & 0xffff;
        }
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 0x10);
    break;
  default:
    goto switchD_08127ac2_default;
  }
  *puVar6 = 0xffff;
switchD_08127ac2_default:
  return uVar7;
}


// sub_08127D70 @ 0x08127D70

void sub_08127D70(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x200dfd4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = 0x8770c54;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x840000a0;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6006000;
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


// sub_08127E04 @ 0x08127E04

void sub_08127E04(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x200dfd4;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = 0x8772294;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x840000a0;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6006000;
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


// sub_08127E98 @ 0x08127E98

undefined4 sub_08127E98(undefined4 arg0)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x08127eaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(0x67 < (ushort)arg0);
  return uVar1;
}


// sub_08127EAC @ 0x08127EAC

void sub_08127EAC(undefined4 arg0,uint arg1)

{
  short sVar1;
  ushort uVar2;
  uint arg0_00;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int unaff_r8;
  undefined1 auStack_34 [16];
  undefined4 local_24;
  
  uVar8 = arg1 & 0xffff;
  local_24 = 0;
  CpuFastSet(&local_24,0x30000b4,0x1000800);
  switch((undefined1)arg0) {
  case 0:
    uVar7 = 0;
    sVar1 = (&DAT_0203c4d0)[uVar8];
    while (sVar1 != -1) {
      iVar3 = sub_080C0148((uint)(ushort)(sVar1 + 0x8000));
      if (*(byte *)(iVar3 + 0xc) < 4) {
        Combatant_DecodeName(iVar3,auStack_34);
        sub_081272CC(auStack_34,uVar7);
      }
      else {
        iVar3 = sub_080BF648((uint)*(ushort *)(iVar3 + 0x12));
        sub_081272CC(iVar3 + 0x22,uVar7);
      }
      DisplayList_Add(0x8127d71,1);
      uVar7 = uVar7 + 1 & 0xff;
      if (4 < uVar7) {
        return;
      }
      sVar1 = (&DAT_0203c4d0)[uVar7 + uVar8];
    }
    break;
  case 1:
    uVar7 = 0;
    uVar2 = (&DAT_0203c4d0)[uVar8];
    while (uVar2 != 0xffff) {
      if ((uVar2 & 0x8000) == 0) {
        iVar3 = sub_080BF648((uint)uVar2);
        sub_081272CC(iVar3 + 0x22,uVar7);
        DisplayList_Add(0x8127d71,1);
      }
      else {
        sub_08127394(0x8777d44,uVar7,2);
        DisplayList_Add(0x8127d71,1);
      }
      uVar7 = uVar7 + 1 & 0xff;
      if (4 < uVar7) {
        return;
      }
      uVar2 = (&DAT_0203c4d0)[uVar7 + uVar8];
    }
    break;
  case 3:
    uVar7 = 0;
    sVar1 = (&DAT_0203c4d0)[uVar8];
    while (sVar1 != -1) {
      iVar3 = sub_080C0148((uint)(ushort)(sVar1 + 0x8000));
      uVar6 = 0;
      iVar4 = sub_080C29B0((int)*(short *)(iVar3 + 0x12));
      if (iVar4 != 0) {
        uVar6 = 6;
      }
      iVar3 = sub_080BF648((uint)*(ushort *)(iVar3 + 0x12));
      sub_08127394(iVar3 + 0x22,uVar7,uVar6);
      DisplayList_Add(0x8127d71,1);
      uVar7 = uVar7 + 1 & 0xff;
      if (4 < uVar7) {
        return;
      }
      sVar1 = (&DAT_0203c4d0)[uVar7 + uVar8];
    }
    break;
  case 4:
    uVar7 = 0;
    uVar2 = (&DAT_0203c4d0)[uVar8 * 2];
    while (uVar2 != 0xffff) {
      iVar3 = Action_GetRecord((uint)uVar2);
      sub_081272CC(iVar3 + 0xc,uVar7);
      sub_0812745C((uint)(ushort)(&DAT_0203c4d0)[(uVar7 + uVar8) * 2 + 1],uVar7);
      DisplayList_Add(0x8127e05,1);
      uVar7 = uVar7 + 1 & 0xff;
      if (4 < uVar7) {
        return;
      }
      uVar2 = (&DAT_0203c4d0)[(uVar7 + uVar8) * 2];
    }
    break;
  case 5:
    uVar5 = arg1 & 0xff;
    uVar7 = 0;
    uVar2 = (&DAT_0203c4d0)[uVar5 * 2];
    while (arg0_00 = (uint)uVar2, arg0_00 != 0xffff) {
      if (arg0_00 < 0x80) {
        iVar3 = sub_080BF32C(arg0_00);
        unaff_r8 = iVar3 + 0x14;
      }
      else if (arg0_00 < 0xd0) {
        iVar3 = Equipment_GetRecord36_MidRange(arg0_00);
        unaff_r8 = iVar3 + 0x14;
      }
      else if (arg0_00 < 0xff) {
        iVar3 = Action_GetRecord(arg0_00);
        unaff_r8 = iVar3 + 0xc;
      }
      uVar6 = 0;
      if (arg0_00 == uVar8 >> 8) {
        uVar6 = 2;
      }
      sub_08127394(unaff_r8,uVar7,uVar6);
      sub_0812756C((uint)(ushort)(&DAT_0203c4d0)[(uVar7 + uVar5) * 2 + 1],uVar7,uVar6);
      DisplayList_Add(0x8127e05,1);
      uVar7 = uVar7 + 1 & 0xff;
      if (4 < uVar7) {
        return;
      }
      uVar2 = (&DAT_0203c4d0)[(uVar7 + uVar5) * 2];
    }
    break;
  case 6:
    uVar7 = 0;
    uVar2 = (&DAT_0203c4d0)[uVar8 * 2];
    while (uVar5 = (uint)uVar2, uVar5 != 0xffff) {
      if (uVar5 < 0x80) {
        iVar3 = sub_080BF32C(uVar5);
LAB_081281da:
        unaff_r8 = iVar3 + 0x14;
      }
      else {
        if (uVar5 < 0xd0) {
          iVar3 = Equipment_GetRecord36_MidRange(uVar5);
          goto LAB_081281da;
        }
        if (uVar5 < 0xff) {
          iVar3 = Action_GetRecord(uVar5);
          unaff_r8 = iVar3 + 0xc;
        }
      }
      sub_081272CC(unaff_r8,uVar7);
      sub_0812745C((uint)(ushort)(&DAT_0203c4d0)[(uVar7 + uVar8) * 2 + 1],uVar7);
      DisplayList_Add(0x8127e05,1);
      uVar7 = uVar7 + 1 & 0xff;
      if (4 < uVar7) {
        return;
      }
      uVar2 = (&DAT_0203c4d0)[(uVar7 + uVar8) * 2];
    }
    break;
  case 7:
    uVar7 = 0;
    uVar2 = (&DAT_0203c4d0)[uVar8];
    while (uVar2 != 0xffff) {
      iVar3 = sub_080BF5C0((uint)uVar2);
      sub_081272CC(iVar3 + 6,uVar7);
      sub_08127678((uint)*(byte *)(iVar3 + 3),uVar7);
      DisplayList_Add(0x8127e05,1);
      uVar7 = uVar7 + 1 & 0xff;
      if (4 < uVar7) {
        return;
      }
      uVar2 = (&DAT_0203c4d0)[uVar7 + uVar8];
    }
    break;
  case 8:
    uVar7 = 0;
    uVar2 = (&DAT_0203c4d0)[uVar8];
    while (uVar5 = (uint)uVar2, uVar5 != 0xffff) {
      iVar3 = sub_080BF5C0(uVar5);
      sub_081272CC(iVar3 + 6,uVar7);
      iVar4 = sub_08127E98(uVar5);
      if (iVar4 == 1) {
        uVar5 = __divsi3((uint)*(byte *)(iVar3 + 3) *
                         (int)(short)(&DAT_030046da)
                                     [((int)(char)(&DAT_030050e0)[DAT_0203c891] & 0xffffU) * 0x40],
                         100);
        sub_081277AC(uVar5 & 0xffff,uVar7);
      }
      else {
        sub_08127678((uint)*(byte *)(iVar3 + 3),uVar7);
      }
      DisplayList_Add(0x8127e05,1);
      uVar7 = uVar7 + 1 & 0xff;
      if (4 < uVar7) {
        return;
      }
      uVar2 = (&DAT_0203c4d0)[uVar7 + uVar8];
    }
  }
  return;
}


// sub_0812834C @ 0x0812834C

void sub_0812834C(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_8 [8];
  
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x850000a0;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_08128388 @ 0x08128388

void sub_08128388(void)

{
  DisplayList_Add(0x812834d,1);
  return;
}


// sub_0812839C @ 0x0812839C

int sub_0812839C(int arg0)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_080C0148(arg0 * 0x10000 + 0x80000000U >> 0x10);
  uVar2 = sub_080C29B0((int)*(short *)(iVar1 + 0x12));
  return ((uint)*(byte *)(iVar1 + 0xd) << 5) << (uVar2 & 0xff);
}


// sub_081283C4 @ 0x081283C4

void sub_081283C4(undefined4 arg0,uint arg1)

{
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined4 arg1_00;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack_14;
  
  uVar1 = (&DAT_0203c4d0)[arg1 & 0xffff];
  uVar5 = (uint)uVar1;
  if (uVar5 != 0xffff) {
    uVar4 = 0;
    do {
      uStack_14 = 0;
      CpuFastSet(&uStack_14,((uVar4 + 2) * 0x20 + 0x10) * 0x20 + 0x30000b4,0x1000080);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 6);
    if ((char)arg0 == '\0') {
      iVar2 = sub_080C0148(uVar5 + 0x8000 & 0xffff);
      sub_081284FC((uint)*(ushort *)(iVar2 + 0x18),(uint)*(ushort *)(iVar2 + 0x1a));
      sub_08128634((uint)*(ushort *)(iVar2 + 0x1c),(uint)*(ushort *)(iVar2 + 0x1e));
      sub_08128828((uint)*(ushort *)(iVar2 + 0x10),(uint)*(byte *)(iVar2 + 0xc));
    }
    else if ((char)arg0 == '\x01') {
      iVar2 = sub_080BF648(uVar5);
      sub_081284FC((uint)*(ushort *)(iVar2 + 2),(uint)*(ushort *)(iVar2 + 2));
      sub_08128634((uint)*(ushort *)(iVar2 + 4),(uint)*(ushort *)(iVar2 + 4));
      sub_08128828(0,4);
    }
    else if ((char)arg0 == '\x02') {
      pcVar3 = (char *)sub_080BF648(uVar5 & 0x7fff);
      if ((uVar1 & 0x8000) == 0) {
        Menu_DrawLabeledName((int)*pcVar3);
        sub_08128AAC((uint)(byte)pcVar3[1]);
      }
      else {
        Menu_DrawLabeledName(0xffffffff);
        sub_08128AAC(0xffff);
      }
    }
    else if ((char)arg0 == '\x03') {
      arg1_00 = 0;
      iVar2 = sub_080C0148(uVar5 + 0x8000 & 0xffff);
      sub_081284FC((uint)*(ushort *)(iVar2 + 0x18),(uint)*(ushort *)(iVar2 + 0x1a));
      sub_08128634((uint)*(ushort *)(iVar2 + 0x1c),(uint)*(ushort *)(iVar2 + 0x1e));
      iVar2 = sub_080C29B0((int)*(short *)(iVar2 + 0x12));
      if (iVar2 != 0) {
        arg1_00 = 6;
      }
      uVar5 = sub_0812839C(uVar5);
      sub_0812876C(uVar5 & 0xffff,arg1_00);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x081284fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081284FC @ 0x081284FC

void sub_081284FC(uint arg0,uint arg1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  
  sub_080ACB78(0x28,0x3000ab4,3,6);
  sub_080ACB78(0x30,0x3000ab4,0xb,6);
  sub_080ACB78(0xf,0x3000ab4,0x3d,6);
  pbVar3 = (byte *)sub_080A9CC0(arg0 & 0xffff);
  bVar1 = pbVar3[1];
  bVar2 = pbVar3[2];
  sub_080ACB78(*pbVar3 + 0x10,0x3000ab4,0x35,6);
  uVar4 = 0;
  if (bVar1 == 0) {
    uVar4 = -(uint)bVar2 >> 0x1f;
  }
  if ((int)-(uint)bVar1 < 0 || uVar4 != 0) {
    sub_080ACB78(bVar1 + 0x10,0x3000ab4,0x2d,6);
  }
  if (bVar2 != 0) {
    sub_080ACB78(bVar2 + 0x10,0x3000ab4,0x25,6);
  }
  pbVar3 = (byte *)sub_080A9CC0(arg1 & 0xffff);
  bVar1 = pbVar3[1];
  bVar2 = pbVar3[2];
  sub_080ACB78(*pbVar3 + 0x10,0x3000ab4,0x55,6);
  uVar4 = 0;
  if (bVar1 == 0) {
    uVar4 = -(uint)bVar2 >> 0x1f;
  }
  if ((int)-(uint)bVar1 < 0 || uVar4 != 0) {
    sub_080ACB78(bVar1 + 0x10,0x3000ab4,0x4d,6);
  }
  if (bVar2 != 0) {
    sub_080ACB78(bVar2 + 0x10,0x3000ab4,0x45,6);
  }
  return;
}


// sub_08128634 @ 0x08128634

void sub_08128634(uint arg0,uint arg1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  
  sub_080ACB78(0x2d,0x3000ab4,3,0x12);
  sub_080ACB78(0x30,0x3000ab4,0xb,0x12);
  sub_080ACB78(0xf,0x3000ab4,0x3d,0x12);
  pbVar3 = (byte *)sub_080A9CC0(arg0 & 0xffff);
  bVar1 = pbVar3[1];
  bVar2 = pbVar3[2];
  sub_080ACB78(*pbVar3 + 0x10,0x3000ab4,0x35,0x12);
  uVar4 = 0;
  if (bVar1 == 0) {
    uVar4 = -(uint)bVar2 >> 0x1f;
  }
  if ((int)-(uint)bVar1 < 0 || uVar4 != 0) {
    sub_080ACB78(bVar1 + 0x10,0x3000ab4,0x2d,0x12);
  }
  if (bVar2 != 0) {
    sub_080ACB78(bVar2 + 0x10,0x3000ab4,0x25,0x12);
  }
  pbVar3 = (byte *)sub_080A9CC0(arg1 & 0xffff);
  bVar1 = pbVar3[1];
  bVar2 = pbVar3[2];
  sub_080ACB78(*pbVar3 + 0x10,0x3000ab4,0x55,0x12);
  uVar4 = 0;
  if (bVar1 == 0) {
    uVar4 = -(uint)bVar2 >> 0x1f;
  }
  if ((int)-(uint)bVar1 < 0 || uVar4 != 0) {
    sub_080ACB78(bVar1 + 0x10,0x3000ab4,0x4d,0x12);
  }
  if (bVar2 != 0) {
    sub_080ACB78(bVar2 + 0x10,0x3000ab4,0x45,0x12);
  }
  return;
}


// sub_0812876C @ 0x0812876C

void sub_0812876C(uint arg0,uint arg1)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined1 uStack_17;
  char cStack_16;
  char cStack_15;
  
  uStack_1c = 4;
  sub_080ACB78(0x23,0x3000ab4,3,0x1e);
  uStack_1c = 4;
  sub_080ACB78(0x2f,0x3000ab4,0xb,0x1e);
  uStack_1c = 4;
  sub_080ACB78(0x33,0x3000ab4,0x13,0x1e);
  uStack_1c = 4;
  sub_080ACB78(0x34,0x3000ab4,0x1b,0x1e);
  puVar1 = (undefined1 *)sub_080A9CC0(arg0 & 0xffff);
  uStack_18 = *puVar1;
  uStack_17 = puVar1[1];
  cStack_16 = puVar1[2];
  cStack_15 = puVar1[3];
  uVar2 = 4;
  if (puVar1[3] != '\0') goto LAB_08128818;
  if (puVar1[2] == '\0') {
    uVar2 = 2;
  }
  else {
    uVar2 = 3;
  }
  do {
    uStack_1c = arg1 & 0xff;
    sub_080ACB78(*(byte *)((int)&uStack_1c + uVar2 + 3) + 0x10,0x3000ab4,
                 (0xb - uVar2) * 8 + 5 & 0xffff,0x1e);
    uVar2 = uVar2 - 1 & 0xff;
LAB_08128818:
  } while (uVar2 != 0);
  return;
}


// sub_08128828 @ 0x08128828

void sub_08128828(uint arg0,undefined4 arg1)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080ACB78(0x33,0x3000ab4,3,0x1e);
  sub_080ACB78(0x34,0x3000ab4,0xb,0x1e);
  if ((arg0 & 0x8000) == 0) {
    if ((arg0 & 0x4000) == 0) {
      if ((arg0 & 0x2000) == 0) {
        if ((arg0 & 0x1000) == 0) {
          if ((arg0 & 4) == 0) {
            if ((arg0 & 0x800) == 0) {
              if ((arg0 & 0x400) == 0) {
                if ((arg0 & 1) == 0) {
                  if ((arg0 & 0x200) == 0) {
                    if ((arg0 & 0x40) == 0) {
                      if ((arg0 & 0x20) == 0) {
                        if ((arg0 & 0x100) == 0) {
                          if ((arg0 & 0x80) == 0) {
                            if ((arg0 & 2) == 0) {
                              if ((arg0 & 0x10) == 0) {
                                pcVar2 = (char *)0x8777ddc;
                                if ((arg0 & 8) != 0) {
                                  pcVar2 = " HAPPY ";
                                }
                              }
                              else {
                                pcVar2 = (char *)0x8777db4;
                              }
                            }
                            else {
                              pcVar2 = (char *)0x8777dcc;
                            }
                          }
                          else {
                            pcVar2 = (char *)0x8777d9c;
                          }
                        }
                        else {
                          pcVar2 = (char *)0x8777d94;
                        }
                      }
                      else {
                        pcVar2 = (char *)0x8777dac;
                      }
                    }
                    else {
                      pcVar2 = (char *)0x8777da4;
                    }
                  }
                  else {
                    pcVar2 = (char *)0x8777d8c;
                  }
                }
                else {
                  pcVar2 = (char *)0x8777dd4;
                }
              }
              else {
                pcVar2 = (char *)0x8777d84;
              }
            }
            else {
              pcVar2 = (char *)0x8777d7c;
            }
          }
          else {
            pcVar2 = (char *)0x8777dc4;
          }
        }
        else {
          pcVar2 = (char *)0x8777d74;
        }
      }
      else {
        pcVar2 = (char *)0x8777d6c;
      }
    }
    else {
      pcVar2 = (char *)0x8777d64;
    }
  }
  else {
    pcVar2 = (char *)0x8777d54;
    if ((ushort)arg1 < 4) {
      pcVar2 = &UNK_08777d5c;
    }
  }
  uVar3 = 0;
  do {
    bVar1 = *pcVar2;
    if (bVar1 != 0) {
      pcVar2 = pcVar2 + 1;
      sub_080ACB78(bVar1 - 0x20 & 0xffff,0x3000ab4,(uVar3 + 5) * 8 + 5,0x1e);
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 8);
                    /* WARNING: Could not recover jumptable at 0x081289ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// Menu_DrawLabeledName @ 0x081289B8

void Menu_DrawLabeledName(undefined4 arg0)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  
  sub_080ACB78(0x32,0x3000ab4,3,6);
  sub_080ACB78(0x21,0x3000ab4,0xb,6);
  sub_080ACB78(0x23,0x3000ab4,0x13,6);
  sub_080ACB78(0x25,0x3000ab4,0x1b,6);
  if ((char)arg0 == -1) {
    uVar3 = 0;
    do {
      if (2 < uVar3) {
        Font_DrawGlyphTinted(0x3c,0x3000ab4,uVar3 * 0xc0000 + 0x230000 >> 0x10,3);
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 5);
  }
  else {
    puVar2 = *(ushort **)((char)arg0 * 4 + 0x8777de4);
    uVar3 = 0;
    uVar4 = 0;
    uVar1 = *puVar2;
    while (uVar1 != 0) {
      uVar3 = uVar3 + 1 & 0xffff;
      uVar4 = uVar4 + 1 & 0xff;
      if (4 < uVar4) break;
      uVar1 = puVar2[uVar4];
    }
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        uVar1 = *puVar2;
        puVar2 = puVar2 + 1;
        Font_DrawGlyphTinted
                  ((uint)uVar1,0x3000ab4,((uVar4 + 5) - uVar3) * 0xc0000 + 0x230000 >> 0x10,3);
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < uVar3);
    }
  }
  return;
}


// sub_08128AAC @ 0x08128AAC

void sub_08128AAC(uint arg0)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  
  sub_080ACB78(0x2c,0x3000ab4,3,0x14);
  sub_080ACB78(0x36,0x3000ab4,0xb,0x14);
  if ((arg0 & 0xffff) == 0xffff) {
    sub_080ACB78(0xd,0x3000ab4,0x55,0x14);
    sub_080ACB78(0xd,0x3000ab4,0x4d,0x14);
  }
  else {
    pbVar3 = (byte *)sub_080A9CC0(arg0 & 0xffff);
    bVar1 = pbVar3[1];
    bVar2 = pbVar3[2];
    sub_080ACB78(*pbVar3 + 0x10,0x3000ab4,0x55,0x14);
    uVar4 = 0;
    if (bVar1 == 0) {
      uVar4 = -(uint)bVar2 >> 0x1f;
    }
    if ((int)-(uint)bVar1 < 0 || uVar4 != 0) {
      sub_080ACB78(bVar1 + 0x10,0x3000ab4,0x4d,0x14);
    }
    if (bVar2 != 0) {
      sub_080ACB78(bVar2 + 0x10,0x3000ab4,0x45,0x14);
    }
  }
  return;
}


// sub_08128B84 @ 0x08128B84

void sub_08128B84(undefined4 arg0)

{
  DAT_0203c250 = 0;
  DAT_0203c24c = 0;
  switch((undefined1)arg0) {
  case 0:
    sub_080C7218();
    sub_080C7648();
    sub_080C7C60();
    sub_080EA528();
    goto LAB_08128bda;
  case 1:
    sub_080C700C();
    sub_080C7430();
    sub_080C7648();
LAB_08128bda:
    DAT_0203c240 = sub_080AD0FC(0x8777eb8,0xffff);
    DAT_0203c896 = 0;
    break;
  case 2:
    sub_080C7C60();
    sub_0812A710();
    break;
  case 3:
    DAT_0203c240 = sub_080AD0FC(0x8777eb8,0xffff);
    break;
  case 4:
    sub_08128EB4();
  }
  return;
}


// sub_08128C28 @ 0x08128C28

void sub_08128C28(int arg0)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  
  pcVar3 = (char *)sub_08126D1C(0);
  sVar2 = *(short *)(pcVar3 + 0x16);
  sub_08126A08(0);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  cVar1 = *pcVar3;
  if (cVar1 == '\x04') {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_08128E28();
  }
  else if (cVar1 == '\x03') {
    switch(*(undefined2 *)(pcVar3 + 0x16)) {
    case 0:
      sub_08128EB4();
      DAT_0203c896 = 0;
      break;
    case 1:
      sub_0812C0D0();
      break;
    case 2:
      sub_0812AD70();
      break;
    case 3:
      sub_080CE258(0,0);
      break;
    case 4:
      sub_0812CC70(0);
      break;
    case 5:
      sub_0812CE78();
      break;
    default:
      goto switchD_08128c6a_default;
    }
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_08128E80();
  }
  else if (cVar1 == '\x06') {
    if (DAT_0203c9e0 == '\x04') {
      sub_080EA528();
      sub_080EA964();
    }
    else {
      sub_080EA2AC();
      BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar3 + 0x16) * 4 + 0x8777ea0));
    }
  }
  else if ((sVar2 != *(short *)(pcVar3 + 0x16)) && (DAT_0203c9e0 == '\x04')) {
    BattleMenu_SetMode(4,*(undefined4 *)((uint)*(ushort *)(pcVar3 + 0x16) * 4 + 0x8777ea0));
  }
switchD_08128c6a_default:
  sub_080AA184(0x8000868,0,0,0);
  return;
}


// sub_08128D54 @ 0x08128D54

void sub_08128D54(void)

{
  sub_08126E4C(0,0);
  sub_08126928(0,1,6,1);
  DAT_03000030 = 0xf0;
  DAT_03000031 = 0;
  DAT_03000035 = 0x5e;
  DAT_03000034 = 0x68;
  DAT_03000038 = 0x1d;
  DAT_03000032 = 0xf0;
  DAT_03000033 = 0;
  DAT_03000037 = 0x5e;
  DAT_03000036 = 0x68;
  DAT_03000039 = 0x1f;
  DAT_0300003a = 0x3f;
  return;
}


// sub_08128DE0 @ 0x08128DE0

void sub_08128DE0(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  DAT_03000031 = DAT_03000031 + 8;
  DAT_03000030 = DAT_03000030 + -8;
  if (0x77 < DAT_03000031) {
    DAT_03000030 = -0x10;
    DAT_03000031 = 0xf0;
    DAT_03000038 = 0x1f;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080ECF70(0x67);
  }
  return;
}


// sub_08128E28 @ 0x08128E28

void sub_08128E28(void)

{
  sub_081269B0(0);
  sub_08126F4C();
  if (DAT_0203c9e0 == '\x04') {
    sub_080EA964();
  }
  sub_081279D4();
  if (DAT_03004550 == 0x1b) {
    Field_SetState(0x1e);
    DAT_0300456e = 0;
  }
  else {
    Field_SetState(1);
  }
  sub_080C7234();
  sub_080C762C();
  sub_080C7C94();
  return;
}


// sub_08128E80 @ 0x08128E80

void sub_08128E80(void)

{
  sub_08126F4C();
  if (DAT_0203c9e0 == '\x04') {
    sub_080EA964();
  }
  sub_081279D4();
  sub_080C6FF0();
  sub_080C7414();
  sub_080C762C();
  return;
}


// sub_08128EB4 @ 0x08128EB4

void sub_08128EB4(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = sub_080F3190();
  if (uVar1 == 0) {
    DAT_0203c244 = sub_080AD0FC(0x8778000,0xffff);
  }
  else {
    if (DAT_0203c9e0 == '\x04') {
      sub_080EA528();
      sub_080EA964();
    }
    DAT_0203c244 = sub_080AD0FC(0x877812c,0xffff);
    sub_080EA210();
    uVar2 = sub_080EC038(uVar1 & 0xffff);
    uVar2 = Menu_ExpandListTemplate(uVar2,0);
    BattleMenu_SetMode(3,uVar2);
    sub_080C51D4(0x68);
  }
  return;
}


// sub_08128F28 @ 0x08128F28

void sub_08128F28(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  REG_DMA3SAD = 0x30000b4;
  REG_DMA3DAD = 0x6015000;
  REG_DMA3CNT = 0x84000180;
  uVar1 = REG_DMA3CNT;
  iVar2 = REG_DMA3CNT;
  if (iVar2 < 0) {
    do {
      uVar3 = REG_DMA3CNT;
    } while ((uVar3 & 0x80000000) != 0);
  }
  return;
}


// sub_08128F60 @ 0x08128F60

void sub_08128F60(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  uint arg3;
  
  iVar4 = 0;
  sub_080C7E24(0x30000b4,0x8777f2c);
  DisplayList_Add(0x8128f29,1);
  puVar2 = &DAT_0203c4d0;
  iVar1 = sub_080C2340(3);
  if (iVar1 != 0) {
    DAT_0203c4d0 = 0;
    DAT_0203c4d2 = 1;
    DAT_0203c4d4 = 2;
    puVar2 = &DAT_0203c4d6;
    iVar4 = 3;
  }
  *puVar2 = 3;
  puVar2[1] = 4;
  puVar3 = puVar2 + 2;
  arg3 = (iVar4 + 1) * 0x1000000 + 0x1000000U >> 0x18;
  iVar1 = sub_080C2340(0xe5);
  if (iVar1 != 0) {
    *puVar3 = 5;
    puVar3 = puVar2 + 3;
    arg3 = arg3 + 1;
  }
  *puVar3 = 0xffff;
  if (arg3 == 2) {
    iVar1 = 5;
  }
  else {
    iVar1 = arg3 + 4;
  }
  DAT_0203c24c = sub_080ABC40(10,1,10,iVar1);
  sub_08126928(1,1,1,arg3);
  *(char *)(DAT_0203c244 + 0x24) = (char)arg3;
  return;
}


// sub_08129030 @ 0x08129030

void sub_08129030(int arg0,int arg1)

{
  int iVar1;
  
  iVar1 = DAT_0203c24c;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (arg1 == 1) {
    if (*(short *)(iVar1 + 0x2e) == 2) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else if ((arg1 == 0) && (*(short *)(iVar1 + 0x1e) != 0xff)) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_08129068 @ 0x08129068

void sub_08129068(int arg0)

{
  byte bVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar3 = (char *)sub_08126D1C(1);
  bVar1 = pcVar3[0x18];
  sub_08126A08(1);
  uVar2 = *(ushort *)(pcVar3 + 0x18);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_030031b8 & 1) == 0) {
      if (*pcVar3 == '\x06') {
        if (DAT_0203c9e0 == '\x04') {
          sub_080EA528();
          sub_080EA964();
        }
        else {
          sub_080EA210();
          BattleMenu_SetMode(4,*(undefined4 *)
                                ((uint)(ushort)(&DAT_0203c4d0)[*(ushort *)(pcVar3 + 0x18)] * 4 +
                                0x8777fe0));
        }
      }
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = (&DAT_0203c4d0)[*(ushort *)(pcVar3 + 0x18)];
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0xff;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  if (((int)-((uint)uVar2 ^ (uint)bVar1) < 0) && (DAT_0203c9e0 == '\x04')) {
    BattleMenu_SetMode(4,*(undefined4 *)
                          ((uint)(ushort)(&DAT_0203c4d0)[*(ushort *)(pcVar3 + 0x18)] * 4 + 0x8777fe0
                          ));
  }
  sub_080AA184(0x8000e58,0,0,0);
  uVar5 = 0;
  do {
    if ((ushort)(&DAT_0203c4d0)[uVar5] == 0xffff) break;
    iVar4 = (uint)(ushort)(&DAT_0203c4d0)[uVar5] * 0x10;
    sub_080AA1F4(iVar4 + 0x8777f60,0,0,0);
    sub_080AA1F4(iVar4 + 0x8777f68,0,0,0);
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 6);
                    /* WARNING: Could not recover jumptable at 0x081291fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08129214 @ 0x08129214

void sub_08129214(int arg0,uint arg1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(ushort *)(arg0 + 0x1c) = (ushort)(*(ushort *)(arg0 + 0x1e) == arg1);
                    /* WARNING: Could not recover jumptable at 0x08129228. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0812922C @ 0x0812922C

void sub_0812922C(void)

{
  if (DAT_0203c896 == '\0') {
    sub_08128B84(1);
  }
  else {
    if (DAT_0203c9e0 == '\x04') {
      sub_080EA964();
    }
    sub_081279D4();
    if (DAT_03004550 == 0x1b) {
      Field_SetState(0x1e);
      DAT_0300456e = 0;
    }
    else {
      Field_SetState(1);
    }
    sub_080C7234();
    sub_080C762C();
    sub_080C7C94();
  }
  sub_081269B0(1);
  return;
}


// sub_08129298 @ 0x08129298

void sub_08129298(void)

{
  sub_080EA964();
  if (DAT_0203c896 == '\0') {
    sub_08128B84(1);
  }
  else {
    sub_081279D4();
    if (DAT_03004550 == 0x1b) {
      Field_SetState(0x1e);
      DAT_0300456e = 0;
    }
    else {
      Field_SetState(1);
    }
  }
  sub_081269B0(1);
  return;
}


// sub_081292EC @ 0x081292EC

void sub_081292EC(void)

{
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  if (DAT_0203c9e0 == '\x04') {
    sub_080EA964();
  }
  sub_08128388();
  return;
}


// sub_0812931C @ 0x0812931C

void sub_0812931C(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    (&DAT_0203d0f0)[uVar1] = 0xffff;
    (&DAT_0203d110)[uVar1] = 0xffff;
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x10);
  return;
}


// sub_0812935C @ 0x0812935C

void sub_0812935C(int arg0)

{
  undefined4 uVar1;
  
  switch(*(undefined2 *)(arg0 + 0x1e)) {
  case 0:
    sub_0812931C();
    sub_081293F8(0);
    break;
  case 1:
    sub_08129D58();
    break;
  case 2:
    sub_08129FDC();
    break;
  case 3:
    if (DAT_03005180 == 0) {
      sub_080AD6E4(1);
    }
    else {
      sub_080EA210();
      uVar1 = sub_080EC038(0x5b);
      uVar1 = Menu_ExpandListTemplate(uVar1,0);
      BattleMenu_SetMode(3,uVar1);
      *(undefined2 *)(arg0 + 0x1e) = 0x100;
    }
    break;
  case 4:
    sub_0812E734();
    break;
  case 5:
    sub_0812A6F0();
  }
  sub_081269B0(1);
  return;
}


// sub_081293F8 @ 0x081293F8

void sub_081293F8(undefined4 arg0)

{
  DAT_0203c248 = sub_080AD0FC(0x8778160,0xffff);
  DAT_0203c894 = (byte)arg0;
  if ((((byte)arg0 & 1) != 1) && (((byte)arg0 & 1) == 0)) {
    sub_080EA210();
  }
  *(undefined1 *)(DAT_0203c248 + 0x24) = 0;
  return;
}


// sub_08129440 @ 0x08129440

uint sub_08129440(void)

{
  uint uVar1;
  
  if (*DAT_0203c248 == 0) {
    uVar1 = (uint)*(byte *)(DAT_0203c248 + 0x12);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// sub_08129460 @ 0x08129460

undefined4 sub_08129460(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = sub_080C0FC0();
  uVar3 = 0;
  if ((uVar1 & 0xffff) < 6) {
    uVar2 = 0;
    do {
      if ((&DAT_0203d0f0)[uVar2] != -1) {
        uVar3 = uVar3 + 1 & 0xffff;
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < 0x10);
    if ((uVar1 & 0xffff) + uVar3 < 6) {
      return 1;
    }
  }
  return 0;
}


// sub_081294B0 @ 0x081294B0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_081294B0(int arg0,int arg1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  iVar2 = sub_080C2340(0xd5);
  if ((iVar2 == 0) || (_DAT_0203bb74 != 1)) {
    if ((DAT_0203c894 & 1) == 0) {
LAB_0812952c:
      if (DAT_0203c894 == 7) {
        uVar4 = 9;
      }
      else {
        uVar4 = 7;
      }
      uVar5 = sub_08127A98(uVar4);
      uVar5 = uVar5 & 0xffff;
      if (uVar5 != 0) {
        DAT_0203c24c = sub_080ABC40(1,0,0xf,10);
        DAT_0203c250 = sub_080ABC40(0x11,0,0xc,6);
        sub_081272AC();
        if (uVar5 < 5) {
          sub_08126928(3,0,1,uVar5);
        }
        else {
          sub_08126928(3,0x10,1,uVar5);
        }
        BattleMenu_SetMode(4,0x81240a0);
        goto LAB_081295c2;
      }
      BattleMenu_SetMode(3,0x81240f0);
      uVar1 = 1;
    }
    else {
      iVar2 = sub_080F4504();
      iVar3 = sub_080F45D4();
      if ((iVar3 < iVar2) && (iVar2 = sub_080C0FC0(), iVar2 < 6)) goto LAB_0812952c;
      uVar4 = sub_080EC038(0x92);
      uVar4 = Menu_ExpandListTemplate(uVar4,0);
      BattleMenu_SetMode(3,uVar4);
      uVar1 = 2;
    }
    *(undefined2 *)(arg0 + 0x1e) = uVar1;
  }
  else {
    BattleMenu_SetMode(3,0x812410a);
    *(undefined2 *)(arg0 + 0x1e) = 1;
  }
  if (arg1 == 0) {
    *(undefined1 *)(DAT_0203c248 + 0x24) = 0xff;
  }
LAB_081295c2:
                    /* WARNING: Could not recover jumptable at 0x081295cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_081295D4 @ 0x081295D4

void sub_081295D4(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(3);
  sub_08127EAC(3,(uint)*(ushort *)(iVar1 + 0xc));
  sub_081283C4(3,(uint)*(ushort *)(iVar1 + 0x12));
  return;
}


// sub_081295F4 @ 0x081295F4

void sub_081295F4(void)

{
  sub_080D3654(1,0);
  return;
}


// sub_08129604 @ 0x08129604

void sub_08129604(int arg0,int arg1)

{
  byte bVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  code *UNRECOVERED_JUMPTABLE;
  
  pcVar3 = (char *)sub_08126D1C(3);
  bVar1 = pcVar3[0x12];
  sub_08126A08(3);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar2 = DAT_030031b8 & 2;
  if ((DAT_030031b8 & 2) == 0) {
    if (*pcVar3 == '\x03') {
      bVar8 = true;
      *(undefined2 *)(arg0 + 0x1c) = 1;
      DAT_0203c892 = (byte)(&DAT_0203c4d0)[*(ushort *)(pcVar3 + 0x12)];
      iVar4 = sub_080C0148(DAT_0203c892 + 0x8000);
      *(ushort *)(arg0 + 0x1e) = uVar2;
      if (arg1 == 0) {
        if ((DAT_0203c894 & 2) == 0) {
          uVar5 = sub_0812839C((uint)DAT_0203c892);
          uVar6 = sub_080C3100();
          if (uVar6 < uVar5) {
            *(undefined2 *)(arg0 + 0x1e) = 1;
            *(undefined1 *)(DAT_0203c248 + 0x24) = 0xff;
            bVar8 = false;
          }
        }
        if (((DAT_0203c894 & 2) == 0) && (iVar7 = sub_080C07B0(0,(uint)DAT_0203c892), iVar7 == 0)) {
          *(undefined2 *)(arg0 + 0x1e) = 2;
          *(undefined1 *)(DAT_0203c248 + 0x24) = 0xff;
          bVar8 = false;
        }
      }
      if (((ushort)(*(short *)(iVar4 + 0x12) - 0x16aU) < 0x12) &&
         (uVar5 = sub_080C5CC0(), 1 < uVar5)) {
        *(undefined2 *)(arg0 + 0x1e) = 5;
        if (arg1 == 0) {
          *(undefined1 *)(DAT_0203c248 + 0x24) = 0xff;
        }
        bVar8 = false;
      }
      if (bVar8) {
        iVar4 = sub_080F4504();
        iVar7 = sub_080F45D4();
        if ((iVar7 < iVar4) && (iVar4 = sub_080C0FC0(), iVar4 < 6)) {
          if ((((DAT_0203c894 & 1) != 0) && (iVar4 = sub_08129460(), iVar4 == 0)) &&
             (*(undefined2 *)(arg0 + 0x1e) = 4, arg1 == 0)) {
            *(undefined1 *)(DAT_0203c248 + 0x24) = 0xff;
          }
        }
        else {
          *(undefined2 *)(arg0 + 0x1e) = 3;
        }
      }
      sub_080D3688();
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    if (arg1 == 0) {
      *(undefined1 *)(DAT_0203c248 + 0x24) = 0xff;
    }
    sub_080D3688();
  }
  sub_080AA184(0x8000ea4,0,0,1);
  if (5 < *(ushort *)(pcVar3 + 10)) {
    if (*(short *)(pcVar3 + 0xc) != 0) {
      sub_080AA184(0x8000ff0,0,0,1);
    }
    if (*(ushort *)(pcVar3 + 0xc) + 5 != (uint)*(ushort *)(pcVar3 + 10)) {
      sub_080AA184(0x8001000,0,0,1);
    }
  }
  if ((ushort)bVar1 != *(ushort *)(pcVar3 + 0x12)) {
    sub_08127EAC(3,(uint)*(ushort *)(pcVar3 + 0xc));
    sub_081283C4(3,(uint)*(ushort *)(pcVar3 + 0x12));
  }
                    /* WARNING: Could not recover jumptable at 0x08129826. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08129838 @ 0x08129838

void sub_08129838(int arg0)

{
  int iVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  iVar1 = sub_080EA934();
  if (iVar1 == 1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_08129850 @ 0x08129850

void sub_08129850(void)

{
  if ((DAT_0203c894 < 4) && (DAT_0203c894 == 0)) {
    sub_08128EB4();
    sub_080EA964();
  }
  sub_081269B0(3);
  return;
}


// sub_08129880 @ 0x08129880

void sub_08129880(void)

{
  if (DAT_0203c24c != 0) {
    sub_080ABD30(DAT_0203c24c,0);
  }
  if (DAT_0203c250 != 0) {
    sub_080ABD30(DAT_0203c250,0);
  }
  sub_08128388();
  return;
}


// sub_081298AC @ 0x081298AC

void sub_081298AC(void)

{
  DAT_0203c24c = sub_080C8AAC(0,1);
  sub_080C8ADC(DAT_0203c24c,1);
  BattleMenu_SetMode(4,0x81240bc);
  sub_081269B0(3);
  return;
}


// sub_081298DC @ 0x081298DC

void sub_081298DC(int arg0)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if ((DAT_030031b8 & 3) == 0) {
      if ((DAT_030031b8 & 0xf0) != 0) {
        sub_080ECF70(100);
      }
      goto LAB_0812998c;
    }
    bVar1 = false;
    uVar2 = sub_080C8AF4(DAT_0203c24c);
    *(short *)(arg0 + 0x1e) = (short)uVar2;
    if ((&DAT_030050e0)[*(ushort *)(arg0 + 0x1e)] == -1) {
      if (((DAT_0203c894 & 1) != 0) && (iVar3 = sub_08129460(), iVar3 == 0)) {
        bVar1 = true;
      }
      if (!bVar1) {
        *(undefined2 *)(arg0 + 0x1c) = 1;
        sub_080C8ADC(DAT_0203c24c,0);
        sub_080ECF70(0x65);
        goto LAB_0812998c;
      }
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080C8ADC(DAT_0203c24c,0);
  }
  sub_080ECF70(0x66);
LAB_0812998c:
                    /* WARNING: Could not recover jumptable at 0x08129990. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_08129994 @ 0x08129994

void sub_08129994(int arg0)

{
  uint uVar1;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_0203c894 == '\0') && (uVar1 = sub_08127A98(7), (uVar1 & 0xffff) != 0)) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_081299C8 @ 0x081299C8

void sub_081299C8(int arg0,int arg1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = (uint)(char)(&DAT_030050e0)[*(ushort *)(arg0 + 0x1e)];
  switch(DAT_0203c894) {
  case 0:
    if (uVar4 != 0xffffffff) {
      sub_080C0290(uVar4 & 0xffff,0);
    }
    uVar4 = (uint)DAT_0203c892;
    iVar2 = sub_0812839C(uVar4);
    sub_080C30AC(-iVar2);
    uVar3 = sub_080EC038(0xe9);
    uVar3 = Menu_ExpandListTemplate(uVar3,uVar4);
    BattleMenu_SetMode(3,uVar3);
    sub_080C0248(uVar4,(uint)*(ushort *)(arg0 + 0x1e));
    sub_080C366C();
    Party_BuildMemberNameTiles();
    sub_080C6FD8();
    uVar1 = 1;
    break;
  case 1:
  case 3:
  case 7:
    (&DAT_0203d0f0)[(char)(&DAT_030050e0)[DAT_0203d166]] = (ushort)DAT_0203c892;
    (&DAT_0203d110)[(char)(&DAT_030050e0)[DAT_0203d166]] = *(undefined2 *)(arg0 + 0x1e);
    *(undefined2 *)(arg0 + 0x1e) = 0;
    goto LAB_08129b1c;
  case 2:
    if (uVar4 != 0xffffffff) {
      sub_080C0290(uVar4 & 0xffff,0);
    }
    uVar4 = (uint)DAT_0203c892;
    uVar3 = sub_080EC038(0xe9);
    uVar3 = Menu_ExpandListTemplate(uVar3,uVar4);
    BattleMenu_SetMode(3,uVar3);
    sub_080C0248(uVar4,(uint)*(ushort *)(arg0 + 0x1e));
    sub_080C366C();
    Party_BuildMemberNameTiles();
    sub_080C6FD8();
    uVar1 = 1;
    break;
  default:
    uVar1 = 0;
  }
  *(undefined2 *)(arg0 + 0x1e) = uVar1;
LAB_08129b1c:
  if (arg1 == 0) {
    *(undefined1 *)(DAT_0203c248 + 0x24) = 1;
  }
  return;
}


// sub_08129B34 @ 0x08129B34

void sub_08129B34(void)

{
  undefined4 in_r1;
  
  BattleMenu_SetMode(3,in_r1);
  return;
}


// sub_08129B40 @ 0x08129B40

void sub_08129B40(undefined4 arg0,undefined4 arg1)

{
  undefined4 arg1_00;
  
  arg1_00 = Menu_ExpandListTemplate(arg1,0);
  BattleMenu_SetMode(3,arg1_00);
  return;
}


// sub_08129B58 @ 0x08129B58

void sub_08129B58(undefined4 arg0,uint arg1)

{
  undefined4 uVar1;
  
  uVar1 = sub_080EC038(arg1 & 0xffff);
  uVar1 = Menu_ExpandListTemplate(uVar1,0);
  BattleMenu_SetMode(3,uVar1);
  return;
}


// sub_08129B74 @ 0x08129B74

void sub_08129B74(int arg0,int arg1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = sub_08127A98(3);
  if ((uVar1 & 0xffff) == 0) {
    BattleMenu_SetMode(3,0x81240f0);
    *(undefined2 *)(arg0 + 0x1e) = 1;
    if (arg1 == 0) {
      *(undefined1 *)(DAT_0203c248 + 0x24) = 0xff;
    }
  }
  else {
    DAT_0203c24c = sub_080ABC40(1,0,0xf,10);
    DAT_0203c250 = sub_080ABC40(0x11,0,0xc,6);
    sub_081272AC();
    sub_08126928(4,0,1,uVar1 & 0xffff);
    uVar2 = sub_080EC038(0x6a);
    uVar2 = Menu_ExpandListTemplate(uVar2,0);
    BattleMenu_SetMode(4,uVar2);
  }
  return;
}


// sub_08129C00 @ 0x08129C00

void sub_08129C00(void)

{
  int iVar1;
  
  iVar1 = sub_08126D1C(4);
  sub_08127EAC(3,(uint)*(ushort *)(iVar1 + 0xc));
  sub_081283C4(3,(uint)*(ushort *)(iVar1 + 0x12));
  return;
}


// sub_08129C20 @ 0x08129C20

void sub_08129C20(int arg0)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  
  pcVar3 = (char *)sub_08126D1C(4);
  bVar1 = pcVar3[0x12];
  sub_08126A08(4);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 2) == 0) {
    if (*pcVar3 == '\x03') {
      uVar4 = 0;
      cVar2 = DAT_030050e0;
      while (((int)cVar2 != (uint)(ushort)(&DAT_0203c4d0)[*(ushort *)(pcVar3 + 0x12)] &&
             (uVar4 = uVar4 + 1 & 0xff, uVar4 < 6))) {
        cVar2 = (&DAT_030050e0)[uVar4];
      }
      *(short *)(arg0 + 0x1e) = (short)uVar4;
      *(undefined2 *)(arg0 + 0x1c) = 1;
      sub_080ECF70(0x65);
      sub_081269B0(4);
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 0x100;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080ECF70(0x66);
    sub_081269B0(4);
  }
  sub_080AA184(0x8000ea4,0,0,1);
  if ((ushort)bVar1 != *(ushort *)(pcVar3 + 0x12)) {
    sub_08127EAC(3,(uint)*(ushort *)(pcVar3 + 0xc));
    sub_081283C4(3,(uint)*(ushort *)(pcVar3 + 0x12));
  }
  return;
}


