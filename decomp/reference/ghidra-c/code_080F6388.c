/* Ghidra decompilation of asm/code_080F6388.s (reference only; not compiled). */

// sub_080F6388 @ 0x080F6388

void sub_080F6388(int arg0)

{
  *(undefined4 *)(arg0 + 0xc) = 0;
  return;
}


// sub_080F6390 @ 0x080F6390

uint sub_080F6390(void)

{
  uint uVar1;
  
  uVar1 = sub_080C2244();
  return uVar1 & 0xf | 3;
}


// sub_080F63A4 @ 0x080F63A4

void sub_080F63A4(int arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080F3F44();
  if ((uVar1 & 0x200) == 0) {
    sub_080F3F74(0x200);
  }
  else {
    *(undefined4 *)(arg0 + 8) = 0x96;
  }
                    /* WARNING: Could not recover jumptable at 0x080f63c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F63C8 @ 0x080F63C8

void sub_080F63C8(void)

{
  undefined4 in_r0;
  
  sub_080F6178(in_r0,0x20,0x326);
  return;
}


// sub_080F63DC @ 0x080F63DC

void sub_080F63DC(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = (uint)DAT_03004562;
  uVar1 = (uint)DAT_03004564;
  uVar5 = 0;
  do {
    uVar3 = 0;
    do {
      uVar6 = ((int)((uVar2 - 2) * 0x10000) >> 0x10) + ((int)(uVar3 * 0x10000) >> 0x10);
      if ((-1 < (int)uVar6) &&
         (uVar4 = ((int)((uVar1 - 2) * 0x10000) >> 0x10) + ((int)(uVar5 * 0x10000) >> 0x10),
         -1 < (int)uVar4)) {
        sub_080AF4EC(uVar6 & 0xffff,uVar4 & 0xffff);
      }
      uVar6 = uVar3 * 0x10000 + 0x10000;
      uVar3 = uVar6 >> 0x10;
    } while ((int)uVar6 >> 0x10 < 5);
    uVar3 = uVar5 * 0x10000 + 0x10000;
    uVar5 = uVar3 >> 0x10;
  } while ((int)uVar3 >> 0x10 < 5);
  return;
}


// sub_080F6448 @ 0x080F6448

void sub_080F6448(int arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080F3F44();
  if ((uVar1 & 0x400) == 0) {
    sub_080F3F74(0x400);
  }
  else {
    *(undefined4 *)(arg0 + 8) = 0x96;
  }
                    /* WARNING: Could not recover jumptable at 0x080f646a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080F646C @ 0x080F646C

void sub_080F646C(int arg0)

{
  *(undefined4 *)(arg0 + 0xc) = 0;
  return;
}


