	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080E98F8
sub_080E98F8: @ 0x080E98F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r6, .L080E993C
	ldr r1, .L080E9940
	adds r0, r6, r1
	ldrh r7, [r0]
	movs r2, #0
	mov sb, r2
	movs r0, #0xe5
	bl Flag_Test
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r3, sb
	strh r3, [r4, #0x1c]
	ldr r1, .L080E9944
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0x14
	bls .L080E9930
	bl .L080EA168
.L080E9930:
	lsls r0, r0, #2
	ldr r1, .L080E9948
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080E993C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E9940: .4byte 0x0000099C
.L080E9944: .4byte 0x0000097A
.L080E9948: .4byte gUnknown_080E994C
	.global gUnknown_080E994C
gUnknown_080E994C:
.L080E994C: @ jump table
	.4byte .L080E99A0
	.4byte .L080E9ADC
	.4byte .L080E9BD4
	.4byte .L080E9C18
	.4byte .L080E9C48
	.4byte .L080E9C6C
	.4byte .L080E9D0C
	.4byte .L080E9D80
	.4byte .L080E9DD8
	.4byte .L080E9E3C
	.4byte .L080E9F88
	.4byte .L080EA120
	.4byte .L080E9FDC
	.4byte .L080EA02C
	.4byte .L080E9D64
	.4byte .L080E9DBC
	.4byte .L080E9E24
	.4byte .L080E9CD4
	.4byte .L080EA0B0
	.4byte .L080EA120
	.4byte .L080EA158
.L080E99A0:
	movs r0, #0x80
	lsls r0, r0, #7
	bl sub_080F00FC
	movs r0, #0
	bl BattleMsg_SetLocked
	bl sub_080E51FC
	movs r0, #0xb3
	lsls r0, r0, #1
	bl Flag_Clear
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #6
	ands r1, r0
	cmp r1, #0
	beq .L080E99E0
	bl sub_080EF364
	ldr r3, .L080E99DC
	adds r0, r6, r3
	movs r1, #0x10
	strh r1, [r0]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080E9B06
	.byte 0x00, 0x00
.L080E99DC: .4byte 0x00000978
.L080E99E0:
	bl Battle_IsTwoSided
	cmp r0, #0
	bne .L080E9A30
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	bne .L080E9A60
	cmp r5, #0
	beq .L080E9A06
	movs r5, #0x99
	lsls r5, r5, #4
	adds r0, r6, r5
	ldr r0, [r0]
	bl sub_080C2584
.L080E9A06:
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r6, r1
	ldrh r0, [r0]
	ldr r2, .L080E9A28
	adds r1, r6, r2
	ldrh r1, [r1]
	ldr r2, .L080E9A2C
	bl Battle_BuildRaceCountText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r3, #1
	mov sb, r3
	b .L080E9A60
.L080E9A28: .4byte 0x00000998
.L080E9A2C: .4byte gUnknown_08124270
.L080E9A30:
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	bne .L080E9A60
	cmp r5, #0
	beq .L080E9A60
	movs r5, #0x99
	lsls r5, r5, #4
	adds r0, r6, r5
	ldr r0, [r0]
	bl sub_080C2584
	ldr r1, .L080E9ACC
	adds r0, r6, r1
	ldr r0, [r0]
	bl sub_080C2584
	ldr r2, .L080E9AD0
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
.L080E9A60:
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	bne .L080E9AB6
	movs r3, #0x99
	lsls r3, r3, #4
	adds r0, r6, r3
	ldr r0, [r0]
	bl sub_080EF3C8
	adds r4, r0, #0
	movs r5, #1
	rsbs r5, r5, #0
	cmp r4, r5
	beq .L080E9A8E
	bl sub_080C10B4
	cmp r0, #0x62
	ble .L080E9A8E
	adds r4, r5, #0
.L080E9A8E:
	ldr r5, .L080E9AD4
	adds r0, r6, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r0, #1
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	bl sub_080F01D8
	movs r2, #0x99
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	bl sub_080EF434
	cmp r0, #0
	beq .L080E9AB6
	movs r0, #1
	bl sub_080F0150
.L080E9AB6:
	ldr r3, .L080E9AD8
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	mov r5, sb
	cmp r5, #0
	beq .L080E9B06
	movs r0, #0x14
	bl sub_080E5A18
	b .L080E9B06
.L080E9ACC: .4byte 0x00000994
.L080E9AD0: .4byte 0x000007E4
.L080E9AD4: .4byte 0x0000099E
.L080E9AD8: .4byte 0x0000097A
.L080E9ADC:
	ldr r0, .L080E9B0C
	adds r1, r6, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble .L080E9B18
	ldr r2, .L080E9B10
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
	bl Random_Byte
	ldr r4, .L080E9B14
	strh r0, [r4]
	bl Random_Byte
	strh r0, [r4, #2]
	bl sub_080EF364
.L080E9B06:
	bl sub_080C84A0
	b .L080EA168
.L080E9B0C: .4byte 0x0000099E
.L080E9B10: .4byte 0x0000097A
.L080E9B14: .4byte 0x0203A450 @ EWRAM+0x3A450
.L080E9B18:
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	beq .L080E9B9A
	movs r5, #0x10
	movs r7, #0x80
	lsls r7, r7, #8
.L080E9B2C:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L080E9B68
	adds r0, r4, #0
	bl Combatant_GetStatus
	adds r1, r7, #0
	adds r0, r4, #0
	bl Combatant_SetStatus
	adds r0, r4, #0
	movs r1, #0
	bl Battle_SetHp
	adds r0, r4, #0
	movs r1, #0
	bl Battle_SetMp
	adds r0, r5, #0
	subs r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	movs r2, #0
	bl sub_080E7538
.L080E9B68:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x17
	ble .L080E9B2C
	bl sub_080E980C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E9B9A
	ldr r3, .L080E9BC4
	adds r4, r6, r3
	ldr r0, [r4]
	cmp r0, #0
	bne .L080E9B9A
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #2
	bl sub_080AB890
	str r0, [r4]
.L080E9B9A:
	bl sub_080EF364
	bl sub_080C84A0
	ldr r5, .L080E9BC8
	adds r0, r6, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080E9BB4
	movs r0, #9
	bl sub_080ECF60
.L080E9BB4:
	ldr r1, .L080E9BCC
	movs r0, #9
	strh r0, [r1, #0x10]
	ldr r2, .L080E9BD0
	adds r1, r6, r2
	movs r0, #4
	strh r0, [r1]
	b .L080EA168
.L080E9BC4: .4byte 0x00000974
.L080E9BC8: .4byte 0x00000F6A
.L080E9BCC: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E9BD0: .4byte 0x0000097A
.L080E9BD4:
	ldr r3, .L080E9C08
	adds r0, r6, r3
	movs r4, #0
	strh r4, [r0]
	movs r0, #4
	bl Music_FadeOut
	ldr r0, .L080E9C0C
	strh r4, [r0]
	bl BattleMenu_Reset
	bl BattleMsg_Close
	bl sub_080E9008
	ldr r1, .L080E9C10
	movs r0, #1
	strh r0, [r1]
	bl sub_080C7C60
	ldr r5, .L080E9C14
	adds r1, r6, r5
	movs r0, #3
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080E9C08: .4byte 0x00000F68
.L080E9C0C: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080E9C10: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E9C14: .4byte 0x0000097A
.L080E9C18:
	ldr r1, .L080E9C3C
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080E9C34
	ldr r0, .L080E9C40
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080E9C34
	cmp r0, #2
	beq .L080E9C34
	bl sub_080C700C
.L080E9C34:
	ldr r3, .L080E9C44
	adds r0, r6, r3
	movs r1, #0
	b .L080EA138
.L080E9C3C: .4byte 0x00000F6A
.L080E9C40: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080E9C44: .4byte 0x00000978
.L080E9C48:
	bl sub_080E9870
	cmp r0, #0
	beq .L080E9C54
	movs r5, #1
	mov sb, r5
.L080E9C54:
	ldr r0, .L080E9C64
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, .L080E9C68
	adds r1, r6, r2
	movs r0, #5
	b .L080E9F66
.L080E9C64: .4byte 0x00000ECE
.L080E9C68: .4byte 0x0000097A
.L080E9C6C:
	ldr r0, .L080E9CA8
	adds r5, r6, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl sub_080F01EC
	adds r4, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L080E9CB4
	adds r0, r4, #0
	movs r1, #1
	bl sub_080F3E54
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080E9CAC
	bl Battle_BuildItemDropText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	ldr r2, .L080E9CB0
	adds r1, r6, r2
	movs r0, #0x11
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080E9CA8: .4byte 0x00000ECE
.L080E9CAC: .4byte gUnknown_08124452
.L080E9CB0: .4byte 0x0000097A
.L080E9CB4:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsls r1, r7, #0x10
	cmp r0, r1
	bge .L080E9CC4
	b .L080EA168
.L080E9CC4:
	ldr r3, .L080E9CD0
	adds r1, r6, r3
	movs r0, #6
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080E9CD0: .4byte 0x0000097A
.L080E9CD4:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9CE2
	b .L080EA168
.L080E9CE2:
	ldr r5, .L080E9D04
	adds r2, r6, r5
	movs r0, #5
	strh r0, [r2]
	ldr r0, .L080E9D08
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsls r1, r7, #0x10
	cmp r0, r1
	bge .L080E9CFE
	b .L080EA168
.L080E9CFE:
	movs r0, #6
	strh r0, [r2]
	b .L080EA168
.L080E9D04: .4byte 0x0000097A
.L080E9D08: .4byte 0x00000ECE
.L080E9D0C:
	bl sub_080F0168
	adds r4, r0, #0
	ldr r1, .L080E9D58
	adds r6, r6, r1
	movs r5, #7
	strh r5, [r6]
	cmp r4, #0
	bne .L080E9D20
	b .L080EA168
.L080E9D20:
	bl Random_Byte
	ands r0, r5
	movs r1, #0xdb
	cmp r0, #0
	beq .L080E9D2E
	movs r1, #0xe5
.L080E9D2E:
	adds r0, r1, #0
	ldr r5, .L080E9D5C
	cmp r0, #0xe5
	bne .L080E9D38
	ldr r5, .L080E9D60
.L080E9D38:
	adds r1, r4, #0
	bl sub_080F3E54
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl Battle_BuildValueRewardText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	movs r0, #0xe
	strh r0, [r6]
	b .L080EA168
	.byte 0x00, 0x00
.L080E9D58: .4byte 0x0000097A
.L080E9D5C: .4byte gUnknown_0812443C
.L080E9D60: .4byte gUnknown_08124426
.L080E9D64:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9D72
	b .L080EA168
.L080E9D72:
	ldr r2, .L080E9D7C
	adds r1, r6, r2
	movs r0, #7
	strh r0, [r1]
	b .L080EA168
.L080E9D7C: .4byte 0x0000097A
.L080E9D80:
	bl sub_080F0124
	adds r4, r0, #0
	ldr r3, .L080E9DB4
	adds r5, r6, r3
	movs r0, #8
	strh r0, [r5]
	cmp r4, #0
	bne .L080E9D94
	b .L080EA168
.L080E9D94:
	adds r0, r4, #0
	bl sub_080F3E20
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080E9DB8
	bl Battle_BuildValueRewardText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	movs r0, #0xf
	strh r0, [r5]
	b .L080EA168
	.byte 0x00, 0x00
.L080E9DB4: .4byte 0x0000097A
.L080E9DB8: .4byte gUnknown_081243EE
.L080E9DBC:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9DCA
	b .L080EA168
.L080E9DCA:
	ldr r5, .L080E9DD4
	adds r1, r6, r5
	movs r0, #8
	strh r0, [r1]
	b .L080EA168
.L080E9DD4: .4byte 0x0000097A
.L080E9DD8:
	bl sub_080F0144
	adds r4, r0, #0
	ldr r0, .L080E9E14
	adds r5, r6, r0
	movs r7, #0
	movs r0, #9
	strh r0, [r5]
	cmp r4, #0
	beq .L080E9E08
	adds r0, r4, #0
	bl sub_080F3E2C
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080E9E18
	bl Battle_BuildValueRewardText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	movs r0, #0x10
	strh r0, [r5]
.L080E9E08:
	ldr r0, .L080E9E1C
	strh r7, [r0]
	ldr r1, .L080E9E20
	adds r0, r6, r1
	strh r7, [r0]
	b .L080EA168
.L080E9E14: .4byte 0x0000097A
.L080E9E18: .4byte gUnknown_0812440A
.L080E9E1C: .4byte 0x03000056 @ IWRAM+0x56
.L080E9E20: .4byte 0x00000ECE
.L080E9E24:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9E32
	b .L080EA168
.L080E9E32:
	ldr r2, .L080E9E38
	adds r1, r6, r2
	b .L080EA14C
.L080E9E38: .4byte 0x0000097A
.L080E9E3C:
	ldr r3, .L080E9F30
	adds r5, r6, r3
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl Combatant_IsInParty
	cmp r0, #0
	bne .L080E9E4E
	b .L080E9F7C
.L080E9E4E:
	movs r2, #0
	ldrsh r0, [r5, r2]
	bl Combatant_IsAlive
	cmp r0, #0
	bne .L080E9E5C
	b .L080E9F7C
.L080E9E5C:
	ldr r3, .L080E9F34
	adds r0, r3, #0
	ldrh r1, [r5]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	movs r2, #0
	ldrsh r0, [r5, r2]
	bl sub_080F0194
	adds r7, r0, #0
	ldr r0, [r4, #8]
	bl Exp_GetLevel
	mov sl, r0
	ldr r1, .L080E9F38
	movs r0, #0
	strh r0, [r1]
	movs r5, #0
	movs r3, #0x5d
	adds r3, r3, r4
	mov ip, r3
	ldr r0, .L080E9F3C
	mov r8, r0
.L080E9E92:
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	mov r3, ip
	adds r0, r3, r2
	ldrb r3, [r0]
	adds r0, r3, #0
	cmp r0, #0xff
	beq .L080E9EAE
	mov r5, r8
	adds r0, r2, r5
	strb r3, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L080E9EAE:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble .L080E9E92
	cmp r7, #0
	beq .L080E9EE4
	ldr r0, [r4, #8]
	adds r0, r0, r7
	str r0, [r4, #8]
	ldr r1, .L080E9F40
	cmp r0, r1
	ble .L080E9ECE
	ldr r0, .L080E9F44
	str r0, [r4, #8]
.L080E9ECE:
	ldr r2, .L080E9F48
	adds r0, r4, #0
	adds r1, r7, #0
	bl Battle_BuildRewardText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	movs r0, #1
	mov sb, r0
.L080E9EE4:
	ldr r0, [r4, #8]
	bl Exp_GetLevel
	adds r4, r0, #0
	ldr r1, .L080E9F30
	adds r5, r6, r1
	movs r2, #0
	ldrsh r0, [r5, r2]
	adds r1, r4, #0
	bl Combatant_SetLevel
	ldr r0, .L080E9F4C
	mov r3, sl
	subs r4, r4, r3
	strh r4, [r0]
	lsls r0, r4, #0x10
	cmp r0, #0
	beq .L080E9F60
	ldr r1, .L080E9F50
	movs r0, #1
	strh r0, [r1]
	ldr r0, .L080E9F54
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, .L080E9F58
	adds r1, r6, r2
	movs r0, #0xa
	strh r0, [r1]
	ldr r3, .L080E9F5C
	adds r0, r6, r3
	strh r4, [r0]
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl Combatant_RecalcStats
	b .L080EA168
	.byte 0x00, 0x00
.L080E9F30: .4byte 0x00000ECE
.L080E9F34: .4byte 0xFFFF8000
.L080E9F38: .4byte 0x0300005C @ IWRAM+0x5C
.L080E9F3C: .4byte 0x03000060 @ IWRAM+0x60
.L080E9F40: .4byte 0x0098967E
.L080E9F44: .4byte 0x0098967F
.L080E9F48: .4byte gUnknown_0812428E
.L080E9F4C: .4byte 0x03000054 @ IWRAM+0x54
.L080E9F50: .4byte 0x03000056 @ IWRAM+0x56
.L080E9F54: .4byte 0x0000097C
.L080E9F58: .4byte 0x0000097A
.L080E9F5C: .4byte 0x00001178
.L080E9F60:
	ldr r2, .L080E9F78
	adds r1, r6, r2
	movs r0, #0xb
.L080E9F66:
	strh r0, [r1]
	mov r3, sb
	cmp r3, #0
	bne .L080E9F70
	b .L080EA168
.L080E9F70:
	movs r0, #0x14
	bl sub_080E5A18
	b .L080EA168
.L080E9F78: .4byte 0x0000097A
.L080E9F7C:
	ldr r5, .L080E9F84
	adds r1, r6, r5
	b .L080EA0F6
	.byte 0x00, 0x00
.L080E9F84: .4byte 0x0000097A
.L080E9F88:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9F96
	b .L080EA168
.L080E9F96:
	ldr r0, .L080E9FCC
	adds r1, r6, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, .L080E9FD0
	adds r1, r6, r2
	ldr r3, .L080E9FD4
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080E9FD8
	bl Battle_BuildNamePrefixText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	movs r0, #0xb
	bl sub_080ECF60
	movs r0, #0x67
	bl sub_080ECF70
	b .L080EA168
	.byte 0x00, 0x00
.L080E9FCC: .4byte 0x0000097A
.L080E9FD0: .4byte 0x00000ECE
.L080E9FD4: .4byte 0xFFFF8000
.L080E9FD8: .4byte gUnknown_0812434A
.L080E9FDC:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9FEA
	b .L080EA168
.L080E9FEA:
	ldr r5, .L080EA01C
	adds r1, r6, r5
	ldr r2, .L080EA020
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	ldrb r0, [r4, #0xc]
	ldr r3, .L080EA024
	adds r1, r6, r3
	ldrh r1, [r1]
	bl sub_080CE62C
	bl BattleMsg_Close
	ldr r5, .L080EA028
	adds r1, r6, r5
	movs r0, #0xd
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080EA01C: .4byte 0x00000ECE
.L080EA020: .4byte 0xFFFF8000
.L080EA024: .4byte 0x00001178
.L080EA028: .4byte 0x0000097A
.L080EA02C:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080EA03A
	b .L080EA168
.L080EA03A:
	ldr r0, .L080EA090
	adds r5, r6, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl Party_BuildSkillList
	ldr r7, .L080EA094
	movs r2, #0
	ldrsh r4, [r7, r2]
	movs r3, #0
	ldrsh r0, [r5, r3]
	bl Party_GetSkillCount
	cmp r4, r0
	bge .L080EA0A4
	ldr r1, .L080EA098
	adds r0, r1, #0
	ldrh r5, [r5]
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r2, .L080EA09C
	movs r1, #0
	strh r1, [r2]
	movs r2, #0
	ldrsh r1, [r7, r2]
	adds r0, #0x5d
	adds r0, r0, r1
	ldrb r0, [r0]
	bl sub_080EB008
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldr r3, .L080EA0A0
	adds r1, r6, r3
	movs r0, #0x12
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080EA090: .4byte 0x00000ECE
.L080EA094: .4byte 0x0300005C @ IWRAM+0x5C
.L080EA098: .4byte 0xFFFF8000
.L080EA09C: .4byte 0x0300005E @ IWRAM+0x5E
.L080EA0A0: .4byte 0x0000097A
.L080EA0A4:
	ldr r5, .L080EA0AC
	adds r1, r6, r5
	b .L080EA0F6
	.byte 0x00, 0x00
.L080EA0AC: .4byte 0x0000097A
.L080EA0B0:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080EA168
	ldr r0, .L080EA0FC
	adds r1, r6, r0
	ldr r2, .L080EA100
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r2, .L080EA104
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	ldr r1, .L080EA108
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r5, #0
	ldrsh r2, [r2, r5]
	adds r1, r1, r2
	adds r0, #0x5d
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0xff
	bne .L080EA110
	bl BattleMenu_Reset
	ldr r0, .L080EA10C
	adds r1, r6, r0
.L080EA0F6:
	movs r0, #0xb
	strh r0, [r1]
	b .L080EA168
.L080EA0FC: .4byte 0x00000ECE
.L080EA100: .4byte 0xFFFF8000
.L080EA104: .4byte 0x0300005E @ IWRAM+0x5E
.L080EA108: .4byte 0x0300005C @ IWRAM+0x5C
.L080EA10C: .4byte 0x0000097A
.L080EA110:
	ldrb r0, [r1]
	bl sub_080EB008
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	b .L080EA168
.L080EA120:
	ldr r2, .L080EA140
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble .L080EA148
	ldr r3, .L080EA144
	adds r0, r6, r3
	movs r1, #0x10
.L080EA138:
	strh r1, [r0]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080EA168
.L080EA140: .4byte 0x00000ECE
.L080EA144: .4byte 0x00000978
.L080EA148:
	ldr r5, .L080EA154
	adds r1, r6, r5
.L080EA14C:
	movs r0, #9
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080EA154: .4byte 0x0000097A
.L080EA158:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080EA168
	bl sub_080E5A3C
.L080EA168:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
