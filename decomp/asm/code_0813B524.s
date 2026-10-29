	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start ScriptOp_445
ScriptOp_445: @ 0x0813B524
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r2, .L0813B5AC
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L0813B5B0
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #3
	bne .L0813B5CA
	bl Stock_GetCapacity
	adds r7, r0, #0
	movs r6, #4
	adds r0, r7, #4
	cmp r6, r0
	blt .L0813B550
	b .L0813BC20
.L0813B550:
	adds r0, r6, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813B5BC
	adds r0, r6, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L0813B5B4
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0813B5BC
	adds r0, r6, #0
	bl Combatant_GetStatus
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0813B580
	b .L0813BBEA
.L0813B580:
	ldr r1, .L0813B5B8
	lsls r0, r6, #7
	adds r4, r0, r1
	movs r3, #0x1a
	ldrsh r0, [r4, r3]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	movs r2, #0x18
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt .L0813B59A
	b .L0813BC20
.L0813B59A:
	adds r0, r6, #0
	movs r1, #1
	bl Combatant_ClearStatus
	ldrh r0, [r4, #0x1a]
	strh r0, [r4, #0x18]
.L0813B5A6:
	bl sub_080C84A0
	b .L0813BC20
.L0813B5AC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813B5B0: .4byte 0x03006950 @ IWRAM+0x6950
.L0813B5B4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B5B8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B5BC:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r7, #4
	cmp r6, r0
	blt .L0813B550
	b .L0813BC20
.L0813B5CA:
	cmp r1, #4
	bne .L0813B5E8
	movs r0, #0
	movs r1, #0
	bl sub_0812EE8C
	ldr r1, .L0813B5E0
	str r0, [r1]
	ldr r1, .L0813B5E4
	movs r0, #0x4f
	b .L0813BA0E
.L0813B5E0: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813B5E4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813B5E8:
	cmp r1, #5
	beq .L0813B5A6
	cmp r1, #6
	bne .L0813B600
	movs r0, #0
	movs r1, #1
	bl Combatant_ClearStatus
	movs r0, #0
	bl Combatant_RestoreHp
	b .L0813B5A6
.L0813B600:
	cmp r1, #7
	bne .L0813B620
	bl sub_080EF954
	adds r2, r0, #0
	bl sub_080EF930
	ldr r0, .L0813B618
	ldr r1, .L0813B61C
	ldrb r1, [r1]
	strb r1, [r0]
	b .L0813BC20
.L0813B618: .4byte 0x030068B4 @ IWRAM+0x68B4
.L0813B61C: .4byte 0x030069E8 @ IWRAM+0x69E8
.L0813B620:
	cmp r1, #8
	bne .L0813B658
	ldr r0, .L0813B650
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	ldr r2, .L0813B654
	ldrh r0, [r2, #0x18]
	subs r0, r0, r1
	strh r0, [r2, #0x18]
	movs r3, #0x18
	ldrsh r0, [r2, r3]
	subs r0, #1
	lsls r0, r0, #0x10
	cmp r0, #0
	ble .L0813B648
	b .L0813BC20
.L0813B648:
	movs r0, #1
	strh r0, [r2, #0x18]
	b .L0813BC20
	.byte 0x00, 0x00
.L0813B650: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B654: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B658:
	cmp r1, #9
	bne .L0813B694
	bl Random_Byte
	movs r1, #7
	ands r0, r1
	adds r5, r0, #1
	ldr r0, .L0813B68C
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	adds r0, r5, r0
	lsls r0, r0, #0x10
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r1, r0
	lsrs r5, r1, #0x10
	ldr r1, .L0813B690
	ldrh r0, [r1, #0x18]
	subs r0, r0, r5
	strh r0, [r1, #0x18]
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	b .L0813B6B4
	.byte 0x00, 0x00
.L0813B68C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B690: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B694:
	cmp r1, #0xa
	bne .L0813B6CC
	ldr r0, .L0813B6C4
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	lsls r5, r1, #1
	ldr r1, .L0813B6C8
	ldrh r0, [r1, #0x18]
	subs r0, r0, r5
	strh r0, [r1, #0x18]
	movs r3, #0x18
	ldrsh r0, [r1, r3]
.L0813B6B4:
	subs r0, #1
	lsls r0, r0, #0x10
	cmp r0, #0
	ble .L0813B6BE
	b .L0813BC20
.L0813B6BE:
	movs r0, #1
	strh r0, [r1, #0x18]
	b .L0813BC20
.L0813B6C4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B6C8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B6CC:
	cmp r1, #0xb
	bne .L0813B724
	ldr r0, .L0813B6F0
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	lsrs r1, r1, #2
	adds r5, r1, #1
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813B6F4
	movs r6, #1
	b .L0813B702
.L0813B6F0: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B6F4:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L0813B700
	b .L0813BC20
.L0813B700:
	movs r6, #2
.L0813B702:
	ldr r1, .L0813B720
	lsls r0, r6, #7
	adds r1, r0, r1
	ldrh r0, [r1, #0x1c]
	subs r0, r0, r5
	strh r0, [r1, #0x1c]
	movs r2, #0x1c
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble .L0813B718
	b .L0813B5A6
.L0813B718:
	movs r0, #0
	strh r0, [r1, #0x1c]
	b .L0813B5A6
	.byte 0x00, 0x00
.L0813B720: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B724:
	cmp r1, #0xc
	bne .L0813B740
	ldr r2, .L0813B738
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L0813B73C
	movs r0, #0xf7
	b .L0813B752
.L0813B738: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B73C:
	movs r0, #8
	b .L0813B75E
.L0813B740:
	cmp r1, #0xd
	bne .L0813B764
	ldr r2, .L0813B758
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L0813B75C
	movs r0, #0xef
.L0813B752:
	ands r0, r1
	strb r0, [r2]
	b .L0813BC20
.L0813B758: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B75C:
	movs r0, #0x10
.L0813B75E:
	orrs r0, r1
	strb r0, [r2]
	b .L0813BC20
.L0813B764:
	cmp r1, #0xe
	bne .L0813B774
	ldr r0, .L0813B770
	ldrb r1, [r0]
	movs r2, #1
	b .L0813B78E
.L0813B770: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B774:
	cmp r1, #0xf
	bne .L0813B784
	ldr r0, .L0813B780
	ldrb r1, [r0]
	movs r2, #4
	b .L0813B78E
.L0813B780: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B784:
	cmp r1, #0x10
	bne .L0813B798
	ldr r0, .L0813B794
	ldrb r1, [r0]
	movs r2, #2
.L0813B78E:
	orrs r1, r2
	strb r1, [r0]
	b .L0813BC20
.L0813B794: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B798:
	cmp r1, #0x11
	bne .L0813B7EA
	bl Stock_GetCapacity
	adds r7, r0, #0
	movs r6, #0
	adds r0, r7, #4
	cmp r6, r0
	blt .L0813B7AC
	b .L0813BC20
.L0813B7AC:
	adds r0, r6, #0
	bl Combatant_IsAlive
	cmp r0, #1
	bne .L0813B7DC
	movs r3, #0x80
	lsls r3, r3, #8
	adds r4, r6, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	adds r5, r0, #0
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r2, #0x18
	ldrsh r1, [r5, r2]
	movs r3, #0x1a
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge .L0813B7DC
	b .L0813BC04
.L0813B7DC:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r7, #4
	cmp r6, r0
	blt .L0813B7AC
	b .L0813BC20
.L0813B7EA:
	cmp r1, #0x12
	bne .L0813B844
	ldr r4, .L0813B838
	ldr r0, .L0813B83C
	ldrh r0, [r0]
	movs r1, #5
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	str r1, [r4]
	movs r0, #0x41
	bl sub_08132350
	movs r1, #0
	ldr r0, .L0813B840
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r2, r0, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq .L0813B82E
.L0813B818:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #4
	bhi .L0813B82E
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0813B818
.L0813B82E:
	adds r0, r1, #0
	movs r1, #1
	bl sub_080C8890
	b .L0813BA10
.L0813B838: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813B83C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B840: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B844:
	cmp r1, #0x13
	bne .L0813B868
	movs r0, #0x16
	bl sub_08132350
	movs r0, #0x1f
	movs r1, #1
	bl sub_080B8AE0
	ldr r1, .L0813B860
	str r0, [r1]
	ldr r1, .L0813B864
	movs r0, #0x4c
	b .L0813BA0E
.L0813B860: .4byte 0x03006964 @ IWRAM+0x6964
.L0813B864: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813B868:
	cmp r1, #0x14
	bne .L0813B874
	movs r0, #0x39
	bl sub_08132350
	b .L0813BC20
.L0813B874:
	cmp r1, #0x15
	bne .L0813B8E4
	movs r0, #0x40
	bl sub_08132350
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r2, #0x18
	ldrsh r1, [r0, r2]
	ldr r5, .L0813B8E0
	ldr r0, [r5]
	cmp r1, r0
	bhs .L0813B8A2
	adds r0, r4, #0
	bl Battle_GetCombatant
	ldr r2, [r5]
	ldrh r1, [r0, #0x18]
	subs r1, r1, r2
	strh r1, [r0, #0x18]
.L0813B8A2:
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r3, #0x18
	ldrsh r0, [r0, r3]
	ands r0, r4
	cmp r0, #0
	bne .L0813B8C2
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble .L0813B8C2
	b .L0813BC20
.L0813B8C2:
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0
	strh r1, [r0, #0x18]
	movs r0, #0
	movs r1, #1
	bl Combatant_ClearStatus
	movs r0, #0
	adds r1, r4, #0
	bl sub_080C08E8
	b .L0813B980
	.byte 0x00, 0x00
.L0813B8E0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813B8E4:
	cmp r1, #0x17
	bne .L0813B92C
	bl sub_0813B400
	bl sub_0813BE70
	ldr r2, .L0813B918
	ldrb r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r0, .L0813B91C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813B920
	strh r1, [r0]
	ldr r0, .L0813B924
	strh r1, [r0]
	ldr r0, .L0813B928
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	b .L0813BC20
	.byte 0x00, 0x00
.L0813B918: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B91C: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813B920: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813B924: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813B928: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0813B92C:
	cmp r1, #0x18
	bne .L0813B97C
	ldr r0, .L0813B96C
	ldrh r0, [r0]
	subs r0, #0x9d
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_0812F188
	rsbs r0, r0, #0
	bl Money_Add
	bl Moon_GetPhase
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x80
	beq .L0813B956
	movs r0, #0xcf
	bl Flag_Set
.L0813B956:
	ldr r0, .L0813B970
	ldrh r4, [r0]
	adds r0, r4, #0
	bl sub_0813B438
	cmp r4, #0
	bne .L0813B974
	movs r0, #0xe2
	bl Flag_Set
	b .L0813BC20
.L0813B96C: .4byte 0x030065E0 @ IWRAM+0x65E0
.L0813B970: .4byte 0x03006898 @ IWRAM+0x6898
.L0813B974:
	movs r0, #0xe3
	bl Flag_Set
	b .L0813BC20
.L0813B97C:
	cmp r1, #0x19
	bne .L0813B992
.L0813B980:
	bl sub_08138CE8
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813B98C
	b .L0813BC20
.L0813B98C:
	movs r0, #1
	strh r0, [r6, #0x1c]
	b .L0813BC20
.L0813B992:
	cmp r1, #0x1a
	bne .L0813B9D4
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r2, #0x18
	ldrsh r1, [r0, r2]
	ldr r5, .L0813B9C0
	ldr r0, [r5]
	cmp r1, r0
	bhi .L0813B9C4
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0
	strh r1, [r0, #0x18]
	movs r0, #0
	adds r1, r4, #0
	bl sub_080C08E8
	b .L0813B5A6
.L0813B9C0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813B9C4:
	adds r0, r4, #0
	bl Battle_GetCombatant
	ldr r2, [r5]
	ldrh r1, [r0, #0x18]
	subs r1, r1, r2
	strh r1, [r0, #0x18]
	b .L0813B5A6
.L0813B9D4:
	cmp r1, #0x1b
	bne .L0813B9EC
	ldr r0, .L0813B9E4
	ldr r1, .L0813B9E8
	ldrh r1, [r1]
	strh r1, [r0]
	b .L0813BC20
	.byte 0x00, 0x00
.L0813B9E4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B9E8: .4byte 0x0203DB80 @ EWRAM+0x3DB80
.L0813B9EC:
	cmp r1, #0x1c
	bne .L0813B9F8
	movs r0, #1
	bl sub_080D3AA0
	b .L0813BC20
.L0813B9F8:
	cmp r1, #0x1d
	bne .L0813BA00
	movs r0, #0
	b .L0813BA06
.L0813BA00:
	cmp r1, #0x1e
	bne .L0813BA20
	movs r0, #1
.L0813BA06:
	bl sub_080D4560
	ldr r1, .L0813BA18
	movs r0, #0x52
.L0813BA0E:
	strh r0, [r1]
.L0813BA10:
	ldr r1, .L0813BA1C
	movs r0, #1
	strh r0, [r1]
	b .L0813BC20
.L0813BA18: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813BA1C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L0813BA20:
	cmp r1, #0x1f
	bne .L0813BA30
	ldr r1, .L0813BA2C
	movs r0, #0
	strh r0, [r1, #2]
	b .L0813BC20
.L0813BA2C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA30:
	cmp r1, #0x20
	bne .L0813BA40
	ldr r1, .L0813BA3C
	movs r0, #1
	strh r0, [r1, #2]
	b .L0813BC20
.L0813BA3C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA40:
	cmp r1, #0x21
	bne .L0813BA50
	ldr r1, .L0813BA4C
	movs r0, #2
	strh r0, [r1, #2]
	b .L0813BC20
.L0813BA4C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA50:
	cmp r1, #0x22
	bne .L0813BA60
	ldr r1, .L0813BA5C
	movs r0, #0
	strh r0, [r1]
	b .L0813BC20
.L0813BA5C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA60:
	cmp r1, #0x23
	bne .L0813BA70
	ldr r1, .L0813BA6C
	movs r0, #1
	strh r0, [r1]
	b .L0813BC20
.L0813BA6C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA70:
	cmp r1, #0x24
	bne .L0813BA80
	ldr r1, .L0813BA7C
	movs r0, #2
	strh r0, [r1]
	b .L0813BC20
.L0813BA7C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA80:
	cmp r1, #0x25
	bne .L0813BAA0
	ldr r1, .L0813BA9C
	movs r0, #0
	strh r0, [r1, #4]
	movs r0, #0xff
	strh r0, [r1, #6]
	ldrh r0, [r1]
	cmp r0, #1
	beq .L0813BA96
	b .L0813BC20
.L0813BA96:
	bl Party_SaveOrderHeroOnly
	b .L0813BC20
.L0813BA9C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BAA0:
	cmp r1, #0x26
	bne .L0813BABC
	ldr r0, .L0813BAB4
	ldrh r1, [r0, #4]
	adds r1, #1
	strh r1, [r0, #4]
	ldrh r1, [r0, #4]
	ldr r0, .L0813BAB8
	str r1, [r0]
	b .L0813BC20
.L0813BAB4: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BAB8: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813BABC:
	cmp r1, #0x27
	bne .L0813BAD4
	ldr r0, .L0813BAD0
	ldrh r0, [r0]
	cmp r0, #1
	beq .L0813BACA
	b .L0813BC20
.L0813BACA:
	bl Party_RestoreOrder
	b .L0813BC20
.L0813BAD0: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BAD4:
	cmp r1, #0x28
	beq .L0813BADA
	b .L0813BC20
.L0813BADA:
	movs r0, #0
	bl Combatant_GetLevel
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #6
	bhi .L0813BAEA
	b .L0813BC20
.L0813BAEA:
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0
	adds r1, r4, #0
	bl Combatant_SetLevel
	adds r0, r4, #0
	bl Exp_GetForLevel
	adds r1, r0, #0
	movs r0, #0
	bl sub_080C0F70
	bl Random_Byte
	adds r6, r0, #0
	movs r0, #3
	ands r6, r0
	bl Random_Byte
	movs r4, #1
	ands r0, r4
	adds r6, r6, r0
	bl Random_Byte
	ands r0, r4
	adds r6, r6, r0
	movs r5, #0
.L0813BB24:
	cmp r6, #0
	bne .L0813BB46
	movs r0, #0
	movs r1, #0
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #6
	bgt .L0813BB3A
	movs r6, #1
	b .L0813BBDE
.L0813BB3A:
	subs r2, #1
	movs r0, #0
	movs r1, #0
	bl sub_08136204
	b .L0813BC16
.L0813BB46:
	cmp r6, #1
	bne .L0813BB68
	movs r0, #0
	movs r1, #1
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #5
	bgt .L0813BB5C
	movs r6, #2
	b .L0813BBDE
.L0813BB5C:
	subs r2, #1
	movs r0, #0
	movs r1, #1
	bl sub_08136204
	b .L0813BC16
.L0813BB68:
	cmp r6, #2
	bne .L0813BB8A
	movs r0, #0
	movs r1, #2
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #4
	bgt .L0813BB7E
	movs r6, #3
	b .L0813BBDE
.L0813BB7E:
	subs r2, #1
	movs r0, #0
	movs r1, #2
	bl sub_08136204
	b .L0813BC16
.L0813BB8A:
	cmp r6, #3
	bne .L0813BBAC
	movs r0, #0
	movs r1, #3
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #6
	bgt .L0813BBA0
	movs r6, #4
	b .L0813BBDE
.L0813BBA0:
	subs r2, #1
	movs r0, #0
	movs r1, #3
	bl sub_08136204
	b .L0813BC16
.L0813BBAC:
	cmp r6, #4
	bne .L0813BBCE
	movs r0, #0
	movs r1, #4
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #6
	bgt .L0813BBC2
	movs r6, #5
	b .L0813BBDE
.L0813BBC2:
	subs r2, #1
	movs r0, #0
	movs r1, #4
	bl sub_08136204
	b .L0813BC16
.L0813BBCE:
	movs r0, #0
	movs r1, #5
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #3
	bgt .L0813BC0C
	movs r6, #0
.L0813BBDE:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #5
	bhi .L0813BC20
	b .L0813BB24
.L0813BBEA:
	adds r0, r6, #0
	movs r1, #1
	bl Combatant_ClearStatus
	ldr r0, .L0813BC00
	lsls r1, r6, #7
	adds r1, r1, r0
	ldrh r0, [r1, #0x1a]
	strh r0, [r1, #0x18]
	b .L0813B5A6
	.byte 0x00, 0x00
.L0813BC00: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813BC04:
	adds r0, r6, #0
	bl Combatant_RestoreHp
	b .L0813BC20
.L0813BC0C:
	subs r2, #1
	movs r0, #0
	movs r1, #5
	bl sub_08136204
.L0813BC16:
	ldr r1, .L0813BC28
	ldrh r0, [r1, #0x1a]
	strh r0, [r1, #0x18]
	bl Hud_InvalidateGauges
.L0813BC20:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813BC28: .4byte 0x030046C0 @ IWRAM+0x46C0
