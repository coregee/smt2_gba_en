/* Ghidra decompilation of asm/code_0813D0F4.s (reference only; not compiled). */

// sub_0813D0F4 @ 0x0813D0F4

void sub_0813D0F4(void)

{
  int iVar1;
  
  iVar1 = sub_080B092C();
  if (iVar1 != 1) {
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 1);
  return;
}


// sub_0813D118 @ 0x0813D118

void sub_0813D118(void)

{
  int iVar1;
  
  iVar1 = sub_080CE74C(DAT_030068e0);
  if (iVar1 != 0) {
    DAT_0203db5a = 0xf;
    DAT_0203db5c = 0x3c;
  }
  DAT_03006858 = 1;
  return;
}


// sub_0813D14C @ 0x0813D14C

void sub_0813D14C(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D158 @ 0x0813D158

void sub_0813D158(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D164 @ 0x0813D164

void sub_0813D164(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D170 @ 0x0813D170

void sub_0813D170(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D17C @ 0x0813D17C

void sub_0813D17C(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D188 @ 0x0813D188

void sub_0813D188(void)

{
  DAT_0203db5a = 0;
  DAT_030068e4 = DAT_0203dac8;
  DAT_03006858 = 0;
  return;
}


// sub_0813D1AC @ 0x0813D1AC

void sub_0813D1AC(void)

{
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813D1C0 @ 0x0813D1C0

void sub_0813D1C0(void)

{
  int iVar1;
  
  iVar1 = sub_080B7DF8(DAT_03006954);
  if (iVar1 != 0) {
    DAT_03006954 = 0;
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 0);
  return;
}


// sub_0813D1F8 @ 0x0813D1F8

void sub_0813D1F8(void)

{
  return;
}


// sub_0813D1FC @ 0x0813D1FC

void sub_0813D1FC(void)

{
  int iVar1;
  
  iVar1 = sub_080D1EA8(DAT_030068e0);
  if (iVar1 != 0) {
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 0);
  return;
}


// sub_0813D234 @ 0x0813D234

void sub_0813D234(void)

{
  int iVar1;
  
  iVar1 = sub_080B8160(DAT_03006938);
  if (iVar1 != 0) {
    DAT_03006938 = 0;
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 0);
  return;
}


// sub_0813D26C @ 0x0813D26C

void sub_0813D26C(void)

{
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  DAT_0203db72 = DAT_030065e0 - 0x90;
  sub_080B7E3C(0,(uint)*(ushort *)((uint)DAT_0203db72 * 6 + 0x878ffd0),
               (uint)*(ushort *)(((uint)DAT_0203db72 * 3 + 1) * 2 + 0x878ffd0));
  DAT_030068e4 = *(undefined4 *)((*(byte *)(DAT_0203db72 + 0x8790e4c) + 1) * 4 + 0x203dac8);
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813D314 @ 0x0813D314

void sub_0813D314(void)

{
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db4a = 0;
  Font_ResetGlyphSpriteCache(0x180);
  DAT_030068e4 = DAT_0203dac8;
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813D368 @ 0x0813D368

void sub_0813D368(void)

{
  DAT_030068e4 = DAT_0203dac8;
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813D38C @ 0x0813D38C

void sub_0813D38C(void)

{
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813D3A0 @ 0x0813D3A0

void sub_0813D3A0(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D3AC @ 0x0813D3AC

void sub_0813D3AC(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D3B8 @ 0x0813D3B8

void sub_0813D3B8(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D3C4 @ 0x0813D3C4

void sub_0813D3C4(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D3D0 @ 0x0813D3D0

void sub_0813D3D0(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D3DC @ 0x0813D3DC

void sub_0813D3DC(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D3E8 @ 0x0813D3E8

void sub_0813D3E8(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D3F4 @ 0x0813D3F4

void sub_0813D3F4(void)

{
  short sVar1;
  uint uVar2;
  
  sVar1 = DAT_030065e8;
  if (DAT_030065e8 == 0) {
    uVar2 = sub_0812DC10();
    if ((uVar2 & 0xffff) == 0xfe) {
      DAT_03006858 = 1;
    }
    else {
      if ((uVar2 & 0xffff) == 0xff) {
        DAT_030068e4 = DAT_0203dac8;
      }
      else {
        DAT_03006944 = (undefined2)uVar2;
      }
      DAT_0203db5a = sVar1;
      DAT_03006858 = 0;
    }
  }
  else {
    DAT_03006944 = 0;
    DAT_0203db5a = 0;
    DAT_03006858 = 0;
  }
  return;
}


// sub_0813D474 @ 0x0813D474

void sub_0813D474(void)

{
  int iVar1;
  
  iVar1 = sub_080CE74C(DAT_030068e0);
  if (iVar1 == 0) {
    DAT_03006858 = 1;
  }
  else {
    DAT_0203db5a = 0;
    if (DAT_030031cc == 1) {
      DAT_030068e4 = DAT_0203dac8;
    }
    DAT_03006858 = 0;
  }
  return;
}


// sub_0813D4C8 @ 0x0813D4C8

void sub_0813D4C8(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)DAT_0203db5c;
  DAT_0203db5c = (ushort)(uVar1 - 1);
  iVar2 = (uVar1 - 1) * 0x10000;
  if (iVar2 >> 0x10 == 0) {
    DAT_0203db5a = (undefined2)((uint)iVar2 >> 0x10);
    sub_080D34F0(DAT_030068a4);
  }
  DAT_03006858 = 1;
  return;
}


// sub_0813D508 @ 0x0813D508

void sub_0813D508(void)

{
  DAT_03006954 = 0;
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813D524 @ 0x0813D524

void sub_0813D524(void)

{
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813D538 @ 0x0813D538

void sub_0813D538(void)

{
  DAT_0203db5a = 0;
  DAT_03006858 = 0;
  return;
}


// sub_0813D54C @ 0x0813D54C

void sub_0813D54C(void)

{
  int iVar1;
  
  iVar1 = sub_080B9528(DAT_03006954);
  if (iVar1 != 0) {
    DAT_03006954 = 0;
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 0);
  return;
}


// sub_0813D584 @ 0x0813D584

void sub_0813D584(void)

{
  int iVar1;
  
  iVar1 = sub_080BA920();
  if (iVar1 != 0) {
    DAT_03006954 = 0;
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 == 0);
  return;
}


// sub_0813D5BC @ 0x0813D5BC

void sub_0813D5BC(void)

{
  int iVar1;
  
  iVar1 = sub_080CE74C(DAT_03006964);
  if (iVar1 == 0) {
    DAT_03006858 = 1;
  }
  else {
    iVar1 = sub_080F2F64(0x8000);
    if (DAT_0203db2c < (uint)(int)*(short *)(iVar1 + 0x18)) {
      iVar1 = sub_080F2F64(0x8000);
      *(short *)(iVar1 + 0x18) = *(short *)(iVar1 + 0x18) - (short)DAT_0203db2c;
    }
    else {
      iVar1 = sub_080F2F64(0x8000);
      *(undefined2 *)(iVar1 + 0x18) = 0;
      sub_080C08E8(0,0x8000);
    }
    sub_080C84A0();
    DAT_0203db5a = 0;
    DAT_03006858 = 0;
  }
  return;
}


// sub_0813D638 @ 0x0813D638

void sub_0813D638(int arg0)

{
  int iVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  int arg0_00;
  
  iVar1 = sub_080B8B08(DAT_03006964);
  if (iVar1 == 0) {
    DAT_03006858 = 1;
  }
  else {
    iVar1 = sub_080C104C();
    uVar4 = 0;
    if (0 < iVar1 + 4) {
      do {
        arg0_00 = (int)(uVar4 * 0x10000) >> 0x10;
        iVar2 = sub_080C0A00(arg0_00);
        if ((iVar2 == 1) && (iVar2 = sub_080F3EC8(arg0_00), iVar2 == 1)) {
          uVar5 = arg0_00 - 0x8000U & 0xffff;
          iVar2 = sub_080F2F64(uVar5);
          sVar3 = (short)*(ushort *)(iVar2 + 0x18) >> 3;
          if (((int)((uint)*(ushort *)(iVar2 + 0x18) << 0x10) >> 0x13) * 0x10000 < 1) {
            sVar3 = 1;
          }
          iVar2 = sub_080F2F64(uVar5);
          if (sVar3 < *(short *)(iVar2 + 0x18)) {
            iVar2 = sub_080F2F64(uVar5);
            *(short *)(iVar2 + 0x18) = *(short *)(iVar2 + 0x18) - sVar3;
          }
          else {
            iVar2 = sub_080F2F64(uVar5);
            *(undefined2 *)(iVar2 + 0x18) = 0;
            sub_080C08E8(arg0_00,0x8000);
          }
        }
        uVar5 = uVar4 * 0x10000 + 0x10000;
        uVar4 = uVar5 >> 0x10;
      } while ((int)uVar5 >> 0x10 < iVar1 + 4);
    }
    sub_080C84A0();
    uVar4 = sub_08138CE8();
    if ((uVar4 & 0xffff) != 0) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
    DAT_0203db5a = 0;
    DAT_03006858 = 0;
  }
  return;
}


// sub_0813D724 @ 0x0813D724

void sub_0813D724(void)

{
  int iVar1;
  
  iVar1 = sub_080D53E0();
  if (iVar1 == 1) {
    if (DAT_030037f0 != 0) {
      if (DAT_030037f0 < 0xc351) {
        iVar1 = sub_080C31F0();
        if (iVar1 + DAT_030037f0 < 1000000) {
          DAT_0203db2c = DAT_030037f0;
          DAT_030068e4 = DAT_0203dac8;
        }
        else {
          DAT_030068e4 = DAT_0203dacc;
        }
      }
      else {
        DAT_030068e4 = DAT_0203dad0;
      }
    }
    DAT_0203db5a = 0;
    DAT_03006858 = 0;
  }
  else {
    DAT_03006858 = 1;
  }
  return;
}


// sub_0813D7B8 @ 0x0813D7B8

void sub_0813D7B8(void)

{
  int iVar1;
  
  iVar1 = sub_080CE74C(DAT_030068e0);
  if (iVar1 == 0) {
    DAT_03006858 = 1;
  }
  else {
    if (DAT_030031cc != 1) {
      DAT_030068e4 = DAT_0203dac8;
      DAT_0203db86 = 1;
    }
    DAT_0203db5a = 0;
    DAT_03006858 = 0;
  }
  return;
}


// sub_0813D814 @ 0x0813D814

void sub_0813D814(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = sub_080CE74C(DAT_030068e0);
  if (iVar1 == 0) {
    DAT_03006858 = 1;
  }
  else {
    uVar2 = sub_0812EEC4();
    uVar3 = sub_0813E60C(uVar2 & 0xffff,0x1f);
    if ((uVar3 & 0xff) < 0xc0) {
      uVar3 = (uint)*(ushort *)((uVar3 & 0xff) * 2 + 0x8790e5a);
      if ((uVar3 - 10 & 0xffff) < 2) {
        DAT_0203db80 = DAT_0203db7c;
        DAT_0203db7c = (undefined2)uVar2;
      }
    }
    else {
      uVar3 = 0x1c;
    }
    DAT_03006950 = 0x8032cd8;
    DAT_030068e4 = *(undefined4 *)((uVar3 & 0x7fff) * 4 + 0x8032cd8);
    DAT_0203db5a = 0;
    DAT_03006858 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0813d894. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0813D8B8 @ 0x0813D8B8

void sub_0813D8B8(void)

{
  int iVar1;
  
  iVar1 = sub_080D3AA0(0);
  if (iVar1 == 1) {
    if (DAT_030031cc == 1) {
      DAT_030068e4 = DAT_0203dac8;
    }
    DAT_0203db5a = 0;
    DAT_03006858 = 0;
  }
  else {
    DAT_03006858 = 1;
  }
  return;
}


// sub_0813D904 @ 0x0813D904

void sub_0813D904(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_080D3CCC();
  if (iVar1 == 1) {
    iVar1 = sub_080D3CE4();
    uVar2 = DAT_0203dac8;
    if ((iVar1 - 1U < 2) || (uVar2 = DAT_0203dacc, iVar1 - 3U < 2)) {
      DAT_030068e4 = uVar2;
    }
    DAT_0203db5a = 0;
    DAT_03006858 = 0;
  }
  else {
    DAT_03006858 = 1;
  }
  return;
}


// sub_0813D964 @ 0x0813D964

void sub_0813D964(void)

{
  int iVar1;
  
  iVar1 = sub_080D4594();
  if (iVar1 == 1) {
    DAT_0203db5a = 0;
  }
  DAT_03006858 = (ushort)(iVar1 != 1);
  return;
}


// sub_0813D994 @ 0x0813D994

void sub_0813D994(void)

{
  DAT_0203db5a = 0;
  DAT_030068e4 = DAT_0203dad0;
  DAT_03006858 = 0;
  return;
}


// sub_0813D9B8 @ 0x0813D9B8

void sub_0813D9B8(void)

{
  DAT_03006858 = 1;
  return;
}


// sub_0813D9C4 @ 0x0813D9C4

void sub_0813D9C4(void)

{
  int iVar1;
  
  iVar1 = sub_080AB994(DAT_03006968);
  if (iVar1 != 0) {
    DAT_0203db5c = 10;
    DAT_0203db5a = 0xf;
  }
  DAT_03006858 = 1;
  return;
}


// sub_0813D9F8 @ 0x0813D9F8

void sub_0813D9F8(void)

{
  return;
}


// sub_0813D9FC @ 0x0813D9FC

void sub_0813D9FC(void)

{
  return;
}


// sub_0813DA00 @ 0x0813DA00

void sub_0813DA00(void)

{
  return;
}


// sub_0813DA04 @ 0x0813DA04

void sub_0813DA04(void)

{
  DAT_0203db40 = DAT_0203db40 + 4;
  return;
}


// sub_0813DA14 @ 0x0813DA14

void sub_0813DA14(undefined4 arg0)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_080C07E0(arg0);
  sVar1 = (short)uVar2;
  if ((((sVar1 != 0x75) && (sVar1 != 0x20)) && (sVar1 != 0x21)) && (sVar1 != 0x22)) {
    uVar3 = sub_080C0818(arg0);
    if ((uVar3 & 0x8000) == 0) {
      if ((uVar3 & 0x8000) == 0) goto LAB_0813da62;
      uVar3 = 0x3f;
    }
    else {
      uVar3 = 0x7f;
    }
    uVar4 = sub_080C2244();
    if ((uVar3 & uVar4) == 0) {
      uVar2 = 0;
      goto LAB_0813da64;
    }
  }
LAB_0813da62:
  uVar2 = 1;
LAB_0813da64:
                    /* WARNING: Could not recover jumptable at 0x0813da68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}


// sub_0813DA6C @ 0x0813DA6C

undefined4 sub_0813DA6C(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = sub_0812DC10();
  uVar2 = uVar2 & 0xffff;
  if (uVar2 == 0xfe) {
    uVar3 = 0;
    goto LAB_0813db28;
  }
  if (uVar2 == 0xff) {
LAB_0813db20:
    DAT_0203db5a = 0;
  }
  else {
    iVar4 = sub_080C3100();
    iVar5 = sub_08135064(uVar2,(uint)DAT_0300668c);
    if (iVar5 <= iVar4) {
      sub_080C30AC(-iVar5);
      sub_081350CC(uVar2,(uint)DAT_0300668c);
      sub_080C84A0();
      uVar1 = DAT_0300668c;
      DAT_0203db34 = 1;
      if (DAT_0300668c == 0) {
        uVar2 = sub_0813560C();
        if ((uVar2 & 0xffff) != 0) {
          DAT_0203db5a = uVar1;
          goto LAB_0813db26;
        }
      }
      else {
        if (DAT_0300668c == 1) {
          uVar2 = sub_08135370();
        }
        else if (DAT_0300668c == 2) {
          uVar2 = sub_08135420();
        }
        else if (DAT_0300668c == 3) {
          uVar2 = sub_081354B0();
        }
        else {
          uVar2 = sub_08135540();
        }
        if ((uVar2 & 0xffff) != 0) goto LAB_0813db20;
      }
      sub_0812DC24();
      uVar3 = 0;
      goto LAB_0813db28;
    }
    DAT_0203db5a = 0;
    DAT_030068e4 = DAT_0203dac8;
  }
LAB_0813db26:
  uVar3 = 1;
LAB_0813db28:
                    /* WARNING: Could not recover jumptable at 0x0813db2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(uVar3);
  return uVar3;
}


// ScriptVM_Run @ 0x0813DB34

void ScriptVM_Run(undefined4 arg0)

{
  undefined4 arg0_00;
  undefined4 arg1;
  uint uVar1;
  undefined4 arg2;
  uint uVar2;
  undefined4 arg3;
  code *UNRECOVERED_JUMPTABLE;
  
  _call_via_r1(arg0,*(undefined4 *)(DAT_0203db5a * 4 + 0x8790fdc));
  if (DAT_03006858 != 1) {
    DAT_0203db6e = 0;
    do {
      while( true ) {
        if (DAT_030068e4 != 0) {
          DAT_03006950 = DAT_030068e4;
          DAT_030068e4 = 0;
          DAT_0203db40 = 0;
        }
        DAT_0203db44 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
        DAT_0203db40 = DAT_0203db40 + 1;
        if (0x170 < (ushort)(DAT_0203db44 - 0x300)) break;
        _call_via_r1(arg0,*(undefined4 *)((uint)(ushort)(DAT_0203db44 - 0x300) * 4 + 0x87913dc));
        if (DAT_0203db6e == 1) goto LAB_0813dcf6;
      }
      if ((DAT_0203db6c == 0) && (DAT_03006670 == 0)) {
        if (DAT_0203db7a == 0) {
          arg0_00 = 2;
          arg1 = 0xb;
          arg2 = 0x1a;
          arg3 = 8;
        }
        else {
          arg0_00 = 1;
          arg1 = 0xc;
          arg2 = 0x1c;
          arg3 = 7;
        }
        DAT_03006968 = sub_080AB7D4(arg0_00,arg1,arg2,arg3);
        DAT_0203db40 = DAT_0203db40 - 1;
        DAT_0203db6c = 1;
        DAT_0203db5a = 1;
        goto LAB_0813dcf6;
      }
      uVar1 = DAT_0203db3e & 0x3fff;
      uVar2 = uVar1 << 2 | 1;
      *(short *)(uVar1 * 8 + 0x203d800) = DAT_0203db44;
      uVar1 = uVar2 + 1;
      *(short *)(uVar2 * 2 + 0x203d800) = DAT_0203db38 * 0xd + 0x11;
      *(short *)((uVar1 & 0xffff) * 2 + 0x203d800) = DAT_0203db3a * 0xd + DAT_03006614;
      *(undefined2 *)((uVar1 * 0x10000 + 0x10000 >> 0xf) + 0x203d800) = 0;
      uVar1 = DAT_0203db3e + 1;
      DAT_0203db3e = (ushort)uVar1;
      if (0x3f < (uVar1 & 0xffff)) {
        DAT_0203db3e = 0x3f;
      }
      DAT_0203db38 = DAT_0203db38 + 1;
    } while (DAT_0203db48 == 1);
    DAT_0203db5a = 0xf;
    DAT_0203db5c = DAT_0203db82;
    if ((DAT_030031b0 & 2) != 0) {
      DAT_0203db48 = 1;
    }
  }
LAB_0813dcf6:
                    /* WARNING: Could not recover jumptable at 0x0813dd04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_0813DD2C @ 0x0813DD2C

void sub_0813DD2C(int arg0)

{
  if ((DAT_03006670 == 0) && (DAT_0203db6c != 0)) {
    sub_080AB91C(DAT_03006968,0);
  }
  *(undefined2 *)(arg0 + 0x1c) = 0;
  return;
}


// sub_0813DD64 @ 0x0813DD64

void sub_0813DD64(int arg0)

{
  short sVar1;
  int iVar2;
  
  sVar1 = DAT_03006670;
  if ((DAT_03006670 == 0) && (DAT_0203db6c != 0)) {
    iVar2 = sub_080AB994(DAT_03006968);
    if (iVar2 != 1) {
      return;
    }
    DAT_0203db6c = sVar1;
  }
  *(undefined2 *)(arg0 + 0x1c) = 1;
  return;
}


// sub_0813DDA4 @ 0x0813DDA4

void sub_0813DDA4(void)

{
  sub_080AF3FC();
  return;
}


// sub_0813DDB0 @ 0x0813DDB0

void sub_0813DDB0(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  return;
}


// sub_0813DDB8 @ 0x0813DDB8

void sub_0813DDB8(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  return;
}


// sub_0813DDC0 @ 0x0813DDC0

void sub_0813DDC0(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  return;
}


// sub_0813DDC8 @ 0x0813DDC8

void sub_0813DDC8(void)

{
  DAT_0203db5a = 4;
  return;
}


// sub_0813DDD4 @ 0x0813DDD4

void sub_0813DDD4(int arg0)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  return;
}


// sub_0813DDDC @ 0x0813DDDC

void sub_0813DDDC(int arg0)

{
  if (DAT_0203db4a == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  else {
    DAT_0203db4a = DAT_0203db4a + -1;
  }
  return;
}


// sub_0813DE04 @ 0x0813DE04

void sub_0813DE04(void)

{
  undefined4 uVar1;
  
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db5a = 6;
  Font_ResetGlyphSpriteCache(0x180);
  uVar1 = sub_0813E408();
  DAT_0203db48 = (short)uVar1;
  return;
}


// sub_0813DE44 @ 0x0813DE44

void sub_0813DE44(int arg0)

{
  if (((((DAT_030031c4 & 1) != 0) || ((DAT_030031c4 & 0x40) != 0)) || ((DAT_030031c4 & 0x80) != 0))
     || ((((DAT_030031c4 & 0x10) != 0 || ((DAT_030031c4 & 0x20) != 0)) || ((DAT_030031c4 & 2) != 0))
        )) {
    sub_080C51D4(0x65);
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_0813DE9C @ 0x0813DE9C

void sub_0813DE9C(void)

{
  uint uVar1;
  uint uVar2;
  short *psVar3;
  
  uVar2 = 0;
  if (DAT_0203db3e != 0) {
    do {
      psVar3 = (short *)(((short)uVar2 * 4 + 2) * 2 + 0x203d800);
      *psVar3 = *psVar3 + -0xd;
      uVar1 = (int)(short)uVar2 + 1;
      uVar2 = uVar1 & 0xffff;
    } while ((int)(uVar1 * 0x10000) >> 0x10 < (int)(uint)DAT_0203db3e);
  }
  return;
}


// sub_0813DED8 @ 0x0813DED8

void sub_0813DED8(int arg0)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  if ((DAT_0203db3e != 0) && (uVar2 = 0, DAT_0203db3e != 0)) {
    do {
      iVar3 = (int)(short)uVar2;
      if ((int)DAT_03006614 <= (int)(uint)*(ushort *)((iVar3 * 4 + 2) * 2 + 0x203d800)) {
        sub_080AC2A0((uint)*(ushort *)(iVar3 * 8 + 0x203d800),0,0,
                     (uint)*(ushort *)((iVar3 * 4 + 1) * 2 + 0x203d800));
      }
      uVar2 = iVar3 + 1U & 0xffff;
    } while ((int)((iVar3 + 1U) * 0x10000) >> 0x10 < (int)(uint)DAT_0203db3e);
  }
  if ((DAT_0300699c != 0) && (uVar2 = 0, 0 < DAT_0300669c)) {
    do {
      iVar3 = (int)(short)uVar2;
      sub_080AC2A0((uint)*(ushort *)(iVar3 * 8 + 0x203da00),0,0,
                   (uint)*(ushort *)((iVar3 * 4 + 1) * 2 + 0x203da00));
      uVar2 = iVar3 + 1U & 0xffff;
    } while ((int)((iVar3 + 1U) * 0x10000) >> 0x10 < (int)DAT_0300669c);
  }
  uVar2 = 0;
  do {
    iVar3 = (int)(short)uVar2;
    if (*(short *)(iVar3 * 0x10 + 0x3006620) != 0) {
      sub_080D31F8((&DAT_03006624)[iVar3 * 4],(uint)(ushort)(&DAT_03006628)[iVar3 * 8],
                   (uint)(ushort)(&DAT_0300662a)[iVar3 * 8],(uint)(ushort)(&DAT_0300662c)[iVar3 * 8]
                  );
    }
    uVar2 = iVar3 + 1U & 0xffff;
  } while ((int)((iVar3 + 1U) * 0x10000) >> 0x10 < 5);
  uVar1 = DAT_030069d8;
  if (DAT_030069d0 != 1) {
    if (DAT_030069d0 != 2) {
      if (DAT_030069d0 == 3) {
        sub_080C6B40((uint)DAT_030069d8,0,0,0x17);
        sub_080C6B40((uint)DAT_030069da,0,0,0x17);
        sub_080C6B40((uint)DAT_030069dc,0,0,0x17);
      }
      goto LAB_0813e05a;
    }
    sub_080C6B40((uint)DAT_030069d8,0,0,0x17);
    uVar1 = DAT_030069da;
  }
  sub_080C6B40((uint)uVar1,0,0,0x17);
LAB_0813e05a:
  if (DAT_03006920 != 0) {
    sub_080D3170((uint)DAT_03006922,0x12,0x66,(uint)DAT_03006924);
  }
  if (DAT_03006928 != 0) {
    sub_080D3170((uint)DAT_0300692a,0x12,0x74,(uint)DAT_0300692c);
  }
  if (DAT_03006930 != 0) {
    sub_080D3170((uint)DAT_03006932,0x12,0x83,(uint)DAT_03006934);
  }
  if (DAT_03006958 != 0) {
    sub_080C49EC((uint)DAT_030066a0,4,0,(uint)DAT_0300689c);
  }
  if (DAT_03006678 != 0) {
    sub_080C49EC(0x13,4,0,0x1f);
  }
  if (DAT_0203db46 == 1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  if (DAT_0203db52 != 0) {
    if (DAT_0203db7a == 0) {
      sub_080C4AB0(0,0,0xd5,0x8d);
    }
    else {
      sub_080C4AB0(0,0,0xd5,0x8d);
    }
  }
  uVar2 = (uint)DAT_03006848;
  if (uVar2 != 0) {
    sub_080C4A4C(0,0,(uint)*(ushort *)(uVar2 * 4 + 0x87923dc),
                 (uint)*(ushort *)((uVar2 * 2 + 1) * 2 + 0x87923dc));
  }
  uVar2 = (uint)DAT_03006680;
  if (uVar2 != 0) {
    sub_080C4AB0(0,0,(uint)*(ushort *)(uVar2 * 4 + 0x87923fc),
                 (uint)*(ushort *)((uVar2 * 2 + 1) * 2 + 0x87923fc));
  }
  return;
}


// sub_0813E184 @ 0x0813E184

void sub_0813E184(undefined4 arg0,undefined4 arg1)

{
  undefined4 uVar1;
  uint uVar2;
  
  DAT_030065f0 = 0;
  DAT_030069cc = 0;
  DAT_0203db86 = 0;
  DAT_0203db82 = 2;
  if (DAT_0203db7a == 1) {
    DAT_03006614 = 0x61;
  }
  else if (DAT_0203db7a == 2) {
    DAT_03006614 = 0x69;
  }
  else {
    DAT_03006614 = 0x59;
  }
  DAT_030069d0 = 0;
  sub_0813EB6C(1);
  DAT_03006914 = 0xff;
  DAT_030068ac = 0;
  DAT_03006958 = 0;
  DAT_030065e4 = 0;
  uVar2 = 0;
  DAT_0203db2c = 0;
  DAT_030068a0 = 0;
  DAT_0300667c = 0;
  DAT_03006678 = 0;
  DAT_0300693c = 0;
  DAT_0203db5a = 0;
  DAT_0300669c = 0;
  DAT_0300699c = 0;
  DAT_030068e4 = 0;
  DAT_030065fc = 0;
  DAT_03006670 = (undefined2)arg1;
  DAT_03006950 = arg0;
  do {
    *(undefined2 *)(uVar2 * 0x10 + 0x3006620) = 0;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 5);
  uVar2 = 0;
  do {
    *(undefined2 *)(uVar2 * 8 + 0x3006920) = 0;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 3);
  DAT_0203db52 = 0;
  DAT_0203db56 = 0;
  DAT_030069c0 = 0;
  DAT_030069c4 = 0;
  DAT_030068f0 = 0;
  DAT_030068f4 = 0;
  DAT_030068f8 = 0;
  DAT_030068fc = 0;
  DAT_03006900 = 0;
  DAT_03006904 = 0;
  DAT_03006908 = 0;
  DAT_0300690c = 0;
  DAT_0203db66 = 0;
  DAT_0203db68 = 0;
  DAT_0203db64 = 0;
  DAT_030068c4 = 0;
  DAT_03006818 = 0;
  DAT_03006600 = 0;
  DAT_030065ec = 0;
  DAT_030068d0 = 0;
  DAT_03006610 = 0;
  DAT_03006910 = 0;
  uVar1 = sub_0813E408();
  DAT_0203db48 = (undefined2)uVar1;
  DAT_0203db4a = 0;
  DAT_0203db3e = 0;
  DAT_0203db38 = 0;
  DAT_0203db3a = 0;
  DAT_0203db44 = 0;
  DAT_0203db40 = 0;
  DAT_0203db46 = 0;
  DAT_0203db6c = 0;
  DAT_03006968 = 0;
  DAT_030068b0 = 0;
  DAT_030068a4 = 0;
  DAT_030065f4 = sub_080AD0FC(0x8790024,0xffff);
  sub_080AD0FC(0x878fb48,0xffff);
  DAT_030069e4 = sub_080AD0FC(0x878fb84,0xffff);
  DAT_03006848 = 0;
  DAT_03006680 = 0;
  DAT_0203db18 = 0x318;
  return;
}


// sub_0813E408 @ 0x0813E408

uint sub_0813E408(void)

{
  uint uVar1;
  
  if (DAT_03006670 == 1) {
    uVar1 = Settings_GetBattleMsgSpeed();
  }
  else {
    uVar1 = sub_080C2AFC();
  }
  return uVar1 & 0xffff;
}


// ScriptVM_RunAlt @ 0x0813E428

undefined4 ScriptVM_RunAlt(int arg0)

{
  undefined4 arg0_00;
  
  arg0_00 = DAT_030068b0;
  DAT_030065f0 = 1;
  DAT_0203db76 = DAT_0203db72;
  DAT_0203db78 = DAT_0203db74;
  DAT_030068c0 = DAT_03006950;
  DAT_030068dc = DAT_0203db40;
  DAT_030068e4 = 0;
  DAT_0203db40 = 0;
  DAT_0203db5e = 0;
  DAT_0203db60 = 0;
  DAT_0203db6e = 0;
  DAT_03006950 = arg0;
  sub_0813E544();
  while( true ) {
    if (DAT_030068e4 != 0) {
      DAT_03006950 = DAT_030068e4;
      DAT_030068e4 = 0;
      DAT_0203db40 = 0;
    }
    DAT_0203db44 = *(short *)((uint)DAT_0203db40 * 2 + DAT_03006950);
    DAT_0203db40 = DAT_0203db40 + 1;
    if (0x170 < (ushort)(DAT_0203db44 - 0x300)) goto LAB_0813e52e;
    _call_via_r1(arg0_00,*(undefined4 *)((uint)(ushort)(DAT_0203db44 - 0x300) * 4 + 0x8791bdc));
    if (DAT_0203db5e == 1) break;
    if (DAT_0203db5e == 2) {
      sub_0813E574();
      return 0;
    }
    if (DAT_0203db6e == 1) {
LAB_0813e52e:
      sub_0813E574();
      return 2;
    }
  }
  if (DAT_0203db60 == 1) {
    sub_0813E574();
    return 1;
  }
  goto LAB_0813e52e;
}


// sub_0813E544 @ 0x0813E544

void sub_0813E544(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    *(undefined1 *)(uVar1 + 0x30066b0) = *(undefined1 *)(uVar1 + 0x3005ca8);
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x168);
  return;
}


// sub_0813E574 @ 0x0813E574

void sub_0813E574(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    *(undefined1 *)(uVar1 + 0x3005ca8) = *(undefined1 *)(uVar1 + 0x30066b0);
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x168);
  DAT_03006950 = DAT_030068c0;
  DAT_0203db40 = DAT_030068dc;
  DAT_0203db72 = DAT_0203db76;
  DAT_0203db74 = DAT_0203db78;
  DAT_030065f0 = 0;
  return;
}


// sub_0813E60C @ 0x0813E60C

uint sub_0813E60C(uint arg0,undefined4 arg1)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  uint arg0_00;
  
  arg0_00 = arg0 & 0xffff;
  uVar1 = 0;
  switch((undefined2)arg1) {
  case 0:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 1);
    break;
  case 1:
  case 2:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(ushort *)(iVar2 + 2);
    break;
  case 3:
  case 4:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(ushort *)(iVar2 + 4);
    break;
  case 5:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(char *)(iVar2 + 6);
    goto LAB_0813e75a;
  case 6:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(char *)(iVar2 + 7);
    goto LAB_0813e75a;
  case 7:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(char *)(iVar2 + 8);
    goto LAB_0813e75a;
  case 8:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(char *)(iVar2 + 9);
    goto LAB_0813e75a;
  case 9:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(char *)(iVar2 + 10);
    goto LAB_0813e75a;
  case 10:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(char *)(iVar2 + 0xb);
    goto LAB_0813e75a;
  case 0xb:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0xc);
    break;
  case 0xc:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0xd);
    break;
  case 0xd:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(char *)(iVar2 + 0xe);
    goto LAB_0813e75a;
  case 0xe:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(char *)(iVar2 + 0xf);
    goto LAB_0813e75a;
  case 0xf:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(char *)(iVar2 + 0x10);
LAB_0813e75a:
    uVar1 = uVar1 & 0xffff;
    break;
  case 0x10:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x11);
    break;
  case 0x11:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x12);
    break;
  case 0x12:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x13);
    break;
  case 0x13:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x14);
    break;
  case 0x14:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x15);
    break;
  case 0x15:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x16);
    break;
  case 0x16:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x17);
    break;
  case 0x17:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x18);
    break;
  case 0x18:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x19);
    break;
  case 0x19:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(ushort *)(iVar2 + 0x1a);
    break;
  case 0x1a:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x1c);
    break;
  case 0x1b:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x1d);
    break;
  case 0x1c:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x1e);
    break;
  case 0x1d:
    iVar2 = sub_080BF648(arg0_00);
    uVar1 = (uint)*(byte *)(iVar2 + 0x1f);
    break;
  case 0x1e:
    iVar2 = sub_080BF648(arg0_00);
    pbVar3 = (byte *)(iVar2 + 0x20);
    goto LAB_0813e7fe;
  case 0x1f:
    iVar2 = sub_080BF648(arg0_00);
    pbVar3 = (byte *)(iVar2 + 0x21);
LAB_0813e7fe:
    uVar1 = (uint)*pbVar3;
  }
  return uVar1;
}


// sub_0813E804 @ 0x0813E804

uint sub_0813E804(uint arg0)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  iVar1 = sub_080C104C();
  for (uVar4 = 4; (int)uVar4 < iVar1 + 4; uVar4 = uVar4 + 1 & 0xffff) {
    iVar2 = sub_080C09B0(uVar4);
    if ((iVar2 != 0) && (uVar3 = sub_080C07E0(uVar4), (int)(short)uVar3 == (arg0 & 0xffff))) {
      uVar5 = uVar5 + 1;
    }
  }
  uVar4 = sub_08134C3C();
  if ((uVar4 & 0xffff) != 0) {
    uVar5 = uVar5 + 1;
  }
  return uVar5 & 0xffff;
}


// sub_0813E854 @ 0x0813E854

uint sub_0813E854(uint arg0)

{
  uint uVar1;
  
  uVar1 = arg0 & 0xff;
  if ((uVar1 < 0x54) || (0xb1 < uVar1)) {
    uVar1 = sub_0813E60C(arg0 & 0xffff,0x1e);
    uVar1 = uVar1 & 0xffff;
    DAT_03006860 = 1;
  }
  else {
    uVar1 = (uint)(byte)(&DAT_03005734)[uVar1 - 0x54 & 0xffff];
    DAT_03006860 = 0;
  }
  return uVar1;
}


// sub_0813E8A8 @ 0x0813E8A8

undefined4 sub_0813E8A8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = sub_080C1D9C();
  if ((uVar1 & 0xf0) != 0x80) {
    uVar1 = sub_0813E854((uint)DAT_0203db7c);
    if (DAT_03006860 == 0) {
      uVar2 = sub_0813E854((uint)DAT_0203db7e);
      if (((DAT_03006860 == 0) && ((uVar2 & 0xffff) < (uVar1 & 0xffff))) &&
         (uVar1 = sub_0813E804((uint)DAT_0203db7e), (uVar1 & 0xffff) == 0)) {
        return 1;
      }
    }
  }
  return 0;
}


// sub_0813E908 @ 0x0813E908

void sub_0813E908(undefined4 arg0,undefined4 arg1)

{
  DAT_0203db28 = (undefined2)arg0;
  DAT_0203db2a = (undefined2)arg1;
  return;
}


// sub_0813E914 @ 0x0813E914

void sub_0813E914(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  dword arg0;
  char cVar5;
  
  DAT_0203db7a = 0;
  DAT_0300684c = DAT_0300684c & 3;
  cVar5 = '\0';
  uVar2 = sub_0813E60C((uint)DAT_0203db7c,0xb);
  uVar2 = uVar2 & 0xff;
  if (uVar2 < 0x70) {
    uVar2 = sub_080C0794(0);
    uVar2 = (uVar2 & 0xffff) >> 8;
    if (uVar2 < 0x70) {
LAB_0813e96e:
      cVar5 = '\x04';
    }
  }
  else if (0x8f < uVar2) {
    uVar2 = sub_080C0794(0);
    uVar2 = (uVar2 & 0xffff) >> 8;
    if (0x8f < uVar2) goto LAB_0813e96e;
  }
  if ((ushort)(DAT_0203db7c - 0x54) < 0x5e) {
    if (DAT_0203db7c < 0xb2) {
      uVar2 = (uint)(byte)(&DAT_03005734)[(ushort)(DAT_0203db7c - 0x54)];
    }
  }
  else {
    uVar2 = sub_0813E60C((uint)DAT_0203db7c,0x1e);
    uVar2 = uVar2 & 0xff;
  }
  DAT_030068b4 = (char)(uVar2 >> 3) + cVar5;
  sub_080EF930((uint)DAT_030068b4);
  uVar2 = sub_080C0F8C(0);
  iVar3 = sub_0813E60C((uint)DAT_0203db7c,0);
  uVar2 = (((uVar2 & 0xffff) - iVar3 & 0xffff) >> 1) + 8;
  if ((uVar2 & 0x80) == 0) {
    if ((uVar2 & 0xff) < 0x20) {
      DAT_030069e8 = (byte)uVar2;
    }
    else {
      DAT_030069e8 = 0x1f;
    }
  }
  else {
    DAT_030069e8 = 0;
  }
  sub_080EF978((uint)DAT_030069e8);
  uVar4 = sub_0813E60C((uint)DAT_0203db7c,0x1f);
  DAT_0300685c = (byte)uVar4;
  sub_080C0818(0);
  uVar2 = sub_0813E804((uint)DAT_0203db7c);
  if ((uVar2 & 0xffff) == 0) {
    if ((DAT_0203db7e != 0xffff) &&
       (uVar2 = sub_0813E8A8(), uVar1 = DAT_0203db7e, (uVar2 & 0xffff) != 0)) {
      DAT_0203db7e = DAT_0203db7c;
      DAT_0203db7c = uVar1;
      uVar2 = sub_0813E60C((uint)uVar1,0x1f);
      DAT_0300685c = (byte)uVar2;
      DAT_03006950 = 0x8032c78;
      sub_0813E184(*(undefined4 *)(((uVar2 & 0xff) >> 4) * 4 + 0x8032c78),1);
      DAT_0203db70 = 0xffff;
      DAT_03004530 = 10;
      return;
    }
    uVar2 = sub_080C1D9C();
    if ((uVar2 & 0xf0) == 0x80) {
      DAT_03006950 = 0x8032d4c;
      arg0 = *(dword *)((uint)(DAT_0300685c >> 4) * 4 + 0x8032d4c);
      goto LAB_0813eb32;
    }
    uVar2 = sub_0813E60C((uint)DAT_0203db7c,0);
    uVar4 = sub_080C0F8C(0);
    if ((int)(short)uVar4 < (int)(uVar2 & 0xffff)) {
      DAT_03006950 = 0x8032ca8;
      arg0 = *(dword *)((uint)(DAT_0300685c >> 4) * 4 + 0x8032ca8);
      goto LAB_0813eb32;
    }
  }
  else {
    sub_0815BAC8((uint)DAT_0203db7c,3);
  }
  arg0 = 0x8084020;
LAB_0813eb32:
  sub_0813E184(arg0,1);
  DAT_0203db70 = 0xffff;
  DAT_03004530 = 10;
  return;
}


// sub_0813EB60 @ 0x0813EB60

uint sub_0813EB60(void)

{
  return (uint)DAT_0203db70;
}


// sub_0813EB6C @ 0x0813EB6C

void sub_0813EB6C(undefined4 arg0)

{
  DAT_0203db6a = (undefined2)arg0;
  return;
}


// sub_0813EB78 @ 0x0813EB78

uint sub_0813EB78(void)

{
  return (uint)DAT_0203db6a;
}


// sub_0813EB84 @ 0x0813EB84

void sub_0813EB84(undefined4 arg0,undefined4 arg1)

{
  DAT_0300684c = 0;
  DAT_0203db7c = (undefined2)arg0;
  DAT_0203db7e = (undefined2)arg1;
  DAT_0203db30 = sub_080EDA24(1);
  return;
}


