	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080F2514
sub_080F2514: @ 0x080F2514
.L080F2514:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	lsls r1, r1, #0x10
	ldr r0, .L080F2570
	mov r8, r0
	lsrs r4, r1, #0x10
	asrs r5, r1, #0x10
	adds r0, r5, #0
	bl Combatant_GetChosenSkill
	str r0, [sp]
	adds r0, r5, #0
	bl sub_080C35E4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, .L080F2574
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl sub_080EFFF8
	adds r0, r5, #0
	bl Battle_IsEnemyId
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r7, #8
	bne .L080F2586
	adds r0, r5, #0
	bl Combatant_GetChosenSkill
	cmp r0, #0xf0
	bne .L080F257C
	ldr r0, .L080F2578
	add r0, r8
	ldrh r0, [r0]
	str r0, [sp]
	b .L080F2586
.L080F2570: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2574: .4byte 0x00000F66
.L080F2578: .4byte 0x00001192
.L080F257C:
	ldr r0, [sp]
	movs r1, #0xc
	mov r2, sp
	bl Item_GetAttribute
.L080F2586:
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r5, [r0, #2]
	lsls r4, r4, #0x10
	asrs r6, r4, #0x10
	ldr r0, .L080F25C4
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl sub_080EFFF8
	cmp r5, #0x80
	beq .L080F25AC
	cmp r5, #0x82
	bne .L080F25CC
.L080F25AC:
	ldr r2, .L080F25C8
	str r6, [r2]
	lsls r1, r6, #1
	movs r0, #0xf3
	lsls r0, r0, #4
	add r0, r8
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r2, #4]
	lsls r7, r7, #0x10
	b .L080F2626
.L080F25C4: .4byte 0x00000F66
.L080F25C8: .4byte 0x03000088 @ IWRAM+0x88
.L080F25CC:
	ldr r5, .L080F2670
	str r6, [r5]
	mov r2, sb
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #4
	str r0, [r5, #4]
	ldr r0, [sp]
	subs r0, #0x2b
	lsls r7, r7, #0x10
	cmp r0, #0xd
	bhi .L080F2626
	cmp r1, #0
	beq .L080F2626
	movs r0, #0x10
	str r0, [r5, #4]
	bl Battle_IsTwoSided
	cmp r0, #1
	bne .L080F2626
	ldr r0, [r5]
	cmp r0, #0x13
	ble .L080F2626
	movs r6, #0
	movs r5, #0x10
.L080F2602:
	adds r0, r5, #0
	bl Combatant_IsDead
	cmp r0, #0
	bne .L080F2612
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080F2612:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x13
	bls .L080F2602
	cmp r6, #0
	bne .L080F2626
	ldr r1, .L080F2670
	movs r0, #0x14
	str r0, [r1, #4]
.L080F2626:
	asrs r0, r7, #0x10
	cmp r0, #8
	bne .L080F2646
	asrs r0, r4, #0x10
	bl Combatant_GetChosenSkill
	cmp r0, #0xf0
	bne .L080F2646
	ldr r0, [sp]
	subs r0, #0x2b
	cmp r0, #1
	bhi .L080F2646
	ldr r1, .L080F2670
	mov r2, sl
	ldrb r0, [r2, #0xc]
	str r0, [r1, #4]
.L080F2646:
	ldr r5, .L080F2670
	ldr r0, [r5, #4]
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r1, [sp]
	adds r0, r5, #0
	bl sub_080F4988
	ldr r1, [sp]
	adds r0, r1, #0
	subs r0, #0x3e
	cmp r0, #1
	bhi .L080F26BC
	cmp r1, #0x3e
	bne .L080F2674
	asrs r0, r4, #0x10
	movs r1, #1
	b .L080F2678
	.byte 0x00, 0x00
.L080F2670: .4byte 0x03000088 @ IWRAM+0x88
.L080F2674:
	asrs r0, r4, #0x10
	movs r1, #3
.L080F2678:
	bl sub_080F1678
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0xe9
	bl Battle_GetMessage
	ldr r1, .L080F26B4
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r1, r2
	adds r1, r4, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, .L080F26B8
	add r1, r8
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
	b .L080F27B8
.L080F26B4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F26B8: .4byte 0x0000097C
.L080F26BC:
	ldr r0, [r5, #0xc]
	cmp r0, #1
	bne .L080F2774
	ldr r2, [r5, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L080F26FC
	subs r1, #0x1d
	ldr r0, .L080F26F0
	lsls r1, r1, #0x11
	asrs r1, r1, #0xf
	adds r1, r1, r0
	mov r2, sb
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L080F26F4
	cmp r4, r0
	beq .L080F272C
	ldr r0, .L080F26F8
	ands r4, r0
	b .L080F2700
.L080F26F0: .4byte gUnknown_0876F9CC
.L080F26F4: .4byte 0x0000FFFF
.L080F26F8: .4byte 0x00007FFF
.L080F26FC:
	lsls r0, r2, #0x10
	lsrs r4, r0, #0x10
.L080F2700:
	ldr r0, .L080F2768
	cmp r4, r0
	beq .L080F272C
	adds r0, r4, #0
	bl Battle_GetMessage
	ldr r1, .L080F276C
	ldr r1, [r1, #4]
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, .L080F2770
	add r1, r8
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
.L080F272C:
	ldr r1, .L080F2770
	add r1, r8
	movs r0, #0xa
	strh r0, [r1]
	ldr r4, .L080F276C
	ldr r0, [r4, #4]
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r6, r0
	beq .L080F27B8
	ldr r0, [r4, #4]
	cmp r0, #0xf
	bgt .L080F27B8
	bl Party_FindPosition
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080C86B4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x12
	bgt .L080F27B8
	adds r0, r4, #0
	bl sub_080C8490
	b .L080F27B8
.L080F2768: .4byte 0x0000FFFF
.L080F276C: .4byte 0x03000088 @ IWRAM+0x88
.L080F2770: .4byte 0x0000097C
.L080F2774:
	ldr r1, [r5, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080F2794
	ldr r0, .L080F2790
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F27A8
.L080F2790: .4byte gUnknown_08124534
.L080F2794:
	adds r0, r1, #0
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F27A8:
	ldr r1, .L080F27C8
	add r1, r8
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
.L080F27B8:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F27C8: .4byte 0x0000097C

	thumb_func_start sub_080F27CC
sub_080F27CC: @ 0x080F27CC
.L080F27CC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r1, r1, #0x10
	ldr r7, .L080F282C
	lsrs r6, r1, #0x10
	asrs r5, r1, #0x10
	adds r0, r5, #0
	bl Combatant_GetChosenSkill
	str r0, [sp]
	mov r0, sp
	ldrh r0, [r0]
	bl Action_GetRecord
	ldrb r4, [r0, #3]
	adds r0, r5, #0
	bl Battle_IsEnemyId
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, #0x80
	beq .L080F2804
	cmp r4, #0x82
	beq .L080F2804
	cmp r4, #0x83
	bne .L080F2834
.L080F2804:
	ldr r2, .L080F2830
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	str r1, [r2]
	lsls r1, r1, #1
	movs r3, #0xf3
	lsls r3, r3, #4
	adds r0, r7, r3
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r2, #4]
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	b .L080F2844
	.byte 0x00, 0x00
.L080F282C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2830: .4byte 0x03000088 @ IWRAM+0x88
.L080F2834:
	ldr r2, .L080F28B4
	str r5, [r2]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #4
	str r0, [r2, #4]
.L080F2844:
	ldr r5, .L080F28B4
	ldr r0, [r5, #4]
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [sp]
	subs r0, #0xf1
	cmp r0, #1
	bhi .L080F287C
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	str r0, [r5]
	ldr r0, .L080F28B8
	ldr r1, [r0]
	ldr r2, .L080F28BC
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [r5, #4]
.L080F287C:
	adds r0, r5, #0
	ldr r1, [sp]
	bl Item_RunUseEffect
	ldr r1, [sp]
	adds r0, r1, #0
	subs r0, #0xf1
	cmp r0, #1
	bhi .L080F2960
	ldr r0, [r5, #0xc]
	cmp r0, #1
	bne .L080F28C4
	ldr r0, .L080F28C0
	bl Battle_GetMessage
	adds r4, r0, #0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	bl Combatant_GetChosenSkill
	lsls r0, r0, #0x10
	ldr r1, [r5, #4]
	adds r1, r1, r0
	adds r0, r4, #0
	bl Menu_ExpandListTemplate
	b .L080F291E
	.byte 0x00, 0x00
.L080F28B4: .4byte 0x03000088 @ IWRAM+0x88
.L080F28B8: .4byte 0x03006434 @ IWRAM+0x6434
.L080F28BC: .4byte 0x00000F66
.L080F28C0: .4byte 0x00000123
.L080F28C4:
	cmp r0, #2
	bne .L080F2950
	movs r2, #0
	ldr r0, .L080F2938
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r3, r0, r1
	movs r1, #0
	ldrsb r1, [r3, r1]
	ldr r0, [r5, #4]
	cmp r1, r0
	beq .L080F28F6
	adds r4, r3, #0
	adds r3, r5, #0
.L080F28E0:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #5
	bhi .L080F28F6
	adds r0, r2, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r0, [r3, #4]
	cmp r1, r0
	bne .L080F28E0
.L080F28F6:
	cmp r2, #6
	beq .L080F2900
	adds r0, r2, #0
	bl sub_080C86F4
.L080F2900:
	ldr r0, .L080F293C
	bl sub_080ECF70
	ldr r4, .L080F2940
	ldr r0, [r4, #4]
	ldr r2, .L080F2944
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r1, [r4, #0x18]
	ldr r2, .L080F2948
	bl Battle_BuildDamageDealtText
.L080F291E:
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r3, .L080F294C
	adds r1, r7, r3
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
	b .L080F2AB8
.L080F2938: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F293C: .4byte 0x0000012B
.L080F2940: .4byte 0x03000088 @ IWRAM+0x88
.L080F2944: .4byte 0xFFFF8000
.L080F2948: .4byte gUnknown_0812310C
.L080F294C: .4byte 0x0000097C
.L080F2950:
	ldr r0, .L080F295C
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	b .L080F2AB8
	.byte 0x00, 0x00
.L080F295C: .4byte 0x0000097C
.L080F2960:
	ldr r0, [r5, #0xc]
	cmp r0, #1
	beq .L080F2968
	b .L080F2A74
.L080F2968:
	adds r0, r1, #0
	bl sub_080F3E38
	ldr r0, [sp]
	movs r1, #0xc
	mov r2, sp
	bl Item_GetAttribute
	ldr r1, [r5, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080F29B0
	ldr r0, [sp]
	subs r0, #0x80
	ldr r1, .L080F29A4
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, .L080F29A8
	cmp r4, r0
	bne .L080F29F0
	bl sub_080ED9F4
	cmp r0, #0
	beq .L080F29B4
	ldr r4, .L080F29AC
	b .L080F29B4
	.byte 0x00, 0x00
.L080F29A4: .4byte gUnknown_0876FAE4
.L080F29A8: .4byte 0x00000137
.L080F29AC: .4byte 0x0000FFFF
.L080F29B0:
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
.L080F29B4:
	ldr r0, .L080F29E4
	cmp r4, r0
	bne .L080F29F0
	adds r0, r4, #0
	bl Battle_GetMessage
	ldr r1, .L080F29E8
	ldr r1, [r1, #4]
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r2, .L080F29EC
	adds r1, r7, r2
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
	b .L080F2A2C
	.byte 0x00, 0x00
.L080F29E4: .4byte 0x00000137
.L080F29E8: .4byte 0x03000088 @ IWRAM+0x88
.L080F29EC: .4byte 0x0000097C
.L080F29F0:
	ldr r0, .L080F2A68
	cmp r4, r0
	beq .L080F2A2C
	adds r0, r4, #0
	bl Battle_GetMessage
	adds r4, r0, #0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	bl Combatant_GetChosenSkill
	ldr r1, .L080F2A6C
	lsls r0, r0, #0x10
	ldr r1, [r1, #4]
	adds r1, r1, r0
	adds r0, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r3, .L080F2A70
	adds r1, r7, r3
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
.L080F2A2C:
	ldr r0, .L080F2A70
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	ldr r4, .L080F2A6C
	ldr r0, [r4, #4]
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r8, r0
	beq .L080F2AB8
	ldr r0, [r4, #4]
	cmp r0, #0xf
	bgt .L080F2AB8
	bl Party_FindPosition
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080C86B4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x12
	bgt .L080F2AB8
	adds r0, r4, #0
	bl sub_080C8490
	b .L080F2AB8
.L080F2A68: .4byte 0x0000FFFF
.L080F2A6C: .4byte 0x03000088 @ IWRAM+0x88
.L080F2A70: .4byte 0x0000097C
.L080F2A74:
	ldr r1, [r5, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080F2A94
	ldr r0, .L080F2A90
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F2AA8
.L080F2A90: .4byte gUnknown_08124534
.L080F2A94:
	adds r0, r1, #0
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F2AA8:
	ldr r2, .L080F2AC4
	adds r1, r7, r2
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
.L080F2AB8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F2AC4: .4byte 0x0000097C
