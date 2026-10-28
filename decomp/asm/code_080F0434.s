	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080F0434
sub_080F0434: @ 0x080F0434
.L080F0434:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	lsls r0, r0, #0x10
	ldr r1, .L080F046C
	mov sl, r1
	lsrs r4, r0, #0x10
	asrs r5, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r6, r0, #0
	cmp r5, #0xf
	bgt .L080F0470
	adds r0, r5, #0
	bl sub_080C35E4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	b .L080F0474
	.byte 0x00, 0x00
.L080F046C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F0470:
	ldrb r3, [r6, #0x17]
	str r3, [sp]
.L080F0474:
	ldr r0, .L080F048C
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xf
	bls .L080F0482
	b .L080F0B64
.L080F0482:
	lsls r0, r0, #2
	ldr r1, .L080F0490
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F048C: .4byte 0x0000097C
.L080F0490: .4byte gUnknown_080F0494
	.global gUnknown_080F0494
gUnknown_080F0494:
.L080F0494: @ jump table
	.4byte .L080F04D4
	.4byte .L080F0544
	.4byte .L080F0784
	.4byte .L080F079C
	.4byte .L080F079C
	.4byte .L080F07A8
	.4byte .L080F0B64
	.4byte .L080F07B4
	.4byte .L080F07C0
	.4byte .L080F07CC
	.4byte .L080F08D4
	.4byte .L080F0A94
	.4byte .L080F0ADC
	.4byte .L080F0AFC
	.4byte .L080F0B60
	.4byte .L080F0B64
.L080F04D4:
	ldr r0, .L080F0534
	add r0, sl
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080F0538
	add r0, sl
	strh r1, [r0]
	ldr r0, .L080F053C
	strh r1, [r0]
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080F0C18
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080F04FC
	b .L080F0B64
.L080F04FC:
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080EF5FC
	ldr r1, .L080F0540
	ldr r1, [r1]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r1, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r1, r6, #0
	bl sub_080F038C
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r0, #0x17
	ldrsb r0, [r6, r0]
	cmp r0, #9
	bne .L080F0526
	b .L080F0A78
.L080F0526:
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080F108C
	b .L080F0B64
.L080F0534: .4byte 0x00000F66
.L080F0538: .4byte 0x000011AA
.L080F053C: .4byte 0x03000080 @ IWRAM+0x80
.L080F0540: .4byte 0x03006434 @ IWRAM+0x6434
.L080F0544:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080F0552
	b .L080F0B64
.L080F0552:
	ldr r5, .L080F0610
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r0, #0xff
	beq .L080F0572
	bl sub_080C2B6C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080F0572
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0
	bl sub_080F4608
.L080F0572:
	ldr r5, .L080F0614
	add r5, sl
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0xff
	bne .L080F0580
	b .L080F0760
.L080F0580:
	cmp r0, #0xd2
	bgt .L080F0586
	b .L080F0720
.L080F0586:
	lsls r4, r4, #0x10
	asrs r1, r4, #0xf
	movs r0, #0xf3
	lsls r0, r0, #4
	add r0, sl
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	bl Battle_FindPartyPosition
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r1, .L080F0618
	add r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r4, [sp, #8]
	cmp r0, #0xff
	beq .L080F05B4
	movs r3, #0
	ldrsh r0, [r1, r3]
	bl sub_080ECF70
.L080F05B4:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L080F05CE
	ldrh r0, [r5]
	subs r0, #0xf0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L080F05CE
	b .L080F0770
.L080F05CE:
	ldr r0, [sp, #8]
	asrs r4, r0, #0x10
	lsls r1, r4, #1
	movs r0, #0xf3
	lsls r0, r0, #4
	add r0, sl
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080F05F2
	adds r0, r4, #0
	bl Battle_FindPartyPosition
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080F05F2:
	ldr r0, .L080F0614
	add r0, sl
	ldrh r0, [r0]
	subs r0, #0xf0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bls .L080F0604
	b .L080F0748
.L080F0604:
	lsls r0, r0, #2
	ldr r1, .L080F061C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080F0610: .4byte 0x030000AA @ IWRAM+0xAA
.L080F0614: .4byte 0x00000EC6
.L080F0618: .4byte 0x00000ECA
.L080F061C: .4byte gUnknown_080F0620
	.global gUnknown_080F0620
gUnknown_080F0620:
.L080F0620: @ jump table
	.4byte .L080F0640
	.4byte .L080F0654
	.4byte .L080F0668
	.4byte .L080F067C
	.4byte .L080F0690
	.4byte .L080F06B4
	.4byte .L080F06D8
	.4byte .L080F06FC
.L080F0640:
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #3
	bl sub_080ECE38
	b .L080F0748
.L080F0654:
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #0
	bl sub_080ECE38
	b .L080F0748
.L080F0668:
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #5
	bl sub_080ECE38
	b .L080F0748
.L080F067C:
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #1
	bl sub_080ECE38
	b .L080F0748
.L080F0690:
	movs r0, #5
	bl sub_080ECE08
	movs r0, #0
.L080F0698:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #3
	adds r0, r4, #0
	movs r2, #3
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L080F0698
	b .L080F0748
.L080F06B4:
	movs r0, #5
	bl sub_080ECE08
	movs r0, #0
.L080F06BC:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #3
	adds r0, r4, #0
	movs r2, #0
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L080F06BC
	b .L080F0748
.L080F06D8:
	movs r0, #5
	bl sub_080ECE08
	movs r0, #0
.L080F06E0:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #3
	adds r0, r4, #0
	movs r2, #5
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L080F06E0
	b .L080F0748
.L080F06FC:
	movs r0, #5
	bl sub_080ECE08
	movs r0, #0
.L080F0704:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #3
	adds r0, r4, #0
	movs r2, #1
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L080F0704
	b .L080F0748
.L080F0720:
	cmp r0, #0xff
	beq .L080F0760
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	bl Battle_IsEnemyId
	adds r3, r0, #0
	movs r4, #0
	ldrsh r0, [r5, r4]
	ldr r1, .L080F0754
	movs r2, #0
	ldrsh r1, [r1, r2]
	ldr r2, .L080F0758
	add r2, sl
	movs r4, #0
	ldrsh r2, [r2, r4]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl sub_080EC9AC
.L080F0748:
	ldr r1, .L080F075C
	add r1, sl
	movs r0, #2
	strh r0, [r1]
	b .L080F0B64
	.byte 0x00, 0x00
.L080F0754: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F0758: .4byte 0x00000ECA
.L080F075C: .4byte 0x0000097C
.L080F0760:
	ldr r1, .L080F077C
	add r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0xff
	beq .L080F0770
	bl sub_080ECF70
.L080F0770:
	ldr r1, .L080F0780
	add r1, sl
	movs r0, #3
	strh r0, [r1]
	b .L080F0B64
	.byte 0x00, 0x00
.L080F077C: .4byte 0x00000ECA
.L080F0780: .4byte 0x0000097C
.L080F0784:
	bl sub_080ECB10
	cmp r0, #0
	bne .L080F078E
	b .L080F0B64
.L080F078E:
	ldr r1, .L080F0798
	add r1, sl
	movs r0, #4
	strh r0, [r1]
	b .L080F0B64
.L080F0798: .4byte 0x0000097C
.L080F079C:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, r6, #0
	bl sub_080F0CFC
	b .L080F0B64
.L080F07A8:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, r6, #0
	bl sub_080F17C0
	b .L080F0B64
.L080F07B4:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, r6, #0
	bl sub_080F2514
	b .L080F0B64
.L080F07C0:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, r6, #0
	bl sub_080F27CC
	b .L080F0B64
.L080F07CC:
	ldr r5, .L080F0810
	ldrh r6, [r5, #4]
	movs r0, #4
	ldrsh r4, [r5, r0]
	adds r0, r4, #0
	bl sub_080EF0E4
	cmp r0, #0
	beq .L080F081C
	ldr r1, .L080F0814
	adds r0, r4, #0
	bl Combatant_ClearStatus
	ldr r1, [r5, #0x18]
	adds r0, r4, #0
	bl Combatant_ChangeHp
	ldr r0, .L080F0818
	bl Battle_GetMessage
	adds r4, r0, #0
	bl sub_080F3E44
	adds r1, r0, #0
	lsls r1, r1, #0x10
	adds r0, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F0B48
	.byte 0x00, 0x00
.L080F0810: .4byte 0x03000088 @ IWRAM+0x88
.L080F0814: .4byte 0x00007FFF
.L080F0818: .4byte 0x00000171
.L080F081C:
	adds r0, r4, #0
	bl Battle_IsEnemyId
	cmp r0, #1
	bne .L080F0850
	ldr r1, .L080F0848
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	bl Battle_BuildDefeatedTargetText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r0, .L080F084C
	bl sub_080ECF70
	b .L080F08A8
	.byte 0x00, 0x00
.L080F0848: .4byte 0xFFFF8000
.L080F084C: .4byte 0x0000012F
.L080F0850:
	movs r2, #0x97
	lsls r2, r2, #1
	mov r8, r2
	cmp r4, #3
	bgt .L080F085E
	ldr r3, .L080F08C4
	mov r8, r3
.L080F085E:
	ldr r1, .L080F08C8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r5, r0, #0
	ldrh r7, [r5, #0x10]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	adds r0, r7, #0
	orrs r0, r1
	strh r0, [r5, #0x10]
	bl Battle_IsPartyDefeated
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F088C
	movs r0, #0
	bl BattleMsg_SetLocked
.L080F088C:
	strh r7, [r5, #0x10]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r4, r3
	ldr r1, .L080F08CC
	bl Battle_BuildNamePrependText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	mov r0, r8
	bl sub_080ECF70
.L080F08A8:
	lsls r4, r6, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_080EF218
	cmp r4, #0xf
	bgt .L080F08B8
	b .L080F0B48
.L080F08B8:
	ldr r1, .L080F08D0
	add r1, sl
	movs r0, #0xd
	strh r0, [r1]
	b .L080F0B64
	.byte 0x00, 0x00
.L080F08C4: .4byte 0x0000012D
.L080F08C8: .4byte 0xFFFF8000
.L080F08CC: .4byte gUnknown_08124264
.L080F08D0: .4byte 0x0000097C
.L080F08D4:
	bl sub_080ED9F4
	cmp r0, #0
	bne .L080F08DE
	b .L080F0A78
.L080F08DE:
	bl Battle_IsPartyDefeated
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F08EC
	b .L080F0A78
.L080F08EC:
	ldr r1, .L080F0938
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r7, .L080F093C
	add r7, sl
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	ldr r1, .L080F0940
	add r1, sl
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, .L080F0944
	add r2, sl
	mov sb, r2
	movs r0, #3
	strh r0, [r2]
	lsls r4, r4, #0x10
	asrs r5, r4, #0x10
	adds r0, r5, #0
	bl Combatant_GetStatus
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	cmp r1, #0
	beq .L080F0948
	movs r0, #0xb
	mov r3, sb
	strh r0, [r3]
	b .L080F0B64
	.byte 0x00, 0x00
.L080F0938: .4byte 0x03000080 @ IWRAM+0x80
.L080F093C: .4byte 0x00000F66
.L080F0940: .4byte 0x000011AA
.L080F0944: .4byte 0x0000097C
.L080F0948:
	bl Battle_IsTwoSided
	cmp r0, #0
	beq .L080F09BC
	ldr r4, .L080F09B4
	mov r8, r4
	ldr r0, [r4]
	movs r4, #0xae
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r2, .L080F09B8
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r0, [r0]
	cmp r0, r1
	ble .L080F09BC
	movs r0, #0
	ldrsh r1, [r7, r0]
	adds r0, r5, #0
	bl sub_080EFFF8
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L080F09BC
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r4
	ldr r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #8
	cmp r0, r2
	beq .L080F09BC
	mov r3, sp
	ldrh r3, [r3, #4]
	strh r3, [r7]
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_080F038C
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r4
	ldr r2, .L080F09B8
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r0, [r0]
	cmp r0, r1
	ble .L080F09AC
	b .L080F0B64
.L080F09AC:
	movs r0, #0xb
	mov r4, sb
	strh r0, [r4]
	b .L080F0B64
.L080F09B4: .4byte 0x03006434 @ IWRAM+0x6434
.L080F09B8: .4byte 0x03000080 @ IWRAM+0x80
.L080F09BC:
	ldr r1, [sp]
	lsls r0, r1, #0x18
	asrs r2, r0, #0x18
	movs r3, #0xfc
	lsls r3, r3, #0x18
	adds r0, r0, r3
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls .L080F09E2
	cmp r2, #0xa
	beq .L080F09E2
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r1, [r0]
	adds r0, r2, #0
	bl sub_080F03D8
	cmp r0, #1
	bne .L080F0A2C
.L080F09E2:
	ldr r6, .L080F0A20
	ldr r0, [r6]
	movs r5, #0xae
	lsls r5, r5, #1
	adds r0, r0, r5
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r1, r0
	beq .L080F0A2C
	ldr r4, [sp, #8]
	asrs r0, r4, #0x10
	ldr r4, .L080F0A24
	add r4, sl
	movs r2, #0
	ldrsh r1, [r4, r2]
	bl sub_080EFFF8
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L080F0A12
	movs r0, #0
	strh r0, [r4]
.L080F0A12:
	ldr r0, [r6]
	adds r0, r0, r5
	ldr r1, .L080F0A28
	movs r3, #0
	ldrsh r1, [r1, r3]
	b .L080F0A72
	.byte 0x00, 0x00
.L080F0A20: .4byte 0x03006434 @ IWRAM+0x6434
.L080F0A24: .4byte 0x00000F66
.L080F0A28: .4byte 0x03000080 @ IWRAM+0x80
.L080F0A2C:
	ldr r5, .L080F0A84
	ldr r0, [r5]
	movs r4, #0xae
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r2, .L080F0A88
	add r2, sl
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r0, [r0]
	cmp r0, r1
	bgt .L080F0A4C
	ldr r1, .L080F0A8C
	add r1, sl
	movs r0, #0xb
	strh r0, [r1]
.L080F0A4C:
	ldr r1, [sp, #8]
	asrs r0, r1, #0x10
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl sub_080EFFF8
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L080F0A68
	ldr r1, .L080F0A8C
	add r1, sl
	movs r0, #0xb
	strh r0, [r1]
.L080F0A68:
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r1, .L080F0A90
	movs r4, #0
	ldrsh r1, [r1, r4]
.L080F0A72:
	ldr r0, [r0]
	cmp r0, r1
	bgt .L080F0B64
.L080F0A78:
	ldr r1, .L080F0A8C
	add r1, sl
	movs r0, #0xb
	strh r0, [r1]
	b .L080F0B64
	.byte 0x00, 0x00
.L080F0A84: .4byte 0x03006434 @ IWRAM+0x6434
.L080F0A88: .4byte 0x00000F66
.L080F0A8C: .4byte 0x0000097C
.L080F0A90: .4byte 0x03000080 @ IWRAM+0x80
.L080F0A94:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F0B64
	bl Battle_IsTwoSided
	cmp r0, #0
	beq .L080F0AD8
	ldr r0, .L080F0AD0
	add r0, sl
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080F0AD8
	movs r0, #0
	bl sub_080EDA24
	cmp r0, #0
	beq .L080F0AC6
	movs r0, #1
	bl sub_080EDA24
	cmp r0, #0
	bne .L080F0AD8
.L080F0AC6:
	ldr r1, .L080F0AD4
	add r1, sl
	movs r0, #0xe
	b .L080F0B4E
	.byte 0x00, 0x00
.L080F0AD0: .4byte 0x0000118C
.L080F0AD4: .4byte 0x0000097C
.L080F0AD8:
	movs r0, #1
	b .L080F0B66
.L080F0ADC:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F0B64
	ldr r0, .L080F0AF4
	ldrh r1, [r0]
	ldr r0, .L080F0AF8
	add r0, sl
	strh r1, [r0]
	b .L080F0B64
.L080F0AF4: .4byte 0x030000AC @ IWRAM+0xAC
.L080F0AF8: .4byte 0x0000097C
.L080F0AFC:
	bl sub_080EDAD0
	cmp r0, #0
	beq .L080F0B14
	movs r0, #0x99
	lsls r0, r0, #4
	add r0, sl
	ldr r0, [r0]
	bl sub_080EDAEC
	cmp r0, #0
	beq .L080F0B48
.L080F0B14:
	ldr r0, .L080F0B40
	ldrh r6, [r0, #4]
	adds r0, r6, #0
	subs r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #2
	bl sub_080E75DC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080F0B64
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	bl sub_080F0B78
	cmp r0, #1
	bne .L080F0B48
	ldr r1, .L080F0B44
	add r1, sl
	movs r0, #0xe
	b .L080F0B4E
.L080F0B40: .4byte 0x03000088 @ IWRAM+0x88
.L080F0B44: .4byte 0x0000097C
.L080F0B48:
	ldr r1, .L080F0B5C
	add r1, sl
	movs r0, #0xa
.L080F0B4E:
	strh r0, [r1]
	movs r0, #3
	movs r1, #0xc
	bl sub_080F0344
	b .L080F0B64
	.byte 0x00, 0x00
.L080F0B5C: .4byte 0x0000097C
.L080F0B60:
	bl sub_080F0BEC
.L080F0B64:
	movs r0, #0
.L080F0B66:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
