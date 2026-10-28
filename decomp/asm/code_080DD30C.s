	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080DD30C
sub_080DD30C: @ 0x080DD30C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x24
	movs r1, #0
	strh r1, [r5, #0x1c]
	strh r1, [r5, #0x1e]
	ldrb r0, [r6]
	cmp r0, #3
	bne .L080DD332
	ldrb r0, [r6, #0xb]
	cmp r0, #0
	beq .L080DD32C
	b .L080DD7BE
.L080DD32C:
	movs r0, #1
	strh r0, [r5, #0x1c]
	b .L080DD7BE
.L080DD332:
	cmp r0, #2
	bne .L080DD34A
	ldrh r0, [r6, #0x10]
	adds r0, #1
	strh r0, [r6, #0x10]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble .L080DD34A
	strh r1, [r6, #0x10]
	movs r0, #0
	strb r0, [r6]
.L080DD34A:
	ldr r3, .L080DD374
	ldrh r0, [r3]
	movs r4, #1
	ands r4, r0
	cmp r4, #0
	bne .L080DD358
	b .L080DD4E2
.L080DD358:
	movs r0, #0x65
	bl sub_080C51D4
	movs r0, #1
	ldrsb r0, [r6, r0]
	cmp r0, #6
	bls .L080DD368
	b .L080DD6E0
.L080DD368:
	lsls r0, r0, #2
	ldr r1, .L080DD378
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080DD374: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DD378: .4byte gUnknown_080DD37C
	.global gUnknown_080DD37C
gUnknown_080DD37C:
.L080DD37C: @ jump table
	.4byte .L080DD398
	.4byte .L080DD3EC
	.4byte .L080DD418
	.4byte .L080DD450
	.4byte .L080DD4AC
	.4byte .L080DD4C4
	.4byte .L080DD4D8
.L080DD398:
	movs r0, #0xf
	strb r0, [r6, #5]
	ldrb r0, [r6, #0x14]
	subs r0, #1
	strb r0, [r6, #0x14]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge .L080DD3AC
	movs r0, #0x1a
	strb r0, [r6, #0x14]
.L080DD3AC:
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	adds r0, r6, #0
	adds r0, #0x15
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #2]
	ldr r1, .L080DD3E4
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r5, #0
	strh r0, [r6, #0x12]
	ldrb r0, [r6]
	adds r4, r0, #0
	adds r3, r0, #0
	cmp r4, #1
	beq .L080DD3D6
	b .L080DD710
.L080DD3D6:
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r1, .L080DD3E8
	movs r0, #0
	strh r0, [r1]
	b .L080DD49A
.L080DD3E4: .4byte gUnknown_085861C8
.L080DD3E8: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD3EC:
	movs r4, #0
	movs r0, #0xf
	strb r0, [r6, #6]
	strb r4, [r6, #7]
	ldrb r0, [r6]
	adds r3, r0, #0
	cmp r3, #1
	beq .L080DD3FE
	b .L080DD710
.L080DD3FE:
	strb r4, [r6]
	ldrh r0, [r6, #0x12]
	bl m4aSongNumStop
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	ldr r0, .L080DD414
	strh r4, [r0]
	b .L080DD6E0
	.byte 0x00, 0x00
.L080DD414: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD418:
	movs r5, #0
	movs r0, #0xf
	strb r0, [r6, #7]
	strb r5, [r6, #6]
	ldr r1, .L080DD448
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r4, #0
	strh r0, [r6, #0x12]
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD44C
	strh r5, [r0]
	movs r0, #1
	strb r0, [r6]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	b .L080DD6E0
	.byte 0x00, 0x00
.L080DD448: .4byte gUnknown_085861C8
.L080DD44C: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD450:
	movs r7, #0
	movs r0, #0xf
	strb r0, [r6, #8]
	ldrb r0, [r6, #0x14]
	adds r0, #1
	strb r0, [r6, #0x14]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1a
	ble .L080DD466
	strb r7, [r6, #0x14]
.L080DD466:
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	adds r0, r6, #0
	adds r0, #0x15
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #2]
	ldr r1, .L080DD4A4
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r5, #0
	strh r0, [r6, #0x12]
	ldrb r0, [r6]
	adds r4, r0, #0
	adds r3, r0, #0
	cmp r4, #1
	beq .L080DD490
	b .L080DD710
.L080DD490:
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD4A8
	strh r7, [r0]
.L080DD49A:
	strb r4, [r6]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xd]
	strb r5, [r6, #0xc]
	b .L080DD6E0
.L080DD4A4: .4byte gUnknown_085861C8
.L080DD4A8: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD4AC:
	movs r0, #0xf
	strb r0, [r6, #9]
	ldrb r1, [r6, #3]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r6, #3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080DD4C2
	b .L080DD6E0
.L080DD4C2:
	b .L080DD4D0
.L080DD4C4:
	movs r0, #0xf
	strb r0, [r6, #0xa]
	ldrb r1, [r6, #4]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r6, #4]
.L080DD4D0:
	adds r0, r5, #0
	bl Cards_Deal
	b .L080DD6E0
.L080DD4D8:
	movs r0, #0xf
	strb r0, [r6, #0xb]
	movs r0, #3
	strb r0, [r6]
	b .L080DD6E0
.L080DD4E2:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq .L080DD51C
	movs r0, #0xf
	strb r0, [r6, #6]
	strb r4, [r6, #7]
	ldrb r0, [r6]
	cmp r0, #1
	bne .L080DD50E
	strb r4, [r6]
	ldrh r0, [r6, #0x12]
	bl m4aSongNumStop
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	ldr r0, .L080DD518
	strh r4, [r0]
.L080DD50E:
	movs r0, #0x66
	bl sub_080C51D4
	b .L080DD6E0
	.byte 0x00, 0x00
.L080DD518: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD51C:
	ldrh r1, [r3]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L080DD560
	movs r0, #0xf
	strb r0, [r6, #7]
	strb r5, [r6, #6]
	ldr r1, .L080DD558
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r4, #0
	strh r0, [r6, #0x12]
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD55C
	strh r5, [r0]
	movs r0, #1
	strb r0, [r6]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	b .L080DD672
	.byte 0x00, 0x00
.L080DD558: .4byte gUnknown_085861C8
.L080DD55C: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD560:
	ldrh r1, [r3]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq .L080DD584
	adds r1, r6, #0
	adds r1, #0x30
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls .L080DD610
	strb r2, [r1]
	b .L080DD610
.L080DD584:
	ldr r0, .L080DD5A4
	ldrh r2, [r0]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq .L080DD5B0
	ldrb r0, [r6, #1]
	adds r0, #1
	strb r0, [r6, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne .L080DD5A8
	strb r1, [r6, #1]
	b .L080DD610
	.byte 0x00, 0x00
.L080DD5A4: .4byte 0x03003964 @ IWRAM+0x3964
.L080DD5A8:
	cmp r0, #7
	bne .L080DD610
	movs r0, #4
	b .L080DD60E
.L080DD5B0:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq .L080DD5D2
	ldrb r0, [r6, #1]
	subs r0, #1
	strb r0, [r6, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge .L080DD5CA
	movs r0, #3
	b .L080DD60E
.L080DD5CA:
	cmp r0, #3
	bne .L080DD610
	movs r0, #6
	b .L080DD60E
.L080DD5D2:
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080DD5EC
	ldrb r1, [r6, #1]
	movs r0, #1
	ldrsb r0, [r6, r0]
	cmp r0, #3
	bgt .L080DD5E8
	b .L080DD6E0
.L080DD5E8:
	subs r0, r1, #4
	b .L080DD60E
.L080DD5EC:
	ldrh r1, [r3]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	beq .L080DD618
	ldrb r0, [r6, #1]
	movs r1, #1
	ldrsb r1, [r6, r1]
	cmp r1, #3
	bne .L080DD608
	movs r0, #6
	b .L080DD60E
.L080DD608:
	cmp r1, #3
	bgt .L080DD6E0
	adds r0, #4
.L080DD60E:
	strb r0, [r6, #1]
.L080DD610:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DD6E0
.L080DD618:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0
	beq .L080DD684
	movs r0, #0xf
	strb r0, [r6, #8]
	ldrb r0, [r6, #0x14]
	adds r0, #1
	strb r0, [r6, #0x14]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1a
	ble .L080DD63C
	strb r7, [r6, #0x14]
.L080DD63C:
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	adds r0, r6, #0
	adds r0, #0x15
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #2]
	ldr r1, .L080DD67C
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r5, #0
	strh r0, [r6, #0x12]
	ldrb r4, [r6]
	cmp r4, #1
	bne .L080DD672
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD680
	strh r7, [r0]
	strb r4, [r6]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xd]
	strb r5, [r6, #0xc]
.L080DD672:
	movs r0, #0x65
	bl sub_080C51D4
	b .L080DD6E0
	.byte 0x00, 0x00
.L080DD67C: .4byte gUnknown_085861C8
.L080DD680: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD684:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080DD6E0
	movs r0, #0xf
	strb r0, [r6, #5]
	ldrb r0, [r6, #0x14]
	subs r0, #1
	strb r0, [r6, #0x14]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge .L080DD6A2
	movs r0, #0x1a
	strb r0, [r6, #0x14]
.L080DD6A2:
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	adds r0, r6, #0
	adds r0, #0x15
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #2]
	ldr r1, .L080DD73C
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r5, #0
	strh r0, [r6, #0x12]
	ldrb r4, [r6]
	cmp r4, #1
	bne .L080DD6DA
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD740
	mov r1, r8
	strh r1, [r0]
	strb r4, [r6]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xd]
	strb r5, [r6, #0xc]
.L080DD6DA:
	movs r0, #0x65
	bl sub_080C51D4
.L080DD6E0:
	ldrb r0, [r6]
	adds r3, r0, #0
	cmp r3, #1
	bne .L080DD710
	ldrb r0, [r6, #0xe]
	adds r0, #1
	movs r1, #0
	strb r0, [r6, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls .L080DD710
	strb r1, [r6, #0xe]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls .L080DD710
	strb r1, [r6, #0xd]
	ldrb r0, [r6, #0xc]
	adds r0, #1
	strb r0, [r6, #0xc]
.L080DD710:
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	ldr r1, .L080DD73C
	adds r2, r0, r1
	ldrb r0, [r6, #0xc]
	adds r4, r1, #0
	ldrb r1, [r2, #2]
	cmp r0, r1
	bne .L080DD744
	ldrb r1, [r6, #0xd]
	ldrb r0, [r2, #3]
	subs r0, #2
	cmp r1, r0
	bne .L080DD744
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne .L080DD744
	movs r0, #8
	bl sub_080C51BC
	b .L080DD7BE
.L080DD73C: .4byte gUnknown_085861C8
.L080DD740: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD744:
	ldrh r0, [r6, #0xc]
	ldrh r2, [r2, #2]
	cmp r0, r2
	bne .L080DD7BE
	ldrb r0, [r6, #0xe]
	cmp r0, #0xa
	bls .L080DD7BE
	ldrb r5, [r6, #3]
	cmp r5, #1
	bne .L080DD7A0
	ldrb r0, [r6, #0x14]
	adds r0, #1
	movs r7, #0
	strb r0, [r6, #0x14]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1a
	ble .L080DD76A
	strb r7, [r6, #0x14]
.L080DD76A:
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	adds r0, r6, #0
	adds r0, #0x15
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #2]
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r4, #0
	strh r0, [r6, #0x12]
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD79C
	strh r7, [r0]
	strb r5, [r6]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	b .L080DD7BE
	.byte 0x00, 0x00
.L080DD79C: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD7A0:
	movs r4, #0
	movs r0, #0xf
	strb r0, [r6, #6]
	strb r4, [r6, #7]
	cmp r3, #1
	bne .L080DD7BE
	strb r4, [r6]
	ldrh r0, [r6, #0x12]
	bl m4aSongNumStop
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	ldr r0, .L080DD7C8
	strh r4, [r0]
.L080DD7BE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080DD7C8: .4byte 0x030031B4 @ IWRAM+0x31B4

	thumb_func_start sub_080DD7CC
sub_080DD7CC: @ 0x080DD7CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0x24
	adds r0, r0, r5
	mov sb, r0
	movs r4, #2
	ldrsb r4, [r0, r4]
	adds r0, r4, #0
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r7, #2
	ldr r1, .L080DD974
	adds r0, r0, r1
	ldr r0, [r0]
	movs r3, #0xa0
	lsls r3, r3, #1
	mov sl, r3
	str r3, [sp]
	movs r1, #0x31
	str r1, [sp, #4]
	movs r4, #0x2b
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r0, r6, #2
	ldr r1, .L080DD974
	adds r0, r0, r1
	ldr r0, [r0]
	mov r3, sl
	str r3, [sp]
	movs r1, #0x39
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DD978
	mov r1, sl
	str r1, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	mov r3, sb
	ldrb r2, [r3, #4]
	lsls r1, r2, #3
	adds r1, r1, r2
	adds r1, #0x20
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	movs r0, #0xf0
	lsls r0, r0, #2
	bl Font_ResetGlyphSpriteCache
	ldr r4, .L080DD97C
	mov r1, sb
	movs r0, #2
	ldrsb r0, [r1, r0]
	lsls r0, r0, #3
	adds r1, r4, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x3a
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0xe
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0x15
	bl Text_DrawSpriteStringTinted
	mov r3, sb
	ldrb r0, [r3, #3]
	cmp r0, #1
	bne .L080DD8C2
	ldr r2, .L080DD980
	ldr r0, .L080DD984
	mov r1, sl
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DD988
	mov r3, sl
	str r3, [sp]
	movs r1, #0x66
	str r1, [sp, #4]
	movs r1, #0x41
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DD8C2:
	adds r0, r5, #0
	adds r0, #0x54
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080DD98C
	mov r0, sb
	ldrb r4, [r0, #0xc]
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r7, #2
	ldr r1, .L080DD974
	adds r0, r0, r1
	ldr r0, [r0]
	mov r3, sl
	str r3, [sp]
	movs r1, #0x3b
	str r1, [sp, #4]
	movs r1, #0x43
	mov r8, r1
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r0, r6, #2
	ldr r3, .L080DD974
	adds r0, r0, r3
	ldr r0, [r0]
	mov r1, sl
	str r1, [sp]
	mov r3, r8
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	mov r0, sb
	ldrb r4, [r0, #0xd]
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r7, #2
	ldr r1, .L080DD974
	adds r0, r0, r1
	ldr r0, [r0]
	mov r3, sl
	str r3, [sp]
	movs r1, #0x53
	str r1, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r0, r6, #2
	ldr r3, .L080DD974
	adds r0, r0, r3
	ldr r0, [r0]
	mov r1, sl
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	b .L080DDBF4
.L080DD974: .4byte gUnknown_085861A0
.L080DD978: .4byte gUnknown_080087B8
.L080DD97C: .4byte gUnknown_085861C8
.L080DD980: .4byte gUnknown_0858617C
.L080DD984: .4byte gUnknown_08008958
.L080DD988: .4byte gUnknown_08008C44
.L080DD98C:
	cmp r0, #1
	bne .L080DDA7C
	mov r1, sb
	movs r0, #2
	ldrsb r0, [r1, r0]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldrb r2, [r0, #2]
	ldrb r1, [r1, #0xc]
	subs r2, r2, r1
	lsls r2, r2, #0x18
	ldrb r0, [r0, #3]
	mov r3, sb
	ldrb r1, [r3, #0xd]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsrs r4, r2, #0x18
	asrs r2, r2, #0x18
	cmp r2, #0
	ble .L080DD9CC
	lsls r0, r5, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	bge .L080DD9CC
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r1, #0
	adds r0, #0x3c
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L080DD9CC:
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, .L080DDA78
	mov r8, r0
	lsls r0, r7, #2
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x3b
	str r1, [sp, #4]
	movs r3, #0x43
	mov sl, r3
	str r3, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r0, r6, #2
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	mov r3, sl
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r4, r5, #0x18
	asrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r7, #2
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x53
	str r1, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r0, r6, #2
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	b .L080DDBF4
.L080DDA78: .4byte gUnknown_085861A0
.L080DDA7C:
	cmp r0, #2
	beq .L080DDA82
	b .L080DDC24
.L080DDA82:
	mov r1, sb
	ldrb r0, [r1, #0xd]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x11
	adds r0, r0, r3
	lsrs r4, r0, #0x18
	cmp r4, #9
	bls .L080DDA9E
	movs r4, #0
.L080DDA9E:
	mov r0, sb
	ldrb r1, [r0, #0xe]
	cmp r1, #0xb
	bhi .L080DDAAC
	movs r1, #0
	mov r8, r1
	b .L080DDAF8
.L080DDAAC:
	adds r0, r1, #0
	subs r0, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bhi .L080DDABE
	movs r3, #1
	mov r8, r3
	b .L080DDB20
.L080DDABE:
	adds r0, r1, #0
	subs r0, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bhi .L080DDAD0
	movs r0, #2
	mov r8, r0
	b .L080DDB20
.L080DDAD0:
	adds r0, r1, #0
	subs r0, #0x24
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bhi .L080DDAE2
	movs r1, #3
	mov r8, r1
	b .L080DDB20
.L080DDAE2:
	adds r0, r1, #0
	subs r0, #0x30
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bhi .L080DDAF2
	movs r3, #4
	mov r8, r3
.L080DDAF2:
	mov r0, r8
	cmp r0, #0
	bne .L080DDB20
.L080DDAF8:
	ldr r1, .L080DDB1C
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x3b
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDB40
	.byte 0x00, 0x00
.L080DDB1C: .4byte gUnknown_085861A0
.L080DDB20:
	ldr r1, .L080DDB68
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x3b
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDB40:
	mov r1, r8
	cmp r1, #1
	bhi .L080DDB6C
	ldr r1, .L080DDB68
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x43
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDB8A
	.byte 0x00, 0x00
.L080DDB68: .4byte gUnknown_085861A0
.L080DDB6C:
	ldr r1, .L080DDBB4
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x43
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDB8A:
	mov r3, r8
	cmp r3, #2
	bhi .L080DDBB8
	ldr r1, .L080DDBB4
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x53
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDBD8
	.byte 0x00, 0x00
.L080DDBB4: .4byte gUnknown_085861A0
.L080DDBB8:
	ldr r1, .L080DDC00
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x53
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDBD8:
	mov r0, r8
	cmp r0, #3
	bhi .L080DDC04
	ldr r1, .L080DDC00
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
.L080DDBF4:
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDC24
.L080DDC00: .4byte gUnknown_085861A0
.L080DDC04:
	ldr r1, .L080DDC98
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDC24:
	movs r3, #0
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne .L080DDC34
	movs r3, #1
.L080DDC34:
	ldr r0, .L080DDC9C
	cmp r1, r0
	bne .L080DDC44
	mov r1, sb
	ldrb r0, [r1, #7]
	cmp r0, #0x3b
	bhi .L080DDC44
	movs r3, #1
.L080DDC44:
	mov r1, sb
	ldr r0, [r1]
	ldr r1, .L080DDCA0
	ands r0, r1
	ldr r1, .L080DDCA4
	cmp r0, r1
	bne .L080DDC54
	movs r3, #1
.L080DDC54:
	mov r1, sb
	movs r0, #1
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bne .L080DDC66
	ldrb r0, [r1, #4]
	cmp r0, #1
	bne .L080DDC66
	movs r3, #1
.L080DDC66:
	mov r1, sb
	movs r0, #1
	ldrsb r0, [r1, r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, .L080DDCA8
	adds r2, r1, r0
	cmp r3, #1
	bne .L080DDCAC
	ldr r0, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDCC6
	.byte 0x00, 0x00
.L080DDC98: .4byte gUnknown_085861A0
.L080DDC9C: .4byte 0x00000201
.L080DDCA0: .4byte 0xFF00FF00
.L080DDCA4: .4byte 0x01000400
.L080DDCA8: .4byte gUnknown_0858614C
.L080DDCAC:
	ldr r0, [r2, #4]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDCC6:
	mov r3, sb
	ldrb r0, [r3, #5]
	cmp r0, #0
	beq .L080DDCEE
	subs r0, #1
	strb r0, [r3, #5]
	ldr r2, .L080DDD48
	ldr r0, .L080DDD4C
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDCEE:
	mov r1, sb
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq .L080DDD16
	subs r0, #1
	strb r0, [r1, #8]
	ldr r2, .L080DDD50
	ldr r0, .L080DDD54
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDD16:
	mov r3, sb
	ldrb r0, [r3, #7]
	cmp r0, #0
	beq .L080DDD60
	subs r0, #1
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x2c
	bhi .L080DDD6C
	ldr r2, .L080DDD58
	ldr r0, .L080DDD5C
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDD6C
.L080DDD48: .4byte gUnknown_0858614C
.L080DDD4C: .4byte gUnknown_08008890
.L080DDD50: .4byte gUnknown_08586170
.L080DDD54: .4byte gUnknown_08008928
.L080DDD58: .4byte gUnknown_08586164
.L080DDD5C: .4byte gUnknown_080088F0
.L080DDD60:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #1
	bne .L080DDD6C
	movs r0, #0x5a
	strb r0, [r1, #7]
.L080DDD6C:
	mov r3, sb
	ldrb r0, [r3, #6]
	cmp r0, #0
	beq .L080DDD90
	ldr r2, .L080DDE18
	ldr r0, .L080DDE1C
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDD90:
	mov r1, sb
	ldrb r0, [r1, #0xb]
	cmp r0, #0
	beq .L080DDDB8
	subs r0, #1
	strb r0, [r1, #0xb]
	ldr r2, .L080DDE20
	ldr r0, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDDB8:
	mov r3, sb
	ldrb r0, [r3, #9]
	cmp r0, #0
	beq .L080DDDE0
	subs r0, #1
	strb r0, [r3, #9]
	ldr r2, .L080DDE24
	ldr r0, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDDE0:
	mov r1, sb
	ldrb r0, [r1, #0xa]
	cmp r0, #0
	beq .L080DDE08
	subs r0, #1
	strb r0, [r1, #0xa]
	ldr r2, .L080DDE28
	ldr r0, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDE08:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080DDE18: .4byte gUnknown_08586158
.L080DDE1C: .4byte gUnknown_080088C0
.L080DDE20: .4byte gUnknown_08586194
.L080DDE24: .4byte gUnknown_0858617C
.L080DDE28: .4byte gUnknown_08586188
