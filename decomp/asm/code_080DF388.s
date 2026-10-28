	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080DF388
sub_080DF388: @ 0x080DF388
.L080DF388:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	mov r8, r0
	ldr r2, .L080DF3A8
	ldrb r0, [r2]
	cmp r0, #1
	beq .L080DF3AC
	cmp r0, #1
	ble .L080DF480
	cmp r0, #2
	beq .L080DF3F8
	b .L080DF480
.L080DF3A8: .4byte 0x030062F0 @ IWRAM+0x62F0
.L080DF3AC:
	ldr r0, .L080DF3C0
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq .L080DF3C4
	movs r0, #0
	b .L080DF482
	.byte 0x00, 0x00
.L080DF3C0: .4byte 0x03006360 @ IWRAM+0x6360
.L080DF3C4:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	beq .L080DF480
	movs r0, #2
	strb r0, [r2]
	ldr r1, .L080DF3F4
	movs r0, #0xc1
	lsls r0, r0, #8
	strh r0, [r1]
	adds r5, r1, #2
	movs r2, #0
.L080DF3DE:
	ldrb r0, [r4]
	strb r0, [r5]
	adds r4, #1
	adds r5, #1
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls .L080DF3DE
	b .L080DF480
	.byte 0x00, 0x00
.L080DF3F4: .4byte 0x03006380 @ IWRAM+0x6380
.L080DF3F8:
	movs r0, #0xc1
	lsls r0, r0, #8
	bl sub_080DF6FC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080DF480
	mov r3, sp
	mov r2, sp
	mov r1, sp
	mov r0, sp
	mov r5, r8
	strb r5, [r0, #3]
	strb r5, [r1, #2]
	strb r5, [r2, #1]
	strb r5, [r3]
	movs r3, #0
	ldr r0, .L080DF490
	mov ip, r0
	movs r7, #1
.L080DF422:
	lsls r0, r3, #4
	mov r1, ip
	adds r5, r0, r1
	mov r0, sp
	adds r1, r0, r3
	movs r0, #0
	strb r0, [r1]
	movs r2, #0
	adds r6, r3, #1
	adds r3, r1, #0
.L080DF436:
	adds r0, r4, r2
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq .L080DF444
	strb r7, [r3]
.L080DF444:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls .L080DF436
	lsls r0, r6, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls .L080DF422
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080DF480
	mov r0, sp
	ldrb r0, [r0, #1]
	cmp r0, #0
	bne .L080DF480
	mov r0, sp
	ldrb r0, [r0, #2]
	cmp r0, #0
	bne .L080DF480
	mov r0, sp
	ldrb r0, [r0, #3]
	adds r1, r0, #0
	cmp r1, #0
	bne .L080DF480
	movs r5, #1
	mov r8, r5
	ldr r0, .L080DF494
	strh r1, [r0]
.L080DF480:
	mov r0, r8
.L080DF482:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080DF490: .4byte 0x03006342 @ IWRAM+0x6342
.L080DF494: .4byte 0x03006380 @ IWRAM+0x6380
