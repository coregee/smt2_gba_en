	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080F2AC8
sub_080F2AC8: @ 0x080F2AC8
.L080F2AC8:
	push {r4, r5, r6, lr}
	ldr r1, .L080F2B08
	ldr r0, [r1, #4]
	ldrh r6, [r1, #4]
	bl sub_080F3110
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl sub_080EDA90
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r2, r1, #0
	cmp r1, #0x80
	bne .L080F2AE8
	b .L080F2BFC
.L080F2AE8:
	cmp r1, #0x80
	bgt .L080F2B2C
	cmp r1, #8
	bne .L080F2AF2
	b .L080F2C3C
.L080F2AF2:
	cmp r1, #8
	bgt .L080F2B14
	cmp r1, #2
	bne .L080F2AFC
	b .L080F2C5C
.L080F2AFC:
	cmp r1, #2
	bgt .L080F2B0C
	cmp r1, #1
	bne .L080F2B06
	b .L080F2C6C
.L080F2B06:
	b .L080F2C78
.L080F2B08: .4byte 0x03000088 @ IWRAM+0x88
.L080F2B0C:
	cmp r1, #4
	bne .L080F2B12
	b .L080F2C4C
.L080F2B12:
	b .L080F2C78
.L080F2B14:
	cmp r1, #0x20
	bne .L080F2B1A
	b .L080F2C1C
.L080F2B1A:
	cmp r1, #0x20
	bgt .L080F2B26
	cmp r1, #0x10
	bne .L080F2B24
	b .L080F2C2C
.L080F2B24:
	b .L080F2C78
.L080F2B26:
	cmp r1, #0x40
	beq .L080F2C0C
	b .L080F2C78
.L080F2B2C:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	beq .L080F2BBC
	cmp r1, r0
	bgt .L080F2B58
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	beq .L080F2BDC
	cmp r1, r0
	bgt .L080F2B4E
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq .L080F2BEC
	b .L080F2C78
.L080F2B4E:
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	beq .L080F2BCC
	b .L080F2C78
.L080F2B58:
	movs r0, #0x80
	lsls r0, r0, #6
	cmp r1, r0
	beq .L080F2B9C
	cmp r1, r0
	bgt .L080F2B6E
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r1, r0
	beq .L080F2BAC
	b .L080F2C78
.L080F2B6E:
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r2, r0
	beq .L080F2B8C
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r2, r0
	beq .L080F2B80
	b .L080F2C78
.L080F2B80:
	ldr r1, .L080F2B88
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	b .L080F2C74
.L080F2B88: .4byte gUnknown_0876E938
.L080F2B8C:
	ldr r1, .L080F2B98
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #4
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2B98: .4byte gUnknown_0876E938
.L080F2B9C:
	ldr r1, .L080F2BA8
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #8
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2BA8: .4byte gUnknown_0876E938
.L080F2BAC:
	ldr r1, .L080F2BB8
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0xc
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2BB8: .4byte gUnknown_0876E938
.L080F2BBC:
	ldr r1, .L080F2BC8
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x10
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2BC8: .4byte gUnknown_0876E938
.L080F2BCC:
	ldr r1, .L080F2BD8
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x14
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2BD8: .4byte gUnknown_0876E938
.L080F2BDC:
	ldr r1, .L080F2BE8
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x18
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2BE8: .4byte gUnknown_0876E938
.L080F2BEC:
	ldr r1, .L080F2BF8
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x1c
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2BF8: .4byte gUnknown_0876E938
.L080F2BFC:
	ldr r1, .L080F2C08
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x20
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2C08: .4byte gUnknown_0876E938
.L080F2C0C:
	ldr r1, .L080F2C18
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x24
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2C18: .4byte gUnknown_0876E938
.L080F2C1C:
	ldr r1, .L080F2C28
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x28
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2C28: .4byte gUnknown_0876E938
.L080F2C2C:
	ldr r1, .L080F2C38
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x2c
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2C38: .4byte gUnknown_0876E938
.L080F2C3C:
	ldr r1, .L080F2C48
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x30
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2C48: .4byte gUnknown_0876E938
.L080F2C4C:
	ldr r1, .L080F2C58
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x34
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2C58: .4byte gUnknown_0876E938
.L080F2C5C:
	ldr r1, .L080F2C68
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x38
	b .L080F2C74
	.byte 0x00, 0x00
.L080F2C68: .4byte gUnknown_0876E938
.L080F2C6C:
	ldr r1, .L080F2C98
	lsls r0, r4, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x3c
.L080F2C74:
	adds r0, r0, r1
	ldrh r5, [r0]
.L080F2C78:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	bl Battle_GetMessage
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F2C98: .4byte gUnknown_0876E938

	thumb_func_start sub_080F2C9C
sub_080F2C9C: @ 0x080F2C9C
.L080F2C9C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	movs r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	bgt .L080F2CE8
	movs r6, #0x10
.L080F2CB0:
	lsls r4, r6, #0x10
	asrs r5, r4, #0x10
	adds r0, r5, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080F2CD8
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F2CD8
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	.2byte 0x4469 @ add r1, sp, r1
	strh r6, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L080F2CD8:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x17
	ble .L080F2CB0
	b .L080F2D28
.L080F2CE8:
	movs r6, #0
	movs r0, #1
	rsbs r0, r0, #0
	mov r8, r0
.L080F2CF0:
	lsls r4, r6, #0x10
	asrs r0, r4, #0x10
	bl sub_080F40EC
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080F2D1A
	bl sub_080C0830
	cmp r0, #0
	bne .L080F2D1A
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	.2byte 0x4469 @ add r1, sp, r1
	strh r5, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L080F2D1A:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble .L080F2CF0
.L080F2D28:
	bl sub_080C2244
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	bl __umodsi3
	lsls r0, r0, #1
	.2byte 0x4468 @ add r0, sp, r0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F2D4C
sub_080F2D4C: @ 0x080F2D4C
.L080F2D4C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r1, #0
.L080F2D58:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	mov r8, r1
	lsls r1, r1, #7
	movs r2, #0x9a
	lsls r2, r2, #4
	adds r1, r1, r2
	ldr r2, .L080F2DE8
	adds r5, r2, r1
	ldrh r1, [r5, #0xe]
	mov sl, r0
	cmp r1, #0
	bne .L080F2D74
	b .L080F2E88
.L080F2D74:
	ldrh r1, [r5, #0x10]
	ldr r2, .L080F2DEC
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080F2D82
	b .L080F2E88
.L080F2D82:
	ldrh r0, [r5, #0x12]
	lsls r6, r0, #0x10
	asrs r0, r6, #0x10
	bl sub_080F30F8
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080F2E5A
	movs r7, #1
	bl sub_080C2244
	adds r4, r0, #0
	movs r0, #7
	mov sb, r0
	mov r1, sb
	ands r4, r1
	cmp r4, #6
	ble .L080F2DA8
	movs r4, #0
.L080F2DA8:
	lsrs r0, r6, #0x10
	bl Demon_GetRecord
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, #0x11
	adds r0, r0, r1
	ldrb r4, [r0]
	adds r0, r4, #0
	bl sub_080ED694
	adds r6, r0, #0
	adds r0, r4, #0
	bl sub_080BF5C0
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080F2DE4
	cmp r4, #0x3e
	beq .L080F2DE4
	cmp r4, #0x3f
	beq .L080F2DE4
	cmp r4, #0x36
	beq .L080F2DE4
	cmp r4, #0x37
	beq .L080F2DE4
	cmp r4, #0x3c
	bne .L080F2DF0
.L080F2DE4:
	movs r7, #0
	b .L080F2E5A
.L080F2DE8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2DEC: .4byte 0x0000B1E0
.L080F2DF0:
	cmp r4, #0x9f
	ble .L080F2DF8
	movs r7, #0
	b .L080F2E5A
.L080F2DF8:
	mov r0, r8
	adds r0, #0x10
	adds r1, r4, #0
	bl sub_080ED744
	cmp r0, #0
	bne .L080F2E0A
	movs r7, #0
	b .L080F2E5A
.L080F2E0A:
	cmp r4, #0x3f
	bgt .L080F2E20
	ldrh r1, [r5, #0x10]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080F2E1A
	movs r7, #0
.L080F2E1A:
	mov r2, sb
	strb r2, [r5, #0x17]
	b .L080F2E24
.L080F2E20:
	movs r0, #0xb
	strb r0, [r5, #0x17]
.L080F2E24:
	cmp r6, #0x80
	beq .L080F2E2C
	cmp r6, #0x82
	bne .L080F2E50
.L080F2E2C:
	adds r0, r4, #0
	bl sub_080F2EAC
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080F2E40
	movs r7, #0
	b .L080F2E5A
.L080F2E40:
	mov r2, sl
	asrs r0, r2, #0xf
	ldr r2, .L080F2E60
	adds r0, r2, r0
	movs r2, #0xf5
	lsls r2, r2, #4
	adds r0, r0, r2
	strh r1, [r0]
.L080F2E50:
	adds r0, r5, #0
	adds r0, #0x5c
	strb r4, [r0]
	cmp r7, #0
	bne .L080F2E64
.L080F2E5A:
	movs r0, #0xa
	strb r0, [r5, #0x17]
	b .L080F2E88
.L080F2E60: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2E64:
	cmp r4, #0x9f
	bne .L080F2E88
	ldr r1, .L080F2EA8
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq .L080F2E76
	movs r0, #0xa
	strb r0, [r5, #0x17]
.L080F2E76:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble .L080F2E88
	movs r0, #0
	strh r0, [r1]
.L080F2E88:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sl
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt .L080F2E98
	b .L080F2D58
.L080F2E98:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F2EA8: .4byte 0x0203C174 @ EWRAM+0x3C174

	thumb_func_start sub_080F2EAC
sub_080F2EAC: @ 0x080F2EAC
.L080F2EAC:
	push {r4, r5, r6, r7, lr}
	ldr r6, .L080F2EC0
	bl sub_080ED694
	adds r4, r0, #0
	cmp r4, #0x80
	bne .L080F2EC4
	movs r4, #0
	b .L080F2ECA
	.byte 0x00, 0x00
.L080F2EC0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2EC4:
	cmp r4, #0x82
	bne .L080F2ECA
	movs r4, #1
.L080F2ECA:
	movs r3, #0
	movs r5, #0x80
	lsls r5, r5, #8
.L080F2ED0:
	lsls r0, r3, #7
	movs r1, #0x9a
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r2, r6, r0
	ldrh r0, [r2, #0xe]
	cmp r0, #0
	beq .L080F2F04
	ldrh r1, [r2, #0x10]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne .L080F2F04
	cmp r4, #0
	beq .L080F2EF8
	cmp r1, #0
	beq .L080F2F04
.L080F2EF2:
	adds r0, r3, #0
	adds r0, #0x10
	b .L080F2F0E
.L080F2EF8:
	movs r7, #0x18
	ldrsh r1, [r2, r7]
	movs r7, #0x1a
	ldrsh r0, [r2, r7]
	cmp r1, r0
	blt .L080F2EF2
.L080F2F04:
	adds r3, #1
	cmp r3, #7
	ble .L080F2ED0
	movs r0, #1
	rsbs r0, r0, #0
.L080F2F0E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080F2F14
sub_080F2F14: @ 0x080F2F14
.L080F2F14:
	push {r4, r5, lr}
	ldr r2, .L080F2F5C
	movs r3, #0
	ldr r4, .L080F2F60
	ldr r0, [r4]
	movs r1, #0xc
	ldrsh r0, [r0, r1]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L080F2F50
	adds r5, r1, #0
.L080F2F2C:
	lsls r0, r2, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	lsls r0, r3, #0x10
	adds r0, r0, r1
	lsrs r3, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0xc
	bgt .L080F2F50
	ldr r0, [r4]
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0xc
	ldrsh r0, [r0, r1]
	cmp r0, r5
	bne .L080F2F2C
.L080F2F50:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080F2F5C: .4byte 0x0000FFFF
.L080F2F60: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start Battle_GetCombatant
Battle_GetCombatant: @ 0x080F2F64
.L080F2F64:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L080F2F80
	ands r0, r1
	cmp r0, #0xf
	bls .L080F2F88
	ldr r1, .L080F2F84
	lsls r0, r0, #7
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r0, r0, r1
	b .L080F2F8E
.L080F2F80: .4byte 0x00007FFF
.L080F2F84: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2F88:
	adds r0, r1, #0
	bl sub_080C0148
.L080F2F8E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F2F94
sub_080F2F94: @ 0x080F2F94
.L080F2F94:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bgt .L080F2FE6
	movs r6, #1
	rsbs r6, r6, #0
.L080F2FAC:
	movs r1, #0
	ldrsh r0, [r4, r1]
	bl sub_080F30CC
	strh r0, [r5]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r6
	beq .L080F2FD8
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl sub_080F3EC8
	cmp r0, #0
	beq .L080F2FD8
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl sub_080F3040
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080F2FE6
.L080F2FD8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble .L080F2FAC
.L080F2FE6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080F2FEC
sub_080F2FEC: @ 0x080F2FEC
.L080F2FEC:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	blt .L080F303A
	movs r6, #1
	rsbs r6, r6, #0
.L080F3002:
	movs r1, #0
	ldrsh r0, [r4, r1]
	bl sub_080F30CC
	strh r0, [r5]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r6
	beq .L080F302E
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl sub_080F3EC8
	cmp r0, #0
	beq .L080F302E
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl sub_080F3040
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080F303A
.L080F302E:
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L080F3002
.L080F303A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080F3040
sub_080F3040: @ 0x080F3040
.L080F3040:
	push {lr}
	bl sub_080C0818
	ldr r1, .L080F3054
	ands r1, r0
	cmp r1, #0
	bne .L080F3058
	movs r0, #1
	b .L080F305A
	.byte 0x00, 0x00
.L080F3054: .4byte 0x0000B3F0
.L080F3058:
	movs r0, #0
.L080F305A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F3060
sub_080F3060: @ 0x080F3060
.L080F3060:
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r6, #0
	movs r1, #0
.L080F3068:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	adds r0, #0x10
	bl sub_080C0A00
	cmp r0, #0
	beq .L080F3082
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r5, r0, #0x10
.L080F3082:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble .L080F3068
	movs r1, #0
	lsls r5, r5, #0x10
.L080F3092:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	adds r0, #0x14
	bl sub_080C0A00
	cmp r0, #0
	beq .L080F30AC
	lsls r0, r6, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r6, r0, #0x10
.L080F30AC:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble .L080F3092
	cmp r5, #0
	beq .L080F30C0
	cmp r6, #0
	bne .L080F30C4
.L080F30C0:
	movs r0, #0
	b .L080F30C6
.L080F30C4:
	movs r0, #1
.L080F30C6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_080F30CC
sub_080F30CC: @ 0x080F30CC
.L080F30CC:
	ldr r1, .L080F30E0
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r1, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bx lr
	.byte 0x00, 0x00
.L080F30E0: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_080F30E4
sub_080F30E4: @ 0x080F30E4
.L080F30E4:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Demon_GetRecord
	ldrb r0, [r0, #0x10]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start sub_080F30F8
sub_080F30F8: @ 0x080F30F8
.L080F30F8:
	push {lr}
	bl sub_080F30E4
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #1
	bl sub_080ED3FC
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F3110
sub_080F3110: @ 0x080F3110
.L080F3110:
	push {lr}
	cmp r0, #0xf
	ble .L080F311A
	movs r0, #1
	b .L080F311C
.L080F311A:
	movs r0, #0
.L080F311C:
	pop {r1}
	bx r1

	thumb_func_start sub_080F3120
sub_080F3120: @ 0x080F3120
.L080F3120:
	push {r4, lr}
	movs r0, #0
.L080F3124:
	lsls r4, r0, #0x10
	lsrs r0, r4, #0x10
	bl sub_080C0148
	ldrb r1, [r0, #0x17]
	strb r1, [r0, #0x16]
	movs r0, #0x80
	lsls r0, r0, #9
	adds r4, r4, r0
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L080F3124
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F3144
sub_080F3144: @ 0x080F3144
.L080F3144:
	push {r4, lr}
	movs r4, #0
.L080F3148:
	ldr r1, .L080F317C
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r2, r0, #0
	cmp r2, #0
	beq .L080F3180
	ldrh r1, [r2, #0xe]
	movs r3, #0xc0
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080F3180
	ldrh r1, [r2, #0x10]
	movs r2, #0xa0
	lsls r2, r2, #8
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne .L080F3180
	movs r0, #0
	b .L080F3188
	.byte 0x00, 0x00
.L080F317C: .4byte 0xFFFF8000
.L080F3180:
	adds r4, #1
	cmp r4, #3
	ble .L080F3148
	movs r0, #1
.L080F3188:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F3190
sub_080F3190: @ 0x080F3190
.L080F3190:
	push {r4, lr}
	movs r0, #0x80
	lsls r0, r0, #8
	bl sub_080C0148
	adds r4, r0, #0
	ldr r0, .L080F31C0
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080F31C4
	bl sub_080C5D0C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080F31C4
	movs r0, #0x55
	b .L080F31DA
	.byte 0x00, 0x00
.L080F31C0: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F31C4:
	ldrh r1, [r4, #0x10]
	ldr r0, .L080F31D4
	ands r0, r1
	cmp r0, #0
	bne .L080F31D8
	movs r0, #0
	b .L080F31DA
	.byte 0x00, 0x00
.L080F31D4: .4byte 0x0000B1E0
.L080F31D8:
	movs r0, #0x53
.L080F31DA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080F31E0
sub_080F31E0: @ 0x080F31E0
.L080F31E0:
	push {lr}
	ldr r0, .L080F3208
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080F320C
	bl sub_080C5D0C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080F320C
	movs r0, #1
	b .L080F320E
	.byte 0x00, 0x00
.L080F3208: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F320C:
	movs r0, #0
.L080F320E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F3214
sub_080F3214: @ 0x080F3214
.L080F3214:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080F3244
	add r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r5, r0, #0
	ldrh r6, [r5, #0x10]
	mov r0, r8
	adds r1, r4, #0
	bl sub_080C08F8
	strh r6, [r5, #0x10]
	cmp r0, #0
	beq .L080F3248
	movs r0, #0
	b .L080F324A
	.byte 0x00, 0x00
.L080F3244: .4byte 0xFFFF8000
.L080F3248:
	movs r0, #1
.L080F324A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Skill_DrawEquippedRow
Skill_DrawEquippedRow: @ 0x080F3254
	push {r4, r5, r6, lr}
	sub sp, #0x14
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	mov r1, sp
	bl Combatant_DecodeName
	cmp r5, #4
	bne .L080F32F4
	ldr r0, .L080F32E0
	ldr r2, .L080F32E4
	adds r1, r0, r2
	movs r2, #0x80
	bl CpuFastSet
	movs r4, #0
	add r6, sp, #0x10
.L080F3276:
	lsls r2, r4, #1
	mov r0, sp
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080F3296
	adds r2, r2, r4
	lsls r2, r2, #0x12
	movs r1, #0x80
	lsls r1, r1, #0x10
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	ldr r1, .L080F32E8
	movs r3, #4
	bl Font_DrawGlyph
.L080F3296:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls .L080F3276
	ldr r4, .L080F32EC
	movs r2, #0xd0
	lsls r2, r2, #5
	adds r1, r4, r2
	adds r0, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	movs r0, #0x80
	lsls r0, r0, #3
	adds r5, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	movs r1, #0x80
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x80
	bl CpuFastSet
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r2, .L080F32F0
	adds r0, r6, #0
	adds r1, r4, #0
	bl CpuFastSet
	b .L080F3320
.L080F32E0: .4byte 0x03001CB4 @ IWRAM+0x1CB4
.L080F32E4: .4byte 0xFFFFE600
.L080F32E8: .4byte 0x030000B4 @ IWRAM+0xB4
.L080F32EC: .4byte 0x030002B4 @ IWRAM+0x2B4
.L080F32F0: .4byte 0x01000080
.L080F32F4:
	movs r4, #0
	movs r0, #0xd
	muls r0, r5, r0
	adds r0, #8
	lsls r5, r0, #0x10
.L080F32FE:
	lsls r2, r4, #1
	mov r0, sp
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080F3316
	adds r2, r2, r4
	lsls r2, r2, #2
	ldr r1, .L080F3328
	lsrs r3, r5, #0x10
	bl Font_DrawGlyph
.L080F3316:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls .L080F32FE
.L080F3320:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080F3328: .4byte 0x030000B4 @ IWRAM+0xB4

	thumb_func_start sub_080F332C
sub_080F332C: @ 0x080F332C
.L080F332C:
	push {lr}
	ldr r0, .L080F3348
	ldr r2, .L080F334C
	adds r1, r0, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #1
	beq .L080F3364
	cmp r0, #1
	bgt .L080F3350
	cmp r0, #0
	beq .L080F335A
	b .L080F3390
	.byte 0x00, 0x00
.L080F3348: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F334C: .4byte 0x0000097E
.L080F3350:
	cmp r0, #2
	beq .L080F336A
	cmp r0, #3
	beq .L080F338C
	b .L080F3390
.L080F335A:
	movs r0, #1
	strh r0, [r1]
	bl sub_081293F8
	b .L080F3390
.L080F3364:
	movs r0, #2
	strh r0, [r1]
	b .L080F3390
.L080F336A:
	bl sub_08129440
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080F3384
	cmp r0, #1
	ble .L080F3390
	cmp r0, #2
	beq .L080F3388
	cmp r0, #0xff
	beq .L080F338C
	b .L080F3390
.L080F3384:
	movs r0, #1
	b .L080F3392
.L080F3388:
	movs r0, #2
	b .L080F3392
.L080F338C:
	movs r0, #3
	b .L080F3392
.L080F3390:
	movs r0, #0
.L080F3392:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F3398
sub_080F3398: @ 0x080F3398
.L080F3398:
	push {r4, lr}
	ldr r0, .L080F33B4
	ldr r1, .L080F33B8
	adds r4, r0, r1
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #1
	beq .L080F33CC
	cmp r0, #1
	bgt .L080F33BC
	cmp r0, #0
	beq .L080F33C2
	b .L080F33E0
	.byte 0x00, 0x00
.L080F33B4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F33B8: .4byte 0x0000097E
.L080F33BC:
	cmp r0, #6
	beq .L080F33DC
	b .L080F33E0
.L080F33C2:
	bl sub_0812D390
	movs r0, #1
	strh r0, [r4]
	b .L080F33E0
.L080F33CC:
	bl sub_0812D5FC
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080F33E0
	movs r0, #6
	strh r0, [r4]
	b .L080F33E0
.L080F33DC:
	movs r0, #1
	b .L080F33E2
.L080F33E0:
	movs r0, #0
.L080F33E2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080F33E8
sub_080F33E8: @ 0x080F33E8
.L080F33E8:
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r5, .L080F340C
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r4, r5, r0
	ldr r1, .L080F3410
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #8
	bls .L080F3402
	b .L080F3734
.L080F3402:
	lsls r0, r0, #2
	ldr r1, .L080F3414
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F340C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F3410: .4byte 0x0000097E
.L080F3414: .4byte gUnknown_080F3418
	.global gUnknown_080F3418
gUnknown_080F3418:
.L080F3418: @ jump table
	.4byte .L080F343C
	.4byte .L080F34A2
	.4byte .L080F351C
	.4byte .L080F353C
	.4byte .L080F3554
	.4byte .L080F356C
	.4byte .L080F357E
	.4byte .L080F358C
	.4byte .L080F3650
.L080F343C:
	ldr r0, .L080F3464
	adds r4, r5, r0
	movs r0, #0
	strh r0, [r4]
	bl sub_080EDAD0
	cmp r0, #0
	beq .L080F3470
	ldr r0, .L080F3468
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldr r2, .L080F346C
	adds r1, r5, r2
	b .L080F362E
	.byte 0x00, 0x00
.L080F3464: .4byte 0x00001190
.L080F3468: .4byte gUnknown_08124A62
.L080F346C: .4byte 0x0000097E
.L080F3470:
	bl Battle_IsTwoSided
	cmp r0, #0
	beq .L080F3488
	ldr r0, .L080F3484
	adds r1, r5, r0
	movs r0, #7
	strh r0, [r1]
	b .L080F3734
	.byte 0x00, 0x00
.L080F3484: .4byte 0x0000097E
.L080F3488:
	ldrh r1, [r4]
	lsls r1, r1, #2
	movs r2, #0x99
	lsls r2, r2, #4
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r0, [r0]
	bl sub_080C2554
	cmp r0, #0
	bne .L080F34A0
	b .L080F361A
.L080F34A0:
	b .L080F355C
.L080F34A2:
	ldr r1, .L080F3514
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0
	bl Window_SetHeight
	bl BattleMenu_Reset
	movs r4, #1
	str r4, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0x15
	movs r3, #3
	bl TextWindow_Create
	str r0, [r5, #0x4c]
	str r4, [sp]
	movs r0, #1
	movs r1, #3
	movs r2, #0xb
	movs r3, #6
	bl TextWindow_Create
	str r0, [r5, #0x50]
	str r4, [sp]
	movs r0, #0xf
	movs r1, #7
	movs r2, #0xe
	movs r3, #6
	bl TextWindow_Create
	str r0, [r5, #0x54]
	ldr r2, .L080F3518
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bl Battle_IsTwoSided
	cmp r0, #0
	beq .L080F350C
	movs r0, #0
	bl sub_080EDA24
	cmp r0, #0
	beq .L080F350C
	movs r0, #1
	bl sub_080EDA24
	cmp r0, #0
	beq .L080F350C
	b .L080F3734
.L080F350C:
	movs r0, #0
	bl sub_080E6DBC
	b .L080F3734
.L080F3514: .4byte 0x00000974
.L080F3518: .4byte 0x0000097E
.L080F351C:
	movs r0, #0
	bl sub_080F3740
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080F352A
	b .L080F3734
.L080F352A:
	ldr r0, .L080F3538
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	bl sub_080F390C
	b .L080F355C
.L080F3538: .4byte 0x00000693
.L080F353C:
	bl sub_080F3C4C
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080F3548
	b .L080F3734
.L080F3548:
	ldr r0, .L080F3550
	adds r1, r5, r0
	b .L080F3560
	.byte 0x00, 0x00
.L080F3550: .4byte 0x0000097E
.L080F3554:
	bl sub_080ECB38
	bl sub_080F3DA4
.L080F355C:
	ldr r2, .L080F3568
	adds r1, r5, r2
.L080F3560:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b .L080F3734
.L080F3568: .4byte 0x0000097E
.L080F356C:
	movs r0, #1
	bl sub_080F3740
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080F357A
	b .L080F3734
.L080F357A:
	movs r0, #1
	b .L080F3736
.L080F357E:
	bl BattleMsg_IsDone
	cmp r0, #1
	beq .L080F3588
	b .L080F3734
.L080F3588:
	movs r0, #1
	b .L080F3736
.L080F358C:
	movs r0, #0
	bl sub_080EDA24
	cmp r0, #0
	beq .L080F35E0
	movs r0, #1
	bl sub_080EDA24
	cmp r0, #0
	beq .L080F35E0
	ldr r1, .L080F35D0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	movs r0, #1
	bl sub_080E6DBC
	ldr r0, .L080F35D4
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080F35D8
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, .L080F35DC
	adds r1, r5, r2
	movs r0, #8
	strh r0, [r1]
	b .L080F3734
	.byte 0x00, 0x00
.L080F35D0: .4byte gUnknown_081242CE
.L080F35D4: .4byte 0x00001190
.L080F35D8: .4byte 0x00000695
.L080F35DC: .4byte 0x0000097E
.L080F35E0:
	movs r0, #0
	bl sub_080EDA24
	cmp r0, #0
	beq .L080F35F8
	ldr r0, .L080F35F4
	adds r1, r5, r0
	movs r0, #0
	b .L080F35FE
	.byte 0x00, 0x00
.L080F35F4: .4byte 0x00001190
.L080F35F8:
	ldr r2, .L080F3634
	adds r1, r5, r2
	movs r0, #1
.L080F35FE:
	strh r0, [r1]
	ldr r1, .L080F3634
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r1, r1, #2
	movs r2, #0x99
	lsls r2, r2, #4
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r0, [r0]
	bl sub_080C2554
	cmp r0, #0
	bne .L080F3640
.L080F361A:
	ldr r0, .L080F3638
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldr r0, .L080F363C
	adds r1, r5, r0
.L080F362E:
	movs r0, #6
	strh r0, [r1]
	b .L080F3734
.L080F3634: .4byte 0x00001190
.L080F3638: .4byte gUnknown_08124A50
.L080F363C: .4byte 0x0000097E
.L080F3640:
	ldr r2, .L080F364C
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	b .L080F3734
	.byte 0x00, 0x00
.L080F364C: .4byte 0x0000097E
.L080F3650:
	ldr r2, .L080F3674
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq .L080F3680
	ldr r0, .L080F3678
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #1
	beq .L080F3734
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L080F367C
	ldrh r0, [r0, #4]
	b .L080F369A
.L080F3674: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080F3678: .4byte 0x00000695
.L080F367C: .4byte gUnknown_086BF72C
.L080F3680:
	ldrh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080F36AC
	ldr r2, .L080F36A4
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080F3734
	strb r3, [r1]
	ldr r0, .L080F36A8
	ldrh r0, [r0, #2]
.L080F369A:
	strh r0, [r4, #0xc]
	movs r0, #0x64
	bl sub_080ECF70
	b .L080F3734
.L080F36A4: .4byte 0x00000695
.L080F36A8: .4byte gUnknown_086BF72C
.L080F36AC:
	ldrh r1, [r2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080F371C
	ldr r1, .L080F3700
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r2, .L080F3704
	adds r4, r5, r2
	strh r0, [r4]
	movs r0, #0x65
	bl sub_080ECF70
	ldrh r1, [r4]
	lsls r1, r1, #2
	movs r2, #0x99
	lsls r2, r2, #4
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r0, [r0]
	bl sub_080C2554
	cmp r0, #0
	bne .L080F3710
	ldr r0, .L080F3708
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldr r0, .L080F370C
	adds r1, r5, r0
	movs r0, #6
	strh r0, [r1]
	bl sub_080ECB38
	b .L080F3734
	.byte 0x00, 0x00
.L080F3700: .4byte 0x00000695
.L080F3704: .4byte 0x00001190
.L080F3708: .4byte gUnknown_08124A50
.L080F370C: .4byte 0x0000097E
.L080F3710:
	ldr r1, .L080F3718
	adds r0, r5, r1
	strh r6, [r0]
	b .L080F3734
.L080F3718: .4byte 0x0000097E
.L080F371C:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080F3734
	movs r0, #0x66
	bl sub_080ECF70
	bl sub_080ECB38
	movs r0, #1
	b .L080F3736
.L080F3734:
	movs r0, #0
.L080F3736:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F3740
sub_080F3740: @ 0x080F3740
.L080F3740:
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, .L080F376C
	ldr r3, [r0, #0x50]
	adds r0, r3, #0
	adds r0, #0x24
	movs r1, #0
	cmp r2, #1
	beq .L080F3770
	cmp r2, #1
	bgt .L080F3778
	cmp r2, #0
	bne .L080F3778
	ldrh r0, [r3, #0x1e]
	movs r1, #0xff
	eors r0, r1
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	b .L080F3778
	.byte 0x00, 0x00
.L080F376C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F3770:
	ldrh r0, [r0, #0xa]
	cmp r0, #2
	bne .L080F3778
	movs r1, #1
.L080F3778:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F3780
sub_080F3780: @ 0x080F3780
	push {r4, lr}
	ldr r1, .L080F37F0
	ldr r0, .L080F37F4
	str r0, [r1]
	ldr r0, .L080F37F8
	str r0, [r1, #4]
	ldr r0, .L080F37FC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	ldr r3, .L080F3800
	ldr r4, .L080F3804
	cmp r0, #0
	bge .L080F37A8
.L080F37A0:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L080F37A0
.L080F37A8:
	ldr r1, .L080F37F0
	str r3, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080F3808
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L080F37CA
.L080F37C2:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L080F37C2
.L080F37CA:
	ldr r1, .L080F37F0
	str r4, [r1]
	ldr r0, .L080F380C
	str r0, [r1, #4]
	ldr r0, .L080F3810
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L080F37EA
.L080F37E2:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L080F37E2
.L080F37EA:
	pop {r4}
	pop {r0}
	bx r0
.L080F37F0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080F37F4: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080F37F8: .4byte 0x06001000 @ VRAM+0x1000
.L080F37FC: .4byte 0x84000200
.L080F3800: .4byte gUnknown_08771F54
.L080F3804: .4byte 0x030000B4 @ IWRAM+0xB4
.L080F3808: .4byte 0x840000D0
.L080F380C: .4byte 0x06006000 @ VRAM+0x6000
.L080F3810: .4byte 0x84000800

	thumb_func_start sub_080F3814
sub_080F3814: @ 0x080F3814
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080F3848
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080F384C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L080F3840
.L080F3838:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L080F3838
.L080F3840:
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F3848: .4byte 0x040000D4 @ REG_DMA3SAD
.L080F384C: .4byte 0x850000D0

	thumb_func_start sub_080F3850
sub_080F3850: @ 0x080F3850
.L080F3850:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	movs r5, #0
	cmp r5, r8
	bhs .L080F38F6
.L080F3870:
	mov r1, sb
	adds r0, r5, r1
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0xff
	beq .L080F38BC
	bl sub_080BF5C0
	adds r6, r0, #6
	movs r4, #0
	adds r7, r5, #1
	movs r0, #0xd
	muls r0, r5, r0
	adds r0, #3
	lsls r5, r0, #0x10
.L080F388E:
	ldrh r0, [r6]
	adds r6, #2
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #0x12
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #0
	str r1, [sp]
	ldr r1, .L080F38B8
	lsrs r3, r5, #0x10
	bl Font_DrawGlyphTinted
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #7
	bls .L080F388E
	b .L080F38EE
.L080F38B8: .4byte 0x030002B4 @ IWRAM+0x2B4
.L080F38BC:
	movs r4, #0
	adds r7, r5, #1
	movs r0, #0xd
	muls r0, r5, r0
	adds r0, #3
	lsls r5, r0, #0x10
.L080F38C8:
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #0x12
	movs r0, #0xc0
	lsls r0, r0, #0xc
	adds r2, r2, r0
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	movs r0, #0x3c
	ldr r1, .L080F3908
	lsrs r3, r5, #0x10
	bl Font_DrawGlyphTinted
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #7
	bls .L080F38C8
.L080F38EE:
	lsls r0, r7, #0x10
	lsrs r5, r0, #0x10
	cmp r5, r8
	blo .L080F3870
.L080F38F6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F3908: .4byte 0x030002B4 @ IWRAM+0x2B4

	thumb_func_start sub_080F390C
sub_080F390C: @ 0x080F390C
.L080F390C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r4, .L080F3980
	ldr r0, .L080F3984
	adds r5, r4, r0
	ldrh r0, [r5]
	lsls r0, r0, #2
	movs r1, #0x99
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r0, r0, r4
	ldrh r0, [r0]
	bl Demon_GetRecord
	adds r7, r0, #0
	ldrh r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	bl sub_0815B864
	adds r6, r0, #0
	bl sub_081272AC
	movs r4, #0
.L080F3948:
	lsls r3, r4, #3
	ldr r0, .L080F3988
	adds r5, r3, r0
	adds r3, r3, r4
	adds r3, #6
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	adds r0, r5, #0
	ldr r1, .L080F398C
	movs r2, #3
	bl SmallFont_DrawAsciiTinted
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #3
	bls .L080F3948
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0xc
	bgt .L080F3994
	ldr r5, .L080F3990
	b .L080F399C
	.byte 0x00, 0x00
.L080F3980: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F3984: .4byte 0x00001190
.L080F3988: .4byte gUnknown_0876F81C
.L080F398C: .4byte 0x030000B4 @ IWRAM+0xB4
.L080F3990: .4byte gUnknown_0876F83C
.L080F3994:
	ldr r5, .L080F39B8
	cmp r0, #0x1a
	bgt .L080F399C
	subs r5, #8
.L080F399C:
	ldr r1, .L080F39BC
	movs r0, #0
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x3e
	movs r3, #6
	bl SmallFont_DrawAsciiTinted
	cmp r6, #0
	bne .L080F39C4
	ldr r5, .L080F39C0
	b .L080F39D6
.L080F39B8: .4byte gUnknown_0876F84C
.L080F39BC: .4byte 0x030000B4 @ IWRAM+0xB4
.L080F39C0: .4byte gUnknown_0876F854
.L080F39C4:
	cmp r6, #1
	bne .L080F39D0
	ldr r5, .L080F39CC
	b .L080F39D6
.L080F39CC: .4byte gUnknown_0876F85C
.L080F39D0:
	cmp r6, #2
	bne .L080F39D6
	ldr r5, .L080F3B0C
.L080F39D6:
	ldr r6, .L080F3B10
	movs r4, #0
	str r4, [sp]
	movs r0, #8
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x4e
	movs r3, #6
	bl SmallFont_DrawAsciiTinted
	ldrb r0, [r7, #1]
	bl NumberToDigits
	adds r5, r0, #0
	ldrb r0, [r5]
	adds r0, #9
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x4e
	movs r3, #0xf
	bl SmallFont_DrawGlyphTinted
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq .L080F3A18
	adds r0, #9
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x46
	movs r3, #0xf
	bl SmallFont_DrawGlyphTinted
.L080F3A18:
	movs r1, #2
	ldrsh r0, [r7, r1]
	bl NumberToDigits
	adds r5, r0, #0
	ldrb r0, [r5]
	adds r0, #9
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x4e
	movs r3, #0x18
	bl SmallFont_DrawGlyphTinted
	ldrb r0, [r5, #1]
	cmp r0, #0
	bne .L080F3A3E
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq .L080F3A62
.L080F3A3E:
	ldrb r0, [r5, #1]
	adds r0, #9
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x46
	movs r3, #0x18
	bl SmallFont_DrawGlyphTinted
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq .L080F3A62
	adds r0, #9
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x3e
	movs r3, #0x18
	bl SmallFont_DrawGlyphTinted
.L080F3A62:
	movs r1, #4
	ldrsh r0, [r7, r1]
	bl NumberToDigits
	adds r5, r0, #0
	ldrb r0, [r5]
	adds r0, #9
	ldr r6, .L080F3B10
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x4e
	movs r3, #0x21
	bl SmallFont_DrawGlyphTinted
	ldrb r0, [r5, #1]
	cmp r0, #0
	bne .L080F3A8C
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq .L080F3AB0
.L080F3A8C:
	ldrb r0, [r5, #1]
	adds r0, #9
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x46
	movs r3, #0x21
	bl SmallFont_DrawGlyphTinted
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq .L080F3AB0
	adds r0, #9
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x3e
	movs r3, #0x21
	bl SmallFont_DrawGlyphTinted
.L080F3AB0:
	mov r0, r8
	cmp r0, #2
	bhi .L080F3B3A
	movs r2, #0
	movs r4, #0
	adds r3, r7, #0
	adds r3, #0x11
	movs r5, #0xff
.L080F3AC0:
	mov r0, sp
	adds r0, r0, r4
	adds r0, #8
	ldrb r1, [r0]
	orrs r1, r5
	strb r1, [r0]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #6
	bls .L080F3AC0
	movs r4, #0
.L080F3AD8:
	adds r0, r3, r4
	ldrb r1, [r0]
	adds r0, r1, #0
	cmp r0, #0xff
	beq .L080F3AF0
	mov r0, sp
	adds r0, r0, r2
	adds r0, #8
	strb r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
.L080F3AF0:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #6
	bls .L080F3AD8
	mov r1, r8
	cmp r1, #1
	beq .L080F3B22
	cmp r1, #1
	bgt .L080F3B14
	cmp r1, #0
	beq .L080F3B1C
	b .L080F3BF0
	.byte 0x00, 0x00
.L080F3B0C: .4byte gUnknown_0876F864
.L080F3B10: .4byte 0x030000B4 @ IWRAM+0xB4
.L080F3B14:
	mov r0, r8
	cmp r0, #2
	beq .L080F3B2E
	b .L080F3BF0
.L080F3B1C:
	add r0, sp, #8
	movs r1, #0
	b .L080F3B26
.L080F3B22:
	add r0, sp, #8
	movs r1, #3
.L080F3B26:
	movs r2, #3
	bl sub_080F3850
	b .L080F3BF0
.L080F3B2E:
	add r0, sp, #8
	movs r1, #6
	movs r2, #1
	bl sub_080F3850
	b .L080F3BF0
.L080F3B3A:
	adds r4, r7, #0
	adds r4, #0x32
	movs r5, #0
	adds r6, r7, #0
	adds r6, #0x48
.L080F3B44:
	ldrh r0, [r4]
	adds r4, #2
	lsls r2, r5, #1
	adds r2, r2, r5
	lsls r2, r2, #0x12
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #0
	str r1, [sp]
	ldr r1, .L080F3BA4
	movs r3, #3
	bl Font_DrawGlyphTinted
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bls .L080F3B44
	adds r4, r6, #0
	movs r5, #0
.L080F3B70:
	ldrh r0, [r4]
	adds r4, #2
	lsls r2, r5, #1
	adds r2, r2, r5
	lsls r2, r2, #0x12
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #0
	str r1, [sp]
	ldr r1, .L080F3BA4
	movs r3, #0x10
	bl Font_DrawGlyphTinted
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bls .L080F3B70
	ldrh r1, [r7, #0x1a]
	ldrb r0, [r7, #0x1a]
	cmp r0, #0xff
	bne .L080F3BAC
	ldr r4, .L080F3BA8
	b .L080F3BC6
.L080F3BA4: .4byte 0x030002B4 @ IWRAM+0x2B4
.L080F3BA8: .4byte gUnknown_0876F86C
.L080F3BAC:
	cmp r1, #0xcf
	bhi .L080F3BBA
	bl Equipment_GetRecord36_MidRange
	adds r4, r0, #0
	adds r4, #0x14
	b .L080F3BC6
.L080F3BBA:
	ldr r0, .L080F3BFC
	ands r0, r1
	bl Action_GetRecord
	adds r4, r0, #0
	adds r4, #0xc
.L080F3BC6:
	movs r5, #0
.L080F3BC8:
	ldrh r0, [r4]
	adds r4, #2
	lsls r2, r5, #1
	adds r2, r2, r5
	lsls r2, r2, #0x12
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #6
	str r1, [sp]
	ldr r1, .L080F3C00
	movs r3, #0x1d
	bl Font_DrawGlyphTinted
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bls .L080F3BC8
.L080F3BF0:
	ldrb r0, [r7]
	bl sub_080EA9F8
	adds r4, r0, #0
	movs r5, #0
	b .L080F3C28
.L080F3BFC: .4byte 0x000001FF
.L080F3C00: .4byte 0x030002B4 @ IWRAM+0x2B4
.L080F3C04:
	ldrh r0, [r4]
	adds r4, #2
	lsls r2, r5, #1
	adds r2, r2, r5
	lsls r2, r2, #0x12
	movs r1, #0x80
	lsls r1, r1, #0xb
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #6
	str r1, [sp]
	ldr r1, .L080F3C44
	movs r3, #4
	bl Font_DrawGlyphTinted
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080F3C28:
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080F3C04
	ldr r0, .L080F3C48
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F3C44: .4byte 0x030014B4 @ IWRAM+0x14B4
.L080F3C48: .4byte sub_080F3780

	thumb_func_start sub_080F3C4C
sub_080F3C4C: @ 0x080F3C4C
.L080F3C4C:
	push {r4, r5, lr}
	sub sp, #0x20
	ldr r4, .L080F3C8C
	ldr r1, .L080F3C90
	adds r0, r4, r1
	ldrh r0, [r0]
	lsls r0, r0, #2
	movs r2, #0x99
	lsls r2, r2, #4
	adds r1, r4, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	bl Demon_GetRecord
	adds r5, r0, #0
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0x14
	bl memset
	ldr r2, .L080F3C94
	ldrh r1, [r2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq .L080F3C98
	movs r0, #0x66
	bl sub_080C51D4
	movs r0, #1
	b .L080F3D96
	.byte 0x00, 0x00
.L080F3C8C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F3C90: .4byte 0x00001190
.L080F3C94: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080F3C98:
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080F3CC4
	ldr r0, .L080F3CC0
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080F3CE8
	subs r0, #1
	strb r0, [r1]
	ldrb r0, [r1]
	bl sub_080F390C
	movs r0, #0x64
	bl sub_080C51D4
	b .L080F3CE8
	.byte 0x00, 0x00
.L080F3CC0: .4byte 0x00000693
.L080F3CC4:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080F3CE8
	ldr r2, .L080F3D34
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #3
	beq .L080F3CE8
	adds r0, #1
	strb r0, [r1]
	ldrb r0, [r1]
	bl sub_080F390C
	movs r0, #0x64
	bl sub_080C51D4
.L080F3CE8:
	movs r2, #0
	adds r3, r5, #0
	adds r3, #0x22
.L080F3CEE:
	lsls r0, r2, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #0xc
	adds r0, r3, r0
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls .L080F3CEE
	movs r0, #3
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0x4a
	bl Text_DrawSpriteString
	ldr r1, .L080F3D34
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r2, r0, #0
	cmp r2, #0
	bne .L080F3D3C
	ldr r0, .L080F3D38
	str r2, [sp]
	movs r1, #0xde
	str r1, [sp, #4]
	movs r1, #0x5c
	b .L080F3D66
	.byte 0x00, 0x00
.L080F3D34: .4byte 0x00000693
.L080F3D38: .4byte gUnknown_08001000
.L080F3D3C:
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi .L080F3D7C
	ldr r0, .L080F3D74
	movs r5, #0
	str r5, [sp]
	movs r4, #0xde
	str r4, [sp, #4]
	movs r1, #0x5c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldr r0, .L080F3D78
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
.L080F3D66:
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	b .L080F3D94
.L080F3D74: .4byte gUnknown_08001000
.L080F3D78: .4byte gUnknown_08000FF0
.L080F3D7C:
	ldr r0, .L080F3DA0
	movs r1, #0
	str r1, [sp]
	movs r1, #0xde
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080F3D94:
	movs r0, #0
.L080F3D96:
	add sp, #0x20
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080F3DA0: .4byte gUnknown_08000FF0

	thumb_func_start sub_080F3DA4
sub_080F3DA4: @ 0x080F3DA4
.L080F3DA4:
	push {r4, lr}
	ldr r4, .L080F3DD0
	ldr r0, [r4, #0x4c]
	movs r1, #0
	bl TextWindow_Close
	ldr r0, [r4, #0x50]
	movs r1, #0
	bl TextWindow_Close
	ldr r0, [r4, #0x54]
	movs r1, #0
	bl TextWindow_Close
	ldr r0, .L080F3DD4
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F3DD0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F3DD4: .4byte sub_080F3814

	thumb_func_start sub_080F3DD8
sub_080F3DD8: @ 0x080F3DD8
.L080F3DD8:
	push {lr}
	bl sub_080C1D9C
	lsrs r0, r0, #4
	movs r1, #0xf
	ands r0, r1
	pop {r1}
	bx r1

	thumb_func_start sub_080F3DE8
sub_080F3DE8: @ 0x080F3DE8
	ldr r1, .L080F3DF0
	ldr r1, [r1]
	strh r0, [r1, #0x1a]
	bx lr
.L080F3DF0: .4byte 0x03006438 @ IWRAM+0x6438

	thumb_func_start sub_080F3DF4
sub_080F3DF4: @ 0x080F3DF4
	ldr r0, .L080F3E00
	ldr r0, [r0]
	movs r1, #0x1a
	ldrsh r0, [r0, r1]
	bx lr
	.byte 0x00, 0x00
.L080F3E00: .4byte 0x03006438 @ IWRAM+0x6438

	thumb_func_start sub_080F3E04
sub_080F3E04: @ 0x080F3E04
	ldr r1, .L080F3E0C
	ldr r1, [r1]
	strh r0, [r1, #0x1c]
	bx lr
.L080F3E0C: .4byte 0x03006438 @ IWRAM+0x6438

	thumb_func_start sub_080F3E10
sub_080F3E10: @ 0x080F3E10
	ldr r0, .L080F3E1C
	ldr r0, [r0]
	movs r1, #0x1c
	ldrsh r0, [r0, r1]
	bx lr
	.byte 0x00, 0x00
.L080F3E1C: .4byte 0x03006438 @ IWRAM+0x6438

	thumb_func_start sub_080F3E20
sub_080F3E20: @ 0x080F3E20
.L080F3E20:
	push {lr}
	bl sub_080C30AC
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F3E2C
sub_080F3E2C: @ 0x080F3E2C
.L080F3E2C:
	push {lr}
	bl sub_080C3114
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F3E38
sub_080F3E38: @ 0x080F3E38
.L080F3E38:
	ldr r1, .L080F3E40
	ldr r1, [r1]
	strh r0, [r1, #0x16]
	bx lr
.L080F3E40: .4byte 0x03006438 @ IWRAM+0x6438

	thumb_func_start sub_080F3E44
sub_080F3E44: @ 0x080F3E44
.L080F3E44:
	ldr r0, .L080F3E50
	ldr r0, [r0]
	movs r1, #0x16
	ldrsh r0, [r0, r1]
	bx lr
	.byte 0x00, 0x00
.L080F3E50: .4byte 0x03006438 @ IWRAM+0x6438

	thumb_func_start sub_080F3E54
sub_080F3E54: @ 0x080F3E54
.L080F3E54:
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	cmp r5, #0
	bne .L080F3E60
	movs r0, #0
	b .L080F3E90
.L080F3E60:
	cmp r5, #0
	ble .L080F3E7A
	cmp r5, #0
	ble .L080F3E8E
	lsls r6, r0, #0x10
	adds r4, r5, #0
.L080F3E6C:
	lsrs r0, r6, #0x10
	bl sub_080C3328
	subs r4, #1
	cmp r4, #0
	bne .L080F3E6C
	b .L080F3E8E
.L080F3E7A:
	movs r4, #0
	cmp r4, r5
	ble .L080F3E8E
	lsls r6, r0, #0x10
.L080F3E82:
	lsrs r0, r6, #0x10
	bl sub_080C33AC
	subs r4, #1
	cmp r4, r5
	bgt .L080F3E82
.L080F3E8E:
	adds r0, r5, #0
.L080F3E90:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F3E98
sub_080F3E98: @ 0x080F3E98
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C3100
	cmp r0, r4
	bhs .L080F3EA8
	movs r0, #0
	b .L080F3EAA
.L080F3EA8:
	movs r0, #1
.L080F3EAA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080F3EB0
sub_080F3EB0: @ 0x080F3EB0
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C3168
	cmp r0, r4
	bhs .L080F3EC0
	movs r0, #0
	b .L080F3EC2
.L080F3EC0:
	movs r0, #1
.L080F3EC2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080F3EC8
sub_080F3EC8: @ 0x080F3EC8
.L080F3EC8:
	push {lr}
	ldr r1, .L080F3EE8
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r1, [r0, #0xe]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	bne .L080F3EEC
	movs r0, #0
	b .L080F3EEE
	.byte 0x00, 0x00
.L080F3EE8: .4byte 0xFFFF8000
.L080F3EEC:
	movs r0, #1
.L080F3EEE:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F3EF4
sub_080F3EF4: @ 0x080F3EF4
.L080F3EF4:
	push {r4, lr}
	lsls r4, r1, #0x18
	lsrs r4, r4, #0x18
	ldr r1, .L080F3F10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x5c
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
.L080F3F10: .4byte 0xFFFF8000

	thumb_func_start sub_080F3F14
sub_080F3F14: @ 0x080F3F14
.L080F3F14:
	push {lr}
	ldr r1, .L080F3F2C
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x5c
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080F3F2C: .4byte 0xFFFF8000

	thumb_func_start sub_080F3F30
sub_080F3F30: @ 0x080F3F30
.L080F3F30:
	ldr r1, .L080F3F3C
	ldr r2, .L080F3F40
	adds r1, r1, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080F3F3C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F3F40: .4byte 0x00001146

	thumb_func_start sub_080F3F44
sub_080F3F44: @ 0x080F3F44
.L080F3F44:
	ldr r0, .L080F3F50
	ldr r1, .L080F3F54
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080F3F50: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F3F54: .4byte 0x00001146

	thumb_func_start sub_080F3F58
sub_080F3F58: @ 0x080F3F58
.L080F3F58:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080F3F6C
	ldr r2, .L080F3F70
	adds r1, r1, r2
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080F3F6C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F3F70: .4byte 0x00001146

	thumb_func_start sub_080F3F74
sub_080F3F74: @ 0x080F3F74
.L080F3F74:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080F3F88
	ldr r2, .L080F3F8C
	adds r1, r1, r2
	ldrh r2, [r1]
	orrs r0, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080F3F88: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F3F8C: .4byte 0x00001146

	thumb_func_start sub_080F3F90
sub_080F3F90: @ 0x080F3F90
.L080F3F90:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r1, #0
	movs r6, #0xfa
	lsls r6, r6, #2
	cmp r5, #0xf
	bgt .L080F3FBC
	bl sub_080F3F44
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	beq .L080F3FBC
	ldr r0, .L080F3FB8
	bl sub_080F3F58
	movs r0, #0
	b .L080F4014
.L080F3FB8: .4byte 0x0000FDFF
.L080F3FBC:
	cmp r5, #3
	bgt .L080F4000
	movs r4, #0
.L080F3FC2:
	adds r1, r4, #2
	adds r0, r5, #0
	bl sub_080C00DC
	str r0, [sp]
	cmp r0, #0xff
	beq .L080F3FEA
	movs r1, #7
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	adds r1, r7, #0
	bl sub_080ED3D0
	cmp r0, #0xb
	bgt .L080F4014
	cmp r0, r6
	bge .L080F3FEA
	adds r6, r0, #0
.L080F3FEA:
	adds r4, #1
	cmp r4, #3
	ble .L080F3FC2
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r6, r0
	bne .L080F3FFC
	movs r0, #8
	b .L080F4014
.L080F3FFC:
	adds r0, r6, #0
	b .L080F4014
.L080F4000:
	adds r0, r5, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080ED494
	adds r1, r7, #0
	bl sub_080ED3D0
.L080F4014:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080F401C
sub_080F401C: @ 0x080F401C
.L080F401C:
	push {lr}
	ldr r1, .L080F4034
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080F4034: .4byte 0xFFFF8000

	thumb_func_start sub_080F4038
sub_080F4038: @ 0x080F4038
.L080F4038:
	push {lr}
	ldr r1, .L080F4050
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x1a
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080F4050: .4byte 0xFFFF8000

	thumb_func_start sub_080F4054
sub_080F4054: @ 0x080F4054
.L080F4054:
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080F406C
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	strh r4, [r0, #0x18]
	pop {r4}
	pop {r0}
	bx r0
.L080F406C: .4byte 0xFFFF8000

	thumb_func_start sub_080F4070
sub_080F4070: @ 0x080F4070
.L080F4070:
	push {lr}
	ldr r1, .L080F4088
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x1c
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080F4088: .4byte 0xFFFF8000

	thumb_func_start sub_080F408C
sub_080F408C: @ 0x080F408C
.L080F408C:
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080F40A4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	strh r4, [r0, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
.L080F40A4: .4byte 0xFFFF8000

	thumb_func_start sub_080F40A8
sub_080F40A8: @ 0x080F40A8
.L080F40A8:
	push {lr}
	ldr r1, .L080F40C0
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x1e
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080F40C0: .4byte 0xFFFF8000

	thumb_func_start sub_080F40C4
sub_080F40C4: @ 0x080F40C4
.L080F40C4:
	ldr r1, .L080F40D0
	ldr r2, .L080F40D4
	adds r1, r1, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080F40D0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F40D4: .4byte 0x0000113C

	thumb_func_start sub_080F40D8
sub_080F40D8: @ 0x080F40D8
	ldr r0, .L080F40E4
	ldr r1, .L080F40E8
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
.L080F40E4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F40E8: .4byte 0x0000113C

	thumb_func_start sub_080F40EC
sub_080F40EC: @ 0x080F40EC
.L080F40EC:
	ldr r1, .L080F4100
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r1, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bx lr
	.byte 0x00, 0x00
.L080F4100: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_080F4104
sub_080F4104: @ 0x080F4104
.L080F4104:
	push {lr}
	ldr r1, .L080F411C
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0
	strh r1, [r0, #0xe]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F411C: .4byte 0xFFFF8000

	thumb_func_start sub_080F4120
sub_080F4120: @ 0x080F4120
	push {lr}
	ldr r1, .L080F4138
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x80
	lsls r1, r1, #8
	strh r1, [r0, #0xe]
	pop {r0}
	bx r0
.L080F4138: .4byte 0xFFFF8000

	thumb_func_start sub_080F413C
sub_080F413C: @ 0x080F413C
.L080F413C:
	push {r4, lr}
	bl sub_080C0794
	cmp r0, #0
	bne .L080F414C
	movs r4, #0x19
	rsbs r4, r4, #0
	b .L080F4152
.L080F414C:
	cmp r0, #2
	bne .L080F4162
	movs r4, #0x19
.L080F4152:
	movs r0, #0
	adds r1, r4, #0
	bl sub_080C06EC
	movs r0, #1
	adds r1, r4, #0
	bl sub_080C06EC
.L080F4162:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4168
sub_080F4168: @ 0x080F4168
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_080F413C
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080C0248
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4190
sub_080F4190: @ 0x080F4190
.L080F4190:
	push {r4, lr}
	adds r4, r0, #0
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C0290
	movs r1, #0xb0
	lsls r1, r1, #8
	adds r0, r4, #0
	bl sub_080C08BC
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F41B0
sub_080F41B0: @ 0x080F41B0
.L080F41B0:
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl sub_080C0290
	adds r0, r5, #0
	bl sub_080F4104
	adds r0, r5, #0
	bl sub_080C0818
	lsls r0, r0, #0x10
	movs r4, #0x19
	cmp r0, #0
	beq .L080F41D4
	movs r4, #0x64
.L080F41D4:
	movs r0, #0
	adds r1, r4, #0
	bl sub_080C06EC
	movs r0, #1
	adds r1, r4, #0
	bl sub_080C06EC
	adds r0, r5, #0
	movs r1, #0
	bl sub_080C08F8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F41F4
sub_080F41F4: @ 0x080F41F4
.L080F41F4:
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L080F421C
	mov r0, sp
	movs r2, #4
	bl memcpy
	ldr r1, .L080F4220
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	cmp r4, #0
	bne .L080F4224
	movs r0, #0
	b .L080F4256
	.byte 0x00, 0x00
.L080F421C: .4byte gUnknown_0876F87C
.L080F4220: .4byte 0xFFFF8000
.L080F4224:
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #1
	adds r0, r2, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r1, r0
	cmp r0, #0
	bge .L080F4246
	adds r0, #7
.L080F4246:
	asrs r1, r0, #3
	mov r2, sp
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r1, r0
	ble .L080F4254
	adds r1, r0, #0
.L080F4254:
	adds r0, r1, #0
.L080F4256:
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F4260
sub_080F4260: @ 0x080F4260
.L080F4260:
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, .L080F42D8
	adds r0, r6, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	movs r2, #0
	adds r3, r4, #0
	adds r3, #0x5d
	movs r5, #0xff
	adds r7, r3, #0
.L080F427C:
	adds r1, r3, r2
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r2, #1
	cmp r2, #0x1f
	bls .L080F427C
	cmp r6, #0
	beq .L080F42D2
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r1, r0
	cmp r0, #0
	bge .L080F42B0
	adds r0, #7
.L080F42B0:
	asrs r3, r0, #3
	movs r2, #0
	adds r4, r7, #0
	ldr r5, .L080F42DC
.L080F42B8:
	adds r1, r4, r2
	adds r0, r2, r5
	ldrb r0, [r0]
	strb r0, [r1]
	cmp r0, #0xff
	beq .L080F42CC
	adds r2, #1
	subs r3, #1
	cmp r3, #0
	bne .L080F42B8
.L080F42CC:
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
.L080F42D2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F42D8: .4byte 0xFFFF8000
.L080F42DC: .4byte gUnknown_0876F880

	thumb_func_start sub_080F42E0
sub_080F42E0: @ 0x080F42E0
.L080F42E0:
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080F42FC
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x5d
	adds r0, r0, r4
	ldrb r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
.L080F42FC: .4byte 0xFFFF8000

	thumb_func_start sub_080F4300
sub_080F4300: @ 0x080F4300
.L080F4300:
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	movs r5, #0
	movs r4, #0
	cmp r6, #3
	ble .L080F4346
.L080F4310:
	adds r0, r6, #0
	adds r1, r5, #0
	bl sub_080F42E0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq .L080F4330
	cmp r0, #0x3f
	bhi .L080F4330
	bl sub_080ED6B8
	ands r0, r7
	cmp r0, #0
	beq .L080F4330
	adds r4, #1
.L080F4330:
	adds r5, #1
	cmp r5, #6
	ble .L080F4310
	b .L080F4356
.L080F4338:
	bl sub_080ED6B8
	ands r0, r7
	cmp r0, #0
	beq .L080F4344
	adds r4, #1
.L080F4344:
	adds r5, #1
.L080F4346:
	adds r0, r6, #0
	adds r1, r5, #0
	bl sub_080F42E0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne .L080F4338
.L080F4356:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F4360
sub_080F4360: @ 0x080F4360
.L080F4360:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #4
.L080F4368:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	ldrh r0, [r2, #0xe]
	cmp r0, #0
	beq .L080F4394
	movs r1, #0
	adds r2, #0x5d
.L080F4382:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, r5
	bne .L080F438E
	movs r0, #1
	b .L080F439C
.L080F438E:
	adds r1, #1
	cmp r1, #0x1f
	bls .L080F4382
.L080F4394:
	adds r4, #1
	cmp r4, #0xb
	bls .L080F4368
	movs r0, #0
.L080F439C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F43A4
sub_080F43A4: @ 0x080F43A4
.L080F43A4:
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	movs r4, #0
	ldr r7, .L080F43DC
.L080F43AE:
	adds r0, r4, r7
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L080F43CE
	adds r0, r1, #0
	adds r1, r6, #0
	bl sub_080C0E44
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r5
	ble .L080F43CE
	adds r5, r0, #0
.L080F43CE:
	adds r4, #1
	cmp r4, #5
	ble .L080F43AE
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080F43DC: .4byte 0x030050E0 @ IWRAM+0x50E0

	thumb_func_start sub_080F43E0
sub_080F43E0: @ 0x080F43E0
.L080F43E0:
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x10
	adds r1, r5, #0
	bl sub_080C0E44
	adds r4, r0, #0
	bl Battle_IsTwoSided
	cmp r0, #0
	beq .L080F4408
	movs r0, #0x14
	adds r1, r5, #0
	bl sub_080C0E44
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r4
	ble .L080F4408
	adds r4, r0, #0
.L080F4408:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080F4410
sub_080F4410: @ 0x080F4410
.L080F4410:
	push {r4, lr}
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	movs r1, #0xe0
	bl sub_080F4300
	cmp r0, #0
	bne .L080F4426
	movs r0, #0
	b .L080F443E
.L080F4426:
	adds r0, r4, #0
	bl sub_080C0818
	ldr r1, .L080F4438
	ands r1, r0
	cmp r1, #0
	bne .L080F443C
	movs r0, #2
	b .L080F443E
.L080F4438: .4byte 0x0000B063
.L080F443C:
	movs r0, #1
.L080F443E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080F4444
sub_080F4444: @ 0x080F4444
.L080F4444:
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	movs r4, #0
	movs r7, #1
	rsbs r7, r7, #0
.L080F444E:
	lsls r4, r4, #0x10
	asrs r0, r4, #0x10
	bl sub_080F40EC
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, r7
	beq .L080F4478
	cmp r5, #3
	bgt .L080F4468
	adds r0, r5, #0
	bl sub_080F4260
.L080F4468:
	adds r0, r5, #0
	bl sub_080F4410
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L080F4478
	movs r6, #1
.L080F4478:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble .L080F444E
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F4490
sub_080F4490: @ 0x080F4490
.L080F4490:
	push {r4, lr}
	movs r2, #0
	movs r1, #0
	ldr r4, .L080F44B4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
.L080F449C:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r3
	bne .L080F44B8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	b .L080F44D2
	.byte 0x00, 0x00
.L080F44B4: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080F44B8:
	lsls r0, r2, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble .L080F449C
	movs r0, #1
	rsbs r0, r0, #0
.L080F44D2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080F44D8
sub_080F44D8: @ 0x080F44D8
.L080F44D8:
	push {lr}
	adds r2, r0, #0
	adds r0, r1, #0
	ldr r3, .L080F4500
	subs r0, #0x10
	lsls r0, r0, #7
	adds r0, r0, r3
	movs r1, #0x9a
	lsls r1, r1, #4
	adds r0, r0, r1
	subs r2, #0x10
	lsls r2, r2, #7
	adds r2, r2, r3
	adds r2, r2, r1
	adds r1, r2, #0
	movs r2, #0x80
	bl memcpy
	pop {r0}
	bx r0
.L080F4500: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080F4504
sub_080F4504: @ 0x080F4504
.L080F4504:
	movs r0, #5
	bx lr

	thumb_func_start sub_080F4508
sub_080F4508: @ 0x080F4508
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F450C
sub_080F450C: @ 0x080F450C
.L080F450C:
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	bl sub_080C5D98
	adds r4, r0, #0
	ldrb r5, [r4, #2]
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq .L080F452A
	bl Flag_Test
	cmp r0, #0
	bne .L080F452A
	ldrb r5, [r4, #3]
.L080F452A:
	cmp r5, #0xff
	bne .L080F4536
	movs r0, #0
	str r0, [r6]
	str r0, [r7]
	b .L080F4540
.L080F4536:
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080ED35C
.L080F4540:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F4548
sub_080F4548: @ 0x080F4548
.L080F4548:
	push {lr}
	sub sp, #4
	adds r1, r0, #0
	cmp r1, #0x57
	bgt .L080F4556
	movs r0, #1
	b .L080F45CC
.L080F4556:
	cmp r1, #0x6f
	bgt .L080F455E
	movs r0, #2
	b .L080F45CC
.L080F455E:
	cmp r1, #0x7f
	bgt .L080F4566
	movs r0, #4
	b .L080F45CC
.L080F4566:
	cmp r1, #0x93
	bgt .L080F456E
	movs r0, #8
	b .L080F45CC
.L080F456E:
	cmp r1, #0xa7
	bgt .L080F4576
	movs r0, #0x10
	b .L080F45CC
.L080F4576:
	cmp r1, #0xbb
	bgt .L080F457E
	movs r0, #0x20
	b .L080F45CC
.L080F457E:
	cmp r1, #0xcf
	bgt .L080F4586
	movs r0, #0x40
	b .L080F45CC
.L080F4586:
	cmp r1, #0xfe
	bgt .L080F45B8
	adds r0, r1, #0
	movs r1, #0xa
	mov r2, sp
	bl Item_GetAttribute
	ldr r2, [sp]
	movs r1, #0xc0
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r1, r0, #0x1f
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	movs r0, #0x20
	ands r2, r0
	cmp r2, #0
	beq .L080F45B4
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r1, r0
.L080F45B4:
	adds r0, r1, #0
	b .L080F45CC
.L080F45B8:
	ldr r0, .L080F45C4
	cmp r1, r0
	ble .L080F45C8
	movs r0, #0x80
	b .L080F45CC
	.byte 0x00, 0x00
.L080F45C4: .4byte 0x0000011B
.L080F45C8:
	movs r0, #0x80
	lsls r0, r0, #1
.L080F45CC:
	add sp, #4
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080F45D4
sub_080F45D4: @ 0x080F45D4
.L080F45D4:
	push {r4, r5, lr}
	movs r5, #0
	movs r1, #0
.L080F45DA:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080F40EC
	cmp r0, #3
	ble .L080F45F2
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r5, r0, #0x10
.L080F45F2:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble .L080F45DA
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080F4608
sub_080F4608: @ 0x080F4608
.L080F4608:
	push {r4, r5, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r5, #5
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt .L080F4646
	cmp r0, #1
	beq .L080F4634
	cmp r0, #1
	bgt .L080F462A
	cmp r0, #0
	beq .L080F4634
	b .L080F4650
.L080F462A:
	cmp r0, #2
	beq .L080F463A
	cmp r0, #3
	beq .L080F4642
	b .L080F4650
.L080F4634:
	movs r2, #0x50
	movs r3, #0
	b .L080F4650
.L080F463A:
	movs r2, #0x58
	movs r5, #8
	movs r3, #0
	b .L080F4650
.L080F4642:
	movs r2, #0x5a
	b .L080F464E
.L080F4646:
	subs r0, #4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0x50
.L080F464E:
	movs r3, #0xf
.L080F4650:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	adds r3, r5, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	str r4, [sp]
	bl sub_080F4670
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4670
sub_080F4670: @ 0x080F4670
.L080F4670:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, [sp, #0x18]
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080F46AC
	ldr r1, .L080F46B0
	bl Task_Create
	adds r2, r0, #0
	adds r2, #0x24
	strh r4, [r2, #2]
	cmp r7, #3
	bne .L080F46B4
	lsls r1, r5, #0x10
	asrs r1, r1, #0xf
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	subs r0, r0, r1
	b .L080F46B6
.L080F46AC: .4byte gUnknown_0876F89C
.L080F46B0: .4byte 0x0000FFFF
.L080F46B4:
	movs r0, #0
.L080F46B6:
	strh r0, [r2, #4]
	strh r5, [r2]
	mov r0, r8
	strh r0, [r2, #0xa]
	strh r7, [r2, #6]
	strh r6, [r2, #8]
	ldr r0, .L080F46D8
	ldr r1, .L080F46DC
	movs r2, #0x80
	bl CpuFastSet
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F46D8: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080F46DC: .4byte 0x0203D600 @ EWRAM+0x3D600

	thumb_func_start sub_080F46E0
sub_080F46E0: @ 0x080F46E0
.L080F46E0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, [sp, #0x24]
	ldr r5, [sp, #0x28]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sb, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov ip, r5
	adds r5, r0, #0
	adds r4, r1, #0
	movs r6, #0
	cmp r6, r2
	bhs .L080F4774
	movs r0, #0xf8
	lsls r0, r0, #7
	mov sl, r0
.L080F4718:
	ldrh r1, [r5]
	adds r5, #2
	movs r3, #0x1f
	ands r3, r1
	adds r0, r1, #0
	movs r2, #0xf8
	lsls r2, r2, #2
	ands r0, r2
	lsrs r2, r0, #5
	mov r7, sl
	ands r1, r7
	lsrs r1, r1, #0xa
	mov r7, sb
	lsrs r0, r7, #3
	adds r3, r3, r0
	cmp r3, #0x1f
	bls .L080F473C
	movs r3, #0x1f
.L080F473C:
	mov r7, r8
	lsrs r0, r7, #3
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x1f
	bls .L080F474C
	movs r2, #0x1f
.L080F474C:
	mov r7, ip
	lsrs r0, r7, #3
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x1f
	bls .L080F475C
	movs r1, #0x1f
.L080F475C:
	lsls r0, r2, #5
	adds r0, r3, r0
	lsls r1, r1, #0xa
	adds r0, r0, r1
	strh r0, [r4]
	adds r4, #2
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, [sp]
	cmp r6, r0
	blo .L080F4718
.L080F4774:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4784
sub_080F4784: @ 0x080F4784
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r2, r0, #0
	adds r7, r2, #0
	adds r7, #0x24
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldrh r0, [r7, #0xa]
	subs r0, #1
	strh r0, [r7, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble .L080F47A4
	b .L080F4954
.L080F47A4:
	ldrh r0, [r2, #0x24]
	ldrh r1, [r7, #4]
	adds r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #8
	ldrsh r1, [r7, r3]
	cmp r0, r1
	blt .L080F47C0
	movs r4, #0x24
	ldrsh r0, [r2, r4]
	rsbs r0, r0, #0
	strh r0, [r2, #0x24]
.L080F47C0:
	movs r1, #4
	ldrsh r0, [r7, r1]
	ldrh r3, [r7, #4]
	cmp r0, #0
	bne .L080F47E8
	movs r0, #1
	strh r0, [r2, #0x1c]
	ldr r0, .L080F47E0
	ldr r1, .L080F47E4
	movs r2, #0x80
	bl CpuFastSet
	bl Palette_MarkDirty
	b .L080F4954
	.byte 0x00, 0x00
.L080F47E0: .4byte 0x0203D600 @ EWRAM+0x3D600
.L080F47E4: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080F47E8:
	movs r2, #6
	ldrsh r0, [r7, r2]
	cmp r0, #5
	bls .L080F47F2
	b .L080F4950
.L080F47F2:
	lsls r0, r0, #2
	ldr r1, .L080F47FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F47FC: .4byte gUnknown_080F4800
	.global gUnknown_080F4800
gUnknown_080F4800:
.L080F4800: @ jump table
	.4byte .L080F4818
	.4byte .L080F4838
	.4byte .L080F48E8
	.4byte .L080F4860
	.4byte .L080F4884
	.4byte .L080F48B8
.L080F4818:
	ldr r0, .L080F4830
	ldr r1, .L080F4834
	movs r3, #4
	ldrsh r2, [r7, r3]
	lsls r3, r2, #1
	adds r3, r3, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	b .L080F48D8
.L080F4830: .4byte 0x0203D700 @ EWRAM+0x3D700
.L080F4834: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080F4838:
	ldr r0, .L080F4858
	ldr r1, .L080F485C
	lsls r3, r3, #0x10
	asrs r3, r3, #0x12
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp]
	movs r2, #4
	ldrsh r4, [r7, r2]
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	b .L080F48D8
	.byte 0x00, 0x00
.L080F4858: .4byte 0x0203D700 @ EWRAM+0x3D700
.L080F485C: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080F4860:
	ldr r0, .L080F487C
	ldr r1, .L080F4880
	movs r4, #4
	ldrsh r3, [r7, r4]
	lsls r3, r3, #0x11
	lsrs r3, r3, #0x10
	str r3, [sp]
	movs r4, #4
	ldrsh r2, [r7, r4]
	lsls r2, r2, #0x11
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	b .L080F48D8
	.byte 0x00, 0x00
.L080F487C: .4byte 0x0203D700 @ EWRAM+0x3D700
.L080F4880: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080F4884:
	ldr r4, .L080F48B0
	ldr r5, .L080F48B4
	movs r1, #4
	ldrsh r0, [r7, r1]
	lsls r0, r0, #3
	movs r1, #0xa
	bl __divsi3
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0
	str r0, [sp]
	movs r2, #4
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L080F48D2
	.byte 0x00, 0x00
.L080F48B0: .4byte 0x0203D700 @ EWRAM+0x3D700
.L080F48B4: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080F48B8:
	ldr r4, .L080F48E0
	ldr r5, .L080F48E4
	movs r3, #4
	ldrsh r0, [r7, r3]
	lsls r0, r0, #3
	movs r1, #0xa
	bl __divsi3
	adds r3, r0, #0
	lsls r3, r3, #0x11
	lsrs r3, r3, #0x10
	str r3, [sp]
	movs r0, #0
.L080F48D2:
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
.L080F48D8:
	movs r2, #0x80
	bl sub_080F46E0
	b .L080F4950
.L080F48E0: .4byte 0x0203D700 @ EWRAM+0x3D700
.L080F48E4: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080F48E8:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x30
	bne .L080F490C
	ldr r0, .L080F4904
	ldr r1, .L080F4908
	movs r2, #0xa0
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x80
	movs r3, #0xa0
	bl sub_080F46E0
	b .L080F4950
.L080F4904: .4byte 0x0203D700 @ EWRAM+0x3D700
.L080F4908: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080F490C:
	ldr r6, .L080F4960
	ldr r4, .L080F4964
	mov r8, r4
	movs r0, #4
	ldrsh r4, [r7, r0]
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	movs r1, #0x34
	bl __divsi3
	adds r5, r0, #0
	lsls r5, r5, #0x11
	lsrs r5, r5, #0x10
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #1
	movs r1, #0x34
	bl __divsi3
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x10
	str r0, [sp]
	movs r1, #4
	ldrsh r0, [r7, r1]
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	adds r0, r6, #0
	mov r1, r8
	movs r2, #0x80
	adds r3, r5, #0
	bl sub_080F46E0
.L080F4950:
	bl Palette_MarkDirty
.L080F4954:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F4960: .4byte 0x0203D700 @ EWRAM+0x3D700
.L080F4964: .4byte 0x03002EB0 @ IWRAM+0x2EB0

	thumb_func_start sub_080F4968
sub_080F4968: @ 0x080F4968
.L080F4968:
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0
.L080F496E:
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080F497A
	adds r5, #1
.L080F497A:
	adds r4, #1
	cmp r4, #3
	ble .L080F496E
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080F4988
sub_080F4988: @ 0x080F4988
.L080F4988:
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	subs r3, #0x1d
	cmp r3, #0
	blt .L080F49AC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r2, #8]
	movs r0, #1
	str r0, [r2, #0xc]
	ldr r1, .L080F49B0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
.L080F49AC:
	pop {r0}
	bx r0
.L080F49B0: .4byte gUnknown_0876F940

	thumb_func_start sub_080F49B4
sub_080F49B4: @ 0x080F49B4
.L080F49B4:
	push {lr}
	movs r2, #1
	rsbs r2, r2, #0
	str r2, [r0, #8]
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r2, .L080F49D0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
.L080F49D0: .4byte gUnknown_0876F8C0

	thumb_func_start sub_080F49D4
sub_080F49D4: @ 0x080F49D4
.L080F49D4:
	push {lr}
	cmp r0, #0
	beq .L080F49E2
	movs r0, #0x96
	str r0, [r1, #8]
	movs r0, #0
	str r0, [r1, #0xc]
.L080F49E2:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F49E8
sub_080F49E8: @ 0x080F49E8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	ldr r0, [r4, #4]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_080EFD14
	adds r1, r4, #0
	bl sub_080F49D4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4A10
sub_080F4A10: @ 0x080F4A10
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	ldr r0, [r4, #4]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_080EFD5C
	adds r1, r4, #0
	bl sub_080F49D4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4A38
sub_080F4A38: @ 0x080F4A38
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	ldr r0, [r4, #4]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_080EFDA4
	adds r1, r4, #0
	bl sub_080F49D4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4A60
sub_080F4A60: @ 0x080F4A60
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r5, #0
	ldr r4, [r0, #4]
	cmp r4, #0xf
	bgt .L080F4AE4
	movs r6, #0
	ldr r0, .L080F4AE0
	mov r8, r0
	movs r7, #1
	rsbs r7, r7, #0
.L080F4A7C:
	mov r0, r8
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r7
	beq .L080F4AD8
	adds r4, r0, #0
	bl sub_080EFBFC
	cmp r0, #0
	ble .L080F4A9C
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFD28
.L080F4A9C:
	adds r0, r4, #0
	bl sub_080EFD3C
	cmp r0, #0
	ble .L080F4AB0
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFD70
.L080F4AB0:
	adds r0, r4, #0
	bl sub_080EFD84
	cmp r0, #0
	ble .L080F4AC4
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFDB8
.L080F4AC4:
	adds r0, r4, #0
	bl sub_080EFDCC
	cmp r0, #0
	ble .L080F4AD8
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFDEC
.L080F4AD8:
	adds r6, #1
	cmp r6, #5
	ble .L080F4A7C
	b .L080F4B40
.L080F4AE0: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080F4AE4:
	movs r6, #0
.L080F4AE6:
	adds r4, r6, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl sub_080EFBFC
	cmp r0, #0
	ble .L080F4AFE
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFD28
.L080F4AFE:
	adds r0, r4, #0
	bl sub_080EFD3C
	cmp r0, #0
	ble .L080F4B12
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFD70
.L080F4B12:
	adds r0, r4, #0
	bl sub_080EFD84
	cmp r0, #0
	ble .L080F4B26
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFDB8
.L080F4B26:
	adds r0, r4, #0
	bl sub_080EFDCC
	cmp r0, #0
	ble .L080F4B3A
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFE00
.L080F4B3A:
	adds r6, #1
	cmp r6, #7
	ble .L080F4AE6
.L080F4B40:
	cmp r5, #0
	bne .L080F4B48
	mov r0, sb
	str r5, [r0, #0xc]
.L080F4B48:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4B54
sub_080F4B54: @ 0x080F4B54
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r5, #0
	ldr r4, [r0]
	cmp r4, #0xf
	bgt .L080F4BC4
	movs r6, #0
	ldr r0, .L080F4BC0
	mov r8, r0
	movs r7, #1
	rsbs r7, r7, #0
.L080F4B70:
	mov r0, r8
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r7
	beq .L080F4BB8
	adds r4, r0, #0
	bl sub_080EFBFC
	cmp r0, #0
	bge .L080F4B90
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFD28
.L080F4B90:
	adds r0, r4, #0
	bl sub_080EFD3C
	cmp r0, #0
	bge .L080F4BA4
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFD70
.L080F4BA4:
	adds r0, r4, #0
	bl sub_080EFD84
	cmp r0, #0
	bge .L080F4BB8
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFDB8
.L080F4BB8:
	adds r6, #1
	cmp r6, #5
	ble .L080F4B70
	b .L080F4C0C
.L080F4BC0: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080F4BC4:
	movs r6, #0
.L080F4BC6:
	adds r4, r6, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl sub_080EFBFC
	cmp r0, #0
	bge .L080F4BDE
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFD28
.L080F4BDE:
	adds r0, r4, #0
	bl sub_080EFD3C
	cmp r0, #0
	bge .L080F4BF2
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFD70
.L080F4BF2:
	adds r0, r4, #0
	bl sub_080EFD84
	cmp r0, #0
	bge .L080F4C06
	adds r5, #1
	rsbs r1, r0, #0
	adds r0, r4, #0
	bl sub_080EFDB8
.L080F4C06:
	adds r6, #1
	cmp r6, #7
	ble .L080F4BC6
.L080F4C0C:
	cmp r5, #0
	bne .L080F4C14
	mov r0, sb
	str r5, [r0, #0xc]
.L080F4C14:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4C20
sub_080F4C20: @ 0x080F4C20
	push {lr}
	movs r2, #0xcc
	lsls r2, r2, #2
	movs r1, #0x20
	bl sub_080F4C90
	pop {r0}
	bx r0

	thumb_func_start sub_080F4C30
sub_080F4C30: @ 0x080F4C30
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #1
	bl sub_080EFD14
	adds r1, r4, #0
	bl sub_080F49D4
	pop {r4}
	pop {r0}
	bx r0
