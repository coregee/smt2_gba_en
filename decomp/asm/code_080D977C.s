	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080D977C
sub_080D977C: @ 0x080D977C
	push {lr}
	ldr r0, .L080D979C
	ldr r0, [r0]
	cmp r0, #0
	bne .L080D978E
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
.L080D978E:
	bl sub_080BDB58
	bl Task_RunAll
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D979C: .4byte 0x0300609C @ IWRAM+0x609C

	thumb_func_start sub_080D97A0
sub_080D97A0: @ 0x080D97A0
	push {r4, r5, lr}
	adds r0, r1, #0
	adds r4, r2, #0
	ldr r1, .L080D97C0
	adds r4, r4, r1
	ldr r5, .L080D97C4
	adds r1, r5, #0
	bl HuffUnComp
	adds r0, r5, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D97C0: .4byte 0x02001000 @ EWRAM+0x1000
.L080D97C4: .4byte 0x0200AFC8 @ EWRAM+0xAFC8

	thumb_func_start sub_080D97C8
sub_080D97C8: @ 0x080D97C8
	push {lr}
	adds r0, r1, #0
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D97D8
sub_080D97D8: @ 0x080D97D8
	ldr r0, .L080D97EC
	ldr r1, .L080D97F0
	str r0, [r1]
	ldr r0, .L080D97F4
	str r0, [r1, #4]
	ldr r0, .L080D97F8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D97EC: .4byte 0x02001000 @ EWRAM+0x1000
.L080D97F0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D97F4: .4byte 0x06004040 @ VRAM+0x4040
.L080D97F8: .4byte 0x840007F0

	thumb_func_start sub_080D97FC
sub_080D97FC: @ 0x080D97FC
	ldr r0, .L080D9814
	ldr r1, .L080D9818
	movs r2, #0xfe
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, .L080D981C
	str r0, [r1, #4]
	ldr r0, .L080D9820
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L080D9814: .4byte 0x02001000 @ EWRAM+0x1000
.L080D9818: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D981C: .4byte 0x06008040 @ VRAM+0x8040
.L080D9820: .4byte 0x84000ED0

	thumb_func_start sub_080D9824
sub_080D9824: @ 0x080D9824
	ldr r2, .L080D9850
	ldr r1, .L080D9854
	movs r3, #0xfe
	lsls r3, r3, #5
	adds r0, r2, r3
	str r0, [r1]
	ldr r0, .L080D9858
	str r0, [r1, #4]
	ldr r0, .L080D985C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #7
	adds r2, r2, r0
	str r2, [r1]
	ldr r0, .L080D9860
	str r0, [r1, #4]
	ldr r0, .L080D9864
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D9850: .4byte 0x02001000 @ EWRAM+0x1000
.L080D9854: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9858: .4byte 0x06008040 @ VRAM+0x8040
.L080D985C: .4byte 0x84000370
.L080D9860: .4byte 0x06008E00 @ VRAM+0x8E00
.L080D9864: .4byte 0x84000B60

	thumb_func_start sub_080D9868
sub_080D9868: @ 0x080D9868
	ldr r1, .L080D987C
	ldr r0, .L080D9880
	str r0, [r1]
	ldr r0, .L080D9884
	str r0, [r1, #4]
	ldr r0, .L080D9888
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D987C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9880: .4byte 0x02000000 @ EWRAM
.L080D9884: .4byte 0x06003040 @ VRAM+0x3040
.L080D9888: .4byte 0x84000200

	thumb_func_start sub_080D988C
sub_080D988C: @ 0x080D988C
	push {r4, r5, r6, r7, lr}
	ldr r6, .L080D98DC
	ldr r0, .L080D98E0
	str r1, [r0]
	str r6, [r0, #4]
	ldr r1, .L080D98E4
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	movs r1, #0
	ldr r0, .L080D98E8
	mov ip, r0
	movs r5, #0xf
.L080D98A4:
	movs r3, #0
	adds r4, r1, #1
	lsls r1, r1, #6
	adds r0, r6, #2
	adds r1, r1, r0
.L080D98AE:
	ldrb r0, [r2]
	adds r2, #1
	ands r0, r5
	adds r0, #8
	lsls r0, r0, #0xc
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	cmp r3, #0x1b
	bls .L080D98AE
	adds r1, r4, #0
	cmp r1, #0x19
	bls .L080D98A4
	mov r0, ip
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D98DC: .4byte 0x02000000 @ EWRAM
.L080D98E0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D98E4: .4byte 0x84000400
.L080D98E8: .4byte sub_080D9868

	thumb_func_start sub_080D98EC
sub_080D98EC: @ 0x080D98EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r2, #0
	ldr r7, .L080D9958
	ldr r0, .L080D995C
	str r1, [r0]
	str r7, [r0, #4]
	ldr r1, .L080D9960
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	movs r2, #0
	ldr r0, .L080D9964
	mov r8, r0
	movs r1, #0xf
	mov ip, r1
.L080D990C:
	movs r5, #0
	lsls r0, r2, #5
	adds r6, r2, #1
	adds r0, #0x1c
	lsls r2, r2, #6
	adds r1, r7, #2
	adds r2, r2, r1
	lsls r0, r0, #1
	adds r3, r0, r7
.L080D991E:
	ldrb r0, [r4]
	adds r4, #1
	mov r1, ip
	ands r0, r1
	adds r0, #8
	lsls r0, r0, #0xc
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r1, [r3]
	adds r1, r1, r0
	strh r1, [r3]
	subs r3, #2
	adds r2, #2
	adds r5, #1
	cmp r5, #0xd
	bls .L080D991E
	adds r2, r6, #0
	cmp r2, #0x19
	bls .L080D990C
	mov r0, r8
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080D9958: .4byte 0x02000000 @ EWRAM
.L080D995C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9960: .4byte 0x84000400
.L080D9964: .4byte sub_080D9868

	thumb_func_start sub_080D9968
sub_080D9968: @ 0x080D9968
	push {lr}
	sub sp, #4
	ldr r2, .L080D9984
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D9984: .4byte 0x03002AB0 @ IWRAM+0x2AB0

	thumb_func_start sub_080D9988
sub_080D9988: @ 0x080D9988
	push {lr}
	ldr r3, .L080D999C
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #1
	bl PalFade_FadeRangeInFromBlackTagged
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D999C: .4byte 0x00008001

	thumb_func_start sub_080D99A0
sub_080D99A0: @ 0x080D99A0
	push {lr}
	ldr r3, .L080D99B4
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #1
	bl PalFade_FadeRangeToBlackTagged
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D99B4: .4byte 0x00008001

	thumb_func_start sub_080D99B8
sub_080D99B8: @ 0x080D99B8
	push {r4, r5, lr}
	sub sp, #4
	ldr r1, .L080D99F4
	ldr r4, .L080D99F8
	movs r3, #0x80
	lsls r3, r3, #1
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	bl Palette_CopyWithEffect
	ldr r1, .L080D99FC
	adds r4, #0xe0
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r1, #0xc0
	lsls r1, r1, #1
	movs r0, #0x80
	movs r2, #1
	bl PalFade_FadeRangeInFromBlack
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D99F4: .4byte gUnknown_081B6C30
.L080D99F8: .4byte 0x03002BB0 @ IWRAM+0x2BB0
.L080D99FC: .4byte gUnknown_08580A60

	thumb_func_start sub_080D9A00
sub_080D9A00: @ 0x080D9A00
	push {lr}
	movs r1, #0xc0
	lsls r1, r1, #1
	movs r0, #0x80
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D9A14
sub_080D9A14: @ 0x080D9A14
.L080D9A14:
	ldr r1, .L080D9A28
	ldr r0, .L080D9A2C
	str r0, [r1]
	ldr r0, .L080D9A30
	str r0, [r1, #4]
	ldr r0, .L080D9A34
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D9A28: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9A2C: .4byte 0x02024074 @ EWRAM+0x24074
.L080D9A30: .4byte 0x06002000 @ VRAM+0x2000
.L080D9A34: .4byte 0x84000140

	thumb_func_start sub_080D9A38
sub_080D9A38: @ 0x080D9A38
.L080D9A38:
	ldr r1, .L080D9A4C
	ldr r0, .L080D9A50
	str r0, [r1]
	ldr r0, .L080D9A54
	str r0, [r1, #4]
	ldr r0, .L080D9A58
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D9A4C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9A50: .4byte 0x02006000 @ EWRAM+0x6000
.L080D9A54: .4byte 0x06010000 @ VRAM+0x10000
.L080D9A58: .4byte 0x84000800

	thumb_func_start sub_080D9A5C
sub_080D9A5C: @ 0x080D9A5C
.L080D9A5C:
	ldr r1, .L080D9A70
	ldr r0, .L080D9A74
	str r0, [r1]
	ldr r0, .L080D9A78
	str r0, [r1, #4]
	ldr r0, .L080D9A7C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D9A70: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9A74: .4byte gUnknown_08573AF4
.L080D9A78: .4byte 0x06012000 @ VRAM+0x12000
.L080D9A7C: .4byte 0x84000200

	thumb_func_start sub_080D9A80
sub_080D9A80: @ 0x080D9A80
	push {lr}
	ldr r1, .L080D9AA4
	ldr r0, .L080D9AA8
	str r0, [r1]
	ldr r0, .L080D9AAC
	str r0, [r1, #4]
	ldr r0, .L080D9AB0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080D9A14
	bl sub_080D9A38
	bl sub_080D9A5C
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D9AA4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9AA8: .4byte 0x02001000 @ EWRAM+0x1000
.L080D9AAC: .4byte 0x0600BC00 @ VRAM+0xBC00
.L080D9AB0: .4byte 0x84001100

	thumb_func_start sub_080D9AB4
sub_080D9AB4: @ 0x080D9AB4
	push {r4, r5, lr}
	sub sp, #4
	ldr r1, .L080D9B10
	ldr r5, .L080D9B14
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	adds r2, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080D9B18
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r3, #0x80
	lsls r3, r3, #1
	str r4, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	ldr r1, .L080D9B1C
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r2, r5, r0
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080D9B20
	movs r0, #0
	strh r0, [r1]
	strh r0, [r5]
	ldr r1, .L080D9B24
	ldr r0, .L080D9B28
	str r0, [r1]
	ldr r0, .L080D9B2C
	str r0, [r1, #4]
	ldr r0, .L080D9B30
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D9B10: .4byte gUnknown_08580880
.L080D9B14: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080D9B18: .4byte gUnknown_081B6C30
.L080D9B1C: .4byte gUnknown_08580A60
.L080D9B20: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080D9B24: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9B28: .4byte gUnknown_0857D9C0
.L080D9B2C: .4byte 0x02024074 @ EWRAM+0x24074
.L080D9B30: .4byte 0x84000140

	thumb_func_start sub_080D9B34
sub_080D9B34: @ 0x080D9B34
.L080D9B34:
	push {lr}
	sub sp, #8
	ldr r1, .L080D9B5C
	movs r0, #0x1c
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #1
	movs r3, #1
	bl Tilemap_FillRect
	ldr r0, .L080D9B60
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D9B5C: .4byte 0x02024074 @ EWRAM+0x24074
.L080D9B60: .4byte sub_080D9A14

	thumb_func_start sub_080D9B64
sub_080D9B64: @ 0x080D9B64
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r5, #0x24
	ldr r2, [r5, #0x18]
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r4, #0x10
	str r4, [sp, #4]
	ldrh r1, [r0, #0x24]
	movs r0, #0xb
	muls r0, r1, r0
	adds r0, #0xe
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r2, #0
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	ldr r0, [r5, #0x14]
	movs r1, #0
	str r1, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080D9BAC
sub_080D9BAC: @ 0x080D9BAC
	ldr r1, .L080D9BC0
	ldr r0, .L080D9BC4
	str r0, [r1]
	ldr r0, .L080D9BC8
	str r0, [r1, #4]
	ldr r0, .L080D9BCC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D9BC0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9BC4: .4byte 0x02024074 @ EWRAM+0x24074
.L080D9BC8: .4byte 0x06002000 @ VRAM+0x2000
.L080D9BCC: .4byte 0x84000400

	thumb_func_start sub_080D9BD0
sub_080D9BD0: @ 0x080D9BD0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r0, r1, #0
	ldr r7, [sp, #0x2c]
	adds r6, r5, #0
	adds r6, #0x24
	ldr r1, .L080D9C18
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080D9C1C
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080D9C20
	str r0, [r5, #0x20]
	strh r7, [r5, #0x24]
	ldr r0, [sp, #0x24]
	str r0, [r6, #0x14]
	ldr r1, [sp, #0x28]
	str r1, [r6, #0x18]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080D9C18: .4byte 0x02024074 @ EWRAM+0x24074
.L080D9C1C: .4byte sub_080D9BAC
.L080D9C20: .4byte sub_080D9B64

	thumb_func_start sub_080D9C24
sub_080D9C24: @ 0x080D9C24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x24
	ldr r0, [r6, #0x18]
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x10
	str r1, [sp, #4]
	ldrh r2, [r4, #0x24]
	movs r1, #0xb
	muls r1, r2, r1
	adds r1, #0xe
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	movs r5, #0
	adds r4, #0x4f
	ldrb r4, [r4]
	cmp r5, r4
	bhs .L080D9CBA
	movs r7, #0
	ldr r0, .L080D9CC8
	mov r8, r0
.L080D9C66:
	ldr r1, .L080D9CCC
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r7, [sp]
	movs r1, #0x10
	str r1, [sp, #4]
	movs r1, #0xb
	adds r4, r5, #0
	muls r4, r1, r4
	adds r4, #0x11
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	adds r0, r6, #0
	adds r0, #0x24
	adds r0, r0, r5
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r7, [sp]
	movs r1, #0x20
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	adds r5, #1
	adds r0, r6, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r5, r0
	blo .L080D9C66
.L080D9CBA:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D9CC8: .4byte gUnknown_085814B4
.L080D9CCC: .4byte gUnknown_085814A0

	thumb_func_start sub_080D9CD0
sub_080D9CD0: @ 0x080D9CD0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r0, r1, #0
	ldr r7, [sp, #0x2c]
	adds r6, r5, #0
	adds r6, #0x24
	ldr r1, .L080D9D18
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080D9D1C
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080D9D20
	str r0, [r5, #0x20]
	strh r7, [r5, #0x24]
	ldr r0, [sp, #0x24]
	str r0, [r6, #0x14]
	ldr r1, [sp, #0x28]
	str r1, [r6, #0x18]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080D9D18: .4byte 0x02024074 @ EWRAM+0x24074
.L080D9D1C: .4byte sub_080D9BAC
.L080D9D20: .4byte sub_080D9C24

	thumb_func_start sub_080D9D24
sub_080D9D24: @ 0x080D9D24
.L080D9D24:
	ldr r1, .L080D9D38
	ldr r0, .L080D9D3C
	str r0, [r1]
	ldr r0, .L080D9D40
	str r0, [r1, #4]
	ldr r0, .L080D9D44
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D9D38: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D9D3C: .4byte 0x0201D874 @ EWRAM+0x1D874
.L080D9D40: .4byte 0x06001000 @ VRAM+0x1000
.L080D9D44: .4byte 0x84000400

	thumb_func_start sub_080D9D48
sub_080D9D48: @ 0x080D9D48
	push {r4, r5, lr}
	sub sp, #0x10
	adds r0, r1, #0
	ldr r4, [sp, #0x1c]
	ldr r5, [sp, #0x20]
	ldr r1, .L080D9D84
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #4]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #8]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080D9D88
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D9D84: .4byte 0x0201D874 @ EWRAM+0x1D874
.L080D9D88: .4byte sub_080D9D24

	thumb_func_start sub_080D9D8C
sub_080D9D8C: @ 0x080D9D8C
.L080D9D8C:
	push {lr}
	sub sp, #8
	ldr r1, .L080D9DB4
	movs r0, #0x1c
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #1
	movs r3, #1
	bl Tilemap_FillRect
	ldr r0, .L080D9DB8
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D9DB4: .4byte 0x0201D874 @ EWRAM+0x1D874
.L080D9DB8: .4byte sub_080D9D24

	thumb_func_start sub_080D9DBC
sub_080D9DBC: @ 0x080D9DBC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, [sp, #0x14]
	ldr r1, .L080D9DF8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #0
	adds r2, r4, #0
	adds r3, r5, #0
	bl Tilemap_FillRect
	ldr r0, .L080D9DFC
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D9DF8: .4byte 0x0201D874 @ EWRAM+0x1D874
.L080D9DFC: .4byte sub_080D9D24

	thumb_func_start sub_080D9E00
sub_080D9E00: @ 0x080D9E00
	ldr r0, .L080D9E1C
	strb r2, [r0]
	ldr r0, .L080D9E20
	strb r1, [r0]
	ldr r1, .L080D9E24
	movs r0, #0x58
	strb r0, [r1]
	ldr r1, .L080D9E28
	movs r0, #8
	strb r0, [r1]
	ldr r1, .L080D9E2C
	movs r0, #0x2b
	strb r0, [r1]
	bx lr
.L080D9E1C: .4byte 0x03000030 @ IWRAM+0x30
.L080D9E20: .4byte 0x03000031 @ IWRAM+0x31
.L080D9E24: .4byte 0x03000034 @ IWRAM+0x34
.L080D9E28: .4byte 0x03000035 @ IWRAM+0x35
.L080D9E2C: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080D9E30
sub_080D9E30: @ 0x080D9E30
	ldr r0, .L080D9E4C
	strb r2, [r0]
	ldr r0, .L080D9E50
	strb r1, [r0]
	ldr r0, .L080D9E54
	movs r1, #0x58
	strb r1, [r0]
	ldr r0, .L080D9E58
	strb r1, [r0]
	ldr r1, .L080D9E5C
	movs r0, #0x2b
	strb r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080D9E4C: .4byte 0x03000030 @ IWRAM+0x30
.L080D9E50: .4byte 0x03000031 @ IWRAM+0x31
.L080D9E54: .4byte 0x03000034 @ IWRAM+0x34
.L080D9E58: .4byte 0x03000035 @ IWRAM+0x35
.L080D9E5C: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080D9E60
sub_080D9E60: @ 0x080D9E60
	ldr r2, .L080D9E6C
	ldrb r0, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080D9E6C: .4byte 0x03000035 @ IWRAM+0x35

	thumb_func_start sub_080D9E70
sub_080D9E70: @ 0x080D9E70
	ldr r1, .L080D9E90
	movs r0, #0xe8
	strb r0, [r1]
	ldr r0, .L080D9E94
	movs r2, #8
	strb r2, [r0]
	ldr r1, .L080D9E98
	movs r0, #0x98
	strb r0, [r1]
	ldr r0, .L080D9E9C
	strb r2, [r0]
	ldr r1, .L080D9EA0
	movs r0, #0x29
	strb r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080D9E90: .4byte 0x03000030 @ IWRAM+0x30
.L080D9E94: .4byte 0x03000031 @ IWRAM+0x31
.L080D9E98: .4byte 0x03000034 @ IWRAM+0x34
.L080D9E9C: .4byte 0x03000035 @ IWRAM+0x35
.L080D9EA0: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080D9EA4
sub_080D9EA4: @ 0x080D9EA4
	ldr r1, .L080D9EC4
	movs r0, #0xe8
	strb r0, [r1]
	ldr r1, .L080D9EC8
	movs r0, #8
	strb r0, [r1]
	ldr r0, .L080D9ECC
	movs r1, #0x98
	strb r1, [r0]
	ldr r0, .L080D9ED0
	strb r1, [r0]
	ldr r1, .L080D9ED4
	movs r0, #0x29
	strb r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080D9EC4: .4byte 0x03000030 @ IWRAM+0x30
.L080D9EC8: .4byte 0x03000031 @ IWRAM+0x31
.L080D9ECC: .4byte 0x03000034 @ IWRAM+0x34
.L080D9ED0: .4byte 0x03000035 @ IWRAM+0x35
.L080D9ED4: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080D9ED8
sub_080D9ED8: @ 0x080D9ED8
	ldr r2, .L080D9EE4
	ldrb r0, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080D9EE4: .4byte 0x03000035 @ IWRAM+0x35

	thumb_func_start sub_080D9EE8
sub_080D9EE8: @ 0x080D9EE8
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	bne .L080D9F0C
	str r0, [sp]
	movs r0, #2
	movs r1, #0xc
	movs r2, #0x1a
	movs r3, #6
	bl Window_Create
	str r0, [r4, #0x1c]
	ldrh r1, [r5, #2]
	strh r1, [r0, #4]
.L080D9F0C:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080D9F14
sub_080D9F14: @ 0x080D9F14
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	bne .L080D9F38
	str r0, [sp]
	movs r0, #2
	movs r1, #0xc
	movs r2, #0x1a
	movs r3, #6
	bl Window_CreateOpen
	str r0, [r4, #0x1c]
	ldrh r1, [r5, #2]
	strh r1, [r0, #4]
.L080D9F38:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080D9F40
sub_080D9F40: @ 0x080D9F40
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r5, #0x24
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	beq .L080D9F56
	movs r4, #0
	str r4, [r0, #0x20]
	bl Window_Close
	str r4, [r5, #0x1c]
.L080D9F56:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080D9F5C
sub_080D9F5C: @ 0x080D9F5C
	push {lr}
	ldr r1, [r0, #0x40]
	cmp r1, #0
	beq .L080D9F68
	movs r0, #0
	str r0, [r1, #0x20]
.L080D9F68:
	pop {r0}
	bx r0

	thumb_func_start sub_080D9F6C
sub_080D9F6C: @ 0x080D9F6C
	push {lr}
	ldr r0, [r0, #0x40]
	cmp r0, #0
	beq .L080D9F76
	str r1, [r0, #0x20]
.L080D9F76:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D9F7C
sub_080D9F7C: @ 0x080D9F7C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	ldr r0, [r5, #4]
	movs r6, #0
	str r6, [sp]
	movs r1, #0xb8
	str r1, [sp, #4]
	movs r1, #0x78
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D9FE4
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0xbd
	str r1, [sp, #4]
	ldrh r2, [r4, #0x24]
	movs r1, #0xb
	muls r1, r2, r1
	adds r1, #0x7a
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	ldr r1, [r5, #8]
	ldr r0, .L080D9FE8
	cmp r1, r0
	bne .L080D9FEC
	str r6, [sp]
	movs r0, #0xbb
	str r0, [sp, #4]
	movs r0, #0x79
	str r0, [sp, #8]
	adds r0, r1, #0
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	b .L080DA002
	.byte 0x00, 0x00
.L080D9FE4: .4byte gUnknown_080083DC
.L080D9FE8: .4byte gUnknown_080083C4
.L080D9FEC:
	str r6, [sp]
	movs r0, #0xbb
	str r0, [sp, #4]
	movs r0, #0x7d
	str r0, [sp, #8]
	adds r0, r1, #0
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
.L080DA002:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080DA00C
sub_080DA00C: @ 0x080DA00C
	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r4, .L080DA038
	ldrh r1, [r4]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DA040
	ldr r0, .L080DA03C
	ldrh r1, [r2, #0x24]
	str r1, [r0]
	strh r3, [r2, #0x1c]
	cmp r1, #0
	bne .L080DA050
	movs r0, #0x65
	bl sub_080C51D4
	b .L080DA078
	.byte 0x00, 0x00
.L080DA038: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DA03C: .4byte 0x030031CC @ IWRAM+0x31CC
.L080DA040:
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DA05C
	ldr r0, .L080DA058
	str r3, [r0]
	strh r3, [r2, #0x1c]
.L080DA050:
	movs r0, #0x66
	bl sub_080C51D4
	b .L080DA078
.L080DA058: .4byte 0x030031CC @ IWRAM+0x31CC
.L080DA05C:
	ldr r0, .L080DA080
	ldrh r1, [r0]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq .L080DA078
	ldrh r0, [r2, #0x24]
	adds r0, #1
	movs r1, #1
	ands r0, r1
	strh r0, [r2, #0x24]
	movs r0, #0x64
	bl sub_080C51D4
.L080DA078:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DA080: .4byte 0x03003964 @ IWRAM+0x3964

	thumb_func_start sub_080DA084
sub_080DA084: @ 0x080DA084
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, .L080DA0A0
	ldrh r1, [r3, #2]
	bl Task_Create
	adds r0, #0x24
	str r4, [r0, #4]
	str r5, [r0, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080DA0A0: .4byte gUnknown_08581568

	thumb_func_start sub_080DA0A4
sub_080DA0A4: @ 0x080DA0A4
	ldr r1, .L080DA0AC
	ldr r1, [r1]
	strh r1, [r0, #0x1e]
	bx lr
.L080DA0AC: .4byte 0x030031CC @ IWRAM+0x31CC

	thumb_func_start sub_080DA0B0
sub_080DA0B0: @ 0x080DA0B0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r4, #0
	adds r3, #0x4f
	ldrb r6, [r3]
	adds r7, r6, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldr r2, .L080DA0E0
	ldrh r1, [r2]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DA0E4
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r1, [r4, #0x24]
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r4, #0x1e]
	movs r0, #0x65
	b .L080DA0FA
	.byte 0x00, 0x00
.L080DA0E0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DA0E4:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DA102
	ldrb r0, [r3]
	subs r0, #1
	strh r0, [r4, #0x24]
	movs r0, #5
	strh r0, [r4, #0x1e]
	movs r0, #0x66
.L080DA0FA:
	bl sub_080C51D4
	strh r5, [r4, #0x1c]
	b .L080DA14A
.L080DA102:
	ldr r0, .L080DA11C
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L080DA12C
	ldrh r0, [r4, #0x24]
	cmp r0, #0
	beq .L080DA120
	subs r0, #1
	b .L080DA122
.L080DA11C: .4byte 0x03003964 @ IWRAM+0x3964
.L080DA120:
	subs r0, r6, #1
.L080DA122:
	strh r0, [r4, #0x24]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DA14A
.L080DA12C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080DA14A
	ldrh r1, [r4, #0x24]
	subs r0, r7, #1
	cmp r1, r0
	beq .L080DA142
	adds r0, r1, #1
	strh r0, [r4, #0x24]
	b .L080DA144
.L080DA142:
	strh r2, [r4, #0x24]
.L080DA144:
	movs r0, #0x64
	bl sub_080C51D4
.L080DA14A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080DA150
sub_080DA150: @ 0x080DA150
	push {lr}
	sub sp, #8
	bl Task_GetParent
	ldrh r3, [r0, #0x24]
	adds r0, #0x48
	adds r0, r0, r3
	ldrb r1, [r0]
	subs r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, .L080DA18C
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0x64
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x14
	bl Text_DrawSpriteString
	add sp, #8
	pop {r0}
	bx r0
.L080DA18C: .4byte gUnknown_08581598

	thumb_func_start sub_080DA190
sub_080DA190: @ 0x080DA190
	push {lr}
	ldr r1, .L080DA1A8
	ldr r2, .L080DA1AC
	adds r0, r1, r2
	ldr r0, [r0]
	bl SaveSlot_Write
	ldr r0, .L080DA1B0
	bl SetMainCallback
	pop {r0}
	bx r0
.L080DA1A8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080DA1AC: .4byte 0x000018B0
.L080DA1B0: .4byte sub_080DE78C

	thumb_func_start sub_080DA1B4
sub_080DA1B4: @ 0x080DA1B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r5, #0
	adds r7, r4, #0
	adds r7, #0x24
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080DA1F0
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080DA1F0
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r6, r4, #0
	adds r6, #0x48
	cmp r0, #1
	bne .L080DA1FE
.L080DA1F0:
	adds r2, r7, #0
	adds r2, #0x24
	adds r1, r2, r5
	movs r0, #1
	strb r0, [r1]
	adds r5, #1
	adds r6, r2, #0
.L080DA1FE:
	movs r4, #0
	adds r7, #0x2b
	mov r8, r7
	b .L080DA208
.L080DA206:
	adds r4, #1
.L080DA208:
	ldr r0, .L080DA228
	cmp r4, r0
	bhi .L080DA220
	adds r0, r4, #0
	bl sub_080C2644
	cmp r0, #0
	beq .L080DA206
	adds r1, r6, r5
	movs r0, #2
	strb r0, [r1]
	adds r5, #1
.L080DA220:
	movs r4, #0
	movs r7, #3
	b .L080DA22E
	.byte 0x00, 0x00
.L080DA228: .4byte 0x0000017B
.L080DA22C:
	adds r4, #1
.L080DA22E:
	cmp r4, #0x3f
	bhi .L080DA246
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, r1
	bl sub_080C2734
	cmp r0, #0
	beq .L080DA22C
	adds r0, r6, r5
	strb r7, [r0]
	adds r5, #1
.L080DA246:
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080DA270
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080DA270
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080DA278
.L080DA270:
	adds r1, r6, r5
	movs r0, #4
	strb r0, [r1]
	adds r5, #1
.L080DA278:
	adds r1, r6, r5
	movs r0, #5
	strb r0, [r1]
	adds r5, #1
	mov r0, r8
	strb r5, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080DA290
sub_080DA290: @ 0x080DA290
	ldr r1, .L080DA2A4
	ldr r0, .L080DA2A8
	str r0, [r1]
	ldr r0, .L080DA2AC
	str r0, [r1, #4]
	ldr r0, .L080DA2B0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080DA2A4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DA2A8: .4byte 0x0600CC00 @ VRAM+0xCC00
.L080DA2AC: .4byte 0x06012800 @ VRAM+0x12800
.L080DA2B0: .4byte 0x84000800

	thumb_func_start sub_080DA2B4
sub_080DA2B4: @ 0x080DA2B4
	push {lr}
	sub sp, #4
	ldr r1, .L080DA2DC
	ldr r2, .L080DA2E0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080DA2E4
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DA2DC: .4byte gUnknown_08580880
.L080DA2E0: .4byte 0x030030F0 @ IWRAM+0x30F0
.L080DA2E4: .4byte sub_080DA290

	thumb_func_start sub_080DA2E8
sub_080DA2E8: @ 0x080DA2E8
	push {r4, lr}
	ldr r4, [sp, #8]
	ldr r0, .L080DA308
	strb r4, [r0]
	ldr r0, .L080DA30C
	strb r3, [r0]
	ldr r0, .L080DA310
	strb r2, [r0]
	ldr r0, .L080DA314
	strb r1, [r0]
	ldr r1, .L080DA318
	movs r0, #0x2f
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L080DA308: .4byte 0x03000030 @ IWRAM+0x30
.L080DA30C: .4byte 0x03000031 @ IWRAM+0x31
.L080DA310: .4byte 0x03000034 @ IWRAM+0x34
.L080DA314: .4byte 0x03000035 @ IWRAM+0x35
.L080DA318: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080DA31C
sub_080DA31C: @ 0x080DA31C
	ldr r1, .L080DA324
	movs r0, #0x3f
	strb r0, [r1]
	bx lr
.L080DA324: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080DA328
sub_080DA328: @ 0x080DA328
	push {r4, lr}
	ldr r4, [sp, #8]
	ldr r0, .L080DA348
	strb r4, [r0]
	ldr r0, .L080DA34C
	strb r3, [r0]
	ldr r0, .L080DA350
	strb r2, [r0]
	ldr r0, .L080DA354
	strb r1, [r0]
	ldr r1, .L080DA358
	movs r0, #0x2f
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L080DA348: .4byte 0x03000032 @ IWRAM+0x32
.L080DA34C: .4byte 0x03000033 @ IWRAM+0x33
.L080DA350: .4byte 0x03000036 @ IWRAM+0x36
.L080DA354: .4byte 0x03000037 @ IWRAM+0x37
.L080DA358: .4byte 0x03000039 @ IWRAM+0x39

	thumb_func_start sub_080DA35C
sub_080DA35C: @ 0x080DA35C
	ldr r1, .L080DA364
	movs r0, #0x3f
	strb r0, [r1]
	bx lr
.L080DA364: .4byte 0x03000039 @ IWRAM+0x39

	thumb_func_start sub_080DA368
sub_080DA368: @ 0x080DA368
	ldr r1, .L080DA370
	movs r0, #0
	str r0, [r1]
	bx lr
.L080DA370: .4byte 0x03006098 @ IWRAM+0x6098

	thumb_func_start sub_080DA374
sub_080DA374: @ 0x080DA374
	push {lr}
	adds r2, r1, #0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	bl Task_Create
	ldr r1, .L080DA388
	str r0, [r1]
	pop {r0}
	bx r0
.L080DA388: .4byte 0x03006098 @ IWRAM+0x6098

	thumb_func_start sub_080DA38C
sub_080DA38C: @ 0x080DA38C
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080DA3A8
	ldr r0, [r0]
	cmp r0, #0
	beq .L080DA3AC
	ldr r1, [r0, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080DA3AC
	movs r0, #1
	b .L080DA3AE
	.byte 0x00, 0x00
.L080DA3A8: .4byte 0x03006098 @ IWRAM+0x6098
.L080DA3AC:
	movs r0, #0
.L080DA3AE:
	strh r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080DA3B4
sub_080DA3B4: @ 0x080DA3B4
	push {lr}
	ldr r0, .L080DA3D0
	ldr r2, [r0]
	cmp r2, #0
	beq .L080DA3CC
	ldr r1, [r2, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080DA3CC
	movs r0, #1
	str r0, [r2, #0xc]
.L080DA3CC:
	pop {r0}
	bx r0
.L080DA3D0: .4byte 0x03006098 @ IWRAM+0x6098

	thumb_func_start sub_080DA3D4
sub_080DA3D4: @ 0x080DA3D4
	push {r4, lr}
	ldr r4, .L080DA3F8
	ldr r0, [r4]
	cmp r0, #0
	beq .L080DA3F0
	bl Task_End
	movs r0, #0
	str r0, [r4]
	ldr r0, .L080DA3FC
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080DA400
	strb r1, [r0]
.L080DA3F0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DA3F8: .4byte 0x03006098 @ IWRAM+0x6098
.L080DA3FC: .4byte 0x03000038 @ IWRAM+0x38
.L080DA400: .4byte 0x03000039 @ IWRAM+0x39

	thumb_func_start sub_080DA404
sub_080DA404: @ 0x080DA404
	push {lr}
	sub sp, #0xc
	ldr r0, .L080DA434
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080DA43C
	ldr r0, .L080DA438
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x63
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xa
	movs r3, #0
	bl Sprite_Draw
	b .L080DA456
	.byte 0x00, 0x00
.L080DA434: .4byte 0x030031BC @ IWRAM+0x31BC
.L080DA438: .4byte gUnknown_08008D28
.L080DA43C:
	ldr r0, .L080DA45C
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x63
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xa
	movs r3, #0
	bl Sprite_Draw
.L080DA456:
	add sp, #0xc
	pop {r0}
	bx r0
.L080DA45C: .4byte gUnknown_08008E20

	thumb_func_start sub_080DA460
sub_080DA460: @ 0x080DA460
	push {lr}
	sub sp, #0xc
	ldr r0, .L080DA490
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080DA498
	ldr r0, .L080DA494
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x63
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xa
	movs r3, #0
	bl Sprite_Draw
	b .L080DA4B2
	.byte 0x00, 0x00
.L080DA490: .4byte 0x030031BC @ IWRAM+0x31BC
.L080DA494: .4byte gUnknown_08008DA4
.L080DA498:
	ldr r0, .L080DA4B8
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x63
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xa
	movs r3, #0
	bl Sprite_Draw
.L080DA4B2:
	add sp, #0xc
	pop {r0}
	bx r0
.L080DA4B8: .4byte gUnknown_08008EC8

	thumb_func_start sub_080DA4BC
sub_080DA4BC: @ 0x080DA4BC
	push {lr}
	sub sp, #0xc
	ldr r0, .L080DA4EC
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080DA4F4
	ldr r0, .L080DA4F0
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x63
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xa
	movs r3, #0
	bl Sprite_Draw
	b .L080DA50E
	.byte 0x00, 0x00
.L080DA4EC: .4byte 0x030031BC @ IWRAM+0x31BC
.L080DA4F0: .4byte gUnknown_08008DD8
.L080DA4F4:
	ldr r0, .L080DA514
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x63
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xa
	movs r3, #0
	bl Sprite_Draw
.L080DA50E:
	add sp, #0xc
	pop {r0}
	bx r0
.L080DA514: .4byte gUnknown_08008F10

	thumb_func_start sub_080DA518
sub_080DA518: @ 0x080DA518
	push {lr}
	sub sp, #0xc
	ldr r0, .L080DA548
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080DA550
	ldr r0, .L080DA54C
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x63
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xa
	movs r3, #0
	bl Sprite_Draw
	b .L080DA56A
	.byte 0x00, 0x00
.L080DA548: .4byte 0x030031BC @ IWRAM+0x31BC
.L080DA54C: .4byte gUnknown_08008D7C
.L080DA550:
	ldr r0, .L080DA570
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x63
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xa
	movs r3, #0
	bl Sprite_Draw
.L080DA56A:
	add sp, #0xc
	pop {r0}
	bx r0
.L080DA570: .4byte gUnknown_08008E8C

	thumb_func_start sub_080DA574
sub_080DA574: @ 0x080DA574
.L080DA574:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r0, .L080DA5D4
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080DA5CA
	ldr r6, .L080DA5D8
	movs r5, #0xa0
	lsls r5, r5, #2
	str r5, [sp]
	movs r4, #0x12
	str r4, [sp, #4]
	movs r0, #0x5b
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0x63
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0x6b
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080DA5CA:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DA5D4: .4byte 0x030031BC @ IWRAM+0x31BC
.L080DA5D8: .4byte gUnknown_08002BE8

	thumb_func_start sub_080DA5DC
sub_080DA5DC: @ 0x080DA5DC
	push {lr}
	sub sp, #0xc
	ldr r0, .L080DA604
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_080DA574
	add sp, #0xc
	pop {r0}
	bx r0
.L080DA604: .4byte gUnknown_08002B34

	thumb_func_start sub_080DA608
sub_080DA608: @ 0x080DA608
	push {lr}
	sub sp, #0xc
	ldr r0, .L080DA630
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_080DA574
	add sp, #0xc
	pop {r0}
	bx r0
.L080DA630: .4byte gUnknown_08002B68

	thumb_func_start sub_080DA634
sub_080DA634: @ 0x080DA634
	ldr r1, .L080DA648
	ldr r0, .L080DA64C
	str r0, [r1]
	ldr r0, .L080DA650
	str r0, [r1, #4]
	ldr r0, .L080DA654
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080DA648: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DA64C: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080DA650: .4byte 0x06015000 @ VRAM+0x15000
.L080DA654: .4byte 0x84000200

	thumb_func_start sub_080DA658
sub_080DA658: @ 0x080DA658
	push {lr}
	ldr r0, .L080DA670
	ldr r1, .L080DA674
	bl LZ77UnCompWram
	ldr r0, .L080DA678
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DA670: .4byte gUnknown_081B6A64
.L080DA674: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080DA678: .4byte sub_080DA634

	thumb_func_start sub_080DA67C
sub_080DA67C: @ 0x080DA67C
	push {lr}
	sub sp, #0xc
	ldr r0, .L080DA6A4
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_080DA574
	add sp, #0xc
	pop {r0}
	bx r0
.L080DA6A4: .4byte gUnknown_08002BA4

	thumb_func_start sub_080DA6A8
sub_080DA6A8: @ 0x080DA6A8
	push {lr}
	sub sp, #0xc
	ldr r0, .L080DA6D0
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0x12
	str r1, [sp, #4]
	movs r1, #0x5b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_080DA574
	add sp, #0xc
	pop {r0}
	bx r0
.L080DA6D0: .4byte gUnknown_08002BD8

	thumb_func_start sub_080DA6D4
sub_080DA6D4: @ 0x080DA6D4
	ldr r1, .L080DA6E8
	ldr r0, .L080DA6EC
	str r0, [r1]
	ldr r0, .L080DA6F0
	str r0, [r1, #4]
	ldr r0, .L080DA6F4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080DA6E8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DA6EC: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080DA6F0: .4byte 0x06015000 @ VRAM+0x15000
.L080DA6F4: .4byte 0x84000200

	thumb_func_start sub_080DA6F8
sub_080DA6F8: @ 0x080DA6F8
	push {lr}
	ldr r0, .L080DA710
	ldr r1, .L080DA714
	bl LZ77UnCompWram
	ldr r0, .L080DA718
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DA710: .4byte gUnknown_081B6A64
.L080DA714: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080DA718: .4byte sub_080DA6D4

	thumb_func_start sub_080DA71C
sub_080DA71C: @ 0x080DA71C
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080DA738
	ldrh r0, [r0]
	ldr r1, .L080DA73C
	ands r1, r0
	cmp r1, #0
	beq .L080DA740
	movs r0, #1
	strh r0, [r2, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	b .L080DA75C
.L080DA738: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DA73C: .4byte 0x000003FF
.L080DA740:
	strh r1, [r2, #0x1c]
	ldr r0, .L080DA760
	ldr r0, [r0]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080DA75C
	movs r0, #0
	movs r1, #0
	movs r2, #0xd5
	movs r3, #0x85
	bl sub_080C4AB0
.L080DA75C:
	pop {r0}
	bx r0
.L080DA760: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_080DA764
sub_080DA764: @ 0x080DA764
.L080DA764:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	ldr r0, .L080DA7C4
	movs r1, #0
	mov r8, r1
	str r1, [sp]
	str r6, [sp, #4]
	str r7, [sp, #8]
	movs r1, #6
	movs r2, #7
	movs r3, #1
	bl Sprite_Draw
	adds r0, r4, #0
	bl NumberToDigits
	adds r5, r0, #0
	cmp r4, #0x63
	bls .L080DA7CC
	ldr r4, .L080DA7C8
	ldrb r0, [r5, #2]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, #0
	adds r1, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r7, [sp, #8]
	movs r1, #6
	movs r2, #7
	movs r3, #1
	bl Sprite_Draw
	b .L080DA7D2
	.byte 0x00, 0x00
.L080DA7C4: .4byte gUnknown_08008F58
.L080DA7C8: .4byte gUnknown_08582410
.L080DA7CC:
	cmp r4, #9
	bls .L080DA81C
	ldr r4, .L080DA818
.L080DA7D2:
	ldrb r0, [r5, #1]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, #0
	adds r1, #0x1e
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r7, [sp, #8]
	movs r1, #6
	movs r2, #7
	movs r3, #1
	bl Sprite_Draw
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, #0
	adds r1, #0x24
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r7, [sp, #8]
	movs r1, #6
	movs r2, #7
	movs r3, #1
	bl Sprite_Draw
	b .L080DA840
.L080DA818: .4byte gUnknown_08582410
.L080DA81C:
	ldr r1, .L080DA8C4
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, #0
	adds r1, #0x24
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r7, [sp, #8]
	movs r1, #6
	movs r2, #7
	movs r3, #1
	bl Sprite_Draw
.L080DA840:
	ldr r0, .L080DA8C8
	movs r1, #0
	mov r8, r1
	str r1, [sp]
	adds r1, r6, #0
	adds r1, #0x2a
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r7, [sp, #8]
	movs r1, #6
	movs r2, #7
	movs r3, #1
	bl Sprite_Draw
	mov r0, sb
	bl NumberToDigits
	adds r5, r0, #0
	mov r0, sb
	cmp r0, #0x63
	bls .L080DA8CC
	ldr r4, .L080DA8C4
	ldrb r0, [r5, #2]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, #0
	adds r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r7, [sp, #8]
	movs r1, #6
	movs r2, #7
	movs r3, #1
	bl Sprite_Draw
	ldrb r0, [r5, #1]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, #0
	adds r1, #0x36
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r7, [sp, #8]
	movs r1, #6
	movs r2, #7
	movs r3, #1
	bl Sprite_Draw
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, #0
	adds r1, #0x3c
	b .L080DA906
.L080DA8C4: .4byte gUnknown_08582410
.L080DA8C8: .4byte gUnknown_08008F68
.L080DA8CC:
	mov r0, sb
	cmp r0, #9
	bls .L080DA920
	ldr r4, .L080DA91C
	ldrb r0, [r5, #1]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, #0
	adds r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r7, [sp, #8]
	movs r1, #6
	movs r2, #7
	movs r3, #1
	bl Sprite_Draw
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, #0
	adds r1, #0x36
.L080DA906:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r7, [sp, #8]
	movs r1, #6
	movs r2, #7
	movs r3, #1
	bl Sprite_Draw
	b .L080DA944
	.byte 0x00, 0x00
.L080DA91C: .4byte gUnknown_08582410
.L080DA920:
	ldr r1, .L080DA954
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, #0
	adds r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r7, [sp, #8]
	movs r1, #6
	movs r2, #7
	movs r3, #1
	bl Sprite_Draw
.L080DA944:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DA954: .4byte gUnknown_08582410

	thumb_func_start sub_080DA958
sub_080DA958: @ 0x080DA958
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L080DA9A4
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	str r4, [r1, #0x78]
	adds r1, #0x80
	ldr r0, [r4, #0x20]
	str r0, [r1]
	ldr r2, .L080DA9A8
	ldrh r1, [r2]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DA9AC
	ldrh r0, [r4, #0x24]
	adds r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #0x65
	bl sub_080C51D4
	strh r5, [r4, #0x1c]
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne .L080DAA06
	movs r0, #1
	bl sub_080DABCC
	bl sub_080DAC4C
	cmp r0, #0
	bne .L080DAA06
	movs r0, #3
	strh r0, [r4, #0x1e]
	b .L080DAA06
	.byte 0x00, 0x00
.L080DA9A4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080DA9A8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DA9AC:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DA9C0
	movs r0, #0x66
	bl sub_080C51D4
	strh r5, [r4, #0x1c]
	b .L080DAA06
.L080DA9C0:
	ldr r0, .L080DA9DC
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L080DA9EA
	ldrh r0, [r4, #0x24]
	cmp r0, #0
	beq .L080DA9E0
	subs r0, #1
	strh r0, [r4, #0x24]
	b .L080DA9E2
.L080DA9DC: .4byte 0x03003964 @ IWRAM+0x3964
.L080DA9E0:
	strh r5, [r4, #0x24]
.L080DA9E2:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DAA06
.L080DA9EA:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080DAA06
	ldrh r0, [r4, #0x24]
	cmp r0, #1
	beq .L080DA9FE
	adds r0, #1
	strh r0, [r4, #0x24]
	b .L080DAA00
.L080DA9FE:
	strh r2, [r4, #0x24]
.L080DAA00:
	movs r0, #0x64
	bl sub_080C51D4
.L080DAA06:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080DAA0C
sub_080DAA0C: @ 0x080DAA0C
	push {lr}
	sub sp, #8
	bl Task_GetParent
	ldr r1, .L080DAA38
	ldrh r0, [r0, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x64
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x14
	bl Text_DrawSpriteString
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DAA38: .4byte gUnknown_08582438

	thumb_func_start sub_080DAA3C
sub_080DAA3C: @ 0x080DAA3C
	push {lr}
	sub sp, #8
	ldr r0, .L080DAA5C
	movs r1, #0x64
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x14
	bl Text_DrawSpriteString
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DAA5C: .4byte gUnknown_08009550

	thumb_func_start sub_080DAA60
sub_080DAA60: @ 0x080DAA60
	ldr r1, .L080DAA6C
	ldr r2, .L080DAA70
	adds r0, r2, #0
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080DAA6C: .4byte 0x0400000E @ REG_BG3CNT
.L080DAA70: .4byte 0x00008607

	thumb_func_start sub_080DAA74
sub_080DAA74: @ 0x080DAA74
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L080DAA84
	ands r0, r1
	strh r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080DAA84: .4byte 0x0000F7FF

	thumb_func_start sub_080DAA88
sub_080DAA88: @ 0x080DAA88
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080DAA9C
sub_080DAA9C: @ 0x080DAA9C
	ldr r1, .L080DAAA4
	movs r0, #0x3f
	strb r0, [r1]
	bx lr
.L080DAAA4: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080DAAA8
sub_080DAAA8: @ 0x080DAAA8
	push {r4, lr}
	sub sp, #4
	ldr r4, .L080DAAD8
	ldr r0, .L080DAADC
	adds r1, r4, #0
	stm r1!, {r0}
	ldr r0, .L080DAAE0
	ldr r2, .L080DAAE4
	bl CpuSet
	movs r0, #0
	str r0, [r4, #0x34]
	str r0, [sp]
	adds r4, #0x38
	ldr r2, .L080DAAE8
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DAAD8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080DAADC: .4byte 0x13240800
.L080DAAE0: .4byte 0x03006090 @ IWRAM+0x6090
.L080DAAE4: .4byte 0x04000002 @ IO+0x2
.L080DAAE8: .4byte 0x05000002 @ PLTT+0x2

	thumb_func_start sub_080DAAEC
sub_080DAAEC: @ 0x080DAAEC
	push {lr}
	ldr r1, .L080DAB00
	adds r2, r1, #0
	adds r2, #0x34
	movs r0, #0xc
	bl sub_080DF954
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DAB00: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080DAB04
sub_080DAB04: @ 0x080DAB04
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080DAB18
	ldr r1, [r0, #0x34]
	ldr r0, .L080DAB1C
	cmp r1, r0
	bne .L080DAB20
	movs r0, #1
	b .L080DAB22
	.byte 0x00, 0x00
.L080DAB18: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080DAB1C: .4byte 0x13240800
.L080DAB20:
	movs r0, #0
.L080DAB22:
	strh r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080DAB28
sub_080DAB28: @ 0x080DAB28
	push {r4, r5, r6, lr}
	ldr r0, .L080DAB7C
	adds r6, r0, #0
	adds r6, #0x38
	movs r5, #0
.L080DAB32:
	lsrs r0, r5, #3
	adds r0, r6, r0
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r5
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq .L080DAB62
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080DAB62
	adds r0, r4, #0
	bl sub_080C3328
.L080DAB62:
	adds r5, #1
	cmp r5, #0x3f
	bls .L080DAB32
	ldr r1, .L080DAB80
	ldr r2, .L080DAB84
	adds r0, r1, r2
	ldr r0, [r0]
	bl SaveSlot_Write
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DAB7C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080DAB80: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080DAB84: .4byte 0x000018B0

	thumb_func_start sub_080DAB88
sub_080DAB88: @ 0x080DAB88
	push {r4, lr}
	ldr r4, .L080DABC8
	movs r0, #1
	bl sub_080DABCC
	bl sub_080AE2D0
	ldr r0, [r4]
	cmp r0, #0
	bne .L080DABC0
	ldr r0, [r4, #4]
	cmp r0, #0
	bne .L080DABC0
	movs r0, #0x62
	strb r0, [r4]
	movs r0, #0x7d
	strb r0, [r4, #1]
	movs r0, #0x33
	strb r0, [r4, #2]
	movs r0, #0x80
	strb r0, [r4, #3]
	movs r0, #0xff
	strb r0, [r4, #4]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4, #5]
	strb r0, [r4, #6]
	strb r0, [r4, #7]
.L080DABC0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DABC8: .4byte 0x03004740 @ IWRAM+0x4740

	thumb_func_start sub_080DABCC
sub_080DABCC: @ 0x080DABCC
.L080DABCC:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r6, .L080DAC08
	movs r7, #0
	str r7, [sp]
	ldr r2, .L080DAC0C
	mov r0, sp
	adds r1, r6, #0
	bl CpuSet
	cmp r4, #0
	bne .L080DAC10
	movs r5, #0
.L080DABE8:
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r0, r4, #0
	bl sub_080C2734
	cmp r0, #0
	beq .L080DABFE
	strh r4, [r6]
	adds r6, #2
	adds r7, #1
.L080DABFE:
	adds r5, #1
	cmp r5, #0x3f
	bls .L080DABE8
	b .L080DAC40
	.byte 0x00, 0x00
.L080DAC08: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080DAC0C: .4byte 0x05000040 @ PLTT+0x40
.L080DAC10:
	movs r0, #0x2e
	mov ip, r0
	movs r5, #0
	movs r4, #0x96
	lsls r4, r4, #1
	movs r3, #0x9b
	lsls r3, r3, #1
	movs r2, #0xa9
	lsls r2, r2, #1
	movs r1, #0xab
	lsls r1, r1, #1
.L080DAC26:
	adds r0, r5, r4
	cmp r0, r3
	beq .L080DAC3A
	cmp r0, r2
	beq .L080DAC3A
	cmp r0, r1
	beq .L080DAC3A
	strh r0, [r6]
	adds r6, #2
	adds r7, #1
.L080DAC3A:
	adds r5, #1
	cmp r5, ip
	blo .L080DAC26
.L080DAC40:
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080DAC4C
sub_080DAC4C: @ 0x080DAC4C
.L080DAC4C:
	push {lr}
	movs r3, #0
	movs r2, #0
	ldr r1, .L080DAC6C
.L080DAC54:
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080DAC5C
	adds r3, #1
.L080DAC5C:
	adds r1, #2
	adds r2, #1
	cmp r2, #0x3f
	bls .L080DAC54
	adds r0, r3, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080DAC6C: .4byte 0x0203B454 @ EWRAM+0x3B454

	thumb_func_start sub_080DAC70
sub_080DAC70: @ 0x080DAC70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x24
	ldr r4, .L080DACDC
	ldr r0, .L080DACE0
	mov r8, r0
	bl sub_080DAC4C
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r1, #0
	str r5, [r4, #0x7c]
	adds r4, #0x84
	ldr r0, [r5, #0x20]
	str r0, [r4]
	strh r1, [r5, #0x1c]
	strh r1, [r5, #0x1e]
	mov ip, r7
	cmp r7, #5
	bls .L080DACA2
	movs r1, #6
	mov ip, r1
.L080DACA2:
	ldr r2, .L080DACE4
	ldrh r1, [r2]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DACF0
	ldrh r0, [r5, #0x24]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	bl sub_080C2734
	cmp r0, #0
	beq .L080DACE8
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldrh r0, [r6, #2]
	ldrh r1, [r5, #0x24]
	adds r0, r0, r1
	adds r0, #1
	strh r0, [r5, #0x1e]
	movs r0, #0x65
	b .L080DACFC
	.byte 0x00, 0x00
.L080DACDC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080DACE0: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080DACE4: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DACE8:
	movs r0, #0x66
	bl sub_080C51D4
	b .L080DADEE
.L080DACF0:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DAD04
	movs r0, #0x66
.L080DACFC:
	bl sub_080C51D4
	strh r4, [r5, #0x1c]
	b .L080DADEE
.L080DAD04:
	ldr r1, .L080DAD24
	ldrh r2, [r1]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L080DAD34
	ldrh r0, [r5, #0x24]
	cmp r0, #0
	beq .L080DAD28
	subs r0, #1
.L080DAD18:
	strh r0, [r5, #0x24]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DAD9A
	.byte 0x00, 0x00
.L080DAD24: .4byte 0x03003964 @ IWRAM+0x3964
.L080DAD28:
	ldrh r0, [r6, #2]
	cmp r0, #0
	beq .L080DAD9A
	subs r0, #1
	strh r0, [r6, #2]
	b .L080DAD94
.L080DAD34:
	movs r0, #0x80
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq .L080DAD64
	ldrh r1, [r5, #0x24]
	mov r0, ip
	subs r0, #1
	cmp r1, r0
	beq .L080DAD4E
	adds r0, r1, #1
	b .L080DAD18
.L080DAD4E:
	cmp r1, #5
	bne .L080DAD9A
	ldrh r2, [r6, #2]
	adds r0, r1, r2
	adds r0, #1
	subs r1, r7, #1
	cmp r0, r1
	bgt .L080DAD9A
	adds r0, r2, #1
	strh r0, [r6, #2]
	b .L080DAD94
.L080DAD64:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080DADA4
	cmp r7, #6
	bls .L080DADA4
	ldrh r2, [r5, #0x24]
	ldrh r1, [r6, #2]
	adds r0, r2, #0
	cmp r0, #0
	beq .L080DAD80
	strh r3, [r5, #0x24]
	b .L080DAD88
.L080DAD80:
	cmp r1, #4
	bls .L080DAD86
	subs r0, r1, #5
.L080DAD86:
	strh r0, [r6, #2]
.L080DAD88:
	ldrh r0, [r6]
	cmp r2, r0
	bne .L080DAD94
	ldrh r6, [r6, #2]
	cmp r1, r6
	beq .L080DAD9A
.L080DAD94:
	movs r0, #0x64
	bl sub_080C51D4
.L080DAD9A:
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	b .L080DADEE
.L080DADA4:
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080DADEE
	cmp r7, #6
	bls .L080DADEE
	ldrh r2, [r6]
	ldrh r3, [r6, #2]
	cmp r2, #5
	beq .L080DADC2
	movs r0, #5
	strh r0, [r6]
	b .L080DADD4
.L080DADC2:
	adds r0, r2, r3
	adds r0, #6
	subs r1, r7, #1
	cmp r0, r1
	bge .L080DADD0
	adds r0, r3, #6
	b .L080DADD2
.L080DADD0:
	subs r0, r7, #6
.L080DADD2:
	strh r0, [r6, #2]
.L080DADD4:
	ldrh r1, [r6]
	cmp r2, r1
	bne .L080DADE0
	ldrh r6, [r6, #2]
	cmp r3, r6
	beq .L080DADE6
.L080DADE0:
	movs r0, #0x64
	bl sub_080C51D4
.L080DADE6:
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
.L080DADEE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Vision_DrawItemList
Vision_DrawItemList: @ 0x080DADF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r0, #0x24
	str r0, [sp, #0xc]
	bl sub_080DAC4C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, .L080DAE80
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x6a
	str r1, [sp, #4]
	ldrh r2, [r4, #0x24]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0x88
	lsls r2, r2, #0xd
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	movs r0, #0
	mov r8, r0
	movs r1, #0x10
	lsls r1, r1, #0x10
	str r1, [sp, #0x18]
.L080DAE46:
	ldr r2, [sp, #0xc]
	ldrh r0, [r2, #2]
	add r0, r8
	lsls r0, r0, #1
	ldr r1, .L080DAE84
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r2, #0x6c
	adds r2, #0x25
	mov sl, r2
	movs r0, #0x10
	adds r0, #0x5a
	mov sb, r0
	ldr r1, [sp, #0x10]
	subs r1, #1
	str r1, [sp, #0x14]
	cmp r4, #0
	beq .L080DAEC4
	adds r0, r4, #0
	bl sub_080C2734
	cmp r0, #0
	beq .L080DAE88
	adds r0, r4, #0
	bl Action_GetRecord
	adds r0, #0xc
	b .L080DAE8A
	.byte 0x00, 0x00
.L080DAE80: .4byte gUnknown_0800853C
.L080DAE84: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080DAE88:
	ldr r0, .L080DAF4C
.L080DAE8A:
	movs r6, #0
	movs r2, #0x6c
	adds r2, #0x25
	mov sl, r2
	movs r1, #0x10
	adds r1, #0x5a
	mov sb, r1
	ldr r2, [sp, #0x10]
	subs r2, #1
	str r2, [sp, #0x14]
	ldr r1, [sp, #0x18]
	lsrs r7, r1, #0x10
	movs r2, #0x6c
	lsls r5, r2, #0x10
	adds r4, r0, #0
.L080DAEA8:
	ldrh r0, [r4]
	lsrs r3, r5, #0x10
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
	movs r0, #0xc0
	lsls r0, r0, #0xc
	adds r5, r5, r0
	adds r4, #2
	adds r6, #1
	cmp r6, #7
	bls .L080DAEA8
.L080DAEC4:
	ldr r1, [sp, #0x18]
	movs r2, #0xc0
	lsls r2, r2, #0xc
	adds r1, r1, r2
	str r1, [sp, #0x18]
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #5
	bls .L080DAE46
	movs r4, #0
	mov r8, r4
.L080DAEDC:
	movs r0, #0x96
	lsls r0, r0, #1
	add r0, r8
	bl sub_080C2734
	cmp r0, #0
	beq .L080DAEEC
	adds r4, #1
.L080DAEEC:
	movs r2, #1
	add r8, r2
	mov r0, r8
	cmp r0, #0x2d
	bls .L080DAEDC
	mov r2, sl
	mov r3, sb
	adds r0, r4, #0
	movs r1, #0x2b
	bl sub_080DA764
	ldr r1, [sp, #0xc]
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq .L080DAF1E
	movs r2, #0x6c
	adds r2, #0x60
	movs r3, #0x10
	subs r3, #4
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #6
	movs r1, #1
	bl sub_080C4A4C
.L080DAF1E:
	ldr r2, [sp, #0xc]
	ldrh r0, [r2, #2]
	adds r0, #6
	ldr r1, [sp, #0x14]
	cmp r0, r1
	bgt .L080DAF3A
	movs r2, #0x6c
	adds r2, #0x60
	movs r3, #0x10
	adds r3, #0x4c
	movs r0, #6
	movs r1, #1
	bl sub_080C4AB0
.L080DAF3A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DAF4C: .4byte gUnknown_085829BC

	thumb_func_start Vision_ComposePrompt
Vision_ComposePrompt: @ 0x080DAF50
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	bl Task_GetParent
	movs r6, #0x14
	movs r7, #0x64
	ldr r2, .L080DAFE0
	ldrh r1, [r0, #0x24]
	ldrh r0, [r0, #0x26]
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r0, [r1]
	bl Action_GetRecord
	adds r5, r0, #0
	adds r5, #0xc
	movs r4, #0
	ldrh r0, [r0, #0xc]
	cmp r0, #0
	beq .L080DAFAC
.L080DAF7A:
	lsls r0, r4, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	str r7, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl FontSprite_DrawGlyphTinted
	adds r0, r6, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #7
	bhi .L080DAFAC
	lsls r0, r4, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080DAF7A
.L080DAFAC:
	ldr r5, .L080DAFE4
	str r7, [sp]
	movs r4, #0xc
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl Text_DrawSpriteString
	ldr r5, .L080DAFE8
	adds r0, r7, #0
	adds r0, #0xc
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x14
	bl Text_DrawSpriteString
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DAFE0: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080DAFE4: .4byte gUnknown_08009534
.L080DAFE8: .4byte gUnknown_08009540

	thumb_func_start sub_080DAFEC
sub_080DAFEC: @ 0x080DAFEC
	ldr r2, .L080DAFFC
	ldr r0, [r2, #0x78]
	movs r1, #0
	str r1, [r0, #0x20]
	ldr r0, [r2, #0x7c]
	str r1, [r0, #0x20]
	bx lr
	.byte 0x00, 0x00
.L080DAFFC: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080DB000
sub_080DB000: @ 0x080DB000
	push {lr}
	sub sp, #4
	movs r1, #0
	str r1, [sp]
	ldr r2, .L080DB064
	mov r1, sp
	str r1, [r2]
	ldr r1, .L080DB068
	str r1, [r2, #4]
	ldr r1, .L080DB06C
	str r1, [r2, #8]
	ldr r1, [r2, #8]
	ldr r3, .L080DB070
	movs r2, #0x3f
	ldr r1, .L080DB074
	strb r2, [r1]
	ldr r2, .L080DB078
	movs r1, #0xe8
	strb r1, [r2]
	ldr r2, .L080DB07C
	movs r1, #8
	strb r1, [r2]
	ldr r2, .L080DB080
	movs r1, #0x98
	strb r1, [r2]
	ldr r2, .L080DB084
	movs r1, #0x60
	strb r1, [r2]
	movs r1, #0x37
	strb r1, [r3]
	ldr r2, .L080DB088
	ldr r3, .L080DB08C
	ldrh r1, [r0, #0x24]
	ldrh r0, [r0, #0x26]
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r0, [r1]
	ldr r1, .L080DB090
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r1, [r0]
	movs r0, #0x24
	bl sub_080AF218
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DB064: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DB068: .4byte 0x03004550 @ IWRAM+0x4550
.L080DB06C: .4byte 0x85000029
.L080DB070: .4byte 0x03000038 @ IWRAM+0x38
.L080DB074: .4byte 0x03000039 @ IWRAM+0x39
.L080DB078: .4byte 0x03000030 @ IWRAM+0x30
.L080DB07C: .4byte 0x03000031 @ IWRAM+0x31
.L080DB080: .4byte 0x03000034 @ IWRAM+0x34
.L080DB084: .4byte 0x03000035 @ IWRAM+0x35
.L080DB088: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080DB08C: .4byte gUnknown_085829CC
.L080DB090: .4byte 0xFFFFFED4

	thumb_func_start sub_080DB094
sub_080DB094: @ 0x080DB094
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080DB0B0
	ldrh r0, [r0]
	cmp r0, #0x24
	bne .L080DB0B4
	movs r0, #1
	strh r0, [r1, #0x1c]
	bl sub_080C3818
	bl sub_080AE2D0
	b .L080DB0B8
	.byte 0x00, 0x00
.L080DB0B0: .4byte 0x03004550 @ IWRAM+0x4550
.L080DB0B4:
	movs r0, #0
	strh r0, [r1, #0x1c]
.L080DB0B8:
	pop {r0}
	bx r0

	thumb_func_start sub_080DB0BC
sub_080DB0BC: @ 0x080DB0BC
	sub sp, #4
	movs r3, #0
	str r3, [sp]
	ldr r0, .L080DB0E4
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080DB0E8
	str r1, [r0, #4]
	ldr r2, .L080DB0EC
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080DB0F0
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	add sp, #4
	bx lr
.L080DB0E4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DB0E8: .4byte 0x06001000 @ VRAM+0x1000
.L080DB0EC: .4byte 0x85000400
.L080DB0F0: .4byte 0x06003000 @ VRAM+0x3000

	thumb_func_start sub_080DB0F4
sub_080DB0F4: @ 0x080DB0F4
	push {r4, lr}
	sub sp, #8
	movs r4, #0
	str r4, [sp]
	ldr r0, .L080DB158
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080DB15C
	str r1, [r0, #4]
	ldr r1, .L080DB160
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080DB164
	str r1, [r0, #4]
	ldr r1, .L080DB168
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	add r1, sp, #4
	strh r4, [r1]
	str r1, [r0]
	ldr r1, .L080DB16C
	str r1, [r0, #4]
	ldr r1, .L080DB170
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080DB174
	str r1, [r0, #4]
	ldr r1, .L080DB178
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	bl Palette_MarkDirty
	ldr r0, .L080DB17C
	strh r4, [r0]
	ldr r0, .L080DB180
	strh r4, [r0]
	ldr r0, .L080DB184
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
.L080DB158: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DB15C: .4byte 0x02000000 @ EWRAM
.L080DB160: .4byte 0x85000400
.L080DB164: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080DB168: .4byte 0x85000040
.L080DB16C: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080DB170: .4byte 0x81000400
.L080DB174: .4byte 0x0201D874 @ EWRAM+0x1D874
.L080DB178: .4byte 0x85001A00
.L080DB17C: .4byte 0x0300000E @ IWRAM+0xE
.L080DB180: .4byte 0x03000006 @ IWRAM+0x6
.L080DB184: .4byte sub_080DB0BC
