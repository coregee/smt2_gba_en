	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start MessageBox_ComposeWrappedText
MessageBox_ComposeWrappedText: @ 0x080EBED4
.L080EBED4:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	mov r8, r0
	mov sb, r1
	ldr r5, .L080EBF04
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r4, r5, r0
	movs r7, #0
	mov r0, sp
	movs r1, #0
	movs r2, #0x12
	bl memset
	ldrb r0, [r4, #7]
	cmp r0, #1
	bne .L080EBF0C
	ldr r1, .L080EBF08
	adds r0, r5, r1
	b .L080EC018
	.byte 0x00, 0x00
.L080EBF04: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EBF08: .4byte 0x000008EC
.L080EBF0C:
	str r7, [sp, #0x14]
	add r0, sp, #0x14
	ldr r3, .L080EBF24
	adds r4, r5, r3
	ldr r2, .L080EBF28
	adds r1, r4, #0
	bl CpuSet
	adds r6, r4, #0
	mov r5, r8
	b .L080EBFFE
	.byte 0x00, 0x00
.L080EBF24: .4byte 0x000008EC
.L080EBF28: .4byte 0x05000020 @ PLTT+0x20
.L080EBF2C:
	adds r2, r1, #0
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r2, r0
	bne .L080EBFC4
	movs r0, #0x80
	lsls r0, r0, #8
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r4, #0
	adds r5, #2
	b .L080EBF50
.L080EBF4A:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
.L080EBF50:
	cmp r4, #3
	bhi .L080EBF68
	adds r0, r4, #0
	bl sub_080F3EC8
	cmp r0, #0
	beq .L080EBF4A
	adds r0, r4, #0
	bl sub_080C0A00
	cmp r0, #0
	beq .L080EBF4A
.L080EBF68:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
	adds r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	mov r1, sp
	bl Combatant_DecodeName
	movs r1, #0
	mov r0, sp
	b .L080EBFA2
.L080EBF84:
	lsls r0, r1, #1
	.2byte 0x4468 @ add r0, sp, r0
	ldrh r0, [r0]
	strh r0, [r6]
	adds r6, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #7
	bhi .L080EBFA8
	lsls r0, r1, #1
	.2byte 0x4468 @ add r0, sp, r0
.L080EBFA2:
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080EBF84
.L080EBFA8:
	bl sub_080F4968
	cmp r0, #1
	ble .L080EBFFE
	ldr r3, .L080EBFC0
	adds r0, r3, #0
	strh r0, [r6]
	adds r6, #2
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	b .L080EBFFE
.L080EBFC0: .4byte 0x00000C8F
.L080EBFC4:
	ldr r3, .L080EC028
	adds r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080EBFFC
	movs r4, #0xc0
	lsls r4, r4, #2
	cmp r2, r4
	beq .L080EBFFC
	strh r1, [r6]
	adds r6, #2
	ldrh r1, [r5]
	ldr r0, .L080EC02C
	cmp r1, r0
	beq .L080EBFFC
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r7, #0
	movs r1, #0x11
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080EBFFC
	strh r4, [r6]
	adds r6, #2
.L080EBFFC:
	adds r5, #2
.L080EBFFE:
	ldrh r1, [r5]
	ldr r0, .L080EC030
	cmp r1, r0
	bne .L080EBF2C
	subs r6, #2
	ldrh r1, [r6]
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r1, r0
	bne .L080EC016
	movs r0, #0
	strh r0, [r6]
.L080EC016:
	ldr r0, .L080EC034
.L080EC018:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080EC028: .4byte 0xFFFFFCEA
.L080EC02C: .4byte 0x00000315
.L080EC030: .4byte 0x00000301
.L080EC034: .4byte 0x0203CAEC @ EWRAM+0x3CAEC

	thumb_func_start sub_080EC038
sub_080EC038: @ 0x080EC038
.L080EC038:
	lsls r0, r0, #0x10
	ldr r1, .L080EC044
	lsrs r0, r0, #0xe
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
.L080EC044: .4byte gUnknown_0876FB54

	thumb_func_start sub_080EC048
sub_080EC048: @ 0x080EC048
	push {r4, lr}
	ldr r4, .L080EC064
	bl sub_080EA210
	ldr r1, .L080EC068
	ldrh r0, [r1, #0xc]
	cmp r0, #0
	beq .L080EC06C
	movs r0, #9
	strh r0, [r1, #0x10]
	bl sub_080ECF60
	b .L080EC070
	.byte 0x00, 0x00
.L080EC064: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EC068: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080EC06C:
	bl sub_080EC948
.L080EC070:
	ldr r0, .L080EC08C
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	ldr r2, .L080EC090
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne .L080EC086
	movs r0, #3
	strh r0, [r1]
.L080EC086:
	pop {r4}
	pop {r0}
	bx r0
.L080EC08C: .4byte 0x00000978
.L080EC090: .4byte 0x00001189

	thumb_func_start sub_080EC094
sub_080EC094: @ 0x080EC094
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, .L080EC0C0
	movs r0, #0xb3
	lsls r0, r0, #1
	bl Flag_Test
	cmp r0, #0
	beq .L080EC0C8
	bl sub_080ED9F4
	adds r4, r0, #0
	bl sub_080ED9F4
	adds r3, r0, #0
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, .L080EC0C4
	b .L080EC10E
	.byte 0x00, 0x00
.L080EC0C0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EC0C4: .4byte gUnknown_081267E0
.L080EC0C8:
	bl sub_080ED954
	cmp r0, #1
	bne .L080EC0F8
	movs r0, #0
	bl sub_080EDA24
	adds r4, r0, #0
	movs r0, #1
	bl sub_080EDA24
	adds r3, r0, #0
	movs r2, #0x99
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	adds r2, #4
	adds r1, r5, r2
	ldr r1, [r1]
	ldr r2, .L080EC0F4
	str r2, [sp]
	b .L080EC112
.L080EC0F4: .4byte gUnknown_081267BA
.L080EC0F8:
	bl sub_080ED9F4
	adds r4, r0, #0
	bl sub_080ED9F4
	adds r3, r0, #0
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, .L080EC138
.L080EC10E:
	str r0, [sp]
	adds r0, r1, #0
.L080EC112:
	adds r2, r4, #0
	bl MessageBox_ComposeSpeciesText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r2, .L080EC13C
	adds r1, r5, r2
	movs r2, #0
	movs r0, #3
	strh r0, [r1]
	ldr r1, .L080EC140
	adds r0, r5, r1
	strh r2, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080EC138: .4byte gUnknown_081267A6
.L080EC13C: .4byte 0x00000978
.L080EC140: .4byte 0x0000097A

	thumb_func_start sub_080EC144
sub_080EC144: @ 0x080EC144
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, .L080EC170
	mov r8, r0
	bl sub_080C84A0
	movs r7, #0
	strh r7, [r5, #0x1c]
	ldr r6, .L080EC174
	add r6, r8
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #1
	beq .L080EC1C2
	cmp r0, #1
	bgt .L080EC178
	cmp r0, #0
	beq .L080EC17E
	b .L080EC250
	.byte 0x00, 0x00
.L080EC170: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EC174: .4byte 0x0000097A
.L080EC178:
	cmp r0, #2
	beq .L080EC240
	b .L080EC250
.L080EC17E:
	ldr r0, .L080EC1B0
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bgt .L080EC192
	bl sub_080EDE70
	ldr r1, .L080EC1B4
	strh r0, [r1, #0x16]
.L080EC192:
	ldr r4, .L080EC1B4
	ldrh r0, [r4, #0x16]
	bl sub_080ED920
	ldrh r0, [r4, #0x16]
	cmp r0, #0
	bne .L080EC1BC
	ldr r0, .L080EC1B8
	add r0, r8
	movs r1, #5
	strh r1, [r0]
	strh r7, [r6]
	movs r0, #1
	b .L080EC24E
	.byte 0x00, 0x00
.L080EC1B0: .4byte 0x00000F6A
.L080EC1B4: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080EC1B8: .4byte 0x00000978
.L080EC1BC:
	movs r0, #1
	strh r0, [r6]
	b .L080EC250
.L080EC1C2:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080EC250
	ldr r0, .L080EC1FC
	ldrh r1, [r0, #0x16]
	movs r0, #0xc0
	lsls r0, r0, #8
	cmp r1, r0
	bne .L080EC208
	bl sub_080EC948
	ldr r0, .L080EC200
	bl sub_080EC038
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, .L080EC204
	add r1, r8
	movs r0, #0xa
	b .L080EC22C
	.byte 0x00, 0x00
.L080EC1FC: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080EC200: .4byte 0x00000167
.L080EC204: .4byte 0x00000978
.L080EC208:
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r1, r0
	bne .L080EC22E
	movs r0, #0xb3
	lsls r0, r0, #1
	bl sub_080EC038
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetModeAutoClose
	ldr r1, .L080EC238
	add r1, r8
	movs r0, #5
.L080EC22C:
	strh r0, [r1]
.L080EC22E:
	ldr r1, .L080EC23C
	add r1, r8
	movs r0, #2
	strh r0, [r1]
	b .L080EC250
.L080EC238: .4byte 0x00000978
.L080EC23C: .4byte 0x0000097A
.L080EC240:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080EC250
	strh r7, [r6]
.L080EC24E:
	strh r0, [r5, #0x1c]
.L080EC250:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080EC25C
sub_080EC25C: @ 0x080EC25C
	push {r4, lr}
	ldr r4, .L080EC27C
	ldr r1, .L080EC280
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl sub_080EC99C
	ldr r0, .L080EC284
	adds r4, r4, r0
	movs r0, #7
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
.L080EC27C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EC280: .4byte gUnknown_086BE5DA
.L080EC284: .4byte 0x00000978

	thumb_func_start sub_080EC288
sub_080EC288: @ 0x080EC288
	push {r4, lr}
	ldr r4, .L080EC2C8
	movs r0, #0
	bl BattleMsg_SetLocked
	ldr r1, .L080EC2CC
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl sub_080EC99C
	ldr r0, .L080EC2D0
	adds r4, r4, r0
	movs r0, #7
	strh r0, [r4]
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L080EC2D8
	ldr r0, .L080EC2D4
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080EC2DC
	cmp r0, #2
	beq .L080EC2DC
	bl sub_080C700C
	b .L080EC2DC
.L080EC2C8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EC2CC: .4byte gUnknown_086BE5DA
.L080EC2D0: .4byte 0x00000978
.L080EC2D4: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080EC2D8:
	bl sub_080C7054
.L080EC2DC:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080EC2E4
sub_080EC2E4: @ 0x080EC2E4
.L080EC2E4:
	push {r4, lr}
	ldr r4, .L080EC304
	bl sub_080EFA9C
	ldr r1, .L080EC308
	adds r2, r4, r1
	movs r1, #0
	strh r1, [r2]
	subs r0, #1
	cmp r0, #0xa
	bhi .L080EC350
	lsls r0, r0, #2
	ldr r1, .L080EC30C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080EC304: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EC308: .4byte 0x000011A8
.L080EC30C: .4byte gUnknown_080EC310
	.global gUnknown_080EC310
gUnknown_080EC310:
.L080EC310: @ jump table
	.4byte .L080EC33C
	.4byte .L080EC350
	.4byte .L080EC350
	.4byte .L080EC348
	.4byte .L080EC348
	.4byte .L080EC348
	.4byte .L080EC348
	.4byte .L080EC33C
	.4byte .L080EC348
	.4byte .L080EC348
	.4byte .L080EC348
.L080EC33C:
	ldr r0, .L080EC344
	adds r1, r4, r0
	movs r0, #1
	b .L080EC34E
.L080EC344: .4byte 0x000011A8
.L080EC348:
	ldr r0, .L080EC358
	adds r1, r4, r0
	movs r0, #2
.L080EC34E:
	strh r0, [r1]
.L080EC350:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EC358: .4byte 0x000011A8

	thumb_func_start sub_080EC35C
sub_080EC35C: @ 0x080EC35C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, .L080EC380
	movs r0, #0
	strh r0, [r6, #0x1c]
	ldr r1, .L080EC384
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #9
	bls .L080EC374
	b .L080EC7F4
.L080EC374:
	lsls r0, r0, #2
	ldr r1, .L080EC388
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080EC380: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EC384: .4byte 0x0000097A
.L080EC388: .4byte gUnknown_080EC38C
	.global gUnknown_080EC38C
gUnknown_080EC38C:
.L080EC38C: @ jump table
	.4byte .L080EC3B4
	.4byte .L080EC4A8
	.4byte .L080EC548
	.4byte .L080EC5CC
	.4byte .L080EC600
	.4byte .L080EC630
	.4byte .L080EC65C
	.4byte .L080EC70C
	.4byte .L080EC7CC
	.4byte .L080EC7DE
.L080EC3B4:
	ldr r3, .L080EC3F0
	adds r6, r5, r3
	movs r0, #0
	strh r0, [r6]
	movs r0, #1
	bl Flag_Test
	cmp r0, #0
	bne .L080EC3D0
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	beq .L080EC400
.L080EC3D0:
	ldr r0, .L080EC3F4
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldr r0, .L080EC3F8
	adds r1, r5, r0
	movs r0, #6
	strh r0, [r1]
	ldr r2, .L080EC3FC
	adds r1, r5, r2
	b .L080EC79C
	.byte 0x00, 0x00
.L080EC3F0: .4byte 0x000011A8
.L080EC3F4: .4byte gUnknown_081265BE
.L080EC3F8: .4byte 0x00000978
.L080EC3FC: .4byte 0x0000097A
.L080EC400:
	movs r0, #3
	bl Flag_Test
	cmp r0, #0
	bne .L080EC414
	ldr r0, .L080EC410
	b .L080EC782
	.byte 0x00, 0x00
.L080EC410: .4byte gUnknown_0812490C
.L080EC414:
	ldr r1, .L080EC448
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080EC42E
	movs r0, #0
	bl sub_080C0818
	ldr r1, .L080EC44C
	ands r1, r0
	cmp r1, #0
	beq .L080EC450
.L080EC42E:
	movs r0, #0
	bl sub_080C0818
	ldr r1, .L080EC44C
	ands r1, r0
	movs r0, #0xb0
	lsls r0, r0, #1
	cmp r1, #0
	bne .L080EC442
	b .L080EC77E
.L080EC442:
	adds r0, #1
	b .L080EC77E
	.byte 0x00, 0x00
.L080EC448: .4byte 0x00000F6A
.L080EC44C: .4byte 0x0000B160
.L080EC450:
	bl sub_080ED8F4
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq .L080EC47C
	bl sub_080EF99C
	lsls r0, r0, #0x10
	asrs r0, r0, #0xe
	movs r2, #0x99
	lsls r2, r2, #4
	adds r1, r5, r2
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r1, .L080EC478
	bl MessageBox_ComposeNameText
	b .L080EC788
	.byte 0x00, 0x00
.L080EC478: .4byte gUnknown_0812466C
.L080EC47C:
	ldr r0, .L080EC4A0
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldr r1, .L080EC4A4
	adds r0, r5, r1
	movs r4, #1
	strh r4, [r0]
	movs r0, #8
	bl sub_080E5A18
	strh r4, [r6]
	b .L080EC7F4
	.byte 0x00, 0x00
.L080EC4A0: .4byte gUnknown_0812634E
.L080EC4A4: .4byte 0x0000097A
.L080EC4A8:
	ldr r2, .L080EC4E8
	adds r4, r5, r2
	movs r6, #0
	movs r0, #3
	strh r0, [r4]
	ldr r0, .L080EC4EC
	ldr r0, [r0]
	movs r3, #0x91
	lsls r3, r3, #1
	adds r0, r0, r3
	strh r6, [r0]
	bl sub_080ED954
	cmp r0, #1
	bne .L080EC534
	movs r0, #0
	bl sub_080EDA24
	cmp r0, #0
	beq .L080EC4F4
	movs r0, #1
	bl sub_080EDA24
	cmp r0, #0
	beq .L080EC4F4
	ldr r1, .L080EC4F0
	adds r0, r5, r1
	strh r6, [r0]
	movs r0, #2
	strh r0, [r4]
	b .L080EC7F4
	.byte 0x00, 0x00
.L080EC4E8: .4byte 0x0000097A
.L080EC4EC: .4byte 0x03006434 @ IWRAM+0x6434
.L080EC4F0: .4byte 0x0000097E
.L080EC4F4:
	movs r0, #0
	bl sub_080EDA24
	cmp r0, #0
	beq .L080EC518
	ldr r0, .L080EC514
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0
	strh r0, [r1]
	movs r3, #0x99
	lsls r3, r3, #4
	adds r0, r5, r3
	b .L080EC53A
.L080EC514: .4byte 0x03006434 @ IWRAM+0x6434
.L080EC518:
	ldr r0, .L080EC52C
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #1
	strh r0, [r1]
	ldr r3, .L080EC530
	adds r0, r5, r3
	b .L080EC53A
.L080EC52C: .4byte 0x03006434 @ IWRAM+0x6434
.L080EC530: .4byte 0x00000994
.L080EC534:
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r5, r1
.L080EC53A:
	ldrh r0, [r0]
	ldr r1, .L080EC544
	bl sub_0813EB84
	b .L080EC7F4
.L080EC544: .4byte 0x0000FFFF
.L080EC548:
	bl sub_080E6FA0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #3
	bne .L080EC5A8
	ldr r0, .L080EC580
	ldr r1, [r0]
	ldr r3, .L080EC584
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r3, #0x91
	lsls r3, r3, #1
	adds r1, r1, r3
	strh r0, [r1]
	ldr r3, .L080EC588
	adds r0, r5, r3
	strh r2, [r0]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne .L080EC590
	adds r3, #0x16
	adds r0, r5, r3
	ldrh r0, [r0]
	ldr r2, .L080EC58C
	b .L080EC59A
	.byte 0x00, 0x00
.L080EC580: .4byte 0x03006434 @ IWRAM+0x6434
.L080EC584: .4byte 0x00000695
.L080EC588: .4byte 0x0000097A
.L080EC58C: .4byte 0x00000994
.L080EC590:
	ldr r3, .L080EC5A4
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r2, #0x99
	lsls r2, r2, #4
.L080EC59A:
	adds r1, r5, r2
	ldrh r1, [r1]
	bl sub_0813EB84
	b .L080EC7F4
.L080EC5A4: .4byte 0x00000994
.L080EC5A8:
	cmp r2, #2
	beq .L080EC5AE
	b .L080EC7F4
.L080EC5AE:
	bl BattleMenu_Reset
	ldr r3, .L080EC5C4
	adds r1, r5, r3
	movs r2, #0
	movs r0, #6
	strh r0, [r1]
	ldr r1, .L080EC5C8
	adds r0, r5, r1
	strh r2, [r0]
	b .L080EC7C0
.L080EC5C4: .4byte 0x00000978
.L080EC5C8: .4byte 0x000011A8
.L080EC5CC:
	bl BattleMenu_Reset
	ldr r2, .L080EC61C
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #8
	bl Window_SetHeight
	ldr r3, .L080EC620
	adds r1, r5, r3
	ldr r0, .L080EC624
	strh r0, [r1]
	bl sub_0813E914
	bl sub_080C7430
	bl sub_080C7648
	ldr r0, .L080EC628
	adds r1, r5, r0
	movs r0, #0xa
	strh r0, [r1]
	ldr r2, .L080EC62C
	adds r1, r5, r2
	movs r0, #4
	strh r0, [r1]
.L080EC600:
	ldr r3, .L080EC628
	adds r1, r5, r3
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080EC612
	b .L080EC7F4
.L080EC612:
	ldr r0, .L080EC62C
	adds r1, r5, r0
	movs r0, #5
	strh r0, [r1]
	b .L080EC7F4
.L080EC61C: .4byte 0x00000974
.L080EC620: .4byte 0x0000118E
.L080EC624: .4byte 0x0000FFFF
.L080EC628: .4byte 0x000011B2
.L080EC62C: .4byte 0x0000097A
.L080EC630:
	bl sub_0813EB60
	ldr r1, .L080EC654
	cmp r0, r1
	bne .L080EC63C
	b .L080EC7F4
.L080EC63C:
	bl sub_080EEF98
	bl sub_080C7414
	bl sub_080C762C
	ldr r2, .L080EC658
	adds r1, r5, r2
	movs r0, #6
	strh r0, [r1]
	b .L080EC7F4
	.byte 0x00, 0x00
.L080EC654: .4byte 0x0000FFFF
.L080EC658: .4byte 0x0000097A
.L080EC65C:
	bl sub_080ED8F4
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq .L080EC66C
	bl sub_080EC948
.L080EC66C:
	bl sub_080EFA9C
	adds r4, r0, #0
	bl sub_080EC2E4
	cmp r4, #6
	beq .L080EC686
	cmp r4, #8
	beq .L080EC686
	cmp r4, #0xc
	beq .L080EC686
	cmp r4, #5
	bne .L080EC690
.L080EC686:
	movs r3, #0xec
	lsls r3, r3, #4
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
.L080EC690:
	cmp r4, #4
	bne .L080EC69A
	movs r0, #0x80
	lsls r0, r0, #6
	b .L080EC6B0
.L080EC69A:
	adds r0, r4, #0
	subs r0, #9
	cmp r0, #2
	bls .L080EC6AC
	subs r0, r4, #6
	cmp r0, #1
	bls .L080EC6AC
	cmp r4, #0xc
	bne .L080EC6EC
.L080EC6AC:
	movs r0, #0x80
	lsls r0, r0, #2
.L080EC6B0:
	bl sub_080ED90C
	ldr r1, .L080EC6E0
	adds r0, r5, r1
	movs r7, #0
	strh r7, [r0]
	ldr r2, .L080EC6E4
	adds r1, r5, r2
	movs r0, #0xe
	strh r0, [r1]
	movs r0, #1
	strh r0, [r6, #0x1c]
	ldr r3, .L080EC6E8
	adds r4, r5, r3
	ldr r0, [r4]
	cmp r0, #0
	bne .L080EC6D4
	b .L080EC7F4
.L080EC6D4:
	movs r1, #0
	bl Window_Close
	str r7, [r4]
	b .L080EC7F4
	.byte 0x00, 0x00
.L080EC6E0: .4byte 0x0000097A
.L080EC6E4: .4byte 0x00000978
.L080EC6E8: .4byte 0x00000974
.L080EC6EC:
	ldr r1, .L080EC704
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #2
	bl Window_SetHeight
	ldr r2, .L080EC708
	adds r1, r5, r2
	movs r0, #7
	strh r0, [r1]
	b .L080EC7F4
	.byte 0x00, 0x00
.L080EC704: .4byte 0x00000974
.L080EC708: .4byte 0x0000097A
.L080EC70C:
	bl sub_080EFA9C
	adds r4, r0, #0
	cmp r4, #3
	beq .L080EC77A
	cmp r4, #3
	bgt .L080EC720
	cmp r4, #2
	beq .L080EC72A
	b .L080EC7B8
.L080EC720:
	cmp r4, #5
	beq .L080EC7AC
	cmp r4, #8
	beq .L080EC7AC
	b .L080EC7B8
.L080EC72A:
	bl sub_080EC948
	ldr r0, .L080EC764
	bl sub_080EC038
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldr r3, .L080EC768
	adds r1, r5, r3
	movs r0, #9
	strh r0, [r1]
	ldr r0, .L080EC76C
	adds r1, r5, r0
	movs r0, #0xa
	strh r0, [r1]
	ldr r1, .L080EC770
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080EC774
	bl sub_080C6FF0
	b .L080EC7F4
.L080EC764: .4byte 0x00000167
.L080EC768: .4byte 0x0000097A
.L080EC76C: .4byte 0x00000978
.L080EC770: .4byte 0x00000F6A
.L080EC774:
	bl sub_080C7038
	b .L080EC7F4
.L080EC77A:
	movs r0, #0xb3
	lsls r0, r0, #1
.L080EC77E:
	bl sub_080EC038
.L080EC782:
	movs r1, #0
	bl Menu_ExpandListTemplate
.L080EC788:
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldr r3, .L080EC7A4
	adds r1, r5, r3
	movs r0, #6
	strh r0, [r1]
	ldr r0, .L080EC7A8
	adds r1, r5, r0
.L080EC79C:
	movs r0, #9
	strh r0, [r1]
	b .L080EC7F4
	.byte 0x00, 0x00
.L080EC7A4: .4byte 0x00000978
.L080EC7A8: .4byte 0x0000097A
.L080EC7AC:
	ldr r1, .L080EC7B4
	adds r0, r5, r1
	b .L080EC7BC
	.byte 0x00, 0x00
.L080EC7B4: .4byte 0x00000978
.L080EC7B8:
	ldr r2, .L080EC7C8
	adds r0, r5, r2
.L080EC7BC:
	movs r1, #6
	strh r1, [r0]
.L080EC7C0:
	movs r0, #1
	strh r0, [r6, #0x1c]
	b .L080EC7F4
	.byte 0x00, 0x00
.L080EC7C8: .4byte 0x00000978
.L080EC7CC:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080EC7F4
	bl sub_080E5A3C
	b .L080EC7F4
.L080EC7DE:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080EC7F4
	movs r1, #0
	strh r0, [r6, #0x1c]
	ldr r3, .L080EC7FC
	adds r0, r5, r3
	strh r1, [r0]
.L080EC7F4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EC7FC: .4byte 0x0000097A

	thumb_func_start sub_080EC800
sub_080EC800: @ 0x080EC800
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, .L080EC824
	mov r8, r0
	movs r7, #0
	strh r7, [r5, #0x1c]
	ldr r6, .L080EC828
	add r6, r8
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq .L080EC82C
	cmp r0, #1
	beq .L080EC89C
	b .L080EC918
	.byte 0x00, 0x00
.L080EC824: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EC828: .4byte 0x0000097A
.L080EC82C:
	bl sub_080EDF0C
	adds r1, r0, #0
	str r1, [r5, #0x24]
	ldr r0, .L080EC848
	cmp r1, r0
	beq .L080EC860
	cmp r1, r0
	bgt .L080EC84C
	subs r0, #1
	cmp r1, r0
	beq .L080EC856
	b .L080EC88C
	.byte 0x00, 0x00
.L080EC848: .4byte 0x00000145
.L080EC84C:
	movs r0, #0xa3
	lsls r0, r0, #1
	cmp r1, r0
	beq .L080EC878
	b .L080EC88C
.L080EC856:
	ldr r0, .L080EC85C
	b .L080EC862
	.byte 0x00, 0x00
.L080EC85C: .4byte gUnknown_08126254
.L080EC860:
	ldr r0, .L080EC874
.L080EC862:
	movs r1, #0
	bl MessageBox_ComposeWrappedText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	b .L080EC88C
	.byte 0x00, 0x00
.L080EC874: .4byte gUnknown_081262BE
.L080EC878:
	adds r0, r1, #0
	bl sub_080EC038
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
.L080EC88C:
	ldr r1, .L080EC898
	add r1, r8
	movs r0, #1
	strh r0, [r1]
	b .L080EC918
	.byte 0x00, 0x00
.L080EC898: .4byte 0x0000097A
.L080EC89C:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #1
	bne .L080EC918
	ldr r1, [r5, #0x24]
	movs r0, #0xa2
	lsls r0, r0, #1
	cmp r1, r0
	beq .L080EC8FA
	bl sub_080EC948
	movs r0, #0xc0
	lsls r0, r0, #8
	bl sub_080ED920
	strh r7, [r6]
	ldr r1, .L080EC8E8
	add r1, r8
	movs r0, #0xa
	strh r0, [r1]
	ldr r1, .L080EC8EC
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	strh r4, [r5, #0x1c]
	ldr r0, .L080EC8F0
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080EC8F4
	bl sub_080C6FF0
	b .L080EC918
	.byte 0x00, 0x00
.L080EC8E8: .4byte 0x00000978
.L080EC8EC: .4byte 0x00001122
.L080EC8F0: .4byte 0x00000F6A
.L080EC8F4:
	bl sub_080C7038
	b .L080EC918
.L080EC8FA:
	movs r0, #0x80
	lsls r0, r0, #6
	bl sub_080ED90C
	ldr r1, .L080EC924
	ldrh r0, [r1, #0xc]
	cmp r0, #2
	bne .L080EC90C
	strh r4, [r1, #0x14]
.L080EC90C:
	strh r7, [r6]
	ldr r1, .L080EC928
	add r1, r8
	movs r0, #0xe
	strh r0, [r1]
	strh r4, [r5, #0x1c]
.L080EC918:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EC924: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080EC928: .4byte 0x00000978

	thumb_func_start sub_080EC92C
sub_080EC92C: @ 0x080EC92C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080EC942
	strh r0, [r4, #0x1c]
.L080EC942:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080EC948
sub_080EC948: @ 0x080EC948
.L080EC948:
	push {lr}
	ldr r0, .L080EC970
	ldr r2, .L080EC974
	adds r1, r0, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne .L080EC96A
	movs r0, #1
	strh r0, [r1]
	bl sub_080EFEDC
	ldr r1, .L080EC978
	strh r0, [r1, #0x10]
	ldrh r0, [r1, #0x10]
	bl sub_080ECF60
.L080EC96A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EC970: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EC974: .4byte 0x00000F68
.L080EC978: .4byte 0x030063A0 @ IWRAM+0x63A0

	thumb_func_start sub_080EC97C
sub_080EC97C: @ 0x080EC97C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_080F3144
	adds r4, r0, #0
	cmp r4, #1
	bne .L080EC992
	bl sub_080B9058
	strh r4, [r5, #0x1c]
	b .L080EC996
.L080EC992:
	movs r0, #0
	strh r0, [r5, #0x1c]
.L080EC996:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080EC99C
sub_080EC99C: @ 0x080EC99C
.L080EC99C:
	ldr r1, .L080EC9A8
	movs r2, #0xfc
	lsls r2, r2, #3
	adds r1, r1, r2
	strb r0, [r1, #4]
	bx lr
.L080EC9A8: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080EC9AC
sub_080EC9AC: @ 0x080EC9AC
.L080EC9AC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r2, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080EC9F0
	mov r8, r0
	movs r6, #0x8b
	lsls r6, r6, #5
	add r6, r8
	ldr r0, .L080EC9F4
	ldr r1, .L080EC9F8
	bl Task_Create
	str r0, [r6, #0x14]
	movs r1, #0
	movs r0, #1
	strb r0, [r6]
	strb r1, [r6, #1]
	strb r1, [r6, #4]
	strb r1, [r6, #5]
	strb r4, [r6, #2]
	strh r5, [r6, #6]
	cmp r4, #0xc7
	bls .L080EC9FC
	movs r0, #0x38
	b .L080EC9FE
	.byte 0x00, 0x00
.L080EC9F0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EC9F4: .4byte gUnknown_086BF734
.L080EC9F8: .4byte 0x0000FFFF
.L080EC9FC:
	movs r0, #0x30
.L080EC9FE:
	strh r0, [r6, #0xe]
	ldr r1, .L080ECA18
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	strh r1, [r6, #0xc]
	cmp r7, #1
	bne .L080ECA20
	ldr r0, .L080ECA1C
	add r0, r8
	ldrh r0, [r0]
	adds r0, r1, r0
	b .L080ECA2C
.L080ECA18: .4byte gUnknown_086BF72C
.L080ECA1C: .4byte 0x0000118C
.L080ECA20:
	cmp r7, #2
	bne .L080ECA2E
	ldr r0, .L080ECA58
	add r0, r8
	ldrh r0, [r0]
	subs r0, r1, r0
.L080ECA2C:
	strh r0, [r6, #0xc]
.L080ECA2E:
	ldr r2, .L080ECA5C
	ldrb r1, [r6, #2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x10]
	adds r0, r1, #0
	cmp r0, #0xc7
	bhi .L080ECA4E
	movs r0, #8
	movs r1, #0x10
	bl sub_080C140C
.L080ECA4E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080ECA58: .4byte 0x0000118C
.L080ECA5C: .4byte gUnknown_0876CE10

	thumb_func_start sub_080ECA60
sub_080ECA60: @ 0x080ECA60
.L080ECA60:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r2, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080ECAA0
	mov r8, r0
	movs r6, #0x8b
	lsls r6, r6, #5
	add r6, r8
	ldr r0, .L080ECAA4
	ldr r1, .L080ECAA8
	bl Task_Create
	str r0, [r6, #0x14]
	movs r1, #0
	movs r0, #1
	strb r0, [r6]
	strb r1, [r6, #4]
	strb r1, [r6, #5]
	strb r4, [r6, #2]
	strh r5, [r6, #6]
	cmp r4, #0xc7
	bls .L080ECAAC
	movs r0, #0x3a
	b .L080ECAAE
.L080ECAA0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ECAA4: .4byte gUnknown_086BF734
.L080ECAA8: .4byte 0x0000FFFF
.L080ECAAC:
	movs r0, #0x32
.L080ECAAE:
	strh r0, [r6, #0xe]
	ldr r1, .L080ECAC8
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	strh r1, [r6, #0xc]
	cmp r7, #1
	bne .L080ECAD0
	ldr r0, .L080ECACC
	add r0, r8
	ldrh r0, [r0]
	adds r0, r1, r0
	b .L080ECADC
.L080ECAC8: .4byte gUnknown_086BF72C
.L080ECACC: .4byte 0x0000118C
.L080ECAD0:
	cmp r7, #2
	bne .L080ECADE
	ldr r0, .L080ECB08
	add r0, r8
	ldrh r0, [r0]
	subs r0, r1, r0
.L080ECADC:
	strh r0, [r6, #0xc]
.L080ECADE:
	ldr r2, .L080ECB0C
	ldrb r1, [r6, #2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x10]
	adds r0, r1, #0
	cmp r0, #0xc7
	bhi .L080ECAFE
	movs r0, #8
	movs r1, #0x10
	bl sub_080C140C
.L080ECAFE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080ECB08: .4byte 0x0000118C
.L080ECB0C: .4byte gUnknown_0876CE10

	thumb_func_start sub_080ECB10
sub_080ECB10: @ 0x080ECB10
.L080ECB10:
	push {lr}
	ldr r0, .L080ECB24
	movs r2, #0x8b
	lsls r2, r2, #5
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #3
	beq .L080ECB28
	movs r0, #0
	b .L080ECB32
.L080ECB24: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ECB28:
	movs r0, #0
	strb r0, [r1]
	bl sub_080C1440
	movs r0, #1
.L080ECB32:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080ECB38
sub_080ECB38: @ 0x080ECB38
.L080ECB38:
	push {r4, lr}
	ldr r4, .L080ECB58
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, [r4, #0x14]
	bl Task_End
	movs r0, #0
	strb r0, [r4]
	bl sub_080C1440
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080ECB58: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080ECB5C
sub_080ECB5C: @ 0x080ECB5C
	ldr r1, .L080ECB68
	movs r2, #0x8b
	lsls r2, r2, #5
	adds r1, r1, r2
	strb r0, [r1]
	bx lr
.L080ECB68: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080ECB6C
sub_080ECB6C: @ 0x080ECB6C
.L080ECB6C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x18
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #3
	ldr r0, .L080ECB90
	adds r2, r2, r0
	lsrs r1, r1, #0x16
	adds r2, #8
	adds r2, r2, r1
	ldr r0, [r2]
	ldr r1, .L080ECB94
	bl HuffUnComp
	pop {r1}
	bx r1
.L080ECB90: .4byte gUnknown_0876CE10
.L080ECB94: .4byte 0x0200AFC8 @ EWRAM+0xAFC8

	thumb_func_start sub_080ECB98
sub_080ECB98: @ 0x080ECB98
.L080ECB98:
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, .L080ECBE0
	adds r5, r1, r0
	ldr r0, .L080ECBE4
	lsls r1, r4, #0xb
	ldr r2, .L080ECBE8
	adds r1, r1, r2
	bl LZ77UnCompWram
	cmp r4, #0
	bne .L080ECBD4
	ldr r2, .L080ECBEC
	ldr r1, [r5, #4]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
.L080ECBD4:
	movs r0, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080ECBE0: .4byte gUnknown_0876CE10
.L080ECBE4: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080ECBE8: .4byte 0x030000B4 @ IWRAM+0xB4
.L080ECBEC: .4byte 0x03003130 @ IWRAM+0x3130

	thumb_func_start sub_080ECBF0
sub_080ECBF0: @ 0x080ECBF0
	push {lr}
	ldr r0, .L080ECC0C
	movs r3, #0x8b
	lsls r3, r3, #5
	adds r2, r0, r3
	ldrb r0, [r2, #2]
	cmp r0, #0xd2
	bhi .L080ECC08
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_080ECB98
.L080ECC08:
	pop {r0}
	bx r0
.L080ECC0C: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080ECC10
sub_080ECC10: @ 0x080ECC10
	push {lr}
	ldr r0, .L080ECC2C
	movs r3, #0x8b
	lsls r3, r3, #5
	adds r2, r0, r3
	ldrb r0, [r2, #2]
	cmp r0, #0xd2
	bhi .L080ECC28
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_080ECB6C
.L080ECC28:
	pop {r0}
	bx r0
.L080ECC2C: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080ECC30
sub_080ECC30: @ 0x080ECC30
	ldr r1, .L080ECC44
	ldr r0, .L080ECC48
	str r0, [r1]
	ldr r0, .L080ECC4C
	str r0, [r1, #4]
	ldr r0, .L080ECC50
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080ECC44: .4byte 0x040000D4 @ REG_DMA3SAD
.L080ECC48: .4byte 0x030000B4 @ IWRAM+0xB4
.L080ECC4C: .4byte 0x06014000 @ VRAM+0x14000
.L080ECC50: .4byte 0x84000400

	thumb_func_start sub_080ECC54
sub_080ECC54: @ 0x080ECC54
	ldr r1, .L080ECC68
	ldr r0, .L080ECC6C
	str r0, [r1]
	ldr r0, .L080ECC70
	str r0, [r1, #4]
	ldr r0, .L080ECC74
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080ECC68: .4byte 0x040000D4 @ REG_DMA3SAD
.L080ECC6C: .4byte 0x030010B4 @ IWRAM+0x10B4
.L080ECC70: .4byte 0x06015000 @ VRAM+0x15000
.L080ECC74: .4byte 0x84000400

	thumb_func_start sub_080ECC78
sub_080ECC78: @ 0x080ECC78
	push {lr}
	ldr r0, .L080ECC98
	movs r2, #0x8b
	lsls r2, r2, #5
	adds r0, r0, r2
	ldrb r0, [r0, #2]
	cmp r0, #0xd2
	bhi .L080ECCA8
	cmp r1, #0
	bne .L080ECCA0
	ldr r0, .L080ECC9C
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080ECCA8
	.byte 0x00, 0x00
.L080ECC98: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ECC9C: .4byte sub_080ECC30
.L080ECCA0:
	ldr r0, .L080ECCAC
	movs r1, #1
	bl VBlankTask_AddCounted
.L080ECCA8:
	pop {r0}
	bx r0
.L080ECCAC: .4byte sub_080ECC54

	thumb_func_start sub_080ECCB0
sub_080ECCB0: @ 0x080ECCB0
.L080ECCB0:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r3, [r5, #4]
	lsls r0, r3, #3
	ldr r4, [r5, #0x10]
	adds r6, r4, r0
	ldrb r2, [r5, #5]
	ldrh r0, [r6, #4]
	ldrb r1, [r5, #1]
	adds r0, r0, r1
	cmp r2, r0
	bne .L080ECD18
	adds r0, r3, #1
	movs r1, #0
	strb r0, [r5, #4]
	strb r1, [r5, #5]
	ldrb r2, [r5, #4]
	lsls r0, r2, #3
	adds r6, r4, r0
	ldr r1, [r6]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080ECCFE
	ldrb r0, [r5, #2]
	cmp r0, #0xd2
	beq .L080ECCF0
	movs r0, #0
	b .L080ECD92
.L080ECCF0:
	subs r0, r2, #1
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	ldrb r0, [r5, #4]
	lsls r0, r0, #3
	adds r6, r4, r0
.L080ECCFE:
	ldrh r1, [r6, #4]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne .L080ECD18
	ldrb r1, [r6, #6]
	ldrb r0, [r5, #4]
	subs r0, r0, r1
	strb r0, [r5, #4]
	ldrb r0, [r5, #4]
	lsls r0, r0, #3
	ldr r1, [r5, #0x10]
	adds r6, r1, r0
.L080ECD18:
	ldrb r0, [r5, #2]
	cmp r0, #0xd2
	bne .L080ECD70
	lsls r0, r0, #4
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r2, .L080ECDA0
	adds r2, r2, r0
	ldrb r0, [r5, #8]
	adds r0, #1
	movs r1, #0x1f
	ands r0, r1
	strb r0, [r5, #8]
	lsrs r4, r0, #1
	ldr r3, .L080ECDA4
	ldr r2, [r2, #4]
	mov r8, r2
	movs r7, #0
.L080ECD3E:
	cmp r4, #0
	bne .L080ECD44
	movs r4, #1
.L080ECD44:
	lsls r0, r4, #1
	add r0, r8
	ldrh r0, [r0]
	str r3, [sp, #0xc]
	bl Color_ApplyEffect
	ldr r3, [sp, #0xc]
	strh r0, [r3]
	adds r3, #2
	adds r1, r4, #1
	lsls r1, r1, #0x18
	movs r0, #0xf0
	lsls r0, r0, #0x14
	ands r0, r1
	lsrs r4, r0, #0x18
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0xe
	bls .L080ECD3E
	bl Palette_MarkDirty
.L080ECD70:
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldrh r1, [r5, #0xc]
	str r1, [sp, #4]
	ldrh r1, [r5, #0xe]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xc
	movs r3, #2
	bl Sprite_DrawPlain
	ldrb r0, [r5, #5]
	adds r0, #1
	strb r0, [r5, #5]
	movs r0, #1
.L080ECD92:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080ECDA0: .4byte gUnknown_0876CE10
.L080ECDA4: .4byte 0x03003132 @ IWRAM+0x3132

	thumb_func_start sub_080ECDA8
sub_080ECDA8: @ 0x080ECDA8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080ECDD8
	movs r2, #0x8b
	lsls r2, r2, #5
	adds r1, r0, r2
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldrb r0, [r1, #2]
	cmp r0, #0xd2
	bhi .L080ECDCE
	movs r0, #2
	strb r0, [r1]
	adds r0, r1, #0
	bl sub_080ECCB0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080ECDD2
.L080ECDCE:
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080ECDD2:
	pop {r4}
	pop {r0}
	bx r0
.L080ECDD8: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080ECDDC
sub_080ECDDC: @ 0x080ECDDC
	ldr r0, .L080ECDEC
	movs r1, #0x8b
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080ECDEC: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080ECDF0
sub_080ECDF0: @ 0x080ECDF0
	push {lr}
	ldr r0, .L080ECE04
	movs r1, #0x8b
	lsls r1, r1, #5
	adds r0, r0, r1
	ldrh r0, [r0, #6]
	bl sub_08126D34
	pop {r0}
	bx r0
.L080ECE04: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080ECE08
sub_080ECE08: @ 0x080ECE08
.L080ECE08:
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r4, .L080ECE2C
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, .L080ECE30
	ldr r1, .L080ECE34
	bl Task_Create
	str r0, [r4, #0x14]
	strb r5, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080ECE2C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ECE30: .4byte gUnknown_086BF840
.L080ECE34: .4byte 0x0000FFFF

	thumb_func_start sub_080ECE38
sub_080ECE38: @ 0x080ECE38
.L080ECE38:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r5, r2, #0
	ldr r6, .L080ECE68
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r3, r6, r0
	ldrb r0, [r3]
	cmp r0, #4
	bne .L080ECE58
	strb r4, [r3, #3]
.L080ECE58:
	cmp r2, #1
	beq .L080ECE8A
	cmp r2, #1
	bgt .L080ECE6C
	cmp r2, #0
	beq .L080ECE76
	b .L080ECEA6
	.byte 0x00, 0x00
.L080ECE68: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ECE6C:
	cmp r5, #3
	beq .L080ECE80
	cmp r5, #5
	beq .L080ECE94
	b .L080ECEA6
.L080ECE76:
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	bl sub_080C88C0
	b .L080ECE9C
.L080ECE80:
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	bl sub_080C8890
	b .L080ECE9C
.L080ECE8A:
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	bl sub_080C88A8
	b .L080ECE9C
.L080ECE94:
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	bl sub_080C88D8
.L080ECE9C:
	asrs r4, r4, #0xe
	adds r1, r6, #0
	adds r1, #0x10
	adds r4, r4, r1
	str r0, [r4]
.L080ECEA6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080ECEAC
sub_080ECEAC: @ 0x080ECEAC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, .L080ECED4
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #4
	bne .L080ECED8
	ldrb r0, [r2, #3]
	lsls r0, r0, #2
	adds r1, #0x10
	adds r0, r0, r1
	ldr r0, [r0]
	bl sub_080C88F0
	cmp r0, #1
	bne .L080ECF0A
	b .L080ECF08
	.byte 0x00, 0x00
.L080ECED4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ECED8:
	cmp r0, #5
	bne .L080ECF06
	movs r5, #0
	movs r4, #0
	adds r7, r1, #0
	adds r7, #0x10
.L080ECEE4:
	lsls r0, r4, #2
	adds r0, r7, r0
	ldr r0, [r0]
	bl sub_080C88F0
	cmp r0, #1
	bne .L080ECEF8
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L080ECEF8:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls .L080ECEE4
	cmp r5, #6
	bne .L080ECF0A
.L080ECF06:
	movs r0, #1
.L080ECF08:
	strh r0, [r6, #0x1c]
.L080ECF0A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080ECF10
sub_080ECF10: @ 0x080ECF10
	push {r4, lr}
	ldr r1, .L080ECF30
	movs r0, #0x8b
	lsls r0, r0, #5
	adds r3, r1, r0
	ldrb r0, [r3]
	cmp r0, #4
	bne .L080ECF34
	ldrb r0, [r3, #3]
	lsls r0, r0, #2
	adds r1, #0x10
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	b .L080ECF50
	.byte 0x00, 0x00
.L080ECF30: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ECF34:
	cmp r0, #5
	bne .L080ECF50
	movs r2, #0
	adds r4, r1, #0
	adds r4, #0x10
	movs r1, #0
.L080ECF40:
	lsls r0, r2, #2
	adds r0, r4, r0
	str r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #5
	bls .L080ECF40
.L080ECF50:
	movs r1, #0
	movs r0, #3
	strb r0, [r3]
	strb r1, [r3, #3]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080ECF60
sub_080ECF60: @ 0x080ECF60
.L080ECF60:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C5170
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080ECF70
sub_080ECF70: @ 0x080ECF70
.L080ECF70:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_08126D34
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080ECF80
sub_080ECF80: @ 0x080ECF80
.L080ECF80:
	push {r4, lr}
	ldr r4, .L080ECFA4
	ldr r0, .L080ECFA8
	ldr r1, .L080ECFAC
	bl Task_Create
	str r0, [r4, #0x2c]
	adds r0, #0x24
	movs r2, #0
	strb r2, [r0]
	strb r2, [r0, #1]
	movs r1, #0x10
	strb r1, [r0, #2]
	strb r1, [r0, #4]
	strb r2, [r0, #3]
	pop {r4}
	pop {r0}
	bx r0
.L080ECFA4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ECFA8: .4byte gUnknown_086BF86C
.L080ECFAC: .4byte 0x0000FFFF

	thumb_func_start sub_080ECFB0
sub_080ECFB0: @ 0x080ECFB0
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0x24
	movs r4, #0
	movs r0, #0
	strh r0, [r3, #0x1c]
	ldrb r0, [r2, #3]
	adds r5, r0, #0
	cmp r5, #1
	bne .L080ECFE4
	strb r4, [r2, #3]
	ldrb r0, [r2, #4]
	subs r1, r0, #1
	strb r1, [r2, #4]
	lsls r0, r1, #0x18
	cmp r0, #0
	ble .L080ECFD8
	strb r1, [r2, #2]
	b .L080ECFE8
.L080ECFD8:
	strh r5, [r3, #0x1c]
	strb r4, [r2]
	strb r4, [r2, #1]
	strb r4, [r2, #2]
	strb r4, [r2, #4]
	b .L080ECFE8
.L080ECFE4:
	adds r0, #1
	strb r0, [r2, #3]
.L080ECFE8:
	ldrb r0, [r2]
	movs r1, #1
	ldrsb r1, [r2, r1]
	ldrb r2, [r2, #2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	bl sub_080E845C
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
