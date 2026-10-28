	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start MPlayExtender
MPlayExtender: @ 0x080E325C
.L080E325C:
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L080E3324
	movs r0, #0x8f
	strh r0, [r1]
	ldr r3, .L080E3328
	movs r2, #0
	strh r2, [r3]
	ldr r0, .L080E332C
	movs r1, #8
	strb r1, [r0]
	adds r0, #6
	strb r1, [r0]
	adds r0, #0x10
	strb r1, [r0]
	subs r0, #0x14
	movs r1, #0x80
	strb r1, [r0]
	adds r0, #8
	strb r1, [r0]
	adds r0, #0x10
	strb r1, [r0]
	subs r0, #0xd
	strb r2, [r0]
	movs r0, #0x77
	strb r0, [r3]
	ldr r0, .L080E3330
	ldr r4, [r0]
	ldr r6, [r4]
	ldr r0, .L080E3334
	cmp r6, r0
	bne .L080E331C
	adds r0, r6, #1
	str r0, [r4]
	ldr r1, .L080E3338
	ldr r0, .L080E333C
	str r0, [r1, #0x20]
	ldr r0, .L080E3340
	str r0, [r1, #0x44]
	ldr r0, .L080E3344
	str r0, [r1, #0x4c]
	ldr r0, .L080E3348
	str r0, [r1, #0x70]
	ldr r0, .L080E334C
	str r0, [r1, #0x74]
	ldr r0, .L080E3350
	str r0, [r1, #0x78]
	ldr r0, .L080E3354
	str r0, [r1, #0x7c]
	adds r2, r1, #0
	adds r2, #0x80
	ldr r0, .L080E3358
	str r0, [r2]
	adds r1, #0x84
	ldr r0, .L080E335C
	str r0, [r1]
	str r5, [r4, #0x1c]
	ldr r0, .L080E3360
	str r0, [r4, #0x28]
	ldr r0, .L080E3364
	str r0, [r4, #0x2c]
	ldr r0, .L080E3368
	str r0, [r4, #0x30]
	ldr r0, .L080E336C
	movs r1, #0
	strb r0, [r4, #0xc]
	str r1, [sp]
	ldr r2, .L080E3370
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	movs r0, #1
	strb r0, [r5, #1]
	movs r0, #0x11
	strb r0, [r5, #0x1c]
	adds r1, r5, #0
	adds r1, #0x41
	movs r0, #2
	strb r0, [r1]
	adds r1, #0x1b
	movs r0, #0x22
	strb r0, [r1]
	adds r1, #0x25
	movs r0, #3
	strb r0, [r1]
	adds r1, #0x1b
	movs r0, #0x44
	strb r0, [r1]
	adds r1, #0x24
	movs r0, #4
	strb r0, [r1, #1]
	movs r0, #0x88
	strb r0, [r1, #0x1c]
	str r6, [r4]
.L080E331C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080E3324: .4byte 0x04000084 @ REG_SOUNDCNT_X
.L080E3328: .4byte 0x04000080 @ REG_SOUNDCNT_L
.L080E332C: .4byte 0x04000063 @ IO+0x63
.L080E3330: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E3334: .4byte 0x68736D53
.L080E3338: .4byte 0x0203F150 @ EWRAM+0x3F150
.L080E333C: .4byte ply_memacc
.L080E3340: .4byte ply_lfos
.L080E3344: .4byte ply_mod
.L080E3348: .4byte ply_xcmd
.L080E334C: .4byte ply_endtie
.L080E3350: .4byte SampleFreqSet
.L080E3354: .4byte TrackStop
.L080E3358: .4byte FadeOutBody
.L080E335C: .4byte TrkVolPitSet
.L080E3360: .4byte CgbSound
.L080E3364: .4byte CgbOscOff
.L080E3368: .4byte MidiKeyToCgbFreq
.L080E336C: .4byte 0x00000000
.L080E3370: .4byte 0x05000040 @ PLTT+0x40

	thumb_func_start MusicPlayerJumpTableCopy
MusicPlayerJumpTableCopy: @ 0x080E3374
	svc #0x2a
	bx lr

	thumb_func_start ClearChain
ClearChain: @ 0x080E3378
.L080E3378:
	push {lr}
	ldr r1, .L080E3388
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E3388: .4byte 0x0203F1D8 @ EWRAM+0x3F1D8

	thumb_func_start Clear64byte
Clear64byte: @ 0x080E338C
.L080E338C:
	push {lr}
	ldr r1, .L080E339C
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E339C: .4byte 0x0203F1DC @ EWRAM+0x3F1DC

	thumb_func_start SoundInit
SoundInit: @ 0x080E33A0
.L080E33A0:
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r3, #0
	str r3, [r5]
	ldr r2, .L080E3438
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x12
	ands r0, r1
	cmp r0, #0
	beq .L080E33BC
	ldr r0, .L080E343C
	str r0, [r2]
.L080E33BC:
	ldr r1, .L080E3440
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #0x42
	movs r0, #0x8f
	strh r0, [r1]
	subs r1, #2
	ldr r2, .L080E3444
	adds r0, r2, #0
	strh r0, [r1]
	ldr r2, .L080E3448
	ldrb r1, [r2]
	movs r0, #0x3f
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r1, .L080E344C
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1]
	adds r1, #4
	ldr r0, .L080E3450
	str r0, [r1]
	ldr r0, .L080E3454
	str r5, [r0]
	str r3, [sp]
	ldr r2, .L080E3458
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	movs r0, #8
	strb r0, [r5, #6]
	movs r0, #0xf
	strb r0, [r5, #7]
	ldr r0, .L080E345C
	str r0, [r5, #0x38]
	ldr r0, .L080E3460
	str r0, [r5, #0x28]
	str r0, [r5, #0x2c]
	str r0, [r5, #0x30]
	str r0, [r5, #0x3c]
	ldr r4, .L080E3464
	adds r0, r4, #0
	bl MPlayJumpTableCopy
	str r4, [r5, #0x34]
	movs r0, #0x80
	lsls r0, r0, #0xb
	bl SampleFreqSet
	ldr r0, .L080E3468
	str r0, [r5]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E3438: .4byte 0x040000C4 @ REG_DMA1CNT
.L080E343C: .4byte 0x84400004
.L080E3440: .4byte 0x040000C6 @ IO+0xC6
.L080E3444: .4byte 0x00000B0E
.L080E3448: .4byte 0x04000089 @ IO+0x89
.L080E344C: .4byte 0x040000BC @ REG_DMA1SAD
.L080E3450: .4byte 0x040000A0 @ REG_FIFO_A
.L080E3454: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E3458: .4byte 0x05000260 @ PLTT+0x260
.L080E345C: .4byte ply_note
.L080E3460: .4byte DummyFunc
.L080E3464: .4byte 0x0203F150 @ EWRAM+0x3F150
.L080E3468: .4byte 0x68736D53

	thumb_func_start SampleFreqSet
SampleFreqSet: @ 0x080E346C
.L080E346C:
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r0, .L080E34EC
	ldr r4, [r0]
	movs r0, #0xf0
	lsls r0, r0, #0xc
	ands r0, r2
	lsrs r2, r0, #0x10
	movs r6, #0
	strb r2, [r4, #8]
	ldr r1, .L080E34F0
	subs r0, r2, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	str r5, [r4, #0x10]
	movs r0, #0xc6
	lsls r0, r0, #3
	adds r1, r5, #0
	bl __divsi3
	strb r0, [r4, #0xb]
	ldr r0, .L080E34F4
	muls r0, r5, r0
	ldr r1, .L080E34F8
	adds r0, r0, r1
	ldr r1, .L080E34FC
	bl __divsi3
	adds r1, r0, #0
	str r1, [r4, #0x14]
	movs r0, #0x80
	lsls r0, r0, #0x11
	bl __divsi3
	adds r0, #1
	asrs r0, r0, #1
	str r0, [r4, #0x18]
	ldr r0, .L080E3500
	strh r6, [r0]
	ldr r4, .L080E3504
	ldr r0, .L080E3508
	adds r1, r5, #0
	bl __divsi3
	rsbs r0, r0, #0
	strh r0, [r4]
	bl m4aSoundVSyncOn
	ldr r1, .L080E350C
.L080E34D0:
	ldrb r0, [r1]
	cmp r0, #0x9f
	beq .L080E34D0
	ldr r1, .L080E350C
.L080E34D8:
	ldrb r0, [r1]
	cmp r0, #0x9f
	bne .L080E34D8
	ldr r1, .L080E3500
	movs r0, #0x80
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E34EC: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E34F0: .4byte gUnknown_0858BD30
.L080E34F4: .4byte 0x00091D1B
.L080E34F8: .4byte 0x00001388
.L080E34FC: .4byte 0x00002710
.L080E3500: .4byte 0x04000102 @ IO+0x102
.L080E3504: .4byte 0x04000100 @ REG_TM0CNT
.L080E3508: .4byte 0x00044940
.L080E350C: .4byte 0x04000006 @ REG_VCOUNT

	thumb_func_start m4aSoundMode
m4aSoundMode: @ 0x080E3510
.L080E3510:
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, .L080E359C
	ldr r5, [r0]
	ldr r1, [r5]
	ldr r0, .L080E35A0
	cmp r1, r0
	bne .L080E3596
	adds r0, r1, #1
	str r0, [r5]
	movs r4, #0xff
	ands r4, r3
	cmp r4, #0
	beq .L080E3532
	movs r0, #0x7f
	ands r4, r0
	strb r4, [r5, #5]
.L080E3532:
	movs r4, #0xf0
	lsls r4, r4, #4
	ands r4, r3
	cmp r4, #0
	beq .L080E3552
	lsrs r0, r4, #8
	strb r0, [r5, #6]
	movs r4, #0xc
	adds r0, r5, #0
	adds r0, #0x50
	movs r1, #0
.L080E3548:
	strb r1, [r0]
	subs r4, #1
	adds r0, #0x40
	cmp r4, #0
	bne .L080E3548
.L080E3552:
	movs r4, #0xf0
	lsls r4, r4, #8
	ands r4, r3
	cmp r4, #0
	beq .L080E3560
	lsrs r0, r4, #0xc
	strb r0, [r5, #7]
.L080E3560:
	movs r4, #0xb0
	lsls r4, r4, #0x10
	ands r4, r3
	cmp r4, #0
	beq .L080E357E
	movs r0, #0xc0
	lsls r0, r0, #0xe
	ands r0, r4
	lsrs r4, r0, #0xe
	ldr r2, .L080E35A4
	ldrb r1, [r2]
	movs r0, #0x3f
	ands r0, r1
	orrs r0, r4
	strb r0, [r2]
.L080E357E:
	movs r4, #0xf0
	lsls r4, r4, #0xc
	ands r4, r3
	cmp r4, #0
	beq .L080E3592
	bl m4aSoundVSyncOff
	adds r0, r4, #0
	bl SampleFreqSet
.L080E3592:
	ldr r0, .L080E35A0
	str r0, [r5]
.L080E3596:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E359C: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E35A0: .4byte 0x68736D53
.L080E35A4: .4byte 0x04000089 @ IO+0x89

	thumb_func_start SoundClear
SoundClear: @ 0x080E35A8
	push {r4, r5, r6, r7, lr}
	ldr r0, .L080E35F4
	ldr r6, [r0]
	ldr r1, [r6]
	ldr r0, .L080E35F8
	cmp r1, r0
	bne .L080E35EE
	adds r0, r1, #1
	str r0, [r6]
	movs r5, #0xc
	adds r4, r6, #0
	adds r4, #0x50
	movs r0, #0
.L080E35C2:
	strb r0, [r4]
	subs r5, #1
	adds r4, #0x40
	cmp r5, #0
	bgt .L080E35C2
	ldr r4, [r6, #0x1c]
	cmp r4, #0
	beq .L080E35EA
	movs r5, #1
	movs r7, #0
.L080E35D6:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [r6, #0x2c]
	bl _call_via_r1
	strb r7, [r4]
	adds r5, #1
	adds r4, #0x40
	cmp r5, #4
	ble .L080E35D6
.L080E35EA:
	ldr r0, .L080E35F8
	str r0, [r6]
.L080E35EE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E35F4: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E35F8: .4byte 0x68736D53

	thumb_func_start m4aSoundVSyncOff
m4aSoundVSyncOff: @ 0x080E35FC
.L080E35FC:
	push {lr}
	sub sp, #4
	ldr r0, .L080E3648
	ldr r2, [r0]
	ldr r1, [r2]
	ldr r3, .L080E364C
	adds r0, r1, r3
	cmp r0, #1
	bhi .L080E3642
	adds r0, r1, #0
	adds r0, #0xa
	str r0, [r2]
	ldr r3, .L080E3650
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #0x12
	ands r0, r1
	cmp r0, #0
	beq .L080E3626
	ldr r0, .L080E3654
	str r0, [r3]
.L080E3626:
	ldr r1, .L080E3658
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r3, #0
	strh r0, [r1]
	movs r0, #0
	str r0, [sp]
	movs r0, #0xd4
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r2, .L080E365C
	mov r0, sp
	bl CpuSet
.L080E3642:
	add sp, #4
	pop {r0}
	bx r0
.L080E3648: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E364C: .4byte 0x978C92AD
.L080E3650: .4byte 0x040000C4 @ REG_DMA1CNT
.L080E3654: .4byte 0x84400004
.L080E3658: .4byte 0x040000C6 @ IO+0xC6
.L080E365C: .4byte 0x0500018C @ PLTT+0x18C

	thumb_func_start m4aSoundVSyncOn
m4aSoundVSyncOn: @ 0x080E3660
.L080E3660:
	push {r4, lr}
	ldr r0, .L080E368C
	ldr r2, [r0]
	ldr r3, [r2]
	ldr r0, .L080E3690
	cmp r3, r0
	beq .L080E3684
	ldr r1, .L080E3694
	movs r4, #0xb6
	lsls r4, r4, #8
	adds r0, r4, #0
	strh r0, [r1]
	ldrb r0, [r2, #4]
	movs r0, #0
	strb r0, [r2, #4]
	adds r0, r3, #0
	subs r0, #0xa
	str r0, [r2]
.L080E3684:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E368C: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E3690: .4byte 0x68736D53
.L080E3694: .4byte 0x040000C6 @ IO+0xC6

	thumb_func_start MPlayOpen
MPlayOpen: @ 0x080E3698
.L080E3698:
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	cmp r4, #0
	beq .L080E36FC
	cmp r4, #0x10
	bls .L080E36AC
	movs r4, #0x10
.L080E36AC:
	ldr r0, .L080E3704
	ldr r5, [r0]
	ldr r1, [r5]
	ldr r0, .L080E3708
	cmp r1, r0
	bne .L080E36FC
	adds r0, r1, #1
	str r0, [r5]
	adds r0, r7, #0
	bl Clear64byte
	str r6, [r7, #0x2c]
	strb r4, [r7, #8]
	movs r0, #0x80
	lsls r0, r0, #0x18
	str r0, [r7, #4]
	cmp r4, #0
	beq .L080E36E0
	movs r1, #0
.L080E36D2:
	strb r1, [r6]
	subs r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r6, #0x50
	cmp r4, #0
	bne .L080E36D2
.L080E36E0:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq .L080E36F0
	str r0, [r7, #0x38]
	ldr r0, [r5, #0x24]
	str r0, [r7, #0x3c]
	movs r0, #0
	str r0, [r5, #0x20]
.L080E36F0:
	str r7, [r5, #0x24]
	ldr r0, .L080E370C
	str r0, [r5, #0x20]
	ldr r0, .L080E3708
	str r0, [r5]
	str r0, [r7, #0x34]
.L080E36FC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E3704: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E3708: .4byte 0x68736D53
.L080E370C: .4byte MPlayMain

	thumb_func_start MPlayStart
MPlayStart: @ 0x080E3710
.L080E3710:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r1, #0
	ldr r1, [r5, #0x34]
	ldr r0, .L080E37F0
	cmp r1, r0
	bne .L080E37E6
	ldrb r0, [r5, #0xb]
	ldrb r2, [r7, #2]
	cmp r0, #0
	beq .L080E3752
	ldr r0, [r5]
	cmp r0, #0
	beq .L080E373C
	ldr r1, [r5, #0x2c]
	movs r0, #0x40
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L080E3748
.L080E373C:
	ldr r1, [r5, #4]
	ldrh r0, [r5, #4]
	cmp r0, #0
	beq .L080E3752
	cmp r1, #0
	blt .L080E3752
.L080E3748:
	ldrb r0, [r7, #2]
	adds r2, r0, #0
	ldrb r0, [r5, #9]
	cmp r0, r2
	bhi .L080E37E6
.L080E3752:
	ldr r0, [r5, #0x34]
	adds r0, #1
	str r0, [r5, #0x34]
	movs r1, #0
	str r1, [r5, #4]
	str r7, [r5]
	ldr r0, [r7, #4]
	str r0, [r5, #0x30]
	strb r2, [r5, #9]
	str r1, [r5, #0xc]
	movs r0, #0x96
	strh r0, [r5, #0x1c]
	strh r0, [r5, #0x20]
	adds r0, #0x6a
	strh r0, [r5, #0x1e]
	strh r1, [r5, #0x22]
	strh r1, [r5, #0x24]
	movs r6, #0
	ldr r4, [r5, #0x2c]
	ldrb r1, [r7]
	cmp r6, r1
	bge .L080E37B2
	ldrb r0, [r5, #8]
	cmp r6, r0
	bge .L080E37D2
	mov r8, r6
.L080E3786:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TrackStop
	movs r0, #0xc0
	strb r0, [r4]
	mov r1, r8
	str r1, [r4, #0x20]
	lsls r1, r6, #2
	adds r0, r7, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x40]
	adds r6, #1
	adds r4, #0x50
	ldrb r0, [r7]
	cmp r6, r0
	bge .L080E37B2
	ldrb r1, [r5, #8]
	cmp r6, r1
	blt .L080E3786
.L080E37B2:
	ldrb r0, [r5, #8]
	cmp r6, r0
	bge .L080E37D2
	movs r1, #0
	mov r8, r1
.L080E37BC:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TrackStop
	mov r0, r8
	strb r0, [r4]
	adds r6, #1
	adds r4, #0x50
	ldrb r1, [r5, #8]
	cmp r6, r1
	blt .L080E37BC
.L080E37D2:
	movs r0, #0x80
	ldrb r1, [r7, #3]
	ands r0, r1
	cmp r0, #0
	beq .L080E37E2
	ldrb r0, [r7, #3]
	bl m4aSoundMode
.L080E37E2:
	ldr r0, .L080E37F0
	str r0, [r5, #0x34]
.L080E37E6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E37F0: .4byte 0x68736D53

	thumb_func_start m4aMPlayStop
m4aMPlayStop: @ 0x080E37F4
.L080E37F4:
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x34]
	ldr r0, .L080E3830
	cmp r1, r0
	bne .L080E382A
	adds r0, r1, #1
	str r0, [r6, #0x34]
	ldr r0, [r6, #4]
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r6, #4]
	ldrb r4, [r6, #8]
	ldr r5, [r6, #0x2c]
	cmp r4, #0
	ble .L080E3826
.L080E3816:
	adds r0, r6, #0
	adds r1, r5, #0
	bl TrackStop
	subs r4, #1
	adds r5, #0x50
	cmp r4, #0
	bgt .L080E3816
.L080E3826:
	ldr r0, .L080E3830
	str r0, [r6, #0x34]
.L080E382A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080E3830: .4byte 0x68736D53

	thumb_func_start FadeOutBody
FadeOutBody: @ 0x080E3834
.L080E3834:
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrh r1, [r6, #0x24]
	cmp r1, #0
	beq .L080E38F6
	ldrh r0, [r6, #0x26]
	subs r0, #1
	strh r0, [r6, #0x26]
	ldr r3, .L080E3874
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne .L080E38F6
	strh r1, [r6, #0x26]
	ldrh r1, [r6, #0x28]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080E3878
	adds r0, r1, #0
	adds r0, #0x10
	strh r0, [r6, #0x28]
	ands r0, r2
	cmp r0, #0xff
	bls .L080E38CA
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r6, #0x28]
	strh r3, [r6, #0x24]
	b .L080E38CA
	.byte 0x00, 0x00
.L080E3874: .4byte 0x0000FFFF
.L080E3878:
	adds r0, r1, #0
	subs r0, #0x10
	strh r0, [r6, #0x28]
	ands r0, r2
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt .L080E38CA
	ldrb r5, [r6, #8]
	ldr r4, [r6, #0x2c]
	cmp r5, #0
	ble .L080E38AA
.L080E388E:
	adds r0, r6, #0
	adds r1, r4, #0
	bl TrackStop
	movs r0, #1
	ldrh r7, [r6, #0x28]
	ands r0, r7
	cmp r0, #0
	bne .L080E38A2
	strb r0, [r4]
.L080E38A2:
	subs r5, #1
	adds r4, #0x50
	cmp r5, #0
	bgt .L080E388E
.L080E38AA:
	movs r0, #1
	ldrh r1, [r6, #0x28]
	ands r0, r1
	cmp r0, #0
	beq .L080E38BE
	ldr r0, [r6, #4]
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	b .L080E38C2
.L080E38BE:
	movs r0, #0x80
	lsls r0, r0, #0x18
.L080E38C2:
	str r0, [r6, #4]
	movs r0, #0
	strh r0, [r6, #0x24]
	b .L080E38F6
.L080E38CA:
	ldrb r5, [r6, #8]
	ldr r4, [r6, #0x2c]
	cmp r5, #0
	ble .L080E38F6
	movs r3, #0x80
	movs r7, #0
	movs r2, #3
.L080E38D8:
	ldrb r1, [r4]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E38EE
	ldrh r7, [r6, #0x28]
	lsrs r0, r7, #2
	strb r0, [r4, #0x13]
	adds r0, r1, #0
	orrs r0, r2
	strb r0, [r4]
.L080E38EE:
	subs r5, #1
	adds r4, #0x50
	cmp r5, #0
	bgt .L080E38D8
.L080E38F6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start TrkVolPitSet
TrkVolPitSet: @ 0x080E38FC
.L080E38FC:
	push {r4, lr}
	adds r2, r1, #0
	movs r0, #1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq .L080E3960
	ldrb r3, [r2, #0x13]
	ldrb r1, [r2, #0x12]
	adds r0, r3, #0
	muls r0, r1, r0
	lsrs r3, r0, #5
	ldrb r4, [r2, #0x18]
	cmp r4, #1
	bne .L080E3924
	movs r0, #0x16
	ldrsb r0, [r2, r0]
	adds r0, #0x80
	muls r0, r3, r0
	lsrs r3, r0, #7
.L080E3924:
	movs r0, #0x14
	ldrsb r0, [r2, r0]
	lsls r0, r0, #1
	movs r1, #0x15
	ldrsb r1, [r2, r1]
	adds r1, r0, r1
	cmp r4, #2
	bne .L080E393A
	movs r0, #0x16
	ldrsb r0, [r2, r0]
	adds r1, r1, r0
.L080E393A:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge .L080E3946
	adds r1, r0, #0
	b .L080E394C
.L080E3946:
	cmp r1, #0x7f
	ble .L080E394C
	movs r1, #0x7f
.L080E394C:
	adds r0, r1, #0
	adds r0, #0x80
	muls r0, r3, r0
	lsrs r0, r0, #8
	strb r0, [r2, #0x10]
	movs r0, #0x7f
	subs r0, r0, r1
	muls r0, r3, r0
	lsrs r0, r0, #8
	strb r0, [r2, #0x11]
.L080E3960:
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	adds r3, r1, #0
	cmp r0, #0
	beq .L080E39A4
	movs r0, #0xe
	ldrsb r0, [r2, r0]
	ldrb r1, [r2, #0xf]
	muls r0, r1, r0
	movs r1, #0xc
	ldrsb r1, [r2, r1]
	adds r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xa
	ldrsb r0, [r2, r0]
	lsls r0, r0, #8
	adds r1, r1, r0
	movs r0, #0xb
	ldrsb r0, [r2, r0]
	lsls r0, r0, #8
	adds r1, r1, r0
	ldrb r0, [r2, #0xd]
	adds r1, r0, r1
	ldrb r0, [r2, #0x18]
	cmp r0, #0
	bne .L080E399E
	movs r0, #0x16
	ldrsb r0, [r2, r0]
	lsls r0, r0, #4
	adds r1, r1, r0
.L080E399E:
	asrs r0, r1, #8
	strb r0, [r2, #8]
	strb r1, [r2, #9]
.L080E39A4:
	movs r0, #0xfa
	ands r0, r3
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start MidiKeyToCgbFreq
MidiKeyToCgbFreq: @ 0x080E39B0
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov ip, r2
	cmp r0, #4
	bne .L080E39E8
	cmp r5, #0x14
	bhi .L080E39CC
	movs r5, #0
	b .L080E39DA
.L080E39CC:
	adds r0, r5, #0
	subs r0, #0x15
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x3b
	bls .L080E39DA
	movs r5, #0x3b
.L080E39DA:
	ldr r0, .L080E39E4
	adds r0, r5, r0
	ldrb r0, [r0]
	b .L080E3A4A
	.byte 0x00, 0x00
.L080E39E4: .4byte gUnknown_0858BDE4
.L080E39E8:
	cmp r5, #0x23
	bhi .L080E39F4
	movs r0, #0
	mov ip, r0
	movs r5, #0
	b .L080E3A06
.L080E39F4:
	adds r0, r5, #0
	subs r0, #0x24
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x82
	bls .L080E3A06
	movs r5, #0x82
	movs r1, #0xff
	mov ip, r1
.L080E3A06:
	ldr r3, .L080E3A50
	adds r0, r5, r3
	ldrb r6, [r0]
	ldr r4, .L080E3A54
	movs r2, #0xf
	adds r0, r6, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r7, #0
	ldrsh r1, [r0, r7]
	asrs r0, r6, #4
	adds r6, r1, #0
	asrs r6, r0
	adds r0, r5, #1
	adds r0, r0, r3
	ldrb r1, [r0]
	adds r0, r1, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	asrs r1, r1, #4
	asrs r0, r1
	subs r0, r0, r6
	mov r7, ip
	muls r7, r0, r7
	adds r0, r7, #0
	asrs r0, r0, #8
	adds r0, r6, r0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
.L080E3A4A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080E3A50: .4byte gUnknown_0858BD48
.L080E3A54: .4byte gUnknown_0858BDCC

	thumb_func_start CgbOscOff
CgbOscOff: @ 0x080E3A58
.L080E3A58:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #2
	beq .L080E3A80
	cmp r0, #2
	bgt .L080E3A6C
	cmp r0, #1
	beq .L080E3A72
	b .L080E3A94
.L080E3A6C:
	cmp r1, #3
	beq .L080E3A88
	b .L080E3A94
.L080E3A72:
	ldr r1, .L080E3A7C
	movs r0, #8
	strb r0, [r1]
	adds r1, #2
	b .L080E3A9C
.L080E3A7C: .4byte 0x04000063 @ IO+0x63
.L080E3A80:
	ldr r1, .L080E3A84
	b .L080E3A96
.L080E3A84: .4byte 0x04000069 @ IO+0x69
.L080E3A88:
	ldr r1, .L080E3A90
	movs r0, #0
	b .L080E3A9E
	.byte 0x00, 0x00
.L080E3A90: .4byte 0x04000070 @ REG_SOUND3CNT_L
.L080E3A94:
	ldr r1, .L080E3AA4
.L080E3A96:
	movs r0, #8
	strb r0, [r1]
	adds r1, #4
.L080E3A9C:
	movs r0, #0x80
.L080E3A9E:
	strb r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080E3AA4: .4byte 0x04000079 @ IO+0x79

	thumb_func_start CgbModVol
CgbModVol: @ 0x080E3AA8
.L080E3AA8:
	push {r4, lr}
	adds r1, r0, #0
	ldrb r0, [r1, #2]
	lsls r2, r0, #0x18
	lsrs r4, r2, #0x18
	ldrb r3, [r1, #3]
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
	cmp r4, r3
	blo .L080E3AC8
	lsrs r0, r2, #0x19
	cmp r0, r3
	blo .L080E3AD4
	movs r0, #0xf
	strb r0, [r1, #0x1b]
	b .L080E3AE2
.L080E3AC8:
	lsrs r0, r0, #0x19
	cmp r0, r4
	blo .L080E3AD4
	movs r0, #0xf0
	strb r0, [r1, #0x1b]
	b .L080E3AE2
.L080E3AD4:
	movs r0, #0xff
	strb r0, [r1, #0x1b]
	ldrb r2, [r1, #3]
	ldrb r3, [r1, #2]
	adds r0, r2, r3
	lsrs r0, r0, #4
	b .L080E3AF2
.L080E3AE2:
	ldrb r2, [r1, #3]
	ldrb r3, [r1, #2]
	adds r0, r2, r3
	lsrs r0, r0, #4
	strb r0, [r1, #0xa]
	cmp r0, #0xf
	bls .L080E3AF4
	movs r0, #0xf
.L080E3AF2:
	strb r0, [r1, #0xa]
.L080E3AF4:
	ldrb r2, [r1, #6]
	ldrb r3, [r1, #0xa]
	adds r0, r2, #0
	muls r0, r3, r0
	adds r0, #0xf
	asrs r0, r0, #4
	strb r0, [r1, #0x19]
	ldrb r0, [r1, #0x1c]
	ldrb r2, [r1, #0x1b]
	ands r0, r2
	strb r0, [r1, #0x1b]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start CgbSound
CgbSound: @ 0x080E3B10
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, .L080E3B30
	ldr r0, [r0]
	str r0, [sp, #4]
	ldrb r0, [r0, #0xa]
	cmp r0, #0
	beq .L080E3B34
	subs r0, #1
	ldr r1, [sp, #4]
	strb r0, [r1, #0xa]
	b .L080E3B3A
.L080E3B30: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E3B34:
	movs r0, #0xe
	ldr r2, [sp, #4]
	strb r0, [r2, #0xa]
.L080E3B3A:
	movs r6, #1
	ldr r0, [sp, #4]
	ldr r4, [r0, #0x1c]
.L080E3B40:
	ldrb r1, [r4]
	movs r0, #0xc7
	ands r0, r1
	adds r2, r6, #1
	mov sl, r2
	movs r2, #0x40
	adds r2, r2, r4
	mov sb, r2
	cmp r0, #0
	bne .L080E3B56
	b .L080E3F40
.L080E3B56:
	cmp r6, #2
	beq .L080E3B88
	cmp r6, #2
	bgt .L080E3B64
	cmp r6, #1
	beq .L080E3B6A
	b .L080E3BC0
.L080E3B64:
	cmp r6, #3
	beq .L080E3BA0
	b .L080E3BC0
.L080E3B6A:
	ldr r0, .L080E3B7C
	str r0, [sp, #8]
	ldr r7, .L080E3B80
	ldr r2, .L080E3B84
	str r2, [sp, #0xc]
	adds r0, #4
	str r0, [sp, #0x10]
	adds r2, #2
	b .L080E3BD0
.L080E3B7C: .4byte 0x04000060 @ REG_SOUND1CNT_L
.L080E3B80: .4byte 0x04000062 @ REG_SOUND1CNT_H
.L080E3B84: .4byte 0x04000063 @ IO+0x63
.L080E3B88:
	ldr r0, .L080E3B94
	str r0, [sp, #8]
	ldr r7, .L080E3B98
	ldr r2, .L080E3B9C
	b .L080E3BC8
	.byte 0x00, 0x00
.L080E3B94: .4byte 0x04000061 @ IO+0x61
.L080E3B98: .4byte 0x04000068 @ REG_SOUND2CNT_L
.L080E3B9C: .4byte 0x04000069 @ IO+0x69
.L080E3BA0:
	ldr r0, .L080E3BB4
	str r0, [sp, #8]
	ldr r7, .L080E3BB8
	ldr r2, .L080E3BBC
	str r2, [sp, #0xc]
	adds r0, #4
	str r0, [sp, #0x10]
	adds r2, #2
	b .L080E3BD0
	.byte 0x00, 0x00
.L080E3BB4: .4byte 0x04000070 @ REG_SOUND3CNT_L
.L080E3BB8: .4byte 0x04000072 @ REG_SOUND3CNT_H
.L080E3BBC: .4byte 0x04000073 @ IO+0x73
.L080E3BC0:
	ldr r0, .L080E3C20
	str r0, [sp, #8]
	ldr r7, .L080E3C24
	ldr r2, .L080E3C28
.L080E3BC8:
	str r2, [sp, #0xc]
	adds r0, #0xb
	str r0, [sp, #0x10]
	adds r2, #4
.L080E3BD0:
	str r2, [sp, #0x14]
	ldr r0, [sp, #4]
	ldrb r0, [r0, #0xa]
	str r0, [sp]
	ldr r2, [sp, #0xc]
	ldrb r0, [r2]
	mov r8, r0
	adds r2, r1, #0
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq .L080E3CC6
	movs r3, #0x40
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r6, #1
	mov sl, r0
	movs r1, #0x40
	adds r1, r1, r4
	mov sb, r1
	cmp r5, #0
	bne .L080E3CEA
	movs r0, #3
	strb r0, [r4]
	strb r0, [r4, #0x1d]
	adds r0, r4, #0
	str r3, [sp, #0x18]
	bl CgbModVol
	ldr r3, [sp, #0x18]
	cmp r6, #2
	beq .L080E3C38
	cmp r6, #2
	bgt .L080E3C2C
	cmp r6, #1
	beq .L080E3C32
	b .L080E3C8C
	.byte 0x00, 0x00
.L080E3C20: .4byte 0x04000071 @ IO+0x71
.L080E3C24: .4byte 0x04000078 @ REG_SOUND4CNT_L
.L080E3C28: .4byte 0x04000079 @ IO+0x79
.L080E3C2C:
	cmp r6, #3
	beq .L080E3C44
	b .L080E3C8C
.L080E3C32:
	ldrb r0, [r4, #0x1f]
	ldr r2, [sp, #8]
	strb r0, [r2]
.L080E3C38:
	ldr r0, [r4, #0x24]
	lsls r0, r0, #6
	ldrb r1, [r4, #0x1e]
	adds r0, r1, r0
	strb r0, [r7]
	b .L080E3C98
.L080E3C44:
	ldr r1, [r4, #0x24]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	beq .L080E3C6C
	ldr r2, [sp, #8]
	strb r3, [r2]
	ldr r1, .L080E3C80
	ldr r2, [r4, #0x24]
	ldr r0, [r2]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r2, #4]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r2, #8]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r2, #0xc]
	str r0, [r1]
	str r2, [r4, #0x28]
.L080E3C6C:
	ldr r0, [sp, #8]
	strb r5, [r0]
	ldrb r0, [r4, #0x1e]
	strb r0, [r7]
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq .L080E3C84
	movs r0, #0xc0
	b .L080E3CA6
	.byte 0x00, 0x00
.L080E3C80: .4byte 0x04000090 @ REG_WAVE_RAM
.L080E3C84:
	movs r1, #0x80
	rsbs r1, r1, #0
	strb r1, [r4, #0x1a]
	b .L080E3CA8
.L080E3C8C:
	ldrb r0, [r4, #0x1e]
	strb r0, [r7]
	ldr r0, [r4, #0x24]
	lsls r0, r0, #3
	ldr r2, [sp, #0x10]
	strb r0, [r2]
.L080E3C98:
	ldrb r0, [r4, #4]
	adds r0, #8
	mov r8, r0
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq .L080E3CA6
	movs r0, #0x40
.L080E3CA6:
	strb r0, [r4, #0x1a]
.L080E3CA8:
	ldrb r1, [r4, #4]
	movs r2, #0
	strb r1, [r4, #0xb]
	movs r0, #0xff
	ands r0, r1
	adds r1, r6, #1
	mov sl, r1
	movs r1, #0x40
	adds r1, r1, r4
	mov sb, r1
	cmp r0, #0
	bne .L080E3CC2
	b .L080E3DFE
.L080E3CC2:
	strb r2, [r4, #9]
	b .L080E3E2C
.L080E3CC6:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq .L080E3CF8
	ldrb r0, [r4, #0xd]
	subs r0, #1
	strb r0, [r4, #0xd]
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #0x18
	adds r1, r6, #1
	mov sl, r1
	movs r2, #0x40
	adds r2, r2, r4
	mov sb, r2
	cmp r0, #0
	ble .L080E3CEA
	b .L080E3E3E
.L080E3CEA:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl CgbOscOff
	movs r0, #0
	strb r0, [r4]
	b .L080E3F3C
.L080E3CF8:
	movs r0, #0x40
	ands r0, r1
	adds r2, r6, #1
	mov sl, r2
	movs r2, #0x40
	adds r2, r2, r4
	mov sb, r2
	cmp r0, #0
	beq .L080E3D38
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq .L080E3D38
	movs r0, #0xfc
	ands r0, r1
	movs r2, #0
	strb r0, [r4]
	ldrb r1, [r4, #7]
	strb r1, [r4, #0xb]
	movs r0, #0xff
	ands r0, r1
	cmp r0, #0
	beq .L080E3D6A
	movs r0, #1
	ldrb r1, [r4, #0x1d]
	orrs r0, r1
	strb r0, [r4, #0x1d]
	cmp r6, #3
	beq .L080E3E2C
	ldrb r2, [r4, #7]
	mov r8, r2
	b .L080E3E2C
.L080E3D38:
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	bne .L080E3E2C
	cmp r6, #3
	bne .L080E3D4A
	movs r0, #1
	ldrb r1, [r4, #0x1d]
	orrs r0, r1
	strb r0, [r4, #0x1d]
.L080E3D4A:
	adds r0, r4, #0
	bl CgbModVol
	movs r0, #3
	ldrb r2, [r4]
	ands r0, r2
	cmp r0, #0
	bne .L080E3D9E
	ldrb r0, [r4, #9]
	subs r0, #1
	strb r0, [r4, #9]
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt .L080E3D9A
.L080E3D6A:
	ldrb r2, [r4, #0xc]
	ldrb r1, [r4, #0xa]
	adds r0, r2, #0
	muls r0, r1, r0
	adds r0, #0xff
	asrs r0, r0, #8
	movs r1, #0
	strb r0, [r4, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E3CEA
	movs r0, #4
	ldrb r2, [r4]
	orrs r0, r2
	strb r0, [r4]
	movs r0, #1
	ldrb r1, [r4, #0x1d]
	orrs r0, r1
	strb r0, [r4, #0x1d]
	cmp r6, #3
	beq .L080E3E3E
	movs r2, #8
	mov r8, r2
	b .L080E3E3E
.L080E3D9A:
	ldrb r0, [r4, #7]
	b .L080E3E2A
.L080E3D9E:
	cmp r0, #1
	bne .L080E3DAA
.L080E3DA2:
	ldrb r0, [r4, #0x19]
	strb r0, [r4, #9]
	movs r0, #7
	b .L080E3E2A
.L080E3DAA:
	cmp r0, #2
	bne .L080E3DEE
	ldrb r0, [r4, #9]
	subs r0, #1
	strb r0, [r4, #9]
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #0x18
	ldrb r2, [r4, #0x19]
	lsls r1, r2, #0x18
	cmp r0, r1
	bgt .L080E3DEA
.L080E3DC2:
	ldrb r0, [r4, #6]
	cmp r0, #0
	bne .L080E3DD2
	movs r0, #0xfc
	ldrb r1, [r4]
	ands r0, r1
	strb r0, [r4]
	b .L080E3D6A
.L080E3DD2:
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	movs r0, #1
	ldrb r2, [r4, #0x1d]
	orrs r0, r2
	strb r0, [r4, #0x1d]
	cmp r6, #3
	beq .L080E3DA2
	movs r0, #8
	mov r8, r0
	b .L080E3DA2
.L080E3DEA:
	ldrb r0, [r4, #5]
	b .L080E3E2A
.L080E3DEE:
	ldrb r0, [r4, #9]
	adds r0, #1
	strb r0, [r4, #9]
	movs r1, #0xff
	ands r0, r1
	ldrb r2, [r4, #0xa]
	cmp r0, r2
	blo .L080E3E28
.L080E3DFE:
	ldrb r0, [r4]
	subs r0, #1
	movs r2, #0
	strb r0, [r4]
	ldrb r1, [r4, #5]
	strb r1, [r4, #0xb]
	movs r0, #0xff
	ands r0, r1
	cmp r0, #0
	beq .L080E3DC2
	movs r0, #1
	ldrb r1, [r4, #0x1d]
	orrs r0, r1
	strb r0, [r4, #0x1d]
	ldrb r0, [r4, #0xa]
	strb r0, [r4, #9]
	cmp r6, #3
	beq .L080E3E2C
	ldrb r2, [r4, #5]
	mov r8, r2
	b .L080E3E2C
.L080E3E28:
	ldrb r0, [r4, #4]
.L080E3E2A:
	strb r0, [r4, #0xb]
.L080E3E2C:
	ldrb r0, [r4, #0xb]
	subs r0, #1
	strb r0, [r4, #0xb]
	ldr r0, [sp]
	cmp r0, #0
	bne .L080E3E3E
	subs r0, #1
	str r0, [sp]
	b .L080E3D38
.L080E3E3E:
	movs r0, #2
	ldrb r1, [r4, #0x1d]
	ands r0, r1
	cmp r0, #0
	beq .L080E3EB6
	cmp r6, #3
	bgt .L080E3E7E
	movs r0, #8
	ldrb r2, [r4, #1]
	ands r0, r2
	cmp r0, #0
	beq .L080E3E7E
	ldr r0, .L080E3E68
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt .L080E3E70
	ldr r0, [r4, #0x20]
	adds r0, #2
	ldr r1, .L080E3E6C
	b .L080E3E7A
	.byte 0x00, 0x00
.L080E3E68: .4byte 0x04000089 @ IO+0x89
.L080E3E6C: .4byte 0x000007FC
.L080E3E70:
	cmp r0, #0x7f
	bgt .L080E3E7E
	ldr r0, [r4, #0x20]
	adds r0, #1
	ldr r1, .L080E3E8C
.L080E3E7A:
	ands r0, r1
	str r0, [r4, #0x20]
.L080E3E7E:
	cmp r6, #4
	beq .L080E3E90
	ldr r0, [r4, #0x20]
	ldr r1, [sp, #0x10]
	strb r0, [r1]
	b .L080E3E9E
	.byte 0x00, 0x00
.L080E3E8C: .4byte 0x000007FE
.L080E3E90:
	ldr r2, [sp, #0x10]
	ldrb r0, [r2]
	movs r1, #8
	ands r1, r0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	strb r0, [r2]
.L080E3E9E:
	movs r0, #0xc0
	ldrb r1, [r4, #0x1a]
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x21
	ldrb r1, [r1]
	adds r0, r1, r0
	strb r0, [r4, #0x1a]
	movs r2, #0xff
	ands r0, r2
	ldr r1, [sp, #0x14]
	strb r0, [r1]
.L080E3EB6:
	movs r0, #1
	ldrb r2, [r4, #0x1d]
	ands r0, r2
	cmp r0, #0
	beq .L080E3F3C
	ldr r1, .L080E3F00
	ldrb r0, [r1]
	ldrb r2, [r4, #0x1c]
	bics r0, r2
	ldrb r2, [r4, #0x1b]
	orrs r0, r2
	strb r0, [r1]
	cmp r6, #3
	bne .L080E3F08
	ldr r0, .L080E3F04
	ldrb r1, [r4, #9]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, [sp, #0xc]
	strb r0, [r2]
	movs r1, #0x80
	adds r0, r1, #0
	ldrb r2, [r4, #0x1a]
	ands r0, r2
	cmp r0, #0
	beq .L080E3F3C
	ldr r0, [sp, #8]
	strb r1, [r0]
	ldrb r0, [r4, #0x1a]
	ldr r1, [sp, #0x14]
	strb r0, [r1]
	movs r0, #0x7f
	ldrb r2, [r4, #0x1a]
	ands r0, r2
	strb r0, [r4, #0x1a]
	b .L080E3F3C
	.byte 0x00, 0x00
.L080E3F00: .4byte 0x04000081 @ IO+0x81
.L080E3F04: .4byte gUnknown_0858BE20
.L080E3F08:
	movs r0, #0xf
	mov r1, r8
	ands r1, r0
	mov r8, r1
	ldrb r2, [r4, #9]
	lsls r0, r2, #4
	add r0, r8
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	movs r2, #0x80
	ldrb r0, [r4, #0x1a]
	orrs r0, r2
	ldr r1, [sp, #0x14]
	strb r0, [r1]
	cmp r6, #1
	bne .L080E3F3C
	ldr r0, [sp, #8]
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L080E3F3C
	ldrb r0, [r4, #0x1a]
	orrs r0, r2
	ldr r1, [sp, #0x14]
	strb r0, [r1]
.L080E3F3C:
	movs r0, #0
	strb r0, [r4, #0x1d]
.L080E3F40:
	mov r6, sl
	mov r4, sb
	cmp r6, #4
	bgt .L080E3F4A
	b .L080E3B40
.L080E3F4A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start m4aMPlayTempoControl
m4aMPlayTempoControl: @ 0x080E3F5C
	push {r4, lr}
	adds r2, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [r2, #0x34]
	ldr r0, .L080E3F80
	cmp r3, r0
	bne .L080E3F78
	strh r1, [r2, #0x1e]
	ldrh r4, [r2, #0x1c]
	adds r0, r1, #0
	muls r0, r4, r0
	asrs r0, r0, #8
	strh r0, [r2, #0x20]
.L080E3F78:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E3F80: .4byte 0x68736D53

	thumb_func_start m4aMPlayVolumeControl
m4aMPlayVolumeControl: @ 0x080E3F84
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r6, r2, #0x10
	ldr r3, [r4, #0x34]
	ldr r0, .L080E3FE8
	cmp r3, r0
	bne .L080E3FDC
	adds r0, r3, #1
	str r0, [r4, #0x34]
	ldrb r2, [r4, #8]
	ldr r1, [r4, #0x2c]
	movs r5, #1
	cmp r2, #0
	ble .L080E3FD8
	movs r0, #0x80
	mov r8, r0
	lsrs r6, r6, #0x12
	movs r0, #3
	mov ip, r0
.L080E3FB4:
	adds r0, r7, #0
	ands r0, r5
	cmp r0, #0
	beq .L080E3FCE
	ldrb r3, [r1]
	mov r0, r8
	ands r0, r3
	cmp r0, #0
	beq .L080E3FCE
	strb r6, [r1, #0x13]
	mov r0, ip
	orrs r0, r3
	strb r0, [r1]
.L080E3FCE:
	subs r2, #1
	adds r1, #0x50
	lsls r5, r5, #1
	cmp r2, #0
	bgt .L080E3FB4
.L080E3FD8:
	ldr r0, .L080E3FE8
	str r0, [r4, #0x34]
.L080E3FDC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E3FE8: .4byte 0x68736D53

	thumb_func_start m4aMPlayPitchControl
m4aMPlayPitchControl: @ 0x080E3FEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov ip, r1
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r3, [r4, #0x34]
	ldr r0, .L080E405C
	cmp r3, r0
	bne .L080E404E
	adds r0, r3, #1
	str r0, [r4, #0x34]
	ldrb r2, [r4, #8]
	ldr r3, [r4, #0x2c]
	movs r5, #1
	cmp r2, #0
	ble .L080E404A
	movs r0, #0x80
	mov sb, r0
	lsls r0, r6, #0x10
	asrs r7, r0, #0x18
	movs r0, #0xc
	mov r8, r0
.L080E4024:
	mov r0, ip
	ands r0, r5
	cmp r0, #0
	beq .L080E4040
	ldrb r1, [r3]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq .L080E4040
	strb r7, [r3, #0xb]
	strb r6, [r3, #0xd]
	mov r0, r8
	orrs r0, r1
	strb r0, [r3]
.L080E4040:
	subs r2, #1
	adds r3, #0x50
	lsls r5, r5, #1
	cmp r2, #0
	bgt .L080E4024
.L080E404A:
	ldr r0, .L080E405C
	str r0, [r4, #0x34]
.L080E404E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E405C: .4byte 0x68736D53

	thumb_func_start m4aMPlayPanpotControl
m4aMPlayPanpotControl: @ 0x080E4060
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r3, [r4, #0x34]
	ldr r0, .L080E40C4
	cmp r3, r0
	bne .L080E40B8
	adds r0, r3, #1
	str r0, [r4, #0x34]
	ldrb r2, [r4, #8]
	ldr r1, [r4, #0x2c]
	movs r5, #1
	cmp r2, #0
	ble .L080E40B4
	movs r0, #0x80
	mov r8, r0
	movs r0, #3
	mov ip, r0
.L080E4090:
	adds r0, r7, #0
	ands r0, r5
	cmp r0, #0
	beq .L080E40AA
	ldrb r3, [r1]
	mov r0, r8
	ands r0, r3
	cmp r0, #0
	beq .L080E40AA
	strb r6, [r1, #0x15]
	mov r0, ip
	orrs r0, r3
	strb r0, [r1]
.L080E40AA:
	subs r2, #1
	adds r1, #0x50
	lsls r5, r5, #1
	cmp r2, #0
	bgt .L080E4090
.L080E40B4:
	ldr r0, .L080E40C4
	str r0, [r4, #0x34]
.L080E40B8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E40C4: .4byte 0x68736D53

	thumb_func_start ClearModM
ClearModM: @ 0x080E40C8
.L080E40C8:
	adds r1, r0, #0
	movs r2, #0
	movs r0, #0
	strb r0, [r1, #0x1a]
	strb r0, [r1, #0x16]
	ldrb r0, [r1, #0x18]
	cmp r0, #0
	bne .L080E40DC
	movs r0, #0xc
	b .L080E40DE
.L080E40DC:
	movs r0, #3
.L080E40DE:
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start m4aMPlayModDepthSet
m4aMPlayModDepthSet: @ 0x080E40E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	ldr r1, [r6, #0x34]
	ldr r0, .L080E4158
	cmp r1, r0
	bne .L080E4148
	adds r0, r1, #1
	str r0, [r6, #0x34]
	ldrb r5, [r6, #8]
	ldr r4, [r6, #0x2c]
	movs r7, #1
	cmp r5, #0
	ble .L080E4144
	mov sb, r8
.L080E4118:
	mov r0, sl
	ands r0, r7
	cmp r0, #0
	beq .L080E413A
	movs r0, #0x80
	ldrb r1, [r4]
	ands r0, r1
	cmp r0, #0
	beq .L080E413A
	mov r0, r8
	strb r0, [r4, #0x17]
	mov r1, sb
	cmp r1, #0
	bne .L080E413A
	adds r0, r4, #0
	bl ClearModM
.L080E413A:
	subs r5, #1
	adds r4, #0x50
	lsls r7, r7, #1
	cmp r5, #0
	bgt .L080E4118
.L080E4144:
	ldr r0, .L080E4158
	str r0, [r6, #0x34]
.L080E4148:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E4158: .4byte 0x68736D53

	thumb_func_start m4aMPlayLFOSpeedSet
m4aMPlayLFOSpeedSet: @ 0x080E415C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	ldr r1, [r6, #0x34]
	ldr r0, .L080E41CC
	cmp r1, r0
	bne .L080E41BC
	adds r0, r1, #1
	str r0, [r6, #0x34]
	ldrb r5, [r6, #8]
	ldr r4, [r6, #0x2c]
	movs r7, #1
	cmp r5, #0
	ble .L080E41B8
	mov sb, r8
.L080E418C:
	mov r0, sl
	ands r0, r7
	cmp r0, #0
	beq .L080E41AE
	movs r0, #0x80
	ldrb r1, [r4]
	ands r0, r1
	cmp r0, #0
	beq .L080E41AE
	mov r0, r8
	strb r0, [r4, #0x19]
	mov r1, sb
	cmp r1, #0
	bne .L080E41AE
	adds r0, r4, #0
	bl ClearModM
.L080E41AE:
	subs r5, #1
	adds r4, #0x50
	lsls r7, r7, #1
	cmp r5, #0
	bgt .L080E418C
.L080E41B8:
	ldr r0, .L080E41CC
	str r0, [r6, #0x34]
.L080E41BC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E41CC: .4byte 0x68736D53

	thumb_func_start ply_memacc
ply_memacc: @ 0x080E41D0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, [r6, #0x40]
	ldrb r5, [r1]
	adds r2, r1, #1
	str r2, [r6, #0x40]
	ldr r0, [r4, #0x18]
	ldrb r1, [r1, #1]
	adds r3, r1, r0
	adds r0, r2, #1
	str r0, [r6, #0x40]
	ldrb r2, [r2, #1]
	adds r0, #1
	str r0, [r6, #0x40]
	cmp r5, #0x11
	bls .L080E41F4
	b .L080E4322
.L080E41F4:
	lsls r0, r5, #2
	ldr r1, .L080E4200
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080E4200: .4byte gUnknown_080E4204
	.global gUnknown_080E4204
gUnknown_080E4204:
.L080E4204: @ jump table
	.4byte .L080E424C
	.4byte .L080E4250
	.4byte .L080E4258
	.4byte .L080E4260
	.4byte .L080E426A
	.4byte .L080E4278
	.4byte .L080E4286
	.4byte .L080E428E
	.4byte .L080E4296
	.4byte .L080E429E
	.4byte .L080E42A6
	.4byte .L080E42AE
	.4byte .L080E42B6
	.4byte .L080E42C4
	.4byte .L080E42D2
	.4byte .L080E42E0
	.4byte .L080E42EE
	.4byte .L080E42FC
.L080E424C:
	strb r2, [r3]
	b .L080E4322
.L080E4250:
	ldrb r1, [r3]
	adds r0, r1, r2
	strb r0, [r3]
	b .L080E4322
.L080E4258:
	ldrb r1, [r3]
	subs r0, r1, r2
	strb r0, [r3]
	b .L080E4322
.L080E4260:
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r3]
	b .L080E4322
.L080E426A:
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	ldrb r1, [r3]
	ldrb r0, [r0]
	adds r0, r1, r0
	strb r0, [r3]
	b .L080E4322
.L080E4278:
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	ldrb r1, [r3]
	ldrb r0, [r0]
	subs r0, r1, r0
	strb r0, [r3]
	b .L080E4322
.L080E4286:
	ldrb r3, [r3]
	cmp r3, r2
	beq .L080E4308
	b .L080E431C
.L080E428E:
	ldrb r3, [r3]
	cmp r3, r2
	bne .L080E4308
	b .L080E431C
.L080E4296:
	ldrb r3, [r3]
	cmp r3, r2
	bhi .L080E4308
	b .L080E431C
.L080E429E:
	ldrb r3, [r3]
	cmp r3, r2
	bhs .L080E4308
	b .L080E431C
.L080E42A6:
	ldrb r3, [r3]
	cmp r3, r2
	bls .L080E4308
	b .L080E431C
.L080E42AE:
	ldrb r3, [r3]
	cmp r3, r2
	blo .L080E4308
	b .L080E431C
.L080E42B6:
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	beq .L080E4308
	b .L080E431C
.L080E42C4:
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bne .L080E4308
	b .L080E431C
.L080E42D2:
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bhi .L080E4308
	b .L080E431C
.L080E42E0:
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bhs .L080E4308
	b .L080E431C
.L080E42EE:
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bls .L080E4308
	b .L080E431C
.L080E42FC:
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bhs .L080E431C
.L080E4308:
	ldr r0, .L080E4318
	ldr r2, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	bl _call_via_r2
	b .L080E4322
	.byte 0x00, 0x00
.L080E4318: .4byte 0x0203F154 @ EWRAM+0x3F154
.L080E431C:
	ldr r0, [r6, #0x40]
	adds r0, #4
	str r0, [r6, #0x40]
.L080E4322:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ply_xcmd
ply_xcmd: @ 0x080E4328
	push {lr}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	adds r2, #1
	str r2, [r1, #0x40]
	ldr r2, .L080E4344
	lsls r3, r3, #2
	adds r3, r3, r2
	ldr r2, [r3]
	bl _call_via_r2
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E4344: .4byte gUnknown_0858BE64

	thumb_func_start ply_xxx
ply_xxx: @ 0x080E4348
	push {lr}
	ldr r2, .L080E4358
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E4358: .4byte 0x0203F150 @ EWRAM+0x3F150

	thumb_func_start ply_xwave
ply_xwave: @ 0x080E435C
	push {r4, lr}
	ldr r2, [r1, #0x40]
	ldr r0, .L080E4394
	ands r4, r0
	ldrb r0, [r2]
	orrs r4, r0
	ldrb r0, [r2, #1]
	lsls r3, r0, #8
	ldr r0, .L080E4398
	ands r4, r0
	orrs r4, r3
	ldrb r0, [r2, #2]
	lsls r3, r0, #0x10
	ldr r0, .L080E439C
	ands r4, r0
	orrs r4, r3
	ldrb r0, [r2, #3]
	lsls r3, r0, #0x18
	ldr r0, .L080E43A0
	ands r4, r0
	orrs r4, r3
	str r4, [r1, #0x28]
	adds r2, #4
	str r2, [r1, #0x40]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E4394: .4byte 0xFFFFFF00
.L080E4398: .4byte 0xFFFF00FF
.L080E439C: .4byte 0xFF00FFFF
.L080E43A0: .4byte 0x00FFFFFF

	thumb_func_start ply_xtype
ply_xtype: @ 0x080E43A4
	ldr r0, [r1, #0x40]
	ldrb r2, [r0]
	adds r0, r1, #0
	adds r0, #0x24
	strb r2, [r0]
	ldr r0, [r1, #0x40]
	adds r0, #1
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ply_xatta
ply_xatta: @ 0x080E43B8
	ldr r0, [r1, #0x40]
	ldrb r2, [r0]
	adds r0, r1, #0
	adds r0, #0x2c
	strb r2, [r0]
	ldr r0, [r1, #0x40]
	adds r0, #1
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ply_xdeca
ply_xdeca: @ 0x080E43CC
	ldr r0, [r1, #0x40]
	ldrb r0, [r0]
	adds r2, r1, #0
	adds r2, #0x2d
	strb r0, [r2]
	ldr r0, [r1, #0x40]
	adds r0, #1
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ply_xsust
ply_xsust: @ 0x080E43E0
	ldr r0, [r1, #0x40]
	ldrb r0, [r0]
	adds r2, r1, #0
	adds r2, #0x2e
	strb r0, [r2]
	ldr r0, [r1, #0x40]
	adds r0, #1
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ply_xrele
ply_xrele: @ 0x080E43F4
	ldr r0, [r1, #0x40]
	ldrb r0, [r0]
	adds r2, r1, #0
	adds r2, #0x2f
	strb r0, [r2]
	ldr r0, [r1, #0x40]
	adds r0, #1
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ply_xiecv
ply_xiecv: @ 0x080E4408
	ldr r0, [r1, #0x40]
	ldrb r2, [r0]
	strb r2, [r1, #0x1e]
	adds r0, #1
	str r0, [r1, #0x40]
	bx lr

	thumb_func_start ply_xiecl
ply_xiecl: @ 0x080E4414
	ldr r0, [r1, #0x40]
	ldrb r2, [r0]
	strb r2, [r1, #0x1f]
	adds r0, #1
	str r0, [r1, #0x40]
	bx lr

	thumb_func_start ply_xleng
ply_xleng: @ 0x080E4420
	ldr r0, [r1, #0x40]
	ldrb r0, [r0]
	adds r2, r1, #0
	adds r2, #0x26
	strb r0, [r2]
	ldr r0, [r1, #0x40]
	adds r0, #1
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ply_xswee
ply_xswee: @ 0x080E4434
	ldr r0, [r1, #0x40]
	ldrb r0, [r0]
	adds r2, r1, #0
	adds r2, #0x27
	strb r0, [r2]
	ldr r0, [r1, #0x40]
	adds r0, #1
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start DummyFunc
DummyFunc: @ 0x080E4448
	bx lr
	.byte 0x00, 0x00

	thumb_func_start Demon_GetGfxRecord
Demon_GetGfxRecord: @ 0x080E444C
.L080E444C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	ldr r2, .L080E4470
	ldr r0, .L080E4474
	cmp r1, r0
	bne .L080E4480
	ldr r1, .L080E4478
	adds r0, r2, r1
	ldrh r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L080E447C
	adds r0, r0, r1
	b .L080E449A
	.byte 0x00, 0x00
.L080E4470: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E4474: .4byte 0x0000012D
.L080E4478: .4byte 0x000011A4
.L080E447C: .4byte gUnknown_0872F104
.L080E4480:
	movs r0, #0x97
	lsls r0, r0, #1
	cmp r1, r0
	beq .L080E4498
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L080E4494
	adds r0, r0, r1
	b .L080E449A
.L080E4494: .4byte gDemonGfxRecords
.L080E4498:
	ldr r0, .L080E44A0
.L080E449A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080E44A0: .4byte gUnknown_0872F174

	thumb_func_start sub_080E44A4
sub_080E44A4: @ 0x080E44A4
.L080E44A4:
	push {r4, r5, lr}
	sub sp, #4
	ldr r4, .L080E44E4
	movs r5, #0
	str r5, [sp]
	ldr r1, .L080E44E8
	ldr r2, .L080E44EC
	mov r0, sp
	bl CpuSet
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r4, r0
	adds r0, #4
	adds r1, r4, r0
	ldr r0, .L080E44F0
	str r0, [r1]
	str r0, [r2]
	movs r0, #0
	bl BattleMsg_SetLocked
	bl sub_080E44F8
	bl sub_080EA280
	ldr r0, .L080E44F4
	adds r4, r4, r0
	strb r5, [r4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E44E4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E44E8: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E44EC: .4byte 0x05000007 @ PLTT+0x7
.L080E44F0: .4byte 0x0000FFFF
.L080E44F4: .4byte 0x00001188

	thumb_func_start sub_080E44F8
sub_080E44F8: @ 0x080E44F8
.L080E44F8:
	ldr r0, .L080E4518
	movs r1, #0
	str r1, [r0, #0xc]
	str r1, [r0, #8]
	str r1, [r0, #4]
	str r1, [r0, #0x24]
	str r1, [r0, #0x20]
	str r1, [r0, #0x1c]
	str r1, [r0, #0x18]
	str r1, [r0, #0x14]
	str r1, [r0, #0x10]
	ldr r2, .L080E451C
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080E4518: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E451C: .4byte 0x0000119E

	thumb_func_start sub_080E4520
sub_080E4520: @ 0x080E4520
.L080E4520:
	push {r4, r5, lr}
	movs r1, #0
.L080E4524:
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	movs r4, #0xa
	cmp r5, #3
	bgt .L080E4530
	movs r4, #4
.L080E4530:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080C35C4
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080C3600
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	ble .L080E4524
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E4554
sub_080E4554: @ 0x080E4554
.L080E4554:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r7, .L080E459C
	bl sub_080E44F8
	ldr r1, .L080E45A0
	adds r0, r7, r1
	movs r2, #0
	strh r2, [r0]
	ldr r0, .L080E45A4
	adds r1, r7, r0
	ldr r0, .L080E45A8
	strh r0, [r1]
	ldr r0, .L080E45AC
	adds r1, r7, r0
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	ldr r1, .L080E45B0
	adds r0, r7, r1
	strh r2, [r0]
	ldr r3, .L080E45B4
	strh r2, [r3, #0x14]
	ldr r0, .L080E45B8
	movs r2, #0xac
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrh r1, [r0]
	cmp r1, #0
	beq .L080E45BC
	cmp r1, #1
	beq .L080E45DC
	b .L080E45F8
	.byte 0x00, 0x00
.L080E459C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E45A0: .4byte 0x0000118C
.L080E45A4: .4byte 0x000011AC
.L080E45A8: .4byte 0x0000FFFF
.L080E45AC: .4byte 0x000011AE
.L080E45B0: .4byte 0x000011A8
.L080E45B4: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E45B8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E45BC:
	movs r0, #2
	strh r0, [r3, #0xc]
	strh r1, [r3, #0x14]
	bl sub_080C5D0C
	adds r2, r0, #0
	movs r0, #0x7f
	ands r2, r0
	cmp r2, #0x6b
	bls .L080E45D2
	movs r2, #0x3e
.L080E45D2:
	add r1, sp, #4
	mov r0, sp
	bl sub_080ED398
	b .L080E45E6
.L080E45DC:
	strh r1, [r3, #0xc]
	add r1, sp, #4
	mov r0, sp
	bl sub_080F450C
.L080E45E6:
	movs r0, #0x98
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [sp]
	str r0, [r1]
	ldr r1, [sp, #4]
	ldr r2, .L080E46E0
	adds r0, r7, r2
	strh r1, [r0]
.L080E45F8:
	movs r4, #0
	str r4, [r7]
	ldr r1, .L080E46E4
	adds r0, r7, r1
	str r4, [r0]
	movs r2, #0x97
	lsls r2, r2, #4
	adds r0, r7, r2
	str r4, [r0]
	ldr r1, .L080E46E8
	adds r0, r7, r1
	strh r4, [r0]
	adds r2, #8
	adds r0, r7, r2
	strh r4, [r0]
	ldr r1, .L080E46EC
	adds r0, r7, r1
	strh r4, [r0]
	adds r2, #4
	adds r0, r7, r2
	strh r4, [r0]
	adds r1, #4
	adds r0, r7, r1
	strh r4, [r0]
	bl sub_080ED7BC
	ldr r2, .L080E46F0
	adds r0, r7, r2
	strh r4, [r0]
	ldr r0, .L080E46F4
	adds r5, r7, r0
	strh r4, [r5]
	movs r0, #0
	bl sub_080ED938
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	ble .L080E464E
	ldr r2, .L080E46E0
	adds r1, r7, r2
	movs r0, #1
	strh r0, [r1]
.L080E464E:
	ldr r0, .L080E46E0
	adds r1, r7, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne .L080E465E
	movs r0, #1
	strh r0, [r1]
.L080E465E:
	ldrh r1, [r1]
	ldr r2, .L080E46F8
	adds r0, r7, r2
	strh r1, [r0]
	bl sub_080E74DC
	movs r0, #0
.L080E466C:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_080BFD94
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble .L080E466C
	ldr r4, .L080E46FC
	movs r6, #0
	movs r0, #0
	mov r8, r0
	movs r5, #1
	strh r5, [r4]
	ldr r1, .L080E46F4
	adds r0, r7, r1
	mov r2, r8
	strh r2, [r0]
	ldr r1, .L080E4700
	adds r0, r7, r1
	strb r6, [r0]
	bl sub_080C7C60
	movs r0, #0
	bl BattleMsg_SetLocked
	ldr r2, .L080E4704
	adds r0, r7, r2
	strb r6, [r0]
	strh r5, [r4, #6]
	mov r0, r8
	strh r0, [r4, #0xa]
	ldr r0, .L080E4708
	bl sub_080E5668
	ldr r0, .L080E470C
	ldr r1, .L080E4710
	bl Task_Create
	str r0, [r4, #0x18]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L080E4714
	ldrh r1, [r0]
	ldr r2, .L080E4718
	adds r0, r7, r2
	strh r1, [r0]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E46E0: .4byte 0x0000099C
.L080E46E4: .4byte 0x00000974
.L080E46E8: .4byte 0x00000F68
.L080E46EC: .4byte 0x0000097A
.L080E46F0: .4byte 0x00000ECE
.L080E46F4: .4byte 0x00000F6A
.L080E46F8: .4byte 0x0000099E
.L080E46FC: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E4700: .4byte 0x00001122
.L080E4704: .4byte 0x00001123
.L080E4708: .4byte sub_080E5674
.L080E470C: .4byte gUnknown_086BEF88
.L080E4710: .4byte 0x0000FFFF
.L080E4714: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080E4718: .4byte 0x0000118A

	thumb_func_start sub_080E471C
sub_080E471C: @ 0x080E471C
.L080E471C:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r3, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r7, .L080E477C
	str r2, [sp]
	bl sub_080E4554
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r7, r1
	str r4, [r0]
	ldr r3, .L080E4780
	adds r0, r7, r3
	ldr r2, [sp]
	str r2, [r0]
	adds r1, #8
	adds r0, r7, r1
	movs r1, #0
	strh r5, [r0]
	adds r3, #6
	adds r0, r7, r3
	strh r6, [r0]
	subs r3, #0x1a
	adds r0, r7, r3
	str r1, [r0]
	ldr r1, .L080E4784
	adds r0, r7, r1
	movs r1, #1
	strh r1, [r0]
	adds r3, #0x1e
	adds r0, r7, r3
	strh r1, [r0]
	ldr r0, .L080E4788
	cmp r2, r0
	beq .L080E478C
	bl sub_080ED938
	b .L080E4792
.L080E477C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E4780: .4byte 0x00000994
.L080E4784: .4byte 0x0000099C
.L080E4788: .4byte 0x0000FFFF
.L080E478C:
	movs r0, #0
	bl sub_080ED938
.L080E4792:
	ldr r0, .L080E47A4
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E47A4: .4byte 0x00001123
