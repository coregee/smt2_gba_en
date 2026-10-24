	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_08129D08
sub_08129D08: @ 0x08129D08
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08129D48
	movs r1, #0
	strh r1, [r5, #0x1c]
	ldr r1, .L08129D4C
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne .L08129D40
	ldr r4, .L08129D50
	ldr r1, .L08129D54
	adds r0, r1, #0
	ldrh r1, [r4, #6]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r1, [r4, #2]
	bl sub_080EAF1C
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	strh r0, [r5, #0x1c]
.L08129D40:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08129D48: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129D4C: .4byte 0x00000694
.L08129D50: .4byte 0x030065C0 @ IWRAM+0x65C0
.L08129D54: .4byte 0xFFFF8000

	thumb_func_start sub_08129D58
sub_08129D58: @ 0x08129D58
.L08129D58:
	push {r4, lr}
	ldr r4, .L08129D6C
	ldr r0, .L08129D70
	ldr r1, .L08129D74
	bl Task_Create
	str r0, [r4, #0x48]
	pop {r4}
	pop {r0}
	bx r0
.L08129D6C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129D70: .4byte gUnknown_087784CC
.L08129D74: .4byte 0x0000FFFF

	thumb_func_start sub_08129D78
sub_08129D78: @ 0x08129D78
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r6, .L08129DA4
	movs r5, #0
	strh r5, [r4, #0x1e]
	bl sub_080EA210
	movs r0, #3
	bl sub_08127A98
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne .L08129DAC
	ldr r1, .L08129DA8
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	strh r0, [r4, #0x1e]
	b .L08129DE8
.L08129DA4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129DA8: .4byte gUnknown_0812416C
.L08129DAC:
	movs r4, #1
	str r4, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r6, #0x4c]
	str r4, [sp]
	movs r0, #0x11
	movs r1, #0
	movs r2, #0xc
	movs r3, #6
	bl TextWindow_Create
	str r0, [r6, #0x50]
	bl sub_081272AC
	str r5, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
	ldr r1, .L08129DF0
	movs r0, #4
	bl BattleMenu_SetMode
.L08129DE8:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08129DF0: .4byte gUnknown_08124154

	thumb_func_start sub_08129DF4
sub_08129DF4: @ 0x08129DF4
	push {r4, lr}
	movs r0, #2
	bl sub_08126D1C
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	movs r0, #0
	bl sub_08127EAC
	ldrh r1, [r4, #0x12]
	movs r0, #0
	bl sub_081283C4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_08129E14
sub_08129E14: @ 0x08129E14
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #2
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r6, [r5, #0x12]
	movs r0, #2
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r0, .L08129E44
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08129E48
	movs r0, #0x80
	lsls r0, r0, #1
	b .L08129E50
	.byte 0x00, 0x00
.L08129E44: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08129E48:
	ldrb r0, [r5]
	cmp r0, #3
	bne .L08129E56
	ldrh r0, [r5, #0x12]
.L08129E50:
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
.L08129E56:
	ldr r0, .L08129ED8
	movs r4, #0
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L08129EBA
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L08129E9A
	ldr r0, .L08129EDC
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L08129E9A:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r1, [r5, #0xa]
	cmp r0, r1
	beq .L08129EBA
	ldr r0, .L08129EE0
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L08129EBA:
	ldrh r0, [r5, #0x12]
	cmp r6, r0
	beq .L08129ED0
	ldrh r1, [r5, #0xc]
	movs r0, #0
	bl sub_08127EAC
	ldrh r1, [r5, #0x12]
	movs r0, #0
	bl sub_081283C4
.L08129ED0:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08129ED8: .4byte gUnknown_08000EA4
.L08129EDC: .4byte gUnknown_08000FF0
.L08129EE0: .4byte gUnknown_08001000

	thumb_func_start sub_08129EE4
sub_08129EE4: @ 0x08129EE4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	bl BattleMsg_IsDone
	cmp r0, #1
	bne .L08129EF6
	strh r0, [r4, #0x1c]
.L08129EF6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_08129EFC
sub_08129EFC: @ 0x08129EFC
	push {lr}
	bl BattleMsg_Close
	bl sub_08128EB4
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0

	thumb_func_start sub_08129F10
sub_08129F10: @ 0x08129F10
	push {r4, lr}
	ldr r4, .L08129F38
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L08129F20
	movs r1, #0
	bl TextWindow_Close
.L08129F20:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L08129F2C
	movs r1, #0
	bl TextWindow_Close
.L08129F2C:
	bl sub_08128388
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08129F38: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_08129F3C
sub_08129F3C: @ 0x08129F3C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	movs r0, #3
	bl sub_08127A98
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08129F54
	movs r0, #1
	strh r0, [r4, #0x1c]
.L08129F54:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08129F5C
sub_08129F5C: @ 0x08129F5C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r6, .L08129F80
	movs r2, #0
	ldr r0, .L08129F84
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r5, r0, r1
	movs r1, #0
	ldrsb r1, [r5, r1]
	ldrh r0, [r4, #0x1e]
	lsls r0, r0, #1
	movs r7, #0xb4
	lsls r7, r7, #2
	adds r3, r6, r7
	adds r0, r0, r3
	ldr r7, .L08129F88
	b .L08129FA2
.L08129F80: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129F84: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08129F88: .4byte gUnknown_08124182
.L08129F8C:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #5
	bhi .L08129FA8
	adds r0, r2, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r4, #0x1e]
	lsls r0, r0, #1
	adds r0, r3, r0
.L08129FA2:
	ldrh r0, [r0]
	cmp r1, r0
	bne .L08129F8C
.L08129FA8:
	adds r0, r2, #0
	adds r1, r7, #0
	bl Battle_BuildNamePrependText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldrh r1, [r4, #0x1e]
	lsls r1, r1, #1
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r6, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0
	bl sub_080C0290
	bl sub_080C366C
	movs r0, #2
	bl sub_081269B0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08129FDC
sub_08129FDC: @ 0x08129FDC
.L08129FDC:
	push {r4, lr}
	ldr r4, .L08129FF0
	ldr r0, .L08129FF4
	ldr r1, .L08129FF8
	bl Task_Create
	str r0, [r4, #0x48]
	pop {r4}
	pop {r0}
	bx r0
.L08129FF0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L08129FF4: .4byte gUnknown_08778614
.L08129FF8: .4byte 0x0000FFFF

	thumb_func_start sub_08129FFC
sub_08129FFC: @ 0x08129FFC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r7, .L0812A030
	movs r5, #0
	strh r5, [r4, #0x1e]
	cmp r6, #0
	bne .L0812A012
	bl sub_080EA210
.L0812A012:
	movs r0, #2
	bl sub_08127A98
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne .L0812A038
	ldr r1, .L0812A034
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	strh r0, [r4, #0x1e]
	b .L0812A08E
	.byte 0x00, 0x00
.L0812A030: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A034: .4byte gUnknown_0812439A
.L0812A038:
	movs r4, #1
	str r4, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r7, #0x4c]
	str r4, [sp]
	movs r0, #0x11
	movs r1, #0
	movs r2, #0xc
	movs r3, #6
	bl TextWindow_Create
	str r0, [r7, #0x50]
	bl sub_081272AC
	cmp r5, #4
	bhi .L0812A072
	str r5, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
	b .L0812A082
.L0812A072:
	movs r0, #5
	str r0, [sp]
	movs r0, #2
	movs r1, #0x10
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
.L0812A082:
	cmp r6, #0
	bne .L0812A08E
	ldr r1, .L0812A098
	movs r0, #4
	bl BattleMenu_SetMode
.L0812A08E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812A098: .4byte gUnknown_08124364

	thumb_func_start sub_0812A09C
sub_0812A09C: @ 0x0812A09C
	push {r4, lr}
	movs r0, #2
	bl sub_08126D1C
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	movs r0, #0
	bl sub_08127EAC
	ldrh r1, [r4, #0x12]
	movs r0, #0
	bl sub_081283C4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0812A0BC
sub_0812A0BC: @ 0x0812A0BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov r8, r1
	movs r0, #2
	bl sub_08126D1C
	adds r4, r0, #0
	ldrb r7, [r4, #0x12]
	movs r0, #2
	bl sub_08126A08
	movs r1, #0
	movs r0, #0
	strh r0, [r5, #0x1e]
	adds r2, r5, #0
	adds r2, #0x24
	strb r1, [r2]
	strh r0, [r5, #0x1c]
	ldr r0, .L0812A0FC
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812A100
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r5, #0x1e]
	b .L0812A10E
	.byte 0x00, 0x00
.L0812A0FC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812A100:
	ldrb r0, [r4]
	cmp r0, #3
	bne .L0812A112
	ldrh r0, [r4, #0x12]
	strh r0, [r5, #0x1e]
	ldrh r0, [r4, #0x12]
	strb r0, [r2]
.L0812A10E:
	movs r0, #1
	strh r0, [r5, #0x1c]
.L0812A112:
	ldr r0, .L0812A1B8
	movs r6, #0
	str r6, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r4, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r4, #0xa]
	cmp r0, #5
	bls .L0812A176
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	beq .L0812A156
	ldr r0, .L0812A1BC
	str r6, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812A156:
	ldrh r0, [r4, #0xc]
	adds r0, #5
	ldrh r1, [r4, #0xa]
	cmp r0, r1
	beq .L0812A176
	ldr r0, .L0812A1C0
	str r6, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812A176:
	ldrh r0, [r4, #0x12]
	cmp r7, r0
	beq .L0812A18C
	ldrh r1, [r4, #0xc]
	movs r0, #0
	bl sub_08127EAC
	ldrh r1, [r4, #0x12]
	movs r0, #0
	bl sub_081283C4
.L0812A18C:
	mov r1, r8
	cmp r1, #1
	bne .L0812A1AA
	ldr r0, .L0812A1C4
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	movs r0, #0
	strb r0, [r5, #6]
.L0812A1AA:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812A1B8: .4byte gUnknown_08000EA4
.L0812A1BC: .4byte gUnknown_08000FF0
.L0812A1C0: .4byte gUnknown_08001000
.L0812A1C4: .4byte gUnknown_08124364

	thumb_func_start sub_0812A1C8
sub_0812A1C8: @ 0x0812A1C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, .L0812A224
	movs r0, #0
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r1, [r0]
	lsls r1, r1, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	ldrh r0, [r0, #0x12]
	movs r1, #1
	bl sub_0815B8F8
	rsbs r1, r0, #0
	orrs r1, r0
	cmp r1, #0
	blt .L0812A21E
	movs r0, #0x6e
	bl sub_080EC038
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
.L0812A21E:
	pop {r4}
	pop {r0}
	bx r0
.L0812A224: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812A228
sub_0812A228: @ 0x0812A228
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	movs r0, #2
	bl sub_08127A98
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0812A240
	movs r0, #1
	strh r0, [r4, #0x1c]
.L0812A240:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812A248
sub_0812A248: @ 0x0812A248
	push {lr}
	ldr r1, .L0812A270
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_080F41B0
	bl sub_080C366C
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812A270: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812A274
sub_0812A274: @ 0x0812A274
	push {lr}
	bl BattleMsg_Close
	bl sub_08128EB4
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0

	thumb_func_start sub_0812A288
sub_0812A288: @ 0x0812A288
	push {lr}
	bl BattleMenu_Reset
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0

	thumb_func_start sub_0812A298
sub_0812A298: @ 0x0812A298
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, .L0812A2E0
	ldr r0, .L0812A2E4
	adds r6, r5, r0
	movs r0, #0
	bl YesNo_Create
	str r0, [r6, #4]
	adds r4, #0x24
	ldrb r1, [r4]
	lsls r1, r1, #1
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r5, r5, r2
	adds r1, r1, r5
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L0812A2E8
	bl Battle_BuildNamePrependText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl sub_080EC99C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0812A2E0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A2E4: .4byte 0x0000110C
.L0812A2E8: .4byte gUnknown_0812437C

	thumb_func_start sub_0812A2EC
sub_0812A2EC: @ 0x0812A2EC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, .L0812A318
	ldr r1, .L0812A31C
	adds r6, r0, r1
	movs r5, #0
	strh r5, [r4, #0x1c]
	ldr r0, [r6, #4]
	bl Task_IsFree
	adds r1, r0, #0
	cmp r1, #1
	bne .L0812A332
	ldr r0, .L0812A320
	ldr r0, [r0]
	cmp r0, #1
	beq .L0812A324
	cmp r0, #0
	bne .L0812A324
	strh r1, [r4, #0x1e]
	b .L0812A326
	.byte 0x00, 0x00
.L0812A318: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A31C: .4byte 0x0000110C
.L0812A320: .4byte 0x030031CC @ IWRAM+0x31CC
.L0812A324:
	strh r5, [r4, #0x1e]
.L0812A326:
	ldr r0, [r6, #4]
	movs r1, #0
	bl Window_Close
	movs r0, #1
	strh r0, [r4, #0x1c]
.L0812A332:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_0812A338
sub_0812A338: @ 0x0812A338
	push {r4, r5, lr}
	ldr r1, .L0812A378
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r5, #0
	bl sub_080C0148
	adds r0, r4, #0
	bl sub_080C0A00
	cmp r0, #0
	beq .L0812A380
	ldr r1, .L0812A37C
	adds r0, r5, #0
	bl Battle_BuildNamePrependText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	b .L0812A390
.L0812A378: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A37C: .4byte gUnknown_081243C6
.L0812A380:
	ldr r1, .L0812A398
	adds r0, r5, #0
	bl Battle_BuildNamePrependText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
.L0812A390:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812A398: .4byte gUnknown_081243B0

	thumb_func_start sub_0812A39C
sub_0812A39C: @ 0x0812A39C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov r8, r0
	ldr r0, .L0812A4C8
	mov sb, r0
	movs r0, #2
	bl sub_08126D1C
	adds r4, r0, #0
	ldrb r6, [r4, #0x12]
	ldr r0, .L0812A4CC
	movs r5, #0
	str r5, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r4, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r4, #0xa]
	cmp r0, #5
	bls .L0812A41A
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	beq .L0812A3FA
	ldr r0, .L0812A4D0
	str r5, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812A3FA:
	ldrh r0, [r4, #0xc]
	adds r0, #5
	ldrh r1, [r4, #0xa]
	cmp r0, r1
	beq .L0812A41A
	ldr r0, .L0812A4D4
	str r5, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812A41A:
	ldrh r2, [r4, #0x12]
	cmp r6, r2
	beq .L0812A430
	ldrh r1, [r4, #0xc]
	movs r0, #0
	bl sub_08127EAC
	ldrh r1, [r4, #0x12]
	movs r0, #0
	bl sub_081283C4
.L0812A430:
	mov r1, r8
	ldrb r0, [r1, #6]
	cmp r0, #1
	bne .L0812A4E0
	movs r6, #0x12
	movs r7, #0x59
	mov r0, r8
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, sb
	adds r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r0, [r0, #0x12]
	bl sub_080BF648
	movs r4, #0
	adds r1, r0, #0
	adds r1, #0x22
	ldrh r0, [r0, #0x22]
	cmp r0, #0
	beq .L0812A4A0
	adds r5, r1, #0
.L0812A472:
	lsls r0, r4, #1
	adds r0, r5, r0
	ldrh r0, [r0]
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl FontSprite_DrawGlyph
	adds r0, r6, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #7
	bhi .L0812A4A0
	lsls r0, r4, #1
	adds r0, r5, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0812A472
.L0812A4A0:
	ldr r0, .L0812A4D8
	str r7, [sp]
	movs r4, #0xc
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl Text_DrawSpriteString
	ldr r0, .L0812A4DC
	adds r1, r7, #0
	adds r1, #0xc
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	b .L0812A4F8
.L0812A4C8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A4CC: .4byte gUnknown_08000EA4
.L0812A4D0: .4byte gUnknown_08000FF0
.L0812A4D4: .4byte gUnknown_08001000
.L0812A4D8: .4byte gUnknown_0800354A
.L0812A4DC: .4byte gUnknown_08003556
.L0812A4E0:
	cmp r0, #2
	bne .L0812A4F8
	ldr r0, .L0812A508
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
.L0812A4F8:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812A508: .4byte gUnknown_08003568

	thumb_func_start sub_0812A50C
sub_0812A50C: @ 0x0812A50C
	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r3, .L0812A538
	ldrh r1, [r3]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne .L0812A52C
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812A532
.L0812A52C:
	strh r4, [r2, #0x1c]
	movs r0, #0
	strb r0, [r2, #6]
.L0812A532:
	pop {r4}
	pop {r0}
	bx r0
.L0812A538: .4byte 0x030031B8 @ IWRAM+0x31B8

	thumb_func_start sub_0812A53C
sub_0812A53C: @ 0x0812A53C
	push {r4, lr}
	ldr r4, .L0812A554
	ldr r0, .L0812A558
	adds r4, r4, r0
	movs r0, #0
	bl YesNo_Create
	str r0, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812A554: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A558: .4byte 0x0000110C

	thumb_func_start sub_0812A55C
sub_0812A55C: @ 0x0812A55C
	push {lr}
	ldr r2, .L0812A580
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r1, r2, r3
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, .L0812A584
	adds r2, r2, r1
	strh r0, [r2]
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0
.L0812A580: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A584: .4byte 0x0000118E

	thumb_func_start sub_0812A588
sub_0812A588: @ 0x0812A588
	push {lr}
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0

	thumb_func_start sub_0812A594
sub_0812A594: @ 0x0812A594
	push {lr}
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0

	thumb_func_start sub_0812A5A0
sub_0812A5A0: @ 0x0812A5A0
	ldr r0, .L0812A5AC
	ldr r1, .L0812A5B0
	adds r0, r0, r1
	ldr r1, .L0812A5B4
	strh r1, [r0]
	bx lr
.L0812A5AC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A5B0: .4byte 0x0000118E
.L0812A5B4: .4byte 0x0000FFFF

	thumb_func_start sub_0812A5B8
sub_0812A5B8: @ 0x0812A5B8
	ldr r0, .L0812A5C0
	str r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L0812A5C0: .4byte 0x030031CC @ IWRAM+0x31CC

	thumb_func_start sub_0812A5C4
sub_0812A5C4: @ 0x0812A5C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, .L0812A60C
	movs r0, #0
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r1, [r0]
	lsls r1, r1, #1
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	ldrh r0, [r0, #0x12]
	movs r1, #1
	bl sub_0815B8F8
	rsbs r1, r0, #0
	orrs r1, r0
	cmp r1, #0
	blt .L0812A610
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #2
	b .L0812A612
	.byte 0x00, 0x00
.L0812A60C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A610:
	movs r0, #1
.L0812A612:
	strb r0, [r4, #6]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812A61C
sub_0812A61C: @ 0x0812A61C
	push {lr}
	cmp r1, #0
	bne .L0812A630
	bl sub_080C6FF0
	bl sub_080C7414
	bl sub_080C762C
	b .L0812A63C
.L0812A630:
	bl sub_080C700C
	bl sub_080C7430
	bl sub_080C7648
.L0812A63C:
	pop {r0}
	bx r0

	thumb_func_start sub_0812A640
sub_0812A640: @ 0x0812A640
.L0812A640:
	push {lr}
	ldr r0, .L0812A658
	ldr r1, .L0812A65C
	adds r0, r0, r1
	ldr r1, .L0812A660
	strh r1, [r0]
	ldr r0, .L0812A664
	bl Task_Create
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0812A658: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A65C: .4byte 0x0000118E
.L0812A660: .4byte 0x0000FFFF
.L0812A664: .4byte gUnknown_087787F8

	thumb_func_start sub_0812A668
sub_0812A668: @ 0x0812A668
.L0812A668:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L0812A6B0
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r6, r1, r2
	movs r7, #0
	bl sub_080C9210
	adds r5, r0, #0
	ldrh r4, [r5]
	ldr r0, .L0812A6B4
	cmp r4, r0
	beq .L0812A6DA
	mov r8, r0
.L0812A68C:
	movs r0, #0xb6
	bl Flag_Test
	cmp r0, #0
	beq .L0812A6B8
	ldrh r0, [r5, #2]
	cmp r0, #0
	bne .L0812A6D2
	adds r0, r4, #0
	bl sub_080C2554
	cmp r0, #0
	bne .L0812A6C8
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, r1
	strh r0, [r6]
	b .L0812A6CA
.L0812A6B0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A6B4: .4byte 0x0000FFFF
.L0812A6B8:
	ldrh r0, [r5, #2]
	cmp r0, #0
	bne .L0812A6D2
	adds r0, r4, #0
	bl sub_080C2554
	cmp r0, #0
	beq .L0812A6D2
.L0812A6C8:
	strh r4, [r6]
.L0812A6CA:
	adds r6, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L0812A6D2:
	adds r5, #4
	ldrh r4, [r5]
	cmp r4, r8
	bne .L0812A68C
.L0812A6DA:
	ldr r2, .L0812A6EC
	adds r0, r2, #0
	strh r0, [r6]
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L0812A6EC: .4byte 0x0000FFFF

	thumb_func_start sub_0812A6F0
sub_0812A6F0: @ 0x0812A6F0
.L0812A6F0:
	push {r4, lr}
	ldr r4, .L0812A704
	ldr r0, .L0812A708
	ldr r1, .L0812A70C
	bl Task_Create
	str r0, [r4, #0x48]
	pop {r4}
	pop {r0}
	bx r0
.L0812A704: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A708: .4byte gUnknown_08778ADC
.L0812A70C: .4byte 0x0000FFFF

	thumb_func_start sub_0812A710
sub_0812A710: @ 0x0812A710
.L0812A710:
	push {r4, lr}
	ldr r4, .L0812A724
	ldr r0, .L0812A728
	ldr r1, .L0812A72C
	bl Task_Create
	str r0, [r4, #0x48]
	pop {r4}
	pop {r0}
	bx r0
.L0812A724: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A728: .4byte gUnknown_08778CB4
.L0812A72C: .4byte 0x0000FFFF

	thumb_func_start sub_0812A730
sub_0812A730: @ 0x0812A730
.L0812A730:
	push {r4, r5, lr}
	ldr r5, .L0812A774
	movs r0, #0xe5
	bl Flag_Test
	adds r1, r0, #0
	cmp r1, #1
	bne .L0812A7B2
	ldr r2, .L0812A778
	adds r0, r5, r2
	strb r1, [r0]
	bl BattleMenu_Reset
	bl sub_080F3190
	adds r4, r0, #0
	cmp r4, #0
	bne .L0812A784
	ldr r0, .L0812A77C
	ldr r1, .L0812A780
	bl Task_Create
	str r0, [r5, #0x48]
	bl sub_080C6FF0
	bl sub_080C7414
	bl sub_080C7218
	bl sub_080C7C60
	movs r0, #1
	b .L0812A7B4
	.byte 0x00, 0x00
.L0812A774: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A778: .4byte 0x00000696
.L0812A77C: .4byte gUnknown_08778ADC
.L0812A780: .4byte 0x0000FFFF
.L0812A784:
	ldr r0, .L0812A7BC
	ldr r1, .L0812A7C0
	bl Task_Create
	str r0, [r5, #0x44]
	bl sub_080EA210
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080EC038
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	bl sub_080B1BC4
	movs r0, #0x68
	bl sub_080C51D4
.L0812A7B2:
	movs r0, #0
.L0812A7B4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0812A7BC: .4byte gUnknown_0877812C
.L0812A7C0: .4byte 0x0000FFFF

	thumb_func_start sub_0812A7C4
sub_0812A7C4: @ 0x0812A7C4
.L0812A7C4:
	push {lr}
	movs r0, #0xe5
	bl Flag_Test
	cmp r0, #1
	bne .L0812A7DC
	bl sub_080F3190
	cmp r0, #0
	bne .L0812A7DC
	movs r0, #1
	b .L0812A7DE
.L0812A7DC:
	movs r0, #0
.L0812A7DE:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0812A7E4
sub_0812A7E4: @ 0x0812A7E4
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, .L0812A81C
	movs r0, #0
	strh r0, [r4, #0x1e]
	bl sub_0812A668
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0812A824
	bl sub_080EA210
	ldr r0, .L0812A820
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #0x68
	bl sub_080C51D4
	movs r0, #1
	strh r0, [r4, #0x1e]
	b .L0812A856
	.byte 0x00, 0x00
.L0812A81C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A820: .4byte gUnknown_08124A62
.L0812A824:
	movs r0, #1
	str r0, [sp]
	movs r0, #9
	movs r1, #1
	movs r2, #0xc
	movs r3, #7
	bl TextWindow_Create
	str r0, [r5, #0x4c]
	ldr r0, .L0812A860
	ldr r1, .L0812A864
	bl sub_080C7E24
	ldr r0, .L0812A868
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #4
	str r0, [sp]
	movs r0, #2
	movs r1, #1
	movs r2, #1
	movs r3, #4
	bl sub_08126928
.L0812A856:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812A860: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812A864: .4byte gUnknown_08778A9C
.L0812A868: .4byte sub_08128F28

	thumb_func_start sub_0812A86C
sub_0812A86C: @ 0x0812A86C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r7, .L0812A8BC
	movs r0, #2
	bl sub_08126D1C
	adds r6, r0, #0
	ldrh r0, [r6, #0x18]
	mov r8, r0
	movs r0, #2
	bl sub_08126A08
	cmp r5, #1
	bne .L0812A89A
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq .L0812A89A
	movs r5, #0
.L0812A89A:
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r2, .L0812A8C0
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812A8C4
	cmp r5, #0
	bne .L0812A8C4
	movs r0, #0xff
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L0812A93E
	.byte 0x00, 0x00
.L0812A8BC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812A8C0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812A8C4:
	ldrh r1, [r2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812A8E4
	ldrh r0, [r6, #0x18]
	strh r0, [r4, #0x1e]
	ldrh r1, [r6, #0x18]
	ldr r3, .L0812A8E0
	adds r0, r7, r3
	strb r1, [r0]
	strh r2, [r4, #0x1c]
	b .L0812A93E
.L0812A8E0: .4byte 0x00000697
.L0812A8E4:
	ldrb r0, [r6]
	cmp r0, #6
	bne .L0812A91C
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812A900
	bl BattleMenu_Reset
	bl BattleMsg_Close
	b .L0812A93E
.L0812A900:
	bl sub_080EA210
	ldr r0, .L0812A918
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
	b .L0812A93E
	.byte 0x00, 0x00
.L0812A918: .4byte gUnknown_08778ACC
.L0812A91C:
	ldrh r2, [r6, #0x18]
	cmp r8, r2
	beq .L0812A93E
	movs r3, #0xfc
	lsls r3, r3, #3
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812A93E
	ldr r0, .L0812A9DC
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L0812A93E:
	ldr r0, .L0812A9E0
	movs r1, #0
	str r1, [sp]
	movs r1, #0x4c
	str r1, [sp, #4]
	ldrh r2, [r6, #0x18]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0xa0
	lsls r2, r2, #0xc
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r6, #0
	ldr r3, .L0812A9E4
	mov r8, r3
	movs r7, #0
	movs r0, #8
	add r0, r8
	mov sb, r0
.L0812A972:
	lsls r5, r6, #4
	mov r1, r8
	adds r0, r5, r1
	str r7, [sp]
	movs r1, #0x50
	str r1, [sp, #4]
	lsls r4, r6, #1
	adds r4, r4, r6
	lsls r4, r4, #0x12
	movs r2, #0xe0
	lsls r2, r2, #0xc
	adds r4, r4, r2
	lsrs r4, r4, #0x10
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	add r5, sb
	str r7, [sp]
	movs r0, #0x70
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	str r7, [sp]
	movs r0, #0x80
	str r0, [sp, #4]
	str r4, [sp, #8]
	ldr r0, .L0812A9E8
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bls .L0812A972
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812A9DC: .4byte gUnknown_08778ACC
.L0812A9E0: .4byte gUnknown_08000EE4
.L0812A9E4: .4byte gUnknown_08777F60
.L0812A9E8: .4byte gUnknown_08778AC4

	thumb_func_start sub_0812A9EC
sub_0812A9EC: @ 0x0812A9EC
	push {r4, lr}
	ldr r1, .L0812AA00
	ldr r2, .L0812AA04
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0812AA08
	bl sub_08128EB4
	b .L0812AA46
.L0812AA00: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812AA04: .4byte 0x00000696
.L0812AA08:
	movs r2, #0xfc
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812AA18
	bl BattleMsg_Close
.L0812AA18:
	bl sub_081279D4
	ldr r4, .L0812AA30
	ldrh r0, [r4]
	cmp r0, #0x1b
	bne .L0812AA34
	movs r0, #0x1e
	bl Field_SetState
	movs r0, #0
	strh r0, [r4, #0x1e]
	b .L0812AA3A
.L0812AA30: .4byte 0x03004550 @ IWRAM+0x4550
.L0812AA34:
	movs r0, #1
	bl Field_SetState
.L0812AA3A:
	bl sub_080C7234
	bl sub_080C762C
	bl sub_080C7C94
.L0812AA46:
	movs r0, #2
	bl sub_081269B0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812AA54
sub_0812AA54: @ 0x0812AA54
	push {r4, lr}
	ldr r0, .L0812AA68
	ldr r1, .L0812AA6C
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0812AA70
	bl sub_08128EB4
	b .L0812AA9E
.L0812AA68: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812AA6C: .4byte 0x00000696
.L0812AA70:
	bl sub_081279D4
	ldr r4, .L0812AA88
	ldrh r0, [r4]
	cmp r0, #0x1b
	bne .L0812AA8C
	movs r0, #0x1e
	bl Field_SetState
	movs r0, #0
	strh r0, [r4, #0x1e]
	b .L0812AA92
.L0812AA88: .4byte 0x03004550 @ IWRAM+0x4550
.L0812AA8C:
	movs r0, #1
	bl Field_SetState
.L0812AA92:
	bl sub_080C7234
	bl sub_080C762C
	bl sub_080C7C94
.L0812AA9E:
	bl BattleMsg_Close
	movs r0, #2
	bl sub_081269B0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812AAB0
sub_0812AAB0: @ 0x0812AAB0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r1, #0
	ldr r4, .L0812AB08
	movs r5, #1
	str r5, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r4, #0x4c]
	str r5, [sp]
	movs r0, #0x11
	movs r1, #0
	movs r2, #0xc
	movs r3, #6
	bl TextWindow_Create
	str r0, [r4, #0x50]
	bl sub_081272AC
	ldr r0, .L0812AB0C
	adds r4, r4, r0
	ldrb r0, [r4]
	bl sub_0812A668
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #2
	bl sub_081269B0
	cmp r4, #4
	bhi .L0812AB10
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #1
	adds r3, r4, #0
	bl sub_08126928
	b .L0812AB20
	.byte 0x00, 0x00
.L0812AB08: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812AB0C: .4byte 0x00000697
.L0812AB10:
	movs r0, #5
	str r0, [sp]
	movs r0, #2
	movs r1, #0x10
	movs r2, #1
	adds r3, r4, #0
	bl sub_08126928
.L0812AB20:
	cmp r6, #1
	bne .L0812AB2A
	movs r0, #1
	bl sub_0812AC68
.L0812AB2A:
	bl sub_080EA210
	ldr r1, .L0812AB40
	movs r0, #4
	bl BattleMenu_SetMode
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812AB40: .4byte gUnknown_08123DF0

	thumb_func_start sub_0812AB44
sub_0812AB44: @ 0x0812AB44
	push {r4, lr}
	movs r0, #2
	bl sub_08126D1C
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	movs r0, #1
	bl sub_08127EAC
	ldrh r1, [r4, #0x12]
	movs r0, #2
	bl sub_081283C4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0812AB64
sub_0812AB64: @ 0x0812AB64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r6, .L0812ABA0
	movs r0, #2
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	mov r8, r0
	movs r0, #2
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r2, .L0812ABA4
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812ABA8
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L0812ABD6
.L0812ABA0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812ABA4: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812ABA8:
	ldrh r1, [r2]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812ABD6
	ldrh r2, [r5, #0x12]
	lsls r0, r2, #1
	movs r7, #0xb4
	lsls r7, r7, #2
	adds r1, r6, r7
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L0812ABD6
	strh r2, [r4, #0x1e]
	strh r3, [r4, #0x1c]
	movs r0, #0
	bl sub_0812AC68
.L0812ABD6:
	ldr r0, .L0812AC5C
	movs r4, #0
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L0812AC3A
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L0812AC1A
	ldr r0, .L0812AC60
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812AC1A:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r1, [r5, #0xa]
	cmp r0, r1
	beq .L0812AC3A
	ldr r0, .L0812AC64
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812AC3A:
	ldrh r7, [r5, #0x12]
	cmp r8, r7
	beq .L0812AC50
	ldrh r1, [r5, #0xc]
	movs r0, #1
	bl sub_08127EAC
	ldrh r1, [r5, #0x12]
	movs r0, #2
	bl sub_081283C4
.L0812AC50:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0812AC5C: .4byte gUnknown_08000EA4
.L0812AC60: .4byte gUnknown_08000FF0
.L0812AC64: .4byte gUnknown_08001000

	thumb_func_start sub_0812AC68
sub_0812AC68: @ 0x0812AC68
.L0812AC68:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne .L0812AC84
	movs r0, #2
	bl sub_08126D1C
	adds r4, r0, #0
	ldr r1, .L0812AC80
	b .L0812AC8E
	.byte 0x00, 0x00
.L0812AC80: .4byte 0x03006450 @ IWRAM+0x6450
.L0812AC84:
	ldr r4, .L0812ACB4
	movs r0, #2
	bl sub_08126D1C
	adds r1, r0, #0
.L0812AC8E:
	movs r2, #0
.L0812AC90:
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, #1
	adds r1, #1
	adds r2, #1
	cmp r2, #0x27
	bls .L0812AC90
	cmp r5, #1
	bne .L0812ACAC
	ldr r0, .L0812ACB4
	ldrh r1, [r0, #0x12]
	movs r0, #2
	bl sub_08127960
.L0812ACAC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812ACB4: .4byte 0x03006450 @ IWRAM+0x6450

	thumb_func_start sub_0812ACB8
sub_0812ACB8: @ 0x0812ACB8
	push {lr}
	ldrh r1, [r0, #0x1e]
	movs r0, #0
	bl sub_080CB01C
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0

	thumb_func_start sub_0812ACCC
sub_0812ACCC: @ 0x0812ACCC
.L0812ACCC:
	lsls r0, r0, #0x10
	ldr r1, .L0812ACE0
	lsrs r0, r0, #0xf
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L0812ACE0: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812ACE4
sub_0812ACE4: @ 0x0812ACE4
.L0812ACE4:
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r6, .L0812AD10
	movs r0, #0
	str r0, [sp]
	ldr r2, .L0812AD14
	mov r0, sp
	adds r1, r6, #0
	bl CpuFastSet
	ldr r5, .L0812AD18
	ldr r2, .L0812AD1C
	adds r1, r6, #0
	movs r4, #0xad
	lsls r4, r4, #1
.L0812AD02:
	ldr r0, [r5]
	cmp r0, #0
	bne .L0812AD20
	strh r0, [r1]
	strh r2, [r1, #2]
	b .L0812AD28
	.byte 0x00, 0x00
.L0812AD10: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812AD14: .4byte 0x0100015A
.L0812AD18: .4byte 0x030051AC @ IWRAM+0x51AC
.L0812AD1C: .4byte 0x00000FFF
.L0812AD20:
	ldrh r0, [r5, #2]
	strh r0, [r1]
	ldrh r0, [r5]
	strh r0, [r1, #2]
.L0812AD28:
	adds r5, #4
	adds r1, #4
	subs r4, #1
	cmp r4, #0
	bne .L0812AD02
	ldr r5, .L0812AD6C
	movs r4, #0xad
	lsls r4, r4, #1
	movs r0, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl sub_080EDB6C
	movs r3, #1
	rsbs r3, r3, #0
	adds r1, r6, #0
.L0812AD48:
	ldrh r2, [r1, #2]
	movs r6, #2
	ldrsh r0, [r1, r6]
	cmp r0, r3
	beq .L0812AD5A
	strh r2, [r5]
	ldrh r0, [r1]
	strh r0, [r5, #2]
	adds r5, #4
.L0812AD5A:
	adds r1, #4
	subs r4, #1
	cmp r4, #0
	bne .L0812AD48
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812AD6C: .4byte 0x030051AC @ IWRAM+0x51AC

	thumb_func_start sub_0812AD70
sub_0812AD70: @ 0x0812AD70
.L0812AD70:
	push {r4, lr}
	ldr r4, .L0812AD84
	ldr r0, .L0812AD88
	ldr r1, .L0812AD8C
	bl Task_Create
	str r0, [r4, #0x44]
	pop {r4}
	pop {r0}
	bx r0
.L0812AD84: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812AD88: .4byte gUnknown_08778E04
.L0812AD8C: .4byte 0x0000FFFF

	thumb_func_start sub_0812AD90
sub_0812AD90: @ 0x0812AD90
	push {r4, lr}
	sub sp, #4
	ldr r4, .L0812ADD4
	movs r0, #1
	str r0, [sp]
	movs r0, #9
	movs r1, #1
	movs r2, #0xc
	movs r3, #7
	bl TextWindow_Create
	str r0, [r4, #0x4c]
	ldr r0, .L0812ADD8
	ldr r1, .L0812ADDC
	bl sub_080C7E24
	ldr r0, .L0812ADE0
	movs r1, #1
	bl VBlankTask_AddCounted
	bl BattleMsg_Close
	movs r0, #4
	str r0, [sp]
	movs r0, #5
	movs r1, #1
	movs r2, #1
	movs r3, #4
	bl sub_08126928
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L0812ADD4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812ADD8: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812ADDC: .4byte gUnknown_08778DD0
.L0812ADE0: .4byte sub_08128F28

	thumb_func_start sub_0812ADE4
sub_0812ADE4: @ 0x0812ADE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r7, .L0812AE20
	movs r0, #5
	bl sub_08126D1C
	adds r5, r0, #0
	ldrh r6, [r5, #0x18]
	movs r0, #5
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r2, .L0812AE24
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812AE28
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L0812AE9E
.L0812AE20: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812AE24: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812AE28:
	ldrh r1, [r2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812AE44
	ldrh r0, [r5, #0x18]
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0
	strb r0, [r1]
	b .L0812AE9E
.L0812AE44:
	ldrb r0, [r5]
	cmp r0, #6
	bne .L0812AE7C
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812AE60
	bl BattleMenu_Reset
	bl BattleMsg_Close
	b .L0812AE9E
.L0812AE60:
	bl sub_080EA210
	ldr r0, .L0812AE78
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
	b .L0812AE9E
	.byte 0x00, 0x00
.L0812AE78: .4byte gUnknown_08778DF4
.L0812AE7C:
	ldrh r2, [r5, #0x18]
	cmp r6, r2
	beq .L0812AE9E
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812AE9E
	ldr r0, .L0812AF28
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L0812AE9E:
	ldr r0, .L0812AF2C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x4c
	str r1, [sp, #4]
	ldrh r2, [r5, #0x18]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0xa0
	lsls r2, r2, #0xc
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r6, #0
	ldr r0, .L0812AF30
	mov r8, r0
	movs r7, #0
	movs r1, #8
	add r1, r8
	mov sb, r1
.L0812AED2:
	lsls r5, r6, #4
	mov r2, r8
	adds r0, r5, r2
	str r7, [sp]
	movs r1, #0x58
	str r1, [sp, #4]
	lsls r4, r6, #1
	adds r4, r4, r6
	lsls r4, r4, #0x12
	movs r1, #0xe0
	lsls r1, r1, #0xc
	adds r4, r4, r1
	lsrs r4, r4, #0x10
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	add r5, sb
	str r7, [sp]
	movs r0, #0x78
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bls .L0812AED2
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812AF28: .4byte gUnknown_08778DF4
.L0812AF2C: .4byte gUnknown_08000EE4
.L0812AF30: .4byte gUnknown_08777F60

	thumb_func_start sub_0812AF34
sub_0812AF34: @ 0x0812AF34
	push {lr}
	movs r0, #1
	bl sub_08128B84
	movs r0, #5
	bl sub_081269B0
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812AF48
sub_0812AF48: @ 0x0812AF48
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_080EA210
	movs r0, #0xff
	bl sub_0812B320
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L0812AF78
	ldr r0, .L0812AF74
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	strh r4, [r5, #0x1c]
	b .L0812AF88
	.byte 0x00, 0x00
.L0812AF74: .4byte gUnknown_08124C20
.L0812AF78:
	ldr r1, .L0812AF90
	movs r0, #3
	bl BattleMenu_SetMode
	bl sub_0812ACE4
	movs r0, #1
	strh r0, [r5, #0x1c]
.L0812AF88:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812AF90: .4byte gUnknown_081244BA

	thumb_func_start sub_0812AF94
sub_0812AF94: @ 0x0812AF94
	push {lr}
	ldr r1, .L0812AFA4
	movs r0, #3
	bl BattleMenu_SetMode
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812AFA4: .4byte gUnknown_081244C4

	thumb_func_start sub_0812AFA8
sub_0812AFA8: @ 0x0812AFA8
	push {lr}
	bl BattleMenu_Reset
	bl BattleMsg_Close
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812AFB8
sub_0812AFB8: @ 0x0812AFB8
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	bl sub_0812B194
	pop {r0}
	bx r0

	thumb_func_start sub_0812AFC8
sub_0812AFC8: @ 0x0812AFC8
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0812B1D4
	adds r3, r0, #0
	ldr r1, .L0812AFF8
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	subs r0, #1
	cmp r3, r0
	beq .L0812B01C
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r2, .L0812AFFC
	ands r2, r3
	ldr r0, .L0812B000
	cmp r2, r0
	bne .L0812B004
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	b .L0812B01C
	.byte 0x00, 0x00
.L0812AFF8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812AFFC: .4byte 0xFFFF0000
.L0812B000: .4byte 0xFFFE0000
.L0812B004:
	lsrs r2, r2, #0x10
	lsls r0, r2, #1
	movs r4, #0xf3
	lsls r4, r4, #4
	adds r1, r1, r4
	adds r0, r0, r1
	strh r2, [r0]
	ldr r0, .L0812B024
	strh r3, [r0, #2]
	strh r2, [r0, #6]
	movs r1, #8
	strh r1, [r0, #4]
.L0812B01C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812B024: .4byte 0x030065C0 @ IWRAM+0x65C0

	thumb_func_start sub_0812B028
sub_0812B028: @ 0x0812B028
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r7, .L0812B044
	movs r0, #0
	strh r0, [r6, #0x1c]
	ldrh r0, [r6, #0x1e]
	cmp r0, #1
	beq .L0812B08C
	cmp r0, #1
	bgt .L0812B048
	cmp r0, #0
	beq .L0812B052
	b .L0812B130
.L0812B044: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812B048:
	cmp r0, #2
	beq .L0812B116
	cmp r0, #3
	beq .L0812B12C
	b .L0812B130
.L0812B052:
	ldr r0, .L0812B080
	ldrh r5, [r0, #2]
	ldr r0, .L0812B084
	strh r5, [r0]
	bl sub_080EA210
	ldr r4, .L0812B088
	bl sub_0812EA54
	lsls r1, r5, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	adds r0, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	strh r0, [r6, #0x1e]
	b .L0812B130
.L0812B080: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812B084: .4byte 0x03006440 @ IWRAM+0x6440
.L0812B088: .4byte gUnknown_08124D5E
.L0812B08C:
	bl BattleMsg_IsDone
	cmp r0, #1
	bne .L0812B130
	ldr r4, .L0812B0FC
	ldrh r5, [r4, #2]
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r5, #0
	bl sub_080F3E54
	adds r0, r5, #0
	movs r1, #0xc
	mov r2, sp
	bl sub_080BF468
	ldr r0, [sp]
	cmp r0, #0x7f
	bgt .L0812B108
	movs r1, #6
	ldrsh r0, [r4, r1]
	movs r2, #0xf3
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r2, .L0812B100
	movs r3, #1
	bl sub_0812E780
	ldr r0, [sp]
	subs r0, #0x3e
	cmp r0, #1
	bhi .L0812B110
	movs r0, #0
	movs r1, #2
	bl sub_080F1678
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0xe9
	bl sub_080EC038
	ldr r1, .L0812B104
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r1, r2
	adds r4, r4, r1
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	b .L0812B110
.L0812B0FC: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812B100: .4byte gUnknown_08124D5E
.L0812B104: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812B108:
	movs r1, #6
	ldrsh r0, [r4, r1]
	bl sub_0812EA98
.L0812B110:
	movs r0, #2
	strh r0, [r6, #0x1e]
	b .L0812B130
.L0812B116:
	bl BattleMsg_IsDone
	cmp r0, #1
	bne .L0812B130
	bl BattleMenu_Reset
	bl BattleMsg_Close
	movs r0, #3
	strh r0, [r6, #0x1e]
	b .L0812B130
.L0812B12C:
	movs r0, #1
	strh r0, [r6, #0x1c]
.L0812B130:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0812B138
sub_0812B138: @ 0x0812B138
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r0, .L0812B168
	ldrh r0, [r0]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0812B18E
	movs r0, #0
	bl sub_0812B260
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L0812B18C
	cmp r2, #4
	bhi .L0812B170
	ldr r0, .L0812B16C
	strh r2, [r0, #0xa]
	strh r2, [r0, #0x10]
	b .L0812B178
.L0812B168: .4byte 0x03006440 @ IWRAM+0x6440
.L0812B16C: .4byte 0x03006450 @ IWRAM+0x6450
.L0812B170:
	ldr r0, .L0812B188
	strh r2, [r0, #0xa]
	movs r1, #5
	strh r1, [r0, #0x10]
.L0812B178:
	adds r3, r0, #0
	ldrh r1, [r3, #0x12]
	subs r0, r2, #1
	cmp r1, r0
	ble .L0812B18E
	subs r0, r1, #1
	strh r0, [r3, #0x12]
	b .L0812B18E
.L0812B188: .4byte 0x03006450 @ IWRAM+0x6450
.L0812B18C:
	strh r2, [r4, #0x1c]
.L0812B18E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0812B194
sub_0812B194: @ 0x0812B194
.L0812B194:
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r5, .L0812B1C4
	ldr r0, .L0812B1C8
	strh r1, [r0]
	ldr r0, .L0812B1CC
	ldr r1, .L0812B1D0
	bl Task_Create
	str r0, [r5, #0x48]
	adds r0, #0x24
	strb r4, [r0]
	ldr r4, [r5, #0x48]
	bl BattleMsg_Close
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x28]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812B1C4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812B1C8: .4byte 0x03006478 @ IWRAM+0x6478
.L0812B1CC: .4byte gUnknown_087790C4
.L0812B1D0: .4byte 0x0000FFFF

	thumb_func_start sub_0812B1D4
sub_0812B1D4: @ 0x0812B1D4
.L0812B1D4:
	ldr r0, .L0812B1DC
	ldr r0, [r0, #0x48]
	ldr r0, [r0, #0x28]
	bx lr
.L0812B1DC: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812B1E0
sub_0812B1E0: @ 0x0812B1E0
.L0812B1E0:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	lsls r1, r1, #0x18
	movs r7, #0
	lsrs r6, r1, #0x18
	cmp r6, #0
	bne .L0812B1F8
	movs r0, #0
	b .L0812B250
.L0812B1F8:
	cmp r6, #6
	bls .L0812B1FE
	movs r6, #6
.L0812B1FE:
	movs r5, #0
	cmp r7, r6
	bhs .L0812B24E
	ldr r0, .L0812B25C
	mov sb, r0
.L0812B208:
	mov r1, sb
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080F3EC8
	cmp r0, #0
	beq .L0812B244
	adds r0, r4, #0
	bl sub_080F3040
	cmp r0, #0
	beq .L0812B244
	adds r0, r4, #0
	bl sub_080C35E4
	cmp r0, #8
	bne .L0812B244
	adds r0, r4, #0
	bl sub_080F3F14
	cmp r0, r8
	bne .L0812B244
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L0812B244:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, r6
	blo .L0812B208
.L0812B24E:
	adds r0, r7, #0
.L0812B250:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L0812B25C: .4byte 0x030050E0 @ IWRAM+0x50E0

	thumb_func_start sub_0812B260
sub_0812B260: @ 0x0812B260
.L0812B260:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, .L0812B30C
	mov sl, r0
	movs r7, #0xb4
	lsls r7, r7, #2
	add r7, sl
	movs r1, #0
	mov sb, r1
	movs r0, #0xc0
	mov r1, r8
	cmp r1, #0
	beq .L0812B28A
	movs r0, #0x20
.L0812B28A:
	str r0, [sp]
	movs r6, #0
.L0812B28E:
	lsls r0, r6, #2
	ldr r1, .L0812B310
	adds r0, r0, r1
	ldrh r2, [r0]
	adds r5, r2, #0
	ldrh r4, [r0, #2]
	mov r0, r8
	cmp r0, #1
	bne .L0812B2B2
	ldr r0, .L0812B314
	add r0, sl
	ldrb r1, [r0]
	adds r0, r2, #0
	bl sub_0812B1E0
	subs r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L0812B2B2:
	adds r0, r5, #0
	subs r0, #0xd0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2d
	bhi .L0812B2E2
	cmp r4, #0
	beq .L0812B2E2
	adds r0, r5, #0
	bl Action_GetRecord
	ldrb r0, [r0]
	ldr r1, [sp]
	ands r0, r1
	cmp r0, #0
	beq .L0812B2E2
	strh r5, [r7]
	strh r4, [r7, #2]
	adds r7, #4
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
.L0812B2E2:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L0812B318
	cmp r6, r0
	bls .L0812B28E
	ldr r0, .L0812B31C
	strh r0, [r7]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r7, #2]
	mov r0, sb
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0812B30C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812B310: .4byte 0x030051AC @ IWRAM+0x51AC
.L0812B314: .4byte 0x00000F66
.L0812B318: .4byte 0x00000159
.L0812B31C: .4byte 0x0000FFFF

	thumb_func_start sub_0812B320
sub_0812B320: @ 0x0812B320
.L0812B320:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L0812B36C
	ldr r1, .L0812B370
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r4, r0, r2
	movs r3, #0
	movs r2, #0
	ldr r6, .L0812B374
.L0812B336:
	ldrh r0, [r1]
	cmp r0, r5
	bhs .L0812B34C
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq .L0812B34C
	ldr r0, [r1]
	stm r4!, {r0}
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L0812B34C:
	adds r1, #4
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r6
	bls .L0812B336
	ldr r0, .L0812B378
	strh r0, [r4]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r4, #2]
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0812B36C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812B370: .4byte 0x030051AC @ IWRAM+0x51AC
.L0812B374: .4byte 0x00000159
.L0812B378: .4byte 0x0000FFFF

	thumb_func_start sub_0812B37C
sub_0812B37C: @ 0x0812B37C
.L0812B37C:
	push {r4, lr}
	movs r4, #0
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	beq .L0812B398
	ldr r0, .L0812B3A0
	ldrh r1, [r0]
	movs r0, #2
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
.L0812B398:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
.L0812B3A0: .4byte 0x0203BB74 @ EWRAM+0x3BB74

	thumb_func_start sub_0812B3A4
sub_0812B3A4: @ 0x0812B3A4
.L0812B3A4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r0, #0
	mov r8, r0
	movs r0, #0xc0
	cmp r7, #0
	beq .L0812B3BE
	movs r0, #0x20
.L0812B3BE:
	mov sb, r0
	bl sub_0812B37C
	cmp r0, #0
	beq .L0812B3CC
	movs r0, #0
	b .L0812B428
.L0812B3CC:
	movs r6, #0
	ldr r1, .L0812B438
	mov sl, r1
.L0812B3D2:
	lsls r0, r6, #2
	ldr r1, .L0812B43C
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r5, r1, #0
	ldrh r4, [r0, #2]
	adds r0, r1, #0
	subs r0, #0xd0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2e
	bhi .L0812B41C
	cmp r7, #1
	bne .L0812B3FC
	adds r0, r1, #0
	movs r1, #0xff
	bl sub_0812B1E0
	subs r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L0812B3FC:
	lsls r0, r4, #0x10
	cmp r0, #0
	ble .L0812B41C
	adds r0, r5, #0
	bl Action_GetRecord
	ldrb r0, [r0]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq .L0812B41C
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
.L0812B41C:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, sl
	bls .L0812B3D2
	mov r0, r8
.L0812B428:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0812B438: .4byte 0x00000159
.L0812B43C: .4byte 0x030051AC @ IWRAM+0x51AC

	thumb_func_start sub_0812B440
sub_0812B440: @ 0x0812B440
.L0812B440:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne .L0812B45C
	movs r0, #4
	bl sub_08126D1C
	adds r4, r0, #0
	ldr r1, .L0812B458
	b .L0812B466
	.byte 0x00, 0x00
.L0812B458: .4byte 0x03006450 @ IWRAM+0x6450
.L0812B45C:
	ldr r4, .L0812B48C
	movs r0, #4
	bl sub_08126D1C
	adds r1, r0, #0
.L0812B466:
	movs r2, #0
.L0812B468:
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, #1
	adds r1, #1
	adds r2, #1
	cmp r2, #0x27
	bls .L0812B468
	cmp r5, #1
	bne .L0812B484
	ldr r0, .L0812B48C
	ldrh r1, [r0, #0x12]
	movs r0, #4
	bl sub_08127960
.L0812B484:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812B48C: .4byte 0x03006450 @ IWRAM+0x6450

	thumb_func_start sub_0812B490
sub_0812B490: @ 0x0812B490
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r7, .L0812B4CC
	movs r4, #0
	strh r4, [r5, #0x1e]
	bl sub_080EA210
	bl sub_0812B37C
	adds r6, r0, #0
	cmp r6, #0
	bne .L0812B4BA
	bl sub_0812EA54
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L0812B4EA
.L0812B4BA:
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	beq .L0812B4D4
	ldr r0, .L0812B4D0
	bl sub_080EC038
	b .L0812B4FE
.L0812B4CC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812B4D0: .4byte 0x00000392
.L0812B4D4:
	movs r0, #0x74
	bl sub_080EC038
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	b .L0812B50C
.L0812B4EA:
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	bl sub_0812B260
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L0812B518
	ldr r0, .L0812B514
.L0812B4FE:
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
.L0812B50C:
	movs r0, #1
	strh r0, [r5, #0x1e]
	b .L0812B56E
	.byte 0x00, 0x00
.L0812B514: .4byte gUnknown_08124BD2
.L0812B518:
	movs r0, #1
	str r0, [sp]
	movs r1, #0
	movs r2, #0x13
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r7, #0x4c]
	str r6, [sp]
	movs r0, #2
	movs r1, #0xd
	movs r2, #0x1a
	movs r3, #6
	bl sub_080AB890
	str r0, [r7, #0x50]
	bl sub_081272AC
	cmp r4, #4
	bhi .L0812B550
	str r4, [sp]
	movs r0, #4
	movs r1, #0
	movs r2, #1
	adds r3, r4, #0
	bl sub_08126928
	b .L0812B560
.L0812B550:
	movs r0, #5
	str r0, [sp]
	movs r0, #4
	movs r1, #0x10
	movs r2, #1
	adds r3, r4, #0
	bl sub_08126928
.L0812B560:
	ldr r0, .L0812B578
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0812B56E
	movs r0, #1
	bl sub_0812B440
.L0812B56E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812B578: .4byte 0x03006478 @ IWRAM+0x6478

	thumb_func_start sub_0812B57C
sub_0812B57C: @ 0x0812B57C
	push {lr}
	ldr r0, .L0812B594
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #4
	bl BattleMenu_SetMode
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812B594: .4byte gUnknown_08124CC8

	thumb_func_start sub_0812B598
sub_0812B598: @ 0x0812B598
	push {r4, lr}
	movs r0, #4
	bl sub_08126D1C
	ldr r2, .L0812B5D4
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r2, r2, r1
	ldrh r1, [r0, #0x12]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r4, [r1]
	ldrh r1, [r0, #0xc]
	movs r0, #4
	bl sub_08127EAC
	adds r0, r4, #0
	bl Action_GetRecord
	ldr r0, [r0, #0x1c]
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #8
	bl BattleMenu_SetMode
	pop {r4}
	pop {r0}
	bx r0
.L0812B5D4: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812B5D8
sub_0812B5D8: @ 0x0812B5D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, .L0812B61C
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r1, r1, r0
	mov r8, r1
	movs r0, #4
	bl sub_08126D1C
	adds r4, r0, #0
	ldrb r6, [r4, #0xc]
	ldrb r7, [r4, #0x12]
	movs r0, #4
	bl sub_08126A08
	movs r0, #0
	strh r0, [r5, #0x1e]
	strh r0, [r5, #0x1c]
	ldr r2, .L0812B620
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812B624
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r5, #0x1e]
	movs r0, #1
	strh r0, [r5, #0x1c]
	b .L0812B646
.L0812B61C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812B620: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812B624:
	ldrh r1, [r2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812B646
	ldrh r0, [r4, #0x12]
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x2c
	strb r1, [r0]
	strh r2, [r5, #0x1c]
	movs r0, #0
	bl sub_0812B440
.L0812B646:
	ldrh r0, [r4, #0xc]
	cmp r6, r0
	beq .L0812B654
	ldrh r1, [r4, #0xc]
	movs r0, #4
	bl sub_08127EAC
.L0812B654:
	ldrh r1, [r4, #0x12]
	cmp r7, r1
	beq .L0812B676
	ldrh r0, [r4, #0x12]
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	bl Action_GetRecord
	ldr r0, [r0, #0x1c]
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #8
	bl BattleMenu_SetMode
.L0812B676:
	ldr r0, .L0812B6E8
	movs r5, #0
	str r5, [sp]
	movs r1, #0x14
	str r1, [sp, #4]
	ldrh r2, [r4, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r4, #0xa]
	cmp r0, #5
	bls .L0812B6DA
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	beq .L0812B6BA
	ldr r0, .L0812B6EC
	str r5, [sp]
	movs r1, #0x94
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812B6BA:
	ldrh r0, [r4, #0xc]
	adds r0, #5
	ldrh r4, [r4, #0xa]
	cmp r0, r4
	beq .L0812B6DA
	ldr r0, .L0812B6F0
	str r5, [sp]
	movs r1, #0x94
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812B6DA:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812B6E8: .4byte gUnknown_08000F8C
.L0812B6EC: .4byte gUnknown_08000FF0
.L0812B6F0: .4byte gUnknown_08001000

	thumb_func_start sub_0812B6F4
sub_0812B6F4: @ 0x0812B6F4
	push {r4, lr}
	ldr r4, .L0812B738
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812B704
	movs r1, #0
	bl TextWindow_Close
.L0812B704:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812B710
	movs r1, #0
	bl Window_Close
.L0812B710:
	ldr r0, .L0812B73C
	adds r4, r4, r0
	ldr r0, [r4]
	cmp r0, #0
	beq .L0812B724
	movs r1, #0
	bl Window_Close
	movs r0, #0
	str r0, [r4]
.L0812B724:
	movs r0, #4
	bl sub_081269B0
	bl BattleMenu_Reset
	bl sub_08128388
	pop {r4}
	pop {r0}
	bx r0
.L0812B738: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812B73C: .4byte 0x00000974

	thumb_func_start sub_0812B740
sub_0812B740: @ 0x0812B740
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r0, #0x2c
	ldrb r4, [r0]
	adds r6, r4, #0
	adds r0, r4, #0
	bl Action_GetRecord
	movs r1, #0
	strh r1, [r5, #0x1e]
	ldrb r0, [r0, #3]
	cmp r0, #0x80
	beq .L0812B762
	cmp r0, #0x82
	beq .L0812B762
	cmp r0, #0x83
	bne .L0812B766
.L0812B762:
	movs r0, #1
	b .L0812B77C
.L0812B766:
	cmp r4, #0xfb
	bne .L0812B76E
	movs r0, #3
	b .L0812B77C
.L0812B76E:
	cmp r6, #0xe1
	bne .L0812B776
	movs r0, #4
	b .L0812B77C
.L0812B776:
	cmp r0, #0
	bne .L0812B77E
	movs r0, #2
.L0812B77C:
	strh r0, [r5, #0x1e]
.L0812B77E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_0812B784
sub_0812B784: @ 0x0812B784
	ldrh r1, [r0, #0x1e]
	lsls r1, r1, #0x10
	adds r2, r0, #0
	adds r2, #0x2c
	ldrb r2, [r2]
	adds r1, r1, r2
	str r1, [r0, #0x28]
	bx lr

	thumb_func_start sub_0812B794
sub_0812B794: @ 0x0812B794
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	bl Action_GetRecord
	movs r5, #0
	ldr r6, .L0812B7BC
	strh r5, [r7, #0x1e]
	ldrb r0, [r0, #3]
	cmp r0, #0x81
	beq .L0812B7F8
	cmp r0, #0x81
	bgt .L0812B7C0
	cmp r0, #0
	beq .L0812B7F8
	cmp r0, #0x80
	beq .L0812B7CA
	b .L0812B7F8
.L0812B7BC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812B7C0:
	cmp r0, #0x83
	beq .L0812B7EE
	cmp r0, #0x83
	blt .L0812B7DC
	b .L0812B7F8
.L0812B7CA:
	ldr r0, [r6, #0x48]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0812B7D8
	movs r0, #1
	b .L0812B7F0
.L0812B7D8:
	movs r0, #0
	b .L0812B7F0
.L0812B7DC:
	ldr r0, [r6, #0x48]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0812B7EA
	movs r0, #1
	b .L0812B7F0
.L0812B7EA:
	movs r0, #0
	b .L0812B7F0
.L0812B7EE:
	movs r0, #6
.L0812B7F0:
	bl sub_08127A98
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0812B7F8:
	cmp r5, #0
	beq .L0812B86A
	ldr r0, [r6, #0x4c]
	bl Task_End
	ldr r0, [r6, #0x50]
	bl Task_End
	movs r4, #1
	str r4, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r6, #0x4c]
	str r4, [sp]
	movs r0, #0x11
	movs r1, #0
	movs r2, #0xc
	movs r3, #6
	bl TextWindow_Create
	str r0, [r6, #0x50]
	bl sub_081272AC
	cmp r5, #4
	bhi .L0812B842
	str r5, [sp]
	movs r0, #4
	movs r1, #0
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
	b .L0812B852
.L0812B842:
	movs r0, #5
	str r0, [sp]
	movs r0, #4
	movs r1, #0x10
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
.L0812B852:
	movs r0, #1
	strh r0, [r7, #0x1e]
	bl sub_080EA210
	ldr r0, .L0812B874
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #4
	bl BattleMenu_SetMode
.L0812B86A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812B874: .4byte gUnknown_08124D72

	thumb_func_start sub_0812B878
sub_0812B878: @ 0x0812B878
	push {r4, lr}
	movs r0, #4
	bl sub_08126D1C
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	movs r0, #0
	bl sub_08127EAC
	ldrh r1, [r4, #0x12]
	movs r0, #0
	bl sub_081283C4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0812B898
sub_0812B898: @ 0x0812B898
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r6, .L0812B8C8
	movs r0, #4
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r7, [r5, #0x12]
	movs r0, #4
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r0, .L0812B8CC
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812B8D0
	movs r0, #0x80
	lsls r0, r0, #1
	b .L0812B8E4
.L0812B8C8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812B8CC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812B8D0:
	ldrb r0, [r5]
	cmp r0, #3
	bne .L0812B8EA
	ldrh r0, [r5, #0x12]
	lsls r0, r0, #1
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r6, r2
	adds r0, r0, r1
	ldrh r0, [r0]
.L0812B8E4:
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
.L0812B8EA:
	ldr r0, .L0812B96C
	movs r4, #0
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L0812B94E
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L0812B92E
	ldr r0, .L0812B970
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812B92E:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r1, [r5, #0xa]
	cmp r0, r1
	beq .L0812B94E
	ldr r0, .L0812B974
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812B94E:
	ldrh r2, [r5, #0x12]
	cmp r7, r2
	beq .L0812B964
	ldrh r1, [r5, #0xc]
	movs r0, #0
	bl sub_08127EAC
	ldrh r1, [r5, #0x12]
	movs r0, #0
	bl sub_081283C4
.L0812B964:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0812B96C: .4byte gUnknown_08000EA4
.L0812B970: .4byte gUnknown_08000FF0
.L0812B974: .4byte gUnknown_08001000

	thumb_func_start sub_0812B978
sub_0812B978: @ 0x0812B978
	push {r4, lr}
	ldr r4, .L0812B9A8
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812B988
	movs r1, #0
	bl TextWindow_Close
.L0812B988:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812B994
	movs r1, #0
	bl TextWindow_Close
.L0812B994:
	movs r0, #4
	bl sub_081269B0
	bl BattleMenu_Reset
	bl sub_08128388
	pop {r4}
	pop {r0}
	bx r0
.L0812B9A8: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812B9AC
sub_0812B9AC: @ 0x0812B9AC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0812B9F0
	bl sub_080E6E08
	ldr r1, .L0812B9F4
	ldr r2, .L0812B9F8
	adds r4, r4, r2
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r1, r2
	ldrb r4, [r4]
	adds r1, r1, r4
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	movs r1, #0
	strh r1, [r5, #0x1c]
	strh r1, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	beq .L0812B9FC
	cmp r0, #3
	bne .L0812BA06
	movs r0, #1
	strh r0, [r5, #0x1c]
	adds r0, r2, #0
	bl sub_080EDA64
	strh r0, [r5, #0x1e]
	b .L0812BA06
.L0812B9F0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812B9F4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812B9F8: .4byte 0x00000691
.L0812B9FC:
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r5, #0x1e]
	movs r0, #1
	strh r0, [r5, #0x1c]
.L0812BA06:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0812BA0C
sub_0812BA0C: @ 0x0812BA0C
	push {lr}
	adds r1, r0, #0
	movs r0, #1
	bl sub_0812EE8C
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812BA1C
sub_0812BA1C: @ 0x0812BA1C
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0812BA2C
	ldr r0, [r0]
	cmp r0, #0
	bne .L0812BA30
	movs r0, #1
	b .L0812BA32
.L0812BA2C: .4byte 0x030031CC @ IWRAM+0x31CC
.L0812BA30:
	movs r0, #0
.L0812BA32:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_0812BA38
sub_0812BA38: @ 0x0812BA38
	push {r4, r5, lr}
	ldr r0, .L0812BA48
	cmp r1, #0
	bne .L0812BA4C
	ldr r0, [r0, #0x44]
	bl Task_End
	b .L0812BAF4
.L0812BA48: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812BA4C:
	cmp r1, #1
	bne .L0812BAB0
	ldr r5, .L0812BAA0
	ldr r0, [r5]
	ldr r4, .L0812BAA4
	ands r0, r4
	cmp r0, #0
	bne .L0812BA82
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl sub_080B3078
	cmp r0, #1
	beq .L0812BA9A
	ldr r0, [r5]
	ands r0, r4
	cmp r0, #0
	bne .L0812BA82
	ldr r0, .L0812BAA8
	ldr r0, [r0]
	cmp r0, #2
	beq .L0812BA9A
	cmp r0, #0x27
	beq .L0812BA9A
	cmp r0, #0x41
	beq .L0812BA9A
.L0812BA82:
	bl sub_080B0888
	ldr r0, .L0812BAAC
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0812BA9A
	movs r0, #0
	movs r1, #1
	movs r2, #1
	movs r3, #4
	bl PalFade_FadeRangeToBlackWithDuration
.L0812BA9A:
	bl sub_080C700C
	b .L0812BAF4
.L0812BAA0: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L0812BAA4: .4byte 0x00007FFF
.L0812BAA8: .4byte 0x03004614 @ IWRAM+0x4614
.L0812BAAC: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L0812BAB0:
	movs r0, #0xfb
	bl sub_080C33AC
	ldr r0, .L0812BACC
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne .L0812BAD4
	ldr r0, .L0812BAD0
	str r1, [r0]
	b .L0812BADA
	.byte 0x00, 0x00
.L0812BACC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812BAD0: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L0812BAD4:
	ldr r1, .L0812BAFC
	movs r0, #1
	str r0, [r1]
.L0812BADA:
	movs r0, #0xb3
	lsls r0, r0, #1
	bl Flag_Set
	bl sub_0812EEC4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0812BB00
	movs r1, #1
	movs r3, #0
	bl sub_080E471C
.L0812BAF4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812BAFC: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L0812BB00: .4byte 0x0000FFFF

	thumb_func_start sub_0812BB04
sub_0812BB04: @ 0x0812BB04
	push {lr}
	bl sub_0812EF8C
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812BB10
sub_0812BB10: @ 0x0812BB10
	push {r4, lr}
	ldr r4, .L0812BB34
	ldr r0, .L0812BB38
	ldr r1, .L0812BB3C
	bl Task_Create
	str r0, [r4, #0x48]
	adds r0, #0x24
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r4, #0x48]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1, #0x28]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812BB34: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812BB38: .4byte gUnknown_08779418
.L0812BB3C: .4byte 0x0000FFFF

	thumb_func_start sub_0812BB40
sub_0812BB40: @ 0x0812BB40
	push {lr}
	adds r0, r1, #0
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #4
	bl BattleMenu_SetMode
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812BB58
sub_0812BB58: @ 0x0812BB58
	push {lr}
	adds r0, r1, #0
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #9
	bl BattleMenu_SetMode
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812BB70
sub_0812BB70: @ 0x0812BB70
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #4
	bl sub_08126D1C
	adds r4, #0x2c
	ldrb r1, [r4]
	lsls r1, r1, #8
	ldrh r0, [r0, #0xc]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #5
	bl sub_08127EAC
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0812BB94
sub_0812BB94: @ 0x0812BB94
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #4
	bl sub_08126D1C
	ldr r2, .L0812BBE0
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r2, r2, r1
	ldrh r1, [r0, #0x12]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r5, [r1]
	adds r4, #0x2c
	ldrb r1, [r4]
	lsls r1, r1, #8
	ldrh r0, [r0, #0xc]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #5
	bl sub_08127EAC
	adds r0, r5, #0
	bl Action_GetRecord
	ldr r0, [r0, #0x1c]
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #8
	bl BattleMenu_SetMode
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812BBE0: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812BBE4
sub_0812BBE4: @ 0x0812BBE4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, .L0812BC20
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r7, r0, r1
	movs r0, #4
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r6, [r5, #0xc]
	movs r0, #4
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r2, .L0812BC24
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812BC28
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L0812BC40
.L0812BC20: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812BC24: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812BC28:
	ldrh r1, [r2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812BC40
	ldrh r0, [r5, #0x12]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrh r0, [r0]
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x1c]
.L0812BC40:
	ldrh r2, [r5, #0xc]
	cmp r6, r2
	beq .L0812BC5A
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	lsls r1, r1, #8
	adds r1, r2, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #5
	bl sub_08127EAC
.L0812BC5A:
	ldr r0, .L0812BCC8
	movs r4, #0
	str r4, [sp]
	movs r1, #0x14
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L0812BCBE
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L0812BC9E
	ldr r0, .L0812BCCC
	str r4, [sp]
	movs r1, #0x94
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812BC9E:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r5, [r5, #0xa]
	cmp r0, r5
	beq .L0812BCBE
	ldr r0, .L0812BCD0
	str r4, [sp]
	movs r1, #0x94
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812BCBE:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812BCC8: .4byte gUnknown_08000F8C
.L0812BCCC: .4byte gUnknown_08000FF0
.L0812BCD0: .4byte gUnknown_08001000

	thumb_func_start sub_0812BCD4
sub_0812BCD4: @ 0x0812BCD4
.L0812BCD4:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, .L0812BCE0
	b .L0812BCE6
	.byte 0x00, 0x00
.L0812BCE0: .4byte 0x030051AC @ IWRAM+0x51AC
.L0812BCE4:
	adds r1, #4
.L0812BCE6:
	ldrh r0, [r1]
	cmp r0, r2
	bne .L0812BCE4
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0812BCF4
sub_0812BCF4: @ 0x0812BCF4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	bl sub_0812BCD4
	adds r5, r0, #0
	ldrh r0, [r4, #0x1e]
	bl sub_0812BCD4
	ldr r2, [r5]
	ldr r1, [r0]
	str r1, [r5]
	str r2, [r0]
	movs r0, #0xff
	bl sub_0812B320
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0812BD1C
sub_0812BD1C: @ 0x0812BD1C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r7, .L0812BD54
	movs r5, #0
	strh r5, [r6, #0x1e]
	bl sub_080EA210
	movs r0, #0xff
	bl sub_0812B320
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, r4, #0
	cmp r4, #0
	bne .L0812BD5C
	ldr r0, .L0812BD58
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	strh r0, [r6, #0x1e]
	b .L0812BD94
	.byte 0x00, 0x00
.L0812BD54: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812BD58: .4byte gUnknown_08124BF4
.L0812BD5C:
	movs r0, #1
	str r0, [sp]
	movs r1, #0
	movs r2, #0x13
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r7, #0x4c]
	bl sub_081272AC
	cmp r4, #4
	bhi .L0812BD84
	str r4, [sp]
	movs r0, #4
	movs r1, #0
	movs r2, #1
	adds r3, r4, #0
	bl sub_08126928
	b .L0812BD94
.L0812BD84:
	movs r0, #5
	str r0, [sp]
	movs r0, #4
	movs r1, #0x10
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
.L0812BD94:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0812BD9C
sub_0812BD9C: @ 0x0812BD9C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, .L0812BDD8
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r7, r0, r1
	movs r0, #4
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r6, [r5, #0xc]
	movs r0, #4
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r2, .L0812BDDC
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812BDE0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L0812BDFC
.L0812BDD8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812BDDC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812BDE0:
	ldrh r1, [r2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812BDFC
	ldrh r0, [r5, #0x12]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x2c
	strb r1, [r0]
	strh r2, [r4, #0x1c]
.L0812BDFC:
	ldrh r0, [r5, #0xc]
	cmp r6, r0
	beq .L0812BE0A
	ldrh r1, [r5, #0xc]
	movs r0, #6
	bl sub_08127EAC
.L0812BE0A:
	ldr r0, .L0812BE78
	movs r4, #0
	str r4, [sp]
	movs r1, #0x14
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L0812BE6E
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L0812BE4E
	ldr r0, .L0812BE7C
	str r4, [sp]
	movs r1, #0x94
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812BE4E:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r5, [r5, #0xa]
	cmp r0, r5
	beq .L0812BE6E
	ldr r0, .L0812BE80
	str r4, [sp]
	movs r1, #0x94
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812BE6E:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812BE78: .4byte gUnknown_08000F8C
.L0812BE7C: .4byte gUnknown_08000FF0
.L0812BE80: .4byte gUnknown_08001000

	thumb_func_start sub_0812BE84
sub_0812BE84: @ 0x0812BE84
	push {r4, lr}
	ldr r4, .L0812BEAC
	ldr r0, .L0812BEB0
	ldr r1, .L0812BEB4
	bl Task_Create
	str r0, [r4, #0x48]
	adds r0, #0x24
	movs r1, #0
	strb r1, [r0]
	ldr r4, [r4, #0x48]
	bl BattleMsg_Close
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x28]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812BEAC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812BEB0: .4byte gUnknown_087795D8
.L0812BEB4: .4byte 0x0000FFFF

	thumb_func_start sub_0812BEB8
sub_0812BEB8: @ 0x0812BEB8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r7, .L0812BEF0
	movs r5, #0
	strh r5, [r6, #0x1e]
	bl sub_080EA210
	movs r0, #0xff
	bl sub_0812B320
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, r4, #0
	cmp r4, #0
	bne .L0812BEF8
	ldr r0, .L0812BEF4
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	strh r0, [r6, #0x1e]
	b .L0812BF46
	.byte 0x00, 0x00
.L0812BEF0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812BEF4: .4byte gUnknown_08124C38
.L0812BEF8:
	movs r0, #1
	str r0, [sp]
	movs r1, #0
	movs r2, #0x13
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r7, #0x4c]
	bl sub_081272AC
	cmp r4, #4
	bhi .L0812BF20
	str r4, [sp]
	movs r0, #4
	movs r1, #0
	movs r2, #1
	adds r3, r4, #0
	bl sub_08126928
	b .L0812BF30
.L0812BF20:
	movs r0, #5
	str r0, [sp]
	movs r0, #4
	movs r1, #0x10
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
.L0812BF30:
	ldr r0, .L0812BF50
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl sub_080EC99C
.L0812BF46:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812BF50: .4byte gUnknown_08124CE6
