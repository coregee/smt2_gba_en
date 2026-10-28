	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_08131400
sub_08131400: @ 0x08131400
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r6, #0
	bl CasinoPrize_GetSet
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov ip, r7
	ldr r0, .L08131488
	mov sb, r0
	ldr r4, .L0813148C
	ldr r5, .L08131490
	movs r2, #0
	ldrsh r1, [r5, r2]
	lsls r1, r1, #2
	ldr r2, .L08131494
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r4
	ldrh r0, [r1]
	subs r0, #2
	mov r1, sb
	strh r0, [r1]
	ldr r3, .L08131498
	mov sb, r3
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0]
	mov r1, sb
	strh r0, [r1]
	ldr r1, .L0813149C
	movs r0, #0x17
	strh r0, [r1]
	ldrh r3, [r5]
	movs r0, #0
	ldrsh r2, [r5, r0]
	cmp r2, #2
	bne .L0813146A
	movs r0, #0x16
	strh r0, [r1]
.L0813146A:
	ldr r1, .L081314A0
	movs r0, #1
	strh r0, [r1]
	ldr r0, .L081314A4
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L081314CA
	cmp r2, #0
	beq .L081314A8
	strh r6, [r5]
	b .L08131580
	.byte 0x00, 0x00
.L08131488: .4byte 0x0300689C @ IWRAM+0x689C
.L0813148C: .4byte gUnknown_0878FBA4
.L08131490: .4byte 0x0300696C @ IWRAM+0x696C
.L08131494: .4byte 0x03006844 @ IWRAM+0x6844
.L08131498: .4byte 0x0300695C @ IWRAM+0x695C
.L0813149C: .4byte 0x030066A0 @ IWRAM+0x66A0
.L081314A0: .4byte 0x03006958 @ IWRAM+0x6958
.L081314A4: .4byte 0x03003964 @ IWRAM+0x3964
.L081314A8:
	ldr r1, .L081314BC
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r0, #3
	cmp r0, #0
	blt .L081314C0
	ldrh r0, [r1]
	subs r0, #3
	strh r0, [r1]
	b .L081314C2
.L081314BC: .4byte 0x03006940 @ IWRAM+0x6940
.L081314C0:
	strh r6, [r1]
.L081314C2:
	ldrh r0, [r1]
	bl CasinoPrize_DrawList
	b .L08131580
.L081314CA:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08131510
	cmp r2, #2
	beq .L081314DE
	movs r0, #2
	strh r0, [r5]
	b .L08131684
.L081314DE:
	movs r3, #0
	ldrsh r2, [r5, r3]
	ldr r3, .L08131508
	movs r5, #0
	ldrsh r0, [r3, r5]
	adds r2, r2, r0
	ldr r1, .L0813150C
	lsls r0, r7, #5
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #2
	adds r1, r3, #0
	cmp r2, r0
	bge .L081314FE
	ldrh r0, [r1]
	adds r0, #3
.L081314FE:
	strh r0, [r1]
	ldrh r0, [r1]
	bl CasinoPrize_DrawList
	b .L08131580
.L08131508: .4byte 0x03006940 @ IWRAM+0x6940
.L0813150C: .4byte gUnknown_0878FEA8
.L08131510:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L08131540
	cmp r2, #0
	beq .L08131520
	subs r0, r3, #1
	b .L0813157E
.L08131520:
	ldr r1, .L0813153C
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne .L0813152E
	b .L08131684
.L0813152E:
	subs r0, r2, #1
	strh r0, [r1]
	ldrh r0, [r1]
	bl CasinoPrize_DrawList
	b .L08131580
	.byte 0x00, 0x00
.L0813153C: .4byte 0x03006940 @ IWRAM+0x6940
.L08131540:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08131588
	cmp r2, #2
	bne .L0813157C
	movs r0, #0
	ldrsh r1, [r5, r0]
	ldr r3, .L08131574
	movs r2, #0
	ldrsh r0, [r3, r2]
	adds r1, r1, r0
	ldr r2, .L08131578
	lsls r0, r7, #5
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt .L08131566
	b .L08131684
.L08131566:
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ldrh r0, [r3]
	bl CasinoPrize_DrawList
	b .L08131580
.L08131574: .4byte 0x03006940 @ IWRAM+0x6940
.L08131578: .4byte gUnknown_0878FEA8
.L0813157C:
	adds r0, r3, #1
.L0813157E:
	strh r0, [r5]
.L08131580:
	movs r0, #0x64
	bl Sound_Play
	b .L08131684
.L08131588:
	ldr r1, .L081315EC
	ldrh r0, [r1]
	movs r3, #1
	adds r2, r3, #0
	ands r2, r0
	cmp r2, #0
	beq .L0813166C
	mov r0, r8
	strh r3, [r0, #0x1c]
	ldr r0, .L081315F0
	strh r6, [r0]
	ldr r7, .L081315F4
	ldr r4, .L081315F8
	movs r1, #0
	ldrsh r0, [r5, r1]
	ldr r3, .L081315FC
	movs r2, #0
	ldrsh r1, [r3, r2]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	mov r1, ip
	lsls r2, r1, #5
	adds r0, r0, r2
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r7]
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #4
	adds r0, r0, r2
	adds r0, r0, r4
	ldrh r6, [r0]
	ldr r0, .L08131600
	cmp r6, r0
	bne .L081315DC
	ldr r6, .L08131604
.L081315DC:
	bl sub_080C31F0
	cmp r0, r6
	bhs .L08131610
	ldr r0, .L08131608
	ldr r1, .L0813160C
	ldr r1, [r1]
	b .L08131634
.L081315EC: .4byte 0x030031C4 @ IWRAM+0x31C4
.L081315F0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L081315F4: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L081315F8: .4byte gUnknown_0878FEA8
.L081315FC: .4byte 0x03006940 @ IWRAM+0x6940
.L08131600: .4byte 0x0000FFFF
.L08131604: .4byte 0x000186A0
.L08131608: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813160C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08131610:
	ldrh r0, [r7]
	bl Inventory_GetCount
	adds r4, r0, #0
	ldrh r1, [r7]
	movs r0, #0xff
	bl Party_CountEquipped
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r0
	cmp r4, #0x62
	ble .L08131648
	ldr r0, .L08131640
	ldr r1, .L08131644
	ldr r1, [r1, #4]
.L08131634:
	str r1, [r0]
	movs r0, #0x66
	bl Sound_Play
	b .L08131684
	.byte 0x00, 0x00
.L08131640: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08131644: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08131648:
	ldrh r0, [r7]
	bl Inventory_AddItem
	rsbs r0, r6, #0
	bl sub_080C31B4
	ldr r1, .L08131664
	ldr r0, .L08131668
	ldr r0, [r0, #8]
	str r0, [r1]
	movs r0, #0x65
	bl Sound_Play
	b .L08131684
.L08131664: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08131668: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813166C:
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08131684
	mov r0, r8
	strh r3, [r0, #0x1c]
	ldr r0, .L08131690
	strh r2, [r0]
	movs r0, #0x66
	bl Sound_Play
.L08131684:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08131690: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
