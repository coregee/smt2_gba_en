	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start umul3232H32
umul3232H32: @ 0x080E2364
.L080E2364:
	add r2, pc, #0
	bx r2
	.arm
	umull r2, r3, r0, r1
	add r0, r3, #0
	bx lr
	.thumb

	thumb_func_start SoundMain
SoundMain: @ 0x080E2374
.L080E2374:
	ldr r0, .L080E23E0
	ldr r0, [r0]
	ldr r2, .L080E23E4
	ldr r3, [r0]
	cmp r2, r3
	beq .L080E2382
	bx lr
.L080E2382:
	adds r3, #1
	str r3, [r0]
	push {r4, r5, r6, r7, lr}
	mov r1, r8
	mov r2, sb
	mov r3, sl
	mov r4, fp
	push {r0, r1, r2, r3, r4}
	sub sp, #0x18
	ldrb r1, [r0, #0xc]
	cmp r1, #0
	beq .L080E23A6
	ldr r2, .L080E23EC
	ldrb r2, [r2]
	cmp r2, #0xa0
	bhs .L080E23A4
	adds r2, #0xe4
.L080E23A4:
	adds r1, r1, r2
.L080E23A6:
	str r1, [sp, #0x14]
	ldr r3, [r0, #0x20]
	cmp r3, #0
	beq .L080E23B6
	ldr r0, [r0, #0x24]
	bl sub_080E2722
	ldr r0, [sp, #0x18]
.L080E23B6:
	ldr r3, [r0, #0x28]
	bl sub_080E2722
	ldr r0, [sp, #0x18]
	ldr r3, [r0, #0x10]
	mov r8, r3
	ldr r5, .L080E23F0
	adds r5, r5, r0
	ldrb r4, [r0, #4]
	subs r7, r4, #1
	bls .L080E23D6
	ldrb r1, [r0, #0xb]
	subs r1, r1, r7
	mov r2, r8
	muls r2, r1, r2
	adds r5, r5, r2
.L080E23D6:
	str r5, [sp, #8]
	ldr r6, .L080E23F4
	ldr r3, .L080E23E8
	bx r3
	.byte 0x00, 0x00
.L080E23E0: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E23E4: .4byte 0x68736D53
.L080E23E8: .4byte 0x03007001 @ IWRAM+0x7001
.L080E23EC: .4byte 0x04000006 @ REG_VCOUNT
.L080E23F0: .4byte 0x00000350
.L080E23F4: .4byte 0x00000630

	thumb_func_start SoundMainRAM
SoundMainRAM: @ 0x080E23F8
	ldrb r3, [r0, #5]
	cmp r3, #0
	beq .L080E2444
	add r1, pc, #4
	bx r1
	.byte 0x00, 0x00
	.arm
	cmp r4, #2
	addeq r7, r0, #0x350
	addne r7, r5, r8
	mov r4, r8
.L080E2414:
	ldrsb r0, [r5]
	ldrsb r1, [r7], #1
	add r0, r0, r1
	mul r1, r0, r3
	asr r0, r1, #8
	tst r0, #0x80
	addne r0, r0, #1
	strb r0, [r5], #1
	subs r4, r4, #1
	bgt .L080E2414
	add r0, pc, #0x1f
	bx r0
	.thumb
.L080E2444:
	movs r0, #0
	mov r1, r8
	lsrs r1, r1, #3
	blo .L080E244E
	stm r5!, {r0}
.L080E244E:
	lsrs r1, r1, #1
	blo .L080E2456
	stm r5!, {r0}
	stm r5!, {r0}
.L080E2456:
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	subs r1, #1
	bgt .L080E2456
	ldr r4, [sp, #0x18]
	ldr r0, [r4, #0x18]
	mov ip, r0
	ldrb r0, [r4, #6]
	adds r4, #0x50
.L080E246C:
	str r0, [sp, #4]
	ldr r3, [r4, #0x24]
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq .L080E248C
	ldr r1, .L080E2488
	ldrb r1, [r1]
	cmp r1, #0xa0
	bhs .L080E2480
	adds r1, #0xe4
.L080E2480:
	cmp r1, r0
	blo .L080E248C
	b .L080E270E
	.byte 0x00, 0x00
.L080E2488: .4byte 0x04000006 @ REG_VCOUNT
.L080E248C:
	ldrb r6, [r4]
	movs r0, #0xc7
	tst r0, r6
	bne .L080E2496
	b .L080E2704
.L080E2496:
	movs r0, #0x80
	tst r0, r6
	beq .L080E24C6
	movs r0, #0x40
	tst r0, r6
	bne .L080E24D6
	movs r6, #3
	strb r6, [r4]
	adds r0, r3, #0
	adds r0, #0x10
	str r0, [r4, #0x28]
	ldr r0, [r3, #0xc]
	str r0, [r4, #0x18]
	movs r5, #0
	strb r5, [r4, #9]
	str r5, [r4, #0x1c]
	ldrb r2, [r3, #3]
	movs r0, #0xc0
	tst r0, r2
	beq .L080E251E
	movs r0, #0x10
	orrs r6, r0
	strb r6, [r4]
	b .L080E251E
.L080E24C6:
	ldrb r5, [r4, #9]
	movs r0, #4
	tst r0, r6
	beq .L080E24DC
	ldrb r0, [r4, #0xd]
	subs r0, #1
	strb r0, [r4, #0xd]
	bhi .L080E252C
.L080E24D6:
	movs r0, #0
	strb r0, [r4]
	b .L080E2704
.L080E24DC:
	movs r0, #0x40
	tst r0, r6
	beq .L080E24FC
	ldrb r0, [r4, #7]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #0xc]
	cmp r5, r0
	bhi .L080E252C
.L080E24EE:
	ldrb r5, [r4, #0xc]
	cmp r5, #0
	beq .L080E24D6
	movs r0, #4
	orrs r6, r0
	strb r6, [r4]
	b .L080E252C
.L080E24FC:
	movs r2, #3
	ands r2, r6
	cmp r2, #2
	bne .L080E251A
	ldrb r0, [r4, #5]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #6]
	cmp r5, r0
	bhi .L080E252C
	adds r5, r0, #0
	beq .L080E24EE
	subs r6, #1
	strb r6, [r4]
	b .L080E252C
.L080E251A:
	cmp r2, #3
	bne .L080E252C
.L080E251E:
	ldrb r0, [r4, #4]
	adds r5, r5, r0
	cmp r5, #0xff
	blo .L080E252C
	movs r5, #0xff
	subs r6, #1
	strb r6, [r4]
.L080E252C:
	strb r5, [r4, #9]
	ldr r0, [sp, #0x18]
	ldrb r0, [r0, #7]
	adds r0, #1
	muls r0, r5, r0
	lsrs r5, r0, #4
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	adds r0, r0, r1
	muls r0, r5, r0
	lsrs r0, r0, #9
	strb r0, [r4, #0xa]
	movs r0, #0x10
	ands r0, r6
	str r0, [sp, #0x10]
	beq .L080E255C
	adds r0, r3, #0
	adds r0, #0x10
	ldr r1, [r3, #8]
	adds r0, r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r3, #0xc]
	subs r0, r0, r1
	str r0, [sp, #0x10]
.L080E255C:
	ldr r5, [sp, #8]
	ldr r2, [r4, #0x18]
	ldr r3, [r4, #0x28]
	add r0, pc, #4
	bx r0
	.byte 0x00, 0x00
	.arm
	str r8, [sp]
	ldrb sl, [r4, #0xa]
	lsl sl, sl, #0x10
	ldrb r0, [r4, #1]
	tst r0, #8
	beq .L080E2670
.L080E2580:
	cmp r2, #4
	ble .L080E25DC
	subs r2, r2, r8
	movgt lr, #0
	bgt .L080E25AC
	mov lr, r8
	add r2, r2, r8
	sub r8, r2, #4
	sub lr, lr, r8
	ands r2, r2, #3
	moveq r2, #4
.L080E25AC:
	ldr r6, [r5]
.L080E25B0:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	adds r5, r5, #0x40000000
	blo .L080E25B0
	str r6, [r5], #4
	subs r8, r8, #4
	bgt .L080E25AC
	adds r8, r8, lr
	beq .L080E26F0
.L080E25DC:
	ldr r6, [r5]
.L080E25E0:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	subs r2, r2, #1
	beq .L080E2640
.L080E25F8:
	adds r5, r5, #0x40000000
	blo .L080E25E0
	str r6, [r5], #4
	subs r8, r8, #4
	bgt .L080E2580
	b .L080E26F0
.L080E2610:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq .L080E2634
	ldr r3, [sp, #0x14]
	rsb sb, r2, #0
.L080E2624:
	adds r2, r0, r2
	bgt .L080E26C4
	sub sb, sb, r0
	b .L080E2624
.L080E2634:
	pop {r4, ip}
	mov r2, #0
	b .L080E2650
.L080E2640:
	ldr r2, [sp, #0x10]
	cmp r2, #0
	ldrne r3, [sp, #0xc]
	bne .L080E25F8
.L080E2650:
	strb r2, [r4]
	lsr r0, r5, #0x1e
	bic r5, r5, #0xc0000000
	rsb r0, r0, #3
	lsl r0, r0, #3
	ror r6, r6, r0
	str r6, [r5], #4
	b .L080E26F8
.L080E2670:
	push {r4, ip}
	ldr lr, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	mul r4, ip, r1
	ldrsb r0, [r3]
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
.L080E268C:
	ldr r6, [r5]
.L080E2690:
	mul sb, lr, r1
	add sb, r0, sb, asr #23
	mul ip, sl, sb
	bic ip, ip, #0xff0000
	add r6, ip, r6, ror #8
	add lr, lr, r4
	lsrs sb, lr, #0x17
	beq .L080E26D0
	bic lr, lr, #0x3f800000
	subs r2, r2, sb
	ble .L080E2610
	subs sb, sb, #1
	addeq r0, r0, r1
.L080E26C4:
	ldrsbne r0, [r3, sb]!
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
.L080E26D0:
	adds r5, r5, #0x40000000
	blo .L080E2690
	str r6, [r5], #4
	subs r8, r8, #4
	bgt .L080E268C
	sub r3, r3, #1
	pop {r4, ip}
	str lr, [r4, #0x1c]
.L080E26F0:
	str r2, [r4, #0x18]
	str r3, [r4, #0x28]
.L080E26F8:
	ldr r8, [sp]
	add r0, pc, #1
	bx r0
	.thumb
.L080E2704:
	ldr r0, [sp, #4]
	subs r0, #1
	ble .L080E270E
	adds r4, #0x40
	b .L080E246C
.L080E270E:
	ldr r0, [sp, #0x18]
	ldr r3, .L080E2724
	str r3, [r0]
	add sp, #0x1c
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r3}

	thumb_func_start sub_080E2722
sub_080E2722: @ 0x080E2722
.L080E2722:
	bx r3
.L080E2724: .4byte 0x68736D53

	thumb_func_start SoundMainBTM
SoundMainBTM: @ 0x080E2728
	mov ip, r4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	movs r4, #0
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	mov r4, ip
	bx lr
	.byte 0x00, 0x00
