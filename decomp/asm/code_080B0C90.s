	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080B0C90
sub_080B0C90: @ 0x080B0C90
.L080B0C90:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r1, .L080B0CD0
	ldr r0, .L080B0CD4
	ldrh r0, [r0]
	ldrh r2, [r1, #0x38]
	strh r0, [r1, #0x38]
	ldr r0, .L080B0CD8
	ldrh r0, [r0]
	ldrh r2, [r1, #0x3a]
	strh r0, [r1, #0x3a]
	ldr r0, .L080B0CDC
	ldrh r0, [r0]
	ldrh r2, [r1, #0x3c]
	strh r0, [r1, #0x3c]
	ldr r2, .L080B0CE0
	ldr r0, [r2]
	cmp r0, #0
	beq .L080B0CEC
	ldr r0, .L080B0CE4
	ldrh r0, [r0]
	ldr r1, .L080B0CE8
	ldrh r1, [r1]
	bl Map_LoadGraphicsStep
	bl .L080B1A0A
	.byte 0x00, 0x00
.L080B0CD0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0CD4: .4byte 0x030031D0 @ IWRAM+0x31D0
.L080B0CD8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080B0CDC: .4byte 0x03003964 @ IWRAM+0x3964
.L080B0CE0: .4byte 0x03003FF8 @ IWRAM+0x3FF8
.L080B0CE4: .4byte 0x03004614 @ IWRAM+0x4614
.L080B0CE8: .4byte 0x03004514 @ IWRAM+0x4514
.L080B0CEC:
	ldr r0, .L080B0D20
	ldr r1, [r0]
	cmp r1, #0
	blt .L080B0D38
	ldr r0, .L080B0D24
	ldrh r0, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl DungeonMap_GetFloor
	ldr r1, .L080B0D28
	ldr r2, .L080B0D2C
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0xe8
	muls r1, r2, r1
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L080B0D30
	bl _call_via_r0
	b .L080B0D38
.L080B0D20: .4byte 0x03004514 @ IWRAM+0x4514
.L080B0D24: .4byte 0x03004614 @ IWRAM+0x4614
.L080B0D28: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B0D2C: .4byte 0x00000A38
.L080B0D30:
	movs r0, #0x84
	lsls r0, r0, #1
	bl Flag_Clear
.L080B0D38:
	movs r0, #0x81
	lsls r0, r0, #1
	bl Flag_Test
	adds r4, r0, #0
	cmp r4, #0
	beq .L080B0DBC
	ldr r3, .L080B0D84
	adds r1, r3, #0
	adds r1, #0x48
	ldrh r0, [r1]
	cmp r0, #0
	bne .L080B0D56
	movs r0, #1
	strh r0, [r1]
.L080B0D56:
	ldrh r4, [r1]
	cmp r4, #1
	bne .L080B0DAC
	ldr r0, .L080B0D88
	ldr r2, [r0]
	movs r0, #0xf
	ands r2, r0
	cmp r2, #0
	bne .L080B0DA2
	adds r3, #0x4a
	ldrh r0, [r3]
	cmp r0, #0
	bne .L080B0D90
	ldr r1, .L080B0D8C
	ldrb r0, [r1]
	adds r0, #0x10
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls .L080B0DA2
	strh r4, [r3]
	b .L080B0DA2
.L080B0D84: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0D88: .4byte 0x030031BC @ IWRAM+0x31BC
.L080B0D8C: .4byte 0x0300003C @ IWRAM+0x3C
.L080B0D90:
	ldr r1, .L080B0DA8
	ldrb r0, [r1]
	subs r0, #0x10
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne .L080B0DA2
	strh r2, [r3]
.L080B0DA2:
	bl sub_080B0AE0
	b .L080B0DCE
.L080B0DA8: .4byte 0x0300003C @ IWRAM+0x3C
.L080B0DAC:
	ldr r0, .L080B0DB8
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	b .L080B0DCE
	.byte 0x00, 0x00
.L080B0DB8: .4byte sub_080B0ABC
.L080B0DBC:
	ldr r0, .L080B0E1C
	adds r5, r0, #0
	adds r5, #0x48
	ldrh r0, [r5]
	cmp r0, #0
	beq .L080B0DCE
	bl sub_080B0B54
	strh r4, [r5]
.L080B0DCE:
	movs r0, #0x83
	lsls r0, r0, #1
	bl Flag_Test
	adds r1, r0, #0
	cmp r1, #0
	beq .L080B0E40
	ldr r3, .L080B0E1C
	adds r1, r3, #0
	adds r1, #0x4c
	ldrh r0, [r1]
	cmp r0, #0
	bne .L080B0DEC
	movs r0, #1
	strh r0, [r1]
.L080B0DEC:
	ldrh r4, [r1]
	cmp r4, #1
	bne .L080B0E46
	ldr r0, .L080B0E20
	ldr r2, [r0]
	movs r0, #0xf
	ands r2, r0
	cmp r2, #0
	bne .L080B0E46
	adds r3, #0x4e
	ldrh r0, [r3]
	cmp r0, #0
	bne .L080B0E28
	ldr r1, .L080B0E24
	ldrb r0, [r1]
	adds r0, #0x10
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls .L080B0E46
	strh r4, [r3]
	b .L080B0E46
	.byte 0x00, 0x00
.L080B0E1C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0E20: .4byte 0x030031BC @ IWRAM+0x31BC
.L080B0E24: .4byte 0x0300003D @ IWRAM+0x3D
.L080B0E28:
	ldr r1, .L080B0E3C
	ldrb r0, [r1]
	subs r0, #0x10
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne .L080B0E46
	strh r2, [r3]
	b .L080B0E46
.L080B0E3C: .4byte 0x0300003D @ IWRAM+0x3D
.L080B0E40:
	ldr r0, .L080B0E70
	adds r0, #0x4c
	strh r1, [r0]
.L080B0E46:
	movs r0, #0x84
	lsls r0, r0, #1
	bl Flag_Test
	adds r4, r0, #0
	cmp r4, #0
	beq .L080B0E7A
	ldr r0, .L080B0E70
	adds r1, r0, #0
	adds r1, #0x50
	ldrh r0, [r1]
	cmp r0, #0
	bne .L080B0E64
	movs r0, #1
	strh r0, [r1]
.L080B0E64:
	ldrh r0, [r1]
	cmp r0, #1
	bne .L080B0E74
	bl sub_080B0C38
	b .L080B0E8C
.L080B0E70: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0E74:
	bl sub_080B0C7C
	b .L080B0E8C
.L080B0E7A:
	ldr r0, .L080B0EA8
	adds r5, r0, #0
	adds r5, #0x50
	ldrh r0, [r5]
	cmp r0, #0
	beq .L080B0E8C
	bl sub_080B0C7C
	strh r4, [r5]
.L080B0E8C:
	ldr r1, .L080B0EA8
	ldrh r0, [r1]
	subs r0, #1
	adds r5, r1, #0
	cmp r0, #0x24
	bls .L080B0E9C
	bl .L080B1A06
.L080B0E9C:
	lsls r0, r0, #2
	ldr r1, .L080B0EAC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080B0EA8: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0EAC: .4byte gUnknown_080B0EB0
	.global gUnknown_080B0EB0
gUnknown_080B0EB0:
.L080B0EB0: @ jump table
	.4byte .L080B0F44
	.4byte .L080B0F94
	.4byte .L080B1A06
	.4byte .L080B1078
	.4byte .L080B1082
	.4byte .L080B1124
	.4byte .L080B1242
	.4byte .L080B1254
	.4byte .L080B1A06
	.4byte .L080B1A06
	.4byte .L080B1354
	.4byte .L080B1420
	.4byte .L080B1426
	.4byte .L080B14EC
	.4byte .L080B1644
	.4byte .L080B1680
	.4byte .L080B1686
	.4byte .L080B16E0
	.4byte .L080B1712
	.4byte .L080B1798
	.4byte .L080B1A06
	.4byte .L080B17C0
	.4byte .L080B1A06
	.4byte .L080B18D0
	.4byte .L080B1A06
	.4byte .L080B1A06
	.4byte .L080B1930
	.4byte .L080B196C
	.4byte .L080B1984
	.4byte .L080B1984
	.4byte .L080B19D0
	.4byte .L080B1A06
	.4byte .L080B1426
	.4byte .L080B14EC
	.4byte .L080B1A06
	.4byte .L080B1A06
	.4byte .L080B1910
.L080B0F44:
	ldrh r0, [r5, #0x34]
	cmp r0, #1
	bne .L080B0F8A
	ldrh r0, [r5, #0x36]
	adds r1, r0, #0
	cmp r1, #0
	beq .L080B0F7C
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, .L080B0F78
	lsls r2, r0, #1
	ldrh r1, [r5, #2]
	lsls r1, r1, #3
	adds r2, r2, r1
	adds r2, r2, r3
	ldrh r1, [r2]
	movs r2, #0
	strh r2, [r5, #0x36]
	bl sub_080B2064
	movs r0, #6
	bl Field_SetState
	bl .L080B1A0A
.L080B0F78: .4byte gUnknown_08163258
.L080B0F7C:
	ldrh r0, [r5, #0x3a]
	strh r1, [r5, #0x3a]
	ldrh r0, [r5, #0x38]
	movs r0, #0x40
	strh r0, [r5, #0x38]
	ldrh r0, [r5, #0x3c]
	strh r1, [r5, #0x3c]
.L080B0F8A:
	ldrh r0, [r5, #0x38]
	bl Field_HandleInput
	bl .L080B1A06
.L080B0F94:
	ldrh r2, [r5, #0x1e]
	subs r0, r2, #1
	strh r0, [r5, #0x1e]
	ldrh r1, [r5, #0xa]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r1, r1, #1
	cmp r0, r1
	bne .L080B0FD8
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	beq .L080B0FAE
	b .L080B10C4
.L080B0FAE:
	ldr r0, .L080B0FD0
	bl sub_080AE494
	movs r0, #0
	bl View_IsSideOpen
	cmp r0, #1
	beq .L080B0FC2
	bl .L080B1A06
.L080B0FC2:
	ldr r1, .L080B0FD4
	movs r0, #0
	bl sub_080B09C4
	bl .L080B1A06
	.byte 0x00, 0x00
.L080B0FD0: .4byte sub_080B018C
.L080B0FD4: .4byte 0x0000FFFF
.L080B0FD8:
	ldrh r2, [r5, #0x1e]
	subs r0, r1, #1
	cmp r2, r0
	bne .L080B0FFA
	movs r0, #0
	bl View_IsSideOpen
	cmp r0, #1
	bne .L080B0FF2
	ldrh r0, [r5, #2]
	bl Field_Step
	b .L080B16AC
.L080B0FF2:
	movs r0, #0x69
	bl Sound_Play
	b .L080B16AC
.L080B0FFA:
	adds r1, r2, #0
	cmp r1, #0
	bne .L080B100E
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	beq .L080B10B4
	adds r0, r2, #1
	strh r0, [r5, #0x1e]
	bl .L080B1A06
.L080B100E:
	ldr r0, .L080B1048
	cmp r1, r0
	beq .L080B1018
	bl .L080B1A06
.L080B1018:
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080B1028
	bl .L080B19F8
.L080B1028:
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl sub_080AF8D0
	cmp r0, #0
	bne .L080B1066
	adds r0, r5, #0
	adds r0, #0x46
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B104C
	movs r0, #1
	bl Field_SetState
	b .L080B1052
.L080B1048: .4byte 0x0000FFFF
.L080B104C:
	movs r0, #1
	bl sub_080B03BC
.L080B1052:
	ldr r0, .L080B106C
	ldrh r0, [r0]
	ldr r1, .L080B1070
	ldrh r1, [r1]
	bl sub_080AD608
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Music_Play
.L080B1066:
	ldr r0, .L080B1074
	adds r0, #0x46
	b .L080B1116
.L080B106C: .4byte 0x03004614 @ IWRAM+0x4614
.L080B1070: .4byte 0x03004514 @ IWRAM+0x4514
.L080B1074: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1078:
	movs r0, #1
	bl sub_080B0A08
	bl .L080B1A06
.L080B1082:
	ldrh r2, [r5, #0x1e]
	subs r0, r2, #1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #6
	bne .L080B10A4
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	bne .L080B10C4
	movs r1, #8
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq .L080B10A2
	bl .L080B1A06
.L080B10A2:
	b .L080B169A
.L080B10A4:
	cmp r1, #5
	bne .L080B10AA
	b .L080B16AC
.L080B10AA:
	cmp r1, #0
	bne .L080B10CA
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	bne .L080B10C4
.L080B10B4:
	ldr r0, .L080B10C0
	bl sub_080AE494
	bl .L080B1A06
	.byte 0x00, 0x00
.L080B10C0: .4byte sub_080B0158
.L080B10C4:
	strh r2, [r5, #0x1e]
	bl .L080B1A06
.L080B10CA:
	ldr r0, .L080B1108
	cmp r1, r0
	beq .L080B10D4
	bl .L080B1A06
.L080B10D4:
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080B10E4
	bl .L080B19F8
.L080B10E4:
	movs r0, #1
	movs r1, #2
	movs r2, #1
	bl sub_080AF8D0
	cmp r0, #0
	beq .L080B10F6
	bl .L080B1A06
.L080B10F6:
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B110C
	movs r0, #1
	bl Field_SetState
	b .L080B1112
.L080B1108: .4byte 0x0000FFFF
.L080B110C:
	movs r0, #1
	bl sub_080B03BC
.L080B1112:
	ldr r0, .L080B1120
	adds r0, #0x44
.L080B1116:
	movs r1, #0
	strh r1, [r0]
	bl .L080B1A06
	.byte 0x00, 0x00
.L080B1120: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1124:
	bl sub_080B2090
	adds r6, r0, #0
	cmp r6, #1
	beq .L080B1130
	b .L080B1230
.L080B1130:
	movs r0, #0
	movs r1, #0
	bl FieldMap_CellRecordsRel
	adds r7, r0, #0
	movs r1, #0x1d
	bl FieldMap_FindRecord
	adds r5, r0, #0
	ldr r2, .L080B1180
	mov r8, r2
	ldrh r0, [r2, #0x12]
	ldrh r1, [r2, #0x14]
	ldrh r2, [r2, #2]
	add r3, sp, #4
	bl FieldEvent_FindAt
	adds r4, r0, #0
	movs r3, #0
	mov sb, r3
	mov sl, r3
	cmp r5, #0
	beq .L080B1184
	mov r0, r8
	ldrh r1, [r0, #2]
	lsls r1, r1, #2
	adds r0, r5, #4
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	adds r0, r7, #0
	movs r1, #0x1a
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B11F4
	ldrh r0, [r0, #2]
	bl sub_080B011C
	b .L080B11F4
.L080B1180: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1184:
	cmp r4, #0
	beq .L080B11F4
	add r0, sp, #4
	ldrh r1, [r0]
	ldr r0, .L080B11BC
	cmp r1, r0
	beq .L080B11F4
	add r0, sp, #4
	ldrh r0, [r0]
	bl sub_080C2480
	cmp r0, #1
	beq .L080B11F4
	ldr r1, [r4, #4]
	ldr r0, .L080B11C0
	cmp r1, r0
	bne .L080B11C4
	bl sub_080C9100
	mov sl, r0
	cmp r0, #0
	beq .L080B11F4
	adds r1, r4, #0
	bl sub_080AF85C
	mov sb, r0
	b .L080B11F4
	.byte 0x00, 0x00
.L080B11BC: .4byte 0x0000FFFF
.L080B11C0: .4byte gUnknown_08073A00
.L080B11C4:
	adds r0, r1, #0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B11F4
	ldr r1, [r4, #4]
	mov sb, r1
	add r0, sp, #4
	ldrh r0, [r0]
	bl sub_080C24B8
	mov r2, r8
	strh r6, [r2, #0x3e]
	ldr r0, [r4, #4]
	bl ScriptVM_RunAlt
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L080B11F4
	ldr r0, .L080B1210
	bl Flag_Set
.L080B11F4:
	mov r3, sb
	cmp r3, #0
	beq .L080B1214
	mov r0, sl
	cmp r0, #0
	beq .L080B1204
	bl .L080B1A06
.L080B1204:
	movs r0, #0xc
	mov r1, sb
	bl sub_080AF178
	bl .L080B1A06
.L080B1210: .4byte 0x0000010B
.L080B1214:
	movs r0, #1
	bl Field_SetState
	bl Door_TryOpen
	cmp r0, #1
	beq .L080B1226
	bl .L080B1A06
.L080B1226:
	movs r0, #0x1a
	bl Field_SetState
	bl .L080B1A06
.L080B1230:
	cmp r6, #7
	beq .L080B1238
	bl .L080B1A06
.L080B1238:
	movs r0, #7
	bl Field_SetState
	bl .L080B1A06
.L080B1242:
	ldrh r0, [r5, #6]
	ldrh r1, [r5, #8]
	bl sub_080B2064
	movs r0, #6
	bl Field_SetState
	bl .L080B1A06
.L080B1254:
	ldrh r1, [r5, #0x1e]
	subs r0, r1, #1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #6
	bne .L080B12D0
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	beq .L080B126A
	b .L080B16DC
.L080B126A:
	ldr r0, .L080B1294
	bl sub_080AE494
	movs r1, #8
	ldrsh r0, [r5, r1]
	cmp r0, #1
	bne .L080B12A0
	ldr r2, .L080B1298
	ldr r1, .L080B129C
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	movs r0, #1
	bl View_IsSideOpen
	cmp r0, #1
	beq .L080B1290
	b .L080B1A06
.L080B1290:
	movs r0, #1
	b .L080B12BA
.L080B1294: .4byte sub_080B0158
.L080B1298: .4byte 0x0300000C @ IWRAM+0xC
.L080B129C: .4byte 0x03004540 @ IWRAM+0x4540
.L080B12A0:
	ldr r2, .L080B12C4
	ldr r1, .L080B12C8
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	movs r0, #3
	bl View_IsSideOpen
	cmp r0, #1
	beq .L080B12B8
	b .L080B1A06
.L080B12B8:
	ldr r0, .L080B12CC
.L080B12BA:
	movs r1, #0
	bl sub_080B09C4
	b .L080B1A06
	.byte 0x00, 0x00
.L080B12C4: .4byte 0x0300000C @ IWRAM+0xC
.L080B12C8: .4byte 0x03004540 @ IWRAM+0x4540
.L080B12CC: .4byte 0x0000FFFF
.L080B12D0:
	cmp r4, #5
	bne .L080B1308
	movs r2, #8
	ldrsh r0, [r5, r2]
	cmp r0, #1
	bne .L080B12EE
	movs r0, #1
	bl View_IsSideOpen
	cmp r0, #1
	beq .L080B12F8
	movs r0, #0x69
	bl Sound_Play
	b .L080B16AC
.L080B12EE:
	movs r0, #3
	bl View_IsSideOpen
	cmp r0, #1
	bne .L080B1300
.L080B12F8:
	ldrh r0, [r5, #6]
	bl Field_Step
	b .L080B16AC
.L080B1300:
	movs r0, #0x69
	bl Sound_Play
	b .L080B16AC
.L080B1308:
	cmp r4, #0
	bne .L080B1328
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	beq .L080B1314
	b .L080B16DC
.L080B1314:
	ldr r0, .L080B1320
	bl sub_080AE494
	ldr r0, .L080B1324
	strh r4, [r0]
	b .L080B1A06
.L080B1320: .4byte sub_080B0158
.L080B1324: .4byte 0x0300000C @ IWRAM+0xC
.L080B1328:
	ldr r0, .L080B1350
	cmp r4, r0
	beq .L080B1330
	b .L080B1A06
.L080B1330:
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080B133E
	b .L080B19F8
.L080B133E:
	movs r0, #1
	movs r1, #2
	movs r2, #1
	bl sub_080AF8D0
	cmp r0, #0
	beq .L080B134E
	b .L080B1A06
.L080B134E:
	b .L080B16F6
.L080B1350: .4byte 0x0000FFFF
.L080B1354:
	movs r0, #0xae
	bl Flag_Test
	cmp r0, #0
	beq .L080B1394
	movs r0, #0x5e
	bl Flag_Test
	cmp r0, #0
	beq .L080B1370
	ldr r1, .L080B136C
	b .L080B1386
.L080B136C: .4byte gUnknown_0804C354
.L080B1370:
	movs r0, #0x5f
	bl Flag_Test
	cmp r0, #0
	beq .L080B1384
	ldr r1, .L080B1380
	b .L080B1386
	.byte 0x00, 0x00
.L080B1380: .4byte gUnknown_0804C564
.L080B1384:
	ldr r1, .L080B1390
.L080B1386:
	movs r0, #0xc
	bl sub_080AF178
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1390: .4byte gUnknown_0804CB9C
.L080B1394:
	ldr r0, .L080B13C8
	ldr r4, [r0]
	movs r0, #0
	bl Encounter_SetCounter
	movs r0, #4
	ldrsb r0, [r4, r0]
	movs r1, #6
	ldrsb r1, [r4, r1]
	movs r2, #0
	bl sub_080C2CD8
	ldr r0, .L080B13CC
	ldrh r3, [r0, #0x12]
	ldrh r1, [r0, #0x14]
	movs r2, #0x3f
	ands r2, r1
	ldrh r0, [r0, #2]
	cmp r0, #1
	beq .L080B13DE
	cmp r0, #1
	bgt .L080B13D0
	cmp r0, #0
	beq .L080B13DA
	b .L080B13F0
	.byte 0x00, 0x00
.L080B13C8: .4byte 0x03004000 @ IWRAM+0x4000
.L080B13CC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B13D0:
	cmp r0, #2
	beq .L080B13E2
	cmp r0, #3
	beq .L080B13EA
	b .L080B13F0
.L080B13DA:
	adds r0, r2, #1
	b .L080B13E4
.L080B13DE:
	subs r0, r3, #1
	b .L080B13EC
.L080B13E2:
	subs r0, r2, #1
.L080B13E4:
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	b .L080B13F0
.L080B13EA:
	adds r0, r3, #1
.L080B13EC:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L080B13F0:
	mov r4, sp
	adds r4, #6
	add r5, sp, #8
	adds r0, r3, #0
	adds r1, r2, #0
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080C1F50
	ldrh r0, [r4]
	ldrh r1, [r5]
	bl WorldMap_FindLocationByWorldPos
	ldr r2, .L080B141C
	movs r3, #0xc6
	lsls r3, r3, #5
	adds r2, r2, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	b .L080B1A06
.L080B141C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B1420:
	bl sub_080B38A8
	b .L080B1A06
.L080B1426:
	ldr r4, .L080B1464
	ldrh r0, [r4]
	cmp r0, #0x97
	bne .L080B143E
	movs r0, #0x11
	bl Flag_Test
	cmp r0, #0
	beq .L080B143E
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
.L080B143E:
	bl sub_080B38A8
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, r5
	bne .L080B1474
	ldr r5, .L080B1468
	ldrh r0, [r5]
	cmp r0, #0
	bne .L080B1454
	b .L080B1A06
.L080B1454:
	ldr r4, .L080B146C
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r1, .L080B1470
	ldr r0, [r1]
	adds r0, #1
	b .L080B1528
	.byte 0x00, 0x00
.L080B1464: .4byte 0x03004534 @ IWRAM+0x4534
.L080B1468: .4byte 0x0300460C @ IWRAM+0x460C
.L080B146C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1470: .4byte 0x03004514 @ IWRAM+0x4514
.L080B1474:
	cmp r0, #1
	beq .L080B147A
	b .L080B1A06
.L080B147A:
	ldr r0, .L080B1498
	ldr r1, [r0]
	cmp r1, #0
	bne .L080B14A4
	ldr r2, .L080B149C
	ldrh r0, [r2, #0x34]
	cmp r0, #0
	beq .L080B148C
	b .L080B1590
.L080B148C:
	ldrh r0, [r2]
	ldr r1, .L080B14A0
	bl sub_080AF178
	b .L080B1594
	.byte 0x00, 0x00
.L080B1498: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080B149C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B14A0: .4byte gUnknown_08124DBC
.L080B14A4:
	ldr r0, .L080B14D0
	ldr r0, [r0]
	cmp r0, #0
	beq .L080B14AE
	b .L080B1628
.L080B14AE:
	bl sub_080B0820
	movs r0, #0x6e
	bl Sound_Play
	ldr r4, .L080B14D4
	ldrh r0, [r4]
	cmp r0, #0xd
	bne .L080B14DC
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	ldr r1, .L080B14D8
	movs r0, #2
	strh r0, [r1]
	b .L080B15C8
	.byte 0x00, 0x00
.L080B14D0: .4byte 0x030031CC @ IWRAM+0x31CC
.L080B14D4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B14D8: .4byte 0x0300460C @ IWRAM+0x460C
.L080B14DC:
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	ldr r1, .L080B14E8
	movs r0, #0x1c
	b .L080B15F2
.L080B14E8: .4byte 0x0300460C @ IWRAM+0x460C
.L080B14EC:
	ldr r4, .L080B154C
	ldrh r0, [r4]
	cmp r0, #0x98
	bne .L080B1504
	movs r0, #0x11
	bl Flag_Test
	cmp r0, #0
	beq .L080B1504
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
.L080B1504:
	bl sub_080B38A8
	adds r5, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L080B1564
	ldr r5, .L080B1550
	ldrh r0, [r5]
	cmp r0, #0
	bne .L080B151C
	b .L080B1A06
.L080B151C:
	ldr r4, .L080B1554
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r1, .L080B1558
	ldr r0, [r1]
	subs r0, #1
.L080B1528:
	str r0, [r1]
	ldrh r0, [r4, #2]
	bl sub_080B1A1C
	strh r0, [r4, #2]
	bl sub_080AE234
	bl sub_080AE294
	ldr r0, .L080B155C
	ldrh r0, [r0]
	ldrh r1, [r5]
	ldr r2, .L080B1560
	ldrh r2, [r2]
	bl sub_080B31C4
	b .L080B1A06
	.byte 0x00, 0x00
.L080B154C: .4byte 0x03004534 @ IWRAM+0x4534
.L080B1550: .4byte 0x0300460C @ IWRAM+0x460C
.L080B1554: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1558: .4byte 0x03004514 @ IWRAM+0x4514
.L080B155C: .4byte 0x03004614 @ IWRAM+0x4614
.L080B1560: .4byte 0x03003BA8 @ IWRAM+0x3BA8
.L080B1564:
	cmp r5, #1
	beq .L080B156A
	b .L080B1A06
.L080B156A:
	ldr r0, .L080B1584
	ldr r1, [r0]
	cmp r1, #0
	bne .L080B15A4
	ldr r2, .L080B1588
	ldrh r0, [r2, #0x34]
	cmp r0, #0
	bne .L080B1590
	ldrh r0, [r2]
	ldr r1, .L080B158C
	bl sub_080AF178
	b .L080B1594
.L080B1584: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080B1588: .4byte 0x03004550 @ IWRAM+0x4550
.L080B158C: .4byte gUnknown_08124DD8
.L080B1590:
	ldr r0, .L080B159C
	str r1, [r0]
.L080B1594:
	ldr r1, .L080B15A0
	movs r0, #1
	str r0, [r1]
	b .L080B1A06
.L080B159C: .4byte 0x030031CC @ IWRAM+0x31CC
.L080B15A0: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080B15A4:
	ldr r0, .L080B15D4
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B1628
	bl sub_080B0820
	movs r0, #0x6e
	bl Sound_Play
	ldr r4, .L080B15D8
	ldrh r0, [r4]
	cmp r0, #0xe
	bne .L080B15E8
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	ldr r0, .L080B15DC
	strh r5, [r0]
.L080B15C8:
	ldr r1, .L080B15E0
	ldr r0, .L080B15E4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	strh r0, [r1]
	b .L080B1A06
.L080B15D4: .4byte 0x030031CC @ IWRAM+0x31CC
.L080B15D8: .4byte 0x03004550 @ IWRAM+0x4550
.L080B15DC: .4byte 0x0300460C @ IWRAM+0x460C
.L080B15E0: .4byte 0x03003BA8 @ IWRAM+0x3BA8
.L080B15E4: .4byte 0x03004000 @ IWRAM+0x4000
.L080B15E8:
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	ldr r1, .L080B1614
	movs r0, #0x1b
.L080B15F2:
	strh r0, [r1]
	ldr r2, .L080B1618
	ldr r0, .L080B161C
	ldr r1, [r0]
	ldrh r0, [r1, #6]
	strh r0, [r2]
	ldr r2, .L080B1620
	ldrh r0, [r1, #4]
	str r0, [r2]
	ldr r0, .L080B1624
	str r5, [r0]
	ldrh r0, [r1, #8]
	bl sub_080B1A1C
	strh r0, [r4, #2]
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1614: .4byte 0x0300460C @ IWRAM+0x460C
.L080B1618: .4byte 0x03003BA8 @ IWRAM+0x3BA8
.L080B161C: .4byte 0x03004000 @ IWRAM+0x4000
.L080B1620: .4byte 0x03004614 @ IWRAM+0x4614
.L080B1624: .4byte 0x03004514 @ IWRAM+0x4514
.L080B1628:
	bl sub_080B0820
	ldr r1, .L080B163C
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	movs r2, #0
	strh r0, [r1, #0x1e]
	ldr r0, .L080B1640
	strh r2, [r0]
	b .L080B1A06
.L080B163C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1640: .4byte 0x0300460C @ IWRAM+0x460C
.L080B1644:
	bl sub_080B092C
	cmp r0, #0
	beq .L080B164E
	b .L080B1A06
.L080B164E:
	bl sub_080AE234
	ldr r0, .L080B1670
	ldrh r0, [r0]
	ldr r1, .L080B1674
	ldrh r1, [r1]
	ldr r2, .L080B1678
	ldrh r2, [r2]
	bl sub_080B31C4
	ldr r1, .L080B167C
	ldrh r0, [r1, #0xa]
	ldrh r1, [r1, #2]
	movs r2, #3
	bl sub_080B2030
	b .L080B1A06
.L080B1670: .4byte 0x03004614 @ IWRAM+0x4614
.L080B1674: .4byte 0x0300460C @ IWRAM+0x460C
.L080B1678: .4byte 0x03003BA8 @ IWRAM+0x3BA8
.L080B167C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1680:
	bl Automap_Update
	b .L080B1A06
.L080B1686:
	ldrh r1, [r5, #0x1e]
	subs r0, r1, #1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bne .L080B16A8
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	bne .L080B16DC
.L080B169A:
	ldr r0, .L080B16A4
	bl sub_080AE494
	b .L080B1A06
	.byte 0x00, 0x00
.L080B16A4: .4byte sub_080B018C
.L080B16A8:
	cmp r0, #3
	bne .L080B16B8
.L080B16AC:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	b .L080B1A06
.L080B16B8:
	cmp r0, #0
	beq .L080B16BE
	b .L080B1A06
.L080B16BE:
	ldrh r4, [r5, #0xe]
	cmp r4, #0
	bne .L080B16DC
	ldr r0, .L080B16D8
	bl sub_080AE494
	bl sub_080B05A4
	strh r4, [r5, #0x2e]
	movs r0, #0x12
	bl Field_SetState
	b .L080B1A06
.L080B16D8: .4byte sub_080B0158
.L080B16DC:
	strh r1, [r5, #0x1e]
	b .L080B1A06
.L080B16E0:
	bl sub_080B092C
	adds r1, r0, #0
	cmp r1, #0
	beq .L080B16EC
	b .L080B1A06
.L080B16EC:
	ldr r0, .L080B1700
	strh r1, [r0, #0x2e]
	ldrh r0, [r0, #0x32]
	cmp r0, #0
	bne .L080B1704
.L080B16F6:
	movs r0, #1
	bl sub_080B03BC
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1700: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1704:
	movs r0, #4
	bl sub_08128B84
	movs r0, #0xa
	bl Field_SetState
	b .L080B1A06
.L080B1712:
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl FieldMap_HasRecordRel
	cmp r0, #1
	bne .L080B1738
	ldr r1, .L080B1734
	movs r0, #0
	str r0, [r1]
	bl sub_080E4554
	movs r0, #0x15
	bl Field_SetState
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1734: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B1738:
	ldr r4, .L080B176C
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne .L080B1778
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #4
	movs r3, #4
	bl PalFade_FadeRangeToBlackWithDuration
	ldr r1, .L080B1770
	str r0, [r1]
	ldr r0, .L080B1774
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B1764
	movs r0, #0
	movs r1, #1
	movs r2, #4
	movs r3, #4
	bl PalFade_FadeRangeToBlackWithDuration
.L080B1764:
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	b .L080B17B4
.L080B176C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1770: .4byte 0x0300452C @ IWRAM+0x452C
.L080B1774: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080B1778:
	bl sub_080B092C
	adds r1, r0, #0
	cmp r1, #0
	bne .L080B17B4
	ldr r0, .L080B1794
	str r1, [r0]
	bl sub_080E4554
	movs r0, #0x15
	bl Field_SetState
	b .L080B17B4
	.byte 0x00, 0x00
.L080B1794: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B1798:
	ldr r1, .L080B17BC
	movs r0, #1
	str r0, [r1]
	bl sub_080E4554
	bl sub_080B0888
	movs r0, #0x15
	bl Field_SetState
	bl sub_080C7218
	bl sub_080C7414
.L080B17B4:
	movs r0, #1
	bl Music_FadeOut
	b .L080B1A06
.L080B17BC: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B17C0:
	ldr r0, .L080B17F0
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B18A6
	ldr r0, .L080B17F4
	ldrh r1, [r5, #2]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r4, [r1]
	adds r6, r4, #0
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl FieldMap_HasRecordRel
	cmp r0, #1
	bne .L080B17F8
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B189E
	adds r0, r4, #0
	b .L080B1896
.L080B17F0: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B17F4: .4byte gUnknown_0815F31C
.L080B17F8:
	ldrh r0, [r5, #0x1e]
	cmp r0, #0
	bne .L080B1880
	ldr r0, .L080B186C
	ldr r1, [r0]
	ldr r6, .L080B1870
	ldrh r0, [r1]
	strh r0, [r6]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r0, .L080B1874
	ldr r1, [r0]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r2, r6, r3
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r0, .L080B1878
	ldr r1, [r0]
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #1
	movs r3, #0x10
	bl PalFade_FadeRangeWithDuration
	ldr r1, .L080B187C
	str r0, [r1]
	ldrh r0, [r6]
	cmp r0, #0
	bne .L080B185C
	b .L080B19F8
.L080B185C:
	movs r0, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0x10
	bl PalFade_FadeRangeWithDuration
	b .L080B19F8
	.byte 0x00, 0x00
.L080B186C: .4byte 0x03004630 @ IWRAM+0x4630
.L080B1870: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B1874: .4byte 0x03004510 @ IWRAM+0x4510
.L080B1878: .4byte 0x03003FC8 @ IWRAM+0x3FC8
.L080B187C: .4byte 0x0300452C @ IWRAM+0x452C
.L080B1880:
	bl sub_080B092C
	cmp r0, #0
	beq .L080B188A
	b .L080B1A06
.L080B188A:
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B189E
	adds r0, r6, #0
.L080B1896:
	movs r1, #1
	bl sub_080B1A4C
	b .L080B1A06
.L080B189E:
	movs r0, #1
	bl Field_SetState
	b .L080B1A06
.L080B18A6:
	ldrh r0, [r5, #0x1e]
	cmp r0, #0
	bne .L080B18C4
	ldr r1, .L080B18BC
	movs r0, #1
	strh r0, [r1, #0x34]
	bl PalFade_FadeToBlack
	ldr r1, .L080B18C0
	str r0, [r1]
	b .L080B19F8
.L080B18BC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080B18C0: .4byte 0x0300452C @ IWRAM+0x452C
.L080B18C4:
	bl sub_080B092C
	cmp r0, #0
	beq .L080B18CE
	b .L080B1A06
.L080B18CE:
	b .L080B19AE
.L080B18D0:
	bl sub_080B38A8
	adds r1, r0, #0
	cmp r1, #1
	beq .L080B18DC
	b .L080B1A06
.L080B18DC:
	ldr r4, .L080B1908
	ldrh r0, [r4, #0x3a]
	adds r5, r0, #0
	ands r5, r1
	cmp r5, #0
	beq .L080B18EA
	b .L080B1A06
.L080B18EA:
	ldrh r1, [r4, #0x3a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L080B18F6
	b .L080B1A06
.L080B18F6:
	bl sub_080B0820
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	ldr r0, .L080B190C
	strh r5, [r0]
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1908: .4byte 0x03004550 @ IWRAM+0x4550
.L080B190C: .4byte 0x0300460C @ IWRAM+0x460C
.L080B1910:
	ldrh r0, [r5, #0x1e]
	cmp r0, #0
	beq .L080B1918
	b .L080B1A06
.L080B1918:
	ldr r0, .L080B1928
	ldr r0, [r0]
	ldr r1, .L080B192C
	bl Task_Create
	movs r0, #1
	strh r0, [r5, #0x1e]
	b .L080B1A06
.L080B1928: .4byte 0x03004628 @ IWRAM+0x4628
.L080B192C: .4byte 0x0000FFFF
.L080B1930:
	ldrh r0, [r5, #0x1e]
	cmp r0, #0
	bne .L080B1A06
	ldr r0, .L080B1948
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B194C
	movs r0, #0
	bl sub_08128B84
	b .L080B195C
	.byte 0x00, 0x00
.L080B1948: .4byte 0x03004628 @ IWRAM+0x4628
.L080B194C:
	cmp r0, #1
	bne .L080B1958
	movs r0, #0
	bl sub_0812D0FC
	b .L080B195C
.L080B1958:
	bl sub_0812A730
.L080B195C:
	ldr r1, .L080B1968
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	strh r0, [r1, #0x1e]
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1968: .4byte 0x03004550 @ IWRAM+0x4550
.L080B196C:
	ldr r1, .L080B1980
	movs r0, #1
	str r0, [r1]
	bl sub_080AF280
	bl sub_080C7218
	bl sub_080C7414
	b .L080B1A06
.L080B1980: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B1984:
	ldrh r0, [r5, #0x1e]
	cmp r0, #0
	bne .L080B19A4
	ldr r1, .L080B199C
	movs r0, #1
	strh r0, [r1, #0x34]
	bl PalFade_FadeToBlack
	ldr r1, .L080B19A0
	str r0, [r1]
	b .L080B19F8
	.byte 0x00, 0x00
.L080B199C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080B19A0: .4byte 0x0300452C @ IWRAM+0x452C
.L080B19A4:
	bl sub_080B092C
	cmp r0, #0
	bne .L080B1A06
	ldrh r0, [r5]
.L080B19AE:
	ldr r0, .L080B19C8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, .L080B19CC
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #1
	bl sub_080C2CD8
	b .L080B1A06
	.byte 0x00, 0x00
.L080B19C8: .4byte 0x03003FC4 @ IWRAM+0x3FC4
.L080B19CC: .4byte 0x03004618 @ IWRAM+0x4618
.L080B19D0:
	adds r4, r5, #0
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne .L080B19F0
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	bne .L080B1A06
	ldr r0, .L080B19EC
	bl sub_080AE494
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	b .L080B1A06
.L080B19EC: .4byte sub_080B0158
.L080B19F0:
	cmp r0, #1
	bne .L080B1A00
	bl sub_080B05A4
.L080B19F8:
	ldrh r0, [r5, #0x1e]
	adds r0, #1
	strh r0, [r5, #0x1e]
	b .L080B1A06
.L080B1A00:
	movs r0, #0
	bl sub_080B0A08
.L080B1A06:
	bl sub_080B2CC0
.L080B1A0A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
