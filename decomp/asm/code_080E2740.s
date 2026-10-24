	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start RealClearChain
RealClearChain: @ 0x080E2740
.L080E2740:
	ldr r3, [r0, #0x2c]
	cmp r3, #0
	beq .L080E275E
	ldr r1, [r0, #0x34]
	ldr r2, [r0, #0x30]
	cmp r2, #0
	beq .L080E2752
	str r1, [r2, #0x34]
	b .L080E2754
.L080E2752:
	str r1, [r3, #0x20]
.L080E2754:
	cmp r1, #0
	beq .L080E275A
	str r2, [r1, #0x30]
.L080E275A:
	movs r1, #0
	str r1, [r0, #0x2c]
.L080E275E:
	bx lr
.L080E2760:
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq .L080E2784
.L080E276A:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq .L080E2778
	movs r0, #0x40
	orrs r1, r0
	strb r1, [r4]
.L080E2778:
	adds r0, r4, #0
	bl RealClearChain
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne .L080E276A
.L080E2784:
	movs r0, #0
	strb r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start MPlayJumpTableCopy
MPlayJumpTableCopy: @ 0x080E2790
.L080E2790:
	mov ip, lr
	movs r1, #0x24
	ldr r2, .L080E27C0
.L080E2796:
	ldr r3, [r2]
	bl chk_adr_r2
	stm r0!, {r3}
	adds r2, #4
	subs r1, #1
	bgt .L080E2796
	bx ip
	.byte 0x00, 0x00

	thumb_func_start ldrb_r3_r2
ldrb_r3_r2: @ 0x080E27A8
.L080E27A8:
	ldrb r3, [r2]

	thumb_func_start chk_adr_r2
chk_adr_r2: @ 0x080E27AA
.L080E27AA:
	push {r0}
	lsrs r0, r2, #0x19
	bne .L080E27BC
	ldr r0, .L080E27C0
	cmp r2, r0
	blo .L080E27BA
	lsrs r0, r2, #0xe
	beq .L080E27BC
.L080E27BA:
	movs r3, #0
.L080E27BC:
	pop {r0}
	bx lr
.L080E27C0: .4byte gMPlayJumpTableTemplate

	thumb_func_start ld_r3_tp_adr_i
ld_r3_tp_adr_i: @ 0x080E27C4
.L080E27C4:
	ldr r2, [r1, #0x40]

	thumb_func_start sub_080E27C6
sub_080E27C6: @ 0x080E27C6
.L080E27C6:
	adds r3, r2, #1
	str r3, [r1, #0x40]
	ldrb r3, [r2]
	b chk_adr_r2
	.byte 0x00, 0x00
.L080E27D0:
	push {lr}
.L080E27D2:
	ldr r2, [r1, #0x40]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	ldrb r3, [r2, #2]
	orrs r0, r3
	lsls r0, r0, #8
	ldrb r3, [r2, #1]
	orrs r0, r3
	lsls r0, r0, #8
	bl ldrb_r3_r2
	orrs r0, r3
	str r0, [r1, #0x40]
	pop {r0}
	bx r0

	thumb_func_start ply_patt
ply_patt: @ 0x080E27F0
	ldrb r2, [r1, #2]
	cmp r2, #3
	bhs .L080E2808
	lsls r2, r2, #2
	adds r3, r1, r2
	ldr r2, [r1, #0x40]
	adds r2, #4
	str r2, [r3, #0x44]
	ldrb r2, [r1, #2]
	adds r2, #1
	strb r2, [r1, #2]
	b .L080E27D0
.L080E2808:
	b .L080E2760
	.byte 0x00, 0x00

	thumb_func_start ply_pend
ply_pend: @ 0x080E280C
	ldrb r2, [r1, #2]
	cmp r2, #0
	beq .L080E281E
	subs r2, #1
	strb r2, [r1, #2]
	lsls r2, r2, #2
	adds r3, r1, r2
	ldr r2, [r3, #0x44]
	str r2, [r1, #0x40]
.L080E281E:
	bx lr

	thumb_func_start ply_rept
ply_rept: @ 0x080E2820
	push {lr}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	cmp r3, #0
	bne .L080E2830
	adds r2, #1
	str r2, [r1, #0x40]
	b .L080E27D2
.L080E2830:
	ldrb r3, [r1, #3]
	adds r3, #1
	strb r3, [r1, #3]
	mov ip, r3
	bl ld_r3_tp_adr_i
	cmp ip, r3
	bhs .L080E2842
	b .L080E27D2
.L080E2842:
	movs r3, #0
	strb r3, [r1, #3]
	adds r2, #5
	str r2, [r1, #0x40]
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start ply_prio
ply_prio: @ 0x080E2850
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0x1d]
	bx ip
	.byte 0x00, 0x00

	thumb_func_start ply_tempo
ply_tempo: @ 0x080E285C
	mov ip, lr
	bl ld_r3_tp_adr_i
	lsls r3, r3, #1
	strh r3, [r0, #0x1c]
	ldrh r2, [r0, #0x1e]
	muls r3, r2, r3
	lsrs r3, r3, #8
	strh r3, [r0, #0x20]
	bx ip

	thumb_func_start ply_keysh
ply_keysh: @ 0x080E2870
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0xa]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.byte 0x00, 0x00

	thumb_func_start ply_voice
ply_voice: @ 0x080E2884
	mov ip, lr
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	adds r2, #1
	str r2, [r1, #0x40]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	ldr r3, [r0, #0x30]
	adds r2, r2, r3
	ldr r3, [r2]
	bl chk_adr_r2
	str r3, [r1, #0x24]
	ldr r3, [r2, #4]
	bl chk_adr_r2
	str r3, [r1, #0x28]
	ldr r3, [r2, #8]
	bl chk_adr_r2
	str r3, [r1, #0x2c]
	bx ip
	.byte 0x00, 0x00

	thumb_func_start ply_vol
ply_vol: @ 0x080E28B4
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0x12]
	ldrb r3, [r1]
	movs r2, #3
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.byte 0x00, 0x00

	thumb_func_start ply_pan
ply_pan: @ 0x080E28C8
	mov ip, lr
	bl ld_r3_tp_adr_i
	subs r3, #0x40
	strb r3, [r1, #0x14]
	ldrb r3, [r1]
	movs r2, #3
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start ply_bend
ply_bend: @ 0x080E28DC
	mov ip, lr
	bl ld_r3_tp_adr_i
	subs r3, #0x40
	strb r3, [r1, #0xe]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start ply_bendr
ply_bendr: @ 0x080E28F0
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0xf]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.byte 0x00, 0x00

	thumb_func_start ply_lfodl
ply_lfodl: @ 0x080E2904
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0x1b]
	bx ip
	.byte 0x00, 0x00

	thumb_func_start ply_modt
ply_modt: @ 0x080E2910
	mov ip, lr
	bl ld_r3_tp_adr_i
	ldrb r0, [r1, #0x18]
	cmp r0, r3
	beq .L080E2926
	strb r3, [r1, #0x18]
	ldrb r3, [r1]
	movs r2, #0xf
	orrs r3, r2
	strb r3, [r1]
.L080E2926:
	bx ip

	thumb_func_start ply_tune
ply_tune: @ 0x080E2928
	mov ip, lr
	bl ld_r3_tp_adr_i
	subs r3, #0x40
	strb r3, [r1, #0xc]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start ply_port
ply_port: @ 0x080E293C
	mov ip, lr
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	adds r2, #1
	ldr r0, .L080E2950
	adds r0, r0, r3
	bl sub_080E27C6
	strb r3, [r0]
	bx ip
.L080E2950: .4byte 0x04000060 @ REG_SOUND1CNT_L

	thumb_func_start m4aSoundVSync
m4aSoundVSync: @ 0x080E2954
.L080E2954:
	ldr r0, .L080E2BF0
	ldr r0, [r0]
	ldr r2, .L080E2BF4
	ldr r3, [r0]
	subs r3, r3, r2
	cmp r3, #1
	bhi .L080E2986
	ldrb r1, [r0, #4]
	subs r1, #1
	strb r1, [r0, #4]
	bgt .L080E2986
	ldrb r1, [r0, #0xb]
	strb r1, [r0, #4]
	ldr r2, .L080E2988
	ldr r1, [r2, #8]
	lsls r1, r1, #7
	blo .L080E297A
	ldr r1, .L080E298C
	str r1, [r2, #8]
.L080E297A:
	movs r1, #4
	lsls r1, r1, #8
	strh r1, [r2, #0xa]
	movs r1, #0xb6
	lsls r1, r1, #8
	strh r1, [r2, #0xa]
.L080E2986:
	bx lr
.L080E2988: .4byte 0x040000BC @ REG_DMA1SAD
.L080E298C: .4byte 0x84400004

	thumb_func_start MPlayMain
MPlayMain: @ 0x080E2990
	ldr r2, .L080E2BF4
	ldr r3, [r0, #0x34]
	cmp r2, r3
	beq .L080E299A
	bx lr
.L080E299A:
	adds r3, #1
	str r3, [r0, #0x34]
	push {r0, lr}
	ldr r3, [r0, #0x38]
	cmp r3, #0
	beq .L080E29AC
	ldr r0, [r0, #0x3c]
	bl sub_080E2BE8
.L080E29AC:
	pop {r0}
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	adds r7, r0, #0
	ldr r0, [r7, #4]
	cmp r0, #0
	bge .L080E29C4
	b .L080E2BD8
.L080E29C4:
	ldr r0, .L080E2BF0
	ldr r0, [r0]
	mov r8, r0
	adds r0, r7, #0
	bl FadeOutBody
	ldr r0, [r7, #4]
	cmp r0, #0
	bge .L080E29D8
	b .L080E2BD8
.L080E29D8:
	ldrh r0, [r7, #0x22]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	b .L080E2B28
.L080E29E0:
	ldrb r6, [r7, #8]
	ldr r5, [r7, #0x2c]
	movs r3, #1
	movs r4, #0
.L080E29E8:
	ldrb r0, [r5]
	movs r1, #0x80
	tst r1, r0
	bne .L080E29F2
	b .L080E2B04
.L080E29F2:
	mov sl, r3
	orrs r4, r3
	mov fp, r4
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq .L080E2A26
.L080E29FE:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq .L080E2A1A
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq .L080E2A20
	subs r0, #1
	strb r0, [r4, #0x10]
	bne .L080E2A20
	movs r0, #0x40
	orrs r1, r0
	strb r1, [r4]
	b .L080E2A20
.L080E2A1A:
	adds r0, r4, #0
	bl ClearChain
.L080E2A20:
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne .L080E29FE
.L080E2A26:
	ldrb r3, [r5]
	movs r0, #0x40
	tst r0, r3
	beq .L080E2AA4
	adds r0, r5, #0
	bl Clear64byte
	movs r0, #0x80
	strb r0, [r5]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0x40
	strb r0, [r5, #0x13]
	movs r0, #0x16
	strb r0, [r5, #0x19]
	movs r0, #1
	adds r1, r5, #6
	strb r0, [r1, #0x1e]
	b .L080E2AA4
.L080E2A4C:
	ldr r2, [r5, #0x40]
	ldrb r1, [r2]
	cmp r1, #0x80
	bhs .L080E2A58
	ldrb r1, [r5, #7]
	b .L080E2A62
.L080E2A58:
	adds r2, #1
	str r2, [r5, #0x40]
	cmp r1, #0xbd
	blo .L080E2A62
	strb r1, [r5, #7]
.L080E2A62:
	cmp r1, #0xcf
	blo .L080E2A78
	mov r0, r8
	ldr r3, [r0, #0x38]
	adds r0, r1, #0
	subs r0, #0xcf
	adds r1, r7, #0
	adds r2, r5, #0
	bl sub_080E2BE8
	b .L080E2AA4
.L080E2A78:
	cmp r1, #0xb0
	bls .L080E2A9A
	adds r0, r1, #0
	subs r0, #0xb1
	strb r0, [r7, #0xa]
	mov r3, r8
	ldr r3, [r3, #0x34]
	lsls r0, r0, #2
	ldr r3, [r3, r0]
	adds r0, r7, #0
	adds r1, r5, #0
	bl sub_080E2BE8
	ldrb r0, [r5]
	cmp r0, #0
	beq .L080E2B00
	b .L080E2AA4
.L080E2A9A:
	ldr r0, .L080E2BEC
	subs r1, #0x80
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r5, #1]
.L080E2AA4:
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq .L080E2A4C
	subs r0, #1
	strb r0, [r5, #1]
	ldrb r1, [r5, #0x19]
	cmp r1, #0
	beq .L080E2B00
	ldrb r0, [r5, #0x17]
	cmp r0, #0
	beq .L080E2B00
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq .L080E2AC6
	subs r0, #1
	strb r0, [r5, #0x1c]
	b .L080E2B00
.L080E2AC6:
	ldrb r0, [r5, #0x1a]
	adds r0, r0, r1
	strb r0, [r5, #0x1a]
	adds r1, r0, #0
	subs r0, #0x40
	lsls r0, r0, #0x18
	bpl .L080E2ADA
	lsls r2, r1, #0x18
	asrs r2, r2, #0x18
	b .L080E2ADE
.L080E2ADA:
	movs r0, #0x80
	subs r2, r0, r1
.L080E2ADE:
	ldrb r0, [r5, #0x17]
	muls r0, r2, r0
	asrs r2, r0, #6
	ldrb r0, [r5, #0x16]
	eors r0, r2
	lsls r0, r0, #0x18
	beq .L080E2B00
	strb r2, [r5, #0x16]
	ldrb r0, [r5]
	ldrb r1, [r5, #0x18]
	cmp r1, #0
	bne .L080E2AFA
	movs r1, #0xc
	b .L080E2AFC
.L080E2AFA:
	movs r1, #3
.L080E2AFC:
	orrs r0, r1
	strb r0, [r5]
.L080E2B00:
	mov r3, sl
	mov r4, fp
.L080E2B04:
	subs r6, #1
	ble .L080E2B10
	movs r0, #0x50
	adds r5, r5, r0
	lsls r3, r3, #1
	b .L080E29E8
.L080E2B10:
	ldr r0, [r7, #0xc]
	adds r0, #1
	str r0, [r7, #0xc]
	cmp r4, #0
	bne .L080E2B22
	movs r0, #0x80
	lsls r0, r0, #0x18
	str r0, [r7, #4]
	b .L080E2BD8
.L080E2B22:
	str r4, [r7, #4]
	ldrh r0, [r7, #0x22]
	subs r0, #0x96
.L080E2B28:
	strh r0, [r7, #0x22]
	cmp r0, #0x96
	blo .L080E2B30
	b .L080E29E0
.L080E2B30:
	ldrb r2, [r7, #8]
	ldr r5, [r7, #0x2c]
.L080E2B34:
	ldrb r0, [r5]
	movs r1, #0x80
	tst r1, r0
	beq .L080E2BCE
	movs r1, #0xf
	tst r1, r0
	beq .L080E2BCE
	mov sb, r2
	adds r0, r7, #0
	adds r1, r5, #0
	bl TrkVolPitSet
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq .L080E2BC4
.L080E2B52:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	bne .L080E2B62
	adds r0, r4, #0
	bl ClearChain
	b .L080E2BBE
.L080E2B62:
	ldrb r0, [r4, #1]
	movs r6, #7
	ands r6, r0
	ldrb r3, [r5]
	movs r0, #3
	tst r0, r3
	beq .L080E2B80
	bl ChnVolSetAsm
	cmp r6, #0
	beq .L080E2B80
	ldrb r0, [r4, #0x1d]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0x1d]
.L080E2B80:
	ldrb r3, [r5]
	movs r0, #0xc
	tst r0, r3
	beq .L080E2BBE
	ldrb r1, [r4, #8]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r2, r1, r0
	bpl .L080E2B94
	movs r2, #0
.L080E2B94:
	cmp r6, #0
	beq .L080E2BB2
	mov r0, r8
	ldr r3, [r0, #0x30]
	adds r1, r2, #0
	ldrb r2, [r5, #9]
	adds r0, r6, #0
	bl sub_080E2BE8
	str r0, [r4, #0x20]
	ldrb r0, [r4, #0x1d]
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0x1d]
	b .L080E2BBE
.L080E2BB2:
	adds r1, r2, #0
	ldrb r2, [r5, #9]
	ldr r0, [r4, #0x24]
	bl MidiKeyToFreq
	str r0, [r4, #0x20]
.L080E2BBE:
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne .L080E2B52
.L080E2BC4:
	ldrb r0, [r5]
	movs r1, #0xf0
	ands r0, r1
	strb r0, [r5]
	mov r2, sb
.L080E2BCE:
	subs r2, #1
	ble .L080E2BD8
	movs r0, #0x50
	adds r5, r5, r0
	bgt .L080E2B34
.L080E2BD8:
	ldr r0, .L080E2BF4
	str r0, [r7, #0x34]
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r3}

	thumb_func_start sub_080E2BE8
sub_080E2BE8: @ 0x080E2BE8
.L080E2BE8:
	bx r3
	.byte 0x00, 0x00
.L080E2BEC: .4byte gUnknown_0858BE30
.L080E2BF0: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E2BF4: .4byte 0x68736D53

	thumb_func_start TrackStop
TrackStop: @ 0x080E2BF8
.L080E2BF8:
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	ldrb r1, [r5]
	movs r0, #0x80
	tst r0, r1
	beq .L080E2C30
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq .L080E2C2E
	movs r6, #0
.L080E2C0C:
	ldrb r0, [r4]
	cmp r0, #0
	beq .L080E2C26
	ldrb r0, [r4, #1]
	movs r3, #7
	ands r0, r3
	beq .L080E2C24
	ldr r3, .L080E2C38
	ldr r3, [r3]
	ldr r3, [r3, #0x2c]
	bl sub_080E2BE8
.L080E2C24:
	strb r6, [r4]
.L080E2C26:
	str r6, [r4, #0x2c]
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne .L080E2C0C
.L080E2C2E:
	str r4, [r5, #0x20]
.L080E2C30:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E2C38: .4byte 0x03007FF0 @ IWRAM+0x7FF0

	thumb_func_start ChnVolSetAsm
ChnVolSetAsm: @ 0x080E2C3C
.L080E2C3C:
	ldrb r1, [r4, #0x12]
	movs r0, #0x14
	ldrsb r2, [r4, r0]
	movs r3, #0x80
	adds r3, r3, r2
	muls r3, r1, r3
	ldrb r0, [r5, #0x10]
	muls r0, r3, r0
	asrs r0, r0, #0xe
	cmp r0, #0xff
	bls .L080E2C54
	movs r0, #0xff
.L080E2C54:
	strb r0, [r4, #2]
	movs r3, #0x7f
	subs r3, r3, r2
	muls r3, r1, r3
	ldrb r0, [r5, #0x11]
	muls r0, r3, r0
	asrs r0, r0, #0xe
	cmp r0, #0xff
	bls .L080E2C68
	movs r0, #0xff
.L080E2C68:
	strb r0, [r4, #3]
	bx lr

	thumb_func_start ply_note
ply_note: @ 0x080E2C6C
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	sub sp, #0x18
	str r1, [sp]
	adds r5, r2, #0
	ldr r1, .L080E2E64
	ldr r1, [r1]
	str r1, [sp, #4]
	ldr r1, .L080E2E68
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #4]
	ldr r3, [r5, #0x40]
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs .L080E2CB2
	strb r0, [r5, #5]
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs .L080E2CB0
	strb r0, [r5, #6]
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs .L080E2CB0
	ldrb r1, [r5, #4]
	adds r1, r1, r0
	strb r1, [r5, #4]
	adds r3, #1
.L080E2CB0:
	str r3, [r5, #0x40]
.L080E2CB2:
	movs r0, #0
	str r0, [sp, #0x14]
	adds r4, r5, #0
	adds r4, #0x24
	ldrb r2, [r4]
	movs r0, #0xc0
	tst r0, r2
	beq .L080E2D04
	ldrb r3, [r5, #5]
	movs r0, #0x40
	tst r0, r2
	beq .L080E2CD2
	ldr r1, [r5, #0x2c]
	adds r1, r1, r3
	ldrb r0, [r1]
	b .L080E2CD4
.L080E2CD2:
	adds r0, r3, #0
.L080E2CD4:
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r5, #0x28]
	adds r1, r1, r0
	mov sb, r1
	mov r6, sb
	ldrb r1, [r6]
	movs r0, #0xc0
	tst r0, r1
	beq .L080E2CEC
	b .L080E2E52
.L080E2CEC:
	movs r0, #0x80
	tst r0, r2
	beq .L080E2D08
	ldrb r1, [r6, #3]
	movs r0, #0x80
	tst r0, r1
	beq .L080E2D00
	subs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp, #0x14]
.L080E2D00:
	ldrb r3, [r6, #1]
	b .L080E2D08
.L080E2D04:
	mov sb, r4
	ldrb r3, [r5, #5]
.L080E2D08:
	str r3, [sp, #8]
	ldr r6, [sp]
	ldrb r1, [r6, #9]
	ldrb r0, [r5, #0x1d]
	adds r0, r0, r1
	cmp r0, #0xff
	bls .L080E2D18
	movs r0, #0xff
.L080E2D18:
	str r0, [sp, #0x10]
	mov r6, sb
	ldrb r0, [r6]
	movs r6, #7
	ands r6, r0
	str r6, [sp, #0xc]
	beq .L080E2D58
	ldr r0, [sp, #4]
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	bne .L080E2D30
	b .L080E2E52
.L080E2D30:
	subs r6, #1
	lsls r0, r6, #6
	adds r4, r4, r0
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq .L080E2DAC
	movs r0, #0x40
	tst r0, r1
	bne .L080E2DAC
	ldrb r1, [r4, #0x13]
	ldr r0, [sp, #0x10]
	cmp r1, r0
	blo .L080E2DAC
	beq .L080E2D50
	b .L080E2E52
.L080E2D50:
	ldr r0, [r4, #0x2c]
	cmp r0, r5
	bhs .L080E2DAC
	b .L080E2E52
.L080E2D58:
	ldr r6, [sp, #0x10]
	adds r7, r5, #0
	movs r2, #0
	mov r8, r2
	ldr r4, [sp, #4]
	ldrb r3, [r4, #6]
	adds r4, #0x50
.L080E2D66:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq .L080E2DAC
	movs r0, #0x40
	tst r0, r1
	beq .L080E2D80
	cmp r2, #0
	bne .L080E2D84
	adds r2, #1
	ldrb r6, [r4, #0x13]
	ldr r7, [r4, #0x2c]
	b .L080E2D9E
.L080E2D80:
	cmp r2, #0
	bne .L080E2DA0
.L080E2D84:
	ldrb r0, [r4, #0x13]
	cmp r0, r6
	bhs .L080E2D90
	adds r6, r0, #0
	ldr r7, [r4, #0x2c]
	b .L080E2D9E
.L080E2D90:
	bhi .L080E2DA0
	ldr r0, [r4, #0x2c]
	cmp r0, r7
	bls .L080E2D9C
	adds r7, r0, #0
	b .L080E2D9E
.L080E2D9C:
	blo .L080E2DA0
.L080E2D9E:
	mov r8, r4
.L080E2DA0:
	adds r4, #0x40
	subs r3, #1
	bgt .L080E2D66
	mov r4, r8
	cmp r4, #0
	beq .L080E2E52
.L080E2DAC:
	adds r0, r4, #0
	bl ClearChain
	movs r1, #0
	str r1, [r4, #0x30]
	ldr r3, [r5, #0x20]
	str r3, [r4, #0x34]
	cmp r3, #0
	beq .L080E2DC0
	str r4, [r3, #0x30]
.L080E2DC0:
	str r4, [r5, #0x20]
	str r5, [r4, #0x2c]
	ldrb r0, [r5, #0x1b]
	strb r0, [r5, #0x1c]
	cmp r0, r1
	beq .L080E2DD2
	adds r1, r5, #0
	bl clear_modM
.L080E2DD2:
	ldr r0, [sp]
	adds r1, r5, #0
	bl TrkVolPitSet
	ldr r0, [r5, #4]
	str r0, [r4, #0x10]
	ldr r0, [sp, #0x10]
	strb r0, [r4, #0x13]
	ldr r0, [sp, #8]
	strb r0, [r4, #8]
	ldr r0, [sp, #0x14]
	strb r0, [r4, #0x14]
	mov r6, sb
	ldrb r0, [r6]
	strb r0, [r4, #1]
	ldr r7, [r6, #4]
	str r7, [r4, #0x24]
	ldr r0, [r6, #8]
	str r0, [r4, #4]
	ldrh r0, [r5, #0x1e]
	strh r0, [r4, #0xc]
	bl ChnVolSetAsm
	ldrb r1, [r4, #8]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r3, r1, r0
	bpl .L080E2E0C
	movs r3, #0
.L080E2E0C:
	ldr r6, [sp, #0xc]
	cmp r6, #0
	beq .L080E2E3A
	mov r6, sb
	ldrb r0, [r6, #2]
	strb r0, [r4, #0x1e]
	ldrb r1, [r6, #3]
	movs r0, #0x80
	tst r0, r1
	bne .L080E2E26
	movs r0, #0x70
	tst r0, r1
	bne .L080E2E28
.L080E2E26:
	movs r1, #8
.L080E2E28:
	strb r1, [r4, #0x1f]
	ldrb r2, [r5, #9]
	adds r1, r3, #0
	ldr r0, [sp, #0xc]
	ldr r3, [sp, #4]
	ldr r3, [r3, #0x30]
	bl sub_080E2BE8
	b .L080E2E44
.L080E2E3A:
	ldrb r2, [r5, #9]
	adds r1, r3, #0
	adds r0, r7, #0
	bl MidiKeyToFreq
.L080E2E44:
	str r0, [r4, #0x20]
	movs r0, #0x80
	strb r0, [r4]
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	strb r0, [r5]
.L080E2E52:
	add sp, #0x18
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E2E64: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E2E68: .4byte gUnknown_0858BE30

	thumb_func_start ply_endtie
ply_endtie: @ 0x080E2E6C
	push {r4, r5}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	cmp r3, #0x80
	bhs .L080E2E7E
	strb r3, [r1, #5]
	adds r2, #1
	str r2, [r1, #0x40]
	b .L080E2E80
.L080E2E7E:
	ldrb r3, [r1, #5]
.L080E2E80:
	ldr r1, [r1, #0x20]
	cmp r1, #0
	beq .L080E2EA8
	movs r4, #0x83
	movs r5, #0x40
.L080E2E8A:
	ldrb r2, [r1]
	tst r2, r4
	beq .L080E2EA2
	tst r2, r5
	bne .L080E2EA2
	ldrb r0, [r1, #0x11]
	cmp r0, r3
	bne .L080E2EA2
	movs r0, #0x40
	orrs r2, r0
	strb r2, [r1]
	b .L080E2EA8
.L080E2EA2:
	ldr r1, [r1, #0x34]
	cmp r1, #0
	bne .L080E2E8A
.L080E2EA8:
	pop {r4, r5}
	bx lr

	thumb_func_start clear_modM
clear_modM: @ 0x080E2EAC
.L080E2EAC:
	movs r2, #0
	strb r2, [r1, #0x16]
	strb r2, [r1, #0x1a]
	ldrb r2, [r1, #0x18]
	cmp r2, #0
	bne .L080E2EBC
	movs r2, #0xc
	b .L080E2EBE
.L080E2EBC:
	movs r2, #3
.L080E2EBE:
	ldrb r3, [r1]
	orrs r3, r2
	strb r3, [r1]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ld_r3_tp_adr_i_2
ld_r3_tp_adr_i_2: @ 0x080E2EC8
.L080E2EC8:
	ldr r2, [r1, #0x40]
	adds r3, r2, #1
	str r3, [r1, #0x40]
	ldrb r3, [r2]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ply_lfos
ply_lfos: @ 0x080E2ED4
	mov ip, lr
	bl ld_r3_tp_adr_i_2
	strb r3, [r1, #0x19]
	cmp r3, #0
	bne .L080E2EE4
	bl clear_modM
.L080E2EE4:
	bx ip
	.byte 0x00, 0x00

	thumb_func_start ply_mod
ply_mod: @ 0x080E2EE8
	mov ip, lr
	bl ld_r3_tp_adr_i_2
	strb r3, [r1, #0x17]
	cmp r3, #0
	bne .L080E2EF8
	bl clear_modM
.L080E2EF8:
	bx ip
	.byte 0x00, 0x00
