	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080BA1AC
sub_080BA1AC: @ 0x080BA1AC
	push {lr}
	ldr r0, .L080BA1BC
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BA1BC: .4byte sub_080BA170

	thumb_func_start sub_080BA1C0
sub_080BA1C0: @ 0x080BA1C0
	push {r4, r5, lr}
	ldr r1, .L080BA1E4
	ldr r4, .L080BA1E8
	ldr r5, [r4]
	ldr r0, .L080BA1EC
	str r0, [r4]
	ldr r0, .L080BA1F0
	bl _call_via_r1
	str r5, [r4]
	ldr r0, .L080BA1F4
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BA1E4: .4byte 0x03004011 @ IWRAM+0x4011
.L080BA1E8: .4byte 0x03003FC0 @ IWRAM+0x3FC0
.L080BA1EC: .4byte 0x02001000 @ EWRAM+0x1000
.L080BA1F0: .4byte gUnknown_08173578
.L080BA1F4: .4byte sub_080B2880

	thumb_func_start sub_080BA1F8
sub_080BA1F8: @ 0x080BA1F8
	ldr r1, .L080BA20C
	ldr r0, .L080BA210
	str r0, [r1]
	ldr r0, .L080BA214
	str r0, [r1, #4]
	ldr r0, .L080BA218
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BA20C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BA210: .4byte 0x02001000 @ EWRAM+0x1000
.L080BA214: .4byte 0x06015000 @ VRAM+0x15000
.L080BA218: .4byte 0x84000800

	thumb_func_start sub_080BA21C
sub_080BA21C: @ 0x080BA21C
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r0, .L080BA2B0
	ldr r4, .L080BA2B4
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080BA2B8
	movs r1, #0x80
	lsls r1, r1, #5
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080BA2BC
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080BA2C0
	ldr r6, .L080BA2C4
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	adds r2, r6, #0
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r5, .L080BA2C8
	adds r2, r6, #0
	subs r2, #0x20
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080BA2CC
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r1, #0x80
	lsls r1, r1, #2
	adds r2, r6, r1
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r3, .L080BA2D0
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #1
	bl PalFade_FadeRangeInFromBlackTagged
	ldr r1, .L080BA2D4
	str r0, [r1]
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x20
	movs r2, #1
	bl PalFade_FadeRangeInFromBlack
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BA2B0: .4byte gUnknown_08165AD4
.L080BA2B4: .4byte 0x02001000 @ EWRAM+0x1000
.L080BA2B8: .4byte gUnknown_081660D4
.L080BA2BC: .4byte sub_080BA1F8
.L080BA2C0: .4byte gUnknown_08165A54
.L080BA2C4: .4byte 0x03002B70 @ IWRAM+0x2B70
.L080BA2C8: .4byte gUnknown_08165A94
.L080BA2CC: .4byte gUnknown_08165AB4
.L080BA2D0: .4byte 0x00008001
.L080BA2D4: .4byte 0x0300452C @ IWRAM+0x452C

	thumb_func_start sub_080BA2D8
sub_080BA2D8: @ 0x080BA2D8
	push {r4, lr}
	ldr r4, .L080BA2EC
	ldrh r0, [r4, #2]
	bl sub_080B1A1C
	strh r0, [r4, #2]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BA2EC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080BA2F0
sub_080BA2F0: @ 0x080BA2F0
.L080BA2F0:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r6, #0x24
	ldrh r1, [r6, #0x30]
	movs r7, #0x80
	lsls r7, r7, #8
	cmp r1, r7
	beq .L080BA33A
	ldr r0, .L080BA3A0
	movs r5, #0xc0
	lsls r5, r5, #2
	str r5, [sp]
	movs r4, #0x58
	str r4, [sp, #4]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #9
	movs r2, #0xe
	movs r3, #3
	bl Sprite_Draw
	ldr r0, .L080BA3A4
	str r5, [sp]
	str r4, [sp, #4]
	ldrh r1, [r6, #0x30]
	adds r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #9
	movs r2, #0xe
	movs r3, #3
	bl Sprite_Draw
.L080BA33A:
	ldrh r0, [r6, #0x32]
	cmp r0, r7
	beq .L080BA396
	ldr r0, .L080BA3A8
	movs r4, #0xa0
	lsls r4, r4, #2
	str r4, [sp]
	movs r1, #0x58
	str r1, [sp, #4]
	movs r5, #0x18
	str r5, [sp, #8]
	movs r1, #9
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
	ldr r0, .L080BA3AC
	str r4, [sp]
	ldrh r2, [r6, #0x32]
	movs r1, #0x58
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #9
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
	ldr r0, .L080BA3B0
	str r4, [sp]
	ldrh r1, [r6, #0x32]
	adds r1, #0x78
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #9
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
	movs r0, #0
	bl sub_080B29A8
.L080BA396:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BA3A0: .4byte gUnknown_08002D08
.L080BA3A4: .4byte gUnknown_08002D44
.L080BA3A8: .4byte gUnknown_08002CAC
.L080BA3AC: .4byte gUnknown_08002C88
.L080BA3B0: .4byte gUnknown_08002C70

	thumb_func_start sub_080BA3B4
sub_080BA3B4: @ 0x080BA3B4
	adds r0, #0x24
	ldrh r1, [r0, #0x30]
	adds r1, #2
	strh r1, [r0, #0x30]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080BA3C0
sub_080BA3C0: @ 0x080BA3C0
	adds r0, #0x24
	movs r2, #0
	movs r1, #0x80
	lsls r1, r1, #8
	strh r1, [r0, #0x30]
	strh r2, [r0, #0x32]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080BA3D0
sub_080BA3D0: @ 0x080BA3D0
	adds r0, #0x24
	ldrh r1, [r0, #0x32]
	adds r1, #2
	strh r1, [r0, #0x32]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080BA3DC
sub_080BA3DC: @ 0x080BA3DC
	push {lr}
	ldr r0, .L080BA3F8
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080BA3FC
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080BA400
	strb r1, [r0]
	ldr r0, .L080BA404
	strb r1, [r0]
	pop {r0}
	bx r0
.L080BA3F8: .4byte sub_080ADF64
.L080BA3FC: .4byte 0x03000038 @ IWRAM+0x38
.L080BA400: .4byte 0x03000039 @ IWRAM+0x39
.L080BA404: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080BA408
sub_080BA408: @ 0x080BA408
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	adds r7, r4, #0
	adds r7, #0x24
	ldr r5, .L080BA494
	ldrh r0, [r5]
	ldr r1, [r7, #8]
	lsls r1, r1, #1
	adds r4, #0x44
	adds r1, r4, r1
	ldrh r1, [r1]
	bl sub_080C8B10
	adds r6, r0, #0
	ldrh r0, [r5]
	ldr r1, [r7, #0xc]
	lsls r1, r1, #1
	adds r4, r4, r1
	ldrh r1, [r4]
	bl sub_080C8B10
	ldrh r4, [r0, #6]
	ldrh r0, [r6, #6]
	mov r8, r0
	movs r1, #6
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bge .L080BA44E
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
.L080BA44E:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge .L080BA45C
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L080BA45C:
	movs r0, #0
	str r0, [r7, #0x34]
	strh r0, [r7, #0x38]
	ldr r1, .L080BA498
	ldrh r0, [r1, #0x12]
	ldrh r1, [r1, #0x14]
	mov r5, sp
	adds r5, #2
	mov r2, sp
	adds r3, r5, #0
	bl sub_080C1F50
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #0x40
	bne .L080BA49C
	ldrh r0, [r5]
	cmp r0, #0xc
	bne .L080BA49C
	mov r0, r8
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	movs r0, #0xa8
	b .L080BA4B2
	.byte 0x00, 0x00
.L080BA494: .4byte 0x03004614 @ IWRAM+0x4614
.L080BA498: .4byte 0x03004550 @ IWRAM+0x4550
.L080BA49C:
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble .L080BA4AE
	subs r0, r1, r0
	b .L080BA4B0
.L080BA4AE:
	subs r0, r0, r1
.L080BA4B0:
	movs r1, #0xa8
.L080BA4B2:
	muls r0, r1, r0
	strh r0, [r7, #0x3a]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BA4C4
sub_080BA4C4: @ 0x080BA4C4
.L080BA4C4:
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r5, #0x24
	ldr r1, .L080BA514
	ldrh r0, [r1, #0x12]
	ldrh r1, [r1, #0x14]
	mov r4, sp
	adds r4, #2
	mov r2, sp
	adds r3, r4, #0
	bl sub_080C1F50
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #0x40
	bne .L080BA4EC
	ldrh r0, [r4]
	cmp r0, #0xc
	beq .L080BA4FE
.L080BA4EC:
	ldr r0, [r5, #8]
	lsls r0, r0, #1
	adds r1, r5, #0
	adds r1, #0x20
	adds r1, r1, r0
	ldr r0, [r5, #0xc]
	ldrh r1, [r1]
	cmp r0, r1
	bhs .L080BA51C
.L080BA4FE:
	ldr r4, .L080BA518
	ldrh r0, [r5, #0x38]
	movs r1, #0xa8
	bl __umodsi3
	movs r1, #0xff
	ands r0, r1
	movs r1, #0xa8
	subs r1, r1, r0
	strh r1, [r4]
	b .L080BA52C
.L080BA514: .4byte 0x03004550 @ IWRAM+0x4550
.L080BA518: .4byte 0x0300000E @ IWRAM+0xE
.L080BA51C:
	ldr r4, .L080BA534
	ldrh r0, [r5, #0x38]
	movs r1, #0xa8
	bl __umodsi3
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4]
.L080BA52C:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BA534: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080BA538
sub_080BA538: @ 0x080BA538
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r0, [r1, #0x34]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r0, r3
	str r0, [r1, #0x34]
	lsrs r0, r0, #0x10
	cmp r0, #8
	bls .L080BA558
	movs r0, #1
	strh r0, [r2, #0x1c]
.L080BA558:
	ldrh r0, [r1, #0x38]
	ldrh r3, [r1, #0x36]
	adds r0, r0, r3
	strh r0, [r1, #0x38]
	adds r0, r2, #0
	bl sub_080BA4C4
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BA56C
sub_080BA56C: @ 0x080BA56C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	movs r0, #0
	strh r0, [r5, #0x1c]
	ldrh r0, [r4, #0x38]
	ldrh r1, [r4, #0x36]
	adds r0, r0, r1
	strh r0, [r4, #0x38]
	adds r0, r5, #0
	bl sub_080BA4C4
	ldrh r2, [r4, #0x38]
	ldrh r0, [r4, #0x3a]
	lsrs r1, r0, #4
	subs r0, r0, r1
	cmp r2, r0
	ble .L080BA596
	movs r0, #1
	strh r0, [r5, #0x1c]
.L080BA596:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080BA59C
sub_080BA59C: @ 0x080BA59C
	push {r4, lr}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0x24
	movs r0, #0
	strh r0, [r3, #0x1c]
	ldr r1, [r2, #0x34]
	lsrs r0, r1, #0x10
	cmp r0, #2
	bls .L080BA5B6
	ldr r4, .L080BA5DC
	adds r0, r1, r4
	str r0, [r2, #0x34]
.L080BA5B6:
	ldrh r1, [r2, #0x36]
	ldrh r0, [r2, #0x38]
	adds r0, r0, r1
	strh r0, [r2, #0x38]
	ldrh r1, [r2, #0x3a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls .L080BA5CE
	strh r1, [r2, #0x38]
	movs r0, #1
	strh r0, [r3, #0x1c]
.L080BA5CE:
	adds r0, r3, #0
	bl sub_080BA4C4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BA5DC: .4byte 0xFFFFF000

	thumb_func_start sub_080BA5E0
sub_080BA5E0: @ 0x080BA5E0
.L080BA5E0:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r0, .L080BA600
	ldrh r2, [r0, #0x12]
	ldrh r3, [r0, #0x14]
	ldrh r0, [r0, #2]
	cmp r0, #1
	beq .L080BA628
	cmp r0, #1
	bgt .L080BA604
	cmp r0, #0
	beq .L080BA60E
	b .L080BA684
.L080BA600: .4byte 0x03004550 @ IWRAM+0x4550
.L080BA604:
	cmp r0, #2
	beq .L080BA646
	cmp r0, #3
	beq .L080BA664
	b .L080BA684
.L080BA60E:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r1
	b .L080BA680
.L080BA628:
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	bgt .L080BA698
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r4
	b .L080BA680
.L080BA646:
	lsls r0, r5, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L080BA698
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	subs r0, r0, r5
	b .L080BA680
.L080BA664:
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L080BA698
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	subs r0, r0, r4
.L080BA680:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L080BA684:
	lsls r4, r2, #0x10
	lsrs r0, r4, #0x10
	cmp r0, #2
	bhi .L080BA698
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L080BA698
	cmp r1, #0xc
	ble .L080BA69C
.L080BA698:
	movs r0, #0
	b .L080BA6A8
.L080BA69C:
	ldr r2, .L080BA6B0
	asrs r0, r4, #0xf
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0]
.L080BA6A8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080BA6B0: .4byte gUnknown_0817417C

	thumb_func_start sub_080BA6B4
sub_080BA6B4: @ 0x080BA6B4
.L080BA6B4:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, .L080BA6CC
	cmp r0, #0
	beq .L080BA6C4
	cmp r0, #3
	bne .L080BA6D8
.L080BA6C4:
	ldr r4, .L080BA6D0
	ldr r2, .L080BA6D4
	b .L080BA702
	.byte 0x00, 0x00
.L080BA6CC: .4byte 0x03003BC1 @ IWRAM+0x3BC1
.L080BA6D0: .4byte gUnknown_08173D04
.L080BA6D4: .4byte 0x03004550 @ IWRAM+0x4550
.L080BA6D8:
	cmp r0, #1
	bne .L080BA6EC
	ldr r4, .L080BA6E4
	ldr r2, .L080BA6E8
	b .L080BA702
	.byte 0x00, 0x00
.L080BA6E4: .4byte gUnknown_08173FBC
.L080BA6E8: .4byte 0x03004550 @ IWRAM+0x4550
.L080BA6EC:
	ldr r2, .L080BA720
	cmp r0, #2
	bne .L080BA702
	movs r0, #8
	ldrsh r1, [r2, r0]
	movs r0, #1
	rsbs r0, r0, #0
	ldr r4, .L080BA724
	cmp r1, r0
	bne .L080BA702
	ldr r4, .L080BA728
.L080BA702:
	ldrh r1, [r2, #0xe]
	lsls r0, r1, #3
	subs r0, #8
	adds r4, r4, r0
	ldr r0, [r4]
	cmp r0, #0
	bne .L080BA730
	strh r0, [r2, #0xe]
	ldr r0, .L080BA72C
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #1
	b .L080BA750
	.byte 0x00, 0x00
.L080BA720: .4byte 0x03004550 @ IWRAM+0x4550
.L080BA724: .4byte gUnknown_08174144
.L080BA728: .4byte gUnknown_0817410C
.L080BA72C: .4byte sub_080B2880
.L080BA730:
	adds r0, r1, #1
	strh r0, [r2, #0xe]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r2, #6
	ldrsh r1, [r4, r2]
	bl sub_080BA5E0
	cmp r0, #0
	beq .L080BA74E
	ldr r0, [r4]
	bl _call_via_r5
	movs r0, #1
	b .L080BA750
.L080BA74E:
	movs r0, #0
.L080BA750:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080BA758
sub_080BA758: @ 0x080BA758
	ldr r0, .L080BA780
	ldr r1, .L080BA784
	str r0, [r1]
	ldr r0, .L080BA788
	ldr r0, [r0]
	lsls r0, r0, #5
	ldr r2, .L080BA78C
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, .L080BA790
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080BA794
	str r0, [r1]
	ldr r0, .L080BA798
	str r0, [r1, #4]
	ldr r0, .L080BA79C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L080BA780: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080BA784: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BA788: .4byte 0x03004638 @ IWRAM+0x4638
.L080BA78C: .4byte 0x06004000 @ VRAM+0x4000
.L080BA790: .4byte 0x840000E0
.L080BA794: .4byte 0x02000000 @ EWRAM
.L080BA798: .4byte 0x06003800 @ VRAM+0x3800
.L080BA79C: .4byte 0x84000200

	thumb_func_start sub_080BA7A0
sub_080BA7A0: @ 0x080BA7A0
.L080BA7A0:
	push {lr}
	cmp r0, #0
	bne .L080BA7B8
	ldr r0, .L080BA7B0
	ldr r1, .L080BA7B4
	bl LZ77UnCompWram
	b .L080BA7C0
.L080BA7B0: .4byte gUnknown_08182270
.L080BA7B4: .4byte 0x02000000 @ EWRAM
.L080BA7B8:
	ldr r0, .L080BA7C4
	ldr r1, .L080BA7C8
	bl LZ77UnCompWram
.L080BA7C0:
	pop {r0}
	bx r0
.L080BA7C4: .4byte gUnknown_08182688
.L080BA7C8: .4byte 0x02000000 @ EWRAM

	thumb_func_start sub_080BA7CC
sub_080BA7CC: @ 0x080BA7CC
.L080BA7CC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, .L080BA844
	ldrh r0, [r0]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x13
	subs r3, r3, r4
	subs r3, #1
	lsls r3, r3, #0x10
	ldr r0, .L080BA848
	mov r8, r0
	lsrs r1, r3, #0x10
	cmp r3, #0
	bge .L080BA7F8
	movs r1, #0
.L080BA7F8:
	lsls r0, r1, #2
	adds r0, r0, r5
	ldr r0, [r0]
	muls r1, r7, r1
	adds r5, r6, r1
	ldr r1, .L080BA84C
	bl LZ77UnCompWram
	movs r0, #0x1f
	subs r1, r0, r4
	ldr r0, [sp, #0x20]
	cmp r0, #0
	bne .L080BA854
	movs r6, #0
	mov sb, r4
	ldr r3, .L080BA850
	mov sl, r3
	cmp r6, r7
	bhs .L080BA8A0
	movs r2, #0xf
	lsls r1, r1, #6
	mov r0, r8
	adds r0, #2
	adds r1, r1, r0
.L080BA828:
	ldrb r0, [r5]
	adds r5, #1
	ands r0, r2
	adds r0, #8
	lsls r0, r0, #0xc
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r1, #2
	adds r6, #1
	cmp r6, r7
	blo .L080BA828
	b .L080BA8A0
	.byte 0x00, 0x00
.L080BA844: .4byte 0x0300000E @ IWRAM+0xE
.L080BA848: .4byte 0x02000000 @ EWRAM
.L080BA84C: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080BA850: .4byte sub_080BA758
.L080BA854:
	movs r6, #0
	mov sb, r4
	ldr r0, .L080BA8C8
	mov sl, r0
	cmp r6, r7
	bhs .L080BA8A0
	ldr r3, .L080BA8CC
	mov ip, r3
	lsls r0, r1, #5
	adds r0, #0x1c
	lsls r2, r1, #6
	mov r1, r8
	adds r1, #2
	adds r4, r2, r1
	lsls r0, r0, #1
	mov r1, r8
	adds r3, r0, r1
.L080BA876:
	ldrb r1, [r5]
	adds r5, #1
	movs r0, #0xf
	ands r1, r0
	adds r1, #8
	ldrh r2, [r4]
	mov r0, ip
	ands r0, r2
	lsls r1, r1, #0xc
	adds r0, r0, r1
	strh r0, [r4]
	ldrh r2, [r3]
	mov r0, ip
	ands r0, r2
	adds r0, r0, r1
	strh r0, [r3]
	subs r3, #2
	adds r4, #2
	adds r6, #1
	cmp r6, r7
	blo .L080BA876
.L080BA8A0:
	movs r0, #0x1f
	mov r3, sb
	subs r0, r0, r3
	lsls r0, r0, #2
	ldr r1, .L080BA8D0
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, .L080BA8D4
	str r0, [r3]
	mov r0, sl
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080BA8C8: .4byte sub_080BA758
.L080BA8CC: .4byte 0x00000FFF
.L080BA8D0: .4byte gUnknown_08182AA0
.L080BA8D4: .4byte 0x03004638 @ IWRAM+0x4638

	thumb_func_start sub_080BA8D8
sub_080BA8D8: @ 0x080BA8D8
.L080BA8D8:
	push {lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r0, #0
	bne .L080BA8EC
	ldr r1, .L080BA8E8
	b .L080BA8EE
.L080BA8E8: .4byte gUnknown_08182B20
.L080BA8EC:
	ldr r1, .L080BA908
.L080BA8EE:
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq .L080BA914
	ldr r1, .L080BA90C
	adds r0, r2, #0
	bl Task_Create
	ldr r1, .L080BA910
	str r0, [r1]
	b .L080BA918
	.byte 0x00, 0x00
.L080BA908: .4byte gUnknown_08182B54
.L080BA90C: .4byte 0x0000FFFF
.L080BA910: .4byte 0x0300463C @ IWRAM+0x463C
.L080BA914:
	ldr r0, .L080BA91C
	str r2, [r0]
.L080BA918:
	pop {r0}
	bx r0
.L080BA91C: .4byte 0x0300463C @ IWRAM+0x463C

	thumb_func_start sub_080BA920
sub_080BA920: @ 0x080BA920
.L080BA920:
	push {lr}
	movs r1, #0
	ldr r0, .L080BA93C
	ldr r0, [r0]
	cmp r0, #0
	beq .L080BA932
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080BA934
.L080BA932:
	movs r1, #1
.L080BA934:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080BA93C: .4byte 0x0300463C @ IWRAM+0x463C

	thumb_func_start sub_080BA940
sub_080BA940: @ 0x080BA940
.L080BA940:
	push {lr}
	ldr r2, .L080BA954
	ldr r1, [r2]
	cmp r1, #0
	beq .L080BA950
	movs r0, #0
	strh r0, [r1]
	str r0, [r2]
.L080BA950:
	pop {r0}
	bx r0
.L080BA954: .4byte 0x0300463C @ IWRAM+0x463C

	thumb_func_start sub_080BA958
sub_080BA958: @ 0x080BA958
.L080BA958:
	push {lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r0, #0
	bne .L080BA988
	cmp r1, #2
	bne .L080BA988
	ldr r0, .L080BA990
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L080BA97E
	ldr r0, .L080BA994
	movs r1, #1
	bl VBlankTask_AddCounted
.L080BA97E:
	ldr r0, .L080BA998
	ldr r0, [r0]
	ldr r1, .L080BA99C
	ldrh r0, [r0, #0x24]
	strh r0, [r1]
.L080BA988:
	bl sub_080BA940
	pop {r0}
	bx r0
.L080BA990: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080BA994: .4byte sub_080B2880
.L080BA998: .4byte 0x0300463C @ IWRAM+0x463C
.L080BA99C: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080BA9A0
sub_080BA9A0: @ 0x080BA9A0
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x1c
	bl sub_080B6DB4
	str r0, [r4, #0x24]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BA9B4
sub_080BA9B4: @ 0x080BA9B4
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x24]
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080BA9C4
	movs r0, #0
	b .L080BA9C6
.L080BA9C4:
	movs r0, #1
.L080BA9C6:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080BA9CC
sub_080BA9CC: @ 0x080BA9CC
	ldr r1, .L080BA9E0
	ldr r0, .L080BA9E4
	str r0, [r1]
	ldr r0, .L080BA9E8
	str r0, [r1, #4]
	ldr r0, .L080BA9EC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BA9E0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BA9E4: .4byte 0x02001000 @ EWRAM+0x1000
.L080BA9E8: .4byte 0x0600E000 @ VRAM+0xE000
.L080BA9EC: .4byte 0x84000300

	thumb_func_start sub_080BA9F0
sub_080BA9F0: @ 0x080BA9F0
.L080BA9F0:
	push {lr}
	ldr r0, .L080BAA08
	ldr r1, .L080BAA0C
	bl LZ77UnCompWram
	ldr r0, .L080BAA10
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BAA08: .4byte gUnknown_08182F4C
.L080BAA0C: .4byte 0x02001000 @ EWRAM+0x1000
.L080BAA10: .4byte sub_080BA9CC

	thumb_func_start sub_080BAA14
sub_080BAA14: @ 0x080BAA14
.L080BAA14:
	push {lr}
	ldr r0, .L080BAA2C
	ldr r1, .L080BAA30
	bl LZ77UnCompWram
	ldr r0, .L080BAA34
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BAA2C: .4byte gUnknown_081831B4
.L080BAA30: .4byte 0x02001000 @ EWRAM+0x1000
.L080BAA34: .4byte sub_080BA9CC

	thumb_func_start sub_080BAA38
sub_080BAA38: @ 0x080BAA38
	ldr r1, .L080BAA4C
	ldr r0, .L080BAA50
	str r0, [r1]
	ldr r0, .L080BAA54
	str r0, [r1, #4]
	ldr r0, .L080BAA58
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BAA4C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BAA50: .4byte 0x02000000 @ EWRAM
.L080BAA54: .4byte 0x06001000 @ VRAM+0x1000
.L080BAA58: .4byte 0x84000400

	thumb_func_start sub_080BAA5C
sub_080BAA5C: @ 0x080BAA5C
	push {r4, lr}
	sub sp, #4
	movs r4, #0
	str r4, [sp]
	ldr r1, .L080BAA90
	ldr r2, .L080BAA94
	mov r0, sp
	bl CpuSet
	ldr r0, .L080BAA98
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080BAA9C
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080BAAA0
	strb r1, [r0]
	ldr r0, .L080BAAA4
	strb r1, [r0]
	ldr r0, .L080BAAA8
	strh r4, [r0]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080BAA90: .4byte 0x02000000 @ EWRAM
.L080BAA94: .4byte 0x05000400
.L080BAA98: .4byte sub_080BAA38
.L080BAA9C: .4byte 0x03000038 @ IWRAM+0x38
.L080BAAA0: .4byte 0x03000039 @ IWRAM+0x39
.L080BAAA4: .4byte 0x0300003A @ IWRAM+0x3A
.L080BAAA8: .4byte 0x03000006 @ IWRAM+0x6

	thumb_func_start sub_080BAAAC
sub_080BAAAC: @ 0x080BAAAC
	push {r4, r5, lr}
	sub sp, #0x10
	ldr r0, .L080BAB24
	ldr r5, .L080BAB28
	adds r1, r5, #0
	bl LZ77UnCompWram
	ldr r1, .L080BAB2C
	movs r2, #0xc0
	lsls r2, r2, #2
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r4, #0x20
	str r4, [sp, #8]
	movs r0, #0x40
	str r0, [sp, #0xc]
	adds r0, r5, #0
	movs r3, #7
	bl Tilemap_CopyRectSkipZero
	ldr r1, .L080BAB30
	ldr r2, .L080BAB34
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0x70
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
	ldr r0, .L080BAB38
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080BAB3C
	movs r0, #0x78
	strh r0, [r1]
	ldr r1, .L080BAB40
	movs r0, #0xe8
	strb r0, [r1]
	ldr r1, .L080BAB44
	movs r0, #8
	strb r0, [r1]
	ldr r1, .L080BAB48
	movs r0, #0xe0
	strb r0, [r1]
	ldr r1, .L080BAB4C
	movs r0, #0x68
	strb r0, [r1]
	ldr r1, .L080BAB50
	movs r0, #0x3d
	strb r0, [r1]
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BAB24: .4byte gUnknown_08183474
.L080BAB28: .4byte 0x0200BFC8 @ EWRAM+0xBFC8
.L080BAB2C: .4byte 0x02000000 @ EWRAM
.L080BAB30: .4byte gUnknown_08183454
.L080BAB34: .4byte 0x03002A90 @ IWRAM+0x2A90
.L080BAB38: .4byte sub_080BAA38
.L080BAB3C: .4byte 0x03000006 @ IWRAM+0x6
.L080BAB40: .4byte 0x03000030 @ IWRAM+0x30
.L080BAB44: .4byte 0x03000031 @ IWRAM+0x31
.L080BAB48: .4byte 0x03000034 @ IWRAM+0x34
.L080BAB4C: .4byte 0x03000035 @ IWRAM+0x35
.L080BAB50: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080BAB54
sub_080BAB54: @ 0x080BAB54
	push {lr}
	adds r3, r0, #0
	ldr r2, .L080BAB78
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r0, .L080BAB7C
	ldr r0, [r0]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080BAB80
	adds r0, r3, #0
	bl sub_080BA9F0
	b .L080BAB86
	.byte 0x00, 0x00
.L080BAB78: .4byte 0x03000006 @ IWRAM+0x6
.L080BAB7C: .4byte 0x030031BC @ IWRAM+0x31BC
.L080BAB80:
	adds r0, r3, #0
	bl sub_080BAA14
.L080BAB86:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BAB8C
sub_080BAB8C: @ 0x080BAB8C
	ldr r0, .L080BAB94
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080BAB94: .4byte 0x03000006 @ IWRAM+0x6

	thumb_func_start sub_080BAB98
sub_080BAB98: @ 0x080BAB98
	ldr r1, .L080BABAC
	ldr r0, .L080BABB0
	str r0, [r1]
	ldr r0, .L080BABB4
	str r0, [r1, #4]
	ldr r0, .L080BABB8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BABAC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BABB0: .4byte 0x02001000 @ EWRAM+0x1000
.L080BABB4: .4byte 0x06015000 @ VRAM+0x15000
.L080BABB8: .4byte 0x84000200

	thumb_func_start sub_080BABBC
sub_080BABBC: @ 0x080BABBC
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, .L080BAC08
	ldr r1, .L080BAC0C
	bl LZ77UnCompWram
	ldr r5, .L080BAC10
	adds r0, r5, #0
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080BAC14
	ldr r2, .L080BAC18
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
	adds r0, r5, #0
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0x30
	strh r0, [r4, #4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BAC08: .4byte gUnknown_08182CC4
.L080BAC0C: .4byte 0x02001000 @ EWRAM+0x1000
.L080BAC10: .4byte sub_080BAB98
.L080BAC14: .4byte gUnknown_08183434
.L080BAC18: .4byte 0x03002D50 @ IWRAM+0x2D50

	thumb_func_start sub_080BAC1C
sub_080BAC1C: @ 0x080BAC1C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r6, #0x24
	ldr r0, .L080BAC6C
	ldr r0, [r0]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080BAC74
	ldr r5, .L080BAC70
	movs r4, #0xa0
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0x40
	str r0, [sp, #4]
	ldrh r0, [r6, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
	str r4, [sp]
	movs r0, #0xb4
	str r0, [sp, #4]
	ldrh r0, [r6, #4]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
	b .L080BACAC
.L080BAC6C: .4byte 0x030031BC @ IWRAM+0x31BC
.L080BAC70: .4byte gUnknown_0800781C
.L080BAC74:
	ldr r5, .L080BACB4
	movs r4, #0xa0
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0x40
	str r0, [sp, #4]
	ldrh r0, [r6, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
	str r4, [sp]
	movs r0, #0xb4
	str r0, [sp, #4]
	ldrh r0, [r6, #4]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xd
	movs r3, #3
	bl Sprite_Draw
.L080BACAC:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BACB4: .4byte gUnknown_08007844

	thumb_func_start sub_080BACB8
sub_080BACB8: @ 0x080BACB8
	adds r0, #0x24
	ldrh r2, [r0, #4]
	adds r2, r2, r1
	strh r2, [r0, #4]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080BACC4
sub_080BACC4: @ 0x080BACC4
	ldr r1, .L080BACD0
	ldr r2, .L080BACD4
	adds r0, r2, #0
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080BACD0: .4byte 0x0400000A @ REG_BG1CNT
.L080BACD4: .4byte 0x00004209

	thumb_func_start sub_080BACD8
sub_080BACD8: @ 0x080BACD8
	push {lr}
	ldr r1, .L080BAD0C
	movs r0, #8
	strb r0, [r1]
	ldr r0, .L080BAD10
	movs r2, #0
	strb r2, [r0]
	ldr r1, .L080BAD14
	movs r0, #0x68
	strb r0, [r1]
	ldr r0, .L080BAD18
	strb r2, [r0]
	ldr r1, .L080BAD1C
	movs r0, #0x3d
	strb r0, [r1]
	ldr r0, .L080BAD20
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080BAD24
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BAD0C: .4byte 0x03000030 @ IWRAM+0x30
.L080BAD10: .4byte 0x03000031 @ IWRAM+0x31
.L080BAD14: .4byte 0x03000034 @ IWRAM+0x34
.L080BAD18: .4byte 0x03000035 @ IWRAM+0x35
.L080BAD1C: .4byte 0x03000038 @ IWRAM+0x38
.L080BAD20: .4byte sub_080BACC4
.L080BAD24: .4byte 0x03000004 @ IWRAM+0x4

	thumb_func_start sub_080BAD28
sub_080BAD28: @ 0x080BAD28
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080BAD4C
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080BAD50
	str r0, [r1, #4]
	ldr r0, .L080BAD54
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xca
	ldr r2, .L080BAD58
	adds r0, r2, #0
	strh r0, [r1]
	add sp, #4
	bx lr
	.byte 0x00, 0x00
.L080BAD4C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BAD50: .4byte 0x06001000 @ VRAM+0x1000
.L080BAD54: .4byte 0x85000200
.L080BAD58: .4byte 0x00008209

	thumb_func_start sub_080BAD5C
sub_080BAD5C: @ 0x080BAD5C
	push {lr}
	cmp r1, #0
	bne .L080BAD70
	ldr r0, .L080BAD6C
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080BAD7C
.L080BAD6C: .4byte sub_080BAD28
.L080BAD70:
	ldr r1, .L080BAD80
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080BAD84
	movs r0, #0x3f
	strb r0, [r1]
.L080BAD7C:
	pop {r0}
	bx r0
.L080BAD80: .4byte 0x03000004 @ IWRAM+0x4
.L080BAD84: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080BAD88
sub_080BAD88: @ 0x080BAD88
.L080BAD88:
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r5, r2, #0
	adds r4, r3, #0
	movs r3, #0
	ldr r2, .L080BADC0
.L080BAD94:
	ldr r0, [r2]
	cmp r0, #0
	beq .L080BADB0
	adds r1, r0, #0
	adds r1, #0x24
	ldrh r0, [r1, #6]
	cmp r0, r6
	bne .L080BADB0
	ldrh r0, [r1, #8]
	adds r0, r0, r5
	strh r0, [r1, #8]
	ldrh r0, [r1, #0xa]
	adds r0, r0, r4
	strh r0, [r1, #0xa]
.L080BADB0:
	adds r2, #4
	adds r3, #1
	cmp r3, #7
	bls .L080BAD94
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BADC0: .4byte 0x02036094 @ EWRAM+0x36094

	thumb_func_start sub_080BADC4
sub_080BADC4: @ 0x080BADC4
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, .L080BADF0
	ldr r4, .L080BADF4
.L080BADCC:
	ldr r1, [r4]
	cmp r1, #0
	beq .L080BADE0
	ldrh r0, [r1, #0x2a]
	cmp r0, r6
	bne .L080BADE0
	adds r0, r1, #0
	movs r1, #0
	bl sub_080C48F0
.L080BADE0:
	adds r4, #4
	adds r5, #1
	cmp r5, #7
	bls .L080BADCC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BADF0: .4byte 0x00000157
.L080BADF4: .4byte 0x02036094 @ EWRAM+0x36094

	thumb_func_start sub_080BADF8
sub_080BADF8: @ 0x080BADF8
	push {lr}
	ldr r0, .L080BAE08
	ldr r0, [r0]
	cmp r0, #0
	beq .L080BAE04
	strh r1, [r0, #0x1e]
.L080BAE04:
	pop {r0}
	bx r0
.L080BAE08: .4byte 0x02036094 @ EWRAM+0x36094

	thumb_func_start sub_080BAE0C
sub_080BAE0C: @ 0x080BAE0C
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080BAE1C
	ldr r0, [r0]
	cmp r0, #0
	bne .L080BAE20
	movs r0, #1
	b .L080BAE22
.L080BAE1C: .4byte 0x02036094 @ EWRAM+0x36094
.L080BAE20:
	movs r0, #0
.L080BAE22:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080BAE28
sub_080BAE28: @ 0x080BAE28
	push {r4, lr}
	ldr r4, .L080BAE44
	ldr r0, [r4]
	movs r1, #1
	bl Window_Close
	movs r1, #0
	str r1, [r4]
	ldr r0, .L080BAE48
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BAE44: .4byte 0x03006968 @ IWRAM+0x6968
.L080BAE48: .4byte 0x0203DB6C @ EWRAM+0x3DB6C

	thumb_func_start sub_080BAE4C
sub_080BAE4C: @ 0x080BAE4C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	bl sub_080B6DB4
	str r0, [r4, #0x24]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BAE60
sub_080BAE60: @ 0x080BAE60
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x24]
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080BAE70
	movs r0, #0
	b .L080BAE72
.L080BAE70:
	movs r0, #1
.L080BAE72:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080BAE78
sub_080BAE78: @ 0x080BAE78
	push {r4, lr}
	sub sp, #8
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r3, [sp, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	bl sub_080C4618
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BAEA8
sub_080BAEA8: @ 0x080BAEA8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xc8
	lsls r0, r0, #1
	bl sub_080BC230
	ldr r1, [r0, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080BAEC2
	movs r0, #1
	b .L080BAEC4
.L080BAEC2:
	movs r0, #0
.L080BAEC4:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080BAECC
sub_080BAECC: @ 0x080BAECC
	ldr r1, .L080BAEE0
	ldr r0, .L080BAEE4
	str r0, [r1]
	ldr r0, .L080BAEE8
	str r0, [r1, #4]
	ldr r0, .L080BAEEC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BAEE0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BAEE4: .4byte 0x02001000 @ EWRAM+0x1000
.L080BAEE8: .4byte 0x06013000 @ VRAM+0x13000
.L080BAEEC: .4byte 0x84000700

	thumb_func_start sub_080BAEF0
sub_080BAEF0: @ 0x080BAEF0
	push {r4, lr}
	sub sp, #4
	ldr r0, .L080BAF2C
	ldr r4, .L080BAF30
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080BAF34
	movs r1, #0x80
	lsls r1, r1, #5
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	bl Palette_IsBg13Black
	cmp r0, #0
	bne .L080BAF40
	ldr r1, .L080BAF38
	ldr r2, .L080BAF3C
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	b .L080BAF5E
	.byte 0x00, 0x00
.L080BAF2C: .4byte gUnknown_081839F4
.L080BAF30: .4byte 0x02001000 @ EWRAM+0x1000
.L080BAF34: .4byte gUnknown_081845E4
.L080BAF38: .4byte gUnknown_08184BA4
.L080BAF3C: .4byte 0x03003190 @ IWRAM+0x3190
.L080BAF40:
	ldr r1, .L080BAF70
	ldr r2, .L080BAF74
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xf8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
.L080BAF5E:
	ldr r0, .L080BAF78
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BAF70: .4byte gUnknown_08184BA4
.L080BAF74: .4byte 0x03002D90 @ IWRAM+0x2D90
.L080BAF78: .4byte sub_080BAECC

	thumb_func_start sub_080BAF7C
sub_080BAF7C: @ 0x080BAF7C
	ldr r1, .L080BAF9C
	ldr r0, .L080BAFA0
	str r0, [r1]
	ldr r0, .L080BAFA4
	str r0, [r1, #4]
	ldr r0, .L080BAFA8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080BAFAC
	str r0, [r1]
	ldr r0, .L080BAFB0
	str r0, [r1, #4]
	ldr r0, .L080BAFB4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L080BAF9C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BAFA0: .4byte 0x02001000 @ EWRAM+0x1000
.L080BAFA4: .4byte 0x0600E000 @ VRAM+0xE000
.L080BAFA8: .4byte 0x84000800
.L080BAFAC: .4byte 0x02000000 @ EWRAM
.L080BAFB0: .4byte 0x06001000 @ VRAM+0x1000
.L080BAFB4: .4byte 0x84000400

	thumb_func_start sub_080BAFB8
sub_080BAFB8: @ 0x080BAFB8
	push {r4, r5, r6, lr}
	sub sp, #0x14
	cmp r1, #1
	beq .L080BAFE0
	cmp r1, #1
	blo .L080BAFCE
	cmp r1, #2
	beq .L080BAFF4
	cmp r1, #3
	beq .L080BB044
	b .L080BB070
.L080BAFCE:
	ldr r0, .L080BAFD8
	ldr r1, .L080BAFDC
	bl LZ77UnCompWram
	b .L080BB070
.L080BAFD8: .4byte gUnknown_08184BC4
.L080BAFDC: .4byte 0x02001000 @ EWRAM+0x1000
.L080BAFE0:
	ldr r0, .L080BAFEC
	ldr r1, .L080BAFF0
	bl LZ77UnCompWram
	b .L080BB070
	.byte 0x00, 0x00
.L080BAFEC: .4byte gUnknown_0818596C
.L080BAFF0: .4byte 0x02002000 @ EWRAM+0x2000
.L080BAFF4:
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r1, .L080BB030
	add r0, sp, #0x10
	str r0, [r1]
	ldr r6, .L080BB034
	str r6, [r1, #4]
	ldr r0, .L080BB038
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080BB03C
	ldr r5, .L080BB040
	adds r1, r5, #0
	bl LZ77UnCompWram
	movs r2, #0xc0
	lsls r2, r2, #2
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	str r0, [sp, #8]
	movs r0, #0x24
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r3, #7
	bl Tilemap_CopyRectSkipZero
	b .L080BB070
	.byte 0x00, 0x00
.L080BB030: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BB034: .4byte 0x02000000 @ EWRAM
.L080BB038: .4byte 0x85000400
.L080BB03C: .4byte gUnknown_08186524
.L080BB040: .4byte 0x0200BFC8 @ EWRAM+0xBFC8
.L080BB044:
	ldr r0, .L080BB078
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080BB07C
	movs r0, #0xa8
	strh r0, [r1]
	ldr r1, .L080BB080
	movs r0, #0xe8
	strb r0, [r1]
	ldr r1, .L080BB084
	movs r0, #8
	strb r0, [r1]
	ldr r1, .L080BB088
	movs r0, #0xe0
	strb r0, [r1]
	ldr r1, .L080BB08C
	movs r0, #0x68
	strb r0, [r1]
	ldr r1, .L080BB090
	movs r0, #0x3d
	strb r0, [r1]
.L080BB070:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BB078: .4byte sub_080BAF7C
.L080BB07C: .4byte 0x03000006 @ IWRAM+0x6
.L080BB080: .4byte 0x03000030 @ IWRAM+0x30
.L080BB084: .4byte 0x03000031 @ IWRAM+0x31
.L080BB088: .4byte 0x03000034 @ IWRAM+0x34
.L080BB08C: .4byte 0x03000035 @ IWRAM+0x35
.L080BB090: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080BB094
sub_080BB094: @ 0x080BB094
	push {lr}
	cmp r1, #0
	bne .L080BB0A0
	bl sub_080C7C60
	b .L080BB0D2
.L080BB0A0:
	cmp r1, #1
	bne .L080BB0C0
	ldr r1, .L080BB0B4
	movs r2, #0xf1
	lsls r2, r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080BB0B8
	ldr r2, .L080BB0BC
	b .L080BB0CE
.L080BB0B4: .4byte 0x03000040 @ IWRAM+0x40
.L080BB0B8: .4byte 0x0400000A @ REG_BG1CNT
.L080BB0BC: .4byte 0x0000820B
.L080BB0C0:
	bl sub_080C1440
	ldr r1, .L080BB0D8
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080BB0DC
	ldr r2, .L080BB0E0
.L080BB0CE:
	adds r0, r2, #0
	strh r0, [r1]
.L080BB0D2:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BB0D8: .4byte 0x03000006 @ IWRAM+0x6
.L080BB0DC: .4byte 0x0400000A @ REG_BG1CNT
.L080BB0E0: .4byte 0x00008209

	thumb_func_start sub_080BB0E4
sub_080BB0E4: @ 0x080BB0E4
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0x24
	movs r0, #0
	strh r0, [r3, #0x1c]
	ldr r2, .L080BB10C
	ldr r0, [r2]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne .L080BB118
	ldr r1, .L080BB110
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080BB114
	subs r0, #1
	strh r0, [r1]
	b .L080BB118
	.byte 0x00, 0x00
.L080BB10C: .4byte 0x030031BC @ IWRAM+0x31BC
.L080BB110: .4byte 0x0300000E @ IWRAM+0xE
.L080BB114:
	movs r0, #1
	strh r0, [r3, #0x1c]
.L080BB118:
	ldrh r0, [r3, #0x1c]
	cmp r0, #0
	bne .L080BB140
	ldr r2, [r2]
	movs r0, #3
	ands r2, r0
	cmp r2, #0
	bne .L080BB140
	ldr r1, .L080BB148
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x38
	bls .L080BB140
	str r2, [r3, #0x20]
.L080BB140:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BB148: .4byte 0x03000006 @ IWRAM+0x6

	thumb_func_start sub_080BB14C
sub_080BB14C: @ 0x080BB14C
	push {lr}
	movs r0, #0xb1
	lsls r0, r0, #1
	bl sub_080BC230
	adds r0, #0x24
	ldrh r1, [r0, #0xa]
	subs r1, #1
	strh r1, [r0, #0xa]
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BB164
sub_080BB164: @ 0x080BB164
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #0xb1
	lsls r0, r0, #1
	bl sub_080BC230
	adds r5, r4, #0
	adds r5, #0x24
	ldr r0, .L080BB1D0
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L080BB1C6
	movs r4, #0
	ldr r1, .L080BB1D4
	ldr r0, [r1]
	cmp r0, #0
	beq .L080BB1A0
.L080BB18C:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #5
	bhi .L080BB1A0
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne .L080BB18C
.L080BB1A0:
	cmp r4, #6
	beq .L080BB1C6
	bl sub_080C2244
	adds r2, r0, #0
	adds r2, #0x40
	movs r0, #0x7f
	ands r2, r0
	ldr r1, .L080BB1D8
	ldrh r3, [r5, #4]
	adds r3, #0xe
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	bl sub_080C4618
.L080BB1C6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BB1D0: .4byte 0x030031BC @ IWRAM+0x31BC
.L080BB1D4: .4byte 0x02036094 @ EWRAM+0x36094
.L080BB1D8: .4byte 0x00000177

	thumb_func_start sub_080BB1DC
sub_080BB1DC: @ 0x080BB1DC
	push {lr}
	movs r0, #0xf0
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BB1F0
sub_080BB1F0: @ 0x080BB1F0
	ldr r1, .L080BB200
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080BB204
	ldr r2, .L080BB208
	adds r0, r2, #0
	strh r0, [r1]
	bx lr
.L080BB200: .4byte 0x0300000E @ IWRAM+0xE
.L080BB204: .4byte 0x03000006 @ IWRAM+0x6
.L080BB208: .4byte 0x0000FFD8

	thumb_func_start sub_080BB20C
sub_080BB20C: @ 0x080BB20C
	adds r0, #0x24
	movs r1, #0x73
	strh r1, [r0, #4]
	movs r1, #6
	strh r1, [r0, #6]
	bx lr

	thumb_func_start sub_080BB218
sub_080BB218: @ 0x080BB218
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r2, #0
	adds r4, r5, #0
	adds r4, #0x24
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r2, [r4, #4]
	ldrh r3, [r4, #6]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	bl sub_080C4618
	str r0, [r5, #0x24]
	ldrh r0, [r4, #4]
	subs r0, r0, r6
	strh r0, [r4, #4]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BB248
sub_080BB248: @ 0x080BB248
	push {lr}
	adds r3, r0, #0
	adds r3, #0x24
	ldrh r2, [r3, #4]
	subs r2, r2, r1
	strh r2, [r3, #4]
	ldr r0, [r0, #0x24]
	ldrh r1, [r3, #4]
	ldrh r2, [r3, #6]
	bl sub_080C48CC
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BB264
sub_080BB264: @ 0x080BB264
	push {lr}
	ldr r0, [r0, #0x24]
	movs r1, #0
	bl sub_080C48F0
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BB274
sub_080BB274: @ 0x080BB274
	push {lr}
	cmp r1, #1
	bne .L080BB28C
	movs r0, #0x81
	lsls r0, r0, #1
	bl Flag_Set
	movs r0, #0x83
	lsls r0, r0, #1
	bl Flag_Set
	b .L080BB29C
.L080BB28C:
	movs r0, #0x81
	lsls r0, r0, #1
	bl Flag_Clear
	movs r0, #0x83
	lsls r0, r0, #1
	bl Flag_Clear
.L080BB29C:
	pop {r0}
	bx r0

	thumb_func_start sub_080BB2A0
sub_080BB2A0: @ 0x080BB2A0
	push {lr}
	ldr r0, .L080BB2C8
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L080BB2CC
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #2
	bl PalFade_FadeRangeToWhite
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #2
	bl PalFade_FadeRangeToWhite
	b .L080BB2E2
.L080BB2C8: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080BB2CC:
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #2
	bl PalFade_FadeRangeToWhite
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #2
	bl PalFade_FadeRangeToWhite
.L080BB2E2:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BB2E8
sub_080BB2E8: @ 0x080BB2E8
	push {lr}
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #1
	movs r3, #0x20
	bl PalFade_FadeRangeToBlackWithDuration
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #1
	movs r3, #0x20
	bl PalFade_FadeRangeToBlackWithDuration
	pop {r0}
	bx r0

	thumb_func_start sub_080BB308
sub_080BB308: @ 0x080BB308
	push {lr}
	ldr r0, .L080BB314
	bl Flag_Set
	pop {r0}
	bx r0
.L080BB314: .4byte 0x00000105

	thumb_func_start sub_080BB318
sub_080BB318: @ 0x080BB318
	ldr r1, .L080BB32C
	ldr r0, .L080BB330
	str r0, [r1]
	ldr r0, .L080BB334
	str r0, [r1, #4]
	ldr r0, .L080BB338
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BB32C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BB330: .4byte 0x02001000 @ EWRAM+0x1000
.L080BB334: .4byte 0x06013000 @ VRAM+0x13000
.L080BB338: .4byte 0x84001200

	thumb_func_start sub_080BB33C
sub_080BB33C: @ 0x080BB33C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	mov r8, r0
	mov r5, r8
	adds r5, #0x24
	ldr r0, .L080BB404
	ldr r4, .L080BB408
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080BB40C
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080BB410
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080BB414
	movs r1, #0x80
	lsls r1, r1, #7
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080BB418
	ldr r4, .L080BB41C
	movs r6, #0x20
	str r6, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080BB420
	adds r2, r4, #0
	adds r2, #0x20
	str r6, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080BB424
	adds r2, r4, #0
	adds r2, #0x40
	str r6, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080BB428
	adds r4, #0x60
	str r6, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xe0
	lsls r0, r0, #1
	movs r1, #0x40
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
	ldr r0, .L080BB42C
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0
	movs r2, #1
	mov r1, r8
	strh r2, [r1, #0x24]
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r5, #2]
	strh r1, [r5, #4]
	strh r0, [r5, #6]
	strh r2, [r5, #0x12]
	strh r6, [r5, #0x14]
	strh r6, [r5, #0x16]
	strh r0, [r5, #0x18]
	strh r0, [r5, #8]
	strh r0, [r5, #0xa]
	strh r0, [r5, #0xe]
	strh r0, [r5, #0x1c]
	strh r0, [r5, #0x20]
	strh r0, [r5, #0x1a]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BB404: .4byte gUnknown_08186EB0
.L080BB408: .4byte 0x02001000 @ EWRAM+0x1000
.L080BB40C: .4byte gUnknown_081873FC
.L080BB410: .4byte gUnknown_08187D00
.L080BB414: .4byte gUnknown_081892C8
.L080BB418: .4byte gUnknown_08189434
.L080BB41C: .4byte 0x03002D30 @ IWRAM+0x2D30
.L080BB420: .4byte gUnknown_08189454
.L080BB424: .4byte gUnknown_08189474
.L080BB428: .4byte gUnknown_08189494
.L080BB42C: .4byte sub_080BB318

	thumb_func_start sub_080BB430
sub_080BB430: @ 0x080BB430
	push {lr}
	movs r0, #0xe0
	lsls r0, r0, #1
	movs r1, #0x40
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BB444
sub_080BB444: @ 0x080BB444
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r5, r0, #0
	adds r5, #0x24
	ldrh r4, [r5, #2]
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #3
	movs r1, #0xff
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #4
	movs r1, #0xff
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, .L080BB598
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r5, [sp, #0x14]
	ldrh r1, [r5, #2]
	ldrh r2, [r5, #4]
	add r0, sp, #0x10
	movs r3, #8
	bl sub_0815862C
	ldr r4, .L080BB59C
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp]
	ldrh r0, [r5, #8]
	str r0, [sp, #4]
	ldrh r0, [r5, #0xa]
	str r0, [sp, #8]
	movs r6, #0
	str r6, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #4
	movs r2, #0xe
	movs r3, #3
	bl Sprite_DrawSharedAffine
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	beq .L080BB516
	ldr r1, .L080BB5A0
	ldrh r0, [r5, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r5, [sp, #0x14]
	ldrh r1, [r5, #2]
	ldrh r2, [r5, #4]
	add r0, sp, #0x10
	movs r3, #8
	bl sub_0815862C
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	movs r0, #0xe0
	lsls r0, r0, #2
	str r0, [sp]
	ldrh r0, [r5, #8]
	add r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5, #0xa]
	adds r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #3
	movs r2, #0xf
	movs r3, #3
	bl Sprite_DrawSharedAffine
	ldr r0, .L080BB5A4
	ldr r1, [r0]
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne .L080BB516
	ldrh r0, [r5, #0x1e]
	adds r0, #1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne .L080BB516
	strh r1, [r5, #0x1e]
.L080BB516:
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	beq .L080BB5AE
	ldr r1, .L080BB5A8
	ldrh r0, [r5, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r4, r5, #0
	adds r4, #0x12
	str r4, [sp, #0x14]
	ldrh r1, [r5, #0x14]
	ldrh r2, [r5, #0x16]
	add r0, sp, #0x10
	movs r3, #8
	bl sub_0815862C
	ldr r0, .L080BB59C
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #0xf0
	lsls r0, r0, #1
	str r0, [sp]
	ldrh r0, [r5, #8]
	adds r0, #0x30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5, #0xa]
	adds r0, #0x34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #2
	movs r2, #0xd
	movs r3, #3
	bl Sprite_DrawSharedAffine
	ldrh r0, [r5, #0x10]
	adds r0, #1
	movs r2, #0
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bne .L080BB57E
	strh r2, [r5, #0x10]
.L080BB57E:
	ldrh r1, [r5, #0x14]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq .L080BB5AC
	adds r0, r1, #0
	adds r0, #8
	strh r0, [r5, #0x14]
	ldrh r0, [r5, #0x16]
	adds r0, #8
	strh r0, [r5, #0x16]
	b .L080BB5AE
	.byte 0x00, 0x00
.L080BB598: .4byte gUnknown_080073B0
.L080BB59C: .4byte 0x03003800 @ IWRAM+0x3800
.L080BB5A0: .4byte gUnknown_081894B4
.L080BB5A4: .4byte 0x030031BC @ IWRAM+0x31BC
.L080BB5A8: .4byte gUnknown_081894C8
.L080BB5AC:
	strh r2, [r5, #0xe]
.L080BB5AE:
	ldrh r0, [r5, #0x1a]
	cmp r0, #1
	bne .L080BB5C4
	ldrh r0, [r5, #2]
	cmp r0, #0x18
	beq .L080BB5C4
	subs r0, #1
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	subs r0, #1
	strh r0, [r5, #4]
.L080BB5C4:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080BB5D0
sub_080BB5D0: @ 0x080BB5D0
	push {lr}
	adds r0, #0x24
	movs r1, #1
	strh r1, [r0, #0xe]
	strh r1, [r0, #0x1c]
	strh r1, [r0, #0x20]
	movs r0, #0x98
	bl sub_080C51D4
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BB5E8
sub_080BB5E8: @ 0x080BB5E8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r4, #0x24
	bl sub_080B6DB4
	str r0, [r4, #0x24]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080BB5FC
sub_080BB5FC: @ 0x080BB5FC
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x24
	ldr r0, [r2, #0x24]
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080BB612
	movs r0, #0
	strh r0, [r1, #0x1c]
	b .L080BB618
.L080BB612:
	movs r0, #1
	strh r0, [r1, #0x1c]
	strh r0, [r2, #0x1a]
.L080BB618:
	pop {r0}
	bx r0

	thumb_func_start sub_080BB61C
sub_080BB61C: @ 0x080BB61C
	ldr r1, .L080BB630
	ldr r0, .L080BB634
	str r0, [r1]
	ldr r0, .L080BB638
	str r0, [r1, #4]
	ldr r0, .L080BB63C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BB630: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BB634: .4byte 0x02001000 @ EWRAM+0x1000
.L080BB638: .4byte 0x06013000 @ VRAM+0x13000
.L080BB63C: .4byte 0x84001200

	thumb_func_start sub_080BB640
sub_080BB640: @ 0x080BB640
	push {r4, r5, lr}
	sub sp, #4
	adds r2, r0, #0
	adds r2, #0x24
	ldr r1, .L080BB6C0
	str r2, [r1]
	movs r3, #0
	movs r1, #1
	strh r1, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2, #2]
	strh r0, [r2, #4]
	strh r3, [r2, #6]
	movs r0, #0x78
	strh r0, [r2, #8]
	movs r0, #0x44
	strh r0, [r2, #0xa]
	movs r0, #8
	strh r0, [r2, #0xc]
	ldr r0, .L080BB6C4
	ldr r4, .L080BB6C8
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080BB6CC
	movs r1, #0x80
	lsls r1, r1, #5
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080BB6D0
	ldr r4, .L080BB6D4
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080BB6D8
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
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
	ldr r0, .L080BB6DC
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BB6C0: .4byte 0x03004640 @ IWRAM+0x4640
.L080BB6C4: .4byte gUnknown_08189570
.L080BB6C8: .4byte 0x02001000 @ EWRAM+0x1000
.L080BB6CC: .4byte gUnknown_08189BFC
.L080BB6D0: .4byte gUnknown_08189BDC
.L080BB6D4: .4byte 0x03002D70 @ IWRAM+0x2D70
.L080BB6D8: .4byte gUnknown_0818B1C0
.L080BB6DC: .4byte sub_080BB61C

	thumb_func_start sub_080BB6E0
sub_080BB6E0: @ 0x080BB6E0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r4, #0x24
	bl sub_080B6DB4
	str r0, [r4, #0x10]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080BB6F4
sub_080BB6F4: @ 0x080BB6F4
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x34]
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080BB704
	movs r0, #0
	b .L080BB706
.L080BB704:
	movs r0, #1
.L080BB706:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080BB70C
sub_080BB70C: @ 0x080BB70C
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r4, #0x24
	movs r6, #0
	ldr r0, .L080BB79C
	str r4, [r0]
	ldr r1, .L080BB7A0
	ldr r0, [r1]
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	add r0, sp, #0x10
	movs r3, #8
	bl sub_0815862C
	ldr r5, .L080BB7A4
	str r5, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [sp]
	ldrh r0, [r4, #8]
	str r0, [sp, #4]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r2, #0xe
	movs r3, #3
	bl Sprite_DrawSharedAffine
	ldr r0, .L080BB7A8
	ldr r0, [r0]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	ldr r1, .L080BB7AC
	cmp r0, #0
	bne .L080BB762
	ldr r1, .L080BB7B0
.L080BB762:
	ldr r0, [r1]
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	add r0, sp, #0x10
	movs r3, #8
	bl sub_0815862C
	str r5, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	ldrh r0, [r4, #8]
	str r0, [sp, #4]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	movs r2, #0xf
	movs r3, #3
	bl Sprite_DrawSharedAffine
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BB79C: .4byte 0x03004640 @ IWRAM+0x4640
.L080BB7A0: .4byte gUnknown_08007174
.L080BB7A4: .4byte 0x03003800 @ IWRAM+0x3800
.L080BB7A8: .4byte 0x030031BC @ IWRAM+0x31BC
.L080BB7AC: .4byte gUnknown_080071FC
.L080BB7B0: .4byte gUnknown_080071B0

	thumb_func_start sub_080BB7B4
sub_080BB7B4: @ 0x080BB7B4
	push {lr}
	cmp r1, #0
	bne .L080BB7C6
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #8
	bl PalFade_FadeRangeToBlack
	b .L080BB7D2
.L080BB7C6:
	movs r0, #0xf0
	lsls r0, r0, #1
	movs r1, #0x20
	movs r2, #1
	bl PalFade_FadeRangeToBlack
.L080BB7D2:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BB7D8
sub_080BB7D8: @ 0x080BB7D8
	push {lr}
	adds r2, r0, #0
	adds r2, #0x24
	ldrh r0, [r2, #2]
	cmp r0, #0x20
	beq .L080BB7EE
	subs r0, #1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	subs r0, #1
	strh r0, [r2, #4]
.L080BB7EE:
	cmp r1, #0
	bne .L080BB7FA
	ldr r1, .L080BB81C
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
.L080BB7FA:
	ldrh r0, [r2, #0xc]
	subs r0, #1
	strh r0, [r2, #0xc]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080BB816
	movs r0, #8
	strh r0, [r2, #0xc]
	ldrh r0, [r2, #0xa]
	subs r0, #1
	strh r0, [r2, #0xa]
	ldrh r0, [r2, #8]
	adds r0, #1
	strh r0, [r2, #8]
.L080BB816:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BB81C: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080BB820
sub_080BB820: @ 0x080BB820
	push {lr}
	adds r1, r0, #0
	adds r1, #0x24
	ldr r0, .L080BB844
	ldrh r2, [r0]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L080BB848
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq .L080BB864
	subs r0, #1
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	subs r0, #1
	b .L080BB862
	.byte 0x00, 0x00
.L080BB844: .4byte 0x03003964 @ IWRAM+0x3964
.L080BB848:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq .L080BB864
	ldrh r2, [r1, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r2, r0
	beq .L080BB864
	adds r0, r2, #1
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	adds r0, #1
.L080BB862:
	strh r0, [r1, #4]
.L080BB864:
	pop {r0}
	bx r0

	thumb_func_start sub_080BB868
sub_080BB868: @ 0x080BB868
.L080BB868:
	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0
	adds r1, r2, #0
	adds r4, r3, #0
	bl LZ77UnCompWram
	movs r6, #0xf
	ldr r7, .L080BB89C
	movs r3, #0x1c
.L080BB87A:
	ldrb r0, [r5]
	adds r5, #1
	ands r0, r6
	adds r0, #8
	ldrh r2, [r4]
	adds r1, r7, #0
	ands r1, r2
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4]
	adds r4, #2
	subs r3, #1
	cmp r3, #0
	bge .L080BB87A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080BB89C: .4byte 0x00000FFF

	thumb_func_start sub_080BB8A0
sub_080BB8A0: @ 0x080BB8A0
	sub sp, #4
	movs r2, #0
	str r2, [sp]
	ldr r0, .L080BB8CC
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080BB8D0
	str r1, [r0, #4]
	ldr r1, .L080BB8D4
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r2, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080BB8D8
	str r1, [r0, #4]
	ldr r1, .L080BB8DC
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	add sp, #4
	bx lr
	.byte 0x00, 0x00
.L080BB8CC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BB8D0: .4byte 0x06004000 @ VRAM+0x4000
.L080BB8D4: .4byte 0x85001000
.L080BB8D8: .4byte 0x06003000 @ VRAM+0x3000
.L080BB8DC: .4byte 0x85000400

	thumb_func_start sub_080BB8E0
sub_080BB8E0: @ 0x080BB8E0
	push {lr}
	sub sp, #8
	bl sub_080C14FC
	ldr r1, .L080BB918
	movs r0, #0x1c
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #1
	movs r3, #0
	bl Tilemap_FillRect
	ldr r0, .L080BB91C
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080BB920
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080BB924
	movs r0, #1
	strh r0, [r1, #0x30]
	add sp, #8
	pop {r0}
	bx r0
.L080BB918: .4byte 0x02000000 @ EWRAM
.L080BB91C: .4byte sub_080BB8A0
.L080BB920: .4byte sub_080C153C
.L080BB924: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080BB928
sub_080BB928: @ 0x080BB928
	ldr r1, .L080BB948
	ldr r0, .L080BB94C
	str r0, [r1]
	ldr r0, .L080BB950
	str r0, [r1, #4]
	ldr r0, .L080BB954
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080BB958
	str r0, [r1]
	ldr r0, .L080BB95C
	str r0, [r1, #4]
	ldr r0, .L080BB960
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L080BB948: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BB94C: .4byte 0x02001000 @ EWRAM+0x1000
.L080BB950: .4byte 0x0600E000 @ VRAM+0xE000
.L080BB954: .4byte 0x84000500
.L080BB958: .4byte 0x02000000 @ EWRAM
.L080BB95C: .4byte 0x06001000 @ VRAM+0x1000
.L080BB960: .4byte 0x84000400

	thumb_func_start sub_080BB964
sub_080BB964: @ 0x080BB964
	push {r4, r5, r6, lr}
	ldr r4, .L080BB9E8
	ldr r0, .L080BB9EC
	ldr r1, .L080BB9F0
	bl LZ77UnCompWram
	ldr r0, .L080BB9F4
	adds r1, r4, #0
	bl LZ77UnCompWram
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r3, r0, #0
	movs r0, #0x80
	lsls r0, r0, #8
	adds r2, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
.L080BB988:
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080BB998
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, r0, r2
	strh r0, [r4]
.L080BB998:
	subs r1, #1
	adds r4, #2
	cmp r1, #0
	bne .L080BB988
	ldr r0, .L080BB9F8
	movs r6, #0
	strh r1, [r0]
	ldr r1, .L080BB9FC
	movs r0, #8
	strh r0, [r1]
	ldr r1, .L080BBA00
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, .L080BBA04
	strb r6, [r0]
	ldr r5, .L080BBA08
	movs r0, #0xe0
	strb r0, [r5]
	ldr r0, .L080BBA0C
	movs r4, #0x68
	strb r4, [r0]
	ldr r1, .L080BBA10
	movs r0, #0x3d
	strb r0, [r1]
	movs r0, #0xc6
	bl Flag_Test
	cmp r0, #0
	beq .L080BB9D8
	strb r4, [r5]
	ldr r0, .L080BBA14
	strb r6, [r0]
.L080BB9D8:
	ldr r0, .L080BBA18
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BB9E8: .4byte 0x02000000 @ EWRAM
.L080BB9EC: .4byte gUnknown_08181238
.L080BB9F0: .4byte 0x02001000 @ EWRAM+0x1000
.L080BB9F4: .4byte gUnknown_08181F84
.L080BB9F8: .4byte 0x03000040 @ IWRAM+0x40
.L080BB9FC: .4byte 0x03000006 @ IWRAM+0x6
.L080BBA00: .4byte 0x03000030 @ IWRAM+0x30
.L080BBA04: .4byte 0x03000031 @ IWRAM+0x31
.L080BBA08: .4byte 0x03000034 @ IWRAM+0x34
.L080BBA0C: .4byte 0x03000035 @ IWRAM+0x35
.L080BBA10: .4byte 0x03000038 @ IWRAM+0x38
.L080BBA14: .4byte 0x0300003B @ IWRAM+0x3B
.L080BBA18: .4byte sub_080BB928

	thumb_func_start sub_080BBA1C
sub_080BBA1C: @ 0x080BBA1C
	ldr r1, .L080BBA44
	ldr r0, .L080BBA48
	str r0, [r1]
	ldr r0, .L080BBA4C
	str r0, [r1, #4]
	ldr r0, .L080BBA50
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080BBA54
	str r0, [r1]
	ldr r0, .L080BBA58
	str r0, [r1, #4]
	ldr r0, .L080BBA5C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xc6
	ldr r2, .L080BBA60
	adds r0, r2, #0
	strh r0, [r1]
	bx lr
.L080BBA44: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BBA48: .4byte 0x02005000 @ EWRAM+0x5000
.L080BBA4C: .4byte 0x06004000 @ VRAM+0x4000
.L080BBA50: .4byte 0x84001000
.L080BBA54: .4byte 0x02000000 @ EWRAM
.L080BBA58: .4byte 0x06003000 @ VRAM+0x3000
.L080BBA5C: .4byte 0x84000400
.L080BBA60: .4byte 0x00008607

	thumb_func_start sub_080BBA64
sub_080BBA64: @ 0x080BBA64
.L080BBA64:
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x24
	ldrh r4, [r7, #0x24]
	ldrh r5, [r6, #2]
	ldrh r1, [r6, #4]
	lsls r4, r4, #3
	ldr r0, .L080BBAB4
	adds r4, r4, r0
	ldr r2, .L080BBAB8
	ldr r3, .L080BBABC
	lsls r1, r1, #0xa
	adds r1, #0x20
	adds r2, r1, r2
	lsls r5, r5, #6
	adds r3, r5, r3
	ldr r0, [r4]
	ldr r1, [r4, #4]
	bl sub_080BB868
	ldrh r0, [r7, #0x24]
	cmp r0, #0
	beq .L080BBA98
	subs r0, #1
	strh r0, [r7, #0x24]
.L080BBA98:
	ldrh r0, [r6, #4]
	subs r0, #1
	movs r1, #0xf
	ands r0, r1
	strh r0, [r6, #4]
	ldrh r0, [r6, #2]
	subs r0, #1
	movs r1, #0x3f
	ands r0, r1
	strh r0, [r6, #2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BBAB4: .4byte gUnknown_0818B2E0
.L080BBAB8: .4byte 0x02005000 @ EWRAM+0x5000
.L080BBABC: .4byte 0x02000000 @ EWRAM

	thumb_func_start sub_080BBAC0
sub_080BBAC0: @ 0x080BBAC0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
	str r4, [sp, #4]
	ldr r1, .L080BBB68
	ldr r2, .L080BBB6C
	add r0, sp, #4
	bl CpuSet
	str r4, [sp, #8]
	add r0, sp, #8
	ldr r4, .L080BBB70
	ldr r2, .L080BBB74
	adds r1, r4, #0
	bl CpuSet
	ldr r0, .L080BBB78
	adds r1, r4, #0
	bl LZ77UnCompWram
	movs r0, #0x61
	strh r0, [r6, #0x24]
	movs r0, #0x3f
	strh r0, [r5, #2]
	movs r0, #0xf
	strh r0, [r5, #4]
	movs r4, #0
.L080BBAFC:
	adds r0, r6, #0
	bl sub_080BBA64
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xf
	bls .L080BBAFC
	ldr r1, .L080BBB7C
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L080BBB80
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r2, .L080BBB84
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r2]
	ldr r1, .L080BBB88
	movs r0, #0x66
	strh r0, [r1]
	ldr r1, .L080BBB8C
	ldr r4, .L080BBB90
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r2, r4, #0
	bl Palette_CopyWithEffect
	ldr r1, .L080BBB94
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080BBB98
	strh r1, [r0]
	ldr r3, .L080BBB9C
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #1
	bl PalFade_FadeRangeInFromBlackTagged
	ldr r1, .L080BBBA0
	str r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BBB68: .4byte 0x02005000 @ EWRAM+0x5000
.L080BBB6C: .4byte 0x05001000
.L080BBB70: .4byte 0x02000000 @ EWRAM
.L080BBB74: .4byte 0x05000400
.L080BBB78: .4byte gUnknown_08180BA0
.L080BBB7C: .4byte 0x0300000E @ IWRAM+0xE
.L080BBB80: .4byte sub_080BBA1C
.L080BBB84: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080BBB88: .4byte 0x03004534 @ IWRAM+0x4534
.L080BBB8C: .4byte gUnknown_08181138
.L080BBB90: .4byte 0x03002AB0 @ IWRAM+0x2AB0
.L080BBB94: .4byte 0xFFFFFF00
.L080BBB98: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080BBB9C: .4byte 0x00008001
.L080BBBA0: .4byte 0x0300452C @ IWRAM+0x452C

	thumb_func_start sub_080BBBA4
sub_080BBBA4: @ 0x080BBBA4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x24
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldr r1, .L080BBC04
	ldrh r0, [r1]
	subs r2, r0, #1
	strh r2, [r1]
	ldr r3, .L080BBC08
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r0, #0xa0
	rsbs r0, r0, #0
	cmp r1, r0
	ble .L080BBBCC
	subs r0, r5, #1
	strh r0, [r3]
.L080BBBCC:
	movs r0, #7
	ands r2, r0
	cmp r2, #0
	bne .L080BBBE2
	adds r0, r4, #0
	bl sub_080BBA64
	ldr r0, .L080BBC0C
	movs r1, #1
	bl VBlankTask_AddCounted
.L080BBBE2:
	ldr r0, [r6, #0xc]
	adds r1, r0, #0
	adds r1, #0x24
	ldrh r0, [r1, #4]
	cmp r0, #0x40
	beq .L080BBBF2
	adds r0, #1
	strh r0, [r1, #4]
.L080BBBF2:
	ldrh r0, [r4, #0x24]
	cmp r0, #0
	bne .L080BBBFC
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080BBBFC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BBC04: .4byte 0x0300000E @ IWRAM+0xE
.L080BBC08: .4byte 0x03000006 @ IWRAM+0x6
.L080BBC0C: .4byte sub_080BBA1C

	thumb_func_start sub_080BBC10
sub_080BBC10: @ 0x080BBC10
	push {r4, lr}
	adds r2, r0, #0
	adds r2, #0x24
	ldr r0, .L080BBC40
	ldr r1, [r0]
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	bne .L080BBCA8
	ldrh r3, [r2, #6]
	movs r4, #6
	ldrsh r0, [r2, r4]
	cmp r0, #0
	bne .L080BBC50
	ldr r1, .L080BBC44
	ldr r4, .L080BBC48
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, .L080BBC4C
	strh r0, [r1]
	orrs r0, r3
	strh r0, [r2, #6]
	b .L080BBC5A
	.byte 0x00, 0x00
.L080BBC40: .4byte 0x030031BC @ IWRAM+0x31BC
.L080BBC44: .4byte 0x0300000C @ IWRAM+0xC
.L080BBC48: .4byte 0x0000FFFF
.L080BBC4C: .4byte 0x03000004 @ IWRAM+0x4
.L080BBC50:
	ldr r0, .L080BBC7C
	strh r1, [r0]
	ldr r0, .L080BBC80
	strh r1, [r0]
	strh r1, [r2, #6]
.L080BBC5A:
	ldrh r3, [r2, #8]
	movs r1, #8
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne .L080BBC94
	ldr r1, .L080BBC84
	ldr r4, .L080BBC88
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, .L080BBC8C
	movs r0, #7
	strh r0, [r1]
	ldr r1, .L080BBC90
	adds r0, r1, #0
	orrs r0, r3
	b .L080BBCA6
	.byte 0x00, 0x00
.L080BBC7C: .4byte 0x0300000C @ IWRAM+0xC
.L080BBC80: .4byte 0x03000004 @ IWRAM+0x4
.L080BBC84: .4byte 0x0300000E @ IWRAM+0xE
.L080BBC88: .4byte 0x00000197
.L080BBC8C: .4byte 0x03000006 @ IWRAM+0x6
.L080BBC90: .4byte 0x0000FFFF
.L080BBC94:
	ldr r1, .L080BBCB0
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r3, #0
	strh r0, [r1]
	ldr r1, .L080BBCB4
	movs r0, #8
	strh r0, [r1]
	movs r0, #0
.L080BBCA6:
	strh r0, [r2, #8]
.L080BBCA8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BBCB0: .4byte 0x0300000E @ IWRAM+0xE
.L080BBCB4: .4byte 0x03000006 @ IWRAM+0x6

	thumb_func_start sub_080BBCB8
sub_080BBCB8: @ 0x080BBCB8
	ldr r2, .L080BBCD0
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r3, #0
	strh r1, [r2]
	ldr r2, .L080BBCD4
	movs r1, #8
	strh r1, [r2]
	movs r1, #0
	str r1, [r0, #0x20]
	bx lr
	.byte 0x00, 0x00
.L080BBCD0: .4byte 0x0300000E @ IWRAM+0xE
.L080BBCD4: .4byte 0x03000006 @ IWRAM+0x6

	thumb_func_start sub_080BBCD8
sub_080BBCD8: @ 0x080BBCD8
	ldr r1, .L080BBCEC
	ldr r0, .L080BBCF0
	str r0, [r1]
	ldr r0, .L080BBCF4
	str r0, [r1, #4]
	ldr r0, .L080BBCF8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BBCEC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BBCF0: .4byte 0x02001000 @ EWRAM+0x1000
.L080BBCF4: .4byte 0x06013000 @ VRAM+0x13000
.L080BBCF8: .4byte 0x84000D00
