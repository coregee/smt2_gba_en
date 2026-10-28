	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080E47A8
sub_080E47A8: @ 0x080E47A8
.L080E47A8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, [sp, #0x24]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sb, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov sl, r4
	ldr r7, .L080E480C
	ldr r1, .L080E4810
	adds r5, r7, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r6, #0xf
	ands r6, r0
	movs r1, #0x10
	ands r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	ldr r2, .L080E4814
	adds r0, r7, r2
	movs r4, #0
	strb r1, [r0]
	bl sub_080E44F8
	ldr r3, .L080E4818
	strh r4, [r3, #0x14]
	ldrh r2, [r3]
	cmp r2, #1
	bne .L080E4830
	strh r2, [r3, #6]
	cmp r6, #0
	bne .L080E4820
	strh r2, [r5, #2]
	ldr r1, .L080E481C
	adds r0, r7, r1
	strh r2, [r0]
	b .L080E4A00
	.byte 0x00, 0x00
.L080E480C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E4810: .4byte 0x00001154
.L080E4814: .4byte 0x00001189
.L080E4818: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E481C: .4byte 0x00000F6A
.L080E4820:
	strh r6, [r5, #2]
	ldr r2, .L080E482C
	adds r0, r7, r2
	strh r6, [r0]
	b .L080E4A00
	.byte 0x00, 0x00
.L080E482C: .4byte 0x00000F6A
.L080E4830:
	strh r6, [r5, #2]
	ldr r1, .L080E48AC
	adds r0, r7, r1
	strh r6, [r0]
	mov r2, r8
	strh r2, [r5, #4]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5, #6]
	mov r1, sb
	strh r1, [r5, #8]
	mov r2, sl
	strh r2, [r5, #0xa]
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
	adds r1, #4
	adds r0, r7, r1
	ldr r2, [sp]
	str r2, [r0]
	adds r1, #4
	adds r0, r7, r1
	mov r2, sb
	strh r2, [r0]
	adds r1, #2
	adds r0, r7, r1
	mov r2, sl
	strh r2, [r0]
	ldr r1, .L080E48B0
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, .L080E48B4
	adds r0, r7, r2
	strh r4, [r0]
	ldr r1, .L080E48B8
	movs r0, #0
	strb r0, [r1]
	ldr r1, .L080E48BC
	adds r0, r7, r1
	strh r4, [r0]
	adds r2, #6
	adds r1, r7, r2
	ldr r0, .L080E48C0
	strh r0, [r1]
	ldr r0, .L080E48C4
	adds r1, r7, r0
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	ldr r1, .L080E48C8
	adds r0, r7, r1
	strh r4, [r0]
	adds r0, r6, #0
	cmp r0, #2
	beq .L080E48DE
	cmp r0, #2
	bgt .L080E48CC
	cmp r0, #1
	beq .L080E48D2
	b .L080E48E6
.L080E48AC: .4byte 0x00000F6A
.L080E48B0: .4byte 0x000011A4
.L080E48B4: .4byte 0x000011A6
.L080E48B8: .4byte 0x0300003D @ IWRAM+0x3D
.L080E48BC: .4byte 0x0000118C
.L080E48C0: .4byte 0x0000FFFF
.L080E48C4: .4byte 0x000011AE
.L080E48C8: .4byte 0x000011A8
.L080E48CC:
	cmp r0, #3
	beq .L080E48D6
	b .L080E48E6
.L080E48D2:
	strh r4, [r3, #0x16]
	b .L080E48EC
.L080E48D6:
	movs r0, #0x80
	lsls r0, r0, #8
	strh r0, [r3, #0x16]
	b .L080E48EC
.L080E48DE:
	movs r0, #0xc0
	lsls r0, r0, #8
	strh r0, [r3, #0x16]
	b .L080E48EC
.L080E48E6:
	ldr r1, .L080E4934
	movs r0, #0
	strh r0, [r1, #0x16]
.L080E48EC:
	movs r1, #0
	str r1, [r7]
	ldr r2, .L080E4938
	adds r0, r7, r2
	str r1, [r0]
	subs r2, #4
	adds r0, r7, r2
	str r1, [r0]
	ldr r2, .L080E493C
	adds r0, r7, r2
	strh r1, [r0]
	ldr r2, .L080E4940
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	ldr r2, .L080E4944
	adds r0, r7, r2
	strh r1, [r0]
	bl BattleState_Init
	ldr r0, .L080E4948
	ldr r1, [sp]
	cmp r1, r0
	beq .L080E494C
	bl sub_080ED938
	b .L080E4952
	.byte 0x00, 0x00
.L080E4934: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E4938: .4byte 0x00000974
.L080E493C: .4byte 0x00000F68
.L080E4940: .4byte 0x00000978
.L080E4944: .4byte 0x00000ECE
.L080E4948: .4byte 0x0000FFFF
.L080E494C:
	movs r0, #0
	bl sub_080ED938
.L080E4952:
	ldr r2, .L080E4A10
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble .L080E496E
	ldr r2, .L080E4A14
	adds r0, r7, r2
	movs r1, #1
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl sub_080ED90C
.L080E496E:
	ldr r0, .L080E4A14
	adds r1, r7, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne .L080E497E
	movs r0, #1
	strh r0, [r1]
.L080E497E:
	ldrh r1, [r1]
	ldr r2, .L080E4A18
	adds r0, r7, r2
	strh r1, [r0]
	bl sub_080E74DC
	movs r0, #0
.L080E498C:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl Combatant_UpdateStats
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble .L080E498C
	ldr r4, .L080E4A1C
	movs r6, #0
	movs r0, #0
	mov r8, r0
	movs r5, #1
	strh r5, [r4]
	ldr r1, .L080E4A20
	adds r0, r7, r1
	strb r6, [r0]
	mov r2, r8
	strh r2, [r4, #0xc]
	bl sub_080C7C60
	movs r0, #0
	bl BattleMsg_SetLocked
	ldr r1, .L080E4A24
	adds r0, r7, r1
	strb r6, [r0]
	strh r5, [r4, #6]
	mov r2, r8
	strh r2, [r4, #0xa]
	ldr r0, .L080E4A28
	bl sub_080E5668
	ldr r0, .L080E4A2C
	ldr r1, .L080E4A30
	bl Task_Create
	str r0, [r4, #0x18]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L080E4A34
	ldrh r1, [r0]
	cmp r1, #9
	bne .L080E49F2
	ldr r0, .L080E4A38
	ldrh r1, [r0]
.L080E49F2:
	ldr r2, .L080E4A3C
	adds r0, r7, r2
	strh r1, [r0]
	bl sub_080B0888
	bl sub_080C7054
.L080E4A00:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E4A10: .4byte 0x00000F6A
.L080E4A14: .4byte 0x0000099C
.L080E4A18: .4byte 0x0000099E
.L080E4A1C: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E4A20: .4byte 0x00001122
.L080E4A24: .4byte 0x00001123
.L080E4A28: .4byte sub_080E5674
.L080E4A2C: .4byte gUnknown_086BEF88
.L080E4A30: .4byte 0x0000FFFF
.L080E4A34: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080E4A38: .4byte 0x030031EC @ IWRAM+0x31EC
.L080E4A3C: .4byte 0x0000118A

	thumb_func_start sub_080E4A40
sub_080E4A40: @ 0x080E4A40
.L080E4A40:
	push {r4, r5, r6, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L080E4A94
	lsls r1, r6, #2
	movs r2, #0x99
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r5, r1, r0
	ldrh r0, [r5]
	bl Demon_GetGfxRecord
	ldr r4, [r0, #4]
	ldr r0, .L080E4A98
	ldr r1, [r0]
	ldr r0, .L080E4A9C
	cmp r1, r0
	bne .L080E4A72
	ldr r0, [r5]
	bl sub_080C2644
	cmp r0, #0
	bne .L080E4A72
	ldr r4, .L080E4AA0
.L080E4A72:
	cmp r6, #0
	bne .L080E4AA8
	ldr r2, .L080E4AA4
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xf0
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #2
	bl PalFade_FadeRangeInFromBlack
	b .L080E4AC4
.L080E4A94: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E4A98: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080E4A9C: .4byte sub_080D977C
.L080E4AA0: .4byte gUnknown_086BE584
.L080E4AA4: .4byte 0x03002D70 @ IWRAM+0x2D70
.L080E4AA8:
	ldr r2, .L080E4ACC
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xf8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #2
	bl PalFade_FadeRangeInFromBlack
.L080E4AC4:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080E4ACC: .4byte 0x03002D90 @ IWRAM+0x2D90

	thumb_func_start sub_080E4AD0
sub_080E4AD0: @ 0x080E4AD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r6, .L080E4AF8
	movs r0, #0
	mov r1, r8
	strh r0, [r1, #0x1c]
	ldr r2, .L080E4AFC
	adds r0, r6, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bls .L080E4AEE
	b .L080E51AA
.L080E4AEE:
	lsls r0, r0, #2
	ldr r1, .L080E4B00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080E4AF8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E4AFC: .4byte 0x00000978
.L080E4B00: .4byte gUnknown_080E4B04
	.global gUnknown_080E4B04
gUnknown_080E4B04:
.L080E4B04: @ jump table
	.4byte .L080E4B2C
	.4byte .L080E4E58
	.4byte .L080E4EB0
	.4byte .L080E4F0C
	.4byte .L080E4F50
	.4byte .L080E4F9C
	.4byte .L080E5020
	.4byte .L080E5090
	.4byte .L080E50E0
	.4byte .L080E5188
.L080E4B2C:
	movs r2, #0
	movs r5, #0x9a
	lsls r5, r5, #4
	movs r3, #0
	movs r4, #0x80
	lsls r4, r4, #8
.L080E4B38:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #7
	adds r0, r0, r5
	adds r0, r6, r0
	strh r3, [r0, #0xe]
	strh r4, [r0, #0x10]
	strh r3, [r0, #0x18]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #7
	ble .L080E4B38
	bl sub_080ED878
	movs r0, #0
	bl sub_080ED900
	movs r0, #3
	rsbs r0, r0, #0
	bl BattleFlags_Mask
	movs r0, #5
	rsbs r0, r0, #0
	bl BattleFlags_Mask
	movs r0, #9
	rsbs r0, r0, #0
	bl BattleFlags_Mask
	ldr r0, .L080E4C50
	bl BattleFlags_Mask
	ldr r0, .L080E4C54
	bl BattleFlags_Mask
	ldr r0, .L080E4C58
	bl BattleFlags_Mask
	ldr r2, .L080E4C5C
	adds r0, r6, r2
	movs r1, #0
	ldrsh r5, [r0, r1]
	cmp r5, #0
	beq .L080E4B96
	b .L080E4D44
.L080E4B96:
	ldr r1, .L080E4C60
	ldr r0, .L080E4C64
	strh r0, [r1, #0x12]
	ldr r2, .L080E4C68
	adds r0, r6, r2
	strh r5, [r0]
	ldr r1, .L080E4C6C
	adds r0, r6, r1
	strh r5, [r0]
	adds r2, #0x10
	adds r7, r6, r2
	strh r5, [r7]
	subs r1, #0x7b
	adds r0, r6, r1
	ldrb r4, [r0]
	cmp r4, #1
	bne .L080E4BBA
	b .L080E4CF4
.L080E4BBA:
	ldr r2, .L080E4C70
	adds r0, r6, r2
	ldr r7, [r0]
	movs r0, #0xf0
	mov r8, r0
	ands r7, r0
	cmp r7, #0
	beq .L080E4C04
	movs r1, #0x98
	lsls r1, r1, #4
	adds r4, r6, r1
	ldr r0, [r4]
	movs r1, #0
	bl sub_080ED5B4
	ldr r2, .L080E4C74
	adds r5, r6, r2
	str r0, [r5]
	ldr r0, [r4]
	movs r1, #1
	bl sub_080ED5B4
	ldr r2, .L080E4C78
	adds r1, r6, r2
	str r0, [r1]
	ldr r1, [r5]
	cmp r1, r0
	beq .L080E4C04
	bl Random_Byte
	mov r1, r8
	ands r0, r1
	cmp r7, r0
	bhi .L080E4C04
	ldr r0, .L080E4C7C
	bl sub_080ED938
.L080E4C04:
	bl Battle_IsTwoSided
	cmp r0, #0
	beq .L080E4C22
	ldr r2, .L080E4C74
	adds r0, r6, r2
	adds r2, #4
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne .L080E4C22
	movs r0, #0
	bl sub_080ED938
.L080E4C22:
	bl Battle_IsTwoSided
	cmp r0, #0
	bne .L080E4C84
	movs r1, #0x98
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0
	bl sub_080ED5B4
	movs r2, #0x99
	lsls r2, r2, #4
	adds r1, r6, r2
	str r0, [r1]
	ldr r0, .L080E4C80
	adds r1, r6, r0
	ldr r0, .L080E4C7C
	str r0, [r1]
	subs r2, #0x18
	adds r1, r6, r2
	b .L080E4CB2
	.byte 0x00, 0x00
.L080E4C50: .4byte 0xFFFFFDFF
.L080E4C54: .4byte 0xFFFFFBFF
.L080E4C58: .4byte 0xFFFFF7FF
.L080E4C5C: .4byte 0x00000F6A
.L080E4C60: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E4C64: .4byte 0x000003E7
.L080E4C68: .4byte 0x0000118C
.L080E4C6C: .4byte 0x0000119E
.L080E4C70: .4byte 0x00000984
.L080E4C74: .4byte 0x00000988
.L080E4C78: .4byte 0x0000098C
.L080E4C7C: .4byte 0x0000FFFF
.L080E4C80: .4byte 0x00000994
.L080E4C84:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r2, .L080E4CDC
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L080E4CE0
	adds r1, r6, r0
	adds r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L080E4CE4
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	subs r2, #0x14
	adds r1, r6, r2
	movs r0, #5
	strh r0, [r1]
	ldr r0, .L080E4CE8
	adds r1, r6, r0
.L080E4CB2:
	movs r0, #1
	strh r0, [r1]
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	bl sub_080ED610
	ldr r2, .L080E4CEC
	adds r1, r6, r2
	strh r0, [r1]
	ldr r1, .L080E4CE0
	adds r0, r6, r1
	ldr r0, [r0]
	bl sub_080ED610
	ldr r2, .L080E4CF0
	adds r1, r6, r2
	strh r0, [r1]
	b .L080E4D20
	.byte 0x00, 0x00
.L080E4CDC: .4byte 0x00000988
.L080E4CE0: .4byte 0x00000994
.L080E4CE4: .4byte 0x00001198
.L080E4CE8: .4byte 0x0000119C
.L080E4CEC: .4byte 0x00000998
.L080E4CF0: .4byte 0x0000099A
.L080E4CF4:
	bl Battle_IsTwoSided
	cmp r0, #0
	bne .L080E4D08
	ldr r1, .L080E4D04
	adds r0, r6, r1
	strh r4, [r0]
	b .L080E4D18
.L080E4D04: .4byte 0x00000978
.L080E4D08:
	ldr r2, .L080E4D34
	adds r0, r6, r2
	strh r5, [r0]
	ldr r0, .L080E4D38
	adds r1, r6, r0
	movs r0, #5
	strh r0, [r1]
	strh r4, [r7]
.L080E4D18:
	ldr r2, .L080E4D3C
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
.L080E4D20:
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r6, r1
	ldrh r0, [r0]
	ldr r2, .L080E4D40
	adds r1, r6, r2
	ldrh r1, [r1]
	bl sub_0813E908
	b .L080E4D66
.L080E4D34: .4byte 0x00001198
.L080E4D38: .4byte 0x00000978
.L080E4D3C: .4byte 0x00001123
.L080E4D40: .4byte 0x00000994
.L080E4D44:
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	bl sub_080ED67C
	ldr r1, .L080E4DA4
	movs r0, #0
	strh r0, [r1, #0x12]
	movs r0, #0x80
	lsls r0, r0, #1
	bl sub_080ED90C
	ldr r2, .L080E4DA8
	adds r1, r6, r2
	movs r0, #4
	strh r0, [r1]
.L080E4D66:
	bl Battle_IsTwoSided
	cmp r0, #0
	bne .L080E4DB0
	movs r2, #0
	ldr r1, .L080E4DAC
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge .L080E4E16
.L080E4D7C:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	movs r2, #0x99
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl Battle_InitEnemyUnit
	adds r4, #1
	lsls r4, r4, #0x10
	ldr r1, .L080E4DAC
	adds r0, r6, r1
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt .L080E4D7C
	b .L080E4E16
.L080E4DA4: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E4DA8: .4byte 0x00000978
.L080E4DAC: .4byte 0x00000998
.L080E4DB0:
	movs r2, #0
	ldr r1, .L080E4E48
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge .L080E4DE4
.L080E4DBE:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	movs r2, #0x99
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl Battle_InitEnemyUnit
	adds r4, #1
	lsls r4, r4, #0x10
	ldr r1, .L080E4E48
	adds r0, r6, r1
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt .L080E4DBE
.L080E4DE4:
	movs r2, #0
	ldr r1, .L080E4E4C
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge .L080E4E16
.L080E4DF2:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #4
	ldr r2, .L080E4E50
	adds r1, r6, r2
	ldr r1, [r1]
	bl Battle_InitEnemyUnit
	adds r4, #1
	lsls r4, r4, #0x10
	ldr r1, .L080E4E4C
	adds r0, r6, r1
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt .L080E4DF2
.L080E4E16:
	movs r2, #0x99
	lsls r2, r2, #4
	adds r4, r6, r2
	ldrh r0, [r4]
	bl Demon_GetRecord
	adds r0, #0x21
	ldrb r0, [r0]
	bl sub_080EF8F8
	ldr r1, .L080E4E54
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq .L080E4E38
	b .L080E51AA
.L080E4E38:
	ldrh r0, [r4]
	ldr r2, .L080E4E50
	adds r1, r6, r2
	ldrh r1, [r1]
	movs r2, #0
	bl sub_080E8C58
	b .L080E51AA
.L080E4E48: .4byte 0x00000998
.L080E4E4C: .4byte 0x0000099A
.L080E4E50: .4byte 0x00000994
.L080E4E54: .4byte 0x00000F6A
.L080E4E58:
	bl sub_080E8D64
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080E4E64
	b .L080E51AA
.L080E4E64:
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	bl sub_080ED67C
	adds r5, r0, #0
	cmp r5, #1
	bls .L080E4EA2
	lsls r4, r5, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r5, #0
	bl sub_080ED32C
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl sub_080EC9AC
	adds r0, r5, #0
	bl sub_080ED32C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080ECF70
.L080E4EA2:
	ldr r2, .L080E4EAC
	adds r1, r6, r2
	movs r0, #2
	b .L080E51A8
	.byte 0x00, 0x00
.L080E4EAC: .4byte 0x00000978
.L080E4EB0:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r4, r6, r0
	ldr r0, [r4]
	bl sub_080ED67C
	adds r5, r0, #0
	ldr r0, [r4]
	cmp r0, #0xff
	bhi .L080E4EC8
	cmp r5, #1
	bne .L080E4ED4
.L080E4EC8:
	ldr r2, .L080E4ED0
	adds r1, r6, r2
	movs r0, #4
	b .L080E51A8
.L080E4ED0: .4byte 0x00000978
.L080E4ED4:
	cmp r5, #0
	bne .L080E4EF4
	movs r1, #0x8d
	lsls r1, r1, #5
	adds r0, r6, r1
	strh r5, [r0]
	ldr r2, .L080E4EF0
	adds r1, r6, r2
	movs r0, #3
	strh r0, [r1]
	movs r0, #0
	bl sub_080E4A40
	b .L080E51AA
.L080E4EF0: .4byte 0x00000978
.L080E4EF4:
	bl sub_080ECB10
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080E4F00
	b .L080E51AA
.L080E4F00:
	ldr r0, .L080E4F08
	adds r1, r6, r0
	movs r0, #4
	b .L080E51A8
.L080E4F08: .4byte 0x00000978
.L080E4F0C:
	movs r1, #0x8d
	lsls r1, r1, #5
	adds r4, r6, r1
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #7
	ble .L080E4F28
	ldr r0, .L080E4F24
	adds r1, r6, r0
	movs r0, #4
	b .L080E51A8
	.byte 0x00, 0x00
.L080E4F24: .4byte 0x00000978
.L080E4F28:
	bl sub_080E8DEC
	ldr r1, .L080E4F4C
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #0
	movs r1, #0
	bl sub_080E845C
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b .L080E51AA
.L080E4F4C: .4byte gUnknown_086BE5A4
.L080E4F50:
	movs r1, #0x99
	lsls r1, r1, #4
	adds r4, r6, r1
	ldr r0, [r4]
	bl sub_080ED67C
	adds r5, r0, #0
	bl sub_080E8DEC
	bl sub_080EDAD0
	cmp r0, #0
	beq .L080E4F76
	ldr r0, [r4]
	bl sub_080EDAEC
	cmp r0, #1
	beq .L080E4F76
	b .L080E5152
.L080E4F76:
	cmp r5, #0
	beq .L080E4F80
	movs r0, #0
	bl sub_080E4A40
.L080E4F80:
	bl sub_080E760C
	bl sub_080E7C98
	ldr r0, .L080E4F94
	ldr r1, .L080E4F98
	bl Task_Create
	str r0, [r6, #0xc]
	b .L080E5152
.L080E4F94: .4byte gUnknown_086BE738
.L080E4F98: .4byte 0x0000FFFF
.L080E4F9C:
	ldr r2, .L080E5014
	adds r7, r6, r2
	ldrh r0, [r7]
	cmp r0, #0
	bne .L080E4FB2
	bl sub_080E8D64
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080E4FB2
	b .L080E51AA
.L080E4FB2:
	ldrh r0, [r7]
	lsls r0, r0, #2
	movs r2, #0x99
	lsls r2, r2, #4
	adds r1, r6, r2
	adds r1, r1, r0
	ldr r0, [r1]
	bl sub_080ED67C
	adds r5, r0, #0
	cmp r5, #1
	bls .L080E500A
	lsls r4, r5, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r5, #0
	bl sub_080ED32C
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl sub_080EC9AC
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r2, r6, r0
	ldr r1, .L080E5018
	ldrh r0, [r7]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2, #0xc]
	adds r0, r5, #0
	bl sub_080ED32C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080ECF70
.L080E500A:
	ldr r2, .L080E501C
	adds r1, r6, r2
	movs r0, #6
	b .L080E51A8
	.byte 0x00, 0x00
.L080E5014: .4byte 0x00001198
.L080E5018: .4byte gUnknown_086BF72C
.L080E501C: .4byte 0x00000978
.L080E5020:
	ldr r0, .L080E5050
	adds r7, r6, r0
	ldrh r0, [r7]
	lsls r0, r0, #2
	movs r1, #0x99
	lsls r1, r1, #4
	adds r4, r6, r1
	adds r0, r4, r0
	ldr r0, [r0]
	bl sub_080ED67C
	adds r5, r0, #0
	ldrh r0, [r7]
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r0, [r4]
	cmp r0, #0xff
	bhi .L080E5048
	cmp r5, #1
	bne .L080E5058
.L080E5048:
	ldr r2, .L080E5054
	adds r1, r6, r2
	movs r0, #8
	b .L080E51A8
.L080E5050: .4byte 0x00001198
.L080E5054: .4byte 0x00000978
.L080E5058:
	cmp r5, #0
	bne .L080E5078
	movs r1, #0x8d
	lsls r1, r1, #5
	adds r0, r6, r1
	strh r5, [r0]
	ldr r2, .L080E5074
	adds r1, r6, r2
	movs r0, #7
	strh r0, [r1]
	ldrh r0, [r7]
	bl sub_080E4A40
	b .L080E51AA
.L080E5074: .4byte 0x00000978
.L080E5078:
	bl sub_080ECB10
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080E5084
	b .L080E51AA
.L080E5084:
	ldr r0, .L080E508C
	adds r1, r6, r0
	movs r0, #8
	b .L080E51A8
.L080E508C: .4byte 0x00000978
.L080E5090:
	movs r1, #0x8d
	lsls r1, r1, #5
	adds r7, r6, r1
	movs r2, #0
	ldrsh r0, [r7, r2]
	cmp r0, #7
	ble .L080E50AC
	ldr r0, .L080E50A8
	adds r1, r6, r0
	movs r0, #8
	b .L080E51A8
	.byte 0x00, 0x00
.L080E50A8: .4byte 0x00000978
.L080E50AC:
	ldr r1, .L080E50D8
	adds r4, r6, r1
	ldrh r0, [r4]
	bl sub_080E8DB4
	ldrb r0, [r4]
	ldr r2, .L080E50DC
	ldrh r1, [r7]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	movs r1, #0
	bl sub_080E845C
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	b .L080E51AA
	.byte 0x00, 0x00
.L080E50D8: .4byte 0x00001198
.L080E50DC: .4byte gUnknown_086BE5A4
.L080E50E0:
	ldr r2, .L080E5134
	adds r4, r6, r2
	ldrh r0, [r4]
	lsls r0, r0, #2
	movs r1, #0x99
	lsls r1, r1, #4
	adds r7, r6, r1
	adds r0, r7, r0
	ldr r0, [r0]
	bl sub_080ED67C
	adds r5, r0, #0
	ldrh r0, [r4]
	bl sub_080E8DB4
	cmp r5, #0
	beq .L080E5108
	ldrh r0, [r4]
	bl sub_080E4A40
.L080E5108:
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080E5140
	bl sub_080EDAD0
	cmp r0, #0
	beq .L080E5120
	ldr r0, [r7]
	bl sub_080EDAEC
	cmp r0, #1
	bne .L080E5148
.L080E5120:
	bl sub_080E760C
	bl sub_080E7C98
	ldr r0, .L080E5138
	ldr r1, .L080E513C
	bl Task_Create
	str r0, [r6, #0xc]
	b .L080E5148
.L080E5134: .4byte 0x00001198
.L080E5138: .4byte gUnknown_086BE738
.L080E513C: .4byte 0x0000FFFF
.L080E5140:
	ldr r2, .L080E5164
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
.L080E5148:
	ldr r1, .L080E5168
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080E5170
.L080E5152:
	ldr r2, .L080E516C
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r0, #1
	mov r1, r8
	strh r0, [r1, #0x1c]
	b .L080E51AA
	.byte 0x00, 0x00
.L080E5164: .4byte 0x0000119C
.L080E5168: .4byte 0x00001198
.L080E516C: .4byte 0x00000978
.L080E5170:
	ldr r2, .L080E5180
	adds r1, r6, r2
	movs r0, #9
	strh r0, [r1]
	ldr r0, .L080E5184
	adds r1, r6, r0
	movs r0, #0x1e
	b .L080E51A8
.L080E5180: .4byte 0x00000978
.L080E5184: .4byte 0x0000119A
.L080E5188:
	ldr r2, .L080E51B4
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080E51AA
	ldr r0, .L080E51B8
	adds r1, r6, r0
	movs r0, #5
	strh r0, [r1]
	subs r2, #2
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
.L080E51A8:
	strh r0, [r1]
.L080E51AA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E51B4: .4byte 0x0000119A
.L080E51B8: .4byte 0x00000978

	thumb_func_start sub_080E51BC
sub_080E51BC: @ 0x080E51BC
	push {lr}
	ldr r0, .L080E51E8
	ldr r1, .L080E51EC
	ldr r2, .L080E51F0
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, .L080E51F4
	str r0, [r1, #4]
	ldr r0, .L080E51F8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L080E51E4
.L080E51DC:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L080E51DC
.L080E51E4:
	pop {r0}
	bx r0
.L080E51E8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E51EC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080E51F0: .4byte 0x0000077A
.L080E51F4: .4byte 0x06000300 @ VRAM+0x300
.L080E51F8: .4byte 0x84000010

	thumb_func_start sub_080E51FC
sub_080E51FC: @ 0x080E51FC
.L080E51FC:
	push {r4, lr}
	ldr r4, .L080E5210
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq .L080E5214
	bl Task_End
	movs r0, #0
	str r0, [r4, #0xc]
	b .L080E5218
.L080E5210: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5214:
	bl sub_080E7484
.L080E5218:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E5220
sub_080E5220: @ 0x080E5220
.L080E5220:
	push {r4, r5, lr}
	ldr r5, .L080E523C
	ldr r0, .L080E5240
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #8
	bls .L080E5230
	b .L080E54CA
.L080E5230:
	lsls r0, r1, #2
	ldr r1, .L080E5244
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080E523C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5240: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E5244: .4byte gUnknown_080E5248
	.global gUnknown_080E5248
gUnknown_080E5248:
.L080E5248: @ jump table
	.4byte .L080E54CA
	.4byte .L080E526C
	.4byte .L080E529C
	.4byte .L080E542C
	.4byte .L080E54CA
	.4byte .L080E54CA
	.4byte .L080E546E
	.4byte .L080E54CA
	.4byte .L080E54B4
.L080E526C:
	ldr r1, .L080E5298
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq .L080E5278
	b .L080E54CA
.L080E5278:
	bl sub_080EF90C
	movs r1, #0x10
	movs r2, #0x30
	movs r3, #0
	bl sub_080C8048
	bl sub_080EF954
	movs r1, #0x10
	movs r2, #0x3c
	movs r3, #0
	bl sub_080C8048
	b .L080E54CA
	.byte 0x00, 0x00
.L080E5298: .4byte 0x00001188
.L080E529C:
	movs r0, #0
	strh r0, [r2]
	ldr r0, [r2, #0x18]
	bl Task_End
	bl sub_080E51FC
	bl sub_08126F14
	movs r4, #0
.L080E52B0:
	adds r0, r4, #0
	bl Combatant_RecalcStats
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls .L080E52B0
	ldr r0, .L080E52D0
	ldrh r0, [r0, #0x14]
	cmp r0, #1
	bne .L080E52D4
	bl sub_080AF018
	b .L080E5320
	.byte 0x00, 0x00
.L080E52D0: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E52D4:
	ldr r0, .L080E52F0
	adds r4, r5, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L080E52FA
	movs r0, #0xdf
	bl Flag_Test
	cmp r0, #0
	beq .L080E52F4
	bl sub_080B9080
	b .L080E5320
.L080E52F0: .4byte 0x00000F6A
.L080E52F4:
	bl sub_080AEFFC
	b .L080E5320
.L080E52FA:
	movs r0, #0xdf
	bl Flag_Test
	cmp r0, #0
	beq .L080E531C
	movs r1, #0
	strh r1, [r4]
	ldr r0, .L080E5318
	strh r1, [r0]
	bl Task_ClearAll
	bl sub_080B9080
	b .L080E5320
	.byte 0x00, 0x00
.L080E5318: .4byte 0x0203DB6A @ EWRAM+0x3DB6A
.L080E531C:
	bl sub_080B08AC
.L080E5320:
	ldr r1, .L080E5368
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080E5352
	ldr r0, .L080E536C
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080E5346
	cmp r0, #2
	beq .L080E5346
	movs r0, #0xdf
	bl Flag_Test
	cmp r0, #0
	bne .L080E5346
	bl sub_080C700C
.L080E5346:
	ldr r1, .L080E5368
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080E5378
.L080E5352:
	ldr r4, .L080E5370
	movs r0, #6
	strh r0, [r4]
	ldr r0, .L080E5374
	bl Flag_Test
	cmp r0, #0
	beq .L080E537C
	movs r0, #8
	strh r0, [r4]
	b .L080E537C
.L080E5368: .4byte 0x00000F6A
.L080E536C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080E5370: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E5374: .4byte 0x0000014F
.L080E5378:
	bl sub_080E9008
.L080E537C:
	bl sub_080C7C94
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r0, #0x83
	lsls r0, r0, #1
	cmp r1, r0
	bne .L080E5392
	b .L080E54CA
.L080E5392:
	adds r0, #0x10
	cmp r1, r0
	bne .L080E539A
	b .L080E54CA
.L080E539A:
	subs r0, #3
	cmp r1, r0
	bne .L080E53A2
	b .L080E54CA
.L080E53A2:
	subs r0, #0xa
	cmp r1, r0
	bne .L080E53B0
	movs r0, #0x14
	bl Music_Play
	b .L080E54CA
.L080E53B0:
	ldr r0, .L080E53EC
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080E5404
	ldr r0, .L080E53F0
	adds r4, r5, r0
	ldr r0, .L080E53F4
	ldrh r0, [r0]
	ldr r1, .L080E53F8
	ldrh r1, [r1]
	bl sub_080AD608
	ldrh r1, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	beq .L080E53E2
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	beq .L080E53FC
.L080E53E2:
	ldrh r0, [r4]
	bl Music_Play
	b .L080E54CA
	.byte 0x00, 0x00
.L080E53EC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E53F0: .4byte 0x0000118A
.L080E53F4: .4byte 0x03004614 @ IWRAM+0x4614
.L080E53F8: .4byte 0x03004514 @ IWRAM+0x4514
.L080E53FC:
	movs r0, #4
	bl Music_FadeOut
	b .L080E54CA
.L080E5404:
	ldr r1, .L080E5424
	adds r4, r5, r1
	ldr r0, .L080E5428
	ldrh r0, [r0, #8]
	bl sub_080AD67C
	ldrh r1, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bne .L080E54CA
	adds r0, r1, #0
	bl Music_Play
	b .L080E54CA
	.byte 0x00, 0x00
.L080E5424: .4byte 0x0000118A
.L080E5428: .4byte 0x030069F0 @ IWRAM+0x69F0
.L080E542C:
	movs r0, #1
	bl Flag_Test
	cmp r0, #0
	beq .L080E5448
	ldr r1, .L080E5444
	movs r0, #7
	strh r0, [r1]
	movs r0, #0xdf
	bl Flag_Set
	b .L080E54CA
.L080E5444: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E5448:
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	beq .L080E5468
	ldr r0, .L080E5460
	movs r1, #7
	strh r1, [r0]
	ldr r0, .L080E5464
	bl Flag_Set
	b .L080E54CA
.L080E5460: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E5464: .4byte 0x0000014F
.L080E5468:
	bl sub_080B9058
	b .L080E54CA
.L080E546E:
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E54CA
	movs r0, #1
	bl Flag_Test
	cmp r0, #0
	beq .L080E548E
	movs r0, #0xdf
	bl Flag_Test
	cmp r0, #0
	bne .L080E54A2
.L080E548E:
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	beq .L080E54C0
	ldr r0, .L080E54AC
	bl Flag_Test
	cmp r0, #0
	beq .L080E54C0
.L080E54A2:
	ldr r1, .L080E54B0
	movs r0, #2
	strh r0, [r1]
	b .L080E54CA
	.byte 0x00, 0x00
.L080E54AC: .4byte 0x0000014F
.L080E54B0: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E54B4:
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E54CA
.L080E54C0:
	ldr r0, .L080E54D0
	movs r2, #0
	movs r1, #4
	strh r1, [r0, #6]
	strh r2, [r0]
.L080E54CA:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E54D0: .4byte 0x030063A0 @ IWRAM+0x63A0

	thumb_func_start sub_080E54D4
sub_080E54D4: @ 0x080E54D4
.L080E54D4:
	push {lr}
	ldr r0, .L080E54E4
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080E54E8
	movs r0, #0
	b .L080E54EA
	.byte 0x00, 0x00
.L080E54E4: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E54E8:
	movs r0, #1
.L080E54EA:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080E54F0
sub_080E54F0: @ 0x080E54F0
	adds r2, r0, #0
	ldr r1, .L080E54FC
	ldr r3, .L080E5500
	adds r1, r1, r3
	strh r2, [r1]
	bx lr
.L080E54FC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5500: .4byte 0x0000118A

	thumb_func_start sub_080E5504
sub_080E5504: @ 0x080E5504
	ldr r1, .L080E5518
	ldr r0, .L080E551C
	str r0, [r1]
	ldr r0, .L080E5520
	str r0, [r1, #4]
	ldr r0, .L080E5524
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080E5518: .4byte 0x040000D4 @ REG_DMA3SAD
.L080E551C: .4byte 0x030000B4 @ IWRAM+0xB4
.L080E5520: .4byte 0x06016000 @ VRAM+0x16000
.L080E5524: .4byte 0x84000400

	thumb_func_start sub_080E5528
sub_080E5528: @ 0x080E5528
	push {r4, lr}
	ldr r4, .L080E55A4
	movs r0, #0xda
	lsls r0, r0, #4
	adds r3, r4, r0
	ldrb r0, [r3, #3]
	cmp r0, #1
	bne .L080E5564
	ldr r2, .L080E55A8
	ldrb r0, [r3, #2]
	lsls r0, r0, #0xc
	ldr r1, .L080E55AC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, .L080E55B0
	str r0, [r2, #4]
	ldr r0, .L080E55B4
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, #0
	bge .L080E5560
.L080E5558:
	ldr r0, [r2, #8]
	ands r0, r1
	cmp r0, #0
	bne .L080E5558
.L080E5560:
	movs r0, #0
	strb r0, [r3, #3]
.L080E5564:
	movs r0, #0xde
	lsls r0, r0, #4
	adds r3, r4, r0
	ldrb r0, [r3, #3]
	cmp r0, #1
	bne .L080E559E
	ldr r2, .L080E55A8
	ldrb r0, [r3, #2]
	adds r0, #2
	lsls r0, r0, #0xc
	ldr r1, .L080E55AC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, .L080E55B8
	str r0, [r2, #4]
	ldr r0, .L080E55B4
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, #0
	bge .L080E559A
.L080E5592:
	ldr r0, [r2, #8]
	ands r0, r1
	cmp r0, #0
	bne .L080E5592
.L080E559A:
	movs r0, #0
	strb r0, [r3, #3]
.L080E559E:
	pop {r4}
	pop {r0}
	bx r0
.L080E55A4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E55A8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080E55AC: .4byte 0x02001000 @ EWRAM+0x1000
.L080E55B0: .4byte 0x06016000 @ VRAM+0x16000
.L080E55B4: .4byte 0x84000400
.L080E55B8: .4byte 0x06017000 @ VRAM+0x17000

	thumb_func_start sub_080E55BC
sub_080E55BC: @ 0x080E55BC
	push {lr}
	ldr r0, .L080E55FC
	movs r1, #0xda
	lsls r1, r1, #4
	adds r3, r0, r1
	ldrb r0, [r3, #3]
	cmp r0, #1
	bne .L080E55F8
	ldr r2, .L080E5600
	ldrb r0, [r3, #2]
	lsls r0, r0, #0xc
	ldr r1, .L080E5604
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, .L080E5608
	str r0, [r2, #4]
	ldr r0, .L080E560C
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, #0
	bge .L080E55F4
.L080E55EC:
	ldr r0, [r2, #8]
	ands r0, r1
	cmp r0, #0
	bne .L080E55EC
.L080E55F4:
	movs r0, #0
	strb r0, [r3, #3]
.L080E55F8:
	pop {r0}
	bx r0
.L080E55FC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5600: .4byte 0x040000D4 @ REG_DMA3SAD
.L080E5604: .4byte 0x02001000 @ EWRAM+0x1000
.L080E5608: .4byte 0x06016000 @ VRAM+0x16000
.L080E560C: .4byte 0x84000400

	thumb_func_start sub_080E5610
sub_080E5610: @ 0x080E5610
	push {lr}
	ldr r0, .L080E5654
	movs r1, #0xde
	lsls r1, r1, #4
	adds r3, r0, r1
	ldrb r0, [r3, #3]
	cmp r0, #1
	bne .L080E564E
	ldr r2, .L080E5658
	ldrb r0, [r3, #2]
	adds r0, #2
	lsls r0, r0, #0xc
	ldr r1, .L080E565C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, .L080E5660
	str r0, [r2, #4]
	ldr r0, .L080E5664
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, #0
	bge .L080E564A
.L080E5642:
	ldr r0, [r2, #8]
	ands r0, r1
	cmp r0, #0
	bne .L080E5642
.L080E564A:
	movs r0, #0
	strb r0, [r3, #3]
.L080E564E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E5654: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5658: .4byte 0x040000D4 @ REG_DMA3SAD
.L080E565C: .4byte 0x02001000 @ EWRAM+0x1000
.L080E5660: .4byte 0x06017000 @ VRAM+0x17000
.L080E5664: .4byte 0x84000400

	thumb_func_start sub_080E5668
sub_080E5668: @ 0x080E5668
.L080E5668:
	push {lr}
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0

	thumb_func_start sub_080E5674
sub_080E5674: @ 0x080E5674
	bx lr
	.byte 0x00, 0x00

	thumb_func_start Demon_LoadGfx
Demon_LoadGfx: @ 0x080E5678
.L080E5678:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	mov sb, r5
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	adds r6, r4, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sl, r3
	ldr r0, .L080E56A8
	cmp r8, r0
	bls .L080E56AC
	movs r0, #0xff
	b .L080E57AE
	.byte 0x00, 0x00
.L080E56A8: .4byte 0x0000017B
.L080E56AC:
	mov r0, r8
	bl Demon_GetGfxRecord
	adds r2, r0, #0
	ldr r7, [r2, #4]
	cmp r5, #0
	bne .L080E56DC
	cmp r4, #0
	bne .L080E56C2
	ldr r0, [r2, #0xc]
	b .L080E56EA
.L080E56C2:
	ldr r0, .L080E56D4
	subs r1, r4, #1
	lsls r1, r1, #0xb
	ldr r2, .L080E56D8
	adds r1, r1, r2
	bl LZ77UnCompWram
	b .L080E571E
	.byte 0x00, 0x00
.L080E56D4: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080E56D8: .4byte 0x030000B4 @ IWRAM+0xB4
.L080E56DC:
	cmp r4, #0
	bne .L080E56FC
	lsls r1, r5, #3
	adds r0, r2, #0
	adds r0, #0xc
	adds r0, r0, r1
	ldr r0, [r0]
.L080E56EA:
	cmp r0, #0
	beq .L080E571E
	ldr r1, .L080E56F8
	bl HuffUnComp
	b .L080E571E
	.byte 0x00, 0x00
.L080E56F8: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080E56FC:
	subs r3, r6, #1
	lsls r0, r3, #2
	mov r4, sb
	lsls r1, r4, #3
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0xc
	adds r1, r1, r0
	ldr r0, [r1]
	cmp r0, #0
	beq .L080E571E
	ldr r0, .L080E5744
	lsls r1, r3, #0xb
	ldr r2, .L080E5748
	adds r1, r1, r2
	bl LZ77UnCompWram
.L080E571E:
	mov r0, sl
	cmp r0, #0xff
	beq .L080E57A2
	lsls r2, r0, #5
	ldr r0, .L080E574C
	adds r5, r2, r0
	ldr r0, .L080E5750
	ldr r1, [r0]
	ldr r0, .L080E5754
	adds r4, r2, #0
	cmp r1, r0
	bne .L080E575C
	mov r0, r8
	bl sub_080C2644
	cmp r0, #0
	bne .L080E575C
	ldr r7, .L080E5758
	b .L080E5764
.L080E5744: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080E5748: .4byte 0x030000B4 @ IWRAM+0xB4
.L080E574C: .4byte 0x03002FB0 @ IWRAM+0x2FB0
.L080E5750: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080E5754: .4byte sub_080D977C
.L080E5758: .4byte gUnknown_086BE584
.L080E575C:
	bl Palette_IsBg13Black
	cmp r0, #0
	bne .L080E577A
.L080E5764:
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r7, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	b .L080E57A2
.L080E577A:
	ldr r2, .L080E57C0
	adds r2, r4, r2
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r7, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	mov r1, sl
	lsls r0, r1, #0x14
	movs r4, #0x80
	lsls r4, r4, #0x11
	adds r0, r0, r4
	lsrs r0, r0, #0x10
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
.L080E57A2:
	ldr r0, .L080E57C4
	ldr r1, .L080E57C8
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	movs r0, #0
.L080E57AE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080E57C0: .4byte 0x03002BB0 @ IWRAM+0x2BB0
.L080E57C4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E57C8: .4byte 0x000011A4

	thumb_func_start sub_080E57CC
sub_080E57CC: @ 0x080E57CC
	push {lr}
	lsls r0, r0, #0x18
	ldr r1, .L080E57EC
	lsrs r0, r0, #0x12
	movs r2, #0xda
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r1, r0, r1
	ldrb r0, [r1, #1]
	cmp r0, #0
	beq .L080E57E6
	subs r0, #1
	strb r0, [r1, #1]
.L080E57E6:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E57EC: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080E57F0
sub_080E57F0: @ 0x080E57F0
	push {r4, r5, lr}
	ldr r5, .L080E5840
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r4, [r0]
	movs r2, #0xda
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r2, #0
	strb r2, [r1, #2]
	strb r2, [r1, #1]
	strb r2, [r1, #5]
	ldrb r0, [r1, #4]
	cmp r0, #2
	beq .L080E5814
	strb r2, [r1, #7]
	strb r2, [r1, #6]
.L080E5814:
	strb r2, [r1, #4]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xe
	bl Demon_LoadGfx
	adds r0, r4, #0
	bl Demon_GetGfxRecord
	ldr r0, .L080E5844
	ldr r2, .L080E5848
	adds r1, r5, r2
	adds r2, r4, #0
	bl sub_080E86B4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E5840: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5844: .4byte 0x03003170 @ IWRAM+0x3170
.L080E5848: .4byte 0x00000DB4

	thumb_func_start sub_080E584C
sub_080E584C: @ 0x080E584C
	push {lr}
	ldr r0, .L080E5868
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0
	movs r2, #1
	movs r3, #0xff
	bl Demon_LoadGfx
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E5868: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080E586C
sub_080E586C: @ 0x080E586C
	push {r4, r5, lr}
	ldr r5, .L080E58B8
	ldr r1, .L080E58BC
	adds r0, r5, r1
	ldr r4, [r0]
	cmp r4, #0xff
	beq .L080E58B0
	movs r2, #0xde
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1, #2]
	strb r0, [r1, #1]
	strb r0, [r1, #4]
	strb r0, [r1, #7]
	strb r0, [r1, #6]
	strb r0, [r1, #5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xf
	bl Demon_LoadGfx
	adds r0, r4, #0
	bl Demon_GetGfxRecord
	ldr r0, .L080E58C0
	ldr r2, .L080E58C4
	adds r1, r5, r2
	adds r2, r4, #0
	bl sub_080E86B4
.L080E58B0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E58B8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E58BC: .4byte 0x00000994
.L080E58C0: .4byte 0x03003190 @ IWRAM+0x3190
.L080E58C4: .4byte 0x00000DF4

	thumb_func_start sub_080E58C8
sub_080E58C8: @ 0x080E58C8
	push {lr}
	ldr r0, .L080E58E8
	ldr r1, .L080E58EC
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0xff
	beq .L080E58E4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	movs r2, #1
	movs r3, #0xff
	bl Demon_LoadGfx
.L080E58E4:
	pop {r0}
	bx r0
.L080E58E8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E58EC: .4byte 0x00000994

	thumb_func_start sub_080E58F0
sub_080E58F0: @ 0x080E58F0
	push {lr}
	lsls r1, r1, #0x18
	ldr r0, .L080E5908
	lsrs r1, r1, #0xc
	ldr r2, .L080E590C
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #3
	bl CpuFastSet
	pop {r0}
	bx r0
.L080E5908: .4byte 0x030000B4 @ IWRAM+0xB4
.L080E590C: .4byte 0x02001000 @ EWRAM+0x1000

	thumb_func_start sub_080E5910
sub_080E5910: @ 0x080E5910
	push {r4, lr}
	lsls r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, .L080E593C
	lsrs r1, r1, #0x16
	movs r4, #0x99
	lsls r4, r4, #4
	adds r0, r0, r4
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r1, r2, #0
	adds r2, r3, #0
	movs r3, #0xff
	bl Demon_LoadGfx
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E593C: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080E5940
sub_080E5940: @ 0x080E5940
	push {lr}
	ldr r0, .L080E597C
	ldr r2, .L080E5980
	str r2, [r0]
	ldr r1, .L080E5984
	str r1, [r0, #4]
	ldr r3, .L080E5988
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r2, r2, r1
	str r2, [r0]
	ldr r1, .L080E598C
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	adds r2, r0, #0
	ldr r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, #0
	bge .L080E5976
.L080E596E:
	ldr r0, [r2, #8]
	ands r0, r1
	cmp r0, #0
	bne .L080E596E
.L080E5976:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E597C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080E5980: .4byte 0x02001000 @ EWRAM+0x1000
.L080E5984: .4byte 0x06016000 @ VRAM+0x16000
.L080E5988: .4byte 0x84000400
.L080E598C: .4byte 0x06017000 @ VRAM+0x17000

	thumb_func_start sub_080E5990
sub_080E5990: @ 0x080E5990
	push {lr}
	ldr r1, .L080E59B8
	ldr r0, .L080E59BC
	str r0, [r1]
	ldr r0, .L080E59C0
	str r0, [r1, #4]
	ldr r0, .L080E59C4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L080E59B4
.L080E59AC:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L080E59AC
.L080E59B4:
	pop {r0}
	bx r0
.L080E59B8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080E59BC: .4byte 0x02001000 @ EWRAM+0x1000
.L080E59C0: .4byte 0x06016000 @ VRAM+0x16000
.L080E59C4: .4byte 0x84000800

	thumb_func_start sub_080E59C8
sub_080E59C8: @ 0x080E59C8
	push {lr}
	adds r2, r1, #0
	ldr r0, .L080E59FC
	lsls r1, r2, #2
	movs r3, #0x99
	lsls r3, r3, #4
	adds r0, r0, r3
	adds r1, r1, r0
	ldrh r1, [r1]
	ldr r0, .L080E5A00
	cmp r1, r0
	beq .L080E5A10
	cmp r2, #0
	bne .L080E5A10
	adds r0, r1, #0
	bl Demon_GetGfxRecord
	ldr r0, [r0, #0x14]
	cmp r0, #0
	beq .L080E5A08
	ldr r0, .L080E5A04
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080E5A10
	.byte 0x00, 0x00
.L080E59FC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5A00: .4byte 0x0000FFFF
.L080E5A04: .4byte sub_080E5990
.L080E5A08:
	ldr r0, .L080E5A14
	movs r1, #1
	bl VBlankTask_AddCounted
.L080E5A10:
	pop {r0}
	bx r0
.L080E5A14: .4byte sub_080E5940

	thumb_func_start sub_080E5A18
sub_080E5A18: @ 0x080E5A18
.L080E5A18:
	push {r4, lr}
	ldr r1, .L080E5A30
	ldr r3, .L080E5A34
	ldr r2, .L080E5A38
	adds r1, r1, r2
	movs r4, #0
	ldrsh r2, [r1, r4]
	str r2, [r3]
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L080E5A30: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5A34: .4byte 0x03000058 @ IWRAM+0x58
.L080E5A38: .4byte 0x0000097A

	thumb_func_start sub_080E5A3C
sub_080E5A3C: @ 0x080E5A3C
.L080E5A3C:
	ldr r0, .L080E5A4C
	ldr r1, .L080E5A50
	ldr r1, [r1]
	ldr r2, .L080E5A54
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080E5A4C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5A50: .4byte 0x03000058 @ IWRAM+0x58
.L080E5A54: .4byte 0x0000097A

	thumb_func_start sub_080E5A58
sub_080E5A58: @ 0x080E5A58
	push {r4, r5, r6, r7, lr}
	ldr r7, .L080E5A6C
	ldr r2, .L080E5A70
	cmp r1, #1
	beq .L080E5A74
	cmp r1, #2
	bne .L080E5A68
	b .L080E5B94
.L080E5A68:
	b .L080E5BD4
	.byte 0x00, 0x00
.L080E5A6C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5A70: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E5A74:
	ldr r1, .L080E5A9C
	adds r0, r7, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r1, r2, r3
	adds r0, r0, r1
	ldrb r4, [r0]
	adds r0, r4, #0
	bl sub_080F3040
	cmp r0, #0
	bne .L080E5AA4
	ldr r0, .L080E5AA0
	adds r1, r7, r0
	movs r0, #3
	strh r0, [r1]
	b .L080E5BD4
	.byte 0x00, 0x00
.L080E5A9C: .4byte 0x00000F66
.L080E5AA0: .4byte 0x0000097A
.L080E5AA4:
	cmp r4, #0
	beq .L080E5AC4
	cmp r4, #0
	blt .L080E5B52
	cmp r4, #3
	bgt .L080E5B52
	movs r6, #3
	movs r5, #0
	adds r0, r4, #0
	movs r1, #0
	bl Combatant_GetEquip
	cmp r0, #0xff
	bne .L080E5B02
	movs r5, #1
	b .L080E5B02
.L080E5AC4:
	movs r6, #2
	movs r5, #0
	movs r0, #0
	movs r1, #0
	bl Combatant_GetEquip
	cmp r0, #0xff
	bne .L080E5AD6
	movs r5, #1
.L080E5AD6:
	movs r0, #0
	movs r1, #1
	bl Combatant_GetEquip
	cmp r0, #0xff
	beq .L080E5AEE
	movs r0, #0
	movs r1, #6
	bl Combatant_GetEquip
	cmp r0, #0xff
	bne .L080E5AF2
.L080E5AEE:
	movs r0, #2
	orrs r5, r0
.L080E5AF2:
	movs r0, #3
	bl Flag_Test
	cmp r0, #0
	beq .L080E5B34
	bl sub_080F3190
	b .L080E5B30
.L080E5B02:
	adds r0, r4, #0
	movs r1, #1
	bl Combatant_GetEquip
	cmp r0, #0xff
	beq .L080E5B1A
	adds r0, r4, #0
	movs r1, #6
	bl Combatant_GetEquip
	cmp r0, #0xff
	bne .L080E5B22
.L080E5B1A:
	movs r0, #2
	orrs r5, r0
	lsls r0, r5, #0x18
	lsrs r5, r0, #0x18
.L080E5B22:
	adds r0, r4, #0
	bl sub_080F4410
	cmp r0, #2
	bne .L080E5B34
	bl sub_080F31E0
.L080E5B30:
	cmp r0, #0
	beq .L080E5B3C
.L080E5B34:
	movs r0, #4
	orrs r5, r0
	lsls r0, r5, #0x18
	lsrs r5, r0, #0x18
.L080E5B3C:
	movs r0, #1
	bl sub_0812B3A4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080E5B7A
	movs r0, #8
	orrs r5, r0
	lsls r0, r5, #0x18
	lsrs r5, r0, #0x18
	b .L080E5B7A
.L080E5B52:
	movs r6, #4
	movs r5, #0
	movs r0, #2
	adds r1, r4, #0
	bl BattleMenu_BuildSkillList
	cmp r0, #0
	bne .L080E5B64
	movs r5, #2
.L080E5B64:
	adds r0, r4, #0
	bl sub_080F4410
	cmp r0, #2
	bne .L080E5B76
	bl sub_080F31E0
	cmp r0, #0
	beq .L080E5B7A
.L080E5B76:
	movs r0, #4
	orrs r5, r0
.L080E5B7A:
	adds r0, r6, #0
	adds r1, r5, #0
	bl sub_08126D50
	ldr r1, .L080E5B90
	adds r0, r7, r1
	strb r5, [r0]
	bl sub_080C7AE0
	b .L080E5BAA
	.byte 0x00, 0x00
.L080E5B90: .4byte 0x00001121
.L080E5B94:
	movs r6, #5
	movs r5, #0
	movs r0, #5
	movs r1, #0
	bl sub_08126D50
	ldr r3, .L080E5BDC
	adds r0, r7, r3
	strb r5, [r0]
	bl sub_080C7AE0
.L080E5BAA:
	ldr r1, .L080E5BE0
	adds r0, r7, r1
	strb r6, [r0]
	ldr r1, .L080E5BE4
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, .L080E5BE8
	movs r0, #0xb0
	strb r0, [r1]
	ldr r1, .L080E5BEC
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, .L080E5BF0
	movs r0, #0x58
	strb r0, [r1]
	ldr r1, .L080E5BF4
	movs r0, #0x1f
	strb r0, [r1]
	ldr r1, .L080E5BF8
	movs r0, #0x3f
	strb r0, [r1]
.L080E5BD4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E5BDC: .4byte 0x00001121
.L080E5BE0: .4byte 0x00000693
.L080E5BE4: .4byte 0x03000030 @ IWRAM+0x30
.L080E5BE8: .4byte 0x03000031 @ IWRAM+0x31
.L080E5BEC: .4byte 0x03000035 @ IWRAM+0x35
.L080E5BF0: .4byte 0x03000034 @ IWRAM+0x34
.L080E5BF4: .4byte 0x03000038 @ IWRAM+0x38
.L080E5BF8: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080E5BFC
sub_080E5BFC: @ 0x080E5BFC
	push {r4, r5, lr}
	sub sp, #0x2c
	ldr r5, .L080E5CA0
	movs r0, #1
	movs r1, #0
	bl sub_08126D50
	bl sub_080C7AE0
	bl sub_08126870
	movs r4, #0
	str r4, [sp, #0x28]
	add r0, sp, #0x28
	ldr r2, .L080E5CA4
	mov r1, sp
	bl CpuSet
	mov r0, sp
	movs r1, #1
	strb r1, [r0]
	strb r4, [r0, #1]
	strb r4, [r0, #2]
	strb r1, [r0, #3]
	strh r1, [r0, #6]
	movs r1, #4
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	strh r4, [r0, #0xc]
	strh r4, [r0, #0xe]
	strh r1, [r0, #0x10]
	strh r4, [r0, #0x12]
	strh r4, [r0, #0x14]
	strh r4, [r0, #0x16]
	strh r4, [r0, #0x18]
	mov r2, sp
	mov r1, sp
	movs r0, #0x64
	strh r0, [r1, #0x1c]
	strh r0, [r2, #0x1a]
	movs r0, #0x65
	strh r0, [r1, #0x1e]
	movs r0, #0x66
	strh r0, [r1, #0x20]
	mov r3, sp
	ldr r0, .L080E5CA8
	strh r0, [r1, #0x26]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r2, #0x24]
	strh r0, [r3, #0x22]
	movs r0, #0
	bl sub_081268E4
	ldr r1, .L080E5CAC
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, .L080E5CB0
	movs r0, #0xb0
	strb r0, [r1]
	ldr r1, .L080E5CB4
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, .L080E5CB8
	movs r0, #0x58
	strb r0, [r1]
	ldr r1, .L080E5CBC
	movs r0, #0x1f
	strb r0, [r1]
	ldr r1, .L080E5CC0
	movs r0, #0x3f
	strb r0, [r1]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r5, r5, r0
	movs r0, #0xff
	strb r0, [r5]
	add sp, #0x2c
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E5CA0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5CA4: .4byte 0x0500000A @ PLTT+0xA
.L080E5CA8: .4byte 0x0000FFFF
.L080E5CAC: .4byte 0x03000030 @ IWRAM+0x30
.L080E5CB0: .4byte 0x03000031 @ IWRAM+0x31
.L080E5CB4: .4byte 0x03000035 @ IWRAM+0x35
.L080E5CB8: .4byte 0x03000034 @ IWRAM+0x34
.L080E5CBC: .4byte 0x03000038 @ IWRAM+0x38
.L080E5CC0: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080E5CC4
sub_080E5CC4: @ 0x080E5CC4
	push {lr}
	adds r3, r0, #0
	movs r0, #0
	strh r0, [r3, #0x1c]
	ldr r0, .L080E5CF8
	ldrb r1, [r0]
	adds r1, #8
	strb r1, [r0]
	ldr r2, .L080E5CFC
	ldrb r0, [r2]
	subs r0, #8
	strb r0, [r2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x77
	bls .L080E5CF4
	ldr r0, .L080E5D00
	movs r1, #0x1f
	strb r1, [r0]
	movs r0, #1
	strh r0, [r3, #0x1c]
	movs r0, #0x67
	bl sub_080ECF70
.L080E5CF4:
	pop {r0}
	bx r0
.L080E5CF8: .4byte 0x03000031 @ IWRAM+0x31
.L080E5CFC: .4byte 0x03000030 @ IWRAM+0x30
.L080E5D00: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080E5D04
sub_080E5D04: @ 0x080E5D04
	push {lr}
	adds r3, r0, #0
	movs r0, #0
	strh r0, [r3, #0x1c]
	ldr r2, .L080E5D30
	ldrb r0, [r2]
	subs r0, #2
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x48
	bhi .L080E5D2A
	ldr r1, .L080E5D34
	movs r0, #0x1f
	strb r0, [r1]
	movs r0, #0x58
	strb r0, [r2]
	movs r0, #1
	strh r0, [r3, #0x1c]
.L080E5D2A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E5D30: .4byte 0x03000034 @ IWRAM+0x34
.L080E5D34: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080E5D38
sub_080E5D38: @ 0x080E5D38
	push {lr}
	bl sub_080C7ACC
	ldr r0, .L080E5D58
	movs r1, #0xf0
	strb r1, [r0]
	ldr r0, .L080E5D5C
	strb r1, [r0]
	ldr r0, .L080E5D60
	movs r1, #0x48
	strb r1, [r0]
	ldr r0, .L080E5D64
	strb r1, [r0]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E5D58: .4byte 0x03000030 @ IWRAM+0x30
.L080E5D5C: .4byte 0x03000031 @ IWRAM+0x31
.L080E5D60: .4byte 0x03000034 @ IWRAM+0x34
.L080E5D64: .4byte 0x03000035 @ IWRAM+0x35

	thumb_func_start sub_080E5D68
sub_080E5D68: @ 0x080E5D68
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0
	strh r0, [r5, #0x1c]
	ldr r4, .L080E5D98
	ldrb r0, [r4]
	adds r0, #8
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x57
	bls .L080E5D92
	ldr r1, .L080E5D9C
	movs r0, #0x3f
	strb r0, [r1]
	bl sub_08126F14
	movs r0, #0x58
	strb r0, [r4]
	movs r0, #1
	strh r0, [r5, #0x1c]
.L080E5D92:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E5D98: .4byte 0x03000034 @ IWRAM+0x34
.L080E5D9C: .4byte 0x03000038 @ IWRAM+0x38

	thumb_func_start sub_080E5DA0
sub_080E5DA0: @ 0x080E5DA0
.L080E5DA0:
	push {r4, lr}
	ldr r0, .L080E5DCC
	movs r2, #0
	ldr r1, .L080E5DD0
	adds r3, r1, #0
	movs r4, #0xef
	lsls r4, r4, #4
	adds r1, r0, r4
.L080E5DB0:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	ldrh r0, [r1, #0x20]
	orrs r0, r3
	strh r0, [r1, #0x20]
	adds r1, #2
	adds r2, #1
	cmp r2, #0xf
	bls .L080E5DB0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E5DCC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5DD0: .4byte 0x0000FFFF

	thumb_func_start sub_080E5DD4
sub_080E5DD4: @ 0x080E5DD4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r0
	ldr r7, .L080E5E7C
	movs r0, #0
	bl sub_08126D1C
	mov r8, r0
	ldrh r5, [r0, #0x18]
	movs r0, #0
	bl sub_08126A08
	ldr r0, .L080E5E80
	movs r4, #0
	str r4, [sp]
	movs r1, #0xb6
	str r1, [sp, #4]
	ldr r2, .L080E5E84
	mov r3, r8
	ldrh r1, [r3, #0x18]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	mov r0, sb
	strh r4, [r0, #0x1c]
	mov r2, r8
	ldrh r1, [r2, #0x18]
	ldr r3, .L080E5E88
	adds r0, r7, r3
	strh r1, [r0]
	ldr r1, .L080E5E8C
	adds r0, r7, r1
	strh r4, [r0]
	ldrh r2, [r2, #0x18]
	cmp r5, r2
	beq .L080E5E4C
	movs r3, #0xfc
	lsls r3, r3, #3
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #4
	bne .L080E5E4C
	ldr r0, .L080E5E90
	mov r2, r8
	ldrh r1, [r2, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L080E5E4C:
	ldr r0, .L080E5E94
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080E5E60
	movs r0, #3
	mov r3, r8
	strb r0, [r3]
	strh r0, [r3, #0x18]
.L080E5E60:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #3
	beq .L080E5E6A
	b .L080E5FA8
.L080E5E6A:
	ldrh r4, [r1, #0x18]
	cmp r4, #1
	beq .L080E5F36
	cmp r4, #1
	bgt .L080E5E98
	cmp r4, #0
	beq .L080E5EA2
	b .L080E5F78
	.byte 0x00, 0x00
.L080E5E7C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E5E80: .4byte gUnknown_080008B0
.L080E5E84: .4byte gUnknown_086BE5D2
.L080E5E88: .4byte 0x00000F64
.L080E5E8C: .4byte 0x00000F62
.L080E5E90: .4byte gUnknown_086BE5EC
.L080E5E94: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E5E98:
	cmp r4, #2
	beq .L080E5F44
	cmp r4, #3
	beq .L080E5F50
	b .L080E5F78
.L080E5EA2:
	bl sub_080E5DA0
	ldr r2, .L080E5EC8
	adds r1, r7, r2
	movs r0, #9
	strh r0, [r1]
	ldr r3, .L080E5ECC
	adds r0, r7, r3
	strh r4, [r0]
	ldr r1, .L080E5ED0
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, .L080E5ED4
	adds r0, r7, r2
	strh r4, [r0]
	movs r4, #0
	adds r6, r7, r1
	adds r5, r0, #0
	b .L080E5EEA
.L080E5EC8: .4byte 0x00000978
.L080E5ECC: .4byte 0x0000097A
.L080E5ED0: .4byte 0x00000F66
.L080E5ED4: .4byte 0x000011AA
.L080E5ED8:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
.L080E5EEA:
	cmp r4, #5
	bhi .L080E5EFC
	adds r0, r4, #0
	bl sub_080F30CC
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L080E5ED8
.L080E5EFC:
	ldr r3, .L080E5F20
	adds r0, r7, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_080F30CC
	ldr r2, .L080E5F24
	adds r1, r7, r2
	strh r0, [r1]
	ldr r3, .L080E5F28
	adds r0, r7, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080E5F2C
	bl sub_080C6FF0
	b .L080E5F30
.L080E5F20: .4byte 0x00000F66
.L080E5F24: .4byte 0x00000ECE
.L080E5F28: .4byte 0x00000F6A
.L080E5F2C:
	bl sub_080C7038
.L080E5F30:
	bl sub_080EC948
	b .L080E5F78
.L080E5F36:
	ldr r2, .L080E5F40
	adds r1, r7, r2
	movs r0, #0xb
	b .L080E5F76
	.byte 0x00, 0x00
.L080E5F40: .4byte 0x00000978
.L080E5F44:
	ldr r3, .L080E5F4C
	adds r1, r7, r3
	movs r0, #0xc
	b .L080E5F76
.L080E5F4C: .4byte 0x00000978
.L080E5F50:
	ldr r1, .L080E5F64
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080E5F68
	bl sub_080C6FF0
	b .L080E5F6C
	.byte 0x00, 0x00
.L080E5F64: .4byte 0x00000F6A
.L080E5F68:
	bl sub_080C7038
.L080E5F6C:
	bl sub_080EC948
	ldr r3, .L080E5FA0
	adds r1, r7, r3
	movs r0, #0xd
.L080E5F76:
	strh r0, [r1]
.L080E5F78:
	ldr r0, .L080E5FA4
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	mov r1, sb
	strh r0, [r1, #0x1c]
	mov r2, r8
	ldrh r1, [r2, #0x18]
	movs r3, #0xd2
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	movs r0, #0
	bl sub_081269B0
	bl BattleMenu_Reset
	b .L080E5FDE
	.byte 0x00, 0x00
.L080E5FA0: .4byte 0x00000978
.L080E5FA4: .4byte 0x0000097A
.L080E5FA8:
	cmp r0, #6
	bne .L080E5FDE
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L080E5FCC
	ldr r1, .L080E5FC8
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	b .L080E5FDE
.L080E5FC8: .4byte gUnknown_086BE5DA
.L080E5FCC:
	ldr r0, .L080E5FEC
	mov r2, r8
	ldrh r1, [r2, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L080E5FDE:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E5FEC: .4byte gUnknown_086BE5EC

	thumb_func_start sub_080E5FF0
sub_080E5FF0: @ 0x080E5FF0
	push {r4, r5, r6, lr}
	sub sp, #0x2c
	ldr r6, .L080E6084
	movs r4, #0
	str r4, [sp, #0x28]
	add r0, sp, #0x28
	ldr r2, .L080E6088
	mov r1, sp
	bl CpuSet
	mov r0, sp
	movs r1, #1
	strb r1, [r0]
	strb r4, [r0, #1]
	strb r4, [r0, #2]
	strb r1, [r0, #3]
	strh r1, [r0, #6]
	movs r1, #5
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	strh r4, [r0, #0xc]
	strh r4, [r0, #0xe]
	strh r1, [r0, #0x10]
	strh r4, [r0, #0x12]
	strh r4, [r0, #0x14]
	strh r4, [r0, #0x16]
	strh r4, [r0, #0x18]
	mov r2, sp
	mov r1, sp
	movs r0, #0x64
	strh r0, [r1, #0x1c]
	strh r0, [r2, #0x1a]
	movs r0, #0x65
	strh r0, [r1, #0x1e]
	movs r0, #0x66
	strh r0, [r1, #0x20]
	mov r3, sp
	ldr r0, .L080E608C
	strh r0, [r1, #0x26]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r2, #0x24]
	strh r0, [r3, #0x22]
	movs r0, #0
	bl sub_081268E4
	ldr r1, .L080E6090
	ldr r0, .L080E6094
	adds r4, r6, r0
	movs r2, #0
	ldrsh r0, [r4, r2]
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r1, r1, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl sub_080C3620
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r0, [r4]
	bl sub_080E6130
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0
	ldr r3, .L080E6098
	lsls r1, r0, #2
	adds r1, r1, r0
	adds r0, r1, r3
	b .L080E60AA
	.byte 0x00, 0x00
.L080E6084: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6088: .4byte 0x0500000A @ PLTT+0xA
.L080E608C: .4byte 0x0000FFFF
.L080E6090: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E6094: .4byte 0x00000F66
.L080E6098: .4byte gUnknown_086BE610
.L080E609C:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #4
	bhi .L080E60B0
	adds r0, r2, r1
	adds r0, r0, r3
.L080E60AA:
	ldrb r0, [r0]
	cmp r5, r0
	bne .L080E609C
.L080E60B0:
	cmp r2, #5
	bne .L080E60B6
	movs r2, #0
.L080E60B6:
	movs r0, #0
	adds r1, r2, #0
	bl MenuCursor_SetIndex
	ldr r0, .L080E6124
	adds r4, r6, r0
	ldrb r0, [r4]
	bl Battle_BuildActorPrompt
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	movs r1, #0
	ldrsh r0, [r4, r1]
	bl sub_080C8490
	ldr r2, .L080E6128
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r2, r2, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	movs r3, #0xef
	lsls r3, r3, #4
	adds r1, r6, r3
	adds r1, r1, r0
	ldr r0, .L080E612C
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	movs r2, #0xf1
	lsls r2, r2, #4
	adds r1, r6, r2
	adds r1, r1, r0
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	add sp, #0x2c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080E6124: .4byte 0x00000F66
.L080E6128: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E612C: .4byte 0x0000FFFF

	thumb_func_start sub_080E6130
sub_080E6130: @ 0x080E6130
.L080E6130:
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L080E6150
	movs r2, #2
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r1, r1, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L080E6154
	movs r2, #0
	b .L080E615E
.L080E6150: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E6154:
	cmp r0, #0
	blt .L080E615E
	cmp r0, #3
	bgt .L080E615E
	movs r2, #1
.L080E615E:
	adds r0, r2, #0
	pop {r1}
	bx r1

	thumb_func_start sub_080E6164
sub_080E6164: @ 0x080E6164
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r6, .L080E61E0
	movs r0, #0
	bl sub_08126D1C
	mov r8, r0
	ldrh r0, [r0, #0x18]
	mov sb, r0
	movs r0, #0
	bl sub_08126A08
	ldr r4, .L080E61E4
	ldr r1, .L080E61E8
	adds r7, r6, r1
	ldrb r0, [r7]
	bl sub_080E6130
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	mov r2, r8
	ldrh r2, [r2, #0x18]
	adds r1, r1, r2
	adds r1, r1, r4
	ldrb r2, [r1]
	adds r1, r2, #0
	movs r0, #0
	strh r0, [r5, #0x1c]
	ldr r3, .L080E61EC
	adds r4, r6, r3
	strh r0, [r4]
	mov r3, r8
	ldrb r0, [r3]
	cmp r0, #4
	bne .L080E6204
	movs r0, #1
	strh r0, [r5, #0x1c]
	ldr r1, .L080E61F0
	adds r0, r6, r1
	adds r1, r7, #0
	bl sub_080F2FEC
	movs r2, #0
	ldrsh r0, [r7, r2]
	cmp r0, #0
	blt .L080E61D4
	movs r3, #0
	ldrsh r2, [r4, r3]
	cmp r2, #0
	beq .L080E61F8
.L080E61D4:
	ldr r0, .L080E61F4
	adds r1, r6, r0
	movs r0, #6
	strh r0, [r1]
	b .L080E62AA
	.byte 0x00, 0x00
.L080E61E0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E61E4: .4byte gUnknown_086BE610
.L080E61E8: .4byte 0x00000F66
.L080E61EC: .4byte 0x00000F62
.L080E61F0: .4byte 0x00000ECE
.L080E61F4: .4byte 0x00000978
.L080E61F8:
	ldr r1, .L080E6200
	adds r0, r6, r1
	strh r2, [r0]
	b .L080E62AA
.L080E6200: .4byte 0x0000097A
.L080E6204:
	cmp r0, #3
	bne .L080E624C
	movs r0, #1
	strh r0, [r5, #0x1c]
	mov r3, r8
	ldrh r1, [r3, #0x18]
	movs r3, #0xd2
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r1, [r0]
	ldr r0, .L080E6244
	movs r3, #0
	ldrsh r1, [r7, r3]
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r0, r0, r3
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r1, r2, #0
	bl sub_080C35C4
	movs r1, #0
	ldrsh r0, [r7, r1]
	bl sub_080C8480
	ldr r2, .L080E6248
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
	b .L080E62AA
	.byte 0x00, 0x00
.L080E6244: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E6248: .4byte 0x0000097A
.L080E624C:
	cmp r0, #6
	bne .L080E6288
	movs r3, #0xfc
	lsls r3, r3, #3
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #4
	bne .L080E6272
	ldrb r0, [r7]
	bl Battle_BuildActorPrompt
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	b .L080E62AA
.L080E6272:
	ldr r0, .L080E6284
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
	b .L080E62AA
	.byte 0x00, 0x00
.L080E6284: .4byte gUnknown_086BE620
.L080E6288:
	mov r0, r8
	ldrh r0, [r0, #0x18]
	cmp sb, r0
	beq .L080E62AA
	movs r2, #0xfc
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #4
	bne .L080E62AA
	ldr r0, .L080E62DC
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L080E62AA:
	ldr r0, .L080E62E0
	movs r1, #0
	str r1, [sp]
	movs r1, #0xb6
	str r1, [sp, #4]
	ldr r2, .L080E62E4
	mov r3, r8
	ldrh r1, [r3, #0x18]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E62DC: .4byte gUnknown_086BE620
.L080E62E0: .4byte gUnknown_080008B0
.L080E62E4: .4byte gUnknown_086BE606

	thumb_func_start sub_080E62E8
sub_080E62E8: @ 0x080E62E8
	push {r4, lr}
	ldr r4, .L080E630C
	ldr r0, .L080E6310
	adds r4, r4, r0
	movs r0, #0
	bl YesNo_Create
	str r0, [r4, #4]
	ldr r1, .L080E6314
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	pop {r4}
	pop {r0}
	bx r0
.L080E630C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6310: .4byte 0x0000110C
.L080E6314: .4byte gUnknown_081230DC

	thumb_func_start sub_080E6318
sub_080E6318: @ 0x080E6318
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r5, .L080E637C
	ldr r0, .L080E6380
	adds r0, r0, r5
	mov sb, r0
	movs r1, #0
	mov r8, r1
	mov r0, r8
	strh r0, [r7, #0x1c]
	ldr r0, .L080E6384
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq .L080E6394
	ldr r1, .L080E6388
	adds r0, r5, r1
	adds r1, #0x98
	adds r4, r5, r1
	adds r1, r4, #0
	bl sub_080F2FEC
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge .L080E6360
	ldr r0, .L080E638C
	adds r1, r5, r0
	movs r0, #6
	strh r0, [r1]
.L080E6360:
	ldr r1, .L080E6390
	adds r0, r5, r1
	mov r1, r8
	strh r1, [r0]
	mov r1, sb
	ldr r0, [r1, #4]
	bl Task_End
	movs r0, #1
	strh r0, [r7, #0x1c]
	movs r0, #0x66
	bl sub_080ECF70
	b .L080E63F0
.L080E637C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6380: .4byte 0x0000110C
.L080E6384: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E6388: .4byte 0x00000ECE
.L080E638C: .4byte 0x00000978
.L080E6390: .4byte 0x0000097A
.L080E6394:
	mov r1, sb
	ldr r0, [r1, #4]
	bl Task_IsFree
	cmp r0, #1
	bne .L080E63F0
	ldr r0, .L080E63BC
	ldr r0, [r0]
	cmp r0, #1
	beq .L080E63C8
	cmp r0, #0
	bne .L080E63C8
	ldr r1, .L080E63C0
	adds r0, r5, r1
	strh r6, [r0]
	ldr r0, .L080E63C4
	adds r1, r5, r0
	movs r0, #0xa
	b .L080E63E4
	.byte 0x00, 0x00
.L080E63BC: .4byte 0x030031CC @ IWRAM+0x31CC
.L080E63C0: .4byte 0x00000ECE
.L080E63C4: .4byte 0x00000978
.L080E63C8:
	ldr r1, .L080E63FC
	adds r0, r5, r1
	adds r1, #0x98
	adds r4, r5, r1
	adds r1, r4, #0
	bl sub_080F2FEC
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge .L080E63E6
	ldr r0, .L080E6400
	adds r1, r5, r0
	movs r0, #6
.L080E63E4:
	strh r0, [r1]
.L080E63E6:
	ldr r1, .L080E6404
	adds r0, r5, r1
	strh r6, [r0]
	movs r0, #1
	strh r0, [r7, #0x1c]
.L080E63F0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E63FC: .4byte 0x00000ECE
.L080E6400: .4byte 0x00000978
.L080E6404: .4byte 0x0000097A

	thumb_func_start sub_080E6408
sub_080E6408: @ 0x080E6408
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r5, .L080E645C
	movs r0, #0
	bl sub_08126A08
	movs r0, #0
	bl sub_08126D1C
	adds r3, r0, #0
	movs r2, #0
	strh r2, [r4, #0x1c]
	ldrb r0, [r3]
	cmp r0, #3
	bne .L080E6436
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldrh r1, [r3, #0x16]
	movs r4, #0xd2
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r1, [r0]
.L080E6436:
	ldr r0, .L080E6460
	str r2, [sp]
	ldr r2, .L080E6464
	ldrh r1, [r3, #0x16]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #0x4a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E645C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6460: .4byte gUnknown_08000868
.L080E6464: .4byte gUnknown_086BE5FC

	thumb_func_start sub_080E6468
sub_080E6468: @ 0x080E6468
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r6, .L080E64D4
	movs r0, #0x89
	lsls r0, r0, #5
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0
	strb r1, [r0]
	ldr r2, .L080E64D8
	adds r0, r6, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	ldr r1, .L080E64DC
	ldr r0, .L080E64E0
	adds r7, r6, r0
	movs r2, #0
	ldrsh r0, [r7, r2]
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r5, r1, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl sub_080C35E4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r1, #0
	ldrsh r0, [r7, r1]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r4, #0
	mov r2, sp
	bl Battle_CanUseCommand
	cmp r0, #0
	beq .L080E651C
	subs r0, r4, #4
	cmp r0, #8
	bhi .L080E650C
	lsls r0, r0, #2
	ldr r1, .L080E64E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080E64D4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E64D8: .4byte 0x0000097C
.L080E64DC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E64E0: .4byte 0x00000F66
.L080E64E4: .4byte gUnknown_080E64E8
	.global gUnknown_080E64E8
gUnknown_080E64E8:
.L080E64E8: @ jump table
	.4byte .L080E6544
	.4byte .L080E6544
	.4byte .L080E6544
	.4byte .L080E6544
	.4byte .L080E6544
	.4byte .L080E650C
	.4byte .L080E6544
	.4byte .L080E6544
	.4byte .L080E650C
.L080E650C:
	ldr r2, .L080E6518
	adds r1, r6, r2
	movs r0, #3
	strh r0, [r1]
	b .L080E6544
	.byte 0x00, 0x00
.L080E6518: .4byte 0x0000097A
.L080E651C:
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetMessage
	movs r2, #0
	ldrsh r1, [r7, r2]
	adds r1, r1, r5
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
.L080E6544:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080E6550
sub_080E6550: @ 0x080E6550
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r5, .L080E65B8
	movs r6, #0
	strh r6, [r7, #0x1c]
	ldr r0, .L080E65BC
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	beq .L080E65CC
	ldr r1, .L080E65C0
	ldr r2, .L080E65C4
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r1, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl sub_080C35E4
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r2, #0x89
	lsls r2, r2, #5
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne .L080E659A
	movs r1, #0xd
.L080E659A:
	subs r0, r1, #4
	lsls r0, r0, #0x18
	ldr r1, .L080E65C8
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne .L080E6604
	b .L080E6600
	.byte 0x00, 0x00
.L080E65B8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E65BC: .4byte 0x0000097A
.L080E65C0: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E65C4: .4byte 0x00000F66
.L080E65C8: .4byte gUnknown_086BE654
.L080E65CC:
	ldr r1, .L080E65F0
	adds r0, r5, r1
	ldr r2, .L080E65F4
	adds r4, r5, r2
	adds r1, r4, #0
	bl sub_080F2F94
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #5
	ble .L080E65FC
	ldr r2, .L080E65F8
	adds r0, r5, r2
	strh r6, [r0]
	movs r0, #4
	mov r1, r8
	strh r0, [r1]
	b .L080E6600
.L080E65F0: .4byte 0x00000ECE
.L080E65F4: .4byte 0x00000F66
.L080E65F8: .4byte 0x00000F64
.L080E65FC:
	mov r2, r8
	strh r6, [r2]
.L080E6600:
	movs r0, #1
	strh r0, [r7, #0x1c]
.L080E6604:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E6610
sub_080E6610: @ 0x080E6610
	push {r4, r5, lr}
	ldr r5, .L080E6640
	ldr r0, .L080E6644
	adds r4, r5, r0
	ldrh r0, [r4]
	bl Party_GetMember
	ldr r1, .L080E6648
	movs r3, #0
	ldrsh r2, [r4, r3]
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r1, r1, r3
	adds r2, r2, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	bl sub_080EF5FC
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	bne .L080E664C
	movs r0, #3
	b .L080E6654
.L080E6640: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6644: .4byte 0x00000F66
.L080E6648: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E664C:
	bl sub_080E6E08
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080E6654:
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #3
	bne .L080E6662
	ldr r2, .L080E6674
	adds r0, r5, r2
	strh r1, [r0]
.L080E6662:
	cmp r1, #2
	bne .L080E666E
	ldr r3, .L080E6674
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
.L080E666E:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E6674: .4byte 0x0000097A

	thumb_func_start sub_080E6678
sub_080E6678: @ 0x080E6678
	push {r4, r5, lr}
	ldr r5, .L080E66A8
	ldr r0, .L080E66AC
	adds r4, r5, r0
	ldrh r0, [r4]
	bl Party_GetMember
	ldr r1, .L080E66B0
	movs r3, #0
	ldrsh r2, [r4, r3]
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r1, r1, r3
	adds r2, r2, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	bl sub_080EF5FC
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	bne .L080E66B4
	movs r0, #3
	b .L080E66BC
.L080E66A8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E66AC: .4byte 0x00000F66
.L080E66B0: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E66B4:
	bl sub_080E6E08
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080E66BC:
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #3
	bne .L080E66CA
	ldr r2, .L080E66DC
	adds r0, r5, r2
	strh r1, [r0]
.L080E66CA:
	cmp r1, #2
	bne .L080E66D6
	ldr r3, .L080E66DC
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
.L080E66D6:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E66DC: .4byte 0x0000097A

	thumb_func_start sub_080E66E0
sub_080E66E0: @ 0x080E66E0
	ldr r0, .L080E66EC
	ldr r1, .L080E66F0
	adds r0, r0, r1
	movs r1, #3
	strh r1, [r0]
	bx lr
.L080E66EC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E66F0: .4byte 0x0000097A

	thumb_func_start sub_080E66F4
sub_080E66F4: @ 0x080E66F4
	push {r4, lr}
	ldr r4, .L080E671C
	bl sub_080E6E08
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #3
	bne .L080E670A
	ldr r2, .L080E6720
	adds r0, r4, r2
	strh r1, [r0]
.L080E670A:
	cmp r1, #2
	bne .L080E6716
	ldr r0, .L080E6720
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
.L080E6716:
	pop {r4}
	pop {r0}
	bx r0
.L080E671C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6720: .4byte 0x0000097A

	thumb_func_start sub_080E6724
sub_080E6724: @ 0x080E6724
	ldr r0, .L080E6730
	ldr r1, .L080E6734
	adds r0, r0, r1
	movs r1, #3
	strh r1, [r0]
	bx lr
.L080E6730: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6734: .4byte 0x0000097A

	thumb_func_start sub_080E6738
sub_080E6738: @ 0x080E6738
	push {r4, lr}
	ldr r4, .L080E6758
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080E6750
	ldr r0, .L080E675C
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
.L080E6750:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E6758: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E675C: .4byte 0x0000097A

	thumb_func_start sub_080E6760
sub_080E6760: @ 0x080E6760
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r4, .L080E6780
	ldr r1, .L080E6784
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #9
	bls .L080E6774
	b .L080E6A6C
.L080E6774:
	lsls r0, r0, #2
	ldr r1, .L080E6788
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080E6780: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6784: .4byte 0x0000097C
.L080E6788: .4byte gUnknown_080E678C
	.global gUnknown_080E678C
gUnknown_080E678C:
.L080E678C: @ jump table
	.4byte .L080E67B4
	.4byte .L080E6860
	.4byte .L080E6878
	.4byte .L080E6988
	.4byte .L080E69CC
	.4byte .L080E69E0
	.4byte .L080E6A00
	.4byte .L080E6A14
	.4byte .L080E6A34
	.4byte .L080E6A54
.L080E67B4:
	movs r0, #0xe5
	bl Flag_Test
	cmp r0, #0
	beq .L080E67E8
	movs r5, #0
	movs r0, #5
	movs r1, #0
	bl sub_08126D50
	movs r0, #3
	str r0, [sp]
	movs r0, #2
	movs r1, #1
	movs r2, #1
	movs r3, #3
	bl sub_08126928
	ldr r3, .L080E67E4
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b .L080E6806
	.byte 0x00, 0x00
.L080E67E4: .4byte 0x00000692
.L080E67E8:
	movs r5, #0
	movs r0, #6
	movs r1, #0
	bl sub_08126D50
	movs r0, #2
	str r0, [sp]
	movs r1, #1
	movs r2, #1
	movs r3, #2
	bl sub_08126928
	ldr r1, .L080E6840
	adds r0, r4, r1
	strb r5, [r0]
.L080E6806:
	ldr r2, .L080E6844
	adds r0, r4, r2
	strb r5, [r0]
	ldr r1, .L080E6848
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, .L080E684C
	movs r0, #0xb0
	strb r0, [r1]
	ldr r1, .L080E6850
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, .L080E6854
	movs r0, #0x58
	strb r0, [r1]
	bl sub_080C7AE0
	ldr r1, .L080E6858
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	ldr r3, .L080E685C
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	b .L080E6A6C
.L080E6840: .4byte 0x00000692
.L080E6844: .4byte 0x00001121
.L080E6848: .4byte 0x03000030 @ IWRAM+0x30
.L080E684C: .4byte 0x03000031 @ IWRAM+0x31
.L080E6850: .4byte 0x03000035 @ IWRAM+0x35
.L080E6854: .4byte 0x03000034 @ IWRAM+0x34
.L080E6858: .4byte gUnknown_0812326A
.L080E685C: .4byte 0x0000097C
.L080E6860:
	bl sub_080C7AF0
	cmp r0, #2
	bne .L080E686A
	b .L080E6A6C
.L080E686A:
	ldr r0, .L080E6874
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	b .L080E6A6C
.L080E6874: .4byte 0x0000097C
.L080E6878:
	movs r0, #2
	bl sub_08126D1C
	adds r5, r0, #0
	ldrh r6, [r5, #0x18]
	movs r0, #2
	bl sub_08126A08
	ldr r2, .L080E68BC
	ldr r1, .L080E68C0
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrh r3, [r5, #0x18]
	adds r0, r0, r3
	adds r0, r0, r2
	ldrb r1, [r0]
	adds r3, r1, #0
	ldr r2, .L080E68C4
	adds r0, r4, r2
	movs r2, #0
	strh r2, [r0]
	ldrb r0, [r5]
	cmp r0, #4
	bne .L080E68CC
	ldr r3, .L080E68C8
	adds r1, r4, r3
	movs r0, #6
	strh r0, [r1]
	bl sub_080C7ACC
	b .L080E6958
	.byte 0x00, 0x00
.L080E68BC: .4byte gUnknown_086BE67C
.L080E68C0: .4byte 0x00000692
.L080E68C4: .4byte 0x00000F62
.L080E68C8: .4byte 0x0000097C
.L080E68CC:
	cmp r0, #3
	bne .L080E68F4
	ldr r3, .L080E68E8
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, .L080E68EC
	adds r0, r4, r1
	strh r2, [r0]
	ldr r1, .L080E68F0
	movs r0, #0xf0
	strb r0, [r1]
	bl sub_080C7ACC
	b .L080E6958
.L080E68E8: .4byte 0x0000097C
.L080E68EC: .4byte 0x0000097E
.L080E68F0: .4byte 0x03000031 @ IWRAM+0x31
.L080E68F4:
	cmp r0, #6
	bne .L080E6938
	movs r2, #0xfc
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bne .L080E6924
	ldr r3, .L080E6920
	adds r0, r4, r3
	ldrb r0, [r0]
	bl Battle_BuildActorPrompt
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	b .L080E6958
	.byte 0x00, 0x00
.L080E6920: .4byte 0x00000F66
.L080E6924:
	ldr r0, .L080E6934
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
	b .L080E6958
.L080E6934: .4byte gUnknown_086BE684
.L080E6938:
	ldrh r0, [r5, #0x18]
	cmp r6, r0
	beq .L080E6958
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L080E6958
	ldr r0, .L080E697C
	lsls r1, r3, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L080E6958:
	ldr r0, .L080E6980
	movs r1, #0
	str r1, [sp]
	movs r1, #0xb6
	str r1, [sp, #4]
	ldr r2, .L080E6984
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L080E6A6C
	.byte 0x00, 0x00
.L080E697C: .4byte gUnknown_086BE684
.L080E6980: .4byte gUnknown_080008B0
.L080E6984: .4byte gUnknown_086BE606
.L080E6988:
	bl sub_080C7AF0
	cmp r0, #1
	beq .L080E6A6C
	movs r0, #0
	bl sub_080F332C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	beq .L080E69F2
	cmp r0, #2
	bgt .L080E69A8
	cmp r0, #1
	beq .L080E69AE
	b .L080E6A6C
.L080E69A8:
	cmp r0, #3
	beq .L080E69C0
	b .L080E6A6C
.L080E69AE:
	ldr r2, .L080E69BC
	adds r1, r4, r2
	movs r0, #8
	strh r0, [r1]
	bl sub_080C7ACC
	b .L080E6A6C
.L080E69BC: .4byte 0x0000097C
.L080E69C0:
	ldr r0, .L080E69C8
	adds r1, r4, r0
	b .L080E69F6
	.byte 0x00, 0x00
.L080E69C8: .4byte 0x0000097C
.L080E69CC:
	bl sub_080F33E8
	cmp r0, #0
	beq .L080E6A6C
	ldr r2, .L080E69DC
	adds r1, r4, r2
	b .L080E69F6
	.byte 0x00, 0x00
.L080E69DC: .4byte 0x0000097C
.L080E69E0:
	bl sub_080C7AF0
	cmp r0, #1
	beq .L080E6A6C
	bl sub_080F3398
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080E6A6C
.L080E69F2:
	ldr r3, .L080E69FC
	adds r1, r4, r3
.L080E69F6:
	movs r0, #0
	strh r0, [r1]
	b .L080E6A6C
.L080E69FC: .4byte 0x0000097C
.L080E6A00:
	movs r0, #2
	bl sub_081269B0
	ldr r0, .L080E6A10
	adds r1, r4, r0
	movs r0, #7
	b .L080E6A40
	.byte 0x00, 0x00
.L080E6A10: .4byte 0x0000097C
.L080E6A14:
	bl sub_080C7AF0
	cmp r0, #1
	beq .L080E6A6C
	ldr r1, .L080E6A2C
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, .L080E6A30
	adds r0, r4, r2
	strh r1, [r0]
	b .L080E6A6C
.L080E6A2C: .4byte 0x0000097A
.L080E6A30: .4byte 0x0000097C
.L080E6A34:
	movs r0, #2
	bl sub_081269B0
	ldr r3, .L080E6A4C
	adds r1, r4, r3
	movs r0, #9
.L080E6A40:
	strh r0, [r1]
	ldr r1, .L080E6A50
	movs r0, #0xf0
	strb r0, [r1]
	b .L080E6A6C
	.byte 0x00, 0x00
.L080E6A4C: .4byte 0x0000097C
.L080E6A50: .4byte 0x03000031 @ IWRAM+0x31
.L080E6A54:
	bl sub_080C7AF0
	cmp r0, #1
	beq .L080E6A6C
	ldr r0, .L080E6A74
	adds r1, r4, r0
	movs r2, #0
	movs r0, #3
	strh r0, [r1]
	ldr r1, .L080E6A78
	adds r0, r4, r1
	strh r2, [r0]
.L080E6A6C:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080E6A74: .4byte 0x0000097A
.L080E6A78: .4byte 0x0000097C

	thumb_func_start sub_080E6A7C
sub_080E6A7C: @ 0x080E6A7C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r7, .L080E6A9C
	ldr r1, .L080E6AA0
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bls .L080E6A90
	b .L080E6BD2
.L080E6A90:
	lsls r0, r0, #2
	ldr r1, .L080E6AA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080E6A9C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6AA0: .4byte 0x0000097C
.L080E6AA4: .4byte gUnknown_080E6AA8
	.global gUnknown_080E6AA8
gUnknown_080E6AA8:
.L080E6AA8: @ jump table
	.4byte .L080E6AC0
	.4byte .L080E6AE0
	.4byte .L080E6BAC
	.4byte .L080E6BC4
	.4byte .L080E6BD2
	.4byte .L080E6B7C
.L080E6AC0:
	ldr r3, .L080E6AD8
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #1
	bl sub_0812C490
	ldr r0, .L080E6ADC
	adds r1, r7, r0
	movs r0, #1
.L080E6AD2:
	strh r0, [r1]
	b .L080E6BD2
	.byte 0x00, 0x00
.L080E6AD8: .4byte 0x00000F66
.L080E6ADC: .4byte 0x0000097C
.L080E6AE0:
	bl sub_0812C4D4
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L080E6BD2
	ldr r2, .L080E6AFC
	ands r2, r1
	ldr r0, .L080E6B00
	cmp r2, r0
	bne .L080E6B08
	ldr r2, .L080E6B04
	b .L080E6BB6
.L080E6AFC: .4byte 0xFFFF0000
.L080E6B00: .4byte 0xFFFE0000
.L080E6B04: .4byte 0x0000097C
.L080E6B08:
	lsls r0, r1, #0x18
	lsrs r6, r0, #0x18
	ldr r4, .L080E6B60
	ldr r3, .L080E6B64
	adds r5, r7, r3
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r4, r4, r3
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r6, #0
	str r2, [sp]
	bl Combatant_SetChosenSkill
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	movs r3, #0xf3
	lsls r3, r3, #4
	adds r1, r7, r3
	adds r1, r1, r0
	ldr r2, [sp]
	lsrs r0, r2, #0x10
	strh r0, [r1]
	ldr r0, .L080E6B68
	adds r1, r7, r0
	movs r0, #2
	strh r0, [r1]
	cmp r6, #0x3e
	bne .L080E6B6C
	movs r0, #5
	strh r0, [r1]
	movs r0, #3
	bl sub_081293F8
	b .L080E6BD2
.L080E6B60: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E6B64: .4byte 0x00000F66
.L080E6B68: .4byte 0x0000097C
.L080E6B6C:
	cmp r6, #0x3f
	bne .L080E6AD2
	movs r0, #5
	strh r0, [r1]
	movs r0, #7
	bl sub_081293F8
	b .L080E6BD2
.L080E6B7C:
	bl sub_08129440
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #0
	beq .L080E6BD2
	cmp r0, #1
	bne .L080E6B9C
	ldr r2, .L080E6B98
	adds r1, r7, r2
	movs r0, #2
	b .L080E6AD2
	.byte 0x00, 0x00
.L080E6B98: .4byte 0x0000097C
.L080E6B9C:
	cmp r1, #0xff
	bne .L080E6BD2
	ldr r3, .L080E6BA8
	adds r1, r7, r3
	b .L080E6BB8
	.byte 0x00, 0x00
.L080E6BA8: .4byte 0x0000097C
.L080E6BAC:
	ldr r0, .L080E6BBC
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, .L080E6BC0
.L080E6BB6:
	adds r1, r7, r2
.L080E6BB8:
	movs r0, #3
	b .L080E6AD2
.L080E6BBC: .4byte 0x0000097C
.L080E6BC0: .4byte 0x0000097A
.L080E6BC4:
	ldr r3, .L080E6BDC
	adds r0, r7, r3
	movs r1, #0
	strh r1, [r0]
	ldr r2, .L080E6BE0
	adds r0, r7, r2
	strh r1, [r0]
.L080E6BD2:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E6BDC: .4byte 0x0000097A
.L080E6BE0: .4byte 0x0000097C

	thumb_func_start sub_080E6BE4
sub_080E6BE4: @ 0x080E6BE4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r7, .L080E6C04
	ldr r0, .L080E6C08
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq .L080E6C26
	cmp r0, #1
	bgt .L080E6C0C
	cmp r0, #0
	beq .L080E6C16
	b .L080E6CBC
.L080E6C04: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6C08: .4byte 0x0000097C
.L080E6C0C:
	cmp r0, #2
	beq .L080E6C9C
	cmp r0, #3
	beq .L080E6CB0
	b .L080E6CBC
.L080E6C16:
	movs r0, #1
	movs r1, #0
	bl sub_0812B194
	movs r0, #1
	mov r2, r8
	strh r0, [r2]
	b .L080E6CBC
.L080E6C26:
	bl sub_0812B1D4
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L080E6CBC
	ldr r6, .L080E6C44
	ands r6, r1
	ldr r0, .L080E6C48
	cmp r6, r0
	bne .L080E6C4C
	movs r0, #3
	b .L080E6C88
	.byte 0x00, 0x00
.L080E6C44: .4byte 0xFFFF0000
.L080E6C48: .4byte 0xFFFE0000
.L080E6C4C:
	ldr r4, .L080E6C94
	ldr r2, .L080E6C98
	adds r5, r7, r2
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r4, r4, r2
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl Combatant_SetChosenSkill
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	movs r2, #0xf3
	lsls r2, r2, #4
	adds r1, r7, r2
	adds r0, r0, r1
	lsrs r1, r6, #0x10
	strh r1, [r0]
	movs r0, #2
.L080E6C88:
	mov r1, r8
	strh r0, [r1]
	bl sub_080EA210
	b .L080E6CBC
	.byte 0x00, 0x00
.L080E6C94: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E6C98: .4byte 0x00000F66
.L080E6C9C:
	movs r0, #0
	mov r2, r8
	strh r0, [r2]
	ldr r0, .L080E6CAC
	adds r1, r7, r0
	movs r0, #3
	b .L080E6CBA
	.byte 0x00, 0x00
.L080E6CAC: .4byte 0x0000097A
.L080E6CB0:
	ldr r2, .L080E6CC8
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	mov r1, r8
.L080E6CBA:
	strh r0, [r1]
.L080E6CBC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E6CC8: .4byte 0x0000097A

	thumb_func_start sub_080E6CCC
sub_080E6CCC: @ 0x080E6CCC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r7, .L080E6CEC
	ldr r0, .L080E6CF0
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq .L080E6D14
	cmp r0, #1
	bgt .L080E6CF4
	cmp r0, #0
	beq .L080E6CFE
	b .L080E6DAC
.L080E6CEC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6CF0: .4byte 0x0000097C
.L080E6CF4:
	cmp r0, #2
	beq .L080E6D8C
	cmp r0, #3
	beq .L080E6DA0
	b .L080E6DAC
.L080E6CFE:
	ldr r2, .L080E6D10
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r0, #2
	bl sub_0812C490
	movs r0, #1
	b .L080E6DA8
	.byte 0x00, 0x00
.L080E6D10: .4byte 0x00000F66
.L080E6D14:
	bl sub_0812C4D4
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L080E6DAC
	ldr r6, .L080E6D34
	ands r6, r1
	ldr r0, .L080E6D38
	cmp r6, r0
	bne .L080E6D3C
	movs r0, #3
	mov r2, r8
	strh r0, [r2]
	b .L080E6D7C
.L080E6D34: .4byte 0xFFFF0000
.L080E6D38: .4byte 0xFFFE0000
.L080E6D3C:
	ldr r4, .L080E6D84
	ldr r0, .L080E6D88
	adds r5, r7, r0
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r4, r4, r2
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl Combatant_SetChosenSkill
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	movs r2, #0xf3
	lsls r2, r2, #4
	adds r1, r7, r2
	adds r0, r0, r1
	lsrs r1, r6, #0x10
	strh r1, [r0]
	movs r0, #2
	mov r1, r8
	strh r0, [r1]
.L080E6D7C:
	bl sub_080EA210
	b .L080E6DAC
	.byte 0x00, 0x00
.L080E6D84: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E6D88: .4byte 0x00000F66
.L080E6D8C:
	movs r0, #0
	mov r2, r8
	strh r0, [r2]
	ldr r0, .L080E6D9C
	adds r1, r7, r0
	movs r0, #3
	b .L080E6DAA
	.byte 0x00, 0x00
.L080E6D9C: .4byte 0x0000097A
.L080E6DA0:
	ldr r2, .L080E6DB8
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
.L080E6DA8:
	mov r1, r8
.L080E6DAA:
	strh r0, [r1]
.L080E6DAC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E6DB8: .4byte 0x0000097A

	thumb_func_start sub_080E6DBC
sub_080E6DBC: @ 0x080E6DBC
.L080E6DBC:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r6, r4, #0
	ldr r5, .L080E6DF8
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r7, r5, r0
	ldr r2, .L080E6DFC
	movs r0, #0xd2
	movs r1, #0
	movs r3, #0
	bl sub_080EC9AC
	cmp r4, #0
	beq .L080E6DE4
	subs r1, r4, #1
	ldr r2, .L080E6E00
	adds r0, r5, r2
	strb r1, [r0]
.L080E6DE4:
	movs r0, #0x30
	strh r0, [r7, #0xe]
	ldr r1, .L080E6E04
	lsls r0, r6, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #0xc]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E6DF8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6DFC: .4byte 0x0000FFFF
.L080E6E00: .4byte 0x00000695
.L080E6E04: .4byte gUnknown_086BF72C

	thumb_func_start sub_080E6E08
sub_080E6E08: @ 0x080E6E08
.L080E6E08:
	push {r4, r5, r6, lr}
	ldr r4, .L080E6E30
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r6, r4, r0
	ldr r1, .L080E6E34
	adds r0, r4, r1
	ldrh r5, [r0]
	ldr r2, .L080E6E38
	adds r0, r4, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bls .L080E6E26
	b .L080E6F98
.L080E6E26:
	lsls r0, r0, #2
	ldr r1, .L080E6E3C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080E6E30: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6E34: .4byte 0x00000ECE
.L080E6E38: .4byte 0x0000097E
.L080E6E3C: .4byte gUnknown_080E6E40
	.global gUnknown_080E6E40
gUnknown_080E6E40:
.L080E6E40: @ jump table
	.4byte .L080E6E54
	.4byte .L080E6EB8
	.4byte .L080E6F78
	.4byte .L080E6F88
	.4byte .L080E6E94
.L080E6E54:
	bl sub_080F3060
	cmp r0, #0
	beq .L080E6F40
	bl Battle_IsTwoSided
	cmp r0, #0
	beq .L080E6F40
	ldr r0, .L080E6E8C
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	movs r0, #1
	bl sub_080E6DBC
	ldr r1, .L080E6E90
	movs r0, #0x14
	strb r0, [r1]
	b .L080E6EA8
.L080E6E8C: .4byte 0x00000149
.L080E6E90: .4byte 0x03000050 @ IWRAM+0x50
.L080E6E94:
	ldr r1, .L080E6EA4
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080E6EA8
	subs r0, #1
	strb r0, [r1]
	b .L080E6F98
	.byte 0x00, 0x00
.L080E6EA4: .4byte 0x03000050 @ IWRAM+0x50
.L080E6EA8:
	ldr r2, .L080E6EB4
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
	b .L080E6F98
	.byte 0x00, 0x00
.L080E6EB4: .4byte 0x0000097E
.L080E6EB8:
	ldr r2, .L080E6EDC
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq .L080E6EE8
	ldr r0, .L080E6EE0
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #1
	beq .L080E6F98
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L080E6EE4
	ldrh r0, [r0, #4]
	b .L080E6F02
.L080E6EDC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E6EE0: .4byte 0x00000695
.L080E6EE4: .4byte gUnknown_086BF72C
.L080E6EE8:
	ldrh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080E6F14
	ldr r2, .L080E6F0C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080E6F98
	strb r3, [r1]
	ldr r0, .L080E6F10
	ldrh r0, [r0, #2]
.L080E6F02:
	strh r0, [r6, #0xc]
	movs r0, #0x64
	bl sub_080ECF70
	b .L080E6F98
.L080E6F0C: .4byte 0x00000695
.L080E6F10: .4byte gUnknown_086BF72C
.L080E6F14:
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E6F54
	ldr r1, .L080E6F4C
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #0x12
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #0xd
	adds r1, r1, r2
	asrs r1, r1, #0x10
	bl sub_080EDA4C
	movs r0, #0x65
	bl sub_080ECF70
	bl sub_080ECB38
.L080E6F40:
	ldr r0, .L080E6F50
	adds r1, r4, r0
	movs r0, #3
	strh r0, [r1]
	b .L080E6F98
	.byte 0x00, 0x00
.L080E6F4C: .4byte 0x00000695
.L080E6F50: .4byte 0x0000097E
.L080E6F54:
	ldrh r1, [r2]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E6F98
	movs r0, #0x66
	bl sub_080ECF70
	bl sub_080ECB38
	ldr r1, .L080E6F74
	adds r0, r4, r1
	strh r5, [r0]
	b .L080E6F98
	.byte 0x00, 0x00
.L080E6F74: .4byte 0x0000097E
.L080E6F78:
	ldr r2, .L080E6F84
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	movs r0, #2
	b .L080E6F9A
.L080E6F84: .4byte 0x0000097E
.L080E6F88:
	ldr r0, .L080E6F94
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r0, #3
	b .L080E6F9A
.L080E6F94: .4byte 0x0000097E
.L080E6F98:
	movs r0, #0
.L080E6F9A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_080E6FA0
sub_080E6FA0: @ 0x080E6FA0
.L080E6FA0:
	push {r4, r5, r6, lr}
	ldr r4, .L080E6FC8
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r6, r4, r0
	ldr r1, .L080E6FCC
	adds r0, r4, r1
	ldrh r5, [r0]
	ldr r2, .L080E6FD0
	adds r0, r4, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bls .L080E6FBE
	b .L080E7114
.L080E6FBE:
	lsls r0, r0, #2
	ldr r1, .L080E6FD4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080E6FC8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E6FCC: .4byte 0x00000ECE
.L080E6FD0: .4byte 0x0000097E
.L080E6FD4: .4byte gUnknown_080E6FD8
	.global gUnknown_080E6FD8
gUnknown_080E6FD8:
.L080E6FD8: @ jump table
	.4byte .L080E6FEC
	.4byte .L080E7034
	.4byte .L080E70F4
	.4byte .L080E7104
	.4byte .L080E7010
.L080E6FEC:
	bl sub_080F3060
	cmp r0, #0
	beq .L080E70BC
	bl Battle_IsTwoSided
	cmp r0, #0
	beq .L080E70BC
	movs r0, #1
	bl sub_080E6DBC
	ldr r1, .L080E700C
	movs r0, #0x14
	strb r0, [r1]
	b .L080E7024
	.byte 0x00, 0x00
.L080E700C: .4byte 0x03000051 @ IWRAM+0x51
.L080E7010:
	ldr r1, .L080E7020
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080E7024
	subs r0, #1
	strb r0, [r1]
	b .L080E7114
	.byte 0x00, 0x00
.L080E7020: .4byte 0x03000051 @ IWRAM+0x51
.L080E7024:
	ldr r2, .L080E7030
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
	b .L080E7114
	.byte 0x00, 0x00
.L080E7030: .4byte 0x0000097E
.L080E7034:
	ldr r2, .L080E7058
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq .L080E7064
	ldr r0, .L080E705C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #1
	beq .L080E7114
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L080E7060
	ldrh r0, [r0, #4]
	b .L080E707E
.L080E7058: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E705C: .4byte 0x00000695
.L080E7060: .4byte gUnknown_086BF72C
.L080E7064:
	ldrh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080E7090
	ldr r2, .L080E7088
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080E7114
	strb r3, [r1]
	ldr r0, .L080E708C
	ldrh r0, [r0, #2]
.L080E707E:
	strh r0, [r6, #0xc]
	movs r0, #0x64
	bl sub_080ECF70
	b .L080E7114
.L080E7088: .4byte 0x00000695
.L080E708C: .4byte gUnknown_086BF72C
.L080E7090:
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E70D0
	ldr r1, .L080E70C8
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #0x12
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #0xd
	adds r1, r1, r2
	asrs r1, r1, #0x10
	bl sub_080EDA4C
	movs r0, #0x65
	bl sub_080ECF70
	bl sub_080ECB38
.L080E70BC:
	ldr r0, .L080E70CC
	adds r1, r4, r0
	movs r0, #3
	strh r0, [r1]
	b .L080E7114
	.byte 0x00, 0x00
.L080E70C8: .4byte 0x00000695
.L080E70CC: .4byte 0x0000097E
.L080E70D0:
	ldrh r1, [r2]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E7114
	movs r0, #0x66
	bl sub_080ECF70
	bl sub_080ECB38
	ldr r1, .L080E70F0
	adds r0, r4, r1
	strh r5, [r0]
	b .L080E7114
	.byte 0x00, 0x00
.L080E70F0: .4byte 0x0000097E
.L080E70F4:
	ldr r2, .L080E7100
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	movs r0, #2
	b .L080E7116
.L080E7100: .4byte 0x0000097E
.L080E7104:
	ldr r0, .L080E7110
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r0, #3
	b .L080E7116
.L080E7110: .4byte 0x0000097E
.L080E7114:
	movs r0, #0
.L080E7116:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_080E711C
sub_080E711C: @ 0x080E711C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	ldr r2, .L080E7134
	cmp r1, #4
	bhi .L080E717A
	lsls r0, r1, #2
	ldr r1, .L080E7138
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080E7134: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E7138: .4byte gUnknown_080E713C
	.global gUnknown_080E713C
gUnknown_080E713C:
.L080E713C: @ jump table
	.4byte .L080E7150
	.4byte .L080E715A
	.4byte .L080E7164
	.4byte .L080E716C
	.4byte .L080E7174
.L080E7150:
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrb r3, [r0]
	b .L080E717A
.L080E715A:
	ldr r1, .L080E7160
	b .L080E7176
	.byte 0x00, 0x00
.L080E7160: .4byte 0x00000978
.L080E7164:
	ldr r1, .L080E7168
	b .L080E7176
.L080E7168: .4byte 0x0000097A
.L080E716C:
	ldr r1, .L080E7170
	b .L080E7176
.L080E7170: .4byte 0x0000097C
.L080E7174:
	ldr r1, .L080E7190
.L080E7176:
	adds r0, r2, r1
	ldrh r3, [r0]
.L080E717A:
	movs r0, #0
	strh r0, [r4, #0x1c]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, r5
	bne .L080E718A
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080E718A:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E7190: .4byte 0x0000097E

	thumb_func_start sub_080E7194
sub_080E7194: @ 0x080E7194
	push {lr}
	ldr r1, .L080E71C0
	ldrh r0, [r1]
	cmp r0, #3
	beq .L080E71A2
	movs r0, #2
	strh r0, [r1]
.L080E71A2:
	bl BattleMsg_Close
	movs r0, #0
	bl BattleMsg_SetLocked
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	bl sub_080C84A0
	bl sub_081269D0
	pop {r0}
	bx r0
.L080E71C0: .4byte 0x030063A0 @ IWRAM+0x63A0

	thumb_func_start sub_080E71C4
sub_080E71C4: @ 0x080E71C4
	push {lr}
	ldr r1, .L080E71D8
	ldrh r0, [r1]
	cmp r0, #3
	beq .L080E71D2
	movs r0, #2
	strh r0, [r1]
.L080E71D2:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E71D8: .4byte 0x030063A0 @ IWRAM+0x63A0

	thumb_func_start sub_080E71DC
sub_080E71DC: @ 0x080E71DC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r1, r5, #2
	ldr r0, .L080E7234
	adds r6, r1, r0
	ldrb r0, [r6]
	lsls r0, r0, #7
	ldr r1, .L080E7238
	adds r3, r0, r1
	lsls r1, r7, #7
	ldr r0, .L080E723C
	adds r2, r1, r0
	ldr r1, .L080E7240
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #2
	movs r4, #0xe6
	lsls r4, r4, #4
	adds r0, r0, r4
	adds r4, r0, r1
	ldrb r0, [r4, #1]
	cmp r0, r5
	beq .L080E722E
	adds r0, r3, #0
	adds r1, r2, #0
	movs r2, #0x20
	bl CpuFastSet
	strb r5, [r4, #1]
	ldrb r0, [r6]
	strb r0, [r4, #2]
	ldrb r0, [r6, #1]
	strb r0, [r4, #3]
	ldr r0, .L080E7244
	strb r7, [r0]
	ldr r0, .L080E7248
	bl sub_080E5668
.L080E722E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E7234: .4byte gUnknown_086BE6A4
.L080E7238: .4byte gUnknown_081A81B8
.L080E723C: .4byte 0x030010B4 @ IWRAM+0x10B4
.L080E7240: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E7244: .4byte 0x030063C0 @ IWRAM+0x63C0
.L080E7248: .4byte sub_080E7318

	thumb_func_start sub_080E724C
sub_080E724C: @ 0x080E724C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, .L080E7300
	mov sb, r0
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080E7304
	ldr r2, .L080E7308
	mov r0, sp
	bl CpuFastSet
	movs r6, #0
	movs r1, #0x80
	lsls r1, r1, #8
	mov sl, r1
.L080E7272:
	lsls r7, r6, #7
	movs r1, #0x9a
	lsls r1, r1, #4
	adds r0, r7, r1
	mov r1, sb
	adds r2, r1, r0
	ldrh r1, [r2, #0xe]
	cmp r1, sl
	bne .L080E72D4
	ldrh r0, [r2, #0x10]
	ands r1, r0
	mov r8, r1
	cmp r1, #0
	bne .L080E72D4
	ldrh r0, [r2, #0x10]
	bl sub_080E739C
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r4, #2
	ldr r0, .L080E730C
	adds r5, r5, r0
	ldrb r0, [r5]
	lsls r0, r0, #7
	ldr r1, .L080E7310
	adds r0, r0, r1
	ldr r1, .L080E7304
	adds r1, r7, r1
	movs r2, #0x20
	bl CpuFastSet
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	movs r1, #0xe6
	lsls r1, r1, #4
	adds r0, r0, r1
	add r0, sb
	strb r6, [r0]
	strb r4, [r0, #1]
	ldrb r1, [r5]
	strb r1, [r0, #2]
	ldrb r1, [r5, #1]
	strb r1, [r0, #3]
	movs r1, #1
	strb r1, [r0, #8]
	mov r1, r8
	strb r1, [r0, #9]
.L080E72D4:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #7
	bls .L080E7272
	ldr r0, .L080E7314
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r1, #0xec
	lsls r1, r1, #4
	add r1, sb
	movs r0, #0
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E7300: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E7304: .4byte 0x030010B4 @ IWRAM+0x10B4
.L080E7308: .4byte 0x01000100
.L080E730C: .4byte gUnknown_086BE6A4
.L080E7310: .4byte gUnknown_081A81B8
.L080E7314: .4byte sub_080E7364

	thumb_func_start sub_080E7318
sub_080E7318: @ 0x080E7318
	push {lr}
	ldr r2, .L080E7350
	ldr r3, .L080E7354
	ldrb r0, [r3]
	lsls r0, r0, #7
	ldr r1, .L080E7358
	adds r0, r0, r1
	str r0, [r2]
	ldrb r0, [r3]
	lsls r0, r0, #7
	ldr r1, .L080E735C
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, .L080E7360
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, #0
	bge .L080E734A
.L080E7342:
	ldr r0, [r2, #8]
	ands r0, r1
	cmp r0, #0
	bne .L080E7342
.L080E734A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E7350: .4byte 0x040000D4 @ REG_DMA3SAD
.L080E7354: .4byte 0x030063C0 @ IWRAM+0x63C0
.L080E7358: .4byte 0x030010B4 @ IWRAM+0x10B4
.L080E735C: .4byte 0x06011500 @ VRAM+0x11500
.L080E7360: .4byte 0x84000020

	thumb_func_start sub_080E7364
sub_080E7364: @ 0x080E7364
	push {lr}
	ldr r1, .L080E738C
	ldr r0, .L080E7390
	str r0, [r1]
	ldr r0, .L080E7394
	str r0, [r1, #4]
	ldr r0, .L080E7398
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L080E7388
.L080E7380:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L080E7380
.L080E7388:
	pop {r0}
	bx r0
.L080E738C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080E7390: .4byte 0x030010B4 @ IWRAM+0x10B4
.L080E7394: .4byte 0x06011500 @ VRAM+0x11500
.L080E7398: .4byte 0x84000100

	thumb_func_start sub_080E739C
sub_080E739C: @ 0x080E739C
.L080E739C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r0, #8
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r1, r0, #0x1f
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq .L080E73B8
	movs r1, #2
.L080E73B8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080E73C2
	movs r1, #3
.L080E73C2:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq .L080E73CC
	movs r1, #4
.L080E73CC:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq .L080E73D8
	movs r1, #5
.L080E73D8:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq .L080E73E2
	movs r1, #6
.L080E73E2:
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L080E73EC
	movs r1, #7
.L080E73EC:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080E73F8
	movs r1, #8
.L080E73F8:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq .L080E7402
	movs r1, #9
.L080E7402:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r2
	cmp r0, #0
	beq .L080E740E
	movs r1, #0xb
.L080E740E:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq .L080E7418
	movs r1, #0xc
.L080E7418:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r2
	cmp r0, #0
	beq .L080E7424
	movs r1, #0xd
.L080E7424:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq .L080E7430
	movs r1, #0xe
.L080E7430:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq .L080E743C
	movs r1, #0x10
.L080E743C:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080E7444
sub_080E7444: @ 0x080E7444
	push {r4, lr}
	ldr r0, .L080E7480
	movs r2, #0xe6
	lsls r2, r2, #4
	adds r1, r0, r2
	movs r3, #0
	movs r4, #0xff
	movs r2, #0
.L080E7454:
	ldrb r0, [r1, #1]
	orrs r0, r4
	strb r0, [r1, #1]
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	strb r2, [r1, #3]
	strb r2, [r1, #2]
	strh r2, [r1, #6]
	strh r2, [r1, #4]
	strb r2, [r1, #8]
	strb r2, [r1, #9]
	adds r1, #0xc
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #7
	bls .L080E7454
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E7480: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080E7484
sub_080E7484: @ 0x080E7484
.L080E7484:
	push {r4, lr}
	movs r4, #0
.L080E7488:
	movs r0, #0x64
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, .L080E74B4
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq .L080E74A6
	ldr r1, [r2, #0x20]
	ldr r0, .L080E74B8
	cmp r1, r0
	bne .L080E74A6
	adds r0, r2, #0
	bl Task_End
.L080E74A6:
	adds r4, #1
	cmp r4, #0x3f
	bls .L080E7488
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E74B4: .4byte 0x02009004 @ EWRAM+0x9004
.L080E74B8: .4byte sub_080E7A44

	thumb_func_start sub_080E74BC
sub_080E74BC: @ 0x080E74BC
	push {r4, lr}
	ldr r4, .L080E74D0
	ldr r0, .L080E74D4
	ldr r1, .L080E74D8
	bl Task_Create
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
.L080E74D0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E74D4: .4byte gUnknown_086BE738
.L080E74D8: .4byte 0x0000FFFF

	thumb_func_start sub_080E74DC
sub_080E74DC: @ 0x080E74DC
.L080E74DC:
	push {r4, r5, r6, lr}
	ldr r5, .L080E7528
	movs r0, #0xe6
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r3, #0
	movs r4, #0xff
	movs r2, #0
	ldr r6, .L080E752C
.L080E74EE:
	ldrb r0, [r1, #1]
	orrs r0, r4
	strb r0, [r1, #1]
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	strb r2, [r1, #3]
	strb r2, [r1, #2]
	strh r2, [r1, #4]
	strh r6, [r1, #6]
	strb r2, [r1, #8]
	strb r2, [r1, #9]
	adds r1, #0xc
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #7
	bls .L080E74EE
	ldr r1, .L080E7530
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, .L080E7534
	adds r0, r5, r2
	strb r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E7528: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E752C: .4byte 0x0000FFFC
.L080E7530: .4byte 0x00000EC4
.L080E7534: .4byte 0x00000EC5

	thumb_func_start sub_080E7538
sub_080E7538: @ 0x080E7538
.L080E7538:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r5, .L080E7564
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xe6
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r3, r1, r5
	cmp r4, #4
	bhi .L080E75D4
	lsls r0, r4, #2
	ldr r1, .L080E7568
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080E7564: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E7568: .4byte gUnknown_080E756C
	.global gUnknown_080E756C
gUnknown_080E756C:
.L080E756C: @ jump table
	.4byte .L080E7580
	.4byte .L080E7588
	.4byte .L080E759C
	.4byte .L080E75B2
	.4byte .L080E75CC
.L080E7580:
	movs r0, #0
	strb r0, [r3, #8]
	strb r0, [r3, #0xa]
	b .L080E75D4
.L080E7588:
	movs r0, #0
	ldr r1, .L080E7598
	strh r1, [r3, #6]
	movs r1, #1
	strb r1, [r3, #8]
	strb r0, [r3, #0xa]
	b .L080E75D4
	.byte 0x00, 0x00
.L080E7598: .4byte 0x0000FFFC
.L080E759C:
	movs r2, #0
	movs r0, #2
	strb r0, [r3, #8]
	movs r0, #0xec
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	strb r2, [r3, #0xa]
	strb r2, [r3, #0xb]
	b .L080E75D4
.L080E75B2:
	movs r0, #3
	strb r0, [r3, #8]
	movs r0, #0xff
	strb r0, [r3, #1]
	movs r0, #4
	strh r0, [r3, #6]
	movs r0, #0xec
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	strb r2, [r3, #0xa]
	b .L080E75D4
.L080E75CC:
	movs r1, #0
	movs r0, #4
	strb r0, [r3, #8]
	strb r1, [r3, #0xa]
.L080E75D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E75DC
sub_080E75DC: @ 0x080E75DC
.L080E75DC:
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, .L080E7600
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #2
	movs r0, #0xe6
	lsls r0, r0, #4
	adds r2, r2, r0
	adds r2, r2, r3
	ldrb r0, [r2, #8]
	cmp r0, r1
	beq .L080E7604
	movs r0, #0
	b .L080E7606
.L080E7600: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E7604:
	movs r0, #1
.L080E7606:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080E760C
sub_080E760C: @ 0x080E760C
.L080E760C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, .L080E76EC
	mov r8, r0
	bl sub_080E74DC
	movs r5, #0
.L080E761C:
	adds r4, r5, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl Combatant_IsDead
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080E7646
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L080E7646
	lsls r2, r5, #1
	adds r2, r2, r5
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r5, #0
	movs r1, #3
	bl sub_080E7538
.L080E7646:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L080E761C
	bl Battle_IsTwoSided
	adds r1, r0, #0
	cmp r1, #0
	bne .L080E76F8
	ldr r0, .L080E76F0
	add r0, r8
	strb r1, [r0]
	movs r6, #0
	movs r5, #0
	ldr r7, .L080E76F0
	add r7, r8
.L080E7668:
	adds r4, r5, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl Combatant_IsDead
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080E769E
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L080E769E
	lsls r2, r6, #1
	adds r2, r2, r6
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r5, #0
	movs r1, #3
	bl sub_080E7538
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E769E:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L080E7668
	movs r6, #0
	ldr r0, .L080E76F0
	add r0, r8
	ldrb r1, [r0]
	ldr r0, .L080E76F4
	adds r1, r1, r0
	movs r3, #0
	movs r4, #0xe6
	lsls r4, r4, #4
.L080E76BA:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	mov r5, r8
	adds r2, r5, r0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq .L080E76E0
	strb r3, [r2]
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #1
	ldrb r5, [r1]
	adds r0, r0, r5
	strh r0, [r2, #4]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E76E0:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #7
	bls .L080E76BA
	b .L080E781A
.L080E76EC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E76F0: .4byte 0x00000EC4
.L080E76F4: .4byte gUnknown_086BE707
.L080E76F8:
	ldr r0, .L080E7824
	add r0, r8
	movs r1, #0
	strb r1, [r0]
	ldr r0, .L080E7828
	add r0, r8
	strb r1, [r0]
	movs r6, #0
	movs r5, #0
	ldr r7, .L080E7824
	add r7, r8
.L080E770E:
	adds r4, r5, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl Combatant_IsDead
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080E7744
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L080E7744
	lsls r2, r6, #1
	adds r2, r2, r6
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r5, #0
	movs r1, #3
	bl sub_080E7538
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E7744:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls .L080E770E
	movs r6, #0
	ldr r0, .L080E7824
	add r0, r8
	ldrb r1, [r0]
	ldr r0, .L080E782C
	adds r1, r1, r0
	movs r3, #0
	movs r4, #0xe6
	lsls r4, r4, #4
.L080E7760:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	mov r5, r8
	adds r2, r5, r0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq .L080E7786
	strb r3, [r2]
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #1
	ldrb r5, [r1]
	adds r0, r0, r5
	strh r0, [r2, #4]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E7786:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #3
	bls .L080E7760
	movs r6, #0
	movs r5, #4
	ldr r7, .L080E7828
	add r7, r8
.L080E7798:
	adds r4, r5, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl Combatant_IsDead
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080E77CE
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L080E77CE
	lsls r2, r6, #1
	adds r2, r2, r6
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r5, #0
	movs r1, #3
	bl sub_080E7538
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E77CE:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L080E7798
	movs r6, #0
	ldr r0, .L080E7828
	add r0, r8
	ldrb r1, [r0]
	ldr r0, .L080E7830
	adds r1, r1, r0
	movs r3, #4
.L080E77E6:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	movs r2, #0xe6
	lsls r2, r2, #4
	adds r0, r0, r2
	mov r4, r8
	adds r2, r4, r0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq .L080E7810
	strb r3, [r2]
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #1
	ldrb r5, [r1]
	adds r0, r0, r5
	strh r0, [r2, #4]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E7810:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #7
	bls .L080E77E6
.L080E781A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E7824: .4byte 0x00000EC4
.L080E7828: .4byte 0x00000EC5
.L080E782C: .4byte gUnknown_086BE70F
.L080E7830: .4byte gUnknown_086BE713

	thumb_func_start sub_080E7834
sub_080E7834: @ 0x080E7834
.L080E7834:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	bl Battle_GetHp
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r4, #0
	bl Battle_GetMaxHp
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, .L080E787C
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	movs r3, #0xda
	lsls r3, r3, #4
	adds r0, r0, r3
	adds r1, r0, r1
	ldrb r0, [r1, #8]
	cmp r0, #2
	bne .L080E7880
	ldrb r0, [r1, #0xb]
	adds r0, #0x13
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b .L080E7962
	.byte 0x00, 0x00
.L080E787C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E7880:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080E788E
	movs r0, #1
	b .L080E7962
.L080E788E:
	lsls r1, r2, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0x12
	cmp r0, r1
	bge .L080E789E
	movs r0, #2
	b .L080E7962
.L080E789E:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r5
	cmp r0, #0
	beq .L080E78AC
	movs r0, #3
	b .L080E7962
.L080E78AC:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r5
	cmp r0, #0
	beq .L080E78BA
	movs r0, #4
	b .L080E7962
.L080E78BA:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r5
	cmp r0, #0
	beq .L080E78C8
	movs r0, #5
	b .L080E7962
.L080E78C8:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080E78D6
	movs r0, #6
	b .L080E7962
.L080E78D6:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r5
	cmp r0, #0
	beq .L080E78E4
	movs r0, #8
	b .L080E7962
.L080E78E4:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080E78F2
	movs r0, #9
	b .L080E7962
.L080E78F2:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080E7900
	movs r0, #0xa
	b .L080E7962
.L080E7900:
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0
	beq .L080E790C
	movs r0, #0xb
	b .L080E7962
.L080E790C:
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0
	beq .L080E7918
	movs r0, #0xc
	b .L080E7962
.L080E7918:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L080E7924
	movs r0, #0xd
	b .L080E7962
.L080E7924:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L080E7930
	movs r0, #0xe
	b .L080E7962
.L080E7930:
	movs r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080E793C
	movs r0, #0xf
	b .L080E7962
.L080E793C:
	movs r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080E7948
	movs r0, #0x10
	b .L080E7962
.L080E7948:
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080E7954
	movs r0, #0x11
	b .L080E7962
.L080E7954:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	bne .L080E7960
	movs r0, #0
	b .L080E7962
.L080E7960:
	movs r0, #0x12
.L080E7962:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_080E7968
sub_080E7968: @ 0x080E7968
.L080E7968:
	push {r4, r5, r6, lr}
	ldr r6, .L080E7994
	movs r5, #0x10
.L080E796E:
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	movs r1, #0xda
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r4, r6, r0
	adds r0, r5, #0
	bl Battle_GetCombatant
	ldrb r0, [r4, #8]
	cmp r0, #4
	bhi .L080E7A32
	lsls r0, r0, #2
	ldr r1, .L080E7998
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080E7994: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E7998: .4byte gUnknown_080E799C
	.global gUnknown_080E799C
gUnknown_080E799C:
.L080E799C: @ jump table
	.4byte .L080E7A32
	.4byte .L080E79B0
	.4byte .L080E79CC
	.4byte .L080E79FA
	.4byte .L080E7A20
.L080E79B0:
	adds r0, r5, #0
	bl sub_080E7834
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r4, [r4, #1]
	cmp r0, r4
	beq .L080E7A32
	movs r0, #0xec
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	b .L080E7A32
.L080E79CC:
	ldrb r0, [r4, #0xa]
	cmp r0, #9
	bhi .L080E79D8
	adds r0, #1
	strb r0, [r4, #0xa]
	b .L080E7A32
.L080E79D8:
	movs r2, #0
	strb r2, [r4, #0xa]
	movs r0, #0xec
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0xb]
	adds r0, #1
	strb r0, [r4, #0xb]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls .L080E7A32
	strb r2, [r4, #8]
	strb r2, [r4, #0xb]
	b .L080E7A32
.L080E79FA:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	beq .L080E7A06
	subs r0, #1
	strb r0, [r4, #0xa]
	b .L080E7A32
.L080E7A06:
	ldrh r0, [r4, #6]
	subs r0, #2
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #4
	rsbs r1, r1, #0
	cmp r0, r1
	bge .L080E7A32
	strh r1, [r4, #6]
	movs r0, #1
	strb r0, [r4, #8]
	b .L080E7A32
.L080E7A20:
	ldrh r0, [r4, #6]
	adds r0, #2
	movs r1, #0
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	ble .L080E7A32
	strb r1, [r4, #8]
.L080E7A32:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x17
	bls .L080E796E
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E7A44
sub_080E7A44: @ 0x080E7A44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	mov r8, r0
	ldr r6, .L080E7AF4
	movs r7, #0
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #2
	bl memset
	add r0, sp, #0x10
	movs r1, #0
	movs r2, #0x10
	bl memset
	bl sub_080E7968
	bl Battle_IsTwoSided
	cmp r0, #0
	bne .L080E7AFC
	movs r5, #0
	movs r1, #0
	movs r2, #0xe6
	lsls r2, r2, #4
.L080E7A7A:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r4, r6, r0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq .L080E7A90
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L080E7A90:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #7
	bls .L080E7A7A
	add r0, sp, #0xc
	strb r5, [r0]
	cmp r5, #0
	bne .L080E7AA4
	b .L080E7C64
.L080E7AA4:
	movs r5, #0
.L080E7AA6:
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	movs r1, #0xe6
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r4, r6, r0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq .L080E7AE8
	cmp r0, #3
	bne .L080E7AC4
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	bne .L080E7AE8
.L080E7AC4:
	ldr r1, .L080E7AF8
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #3
	ldrsb r2, [r4, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r4, #4]
	str r1, [sp, #4]
	ldrh r1, [r4, #6]
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #2
	bl Sprite_Draw
.L080E7AE8:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L080E7AA6
	b .L080E7C6A
.L080E7AF4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E7AF8: .4byte gUnknown_086BE718
.L080E7AFC:
	movs r5, #0
	movs r1, #0
	movs r2, #0xe6
	lsls r2, r2, #4
.L080E7B04:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r4, r6, r0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq .L080E7B1A
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L080E7B1A:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls .L080E7B04
	add r0, sp, #0xc
	strb r5, [r0]
	cmp r5, #0
	beq .L080E7BA0
	movs r5, #0
.L080E7B2E:
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	movs r3, #0xe6
	lsls r3, r3, #4
	adds r0, r0, r3
	adds r4, r6, r0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq .L080E7B88
	cmp r0, #3
	bne .L080E7B4C
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	bne .L080E7B88
.L080E7B4C:
	ldr r1, .L080E7B94
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #3
	ldrsb r2, [r4, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0
	str r1, [sp]
	ldr r3, .L080E7B98
	adds r1, r6, r3
	ldrh r1, [r1]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldr r1, .L080E7B9C
	adds r3, r6, r1
	ldrh r1, [r4, #6]
	ldrh r3, [r3]
	subs r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #2
	bl Sprite_Draw
.L080E7B88:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls .L080E7B2E
	b .L080E7BA2
.L080E7B94: .4byte gUnknown_086BE718
.L080E7B98: .4byte 0x0000118C
.L080E7B9C: .4byte 0x0000119E
.L080E7BA0:
	movs r7, #2
.L080E7BA2:
	movs r5, #0
	movs r1, #4
	movs r2, #0xe6
	lsls r2, r2, #4
.L080E7BAA:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r4, r6, r0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq .L080E7BC0
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L080E7BC0:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #7
	bls .L080E7BAA
	add r0, sp, #0xc
	strb r5, [r0, #1]
	ldr r3, .L080E7C50
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080E7BDE
	add r1, sp, #0xc
	movs r0, #0
	strb r0, [r1, #1]
.L080E7BDE:
	add r0, sp, #0xc
	ldrb r0, [r0, #1]
	cmp r0, #0
	beq .L080E7C60
	movs r5, #4
.L080E7BE8:
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	movs r1, #0xe6
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r4, r6, r0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq .L080E7C42
	cmp r0, #3
	bne .L080E7C06
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	bne .L080E7C42
.L080E7C06:
	ldr r1, .L080E7C54
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #3
	ldrsb r2, [r4, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0
	str r1, [sp]
	ldr r1, .L080E7C58
	adds r3, r6, r1
	ldrh r1, [r4, #4]
	ldrh r3, [r3]
	subs r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldr r1, .L080E7C5C
	adds r3, r6, r1
	ldrh r1, [r4, #6]
	ldrh r3, [r3]
	subs r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #2
	bl Sprite_Draw
.L080E7C42:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L080E7BE8
	b .L080E7C68
	.byte 0x00, 0x00
.L080E7C50: .4byte 0x0000119C
.L080E7C54: .4byte gUnknown_086BE718
.L080E7C58: .4byte 0x0000118C
.L080E7C5C: .4byte 0x0000119E
.L080E7C60:
	cmp r7, #2
	bne .L080E7C68
.L080E7C64:
	movs r7, #1
	b .L080E7C6A
.L080E7C68:
	movs r7, #0
.L080E7C6A:
	movs r3, #0xec
	lsls r3, r3, #4
	adds r4, r6, r3
	ldrb r0, [r4]
	cmp r0, #1
	bne .L080E7C7E
	bl sub_080E7C98
	movs r0, #0
	strb r0, [r4]
.L080E7C7E:
	movs r0, #0
	mov r1, r8
	strh r0, [r1, #0x1c]
	cmp r7, #1
	bne .L080E7C8A
	strh r7, [r1, #0x1c]
.L080E7C8A:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E7C98
sub_080E7C98: @ 0x080E7C98
.L080E7C98:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r7, .L080E7D18
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080E7D1C
	ldr r2, .L080E7D20
	mov r0, sp
	bl CpuFastSet
	movs r6, #0
.L080E7CAE:
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	movs r1, #0xe6
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r5, r7, r0
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq .L080E7CF2
	adds r0, r6, #0
	adds r0, #0x10
	bl sub_080E7834
	strb r0, [r5, #1]
	ldrb r4, [r5, #1]
	lsls r4, r4, #2
	ldr r0, .L080E7D24
	adds r4, r4, r0
	ldrb r0, [r4]
	lsls r0, r0, #7
	ldr r1, .L080E7D28
	adds r0, r0, r1
	lsls r1, r6, #7
	ldr r2, .L080E7D1C
	adds r1, r1, r2
	movs r2, #0x20
	bl CpuFastSet
	strb r6, [r5]
	ldrb r0, [r4]
	strb r0, [r5, #2]
	ldrb r0, [r4, #1]
	strb r0, [r5, #3]
.L080E7CF2:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #7
	bls .L080E7CAE
	ldr r0, .L080E7D2C
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0xec
	lsls r0, r0, #4
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E7D18: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E7D1C: .4byte 0x030010B4 @ IWRAM+0x10B4
.L080E7D20: .4byte 0x01000100
.L080E7D24: .4byte gUnknown_086BE6A4
.L080E7D28: .4byte gUnknown_081A81B8
.L080E7D2C: .4byte sub_080E7364

	thumb_func_start sub_080E7D30
sub_080E7D30: @ 0x080E7D30
.L080E7D30:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Demon_GetGfxRecord
	ldrh r1, [r0]
	ldr r0, .L080E7D4C
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	beq .L080E7D50
	movs r0, #0
	b .L080E7D52
.L080E7D4C: .4byte 0x000080FF
.L080E7D50:
	movs r0, #1
.L080E7D52:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080E7D58
sub_080E7D58: @ 0x080E7D58
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	ldr r0, .L080E7DE0
	mov r8, r0
	bl Battle_IsTwoSided
	cmp r0, #0
	bne .L080E7E5C
	movs r6, #0
	movs r5, #0
.L080E7D70:
	adds r4, r5, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl Combatant_IsDead
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E7D9A
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	movs r2, #0xe6
	lsls r2, r2, #4
	adds r0, r0, r2
	add r0, r8
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq .L080E7D9A
	movs r1, #0
.L080E7D9A:
	cmp r1, #0
	bne .L080E7DAE
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L080E7DAE
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E7DAE:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L080E7D70
	cmp r6, #0
	bne .L080E7DBE
	b .L080E801A
.L080E7DBE:
	movs r0, #0
	bl sub_080E8738
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080E7DCC
	b .L080E801A
.L080E7DCC:
	movs r5, #0xda
	lsls r5, r5, #4
	add r5, r8
	movs r0, #8
	ldrsh r1, [r5, r0]
	ldr r0, .L080E7DE4
	cmp r1, r0
	beq .L080E7DE8
	ldrh r7, [r5, #8]
	b .L080E7DF2
.L080E7DE0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E7DE4: .4byte 0x00007FFF
.L080E7DE8:
	movs r0, #6
	ldrsb r0, [r5, r0]
	adds r0, #0x78
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L080E7DF2:
	movs r2, #0xa
	ldrsh r1, [r5, r2]
	ldr r0, .L080E7E00
	cmp r1, r0
	beq .L080E7E04
	ldrh r6, [r5, #0xa]
	b .L080E7E0E
.L080E7E00: .4byte 0x00007FFF
.L080E7E04:
	movs r0, #7
	ldrsb r0, [r5, r0]
	adds r0, #0x56
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080E7E0E:
	movs r0, #0x99
	lsls r0, r0, #4
	add r0, r8
	ldrh r0, [r0]
	bl sub_080E7D30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, [r5, #0xc]
	ldrb r1, [r5, #0x11]
	ldrb r3, [r5, #0x10]
	movs r2, #0xc0
	lsls r2, r2, #2
	str r2, [sp]
	ldr r2, .L080E7E54
	add r2, r8
	ldrh r2, [r2]
	adds r2, r2, r7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	ldr r2, .L080E7E58
	add r2, r8
	ldrh r2, [r2]
	subs r2, r6, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0xe
	bl sub_080AA514
	b .L080E801A
	.byte 0x00, 0x00
.L080E7E54: .4byte 0x0000118C
.L080E7E58: .4byte 0x0000119E
.L080E7E5C:
	movs r6, #0
	movs r5, #0
.L080E7E60:
	adds r0, r5, #0
	adds r0, #0x10
	bl Combatant_IsDead
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E7E88
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	movs r2, #0xe6
	lsls r2, r2, #4
	adds r0, r0, r2
	add r0, r8
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq .L080E7E88
	movs r1, #0
.L080E7E88:
	cmp r1, #0
	bne .L080E7E9E
	adds r0, r5, #0
	adds r0, #0x10
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L080E7E9E
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E7E9E:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls .L080E7E60
	cmp r6, #0
	beq .L080E7F38
	movs r0, #0
	bl sub_080E8738
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E7F38
	movs r5, #0xda
	lsls r5, r5, #4
	add r5, r8
	movs r0, #8
	ldrsh r1, [r5, r0]
	ldr r0, .L080E7ECC
	cmp r1, r0
	beq .L080E7ED0
	ldrh r7, [r5, #8]
	b .L080E7EDA
.L080E7ECC: .4byte 0x00007FFF
.L080E7ED0:
	movs r0, #6
	ldrsb r0, [r5, r0]
	adds r0, #0x50
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L080E7EDA:
	movs r2, #0xa
	ldrsh r1, [r5, r2]
	ldr r0, .L080E7EE8
	cmp r1, r0
	beq .L080E7EEC
	ldrh r6, [r5, #0xa]
	b .L080E7EF6
.L080E7EE8: .4byte 0x00007FFF
.L080E7EEC:
	movs r0, #7
	ldrsb r0, [r5, r0]
	adds r0, #0x56
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080E7EF6:
	movs r0, #0x99
	lsls r0, r0, #4
	add r0, r8
	ldrh r0, [r0]
	bl sub_080E7D30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, [r5, #0xc]
	ldrb r1, [r5, #0x11]
	ldrb r3, [r5, #0x10]
	movs r2, #0xc0
	lsls r2, r2, #2
	str r2, [sp]
	ldr r2, .L080E7FA8
	add r2, r8
	ldrh r2, [r2]
	adds r2, r2, r7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	ldr r2, .L080E7FAC
	add r2, r8
	ldrh r2, [r2]
	subs r2, r6, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0xe
	bl sub_080AA514
.L080E7F38:
	movs r5, #4
	movs r6, #0
.L080E7F3C:
	adds r4, r5, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl Combatant_IsDead
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E7F66
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	movs r2, #0xe6
	lsls r2, r2, #4
	adds r0, r0, r2
	add r0, r8
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq .L080E7F66
	movs r1, #0
.L080E7F66:
	cmp r1, #0
	bne .L080E7F7A
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L080E7F7A
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E7F7A:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L080E7F3C
	cmp r6, #0
	beq .L080E801A
	movs r0, #1
	bl sub_080E8738
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E801A
	movs r5, #0xde
	lsls r5, r5, #4
	add r5, r8
	movs r0, #8
	ldrsh r1, [r5, r0]
	ldr r0, .L080E7FB0
	cmp r1, r0
	beq .L080E7FB4
	ldrh r7, [r5, #8]
	b .L080E7FBE
.L080E7FA8: .4byte 0x0000118C
.L080E7FAC: .4byte 0x0000119E
.L080E7FB0: .4byte 0x00007FFF
.L080E7FB4:
	movs r0, #6
	ldrsb r0, [r5, r0]
	adds r0, #0xa1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L080E7FBE:
	movs r2, #0xa
	ldrsh r1, [r5, r2]
	ldr r0, .L080E7FCC
	cmp r1, r0
	beq .L080E7FD0
	ldrh r6, [r5, #0xa]
	b .L080E7FDA
.L080E7FCC: .4byte 0x00007FFF
.L080E7FD0:
	movs r0, #7
	ldrsb r0, [r5, r0]
	adds r0, #0x56
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080E7FDA:
	ldr r0, .L080E8028
	add r0, r8
	ldrh r0, [r0]
	bl sub_080E7D30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, [r5, #0xc]
	ldrb r1, [r5, #0x11]
	ldrb r3, [r5, #0x10]
	movs r2, #0xe0
	lsls r2, r2, #2
	str r2, [sp]
	ldr r2, .L080E802C
	add r2, r8
	ldrh r2, [r2]
	subs r2, r7, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	ldr r2, .L080E8030
	add r2, r8
	ldrh r2, [r2]
	subs r2, r6, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0xf
	bl sub_080AA514
.L080E801A:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E8028: .4byte 0x00000998
.L080E802C: .4byte 0x0000118C
.L080E8030: .4byte 0x0000119E

	thumb_func_start sub_080E8034
sub_080E8034: @ 0x080E8034
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	ldr r0, .L080E80D8
	mov r8, r0
	bl Battle_IsTwoSided
	cmp r0, #0
	beq .L080E804A
	b .L080E8210
.L080E804A:
	movs r6, #0
	movs r5, #0
.L080E804E:
	adds r4, r5, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl Combatant_IsDead
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E8078
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	movs r2, #0xe6
	lsls r2, r2, #4
	adds r0, r0, r2
	add r0, r8
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq .L080E8078
	movs r1, #0
.L080E8078:
	cmp r1, #0
	bne .L080E808C
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L080E808C
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E808C:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L080E804E
	ldr r0, .L080E80DC
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	beq .L080E80A8
	cmp r6, #0
	bne .L080E80AE
	movs r6, #1
.L080E80A8:
	cmp r6, #0
	bne .L080E80AE
	b .L080E8318
.L080E80AE:
	movs r0, #0
	bl sub_080E8738
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080E80BC
	b .L080E8318
.L080E80BC:
	movs r5, #0xda
	lsls r5, r5, #4
	add r5, r8
	ldrh r2, [r5, #8]
	movs r0, #8
	ldrsh r1, [r5, r0]
	ldr r0, .L080E80E0
	cmp r1, r0
	beq .L080E80E4
	movs r0, #6
	ldrsb r0, [r5, r0]
	adds r0, r2, r0
	b .L080E80EA
	.byte 0x00, 0x00
.L080E80D8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E80DC: .4byte 0x00000F6A
.L080E80E0: .4byte 0x00007FFF
.L080E80E4:
	movs r0, #6
	ldrsb r0, [r5, r0]
	adds r0, #0x78
.L080E80EA:
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrh r2, [r5, #0xa]
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	ldr r0, .L080E8104
	cmp r1, r0
	beq .L080E8108
	movs r0, #7
	ldrsb r0, [r5, r0]
	adds r0, r2, r0
	b .L080E810E
	.byte 0x00, 0x00
.L080E8104: .4byte 0x00007FFF
.L080E8108:
	movs r0, #7
	ldrsb r0, [r5, r0]
	adds r0, #0x56
.L080E810E:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x99
	lsls r0, r0, #4
	add r0, r8
	ldr r1, [r0]
	movs r0, #0x97
	lsls r0, r0, #1
	cmp r1, r0
	bne .L080E81C8
	adds r0, r1, #0
	bl sub_080E7D30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, [r5, #0xc]
	ldrb r1, [r5, #0x11]
	ldrb r3, [r5, #0x10]
	movs r2, #0xc0
	lsls r2, r2, #2
	str r2, [sp]
	ldr r2, .L080E8194
	add r2, r8
	ldrh r2, [r2]
	adds r2, r2, r7
	ldr r5, .L080E8198
	adds r2, r2, r5
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	ldr r2, .L080E819C
	add r2, r8
	ldrh r2, [r2]
	subs r2, r6, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0xe
	bl sub_080AA514
	ldr r0, .L080E81A0
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq .L080E8170
	b .L080E8318
.L080E8170:
	ldr r2, .L080E81A4
	add r2, r8
	ldrh r0, [r2]
	cmp r0, #0
	bne .L080E81AC
	ldr r1, .L080E81A8
	ldrb r0, [r1]
	adds r0, #0x10
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bhi .L080E818C
	b .L080E8318
.L080E818C:
	movs r0, #1
	strh r0, [r2]
	b .L080E8318
	.byte 0x00, 0x00
.L080E8194: .4byte 0x0000118C
.L080E8198: .4byte 0xFFFF8000
.L080E819C: .4byte 0x0000119E
.L080E81A0: .4byte 0x030031BC @ IWRAM+0x31BC
.L080E81A4: .4byte 0x000011A6
.L080E81A8: .4byte 0x0300003D @ IWRAM+0x3D
.L080E81AC:
	ldr r1, .L080E81C4
	ldrb r0, [r1]
	subs r0, #0x10
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq .L080E81BE
	b .L080E8318
.L080E81BE:
	strh r0, [r2]
	b .L080E8318
	.byte 0x00, 0x00
.L080E81C4: .4byte 0x0300003D @ IWRAM+0x3D
.L080E81C8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl sub_080E7D30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, [r5, #0xc]
	ldrb r1, [r5, #0x11]
	ldrb r3, [r5, #0x10]
	movs r2, #0xc0
	lsls r2, r2, #2
	str r2, [sp]
	ldr r2, .L080E8208
	add r2, r8
	ldrh r2, [r2]
	adds r2, r2, r7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	ldr r2, .L080E820C
	add r2, r8
	ldrh r2, [r2]
	subs r2, r6, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0xe
	bl sub_080AA514
	b .L080E8318
.L080E8208: .4byte 0x0000118C
.L080E820C: .4byte 0x0000119E
.L080E8210:
	movs r6, #0
	movs r5, #0
.L080E8214:
	adds r4, r5, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl Combatant_IsDead
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E823E
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	movs r2, #0xe6
	lsls r2, r2, #4
	adds r0, r0, r2
	add r0, r8
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq .L080E823E
	movs r1, #0
.L080E823E:
	cmp r1, #0
	bne .L080E8252
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L080E8252
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E8252:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls .L080E8214
	movs r0, #0x99
	lsls r0, r0, #4
	add r0, r8
	ldr r1, [r0]
	movs r0, #0x88
	lsls r0, r0, #1
	cmp r1, r0
	bne .L080E8278
	movs r0, #0
	bl sub_080EDA24
	cmp r0, #0
	bne .L080E8278
	movs r6, #0
.L080E8278:
	cmp r6, #0
	beq .L080E8318
	movs r0, #0
	bl sub_080E8738
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E8318
	movs r5, #0xda
	lsls r5, r5, #4
	add r5, r8
	ldrh r2, [r5, #8]
	movs r0, #8
	ldrsh r1, [r5, r0]
	ldr r0, .L080E82A4
	cmp r1, r0
	beq .L080E82A8
	movs r0, #6
	ldrsb r0, [r5, r0]
	adds r0, r2, r0
	b .L080E82AE
	.byte 0x00, 0x00
.L080E82A4: .4byte 0x00007FFF
.L080E82A8:
	movs r0, #6
	ldrsb r0, [r5, r0]
	adds r0, #0x50
.L080E82AE:
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrh r2, [r5, #0xa]
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	ldr r0, .L080E82C8
	cmp r1, r0
	beq .L080E82CC
	movs r0, #7
	ldrsb r0, [r5, r0]
	adds r0, r2, r0
	b .L080E82D2
	.byte 0x00, 0x00
.L080E82C8: .4byte 0x00007FFF
.L080E82CC:
	movs r0, #7
	ldrsb r0, [r5, r0]
	adds r0, #0x56
.L080E82D2:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x99
	lsls r0, r0, #4
	add r0, r8
	ldrh r0, [r0]
	bl sub_080E7D30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, [r5, #0xc]
	ldrb r1, [r5, #0x11]
	ldrb r3, [r5, #0x10]
	movs r2, #0xc0
	lsls r2, r2, #2
	str r2, [sp]
	ldr r2, .L080E8324
	add r2, r8
	ldrh r2, [r2]
	adds r2, r2, r7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	ldr r2, .L080E8328
	add r2, r8
	ldrh r2, [r2]
	subs r2, r6, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0xe
	bl sub_080AA514
.L080E8318:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E8324: .4byte 0x0000118C
.L080E8328: .4byte 0x0000119E

	thumb_func_start sub_080E832C
sub_080E832C: @ 0x080E832C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	ldr r7, .L080E83C4
	movs r5, #4
	movs r6, #0
.L080E833A:
	adds r4, r5, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl Combatant_IsDead
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E8364
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	movs r2, #0xe6
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r0, r7, r0
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq .L080E8364
	movs r1, #0
.L080E8364:
	cmp r1, #0
	bne .L080E8378
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L080E8378
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080E8378:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L080E833A
	ldr r5, .L080E83C8
	adds r0, r7, r5
	ldr r1, [r0]
	ldr r0, .L080E83CC
	cmp r1, r0
	bne .L080E839A
	movs r0, #1
	bl sub_080EDA24
	cmp r0, #0
	bne .L080E839A
	movs r6, #0
.L080E839A:
	cmp r6, #0
	beq .L080E8444
	movs r0, #1
	bl sub_080E8738
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E8444
	movs r0, #0xde
	lsls r0, r0, #4
	adds r5, r7, r0
	ldrh r2, [r5, #8]
	movs r0, #8
	ldrsh r1, [r5, r0]
	ldr r0, .L080E83D0
	cmp r1, r0
	beq .L080E83D4
	movs r0, #6
	ldrsb r0, [r5, r0]
	adds r0, r2, r0
	b .L080E83DA
.L080E83C4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E83C8: .4byte 0x00000994
.L080E83CC: .4byte 0x0000010F
.L080E83D0: .4byte 0x00007FFF
.L080E83D4:
	movs r0, #6
	ldrsb r0, [r5, r0]
	adds r0, #0xa1
.L080E83DA:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldrh r2, [r5, #0xa]
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	ldr r0, .L080E83F4
	cmp r1, r0
	beq .L080E83F8
	movs r0, #7
	ldrsb r0, [r5, r0]
	adds r0, r2, r0
	b .L080E83FE
.L080E83F4: .4byte 0x00007FFF
.L080E83F8:
	movs r0, #7
	ldrsb r0, [r5, r0]
	adds r0, #0x56
.L080E83FE:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r1, .L080E8450
	adds r0, r7, r1
	ldrh r0, [r0]
	bl sub_080E7D30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, [r5, #0xc]
	ldrb r1, [r5, #0x11]
	ldrb r3, [r5, #0x10]
	movs r2, #0xe0
	lsls r2, r2, #2
	str r2, [sp]
	ldr r5, .L080E8454
	adds r2, r7, r5
	ldrh r2, [r2]
	mov r5, r8
	subs r2, r5, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	ldr r5, .L080E8458
	adds r2, r7, r5
	ldrh r2, [r2]
	subs r2, r6, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0xf
	bl sub_080AA514
.L080E8444:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E8450: .4byte 0x00000994
.L080E8454: .4byte 0x0000118C
.L080E8458: .4byte 0x0000119E

	thumb_func_start sub_080E845C
sub_080E845C: @ 0x080E845C
.L080E845C:
	push {r4, lr}
	lsls r0, r0, #0x18
	ldr r3, .L080E8478
	lsrs r0, r0, #0x12
	movs r4, #0xda
	lsls r4, r4, #4
	adds r0, r0, r4
	adds r0, r0, r3
	strb r1, [r0, #6]
	strb r2, [r0, #7]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E8478: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080E847C
sub_080E847C: @ 0x080E847C
.L080E847C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E8580
	bl Palette_IsBg13Black
	cmp r0, #1
	beq .L080E8580
	ldrb r1, [r5, #5]
	movs r0, #5
	ldrsb r0, [r5, r0]
	cmp r0, #1
	bne .L080E84B8
	ldrb r0, [r5, #4]
	adds r0, #1
	strb r0, [r5, #4]
	movs r0, #4
	ldrsb r0, [r5, r0]
	ldrb r2, [r5, #3]
	cmp r0, r2
	bne .L080E84CA
	b .L080E84C4
.L080E84B8:
	ldrb r0, [r5, #4]
	subs r0, #1
	strb r0, [r5, #4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080E84CA
.L080E84C4:
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r5, #5]
.L080E84CA:
	movs r3, #0
	mov r8, r3
	ldr r0, [r5, #0x28]
	mov sl, r0
	movs r1, #8
	adds r1, r1, r5
	mov sb, r1
	movs r2, #0xf8
	lsls r2, r2, #5
	mov ip, r2
.L080E84DE:
	ldrb r0, [r5]
	movs r2, #4
	ldrsb r2, [r5, r2]
	muls r0, r2, r0
	adds r0, #0xc0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r3, r8
	lsls r1, r3, #1
	mov r3, sb
	adds r0, r3, r1
	ldrh r6, [r0]
	movs r0, #0x1f
	ands r0, r6
	muls r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r7, r1, #0
	cmp r4, ip
	bls .L080E8508
	mov r4, ip
.L080E8508:
	lsrs r4, r4, #8
	ldrb r0, [r5, #1]
	muls r0, r2, r0
	adds r0, #0xc0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r0, r1, #0
	ands r0, r6
	lsrs r0, r0, #5
	muls r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, ip
	bls .L080E852C
	adds r3, r1, #0
	b .L080E8532
.L080E852C:
	mov r0, ip
	ands r0, r3
	lsrs r3, r0, #3
.L080E8532:
	ldrb r0, [r5, #2]
	muls r0, r2, r0
	adds r0, #0xc0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov r1, sb
	adds r0, r1, r7
	ldrh r1, [r0]
	movs r6, #0xf8
	lsls r6, r6, #7
	adds r0, r6, #0
	ands r0, r1
	lsrs r0, r0, #0xa
	muls r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #0xf8
	lsls r1, r1, #0x15
	lsrs r0, r1, #0x10
	cmp r2, r0
	bls .L080E8560
	adds r2, r6, #0
	b .L080E8564
.L080E8560:
	ands r2, r0
	lsls r2, r2, #2
.L080E8564:
	mov r1, sl
	adds r0, r7, r1
	adds r1, r4, r3
	adds r1, r2, r1
	strh r1, [r0]
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0xf
	bls .L080E84DE
	bl Palette_MarkDirty
.L080E8580:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E8590
sub_080E8590: @ 0x080E8590
.L080E8590:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E86A4
	bl Palette_IsBg13Black
	cmp r0, #1
	beq .L080E86A4
	ldrb r1, [r5, #5]
	movs r0, #5
	ldrsb r0, [r5, r0]
	cmp r0, #1
	bne .L080E85D4
	ldrb r0, [r5, #4]
	adds r0, #1
	strb r0, [r5, #4]
	movs r0, #4
	ldrsb r0, [r5, r0]
	ldrb r2, [r5, #3]
	cmp r0, r2
	bne .L080E85E6
	b .L080E85E0
.L080E85D4:
	ldrb r0, [r5, #4]
	subs r0, #1
	strb r0, [r5, #4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080E85E6
.L080E85E0:
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r5, #5]
.L080E85E6:
	movs r0, #0
	mov sb, r0
	movs r1, #0xf8
	lsls r1, r1, #0x15
	mov sl, r1
.L080E85F0:
	ldr r0, [sp]
	mov r2, sb
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E8692
	ldrb r0, [r5]
	movs r3, #4
	ldrsb r3, [r5, r3]
	muls r0, r3, r0
	adds r0, #0xc0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r2, #1
	adds r2, r5, #0
	adds r2, #8
	adds r0, r2, r1
	ldrh r7, [r0]
	movs r0, #0x1f
	ands r0, r7
	muls r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r0, sl
	lsrs r6, r0, #0x10
	mov r8, r1
	mov ip, r2
	cmp r4, r6
	bls .L080E862E
	adds r4, r6, #0
.L080E862E:
	lsrs r4, r4, #8
	ldrb r0, [r5, #1]
	muls r0, r3, r0
	adds r0, #0xc0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r0, r1, #0
	ands r0, r7
	lsrs r0, r0, #5
	muls r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r6
	bls .L080E8652
	adds r2, r1, #0
	b .L080E8658
.L080E8652:
	adds r0, r6, #0
	ands r0, r2
	lsrs r2, r0, #3
.L080E8658:
	ldrb r0, [r5, #2]
	muls r0, r3, r0
	adds r0, #0xc0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov r0, ip
	add r0, r8
	ldrh r1, [r0]
	movs r6, #0xf8
	lsls r6, r6, #7
	adds r0, r6, #0
	ands r0, r1
	lsrs r0, r0, #0xa
	muls r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov r1, sl
	lsrs r0, r1, #0x10
	cmp r3, r0
	bls .L080E8684
	adds r3, r6, #0
	b .L080E8688
.L080E8684:
	ands r3, r0
	lsls r3, r3, #2
.L080E8688:
	ldr r1, [r5, #0x28]
	add r1, r8
	adds r0, r4, r2
	adds r0, r3, r0
	strh r0, [r1]
.L080E8692:
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #0xf
	bls .L080E85F0
	bl Palette_MarkDirty
.L080E86A4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080E86B4
sub_080E86B4: @ 0x080E86B4
.L080E86B4:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	adds r0, r6, #0
	bl Demon_GetGfxRecord
	adds r5, r0, #0
	ldrb r1, [r5, #1]
	movs r2, #0x80
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E8722
	movs r0, #0x3f
	ands r0, r1
	lsls r0, r0, #1
	movs r1, #0
	strb r0, [r4, #4]
	strb r0, [r4, #3]
	strb r1, [r4, #5]
	movs r0, #0xff
	strb r0, [r4, #6]
	strb r2, [r4, #7]
	ldrb r1, [r4, #3]
	movs r0, #0x80
	bl __divsi3
	strb r0, [r4, #2]
	strb r0, [r4, #1]
	strb r0, [r4]
	str r7, [r4, #0x28]
	ldr r5, [r5, #4]
	ldr r0, .L080E872C
	ldr r1, [r0]
	ldr r0, .L080E8730
	cmp r1, r0
	bne .L080E8710
	adds r0, r6, #0
	bl sub_080C2644
	cmp r0, #0
	bne .L080E8710
	ldr r5, .L080E8734
.L080E8710:
	adds r2, r4, #0
	adds r2, #8
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
.L080E8722:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E872C: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080E8730: .4byte sub_080D977C
.L080E8734: .4byte gUnknown_086BE584

	thumb_func_start sub_080E8738
sub_080E8738: @ 0x080E8738
.L080E8738:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r6, .L080E87B0
	lsls r0, r5, #6
	movs r1, #0xda
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r4, r0, r6
	ldrb r0, [r4, #4]
	cmp r0, #2
	beq .L080E876A
	cmp r0, #2
	ble .L080E876E
	cmp r0, #3
	bne .L080E876E
	adds r0, r4, #0
	bl sub_080E8B20
	cmp r0, #0
	beq .L080E876E
	adds r0, r5, #0
	movs r1, #0
	bl sub_080E8B78
.L080E876A:
	movs r0, #1
	strb r0, [r4, #4]
.L080E876E:
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne .L080E8776
	b .L080E88B2
.L080E8776:
	lsls r1, r5, #2
	movs r2, #0x99
	lsls r2, r2, #4
	adds r0, r6, r2
	adds r5, r0, r1
	ldrh r0, [r5]
	bl Demon_GetGfxRecord
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r0, #0
	bne .L080E885C
	ldrb r1, [r6, #1]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080E880A
	ldr r0, [r6, #8]
	ldrb r3, [r4, #2]
	lsls r1, r3, #3
	ldr r0, [r0, #4]
	adds r5, r0, r1
	ldrb r0, [r4, #1]
	adds r2, r0, #0
	cmp r2, #0
	beq .L080E87B4
	subs r0, #1
	strb r0, [r4, #1]
	b .L080E87D8
.L080E87B0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E87B4:
	adds r0, r3, #1
	strb r0, [r4, #2]
	ldr r1, [r6, #8]
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	ldr r1, [r1, #4]
	adds r5, r1, r0
	ldrh r1, [r5, #4]
	ldr r0, .L080E87F8
	cmp r1, r0
	bne .L080E87D0
	strb r2, [r4, #2]
	ldr r0, [r6, #8]
	ldr r5, [r0, #4]
.L080E87D0:
	ldrh r0, [r5, #4]
	lsls r0, r0, #1
	strb r0, [r4, #1]
	strb r2, [r4, #3]
.L080E87D8:
	ldr r0, [r5]
	str r0, [r4, #0xc]
	ldrb r0, [r4, #4]
	cmp r0, #3
	beq .L080E8848
	ldrb r1, [r6, #1]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0xc0
	beq .L080E87FC
	adds r0, r4, #0
	adds r0, #0x14
	bl sub_080E847C
	b .L080E8848
	.byte 0x00, 0x00
.L080E87F8: .4byte 0x0000FFFF
.L080E87FC:
	adds r0, r4, #0
	adds r0, #0x14
	movs r1, #0
	bl sub_080E8590
	ldr r0, [r5]
	b .L080E8846
.L080E880A:
	ldrb r0, [r4, #1]
	adds r2, r0, #0
	cmp r2, #0
	beq .L080E8818
	subs r0, #1
	strb r0, [r4, #1]
	b .L080E8844
.L080E8818:
	ldrb r0, [r4, #2]
	adds r0, #1
	strb r0, [r4, #2]
	ldrb r0, [r6, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	ldrb r0, [r4, #2]
	ldr r3, .L080E8854
	adds r0, r0, r3
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0xff
	bne .L080E883C
	strb r2, [r4, #2]
	ldrb r1, [r6, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r1, r0, r3
.L080E883C:
	ldrb r0, [r1]
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4, #3]
.L080E8844:
	ldr r0, .L080E8858
.L080E8846:
	str r0, [r4, #0xc]
.L080E8848:
	movs r0, #2
	strb r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #0x11]
	b .L080E88B2
	.byte 0x00, 0x00
.L080E8854: .4byte gUnknown_086BE75C
.L080E8858: .4byte gUnknown_080F649C
.L080E885C:
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq .L080E8868
	subs r0, #1
	strb r0, [r4, #1]
	b .L080E88B2
.L080E8868:
	ldrh r0, [r5]
	bl sub_080E8AC0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L080E887E
	movs r0, #2
	strb r0, [r4, #0x10]
	movs r0, #1
	b .L080E8884
.L080E887E:
	movs r0, #3
	strb r0, [r4, #0x10]
	movs r0, #9
.L080E8884:
	strb r0, [r4, #0x11]
	ldrb r0, [r4, #2]
	adds r0, #1
	movs r3, #0
	strb r0, [r4, #2]
	ldr r1, [r6, #8]
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	ldr r1, [r1, #4]
	adds r2, r1, r0
	ldrh r1, [r2, #4]
	ldr r0, .L080E88BC
	cmp r1, r0
	bne .L080E88A6
	strb r3, [r4, #2]
	ldr r0, [r6, #8]
	ldr r2, [r0, #4]
.L080E88A6:
	ldrh r0, [r2, #4]
	lsls r0, r0, #1
	strb r0, [r4, #1]
	strb r3, [r4, #3]
	ldr r0, [r2]
	str r0, [r4, #0xc]
.L080E88B2:
	ldrb r0, [r4, #4]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080E88BC: .4byte 0x0000FFFF

	thumb_func_start sub_080E88C0
sub_080E88C0: @ 0x080E88C0
.L080E88C0:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	ldr r1, .L080E8914
	movs r7, #0
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne .L080E88D0
	movs r0, #0
.L080E88D0:
	lsls r0, r0, #6
	movs r2, #0xda
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r4, r0, r1
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne .L080E88E2
	b .L080E8A1C
.L080E88E2:
	ldrh r0, [r4, #0x12]
	bl Demon_GetGfxRecord
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r0, #0
	bne .L080E89C4
	ldrb r1, [r6, #1]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080E8972
	ldr r1, [r6, #8]
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	ldr r1, [r1, #4]
	adds r5, r1, r0
	ldr r0, [r5]
	str r0, [r4, #0xc]
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq .L080E8918
	subs r0, #1
	strb r0, [r4, #1]
	b .L080E8944
.L080E8914: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E8918:
	ldrb r0, [r4, #2]
	adds r0, #1
	strb r0, [r4, #2]
	ldr r1, [r6, #8]
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	ldr r1, [r1, #4]
	adds r5, r1, r0
	ldrh r1, [r5, #4]
	ldr r0, .L080E8960
	cmp r1, r0
	bne .L080E8936
	strb r7, [r4, #2]
	ldr r0, [r6, #8]
	ldr r5, [r0, #4]
.L080E8936:
	ldrh r0, [r5, #4]
	lsls r0, r0, #1
	strb r0, [r4, #1]
	strb r7, [r4, #3]
	movs r7, #1
	ldr r0, [r5]
	str r0, [r4, #0xc]
.L080E8944:
	ldrb r0, [r4, #4]
	cmp r0, #3
	beq .L080E89B0
	ldrb r1, [r6, #1]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0xc0
	beq .L080E8964
	adds r0, r4, #0
	adds r0, #0x14
	bl sub_080E847C
	b .L080E89B0
	.byte 0x00, 0x00
.L080E8960: .4byte 0x0000FFFF
.L080E8964:
	adds r0, r4, #0
	adds r0, #0x14
	movs r1, #0
	bl sub_080E8590
	ldr r0, [r5]
	b .L080E89AE
.L080E8972:
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq .L080E897E
	subs r0, #1
	strb r0, [r4, #1]
	b .L080E89AC
.L080E897E:
	ldrb r0, [r4, #2]
	adds r0, #1
	strb r0, [r4, #2]
	ldrb r0, [r6, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	ldrb r0, [r4, #2]
	ldr r2, .L080E89BC
	adds r0, r0, r2
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0xff
	bne .L080E89A2
	strb r7, [r4, #2]
	ldrb r1, [r6, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r1, r0, r2
.L080E89A2:
	ldrb r0, [r1]
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4, #3]
	movs r7, #1
.L080E89AC:
	ldr r0, .L080E89C0
.L080E89AE:
	str r0, [r4, #0xc]
.L080E89B0:
	movs r0, #2
	strb r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #0x11]
	b .L080E8A1C
	.byte 0x00, 0x00
.L080E89BC: .4byte gUnknown_086BE75C
.L080E89C0: .4byte gUnknown_080F649C
.L080E89C4:
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq .L080E89D0
	subs r0, #1
	strb r0, [r4, #1]
	b .L080E8A1C
.L080E89D0:
	ldrh r0, [r4, #0x12]
	bl sub_080E8AC0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L080E89E6
	movs r0, #2
	strb r0, [r4, #0x10]
	movs r0, #1
	b .L080E89EC
.L080E89E6:
	movs r0, #3
	strb r0, [r4, #0x10]
	movs r0, #9
.L080E89EC:
	strb r0, [r4, #0x11]
	ldrb r0, [r4, #2]
	adds r0, #1
	movs r3, #0
	strb r0, [r4, #2]
	ldr r1, [r6, #8]
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	ldr r1, [r1, #4]
	adds r2, r1, r0
	ldrh r1, [r2, #4]
	ldr r0, .L080E8A24
	cmp r1, r0
	bne .L080E8A0E
	strb r3, [r4, #2]
	ldr r0, [r6, #8]
	ldr r2, [r0, #4]
.L080E8A0E:
	ldrh r0, [r2, #4]
	lsls r0, r0, #1
	strb r0, [r4, #1]
	strb r3, [r4, #3]
	ldr r0, [r2]
	str r0, [r4, #0xc]
	movs r7, #1
.L080E8A1C:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080E8A24: .4byte 0x0000FFFF

	thumb_func_start sub_080E8A28
sub_080E8A28: @ 0x080E8A28
.L080E8A28:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	ldr r1, .L080E8A6C
	lsrs r5, r0, #0x18
	cmp r5, #3
	bne .L080E8A3A
	movs r5, #0
.L080E8A3A:
	lsls r0, r5, #6
	movs r3, #0xda
	lsls r3, r3, #4
	adds r0, r0, r3
	adds r4, r0, r1
	movs r1, #0
	strb r1, [r4, #2]
	strb r1, [r4, #1]
	movs r0, #1
	strb r0, [r4, #4]
	strb r1, [r4, #7]
	strb r1, [r4, #6]
	strb r1, [r4, #5]
	strh r2, [r4, #0x12]
	str r1, [r4, #0xc]
	ldrh r0, [r4, #0x12]
	bl Demon_GetGfxRecord
	cmp r5, #1
	beq .L080E8A80
	cmp r5, #1
	bgt .L080E8A70
	cmp r5, #0
	beq .L080E8A76
	b .L080E8A8A
.L080E8A6C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E8A70:
	cmp r5, #2
	beq .L080E8A88
	b .L080E8A8A
.L080E8A76:
	ldr r6, .L080E8A7C
	b .L080E8A8A
	.byte 0x00, 0x00
.L080E8A7C: .4byte 0x03003170 @ IWRAM+0x3170
.L080E8A80:
	ldr r6, .L080E8A84
	b .L080E8A8A
.L080E8A84: .4byte 0x03003190 @ IWRAM+0x3190
.L080E8A88:
	ldr r6, .L080E8A9C
.L080E8A8A:
	adds r1, r4, #0
	adds r1, #0x14
	ldrh r2, [r4, #0x12]
	adds r0, r6, #0
	bl sub_080E86B4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080E8A9C: .4byte 0x03003150 @ IWRAM+0x3150

	thumb_func_start sub_080E8AA0
sub_080E8AA0: @ 0x080E8AA0
.L080E8AA0:
	push {lr}
	lsls r0, r0, #0x18
	ldr r1, .L080E8ABC
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne .L080E8AAE
	movs r0, #0
.L080E8AAE:
	lsls r0, r0, #6
	movs r2, #0xda
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r0, r0, r1
	pop {r1}
	bx r1
.L080E8ABC: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080E8AC0
sub_080E8AC0: @ 0x080E8AC0
.L080E8AC0:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, .L080E8AE8
	ldr r1, [r0]
	ldr r0, .L080E8AEC
	cmp r1, r0
	beq .L080E8AF4
	ldr r0, .L080E8AF0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080E8AE2
	cmp r2, #0xff
	bhi .L080E8AF4
.L080E8AE2:
	movs r0, #0
	b .L080E8AF6
	.byte 0x00, 0x00
.L080E8AE8: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080E8AEC: .4byte sub_080D977C
.L080E8AF0: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080E8AF4:
	movs r0, #3
.L080E8AF6:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080E8AFC
sub_080E8AFC: @ 0x080E8AFC
.L080E8AFC:
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, .L080E8B1C
	lsls r1, r0, #6
	movs r3, #0xda
	lsls r3, r3, #4
	adds r1, r1, r3
	adds r1, r1, r2
	movs r2, #3
	strb r2, [r1, #4]
	movs r1, #1
	bl sub_080E8B78
	pop {r0}
	bx r0
.L080E8B1C: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080E8B20
sub_080E8B20: @ 0x080E8B20
.L080E8B20:
	push {r4, r5, lr}
	sub sp, #0x28
	adds r2, r0, #0
	mov r1, sp
	ldr r0, .L080E8B60
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [r0]
	str r0, [r1]
	ldrb r1, [r2, #5]
	movs r0, #5
	ldrsb r0, [r2, r0]
	cmp r0, #9
	bgt .L080E8B64
	lsls r0, r0, #2
	.2byte 0x4468 @ add r0, sp, r0
	ldrh r0, [r0]
	strb r0, [r2, #6]
	movs r0, #5
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	.2byte 0x4468 @ add r0, sp, r0
	ldrh r0, [r0, #2]
	strb r0, [r2, #7]
	adds r0, r1, #1
	strb r0, [r2, #5]
	movs r0, #0
	b .L080E8B6E
.L080E8B60: .4byte gUnknown_086BE7BC
.L080E8B64:
	movs r0, #0
	strb r0, [r2, #6]
	strb r0, [r2, #7]
	strb r0, [r2, #5]
	movs r0, #1
.L080E8B6E:
	add sp, #0x28
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080E8B78
sub_080E8B78: @ 0x080E8B78
.L080E8B78:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r3, r1, #0
	ldr r7, .L080E8BAC
	adds r0, r4, #0
	adds r0, #0xe
	lsls r0, r0, #5
	ldr r1, .L080E8BB0
	adds r6, r0, r1
	cmp r3, #0
	bne .L080E8BB4
	lsls r0, r4, #2
	movs r2, #0x99
	lsls r2, r2, #4
	adds r1, r7, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	bl Demon_GetGfxRecord
	ldr r5, [r0, #4]
	b .L080E8BC4
	.byte 0x00, 0x00
.L080E8BAC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E8BB0: .4byte 0x03002FB0 @ IWRAM+0x2FB0
.L080E8BB4:
	cmp r3, #0
	blt .L080E8BC4
	cmp r3, #5
	bgt .L080E8BC4
	ldr r1, .L080E8C00
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r5, [r0]
.L080E8BC4:
	ldr r0, .L080E8C04
	ldr r1, [r0]
	ldr r0, .L080E8C08
	cmp r1, r0
	bne .L080E8BE4
	lsls r1, r4, #2
	movs r2, #0x99
	lsls r2, r2, #4
	adds r0, r7, r2
	adds r0, r0, r1
	ldr r0, [r0]
	bl sub_080C2644
	cmp r0, #0
	bne .L080E8BE4
	ldr r5, .L080E8C0C
.L080E8BE4:
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r5, #0
	adds r2, r6, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E8C00: .4byte gUnknown_086BE884
.L080E8C04: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080E8C08: .4byte sub_080D977C
.L080E8C0C: .4byte gUnknown_086BE584

	thumb_func_start sub_080E8C10
sub_080E8C10: @ 0x080E8C10
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #6]
	cmp r0, #0
	beq .L080E8C1C
	movs r0, #1
.L080E8C1C:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E8C24
sub_080E8C24: @ 0x080E8C24
	push {lr}
	ldrb r0, [r0, #6]
	cmp r0, #0
	beq .L080E8C32
	movs r0, #0
	bl sub_080E8DB4
.L080E8C32:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E8C38
sub_080E8C38: @ 0x080E8C38
	push {r4, lr}
	ldr r4, .L080E8C4C
	ldr r0, .L080E8C50
	ldr r1, .L080E8C54
	bl Task_Create
	str r0, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0
.L080E8C4C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E8C50: .4byte gUnknown_086BE89C
.L080E8C54: .4byte 0x0000FFFF

	thumb_func_start sub_080E8C58
sub_080E8C58: @ 0x080E8C58
.L080E8C58:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r4, .L080E8CB0
	movs r2, #0
	ldr r1, .L080E8CB4
	ldr r7, .L080E8CB8
	adds r0, r4, r7
	str r0, [r1]
	ldr r1, .L080E8CBC
	adds r0, r4, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	bne .L080E8D42
	movs r0, #0xda
	lsls r0, r0, #4
	adds r1, r4, r0
	strb r2, [r1]
	movs r7, #0xde
	lsls r7, r7, #4
	adds r0, r4, r7
	strb r2, [r0]
	ldr r0, .L080E8CC0
	cmp r3, r0
	beq .L080E8CD0
	movs r7, #0x99
	lsls r7, r7, #4
	adds r0, r4, r7
	str r3, [r0]
	movs r0, #1
	strb r0, [r1]
	ldr r1, .L080E8CC4
	adds r0, r4, r1
	ldr r1, .L080E8CC8
	strh r1, [r0]
	ldr r3, .L080E8CCC
	adds r0, r4, r3
	strh r1, [r0]
	b .L080E8CD2
.L080E8CB0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E8CB4: .4byte 0x03006434 @ IWRAM+0x6434
.L080E8CB8: .4byte 0x00000F6C
.L080E8CBC: .4byte 0x00000F6A
.L080E8CC0: .4byte 0x0000FFFF
.L080E8CC4: .4byte 0x00000DA8
.L080E8CC8: .4byte 0x00007FFF
.L080E8CCC: .4byte 0x00000DAA
.L080E8CD0:
	movs r2, #1
.L080E8CD2:
	ldr r0, .L080E8CF8
	cmp r5, r0
	beq .L080E8D0C
	ldr r7, .L080E8CFC
	adds r0, r4, r7
	str r5, [r0]
	movs r0, #0xde
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, .L080E8D00
	adds r0, r4, r1
	ldr r1, .L080E8D04
	strh r1, [r0]
	ldr r3, .L080E8D08
	adds r0, r4, r3
	strh r1, [r0]
	b .L080E8D12
.L080E8CF8: .4byte 0x0000FFFF
.L080E8CFC: .4byte 0x00000994
.L080E8D00: .4byte 0x00000DE8
.L080E8D04: .4byte 0x00007FFF
.L080E8D08: .4byte 0x00000DEA
.L080E8D0C:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
.L080E8D12:
	cmp r2, #2
	beq .L080E8D42
	ldr r0, .L080E8D48
	bl VBlankTask_Add
	ldr r7, .L080E8D4C
	adds r1, r4, r7
	str r0, [r1]
	ldr r1, .L080E8D50
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, .L080E8D54
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, .L080E8D58
	bl sub_080E5668
	ldr r0, .L080E8D5C
	ldr r1, .L080E8D60
	bl Task_Create
	str r0, [r4, #4]
	strb r6, [r0, #6]
.L080E8D42:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E8D48: .4byte sub_080E5528
.L080E8D4C: .4byte 0x00001114
.L080E8D50: .4byte 0x00000DA3
.L080E8D54: .4byte 0x00000DE3
.L080E8D58: .4byte sub_080E5674
.L080E8D5C: .4byte gUnknown_086BE89C
.L080E8D60: .4byte 0x0000FFFF

	thumb_func_start sub_080E8D64
sub_080E8D64: @ 0x080E8D64
.L080E8D64:
	push {lr}
	ldr r0, .L080E8D78
	ldr r1, .L080E8D7C
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080E8D80
	movs r0, #0
	b .L080E8D82
	.byte 0x00, 0x00
.L080E8D78: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E8D7C: .4byte 0x00000EC3
.L080E8D80:
	movs r0, #1
.L080E8D82:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
