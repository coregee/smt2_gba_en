	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_0814A414
sub_0814A414: @ 0x0814A414
.L0814A414:
	push {r4, r5, r6, lr}
	ldr r5, .L0814A440
	ldr r0, .L0814A444
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L0814A49C
	ldr r0, .L0814A448
	bl sub_080C51D4
	ldr r0, .L0814A44C
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0814A450
	ldr r0, [r5, #0x2c]
	bl sub_0814A36C
	b .L0814A452
	.byte 0x00, 0x00
.L0814A440: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814A444: .4byte 0x030031BC @ IWRAM+0x31BC
.L0814A448: .4byte 0x00000159
.L0814A44C: .4byte 0x03003964 @ IWRAM+0x3964
.L0814A450:
	movs r0, #5
.L0814A452:
	str r0, [r5, #0x38]
	ldr r0, [r5, #0x2c]
	ldr r2, [r5, #0x38]
	subs r0, r0, r2
	str r0, [r5, #0x2c]
	ldr r1, [r5, #0x28]
	adds r1, r1, r2
	str r1, [r5, #0x28]
	cmp r0, #0
	bgt .L0814A49C
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x30]
	adds r0, r0, r1
	str r0, [r5, #0x28]
	movs r4, #0
	str r4, [r5, #0x30]
	strh r4, [r5, #0xc]
	ldr r3, .L0814A4A4
	adds r6, r5, #0
	adds r6, #0x46
	ldrh r0, [r6]
	lsls r0, r0, #2
	ldr r2, .L0814A4A8
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r1, #0x2c
	muls r1, r2, r1
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0]
	bl sub_080C3328
	strh r4, [r6]
	movs r0, #0x63
	strb r0, [r5, #0x1a]
	movs r0, #7
	strb r0, [r5, #4]
.L0814A49C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814A4A4: .4byte gUnknown_0879E2A4
.L0814A4A8: .4byte 0x00000262

	thumb_func_start sub_0814A4AC
sub_0814A4AC: @ 0x0814A4AC
.L0814A4AC:
	push {r4, lr}
	ldr r4, .L0814A4D8
	bl sub_080C2244
	movs r1, #5
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x54
	strh r0, [r1]
	ldrh r2, [r4, #0x12]
	ldrh r0, [r1]
	adds r0, r2, r0
	cmp r0, #9
	ble .L0814A4CA
	subs r0, #0xa
.L0814A4CA:
	strh r0, [r4, #0x12]
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
	pop {r4}
	pop {r0}
	bx r0
.L0814A4D8: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0814A4DC
sub_0814A4DC: @ 0x0814A4DC
.L0814A4DC:
	push {r4, lr}
	sub sp, #0xc
	ldr r4, .L0814A508
	adds r0, r4, #0
	adds r0, #0x26
	movs r3, #0
	strb r3, [r0]
	ldrh r2, [r4, #0x1c]
	cmp r2, #3
	bhi .L0814A510
	ldr r0, .L0814A50C
	str r3, [sp]
	movs r1, #0xba
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	bl Sprite_Draw
	b .L0814A55A
	.byte 0x00, 0x00
.L0814A508: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814A50C: .4byte gUnknown_0814F970
.L0814A510:
	ldrh r1, [r4, #0x20]
	subs r0, r1, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814A524
	ldr r0, .L0814A520
	b .L0814A532
.L0814A520: .4byte gUnknown_0814F988
.L0814A524:
	cmp r2, #6
	bls .L0814A54C
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bhi .L0814A54C
	ldr r0, .L0814A548
.L0814A532:
	str r3, [sp]
	movs r1, #0xba
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814A55A
.L0814A548: .4byte gUnknown_0814F9A0
.L0814A54C:
	ldrh r0, [r4, #0x1c]
	cmp r0, #9
	bls .L0814A55A
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
.L0814A55A:
	ldrh r0, [r4, #0x20]
	adds r0, #1
	strh r0, [r4, #0x20]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0814A568
sub_0814A568: @ 0x0814A568
.L0814A568:
	push {r4, lr}
	sub sp, #0xc
	ldr r4, .L0814A590
	adds r0, r4, #0
	adds r0, #0x27
	movs r2, #0
	strb r2, [r0]
	ldrh r1, [r4, #0x1e]
	adds r3, r1, #0
	cmp r3, #3
	bhi .L0814A598
	ldr r0, .L0814A594
	str r2, [sp]
	movs r1, #7
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #1
	b .L0814A5C6
	.byte 0x00, 0x00
.L0814A590: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814A594: .4byte gUnknown_0814F970
.L0814A598:
	subs r0, r1, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814A5AC
	ldr r0, .L0814A5A8
	b .L0814A5B8
	.byte 0x00, 0x00
.L0814A5A8: .4byte gUnknown_0814F988
.L0814A5AC:
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814A5D4
	ldr r0, .L0814A5D0
.L0814A5B8:
	str r2, [sp]
	movs r1, #7
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
.L0814A5C6:
	movs r3, #0
	bl Sprite_Draw
	b .L0814A5E0
	.byte 0x00, 0x00
.L0814A5D0: .4byte gUnknown_0814F9A0
.L0814A5D4:
	cmp r3, #9
	bls .L0814A5E0
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #1
	strb r0, [r1]
.L0814A5E0:
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814A5F0
sub_0814A5F0: @ 0x0814A5F0
.L0814A5F0:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r5, .L0814A604
	ldrh r1, [r5, #0x20]
	adds r2, r1, #0
	cmp r2, #3
	bhi .L0814A60C
	ldr r0, .L0814A608
	b .L0814A62C
	.byte 0x00, 0x00
.L0814A604: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814A608: .4byte gUnknown_0814F9A0
.L0814A60C:
	subs r0, r1, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814A620
	ldr r0, .L0814A61C
	b .L0814A62C
	.byte 0x00, 0x00
.L0814A61C: .4byte gUnknown_0814F988
.L0814A620:
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814A648
	ldr r0, .L0814A644
.L0814A62C:
	movs r1, #0
	str r1, [sp]
	movs r1, #0xba
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814A672
.L0814A644: .4byte gUnknown_0814F970
.L0814A648:
	cmp r2, #9
	bls .L0814A672
	ldr r0, .L0814A680
	movs r4, #0
	str r4, [sp]
	movs r1, #0xba
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r1, r5, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
.L0814A672:
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L0814A680: .4byte gUnknown_0814F958

	thumb_func_start sub_0814A684
sub_0814A684: @ 0x0814A684
.L0814A684:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r5, .L0814A698
	ldrh r1, [r5, #0x22]
	adds r2, r1, #0
	cmp r2, #3
	bhi .L0814A6A0
	ldr r0, .L0814A69C
	b .L0814A6C0
	.byte 0x00, 0x00
.L0814A698: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814A69C: .4byte gUnknown_0814F9A0
.L0814A6A0:
	subs r0, r1, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814A6B4
	ldr r0, .L0814A6B0
	b .L0814A6C0
	.byte 0x00, 0x00
.L0814A6B0: .4byte gUnknown_0814F988
.L0814A6B4:
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814A6DC
	ldr r0, .L0814A6D8
.L0814A6C0:
	movs r1, #0
	str r1, [sp]
	movs r1, #7
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814A706
.L0814A6D8: .4byte gUnknown_0814F970
.L0814A6DC:
	cmp r2, #9
	bls .L0814A706
	ldr r0, .L0814A714
	movs r4, #0
	str r4, [sp]
	movs r1, #7
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r1, r5, #0
	adds r1, #0x27
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x25
	strb r4, [r0]
.L0814A706:
	ldrh r0, [r5, #0x22]
	adds r0, #1
	strh r0, [r5, #0x22]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L0814A714: .4byte gUnknown_0814F958

	thumb_func_start sub_0814A718
sub_0814A718: @ 0x0814A718
.L0814A718:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	ldr r5, .L0814A750
	ldrh r0, [r5, #0x3e]
	cmp r0, #0
	bne .L0814A760
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	cmp r0, #0xa2
	bhi .L0814A760
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r5, #0x1a]
	cmp r0, #0
	beq .L0814A746
	cmp r0, #0x63
	bne .L0814A758
.L0814A746:
	ldr r0, .L0814A754
	bl sub_080C51D4
	b .L0814A760
	.byte 0x00, 0x00
.L0814A750: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814A754: .4byte 0x00000163
.L0814A758:
	movs r0, #0xaf
	lsls r0, r0, #1
	bl sub_080C51D4
.L0814A760:
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #1
	bne .L0814A780
	ldrh r0, [r5, #0x3e]
	adds r0, #1
	strh r0, [r5, #0x3e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x14
	bne .L0814A780
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
.L0814A780:
	ldrb r0, [r5, #0x1a]
	cmp r0, #0
	beq .L0814A78A
	cmp r0, #0x63
	bne .L0814A7B8
.L0814A78A:
	ldr r0, .L0814A7B4
	movs r1, #0
	str r1, [sp]
	adds r4, r5, #0
	adds r4, #0x40
	adds r2, r5, #0
	adds r2, #0x44
	ldrh r1, [r4]
	ldrh r2, [r2]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x3f
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814A7E4
.L0814A7B4: .4byte gUnknown_0814F7DC
.L0814A7B8:
	ldr r0, .L0814A81C
	movs r1, #0
	str r1, [sp]
	adds r4, r5, #0
	adds r4, #0x40
	adds r2, r5, #0
	adds r2, #0x42
	ldrh r1, [r4]
	ldrh r2, [r2]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x3f
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_0814A9A4
.L0814A7E4:
	mov r8, r4
	adds r6, r5, #0
	adds r6, #0x56
	ldrh r0, [r6]
	cmp r0, #0x3d
	bne .L0814A82A
	ldr r7, .L0814A820
	movs r2, #0x98
	lsls r2, r2, #2
	adds r4, r5, r2
	ldrh r1, [r4]
	strh r1, [r7]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bne .L0814A824
	bl sub_0814AD74
	ldrh r0, [r7]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r7]
	movs r0, #0
	strh r0, [r4]
	ldrh r0, [r6]
	subs r0, #4
	strh r0, [r6]
	b .L0814A84A
.L0814A81C: .4byte gUnknown_0814F7C0
.L0814A820: .4byte 0x0300000C @ IWRAM+0xC
.L0814A824:
	adds r0, r1, #1
	strh r0, [r4]
	b .L0814A84A
.L0814A82A:
	ldrh r0, [r6]
	adds r1, r5, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r5, r0
	adds r0, #0x64
	ldrh r0, [r0]
	cmp r0, #4
	bls .L0814A846
	bl sub_0814AA70
	b .L0814A84A
.L0814A846:
	bl sub_0814AB5C
.L0814A84A:
	mov r0, r8
	ldrh r1, [r0]
	cmp r1, #0
	bne .L0814A890
	movs r0, #0xaa
	lsls r0, r0, #1
	mov r2, r8
	strh r0, [r2]
	strh r1, [r5, #0x3e]
	ldrb r0, [r5, #0x1a]
	cmp r0, #0
	beq .L0814A866
	cmp r0, #0x63
	bne .L0814A876
.L0814A866:
	str r1, [r5, #0x2c]
	str r1, [r5, #0x30]
	adds r0, r5, #0
	adds r0, #0x46
	strh r1, [r0]
	movs r0, #7
	strb r0, [r5, #4]
	b .L0814A890
.L0814A876:
	movs r0, #3
	strb r0, [r5, #4]
	adds r3, r5, #0
	adds r3, #0x46
	adds r0, r5, #0
	adds r0, #0x4a
	ldrh r1, [r3]
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
.L0814A890:
	mov r2, sb
	ldrb r0, [r2]
	cmp r0, #0
	bne .L0814A8A0
	mov r1, r8
	ldrh r0, [r1]
	subs r0, #4
	strh r0, [r1]
.L0814A8A0:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814A8B0
sub_0814A8B0: @ 0x0814A8B0
.L0814A8B0:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r5, .L0814A940
	movs r4, #0
.L0814A8B8:
	adds r0, r5, #0
	adds r0, #0x4a
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814A8E2
	ldr r0, .L0814A944
	lsls r2, r4, #3
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r2, #4]
	str r1, [sp, #4]
	ldrb r1, [r2, #6]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814A8E2:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #9
	bls .L0814A8B8
	movs r0, #0xe8
	lsls r0, r0, #2
	bl Font_ResetGlyphSpriteCache
	adds r1, r5, #0
	adds r1, #0x46
	ldrh r0, [r1]
	cmp r0, #2
	beq .L0814A902
	cmp r0, #7
	bne .L0814A954
.L0814A902:
	ldr r2, .L0814A948
	adds r0, r5, r2
	ldrh r4, [r0]
	movs r0, #0xc6
	muls r0, r4, r0
	ldrh r2, [r1]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r3, .L0814A94C
	adds r1, r1, r3
	adds r0, r0, r1
	ldr r3, .L0814A950
	lsls r2, r2, #2
	movs r1, #0x2c
	muls r1, r4, r1
	adds r2, r2, r1
	adds r2, r2, r3
	ldrh r3, [r2, #2]
	adds r3, #0x46
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r1, #0x52
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	bl sub_0814ADAC
	b .L0814A990
.L0814A940: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814A944: .4byte gUnknown_0879DE24
.L0814A948: .4byte 0x00000262
.L0814A94C: .4byte gUnknown_0879DF8C
.L0814A950: .4byte gUnknown_0879E2A4
.L0814A954:
	ldr r2, .L0814A998
	adds r0, r5, r2
	ldrh r4, [r0]
	movs r0, #0xc6
	muls r0, r4, r0
	ldrh r2, [r1]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r3, .L0814A99C
	adds r1, r1, r3
	adds r0, r0, r1
	ldr r3, .L0814A9A0
	lsls r2, r2, #2
	movs r1, #0x2c
	muls r1, r4, r1
	adds r2, r2, r1
	adds r2, r2, r3
	ldrh r3, [r2, #2]
	adds r3, #0x4d
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r1, #0x52
	str r1, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	bl sub_0814ADAC
.L0814A990:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L0814A998: .4byte 0x00000262
.L0814A99C: .4byte gUnknown_0879DF8C
.L0814A9A0: .4byte gUnknown_0879E2A4

	thumb_func_start sub_0814A9A4
sub_0814A9A4: @ 0x0814A9A4
.L0814A9A4:
	push {r4, lr}
	sub sp, #0xc
	ldr r2, .L0814A9FC
	adds r4, r2, #0
	adds r4, #0x48
	ldrh r0, [r4]
	cmp r0, #3
	bls .L0814A9E2
	ldr r3, .L0814AA00
	adds r2, #0x46
	ldrh r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r2]
	lsls r1, r1, #3
	adds r1, r1, r3
	ldrh r1, [r1, #4]
	str r1, [sp, #4]
	ldrh r1, [r2]
	lsls r1, r1, #3
	adds r1, r1, r3
	ldrb r1, [r1, #6]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814A9E2:
	ldrh r0, [r4]
	cmp r0, #6
	bls .L0814A9EC
	movs r0, #0
	strh r0, [r4]
.L0814A9EC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814A9FC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814AA00: .4byte gUnknown_0879DE24

	thumb_func_start sub_0814AA04
sub_0814AA04: @ 0x0814AA04
.L0814AA04:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r5, .L0814AA64
	movs r4, #0
	ldr r6, .L0814AA68
.L0814AA0E:
	lsls r0, r4, #3
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0x60
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814AA52
	adds r0, r1, #0
	adds r0, #0x64
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldr r1, .L0814AA6C
	lsls r3, r4, #2
	adds r3, r3, r1
	movs r1, #0x98
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r3]
	ldrh r2, [r2]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrb r1, [r3, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #2
	bl Sprite_Draw
.L0814AA52:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x3b
	bls .L0814AA0E
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0814AA64: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814AA68: .4byte gUnknown_0879DE74
.L0814AA6C: .4byte gUnknown_0879DE9C

	thumb_func_start sub_0814AA70
sub_0814AA70: @ 0x0814AA70
.L0814AA70:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r5, .L0814AA84
	adds r0, r5, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	cmp r1, #3
	bhi .L0814AA8C
	ldr r0, .L0814AA88
	b .L0814AAC2
.L0814AA84: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814AA88: .4byte gUnknown_0814F900
.L0814AA8C:
	subs r0, r1, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814AAA0
	ldr r0, .L0814AA9C
	b .L0814AAC2
	.byte 0x00, 0x00
.L0814AA9C: .4byte gUnknown_0814F910
.L0814AAA0:
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814AAB4
	ldr r0, .L0814AAB0
	b .L0814AAC2
	.byte 0x00, 0x00
.L0814AAB0: .4byte gUnknown_0814F920
.L0814AAB4:
	adds r0, r1, #0
	subs r0, #0xa
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814AAF8
	ldr r0, .L0814AAF0
.L0814AAC2:
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814AAF4
	adds r3, r5, #0
	adds r3, #0x56
	ldrh r1, [r3]
	subs r1, #1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r3]
	subs r1, #1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814AB40
.L0814AAF0: .4byte gUnknown_0814F930
.L0814AAF4: .4byte gUnknown_0879DE9C
.L0814AAF8:
	adds r0, r1, #0
	subs r0, #0xd
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814AB40
	ldr r0, .L0814AB54
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814AB58
	adds r4, r5, #0
	adds r4, #0x56
	ldrh r1, [r4]
	subs r1, #1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r4]
	subs r1, #1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r4]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, #0x60
	movs r1, #1
	strb r1, [r0]
.L0814AB40:
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814AB54: .4byte gUnknown_0814F940
.L0814AB58: .4byte gUnknown_0879DE9C

	thumb_func_start sub_0814AB5C
sub_0814AB5C: @ 0x0814AB5C
.L0814AB5C:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r5, .L0814AB70
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r1, [r0]
	cmp r1, #3
	bhi .L0814AB78
	ldr r0, .L0814AB74
	b .L0814ABAE
.L0814AB70: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814AB74: .4byte gUnknown_0814F8B0
.L0814AB78:
	subs r0, r1, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814AB8C
	ldr r0, .L0814AB88
	b .L0814ABAE
	.byte 0x00, 0x00
.L0814AB88: .4byte gUnknown_0814F8C0
.L0814AB8C:
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814ABA0
	ldr r0, .L0814AB9C
	b .L0814ABAE
	.byte 0x00, 0x00
.L0814AB9C: .4byte gUnknown_0814F8D0
.L0814ABA0:
	adds r0, r1, #0
	subs r0, #0xa
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814ABE4
	ldr r0, .L0814ABDC
.L0814ABAE:
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814ABE0
	adds r3, r5, #0
	adds r3, #0x56
	ldrh r1, [r3]
	subs r1, #1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r3]
	subs r1, #1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814AC2C
.L0814ABDC: .4byte gUnknown_0814F8E0
.L0814ABE0: .4byte gUnknown_0879DE9C
.L0814ABE4:
	adds r0, r1, #0
	subs r0, #0xd
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814AC2C
	ldr r0, .L0814AC40
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814AC44
	adds r4, r5, #0
	adds r4, #0x56
	ldrh r1, [r4]
	subs r1, #1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r4]
	subs r1, #1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r4]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, #0x60
	movs r1, #1
	strb r1, [r0]
.L0814AC2C:
	adds r1, r5, #0
	adds r1, #0x5c
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814AC40: .4byte gUnknown_0814F8F0
.L0814AC44: .4byte gUnknown_0879DE9C

	thumb_func_start sub_0814AC48
sub_0814AC48: @ 0x0814AC48
.L0814AC48:
	push {r4, r5, lr}
	ldr r3, .L0814AC78
	movs r0, #0x56
	adds r0, r0, r3
	mov ip, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0814AC7C
	mov r1, ip
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r1, [r3, #0x12]
	adds r0, #0x64
	strh r1, [r0]
	mov r2, ip
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0x58
	movs r0, #1
	strh r0, [r1]
	b .L0814AD6C
.L0814AC78: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814AC7C:
	mov r0, ip
	ldrh r2, [r0]
	adds r5, r3, #0
	adds r5, #0x58
	ldrh r0, [r5]
	subs r0, r2, r0
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, #0x64
	ldrh r0, [r0]
	cmp r0, #4
	bls .L0814ACE8
	ldrh r4, [r3, #0x12]
	cmp r4, #4
	bls .L0814ACAC
	lsls r0, r2, #3
	adds r0, r0, r3
	adds r0, #0x64
	strh r4, [r0]
	mov r1, ip
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b .L0814AD68
.L0814ACAC:
	movs r1, #3
	ands r1, r2
	cmp r1, #1
	beq .L0814AD2C
	cmp r1, #1
	bgt .L0814ACBE
	cmp r1, #0
	beq .L0814ACC4
	b .L0814AD6C
.L0814ACBE:
	cmp r1, #2
	beq .L0814ACD4
	b .L0814AD16
.L0814ACC4:
	lsls r0, r2, #3
	adds r0, r0, r3
	adds r0, #0x64
	strh r4, [r0]
	mov r2, ip
	ldrh r0, [r2]
	adds r0, #1
	b .L0814AD66
.L0814ACD4:
	adds r0, r2, #2
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, #0x64
	strh r4, [r0]
	mov r1, ip
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	b .L0814AD68
.L0814ACE8:
	ldrh r4, [r3, #0x12]
	cmp r4, #4
	bhi .L0814AD00
	lsls r0, r2, #3
	adds r0, r0, r3
	adds r0, #0x64
	strh r4, [r0]
	mov r1, ip
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b .L0814AD68
.L0814AD00:
	movs r1, #3
	ands r1, r2
	cmp r1, #1
	beq .L0814AD2C
	cmp r1, #1
	bgt .L0814AD12
	cmp r1, #0
	beq .L0814AD1C
	b .L0814AD6C
.L0814AD12:
	cmp r1, #2
	beq .L0814AD42
.L0814AD16:
	cmp r1, #3
	beq .L0814AD56
	b .L0814AD6C
.L0814AD1C:
	lsls r0, r2, #3
	adds r0, r0, r3
	adds r0, #0x64
	strh r4, [r0]
	mov r2, ip
	ldrh r0, [r2]
	adds r0, #1
	b .L0814AD66
.L0814AD2C:
	adds r0, r2, #3
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, #0x64
	strh r4, [r0]
	mov r2, ip
	ldrh r0, [r2]
	adds r0, #4
	strh r0, [r2]
	strh r1, [r5]
	b .L0814AD6C
.L0814AD42:
	adds r0, r2, #2
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, #0x64
	strh r4, [r0]
	mov r1, ip
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	b .L0814AD68
.L0814AD56:
	adds r0, r2, #1
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, #0x64
	strh r4, [r0]
	mov r2, ip
	ldrh r0, [r2]
	adds r0, #2
.L0814AD66:
	strh r0, [r2]
.L0814AD68:
	movs r0, #1
	strh r0, [r5]
.L0814AD6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814AD74
sub_0814AD74: @ 0x0814AD74
.L0814AD74:
	push {r4, r5, lr}
	ldr r5, .L0814ADA8
	movs r4, #0
.L0814AD7A:
	lsls r3, r4, #3
	adds r3, r5, r3
	adds r0, r4, #4
	lsls r0, r0, #3
	adds r0, r5, r0
	adds r1, r0, #0
	adds r1, #0x60
	ldrb r2, [r1]
	adds r1, r3, #0
	adds r1, #0x60
	strb r2, [r1]
	adds r0, #0x64
	ldrh r0, [r0]
	adds r3, #0x64
	strh r0, [r3]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x3b
	bls .L0814AD7A
	pop {r4, r5}
	pop {r0}
	bx r0
.L0814ADA8: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0814ADAC
sub_0814ADAC: @ 0x0814ADAC
.L0814ADAC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [sp, #0x28]
	ldr r4, [sp, #0x2c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sb, r2
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r5
	b .L0814AE06
.L0814ADDA:
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	bne .L0814ADEC
	mov r5, r8
	adds r0, r7, r4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	b .L0814AE04
.L0814ADEC:
	ldrh r0, [r6]
	str r7, [sp]
	movs r1, #0xf
	str r1, [sp, #4]
	mov r1, sl
	mov r2, sb
	adds r3, r5, #0
	bl FontSprite_DrawGlyphTinted
	adds r0, r5, r4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0814AE04:
	adds r6, #2
.L0814AE06:
	ldrh r0, [r6]
	cmp r0, #0
	bne .L0814ADDA
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814AE1C
sub_0814AE1C: @ 0x0814AE1C
	ldr r0, .L0814AE24
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L0814AE24: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0814AE28
sub_0814AE28: @ 0x0814AE28
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r5, .L0814AE70
	ldr r6, .L0814AE74
	movs r4, #0
	str r4, [sp]
	ldr r2, .L0814AE78
	mov r0, sp
	adds r1, r6, #0
	bl CpuSet
	ldr r1, .L0814AE7C
	ldr r2, .L0814AE80
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L0814AE84
	strh r4, [r0]
	ldr r0, .L0814AE88
	strh r4, [r0]
	movs r0, #1
	strh r0, [r6]
	movs r0, #0x75
	strh r0, [r6, #0x3c]
	movs r2, #0x50
	strh r2, [r6, #0x3a]
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r6, #0x34]
	ldrh r0, [r5, #2]
	cmp r0, #1
	beq .L0814AEB6
	cmp r0, #1
	bgt .L0814AE8C
	cmp r0, #0
	beq .L0814AE9A
	b .L0814AE94
.L0814AE70: .4byte 0x0203B554 @ EWRAM+0x3B554
.L0814AE74: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814AE78: .4byte 0x05000200 @ PLTT+0x200
.L0814AE7C: .4byte 0x04000008 @ REG_BG0CNT
.L0814AE80: .4byte 0x00004008
.L0814AE84: .4byte 0x03000002 @ IWRAM+0x2
.L0814AE88: .4byte 0x03000040 @ IWRAM+0x40
.L0814AE8C:
	cmp r0, #2
	beq .L0814AED2
	cmp r0, #3
	beq .L0814AED2
.L0814AE94:
	adds r1, r6, #0
	adds r1, #0x2e
	b .L0814AEE8
.L0814AE9A:
	movs r0, #0
	strb r0, [r6, #5]
	adds r1, r6, #0
	adds r1, #0x2f
	movs r0, #3
	strb r0, [r1]
	subs r1, #1
	movs r0, #5
	strb r0, [r1]
	movs r0, #0x14
	strh r0, [r6, #0x1e]
	movs r0, #0x32
	strh r0, [r6, #0x20]
	b .L0814AEE8
.L0814AEB6:
	movs r0, #1
	strb r0, [r6, #5]
	adds r1, r6, #0
	adds r1, #0x2f
	movs r0, #4
	strb r0, [r1]
	subs r1, #1
	movs r0, #7
	strb r0, [r1]
	movs r0, #0x14
	strh r0, [r6, #0x1e]
	movs r0, #0x41
	strh r0, [r6, #0x20]
	b .L0814AEE8
.L0814AED2:
	strb r0, [r6, #5]
	adds r1, r6, #0
	adds r1, #0x2f
	movs r0, #5
	strb r0, [r1]
	subs r1, #1
	movs r0, #8
	strb r0, [r1]
	movs r0, #0x14
	strh r0, [r6, #0x1e]
	strh r2, [r6, #0x20]
.L0814AEE8:
	movs r2, #0
	ldrb r0, [r1]
	cmp r2, r0
	bhs .L0814AF0C
	movs r3, #0xb6
	lsls r3, r3, #1
.L0814AEF4:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r0, r0, r3
	strb r2, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrb r0, [r1]
	cmp r2, r0
	blo .L0814AEF4
.L0814AF0C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_0814AF14
sub_0814AF14: @ 0x0814AF14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	ldr r5, .L0814AF44
	ldrh r0, [r5]
	cmp r0, #1
	bne .L0814AF34
	ldr r0, .L0814AF48
	ldr r1, .L0814AF4C
	bl Task_Create
	movs r0, #0
	strh r0, [r5]
.L0814AF34:
	ldrb r1, [r5, #5]
	cmp r1, #1
	beq .L0814AF64
	cmp r1, #1
	bgt .L0814AF50
	cmp r1, #0
	beq .L0814AF5A
	b .L0814AFA4
.L0814AF44: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814AF48: .4byte gUnknown_0879F064
.L0814AF4C: .4byte 0x0000FFFF
.L0814AF50:
	cmp r1, #2
	beq .L0814AF6C
	cmp r1, #3
	beq .L0814AF8C
	b .L0814AFA4
.L0814AF5A:
	ldr r0, .L0814AF60
	b .L0814AF70
	.byte 0x00, 0x00
.L0814AF60: .4byte gUnknown_0814FC1C
.L0814AF64:
	ldr r0, .L0814AF68
	b .L0814AF6E
.L0814AF68: .4byte gUnknown_0814FC2C
.L0814AF6C:
	ldr r0, .L0814AF88
.L0814AF6E:
	movs r1, #0
.L0814AF70:
	str r1, [sp]
	movs r1, #0x49
	str r1, [sp, #4]
	movs r1, #0x1a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814AFA4
	.byte 0x00, 0x00
.L0814AF88: .4byte gUnknown_0814FC3C
.L0814AF8C:
	ldr r0, .L0814B12C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x49
	str r1, [sp, #4]
	movs r1, #0x1a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814AFA4:
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	bne .L0814AFC2
	ldr r0, .L0814B130
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814AFC2:
	bl sub_0814B838
	bl sub_0814B894
	bl sub_0814B8F4
	ldrb r0, [r5, #0x1c]
	cmp r0, #1
	bne .L0814AFFA
	ldr r0, .L0814B134
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814B138
	ldrh r1, [r5, #0x1a]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r5, #0x1a]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814AFFA:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814B008
	bl sub_0814BE8C
.L0814B008:
	bl sub_0814C318
	movs r0, #0xfe
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xd7
	movs r2, #0x27
	movs r3, #0
	bl sub_0814C3FC
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0814B02E
	b .L0814B184
.L0814B02E:
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq .L0814B036
	b .L0814B184
.L0814B036:
	ldr r0, .L0814B13C
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0814B046
	b .L0814B14C
.L0814B046:
	movs r0, #0xfe
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0814B14C
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0x2f
	movs r7, #0x2e
	adds r7, r7, r5
	mov sb, r7
	movs r0, #0x44
	adds r0, r0, r5
	mov sl, r0
	adds r1, r5, #0
	adds r1, #0x3f
	str r1, [sp, #0xc]
	movs r7, #0x96
	lsls r7, r7, #1
	movs r2, #0
	ldr r6, .L0814B140
.L0814B072:
	lsls r0, r3, #2
	adds r0, r5, r0
	adds r1, r0, r7
	strb r2, [r1]
	adds r0, r0, r6
	strb r2, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #7
	bls .L0814B072
	movs r3, #0
	adds r2, r4, #0
	ldrb r7, [r4]
	cmp r3, r7
	bhs .L0814B0BC
	movs r0, #0x8d
	lsls r0, r0, #1
	mov ip, r0
	mov r8, r3
	movs r6, #0xa
.L0814B09C:
	lsls r0, r3, #2
	adds r0, r5, r0
	mov r7, ip
	adds r1, r0, r7
	mov r7, r8
	strb r7, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r0, r1
	strb r6, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrb r7, [r2]
	cmp r3, r7
	blo .L0814B09C
.L0814B0BC:
	movs r3, #0
	mov r0, sb
	ldrb r0, [r0]
	cmp r3, r0
	bhs .L0814B10E
	adds r6, r4, #0
.L0814B0C8:
	movs r2, #0
	adds r1, r3, #1
	str r1, [sp, #0x10]
	ldrb r7, [r6]
	cmp r2, r7
	bhs .L0814B100
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r4, r0, #2
	movs r3, #0
	ldr r0, .L0814B144
	mov r8, r0
	ldr r1, .L0814B148
	mov ip, r1
.L0814B0E4:
	lsls r0, r2, #2
	adds r0, r0, r4
	adds r0, r5, r0
	mov r7, r8
	adds r1, r0, r7
	strb r3, [r1]
	add r0, ip
	strb r3, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrb r0, [r6]
	cmp r2, r0
	blo .L0814B0E4
.L0814B100:
	ldr r1, [sp, #0x10]
	lsls r0, r1, #0x10
	lsrs r3, r0, #0x10
	mov r7, sb
	ldrb r7, [r7]
	cmp r3, r7
	blo .L0814B0C8
.L0814B10E:
	movs r0, #0
	mov r1, sl
	strb r0, [r1]
	movs r4, #1
	ldr r7, [sp, #0xc]
	strb r4, [r7]
	movs r0, #0xfe
	bl sub_080C33AC
	strb r4, [r5, #4]
	movs r0, #0xad
	lsls r0, r0, #1
	bl sub_080C51D4
	b .L0814B16A
.L0814B12C: .4byte gUnknown_0814FC3C
.L0814B130: .4byte gUnknown_0814FE04
.L0814B134: .4byte gUnknown_0814FBEC
.L0814B138: .4byte gUnknown_0879EB64
.L0814B13C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0814B140: .4byte 0x0000012D
.L0814B144: .4byte 0x0000016F
.L0814B148: .4byte 0x0000016D
.L0814B14C:
	ldr r0, .L0814B1F8
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0814B16A
	movs r0, #0xfe
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0814B16A
	movs r0, #0x63
	strb r0, [r5, #4]
.L0814B16A:
	ldr r0, .L0814B1F8
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0814B184
	movs r0, #0xac
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r0, #0x63
	strb r0, [r5, #4]
.L0814B184:
	ldrb r0, [r5, #4]
	cmp r0, #3
	bne .L0814B25C
	ldr r2, .L0814B1F8
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L0814B1AA
	adds r3, r5, #0
	adds r3, #0x2a
	ldrb r0, [r3]
	cmp r0, #0
	bne .L0814B1AA
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
	strb r0, [r3]
.L0814B1AA:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L0814B1C8
	adds r3, r5, #0
	adds r3, #0x2a
	ldrb r0, [r3]
	cmp r0, #0
	bne .L0814B1C8
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #1
	strb r0, [r1]
	strb r0, [r3]
.L0814B1C8:
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L0814B204
	adds r0, r5, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0814B204
	ldr r0, .L0814B1FC
	ldrh r3, [r5, #0x1a]
	lsls r1, r3, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	ldrh r1, [r5, #0x20]
	cmp r0, r1
	bne .L0814B200
	adds r0, r3, #1
	adds r1, r5, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	subs r0, r0, r1
	b .L0814B202
.L0814B1F8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0814B1FC: .4byte gUnknown_0879EB64
.L0814B200:
	adds r0, r3, #1
.L0814B202:
	strh r0, [r5, #0x1a]
.L0814B204:
	ldrh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L0814B244
	adds r0, r5, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0814B244
	ldr r0, .L0814B238
	ldrh r4, [r5, #0x1a]
	lsls r1, r4, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	ldrh r7, [r5, #0x1e]
	cmp r0, r7
	bne .L0814B240
	adds r3, r5, #0
	adds r3, #0x2f
	ldr r1, .L0814B23C
	adds r0, r4, r1
	ldrb r3, [r3]
	adds r0, r0, r3
	b .L0814B242
	.byte 0x00, 0x00
.L0814B238: .4byte gUnknown_0879EB64
.L0814B23C: .4byte 0x0000FFFF
.L0814B240:
	subs r0, r4, #1
.L0814B242:
	strh r0, [r5, #0x1a]
.L0814B244:
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0814B25C
	adds r0, r5, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0814B25C
	movs r0, #4
	strb r0, [r5, #4]
.L0814B25C:
	ldrb r0, [r5, #4]
	cmp r0, #0x63
	bls .L0814B264
	b .L0814B508
.L0814B264:
	lsls r0, r0, #2
	ldr r1, .L0814B270
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L0814B270: .4byte gUnknown_0814B274
	.global gUnknown_0814B274
gUnknown_0814B274:
.L0814B274: @ jump table
	.4byte .L0814B404
	.4byte .L0814B43C
	.4byte .L0814B460
	.4byte .L0814B466
	.4byte .L0814B486
	.4byte .L0814B48C
	.4byte .L0814B492
	.4byte .L0814B498
	.4byte .L0814B49E
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B508
	.4byte .L0814B4C4
.L0814B404:
	ldrh r0, [r5, #6]
	cmp r0, #0x14
	bls .L0814B4F8
	ldr r0, .L0814B438
	movs r4, #0
	str r4, [sp]
	movs r1, #0xbb
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r5, #6]
	cmp r0, #0x28
	bls .L0814B4F8
	strh r4, [r5, #6]
	movs r7, #0x83
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r0, #1
	strb r0, [r1]
	b .L0814B4F8
	.byte 0x00, 0x00
.L0814B438: .4byte gUnknown_0814FBC4
.L0814B43C:
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	bne .L0814B446
	movs r0, #1
	strb r0, [r5, #0x1c]
.L0814B446:
	bl sub_0814B7AC
	bl sub_0814B524
	adds r1, r5, #0
	adds r1, #0x2f
	ldrh r0, [r5, #0xe]
	ldrb r1, [r1]
	cmp r0, r1
	bhs .L0814B508
	bl sub_0814B6C4
	b .L0814B508
.L0814B460:
	bl sub_0814C098
	b .L0814B508
.L0814B466:
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814B476
	bl sub_0814BB1C
	b .L0814B508
.L0814B476:
	adds r0, r5, #0
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814B508
	bl sub_0814BC0C
	b .L0814B508
.L0814B486:
	bl sub_0814BCF4
	b .L0814B508
.L0814B48C:
	bl sub_0814BF7C
	b .L0814B508
.L0814B492:
	bl sub_0814C130
	b .L0814B508
.L0814B498:
	bl sub_0814C230
	b .L0814B508
.L0814B49E:
	ldr r3, .L0814B4C0
	adds r0, r5, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	lsls r1, r1, #2
	ldrb r2, [r5, #5]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r1, r3
	ldrh r0, [r1]
	bl sub_080C3328
	movs r0, #0
	strb r0, [r5, #4]
	b .L0814B508
.L0814B4C0: .4byte gUnknown_0879EEE4
.L0814B4C4:
	ldrh r0, [r5, #8]
	cmp r0, #5
	bhi .L0814B504
	ldrh r0, [r5, #6]
	cmp r0, #3
	bls .L0814B4E8
	ldr r0, .L0814B500
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814B4E8:
	ldrh r0, [r5, #6]
	cmp r0, #6
	bls .L0814B4F8
	movs r0, #0
	strh r0, [r5, #6]
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
.L0814B4F8:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b .L0814B508
.L0814B500: .4byte gUnknown_0814FBDC
.L0814B504:
	bl sub_080BE4C4
.L0814B508:
	ldrb r0, [r5, #5]
	cmp r0, #3
	beq .L0814B512
	bl sub_0814C47C
.L0814B512:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814B524
sub_0814B524: @ 0x0814B524
.L0814B524:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r5, .L0814B538
	ldrh r1, [r5, #0xa]
	adds r2, r1, #0
	cmp r2, #2
	bhi .L0814B540
	ldr r0, .L0814B53C
	b .L0814B574
	.byte 0x00, 0x00
.L0814B538: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814B53C: .4byte gUnknown_0814FCEC
.L0814B540:
	subs r0, r1, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814B554
	ldr r0, .L0814B550
	b .L0814B574
	.byte 0x00, 0x00
.L0814B550: .4byte gUnknown_0814FD1C
.L0814B554:
	subs r0, r1, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814B568
	ldr r0, .L0814B564
	b .L0814B574
	.byte 0x00, 0x00
.L0814B564: .4byte gUnknown_0814FD0C
.L0814B568:
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814B5B8
	ldr r0, .L0814B5B0
.L0814B574:
	movs r1, #0
	str r1, [sp]
	ldr r4, .L0814B5B4
	ldrh r2, [r5, #0x10]
	lsls r2, r2, #3
	ldrb r3, [r5, #5]
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #6
	adds r2, r2, r1
	adds r2, r2, r4
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r2, [r5, #0x10]
	lsls r2, r2, #3
	ldrb r3, [r5, #5]
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #6
	adds r2, r2, r1
	adds r2, r2, r4
	ldrb r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814B6B6
	.byte 0x00, 0x00
.L0814B5B0: .4byte gUnknown_0814FCFC
.L0814B5B4: .4byte gUnknown_0879E5C4
.L0814B5B8:
	cmp r2, #8
	bhi .L0814B5BE
	b .L0814B6B6
.L0814B5BE:
	ldr r0, .L0814B648
	movs r6, #0
	str r6, [sp]
	ldr r4, .L0814B64C
	ldrh r2, [r5, #0x10]
	lsls r2, r2, #3
	ldrb r3, [r5, #5]
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #6
	adds r2, r2, r1
	adds r2, r2, r4
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r2, [r5, #0x10]
	lsls r2, r2, #3
	ldrb r3, [r5, #5]
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #6
	adds r2, r2, r1
	adds r2, r2, r4
	ldrb r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L0814B650
	bl sub_080C51D4
	ldrh r0, [r5, #0xa]
	cmp r0, #0xc
	bls .L0814B6B6
	ldrh r1, [r5, #0x10]
	adds r0, r5, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bgt .L0814B654
	lsls r1, r1, #3
	ldrb r2, [r5, #5]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r4
	ldrb r0, [r1, #4]
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, #0x78
	strb r6, [r0]
	ldrh r1, [r5, #0x10]
	lsls r1, r1, #3
	ldrb r2, [r5, #5]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r4
	ldrb r0, [r1, #4]
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, #0x7a
	movs r1, #1
	strb r1, [r0]
	b .L0814B686
.L0814B648: .4byte gUnknown_0814FCEC
.L0814B64C: .4byte gUnknown_0879E5C4
.L0814B650: .4byte 0x0000015B
.L0814B654:
	lsls r1, r1, #3
	ldrb r2, [r5, #5]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r4
	ldrb r0, [r1, #4]
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, #0x78
	strb r6, [r0]
	ldrh r1, [r5, #0x10]
	lsls r1, r1, #3
	ldrb r2, [r5, #5]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r4
	ldrb r0, [r1, #4]
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, #0x7a
	strb r6, [r0]
.L0814B686:
	ldr r3, .L0814B6A4
	ldrh r4, [r5, #0x10]
	lsls r1, r4, #3
	ldrb r2, [r5, #5]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r3
	ldrb r0, [r1, #5]
	cmp r0, #1
	beq .L0814B6A8
	adds r0, r4, #1
	strh r0, [r5, #0x10]
	b .L0814B6B2
.L0814B6A4: .4byte gUnknown_0879E5C4
.L0814B6A8:
	movs r0, #0
	strh r0, [r5, #0x10]
	strh r0, [r5, #0xe]
	movs r0, #2
	strb r0, [r5, #4]
.L0814B6B2:
	movs r0, #0
	strh r0, [r5, #0xa]
.L0814B6B6:
	ldrh r0, [r5, #0xa]
	adds r0, #1
	strh r0, [r5, #0xa]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_0814B6C4
sub_0814B6C4: @ 0x0814B6C4
.L0814B6C4:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, .L0814B6D8
	ldrh r1, [r4, #0xc]
	adds r2, r1, #0
	cmp r2, #2
	bhi .L0814B6E0
	ldr r0, .L0814B6DC
	b .L0814B714
	.byte 0x00, 0x00
.L0814B6D8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814B6DC: .4byte gUnknown_0814FCEC
.L0814B6E0:
	subs r0, r1, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814B6F4
	ldr r0, .L0814B6F0
	b .L0814B714
	.byte 0x00, 0x00
.L0814B6F0: .4byte gUnknown_0814FD1C
.L0814B6F4:
	subs r0, r1, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814B708
	ldr r0, .L0814B704
	b .L0814B714
	.byte 0x00, 0x00
.L0814B704: .4byte gUnknown_0814FD0C
.L0814B708:
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814B744
	ldr r0, .L0814B73C
.L0814B714:
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814B740
	ldrh r1, [r4, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r4, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814B792
	.byte 0x00, 0x00
.L0814B73C: .4byte gUnknown_0814FCFC
.L0814B740: .4byte gUnknown_0879E5B0
.L0814B744:
	cmp r2, #8
	bls .L0814B792
	ldr r0, .L0814B7A0
	movs r5, #0
	str r5, [sp]
	ldr r2, .L0814B7A4
	ldrh r1, [r4, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r4, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L0814B7A8
	bl sub_080C51D4
	ldrh r0, [r4, #0xc]
	cmp r0, #0xc
	bls .L0814B792
	ldrh r0, [r4, #0xe]
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #8
	strb r1, [r0]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	strh r5, [r4, #0xc]
.L0814B792:
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L0814B7A0: .4byte gUnknown_0814FCEC
.L0814B7A4: .4byte gUnknown_0879E5B0
.L0814B7A8: .4byte 0x0000015B

	thumb_func_start sub_0814B7AC
sub_0814B7AC: @ 0x0814B7AC
.L0814B7AC:
	push {r4, lr}
	sub sp, #0xc
	ldr r4, .L0814B7C0
	ldrh r1, [r4, #0x16]
	adds r2, r1, #0
	cmp r2, #3
	bhi .L0814B7C8
	ldr r0, .L0814B7C4
	b .L0814B7E8
	.byte 0x00, 0x00
.L0814B7C0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814B7C4: .4byte gUnknown_0814FE4C
.L0814B7C8:
	subs r0, r1, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814B7DC
	ldr r0, .L0814B7D8
	b .L0814B7E8
	.byte 0x00, 0x00
.L0814B7D8: .4byte gUnknown_0814FE34
.L0814B7DC:
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi .L0814B804
	ldr r0, .L0814B800
.L0814B7E8:
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814B824
.L0814B800: .4byte gUnknown_0814FE1C
.L0814B804:
	cmp r2, #9
	bls .L0814B824
	ldr r0, .L0814B834
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r0, #1
	strb r0, [r4, #0x18]
.L0814B824:
	ldrh r0, [r4, #0x16]
	adds r0, #1
	strh r0, [r4, #0x16]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814B834: .4byte gUnknown_0814FE04

	thumb_func_start sub_0814B838
sub_0814B838: @ 0x0814B838
.L0814B838:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r6, .L0814B888
	movs r4, #0
	ldr r5, .L0814B88C
.L0814B842:
	lsls r3, r4, #2
	adds r1, r6, r3
	adds r0, r1, #0
	adds r0, #0x7a
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814B876
	adds r0, r1, #0
	adds r0, #0x78
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814B890
	adds r2, r3, r2
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrb r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0814B876:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x27
	bls .L0814B842
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0814B888: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814B88C: .4byte gUnknown_0879E58C
.L0814B890: .4byte gUnknown_0879EAC4

	thumb_func_start sub_0814B894
sub_0814B894: @ 0x0814B894
.L0814B894:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r6, .L0814B8E8
	movs r4, #0
	ldr r5, .L0814B8EC
.L0814B89E:
	lsls r3, r4, #2
	adds r1, r6, r3
	movs r2, #0x8d
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0814B8D4
	subs r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814B8F0
	adds r2, r3, r2
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrb r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0814B8D4:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #4
	bls .L0814B89E
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814B8E8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814B8EC: .4byte gUnknown_0879E58C
.L0814B8F0: .4byte gUnknown_0879E5B0

	thumb_func_start sub_0814B8F4
sub_0814B8F4: @ 0x0814B8F4
.L0814B8F4:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0xc
	ldr r0, .L0814B910
	ldrb r6, [r0, #5]
	cmp r6, #1
	beq .L0814B9E4
	cmp r6, #1
	bgt .L0814B914
	cmp r6, #0
	beq .L0814B922
	b .L0814BB08
	.byte 0x00, 0x00
.L0814B910: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814B914:
	cmp r6, #2
	bne .L0814B91A
	b .L0814BB08
.L0814B91A:
	cmp r6, #3
	bne .L0814B920
	b .L0814BA4C
.L0814B920:
	b .L0814BB08
.L0814B922:
	ldr r5, .L0814B9D8
	str r6, [sp]
	movs r0, #0x39
	str r0, [sp, #4]
	movs r4, #0x21
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	movs r0, #0x48
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r5, .L0814B9DC
	str r6, [sp]
	movs r0, #0x3d
	str r0, [sp, #4]
	movs r4, #0x41
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	movs r0, #0x4c
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	movs r0, #0xca
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	movs r0, #0xd9
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r5, .L0814B9E0
	str r6, [sp]
	movs r4, #0x8e
	str r4, [sp, #4]
	movs r0, #0x78
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0x83
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	b .L0814BA32
.L0814B9D8: .4byte gUnknown_0814FCDC
.L0814B9DC: .4byte gUnknown_0814FEEC
.L0814B9E0: .4byte gUnknown_0814FEC8
.L0814B9E4:
	ldr r0, .L0814BA40
	movs r4, #0
	str r4, [sp]
	movs r1, #0x48
	str r1, [sp, #4]
	movs r1, #0x21
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r6, .L0814BA44
	str r4, [sp]
	movs r0, #0x4c
	str r0, [sp, #4]
	movs r5, #0x41
	str r5, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r4, [sp]
	movs r0, #0xd9
	str r0, [sp, #4]
	str r5, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L0814BA48
	str r4, [sp]
	movs r1, #0x8e
	str r1, [sp, #4]
	str r1, [sp, #8]
.L0814BA32:
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814BB08
	.byte 0x00, 0x00
.L0814BA40: .4byte gUnknown_0814FCDC
.L0814BA44: .4byte gUnknown_0814FEEC
.L0814BA48: .4byte gUnknown_0814FEC8
.L0814BA4C:
	ldr r0, .L0814BB14
	movs r6, #0
	str r6, [sp]
	movs r1, #0xd9
	str r1, [sp, #4]
	movs r1, #0x41
	mov r8, r1
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r5, .L0814BB18
	str r6, [sp]
	movs r4, #0x8e
	str r4, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0x4c
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0x57
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0x62
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0x6d
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0x78
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0x83
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r6, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814BB08:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0814BB14: .4byte gUnknown_0814FEEC
.L0814BB18: .4byte gUnknown_0814FEC8

	thumb_func_start sub_0814BB1C
sub_0814BB1C: @ 0x0814BB1C
.L0814BB1C:
	push {r4, lr}
	sub sp, #0xc
	ldr r4, .L0814BB2C
	ldrh r1, [r4, #0x26]
	cmp r1, #4
	bhi .L0814BB34
	ldr r0, .L0814BB30
	b .L0814BB92
.L0814BB2C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814BB30: .4byte gUnknown_0814FCFC
.L0814BB34:
	subs r0, r1, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L0814BB48
	ldr r0, .L0814BB44
	b .L0814BB92
	.byte 0x00, 0x00
.L0814BB44: .4byte gUnknown_0814FD0C
.L0814BB48:
	adds r0, r1, #0
	subs r0, #9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L0814BB5C
	ldr r0, .L0814BB58
	b .L0814BB92
.L0814BB58: .4byte gUnknown_0814FD1C
.L0814BB5C:
	adds r0, r1, #0
	subs r0, #0xd
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L0814BB70
	ldr r0, .L0814BB6C
	b .L0814BB92
.L0814BB6C: .4byte gUnknown_0814FD2C
.L0814BB70:
	adds r0, r1, #0
	subs r0, #0x11
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L0814BB84
	ldr r0, .L0814BB80
	b .L0814BB92
.L0814BB80: .4byte gUnknown_0814FD3C
.L0814BB84:
	adds r0, r1, #0
	subs r0, #0x15
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L0814BBC0
	ldr r0, .L0814BBB8
.L0814BB92:
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814BBBC
	ldrh r1, [r4, #0x1a]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r4, #0x1a]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814BBFC
.L0814BBB8: .4byte gUnknown_0814FD4C
.L0814BBBC: .4byte gUnknown_0879EAC4
.L0814BBC0:
	ldr r0, .L0814BBE4
	bl sub_080C51D4
	ldrh r0, [r4, #0x1a]
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r1, r0, #0
	adds r1, #0x78
	ldrb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	subs r0, #1
	cmp r2, r0
	bne .L0814BBE8
	movs r0, #0
	b .L0814BBEA
	.byte 0x00, 0x00
.L0814BBE4: .4byte 0x0000015B
.L0814BBE8:
	adds r0, r2, #1
.L0814BBEA:
	strb r0, [r1]
	movs r0, #0
	movs r1, #0
	strh r1, [r4, #0x26]
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r1, #6
	strb r0, [r1]
.L0814BBFC:
	ldrh r0, [r4, #0x26]
	adds r0, #1
	strh r0, [r4, #0x26]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814BC0C
sub_0814BC0C: @ 0x0814BC0C
.L0814BC0C:
	push {r4, lr}
	sub sp, #0xc
	ldr r4, .L0814BC1C
	ldrh r1, [r4, #0x28]
	cmp r1, #4
	bhi .L0814BC24
	ldr r0, .L0814BC20
	b .L0814BC82
.L0814BC1C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814BC20: .4byte gUnknown_0814FD4C
.L0814BC24:
	subs r0, r1, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L0814BC38
	ldr r0, .L0814BC34
	b .L0814BC82
	.byte 0x00, 0x00
.L0814BC34: .4byte gUnknown_0814FD3C
.L0814BC38:
	adds r0, r1, #0
	subs r0, #9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L0814BC4C
	ldr r0, .L0814BC48
	b .L0814BC82
.L0814BC48: .4byte gUnknown_0814FD2C
.L0814BC4C:
	adds r0, r1, #0
	subs r0, #0xd
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L0814BC60
	ldr r0, .L0814BC5C
	b .L0814BC82
.L0814BC5C: .4byte gUnknown_0814FD1C
.L0814BC60:
	adds r0, r1, #0
	subs r0, #0x11
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L0814BC74
	ldr r0, .L0814BC70
	b .L0814BC82
.L0814BC70: .4byte gUnknown_0814FD0C
.L0814BC74:
	adds r0, r1, #0
	subs r0, #0x15
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L0814BCB0
	ldr r0, .L0814BCA8
.L0814BC82:
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814BCAC
	ldrh r1, [r4, #0x1a]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r4, #0x1a]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814BCE0
.L0814BCA8: .4byte gUnknown_0814FCFC
.L0814BCAC: .4byte gUnknown_0879EAC4
.L0814BCB0:
	ldr r0, .L0814BCF0
	bl sub_080C51D4
	ldrh r0, [r4, #0x1a]
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r1, r0, #0
	adds r1, #0x78
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0814BCCC
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
.L0814BCCC:
	subs r0, #1
	strb r0, [r1]
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0x28]
	adds r0, r4, #0
	adds r0, #0x25
	strb r1, [r0]
	adds r0, #5
	strb r1, [r0]
.L0814BCE0:
	ldrh r0, [r4, #0x28]
	adds r0, #1
	strh r0, [r4, #0x28]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814BCF0: .4byte 0x0000015B

	thumb_func_start sub_0814BCF4
sub_0814BCF4: @ 0x0814BCF4
.L0814BCF4:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r5, .L0814BD50
	movs r6, #0
	adds r0, r5, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r6, r0
	bhs .L0814BDBE
	movs r0, #0x2b
	adds r0, r0, r5
	mov r8, r0
.L0814BD12:
	mov r1, r8
	ldrb r2, [r1]
	adds r0, r2, r6
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r0, #0x78
	lsls r1, r6, #2
	adds r1, r5, r1
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r1, r1, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne .L0814BD54
	adds r0, r2, #0
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r5, r0
	movs r7, #0x96
	lsls r7, r7, #1
	adds r0, r0, r7
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	adds r3, r6, #1
	b .L0814BDB0
	.byte 0x00, 0x00
.L0814BD50: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814BD54:
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x2f
	mov sb, r0
	adds r3, r6, #1
	ldrb r0, [r0]
	cmp r4, r0
	bhs .L0814BDB0
.L0814BD64:
	cmp r6, r4
	beq .L0814BDA2
	mov r1, r8
	ldrb r2, [r1]
	adds r0, r2, r6
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r0, #0x78
	lsls r1, r4, #2
	adds r1, r5, r1
	movs r7, #0x8c
	lsls r7, r7, #1
	adds r1, r1, r7
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne .L0814BDA2
	adds r0, r2, #0
	movs r1, #5
	str r3, [sp]
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r5, r0
	ldr r2, .L0814BE40
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r3, [sp]
.L0814BDA2:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r7, sb
	ldrb r7, [r7]
	cmp r4, r7
	blo .L0814BD64
.L0814BDB0:
	lsls r0, r3, #0x10
	lsrs r6, r0, #0x10
	adds r0, r5, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r6, r0
	blo .L0814BD12
.L0814BDBE:
	adds r7, r5, #0
	adds r7, #0x2b
	ldrb r0, [r7]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r5, r0
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x42
	movs r2, #0
	mov sb, r2
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r5, r0
	ldr r3, .L0814BE40
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x43
	strb r0, [r1]
	bl sub_0814D150
	adds r0, r5, #0
	adds r0, #0x30
	movs r1, #1
	mov r8, r1
	mov r2, r8
	strb r2, [r0]
	ldrb r6, [r7]
	adds r0, r6, #0
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r5, r0
	adds r0, r0, r4
	adds r1, r5, #0
	adds r1, #0x2f
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne .L0814BE44
	movs r0, #0
	mov r3, sb
	strh r3, [r5, #0x1a]
	strb r0, [r7]
	strb r0, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x3e
	mov r7, r8
	strb r7, [r0]
	movs r0, #6
	b .L0814BE7A
.L0814BE40: .4byte 0x0000012D
.L0814BE44:
	cmp r6, #0x23
	bne .L0814BE5E
	movs r0, #0
	mov r1, sb
	strh r1, [r5, #0x1a]
	strb r0, [r7]
	strb r0, [r5, #0x1c]
	strb r0, [r5, #0x18]
	adds r1, r5, #0
	adds r1, #0x3e
	strb r0, [r1]
	movs r0, #6
	b .L0814BE7A
.L0814BE5E:
	adds r0, r6, #5
	strb r0, [r7]
	ldrh r0, [r5, #0x1a]
	bl sub_0814C52C
	ldrh r2, [r5, #0x1a]
	adds r0, r0, r2
	strh r0, [r5, #0x1a]
	adds r1, r5, #0
	adds r1, #0x3f
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #5
.L0814BE7A:
	strb r0, [r5, #4]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814BE8C
sub_0814BE8C: @ 0x0814BE8C
.L0814BE8C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r4, .L0814BF68
	movs r0, #0
	mov r8, r0
	mov sb, r0
.L0814BEA0:
	movs r5, #0
	mov r2, r8
	lsls r1, r2, #2
	adds r0, r4, r1
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r6, r1, #0
	movs r1, #1
	add r1, r8
	mov sl, r1
	ldrb r0, [r0]
	cmp r5, r0
	bhs .L0814BEFC
	mov r2, r8
	lsls r0, r2, #1
	ldr r1, .L0814BF6C
	adds r0, r0, r1
	ldrb r7, [r0]
.L0814BEC6:
	mov r2, sb
	str r2, [sp]
	ldrh r0, [r4, #0x32]
	adds r0, #0x63
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	str r7, [sp, #8]
	ldr r0, .L0814BF70
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r4, #0x32]
	adds r0, #7
	strh r0, [r4, #0x32]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, r6
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blo .L0814BEC6
.L0814BEFC:
	movs r5, #0
	adds r0, r4, r6
	ldr r2, .L0814BF74
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r5, r0
	bhs .L0814BF48
	mov r1, r8
	lsls r0, r1, #1
	ldr r2, .L0814BF6C
	adds r0, r0, r2
	ldrb r7, [r0]
.L0814BF14:
	mov r0, sb
	str r0, [sp]
	ldrh r0, [r4, #0x32]
	adds r0, #0x63
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	str r7, [sp, #8]
	ldr r0, .L0814BF78
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r4, #0x32]
	adds r0, #7
	strh r0, [r4, #0x32]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, r6
	ldr r1, .L0814BF74
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blo .L0814BF14
.L0814BF48:
	mov r2, sb
	strh r2, [r4, #0x32]
	mov r1, sl
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #7
	bls .L0814BEA0
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814BF68: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814BF6C: .4byte gUnknown_0879EC04
.L0814BF70: .4byte gUnknown_0814FBFC
.L0814BF74: .4byte 0x0000012D
.L0814BF78: .4byte gUnknown_0814FC0C

	thumb_func_start sub_0814BF7C
sub_0814BF7C: @ 0x0814BF7C
.L0814BF7C:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, .L0814BF90
	ldrh r1, [r4, #0xa]
	adds r2, r1, #0
	cmp r2, #2
	bhi .L0814BF98
	ldr r0, .L0814BF94
	b .L0814BFCC
	.byte 0x00, 0x00
.L0814BF90: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814BF94: .4byte gUnknown_0814FCEC
.L0814BF98:
	subs r0, r1, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814BFAC
	ldr r0, .L0814BFA8
	b .L0814BFCC
	.byte 0x00, 0x00
.L0814BFA8: .4byte gUnknown_0814FD1C
.L0814BFAC:
	subs r0, r1, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814BFC0
	ldr r0, .L0814BFBC
	b .L0814BFCC
	.byte 0x00, 0x00
.L0814BFBC: .4byte gUnknown_0814FD0C
.L0814BFC0:
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814C004
	ldr r0, .L0814BFFC
.L0814BFCC:
	movs r1, #0
	str r1, [sp]
	ldr r3, .L0814C000
	ldrh r1, [r4, #0x10]
	ldrh r2, [r4, #0x1a]
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r4, #0x10]
	ldrh r2, [r4, #0x1a]
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814C08A
	.byte 0x00, 0x00
.L0814BFFC: .4byte gUnknown_0814FCFC
.L0814C000: .4byte gUnknown_0879EAC4
.L0814C004:
	cmp r2, #8
	bls .L0814C08A
	ldr r0, .L0814C078
	movs r5, #0
	str r5, [sp]
	ldr r3, .L0814C07C
	ldrh r1, [r4, #0x10]
	ldrh r2, [r4, #0x1a]
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r4, #0x10]
	ldrh r2, [r4, #0x1a]
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L0814C080
	bl sub_080C51D4
	ldrh r0, [r4, #0xa]
	cmp r0, #0xc
	bls .L0814C08A
	ldrh r0, [r4, #0x10]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x78
	strb r5, [r0]
	ldrh r0, [r4, #0x10]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x7a
	movs r1, #1
	strb r1, [r0]
	ldrh r1, [r4, #0x10]
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne .L0814C084
	strh r5, [r4, #0x10]
	movs r0, #3
	strb r0, [r4, #4]
	b .L0814C08A
	.byte 0x00, 0x00
.L0814C078: .4byte gUnknown_0814FCEC
.L0814C07C: .4byte gUnknown_0879EAC4
.L0814C080: .4byte 0x0000015B
.L0814C084:
	adds r0, r1, #1
	strh r0, [r4, #0x10]
	strh r5, [r4, #0xa]
.L0814C08A:
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0814C098
sub_0814C098: @ 0x0814C098
.L0814C098:
	push {r4, r5, r6, r7, lr}
	ldr r4, .L0814C0A0
	b .L0814C120
	.byte 0x00, 0x00
.L0814C0A0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814C0A4:
	movs r0, #0
	strb r0, [r4, #0x14]
	bl sub_080C2244
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x22]
	ldrh r1, [r4, #0x22]
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r1, r0, #8
	strh r1, [r4, #0x22]
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x2f
	adds r3, r0, #0
	ldrb r0, [r3]
	cmp r2, r0
	bhs .L0814C0F4
	movs r7, #0x8c
	lsls r7, r7, #1
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	movs r6, #1
	adds r1, r3, #0
.L0814C0DA:
	lsls r0, r2, #2
	adds r0, r4, r0
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, r5
	bne .L0814C0E8
	strb r6, [r4, #0x14]
.L0814C0E8:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrb r0, [r1]
	cmp r2, r0
	blo .L0814C0DA
.L0814C0F4:
	ldrb r0, [r4, #0x14]
	cmp r0, #0
	bne .L0814C110
	ldrh r0, [r4, #0x12]
	lsls r0, r0, #2
	adds r0, r4, r0
	ldrh r1, [r4, #0x22]
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	ldrh r0, [r4, #0x12]
	adds r0, #1
	strh r0, [r4, #0x12]
.L0814C110:
	ldrh r0, [r4, #0x12]
	ldrb r3, [r3]
	cmp r0, r3
	bne .L0814C120
	movs r0, #0
	strh r0, [r4, #0x12]
	movs r0, #3
	strb r0, [r4, #4]
.L0814C120:
	ldrb r0, [r4, #4]
	cmp r0, #3
	bne .L0814C0A4
	movs r0, #3
	strb r0, [r4, #4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814C130
sub_0814C130: @ 0x0814C130
.L0814C130:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, .L0814C144
	ldrh r1, [r4, #0xc]
	adds r2, r1, #0
	cmp r2, #2
	bhi .L0814C14C
	ldr r0, .L0814C148
	b .L0814C180
	.byte 0x00, 0x00
.L0814C144: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814C148: .4byte gUnknown_0814FCEC
.L0814C14C:
	subs r0, r1, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814C160
	ldr r0, .L0814C15C
	b .L0814C180
	.byte 0x00, 0x00
.L0814C15C: .4byte gUnknown_0814FD1C
.L0814C160:
	subs r0, r1, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814C174
	ldr r0, .L0814C170
	b .L0814C180
	.byte 0x00, 0x00
.L0814C170: .4byte gUnknown_0814FD0C
.L0814C174:
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0814C1B0
	ldr r0, .L0814C1A8
.L0814C180:
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814C1AC
	ldrh r1, [r4, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r4, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814C222
	.byte 0x00, 0x00
.L0814C1A8: .4byte gUnknown_0814FCFC
.L0814C1AC: .4byte gUnknown_0879E5B0
.L0814C1B0:
	cmp r2, #8
	bls .L0814C222
	ldr r0, .L0814C210
	movs r5, #0
	str r5, [sp]
	ldr r2, .L0814C214
	ldrh r1, [r4, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrh r1, [r4, #0xe]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L0814C218
	bl sub_080C51D4
	ldrh r0, [r4, #0xc]
	cmp r0, #0xc
	bls .L0814C222
	ldrh r0, [r4, #0xe]
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r2, #0x8d
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
	ldrh r1, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne .L0814C21C
	strh r5, [r4, #0xe]
	strh r5, [r4, #0xc]
	movs r0, #7
	strb r0, [r4, #4]
	b .L0814C222
	.byte 0x00, 0x00
.L0814C210: .4byte gUnknown_0814FCEC
.L0814C214: .4byte gUnknown_0879E5B0
.L0814C218: .4byte 0x0000015B
.L0814C21C:
	adds r0, r1, #1
	strh r0, [r4, #0xe]
	strh r5, [r4, #0xc]
.L0814C222:
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0814C230
sub_0814C230: @ 0x0814C230
.L0814C230:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r4, .L0814C254
	ldrh r0, [r4, #0x36]
	cmp r0, #0
	bne .L0814C26C
	ldrh r0, [r4, #0x34]
	cmp r0, #0xd2
	bhi .L0814C26C
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0814C25C
	ldr r0, .L0814C258
	bl sub_080C51D4
	b .L0814C264
.L0814C254: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814C258: .4byte 0x00000163
.L0814C25C:
	movs r0, #0xaf
	lsls r0, r0, #1
	bl sub_080C51D4
.L0814C264:
	adds r1, r4, #0
	adds r1, #0x38
	movs r0, #1
	strb r0, [r1]
.L0814C26C:
	adds r0, r4, #0
	adds r0, #0x38
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #1
	bne .L0814C28A
	ldrh r0, [r4, #0x36]
	adds r0, #1
	strh r0, [r4, #0x36]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bne .L0814C28A
	movs r0, #0
	strb r0, [r6]
.L0814C28A:
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne .L0814C2BC
	ldr r0, .L0814C2B8
	str r1, [sp]
	ldrh r1, [r4, #0x34]
	ldrh r2, [r4, #0x3a]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x3f
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814C2DC
	.byte 0x00, 0x00
.L0814C2B8: .4byte gUnknown_0814FC7C
.L0814C2BC:
	ldr r0, .L0814C2FC
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r4, #0x34]
	ldrh r2, [r4, #0x3c]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x3f
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814C2DC:
	ldrh r1, [r4, #0x34]
	cmp r1, #0
	bne .L0814C304
	movs r2, #0
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r4, #0x34]
	strh r1, [r4, #0x36]
	ldrb r0, [r5]
	cmp r0, #1
	bne .L0814C300
	strb r2, [r4, #0x18]
	movs r0, #8
	strb r0, [r4, #4]
	b .L0814C304
	.byte 0x00, 0x00
.L0814C2FC: .4byte gUnknown_0814FC54
.L0814C300:
	strb r2, [r4, #0x18]
	strb r2, [r4, #4]
.L0814C304:
	ldrb r0, [r6]
	cmp r0, #0
	bne .L0814C310
	ldrh r0, [r4, #0x34]
	subs r0, #4
	strh r0, [r4, #0x34]
.L0814C310:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_0814C318
sub_0814C318: @ 0x0814C318
.L0814C318:
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r4, .L0814C368
	movs r0, #0xe0
	lsls r0, r0, #2
	bl Font_ResetGlyphSpriteCache
	ldr r6, .L0814C36C
	adds r5, r4, #0
	adds r5, #0x3f
	ldrb r1, [r5]
	lsls r1, r1, #2
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r1, r6
	ldrh r0, [r1]
	bl sub_080C32FC
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0814C374
	ldrb r2, [r4, #5]
	movs r0, #0xb4
	muls r0, r2, r0
	ldr r1, .L0814C370
	adds r0, r0, r1
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrh r3, [r1, #0x26]
	adds r3, #0x63
	movs r1, #0x1d
	str r1, [sp]
	movs r1, #0xa
	b .L0814C3AA
	.byte 0x00, 0x00
.L0814C368: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814C36C: .4byte gUnknown_0879EEE4
.L0814C370: .4byte gUnknown_0879ECB6
.L0814C374:
	ldrb r0, [r5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi .L0814C3BC
	ldrb r4, [r4, #5]
	movs r0, #0xb4
	muls r0, r4, r0
	ldrb r2, [r5]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r3, .L0814C3B8
	adds r1, r1, r3
	adds r0, r0, r1
	lsls r2, r2, #2
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r2, r2, r1
	adds r2, r2, r6
	ldrh r3, [r2, #2]
	adds r3, #0x64
	movs r1, #0x1d
	str r1, [sp]
	movs r1, #0xc
.L0814C3AA:
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	bl sub_0814ADAC
	b .L0814C3F0
	.byte 0x00, 0x00
.L0814C3B8: .4byte gUnknown_0879EC14
.L0814C3BC:
	ldrb r4, [r4, #5]
	movs r0, #0xb4
	muls r0, r4, r0
	ldrb r2, [r5]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r3, .L0814C3F8
	adds r1, r1, r3
	adds r0, r0, r1
	lsls r2, r2, #2
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r2, r2, r1
	adds r2, r2, r6
	ldrh r3, [r2, #2]
	adds r3, #0x64
	movs r1, #0x1d
	str r1, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	bl sub_0814ADAC
.L0814C3F0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0814C3F8: .4byte gUnknown_0879EC14

	thumb_func_start sub_0814C3FC
sub_0814C3FC: @ 0x0814C3FC
.L0814C3FC:
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0xc
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	bl NumberToDigits
	mov sb, r0
	ldr r0, .L0814C478
	mov sl, r0
	mov r1, sb
	ldrb r0, [r1]
	lsls r0, r0, #2
	add r0, sl
	ldr r0, [r0]
	movs r1, #0
	mov r8, r1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0xff
	ands r5, r1
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl Sprite_Draw
	mov r1, sb
	ldrb r0, [r1, #1]
	lsls r0, r0, #2
	add r0, sl
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	subs r4, #8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0814C478: .4byte gUnknown_0879EF84

	thumb_func_start sub_0814C47C
sub_0814C47C: @ 0x0814C47C
.L0814C47C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, .L0814C518
	mov sl, r0
	movs r1, #0
	adds r0, #0x2e
	ldrb r2, [r0]
	cmp r1, r2
	bhs .L0814C508
	movs r2, #0x2f
	add r2, sl
	mov sb, r2
.L0814C49C:
	movs r4, #0
	adds r7, r1, #1
	mov r0, sb
	ldrb r0, [r0]
	cmp r4, r0
	bhs .L0814C4FC
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r6, r0, #2
	movs r5, #0xff
	ldr r1, .L0814C51C
	mov r8, r1
.L0814C4B4:
	lsls r0, r4, #2
	adds r3, r0, r6
	mov r2, sl
	adds r0, r2, r3
	ldr r2, .L0814C520
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq .L0814C4EE
	adds r0, #1
	ands r0, r5
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldr r2, .L0814C524
	adds r2, r3, r2
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r2, [r2, #2]
	adds r1, r5, #0
	ands r1, r2
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814C4EE:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r0, sb
	ldrb r0, [r0]
	cmp r4, r0
	blo .L0814C4B4
.L0814C4FC:
	lsls r0, r7, #0x10
	lsrs r1, r0, #0x10
	ldr r2, .L0814C528
	ldrb r2, [r2]
	cmp r1, r2
	blo .L0814C49C
.L0814C508:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814C518: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814C51C: .4byte gUnknown_0879EFAC
.L0814C520: .4byte 0x0000016D
.L0814C524: .4byte gUnknown_0879EFBC
.L0814C528: .4byte 0x0203A482 @ EWRAM+0x3A482

	thumb_func_start sub_0814C52C
sub_0814C52C: @ 0x0814C52C
.L0814C52C:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi .L0814C576
	lsls r0, r0, #2
	ldr r1, .L0814C54C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L0814C54C: .4byte gUnknown_0814C550
	.global gUnknown_0814C550
gUnknown_0814C550:
.L0814C550: @ jump table
	.4byte .L0814C564
	.4byte .L0814C568
	.4byte .L0814C56C
	.4byte .L0814C570
	.4byte .L0814C574
.L0814C564:
	movs r4, #5
	b .L0814C576
.L0814C568:
	movs r4, #4
	b .L0814C576
.L0814C56C:
	movs r4, #3
	b .L0814C576
.L0814C570:
	movs r4, #2
	b .L0814C576
.L0814C574:
	movs r4, #1
.L0814C576:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0814C580
sub_0814C580: @ 0x0814C580
.L0814C580:
	push {r4, r5, r6, r7, lr}
	ldr r7, .L0814C5F8
	movs r6, #0
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	cmp r6, r2
	bhs .L0814C5B2
	subs r0, #4
	ldrb r3, [r0]
	ldr r4, .L0814C5FC
.L0814C598:
	adds r0, r3, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r0, #0x78
	ldrb r5, [r0]
	adds r0, r5, r4
	ldrb r0, [r0]
	orrs r6, r0
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, r2
	blo .L0814C598
.L0814C5B2:
	adds r4, r7, #0
	adds r4, #0x2b
	ldrb r0, [r4]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r7, #0
	adds r1, #0x58
	adds r1, r1, r0
	strb r6, [r1]
	movs r5, #0
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	adds r7, #0x50
	cmp r5, r0
	bhs .L0814C60C
	adds r2, r0, #0
	movs r3, #1
.L0814C5DE:
	adds r0, r6, #0
	ands r0, r3
	cmp r0, #0
	beq .L0814C600
	lsrs r6, r6, #1
	movs r0, #0x80
	orrs r6, r0
	lsls r0, r6, #0x18
	lsrs r6, r0, #0x18
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b .L0814C602
.L0814C5F8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814C5FC: .4byte gUnknown_0879F05C
.L0814C600:
	lsrs r6, r6, #1
.L0814C602:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, r2
	blo .L0814C5DE
.L0814C60C:
	ldrb r0, [r4]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r7, r0
	strb r5, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814C624
sub_0814C624: @ 0x0814C624
.L0814C624:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	ldr r0, .L0814C698
	mov r8, r0
	movs r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r4, r0
	bhs .L0814C6B6
.L0814C644:
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq .L0814C6A0
	lsrs r3, r3, #1
	movs r0, #0x80
	orrs r3, r0
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
	movs r1, #0
	mov r2, r8
	adds r2, #0x2f
	movs r0, #0x2e
	add r0, r8
	mov ip, r0
	adds r6, r4, #1
	ldrb r0, [r2]
	cmp r1, r0
	bhs .L0814C6AA
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r5, r0, #2
	ldr r7, .L0814C69C
	adds r4, r2, #0
.L0814C674:
	lsls r0, r1, #2
	adds r0, r0, r5
	add r0, r8
	adds r0, r0, r7
	ldrb r2, [r0]
	cmp r2, #0xff
	beq .L0814C68A
	cmp r2, #2
	beq .L0814C68A
	mov r2, sb
	strb r2, [r0]
.L0814C68A:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldrb r0, [r4]
	cmp r1, r0
	blo .L0814C674
	b .L0814C6AA
.L0814C698: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814C69C: .4byte 0x0000016D
.L0814C6A0:
	lsrs r3, r3, #1
	movs r1, #0x2e
	add r1, r8
	mov ip, r1
	adds r6, r4, #1
.L0814C6AA:
	lsls r0, r6, #0x10
	lsrs r4, r0, #0x10
	mov r2, ip
	ldrb r2, [r2]
	cmp r4, r2
	blo .L0814C644
.L0814C6B6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814C6C4
sub_0814C6C4: @ 0x0814C6C4
.L0814C6C4:
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r4, .L0814C6F0
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, #0x58
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r1, r5, #0
	bl sub_0814C624
	pop {r4, r5}
	pop {r0}
	bx r0
.L0814C6F0: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0814C6F4
sub_0814C6F4: @ 0x0814C6F4
.L0814C6F4:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r7, .L0814C744
	adds r0, r7, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r7, #0
	adds r1, #0x58
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r4, #0
	adds r0, r7, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r4, r0
	bhs .L0814C798
.L0814C728:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq .L0814C748
	lsrs r2, r2, #1
	movs r0, #0x80
	orrs r2, r0
	lsls r0, r2, #0x18
	lsrs r2, r0, #0x18
	movs r0, #0x2e
	adds r0, r0, r7
	mov ip, r0
	adds r6, r4, #1
	b .L0814C78C
.L0814C744: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814C748:
	lsrs r2, r2, #1
	movs r3, #0
	adds r1, r7, #0
	adds r1, #0x2f
	movs r0, #0x2e
	adds r0, r0, r7
	mov ip, r0
	adds r6, r4, #1
	ldrb r0, [r1]
	cmp r3, r0
	bhs .L0814C78C
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r5, r0, #2
	ldr r0, .L0814C7A4
	mov r8, r0
	adds r4, r1, #0
.L0814C76A:
	lsls r0, r3, #2
	adds r0, r0, r5
	adds r0, r7, r0
	add r0, r8
	ldrb r1, [r0]
	cmp r1, #0xff
	beq .L0814C780
	cmp r1, #2
	beq .L0814C780
	mov r1, sb
	strb r1, [r0]
.L0814C780:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrb r0, [r4]
	cmp r3, r0
	blo .L0814C76A
.L0814C78C:
	lsls r0, r6, #0x10
	lsrs r4, r0, #0x10
	mov r1, ip
	ldrb r1, [r1]
	cmp r4, r1
	blo .L0814C728
.L0814C798:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814C7A4: .4byte 0x0000016D

	thumb_func_start sub_0814C7A8
sub_0814C7A8: @ 0x0814C7A8
.L0814C7A8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r6, .L0814C7DC
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r6, #0
	adds r1, #0x58
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r5, #0
	adds r0, r6, #0
	adds r0, #0x2e
	b .L0814C864
	.byte 0x00, 0x00
.L0814C7DC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814C7E0:
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq .L0814C850
	lsrs r3, r3, #1
	movs r0, #0x80
	orrs r3, r0
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
	movs r4, #0
	adds r0, r6, #0
	adds r0, #0x2f
	movs r1, #0x2e
	adds r1, r1, r6
	mov sb, r1
	adds r7, r0, #0
	adds r0, r5, #1
	mov r8, r0
	ldrb r1, [r7]
	cmp r4, r1
	bhs .L0814C85C
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	mov ip, r0
.L0814C812:
	lsls r0, r4, #2
	add r0, ip
	adds r0, r6, r0
	ldr r1, .L0814C84C
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r0, #0x78
	ldrb r0, [r0]
	cmp r0, r5
	bne .L0814C83E
	cmp r1, #0xff
	beq .L0814C83E
	cmp r1, #2
	beq .L0814C83E
	mov r0, sl
	strb r0, [r2]
.L0814C83E:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldrb r1, [r7]
	cmp r4, r1
	blo .L0814C812
	b .L0814C85C
.L0814C84C: .4byte 0x0000016D
.L0814C850:
	lsrs r3, r3, #1
	movs r0, #0x2e
	adds r0, r0, r6
	mov sb, r0
	adds r5, #1
	mov r8, r5
.L0814C85C:
	mov r1, r8
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	mov r0, sb
.L0814C864:
	ldrb r0, [r0]
	cmp r5, r0
	blo .L0814C7E0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814C878
sub_0814C878: @ 0x0814C878
.L0814C878:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r6, .L0814C8AC
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r6, #0
	adds r1, #0x58
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r5, #0
	adds r0, r6, #0
	adds r0, #0x2e
	b .L0814C934
	.byte 0x00, 0x00
.L0814C8AC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814C8B0:
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq .L0814C920
	lsrs r3, r3, #1
	movs r0, #0x80
	orrs r3, r0
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
	movs r4, #0
	adds r0, r6, #0
	adds r0, #0x2f
	movs r1, #0x2e
	adds r1, r1, r6
	mov sb, r1
	adds r7, r0, #0
	adds r0, r5, #1
	mov r8, r0
	ldrb r1, [r7]
	cmp r4, r1
	bhs .L0814C92C
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	mov ip, r0
.L0814C8E2:
	lsls r0, r4, #2
	add r0, ip
	adds r0, r6, r0
	ldr r1, .L0814C91C
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r0, #0x78
	ldrb r0, [r0]
	cmp r0, r5
	beq .L0814C90E
	cmp r1, #0xff
	beq .L0814C90E
	cmp r1, #2
	beq .L0814C90E
	mov r0, sl
	strb r0, [r2]
.L0814C90E:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldrb r1, [r7]
	cmp r4, r1
	blo .L0814C8E2
	b .L0814C92C
.L0814C91C: .4byte 0x0000016D
.L0814C920:
	lsrs r3, r3, #1
	movs r0, #0x2e
	adds r0, r0, r6
	mov sb, r0
	adds r5, #1
	mov r8, r5
.L0814C92C:
	mov r1, r8
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	mov r0, sb
.L0814C934:
	ldrb r0, [r0]
	cmp r5, r0
	blo .L0814C8B0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814C948
sub_0814C948: @ 0x0814C948
.L0814C948:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, .L0814C9E0
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r4, #0
	adds r1, #0x58
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r0, #0
	mov sb, r0
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp sb, r0
	bhs .L0814CA02
	ldr r1, .L0814C9E4
	mov sl, r1
.L0814C980:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq .L0814C9E8
	lsrs r2, r2, #1
	movs r0, #0x80
	orrs r2, r0
	lsls r0, r2, #0x18
	lsrs r2, r0, #0x18
	movs r5, #0
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	movs r0, #0x2e
	adds r0, r0, r4
	mov ip, r0
	mov r7, r8
	adds r7, #1
	cmp r5, r1
	bhs .L0814C9CE
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r6, [r0]
.L0814C9B0:
	adds r0, r6, r3
	lsls r0, r0, #2
	adds r0, r4, r0
	adds r0, #0x78
	ldrb r0, [r0]
	cmp r8, r0
	bne .L0814C9C4
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L0814C9C4:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r1
	blo .L0814C9B0
.L0814C9CE:
	cmp r5, #1
	bls .L0814C9F4
	mov r0, r8
	add r0, sl
	ldrb r0, [r0]
	mov r1, sb
	orrs r1, r0
	mov sb, r1
	b .L0814C9F4
.L0814C9E0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814C9E4: .4byte gUnknown_0879F05C
.L0814C9E8:
	lsrs r2, r2, #1
	movs r0, #0x2e
	adds r0, r0, r4
	mov ip, r0
	mov r7, r8
	adds r7, #1
.L0814C9F4:
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r1, ip
	ldrb r1, [r1]
	cmp r8, r1
	blo .L0814C980
.L0814CA02:
	adds r0, r4, #0
	adds r0, #0x62
	mov r1, sb
	strb r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814CA18
sub_0814CA18: @ 0x0814CA18
.L0814CA18:
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, .L0814CA30
	adds r0, #0x62
	ldrb r0, [r0]
	bl sub_0814C624
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814CA30: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0814CA34
sub_0814CA34: @ 0x0814CA34
.L0814CA34:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	ldr r0, .L0814CAA8
	mov r8, r0
	movs r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r4, r0
	bhs .L0814CAC6
.L0814CA54:
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq .L0814CAB0
	lsrs r3, r3, #1
	movs r0, #0x80
	orrs r3, r0
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
	movs r1, #0
	mov r2, r8
	adds r2, #0x2f
	movs r0, #0x2e
	add r0, r8
	mov ip, r0
	adds r6, r4, #1
	ldrb r0, [r2]
	cmp r1, r0
	bhs .L0814CABA
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r5, r0, #2
	ldr r7, .L0814CAAC
	adds r4, r2, #0
.L0814CA84:
	lsls r0, r1, #2
	adds r0, r0, r5
	add r0, r8
	adds r0, r0, r7
	ldrb r2, [r0]
	cmp r2, #0xff
	beq .L0814CA9A
	cmp r2, #2
	beq .L0814CA9A
	mov r2, sb
	strb r2, [r0]
.L0814CA9A:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldrb r0, [r4]
	cmp r1, r0
	blo .L0814CA84
	b .L0814CABA
.L0814CAA8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814CAAC: .4byte 0x0000016D
.L0814CAB0:
	lsrs r3, r3, #1
	movs r1, #0x2e
	add r1, r8
	mov ip, r1
	adds r6, r4, #1
.L0814CABA:
	lsls r0, r6, #0x10
	lsrs r4, r0, #0x10
	mov r2, ip
	ldrb r2, [r2]
	cmp r4, r2
	blo .L0814CA54
.L0814CAC6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814CAD4
sub_0814CAD4: @ 0x0814CAD4
.L0814CAD4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r6, .L0814CB84
	movs r0, #0
	mov sl, r0
	mov sb, r0
	movs r5, #0
	adds r0, r6, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp sb, r0
	bhs .L0814CB66
	movs r1, #0x2f
	adds r1, r1, r6
	mov r8, r1
	ldrb r2, [r1]
	str r2, [sp]
.L0814CAFE:
	movs r1, #0
	movs r0, #0x2e
	adds r0, r0, r6
	mov ip, r0
	adds r7, r5, #1
	ldr r2, [sp]
	cmp r1, r2
	bhs .L0814CB3C
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r2, r0, #2
	adds r0, r6, r2
	ldr r4, .L0814CB88
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0814CB3C
	mov r0, r8
	ldrb r3, [r0]
.L0814CB24:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r3
	bhs .L0814CB3C
	lsls r0, r1, #2
	adds r0, r0, r2
	adds r0, r6, r0
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0xff
	beq .L0814CB24
.L0814CB3C:
	mov r2, r8
	ldrb r2, [r2]
	cmp r1, r2
	bne .L0814CB5A
	ldr r0, .L0814CB8C
	adds r0, r5, r0
	ldrb r0, [r0]
	mov r1, sl
	orrs r1, r0
	mov sl, r1
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
.L0814CB5A:
	lsls r0, r7, #0x10
	lsrs r5, r0, #0x10
	mov r2, ip
	ldrb r2, [r2]
	cmp r5, r2
	blo .L0814CAFE
.L0814CB66:
	adds r0, r6, #0
	adds r0, #0x66
	mov r1, sl
	strb r1, [r0]
	subs r0, #1
	mov r2, sb
	strb r2, [r0]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814CB84: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814CB88: .4byte 0x0000016D
.L0814CB8C: .4byte gUnknown_0879F05C

	thumb_func_start sub_0814CB90
sub_0814CB90: @ 0x0814CB90
.L0814CB90:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, .L0814CBFC
	mov r8, r0
	movs r1, #0
	mov ip, r1
	movs r6, #0
	movs r2, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r6, r0
	bhs .L0814CC1A
	movs r1, #0x2f
	add r1, r8
	mov sb, r1
	ldrb r1, [r1]
	str r1, [sp]
	mov sl, r0
.L0814CBBC:
	movs r1, #0
	adds r7, r2, #1
	ldr r0, [sp]
	cmp r1, r0
	bhs .L0814CC12
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r4, r0, #2
	ldr r0, .L0814CC00
	adds r3, r2, r0
	mov r0, sb
	ldrb r2, [r0]
	ldr r5, .L0814CC04
.L0814CBD6:
	lsls r0, r1, #2
	adds r0, r0, r4
	add r0, r8
	adds r0, r0, r5
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi .L0814CC08
	ldrb r0, [r3]
	mov r1, ip
	orrs r1, r0
	mov ip, r1
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	b .L0814CC12
	.byte 0x00, 0x00
.L0814CBFC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814CC00: .4byte gUnknown_0879F05C
.L0814CC04: .4byte 0x0000016D
.L0814CC08:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r2
	blo .L0814CBD6
.L0814CC12:
	lsls r0, r7, #0x10
	lsrs r2, r0, #0x10
	cmp r2, sl
	blo .L0814CBBC
.L0814CC1A:
	mov r0, r8
	adds r0, #0x64
	mov r1, ip
	strb r1, [r0]
	subs r0, #1
	strb r6, [r0]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814CC38
sub_0814CC38: @ 0x0814CC38
.L0814CC38:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	ldr r0, .L0814CD00
	mov sb, r0
	movs r1, #0
	str r1, [sp, #4]
	mov r8, r1
	mov ip, r1
	movs r5, #0
	mov r3, sb
	adds r3, #0x2f
	ldrb r2, [r3]
	cmp r8, r2
	bhs .L0814CCE0
.L0814CC62:
	ldr r1, [sp]
	adds r0, r1, r5
	lsls r0, r0, #2
	add r0, sb
	adds r2, r0, #0
	adds r2, #0x78
	ldrb r1, [r2]
	movs r4, #0
	adds r0, r5, #1
	mov sl, r0
	ldrb r3, [r3]
	cmp r4, r3
	bhs .L0814CCD2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r7, r0, #2
	adds r6, r2, #0
	ldr r2, .L0814CD04
	ldr r1, .L0814CD08
	ldrb r3, [r1]
.L0814CC8A:
	lsls r0, r4, #2
	adds r0, r0, r7
	add r0, sb
	ldr r1, .L0814CD0C
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi .L0814CCC8
	ldrb r0, [r6]
	adds r0, r0, r2
	ldrb r1, [r0]
	mov r0, ip
	ands r0, r1
	cmp r0, #0
	bne .L0814CCD2
	mov r0, ip
	orrs r0, r1
	mov ip, r0
	ldr r0, [sp, #4]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	adds r0, r5, r2
	ldrb r0, [r0]
	mov r1, r8
	orrs r1, r0
	mov r8, r1
.L0814CCC8:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r3
	blo .L0814CC8A
.L0814CCD2:
	mov r2, sl
	lsls r0, r2, #0x10
	lsrs r5, r0, #0x10
	ldr r3, .L0814CD08
	ldrb r0, [r3]
	cmp r5, r0
	blo .L0814CC62
.L0814CCE0:
	mov r0, sb
	adds r0, #0x63
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r0]
	adds r0, #1
	mov r2, r8
	strb r2, [r0]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814CD00: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814CD04: .4byte gUnknown_0879F05C
.L0814CD08: .4byte 0x0203A483 @ EWRAM+0x3A483
.L0814CD0C: .4byte 0x0000016D

	thumb_func_start sub_0814CD10
sub_0814CD10: @ 0x0814CD10
.L0814CD10:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r4, .L0814CD54
	movs r1, #0
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r1, r0
	bhs .L0814CD68
	adds r5, r0, #0
	ldr r7, .L0814CD58
.L0814CD2E:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq .L0814CD5C
	lsrs r2, r2, #1
	movs r0, #0x80
	orrs r2, r0
	lsls r0, r2, #0x18
	lsrs r2, r0, #0x18
	adds r0, r6, r3
	lsls r0, r0, #2
	adds r0, r4, r0
	adds r0, #0x78
	ldrb r0, [r0]
	adds r0, r0, r7
	ldrb r0, [r0]
	orrs r1, r0
	b .L0814CD5E
	.byte 0x00, 0x00
.L0814CD54: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814CD58: .4byte gUnknown_0879F05C
.L0814CD5C:
	lsrs r2, r2, #1
.L0814CD5E:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r5
	blo .L0814CD2E
.L0814CD68:
	adds r0, r1, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0814CD70
sub_0814CD70: @ 0x0814CD70
.L0814CD70:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, .L0814CE40
	mov ip, r0
	movs r2, #0
	mov r3, ip
	adds r3, #0x2f
	ldrb r1, [r3]
	cmp r2, r1
	bhs .L0814CDC4
	mov r7, ip
	adds r7, #0x67
	mov r6, ip
	adds r6, #0x6c
.L0814CD9C:
	adds r1, r7, r2
	adds r0, r5, r2
	lsls r0, r0, #2
	add r0, ip
	adds r0, #0x78
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r6, r2
	adds r0, r4, r2
	lsls r0, r0, #2
	add r0, ip
	adds r0, #0x78
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrb r0, [r3]
	cmp r2, r0
	blo .L0814CD9C
.L0814CDC4:
	movs r1, #0
	mov sb, r1
	movs r2, #0
	str r2, [sp]
	mov sl, r2
	mov r0, ip
	adds r0, #0x2f
	adds r6, r0, #0
	mov r2, ip
	adds r2, #0x61
	str r2, [sp, #0x14]
	adds r2, #0x10
	str r2, [sp, #4]
	adds r2, #1
	str r2, [sp, #8]
	subs r2, #0x12
	str r2, [sp, #0x10]
	ldrb r2, [r0]
	cmp sl, r2
	bhs .L0814CE60
.L0814CDEC:
	movs r3, #0
	adds r2, r1, #1
	str r2, [sp, #0xc]
	ldrb r0, [r0]
	cmp r3, r0
	bhs .L0814CE52
	ldr r0, .L0814CE44
	mov r8, r0
	mov r0, ip
	adds r0, #0x6c
	adds r5, r0, r1
	mov r2, r8
	adds r7, r1, r2
	ldrb r4, [r6]
.L0814CE08:
	mov r1, r8
	adds r0, r3, r1
	ldrb r2, [r0]
	adds r0, r2, #0
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	bne .L0814CE48
	mov r0, ip
	adds r0, #0x67
	adds r0, r0, r3
	ldrb r1, [r5]
	ldrb r0, [r0]
	cmp r1, r0
	bne .L0814CE48
	mov r0, sb
	orrs r0, r2
	mov sb, r0
	ldrb r0, [r7]
	ldr r1, [sp]
	orrs r1, r0
	str r1, [sp]
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	b .L0814CE52
.L0814CE40: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814CE44: .4byte gUnknown_0879F05C
.L0814CE48:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r4
	blo .L0814CE08
.L0814CE52:
	ldr r2, [sp, #0xc]
	lsls r0, r2, #0x10
	lsrs r1, r0, #0x10
	adds r0, r6, #0
	ldrb r2, [r6]
	cmp r1, r2
	blo .L0814CDEC
.L0814CE60:
	mov r1, sb
	mvns r0, r1
	ldr r2, [sp, #0x14]
	strb r0, [r2]
	ldr r1, [sp, #4]
	strb r0, [r1]
	ldr r2, [sp]
	mvns r0, r2
	ldr r1, [sp, #8]
	strb r0, [r1]
	ldrb r0, [r6]
	mov r2, sl
	subs r0, r0, r2
	ldr r1, [sp, #0x10]
	strb r0, [r1]
	ldrb r0, [r1]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0814CE90
sub_0814CE90: @ 0x0814CE90
.L0814CE90:
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_0814C624
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814CEA4
sub_0814CEA4: @ 0x0814CEA4
.L0814CEA4:
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_0814C624
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814CEB8
sub_0814CEB8: @ 0x0814CEB8
.L0814CEB8:
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_0814C624
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814CECC
sub_0814CECC: @ 0x0814CECC
.L0814CECC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, .L0814CF2C
	mov r8, r0
	movs r1, #0
	mov sl, r1
	movs r6, #0
	str r6, [sp]
	movs r2, #0
	adds r0, #0x2e
	ldrb r1, [r0]
	cmp r2, r1
	bhs .L0814CFC2
	ldr r6, .L0814CF30
	mov sb, r6
.L0814CEF2:
	movs r7, #0
	movs r0, #0
	mov ip, r0
	movs r5, #0
	adds r1, r2, #1
	str r1, [sp, #4]
	ldr r6, .L0814CF34
	ldrb r6, [r6]
	cmp r7, r6
	bhs .L0814CF8E
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r3, r0, #2
	ldr r4, .L0814CF34
	adds r6, r0, #0
.L0814CF10:
	lsls r0, r5, #2
	adds r0, r0, r3
	add r0, r8
	add r0, sb
	ldrb r0, [r0]
	adds r1, r0, #0
	cmp r0, #0xff
	bne .L0814CF38
	mov r0, ip
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	b .L0814CF82
.L0814CF2C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814CF30: .4byte 0x0000016D
.L0814CF34: .4byte 0x0203A483 @ EWRAM+0x3A483
.L0814CF38:
	cmp r0, #1
	bne .L0814CF50
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	b .L0814CF82
.L0814CF50:
	cmp r1, #2
	bne .L0814CF82
	movs r2, #0
	ldrb r0, [r4]
	cmp r2, r0
	bhs .L0814CF8E
	lsls r3, r6, #2
.L0814CF5E:
	lsls r0, r2, #2
	adds r0, r0, r3
	add r0, r8
	mov r6, sb
	adds r1, r0, r6
	ldrb r0, [r1]
	cmp r0, #2
	beq .L0814CF74
	movs r6, #0xff
	orrs r0, r6
	strb r0, [r1]
.L0814CF74:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrb r0, [r4]
	cmp r2, r0
	blo .L0814CF5E
	b .L0814CF8E
.L0814CF82:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrb r1, [r4]
	cmp r5, r1
	blo .L0814CF10
.L0814CF8E:
	ldr r6, .L0814CFD4
	ldrb r0, [r6]
	cmp r5, r0
	bne .L0814CFB4
	subs r0, #1
	cmp ip, r0
	bne .L0814CFB4
	cmp r7, #1
	bne .L0814CFB4
	mov r1, sl
	lsls r0, r1, #2
	add r0, sl
	ldr r6, [sp]
	adds r0, r0, r6
	lsls r0, r0, #2
	add r0, r8
	add r0, sb
	movs r1, #2
	strb r1, [r0]
.L0814CFB4:
	ldr r1, [sp, #4]
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	ldr r6, .L0814CFD8
	ldrb r6, [r6]
	cmp r2, r6
	blo .L0814CEF2
.L0814CFC2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814CFD4: .4byte 0x0203A483 @ EWRAM+0x3A483
.L0814CFD8: .4byte 0x0203A482 @ EWRAM+0x3A482

	thumb_func_start sub_0814CFDC
sub_0814CFDC: @ 0x0814CFDC
.L0814CFDC:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	ldr r5, .L0814D04C
	movs r4, #0
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	adds r3, #0x2e
	ldrb r3, [r3]
	cmp r1, r3
	bhs .L0814D034
	lsls r6, r0, #2
	ldr r0, .L0814D050
	mov r8, r0
	ldr r7, .L0814D054
	mov ip, r7
.L0814D00A:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r0, r5, r0
	add r0, ip
	ldrb r0, [r0]
	cmp r0, sb
	bne .L0814D02A
	mov r7, r8
	adds r0, r2, r7
	ldrb r0, [r0]
	orrs r4, r0
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
.L0814D02A:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r3
	blo .L0814D00A
.L0814D034:
	adds r0, r5, #0
	adds r0, #0x73
	strb r4, [r0]
	adds r0, #1
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814D04C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814D050: .4byte gUnknown_0879F05C
.L0814D054: .4byte 0x0000016D

	thumb_func_start sub_0814D058
sub_0814D058: @ 0x0814D058
.L0814D058:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r2, .L0814D0A4
	movs r1, #0
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r3, [r3]
	cmp r1, r3
	bhs .L0814D0BE
	lsls r5, r0, #2
.L0814D076:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L0814D0AC
	lsrs r4, r4, #1
	movs r0, #0x80
	orrs r4, r0
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r0, r2, r0
	ldr r7, .L0814D0A8
	adds r3, r0, r7
	ldrb r0, [r3]
	cmp r0, #0xff
	beq .L0814D0AE
	cmp r0, #2
	beq .L0814D0AE
	strb r6, [r3]
	b .L0814D0AE
.L0814D0A4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814D0A8: .4byte 0x0000016D
.L0814D0AC:
	lsrs r4, r4, #1
.L0814D0AE:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r2, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r1, r0
	blo .L0814D076
.L0814D0BE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814D0C4
sub_0814D0C4: @ 0x0814D0C4
.L0814D0C4:
	push {r4, r5, r6, lr}
	ldr r5, .L0814D0CC
	movs r4, #0
	b .L0814D102
.L0814D0CC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814D0D0:
	adds r0, r4, #0
	movs r1, #0xff
	bl sub_0814CFDC
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r1, [r0]
	subs r0, #0x46
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne .L0814D0FC
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r4, #0
	movs r2, #2
	bl sub_0814D058
.L0814D0FC:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
.L0814D102:
	adds r0, r5, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r4, r0
	blo .L0814D0D0
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x2f
	adds r6, r0, #0
	b .L0814D142
.L0814D116:
	adds r0, r4, #0
	movs r1, #2
	bl sub_0814CFDC
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0814D13C
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r4, #0
	movs r2, #0xff
	bl sub_0814D058
.L0814D13C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
.L0814D142:
	ldrb r0, [r6]
	cmp r4, r0
	blo .L0814D116
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814D150
sub_0814D150: @ 0x0814D150
.L0814D150:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r6, .L0814D1C0
	adds r4, r6, #0
	adds r4, #0x2b
	ldrb r0, [r4]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r5, r6, #0
	adds r5, #0x48
	adds r0, r0, r5
	adds r7, r6, #0
	adds r7, #0x42
	adds r1, r6, #0
	adds r1, #0x43
	ldrb r1, [r1]
	ldrb r2, [r7]
	adds r1, r1, r2
	strb r1, [r0]
	bl sub_0814C580
	ldrb r0, [r4]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r0, r6, #0
	adds r0, #0x50
	adds r3, r2, r0
	adds r1, r6, #0
	adds r1, #0x2f
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bne .L0814D1E0
	adds r0, r2, r5
	ldrb r2, [r0]
	cmp r2, r1
	bne .L0814D1C4
	movs r0, #1
	bl sub_0814C6C4
	movs r0, #0xff
	bl sub_0814C6F4
	str r4, [sp, #0xc]
	b .L0814D244
	.byte 0x00, 0x00
.L0814D1C0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814D1C4:
	ldrb r0, [r6, #5]
	cmp r0, #2
	beq .L0814D1D2
	str r4, [sp, #0xc]
	cmp r2, #1
	bne .L0814D244
	b .L0814D1D8
.L0814D1D2:
	str r4, [sp, #0xc]
	cmp r2, #2
	bne .L0814D244
.L0814D1D8:
	movs r0, #1
	bl sub_0814C6F4
	b .L0814D244
.L0814D1E0:
	adds r2, r2, r5
	ldrb r0, [r2]
	cmp r0, r1
	bne .L0814D1F0
	movs r0, #1
	bl sub_0814C6C4
	b .L0814D212
.L0814D1F0:
	cmp r0, #0
	bne .L0814D1FC
	movs r0, #0xff
	bl sub_0814C6C4
	b .L0814D212
.L0814D1FC:
	ldrb r0, [r6, #5]
	cmp r0, #2
	bne .L0814D212
	ldrb r0, [r3]
	ldrb r1, [r2]
	subs r0, r0, r1
	cmp r0, #3
	bne .L0814D212
	movs r0, #1
	bl sub_0814C6F4
.L0814D212:
	adds r4, r6, #0
	adds r4, #0x2b
	ldrb r0, [r4]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r6, #0
	adds r1, #0x50
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r1, [r1]
	str r4, [sp, #0xc]
	adds r7, r0, #0
	ldrb r3, [r7]
	cmp r1, r3
	bne .L0814D244
	movs r0, #1
	bl sub_0814C7A8
	movs r0, #0xff
	bl sub_0814C878
.L0814D244:
	adds r0, r6, #0
	adds r0, #0x43
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne .L0814D28C
	ldrb r0, [r7]
	cmp r0, #0
	beq .L0814D286
	movs r0, #0xff
	bl sub_0814C878
	ldr r4, [sp, #0xc]
	ldrb r0, [r4]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r6, #0
	adds r1, #0x50
	adds r1, r1, r0
	adds r2, r6, #0
	adds r2, #0x2f
	ldrb r0, [r1]
	ldrb r2, [r2]
	cmp r0, r2
	beq .L0814D286
	bl sub_0814C948
	movs r0, #0xff
	bl sub_0814CA18
.L0814D286:
	ldrb r0, [r5]
	cmp r0, #0
	beq .L0814D298
.L0814D28C:
	ldrb r0, [r7]
	cmp r0, #0
	bne .L0814D298
	movs r0, #0xff
	bl sub_0814C7A8
.L0814D298:
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne .L0814D2AC
	b .L0814D65C
.L0814D2AC:
	adds r5, r6, #0
	adds r5, #0x48
	adds r0, r5, r0
	ldrb r0, [r0]
	adds r1, r6, #0
	adds r1, #0x46
	strb r0, [r1]
	ldr r2, [sp, #0xc]
	ldrb r0, [r2]
	str r1, [sp, #0x18]
	cmp r0, #0
	beq .L0814D2CA
	ldrb r0, [r2]
	subs r0, #5
	strh r0, [r6, #0x2c]
.L0814D2CA:
	ldr r3, [sp, #0xc]
	ldrb r0, [r3]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #8
	ldr r4, .L0814D548
	adds r0, r0, r4
	lsrs r7, r0, #0x10
	adds r1, r6, #0
	adds r1, #0x2f
	str r1, [sp, #0x14]
	adds r2, r6, #0
	adds r2, #0x63
	str r2, [sp, #0x1c]
	adds r3, r6, #0
	adds r3, #0x65
	str r3, [sp, #0x20]
	adds r4, r6, #0
	adds r4, #0x2e
	str r4, [sp, #0x10]
	cmp r0, #0
	bge .L0814D2FC
	b .L0814D612
.L0814D2FC:
	ldr r0, [sp, #0xc]
	mov sb, r0
	str r2, [sp]
	str r5, [sp, #4]
.L0814D304:
	mov r1, sb
	ldrb r0, [r1]
	bl sub_0814CC38
	mov r2, sb
	ldrb r5, [r2]
	adds r0, r5, #0
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, [sp, #4]
	adds r0, r3, r0
	ldr r4, [sp]
	ldrb r1, [r4]
	ldrb r0, [r0]
	cmp r1, r0
	bne .L0814D360
	adds r0, r6, #0
	adds r0, #0x64
	ldrb r0, [r0]
	adds r1, r5, #0
	bl sub_0814CD10
	lsls r0, r0, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	eors r0, r1
	lsrs r4, r0, #0x18
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r6, #0
	adds r1, #0x58
	adds r1, r1, r0
	ldrb r0, [r1]
	ands r4, r0
	adds r0, r4, #0
	movs r1, #0xff
	bl sub_0814CA34
.L0814D360:
	ldrh r0, [r6, #0x2c]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0814CC38
	lsls r1, r7, #0x10
	asrs r2, r1, #0x10
	mov sl, r2
	ldr r3, [sp, #4]
	add r3, sl
	mov r8, r3
	ldr r4, [sp]
	ldrb r0, [r4]
	str r1, [sp, #8]
	ldrb r1, [r3]
	cmp r0, r1
	bne .L0814D3AA
	adds r0, r6, #0
	adds r0, #0x64
	ldrb r0, [r0]
	ldrh r1, [r6, #0x2c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_0814CD10
	lsls r0, r0, #0x18
	adds r1, r6, #0
	adds r1, #0x58
	add r1, sl
	ldrb r1, [r1]
	lsrs r0, r0, #0x18
	adds r2, r1, #0
	bics r2, r0
	adds r0, r2, #0
	movs r1, #0xff
	bl sub_0814CA34
.L0814D3AA:
	mov r3, r8
	ldrb r0, [r3]
	adds r5, r6, #0
	adds r5, #0x47
	strb r0, [r5]
	mov r4, sb
	ldrb r0, [r4]
	ldrh r1, [r6, #0x2c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_0814CD70
	ldr r0, [sp, #0x18]
	ldrb r1, [r0]
	ldrb r0, [r5]
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0x60
	adds r7, r0, #0
	ldrb r2, [r7]
	cmp r1, r2
	bne .L0814D408
	adds r0, #0x11
	ldrb r0, [r0]
	ldrb r1, [r4]
	bl sub_0814CD10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl sub_0814CE90
	adds r0, r6, #0
	adds r0, #0x72
	ldrb r0, [r0]
	ldrh r1, [r6, #0x2c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_0814CD10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xff
	bl sub_0814CEA4
.L0814D408:
	ldrb r0, [r5]
	ldr r3, [sp, #0x18]
	ldrb r1, [r3]
	subs r0, r0, r1
	ldrb r4, [r7]
	cmp r0, r4
	bne .L0814D44C
	adds r0, r6, #0
	adds r0, #0x71
	ldrb r0, [r0]
	mov r2, sb
	ldrb r1, [r2]
	bl sub_0814CD10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xff
	bl sub_0814CE90
	adds r0, r6, #0
	adds r0, #0x72
	ldrb r0, [r0]
	ldrh r1, [r6, #0x2c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_0814CD10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl sub_0814CEA4
.L0814D44C:
	mov r3, sb
	ldrb r5, [r3]
	adds r0, r5, #0
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r2, r6, #0
	adds r2, #0x50
	adds r0, r2, r3
	ldrb r1, [r0]
	ldr r4, [sp, #0x14]
	ldrb r4, [r4]
	cmp r1, r4
	beq .L0814D46E
	b .L0814D5FE
.L0814D46E:
	mov r4, sl
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, r1
	beq .L0814D47A
	b .L0814D5FE
.L0814D47A:
	ldrb r0, [r6, #5]
	cmp r0, #0
	bne .L0814D482
	b .L0814D5FE
.L0814D482:
	cmp r0, #1
	bne .L0814D55C
	ldrb r0, [r7]
	cmp r0, #2
	bne .L0814D4DE
	ldr r0, [sp, #0x18]
	ldrh r1, [r0]
	ldr r0, .L0814D54C
	cmp r1, r0
	bne .L0814D4DE
	adds r0, r6, #0
	adds r0, #0x61
	ldrb r0, [r0]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r5, #0
	bl sub_0814CD10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl sub_0814CEB8
	mov r1, sb
	ldrb r0, [r1]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r6, #0
	adds r1, #0x58
	adds r0, r1, r0
	add r1, sl
	ldrb r0, [r0]
	ldrb r1, [r1]
	orrs r0, r1
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xff
	bl sub_0814CA34
.L0814D4DE:
	ldrb r0, [r7]
	cmp r0, #3
	beq .L0814D4E6
	b .L0814D5FE
.L0814D4E6:
	ldr r5, .L0814D550
	ldr r2, [sp, #0x18]
	ldrh r1, [r2]
	ldr r0, .L0814D554
	cmp r1, r0
	bne .L0814D512
	adds r0, r6, #0
	adds r0, #0x61
	ldrb r0, [r0]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, [sp, #0xc]
	ldrb r1, [r3]
	bl sub_0814CD10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xff
	bl sub_0814CEB8
.L0814D512:
	ldrb r0, [r7]
	cmp r0, #3
	bne .L0814D5FE
	ldr r4, [sp, #0x18]
	ldrh r0, [r4]
	ands r5, r0
	ldr r0, .L0814D558
	cmp r5, r0
	bne .L0814D5FE
	adds r0, r6, #0
	adds r0, #0x61
	ldrb r0, [r0]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, [sp, #0xc]
	ldrb r1, [r2]
	bl sub_0814CD10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl sub_0814CEB8
	b .L0814D5FE
	.byte 0x00, 0x00
.L0814D548: .4byte 0xFFFF0000
.L0814D54C: .4byte 0x00000303
.L0814D550: .4byte 0x0000FFFF
.L0814D554: .4byte 0x00000202
.L0814D558: .4byte 0x00000203
.L0814D55C:
	ldrb r0, [r7]
	cmp r0, #3
	bne .L0814D5A0
	ldr r4, [sp, #4]
	adds r0, r4, r3
	ldrb r1, [r0]
	cmp r1, #3
	bne .L0814D574
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #4
	beq .L0814D580
.L0814D574:
	cmp r1, #4
	bne .L0814D5A0
	mov r3, r8
	ldrb r0, [r3]
	cmp r0, #3
	bne .L0814D5A0
.L0814D580:
	adds r0, r6, #0
	adds r0, #0x61
	ldrb r0, [r0]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r4, [sp, #0xc]
	ldrb r1, [r4]
	bl sub_0814CD10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl sub_0814CEB8
.L0814D5A0:
	ldrb r0, [r7]
	cmp r0, #2
	bne .L0814D5FE
	ldr r0, [sp, #0x18]
	ldrh r1, [r0]
	ldr r0, .L0814D680
	cmp r1, r0
	bne .L0814D5FE
	adds r0, r6, #0
	adds r0, #0x61
	ldrb r0, [r0]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r2, sb
	ldrb r1, [r2]
	bl sub_0814CD10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl sub_0814CEB8
	mov r3, sb
	ldrb r0, [r3]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r6, #0
	adds r2, #0x58
	adds r0, r2, r0
	ldr r4, [sp, #8]
	asrs r1, r4, #0x10
	adds r2, r2, r1
	ldrb r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xff
	bl sub_0814CA34
.L0814D5FE:
	ldrh r0, [r6, #0x2c]
	subs r0, #5
	strh r0, [r6, #0x2c]
	ldr r1, [sp, #8]
	ldr r2, .L0814D684
	adds r0, r1, r2
	lsrs r7, r0, #0x10
	cmp r0, #0
	blt .L0814D612
	b .L0814D304
.L0814D612:
	bl sub_0814CB90
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
	ldr r4, [sp, #0x14]
	ldrb r4, [r4]
	cmp r0, r4
	bne .L0814D634
	adds r0, r6, #0
	adds r0, #0x64
	ldrb r0, [r0]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xff
	bl sub_0814CA34
.L0814D634:
	bl sub_0814CAD4
	ldr r1, [sp, #0x20]
	ldrb r0, [r1]
	ldr r2, [sp, #0x10]
	ldrb r1, [r2]
	ldr r3, [sp, #0x14]
	ldrb r2, [r3]
	subs r1, r1, r2
	cmp r0, r1
	bne .L0814D65C
	adds r0, r6, #0
	adds r0, #0x66
	ldrb r0, [r0]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl sub_0814CA34
.L0814D65C:
	movs r4, #0
.L0814D65E:
	bl sub_0814CECC
	bl sub_0814D0C4
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #2
	bls .L0814D65E
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814D680: .4byte 0x00000404
.L0814D684: .4byte 0xFFFF0000

	thumb_func_start sub_0814D688
sub_0814D688: @ 0x0814D688
	ldr r0, .L0814D690
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L0814D690: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0814D694
sub_0814D694: @ 0x0814D694
.L0814D694:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r3, .L0814D704
	ldr r1, .L0814D708
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov ip, r0
	lsls r1, r4, #1
	adds r0, r3, #0
	adds r0, #8
	adds r0, r1, r0
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0814D6FC
	adds r0, r3, #0
	adds r0, #0x30
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r5, r3, #0
	adds r5, #0x58
	cmp r0, #0
	bne .L0814D6D6
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0814D6DC
.L0814D6D6:
	ldrh r7, [r2]
	adds r0, r1, r5
	ldrh r6, [r0]
.L0814D6DC:
	lsls r1, r4, #1
	adds r0, r3, #0
	adds r0, #8
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, ip
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r7, [sp, #4]
	str r6, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814D6FC:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814D704: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814D708: .4byte gUnknown_0879F334

	thumb_func_start sub_0814D70C
sub_0814D70C: @ 0x0814D70C
.L0814D70C:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r2, .L0814D744
	mov ip, r2
	lsrs r2, r0, #0xf
	mov r0, ip
	adds r0, #8
	adds r0, r2, r0
	strh r1, [r0]
	cmp r4, #0
	beq .L0814D732
	mov r0, ip
	adds r0, #0x30
	adds r0, r2, r0
	strh r4, [r0]
.L0814D732:
	cmp r3, #0
	beq .L0814D73E
	mov r0, ip
	adds r0, #0x58
	adds r0, r2, r0
	strh r3, [r0]
.L0814D73E:
	pop {r4}
	pop {r0}
	bx r0
.L0814D744: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0814D748
sub_0814D748: @ 0x0814D748
.L0814D748:
	push {r4, lr}
	lsls r0, r0, #0x10
	ldr r4, .L0814D770
	mov ip, r4
	lsrs r0, r0, #0xf
	adds r4, #8
	adds r4, r0, r4
	strh r1, [r4]
	mov r1, ip
	adds r1, #0x30
	adds r1, r0, r1
	strh r2, [r1]
	mov r1, ip
	adds r1, #0x58
	adds r0, r0, r1
	strh r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814D770: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0814D774
sub_0814D774: @ 0x0814D774
	push {lr}
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r3, [sp, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	bl sub_0814D70C
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814D798
sub_0814D798: @ 0x0814D798
	push {lr}
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r3, [sp, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	bl sub_0814D748
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814D7BC
sub_0814D7BC: @ 0x0814D7BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r0, .L0814D934
	mov r8, r0
	movs r4, #0
	str r4, [sp]
	ldr r2, .L0814D938
	mov r0, sp
	mov r1, r8
	bl CpuSet
	str r4, [sp, #4]
	ldr r1, .L0814D93C
	add r0, sp, #4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L0814D940
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xcc
	ldr r2, .L0814D944
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L0814D948
	strh r4, [r0]
	ldr r0, .L0814D94C
	strh r4, [r0]
	movs r0, #1
	mov r1, r8
	strh r0, [r1]
	movs r0, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #2
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #3
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #5
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #6
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #7
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #8
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #9
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #0xa
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #0xb
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #0xc
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #0xd
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #0xe
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #0xf
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #0x10
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #0x11
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	ldr r0, .L0814D950
	adds r2, r0, #0
	mov r7, r8
	adds r7, #0x80
	adds r1, r7, #0
.L0814D8E2:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldrh r0, [r1, #0x18]
	orrs r0, r2
	strh r0, [r1, #0x18]
	adds r1, #2
	adds r4, #1
	cmp r4, #0xb
	bls .L0814D8E2
	movs r5, #0
	movs r4, #4
	ldr r0, .L0814D954
	movs r1, #0x80
	lsls r1, r1, #2
	adds r6, r0, r1
.L0814D902:
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L0814D91A
	lsls r0, r5, #1
	adds r0, r7, r0
	ldrh r1, [r6, #0x12]
	strh r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0814D91A:
	adds r6, #0x80
	adds r4, #1
	cmp r4, #0xf
	bls .L0814D902
	mov r2, r8
	strh r5, [r2, #2]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814D934: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814D938: .4byte 0x05000200 @ PLTT+0x200
.L0814D93C: .4byte 0x040000D4 @ REG_DMA3SAD
.L0814D940: .4byte 0x85001000
.L0814D944: .4byte 0x00004008
.L0814D948: .4byte 0x03000002 @ IWRAM+0x2
.L0814D94C: .4byte 0x03000040 @ IWRAM+0x40
.L0814D950: .4byte 0x0000FFFF
.L0814D954: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_0814D958
sub_0814D958: @ 0x0814D958
	push {r4, lr}
	ldr r4, .L0814D96C
	ldrh r0, [r4]
	cmp r0, #1
	beq .L0814D970
	cmp r0, #1
	ble .L0814D98C
	cmp r0, #2
	beq .L0814D984
	b .L0814D98C
.L0814D96C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814D970:
	ldr r0, .L0814D97C
	ldr r1, .L0814D980
	bl Task_Create
	b .L0814D988
	.byte 0x00, 0x00
.L0814D97C: .4byte gUnknown_0879F3C4
.L0814D980: .4byte 0x0000FFFF
.L0814D984:
	bl sub_080BE4C4
.L0814D988:
	movs r0, #0
	strh r0, [r4]
.L0814D98C:
	movs r0, #2
	movs r1, #0x10
	movs r2, #5
	bl sub_0814D694
	ldr r0, .L0814D9B0
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L0814D9B4
	movs r0, #2
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	b .L0814D9C0
.L0814D9B0: .4byte 0x030031BC @ IWRAM+0x31BC
.L0814D9B4:
	movs r0, #2
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
.L0814D9C0:
	movs r0, #0
	movs r1, #7
	movs r2, #4
	bl sub_0814D694
	movs r0, #3
	movs r1, #0xbb
	movs r2, #5
	bl sub_0814D694
	movs r0, #1
	movs r1, #0xbb
	movs r2, #4
	bl sub_0814D694
	movs r0, #4
	movs r1, #0x4f
	movs r2, #0xa
	bl sub_0814D694
	movs r0, #5
	movs r1, #0x5e
	movs r2, #0xa
	bl sub_0814D694
	movs r0, #6
	movs r1, #0x6d
	movs r2, #0xa
	bl sub_0814D694
	movs r0, #7
	movs r1, #0x7c
	movs r2, #0xa
	bl sub_0814D694
	movs r0, #8
	movs r1, #0x8b
	movs r2, #0xa
	bl sub_0814D694
	movs r0, #9
	movs r1, #0x9a
	movs r2, #0xa
	bl sub_0814D694
	movs r0, #0xa
	movs r1, #0
	movs r2, #0x20
	bl sub_0814D694
	movs r0, #0xb
	movs r1, #0
	movs r2, #0x25
	bl sub_0814D694
	movs r0, #0xe
	movs r1, #0xcf
	movs r2, #0x48
	bl sub_0814D694
	movs r0, #0xd
	movs r1, #0xac
	movs r2, #0x6c
	bl sub_0814D694
	movs r0, #0x11
	movs r1, #0xf0
	movs r2, #0x64
	bl sub_0814D694
	movs r0, #0xc
	movs r1, #0xa6
	movs r2, #0x50
	bl sub_0814D694
	movs r0, #0xf
	movs r1, #0x5e
	movs r2, #0x1c
	bl sub_0814D694
	movs r0, #0x10
	movs r1, #0x5e
	movs r2, #0x64
	bl sub_0814D694
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0814DA70
sub_0814DA70: @ 0x0814DA70
.L0814DA70:
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r4, .L0814DAA8
	lsrs r0, r0, #8
	movs r5, #0xc8
	lsls r5, r5, #0x12
	adds r0, r0, r5
	lsrs r0, r0, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	adds r2, r3, #0
	movs r3, #0
	bl Sprite_DrawSingle
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L0814DAA8: .4byte gUnknown_0879F394

	thumb_func_start sub_0814DAAC
sub_0814DAAC: @ 0x0814DAAC
.L0814DAAC:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r0, [sp, #0x1c]
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sb, r2
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r5, #0
	b .L0814DAEA
.L0814DAD0:
	adds r1, r6, #0
	mov r2, sb
	mov r3, r8
	bl sub_0814DA70
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r6, #0
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r4, #1
.L0814DAEA:
	cmp r5, r7
	bhs .L0814DAF8
	ldrb r0, [r4]
	cmp r0, #0xff
	beq .L0814DAF8
	cmp r0, #0
	bne .L0814DAD0
.L0814DAF8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814DB04
sub_0814DB04: @ 0x0814DB04
	ldr r0, .L0814DB0C
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L0814DB0C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0814DB10
sub_0814DB10: @ 0x0814DB10
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0814DB38
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq .L0814DB30
	movs r0, #0xad
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r0, #1
.L0814DB30:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
.L0814DB38: .4byte 0x030031B8 @ IWRAM+0x31B8

	thumb_func_start sub_0814DB3C
sub_0814DB3C: @ 0x0814DB3C
	push {lr}
	ldr r2, .L0814DB58
	ldr r0, .L0814DB5C
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne .L0814DB78
	ldrh r0, [r2, #0xe]
	cmp r0, #1
	bne .L0814DB60
	movs r0, #2
	b .L0814DB76
	.byte 0x00, 0x00
.L0814DB58: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814DB5C: .4byte 0x030031BC @ IWRAM+0x31BC
.L0814DB60:
	cmp r0, #2
	bne .L0814DB68
	movs r0, #1
	b .L0814DB76
.L0814DB68:
	cmp r0, #3
	bne .L0814DB70
	movs r0, #4
	b .L0814DB76
.L0814DB70:
	cmp r0, #4
	bne .L0814DB78
	movs r0, #3
.L0814DB76:
	strh r0, [r2, #0xe]
.L0814DB78:
	pop {r0}
	bx r0

	thumb_func_start sub_0814DB7C
sub_0814DB7C: @ 0x0814DB7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	ldr r0, .L0814DBE4
	mov r8, r0
	movs r7, #8
	ldr r0, .L0814DBE8
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	movs r2, #0x1a
	movs r3, #8
	bl sub_0814DAAC
	movs r6, #0x28
	movs r5, #0
	ldr r0, .L0814DBEC
	mov sb, r0
.L0814DBA4:
	lsls r1, r5, #1
	mov r0, r8
	adds r0, #0x80
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, sb
	beq .L0814DC00
	adds r0, r4, #0
	bl Demon_GetRecord
	adds r0, #0x22
	add r1, sp, #4
	bl sub_080C0420
	adds r0, r4, #0
	bl sub_080C0198
	ldrb r0, [r0, #0xc]
	bl sub_0814E844
	cmp r0, #1
	bne .L0814DBF0
	movs r0, #0
	str r0, [sp]
	add r0, sp, #4
	adds r1, r7, #0
	adds r2, r6, #0
	movs r3, #8
	bl sub_0814DAAC
	b .L0814DC00
	.byte 0x00, 0x00
.L0814DBE4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814DBE8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0814DBEC: .4byte 0x0000FFFF
.L0814DBF0:
	movs r0, #2
	str r0, [sp]
	add r0, sp, #4
	adds r1, r7, #0
	adds r2, r6, #0
	movs r3, #8
	bl sub_0814DAAC
.L0814DC00:
	adds r0, r6, #0
	adds r0, #9
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xb
	bls .L0814DBA4
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814DC20
sub_0814DC20: @ 0x0814DC20
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r5, .L0814DC6C
	ldrh r6, [r5, #2]
	mov r8, r6
	movs r0, #0
	strh r0, [r7, #0x1c]
	ldr r0, .L0814DC70
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0814DC7C
	adds r4, r5, #0
	adds r4, #0xc8
	ldrh r0, [r4]
	lsls r0, r0, #1
	adds r1, r5, #0
	adds r1, #0x80
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_080C0198
	ldrb r0, [r0, #0xc]
	bl sub_0814E844
	adds r5, r0, #0
	mov sb, r4
	cmp r5, #1
	bne .L0814DC74
	movs r0, #0x65
	bl sub_080C51D4
	strh r5, [r7, #0x1c]
	b .L0814DCD4
.L0814DC6C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814DC70: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0814DC74:
	movs r0, #0x66
	bl sub_080C51D4
	b .L0814DCD4
.L0814DC7C:
	ldr r0, .L0814DCA4
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L0814DCAC
	movs r0, #0x64
	bl sub_080C51D4
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r2, [r0]
	mov sb, r0
	cmp r2, #0
	beq .L0814DCA8
	subs r0, r2, #1
	b .L0814DCCA
	.byte 0x00, 0x00
.L0814DCA4: .4byte 0x03003964 @ IWRAM+0x3964
.L0814DCA8:
	subs r0, r6, #1
	b .L0814DCCA
.L0814DCAC:
	movs r0, #0x80
	ands r0, r1
	adds r5, #0xc8
	mov sb, r5
	cmp r0, #0
	beq .L0814DCD4
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r1, [r5]
	mov r0, r8
	subs r0, #1
	cmp r1, r0
	beq .L0814DCD0
	adds r0, r1, #1
.L0814DCCA:
	mov r1, sb
	strh r0, [r1]
	b .L0814DCD4
.L0814DCD0:
	mov r0, sb
	strh r4, [r0]
.L0814DCD4:
	mov r1, sb
	ldrh r0, [r1]
	lsls r3, r0, #3
	adds r3, r3, r0
	adds r3, #0x25
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0xb
	movs r1, #1
	movs r2, #0
	bl sub_0814D70C
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814DCF8
sub_0814DCF8: @ 0x0814DCF8
	push {r4, lr}
	sub sp, #4
	ldr r0, .L0814DD24
	movs r4, #0
	str r4, [sp]
	movs r1, #8
	movs r2, #0x59
	movs r3, #8
	bl sub_0814DAAC
	ldr r0, .L0814DD28
	str r4, [sp]
	movs r1, #8
	movs r2, #0x65
	movs r3, #8
	bl sub_0814DAAC
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814DD24: .4byte gUnknown_0879F39C
.L0814DD28: .4byte gUnknown_0879F3A1

	thumb_func_start sub_0814DD2C
sub_0814DD2C: @ 0x0814DD2C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, .L0814DD50
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldr r0, .L0814DD54
	ldrh r1, [r0]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L0814DD58
	movs r0, #0x65
	bl sub_080C51D4
	strh r5, [r4, #0x1c]
	adds r6, #0xcc
	b .L0814DDA6
.L0814DD50: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814DD54: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0814DD58:
	ldr r0, .L0814DD80
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L0814DD88
	movs r0, #0x64
	bl sub_080C51D4
	adds r0, r6, #0
	adds r0, #0xcc
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq .L0814DD84
	subs r0, r1, #1
	strh r0, [r6]
	b .L0814DDA6
.L0814DD80: .4byte 0x03003964 @ IWRAM+0x3964
.L0814DD84:
	strh r5, [r6]
	b .L0814DDA6
.L0814DD88:
	movs r0, #0x80
	ands r0, r1
	adds r6, #0xcc
	cmp r0, #0
	beq .L0814DDA6
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r6]
	cmp r0, #1
	beq .L0814DDA4
	adds r0, #1
	strh r0, [r6]
	b .L0814DDA6
.L0814DDA4:
	strh r4, [r6]
.L0814DDA6:
	ldrh r0, [r6]
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #0x12
	movs r0, #0xac
	lsls r0, r0, #0xf
	adds r3, r3, r0
	lsrs r3, r3, #0x10
	movs r0, #0xb
	movs r1, #1
	movs r2, #0
	bl sub_0814D70C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814DDC8
sub_0814DDC8: @ 0x0814DDC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r6, .L0814DDF0
	ldr r1, .L0814DDF4
	ldrh r0, [r1]
	cmp r0, #3
	beq .L0814DDFC
	lsls r0, r0, #3
	ldr r1, .L0814DDF8
	adds r0, r0, r1
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	movs r2, #0x1a
	movs r3, #8
	bl sub_0814DAAC
	b .L0814DE0C
.L0814DDF0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814DDF4: .4byte 0x0203DB72 @ EWRAM+0x3DB72
.L0814DDF8: .4byte gUnknown_0879F37C
.L0814DDFC:
	ldr r0, .L0814DE5C
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	movs r2, #0x1a
	movs r3, #8
	bl sub_0814DAAC
.L0814DE0C:
	movs r0, #8
	mov r8, r0
	movs r5, #0x28
	movs r4, #0
	adds r6, #0x98
	ldr r7, .L0814DE60
.L0814DE18:
	lsls r0, r4, #1
	adds r0, r6, r0
	ldrh r0, [r0]
	cmp r0, r7
	beq .L0814DE46
	bl Demon_GetRecord
	adds r0, #0x22
	add r1, sp, #4
	bl sub_080C0420
	movs r0, #0
	str r0, [sp]
	add r0, sp, #4
	mov r1, r8
	adds r2, r5, #0
	movs r3, #8
	bl sub_0814DAAC
	adds r0, r5, #0
	adds r0, #9
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0814DE46:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xb
	bls .L0814DE18
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814DE5C: .4byte 0x030050C8 @ IWRAM+0x50C8
.L0814DE60: .4byte 0x0000FFFF

	thumb_func_start sub_0814DE64
sub_0814DE64: @ 0x0814DE64
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, .L0814DE8C
	movs r0, #0
	strh r0, [r6, #0x1c]
	adds r0, r4, #0
	adds r0, #0xc8
	adds r5, r4, #0
	adds r5, #0xca
	ldrh r0, [r0]
	ldrh r1, [r5]
	cmp r0, r1
	bne .L0814DE90
	movs r0, #0x65
	bl sub_080C51D4
	movs r0, #1
	strh r0, [r6, #0x1c]
	b .L0814DE9C
	.byte 0x00, 0x00
.L0814DE8C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814DE90:
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
.L0814DE9C:
	adds r0, r4, #0
	adds r0, #0xca
	ldrh r0, [r0]
	lsls r3, r0, #3
	adds r3, r3, r0
	adds r3, #0x25
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0xb
	movs r1, #1
	movs r2, #0
	bl sub_0814D70C
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_0814DEBC
sub_0814DEBC: @ 0x0814DEBC
	push {lr}
	ldr r0, .L0814DED4
	cmp r1, #0
	bne .L0814DED8
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xa6
	movs r3, #0x50
	bl sub_0814D70C
	b .L0814DEF0
	.byte 0x00, 0x00
.L0814DED4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814DED8:
	cmp r1, #1
	bne .L0814DEE6
	adds r1, r0, #0
	adds r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	b .L0814DEEE
.L0814DEE6:
	adds r1, r0, #0
	adds r1, #0x70
	ldrh r0, [r1]
	subs r0, #1
.L0814DEEE:
	strh r0, [r1]
.L0814DEF0:
	pop {r0}
	bx r0

	thumb_func_start sub_0814DEF4
sub_0814DEF4: @ 0x0814DEF4
	push {lr}
	ldr r0, .L0814DF0C
	cmp r1, #0
	bne .L0814DF10
	movs r0, #0x11
	movs r1, #1
	movs r2, #0xf0
	movs r3, #0x64
	bl sub_0814D70C
	b .L0814DF1A
	.byte 0x00, 0x00
.L0814DF0C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814DF10:
	adds r1, r0, #0
	adds r1, #0x52
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
.L0814DF1A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814DF20
sub_0814DF20: @ 0x0814DF20
	push {r4, lr}
	adds r4, r3, #0
	ldr r3, .L0814DF38
	cmp r1, #0
	bne .L0814DF3C
	movs r0, #0xa
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl sub_0814D748
	b .L0814DF4E
.L0814DF38: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814DF3C:
	adds r1, r3, #0
	adds r1, #0x44
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #0x28
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
.L0814DF4E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0814DF54
sub_0814DF54: @ 0x0814DF54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r4, .L0814DF80
	adds r0, r4, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0814DF84
	movs r2, #0x38
	movs r0, #0x4c
	mov r8, r0
	movs r1, #8
	mov sb, r1
	movs r6, #0x78
	movs r0, #0x94
	mov sl, r0
	b .L0814DF94
	.byte 0x00, 0x00
.L0814DF80: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814DF84:
	movs r2, #0x78
	movs r1, #0x94
	mov r8, r1
	movs r0, #8
	mov sb, r0
	movs r6, #0x38
	movs r1, #0x4c
	mov sl, r1
.L0814DF94:
	ldr r7, .L0814DFE8
	movs r5, #0
	str r5, [sp]
	adds r0, r7, #0
	movs r1, #8
	movs r3, #8
	bl sub_0814DAAC
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	lsls r1, r1, #1
	subs r0, #0x48
	adds r0, r0, r1
	ldrh r0, [r0]
	bl Demon_GetRecord
	adds r0, #0x22
	add r1, sp, #4
	bl sub_080C0420
	str r5, [sp]
	add r0, sp, #4
	movs r1, #0x5c
	mov r2, r8
	movs r3, #8
	bl sub_0814DAAC
	ldr r1, .L0814DFEC
	ldrh r0, [r1]
	cmp r0, #3
	beq .L0814DFF4
	lsls r0, r0, #3
	ldr r1, .L0814DFF0
	adds r0, r0, r1
	str r5, [sp]
	mov r1, sb
	adds r2, r6, #0
	movs r3, #8
	bl sub_0814DAAC
	b .L0814E004
.L0814DFE8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0814DFEC: .4byte 0x0203DB72 @ EWRAM+0x3DB72
.L0814DFF0: .4byte gUnknown_0879F37C
.L0814DFF4:
	ldr r1, .L0814E040
	adds r0, r7, r1
	str r5, [sp]
	mov r1, sb
	adds r2, r6, #0
	movs r3, #8
	bl sub_0814DAAC
.L0814E004:
	adds r0, r4, #0
	adds r0, #0xca
	ldrh r1, [r0]
	lsls r1, r1, #1
	subs r0, #0x32
	adds r0, r0, r1
	ldrh r0, [r0]
	bl Demon_GetRecord
	adds r0, #0x22
	add r1, sp, #4
	bl sub_080C0420
	movs r0, #0
	str r0, [sp]
	add r0, sp, #4
	movs r1, #0x5c
	mov r2, sl
	movs r3, #8
	bl sub_0814DAAC
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814E040: .4byte 0x00000A08

	thumb_func_start sub_0814E044
sub_0814E044: @ 0x0814E044
	push {r4, lr}
	ldr r4, .L0814E060
	bl sub_080C2244
	movs r1, #7
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsrs r1, r1, #2
	strh r1, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814E060: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_0814E064
sub_0814E064: @ 0x0814E064
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r6, .L0814E098
	movs r0, #0
	strh r0, [r5, #0x1e]
	ldrh r0, [r6, #4]
	cmp r0, r4
	bne .L0814E0C6
	movs r1, #1
	strh r1, [r5, #0x1c]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne .L0814E09C
	movs r0, #0xf
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #0xc6
	lsls r0, r0, #1
	bl sub_080C51D4
	b .L0814E0B0
.L0814E098: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E09C:
	movs r0, #0x10
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #0xc6
	lsls r0, r0, #1
	bl sub_080C51D4
.L0814E0B0:
	movs r1, #1
	ands r4, r1
	adds r0, r6, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	cmp r4, r0
	bne .L0814E0C4
	movs r0, #2
	strh r0, [r5, #0x1e]
	b .L0814E0C6
.L0814E0C4:
	strh r1, [r5, #0x1e]
.L0814E0C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_0814E0CC
sub_0814E0CC: @ 0x0814E0CC
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	ldr r0, .L0814E0F0
	movs r1, #0
	strh r1, [r4, #0x1c]
	adds r0, #0xcc
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0814E0F4
	cmp r2, #0
	beq .L0814E100
	cmp r2, #2
	beq .L0814E100
	cmp r2, #4
	beq .L0814E100
	b .L0814E13E
	.byte 0x00, 0x00
.L0814E0F0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E0F4:
	cmp r2, #0
	beq .L0814E13E
	cmp r2, #2
	beq .L0814E13E
	cmp r2, #4
	beq .L0814E13E
.L0814E100:
	ldr r0, .L0814E114
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0814E118
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L0814E14E
.L0814E114: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0814E118:
	ldr r0, .L0814E12C
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L0814E130
	movs r0, #3
	movs r1, #3
	b .L0814E134
.L0814E12C: .4byte 0x030031BC @ IWRAM+0x31BC
.L0814E130:
	movs r0, #3
	movs r1, #4
.L0814E134:
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	b .L0814E14E
.L0814E13E:
	movs r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #3
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
.L0814E14E:
	ldrh r0, [r4, #0x1c]
	cmp r0, #1
	bne .L0814E16C
	movs r0, #0xd
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
	movs r0, #3
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl sub_0814D70C
.L0814E16C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814E174
sub_0814E174: @ 0x0814E174
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	ldr r6, .L0814E190
	movs r0, #0
	strh r0, [r4, #0x1c]
	cmp r2, #0
	bne .L0814E194
	adds r0, r6, #0
	adds r0, #0xca
	strh r2, [r0]
	adds r5, r0, #0
	b .L0814E1DC
	.byte 0x00, 0x00
.L0814E190: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E194:
	cmp r2, #1
	bne .L0814E1B4
	adds r0, r6, #0
	adds r0, #0xca
	adds r1, r6, #0
	adds r1, #0xc8
	ldrh r3, [r0]
	adds r5, r0, #0
	ldrh r1, [r1]
	cmp r3, r1
	beq .L0814E1B0
	adds r0, r3, #1
	strh r0, [r5]
	b .L0814E1DC
.L0814E1B0:
	strh r2, [r4, #0x1c]
	b .L0814E1DC
.L0814E1B4:
	adds r5, r6, #0
	adds r5, #0xc8
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r4, r6, #0
	adds r4, #0x80
	adds r0, r0, r4
	ldrh r0, [r0]
	bl sub_080C0198
	ldrb r0, [r0, #0xc]
	movs r1, #1
	bl sub_080C0290
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldr r1, .L0814E1F8
	strh r1, [r0]
	adds r5, #2
.L0814E1DC:
	ldrh r0, [r5]
	lsls r3, r0, #3
	adds r3, r3, r0
	adds r3, #0x25
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0xb
	movs r1, #1
	movs r2, #0
	bl sub_0814D70C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0814E1F8: .4byte 0x0000FFFF

	thumb_func_start sub_0814E1FC
sub_0814E1FC: @ 0x0814E1FC
	push {r4, lr}
	adds r3, r0, #0
	ldr r2, .L0814E214
	movs r0, #0
	strh r0, [r3, #0x1c]
	cmp r1, #0
	bne .L0814E218
	adds r0, r2, #0
	adds r0, #0xc8
	strh r1, [r0]
	adds r4, r0, #0
	b .L0814E230
.L0814E214: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E218:
	adds r4, r2, #0
	adds r4, #0xc8
	cmp r1, #1
	bne .L0814E230
	ldrh r0, [r4]
	ldrh r2, [r2, #2]
	cmp r0, r2
	beq .L0814E22E
	adds r0, #1
	strh r0, [r4]
	b .L0814E230
.L0814E22E:
	strh r1, [r3, #0x1c]
.L0814E230:
	ldrh r0, [r4]
	lsls r3, r0, #3
	adds r3, r3, r0
	adds r3, #0x25
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0xb
	movs r1, #1
	movs r2, #0
	bl sub_0814D70C
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0814E24C
sub_0814E24C: @ 0x0814E24C
	push {lr}
	adds r2, r0, #0
	ldr r3, .L0814E268
	ldr r0, .L0814E26C
	ldr r1, .L0814E270
	adds r0, r0, r1
	ldrh r1, [r3, #2]
	ldrb r0, [r0]
	cmp r1, r0
	blo .L0814E274
	movs r0, #1
	strh r0, [r2, #0x1c]
	b .L0814E27E
	.byte 0x00, 0x00
.L0814E268: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E26C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0814E270: .4byte 0x00000AC3
.L0814E274:
	movs r0, #0
	strh r0, [r2, #0x1c]
	adds r0, r3, #0
	adds r0, #0xc8
	strh r1, [r0]
.L0814E27E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814E284
sub_0814E284: @ 0x0814E284
	push {r4, lr}
	sub sp, #4
	ldr r0, .L0814E2CC
	movs r4, #0
	str r4, [sp]
	movs r1, #8
	movs r2, #0x1a
	movs r3, #8
	bl sub_0814DAAC
	ldr r0, .L0814E2D0
	str r4, [sp]
	movs r1, #8
	movs r2, #0x22
	movs r3, #8
	bl sub_0814DAAC
	ldr r0, .L0814E2D4
	str r4, [sp]
	movs r1, #8
	movs r2, #0x59
	movs r3, #8
	bl sub_0814DAAC
	ldr r0, .L0814E2D8
	str r4, [sp]
	movs r1, #8
	movs r2, #0x65
	movs r3, #8
	bl sub_0814DAAC
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814E2CC: .4byte gUnknown_0879F3A6
.L0814E2D0: .4byte gUnknown_0879F3AE
.L0814E2D4: .4byte gUnknown_0879F3B6
.L0814E2D8: .4byte gUnknown_0879F3BC

	thumb_func_start sub_0814E2DC
sub_0814E2DC: @ 0x0814E2DC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r7, .L0814E2F8
	movs r5, #0
	strh r5, [r4, #0x1c]
	strh r5, [r4, #0x1e]
	cmp r1, #0
	bne .L0814E2FC
	adds r0, r7, #0
	adds r0, #0xcc
	strh r5, [r0]
	b .L0814E39E
	.byte 0x00, 0x00
.L0814E2F8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E2FC:
	ldr r0, .L0814E32C
	ldrh r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L0814E330
	movs r0, #0x65
	bl sub_080C51D4
	strh r6, [r4, #0x1c]
	adds r1, r7, #0
	adds r1, #0xcc
	ldrh r0, [r1]
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L0814E384
	adds r0, r7, #0
	adds r0, #0xc8
	strh r5, [r0]
	b .L0814E384
	.byte 0x00, 0x00
.L0814E32C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0814E330:
	ldr r0, .L0814E358
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L0814E360
	movs r0, #0x64
	bl sub_080C51D4
	adds r0, r7, #0
	adds r0, #0xcc
	ldrh r2, [r0]
	adds r1, r0, #0
	cmp r2, #0
	beq .L0814E35C
	subs r0, r2, #1
	strh r0, [r1]
	b .L0814E384
.L0814E358: .4byte 0x03003964 @ IWRAM+0x3964
.L0814E35C:
	strh r6, [r1]
	b .L0814E384
.L0814E360:
	movs r0, #0x80
	ands r0, r1
	adds r1, r7, #0
	adds r1, #0xcc
	cmp r0, #0
	beq .L0814E384
	movs r0, #0x64
	str r1, [sp]
	bl sub_080C51D4
	ldr r1, [sp]
	ldrh r0, [r1]
	cmp r0, #1
	beq .L0814E382
	adds r0, #1
	strh r0, [r1]
	b .L0814E384
.L0814E382:
	strh r4, [r1]
.L0814E384:
	ldrh r0, [r1]
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #0x12
	movs r0, #0xac
	lsls r0, r0, #0xf
	adds r3, r3, r0
	lsrs r3, r3, #0x10
	movs r0, #0xb
	movs r1, #1
	movs r2, #0
	bl sub_0814D70C
.L0814E39E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814E3A8
sub_0814E3A8: @ 0x0814E3A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r6, .L0814E430
	movs r0, #8
	mov r8, r0
	adds r0, r6, #0
	adds r0, #0xca
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r1, #0x98
	adds r0, r0, r1
	ldrh r0, [r0]
	bl Demon_GetRecord
	adds r0, #0x22
	add r1, sp, #4
	bl sub_080C0420
	movs r0, #0
	str r0, [sp]
	add r0, sp, #4
	movs r1, #8
	movs r2, #0x1a
	movs r3, #8
	bl sub_0814DAAC
	movs r5, #0x28
	movs r4, #0
	ldr r7, .L0814E434
.L0814E3E8:
	lsls r1, r4, #1
	adds r0, r6, #0
	adds r0, #0x80
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r7
	beq .L0814E412
	bl Demon_GetRecord
	adds r0, #0x22
	add r1, sp, #4
	bl sub_080C0420
	movs r0, #0
	str r0, [sp]
	add r0, sp, #4
	mov r1, r8
	adds r2, r5, #0
	movs r3, #8
	bl sub_0814DAAC
.L0814E412:
	adds r0, r5, #0
	adds r0, #9
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xb
	bls .L0814E3E8
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814E430: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E434: .4byte 0x0000FFFF

	thumb_func_start sub_0814E438
sub_0814E438: @ 0x0814E438
	push {r4, r5, r6, lr}
	ldr r6, .L0814E468
	cmp r1, #0
	bne .L0814E470
	adds r5, r6, #0
	adds r5, #0xc8
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r4, r6, #0
	adds r4, #0x80
	adds r0, r0, r4
	ldrh r0, [r0]
	bl sub_080C0198
	ldrb r0, [r0, #0xc]
	movs r1, #1
	bl sub_080C0290
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldr r1, .L0814E46C
	strh r1, [r0]
	b .L0814E4A6
.L0814E468: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E46C: .4byte 0x0000FFFF
.L0814E470:
	adds r0, r6, #0
	adds r0, #0xca
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r1, #0x98
	adds r0, r0, r1
	ldrh r4, [r0]
	adds r0, r4, #0
	bl sub_080C062C
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r1, #0x80
	adds r0, r0, r1
	movs r5, #0
	strh r4, [r0]
	adds r0, r4, #0
	bl sub_080C3560
	strh r5, [r0, #0x18]
	movs r1, #0x80
	lsls r1, r1, #8
	strh r1, [r0, #0x10]
.L0814E4A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_0814E4AC
sub_0814E4AC: @ 0x0814E4AC
.L0814E4AC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r1, .L0814E52C
	mov ip, r1
	movs r7, #0
	ldr r3, .L0814E530
	mov r8, r3
	lsls r0, r0, #1
	adds r1, #0x98
	adds r0, r0, r1
	mov sl, r0
.L0814E4CA:
	movs r6, #0
	movs r2, #0
	mov r4, ip
	ldrh r5, [r4, #2]
	adds r0, r7, #1
	mov sb, r0
	cmp r6, r5
	bhs .L0814E508
	lsls r0, r7, #1
	mov r3, r8
	adds r1, r0, r3
	ldrh r1, [r1]
	str r0, [sp]
	mov r3, ip
	adds r3, #0x80
	ldr r4, .L0814E534
	ldrh r4, [r4]
	cmp r1, r4
	beq .L0814E516
.L0814E4F0:
	adds r2, #1
	cmp r2, r5
	bhs .L0814E508
	ldr r0, [sp]
	add r0, r8
	lsls r1, r2, #1
	adds r1, r3, r1
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0814E4F0
	movs r6, #1
.L0814E508:
	cmp r6, #0
	bne .L0814E516
	lsls r0, r7, #1
	add r0, r8
	ldrh r0, [r0]
	mov r1, sl
	strh r0, [r1]
.L0814E516:
	mov r7, sb
	cmp r7, #0xb
	bls .L0814E4CA
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814E52C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E530: .4byte gUnknown_087A075A
.L0814E534: .4byte 0x0203A4D4 @ EWRAM+0x3A4D4

	thumb_func_start sub_0814E538
sub_0814E538: @ 0x0814E538
.L0814E538:
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r4, .L0814E554
.L0814E540:
	ldrh r0, [r4]
	cmp r0, r6
	bne .L0814E558
	ldrh r0, [r4, #2]
	bl Flag_Test
	cmp r0, #0
	bne .L0814E558
	movs r0, #1
	b .L0814E562
.L0814E554: .4byte gUnknown_087A0772
.L0814E558:
	adds r4, #4
	adds r5, #1
	cmp r5, #0x19
	ble .L0814E540
	movs r0, #0
.L0814E562:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_0814E568
sub_0814E568: @ 0x0814E568
.L0814E568:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp]
	ldr r7, .L0814E6A8
	movs r0, #0
	str r0, [sp, #4]
	ldrh r1, [r7, #2]
	cmp r0, r1
	blo .L0814E584
	b .L0814E6DC
.L0814E584:
	ldr r2, [sp]
	lsls r6, r2, #1
	ldr r3, [sp, #4]
	cmp r3, #0
	bne .L0814E596
	adds r0, r7, #0
	adds r0, #0xb0
	adds r0, r0, r6
	strh r3, [r0]
.L0814E596:
	ldr r2, .L0814E6AC
	adds r1, r7, #0
	adds r1, #0x80
	adds r0, r1, r6
	ldrh r0, [r0]
	adds r0, r0, r2
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	lsls r0, r3, #1
	adds r0, r1, r0
	mov sl, r1
	ldrh r0, [r0]
	cmp r2, r0
	beq .L0814E5C2
	adds r0, r2, #0
	bl sub_0814E538
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L0814E5C2
	b .L0814E6CE
.L0814E5C2:
	movs r0, #0
	mov sb, r0
	ldrh r1, [r7, #2]
	cmp sb, r1
	blo .L0814E5CE
	b .L0814E6CE
.L0814E5CE:
	mov r8, sl
.L0814E5D0:
	mov r2, sb
	cmp r2, #0
	bne .L0814E5E0
	adds r0, r7, #0
	adds r0, #0xb0
	adds r0, r0, r6
	movs r1, #0xa
	strh r1, [r0]
.L0814E5E0:
	mov r3, r8
	adds r0, r3, r6
	ldrh r1, [r0]
	ldr r0, .L0814E6B0
	adds r1, r1, r0
	mov r2, sb
	lsls r0, r2, #1
	add r0, r8
	ldrb r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne .L0814E644
	movs r5, #0
	ldrh r3, [r7, #2]
	cmp r5, r3
	bhs .L0814E644
	adds r1, r7, #0
	adds r1, #0xb0
	adds r0, r1, r6
	str r0, [sp, #0x14]
	mov r2, sl
	mov r4, sl
.L0814E60C:
	cmp r5, #0
	bne .L0814E616
	movs r0, #0x14
	ldr r3, [sp, #0x14]
	strh r0, [r3]
.L0814E616:
	adds r0, r2, r6
	ldrh r0, [r0]
	ldr r3, .L0814E6B4
	adds r0, r0, r3
	ldrb r0, [r0]
	ldrh r3, [r4]
	cmp r0, r3
	beq .L0814E6A0
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	bl sub_0814E538
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	cmp r0, #1
	beq .L0814E6A0
	adds r4, #2
	adds r5, #1
	ldrh r0, [r7, #2]
	cmp r5, r0
	blo .L0814E60C
.L0814E644:
	mov r1, sl
	adds r0, r1, r6
	ldrh r0, [r0]
	ldr r2, .L0814E6B0
	adds r0, r0, r2
	ldrb r0, [r0]
	bl sub_0814E538
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L0814E6C2
	movs r5, #0
	ldrh r3, [r7, #2]
	cmp r5, r3
	bhs .L0814E6C2
	adds r1, r7, #0
	adds r1, #0xb0
	adds r2, r1, r6
	mov r4, r8
.L0814E66C:
	cmp r5, #0
	bne .L0814E674
	movs r0, #0x1e
	strh r0, [r2]
.L0814E674:
	mov r3, r8
	adds r0, r3, r6
	ldrh r0, [r0]
	ldr r3, .L0814E6B4
	adds r0, r0, r3
	ldrb r0, [r0]
	ldr r3, .L0814E6AC
	adds r0, r0, r3
	ldrb r0, [r0]
	ldrh r3, [r4]
	cmp r0, r3
	beq .L0814E6A0
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	bl sub_0814E538
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	cmp r0, #1
	bne .L0814E6B8
.L0814E6A0:
	adds r1, r1, r6
	movs r0, #2
	strh r0, [r1]
	b .L0814E6DC
.L0814E6A8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E6AC: .4byte gUnknown_087A045C
.L0814E6B0: .4byte gUnknown_087A055B
.L0814E6B4: .4byte gUnknown_087A065A
.L0814E6B8:
	adds r4, #2
	adds r5, #1
	ldrh r0, [r7, #2]
	cmp r5, r0
	blo .L0814E66C
.L0814E6C2:
	movs r1, #1
	add sb, r1
	ldrh r2, [r7, #2]
	cmp sb, r2
	bhs .L0814E6CE
	b .L0814E5D0
.L0814E6CE:
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
	ldrh r0, [r7, #2]
	cmp r3, r0
	bhs .L0814E6DC
	b .L0814E584
.L0814E6DC:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814E6EC
sub_0814E6EC: @ 0x0814E6EC
.L0814E6EC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r6, .L0814E778
	adds r1, r6, #0
	adds r1, #0xc8
	ldrh r2, [r1]
	cmp r0, r2
	beq .L0814E788
	lsls r2, r0, #1
	adds r5, r6, #0
	adds r5, #0xb0
	adds r4, r2, r5
	movs r0, #0
	strh r0, [r4]
	ldr r0, .L0814E77C
	mov ip, r0
	ldrh r0, [r1]
	lsls r7, r0, #1
	subs r1, #0x48
	adds r0, r7, r1
	ldrh r0, [r0]
	add r0, ip
	adds r3, r2, r1
	ldrb r0, [r0]
	mov sb, r2
	mov r8, r5
	mov sl, r1
	ldrh r3, [r3]
	cmp r0, r3
	bne .L0814E73C
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #0xa
	bne .L0814E73C
	strh r0, [r4]
.L0814E73C:
	mov r5, sb
	mov r1, sl
	adds r7, r1, r5
	ldrh r0, [r7]
	ldr r2, .L0814E77C
	adds r0, r0, r2
	ldrb r0, [r0]
	bl sub_0814E538
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L0814E788
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	ldr r1, .L0814E77C
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrh r7, [r7]
	cmp r0, r7
	bne .L0814E780
	mov r2, r8
	adds r1, r2, r5
	movs r0, #0x14
	b .L0814E786
	.byte 0x00, 0x00
.L0814E778: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E77C: .4byte gUnknown_087A045C
.L0814E780:
	mov r1, r8
	add r1, sb
	movs r0, #0xa
.L0814E786:
	strh r0, [r1]
.L0814E788:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814E798
sub_0814E798: @ 0x0814E798
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r6, .L0814E7AC
	adds r0, r6, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	bl sub_0814E568
	movs r5, #0
	b .L0814E7BA
.L0814E7AC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814E7B0:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_0814E6EC
	adds r5, #1
.L0814E7BA:
	ldrh r0, [r6, #2]
	cmp r5, r0
	blo .L0814E7B0
	movs r5, #0
	ldrh r0, [r6, #2]
	cmp r5, r0
	bhs .L0814E83C
	ldr r2, .L0814E7EC
	adds r4, r6, #0
	adds r4, #0x80
	ldr r7, .L0814E7F0
.L0814E7D0:
	lsls r1, r5, #1
	adds r0, r6, #0
	adds r0, #0xb0
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne .L0814E7F4
	adds r0, r5, #0
	str r2, [sp]
	bl sub_0814E4AC
	ldr r2, [sp]
	b .L0814E832
	.byte 0x00, 0x00
.L0814E7EC: .4byte gUnknown_087A045C
.L0814E7F0: .4byte gUnknown_087A065A
.L0814E7F4:
	cmp r0, #1
	bne .L0814E7FC
	ldrh r0, [r4]
	b .L0814E830
.L0814E7FC:
	cmp r0, #0
	bne .L0814E804
	ldrh r0, [r4]
	b .L0814E82C
.L0814E804:
	cmp r0, #0xa
	bne .L0814E818
	ldr r0, .L0814E814
	ldrh r1, [r4]
	adds r1, r1, r0
	ldrb r0, [r1]
	b .L0814E830
	.byte 0x00, 0x00
.L0814E814: .4byte gUnknown_087A055B
.L0814E818:
	cmp r0, #0x14
	bne .L0814E822
	ldrh r0, [r4]
	adds r0, r0, r7
	b .L0814E82E
.L0814E822:
	cmp r0, #0x1e
	bne .L0814E832
	ldrh r0, [r4]
	adds r0, r0, r7
	ldrb r0, [r0]
.L0814E82C:
	adds r0, r0, r2
.L0814E82E:
	ldrb r0, [r0]
.L0814E830:
	strh r0, [r4, #0x18]
.L0814E832:
	adds r4, #2
	adds r5, #1
	ldrh r0, [r6, #2]
	cmp r5, r0
	blo .L0814E7D0
.L0814E83C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
