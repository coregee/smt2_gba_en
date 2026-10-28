	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080AF8D0
sub_080AF8D0: @ 0x080AF8D0
.L080AF8D0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x70
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	movs r0, #0
	movs r1, #0
	bl FieldMap_CellRecordsRel
	adds r4, r0, #0
	movs r1, #4
	bl FieldMap_FindRecord
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0x15
	bl FieldMap_FindRecord
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #1
	bl FieldMap_FindRecord
	str r0, [sp, #0x10]
	adds r0, r4, #0
	movs r1, #2
	bl FieldMap_FindRecord
	str r0, [sp, #0x14]
	adds r0, r4, #0
	movs r1, #0x1b
	bl FieldMap_FindRecord
	str r0, [sp, #0x18]
	adds r0, r4, #0
	movs r1, #0x1c
	bl FieldMap_FindRecord
	str r0, [sp, #0x1c]
	adds r0, r4, #0
	movs r1, #0x10
	bl FieldMap_FindRecord
	str r0, [sp, #0x20]
	adds r0, r4, #0
	movs r1, #0x13
	bl FieldMap_FindRecord
	adds r6, r0, #0
	adds r0, r4, #0
	movs r1, #0x1d
	bl FieldMap_FindRecord
	str r0, [sp, #0x24]
	adds r0, r4, #0
	movs r1, #0x1e
	bl FieldMap_FindRecord
	str r0, [sp, #0x28]
	adds r0, r4, #0
	movs r1, #3
	bl FieldMap_FindRecord
	str r0, [sp, #0x2c]
	adds r0, r4, #0
	movs r1, #9
	bl FieldMap_FindRecord
	str r0, [sp, #0x30]
	adds r0, r4, #0
	movs r1, #8
	bl FieldMap_FindRecord
	str r0, [sp, #0x34]
	adds r0, r4, #0
	movs r1, #0x19
	bl FieldMap_FindRecord
	str r0, [sp, #0x38]
	adds r0, r4, #0
	movs r1, #5
	bl FieldMap_FindRecord
	str r0, [sp, #0x3c]
	adds r0, r4, #0
	movs r1, #0xb
	bl FieldMap_FindRecord
	str r0, [sp, #0x40]
	adds r0, r4, #0
	movs r1, #0xc
	bl FieldMap_FindRecord
	str r0, [sp, #0x44]
	adds r0, r4, #0
	movs r1, #0xd
	bl FieldMap_FindRecord
	str r0, [sp, #0x48]
	adds r0, r4, #0
	movs r1, #0xe
	bl FieldMap_FindRecord
	str r0, [sp, #0x4c]
	adds r0, r4, #0
	movs r1, #0xf
	bl FieldMap_FindRecord
	str r0, [sp, #0x50]
	adds r0, r4, #0
	movs r1, #0x25
	bl FieldMap_FindRecord
	str r0, [sp, #0x54]
	adds r0, r4, #0
	movs r1, #0x26
	bl FieldMap_FindRecord
	str r0, [sp, #0x58]
	adds r0, r4, #0
	movs r1, #0x27
	bl FieldMap_FindRecord
	str r0, [sp, #0x5c]
	ldr r2, .L080AFA58
	ldrh r0, [r2, #0x12]
	ldrh r1, [r2, #0x14]
	ldrh r2, [r2, #2]
	mov r3, sp
	bl sub_080C9084
	adds r7, r0, #0
	adds r0, r4, #0
	movs r1, #0x14
	bl FieldMap_FindRecord
	str r0, [sp, #0x60]
	adds r0, r4, #0
	movs r1, #0x1f
	bl FieldMap_FindRecord
	adds r5, r0, #0
	adds r0, r4, #0
	movs r1, #0x16
	bl FieldMap_FindRecord
	mov sl, r0
	adds r0, r4, #0
	movs r1, #0x17
	bl FieldMap_FindRecord
	str r0, [sp, #0x64]
	adds r0, r4, #0
	movs r1, #0x18
	bl FieldMap_FindRecord
	str r0, [sp, #0x68]
	adds r0, r4, #0
	movs r1, #0x1a
	bl FieldMap_FindRecord
	str r0, [sp, #0x6c]
	ldr r0, .L080AFA5C
	movs r1, #0
	str r1, [r0]
	ldr r0, .L080AFA60
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080AFA38
	b .L080B0102
.L080AFA38:
	cmp r5, #0
	beq .L080AFA8C
	ldrh r0, [r5, #4]
	bl sub_080C57CC
	cmp r0, #1
	bne .L080AFA8C
	mov r2, r8
	cmp r2, #1
	bne .L080AFA76
	mov r3, sb
	cmp r3, #1
	bne .L080AFA64
	adds r0, r5, #0
	b .L080B0080
	.byte 0x00, 0x00
.L080AFA58: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFA5C: .4byte 0x03004538 @ IWRAM+0x4538
.L080AFA60: .4byte 0x03003FF4 @ IWRAM+0x3FF4
.L080AFA64:
	mov r0, sb
	cmp r0, #2
	bne .L080AFA76
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080AF6E4
	adds r0, r5, #0
	b .L080B00DA
.L080AFA76:
	mov r1, r8
	cmp r1, #2
	beq .L080AFA7E
	b .L080B0102
.L080AFA7E:
	mov r2, sb
	cmp r2, #2
	beq .L080AFA86
	b .L080B0102
.L080AFA86:
	adds r0, r4, #0
	adds r1, r5, #0
	b .L080B00A0
.L080AFA8C:
	ldr r3, [sp, #8]
	cmp r3, #0
	beq .L080AFAAC
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	movs r0, #0xb
	bl Field_SetState
	ldr r1, .L080AFAA8
	movs r0, #0
	strh r0, [r1, #0x1e]
	b .L080B0102
.L080AFAA8: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFAAC:
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq .L080AFAD8
	adds r0, r4, #0
	ldr r1, [sp, #0xc]
	bl sub_080AF6E4
	movs r0, #0xc
	bl Field_SetState
	ldr r0, .L080AFAD0
	mov r1, sp
	ldrh r1, [r1, #8]
	strh r1, [r0, #0x1e]
	ldr r1, .L080AFAD4
	ldr r2, [sp, #0xc]
	b .L080AFE6C
	.byte 0x00, 0x00
.L080AFAD0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFAD4: .4byte 0x03004534 @ IWRAM+0x4534
.L080AFAD8:
	ldr r3, [sp, #0x10]
	cmp r3, #0
	beq .L080AFB14
	ldrh r0, [r3, #2]
	cmp r0, #0
	beq .L080AFB14
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	movs r0, #0xd
	bl Field_SetState
	ldr r0, .L080AFB08
	mov r1, sp
	ldrh r1, [r1, #0xc]
	strh r1, [r0, #0x1e]
	ldr r1, .L080AFB0C
	ldr r2, [sp, #0x10]
	ldrh r0, [r2, #2]
	strh r0, [r1]
	ldr r0, .L080AFB10
	ldr r3, [sp, #0xc]
	b .L080B0100
.L080AFB08: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFB0C: .4byte 0x03004534 @ IWRAM+0x4534
.L080AFB10: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080AFB14:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq .L080AFB44
	movs r1, #0
	cmp r1, #0
	bne .L080AFB44
	cmp r6, #0
	bne .L080AFB44
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	bl sub_080AF6E4
	movs r0, #0x21
	bl Field_SetState
	ldr r0, .L080AFB3C
	strh r6, [r0, #0x1e]
	ldr r1, .L080AFB40
	ldr r2, [sp, #0x18]
	b .L080AFBB4
.L080AFB3C: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFB40: .4byte 0x03004534 @ IWRAM+0x4534
.L080AFB44:
	ldr r3, [sp, #0x14]
	cmp r3, #0
	beq .L080AFB8E
	ldrh r0, [r3, #2]
	cmp r0, #0
	beq .L080AFB80
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	movs r0, #0xe
	bl Field_SetState
	ldr r0, .L080AFB74
	movs r2, #0
	strh r2, [r0, #0x1e]
	ldr r1, .L080AFB78
	ldr r3, [sp, #0x14]
	ldrh r0, [r3, #2]
	strh r0, [r1]
	ldr r0, .L080AFB7C
	str r2, [r0]
	b .L080B0102
	.byte 0x00, 0x00
.L080AFB74: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFB78: .4byte 0x03004534 @ IWRAM+0x4534
.L080AFB7C: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080AFB80:
	adds r0, r4, #0
	ldr r1, [sp, #0x14]
	bl sub_080AF6E4
	bl sub_080B5FD8
	b .L080B0102
.L080AFB8E:
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq .L080AFBCC
	movs r1, #0
	cmp r1, #0
	bne .L080AFBCC
	cmp r6, #0
	bne .L080AFBCC
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	bl sub_080AF6E4
	movs r0, #0x22
	bl Field_SetState
	ldr r0, .L080AFBC0
	strh r6, [r0, #0x1e]
	ldr r1, .L080AFBC4
	ldr r2, [sp, #0x1c]
.L080AFBB4:
	ldrh r0, [r2, #2]
	strh r0, [r1]
	ldr r0, .L080AFBC8
	str r6, [r0]
	b .L080B0102
	.byte 0x00, 0x00
.L080AFBC0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFBC4: .4byte 0x03004534 @ IWRAM+0x4534
.L080AFBC8: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080AFBCC:
	ldr r3, [sp, #0x20]
	cmp r3, #0
	beq .L080AFBEC
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080AFBE4
	movs r1, #0
	strh r1, [r0, #0x1e]
	ldr r1, .L080AFBE8
	b .L080B005E
.L080AFBE4: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFBE8: .4byte gUnknown_0805A65E
.L080AFBEC:
	cmp r6, #0
	beq .L080AFC62
	ldr r0, [r6, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFC0E
	ldr r0, [r6, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFC0E
	b .L080B0102
.L080AFC0E:
	adds r0, r4, #0
	adds r1, r6, #0
	bl sub_080AF6E4
	ldr r0, .L080AFC3C
	mov r1, sp
	ldrh r1, [r1, #0x20]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #4]
	cmp r2, #0
	bne .L080AFC4A
	movs r0, #0
	movs r1, #0
	movs r2, #0x28
	bl FieldMap_HasRecordRel
	cmp r0, #1
	bne .L080AFC40
	ldr r1, [r6, #4]
	movs r0, #0xc
	bl sub_080AF1D0
	b .L080AFC52
.L080AFC3C: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFC40:
	ldr r1, [r6, #4]
	movs r0, #0xc
	bl sub_080AF178
	b .L080AFC52
.L080AFC4A:
	ldr r1, [r6, #4]
	movs r0, #0xc
	bl sub_080AF1D0
.L080AFC52:
	ldr r3, [sp, #0x6c]
	cmp r3, #0
	bne .L080AFC5A
	b .L080B0102
.L080AFC5A:
	ldrh r0, [r3, #2]
	bl sub_080B011C
	b .L080B0102
.L080AFC62:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq .L080AFCEC
	ldrh r6, [r0, #2]
	cmp r6, #0
	bne .L080AFCEC
	bl sub_080B6170
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L080AFCCC
	cmp r1, r0
	bne .L080AFC80
	ldr r0, .L080AFCD0
	ldrh r1, [r0, #2]
.L080AFC80:
	lsls r1, r1, #2
	ldr r0, [sp, #0x24]
	adds r0, #4
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	bne .L080AFC90
	b .L080B0102
.L080AFC90:
	adds r0, r5, #0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFCAE
	adds r0, r5, #0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFCAE
	b .L080B0102
.L080AFCAE:
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	bl sub_080AF6E4
	ldr r0, .L080AFCD0
	strh r6, [r0, #0x1e]
	ldr r1, [sp, #4]
	cmp r1, #0
	bne .L080AFCD4
	movs r0, #0xc
	adds r1, r5, #0
	bl sub_080AF178
	b .L080AFCDC
	.byte 0x00, 0x00
.L080AFCCC: .4byte 0x0000FFFF
.L080AFCD0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFCD4:
	movs r0, #0xc
	adds r1, r5, #0
	bl sub_080AF1D0
.L080AFCDC:
	ldr r2, [sp, #0x6c]
	cmp r2, #0
	bne .L080AFCE4
	b .L080B0102
.L080AFCE4:
	ldrh r0, [r2, #2]
	bl sub_080B011C
	b .L080B0102
.L080AFCEC:
	ldr r3, [sp, #0x28]
	cmp r3, #0
	beq .L080AFD4E
	movs r0, #0
	bl sub_080C06BC
	lsls r0, r0, #2
	ldr r1, [sp, #0x28]
	adds r1, #4
	adds r1, r1, r0
	ldr r5, [r1]
	adds r0, r5, #0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFD20
	adds r0, r5, #0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFD20
	b .L080B0102
.L080AFD20:
	adds r0, r4, #0
	ldr r1, [sp, #0x28]
	bl sub_080AF6E4
	ldr r1, .L080AFD40
	movs r0, #0
	strh r0, [r1, #0x1e]
	ldr r0, [sp, #4]
	cmp r0, #0
	bne .L080AFD44
	movs r0, #0xc
	adds r1, r5, #0
	bl sub_080AF178
	b .L080B0102
	.byte 0x00, 0x00
.L080AFD40: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFD44:
	movs r0, #0xc
	adds r1, r5, #0
	bl sub_080AF1D0
	b .L080B0102
.L080AFD4E:
	cmp r7, #0
	beq .L080AFDC0
	ldr r1, [r7, #4]
	ldr r0, .L080AFD74
	cmp r1, r0
	bne .L080AFD78
	bl Palette_IsBg13Black
	cmp r0, #0
	bne .L080AFD78
	bl sub_080C9100
	cmp r0, #0
	bne .L080AFD6C
	b .L080B0102
.L080AFD6C:
	adds r1, r7, #0
	bl sub_080AF85C
	b .L080B0102
.L080AFD74: .4byte gUnknown_08073A00
.L080AFD78:
	ldr r0, [r7, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFD96
	ldr r0, [r7, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFD96
	b .L080B0102
.L080AFD96:
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, .L080AFDBC
	cmp r1, r0
	bne .L080AFDA2
	b .L080B0102
.L080AFDA2:
	mov r0, sp
	ldrh r0, [r0]
	bl sub_080C2480
	cmp r0, #1
	bne .L080AFDB0
	b .L080B0102
.L080AFDB0:
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl sub_080AF7E8
	b .L080B0102
.L080AFDBC: .4byte 0x0000FFFF
.L080AFDC0:
	mov r1, sl
	cmp r1, #0
	beq .L080AFDF0
	ldr r0, [r1, #4]
	cmp r0, #0
	beq .L080AFDF0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFDEA
	mov r2, sl
	ldr r0, [r2, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFDEA
	b .L080B0102
.L080AFDEA:
	adds r0, r4, #0
	mov r1, sl
	b .L080AFE4E
.L080AFDF0:
	ldr r3, [sp, #0x64]
	cmp r3, #0
	beq .L080AFE20
	ldr r0, [r3, #4]
	cmp r0, #0
	beq .L080AFE20
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFE1A
	ldr r1, [sp, #0x64]
	ldr r0, [r1, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFE1A
	b .L080B0102
.L080AFE1A:
	adds r0, r4, #0
	ldr r1, [sp, #0x64]
	b .L080AFE4E
.L080AFE20:
	ldr r2, [sp, #0x68]
	cmp r2, #0
	beq .L080AFE56
	ldr r0, [r2, #4]
	cmp r0, #0
	beq .L080AFE56
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFE4A
	ldr r3, [sp, #0x68]
	ldr r0, [r3, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFE4A
	b .L080B0102
.L080AFE4A:
	adds r0, r4, #0
	ldr r1, [sp, #0x68]
.L080AFE4E:
	ldr r2, [sp, #4]
	bl sub_080AF6F8
	b .L080B0102
.L080AFE56:
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq .L080AFE78
	adds r0, r4, #0
	ldr r1, [sp, #0x2c]
	bl sub_080AF6E4
	bl sub_080BA070
	ldr r1, .L080AFE74
	ldr r2, [sp, #0x2c]
.L080AFE6C:
	ldrh r0, [r2, #2]
	strh r0, [r1]
	b .L080B0102
	.byte 0x00, 0x00
.L080AFE74: .4byte 0x03003B9C @ IWRAM+0x3B9C
.L080AFE78:
	ldr r3, [sp, #0x30]
	cmp r3, #0
	beq .L080AFE8C
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	bl sub_080B5E50
	b .L080B0102
.L080AFE8C:
	ldr r0, [sp, #0x34]
	cmp r0, #0
	beq .L080AFEB8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq .L080AFEA6
	ldr r1, [sp, #0x34]
	ldrh r0, [r1, #2]
	subs r0, #1
	ldr r1, .L080AFEB4
	ldrh r1, [r1, #2]
	cmp r0, r1
	beq .L080AFEB8
.L080AFEA6:
	adds r0, r4, #0
	ldr r1, [sp, #0x34]
	bl sub_080AF6E4
	bl sub_080B614C
	b .L080B0102
.L080AFEB4: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFEB8:
	ldr r2, [sp, #0x38]
	cmp r2, #0
	beq .L080AFEFC
	mov r0, r8
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080AFECC
	b .L080B0102
.L080AFECC:
	mov r3, sb
	cmp r3, #2
	beq .L080AFED4
	b .L080B0102
.L080AFED4:
	ldr r0, .L080AFEF8
	ldrh r1, [r0, #0x3a]
	movs r2, #0
	strh r2, [r0, #0x3a]
	ldrh r1, [r0, #0x38]
	movs r1, #0x40
	strh r1, [r0, #0x38]
	ldrh r1, [r0, #0x3c]
	strh r2, [r0, #0x3c]
	ldrh r0, [r0, #0x38]
	bl Field_HandleInput
	adds r0, r4, #0
	ldr r1, [sp, #0x38]
	bl sub_080AF6E4
	b .L080B0102
	.byte 0x00, 0x00
.L080AFEF8: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFEFC:
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	beq .L080AFF5A
	bl sub_080F3F44
	movs r1, #0x50
	ands r1, r0
	cmp r1, #0
	beq .L080AFF10
	b .L080B0102
.L080AFF10:
	mov r1, r8
	cmp r1, #1
	bne .L080AFF44
	mov r2, sb
	cmp r2, #2
	bne .L080AFF34
	adds r0, r4, #0
	ldr r1, [sp, #0x3c]
	bl sub_080AF6E4
	ldr r0, [sp, #0x3c]
	movs r1, #0
	bl sub_080B8FF0
	movs r0, #0x20
	bl Field_SetState
	b .L080B0102
.L080AFF34:
	mov r3, sb
	cmp r3, #1
	bne .L080AFF44
	ldr r0, [sp, #0x3c]
	movs r1, #1
	bl sub_080B8FF0
	b .L080B0084
.L080AFF44:
	mov r0, r8
	cmp r0, #2
	beq .L080AFF4C
	b .L080B0102
.L080AFF4C:
	mov r1, sb
	cmp r1, #2
	beq .L080AFF54
	b .L080B0102
.L080AFF54:
	adds r0, r4, #0
	ldr r1, [sp, #0x3c]
	b .L080B00A0
.L080AFF5A:
	ldr r2, [sp, #0x40]
	cmp r2, #0
	beq .L080AFF7C
	adds r0, r4, #0
	adds r1, r2, #0
	bl sub_080AF6E4
	ldr r0, .L080AFF78
	mov r3, sp
	ldrh r3, [r3, #0x3c]
	strh r3, [r0, #0x1e]
	ldr r0, [sp, #0x40]
	ldr r1, [r0, #4]
	b .L080B005E
	.byte 0x00, 0x00
.L080AFF78: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFF7C:
	ldr r1, [sp, #0x44]
	cmp r1, #0
	beq .L080AFFA4
	ldr r0, [r1, #4]
	cmp r0, #0
	bne .L080AFF8A
	b .L080B0102
.L080AFF8A:
	adds r0, r4, #0
	bl sub_080AF6E4
	ldr r0, .L080AFFA0
	add r2, sp, #0x40
	ldrh r2, [r2]
	strh r2, [r0, #0x1e]
	ldr r3, [sp, #0x44]
	ldr r1, [r3, #4]
	b .L080B005E
	.byte 0x00, 0x00
.L080AFFA0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFFA4:
	ldr r0, [sp, #0x48]
	cmp r0, #0
	beq .L080AFFC4
	adds r0, r4, #0
	ldr r1, [sp, #0x48]
	bl sub_080AF6E4
	ldr r0, .L080AFFC0
	add r1, sp, #0x44
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x48]
	b .L080B005C
	.byte 0x00, 0x00
.L080AFFC0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFFC4:
	ldr r3, [sp, #0x4c]
	cmp r3, #0
	beq .L080AFFE4
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080AFFE0
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x4c]
	b .L080B005C
	.byte 0x00, 0x00
.L080AFFE0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFFE4:
	ldr r3, [sp, #0x50]
	cmp r3, #0
	beq .L080B0004
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080B0000
	add r1, sp, #0x4c
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x50]
	b .L080B005C
	.byte 0x00, 0x00
.L080B0000: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0004:
	ldr r3, [sp, #0x54]
	cmp r3, #0
	beq .L080B0024
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080B0020
	add r1, sp, #0x50
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x54]
	b .L080B005C
	.byte 0x00, 0x00
.L080B0020: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0024:
	ldr r3, [sp, #0x58]
	cmp r3, #0
	beq .L080B0044
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080B0040
	add r1, sp, #0x54
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x58]
	b .L080B005C
	.byte 0x00, 0x00
.L080B0040: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0044:
	ldr r3, [sp, #0x5c]
	cmp r3, #0
	beq .L080B006C
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080B0068
	add r1, sp, #0x58
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x5c]
.L080B005C:
	ldr r1, [r2, #4]
.L080B005E:
	movs r0, #0xc
	bl sub_080AF178
	b .L080B0102
	.byte 0x00, 0x00
.L080B0068: .4byte 0x03004550 @ IWRAM+0x4550
.L080B006C:
	ldr r3, [sp, #0x60]
	cmp r3, #0
	beq .L080B00F0
	mov r0, r8
	cmp r0, #1
	bne .L080B0090
	mov r1, sb
	cmp r1, #1
	bne .L080B0090
	adds r0, r3, #0
.L080B0080:
	bl sub_080B8994
.L080B0084:
	ldr r1, .L080B008C
	str r0, [r1]
	b .L080B0102
	.byte 0x00, 0x00
.L080B008C: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080B0090:
	mov r2, r8
	cmp r2, #2
	bne .L080B00C4
	mov r3, sb
	cmp r3, #2
	bne .L080B00C4
	adds r0, r4, #0
	ldr r1, [sp, #0x60]
.L080B00A0:
	bl sub_080AF6E4
	ldr r1, .L080B00BC
	movs r0, #0
	strh r0, [r1, #0x1e]
	movs r0, #0x20
	bl Field_SetState
	ldr r0, .L080B00C0
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0xc]
	b .L080B0102
	.byte 0x00, 0x00
.L080B00BC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B00C0: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080B00C4:
	mov r0, r8
	cmp r0, #1
	bne .L080B0102
	mov r1, sb
	cmp r1, #2
	bne .L080B0102
	adds r0, r4, #0
	ldr r1, [sp, #0x60]
	bl sub_080AF6E4
	ldr r0, [sp, #0x60]
.L080B00DA:
	bl sub_080B8994
	ldr r1, .L080B00EC
	str r0, [r1]
	movs r0, #0x1a
	bl Field_SetState
	b .L080B0102
	.byte 0x00, 0x00
.L080B00EC: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080B00F0:
	ldr r2, [sp, #0x6c]
	cmp r2, #0
	beq .L080B0102
	ldrh r0, [r2, #2]
	bl sub_080B011C
	ldr r0, .L080B0118
	ldr r3, [sp, #0x60]
.L080B0100:
	str r3, [r0]
.L080B0102:
	ldr r0, .L080B0118
	ldr r0, [r0]
	add sp, #0x70
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B0118: .4byte 0x03004538 @ IWRAM+0x4538
