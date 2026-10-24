	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080BBCFC
sub_080BBCFC: @ 0x080BBCFC
	ldr r1, .L080BBD10
	ldr r0, .L080BBD14
	str r0, [r1]
	ldr r0, .L080BBD18
	str r0, [r1, #4]
	ldr r0, .L080BBD1C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BBD10: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BBD14: .4byte 0x02001000 @ EWRAM+0x1000
.L080BBD18: .4byte 0x06016800 @ VRAM+0x16800
.L080BBD1C: .4byte 0x84000600

	thumb_func_start sub_080BBD20
sub_080BBD20: @ 0x080BBD20
	push {r4, lr}
	sub sp, #4
	cmp r1, #0
	bne .L080BBD58
	ldr r0, .L080BBD44
	ldr r1, .L080BBD48
	bl LZ77UnCompWram
	ldr r1, .L080BBD4C
	ldr r2, .L080BBD50
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r0, .L080BBD54
	b .L080BBD76
.L080BBD44: .4byte gUnknown_08174294
.L080BBD48: .4byte 0x02001000 @ EWRAM+0x1000
.L080BBD4C: .4byte gUnknown_08174CF8
.L080BBD50: .4byte 0x03003170 @ IWRAM+0x3170
.L080BBD54: .4byte sub_080BBCD8
.L080BBD58:
	cmp r1, #1
	bne .L080BBD94
	ldr r0, .L080BBD80
	ldr r1, .L080BBD84
	bl LZ77UnCompWram
	ldr r1, .L080BBD88
	ldr r2, .L080BBD8C
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r0, .L080BBD90
.L080BBD76:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080BBDC8
	.byte 0x00, 0x00
.L080BBD80: .4byte gUnknown_08174D18
.L080BBD84: .4byte 0x02001000 @ EWRAM+0x1000
.L080BBD88: .4byte gUnknown_081755F0
.L080BBD8C: .4byte 0x03003190 @ IWRAM+0x3190
.L080BBD90: .4byte sub_080BBCFC
.L080BBD94:
	subs r4, r1, #2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r1, .L080BBDD4
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r1, r4, #0xb
	ldr r2, .L080BBDD8
	adds r1, r1, r2
	bl LZ77UnCompWram
	cmp r4, #6
	bne .L080BBDC8
	ldr r1, .L080BBDDC
	ldr r2, .L080BBDE0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r0, .L080BBDE4
	movs r1, #1
	bl VBlankTask_AddCounted
.L080BBDC8:
	bl Palette_MarkDirty
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080BBDD4: .4byte gUnknown_0818B5F0
.L080BBDD8: .4byte 0x02001000 @ EWRAM+0x1000
.L080BBDDC: .4byte gUnknown_0817748C
.L080BBDE0: .4byte 0x03003170 @ IWRAM+0x3170
.L080BBDE4: .4byte sub_080BBCD8

	thumb_func_start sub_080BBDE8
sub_080BBDE8: @ 0x080BBDE8
	strh r1, [r0, #0x24]
	bx lr

	thumb_func_start sub_080BBDEC
sub_080BBDEC: @ 0x080BBDEC
	push {r4, r5, r6, r7, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	adds r7, r0, #0
	adds r7, #0x24
	ldrh r1, [r0, #2]
	adds r0, r4, #0
	bl Task_Create
	adds r1, r0, #0
	adds r0, #0x24
	strh r5, [r0, #2]
	strh r6, [r0, #4]
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bne .L080BBE10
	str r1, [r7, #0xc]
.L080BBE10:
	ldr r0, [sp, #0x14]
	cmp r0, #2
	bne .L080BBE18
	str r1, [r7, #0x10]
.L080BBE18:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BBE20
sub_080BBE20: @ 0x080BBE20
	push {lr}
	sub sp, #0xc
	adds r2, r0, #0
	adds r2, #0x24
	ldr r1, .L080BBE50
	ldrh r0, [r0, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2, #2]
	str r1, [sp, #4]
	ldrh r1, [r2, #4]
	str r1, [sp, #8]
	movs r1, #6
	movs r2, #0xe
	movs r3, #2
	bl Sprite_Draw
	add sp, #0xc
	pop {r0}
	bx r0
.L080BBE50: .4byte gUnknown_0818B60C

	thumb_func_start sub_080BBE54
sub_080BBE54: @ 0x080BBE54
	push {lr}
	sub sp, #0xc
	adds r2, r0, #0
	adds r2, #0x24
	ldr r1, .L080BBE84
	ldrh r0, [r0, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xd0
	lsls r1, r1, #2
	str r1, [sp]
	ldrh r1, [r2, #2]
	str r1, [sp, #4]
	ldrh r1, [r2, #4]
	str r1, [sp, #8]
	movs r1, #9
	movs r2, #0xf
	movs r3, #3
	bl Sprite_Draw
	add sp, #0xc
	pop {r0}
	bx r0
.L080BBE84: .4byte gUnknown_0818B720

	thumb_func_start sub_080BBE88
sub_080BBE88: @ 0x080BBE88
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x24
	ldr r1, .L080BBEE0
	ldrh r0, [r4, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xd0
	lsls r1, r1, #2
	str r1, [sp]
	ldrh r1, [r2, #2]
	str r1, [sp, #4]
	ldrh r1, [r2, #4]
	adds r1, #0x38
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #9
	movs r2, #0xf
	movs r3, #3
	bl Sprite_Draw
	ldr r0, .L080BBEE4
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne .L080BBED6
	ldrh r0, [r4, #0x24]
	adds r0, #1
	strh r0, [r4, #0x24]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xd
	bne .L080BBED6
	strh r1, [r4, #0x24]
.L080BBED6:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BBEE0: .4byte gUnknown_0818B720
.L080BBEE4: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_080BBEE8
sub_080BBEE8: @ 0x080BBEE8
	adds r0, #0x24
	ldrh r1, [r0, #4]
	subs r1, #1
	strh r1, [r0, #4]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080BBEF4
sub_080BBEF4: @ 0x080BBEF4
	push {lr}
	ldr r0, [r0, #0x34]
	bl Task_End
	pop {r0}
	bx r0

	thumb_func_start sub_080BBF00
sub_080BBF00: @ 0x080BBF00
	push {lr}
	sub sp, #0xc
	adds r2, r0, #0
	adds r2, #0x24
	ldr r1, .L080BBF30
	ldrh r0, [r0, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2, #2]
	str r1, [sp, #4]
	ldrh r1, [r2, #4]
	str r1, [sp, #8]
	movs r1, #4
	movs r2, #0xe
	movs r3, #2
	bl Sprite_Draw
	add sp, #0xc
	pop {r0}
	bx r0
.L080BBF30: .4byte gUnknown_0818B834

	thumb_func_start sub_080BBF34
sub_080BBF34: @ 0x080BBF34
	push {lr}
	sub sp, #0xc
	adds r2, r0, #0
	adds r2, #0x24
	ldr r1, .L080BBF64
	ldrh r0, [r0, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2, #2]
	str r1, [sp, #4]
	ldrh r1, [r2, #4]
	str r1, [sp, #8]
	movs r1, #7
	movs r2, #0xe
	movs r3, #2
	bl Sprite_Draw
	add sp, #0xc
	pop {r0}
	bx r0
.L080BBF64: .4byte gUnknown_0818B960

	thumb_func_start sub_080BBF68
sub_080BBF68: @ 0x080BBF68
	ldr r1, [r0, #0x30]
	adds r1, #0x24
	ldrh r0, [r1, #4]
	subs r0, #1
	strh r0, [r1, #4]
	bx lr

	thumb_func_start sub_080BBF74
sub_080BBF74: @ 0x080BBF74
	push {lr}
	ldr r0, .L080BBF84
	movs r1, #1
	bl sub_080B8AE0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BBF84: .4byte 0x00007FFF

	thumb_func_start sub_080BBF88
sub_080BBF88: @ 0x080BBF88
	push {lr}
	movs r0, #0xf0
	lsls r0, r0, #1
	movs r1, #0x20
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BBF9C
sub_080BBF9C: @ 0x080BBF9C
	push {lr}
	ldr r0, [r0, #0x30]
	bl Task_End
	pop {r0}
	bx r0

	thumb_func_start sub_080BBFA8
sub_080BBFA8: @ 0x080BBFA8
	push {lr}
	sub sp, #8
	ldr r1, .L080BBFC4
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r2, #0x28
	movs r3, #3
	bl sub_080C4618
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BBFC4: .4byte 0x00000161

	thumb_func_start sub_080BBFC8
sub_080BBFC8: @ 0x080BBFC8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080BBFE0
	bl sub_080BC230
	ldr r1, [r0, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080BBFE4
	movs r0, #1
	b .L080BBFE6
.L080BBFE0: .4byte 0x00000161
.L080BBFE4:
	movs r0, #0
.L080BBFE6:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BBFF0
sub_080BBFF0: @ 0x080BBFF0
	push {lr}
	ldr r0, .L080BC000
	bl sub_080BC230
	movs r1, #1
	str r1, [r0, #0xc]
	pop {r0}
	bx r0
.L080BC000: .4byte 0x00000161

	thumb_func_start sub_080BC004
sub_080BC004: @ 0x080BC004
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080BC018
	bl sub_080BC230
	cmp r0, #0
	bne .L080BC01C
	movs r0, #1
	b .L080BC01E
	.byte 0x00, 0x00
.L080BC018: .4byte 0x00000161
.L080BC01C:
	movs r0, #0
.L080BC01E:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BC028
sub_080BC028: @ 0x080BC028
	ldr r1, .L080BC03C
	ldr r0, .L080BC040
	str r0, [r1]
	ldr r0, .L080BC044
	str r0, [r1, #4]
	ldr r0, .L080BC048
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BC03C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BC040: .4byte 0x02001000 @ EWRAM+0x1000
.L080BC044: .4byte 0x06015000 @ VRAM+0x15000
.L080BC048: .4byte 0x84000400

	thumb_func_start sub_080BC04C
sub_080BC04C: @ 0x080BC04C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	ldr r0, .L080BC090
	ldr r1, .L080BC094
	bl LZ77UnCompWram
	ldr r1, .L080BC098
	ldr r2, .L080BC09C
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080BC0A0
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r1, #0
	movs r0, #1
	strh r0, [r5, #0x24]
	movs r0, #4
	strh r0, [r4, #2]
	strh r0, [r4, #4]
	strh r1, [r4, #6]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BC090: .4byte gUnknown_0818C0C8
.L080BC094: .4byte 0x02001000 @ EWRAM+0x1000
.L080BC098: .4byte gUnknown_0818C5E0
.L080BC09C: .4byte 0x03003150 @ IWRAM+0x3150
.L080BC0A0: .4byte sub_080BC028

	thumb_func_start sub_080BC0A4
sub_080BC0A4: @ 0x080BC0A4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x18
	adds r6, r0, #0
	adds r6, #0x24
	ldr r0, .L080BC14C
	mov sb, r0
	ldrh r4, [r6, #2]
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	movs r1, #0xff
	bl __divsi3
	mov r8, r0
	mov r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	movs r1, #0xff
	bl __divsi3
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov r1, sb
	ldr r0, [r1]
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	add r0, sp, #0x10
	bl sub_0815851C
	ldr r0, .L080BC150
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	movs r6, #0xa0
	lsls r6, r6, #2
	str r6, [sp]
	movs r0, #0x2c
	mov r1, r8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r4, #0x26
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #8]
	movs r5, #0
	str r5, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl Sprite_DrawSharedAffine
	str r6, [sp]
	movs r0, #0xc4
	mov r1, r8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl Sprite_DrawSharedAffine
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BC14C: .4byte gUnknown_0800786C
.L080BC150: .4byte 0x03003800 @ IWRAM+0x3800

	thumb_func_start sub_080BC154
sub_080BC154: @ 0x080BC154
	adds r0, #0x24
	ldrh r1, [r0, #2]
	adds r1, #4
	strh r1, [r0, #2]
	ldrh r1, [r0, #4]
	adds r1, #4
	strh r1, [r0, #4]
	bx lr

	thumb_func_start sub_080BC164
sub_080BC164: @ 0x080BC164
	push {lr}
	movs r1, #0xbe
	bl sub_080BC260
	pop {r0}
	bx r0

	thumb_func_start sub_080BC170
sub_080BC170: @ 0x080BC170
	push {lr}
	sub sp, #4
	movs r0, #1
	bl sub_080BA7A0
	ldr r0, .L080BC190
	ldr r1, .L080BC194
	movs r2, #1
	str r2, [sp]
	movs r2, #0xe
	movs r3, #0x1a
	bl sub_080BA7CC
	add sp, #4
	pop {r0}
	bx r0
.L080BC190: .4byte gUnknown_0818F010
.L080BC194: .4byte gUnknown_0818EEA0

	thumb_func_start sub_080BC198
sub_080BC198: @ 0x080BC198
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, .L080BC1FC
	ldr r5, [r0]
	movs r0, #1
	ands r5, r0
	cmp r5, #0
	bne .L080BC1F2
	bl sub_080C2244
	adds r2, r0, #0
	movs r4, #0x7f
	ands r2, r4
	adds r2, #0x30
	str r5, [sp]
	str r5, [sp, #4]
	movs r0, #3
	movs r1, #0xc8
	movs r3, #0
	bl sub_080C4618
	bl sub_080C2244
	adds r2, r0, #0
	ands r2, r4
	adds r2, #0x30
	str r5, [sp]
	str r5, [sp, #4]
	movs r0, #4
	movs r1, #0xc9
	movs r3, #0
	bl sub_080C4618
	bl sub_080C2244
	adds r2, r0, #0
	ands r2, r4
	adds r2, #0x30
	str r5, [sp]
	str r5, [sp, #4]
	movs r0, #5
	movs r1, #0xca
	movs r3, #0
	bl sub_080C4618
.L080BC1F2:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BC1FC: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_080BC200
sub_080BC200: @ 0x080BC200
	push {lr}
	sub sp, #4
	ldr r1, .L080BC224
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r0, .L080BC228
	ldr r1, .L080BC22C
	movs r2, #1
	str r2, [sp]
	movs r2, #0xe
	movs r3, #0x1a
	bl sub_080BA7CC
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BC224: .4byte 0x0300000E @ IWRAM+0xE
.L080BC228: .4byte gUnknown_0818F010
.L080BC22C: .4byte gUnknown_0818EEA0

	thumb_func_start sub_080BC230
sub_080BC230: @ 0x080BC230
.L080BC230:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r3, #0
	ldr r2, .L080BC24C
.L080BC23A:
	ldr r1, [r2]
	cmp r1, #0
	beq .L080BC250
	ldrh r0, [r1, #0x2a]
	cmp r0, r4
	bne .L080BC250
	adds r0, r1, #0
	b .L080BC25A
	.byte 0x00, 0x00
.L080BC24C: .4byte 0x02036094 @ EWRAM+0x36094
.L080BC250:
	adds r2, #4
	adds r3, #1
	cmp r3, #5
	bls .L080BC23A
	movs r0, #0
.L080BC25A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080BC260
sub_080BC260: @ 0x080BC260
.L080BC260:
	push {lr}
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BC230
	cmp r0, #0
	beq .L080BC274
	movs r1, #0
	bl sub_080C48F0
.L080BC274:
	pop {r0}
	bx r0

	thumb_func_start sub_080BC278
sub_080BC278: @ 0x080BC278
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	cmp r1, #0x65
	bls .L080BC288
	b .L080BC4BE
.L080BC288:
	lsls r0, r1, #2
	ldr r1, .L080BC294
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080BC294: .4byte gUnknown_080BC298
	.global gUnknown_080BC298
gUnknown_080BC298:
.L080BC298: @ jump table
	.4byte .L080BC430
	.4byte .L080BC44C
	.4byte .L080BC460
	.4byte .L080BC470
	.4byte .L080BC470
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC488
	.4byte .L080BC48E
	.4byte .L080BC49C
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4BE
	.4byte .L080BC4A6
	.4byte .L080BC4AA
.L080BC430:
	adds r0, r4, #0
	movs r1, #0xb0
	bl sub_080BC260
	adds r0, r4, #0
	movs r1, #0xb1
	bl sub_080BC260
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #0xc5
	b .L080BC456
.L080BC44C:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #0xc6
.L080BC456:
	movs r2, #0x51
	movs r3, #0x40
	bl sub_080C4618
	b .L080BC4BE
.L080BC460:
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r4, #0
	movs r1, #0xc6
	movs r2, #0
	bl sub_080BAD88
	b .L080BC4BE
.L080BC470:
	ldr r3, .L080BC484
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #0xc7
	movs r2, #0x50
	bl sub_080C4618
	b .L080BC4BE
.L080BC484: .4byte 0x0000FF70
.L080BC488:
	bl sub_080B0820
	b .L080BC4BE
.L080BC48E:
	ldr r1, .L080BC498
	movs r0, #0
	strh r0, [r1]
	b .L080BC4BE
	.byte 0x00, 0x00
.L080BC498: .4byte 0x0300000E @ IWRAM+0xE
.L080BC49C:
	bl sub_080B4140
	bl sub_080B0778
	b .L080BC4BE
.L080BC4A6:
	movs r0, #0xc5
	b .L080BC4AC
.L080BC4AA:
	movs r0, #0xc7
.L080BC4AC:
	bl sub_080BC230
	ldr r1, [r0, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080BC4BE
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080BC4BE:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BC4C8
sub_080BC4C8: @ 0x080BC4C8
	push {lr}
	cmp r1, #0
	bne .L080BC4E0
	movs r0, #0xd8
	bl sub_080BC230
	cmp r0, #0
	beq .L080BC4F8
	movs r1, #0
	bl sub_080C48F0
	b .L080BC4F8
.L080BC4E0:
	cmp r1, #1
	beq .L080BC4F8
	cmp r1, #2
	bne .L080BC4F8
	movs r0, #0xd9
	bl sub_080BC230
	cmp r0, #0
	beq .L080BC4F8
	movs r1, #0
	bl sub_080C48F0
.L080BC4F8:
	pop {r0}
	bx r0

	thumb_func_start sub_080BC4FC
sub_080BC4FC: @ 0x080BC4FC
	push {lr}
	movs r0, #0xd9
	bl sub_080BC230
	adds r1, r0, #0
	cmp r1, #0
	beq .L080BC50E
	movs r0, #1
	strh r0, [r1, #0x34]
.L080BC50E:
	movs r0, #0xdf
	lsls r0, r0, #1
	bl sub_080BC230
	adds r1, r0, #0
	cmp r1, #0
	beq .L080BC520
	movs r0, #1
	strh r0, [r1, #0x34]
.L080BC520:
	ldr r0, .L080BC558
	bl sub_080BC230
	adds r1, r0, #0
	cmp r1, #0
	beq .L080BC530
	movs r0, #1
	strh r0, [r1, #0x34]
.L080BC530:
	ldr r0, .L080BC55C
	bl sub_080BC230
	adds r1, r0, #0
	cmp r1, #0
	beq .L080BC540
	movs r0, #1
	strh r0, [r1, #0x34]
.L080BC540:
	movs r0, #0xb6
	lsls r0, r0, #1
	bl sub_080BC230
	adds r1, r0, #0
	cmp r1, #0
	beq .L080BC552
	movs r0, #1
	strh r0, [r1, #0x34]
.L080BC552:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BC558: .4byte 0x000001BF
.L080BC55C: .4byte 0x0000016B

	thumb_func_start sub_080BC560
sub_080BC560: @ 0x080BC560
	ldr r1, .L080BC574
	ldr r0, .L080BC578
	str r0, [r1]
	ldr r0, .L080BC57C
	str r0, [r1, #4]
	ldr r0, .L080BC580
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BC574: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BC578: .4byte 0x02001000 @ EWRAM+0x1000
.L080BC57C: .4byte 0x06016800 @ VRAM+0x16800
.L080BC580: .4byte 0x84000300

	thumb_func_start sub_080BC584
sub_080BC584: @ 0x080BC584
	ldr r1, .L080BC598
	ldr r0, .L080BC59C
	str r0, [r1]
	ldr r0, .L080BC5A0
	str r0, [r1, #4]
	ldr r0, .L080BC5A4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BC598: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BC59C: .4byte 0x02001000 @ EWRAM+0x1000
.L080BC5A0: .4byte 0x06013000 @ VRAM+0x13000
.L080BC5A4: .4byte 0x84000E00

	thumb_func_start sub_080BC5A8
sub_080BC5A8: @ 0x080BC5A8
	push {r4, r5, lr}
	sub sp, #8
	cmp r1, #0
	bne .L080BC618
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #2
	movs r1, #0xd9
	movs r2, #0x78
	movs r3, #0x46
	bl sub_080C4618
	movs r0, #0xd8
	bl sub_080BC230
	cmp r0, #0
	beq .L080BC5D0
	movs r1, #0
	bl sub_080C48F0
.L080BC5D0:
	ldr r0, .L080BC600
	ldr r4, .L080BC604
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080BC608
	movs r1, #0x80
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080BC60C
	ldr r2, .L080BC610
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080BC614
	b .L080BC698
.L080BC600: .4byte gUnknown_08554E10
.L080BC604: .4byte 0x02001000 @ EWRAM+0x1000
.L080BC608: .4byte gUnknown_08555260
.L080BC60C: .4byte gUnknown_08555694
.L080BC610: .4byte 0x03003190 @ IWRAM+0x3190
.L080BC614: .4byte sub_080BC560
.L080BC618:
	cmp r1, #1
	bne .L080BC6C8
	ldr r1, .L080BC6A0
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #4
	movs r2, #0x78
	movs r3, #0x36
	bl sub_080C4618
	movs r1, #0xb6
	lsls r1, r1, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #5
	movs r2, #0x78
	movs r3, #0x46
	bl sub_080C4618
	ldr r0, .L080BC6A4
	ldr r4, .L080BC6A8
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080BC6AC
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080BC6B0
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080BC6B4
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080BC6B8
	ldr r4, .L080BC6BC
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080BC6C0
	adds r4, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080BC6C4
.L080BC698:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080BC700
.L080BC6A0: .4byte 0x0000016B
.L080BC6A4: .4byte gUnknown_08552CE0
.L080BC6A8: .4byte 0x02001000 @ EWRAM+0x1000
.L080BC6AC: .4byte gUnknown_085537C8
.L080BC6B0: .4byte gUnknown_08554300
.L080BC6B4: .4byte gUnknown_08554AE4
.L080BC6B8: .4byte gUnknown_08554AC4
.L080BC6BC: .4byte 0x03003150 @ IWRAM+0x3150
.L080BC6C0: .4byte gUnknown_08554DF0
.L080BC6C4: .4byte sub_080BC584
.L080BC6C8:
	cmp r1, #2
	bne .L080BC700
	movs r1, #0xdf
	lsls r1, r1, #1
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r2, #0x78
	movs r3, #0x46
	bl sub_080C4618
	ldr r1, .L080BC708
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #3
	movs r2, #0x78
	movs r3, #0x46
	bl sub_080C4618
	ldr r1, .L080BC70C
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0x78
	movs r3, #0x36
	bl sub_080C4618
.L080BC700:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BC708: .4byte 0x000001BF
.L080BC70C: .4byte 0x0000016D

	thumb_func_start sub_080BC710
sub_080BC710: @ 0x080BC710
	push {r4, r5, lr}
	adds r4, r1, #0
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r0, r5, #0
	bl sub_080BC230
	cmp r4, #0
	bne .L080BC742
	adds r0, r5, #0
	bl sub_080BC230
	adds r1, r0, #0
	adds r1, #0x24
	ldrh r0, [r1, #0xa]
	subs r0, #1
	strh r0, [r1, #0xa]
	ldr r0, .L080BC7BC
	bl sub_080BC230
	adds r1, r0, #0
	adds r1, #0x24
	ldrh r0, [r1, #0xa]
	subs r0, #1
	strh r0, [r1, #0xa]
.L080BC742:
	ldr r0, .L080BC7C0
	bl sub_080BC230
	adds r1, r0, #0
	adds r1, #0x24
	ldrh r0, [r1, #0xa]
	adds r0, #1
	movs r4, #0
	strh r0, [r1, #0xa]
	ldr r0, .L080BC7C4
	bl sub_080BC230
	adds r1, r0, #0
	adds r1, #0x24
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	movs r0, #0xb6
	lsls r0, r0, #1
	bl sub_080BC230
	adds r1, r0, #0
	adds r1, #0x24
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	movs r0, #0xc6
	bl Flag_Test
	cmp r0, #0
	beq .L080BC7F8
	ldr r2, .L080BC7C8
	ldr r1, .L080BC7CC
	movs r0, #0xe8
	strb r0, [r1]
	strb r0, [r2]
	ldr r2, .L080BC7D0
	ldr r1, .L080BC7D4
	movs r0, #8
	strb r0, [r1]
	strb r0, [r2]
	ldr r2, .L080BC7D8
	ldr r1, .L080BC7DC
	movs r0, #0x68
	strb r0, [r1]
	strb r0, [r2]
	ldr r1, .L080BC7E0
	ldr r0, .L080BC7E4
	strb r4, [r0]
	strb r4, [r1]
	ldr r0, .L080BC7E8
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080BC7EC
	strb r1, [r0]
	ldr r0, .L080BC7F0
	strb r4, [r0]
	ldr r0, .L080BC7F4
	strb r4, [r0]
	b .L080BC816
	.byte 0x00, 0x00
.L080BC7BC: .4byte 0x0000016D
.L080BC7C0: .4byte 0x000001BF
.L080BC7C4: .4byte 0x0000016B
.L080BC7C8: .4byte 0x03000030 @ IWRAM+0x30
.L080BC7CC: .4byte 0x03000032 @ IWRAM+0x32
.L080BC7D0: .4byte 0x03000031 @ IWRAM+0x31
.L080BC7D4: .4byte 0x03000033 @ IWRAM+0x33
.L080BC7D8: .4byte 0x03000034 @ IWRAM+0x34
.L080BC7DC: .4byte 0x03000036 @ IWRAM+0x36
.L080BC7E0: .4byte 0x03000035 @ IWRAM+0x35
.L080BC7E4: .4byte 0x03000037 @ IWRAM+0x37
.L080BC7E8: .4byte 0x03000038 @ IWRAM+0x38
.L080BC7EC: .4byte 0x03000039 @ IWRAM+0x39
.L080BC7F0: .4byte 0x0300003A @ IWRAM+0x3A
.L080BC7F4: .4byte 0x0300003B @ IWRAM+0x3B
.L080BC7F8:
	ldr r1, .L080BC824
	movs r0, #0xe8
	strb r0, [r1]
	ldr r1, .L080BC828
	movs r0, #8
	strb r0, [r1]
	ldr r1, .L080BC82C
	movs r0, #0xe0
	strb r0, [r1]
	ldr r1, .L080BC830
	movs r0, #0x68
	strb r0, [r1]
	ldr r1, .L080BC834
	movs r0, #0x3d
	strb r0, [r1]
.L080BC816:
	ldr r1, .L080BC838
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BC824: .4byte 0x03000030 @ IWRAM+0x30
.L080BC828: .4byte 0x03000031 @ IWRAM+0x31
.L080BC82C: .4byte 0x03000034 @ IWRAM+0x34
.L080BC830: .4byte 0x03000035 @ IWRAM+0x35
.L080BC834: .4byte 0x03000038 @ IWRAM+0x38
.L080BC838: .4byte 0x03000006 @ IWRAM+0x6

	thumb_func_start sub_080BC83C
sub_080BC83C: @ 0x080BC83C
	push {lr}
	ldr r1, .L080BC858
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080BC85C
	movs r0, #0x3f
	strb r0, [r1]
	ldr r0, .L080BC860
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BC858: .4byte 0x03000006 @ IWRAM+0x6
.L080BC85C: .4byte 0x03000038 @ IWRAM+0x38
.L080BC860: .4byte sub_080BAD28

	thumb_func_start sub_080BC864
sub_080BC864: @ 0x080BC864
	push {lr}
	ldr r0, .L080BC8AC
	bl sub_080BC230
	adds r1, r0, #0
	cmp r1, #0
	beq .L080BC876
	movs r0, #1
	strh r0, [r1, #0x34]
.L080BC876:
	ldr r0, .L080BC8B0
	bl sub_080BC230
	adds r1, r0, #0
	cmp r1, #0
	beq .L080BC886
	movs r0, #1
	strh r0, [r1, #0x34]
.L080BC886:
	ldr r0, .L080BC8B4
	bl sub_080BC230
	adds r1, r0, #0
	cmp r1, #0
	beq .L080BC896
	movs r0, #1
	strh r0, [r1, #0x34]
.L080BC896:
	movs r0, #0xdd
	lsls r0, r0, #1
	bl sub_080BC230
	adds r1, r0, #0
	cmp r1, #0
	beq .L080BC8A8
	movs r0, #1
	strh r0, [r1, #0x34]
.L080BC8A8:
	pop {r0}
	bx r0
.L080BC8AC: .4byte 0x000001BB
.L080BC8B0: .4byte 0x000001BD
.L080BC8B4: .4byte 0x000001B9

	thumb_func_start sub_080BC8B8
sub_080BC8B8: @ 0x080BC8B8
	push {lr}
	sub sp, #8
	ldr r1, .L080BC8D4
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #3
	movs r2, #0x78
	movs r3, #0x46
	bl sub_080C4618
	add sp, #8
	pop {r0}
	bx r0
.L080BC8D4: .4byte 0x000001BB

	thumb_func_start sub_080BC8D8
sub_080BC8D8: @ 0x080BC8D8
	push {r4, r5, lr}
	adds r4, r1, #0
	ldr r0, .L080BC91C
	bl sub_080BC230
	adds r5, r0, #0
	adds r5, #0x24
	ldrh r0, [r5, #6]
	bl sub_080D95F4
	strh r4, [r5, #0x18]
	subs r4, #3
	cmp r4, #1
	bhi .L080BC916
	ldr r0, .L080BC920
	bl sub_080BC230
	adds r5, r0, #0
	adds r5, #0x24
	ldrh r0, [r5, #0xa]
	subs r0, #1
	strh r0, [r5, #0xa]
	movs r0, #0xdd
	lsls r0, r0, #1
	bl sub_080BC230
	adds r5, r0, #0
	adds r5, #0x24
	ldrh r0, [r5, #0xa]
	subs r0, #1
	strh r0, [r5, #0xa]
.L080BC916:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BC91C: .4byte 0x000001BB
.L080BC920: .4byte 0x000001B9

	thumb_func_start sub_080BC924
sub_080BC924: @ 0x080BC924
	push {r4, lr}
	sub sp, #8
	ldr r0, .L080BC96C
	movs r1, #1
	bl sub_080B8AE0
	ldr r1, .L080BC970
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #4
	movs r2, #0x78
	movs r3, #0x46
	bl sub_080C4618
	ldr r1, .L080BC974
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #5
	movs r2, #0x78
	movs r3, #0x36
	bl sub_080C4618
	movs r1, #0xdd
	lsls r1, r1, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #6
	movs r2, #0x78
	movs r3, #0x3e
	bl sub_080C4618
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
.L080BC96C: .4byte 0x00007FFF
.L080BC970: .4byte 0x000001BD
.L080BC974: .4byte 0x000001B9

	thumb_func_start sub_080BC978
sub_080BC978: @ 0x080BC978
	ldr r1, .L080BC98C
	ldr r0, .L080BC990
	str r0, [r1]
	ldr r0, .L080BC994
	str r0, [r1, #4]
	ldr r0, .L080BC998
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BC98C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BC990: .4byte 0x02001800 @ EWRAM+0x1800
.L080BC994: .4byte 0x06013000 @ VRAM+0x13000
.L080BC998: .4byte 0x84000C00

	thumb_func_start sub_080BC99C
sub_080BC99C: @ 0x080BC99C
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L080BC9FC
	ldr r4, .L080BCA00
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080BCA04
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080BCA08
	movs r1, #0x80
	lsls r1, r1, #6
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080BCA0C
	ldr r4, .L080BCA10
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080BCA14
	adds r4, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080BCA18
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BC9FC: .4byte gUnknown_085537C8
.L080BCA00: .4byte 0x02001000 @ EWRAM+0x1000
.L080BCA04: .4byte gUnknown_08554300
.L080BCA08: .4byte gUnknown_08174D18
.L080BCA0C: .4byte gUnknown_08554AC4
.L080BCA10: .4byte 0x03003170 @ IWRAM+0x3170
.L080BCA14: .4byte gUnknown_081755F0
.L080BCA18: .4byte sub_080BC978

	thumb_func_start sub_080BCA1C
sub_080BCA1C: @ 0x080BCA1C
	push {lr}
	movs r0, #0xf0
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #0x20
	bl PalFade_FadeRangeToBlackWithDuration
	movs r0, #0xf8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #0x20
	bl PalFade_FadeRangeToBlackWithDuration
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BCA40
sub_080BCA40: @ 0x080BCA40
	push {lr}
	sub sp, #0xc
	ldr r0, .L080BCA68
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x46
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r0}
	bx r0
.L080BCA68: .4byte gUnknown_0818F54C

	thumb_func_start sub_080BCA6C
sub_080BCA6C: @ 0x080BCA6C
	push {lr}
	sub sp, #0xc
	ldr r0, .L080BCA98
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r1, #0x90
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x46
	str r1, [sp, #8]
	movs r1, #7
	movs r2, #0xf
	movs r3, #2
	bl Sprite_Draw
	add sp, #0xc
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BCA98: .4byte gUnknown_0818F634

	thumb_func_start sub_080BCA9C
sub_080BCA9C: @ 0x080BCA9C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	cmp r1, #0
	bne .L080BCABC
	ldr r0, .L080BCAB4
	ldr r1, .L080BCAB8
	bl Task_Create
	str r0, [r4, #0x24]
	b .L080BCAC6
.L080BCAB4: .4byte gUnknown_0818F564
.L080BCAB8: .4byte 0x0000FFFF
.L080BCABC:
	ldr r0, .L080BCACC
	ldr r1, .L080BCAD0
	bl Task_Create
	str r0, [r5, #4]
.L080BCAC6:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BCACC: .4byte gUnknown_0818F650
.L080BCAD0: .4byte 0x0000FFFF

	thumb_func_start sub_080BCAD4
sub_080BCAD4: @ 0x080BCAD4
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, [r0, #0x24]
	bl Task_End
	ldr r0, [r4, #4]
	bl Task_End
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080BCAEC
sub_080BCAEC: @ 0x080BCAEC
	adds r0, #0x24
	movs r2, #0
	movs r1, #4
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	strh r2, [r0, #6]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080BCAFC
sub_080BCAFC: @ 0x080BCAFC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r5, r0, #0
	adds r5, #0x24
	ldr r7, .L080BCB74
	ldrh r4, [r5, #2]
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	movs r1, #0xff
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	movs r1, #0xff
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, [r7]
	str r0, [sp, #0xc]
	str r5, [sp, #0x10]
	add r0, sp, #0xc
	bl sub_0815851C
	ldr r0, .L080BCB78
	str r0, [sp, #0xc]
	str r5, [sp, #0x10]
	ldr r0, .L080BCB7C
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080BCB6C
	movs r0, #0xf0
	lsls r0, r0, #2
	str r0, [sp]
	ldrh r0, [r5, #0xa]
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5, #0xc]
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
.L080BCB6C:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080BCB74: .4byte gUnknown_08006170
.L080BCB78: .4byte 0x03003800 @ IWRAM+0x3800
.L080BCB7C: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_080BCB80
sub_080BCB80: @ 0x080BCB80
	adds r0, #0x24
	ldrh r2, [r0, #2]
	adds r2, r2, r1
	strh r2, [r0, #2]
	ldrh r2, [r0, #4]
	adds r2, r2, r1
	strh r2, [r0, #4]
	bx lr

	thumb_func_start sub_080BCB90
sub_080BCB90: @ 0x080BCB90
	push {lr}
	sub sp, #8
	adds r0, r1, #0
	cmp r0, #0
	bne .L080BCBB4
	ldr r1, .L080BCBAC
	ldr r3, .L080BCBB0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0xf0
	bl sub_080C4618
	b .L080BCBCA
.L080BCBAC: .4byte 0x00000195
.L080BCBB0: .4byte 0x0000FFF3
.L080BCBB4:
	ldr r0, .L080BCBD0
	bl sub_080BC230
	adds r0, #0x24
	ldrh r1, [r0, #8]
	subs r1, #1
	strh r1, [r0, #8]
	ldr r1, .L080BCBD4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L080BCBCA:
	add sp, #8
	pop {r0}
	bx r0
.L080BCBD0: .4byte 0x00000195
.L080BCBD4: .4byte 0x03000004 @ IWRAM+0x4

	thumb_func_start sub_080BCBD8
sub_080BCBD8: @ 0x080BCBD8
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	cmp r1, #0
	bne .L080BCBF8
	ldr r3, .L080BCBF4
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #1
	movs r1, #0xc0
	movs r2, #0x50
	bl sub_080C4618
	b .L080BCC0A
.L080BCBF4: .4byte 0x0000FFD3
.L080BCBF8:
	movs r0, #0xc0
	bl sub_080BC230
	cmp r0, #0
	bne .L080BCC06
	movs r0, #1
	b .L080BCC08
.L080BCC06:
	movs r0, #0
.L080BCC08:
	strh r0, [r4, #0x1c]
.L080BCC0A:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BCC14
sub_080BCC14: @ 0x080BCC14
	ldr r1, .L080BCC28
	ldr r0, .L080BCC2C
	str r0, [r1]
	ldr r0, .L080BCC30
	str r0, [r1, #4]
	ldr r0, .L080BCC34
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BCC28: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BCC2C: .4byte 0x02001000 @ EWRAM+0x1000
.L080BCC30: .4byte 0x06017800 @ VRAM+0x17800
.L080BCC34: .4byte 0x84000200

	thumb_func_start sub_080BCC38
sub_080BCC38: @ 0x080BCC38
	push {lr}
	sub sp, #4
	ldr r0, .L080BCC68
	ldr r1, .L080BCC6C
	bl LZ77UnCompWram
	ldr r1, .L080BCC70
	ldr r2, .L080BCC74
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080BCC78
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BCC68: .4byte gUnknown_08532ABC
.L080BCC6C: .4byte 0x02001000 @ EWRAM+0x1000
.L080BCC70: .4byte gUnknown_08532D50
.L080BCC74: .4byte 0x03003150 @ IWRAM+0x3150
.L080BCC78: .4byte sub_080BCC14

	thumb_func_start sub_080BCC7C
sub_080BCC7C: @ 0x080BCC7C
	push {r4, r5, lr}
	ldr r0, .L080BCCA8
	ldr r1, .L080BCCAC
	bl Task_Create
	adds r4, r0, #0
	adds r4, #0x24
	bl sub_080C2244
	movs r5, #0x3f
	ands r0, r5
	adds r0, #0x30
	strh r0, [r4, #0xa]
	bl sub_080C2244
	ands r0, r5
	ldr r1, .L080BCCB0
	adds r0, r0, r1
	strh r0, [r4, #0xc]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BCCA8: .4byte gUnknown_0818F760
.L080BCCAC: .4byte 0x0000FFFF
.L080BCCB0: .4byte 0x0000FFF3

	thumb_func_start sub_080BCCB4
sub_080BCCB4: @ 0x080BCCB4
	push {lr}
	sub sp, #8
	adds r2, r0, #0
	cmp r1, #9
	bhi .L080BCD7E
	lsls r0, r1, #2
	ldr r1, .L080BCCC8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080BCCC8: .4byte gUnknown_080BCCCC
	.global gUnknown_080BCCCC
gUnknown_080BCCCC:
.L080BCCCC: @ jump table
	.4byte .L080BCCF4
	.4byte .L080BCD08
	.4byte .L080BCD18
	.4byte .L080BCD38
	.4byte .L080BCD30
	.4byte .L080BCD7E
	.4byte .L080BCD4C
	.4byte .L080BCD54
	.4byte .L080BCD5C
	.4byte .L080BCD78
.L080BCCF4:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #0xcb
	movs r2, #0x50
	movs r3, #0x6b
	bl sub_080C4618
	b .L080BCD7E
.L080BCD08:
	ldr r1, .L080BCD14
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b .L080BCD7E
	.byte 0x00, 0x00
.L080BCD14: .4byte 0x0300000E @ IWRAM+0xE
.L080BCD18:
	ldr r3, .L080BCD2C
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0xc6
	movs r2, #0x50
	bl sub_080C4618
	b .L080BCD7E
	.byte 0x00, 0x00
.L080BCD2C: .4byte 0x0000FFC0
.L080BCD30:
	ldr r1, .L080BCD48
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L080BCD38:
	adds r0, r2, #0
	movs r1, #0xc6
	movs r2, #0
	movs r3, #1
	bl sub_080BAD88
	b .L080BCD7E
	.byte 0x00, 0x00
.L080BCD48: .4byte 0x0300000E @ IWRAM+0xE
.L080BCD4C:
	adds r0, r2, #0
	bl sub_080BCDC4
	b .L080BCD7E
.L080BCD54:
	movs r0, #1
	bl sub_080C3818
	b .L080BCD7E
.L080BCD5C:
	movs r1, #0xe2
	lsls r1, r1, #1
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r2, #0x50
	movs r3, #0x6b
	bl sub_080C4618
	ldr r1, .L080BCD74
	str r0, [r1]
	b .L080BCD7E
.L080BCD74: .4byte 0x030068F0 @ IWRAM+0x68F0
.L080BCD78:
	adds r0, r2, #0
	bl sub_080BCE0C
.L080BCD7E:
	add sp, #8
	pop {r0}
	bx r0

	thumb_func_start sub_080BCD84
sub_080BCD84: @ 0x080BCD84
	push {lr}
	ldr r0, .L080BCD9C
	movs r1, #1
	strh r1, [r0, #0x34]
	movs r1, #0x80
	lsls r1, r1, #2
	movs r0, #0
	movs r2, #8
	bl PalFade_FadeRangeToBlack
	pop {r0}
	bx r0
.L080BCD9C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080BCDA0
sub_080BCDA0: @ 0x080BCDA0
	push {lr}
	sub sp, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, .L080BCDC0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r2, #0x50
	bl sub_080C4618
	add sp, #8
	pop {r0}
	bx r0
.L080BCDC0: .4byte 0x0000FFD3

	thumb_func_start sub_080BCDC4
sub_080BCDC4: @ 0x080BCDC4
.L080BCDC4:
	push {lr}
	ldr r0, .L080BCDEC
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L080BCDF0
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #2
	bl PalFade_FadeRangeToWhite
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #2
	bl PalFade_FadeRangeToWhite
	b .L080BCE06
.L080BCDEC: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080BCDF0:
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #2
	bl PalFade_FadeRangeToWhite
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #2
	bl PalFade_FadeRangeToWhite
.L080BCE06:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BCE0C
sub_080BCE0C: @ 0x080BCE0C
.L080BCE0C:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, .L080BCE30
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L080BCE34
	bl sub_080B04BC
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #2
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	b .L080BCE44
.L080BCE30: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080BCE34:
	bl sub_080B4140
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #2
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
.L080BCE44:
	movs r5, #0
	ldr r7, .L080BCE70
	movs r6, #0x20
.L080BCE4A:
	ldr r1, .L080BCE74
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L080BCED0
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r0, [r4, #6]
	bl sub_080D95F4
	ldr r1, [r0, #0x24]
	ldrh r2, [r4, #6]
	cmp r2, r7
	bne .L080BCE7C
	ldr r0, .L080BCE78
	ldrh r0, [r0]
	b .L080BCE88
	.byte 0x00, 0x00
.L080BCE70: .4byte 0x000001C1
.L080BCE74: .4byte 0x02036094 @ EWRAM+0x36094
.L080BCE78: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080BCE7C:
	movs r0, #0xe0
	lsls r0, r0, #1
	cmp r2, r0
	bne .L080BCE8E
	ldr r0, .L080BCEA4
	ldrh r0, [r0, #2]
.L080BCE88:
	bl sub_080D8248
	ldr r1, [r0, #4]
.L080BCE8E:
	ldrh r0, [r4, #4]
	cmp r0, #1
	bne .L080BCED0
	ldrh r0, [r4, #2]
	cmp r0, #0
	bne .L080BCEAC
	str r6, [sp]
	movs r0, #3
	ldr r2, .L080BCEA8
	b .L080BCEB6
	.byte 0x00, 0x00
.L080BCEA4: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080BCEA8: .4byte 0x03002D70 @ IWRAM+0x2D70
.L080BCEAC:
	cmp r0, #1
	bne .L080BCEC4
	str r6, [sp]
	movs r0, #3
	ldr r2, .L080BCEC0
.L080BCEB6:
	movs r3, #0x20
	bl Palette_CopyWithEffect
	b .L080BCED0
	.byte 0x00, 0x00
.L080BCEC0: .4byte 0x03002D90 @ IWRAM+0x2D90
.L080BCEC4:
	str r6, [sp]
	movs r0, #3
	ldr r2, .L080BCEEC
	movs r3, #0x20
	bl Palette_CopyWithEffect
.L080BCED0:
	adds r5, #1
	cmp r5, #5
	bls .L080BCE4A
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #2
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080BCEEC: .4byte 0x03002D50 @ IWRAM+0x2D50

	thumb_func_start sub_080BCEF0
sub_080BCEF0: @ 0x080BCEF0
	push {r4, lr}
	sub sp, #4
	movs r4, #0
	str r4, [sp]
	ldr r0, .L080BCF6C
	mov r1, sp
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, .L080BCF70
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080BCF74
	str r1, [r0, #4]
	ldr r2, .L080BCF78
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080BCF7C
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	bl sub_080C1450
	ldr r2, .L080BCF80
	ldr r1, .L080BCF84
	movs r0, #0xe8
	strb r0, [r1]
	strb r0, [r2]
	ldr r2, .L080BCF88
	ldr r1, .L080BCF8C
	movs r0, #8
	strb r0, [r1]
	strb r0, [r2]
	ldr r2, .L080BCF90
	ldr r1, .L080BCF94
	movs r0, #0x68
	strb r0, [r1]
	strb r0, [r2]
	ldr r1, .L080BCF98
	ldr r0, .L080BCF9C
	strb r4, [r0]
	strb r4, [r1]
	ldr r0, .L080BCFA0
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080BCFA4
	strb r1, [r0]
	ldr r0, .L080BCFA8
	strb r4, [r0]
	ldr r0, .L080BCFAC
	strb r4, [r0]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080BCF6C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BCF70: .4byte 0x85001000
.L080BCF74: .4byte 0x06004000 @ VRAM+0x4000
.L080BCF78: .4byte 0x85000020
.L080BCF7C: .4byte 0x06008000 @ VRAM+0x8000
.L080BCF80: .4byte 0x03000030 @ IWRAM+0x30
.L080BCF84: .4byte 0x03000032 @ IWRAM+0x32
.L080BCF88: .4byte 0x03000031 @ IWRAM+0x31
.L080BCF8C: .4byte 0x03000033 @ IWRAM+0x33
.L080BCF90: .4byte 0x03000034 @ IWRAM+0x34
.L080BCF94: .4byte 0x03000036 @ IWRAM+0x36
.L080BCF98: .4byte 0x03000035 @ IWRAM+0x35
.L080BCF9C: .4byte 0x03000037 @ IWRAM+0x37
.L080BCFA0: .4byte 0x03000038 @ IWRAM+0x38
.L080BCFA4: .4byte 0x03000039 @ IWRAM+0x39
.L080BCFA8: .4byte 0x0300003A @ IWRAM+0x3A
.L080BCFAC: .4byte 0x0300003B @ IWRAM+0x3B

	thumb_func_start sub_080BCFB0
sub_080BCFB0: @ 0x080BCFB0
.L080BCFB0:
	ldr r1, .L080BCFB8
	movs r0, #1
	strh r0, [r1, #0x34]
	bx lr
.L080BCFB8: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080BCFBC
sub_080BCFBC: @ 0x080BCFBC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #1
	bl sub_080C6E30
	ldr r1, .L080BCFE8
	movs r4, #0
	movs r0, #1
	strh r0, [r1, #0x30]
	adds r0, r5, #0
	bl sub_080BCFB0
	ldr r0, .L080BCFEC
	strh r4, [r0]
	ldr r0, .L080BCFF0
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BCFE8: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080BCFEC: .4byte 0x03004534 @ IWRAM+0x4534
.L080BCFF0: .4byte sub_080BCEF0

	thumb_func_start sub_080BCFF4
sub_080BCFF4: @ 0x080BCFF4
	push {r4, r5, lr}
	adds r0, r1, #0
	adds r4, r2, #0
	ldr r5, .L080BD014
	adds r1, r5, #0
	bl HuffUnComp
	ldr r0, .L080BD018
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BD014: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080BD018: .4byte 0x02001000 @ EWRAM+0x1000

	thumb_func_start sub_080BD01C
sub_080BD01C: @ 0x080BD01C
	ldr r1, .L080BD08C
	ldr r0, .L080BD090
	str r0, [r1]
	ldr r0, .L080BD094
	str r0, [r1, #4]
	ldr r0, .L080BD098
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080BD09C
	str r0, [r1]
	ldr r0, .L080BD0A0
	str r0, [r1, #4]
	ldr r0, .L080BD0A4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xd4
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r0, r2, #0
	strh r0, [r1]
	ldr r2, .L080BD0A8
	ldr r1, .L080BD0AC
	movs r0, #0xe8
	strb r0, [r1]
	strb r0, [r2]
	ldr r2, .L080BD0B0
	ldr r1, .L080BD0B4
	movs r0, #8
	strb r0, [r1]
	strb r0, [r2]
	ldr r2, .L080BD0B8
	ldr r1, .L080BD0BC
	movs r0, #0x68
	strb r0, [r1]
	strb r0, [r2]
	ldr r1, .L080BD0C0
	ldr r0, .L080BD0C4
	movs r2, #0
	strb r2, [r0]
	strb r2, [r1]
	ldr r0, .L080BD0C8
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080BD0CC
	strb r1, [r0]
	ldr r0, .L080BD0D0
	strb r2, [r0]
	ldr r0, .L080BD0D4
	strb r2, [r0]
	ldr r0, .L080BD0D8
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080BD0DC
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080BD08C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BD090: .4byte 0x02000000 @ EWRAM
.L080BD094: .4byte 0x06003000 @ VRAM+0x3000
.L080BD098: .4byte 0x84000400
.L080BD09C: .4byte 0x02001000 @ EWRAM+0x1000
.L080BD0A0: .4byte 0x06004000 @ VRAM+0x4000
.L080BD0A4: .4byte 0x84001500
.L080BD0A8: .4byte 0x03000030 @ IWRAM+0x30
.L080BD0AC: .4byte 0x03000032 @ IWRAM+0x32
.L080BD0B0: .4byte 0x03000031 @ IWRAM+0x31
.L080BD0B4: .4byte 0x03000033 @ IWRAM+0x33
.L080BD0B8: .4byte 0x03000034 @ IWRAM+0x34
.L080BD0BC: .4byte 0x03000036 @ IWRAM+0x36
.L080BD0C0: .4byte 0x03000035 @ IWRAM+0x35
.L080BD0C4: .4byte 0x03000037 @ IWRAM+0x37
.L080BD0C8: .4byte 0x03000038 @ IWRAM+0x38
.L080BD0CC: .4byte 0x03000039 @ IWRAM+0x39
.L080BD0D0: .4byte 0x0300003A @ IWRAM+0x3A
.L080BD0D4: .4byte 0x0300003B @ IWRAM+0x3B
.L080BD0D8: .4byte 0x0300000E @ IWRAM+0xE
.L080BD0DC: .4byte 0x0300000C @ IWRAM+0xC

	thumb_func_start sub_080BD0E0
sub_080BD0E0: @ 0x080BD0E0
	push {r4, lr}
	sub sp, #4
	ldr r0, .L080BD118
	ldr r4, .L080BD11C
	adds r1, r4, #0
	bl HuffUnComp
	ldr r1, .L080BD120
	adds r0, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080BD124
	ldr r2, .L080BD128
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	ldr r0, .L080BD12C
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080BD118: .4byte gUnknown_08194C78
.L080BD11C: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080BD120: .4byte 0x02000000 @ EWRAM
.L080BD124: .4byte gUnknown_08195278
.L080BD128: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080BD12C: .4byte sub_080BD01C

	thumb_func_start sub_080BD130
sub_080BD130: @ 0x080BD130
	ldr r1, .L080BD144
	ldr r0, .L080BD148
	str r0, [r1]
	ldr r0, .L080BD14C
	str r0, [r1, #4]
	ldr r0, .L080BD150
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BD144: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BD148: .4byte 0x02001000 @ EWRAM+0x1000
.L080BD14C: .4byte 0x06010000 @ VRAM+0x10000
.L080BD150: .4byte 0x84001000

	thumb_func_start sub_080BD154
sub_080BD154: @ 0x080BD154
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x24
	ldr r1, .L080BD1B0
	ldr r5, .L080BD1B4
	movs r6, #0x20
	str r6, [sp]
	movs r0, #3
	adds r2, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080BD1B8
	adds r5, #0x20
	str r6, [sp]
	movs r0, #3
	adds r2, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r0, .L080BD1BC
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r1, #0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #2]
	strh r0, [r4, #4]
	strh r1, [r4, #6]
	strh r1, [r4, #8]
	strh r6, [r4, #0xa]
	movs r0, #0x78
	strh r0, [r4, #0xc]
	ldr r0, .L080BD1C0
	strh r0, [r4, #0xe]
	movs r0, #0x8c
	lsls r0, r0, #1
	strh r0, [r4, #0x10]
	movs r0, #0x48
	strh r0, [r4, #0x12]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BD1B0: .4byte gUnknown_08196438
.L080BD1B4: .4byte 0x03002D70 @ IWRAM+0x2D70
.L080BD1B8: .4byte gUnknown_08196C80
.L080BD1BC: .4byte sub_080BD130
.L080BD1C0: .4byte 0x0000FFF8

	thumb_func_start sub_080BD1C4
sub_080BD1C4: @ 0x080BD1C4
	push {r4, r5, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, .L080BD290
	ldr r0, [r0]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	ldr r1, .L080BD294
	cmp r0, #0
	bne .L080BD1DE
	ldr r1, .L080BD298
.L080BD1DE:
	ldr r0, [r1]
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	add r0, sp, #0x10
	movs r3, #0
	bl sub_0815862C
	ldr r5, .L080BD29C
	str r5, [sp, #0x10]
	str r4, [sp, #0x14]
	ldrh r0, [r4, #2]
	cmp r0, #4
	beq .L080BD21A
	movs r0, #0xa0
	lsls r0, r0, #1
	str r0, [sp]
	ldrh r0, [r4, #0x10]
	str r0, [sp, #4]
	ldrh r0, [r4, #0x12]
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	movs r2, #0xf
	movs r3, #0
	bl Sprite_DrawSharedAffine
.L080BD21A:
	ldr r1, .L080BD2A0
	ldrh r0, [r4, #8]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r1]
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	add r0, sp, #0x10
	movs r3, #0
	bl sub_0815862C
	str r5, [sp, #0x10]
	str r4, [sp, #0x14]
	ldrh r0, [r4, #2]
	cmp r0, #4
	beq .L080BD25A
	movs r0, #0
	str r0, [sp]
	ldrh r1, [r4, #0xc]
	str r1, [sp, #4]
	ldrh r1, [r4, #0xe]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_DrawSharedAffine
.L080BD25A:
	ldrh r1, [r4, #8]
	cmp r1, #0xc
	beq .L080BD274
	ldrh r0, [r4, #0xa]
	subs r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080BD274
	movs r0, #0x20
	strh r0, [r4, #0xa]
	adds r0, r1, #1
	strh r0, [r4, #8]
.L080BD274:
	ldr r0, .L080BD290
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L080BD288
	ldr r1, .L080BD2A4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L080BD288:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BD290: .4byte 0x030031BC @ IWRAM+0x31BC
.L080BD294: .4byte gUnknown_080075D8
.L080BD298: .4byte gUnknown_080075A0
.L080BD29C: .4byte 0x03003800 @ IWRAM+0x3800
.L080BD2A0: .4byte gUnknown_08196CA0
.L080BD2A4: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080BD2A8
sub_080BD2A8: @ 0x080BD2A8
	push {lr}
	adds r2, r0, #0
	adds r2, #0x24
	ldr r0, .L080BD2C4
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L080BD2C0
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
.L080BD2C0:
	pop {r0}
	bx r0
.L080BD2C4: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_080BD2C8
sub_080BD2C8: @ 0x080BD2C8
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldrh r0, [r1, #8]
	cmp r0, #0xc
	bne .L080BD2F8
	ldrh r0, [r1, #0xe]
	strh r0, [r1, #0x12]
	ldrh r0, [r1, #0xc]
	strh r0, [r1, #0x10]
	ldrh r0, [r1, #2]
	cmp r0, #4
	beq .L080BD2F4
	subs r0, #2
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	subs r0, #2
	strh r0, [r1, #4]
	b .L080BD2F8
.L080BD2F4:
	movs r0, #1
	strh r0, [r2, #0x1c]
.L080BD2F8:
	pop {r0}
	bx r0

	thumb_func_start sub_080BD2FC
sub_080BD2FC: @ 0x080BD2FC
	push {lr}
	adds r2, r1, #0
	ldr r1, .L080BD310
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #1
	bl PalFade_FadeRangeToWhite
	pop {r0}
	bx r0
.L080BD310: .4byte 0x000001FF

	thumb_func_start sub_080BD314
sub_080BD314: @ 0x080BD314
	push {lr}
	movs r0, #0xfd
	bl Flag_Set
	ldr r0, .L080BD330
	bl Flag_Set
	movs r0, #0x87
	lsls r0, r0, #1
	bl Flag_Set
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BD330: .4byte 0x0000010D

	thumb_func_start sub_080BD334
sub_080BD334: @ 0x080BD334
	ldr r2, .L080BD384
	ldr r1, .L080BD388
	movs r0, #0xe8
	strb r0, [r1]
	strb r0, [r2]
	ldr r2, .L080BD38C
	ldr r1, .L080BD390
	movs r0, #8
	strb r0, [r1]
	strb r0, [r2]
	ldr r2, .L080BD394
	ldr r1, .L080BD398
	movs r0, #0x68
	strb r0, [r1]
	strb r0, [r2]
	ldr r1, .L080BD39C
	ldr r0, .L080BD3A0
	movs r2, #0
	strb r2, [r0]
	strb r2, [r1]
	ldr r0, .L080BD3A4
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080BD3A8
	strb r1, [r0]
	ldr r0, .L080BD3AC
	strb r2, [r0]
	ldr r0, .L080BD3B0
	strb r2, [r0]
	ldr r0, .L080BD3B4
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080BD3B8
	strh r1, [r0]
	ldr r0, .L080BD3BC
	strh r1, [r0]
	ldr r0, .L080BD3C0
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080BD384: .4byte 0x03000030 @ IWRAM+0x30
.L080BD388: .4byte 0x03000032 @ IWRAM+0x32
.L080BD38C: .4byte 0x03000031 @ IWRAM+0x31
.L080BD390: .4byte 0x03000033 @ IWRAM+0x33
.L080BD394: .4byte 0x03000034 @ IWRAM+0x34
.L080BD398: .4byte 0x03000036 @ IWRAM+0x36
.L080BD39C: .4byte 0x03000035 @ IWRAM+0x35
.L080BD3A0: .4byte 0x03000037 @ IWRAM+0x37
.L080BD3A4: .4byte 0x03000038 @ IWRAM+0x38
.L080BD3A8: .4byte 0x03000039 @ IWRAM+0x39
.L080BD3AC: .4byte 0x0300003A @ IWRAM+0x3A
.L080BD3B0: .4byte 0x0300003B @ IWRAM+0x3B
.L080BD3B4: .4byte 0x0300000E @ IWRAM+0xE
.L080BD3B8: .4byte 0x0300000C @ IWRAM+0xC
.L080BD3BC: .4byte 0x03000006 @ IWRAM+0x6
.L080BD3C0: .4byte 0x03000004 @ IWRAM+0x4

	thumb_func_start sub_080BD3C4
sub_080BD3C4: @ 0x080BD3C4
	push {lr}
	ldr r0, .L080BD3D4
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BD3D4: .4byte sub_080BD334

	thumb_func_start sub_080BD3D8
sub_080BD3D8: @ 0x080BD3D8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x6d
	bl sub_080B6DB4
	str r0, [r4, #0x24]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BD3EC
sub_080BD3EC: @ 0x080BD3EC
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x24]
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080BD3FC
	movs r0, #0
	b .L080BD3FE
.L080BD3FC:
	movs r0, #1
.L080BD3FE:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080BD404
sub_080BD404: @ 0x080BD404
	push {lr}
	movs r0, #0x8f
	lsls r0, r0, #1
	bl sub_080BC230
	adds r1, r0, #0
	cmp r1, #0
	beq .L080BD418
	movs r0, #3
	strh r0, [r1, #0x34]
.L080BD418:
	pop {r0}
	bx r0

	thumb_func_start sub_080BD41C
sub_080BD41C: @ 0x080BD41C
	push {lr}
	movs r0, #0xf0
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #0x10
	movs r3, #8
	bl PalFade_FadeRangeToBlackWithDuration
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #0x10
	movs r3, #8
	bl PalFade_FadeRangeToBlackWithDuration
	pop {r0}
	bx r0

	thumb_func_start sub_080BD43C
sub_080BD43C: @ 0x080BD43C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x71
	bl sub_080B6DB4
	str r0, [r4, #0x24]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BD450
sub_080BD450: @ 0x080BD450
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x24]
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080BD460
	movs r0, #0
	b .L080BD462
.L080BD460:
	movs r0, #1
.L080BD462:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080BD468
sub_080BD468: @ 0x080BD468
	ldr r1, .L080BD4F0
	ldr r0, .L080BD4F4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080BD4F8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080BD4FC
	str r0, [r1]
	ldr r0, .L080BD500
	str r0, [r1, #4]
	ldr r0, .L080BD504
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xd4
	movs r2, #0xf2
	lsls r2, r2, #7
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #8
	ldr r2, .L080BD508
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #6
	ldr r2, .L080BD50C
	adds r0, r2, #0
	strh r0, [r1]
	ldr r2, .L080BD510
	ldr r1, .L080BD514
	movs r0, #0xe8
	strb r0, [r1]
	strb r0, [r2]
	ldr r2, .L080BD518
	ldr r1, .L080BD51C
	movs r0, #8
	strb r0, [r1]
	strb r0, [r2]
	ldr r2, .L080BD520
	ldr r1, .L080BD524
	movs r0, #0x68
	strb r0, [r1]
	strb r0, [r2]
	ldr r1, .L080BD528
	ldr r0, .L080BD52C
	movs r2, #0
	strb r2, [r0]
	strb r2, [r1]
	ldr r0, .L080BD530
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080BD534
	strb r1, [r0]
	ldr r0, .L080BD538
	strb r2, [r0]
	ldr r0, .L080BD53C
	strb r2, [r0]
	ldr r0, .L080BD540
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080BD544
	strh r1, [r0]
	ldr r0, .L080BD548
	strh r1, [r0]
	ldr r0, .L080BD54C
	strh r1, [r0]
	bx lr
.L080BD4F0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BD4F4: .4byte 0x02000000 @ EWRAM
.L080BD4F8: .4byte 0x84000400
.L080BD4FC: .4byte 0x02001000 @ EWRAM+0x1000
.L080BD500: .4byte 0x0600F800 @ VRAM+0xF800
.L080BD504: .4byte 0x84000200
.L080BD508: .4byte 0x0000800B
.L080BD50C: .4byte 0x00008604
.L080BD510: .4byte 0x03000030 @ IWRAM+0x30
.L080BD514: .4byte 0x03000032 @ IWRAM+0x32
.L080BD518: .4byte 0x03000031 @ IWRAM+0x31
.L080BD51C: .4byte 0x03000033 @ IWRAM+0x33
.L080BD520: .4byte 0x03000034 @ IWRAM+0x34
.L080BD524: .4byte 0x03000036 @ IWRAM+0x36
.L080BD528: .4byte 0x03000035 @ IWRAM+0x35
.L080BD52C: .4byte 0x03000037 @ IWRAM+0x37
.L080BD530: .4byte 0x03000038 @ IWRAM+0x38
.L080BD534: .4byte 0x03000039 @ IWRAM+0x39
.L080BD538: .4byte 0x0300003A @ IWRAM+0x3A
.L080BD53C: .4byte 0x0300003B @ IWRAM+0x3B
.L080BD540: .4byte 0x0300000E @ IWRAM+0xE
.L080BD544: .4byte 0x0300000C @ IWRAM+0xC
.L080BD548: .4byte 0x03000002 @ IWRAM+0x2
.L080BD54C: .4byte 0x03000000 @ IWRAM

	thumb_func_start sub_080BD550
sub_080BD550: @ 0x080BD550
	push {lr}
	sub sp, #0x10
	ldr r0, .L080BD580
	ldr r1, .L080BD584
	movs r2, #0xf0
	lsls r2, r2, #2
	movs r3, #1
	str r3, [sp]
	movs r3, #0
	str r3, [sp, #4]
	movs r3, #0x1c
	str r3, [sp, #8]
	movs r3, #0xd
	str r3, [sp, #0xc]
	movs r3, #8
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080BD588
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #0x10
	pop {r0}
	bx r0
.L080BD580: .4byte gUnknown_081974F4
.L080BD584: .4byte 0x02000000 @ EWRAM
.L080BD588: .4byte sub_080BD468

	thumb_func_start sub_080BD58C
sub_080BD58C: @ 0x080BD58C
	push {lr}
	movs r0, #0xfd
	bl Flag_Set
	pop {r0}
	bx r0

	thumb_func_start sub_080BD598
sub_080BD598: @ 0x080BD598
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x21
	bl sub_080BC230
	adds r3, r0, #0
	adds r3, #0x24
	movs r1, #0
	strh r1, [r4, #0x1c]
	ldrh r1, [r3, #8]
	subs r1, #1
	strh r1, [r3, #8]
	ldrh r2, [r0, #0x24]
	movs r1, #0x20
	orrs r1, r2
	strh r1, [r0, #0x24]
	movs r1, #1
	strh r1, [r3, #0x12]
	ldrh r0, [r3, #8]
	cmp r0, #0x50
	bhi .L080BD5C4
	strh r1, [r4, #0x1c]
.L080BD5C4:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BD5CC
sub_080BD5CC: @ 0x080BD5CC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	ldr r0, .L080BD614
	ldr r1, .L080BD618
	bl LZ77UnCompWram
	ldr r1, .L080BD61C
	ldr r2, .L080BD620
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080BD624
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r1, #0
	movs r0, #1
	strh r0, [r5, #0x24]
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r4, #2]
	strh r0, [r4, #4]
	strh r1, [r4, #6]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BD614: .4byte gUnknown_0818C0C8
.L080BD618: .4byte 0x02001000 @ EWRAM+0x1000
.L080BD61C: .4byte gUnknown_0818C600
.L080BD620: .4byte 0x03003150 @ IWRAM+0x3150
.L080BD624: .4byte sub_080BC028

	thumb_func_start sub_080BD628
sub_080BD628: @ 0x080BD628
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r1, #0
	adds r4, #0x24
	ldr r0, .L080BD678
	ldr r0, [r0]
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	add r0, sp, #0x14
	movs r3, #0
	bl sub_0815862C
	ldr r0, .L080BD67C
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0x78
	str r0, [sp, #4]
	movs r0, #0x2b
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl Sprite_DrawSharedAffineDouble
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BD678: .4byte gUnknown_080078A8
.L080BD67C: .4byte 0x03003800 @ IWRAM+0x3800

	thumb_func_start sub_080BD680
sub_080BD680: @ 0x080BD680
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	ldr r0, .L080BD6C4
	ldr r1, .L080BD6C8
	bl LZ77UnCompWram
	ldr r1, .L080BD6CC
	ldr r2, .L080BD6D0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080BD6D4
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r1, #0
	movs r0, #1
	strh r0, [r5, #0x24]
	movs r0, #4
	strh r0, [r4, #2]
	strh r0, [r4, #4]
	strh r1, [r4, #6]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BD6C4: .4byte gUnknown_0818C0C8
.L080BD6C8: .4byte 0x02001000 @ EWRAM+0x1000
.L080BD6CC: .4byte gUnknown_0818C5E0
.L080BD6D0: .4byte 0x03003150 @ IWRAM+0x3150
.L080BD6D4: .4byte sub_080BC028

	thumb_func_start sub_080BD6D8
sub_080BD6D8: @ 0x080BD6D8
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, .L080BD724
	movs r5, #0
	ldr r0, [r0]
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	add r0, sp, #0x14
	movs r3, #0
	bl sub_0815862C
	ldr r0, .L080BD728
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0x78
	str r0, [sp, #4]
	movs r0, #0x27
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	str r5, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl Sprite_DrawSharedAffineDouble
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BD724: .4byte gUnknown_080078A8
.L080BD728: .4byte 0x03003800 @ IWRAM+0x3800

	thumb_func_start sub_080BD72C
sub_080BD72C: @ 0x080BD72C
	adds r0, #0x24
	ldrh r2, [r0, #2]
	adds r2, r2, r1
	strh r2, [r0, #2]
	ldrh r2, [r0, #4]
	adds r2, r2, r1
	strh r2, [r0, #4]
	bx lr

	thumb_func_start sub_080BD73C
sub_080BD73C: @ 0x080BD73C
	push {r4, lr}
	ldr r4, .L080BD754
	ldr r0, [r4]
	movs r1, #0
	bl sub_080E9044
	movs r0, #0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BD754: .4byte 0x030069C0 @ IWRAM+0x69C0

	thumb_func_start sub_080BD758
sub_080BD758: @ 0x080BD758
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r6, .L080BD798
	movs r4, #0
	movs r0, #0x22
	strh r0, [r6]
	ldr r1, .L080BD79C
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0x50
	movs r3, #0x43
	bl sub_080C4618
	ldr r5, .L080BD7A0
	str r0, [r5]
	movs r0, #0x47
	strh r0, [r6, #2]
	movs r1, #0xe0
	lsls r1, r1, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #1
	movs r2, #0x50
	movs r3, #0x43
	bl sub_080C4618
	str r0, [r5, #4]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BD798: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080BD79C: .4byte 0x000001C1
.L080BD7A0: .4byte 0x030068F0 @ IWRAM+0x68F0

	thumb_func_start sub_080BD7A4
sub_080BD7A4: @ 0x080BD7A4
	push {r4, r5, r6, lr}
	sub sp, #4
	cmp r1, #0
	bne .L080BD7E0
	ldr r4, .L080BD7D8
	ldr r5, .L080BD7DC
	movs r6, #0x10
	str r6, [sp]
	movs r0, #3
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl Palette_FillWithEffect
	adds r5, #0x20
	str r6, [sp]
	movs r0, #3
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl Palette_FillWithEffect
	bl Palette_MarkDirty
	b .L080BD81E
	.byte 0x00, 0x00
.L080BD7D8: .4byte 0x00007FFF
.L080BD7DC: .4byte 0x03003170 @ IWRAM+0x3170
.L080BD7E0:
	ldr r6, .L080BD828
	ldrh r0, [r6]
	bl sub_080D8248
	ldr r1, [r0, #4]
	ldr r4, .L080BD82C
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldrh r0, [r6, #2]
	bl sub_080D8248
	ldr r1, [r0, #4]
	adds r4, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xf0
	lsls r0, r0, #1
	movs r1, #0x20
	movs r2, #1
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
.L080BD81E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BD828: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080BD82C: .4byte 0x03002D70 @ IWRAM+0x2D70

	thumb_func_start sub_080BD830
sub_080BD830: @ 0x080BD830
	push {lr}
	ldr r1, .L080BD85C
	ldr r0, [r1]
	adds r2, r0, #0
	adds r2, #0x24
	ldr r0, [r1, #4]
	adds r3, r0, #0
	adds r3, #0x24
	ldr r0, .L080BD860
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080BD858
	ldrh r0, [r2, #8]
	subs r0, #1
	strh r0, [r2, #8]
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
.L080BD858:
	pop {r0}
	bx r0
.L080BD85C: .4byte 0x030068F0 @ IWRAM+0x68F0
.L080BD860: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_080BD864
sub_080BD864: @ 0x080BD864
	push {lr}
	ldr r0, .L080BD874
	movs r1, #1
	bl sub_080B8AE0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BD874: .4byte 0x00007FFF
