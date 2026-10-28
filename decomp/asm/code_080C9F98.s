	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080C9F98
sub_080C9F98: @ 0x080C9F98
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	str r0, [sp, #0x10]
	ldr r0, .L080CA040
	mov sb, r0
	ldrh r0, [r0, #2]
	bl Status_GetCombatant
	adds r7, r0, #0
	mov r1, sb
	ldrh r0, [r1, #0x16]
	cmp r0, #1
	bne .L080C9FDE
	ldr r0, .L080CA044
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA048
	ldrh r2, [r1]
	movs r1, #0xa0
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x18
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080C9FDE:
	mov r2, sb
	ldrh r0, [r2, #0x1c]
	cmp r0, #1
	bne .L080C9FF2
	movs r0, #0
	movs r1, #0
	movs r2, #0x92
	movs r3, #0x14
	bl sub_080C4A4C
.L080C9FF2:
	mov r3, sb
	ldrh r0, [r3, #0x1e]
	cmp r0, #1
	bne .L080CA006
	movs r0, #0
	movs r1, #0
	movs r2, #0x92
	movs r3, #0x76
	bl sub_080C4AB0
.L080CA006:
	mov r1, sb
	ldrh r0, [r1, #2]
	bl sub_080C9388
	cmp r0, #1
	bne .L080CA050
	mov r2, sb
	ldrh r0, [r2, #0x10]
	cmp r0, #1
	bne .L080CA0B0
	ldr r0, .L080CA04C
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA048
	ldrh r2, [r1]
	movs r1, #8
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x11
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #2
	bl Sprite_Draw
	b .L080CA0B0
.L080CA040: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CA044: .4byte gUnknown_0800146C
.L080CA048: .4byte 0x03000004 @ IWRAM+0x4
.L080CA04C: .4byte gUnknown_080014A0
.L080CA050:
	mov r3, sb
	ldrh r0, [r3, #0x10]
	cmp r0, #1
	bne .L080CA0B0
	ldrh r0, [r3, #0x12]
	cmp r0, #0
	beq .L080CA082
	ldr r0, .L080CA0C8
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA0CC
	ldrh r2, [r1]
	movs r1, #8
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrh r1, [r3, #0x12]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080CA082:
	mov r1, sb
	ldrh r0, [r1, #0x14]
	cmp r0, #0
	beq .L080CA0B0
	ldr r0, .L080CA0D0
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA0CC
	ldrh r2, [r1]
	movs r1, #8
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	mov r2, sb
	ldrh r1, [r2, #0x14]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080CA0B0:
	mov r3, sb
	ldrh r0, [r3, #0x18]
	cmp r0, #1
	beq .L080CA0BA
	b .L080CA51E
.L080CA0BA:
	ldrh r0, [r3, #0x1a]
	cmp r0, #0
	bne .L080CA0D4
	ldr r0, .L080CA0CC
	ldrh r2, [r0]
	b .L080CA0D8
	.byte 0x00, 0x00
.L080CA0C8: .4byte gUnknown_08001630
.L080CA0CC: .4byte 0x03000004 @ IWRAM+0x4
.L080CA0D0: .4byte gUnknown_08001780
.L080CA0D4:
	mov r0, sb
	ldrh r2, [r0, #0x1a]
.L080CA0D8:
	ldr r0, .L080CA1D4
	movs r1, #0x80
	lsls r1, r1, #2
	mov sl, r1
	str r1, [sp]
	movs r1, #0x77
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x81
	str r1, [sp, #8]
	movs r1, #3
	movs r2, #0
	movs r3, #2
	bl Sprite_Draw
	ldrh r0, [r7, #0x12]
	bl sub_080C92AC
	cmp r0, #1
	beq .L080CA106
	b .L080CA224
.L080CA106:
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0x16
	mov r8, r2
	str r2, [sp]
	movs r4, #0x86
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x41
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r6, #0x63
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x42
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r5, #0xb0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x43
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, r8
	str r3, [sp]
	movs r4, #0x93
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x44
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x45
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	ldrh r0, [r7, #0x12]
	bl Fusion_GetDemonByIndex
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	add r2, sp, #0xc
	bl Item_GetAttribute
	ldr r0, [sp, #0xc]
	cmp r0, #0x80
	beq .L080CA1EC
	cmp r0, #0x80
	bgt .L080CA1D8
	cmp r0, #0x40
	beq .L080CA1F8
	b .L080CA51E
	.byte 0x00, 0x00
.L080CA1D4: .4byte gUnknown_08001620
.L080CA1D8:
	cmp r0, #0xc0
	beq .L080CA1DE
	b .L080CA51E
.L080CA1DE:
	ldr r0, .L080CA1E8
	mov r1, sl
	str r1, [sp]
	b .L080CA1FE
	.byte 0x00, 0x00
.L080CA1E8: .4byte gUnknown_080014D8
.L080CA1EC:
	ldr r0, .L080CA1F4
	mov r2, sl
	str r2, [sp]
	b .L080CA1FE
.L080CA1F4: .4byte gUnknown_080014B0
.L080CA1F8:
	ldr r0, .L080CA21C
	mov r3, sl
	str r3, [sp]
.L080CA1FE:
	ldr r1, .L080CA220
	ldrh r2, [r1]
	movs r1, #0xd8
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x45
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	b .L080CA51E
.L080CA21C: .4byte gUnknown_080014C0
.L080CA220: .4byte 0x03000004 @ IWRAM+0x4
.L080CA224:
	adds r0, r7, #0
	bl sub_080C99B8
	cmp r0, #1
	bne .L080CA230
	b .L080CA51E
.L080CA230:
	movs r0, #0
	mov sl, r0
	movs r1, #0
	str r1, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x18]
	movs r3, #0
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, .L080CA3FC
	ldrh r0, [r0]
	ldr r1, .L080CA400
	ands r1, r0
	movs r2, #0x30
	adds r2, r2, r7
	mov r8, r2
	adds r3, r7, #0
	adds r3, #0x38
	str r3, [sp, #0x44]
	adds r0, r7, #0
	adds r0, #0x31
	str r0, [sp, #0x30]
	adds r2, r7, #0
	adds r2, #0x39
	str r2, [sp, #0x48]
	subs r3, #6
	str r3, [sp, #0x34]
	adds r0, #9
	str r0, [sp, #0x4c]
	subs r2, #6
	str r2, [sp, #0x38]
	adds r3, #9
	str r3, [sp, #0x50]
	subs r0, #6
	str r0, [sp, #0x3c]
	adds r2, #9
	str r2, [sp, #0x54]
	subs r3, #6
	str r3, [sp, #0x40]
	adds r0, #9
	str r0, [sp, #0x58]
	cmp r1, #0
	bne .L080CA30E
	ldrb r0, [r7, #0xc]
	cmp r0, #0
	bne .L080CA30E
	movs r4, #0
	ldr r6, .L080CA404
	movs r5, #0xf
.L080CA294:
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Inventory_GetCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls .L080CA304
	lsls r2, r4, #2
	adds r0, r2, #1
	adds r0, r0, r6
	ldrb r1, [r0]
	lsrs r0, r1, #4
	add r0, sl
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ands r1, r5
	ldr r3, [sp, #0x14]
	adds r1, r3, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	adds r0, r2, #2
	adds r0, r0, r6
	ldrb r1, [r0]
	lsrs r0, r1, #4
	ldr r3, [sp, #0x18]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	ands r1, r5
	ldr r0, [sp, #0x1c]
	adds r1, r0, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x1c]
	adds r2, #3
	adds r2, r2, r6
	ldrb r1, [r2]
	lsrs r0, r1, #4
	ldr r2, [sp, #0x20]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x20]
	ands r1, r5
	ldr r3, [sp, #0x24]
	adds r1, r3, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x24]
.L080CA304:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xb
	bls .L080CA294
.L080CA30E:
	ldrh r1, [r7, #0x10]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #7
	bne .L080CA320
	ldrh r0, [r7, #0x12]
	bl Stock_FindByDemonId
	ldrh r1, [r0, #0x10]
.L080CA320:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r1, r0
	cmp r1, #0
	beq .L080CA408
	mov r3, r8
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x44]
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0x16
	mov r8, r3
	str r3, [sp]
	movs r4, #0x86
	str r4, [sp, #4]
	movs r0, #1
	mov r3, sl
	bl sub_080CD9C8
	ldr r0, [sp, #0x30]
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x48]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r6, #0x63
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #1
	ldr r3, [sp, #0x14]
	bl sub_080CD9C8
	ldr r0, [sp, #0x34]
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x4c]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r5, #0xb0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #1
	ldr r3, [sp, #0x18]
	bl sub_080CD9C8
	ldr r0, [sp, #0x38]
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x50]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, r8
	str r0, [sp]
	movs r4, #0x93
	str r4, [sp, #4]
	movs r0, #1
	ldr r3, [sp, #0x1c]
	bl sub_080CD9C8
	ldr r2, [sp, #0x3c]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x54]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0x28
	ldr r3, [sp, #0x20]
	bl sub_080CD9C8
	ldr r0, [sp, #0x40]
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x58]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #1
	ldr r3, [sp, #0x24]
	bl sub_080CD9C8
	b .L080CA51E
	.byte 0x00, 0x00
.L080CA3FC: .4byte 0x03000004 @ IWRAM+0x4
.L080CA400: .4byte 0x000001FF
.L080CA404: .4byte gUnknown_081A6ED4
.L080CA408:
	adds r0, r7, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, r8
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x44]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0x16
	mov r8, r3
	str r3, [sp]
	movs r4, #0x86
	str r4, [sp, #4]
	mov r3, sl
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x30]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x48]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r6, #0x63
	str r6, [sp]
	str r4, [sp, #4]
	ldr r3, [sp, #0x14]
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x34]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x4c]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r5, #0xb0
	str r5, [sp]
	str r4, [sp, #4]
	ldr r3, [sp, #0x18]
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x38]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x50]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r3, r8
	str r3, [sp]
	movs r4, #0x93
	str r4, [sp, #4]
	ldr r3, [sp, #0x1c]
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x3c]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x54]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r6, [sp]
	str r4, [sp, #4]
	ldr r3, [sp, #0x20]
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x40]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x58]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r5, [sp]
	str r4, [sp, #4]
	ldr r3, [sp, #0x24]
	bl sub_080CD9C8
.L080CA51E:
	mov r1, sb
	ldrh r0, [r1, #0x32]
	cmp r0, #0x80
	beq .L080CA53C
	cmp r0, #0x80
	bgt .L080CA530
	cmp r0, #0x40
	beq .L080CA56C
	b .L080CA590
.L080CA530:
	cmp r0, #0xc0
	bne .L080CA590
	ldr r0, .L080CA538
	b .L080CA53E
.L080CA538: .4byte gUnknown_080014D8
.L080CA53C:
	ldr r0, .L080CA564
.L080CA53E:
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA568
	ldrh r2, [r1]
	movs r1, #0xd0
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x8c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	b .L080CA590
	.byte 0x00, 0x00
.L080CA564: .4byte gUnknown_080014B0
.L080CA568: .4byte 0x03000004 @ IWRAM+0x4
.L080CA56C:
	ldr r0, .L080CA5B8
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA5BC
	ldrh r2, [r1]
	movs r1, #0xd0
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x8c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080CA590:
	ldr r0, .L080CA5C0
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne .L080CA5EA
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #3
	beq .L080CA5C4
	ldrh r0, [r2, #4]
	cmp r0, #0
	bne .L080CA5D8
	ldrh r4, [r2, #0x20]
	adds r0, r4, #1
	movs r1, #1
	ands r0, r1
	strh r0, [r2, #0x20]
	b .L080CA5DA
	.byte 0x00, 0x00
.L080CA5B8: .4byte gUnknown_080014C0
.L080CA5BC: .4byte 0x03000004 @ IWRAM+0x4
.L080CA5C0: .4byte 0x030031BC @ IWRAM+0x31BC
.L080CA5C4:
	mov r3, sb
	ldrh r0, [r3, #4]
	cmp r0, #1
	bne .L080CA5D8
	ldrh r4, [r3, #0x20]
	adds r0, r4, #1
	movs r1, #1
	ands r0, r1
	strh r0, [r3, #0x20]
	b .L080CA5DA
.L080CA5D8:
	movs r4, #0
.L080CA5DA:
	ldr r0, [sp, #0x10]
	adds r1, r4, #0
	bl sub_080C97F0
	ldr r0, [sp, #0x10]
	adds r1, r4, #0
	bl sub_080C9854
.L080CA5EA:
	mov r1, sb
	ldrh r0, [r1]
	subs r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L080CA670
	ldrh r0, [r1, #0x2c]
	cmp r0, #5
	bhi .L080CA650
	lsls r0, r0, #2
	ldr r1, .L080CA608
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080CA608: .4byte gUnknown_080CA60C
	.global gUnknown_080CA60C
gUnknown_080CA60C:
.L080CA60C: @ jump table
	.4byte .L080CA624
	.4byte .L080CA628
	.4byte .L080CA630
	.4byte .L080CA63A
	.4byte .L080CA63E
	.4byte .L080CA648
.L080CA624:
	movs r2, #5
	b .L080CA632
.L080CA628:
	movs r0, #0x52
	str r0, [sp, #0x28]
	movs r1, #0x82
	b .L080CA64E
.L080CA630:
	movs r2, #0x9f
.L080CA632:
	str r2, [sp, #0x28]
	movs r3, #0x82
	str r3, [sp, #0x2c]
	b .L080CA650
.L080CA63A:
	movs r0, #5
	b .L080CA64A
.L080CA63E:
	movs r2, #0x52
	str r2, [sp, #0x28]
	movs r3, #0x8f
	str r3, [sp, #0x2c]
	b .L080CA650
.L080CA648:
	movs r0, #0x9f
.L080CA64A:
	str r0, [sp, #0x28]
	movs r1, #0x8f
.L080CA64E:
	str r1, [sp, #0x2c]
.L080CA650:
	ldr r0, .L080CA680
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r2, [sp, #0x28]
	str r2, [sp, #4]
	ldr r1, [sp, #0x2c]
	adds r1, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #2
	bl Sprite_Draw
.L080CA670:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CA680: .4byte gUnknown_08001770
