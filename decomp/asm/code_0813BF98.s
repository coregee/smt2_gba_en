	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start ScriptOp_447
ScriptOp_447: @ 0x0813BF98
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
	ldr r3, .L0813BFE8
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813BFEC
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r5, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r4, [r1]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r8, r0
	lsls r0, r0, #0x10
	orrs r0, r4
	mov r8, r0
	cmp r5, #0
	bne .L0813BFF8
	ldr r0, .L0813BFF0
	ldr r1, .L0813BFF4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0813BFE6
	b .L0813C4DE
.L0813BFE6:
	b .L0813C4C0
.L0813BFE8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813BFEC: .4byte 0x03006950 @ IWRAM+0x6950
.L0813BFF0: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813BFF4: .4byte 0x0203DB7E @ EWRAM+0x3DB7E
.L0813BFF8:
	cmp r5, #1
	bne .L0813C054
	ldr r4, .L0813C03C
	ldrh r0, [r4]
	bl sub_0815B9DC
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0x1a
	bls .L0813C00E
	b .L0813C4CC
.L0813C00E:
	ldrh r0, [r4]
	movs r1, #0xb
	bl Demon_GetField
	movs r4, #0xff
	adds r6, r4, #0
	ands r6, r0
	cmp r6, #0x6f
	bls .L0813C040
	cmp r6, #0x8f
	bhi .L0813C026
	b .L0813C4DE
.L0813C026:
	movs r0, #0
	bl sub_080C0794
	lsls r0, r0, #8
	lsrs r5, r0, #0x10
	ands r5, r4
	cmp r5, #0x6f
	bhi .L0813C038
	b .L0813C4CC
.L0813C038:
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C03C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C040:
	movs r0, #0
	bl sub_080C0794
	lsls r0, r0, #8
	lsrs r5, r0, #0x10
	ands r5, r4
	cmp r5, #0x8f
	bhi .L0813C052
	b .L0813C4DE
.L0813C052:
	b .L0813C4CC
.L0813C054:
	cmp r5, #2
	bne .L0813C088
	bl Stock_GetCapacity
	adds r4, r0, #0
	ldr r0, .L0813C084
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0813C068
	b .L0813C4DE
.L0813C068:
	movs r6, #0
	cmp r7, r4
	blt .L0813C070
	b .L0813C4C0
.L0813C070:
	adds r0, r6, #4
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L0813C07C
	b .L0813C4DE
.L0813C07C:
	adds r6, #1
	cmp r6, r4
	blt .L0813C070
	b .L0813C4C0
.L0813C084: .4byte 0x0203DB86 @ EWRAM+0x3DB86
.L0813C088:
	cmp r5, #3
	bne .L0813C0B0
	ldr r0, .L0813C0A8
	ldrb r5, [r0]
	cmp r5, #0x8f
	bls .L0813C096
	b .L0813C4DE
.L0813C096:
	ldr r0, .L0813C0AC
	ldrh r0, [r0]
	bl sub_0813E804
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813C0A6
	b .L0813C4DE
.L0813C0A6:
	b .L0813C4CC
.L0813C0A8: .4byte 0x0300685C @ IWRAM+0x685C
.L0813C0AC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C0B0:
	cmp r5, #4
	bne .L0813C10C
	movs r6, #0x10
.L0813C0B6:
	adds r0, r6, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C0FA
	adds r0, r6, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L0813C104
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0813C0FA
	ldr r0, .L0813C108
	adds r4, r6, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	ldrh r0, [r0, #0x1a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt .L0813C0FA
	b .L0813C4C0
.L0813C0FA:
	adds r6, #1
	cmp r6, #0x17
	ble .L0813C0B6
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C104: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C108: .4byte 0xFFFF8000
.L0813C10C:
	cmp r5, #5
	bne .L0813C154
	movs r6, #0x10
.L0813C112:
	adds r0, r6, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C146
	adds r0, r6, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L0813C150
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0813C146
	adds r0, r6, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	ands r1, r0
	cmp r1, #0
	beq .L0813C146
	b .L0813C4CC
.L0813C146:
	adds r6, #1
	cmp r6, #0x17
	ble .L0813C112
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C150: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C154:
	cmp r5, #6
	bne .L0813C19A
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C178
	movs r0, #1
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	movs r1, #0xa0
	lsls r1, r1, #0x18
	ands r1, r0
	cmp r1, #0
	beq .L0813C176
	b .L0813C4DE
.L0813C176:
	b .L0813C4C0
.L0813C178:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L0813C184
	b .L0813C4C0
.L0813C184:
	movs r0, #2
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	movs r1, #0xa0
	lsls r1, r1, #0x18
	ands r1, r0
	cmp r1, #0
	beq .L0813C198
	b .L0813C4DE
.L0813C198:
	b .L0813C4CC
.L0813C19A:
	cmp r5, #7
	bne .L0813C1AC
	bl sub_0813BF58
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813C1AA
	b .L0813C4DE
.L0813C1AA:
	b .L0813C4CC
.L0813C1AC:
	cmp r5, #8
	bne .L0813C1BE
	bl sub_0813BF78
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813C1BC
	b .L0813C4DE
.L0813C1BC:
	b .L0813C4C0
.L0813C1BE:
	cmp r5, #9
	bne .L0813C22C
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C1D0
	movs r6, #1
	b .L0813C1DE
.L0813C1D0:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L0813C1DC
	b .L0813C4DE
.L0813C1DC:
	movs r6, #2
.L0813C1DE:
	adds r0, r6, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #4
	ands r1, r0
	cmp r1, #0
	beq .L0813C1F6
	movs r6, #1
	b .L0813C204
.L0813C1F6:
	adds r0, r6, #0
	movs r1, #2
	bl Combatant_GetStat
	adds r6, r0, #0
	movs r0, #0xff
	ands r6, r0
.L0813C204:
	bl Random_Byte
	adds r5, r0, #0
	movs r0, #0xf
	ands r5, r0
	ldr r0, .L0813C228
	ldrh r0, [r0]
	movs r1, #7
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	adds r5, r5, r1
	cmp r5, r6
	bhs .L0813C224
	b .L0813C4DE
.L0813C224:
	b .L0813C4CC
	.byte 0x00, 0x00
.L0813C228: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C22C:
	cmp r5, #0xa
	bne .L0813C254
	bl sub_0812A640
	ldr r1, .L0813C248
	str r0, [r1]
	ldr r0, .L0813C24C
	mov r1, r8
	str r1, [r0]
	ldr r1, .L0813C250
	movs r0, #0x4e
	strh r0, [r1]
	b .L0813C32E
	.byte 0x00, 0x00
.L0813C248: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813C24C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813C250: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813C254:
	cmp r5, #0xb
	bne .L0813C2EA
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C266
	movs r6, #1
	b .L0813C274
.L0813C266:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L0813C272
	b .L0813C4C0
.L0813C272:
	movs r6, #2
.L0813C274:
	adds r0, r6, #0
	bl Combatant_GetStatus
	movs r1, #0xc0
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L0813C286
	b .L0813C4C0
.L0813C286:
	movs r6, #0x10
.L0813C288:
	adds r0, r6, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C2D0
	ldr r0, .L0813C2DC
	ldrh r4, [r0]
	adds r0, r6, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	bne .L0813C2D0
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r6, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0x1a
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge .L0813C2BE
	adds r0, #3
.L0813C2BE:
	lsls r0, r0, #0xe
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r2, #0x18
	ldrsh r0, [r0, r2]
	cmp r5, r0
	bge .L0813C2E0
.L0813C2D0:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0x17
	bls .L0813C288
	b .L0813C4C0
.L0813C2DC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C2E0:
	bl Random_Byte
	movs r1, #3
	ands r0, r1
	b .L0813C316
.L0813C2EA:
	cmp r5, #0xc
	bne .L0813C31E
	movs r1, #0xb
.L0813C2F0:
	lsls r4, r1, #0x10
	lsrs r0, r4, #0x10
	bl sub_0813756C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0813C310
	ldr r2, .L0813C30C
	adds r0, r4, r2
	lsrs r1, r0, #0x10
	cmp r0, #0
	bge .L0813C2F0
	b .L0813C4C0
	.byte 0x00, 0x00
.L0813C30C: .4byte 0xFFFF0000
.L0813C310:
	bl sub_0813BD58
	lsls r0, r0, #0x10
.L0813C316:
	cmp r0, #0
	bne .L0813C31C
	b .L0813C4DE
.L0813C31C:
	b .L0813C4C0
.L0813C31E:
	cmp r5, #0xd
	bne .L0813C340
	ldr r0, .L0813C338
	mov r2, r8
	str r2, [r0]
	movs r0, #1
	bl sub_0813BECC
.L0813C32E:
	ldr r1, .L0813C33C
	movs r0, #1
	strh r0, [r1]
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C338: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813C33C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L0813C340:
	cmp r5, #0xe
	bne .L0813C38C
	bl sub_0813BD58
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r7, r5, #0
	cmp r7, #1
	beq .L0813C354
	b .L0813C4C0
.L0813C354:
	bl sub_0813BDA4
	bl sub_0813BDCC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xc
	ldr r1, .L0813C384
	ldrh r4, [r1]
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsrs r5, r4, #2
	adds r0, r6, r5
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L0813C388
	ldrb r0, [r0]
	ands r7, r0
	cmp r7, #0
	beq .L0813C3E0
	b .L0813C3DC
	.byte 0x00, 0x00
.L0813C384: .4byte 0x03006690 @ IWRAM+0x6690
.L0813C388: .4byte 0x0300684C @ IWRAM+0x684C
.L0813C38C:
	cmp r5, #0xf
	bne .L0813C39C
	bl Money_Pay
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813C402
	b .L0813C4CC
.L0813C39C:
	cmp r5, #0x10
	bne .L0813C3F4
	bl sub_0813BD58
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #2
	beq .L0813C3AE
	b .L0813C4C0
.L0813C3AE:
	bl sub_0813BDA4
	bl sub_08137BB8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xc
	ldr r1, .L0813C3E8
	ldrh r4, [r1]
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsrs r5, r4, #2
	adds r0, r6, r5
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L0813C3EC
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0813C3E0
.L0813C3DC:
	lsls r0, r6, #0x11
	lsrs r6, r0, #0x10
.L0813C3E0:
	ldr r0, .L0813C3F0
	str r6, [r0]
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C3E8: .4byte 0x03006690 @ IWRAM+0x6690
.L0813C3EC: .4byte 0x0300684C @ IWRAM+0x684C
.L0813C3F0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813C3F4:
	cmp r5, #0x11
	bne .L0813C418
	bl Magnetite_Pay
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813C4CC
.L0813C402:
	ldr r0, .L0813C414
	ldrb r1, [r0]
	movs r2, #0x40
	orrs r1, r2
	strb r1, [r0]
	bl sub_0813BE98
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C414: .4byte 0x0300684C @ IWRAM+0x684C
.L0813C418:
	cmp r5, #0x12
	bne .L0813C440
	ldr r4, .L0813C43C
	movs r0, #0xe5
	strh r0, [r4]
	movs r0, #0xe5
	bl Inventory_GetCount
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0813C4C0
	ldrh r0, [r4]
	bl Inventory_RemoveItem
	bl sub_0813BEB8
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C43C: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813C440:
	cmp r5, #0x13
	bne .L0813C470
	ldr r0, .L0813C46C
	ldrh r0, [r0]
	movs r1, #0x1b
	bl Demon_GetField
	lsls r0, r0, #0x10
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r1, r0
	lsrs r7, r1, #0x11
	adds r7, #1
	bl Magnetite_Get
	cmp r0, r7
	blo .L0813C4CC
	rsbs r0, r7, #0
	bl Magnetite_Add
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C46C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C470:
	cmp r5, #0x14
	beq .L0813C4A0
	cmp r5, #0x15
	bne .L0813C4DE
	ldr r0, .L0813C49C
	mov r2, r8
	str r2, [r0]
	movs r0, #0xe5
	bl Flag_Test
	cmp r0, #0
	beq .L0813C4D8
	movs r0, #0
	bl sub_0812A668
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813C4D8
	movs r0, #0x2d
	bl Script_JumpToStatusMessage
	b .L0813C4DE
.L0813C49C: .4byte 0x03006840 @ IWRAM+0x6840
.L0813C4A0:
	movs r0, #0
	movs r1, #1
	bl Combatant_GetEquip
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xff
	beq .L0813C4C0
	movs r0, #0
	movs r1, #6
	bl Combatant_GetEquip
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xff
	bne .L0813C4DE
.L0813C4C0:
	ldr r0, .L0813C4C8
	mov r1, r8
	str r1, [r0]
	b .L0813C4DE
.L0813C4C8: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813C4CC:
	ldr r0, .L0813C4D4
	mov r2, r8
	str r2, [r0]
	b .L0813C4DE
.L0813C4D4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813C4D8:
	movs r0, #0x2e
	bl Script_JumpToStatusMessage
.L0813C4DE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
