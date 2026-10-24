	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_0813D0F4
sub_0813D0F4: @ 0x0813D0F4
	push {lr}
	bl sub_080B092C
	adds r1, r0, #0
	cmp r1, #1
	beq .L0813D106
	ldr r0, .L0813D110
	movs r1, #0
	strh r1, [r0]
.L0813D106:
	ldr r0, .L0813D114
	strh r1, [r0]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D110: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D114: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D118
sub_0813D118: @ 0x0813D118
	push {lr}
	ldr r0, .L0813D13C
	ldr r0, [r0]
	bl sub_080CE74C
	cmp r0, #0
	beq .L0813D132
	ldr r1, .L0813D140
	movs r0, #0xf
	strh r0, [r1]
	ldr r1, .L0813D144
	movs r0, #0x3c
	strh r0, [r1]
.L0813D132:
	ldr r1, .L0813D148
	movs r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
.L0813D13C: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813D140: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D144: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L0813D148: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D14C
sub_0813D14C: @ 0x0813D14C
	ldr r1, .L0813D154
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D154: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D158
sub_0813D158: @ 0x0813D158
	ldr r1, .L0813D160
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D160: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D164
sub_0813D164: @ 0x0813D164
	ldr r1, .L0813D16C
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D16C: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D170
sub_0813D170: @ 0x0813D170
	ldr r1, .L0813D178
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D178: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D17C
sub_0813D17C: @ 0x0813D17C
	ldr r1, .L0813D184
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D184: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D188
sub_0813D188: @ 0x0813D188
	ldr r0, .L0813D19C
	movs r2, #0
	strh r2, [r0]
	ldr r1, .L0813D1A0
	ldr r0, .L0813D1A4
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L0813D1A8
	strh r2, [r0]
	bx lr
.L0813D19C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D1A0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D1A4: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D1A8: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D1AC
sub_0813D1AC: @ 0x0813D1AC
	ldr r0, .L0813D1B8
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D1BC
	strh r1, [r0]
	bx lr
.L0813D1B8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D1BC: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D1C0
sub_0813D1C0: @ 0x0813D1C0
	push {r4, lr}
	ldr r4, .L0813D1D4
	ldr r0, [r4]
	bl sub_080B7DF8
	cmp r0, #0
	bne .L0813D1DC
	ldr r1, .L0813D1D8
	movs r0, #1
	b .L0813D1E6
.L0813D1D4: .4byte 0x03006954 @ IWRAM+0x6954
.L0813D1D8: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D1DC:
	movs r0, #0
	str r0, [r4]
	ldr r1, .L0813D1F0
	strh r0, [r1]
	ldr r1, .L0813D1F4
.L0813D1E6:
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D1F0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D1F4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D1F8
sub_0813D1F8: @ 0x0813D1F8
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813D1FC
sub_0813D1FC: @ 0x0813D1FC
	push {lr}
	ldr r0, .L0813D214
	ldr r0, [r0]
	bl sub_080D1EA8
	cmp r0, #0
	bne .L0813D21C
	ldr r1, .L0813D218
	movs r0, #1
	strh r0, [r1]
	b .L0813D226
	.byte 0x00, 0x00
.L0813D214: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813D218: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D21C:
	ldr r0, .L0813D22C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D230
	strh r1, [r0]
.L0813D226:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D22C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D230: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D234
sub_0813D234: @ 0x0813D234
	push {r4, lr}
	ldr r4, .L0813D248
	ldr r0, [r4]
	bl sub_080B8160
	cmp r0, #0
	bne .L0813D250
	ldr r1, .L0813D24C
	movs r0, #1
	b .L0813D25A
.L0813D248: .4byte 0x03006938 @ IWRAM+0x6938
.L0813D24C: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D250:
	movs r0, #0
	str r0, [r4]
	ldr r1, .L0813D264
	strh r0, [r1]
	ldr r1, .L0813D268
.L0813D25A:
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D264: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D268: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D26C
sub_0813D26C: @ 0x0813D26C
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L0813D2E4
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D2E8
	strh r1, [r0]
	ldr r0, .L0813D2EC
	strh r1, [r0]
	ldr r0, .L0813D2F0
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r5, .L0813D2F4
	ldr r0, .L0813D2F8
	ldrh r0, [r0]
	subs r0, #0x90
	strh r0, [r5]
	ldr r4, .L0813D2FC
	ldrh r0, [r5]
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r0, r3, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r2, [r0]
	adds r3, #2
	lsls r3, r3, #1
	adds r3, r3, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	bl sub_080B7E3C
	ldr r3, .L0813D300
	ldr r2, .L0813D304
	ldr r1, .L0813D308
	ldrh r0, [r5]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, .L0813D30C
	strh r4, [r0]
	ldr r0, .L0813D310
	strh r4, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D2E4: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813D2E8: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813D2EC: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813D2F0: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0813D2F4: .4byte 0x0203DB72 @ EWRAM+0x3DB72
.L0813D2F8: .4byte 0x030065E0 @ IWRAM+0x65E0
.L0813D2FC: .4byte gUnknown_0878FFD0
.L0813D300: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D304: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D308: .4byte gUnknown_08790E4C
.L0813D30C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D310: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D314
sub_0813D314: @ 0x0813D314
	push {r4, lr}
	ldr r0, .L0813D348
	movs r4, #0
	strh r4, [r0]
	ldr r0, .L0813D34C
	strh r4, [r0]
	ldr r0, .L0813D350
	strh r4, [r0]
	ldr r0, .L0813D354
	strh r4, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r1, .L0813D358
	ldr r0, .L0813D35C
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L0813D360
	strh r4, [r0]
	ldr r0, .L0813D364
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D348: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813D34C: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813D350: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813D354: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0813D358: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D35C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D360: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D364: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D368
sub_0813D368: @ 0x0813D368
	ldr r1, .L0813D37C
	ldr r0, .L0813D380
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L0813D384
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D388
	strh r1, [r0]
	bx lr
.L0813D37C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D380: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D384: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D388: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D38C
sub_0813D38C: @ 0x0813D38C
	ldr r0, .L0813D398
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D39C
	strh r1, [r0]
	bx lr
.L0813D398: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D39C: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D3A0
sub_0813D3A0: @ 0x0813D3A0
	ldr r1, .L0813D3A8
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D3A8: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D3AC
sub_0813D3AC: @ 0x0813D3AC
	ldr r1, .L0813D3B4
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D3B4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D3B8
sub_0813D3B8: @ 0x0813D3B8
	ldr r1, .L0813D3C0
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D3C0: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D3C4
sub_0813D3C4: @ 0x0813D3C4
	ldr r1, .L0813D3CC
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D3CC: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D3D0
sub_0813D3D0: @ 0x0813D3D0
	ldr r1, .L0813D3D8
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D3D8: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D3DC
sub_0813D3DC: @ 0x0813D3DC
	ldr r1, .L0813D3E4
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D3E4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D3E8
sub_0813D3E8: @ 0x0813D3E8
	ldr r1, .L0813D3F0
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D3F0: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D3F4
sub_0813D3F4: @ 0x0813D3F4
	push {r4, lr}
	movs r1, #0
	ldr r0, .L0813D414
	ldrh r4, [r0]
	cmp r4, #0
	bne .L0813D454
	bl sub_0812DC10
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xfe
	bne .L0813D41C
	ldr r1, .L0813D418
	movs r0, #1
	strh r0, [r1]
	b .L0813D460
.L0813D414: .4byte 0x030065E8 @ IWRAM+0x65E8
.L0813D418: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D41C:
	cmp r1, #0xff
	bne .L0813D434
	ldr r1, .L0813D42C
	ldr r0, .L0813D430
	ldr r0, [r0]
	str r0, [r1]
	b .L0813D438
	.byte 0x00, 0x00
.L0813D42C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D430: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D434:
	ldr r0, .L0813D448
	strh r1, [r0]
.L0813D438:
	ldr r0, .L0813D44C
	strh r4, [r0]
	ldr r0, .L0813D450
	strh r4, [r0]
	adds r1, r0, #0
	movs r0, #0
	strh r0, [r1]
	b .L0813D460
.L0813D448: .4byte 0x03006944 @ IWRAM+0x6944
.L0813D44C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D450: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D454:
	ldr r0, .L0813D468
	strh r1, [r0]
	ldr r0, .L0813D46C
	strh r1, [r0]
	ldr r0, .L0813D470
	strh r1, [r0]
.L0813D460:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D468: .4byte 0x03006944 @ IWRAM+0x6944
.L0813D46C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D470: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D474
sub_0813D474: @ 0x0813D474
	push {lr}
	ldr r0, .L0813D48C
	ldr r0, [r0]
	bl sub_080CE74C
	cmp r0, #0
	bne .L0813D494
	ldr r1, .L0813D490
	movs r0, #1
	strh r0, [r1]
	b .L0813D4AE
	.byte 0x00, 0x00
.L0813D48C: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813D490: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D494:
	ldr r0, .L0813D4B4
	movs r2, #0
	strh r2, [r0]
	ldr r0, .L0813D4B8
	ldr r0, [r0]
	cmp r0, #1
	bne .L0813D4AA
	ldr r0, .L0813D4BC
	ldr r1, .L0813D4C0
	ldr r1, [r1]
	str r1, [r0]
.L0813D4AA:
	ldr r0, .L0813D4C4
	strh r2, [r0]
.L0813D4AE:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D4B4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D4B8: .4byte 0x030031CC @ IWRAM+0x31CC
.L0813D4BC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D4C0: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D4C4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D4C8
sub_0813D4C8: @ 0x0813D4C8
	push {r4, lr}
	ldr r1, .L0813D4F8
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	bne .L0813D4EA
	ldr r0, .L0813D4FC
	strh r4, [r0]
	ldr r0, .L0813D500
	ldr r0, [r0]
	bl sub_080D34F0
	ldr r0, .L0813D504
	strh r4, [r0]
.L0813D4EA:
	ldr r1, .L0813D504
	movs r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D4F8: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L0813D4FC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D500: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813D504: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D508
sub_0813D508: @ 0x0813D508
	ldr r0, .L0813D518
	movs r1, #0
	str r1, [r0]
	ldr r0, .L0813D51C
	strh r1, [r0]
	ldr r0, .L0813D520
	strh r1, [r0]
	bx lr
.L0813D518: .4byte 0x03006954 @ IWRAM+0x6954
.L0813D51C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D520: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D524
sub_0813D524: @ 0x0813D524
	ldr r0, .L0813D530
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D534
	strh r1, [r0]
	bx lr
.L0813D530: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D534: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D538
sub_0813D538: @ 0x0813D538
	ldr r0, .L0813D544
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D548
	strh r1, [r0]
	bx lr
.L0813D544: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D548: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D54C
sub_0813D54C: @ 0x0813D54C
	push {r4, lr}
	ldr r4, .L0813D560
	ldr r0, [r4]
	bl sub_080B9528
	cmp r0, #0
	bne .L0813D568
	ldr r1, .L0813D564
	movs r0, #1
	b .L0813D572
.L0813D560: .4byte 0x03006954 @ IWRAM+0x6954
.L0813D564: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D568:
	movs r0, #0
	str r0, [r4]
	ldr r1, .L0813D57C
	strh r0, [r1]
	ldr r1, .L0813D580
.L0813D572:
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D57C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D580: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D584
sub_0813D584: @ 0x0813D584
	push {lr}
	bl sub_080BA920
	cmp r0, #0
	bne .L0813D59C
	ldr r1, .L0813D598
	movs r0, #1
	strh r0, [r1]
	b .L0813D5AA
	.byte 0x00, 0x00
.L0813D598: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D59C:
	ldr r0, .L0813D5B0
	movs r1, #0
	str r1, [r0]
	ldr r0, .L0813D5B4
	strh r1, [r0]
	ldr r0, .L0813D5B8
	strh r1, [r0]
.L0813D5AA:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D5B0: .4byte 0x03006954 @ IWRAM+0x6954
.L0813D5B4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D5B8: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D5BC
sub_0813D5BC: @ 0x0813D5BC
	push {r4, r5, lr}
	ldr r0, .L0813D5D4
	ldr r0, [r0]
	bl sub_080CE74C
	cmp r0, #0
	bne .L0813D5DC
	ldr r1, .L0813D5D8
	movs r0, #1
	strh r0, [r1]
	b .L0813D628
	.byte 0x00, 0x00
.L0813D5D4: .4byte 0x03006964 @ IWRAM+0x6964
.L0813D5D8: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D5DC:
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r2, #0x18
	ldrsh r1, [r0, r2]
	ldr r5, .L0813D608
	ldr r0, [r5]
	cmp r1, r0
	bhi .L0813D60C
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0
	strh r1, [r0, #0x18]
	movs r0, #0
	adds r1, r4, #0
	bl sub_080C08E8
	b .L0813D61A
	.byte 0x00, 0x00
.L0813D608: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813D60C:
	adds r0, r4, #0
	bl Battle_GetCombatant
	ldr r2, [r5]
	ldrh r1, [r0, #0x18]
	subs r1, r1, r2
	strh r1, [r0, #0x18]
.L0813D61A:
	bl sub_080C84A0
	ldr r0, .L0813D630
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D634
	strh r1, [r0]
.L0813D628:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D630: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D634: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D638
sub_0813D638: @ 0x0813D638
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	ldr r0, .L0813D658
	ldr r0, [r0]
	bl sub_080B8B08
	cmp r0, #0
	bne .L0813D660
	ldr r1, .L0813D65C
	movs r0, #1
	strh r0, [r1]
	b .L0813D710
	.byte 0x00, 0x00
.L0813D658: .4byte 0x03006964 @ IWRAM+0x6964
.L0813D65C: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D660:
	bl sub_080C104C
	mov r8, r0
	movs r4, #0
	adds r0, #4
	cmp r4, r0
	bge .L0813D6F2
.L0813D66E:
	lsls r4, r4, #0x10
	asrs r6, r4, #0x10
	adds r0, r6, #0
	bl sub_080C0A00
	adds r7, r4, #0
	cmp r0, #1
	bne .L0813D6E0
	adds r0, r6, #0
	bl sub_080F3EC8
	cmp r0, #1
	bne .L0813D6E0
	ldr r1, .L0813D6D0
	adds r0, r6, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r5, #0
	bl Battle_GetCombatant
	ldrh r0, [r0, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r0, #0
	bgt .L0813D6A6
	movs r4, #1
.L0813D6A6:
	adds r0, r5, #0
	bl Battle_GetCombatant
	movs r2, #0x18
	ldrsh r1, [r0, r2]
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	cmp r1, r4
	bgt .L0813D6D4
	adds r0, r5, #0
	bl Battle_GetCombatant
	movs r1, #0
	strh r1, [r0, #0x18]
	adds r0, r6, #0
	movs r1, #0x80
	lsls r1, r1, #8
	bl sub_080C08E8
	b .L0813D6E0
	.byte 0x00, 0x00
.L0813D6D0: .4byte 0xFFFF8000
.L0813D6D4:
	adds r0, r5, #0
	bl Battle_GetCombatant
	ldrh r1, [r0, #0x18]
	subs r1, r1, r4
	strh r1, [r0, #0x18]
.L0813D6E0:
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r7, r0
	lsrs r4, r1, #0x10
	asrs r1, r1, #0x10
	mov r0, r8
	adds r0, #4
	cmp r1, r0
	blt .L0813D66E
.L0813D6F2:
	bl sub_080C84A0
	bl sub_08138CE8
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813D706
	movs r0, #1
	mov r1, sb
	strh r0, [r1, #0x1c]
.L0813D706:
	ldr r0, .L0813D71C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D720
	strh r1, [r0]
.L0813D710:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0813D71C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D720: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D724
sub_0813D724: @ 0x0813D724
	push {r4, lr}
	bl sub_080D53E0
	cmp r0, #1
	beq .L0813D73C
	ldr r1, .L0813D738
	movs r0, #1
	strh r0, [r1]
	b .L0813D79E
	.byte 0x00, 0x00
.L0813D738: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D73C:
	ldr r4, .L0813D754
	ldr r1, [r4]
	cmp r1, #0
	beq .L0813D794
	ldr r0, .L0813D758
	cmp r1, r0
	bls .L0813D764
	ldr r0, .L0813D75C
	ldr r1, .L0813D760
	ldr r1, [r1, #8]
	str r1, [r0]
	b .L0813D794
.L0813D754: .4byte 0x030037F0 @ IWRAM+0x37F0
.L0813D758: .4byte 0x0000C350
.L0813D75C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D760: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D764:
	bl sub_080C31F0
	ldr r2, [r4]
	adds r0, r0, r2
	ldr r1, .L0813D77C
	cmp r0, r1
	bls .L0813D788
	ldr r0, .L0813D780
	ldr r1, .L0813D784
	ldr r1, [r1, #4]
	str r1, [r0]
	b .L0813D794
.L0813D77C: .4byte 0x000F423F
.L0813D780: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D784: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D788:
	ldr r0, .L0813D7A4
	str r2, [r0]
	ldr r1, .L0813D7A8
	ldr r0, .L0813D7AC
	ldr r0, [r0]
	str r0, [r1]
.L0813D794:
	ldr r0, .L0813D7B0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D7B4
	strh r1, [r0]
.L0813D79E:
	pop {r4}
	pop {r0}
	bx r0
.L0813D7A4: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813D7A8: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D7AC: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D7B0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D7B4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D7B8
sub_0813D7B8: @ 0x0813D7B8
	push {lr}
	ldr r0, .L0813D7D0
	ldr r0, [r0]
	bl sub_080CE74C
	cmp r0, #0
	bne .L0813D7D8
	ldr r1, .L0813D7D4
	movs r0, #1
	strh r0, [r1]
	b .L0813D7F8
	.byte 0x00, 0x00
.L0813D7D0: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813D7D4: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D7D8:
	ldr r0, .L0813D7FC
	ldr r0, [r0]
	cmp r0, #1
	beq .L0813D7EE
	ldr r1, .L0813D800
	ldr r0, .L0813D804
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, .L0813D808
	movs r0, #1
	strh r0, [r1]
.L0813D7EE:
	ldr r0, .L0813D80C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D810
	strh r1, [r0]
.L0813D7F8:
	pop {r0}
	bx r0
.L0813D7FC: .4byte 0x030031CC @ IWRAM+0x31CC
.L0813D800: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D804: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D808: .4byte 0x0203DB86 @ EWRAM+0x3DB86
.L0813D80C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D810: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D814
sub_0813D814: @ 0x0813D814
	push {r4, lr}
	ldr r0, .L0813D82C
	ldr r0, [r0]
	bl sub_080CE74C
	cmp r0, #0
	bne .L0813D834
	ldr r1, .L0813D830
	movs r0, #1
	strh r0, [r1]
	b .L0813D890
	.byte 0x00, 0x00
.L0813D82C: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813D830: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D834:
	bl sub_0812EEC4
	adds r4, r0, #0
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x1f
	bl sub_0813E60C
	movs r1, #0xff
	ands r1, r0
	cmp r1, #0xbf
	bls .L0813D850
	movs r3, #0x1c
	b .L0813D86E
.L0813D850:
	ldr r0, .L0813D898
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r3, [r1]
	adds r0, r3, #0
	subs r0, #0xa
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0813D86E
	ldr r2, .L0813D89C
	ldr r1, .L0813D8A0
	ldrh r0, [r1]
	strh r0, [r2]
	strh r4, [r1]
.L0813D86E:
	lsls r0, r3, #0x11
	ldr r1, .L0813D8A4
	ldr r2, .L0813D8A8
	str r2, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	orrs r0, r1
	ldr r1, .L0813D8AC
	str r0, [r1]
	ldr r0, .L0813D8B0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D8B4
	strh r1, [r0]
.L0813D890:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D898: .4byte gUnknown_08790E5A
.L0813D89C: .4byte 0x0203DB80 @ EWRAM+0x3DB80
.L0813D8A0: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813D8A4: .4byte 0x03006950 @ IWRAM+0x6950
.L0813D8A8: .4byte gUnknown_08032CD8
.L0813D8AC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D8B0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D8B4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D8B8
sub_0813D8B8: @ 0x0813D8B8
	push {lr}
	movs r0, #0
	bl sub_080D3AA0
	cmp r0, #1
	beq .L0813D8D0
	ldr r1, .L0813D8CC
	movs r0, #1
	strh r0, [r1]
	b .L0813D8EA
.L0813D8CC: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D8D0:
	ldr r0, .L0813D8F0
	ldr r0, [r0]
	cmp r0, #1
	bne .L0813D8E0
	ldr r0, .L0813D8F4
	ldr r1, .L0813D8F8
	ldr r1, [r1]
	str r1, [r0]
.L0813D8E0:
	ldr r0, .L0813D8FC
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D900
	strh r1, [r0]
.L0813D8EA:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D8F0: .4byte 0x030031CC @ IWRAM+0x31CC
.L0813D8F4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D8F8: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D8FC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D900: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D904
sub_0813D904: @ 0x0813D904
	push {lr}
	bl sub_080D3CCC
	cmp r0, #1
	beq .L0813D91C
	ldr r1, .L0813D918
	movs r0, #1
	strh r0, [r1]
	b .L0813D950
	.byte 0x00, 0x00
.L0813D918: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D91C:
	bl sub_080D3CE4
	adds r1, r0, #0
	subs r0, r1, #1
	cmp r0, #1
	bhi .L0813D938
	ldr r0, .L0813D930
	ldr r1, .L0813D934
	ldr r1, [r1]
	b .L0813D944
.L0813D930: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D934: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D938:
	subs r0, r1, #3
	cmp r0, #1
	bhi .L0813D946
	ldr r0, .L0813D954
	ldr r1, .L0813D958
	ldr r1, [r1, #4]
.L0813D944:
	str r1, [r0]
.L0813D946:
	ldr r0, .L0813D95C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D960
	strh r1, [r0]
.L0813D950:
	pop {r0}
	bx r0
.L0813D954: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D958: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D95C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D960: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D964
sub_0813D964: @ 0x0813D964
	push {lr}
	bl sub_080D4594
	cmp r0, #1
	beq .L0813D97C
	ldr r1, .L0813D978
	movs r0, #1
	strh r0, [r1]
	b .L0813D986
	.byte 0x00, 0x00
.L0813D978: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D97C:
	ldr r0, .L0813D98C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D990
	strh r1, [r0]
.L0813D986:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D98C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D990: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D994
sub_0813D994: @ 0x0813D994
	ldr r0, .L0813D9A8
	movs r2, #0
	strh r2, [r0]
	ldr r1, .L0813D9AC
	ldr r0, .L0813D9B0
	ldr r0, [r0, #8]
	str r0, [r1]
	ldr r0, .L0813D9B4
	strh r2, [r0]
	bx lr
.L0813D9A8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D9AC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813D9B0: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813D9B4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D9B8
sub_0813D9B8: @ 0x0813D9B8
	ldr r1, .L0813D9C0
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813D9C0: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D9C4
sub_0813D9C4: @ 0x0813D9C4
	push {lr}
	ldr r0, .L0813D9E8
	ldr r0, [r0]
	bl Window_IsIdle
	cmp r0, #0
	beq .L0813D9DE
	ldr r1, .L0813D9EC
	movs r0, #0xa
	strh r0, [r1]
	ldr r1, .L0813D9F0
	movs r0, #0xf
	strh r0, [r1]
.L0813D9DE:
	ldr r1, .L0813D9F4
	movs r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
.L0813D9E8: .4byte 0x03006968 @ IWRAM+0x6968
.L0813D9EC: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L0813D9F0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D9F4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D9F8
sub_0813D9F8: @ 0x0813D9F8
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813D9FC
sub_0813D9FC: @ 0x0813D9FC
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813DA00
sub_0813DA00: @ 0x0813DA00
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813DA04
sub_0813DA04: @ 0x0813DA04
	ldr r1, .L0813DA10
	ldrh r0, [r1]
	adds r0, #4
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813DA10: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start sub_0813DA14
sub_0813DA14: @ 0x0813DA14
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x75
	beq .L0813DA62
	cmp r0, #0x20
	beq .L0813DA62
	cmp r0, #0x21
	beq .L0813DA62
	cmp r0, #0x22
	beq .L0813DA62
	adds r0, r4, #0
	bl sub_080C0818
	lsls r1, r0, #0x10
	lsrs r2, r1, #0x10
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
	ands r1, r0
	cmp r1, #0
	beq .L0813DA4A
	movs r4, #0x7f
	b .L0813DA54
.L0813DA4A:
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq .L0813DA62
	movs r4, #0x3f
.L0813DA54:
	bl sub_080C2244
	ands r4, r0
	cmp r4, #0
	bne .L0813DA62
	movs r0, #0
	b .L0813DA64
.L0813DA62:
	movs r0, #1
.L0813DA64:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0813DA6C
sub_0813DA6C: @ 0x0813DA6C
.L0813DA6C:
	push {r4, r5, r6, r7, lr}
	bl sub_0812DC10
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r7, r5, #0
	cmp r5, #0xfe
	bne .L0813DA80
	movs r0, #0
	b .L0813DB28
.L0813DA80:
	cmp r5, #0xff
	beq .L0813DB20
	bl sub_080C3100
	adds r4, r0, #0
	ldr r6, .L0813DAA8
	ldrh r1, [r6]
	adds r0, r5, #0
	bl sub_08135064
	cmp r4, r0
	bge .L0813DAB8
	ldr r1, .L0813DAAC
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L0813DAB0
	ldr r0, .L0813DAB4
	ldr r0, [r0]
	str r0, [r1]
	b .L0813DB26
.L0813DAA8: .4byte 0x0300668C @ IWRAM+0x668C
.L0813DAAC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813DAB0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813DAB4: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813DAB8:
	rsbs r0, r0, #0
	bl sub_080C30AC
	ldrh r1, [r6]
	adds r0, r7, #0
	bl sub_081350CC
	bl sub_080C84A0
	ldr r1, .L0813DAE8
	movs r0, #1
	str r0, [r1]
	movs r0, #0
	ldrsh r4, [r6, r0]
	cmp r4, #0
	bne .L0813DAF0
	bl sub_0813560C
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813DB18
	ldr r0, .L0813DAEC
	strh r4, [r0]
	b .L0813DB26
.L0813DAE8: .4byte 0x0203DB34 @ EWRAM+0x3DB34
.L0813DAEC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813DAF0:
	cmp r4, #1
	bne .L0813DAFA
	bl sub_08135370
	b .L0813DB12
.L0813DAFA:
	cmp r4, #2
	bne .L0813DB04
	bl sub_08135420
	b .L0813DB12
.L0813DB04:
	cmp r4, #3
	bne .L0813DB0E
	bl sub_081354B0
	b .L0813DB12
.L0813DB0E:
	bl sub_08135540
.L0813DB12:
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813DB20
.L0813DB18:
	bl sub_0812DC24
	movs r0, #0
	b .L0813DB28
.L0813DB20:
	ldr r1, .L0813DB30
	movs r0, #0
	strh r0, [r1]
.L0813DB26:
	movs r0, #1
.L0813DB28:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0813DB30: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start ScriptVM_Run
ScriptVM_Run: @ 0x0813DB34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp, #4]
	ldr r1, .L0813DBD8
	ldr r0, .L0813DBDC
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [sp, #4]
	bl _call_via_r1
	ldr r0, .L0813DBE0
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #1
	bne .L0813DB62
	b .L0813DCF6
.L0813DB62:
	ldr r1, .L0813DBE4
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L0813DBE8
	mov ip, r0
	movs r1, #0
	mov sl, r1
	ldr r2, .L0813DBEC
	mov sb, r2
	ldr r3, .L0813DBF0
	mov r8, r3
.L0813DB78:
	ldr r1, .L0813DBF4
	ldr r0, [r1]
	cmp r0, #0
	beq .L0813DB8C
	ldr r2, .L0813DBF8
	str r0, [r2]
	mov r3, sl
	str r3, [r1]
	ldr r0, .L0813DBEC
	strh r3, [r0]
.L0813DB8C:
	mov r1, sb
	ldrh r0, [r1]
	ldr r2, .L0813DBF8
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, ip
	strh r1, [r3]
	mov r2, sb
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldr r3, .L0813DBFC
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	movs r0, #0xb8
	lsls r0, r0, #1
	cmp r2, r0
	bhi .L0813DC04
	ldr r1, .L0813DC00
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [sp, #4]
	bl _call_via_r1
	ldr r0, .L0813DBE4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L0813DBD0
	b .L0813DCF6
.L0813DBD0:
	ldr r2, .L0813DBE8
	mov ip, r2
	b .L0813DB78
	.byte 0x00, 0x00
.L0813DBD8: .4byte gUnknown_08790FDC
.L0813DBDC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813DBE0: .4byte 0x03006858 @ IWRAM+0x6858
.L0813DBE4: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L0813DBE8: .4byte 0x0203DB44 @ EWRAM+0x3DB44
.L0813DBEC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813DBF0: .4byte 0x0203D800 @ EWRAM+0x3D800
.L0813DBF4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813DBF8: .4byte 0x03006950 @ IWRAM+0x6950
.L0813DBFC: .4byte 0xFFFFFD00
.L0813DC00: .4byte gScriptOpTable
.L0813DC04:
	ldr r0, .L0813DC2C
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne .L0813DC6C
	ldr r0, .L0813DC30
	ldrh r1, [r0]
	cmp r1, #0
	bne .L0813DC6C
	ldr r0, .L0813DC34
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq .L0813DC38
	str r1, [sp]
	movs r0, #1
	movs r1, #0xc
	movs r2, #0x1c
	movs r3, #7
	b .L0813DC42
.L0813DC2C: .4byte 0x0203DB6C @ EWRAM+0x3DB6C
.L0813DC30: .4byte 0x03006670 @ IWRAM+0x6670
.L0813DC34: .4byte 0x0203DB7A @ EWRAM+0x3DB7A
.L0813DC38:
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #8
.L0813DC42:
	bl Window_Create
	ldr r1, .L0813DC60
	str r0, [r1]
	mov r3, sb
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	ldr r0, .L0813DC64
	movs r1, #1
	strh r1, [r0]
	ldr r0, .L0813DC68
	strh r1, [r0]
	b .L0813DCF6
	.byte 0x00, 0x00
.L0813DC60: .4byte 0x03006968 @ IWRAM+0x6968
.L0813DC64: .4byte 0x0203DB6C @ EWRAM+0x3DB6C
.L0813DC68: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813DC6C:
	ldr r7, .L0813DD08
	ldrh r4, [r7]
	lsls r0, r4, #0x12
	lsrs r0, r0, #0x10
	movs r2, #1
	orrs r2, r0
	lsls r0, r0, #1
	add r0, r8
	mov r3, ip
	ldrh r1, [r3]
	strh r1, [r0]
	adds r1, r2, #1
	lsls r1, r1, #0x10
	lsls r2, r2, #1
	add r2, r8
	ldr r6, .L0813DD0C
	ldrh r0, [r6]
	movs r5, #0xd
	muls r0, r5, r0
	adds r0, #0x11
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #9
	adds r3, r1, r0
	lsrs r1, r1, #0xf
	add r1, r8
	ldr r0, .L0813DD10
	ldrh r0, [r0]
	ldr r2, .L0813DD14
	muls r0, r5, r0
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r1]
	lsrs r3, r3, #0xf
	add r3, r8
	mov r1, sl
	strh r1, [r3]
	adds r4, #1
	strh r4, [r7]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #0x3f
	bls .L0813DCC6
	movs r0, #0x3f
	strh r0, [r7]
.L0813DCC6:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	ldr r2, .L0813DD18
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #1
	bne .L0813DCD8
	b .L0813DB78
.L0813DCD8:
	ldr r1, .L0813DD1C
	movs r0, #0xf
	strh r0, [r1]
	ldr r1, .L0813DD20
	ldr r0, .L0813DD24
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, .L0813DD28
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0813DCF6
	movs r0, #1
	strh r0, [r2]
.L0813DCF6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813DD08: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813DD0C: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813DD10: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813DD14: .4byte 0x03006614 @ IWRAM+0x6614
.L0813DD18: .4byte 0x0203DB48 @ EWRAM+0x3DB48
.L0813DD1C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813DD20: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L0813DD24: .4byte 0x0203DB82 @ EWRAM+0x3DB82
.L0813DD28: .4byte 0x030031B0 @ IWRAM+0x31B0

	thumb_func_start sub_0813DD2C
sub_0813DD2C: @ 0x0813DD2C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0813DD58
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813DD4C
	ldr r0, .L0813DD5C
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0813DD4C
	ldr r0, .L0813DD60
	ldr r0, [r0]
	movs r1, #0
	bl Window_Close
.L0813DD4C:
	movs r0, #0
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813DD58: .4byte 0x03006670 @ IWRAM+0x6670
.L0813DD5C: .4byte 0x0203DB6C @ EWRAM+0x3DB6C
.L0813DD60: .4byte 0x03006968 @ IWRAM+0x6968

	thumb_func_start sub_0813DD64
sub_0813DD64: @ 0x0813DD64
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, .L0813DD8C
	ldrh r5, [r0]
	cmp r5, #0
	bne .L0813DD98
	ldr r6, .L0813DD90
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq .L0813DD98
	ldr r0, .L0813DD94
	ldr r0, [r0]
	bl Window_IsIdle
	cmp r0, #1
	bne .L0813DD9C
	strh r5, [r6]
	b .L0813DD9A
	.byte 0x00, 0x00
.L0813DD8C: .4byte 0x03006670 @ IWRAM+0x6670
.L0813DD90: .4byte 0x0203DB6C @ EWRAM+0x3DB6C
.L0813DD94: .4byte 0x03006968 @ IWRAM+0x6968
.L0813DD98:
	movs r0, #1
.L0813DD9A:
	strh r0, [r4, #0x1c]
.L0813DD9C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0813DDA4
sub_0813DDA4: @ 0x0813DDA4
	push {lr}
	bl sub_080AF3FC
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0813DDB0
sub_0813DDB0: @ 0x0813DDB0
	movs r1, #0
	strh r1, [r0, #0x1c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813DDB8
sub_0813DDB8: @ 0x0813DDB8
	movs r1, #0
	strh r1, [r0, #0x1c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813DDC0
sub_0813DDC0: @ 0x0813DDC0
	movs r1, #0
	strh r1, [r0, #0x1c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813DDC8
sub_0813DDC8: @ 0x0813DDC8
	ldr r1, .L0813DDD0
	movs r0, #4
	strh r0, [r1]
	bx lr
.L0813DDD0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start sub_0813DDD4
sub_0813DDD4: @ 0x0813DDD4
	movs r1, #0
	strh r1, [r0, #0x1c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813DDDC
sub_0813DDDC: @ 0x0813DDDC
	push {r4, lr}
	adds r3, r0, #0
	ldr r1, .L0813DDF4
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bne .L0813DDF8
	movs r0, #1
	strh r0, [r3, #0x1c]
	b .L0813DDFC
	.byte 0x00, 0x00
.L0813DDF4: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0813DDF8:
	subs r0, r2, #1
	strh r0, [r1]
.L0813DDFC:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0813DE04
sub_0813DE04: @ 0x0813DE04
	push {r4, lr}
	ldr r0, .L0813DE30
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813DE34
	strh r1, [r0]
	ldr r0, .L0813DE38
	strh r1, [r0]
	ldr r1, .L0813DE3C
	movs r0, #6
	strh r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r4, .L0813DE40
	bl sub_0813E408
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
.L0813DE30: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813DE34: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813DE38: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813DE3C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813DE40: .4byte 0x0203DB48 @ EWRAM+0x3DB48

	thumb_func_start sub_0813DE44
sub_0813DE44: @ 0x0813DE44
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, .L0813DE98
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0813DE86
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne .L0813DE86
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne .L0813DE86
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne .L0813DE86
	ldrh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0813DE86
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0813DE90
.L0813DE86:
	movs r0, #0x65
	bl sub_080C51D4
	movs r0, #1
	strh r0, [r4, #0x1c]
.L0813DE90:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813DE98: .4byte 0x030031C4 @ IWRAM+0x31C4

	thumb_func_start sub_0813DE9C
sub_0813DE9C: @ 0x0813DE9C
	push {r4, lr}
	movs r1, #0
	ldr r3, .L0813DED0
	ldrh r0, [r3]
	cmp r1, r0
	bge .L0813DECA
	ldr r4, .L0813DED4
.L0813DEAA:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r2, [r1]
	subs r2, #0xd
	strh r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r3]
	cmp r0, r2
	blt .L0813DEAA
.L0813DECA:
	pop {r4}
	pop {r0}
	bx r0
.L0813DED0: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813DED4: .4byte 0x0203D800 @ EWRAM+0x3D800

	thumb_func_start sub_0813DED8
sub_0813DED8: @ 0x0813DED8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	ldr r1, .L0813DFD4
	ldrh r0, [r1]
	cmp r0, #0
	beq .L0813DF3A
	movs r2, #0
	ldrh r1, [r1]
	cmp r2, r1
	bge .L0813DF3A
	ldr r6, .L0813DFD8
.L0813DEF0:
	lsls r0, r2, #0x10
	asrs r5, r0, #0x10
	lsls r2, r5, #2
	adds r0, r2, #2
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r4, [r0]
	ldr r0, .L0813DFDC
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt .L0813DF2A
	lsls r0, r5, #3
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r3, [r1]
	str r4, [sp]
	adds r1, r2, #3
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyphTinted
.L0813DF2A:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L0813DFD4
	ldrh r1, [r1]
	cmp r0, r1
	blt .L0813DEF0
.L0813DF3A:
	ldr r0, .L0813DFE0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0813DF94
	movs r2, #0
	ldr r0, .L0813DFE4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge .L0813DF94
	ldr r5, .L0813DFE8
.L0813DF52:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r2, r4, #2
	lsls r0, r4, #3
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r3, [r1]
	adds r1, r2, #2
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	str r1, [sp]
	adds r2, #3
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r1, [r2]
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyphTinted
	adds r4, #1
	lsls r4, r4, #0x10
	ldr r0, .L0813DFE4
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt .L0813DF52
.L0813DF94:
	movs r2, #0
	ldr r5, .L0813DFEC
	adds r6, r5, #4
.L0813DF9A:
	lsls r0, r2, #0x10
	asrs r4, r0, #0x10
	lsls r1, r4, #4
	adds r3, r1, r5
	ldrh r0, [r3]
	cmp r0, #0
	beq .L0813DFB6
	adds r0, r1, r6
	ldr r0, [r0]
	ldrh r1, [r3, #8]
	ldrh r2, [r3, #0xa]
	ldrh r3, [r3, #0xc]
	bl sub_080D31F8
.L0813DFB6:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble .L0813DF9A
	ldr r0, .L0813DFF0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L0813DFF8
	ldr r0, .L0813DFF4
	ldrh r0, [r0]
	movs r1, #0x66
	b .L0813E012
.L0813DFD4: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813DFD8: .4byte 0x0203D800 @ EWRAM+0x3D800
.L0813DFDC: .4byte 0x03006614 @ IWRAM+0x6614
.L0813DFE0: .4byte 0x0300699C @ IWRAM+0x699C
.L0813DFE4: .4byte 0x0300669C @ IWRAM+0x669C
.L0813DFE8: .4byte 0x0203DA00 @ EWRAM+0x3DA00
.L0813DFEC: .4byte 0x03006620 @ IWRAM+0x6620
.L0813DFF0: .4byte 0x030069D0 @ IWRAM+0x69D0
.L0813DFF4: .4byte 0x030069D8 @ IWRAM+0x69D8
.L0813DFF8:
	cmp r0, #2
	bne .L0813E024
	ldr r4, .L0813E020
	ldrh r0, [r4]
	movs r1, #0x66
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0x17
	bl sub_080C6B40
	ldrh r0, [r4, #2]
	movs r1, #0x74
.L0813E012:
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0x17
	bl sub_080C6B40
	b .L0813E05A
.L0813E020: .4byte 0x030069D8 @ IWRAM+0x69D8
.L0813E024:
	cmp r0, #3
	bne .L0813E05A
	ldr r4, .L0813E0F4
	ldrh r0, [r4]
	movs r1, #0x66
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0x17
	bl sub_080C6B40
	ldrh r0, [r4, #2]
	movs r1, #0x74
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0x17
	bl sub_080C6B40
	ldrh r0, [r4, #4]
	movs r1, #0x83
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0x17
	bl sub_080C6B40
.L0813E05A:
	ldr r4, .L0813E0F8
	ldrh r0, [r4]
	cmp r0, #0
	beq .L0813E06E
	ldrh r0, [r4, #2]
	ldrh r3, [r4, #4]
	movs r1, #0x12
	movs r2, #0x66
	bl sub_080D3170
.L0813E06E:
	ldrh r0, [r4, #8]
	cmp r0, #0
	beq .L0813E080
	ldrh r0, [r4, #0xa]
	ldrh r3, [r4, #0xc]
	movs r1, #0x12
	movs r2, #0x74
	bl sub_080D3170
.L0813E080:
	ldrh r0, [r4, #0x10]
	cmp r0, #0
	beq .L0813E092
	ldrh r0, [r4, #0x12]
	ldrh r3, [r4, #0x14]
	movs r1, #0x12
	movs r2, #0x83
	bl sub_080D3170
.L0813E092:
	ldr r0, .L0813E0FC
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0813E0B0
	ldr r0, .L0813E100
	ldrh r0, [r0]
	ldr r1, .L0813E104
	ldrh r3, [r1]
	ldr r1, .L0813E108
	ldrh r1, [r1]
	str r1, [sp]
	movs r1, #4
	movs r2, #0
	bl sub_080C49EC
.L0813E0B0:
	ldr r1, .L0813E10C
	ldrh r0, [r1]
	cmp r0, #0
	beq .L0813E0C8
	ldrh r0, [r1, #2]
	str r0, [sp]
	movs r0, #0x13
	movs r1, #4
	movs r2, #0
	movs r3, #0x1f
	bl sub_080C49EC
.L0813E0C8:
	ldr r0, .L0813E110
	ldrh r0, [r0]
	cmp r0, #1
	bne .L0813E0D2
	strh r0, [r7, #0x1c]
.L0813E0D2:
	ldr r0, .L0813E114
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0813E128
	ldr r0, .L0813E118
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0813E11C
	movs r0, #0
	movs r1, #0
	movs r2, #0xd5
	movs r3, #0x8d
	bl sub_080C4AB0
	b .L0813E128
.L0813E0F4: .4byte 0x030069D8 @ IWRAM+0x69D8
.L0813E0F8: .4byte 0x03006920 @ IWRAM+0x6920
.L0813E0FC: .4byte 0x03006958 @ IWRAM+0x6958
.L0813E100: .4byte 0x030066A0 @ IWRAM+0x66A0
.L0813E104: .4byte 0x0300689C @ IWRAM+0x689C
.L0813E108: .4byte 0x0300695C @ IWRAM+0x695C
.L0813E10C: .4byte 0x03006678 @ IWRAM+0x6678
.L0813E110: .4byte 0x0203DB46 @ EWRAM+0x3DB46
.L0813E114: .4byte 0x0203DB52 @ EWRAM+0x3DB52
.L0813E118: .4byte 0x0203DB7A @ EWRAM+0x3DB7A
.L0813E11C:
	movs r0, #0
	movs r1, #0
	movs r2, #0xd5
	movs r3, #0x8d
	bl sub_080C4AB0
.L0813E128:
	ldr r1, .L0813E174
	ldrh r0, [r1]
	cmp r0, #0
	beq .L0813E14A
	ldr r3, .L0813E178
	lsls r1, r0, #1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r2, [r0]
	adds r1, #1
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r3, [r1]
	movs r0, #0
	movs r1, #0
	bl sub_080C4A4C
.L0813E14A:
	ldr r1, .L0813E17C
	ldrh r0, [r1]
	cmp r0, #0
	beq .L0813E16C
	ldr r3, .L0813E180
	lsls r1, r0, #1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r2, [r0]
	adds r1, #1
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r3, [r1]
	movs r0, #0
	movs r1, #0
	bl sub_080C4AB0
.L0813E16C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0813E174: .4byte 0x03006848 @ IWRAM+0x6848
.L0813E178: .4byte gUnknown_087923DC
.L0813E17C: .4byte 0x03006680 @ IWRAM+0x6680
.L0813E180: .4byte gUnknown_087923FC

	thumb_func_start sub_0813E184
sub_0813E184: @ 0x0813E184
.L0813E184:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r3, .L0813E1B8
	ldr r2, .L0813E1BC
	ldr r1, .L0813E1C0
	movs r0, #0
	strh r0, [r1]
	strh r0, [r2]
	strh r0, [r3]
	ldr r1, .L0813E1C4
	movs r0, #2
	strh r0, [r1]
	ldr r0, .L0813E1C8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L0813E1D0
	ldr r1, .L0813E1CC
	movs r0, #0x61
	b .L0813E1E4
.L0813E1B8: .4byte 0x0203DB86 @ EWRAM+0x3DB86
.L0813E1BC: .4byte 0x030069CC @ IWRAM+0x69CC
.L0813E1C0: .4byte 0x030065F0 @ IWRAM+0x65F0
.L0813E1C4: .4byte 0x0203DB82 @ EWRAM+0x3DB82
.L0813E1C8: .4byte 0x0203DB7A @ EWRAM+0x3DB7A
.L0813E1CC: .4byte 0x03006614 @ IWRAM+0x6614
.L0813E1D0:
	cmp r0, #2
	bne .L0813E1E0
	ldr r1, .L0813E1DC
	movs r0, #0x69
	b .L0813E1E4
	.byte 0x00, 0x00
.L0813E1DC: .4byte 0x03006614 @ IWRAM+0x6614
.L0813E1E0:
	ldr r1, .L0813E330
	movs r0, #0x59
.L0813E1E4:
	strh r0, [r1]
	ldr r0, .L0813E334
	movs r4, #0
	strh r4, [r0]
	movs r0, #1
	bl sub_0813EB6C
	ldr r0, .L0813E338
	strh r5, [r0]
	ldr r1, .L0813E33C
	movs r0, #0xff
	strh r0, [r1]
	ldr r0, .L0813E340
	strh r4, [r0]
	ldr r0, .L0813E344
	strh r4, [r0]
	ldr r0, .L0813E348
	strh r4, [r0]
	ldr r0, .L0813E34C
	movs r1, #0
	str r1, [r0]
	ldr r2, .L0813E350
	ldr r0, .L0813E354
	strh r1, [r0]
	strh r1, [r2, #4]
	strh r1, [r2]
	ldr r0, .L0813E358
	strh r1, [r0]
	ldr r0, .L0813E35C
	strh r1, [r0]
	ldr r0, .L0813E360
	strh r1, [r0]
	ldr r0, .L0813E364
	strh r1, [r0]
	ldr r0, .L0813E368
	str r6, [r0]
	ldr r0, .L0813E36C
	str r1, [r0]
	ldr r0, .L0813E370
	strh r1, [r0]
	ldr r3, .L0813E374
	movs r2, #0
.L0813E238:
	lsls r0, r1, #4
	adds r0, r0, r3
	strh r2, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #4
	bls .L0813E238
	movs r1, #0
	ldr r6, .L0813E378
	ldr r7, .L0813E37C
	ldr r5, .L0813E380
	ldr r2, .L0813E384
	ldr r0, .L0813E388
	mov ip, r0
	ldr r0, .L0813E38C
	mov r8, r0
	ldr r0, .L0813E390
	mov sb, r0
	ldr r0, .L0813E394
	mov sl, r0
	ldr r4, .L0813E398
	movs r3, #0
.L0813E266:
	lsls r0, r1, #3
	adds r0, r0, r4
	strh r3, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #2
	bls .L0813E266
	movs r0, #0
	strh r0, [r6]
	strh r0, [r7]
	movs r4, #0
	str r4, [r5]
	str r4, [r5, #4]
	str r4, [r2]
	str r4, [r2, #4]
	str r4, [r2, #8]
	str r4, [r2, #0xc]
	str r4, [r2, #0x10]
	str r4, [r2, #0x14]
	str r4, [r2, #0x18]
	str r4, [r2, #0x1c]
	mov r1, ip
	strh r4, [r1]
	mov r0, r8
	strh r4, [r0]
	mov r1, sb
	strh r4, [r1]
	mov r0, sl
	str r4, [r0]
	ldr r1, .L0813E39C
	strh r4, [r1]
	ldr r0, .L0813E3A0
	strh r4, [r0]
	ldr r1, .L0813E3A4
	strh r4, [r1]
	ldr r0, .L0813E3A8
	str r4, [r0]
	ldr r1, .L0813E3AC
	strh r4, [r1]
	ldr r0, .L0813E3B0
	strh r4, [r0]
	bl sub_0813E408
	ldr r1, .L0813E3B4
	strh r0, [r1]
	ldr r0, .L0813E3B8
	strh r4, [r0]
	ldr r0, .L0813E3BC
	strh r4, [r0]
	ldr r0, .L0813E3C0
	strh r4, [r0]
	ldr r0, .L0813E3C4
	strh r4, [r0]
	ldr r0, .L0813E3C8
	strh r4, [r0]
	ldr r0, .L0813E3CC
	strh r4, [r0]
	ldr r0, .L0813E3D0
	strh r4, [r0]
	ldr r0, .L0813E3D4
	strh r4, [r0]
	ldr r0, .L0813E3D8
	str r4, [r0]
	ldr r0, .L0813E3DC
	str r4, [r0]
	ldr r0, .L0813E3E0
	str r4, [r0]
	ldr r0, .L0813E3E4
	ldr r5, .L0813E3E8
	adds r1, r5, #0
	bl Task_Create
	ldr r1, .L0813E3EC
	str r0, [r1]
	ldr r0, .L0813E3F0
	adds r1, r5, #0
	bl Task_Create
	ldr r0, .L0813E3F4
	adds r1, r5, #0
	bl Task_Create
	ldr r1, .L0813E3F8
	str r0, [r1]
	ldr r0, .L0813E3FC
	strh r4, [r0]
	ldr r0, .L0813E400
	strh r4, [r0]
	ldr r1, .L0813E404
	movs r0, #0xc6
	lsls r0, r0, #2
	strh r0, [r1, #0x10]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813E330: .4byte 0x03006614 @ IWRAM+0x6614
.L0813E334: .4byte 0x030069D0 @ IWRAM+0x69D0
.L0813E338: .4byte 0x03006670 @ IWRAM+0x6670
.L0813E33C: .4byte 0x03006914 @ IWRAM+0x6914
.L0813E340: .4byte 0x030068AC @ IWRAM+0x68AC
.L0813E344: .4byte 0x03006958 @ IWRAM+0x6958
.L0813E348: .4byte 0x030065E4 @ IWRAM+0x65E4
.L0813E34C: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813E350: .4byte 0x03006678 @ IWRAM+0x6678
.L0813E354: .4byte 0x030068A0 @ IWRAM+0x68A0
.L0813E358: .4byte 0x0300693C @ IWRAM+0x693C
.L0813E35C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813E360: .4byte 0x0300669C @ IWRAM+0x669C
.L0813E364: .4byte 0x0300699C @ IWRAM+0x699C
.L0813E368: .4byte 0x03006950 @ IWRAM+0x6950
.L0813E36C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813E370: .4byte 0x030065FC @ IWRAM+0x65FC
.L0813E374: .4byte 0x03006620 @ IWRAM+0x6620
.L0813E378: .4byte 0x0203DB52 @ EWRAM+0x3DB52
.L0813E37C: .4byte 0x0203DB56 @ EWRAM+0x3DB56
.L0813E380: .4byte 0x030069C0 @ IWRAM+0x69C0
.L0813E384: .4byte 0x030068F0 @ IWRAM+0x68F0
.L0813E388: .4byte 0x0203DB66 @ EWRAM+0x3DB66
.L0813E38C: .4byte 0x0203DB68 @ EWRAM+0x3DB68
.L0813E390: .4byte 0x0203DB64 @ EWRAM+0x3DB64
.L0813E394: .4byte 0x030068C4 @ IWRAM+0x68C4
.L0813E398: .4byte 0x03006920 @ IWRAM+0x6920
.L0813E39C: .4byte 0x03006818 @ IWRAM+0x6818
.L0813E3A0: .4byte 0x03006600 @ IWRAM+0x6600
.L0813E3A4: .4byte 0x030065EC @ IWRAM+0x65EC
.L0813E3A8: .4byte 0x030068D0 @ IWRAM+0x68D0
.L0813E3AC: .4byte 0x03006610 @ IWRAM+0x6610
.L0813E3B0: .4byte 0x03006910 @ IWRAM+0x6910
.L0813E3B4: .4byte 0x0203DB48 @ EWRAM+0x3DB48
.L0813E3B8: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0813E3BC: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813E3C0: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813E3C4: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813E3C8: .4byte 0x0203DB44 @ EWRAM+0x3DB44
.L0813E3CC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813E3D0: .4byte 0x0203DB46 @ EWRAM+0x3DB46
.L0813E3D4: .4byte 0x0203DB6C @ EWRAM+0x3DB6C
.L0813E3D8: .4byte 0x03006968 @ IWRAM+0x6968
.L0813E3DC: .4byte 0x030068B0 @ IWRAM+0x68B0
.L0813E3E0: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813E3E4: .4byte gUnknown_08790024
.L0813E3E8: .4byte 0x0000FFFF
.L0813E3EC: .4byte 0x030065F4 @ IWRAM+0x65F4
.L0813E3F0: .4byte gUnknown_0878FB48
.L0813E3F4: .4byte gUnknown_0878FB84
.L0813E3F8: .4byte 0x030069E4 @ IWRAM+0x69E4
.L0813E3FC: .4byte 0x03006848 @ IWRAM+0x6848
.L0813E400: .4byte 0x03006680 @ IWRAM+0x6680
.L0813E404: .4byte 0x0203DB08 @ EWRAM+0x3DB08

	thumb_func_start sub_0813E408
sub_0813E408: @ 0x0813E408
.L0813E408:
	push {lr}
	ldr r0, .L0813E418
	ldrh r0, [r0]
	cmp r0, #1
	bne .L0813E41C
	bl Settings_GetBattleMsgSpeed
	b .L0813E420
.L0813E418: .4byte 0x03006670 @ IWRAM+0x6670
.L0813E41C:
	bl sub_080C2AFC
.L0813E420:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1

	thumb_func_start ScriptVM_RunAlt
ScriptVM_RunAlt: @ 0x0813E428
.L0813E428:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, .L0813E4D4
	ldr r6, [r1]
	ldr r2, .L0813E4D8
	movs r1, #1
	strh r1, [r2]
	ldr r2, .L0813E4DC
	ldr r1, .L0813E4E0
	ldrh r1, [r1]
	strh r1, [r2]
	ldr r2, .L0813E4E4
	ldr r1, .L0813E4E8
	ldrh r1, [r1]
	strh r1, [r2]
	ldr r2, .L0813E4EC
	ldr r3, .L0813E4F0
	ldr r1, [r3]
	str r1, [r2]
	ldr r2, .L0813E4F4
	ldr r4, .L0813E4F8
	ldrh r1, [r4]
	strh r1, [r2]
	str r0, [r3]
	ldr r5, .L0813E4FC
	movs r1, #0
	str r1, [r5]
	strh r1, [r4]
	ldr r0, .L0813E500
	strh r1, [r0]
	ldr r0, .L0813E504
	strh r1, [r0]
	ldr r0, .L0813E508
	strh r1, [r0]
	bl sub_0813E544
	ldr r0, .L0813E50C
	mov r8, r0
	movs r7, #0xb8
	lsls r7, r7, #1
.L0813E47A:
	ldr r0, [r5]
	ldr r1, .L0813E4F0
	cmp r0, #0
	beq .L0813E48A
	str r0, [r1]
	movs r0, #0
	str r0, [r5]
	strh r0, [r4]
.L0813E48A:
	ldrh r0, [r4]
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r0, r8
	strh r1, [r0]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r0, .L0813E510
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, r7
	bhi .L0813E52E
	ldr r1, .L0813E514
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldr r0, .L0813E500
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L0813E518
	ldr r0, .L0813E504
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L0813E52E
	bl sub_0813E574
	movs r0, #1
	b .L0813E534
.L0813E4D4: .4byte 0x030068B0 @ IWRAM+0x68B0
.L0813E4D8: .4byte 0x030065F0 @ IWRAM+0x65F0
.L0813E4DC: .4byte 0x0203DB76 @ EWRAM+0x3DB76
.L0813E4E0: .4byte 0x0203DB72 @ EWRAM+0x3DB72
.L0813E4E4: .4byte 0x0203DB78 @ EWRAM+0x3DB78
.L0813E4E8: .4byte 0x0203DB74 @ EWRAM+0x3DB74
.L0813E4EC: .4byte 0x030068C0 @ IWRAM+0x68C0
.L0813E4F0: .4byte 0x03006950 @ IWRAM+0x6950
.L0813E4F4: .4byte 0x030068DC @ IWRAM+0x68DC
.L0813E4F8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813E4FC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813E500: .4byte 0x0203DB5E @ EWRAM+0x3DB5E
.L0813E504: .4byte 0x0203DB60 @ EWRAM+0x3DB60
.L0813E508: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L0813E50C: .4byte 0x0203DB44 @ EWRAM+0x3DB44
.L0813E510: .4byte 0xFFFFFD00
.L0813E514: .4byte gScriptOpAltTable
.L0813E518:
	cmp r0, #2
	bne .L0813E524
	bl sub_0813E574
	movs r0, #0
	b .L0813E534
.L0813E524:
	ldr r0, .L0813E540
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L0813E47A
.L0813E52E:
	bl sub_0813E574
	movs r0, #2
.L0813E534:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0813E540: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start sub_0813E544
sub_0813E544: @ 0x0813E544
.L0813E544:
	push {r4, r5, lr}
	movs r2, #0
	ldr r5, .L0813E568
	ldr r4, .L0813E56C
	ldr r3, .L0813E570
.L0813E54E:
	adds r1, r2, r5
	adds r0, r2, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r3
	bls .L0813E54E
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813E568: .4byte 0x030066B0 @ IWRAM+0x66B0
.L0813E56C: .4byte 0x03005CA8 @ IWRAM+0x5CA8
.L0813E570: .4byte 0x00000167

	thumb_func_start sub_0813E574
sub_0813E574: @ 0x0813E574
.L0813E574:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r2, #0
	ldr r0, .L0813E5DC
	mov r8, r0
	ldr r1, .L0813E5E0
	mov sb, r1
	ldr r6, .L0813E5E4
	ldr r0, .L0813E5E8
	mov sl, r0
	ldr r7, .L0813E5EC
	ldr r1, .L0813E5F0
	mov ip, r1
	ldr r5, .L0813E5F4
	ldr r4, .L0813E5F8
	ldr r3, .L0813E5FC
.L0813E59A:
	adds r1, r2, r5
	adds r0, r2, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r3
	bls .L0813E59A
	mov r1, r8
	ldr r0, [r1]
	ldr r1, .L0813E600
	str r0, [r1]
	ldrh r0, [r6]
	mov r1, sb
	strh r0, [r1]
	ldrh r0, [r7]
	mov r1, sl
	strh r0, [r1]
	mov r1, ip
	ldrh r0, [r1]
	ldr r1, .L0813E604
	strh r0, [r1]
	movs r0, #0
	ldr r1, .L0813E608
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0813E5DC: .4byte 0x030068C0 @ IWRAM+0x68C0
.L0813E5E0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813E5E4: .4byte 0x030068DC @ IWRAM+0x68DC
.L0813E5E8: .4byte 0x0203DB72 @ EWRAM+0x3DB72
.L0813E5EC: .4byte 0x0203DB76 @ EWRAM+0x3DB76
.L0813E5F0: .4byte 0x0203DB78 @ EWRAM+0x3DB78
.L0813E5F4: .4byte 0x03005CA8 @ IWRAM+0x5CA8
.L0813E5F8: .4byte 0x030066B0 @ IWRAM+0x66B0
.L0813E5FC: .4byte 0x00000167
.L0813E600: .4byte 0x03006950 @ IWRAM+0x6950
.L0813E604: .4byte 0x0203DB74 @ EWRAM+0x3DB74
.L0813E608: .4byte 0x030065F0 @ IWRAM+0x65F0

	thumb_func_start sub_0813E60C
sub_0813E60C: @ 0x0813E60C
.L0813E60C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	cmp r1, #0x1f
	bls .L0813E61E
	b .L0813E800
.L0813E61E:
	lsls r0, r1, #2
	ldr r1, .L0813E628
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L0813E628: .4byte gUnknown_0813E62C
	.global gUnknown_0813E62C
gUnknown_0813E62C:
.L0813E62C: @ jump table
	.4byte .L0813E6AC
	.4byte .L0813E6B6
	.4byte .L0813E6B6
	.4byte .L0813E6C0
	.4byte .L0813E6C0
	.4byte .L0813E6CA
	.4byte .L0813E6D8
	.4byte .L0813E6E6
	.4byte .L0813E6F4
	.4byte .L0813E702
	.4byte .L0813E710
	.4byte .L0813E71E
	.4byte .L0813E728
	.4byte .L0813E732
	.4byte .L0813E740
	.4byte .L0813E74E
	.4byte .L0813E760
	.4byte .L0813E76A
	.4byte .L0813E774
	.4byte .L0813E77E
	.4byte .L0813E788
	.4byte .L0813E792
	.4byte .L0813E79C
	.4byte .L0813E7A6
	.4byte .L0813E7B0
	.4byte .L0813E7BA
	.4byte .L0813E7C4
	.4byte .L0813E7CE
	.4byte .L0813E7D8
	.4byte .L0813E7E2
	.4byte .L0813E7EC
	.4byte .L0813E7F6
.L0813E6AC:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #1]
	b .L0813E800
.L0813E6B6:
	adds r0, r2, #0
	bl sub_080BF648
	ldrh r0, [r0, #2]
	b .L0813E800
.L0813E6C0:
	adds r0, r2, #0
	bl sub_080BF648
	ldrh r0, [r0, #4]
	b .L0813E800
.L0813E6CA:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0813E75A
.L0813E6D8:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #7]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0813E75A
.L0813E6E6:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #8]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0813E75A
.L0813E6F4:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #9]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0813E75A
.L0813E702:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0813E75A
.L0813E710:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0813E75A
.L0813E71E:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0xc]
	b .L0813E800
.L0813E728:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0xd]
	b .L0813E800
.L0813E732:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0813E75A
.L0813E740:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0xf]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0813E75A
.L0813E74E:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x10]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
.L0813E75A:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L0813E800
.L0813E760:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x11]
	b .L0813E800
.L0813E76A:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x12]
	b .L0813E800
.L0813E774:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x13]
	b .L0813E800
.L0813E77E:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x14]
	b .L0813E800
.L0813E788:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x15]
	b .L0813E800
.L0813E792:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x16]
	b .L0813E800
.L0813E79C:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x17]
	b .L0813E800
.L0813E7A6:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x18]
	b .L0813E800
.L0813E7B0:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x19]
	b .L0813E800
.L0813E7BA:
	adds r0, r2, #0
	bl sub_080BF648
	ldrh r0, [r0, #0x1a]
	b .L0813E800
.L0813E7C4:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x1c]
	b .L0813E800
.L0813E7CE:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x1d]
	b .L0813E800
.L0813E7D8:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x1e]
	b .L0813E800
.L0813E7E2:
	adds r0, r2, #0
	bl sub_080BF648
	ldrb r0, [r0, #0x1f]
	b .L0813E800
.L0813E7EC:
	adds r0, r2, #0
	bl sub_080BF648
	adds r0, #0x20
	b .L0813E7FE
.L0813E7F6:
	adds r0, r2, #0
	bl sub_080BF648
	adds r0, #0x21
.L0813E7FE:
	ldrb r0, [r0]
.L0813E800:
	pop {r1}
	bx r1

	thumb_func_start sub_0813E804
sub_0813E804: @ 0x0813E804
.L0813E804:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r6, #0
	bl sub_080C104C
	adds r5, r0, #0
	movs r4, #4
	b .L0813E836
.L0813E816:
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L0813E830
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	bne .L0813E830
	adds r6, #1
.L0813E830:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L0813E836:
	adds r0, r5, #4
	cmp r4, r0
	blt .L0813E816
	adds r0, r7, #0
	bl sub_08134C3C
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813E84A
	adds r6, #1
.L0813E84A:
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0813E854
sub_0813E854: @ 0x0813E854
.L0813E854:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xff
	ands r2, r0
	cmp r2, #0x53
	bls .L0813E88C
	cmp r2, #0xb1
	bhi .L0813E88C
	adds r0, r2, #0
	subs r0, #0x54
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L0813E880
	ldr r2, .L0813E884
	adds r1, r1, r2
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r1, .L0813E888
	movs r0, #0
	b .L0813E89A
	.byte 0x00, 0x00
.L0813E880: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813E884: .4byte 0x00001074
.L0813E888: .4byte 0x03006860 @ IWRAM+0x6860
.L0813E88C:
	movs r1, #0x1e
	bl sub_0813E60C
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, .L0813E8A4
	movs r0, #1
.L0813E89A:
	strh r0, [r1]
	adds r0, r2, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0813E8A4: .4byte 0x03006860 @ IWRAM+0x6860

	thumb_func_start sub_0813E8A8
sub_0813E8A8: @ 0x0813E8A8
.L0813E8A8:
	push {r4, r5, r6, lr}
	bl sub_080C1D9C
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x80
	beq .L0813E900
	ldr r0, .L0813E8F4
	ldrh r0, [r0]
	bl sub_0813E854
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r4, .L0813E8F8
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L0813E900
	ldr r6, .L0813E8FC
	ldrh r0, [r6]
	bl sub_0813E854
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne .L0813E900
	cmp r1, r5
	bhs .L0813E900
	ldrh r0, [r6]
	bl sub_0813E804
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813E900
	movs r0, #1
	b .L0813E902
.L0813E8F4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813E8F8: .4byte 0x03006860 @ IWRAM+0x6860
.L0813E8FC: .4byte 0x0203DB7E @ EWRAM+0x3DB7E
.L0813E900:
	movs r0, #0
.L0813E902:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_0813E908
sub_0813E908: @ 0x0813E908
.L0813E908:
	ldr r2, .L0813E910
	strh r0, [r2]
	strh r1, [r2, #2]
	bx lr
.L0813E910: .4byte 0x0203DB28 @ EWRAM+0x3DB28

	thumb_func_start sub_0813E914
sub_0813E914: @ 0x0813E914
.L0813E914:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, .L0813E950
	movs r0, #0
	strh r0, [r1]
	ldr r2, .L0813E954
	ldrb r1, [r2]
	movs r0, #3
	ands r0, r1
	strb r0, [r2]
	movs r4, #0
	ldr r0, .L0813E958
	ldrh r0, [r0]
	movs r1, #0xb
	bl sub_0813E60C
	movs r6, #0xff
	ands r6, r0
	cmp r6, #0x6f
	bhi .L0813E95C
	movs r0, #0
	bl sub_080C0794
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x18
	cmp r6, #0x6f
	bhi .L0813E970
	b .L0813E96E
	.byte 0x00, 0x00
.L0813E950: .4byte 0x0203DB7A @ EWRAM+0x3DB7A
.L0813E954: .4byte 0x0300684C @ IWRAM+0x684C
.L0813E958: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813E95C:
	cmp r6, #0x8f
	bls .L0813E970
	movs r0, #0
	bl sub_080C0794
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x18
	cmp r6, #0x8f
	bls .L0813E970
.L0813E96E:
	movs r4, #4
.L0813E970:
	ldr r3, .L0813E990
	ldrh r1, [r3]
	adds r0, r1, #0
	subs r0, #0x54
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x5d
	bls .L0813E994
	ldrh r0, [r3]
	movs r1, #0x1e
	bl sub_0813E60C
	movs r6, #0xff
	ands r6, r0
	b .L0813E9A6
	.byte 0x00, 0x00
.L0813E990: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813E994:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb1
	bhi .L0813E9A6
	ldr r0, .L0813E9E4
	ldr r1, .L0813E9E8
	adds r0, r0, r1
	adds r0, r2, r0
	ldrb r6, [r0]
.L0813E9A6:
	lsrs r6, r6, #3
	ldr r1, .L0813E9EC
	adds r0, r6, r4
	strb r0, [r1]
	ldrb r0, [r1]
	bl sub_080EF930
	ldr r4, .L0813E9F0
	movs r5, #0xff
	movs r0, #0
	bl sub_080C0F8C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldrh r0, [r4]
	movs r1, #0
	bl sub_0813E60C
	subs r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x11
	adds r6, #8
	ands r6, r5
	movs r0, #0x80
	ands r0, r6
	cmp r0, #0
	beq .L0813E9F8
	ldr r1, .L0813E9F4
	movs r0, #0
	b .L0813EA00
	.byte 0x00, 0x00
.L0813E9E4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813E9E8: .4byte 0x00001074
.L0813E9EC: .4byte 0x030068B4 @ IWRAM+0x68B4
.L0813E9F0: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813E9F4: .4byte 0x030069E8 @ IWRAM+0x69E8
.L0813E9F8:
	cmp r6, #0x1f
	bls .L0813EA0C
	ldr r1, .L0813EA08
	movs r0, #0x1f
.L0813EA00:
	strb r0, [r1]
	adds r0, r1, #0
	b .L0813EA10
	.byte 0x00, 0x00
.L0813EA08: .4byte 0x030069E8 @ IWRAM+0x69E8
.L0813EA0C:
	ldr r0, .L0813EA44
	strb r6, [r0]
.L0813EA10:
	ldrb r0, [r0]
	bl sub_080EF978
	ldr r5, .L0813EA48
	ldrh r0, [r5]
	ldr r2, .L0813EA4C
	mov r8, r2
	movs r1, #0x1f
	bl sub_0813E60C
	mov r1, r8
	strb r0, [r1]
	movs r0, #0
	bl sub_080C0818
	ldrh r0, [r5]
	bl sub_0813E804
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813EA50
	ldrh r0, [r5]
	movs r1, #3
	bl sub_0815BAC8
	b .L0813EB30
.L0813EA44: .4byte 0x030069E8 @ IWRAM+0x69E8
.L0813EA48: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813EA4C: .4byte 0x0300685C @ IWRAM+0x685C
.L0813EA50:
	ldr r4, .L0813EAA0
	ldrh r0, [r4]
	ldr r7, .L0813EAA4
	cmp r0, r7
	beq .L0813EAB4
	bl sub_0813E8A8
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813EAB4
	ldrh r2, [r4]
	ldrh r0, [r5]
	strh r0, [r4]
	strh r2, [r5]
	ldrh r0, [r5]
	movs r1, #0x1f
	bl sub_0813E60C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r2, r8
	strb r6, [r2]
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x1c
	ldr r0, .L0813EAA8
	ldr r1, .L0813EAAC
	str r1, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	orrs r0, r1
	movs r1, #1
	bl sub_0813E184
	ldr r0, .L0813EAB0
	strh r7, [r0]
	b .L0813EB40
	.byte 0x00, 0x00
.L0813EAA0: .4byte 0x0203DB7E @ EWRAM+0x3DB7E
.L0813EAA4: .4byte 0x0000FFFF
.L0813EAA8: .4byte 0x03006950 @ IWRAM+0x6950
.L0813EAAC: .4byte gUnknown_08032C78
.L0813EAB0: .4byte 0x0203DB70 @ EWRAM+0x3DB70
.L0813EAB4:
	bl sub_080C1D9C
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x80
	bne .L0813EAE8
	ldr r1, .L0813EADC
	ldrb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x1c
	ldr r0, .L0813EAE0
	ldr r1, .L0813EAE4
	str r1, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	orrs r0, r1
	b .L0813EB32
.L0813EADC: .4byte 0x0300685C @ IWRAM+0x685C
.L0813EAE0: .4byte 0x03006950 @ IWRAM+0x6950
.L0813EAE4: .4byte gUnknown_08032D4C
.L0813EAE8:
	ldr r0, .L0813EB20
	ldrh r0, [r0]
	movs r1, #0
	bl sub_0813E60C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	bl sub_080C0F8C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r6, r0
	ble .L0813EB30
	ldr r1, .L0813EB24
	ldrb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x1c
	ldr r0, .L0813EB28
	ldr r1, .L0813EB2C
	str r1, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	orrs r0, r1
	b .L0813EB32
.L0813EB20: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813EB24: .4byte 0x0300685C @ IWRAM+0x685C
.L0813EB28: .4byte 0x03006950 @ IWRAM+0x6950
.L0813EB2C: .4byte gUnknown_08032CA8
.L0813EB30:
	ldr r0, .L0813EB50
.L0813EB32:
	movs r1, #1
	bl sub_0813E184
	ldr r1, .L0813EB54
	ldr r2, .L0813EB58
	adds r0, r2, #0
	strh r0, [r1]
.L0813EB40:
	ldr r1, .L0813EB5C
	movs r0, #0xa
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0813EB50: .4byte gUnknown_08084020
.L0813EB54: .4byte 0x0203DB70 @ EWRAM+0x3DB70
.L0813EB58: .4byte 0x0000FFFF
.L0813EB5C: .4byte 0x03004530 @ IWRAM+0x4530

	thumb_func_start sub_0813EB60
sub_0813EB60: @ 0x0813EB60
.L0813EB60:
	ldr r0, .L0813EB68
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L0813EB68: .4byte 0x0203DB70 @ EWRAM+0x3DB70

	thumb_func_start sub_0813EB6C
sub_0813EB6C: @ 0x0813EB6C
.L0813EB6C:
	ldr r1, .L0813EB74
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813EB74: .4byte 0x0203DB6A @ EWRAM+0x3DB6A

	thumb_func_start sub_0813EB78
sub_0813EB78: @ 0x0813EB78
.L0813EB78:
	ldr r0, .L0813EB80
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L0813EB80: .4byte 0x0203DB6A @ EWRAM+0x3DB6A

	thumb_func_start sub_0813EB84
sub_0813EB84: @ 0x0813EB84
.L0813EB84:
	push {r4, lr}
	ldr r2, .L0813EBA4
	strh r0, [r2]
	ldr r0, .L0813EBA8
	strh r1, [r0]
	ldr r1, .L0813EBAC
	movs r0, #0
	strb r0, [r1]
	ldr r4, .L0813EBB0
	movs r0, #1
	bl sub_080EDA24
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
.L0813EBA4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813EBA8: .4byte 0x0203DB7E @ EWRAM+0x3DB7E
.L0813EBAC: .4byte 0x0300684C @ IWRAM+0x684C
.L0813EBB0: .4byte 0x0203DB30 @ EWRAM+0x3DB30
	.byte 0x05, 0x00, 0x00, 0x40, 0xB0, 0x81, 0x01, 0x80, 0x00, 0x40, 0xD0, 0x81, 0x05, 0x80, 0x00, 0x40
	.byte 0xF0, 0x81, 0x09, 0x80, 0x00, 0x40, 0x10, 0x80, 0x0D, 0x80, 0x00, 0x40, 0x30, 0x80, 0x11, 0x80
	.global gUnknown_0813EBD4
gUnknown_0813EBD4: @ 0x0813EBD4
	.incbin "baserom.gba", 0x13EBD4, 0xC4
	.global gUnknown_0813EC98
gUnknown_0813EC98: @ 0x0813EC98
	.byte 0xDC, 0xEB, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xA0, 0xC1, 0x41, 0x80
	.byte 0x00, 0x00, 0xE0, 0xC1, 0x49, 0x80, 0x00, 0x00, 0x20, 0xC0, 0x51, 0x80
	.global gUnknown_0813ECB4
gUnknown_0813ECB4: @ 0x0813ECB4
	.byte 0xA0, 0xEC, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xA0, 0xC1, 0x41, 0x81
	.byte 0x00, 0x00, 0xE0, 0xC1, 0x49, 0x81, 0x00, 0x00, 0x20, 0xC0, 0x51, 0x81
	.global gUnknown_0813ECD0
gUnknown_0813ECD0: @ 0x0813ECD0
	.byte 0xBC, 0xEC, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xA0, 0xC1, 0x41, 0x82
	.byte 0x00, 0x00, 0xE0, 0xC1, 0x49, 0x82, 0x00, 0x00, 0x20, 0xC0, 0x51, 0x82
	.global gUnknown_0813ECEC
gUnknown_0813ECEC: @ 0x0813ECEC
	.incbin "baserom.gba", 0x13ECEC, 0x40
	.global gUnknown_0813ED2C
gUnknown_0813ED2C: @ 0x0813ED2C
	.incbin "baserom.gba", 0x13ED2C, 0x40
	.global gUnknown_0813ED6C
gUnknown_0813ED6C: @ 0x0813ED6C
	.byte 0x58, 0xED, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x40, 0x3C, 0x00
	.byte 0x00, 0x40, 0x28, 0x40, 0x38, 0x00, 0x00, 0x00
	.global gUnknown_0813ED84
gUnknown_0813ED84: @ 0x0813ED84
	.byte 0x74, 0xED, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x40, 0x55, 0x00
	.byte 0x00, 0x40, 0x20, 0x40, 0x59, 0x00, 0x00, 0x00
	.global gUnknown_0813ED9C
gUnknown_0813ED9C: @ 0x0813ED9C
	.byte 0x8C, 0xED, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x40, 0x00, 0x40, 0x11, 0x00
	.byte 0x00, 0x40, 0x20, 0x00, 0x15, 0x00, 0x00, 0x40, 0x38, 0x00, 0x17, 0x00, 0x00, 0x00, 0x48, 0x00
	.byte 0x19, 0x00, 0x00, 0x00
	.global gUnknown_0813EDC0
gUnknown_0813EDC0: @ 0x0813EDC0
	.byte 0xA4, 0xED, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x40, 0x1A, 0x00
	.byte 0x00, 0x40, 0x20, 0x00, 0x1E, 0x00, 0x00, 0x00
	.global gUnknown_0813EDD8
gUnknown_0813EDD8: @ 0x0813EDD8
	.byte 0xC8, 0xED, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x40, 0x3C, 0x10
	.byte 0x00, 0x40, 0x28, 0x40, 0x38, 0x10, 0x00, 0x00
	.global gUnknown_0813EDF0
gUnknown_0813EDF0: @ 0x0813EDF0
	.byte 0xE0, 0xED, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x40, 0x55, 0x10
	.byte 0x00, 0x40, 0x20, 0x40, 0x59, 0x10, 0x00, 0x00
	.global gUnknown_0813EE08
gUnknown_0813EE08: @ 0x0813EE08
	.byte 0xF8, 0xED, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x80, 0x20, 0x00
	.byte 0x00, 0x40, 0x20, 0x80, 0x24, 0x00, 0x00, 0x00
	.global gUnknown_0813EE20
gUnknown_0813EE20: @ 0x0813EE20
	.byte 0x10, 0xEE, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x40, 0x00, 0x80, 0x28, 0x00
	.byte 0x00, 0x40, 0x20, 0x80, 0x2C, 0x00, 0x00, 0x00, 0x40, 0x40, 0x30, 0x00
	.global gUnknown_0813EE3C
gUnknown_0813EE3C: @ 0x0813EE3C
	.byte 0x28, 0xEE, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x40, 0x00, 0x80, 0x60, 0x00
	.byte 0x00, 0x40, 0x20, 0x80, 0x64, 0x00, 0x00, 0x40, 0x40, 0x80, 0x68, 0x00
	.global gUnknown_0813EE58
gUnknown_0813EE58: @ 0x0813EE58
	.byte 0x44, 0xEE, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x40, 0x94, 0xC1, 0xA0, 0x10
	.byte 0x00, 0x40, 0xD4, 0xC1, 0xA8, 0x10, 0x00, 0x40, 0x14, 0xC0, 0xB0, 0x10, 0x00, 0x00, 0x54, 0x80
	.byte 0xB8, 0x10, 0x20, 0x40, 0xFC, 0x81, 0x2D, 0x11, 0x20, 0x80, 0x1C, 0x00, 0x31, 0x11, 0x00, 0x00
	.global gUnknown_0813EE88
gUnknown_0813EE88: @ 0x0813EE88
	.byte 0x60, 0xEE, 0x13, 0x08, 0x00, 0x00, 0x00, 0x00
