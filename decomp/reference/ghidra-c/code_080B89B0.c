/* Ghidra decompilation of asm/code_080B89B0.s (reference only; not compiled). */

// sub_080B89B0 @ 0x080B89B0

void sub_080B89B0(int arg0,int arg1)

{
  undefined4 uVar1;
  int iVar2;
  dword arg1_00;
  undefined *arg2;
  undefined2 local_14 [2];
  
  if (arg1 == 0) {
    sub_080ACFA4(3,(uint)*(ushort *)(arg0 + 0x24),0x3002f70,0x40);
    sub_080ACFA4(3,(uint)*(ushort *)(arg0 + 0x24),&DAT_03002f50,0x20);
    goto LAB_080b8ab0;
  }
  if (arg1 == 1) {
    iVar2 = sub_080B3078(0,0,6);
    if (iVar2 == 0) {
      sub_080ACFCC(3,DAT_03004630,0x3002f70,0x40);
      arg2 = &DAT_03002f50;
      arg1_00 = DAT_03004510;
    }
    else {
      sub_080ACFCC(3,0x200f814,0x3002f70,0x40);
      arg1_00 = 0x200f7f4;
      arg2 = &DAT_03002f50;
    }
  }
  else {
    if (arg1 == 2) {
      local_14[0] = *(undefined2 *)(arg0 + 0x24);
      REG_DMA3SAD = local_14;
      REG_DMA3DAD = 0x3002eb0;
      REG_DMA3CNT = 0x81000080;
      uVar1 = REG_DMA3CNT;
      goto LAB_080b8ab0;
    }
    arg1_00 = sub_080C5F60((uint)DAT_03004534);
    if (DAT_03004534 != 0xda) {
      sub_080ACFCC(3,arg1_00,0x3002eb0,0x100);
      goto LAB_080b8ab0;
    }
    arg2 = (undefined *)0x3002e90;
  }
  sub_080ACFCC(3,arg1_00,arg2,0x20);
LAB_080b8ab0:
  sub_080AABB0();
  return;
}


// sub_080B8AC0 @ 0x080B8AC0

void sub_080B8AC0(int arg0)

{
  short sVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  sVar1 = *(short *)(arg0 + 0x26) + -1;
  *(short *)(arg0 + 0x26) = sVar1;
  *(ushort *)(arg0 + 0x1c) = (ushort)(sVar1 == 0);
                    /* WARNING: Could not recover jumptable at 0x080b8ade. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8AE0 @ 0x080B8AE0

int sub_080B8AE0(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x8164edc,0xffff);
  *(undefined2 *)(iVar1 + 0x24) = (undefined2)arg0;
  *(undefined2 *)(iVar1 + 0x26) = (undefined2)arg1;
  return iVar1;
}


// sub_080B8B08 @ 0x080B8B08

uint sub_080B8B08(short *arg0)

{
  return (uint)(*arg0 == 0);
}


// sub_080B8B1C @ 0x080B8B1C

void sub_080B8B1C(undefined4 arg0,int arg1)

{
  undefined4 arg1_00;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    arg1_00 = 0x3e0;
  }
  else {
    if (arg1 != 1) {
      sub_080ACFCC(3,0x81bb7b0,0x3003110,0x20);
      goto LAB_080b8b5a;
    }
    arg1_00 = 0x1f;
  }
  sub_080ACFA4(3,arg1_00,0x3003110,0x20);
LAB_080b8b5a:
  sub_080AABB0();
                    /* WARNING: Could not recover jumptable at 0x080b8b62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8B68 @ 0x080B8B68

void sub_080B8B68(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x8164f78,0xffff);
  *(undefined2 *)(iVar1 + 0x24) = (undefined2)arg0;
  *(undefined2 *)(iVar1 + 0x26) = (undefined2)arg1;
  return;
}


// sub_080B8B90 @ 0x080B8B90

void sub_080B8B90(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(ushort *)(arg0 + 0x1c) = (ushort)(*(short *)(arg0 + 0x28) == 0);
                    /* WARNING: Could not recover jumptable at 0x080b8ba4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8BA8 @ 0x080B8BA8

void sub_080B8BA8(int arg0)

{
  dword in_r2;
  
  switch(*(undefined2 *)(*(int *)(arg0 + 0x24) + 2)) {
  case 0:
  case 3:
  case 4:
    in_r2 = 0x7c1f;
    break;
  case 1:
    in_r2 = 0x7c00;
    break;
  case 2:
    in_r2 = 0x1f;
  }
  sub_080B8874(arg0,0,in_r2,1);
  return;
}


// sub_080B8BF8 @ 0x080B8BF8

void sub_080B8BF8(int arg0)

{
  *(undefined2 *)(arg0 + 0x1e) = *(undefined2 *)(*(int *)(arg0 + 0x24) + 2);
  return;
}


// sub_080B8C00 @ 0x080B8C00

void sub_080B8C00(int arg0)

{
  undefined2 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = (undefined2 *)(arg0 + 0x2c);
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 6);
  return;
}


// sub_080B8C18 @ 0x080B8C18

uint sub_080B8C18(undefined4 arg0)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  uint arg0_00;
  ushort uVar4;
  uint uVar5;
  
  uVar4 = 0x7fff;
  uVar5 = 0;
  arg0_00 = 0;
  do {
    iVar1 = sub_080C0148(arg0_00);
    if ((iVar1 != 0) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
      if ((short)arg0 == 0) {
        pcVar3 = (char *)(iVar1 + 0x44);
      }
      else {
        pcVar3 = (char *)(iVar1 + 0x40);
      }
      if ((ushort)(short)*pcVar3 <= uVar4) {
        uVar5 = (uint)*(byte *)(iVar1 + 0xc);
        uVar4 = (short)*pcVar3;
      }
    }
    arg0_00 = arg0_00 + 1 & 0xffff;
  } while (arg0_00 < 6);
  return uVar5;
}


// sub_080B8C7C @ 0x080B8C7C

void sub_080B8C7C(int arg0,uint arg1,int arg2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080C0148(arg1 & 0xffff);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (iVar2 == 0) goto LAB_080b8e7a;
  uVar5 = (uint)*(byte *)(iVar2 + 0xc);
  sVar1 = *(short *)(*(int *)(arg0 + 0x24) + 2);
  if (sVar1 == 0) {
    iVar2 = sub_080C09B0(uVar5);
    if (((((iVar2 != 1) || (iVar2 = sub_080C0830(), iVar2 != 0)) || (arg2 != 0)) ||
        ((uVar3 = sub_080B8C18(0), (uVar3 & 0xffff) != uVar5 ||
         (uVar3 = sub_080C0818(uVar5), (uVar3 & 4) != 0)))) ||
       (uVar3 = sub_080C2244(), (uVar3 & 1) == 0)) goto LAB_080b8e7a;
    sub_080C08F8(uVar5,4);
    sub_080C8490(arg1);
    iVar2 = 1;
  }
  else {
    if (1 < (ushort)(sVar1 - 1U)) {
      if (sVar1 == 3) {
        iVar2 = sub_080C09B0(uVar5);
        if ((iVar2 == 1) && (iVar2 = sub_080C0830(), iVar2 == 0)) {
          if (arg2 == 0) {
            *(undefined2 *)(arg0 + 0x2c + arg1 * 2) = 1;
          }
          else {
            iVar2 = sub_080F4038(uVar5);
            iVar2 = iVar2 * 0xc >> 7;
            if (iVar2 == 0) {
              iVar2 = 1;
            }
            sub_080C0C70(uVar5,iVar2);
            *(short *)(arg0 + 0x2c + arg1 * 2) = (short)iVar2;
            *(undefined2 *)(arg0 + 0x1c) = 1;
            sub_080C8490(arg1);
          }
        }
      }
      else if ((((sVar1 == 4) && (iVar2 = sub_080C09B0(uVar5), iVar2 == 1)) &&
               (iVar2 = sub_080C0830(), iVar2 == 0)) && (arg2 == 0)) {
        uVar3 = sub_080B8C18(1);
        uVar3 = uVar3 & 0xffff;
        if (((uVar3 == uVar5) && (uVar5 = sub_080C0818(uVar3), (uVar5 & 0x1000) == 0)) &&
           (uVar5 = sub_080C2244(), (uVar5 & 1) != 0)) {
          sub_080C08F8(uVar3,0x1000);
          sub_080C8490(arg1);
          *(undefined2 *)(arg0 + 0x2c + arg1 * 2) = 1;
        }
      }
      goto LAB_080b8e7a;
    }
    iVar2 = 0;
    if (sVar1 == 1) {
      iVar2 = 2;
    }
    iVar4 = sub_080C09B0(uVar5);
    if ((iVar4 != 1) || (iVar4 = sub_080C0830(), iVar4 != 0)) goto LAB_080b8e7a;
    if (arg2 != 0) {
      uVar3 = (uint)*(ushort *)(arg0 + 0x2c + arg1 * 2);
      if (uVar3 != 0) {
        iVar2 = sub_080F401C(uVar5);
        if (iVar2 == 1) {
          sub_080C0C70(uVar5,uVar3);
        }
        else {
          sub_080C0C70(uVar5,uVar3);
        }
        sub_080C8490(arg1);
        sub_080C86F4(arg1 & 0xffff);
        *(undefined2 *)(arg0 + 0x1c) = 1;
      }
      goto LAB_080b8e7a;
    }
    iVar4 = sub_080C06BC(uVar5);
    if (iVar4 == iVar2) goto LAB_080b8e7a;
    iVar2 = sub_080F4038(uVar5);
    iVar2 = iVar2 * 0x26 >> 7;
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    iVar4 = sub_080F401C(uVar5);
    if (iVar4 < iVar2) {
      iVar2 = sub_080F401C(uVar5);
    }
  }
  *(short *)(arg0 + 0x2c + arg1 * 2) = (short)iVar2;
LAB_080b8e7a:
                    /* WARNING: Could not recover jumptable at 0x080b8e84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8E88 @ 0x080B8E88

void sub_080B8E88(int arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  uVar1 = 0;
  do {
    if (*(short *)(arg0 + 0x2c + uVar1 * 2) != 0) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      break;
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 6);
                    /* WARNING: Could not recover jumptable at 0x080b8eb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8EB8 @ 0x080B8EB8

void sub_080B8EB8(int arg0,uint arg1)

{
  byte bVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080C0148(arg1 & 0xffff);
  sub_080B8490(0x80034ea);
  sub_080B832C();
  bVar1 = *(byte *)(iVar2 + 0xc);
  if (bVar1 == 1) {
    DAT_0203a454 = 0x31d;
    goto LAB_080b8f36;
  }
  if (bVar1 < 2) {
    if (bVar1 == 0) {
      DAT_0203a454 = 0x31a;
      goto LAB_080b8f36;
    }
  }
  else {
    if (bVar1 == 2) {
      DAT_0203a454 = 0x31b;
      goto LAB_080b8f36;
    }
    if (bVar1 == 3) {
      DAT_0203a454 = 0x31c;
      goto LAB_080b8f36;
    }
  }
  DAT_0203a454 = 0x31e;
  DAT_0203db28 = *(undefined2 *)(iVar2 + 0x12);
LAB_080b8f36:
  DAT_0203db2c = (uint)*(ushort *)(arg0 + 0x2c + arg1 * 2);
                    /* WARNING: Could not recover jumptable at 0x080b8f4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8F5C @ 0x080B8F5C

void sub_080B8F5C(int arg0,uint arg1)

{
  byte bVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080C0148(arg1 & 0xffff);
  bVar1 = *(byte *)(iVar2 + 0xc);
  if (bVar1 != 1) {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
LAB_080b8fb4:
        sub_080B832C();
        DAT_0203db28 = *(undefined2 *)(iVar2 + 0x12);
        goto LAB_080b8fc2;
      }
    }
    else if ((bVar1 != 2) && (bVar1 != 3)) goto LAB_080b8fb4;
  }
  sub_080B832C();
LAB_080b8fc2:
  DAT_0203db2c = (uint)*(ushort *)(arg0 + 0x2c + arg1 * 2);
                    /* WARNING: Could not recover jumptable at 0x080b8fd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B8FE4 @ 0x080B8FE4

void sub_080B8FE4(void)

{
  Field_SetState(1);
  return;
}


// sub_080B8FF0 @ 0x080B8FF0

void sub_080B8FF0(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x8164fd0,0xffff);
  *(undefined4 *)(iVar1 + 0x24) = arg0;
  *(undefined2 *)(iVar1 + 0x28) = (undefined2)arg1;
  return;
}


// sub_080B9014 @ 0x080B9014

void sub_080B9014(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x816514c,0xffff);
  *(undefined4 *)(iVar1 + 0x24) = arg0;
  *(undefined2 *)(iVar1 + 0x28) = (undefined2)arg1;
  return;
}


// sub_080B9038 @ 0x080B9038

void sub_080B9038(int arg0)

{
  undefined4 uVar1;
  
  DAT_0200e808 = 1;
  uVar1 = sub_080AAF48(4);
  *(undefined4 *)(arg0 + 0x28) = uVar1;
  return;
}


// sub_080B9058 @ 0x080B9058

void sub_080B9058(void)

{
  sub_080AD0FC(0x81651b4,0xffff);
  return;
}


// sub_080B9070 @ 0x080B9070

void sub_080B9070(void)

{
  sub_080AF060(0x807cf14);
  return;
}


// sub_080B9080 @ 0x080B9080

void sub_080B9080(void)

{
  sub_080AD0FC(0x81651e8,0xffff);
  return;
}


// sub_080B9098 @ 0x080B9098

void sub_080B9098(int arg0,undefined4 arg1)

{
  if ((DAT_030045ac & (ushort)arg1) == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  else {
    DAT_030045ac = DAT_030045ac & ~(ushort)arg1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080B90C0 @ 0x080B90C0

void sub_080B90C0(void)

{
  undefined4 in_r1;
  
  sub_080AF1E8(0x1a,in_r1);
  return;
}


// sub_080B90CC @ 0x080B90CC

void sub_080B90CC(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_03004550 == 0x1a);
  return;
}


// sub_080B90E8 @ 0x080B90E8

void sub_080B90E8(void)

{
  Field_SetState(1);
  return;
}


// sub_080B90F4 @ 0x080B90F4

void sub_080B90F4(void)

{
  sub_080AD0FC(0x816522c,0xffff);
  return;
}


// sub_080B910C @ 0x080B910C

void sub_080B910C(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080AB7D4(2,0xb,0x1a,2);
  *(undefined4 *)(arg0 + 0x2c) = uVar1;
  return;
}


// sub_080B9130 @ 0x080B9130

void sub_080B9130(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if ((*(uint *)(arg0 + 0x24) & 1 << (*(uint *)(arg0 + 0x28) & 0xff)) == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080b914c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B9150 @ 0x080B9150

void sub_080B9150(int arg0)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  uint arg3;
  ushort auStack_34 [16];
  
  iVar2 = sub_080C0148(*(int *)(arg0 + 0x28) + 0x8000U & 0xffff);
  arg3 = 0x12;
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if ((DAT_030031b8 & 1) != 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  if (*(byte *)(iVar2 + 0xc) < 4) {
    Combatant_DecodeName(iVar2,auStack_34);
    if (auStack_34[0] != 0) {
      puVar3 = auStack_34;
      do {
        FontSprite_DrawGlyph((uint)*puVar3,0,0,arg3);
        arg3 = arg3 + 0xc & 0xffff;
        puVar3 = puVar3 + 1;
        if (auStack_34 + 7 < puVar3) break;
      } while (*puVar3 != 0);
    }
  }
  else {
    iVar2 = sub_080BF648((uint)*(ushort *)(iVar2 + 0x12));
    uVar4 = 0;
    puVar3 = (ushort *)(iVar2 + 0x22);
    uVar1 = *(ushort *)(iVar2 + 0x22);
    while (uVar1 != 0) {
      FontSprite_DrawGlyph((uint)*puVar3,0,0,arg3);
      arg3 = arg3 + 0xc & 0xffff;
      puVar3 = puVar3 + 1;
      uVar4 = uVar4 + 1;
      if (7 < uVar4) break;
      uVar1 = *puVar3;
    }
  }
  Text_DrawSpriteString(0x81652d8,0,0,arg3);
  return;
}


// sub_080B921C @ 0x080B921C

void sub_080B921C(int arg0)

{
  *(int *)(arg0 + 0x28) = *(int *)(arg0 + 0x28) + 1;
  return;
}


// sub_080B9228 @ 0x080B9228

void sub_080B9228(int arg0)

{
  sub_080AB91C(*(undefined4 *)(arg0 + 0x2c),0);
  return;
}


// sub_080B9238 @ 0x080B9238

void sub_080B9238(void)

{
  Field_SetState(1);
  return;
}


// sub_080B9244 @ 0x080B9244

void sub_080B9244(int arg0)

{
  undefined2 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = sub_080C5108();
  if (iVar2 == 0) {
    iVar2 = sub_080C2340(1);
    if (iVar2 == 0) {
      sub_080B9058();
    }
    else {
      sub_080B9080();
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
                    /* WARNING: Could not recover jumptable at 0x080b9270. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B9274 @ 0x080B9274

void sub_080B9274(undefined4 arg0)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x81652e4,0xffff);
  *(undefined4 *)(iVar1 + 0x24) = arg0;
  return;
}


// sub_080B9290 @ 0x080B9290

void sub_080B9290(void)

{
  uint uVar1;
  
  uVar1 = sub_080B1A1C((uint)DAT_03004552);
  sub_080B02A0(uVar1 & 0xffff);
  return;
}


// sub_080B92AC @ 0x080B92AC

void sub_080B92AC(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B80F8();
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  return;
}


// sub_080B92BC @ 0x080B92BC

void sub_080B92BC(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080B8160(*(undefined4 *)(arg0 + 0x24));
  *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 == 1);
  return;
}


// sub_080B92D4 @ 0x080B92D4

void sub_080B92D4(void)

{
  int iVar1;
  int iVar2;
  dword arg0;
  
  iVar1 = sub_080B0248(0,0,0);
  iVar2 = sub_080B2938();
  if (iVar1 == 2) {
    DisplayList_Add(0x80ae1c5,1);
    if (iVar2 == 2) {
      arg0 = 0x80b34e9;
    }
    else {
      if (iVar2 != 3) {
        DAT_0300457e = 0x21;
        return;
      }
      arg0 = 0x80b350d;
    }
    DisplayList_Add(arg0,1);
  }
  else {
    DisplayList_Add(0x80ae1fd,1);
  }
  DAT_0300457e = 0x21;
  return;
}


// sub_080B9334 @ 0x080B9334

void sub_080B9334(void)

{
  sub_080B2AB0();
  return;
}


// sub_080B9340 @ 0x080B9340

void sub_080B9340(int arg0)

{
  sub_080B343C(0xfffffffe);
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_0300457e == 0);
  return;
}


// sub_080B9368 @ 0x080B9368

void sub_080B9368(void)

{
  DAT_03000038 = 0x3f;
  DAT_03000039 = 0x3f;
  DAT_0300003a = 0x3f;
  Field_SetState(1);
  return;
}


// sub_080B9390 @ 0x080B9390

void sub_080B9390(void)

{
  undefined4 uVar1;
  undefined1 local_c [4];
  
  REG_DMA3SAD = local_c;
  REG_DMA3DAD = 0x6003800;
  REG_DMA3CNT = 0x85000200;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = local_c;
  REG_DMA3DAD = 0x6008800;
  REG_DMA3CNT = 0x85000d00;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2005404;
  REG_DMA3DAD = 0x6008800;
  REG_DMA3CNT = 0x84000c00;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B93F8 @ 0x080B93F8

void sub_080B93F8(void)

{
  DisplayList_Add(0x80b9391,1);
  DAT_0300000e = 8;
  return;
}


// sub_080B9414 @ 0x080B9414

void sub_080B9414(void)

{
  undefined4 uVar1;
  undefined1 local_c [4];
  
  REG_DMA3SAD = local_c;
  REG_DMA3DAD = 0x6003800;
  REG_DMA3CNT = 0x85000200;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = local_c;
  REG_DMA3DAD = 0x6008800;
  REG_DMA3CNT = 0x85000d00;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2005004;
  REG_DMA3DAD = 0x6008c00;
  REG_DMA3CNT = 0x84000c00;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B947C @ 0x080B947C

void sub_080B947C(void)

{
  DisplayList_Add(0x80b9415,1);
  DAT_0300000e = 0xfff8;
  return;
}


// sub_080B94A0 @ 0x080B94A0

void sub_080B94A0(void)

{
  DisplayList_Add(0x80b2881,1);
  DAT_0300000e = 0;
  return;
}


// sub_080B94BC @ 0x080B94BC

void sub_080B94BC(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)((DAT_0200ab04 & 0x8000) == 0);
  return;
}


// sub_080B94E0 @ 0x080B94E0

void sub_080B94E0(void)

{
  DAT_0300000e = DAT_0300000e + 4;
  return;
}


// sub_080B94F0 @ 0x080B94F0

void sub_080B94F0(void)

{
  DAT_0300000e = DAT_0300000e + -4;
  return;
}


// sub_080B9500 @ 0x080B9500

void sub_080B9500(void)

{
  return;
}


// sub_080B9504 @ 0x080B9504

void sub_080B9504(int arg0)

{
  *(undefined2 *)(arg0 + 0x24) = DAT_0300000e;
  return;
}


// sub_080B9510 @ 0x080B9510

undefined4 sub_080B9510(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080AD0FC(0x8165444,0xffff);
  return uVar1;
}


// sub_080B9528 @ 0x080B9528

uint sub_080B9528(short *arg0)

{
  return (uint)(*arg0 == 0);
}


// sub_080B953C @ 0x080B953C

undefined4 sub_080B953C(void)

{
  undefined4 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar3;
  
  uVar1 = sub_080B2EFC(0,0);
  iVar2 = sub_080B3038(uVar1,0x21);
  if (iVar2 == 0) {
    iVar2 = sub_080F3190();
    bVar3 = iVar2 == 0;
  }
  else {
    bVar3 = false;
  }
                    /* WARNING: Could not recover jumptable at 0x080b9564. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(bVar3);
  return uVar1;
}


// sub_080B9568 @ 0x080B9568

undefined4 sub_080B9568(void)

{
  return 1;
}


// sub_080B956C @ 0x080B956C

void sub_080B956C(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080AB7D4(2,0xb,0x1a,2);
  *(undefined4 *)(arg0 + 0x24) = uVar1;
  return;
}


// sub_080B958C @ 0x080B958C

void sub_080B958C(void)

{
  Text_DrawSpriteString(0x8165574,0,0,0x12);
  sub_080C4AB0(0,0,0xd6,0x5e);
  return;
}


// sub_080B95BC @ 0x080B95BC

void sub_080B95BC(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (((DAT_030031b8 & 1) != 0) || ((DAT_030031b8 & 2) != 0)) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080B95E8 @ 0x080B95E8

void sub_080B95E8(int arg0)

{
  sub_080AB91C(*(undefined4 *)(arg0 + 0x24),0);
  Field_SetState(0x12);
  return;
}


// sub_080B95FC @ 0x080B95FC

void sub_080B95FC(void)

{
  int iVar1;
  
  if ((DAT_03005180 == 0) && (iVar1 = sub_080B3078(0,0,6), iVar1 != 1)) {
    DAT_030029b0 = *DAT_03004630;
    sub_080ACFCC(3,DAT_03004630,&DAT_03002b70,0x40);
    sub_080ACFCC(3,DAT_03004510,&DAT_03002b50,0x20);
    DAT_0300452c = sub_080AB054(0xd0,0x30,1,0x10);
    if (DAT_030029b0 != 0) {
      sub_080AB054(0,1,1,0x10);
    }
  }
  return;
}


// Location_GetNameCellFromCoords @ 0x080B968C

int Location_GetNameCellFromCoords(uint arg0,uint arg1,uint arg2,uint arg3)

{
  uint uVar1;
  uint uVar2;
  ushort local_1c;
  ushort local_1a;
  
  uVar1 = (uint)(ushort)DAT_03004614;
  uVar2 = (uint)(ushort)DAT_03004514;
  DAT_03004514 = arg1 & 0xffff;
  DAT_03004614 = arg0 & 0xffff;
  sub_080C1F50(arg2 & 0xffff,arg3 & 0xffff,&local_1c,&local_1a);
  DAT_03004614 = uVar1;
  DAT_03004514 = uVar2;
  return (((local_1a >> 2 & 3) + (uint)(local_1a >> 4) * 0x20 + (uint)(local_1c >> 4) * 4) * 0x40 +
         (local_1c >> 2 & 3) * 0x10) * 2 + 0x80a54ac;
}


// sub_080B9710 @ 0x080B9710

undefined4 sub_080B9710(int arg0)

{
  return *(undefined4 *)((uint)*(ushort *)(arg0 + 0x1a) * 4 + 0x81655f8);
}


// sub_080B9720 @ 0x080B9720

int sub_080B9720(undefined4 arg0,uint arg1)

{
  int iVar1;
  
  iVar1 = sub_080B9710(arg0);
  return iVar1 + 2 + (arg1 & 0xffff) * 4;
}


// sub_080B9738 @ 0x080B9738

undefined4 sub_080B9738(undefined4 arg0,uint arg1)

{
  ushort *puVar1;
  undefined4 uVar2;
  
  puVar1 = (ushort *)sub_080B9720(arg0,arg1 & 0xffff);
  uVar2 = sub_080C8B10((uint)*puVar1,(uint)puVar1[1]);
  return uVar2;
}


// sub_080B9750 @ 0x080B9750

undefined4 sub_080B9750(void)

{
  undefined4 uVar1;
  
  uVar1 = sub_080B2EFC(0,0);
  uVar1 = sub_080B3038(uVar1,3);
  return uVar1;
}


// sub_080B9764 @ 0x080B9764

undefined4 sub_080B9764(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_080B9750();
  if (*(short *)(iVar1 + 2) == 0) {
    uVar2 = 0x5a;
  }
  else {
    uVar2 = 0x5b;
  }
  return uVar2;
}


// sub_080B977C @ 0x080B977C

void sub_080B977C(int arg0)

{
  undefined2 uVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_080B9764();
  if (((uVar2 & 0xffff) == 0x5a) || (uVar2 = sub_080B9764(), (uVar2 & 0xffff) == 0x5b)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
                    /* WARNING: Could not recover jumptable at 0x080b97a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B97A8 @ 0x080B97A8

void sub_080B97A8(int arg0,int arg1)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 0) {
    *(undefined4 *)(arg0 + 0x38) = 1;
  }
  uVar1 = sub_080B9764();
  sub_080AD824(uVar1 & 0xffff,0,arg0 + 0x38);
  *(ushort *)(arg0 + 0x1c) = (ushort)(*(int *)(arg0 + 0x38) == 0);
                    /* WARNING: Could not recover jumptable at 0x080b97dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B97E0 @ 0x080B97E0

void sub_080B97E0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x81c1270;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B9804 @ 0x080B9804

void sub_080B9804(void)

{
  return;
}


// sub_080B9808 @ 0x080B9808

void sub_080B9808(void)

{
  uint uVar1;
  
  uVar1 = sub_080B9764();
  sub_080ADCCC(uVar1 & 0xffff,0);
  DAT_03003bbc = 0;
  return;
}


// sub_080B9828 @ 0x080B9828

void sub_080B9828(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x8165614;
  REG_DMA3DAD = 0x6016000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B984C @ 0x080B984C

void sub_080B984C(int arg0)

{
  DisplayList_Add(0x80ae0bd,1);
  DisplayList_Add(0x80b9829,1);
  if (DAT_03003bbc == -1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080B2840(0,0,0);
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_080B9898 @ 0x080B9898

void sub_080B9898(int arg0)

{
  if (DAT_0300455e == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080AE494();
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_080B98C0 @ 0x080B98C0

void sub_080B98C0(void)

{
  sub_080C7218();
  sub_080C7414();
  sub_080C6FF0();
  sub_080AE494();
  return;
}


// sub_080B98DC @ 0x080B98DC

undefined4 sub_080B98DC(int arg0)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (*(short *)(arg0 + 0x3c) == 0) {
    uVar1 = *(undefined2 *)(arg0 + 0x40);
  }
  else {
    puVar2 = (undefined2 *)sub_080B9710(arg0 + 0x24);
    uVar1 = *puVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x080b98f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar3;
}


// sub_080B98F8 @ 0x080B98F8

void sub_080B98F8(int arg0)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint arg1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (*(short *)(arg0 + 0x3c) == 0) {
    *(uint *)(arg0 + 0x2c) = (uint)*(ushort *)(arg0 + 0x42);
  }
  else {
    uVar1 = sub_080B98DC(arg0);
    iVar2 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)(ushort)DAT_03004514);
    arg1 = 0;
    if ((uVar1 & 0xffff) != 0) {
      do {
        iVar3 = sub_080B9738(arg0 + 0x24,arg1);
        if (iVar3 == iVar2) {
          *(uint *)(arg0 + 0x2c) = arg1;
          break;
        }
        arg1 = arg1 + 1 & 0xffff;
      } while (arg1 < (uVar1 & 0xffff));
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080b9950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B9954 @ 0x080B9954

void sub_080B9954(int arg0)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = sub_080B98DC(arg0);
  uVar1 = (uVar1 & 0xffff) * 2;
  if (0xb < uVar1) {
    uVar1 = 0xb;
  }
  if (uVar1 == 4) {
    uVar1 = 5;
  }
  sub_080B98F8(arg0);
  uVar2 = sub_080ABC40(0x13,0,9,uVar1 & 0xffff);
  *(undefined4 *)(arg0 + 0x24) = uVar2;
  uVar2 = sub_080AB7D4(2,0xb,0x1a,8);
  *(undefined4 *)(arg0 + 0x28) = uVar2;
  DAT_0200e804 = 1;
  return;
}


// sub_080B99B0 @ 0x080B99B0

void sub_080B99B0(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080ABD58(*(undefined4 *)(arg0 + 0x24));
  *(ushort *)(arg0 + 0x1c) = (ushort)(iVar1 == 1);
  return;
}


// sub_080B99C8 @ 0x080B99C8

void sub_080B99C8(int arg0)

{
  sub_080ABD30(*(undefined4 *)(arg0 + 0x24),0);
  sub_080AB91C(*(undefined4 *)(arg0 + 0x28),0);
  DAT_0200e804 = 0;
  return;
}


// sub_080B99F0 @ 0x080B99F0

void sub_080B99F0(undefined4 arg0,int arg1)

{
  uint uVar1;
  
  if (arg1 == 0) {
    uVar1 = sub_080B1A1C((uint)DAT_03004552);
    sub_080B2064(uVar1 & 0xffff,1);
  }
  else {
    sub_080B2064((uint)DAT_03004556,(uint)DAT_03004558);
  }
  return;
}


// sub_080B9A24 @ 0x080B9A24

void sub_080B9A24(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080B2090();
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (iVar1 != -1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    DAT_0300457e = 0;
  }
  return;
}


// sub_080B9A4C @ 0x080B9A4C

void sub_080B9A4C(undefined4 arg0,int arg1,undefined4 arg2)

{
  ushort uVar1;
  byte *pbVar2;
  uint arg0_00;
  
  sub_080B98DC(arg0);
  if (*(short *)(arg1 + 6) < 0) {
    arg0_00 = -(uint)*(ushort *)(arg1 + 6) & 0xffff;
    pbVar2 = (byte *)sub_080A9CC0(arg0_00);
    Text_DrawSpriteString(0x8165674,0,0,0x9c);
    if (arg0_00 < 10) {
      FontSprite_DrawGlyph((uint)*(ushort *)((uint)*pbVar2 * 2 + 0x816567e),0,0,0xb4);
      Text_DrawSpriteString(0x816567a,0,0,0xc0);
    }
    else {
      FontSprite_DrawGlyph((uint)*(ushort *)((uint)pbVar2[1] * 2 + 0x816567e),0,0,0xb4);
      FontSprite_DrawGlyph((uint)*(ushort *)((uint)*pbVar2 * 2 + 0x816567e),0,0,0xc0);
      Text_DrawSpriteString(0x816567a,0,0,0xcc);
    }
  }
  else {
    uVar1 = *(ushort *)(arg1 + 6);
    pbVar2 = (byte *)sub_080A9CC0((uint)uVar1);
    if (uVar1 < 10) {
      FontSprite_DrawGlyph((uint)*(ushort *)((uint)*pbVar2 * 2 + 0x816567e),0,0,0x9c);
      Text_DrawSpriteString(0x816567a,0,0,0xa8);
    }
    else {
      FontSprite_DrawGlyph((uint)*(ushort *)((uint)pbVar2[1] * 2 + 0x816567e),0,0,0x9c);
      FontSprite_DrawGlyph((uint)*(ushort *)((uint)*pbVar2 * 2 + 0x816567e),0,0,0xa8);
      Text_DrawSpriteString(0x816567a,0,0,0xb4);
    }
  }
  return;
}


// sub_080B9BA4 @ 0x080B9BA4

void sub_080B9BA4(int arg0)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint arg2;
  
  sub_080C8B10((uint)(ushort)DAT_03004614,0);
  iVar1 = sub_080B9750();
  uVar2 = sub_080B98DC(arg0);
  if (*(int *)(arg0 + 0x34) == 1) {
    if (*(short *)(arg0 + 0x3c) == 0) {
      uVar2 = 0;
      if (*(short *)(arg0 + 0x40) != 0) {
        do {
          uVar3 = sub_080C8B10((uint)(ushort)DAT_03004614,(uint)*(ushort *)(arg0 + 0x44 + uVar2 * 2)
                              );
          sub_080B9A4C(arg0,uVar3,uVar2);
          uVar2 = uVar2 + 1;
        } while (uVar2 < *(ushort *)(arg0 + 0x40));
      }
    }
    else {
      arg2 = 0;
      if ((uVar2 & 0xffff) != 0) {
        do {
          uVar3 = sub_080B9738(arg0 + 0x24,arg2 & 0xffff);
          sub_080B9A4C(arg0,uVar3,arg2);
          arg2 = arg2 + 1;
        } while (arg2 < (uVar2 & 0xffff));
      }
    }
    Text_DrawSpriteString(0x8165654,0,0,0x12);
  }
  if (*(ushort *)(iVar1 + 2) < 2) {
    sub_080B2AB0();
  }
  else {
    sub_080BA2F0(arg0);
  }
  return;
}


// sub_080B9C6C @ 0x080B9C6C

void sub_080B9C6C(int arg0)

{
  *(undefined4 *)(arg0 + 0x34) = 1;
  return;
}


// sub_080B9C74 @ 0x080B9C74

void sub_080B9C74(int arg0)

{
  uint uVar1;
  undefined4 arg0_00;
  undefined2 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080B98DC(arg0);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  uVar2 = 1;
  if ((DAT_0300458a & 1) == 0) {
    uVar2 = 2;
    if ((DAT_0300458a & 2) == 0) {
      if ((DAT_0300458c & 0x40) == 0) {
        if (((DAT_0300458c & 0x80) != 0) && (*(int *)(arg0 + 0x2c) != 0)) {
          *(int *)(arg0 + 0x2c) = *(int *)(arg0 + 0x2c) + -1;
          sub_080C51D4(100);
        }
      }
      else if (*(int *)(arg0 + 0x2c) != (uVar1 & 0xffff) - 1) {
        *(int *)(arg0 + 0x2c) = *(int *)(arg0 + 0x2c) + 1;
        sub_080C51D4(100);
      }
      goto LAB_080b9cee;
    }
    arg0_00 = 0x66;
  }
  else {
    arg0_00 = 0x65;
  }
  sub_080C51D4(arg0_00);
  *(undefined2 *)(arg0 + 0x1e) = uVar2;
LAB_080b9cee:
  sub_080C49EC(6,0,0,0x9c);
                    /* WARNING: Could not recover jumptable at 0x080b9d14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B9D18 @ 0x080B9D18

void sub_080B9D18(int arg0)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = DAT_03004514;
  *(uint *)(arg0 + 0x30) = DAT_03004514;
  DAT_03004634 = (undefined2)uVar3;
  if (*(short *)(arg0 + 0x3c) == 0) {
    uVar2 = (uint)*(ushort *)(arg0 + 0x44 + *(int *)(arg0 + 0x2c) * 2);
    if (uVar3 == uVar2) {
      *(undefined2 *)(arg0 + 0x1c) = 0;
      goto LAB_080b9dca;
    }
    DAT_03004514 = uVar2;
    sub_080AE234();
    sub_080AE294();
    sub_080B31C4(DAT_03004614 & 0xffff,3,(uint)*(ushort *)(DAT_03004000 + 4));
  }
  else {
    uVar3 = (uint)*(ushort *)(arg0 + 0x2c);
    sub_080B98F8(arg0);
    if (uVar3 == *(uint *)(arg0 + 0x2c)) {
      *(undefined2 *)(arg0 + 0x1c) = 0;
      goto LAB_080b9dca;
    }
    puVar1 = (ushort *)sub_080B9720(arg0 + 0x24,uVar3);
    DAT_03004614 = (uint)*puVar1;
    DAT_03004514 = (uint)puVar1[1];
    sub_080AE234();
    sub_080AE294();
    sub_080B31C4(DAT_03004614 & 0xffff,3,(uint)*(ushort *)(DAT_03004000 + 4));
    *(undefined4 *)(arg0 + 0x30) = *(undefined4 *)(arg0 + 0x2c);
    *(uint *)(arg0 + 0x2c) = uVar3;
  }
  *(undefined2 *)(arg0 + 0x1c) = 1;
LAB_080b9dca:
                    /* WARNING: Could not recover jumptable at 0x080b9dd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B9DD4 @ 0x080B9DD4

void sub_080B9DD4(int arg0)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(short *)(arg0 + 0x3c) == 0) {
    if (DAT_03004514 == *(ushort *)(arg0 + 0x44 + *(int *)(arg0 + 0x2c) * 2)) {
      uVar1 = 1;
      goto LAB_080b9e3e;
    }
  }
  else {
    iVar2 = sub_080B9738(arg0 + 0x24,(uint)*(ushort *)(arg0 + 0x2c));
    iVar3 = sub_080C8B10((uint)(ushort)DAT_03004614,DAT_03004514 & 0xffff);
    if (iVar2 == iVar3) {
      uVar1 = 1;
      goto LAB_080b9e3e;
    }
  }
  sub_080B343C(0xfffffffe);
  if (DAT_0300457e == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
LAB_080b9e3e:
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
  return;
}


// sub_080B9E48 @ 0x080B9E48

void sub_080B9E48(undefined4 arg0,int arg1)

{
  sub_080C7234();
  sub_080C7430();
  sub_080C700C();
  sub_080B2030((uint)DAT_0300455a,(uint)DAT_03004552,3);
  if (arg1 == 1) {
    DAT_0300457e = 0x21;
  }
  return;
}


// sub_080B9E78 @ 0x080B9E78

void sub_080B9E78(int arg0,int arg1)

{
  uint uVar1;
  dword arg0_00;
  int iVar2;
  short local_18;
  short local_16;
  
  uVar1 = sub_080B9764();
  if ((uVar1 & 0xffff) == 0x5a) {
    if (arg1 == 0) {
      sub_080C1F50((uint)DAT_03004562,(uint)DAT_03004564,&local_18,&local_16);
      if ((local_18 == 0x40) && (local_16 == 0xc)) {
        arg0_00 = 0x8002cbc;
      }
      else if (*(uint *)(arg0 + 0x30) < (uint)*(ushort *)(arg0 + 0x44 + *(int *)(arg0 + 0x2c) * 2))
      {
        arg0_00 = 0x8002cbc;
      }
      else {
        arg0_00 = 0x8002ccc;
      }
      sub_080AA184(arg0_00,1,0xd,0);
    }
  }
  else {
    iVar2 = 0xde;
    if (*(uint *)(arg0 + 0x30) < (uint)*(ushort *)(arg0 + 0x44 + *(int *)(arg0 + 0x2c) * 2)) {
      iVar2 = 0xd7;
    }
    if (arg1 == 0) {
      *(undefined2 *)(iVar2 * 2 + 0x3002db0) = 0x1f;
    }
    else {
      *(undefined2 *)(iVar2 * 2 + 0x3002db0) = *(undefined2 *)(&UNK_084c0bd0 + iVar2 * 2);
    }
    sub_080AABB0();
  }
  return;
}


// sub_080B9F4C @ 0x080B9F4C

void sub_080B9F4C(int arg0,undefined4 arg1)

{
  if (*(uint *)(arg0 + 0x30) < *(uint *)(arg0 + 0x2c)) {
    arg1._0_2_ = -(short)arg1;
  }
  DAT_0300000e = DAT_0300000e + (short)arg1;
  return;
}


// sub_080B9F78 @ 0x080B9F78

void sub_080B9F78(int arg0,int arg1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint arg0_00;
  uint arg1_00;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = DAT_03004564;
  uVar1 = DAT_03004562;
  uVar3 = DAT_03004514 & 0xffff;
  uVar4 = sub_080C8B3C((uint)(ushort)DAT_03004614);
  DAT_03004514 = 0;
  DAT_03004562 = 0;
  DAT_03004564 = 0;
  uVar7 = 0;
  if ((uVar4 & 0xffff) != 0) {
    do {
      sub_080AE234();
      uVar7 = uVar7 + 1;
      for (arg1_00 = 0; arg1_00 < DAT_0300456c; arg1_00 = arg1_00 + 1 & 0xffff) {
        for (arg0_00 = 0; arg0_00 < DAT_0300456a; arg0_00 = arg0_00 + 1 & 0xffff) {
          uVar5 = arg0_00;
          sub_080B2FDC(arg0_00,arg1_00);
          iVar6 = sub_080B3038(uVar5,3);
          uVar5 = DAT_03004514;
          if ((iVar6 != 0) && (*(short *)(iVar6 + 4) == *(short *)(arg1 + 4))) {
            *(short *)(arg0 + 0x20 + (uint)*(ushort *)(arg0 + 0x1c) * 2) = (short)DAT_03004514;
            if (uVar3 == uVar5) {
              *(undefined2 *)(arg0 + 0x1e) = *(undefined2 *)(arg0 + 0x1c);
            }
            *(short *)(arg0 + 0x1c) = *(short *)(arg0 + 0x1c) + 1;
          }
        }
      }
      DAT_03004514 = DAT_03004514 + 1;
    } while (uVar7 < (uVar4 & 0xffff));
  }
  DAT_03004514 = uVar3;
  DAT_03004562 = uVar1;
  DAT_03004564 = uVar2;
  sub_080AE234();
                    /* WARNING: Could not recover jumptable at 0x080ba064. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080BA070 @ 0x080BA070

void sub_080BA070(void)

{
  int arg1;
  dword arg0;
  int iVar1;
  
  arg1 = sub_080B9750();
  if (*(ushort *)(arg1 + 2) < 2) {
    arg0 = 0x8165694;
  }
  else {
    arg0 = 0x8173594;
  }
  iVar1 = sub_080AD0FC(arg0,0xffff);
  DAT_03003fec = iVar1;
  if (*(short *)(arg1 + 2) == 2) {
    *(undefined2 *)(iVar1 + 0x54) = 0;
    *(undefined2 *)(iVar1 + 0x56) = 0x8000;
  }
  if (*(ushort *)(arg1 + 4) < 0x80) {
    sub_080B9F78(iVar1 + 0x24,arg1);
  }
  else {
    *(undefined2 *)(iVar1 + 0x3c) = 1;
    *(ushort *)(iVar1 + 0x3e) = *(ushort *)(arg1 + 4) & 0x7f;
  }
  Field_SetState(0x1a);
  return;
}


// sub_080BA0E0 @ 0x080BA0E0

void sub_080BA0E0(undefined4 arg0,int arg1,int arg2)

{
  int iVar1;
  
  iVar1 = *(int *)(arg2 * 4 + arg1 * 0x10 + 0x8173488);
  if (iVar1 != 0) {
    LZ77UnCompWram(iVar1,arg2 * 0x1000 + 0x2001000,iVar1);
  }
  iVar1 = *(int *)(arg2 * 4 + arg1 * 0x14 + 0x81734e8);
  if (iVar1 != 0) {
    LZ77UnCompWram(iVar1,arg2 * 0x1000 + 0x2005000,iVar1);
  }
  if (arg2 == 3) {
    DAT_0300000e = (undefined2)*(undefined4 *)(&DAT_081734f8 + arg1 * 0x14);
    CpuSet(*(undefined4 *)(arg1 * 4 + 0x8173560),0x2000000,0x4000400);
  }
  return;
}


// sub_080BA170 @ 0x080BA170

void sub_080BA170(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2005000;
  REG_DMA3DAD = 0x6004000;
  REG_DMA3CNT = 0x84000d00;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


