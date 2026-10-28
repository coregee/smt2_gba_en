	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080CBC8C
sub_080CBC8C: @ 0x080CBC8C
.L080CBC8C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r5, .L080CBD40
	ldrh r0, [r5, #2]
	bl Status_GetCombatant
	adds r4, r0, #0
	ldrh r0, [r5, #2]
	bl sub_080C9388
	cmp r0, #1
	bne .L080CBD44
	bl sub_080CBB34
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x1f
	movs r3, #4
	bl DigitFont_DrawNumber
	adds r0, r4, #0
	adds r0, #0x4a
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x2c
	movs r3, #4
	bl DigitFont_DrawNumber
	adds r0, r4, #0
	adds r0, #0x4c
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x39
	movs r3, #4
	bl DigitFont_DrawNumber
	adds r0, r4, #0
	adds r0, #0x4e
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x46
	movs r3, #4
	bl DigitFont_DrawNumber
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x53
	movs r3, #4
	bl DigitFont_DrawNumber
	adds r0, r4, #0
	adds r0, #0x52
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x60
	movs r3, #4
	bl DigitFont_DrawNumber
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x6d
	movs r3, #4
	bl DigitFont_DrawNumber
	adds r0, r4, #0
	adds r0, #0x56
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x7a
	movs r3, #4
	bl DigitFont_DrawNumber
	b .L080CC46A
	.byte 0x00, 0x00
.L080CBD40: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CBD44:
	ldrh r0, [r4, #0x12]
	bl Fusion_GetDemonByIndex
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x93
	bne .L080CBE3C
	ldr r0, .L080CBE10
	mov r8, r0
	ldr r4, .L080CBE14
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CBE18
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	movs r0, #0x93
	movs r1, #0xce
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CD668
	ldr r0, .L080CBE1C
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CBE20
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	movs r0, #0x93
	movs r1, #0xce
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CD6C4
	ldr r0, .L080CBE24
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r6, .L080CBE28
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CBE2C
	movs r5, #4
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xbe
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBE30
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xca
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	str r5, [sp]
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0xd6
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBE34
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xe2
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBE38
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	movs r0, #0x93
	b .L080CC198
	.byte 0x00, 0x00
.L080CBE10: .4byte 0x00000FA9
.L080CBE14: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CBE18: .4byte 0x000008C3
.L080CBE1C: .4byte 0x00000699
.L080CBE20: .4byte 0x00000EB7
.L080CBE24: .4byte 0x00000C1A
.L080CBE28: .4byte 0x00000B7E
.L080CBE2C: .4byte 0x00000B32
.L080CBE30: .4byte 0x00000B8C
.L080CBE34: .4byte 0x00000811
.L080CBE38: .4byte 0x00000C3E
.L080CBE3C:
	cmp r7, #0xa7
	bne .L080CBF28
	ldr r0, .L080CBEFC
	ldr r4, .L080CBF00
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CBF04
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	movs r0, #0xa7
	movs r1, #0xce
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CD668
	ldr r0, .L080CBF08
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CBF0C
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	movs r0, #0xa7
	movs r1, #0xce
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CD6C4
	ldr r0, .L080CBF10
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r6, .L080CBF14
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CBF18
	movs r5, #4
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xbe
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBF1C
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xca
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	str r5, [sp]
	movs r0, #5
	adds r1, r4, #0
	movs r2, #0xd6
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBF20
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xe2
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBF24
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	movs r0, #0xa7
	b .L080CC198
	.byte 0x00, 0x00
.L080CBEFC: .4byte 0x00000FA9
.L080CBF00: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CBF04: .4byte 0x000008C3
.L080CBF08: .4byte 0x00000699
.L080CBF0C: .4byte 0x00000EB7
.L080CBF10: .4byte 0x00000C1A
.L080CBF14: .4byte 0x00000B7E
.L080CBF18: .4byte 0x00000C5E
.L080CBF1C: .4byte 0x00000D6E
.L080CBF20: .4byte 0x00000AEB
.L080CBF24: .4byte 0x00000C3E
.L080CBF28:
	cmp r7, #0xbb
	bne .L080CC004
	ldr r0, .L080CBFD8
	ldr r5, .L080CBFDC
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CBFE0
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	movs r0, #0xbb
	movs r1, #0xce
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CD668
	ldr r0, .L080CBFE4
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CBFE8
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	movs r0, #0xbb
	movs r1, #0xce
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CD6C4
	ldr r0, .L080CBFEC
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r6, .L080CBFF0
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CBFF4
	movs r4, #4
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xca
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBFF8
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xd6
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBFFC
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xe2
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CC000
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	movs r0, #0xbb
	b .L080CC198
.L080CBFD8: .4byte 0x00000FA9
.L080CBFDC: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CBFE0: .4byte 0x000008C3
.L080CBFE4: .4byte 0x00000699
.L080CBFE8: .4byte 0x00000EB7
.L080CBFEC: .4byte 0x00000C1A
.L080CBFF0: .4byte 0x00000B7E
.L080CBFF4: .4byte 0x00000C5E
.L080CBFF8: .4byte 0x00000EDC
.L080CBFFC: .4byte 0x0000086A
.L080CC000: .4byte 0x00000C3E
.L080CC004:
	cmp r7, #0xcf
	bne .L080CC0E0
	ldr r0, .L080CC0B4
	ldr r5, .L080CC0B8
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CC0BC
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	movs r0, #0xcf
	movs r1, #0xce
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CD668
	ldr r0, .L080CC0C0
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CC0C4
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	movs r0, #0xcf
	movs r1, #0xce
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CD6C4
	ldr r0, .L080CC0C8
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r6, .L080CC0CC
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CC0D0
	movs r4, #4
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xca
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CC0D4
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xd6
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CC0D8
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xe2
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CC0DC
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	movs r0, #0xcf
	b .L080CC198
.L080CC0B4: .4byte 0x00000FA9
.L080CC0B8: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CC0BC: .4byte 0x000008C3
.L080CC0C0: .4byte 0x00000699
.L080CC0C4: .4byte 0x00000EB7
.L080CC0C8: .4byte 0x00000C1A
.L080CC0CC: .4byte 0x00000B7E
.L080CC0D0: .4byte 0x00000C5E
.L080CC0D4: .4byte 0x00000676
.L080CC0D8: .4byte 0x00000632
.L080CC0DC: .4byte 0x00000C3E
.L080CC0E0:
	ldrh r0, [r4, #0x12]
	bl sub_080C92AC
	cmp r0, #1
	bne .L080CC1C8
	ldrh r0, [r4, #0x12]
	bl Fusion_GetDemonByIndex
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r6, .L080CC1A4
	ldr r4, .L080CC1A8
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r5, .L080CC1AC
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0xce
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CD330
	ldr r0, .L080CC1B0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CC1B4
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0xce
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CD38C
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CC1B8
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CC1BC
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x36
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0xd6
	movs r2, #0x39
	movs r3, #4
	bl sub_080CD3E8
	ldr r0, .L080CC1C0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	ldr r0, .L080CC1C4
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r7, #0
.L080CC198:
	movs r1, #0xd6
	movs r2, #0x46
	bl sub_080CD45C
	b .L080CC46A
	.byte 0x00, 0x00
.L080CC1A4: .4byte 0x000008F1
.L080CC1A8: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CC1AC: .4byte 0x00000861
.L080CC1B0: .4byte 0x00000FFE
.L080CC1B4: .4byte 0x00000CD3
.L080CC1B8: .4byte 0x00000699
.L080CC1BC: .4byte 0x00000B67
.L080CC1C0: .4byte 0x00000C3E
.L080CC1C4: .4byte 0x00000B7E
.L080CC1C8:
	adds r0, r4, #0
	bl sub_080C99B8
	cmp r0, #1
	beq .L080CC1D4
	b .L080CC328
.L080CC1D4:
	ldr r0, .L080CC2E8
	ldr r4, .L080CC2EC
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CC2F0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r5, .L080CC2F4
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x1f
	movs r3, #4
	bl DigitFont_DrawAscii
	ldr r0, .L080CC2F8
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CC2FC
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x2c
	movs r3, #4
	bl DigitFont_DrawAscii
	ldr r0, .L080CC300
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CC304
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x39
	movs r3, #4
	bl DigitFont_DrawAscii
	ldr r0, .L080CC308
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	ldr r0, .L080CC30C
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x46
	movs r3, #4
	bl DigitFont_DrawAscii
	ldr r1, .L080CC310
	mov r8, r1
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r6, .L080CC314
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r0, .L080CC318
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r0, .L080CC31C
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x50
	bl Font_DrawGlyph
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x53
	movs r3, #4
	bl DigitFont_DrawAscii
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x5d
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x5d
	bl Font_DrawGlyph
	ldr r0, .L080CC320
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x5d
	bl Font_DrawGlyph
	ldr r0, .L080CC324
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x5d
	bl Font_DrawGlyph
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x60
	movs r3, #4
	bl DigitFont_DrawAscii
	b .L080CC46A
.L080CC2E8: .4byte 0x000008F1
.L080CC2EC: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CC2F0: .4byte 0x00000861
.L080CC2F4: .4byte gUnknown_084F01B4
.L080CC2F8: .4byte 0x00000FFE
.L080CC2FC: .4byte 0x00000CD3
.L080CC300: .4byte 0x00000FA9
.L080CC304: .4byte 0x000008C3
.L080CC308: .4byte 0x00000699
.L080CC30C: .4byte 0x00000EB7
.L080CC310: .4byte 0x00000FC3
.L080CC314: .4byte 0x00000F81
.L080CC318: .4byte 0x000005BB
.L080CC31C: .4byte 0x000010CB
.L080CC320: .4byte 0x000008D7
.L080CC324: .4byte 0x00000672
.L080CC328:
	adds r7, r4, #0
	ldrh r0, [r5]
	cmp r0, #7
	bne .L080CC338
	ldrh r0, [r7, #0x12]
	bl Stock_FindByDemonId
	adds r7, r0, #0
.L080CC338:
	ldr r0, .L080CC478
	ldr r4, .L080CC47C
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CC480
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x1f
	movs r3, #4
	bl DigitFont_DrawNumber
	ldr r0, .L080CC484
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CC488
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x4a
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x2c
	movs r3, #4
	bl DigitFont_DrawNumber
	ldr r0, .L080CC48C
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CC490
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x50
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x39
	movs r3, #4
	bl DigitFont_DrawNumber
	ldr r0, .L080CC494
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	ldr r0, .L080CC498
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x52
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x46
	movs r3, #4
	bl DigitFont_DrawNumber
	ldr r6, .L080CC49C
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r5, .L080CC4A0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r0, .L080CC4A4
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r0, .L080CC4A8
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x50
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x54
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x53
	movs r3, #4
	bl DigitFont_DrawNumber
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x5d
	bl Font_DrawGlyph
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x5d
	bl Font_DrawGlyph
	ldr r0, .L080CC4AC
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x5d
	bl Font_DrawGlyph
	ldr r0, .L080CC4B0
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x5d
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x56
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x60
	movs r3, #4
	bl DigitFont_DrawNumber
.L080CC46A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CC478: .4byte 0x000008F1
.L080CC47C: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CC480: .4byte 0x00000861
.L080CC484: .4byte 0x00000FFE
.L080CC488: .4byte 0x00000CD3
.L080CC48C: .4byte 0x00000FA9
.L080CC490: .4byte 0x000008C3
.L080CC494: .4byte 0x00000699
.L080CC498: .4byte 0x00000EB7
.L080CC49C: .4byte 0x00000FC3
.L080CC4A0: .4byte 0x00000F81
.L080CC4A4: .4byte 0x000005BB
.L080CC4A8: .4byte 0x000010CB
.L080CC4AC: .4byte 0x000008D7
.L080CC4B0: .4byte 0x00000672
