	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080F17C0
sub_080F17C0: @ 0x080F17C0
.L080F17C0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	lsls r0, r1, #0x10
	ldr r6, .L080F181C
	movs r1, #0x17
	ldrsb r1, [r7, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	adds r1, r7, #0
	adds r1, #0x5c
	ldrb r1, [r1]
	str r1, [sp]
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, .L080F1820
	adds r1, r6, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	bl sub_080EFFF8
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	mov sb, r0
	mov r2, r8
	cmp r2, #8
	bne .L080F1830
	ldr r0, [sp]
	cmp r0, #0xf8
	bne .L080F1828
	ldr r3, .L080F1824
	adds r0, r6, r3
	ldrh r0, [r0]
	str r0, [sp]
	b .L080F1830
.L080F181C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F1820: .4byte 0x00000F66
.L080F1824: .4byte 0x00001194
.L080F1828:
	movs r1, #0xc
	mov r2, sp
	bl Item_GetAttribute
.L080F1830:
	ldr r1, .L080F184C
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xd
	bls .L080F1840
	bl .L080F20C6
.L080F1840:
	lsls r0, r0, #2
	ldr r1, .L080F1850
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080F184C: .4byte 0x0000097E
.L080F1850: .4byte gUnknown_080F1854
	.global gUnknown_080F1854
gUnknown_080F1854:
.L080F1854: @ jump table
	.4byte .L080F188C
	.4byte .L080F1944
	.4byte .L080F1974
	.4byte .L080F1B5C
	.4byte .L080F1C4C
	.4byte .L080F1CBC
	.4byte .L080F2034
	.4byte .L080F204C
	.4byte .L080F1FB0
	.4byte .L080F2000
	.4byte .L080F1E48
	.4byte .L080F1E2C
	.4byte .L080F1E84
	.4byte .L080F20B0
.L080F188C:
	movs r0, #0
	bl sub_080EDA7C
	ldr r1, .L080F18DC
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	str r0, [r1]
	lsls r0, r5, #0x10
	asrs r3, r0, #0x10
	str r3, [r1, #4]
	movs r2, #0
	str r2, [r1, #0x18]
	movs r4, #1
	str r4, [r1, #0xc]
	ldr r0, .L080F18E0
	strh r2, [r0]
	mov r5, r8
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	ldr r5, .L080F18E4
	adds r0, r0, r5
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080F18C0
	cmp r1, #0xa
	bne .L080F18F0
.L080F18C0:
	ldr r0, .L080F18E8
	strh r2, [r0]
	ldr r1, .L080F18EC
	adds r0, r6, r1
	strh r4, [r0]
	adds r0, r3, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F18D8
	bl .L080F20C6
.L080F18D8:
	bl .L080F20A0
.L080F18DC: .4byte 0x03000088 @ IWRAM+0x88
.L080F18E0: .4byte 0x03000082 @ IWRAM+0x82
.L080F18E4: .4byte 0xFFFC0000
.L080F18E8: .4byte 0x030000AE @ IWRAM+0xAE
.L080F18EC: .4byte 0x0000097E
.L080F18F0:
	ldr r1, [sp]
	adds r0, r1, #0
	subs r0, #0x13
	cmp r0, #9
	bls .L080F1910
	cmp r1, #0x3f
	ble .L080F1928
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080F1928
.L080F1910:
	ldr r0, .L080F1920
	strh r4, [r0]
	ldr r3, .L080F1924
	adds r1, r6, r3
	movs r0, #3
	strh r0, [r1]
	bl .L080F20C6
.L080F1920: .4byte 0x030000AE @ IWRAM+0xAE
.L080F1924: .4byte 0x0000097E
.L080F1928:
	ldr r1, .L080F193C
	movs r0, #0
	strh r0, [r1]
	ldr r5, .L080F1940
	adds r1, r6, r5
	movs r0, #2
	strh r0, [r1]
	bl .L080F20C6
	.byte 0x00, 0x00
.L080F193C: .4byte 0x030000AE @ IWRAM+0xAE
.L080F1940: .4byte 0x0000097E
.L080F1944:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	bl Battle_PhysicalDamage
	ldr r1, .L080F1960
	str r0, [r1, #0x18]
	cmp r0, #0
	bne .L080F1968
	ldr r0, .L080F1964
	adds r1, r6, r0
	b .L080F1B40
	.byte 0x00, 0x00
.L080F1960: .4byte 0x03000088 @ IWRAM+0x88
.L080F1964: .4byte 0x0000097E
.L080F1968:
	ldr r2, .L080F1970
	adds r1, r6, r2
	b .L080F1B50
	.byte 0x00, 0x00
.L080F1970: .4byte 0x0000097E
.L080F1974:
	mov r3, r8
	cmp r3, #8
	bne .L080F19C8
	adds r0, r7, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	str r0, [sp]
	adds r5, r0, #0
	cmp r5, #0xf8
	bne .L080F1998
	ldr r1, .L080F1994
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp]
	b .L080F19A2
	.byte 0x00, 0x00
.L080F1994: .4byte 0x00001194
.L080F1998:
	adds r0, r5, #0
	movs r1, #0xc
	mov r2, sp
	bl Item_GetAttribute
.L080F19A2:
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r1, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_080F3EF4
	ldr r0, .L080F19C4
	bl Battle_SkillDamage
	adds r1, r5, #0
	adds r0, r4, #0
	bl sub_080F3EF4
	b .L080F1AD2
	.byte 0x00, 0x00
.L080F19C4: .4byte 0x03000088 @ IWRAM+0x88
.L080F19C8:
	ldr r4, .L080F19EC
	adds r0, r4, #0
	bl Battle_SkillDamage
	adds r0, r7, #0
	adds r0, #0x5c
	ldrb r1, [r0]
	adds r2, r1, #0
	cmp r2, #0x5c
	beq .L080F19E0
	cmp r2, #0x61
	bne .L080F1A00
.L080F19E0:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq .L080F19F4
	ldr r2, .L080F19F0
	adds r1, r6, r2
	b .L080F1E3E
.L080F19EC: .4byte 0x03000088 @ IWRAM+0x88
.L080F19F0: .4byte 0x0000097E
.L080F19F4:
	ldr r3, .L080F19FC
	adds r1, r6, r3
	b .L080F1B40
	.byte 0x00, 0x00
.L080F19FC: .4byte 0x0000097E
.L080F1A00:
	adds r0, r1, #0
	subs r0, #0x66
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi .L080F1A76
	ldr r5, .L080F1A48
	adds r0, r6, r5
	movs r1, #7
	strh r1, [r0]
	ldr r0, [r4, #0xc]
	cmp r0, #1
	beq .L080F1A1C
	b .L080F20C6
.L080F1A1C:
	ldr r0, [r4, #4]
	bl sub_080EF0E4
	cmp r0, #0
	beq .L080F1A50
	ldr r0, .L080F1A4C
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
	b .L080F1FA0
	.byte 0x00, 0x00
.L080F1A48: .4byte 0x0000097E
.L080F1A4C: .4byte 0x00000171
.L080F1A50:
	ldr r4, [r4, #4]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	bl sub_080C08F8
	adds r0, r4, #0
	movs r1, #0
	bl sub_080F4054
	subs r0, r4, #4
	cmp r0, #0xb
	bhi .L080F1A70
	adds r0, r4, #0
	bl sub_080F4190
.L080F1A70:
	bl sub_080C366C
	b .L080F20C6
.L080F1A76:
	adds r0, r1, #0
	subs r0, #0x63
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi .L080F1AA0
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq .L080F1A94
	ldr r1, .L080F1A90
	movs r0, #1
	strh r0, [r1]
	b .L080F1E3A
.L080F1A90: .4byte 0x030000AE @ IWRAM+0xAE
.L080F1A94:
	ldr r2, .L080F1A9C
	adds r1, r6, r2
	b .L080F2040
	.byte 0x00, 0x00
.L080F1A9C: .4byte 0x0000097E
.L080F1AA0:
	adds r0, r1, #0
	subs r0, #0x54
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls .L080F1AB0
	cmp r2, #0x5e
	bne .L080F1AD2
.L080F1AB0:
	ldr r1, [r4, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080F1ABC
	b .L080F203C
.L080F1ABC:
	adds r0, r1, #0
	bl Battle_GetMessage
	ldr r1, [r4, #4]
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F203C
.L080F1AD2:
	ldr r2, .L080F1B2C
	ldr r1, [r2, #0x18]
	ldr r0, .L080F1B30
	cmp r1, r0
	bne .L080F1B38
	ldr r0, [r2, #8]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L080F1B0C
	ldr r5, [r2, #4]
	cmp r5, r1
	bne .L080F1AEE
	ldr r5, [r2]
.L080F1AEE:
	bl Battle_GetMessage
	adds r4, r0, #0
	bl sub_080F3E44
	adds r1, r0, #0
	lsls r1, r1, #0x10
	adds r1, r5, r1
	adds r0, r4, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F1B0C:
	ldr r0, .L080F1B2C
	ldr r1, [r0, #0xc]
	cmp r1, #1
	bne .L080F1B24
	ldr r0, [sp]
	subs r0, #0x9e
	cmp r0, #1
	bhi .L080F1B24
	movs r5, #0xec
	lsls r5, r5, #4
	adds r0, r6, r5
	strb r1, [r0]
.L080F1B24:
	ldr r0, .L080F1B34
	adds r1, r6, r0
	b .L080F1E74
	.byte 0x00, 0x00
.L080F1B2C: .4byte 0x03000088 @ IWRAM+0x88
.L080F1B30: .4byte 0x0000FFFF
.L080F1B34: .4byte 0x0000097C
.L080F1B38:
	cmp r1, #0
	bne .L080F1B4C
	ldr r2, .L080F1B48
	adds r1, r6, r2
.L080F1B40:
	movs r0, #8
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F1B48: .4byte 0x0000097E
.L080F1B4C:
	ldr r3, .L080F1B58
	adds r1, r6, r3
.L080F1B50:
	movs r0, #4
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F1B58: .4byte 0x0000097E
.L080F1B5C:
	ldr r7, .L080F1BC0
	ldr r5, [r7, #4]
	ldr r1, [sp]
	adds r0, r7, #0
	bl sub_080EEB94
	str r0, [sp, #4]
	ldr r0, .L080F1BC4
	mov r8, r0
	ldr r1, .L080F1BC8
	mov sb, r1
	strh r1, [r0]
	ldr r0, [r7, #8]
	movs r2, #1
	rsbs r2, r2, #0
	mov sl, r2
	cmp r0, sl
	beq .L080F1B98
	bl Battle_GetMessage
	adds r1, r5, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	movs r0, #0
	mov r3, r8
	strh r0, [r3]
.L080F1B98:
	bl sub_080EDA90
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, sb
	bne .L080F1C04
	ldr r0, [r7, #4]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r4, #0
	beq .L080F1BD0
	ldr r5, .L080F1BCC
	adds r1, r6, r5
	movs r0, #0xa
	b .L080F1C2E
.L080F1BC0: .4byte 0x03000088 @ IWRAM+0x88
.L080F1BC4: .4byte 0x030000AC @ IWRAM+0xAC
.L080F1BC8: .4byte 0x0000FFFF
.L080F1BCC: .4byte 0x0000097C
.L080F1BD0:
	ldr r0, [sp, #4]
	cmp r0, #0
	bne .L080F1BE4
	ldr r2, .L080F1BE0
	adds r1, r6, r2
	movs r0, #8
	b .L080F1C2E
	.byte 0x00, 0x00
.L080F1BE0: .4byte 0x0000097E
.L080F1BE4:
	ldr r1, .L080F1BFC
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r3, .L080F1C00
	adds r1, r6, r3
	movs r0, #7
	strh r0, [r1]
	mov r5, r8
	strh r4, [r5]
	b .L080F1C30
	.byte 0x00, 0x00
.L080F1BFC: .4byte gUnknown_08124316
.L080F1C00: .4byte 0x0000097E
.L080F1C04:
	cmp r4, #0
	bne .L080F1C14
	ldr r0, .L080F1C10
	adds r1, r6, r0
	movs r0, #9
	b .L080F1C2E
.L080F1C10: .4byte 0x0000097E
.L080F1C14:
	ldr r0, [r7, #8]
	cmp r0, sl
	beq .L080F1C28
	ldr r2, .L080F1C24
	adds r1, r6, r2
	movs r0, #0xa
	b .L080F1C2E
	.byte 0x00, 0x00
.L080F1C24: .4byte 0x0000097E
.L080F1C28:
	ldr r3, .L080F1C40
	adds r1, r6, r3
	movs r0, #4
.L080F1C2E:
	strh r0, [r1]
.L080F1C30:
	ldr r0, .L080F1C44
	ldrh r1, [r0]
.L080F1C34:
	ldr r0, .L080F1C48
	cmp r1, r0
	bne .L080F1C3C
	b .L080F20C6
.L080F1C3C:
	b .L080F1FA0
	.byte 0x00, 0x00
.L080F1C40: .4byte 0x0000097E
.L080F1C44: .4byte 0x030000AC @ IWRAM+0xAC
.L080F1C48: .4byte 0x0000FFFF
.L080F1C4C:
	ldr r4, .L080F1C68
	adds r0, r4, #0
	bl sub_080EED88
	cmp r0, #0
	bne .L080F1C84
	ldr r0, .L080F1C6C
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #1
	bne .L080F1C74
	ldr r0, .L080F1C70
	adds r1, r6, r0
	b .L080F20A4
.L080F1C68: .4byte 0x03000088 @ IWRAM+0x88
.L080F1C6C: .4byte 0x030000AE @ IWRAM+0xAE
.L080F1C70: .4byte 0x0000097E
.L080F1C74:
	ldr r2, .L080F1C80
	adds r1, r6, r2
	movs r0, #5
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F1C80: .4byte 0x0000097E
.L080F1C84:
	ldr r1, [r4, #8]
	movs r0, #0xb7
	lsls r0, r0, #1
	cmp r1, r0
	bne .L080F1CB4
	bl sub_080F20E0
	ldr r3, .L080F1CAC
	adds r1, r6, r3
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #9
	bne .L080F1CA0
	b .L080F1FA0
.L080F1CA0:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	bne .L080F1CB0
	movs r0, #8
	b .L080F1F9E
	.byte 0x00, 0x00
.L080F1CAC: .4byte 0x0000097E
.L080F1CB0:
	movs r0, #0xa
	b .L080F1F9E
.L080F1CB4:
	ldr r0, .L080F1CB8
	b .L080F2094
.L080F1CB8: .4byte 0x0000097E
.L080F1CBC:
	ldr r4, .L080F1CF0
	ldr r0, [r4]
	bl sub_080EFE60
	adds r1, r0, #0
	ldr r0, [r4, #4]
	bl sub_080F3F90
	adds r5, r0, #0
	ldr r0, [r4, #4]
	cmp r0, #0xf
	bgt .L080F1D24
	bl sub_080F3F44
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	beq .L080F1CF4
	mov r1, r8
	cmp r1, #0xa
	bne .L080F1CF4
	movs r2, #0x12
	ldrsh r0, [r7, r2]
	b .L080F1D1E
	.byte 0x00, 0x00
.L080F1CF0: .4byte 0x03000088 @ IWRAM+0x88
.L080F1CF4:
	ldr r0, .L080F1D54
	ldr r0, [r0, #4]
	cmp r0, #0xf
	bgt .L080F1D24
	bl sub_080F3F44
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	beq .L080F1D24
	mov r0, r8
	ldr r1, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080EED64
	cmp r0, #1
	bne .L080F1D24
	movs r3, #0x12
	ldrsh r0, [r7, r3]
.L080F1D1E:
	cmp r0, #0xb1
	ble .L080F1D24
	movs r5, #0xd
.L080F1D24:
	ldr r4, .L080F1D54
	ldr r0, [r4, #0x18]
	adds r1, r5, #0
	bl Battle_ApplyAffinity
	str r0, [r4, #0x18]
	mov r2, sb
	movs r3, #0x18
	ldrsh r1, [r2, r3]
	cmp r1, r0
	bge .L080F1D3C
	str r1, [r4, #0x18]
.L080F1D3C:
	ldr r1, .L080F1D58
	ldr r2, .L080F1D5C
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, r1, #0
	cmp r5, #0xf
	bhi .L080F1DFE
	lsls r0, r5, #2
	ldr r1, .L080F1D60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F1D54: .4byte 0x03000088 @ IWRAM+0x88
.L080F1D58: .4byte 0x030000AC @ IWRAM+0xAC
.L080F1D5C: .4byte 0x0000FFFF
.L080F1D60: .4byte gUnknown_080F1D64
	.global gUnknown_080F1D64
gUnknown_080F1D64:
.L080F1D64: @ jump table
	.4byte .L080F1DD4
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DFE
	.4byte .L080F1DE4
	.4byte .L080F1DE4
	.4byte .L080F1DA4
	.4byte .L080F1DA4
.L080F1DA4:
	ldr r5, .L080F1DDC
	ldr r0, [r5, #4]
	bl sub_080F401C
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r5, #4]
	bl sub_080F4038
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r1, [r5, #0x18]
	adds r1, r4, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble .L080F1DCC
	subs r0, r0, r4
	str r0, [r5, #0x18]
.L080F1DCC:
	ldr r0, [r5, #4]
	ldr r1, [r5, #0x18]
	bl sub_080C0AD4
.L080F1DD4:
	ldr r3, .L080F1DE0
	adds r1, r6, r3
	b .L080F2096
	.byte 0x00, 0x00
.L080F1DDC: .4byte 0x03000088 @ IWRAM+0x88
.L080F1DE0: .4byte 0x0000097E
.L080F1DE4:
	bl sub_080F20E0
	ldr r5, .L080F1E10
	adds r0, r6, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne .L080F1DF6
	b .L080F1FA0
.L080F1DF6:
	ldr r1, .L080F1E14
	movs r0, #0
	strh r0, [r1]
	adds r2, r1, #0
.L080F1DFE:
	ldr r0, .L080F1E18
	ldr r0, [r0, #0x18]
	cmp r0, #0
	bne .L080F1E1C
	ldr r3, .L080F1E10
	adds r1, r6, r3
	movs r0, #8
	b .L080F1E22
	.byte 0x00, 0x00
.L080F1E10: .4byte 0x0000097E
.L080F1E14: .4byte 0x030000AC @ IWRAM+0xAC
.L080F1E18: .4byte 0x03000088 @ IWRAM+0x88
.L080F1E1C:
	ldr r5, .L080F1E28
	adds r1, r6, r5
	movs r0, #0xa
.L080F1E22:
	strh r0, [r1]
	ldrh r1, [r2]
	b .L080F1C34
.L080F1E28: .4byte 0x0000097E
.L080F1E2C:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080F1E3A
	b .L080F20C6
.L080F1E3A:
	ldr r0, .L080F1E44
	adds r1, r6, r0
.L080F1E3E:
	movs r0, #0xc
	strh r0, [r1]
	b .L080F20C6
.L080F1E44: .4byte 0x0000097E
.L080F1E48:
	ldr r1, .L080F1E5C
	adds r4, r6, r1
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080F1E84
	cmp r0, #1
	bne .L080F1E64
	ldr r1, .L080F1E60
	b .L080F1E66
	.byte 0x00, 0x00
.L080F1E5C: .4byte 0x000011B0
.L080F1E60: .4byte gUnknown_081242EC
.L080F1E64:
	ldr r1, .L080F1E7C
.L080F1E66:
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	movs r0, #0
	strh r0, [r4]
	ldr r2, .L080F1E80
	adds r1, r6, r2
.L080F1E74:
	movs r0, #0xb
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F1E7C: .4byte gUnknown_081242FC
.L080F1E80: .4byte 0x0000097E
.L080F1E84:
	ldr r5, .L080F1EA8
	ldr r0, [r5, #4]
	bl sub_080F401C
	cmp r0, #0
	ble .L080F1EA0
	ldr r0, [r5, #4]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L080F1EB0
.L080F1EA0:
	ldr r3, .L080F1EAC
	adds r1, r6, r3
	b .L080F20A4
	.byte 0x00, 0x00
.L080F1EA8: .4byte 0x03000088 @ IWRAM+0x88
.L080F1EAC: .4byte 0x0000097C
.L080F1EB0:
	bl sub_080F22B4
	bl sub_080EDA90
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L080F1F98
	ldr r0, .L080F1EF0
	cmp r4, r0
	beq .L080F1F98
	bl sub_080EDAD0
	cmp r0, #0
	beq .L080F1F14
	ldr r0, .L080F1EF4
	ands r0, r4
	cmp r0, #0
	beq .L080F1F14
	ldr r1, [r5, #4]
	cmp r1, #0xf
	ble .L080F1F14
	ldr r0, .L080F1EF8
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #1
	bne .L080F1F00
	ldr r0, .L080F1EFC
	adds r1, r6, r0
	movs r0, #9
	b .L080F1F9E
	.byte 0x00, 0x00
.L080F1EF0: .4byte 0x0000FFFF
.L080F1EF4: .4byte 0x00003204
.L080F1EF8: .4byte 0x030000AE @ IWRAM+0xAE
.L080F1EFC: .4byte 0x0000097E
.L080F1F00:
	adds r0, r1, #0
	bl sub_080F401C
	cmp r0, #0
	bgt .L080F1F98
	ldr r2, .L080F1F10
	adds r1, r6, r2
	b .L080F1F9C
.L080F1F10: .4byte 0x0000097E
.L080F1F14:
	ldr r5, .L080F1F34
	ldr r0, [r5, #4]
	adds r1, r4, #0
	bl sub_080C08E8
	ldr r0, [r5, #4]
	bl sub_080F401C
	cmp r0, #0
	bgt .L080F1F3C
	ldr r5, .L080F1F38
	adds r1, r6, r5
	movs r0, #7
	strh r0, [r1]
	b .L080F1F76
	.byte 0x00, 0x00
.L080F1F34: .4byte 0x03000088 @ IWRAM+0x88
.L080F1F38: .4byte 0x0000097E
.L080F1F3C:
	ldr r0, .L080F1F68
	adds r1, r6, r0
	movs r0, #6
	strh r0, [r1]
	ldr r0, [r5, #4]
	cmp r0, #0xf
	bgt .L080F1F6C
	bl sub_080BFFC4
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	adds r0, r5, #0
	bl sub_080C86B4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x12
	bgt .L080F1F76
	adds r0, r5, #0
	bl sub_080C8490
	b .L080F1F76
.L080F1F68: .4byte 0x0000097E
.L080F1F6C:
	movs r2, #0xec
	lsls r2, r2, #4
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
.L080F1F76:
	movs r0, #0x80
	lsls r0, r0, #6
	cmp r4, r0
	bne .L080F1FA0
	ldr r0, .L080F1F94
	ldr r1, [r0, #4]
	subs r0, r1, #4
	cmp r0, #0xb
	bhi .L080F1FA0
	adds r0, r1, #0
	bl sub_080F4190
	bl sub_080C366C
	b .L080F1FA0
.L080F1F94: .4byte 0x03000088 @ IWRAM+0x88
.L080F1F98:
	ldr r3, .L080F1FAC
	adds r1, r6, r3
.L080F1F9C:
	movs r0, #7
.L080F1F9E:
	strh r0, [r1]
.L080F1FA0:
	movs r0, #4
	movs r1, #0xd
	bl sub_080F0344
	b .L080F20C6
	.byte 0x00, 0x00
.L080F1FAC: .4byte 0x0000097E
.L080F1FB0:
	ldr r4, .L080F1FC8
	ldr r0, [r4, #4]
	bl sub_080F3110
	cmp r0, #1
	bne .L080F1FD0
	ldr r1, .L080F1FCC
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F1FEC
	.byte 0x00, 0x00
.L080F1FC8: .4byte 0x03000088 @ IWRAM+0x88
.L080F1FCC: .4byte gUnknown_08124218
.L080F1FD0:
	ldr r0, [r4, #4]
	ldr r5, .L080F1FF4
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r1, .L080F1FF8
	bl Battle_BuildActorStatusText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F1FEC:
	ldr r0, .L080F1FFC
	adds r1, r6, r0
	b .L080F2040
	.byte 0x00, 0x00
.L080F1FF4: .4byte 0xFFFF8000
.L080F1FF8: .4byte gUnknown_08124234
.L080F1FFC: .4byte 0x0000097E
.L080F2000:
	ldr r4, .L080F202C
	ldr r0, [r4, #4]
	bl sub_080F3110
	movs r1, #0xaa
	lsls r1, r1, #1
	cmp r0, #1
	bne .L080F2012
	subs r1, #1
.L080F2012:
	adds r0, r1, #0
	bl Battle_GetMessage
	ldr r1, [r4, #4]
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r2, .L080F2030
	adds r1, r6, r2
	b .L080F2040
.L080F202C: .4byte 0x03000088 @ IWRAM+0x88
.L080F2030: .4byte 0x0000097E
.L080F2034:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	bl sub_080F2AC8
.L080F203C:
	ldr r3, .L080F2048
	adds r1, r6, r3
.L080F2040:
	movs r0, #7
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F2048: .4byte 0x0000097E
.L080F204C:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F20C6
	ldr r4, .L080F2070
	ldr r0, [r4, #4]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	cmp r1, #0
	beq .L080F2078
	ldr r5, .L080F2074
	adds r1, r6, r5
	b .L080F20A4
.L080F2070: .4byte 0x03000088 @ IWRAM+0x88
.L080F2074: .4byte 0x0000097C
.L080F2078:
	ldr r0, [r4, #4]
	bl sub_080F401C
	cmp r0, #0
	ble .L080F2092
	ldr r0, [r4, #4]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L080F20A0
.L080F2092:
	ldr r0, .L080F209C
.L080F2094:
	adds r1, r6, r0
.L080F2096:
	movs r0, #9
	strh r0, [r1]
	b .L080F20C6
.L080F209C: .4byte 0x0000097C
.L080F20A0:
	ldr r2, .L080F20AC
	adds r1, r6, r2
.L080F20A4:
	movs r0, #0xa
	strh r0, [r1]
	b .L080F20C6
	.byte 0x00, 0x00
.L080F20AC: .4byte 0x0000097C
.L080F20B0:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080F20C6
	ldr r0, .L080F20D8
	ldrh r1, [r0]
	ldr r3, .L080F20DC
	adds r0, r6, r3
	strh r1, [r0]
.L080F20C6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F20D8: .4byte 0x030000AC @ IWRAM+0xAC
.L080F20DC: .4byte 0x0000097E

	thumb_func_start sub_080F20E0
sub_080F20E0: @ 0x080F20E0
.L080F20E0:
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r4, .L080F2108
	ldr r0, [r4, #4]
	bl sub_080F3110
	cmp r0, #0
	bne .L080F2110
	ldr r0, [r4, #4]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r0, r1
	ldr r1, .L080F210C
	bl Battle_BuildNamePrependText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F2118
.L080F2108: .4byte 0x03000088 @ IWRAM+0x88
.L080F210C: .4byte gUnknown_081241F0
.L080F2110:
	ldr r1, .L080F2188
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F2118:
	ldr r5, .L080F218C
	ldr r0, [r5]
	str r0, [r5, #4]
	bl sub_080EDA90
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r6, r4, #0
	cmp r4, #0
	beq .L080F215E
	ldr r0, .L080F2190
	cmp r4, r0
	beq .L080F215E
	bl sub_080EDA7C
	ldr r0, [r5, #4]
	adds r1, r4, #0
	bl sub_080F3214
	cmp r0, #0
	beq .L080F215E
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq .L080F2158
	ldrh r0, [r5, #4]
	bl sub_080C0148
	movs r2, #0x1e
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq .L080F215E
.L080F2158:
	adds r0, r6, #0
	bl sub_080EDA7C
.L080F215E:
	ldr r6, .L080F2194
	ldr r5, .L080F218C
	ldr r0, [r5]
	bl sub_080C35E4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	ldr r2, .L080F2198
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080F217A
	cmp r1, #0xa
	bne .L080F219C
.L080F217A:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	bl Battle_PhysicalDamage
	str r0, [r5, #0x18]
	b .L080F21E0
	.byte 0x00, 0x00
.L080F2188: .4byte gUnknown_08124200
.L080F218C: .4byte 0x03000088 @ IWRAM+0x88
.L080F2190: .4byte 0x0000FFFF
.L080F2194: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2198: .4byte 0xFFFC0000
.L080F219C:
	cmp r1, #8
	bne .L080F21D2
	ldr r0, [r5]
	bl sub_080F3F14
	adds r4, r0, #0
	str r4, [sp]
	movs r1, #0xc
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [r5]
	ldr r1, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080F3EF4
	adds r0, r5, #0
	bl Battle_SkillDamage
	ldr r0, [r5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
	bl sub_080F3EF4
	b .L080F21E0
.L080F21D2:
	cmp r1, #7
	beq .L080F21DA
	cmp r1, #0xb
	bne .L080F21E0
.L080F21DA:
	adds r0, r5, #0
	bl Battle_SkillDamage
.L080F21E0:
	ldr r4, .L080F2224
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq .L080F22A4
	ldr r0, [r4]
	bl sub_080EFE60
	adds r1, r0, #0
	ldr r0, [r4, #4]
	bl sub_080F3F90
	adds r5, r0, #0
	ldr r0, [r4, #0x18]
	adds r1, r5, #0
	bl Battle_ApplyAffinity
	str r0, [r4, #0x18]
	ldr r0, [r4, #4]
	bl sub_080F401C
	ldr r1, [r4, #0x18]
	cmp r0, r1
	bge .L080F2216
	ldr r0, [r4, #4]
	bl sub_080F401C
	str r0, [r4, #0x18]
.L080F2216:
	cmp r5, #0xf
	bhi .L080F22A4
	lsls r0, r5, #2
	ldr r1, .L080F2228
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080F2224: .4byte 0x03000088 @ IWRAM+0x88
.L080F2228: .4byte gUnknown_080F222C
	.global gUnknown_080F222C
gUnknown_080F222C:
.L080F222C: @ jump table
	.4byte .L080F229C
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F22A4
	.4byte .L080F226C
	.4byte .L080F226C
.L080F226C:
	ldr r5, .L080F22AC
	ldr r0, [r5, #4]
	bl sub_080F401C
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r5, #4]
	bl sub_080F4038
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r1, [r5, #0x18]
	adds r1, r4, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble .L080F2294
	subs r0, r0, r4
	str r0, [r5, #0x18]
.L080F2294:
	ldr r0, [r5, #4]
	ldr r1, [r5, #0x18]
	bl sub_080C0AD4
.L080F229C:
	ldr r0, .L080F22B0
	adds r1, r6, r0
	movs r0, #9
	strh r0, [r1]
.L080F22A4:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080F22AC: .4byte 0x03000088 @ IWRAM+0x88
.L080F22B0: .4byte 0x0000097E

	thumb_func_start sub_080F22B4
sub_080F22B4: @ 0x080F22B4
.L080F22B4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, .L080F231C
	mov sl, r0
	ldr r4, .L080F2320
	ldrh r7, [r4, #4]
	ldr r0, .L080F2324
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L080F2372
	bl sub_080EDA90
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r8, r0
	bne .L080F236C
	bl sub_080EDAD0
	cmp r0, #0
	beq .L080F2358
	lsls r0, r7, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0xf
	ble .L080F2358
	ldr r0, [r4]
	bl sub_080EFE60
	adds r5, r0, #0
	ldr r0, [r4, #4]
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080ED494
	cmp r0, #0x3f
	bne .L080F2328
	cmp r5, #7
	bne .L080F2328
	adds r0, r6, #0
	bl sub_080F401C
	str r0, [r4, #0x18]
	ldr r0, [r4, #4]
	b .L080F2342
.L080F231C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F2320: .4byte 0x03000088 @ IWRAM+0x88
.L080F2324: .4byte 0x030000AE @ IWRAM+0xAE
.L080F2328:
	cmp r0, #0x3e
	beq .L080F232E
	b .L080F24DA
.L080F232E:
	cmp r5, #8
	beq .L080F2334
	b .L080F24DA
.L080F2334:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	bl sub_080F401C
	ldr r1, .L080F2354
	str r0, [r1, #0x18]
	ldr r0, [r1, #4]
.L080F2342:
	movs r1, #0x80
	lsls r1, r1, #8
	bl sub_080C08E8
	movs r0, #0
	bl sub_080EDA7C
	b .L080F2372
	.byte 0x00, 0x00
.L080F2354: .4byte 0x03000088 @ IWRAM+0x88
.L080F2358:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	bl sub_080F401C
	ldr r1, .L080F2368
	str r0, [r1, #0x18]
	b .L080F2372
	.byte 0x00, 0x00
.L080F2368: .4byte 0x03000088 @ IWRAM+0x88
.L080F236C:
	movs r0, #0
	str r0, [r4, #0x18]
	b .L080F24DA
.L080F2372:
	lsls r4, r7, #0x10
	asrs r5, r4, #0x10
	adds r0, r5, #0
	bl sub_080F3110
	mov sb, r4
	cmp r0, #1
	bne .L080F23BC
	bl Battle_IsTwoSided
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	bl sub_080ED974
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, #1
	bne .L080F23A6
	cmp r0, #1
	bne .L080F23A6
	movs r0, #1
	bl sub_080E8AFC
	b .L080F23AC
.L080F23A6:
	movs r0, #0
	bl sub_080E8AFC
.L080F23AC:
	ldr r1, .L080F23B8
	add r1, sl
	movs r0, #0x96
	lsls r0, r0, #1
	b .L080F23FC
	.byte 0x00, 0x00
.L080F23B8: .4byte 0x00000ECA
.L080F23BC:
	adds r0, r5, #0
	bl sub_080BFFC4
	movs r1, #0
	ldr r0, .L080F24A4
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r2, r0, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, r5
	beq .L080F23EC
	adds r4, r5, #0
.L080F23D6:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #5
	bhi .L080F23EC
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r4
	bne .L080F23D6
.L080F23EC:
	cmp r1, #6
	beq .L080F23F6
	adds r0, r1, #0
	bl sub_080C86F4
.L080F23F6:
	ldr r1, .L080F24A8
	add r1, sl
	ldr r0, .L080F24AC
.L080F23FC:
	strh r0, [r1]
	ldr r0, .L080F24A8
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_080ECF70
	ldr r6, .L080F24B0
	ldr r3, [r6, #0x18]
	mov r8, r3
	movs r7, #0
	mov r0, sb
	asrs r5, r0, #0x10
	adds r0, r5, #0
	bl sub_080F401C
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080F4038
	cmp r4, r0
	ble .L080F242A
	movs r7, #1
.L080F242A:
	ldr r1, [r6, #0x18]
	rsbs r1, r1, #0
	adds r0, r5, #0
	bl Combatant_AddHp
	adds r0, r5, #0
	bl sub_080F401C
	cmp r0, #0
	bge .L080F2452
	adds r0, r5, #0
	bl sub_080F401C
	ldr r1, [r6, #0x18]
	adds r1, r1, r0
	str r1, [r6, #0x18]
	adds r0, r5, #0
	movs r1, #0
	bl sub_080F4054
.L080F2452:
	cmp r7, #0
	bne .L080F2476
	adds r0, r5, #0
	bl sub_080F401C
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080F4038
	cmp r4, r0
	ble .L080F2476
	adds r0, r5, #0
	bl sub_080F4038
	adds r1, r0, #0
	adds r0, r5, #0
	bl sub_080F4054
.L080F2476:
	ldr r4, .L080F24B0
	ldr r0, [r4, #4]
	bl sub_080F3110
	cmp r0, #1
	bne .L080F24BC
	ldr r0, [r4, #4]
	ldr r1, .L080F24B4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r2, .L080F24B8
	mov r1, r8
	bl Battle_BuildDamageDealtText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	b .L080F24DA
	.byte 0x00, 0x00
.L080F24A4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F24A8: .4byte 0x00000ECA
.L080F24AC: .4byte 0x0000012B
.L080F24B0: .4byte 0x03000088 @ IWRAM+0x88
.L080F24B4: .4byte 0xFFFF8000
.L080F24B8: .4byte gUnknown_08123BCC
.L080F24BC:
	ldr r0, [r4, #4]
	ldr r3, .L080F24E8
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r2, .L080F24EC
	mov r1, r8
	bl Battle_BuildDamageDealtText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
.L080F24DA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F24E8: .4byte 0xFFFF8000
.L080F24EC: .4byte gUnknown_0812310C
