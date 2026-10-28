	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080B447C
sub_080B447C: @ 0x080B447C
.L080B447C:
	push {r4, lr}
	ldr r0, .L080B4498
	ldrh r4, [r0, #2]
	bl sub_080C2BF0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B448E
	movs r4, #0
.L080B448E:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B4498: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B449C
sub_080B449C: @ 0x080B449C
.L080B449C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r2
	adds r6, r3, #0
	lsls r0, r0, #0x13
	lsrs r0, r0, #0x10
	mov sl, r0
	lsls r1, r1, #0x13
	lsrs r1, r1, #0x10
	mov sb, r1
	bl sub_080C2BF0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B44E4
	ldr r1, .L080B44D4
	ldrh r0, [r1, #0x1c]
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	cmp r0, #0xb
	bhi .L080B44D8
	ldrh r0, [r1, #0x1a]
	lsrs r5, r0, #1
	lsrs r4, r2, #0x11
	b .L080B4554
.L080B44D4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B44D8:
	ldrh r0, [r1, #0x1a]
	lsrs r5, r0, #1
	ldrh r4, [r1, #0x14]
	movs r2, #0x14
	ldrsh r0, [r1, r2]
	b .L080B453C
.L080B44E4:
	bl sub_080B447C
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L080B44F6
	ldr r7, .L080B450C
	cmp r2, #2
	bne .L080B4510
.L080B44F6:
	ldr r0, .L080B450C
	ldrh r1, [r0, #0x1c]
	lsls r3, r1, #0x10
	lsrs r1, r3, #0x10
	adds r7, r0, #0
	cmp r1, #0xb
	bhi .L080B4510
	ldrh r0, [r7, #0x1a]
	lsrs r5, r0, #1
	lsrs r4, r3, #0x11
	b .L080B4554
.L080B450C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B4510:
	ldrh r0, [r7, #0x1a]
	lsls r3, r0, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0xb
	bhi .L080B452A
	ldrh r0, [r7, #0x1c]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0xb
	bhi .L080B452A
	lsrs r5, r3, #0x11
	lsrs r4, r1, #0x11
	b .L080B4554
.L080B452A:
	cmp r2, #0
	beq .L080B4532
	cmp r2, #2
	bne .L080B4544
.L080B4532:
	ldrh r0, [r7, #0x1a]
	lsrs r5, r0, #1
	ldrh r4, [r7, #0x14]
	movs r1, #0x14
	ldrsh r0, [r7, r1]
.L080B453C:
	cmp r0, #0
	bge .L080B4554
	movs r4, #0
	b .L080B4554
.L080B4544:
	ldrh r0, [r7, #0x1c]
	lsrs r4, r0, #1
	ldrh r5, [r7, #0x12]
	movs r2, #0x12
	ldrsh r0, [r7, r2]
	cmp r0, #0
	bge .L080B4554
	movs r5, #0
.L080B4554:
	bl sub_080B447C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080B4592
	cmp r0, #1
	bgt .L080B456A
	cmp r0, #0
	beq .L080B4574
	b .L080B45FC
.L080B456A:
	cmp r0, #2
	beq .L080B45B0
	cmp r0, #3
	beq .L080B45D0
	b .L080B45FC
.L080B4574:
	movs r0, #0xd
	subs r0, r0, r5
	lsls r0, r0, #3
	mov r1, r8
	strh r0, [r1]
	movs r0, #5
	subs r0, r0, r4
	lsls r0, r0, #3
	strh r0, [r6]
	ldrh r0, [r1]
	add r0, sl
	strh r0, [r1]
	ldrh r1, [r6]
	add r1, sb
	b .L080B45EE
.L080B4592:
	movs r0, #0xd
	subs r0, r0, r4
	lsls r0, r0, #3
	mov r1, r8
	strh r0, [r1]
	adds r0, r5, #5
	lsls r0, r0, #3
	strh r0, [r6]
	ldrh r0, [r1]
	add r0, sb
	strh r0, [r1]
	ldrh r1, [r6]
	mov r2, sl
	subs r1, r1, r2
	b .L080B45EE
.L080B45B0:
	adds r0, r5, #0
	adds r0, #0xd
	lsls r0, r0, #3
	mov r1, r8
	strh r0, [r1]
	adds r0, r4, #5
	lsls r0, r0, #3
	strh r0, [r6]
	ldrh r0, [r1]
	mov r2, sl
	subs r0, r0, r2
	strh r0, [r1]
	ldrh r1, [r6]
	mov r0, sb
	subs r1, r1, r0
	b .L080B45EE
.L080B45D0:
	adds r0, r4, #0
	adds r0, #0xd
	lsls r0, r0, #3
	mov r1, r8
	strh r0, [r1]
	movs r0, #5
	subs r0, r0, r5
	lsls r0, r0, #3
	strh r0, [r6]
	ldrh r0, [r1]
	mov r2, sb
	subs r0, r0, r2
	strh r0, [r1]
	ldrh r1, [r6]
	add r1, sl
.L080B45EE:
	strh r1, [r6]
	ldr r0, .L080B460C
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	adds r1, r1, r0
	strh r1, [r6]
.L080B45FC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B460C: .4byte 0x0200DFCE @ EWRAM+0xDFCE

	thumb_func_start sub_080B4610
sub_080B4610: @ 0x080B4610
.L080B4610:
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r2, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	bl Automap_IsVisitedUnchecked
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B4664
	mov r4, sp
	adds r4, #0xe
	adds r0, r6, #0
	adds r1, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl sub_080B449C
	ldrh r0, [r4]
	cmp r0, #0x57
	bhi .L080B4664
	movs r0, #0x90
	lsls r0, r0, #2
	str r0, [sp]
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r4]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #2
	movs r2, #0
	movs r3, #2
	bl Sprite_Draw
.L080B4664:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080B466C
sub_080B466C: @ 0x080B466C
.L080B466C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r0, .L080B46DC
	ldr r0, [r0]
	cmp r0, #1
	bne .L080B467E
	b .L080B47A4
.L080B467E:
	movs r4, #0
	ldr r5, .L080B46E0
.L080B4682:
	lsls r1, r4, #3
	ldr r0, .L080B46E4
	adds r2, r1, r0
	ldrh r1, [r2, #4]
	ldr r0, .L080B46E8
	ldr r0, [r0]
	cmp r1, r0
	bne .L080B46AC
	ldrh r0, [r2, #6]
	ldr r1, .L080B46EC
	ldr r1, [r1]
	cmp r0, r1
	bne .L080B46AC
	ldrb r0, [r2]
	ldrb r1, [r2, #1]
	ldrb r2, [r2, #3]
	lsls r2, r2, #2
	adds r2, r2, r5
	ldr r2, [r2]
	bl sub_080B4610
.L080B46AC:
	adds r4, #1
	cmp r4, #7
	bls .L080B4682
	ldr r0, .L080B46DC
	ldr r0, [r0]
	cmp r0, #2
	beq .L080B4706
	bl sub_080C2BF0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B46F8
	ldr r2, .L080B46F0
	ldrh r0, [r2, #0x12]
	ldrh r1, [r2, #0x14]
	ldr r3, .L080B46F4
	ldrh r2, [r2, #2]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_080B4610
	b .L080B4706
	.byte 0x00, 0x00
.L080B46DC: .4byte 0x03003FFC @ IWRAM+0x3FFC
.L080B46E0: .4byte gUnknown_081629E4
.L080B46E4: .4byte 0x03005808 @ IWRAM+0x5808
.L080B46E8: .4byte 0x03004614 @ IWRAM+0x4614
.L080B46EC: .4byte 0x03004514 @ IWRAM+0x4514
.L080B46F0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B46F4: .4byte gUnknown_081629F8
.L080B46F8:
	ldr r1, .L080B47B0
	ldrh r0, [r1, #0x12]
	ldrh r1, [r1, #0x14]
	ldr r2, .L080B47B4
	ldr r2, [r2]
	bl sub_080B4610
.L080B4706:
	ldr r0, .L080B47B8
	mov r8, r0
	movs r5, #0
	ldr r0, .L080B47B0
	adds r3, r0, #0
	ldrh r1, [r0, #0x1c]
	cmp r5, r1
	bhs .L080B475E
.L080B4716:
	movs r4, #0
	adds r6, r5, #1
	ldrh r0, [r0, #0x1a]
	cmp r4, r0
	bhs .L080B4752
	ldr r7, .L080B47BC
	ldr r3, .L080B47B0
.L080B4724:
	lsls r0, r5, #5
	adds r0, r0, r4
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	cmp r2, #0
	beq .L080B4744
	adds r0, r4, #0
	adds r1, r5, #0
	str r3, [sp, #4]
	bl sub_080B4610
	ldr r3, [sp, #4]
.L080B4744:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L080B47B0
	ldrh r0, [r0, #0x1a]
	cmp r4, r0
	blo .L080B4724
.L080B4752:
	lsls r0, r6, #0x10
	lsrs r5, r0, #0x10
	adds r0, r3, #0
	ldrh r1, [r3, #0x1c]
	cmp r5, r1
	blo .L080B4716
.L080B475E:
	ldrh r0, [r3, #0x1e]
	cmp r0, #0x36
	beq .L080B4774
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x12
	movs r3, #0x59
	bl MarkerHeader_DrawLocationName
.L080B4774:
	ldr r0, .L080B47C0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B47A4
	ldr r0, .L080B47C4
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B4790
	movs r0, #2
	movs r1, #2
	movs r2, #0xc8
	movs r3, #0x30
	bl sub_080C4A4C
.L080B4790:
	ldr r0, .L080B47C8
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B47A4
	movs r0, #2
	movs r1, #2
	movs r2, #0xc8
	movs r3, #0x48
	bl sub_080C4AB0
.L080B47A4:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B47B0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B47B4: .4byte gUnknown_081629F8
.L080B47B8: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B47BC: .4byte gUnknown_08162A08
.L080B47C0: .4byte 0x0200DFD2 @ EWRAM+0xDFD2
.L080B47C4: .4byte 0x0200DFCA @ EWRAM+0xDFCA
.L080B47C8: .4byte 0x0200DFC8 @ EWRAM+0xDFC8

	thumb_func_start sub_080B47CC
sub_080B47CC: @ 0x080B47CC
.L080B47CC:
	push {r4, lr}
	bl sub_080B447C
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl sub_080C2BF0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B47F4
	ldr r2, .L080B47F0
	ldrh r0, [r2, #0x1c]
	cmp r0, #0xb
	bls .L080B4820
	ldrh r0, [r2, #0x1a]
	lsrs r1, r0, #1
	ldrh r2, [r2, #0x14]
	b .L080B4828
.L080B47F0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B47F4:
	cmp r4, #0
	beq .L080B47FE
	ldr r2, .L080B4810
	cmp r4, #2
	bne .L080B4814
.L080B47FE:
	ldr r0, .L080B4810
	ldrh r1, [r0, #0x1c]
	adds r2, r0, #0
	cmp r1, #0xb
	bhi .L080B4814
	ldrh r1, [r2, #0x1a]
	lsrs r1, r1, #1
	ldrh r2, [r2, #0x1c]
	b .L080B4826
.L080B4810: .4byte 0x03004550 @ IWRAM+0x4550
.L080B4814:
	ldrh r0, [r2, #0x1a]
	cmp r0, #0xb
	bhi .L080B4830
	ldrh r0, [r2, #0x1c]
	cmp r0, #0xb
	bhi .L080B4830
.L080B4820:
	ldrh r1, [r2, #0x1a]
	lsrs r1, r1, #1
	adds r2, r0, #0
.L080B4826:
	lsrs r2, r2, #1
.L080B4828:
	adds r0, r4, #0
	bl Automap_Build
	b .L080B484C
.L080B4830:
	cmp r4, #0
	beq .L080B4838
	cmp r4, #2
	bne .L080B4840
.L080B4838:
	ldrh r0, [r2, #0x1a]
	lsrs r1, r0, #1
	ldrh r2, [r2, #0x14]
	b .L080B4846
.L080B4840:
	ldrh r1, [r2, #0x12]
	ldrh r0, [r2, #0x1c]
	lsrs r2, r0, #1
.L080B4846:
	adds r0, r4, #0
	bl Automap_Build
.L080B484C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B4854
sub_080B4854: @ 0x080B4854
.L080B4854:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, .L080B4874
	mov sb, r0
	movs r0, #0
	str r0, [sp]
	ldr r2, .L080B4878
	mov r0, sp
	mov r1, sb
	bl CpuSet
	movs r7, #0
	b .L080B4A36
.L080B4874: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B4878: .4byte 0x05000C00
.L080B487C:
	movs r6, #0
	adds r1, r7, #1
	mov r8, r1
	b .L080B4A28
.L080B4884:
	adds r0, r6, #0
	adds r1, r7, #0
	bl FieldMap_CellRecordsAt
	adds r4, r0, #0
	lsls r0, r7, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	mov r1, sb
	adds r5, r1, r0
	adds r0, r4, #0
	movs r1, #0x23
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B48AA
	ldrh r0, [r0, #2]
	adds r0, #1
	b .L080B4A1E
.L080B48AA:
	adds r0, r4, #0
	movs r1, #4
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B48BA
	movs r0, #0xf
	b .L080B4A1E
.L080B48BA:
	adds r0, r4, #0
	movs r1, #1
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B48D2
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne .L080B48CE
	b .L080B4A20
.L080B48CE:
	movs r0, #8
	b .L080B4A1E
.L080B48D2:
	adds r0, r4, #0
	movs r1, #2
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B48EA
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne .L080B48E6
	b .L080B4A20
.L080B48E6:
	movs r0, #9
	b .L080B4A1E
.L080B48EA:
	adds r0, r4, #0
	movs r1, #0x1b
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B4902
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne .L080B48FE
	b .L080B4A20
.L080B48FE:
	movs r0, #8
	b .L080B4A1E
.L080B4902:
	adds r0, r4, #0
	movs r1, #0x1c
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B491A
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne .L080B4916
	b .L080B4A20
.L080B4916:
	movs r0, #9
	b .L080B4A1E
.L080B491A:
	adds r0, r4, #0
	movs r1, #0x10
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B492A
	movs r0, #0xb
	b .L080B4A1E
.L080B492A:
	adds r0, r4, #0
	movs r1, #3
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B493A
	movs r0, #0xa
	b .L080B4A1E
.L080B493A:
	adds r0, r4, #0
	movs r1, #0x22
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B494A
	movs r0, #0x11
	b .L080B4A1E
.L080B494A:
	adds r0, r4, #0
	movs r1, #0xb
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B497C
	adds r0, r4, #0
	movs r1, #0xb
	bl FieldMap_FindRecord
	ldrh r0, [r0, #8]
	cmp r0, #7
	bne .L080B4968
	movs r0, #0x14
	b .L080B4A1E
.L080B4968:
	cmp r0, #9
	bne .L080B4970
	movs r0, #0x16
	b .L080B4A1E
.L080B4970:
	cmp r0, #0xa
	bne .L080B4978
	movs r0, #0x21
	b .L080B4A1E
.L080B4978:
	movs r0, #0x11
	b .L080B4A1E
.L080B497C:
	adds r0, r4, #0
	movs r1, #0xc
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B498C
	movs r0, #7
	b .L080B4A1E
.L080B498C:
	adds r0, r4, #0
	movs r1, #0xd
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B49C0
	ldr r0, .L080B49B8
	ldr r0, [r0]
	cmp r0, #0x1a
	bne .L080B49B2
	ldr r0, .L080B49BC
	ldr r0, [r0]
	cmp r0, #1
	bne .L080B49B2
	movs r0, #0x15
	bl Flag_Test
	cmp r0, #0
	beq .L080B4A20
.L080B49B2:
	movs r0, #0xc
	b .L080B4A1E
	.byte 0x00, 0x00
.L080B49B8: .4byte 0x03004614 @ IWRAM+0x4614
.L080B49BC: .4byte 0x03004514 @ IWRAM+0x4514
.L080B49C0:
	adds r0, r4, #0
	movs r1, #0xe
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B49D0
	movs r0, #0xd
	b .L080B4A1E
.L080B49D0:
	adds r0, r4, #0
	movs r1, #0xf
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B49E0
	movs r0, #0xe
	b .L080B4A1E
.L080B49E0:
	adds r0, r4, #0
	movs r1, #0x11
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B49F0
	movs r0, #0x14
	b .L080B4A1E
.L080B49F0:
	adds r0, r4, #0
	movs r1, #0x25
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B4A00
	movs r0, #0x22
	b .L080B4A1E
.L080B4A00:
	adds r0, r4, #0
	movs r1, #0x26
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B4A10
	movs r0, #0x23
	b .L080B4A1E
.L080B4A10:
	adds r0, r4, #0
	movs r1, #0x27
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B4A20
	movs r0, #0x24
.L080B4A1E:
	strh r0, [r5]
.L080B4A20:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L080B4A50
.L080B4A28:
	ldrh r0, [r0, #0x1a]
	cmp r6, r0
	bhs .L080B4A30
	b .L080B4884
.L080B4A30:
	mov r1, r8
	lsls r0, r1, #0x10
	lsrs r7, r0, #0x10
.L080B4A36:
	ldr r0, .L080B4A50
	ldrh r1, [r0, #0x1c]
	cmp r7, r1
	bhs .L080B4A40
	b .L080B487C
.L080B4A40:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B4A50: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B4A54
sub_080B4A54: @ 0x080B4A54
.L080B4A54:
	push {r4, r5, r6, lr}
	movs r5, #0x1c
	movs r6, #0xb
	movs r2, #0
.L080B4A5C:
	movs r1, #0
	cmp r1, r5
	bhs .L080B4A92
	ldr r4, .L080B4A84
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r3, r0, #4
.L080B4A6E:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B4A88
	movs r0, #1
	b .L080B4A9E
	.byte 0x00, 0x00
.L080B4A84: .4byte 0x02005000 @ EWRAM+0x5000
.L080B4A88:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r5
	blo .L080B4A6E
.L080B4A92:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r6
	blo .L080B4A5C
	movs r0, #0
.L080B4A9E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_080B4AA4
sub_080B4AA4: @ 0x080B4AA4
.L080B4AA4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0x1c
	mov sl, r0
	bl sub_080B447C
	movs r1, #0
.L080B4ABA:
	movs r6, #0
	adds r2, r1, #1
	mov sb, r2
	cmp r6, sl
	bhs .L080B4B2E
	ldr r3, .L080B4B10
	lsls r0, r1, #6
	ldr r4, .L080B4B14
	adds r4, r4, r0
	mov r8, r4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r7, r0, #4
.L080B4AD8:
	lsls r1, r6, #1
	adds r0, r1, r6
	lsls r2, r0, #2
	adds r0, r2, r7
	adds r4, r0, r3
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080B4B24
	adds r0, r1, #2
	mov r1, r8
	adds r5, r1, r0
	adds r0, r2, r3
	adds r0, r7, r0
	str r3, [sp]
	bl sub_080B4448
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r4]
	movs r4, #0x80
	lsls r4, r4, #8
	adds r1, r4, #0
	ands r0, r1
	ldr r3, [sp]
	cmp r0, #0
	bne .L080B4B18
	strh r2, [r5]
	b .L080B4B24
.L080B4B10: .4byte 0x02005000 @ EWRAM+0x5000
.L080B4B14: .4byte 0x02000000 @ EWRAM
.L080B4B18:
	movs r0, #0xc0
	lsls r0, r0, #7
	adds r1, r0, #0
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r5]
.L080B4B24:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, sl
	blo .L080B4AD8
.L080B4B2E:
	mov r1, sb
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	blo .L080B4ABA
	bl sub_080B4854
	ldr r0, .L080B4B54
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B4B54: .4byte sub_080B5084

	thumb_func_start sub_080B4B58
sub_080B4B58: @ 0x080B4B58
	ldr r1, .L080B4B6C
	ldr r0, .L080B4B70
	str r0, [r1]
	ldr r0, .L080B4B74
	str r0, [r1, #4]
	ldr r0, .L080B4B78
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B4B6C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B4B70: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B4B74: .4byte 0x06014800 @ VRAM+0x14800
.L080B4B78: .4byte 0x84000400

	thumb_func_start sub_080B4B7C
sub_080B4B7C: @ 0x080B4B7C
	ldr r1, .L080B4B90
	ldr r0, .L080B4B94
	str r0, [r1]
	ldr r0, .L080B4B98
	str r0, [r1, #4]
	ldr r0, .L080B4B9C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B4B90: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B4B94: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B4B98: .4byte 0x06015800 @ VRAM+0x15800
.L080B4B9C: .4byte 0x84000400

	thumb_func_start sub_080B4BA0
sub_080B4BA0: @ 0x080B4BA0
	ldr r1, .L080B4BB4
	ldr r0, .L080B4BB8
	str r0, [r1]
	ldr r0, .L080B4BBC
	str r0, [r1, #4]
	ldr r0, .L080B4BC0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B4BB4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B4BB8: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B4BBC: .4byte 0x06016800 @ VRAM+0x16800
.L080B4BC0: .4byte 0x84000400

	thumb_func_start sub_080B4BC4
sub_080B4BC4: @ 0x080B4BC4
	ldr r1, .L080B4BD8
	ldr r0, .L080B4BDC
	str r0, [r1]
	ldr r0, .L080B4BE0
	str r0, [r1, #4]
	ldr r0, .L080B4BE4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B4BD8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B4BDC: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B4BE0: .4byte 0x06017800 @ VRAM+0x17800
.L080B4BE4: .4byte 0x84000200

	thumb_func_start sub_080B4BE8
sub_080B4BE8: @ 0x080B4BE8
	push {r4, lr}
	adds r0, r1, #0
	adds r4, r2, #0
	ldr r1, .L080B4C08
	bl LZ77UnCompWram
	cmp r4, #1
	beq .L080B4C14
	cmp r4, #1
	blo .L080B4C0C
	cmp r4, #2
	beq .L080B4C1C
	cmp r4, #3
	beq .L080B4C2C
	b .L080B4C3A
	.byte 0x00, 0x00
.L080B4C08: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B4C0C:
	ldr r0, .L080B4C10
	b .L080B4C1E
.L080B4C10: .4byte sub_080B4B58
.L080B4C14:
	ldr r0, .L080B4C18
	b .L080B4C1E
.L080B4C18: .4byte sub_080B4B7C
.L080B4C1C:
	ldr r0, .L080B4C28
.L080B4C1E:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B4C3A
	.byte 0x00, 0x00
.L080B4C28: .4byte sub_080B4BA0
.L080B4C2C:
	ldr r0, .L080B4C40
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080B4C44
	movs r0, #0
	str r0, [r1]
.L080B4C3A:
	pop {r4}
	pop {r0}
	bx r0
.L080B4C40: .4byte sub_080B4BC4
.L080B4C44: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080B4C48
sub_080B4C48: @ 0x080B4C48
.L080B4C48:
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r6, .L080B4C68
	ldrh r5, [r6, #0x1e]
	cmp r5, #0x33
	bne .L080B4C56
	b .L080B4D4C
.L080B4C56:
	cmp r5, #0x33
	bgt .L080B4C76
	cmp r5, #0xf
	beq .L080B4D08
	cmp r5, #0xf
	bgt .L080B4C6C
	cmp r5, #0
	beq .L080B4C9C
	b .L080B5070
.L080B4C68: .4byte 0x03004550 @ IWRAM+0x4550
.L080B4C6C:
	cmp r5, #0x10
	beq .L080B4D28
	cmp r5, #0x32
	beq .L080B4D3C
	b .L080B5070
.L080B4C76:
	cmp r5, #0x36
	bne .L080B4C7C
	b .L080B5030
.L080B4C7C:
	cmp r5, #0x36
	bgt .L080B4C8E
	cmp r5, #0x34
	bne .L080B4C86
	b .L080B4D7C
.L080B4C86:
	cmp r5, #0x35
	bne .L080B4C8C
	b .L080B4EFC
.L080B4C8C:
	b .L080B5070
.L080B4C8E:
	cmp r5, #0x37
	bne .L080B4C94
	b .L080B5004
.L080B4C94:
	cmp r5, #0xc8
	bne .L080B4C9A
	b .L080B5048
.L080B4C9A:
	b .L080B5070
.L080B4C9C:
	bl sub_080C14FC
	movs r0, #0xa
	strh r0, [r6, #0x1e]
	ldr r6, .L080B4D00
	ldrh r0, [r6]
	cmp r0, #0
	beq .L080B4CAE
	strh r5, [r6]
.L080B4CAE:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r3, #0x40
	bl Palette_FillWithEffect
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r2, r6, r1
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r3, #0x20
	bl Palette_FillWithEffect
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r3, #0x20
	bl Palette_FillWithEffect
	bl Palette_MarkDirty
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L080B4D04
	str r5, [r0]
	bl sub_080C7C60
	b .L080B5078
	.byte 0x00, 0x00
.L080B4D00: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080B4D04: .4byte 0x03003FFC @ IWRAM+0x3FFC
.L080B4D08:
	ldr r0, .L080B4D1C
	ldr r1, .L080B4D20
	bl Task_Create
	ldr r1, .L080B4D24
	str r0, [r1]
	movs r0, #0x10
	strh r0, [r6, #0x1e]
	b .L080B5078
	.byte 0x00, 0x00
.L080B4D1C: .4byte gUnknown_08162AB0
.L080B4D20: .4byte 0x0000FFFF
.L080B4D24: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080B4D28:
	ldr r0, .L080B4D38
	ldr r0, [r0]
	cmp r0, #0
	beq .L080B4D32
	b .L080B5078
.L080B4D32:
	movs r0, #0x12
	strh r0, [r6, #0x1e]
	b .L080B5078
.L080B4D38: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080B4D3C:
	bl sub_080C14FC
	ldrh r0, [r6, #0x1e]
	adds r0, #1
	strh r0, [r6, #0x1e]
	bl sub_080B47CC
	b .L080B5078
.L080B4D4C:
	ldr r0, .L080B4D74
	ldrh r4, [r0, #0xc]
	cmp r4, #0
	beq .L080B4D56
	b .L080B5078
.L080B4D56:
	bl sub_080B4AA4
	ldrh r0, [r6, #0x1e]
	adds r0, #1
	strh r0, [r6, #0x1e]
	str r4, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #2
	bl Window_Create
	ldr r1, .L080B4D78
	str r0, [r1]
	b .L080B5078
.L080B4D74: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080B4D78: .4byte 0x030045F8 @ IWRAM+0x45F8
.L080B4D7C:
	ldr r7, .L080B4E10
	ldr r0, [r7]
	bl Window_IsIdle
	cmp r0, #0
	bne .L080B4D8A
	b .L080B5078
.L080B4D8A:
	ldrh r1, [r6, #0x3a]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L080B4DA0
	ldrh r1, [r6, #0x3a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080B4E18
.L080B4DA0:
	bl sub_080C14FC
	movs r0, #0x64
	strh r0, [r6, #0x1e]
	ldr r5, .L080B4E14
	ldrh r0, [r5]
	cmp r0, #0
	beq .L080B4DB4
	movs r0, #0
	strh r0, [r5]
.L080B4DB4:
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r3, #0x40
	bl Palette_FillWithEffect
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r5, r0
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r3, #0x20
	bl Palette_FillWithEffect
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r2, r5, r1
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r3, #0x20
	bl Palette_FillWithEffect
	bl Palette_MarkDirty
	bl sub_080C7848
	ldr r0, [r7]
	movs r1, #1
	bl Window_Close
	ldrh r0, [r6, #0x32]
	cmp r0, #0
	bne .L080B4E08
	bl sub_080C7C94
.L080B4E08:
	movs r0, #0x66
	bl sub_080C51D4
	b .L080B5078
.L080B4E10: .4byte 0x030045F8 @ IWRAM+0x45F8
.L080B4E14: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080B4E18:
	ldrh r1, [r6, #0x3c]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080B4E58
	ldr r0, .L080B4E50
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B4E58
	ldr r4, .L080B4E54
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge .L080B4E3E
	bl sub_080B4A54
	cmp r0, #1
	beq .L080B4E3E
	b .L080B5030
.L080B4E3E:
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	movs r0, #0x37
	strh r0, [r6, #0x1e]
	bl sub_080B47CC
	b .L080B5030
	.byte 0x00, 0x00
.L080B4E50: .4byte 0x0200DFC8 @ EWRAM+0xDFC8
.L080B4E54: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080B4E58:
	ldr r2, .L080B4E94
	ldrh r1, [r2, #0x3c]
	movs r0, #0x40
	ands r0, r1
	adds r5, r2, #0
	cmp r0, #0
	beq .L080B4EA0
	ldr r0, .L080B4E98
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B4EA0
	ldr r4, .L080B4E9C
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble .L080B4E82
	bl sub_080B4A54
	cmp r0, #1
	beq .L080B4E82
	b .L080B5030
.L080B4E82:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r0, #0x37
	strh r0, [r5, #0x1e]
	bl sub_080B47CC
	b .L080B5030
	.byte 0x00, 0x00
.L080B4E94: .4byte 0x03004550 @ IWRAM+0x4550
.L080B4E98: .4byte 0x0200DFCA @ EWRAM+0xDFCA
.L080B4E9C: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080B4EA0:
	adds r4, r5, #0
	ldrh r1, [r4, #0x3a]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L080B4ED0
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #2
	movs r2, #0x1a
	movs r3, #8
	bl Window_CreateOpen
	ldr r1, .L080B4ECC
	str r0, [r1]
	movs r0, #0x35
	strh r0, [r4, #0x1e]
	movs r0, #0x65
	bl sub_080C51D4
	b .L080B5030
.L080B4ECC: .4byte 0x03003FF0 @ IWRAM+0x3FF0
.L080B4ED0:
	ldrh r1, [r5, #0x3a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L080B4EDC
	b .L080B5030
.L080B4EDC:
	bl sub_080B5D00
	movs r0, #0x36
	strh r0, [r5, #0x1e]
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x12
	movs r3, #0x59
	bl MarkerHeader_DrawLocationName
	movs r0, #0x65
	bl sub_080C51D4
	b .L080B5030
.L080B4EFC:
	ldr r4, .L080B4F30
	ldr r0, [r4]
	bl Window_IsIdle
	adds r2, r0, #0
	cmp r2, #1
	beq .L080B4F0C
	b .L080B5030
.L080B4F0C:
	ldrh r1, [r6, #0x3a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080B4F38
	ldr r0, [r4]
	movs r1, #1
	bl Window_Close
	movs r1, #0
	movs r0, #0x34
	strh r0, [r6, #0x1e]
	ldr r0, .L080B4F34
	strh r1, [r0]
	movs r0, #0x66
	bl sub_080C51D4
	b .L080B4F76
.L080B4F30: .4byte 0x03003FF0 @ IWRAM+0x3FF0
.L080B4F34: .4byte 0x0200DFD0 @ EWRAM+0xDFD0
.L080B4F38:
	ldr r3, .L080B4F54
	ldrh r0, [r3]
	cmp r0, #0
	bne .L080B4F58
	ldrh r1, [r6, #0x3a]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080B4F58
	strh r2, [r3]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080B4F76
.L080B4F54: .4byte 0x0200DFD0 @ EWRAM+0xDFD0
.L080B4F58:
	ldr r2, .L080B4FB4
	ldrh r0, [r2]
	cmp r0, #1
	bne .L080B4F76
	ldr r0, .L080B4FB8
	ldrh r1, [r0, #0x3a]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080B4F76
	movs r0, #0
	strh r0, [r2]
	movs r0, #0x64
	bl sub_080C51D4
.L080B4F76:
	ldr r0, .L080B4FB4
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B4FC4
	ldr r0, .L080B4FBC
	movs r1, #0x90
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0x5c
	str r1, [sp, #4]
	movs r1, #0x18
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080B4FC0
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080B5030
	movs r0, #0
	movs r1, #0
	movs r2, #0xd6
	movs r3, #0x48
	bl sub_080C4AB0
	b .L080B5030
.L080B4FB4: .4byte 0x0200DFD0 @ EWRAM+0xDFD0
.L080B4FB8: .4byte 0x03004550 @ IWRAM+0x4550
.L080B4FBC: .4byte gUnknown_08000410
.L080B4FC0: .4byte 0x030031BC @ IWRAM+0x31BC
.L080B4FC4:
	ldr r0, .L080B4FFC
	movs r1, #0x90
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0x5c
	str r1, [sp, #4]
	movs r1, #0x18
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080B5000
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080B5030
	movs r0, #0
	movs r1, #0
	movs r2, #0xd6
	movs r3, #0x14
	bl sub_080C4A4C
	b .L080B5030
	.byte 0x00, 0x00
.L080B4FFC: .4byte gUnknown_08000470
.L080B5000: .4byte 0x030031BC @ IWRAM+0x31BC
.L080B5004:
	ldr r0, .L080B5038
	ldr r1, .L080B503C
	movs r2, #1
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r2, #0x1c
	str r2, [sp, #8]
	movs r2, #0xd
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	bl sub_080B4AA4
	movs r0, #0x34
	strh r0, [r6, #0x1e]
	ldr r1, .L080B5040
	ldr r0, .L080B5044
	ldrh r0, [r0]
	strh r0, [r1]
.L080B5030:
	bl sub_080B466C
	b .L080B5078
	.byte 0x00, 0x00
.L080B5038: .4byte gUnknown_081B8D70
.L080B503C: .4byte 0x02000000 @ EWRAM
.L080B5040: .4byte 0x0200DFCE @ EWRAM+0xDFCE
.L080B5044: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080B5048:
	adds r1, r6, #0
	adds r1, #0x50
	ldrh r0, [r1]
	cmp r0, #2
	bne .L080B5056
	movs r0, #1
	strh r0, [r1]
.L080B5056:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	movs r0, #0xc
	strh r0, [r6, #0x1e]
	ldrh r0, [r6, #2]
	strh r0, [r6, #6]
	movs r0, #0x11
	bl Field_SetState
	b .L080B5078
.L080B5070:
	ldr r0, .L080B5080
	movs r1, #1
	bl VBlankTask_AddCounted
.L080B5078:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B5080: .4byte sub_080B50C0

	thumb_func_start sub_080B5084
sub_080B5084: @ 0x080B5084
	push {lr}
	bl sub_080C153C
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B5090
sub_080B5090: @ 0x080B5090
.L080B5090:
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080B50B4
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080B50B8
	str r0, [r1, #4]
	ldr r0, .L080B50BC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080B2880
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B50B4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B50B8: .4byte 0x02005004 @ EWRAM+0x5004
.L080B50BC: .4byte 0x85001000

	thumb_func_start sub_080B50C0
sub_080B50C0: @ 0x080B50C0
	push {r4, lr}
	sub sp, #0x10
	ldr r4, .L080B50E0
	ldrh r3, [r4, #0x1e]
	cmp r3, #0xe
	beq .L080B5168
	cmp r3, #0xe
	bgt .L080B50EE
	cmp r3, #0xb
	beq .L080B5106
	cmp r3, #0xb
	bgt .L080B50E4
	cmp r3, #0xa
	beq .L080B51B0
	b .L080B51DC
	.byte 0x00, 0x00
.L080B50E0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B50E4:
	cmp r3, #0xc
	beq .L080B511C
	cmp r3, #0xd
	beq .L080B5122
	b .L080B51DC
.L080B50EE:
	cmp r3, #0x32
	beq .L080B51B0
	cmp r3, #0x32
	bgt .L080B50FC
	cmp r3, #0x12
	beq .L080B518C
	b .L080B51DC
.L080B50FC:
	cmp r3, #0x64
	beq .L080B5196
	cmp r3, #0x65
	beq .L080B51C2
	b .L080B51DC
.L080B5106:
	ldr r0, .L080B5114
	ldr r2, .L080B5118
	adds r1, r2, #0
	strh r1, [r0]
	movs r0, #0x22
	strh r0, [r4, #0x2e]
	b .L080B51DC
.L080B5114: .4byte 0x0400000E @ REG_BG3CNT
.L080B5118: .4byte 0x0000860B
.L080B511C:
	bl sub_080B5090
	b .L080B51DC
.L080B5122:
	ldr r1, .L080B5150
	ldr r0, .L080B5154
	str r0, [r1]
	ldr r0, .L080B5158
	str r0, [r1, #4]
	ldr r0, .L080B515C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080B5160
	ldr r1, .L080B5164
	movs r2, #1
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r2, #0x1c
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	b .L080B51DC
	.byte 0x00, 0x00
.L080B5150: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B5154: .4byte gUnknown_081A91B8
.L080B5158: .4byte 0x0600BC00 @ VRAM+0xBC00
.L080B515C: .4byte 0x84001100
.L080B5160: .4byte gUnknown_081B8D70
.L080B5164: .4byte 0x02000000 @ EWRAM
.L080B5168:
	ldr r1, .L080B517C
	ldr r0, .L080B5180
	str r0, [r1]
	ldr r0, .L080B5184
	str r0, [r1, #4]
	ldr r0, .L080B5188
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b .L080B51DC
	.byte 0x00, 0x00
.L080B517C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B5180: .4byte 0x02000000 @ EWRAM
.L080B5184: .4byte 0x06003000 @ VRAM+0x3000
.L080B5188: .4byte 0x84000400
.L080B518C:
	movs r0, #0x32
	strh r0, [r4, #0x1e]
	bl sub_080C7864
	b .L080B51E4
.L080B5196:
	ldr r0, .L080B51B8
	ldrh r0, [r0, #0xc]
	cmp r0, #3
	bne .L080B51BC
	ldrh r0, [r4, #0x32]
	cmp r0, #0
	bne .L080B51B0
	bl sub_080C7234
	bl sub_080C700C
	bl sub_080C7430
.L080B51B0:
	bl sub_080C153C
	b .L080B51DC
	.byte 0x00, 0x00
.L080B51B8: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080B51BC:
	movs r0, #0x63
	strh r0, [r4, #0x1e]
	b .L080B51DC
.L080B51C2:
	ldr r0, .L080B51D4
	ldr r2, .L080B51D8
	adds r1, r2, #0
	strh r1, [r0]
	bl sub_080ADF64
	movs r0, #0xc8
	strh r0, [r4, #0x1e]
	b .L080B51E4
.L080B51D4: .4byte 0x0400000E @ REG_BG3CNT
.L080B51D8: .4byte 0x00008607
.L080B51DC:
	ldr r1, .L080B51EC
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	strh r0, [r1, #0x1e]
.L080B51E4:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
.L080B51EC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B51F0
sub_080B51F0: @ 0x080B51F0
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x24
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #0xd
	movs r2, #0x1a
	movs r3, #7
	bl Window_CreateOpen
	str r0, [r4, #0x18]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B5214
sub_080B5214: @ 0x080B5214
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C6E30
	cmp r4, #1
	bne .L080B522E
	movs r0, #0x80
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	b .L080B523E
.L080B522E:
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L080B5244
	movs r1, #1
	bl VBlankTask_AddCounted
.L080B523E:
	pop {r4}
	pop {r0}
	bx r0
.L080B5244: .4byte sub_080C8440

	thumb_func_start sub_080B5248
sub_080B5248: @ 0x080B5248
.L080B5248:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	adds r6, r0, #0
	adds r6, #0x24
	movs r4, #0
	movs r5, #0x80
	lsls r5, r5, #0xc
.L080B525A:
	movs r0, #0x90
	lsls r0, r0, #2
	str r0, [sp]
	lsrs r0, r5, #0x10
	str r0, [sp, #4]
	ldrh r0, [r6, #0x12]
	lsls r0, r0, #0x13
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldr r0, .L080B52BC
	movs r1, #1
	adds r2, r7, #0
	movs r3, #2
	bl Sprite_Draw
	movs r0, #0x80
	lsls r0, r0, #0xe
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #6
	bls .L080B525A
	movs r4, #0
.L080B5286:
	movs r0, #0x90
	lsls r0, r0, #2
	str r0, [sp]
	ldrh r0, [r6, #0x10]
	lsls r0, r0, #0x13
	movs r1, #0x80
	lsls r1, r1, #0xc
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	lsls r0, r4, #0x15
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldr r0, .L080B52C0
	movs r1, #1
	adds r2, r7, #0
	movs r3, #2
	bl Sprite_Draw
	adds r4, #1
	cmp r4, #2
	bls .L080B5286
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B52BC: .4byte gUnknown_08000508
.L080B52C0: .4byte gUnknown_08000518

	thumb_func_start sub_080B52C4
sub_080B52C4: @ 0x080B52C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0x24
	ldr r0, [r6, #0x24]
	cmp r0, #1
	beq .L080B52F6
	cmp r0, #1
	blo .L080B52E4
	cmp r0, #2
	beq .L080B5330
	cmp r0, #3
	bne .L080B52E2
	b .L080B547C
.L080B52E2:
	b .L080B5498
.L080B52E4:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x12
	movs r3, #0x59
	bl MarkerHeader_DrawLocationName
	b .L080B5498
.L080B52F6:
	ldrh r0, [r7, #0x14]
	cmp r0, #0
	bne .L080B5318
	ldr r0, .L080B5314
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	b .L080B546A
	.byte 0x00, 0x00
.L080B5314: .4byte gUnknown_08162B1C
.L080B5318:
	ldr r0, .L080B532C
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	b .L080B5466
	.byte 0x00, 0x00
.L080B532C: .4byte gUnknown_08162B56
.L080B5330:
	ldr r0, .L080B5390
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	ldr r0, .L080B5394
	movs r5, #0x90
	lsls r5, r5, #2
	str r5, [sp]
	movs r4, #0x12
	str r4, [sp, #4]
	movs r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080B5398
	str r5, [sp]
	str r4, [sp, #4]
	ldr r2, [r7, #0xc]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0xc0
	lsls r2, r2, #0xc
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, [r7, #0xc]
	cmp r0, #4
	bhi .L080B546A
	lsls r0, r0, #2
	ldr r1, .L080B539C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080B5390: .4byte gUnknown_08162B34
.L080B5394: .4byte gUnknown_080004AC
.L080B5398: .4byte gUnknown_080004C4
.L080B539C: .4byte gUnknown_080B53A0
	.global gUnknown_080B53A0
gUnknown_080B53A0:
.L080B53A0: @ jump table
	.4byte .L080B53B4
	.4byte .L080B53D4
	.4byte .L080B53F4
	.4byte .L080B5414
	.4byte .L080B5444
.L080B53B4:
	ldr r0, .L080B53CC
	movs r1, #4
	str r1, [sp]
	movs r4, #0xc
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x6c
	bl Text_DrawSpriteString
	ldr r0, .L080B53D0
	b .L080B542A
.L080B53CC: .4byte gUnknown_08162B8E
.L080B53D0: .4byte gUnknown_08162B9C
.L080B53D4:
	ldr r0, .L080B53EC
	movs r1, #4
	str r1, [sp]
	movs r4, #0xc
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x6c
	bl Text_DrawSpriteString
	ldr r0, .L080B53F0
	b .L080B542A
.L080B53EC: .4byte gUnknown_08162BA8
.L080B53F0: .4byte gUnknown_08162BBE
.L080B53F4:
	ldr r0, .L080B540C
	movs r1, #4
	str r1, [sp]
	movs r4, #0xc
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x6c
	bl Text_DrawSpriteString
	ldr r0, .L080B5410
	b .L080B542A
.L080B540C: .4byte gUnknown_08162BD0
.L080B5410: .4byte gUnknown_08162BE4
.L080B5414:
	ldr r0, .L080B543C
	movs r1, #4
	str r1, [sp]
	movs r4, #0xc
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x6c
	bl Text_DrawSpriteString
	ldr r0, .L080B5440
.L080B542A:
	movs r1, #0x10
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x6c
	bl Text_DrawSpriteString
	b .L080B546A
.L080B543C: .4byte gUnknown_08162BF6
.L080B5440: .4byte gUnknown_08162C06
.L080B5444:
	ldr r0, .L080B5474
	movs r1, #4
	str r1, [sp]
	movs r4, #0xc
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x6c
	bl Text_DrawSpriteString
	ldr r0, .L080B5478
	movs r1, #0x10
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x6c
.L080B5466:
	bl Text_DrawSpriteString
.L080B546A:
	adds r0, r6, #0
	movs r1, #0
	bl sub_080B5248
	b .L080B5498
.L080B5474: .4byte gUnknown_08162C12
.L080B5478: .4byte gUnknown_08162C26
.L080B547C:
	ldr r0, .L080B54FC
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	adds r0, r6, #0
	movs r1, #2
	bl sub_080B5248
.L080B5498:
	ldr r0, [r7, #4]
	ldr r1, [r7, #8]
	subs r0, r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x12
	movs r0, #0xd0
	lsls r0, r0, #0xf
	adds r1, r1, r0
	ldr r0, .L080B5500
	movs r2, #0x90
	lsls r2, r2, #2
	str r2, [sp]
	movs r2, #0x5d
	str r2, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #9
	orrs r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r6, #0
	movs r5, #0xd2
	lsls r5, r5, #0xf
.L080B54D0:
	ldr r0, [r7, #8]
	adds r0, r6, r0
	lsls r0, r0, #3
	ldr r1, .L080B5504
	adds r3, r0, r1
	ldrh r0, [r3, #4]
	cmp r0, #0xff
	beq .L080B5508
	ldrh r1, [r3, #6]
	ldrb r2, [r3]
	ldrb r3, [r3, #1]
	movs r4, #1
	str r4, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r4, #0x12
	str r4, [sp, #8]
	lsrs r4, r5, #0x10
	str r4, [sp, #0xc]
	bl MarkerList_DrawLocationName
	b .L080B551C
.L080B54FC: .4byte gUnknown_08162B76
.L080B5500: .4byte gUnknown_080004F8
.L080B5504: .4byte 0x03005808 @ IWRAM+0x5808
.L080B5508:
	lsrs r0, r5, #0x10
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	ldr r0, .L080B5530
	movs r1, #1
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
.L080B551C:
	movs r2, #0xc0
	lsls r2, r2, #0xc
	adds r5, r5, r2
	adds r6, #1
	cmp r6, #3
	bls .L080B54D0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B5530: .4byte gUnknown_08162B0C

	thumb_func_start sub_080B5534
sub_080B5534: @ 0x080B5534
.L080B5534:
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r0, #0
	adds r2, #0x24
	str r1, [r0, #0x24]
	cmp r1, #2
	bne .L080B5548
	movs r0, #0
	str r0, [r2, #0xc]
.L080B5548:
	pop {r0}
	bx r0

	thumb_func_start sub_080B554C
sub_080B554C: @ 0x080B554C
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080B5534
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B555C
sub_080B555C: @ 0x080B555C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r0, #0
	strh r0, [r6, #0x1e]
	ldr r2, .L080B55A0
	ldrh r1, [r2, #0x3a]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq .L080B55B8
	ldr r4, [r5, #4]
	lsls r4, r4, #3
	ldr r0, .L080B55A4
	adds r4, r4, r0
	movs r0, #0x65
	bl sub_080C51D4
	ldrh r0, [r4, #4]
	cmp r0, #0xff
	bne .L080B55A8
	strh r7, [r6, #0x1e]
	adds r0, r6, #0
	movs r1, #1
	bl sub_080B5534
	movs r0, #0xd
	strh r0, [r5, #0x10]
	movs r0, #5
	strh r0, [r5, #0x12]
	b .L080B568C
	.byte 0x00, 0x00
.L080B55A0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B55A4: .4byte 0x03005808 @ IWRAM+0x5808
.L080B55A8:
	movs r0, #3
	strh r0, [r6, #0x1e]
	ldr r0, .L080B55B4
	strh r7, [r0]
	b .L080B568C
	.byte 0x00, 0x00
.L080B55B4: .4byte 0x0200DFD2 @ EWRAM+0xDFD2
.L080B55B8:
	ldrh r1, [r2, #0x3a]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L080B55CE
	movs r0, #0x66
	bl sub_080C51D4
	strh r4, [r6, #0x1e]
	b .L080B568C
.L080B55CE:
	ldrh r1, [r2, #0x3c]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080B55F6
	ldr r0, [r5, #4]
	cmp r0, #0
	beq .L080B568C
	movs r0, #0x64
	bl sub_080C51D4
	ldr r0, [r5, #4]
	subs r0, #1
	str r0, [r5, #4]
	ldr r1, [r5, #8]
	cmp r1, r0
	bls .L080B568C
	subs r0, r1, #1
	str r0, [r5, #8]
	b .L080B568C
.L080B55F6:
	ldrh r1, [r2, #0x3c]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080B5620
	ldr r0, [r5, #4]
	cmp r0, #7
	beq .L080B568C
	movs r0, #0x64
	bl sub_080C51D4
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	ldr r1, [r5, #8]
	subs r0, r0, r1
	cmp r0, #3
	bls .L080B568C
	adds r0, r1, #1
	str r0, [r5, #8]
	b .L080B568C
.L080B5620:
	ldr r0, .L080B5648
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080B5658
	ldr r1, [r5, #4]
	cmp r1, #0
	beq .L080B568C
	ldr r0, [r5, #8]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne .L080B564C
	str r0, [r5, #4]
	str r0, [r5, #8]
	b .L080B5650
	.byte 0x00, 0x00
.L080B5648: .4byte 0x03003964 @ IWRAM+0x3964
.L080B564C:
	subs r0, r1, r0
	str r0, [r5, #4]
.L080B5650:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080B568C
.L080B5658:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080B568C
	ldr r2, [r5, #4]
	cmp r2, #7
	beq .L080B568C
	ldr r1, [r5, #8]
	subs r1, r2, r1
	movs r0, #3
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne .L080B5682
	movs r0, #7
	str r0, [r5, #4]
	movs r0, #4
	str r0, [r5, #8]
	b .L080B5686
.L080B5682:
	adds r0, r2, r0
	str r0, [r5, #4]
.L080B5686:
	movs r0, #0x64
	bl sub_080C51D4
.L080B568C:
	ldr r0, [r5, #8]
	cmp r0, #0
	beq .L080B569E
	movs r0, #0
	movs r1, #0
	movs r2, #0xd6
	movs r3, #0x6a
	bl sub_080C4A4C
.L080B569E:
	ldr r0, [r5, #8]
	cmp r0, #4
	beq .L080B56B0
	movs r0, #0
	movs r1, #0
	movs r2, #0xd6
	movs r3, #0x98
	bl sub_080C4AB0
.L080B56B0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B56B8
sub_080B56B8: @ 0x080B56B8
.L080B56B8:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r1, #2
	adds r4, r4, r1
	lsls r4, r4, #2
	adds r4, r4, r1
	lsls r4, r4, #4
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, .L080B56E8
	adds r1, r1, r0
	adds r4, r4, r1
	ldrb r0, [r4, #2]
	strh r0, [r2]
	ldrb r0, [r4, #3]
	strh r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B56E8: .4byte 0x02005000 @ EWRAM+0x5000

	thumb_func_start sub_080B56EC
sub_080B56EC: @ 0x080B56EC
.L080B56EC:
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r6, #0x24
	ldr r2, .L080B5718
	ldrh r5, [r6, #0x10]
	lsls r1, r5, #1
	adds r1, r1, r5
	lsls r1, r1, #2
	ldrh r3, [r6, #0x12]
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r1, r1, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne .L080B571C
.L080B5714:
	movs r0, #0
	b .L080B5768
.L080B5718: .4byte 0x02005000 @ EWRAM+0x5000
.L080B571C:
	mov r4, sp
	adds r4, #2
	adds r0, r5, #0
	adds r1, r3, #0
	mov r2, sp
	adds r3, r4, #0
	bl sub_080B56B8
	movs r3, #0
.L080B572E:
	ldr r0, [r6, #4]
	cmp r0, r3
	beq .L080B5760
	lsls r1, r3, #3
	ldr r0, .L080B5770
	adds r2, r1, r0
	ldrh r1, [r2, #4]
	ldr r0, .L080B5774
	ldr r0, [r0]
	cmp r1, r0
	bne .L080B5760
	ldrh r0, [r2, #6]
	ldr r1, .L080B5778
	ldr r1, [r1]
	cmp r0, r1
	bne .L080B5760
	mov r1, sp
	ldrb r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	bne .L080B5760
	ldrb r0, [r2, #1]
	ldrh r1, [r4]
	cmp r0, r1
	beq .L080B5714
.L080B5760:
	adds r3, #1
	cmp r3, #7
	bls .L080B572E
	movs r0, #1
.L080B5768:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080B5770: .4byte 0x03005808 @ IWRAM+0x5808
.L080B5774: .4byte 0x03004614 @ IWRAM+0x4614
.L080B5778: .4byte 0x03004514 @ IWRAM+0x4514

	thumb_func_start sub_080B577C
sub_080B577C: @ 0x080B577C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	movs r0, #0x80
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	movs r7, #0
	strh r7, [r5, #0x1e]
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	beq .L080B579A
	b .L080B5908
.L080B579A:
	ldr r2, .L080B57E0
	ldrh r1, [r2, #0x3a]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080B57E8
	movs r0, #0x65
	bl sub_080C51D4
	bl sub_080B47CC
	adds r0, r5, #0
	bl sub_080B56EC
	cmp r0, #1
	bne .L080B57E4
	strh r6, [r5, #0x1e]
	str r6, [sp]
	movs r0, #0xd
	movs r1, #0
	movs r2, #0x10
	movs r3, #5
	bl TextWindow_CreateOpen
	str r0, [r4, #0x1c]
	str r6, [sp]
	movs r0, #2
	movs r1, #1
	movs r2, #0xa
	movs r3, #9
	bl TextWindow_CreateOpen
	str r0, [r4, #0x20]
	b .L080B5920
.L080B57E0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B57E4:
	strh r6, [r4, #0x14]
	b .L080B5920
.L080B57E8:
	ldrh r1, [r2, #0x3a]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080B5806
	strh r2, [r5, #0x1e]
	adds r0, r5, #0
	movs r1, #0
	bl sub_080B5534
	movs r0, #0x66
	bl sub_080C51D4
	b .L080B5920
.L080B5806:
	ldr r0, .L080B5828
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080B5854
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	beq .L080B582C
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r4, #0x12]
	subs r0, #1
	strh r0, [r4, #0x12]
	b .L080B5920
	.byte 0x00, 0x00
.L080B5828: .4byte 0x03003964 @ IWRAM+0x3964
.L080B582C:
	ldr r0, .L080B584C
	ldrh r5, [r0]
	cmp r5, #1
	bne .L080B5920
	ldr r4, .L080B5850
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble .L080B5846
	bl sub_080B4A54
	cmp r0, #1
	bne .L080B5920
.L080B5846:
	ldrh r0, [r4]
	adds r0, #1
	b .L080B588E
.L080B584C: .4byte 0x0200DFCA @ EWRAM+0xDFCA
.L080B5850: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080B5854:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080B58D0
	ldrh r0, [r4, #0x12]
	cmp r0, #0xa
	beq .L080B5870
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r4, #0x12]
	adds r0, #1
	strh r0, [r4, #0x12]
	b .L080B5920
.L080B5870:
	ldr r0, .L080B58BC
	ldrh r5, [r0]
	cmp r5, #1
	bne .L080B5920
	ldr r4, .L080B58C0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge .L080B588A
	bl sub_080B4A54
	cmp r0, #1
	bne .L080B5920
.L080B588A:
	ldrh r0, [r4]
	subs r0, #1
.L080B588E:
	strh r0, [r4]
	bl sub_080B47CC
	ldr r0, .L080B58C4
	ldr r1, .L080B58C8
	str r5, [sp]
	str r7, [sp, #4]
	movs r2, #0x1c
	str r2, [sp, #8]
	movs r2, #0xd
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	bl sub_080B4AA4
	ldr r1, .L080B58CC
	ldrh r0, [r4]
	strh r0, [r1]
	bl sub_080B466C
	b .L080B5920
.L080B58BC: .4byte 0x0200DFC8 @ EWRAM+0xDFC8
.L080B58C0: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080B58C4: .4byte gUnknown_081B8D70
.L080B58C8: .4byte 0x02000000 @ EWRAM
.L080B58CC: .4byte 0x0200DFCE @ EWRAM+0xDFCE
.L080B58D0:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080B58EC
	ldrh r0, [r4, #0x10]
	cmp r0, #0
	beq .L080B5920
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	b .L080B5920
.L080B58EC:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080B5920
	ldrh r0, [r4, #0x10]
	cmp r0, #0x1b
	beq .L080B5920
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	b .L080B5920
.L080B5908:
	ldr r2, .L080B5928
	ldrh r1, [r2, #0x3a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L080B591E
	ldrh r1, [r2, #0x3a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080B5920
.L080B591E:
	strh r7, [r4, #0x14]
.L080B5920:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B5928: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B592C
sub_080B592C: @ 0x080B592C
.L080B592C:
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r0, [r4, #0x10]
	ldrh r1, [r4, #0x12]
	mov r5, sp
	adds r5, #2
	mov r2, sp
	adds r3, r5, #0
	bl sub_080B56B8
	ldr r1, [r4, #4]
	lsls r1, r1, #3
	ldr r0, .L080B5970
	adds r1, r1, r0
	mov r0, sp
	ldrh r0, [r0]
	strb r0, [r1]
	ldrh r0, [r5]
	strb r0, [r1, #1]
	ldr r0, .L080B5974
	ldr r0, [r0]
	strh r0, [r1, #4]
	ldr r0, .L080B5978
	ldr r0, [r0]
	strh r0, [r1, #6]
	ldr r0, [r4, #0xc]
	strb r0, [r1, #3]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B5970: .4byte 0x03005808 @ IWRAM+0x5808
.L080B5974: .4byte 0x03004614 @ IWRAM+0x4614
.L080B5978: .4byte 0x03004514 @ IWRAM+0x4514

	thumb_func_start sub_080B597C
sub_080B597C: @ 0x080B597C
.L080B597C:
	ldr r0, [r0, #0x28]
	lsls r0, r0, #3
	ldr r1, .L080B5994
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	strb r1, [r0, #1]
	movs r2, #0
	movs r1, #0xff
	strh r1, [r0, #4]
	strb r2, [r0, #3]
	bx lr
.L080B5994: .4byte 0x03005808 @ IWRAM+0x5808

	thumb_func_start sub_080B5998
sub_080B5998: @ 0x080B5998
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	movs r0, #0x80
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r2, .L080B59D4
	ldrh r1, [r2, #0x3a]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080B59D8
	strh r3, [r4, #0x1e]
	adds r0, r4, #0
	movs r1, #0
	bl sub_080B5534
	adds r0, r4, #0
	bl sub_080B592C
	movs r0, #0x65
	bl sub_080C51D4
	b .L080B5A46
	.byte 0x00, 0x00
.L080B59D4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B59D8:
	ldrh r1, [r2, #0x3a]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080B5A0E
	strh r3, [r4, #0x1e]
	adds r0, r4, #0
	movs r1, #1
	bl sub_080B5534
	movs r0, #0x66
	bl sub_080C51D4
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	beq .L080B5A00
	movs r1, #1
	bl TextWindow_Close
.L080B5A00:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq .L080B5A46
	movs r1, #1
	bl TextWindow_Close
	b .L080B5A46
.L080B5A0E:
	ldrh r1, [r2, #0x3c]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080B5A2A
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq .L080B5A46
	movs r0, #0x64
	bl sub_080C51D4
	ldr r0, [r5, #0xc]
	subs r0, #1
	b .L080B5A44
.L080B5A2A:
	ldrh r1, [r2, #0x3c]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080B5A46
	ldr r0, [r5, #0xc]
	cmp r0, #4
	beq .L080B5A46
	movs r0, #0x64
	bl sub_080C51D4
	ldr r0, [r5, #0xc]
	adds r0, #1
.L080B5A44:
	str r0, [r5, #0xc]
.L080B5A46:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080B5A4C
sub_080B5A4C: @ 0x080B5A4C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	movs r0, #0x80
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r0, [r5, #0x24]
	bl Task_IsFree
	adds r1, r0, #0
	cmp r1, #1
	bne .L080B5A96
	ldr r0, .L080B5A80
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B5A84
	strh r1, [r4, #0x1e]
	adds r0, r4, #0
	bl sub_080B597C
	b .L080B5A86
	.byte 0x00, 0x00
.L080B5A80: .4byte 0x030031CC @ IWRAM+0x31CC
.L080B5A84:
	strh r1, [r4, #0x1e]
.L080B5A86:
	ldr r0, .L080B5A9C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080B5AA0
	strh r1, [r0]
	movs r0, #0
	strh r0, [r5, #0x30]
	strh r0, [r5, #0x32]
.L080B5A96:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080B5A9C: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080B5AA0: .4byte 0x0200DFCE @ EWRAM+0xDFCE

	thumb_func_start sub_080B5AA4
sub_080B5AA4: @ 0x080B5AA4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r2, r1, #0
	mov r7, r8
	adds r7, #0x24
	ldr r0, [r7, #4]
	lsls r0, r0, #3
	ldr r1, .L080B5AD8
	adds r6, r0, r1
	movs r0, #0
	mov r1, r8
	strh r0, [r1, #0x1c]
	cmp r2, #5
	bls .L080B5ACC
	b .L080B5C72
.L080B5ACC:
	lsls r0, r2, #2
	ldr r1, .L080B5ADC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080B5AD8: .4byte 0x03005808 @ IWRAM+0x5808
.L080B5ADC: .4byte gUnknown_080B5AE0
	.global gUnknown_080B5AE0
gUnknown_080B5AE0:
.L080B5AE0: @ jump table
	.4byte .L080B5AF8
	.4byte .L080B5BD0
	.4byte .L080B5B08
	.4byte .L080B5BC4
	.4byte .L080B5BD0
	.4byte .L080B5BE4
.L080B5AF8:
	ldr r1, .L080B5B04
	movs r0, #1
	str r0, [r1]
	mov r2, r8
	strh r0, [r2, #0x1c]
	b .L080B5C72
.L080B5B04: .4byte 0x03003FFC @ IWRAM+0x3FFC
.L080B5B08:
	ldr r0, .L080B5BA8
	mov ip, r0
	ldr r0, [r0]
	movs r4, #0
	strh r0, [r7, #0x28]
	ldr r5, .L080B5BAC
	ldr r0, [r5]
	strh r0, [r7, #0x2a]
	ldr r2, .L080B5BB0
	ldrh r0, [r2, #0x12]
	strh r0, [r7, #0x2c]
	ldrh r0, [r2, #0x14]
	strh r0, [r7, #0x2e]
	ldr r3, .L080B5BB4
	ldrh r0, [r3]
	strh r0, [r7, #0x30]
	ldr r1, .L080B5BB8
	ldrh r0, [r1]
	strh r0, [r7, #0x32]
	strh r4, [r3]
	strh r4, [r1]
	ldrh r0, [r6, #4]
	mov r1, ip
	str r0, [r1]
	ldrh r0, [r6, #6]
	str r0, [r5]
	ldrb r0, [r6]
	strh r0, [r2, #0x12]
	ldrb r0, [r6, #1]
	strh r0, [r2, #0x14]
	bl sub_080AE234
	ldrb r0, [r6]
	ldrb r1, [r6, #1]
	mov r4, sp
	adds r4, #0x12
	add r2, sp, #0x10
	adds r3, r4, #0
	bl sub_080B449C
	add r0, sp, #0x10
	ldrh r0, [r0]
	lsrs r0, r0, #3
	strh r0, [r7, #0x10]
	ldrh r0, [r4]
	lsrs r0, r0, #3
	strh r0, [r7, #0x12]
	bl sub_080B47CC
	bl sub_080B4AA4
	mov r0, r8
	movs r1, #3
	bl sub_080B5534
	ldrb r0, [r6]
	ldrb r1, [r6, #1]
	add r4, sp, #0x14
	mov r5, sp
	adds r5, #0x16
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080B449C
	ldrh r0, [r4]
	lsrs r0, r0, #3
	strh r0, [r7, #0x10]
	ldrh r0, [r5]
	lsrs r0, r0, #3
	strh r0, [r7, #0x12]
	ldr r1, .L080B5BBC
	movs r0, #2
	str r0, [r1]
	ldr r1, .L080B5BC0
	movs r0, #0
	bl YesNo_CreateWithTile
	str r0, [r7, #0x24]
	b .L080B5C72
	.byte 0x00, 0x00
.L080B5BA8: .4byte 0x03004614 @ IWRAM+0x4614
.L080B5BAC: .4byte 0x03004514 @ IWRAM+0x4514
.L080B5BB0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B5BB4: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080B5BB8: .4byte 0x0200DFCE @ EWRAM+0xDFCE
.L080B5BBC: .4byte 0x03003FFC @ IWRAM+0x3FFC
.L080B5BC0: .4byte 0x000003F7
.L080B5BC4:
	ldr r1, .L080B5BCC
	movs r0, #1
	str r0, [r1]
	b .L080B5C72
.L080B5BCC: .4byte 0x03003FFC @ IWRAM+0x3FFC
.L080B5BD0:
	bl sub_080C14FC
	ldr r0, .L080B5BE0
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B5C72
	.byte 0x00, 0x00
.L080B5BE0: .4byte sub_080C153C
.L080B5BE4:
	ldr r1, .L080B5C84
	movs r0, #0
	strh r0, [r1]
	ldr r2, .L080B5C88
	mov sb, r2
	ldrh r0, [r7, #0x28]
	str r0, [r2]
	ldr r1, .L080B5C8C
	ldrh r0, [r7, #0x2a]
	str r0, [r1]
	ldr r0, .L080B5C90
	mov r8, r0
	ldrh r0, [r7, #0x2c]
	movs r1, #0
	mov sl, r1
	mov r2, r8
	strh r0, [r2, #0x12]
	ldrh r0, [r7, #0x2e]
	strh r0, [r2, #0x14]
	ldr r1, .L080B5C94
	ldrh r0, [r7, #0x30]
	strh r0, [r1]
	ldr r1, .L080B5C98
	ldrh r0, [r7, #0x32]
	strh r0, [r1]
	ldr r0, .L080B5C9C
	mov r1, sl
	str r1, [r0]
	bl sub_080AE234
	ldrb r0, [r6]
	ldrb r1, [r6, #1]
	add r4, sp, #0x18
	mov r5, sp
	adds r5, #0x1a
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080B449C
	ldrh r0, [r4]
	lsrs r0, r0, #3
	strh r0, [r7, #0x10]
	ldrh r0, [r5]
	lsrs r0, r0, #3
	strh r0, [r7, #0x12]
	mov r2, sb
	ldr r0, [r2]
	cmp r0, #0x42
	bne .L080B5C4E
	mov r1, r8
	adds r1, #0x50
	movs r0, #2
	strh r0, [r1]
.L080B5C4E:
	ldr r0, .L080B5CA0
	ldr r1, .L080B5CA4
	movs r2, #1
	str r2, [sp]
	mov r2, sl
	str r2, [sp, #4]
	movs r2, #0x1c
	str r2, [sp, #8]
	movs r2, #0xd
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	bl sub_080B47CC
	bl sub_080B4AA4
.L080B5C72:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B5C84: .4byte 0x0200DFD2 @ EWRAM+0xDFD2
.L080B5C88: .4byte 0x03004614 @ IWRAM+0x4614
.L080B5C8C: .4byte 0x03004514 @ IWRAM+0x4514
.L080B5C90: .4byte 0x03004550 @ IWRAM+0x4550
.L080B5C94: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080B5C98: .4byte 0x0200DFCE @ EWRAM+0xDFCE
.L080B5C9C: .4byte 0x03003FFC @ IWRAM+0x3FFC
.L080B5CA0: .4byte gUnknown_081B8D70
.L080B5CA4: .4byte 0x02000000 @ EWRAM

	thumb_func_start sub_080B5CA8
sub_080B5CA8: @ 0x080B5CA8
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq .L080B5CBA
	movs r1, #1
	bl Window_Close
.L080B5CBA:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq .L080B5CC6
	movs r1, #1
	bl TextWindow_Close
.L080B5CC6:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq .L080B5CD2
	movs r1, #1
	bl TextWindow_Close
.L080B5CD2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B5CD8
sub_080B5CD8: @ 0x080B5CD8
	ldr r1, .L080B5CE0
	movs r0, #0x34
	strh r0, [r1, #0x1e]
	bx lr
.L080B5CE0: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B5CE4
sub_080B5CE4: @ 0x080B5CE4
	push {lr}
	sub sp, #4
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x12
	movs r3, #0x59
	bl MarkerHeader_DrawLocationName
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B5D00
sub_080B5D00: @ 0x080B5D00
.L080B5D00:
	push {lr}
	ldr r0, .L080B5D10
	ldr r1, .L080B5D14
	bl Task_Create
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B5D10: .4byte gUnknown_08162C34
.L080B5D14: .4byte 0x0000FFFF

	thumb_func_start sub_080B5D18
sub_080B5D18: @ 0x080B5D18
	push {lr}
	ldr r0, .L080B5D30
	ldrh r0, [r0]
	ldr r1, .L080B5D34
	ldr r1, [r1]
	ldrh r2, [r1, #2]
	movs r1, #0xa
	bl sub_080B31C4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B5D30: .4byte 0x03004614 @ IWRAM+0x4614
.L080B5D34: .4byte 0x03004000 @ IWRAM+0x4000

	thumb_func_start sub_080B5D38
sub_080B5D38: @ 0x080B5D38
	push {lr}
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	pop {r0}
	bx r0

	thumb_func_start sub_080B5D48
sub_080B5D48: @ 0x080B5D48
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r7, .L080B5DB4
	ldrh r0, [r7]
	ldr r6, .L080B5DB8
	ldrh r1, [r6]
	bl sub_080C8B10
	adds r4, r0, #0
	ldr r1, .L080B5DBC
	movs r0, #0
	strh r0, [r1]
	movs r0, #0
	movs r1, #0
	bl FieldMap_CellRecordsRel
	movs r1, #0x20
	bl FieldMap_FindRecord
	adds r1, r0, #0
	cmp r1, #0
	beq .L080B5D84
	ldr r0, .L080B5DC0
	ldrh r1, [r1, #2]
	ldr r2, .L080B5DC4
	adds r0, r0, r2
	movs r2, #0
	strh r1, [r0]
	ldr r0, .L080B5DC8
	str r2, [r0]
.L080B5D84:
	ldr r2, .L080B5DC8
	ldr r0, .L080B5DC0
	ldr r1, .L080B5DC4
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xe8
	muls r1, r0, r1
	adds r0, r4, #0
	adds r0, #0xd8
	adds r0, r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	beq .L080B5DCC
	ldr r0, [r7]
	ldr r1, [r6]
	bl Map_SetGraphicsPointers
	bl sub_080AE234
	bl sub_080AD7F0
	movs r0, #0
	b .L080B5DCE
.L080B5DB4: .4byte 0x03004614 @ IWRAM+0x4614
.L080B5DB8: .4byte 0x03004514 @ IWRAM+0x4514
.L080B5DBC: .4byte 0x0300000E @ IWRAM+0xE
.L080B5DC0: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B5DC4: .4byte 0x00000A38
.L080B5DC8: .4byte 0x03003BB4 @ IWRAM+0x3BB4
.L080B5DCC:
	movs r0, #1
.L080B5DCE:
	strh r0, [r5, #0x1c]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B5DD8
sub_080B5DD8: @ 0x080B5DD8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080B5DF0
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne .L080B5DF8
	ldr r0, .L080B5DF4
	bl sub_080AE494
	movs r0, #1
	b .L080B5DFA
	.byte 0x00, 0x00
.L080B5DF0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B5DF4: .4byte sub_080B0158
.L080B5DF8:
	movs r0, #0
.L080B5DFA:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B5E04
sub_080B5E04: @ 0x080B5E04
	push {lr}
	movs r0, #1
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_080B5E10
sub_080B5E10: @ 0x080B5E10
	push {lr}
	cmp r1, #1
	bne .L080B5E20
	movs r0, #0x81
	lsls r0, r0, #1
	bl Flag_Set
	b .L080B5E28
.L080B5E20:
	movs r0, #0x81
	lsls r0, r0, #1
	bl Flag_Clear
.L080B5E28:
	pop {r0}
	bx r0

	thumb_func_start sub_080B5E2C
sub_080B5E2C: @ 0x080B5E2C
	push {lr}
	movs r0, #0
	movs r1, #0
	bl FieldMap_CellRecordsRel
	movs r1, #9
	bl FieldMap_FindRecord
	cmp r0, #0
	bne .L080B5E48
	ldr r0, .L080B5E4C
	ldrh r0, [r0, #2]
	bl Field_Step
.L080B5E48:
	pop {r0}
	bx r0
.L080B5E4C: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B5E50
sub_080B5E50: @ 0x080B5E50
.L080B5E50:
	push {lr}
	ldr r0, .L080B5E68
	ldr r1, .L080B5E6C
	bl Task_Create
	ldr r1, .L080B5E70
	str r0, [r1]
	movs r0, #0x1a
	bl Field_SetState
	pop {r0}
	bx r0
.L080B5E68: .4byte gUnknown_08162EAC
.L080B5E6C: .4byte 0x0000FFFF
.L080B5E70: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080B5E74
sub_080B5E74: @ 0x080B5E74
	push {r4, lr}
	sub sp, #4
	ldr r0, .L080B5EBC
	ldrh r0, [r0]
	lsrs r0, r0, #3
	lsls r0, r0, #0xa
	ldr r3, .L080B5EC0
	adds r3, r0, r3
	movs r1, #0xd0
	lsls r1, r1, #6
	subs r4, r1, r0
	cmp r4, #0
	beq .L080B5EB2
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080B5EC4
	mov r0, sp
	str r0, [r1]
	ldr r2, .L080B5EC8
	str r2, [r1, #4]
	ldr r0, .L080B5ECC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	str r3, [r1]
	str r2, [r1, #4]
	lsrs r0, r4, #2
	movs r2, #0x84
	lsls r2, r2, #0x18
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r1, #8]
.L080B5EB2:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B5EBC: .4byte 0x0300000E @ IWRAM+0xE
.L080B5EC0: .4byte 0x02005004 @ EWRAM+0x5004
.L080B5EC4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B5EC8: .4byte 0x06008800 @ VRAM+0x8800
.L080B5ECC: .4byte 0x85000D00

	thumb_func_start sub_080B5ED0
sub_080B5ED0: @ 0x080B5ED0
	push {lr}
	ldr r0, .L080B5EE4
	bl sub_080AE494
	ldr r1, .L080B5EE8
	ldrh r0, [r1]
	adds r0, #8
	strh r0, [r1]
	pop {r0}
	bx r0
.L080B5EE4: .4byte sub_080B5E74
.L080B5EE8: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080B5EEC
sub_080B5EEC: @ 0x080B5EEC
	push {r4, lr}
	ldr r4, .L080B5F18
	ldr r0, [r4]
	ldr r1, .L080B5F1C
	ldr r1, [r1]
	bl Map_SetGraphicsPointers
	bl sub_080AE234
	bl sub_080AE294
	ldrh r0, [r4]
	ldr r1, .L080B5F20
	ldr r1, [r1]
	ldrh r2, [r1, #4]
	movs r1, #1
	bl sub_080B31C4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B5F18: .4byte 0x03004614 @ IWRAM+0x4614
.L080B5F1C: .4byte 0x03004514 @ IWRAM+0x4514
.L080B5F20: .4byte 0x03004000 @ IWRAM+0x4000

	thumb_func_start sub_080B5F24
sub_080B5F24: @ 0x080B5F24
	push {lr}
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	ldr r0, .L080B5F40
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080B5F44
	strh r1, [r0]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B5F40: .4byte 0x0300000E @ IWRAM+0xE
.L080B5F44: .4byte 0x03003BBC @ IWRAM+0x3BBC

	thumb_func_start sub_080B5F48
sub_080B5F48: @ 0x080B5F48
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080B5F64
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080B5F68
	ldrh r1, [r0]
	ldr r0, .L080B5F6C
	cmp r1, r0
	bne .L080B5F70
	movs r0, #1
	b .L080B5F72
	.byte 0x00, 0x00
.L080B5F64: .4byte Field_LoadGraphicsStep
.L080B5F68: .4byte 0x03003BBC @ IWRAM+0x3BBC
.L080B5F6C: .4byte 0x0000FFFF
.L080B5F70:
	movs r0, #0
.L080B5F72:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B5F7C
sub_080B5F7C: @ 0x080B5F7C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080B5F94
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne .L080B5F9C
	ldr r0, .L080B5F98
	bl sub_080AE494
	movs r0, #1
	b .L080B5F9E
	.byte 0x00, 0x00
.L080B5F94: .4byte 0x03004550 @ IWRAM+0x4550
.L080B5F98: .4byte sub_080B0158
.L080B5F9C:
	movs r0, #0
.L080B5F9E:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B5FA8
sub_080B5FA8: @ 0x080B5FA8
	push {lr}
	movs r0, #1
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_080B5FB4
sub_080B5FB4: @ 0x080B5FB4
	push {lr}
	movs r0, #0
	movs r1, #0
	bl FieldMap_CellRecordsRel
	movs r1, #2
	bl FieldMap_FindRecord
	cmp r0, #0
	bne .L080B5FD0
	ldr r0, .L080B5FD4
	ldrh r0, [r0, #2]
	bl Field_Step
.L080B5FD0:
	pop {r0}
	bx r0
.L080B5FD4: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B5FD8
sub_080B5FD8: @ 0x080B5FD8
.L080B5FD8:
	push {lr}
	ldr r0, .L080B5FF0
	ldr r1, .L080B5FF4
	bl Task_Create
	ldr r1, .L080B5FF8
	str r0, [r1]
	movs r0, #0x1a
	bl Field_SetState
	pop {r0}
	bx r0
.L080B5FF0: .4byte gUnknown_08163060
.L080B5FF4: .4byte 0x0000FFFF
.L080B5FF8: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080B5FFC
sub_080B5FFC: @ 0x080B5FFC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne .L080B6060
	ldr r6, .L080B6030
	ldrh r5, [r6, #2]
	ldr r4, .L080B6034
	bl Random_Next
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r4, [r1]
	ldr r0, .L080B6038
	ldr r0, [r0]
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne .L080B603C
	adds r5, r5, r4
	movs r0, #3
	ands r5, r0
	movs r0, #0x72
	bl sub_080C51D4
	b .L080B6050
.L080B6030: .4byte 0x03004550 @ IWRAM+0x4550
.L080B6034: .4byte gUnknown_08163250
.L080B6038: .4byte 0x03004000 @ IWRAM+0x4000
.L080B603C:
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r2, .L080B605C
	lsls r1, r5, #1
	ldrh r0, [r6, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r1, r2
	ldrh r4, [r1]
.L080B6050:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080B2064
	b .L080B6080
	.byte 0x00, 0x00
.L080B605C: .4byte gUnknown_08163258
.L080B6060:
	ldr r1, .L080B6078
	ldrh r0, [r1, #2]
	ldrh r2, [r1, #6]
	cmp r0, r2
	beq .L080B607C
	ldrh r0, [r1, #6]
	ldrh r1, [r1, #8]
	bl sub_080B2064
	movs r0, #0
	b .L080B607E
	.byte 0x00, 0x00
.L080B6078: .4byte 0x03004550 @ IWRAM+0x4550
.L080B607C:
	movs r0, #1
.L080B607E:
	strh r0, [r4, #0x1c]
.L080B6080:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B6088
sub_080B6088: @ 0x080B6088
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080B2090
	movs r1, #0
	strh r1, [r4, #0x1c]
	subs r1, #1
	cmp r0, r1
	beq .L080B609E
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080B609E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B60A4
sub_080B60A4: @ 0x080B60A4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0
	movs r1, #0
	bl FieldMap_CellRecordsRel
	adds r4, r0, #0
	movs r1, #0x19
	bl FieldMap_FindRecord
	adds r5, r0, #0
	adds r0, r4, #0
	movs r1, #0x14
	bl FieldMap_FindRecord
	cmp r5, #0
	beq .L080B60E4
	ldr r0, .L080B60E0
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
	b .L080B60F6
.L080B60E0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B60E4:
	cmp r0, #0
	beq .L080B60F8
	bl sub_080B8994
	ldr r1, .L080B6100
	str r0, [r1]
	movs r0, #0x1a
	bl Field_SetState
.L080B60F6:
	movs r0, #1
.L080B60F8:
	strh r0, [r6, #0x1c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080B6100: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080B6104
sub_080B6104: @ 0x080B6104
	push {lr}
	movs r0, #1
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_080B6110
sub_080B6110: @ 0x080B6110
	push {lr}
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	pop {r0}
	bx r0

	thumb_func_start sub_080B6120
sub_080B6120: @ 0x080B6120
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080B6138
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne .L080B6140
	ldr r0, .L080B613C
	bl sub_080AE494
	movs r0, #1
	b .L080B6142
	.byte 0x00, 0x00
.L080B6138: .4byte 0x03004550 @ IWRAM+0x4550
.L080B613C: .4byte sub_080B0158
.L080B6140:
	movs r0, #0
.L080B6142:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B614C
sub_080B614C: @ 0x080B614C
.L080B614C:
	push {lr}
	ldr r0, .L080B6164
	ldr r1, .L080B6168
	bl Task_Create
	ldr r1, .L080B616C
	str r0, [r1]
	movs r0, #0x1a
	bl Field_SetState
	pop {r0}
	bx r0
.L080B6164: .4byte gUnknown_08163278
.L080B6168: .4byte 0x0000FFFF
.L080B616C: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080B6170
sub_080B6170: @ 0x080B6170
.L080B6170:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, .L080B619C
	ldrh r7, [r0, #0x12]
	ldrh r5, [r0, #0x14]
	ldrh r6, [r0, #0x16]
	ldrh r4, [r0, #0x18]
	ldr r0, .L080B61A0
	mov r8, r0
	movs r0, #0
	movs r1, #0
	bl FieldMap_CellRecordsRel
	movs r1, #0x28
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B61A4
	ldrh r0, [r0, #2]
	b .L080B61CE
	.byte 0x00, 0x00
.L080B619C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B61A0: .4byte 0x0000FFFF
.L080B61A4:
	cmp r7, r6
	bne .L080B61B8
	cmp r5, r4
	bhs .L080B61B0
	movs r0, #0
	b .L080B61CE
.L080B61B0:
	cmp r5, r4
	bls .L080B61B8
	movs r0, #2
	b .L080B61CE
.L080B61B8:
	cmp r7, r6
	bhs .L080B61C4
	cmp r5, r4
	bne .L080B61C4
	movs r0, #3
	b .L080B61CE
.L080B61C4:
	cmp r7, r6
	bls .L080B61D0
	cmp r5, r4
	bne .L080B61D0
	movs r0, #1
.L080B61CE:
	mov r8, r0
.L080B61D0:
	ldr r0, .L080B61DC
	ldrh r0, [r0, #2]
	cmp r0, r8
	beq .L080B61E0
	mov r0, r8
	b .L080B61E2
.L080B61DC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B61E0:
	ldr r0, .L080B61EC
.L080B61E2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080B61EC: .4byte 0x0000FFFF

	thumb_func_start sub_080B61F0
sub_080B61F0: @ 0x080B61F0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r2, #1
	strh r2, [r4, #0x1c]
	cmp r1, #0
	bne .L080B622C
	bl sub_080B6170
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, .L080B6220
	cmp r3, r0
	beq .L080B624A
	ldr r2, .L080B6224
	lsls r1, r3, #1
	ldr r0, .L080B6228
	ldrh r0, [r0, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r1, r2
	ldrh r1, [r1]
	adds r0, r3, #0
	b .L080B623A
.L080B6220: .4byte 0x0000FFFF
.L080B6224: .4byte gUnknown_08163258
.L080B6228: .4byte 0x03004550 @ IWRAM+0x4550
.L080B622C:
	ldr r1, .L080B6244
	ldrh r0, [r1, #2]
	ldrh r3, [r1, #6]
	cmp r0, r3
	beq .L080B6248
	ldrh r0, [r1, #6]
	ldrh r1, [r1, #8]
.L080B623A:
	bl sub_080B2064
	strh r5, [r4, #0x1c]
	b .L080B624A
	.byte 0x00, 0x00
.L080B6244: .4byte 0x03004550 @ IWRAM+0x4550
.L080B6248:
	strh r2, [r4, #0x1c]
.L080B624A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080B6250
sub_080B6250: @ 0x080B6250
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080B2090
	movs r1, #0
	strh r1, [r4, #0x1c]
	subs r1, #1
	cmp r0, r1
	beq .L080B6266
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080B6266:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B626C
sub_080B626C: @ 0x080B626C
	push {lr}
	movs r0, #0x13
	bl Field_SetState
	bl sub_080C7218
	bl sub_080C7414
	ldr r1, .L080B6288
	movs r0, #0
	strh r0, [r1, #0x1e]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B6288: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B628C
sub_080B628C: @ 0x080B628C
.L080B628C:
	push {lr}
	ldr r0, .L080B62A4
	ldr r1, .L080B62A8
	bl Task_Create
	ldr r1, .L080B62AC
	str r0, [r1]
	movs r0, #0x1a
	bl Field_SetState
	pop {r0}
	bx r0
.L080B62A4: .4byte gUnknown_0816336C
.L080B62A8: .4byte 0x0000FFFF
.L080B62AC: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080B62B0
sub_080B62B0: @ 0x080B62B0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x24
	bl sub_080C7218
	bl sub_080C7414
	ldr r0, .L080B62F4
	movs r4, #0
	strh r4, [r0, #0x1e]
	ldr r1, .L080B62F8
	ldrh r0, [r5, #0x24]
	str r0, [r1]
	str r4, [sp]
	ldr r1, .L080B62FC
	ldr r2, .L080B6300
	mov r0, sp
	bl CpuSet
	ldr r0, .L080B6304
	strh r4, [r0]
	ldr r0, [r6, #4]
	bl sub_080AF060
	movs r0, #0x19
	bl Field_SetState
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B62F4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B62F8: .4byte 0x03004530 @ IWRAM+0x4530
.L080B62FC: .4byte 0x02036094 @ EWRAM+0x36094
.L080B6300: .4byte 0x05000008 @ PLTT+0x8
.L080B6304: .4byte 0x0203DB7A @ EWRAM+0x3DB7A

	thumb_func_start sub_080B6308
sub_080B6308: @ 0x080B6308
.L080B6308:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080B6330
	ldr r1, .L080B6334
	bl Task_Create
	ldr r1, .L080B6338
	str r0, [r1]
	strh r4, [r0, #0x24]
	str r5, [r0, #0x28]
	movs r0, #0x1a
	bl Field_SetState
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B6330: .4byte gUnknown_081633D8
.L080B6334: .4byte 0x0000FFFF
.L080B6338: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080B633C
sub_080B633C: @ 0x080B633C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080B6340
sub_080B6340: @ 0x080B6340
	ldr r1, .L080B6354
	ldr r0, .L080B6358
	str r0, [r1]
	ldr r0, .L080B635C
	str r0, [r1, #4]
	ldr r0, .L080B6360
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B6354: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6358: .4byte 0x0203A2E4 @ EWRAM+0x3A2E4
.L080B635C: .4byte 0x06012F00 @ VRAM+0x12F00
.L080B6360: .4byte 0x84000040

	thumb_func_start sub_080B6364
sub_080B6364: @ 0x080B6364
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldrh r1, [r0, #0x24]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, .L080B63B4
	adds r3, r0, r1
	ldr r2, .L080B63B8
	ldrb r0, [r3]
	ldr r1, .L080B63BC
	mov sb, r1
	ldr r1, .L080B63C0
	mov sl, r1
	cmp r0, #0x20
	beq .L080B6426
	ldr r4, .L080B63C4
	movs r0, #0x20
	adds r0, r0, r4
	mov r8, r0
	ldr r1, .L080B63C8
	adds r1, r1, r4
	mov ip, r1
	ldr r0, .L080B63CC
	adds r7, r4, r0
	ldr r1, .L080B63D0
	adds r6, r4, r1
	ldr r0, .L080B63D4
	adds r5, r4, r0
.L080B63A6:
	ldrb r1, [r3]
	adds r0, r1, #0
	cmp r1, #0x28
	bne .L080B63D8
	adds r1, r4, #0
	b .L080B63FE
	.byte 0x00, 0x00
.L080B63B4: .4byte gUnknown_08163444
.L080B63B8: .4byte 0x0203A2E4 @ EWRAM+0x3A2E4
.L080B63BC: .4byte gUnknown_081635B6
.L080B63C0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080B63C4: .4byte gUnknown_081AE018
.L080B63C8: .4byte 0xFFFFFE20
.L080B63CC: .4byte 0xFFFFF820
.L080B63D0: .4byte 0xFFFFF7A0
.L080B63D4: .4byte 0xFFFFFA80
.L080B63D8:
	cmp r1, #0x29
	bne .L080B63E0
	mov r1, r8
	b .L080B63FE
.L080B63E0:
	cmp r1, #0x27
	bne .L080B63E8
	mov r1, ip
	b .L080B63FE
.L080B63E8:
	cmp r1, #0x26
	bne .L080B63F0
	adds r1, r7, #0
	b .L080B63FE
.L080B63F0:
	cmp r1, #0x5f
	bne .L080B63F8
	adds r1, r6, #0
	b .L080B63FE
.L080B63F8:
	subs r0, #0x41
	lsls r0, r0, #5
	adds r1, r0, r5
.L080B63FE:
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldm r1!, {r0}
	stm r2!, {r0}
	ldr r0, [r1]
	stm r2!, {r0}
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, #0x20
	bne .L080B63A6
.L080B6426:
	movs r1, #0xa
	str r1, [sp]
	movs r0, #2
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, sb
	mov r1, sl
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080B645C
	movs r1, #1
	bl VBlankTask_AddCounted
	bl sub_080C6764
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B645C: .4byte sub_080B6340

	thumb_func_start sub_080B6460
sub_080B6460: @ 0x080B6460
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r0
	mov r7, r8
	adds r7, #0x24
	ldrh r1, [r0, #0x24]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, .L080B6508
	adds r4, r0, r1
	ldrh r0, [r7, #4]
	subs r0, #1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B6494
	movs r0, #4
	strh r0, [r7, #4]
	ldrh r0, [r7, #2]
	cmp r0, #0xa
	beq .L080B6494
	adds r0, #1
	strh r0, [r7, #2]
.L080B6494:
	movs r5, #0
	ldrb r0, [r4]
	ldrh r2, [r7]
	ldrh r6, [r7, #2]
	cmp r0, #0x20
	beq .L080B64AA
.L080B64A0:
	adds r5, #1
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0x20
	bne .L080B64A0
.L080B64AA:
	movs r0, #8
	subs r0, r0, r5
	lsls r0, r0, #3
	lsrs r0, r0, #1
	adds r3, r0, #0
	adds r3, #0x57
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r4, r0, r1
	movs r5, #0
	cmp r5, r6
	bhs .L080B64FA
	ldrb r0, [r4]
	cmp r0, #0x20
	beq .L080B64FA
	adds r6, r3, #0
.L080B64CC:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #0x15
	str r0, [sp, #8]
	ldr r0, .L080B650C
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r6, #8
	adds r5, #1
	adds r4, #1
	ldrh r1, [r7, #2]
	cmp r5, r1
	bhs .L080B64FA
	ldrb r0, [r4]
	cmp r0, #0x20
	bne .L080B64CC
.L080B64FA:
	ldr r0, .L080B6510
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B6514
	movs r0, #0
	b .L080B6516
	.byte 0x00, 0x00
.L080B6508: .4byte gUnknown_08163444
.L080B650C: .4byte gUnknown_08163638
.L080B6510: .4byte 0x03004550 @ IWRAM+0x4550
.L080B6514:
	movs r0, #1
.L080B6516:
	mov r1, r8
	strh r0, [r1, #0x1c]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B6528
sub_080B6528: @ 0x080B6528
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080B653C
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080B6536
	movs r0, #0
.L080B6536:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0
.L080B653C: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B6540
sub_080B6540: @ 0x080B6540
	push {lr}
	sub sp, #8
	ldr r1, .L080B6564
	movs r0, #0xa
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0xa
	movs r3, #2
	bl Tilemap_FillRect
	bl sub_080C6764
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B6564: .4byte 0x0200DFD4 @ EWRAM+0xDFD4

	thumb_func_start sub_080B6568
sub_080B6568: @ 0x080B6568
.L080B6568:
	push {r4, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #1
	ldr r1, .L080B65B4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x3f
	beq .L080B65AC
	ldr r0, .L080B65B8
	ldr r1, .L080B65BC
	bl Task_Create
	movs r3, #0
	str r3, [sp]
	ldr r2, .L080B65C0
	mov r1, sp
	str r1, [r2]
	ldr r1, .L080B65C4
	str r1, [r2, #4]
	ldr r1, .L080B65C8
	str r1, [r2, #8]
	ldr r1, [r2, #8]
	adds r2, r0, #0
	adds r2, #0x24
	strh r4, [r0, #0x24]
	strh r3, [r2, #2]
	movs r1, #1
	strh r1, [r2, #4]
	ldr r1, .L080B65CC
	str r0, [r1]
.L080B65AC:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080B65B4: .4byte gUnknown_08163444
.L080B65B8: .4byte gUnknown_08163640
.L080B65BC: .4byte 0x0000FFFF
.L080B65C0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B65C4: .4byte 0x0203A2E4 @ EWRAM+0x3A2E4
.L080B65C8: .4byte 0x85000040
.L080B65CC: .4byte 0x0203A3E4 @ EWRAM+0x3A3E4

	thumb_func_start sub_080B65D0
sub_080B65D0: @ 0x080B65D0
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	cmp r1, #0
	bne .L080B65EA
	ldr r1, .L080B6600
	ldr r0, .L080B6604
	str r0, [r1]
	ldr r0, .L080B6608
	str r0, [r1, #4]
	ldr r0, .L080B660C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
.L080B65EA:
	ldr r0, .L080B6610
	movs r1, #1
	strh r1, [r0, #0x34]
	movs r0, #1
	bl PalFade_FadeToBlack
	str r0, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B6600: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6604: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080B6608: .4byte 0x0201B874 @ EWRAM+0x1B874
.L080B660C: .4byte 0x84000100
.L080B6610: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080B6614
sub_080B6614: @ 0x080B6614
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	bl PalFade_IsActive
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne .L080B664C
	movs r0, #1
	strh r0, [r4, #0x1c]
	mov r0, sp
	strh r1, [r0]
	ldr r1, .L080B6640
	str r0, [r1]
	ldr r0, .L080B6644
	str r0, [r1, #4]
	ldr r0, .L080B6648
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b .L080B6650
.L080B6640: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6644: .4byte 0x02000000 @ EWRAM
.L080B6648: .4byte 0x81000800
.L080B664C:
	movs r0, #0
	strh r0, [r4, #0x1c]
.L080B6650:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B6658
sub_080B6658: @ 0x080B6658
	push {r4, r5, lr}
	sub sp, #0x40
	adds r4, r0, #0
	adds r5, r1, #0
	adds r4, #0x24
	movs r0, #1
	bl PalFade_FadeInFromBlack
	str r0, [r4, #4]
	cmp r5, #0
	bne .L080B6694
	ldr r4, .L080B668C
	ldr r5, .L080B6690
	adds r0, r4, #0
	mov r1, sp
	adds r2, r5, #0
	bl CpuSet
	bl sub_080C1384
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuSet
	b .L080B669A
.L080B668C: .4byte 0x03002D70 @ IWRAM+0x2D70
.L080B6690: .4byte 0x04000010 @ REG_BG0HOFS
.L080B6694:
	ldr r1, .L080B66A4
	movs r0, #0
	strh r0, [r1, #0x36]
.L080B669A:
	add sp, #0x40
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B66A4: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080B66A8
sub_080B66A8: @ 0x080B66A8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	bl PalFade_IsActive
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B66BC
	movs r0, #1
	b .L080B66BE
.L080B66BC:
	movs r0, #0
.L080B66BE:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B66C8
sub_080B66C8: @ 0x080B66C8
	ldr r0, .L080B66E8
	movs r3, #0xc0
	lsls r3, r3, #0x13
	str r3, [r0]
	ldr r1, .L080B66EC
	str r1, [r0, #4]
	ldr r2, .L080B66F0
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, .L080B66F4
	str r1, [r0]
	str r3, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	bx lr
	.byte 0x00, 0x00
.L080B66E8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B66EC: .4byte 0x02017874 @ EWRAM+0x17874
.L080B66F0: .4byte 0x84000200
.L080B66F4: .4byte 0x02000000 @ EWRAM

	thumb_func_start sub_080B66F8
sub_080B66F8: @ 0x080B66F8
	ldr r0, .L080B6714
	ldr r3, .L080B6718
	str r3, [r0]
	ldr r1, .L080B671C
	str r1, [r0, #4]
	ldr r2, .L080B6720
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, .L080B6724
	str r1, [r0]
	str r3, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	bx lr
.L080B6714: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6718: .4byte 0x06001000 @ VRAM+0x1000
.L080B671C: .4byte 0x02018874 @ EWRAM+0x18874
.L080B6720: .4byte 0x84000200
.L080B6724: .4byte 0x02000000 @ EWRAM

	thumb_func_start sub_080B6728
sub_080B6728: @ 0x080B6728
	ldr r0, .L080B6744
	ldr r3, .L080B6748
	str r3, [r0]
	ldr r1, .L080B674C
	str r1, [r0, #4]
	ldr r2, .L080B6750
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, .L080B6754
	str r1, [r0]
	str r3, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	bx lr
.L080B6744: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6748: .4byte 0x06002000 @ VRAM+0x2000
.L080B674C: .4byte 0x02019874 @ EWRAM+0x19874
.L080B6750: .4byte 0x84000200
.L080B6754: .4byte 0x02000000 @ EWRAM

	thumb_func_start sub_080B6758
sub_080B6758: @ 0x080B6758
.L080B6758:
	ldr r1, .L080B6774
	ldr r0, .L080B6778
	str r0, [r1]
	ldr r0, .L080B677C
	str r0, [r1, #4]
	ldr r0, .L080B6780
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xc6
	ldr r2, .L080B6784
	adds r0, r2, #0
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080B6774: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6778: .4byte 0x02000000 @ EWRAM
.L080B677C: .4byte 0x06003000 @ VRAM+0x3000
.L080B6780: .4byte 0x84000200
.L080B6784: .4byte 0x0000860B

	thumb_func_start sub_080B6788
sub_080B6788: @ 0x080B6788
	push {lr}
	ldr r1, .L080B67A4
	ldr r0, .L080B67A8
	str r0, [r1]
	ldr r0, .L080B67AC
	str r0, [r1, #4]
	ldr r0, .L080B67B0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080B6758
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B67A4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B67A8: .4byte 0x06003000 @ VRAM+0x3000
.L080B67AC: .4byte 0x0201A874 @ EWRAM+0x1A874
.L080B67B0: .4byte 0x84000200

	thumb_func_start sub_080B67B4
sub_080B67B4: @ 0x080B67B4
	push {lr}
	cmp r1, #1
	beq .L080B67D0
	cmp r1, #1
	blo .L080B67C8
	cmp r1, #2
	beq .L080B67D8
	cmp r1, #3
	beq .L080B67E8
	b .L080B67F0
.L080B67C8:
	ldr r0, .L080B67CC
	b .L080B67DA
.L080B67CC: .4byte sub_080B66C8
.L080B67D0:
	ldr r0, .L080B67D4
	b .L080B67DA
.L080B67D4: .4byte sub_080B66F8
.L080B67D8:
	ldr r0, .L080B67E4
.L080B67DA:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B67F0
	.byte 0x00, 0x00
.L080B67E4: .4byte sub_080B6728
.L080B67E8:
	ldr r0, .L080B67F4
	movs r1, #1
	bl VBlankTask_AddCounted
.L080B67F0:
	pop {r0}
	bx r0
.L080B67F4: .4byte sub_080B6788

	thumb_func_start sub_080B67F8
sub_080B67F8: @ 0x080B67F8
	push {lr}
	cmp r1, #0
	bne .L080B682C
	ldr r0, [r0, #0x2c]
	cmp r0, #0
	bne .L080B6814
	ldr r1, .L080B680C
	ldr r0, .L080B6810
	b .L080B6818
	.byte 0x00, 0x00
.L080B680C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6810: .4byte gUnknown_081B8870
.L080B6814:
	ldr r1, .L080B6838
	ldr r0, .L080B683C
.L080B6818:
	str r0, [r1]
	ldr r0, .L080B6840
	str r0, [r1, #4]
	ldr r0, .L080B6844
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080B6848
	movs r1, #1
	bl VBlankTask_AddCounted
.L080B682C:
	ldr r1, .L080B684C
	movs r0, #1
	strh r0, [r1, #0x36]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B6838: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B683C: .4byte gUnknown_081636E8
.L080B6840: .4byte 0x02000000 @ EWRAM
.L080B6844: .4byte 0x84000140
.L080B6848: .4byte sub_080B6758
.L080B684C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080B6850
sub_080B6850: @ 0x080B6850
	push {lr}
	cmp r1, #0
	bne .L080B685A
	bl sub_080AD7F0
.L080B685A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B6860
sub_080B6860: @ 0x080B6860
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	cmp r1, #0
	bne .L080B688C
	ldr r0, .L080B6884
	ldr r0, [r0]
	cmp r0, #0xe
	bls .L080B689E
	ldr r0, .L080B6888
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080B689E
	.byte 0x00, 0x00
.L080B6884: .4byte 0x03003FF8 @ IWRAM+0x3FF8
.L080B6888: .4byte sub_080C1450
.L080B688C:
	ldr r0, .L080B68A4
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne .L080B689E
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r0, .L080B68A8
	bl sub_080AE494
.L080B689E:
	pop {r4}
	pop {r0}
	bx r0
.L080B68A4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B68A8: .4byte sub_080B0158

	thumb_func_start sub_080B68AC
sub_080B68AC: @ 0x080B68AC
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080B68C4
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r1, r0
	cmp r1, #0
	beq .L080B68C8
	movs r0, #1
	strh r0, [r2, #0x1c]
	b .L080B68CA
.L080B68C4: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080B68C8:
	strh r1, [r2, #0x1c]
.L080B68CA:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B68D0
sub_080B68D0: @ 0x080B68D0
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	cmp r1, #5
	bhi .L080B6980
	lsls r0, r1, #2
	ldr r1, .L080B68E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080B68E8: .4byte gUnknown_080B68EC
	.global gUnknown_080B68EC
gUnknown_080B68EC:
.L080B68EC: @ jump table
	.4byte .L080B6904
	.4byte .L080B6928
	.4byte .L080B6930
	.4byte .L080B6960
	.4byte .L080B6968
	.4byte .L080B6978
.L080B6904:
	bl sub_080C14FC
	ldr r1, .L080B6920
	movs r0, #0x1c
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #1
	movs r3, #0
	bl Tilemap_FillRect
	ldr r0, .L080B6924
	b .L080B696A
.L080B6920: .4byte 0x02000000 @ EWRAM
.L080B6924: .4byte sub_080B3E7C
.L080B6928:
	ldr r0, .L080B692C
	b .L080B696A
.L080B692C: .4byte sub_080B3E8C
.L080B6930:
	ldr r0, .L080B6944
	ldrh r1, [r0]
	ldr r0, .L080B6948
	cmp r1, r0
	beq .L080B694C
	movs r0, #0
	bl BgPicture_LoadPiece
	b .L080B6980
	.byte 0x00, 0x00
.L080B6944: .4byte 0x03003BAC @ IWRAM+0x3BAC
.L080B6948: .4byte 0x0000FFFF
.L080B694C:
	ldr r0, .L080B695C
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080B6980
	.byte 0x00, 0x00
.L080B695C: .4byte sub_080B3EA0
.L080B6960:
	ldr r0, .L080B6964
	b .L080B696A
.L080B6964: .4byte sub_080B3ED0
.L080B6968:
	ldr r0, .L080B6974
.L080B696A:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B6980
	.byte 0x00, 0x00
.L080B6974: .4byte BgPicture_BuildTilemap
.L080B6978:
	ldr r0, .L080B6988
	movs r1, #1
	bl VBlankTask_AddCounted
.L080B6980:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
.L080B6988: .4byte sub_080B41B0

	thumb_func_start sub_080B698C
sub_080B698C: @ 0x080B698C
	push {lr}
	bl sub_080C8440
	ldr r1, .L080B69BC
	ldr r2, .L080B69C0
	str r2, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080B69C4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #7
	adds r2, r2, r0
	str r2, [r1]
	ldr r0, .L080B69C8
	str r0, [r1, #4]
	ldr r0, .L080B69CC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B69BC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B69C0: .4byte 0x02017874 @ EWRAM+0x17874
.L080B69C4: .4byte 0x84000200
.L080B69C8: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B69CC: .4byte 0x84000100

	thumb_func_start sub_080B69D0
sub_080B69D0: @ 0x080B69D0
	ldr r1, .L080B69E4
	ldr r0, .L080B69E8
	str r0, [r1]
	ldr r0, .L080B69EC
	str r0, [r1, #4]
	ldr r0, .L080B69F0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B69E4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B69E8: .4byte 0x02018874 @ EWRAM+0x18874
.L080B69EC: .4byte 0x06001000 @ VRAM+0x1000
.L080B69F0: .4byte 0x84000200

	thumb_func_start sub_080B69F4
sub_080B69F4: @ 0x080B69F4
	push {lr}
	sub sp, #4
	bl sub_080C153C
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080B6A18
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080B6A1C
	str r0, [r1, #4]
	ldr r0, .L080B6A20
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B6A18: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6A1C: .4byte 0x06008000 @ VRAM+0x8000
.L080B6A20: .4byte 0x85000008

	thumb_func_start sub_080B6A24
sub_080B6A24: @ 0x080B6A24
	push {lr}
	ldr r1, .L080B6A40
	ldr r0, .L080B6A44
	str r0, [r1]
	ldr r0, .L080B6A48
	str r0, [r1, #4]
	ldr r0, .L080B6A4C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080C1450
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B6A40: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6A44: .4byte 0x0201A874 @ EWRAM+0x1A874
.L080B6A48: .4byte 0x06003000 @ VRAM+0x3000
.L080B6A4C: .4byte 0x84000200

	thumb_func_start sub_080B6A50
sub_080B6A50: @ 0x080B6A50
	push {lr}
	sub sp, #4
	cmp r1, #4
	bhi .L080B6ADE
	lsls r0, r1, #2
	ldr r1, .L080B6A64
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080B6A64: .4byte gUnknown_080B6A68
	.global gUnknown_080B6A68
gUnknown_080B6A68:
.L080B6A68: @ jump table
	.4byte .L080B6A7C
	.4byte .L080B6A84
	.4byte .L080B6A8C
	.4byte .L080B6AA0
	.4byte .L080B6AB0
.L080B6A7C:
	ldr r0, .L080B6A80
	b .L080B6AA2
.L080B6A80: .4byte sub_080B698C
.L080B6A84:
	ldr r0, .L080B6A88
	b .L080B6AA2
.L080B6A88: .4byte sub_080B69D0
.L080B6A8C:
	ldr r0, .L080B6A9C
	movs r1, #1
	bl VBlankTask_AddCounted
	bl sub_080C14FC
	b .L080B6ADE
	.byte 0x00, 0x00
.L080B6A9C: .4byte sub_080B69F4
.L080B6AA0:
	ldr r0, .L080B6AAC
.L080B6AA2:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B6ADE
	.byte 0x00, 0x00
.L080B6AAC: .4byte sub_080B6A24
.L080B6AB0:
	movs r0, #0
	str r0, [sp]
	ldr r0, .L080B6AE4
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080B6AE8
	str r1, [r0, #4]
	ldr r1, .L080B6AEC
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, .L080B6AF0
	str r1, [r0]
	ldr r1, .L080B6AF4
	str r1, [r0, #4]
	ldr r1, .L080B6AF8
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r0, .L080B6AFC
	ldrh r0, [r0, #0x30]
	cmp r0, #0
	bne .L080B6ADE
	bl sub_080C6558
.L080B6ADE:
	add sp, #4
	pop {r0}
	bx r0
.L080B6AE4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6AE8: .4byte 0x06008000 @ VRAM+0x8000
.L080B6AEC: .4byte 0x85000F00
.L080B6AF0: .4byte gUnknown_081A91B8
.L080B6AF4: .4byte 0x0600BC00 @ VRAM+0xBC00
.L080B6AF8: .4byte 0x84001100
.L080B6AFC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080B6B00
sub_080B6B00: @ 0x080B6B00
	push {lr}
	ldr r1, .L080B6B30
	adds r2, r1, #0
	adds r2, #0x48
	ldrh r0, [r2]
	cmp r0, #2
	bne .L080B6B12
	movs r0, #1
	strh r0, [r2]
.L080B6B12:
	adds r2, r1, #0
	adds r2, #0x4c
	ldrh r0, [r2]
	cmp r0, #2
	bne .L080B6B20
	movs r0, #1
	strh r0, [r2]
.L080B6B20:
	adds r1, #0x50
	ldrh r0, [r1]
	cmp r0, #2
	bne .L080B6B2C
	movs r0, #1
	strh r0, [r1]
.L080B6B2C:
	pop {r0}
	bx r0
.L080B6B30: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B6B34
sub_080B6B34: @ 0x080B6B34
	push {lr}
	ldr r0, [r0, #0x24]
	cmp r0, #0
	beq .L080B6B42
	bl _call_via_r0
	b .L080B6B48
.L080B6B42:
	movs r0, #1
	bl Field_SetState
.L080B6B48:
	ldr r1, .L080B6B54
	movs r0, #0
	strh r0, [r1, #0x34]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B6B54: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
