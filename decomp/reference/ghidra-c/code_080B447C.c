/* Ghidra decompilation of asm/code_080B447C.s (reference only; not compiled). */

// sub_080B447C @ 0x080B447C

uint sub_080B447C(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_03004552;
  uVar1 = sub_080C2BF0();
  if ((uVar1 & 0xffff) == 0) {
    uVar2 = 0;
  }
  return uVar2;
}


// sub_080B449C @ 0x080B449C

void sub_080B449C(undefined4 arg0,undefined4 arg1,short *arg2,short *arg3)

{
  uint uVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080C2BF0();
  if ((uVar1 & 0xffff) == 0) {
    if (DAT_0300456c < 0xc) {
      uVar4 = DAT_0300456a >> 1;
      uVar3 = DAT_0300456c >> 1;
    }
    else {
LAB_080b453c:
      uVar4 = DAT_0300456a >> 1;
      uVar3 = DAT_03004564;
      if ((short)DAT_03004564 < 0) {
        uVar3 = 0;
      }
    }
  }
  else {
    uVar1 = sub_080B447C();
    uVar1 = uVar1 & 0xffff;
    if (((uVar1 == 0) || (uVar1 == 2)) && (DAT_0300456c < 0xc)) {
      uVar3 = DAT_0300456c >> 1;
      uVar4 = DAT_0300456a >> 1;
    }
    else if ((DAT_0300456a < 0xc) && (DAT_0300456c < 0xc)) {
      uVar3 = DAT_0300456c >> 1;
      uVar4 = DAT_0300456a >> 1;
    }
    else {
      if ((uVar1 == 0) || (uVar1 == 2)) goto LAB_080b453c;
      uVar3 = DAT_0300456c >> 1;
      uVar4 = DAT_03004562;
      if ((short)DAT_03004562 < 0) {
        uVar4 = 0;
      }
    }
  }
  uVar1 = sub_080B447C();
  uVar1 = uVar1 & 0xffff;
  if (uVar1 == 1) {
    *arg2 = (0xd - uVar3) * 8;
    *arg3 = (uVar4 + 5) * 8;
    *arg2 = *arg2 + (ushort)arg1 * 8;
    sVar2 = *arg3 + ((ushort)arg0 & 0x1fff) * -8;
  }
  else if (uVar1 < 2) {
    if (uVar1 != 0) goto LAB_080b45fc;
    *arg2 = (0xd - uVar4) * 8;
    *arg3 = (5 - uVar3) * 8;
    *arg2 = *arg2 + (ushort)arg0 * 8;
    sVar2 = *arg3 + (ushort)arg1 * 8;
  }
  else if (uVar1 == 2) {
    *arg2 = (uVar4 + 0xd) * 8;
    *arg3 = (uVar3 + 5) * 8;
    *arg2 = *arg2 + (ushort)arg0 * -8;
    sVar2 = *arg3 + ((ushort)arg1 & 0x1fff) * -8;
  }
  else {
    if (uVar1 != 3) goto LAB_080b45fc;
    *arg2 = (uVar3 + 0xd) * 8;
    *arg3 = (5 - uVar4) * 8;
    *arg2 = *arg2 + (ushort)arg1 * -8;
    sVar2 = *arg3 + (ushort)arg0 * 8;
  }
  *arg3 = sVar2;
  *arg3 = sVar2 + DAT_0200dfce * 8;
LAB_080b45fc:
                    /* WARNING: Could not recover jumptable at 0x080b4608. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B4610 @ 0x080B4610

void sub_080B4610(uint arg0,uint arg1,undefined4 arg2)

{
  uint uVar1;
  undefined1 local_18 [2];
  ushort local_16;
  
  uVar1 = sub_080AF68C(arg0 & 0xffff,arg1 & 0xffff);
  if ((uVar1 & 0xffff) != 0) {
    sub_080B449C(arg0 & 0xffff,arg1 & 0xffff,local_18,&local_16);
    if (local_16 < 0x58) {
      sub_080AA184(arg2,2,0,2);
    }
  }
  return;
}


// sub_080B466C @ 0x080B466C

void sub_080B466C(void)

{
  int iVar1;
  uint uVar2;
  uint arg0;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_03003ffc != 1) {
    uVar2 = 0;
    do {
      iVar1 = uVar2 * 8;
      if (((ushort)(&DAT_0300580c)[uVar2 * 4] == DAT_03004614) &&
         ((ushort)(&DAT_0300580e)[uVar2 * 4] == DAT_03004514)) {
        sub_080B4610((uint)*(byte *)(iVar1 + 0x3005808),(uint)(byte)(&DAT_03005809)[iVar1],
                     *(undefined4 *)((uint)(byte)(&DAT_0300580b)[iVar1] * 4 + 0x81629e4));
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 8);
    if (DAT_03003ffc != 2) {
      uVar2 = sub_080C2BF0();
      if ((uVar2 & 0xffff) == 0) {
        sub_080B4610((uint)DAT_03004562,(uint)DAT_03004564,
                     *(undefined4 *)((uint)DAT_03004552 * 4 + 0x81629f8));
      }
      else {
        sub_080B4610((uint)DAT_03004562,(uint)DAT_03004564,&DAT_080001d8);
      }
    }
    uVar2 = 0;
    if (DAT_0300456c != 0) {
      do {
        arg0 = 0;
        if (DAT_0300456a != 0) {
          do {
            iVar1 = *(int *)((uint)*(ushort *)((uVar2 * 0x20 + arg0) * 2 + 0x200afc8) * 4 +
                            0x8162a08);
            if (iVar1 != 0) {
              sub_080B4610(arg0,uVar2,iVar1);
            }
            arg0 = arg0 + 1 & 0xffff;
          } while (arg0 < DAT_0300456a);
        }
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < DAT_0300456c);
    }
    if (DAT_0300456e != 0x36) {
      MarkerHeader_DrawLocationName(0,0,0x12,0x59);
    }
    if (DAT_0200dfd2 == 0) {
      if (DAT_0200dfca == 1) {
        sub_080C4A4C(2,2,200,0x30);
      }
      if (DAT_0200dfc8 == 1) {
        sub_080C4AB0(2,2,200,0x48);
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x080b47ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B47CC @ 0x080B47CC

void sub_080B47CC(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = sub_080B447C();
  uVar3 = uVar3 & 0xffff;
  uVar4 = sub_080C2BF0();
  if ((uVar4 & 0xffff) == 0) {
    uVar1 = DAT_03004564;
    if (DAT_0300456c < 0xc) goto LAB_080b4826;
  }
  else {
    if ((((uVar3 != 0) && (uVar3 != 2)) || (0xb < DAT_0300456c)) &&
       ((0xb < DAT_0300456a || (0xb < DAT_0300456c)))) {
      if ((uVar3 == 0) || (uVar3 == 2)) {
        uVar2 = DAT_0300456a >> 1;
        uVar1 = DAT_03004564;
      }
      else {
        uVar1 = DAT_0300456c >> 1;
        uVar2 = DAT_03004562;
      }
      sub_080AEDB4(uVar3,(uint)uVar2,(uint)uVar1);
      goto LAB_080b484c;
    }
LAB_080b4826:
    uVar1 = DAT_0300456c >> 1;
  }
  sub_080AEDB4(uVar3,(uint)(DAT_0300456a >> 1),(uint)uVar1);
LAB_080b484c:
                    /* WARNING: Could not recover jumptable at 0x080b4850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B4854 @ 0x080B4854

void sub_080B4854(void)

{
  short sVar1;
  undefined4 arg0;
  int iVar2;
  uint arg0_00;
  uint arg1;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 local_20;
  
  local_20 = 0;
  CpuSet(&local_20,0x200afc8,0x5000c00);
  arg1 = 0;
  do {
    if (DAT_0300456c <= arg1) {
                    /* WARNING: Could not recover jumptable at 0x080b4a4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    for (arg0_00 = 0; arg0_00 < DAT_0300456a; arg0_00 = arg0_00 + 1 & 0xffff) {
      arg0 = sub_080B3000(arg0_00,arg1);
      iVar2 = sub_080B3038(arg0,0x23);
      if (iVar2 == 0) {
        iVar2 = sub_080B3038(arg0,4);
        if (iVar2 != 0) {
          sVar1 = 0xf;
          goto LAB_080b4a1e;
        }
        iVar2 = sub_080B3038(arg0,1);
        if (iVar2 == 0) {
          iVar2 = sub_080B3038(arg0,2);
          if (iVar2 == 0) {
            iVar2 = sub_080B3038(arg0,0x1b);
            if (iVar2 == 0) {
              iVar2 = sub_080B3038(arg0,0x1c);
              if (iVar2 == 0) {
                iVar2 = sub_080B3038(arg0,0x10);
                if (iVar2 == 0) {
                  iVar2 = sub_080B3038(arg0,3);
                  if (iVar2 == 0) {
                    iVar2 = sub_080B3038(arg0,0x22);
                    if (iVar2 == 0) {
                      iVar2 = sub_080B3038(arg0,0xb);
                      if (iVar2 == 0) {
                        iVar2 = sub_080B3038(arg0,0xc);
                        if (iVar2 == 0) {
                          iVar2 = sub_080B3038(arg0,0xd);
                          if (iVar2 == 0) {
                            iVar2 = sub_080B3038(arg0,0xe);
                            if (iVar2 == 0) {
                              iVar2 = sub_080B3038(arg0,0xf);
                              if (iVar2 == 0) {
                                iVar2 = sub_080B3038(arg0,0x11);
                                if (iVar2 == 0) {
                                  iVar2 = sub_080B3038(arg0,0x25);
                                  if (iVar2 == 0) {
                                    iVar2 = sub_080B3038(arg0,0x26);
                                    if (iVar2 == 0) {
                                      iVar2 = sub_080B3038(arg0,0x27);
                                      if (iVar2 == 0) goto LAB_080b4a20;
                                      sVar1 = 0x24;
                                    }
                                    else {
                                      sVar1 = 0x23;
                                    }
                                  }
                                  else {
                                    sVar1 = 0x22;
                                  }
                                }
                                else {
                                  sVar1 = 0x14;
                                }
                              }
                              else {
                                sVar1 = 0xe;
                              }
                            }
                            else {
                              sVar1 = 0xd;
                            }
                          }
                          else {
                            if (((DAT_03004614 == 0x1a) && (DAT_03004514 == 1)) &&
                               (iVar2 = sub_080C2340(0x15), iVar2 == 0)) goto LAB_080b4a20;
                            sVar1 = 0xc;
                          }
                        }
                        else {
                          sVar1 = 7;
                        }
                      }
                      else {
                        iVar2 = sub_080B3038(arg0,0xb);
                        sVar1 = *(short *)(iVar2 + 8);
                        if (sVar1 == 7) {
                          sVar1 = 0x14;
                        }
                        else if (sVar1 == 9) {
                          sVar1 = 0x16;
                        }
                        else if (sVar1 == 10) {
                          sVar1 = 0x21;
                        }
                        else {
                          sVar1 = 0x11;
                        }
                      }
                    }
                    else {
                      sVar1 = 0x11;
                    }
                  }
                  else {
                    sVar1 = 10;
                  }
                }
                else {
                  sVar1 = 0xb;
                }
              }
              else {
                if (*(short *)(iVar2 + 2) == 0) goto LAB_080b4a20;
                sVar1 = 9;
              }
            }
            else {
              if (*(short *)(iVar2 + 2) == 0) goto LAB_080b4a20;
              sVar1 = 8;
            }
          }
          else {
            if (*(short *)(iVar2 + 2) == 0) goto LAB_080b4a20;
            sVar1 = 9;
          }
          goto LAB_080b4a1e;
        }
        if (*(short *)(iVar2 + 2) != 0) {
          sVar1 = 8;
          goto LAB_080b4a1e;
        }
      }
      else {
        sVar1 = *(short *)(iVar2 + 2) + 1;
LAB_080b4a1e:
        *(short *)((arg1 * 0x20 + arg0_00) * 2 + 0x200afc8) = sVar1;
      }
LAB_080b4a20:
    }
    arg1 = arg1 + 1 & 0xffff;
  } while( true );
}


// sub_080B4A54 @ 0x080B4A54

undefined4 sub_080B4A54(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = 0;
    do {
      if (*(short *)(uVar1 * 0xc + uVar2 * 0x150 + 0x2005000) != 0) {
        return 1;
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < 0x1c);
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0xb);
  return 0;
}


// sub_080B4AA4 @ 0x080B4AA4

void sub_080B4AA4(void)

{
  undefined4 uVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  
  sub_080B447C();
  uVar2 = 0;
  do {
    uVar4 = 0;
    do {
      puVar3 = (ushort *)(uVar4 * 0xc + uVar2 * 0x150 + 0x2005000);
      if (*puVar3 != 0) {
        uVar1 = sub_080B4448(uVar2 * 0x150 + uVar4 * 0xc + 0x2005000);
        if ((*puVar3 & 0x8000) == 0) {
          (&DAT_02000002)[uVar4 + uVar2 * 0x20] = (ushort)uVar1;
        }
        else {
          (&DAT_02000002)[uVar4 + uVar2 * 0x20] = (ushort)uVar1 | 0x6000;
        }
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < 0x1c);
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0xb);
  sub_080B4854();
  DisplayList_Add(0x80b5085,1);
  return;
}


// sub_080B4B58 @ 0x080B4B58

void sub_080B4B58(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6014800;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B4B7C @ 0x080B4B7C

void sub_080B4B7C(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6015800;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B4BA0 @ 0x080B4BA0

void sub_080B4BA0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6016800;
  REG_DMA3CNT = 0x84000400;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B4BC4 @ 0x080B4BC4

void sub_080B4BC4(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x200afc8;
  REG_DMA3DAD = 0x6017800;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B4BE8 @ 0x080B4BE8

void sub_080B4BE8(undefined4 arg0,undefined4 arg1,int arg2)

{
  dword arg0_00;
  
  LZ77UnCompWram(arg1,0x200afc8,arg2);
  if (arg2 == 1) {
    arg0_00 = 0x80b4b7d;
  }
  else if (arg2 == 0) {
    arg0_00 = 0x80b4b59;
  }
  else {
    if (arg2 != 2) {
      if (arg2 != 3) {
        return;
      }
      DisplayList_Add(0x80b4bc5,1);
      DAT_03003fec = 0;
      return;
    }
    arg0_00 = 0x80b4ba1;
  }
  DisplayList_Add(arg0_00,1);
  return;
}


// sub_080B4C48 @ 0x080B4C48

void sub_080B4C48(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = DAT_0300456e;
  uVar3 = (uint)DAT_0300456e;
  if (uVar3 == 0x33) {
    if (DAT_0200e7e0 == 0) {
      sub_080B4AA4();
      DAT_0300456e = DAT_0300456e + 1;
      DAT_030045f8 = sub_080AB7D4(2,0xb,0x1a,2);
    }
    goto LAB_080b5078;
  }
  if (uVar3 < 0x34) {
    if (uVar3 == 0xf) {
      DAT_03003fec = sub_080AD0FC(0x8162ab0,0xffff);
      DAT_0300456e = 0x10;
      goto LAB_080b5078;
    }
    if (uVar3 < 0x10) {
      if (uVar3 == 0) {
        sub_080C14FC();
        DAT_0300456e = 10;
        if (DAT_03002db0 != 0) {
          DAT_03002db0 = uVar1;
        }
        sub_080ACFA4(3,0,&DAT_03002f70,0x40);
        sub_080ACFA4(3,0,&DAT_03002f50,0x20);
        sub_080ACFA4(3,0,&DAT_03003150,0x20);
        sub_080AABB0();
        Font_ResetGlyphSpriteCache(0x180);
        DAT_03003ffc = uVar3;
        sub_080C7C60();
        goto LAB_080b5078;
      }
    }
    else {
      if (uVar3 == 0x10) {
        if (DAT_03003fec == 0) {
          DAT_0300456e = 0x12;
        }
        goto LAB_080b5078;
      }
      if (uVar3 == 0x32) {
        sub_080C14FC();
        DAT_0300456e = DAT_0300456e + 1;
        sub_080B47CC();
        goto LAB_080b5078;
      }
    }
LAB_080b5070:
    DisplayList_Add(0x80b50c1,1);
  }
  else {
    if (uVar3 != 0x36) {
      if (uVar3 < 0x37) {
        if (uVar3 == 0x34) {
          iVar2 = sub_080AB994(DAT_030045f8);
          if (iVar2 == 0) goto LAB_080b5078;
          if (((DAT_0300458a & 0x200) != 0) || ((DAT_0300458a & 2) != 0)) {
            sub_080C14FC();
            DAT_0300456e = 100;
            if (DAT_03002db0 != 0) {
              DAT_03002db0 = 0;
            }
            sub_080ACFA4(3,0,&DAT_03002f70,0x40);
            sub_080ACFA4(3,0,&DAT_03002f50,0x20);
            sub_080ACFA4(3,0,&DAT_03003150,0x20);
            sub_080AABB0();
            sub_080C7848();
            sub_080AB91C(DAT_030045f8,1);
            if (DAT_03004582 == 0) {
              sub_080C7C94();
            }
            sub_080C51D4(0x66);
            goto LAB_080b5078;
          }
          if (((DAT_0300458c & 0x80) == 0) || (DAT_0200dfc8 != 1)) {
            if (((DAT_0300458c & 0x40) == 0) || (DAT_0200dfca != 1)) {
              if ((DAT_0300458a & 4) == 0) {
                if ((DAT_0300458a & 1) != 0) {
                  sub_080B5D00();
                  DAT_0300456e = 0x36;
                  MarkerHeader_DrawLocationName(0,0,0x12,0x59);
                  sub_080C51D4(0x65);
                }
              }
              else {
                DAT_03003ff0 = sub_080AB860(2,2,0x1a,8);
                DAT_0300456e = 0x35;
                sub_080C51D4(0x65);
              }
            }
            else if ((DAT_0200dfcc < 1) || (iVar2 = sub_080B4A54(), iVar2 == 1)) {
              DAT_0200dfcc = DAT_0200dfcc + 1;
              DAT_0300456e = 0x37;
              sub_080B47CC();
            }
          }
          else if ((-1 < DAT_0200dfcc) || (iVar2 = sub_080B4A54(), iVar2 == 1)) {
            DAT_0200dfcc = DAT_0200dfcc + -1;
            DAT_0300456e = 0x37;
            sub_080B47CC();
          }
        }
        else {
          if (uVar3 != 0x35) goto LAB_080b5070;
          iVar2 = sub_080AB994(DAT_03003ff0);
          if (iVar2 == 1) {
            if ((DAT_0300458a & 2) == 0) {
              if ((DAT_0200dfd0 == 0) && ((DAT_0300458a & 0x80) != 0)) {
                DAT_0200dfd0 = 1;
                sub_080C51D4(100);
              }
              else if ((DAT_0200dfd0 == 1) && ((DAT_0300458a & 0x40) != 0)) {
                DAT_0200dfd0 = 0;
                sub_080C51D4(100);
              }
            }
            else {
              sub_080AB91C(DAT_03003ff0,1);
              DAT_0300456e = 0x34;
              DAT_0200dfd0 = 0;
              sub_080C51D4(0x66);
            }
            if (DAT_0200dfd0 == 0) {
              sub_080AA184(0x8000410,0,0,0);
              if ((DAT_030031bc >> 4 & 1) == 0) {
                sub_080C4AB0(0,0,0xd6,0x48);
              }
            }
            else {
              sub_080AA184(0x8000470,0,0,0);
              if ((DAT_030031bc >> 4 & 1) == 0) {
                sub_080C4A4C(0,0,0xd6,0x14);
              }
            }
          }
        }
      }
      else {
        if (uVar3 != 0x37) {
          if (uVar3 == 200) {
            if (DAT_030045a0 == 2) {
              DAT_030045a0 = 1;
            }
            sub_080B2840(1,0,0);
            DAT_0300456e = 0xc;
            DAT_03004556 = DAT_03004552;
            Field_SetState(0x11);
            goto LAB_080b5078;
          }
          goto LAB_080b5070;
        }
        sub_080AB250(0x81b8d70,0x2000000,0,0);
        sub_080B4AA4();
        DAT_0300456e = 0x34;
        DAT_0200dfce = DAT_0200dfcc;
      }
    }
    sub_080B466C();
  }
LAB_080b5078:
                    /* WARNING: Could not recover jumptable at 0x080b507e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B5084 @ 0x080B5084

void sub_080B5084(void)

{
  sub_080C153C();
  return;
}


// sub_080B5090 @ 0x080B5090

void sub_080B5090(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x2005004;
  REG_DMA3CNT = 0x85001000;
  uVar1 = REG_DMA3CNT;
  sub_080B2880();
  return;
}


// sub_080B50C0 @ 0x080B50C0

void sub_080B50C0(void)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (DAT_0300456e == 0xe) {
    REG_DMA3SAD = 0x2000000;
    REG_DMA3DAD = 0x6003000;
    REG_DMA3CNT = 0x84000400;
    uVar1 = REG_DMA3CNT;
  }
  else if (DAT_0300456e < 0xf) {
    if (DAT_0300456e == 0xb) {
      REG_BG3CNT = 0x860b;
      DAT_0300457e = 0x22;
    }
    else if (DAT_0300456e < 0xc) {
      if (DAT_0300456e == 10) goto LAB_080b51b0;
    }
    else if (DAT_0300456e == 0xc) {
      sub_080B5090();
    }
    else if (DAT_0300456e == 0xd) {
      REG_DMA3SAD = 0x81a91b8;
      REG_DMA3DAD = 0x600bc00;
      REG_DMA3CNT = 0x84001100;
      uVar1 = REG_DMA3CNT;
      sub_080AB250(0x81b8d70,0x2000000,0,0);
    }
  }
  else if (DAT_0300456e == 0x32) {
LAB_080b51b0:
    sub_080C153C();
  }
  else if (DAT_0300456e < 0x33) {
    if (DAT_0300456e == 0x12) {
      DAT_0300456e = 0x32;
      sub_080C7864();
      goto LAB_080b51e4;
    }
  }
  else if (DAT_0300456e == 100) {
    if (DAT_0200e7e0 == 3) {
      if (DAT_03004582 == 0) {
        sub_080C7234();
        sub_080C700C();
        sub_080C7430();
      }
      goto LAB_080b51b0;
    }
    DAT_0300456e = 99;
  }
  else if (DAT_0300456e == 0x65) {
    REG_BG3CNT = 0x8607;
    sub_080ADF64();
    DAT_0300456e = 200;
    goto LAB_080b51e4;
  }
  DAT_0300456e = DAT_0300456e + 1;
LAB_080b51e4:
                    /* WARNING: Could not recover jumptable at 0x080b51ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B51F0 @ 0x080B51F0

void sub_080B51F0(int arg0)

{
  undefined4 uVar1;
  
  uVar1 = sub_080AB860(2,0xd,0x1a,7);
  *(undefined4 *)(arg0 + 0x3c) = uVar1;
  return;
}


// sub_080B5214 @ 0x080B5214

void sub_080B5214(undefined4 arg0,uint arg1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  sub_080C6E30(arg1 & 0xffff);
  if (arg1 == 1) {
    Font_ResetGlyphSpriteCache(0x100);
  }
  else {
    Font_ResetGlyphSpriteCache(0x180);
    DisplayList_Add(0x80c8441,1);
  }
                    /* WARNING: Could not recover jumptable at 0x080b5242. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B5248 @ 0x080B5248

void sub_080B5248(undefined4 arg0,uint arg1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    sub_080AA184(0x8000508,1,arg1 & 0xffff,2);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 7);
  uVar1 = 0;
  do {
    sub_080AA184(0x8000518,1,arg1 & 0xffff,2);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 3);
  return;
}


// sub_080B52C4 @ 0x080B52C4

void sub_080B52C4(int arg0)

{
  int iVar1;
  dword dVar2;
  undefined4 arg3;
  uint uVar3;
  
  iVar1 = *(int *)(arg0 + 0x24);
  if (iVar1 == 1) {
    if (*(short *)(arg0 + 0x38) == 0) {
      Text_DrawSpriteString(0x8162b1c,0,0,0x12);
    }
    else {
      dVar2 = 0x8162b56;
      arg3 = 0x12;
LAB_080b5466:
      Text_DrawSpriteString(dVar2,0,0,arg3);
    }
  }
  else {
    if (iVar1 == 0) {
      MarkerHeader_DrawLocationName(0,0,0x12,0x59);
      goto LAB_080b5498;
    }
    if (iVar1 != 2) {
      if (iVar1 == 3) {
        Text_DrawSpriteString(0x8162b76,0,0,0x12);
        sub_080B5248(arg0,2);
      }
      goto LAB_080b5498;
    }
    Text_DrawSpriteString(0x8162b34,0,0,0x12);
    sub_080AA184(0x80004ac,0,0,0);
    sub_080AA184(0x80004c4,1,0,0);
    switch(*(undefined4 *)(arg0 + 0x30)) {
    case 0:
      Text_DrawSpriteString(0x8162b8e,0,0,0x6c);
      dVar2 = 0x8162b9c;
      break;
    case 1:
      Text_DrawSpriteString(0x8162ba8,0,0,0x6c);
      dVar2 = 0x8162bbe;
      break;
    case 2:
      Text_DrawSpriteString(0x8162bd0,0,0,0x6c);
      dVar2 = 0x8162be4;
      break;
    case 3:
      Text_DrawSpriteString(0x8162bf6,0,0,0x6c);
      dVar2 = 0x8162c06;
      break;
    case 4:
      Text_DrawSpriteString(0x8162c12,0,0,0x6c);
      dVar2 = 0x8162c26;
      arg3 = 0x6c;
      goto LAB_080b5466;
    default:
      goto switchD_080b538e_default;
    }
    Text_DrawSpriteString(dVar2,0,0,0x6c);
  }
switchD_080b538e_default:
  sub_080B5248(arg0,0);
LAB_080b5498:
  sub_080AA184(0x80004f8,1,0,0);
  uVar3 = 0;
  do {
    iVar1 = uVar3 + *(int *)(arg0 + 0x2c);
    if ((ushort)(&DAT_0300580c)[iVar1 * 4] == 0xff) {
      Text_DrawSpriteString(0x8162b0c,1,0,0x12);
    }
    else {
      MarkerList_DrawLocationName
                ((uint)(ushort)(&DAT_0300580c)[iVar1 * 4],(uint)(ushort)(&DAT_0300580e)[iVar1 * 4],
                 (uint)*(byte *)(iVar1 * 8 + 0x3005808),(uint)(byte)(&DAT_03005809)[iVar1 * 8]);
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  return;
}


// sub_080B5534 @ 0x080B5534

void sub_080B5534(int arg0,uint arg1)

{
  *(uint *)(arg0 + 0x24) = arg1 & 0xffff;
  if ((arg1 & 0xffff) == 2) {
    *(undefined4 *)(arg0 + 0x30) = 0;
  }
  return;
}


// sub_080B554C @ 0x080B554C

void sub_080B554C(undefined4 arg0,uint arg1)

{
  sub_080B5534(arg0,arg1 & 0xffff);
  return;
}


// sub_080B555C @ 0x080B555C

void sub_080B555C(int arg0)

{
  uint uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_0300458a & 1) == 0) {
    if ((DAT_0300458a & 2) == 0) {
      if ((DAT_0300458c & 0x40) == 0) {
        if ((DAT_0300458c & 0x80) == 0) {
          if ((DAT_03003964 & 0x200) == 0) {
            if (((DAT_03003964 & 0x100) != 0) && (iVar2 = *(int *)(arg0 + 0x28), iVar2 != 7)) {
              uVar1 = 3U - (iVar2 - *(int *)(arg0 + 0x2c)) & 0xffff;
              if (uVar1 == 0) {
                *(undefined4 *)(arg0 + 0x28) = 7;
                *(undefined4 *)(arg0 + 0x2c) = 4;
              }
              else {
                *(uint *)(arg0 + 0x28) = iVar2 + uVar1;
              }
              sub_080C51D4(100);
            }
          }
          else {
            iVar2 = *(int *)(arg0 + 0x28);
            if (iVar2 != 0) {
              uVar1 = iVar2 - *(int *)(arg0 + 0x2c) & 0xffff;
              if (uVar1 == 0) {
                *(undefined4 *)(arg0 + 0x28) = 0;
                *(undefined4 *)(arg0 + 0x2c) = 0;
              }
              else {
                *(uint *)(arg0 + 0x28) = iVar2 - uVar1;
              }
              sub_080C51D4(100);
            }
          }
        }
        else if (*(int *)(arg0 + 0x28) != 7) {
          sub_080C51D4(100);
          iVar2 = *(int *)(arg0 + 0x28) + 1;
          *(int *)(arg0 + 0x28) = iVar2;
          if (3 < (uint)(iVar2 - *(int *)(arg0 + 0x2c))) {
            *(int *)(arg0 + 0x2c) = *(int *)(arg0 + 0x2c) + 1;
          }
        }
      }
      else if (*(int *)(arg0 + 0x28) != 0) {
        sub_080C51D4(100);
        uVar1 = *(int *)(arg0 + 0x28) - 1;
        *(uint *)(arg0 + 0x28) = uVar1;
        if (uVar1 < *(uint *)(arg0 + 0x2c)) {
          *(uint *)(arg0 + 0x2c) = *(uint *)(arg0 + 0x2c) - 1;
        }
      }
    }
    else {
      sub_080C51D4(0x66);
      *(undefined2 *)(arg0 + 0x1e) = 2;
    }
  }
  else {
    iVar2 = *(int *)(arg0 + 0x28);
    sub_080C51D4(0x65);
    if ((&DAT_0300580c)[iVar2 * 4] == 0xff) {
      *(undefined2 *)(arg0 + 0x1e) = 1;
      sub_080B5534(arg0,1);
      *(undefined2 *)(arg0 + 0x34) = 0xd;
      *(undefined2 *)(arg0 + 0x36) = 5;
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 3;
      DAT_0200dfd2 = 1;
    }
  }
  if (*(int *)(arg0 + 0x2c) != 0) {
    sub_080C4A4C(0,0,0xd6,0x6a);
  }
  if (*(int *)(arg0 + 0x2c) != 4) {
    sub_080C4AB0(0,0,0xd6,0x98);
  }
                    /* WARNING: Could not recover jumptable at 0x080b56b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B56B8 @ 0x080B56B8

void sub_080B56B8(uint arg0,uint arg1,ushort *arg2,ushort *arg3)

{
  int iVar1;
  
  iVar1 = (arg1 & 0xffff) * 0x150 + (arg0 & 0xffff) * 0xc + 0x2005000;
  *arg2 = (ushort)*(byte *)(iVar1 + 2);
  *arg3 = (ushort)*(byte *)(iVar1 + 3);
  return;
}


// sub_080B56EC @ 0x080B56EC

undefined4 sub_080B56EC(int arg0)

{
  undefined4 uVar1;
  uint uVar2;
  ushort local_14;
  ushort local_12;
  
  if (*(short *)((uint)*(ushort *)(arg0 + 0x34) * 0xc + (uint)*(ushort *)(arg0 + 0x36) * 0x150 +
                0x2005000) == 0) {
LAB_080b5714:
    uVar1 = 0;
  }
  else {
    sub_080B56B8((uint)*(ushort *)(arg0 + 0x34),(uint)*(ushort *)(arg0 + 0x36),&local_14,&local_12);
    uVar2 = 0;
    do {
      if (*(uint *)(arg0 + 0x28) != uVar2) {
        if (((((ushort)(&DAT_0300580c)[uVar2 * 4] == DAT_03004614) &&
             ((ushort)(&DAT_0300580e)[uVar2 * 4] == DAT_03004514)) &&
            (*(byte *)(uVar2 * 8 + 0x3005808) == local_14)) &&
           ((byte)(&DAT_03005809)[uVar2 * 8] == local_12)) goto LAB_080b5714;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 8);
    uVar1 = 1;
  }
  return uVar1;
}


// sub_080B577C @ 0x080B577C

void sub_080B577C(int arg0)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  Font_ResetGlyphSpriteCache(0x100);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if (*(short *)(arg0 + 0x38) == 0) {
    if ((DAT_0300458a & 1) == 0) {
      if ((DAT_0300458a & 2) == 0) {
        if ((DAT_03003964 & 0x40) == 0) {
          if ((DAT_03003964 & 0x80) == 0) {
            if ((DAT_03003964 & 0x20) == 0) {
              if (((DAT_03003964 & 0x10) != 0) && (*(short *)(arg0 + 0x34) != 0x1b)) {
                sub_080C51D4(100);
                *(short *)(arg0 + 0x34) = *(short *)(arg0 + 0x34) + 1;
              }
            }
            else if (*(short *)(arg0 + 0x34) != 0) {
              sub_080C51D4(100);
              *(short *)(arg0 + 0x34) = *(short *)(arg0 + 0x34) + -1;
            }
            goto LAB_080b5920;
          }
          if (*(short *)(arg0 + 0x36) != 10) {
            sub_080C51D4(100);
            *(short *)(arg0 + 0x36) = *(short *)(arg0 + 0x36) + 1;
            goto LAB_080b5920;
          }
          if ((DAT_0200dfc8 != 1) || ((DAT_0200dfcc < 0 && (iVar1 = sub_080B4A54(), iVar1 != 1))))
          goto LAB_080b5920;
          DAT_0200dfcc = DAT_0200dfcc + -1;
        }
        else {
          if (*(short *)(arg0 + 0x36) != 0) {
            sub_080C51D4(100);
            *(short *)(arg0 + 0x36) = *(short *)(arg0 + 0x36) + -1;
            goto LAB_080b5920;
          }
          if ((DAT_0200dfca != 1) || ((0 < DAT_0200dfcc && (iVar1 = sub_080B4A54(), iVar1 != 1))))
          goto LAB_080b5920;
          DAT_0200dfcc = DAT_0200dfcc + 1;
        }
        sub_080B47CC();
        sub_080AB250(0x81b8d70,0x2000000,0,0);
        sub_080B4AA4();
        DAT_0200dfce = DAT_0200dfcc;
        sub_080B466C();
      }
      else {
        *(undefined2 *)(arg0 + 0x1e) = 2;
        sub_080B5534(arg0,0);
        sub_080C51D4(0x66);
      }
    }
    else {
      sub_080C51D4(0x65);
      sub_080B47CC();
      iVar1 = sub_080B56EC(arg0);
      if (iVar1 == 1) {
        *(undefined2 *)(arg0 + 0x1e) = 1;
        uVar2 = sub_080ABCD4(0xd,0,0x10,5);
        *(undefined4 *)(arg0 + 0x40) = uVar2;
        uVar2 = sub_080ABCD4(2,1,10,9);
        *(undefined4 *)(arg0 + 0x44) = uVar2;
      }
      else {
        *(undefined2 *)(arg0 + 0x38) = 1;
      }
    }
  }
  else if (((DAT_0300458a & 1) != 0) || ((DAT_0300458a & 2) != 0)) {
    *(undefined2 *)(arg0 + 0x38) = 0;
  }
LAB_080b5920:
                    /* WARNING: Could not recover jumptable at 0x080b5926. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B592C @ 0x080B592C

void sub_080B592C(int arg0)

{
  int iVar1;
  int iVar2;
  undefined1 local_10 [2];
  undefined1 local_e [2];
  
  sub_080B56B8((uint)*(ushort *)(arg0 + 0x34),(uint)*(ushort *)(arg0 + 0x36),local_10,local_e);
  iVar1 = *(int *)(arg0 + 0x28);
  iVar2 = iVar1 * 8;
  *(undefined1 *)(iVar2 + 0x3005808) = local_10[0];
  (&DAT_03005809)[iVar2] = local_e[0];
  (&DAT_0300580c)[iVar1 * 4] = (short)DAT_03004614;
  (&DAT_0300580e)[iVar1 * 4] = (short)DAT_03004514;
  (&DAT_0300580b)[iVar2] = (char)*(undefined4 *)(arg0 + 0x30);
  return;
}


// sub_080B597C @ 0x080B597C

void sub_080B597C(int arg0)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(arg0 + 0x28);
  iVar2 = iVar1 * 8;
  *(undefined1 *)(iVar2 + 0x3005808) = 0;
  (&DAT_03005809)[iVar2] = 0;
  (&DAT_0300580c)[iVar1 * 4] = 0xff;
  (&DAT_0300580b)[iVar2] = 0;
  return;
}


// sub_080B5998 @ 0x080B5998

void sub_080B5998(int arg0)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  Font_ResetGlyphSpriteCache(0x100);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  if ((DAT_0300458a & 1) == 0) {
    if ((DAT_0300458a & 2) == 0) {
      if ((DAT_0300458c & 0x40) == 0) {
        if (((DAT_0300458c & 0x80) == 0) || (*(int *)(arg0 + 0x30) == 4)) goto LAB_080b5a46;
        sub_080C51D4(100);
        iVar1 = *(int *)(arg0 + 0x30) + 1;
      }
      else {
        if (*(int *)(arg0 + 0x30) == 0) goto LAB_080b5a46;
        sub_080C51D4(100);
        iVar1 = *(int *)(arg0 + 0x30) + -1;
      }
      *(int *)(arg0 + 0x30) = iVar1;
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 2;
      sub_080B5534(arg0,1);
      sub_080C51D4(0x66);
      if (*(int *)(arg0 + 0x40) != 0) {
        sub_080ABD30(*(int *)(arg0 + 0x40),1);
      }
      if (*(int *)(arg0 + 0x44) != 0) {
        sub_080ABD30(*(int *)(arg0 + 0x44),1);
      }
    }
  }
  else {
    *(undefined2 *)(arg0 + 0x1e) = 1;
    sub_080B5534(arg0,0);
    sub_080B592C(arg0);
    sub_080C51D4(0x65);
  }
LAB_080b5a46:
                    /* WARNING: Could not recover jumptable at 0x080b5a4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B5A4C @ 0x080B5A4C

void sub_080B5A4C(int arg0)

{
  int iVar1;
  
  Font_ResetGlyphSpriteCache(0x100);
  *(undefined2 *)(arg0 + 0x1e) = 0;
  iVar1 = sub_080ABF04(*(undefined4 *)(arg0 + 0x48));
  if (iVar1 == 1) {
    if (DAT_030031cc == 0) {
      *(undefined2 *)(arg0 + 0x1e) = 1;
      sub_080B597C(arg0);
    }
    else {
      *(undefined2 *)(arg0 + 0x1e) = 1;
    }
    DAT_0200dfcc = 0;
    DAT_0200dfce = 0;
    *(undefined2 *)(arg0 + 0x54) = 0;
    *(undefined2 *)(arg0 + 0x56) = 0;
  }
  return;
}


// sub_080B5AA4 @ 0x080B5AA4

void sub_080B5AA4(int arg0,undefined4 arg1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  ushort local_2c;
  ushort local_2a;
  ushort local_28;
  ushort local_26;
  ushort local_24;
  ushort local_22;
  
  iVar1 = *(int *)(arg0 + 0x28);
  iVar2 = iVar1 * 8;
  pbVar4 = (byte *)(iVar2 + 0x3005808);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  switch(arg1) {
  case 0:
    DAT_03003ffc = 1;
    *(undefined2 *)(arg0 + 0x1c) = 1;
    break;
  case 1:
  case 4:
    sub_080C14FC();
    DisplayList_Add(0x80c153d,1);
    break;
  case 2:
    *(short *)(arg0 + 0x4c) = (short)DAT_03004614;
    *(short *)(arg0 + 0x4e) = (short)DAT_03004514;
    *(ushort *)(arg0 + 0x50) = DAT_03004562;
    *(ushort *)(arg0 + 0x52) = DAT_03004564;
    *(undefined2 *)(arg0 + 0x54) = DAT_0200dfcc;
    *(undefined2 *)(arg0 + 0x56) = DAT_0200dfce;
    DAT_0200dfcc = 0;
    DAT_0200dfce = 0;
    DAT_03004614 = (uint)(ushort)(&DAT_0300580c)[iVar1 * 4];
    DAT_03004514 = (uint)(ushort)(&DAT_0300580e)[iVar1 * 4];
    DAT_03004562 = (ushort)*pbVar4;
    DAT_03004564 = (ushort)(byte)(&DAT_03005809)[iVar2];
    sub_080AE234();
    sub_080B449C((uint)*pbVar4,(uint)(byte)(&DAT_03005809)[iVar2],&local_2c,&local_2a);
    *(ushort *)(arg0 + 0x34) = local_2c >> 3;
    *(ushort *)(arg0 + 0x36) = local_2a >> 3;
    sub_080B47CC();
    sub_080B4AA4();
    sub_080B5534(arg0,3);
    sub_080B449C((uint)*pbVar4,(uint)(byte)(&DAT_03005809)[iVar2],&local_28,&local_26);
    *(ushort *)(arg0 + 0x34) = local_28 >> 3;
    *(ushort *)(arg0 + 0x36) = local_26 >> 3;
    DAT_03003ffc = 2;
    uVar3 = sub_080ABEE0(0,0x3f7);
    *(undefined4 *)(arg0 + 0x48) = uVar3;
    break;
  case 3:
    DAT_03003ffc = 1;
    break;
  case 5:
    DAT_0200dfd2 = 0;
    DAT_03004614 = (uint)*(ushort *)(arg0 + 0x4c);
    DAT_03004514 = (uint)*(ushort *)(arg0 + 0x4e);
    DAT_03004562 = *(ushort *)(arg0 + 0x50);
    DAT_03004564 = *(ushort *)(arg0 + 0x52);
    DAT_0200dfcc = *(undefined2 *)(arg0 + 0x54);
    DAT_0200dfce = *(undefined2 *)(arg0 + 0x56);
    DAT_03003ffc = 0;
    sub_080AE234();
    sub_080B449C((uint)*pbVar4,(uint)(byte)(&DAT_03005809)[iVar2],&local_24,&local_22);
    *(ushort *)(arg0 + 0x34) = local_24 >> 3;
    *(ushort *)(arg0 + 0x36) = local_22 >> 3;
    if (DAT_03004614 == 0x42) {
      DAT_030045a0 = 2;
    }
    sub_080AB250(0x81b8d70,0x2000000,0,0);
    sub_080B47CC();
    sub_080B4AA4();
  }
  return;
}


// sub_080B5CA8 @ 0x080B5CA8

void sub_080B5CA8(int arg0)

{
  if (*(int *)(arg0 + 0x3c) != 0) {
    sub_080AB91C(*(int *)(arg0 + 0x3c),1);
  }
  if (*(int *)(arg0 + 0x40) != 0) {
    sub_080ABD30(*(int *)(arg0 + 0x40),1);
  }
  if (*(int *)(arg0 + 0x44) != 0) {
    sub_080ABD30(*(int *)(arg0 + 0x44),1);
  }
  return;
}


// sub_080B5CD8 @ 0x080B5CD8

void sub_080B5CD8(void)

{
  DAT_0300456e = 0x34;
  return;
}


// sub_080B5CE4 @ 0x080B5CE4

void sub_080B5CE4(void)

{
  MarkerHeader_DrawLocationName(0,0,0x12,0x59);
  return;
}


// sub_080B5D00 @ 0x080B5D00

void sub_080B5D00(void)

{
  sub_080AD0FC(0x8162c34,0xffff);
  return;
}


// sub_080B5D18 @ 0x080B5D18

void sub_080B5D18(void)

{
  sub_080B31C4((uint)(ushort)DAT_03004614,10,(uint)*(ushort *)(DAT_03004000 + 2));
  return;
}


// sub_080B5D38 @ 0x080B5D38

void sub_080B5D38(void)

{
  sub_080B2840(0,0,0);
  return;
}


// sub_080B5D48 @ 0x080B5D48

void sub_080B5D48(int arg0)

{
  int iVar1;
  undefined4 arg0_00;
  int iVar2;
  bool bVar3;
  
  iVar1 = sub_080C8B10(DAT_03004614 & 0xffff,DAT_03004514 & 0xffff);
  DAT_0300000e = 0;
  arg0_00 = sub_080B2EFC(0,0);
  iVar2 = sub_080B3038(arg0_00,0x20);
  if (iVar2 != 0) {
    DAT_030050f8 = *(ushort *)(iVar2 + 2);
    DAT_03003bb4 = 0;
  }
  bVar3 = DAT_03003bb4 == *(int *)(iVar1 + 0xd8 + (uint)DAT_030050f8 * 0xe8);
  if (!bVar3) {
    sub_080ADCCC(DAT_03004614,DAT_03004514);
    sub_080AE234();
    sub_080AD7F0();
  }
  *(ushort *)(arg0 + 0x1c) = (ushort)bVar3;
  return;
}


// sub_080B5DD8 @ 0x080B5DD8

void sub_080B5DD8(int arg0)

{
  bool bVar1;
  
  bVar1 = DAT_0300455e == 0;
  if (bVar1) {
    sub_080AE494();
  }
  *(ushort *)(arg0 + 0x1c) = (ushort)bVar1;
  return;
}


// sub_080B5E04 @ 0x080B5E04

void sub_080B5E04(void)

{
  Field_SetState(1);
  return;
}


// sub_080B5E10 @ 0x080B5E10

void sub_080B5E10(undefined4 arg0,int arg1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 1) {
    sub_080C2364(0x102);
  }
  else {
    sub_080C23BC(0x102);
  }
                    /* WARNING: Could not recover jumptable at 0x080b5e2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B5E2C @ 0x080B5E2C

void sub_080B5E2C(void)

{
  undefined4 arg0;
  int iVar1;
  
  arg0 = sub_080B2EFC(0,0);
  iVar1 = sub_080B3038(arg0,9);
  if (iVar1 == 0) {
    sub_080B02A0((uint)DAT_03004552);
  }
  return;
}


// sub_080B5E50 @ 0x080B5E50

void sub_080B5E50(void)

{
  DAT_03003fec = sub_080AD0FC(0x8162eac,0xffff);
  Field_SetState(0x1a);
  return;
}


// sub_080B5E74 @ 0x080B5E74

void sub_080B5E74(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 local_c [4];
  
  uVar2 = (uint)(DAT_0300000e >> 3) * -0x400 + 0x3400;
  if (uVar2 != 0) {
    REG_DMA3SAD = local_c;
    REG_DMA3DAD = 0x6008800;
    REG_DMA3CNT = 0x85000d00;
    uVar1 = REG_DMA3CNT;
    REG_DMA3SAD = (uint)(DAT_0300000e >> 3) * 0x400 + 0x2005004;
    REG_DMA3DAD = 0x6008800;
    REG_DMA3CNT = uVar2 >> 2 | 0x84000000;
    uVar1 = REG_DMA3CNT;
  }
  return;
}


// sub_080B5ED0 @ 0x080B5ED0

void sub_080B5ED0(void)

{
  sub_080AE494();
  DAT_0300000e = DAT_0300000e + 8;
  return;
}


// sub_080B5EEC @ 0x080B5EEC

void sub_080B5EEC(void)

{
  sub_080ADCCC(DAT_03004614,DAT_03004514);
  sub_080AE234();
  sub_080AE294();
  sub_080B31C4(DAT_03004614 & 0xffff,1,(uint)*(ushort *)(DAT_03004000 + 4));
  return;
}


// sub_080B5F24 @ 0x080B5F24

void sub_080B5F24(void)

{
  sub_080B2840(0,0,0);
  DAT_0300000e = 0;
  DAT_03003bbc = 0;
  return;
}


// sub_080B5F48 @ 0x080B5F48

void sub_080B5F48(int arg0)

{
  DisplayList_Add(0x80ae0bd,1);
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_03003bbc == -1);
  return;
}


// sub_080B5F7C @ 0x080B5F7C

void sub_080B5F7C(int arg0)

{
  bool bVar1;
  
  bVar1 = DAT_0300455e == 0;
  if (bVar1) {
    sub_080AE494();
  }
  *(ushort *)(arg0 + 0x1c) = (ushort)bVar1;
  return;
}


// sub_080B5FA8 @ 0x080B5FA8

void sub_080B5FA8(void)

{
  Field_SetState(1);
  return;
}


// sub_080B5FB4 @ 0x080B5FB4

void sub_080B5FB4(void)

{
  undefined4 arg0;
  int iVar1;
  
  arg0 = sub_080B2EFC(0,0);
  iVar1 = sub_080B3038(arg0,2);
  if (iVar1 == 0) {
    sub_080B02A0((uint)DAT_03004552);
  }
  return;
}


// sub_080B5FD8 @ 0x080B5FD8

void sub_080B5FD8(void)

{
  DAT_03003fec = sub_080AD0FC(0x8163060,0xffff);
  Field_SetState(0x1a);
  return;
}


// sub_080B5FFC @ 0x080B5FFC

void sub_080B5FFC(int arg0,int arg1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (arg1 == 0) {
    uVar2 = (uint)DAT_03004552;
    uVar1 = sub_080AC468();
    uVar1 = (uint)*(ushort *)((uVar1 & 3) * 2 + 0x8163250);
    if (*(short *)(DAT_03004000 + 2) == 0) {
      uVar2 = uVar2 + uVar1 & 3;
      sub_080C51D4(0x72);
    }
    else {
      uVar2 = (uint)(ushort)(*(short *)(DAT_03004000 + 2) - 1);
      uVar1 = (uint)*(ushort *)(uVar2 * 2 + (uint)DAT_03004552 * 8 + 0x8163258);
    }
    sub_080B2064(uVar2,uVar1);
  }
  else {
    bVar3 = DAT_03004552 == DAT_03004556;
    if (!bVar3) {
      sub_080B2064((uint)DAT_03004556,(uint)DAT_03004558);
    }
    *(ushort *)(arg0 + 0x1c) = (ushort)bVar3;
  }
  return;
}


// sub_080B6088 @ 0x080B6088

void sub_080B6088(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080B2090();
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (iVar1 != -1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080B60A4 @ 0x080B60A4

void sub_080B60A4(int arg0)

{
  undefined2 uVar1;
  undefined4 arg0_00;
  int iVar2;
  int arg0_01;
  
  arg0_00 = sub_080B2EFC(0,0);
  iVar2 = sub_080B3038(arg0_00,0x19);
  arg0_01 = sub_080B3038(arg0_00,0x14);
  if (iVar2 == 0) {
    uVar1 = 0;
    if (arg0_01 == 0) goto LAB_080b60f8;
    DAT_03003fec = sub_080B8994(arg0_01);
    Field_SetState(0x1a);
  }
  else {
    DAT_0300458a = 0;
    DAT_03004588 = 0x40;
    DAT_0300458c = 0;
    sub_080B1C18(0x40);
  }
  uVar1 = 1;
LAB_080b60f8:
  *(undefined2 *)(arg0 + 0x1c) = uVar1;
  return;
}


// sub_080B6104 @ 0x080B6104

void sub_080B6104(void)

{
  Field_SetState(1);
  return;
}


// sub_080B6110 @ 0x080B6110

void sub_080B6110(void)

{
  sub_080B2840(0,0,0);
  return;
}


// sub_080B6120 @ 0x080B6120

void sub_080B6120(int arg0)

{
  bool bVar1;
  
  bVar1 = DAT_0300455e == 0;
  if (bVar1) {
    sub_080AE494();
  }
  *(ushort *)(arg0 + 0x1c) = (ushort)bVar1;
  return;
}


// sub_080B614C @ 0x080B614C

void sub_080B614C(void)

{
  DAT_03003fec = sub_080AD0FC(0x8163278,0xffff);
  Field_SetState(0x1a);
  return;
}


// sub_080B6170 @ 0x080B6170

dword sub_080B6170(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 arg0;
  int iVar5;
  dword dVar6;
  
  uVar4 = DAT_03004568;
  uVar3 = DAT_03004566;
  uVar2 = DAT_03004564;
  uVar1 = DAT_03004562;
  dVar6 = 0xffff;
  arg0 = sub_080B2EFC(0,0);
  iVar5 = sub_080B3038(arg0,0x28);
  if (iVar5 != 0) {
    dVar6 = (dword)*(ushort *)(iVar5 + 2);
    goto LAB_080b61d0;
  }
  if (uVar1 == uVar3) {
    if (uVar2 < uVar4) {
      dVar6 = 0;
      goto LAB_080b61d0;
    }
    if (uVar4 < uVar2) {
      dVar6 = 2;
      goto LAB_080b61d0;
    }
  }
  if ((uVar1 < uVar3) && (uVar2 == uVar4)) {
    dVar6 = 3;
  }
  else if ((uVar3 < uVar1) && (uVar2 == uVar4)) {
    dVar6 = 1;
  }
LAB_080b61d0:
  if (DAT_03004552 == dVar6) {
    dVar6 = 0xffff;
  }
  return dVar6;
}


// sub_080B61F0 @ 0x080B61F0

void sub_080B61F0(int arg0,int arg1)

{
  ushort uVar1;
  uint uVar2;
  
  *(undefined2 *)(arg0 + 0x1c) = 1;
  if (arg1 == 0) {
    uVar2 = sub_080B6170();
    uVar2 = uVar2 & 0xffff;
    if (uVar2 == 0xffff) {
      return;
    }
    uVar1 = *(ushort *)(uVar2 * 2 + (uint)DAT_03004552 * 8 + 0x8163258);
  }
  else {
    if (DAT_03004552 == DAT_03004556) {
      *(undefined2 *)(arg0 + 0x1c) = 1;
      return;
    }
    uVar2 = (uint)DAT_03004556;
    uVar1 = DAT_03004558;
  }
  sub_080B2064(uVar2,(uint)uVar1);
  *(undefined2 *)(arg0 + 0x1c) = 0;
  return;
}


// sub_080B6250 @ 0x080B6250

void sub_080B6250(int arg0)

{
  int iVar1;
  
  iVar1 = sub_080B2090();
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (iVar1 != -1) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080B626C @ 0x080B626C

void sub_080B626C(void)

{
  Field_SetState(0x13);
  sub_080C7218();
  sub_080C7414();
  DAT_0300456e = 0;
  return;
}


// sub_080B628C @ 0x080B628C

void sub_080B628C(void)

{
  DAT_03003fec = sub_080AD0FC(0x816336c,0xffff);
  Field_SetState(0x1a);
  return;
}


// sub_080B62B0 @ 0x080B62B0

void sub_080B62B0(int arg0)

{
  undefined4 local_14;
  
  sub_080C7218();
  sub_080C7414();
  DAT_0300456e = 0;
  DAT_03004530 = (uint)*(ushort *)(arg0 + 0x24);
  local_14 = 0;
  CpuSet(&local_14,0x2036094,0x5000008);
  DAT_0203db7a = 0;
  sub_080AF060(*(undefined4 *)(arg0 + 0x28));
  Field_SetState(0x19);
  return;
}


// sub_080B6308 @ 0x080B6308

void sub_080B6308(undefined4 arg0,undefined4 arg1)

{
  int iVar1;
  
  iVar1 = sub_080AD0FC(0x81633d8,0xffff);
  DAT_03003fec = iVar1;
  *(undefined2 *)(iVar1 + 0x24) = (undefined2)arg0;
  *(undefined4 *)(iVar1 + 0x28) = arg1;
  Field_SetState(0x1a);
  return;
}


// sub_080B633C @ 0x080B633C

void sub_080B633C(void)

{
  return;
}


// sub_080B6340 @ 0x080B6340

void sub_080B6340(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x203a2e4;
  REG_DMA3DAD = 0x6012f00;
  REG_DMA3CNT = 0x84000040;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B6364 @ 0x080B6364

void sub_080B6364(int arg0)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  pbVar4 = (byte *)((uint)*(ushort *)(arg0 + 0x24) * 10 + 0x8163444);
  puVar3 = (undefined4 *)0x203a2e4;
  if (*pbVar4 != 0x20) {
    do {
      uVar1 = (uint)*pbVar4;
      if (uVar1 == 0x28) {
        puVar2 = (undefined4 *)0x81ae018;
      }
      else {
        puVar2 = (undefined4 *)&UNK_081ae038;
        if ((uVar1 != 0x29) && (puVar2 = (undefined4 *)&UNK_081ade38, uVar1 != 0x27)) {
          if (uVar1 == 0x26) {
            puVar2 = (undefined4 *)&UNK_081ad838;
          }
          else if (uVar1 == 0x5f) {
            puVar2 = (undefined4 *)&UNK_081ad7b8;
          }
          else {
            puVar2 = (undefined4 *)(&UNK_081ada98 + (uVar1 - 0x41) * 0x20);
          }
        }
      }
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      puVar3[2] = puVar2[2];
      puVar3[3] = puVar2[3];
      puVar3[4] = puVar2[4];
      puVar3[5] = puVar2[5];
      puVar3[6] = puVar2[6];
      puVar3[7] = puVar2[7];
      puVar3 = puVar3 + 8;
      pbVar4 = pbVar4 + 1;
    } while (*pbVar4 != 0x20);
  }
  sub_080AB250(0x81635b6,0x200dfd4,0,0);
  DisplayList_Add(0x80b6341,1);
  sub_080C6764();
                    /* WARNING: Could not recover jumptable at 0x080b6458. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B6460 @ 0x080B6460

void sub_080B6460(int arg0)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  uint uVar4;
  
  pcVar3 = (char *)((uint)*(ushort *)(arg0 + 0x24) * 10 + 0x8163444);
  sVar2 = *(short *)(arg0 + 0x28) + -1;
  *(short *)(arg0 + 0x28) = sVar2;
  if (sVar2 == 0) {
    *(undefined2 *)(arg0 + 0x28) = 4;
    if (*(short *)(arg0 + 0x26) != 10) {
      *(short *)(arg0 + 0x26) = *(short *)(arg0 + 0x26) + 1;
    }
  }
  cVar1 = *pcVar3;
  while (cVar1 != ' ') {
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
  }
  pcVar3 = (char *)((uint)*(ushort *)(arg0 + 0x24) * 10 + 0x8163444);
  uVar4 = 0;
  if (*(short *)(arg0 + 0x26) != 0) {
    cVar1 = *pcVar3;
    while (cVar1 != ' ') {
      sub_080AA1F4(0x8163638,0,0,0);
      uVar4 = uVar4 + 1;
      pcVar3 = pcVar3 + 1;
      if (*(ushort *)(arg0 + 0x26) <= uVar4) break;
      cVar1 = *pcVar3;
    }
  }
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_03004550 != 1);
  return;
}


// sub_080B6528 @ 0x080B6528

void sub_080B6528(int arg0)

{
  *(ushort *)(arg0 + 0x1c) = (ushort)(DAT_03004550 == 1);
  return;
}


// sub_080B6540 @ 0x080B6540

void sub_080B6540(void)

{
  sub_080AB438(0,0x200dfd4,10,2);
  sub_080C6764();
  return;
}


// sub_080B6568 @ 0x080B6568

void sub_080B6568(undefined4 arg0)

{
  undefined4 uVar1;
  undefined1 auStack_c [4];
  
  if (*(char *)((uint)(ushort)arg0 * 10 + 0x8163444) != '?') {
    DAT_0203a3e4 = sub_080AD0FC(0x8163640,0xffff);
    REG_DMA3SAD = auStack_c;
    REG_DMA3DAD = 0x203a2e4;
    REG_DMA3CNT = 0x85000040;
    uVar1 = REG_DMA3CNT;
    *(ushort *)(DAT_0203a3e4 + 0x24) = (ushort)arg0;
    *(undefined2 *)(DAT_0203a3e4 + 0x26) = 0;
    *(undefined2 *)(DAT_0203a3e4 + 0x28) = 1;
  }
  return;
}


// sub_080B65D0 @ 0x080B65D0

void sub_080B65D0(int arg0,int arg1)

{
  undefined4 uVar1;
  
  if (arg1 == 0) {
    REG_DMA3SAD = 0x3002db0;
    REG_DMA3DAD = 0x201b874;
    REG_DMA3CNT = 0x84000100;
    uVar1 = REG_DMA3CNT;
  }
  DAT_0200e808 = 1;
  uVar1 = sub_080AAF48(1);
  *(undefined4 *)(arg0 + 0x28) = uVar1;
  return;
}


// sub_080B6614 @ 0x080B6614

void sub_080B6614(int arg0)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 local_c [4];
  
  uVar2 = sub_080AB178(*(undefined4 *)(arg0 + 0x28));
  if ((uVar2 & 0xffff) == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    REG_DMA3SAD = local_c;
    REG_DMA3DAD = 0x2000000;
    REG_DMA3CNT = 0x81000800;
    uVar1 = REG_DMA3CNT;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  return;
}


// sub_080B6658 @ 0x080B6658

void sub_080B6658(int arg0,int arg1)

{
  undefined4 uVar1;
  undefined1 auStack_4c [64];
  
  uVar1 = sub_080AAEDC(1);
  *(undefined4 *)(arg0 + 0x28) = uVar1;
  if (arg1 == 0) {
    CpuSet(0x3002d70,auStack_4c,0x4000010);
    sub_080C1384();
    CpuSet(auStack_4c,0x3002d70,0x4000010);
  }
  else {
    DAT_0200e80a = 0;
  }
  return;
}


// sub_080B66A8 @ 0x080B66A8

void sub_080B66A8(int arg0)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = sub_080AB178(*(undefined4 *)(arg0 + 0x28));
  *(ushort *)(arg0 + 0x1c) = (ushort)((uVar1 & 0xffff) == 0);
                    /* WARNING: Could not recover jumptable at 0x080b66c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B66C8 @ 0x080B66C8

void sub_080B66C8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x6000000;
  REG_DMA3DAD = 0x2017874;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B66F8 @ 0x080B66F8

void sub_080B66F8(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x6001000;
  REG_DMA3DAD = 0x2018874;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B6728 @ 0x080B6728

void sub_080B6728(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x6002000;
  REG_DMA3DAD = 0x2019874;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6002000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B6758 @ 0x080B6758

void sub_080B6758(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2000000;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  REG_BG3CNT = 0x860b;
  return;
}


// sub_080B6788 @ 0x080B6788

void sub_080B6788(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x6003000;
  REG_DMA3DAD = 0x201a874;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  sub_080B6758();
  return;
}


// sub_080B67B4 @ 0x080B67B4

void sub_080B67B4(undefined4 arg0,int arg1)

{
  dword arg0_00;
  code *UNRECOVERED_JUMPTABLE;
  
  if (arg1 == 1) {
    arg0_00 = 0x80b66f9;
  }
  else if (arg1 == 0) {
    arg0_00 = 0x80b66c9;
  }
  else {
    if (arg1 != 2) {
      if (arg1 == 3) {
        DisplayList_Add(0x80b6789,1);
      }
      goto LAB_080b67f0;
    }
    arg0_00 = 0x80b6729;
  }
  DisplayList_Add(arg0_00,1);
LAB_080b67f0:
                    /* WARNING: Could not recover jumptable at 0x080b67f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// sub_080B67F8 @ 0x080B67F8

void sub_080B67F8(int arg0,int arg1)

{
  dword dVar1;
  
  if (arg1 == 0) {
    if (*(int *)(arg0 + 0x2c) == 0) {
      dVar1 = 0x81b8870;
    }
    else {
      dVar1 = 0x81636e8;
    }
    REG_DMA3SAD = dVar1;
    REG_DMA3DAD = 0x2000000;
    REG_DMA3CNT = 0x84000140;
    DisplayList_Add(0x80b6759,1);
  }
  DAT_0200e80a = 1;
  return;
}


// sub_080B6850 @ 0x080B6850

void sub_080B6850(undefined4 arg0,int arg1)

{
  if (arg1 == 0) {
    sub_080AD7F0();
  }
  return;
}


// sub_080B6860 @ 0x080B6860

void sub_080B6860(int arg0,int arg1)

{
  *(undefined2 *)(arg0 + 0x1c) = 0;
  if (arg1 == 0) {
    if (0xe < DAT_03003ff8) {
      DisplayList_Add(0x80c1451,1);
      *(undefined2 *)(arg0 + 0x1c) = 1;
    }
  }
  else if (DAT_0300455e == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 1;
    sub_080AE494();
  }
  return;
}


// sub_080B68AC @ 0x080B68AC

void sub_080B68AC(int arg0)

{
  if ((DAT_0200ab04 & 0x8000) == 0) {
    *(undefined2 *)(arg0 + 0x1c) = 0;
  }
  else {
    *(undefined2 *)(arg0 + 0x1c) = 1;
  }
  return;
}


// sub_080B68D0 @ 0x080B68D0

void sub_080B68D0(int arg0,undefined4 arg1)

{
  dword arg0_00;
  
  *(undefined2 *)(arg0 + 0x1c) = 0;
  switch(arg1) {
  case 0:
    sub_080C14FC();
    sub_080AB438(0,0x2000000,1,0);
    arg0_00 = 0x80b3e7d;
    break;
  case 1:
    arg0_00 = 0x80b3e8d;
    break;
  case 2:
    if (DAT_03003bac != -1) {
      sub_080B3C5C(0);
      return;
    }
    DisplayList_Add(0x80b3ea1,1);
    *(undefined2 *)(arg0 + 0x1c) = 1;
    return;
  case 3:
    arg0_00 = 0x80b3ed1;
    break;
  case 4:
    arg0_00 = 0x80b3f1d;
    break;
  case 5:
    DisplayList_Add(0x80b41b1,1);
  default:
    goto switchD_080b68e6_default;
  }
  DisplayList_Add(arg0_00,1);
switchD_080b68e6_default:
  return;
}


// sub_080B698C @ 0x080B698C

void sub_080B698C(void)

{
  undefined4 uVar1;
  
  sub_080C8440();
  REG_DMA3SAD = 0x2017874;
  REG_DMA3DAD = 0x6000000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  REG_DMA3SAD = 0x201b874;
  REG_DMA3DAD = 0x30029b0;
  REG_DMA3CNT = 0x84000100;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B69D0 @ 0x080B69D0

void sub_080B69D0(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x2018874;
  REG_DMA3DAD = 0x6001000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B69F4 @ 0x080B69F4

void sub_080B69F4(void)

{
  undefined4 uVar1;
  undefined1 local_8 [8];
  
  sub_080C153C();
  REG_DMA3SAD = local_8;
  REG_DMA3DAD = 0x6008000;
  REG_DMA3CNT = 0x85000008;
  uVar1 = REG_DMA3CNT;
  return;
}


// sub_080B6A24 @ 0x080B6A24

void sub_080B6A24(void)

{
  undefined4 uVar1;
  
  REG_DMA3SAD = 0x201a874;
  REG_DMA3DAD = 0x6003000;
  REG_DMA3CNT = 0x84000200;
  uVar1 = REG_DMA3CNT;
  sub_080C1450();
  return;
}


// sub_080B6A50 @ 0x080B6A50

void sub_080B6A50(undefined4 arg0,undefined4 arg1)

{
  undefined4 uVar1;
  dword arg0_00;
  undefined4 local_8 [2];
  
  switch(arg1) {
  case 0:
    arg0_00 = 0x80b698d;
    break;
  case 1:
    arg0_00 = 0x80b69d1;
    break;
  case 2:
    DisplayList_Add(0x80b69f5,1);
    sub_080C14FC();
    return;
  case 3:
    arg0_00 = 0x80b6a25;
    break;
  case 4:
    local_8[0] = 0;
    REG_DMA3SAD = local_8;
    REG_DMA3DAD = 0x6008000;
    REG_DMA3CNT = 0x85000f00;
    uVar1 = REG_DMA3CNT;
    REG_DMA3SAD = 0x81a91b8;
    REG_DMA3DAD = 0x600bc00;
    REG_DMA3CNT = 0x84001100;
    uVar1 = REG_DMA3CNT;
    if (DAT_0200e804 == 0) {
      sub_080C6558();
    }
  default:
    goto switchD_080b6a60_default;
  }
  DisplayList_Add(arg0_00,1);
switchD_080b6a60_default:
  return;
}


// sub_080B6B00 @ 0x080B6B00

void sub_080B6B00(void)

{
  if (DAT_03004598 == 2) {
    DAT_03004598 = 1;
  }
  if (DAT_0300459c == 2) {
    DAT_0300459c = 1;
  }
  if (DAT_030045a0 == 2) {
    DAT_030045a0 = 1;
  }
  return;
}


// sub_080B6B34 @ 0x080B6B34

void sub_080B6B34(int arg0)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (*(int *)(arg0 + 0x24) == 0) {
    Field_SetState(1);
  }
  else {
    _call_via_r0(*(int *)(arg0 + 0x24));
  }
  DAT_0200e808 = 0;
                    /* WARNING: Could not recover jumptable at 0x080b6b50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


