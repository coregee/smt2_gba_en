/* Ghidra decompilation of asm/crt0.s (reference only; not compiled). */

// Start @ 0x080000C0

void Start(void)

{
  do {
    DAT_03007ffc = IntrMain;
    AgbMain();
  } while( true );
}


// IntrMain @ 0x080000FC

void IntrMain(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  uVar2 = REG_IE;
  uVar2 = uVar2 & uVar2 >> 0x10;
  bVar4 = (uVar2 & 0x2000) != 0;
  if (bVar4) {
    REG_SOUNDCNT_X._0_1_ = 0;
  }
  do {
  } while (bVar4);
  iVar3 = 0;
  uVar1 = (ushort)(uVar2 & 1);
  if ((uVar2 & 1) == 0) {
    iVar3 = 4;
    uVar1 = (ushort)(uVar2 & 2);
    if ((uVar2 & 2) == 0) {
      iVar3 = 8;
      uVar1 = (ushort)(uVar2 & 4);
      if ((uVar2 & 4) == 0) {
        iVar3 = 0xc;
        uVar1 = (ushort)(uVar2 & 8);
        if ((uVar2 & 8) == 0) {
          iVar3 = 0x10;
          uVar1 = (ushort)(uVar2 & 0x10);
          if ((uVar2 & 0x10) == 0) {
            iVar3 = 0x14;
            uVar1 = (ushort)(uVar2 & 0x20);
            if ((uVar2 & 0x20) == 0) {
              iVar3 = 0x18;
              uVar1 = (ushort)(uVar2 & 0x40);
              if ((uVar2 & 0x40) == 0) {
                iVar3 = 0x1c;
                uVar1 = (ushort)(uVar2 & 0x80);
                if ((uVar2 & 0x80) == 0) {
                  iVar3 = 0x20;
                  uVar1 = (ushort)(uVar2 & 0x100);
                  if ((uVar2 & 0x100) == 0) {
                    iVar3 = 0x24;
                    uVar1 = (ushort)(uVar2 & 0x200);
                    if ((uVar2 & 0x200) == 0) {
                      iVar3 = 0x28;
                      uVar1 = (ushort)(uVar2 & 0x400);
                      if ((uVar2 & 0x400) == 0) {
                        iVar3 = 0x2c;
                        uVar1 = (ushort)(uVar2 & 0x800);
                        if ((uVar2 & 0x800) == 0) {
                          iVar3 = 0x30;
                          uVar1 = (ushort)uVar2 & 0x1000;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  REG_IE._2_2_ = uVar1;
                    /* WARNING: Could not recover jumptable at 0x080001c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar3 + 0x30020f0))();
  return;
}


