	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080EE2E8
sub_080EE2E8: @ 0x080EE2E8
.L080EE2E8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	ldr r0, .L080EE4DC
	ldr r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r6, [r0]
	movs r7, #0
	movs r4, #0x98
	lsls r4, r4, #1
	adds r1, r1, r4
	ldr r0, .L080EE4E0
	strh r0, [r1]
	ldr r1, [sp]
	ldr r2, .L080EE4E4
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	movs r0, #0x17
	ldrsb r0, [r4, r0]
	cmp r0, #0xb
	bne .L080EE3D0
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	cmp r0, #0x5c
	bne .L080EE3D0
	movs r5, #0
.L080EE332:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	cmp r4, #0
	beq .L080EE36A
	ldrb r0, [r4, #0xc]
	bl sub_080C0830
	cmp r0, #0
	bne .L080EE36A
	ldrb r1, [r4, #0xc]
	ldr r0, [sp]
	bl sub_080F55F4
	cmp r0, #0
	bne .L080EE36A
	ldr r0, .L080EE4DC
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r1, r1, r0
	ldrb r0, [r4, #0xc]
	movs r4, #0x98
	lsls r4, r4, #1
	adds r1, r1, r4
	strh r0, [r1]
	adds r7, #1
.L080EE36A:
	adds r5, #1
	cmp r5, #5
	ble .L080EE332
	movs r5, #0x10
.L080EE372:
	ldr r1, .L080EE4E4
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080C09B0
	cmp r0, #1
	bne .L080EE3B2
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080EE3B2
	ldr r0, [sp]
	adds r1, r5, #0
	bl sub_080F55F4
	cmp r0, #0
	bne .L080EE3B2
	ldr r0, .L080EE4DC
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, r0, r1
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r5, [r0]
	adds r7, #1
.L080EE3B2:
	adds r5, #1
	cmp r5, #0x17
	ble .L080EE372
	ldr r0, .L080EE4DC
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, .L080EE4E0
	strh r1, [r0]
	cmp r7, #0
	beq .L080EE3D0
	b .L080EE69E
.L080EE3D0:
	movs r0, #0x17
	ldrsb r0, [r4, r0]
	cmp r0, #8
	bne .L080EE44A
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	adds r0, #0xf
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi .L080EE44A
	movs r5, #0
.L080EE3EA:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	cmp r4, #0
	beq .L080EE424
	ldrb r0, [r4, #0xc]
	bl sub_080C0830
	cmp r0, #0
	bne .L080EE424
	ldrh r0, [r4, #0x10]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	bne .L080EE424
	ldr r0, .L080EE4DC
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r1, r1, r0
	ldrb r0, [r4, #0xc]
	movs r4, #0x98
	lsls r4, r4, #1
	adds r1, r1, r4
	strh r0, [r1]
	adds r7, #1
.L080EE424:
	adds r5, #1
	cmp r5, #5
	ble .L080EE3EA
	ldr r0, .L080EE4DC
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r0, r2
	str r7, [r1]
	lsls r1, r7, #2
	adds r0, r0, r1
	movs r4, #0x98
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r1, .L080EE4E0
	strh r1, [r0]
	cmp r7, #0
	beq .L080EE44A
	b .L080EE69E
.L080EE44A:
	adds r0, r6, #1
	cmp r0, #1
	bhi .L080EE452
	b .L080EE69E
.L080EE452:
	ldr r0, .L080EE4DC
	mov r8, r0
	ldr r0, [r0]
	ldr r2, [sp]
	lsls r1, r2, #2
	movs r4, #0xb0
	lsls r4, r4, #1
	adds r0, r0, r4
	adds r0, r0, r1
	ldr r0, [r0]
	bl sub_080ED974
	adds r4, r0, #0
	bl sub_080EDA24
	cmp r0, #0
	bne .L080EE478
	movs r0, #1
	eors r4, r0
.L080EE478:
	adds r0, r4, #0
	bl sub_080ED990
	mov sl, r0
	mov r5, sl
	subs r5, #0x10
	bl Battle_IsTwoSided
	movs r1, #8
	str r1, [sp, #4]
	cmp r0, #0
	beq .L080EE494
	movs r2, #4
	str r2, [sp, #4]
.L080EE494:
	adds r0, r4, #0
	bl sub_080EDA24
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r6, r0
	bne .L080EE4EC
	movs r4, #0x10
	mov sl, r4
	movs r5, #0x10
	ldr r0, .L080EE4E8
	movs r1, #0x9a
	lsls r1, r1, #4
	adds r2, r0, r1
	mov r4, r8
	movs r3, #0x98
	lsls r3, r3, #1
.L080EE4B6:
	ldrh r1, [r2, #0x10]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne .L080EE4CC
	ldr r0, [r4]
	lsls r1, r7, #2
	adds r0, r0, r1
	adds r0, r0, r3
	strh r5, [r0]
	adds r7, #1
.L080EE4CC:
	adds r2, #0x80
	adds r5, #1
	mov r0, sl
	adds r0, #8
	cmp r5, r0
	blt .L080EE4B6
	b .L080EE68C
	.byte 0x00, 0x00
.L080EE4DC: .4byte 0x03006434 @ IWRAM+0x6434
.L080EE4E0: .4byte 0x0000FFFF
.L080EE4E4: .4byte 0xFFFF8000
.L080EE4E8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EE4EC:
	ldr r2, [sp]
	ldr r4, .L080EE570
	adds r0, r2, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	adds r4, #0x40
	lsls r6, r5, #7
	ldr r1, .L080EE574
	adds r0, r6, r1
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r2, r2, r0
	mov r8, r2
	movs r0, #4
	ldrsb r0, [r4, r0]
	movs r1, #2
	bl sub_080C1F94
	adds r5, r0, #0
	movs r0, #5
	ldrsb r0, [r4, r0]
	movs r1, #4
	bl sub_080C1F94
	movs r1, #1
	ldrsb r1, [r4, r1]
	lsls r1, r1, #1
	adds r1, r1, r5
	adds r1, r1, r0
	mov sb, r1
	ldr r4, [sp]
	cmp r4, #3
	ble .L080EE578
	bl sub_080C2244
	movs r6, #7
	ands r0, r6
	add sb, r0
	mov r1, r8
	movs r0, #4
	ldrsb r0, [r1, r0]
	movs r1, #2
	bl sub_080C1F94
	adds r5, r0, #0
	mov r2, r8
	movs r0, #5
	ldrsb r0, [r2, r0]
	movs r1, #4
	bl sub_080C1F94
	adds r4, r0, #0
	bl sub_080C2244
	mov r2, r8
	movs r1, #1
	ldrsb r1, [r2, r1]
	lsls r1, r1, #1
	adds r1, r1, r5
	adds r1, r1, r4
	ands r0, r6
	adds r0, r1, r0
	b .L080EE592
.L080EE570: .4byte 0xFFFF8000
.L080EE574: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EE578:
	bl sub_080C2244
	ldr r4, .L080EE5C4
	adds r1, r4, r6
	ldr r2, .L080EE5C8
	adds r1, r1, r2
	ldrb r2, [r1]
	lsrs r2, r2, #1
	movs r1, #0xf
	ands r1, r0
	adds r2, r2, r1
	adds r0, r2, #0
	adds r0, #0xe
.L080EE592:
	cmp r0, sb
	bge .L080EE61C
	mov r5, sl
	ldr r4, [sp, #4]
	adds r0, r5, r4
	ldr r1, .L080EE5CC
	mov r8, r1
	cmp r5, r0
	bge .L080EE678
	ldr r3, .L080EE5D0
	ldrh r6, [r3]
.L080EE5A8:
	lsls r0, r5, #7
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r1, .L080EE5C4
	adds r4, r1, r0
	ldrh r1, [r4, #0x10]
	adds r2, r1, #0
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne .L080EE5D4
	movs r2, #0
	b .L080EE5EE
.L080EE5C4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EE5C8: .4byte 0x000009AD
.L080EE5CC: .4byte 0x03006434 @ IWRAM+0x6434
.L080EE5D0: .4byte gUnknown_0876F6C4
.L080EE5D4:
	ldrh r0, [r3, #2]
	ands r1, r0
	cmp r1, #0
	bne .L080EE5E4
	ldr r2, .L080EE5E0
	b .L080EE5EE
.L080EE5E0: .4byte 0x00002706
.L080EE5E4:
	ldrh r0, [r3, #4]
	ands r2, r0
	cmp r2, #0
	bne .L080EE60C
	ldr r2, .L080EE618
.L080EE5EE:
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	adds r2, r2, r0
	mov r4, r8
	ldr r1, [r4]
	lsls r0, r7, #2
	adds r1, r1, r0
	movs r4, #0x98
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r5, [r0]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	adds r7, #1
.L080EE60C:
	adds r5, #1
	ldr r0, [sp, #4]
	add r0, sl
	cmp r5, r0
	blt .L080EE5A8
	b .L080EE678
.L080EE618: .4byte 0x00004E0C
.L080EE61C:
	mov r5, sl
	ldr r1, [sp, #4]
	adds r0, r5, r1
	cmp r5, r0
	bge .L080EE678
	ldr r2, .L080EE6B0
	mov r8, r2
	lsls r0, r5, #7
	movs r4, #0xd0
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r1, .L080EE6B4
	adds r6, r0, r1
.L080EE636:
	ldrh r0, [r6, #0x10]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	bne .L080EE66C
	mov r4, r8
	ldr r0, [r4]
	lsls r4, r7, #2
	adds r0, r0, r4
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r5, [r0]
	bl sub_080C2244
	bl sub_080C2244
	mov r2, r8
	ldr r1, [r2]
	adds r1, r1, r4
	movs r4, #0x99
	lsls r4, r4, #1
	adds r1, r1, r4
	strh r0, [r1]
	adds r7, #1
.L080EE66C:
	adds r6, #0x80
	adds r5, #1
	ldr r0, [sp, #4]
	add r0, sl
	cmp r5, r0
	blt .L080EE636
.L080EE678:
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	ldr r0, .L080EE6B0
	ldr r2, [r0]
	movs r0, #0x98
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #0
	bl Battle_SortEntriesInsertion
.L080EE68C:
	ldr r0, .L080EE6B0
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, .L080EE6B8
	strh r1, [r0]
.L080EE69E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EE6B0: .4byte 0x03006434 @ IWRAM+0x6434
.L080EE6B4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EE6B8: .4byte 0x0000FFFF
