	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080DC6D0
sub_080DC6D0: @ 0x080DC6D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r1, #0
	movs r0, #0
	mov sb, r0
	ldr r5, .L080DC7B4
	ldrh r0, [r5, #0x38]
	bl sub_080DC6C8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Demon_GetRecord
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x11
	str r1, [sp, #0x14]
	ldr r2, .L080DC7B8
	ldrb r0, [r2]
	movs r1, #0x3f
	orrs r0, r1
	strb r0, [r2]
	mov r6, sb
	str r6, [sp, #0x10]
	ldr r0, .L080DC7BC
	mov sl, r0
	ldr r2, .L080DC7C0
	add r0, sp, #0x10
	mov r1, sl
	bl CpuSet
	cmp r4, #0
	beq .L080DC71C
	b .L080DC8C4
.L080DC71C:
	ldr r0, .L080DC7C4
	movs r1, #0
	movs r2, #2
	movs r3, #4
	bl sub_080CCE5C
	movs r0, #0
	ldrsb r0, [r7, r0]
	bl Race_GetParentId
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl ParentRace_GetName
	adds r1, r0, #0
	cmp r1, #0
	beq .L080DC750
	str r6, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	adds r0, r1, #0
	mov r1, sl
	movs r2, #4
	movs r3, #0xe
	bl Text_DrawStringTinted
.L080DC750:
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Race_GetName
	adds r1, r0, #0
	cmp r1, #0
	beq .L080DC776
	mov r6, sb
	str r6, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	adds r0, r1, #0
	mov r1, sl
	movs r2, #4
	movs r3, #0x1d
	bl Text_DrawStringTinted
.L080DC776:
	movs r5, #0
	movs r0, #0xb0
	lsls r0, r0, #0xe
	mov r8, r0
	movs r1, #4
	mov sl, r1
	adds r4, r7, #0
	adds r4, #0x22
.L080DC786:
	ldrh r0, [r4]
	mov r6, sl
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0
	str r1, [sp]
	ldr r1, .L080DC7BC
	mov r6, r8
	lsrs r3, r6, #0x10
	bl Font_DrawGlyphTinted
	movs r0, #0xc
	add sl, r0
	adds r4, #2
	adds r5, #1
	cmp r5, #7
	bls .L080DC786
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0xc
	bgt .L080DC7CC
	ldr r1, .L080DC7C8
	b .L080DC7D4
.L080DC7B4: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DC7B8: .4byte 0x03000038 @ IWRAM+0x38
.L080DC7BC: .4byte 0x0200F874 @ EWRAM+0xF874
.L080DC7C0: .4byte 0x05002000
.L080DC7C4: .4byte gUnknown_08583A58
.L080DC7C8: .4byte gUnknown_08583A28
.L080DC7CC:
	ldr r1, .L080DC8B0
	cmp r0, #0x1a
	bgt .L080DC7D4
	subs r1, #0x10
.L080DC7D4:
	ldr r7, .L080DC8B4
	movs r4, #4
	movs r3, #0x3b
	movs r6, #0
	str r6, [sp]
	movs r5, #0xc
	str r5, [sp, #4]
	adds r0, r1, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Text_DrawStringTinted
	ldr r0, .L080DC8B8
	ldr r0, [r0, #0x38]
	bl sub_0815B864
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C06AC
	adds r1, r0, #0
	cmp r1, #0
	beq .L080DC810
	movs r3, #0x4b
	str r6, [sp]
	str r5, [sp, #4]
	adds r1, r7, #0
	adds r2, r4, #0
	bl Text_DrawStringTinted
.L080DC810:
	ldr r0, .L080DC8BC
	movs r1, #0x6a
	movs r2, #2
	movs r3, #4
	bl sub_080CCE5C
	movs r5, #0
.L080DC81E:
	ldr r1, [sp, #0x14]
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #0xff
	beq .L080DC840
	mov r2, sb
	adds r2, #0xe
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0x6e
	bl sub_080CD1F8
	mov r0, sb
	adds r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
.L080DC840:
	adds r5, #1
	cmp r5, #6
	bls .L080DC81E
	movs r5, #0
	ldr r2, .L080DC8B4
.L080DC84A:
	ldr r6, [sp, #0x14]
	adds r0, r6, r5
	ldrb r0, [r0]
	adds r5, #1
	mov r8, r5
	cmp r0, #0xff
	bne .L080DC88C
	movs r5, #0
	mov r0, sb
	adds r0, #0xe
	mov r7, sb
	adds r7, #0xf
	lsls r6, r0, #0x10
	movs r0, #0x6e
	lsls r4, r0, #0x10
.L080DC868:
	lsrs r2, r4, #0x10
	movs r0, #0
	str r0, [sp]
	movs r0, #0x3c
	ldr r1, .L080DC8B4
	lsrs r3, r6, #0x10
	bl Font_DrawGlyphTinted
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r4, r4, r1
	adds r5, #1
	cmp r5, #7
	bls .L080DC868
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	ldr r2, .L080DC8B4
.L080DC88C:
	mov r5, r8
	cmp r5, #6
	bls .L080DC84A
	ldr r0, .L080DC8C0
	movs r1, #0x96
	str r1, [sp]
	movs r1, #0x80
	str r1, [sp, #4]
	movs r1, #8
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r2, #0
	movs r2, #0
	movs r3, #0
	bl Canvas_BlitOr
	b .L080DCB68
	.byte 0x00, 0x00
.L080DC8B0: .4byte gUnknown_08583A48
.L080DC8B4: .4byte 0x0200F874 @ EWRAM+0xF874
.L080DC8B8: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DC8BC: .4byte gUnknown_08583A60
.L080DC8C0: .4byte gUnknown_081B1DB8
.L080DC8C4:
	ldr r6, .L080DCB94
	str r6, [sp, #0x18]
	adds r4, r6, #0
	adds r4, #0x88
	ldrh r0, [r5, #0x38]
	bl sub_080DC6C8
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r1, #4
	bl sub_080C0444
	ldr r0, .L080DCB98
	movs r1, #0
	movs r2, #2
	movs r3, #4
	bl sub_080CCE5C
	ldr r0, .L080DCB9C
	movs r4, #4
	movs r1, #4
	movs r2, #0x10
	movs r3, #4
	bl sub_080CCEC8
	ldrb r0, [r7, #1]
	movs r1, #0x45
	movs r2, #0x10
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBA0
	movs r1, #4
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CCEC8
	movs r1, #2
	ldrsh r0, [r7, r1]
	movs r1, #0x45
	movs r2, #0x1f
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBA4
	movs r1, #4
	movs r2, #0x2e
	movs r3, #4
	bl sub_080CCEC8
	movs r6, #4
	ldrsh r0, [r7, r6]
	movs r1, #0x45
	movs r2, #0x2e
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBA8
	movs r1, #4
	movs r2, #0x3d
	movs r3, #4
	bl sub_080CCEC8
	ldrb r0, [r7, #0x1d]
	movs r1, #0x45
	movs r2, #0x3d
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBAC
	mov r8, r0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x55
	movs r3, #0xe
	bl Font_DrawGlyphTinted
	movs r0, #6
	ldrsb r0, [r7, r0]
	movs r1, #0x6d
	movs r2, #0x11
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBB0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x7e
	movs r3, #0xe
	bl Font_DrawGlyphTinted
	movs r0, #7
	ldrsb r0, [r7, r0]
	movs r1, #0x96
	mov sb, r1
	movs r2, #0x11
	movs r3, #0
	bl sub_080CCFC4
	ldr r6, .L080DCBB4
	str r4, [sp]
	adds r0, r6, #0
	mov r1, sl
	movs r2, #0x55
	movs r3, #0x1d
	bl Font_DrawGlyphTinted
	movs r0, #8
	ldrsb r0, [r7, r0]
	movs r1, #0x6d
	movs r2, #0x20
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBB8
	str r4, [sp]
	mov r1, sl
	movs r2, #0x7e
	movs r3, #0x1d
	bl Font_DrawGlyphTinted
	movs r0, #9
	ldrsb r0, [r7, r0]
	movs r1, #0x96
	movs r2, #0x20
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBBC
	str r4, [sp]
	mov r1, sl
	movs r2, #0x55
	movs r3, #0x2c
	bl Font_DrawGlyphTinted
	movs r0, #0xa
	ldrsb r0, [r7, r0]
	movs r1, #0x6d
	movs r2, #0x2f
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBC0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x7e
	movs r3, #0x2c
	bl Font_DrawGlyphTinted
	movs r0, #0xb
	ldrsb r0, [r7, r0]
	movs r1, #0x96
	movs r2, #0x2f
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBC4
	str r4, [sp]
	mov r1, sl
	movs r2, #4
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBC8
	str r4, [sp]
	mov r1, sl
	movs r2, #0x10
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xd0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x45
	movs r2, #0x52
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBCC
	str r4, [sp]
	mov r1, sl
	movs r2, #4
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBD0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x10
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xd2
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x45
	movs r2, #0x61
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBD4
	str r4, [sp]
	mov r1, sl
	movs r2, #4
	movs r3, #0x6e
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBD8
	str r4, [sp]
	mov r1, sl
	movs r2, #0x10
	movs r3, #0x6e
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xd8
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x45
	movs r2, #0x70
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBDC
	str r4, [sp]
	mov r1, sl
	movs r2, #4
	movs r3, #0x7d
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBE0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x10
	movs r3, #0x7d
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xda
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x45
	movs r2, #0x7f
	movs r3, #0
	bl sub_080CCFC4
	str r4, [sp]
	adds r0, r6, #0
	mov r1, sl
	movs r2, #0x55
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	ldr r5, .L080DCBE4
	str r4, [sp]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x61
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBE8
	str r4, [sp]
	mov r1, sl
	movs r2, #0x6d
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	str r4, [sp]
	mov r0, r8
	mov r1, sl
	movs r2, #0x79
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xdc
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x96
	movs r2, #0x52
	movs r3, #0
	bl sub_080CCFC4
	str r4, [sp]
	adds r0, r6, #0
	mov r1, sl
	movs r2, #0x55
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	str r4, [sp]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x61
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBEC
	str r4, [sp]
	mov r1, sl
	movs r2, #0x6d
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBF0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x79
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xde
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r1, #0x96
	movs r2, #0x61
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBF4
	mov r1, sb
	str r1, [sp]
	movs r1, #5
	str r1, [sp, #4]
	movs r1, #8
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, sl
	movs r2, #0
	movs r3, #0
	bl Canvas_BlitOr
.L080DCB68:
	ldr r1, .L080DCBF8
	ldr r2, .L080DCBFC
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080DCC00
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080DCB94: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080DCB98: .4byte gUnknown_08583A68
.L080DCB9C: .4byte gUnknown_08583A70
.L080DCBA0: .4byte gUnknown_08583A74
.L080DCBA4: .4byte gUnknown_08583A78
.L080DCBA8: .4byte gUnknown_08583A7C
.L080DCBAC: .4byte 0x000010CB
.L080DCBB0: .4byte 0x00000CBA
.L080DCBB4: .4byte 0x00000FC3
.L080DCBB8: .4byte 0x00000C5C
.L080DCBBC: .4byte 0x00000C3C
.L080DCBC0: .4byte 0x00000606
.L080DCBC4: .4byte 0x000008F1
.L080DCBC8: .4byte 0x00000861
.L080DCBCC: .4byte 0x00000FFE
.L080DCBD0: .4byte 0x00000CD3
.L080DCBD4: .4byte 0x00000FA9
.L080DCBD8: .4byte 0x000008C3
.L080DCBDC: .4byte 0x00000699
.L080DCBE0: .4byte 0x00000EB7
.L080DCBE4: .4byte 0x00000F81
.L080DCBE8: .4byte 0x000005BB
.L080DCBEC: .4byte 0x000008D7
.L080DCBF0: .4byte 0x00000672
.L080DCBF4: .4byte gUnknown_081B1D98
.L080DCBF8: .4byte gUnknown_081B6ED0
.L080DCBFC: .4byte 0x030030B0 @ IWRAM+0x30B0
.L080DCC00: .4byte sub_080DC6A4
