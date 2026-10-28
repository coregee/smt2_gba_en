	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080EF218
sub_080EF218: @ 0x080EF218
.L080EF218:
	push {lr}
	movs r1, #1
	bl sub_080EF148
	pop {r0}
	bx r0

	thumb_func_start sub_080EF224
sub_080EF224: @ 0x080EF224
.L080EF224:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r7, #0
	movs r0, #0x10
	mov r8, r0
	cmp r5, #0
	blt .L080EF23E
	adds r0, r5, #0
	bl sub_08126834
.L080EF23E:
	bl sub_080ED954
	cmp r0, #0
	beq .L080EF24E
	cmp r4, #0x13
	ble .L080EF24E
	movs r0, #0x14
	mov r8, r0
.L080EF24E:
	mov r4, r8
	adds r6, r4, #0
	adds r6, #8
	b .L080EF258
.L080EF256:
	adds r4, #1
.L080EF258:
	cmp r4, r6
	bge .L080EF28A
	adds r0, r4, #0
	bl sub_080C0A00
	cmp r0, #0
	bne .L080EF256
	mov r0, r8
	adds r1, r4, #0
	bl sub_080F44D8
	adds r0, r4, #0
	movs r1, #0
	bl sub_080C08F8
	adds r0, r4, #0
	bl sub_080C0A7C
	adds r0, r4, #0
	bl sub_080C0AA8
	movs r7, #1
	subs r5, #1
	cmp r5, #0
	bne .L080EF256
.L080EF28A:
	cmp r7, #1
	bne .L080EF292
	bl sub_080E760C
.L080EF292:
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EF2A0
sub_080EF2A0: @ 0x080EF2A0
.L080EF2A0:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
	ldr r0, .L080EF350
	mov r8, r0
.L080EF2AC:
	mov r1, r8
	adds r0, r7, r1
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #0
	blt .L080EF2DC
	movs r5, #0
	ldr r4, .L080EF354
.L080EF2BC:
	bl sub_080C2244
	lsls r1, r5, #1
	ldrh r2, [r4]
	cmp r0, r2
	bhs .L080EF2D4
	ldr r0, .L080EF358
	adds r0, r1, r0
	ldrh r1, [r0]
	adds r0, r6, #0
	bl sub_080C08BC
.L080EF2D4:
	adds r4, #2
	adds r5, #1
	cmp r5, #3
	ble .L080EF2BC
.L080EF2DC:
	adds r7, #1
	cmp r7, #5
	ble .L080EF2AC
	ldr r4, .L080EF35C
	movs r0, #0
	adds r1, r4, #0
	bl sub_080C08BC
	movs r0, #1
	adds r1, r4, #0
	bl sub_080C08BC
	movs r7, #0
	ldr r0, .L080EF354
	mov r8, r0
.L080EF2FA:
	adds r6, r7, #0
	adds r6, #0x10
	movs r5, #0
	mov r4, r8
.L080EF302:
	bl sub_080C2244
	lsls r1, r5, #1
	ldrh r2, [r4]
	cmp r0, r2
	bhs .L080EF31A
	ldr r0, .L080EF358
	adds r0, r1, r0
	ldrh r1, [r0]
	adds r0, r6, #0
	bl sub_080C08BC
.L080EF31A:
	adds r4, #2
	adds r5, #1
	cmp r5, #3
	ble .L080EF302
	adds r7, #1
	cmp r7, #7
	ble .L080EF2FA
	movs r7, #0
	ldr r3, .L080EF360
	movs r4, #0x24
	rsbs r4, r4, #0
.L080EF330:
	ldr r1, [r3]
	lsls r0, r7, #1
	adds r1, #0x78
	adds r1, r1, r0
	ldrh r2, [r1]
	adds r0, r4, #0
	ands r0, r2
	strh r0, [r1]
	adds r7, #1
	cmp r7, #0xd
	ble .L080EF330
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080EF350: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080EF354: .4byte gUnknown_0876F7C6
.L080EF358: .4byte gUnknown_0876F7BE
.L080EF35C: .4byte 0x0000FFBF
.L080EF360: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EF364
sub_080EF364: @ 0x080EF364
.L080EF364:
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r6, .L080EF398
	movs r5, #0x40
.L080EF36C:
	adds r0, r4, r6
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	blt .L080EF38A
	movs r1, #0xe6
	lsls r1, r1, #2
	cmp r2, #3
	bgt .L080EF380
	orrs r1, r5
.L080EF380:
	ldr r0, .L080EF39C
	eors r1, r0
	adds r0, r2, #0
	bl sub_080C08BC
.L080EF38A:
	adds r4, #1
	cmp r4, #5
	ble .L080EF36C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EF398: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080EF39C: .4byte 0x0000FFFF

	thumb_func_start sub_080EF3A0
sub_080EF3A0: @ 0x080EF3A0
	push {lr}
	adds r2, r0, #0
	cmp r2, #0
	bne .L080EF3AC
	movs r0, #0
	b .L080EF3C4
.L080EF3AC:
	cmp r2, #7
	ble .L080EF3C0
	adds r0, r1, #0
	cmp r1, #0
	bge .L080EF3B8
	adds r0, r1, #7
.L080EF3B8:
	asrs r0, r0, #3
	subs r1, r2, #7
	muls r0, r1, r0
	b .L080EF3C4
.L080EF3C0:
	adds r0, r1, #0
	muls r0, r2, r0
.L080EF3C4:
	pop {r1}
	bx r1

	thumb_func_start sub_080EF3C8
sub_080EF3C8: @ 0x080EF3C8
.L080EF3C8:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF648
	adds r5, r0, #0
	movs r0, #1
	bl Flag_Test
	cmp r0, #0
	bne .L080EF42A
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	bne .L080EF42A
	movs r0, #0xb7
	bl Flag_Test
	cmp r0, #0
	bne .L080EF42A
	ldrb r0, [r5, #0x19]
	movs r4, #0xf
	ands r4, r0
	cmp r4, #0
	beq .L080EF42A
	adds r0, r4, #0
	muls r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x11
	cmp r4, #0
	bne .L080EF40A
	movs r4, #1
.L080EF40A:
	bl sub_080C2244
	movs r1, #0xff
	ands r0, r1
	cmp r0, r4
	bhs .L080EF42A
	ldrb r4, [r5, #0x1f]
	movs r0, #1
	ands r4, r0
	lsls r0, r4, #8
	ldrb r4, [r5, #0x1a]
	orrs r4, r0
	lsls r0, r4, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	b .L080EF42E
.L080EF42A:
	movs r0, #1
	rsbs r0, r0, #0
.L080EF42E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080EF434
sub_080EF434: @ 0x080EF434
.L080EF434:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF648
	adds r4, r0, #0
	movs r0, #1
	bl Flag_Test
	cmp r0, #0
	bne .L080EF48C
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	bne .L080EF48C
	movs r0, #0xb7
	bl Flag_Test
	cmp r0, #0
	bne .L080EF48C
	ldrb r1, [r4, #0x1f]
	movs r0, #0xf0
	ands r0, r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080EF48C
	lsrs r0, r0, #0x1c
	adds r4, r0, #0
	muls r4, r0, r4
	lsrs r4, r4, #1
	bl rand
	movs r1, #0xff
	ands r0, r1
	movs r1, #0xc0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r4
	bhs .L080EF48C
	movs r0, #1
	b .L080EF48E
.L080EF48C:
	movs r0, #0
.L080EF48E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080EF494
sub_080EF494: @ 0x080EF494
.L080EF494:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r8, r6
	adds r0, r4, #0
	bl sub_080ED560
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r7, r5, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_080BF648
	ldrb r1, [r0, #0x19]
	lsrs r2, r1, #4
	cmp r2, #0
	bne .L080EF4C4
	movs r0, #0
	b .L080EF52E
.L080EF4C4:
	lsls r0, r5, #8
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r2, #0
	bl sub_080F030C
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r6, r5
	bhs .L080EF500
	subs r0, r5, r6
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x12
	cmp r1, #0
	beq .L080EF52C
	movs r3, #0x80
	lsls r3, r3, #8
.L080EF4E8:
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	bne .L080EF524
	lsls r0, r2, #0x11
	lsrs r2, r0, #0x10
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne .L080EF4E8
	b .L080EF52C
.L080EF500:
	mov r1, r8
	subs r0, r1, r7
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x12
	cmp r1, #0
	beq .L080EF52C
	cmp r1, #0xff
	bls .L080EF512
	movs r1, #0xff
.L080EF512:
	adds r0, r2, #0
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne .L080EF52C
	movs r0, #1
	b .L080EF52E
.L080EF524:
	ldr r0, .L080EF528
	b .L080EF52E
.L080EF528: .4byte 0x0000FFFF
.L080EF52C:
	adds r0, r2, #0
.L080EF52E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080EF538
sub_080EF538: @ 0x080EF538
.L080EF538:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF648
	adds r4, r0, #0
	movs r0, #1
	bl Flag_Test
	cmp r0, #0
	bne .L080EF562
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	bne .L080EF562
	movs r0, #0xb7
	bl Flag_Test
	cmp r0, #0
	beq .L080EF566
.L080EF562:
	movs r0, #0
	b .L080EF578
.L080EF566:
	ldrb r1, [r4, #0x1c]
	ldrb r2, [r4, #1]
	lsrs r0, r1, #4
	lsls r2, r2, #8
	orrs r0, r2
	bl sub_080F030C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
.L080EF578:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EF580
sub_080EF580: @ 0x080EF580
.L080EF580:
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF648
	adds r4, r0, #0
	movs r0, #1
	bl Flag_Test
	cmp r0, #0
	bne .L080EF5B0
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	bne .L080EF5B0
	movs r0, #0xb7
	bl Flag_Test
	cmp r0, #0
	bne .L080EF5B0
	cmp r5, #0xb1
	bgt .L080EF5B4
.L080EF5B0:
	movs r0, #0
	b .L080EF5CA
.L080EF5B4:
	ldrb r2, [r4, #0x1c]
	ldrb r0, [r4, #1]
	lsls r1, r2, #4
	movs r3, #0xf
	lsls r0, r0, #8
	ands r2, r3
	orrs r0, r2
	bl sub_080F030C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080EF5CA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080EF5D0
sub_080EF5D0: @ 0x080EF5D0
.L080EF5D0:
	push {lr}
	adds r1, r0, #0
	cmp r1, #0xf
	beq .L080EF5E0
	movs r0, #2
	bl sub_080ED3FC
	b .L080EF5E4
.L080EF5E0:
	movs r0, #0x80
	lsls r0, r0, #8
.L080EF5E4:
	pop {r1}
	bx r1

	thumb_func_start sub_080EF5E8
sub_080EF5E8: @ 0x080EF5E8
.L080EF5E8:
	push {lr}
	bl sub_080ED4A8
	adds r1, r0, #0
	movs r0, #0xf
	ands r0, r1
	bl sub_080EF5D0
	pop {r1}
	bx r1

	thumb_func_start sub_080EF5FC
sub_080EF5FC: @ 0x080EF5FC
.L080EF5FC:
	push {r4, lr}
	sub sp, #4
	adds r2, r0, #0
	adds r4, r1, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	str r0, [sp]
	movs r3, #0x17
	ldrsb r3, [r2, r3]
	subs r0, r3, #4
	cmp r0, #8
	bhi .L080EF6AA
	lsls r0, r0, #2
	ldr r1, .L080EF620
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080EF620: .4byte gUnknown_080EF624
	.global gUnknown_080EF624
gUnknown_080EF624:
.L080EF624: @ jump table
	.4byte .L080EF648
	.4byte .L080EF648
	.4byte .L080EF6A4
	.4byte .L080EF66E
	.4byte .L080EF67A
	.4byte .L080EF6A4
	.4byte .L080EF69A
	.4byte .L080EF66E
	.4byte .L080EF6A4
.L080EF648:
	cmp r3, #4
	bne .L080EF650
	movs r0, #0
	b .L080EF652
.L080EF650:
	movs r0, #1
.L080EF652:
	str r0, [sp]
	adds r0, r4, #0
	ldr r1, [sp]
	bl sub_080C00DC
	str r0, [sp]
	movs r1, #4
	mov r2, sp
	bl sub_080BF468
	ldr r0, [sp]
.L080EF668:
	bl sub_080EF5D0
	b .L080EF6AC
.L080EF66E:
	ldr r0, [sp]
	bl sub_080ED694
	cmp r0, #0x7f
	bhi .L080EF6A4
	b .L080EF668
.L080EF67A:
	ldr r0, [sp]
	cmp r0, #0x57
	ble .L080EF696
	movs r1, #0xc
	mov r2, sp
	bl sub_080BF468
	ldr r0, [sp]
	cmp r0, #0
	blt .L080EF6A4
	cmp r0, #0x50
	beq .L080EF66E
	cmp r0, #0x3f
	ble .L080EF66E
.L080EF696:
	movs r0, #1
	b .L080EF6AC
.L080EF69A:
	movs r1, #0x12
	ldrsh r0, [r2, r1]
	bl sub_080EF5E8
	b .L080EF6AC
.L080EF6A4:
	movs r0, #1
	rsbs r0, r0, #0
	b .L080EF6AC
.L080EF6AA:
	movs r0, #0
.L080EF6AC:
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080EF6B4
sub_080EF6B4: @ 0x080EF6B4
.L080EF6B4:
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #4
.L080EF6BA:
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080EF6DC
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r5
	bne .L080EF6DC
	movs r0, #0
	movs r1, #0x19
	bl sub_080C06EC
	b .L080EF6E2
.L080EF6DC:
	adds r4, #1
	cmp r4, #0xf
	ble .L080EF6BA
.L080EF6E2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080EF6E8
sub_080EF6E8: @ 0x080EF6E8
.L080EF6E8:
	push {lr}
	bl sub_080F42E0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xff
	beq .L080EF702
	adds r0, r1, #0
	subs r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x5e
	bls .L080EF708
.L080EF702:
	movs r0, #1
	rsbs r0, r0, #0
	b .L080EF70A
.L080EF708:
	adds r0, r1, #0
.L080EF70A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EF710
sub_080EF710: @ 0x080EF710
.L080EF710:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	cmp r5, #3
	bgt .L080EF720
	movs r0, #1
	rsbs r0, r0, #0
	b .L080EF738
.L080EF720:
	movs r4, #0
.L080EF722:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080EF6E8
	cmp r0, #0
	blt .L080EF730
	adds r6, #1
.L080EF730:
	adds r4, #1
	cmp r4, #6
	ble .L080EF722
	adds r0, r6, #0
.L080EF738:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EF740
sub_080EF740: @ 0x080EF740
.L080EF740:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r6]
	subs r0, r1, #4
	cmp r0, #8
	bhi .L080EF820
	lsls r0, r0, #2
	ldr r1, .L080EF75C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080EF75C: .4byte gUnknown_080EF760
	.global gUnknown_080EF760
gUnknown_080EF760:
.L080EF760: @ jump table
	.4byte .L080EF784
	.4byte .L080EF796
	.4byte .L080EF7F8
	.4byte .L080EF7D0
	.4byte .L080EF820
	.4byte .L080EF820
	.4byte .L080EF820
	.4byte .L080EF7BE
	.4byte .L080EF820
.L080EF784:
	adds r0, r5, #0
	movs r1, #0
	bl sub_080C00DC
	cmp r0, #0xff
	bne .L080EF820
	movs r0, #0xb1
	lsls r0, r0, #1
	b .L080EF804
.L080EF796:
	adds r0, r5, #0
	movs r1, #1
	bl sub_080C00DC
	adds r4, r0, #0
	cmp r4, #0xff
	beq .L080EF7B8
	adds r0, r5, #0
	movs r1, #6
	bl sub_080C00DC
	cmp r0, #0xff
	bne .L080EF820
	adds r0, r4, #0
	subs r0, #0x6d
	cmp r0, #1
	bls .L080EF820
.L080EF7B8:
	movs r0, #0xb1
	lsls r0, r0, #1
	b .L080EF804
.L080EF7BE:
	adds r0, r5, #0
	bl sub_080EF710
	cmp r0, #0
	bne .L080EF820
	ldr r0, .L080EF7CC
	b .L080EF804
.L080EF7CC: .4byte 0x00000165
.L080EF7D0:
	adds r0, r5, #0
	movs r1, #0x20
	bl sub_080F4300
	cmp r0, #0
	bne .L080EF7E0
	movs r0, #0x8f
	b .L080EF804
.L080EF7E0:
	adds r0, r5, #0
	bl sub_080C0818
	ldr r1, .L080EF7F4
	ands r1, r0
	cmp r1, #0
	beq .L080EF820
	movs r0, #0x90
	b .L080EF804
	.byte 0x00, 0x00
.L080EF7F4: .4byte 0x0000B063
.L080EF7F8:
	movs r0, #3
	bl Flag_Test
	cmp r0, #0
	bne .L080EF810
	ldr r0, .L080EF80C
.L080EF804:
	str r0, [r6]
	movs r0, #0
	b .L080EF822
	.byte 0x00, 0x00
.L080EF80C: .4byte 0x00000393
.L080EF810:
	bl sub_080F3190
	adds r4, r0, #0
	cmp r4, #0
	beq .L080EF820
	str r4, [r6]
	movs r0, #0
	b .L080EF822
.L080EF820:
	movs r0, #1
.L080EF822:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_080EF828
sub_080EF828: @ 0x080EF828
.L080EF828:
	push {lr}
	bl sub_080EF99C
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080EF838
	movs r0, #0x14
	b .L080EF83A
.L080EF838:
	movs r0, #0x10
.L080EF83A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EF840
sub_080EF840: @ 0x080EF840
	push {r4, r5, r6, r7, lr}
	bl sub_080EF828
	adds r6, r0, #0
	bl sub_080ED954
	movs r7, #8
	cmp r0, #0
	beq .L080EF854
	movs r7, #4
.L080EF854:
	movs r5, #0
	cmp r5, r7
	bge .L080EF870
.L080EF85A:
	adds r4, r6, r5
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080EF86A
	adds r0, r4, #0
	b .L080EF872
.L080EF86A:
	adds r5, #1
	cmp r5, r7
	blt .L080EF85A
.L080EF870:
	adds r0, r6, #0
.L080EF872:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080EF878
sub_080EF878: @ 0x080EF878
.L080EF878:
	push {r4, r5, r6, r7, lr}
	bl sub_080EF828
	adds r6, r0, #0
	bl sub_080ED954
	movs r7, #8
	cmp r0, #0
	beq .L080EF88C
	movs r7, #4
.L080EF88C:
	movs r5, #0
	cmp r5, r7
	bge .L080EF8B2
.L080EF892:
	adds r4, r6, r5
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080EF8AC
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080EF8AC
	adds r0, r4, #0
	b .L080EF8B4
.L080EF8AC:
	adds r5, #1
	cmp r5, r7
	blt .L080EF892
.L080EF8B2:
	adds r0, r6, #0
.L080EF8B4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EF8BC
sub_080EF8BC: @ 0x080EF8BC
	ldr r1, .L080EF8CC
	ldr r1, [r1]
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080EF8CC: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EF8D0
sub_080EF8D0: @ 0x080EF8D0
.L080EF8D0:
	ldr r0, .L080EF8E0
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
.L080EF8E0: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EF8E4
sub_080EF8E4: @ 0x080EF8E4
	ldr r0, .L080EF8F4
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080EF8F4: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EF8F8
sub_080EF8F8: @ 0x080EF8F8
.L080EF8F8:
	ldr r1, .L080EF908
	ldr r1, [r1]
	movs r2, #0x92
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080EF908: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EF90C
sub_080EF90C: @ 0x080EF90C
.L080EF90C:
	push {r4, lr}
	ldr r0, .L080EF92C
	ldr r4, [r0]
	bl sub_080EF99C
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	movs r1, #0x94
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
.L080EF92C: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EF930
sub_080EF930: @ 0x080EF930
.L080EF930:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080EF99C
	ldr r1, .L080EF950
	ldr r1, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r1, r0
	strh r4, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L080EF950: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EF954
sub_080EF954: @ 0x080EF954
.L080EF954:
	push {r4, lr}
	ldr r0, .L080EF974
	ldr r4, [r0]
	bl sub_080EF99C
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	movs r1, #0x96
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
.L080EF974: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EF978
sub_080EF978: @ 0x080EF978
.L080EF978:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080EF99C
	ldr r1, .L080EF998
	ldr r1, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r1, r0
	strh r4, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L080EF998: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EF99C
sub_080EF99C: @ 0x080EF99C
.L080EF99C:
	push {lr}
	bl sub_080ED954
	cmp r0, #0
	beq .L080EFA00
	ldr r3, .L080EF9D0
	ldr r0, .L080EF9D4
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #1
	adds r2, r0, r1
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne .L080EF9DC
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r1, .L080EF9D8
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq .L080EF9DC
	movs r0, #1
	b .L080EF9FE
	.byte 0x00, 0x00
.L080EF9D0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EF9D4: .4byte 0x03006434 @ IWRAM+0x6434
.L080EF9D8: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L080EF9DC:
	ldr r0, .L080EFA14
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #1
	adds r2, r0, r1
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #1
	bne .L080EFA00
	ldr r1, .L080EFA18
	adds r0, r3, r1
	ldr r1, .L080EFA1C
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq .L080EFA00
	movs r0, #0
.L080EF9FE:
	strh r0, [r2]
.L080EFA00:
	ldr r0, .L080EFA14
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080EFA14: .4byte 0x03006434 @ IWRAM+0x6434
.L080EFA18: .4byte 0x00000994
.L080EFA1C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C

	thumb_func_start sub_080EFA20
sub_080EFA20: @ 0x080EFA20
.L080EFA20:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080EF90C
	adds r0, r0, r4
	cmp r0, #0
	bge .L080EFA32
	movs r0, #0
	b .L080EFA38
.L080EFA32:
	cmp r0, #0x1f
	ble .L080EFA38
	movs r0, #0x1f
.L080EFA38:
	bl sub_080EF930
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080EFA44
sub_080EFA44: @ 0x080EFA44
.L080EFA44:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080EF954
	adds r0, r0, r4
	cmp r0, #0
	bge .L080EFA56
	movs r0, #0
	b .L080EFA5C
.L080EFA56:
	cmp r0, #0x1f
	ble .L080EFA5C
	movs r0, #0x1f
.L080EFA5C:
	bl sub_080EF978
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080EFA68
sub_080EFA68: @ 0x080EFA68
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080EF8D0
	cmp r0, #0
	bne .L080EFA7C
	adds r0, r4, #0
	bl sub_080EFA20
	b .L080EFA82
.L080EFA7C:
	adds r0, r4, #0
	bl sub_080EFA44
.L080EFA82:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080EFA88
sub_080EFA88: @ 0x080EFA88
.L080EFA88:
	ldr r1, .L080EFA98
	ldr r1, [r1]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080EFA98: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFA9C
sub_080EFA9C: @ 0x080EFA9C
.L080EFA9C:
	ldr r0, .L080EFAAC
	ldr r0, [r0]
	movs r1, #0x93
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
.L080EFAAC: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFAB0
sub_080EFAB0: @ 0x080EFAB0
.L080EFAB0:
	push {r4, lr}
	ldr r1, .L080EFACC
	ldr r4, [r1]
	bl sub_080ED8C0
	lsls r0, r0, #1
	adds r4, #0x78
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080EFACC: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFAD0
sub_080EFAD0: @ 0x080EFAD0
.L080EFAD0:
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r0, #0xf
	bgt .L080EFB24
	ldr r0, .L080EFB20
	ldr r0, [r0]
	mov ip, r0
	mov r2, ip
	adds r2, #0x78
	ldrh r3, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	orrs r0, r3
	strh r0, [r2]
	mov r3, ip
	adds r3, #0x7a
	ldrh r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r3]
	adds r3, #2
	ldrh r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r3]
	adds r3, #2
	ldrh r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r3]
	adds r3, #2
	ldrh r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r3]
	mov r2, ip
	adds r2, #0x82
	b .L080EFB7C
.L080EFB20: .4byte 0x03006434 @ IWRAM+0x6434
.L080EFB24:
	ldr r0, .L080EFB88
	ldr r0, [r0]
	mov ip, r0
	mov r2, ip
	adds r2, #0x84
	ldrh r3, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	orrs r0, r3
	strh r0, [r2]
	mov r3, ip
	adds r3, #0x86
	ldrh r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r3]
	adds r3, #2
	ldrh r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r3]
	adds r3, #2
	ldrh r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r3]
	adds r3, #2
	ldrh r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r3]
	adds r3, #2
	ldrh r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r3]
	adds r3, #2
	ldrh r2, [r3]
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r3]
	mov r2, ip
	adds r2, #0x92
.L080EFB7C:
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EFB88: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFB8C
sub_080EFB8C: @ 0x080EFB8C
.L080EFB8C:
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r0, #0xf
	bgt .L080EFBA8
	ldr r0, .L080EFBA4
	ldr r3, [r0]
	adds r2, r3, #0
	adds r2, #0x78
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	b .L080EFBC4
.L080EFBA4: .4byte 0x03006434 @ IWRAM+0x6434
.L080EFBA8:
	ldr r0, .L080EFBF8
	ldr r3, [r0]
	adds r2, r3, #0
	adds r2, #0x84
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r0, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r2, #2
.L080EFBC4:
	ldrh r0, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r2]
	ands r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EFBF8: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFBFC
sub_080EFBFC: @ 0x080EFBFC
.L080EFBFC:
	push {r4, lr}
	ldr r1, .L080EFC18
	ldr r4, [r1]
	bl sub_080ED8C0
	lsls r0, r0, #1
	adds r4, #0x94
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080EFC18: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFC1C
sub_080EFC1C: @ 0x080EFC1C
.L080EFC1C:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r4, r2, #0
	bl sub_080ED8C0
	adds r6, r0, #0
	ldr r0, .L080EFC68
	ldr r2, [r0]
	lsls r1, r6, #1
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r2, #0x78
	adds r2, r2, r1
	ldrh r0, [r2]
	adds r0, r0, r4
	strh r0, [r2]
	ldr r3, .L080EFC6C
	lsls r0, r5, #1
	adds r1, r0, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r4, #0
	ldrsh r3, [r2, r4]
	movs r4, #0
	cmp r3, r1
	bge .L080EFC70
	adds r3, r1, #0
	movs r4, #1
	b .L080EFC7C
.L080EFC68: .4byte 0x03006434 @ IWRAM+0x6434
.L080EFC6C: .4byte gUnknown_0876F7CE
.L080EFC70:
	cmp r3, r0
	ble .L080EFC78
	adds r3, r0, #0
	movs r4, #1
.L080EFC78:
	cmp r4, #0
	beq .L080EFC90
.L080EFC7C:
	ldr r0, .L080EFC98
	ldr r1, [r0]
	lsls r2, r6, #1
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, #0x78
	adds r1, r1, r2
	strh r3, [r1]
.L080EFC90:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080EFC98: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFC9C
sub_080EFC9C: @ 0x080EFC9C
.L080EFC9C:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r5, r2, #0
	movs r7, #0
	cmp r1, #0xf
	bgt .L080EFCE4
	movs r4, #0
	ldr r0, .L080EFCE0
	mov sb, r0
	movs r0, #1
	rsbs r0, r0, #0
	mov r8, r0
.L080EFCBA:
	mov r0, sb
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r8
	beq .L080EFCD6
	adds r1, r0, #0
	adds r0, r6, #0
	adds r2, r5, #0
	bl sub_080EFC1C
	cmp r0, #0
	bne .L080EFCD6
	movs r7, #1
.L080EFCD6:
	adds r4, #1
	cmp r4, #5
	ble .L080EFCBA
	b .L080EFCFE
	.byte 0x00, 0x00
.L080EFCE0: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080EFCE4:
	movs r4, #0
.L080EFCE6:
	adds r1, r4, #0
	adds r1, #0x10
	adds r0, r6, #0
	adds r2, r5, #0
	bl sub_080EFC1C
	cmp r0, #0
	bne .L080EFCF8
	movs r7, #1
.L080EFCF8:
	adds r4, #1
	cmp r4, #7
	ble .L080EFCE6
.L080EFCFE:
	cmp r7, #1
	beq .L080EFD06
	movs r0, #1
	b .L080EFD08
.L080EFD06:
	movs r0, #0
.L080EFD08:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080EFD14
sub_080EFD14: @ 0x080EFD14
.L080EFD14:
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #1
	adds r1, r3, #0
	bl sub_080EFC9C
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFD28
sub_080EFD28: @ 0x080EFD28
.L080EFD28:
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #1
	adds r1, r3, #0
	bl sub_080EFC1C
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFD3C
sub_080EFD3C: @ 0x080EFD3C
.L080EFD3C:
	push {r4, lr}
	ldr r1, .L080EFD58
	ldr r4, [r1]
	bl sub_080ED8C0
	lsls r0, r0, #1
	adds r4, #0xb0
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080EFD58: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFD5C
sub_080EFD5C: @ 0x080EFD5C
.L080EFD5C:
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #2
	adds r1, r3, #0
	bl sub_080EFC9C
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFD70
sub_080EFD70: @ 0x080EFD70
.L080EFD70:
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #2
	adds r1, r3, #0
	bl sub_080EFC1C
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFD84
sub_080EFD84: @ 0x080EFD84
.L080EFD84:
	push {r4, lr}
	ldr r1, .L080EFDA0
	ldr r4, [r1]
	bl sub_080ED8C0
	lsls r0, r0, #1
	adds r4, #0xcc
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080EFDA0: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFDA4
sub_080EFDA4: @ 0x080EFDA4
.L080EFDA4:
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #3
	adds r1, r3, #0
	bl sub_080EFC9C
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFDB8
sub_080EFDB8: @ 0x080EFDB8
.L080EFDB8:
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #3
	adds r1, r3, #0
	bl sub_080EFC1C
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFDCC
sub_080EFDCC: @ 0x080EFDCC
.L080EFDCC:
	push {r4, lr}
	ldr r1, .L080EFDE8
	ldr r4, [r1]
	bl sub_080ED8C0
	lsls r0, r0, #1
	adds r4, #0xe8
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080EFDE8: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFDEC
sub_080EFDEC: @ 0x080EFDEC
.L080EFDEC:
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #4
	adds r1, r3, #0
	bl sub_080EFC9C
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFE00
sub_080EFE00: @ 0x080EFE00
.L080EFE00:
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #4
	adds r1, r3, #0
	bl sub_080EFC1C
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFE14
sub_080EFE14: @ 0x080EFE14
	push {r4, lr}
	ldr r1, .L080EFE34
	ldr r4, [r1]
	bl sub_080ED8C0
	lsls r0, r0, #1
	movs r1, #0x82
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080EFE34: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFE38
sub_080EFE38: @ 0x080EFE38
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #5
	adds r1, r3, #0
	bl sub_080EFC9C
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFE4C
sub_080EFE4C: @ 0x080EFE4C
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #5
	adds r1, r3, #0
	bl sub_080EFC1C
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFE60
sub_080EFE60: @ 0x080EFE60
.L080EFE60:
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl sub_080C35E4
	subs r0, #4
	cmp r0, #8
	bhi .L080EFED0
	lsls r0, r0, #2
	ldr r1, .L080EFE7C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080EFE7C: .4byte gUnknown_080EFE80
	.global gUnknown_080EFE80
gUnknown_080EFE80:
.L080EFE80: @ jump table
	.4byte .L080EFED0
	.4byte .L080EFEA4
	.4byte .L080EFEC8
	.4byte .L080EFEA8
	.4byte .L080EFEB4
	.4byte .L080EFEC8
	.4byte .L080EFED0
	.4byte .L080EFEA8
	.4byte .L080EFEC8
.L080EFEA4:
	movs r0, #1
	b .L080EFED2
.L080EFEA8:
	adds r0, r4, #0
	bl sub_080F3F14
.L080EFEAE:
	bl sub_080ED6A4
	b .L080EFED2
.L080EFEB4:
	adds r0, r4, #0
	bl sub_080F3F14
	movs r1, #0xc
	mov r2, sp
	bl sub_080BF468
	ldr r0, [sp]
	cmp r0, #0x7f
	ble .L080EFEAE
.L080EFEC8:
	ldr r0, .L080EFECC
	b .L080EFED2
.L080EFECC: .4byte 0x0000FFFF
.L080EFED0:
	movs r0, #0
.L080EFED2:
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFEDC
sub_080EFEDC: @ 0x080EFEDC
.L080EFEDC:
	push {lr}
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	ldr r1, .L080EFF94
	cmp r0, r1
	beq .L080EFF90
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	ldr r1, .L080EFF98
	cmp r0, r1
	beq .L080EFF90
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #0x11
	cmp r0, r1
	beq .L080EFF90
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	ldr r1, .L080EFF9C
	cmp r0, r1
	beq .L080EFF90
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	movs r1, #0x97
	lsls r1, r1, #0x11
	cmp r0, r1
	beq .L080EFF90
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	ldr r1, .L080EFFA0
	cmp r0, r1
	beq .L080EFF90
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	ldr r1, .L080EFFA4
	cmp r0, r1
	beq .L080EFF90
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	movs r1, #0x94
	lsls r1, r1, #0x11
	cmp r0, r1
	beq .L080EFF90
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	movs r1, #0x96
	lsls r1, r1, #0x11
	cmp r0, r1
	beq .L080EFF90
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	ldr r1, .L080EFFA8
	cmp r0, r1
	beq .L080EFF90
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	movs r1, #0x95
	lsls r1, r1, #0x11
	cmp r0, r1
	beq .L080EFF90
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	ldr r1, .L080EFFAC
	cmp r0, r1
	bne .L080EFFB0
.L080EFF90:
	movs r0, #0x1b
	b .L080EFFBE
.L080EFF94: .4byte 0x012D0000
.L080EFF98: .4byte 0x010F0000
.L080EFF9C: .4byte 0x01110000
.L080EFFA0: .4byte 0x012F0000
.L080EFFA4: .4byte 0x01270000
.L080EFFA8: .4byte 0x01290000
.L080EFFAC: .4byte 0x012B0000
.L080EFFB0:
	bl sub_080EDAD0
	cmp r0, #0
	bne .L080EFFBC
	movs r0, #0xa
	b .L080EFFBE
.L080EFFBC:
	movs r0, #0x13
.L080EFFBE:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EFFC4
sub_080EFFC4: @ 0x080EFFC4
.L080EFFC4:
	ldr r1, .L080EFFD4
	ldr r1, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0xe
	adds r1, r1, r0
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	bx lr
.L080EFFD4: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EFFD8
sub_080EFFD8: @ 0x080EFFD8
.L080EFFD8:
	push {lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	beq .L080EFFEE
	cmp r0, #8
	beq .L080EFFEE
	cmp r0, #0xb
	bne .L080EFFF2
	cmp r1, #0x67
	bgt .L080EFFF2
.L080EFFEE:
	movs r0, #0
	b .L080EFFF4
.L080EFFF2:
	movs r0, #1
.L080EFFF4:
	pop {r1}
	bx r1

	thumb_func_start sub_080EFFF8
sub_080EFFF8: @ 0x080EFFF8
.L080EFFF8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	ldr r7, .L080F0080
	ldr r0, .L080F0084
	ldr r0, [r0]
	lsrs r2, r1, #0x10
	mov r8, r2
	asrs r1, r1, #0xe
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r6, .L080F0088
	asrs r0, r6, #0x10
	cmp r1, r0
	beq .L080F00B0
	adds r0, r5, #0
	bl sub_080C35E4
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	bl sub_080F3F14
	adds r1, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_080EFFD8
	cmp r0, #1
	bne .L080F00B0
	cmp r5, #0xf
	ble .L080F0090
	ldr r0, .L080F008C
	adds r4, r7, r0
	ldrh r1, [r4]
	lsrs r0, r6, #0x10
	cmp r1, r0
	beq .L080F00B0
	adds r0, r1, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F00B0
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	ldrh r1, [r0, #0xe]
	movs r0, #0xc0
	lsls r0, r0, #8
	cmp r1, r0
	bne .L080F00B0
	movs r1, #0
	ldrsh r0, [r4, r1]
	b .L080F00C6
.L080F0080: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0084: .4byte 0x03006434 @ IWRAM+0x6434
.L080F0088: .4byte 0xFFFF0000
.L080F008C: .4byte 0x000011AC
.L080F0090:
	ldr r2, .L080F00AC
	adds r4, r7, r2
	ldrh r1, [r4]
	lsrs r0, r6, #0x10
	cmp r1, r0
	beq .L080F00B0
	adds r0, r1, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F00B0
	movs r1, #0
	ldrsh r0, [r4, r1]
	b .L080F00C6
.L080F00AC: .4byte 0x000011AE
.L080F00B0:
	ldr r0, .L080F00D0
	ldr r1, [r0]
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r0, r0, #0xe
	adds r1, r1, r0
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
.L080F00C6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080F00D0: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F00D4
sub_080F00D4: @ 0x080F00D4
	ldr r0, .L080F00E4
	ldr r0, [r0]
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080F00E4: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F00E8
sub_080F00E8: @ 0x080F00E8
	ldr r1, .L080F00F8
	ldr r1, [r1]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080F00F8: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F00FC
sub_080F00FC: @ 0x080F00FC
.L080F00FC:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080F010C
	ldr r2, [r1]
	ldrh r1, [r2]
	bics r1, r0
	strh r1, [r2]
	bx lr
.L080F010C: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F0110
sub_080F0110: @ 0x080F0110
	ldr r1, .L080F0120
	ldr r2, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r2, #0x4c]
	adds r1, r1, r0
	str r1, [r2, #0x4c]
	bx lr
.L080F0120: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F0124
sub_080F0124: @ 0x080F0124
.L080F0124:
	ldr r0, .L080F012C
	ldr r0, [r0]
	ldr r0, [r0, #0x4c]
	bx lr
.L080F012C: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F0130
sub_080F0130: @ 0x080F0130
	ldr r1, .L080F0140
	ldr r2, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r2, #0x50]
	adds r1, r1, r0
	str r1, [r2, #0x50]
	bx lr
.L080F0140: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F0144
sub_080F0144: @ 0x080F0144
.L080F0144:
	ldr r0, .L080F014C
	ldr r0, [r0]
	ldr r0, [r0, #0x50]
	bx lr
.L080F014C: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F0150
sub_080F0150: @ 0x080F0150
.L080F0150:
	ldr r1, .L080F0164
	ldr r1, [r1]
	adds r1, #0x54
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080F0164: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F0168
sub_080F0168: @ 0x080F0168
.L080F0168:
	ldr r0, .L080F0174
	ldr r0, [r0]
	adds r0, #0x54
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
.L080F0174: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F0178
sub_080F0178: @ 0x080F0178
	ldr r2, .L080F0190
	ldr r2, [r2]
	lsls r0, r0, #2
	adds r2, #0x68
	adds r2, r2, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080F0190: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F0194
sub_080F0194: @ 0x080F0194
.L080F0194:
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	bne .L080F01D0
	movs r0, #0xb7
	bl Flag_Test
	cmp r0, #0
	bne .L080F01D0
	adds r0, r4, #0
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #4
	ands r1, r0
	cmp r1, #0
	bne .L080F01D0
	ldr r0, .L080F01CC
	ldr r0, [r0]
	lsls r1, r4, #2
	adds r0, #0x68
	adds r0, r0, r1
	ldr r0, [r0]
	b .L080F01D2
	.byte 0x00, 0x00
.L080F01CC: .4byte 0x03006434 @ IWRAM+0x6434
.L080F01D0:
	movs r0, #0
.L080F01D2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080F01D8
sub_080F01D8: @ 0x080F01D8
.L080F01D8:
	ldr r2, .L080F01E8
	ldr r2, [r2]
	lsls r0, r0, #1
	adds r2, #0x56
	adds r2, r2, r0
	strh r1, [r2]
	bx lr
	.byte 0x00, 0x00
.L080F01E8: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F01EC
sub_080F01EC: @ 0x080F01EC
.L080F01EC:
	ldr r1, .L080F01FC
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r1, #0x56
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	bx lr
.L080F01FC: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080F0200
sub_080F0200: @ 0x080F0200
.L080F0200:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L080F0304
	lsls r0, r4, #7
	movs r2, #0x9a
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r6, r0, r1
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF648
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r2, .L080F0308
	mov r0, sp
	adds r1, r6, #0
	bl CpuSet
	adds r4, #0x10
	strb r4, [r6, #0xc]
	strh r5, [r6, #0x12]
	movs r0, #0x80
	lsls r0, r0, #8
	strh r0, [r6, #0xe]
	movs r0, #0
	ldrsb r0, [r7, r0]
	strh r0, [r6, #0x14]
	ldrh r0, [r7, #2]
	strh r0, [r6, #0x18]
	ldrh r0, [r7, #2]
	strh r0, [r6, #0x1a]
	ldrh r0, [r7, #4]
	strh r0, [r6, #0x1c]
	ldrh r0, [r7, #4]
	strh r0, [r6, #0x1e]
	ldrb r0, [r7, #1]
	strb r0, [r6, #0xd]
	ldrb r0, [r7, #0xc]
	lsls r0, r0, #8
	adds r2, r6, #0
	adds r2, #0x58
	strh r0, [r2]
	movs r0, #0xa
	strb r0, [r6, #0x17]
	strb r0, [r6, #0x16]
	ldrb r1, [r7, #6]
	adds r0, r6, #0
	adds r0, #0x40
	strb r1, [r0]
	ldrb r0, [r7, #7]
	adds r1, r6, #0
	adds r1, #0x41
	strb r0, [r1]
	ldrb r0, [r7, #8]
	adds r1, #1
	strb r0, [r1]
	ldrb r0, [r7, #9]
	adds r1, #1
	strb r0, [r1]
	ldrb r1, [r7, #0xa]
	adds r0, r6, #0
	adds r0, #0x44
	strb r1, [r0]
	ldrb r0, [r7, #0xb]
	adds r1, r6, #0
	adds r1, #0x45
	strb r0, [r1]
	ldr r0, [r6, #0x40]
	ldr r1, [r6, #0x44]
	str r0, [r6, #0x28]
	str r1, [r6, #0x2c]
	ldrb r0, [r7, #0xc]
	lsls r0, r0, #8
	strh r0, [r2]
	movs r3, #0
	adds r2, #5
	movs r4, #0xff
	adds r5, r2, #0
.L080F02AA:
	adds r1, r2, r3
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r3, #1
	cmp r3, #0x1f
	ble .L080F02AA
	movs r4, #0
	movs r3, #0
	movs r0, #0x40
	adds r0, r0, r6
	mov sb, r0
	movs r2, #0x48
	adds r2, r2, r6
	mov ip, r2
	movs r0, #0x22
	adds r0, r0, r7
	mov r8, r0
	adds r2, r5, #0
	adds r5, r7, #0
	adds r5, #0x11
.L080F02D4:
	adds r0, r2, r4
	adds r1, r5, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, #1
	adds r3, #1
	cmp r3, #6
	ble .L080F02D4
	ldrb r0, [r6, #0xd]
	mov r1, sb
	mov r2, ip
	bl sub_080C0574
	mov r0, r8
	adds r1, r6, #0
	bl sub_080C0420
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F0304: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0308: .4byte 0x05000020 @ PLTT+0x20

	thumb_func_start sub_080F030C
sub_080F030C: @ 0x080F030C
.L080F030C:
	push {lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	lsrs r3, r0, #0x18
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #7
	bls .L080F0328
	movs r0, #7
	ands r1, r0
	adds r1, #1
.L080F0328:
	adds r0, r1, #0
	muls r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	ands r2, r0
	cmp r2, #0
	bne .L080F033C
	lsls r0, r1, #0x13
	lsrs r1, r0, #0x10
.L080F033C:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F0344
sub_080F0344: @ 0x080F0344
.L080F0344:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	ldr r1, .L080F0360
	cmp r0, #3
	beq .L080F0364
	cmp r0, #3
	ble .L080F0380
	cmp r0, #4
	beq .L080F0374
	b .L080F0380
	.byte 0x00, 0x00
.L080F0360: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0364:
	ldr r2, .L080F036C
	ldr r0, .L080F0370
	b .L080F0378
	.byte 0x00, 0x00
.L080F036C: .4byte 0x030000AC @ IWRAM+0xAC
.L080F0370: .4byte 0x0000097C
.L080F0374:
	ldr r2, .L080F0384
	ldr r0, .L080F0388
.L080F0378:
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
	strh r3, [r1]
.L080F0380:
	pop {r0}
	bx r0
.L080F0384: .4byte 0x030000AC @ IWRAM+0xAC
.L080F0388: .4byte 0x0000097E

	thumb_func_start sub_080F038C
sub_080F038C: @ 0x080F038C
.L080F038C:
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F3110
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r4, #0x10]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq .L080F03B4
	movs r0, #0
	cmp r2, #0
	bne .L080F03B2
	movs r0, #1
.L080F03B2:
	adds r2, r0, #0
.L080F03B4:
	lsls r0, r2, #0x10
	adds r4, r0, #0
	cmp r4, #0
	bne .L080F03C6
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	bl sub_080EE2E8
	b .L080F03CE
.L080F03C6:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	bl sub_080EE10C
.L080F03CE:
	asrs r0, r4, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F03D8
sub_080F03D8: @ 0x080F03D8
.L080F03D8:
	push {lr}
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xb
	bne .L080F042E
	adds r0, r1, #0
	subs r0, #0x4b
	cmp r0, #1
	bls .L080F042A
	cmp r1, #0x6d
	beq .L080F042A
	cmp r1, #0x6e
	beq .L080F042A
	cmp r1, #0x6f
	beq .L080F042A
	cmp r1, #0x4e
	beq .L080F042A
	cmp r1, #0x4f
	beq .L080F042A
	cmp r1, #0x71
	beq .L080F042A
	cmp r1, #0x74
	beq .L080F042A
	cmp r1, #0x7c
	beq .L080F042A
	cmp r1, #0x84
	beq .L080F042A
	cmp r1, #0x88
	beq .L080F042A
	cmp r1, #0x8a
	beq .L080F042A
	cmp r1, #0x8d
	beq .L080F042A
	cmp r1, #0x8e
	beq .L080F042A
	cmp r1, #0x90
	beq .L080F042A
	cmp r1, #0x91
	beq .L080F042A
	cmp r1, #0x92
	bne .L080F042E
.L080F042A:
	movs r0, #1
	b .L080F0430
.L080F042E:
	movs r0, #0
.L080F0430:
	pop {r1}
	bx r1

	thumb_func_start sub_080F0434
sub_080F0434: @ 0x080F0434
.L080F0434:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	lsls r0, r0, #0x10
	ldr r1, .L080F046C
	mov sl, r1
	lsrs r4, r0, #0x10
	asrs r5, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r6, r0, #0
	cmp r5, #0xf
	bgt .L080F0470
	adds r0, r5, #0
	bl sub_080C35E4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	b .L080F0474
	.byte 0x00, 0x00
.L080F046C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0470:
	ldrb r3, [r6, #0x17]
	str r3, [sp]
.L080F0474:
	ldr r0, .L080F048C
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xf
	bls .L080F0482
	b .L080F0B64
.L080F0482:
	lsls r0, r0, #2
	ldr r1, .L080F0490
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F048C: .4byte 0x0000097C
.L080F0490: .4byte gUnknown_080F0494
	.global gUnknown_080F0494
gUnknown_080F0494:
.L080F0494: @ jump table
	.4byte .L080F04D4
	.4byte .L080F0544
	.4byte .L080F0784
	.4byte .L080F079C
	.4byte .L080F079C
	.4byte .L080F07A8
	.4byte .L080F0B64
	.4byte .L080F07B4
	.4byte .L080F07C0
	.4byte .L080F07CC
	.4byte .L080F08D4
	.4byte .L080F0A94
	.4byte .L080F0ADC
	.4byte .L080F0AFC
	.4byte .L080F0B60
	.4byte .L080F0B64
.L080F04D4:
	ldr r0, .L080F0534
	add r0, sl
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080F0538
	add r0, sl
	strh r1, [r0]
	ldr r0, .L080F053C
	strh r1, [r0]
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080F0C18
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080F04FC
	b .L080F0B64
.L080F04FC:
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080EF5FC
	ldr r1, .L080F0540
	ldr r1, [r1]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r1, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r1, r6, #0
	bl sub_080F038C
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r0, #0x17
	ldrsb r0, [r6, r0]
	cmp r0, #9
	bne .L080F0526
	b .L080F0A78
.L080F0526:
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080F108C
	b .L080F0B64
.L080F0534: .4byte 0x00000F66
.L080F0538: .4byte 0x000011AA
.L080F053C: .4byte 0x03000080 @ IWRAM+0x80
.L080F0540: .4byte 0x03006434 @ IWRAM+0x6434
.L080F0544:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080F0552
	b .L080F0B64
.L080F0552:
	ldr r5, .L080F0610
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r0, #0xff
	beq .L080F0572
	bl sub_080C2B6C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080F0572
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0
	bl sub_080F4608
.L080F0572:
	ldr r5, .L080F0614
	add r5, sl
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0xff
	bne .L080F0580
	b .L080F0760
.L080F0580:
	cmp r0, #0xd2
	bgt .L080F0586
	b .L080F0720
.L080F0586:
	lsls r4, r4, #0x10
	asrs r1, r4, #0xf
	movs r0, #0xf3
	lsls r0, r0, #4
	add r0, sl
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	bl sub_080F4490
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r1, .L080F0618
	add r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r4, [sp, #8]
	cmp r0, #0xff
	beq .L080F05B4
	movs r3, #0
	ldrsh r0, [r1, r3]
	bl sub_080ECF70
.L080F05B4:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L080F05CE
	ldrh r0, [r5]
	subs r0, #0xf0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L080F05CE
	b .L080F0770
.L080F05CE:
	ldr r0, [sp, #8]
	asrs r4, r0, #0x10
	lsls r1, r4, #1
	movs r0, #0xf3
	lsls r0, r0, #4
	add r0, sl
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080F05F2
	adds r0, r4, #0
	bl sub_080F4490
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080F05F2:
	ldr r0, .L080F0614
	add r0, sl
	ldrh r0, [r0]
	subs r0, #0xf0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bls .L080F0604
	b .L080F0748
.L080F0604:
	lsls r0, r0, #2
	ldr r1, .L080F061C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080F0610: .4byte 0x030000AA @ IWRAM+0xAA
.L080F0614: .4byte 0x00000EC6
.L080F0618: .4byte 0x00000ECA
.L080F061C: .4byte gUnknown_080F0620
	.global gUnknown_080F0620
gUnknown_080F0620:
.L080F0620: @ jump table
	.4byte .L080F0640
	.4byte .L080F0654
	.4byte .L080F0668
	.4byte .L080F067C
	.4byte .L080F0690
	.4byte .L080F06B4
	.4byte .L080F06D8
	.4byte .L080F06FC
.L080F0640:
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #3
	bl sub_080ECE38
	b .L080F0748
.L080F0654:
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #0
	bl sub_080ECE38
	b .L080F0748
.L080F0668:
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #5
	bl sub_080ECE38
	b .L080F0748
.L080F067C:
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #1
	bl sub_080ECE38
	b .L080F0748
.L080F0690:
	movs r0, #5
	bl sub_080ECE08
	movs r0, #0
.L080F0698:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #3
	adds r0, r4, #0
	movs r2, #3
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L080F0698
	b .L080F0748
.L080F06B4:
	movs r0, #5
	bl sub_080ECE08
	movs r0, #0
.L080F06BC:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #3
	adds r0, r4, #0
	movs r2, #0
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L080F06BC
	b .L080F0748
.L080F06D8:
	movs r0, #5
	bl sub_080ECE08
	movs r0, #0
.L080F06E0:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #3
	adds r0, r4, #0
	movs r2, #5
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L080F06E0
	b .L080F0748
.L080F06FC:
	movs r0, #5
	bl sub_080ECE08
	movs r0, #0
.L080F0704:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #3
	adds r0, r4, #0
	movs r2, #1
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L080F0704
	b .L080F0748
.L080F0720:
	cmp r0, #0xff
	beq .L080F0760
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	bl sub_080F3110
	adds r3, r0, #0
	movs r4, #0
	ldrsh r0, [r5, r4]
	ldr r1, .L080F0754
	movs r2, #0
	ldrsh r1, [r1, r2]
	ldr r2, .L080F0758
	add r2, sl
	movs r4, #0
	ldrsh r2, [r2, r4]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl sub_080EC9AC
.L080F0748:
	ldr r1, .L080F075C
	add r1, sl
	movs r0, #2
	strh r0, [r1]
	b .L080F0B64
	.byte 0x00, 0x00
.L080F0754: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F0758: .4byte 0x00000ECA
.L080F075C: .4byte 0x0000097C
.L080F0760:
	ldr r1, .L080F077C
	add r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0xff
	beq .L080F0770
	bl sub_080ECF70
.L080F0770:
	ldr r1, .L080F0780
	add r1, sl
	movs r0, #3
	strh r0, [r1]
	b .L080F0B64
	.byte 0x00, 0x00
.L080F077C: .4byte 0x00000ECA
.L080F0780: .4byte 0x0000097C
.L080F0784:
	bl sub_080ECB10
	cmp r0, #0
	bne .L080F078E
	b .L080F0B64
.L080F078E:
	ldr r1, .L080F0798
	add r1, sl
	movs r0, #4
	strh r0, [r1]
	b .L080F0B64
.L080F0798: .4byte 0x0000097C
.L080F079C:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, r6, #0
	bl sub_080F0CFC
	b .L080F0B64
.L080F07A8:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, r6, #0
	bl sub_080F17C0
	b .L080F0B64
.L080F07B4:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, r6, #0
	bl sub_080F2514
	b .L080F0B64
.L080F07C0:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, r6, #0
	bl sub_080F27CC
	b .L080F0B64
.L080F07CC:
	ldr r5, .L080F0810
	ldrh r6, [r5, #4]
	movs r0, #4
	ldrsh r4, [r5, r0]
	adds r0, r4, #0
	bl sub_080EF0E4
	cmp r0, #0
	beq .L080F081C
	ldr r1, .L080F0814
	adds r0, r4, #0
	bl sub_080C08BC
	ldr r1, [r5, #0x18]
	adds r0, r4, #0
	bl sub_080C0AD4
	ldr r0, .L080F0818
	bl Battle_GetMessage
	adds r4, r0, #0
	bl sub_080F3E44
	adds r1, r0, #0
	lsls r1, r1, #0x10
	adds r0, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F0B48
	.byte 0x00, 0x00
.L080F0810: .4byte 0x03000088 @ IWRAM+0x88
.L080F0814: .4byte 0x00007FFF
.L080F0818: .4byte 0x00000171
.L080F081C:
	adds r0, r4, #0
	bl sub_080F3110
	cmp r0, #1
	bne .L080F0850
	ldr r1, .L080F0848
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	bl Battle_BuildDefeatedTargetText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r0, .L080F084C
	bl sub_080ECF70
	b .L080F08A8
	.byte 0x00, 0x00
.L080F0848: .4byte 0xFFFF8000
.L080F084C: .4byte 0x0000012F
.L080F0850:
	movs r2, #0x97
	lsls r2, r2, #1
	mov r8, r2
	cmp r4, #3
	bgt .L080F085E
	ldr r3, .L080F08C4
	mov r8, r3
.L080F085E:
	ldr r1, .L080F08C8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r5, r0, #0
	ldrh r7, [r5, #0x10]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	adds r0, r7, #0
	orrs r0, r1
	strh r0, [r5, #0x10]
	bl sub_080F3144
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F088C
	movs r0, #0
	bl BattleMsg_SetLocked
.L080F088C:
	strh r7, [r5, #0x10]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r4, r3
	ldr r1, .L080F08CC
	bl Battle_BuildNamePrependText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	mov r0, r8
	bl sub_080ECF70
.L080F08A8:
	lsls r4, r6, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_080EF218
	cmp r4, #0xf
	bgt .L080F08B8
	b .L080F0B48
.L080F08B8:
	ldr r1, .L080F08D0
	add r1, sl
	movs r0, #0xd
	strh r0, [r1]
	b .L080F0B64
	.byte 0x00, 0x00
.L080F08C4: .4byte 0x0000012D
.L080F08C8: .4byte 0xFFFF8000
.L080F08CC: .4byte gUnknown_08124264
.L080F08D0: .4byte 0x0000097C
.L080F08D4:
	bl sub_080ED9F4
	cmp r0, #0
	bne .L080F08DE
	b .L080F0A78
.L080F08DE:
	bl sub_080F3144
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F08EC
	b .L080F0A78
.L080F08EC:
	ldr r1, .L080F0938
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r7, .L080F093C
	add r7, sl
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	ldr r1, .L080F0940
	add r1, sl
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, .L080F0944
	add r2, sl
	mov sb, r2
	movs r0, #3
	strh r0, [r2]
	lsls r4, r4, #0x10
	asrs r5, r4, #0x10
	adds r0, r5, #0
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	cmp r1, #0
	beq .L080F0948
	movs r0, #0xb
	mov r3, sb
	strh r0, [r3]
	b .L080F0B64
	.byte 0x00, 0x00
.L080F0938: .4byte 0x03000080 @ IWRAM+0x80
.L080F093C: .4byte 0x00000F66
.L080F0940: .4byte 0x000011AA
.L080F0944: .4byte 0x0000097C
.L080F0948:
	bl sub_080ED954
	cmp r0, #0
	beq .L080F09BC
	ldr r4, .L080F09B4
	mov r8, r4
	ldr r0, [r4]
	movs r4, #0xae
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r2, .L080F09B8
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r0, [r0]
	cmp r0, r1
	ble .L080F09BC
	movs r0, #0
	ldrsh r1, [r7, r0]
	adds r0, r5, #0
	bl sub_080EFFF8
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L080F09BC
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r4
	ldr r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #8
	cmp r0, r2
	beq .L080F09BC
	mov r3, sp
	ldrh r3, [r3, #4]
	strh r3, [r7]
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_080F038C
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r4
	ldr r2, .L080F09B8
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r0, [r0]
	cmp r0, r1
	ble .L080F09AC
	b .L080F0B64
.L080F09AC:
	movs r0, #0xb
	mov r4, sb
	strh r0, [r4]
	b .L080F0B64
.L080F09B4: .4byte 0x03006434 @ IWRAM+0x6434
.L080F09B8: .4byte 0x03000080 @ IWRAM+0x80
.L080F09BC:
	ldr r1, [sp]
	lsls r0, r1, #0x18
	asrs r2, r0, #0x18
	movs r3, #0xfc
	lsls r3, r3, #0x18
	adds r0, r0, r3
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls .L080F09E2
	cmp r2, #0xa
	beq .L080F09E2
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r1, [r0]
	adds r0, r2, #0
	bl sub_080F03D8
	cmp r0, #1
	bne .L080F0A2C
.L080F09E2:
	ldr r6, .L080F0A20
	ldr r0, [r6]
	movs r5, #0xae
	lsls r5, r5, #1
	adds r0, r0, r5
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r1, r0
	beq .L080F0A2C
	ldr r4, [sp, #8]
	asrs r0, r4, #0x10
	ldr r4, .L080F0A24
	add r4, sl
	movs r2, #0
	ldrsh r1, [r4, r2]
	bl sub_080EFFF8
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L080F0A12
	movs r0, #0
	strh r0, [r4]
.L080F0A12:
	ldr r0, [r6]
	adds r0, r0, r5
	ldr r1, .L080F0A28
	movs r3, #0
	ldrsh r1, [r1, r3]
	b .L080F0A72
	.byte 0x00, 0x00
.L080F0A20: .4byte 0x03006434 @ IWRAM+0x6434
.L080F0A24: .4byte 0x00000F66
.L080F0A28: .4byte 0x03000080 @ IWRAM+0x80
.L080F0A2C:
	ldr r5, .L080F0A84
	ldr r0, [r5]
	movs r4, #0xae
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r2, .L080F0A88
	add r2, sl
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r0, [r0]
	cmp r0, r1
	bgt .L080F0A4C
	ldr r1, .L080F0A8C
	add r1, sl
	movs r0, #0xb
	strh r0, [r1]
.L080F0A4C:
	ldr r1, [sp, #8]
	asrs r0, r1, #0x10
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl sub_080EFFF8
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L080F0A68
	ldr r1, .L080F0A8C
	add r1, sl
	movs r0, #0xb
	strh r0, [r1]
.L080F0A68:
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r1, .L080F0A90
	movs r4, #0
	ldrsh r1, [r1, r4]
.L080F0A72:
	ldr r0, [r0]
	cmp r0, r1
	bgt .L080F0B64
.L080F0A78:
	ldr r1, .L080F0A8C
	add r1, sl
	movs r0, #0xb
	strh r0, [r1]
	b .L080F0B64
	.byte 0x00, 0x00
.L080F0A84: .4byte 0x03006434 @ IWRAM+0x6434
.L080F0A88: .4byte 0x00000F66
.L080F0A8C: .4byte 0x0000097C
.L080F0A90: .4byte 0x03000080 @ IWRAM+0x80
.L080F0A94:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F0B64
	bl sub_080ED954
	cmp r0, #0
	beq .L080F0AD8
	ldr r0, .L080F0AD0
	add r0, sl
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080F0AD8
	movs r0, #0
	bl sub_080EDA24
	cmp r0, #0
	beq .L080F0AC6
	movs r0, #1
	bl sub_080EDA24
	cmp r0, #0
	bne .L080F0AD8
.L080F0AC6:
	ldr r1, .L080F0AD4
	add r1, sl
	movs r0, #0xe
	b .L080F0B4E
	.byte 0x00, 0x00
.L080F0AD0: .4byte 0x0000118C
.L080F0AD4: .4byte 0x0000097C
.L080F0AD8:
	movs r0, #1
	b .L080F0B66
.L080F0ADC:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F0B64
	ldr r0, .L080F0AF4
	ldrh r1, [r0]
	ldr r0, .L080F0AF8
	add r0, sl
	strh r1, [r0]
	b .L080F0B64
.L080F0AF4: .4byte 0x030000AC @ IWRAM+0xAC
.L080F0AF8: .4byte 0x0000097C
.L080F0AFC:
	bl sub_080EDAD0
	cmp r0, #0
	beq .L080F0B14
	movs r0, #0x99
	lsls r0, r0, #4
	add r0, sl
	ldr r0, [r0]
	bl sub_080EDAEC
	cmp r0, #0
	beq .L080F0B48
.L080F0B14:
	ldr r0, .L080F0B40
	ldrh r6, [r0, #4]
	adds r0, r6, #0
	subs r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #2
	bl sub_080E75DC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080F0B64
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	bl sub_080F0B78
	cmp r0, #1
	bne .L080F0B48
	ldr r1, .L080F0B44
	add r1, sl
	movs r0, #0xe
	b .L080F0B4E
.L080F0B40: .4byte 0x03000088 @ IWRAM+0x88
.L080F0B44: .4byte 0x0000097C
.L080F0B48:
	ldr r1, .L080F0B5C
	add r1, sl
	movs r0, #0xa
.L080F0B4E:
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
	b .L080F0B64
	.byte 0x00, 0x00
.L080F0B5C: .4byte 0x0000097C
.L080F0B60:
	bl sub_080F0BEC
.L080F0B64:
	movs r0, #0
.L080F0B66:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F0B78
sub_080F0B78: @ 0x080F0B78
.L080F0B78:
	push {r4, r5, lr}
	ldr r5, .L080F0BA0
	lsls r0, r0, #0x18
	movs r1, #0xf0
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r4, r0, #0x18
	bl sub_080ED954
	cmp r0, #0
	beq .L080F0BB6
	ldr r1, .L080F0BA4
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080F0BB6
	cmp r4, #3
	bhi .L080F0BA8
	movs r0, #0
	b .L080F0BAA
.L080F0BA0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0BA4: .4byte 0x0000118C
.L080F0BA8:
	movs r0, #1
.L080F0BAA:
	bl sub_080EDA24
	cmp r0, #0
	bne .L080F0BB6
	movs r0, #1
	b .L080F0BB8
.L080F0BB6:
	movs r0, #0
.L080F0BB8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F0BC0
sub_080F0BC0: @ 0x080F0BC0
	ldr r1, .L080F0BD0
	ldr r0, .L080F0BD4
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080F0BD0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0BD4: .4byte 0x0000118C

	thumb_func_start sub_080F0BD8
sub_080F0BD8: @ 0x080F0BD8
	ldr r0, .L080F0BE4
	ldr r1, .L080F0BE8
	adds r0, r0, r1
	movs r1, #0xa
	strh r1, [r0]
	bx lr
.L080F0BE4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0BE8: .4byte 0x0000097C

	thumb_func_start sub_080F0BEC
sub_080F0BEC: @ 0x080F0BEC
.L080F0BEC:
	push {r4, lr}
	ldr r4, .L080F0C08
	ldr r0, .L080F0C0C
	ldr r1, .L080F0C10
	bl Task_Create
	ldr r0, .L080F0C14
	adds r4, r4, r0
	movs r0, #0xf
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F0C08: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0C0C: .4byte gUnknown_0876F7DC
.L080F0C10: .4byte 0x0000FFFF
.L080F0C14: .4byte 0x0000097C

	thumb_func_start sub_080F0C18
sub_080F0C18: @ 0x080F0C18
.L080F0C18:
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r7, .L080F0C40
	ldrh r4, [r6, #0x10]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq .L080F0C64
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	cmp r4, #3
	ble .L080F0C44
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_080C35C4
	b .L080F0CF4
.L080F0C40: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0C44:
	adds r0, r4, #0
	movs r1, #0
	bl sub_080C00DC
	cmp r0, #0xff
	beq .L080F0C5A
	adds r0, r4, #0
	movs r1, #4
	bl sub_080C35C4
	b .L080F0CF4
.L080F0C5A:
	adds r0, r4, #0
	movs r1, #9
	bl sub_080C35C4
	b .L080F0CF4
.L080F0C64:
	movs r0, #8
	ands r0, r4
	cmp r0, #0
	beq .L080F0CAC
	bl sub_080C2244
	movs r1, #0x28
	bl __umodsi3
	cmp r0, #0x13
	bhi .L080F0CAC
	movs r0, #0xb9
	lsls r0, r0, #1
	bl Battle_GetMessage
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r0, .L080F0CA8
	adds r1, r7, r0
	movs r0, #0xb
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
	movs r0, #1
	b .L080F0CF6
	.byte 0x00, 0x00
.L080F0CA8: .4byte 0x0000097C
.L080F0CAC:
	movs r0, #0x10
	ands r4, r0
	cmp r4, #0
	beq .L080F0CF4
	bl sub_080C2244
	adds r2, r0, #0
	movs r0, #3
	ands r2, r0
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080F0CF4
	lsls r0, r5, #0x10
	asrs r3, r0, #0x10
	adds r1, r0, #0
	cmp r3, #0xf
	bgt .L080F0CF0
	cmp r3, #3
	ble .L080F0CE6
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	bne .L080F0CE6
	adds r0, r3, #0
	movs r1, #0xc
	bl sub_080C35C4
	b .L080F0CF4
.L080F0CE6:
	asrs r0, r1, #0x10
	movs r1, #9
	bl sub_080C35C4
	b .L080F0CF4
.L080F0CF0:
	movs r0, #9
	strb r0, [r6, #0x17]
.L080F0CF4:
	movs r0, #0
.L080F0CF6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080F0CFC
sub_080F0CFC: @ 0x080F0CFC
.L080F0CFC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r7, .L080F0D40
	adds r0, #0x5c
	ldrb r0, [r0]
	str r0, [sp]
	movs r0, #0x17
	ldrsb r0, [r6, r0]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L080F0D44
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r2, [r6, #0x10]
	mov r8, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080F0D48
	lsls r4, r1, #0x10
	asrs r0, r4, #0x10
	bl sub_080F2C9C
	b .L080F0D58
	.byte 0x00, 0x00
.L080F0D40: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0D44: .4byte 0x03006434 @ IWRAM+0x6434
.L080F0D48:
	lsls r4, r1, #0x10
	asrs r0, r4, #0x10
	ldr r2, .L080F0D84
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl sub_080EFFF8
.L080F0D58:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	mov sb, r4
	lsls r0, r5, #0x10
	asrs r5, r0, #0x10
	mov sl, r0
	cmp r5, #8
	bne .L080F0D88
	ldr r1, .L080F0D84
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080F0E54
	movs r1, #1
	rsbs r1, r1, #0
	ldr r0, [sp]
	bl sub_080F3E54
	b .L080F0E54
	.byte 0x00, 0x00
.L080F0D84: .4byte 0x00000F66
.L080F0D88:
	cmp r5, #7
	bne .L080F0E0C
	ldr r0, [sp]
	cmp r0, #0x3f
	bgt .L080F0E54
	movs r5, #0
	ldrh r4, [r6, #0x1c]
	bl sub_080ED6CC
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, .L080F0DC8
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080F0DCE
	mov r1, sb
	asrs r0, r1, #0x10
	cmp r0, #0xf
	bgt .L080F0DCE
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r1, #0
	bge .L080F0DCC
	movs r5, #1
	b .L080F0DCE
	.byte 0x00, 0x00
.L080F0DC8: .4byte 0x000011AA
.L080F0DCC:
	strh r4, [r6, #0x1c]
.L080F0DCE:
	movs r0, #2
	mov r2, r8
	ands r2, r0
	cmp r2, #0
	beq .L080F0DDA
	movs r5, #2
.L080F0DDA:
	adds r0, r5, #0
	cmp r0, #0
	beq .L080F0E54
	cmp r0, #2
	bne .L080F0DF4
	ldr r1, .L080F0DF0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F0DFC
	.byte 0x00, 0x00
.L080F0DF0: .4byte gUnknown_081241B0
.L080F0DF4:
	ldr r1, .L080F0E04
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F0DFC:
	ldr r0, .L080F0E08
	adds r1, r7, r0
	movs r0, #0xb
	b .L080F0F4E
.L080F0E04: .4byte gUnknown_081241D0
.L080F0E08: .4byte 0x0000097C
.L080F0E0C:
	cmp r5, #0xb
	bne .L080F0E64
	ldr r1, .L080F0E40
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080F0E54
	mov r2, sb
	asrs r4, r2, #0x10
	cmp r4, #0xf
	bgt .L080F0E54
	adds r0, r4, #0
	ldr r1, [sp]
	bl sub_080ED744
	cmp r0, #1
	beq .L080F0E4C
	ldr r1, .L080F0E44
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, .L080F0E48
	adds r0, r7, r1
	strh r5, [r0]
	b .L080F0F50
	.byte 0x00, 0x00
.L080F0E40: .4byte 0x000011AA
.L080F0E44: .4byte gUnknown_081241E0
.L080F0E48: .4byte 0x0000097C
.L080F0E4C:
	adds r0, r4, #0
	ldr r1, [sp]
	bl sub_080ED6DC
.L080F0E54:
	mov r2, sl
	asrs r0, r2, #0x10
	cmp r0, #0xb
	bne .L080F0E64
	ldr r0, [sp]
	subs r0, #0x54
	cmp r0, #0x13
	bls .L080F0EC8
.L080F0E64:
	mov r0, sb
	asrs r4, r0, #0x10
	ldr r1, [sp, #4]
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080EE028
	cmp r0, #0
	bne .L080F0EC8
	adds r0, r4, #0
	bl sub_080F3110
	cmp r0, #0
	bne .L080F0E94
	ldr r1, .L080F0E90
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F0EAC
	.byte 0x00, 0x00
.L080F0E90: .4byte gUnknown_081230A8
.L080F0E94:
	ldr r2, .L080F0EC0
	adds r0, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	bl Battle_BuildDodgeText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F0EAC:
	ldr r0, .L080F0EC4
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
	b .L080F0F50
	.byte 0x00, 0x00
.L080F0EC0: .4byte 0xFFFF8000
.L080F0EC4: .4byte 0x0000097C
.L080F0EC8:
	mov r1, sl
	asrs r4, r1, #0x10
	ldr r0, .L080F0EF8
	add r0, sl
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080F0F40
	cmp r4, #0xa
	beq .L080F0F40
	cmp r4, #8
	bne .L080F0F2C
	ldr r0, [sp]
	movs r1, #0xc
	mov r2, sp
	bl sub_080BF468
	ldr r0, [sp]
	cmp r0, #0x7f
	ble .L080F0F00
	ldr r1, .L080F0EFC
	adds r0, r7, r1
	strh r4, [r0]
	b .L080F0F50
	.byte 0x00, 0x00
.L080F0EF8: .4byte 0xFFFC0000
.L080F0EFC: .4byte 0x0000097C
.L080F0F00:
	subs r0, #0x1d
	cmp r0, #0x22
	bhi .L080F0F14
	ldr r2, .L080F0F10
	adds r1, r7, r2
	movs r0, #7
	b .L080F0F4E
	.byte 0x00, 0x00
.L080F0F10: .4byte 0x0000097C
.L080F0F14:
	ldr r0, .L080F0F24
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, .L080F0F28
	adds r1, r7, r2
	b .L080F0F4C
	.byte 0x00, 0x00
.L080F0F24: .4byte 0x0000097E
.L080F0F28: .4byte 0x0000097C
.L080F0F2C:
	ldr r0, [sp]
	subs r0, #0x1d
	cmp r0, #0x22
	bhi .L080F0F40
	ldr r0, .L080F0F3C
	adds r1, r7, r0
	movs r0, #7
	b .L080F0F4E
.L080F0F3C: .4byte 0x0000097C
.L080F0F40:
	ldr r2, .L080F0F60
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L080F0F64
	adds r1, r7, r0
.L080F0F4C:
	movs r0, #5
.L080F0F4E:
	strh r0, [r1]
.L080F0F50:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F0F60: .4byte 0x0000097E
.L080F0F64: .4byte 0x0000097C

	thumb_func_start sub_080F0F68
sub_080F0F68: @ 0x080F0F68
.L080F0F68:
	push {lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, .L080F0F8C
	lsrs r0, r0, #0xe
	adds r1, r1, r0
	adds r1, r1, r2
	ldrb r2, [r1]
	adds r0, r2, #0
	subs r0, #0xdc
	cmp r0, #0x22
	bhi .L080F1046
	lsls r0, r0, #2
	ldr r1, .L080F0F90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F0F8C: .4byte gUnknown_0876E1D8
.L080F0F90: .4byte gUnknown_080F0F94
	.global gUnknown_080F0F94
gUnknown_080F0F94:
.L080F0F94: @ jump table
	.4byte .L080F103C
	.4byte .L080F1020
	.4byte .L080F1024
	.4byte .L080F1028
	.4byte .L080F103C
	.4byte .L080F102C
	.4byte .L080F1030
	.4byte .L080F103C
	.4byte .L080F1034
	.4byte .L080F1038
	.4byte .L080F103C
	.4byte .L080F1040
	.4byte .L080F1044
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
.L080F1020:
	movs r2, #0x34
	b .L080F1046
.L080F1024:
	movs r2, #0x64
	b .L080F1046
.L080F1028:
	movs r2, #0x70
	b .L080F1046
.L080F102C:
	movs r2, #0x37
	b .L080F1046
.L080F1030:
	movs r2, #0x67
	b .L080F1046
.L080F1034:
	movs r2, #0x36
	b .L080F1046
.L080F1038:
	movs r2, #0x66
	b .L080F1046
.L080F103C:
	movs r2, #0xff
	b .L080F1046
.L080F1040:
	movs r2, #0x35
	b .L080F1046
.L080F1044:
	movs r2, #0x65
.L080F1046:
	adds r0, r2, #0
	pop {r1}
	bx r1

	thumb_func_start sub_080F104C
sub_080F104C: @ 0x080F104C
.L080F104C:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, .L080F1078
	lsls r4, r3, #2
	adds r0, r1, r4
	adds r2, r0, r5
	ldrb r0, [r2]
	cmp r0, #0xd1
	bls .L080F107C
	adds r0, r3, #0
	bl sub_080F0F68
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xdb
	bls .L080F107E
	adds r0, r4, r5
	ldrh r0, [r0, #2]
	b .L080F1086
.L080F1078: .4byte gUnknown_0876E1D8
.L080F107C:
	ldrb r0, [r2]
.L080F107E:
	bl sub_080ED32C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080F1086:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080F108C
sub_080F108C: @ 0x080F108C
.L080F108C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	adds r4, r1, #0
	lsls r4, r4, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	ldr r0, .L080F110C
	mov sb, r0
	lsrs r1, r4, #0x10
	str r1, [sp, #4]
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_080F3F14
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	movs r2, #0
	str r2, [sp, #0x10]
	ldr r0, .L080F1110
	add r0, sb
	movs r1, #0xff
	strh r1, [r0]
	ldr r0, .L080F1114
	add r0, sb
	strh r1, [r0]
	ldr r0, .L080F1118
	add r0, sb
	strh r1, [r0]
	ldr r0, .L080F111C
	strh r1, [r0]
	ldr r1, .L080F1120
	subs r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080F1124
	add r1, sb
	movs r0, #1
	strh r0, [r1]
	mov r1, sl
	ldrb r0, [r1, #0x17]
	subs r0, #4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bls .L080F1100
	b .L080F14BE
.L080F1100:
	lsls r0, r0, #2
	ldr r1, .L080F1128
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080F110C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F1110: .4byte 0x00000ECA
.L080F1114: .4byte 0x00000EC6
.L080F1118: .4byte 0x00000EC8
.L080F111C: .4byte 0x030000AA @ IWRAM+0xAA
.L080F1120: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F1124: .4byte 0x0000097C
.L080F1128: .4byte gUnknown_080F112C
	.global gUnknown_080F112C
gUnknown_080F112C:
.L080F112C: @ jump table
	.4byte .L080F1150
	.4byte .L080F11AC
	.4byte .L080F1480
	.4byte .L080F1340
	.4byte .L080F1224
	.4byte .L080F1498
	.4byte .L080F1208
	.4byte .L080F1340
	.4byte .L080F149E
.L080F1150:
	mov r0, sl
	movs r1, #0
	bl Battle_BuildCombatActionList
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r2, [sp, #4]
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #0
	bl sub_080C00DC
	ldr r1, .L080F11A0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r0, .L080F11A4
	add r0, sb
	strh r1, [r0]
	ldrh r0, [r0]
	bl sub_080ED32C
	ldr r1, .L080F11A8
	add r1, sb
	strh r0, [r1]
	mov r0, sl
	adds r1, r4, #0
	bl sub_080EF5FC
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	beq .L080F119A
	b .L080F14BE
.L080F119A:
	movs r0, #1
	str r0, [sp, #0x10]
	b .L080F14BE
.L080F11A0: .4byte gUnknown_0876E458
.L080F11A4: .4byte 0x00000EC6
.L080F11A8: .4byte 0x00000ECA
.L080F11AC:
	mov r0, sl
	movs r1, #1
	bl Battle_BuildCombatActionList
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, [sp, #4]
	lsls r4, r1, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #1
	bl sub_080C00DC
	ldr r1, .L080F11FC
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r0, .L080F1200
	add r0, sb
	strh r1, [r0]
	ldrh r0, [r0]
	bl sub_080ED32C
	ldr r1, .L080F1204
	add r1, sb
	strh r0, [r1]
	mov r0, sl
	adds r1, r4, #0
	bl sub_080EF5FC
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	beq .L080F11F6
	b .L080F14BE
.L080F11F6:
	movs r2, #1
	str r2, [sp, #0x10]
	b .L080F14BE
.L080F11FC: .4byte gUnknown_0876E458
.L080F1200: .4byte 0x00000EC6
.L080F1204: .4byte 0x00000ECA
.L080F1208:
	movs r0, #0
	bl sub_080ED32C
	ldr r1, .L080F1220
	add r1, sb
	strh r0, [r1]
	mov r0, sl
	movs r1, #2
	bl Battle_BuildCombatActionList
	b .L080F1332
	.byte 0x00, 0x00
.L080F1220: .4byte 0x00000ECA
.L080F1224:
	lsls r4, r5, #0x10
	asrs r0, r4, #0x10
	movs r1, #0xc
	mov r2, sp
	bl sub_080BF468
	ldr r1, [sp, #4]
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r6, r0, #0
	mov r8, r4
	cmp r1, #0xf
	bgt .L080F124E
	lsrs r0, r4, #0x10
	bl Action_GetRecord
	ldrb r0, [r0, #3]
	cmp r0, #0xff
	bne .L080F124E
	movs r2, #1
	str r2, [sp, #0x10]
.L080F124E:
	mov r1, r8
	asrs r0, r1, #0x10
	cmp r0, #0xf0
	bne .L080F1274
	ldr r1, [sp]
	ldr r0, .L080F1270
	add r0, sb
	strh r1, [r0]
	asrs r1, r6, #0xf
	movs r0, #0xf3
	lsls r0, r0, #4
	add r0, sb
	adds r0, r0, r1
	mov r2, sl
	ldrb r1, [r2, #0xc]
	b .L080F127E
	.byte 0x00, 0x00
.L080F1270: .4byte 0x00001192
.L080F1274:
	cmp r0, #0xf8
	bne .L080F1280
	ldr r1, [sp]
	ldr r0, .L080F12E8
	add r0, sb
.L080F127E:
	strh r1, [r0]
.L080F1280:
	mov r1, r8
	asrs r0, r1, #0x10
	cmp r0, #0xbc
	ble .L080F1290
	ldr r0, [sp]
	subs r0, #0x20
	cmp r0, #0x17
	bhi .L080F129C
.L080F1290:
	asrs r0, r6, #0x10
	bl sub_080F3110
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
.L080F129C:
	mov r2, r8
	asrs r1, r2, #0x10
	cmp r1, #0xf8
	beq .L080F12A8
	cmp r1, #0xf0
	bne .L080F12F4
.L080F12A8:
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	lsls r4, r1, #0x10
	lsrs r5, r4, #0x10
	adds r1, r5, #0
	bl sub_080F0F68
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L080F12EC
	add r1, sb
	strh r0, [r1]
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl sub_080F104C
	ldr r1, .L080F12F0
	add r1, sb
	strh r0, [r1]
	ldr r0, [sp]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	asrs r4, r4, #0x10
	adds r1, r4, #0
	bl sub_080F157C
	b .L080F132C
	.byte 0x00, 0x00
.L080F12E8: .4byte 0x00001194
.L080F12EC: .4byte 0x00000EC6
.L080F12F0: .4byte 0x00000ECA
.L080F12F4:
	ldr r0, .L080F1314
	subs r1, #0xd0
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r0, [r1]
	ldr r2, .L080F1318
	add r2, sb
	strh r0, [r2]
	cmp r0, #0xc8
	ble .L080F1320
	ldrh r1, [r1, #2]
	ldr r0, .L080F131C
	add r0, sb
	strh r1, [r0]
	b .L080F132C
	.byte 0x00, 0x00
.L080F1314: .4byte gUnknown_0876E618
.L080F1318: .4byte 0x00000EC6
.L080F131C: .4byte 0x00000ECA
.L080F1320:
	ldrh r0, [r2]
	bl sub_080ED32C
	ldr r1, .L080F133C
	add r1, sb
	strh r0, [r1]
.L080F132C:
	mov r0, sl
	bl Battle_BuildActorActionText
.L080F1332:
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F14BE
.L080F133C: .4byte 0x00000ECA
.L080F1340:
	ldr r2, [sp, #4]
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	adds r6, r0, #0
	lsls r5, r5, #0x10
	mov r8, r5
	cmp r1, #0xf
	bgt .L080F1364
	lsrs r0, r5, #0x10
	bl sub_080BF5C0
	ldrb r0, [r0, #2]
	cmp r0, #0xf
	beq .L080F1360
	cmp r0, #0xff
	bne .L080F1364
.L080F1360:
	movs r0, #1
	str r0, [sp, #0x10]
.L080F1364:
	mov r1, r8
	asrs r7, r1, #0x10
	cmp r7, #0x3f
	bgt .L080F13E4
	adds r0, r7, #0
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x17
	bhi .L080F1384
	asrs r0, r6, #0x10
	bl sub_080F3110
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
.L080F1384:
	cmp r4, #2
	bhi .L080F138E
	ldr r1, .L080F13B4
	movs r0, #0
	strh r0, [r1]
.L080F138E:
	mov r0, sl
	bl sub_080EAE30
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	movs r0, #2
	ldr r2, [sp, #0xc]
	ands r0, r2
	cmp r0, #0
	beq .L080F13BC
	ldr r1, .L080F13B8
	add r1, sb
	movs r0, #0xff
	strh r0, [r1]
	ldr r0, [sp, #8]
	lsls r4, r0, #0x10
	b .L080F1466
.L080F13B4: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F13B8: .4byte 0x00000EC6
.L080F13BC:
	mov r1, r8
	lsrs r0, r1, #0x10
	ldr r2, [sp, #8]
	lsls r4, r2, #0x10
	lsrs r1, r4, #0x10
	bl sub_080F0F68
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L080F13E0
	add r1, sb
	strh r0, [r1]
	asrs r1, r4, #0x10
	adds r0, r7, #0
	bl sub_080F157C
	b .L080F1466
	.byte 0x00, 0x00
.L080F13E0: .4byte 0x00000EC6
.L080F13E4:
	ldr r1, .L080F141C
	adds r0, r7, #0
	subs r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r5, [r0, r1]
	cmp r7, #0x66
	bne .L080F1420
	bl sub_080F5938
	adds r4, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L080F1406
	movs r4, #0
.L080F1406:
	adds r0, r5, #0
	bl Battle_GetMessage
	adds r1, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F1444
.L080F141C: .4byte gUnknown_0876E878
.L080F1420:
	adds r0, r5, #0
	bl Battle_GetMessage
	adds r5, r0, #0
	asrs r4, r6, #0x10
	adds r0, r4, #0
	bl sub_080F3F14
	lsls r0, r0, #0x10
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F1444:
	mov r2, r8
	lsrs r0, r2, #0x10
	ldr r1, [sp, #8]
	lsls r4, r1, #0x10
	lsrs r1, r4, #0x10
	bl sub_080F0F68
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L080F1478
	add r1, sb
	strh r0, [r1]
	mov r2, r8
	asrs r0, r2, #0x10
	asrs r1, r4, #0x10
	bl sub_080F157C
.L080F1466:
	mov r1, r8
	lsrs r0, r1, #0x10
	lsrs r1, r4, #0x10
	bl sub_080F104C
	ldr r1, .L080F147C
	add r1, sb
	b .L080F14BC
	.byte 0x00, 0x00
.L080F1478: .4byte 0x00000EC6
.L080F147C: .4byte 0x00000ECA
.L080F1480:
	ldr r2, [sp, #4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	bl sub_080F1678
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	movs r1, #3
	b .L080F14AA
.L080F1498:
	mov r0, sl
	movs r1, #4
	b .L080F14AA
.L080F149E:
	ldr r0, [sp, #4]
	movs r1, #0
	bl sub_080C0290
	mov r0, sl
	movs r1, #5
.L080F14AA:
	bl Battle_BuildCombatActionList
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, .L080F14EC
	add r1, sb
	movs r0, #0xb
.L080F14BC:
	strh r0, [r1]
.L080F14BE:
	ldr r0, .L080F14F0
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x88
	bne .L080F14D8
	mov r2, sl
	movs r0, #0x17
	ldrsb r0, [r2, r0]
	cmp r0, #8
	bne .L080F14D8
	movs r0, #1
	str r0, [sp, #0x10]
.L080F14D8:
	bl sub_080ED954
	cmp r0, #0
	beq .L080F14E6
	ldr r1, [sp, #0x10]
	cmp r1, #1
	bne .L080F14F8
.L080F14E6:
	ldr r1, .L080F14F4
	movs r0, #0
	b .L080F154C
.L080F14EC: .4byte 0x0000097C
.L080F14F0: .4byte 0x00000EC6
.L080F14F4: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F14F8:
	ldr r2, [sp, #4]
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	adds r6, r0, #0
	cmp r1, #0xf
	bgt .L080F1538
	movs r0, #0
	bl sub_080EDA24
	cmp r0, #0
	beq .L080F1522
	movs r0, #1
	bl sub_080EDA24
	cmp r0, #0
	beq .L080F1522
	ldr r1, .L080F1534
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq .L080F154C
.L080F1522:
	asrs r0, r6, #0x10
	bl sub_080F1788
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080F1548
	ldr r1, .L080F1534
	movs r0, #1
	b .L080F154C
.L080F1534: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F1538:
	cmp r1, #0x13
	bgt .L080F1548
	ldr r1, .L080F1544
	movs r0, #1
	b .L080F154C
	.byte 0x00, 0x00
.L080F1544: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F1548:
	ldr r1, .L080F1574
	movs r0, #2
.L080F154C:
	strh r0, [r1]
	bl sub_080C2B6C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080F1562
	ldr r1, .L080F1578
	add r1, sb
	movs r0, #0xff
	strh r0, [r1]
.L080F1562:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F1574: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F1578: .4byte 0x00000EC6

	thumb_func_start sub_080F157C
sub_080F157C: @ 0x080F157C
.L080F157C:
	push {lr}
	ldr r2, .L080F15A8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0xe
	adds r1, r1, r0
	adds r1, r1, r2
	ldrb r2, [r1]
	ldr r1, .L080F15AC
	movs r0, #0xff
	strh r0, [r1]
	adds r0, r2, #0
	subs r0, #0xdc
	adds r2, r1, #0
	cmp r0, #0x23
	bhi .L080F1670
	lsls r0, r0, #2
	ldr r1, .L080F15B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F15A8: .4byte gUnknown_0876E1D8
.L080F15AC: .4byte 0x030000AA @ IWRAM+0xAA
.L080F15B0: .4byte gUnknown_080F15B4
	.global gUnknown_080F15B4
gUnknown_080F15B4:
.L080F15B4: @ jump table
	.4byte .L080F1644
	.4byte .L080F1648
	.4byte .L080F164C
	.4byte .L080F1650
	.4byte .L080F1654
	.4byte .L080F1658
	.4byte .L080F165C
	.4byte .L080F1660
	.4byte .L080F1664
	.4byte .L080F1668
	.4byte .L080F166C
	.4byte .L080F166C
	.4byte .L080F166C
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
.L080F1644:
	movs r0, #4
	b .L080F166E
.L080F1648:
	movs r0, #4
	b .L080F166E
.L080F164C:
	movs r0, #4
	b .L080F166E
.L080F1650:
	movs r0, #4
	b .L080F166E
.L080F1654:
	movs r0, #7
	b .L080F166E
.L080F1658:
	movs r0, #7
	b .L080F166E
.L080F165C:
	movs r0, #7
	b .L080F166E
.L080F1660:
	movs r0, #8
	b .L080F166E
.L080F1664:
	movs r0, #8
	b .L080F166E
.L080F1668:
	movs r0, #8
	b .L080F166E
.L080F166C:
	movs r0, #5
.L080F166E:
	strh r0, [r2]
.L080F1670:
	movs r1, #0
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1

	thumb_func_start sub_080F1678
sub_080F1678: @ 0x080F1678
.L080F1678:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r1, r1, #0x10
	ldr r3, .L080F16F0
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	movs r4, #0xf1
	lsls r4, r4, #4
	adds r2, r3, r4
	adds r5, r0, r2
	ldrh r6, [r5]
	movs r2, #0xef
	lsls r2, r2, #4
	adds r3, r3, r2
	adds r4, r0, r3
	ldrh r0, [r4]
	mov r8, r0
	lsrs r7, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #2
	bne .L080F16D4
	ldr r1, .L080F16F4
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r1, r2
	adds r2, r0, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L080F16CA
	adds r0, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C0290
.L080F16CA:
	ldr r0, .L080F16F8
	strh r0, [r4]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r5]
.L080F16D4:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	bl sub_080F30CC
	movs r1, #1
	rsbs r1, r1, #0
	lsls r7, r7, #0x10
	mov r4, r8
	lsls r4, r4, #0x10
	mov r8, r4
	cmp r0, r1
	beq .L080F171A
	movs r0, #0
	b .L080F1702
.L080F16F0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F16F4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F16F8: .4byte 0x0000FFFF
.L080F16FC:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080F1702:
	lsls r5, r0, #0x10
	asrs r4, r5, #0x10
	cmp r4, #5
	bgt .L080F171A
	adds r0, r4, #0
	bl sub_080F30CC
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L080F16FC
	lsrs r6, r5, #0x10
.L080F171A:
	mov r0, r8
	lsrs r5, r0, #0x10
	lsls r6, r6, #0x10
	lsrs r1, r6, #0x10
	adds r0, r5, #0
	bl sub_080C0248
	asrs r4, r7, #0x10
	cmp r4, #0
	bne .L080F173A
	adds r0, r5, #0
	bl sub_0812839C
	rsbs r0, r0, #0
	bl sub_080F3E20
.L080F173A:
	asrs r5, r6, #0x10
	cmp r4, #3
	bne .L080F1760
	ldr r4, .L080F1784
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r4, r5, r4
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0x80
	lsls r1, r1, #7
	bl sub_080C08F8
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0
	bl sub_080F4054
.L080F1760:
	adds r0, r5, #0
	bl sub_080C8490
	bl sub_080C366C
	bl Party_BuildMemberNameTiles
	mov r2, r8
	asrs r0, r2, #0x10
	bl sub_080BFFC4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080F1784: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_080F1788
sub_080F1788: @ 0x080F1788
.L080F1788:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080EDA64
	bl sub_080ED974
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080EDA24
	cmp r0, #0
	bne .L080F17AE
	movs r0, #1
	eors r4, r0
	lsls r0, r4, #0x10
	lsrs r5, r0, #0x10
.L080F17AE:
	cmp r5, #0
	beq .L080F17B6
	movs r0, #1
	b .L080F17B8
.L080F17B6:
	movs r0, #0
.L080F17B8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F17C0
sub_080F17C0: @ 0x080F17C0
.L080F17C0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	lsls r0, r1, #0x10
	ldr r6, .L080F181C
	movs r1, #0x17
	ldrsb r1, [r7, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	adds r1, r7, #0
	adds r1, #0x5c
	ldrb r1, [r1]
	str r1, [sp]
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, .L080F1820
	adds r1, r6, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	bl sub_080EFFF8
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	mov sb, r0
	mov r2, r8
	cmp r2, #8
	bne .L080F1830
	ldr r0, [sp]
	cmp r0, #0xf8
	bne .L080F1828
	ldr r3, .L080F1824
	adds r0, r6, r3
	ldrh r0, [r0]
	str r0, [sp]
	b .L080F1830
.L080F181C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F1820: .4byte 0x00000F66
.L080F1824: .4byte 0x00001194
.L080F1828:
	movs r1, #0xc
	mov r2, sp
	bl sub_080BF468
.L080F1830:
	ldr r1, .L080F184C
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xd
	bls .L080F1840
	bl .L080F20C6
.L080F1840:
	lsls r0, r0, #2
	ldr r1, .L080F1850
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080F184C: .4byte 0x0000097E
.L080F1850: .4byte gUnknown_080F1854
	.global gUnknown_080F1854
gUnknown_080F1854:
.L080F1854: @ jump table
	.4byte .L080F188C
	.4byte .L080F1944
	.4byte .L080F1974
	.4byte .L080F1B5C
	.4byte .L080F1C4C
	.4byte .L080F1CBC
	.4byte .L080F2034
	.4byte .L080F204C
	.4byte .L080F1FB0
	.4byte .L080F2000
	.4byte .L080F1E48
	.4byte .L080F1E2C
	.4byte .L080F1E84
	.4byte .L080F20B0
.L080F188C:
	movs r0, #0
	bl sub_080EDA7C
	ldr r1, .L080F18DC
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	str r0, [r1]
	lsls r0, r5, #0x10
	asrs r3, r0, #0x10
	str r3, [r1, #4]
	movs r2, #0
	str r2, [r1, #0x18]
	movs r4, #1
	str r4, [r1, #0xc]
	ldr r0, .L080F18E0
	strh r2, [r0]
	mov r5, r8
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	ldr r5, .L080F18E4
	adds r0, r0, r5
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080F18C0
	cmp r1, #0xa
	bne .L080F18F0
.L080F18C0:
	ldr r0, .L080F18E8
	strh r2, [r0]
	ldr r1, .L080F18EC
	adds r0, r6, r1
	strh r4, [r0]
	adds r0, r3, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F18D8
	bl .L080F20C6
.L080F18D8:
	bl .L080F20A0
.L080F18DC: .4byte 0x03000088 @ IWRAM+0x88
.L080F18E0: .4byte 0x03000082 @ IWRAM+0x82
.L080F18E4: .4byte 0xFFFC0000
.L080F18E8: .4byte 0x030000AE @ IWRAM+0xAE
.L080F18EC: .4byte 0x0000097E
.L080F18F0:
	ldr r1, [sp]
	adds r0, r1, #0
	subs r0, #0x13
	cmp r0, #9
	bls .L080F1910
	cmp r1, #0x3f
	ble .L080F1928
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080F1928
.L080F1910:
	ldr r0, .L080F1920
	strh r4, [r0]
	ldr r3, .L080F1924
	adds r1, r6, r3
	movs r0, #3
	strh r0, [r1]
	bl .L080F20C6
.L080F1920: .4byte 0x030000AE @ IWRAM+0xAE
.L080F1924: .4byte 0x0000097E
.L080F1928:
	ldr r1, .L080F193C
	movs r0, #0
	strh r0, [r1]
	ldr r5, .L080F1940
	adds r1, r6, r5
	movs r0, #2
	strh r0, [r1]
	bl .L080F20C6
	.byte 0x00, 0x00
.L080F193C: .4byte 0x030000AE @ IWRAM+0xAE
.L080F1940: .4byte 0x0000097E
.L080F1944:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	bl sub_080EE864
	ldr r1, .L080F1960
	str r0, [r1, #0x18]
	cmp r0, #0
	bne .L080F1968
	ldr r0, .L080F1964
	adds r1, r6, r0
	b .L080F1B40
	.byte 0x00, 0x00
.L080F1960: .4byte 0x03000088 @ IWRAM+0x88
.L080F1964: .4byte 0x0000097E
.L080F1968:
	ldr r2, .L080F1970
	adds r1, r6, r2
	b .L080F1B50
	.byte 0x00, 0x00
.L080F1970: .4byte 0x0000097E
.L080F1974:
	mov r3, r8
	cmp r3, #8
	bne .L080F19C8
	adds r0, r7, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	str r0, [sp]
	adds r5, r0, #0
	cmp r5, #0xf8
	bne .L080F1998
	ldr r1, .L080F1994
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp]
	b .L080F19A2
	.byte 0x00, 0x00
.L080F1994: .4byte 0x00001194
.L080F1998:
	adds r0, r5, #0
	movs r1, #0xc
	mov r2, sp
	bl sub_080BF468
.L080F19A2:
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r1, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_080F3EF4
	ldr r0, .L080F19C4
	bl sub_080EE9F8
	adds r1, r5, #0
	adds r0, r4, #0
	bl sub_080F3EF4
	b .L080F1AD2
	.byte 0x00, 0x00
.L080F19C4: .4byte 0x03000088 @ IWRAM+0x88
.L080F19C8:
	ldr r4, .L080F19EC
	adds r0, r4, #0
	bl sub_080EE9F8
	adds r0, r7, #0
	adds r0, #0x5c
	ldrb r1, [r0]
	adds r2, r1, #0
	cmp r2, #0x5c
	beq .L080F19E0
	cmp r2, #0x61
	bne .L080F1A00
.L080F19E0:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq .L080F19F4
	ldr r2, .L080F19F0
	adds r1, r6, r2
	b .L080F1E3E
.L080F19EC: .4byte 0x03000088 @ IWRAM+0x88
.L080F19F0: .4byte 0x0000097E
.L080F19F4:
	ldr r3, .L080F19FC
	adds r1, r6, r3
	b .L080F1B40
	.byte 0x00, 0x00
.L080F19FC: .4byte 0x0000097E
.L080F1A00:
	adds r0, r1, #0
	subs r0, #0x66
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi .L080F1A76
	ldr r5, .L080F1A48
	adds r0, r6, r5
	movs r1, #7
	strh r1, [r0]
	ldr r0, [r4, #0xc]
	cmp r0, #1
	beq .L080F1A1C
	b .L080F20C6
.L080F1A1C:
	ldr r0, [r4, #4]
	bl sub_080EF0E4
	cmp r0, #0
	beq .L080F1A50
	ldr r0, .L080F1A4C
	bl Battle_GetMessage
	adds r4, r0, #0
	bl sub_080F3E44
	adds r1, r0, #0
	lsls r1, r1, #0x10
	adds r0, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F1FA0
	.byte 0x00, 0x00
.L080F1A48: .4byte 0x0000097E
.L080F1A4C: .4byte 0x00000171
.L080F1A50:
	ldr r4, [r4, #4]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	bl sub_080C08F8
	adds r0, r4, #0
	movs r1, #0
	bl sub_080F4054
	subs r0, r4, #4
	cmp r0, #0xb
	bhi .L080F1A70
	adds r0, r4, #0
	bl sub_080F4190
.L080F1A70:
	bl sub_080C366C
	b .L080F20C6
.L080F1A76:
	adds r0, r1, #0
	subs r0, #0x63
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi .L080F1AA0
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq .L080F1A94
	ldr r1, .L080F1A90
	movs r0, #1
	strh r0, [r1]
	b .L080F1E3A
.L080F1A90: .4byte 0x030000AE @ IWRAM+0xAE
.L080F1A94:
	ldr r2, .L080F1A9C
	adds r1, r6, r2
	b .L080F2040
	.byte 0x00, 0x00
.L080F1A9C: .4byte 0x0000097E
.L080F1AA0:
	adds r0, r1, #0
	subs r0, #0x54
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls .L080F1AB0
	cmp r2, #0x5e
	bne .L080F1AD2
.L080F1AB0:
	ldr r1, [r4, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080F1ABC
	b .L080F203C
.L080F1ABC:
	adds r0, r1, #0
	bl Battle_GetMessage
	ldr r1, [r4, #4]
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F203C
.L080F1AD2:
	ldr r2, .L080F1B2C
	ldr r1, [r2, #0x18]
	ldr r0, .L080F1B30
	cmp r1, r0
	bne .L080F1B38
	ldr r0, [r2, #8]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L080F1B0C
	ldr r5, [r2, #4]
	cmp r5, r1
	bne .L080F1AEE
	ldr r5, [r2]
.L080F1AEE:
	bl Battle_GetMessage
	adds r4, r0, #0
	bl sub_080F3E44
	adds r1, r0, #0
	lsls r1, r1, #0x10
	adds r1, r5, r1
	adds r0, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F1B0C:
	ldr r0, .L080F1B2C
	ldr r1, [r0, #0xc]
	cmp r1, #1
	bne .L080F1B24
	ldr r0, [sp]
	subs r0, #0x9e
	cmp r0, #1
	bhi .L080F1B24
	movs r5, #0xec
	lsls r5, r5, #4
	adds r0, r6, r5
	strb r1, [r0]
.L080F1B24:
	ldr r0, .L080F1B34
	adds r1, r6, r0
	b .L080F1E74
	.byte 0x00, 0x00
.L080F1B2C: .4byte 0x03000088 @ IWRAM+0x88
.L080F1B30: .4byte 0x0000FFFF
.L080F1B34: .4byte 0x0000097C
.L080F1B38:
	cmp r1, #0
	bne .L080F1B4C
	ldr r2, .L080F1B48
	adds r1, r6, r2
.L080F1B40:
	movs r0, #8
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F1B48: .4byte 0x0000097E
.L080F1B4C:
	ldr r3, .L080F1B58
	adds r1, r6, r3
.L080F1B50:
	movs r0, #4
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F1B58: .4byte 0x0000097E
.L080F1B5C:
	ldr r7, .L080F1BC0
	ldr r5, [r7, #4]
	ldr r1, [sp]
	adds r0, r7, #0
	bl sub_080EEB94
	str r0, [sp, #4]
	ldr r0, .L080F1BC4
	mov r8, r0
	ldr r1, .L080F1BC8
	mov sb, r1
	strh r1, [r0]
	ldr r0, [r7, #8]
	movs r2, #1
	rsbs r2, r2, #0
	mov sl, r2
	cmp r0, sl
	beq .L080F1B98
	bl Battle_GetMessage
	adds r1, r5, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	movs r0, #0
	mov r3, r8
	strh r0, [r3]
.L080F1B98:
	bl sub_080EDA90
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, sb
	bne .L080F1C04
	ldr r0, [r7, #4]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r4, #0
	beq .L080F1BD0
	ldr r5, .L080F1BCC
	adds r1, r6, r5
	movs r0, #0xa
	b .L080F1C2E
.L080F1BC0: .4byte 0x03000088 @ IWRAM+0x88
.L080F1BC4: .4byte 0x030000AC @ IWRAM+0xAC
.L080F1BC8: .4byte 0x0000FFFF
.L080F1BCC: .4byte 0x0000097C
.L080F1BD0:
	ldr r0, [sp, #4]
	cmp r0, #0
	bne .L080F1BE4
	ldr r2, .L080F1BE0
	adds r1, r6, r2
	movs r0, #8
	b .L080F1C2E
	.byte 0x00, 0x00
.L080F1BE0: .4byte 0x0000097E
.L080F1BE4:
	ldr r1, .L080F1BFC
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r3, .L080F1C00
	adds r1, r6, r3
	movs r0, #7
	strh r0, [r1]
	mov r5, r8
	strh r4, [r5]
	b .L080F1C30
	.byte 0x00, 0x00
.L080F1BFC: .4byte gUnknown_08124316
.L080F1C00: .4byte 0x0000097E
.L080F1C04:
	cmp r4, #0
	bne .L080F1C14
	ldr r0, .L080F1C10
	adds r1, r6, r0
	movs r0, #9
	b .L080F1C2E
.L080F1C10: .4byte 0x0000097E
.L080F1C14:
	ldr r0, [r7, #8]
	cmp r0, sl
	beq .L080F1C28
	ldr r2, .L080F1C24
	adds r1, r6, r2
	movs r0, #0xa
	b .L080F1C2E
	.byte 0x00, 0x00
.L080F1C24: .4byte 0x0000097E
.L080F1C28:
	ldr r3, .L080F1C40
	adds r1, r6, r3
	movs r0, #4
.L080F1C2E:
	strh r0, [r1]
.L080F1C30:
	ldr r0, .L080F1C44
	ldrh r1, [r0]
.L080F1C34:
	ldr r0, .L080F1C48
	cmp r1, r0
	bne .L080F1C3C
	b .L080F20C6
.L080F1C3C:
	b .L080F1FA0
	.byte 0x00, 0x00
.L080F1C40: .4byte 0x0000097E
.L080F1C44: .4byte 0x030000AC @ IWRAM+0xAC
.L080F1C48: .4byte 0x0000FFFF
.L080F1C4C:
	ldr r4, .L080F1C68
	adds r0, r4, #0
	bl sub_080EED88
	cmp r0, #0
	bne .L080F1C84
	ldr r0, .L080F1C6C
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #1
	bne .L080F1C74
	ldr r0, .L080F1C70
	adds r1, r6, r0
	b .L080F20A4
.L080F1C68: .4byte 0x03000088 @ IWRAM+0x88
.L080F1C6C: .4byte 0x030000AE @ IWRAM+0xAE
.L080F1C70: .4byte 0x0000097E
.L080F1C74:
	ldr r2, .L080F1C80
	adds r1, r6, r2
	movs r0, #5
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F1C80: .4byte 0x0000097E
.L080F1C84:
	ldr r1, [r4, #8]
	movs r0, #0xb7
	lsls r0, r0, #1
	cmp r1, r0
	bne .L080F1CB4
	bl sub_080F20E0
	ldr r3, .L080F1CAC
	adds r1, r6, r3
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #9
	bne .L080F1CA0
	b .L080F1FA0
.L080F1CA0:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	bne .L080F1CB0
	movs r0, #8
	b .L080F1F9E
	.byte 0x00, 0x00
.L080F1CAC: .4byte 0x0000097E
.L080F1CB0:
	movs r0, #0xa
	b .L080F1F9E
.L080F1CB4:
	ldr r0, .L080F1CB8
	b .L080F2094
.L080F1CB8: .4byte 0x0000097E
.L080F1CBC:
	ldr r4, .L080F1CF0
	ldr r0, [r4]
	bl sub_080EFE60
	adds r1, r0, #0
	ldr r0, [r4, #4]
	bl sub_080F3F90
	adds r5, r0, #0
	ldr r0, [r4, #4]
	cmp r0, #0xf
	bgt .L080F1D24
	bl sub_080F3F44
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	beq .L080F1CF4
	mov r1, r8
	cmp r1, #0xa
	bne .L080F1CF4
	movs r2, #0x12
	ldrsh r0, [r7, r2]
	b .L080F1D1E
	.byte 0x00, 0x00
.L080F1CF0: .4byte 0x03000088 @ IWRAM+0x88
.L080F1CF4:
	ldr r0, .L080F1D54
	ldr r0, [r0, #4]
	cmp r0, #0xf
	bgt .L080F1D24
	bl sub_080F3F44
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	beq .L080F1D24
	mov r0, r8
	ldr r1, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080EED64
	cmp r0, #1
	bne .L080F1D24
	movs r3, #0x12
	ldrsh r0, [r7, r3]
.L080F1D1E:
	cmp r0, #0xb1
	ble .L080F1D24
	movs r5, #0xd
.L080F1D24:
	ldr r4, .L080F1D54
	ldr r0, [r4, #0x18]
	adds r1, r5, #0
	bl sub_080EEEE8
	str r0, [r4, #0x18]
	mov r2, sb
	movs r3, #0x18
	ldrsh r1, [r2, r3]
	cmp r1, r0
	bge .L080F1D3C
	str r1, [r4, #0x18]
.L080F1D3C:
	ldr r1, .L080F1D58
	ldr r2, .L080F1D5C
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, r1, #0
	cmp r5, #0xf
	bhi .L080F1DFE
	lsls r0, r5, #2
	ldr r1, .L080F1D60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F1D54: .4byte 0x03000088 @ IWRAM+0x88
.L080F1D58: .4byte 0x030000AC @ IWRAM+0xAC
.L080F1D5C: .4byte 0x0000FFFF
.L080F1D60: .4byte gUnknown_080F1D64
	.global gUnknown_080F1D64
gUnknown_080F1D64:
.L080F1D64: @ jump table
	.4byte .L080F1DD4
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DE4
	.4byte .L080F1DE4
	.4byte .L080F1DA4
	.4byte .L080F1DA4
.L080F1DA4:
	ldr r5, .L080F1DDC
	ldr r0, [r5, #4]
	bl sub_080F401C
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r5, #4]
	bl sub_080F4038
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r1, [r5, #0x18]
	adds r1, r4, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble .L080F1DCC
	subs r0, r0, r4
	str r0, [r5, #0x18]
.L080F1DCC:
	ldr r0, [r5, #4]
	ldr r1, [r5, #0x18]
	bl sub_080C0AD4
.L080F1DD4:
	ldr r3, .L080F1DE0
	adds r1, r6, r3
	b .L080F2096
	.byte 0x00, 0x00
.L080F1DDC: .4byte 0x03000088 @ IWRAM+0x88
.L080F1DE0: .4byte 0x0000097E
.L080F1DE4:
	bl sub_080F20E0
	ldr r5, .L080F1E10
	adds r0, r6, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne .L080F1DF6
	b .L080F1FA0
.L080F1DF6:
	ldr r1, .L080F1E14
	movs r0, #0
	strh r0, [r1]
	adds r2, r1, #0
.L080F1DFE:
	ldr r0, .L080F1E18
	ldr r0, [r0, #0x18]
	cmp r0, #0
	bne .L080F1E1C
	ldr r3, .L080F1E10
	adds r1, r6, r3
	movs r0, #8
	b .L080F1E22
	.byte 0x00, 0x00
.L080F1E10: .4byte 0x0000097E
.L080F1E14: .4byte 0x030000AC @ IWRAM+0xAC
.L080F1E18: .4byte 0x03000088 @ IWRAM+0x88
.L080F1E1C:
	ldr r5, .L080F1E28
	adds r1, r6, r5
	movs r0, #0xa
.L080F1E22:
	strh r0, [r1]
	ldrh r1, [r2]
	b .L080F1C34
.L080F1E28: .4byte 0x0000097E
.L080F1E2C:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080F1E3A
	b .L080F20C6
.L080F1E3A:
	ldr r0, .L080F1E44
	adds r1, r6, r0
.L080F1E3E:
	movs r0, #0xc
	strh r0, [r1]
	b .L080F20C6
.L080F1E44: .4byte 0x0000097E
.L080F1E48:
	ldr r1, .L080F1E5C
	adds r4, r6, r1
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080F1E84
	cmp r0, #1
	bne .L080F1E64
	ldr r1, .L080F1E60
	b .L080F1E66
	.byte 0x00, 0x00
.L080F1E5C: .4byte 0x000011B0
.L080F1E60: .4byte gUnknown_081242EC
.L080F1E64:
	ldr r1, .L080F1E7C
.L080F1E66:
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	movs r0, #0
	strh r0, [r4]
	ldr r2, .L080F1E80
	adds r1, r6, r2
.L080F1E74:
	movs r0, #0xb
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F1E7C: .4byte gUnknown_081242FC
.L080F1E80: .4byte 0x0000097E
.L080F1E84:
	ldr r5, .L080F1EA8
	ldr r0, [r5, #4]
	bl sub_080F401C
	cmp r0, #0
	ble .L080F1EA0
	ldr r0, [r5, #4]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L080F1EB0
.L080F1EA0:
	ldr r3, .L080F1EAC
	adds r1, r6, r3
	b .L080F20A4
	.byte 0x00, 0x00
.L080F1EA8: .4byte 0x03000088 @ IWRAM+0x88
.L080F1EAC: .4byte 0x0000097C
.L080F1EB0:
	bl sub_080F22B4
	bl sub_080EDA90
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L080F1F98
	ldr r0, .L080F1EF0
	cmp r4, r0
	beq .L080F1F98
	bl sub_080EDAD0
	cmp r0, #0
	beq .L080F1F14
	ldr r0, .L080F1EF4
	ands r0, r4
	cmp r0, #0
	beq .L080F1F14
	ldr r1, [r5, #4]
	cmp r1, #0xf
	ble .L080F1F14
	ldr r0, .L080F1EF8
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #1
	bne .L080F1F00
	ldr r0, .L080F1EFC
	adds r1, r6, r0
	movs r0, #9
	b .L080F1F9E
	.byte 0x00, 0x00
.L080F1EF0: .4byte 0x0000FFFF
.L080F1EF4: .4byte 0x00003204
.L080F1EF8: .4byte 0x030000AE @ IWRAM+0xAE
.L080F1EFC: .4byte 0x0000097E
.L080F1F00:
	adds r0, r1, #0
	bl sub_080F401C
	cmp r0, #0
	bgt .L080F1F98
	ldr r2, .L080F1F10
	adds r1, r6, r2
	b .L080F1F9C
.L080F1F10: .4byte 0x0000097E
.L080F1F14:
	ldr r5, .L080F1F34
	ldr r0, [r5, #4]
	adds r1, r4, #0
	bl sub_080C08E8
	ldr r0, [r5, #4]
	bl sub_080F401C
	cmp r0, #0
	bgt .L080F1F3C
	ldr r5, .L080F1F38
	adds r1, r6, r5
	movs r0, #7
	strh r0, [r1]
	b .L080F1F76
	.byte 0x00, 0x00
.L080F1F34: .4byte 0x03000088 @ IWRAM+0x88
.L080F1F38: .4byte 0x0000097E
.L080F1F3C:
	ldr r0, .L080F1F68
	adds r1, r6, r0
	movs r0, #6
	strh r0, [r1]
	ldr r0, [r5, #4]
	cmp r0, #0xf
	bgt .L080F1F6C
	bl sub_080BFFC4
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	adds r0, r5, #0
	bl sub_080C86B4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x12
	bgt .L080F1F76
	adds r0, r5, #0
	bl sub_080C8490
	b .L080F1F76
.L080F1F68: .4byte 0x0000097E
.L080F1F6C:
	movs r2, #0xec
	lsls r2, r2, #4
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
.L080F1F76:
	movs r0, #0x80
	lsls r0, r0, #6
	cmp r4, r0
	bne .L080F1FA0
	ldr r0, .L080F1F94
	ldr r1, [r0, #4]
	subs r0, r1, #4
	cmp r0, #0xb
	bhi .L080F1FA0
	adds r0, r1, #0
	bl sub_080F4190
	bl sub_080C366C
	b .L080F1FA0
.L080F1F94: .4byte 0x03000088 @ IWRAM+0x88
.L080F1F98:
	ldr r3, .L080F1FAC
	adds r1, r6, r3
.L080F1F9C:
	movs r0, #7
.L080F1F9E:
	strh r0, [r1]
.L080F1FA0:
	movs r0, #4
	movs r1, #0xd
	bl sub_080F0344
	b .L080F20C6
	.byte 0x00, 0x00
.L080F1FAC: .4byte 0x0000097E
.L080F1FB0:
	ldr r4, .L080F1FC8
	ldr r0, [r4, #4]
	bl sub_080F3110
	cmp r0, #1
	bne .L080F1FD0
	ldr r1, .L080F1FCC
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F1FEC
	.byte 0x00, 0x00
.L080F1FC8: .4byte 0x03000088 @ IWRAM+0x88
.L080F1FCC: .4byte gUnknown_08124218
.L080F1FD0:
	ldr r0, [r4, #4]
	ldr r5, .L080F1FF4
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r1, .L080F1FF8
	bl Battle_BuildActorStatusText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F1FEC:
	ldr r0, .L080F1FFC
	adds r1, r6, r0
	b .L080F2040
	.byte 0x00, 0x00
.L080F1FF4: .4byte 0xFFFF8000
.L080F1FF8: .4byte gUnknown_08124234
.L080F1FFC: .4byte 0x0000097E
.L080F2000:
	ldr r4, .L080F202C
	ldr r0, [r4, #4]
	bl sub_080F3110
	movs r1, #0xaa
	lsls r1, r1, #1
	cmp r0, #1
	bne .L080F2012
	subs r1, #1
.L080F2012:
	adds r0, r1, #0
	bl Battle_GetMessage
	ldr r1, [r4, #4]
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r2, .L080F2030
	adds r1, r6, r2
	b .L080F2040
.L080F202C: .4byte 0x03000088 @ IWRAM+0x88
.L080F2030: .4byte 0x0000097E
.L080F2034:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	bl sub_080F2AC8
.L080F203C:
	ldr r3, .L080F2048
	adds r1, r6, r3
.L080F2040:
	movs r0, #7
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F2048: .4byte 0x0000097E
.L080F204C:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F20C6
	ldr r4, .L080F2070
	ldr r0, [r4, #4]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	cmp r1, #0
	beq .L080F2078
	ldr r5, .L080F2074
	adds r1, r6, r5
	b .L080F20A4
.L080F2070: .4byte 0x03000088 @ IWRAM+0x88
.L080F2074: .4byte 0x0000097C
.L080F2078:
	ldr r0, [r4, #4]
	bl sub_080F401C
	cmp r0, #0
	ble .L080F2092
	ldr r0, [r4, #4]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L080F20A0
.L080F2092:
	ldr r0, .L080F209C
.L080F2094:
	adds r1, r6, r0
.L080F2096:
	movs r0, #9
	strh r0, [r1]
	b .L080F20C6
.L080F209C: .4byte 0x0000097C
.L080F20A0:
	ldr r2, .L080F20AC
	adds r1, r6, r2
.L080F20A4:
	movs r0, #0xa
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F20AC: .4byte 0x0000097C
.L080F20B0:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F20C6
	ldr r0, .L080F20D8
	ldrh r1, [r0]
	ldr r3, .L080F20DC
	adds r0, r6, r3
	strh r1, [r0]
.L080F20C6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F20D8: .4byte 0x030000AC @ IWRAM+0xAC
.L080F20DC: .4byte 0x0000097E

	thumb_func_start sub_080F20E0
sub_080F20E0: @ 0x080F20E0
.L080F20E0:
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r4, .L080F2108
	ldr r0, [r4, #4]
	bl sub_080F3110
	cmp r0, #0
	bne .L080F2110
	ldr r0, [r4, #4]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r0, r1
	ldr r1, .L080F210C
	bl Battle_BuildNamePrependText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F2118
.L080F2108: .4byte 0x03000088 @ IWRAM+0x88
.L080F210C: .4byte gUnknown_081241F0
.L080F2110:
	ldr r1, .L080F2188
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F2118:
	ldr r5, .L080F218C
	ldr r0, [r5]
	str r0, [r5, #4]
	bl sub_080EDA90
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r6, r4, #0
	cmp r4, #0
	beq .L080F215E
	ldr r0, .L080F2190
	cmp r4, r0
	beq .L080F215E
	bl sub_080EDA7C
	ldr r0, [r5, #4]
	adds r1, r4, #0
	bl sub_080F3214
	cmp r0, #0
	beq .L080F215E
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq .L080F2158
	ldrh r0, [r5, #4]
	bl sub_080C0148
	movs r2, #0x1e
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq .L080F215E
.L080F2158:
	adds r0, r6, #0
	bl sub_080EDA7C
.L080F215E:
	ldr r6, .L080F2194
	ldr r5, .L080F218C
	ldr r0, [r5]
	bl sub_080C35E4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	ldr r2, .L080F2198
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080F217A
	cmp r1, #0xa
	bne .L080F219C
.L080F217A:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	bl sub_080EE864
	str r0, [r5, #0x18]
	b .L080F21E0
	.byte 0x00, 0x00
.L080F2188: .4byte gUnknown_08124200
.L080F218C: .4byte 0x03000088 @ IWRAM+0x88
.L080F2190: .4byte 0x0000FFFF
.L080F2194: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2198: .4byte 0xFFFC0000
.L080F219C:
	cmp r1, #8
	bne .L080F21D2
	ldr r0, [r5]
	bl sub_080F3F14
	adds r4, r0, #0
	str r4, [sp]
	movs r1, #0xc
	mov r2, sp
	bl sub_080BF468
	ldr r0, [r5]
	ldr r1, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080F3EF4
	adds r0, r5, #0
	bl sub_080EE9F8
	ldr r0, [r5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
	bl sub_080F3EF4
	b .L080F21E0
.L080F21D2:
	cmp r1, #7
	beq .L080F21DA
	cmp r1, #0xb
	bne .L080F21E0
.L080F21DA:
	adds r0, r5, #0
	bl sub_080EE9F8
.L080F21E0:
	ldr r4, .L080F2224
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq .L080F22A4
	ldr r0, [r4]
	bl sub_080EFE60
	adds r1, r0, #0
	ldr r0, [r4, #4]
	bl sub_080F3F90
	adds r5, r0, #0
	ldr r0, [r4, #0x18]
	adds r1, r5, #0
	bl sub_080EEEE8
	str r0, [r4, #0x18]
	ldr r0, [r4, #4]
	bl sub_080F401C
	ldr r1, [r4, #0x18]
	cmp r0, r1
	bge .L080F2216
	ldr r0, [r4, #4]
	bl sub_080F401C
	str r0, [r4, #0x18]
.L080F2216:
	cmp r5, #0xf
	bhi .L080F22A4
	lsls r0, r5, #2
	ldr r1, .L080F2228
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F2224: .4byte 0x03000088 @ IWRAM+0x88
.L080F2228: .4byte gUnknown_080F222C
	.global gUnknown_080F222C
gUnknown_080F222C:
.L080F222C: @ jump table
	.4byte .L080F229C
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F226C
	.4byte .L080F226C
.L080F226C:
	ldr r5, .L080F22AC
	ldr r0, [r5, #4]
	bl sub_080F401C
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r5, #4]
	bl sub_080F4038
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r1, [r5, #0x18]
	adds r1, r4, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble .L080F2294
	subs r0, r0, r4
	str r0, [r5, #0x18]
.L080F2294:
	ldr r0, [r5, #4]
	ldr r1, [r5, #0x18]
	bl sub_080C0AD4
.L080F229C:
	ldr r0, .L080F22B0
	adds r1, r6, r0
	movs r0, #9
	strh r0, [r1]
.L080F22A4:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080F22AC: .4byte 0x03000088 @ IWRAM+0x88
.L080F22B0: .4byte 0x0000097E

	thumb_func_start sub_080F22B4
sub_080F22B4: @ 0x080F22B4
.L080F22B4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, .L080F231C
	mov sl, r0
	ldr r4, .L080F2320
	ldrh r7, [r4, #4]
	ldr r0, .L080F2324
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L080F2372
	bl sub_080EDA90
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r8, r0
	bne .L080F236C
	bl sub_080EDAD0
	cmp r0, #0
	beq .L080F2358
	lsls r0, r7, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0xf
	ble .L080F2358
	ldr r0, [r4]
	bl sub_080EFE60
	adds r5, r0, #0
	ldr r0, [r4, #4]
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080ED494
	cmp r0, #0x3f
	bne .L080F2328
	cmp r5, #7
	bne .L080F2328
	adds r0, r6, #0
	bl sub_080F401C
	str r0, [r4, #0x18]
	ldr r0, [r4, #4]
	b .L080F2342
.L080F231C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2320: .4byte 0x03000088 @ IWRAM+0x88
.L080F2324: .4byte 0x030000AE @ IWRAM+0xAE
.L080F2328:
	cmp r0, #0x3e
	beq .L080F232E
	b .L080F24DA
.L080F232E:
	cmp r5, #8
	beq .L080F2334
	b .L080F24DA
.L080F2334:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	bl sub_080F401C
	ldr r1, .L080F2354
	str r0, [r1, #0x18]
	ldr r0, [r1, #4]
.L080F2342:
	movs r1, #0x80
	lsls r1, r1, #8
	bl sub_080C08E8
	movs r0, #0
	bl sub_080EDA7C
	b .L080F2372
	.byte 0x00, 0x00
.L080F2354: .4byte 0x03000088 @ IWRAM+0x88
.L080F2358:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	bl sub_080F401C
	ldr r1, .L080F2368
	str r0, [r1, #0x18]
	b .L080F2372
	.byte 0x00, 0x00
.L080F2368: .4byte 0x03000088 @ IWRAM+0x88
.L080F236C:
	movs r0, #0
	str r0, [r4, #0x18]
	b .L080F24DA
.L080F2372:
	lsls r4, r7, #0x10
	asrs r5, r4, #0x10
	adds r0, r5, #0
	bl sub_080F3110
	mov sb, r4
	cmp r0, #1
	bne .L080F23BC
	bl sub_080ED954
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	bl sub_080ED974
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, #1
	bne .L080F23A6
	cmp r0, #1
	bne .L080F23A6
	movs r0, #1
	bl sub_080E8AFC
	b .L080F23AC
.L080F23A6:
	movs r0, #0
	bl sub_080E8AFC
.L080F23AC:
	ldr r1, .L080F23B8
	add r1, sl
	movs r0, #0x96
	lsls r0, r0, #1
	b .L080F23FC
	.byte 0x00, 0x00
.L080F23B8: .4byte 0x00000ECA
.L080F23BC:
	adds r0, r5, #0
	bl sub_080BFFC4
	movs r1, #0
	ldr r0, .L080F24A4
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r2, r0, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, r5
	beq .L080F23EC
	adds r4, r5, #0
.L080F23D6:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #5
	bhi .L080F23EC
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r4
	bne .L080F23D6
.L080F23EC:
	cmp r1, #6
	beq .L080F23F6
	adds r0, r1, #0
	bl sub_080C86F4
.L080F23F6:
	ldr r1, .L080F24A8
	add r1, sl
	ldr r0, .L080F24AC
.L080F23FC:
	strh r0, [r1]
	ldr r0, .L080F24A8
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_080ECF70
	ldr r6, .L080F24B0
	ldr r3, [r6, #0x18]
	mov r8, r3
	movs r7, #0
	mov r0, sb
	asrs r5, r0, #0x10
	adds r0, r5, #0
	bl sub_080F401C
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080F4038
	cmp r4, r0
	ble .L080F242A
	movs r7, #1
.L080F242A:
	ldr r1, [r6, #0x18]
	rsbs r1, r1, #0
	adds r0, r5, #0
	bl sub_080F24F0
	adds r0, r5, #0
	bl sub_080F401C
	cmp r0, #0
	bge .L080F2452
	adds r0, r5, #0
	bl sub_080F401C
	ldr r1, [r6, #0x18]
	adds r1, r1, r0
	str r1, [r6, #0x18]
	adds r0, r5, #0
	movs r1, #0
	bl sub_080F4054
.L080F2452:
	cmp r7, #0
	bne .L080F2476
	adds r0, r5, #0
	bl sub_080F401C
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080F4038
	cmp r4, r0
	ble .L080F2476
	adds r0, r5, #0
	bl sub_080F4038
	adds r1, r0, #0
	adds r0, r5, #0
	bl sub_080F4054
.L080F2476:
	ldr r4, .L080F24B0
	ldr r0, [r4, #4]
	bl sub_080F3110
	cmp r0, #1
	bne .L080F24BC
	ldr r0, [r4, #4]
	ldr r1, .L080F24B4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r2, .L080F24B8
	mov r1, r8
	bl Battle_BuildDamageDealtText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F24DA
	.byte 0x00, 0x00
.L080F24A4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F24A8: .4byte 0x00000ECA
.L080F24AC: .4byte 0x0000012B
.L080F24B0: .4byte 0x03000088 @ IWRAM+0x88
.L080F24B4: .4byte 0xFFFF8000
.L080F24B8: .4byte gUnknown_08123BCC
.L080F24BC:
	ldr r0, [r4, #4]
	ldr r3, .L080F24E8
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r2, .L080F24EC
	mov r1, r8
	bl Battle_BuildDamageDealtText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F24DA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F24E8: .4byte 0xFFFF8000
.L080F24EC: .4byte gUnknown_0812310C

	thumb_func_start sub_080F24F0
sub_080F24F0: @ 0x080F24F0
.L080F24F0:
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080F2510
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r1, [r0, #0x18]
	adds r1, r1, r4
	strh r1, [r0, #0x18]
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	pop {r4}
	pop {r1}
	bx r1
.L080F2510: .4byte 0xFFFF8000

	thumb_func_start sub_080F2514
sub_080F2514: @ 0x080F2514
.L080F2514:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	lsls r1, r1, #0x10
	ldr r0, .L080F2570
	mov r8, r0
	lsrs r4, r1, #0x10
	asrs r5, r1, #0x10
	adds r0, r5, #0
	bl sub_080F3F14
	str r0, [sp]
	adds r0, r5, #0
	bl sub_080C35E4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, .L080F2574
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl sub_080EFFF8
	adds r0, r5, #0
	bl sub_080F3110
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r7, #8
	bne .L080F2586
	adds r0, r5, #0
	bl sub_080F3F14
	cmp r0, #0xf0
	bne .L080F257C
	ldr r0, .L080F2578
	add r0, r8
	ldrh r0, [r0]
	str r0, [sp]
	b .L080F2586
.L080F2570: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2574: .4byte 0x00000F66
.L080F2578: .4byte 0x00001192
.L080F257C:
	ldr r0, [sp]
	movs r1, #0xc
	mov r2, sp
	bl sub_080BF468
.L080F2586:
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r5, [r0, #2]
	lsls r4, r4, #0x10
	asrs r6, r4, #0x10
	ldr r0, .L080F25C4
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl sub_080EFFF8
	cmp r5, #0x80
	beq .L080F25AC
	cmp r5, #0x82
	bne .L080F25CC
.L080F25AC:
	ldr r2, .L080F25C8
	str r6, [r2]
	lsls r1, r6, #1
	movs r0, #0xf3
	lsls r0, r0, #4
	add r0, r8
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r2, #4]
	lsls r7, r7, #0x10
	b .L080F2626
.L080F25C4: .4byte 0x00000F66
.L080F25C8: .4byte 0x03000088 @ IWRAM+0x88
.L080F25CC:
	ldr r5, .L080F2670
	str r6, [r5]
	mov r2, sb
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #4
	str r0, [r5, #4]
	ldr r0, [sp]
	subs r0, #0x2b
	lsls r7, r7, #0x10
	cmp r0, #0xd
	bhi .L080F2626
	cmp r1, #0
	beq .L080F2626
	movs r0, #0x10
	str r0, [r5, #4]
	bl sub_080ED954
	cmp r0, #1
	bne .L080F2626
	ldr r0, [r5]
	cmp r0, #0x13
	ble .L080F2626
	movs r6, #0
	movs r5, #0x10
.L080F2602:
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F2612
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080F2612:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x13
	bls .L080F2602
	cmp r6, #0
	bne .L080F2626
	ldr r1, .L080F2670
	movs r0, #0x14
	str r0, [r1, #4]
.L080F2626:
	asrs r0, r7, #0x10
	cmp r0, #8
	bne .L080F2646
	asrs r0, r4, #0x10
	bl sub_080F3F14
	cmp r0, #0xf0
	bne .L080F2646
	ldr r0, [sp]
	subs r0, #0x2b
	cmp r0, #1
	bhi .L080F2646
	ldr r1, .L080F2670
	mov r2, sl
	ldrb r0, [r2, #0xc]
	str r0, [r1, #4]
.L080F2646:
	ldr r5, .L080F2670
	ldr r0, [r5, #4]
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r1, [sp]
	adds r0, r5, #0
	bl sub_080F4988
	ldr r1, [sp]
	adds r0, r1, #0
	subs r0, #0x3e
	cmp r0, #1
	bhi .L080F26BC
	cmp r1, #0x3e
	bne .L080F2674
	asrs r0, r4, #0x10
	movs r1, #1
	b .L080F2678
	.byte 0x00, 0x00
.L080F2670: .4byte 0x03000088 @ IWRAM+0x88
.L080F2674:
	asrs r0, r4, #0x10
	movs r1, #3
.L080F2678:
	bl sub_080F1678
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0xe9
	bl Battle_GetMessage
	ldr r1, .L080F26B4
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r1, r2
	adds r1, r4, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, .L080F26B8
	add r1, r8
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
	b .L080F27B8
.L080F26B4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F26B8: .4byte 0x0000097C
.L080F26BC:
	ldr r0, [r5, #0xc]
	cmp r0, #1
	bne .L080F2774
	ldr r2, [r5, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L080F26FC
	subs r1, #0x1d
	ldr r0, .L080F26F0
	lsls r1, r1, #0x11
	asrs r1, r1, #0xf
	adds r1, r1, r0
	mov r2, sb
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L080F26F4
	cmp r4, r0
	beq .L080F272C
	ldr r0, .L080F26F8
	ands r4, r0
	b .L080F2700
.L080F26F0: .4byte gUnknown_0876F9CC
.L080F26F4: .4byte 0x0000FFFF
.L080F26F8: .4byte 0x00007FFF
.L080F26FC:
	lsls r0, r2, #0x10
	lsrs r4, r0, #0x10
.L080F2700:
	ldr r0, .L080F2768
	cmp r4, r0
	beq .L080F272C
	adds r0, r4, #0
	bl Battle_GetMessage
	ldr r1, .L080F276C
	ldr r1, [r1, #4]
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, .L080F2770
	add r1, r8
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
.L080F272C:
	ldr r1, .L080F2770
	add r1, r8
	movs r0, #0xa
	strh r0, [r1]
	ldr r4, .L080F276C
	ldr r0, [r4, #4]
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r6, r0
	beq .L080F27B8
	ldr r0, [r4, #4]
	cmp r0, #0xf
	bgt .L080F27B8
	bl sub_080BFFC4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080C86B4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x12
	bgt .L080F27B8
	adds r0, r4, #0
	bl sub_080C8490
	b .L080F27B8
.L080F2768: .4byte 0x0000FFFF
.L080F276C: .4byte 0x03000088 @ IWRAM+0x88
.L080F2770: .4byte 0x0000097C
.L080F2774:
	ldr r1, [r5, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080F2794
	ldr r0, .L080F2790
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F27A8
.L080F2790: .4byte gUnknown_08124534
.L080F2794:
	adds r0, r1, #0
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F27A8:
	ldr r1, .L080F27C8
	add r1, r8
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
.L080F27B8:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F27C8: .4byte 0x0000097C

	thumb_func_start sub_080F27CC
sub_080F27CC: @ 0x080F27CC
.L080F27CC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r1, r1, #0x10
	ldr r7, .L080F282C
	lsrs r6, r1, #0x10
	asrs r5, r1, #0x10
	adds r0, r5, #0
	bl sub_080F3F14
	str r0, [sp]
	mov r0, sp
	ldrh r0, [r0]
	bl Action_GetRecord
	ldrb r4, [r0, #3]
	adds r0, r5, #0
	bl sub_080F3110
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, #0x80
	beq .L080F2804
	cmp r4, #0x82
	beq .L080F2804
	cmp r4, #0x83
	bne .L080F2834
.L080F2804:
	ldr r2, .L080F2830
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	str r1, [r2]
	lsls r1, r1, #1
	movs r3, #0xf3
	lsls r3, r3, #4
	adds r0, r7, r3
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r2, #4]
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	b .L080F2844
	.byte 0x00, 0x00
.L080F282C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2830: .4byte 0x03000088 @ IWRAM+0x88
.L080F2834:
	ldr r2, .L080F28B4
	str r5, [r2]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #4
	str r0, [r2, #4]
.L080F2844:
	ldr r5, .L080F28B4
	ldr r0, [r5, #4]
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [sp]
	subs r0, #0xf1
	cmp r0, #1
	bhi .L080F287C
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	str r0, [r5]
	ldr r0, .L080F28B8
	ldr r1, [r0]
	ldr r2, .L080F28BC
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [r5, #4]
.L080F287C:
	adds r0, r5, #0
	ldr r1, [sp]
	bl sub_080F5C90
	ldr r1, [sp]
	adds r0, r1, #0
	subs r0, #0xf1
	cmp r0, #1
	bhi .L080F2960
	ldr r0, [r5, #0xc]
	cmp r0, #1
	bne .L080F28C4
	ldr r0, .L080F28C0
	bl Battle_GetMessage
	adds r4, r0, #0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	bl sub_080F3F14
	lsls r0, r0, #0x10
	ldr r1, [r5, #4]
	adds r1, r1, r0
	adds r0, r4, #0
	bl Menu_ExpandListTemplate
	b .L080F291E
	.byte 0x00, 0x00
.L080F28B4: .4byte 0x03000088 @ IWRAM+0x88
.L080F28B8: .4byte 0x03006434 @ IWRAM+0x6434
.L080F28BC: .4byte 0x00000F66
.L080F28C0: .4byte 0x00000123
.L080F28C4:
	cmp r0, #2
	bne .L080F2950
	movs r2, #0
	ldr r0, .L080F2938
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r3, r0, r1
	movs r1, #0
	ldrsb r1, [r3, r1]
	ldr r0, [r5, #4]
	cmp r1, r0
	beq .L080F28F6
	adds r4, r3, #0
	adds r3, r5, #0
.L080F28E0:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #5
	bhi .L080F28F6
	adds r0, r2, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r0, [r3, #4]
	cmp r1, r0
	bne .L080F28E0
.L080F28F6:
	cmp r2, #6
	beq .L080F2900
	adds r0, r2, #0
	bl sub_080C86F4
.L080F2900:
	ldr r0, .L080F293C
	bl sub_080ECF70
	ldr r4, .L080F2940
	ldr r0, [r4, #4]
	ldr r2, .L080F2944
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r1, [r4, #0x18]
	ldr r2, .L080F2948
	bl Battle_BuildDamageDealtText
.L080F291E:
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r3, .L080F294C
	adds r1, r7, r3
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
	b .L080F2AB8
.L080F2938: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F293C: .4byte 0x0000012B
.L080F2940: .4byte 0x03000088 @ IWRAM+0x88
.L080F2944: .4byte 0xFFFF8000
.L080F2948: .4byte gUnknown_0812310C
.L080F294C: .4byte 0x0000097C
.L080F2950:
	ldr r0, .L080F295C
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	b .L080F2AB8
	.byte 0x00, 0x00
.L080F295C: .4byte 0x0000097C
.L080F2960:
	ldr r0, [r5, #0xc]
	cmp r0, #1
	beq .L080F2968
	b .L080F2A74
.L080F2968:
	adds r0, r1, #0
	bl sub_080F3E38
	ldr r0, [sp]
	movs r1, #0xc
	mov r2, sp
	bl sub_080BF468
	ldr r1, [r5, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080F29B0
	ldr r0, [sp]
	subs r0, #0x80
	ldr r1, .L080F29A4
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, .L080F29A8
	cmp r4, r0
	bne .L080F29F0
	bl sub_080ED9F4
	cmp r0, #0
	beq .L080F29B4
	ldr r4, .L080F29AC
	b .L080F29B4
	.byte 0x00, 0x00
.L080F29A4: .4byte gUnknown_0876FAE4
.L080F29A8: .4byte 0x00000137
.L080F29AC: .4byte 0x0000FFFF
.L080F29B0:
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
.L080F29B4:
	ldr r0, .L080F29E4
	cmp r4, r0
	bne .L080F29F0
	adds r0, r4, #0
	bl Battle_GetMessage
	ldr r1, .L080F29E8
	ldr r1, [r1, #4]
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r2, .L080F29EC
	adds r1, r7, r2
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
	b .L080F2A2C
	.byte 0x00, 0x00
.L080F29E4: .4byte 0x00000137
.L080F29E8: .4byte 0x03000088 @ IWRAM+0x88
.L080F29EC: .4byte 0x0000097C
.L080F29F0:
	ldr r0, .L080F2A68
	cmp r4, r0
	beq .L080F2A2C
	adds r0, r4, #0
	bl Battle_GetMessage
	adds r4, r0, #0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	bl sub_080F3F14
	ldr r1, .L080F2A6C
	lsls r0, r0, #0x10
	ldr r1, [r1, #4]
	adds r1, r1, r0
	adds r0, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r3, .L080F2A70
	adds r1, r7, r3
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
.L080F2A2C:
	ldr r0, .L080F2A70
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	ldr r4, .L080F2A6C
	ldr r0, [r4, #4]
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r8, r0
	beq .L080F2AB8
	ldr r0, [r4, #4]
	cmp r0, #0xf
	bgt .L080F2AB8
	bl sub_080BFFC4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080C86B4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x12
	bgt .L080F2AB8
	adds r0, r4, #0
	bl sub_080C8490
	b .L080F2AB8
.L080F2A68: .4byte 0x0000FFFF
.L080F2A6C: .4byte 0x03000088 @ IWRAM+0x88
.L080F2A70: .4byte 0x0000097C
.L080F2A74:
	ldr r1, [r5, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080F2A94
	ldr r0, .L080F2A90
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F2AA8
.L080F2A90: .4byte gUnknown_08124534
.L080F2A94:
	adds r0, r1, #0
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F2AA8:
	ldr r2, .L080F2AC4
	adds r1, r7, r2
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
.L080F2AB8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F2AC4: .4byte 0x0000097C
