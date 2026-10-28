	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_0812E47C
sub_0812E47C: @ 0x0812E47C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_080C2C30
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0812E49C
	b .L0812E4B6
.L0812E48C:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldrb r2, [r4]
	movs r1, #0
	bl sub_0812E6C4
	movs r0, #1
	b .L0812E4B8
.L0812E49C:
	ldr r4, .L0812E4A0
	b .L0812E4B0
.L0812E4A0: .4byte gUnknown_0877A509
.L0812E4A4:
	ldrb r0, [r4]
	bl sub_080C10B4
	cmp r0, #0
	bne .L0812E48C
	adds r4, #1
.L0812E4B0:
	ldrb r0, [r4]
	cmp r0, #0xff
	bne .L0812E4A4
.L0812E4B6:
	movs r0, #0
.L0812E4B8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0812E4C0
sub_0812E4C0: @ 0x0812E4C0
.L0812E4C0:
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, .L0812E4DC
	lsls r1, r6, #7
	adds r1, r1, r0
	ldrh r5, [r1, #0x10]
	bl sub_080C2C30
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0812E4FE
	ldr r4, .L0812E4E0
	b .L0812E4F8
	.byte 0x00, 0x00
.L0812E4DC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812E4E0: .4byte gUnknown_0877A50C
.L0812E4E4:
	ldrb r0, [r4]
	bl sub_080C10B4
	cmp r0, #0
	beq .L0812E4F6
	ldrh r0, [r4, #2]
	ands r0, r5
	cmp r0, #0
	bne .L0812E508
.L0812E4F6:
	adds r4, #4
.L0812E4F8:
	ldrb r0, [r4]
	cmp r0, #0xff
	bne .L0812E4E4
.L0812E4FE:
	bl sub_080F31E0
	cmp r0, #0
	beq .L0812E526
	b .L0812E54E
.L0812E508:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	ldrb r2, [r4]
	movs r1, #0
	bl sub_0812E6C4
	movs r0, #1
	b .L0812E550
.L0812E518:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	ldrb r2, [r4]
	bl sub_0812E688
	movs r0, #1
	b .L0812E550
.L0812E526:
	ldr r4, .L0812E52C
	b .L0812E548
	.byte 0x00, 0x00
.L0812E52C: .4byte gUnknown_0877A52C
.L0812E530:
	ldrb r0, [r4]
	bl sub_0812E558
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0812E546
	ldrh r0, [r4, #2]
	ands r0, r5
	cmp r0, #0
	bne .L0812E518
.L0812E546:
	adds r4, #4
.L0812E548:
	ldrb r0, [r4]
	cmp r0, #0xff
	bne .L0812E530
.L0812E54E:
	movs r0, #0
.L0812E550:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0812E558
sub_0812E558: @ 0x0812E558
.L0812E558:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r6, #0
	movs r1, #1
	rsbs r1, r1, #0
	add r0, sp, #0x14
.L0812E570:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge .L0812E570
	movs r5, #4
	lsls r0, r6, #2
	mov r1, sp
	adds r7, r0, r1
.L0812E580:
	lsls r0, r5, #7
	ldr r1, .L0812E5B4
	adds r4, r0, r1
	adds r0, r5, #0
	bl Combatant_IsInParty
	cmp r0, #0
	beq .L0812E5D2
	adds r0, r5, #0
	bl Combatant_GetStatus
	ldr r2, .L0812E5B8
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	bne .L0812E5D2
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x5d
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0xff
	beq .L0812E5BC
	ldrb r0, [r3]
	b .L0812E5CA
	.byte 0x00, 0x00
.L0812E5B4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812E5B8: .4byte 0x0000B063
.L0812E5BC:
	adds r2, #1
	cmp r2, #7
	bgt .L0812E5D2
	adds r1, r3, r2
	ldrb r0, [r1]
	cmp r0, #0xff
	beq .L0812E5BC
.L0812E5CA:
	cmp r0, r8
	bne .L0812E5BC
	stm r7!, {r5}
	adds r6, #1
.L0812E5D2:
	adds r5, #1
	cmp r5, #0xf
	ble .L0812E580
	movs r5, #1
	lsls r0, r6, #2
	mov r1, sp
	adds r7, r0, r1
.L0812E5E0:
	lsls r0, r5, #7
	ldr r1, .L0812E618
	adds r4, r0, r1
	adds r0, r5, #0
	bl Combatant_IsInParty
	adds r2, r5, #1
	mov sb, r2
	cmp r0, #0
	beq .L0812E636
	adds r0, r5, #0
	bl Combatant_GetStatus
	ldr r2, .L0812E61C
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	bne .L0812E636
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x5d
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0xff
	beq .L0812E620
	ldrb r0, [r3]
	b .L0812E62E
	.byte 0x00, 0x00
.L0812E618: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812E61C: .4byte 0x0000B063
.L0812E620:
	adds r2, #1
	cmp r2, #0x1f
	bgt .L0812E636
	adds r1, r3, r2
	ldrb r0, [r1]
	cmp r0, #0xff
	beq .L0812E620
.L0812E62E:
	cmp r0, r8
	bne .L0812E620
	stm r7!, {r5}
	adds r6, #1
.L0812E636:
	mov r5, sb
	cmp r5, #3
	ble .L0812E5E0
	cmp r6, #0
	bne .L0812E646
	b .L0812E670
.L0812E642:
	ldr r0, [r5]
	b .L0812E674
.L0812E646:
	movs r6, #0
	mov r5, sp
.L0812E64A:
	ldr r1, [r5]
	movs r7, #1
	rsbs r7, r7, #0
	cmp r1, r7
	beq .L0812E668
	lsls r1, r1, #7
	ldr r0, .L0812E684
	adds r4, r1, r0
	movs r0, #0x1c
	ldrsh r4, [r4, r0]
	mov r0, r8
	bl sub_080ED6CC
	cmp r4, r0
	bhs .L0812E642
.L0812E668:
	adds r5, #4
	adds r6, #1
	cmp r6, #5
	ble .L0812E64A
.L0812E670:
	movs r0, #1
	rsbs r0, r0, #0
.L0812E674:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0812E684: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_0812E688
sub_0812E688: @ 0x0812E688
.L0812E688:
	push {r4, r5, lr}
	sub sp, #0x20
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	str r4, [sp]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #4]
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	mov r0, sp
	adds r1, r5, #0
	bl sub_080F4988
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080ED6DC
	ldr r1, .L0812E6C0
	movs r0, #1
	strh r0, [r1]
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812E6C0: .4byte 0x030020B4 @ IWRAM+0x20B4

	thumb_func_start sub_0812E6C4
sub_0812E6C4: @ 0x0812E6C4
.L0812E6C4:
	push {r4, r5, r6, lr}
	sub sp, #0x24
	lsls r2, r2, #0x10
	ldr r6, .L0812E6F4
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	str r1, [sp]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #4]
	lsrs r5, r2, #0x10
	asrs r4, r2, #0x10
	add r2, sp, #0x20
	adds r0, r4, #0
	movs r1, #0xc
	bl Item_GetAttribute
	ldr r1, [sp, #0x20]
	cmp r1, #0x7f
	bgt .L0812E6F8
	mov r0, sp
	bl sub_080F4988
	b .L0812E700
.L0812E6F4: .4byte 0x0000FFFF
.L0812E6F8:
	mov r0, sp
	adds r1, r4, #0
	bl Item_RunUseEffect
.L0812E700:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	adds r4, r0, #0
	cmp r1, #0xb5
	bne .L0812E718
	bl Random_Byte
	movs r1, #7
	ands r1, r0
	cmp r1, #0
	beq .L0812E718
	movs r6, #0
.L0812E718:
	asrs r0, r4, #0x10
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	bl sub_080F3E54
	ldr r1, .L0812E730
	movs r0, #1
	strh r0, [r1]
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0812E730: .4byte 0x030020B4 @ IWRAM+0x20B4

	thumb_func_start sub_0812E734
sub_0812E734: @ 0x0812E734
.L0812E734:
	push {r4, r5, lr}
	ldr r4, .L0812E75C
	ldr r0, .L0812E760
	ldr r1, .L0812E764
	bl Task_Create
	str r0, [r4, #0x48]
	ldr r0, .L0812E768
	adds r4, r4, r0
	movs r5, #0
	movs r0, #0xfe
	strb r0, [r4]
	bl sub_080EA210
	ldr r0, .L0812E76C
	strb r5, [r0, #1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812E75C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812E760: .4byte gUnknown_0877A54C
.L0812E764: .4byte 0x0000FFFF
.L0812E768: .4byte 0x00000692
.L0812E76C: .4byte 0x030065CC @ IWRAM+0x65CC

	thumb_func_start sub_0812E770
sub_0812E770: @ 0x0812E770
	push {lr}
	bl BattleMsg_Close
	bl sub_08128EB4
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812E780
sub_0812E780: @ 0x0812E780
.L0812E780:
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	adds r7, r1, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, .L0812E7D0
	movs r1, #2
	ldrsh r0, [r0, r1]
	str r0, [sp, #0x20]
	cmp r3, #1
	bne .L0812E7A2
	add r2, sp, #0x20
	movs r1, #0xc
	bl Item_GetAttribute
.L0812E7A2:
	ldr r1, [sp, #0x20]
	adds r0, r1, #0
	subs r0, #0x2b
	lsls r6, r4, #0x10
	cmp r0, #0x14
	bls .L0812E7B0
	b .L0812E95E
.L0812E7B0:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080F0F68
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #0xf0
	cmp r0, #7
	bls .L0812E7C6
	b .L0812E94A
.L0812E7C6:
	lsls r0, r0, #2
	ldr r1, .L0812E7D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L0812E7D0: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812E7D4: .4byte gUnknown_0812E7D8
	.global gUnknown_0812E7D8
gUnknown_0812E7D8:
.L0812E7D8: @ jump table
	.4byte .L0812E7F8
	.4byte .L0812E826
	.4byte .L0812E854
	.4byte .L0812E880
	.4byte .L0812E8AC
	.4byte .L0812E8D4
	.4byte .L0812E8FC
	.4byte .L0812E924
.L0812E7F8:
	lsls r4, r4, #0x10
	asrs r0, r4, #0xf
	adds r0, r0, r7
	ldrh r0, [r0]
	bl Battle_FindPartyPosition
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	adds r6, r4, #0
	cmp r5, r0
	bne .L0812E814
	b .L0812E94A
.L0812E814:
	movs r0, #4
	bl sub_080ECE08
	adds r0, r5, #0
	movs r1, #0
	movs r2, #3
	bl sub_080ECE38
	b .L0812E94A
.L0812E826:
	lsls r4, r4, #0x10
	asrs r0, r4, #0xf
	adds r0, r0, r7
	ldrh r0, [r0]
	bl Battle_FindPartyPosition
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	adds r6, r4, #0
	cmp r5, r0
	bne .L0812E842
	b .L0812E94A
.L0812E842:
	movs r0, #4
	bl sub_080ECE08
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl sub_080ECE38
	b .L0812E94A
.L0812E854:
	lsls r4, r4, #0x10
	asrs r0, r4, #0xf
	adds r0, r0, r7
	ldrh r0, [r0]
	bl Battle_FindPartyPosition
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	adds r6, r4, #0
	cmp r5, r0
	beq .L0812E94A
	movs r0, #4
	bl sub_080ECE08
	adds r0, r5, #0
	movs r1, #0
	movs r2, #5
	bl sub_080ECE38
	b .L0812E94A
.L0812E880:
	lsls r4, r4, #0x10
	asrs r0, r4, #0xf
	adds r0, r0, r7
	ldrh r0, [r0]
	bl Battle_FindPartyPosition
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	adds r6, r4, #0
	cmp r5, r0
	beq .L0812E94A
	movs r0, #4
	bl sub_080ECE08
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl sub_080ECE38
	b .L0812E94A
.L0812E8AC:
	movs r5, #0
	lsls r6, r4, #0x10
.L0812E8B0:
	movs r0, #5
	bl sub_080ECE08
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #0x1a
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	movs r2, #3
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L0812E8B0
	b .L0812E94A
.L0812E8D4:
	movs r5, #0
	lsls r6, r4, #0x10
.L0812E8D8:
	movs r0, #5
	bl sub_080ECE08
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #0x1a
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	movs r2, #0
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L0812E8D8
	b .L0812E94A
.L0812E8FC:
	movs r5, #0
	lsls r6, r4, #0x10
.L0812E900:
	movs r0, #5
	bl sub_080ECE08
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #0x1a
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	movs r2, #5
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L0812E900
	b .L0812E94A
.L0812E924:
	movs r5, #0
	lsls r6, r4, #0x10
.L0812E928:
	movs r0, #5
	bl sub_080ECE08
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #0x1a
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	movs r2, #1
	bl sub_080ECE38
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble .L0812E928
.L0812E94A:
	ldr r0, [sp, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080F104C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080ECF70
.L0812E95E:
	ldr r0, [sp, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r0, [r0, #2]
	cmp r0, #0x80
	beq .L0812E972
	cmp r0, #0x82
	bne .L0812E97E
.L0812E972:
	asrs r0, r6, #0x10
	str r0, [sp]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	b .L0812E984
.L0812E97E:
	asrs r0, r6, #0x10
	str r0, [sp]
	movs r0, #0x10
.L0812E984:
	str r0, [sp, #4]
	ldr r1, [sp, #0x20]
	mov r0, sp
	bl sub_080F4988
	bl sub_080C84A0
	ldr r1, .L0812E9C4
	movs r0, #0
	strh r0, [r1]
	ldr r0, [sp, #0xc]
	cmp r0, #1
	bne .L0812EA14
	ldr r1, [sp, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0812E9D4
	ldr r0, [sp, #0x20]
	subs r0, #0x1d
	ldr r1, .L0812E9C8
	lsls r0, r0, #0x11
	asrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, .L0812E9CC
	cmp r1, r0
	beq .L0812E9F2
	ldr r0, .L0812E9D0
	ands r1, r0
	b .L0812E9D8
	.byte 0x00, 0x00
.L0812E9C4: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812E9C8: .4byte gUnknown_0876F9CC
.L0812E9CC: .4byte 0x0000FFFF
.L0812E9D0: .4byte 0x00007FFF
.L0812E9D4:
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
.L0812E9D8:
	ldr r0, .L0812EA0C
	cmp r1, r0
	beq .L0812E9F2
	adds r0, r1, #0
	bl Battle_GetMessage
	ldr r1, [sp, #4]
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
.L0812E9F2:
	ldr r0, [sp, #0x20]
	adds r2, r0, #0
	cmp r2, #0x3a
	bne .L0812EA00
	ldr r1, .L0812EA10
	movs r0, #1
	strh r0, [r1]
.L0812EA00:
	cmp r2, #0x3b
	bne .L0812EA4A
	ldr r1, .L0812EA10
	movs r0, #2
	strh r0, [r1]
	b .L0812EA4A
.L0812EA0C: .4byte 0x0000FFFF
.L0812EA10: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812EA14:
	ldr r1, [sp, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0812EA34
	ldr r0, .L0812EA30
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	b .L0812EA4A
.L0812EA30: .4byte gUnknown_08124534
.L0812EA34:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
.L0812EA4A:
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812EA54
sub_0812EA54: @ 0x0812EA54
.L0812EA54:
	push {r4, r5, lr}
	movs r4, #0
	ldr r0, .L0812EA84
	adds r5, r0, #0
.L0812EA5C:
	adds r0, r4, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L0812EA88
	adds r0, r4, #0
	bl Combatant_IsInParty
	cmp r0, #0
	beq .L0812EA88
	adds r0, r4, #0
	bl Combatant_GetStatus
	ands r0, r5
	cmp r0, #0
	bne .L0812EA88
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	b .L0812EA92
	.byte 0x00, 0x00
.L0812EA84: .4byte 0x0000B060
.L0812EA88:
	adds r4, #1
	cmp r4, #3
	ble .L0812EA5C
	movs r0, #1
	rsbs r0, r0, #0
.L0812EA92:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_0812EA98
sub_0812EA98: @ 0x0812EA98
.L0812EA98:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x28
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r6, .L0812EAE4
	ldr r0, .L0812EAE8
	movs r1, #2
	ldrsh r0, [r0, r1]
	str r0, [sp, #0x24]
	add r4, sp, #0x24
	ldrh r0, [r4]
	bl Action_GetRecord
	ldrb r0, [r0, #3]
	mov r8, r0
	add r2, sp, #0x20
	ldr r0, [sp, #0x24]
	movs r1, #0xc
	bl Item_GetAttribute
	ldr r0, [sp, #0x24]
	lsls r0, r0, #2
	ldr r1, .L0812EAEC
	adds r7, r0, r1
	ldrb r0, [r7]
	subs r0, #0xf0
	mov sb, r4
	cmp r0, #7
	bls .L0812EADA
	b .L0812EC64
.L0812EADA:
	lsls r0, r0, #2
	ldr r1, .L0812EAF0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L0812EAE4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812EAE8: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812EAEC: .4byte gUnknown_0876E2D8
.L0812EAF0: .4byte gUnknown_0812EAF4
	.global gUnknown_0812EAF4
gUnknown_0812EAF4:
.L0812EAF4: @ jump table
	.4byte .L0812EB14
	.4byte .L0812EB48
	.4byte .L0812EB7A
	.4byte .L0812EBAC
	.4byte .L0812EBDE
	.4byte .L0812EC00
	.4byte .L0812EC22
	.4byte .L0812EC44
.L0812EB14:
	lsls r1, r5, #0x10
	asrs r1, r1, #0xf
	movs r2, #0xf3
	lsls r2, r2, #4
	adds r0, r6, r2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	bl Battle_FindPartyPosition
	adds r4, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L0812EB34
	b .L0812EC64
.L0812EB34:
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #3
	bl sub_080ECE38
	b .L0812EC64
.L0812EB48:
	lsls r1, r5, #0x10
	asrs r1, r1, #0xf
	movs r2, #0xf3
	lsls r2, r2, #4
	adds r0, r6, r2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	bl Battle_FindPartyPosition
	adds r4, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0812EC64
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #0
	bl sub_080ECE38
	b .L0812EC64
.L0812EB7A:
	lsls r1, r5, #0x10
	asrs r1, r1, #0xf
	movs r2, #0xf3
	lsls r2, r2, #4
	adds r0, r6, r2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	bl Battle_FindPartyPosition
	adds r4, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0812EC64
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #5
	bl sub_080ECE38
	b .L0812EC64
.L0812EBAC:
	lsls r1, r5, #0x10
	asrs r1, r1, #0xf
	movs r2, #0xf3
	lsls r2, r2, #4
	adds r0, r6, r2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	bl Battle_FindPartyPosition
	adds r4, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0812EC64
	movs r0, #4
	bl sub_080ECE08
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	movs r2, #1
	bl sub_080ECE38
	b .L0812EC64
.L0812EBDE:
	movs r4, #0
.L0812EBE0:
	movs r0, #5
	bl sub_080ECE08
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r4, #0x1a
	lsrs r1, r1, #0x18
	movs r2, #3
	bl sub_080ECE38
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #5
	bls .L0812EBE0
	b .L0812EC64
.L0812EC00:
	movs r4, #0
.L0812EC02:
	movs r0, #5
	bl sub_080ECE08
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r4, #0x1a
	lsrs r1, r1, #0x18
	movs r2, #0
	bl sub_080ECE38
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #5
	bls .L0812EC02
	b .L0812EC64
.L0812EC22:
	movs r4, #0
.L0812EC24:
	movs r0, #5
	bl sub_080ECE08
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r4, #0x1a
	lsrs r1, r1, #0x18
	movs r2, #5
	bl sub_080ECE38
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #5
	bls .L0812EC24
	b .L0812EC64
.L0812EC44:
	movs r4, #0
.L0812EC46:
	movs r0, #5
	bl sub_080ECE08
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r4, #0x1a
	lsrs r1, r1, #0x18
	movs r2, #1
	bl sub_080ECE38
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #5
	bls .L0812EC46
.L0812EC64:
	ldrh r0, [r7, #2]
	bl sub_080ECF70
	mov r0, r8
	cmp r0, #0x80
	beq .L0812EC78
	cmp r0, #0x82
	beq .L0812EC78
	cmp r0, #0x83
	bne .L0812EC9C
.L0812EC78:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	str r1, [sp]
	lsls r1, r1, #1
	movs r2, #0xf3
	lsls r2, r2, #4
	adds r0, r6, r2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	b .L0812ECA6
.L0812EC9C:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
.L0812ECA6:
	mov r0, sp
	ldr r1, [sp, #0x24]
	bl Item_RunUseEffect
	bl sub_080C84A0
	ldr r0, [sp, #0xc]
	cmp r0, #1
	bne .L0812ED10
	ldr r0, [sp, #0x24]
	bl sub_080F3E38
	ldr r0, [sp, #0x24]
	movs r1, #0xc
	mov r2, sb
	bl Item_GetAttribute
	ldr r1, [sp, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0812ECE8
	ldr r0, [sp, #0x24]
	subs r0, #0x80
	ldr r1, .L0812ECE4
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	b .L0812ECEC
	.byte 0x00, 0x00
.L0812ECE4: .4byte gUnknown_0876FAE4
.L0812ECE8:
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
.L0812ECEC:
	ldr r0, .L0812ED08
	cmp r1, r0
	beq .L0812ED46
	adds r0, r1, #0
	bl Battle_GetMessage
	ldr r1, .L0812ED0C
	movs r3, #2
	ldrsh r2, [r1, r3]
	lsls r2, r2, #0x10
	ldr r1, [sp, #4]
	adds r1, r1, r2
	b .L0812ED1E
	.byte 0x00, 0x00
.L0812ED08: .4byte 0x0000FFFF
.L0812ED0C: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812ED10:
	ldr r1, [sp, #8]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0812ED30
	ldr r0, .L0812ED2C
	movs r1, #0
.L0812ED1E:
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	b .L0812ED46
.L0812ED2C: .4byte gUnknown_08124534
.L0812ED30:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
.L0812ED46:
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0812ED54
sub_0812ED54: @ 0x0812ED54
	push {lr}
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0

	thumb_func_start sub_0812ED60
sub_0812ED60: @ 0x0812ED60
	push {lr}
	ldr r2, .L0812ED84
	ldrh r0, [r0, #0x1e]
	lsls r0, r0, #1
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r1, r2, r3
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, .L0812ED88
	adds r2, r2, r1
	strh r0, [r2]
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812ED84: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812ED88: .4byte 0x000011A2

	thumb_func_start sub_0812ED8C
sub_0812ED8C: @ 0x0812ED8C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r4, .L0812EDE4
	movs r5, #1
	str r5, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r4, #0x4c]
	str r5, [sp]
	movs r0, #0x11
	movs r1, #0
	movs r2, #0xc
	movs r3, #6
	bl TextWindow_Create
	str r0, [r4, #0x50]
	bl sub_081272AC
	ldr r0, .L0812EDE8
	adds r4, r4, r0
	ldrb r0, [r4]
	bl sub_0812A668
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #2
	bl sub_081269B0
	cmp r4, #4
	bhi .L0812EDEC
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #1
	adds r3, r4, #0
	bl sub_08126928
	b .L0812EDFC
	.byte 0x00, 0x00
.L0812EDE4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812EDE8: .4byte 0x00000697
.L0812EDEC:
	movs r0, #5
	str r0, [sp]
	movs r0, #2
	movs r1, #0x10
	movs r2, #1
	adds r3, r4, #0
	bl sub_08126928
.L0812EDFC:
	ldrb r0, [r6, #6]
	cmp r0, #0
	beq .L0812EE1A
	cmp r0, #1
	bne .L0812EE1A
	bl sub_080EA210
	ldr r0, .L0812EE24
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #4
	bl BattleMenu_SetMode
.L0812EE1A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812EE24: .4byte gUnknown_08124D72

	thumb_func_start sub_0812EE28
sub_0812EE28: @ 0x0812EE28
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0812EE60
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812EE3A
	movs r1, #0
	bl TextWindow_Close
.L0812EE3A:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812EE46
	movs r1, #0
	bl TextWindow_Close
.L0812EE46:
	bl sub_08128388
	ldrb r0, [r5, #6]
	cmp r0, #0
	beq .L0812EE58
	cmp r0, #1
	bne .L0812EE58
	bl BattleMsg_Close
.L0812EE58:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812EE60: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812EE64
sub_0812EE64: @ 0x0812EE64
	push {lr}
	ldrb r1, [r0, #6]
	cmp r1, #0
	bne .L0812EE7A
	bl sub_080C700C
	bl sub_080C7430
	bl sub_080C7648
	b .L0812EE86
.L0812EE7A:
	cmp r1, #1
	bne .L0812EE86
	bl Task_GetParent
	bl Task_Signal
.L0812EE86:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812EE8C
sub_0812EE8C: @ 0x0812EE8C
.L0812EE8C:
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r2, .L0812EEBC
	cmp r1, #0
	beq .L0812EE98
	ldrh r2, [r1, #2]
.L0812EE98:
	ldr r0, .L0812EEC0
	adds r1, r2, #0
	bl Task_Create
	adds r4, r0, #0
	strb r5, [r4, #6]
	cmp r5, #0
	bne .L0812EEB4
	bl sub_080C6FF0
	bl sub_080C7414
	bl sub_080C762C
.L0812EEB4:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
.L0812EEBC: .4byte 0x0000FFFF
.L0812EEC0: .4byte gUnknown_0877A580

	thumb_func_start sub_0812EEC4
sub_0812EEC4: @ 0x0812EEC4
.L0812EEC4:
	ldr r0, .L0812EED0
	ldr r1, .L0812EED4
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L0812EED0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812EED4: .4byte 0x000011A2

	thumb_func_start sub_0812EED8
sub_0812EED8: @ 0x0812EED8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r4, .L0812EEFC
	ldr r1, .L0812EF00
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r6, r1, #0
	ldr r2, .L0812EF04
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0812EF1C
	cmp r0, #1
	bgt .L0812EF08
	cmp r0, #0
	beq .L0812EF12
	b .L0812EF76
	.byte 0x00, 0x00
.L0812EEFC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812EF00: .4byte 0x00000692
.L0812EF04: .4byte 0x00000694
.L0812EF08:
	cmp r0, #2
	beq .L0812EF64
	cmp r0, #3
	beq .L0812EF1C
	b .L0812EF76
.L0812EF12:
	movs r7, #0xef
	lsls r7, r7, #4
	adds r0, r4, r7
	strh r1, [r0]
	b .L0812EF6C
.L0812EF1C:
	ldr r2, .L0812EF5C
	ldr r7, .L0812EF60
	adds r3, r4, r7
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r7, #0xa2
	lsls r7, r7, #4
	adds r2, r2, r7
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #1
	movs r7, #0xef
	lsls r7, r7, #4
	adds r0, r4, r7
	adds r0, r0, r1
	strh r6, [r0]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	movs r2, #0xf1
	lsls r2, r2, #4
	adds r1, r4, r2
	adds r1, r1, r0
	ldrh r0, [r5, #0x1e]
	strh r0, [r1]
	b .L0812EF76
	.byte 0x00, 0x00
.L0812EF5C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812EF60: .4byte 0x00000F66
.L0812EF64:
	movs r7, #0xef
	lsls r7, r7, #4
	adds r0, r4, r7
	strh r6, [r0]
.L0812EF6C:
	ldrh r1, [r5, #0x1e]
	movs r2, #0xf1
	lsls r2, r2, #4
	adds r0, r4, r2
	strh r1, [r0]
.L0812EF76:
	movs r0, #0
	strh r0, [r5, #0x1e]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0812EF80
sub_0812EF80: @ 0x0812EF80
	push {lr}
	movs r0, #3
	bl sub_081269B0
	pop {r0}
	bx r0

	thumb_func_start sub_0812EF8C
sub_0812EF8C: @ 0x0812EF8C
.L0812EF8C:
	push {r4, lr}
	ldr r1, .L0812EFAC
	ldr r3, .L0812EFB0
	cmp r0, #0
	beq .L0812EF98
	ldrh r3, [r0, #2]
.L0812EF98:
	ldr r0, [r1, #0x48]
	adds r0, #0x24
	ldrb r2, [r0]
	cmp r2, #0
	bne .L0812EFB8
	ldr r4, .L0812EFB4
	adds r0, r1, r4
	strb r2, [r0]
	b .L0812EFC0
	.byte 0x00, 0x00
.L0812EFAC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812EFB0: .4byte 0x0000FFFF
.L0812EFB4: .4byte 0x00000694
.L0812EFB8:
	ldr r0, .L0812EFD0
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
.L0812EFC0:
	ldr r0, .L0812EFD4
	adds r1, r3, #0
	bl Task_Create
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0812EFD0: .4byte 0x00000694
.L0812EFD4: .4byte gUnknown_0877A774

	thumb_func_start sub_0812EFD8
sub_0812EFD8: @ 0x0812EFD8
	push {lr}
	ldr r0, .L0812F004
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0812F000
	ldr r1, .L0812F008
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0812F000
	movs r0, #0x1e
	strh r0, [r1]
	ldr r2, .L0812F00C
	ldrh r0, [r2]
	movs r1, #1
	eors r0, r1
	strh r0, [r2]
.L0812F000:
	pop {r0}
	bx r0
.L0812F004: .4byte 0x0203DB56 @ EWRAM+0x3DB56
.L0812F008: .4byte 0x0203DB54 @ EWRAM+0x3DB54
.L0812F00C: .4byte 0x0203DB52 @ EWRAM+0x3DB52

	thumb_func_start sub_0812F010
sub_0812F010: @ 0x0812F010
.L0812F010:
	push {lr}
	ldr r0, .L0812F030
	movs r1, #0
	ldrsh r2, [r0, r1]
	cmp r2, #0
	bne .L0812F070
	ldr r0, .L0812F034
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0
	bne .L0812F03C
	ldr r0, .L0812F038
	strh r2, [r0]
	b .L0812F042
	.byte 0x00, 0x00
.L0812F030: .4byte 0x03006844 @ IWRAM+0x6844
.L0812F034: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F038: .4byte 0x03006848 @ IWRAM+0x6848
.L0812F03C:
	ldr r1, .L0812F060
	movs r0, #1
	strh r0, [r1]
.L0812F042:
	ldr r1, .L0812F064
	movs r2, #0
	ldrsh r0, [r3, r2]
	adds r0, #4
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, .L0812F068
	cmp r1, r0
	bne .L0812F058
	b .L0812F168
.L0812F058:
	ldr r1, .L0812F06C
	movs r0, #1
	b .L0812F16C
	.byte 0x00, 0x00
.L0812F060: .4byte 0x03006848 @ IWRAM+0x6848
.L0812F064: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F068: .4byte 0x0000FFFF
.L0812F06C: .4byte 0x03006680 @ IWRAM+0x6680
.L0812F070:
	cmp r2, #1
	beq .L0812F078
	cmp r2, #4
	bne .L0812F0C4
.L0812F078:
	ldr r0, .L0812F08C
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0
	bne .L0812F094
	ldr r0, .L0812F090
	strh r1, [r0]
	b .L0812F09A
	.byte 0x00, 0x00
.L0812F08C: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F090: .4byte 0x03006848 @ IWRAM+0x6848
.L0812F094:
	ldr r1, .L0812F0B4
	movs r0, #1
	strh r0, [r1]
.L0812F09A:
	ldr r1, .L0812F0B8
	movs r2, #0
	ldrsh r0, [r3, r2]
	adds r0, #3
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, .L0812F0BC
	cmp r1, r0
	beq .L0812F168
	ldr r1, .L0812F0C0
	movs r0, #1
	b .L0812F16C
.L0812F0B4: .4byte 0x03006848 @ IWRAM+0x6848
.L0812F0B8: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F0BC: .4byte 0x0000FFFF
.L0812F0C0: .4byte 0x03006680 @ IWRAM+0x6680
.L0812F0C4:
	cmp r2, #2
	bne .L0812F118
	ldr r0, .L0812F0DC
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #1
	bgt .L0812F0E4
	ldr r1, .L0812F0E0
	movs r0, #0
	b .L0812F0E8
	.byte 0x00, 0x00
.L0812F0DC: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F0E0: .4byte 0x03006848 @ IWRAM+0x6848
.L0812F0E4:
	ldr r1, .L0812F108
	movs r0, #1
.L0812F0E8:
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r0, #8
	cmp r0, #0xf
	bgt .L0812F168
	ldr r1, .L0812F10C
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, .L0812F110
	cmp r1, r0
	beq .L0812F168
	ldr r1, .L0812F114
	movs r0, #1
	b .L0812F16C
.L0812F108: .4byte 0x03006848 @ IWRAM+0x6848
.L0812F10C: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F110: .4byte 0x0000FFFF
.L0812F114: .4byte 0x03006680 @ IWRAM+0x6680
.L0812F118:
	ldr r0, .L0812F12C
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, r0, #0
	cmp r1, #1
	bgt .L0812F134
	ldr r1, .L0812F130
	movs r0, #0
	b .L0812F138
	.byte 0x00, 0x00
.L0812F12C: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F130: .4byte 0x03006848 @ IWRAM+0x6848
.L0812F134:
	ldr r1, .L0812F158
	movs r0, #1
.L0812F138:
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r0, #6
	cmp r0, #0xf
	bgt .L0812F168
	ldr r1, .L0812F15C
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, .L0812F160
	cmp r1, r0
	beq .L0812F168
	ldr r1, .L0812F164
	movs r0, #1
	b .L0812F16C
.L0812F158: .4byte 0x03006848 @ IWRAM+0x6848
.L0812F15C: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F160: .4byte 0x0000FFFF
.L0812F164: .4byte 0x03006680 @ IWRAM+0x6680
.L0812F168:
	ldr r1, .L0812F174
	movs r0, #0
.L0812F16C:
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812F174: .4byte 0x03006680 @ IWRAM+0x6680

	thumb_func_start sub_0812F178
sub_0812F178: @ 0x0812F178
	movs r1, #0
	strh r1, [r0, #0x1c]
	ldr r0, .L0812F184
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L0812F184: .4byte 0x0300696C @ IWRAM+0x696C

	thumb_func_start sub_0812F188
sub_0812F188: @ 0x0812F188
.L0812F188:
	lsls r0, r0, #0x10
	ldr r1, .L0812F194
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
.L0812F194: .4byte gUnknown_0878FC6A

	thumb_func_start sub_0812F198
sub_0812F198: @ 0x0812F198
.L0812F198:
	push {r4, r5, r6, lr}
	movs r2, #0
	ldr r3, .L0812F1D4
	ldr r6, .L0812F1D8
	ldrh r0, [r3]
	cmp r2, r0
	bhs .L0812F1C6
	adds r5, r6, #0
	ldr r4, .L0812F1DC
.L0812F1AA:
	lsls r1, r2, #1
	adds r1, r1, r5
	lsls r0, r2, #3
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r3]
	cmp r2, r0
	bhs .L0812F1C6
	cmp r2, #0xf
	bls .L0812F1AA
.L0812F1C6:
	lsls r0, r2, #1
	adds r0, r0, r6
	ldr r1, .L0812F1E0
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0812F1D4: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0812F1D8: .4byte 0x03006870 @ IWRAM+0x6870
.L0812F1DC: .4byte 0x0203D800 @ EWRAM+0x3D800
.L0812F1E0: .4byte 0x00000301

	thumb_func_start sub_0812F1E4
sub_0812F1E4: @ 0x0812F1E4
.L0812F1E4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r6, #0
	ldr r0, .L0812F298
	ldrh r1, [r0]
	lsls r1, r1, #0x12
	lsrs r3, r1, #0x10
	ldr r1, .L0812F29C
	ldrh r4, [r1]
	ldr r2, .L0812F2A0
	mov sb, r0
	cmp r4, r2
	beq .L0812F28A
	ldr r5, .L0812F2A4
	ldr r7, .L0812F2A8
	movs r0, #0xd
	mov r8, r0
	mov ip, sb
	mov sl, r2
.L0812F210:
	adds r1, r3, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r2, r3, #0
	lsls r1, r1, #1
	adds r1, r1, r5
	strh r4, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r0, [r7]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x11
	strh r0, [r2]
	adds r1, r3, #1
	lsls r1, r1, #0x10
	lsls r3, r3, #1
	adds r3, r3, r5
	ldr r2, .L0812F2AC
	ldrh r0, [r2]
	mov r4, r8
	muls r4, r0, r4
	adds r0, r4, #0
	ldr r2, .L0812F2B0
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r3]
	lsrs r1, r1, #0xf
	adds r1, r1, r5
	movs r4, #0
	strh r4, [r1]
	mov r1, ip
	ldrh r0, [r1]
	cmp r0, #0x3e
	bhi .L0812F266
	adds r0, #1
	mov r2, sb
	strh r0, [r2]
.L0812F266:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0xf
	bhi .L0812F28A
	mov r4, ip
	ldrh r0, [r4]
	lsls r0, r0, #0x12
	lsrs r3, r0, #0x10
	lsls r0, r6, #1
	ldr r1, .L0812F29C
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, sl
	bne .L0812F210
.L0812F28A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0812F298: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0812F29C: .4byte 0x03006870 @ IWRAM+0x6870
.L0812F2A0: .4byte 0x00000301
.L0812F2A4: .4byte 0x0203D800 @ EWRAM+0x3D800
.L0812F2A8: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0812F2AC: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0812F2B0: .4byte 0x03006614 @ IWRAM+0x6614

	thumb_func_start sub_0812F2B4
sub_0812F2B4: @ 0x0812F2B4
.L0812F2B4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #0xc]
	bl sub_080C3100
	str r0, [sp, #0x10]
	ldr r1, .L0812F38C
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, .L0812F390
	ldrh r4, [r0]
	ldr r0, .L0812F394
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r0, .L0812F398
	mov r2, sp
	ldrh r2, [r2, #0xc]
	strh r2, [r0]
	ldr r0, .L0812F39C
	mov r3, sp
	ldrh r3, [r3, #0xc]
	strh r3, [r0]
	ldr r0, .L0812F3A0
	mov r5, sp
	ldrh r5, [r5, #0xc]
	strh r5, [r0]
	ldr r0, .L0812F3A4
	mov r7, sp
	ldrh r7, [r7, #0xc]
	strh r7, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L0812F3A8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq .L0812F31C
	cmp r0, #3
	beq .L0812F31C
	cmp r0, #4
	bne .L0812F320
.L0812F31C:
	bl sub_0812F1E4
.L0812F320:
	movs r2, #0
	mov sb, r2
	ldr r1, .L0812F3AC
	lsls r2, r4, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	ldr r3, .L0812F3B0
	adds r5, r1, #0
	cmp r0, r3
	bne .L0812F336
	b .L0812F50C
.L0812F336:
	lsls r6, r6, #5
	str r6, [sp, #0x14]
.L0812F33A:
	ldr r3, [sp]
	lsls r0, r3, #1
	ldr r7, [sp, #0x14]
	adds r0, r0, r7
	ldr r1, .L0812F3B4
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r7, .L0812F3B0
	cmp r0, r7
	bne .L0812F350
	b .L0812F50C
.L0812F350:
	adds r0, r3, #0
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	adds r1, r0, #0
	lsls r0, r3, #1
	ldr r3, [sp, #0x14]
	adds r0, r0, r3
	ldr r7, .L0812F3B4
	adds r0, r0, r7
	ldrh r6, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsls r1, r1, #1
	adds r1, r1, r3
	adds r1, r1, r7
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldr r0, .L0812F3B8
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0812F3C0
	ldr r0, .L0812F3BC
	ldr r1, .L0812F394
	str r0, [r1]
	b .L0812F3E2
	.byte 0x00, 0x00
.L0812F38C: .4byte 0x030068B8 @ IWRAM+0x68B8
.L0812F390: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F394: .4byte 0x03006950 @ IWRAM+0x6950
.L0812F398: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0812F39C: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0812F3A0: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0812F3A4: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0812F3A8: .4byte 0x03006844 @ IWRAM+0x6844
.L0812F3AC: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F3B0: .4byte 0x0000FFFF
.L0812F3B4: .4byte gUnknown_0878FBA4
.L0812F3B8: .4byte 0x030069CC @ IWRAM+0x69CC
.L0812F3BC: .4byte gUnknown_08036666
.L0812F3C0:
	ldr r0, .L0812F3D0
	ldrh r0, [r0]
	cmp r0, #1
	bne .L0812F3DC
	ldr r0, .L0812F3D4
	ldr r3, .L0812F3D8
	str r0, [r3]
	b .L0812F3E2
.L0812F3D0: .4byte 0x03006670 @ IWRAM+0x6670
.L0812F3D4: .4byte gUnknown_08036156
.L0812F3D8: .4byte 0x03006950 @ IWRAM+0x6950
.L0812F3DC:
	ldr r0, .L0812F524
	ldr r7, .L0812F528
	str r0, [r7]
.L0812F3E2:
	adds r0, r2, r5
	ldrh r3, [r0]
	lsls r0, r3, #0x11
	ldr r2, .L0812F528
	ldr r1, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	str r0, [sp, #0x18]
	mov r8, r0
	ldr r0, .L0812F52C
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bne .L0812F422
	adds r0, r3, #0
	subs r0, #0x9d
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_0812F188
	str r0, [sp, #0xc]
	ldr r2, [sp, #0x10]
	cmp r2, r0
	bhs .L0812F422
	movs r3, #4
	mov r8, r3
.L0812F422:
	ldr r1, [sp, #0x18]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	ldr r2, .L0812F528
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r3, [r1]
	ldr r0, .L0812F530
	mov r5, sb
	lsls r5, r5, #0x10
	mov ip, r5
	adds r4, #1
	mov sl, r4
	cmp r3, r0
	beq .L0812F4AE
	ldr r5, .L0812F534
	ldr r4, .L0812F538
	mov sb, r0
.L0812F44C:
	ldrh r2, [r5]
	lsls r0, r2, #0x12
	lsrs r0, r0, #0x10
	movs r1, #1
	orrs r1, r0
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r3, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsls r1, r1, #1
	adds r1, r1, r4
	strh r6, [r1]
	movs r7, #0x80
	lsls r7, r7, #9
	adds r1, r0, r7
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	mov r3, sp
	ldrh r3, [r3, #4]
	strh r3, [r0]
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	mov r7, r8
	strh r7, [r1]
	adds r2, #1
	strh r2, [r5]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r2, #0x3f
	bls .L0812F48E
	movs r0, #0x3f
	strh r0, [r5]
.L0812F48E:
	adds r0, r6, #0
	adds r0, #0xd
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r1, [sp, #0x18]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	ldr r2, .L0812F528
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r3, [r1]
	cmp r3, sb
	bne .L0812F44C
.L0812F4AE:
	ldr r3, .L0812F52C
	movs r5, #0
	ldrsh r0, [r3, r5]
	cmp r0, #4
	bne .L0812F4E4
	mov r7, ip
	asrs r4, r7, #0x10
	cmp r4, #2
	bgt .L0812F4E4
	ldr r1, .L0812F53C
	lsls r2, r4, #4
	adds r3, r2, r1
	movs r0, #1
	strh r0, [r3]
	adds r1, #4
	adds r2, r2, r1
	ldr r0, [sp, #0xc]
	str r0, [r2]
	movs r0, #0x80
	strh r0, [r3, #8]
	ldr r1, .L0812F540
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r3, #0xa]
	mov r1, r8
	strh r1, [r3, #0xc]
.L0812F4E4:
	mov r2, sl
	lsls r0, r2, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, ip
	lsrs r3, r0, #0x10
	mov sb, r3
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt .L0812F50C
	ldr r1, .L0812F544
	lsls r2, r4, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r5, r1, #0
	ldr r7, .L0812F548
	cmp r0, r7
	beq .L0812F50C
	b .L0812F33A
.L0812F50C:
	ldr r0, [sp, #8]
	ldr r1, .L0812F528
	str r0, [r1]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812F524: .4byte gUnknown_0803631E
.L0812F528: .4byte 0x03006950 @ IWRAM+0x6950
.L0812F52C: .4byte 0x03006844 @ IWRAM+0x6844
.L0812F530: .4byte 0x00000301
.L0812F534: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0812F538: .4byte 0x0203D800 @ EWRAM+0x3D800
.L0812F53C: .4byte 0x03006620 @ IWRAM+0x6620
.L0812F540: .4byte gUnknown_0878FC64
.L0812F544: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F548: .4byte 0x0000FFFF

	thumb_func_start sub_0812F54C
sub_0812F54C: @ 0x0812F54C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	ldr r4, .L0812F5A4
	ldr r5, .L0812F5A8
	ldr r3, .L0812F5AC
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r1, r1, #2
	ldr r2, .L0812F5B0
	movs r6, #0
	ldrsh r0, [r2, r6]
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r5
	ldrh r0, [r1]
	strh r0, [r4]
	ldr r4, .L0812F5B4
	movs r7, #0
	ldrsh r0, [r3, r7]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	movs r6, #0
	ldrsh r1, [r2, r6]
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r4]
	ldrh r1, [r2]
	subs r0, r1, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r6, r3, #0
	mov ip, r2
	cmp r0, #1
	bhi .L0812F5BC
	ldr r1, .L0812F5B8
	movs r0, #0xa
	b .L0812F5D4
	.byte 0x00, 0x00
.L0812F5A4: .4byte 0x0300689C @ IWRAM+0x689C
.L0812F5A8: .4byte gUnknown_0878FBA4
.L0812F5AC: .4byte 0x0300696C @ IWRAM+0x696C
.L0812F5B0: .4byte 0x03006844 @ IWRAM+0x6844
.L0812F5B4: .4byte 0x0300695C @ IWRAM+0x695C
.L0812F5B8: .4byte 0x030066A0 @ IWRAM+0x66A0
.L0812F5BC:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne .L0812F5D0
	ldr r1, .L0812F5CC
	movs r0, #0x14
	b .L0812F5D4
	.byte 0x00, 0x00
.L0812F5CC: .4byte 0x030066A0 @ IWRAM+0x66A0
.L0812F5D0:
	ldr r1, .L0812F614
	movs r0, #0x13
.L0812F5D4:
	strh r0, [r1]
	ldr r0, .L0812F618
	movs r2, #1
	strh r2, [r0]
	ldr r0, .L0812F61C
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L0812F5EC
	b .L0812F780
.L0812F5EC:
	mov r7, ip
	movs r0, #0
	ldrsh r1, [r7, r0]
	cmp r1, #0
	bne .L0812F64E
	ldr r0, .L0812F620
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #3
	bgt .L0812F604
	bl .L08130146
.L0812F604:
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #0
	beq .L0812F624
	strh r1, [r6]
	bl .L0813013A
	.byte 0x00, 0x00
.L0812F614: .4byte 0x030066A0 @ IWRAM+0x66A0
.L0812F618: .4byte 0x03006958 @ IWRAM+0x6958
.L0812F61C: .4byte 0x03003964 @ IWRAM+0x3964
.L0812F620: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F624:
	ldr r2, .L0812F640
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	bne .L0812F634
	bl .L08130146
.L0812F634:
	subs r0, #4
	cmp r0, #0
	blt .L0812F644
	subs r0, r3, #4
	strh r0, [r2]
	b .L0812F646
.L0812F640: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F644:
	strh r1, [r2]
.L0812F646:
	mov r6, ip
	ldrh r0, [r6]
	bl .L08130136
.L0812F64E:
	cmp r1, #4
	beq .L0812F656
	cmp r1, #1
	bne .L0812F6A2
.L0812F656:
	ldr r0, .L0812F674
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #2
	bgt .L0812F664
	bl .L08130146
.L0812F664:
	movs r0, #0
	ldrsh r2, [r6, r0]
	cmp r2, #0
	beq .L0812F678
	movs r0, #0
	strh r0, [r6]
	bl .L0813013A
.L0812F674: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F678:
	ldr r1, .L0812F694
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bne .L0812F688
	bl .L08130146
.L0812F688:
	subs r0, #3
	cmp r0, #0
	blt .L0812F698
	subs r0, r3, #3
	strh r0, [r1]
	b .L0812F69A
.L0812F694: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F698:
	strh r2, [r1]
.L0812F69A:
	mov r6, ip
	ldrh r0, [r6]
	bl .L08130136
.L0812F6A2:
	cmp r1, #2
	bne .L0812F710
	ldr r0, .L0812F6E0
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #7
	bgt .L0812F6B4
	bl .L08130146
.L0812F6B4:
	ldrh r0, [r6]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #1
	bhi .L0812F6F4
	ldr r1, .L0812F6E4
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne .L0812F6CE
	bl .L08130146
.L0812F6CE:
	subs r0, #6
	cmp r0, #0
	blt .L0812F6E8
	subs r0, r2, #6
	strh r0, [r1]
	mov r5, ip
	ldrh r0, [r5]
	bl .L08130136
.L0812F6E0: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F6E4: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F6E8:
	movs r0, #0
	strh r0, [r1]
	mov r6, ip
	ldrh r0, [r6]
	bl .L08130136
.L0812F6F4:
	asrs r0, r1, #0x10
	cmp r0, #2
	beq .L0812F702
	cmp r0, #4
	beq .L0812F702
	cmp r0, #6
	bne .L0812F70A
.L0812F702:
	movs r0, #0
	strh r0, [r6]
	bl .L0813013A
.L0812F70A:
	strh r2, [r6]
	bl .L0813013A
.L0812F710:
	cmp r1, #3
	beq .L0812F718
	bl .L08130146
.L0812F718:
	ldr r0, .L0812F754
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #5
	bgt .L0812F726
	bl .L08130146
.L0812F726:
	ldrh r0, [r6]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #1
	bhi .L0812F768
	ldr r1, .L0812F758
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne .L0812F740
	bl .L08130146
.L0812F740:
	subs r0, #6
	cmp r0, #0
	blt .L0812F75C
	subs r0, r2, #6
	strh r0, [r1]
	mov r5, ip
	ldrh r0, [r5]
	bl .L08130136
	.byte 0x00, 0x00
.L0812F754: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F758: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F75C:
	movs r0, #0
	strh r0, [r1]
	mov r6, ip
	ldrh r0, [r6]
	bl .L08130136
.L0812F768:
	asrs r0, r1, #0x10
	cmp r0, #2
	beq .L0812F772
	cmp r0, #4
	bne .L0812F77A
.L0812F772:
	movs r0, #0
	strh r0, [r6]
	bl .L0813013A
.L0812F77A:
	strh r2, [r6]
	bl .L0813013A
.L0812F780:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0812F78C
	b .L0812FC24
.L0812F78C:
	mov r7, ip
	movs r0, #0
	ldrsh r4, [r7, r0]
	cmp r4, #0
	bne .L0812F7F0
	ldr r3, .L0812F7B8
	ldrh r4, [r3]
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #3
	bgt .L0812F7A6
	bl .L08130146
.L0812F7A6:
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #3
	beq .L0812F7BC
	movs r0, #3
	strh r0, [r6]
	bl .L0813013A
	.byte 0x00, 0x00
.L0812F7B8: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F7BC:
	movs r5, #0
	ldrsh r1, [r6, r5]
	ldr r2, .L0812F7E0
	movs r6, #0
	ldrsh r0, [r2, r6]
	adds r1, r1, r0
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bne .L0812F7D4
	bl .L08130146
.L0812F7D4:
	subs r0, #3
	cmp r1, r0
	bge .L0812F7E4
	ldrh r0, [r2]
	adds r0, #4
	b .L0812F7E6
.L0812F7E0: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F7E4:
	subs r0, r4, #3
.L0812F7E6:
	strh r0, [r2]
	mov r1, ip
	ldrh r0, [r1]
	bl .L08130136
.L0812F7F0:
	cmp r4, #4
	beq .L0812F7F8
	cmp r4, #1
	bne .L0812F850
.L0812F7F8:
	ldr r3, .L0812F818
	ldrh r4, [r3]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #2
	bgt .L0812F808
	bl .L08130146
.L0812F808:
	movs r5, #0
	ldrsh r0, [r6, r5]
	cmp r0, #2
	beq .L0812F81C
	movs r0, #2
	strh r0, [r6]
	bl .L0813013A
.L0812F818: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F81C:
	movs r7, #0
	ldrsh r1, [r6, r7]
	ldr r2, .L0812F840
	movs r5, #0
	ldrsh r0, [r2, r5]
	adds r1, r1, r0
	movs r6, #0
	ldrsh r0, [r3, r6]
	cmp r1, r0
	bne .L0812F834
	bl .L08130146
.L0812F834:
	subs r0, #2
	cmp r1, r0
	bge .L0812F844
	ldrh r0, [r2]
	adds r0, #3
	b .L0812F846
.L0812F840: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F844:
	subs r0, r4, #2
.L0812F846:
	strh r0, [r2]
	mov r7, ip
	ldrh r0, [r7]
	bl .L08130136
.L0812F850:
	cmp r4, #2
	beq .L0812F856
	b .L0812FA64
.L0812F856:
	ldr r0, .L0812F8B0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #7
	bgt .L0812F864
	bl .L08130146
.L0812F864:
	movs r2, #0
	ldrsh r4, [r6, r2]
	cmp r4, #7
	bne .L0812F8DE
	movs r5, #2
	ldr r3, .L0812F8B4
	mov sb, r3
	ldr r2, .L0812F8B8
	mov r7, sb
	movs r4, #0
	ldrsh r1, [r7, r4]
	adds r3, r6, #0
	movs r6, #0
	ldrsh r0, [r3, r6]
	adds r1, r1, r0
	ldr r0, .L0812F8BC
	mov r8, r0
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r6, r0, r2
.L0812F88C:
	adds r0, r1, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r4, [r0]
	cmp r4, r8
	bne .L0812F8C0
	cmp r5, #2
	bne .L0812F8A6
	ldrh r0, [r6]
	cmp r0, r4
	beq .L0812F8A6
	bl .L08130114
.L0812F8A6:
	subs r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b .L0812F8CA
	.byte 0x00, 0x00
.L0812F8B0: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F8B4: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F8B8: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F8BC: .4byte 0x0000FFFF
.L0812F8C0:
	adds r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bls .L0812F88C
.L0812F8CA:
	cmp r5, #0
	bne .L0812F8D2
	bl .L08130146
.L0812F8D2:
	mov r1, sb
	ldrh r0, [r1]
	adds r0, r5, r0
	strh r0, [r1]
	bl .L08130132
.L0812F8DE:
	cmp r4, #6
	bne .L0812F958
	movs r5, #2
	ldr r3, .L0812F94C
	ldr r2, .L0812F950
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r7, #0
	ldrsh r1, [r6, r7]
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, .L0812F954
	mov sb, r2
	adds r2, r3, #0
	cmp r1, r0
	bne .L0812F908
	bl .L08130146
.L0812F908:
	adds r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bhi .L0812F932
	mov r1, sb
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r4, #0
	ldrsh r1, [r6, r4]
	adds r0, r0, r1
	adds r0, r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812F954
	cmp r1, r0
	bne .L0812F908
	subs r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0812F932:
	cmp r5, #0
	bne .L0812F93A
	bl .L08130146
.L0812F93A:
	mov r6, sb
	ldrh r0, [r6]
	adds r0, r5, r0
	strh r0, [r6]
	mov r7, ip
	ldrh r0, [r7]
	bl .L08130136
	.byte 0x00, 0x00
.L0812F94C: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F950: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F954: .4byte 0x0000FFFF
.L0812F958:
	cmp r4, #0
	beq .L0812F964
	cmp r4, #2
	beq .L0812F964
	cmp r4, #4
	bne .L0812F9D4
.L0812F964:
	ldr r2, .L0812F984
	ldr r1, .L0812F988
	movs r0, #0
	ldrsh r5, [r1, r0]
	adds r0, r5, #6
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r4, [r0]
	ldr r0, .L0812F98C
	mov sb, r1
	cmp r4, r0
	beq .L0812F990
	movs r0, #6
	strh r0, [r6]
	bl .L0813013A
.L0812F984: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F988: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F98C: .4byte 0x0000FFFF
.L0812F990:
	adds r0, r5, #4
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r4
	beq .L0812F9AA
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt .L0812F9AA
	movs r0, #4
	strh r0, [r6]
	b .L0813013A
.L0812F9AA:
	mov r3, sb
	movs r4, #0
	ldrsh r0, [r3, r4]
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812F9D0
	cmp r1, r0
	bne .L0812F9C0
	b .L08130146
.L0812F9C0:
	movs r5, #0
	ldrsh r0, [r6, r5]
	cmp r0, #1
	ble .L0812F9CA
	b .L08130146
.L0812F9CA:
	movs r0, #2
	strh r0, [r6]
	b .L0813013A
.L0812F9D0: .4byte 0x0000FFFF
.L0812F9D4:
	ldr r2, .L0812F9F4
	ldr r1, .L0812F9F8
	movs r7, #0
	ldrsh r3, [r1, r7]
	adds r0, r3, #7
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r5, [r0]
	ldr r0, .L0812F9FC
	mov sb, r1
	cmp r5, r0
	beq .L0812FA00
	movs r0, #7
	strh r0, [r6]
	b .L0813013A
	.byte 0x00, 0x00
.L0812F9F4: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F9F8: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F9FC: .4byte 0x0000FFFF
.L0812FA00:
	adds r0, r3, #5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r5
	beq .L0812FA16
	cmp r4, #4
	bgt .L0812FA16
	movs r0, #5
	strh r0, [r6]
	b .L0813013A
.L0812FA16:
	mov r1, sb
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r0, #3
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FA38
	cmp r1, r0
	beq .L0812FA3C
	movs r4, #0
	ldrsh r0, [r6, r4]
	cmp r0, #2
	bgt .L0812FA3C
	movs r0, #3
	strh r0, [r6]
	b .L0813013A
.L0812FA38: .4byte 0x0000FFFF
.L0812FA3C:
	mov r5, sb
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r3, #0
	ldrsh r1, [r6, r3]
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FA60
	cmp r1, r0
	bne .L0812FA58
	b .L08130146
.L0812FA58:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	b .L0813013A
.L0812FA60: .4byte 0x0000FFFF
.L0812FA64:
	cmp r4, #3
	beq .L0812FA6A
	b .L08130146
.L0812FA6A:
	ldr r0, .L0812FAC0
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #5
	bgt .L0812FA76
	b .L08130146
.L0812FA76:
	movs r7, #0
	ldrsh r5, [r6, r7]
	cmp r5, #5
	bne .L0812FAF4
	movs r5, #2
	ldr r0, .L0812FAC4
	mov sb, r0
	ldr r2, .L0812FAC8
	mov r7, sb
	movs r3, #0
	ldrsh r1, [r7, r3]
	adds r3, r6, #0
	movs r4, #0
	ldrsh r0, [r3, r4]
	adds r1, r1, r0
	ldr r6, .L0812FACC
	mov r8, r6
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r6, r0, r2
.L0812FA9E:
	adds r0, r1, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r4, [r0]
	cmp r4, r8
	bne .L0812FAD0
	cmp r5, #2
	bne .L0812FAB6
	ldrh r0, [r6]
	cmp r0, r4
	beq .L0812FAB6
	b .L08130126
.L0812FAB6:
	subs r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b .L0812FADA
	.byte 0x00, 0x00
.L0812FAC0: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FAC4: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FAC8: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FACC: .4byte 0x0000FFFF
.L0812FAD0:
	adds r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bls .L0812FA9E
.L0812FADA:
	cmp r5, #8
	bne .L0812FAE0
	movs r5, #6
.L0812FAE0:
	cmp r5, #0
	bne .L0812FAE6
	b .L08130146
.L0812FAE6:
	mov r7, sb
	ldrh r0, [r7]
	adds r0, r5, r0
	strh r0, [r7]
	mov r1, ip
	ldrh r0, [r1]
	b .L08130136
.L0812FAF4:
	cmp r5, #4
	bne .L0812FB74
	movs r5, #2
	ldr r3, .L0812FB20
	ldr r2, .L0812FB24
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r7, #0
	ldrsh r1, [r6, r7]
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, .L0812FB28
	mov sb, r2
	adds r2, r3, #0
	cmp r1, r0
	bne .L0812FB2C
	movs r5, #0
	b .L0812FB56
	.byte 0x00, 0x00
.L0812FB20: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FB24: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FB28: .4byte 0x0000FFFF
.L0812FB2C:
	adds r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bhi .L0812FB56
	mov r1, sb
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r4, #0
	ldrsh r1, [r6, r4]
	adds r0, r0, r1
	adds r0, r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FB70
	cmp r1, r0
	bne .L0812FB2C
	subs r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0812FB56:
	cmp r5, #8
	bne .L0812FB5C
	movs r5, #6
.L0812FB5C:
	cmp r5, #0
	bne .L0812FB62
	b .L08130146
.L0812FB62:
	mov r6, sb
	ldrh r0, [r6]
	adds r0, r5, r0
	strh r0, [r6]
	mov r7, ip
	ldrh r0, [r7]
	b .L08130136
.L0812FB70: .4byte 0x0000FFFF
.L0812FB74:
	cmp r5, #0
	beq .L0812FB7C
	cmp r5, #2
	bne .L0812FBBE
.L0812FB7C:
	ldr r3, .L0812FB98
	ldr r0, .L0812FB9C
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r2, #4
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, .L0812FBA0
	cmp r1, r0
	beq .L0812FBA4
	movs r0, #4
	strh r0, [r6]
	b .L0813013A
.L0812FB98: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FB9C: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FBA0: .4byte 0x0000FFFF
.L0812FBA4:
	adds r0, r2, #2
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, r1
	bne .L0812FBB2
	b .L08130146
.L0812FBB2:
	cmp r5, #1
	ble .L0812FBB8
	b .L08130146
.L0812FBB8:
	movs r0, #2
	strh r0, [r6]
	b .L0813013A
.L0812FBBE:
	ldr r2, .L0812FBDC
	ldr r1, .L0812FBE0
	movs r3, #0
	ldrsh r7, [r1, r3]
	adds r0, r7, #5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r3, [r0]
	ldr r0, .L0812FBE4
	mov sb, r1
	cmp r3, r0
	beq .L0812FBE8
	movs r0, #5
	strh r0, [r6]
	b .L0813013A
.L0812FBDC: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FBE0: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FBE4: .4byte 0x0000FFFF
.L0812FBE8:
	adds r0, r7, #3
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r3
	beq .L0812FBFC
	cmp r5, #2
	bgt .L0812FBFC
	strh r4, [r6]
	b .L0813013A
.L0812FBFC:
	mov r4, sb
	movs r5, #0
	ldrsh r0, [r4, r5]
	movs r7, #0
	ldrsh r1, [r6, r7]
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FC20
	cmp r1, r0
	bne .L0812FC18
	b .L08130146
.L0812FC18:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	b .L0813013A
.L0812FC20: .4byte 0x0000FFFF
.L0812FC24:
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	beq .L0812FCD6
	mov r1, ip
	ldrh r0, [r1]
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	cmp r0, #1
	bls .L0812FC42
	asrs r0, r2, #0x10
	cmp r0, #4
	bne .L0812FCAC
.L0812FC42:
	ldrh r1, [r6]
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #0
	bne .L0812FCA6
	ldr r1, .L0812FC74
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bne .L0812FCA0
	asrs r0, r2, #0x10
	cmp r0, #0
	bne .L0812FC7C
	ldr r0, .L0812FC78
	ldrh r1, [r0]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #3
	ble .L0812FC6C
	b .L08130146
.L0812FC6C:
	strh r1, [r6]
	mov r6, ip
	ldrh r0, [r6]
	b .L08130136
.L0812FC74: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FC78: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FC7C:
	cmp r0, #1
	beq .L0812FC86
	cmp r0, #4
	beq .L0812FC86
	b .L08130146
.L0812FC86:
	ldr r0, .L0812FC9C
	ldrh r1, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #2
	ble .L0812FC94
	b .L08130146
.L0812FC94:
	strh r1, [r6]
	mov r1, ip
	ldrh r0, [r1]
	b .L08130136
.L0812FC9C: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FCA0:
	subs r0, r3, #1
	strh r0, [r1]
	b .L08130132
.L0812FCA6:
	subs r0, r1, #1
	strh r0, [r6]
	b .L0813013A
.L0812FCAC:
	ldrh r0, [r6]
	cmp r0, #1
	bhi .L0812FCD0
	ldr r1, .L0812FCCC
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #1
	bgt .L0812FCC0
	b .L08130146
.L0812FCC0:
	subs r0, r2, #2
	strh r0, [r1]
	mov r4, ip
	ldrh r0, [r4]
	b .L08130136
	.byte 0x00, 0x00
.L0812FCCC: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FCD0:
	subs r0, #2
	strh r0, [r6]
	b .L0813013A
.L0812FCD6:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne .L0812FCE0
	b .L0812FFCC
.L0812FCE0:
	mov r5, ip
	movs r0, #0
	ldrsh r3, [r5, r0]
	cmp r3, #0
	bne .L0812FD5A
	ldr r0, .L0812FD28
	movs r1, #0
	ldrsh r4, [r0, r1]
	cmp r4, #2
	ble .L0812FD46
	ldrh r1, [r6]
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #3
	bne .L0812FD40
	ldr r2, .L0812FD2C
	ldr r5, .L0812FD30
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r7, #0
	ldrsh r1, [r6, r7]
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FD34
	cmp r1, r0
	bne .L0812FD38
	cmp r4, #3
	beq .L0812FD20
	b .L08130146
.L0812FD20:
	strh r3, [r6]
	mov r1, ip
	ldrh r0, [r1]
	b .L08130136
.L0812FD28: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FD2C: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FD30: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FD34: .4byte 0x0000FFFF
.L0812FD38:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b .L08130132
.L0812FD40:
	adds r0, r1, #1
	strh r0, [r6]
	b .L0813013A
.L0812FD46:
	ldrh r1, [r6]
	movs r5, #0
	ldrsh r0, [r6, r5]
	cmp r0, r4
	bne .L0812FD54
	strh r3, [r6]
	b .L0813013A
.L0812FD54:
	adds r0, r1, #1
	strh r0, [r6]
	b .L0813013A
.L0812FD5A:
	cmp r3, #1
	beq .L0812FD62
	cmp r3, #4
	bne .L0812FDE4
.L0812FD62:
	ldr r0, .L0812FDA8
	movs r1, #0
	ldrsh r4, [r0, r1]
	cmp r4, #1
	ble .L0812FDCA
	ldrh r1, [r6]
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #2
	bne .L0812FDC4
	ldr r5, .L0812FDAC
	mov r8, r5
	ldr r5, .L0812FDB0
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r2, #0
	ldrsh r1, [r6, r2]
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r0]
	ldr r0, .L0812FDB4
	cmp r1, r0
	bne .L0812FDB8
	cmp r3, #1
	beq .L0812FD9E
	cmp r3, #4
	beq .L0812FD9E
	b .L08130146
.L0812FD9E:
	cmp r4, #2
	beq .L0812FDA4
	b .L08130146
.L0812FDA4:
	strh r7, [r6]
	b .L0813013A
.L0812FDA8: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FDAC: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FDB0: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FDB4: .4byte 0x0000FFFF
.L0812FDB8:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	mov r3, ip
	ldrh r0, [r3]
	b .L08130136
.L0812FDC4:
	adds r0, r1, #1
	strh r0, [r6]
	b .L0813013A
.L0812FDCA:
	ldrh r1, [r6]
	movs r5, #0
	ldrsh r0, [r6, r5]
	cmp r0, r4
	bne .L0812FDDE
	cmp r3, #1
	beq .L0812FDDA
	b .L08130146
.L0812FDDA:
	strh r7, [r6]
	b .L0813013A
.L0812FDDE:
	adds r0, r1, #1
	strh r0, [r6]
	b .L0813013A
.L0812FDE4:
	cmp r3, #2
	bne .L0812FED4
	ldr r0, .L0812FE28
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #6
	ble .L0812FEA2
	ldrh r5, [r6]
	movs r0, #0
	ldrsh r3, [r6, r0]
	cmp r3, #5
	ble .L0812FE58
	ldr r4, .L0812FE2C
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, #0xf
	ble .L0812FE0C
	b .L08130146
.L0812FE0C:
	ldr r7, .L0812FE30
	adds r0, r1, #2
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	ldr r0, .L0812FE34
	cmp r2, r0
	beq .L0812FE38
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
	mov r1, ip
	ldrh r0, [r1]
	b .L08130136
.L0812FE28: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FE2C: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FE30: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FE34: .4byte 0x0000FFFF
.L0812FE38:
	cmp r3, #7
	beq .L0812FE3E
	b .L08130146
.L0812FE3E:
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, r2
	bne .L0812FE4C
	b .L08130146
.L0812FE4C:
	subs r0, r5, #1
	strh r0, [r6]
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
	b .L08130132
.L0812FE58:
	ldr r4, .L0812FE7C
	ldr r0, .L0812FE80
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r2, #0
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	adds r0, r1, #2
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r2, [r0]
	ldr r0, .L0812FE84
	cmp r2, r0
	beq .L0812FE88
	adds r0, r5, #2
	strh r0, [r6]
	b .L0813013A
	.byte 0x00, 0x00
.L0812FE7C: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FE80: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FE84: .4byte 0x0000FFFF
.L0812FE88:
	cmp r3, #7
	beq .L0812FE8E
	b .L08130146
.L0812FE8E:
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r2
	bne .L0812FE9C
	b .L08130146
.L0812FE9C:
	adds r0, r5, #1
	strh r0, [r6]
	b .L0813013A
.L0812FEA2:
	ldr r2, .L0812FEC8
	ldr r0, .L0812FECC
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #0
	ldrsh r1, [r6, r4]
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FED0
	cmp r1, r0
	bne .L0812FEC0
	b .L08130146
.L0812FEC0:
	ldrh r0, [r6]
	adds r0, #2
	strh r0, [r6]
	b .L0813013A
.L0812FEC8: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FECC: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FED0: .4byte 0x0000FFFF
.L0812FED4:
	cmp r3, #3
	beq .L0812FEDA
	b .L08130146
.L0812FEDA:
	ldr r0, .L0812FF1C
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #4
	ble .L0812FF9A
	ldrh r5, [r6]
	movs r7, #0
	ldrsh r3, [r6, r7]
	cmp r3, #3
	ble .L0812FF50
	ldr r4, .L0812FF20
	movs r0, #0
	ldrsh r1, [r4, r0]
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, #0xf
	ble .L0812FEFE
	b .L08130146
.L0812FEFE:
	ldr r7, .L0812FF24
	adds r0, r1, #2
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	ldr r0, .L0812FF28
	cmp r2, r0
	beq .L0812FF2C
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
	mov r3, ip
	ldrh r0, [r3]
	b .L08130136
	.byte 0x00, 0x00
.L0812FF1C: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FF20: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FF24: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FF28: .4byte 0x0000FFFF
.L0812FF2C:
	cmp r3, #5
	beq .L0812FF32
	b .L08130146
.L0812FF32:
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, r2
	bne .L0812FF40
	b .L08130146
.L0812FF40:
	subs r0, r5, #1
	strh r0, [r6]
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
	mov r4, ip
	ldrh r0, [r4]
	b .L08130136
.L0812FF50:
	ldr r4, .L0812FF74
	ldr r0, .L0812FF78
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r2, #0
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	adds r0, r1, #2
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r2, [r0]
	ldr r0, .L0812FF7C
	cmp r2, r0
	beq .L0812FF80
	adds r0, r5, #2
	strh r0, [r6]
	b .L0813013A
	.byte 0x00, 0x00
.L0812FF74: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FF78: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FF7C: .4byte 0x0000FFFF
.L0812FF80:
	cmp r3, #5
	beq .L0812FF86
	b .L08130146
.L0812FF86:
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r2
	bne .L0812FF94
	b .L08130146
.L0812FF94:
	adds r0, r5, #1
	strh r0, [r6]
	b .L0813013A
.L0812FF9A:
	ldr r2, .L0812FFC0
	ldr r0, .L0812FFC4
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #0
	ldrsh r1, [r6, r4]
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FFC8
	cmp r1, r0
	bne .L0812FFB8
	b .L08130146
.L0812FFB8:
	ldrh r0, [r6]
	adds r0, #2
	strh r0, [r6]
	b .L0813013A
.L0812FFC0: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FFC4: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FFC8: .4byte 0x0000FFFF
.L0812FFCC:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L08130028
	mov r5, ip
	ldrh r0, [r5]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L0812FFE4
	b .L08130146
.L0812FFE4:
	ldrh r2, [r6]
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r0, #1
	beq .L0812FFFA
	cmp r0, #3
	beq .L0812FFFA
	cmp r0, #5
	beq .L0812FFFA
	cmp r0, #7
	bne .L08130002
.L0812FFFA:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	b .L0813013A
.L08130002:
	ldr r0, .L08130020
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0
	ldrsh r0, [r6, r4]
	adds r1, r1, r0
	ldr r0, .L08130024
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	blt .L0813001A
	b .L08130146
.L0813001A:
	adds r0, r2, #1
	strh r0, [r6]
	b .L0813013A
.L08130020: .4byte 0x03006940 @ IWRAM+0x6940
.L08130024: .4byte 0x03006604 @ IWRAM+0x6604
.L08130028:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L08130082
	mov r7, ip
	ldrh r0, [r7]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L08130040
	b .L08130146
.L08130040:
	ldrh r0, [r6]
	movs r2, #0
	ldrsh r1, [r6, r2]
	cmp r1, #0
	beq .L08130056
	cmp r1, #2
	beq .L08130056
	cmp r1, #4
	beq .L08130056
	cmp r1, #6
	bne .L0813007C
.L08130056:
	ldr r0, .L08130074
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0
	ldrsh r0, [r6, r4]
	adds r1, r1, r0
	ldr r0, .L08130078
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bge .L08130146
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	b .L0813013A
.L08130074: .4byte 0x03006940 @ IWRAM+0x6940
.L08130078: .4byte 0x03006604 @ IWRAM+0x6604
.L0813007C:
	subs r0, #1
	strh r0, [r6]
	b .L0813013A
.L08130082:
	ldr r3, .L081300C4
	ldrh r1, [r3]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L081300E0
	mov r6, r8
	strh r2, [r6, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	ldr r3, .L081300C8
	ldr r2, .L081300CC
	ldr r0, .L081300D0
	movs r7, #0
	ldrsh r0, [r0, r7]
	ldr r1, .L081300D4
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r3]
	ldr r1, .L081300D8
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0x18
	bne .L081300DC
	movs r0, #0x19
	b .L08130144
	.byte 0x00, 0x00
.L081300C4: .4byte 0x030031C4 @ IWRAM+0x31C4
.L081300C8: .4byte 0x030065E0 @ IWRAM+0x65E0
.L081300CC: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L081300D0: .4byte 0x03006940 @ IWRAM+0x6940
.L081300D4: .4byte 0x0300696C @ IWRAM+0x696C
.L081300D8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L081300DC:
	movs r0, #0xe
	b .L08130144
.L081300E0:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08130146
	ldr r0, .L0813010C
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08130146
	mov r6, r8
	strh r2, [r6, #0x1c]
	movs r0, #0x66
	bl sub_080C51D4
	ldr r1, .L08130110
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #0x18
	bne .L08130142
	movs r0, #0x37
	b .L08130144
	.byte 0x00, 0x00
.L0813010C: .4byte 0x03006670 @ IWRAM+0x6670
.L08130110: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08130114:
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	ldrh r0, [r7]
	adds r0, #2
	strh r0, [r7]
	mov r1, ip
	ldrh r0, [r1]
	b .L08130136
.L08130126:
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	ldrh r0, [r7]
	adds r0, #2
	strh r0, [r7]
.L08130132:
	mov r2, ip
	ldrh r0, [r2]
.L08130136:
	bl sub_0812F2B4
.L0813013A:
	movs r0, #0x64
	bl sub_080C51D4
	b .L08130146
.L08130142:
	movs r0, #0x1c
.L08130144:
	strh r0, [r1]
.L08130146:
	bl sub_0812F010
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08130158
sub_08130158: @ 0x08130158
	ldr r0, .L08130174
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L08130178
	strh r1, [r0]
	ldr r0, .L0813017C
	strh r1, [r0]
	ldr r1, .L08130180
	movs r0, #0
	strh r0, [r1]
	strh r0, [r1, #0x10]
	strh r0, [r1, #0x20]
	bx lr
	.byte 0x00, 0x00
.L08130174: .4byte 0x03006958 @ IWRAM+0x6958
.L08130178: .4byte 0x03006848 @ IWRAM+0x6848
.L0813017C: .4byte 0x03006680 @ IWRAM+0x6680
.L08130180: .4byte 0x03006620 @ IWRAM+0x6620

	thumb_func_start sub_08130184
sub_08130184: @ 0x08130184
	push {r4, lr}
	movs r1, #0
	strh r1, [r0, #0x1c]
	ldr r0, .L081301CC
	strh r1, [r0]
	ldr r4, .L081301D0
	strh r1, [r4]
	ldr r0, .L081301D4
	strh r1, [r0]
	movs r0, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L081301A6
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
.L081301A6:
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L081301B6
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
.L081301B6:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L081301C6
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
.L081301C6:
	pop {r4}
	pop {r0}
	bx r0
.L081301CC: .4byte 0x0300696C @ IWRAM+0x696C
.L081301D0: .4byte 0x03006688 @ IWRAM+0x6688
.L081301D4: .4byte 0x03006940 @ IWRAM+0x6940

	thumb_func_start sub_081301D8
sub_081301D8: @ 0x081301D8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, .L08130228
	ldr r2, .L0813022C
	ldr r3, .L08130230
	movs r4, #0
	ldrsh r0, [r3, r4]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, .L08130234
	movs r4, #0
	ldrsh r0, [r3, r4]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, .L08130238
	movs r0, #0x10
	strh r0, [r1]
	ldr r1, .L0813023C
	movs r0, #1
	strh r0, [r1]
	ldr r0, .L08130240
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L08130244
	ldrh r1, [r3]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	beq .L081302F0
	subs r0, r1, #1
	b .L08130260
	.byte 0x00, 0x00
.L08130228: .4byte 0x0300689C @ IWRAM+0x689C
.L0813022C: .4byte gUnknown_0878FCC4
.L08130230: .4byte 0x0300696C @ IWRAM+0x696C
.L08130234: .4byte 0x0300695C @ IWRAM+0x695C
.L08130238: .4byte 0x030066A0 @ IWRAM+0x66A0
.L0813023C: .4byte 0x03006958 @ IWRAM+0x6958
.L08130240: .4byte 0x03003964 @ IWRAM+0x3964
.L08130244:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08130270
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldr r0, .L0813026C
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, #1
	cmp r1, r0
	beq .L081302F0
	ldrh r0, [r3]
	adds r0, #1
.L08130260:
	strh r0, [r3]
	movs r0, #0x64
	bl sub_080C51D4
	b .L081302F0
	.byte 0x00, 0x00
.L0813026C: .4byte 0x03006688 @ IWRAM+0x6688
.L08130270:
	ldr r1, .L0813029C
	ldrh r0, [r1]
	movs r4, #1
	adds r2, r4, #0
	ands r2, r0
	cmp r2, #0
	beq .L081302D4
	ldr r5, .L081302A0
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq .L081302A4
	movs r0, #0x68
	bl sub_080C51D4
	b .L081302F0
	.byte 0x00, 0x00
.L0813029C: .4byte 0x030031C4 @ IWRAM+0x31C4
.L081302A0: .4byte 0x030069D8 @ IWRAM+0x69D8
.L081302A4:
	strh r4, [r6, #0x1c]
	ldr r1, .L081302C8
	movs r0, #0x21
	strh r0, [r1]
	ldr r2, .L081302CC
	ldr r1, .L081302D0
	movs r4, #0
	ldrsh r0, [r3, r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r1]
	strh r0, [r2]
	movs r0, #0x65
	bl sub_080C51D4
	b .L081302F0
	.byte 0x00, 0x00
.L081302C8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L081302CC: .4byte 0x03006850 @ IWRAM+0x6850
.L081302D0: .4byte 0x03006898 @ IWRAM+0x6898
.L081302D4:
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L081302F0
	strh r4, [r6, #0x1c]
	ldr r0, .L081302F8
	movs r1, #0x20
	strh r1, [r0]
	ldr r0, .L081302FC
	strh r2, [r0]
	movs r0, #0x66
	bl sub_080C51D4
.L081302F0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081302F8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L081302FC: .4byte 0x0300699C @ IWRAM+0x699C

	thumb_func_start sub_08130300
sub_08130300: @ 0x08130300
	push {r4, lr}
	ldr r0, .L0813032C
	movs r4, #0
	strh r4, [r0]
	ldr r0, .L08130330
	strh r4, [r0]
	ldr r0, .L08130334
	strh r4, [r0]
	ldr r0, .L08130338
	strh r4, [r0]
	ldr r0, .L0813033C
	strh r4, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L08130340
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813032C: .4byte 0x03006958 @ IWRAM+0x6958
.L08130330: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L08130334: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L08130338: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813033C: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L08130340: .4byte 0x030069D0 @ IWRAM+0x69D0

	thumb_func_start sub_08130344
sub_08130344: @ 0x08130344
	movs r1, #0
	strh r1, [r0, #0x1c]
	ldr r0, .L08130358
	strh r1, [r0]
	ldr r2, .L0813035C
	movs r0, #2
	strh r0, [r2]
	ldr r0, .L08130360
	strh r1, [r0]
	bx lr
.L08130358: .4byte 0x0300696C @ IWRAM+0x696C
.L0813035C: .4byte 0x03006688 @ IWRAM+0x6688
.L08130360: .4byte 0x03006940 @ IWRAM+0x6940

	thumb_func_start sub_08130364
sub_08130364: @ 0x08130364
.L08130364:
	push {r4, lr}
	adds r4, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	adds r2, #0x38
	adds r0, r4, #0
	subs r0, #0x9d
	cmp r0, #8
	bhi .L081303E0
	lsls r0, r0, #2
	ldr r1, .L08130390
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08130390: .4byte gUnknown_08130394
	.global gUnknown_08130394
gUnknown_08130394:
.L08130394: @ jump table
	.4byte .L081303B8
	.4byte .L081303BE
	.4byte .L081303C4
	.4byte .L081303CA
	.4byte .L081303D0
	.4byte .L081303D6
	.4byte .L081303B8
	.4byte .L081303BE
	.4byte .L081303C4
.L081303B8:
	movs r0, #0
	ldrsb r0, [r2, r0]
	b .L081303DA
.L081303BE:
	movs r0, #1
	ldrsb r0, [r2, r0]
	b .L081303DA
.L081303C4:
	movs r0, #2
	ldrsb r0, [r2, r0]
	b .L081303DA
.L081303CA:
	movs r0, #3
	ldrsb r0, [r2, r0]
	b .L081303DA
.L081303D0:
	movs r0, #4
	ldrsb r0, [r2, r0]
	b .L081303DA
.L081303D6:
	movs r0, #5
	ldrsb r0, [r2, r0]
.L081303DA:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L081303E2
.L081303E0:
	movs r0, #0
.L081303E2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_081303E8
sub_081303E8: @ 0x081303E8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, .L08130434
	ldr r2, .L08130438
	ldr r4, .L0813043C
	movs r3, #0
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, .L08130440
	movs r3, #0
	ldrsh r0, [r4, r3]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, .L08130444
	movs r0, #0x10
	strh r0, [r1]
	ldr r0, .L08130448
	movs r1, #1
	strh r1, [r0]
	ldr r0, .L0813044C
	ldrh r0, [r0]
	movs r3, #0xc0
	ands r3, r0
	cmp r3, #0
	beq .L0813045C
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne .L08130450
	strh r1, [r4]
	b .L08130454
.L08130434: .4byte 0x0300689C @ IWRAM+0x689C
.L08130438: .4byte gUnknown_0878FCC4
.L0813043C: .4byte 0x0300696C @ IWRAM+0x696C
.L08130440: .4byte 0x0300695C @ IWRAM+0x695C
.L08130444: .4byte 0x030066A0 @ IWRAM+0x66A0
.L08130448: .4byte 0x03006958 @ IWRAM+0x6958
.L0813044C: .4byte 0x03003964 @ IWRAM+0x3964
.L08130450:
	movs r0, #0
	strh r0, [r4]
.L08130454:
	movs r0, #0x64
	bl sub_080C51D4
	b .L08130532
.L0813045C:
	ldr r1, .L0813049C
	ldrh r0, [r1]
	movs r5, #1
	adds r2, r5, #0
	ands r2, r0
	cmp r2, #0
	beq .L08130514
	ldr r0, .L081304A0
	strh r3, [r0]
	ldr r0, .L081304A4
	strh r3, [r0]
	ldr r0, .L081304A8
	strh r3, [r0]
	ldr r0, .L081304AC
	strh r3, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	movs r3, #0
	ldrsh r2, [r4, r3]
	cmp r2, #0
	beq .L081304C4
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L081304B4
	ldr r0, .L081304B0
	strh r5, [r0]
	b .L081304C8
	.byte 0x00, 0x00
.L0813049C: .4byte 0x030031C4 @ IWRAM+0x31C4
.L081304A0: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L081304A4: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L081304A8: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L081304AC: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L081304B0: .4byte 0x03006898 @ IWRAM+0x6898
.L081304B4:
	ldr r1, .L081304C0
	movs r0, #2
	strh r0, [r1]
	adds r2, r1, #0
	b .L081304CA
	.byte 0x00, 0x00
.L081304C0: .4byte 0x03006898 @ IWRAM+0x6898
.L081304C4:
	ldr r0, .L081304F8
	strh r2, [r0]
.L081304C8:
	adds r2, r0, #0
.L081304CA:
	movs r1, #0
	movs r0, #1
	strh r0, [r6, #0x1c]
	ldr r0, .L081304FC
	strh r1, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, .L08130500
	ldrh r1, [r1]
	bl sub_08130364
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813050C
	movs r0, #0x68
	bl sub_080C51D4
	ldr r0, .L08130504
	ldr r1, .L08130508
	ldr r1, [r1, #4]
	str r1, [r0]
	b .L08130532
	.byte 0x00, 0x00
.L081304F8: .4byte 0x03006898 @ IWRAM+0x6898
.L081304FC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08130500: .4byte 0x030065E0 @ IWRAM+0x65E0
.L08130504: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08130508: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813050C:
	movs r0, #0x65
	bl sub_080C51D4
	b .L08130532
.L08130514:
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08130532
	strh r5, [r6, #0x1c]
	ldr r0, .L08130538
	strh r2, [r0]
	ldr r1, .L0813053C
	ldr r0, .L08130540
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0x66
	bl sub_080C51D4
.L08130532:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08130538: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813053C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08130540: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8

	thumb_func_start sub_08130544
sub_08130544: @ 0x08130544
	ldr r1, .L0813054C
	movs r0, #0
	strh r0, [r1]
	bx lr
.L0813054C: .4byte 0x03006958 @ IWRAM+0x6958

	thumb_func_start sub_08130550
sub_08130550: @ 0x08130550
	movs r1, #0
	strh r1, [r0, #0x1c]
	ldr r0, .L08130568
	strh r1, [r0]
	ldr r0, .L0813056C
	strh r1, [r0]
	ldr r0, .L08130570
	strh r1, [r0]
	ldr r1, .L08130574
	movs r0, #0xa
	strh r0, [r1]
	bx lr
.L08130568: .4byte 0x0300696C @ IWRAM+0x696C
.L0813056C: .4byte 0x03006940 @ IWRAM+0x6940
.L08130570: .4byte 0x030065E4 @ IWRAM+0x65E4
.L08130574: .4byte 0x030068D4 @ IWRAM+0x68D4

	thumb_func_start sub_08130578
sub_08130578: @ 0x08130578
.L08130578:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_080C32D4
	adds r5, r0, #0
	movs r0, #0xff
	adds r1, r4, #0
	bl sub_08131AB0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	adds r5, r5, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r4, .L081305D0
	ldr r6, .L081305D4
	adds r0, r5, #0
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r6
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x68
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r4, #0x70
	strh r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081305D0: .4byte 0x0203D800 @ EWRAM+0x3D800
.L081305D4: .4byte gScriptDigitGlyphs

	thumb_func_start sub_081305D8
sub_081305D8: @ 0x081305D8
.L081305D8:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L08130604
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08130610
	movs r2, #0
	ldr r4, .L08130608
	ldr r3, .L0813060C
.L081305EC:
	lsls r1, r2, #3
	adds r1, r1, r4
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xe
	bls .L081305EC
	b .L08130676
.L08130604: .4byte 0x030065E4 @ IWRAM+0x65E4
.L08130608: .4byte 0x0203D800 @ EWRAM+0x3D800
.L0813060C: .4byte 0x03006820 @ IWRAM+0x6820
.L08130610:
	movs r2, #0
	ldr r3, .L0813067C
	ldr r5, .L08130680
	adds r4, r3, #0
.L08130618:
	lsls r1, r2, #1
	adds r1, r1, r5
	lsls r0, r2, #3
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xe
	bls .L08130618
	ldr r0, .L08130684
	strh r0, [r3]
	adds r0, #0xa7
	strh r0, [r3, #8]
	adds r0, #0x53
	strh r0, [r3, #0x10]
	ldr r1, .L08130688
	strh r1, [r3, #0x18]
	ldr r0, .L0813068C
	strh r0, [r3, #0x20]
	adds r0, #2
	strh r0, [r3, #0x28]
	adds r0, #0x22
	strh r0, [r3, #0x30]
	adds r0, #0x1b
	strh r0, [r3, #0x38]
	adds r0, r3, #0
	adds r0, #0x40
	strh r1, [r0]
	adds r1, r3, #0
	adds r1, #0x48
	movs r0, #0xaa
	lsls r0, r0, #4
	strh r0, [r1]
	adds r1, #8
	subs r0, #0xaa
	strh r0, [r1]
	adds r1, #8
	ldr r0, .L08130690
	strh r0, [r1]
	adds r1, #8
	movs r0, #0x3f
	strh r0, [r1]
	adds r0, r6, #0
	bl sub_08130578
.L08130676:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0813067C: .4byte 0x0203D800 @ EWRAM+0x3D800
.L08130680: .4byte 0x03006820 @ IWRAM+0x6820
.L08130684: .4byte 0x00000BD9
.L08130688: .4byte 0x00000149
.L0813068C: .4byte 0x0000017B
.L08130690: .4byte 0x00000B67

	thumb_func_start sub_08130694
sub_08130694: @ 0x08130694
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, .L081306E8
	ldr r2, .L081306EC
	ldr r6, .L081306F0
	movs r3, #0
	ldrsh r0, [r6, r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #0xe
	strh r0, [r1]
	ldr r1, .L081306F4
	movs r4, #0
	ldrsh r0, [r6, r4]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, .L081306F8
	movs r0, #0x13
	strh r0, [r1]
	ldr r1, .L081306FC
	movs r5, #1
	strh r5, [r1]
	ldr r4, .L08130700
	ldrh r2, [r4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	mov r8, r6
	mov sb, r1
	cmp r0, #0
	beq .L08130704
	subs r0, r2, #1
	strh r0, [r4]
	b .L08130C1A
.L081306E8: .4byte 0x0300689C @ IWRAM+0x689C
.L081306EC: .4byte gUnknown_0878FCC4
.L081306F0: .4byte 0x0300696C @ IWRAM+0x696C
.L081306F4: .4byte 0x0300695C @ IWRAM+0x695C
.L081306F8: .4byte 0x030066A0 @ IWRAM+0x66A0
.L081306FC: .4byte 0x03006958 @ IWRAM+0x6958
.L08130700: .4byte 0x030068D4 @ IWRAM+0x68D4
.L08130704:
	ldr r3, .L0813072C
	ldrh r1, [r3]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L08130738
	ldr r1, .L08130730
	ldrh r0, [r1]
	eors r0, r5
	strh r0, [r1]
	ldr r0, .L08130734
	ldrh r0, [r0]
	ldrh r1, [r1]
	bl Shop_InitItemList
	strh r5, [r4]
	b .L08130C1A
	.byte 0x00, 0x00
.L0813072C: .4byte 0x030031C4 @ IWRAM+0x31C4
.L08130730: .4byte 0x030065E4 @ IWRAM+0x65E4
.L08130734: .4byte 0x03006940 @ IWRAM+0x6940
.L08130738:
	ldr r0, .L08130768
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L081307C0
	movs r4, #0
	ldrsh r1, [r6, r4]
	cmp r1, #0
	beq .L0813077C
	strh r2, [r6]
	ldr r0, .L0813076C
	ldr r0, [r0]
	ldr r1, .L08130770
	ldrh r2, [r1]
	ldr r3, .L08130774
	ldr r1, .L08130778
	movs r5, #0
	ldrsh r1, [r1, r5]
	lsls r1, r1, #1
	adds r1, r1, r3
	b .L08130990
	.byte 0x00, 0x00
.L08130768: .4byte 0x03003964 @ IWRAM+0x3964
.L0813076C: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130770: .4byte 0x03006898 @ IWRAM+0x6898
.L08130774: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130778: .4byte 0x03006940 @ IWRAM+0x6940
.L0813077C:
	ldr r3, .L08130790
	movs r2, #0
	ldrsh r0, [r3, r2]
	subs r0, #3
	cmp r0, #0
	blt .L08130794
	ldrh r0, [r3]
	subs r0, #3
	b .L08130976
	.byte 0x00, 0x00
.L08130790: .4byte 0x03006940 @ IWRAM+0x6940
.L08130794:
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	bne .L0813079E
	b .L081309FA
.L0813079E:
	strh r1, [r3]
	ldr r0, .L081307B4
	ldr r0, [r0]
	ldr r1, .L081307B8
	ldrh r2, [r1]
	ldr r3, .L081307BC
	movs r4, #0
	ldrsh r1, [r6, r4]
	lsls r1, r1, #1
	adds r1, r1, r3
	b .L081309EC
.L081307B4: .4byte 0x030068A4 @ IWRAM+0x68A4
.L081307B8: .4byte 0x03006898 @ IWRAM+0x6898
.L081307BC: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L081307C0:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08130880
	movs r5, #0
	ldrsh r0, [r6, r5]
	cmp r0, #2
	beq .L0813082C
	ldr r0, .L081307E4
	ldrh r1, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	bgt .L081307E8
	subs r0, r1, #1
	b .L081307EA
	.byte 0x00, 0x00
.L081307E4: .4byte 0x03006688 @ IWRAM+0x6688
.L081307E8:
	movs r0, #2
.L081307EA:
	strh r0, [r6]
	movs r0, #0x64
	bl sub_080C51D4
	ldr r0, .L08130818
	ldr r0, [r0]
	ldr r1, .L0813081C
	ldrh r2, [r1]
	ldr r4, .L08130820
	ldr r1, .L08130824
	movs r3, #0
	ldrsh r1, [r1, r3]
	ldr r3, .L08130828
	movs r5, #0
	ldrsh r3, [r3, r5]
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r3, [r1]
	movs r1, #1
	bl sub_080D34A4
	b .L081309FA
.L08130818: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813081C: .4byte 0x03006898 @ IWRAM+0x6898
.L08130820: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130824: .4byte 0x0300696C @ IWRAM+0x696C
.L08130828: .4byte 0x03006940 @ IWRAM+0x6940
.L0813082C:
	movs r0, #0
	ldrsh r1, [r6, r0]
	ldr r3, .L0813084C
	movs r4, #0
	ldrsh r2, [r3, r4]
	adds r1, r1, r2
	ldr r4, .L08130850
	movs r5, #0
	ldrsh r0, [r4, r5]
	subs r0, #3
	cmp r1, r0
	bge .L08130854
	ldrh r0, [r3]
	adds r0, #3
	b .L08130976
	.byte 0x00, 0x00
.L0813084C: .4byte 0x03006940 @ IWRAM+0x6940
.L08130850: .4byte 0x03006688 @ IWRAM+0x6688
.L08130854:
	cmp r2, r0
	bne .L0813085A
	b .L081309FA
.L0813085A:
	ldrh r0, [r4]
	subs r0, #3
	strh r0, [r3]
	ldr r0, .L08130874
	ldr r0, [r0]
	ldr r1, .L08130878
	ldrh r2, [r1]
	ldr r4, .L0813087C
	movs r5, #0
	ldrsh r1, [r6, r5]
	movs r6, #0
	ldrsh r3, [r3, r6]
	b .L081309E6
.L08130874: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130878: .4byte 0x03006898 @ IWRAM+0x6898
.L0813087C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130880:
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L0813090C
	ldrh r1, [r6]
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #0
	beq .L081308C0
	subs r0, r1, #1
	strh r0, [r6]
	ldr r0, .L081308B0
	ldr r0, [r0]
	ldr r1, .L081308B4
	ldrh r2, [r1]
	ldr r4, .L081308B8
	movs r3, #0
	ldrsh r1, [r6, r3]
	ldr r3, .L081308BC
	movs r5, #0
	ldrsh r3, [r3, r5]
	b .L0813098A
.L081308B0: .4byte 0x030068A4 @ IWRAM+0x68A4
.L081308B4: .4byte 0x03006898 @ IWRAM+0x6898
.L081308B8: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L081308BC: .4byte 0x03006940 @ IWRAM+0x6940
.L081308C0:
	ldr r3, .L081308D0
	ldrh r1, [r3]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	beq .L081308D4
	subs r0, r1, #1
	b .L08130976
.L081308D0: .4byte 0x03006940 @ IWRAM+0x6940
.L081308D4:
	ldr r0, .L081308FC
	ldrh r1, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #3
	ble .L081308E2
	b .L081309FA
.L081308E2:
	subs r0, r1, #1
	strh r0, [r6]
	ldr r0, .L08130900
	ldr r0, [r0]
	ldr r1, .L08130904
	ldrh r2, [r1]
	ldr r4, .L08130908
	movs r5, #0
	ldrsh r1, [r6, r5]
	movs r6, #0
	ldrsh r3, [r3, r6]
	b .L081309E6
	.byte 0x00, 0x00
.L081308FC: .4byte 0x03006688 @ IWRAM+0x6688
.L08130900: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130904: .4byte 0x03006898 @ IWRAM+0x6898
.L08130908: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813090C:
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne .L0813091A
	b .L08130A28
.L0813091A:
	ldrh r4, [r6]
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #2
	bne .L081309B0
	ldr r4, .L08130948
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r0, #3
	bne .L0813095C
	strh r2, [r6]
	ldr r0, .L0813094C
	ldr r0, [r0]
	ldr r1, .L08130950
	ldrh r2, [r1]
	ldr r3, .L08130954
	ldr r1, .L08130958
	movs r4, #0
	ldrsh r1, [r1, r4]
	lsls r1, r1, #1
	adds r1, r1, r3
	b .L08130990
	.byte 0x00, 0x00
.L08130948: .4byte 0x03006688 @ IWRAM+0x6688
.L0813094C: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130950: .4byte 0x03006898 @ IWRAM+0x6898
.L08130954: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130958: .4byte 0x03006940 @ IWRAM+0x6940
.L0813095C:
	movs r5, #0
	ldrsh r1, [r6, r5]
	ldr r3, .L081309A0
	movs r2, #0
	ldrsh r0, [r3, r2]
	adds r1, r1, r0
	movs r5, #0
	ldrsh r0, [r4, r5]
	subs r0, #1
	cmp r1, r0
	bge .L081309FA
	ldrh r0, [r3]
	adds r0, #1
.L08130976:
	strh r0, [r3]
	ldr r0, .L081309A4
	ldr r0, [r0]
	ldr r1, .L081309A8
	ldrh r2, [r1]
	ldr r4, .L081309AC
	movs r5, #0
	ldrsh r1, [r6, r5]
	movs r6, #0
	ldrsh r3, [r3, r6]
.L0813098A:
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, r1, r4
.L08130990:
	ldrh r3, [r1]
	movs r1, #1
	bl sub_080D34A4
	movs r0, #0x64
	bl sub_080C51D4
	b .L081309FA
.L081309A0: .4byte 0x03006940 @ IWRAM+0x6940
.L081309A4: .4byte 0x030068A4 @ IWRAM+0x68A4
.L081309A8: .4byte 0x03006898 @ IWRAM+0x6898
.L081309AC: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L081309B0:
	ldr r3, .L081309C8
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #2
	bgt .L081309CC
	movs r5, #0
	ldrsh r1, [r6, r5]
	subs r0, #1
	cmp r1, r0
	blt .L081309CC
	strh r2, [r6]
	b .L081309D0
.L081309C8: .4byte 0x03006688 @ IWRAM+0x6688
.L081309CC:
	adds r0, r4, #1
	strh r0, [r6]
.L081309D0:
	ldr r0, .L08130A10
	ldr r0, [r0]
	ldr r1, .L08130A14
	ldrh r2, [r1]
	ldr r4, .L08130A18
	mov r6, r8
	movs r3, #0
	ldrsh r1, [r6, r3]
	ldr r3, .L08130A1C
	movs r5, #0
	ldrsh r3, [r3, r5]
.L081309E6:
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, r1, r4
.L081309EC:
	ldrh r3, [r1]
	movs r1, #1
	bl sub_080D34A4
	movs r0, #0x64
	bl sub_080C51D4
.L081309FA:
	ldr r0, .L08130A1C
	ldrh r0, [r0]
	ldr r1, .L08130A20
	ldrh r1, [r1]
	bl Shop_InitItemList
	ldr r1, .L08130A24
	movs r0, #1
	strh r0, [r1]
	b .L08130C1A
	.byte 0x00, 0x00
.L08130A10: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130A14: .4byte 0x03006898 @ IWRAM+0x6898
.L08130A18: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130A1C: .4byte 0x03006940 @ IWRAM+0x6940
.L08130A20: .4byte 0x030065E4 @ IWRAM+0x65E4
.L08130A24: .4byte 0x030068D4 @ IWRAM+0x68D4
.L08130A28:
	ldrh r0, [r3]
	movs r1, #1
	mov r8, r1
	mov r2, r8
	ands r2, r0
	cmp r2, #0
	bne .L08130A38
	b .L08130BB4
.L08130A38:
	mov r2, r8
	strh r2, [r7, #0x1c]
	ldr r3, .L08130AA0
	mov sl, r3
	ldr r0, [r3]
	bl sub_080D34F0
	ldr r7, .L08130AA4
	movs r4, #0
	ldrsh r0, [r7, r4]
	cmp r0, #0x28
	bne .L08130AC0
	movs r0, #0x29
	strh r0, [r7]
	ldr r0, .L08130AA8
	mov r8, r0
	ldr r2, .L08130AAC
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r4, .L08130AB0
	movs r3, #0
	ldrsh r1, [r4, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	bl sub_080C3100
	ldr r3, .L08130AB4
	movs r2, #0
	ldrsh r1, [r6, r2]
	movs r6, #0
	ldrsh r2, [r4, r6]
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r1, [r1]
	adds r0, r0, r1
	ldr r1, .L08130AB8
	cmp r0, r1
	bls .L08130B82
	ldr r0, .L08130ABC
	ldr r1, [r0, #8]
	str r1, [r0, #0x10]
	movs r0, #0x23
	strh r0, [r7]
	mov r0, sb
	strh r5, [r0]
	b .L08130B2A
	.byte 0x00, 0x00
.L08130AA0: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130AA4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08130AA8: .4byte 0x030069A8 @ IWRAM+0x69A8
.L08130AAC: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130AB0: .4byte 0x03006940 @ IWRAM+0x6940
.L08130AB4: .4byte 0x0203BD74 @ EWRAM+0x3BD74
.L08130AB8: .4byte 0x000F423F
.L08130ABC: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08130AC0:
	movs r0, #0x23
	strh r0, [r7]
	ldr r2, .L08130B04
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r1, .L08130B08
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r6, [r0]
	adds r0, r6, #0
	bl sub_080C32D4
	adds r4, r0, #0
	movs r0, #0xff
	adds r1, r6, #0
	bl sub_08131AB0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r0
	cmp r4, #0x62
	ble .L08130B10
	ldr r1, .L08130B0C
	ldr r0, [r1, #8]
	str r0, [r1, #0x10]
	mov r4, sb
	strh r5, [r4]
	b .L08130B2A
	.byte 0x00, 0x00
.L08130B04: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130B08: .4byte 0x03006940 @ IWRAM+0x6940
.L08130B0C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08130B10:
	adds r0, r6, #0
	bl sub_080C4C60
	adds r4, r0, #0
	bl sub_080C3100
	cmp r4, r0
	bls .L08130B38
	ldr r1, .L08130B34
	ldr r0, [r1]
	str r0, [r1, #0x10]
	mov r6, sb
	strh r5, [r6]
.L08130B2A:
	movs r0, #0x66
	bl sub_080C51D4
	b .L08130C1A
	.byte 0x00, 0x00
.L08130B34: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08130B38:
	ldr r0, .L08130B8C
	str r5, [r0, #0x10]
	ldr r4, .L08130B90
	strh r6, [r4]
	ldr r0, .L08130B94
	mov r1, r8
	strh r1, [r0]
	ldrh r0, [r4]
	bl sub_080C4C60
	ldr r1, .L08130B98
	str r0, [r1]
	ldr r1, .L08130B9C
	ldrh r0, [r4]
	strh r0, [r1]
	ldr r1, .L08130BA0
	ldr r0, .L08130BA4
	strh r5, [r0, #0x10]
	strh r5, [r0, #8]
	strh r5, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	strh r5, [r0]
	strh r5, [r1, #0x30]
	strh r5, [r1, #0x20]
	strh r5, [r1, #0x10]
	strh r5, [r1]
	ldr r0, .L08130BA8
	strh r5, [r0]
	ldr r0, .L08130BAC
	strh r5, [r0]
	mov r2, sl
	ldr r0, [r2]
	bl sub_080D34F0
	ldr r0, .L08130BB0
	strh r5, [r0]
.L08130B82:
	movs r0, #0x65
	bl sub_080C51D4
	b .L08130C1A
	.byte 0x00, 0x00
.L08130B8C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08130B90: .4byte 0x030069A8 @ IWRAM+0x69A8
.L08130B94: .4byte 0x030065FC @ IWRAM+0x65FC
.L08130B98: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L08130B9C: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08130BA0: .4byte 0x03006620 @ IWRAM+0x6620
.L08130BA4: .4byte 0x03006920 @ IWRAM+0x6920
.L08130BA8: .4byte 0x0300699C @ IWRAM+0x699C
.L08130BAC: .4byte 0x0300669C @ IWRAM+0x669C
.L08130BB0: .4byte 0x03006958 @ IWRAM+0x6958
.L08130BB4:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08130C1A
	mov r3, r8
	strh r3, [r7, #0x1c]
	ldr r1, .L08130BD8
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0x28
	bne .L08130BE4
	strh r2, [r1]
	ldr r0, .L08130BDC
	ldr r1, .L08130BE0
	ldr r1, [r1, #4]
	str r1, [r0]
	b .L08130BE8
.L08130BD8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08130BDC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08130BE0: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08130BE4:
	movs r0, #0x24
	strh r0, [r1]
.L08130BE8:
	ldr r1, .L08130C28
	movs r0, #0
	strh r0, [r1]
	ldr r2, .L08130C2C
	ldr r1, .L08130C30
	movs r0, #0
	strh r0, [r1, #0x10]
	strh r0, [r1, #8]
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0x40
	strh r0, [r1]
	strh r0, [r2, #0x30]
	strh r0, [r2, #0x20]
	strh r0, [r2, #0x10]
	strh r0, [r2]
	mov r5, sb
	strh r0, [r5]
	ldr r0, .L08130C34
	ldr r0, [r0]
	bl sub_080D34F0
	movs r0, #0x66
	bl sub_080C51D4
.L08130C1A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08130C28: .4byte 0x0300699C @ IWRAM+0x699C
.L08130C2C: .4byte 0x03006620 @ IWRAM+0x6620
.L08130C30: .4byte 0x03006920 @ IWRAM+0x6920
.L08130C34: .4byte 0x030068A4 @ IWRAM+0x68A4

	thumb_func_start sub_08130C38
sub_08130C38: @ 0x08130C38
	ldr r0, .L08130C44
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L08130C48
	strh r1, [r0]
	bx lr
.L08130C44: .4byte 0x03006848 @ IWRAM+0x6848
.L08130C48: .4byte 0x03006680 @ IWRAM+0x6680

	thumb_func_start sub_08130C4C
sub_08130C4C: @ 0x08130C4C
	movs r1, #0
	strh r1, [r0, #0x1c]
	ldr r0, .L08130C60
	strh r1, [r0]
	ldr r0, .L08130C64
	strh r1, [r0]
	ldr r0, .L08130C68
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L08130C60: .4byte 0x0300696C @ IWRAM+0x696C
.L08130C64: .4byte 0x03006940 @ IWRAM+0x6940
.L08130C68: .4byte 0x030068AC @ IWRAM+0x68AC

	thumb_func_start sub_08130C6C
sub_08130C6C: @ 0x08130C6C
.L08130C6C:
	push {r4, r5, lr}
	ldr r1, .L08130CBC
	ldr r0, .L08130CC0
	strh r0, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	strh r0, [r1, #8]
	ldr r0, .L08130CC4
	ldrh r2, [r0]
	adds r5, r1, #0
	cmp r2, #0xff
	bne .L08130CD4
	ldr r1, .L08130CC8
	ldr r0, .L08130CCC
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	ldr r4, .L08130CD0
	lsls r0, r1, #2
	adds r3, r0, r1
.L08130CA0:
	lsls r1, r2, #1
	adds r1, r1, r5
	adds r0, r3, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #4
	bls .L08130CA0
	b .L08130D0E
	.byte 0x00, 0x00
.L08130CBC: .4byte 0x03006980 @ IWRAM+0x6980
.L08130CC0: .4byte 0x0000FFFF
.L08130CC4: .4byte 0x030068D8 @ IWRAM+0x68D8
.L08130CC8: .4byte 0x0300696C @ IWRAM+0x696C
.L08130CCC: .4byte 0x03006940 @ IWRAM+0x6940
.L08130CD0: .4byte gUnknown_0878FDEC
.L08130CD4:
	ldr r0, .L08130D14
	ldr r3, .L08130D18
	adds r1, r2, r3
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r0, .L08130D1C
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	ldr r3, .L08130D20
	adds r4, r3, #0
	ldrh r0, [r3]
	cmp r1, r0
	blo .L08130D04
.L08130CF4:
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r1, r0
	bhs .L08130CF4
.L08130D04:
	adds r0, r2, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r5]
.L08130D0E:
	pop {r4, r5}
	pop {r0}
	bx r0
.L08130D14: .4byte 0x0300696C @ IWRAM+0x696C
.L08130D18: .4byte 0xFFFFFEE0
.L08130D1C: .4byte 0x03006940 @ IWRAM+0x6940
.L08130D20: .4byte gUnknown_0878FDCC

	thumb_func_start sub_08130D24
sub_08130D24: @ 0x08130D24
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	ldr r4, .L08130DDC
	ldrh r5, [r4]
	movs r7, #0xf
	ands r7, r5
	mov sl, r7
	ldr r2, .L08130DE0
	ldr r3, .L08130DE4
	ldr r6, .L08130DE8
	movs r1, #0
	ldrsh r0, [r6, r1]
	lsls r0, r0, #2
	lsls r1, r7, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r0, #8
	strh r0, [r2]
	ldr r2, .L08130DEC
	mov r8, r2
	movs r2, #0
	ldrsh r0, [r6, r2]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r3, r8
	strh r0, [r3]
	ldr r1, .L08130DF0
	movs r0, #0x13
	strh r0, [r1]
	ldr r1, .L08130DF4
	movs r0, #1
	strh r0, [r1]
	ldr r0, .L08130DF8
	mov ip, r0
	ldrh r0, [r0]
	mov r8, r6
	mov r2, ip
	cmp r0, #0
	beq .L08130D8A
	subs r0, #1
	strh r0, [r2]
.L08130D8A:
	ldr r0, .L08130DFC
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L08130D9A
	b .L08130EEC
.L08130D9A:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq .L08130E10
	movs r2, #0
	strh r2, [r6]
	cmp r7, #0
	beq .L08130DAC
	b .L08131280
.L08130DAC:
	movs r0, #0xf0
	ands r0, r5
	cmp r0, #0
	beq .L08130DB6
	b .L0813125C
.L08130DB6:
	ldr r5, .L08130E00
	ldr r4, .L08130E04
	movs r3, #0
	ldrsh r0, [r4, r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r3, .L08130E08
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08130E0C
	ldr r0, [r0]
	movs r2, #0
	ldrsh r1, [r6, r2]
	b .L08131234
	.byte 0x00, 0x00
.L08130DDC: .4byte 0x03006844 @ IWRAM+0x6844
.L08130DE0: .4byte 0x0300689C @ IWRAM+0x689C
.L08130DE4: .4byte gUnknown_0878FBA4
.L08130DE8: .4byte 0x0300696C @ IWRAM+0x696C
.L08130DEC: .4byte 0x0300695C @ IWRAM+0x695C
.L08130DF0: .4byte 0x030066A0 @ IWRAM+0x66A0
.L08130DF4: .4byte 0x03006958 @ IWRAM+0x6958
.L08130DF8: .4byte 0x030068AC @ IWRAM+0x68AC
.L08130DFC: .4byte 0x03003964 @ IWRAM+0x3964
.L08130E00: .4byte gUnknown_0878FDB4
.L08130E04: .4byte 0x03006940 @ IWRAM+0x6940
.L08130E08: .4byte 0x0000FFFF
.L08130E0C: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130E10:
	ldr r1, .L08130E38
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne .L08130E1E
	b .L0813134E
.L08130E1E:
	movs r0, #3
	mov r3, ip
	strh r0, [r3]
	cmp r7, #1
	bne .L08130E42
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r0, #3
	cmp r0, #0
	blt .L08130E3C
	subs r0, r2, #3
	strh r0, [r1]
	b .L08130ED4
.L08130E38: .4byte 0x03006940 @ IWRAM+0x6940
.L08130E3C:
	movs r0, #0
	strh r0, [r1]
	b .L08130ED4
.L08130E42:
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, #4
	cmp r0, #0
	blt .L08130E50
	subs r0, r2, #4
	b .L08130E52
.L08130E50:
	movs r0, #0
.L08130E52:
	strh r0, [r1]
	ldrh r1, [r4]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne .L08130EB0
	ldr r5, .L08130EA0
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r4, .L08130EA4
	movs r3, #0
	ldrsh r1, [r4, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r3, .L08130EA8
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08130EAC
	ldr r0, [r0]
	mov r2, r8
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r3, #0
	ldrsh r2, [r4, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r3, [r1]
	movs r1, #3
	movs r2, #0
	bl sub_080D34A4
	b .L08130ED4
.L08130EA0: .4byte gUnknown_0878FDB4
.L08130EA4: .4byte 0x03006940 @ IWRAM+0x6940
.L08130EA8: .4byte 0x0000FFFF
.L08130EAC: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130EB0:
	bl sub_08130C6C
	ldr r4, .L08130EE0
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	ldrh r3, [r4, #6]
	ldrh r4, [r4, #8]
	str r4, [sp]
	bl sub_080D347C
	ldr r0, .L08130EE4
	ldr r0, [r0]
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl sub_080D34A4
.L08130ED4:
	ldr r0, .L08130EE8
	ldrh r0, [r0]
	bl sub_08133F14
	b .L08131280
	.byte 0x00, 0x00
.L08130EE0: .4byte 0x03006980 @ IWRAM+0x6980
.L08130EE4: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130EE8: .4byte 0x03006940 @ IWRAM+0x6940
.L08130EEC:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08130EF8
	b .L08131078
.L08130EF8:
	cmp r7, #1
	bne .L08130F4E
	ldrh r4, [r6]
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #2
	bne .L08130F48
	ldr r2, .L08130F28
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	adds r0, #3
	cmp r0, #0xa
	bgt .L08130F2C
	movs r0, #3
	mov r4, ip
	strh r0, [r4]
	ldrh r0, [r2]
	adds r0, #3
.L08130F1E:
	strh r0, [r2]
	ldrh r0, [r2]
	bl sub_08133F14
	b .L08131280
.L08130F28: .4byte 0x03006940 @ IWRAM+0x6940
.L08130F2C:
	ldrh r3, [r2]
	adds r1, r4, r3
	movs r0, #0xb
	subs r0, r0, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bne .L08130F3E
	b .L0813134E
.L08130F3E:
	movs r0, #3
	mov r4, ip
	strh r0, [r4]
	adds r0, r1, r3
	b .L08130F1E
.L08130F48:
	movs r0, #2
	strh r0, [r6]
	b .L08131280
.L08130F4E:
	ldrh r7, [r6]
	movs r0, #0
	ldrsh r2, [r6, r0]
	cmp r2, #3
	bne .L08131034
	adds r0, r2, #0
	ldr r5, .L08130FB8
	movs r3, #0
	ldrsh r1, [r5, r3]
	adds r0, r0, r1
	adds r0, #4
	cmp r0, #0xa
	bgt .L08130FC8
	mov r0, ip
	strh r2, [r0]
	ldrh r0, [r5]
	adds r0, #4
	strh r0, [r5]
	ldrh r0, [r5]
	bl sub_08133F14
	ldrh r1, [r4]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq .L08130F84
	b .L0813125C
.L08130F84:
	ldr r4, .L08130FBC
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r3, .L08130FC0
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08130FC4
	ldr r0, [r0]
	movs r3, #0
	ldrsh r1, [r6, r3]
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	b .L0813123E
	.byte 0x00, 0x00
.L08130FB8: .4byte 0x03006940 @ IWRAM+0x6940
.L08130FBC: .4byte gUnknown_0878FDB4
.L08130FC0: .4byte 0x0000FFFF
.L08130FC4: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130FC8:
	ldrh r3, [r5]
	adds r1, r7, r3
	movs r0, #0xb
	subs r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne .L08130FDA
	b .L0813134E
.L08130FDA:
	mov r1, ip
	strh r2, [r1]
	adds r0, r0, r3
	strh r0, [r5]
	ldrh r0, [r5]
	bl sub_08133F14
	ldrh r1, [r4]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq .L08130FF4
	b .L0813125C
.L08130FF4:
	ldr r4, .L08131028
	movs r2, #0
	ldrsh r0, [r6, r2]
	movs r3, #0
	ldrsh r1, [r5, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r3, .L0813102C
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08131030
	ldr r0, [r0]
	movs r2, #0
	ldrsh r1, [r6, r2]
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	b .L0813123E
	.byte 0x00, 0x00
.L08131028: .4byte gUnknown_0878FDB4
.L0813102C: .4byte 0x0000FFFF
.L08131030: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08131034:
	movs r0, #3
	strh r0, [r6]
	movs r0, #0xf0
	ands r0, r5
	cmp r0, #0
	beq .L08131042
	b .L0813125C
.L08131042:
	ldr r5, .L08131068
	ldr r4, .L0813106C
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, #3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r3, .L08131070
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08131074
	ldr r0, [r0]
	movs r2, #0
	ldrsh r1, [r6, r2]
	b .L08131234
.L08131068: .4byte gUnknown_0878FDB4
.L0813106C: .4byte 0x03006940 @ IWRAM+0x6940
.L08131070: .4byte 0x0000FFFF
.L08131074: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08131078:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L0813114C
	ldrh r1, [r6]
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #0
	beq .L081310D8
	subs r0, r1, #1
	strh r0, [r6]
	cmp r7, #0
	beq .L08131094
	b .L08131280
.L08131094:
	movs r0, #0xf0
	ands r0, r5
	cmp r0, #0
	beq .L0813109E
	b .L0813125C
.L0813109E:
	ldr r5, .L081310C8
	movs r3, #0
	ldrsh r0, [r6, r3]
	ldr r4, .L081310CC
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r3, .L081310D0
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L081310D4
	ldr r0, [r0]
	movs r3, #0
	ldrsh r1, [r6, r3]
	b .L08131234
.L081310C8: .4byte gUnknown_0878FDB4
.L081310CC: .4byte 0x03006940 @ IWRAM+0x6940
.L081310D0: .4byte 0x0000FFFF
.L081310D4: .4byte 0x030068A4 @ IWRAM+0x68A4
.L081310D8:
	ldr r5, .L0813113C
	ldrh r1, [r5]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bne .L081310E6
	b .L0813134E
.L081310E6:
	movs r0, #3
	mov r3, ip
	strh r0, [r3]
	subs r0, r1, #1
	strh r0, [r5]
	ldrh r0, [r5]
	bl sub_08133F14
	cmp r7, #0
	beq .L081310FC
	b .L08131280
.L081310FC:
	ldrh r1, [r4]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq .L08131108
	b .L0813125C
.L08131108:
	ldr r4, .L08131140
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r3, .L08131144
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08131148
	ldr r0, [r0]
	movs r3, #0
	ldrsh r1, [r6, r3]
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	b .L0813123E
	.byte 0x00, 0x00
.L0813113C: .4byte 0x03006940 @ IWRAM+0x6940
.L08131140: .4byte gUnknown_0878FDB4
.L08131144: .4byte 0x0000FFFF
.L08131148: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813114C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne .L08131156
	b .L08131290
.L08131156:
	cmp r7, #1
	bne .L08131162
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #2
	beq .L0813116E
.L08131162:
	cmp r7, #0
	bne .L081311F0
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #3
	bne .L081311F0
.L0813116E:
	mov r4, r8
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r5, .L081311DC
	movs r3, #0
	ldrsh r1, [r5, r3]
	adds r0, r0, r1
	cmp r0, #0xa
	ble .L08131182
	b .L0813134E
.L08131182:
	movs r0, #3
	strh r0, [r2]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ldrh r0, [r5]
	bl sub_08133F14
	mov r4, sl
	cmp r4, #0
	bne .L08131280
	ldr r0, .L081311E0
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne .L0813125C
	ldr r4, .L081311E4
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r3, #0
	ldrsh r1, [r5, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r3, .L081311E8
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L081311EC
	ldr r0, [r0]
	mov r2, r8
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	b .L0813123E
	.byte 0x00, 0x00
.L081311DC: .4byte 0x03006940 @ IWRAM+0x6940
.L081311E0: .4byte 0x03006844 @ IWRAM+0x6844
.L081311E4: .4byte gUnknown_0878FDB4
.L081311E8: .4byte 0x0000FFFF
.L081311EC: .4byte 0x030068A4 @ IWRAM+0x68A4
.L081311F0:
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	mov r2, sl
	cmp r2, #0
	bne .L08131280
	ldrh r1, [r4]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne .L0813125C
	ldr r5, .L0813124C
	mov r3, r8
	movs r4, #0
	ldrsh r0, [r3, r4]
	ldr r4, .L08131250
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r3, .L08131254
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08131258
	ldr r0, [r0]
	mov r3, r8
	movs r2, #0
	ldrsh r1, [r3, r2]
.L08131234:
	movs r3, #0
	ldrsh r2, [r4, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r5
.L0813123E:
	ldrh r3, [r1]
	movs r1, #3
	movs r2, #0
	bl sub_080D34A4
	b .L08131280
	.byte 0x00, 0x00
.L0813124C: .4byte gUnknown_0878FDB4
.L08131250: .4byte 0x03006940 @ IWRAM+0x6940
.L08131254: .4byte 0x0000FFFF
.L08131258: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813125C:
	bl sub_08130C6C
	ldr r4, .L08131288
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	ldrh r3, [r4, #6]
	ldrh r4, [r4, #8]
	str r4, [sp]
	bl sub_080D347C
	ldr r0, .L0813128C
	ldr r0, [r0]
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl sub_080D34A4
.L08131280:
	movs r0, #0x64
	bl sub_080C51D4
	b .L0813134E
.L08131288: .4byte 0x03006980 @ IWRAM+0x6980
.L0813128C: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08131290:
	ldr r2, .L081312E4
	ldrh r1, [r2]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L08131334
	mov r1, ip
	ldrh r0, [r1]
	cmp r0, #0
	bne .L0813134E
	ldr r7, .L081312E8
	movs r2, #0
	ldrsh r0, [r6, r2]
	ldr r5, .L081312EC
	movs r3, #0
	ldrsh r1, [r5, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08131304
	mov r0, sl
	cmp r0, #0
	bne .L081312FC
	ldr r1, .L081312F0
	ldr r0, .L081312F4
	ldr r0, [r0, #4]
	str r0, [r1]
	mov r1, sb
	strh r4, [r1, #0x1c]
	ldr r1, .L081312F8
	movs r0, #0x30
	strh r0, [r1]
	movs r0, #0x66
	bl sub_080C51D4
	b .L0813134E
.L081312E4: .4byte 0x030031C4 @ IWRAM+0x31C4
.L081312E8: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L081312EC: .4byte 0x03006940 @ IWRAM+0x6940
.L081312F0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081312F4: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L081312F8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L081312FC:
	movs r0, #0x68
	bl sub_080C51D4
	b .L0813134E
.L08131304:
	mov r2, sb
	strh r4, [r2, #0x1c]
	ldr r1, .L0813132C
	movs r0, #0x30
	strh r0, [r1]
	ldr r2, .L08131330
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r4, #0
	ldrsh r1, [r5, r4]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	strh r0, [r2]
	movs r0, #0x65
	bl sub_080C51D4
	b .L0813134E
	.byte 0x00, 0x00
.L0813132C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08131330: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08131334:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0813134E
	mov r0, sb
	strh r4, [r0, #0x1c]
	ldr r1, .L08131360
	movs r0, #0x2f
	strh r0, [r1]
	movs r0, #0x66
	bl sub_080C51D4
.L0813134E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08131360: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start sub_08131364
sub_08131364: @ 0x08131364
	push {r4, lr}
	ldr r0, .L081313BC
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L081313C0
	strh r1, [r0]
	ldr r2, .L081313C4
	ldr r0, .L081313C8
	adds r1, r0, #0
	adds r1, #0x40
	movs r4, #0
	strh r4, [r1]
	strh r4, [r0, #0x30]
	strh r4, [r0, #0x20]
	strh r4, [r0, #0x10]
	strh r4, [r0]
	strh r4, [r2]
	ldr r0, .L081313CC
	strh r4, [r0]
	ldr r0, .L081313D0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq .L0813139C
	ldr r0, .L081313D4
	ldr r0, [r0]
	bl sub_080D34F0
.L0813139C:
	ldr r0, .L081313D8
	strh r4, [r0]
	ldr r0, .L081313DC
	strh r4, [r0]
	ldr r0, .L081313E0
	strh r4, [r0]
	ldr r0, .L081313E4
	strh r4, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081313BC: .4byte 0x03006848 @ IWRAM+0x6848
.L081313C0: .4byte 0x03006680 @ IWRAM+0x6680
.L081313C4: .4byte 0x03006678 @ IWRAM+0x6678
.L081313C8: .4byte 0x03006620 @ IWRAM+0x6620
.L081313CC: .4byte 0x03006958 @ IWRAM+0x6958
.L081313D0: .4byte 0x03006844 @ IWRAM+0x6844
.L081313D4: .4byte 0x030068A4 @ IWRAM+0x68A4
.L081313D8: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L081313DC: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L081313E0: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L081313E4: .4byte 0x0203DB4A @ EWRAM+0x3DB4A

	thumb_func_start sub_081313E8
sub_081313E8: @ 0x081313E8
	movs r1, #0
	strh r1, [r0, #0x1c]
	ldr r0, .L081313F8
	strh r1, [r0]
	ldr r0, .L081313FC
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L081313F8: .4byte 0x0300696C @ IWRAM+0x696C
.L081313FC: .4byte 0x03006940 @ IWRAM+0x6940

	thumb_func_start sub_08131400
sub_08131400: @ 0x08131400
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r6, #0
	bl sub_081394B4
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
	bl sub_080C51D4
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
	bl sub_080C32D4
	adds r4, r0, #0
	ldrh r1, [r7]
	movs r0, #0xff
	bl sub_08131AB0
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
	bl sub_080C51D4
	b .L08131684
	.byte 0x00, 0x00
.L08131640: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08131644: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08131648:
	ldrh r0, [r7]
	bl sub_080C3328
	rsbs r0, r6, #0
	bl sub_080C31B4
	ldr r1, .L08131664
	ldr r0, .L08131668
	ldr r0, [r0, #8]
	str r0, [r1]
	movs r0, #0x65
	bl sub_080C51D4
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
	bl sub_080C51D4
.L08131684:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08131690: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start sub_08131694
sub_08131694: @ 0x08131694
	push {lr}
	ldr r0, .L081316D8
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L081316DC
	strh r1, [r0]
	ldr r0, .L081316E0
	strh r1, [r0]
	ldr r1, .L081316E4
	adds r2, r1, #0
	adds r2, #0x40
	movs r0, #0
	strh r0, [r2]
	strh r0, [r1, #0x30]
	strh r0, [r1, #0x20]
	strh r0, [r1, #0x10]
	strh r0, [r1]
	ldr r1, .L081316E8
	strh r0, [r1]
	ldr r1, .L081316EC
	strh r0, [r1]
	ldr r1, .L081316F0
	strh r0, [r1]
	ldr r1, .L081316F4
	strh r0, [r1]
	ldr r1, .L081316F8
	strh r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081316D8: .4byte 0x030068AC @ IWRAM+0x68AC
.L081316DC: .4byte 0x03006848 @ IWRAM+0x6848
.L081316E0: .4byte 0x03006680 @ IWRAM+0x6680
.L081316E4: .4byte 0x03006620 @ IWRAM+0x6620
.L081316E8: .4byte 0x03006958 @ IWRAM+0x6958
.L081316EC: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L081316F0: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L081316F4: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L081316F8: .4byte 0x0203DB4A @ EWRAM+0x3DB4A

	thumb_func_start sub_081316FC
sub_081316FC: @ 0x081316FC
.L081316FC:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl sub_080C3100
	mov r8, r0
	ldr r0, .L08131760
	ldr r7, [r0]
	ldr r6, .L08131764
	ldrh r1, [r6]
	movs r0, #0xff
	bl sub_08131AB0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, r4, #0
	ldrh r0, [r6]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, r2, #0
	ldr r0, .L08131768
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x2a
	beq .L08131736
	b .L08131908
.L08131736:
	ldr r0, .L0813176C
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #1
	beq .L08131742
	b .L08131854
.L08131742:
	ldr r5, .L08131770
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0x63
	bne .L08131780
	ldr r1, .L08131774
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131778
	ldr r0, .L0813177C
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L08131A68
	.byte 0x00, 0x00
.L08131760: .4byte 0x03006694 @ IWRAM+0x6694
.L08131764: .4byte 0x030069A8 @ IWRAM+0x69A8
.L08131768: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813176C: .4byte 0x030068BC @ IWRAM+0x68BC
.L08131770: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131774: .4byte 0x03006848 @ IWRAM+0x6848
.L08131778: .4byte 0x03006680 @ IWRAM+0x6680
.L0813177C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131780:
	cmp r0, #1
	bgt .L081317D8
	ldrh r0, [r6]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi .L0813179C
	ldr r1, .L08131798
	movs r0, #0
	b .L081317C6
.L08131798: .4byte 0x03006848 @ IWRAM+0x6848
.L0813179C:
	movs r2, #0
	ldrsh r0, [r5, r2]
	adds r0, #1
	muls r0, r7, r0
	add r0, r8
	ldr r1, .L081317B4
	cmp r0, r1
	bls .L081317BC
	ldr r1, .L081317B8
	movs r0, #0
	b .L081317C6
	.byte 0x00, 0x00
.L081317B4: .4byte 0x000F423F
.L081317B8: .4byte 0x03006848 @ IWRAM+0x6848
.L081317BC:
	ldr r1, .L081317CC
	ldr r0, .L081317D0
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
.L081317C6:
	strh r0, [r1]
	ldr r1, .L081317D4
	b .L08131A66
.L081317CC: .4byte 0x03006848 @ IWRAM+0x6848
.L081317D0: .4byte 0x0300696C @ IWRAM+0x696C
.L081317D4: .4byte 0x03006680 @ IWRAM+0x6680
.L081317D8:
	movs r3, #0
	ldrsh r4, [r5, r3]
	ldrh r0, [r6]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bge .L08131834
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r0, #1
	muls r0, r7, r0
	add r0, r8
	ldr r1, .L08131804
	cmp r0, r1
	bls .L08131810
	ldr r1, .L08131808
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L0813180C
	b .L0813181E
.L08131804: .4byte 0x000F423F
.L08131808: .4byte 0x03006848 @ IWRAM+0x6848
.L0813180C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131810:
	ldr r2, .L08131828
	ldr r1, .L0813182C
	ldrh r0, [r1]
	lsls r0, r0, #1
	adds r0, #2
	strh r0, [r2]
	adds r0, r1, #0
.L0813181E:
	ldr r1, .L08131830
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L08131A68
.L08131828: .4byte 0x03006848 @ IWRAM+0x6848
.L0813182C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131830: .4byte 0x03006680 @ IWRAM+0x6680
.L08131834:
	ldr r1, .L08131848
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L0813184C
	ldr r0, .L08131850
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L08131A68
	.byte 0x00, 0x00
.L08131848: .4byte 0x03006848 @ IWRAM+0x6848
.L0813184C: .4byte 0x03006680 @ IWRAM+0x6680
.L08131850: .4byte 0x0300696C @ IWRAM+0x696C
.L08131854:
	ldr r0, .L081318A8
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov sb, r0
	cmp r1, #0x59
	bgt .L081318E8
	mov r0, sb
	movs r1, #0
	ldrsh r5, [r0, r1]
	cmp r5, r2
	beq .L081318E8
	adds r5, #1
	ldrh r0, [r6]
	bl sub_080C32D4
	adds r4, r0, #0
	ldrh r1, [r6]
	movs r0, #0xff
	bl sub_08131AB0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r0
	cmp r5, r4
	bgt .L081318E8
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, #1
	muls r0, r7, r0
	add r0, r8
	ldr r1, .L081318AC
	cmp r0, r1
	bls .L081318B8
	ldr r1, .L081318B0
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L081318B4
	b .L081318C6
	.byte 0x00, 0x00
.L081318A8: .4byte 0x030065FC @ IWRAM+0x65FC
.L081318AC: .4byte 0x000F423F
.L081318B0: .4byte 0x03006848 @ IWRAM+0x6848
.L081318B4: .4byte 0x0300696C @ IWRAM+0x696C
.L081318B8:
	ldr r2, .L081318D8
	ldr r1, .L081318DC
	ldrh r0, [r1]
	lsls r0, r0, #1
	adds r0, #3
	strh r0, [r2]
	adds r0, r1, #0
.L081318C6:
	ldr r1, .L081318E0
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	strh r0, [r1]
	ldr r0, .L081318E4
	mov sb, r0
	b .L08131A5C
	.byte 0x00, 0x00
.L081318D8: .4byte 0x03006848 @ IWRAM+0x6848
.L081318DC: .4byte 0x0300696C @ IWRAM+0x696C
.L081318E0: .4byte 0x03006680 @ IWRAM+0x6680
.L081318E4: .4byte 0x030065FC @ IWRAM+0x65FC
.L081318E8:
	ldr r1, .L081318FC
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131900
	ldr r0, .L08131904
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	b .L08131A5A
	.byte 0x00, 0x00
.L081318FC: .4byte 0x03006848 @ IWRAM+0x6848
.L08131900: .4byte 0x03006680 @ IWRAM+0x6680
.L08131904: .4byte 0x0300696C @ IWRAM+0x696C
.L08131908:
	ldr r0, .L08131930
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L081319C4
	ldr r0, .L08131934
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov sb, r0
	cmp r1, #0x63
	bne .L08131944
	ldr r1, .L08131938
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L0813193C
	ldr r0, .L08131940
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L081319AA
.L08131930: .4byte 0x030068BC @ IWRAM+0x68BC
.L08131934: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131938: .4byte 0x03006848 @ IWRAM+0x6848
.L0813193C: .4byte 0x03006680 @ IWRAM+0x6680
.L08131940: .4byte 0x0300696C @ IWRAM+0x696C
.L08131944:
	adds r0, r4, r2
	mov r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	cmp r0, #0x62
	ble .L08131970
	ldr r1, .L08131964
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131968
	ldr r0, .L0813196C
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L081319AA
	.byte 0x00, 0x00
.L08131964: .4byte 0x03006848 @ IWRAM+0x6848
.L08131968: .4byte 0x03006680 @ IWRAM+0x6680
.L0813196C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131970:
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, #1
	muls r0, r7, r0
	cmp r0, r8
	bls .L0813199C
	ldr r1, .L08131990
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131994
	ldr r0, .L08131998
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L081319AA
.L08131990: .4byte 0x03006848 @ IWRAM+0x6848
.L08131994: .4byte 0x03006680 @ IWRAM+0x6680
.L08131998: .4byte 0x0300696C @ IWRAM+0x696C
.L0813199C:
	ldr r1, .L081319B8
	ldr r0, .L081319BC
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	strh r0, [r1]
	ldr r1, .L081319C0
.L081319AA:
	strh r0, [r1]
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #1
	bgt .L08131A6A
	b .L08131A66
.L081319B8: .4byte 0x03006848 @ IWRAM+0x6848
.L081319BC: .4byte 0x0300696C @ IWRAM+0x696C
.L081319C0: .4byte 0x03006680 @ IWRAM+0x6680
.L081319C4:
	ldr r0, .L081319E4
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov sb, r0
	cmp r1, #0x63
	bne .L081319F4
	ldr r1, .L081319E8
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L081319EC
	ldr r0, .L081319F0
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	b .L08131A5A
	.byte 0x00, 0x00
.L081319E4: .4byte 0x030065FC @ IWRAM+0x65FC
.L081319E8: .4byte 0x03006848 @ IWRAM+0x6848
.L081319EC: .4byte 0x03006680 @ IWRAM+0x6680
.L081319F0: .4byte 0x0300696C @ IWRAM+0x696C
.L081319F4:
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r0, #1
	muls r0, r7, r0
	cmp r0, r8
	bls .L08131A20
	ldr r1, .L08131A14
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131A18
	ldr r0, .L08131A1C
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	b .L08131A5A
.L08131A14: .4byte 0x03006848 @ IWRAM+0x6848
.L08131A18: .4byte 0x03006680 @ IWRAM+0x6680
.L08131A1C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131A20:
	adds r0, r5, r3
	mov r3, sb
	ldrh r3, [r3]
	adds r0, r0, r3
	cmp r0, #0x62
	ble .L08131A4C
	ldr r1, .L08131A40
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131A44
	ldr r0, .L08131A48
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	b .L08131A5A
	.byte 0x00, 0x00
.L08131A40: .4byte 0x03006848 @ IWRAM+0x6848
.L08131A44: .4byte 0x03006680 @ IWRAM+0x6680
.L08131A48: .4byte 0x0300696C @ IWRAM+0x696C
.L08131A4C:
	ldr r1, .L08131A78
	ldr r0, .L08131A7C
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	strh r0, [r1]
	ldr r1, .L08131A80
.L08131A5A:
	strh r0, [r1]
.L08131A5C:
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #1
	bne .L08131A6A
.L08131A66:
	movs r0, #0
.L08131A68:
	strh r0, [r1]
.L08131A6A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08131A78: .4byte 0x03006848 @ IWRAM+0x6848
.L08131A7C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131A80: .4byte 0x03006680 @ IWRAM+0x6680

	thumb_func_start sub_08131A84
sub_08131A84: @ 0x08131A84
	push {r4, lr}
	movs r4, #0
	strh r4, [r0, #0x1c]
	ldr r1, .L08131AA4
	movs r0, #1
	strh r0, [r1]
	bl sub_081316FC
	ldr r0, .L08131AA8
	strh r4, [r0]
	ldr r1, .L08131AAC
	movs r0, #0xa
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L08131AA4: .4byte 0x030068BC @ IWRAM+0x68BC
.L08131AA8: .4byte 0x030065E4 @ IWRAM+0x65E4
.L08131AAC: .4byte 0x030068D4 @ IWRAM+0x68D4

	thumb_func_start sub_08131AB0
sub_08131AB0: @ 0x08131AB0
.L08131AB0:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	adds r6, r0, #0
	movs r7, #0
	cmp r0, #0xcf
	bls .L08131AC6
	movs r0, #0
	b .L08131B16
.L08131AC6:
	bl sub_080D2268
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	bne .L08131B04
	movs r4, #0
.L08131AD8:
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08131AF8
	adds r0, r4, #0
	adds r1, r5, #0
	bl Combatant_GetEquip
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r6
	bne .L08131AF8
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08131AF8:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #2
	bls .L08131AD8
	b .L08131B14
.L08131B04:
	adds r1, r5, #0
	bl Combatant_GetEquip
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r6
	bne .L08131B14
	movs r7, #1
.L08131B14:
	adds r0, r7, #0
.L08131B16:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_08131B1C
sub_08131B1C: @ 0x08131B1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	bl sub_080C3100
	adds r6, r0, #0
	ldr r0, .L08131B78
	ldr r7, [r0]
	ldr r0, .L08131B7C
	mov r8, r0
	ldrh r1, [r0]
	movs r0, #0xff
	bl sub_08131AB0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r1, sb
	str r1, [sp, #4]
	mov r2, r8
	ldrh r0, [r2]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov sl, r4
	ldr r1, .L08131B80
	movs r0, #0x15
	strh r0, [r1]
	movs r5, #1
	ldr r3, .L08131B84
	strh r5, [r3]
	ldr r1, .L08131B88
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq .L08131B8C
	subs r0, r2, #1
	strh r0, [r1]
	b .L0813216E
	.byte 0x00, 0x00
.L08131B78: .4byte 0x03006694 @ IWRAM+0x6694
.L08131B7C: .4byte 0x030069A8 @ IWRAM+0x69A8
.L08131B80: .4byte 0x030066A0 @ IWRAM+0x66A0
.L08131B84: .4byte 0x03006958 @ IWRAM+0x6958
.L08131B88: .4byte 0x030068D4 @ IWRAM+0x68D4
.L08131B8C:
	ldr r3, .L08131BAC
	ldrh r1, [r3]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L08131BB4
	ldr r0, .L08131BB0
	ldrh r1, [r0]
	eors r1, r5
	strh r1, [r0]
	mov r4, r8
	ldrh r0, [r4]
	bl sub_081305D8
	b .L0813216E
	.byte 0x00, 0x00
.L08131BAC: .4byte 0x030031C4 @ IWRAM+0x31C4
.L08131BB0: .4byte 0x030065E4 @ IWRAM+0x65E4
.L08131BB4:
	ldr r0, .L08131C40
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne .L08131BC6
	b .L08131F4C
.L08131BC6:
	ldr r0, .L08131C44
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x2a
	beq .L08131BD2
	b .L08131D68
.L08131BD2:
	ldr r0, .L08131C48
	movs r2, #0
	ldrsh r3, [r0, r2]
	adds r1, r7, #0
	muls r1, r3, r1
	adds r1, r1, r6
	ldr r2, .L08131C4C
	mov r8, r0
	cmp r1, r2
	bls .L08131BE8
	b .L08131EB4
.L08131BE8:
	ldr r0, .L08131C50
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L08131C88
	adds r0, r3, #1
	cmp r0, r4
	bgt .L08131C5C
	muls r0, r7, r0
	adds r0, r0, r6
	ldr r1, .L08131C54
	cmp r0, r1
	bls .L08131C04
	b .L08131EB4
.L08131C04:
	mov r2, r8
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x63
	ble .L08131C18
	movs r0, #0x63
	strh r0, [r2]
.L08131C18:
	ldr r4, .L08131C58
	mov r3, r8
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
	.byte 0x00, 0x00
.L08131C40: .4byte 0x03003964 @ IWRAM+0x3964
.L08131C44: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08131C48: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131C4C: .4byte 0x000F423E
.L08131C50: .4byte 0x030068BC @ IWRAM+0x68BC
.L08131C54: .4byte 0x000F423F
.L08131C58: .4byte 0x03006620 @ IWRAM+0x6620
.L08131C5C:
	mov r0, r8
	strh r4, [r0]
	ldr r4, .L08131C84
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131C84: .4byte 0x03006620 @ IWRAM+0x6620
.L08131C88:
	adds r0, r3, #0
	adds r0, #0xa
	cmp r0, r4
	bgt .L08131D2C
	muls r0, r7, r0
	adds r0, r0, r6
	ldr r1, .L08131CC8
	cmp r0, r1
	bhi .L08131CD0
	mov r4, r8
	ldrh r0, [r4]
	adds r0, #0xa
	strh r0, [r4]
	ldr r4, .L08131CCC
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r3, r8
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131CC8: .4byte 0x000F423F
.L08131CCC: .4byte 0x03006620 @ IWRAM+0x6620
.L08131CD0:
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r2, r7, #0
	muls r2, r0, r2
	movs r3, #0
	adds r1, r2, r6
	ldr r0, .L08131CE4
	ldr r4, .L08131CE8
	b .L08131CF8
.L08131CE4: .4byte 0x000F423F
.L08131CE8: .4byte 0x03006620 @ IWRAM+0x6620
.L08131CEC:
	adds r2, r2, r7
	adds r3, #1
	cmp r3, #9
	bhi .L08131CFE
	adds r1, r2, r6
	ldr r0, .L08131D28
.L08131CF8:
	cmp r1, r0
	bls .L08131CEC
	subs r3, #1
.L08131CFE:
	mov r1, r8
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r3, r8
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131D28: .4byte 0x000F423F
.L08131D2C:
	adds r0, r4, #0
	muls r0, r7, r0
	adds r0, r0, r6
	ldr r1, .L08131D60
	cmp r0, r1
	bhi .L08131CD0
	mov r2, r8
	strh r4, [r2]
	ldr r4, .L08131D64
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131D60: .4byte 0x000F423F
.L08131D64: .4byte 0x03006620 @ IWRAM+0x6620
.L08131D68:
	ldr r0, .L08131DD0
	ldrh r3, [r0]
	mov ip, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r8, r0
	cmp r1, #0x63
	bne .L08131D7A
	b .L08131EB4
.L08131D7A:
	ldr r1, .L08131DD4
	ldrh r5, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xa
	bne .L08131E64
	mov r0, sb
	adds r3, r4, r0
	mov r4, r8
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r0, r3, r2
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r0, r0, r1
	cmp r0, #0x63
	bgt .L08131E24
	adds r0, r2, r1
	muls r0, r7, r0
	cmp r0, r6
	bhi .L08131DDC
	mov r1, ip
	adds r0, r1, r5
	mov r2, r8
	strh r0, [r2]
	ldr r4, .L08131DD8
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131DD0: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131DD4: .4byte 0x030068BC @ IWRAM+0x68BC
.L08131DD8: .4byte 0x03006620 @ IWRAM+0x6620
.L08131DDC:
	mov r3, r8
	movs r4, #0
	ldrsh r0, [r3, r4]
	adds r2, r7, #0
	muls r2, r0, r2
	movs r3, #0
	ldr r4, .L08131E20
.L08131DEA:
	adds r3, #1
	adds r2, r2, r7
	cmp r2, r6
	bls .L08131DEA
	subs r0, r3, #1
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131E20: .4byte 0x03006620 @ IWRAM+0x6620
.L08131E24:
	movs r0, #0x63
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r7, #0
	muls r0, r5, r0
	cmp r0, r6
	bhi .L08131DDC
	mov r3, r8
	strh r5, [r3]
	ldr r4, .L08131E60
	adds r0, r5, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r4, #0x34]
	adds r0, r5, #0
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L08131E54:
	str r0, [r4, #0x44]
	movs r0, #0x64
	bl sub_080C51D4
	b .L08131EB4
	.byte 0x00, 0x00
.L08131E60: .4byte 0x03006620 @ IWRAM+0x6620
.L08131E64:
	ldr r0, [sp, #4]
	add r0, sl
	mov r4, r8
	movs r3, #0
	ldrsh r2, [r4, r3]
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r0, r0, r1
	cmp r0, #0x63
	bgt .L08131EB4
	adds r0, r2, r1
	muls r0, r7, r0
	cmp r0, r6
	bhi .L08131EB4
	mov r1, ip
	adds r0, r1, r5
	mov r2, r8
	strh r0, [r2]
	ldr r4, .L08131F20
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x44]
	movs r0, #0x64
	bl sub_080C51D4
.L08131EB4:
	bl sub_081316FC
	ldr r2, .L08131F24
	ldr r0, .L08131F28
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	str r0, [r2]
	ldr r1, .L08131F2C
	cmp r0, r1
	bhi .L08131ECC
	b .L0813216E
.L08131ECC:
	str r1, [r2]
	ldr r2, .L08131F30
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0x2a
	beq .L08131EDA
	b .L0813216E
.L08131EDA:
	ldr r1, .L08131F34
	movs r0, #0
	strh r0, [r1]
	movs r4, #0
	movs r0, #1
	ldr r1, [sp]
	strh r0, [r1, #0x1c]
	movs r0, #0x47
	strh r0, [r2]
	ldr r0, .L08131F38
	strh r4, [r0]
	ldr r0, .L08131F3C
	strh r4, [r0]
	ldr r0, .L08131F40
	ldr r0, [r0]
	bl sub_080D34F0
	ldr r1, .L08131F20
	ldr r0, .L08131F44
	strh r4, [r0, #0x10]
	strh r4, [r0, #8]
	strh r4, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	strh r4, [r0]
	strh r4, [r1, #0x30]
	strh r4, [r1, #0x20]
	strh r4, [r1, #0x10]
	strh r4, [r1]
	ldr r0, .L08131F48
	strh r4, [r0]
	movs r0, #0x66
	bl sub_080C51D4
	b .L0813216E
.L08131F20: .4byte 0x03006620 @ IWRAM+0x6620
.L08131F24: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L08131F28: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131F2C: .4byte 0x000F423F
.L08131F30: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08131F34: .4byte 0x030068A0 @ IWRAM+0x68A0
.L08131F38: .4byte 0x0300699C @ IWRAM+0x699C
.L08131F3C: .4byte 0x0300669C @ IWRAM+0x669C
.L08131F40: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08131F44: .4byte 0x03006920 @ IWRAM+0x6920
.L08131F48: .4byte 0x03006958 @ IWRAM+0x6958
.L08131F4C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08132000
	ldr r0, .L08131F80
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0xa
	bne .L08131F8C
	ldr r0, .L08131F84
	movs r4, #0
	ldrsh r1, [r0, r4]
	mov r8, r0
	cmp r1, #0xa
	bgt .L08131F9E
	strh r5, [r0]
	ldr r1, .L08131F88
	movs r0, #1
	str r0, [r1, #0x34]
	str r2, [r1, #0x44]
	movs r0, #0x64
	bl sub_080C51D4
	b .L08131FD4
	.byte 0x00, 0x00
.L08131F80: .4byte 0x030068BC @ IWRAM+0x68BC
.L08131F84: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131F88: .4byte 0x03006620 @ IWRAM+0x6620
.L08131F8C:
	ldr r0, .L08131FF0
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	mov r8, r0
	cmp r1, #0
	ble .L08131FD4
.L08131F9E:
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r3]
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2]
	ldr r4, .L08131FF4
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x44]
	movs r0, #0x64
	bl sub_080C51D4
.L08131FD4:
	bl sub_081316FC
	ldr r2, .L08131FF8
	ldr r0, .L08131FF0
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	str r0, [r2]
	ldr r1, .L08131FFC
	cmp r0, r1
	bhi .L08131FEC
	b .L0813216E
.L08131FEC:
	str r1, [r2]
	b .L0813216E
.L08131FF0: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131FF4: .4byte 0x03006620 @ IWRAM+0x6620
.L08131FF8: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L08131FFC: .4byte 0x000F423F
.L08132000:
	ldrh r1, [r3]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L08132014
	ldr r0, .L08132010
	strh r5, [r0]
	b .L08132024
.L08132010: .4byte 0x030068BC @ IWRAM+0x68BC
.L08132014:
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L08132034
	ldr r1, .L08132030
	movs r0, #0xa
	strh r0, [r1]
.L08132024:
	bl sub_081316FC
	movs r0, #0x64
	bl sub_080C51D4
	b .L0813216E
.L08132030: .4byte 0x030068BC @ IWRAM+0x68BC
.L08132034:
	ldrh r0, [r3]
	movs r2, #1
	adds r4, r2, #0
	ands r4, r0
	cmp r4, #0
	beq .L08132124
	ldr r4, [sp]
	strh r2, [r4, #0x1c]
	ldr r4, .L08132060
	movs r0, #0
	ldrsh r1, [r4, r0]
	cmp r1, #0
	bne .L0813206C
	ldr r0, .L08132064
	strh r1, [r0]
	ldr r1, .L08132068
	movs r0, #0x35
	strh r0, [r1]
	movs r0, #0x66
	bl sub_080C51D4
	b .L081320C6
.L08132060: .4byte 0x030065FC @ IWRAM+0x65FC
.L08132064: .4byte 0x030068A0 @ IWRAM+0x68A0
.L08132068: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813206C:
	ldr r0, .L08132094
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x2a
	bne .L081320A0
	ldr r5, .L08132098
	mov r2, r8
	ldrh r0, [r2]
	bl sub_080C4C7C
	movs r3, #0
	ldrsh r1, [r4, r3]
	muls r0, r1, r0
	str r0, [r5]
	ldr r1, .L0813209C
	cmp r0, r1
	bls .L081320B2
	str r1, [r5]
	b .L081320B2
	.byte 0x00, 0x00
.L08132094: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08132098: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813209C: .4byte 0x000F423F
.L081320A0:
	ldr r2, .L081320F8
	movs r1, #0
	ldrsh r0, [r4, r1]
	muls r0, r7, r0
	str r0, [r2]
	ldr r1, .L081320FC
	cmp r0, r1
	bls .L081320B2
	str r1, [r2]
.L081320B2:
	movs r0, #0x65
	bl sub_080C51D4
	ldr r1, .L08132100
	movs r0, #0x27
	strh r0, [r1]
	ldr r1, .L08132104
	ldr r0, .L08132108
	ldrh r0, [r0]
	strh r0, [r1]
.L081320C6:
	ldr r0, .L0813210C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L08132110
	strh r1, [r0]
	ldr r0, .L08132114
	ldr r0, [r0]
	bl sub_080D34F0
	ldr r2, .L08132118
	ldr r1, .L0813211C
	movs r0, #0
	strh r0, [r1, #0x10]
	strh r0, [r1, #8]
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0x40
	strh r0, [r1]
	strh r0, [r2, #0x30]
	strh r0, [r2, #0x20]
	strh r0, [r2, #0x10]
	strh r0, [r2]
	ldr r1, .L08132120
	strh r0, [r1]
	b .L0813216E
.L081320F8: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L081320FC: .4byte 0x000F423F
.L08132100: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08132104: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08132108: .4byte 0x030069A8 @ IWRAM+0x69A8
.L0813210C: .4byte 0x0300699C @ IWRAM+0x699C
.L08132110: .4byte 0x0300669C @ IWRAM+0x669C
.L08132114: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08132118: .4byte 0x03006620 @ IWRAM+0x6620
.L0813211C: .4byte 0x03006920 @ IWRAM+0x6920
.L08132120: .4byte 0x03006958 @ IWRAM+0x6958
.L08132124:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0813216E
	ldr r0, .L08132180
	strh r4, [r0]
	ldr r3, [sp]
	strh r2, [r3, #0x1c]
	ldr r1, .L08132184
	movs r0, #0x26
	strh r0, [r1]
	ldr r0, .L08132188
	strh r4, [r0]
	ldr r0, .L0813218C
	strh r4, [r0]
	ldr r0, .L08132190
	ldr r0, [r0]
	bl sub_080D34F0
	ldr r1, .L08132194
	ldr r0, .L08132198
	strh r4, [r0, #0x10]
	strh r4, [r0, #8]
	strh r4, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	strh r4, [r0]
	strh r4, [r1, #0x30]
	strh r4, [r1, #0x20]
	strh r4, [r1, #0x10]
	strh r4, [r1]
	ldr r0, .L0813219C
	strh r4, [r0]
	movs r0, #0x66
	bl sub_080C51D4
.L0813216E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08132180: .4byte 0x030068A0 @ IWRAM+0x68A0
.L08132184: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08132188: .4byte 0x0300699C @ IWRAM+0x699C
.L0813218C: .4byte 0x0300669C @ IWRAM+0x669C
.L08132190: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08132194: .4byte 0x03006620 @ IWRAM+0x6620
.L08132198: .4byte 0x03006920 @ IWRAM+0x6920
.L0813219C: .4byte 0x03006958 @ IWRAM+0x6958

	thumb_func_start sub_081321A0
sub_081321A0: @ 0x081321A0
	ldr r0, .L081321AC
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L081321B0
	strh r1, [r0]
	bx lr
.L081321AC: .4byte 0x03006848 @ IWRAM+0x6848
.L081321B0: .4byte 0x03006680 @ IWRAM+0x6680
