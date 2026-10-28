	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080F108C
sub_080F108C: @ 0x080F108C
.L080F108C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	adds r4, r1, #0
	lsls r4, r4, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	ldr r0, .L080F110C
	mov sb, r0
	lsrs r1, r4, #0x10
	str r1, [sp, #4]
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl Combatant_GetChosenSkill
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	movs r2, #0
	str r2, [sp, #0x10]
	ldr r0, .L080F1110
	add r0, sb
	movs r1, #0xff
	strh r1, [r0]
	ldr r0, .L080F1114
	add r0, sb
	strh r1, [r0]
	ldr r0, .L080F1118
	add r0, sb
	strh r1, [r0]
	ldr r0, .L080F111C
	strh r1, [r0]
	ldr r1, .L080F1120
	subs r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080F1124
	add r1, sb
	movs r0, #1
	strh r0, [r1]
	mov r1, sl
	ldrb r0, [r1, #0x17]
	subs r0, #4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bls .L080F1100
	b .L080F14BE
.L080F1100:
	lsls r0, r0, #2
	ldr r1, .L080F1128
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080F110C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F1110: .4byte 0x00000ECA
.L080F1114: .4byte 0x00000EC6
.L080F1118: .4byte 0x00000EC8
.L080F111C: .4byte 0x030000AA @ IWRAM+0xAA
.L080F1120: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F1124: .4byte 0x0000097C
.L080F1128: .4byte gUnknown_080F112C
	.global gUnknown_080F112C
gUnknown_080F112C:
.L080F112C: @ jump table
	.4byte .L080F1150
	.4byte .L080F11AC
	.4byte .L080F1480
	.4byte .L080F1340
	.4byte .L080F1224
	.4byte .L080F1498
	.4byte .L080F1208
	.4byte .L080F1340
	.4byte .L080F149E
.L080F1150:
	mov r0, sl
	movs r1, #0
	bl Battle_BuildCombatActionList
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r2, [sp, #4]
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #0
	bl Combatant_GetEquip
	ldr r1, .L080F11A0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r0, .L080F11A4
	add r0, sb
	strh r1, [r0]
	ldrh r0, [r0]
	bl sub_080ED32C
	ldr r1, .L080F11A8
	add r1, sb
	strh r0, [r1]
	mov r0, sl
	adds r1, r4, #0
	bl sub_080EF5FC
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	beq .L080F119A
	b .L080F14BE
.L080F119A:
	movs r0, #1
	str r0, [sp, #0x10]
	b .L080F14BE
.L080F11A0: .4byte gUnknown_0876E458
.L080F11A4: .4byte 0x00000EC6
.L080F11A8: .4byte 0x00000ECA
.L080F11AC:
	mov r0, sl
	movs r1, #1
	bl Battle_BuildCombatActionList
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, [sp, #4]
	lsls r4, r1, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #1
	bl Combatant_GetEquip
	ldr r1, .L080F11FC
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r0, .L080F1200
	add r0, sb
	strh r1, [r0]
	ldrh r0, [r0]
	bl sub_080ED32C
	ldr r1, .L080F1204
	add r1, sb
	strh r0, [r1]
	mov r0, sl
	adds r1, r4, #0
	bl sub_080EF5FC
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	beq .L080F11F6
	b .L080F14BE
.L080F11F6:
	movs r2, #1
	str r2, [sp, #0x10]
	b .L080F14BE
.L080F11FC: .4byte gUnknown_0876E458
.L080F1200: .4byte 0x00000EC6
.L080F1204: .4byte 0x00000ECA
.L080F1208:
	movs r0, #0
	bl sub_080ED32C
	ldr r1, .L080F1220
	add r1, sb
	strh r0, [r1]
	mov r0, sl
	movs r1, #2
	bl Battle_BuildCombatActionList
	b .L080F1332
	.byte 0x00, 0x00
.L080F1220: .4byte 0x00000ECA
.L080F1224:
	lsls r4, r5, #0x10
	asrs r0, r4, #0x10
	movs r1, #0xc
	mov r2, sp
	bl Item_GetAttribute
	ldr r1, [sp, #4]
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r6, r0, #0
	mov r8, r4
	cmp r1, #0xf
	bgt .L080F124E
	lsrs r0, r4, #0x10
	bl Action_GetRecord
	ldrb r0, [r0, #3]
	cmp r0, #0xff
	bne .L080F124E
	movs r2, #1
	str r2, [sp, #0x10]
.L080F124E:
	mov r1, r8
	asrs r0, r1, #0x10
	cmp r0, #0xf0
	bne .L080F1274
	ldr r1, [sp]
	ldr r0, .L080F1270
	add r0, sb
	strh r1, [r0]
	asrs r1, r6, #0xf
	movs r0, #0xf3
	lsls r0, r0, #4
	add r0, sb
	adds r0, r0, r1
	mov r2, sl
	ldrb r1, [r2, #0xc]
	b .L080F127E
	.byte 0x00, 0x00
.L080F1270: .4byte 0x00001192
.L080F1274:
	cmp r0, #0xf8
	bne .L080F1280
	ldr r1, [sp]
	ldr r0, .L080F12E8
	add r0, sb
.L080F127E:
	strh r1, [r0]
.L080F1280:
	mov r1, r8
	asrs r0, r1, #0x10
	cmp r0, #0xbc
	ble .L080F1290
	ldr r0, [sp]
	subs r0, #0x20
	cmp r0, #0x17
	bhi .L080F129C
.L080F1290:
	asrs r0, r6, #0x10
	bl Battle_IsEnemyId
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
.L080F129C:
	mov r2, r8
	asrs r1, r2, #0x10
	cmp r1, #0xf8
	beq .L080F12A8
	cmp r1, #0xf0
	bne .L080F12F4
.L080F12A8:
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	lsls r4, r1, #0x10
	lsrs r5, r4, #0x10
	adds r1, r5, #0
	bl sub_080F0F68
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L080F12EC
	add r1, sb
	strh r0, [r1]
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl sub_080F104C
	ldr r1, .L080F12F0
	add r1, sb
	strh r0, [r1]
	ldr r0, [sp]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	asrs r4, r4, #0x10
	adds r1, r4, #0
	bl sub_080F157C
	b .L080F132C
	.byte 0x00, 0x00
.L080F12E8: .4byte 0x00001194
.L080F12EC: .4byte 0x00000EC6
.L080F12F0: .4byte 0x00000ECA
.L080F12F4:
	ldr r0, .L080F1314
	subs r1, #0xd0
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r0, [r1]
	ldr r2, .L080F1318
	add r2, sb
	strh r0, [r2]
	cmp r0, #0xc8
	ble .L080F1320
	ldrh r1, [r1, #2]
	ldr r0, .L080F131C
	add r0, sb
	strh r1, [r0]
	b .L080F132C
	.byte 0x00, 0x00
.L080F1314: .4byte gUnknown_0876E618
.L080F1318: .4byte 0x00000EC6
.L080F131C: .4byte 0x00000ECA
.L080F1320:
	ldrh r0, [r2]
	bl sub_080ED32C
	ldr r1, .L080F133C
	add r1, sb
	strh r0, [r1]
.L080F132C:
	mov r0, sl
	bl Battle_BuildActorActionText
.L080F1332:
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F14BE
.L080F133C: .4byte 0x00000ECA
.L080F1340:
	ldr r2, [sp, #4]
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	adds r6, r0, #0
	lsls r5, r5, #0x10
	mov r8, r5
	cmp r1, #0xf
	bgt .L080F1364
	lsrs r0, r5, #0x10
	bl sub_080BF5C0
	ldrb r0, [r0, #2]
	cmp r0, #0xf
	beq .L080F1360
	cmp r0, #0xff
	bne .L080F1364
.L080F1360:
	movs r0, #1
	str r0, [sp, #0x10]
.L080F1364:
	mov r1, r8
	asrs r7, r1, #0x10
	cmp r7, #0x3f
	bgt .L080F13E4
	adds r0, r7, #0
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x17
	bhi .L080F1384
	asrs r0, r6, #0x10
	bl Battle_IsEnemyId
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
.L080F1384:
	cmp r4, #2
	bhi .L080F138E
	ldr r1, .L080F13B4
	movs r0, #0
	strh r0, [r1]
.L080F138E:
	mov r0, sl
	bl sub_080EAE30
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	movs r0, #2
	ldr r2, [sp, #0xc]
	ands r0, r2
	cmp r0, #0
	beq .L080F13BC
	ldr r1, .L080F13B8
	add r1, sb
	movs r0, #0xff
	strh r0, [r1]
	ldr r0, [sp, #8]
	lsls r4, r0, #0x10
	b .L080F1466
.L080F13B4: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F13B8: .4byte 0x00000EC6
.L080F13BC:
	mov r1, r8
	lsrs r0, r1, #0x10
	ldr r2, [sp, #8]
	lsls r4, r2, #0x10
	lsrs r1, r4, #0x10
	bl sub_080F0F68
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L080F13E0
	add r1, sb
	strh r0, [r1]
	asrs r1, r4, #0x10
	adds r0, r7, #0
	bl sub_080F157C
	b .L080F1466
	.byte 0x00, 0x00
.L080F13E0: .4byte 0x00000EC6
.L080F13E4:
	ldr r1, .L080F141C
	adds r0, r7, #0
	subs r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r5, [r0, r1]
	cmp r7, #0x66
	bne .L080F1420
	bl sub_080F5938
	adds r4, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L080F1406
	movs r4, #0
.L080F1406:
	adds r0, r5, #0
	bl Battle_GetMessage
	adds r1, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F1444
.L080F141C: .4byte gUnknown_0876E878
.L080F1420:
	adds r0, r5, #0
	bl Battle_GetMessage
	adds r5, r0, #0
	asrs r4, r6, #0x10
	adds r0, r4, #0
	bl Combatant_GetChosenSkill
	lsls r0, r0, #0x10
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F1444:
	mov r2, r8
	lsrs r0, r2, #0x10
	ldr r1, [sp, #8]
	lsls r4, r1, #0x10
	lsrs r1, r4, #0x10
	bl sub_080F0F68
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L080F1478
	add r1, sb
	strh r0, [r1]
	mov r2, r8
	asrs r0, r2, #0x10
	asrs r1, r4, #0x10
	bl sub_080F157C
.L080F1466:
	mov r1, r8
	lsrs r0, r1, #0x10
	lsrs r1, r4, #0x10
	bl sub_080F104C
	ldr r1, .L080F147C
	add r1, sb
	b .L080F14BC
	.byte 0x00, 0x00
.L080F1478: .4byte 0x00000EC6
.L080F147C: .4byte 0x00000ECA
.L080F1480:
	ldr r2, [sp, #4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	bl sub_080F1678
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Party_GetMember
	movs r1, #3
	b .L080F14AA
.L080F1498:
	mov r0, sl
	movs r1, #4
	b .L080F14AA
.L080F149E:
	ldr r0, [sp, #4]
	movs r1, #0
	bl Party_Remove
	mov r0, sl
	movs r1, #5
.L080F14AA:
	bl Battle_BuildCombatActionList
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, .L080F14EC
	add r1, sb
	movs r0, #0xb
.L080F14BC:
	strh r0, [r1]
.L080F14BE:
	ldr r0, .L080F14F0
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x88
	bne .L080F14D8
	mov r2, sl
	movs r0, #0x17
	ldrsb r0, [r2, r0]
	cmp r0, #8
	bne .L080F14D8
	movs r0, #1
	str r0, [sp, #0x10]
.L080F14D8:
	bl Battle_IsTwoSided
	cmp r0, #0
	beq .L080F14E6
	ldr r1, [sp, #0x10]
	cmp r1, #1
	bne .L080F14F8
.L080F14E6:
	ldr r1, .L080F14F4
	movs r0, #0
	b .L080F154C
.L080F14EC: .4byte 0x0000097C
.L080F14F0: .4byte 0x00000EC6
.L080F14F4: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F14F8:
	ldr r2, [sp, #4]
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	adds r6, r0, #0
	cmp r1, #0xf
	bgt .L080F1538
	movs r0, #0
	bl sub_080EDA24
	cmp r0, #0
	beq .L080F1522
	movs r0, #1
	bl sub_080EDA24
	cmp r0, #0
	beq .L080F1522
	ldr r1, .L080F1534
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq .L080F154C
.L080F1522:
	asrs r0, r6, #0x10
	bl sub_080F1788
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080F1548
	ldr r1, .L080F1534
	movs r0, #1
	b .L080F154C
.L080F1534: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F1538:
	cmp r1, #0x13
	bgt .L080F1548
	ldr r1, .L080F1544
	movs r0, #1
	b .L080F154C
	.byte 0x00, 0x00
.L080F1544: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F1548:
	ldr r1, .L080F1574
	movs r0, #2
.L080F154C:
	strh r0, [r1]
	bl sub_080C2B6C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080F1562
	ldr r1, .L080F1578
	add r1, sb
	movs r0, #0xff
	strh r0, [r1]
.L080F1562:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F1574: .4byte 0x030000A8 @ IWRAM+0xA8
.L080F1578: .4byte 0x00000EC6

	thumb_func_start sub_080F157C
sub_080F157C: @ 0x080F157C
.L080F157C:
	push {lr}
	ldr r2, .L080F15A8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0xe
	adds r1, r1, r0
	adds r1, r1, r2
	ldrb r2, [r1]
	ldr r1, .L080F15AC
	movs r0, #0xff
	strh r0, [r1]
	adds r0, r2, #0
	subs r0, #0xdc
	adds r2, r1, #0
	cmp r0, #0x23
	bhi .L080F1670
	lsls r0, r0, #2
	ldr r1, .L080F15B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F15A8: .4byte gUnknown_0876E1D8
.L080F15AC: .4byte 0x030000AA @ IWRAM+0xAA
.L080F15B0: .4byte gUnknown_080F15B4
	.global gUnknown_080F15B4
gUnknown_080F15B4:
.L080F15B4: @ jump table
	.4byte .L080F1644
	.4byte .L080F1648
	.4byte .L080F164C
	.4byte .L080F1650
	.4byte .L080F1654
	.4byte .L080F1658
	.4byte .L080F165C
	.4byte .L080F1660
	.4byte .L080F1664
	.4byte .L080F1668
	.4byte .L080F166C
	.4byte .L080F166C
	.4byte .L080F166C
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
	.4byte .L080F1670
.L080F1644:
	movs r0, #4
	b .L080F166E
.L080F1648:
	movs r0, #4
	b .L080F166E
.L080F164C:
	movs r0, #4
	b .L080F166E
.L080F1650:
	movs r0, #4
	b .L080F166E
.L080F1654:
	movs r0, #7
	b .L080F166E
.L080F1658:
	movs r0, #7
	b .L080F166E
.L080F165C:
	movs r0, #7
	b .L080F166E
.L080F1660:
	movs r0, #8
	b .L080F166E
.L080F1664:
	movs r0, #8
	b .L080F166E
.L080F1668:
	movs r0, #8
	b .L080F166E
.L080F166C:
	movs r0, #5
.L080F166E:
	strh r0, [r2]
.L080F1670:
	movs r1, #0
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1

	thumb_func_start sub_080F1678
sub_080F1678: @ 0x080F1678
.L080F1678:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r1, r1, #0x10
	ldr r3, .L080F16F0
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	movs r4, #0xf1
	lsls r4, r4, #4
	adds r2, r3, r4
	adds r5, r0, r2
	ldrh r6, [r5]
	movs r2, #0xef
	lsls r2, r2, #4
	adds r3, r3, r2
	adds r4, r0, r3
	ldrh r0, [r4]
	mov r8, r0
	lsrs r7, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #2
	bne .L080F16D4
	ldr r1, .L080F16F4
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r1, r2
	adds r2, r0, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L080F16CA
	adds r0, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl Party_Remove
.L080F16CA:
	ldr r0, .L080F16F8
	strh r0, [r4]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r5]
.L080F16D4:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	bl sub_080F30CC
	movs r1, #1
	rsbs r1, r1, #0
	lsls r7, r7, #0x10
	mov r4, r8
	lsls r4, r4, #0x10
	mov r8, r4
	cmp r0, r1
	beq .L080F171A
	movs r0, #0
	b .L080F1702
.L080F16F0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F16F4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F16F8: .4byte 0x0000FFFF
.L080F16FC:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080F1702:
	lsls r5, r0, #0x10
	asrs r4, r5, #0x10
	cmp r4, #5
	bgt .L080F171A
	adds r0, r4, #0
	bl sub_080F30CC
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L080F16FC
	lsrs r6, r5, #0x10
.L080F171A:
	mov r0, r8
	lsrs r5, r0, #0x10
	lsls r6, r6, #0x10
	lsrs r1, r6, #0x10
	adds r0, r5, #0
	bl Party_AddAt
	asrs r4, r7, #0x10
	cmp r4, #0
	bne .L080F173A
	adds r0, r5, #0
	bl sub_0812839C
	rsbs r0, r0, #0
	bl sub_080F3E20
.L080F173A:
	asrs r5, r6, #0x10
	cmp r4, #3
	bne .L080F1760
	ldr r4, .L080F1784
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r4, r5, r4
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0x80
	lsls r1, r1, #7
	bl Combatant_SetStatus
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0
	bl Battle_SetHp
.L080F1760:
	adds r0, r5, #0
	bl sub_080C8490
	bl sub_080C366C
	bl Party_BuildMemberNameTiles
	mov r2, r8
	asrs r0, r2, #0x10
	bl Party_FindPosition
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080F1784: .4byte 0x030046C0 @ IWRAM+0x46C0
