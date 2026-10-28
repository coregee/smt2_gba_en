	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080F0CFC
sub_080F0CFC: @ 0x080F0CFC
.L080F0CFC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r7, .L080F0D40
	adds r0, #0x5c
	ldrb r0, [r0]
	str r0, [sp]
	movs r0, #0x17
	ldrsb r0, [r6, r0]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L080F0D44
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r2, [r6, #0x10]
	mov r8, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080F0D48
	lsls r4, r1, #0x10
	asrs r0, r4, #0x10
	bl sub_080F2C9C
	b .L080F0D58
	.byte 0x00, 0x00
.L080F0D40: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0D44: .4byte 0x03006434 @ IWRAM+0x6434
.L080F0D48:
	lsls r4, r1, #0x10
	asrs r0, r4, #0x10
	ldr r2, .L080F0D84
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl sub_080EFFF8
.L080F0D58:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	mov sb, r4
	lsls r0, r5, #0x10
	asrs r5, r0, #0x10
	mov sl, r0
	cmp r5, #8
	bne .L080F0D88
	ldr r1, .L080F0D84
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080F0E54
	movs r1, #1
	rsbs r1, r1, #0
	ldr r0, [sp]
	bl sub_080F3E54
	b .L080F0E54
	.byte 0x00, 0x00
.L080F0D84: .4byte 0x00000F66
.L080F0D88:
	cmp r5, #7
	bne .L080F0E0C
	ldr r0, [sp]
	cmp r0, #0x3f
	bgt .L080F0E54
	movs r5, #0
	ldrh r4, [r6, #0x1c]
	bl sub_080ED6CC
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, .L080F0DC8
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080F0DCE
	mov r1, sb
	asrs r0, r1, #0x10
	cmp r0, #0xf
	bgt .L080F0DCE
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r1, #0
	bge .L080F0DCC
	movs r5, #1
	b .L080F0DCE
	.byte 0x00, 0x00
.L080F0DC8: .4byte 0x000011AA
.L080F0DCC:
	strh r4, [r6, #0x1c]
.L080F0DCE:
	movs r0, #2
	mov r2, r8
	ands r2, r0
	cmp r2, #0
	beq .L080F0DDA
	movs r5, #2
.L080F0DDA:
	adds r0, r5, #0
	cmp r0, #0
	beq .L080F0E54
	cmp r0, #2
	bne .L080F0DF4
	ldr r1, .L080F0DF0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F0DFC
	.byte 0x00, 0x00
.L080F0DF0: .4byte gUnknown_081241B0
.L080F0DF4:
	ldr r1, .L080F0E04
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F0DFC:
	ldr r0, .L080F0E08
	adds r1, r7, r0
	movs r0, #0xb
	b .L080F0F4E
.L080F0E04: .4byte gUnknown_081241D0
.L080F0E08: .4byte 0x0000097C
.L080F0E0C:
	cmp r5, #0xb
	bne .L080F0E64
	ldr r1, .L080F0E40
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080F0E54
	mov r2, sb
	asrs r4, r2, #0x10
	cmp r4, #0xf
	bgt .L080F0E54
	adds r0, r4, #0
	ldr r1, [sp]
	bl sub_080ED744
	cmp r0, #1
	beq .L080F0E4C
	ldr r1, .L080F0E44
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, .L080F0E48
	adds r0, r7, r1
	strh r5, [r0]
	b .L080F0F50
	.byte 0x00, 0x00
.L080F0E40: .4byte 0x000011AA
.L080F0E44: .4byte gUnknown_081241E0
.L080F0E48: .4byte 0x0000097C
.L080F0E4C:
	adds r0, r4, #0
	ldr r1, [sp]
	bl sub_080ED6DC
.L080F0E54:
	mov r2, sl
	asrs r0, r2, #0x10
	cmp r0, #0xb
	bne .L080F0E64
	ldr r0, [sp]
	subs r0, #0x54
	cmp r0, #0x13
	bls .L080F0EC8
.L080F0E64:
	mov r0, sb
	asrs r4, r0, #0x10
	ldr r1, [sp, #4]
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080EE028
	cmp r0, #0
	bne .L080F0EC8
	adds r0, r4, #0
	bl Battle_IsEnemyId
	cmp r0, #0
	bne .L080F0E94
	ldr r1, .L080F0E90
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F0EAC
	.byte 0x00, 0x00
.L080F0E90: .4byte gUnknown_081230A8
.L080F0E94:
	ldr r2, .L080F0EC0
	adds r0, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	bl Battle_BuildDodgeText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F0EAC:
	ldr r0, .L080F0EC4
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
	b .L080F0F50
	.byte 0x00, 0x00
.L080F0EC0: .4byte 0xFFFF8000
.L080F0EC4: .4byte 0x0000097C
.L080F0EC8:
	mov r1, sl
	asrs r4, r1, #0x10
	ldr r0, .L080F0EF8
	add r0, sl
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080F0F40
	cmp r4, #0xa
	beq .L080F0F40
	cmp r4, #8
	bne .L080F0F2C
	ldr r0, [sp]
	movs r1, #0xc
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	cmp r0, #0x7f
	ble .L080F0F00
	ldr r1, .L080F0EFC
	adds r0, r7, r1
	strh r4, [r0]
	b .L080F0F50
	.byte 0x00, 0x00
.L080F0EF8: .4byte 0xFFFC0000
.L080F0EFC: .4byte 0x0000097C
.L080F0F00:
	subs r0, #0x1d
	cmp r0, #0x22
	bhi .L080F0F14
	ldr r2, .L080F0F10
	adds r1, r7, r2
	movs r0, #7
	b .L080F0F4E
	.byte 0x00, 0x00
.L080F0F10: .4byte 0x0000097C
.L080F0F14:
	ldr r0, .L080F0F24
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, .L080F0F28
	adds r1, r7, r2
	b .L080F0F4C
	.byte 0x00, 0x00
.L080F0F24: .4byte 0x0000097E
.L080F0F28: .4byte 0x0000097C
.L080F0F2C:
	ldr r0, [sp]
	subs r0, #0x1d
	cmp r0, #0x22
	bhi .L080F0F40
	ldr r0, .L080F0F3C
	adds r1, r7, r0
	movs r0, #7
	b .L080F0F4E
.L080F0F3C: .4byte 0x0000097C
.L080F0F40:
	ldr r2, .L080F0F60
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L080F0F64
	adds r1, r7, r0
.L080F0F4C:
	movs r0, #5
.L080F0F4E:
	strh r0, [r1]
.L080F0F50:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F0F60: .4byte 0x0000097E
.L080F0F64: .4byte 0x0000097C

	thumb_func_start sub_080F0F68
sub_080F0F68: @ 0x080F0F68
.L080F0F68:
	push {lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, .L080F0F8C
	lsrs r0, r0, #0xe
	adds r1, r1, r0
	adds r1, r1, r2
	ldrb r2, [r1]
	adds r0, r2, #0
	subs r0, #0xdc
	cmp r0, #0x22
	bhi .L080F1046
	lsls r0, r0, #2
	ldr r1, .L080F0F90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F0F8C: .4byte gUnknown_0876E1D8
.L080F0F90: .4byte gUnknown_080F0F94
	.global gUnknown_080F0F94
gUnknown_080F0F94:
.L080F0F94: @ jump table
	.4byte .L080F103C
	.4byte .L080F1020
	.4byte .L080F1024
	.4byte .L080F1028
	.4byte .L080F103C
	.4byte .L080F102C
	.4byte .L080F1030
	.4byte .L080F103C
	.4byte .L080F1034
	.4byte .L080F1038
	.4byte .L080F103C
	.4byte .L080F1040
	.4byte .L080F1044
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
	.4byte .L080F1046
.L080F1020:
	movs r2, #0x34
	b .L080F1046
.L080F1024:
	movs r2, #0x64
	b .L080F1046
.L080F1028:
	movs r2, #0x70
	b .L080F1046
.L080F102C:
	movs r2, #0x37
	b .L080F1046
.L080F1030:
	movs r2, #0x67
	b .L080F1046
.L080F1034:
	movs r2, #0x36
	b .L080F1046
.L080F1038:
	movs r2, #0x66
	b .L080F1046
.L080F103C:
	movs r2, #0xff
	b .L080F1046
.L080F1040:
	movs r2, #0x35
	b .L080F1046
.L080F1044:
	movs r2, #0x65
.L080F1046:
	adds r0, r2, #0
	pop {r1}
	bx r1
