/* Ghidra decompilation of asm/code_0815E684.s (reference only; not compiled). */

// sub_0815E684 @ 0x0815E684

uint sub_0815E684(uint arg0,uint arg1,uint arg2)

{
  uint uVar1;
  
  if (arg2 != 0) {
    uVar1 = 0x20 - arg2;
    if ((int)uVar1 < 1) {
      arg0 = arg1 >> (-uVar1 & 0xff);
    }
    else {
      arg0 = arg0 >> (arg2 & 0xff) | arg1 << (uVar1 & 0xff);
    }
  }
  return arg0;
}


// sub_0815E6B8 @ 0x0815E6B8

uint sub_0815E6B8(uint arg0,undefined4 arg1,uint arg2,undefined4 arg3)

{
  uint uVar1;
  
  uVar1 = (arg2 & 0xffff) * (arg0 & 0xffff);
  return ((arg2 >> 0x10) * (arg0 & 0xffff) + (uVar1 >> 0x10) + (arg2 & 0xffff) * (arg0 >> 0x10)) *
         0x10000 | uVar1 & 0xffff;
}


// sub_0815E728 @ 0x0815E728

int sub_0815E728(int arg0,undefined4 arg1)

{
  return -arg0;
}


// memcpy @ 0x0815E740

void memcpy(undefined4 *arg0,undefined4 *arg1,uint arg2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((0xf < arg2) && ((((uint)arg1 | (uint)arg0) & 3) == 0)) {
    do {
      *arg0 = *arg1;
      arg0[1] = arg1[1];
      puVar2 = arg1 + 3;
      arg0[2] = arg1[2];
      arg1 = arg1 + 4;
      arg0[3] = *puVar2;
      arg0 = arg0 + 4;
      arg2 = arg2 - 0x10;
    } while (0xf < arg2);
    for (; 3 < arg2; arg2 = arg2 - 4) {
      uVar1 = *arg1;
      arg1 = arg1 + 1;
      *arg0 = uVar1;
      arg0 = arg0 + 1;
    }
  }
  while (arg2 = arg2 - 1, arg2 != 0xffffffff) {
    *(undefined1 *)arg0 = *(undefined1 *)arg1;
    arg1 = (undefined4 *)((int)arg1 + 1);
    arg0 = (undefined4 *)((int)arg0 + 1);
  }
  return;
}


// memset @ 0x0815E7A0

void memset(uint *arg0,uint arg1,uint arg2)

{
  uint uVar1;
  
  if ((3 < arg2) && (((uint)arg0 & 3) == 0)) {
    arg1 = arg1 & 0xff;
    uVar1 = arg1 << 8 | arg1;
    uVar1 = uVar1 | uVar1 << 0x10;
    for (; 0xf < arg2; arg2 = arg2 - 0x10) {
      *arg0 = uVar1;
      arg0[1] = uVar1;
      arg0[2] = uVar1;
      arg0[3] = uVar1;
      arg0 = arg0 + 4;
    }
    for (; 3 < arg2; arg2 = arg2 - 4) {
      *arg0 = uVar1;
      arg0 = arg0 + 1;
    }
  }
  while (arg2 != 0) {
    *(char *)arg0 = (char)arg1;
    arg0 = (uint *)((int)arg0 + 1);
    arg2 = arg2 - 1;
  }
  return;
}


// srand @ 0x0815E7F4

void srand(undefined4 arg0)

{
  *(undefined4 *)(iRam0203de9c + 0x58) = arg0;
  return;
}


// rand @ 0x0815E800

uint rand(void)

{
  uint uVar1;
  
  uVar1 = *(int *)(iRam0203de9c + 0x58) * 0x41c64e6dU + 0x3039;
  *(uint *)(iRam0203de9c + 0x58) = uVar1;
  return uVar1 & 0x7fffffff;
}


