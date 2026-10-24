	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080D2F04
sub_080D2F04: @ 0x080D2F04
.L080D2F04:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, .L080D2F5C
	cmp r3, r0
	beq .L080D2F52
	adds r0, r3, #0
	bl sub_080BF648
	movs r6, #0
	adds r1, r0, #0
	adds r1, #0x22
	ldrh r0, [r0, #0x22]
	cmp r0, #0
	beq .L080D2F52
	lsls r5, r4, #0x10
	adds r4, r1, #0
.L080D2F30:
	ldrh r0, [r4]
	lsrs r3, r5, #0x10
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
	adds r4, #2
	movs r0, #0xc0
	lsls r0, r0, #0xc
	adds r5, r5, r0
	adds r6, #1
	cmp r6, #7
	bhi .L080D2F52
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080D2F30
.L080D2F52:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D2F5C: .4byte 0x0000FFFF

	thumb_func_start sub_080D2F60
sub_080D2F60: @ 0x080D2F60
	push {r4, r5, lr}
	sub sp, #0x10
	ldr r4, .L080D2F98
	movs r1, #0
	add r0, sp, #0xc
	strh r1, [r0]
	mov r1, sp
	adds r1, #0xe
	movs r0, #0x3b
	strh r0, [r1]
	ldrh r2, [r4]
	subs r0, r2, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r5, r1, #0
	cmp r0, #1
	bls .L080D2F84
	b .L080D30E8
.L080D2F84:
	movs r1, #0x72
	add r0, sp, #0xc
	strh r1, [r0]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bne .L080D2F9C
	movs r0, #0x22
	strh r0, [r5]
	b .L080D2FD2
.L080D2F98: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D2F9C:
	movs r0, #2
	strh r0, [r5]
	adds r0, r4, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	add r1, sp, #0xc
	ldrh r1, [r1]
	subs r1, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0x35
	bl sub_080D2F04
	adds r0, r4, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	add r1, sp, #0xc
	ldrh r1, [r1]
	subs r1, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r2, [r5]
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl sub_080D2F04
.L080D2FD2:
	ldr r4, .L080D30E4
	movs r0, #0
	str r0, [sp]
	add r0, sp, #0xc
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldrh r0, [r5]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	movs r0, #4
	str r0, [sp]
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	movs r0, #8
	str r0, [sp]
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	movs r0, #0xc
	str r0, [sp]
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, #0x60
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldrh r0, [r5]
	adds r0, #0x1a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	movs r0, #0x14
	str r0, [sp]
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5]
	adds r0, #0x1a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	movs r0, #0x18
	str r0, [sp]
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5]
	adds r0, #0x1a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	movs r0, #0x1c
	str r0, [sp]
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, #0x60
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5]
	adds r0, #0x1a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	b .L080D3158
	.byte 0x00, 0x00
.L080D30E4: .4byte gUnknown_084F3148
.L080D30E8:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bne .L080D310C
	ldr r1, .L080D3160
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0x9e
	movs r3, #0xc
	bl Canvas_FillRect
	bl sub_080D2D58
	bl sub_080D1F0C
.L080D310C:
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080D313E
	movs r4, #0
.L080D3114:
	lsls r0, r4, #0x12
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r1, sp, #0xc
	lsls r0, r4, #5
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5]
	str r0, [sp, #8]
	ldr r0, .L080D3164
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r4, #1
	cmp r4, #7
	bls .L080D3114
.L080D313E:
	add r0, sp, #0xc
	adds r1, r5, #0
	bl sub_080D21C4
	add r0, sp, #0xc
	ldrh r0, [r0]
	ldrh r1, [r5]
	ldr r2, .L080D3168
	ldr r3, .L080D316C
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_080C7664
.L080D3158:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D3160: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D3164: .4byte gUnknown_084F3148
.L080D3168: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080D316C: .4byte 0x00000AD8

	thumb_func_start sub_080D3170
sub_080D3170: @ 0x080D3170
.L080D3170:
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	cmp r3, #1
	bne .L080D31D0
	ldr r1, .L080D31C8
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D31CC
	movs r1, #0
	str r1, [sp]
	adds r1, r4, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	adds r1, r5, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	b .L080D31EC
	.byte 0x00, 0x00
.L080D31C8: .4byte gUnknown_084F3150
.L080D31CC: .4byte gUnknown_084F316C
.L080D31D0:
	ldr r1, .L080D31F4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D31EC:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D31F4: .4byte gUnknown_084F3150

	thumb_func_start sub_080D31F8
sub_080D31F8: @ 0x080D31F8
.L080D31F8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	bl NumberToDigits
	adds r6, r0, #0
	movs r1, #0
	movs r5, #0
	lsls r4, r4, #0x10
.L080D321C:
	adds r0, r6, #7
	subs r0, r0, r5
	ldrb r0, [r0]
	cmp r1, #1
	beq .L080D322E
	cmp r0, #0
	bne .L080D322E
	cmp r5, #7
	bne .L080D3246
.L080D322E:
	str r0, [sp]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	ldr r0, .L080D3260
	movs r1, #0
	adds r2, r7, #0
	movs r3, #0
	bl Sprite_DrawSingle
	movs r1, #1
.L080D3246:
	movs r0, #0x80
	lsls r0, r0, #0xc
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #7
	bls .L080D321C
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D3260: .4byte gUnknown_084F3174

	thumb_func_start sub_080D3264
sub_080D3264: @ 0x080D3264
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r4, .L080D32A8
	ldrh r0, [r4]
	cmp r0, #1
	beq .L080D3274
	b .L080D33F8
.L080D3274:
	ldrh r0, [r4, #4]
	cmp r0, #0xcf
	bls .L080D3300
	ldrh r0, [r4, #0x12]
	cmp r0, #1
	bhi .L080D3282
	b .L080D33F8
.L080D3282:
	ldrh r2, [r4, #0x10]
	cmp r2, #0
	bne .L080D32B0
	ldr r0, .L080D32AC
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080D32B0
	adds r0, r2, #1
	strh r0, [r4, #0x10]
	movs r0, #0x64
	bl sub_080C51D4
	adds r0, r5, #0
	bl Item_RenderDescription
	b .L080D32D2
	.byte 0x00, 0x00
.L080D32A8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D32AC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D32B0:
	ldrh r2, [r4, #0x10]
	cmp r2, #1
	bne .L080D32D2
	ldr r0, .L080D32FC
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080D32D2
	subs r0, r2, #1
	strh r0, [r4, #0x10]
	movs r0, #0x64
	bl sub_080C51D4
	adds r0, r5, #0
	bl Item_RenderDescription
.L080D32D2:
	ldrh r0, [r4, #0x10]
	cmp r0, #0
	bne .L080D32EC
	movs r0, #0
	movs r1, #0
	movs r2, #0xe6
	movs r3, #0x46
	bl sub_080C4B78
	ldrh r0, [r4, #0x10]
	cmp r0, #0
	bne .L080D32EC
	b .L080D33F8
.L080D32EC:
	movs r0, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0x46
	bl sub_080C4B14
	b .L080D33F8
	.byte 0x00, 0x00
.L080D32FC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D3300:
	movs r3, #0
	ldr r2, .L080D3318
	ldrh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080D331C
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq .L080D3332
	subs r0, #1
	b .L080D332E
.L080D3318: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D331C:
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080D3332
	ldrh r0, [r4, #2]
	cmp r0, #3
	beq .L080D3332
	adds r0, #1
.L080D332E:
	strh r0, [r4, #2]
	movs r3, #1
.L080D3332:
	cmp r3, #1
	bne .L080D3342
	movs r0, #0x64
	bl sub_080C51D4
	adds r0, r5, #0
	bl Item_RenderDescription
.L080D3342:
	ldrh r0, [r4, #0xc]
	subs r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080D335C
	movs r0, #8
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xa]
	adds r0, #1
	movs r1, #1
	ands r0, r1
	strh r0, [r4, #0xa]
.L080D335C:
	ldrh r0, [r4, #0xa]
	cmp r0, #0
	bne .L080D3386
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq .L080D3374
	movs r0, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0x46
	bl sub_080C4B14
.L080D3374:
	ldrh r0, [r4, #2]
	cmp r0, #3
	beq .L080D3386
	movs r0, #0
	movs r1, #0
	movs r2, #0xe6
	movs r3, #0x46
	bl sub_080C4B78
.L080D3386:
	ldrh r0, [r4, #2]
	cmp r0, #0
	bne .L080D33DC
	ldrh r0, [r4, #4]
	movs r1, #0
	add r2, sp, #0xc
	bl sub_080BF468
	ldr r0, [sp, #0xc]
	cmp r0, #0x80
	beq .L080D33B4
	cmp r0, #0x80
	bgt .L080D33A6
	cmp r0, #0x40
	beq .L080D33BC
	b .L080D33F8
.L080D33A6:
	cmp r0, #0xc0
	bne .L080D33F8
	ldr r0, .L080D33B0
	b .L080D33BE
	.byte 0x00, 0x00
.L080D33B0: .4byte gUnknown_080014D8
.L080D33B4:
	ldr r0, .L080D33B8
	b .L080D33BE
.L080D33B8: .4byte gUnknown_080014B0
.L080D33BC:
	ldr r0, .L080D33D8
.L080D33BE:
	movs r1, #0x90
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0xcd
	str r1, [sp, #4]
	movs r1, #0x46
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L080D33F8
.L080D33D8: .4byte gUnknown_080014C0
.L080D33DC:
	cmp r0, #2
	bne .L080D33F8
	movs r0, #0
	movs r1, #0xa
	movs r2, #0x3e
	movs r3, #0
	bl sub_080D3170
	movs r0, #1
	movs r1, #0x55
	movs r2, #0x3e
	movs r3, #0
	bl sub_080D3170
.L080D33F8:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080D3400
sub_080D3400: @ 0x080D3400
.L080D3400:
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	mov r8, r0
	mov sb, r1
	adds r6, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r0, sb
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r0, .L080D346C
	ldr r1, .L080D3470
	bl Task_Create
	mov sl, r0
	ldr r4, .L080D3474
	movs r5, #0
	str r5, [sp]
	ldr r2, .L080D3478
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	mov r0, r8
	strh r0, [r4]
	strh r5, [r4, #2]
	mov r0, sb
	strh r0, [r4, #6]
	strh r6, [r4, #4]
	strh r5, [r4, #0x10]
	adds r0, r6, #0
	bl Action_CountDescriptionBreaks
	strh r0, [r4, #0x12]
	movs r0, #8
	strh r0, [r4, #0xc]
	mov r0, sl
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080D346C: .4byte gUnknown_084F317C
.L080D3470: .4byte 0x0000FFFF
.L080D3474: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D3478: .4byte 0x05000200 @ PLTT+0x200

	thumb_func_start sub_080D347C
sub_080D347C: @ 0x080D347C
.L080D347C:
	push {r4, r5, lr}
	ldr r5, [sp, #0xc]
	ldr r4, .L080D34A0
	mov ip, r4
	adds r4, #0x9c
	strh r0, [r4]
	mov r0, ip
	adds r0, #0x9e
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D34A0: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D34A4
sub_080D34A4: @ 0x080D34A4
.L080D34A4:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r5, r1, #0
	adds r0, r3, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, .L080D34EC
	movs r6, #0
	strh r2, [r4, #6]
	strh r0, [r4, #4]
	strh r6, [r4, #0x10]
	bl Action_CountDescriptionBreaks
	strh r0, [r4, #0x12]
	strh r5, [r4]
	strh r6, [r4, #2]
	movs r0, #8
	strh r0, [r4, #0xc]
	mov r0, r8
	bl sub_080D2028
	mov r0, r8
	bl Item_RenderDescription
	mov r0, r8
	bl sub_080D21F8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D34EC: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D34F0
sub_080D34F0: @ 0x080D34F0
.L080D34F0:
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r4, .L080D3520
	bl sub_080D1FFC
	ldrh r0, [r4]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L080D3528
	ldr r1, .L080D3524
	movs r0, #0x1c
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #1
	movs r3, #0
	bl Tilemap_FillRect
	b .L080D353C
	.byte 0x00, 0x00
.L080D3520: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D3524: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080D3528:
	ldr r1, .L080D356C
	movs r0, #0x1c
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #1
	movs r3, #5
	bl Tilemap_FillRect
.L080D353C:
	bl sub_080C6558
	bl sub_080C6764
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080D355E
	ldr r2, .L080D3570
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r3, #0x20
	bl Palette_FillWithEffect
	bl Palette_MarkDirty
.L080D355E:
	adds r0, r5, #0
	bl Task_End
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D356C: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080D3570: .4byte 0x03003150 @ IWRAM+0x3150

	thumb_func_start sub_080D3574
sub_080D3574: @ 0x080D3574
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	ldr r0, .L080D35D0
	ldr r4, [r0]
	ldr r7, .L080D35D4
	ldr r0, .L080D35D8
	mov r8, r0
	movs r6, #0x15
	str r6, [sp]
	movs r0, #7
	str r0, [sp, #4]
	movs r5, #8
	str r5, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r1, [r4, #0x24]
	cmp r1, #2
	bne .L080D35BE
	str r6, [sp]
	movs r0, #9
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r1, [sp, #0xc]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
.L080D35BE:
	bl sub_080C6764
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D35D0: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080D35D4: .4byte gUnknown_081B8170
.L080D35D8: .4byte 0x0200DFD4 @ EWRAM+0xDFD4

	thumb_func_start sub_080D35DC
sub_080D35DC: @ 0x080D35DC
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r6, .L080D3614
	movs r5, #8
	str r5, [sp]
	movs r4, #2
	str r4, [sp, #4]
	movs r0, #0
	adds r1, r6, #0
	movs r2, #0x15
	movs r3, #7
	bl Tilemap_FillRect
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0
	adds r1, r6, #0
	movs r2, #0x15
	movs r3, #9
	bl Tilemap_FillRect
	bl sub_080C6764
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D3614: .4byte 0x0200DFD4 @ EWRAM+0xDFD4

	thumb_func_start sub_080D3618
sub_080D3618: @ 0x080D3618
	push {r4, r5, lr}
	ldr r0, .L080D3648
	ldr r4, [r0]
	adds r5, r4, #0
	adds r5, #0x24
	ldr r0, .L080D364C
	ldr r1, .L080D3650
	adds r0, r0, r1
	ldr r2, [r0]
	movs r0, #0x15
	movs r1, #7
	bl sub_080C7664
	ldr r0, [r4, #0x24]
	cmp r0, #2
	bne .L080D3642
	ldr r2, [r5, #4]
	movs r0, #0x15
	movs r1, #9
	bl sub_080C7664
.L080D3642:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D3648: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080D364C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080D3650: .4byte 0x00000AD8

	thumb_func_start sub_080D3654
sub_080D3654: @ 0x080D3654
.L080D3654:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L080D3670
	ldr r1, .L080D3674
	bl Task_Create
	ldr r1, .L080D3678
	str r0, [r1]
	str r4, [r0, #0x24]
	str r5, [r0, #0x28]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D3670: .4byte gUnknown_084F31E0
.L080D3674: .4byte 0x0000FFFF
.L080D3678: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D367C
sub_080D367C: @ 0x080D367C
.L080D367C:
	ldr r1, .L080D3684
	ldr r1, [r1]
	str r0, [r1, #0x28]
	bx lr
.L080D3684: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D3688
sub_080D3688: @ 0x080D3688
.L080D3688:
	ldr r0, .L080D3694
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0xc]
	bx lr
	.byte 0x00, 0x00
.L080D3694: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D3698
sub_080D3698: @ 0x080D3698
	ldr r1, .L080D36AC
	ldr r0, .L080D36B0
	str r0, [r1]
	ldr r0, .L080D36B4
	str r0, [r1, #4]
	ldr r0, .L080D36B8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D36AC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D36B0: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080D36B4: .4byte 0x06015000 @ VRAM+0x15000
.L080D36B8: .4byte 0x84000400

	thumb_func_start sub_080D36BC
sub_080D36BC: @ 0x080D36BC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #1
	str r0, [sp]
	movs r0, #0x17
	movs r1, #0
	movs r2, #6
	movs r3, #3
	bl TextWindow_CreateOpen
	str r0, [r4, #0x24]
	ldr r1, .L080D36F4
	ldr r0, .L080D36F8
	str r0, [r1]
	ldr r0, .L080D36FC
	str r0, [r1, #4]
	ldr r0, .L080D3700
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080D3704
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080D36F4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D36F8: .4byte gUnknown_081B5710
.L080D36FC: .4byte 0x0200BEC8 @ EWRAM+0xBEC8
.L080D3700: .4byte 0x84000040
.L080D3704: .4byte sub_080D3698

	thumb_func_start sub_080D3708
sub_080D3708: @ 0x080D3708
	push {lr}
	sub sp, #0xc
	ldr r0, .L080D373C
	movs r1, #0xbe
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0xba
	str r1, [sp, #4]
	movs r1, #3
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_080C31F0
	movs r1, #0xb8
	movs r2, #0xb
	movs r3, #0
	bl sub_080C8048
	add sp, #0xc
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D373C: .4byte gUnknown_08002A4C

	thumb_func_start sub_080D3740
sub_080D3740: @ 0x080D3740
.L080D3740:
	push {lr}
	ldr r0, .L080D3750
	ldr r1, .L080D3754
	bl Task_Create
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080D3750: .4byte gUnknown_084F3204
.L080D3754: .4byte 0x0000FFFF

	thumb_func_start sub_080D3758
sub_080D3758: @ 0x080D3758
.L080D3758:
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x24]
	movs r1, #1
	bl TextWindow_Close
	adds r0, r4, #0
	bl Task_End
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080D3770
sub_080D3770: @ 0x080D3770
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	movs r0, #0
	bl sub_080DABCC
	movs r3, #0
	strh r0, [r4, #8]
	ldr r0, .L080D37B4
	ldr r1, .L080D37B8
	movs r2, #0x15
	str r2, [sp]
	str r3, [sp, #4]
	movs r2, #8
	str r2, [sp, #8]
	movs r2, #2
	str r2, [sp, #0xc]
	movs r2, #0
	bl Tilemap_CopyRectSkipZero
	movs r0, #1
	str r0, [sp]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0xb
	bl TextWindow_CreateOpen
	str r0, [r5, #0x24]
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D37B4: .4byte gUnknown_081B8170
.L080D37B8: .4byte 0x0200DFD4 @ EWRAM+0xDFD4

	thumb_func_start CasinoPrize_DrawRows
CasinoPrize_DrawRows: @ 0x080D37BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r0, #0x24
	mov sl, r0
	ldrh r0, [r0, #8]
	str r0, [sp, #8]
	mov r0, sl
	ldrh r1, [r0, #4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x12
	movs r1, #0x80
	lsls r1, r1, #0xb
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0
	movs r2, #0
	movs r3, #0xc
	bl sub_080C49EC
	movs r4, #0
.L080D37F2:
	mov r1, sl
	ldrh r0, [r1, #6]
	adds r0, r0, r4
	lsls r0, r0, #1
	ldr r1, .L080D3844
	adds r0, r0, r1
	ldrh r7, [r0]
	adds r0, r4, #1
	mov sb, r0
	ldr r1, [sp, #8]
	subs r1, #1
	str r1, [sp, #0xc]
	cmp r7, #0
	beq .L080D386A
	adds r0, r7, #0
	bl Action_GetRecord
	adds r0, #0xc
	mov r8, r0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0xc
	lsls r5, r0, #0x10
	mov r4, r8
.L080D382A:
	adds r0, r7, #0
	bl sub_080C5B10
	cmp r0, #0
	beq .L080D3848
	ldrh r0, [r4]
	lsrs r3, r5, #0x10
	str r6, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
	b .L080D385A
.L080D3844: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080D3848:
	ldrh r0, [r4]
	lsrs r3, r5, #0x10
	str r6, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyphTinted
.L080D385A:
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r5, r5, r1
	adds r4, #2
	mov r0, r8
	adds r0, #0xe
	cmp r4, r0
	bls .L080D382A
.L080D386A:
	mov r4, sb
	cmp r4, #5
	bls .L080D37F2
	ldr r0, .L080D38C8
	ldr r1, .L080D38CC
	adds r0, r0, r1
	ldr r2, [r0]
	movs r0, #0x15
	movs r1, #0
	bl sub_080C7664
	mov r1, sl
	ldrh r0, [r1, #6]
	cmp r0, #0
	beq .L080D389C
	movs r2, #0xc
	adds r2, #0x60
	movs r3, #4
	subs r3, #4
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0
	movs r1, #0
	bl sub_080C4A4C
.L080D389C:
	mov r1, sl
	ldrh r0, [r1, #6]
	adds r0, #6
	ldr r1, [sp, #0xc]
	cmp r0, r1
	bgt .L080D38B8
	movs r2, #0xc
	adds r2, #0x60
	movs r3, #4
	adds r3, #0x4c
	movs r0, #0
	movs r1, #0
	bl sub_080C4AB0
.L080D38B8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080D38C8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080D38CC: .4byte 0x00000AD8
