	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080C4C18
sub_080C4C18: @ 0x080C4C18
	adds r2, r0, #0
	ldr r0, .L080C4C34
	lsrs r1, r2, #3
	ldr r3, .L080C4C38
	adds r0, r0, r3
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r1, #7
	ands r1, r2
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	bx lr
	.byte 0x00, 0x00
.L080C4C34: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C4C38: .4byte 0x00000ACA

	thumb_func_start sub_080C4C3C
sub_080C4C3C: @ 0x080C4C3C
	ldr r1, .L080C4C58
	lsrs r2, r0, #3
	ldr r3, .L080C4C5C
	adds r1, r1, r3
	adds r2, r2, r1
	movs r1, #7
	ands r1, r0
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080C4C58: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C4C5C: .4byte 0x00000ACA

	thumb_func_start sub_080C4C60
sub_080C4C60: @ 0x080C4C60
.L080C4C60:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xcf
	bhi .L080C4C72
	bl sub_080BF32C
	ldr r0, [r0, #0xc]
	b .L080C4C78
.L080C4C72:
	bl Action_GetRecord
	ldr r0, [r0, #4]
.L080C4C78:
	pop {r1}
	bx r1

	thumb_func_start sub_080C4C7C
sub_080C4C7C: @ 0x080C4C7C
.L080C4C7C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xcf
	bhi .L080C4C8E
	bl sub_080BF32C
	ldr r0, [r0, #0x10]
	b .L080C4C94
.L080C4C8E:
	bl Action_GetRecord
	ldr r0, [r0, #8]
.L080C4C94:
	pop {r1}
	bx r1

	thumb_func_start sub_080C4C98
sub_080C4C98: @ 0x080C4C98
.L080C4C98:
	push {r4, lr}
	movs r4, #4
.L080C4C9C:
	adds r0, r4, #0
	bl sub_080F3EC8
	cmp r0, #0
	bne .L080C4CD6
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080C4CD6
	ldr r1, .L080C4CE4
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, r4, #0
	bl sub_080C0F8C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge .L080C4CCC
	adds r0, #3
.L080C4CCC:
	asrs r1, r0, #2
	adds r1, #1
	adds r0, r4, #0
	bl sub_080C0B30
.L080C4CD6:
	adds r4, #1
	cmp r4, #0xf
	ble .L080C4C9C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C4CE4: .4byte 0xFFFF8000

	thumb_func_start sub_080C4CE8
sub_080C4CE8: @ 0x080C4CE8
.L080C4CE8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r7, #0
	ldr r0, .L080C4D70
	mov r8, r0
	movs r5, #0
.L080C4CFA:
	adds r0, r5, #0
	bl sub_080C0148
	adds r4, r0, #0
	cmp r4, #0
	beq .L080C4D22
	ldrb r0, [r4, #0xc]
	cmp r0, r6
	beq .L080C4D22
	bl sub_080C0830
	cmp r0, #0
	bne .L080C4D22
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	cmp r0, r7
	ble .L080C4D22
	ldrh r7, [r4, #0x18]
	ldrb r4, [r4, #0xc]
	mov r8, r4
.L080C4D22:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #5
	bls .L080C4CFA
	ldr r0, .L080C4D70
	cmp r8, r0
	beq .L080C4D64
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r6, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	ldrh r0, [r4, #0x18]
	adds r0, #1
	strh r0, [r4, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r4, #0x1a]
	movs r3, #0x1a
	ldrsh r1, [r4, r3]
	cmp r0, r1
	ble .L080C4D58
	strh r2, [r4, #0x18]
.L080C4D58:
	mov r0, r8
	movs r1, #1
	bl sub_080C0C70
	bl sub_080C84A0
.L080C4D64:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080C4D70: .4byte 0x0000FFFF

	thumb_func_start sub_080C4D74
sub_080C4D74: @ 0x080C4D74
.L080C4D74:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x40
	ands r0, r6
	cmp r0, #0
	beq .L080C4DC8
	adds r0, r4, #0
	adds r0, #0x41
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge .L080C4DAA
	adds r0, #3
.L080C4DAA:
	asrs r0, r0, #2
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C4E00
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C4DC8
	ldr r1, .L080C4DF8
	adds r0, r5, #0
	bl sub_080C08BC
	bl sub_080C84A0
.L080C4DC8:
	movs r0, #0x20
	ands r0, r6
	cmp r0, #0
	beq .L080C4DF2
	bl sub_080C4E24
	movs r1, #0xc
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	bl sub_080C4E00
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C4DF2
	ldr r1, .L080C4DFC
	adds r0, r5, #0
	bl sub_080C08BC
	bl sub_080C84A0
.L080C4DF2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C4DF8: .4byte 0x0000FFBF
.L080C4DFC: .4byte 0x0000FFDF

	thumb_func_start sub_080C4E00
sub_080C4E00: @ 0x080C4E00
.L080C4E00:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xe
	bhi .L080C4E16
	bl sub_080C2244
	movs r1, #0xf
	ands r1, r0
	cmp r4, r1
	blo .L080C4E1A
.L080C4E16:
	movs r0, #1
	b .L080C4E1C
.L080C4E1A:
	movs r0, #0
.L080C4E1C:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C4E24
sub_080C4E24: @ 0x080C4E24
.L080C4E24:
	push {lr}
	bl sub_080C1D9C
	lsls r0, r0, #0x10
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r1, r0
	lsrs r1, r1, #0x14
	cmp r1, #8
	bls .L080C4E40
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
.L080C4E40:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C4E48
sub_080C4E48: @ 0x080C4E48
.L080C4E48:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	adds r7, r1, #0
	movs r0, #0xff
	mov r1, sl
	ands r1, r0
	mov sl, r1
	movs r0, #0
	mov r8, r0
	mov sb, r0
	movs r1, #3
	mov r0, sl
	ands r0, r1
	str r0, [sp]
.L080C4E6E:
	mov r1, sb
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	cmp r0, #0
	beq .L080C4F50
	ldrb r5, [r0, #0xc]
	adds r0, r5, #0
	bl sub_080C09B0
	adds r6, r0, #0
	cmp r6, #1
	bne .L080C4F50
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080C4F50
	adds r0, r5, #0
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne .L080C4F50
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080C4EE8
	adds r0, r5, #0
	bl sub_080C4CE8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L080C4EE4
	cmp r4, r0
	beq .L080C4F40
	adds r0, r4, #0
	bl sub_080F401C
	cmp r0, #0
	bne .L080C4EDC
	lsls r6, r4
	ldr r0, [r7]
	orrs r0, r6
	str r0, [r7]
.L080C4EDC:
	movs r1, #1
	mov r8, r1
	b .L080C4F40
	.byte 0x00, 0x00
.L080C4EE4: .4byte 0x0000FFFF
.L080C4EE8:
	movs r0, #0x80
	lsls r0, r0, #5
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080C4EFE
	mov r1, sl
	ands r6, r1
	cmp r6, #0
	bne .L080C4F1A
.L080C4EFE:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq .L080C4F0C
	ldr r1, [sp]
	cmp r1, #3
	beq .L080C4F1A
.L080C4F0C:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq .L080C4F40
	ldr r1, [sp]
	cmp r1, #3
	bne .L080C4F40
.L080C4F1A:
	adds r0, r5, #0
	bl sub_080F401C
	adds r1, r0, #0
	cmp r1, #1
	bne .L080C4F2E
	lsls r1, r5
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
.L080C4F2E:
	adds r0, r5, #0
	movs r1, #1
	bl sub_080C0C70
	mov r0, sb
	bl sub_080C8490
	movs r0, #1
	mov r8, r0
.L080C4F40:
	adds r0, r5, #0
	bl sub_080F401C
	cmp r0, #0
	beq .L080C4F50
	adds r0, r5, #0
	bl sub_080C4D74
.L080C4F50:
	movs r1, #1
	add sb, r1
	mov r0, sb
	cmp r0, #5
	ble .L080C4E6E
	mov r1, r8
	cmp r1, #1
	bne .L080C4F6E
	ldr r0, .L080C4F80
	movs r1, #1
	bl sub_080B8AE0
	ldr r0, .L080C4F84
	bl sub_080C51D4
.L080C4F6E:
	mov r0, r8
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080C4F80: .4byte 0x00007C1F
.L080C4F84: .4byte 0x0000012B

	thumb_func_start sub_080C4F88
sub_080C4F88: @ 0x080C4F88
.L080C4F88:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	movs r0, #0
	mov sl, r0
	movs r0, #0xff
	mov r1, sb
	ands r1, r0
	mov sb, r1
	movs r7, #0
	movs r0, #0
	mov r8, r0
.L080C4FA6:
	mov r1, r8
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	cmp r0, #0
	beq .L080C509A
	ldrb r5, [r0, #0xc]
	adds r0, r5, #0
	bl sub_080C09B0
	adds r6, r0, #0
	cmp r6, #1
	bne .L080C509A
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080C509A
	adds r0, r5, #0
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne .L080C509A
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080C501C
	adds r0, r5, #0
	bl sub_080C4CE8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L080C5018
	cmp r4, r0
	beq .L080C5060
	adds r0, r4, #0
	bl sub_080F401C
	cmp r0, #0
	bne .L080C503C
	adds r0, r6, #0
	lsls r0, r4
	mov r1, sl
	orrs r1, r0
	mov sl, r1
	b .L080C503C
.L080C5018: .4byte 0x0000FFFF
.L080C501C:
	movs r0, #0x80
	lsls r0, r0, #5
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080C5040
	mov r0, sb
	ands r0, r6
	cmp r0, #0
	beq .L080C5040
	adds r0, r5, #0
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_080C0AD4
.L080C503C:
	orrs r7, r6
	b .L080C5060
.L080C5040:
	movs r0, #5
	ands r0, r2
	cmp r0, #0
	beq .L080C5060
	movs r0, #3
	mov r1, sb
	ands r0, r1
	cmp r0, #3
	bne .L080C5060
	adds r0, r5, #0
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_080C0AD4
	movs r0, #1
	orrs r7, r0
.L080C5060:
	adds r0, r5, #0
	bl sub_080F401C
	cmp r0, #0
	bgt .L080C5094
	adds r0, r5, #0
	bl sub_080C0818
	adds r0, r5, #0
	movs r1, #0x80
	lsls r1, r1, #8
	bl sub_080C08F8
	cmp r5, #3
	ble .L080C508E
	adds r0, r5, #0
	bl sub_080F4190
	bl sub_080C366C
	movs r0, #2
	orrs r7, r0
	b .L080C509A
.L080C508E:
	movs r0, #4
	orrs r7, r0
	b .L080C509A
.L080C5094:
	adds r0, r5, #0
	bl sub_080C4D74
.L080C509A:
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #5
	bgt .L080C50A6
	b .L080C4FA6
.L080C50A6:
	movs r0, #0
	mov r8, r0
.L080C50AA:
	ldr r0, .L080C50E4
	add r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	movs r0, #1
	mov r1, r8
	lsls r0, r1
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq .L080C50EC
	ldrb r0, [r4, #0xc]
	movs r1, #0x80
	lsls r1, r1, #8
	bl sub_080C08F8
	ldrb r0, [r4, #0xc]
	cmp r0, #3
	bls .L080C50E8
	bl sub_080F4190
	bl sub_080C366C
	movs r0, #2
	b .L080C50EA
	.byte 0x00, 0x00
.L080C50E4: .4byte 0xFFFF8000
.L080C50E8:
	movs r0, #4
.L080C50EA:
	orrs r7, r0
.L080C50EC:
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #0xf
	ble .L080C50AA
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080C5108
sub_080C5108: @ 0x080C5108
.L080C5108:
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0
.L080C510E:
	ldr r1, .L080C514C
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r2, r0, #0
	cmp r2, #0
	beq .L080C513E
	ldrh r0, [r2, #0xe]
	cmp r0, #0
	beq .L080C513E
	ldrh r1, [r2, #0x10]
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne .L080C513C
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne .L080C5150
.L080C513C:
	movs r5, #1
.L080C513E:
	adds r4, #1
	cmp r4, #3
	ble .L080C510E
	cmp r5, #0
	beq .L080C5150
	movs r0, #0
	b .L080C5152
.L080C514C: .4byte 0xFFFF8000
.L080C5150:
	movs r0, #1
.L080C5152:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080C5158
sub_080C5158: @ 0x080C5158
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C5108
	cmp r0, #1
	beq .L080C5166
	movs r0, #0
.L080C5166:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C5170
sub_080C5170: @ 0x080C5170
.L080C5170:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r3, .L080C5190
	ldrh r2, [r3]
	cmp r1, r2
	beq .L080C518A
	ldr r0, .L080C5194
	strh r2, [r0]
	strh r1, [r3]
	adds r0, r1, #0
	bl m4aSongNumStart
.L080C518A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C5190: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080C5194: .4byte 0x030031EC @ IWRAM+0x31EC

	thumb_func_start sub_080C5198
sub_080C5198: @ 0x080C5198
	push {r4, lr}
	ldr r4, .L080C51B4
	ldrh r0, [r4]
	bl m4aSongNumStop
	ldr r1, .L080C51B8
	ldrh r0, [r4]
	strh r0, [r1]
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C51B4: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080C51B8: .4byte 0x030031EC @ IWRAM+0x31EC

	thumb_func_start sub_080C51BC
sub_080C51BC: @ 0x080C51BC
.L080C51BC:
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, .L080C51D0
	bl m4aMPlayFadeOut
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C51D0: .4byte 0x0203F2E0 @ EWRAM+0x3F2E0

	thumb_func_start sub_080C51D4
sub_080C51D4: @ 0x080C51D4
.L080C51D4:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C51E4
sub_080C51E4: @ 0x080C51E4
	ldr r1, .L080C51EC
	movs r0, #1
	strh r0, [r1, #0x34]
	bx lr
.L080C51EC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C51F0
sub_080C51F0: @ 0x080C51F0
	push {lr}
	ldr r1, .L080C5218
	ldr r0, .L080C521C
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	ldr r2, .L080C5220
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r2, #2
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl sub_080C2D78
	pop {r0}
	bx r0
.L080C5218: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C521C: .4byte 0x00000A38
.L080C5220: .4byte 0x000018AC

	thumb_func_start sub_080C5224
sub_080C5224: @ 0x080C5224
.L080C5224:
	push {lr}
	ldr r0, .L080C5238
	ldr r1, .L080C523C
	bl Task_Create
	movs r0, #0x1a
	bl Field_SetState
	pop {r0}
	bx r0
.L080C5238: .4byte gUnknown_081A65F4
.L080C523C: .4byte 0x0000FFFF

	thumb_func_start sub_080C5240
sub_080C5240: @ 0x080C5240
.L080C5240:
	push {lr}
	movs r0, #1
	bl Flag_Test
	cmp r0, #0
	bne .L080C5284
	movs r0, #0xae
	bl Flag_Test
	cmp r0, #0
	bne .L080C5284
	ldr r0, .L080C527C
	ldr r0, [r0]
	cmp r0, #0x42
	beq .L080C5284
	cmp r0, #0x4a
	beq .L080C5284
	cmp r0, #0x4b
	beq .L080C5284
	cmp r0, #0xf
	beq .L080C5284
	ldr r0, .L080C5280
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080C5284
	movs r0, #1
	b .L080C5286
.L080C527C: .4byte 0x03004614 @ IWRAM+0x4614
.L080C5280: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C5284:
	movs r0, #0
.L080C5286:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C528C
sub_080C528C: @ 0x080C528C
	ldr r1, .L080C5294
	movs r0, #1
	strh r0, [r1, #0x34]
	bx lr
.L080C5294: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C5298
sub_080C5298: @ 0x080C5298
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r4, .L080C52DC
	ldr r1, .L080C52E0
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, .L080C52E4
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, .L080C52E8
	adds r0, r4, r3
	ldrb r5, [r0]
	cmp r5, #0
	bne .L080C52F8
	ldr r6, .L080C52EC
	adds r0, r4, r6
	ldrh r0, [r0]
	ldr r2, .L080C52F0
	adds r1, r4, r2
	ldrh r1, [r1]
	ldr r3, .L080C52F4
	adds r2, r4, r3
	ldrh r2, [r2]
	subs r6, #2
	adds r3, r4, r6
	ldrh r3, [r3]
	subs r6, #4
	adds r4, r4, r6
	ldrh r4, [r4]
	str r4, [sp]
	str r5, [sp, #4]
	bl sub_080B710C
	b .L080C52FC
.L080C52DC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C52E0: .4byte 0x000018AA
.L080C52E4: .4byte 0x00000A38
.L080C52E8: .4byte 0x00000AC2
.L080C52EC: .4byte 0x000018A6
.L080C52F0: .4byte 0x000018A8
.L080C52F4: .4byte 0x000018A2
.L080C52F8:
	bl sub_080D0BA0
.L080C52FC:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080C5304
sub_080C5304: @ 0x080C5304
.L080C5304:
	push {lr}
	ldr r0, .L080C5318
	ldr r1, .L080C531C
	bl Task_Create
	movs r0, #0x1a
	bl Field_SetState
	pop {r0}
	bx r0
.L080C5318: .4byte gUnknown_081A6634
.L080C531C: .4byte 0x0000FFFF

	thumb_func_start sub_080C5320
sub_080C5320: @ 0x080C5320
.L080C5320:
	push {r4, lr}
	movs r0, #0xcb
	bl Flag_Test
	cmp r0, #0
	beq .L080C53E8
	ldr r0, .L080C53D4
	bl Flag_Test
	cmp r0, #0
	beq .L080C53E8
	ldr r0, .L080C53D8
	ldr r1, .L080C53DC
	adds r4, r0, r1
	ldrh r1, [r4]
	ldr r0, .L080C53E0
	cmp r1, r0
	beq .L080C53E8
	movs r0, #1
	bl Flag_Test
	cmp r0, #0
	bne .L080C53E8
	movs r0, #0x52
	bl sub_080C3560
	cmp r0, #0
	bne .L080C53E8
	movs r0, #0x53
	bl sub_080C3560
	cmp r0, #0
	bne .L080C53E8
	movs r0, #0xae
	bl Flag_Test
	cmp r0, #0
	bne .L080C53E8
	ldr r0, .L080C53E4
	ldr r0, [r0]
	cmp r0, #0x42
	beq .L080C53E8
	cmp r0, #0x4a
	beq .L080C53E8
	cmp r0, #0x4b
	beq .L080C53E8
	cmp r0, #0xf
	beq .L080C53E8
	movs r0, #0xd0
	bl Flag_Test
	cmp r0, #0
	beq .L080C5394
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080C53E8
	cmp r0, #0x10
	beq .L080C53E8
.L080C5394:
	movs r0, #0xd1
	bl Flag_Test
	cmp r0, #0
	beq .L080C53AA
	ldr r0, .L080C53D8
	ldr r1, .L080C53DC
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x14
	beq .L080C53E8
.L080C53AA:
	movs r0, #0x50
	bl Flag_Test
	cmp r0, #0
	beq .L080C53C0
	ldr r0, .L080C53D8
	ldr r1, .L080C53DC
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x22
	beq .L080C53E8
.L080C53C0:
	ldr r0, .L080C53D8
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080C53E8
	movs r0, #1
	b .L080C53EA
	.byte 0x00, 0x00
.L080C53D4: .4byte 0x00000163
.L080C53D8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C53DC: .4byte 0x000018A6
.L080C53E0: .4byte 0x0000FFFF
.L080C53E4: .4byte 0x03004614 @ IWRAM+0x4614
.L080C53E8:
	movs r0, #0
.L080C53EA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C53F0
sub_080C53F0: @ 0x080C53F0
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080C53F4
sub_080C53F4: @ 0x080C53F4
.L080C53F4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r2, #0
	adds r4, r3, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov sl, r6
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	mov sb, r7
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080C5468
	ldrh r0, [r0]
	ldr r1, .L080C546C
	ldrh r1, [r1]
	bl sub_080C8B10
	adds r3, r0, #0
	lsls r2, r4, #3
	adds r2, r2, r4
	lsls r2, r2, #2
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	ldr r1, .L080C5470
	adds r0, r0, r1
	adds r2, r2, r0
	mov r8, r2
	ldrh r0, [r3, #8]
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldrh r0, [r3, #0xa]
	adds r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r6, #0x10
	cmp r0, #0
	blt .L080C5462
	ldr r4, .L080C5474
	ldrh r0, [r4, #0x1a]
	cmp r6, r0
	bhs .L080C5462
	lsls r0, r7, #0x10
	cmp r0, #0
	blt .L080C5462
	ldrh r0, [r4, #0x1c]
	cmp r7, r0
	blo .L080C5478
.L080C5462:
	movs r0, #0
	b .L080C54BC
	.byte 0x00, 0x00
.L080C5468: .4byte 0x03004614 @ IWRAM+0x4614
.L080C546C: .4byte 0x03004514 @ IWRAM+0x4514
.L080C5470: .4byte 0x0200AF08 @ EWRAM+0xAF08
.L080C5474: .4byte 0x03004550 @ IWRAM+0x4550
.L080C5478:
	adds r0, r3, #0
	bl sub_080B7944
	cmp r0, #0
	beq .L080C54BC
	ldrh r2, [r4, #2]
	ldrh r0, [r4, #0x1a]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, sl
	ldr r1, [r4, #0x20]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r6, [r0]
	movs r4, #0
	ldr r7, .L080C54D0
	movs r5, #3
	mov r3, r8
	adds r3, #4
.L080C54A0:
	lsls r1, r2, #1
	adds r1, r1, r7
	adds r0, r6, #0
	ldrh r1, [r1]
	asrs r0, r1
	ands r0, r5
	strh r0, [r3]
	adds r2, #1
	ands r2, r5
	adds r3, #2
	adds r4, #1
	cmp r4, #3
	bls .L080C54A0
	movs r0, #1
.L080C54BC:
	mov r1, r8
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C54D0: .4byte gUnknown_0815F2E6

	thumb_func_start sub_080C54D4
sub_080C54D4: @ 0x080C54D4
.L080C54D4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	ldr r0, .L080C5510
	ldrh r7, [r0, #0x12]
	ldrh r6, [r0, #0x14]
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080C5514
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080C5518
	str r0, [r1, #4]
	ldr r0, .L080C551C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r1, r8
	cmp r1, #1
	beq .L080C552A
	cmp r1, #1
	blo .L080C5520
	cmp r1, #2
	beq .L080C5534
	cmp r1, #3
	beq .L080C553E
	b .L080C554A
.L080C5510: .4byte 0x03004550 @ IWRAM+0x4550
.L080C5514: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C5518: .4byte 0x0200AF08 @ EWRAM+0xAF08
.L080C551C: .4byte 0x8500002D
.L080C5520:
	subs r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	subs r0, r6, #2
	b .L080C5546
.L080C552A:
	adds r0, r7, #2
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	subs r0, r6, #1
	b .L080C5546
.L080C5534:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r6, #2
	b .L080C5546
.L080C553E:
	subs r0, r7, #2
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r6, #1
.L080C5546:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080C554A:
	movs r5, #0
	cmp r5, #5
	bhs .L080C55D0
.L080C5550:
	movs r4, #0
	adds r2, r5, #1
	str r2, [sp, #4]
	cmp r4, #3
	bhs .L080C55C6
	adds r0, r6, r5
	lsls r0, r0, #0x10
	mov sl, r0
	subs r0, r7, r5
	lsls r0, r0, #0x10
	mov sb, r0
.L080C5566:
	mov r0, r8
	cmp r0, #1
	beq .L080C5586
	cmp r0, #1
	blo .L080C557A
	cmp r0, #2
	beq .L080C5592
	cmp r0, #3
	beq .L080C55A8
	b .L080C55BC
.L080C557A:
	adds r0, r7, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, sl
	lsrs r1, r2, #0x10
	b .L080C559E
.L080C5586:
	adds r1, r6, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r2, sb
	lsrs r0, r2, #0x10
	b .L080C559E
.L080C5592:
	subs r0, r7, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r6, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
.L080C559E:
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080C53F4
	b .L080C55BC
.L080C55A8:
	adds r0, r7, r5
	lsls r0, r0, #0x10
	subs r1, r6, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsrs r0, r0, #0x10
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080C53F4
.L080C55BC:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #3
	blo .L080C5566
.L080C55C6:
	ldr r1, [sp, #4]
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #5
	blo .L080C5550
.L080C55D0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080C55E0
sub_080C55E0: @ 0x080C55E0
	ldr r1, .L080C55F4
	ldr r0, .L080C55F8
	str r0, [r1]
	ldr r0, .L080C55FC
	str r0, [r1, #4]
	ldr r0, .L080C5600
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C55F4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C55F8: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C55FC: .4byte 0x06001000 @ VRAM+0x1000
.L080C5600: .4byte 0x84000400

	thumb_func_start sub_080C5604
sub_080C5604: @ 0x080C5604
.L080C5604:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, .L080C5674
	ldrh r0, [r0, #2]
	bl sub_080C54D4
	movs r2, #0
.L080C561A:
	movs r3, #0
	lsls r0, r2, #3
	adds r1, r2, #6
	adds r4, r2, #1
	mov sl, r4
	adds r0, r0, r2
	lsls r0, r0, #2
	mov sb, r0
	lsls r1, r1, #6
	ldr r0, .L080C5678
	adds r0, r0, r1
	mov r8, r0
.L080C5632:
	lsls r2, r3, #1
	adds r0, r2, r3
	lsls r0, r0, #2
	ldr r1, .L080C567C
	adds r0, r0, r1
	mov r1, sb
	adds r4, r1, r0
	adds r2, #0x32
	mov r0, r8
	adds r6, r0, r2
	ldrh r0, [r4]
	cmp r0, #1
	bne .L080C5680
	movs r2, #0
	adds r5, r3, #1
	adds r3, r4, #4
	movs r7, #2
.L080C5654:
	lsls r0, r2, #1
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #3
	bne .L080C5660
	strh r7, [r1]
.L080C5660:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #3
	bls .L080C5654
	adds r0, r4, #0
	bl sub_080B4448
	strh r0, [r6]
	b .L080C568A
.L080C5674: .4byte 0x03004550 @ IWRAM+0x4550
.L080C5678: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C567C: .4byte 0x0200AF08 @ EWRAM+0xAF08
.L080C5680:
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r1, #0
	strh r0, [r6]
	adds r5, r3, #1
.L080C568A:
	lsls r0, r5, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #2
	bls .L080C5632
	mov r4, sl
	lsls r0, r4, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #4
	bls .L080C561A
	ldr r0, .L080C56EC
	movs r1, #0
	str r1, [sp]
	movs r1, #0xd0
	str r1, [sp, #4]
	movs r1, #0x40
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r1, .L080C56F0
	movs r0, #0xe0
	strb r0, [r1]
	ldr r1, .L080C56F4
	movs r0, #0xc8
	strb r0, [r1]
	ldr r1, .L080C56F8
	movs r0, #0x58
	strb r0, [r1]
	ldr r1, .L080C56FC
	movs r0, #0x30
	strb r0, [r1]
	ldr r1, .L080C5700
	movs r0, #0x1f
	strb r0, [r1]
	ldr r0, .L080C5704
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C56EC: .4byte gUnknown_080008C0
.L080C56F0: .4byte 0x03000030 @ IWRAM+0x30
.L080C56F4: .4byte 0x03000031 @ IWRAM+0x31
.L080C56F8: .4byte 0x03000034 @ IWRAM+0x34
.L080C56FC: .4byte 0x03000035 @ IWRAM+0x35
.L080C5700: .4byte 0x03000038 @ IWRAM+0x38
.L080C5704: .4byte sub_080C55E0

	thumb_func_start sub_080C5708
sub_080C5708: @ 0x080C5708
	push {r4, r5, r6, r7, lr}
	ldr r5, .L080C575C
	ldr r0, .L080C5760
	ldrh r0, [r0, #2]
	movs r1, #1
	bl sub_080AE574
	movs r2, #0
	ldr r6, .L080C5764
	ldr r7, .L080C5768
	movs r4, #0
.L080C571E:
	movs r1, #0
	adds r0, r2, #6
	adds r3, r2, #1
	lsls r0, r0, #6
	adds r2, r5, r0
.L080C5728:
	lsls r0, r1, #1
	adds r0, #0x32
	adds r0, r2, r0
	strh r4, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #2
	bls .L080C5728
	lsls r0, r3, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #4
	bls .L080C571E
	movs r0, #0x3f
	strb r0, [r6]
	adds r0, r7, #0
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080C5760
	movs r0, #0
	str r0, [r1, #0x58]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C575C: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C5760: .4byte 0x03004550 @ IWRAM+0x4550
.L080C5764: .4byte 0x03000038 @ IWRAM+0x38
.L080C5768: .4byte sub_080C55E0

	thumb_func_start sub_080C576C
sub_080C576C: @ 0x080C576C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	strh r0, [r4, #0x1c]
	bl sub_080F3F44
	movs r1, #0x80
	lsls r1, r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L080C57AA
	ldr r0, .L080C57B0
	ldrh r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080C57A2
	adds r0, r1, #0
	cmp r0, #5
	beq .L080C57A2
	cmp r0, #6
	beq .L080C57A2
	cmp r0, #7
	beq .L080C57A2
	cmp r0, #8
	bne .L080C57AA
.L080C57A2:
	bl sub_080C5604
	movs r0, #0
	strh r0, [r4, #0x1c]
.L080C57AA:
	pop {r4}
	pop {r0}
	bx r0
.L080C57B0: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080C57B4
sub_080C57B4: @ 0x080C57B4
.L080C57B4:
	push {lr}
	ldr r0, .L080C57C4
	ldr r1, .L080C57C8
	bl Task_Create
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C57C4: .4byte gUnknown_081A6674
.L080C57C8: .4byte 0x0000FFFF

	thumb_func_start sub_080C57CC
sub_080C57CC: @ 0x080C57CC
.L080C57CC:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080C57E0
	b .L080C5988
.L080C57E0:
	ldr r1, .L080C57F4
	adds r0, r4, r1
	cmp r0, #0x2d
	bls .L080C57EA
	b .L080C5B08
.L080C57EA:
	lsls r0, r0, #2
	ldr r1, .L080C57F8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080C57F4: .4byte 0xFFFFFED4
.L080C57F8: .4byte gUnknown_080C57FC
	.global gUnknown_080C57FC
gUnknown_080C57FC:
.L080C57FC: @ jump table
	.4byte .L080C58B4
	.4byte .L080C58BC
	.4byte .L080C58C0
	.4byte .L080C58EC
	.4byte .L080C5AFA
	.4byte .L080C590A
	.4byte .L080C590E
	.4byte .L080C5AFA
	.4byte .L080C593A
	.4byte .L080C5B08
	.4byte .L080C5B08
	.4byte .L080C5958
	.4byte .L080C598C
	.4byte .L080C59C2
	.4byte .L080C59D6
	.4byte .L080C5A0C
	.4byte .L080C5B08
	.4byte .L080C5A42
	.4byte .L080C5AE2
	.4byte .L080C5A4A
	.4byte .L080C5A52
	.4byte .L080C5B08
	.4byte .L080C5B08
	.4byte .L080C5A5A
	.4byte .L080C5A62
	.4byte .L080C5A6A
	.4byte .L080C5B08
	.4byte .L080C5B08
	.4byte .L080C5B08
	.4byte .L080C5A72
	.4byte .L080C5B08
	.4byte .L080C5AE2
	.4byte .L080C5A7A
	.4byte .L080C5AA8
	.4byte .L080C5AE2
	.4byte .L080C5B08
	.4byte .L080C5B08
	.4byte .L080C5AE2
	.4byte .L080C5B08
	.4byte .L080C5AD6
	.4byte .L080C5ADE
	.4byte .L080C5B08
	.4byte .L080C5B08
	.4byte .L080C5B08
	.4byte .L080C5AE2
	.4byte .L080C5B08
.L080C58B4:
	movs r0, #0x5d
	bl Flag_Test
	b .L080C5B02
.L080C58BC:
	movs r0, #0
	b .L080C5AFC
.L080C58C0:
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C58E4
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C58E4
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C5988
.L080C58E4:
	movs r0, #0x23
	bl Flag_Test
	b .L080C5B02
.L080C58EC:
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C5988
	movs r0, #0
	bl sub_080C06BC
	cmp r0, #2
	bne .L080C5988
	movs r0, #0x4e
	bl Flag_Test
	b .L080C5B02
.L080C590A:
	movs r0, #0
	b .L080C5AFC
.L080C590E:
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5932
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5932
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C5988
.L080C5932:
	movs r0, #0x1e
	bl Flag_Test
	b .L080C5B02
.L080C593A:
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C5988
	movs r0, #0
	bl sub_080C06BC
	cmp r0, #0
	bne .L080C5988
	movs r0, #0x71
	bl Flag_Test
	b .L080C5B02
.L080C5958:
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C597C
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C597C
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C5988
.L080C597C:
	movs r0, #0
	bl sub_080C06BC
	cmp r0, #0
	bne .L080C5988
	b .L080C5B08
.L080C5988:
	movs r0, #0
	b .L080C5B0A
.L080C598C:
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C59B0
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C59B0
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C5988
.L080C59B0:
	movs r0, #0
	bl sub_080C06BC
	cmp r0, #2
	bne .L080C5988
	movs r0, #0x5d
	bl Flag_Test
	b .L080C5B02
.L080C59C2:
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C5988
	movs r0, #0x23
	bl Flag_Test
	b .L080C5B02
.L080C59D6:
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C59FA
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C59FA
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C5988
.L080C59FA:
	movs r0, #0
	bl sub_080C06BC
	cmp r0, #0
	bne .L080C5988
	movs r0, #0x5d
	bl Flag_Test
	b .L080C5B02
.L080C5A0C:
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5A30
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5A30
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C5988
.L080C5A30:
	movs r0, #0
	bl sub_080C06BC
	cmp r0, #1
	bne .L080C5988
	movs r0, #0x5d
	bl Flag_Test
	b .L080C5B02
.L080C5A42:
	movs r0, #0xe7
	bl Flag_Test
	b .L080C5B02
.L080C5A4A:
	movs r0, #0x1d
	bl Flag_Test
	b .L080C5B02
.L080C5A52:
	movs r0, #0xc
	bl Flag_Test
	b .L080C5B02
.L080C5A5A:
	movs r0, #0x2d
	bl Flag_Test
	b .L080C5B02
.L080C5A62:
	movs r0, #0x48
	bl Flag_Test
	b .L080C5B02
.L080C5A6A:
	movs r0, #0x49
	bl Flag_Test
	b .L080C5B02
.L080C5A72:
	movs r0, #0x2e
	bl Flag_Test
	b .L080C5B02
.L080C5A7A:
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5AA0
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5AA0
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5AA0
	b .L080C5988
.L080C5AA0:
	movs r0, #0x55
	bl Flag_Test
	b .L080C5B02
.L080C5AA8:
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5ACE
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5ACE
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5ACE
	b .L080C5988
.L080C5ACE:
	movs r0, #0xc9
	bl Flag_Test
	b .L080C5B02
.L080C5AD6:
	movs r0, #0x36
	bl Flag_Test
	b .L080C5B02
.L080C5ADE:
	movs r0, #0
	b .L080C5AFC
.L080C5AE2:
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5B08
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C5B08
.L080C5AFA:
	movs r0, #2
.L080C5AFC:
	bl sub_080C2A84
	lsls r0, r0, #0x10
.L080C5B02:
	cmp r0, #0
	bne .L080C5B08
	b .L080C5988
.L080C5B08:
	movs r0, #1
.L080C5B0A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C5B10
sub_080C5B10: @ 0x080C5B10
.L080C5B10:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl Action_GetRecord
	ldr r0, [r0, #4]
	cmp r0, #0
	beq .L080C5B34
	ldr r1, .L080C5B30
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Flag_Test
	b .L080C5B36
.L080C5B30: .4byte 0x0000FFF4
.L080C5B34:
	movs r0, #1
.L080C5B36:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C5B3C
sub_080C5B3C: @ 0x080C5B3C
.L080C5B3C:
	push {r4, r5, lr}
	movs r4, #0
	ldr r5, .L080C5BAC
.L080C5B42:
	adds r0, r4, r5
	ldrb r1, [r0]
	ldr r0, .L080C5BB0
	adds r0, r4, r0
	strb r1, [r0]
	cmp r1, #0
	beq .L080C5B5C
	cmp r1, #0xff
	beq .L080C5B5C
	adds r0, r1, #0
	movs r1, #0
	bl sub_080C0290
.L080C5B5C:
	adds r4, #1
	cmp r4, #5
	bls .L080C5B42
	ldr r1, .L080C5BB4
	movs r0, #0xa2
	lsls r0, r0, #4
	adds r2, r1, r0
	movs r0, #0
	strb r0, [r2]
	ldr r0, .L080C5BB8
	adds r2, r1, r0
	movs r0, #0xff
	strb r0, [r2]
	ldr r0, .L080C5BBC
	adds r2, r1, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2]
	ldr r0, .L080C5BC0
	adds r2, r1, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2]
	ldr r0, .L080C5BC4
	adds r2, r1, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2]
	ldr r0, .L080C5BC8
	adds r1, r1, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C5BAC: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080C5BB0: .4byte 0x020360D4 @ EWRAM+0x360D4
.L080C5BB4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C5BB8: .4byte 0x00000A21
.L080C5BBC: .4byte 0x00000A22
.L080C5BC0: .4byte 0x00000A23
.L080C5BC4: .4byte 0x00000A24
.L080C5BC8: .4byte 0x00000A25

	thumb_func_start sub_080C5BCC
sub_080C5BCC: @ 0x080C5BCC
.L080C5BCC:
	push {r4, r5, lr}
	movs r4, #0
	ldr r5, .L080C5C0C
.L080C5BD2:
	ldr r0, .L080C5C10
	adds r0, r4, r0
	ldrb r1, [r0]
	adds r0, r4, r5
	strb r1, [r0]
	cmp r1, #0xff
	beq .L080C5BF6
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	movs r1, #0xc0
	lsls r1, r1, #8
	strh r1, [r0, #0xe]
.L080C5BF6:
	adds r4, #1
	cmp r4, #5
	bls .L080C5BD2
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C5C0C: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080C5C10: .4byte 0x020360D4 @ EWRAM+0x360D4

	thumb_func_start sub_080C5C14
sub_080C5C14: @ 0x080C5C14
.L080C5C14:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080C5C48
	ldr r1, .L080C5C40
	ldr r2, .L080C5C44
	adds r0, r4, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl Flag_Test
	cmp r0, #0
	bne .L080C5C48
	movs r0, #0
	b .L080C5C4A
	.byte 0x00, 0x00
.L080C5C40: .4byte gUnknown_081A66A0
.L080C5C44: .4byte 0xFFFFFEF0
.L080C5C48:
	movs r0, #1
.L080C5C4A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C5C50
sub_080C5C50: @ 0x080C5C50
.L080C5C50:
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0
.L080C5C56:
	adds r0, r4, #4
	bl sub_080C09B0
	cmp r0, #0
	beq .L080C5C62
	adds r5, #1
.L080C5C62:
	adds r4, #1
	cmp r4, #0xb
	bls .L080C5C56
	bl sub_080C104C
	cmp r5, r0
	bhs .L080C5C74
	movs r0, #1
	b .L080C5C76
.L080C5C74:
	movs r0, #0
.L080C5C76:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080C5C7C
sub_080C5C7C: @ 0x080C5C7C
.L080C5C7C:
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0
.L080C5C82:
	adds r0, r4, #4
	bl sub_080C09B0
	cmp r0, #0
	beq .L080C5CAA
	ldr r1, .L080C5CB8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	ldr r2, .L080C5CBC
	adds r1, r2, #0
	ldrh r0, [r0, #0x12]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x11
	bhi .L080C5CAA
	adds r5, #1
.L080C5CAA:
	adds r4, #1
	cmp r4, #0xb
	bls .L080C5C82
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
.L080C5CB8: .4byte 0x00008004
.L080C5CBC: .4byte 0xFFFFFE96

	thumb_func_start sub_080C5CC0
sub_080C5CC0: @ 0x080C5CC0
.L080C5CC0:
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r4, #0
	ldr r6, .L080C5D04
.L080C5CC8:
	adds r0, r4, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L080C5CF6
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	ldr r2, .L080C5D08
	adds r1, r2, #0
	ldrh r0, [r0, #0x12]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x11
	bhi .L080C5CF6
	adds r5, #1
.L080C5CF6:
	adds r4, #1
	cmp r4, #5
	bls .L080C5CC8
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080C5D04: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080C5D08: .4byte 0xFFFFFE96

	thumb_func_start sub_080C5D0C
sub_080C5D0C: @ 0x080C5D0C
.L080C5D0C:
	push {r4, lr}
	sub sp, #4
	ldr r1, .L080C5D40
	ldrh r0, [r1, #0x12]
	ldrh r1, [r1, #0x14]
	mov r4, sp
	adds r4, #2
	mov r2, sp
	adds r3, r4, #0
	bl sub_080C1F50
	ldr r2, .L080C5D44
	mov r0, sp
	ldrh r1, [r0]
	lsrs r1, r1, #2
	lsls r1, r1, #1
	ldrh r0, [r4]
	lsrs r0, r0, #2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r2
	ldrh r0, [r1]
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
.L080C5D40: .4byte 0x03004550 @ IWRAM+0x4550
.L080C5D44: .4byte gUnknown_081A66B0

	thumb_func_start sub_080C5D48
sub_080C5D48: @ 0x080C5D48
.L080C5D48:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	ldr r1, .L080C5D54
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
.L080C5D54: .4byte gUnknown_081A6AB0

	thumb_func_start sub_080C5D58
sub_080C5D58: @ 0x080C5D58
.L080C5D58:
	push {r4, lr}
	ldr r4, .L080C5D90
	ldrh r0, [r4, #8]
	bl sub_08151EB4
	ldrh r2, [r4, #0xc]
	adds r1, r0, #0
	adds r1, #0xcc
	lsrs r2, r2, #4
	ldrh r1, [r1]
	adds r2, r2, r1
	lsls r2, r2, #0x10
	ldrh r1, [r4, #0xe]
	adds r0, #0xce
	lsrs r1, r1, #4
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, .L080C5D94
	lsrs r2, r2, #0x13
	lsrs r1, r1, #0x13
	lsls r1, r1, #4
	adds r2, r2, r1
	adds r2, r2, r0
	ldrb r0, [r2]
	pop {r4}
	pop {r1}
	bx r1
.L080C5D90: .4byte 0x030069F0 @ IWRAM+0x69F0
.L080C5D94: .4byte gUnknown_081A6CD4

	thumb_func_start sub_080C5D98
sub_080C5D98: @ 0x080C5D98
.L080C5D98:
	push {lr}
	bl sub_080C5D58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	ldr r1, .L080C5DAC
	adds r0, r0, r1
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C5DAC: .4byte gUnknown_081A6C60

	thumb_func_start sub_080C5DB0
sub_080C5DB0: @ 0x080C5DB0
.L080C5DB0:
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r0, .L080C5DD8
	movs r1, #0x80
	lsls r1, r1, #4
	adds r5, r0, r1
	adds r4, r0, #0
.L080C5DBE:
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, .L080C5DDC
	bl CpuSet
	adds r5, #0x80
	adds r4, #0x80
	adds r6, #1
	cmp r6, #3
	bls .L080C5DBE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C5DD8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C5DDC: .4byte 0x04000020 @ REG_BG2PA

	thumb_func_start sub_080C5DE0
sub_080C5DE0: @ 0x080C5DE0
.L080C5DE0:
	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r0, .L080C5E38
	movs r7, #0
	movs r6, #1
	adds r3, r0, #0
	adds r3, #0x10
	adds r4, r0, #0
.L080C5DF0:
	ldr r1, .L080C5E3C
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r3, #8]
	ldr r2, .L080C5E40
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r3, #0xc]
	ldrh r1, [r3]
	subs r2, #0xc
	adds r0, r4, r2
	ldrh r2, [r0]
	strh r2, [r3]
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq .L080C5E18
	adds r0, r2, #0
	orrs r0, r6
	strh r0, [r3]
.L080C5E18:
	adds r3, #0x80
	adds r4, #0x80
	adds r5, #1
	cmp r5, #3
	bls .L080C5DF0
	bl sub_080C6FD8
	movs r0, #0
	bl sub_080C2230
	movs r0, #0xdf
	bl Flag_Clear
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080C5E38: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C5E3C: .4byte 0x00000818
.L080C5E40: .4byte 0x0000081C

	thumb_func_start sub_080C5E44
sub_080C5E44: @ 0x080C5E44
.L080C5E44:
	lsls r0, r0, #0x10
	ldr r1, .L080C5E54
	lsrs r0, r0, #0xf
	subs r0, #0xbc
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C5E54: .4byte gUnknown_081A6F06

	thumb_func_start sub_080C5E58
sub_080C5E58: @ 0x080C5E58
.L080C5E58:
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, .L080C5EBC
	ldr r1, .L080C5EC0
	ldrh r0, [r1, #0x12]
	ldrh r1, [r1, #0x14]
	mov r4, sp
	adds r4, #2
	mov r2, sp
	adds r3, r4, #0
	bl sub_080C1F50
	ldrh r0, [r5, #2]
	lsrs r0, r0, #5
	movs r1, #6
	ands r0, r1
	lsrs r2, r0, #1
	ldrh r0, [r5]
	ldr r1, .L080C5EC4
	cmp r0, r1
	beq .L080C5EE2
	adds r3, r1, #0
.L080C5E84:
	mov r1, sp
	ldrh r0, [r5]
	ldrh r1, [r1]
	cmp r0, r1
	bne .L080C5ED0
	ldrh r1, [r5, #2]
	movs r0, #0x3f
	ands r0, r1
	ldrh r1, [r4]
	cmp r0, r1
	bne .L080C5ED0
	ldr r0, .L080C5EC0
	ldrh r0, [r0, #2]
	cmp r0, r2
	bne .L080C5ED0
	ldr r0, [r5]
	ldr r1, .L080C5EC8
	ands r0, r1
	ldr r1, .L080C5ECC
	cmp r0, r1
	bne .L080C5EB8
	movs r0, #0x15
	bl Flag_Test
	cmp r0, #0
	beq .L080C5EE2
.L080C5EB8:
	ldrh r0, [r5, #4]
	b .L080C5EE4
.L080C5EBC: .4byte gUnknown_081A6F68
.L080C5EC0: .4byte 0x03004550 @ IWRAM+0x4550
.L080C5EC4: .4byte 0x0000FFFF
.L080C5EC8: .4byte 0x003FFFFF
.L080C5ECC: .4byte 0x0006002D
.L080C5ED0:
	adds r5, #8
	ldrh r0, [r5, #2]
	lsrs r0, r0, #5
	movs r1, #6
	ands r0, r1
	lsrs r2, r0, #1
	ldrh r0, [r5]
	cmp r0, r3
	bne .L080C5E84
.L080C5EE2:
	ldr r0, .L080C5EEC
.L080C5EE4:
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
.L080C5EEC: .4byte 0x0000FFFF

	thumb_func_start sub_080C5EF0
sub_080C5EF0: @ 0x080C5EF0
.L080C5EF0:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x5c
	muls r0, r1, r0
	ldr r1, .L080C5F00
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
.L080C5F00: .4byte gUnknown_08341170

	thumb_func_start sub_080C5F04
sub_080C5F04: @ 0x080C5F04
.L080C5F04:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #7
	bls .L080C5F28
	ldr r2, .L080C5F24
	subs r0, #8
	lsls r0, r0, #2
	movs r1, #0x5c
	muls r1, r3, r1
	adds r0, r0, r1
	adds r2, #0x24
	b .L080C5F34
	.byte 0x00, 0x00
.L080C5F24: .4byte gUnknown_08341170
.L080C5F28:
	ldr r2, .L080C5F3C
	lsls r0, r0, #2
	movs r1, #0x5c
	muls r1, r3, r1
	adds r0, r0, r1
	adds r2, #4
.L080C5F34:
	adds r0, r0, r2
	ldr r0, [r0]
	pop {r1}
	bx r1
.L080C5F3C: .4byte gUnknown_08341170

	thumb_func_start sub_080C5F40
sub_080C5F40: @ 0x080C5F40
.L080C5F40:
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080C5EF0
	cmp r4, #0
	beq .L080C5F58
	ldr r0, [r0, #0x54]
	b .L080C5F5A
.L080C5F58:
	ldr r0, [r0, #0x50]
.L080C5F5A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C5F60
sub_080C5F60: @ 0x080C5F60
.L080C5F60:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080C5F74
	movs r2, #0x5c
	muls r0, r2, r0
	adds r1, #0x48
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C5F74: .4byte gUnknown_08341170

	thumb_func_start sub_080C5F78
sub_080C5F78: @ 0x080C5F78
	ldr r1, .L080C5F98
	ldr r0, .L080C5F9C
	str r0, [r1]
	ldr r0, .L080C5FA0
	str r0, [r1, #4]
	ldr r0, .L080C5FA4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080C5FA8
	str r0, [r1]
	ldr r0, .L080C5FAC
	str r0, [r1, #4]
	ldr r0, .L080C5FB0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L080C5F98: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C5F9C: .4byte 0x02001000 @ EWRAM+0x1000
.L080C5FA0: .4byte 0x0600E400 @ VRAM+0xE400
.L080C5FA4: .4byte 0x84000300
.L080C5FA8: .4byte 0x02000000 @ EWRAM
.L080C5FAC: .4byte 0x06001000 @ VRAM+0x1000
.L080C5FB0: .4byte 0x84000400

	thumb_func_start sub_080C5FB4
sub_080C5FB4: @ 0x080C5FB4
	push {lr}
	ldr r0, .L080C5FD0
	ldr r1, .L080C5FD4
	bl LZ77UnCompWram
	bl sub_080C7C60
	ldr r1, .L080C5FD8
	movs r2, #0xf1
	lsls r2, r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	pop {r0}
	bx r0
.L080C5FD0: .4byte gUnknown_0822E194
.L080C5FD4: .4byte 0x02001000 @ EWRAM+0x1000
.L080C5FD8: .4byte 0x03000040 @ IWRAM+0x40

	thumb_func_start sub_080C5FDC
sub_080C5FDC: @ 0x080C5FDC
	push {lr}
	sub sp, #0x14
	movs r3, #0
	str r3, [sp, #0x10]
	ldr r2, .L080C601C
	add r0, sp, #0x10
	str r0, [r2]
	ldr r1, .L080C6020
	str r1, [r2, #4]
	ldr r0, .L080C6024
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, .L080C6028
	movs r2, #0xc8
	lsls r2, r2, #2
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x20
	str r3, [sp, #8]
	movs r3, #0xd
	str r3, [sp, #0xc]
	movs r3, #8
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080C602C
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #0x14
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C601C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C6020: .4byte 0x02000000 @ EWRAM
.L080C6024: .4byte 0x85000400
.L080C6028: .4byte gUnknown_0822E52C
.L080C602C: .4byte sub_080C5F78

	thumb_func_start sub_080C6030
sub_080C6030: @ 0x080C6030
	push {lr}
	sub sp, #4
	ldr r1, .L080C6058
	ldr r2, .L080C605C
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl sub_080B04BC
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	add sp, #4
	pop {r0}
	bx r0
.L080C6058: .4byte gUnknown_0822E174
.L080C605C: .4byte 0x03002AB0 @ IWRAM+0x2AB0

	thumb_func_start sub_080C6060
sub_080C6060: @ 0x080C6060
	ldr r1, .L080C6068
	movs r0, #8
	strh r0, [r1, #0x1e]
	bx lr
.L080C6068: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080C606C
sub_080C606C: @ 0x080C606C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080C6094
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne .L080C60A0
	ldr r0, .L080C6098
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r2, .L080C609C
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r2]
	b .L080C60A4
	.byte 0x00, 0x00
.L080C6094: .4byte 0x03004550 @ IWRAM+0x4550
.L080C6098: .4byte sub_080B0158
.L080C609C: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080C60A0:
	movs r0, #0
	strh r0, [r4, #0x1c]
.L080C60A4:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C60AC
sub_080C60AC: @ 0x080C60AC
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080C60D0
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080C60D4
	str r0, [r1, #4]
	ldr r0, .L080C60D8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xca
	ldr r2, .L080C60DC
	adds r0, r2, #0
	strh r0, [r1]
	add sp, #4
	bx lr
	.byte 0x00, 0x00
.L080C60D0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C60D4: .4byte 0x06001000 @ VRAM+0x1000
.L080C60D8: .4byte 0x85000200
.L080C60DC: .4byte 0x00008209

	thumb_func_start sub_080C60E0
sub_080C60E0: @ 0x080C60E0
	push {lr}
	bl sub_080C1440
	ldr r0, .L080C6104
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080C6108
	strh r1, [r0]
	ldr r0, .L080C610C
	strh r1, [r0]
	ldr r0, .L080C6110
	strh r1, [r0]
	ldr r0, .L080C6114
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
.L080C6104: .4byte 0x0300000E @ IWRAM+0xE
.L080C6108: .4byte 0x0300000C @ IWRAM+0xC
.L080C610C: .4byte 0x03000006 @ IWRAM+0x6
.L080C6110: .4byte 0x03000004 @ IWRAM+0x4
.L080C6114: .4byte sub_080C60AC

	thumb_func_start sub_080C6118
sub_080C6118: @ 0x080C6118
	push {lr}
	bl sub_080C7C94
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C6124
sub_080C6124: @ 0x080C6124
	ldr r1, .L080C6140
	ldr r0, .L080C6144
	str r0, [r1]
	ldr r0, .L080C6148
	str r0, [r1, #4]
	ldr r0, .L080C614C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xca
	ldr r2, .L080C6150
	adds r0, r2, #0
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080C6140: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C6144: .4byte 0x02001000 @ EWRAM+0x1000
.L080C6148: .4byte 0x06004000 @ VRAM+0x4000
.L080C614C: .4byte 0x84000600
.L080C6150: .4byte 0x00008205

	thumb_func_start sub_080C6154
sub_080C6154: @ 0x080C6154
	push {r4, lr}
	ldr r0, .L080C617C
	ldr r4, .L080C6180
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080C6184
	movs r1, #0x80
	lsls r1, r1, #5
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080C6188
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r4}
	pop {r0}
	bx r0
.L080C617C: .4byte gUnknown_0824D1E4
.L080C6180: .4byte 0x02001000 @ EWRAM+0x1000
.L080C6184: .4byte gUnknown_0824DF94
.L080C6188: .4byte sub_080C6124

	thumb_func_start sub_080C618C
sub_080C618C: @ 0x080C618C
	ldr r1, .L080C61A0
	ldr r0, .L080C61A4
	str r0, [r1]
	ldr r0, .L080C61A8
	str r0, [r1, #4]
	ldr r0, .L080C61AC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C61A0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C61A4: .4byte 0x02000000 @ EWRAM
.L080C61A8: .4byte 0x06003000 @ VRAM+0x3000
.L080C61AC: .4byte 0x84000200

	thumb_func_start sub_080C61B0
sub_080C61B0: @ 0x080C61B0
	ldr r1, .L080C61C4
	ldr r0, .L080C61C8
	str r0, [r1]
	ldr r0, .L080C61CC
	str r0, [r1, #4]
	ldr r0, .L080C61D0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C61C4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C61C8: .4byte 0x02000000 @ EWRAM
.L080C61CC: .4byte 0x06001000 @ VRAM+0x1000
.L080C61D0: .4byte 0x84000200

	thumb_func_start sub_080C61D4
sub_080C61D4: @ 0x080C61D4
	push {r4, lr}
	sub sp, #0x14
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r2, .L080C621C
	add r0, sp, #0x10
	str r0, [r2]
	ldr r3, .L080C6220
	str r3, [r2, #4]
	ldr r0, .L080C6224
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	cmp r1, #0
	bne .L080C6238
	ldr r0, .L080C6228
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x20
	str r1, [sp, #8]
	movs r1, #0xd
	str r1, [sp, #0xc]
	adds r1, r3, #0
	movs r2, #0
	movs r3, #8
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080C622C
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080C6230
	strh r4, [r0]
	ldr r0, .L080C6234
	strh r4, [r0]
	b .L080C6262
	.byte 0x00, 0x00
.L080C621C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C6220: .4byte 0x02000000 @ EWRAM
.L080C6224: .4byte 0x85000400
.L080C6228: .4byte gUnknown_0824E75C
.L080C622C: .4byte sub_080C618C
.L080C6230: .4byte 0x0300000E @ IWRAM+0xE
.L080C6234: .4byte 0x03000006 @ IWRAM+0x6
.L080C6238:
	ldr r0, .L080C626C
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x20
	str r1, [sp, #8]
	movs r1, #0xd
	str r1, [sp, #0xc]
	adds r1, r3, #0
	movs r2, #0
	movs r3, #8
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080C6270
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080C6274
	movs r2, #0xf1
	lsls r2, r2, #6
	adds r0, r2, #0
	strh r0, [r1]
.L080C6262:
	add sp, #0x14
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C626C: .4byte gUnknown_0824EA9C
.L080C6270: .4byte sub_080C61B0
.L080C6274: .4byte 0x03000040 @ IWRAM+0x40

	thumb_func_start sub_080C6278
sub_080C6278: @ 0x080C6278
.L080C6278:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r3, #0
	ldr r2, .L080C6294
.L080C6282:
	ldr r1, [r2]
	cmp r1, #0
	beq .L080C6298
	ldrh r0, [r1, #0x2a]
	cmp r0, r4
	bne .L080C6298
	adds r0, r1, #0
	b .L080C62A2
	.byte 0x00, 0x00
.L080C6294: .4byte 0x02036094 @ EWRAM+0x36094
.L080C6298:
	adds r2, #4
	adds r3, #1
	cmp r3, #5
	bls .L080C6282
	movs r0, #0
.L080C62A2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C62A8
sub_080C62A8: @ 0x080C62A8
	push {lr}
	sub sp, #4
	ldr r1, .L080C62E8
	ldr r2, .L080C62EC
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	movs r0, #0xd8
	bl sub_080C6278
	adds r1, r0, #0
	cmp r1, #0
	beq .L080C62CE
	movs r0, #0
	strh r0, [r1, #0x34]
.L080C62CE:
	movs r0, #0xde
	lsls r0, r0, #1
	bl sub_080C6278
	adds r1, r0, #0
	cmp r1, #0
	beq .L080C62E0
	movs r0, #1
	strh r0, [r1, #0x34]
.L080C62E0:
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C62E8: .4byte gUnknown_0824EDDC
.L080C62EC: .4byte 0x03002AB0 @ IWRAM+0x2AB0

	thumb_func_start sub_080C62F0
sub_080C62F0: @ 0x080C62F0
	push {lr}
	ldr r1, .L080C631C
	ldr r0, .L080C6320
	str r0, [r1]
	ldr r0, .L080C6324
	str r0, [r1, #4]
	ldr r0, .L080C6328
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xca
	ldr r2, .L080C632C
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	ldr r2, .L080C6330
	adds r0, r2, #0
	strh r0, [r1]
	bl sub_080C153C
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C631C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C6320: .4byte 0x02001000 @ EWRAM+0x1000
.L080C6324: .4byte 0x06004000 @ VRAM+0x4000
.L080C6328: .4byte 0x84000B00
.L080C632C: .4byte 0x00004207
.L080C6330: .4byte 0x00008606

	thumb_func_start sub_080C6334
sub_080C6334: @ 0x080C6334
	push {r4, lr}
	sub sp, #0xc
	ldr r0, .L080C63A8
	ldr r4, .L080C63AC
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080C63B0
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, r2
	bl LZ77UnCompWram
	ldr r0, .L080C63B4
	movs r1, #0x80
	lsls r1, r1, #6
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	bl sub_080C14FC
	ldr r1, .L080C63B8
	movs r0, #0x1c
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #1
	movs r3, #0
	bl Tilemap_FillRect
	add r1, sp, #8
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080C63BC
	add r2, sp, #8
	str r2, [r1]
	ldr r0, .L080C63C0
	str r0, [r1, #4]
	ldr r0, .L080C63C4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, .L080C63C8
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r2]
	ldr r0, .L080C63CC
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C63A8: .4byte gUnknown_08245B80
.L080C63AC: .4byte 0x02001000 @ EWRAM+0x1000
.L080C63B0: .4byte gUnknown_08245E28
.L080C63B4: .4byte gUnknown_0824696C
.L080C63B8: .4byte 0x02000000 @ EWRAM
.L080C63BC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C63C0: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080C63C4: .4byte 0x81000080
.L080C63C8: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080C63CC: .4byte sub_080C62F0

	thumb_func_start sub_080C63D0
sub_080C63D0: @ 0x080C63D0
	ldr r1, .L080C63E4
	ldr r0, .L080C63E8
	str r0, [r1]
	ldr r0, .L080C63EC
	str r0, [r1, #4]
	ldr r0, .L080C63F0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C63E4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C63E8: .4byte 0x02000000 @ EWRAM
.L080C63EC: .4byte 0x06003000 @ VRAM+0x3000
.L080C63F0: .4byte 0x84000400

	thumb_func_start sub_080C63F4
sub_080C63F4: @ 0x080C63F4
	ldr r1, .L080C6408
	ldr r0, .L080C640C
	str r0, [r1]
	ldr r0, .L080C6410
	str r0, [r1, #4]
	ldr r0, .L080C6414
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C6408: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C640C: .4byte 0x02000000 @ EWRAM
.L080C6410: .4byte 0x06001000 @ VRAM+0x1000
.L080C6414: .4byte 0x84000400

	thumb_func_start sub_080C6418
sub_080C6418: @ 0x080C6418
	push {r4, lr}
	sub sp, #0x14
	movs r3, #0
	str r3, [sp, #0x10]
	ldr r2, .L080C645C
	add r0, sp, #0x10
	str r0, [r2]
	ldr r4, .L080C6460
	str r4, [r2, #4]
	ldr r0, .L080C6464
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	cmp r1, #0
	bne .L080C6474
	ldr r0, .L080C6468
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #0x20
	str r1, [sp, #8]
	movs r1, #0x15
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #8
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080C646C
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080C6470
	movs r0, #0x40
	b .L080C64A2
	.byte 0x00, 0x00
.L080C645C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C6460: .4byte 0x02000000 @ EWRAM
.L080C6464: .4byte 0x85000400
.L080C6468: .4byte gUnknown_082483CC
.L080C646C: .4byte sub_080C63D0
.L080C6470: .4byte 0x0300000E @ IWRAM+0xE
.L080C6474:
	ldr r0, .L080C64AC
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #0x20
	str r1, [sp, #8]
	movs r1, #0x40
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #8
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080C64B0
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080C64B4
	movs r0, #0x68
	strh r0, [r1]
	ldr r1, .L080C64B8
	movs r2, #0xf1
	lsls r2, r2, #6
	adds r0, r2, #0
.L080C64A2:
	strh r0, [r1]
	add sp, #0x14
	pop {r4}
	pop {r0}
	bx r0
.L080C64AC: .4byte gUnknown_082473CC
.L080C64B0: .4byte sub_080C63F4
.L080C64B4: .4byte 0x03000006 @ IWRAM+0x6
.L080C64B8: .4byte 0x03000040 @ IWRAM+0x40

	thumb_func_start sub_080C64BC
sub_080C64BC: @ 0x080C64BC
	push {lr}
	sub sp, #4
	ldr r1, .L080C64D8
	ldr r2, .L080C64DC
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	add sp, #4
	pop {r0}
	bx r0
.L080C64D8: .4byte gUnknown_082472CC
.L080C64DC: .4byte 0x03002AB0 @ IWRAM+0x2AB0

	thumb_func_start sub_080C64E0
sub_080C64E0: @ 0x080C64E0
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080C650C
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080C6510
	str r0, [r1, #4]
	ldr r0, .L080C6514
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xca
	ldr r2, .L080C6518
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	ldr r2, .L080C651C
	adds r0, r2, #0
	strh r0, [r1]
	add sp, #4
	bx lr
	.byte 0x00, 0x00
.L080C650C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C6510: .4byte 0x06001000 @ VRAM+0x1000
.L080C6514: .4byte 0x85000400
.L080C6518: .4byte 0x00008209
.L080C651C: .4byte 0x00008607

	thumb_func_start sub_080C6520
sub_080C6520: @ 0x080C6520
	push {lr}
	bl sub_080C1440
	ldr r0, .L080C6544
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080C6548
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080C654C
	strh r1, [r0]
	ldr r0, .L080C6550
	strh r1, [r0]
	ldr r0, .L080C6554
	strh r1, [r0]
	pop {r0}
	bx r0
.L080C6544: .4byte sub_080C64E0
.L080C6548: .4byte 0x03000006 @ IWRAM+0x6
.L080C654C: .4byte 0x03000004 @ IWRAM+0x4
.L080C6550: .4byte 0x0300000E @ IWRAM+0xE
.L080C6554: .4byte 0x0300000C @ IWRAM+0xC

	thumb_func_start sub_080C6558
sub_080C6558: @ 0x080C6558
.L080C6558:
	push {lr}
	sub sp, #0x10
	movs r0, #0xc6
	bl Flag_Test
	cmp r0, #0
	bne .L080C658C
	ldr r0, .L080C6594
	ldr r1, [r0]
	ldr r0, .L080C6598
	cmp r1, r0
	beq .L080C658C
	ldr r0, .L080C659C
	ldr r1, .L080C65A0
	movs r2, #3
	str r2, [sp]
	movs r2, #0xc
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
.L080C658C:
	add sp, #0x10
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C6594: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080C6598: .4byte sub_080D977C
.L080C659C: .4byte gUnknown_081B90B0
.L080C65A0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4

	thumb_func_start sub_080C65A4
sub_080C65A4: @ 0x080C65A4
.L080C65A4:
	ldr r1, .L080C65B8
	ldr r0, .L080C65BC
	str r0, [r1]
	ldr r0, .L080C65C0
	str r0, [r1, #4]
	ldr r0, .L080C65C4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C65B8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C65BC: .4byte gUnknown_081A7DB8
.L080C65C0: .4byte 0x06011500 @ VRAM+0x11500
.L080C65C4: .4byte 0x84000100

	thumb_func_start sub_080C65C8
sub_080C65C8: @ 0x080C65C8
.L080C65C8:
	push {lr}
	movs r1, #0
	movs r2, #0xa0
	lsls r2, r2, #7
	ldr r0, .L080C65E4
.L080C65D2:
	strh r2, [r0]
	strh r2, [r0, #2]
	adds r0, #4
	adds r1, #1
	cmp r1, #5
	bls .L080C65D2
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C65E4: .4byte 0x0200F7D8 @ EWRAM+0xF7D8

	thumb_func_start sub_080C65E8
sub_080C65E8: @ 0x080C65E8
.L080C65E8:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	add r1, sp, #0x10
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080C6688
	add r0, sp, #0x10
	str r0, [r1]
	ldr r4, .L080C668C
	str r4, [r1, #4]
	ldr r0, .L080C6690
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0
	mov sb, r2
	movs r0, #8
	strh r0, [r4, #0x18]
	movs r5, #3
	strh r5, [r4, #8]
	movs r7, #7
	strh r7, [r4, #0x1c]
	strh r5, [r4, #0xc]
	strh r7, [r4, #0x1e]
	strh r5, [r4, #0xe]
	movs r6, #9
	strh r6, [r4, #0x12]
	strh r5, [r4, #2]
	add r0, sp, #0x10
	mov r2, sb
	strh r2, [r0]
	str r0, [r1]
	ldr r0, .L080C6694
	mov r8, r0
	str r0, [r1, #4]
	ldr r0, .L080C6698
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080C669C
	ldrh r0, [r0]
	bl sub_080C8AF8
	adds r1, r0, #0
	cmp r1, #1
	bne .L080C66DC
	ldr r0, .L080C66A0
	str r1, [sp]
	mov r1, sb
	str r1, [sp, #4]
	str r7, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080C66A4
	movs r2, #0xac
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080C66AC
	ldr r0, .L080C66A8
	movs r1, #0xd
	str r1, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	b .L080C66B0
.L080C6688: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C668C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C6690: .4byte 0x8100003A
.L080C6694: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C6698: .4byte 0x81000400
.L080C669C: .4byte 0x03004614 @ IWRAM+0x4614
.L080C66A0: .4byte gUnknown_081B8270
.L080C66A4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C66A8: .4byte gUnknown_081B92B0
.L080C66AC:
	strh r5, [r4, #0x14]
	strh r5, [r4, #4]
.L080C66B0:
	ldr r0, .L080C66D4
	ldr r1, .L080C66D8
	movs r2, #0x15
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r2, #8
	str r2, [sp, #8]
	movs r2, #2
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	bl sub_080C6558
	b .L080C66EC
	.byte 0x00, 0x00
.L080C66D4: .4byte gUnknown_081B8170
.L080C66D8: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C66DC:
	strh r6, [r4, #0x10]
	strh r5, [r4]
	strh r5, [r4, #0x14]
	strh r5, [r4, #4]
	strh r6, [r4, #0x16]
	strh r5, [r4, #6]
	movs r0, #1
	strh r0, [r4, #0x30]
.L080C66EC:
	bl sub_080C65A4
	bl sub_080C7EFC
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r1, .L080C6728
	add r0, sp, #0x14
	str r0, [r1]
	ldr r0, .L080C672C
	str r0, [r1, #4]
	ldr r0, .L080C6730
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080C8440
	bl sub_080C65C8
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C6728: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C672C: .4byte 0x0200E8D8 @ EWRAM+0xE8D8
.L080C6730: .4byte 0x850003C0

	thumb_func_start sub_080C6734
sub_080C6734: @ 0x080C6734
.L080C6734:
	ldr r1, .L080C6750
	ldr r0, .L080C6754
	str r0, [r1]
	ldr r0, .L080C6758
	str r0, [r1, #4]
	ldr r0, .L080C675C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080C6760
	adds r0, #0x6c
	movs r1, #0
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C6750: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C6754: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C6758: .4byte 0x06001000 @ VRAM+0x1000
.L080C675C: .4byte 0x80000400
.L080C6760: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C6764
sub_080C6764: @ 0x080C6764
.L080C6764:
	push {r4, lr}
	ldr r0, .L080C6790
	ldr r1, [r0]
	ldr r0, .L080C6794
	cmp r1, r0
	beq .L080C6788
	ldr r0, .L080C6798
	adds r4, r0, #0
	adds r4, #0x6c
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080C6788
	ldr r0, .L080C679C
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #1
	strh r0, [r4]
.L080C6788:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C6790: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080C6794: .4byte sub_080D977C
.L080C6798: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C679C: .4byte sub_080C6734

	thumb_func_start sub_080C67A0
sub_080C67A0: @ 0x080C67A0
.L080C67A0:
	push {lr}
	bl sub_080C21D0
	ldr r2, .L080C67B8
	ldr r1, .L080C67BC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2, #0x38]
	pop {r0}
	bx r0
.L080C67B8: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C67BC: .4byte gUnknown_0834A230

	thumb_func_start sub_080C67C0
sub_080C67C0: @ 0x080C67C0
.L080C67C0:
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	bl sub_080C21D0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r4, #0x14
	lsrs r0, r0, #0xf
	adds r0, r0, r5
	ldr r1, .L080C67F8
	adds r3, r0, r1
	ldr r1, .L080C67FC
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, .L080C6800
	adds r0, r1, r0
	adds r1, r3, #0
	bl sub_080C7EB4
	bl sub_080C67A0
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C67F8: .4byte 0x0000021E
.L080C67FC: .4byte gUnknown_0834A224
.L080C6800: .4byte gUnknown_081B7030

	thumb_func_start sub_080C6804
sub_080C6804: @ 0x080C6804
.L080C6804:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r0, .L080C6828
	ldrh r0, [r0, #0x36]
	cmp r0, #1
	bne .L080C6812
	b .L080C6AC8
.L080C6812:
	ldr r0, .L080C682C
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080C6830
	bl sub_080C700C
	bl sub_080C7234
	bl sub_080C7430
	b .L080C6840
.L080C6828: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C682C: .4byte 0x03004550 @ IWRAM+0x4550
.L080C6830:
	cmp r0, #0x19
	bne .L080C6840
	bl sub_080C6FF0
	bl sub_080C7218
	bl sub_080C7414
.L080C6840:
	bl sub_080C726C
	bl sub_080C7880
	bl sub_080C7AFC
	bl sub_080C71EC
	ldr r0, .L080C6914
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne .L080C6874
	ldr r2, .L080C6918
	ldr r0, .L080C691C
	adds r2, r2, r0
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	strb r0, [r2]
	ldr r0, .L080C6920
	movs r1, #1
	bl VBlankTask_AddCounted
.L080C6874:
	bl sub_080C745C
	bl sub_080C76B4
	movs r0, #0xc6
	bl Flag_Test
	cmp r0, #0
	bne .L080C68E6
	ldr r0, .L080C6924
	ldr r1, [r0]
	ldr r0, .L080C6928
	cmp r1, r0
	beq .L080C68E6
	ldr r4, .L080C692C
	ldrh r1, [r4, #0x30]
	cmp r1, #0
	bne .L080C68AE
	ldr r0, .L080C6930
	str r1, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x60
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080C68AE:
	ldrh r0, [r4, #0x38]
	cmp r0, #0
	beq .L080C68BE
	subs r0, #1
	strh r0, [r4, #0x38]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C68E6
.L080C68BE:
	ldrh r5, [r4, #0x34]
	cmp r5, #0
	bne .L080C68E6
	ldr r0, .L080C6934
	movs r1, #7
	bl sub_080C67C0
	bl sub_080C7E90
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #0x32]
	adds r1, #1
	strh r1, [r4, #0x32]
	ldrh r1, [r4, #0x32]
	cmp r1, r0
	bne .L080C68E2
	strh r5, [r4, #0x32]
.L080C68E2:
	bl Palette_MarkDirty
.L080C68E6:
	ldr r0, .L080C6938
	movs r2, #0
	str r2, [r0]
	ldr r0, .L080C692C
	adds r1, r0, #0
	adds r1, #0x72
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls .L080C6902
	strh r2, [r1]
.L080C6902:
	ldrh r0, [r1]
	cmp r0, #5
	bls .L080C690A
	b .L080C6AB8
.L080C690A:
	lsls r0, r0, #2
	ldr r1, .L080C693C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080C6914: .4byte 0x030031BC @ IWRAM+0x31BC
.L080C6918: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C691C: .4byte 0x00000A27
.L080C6920: .4byte sub_080C7EFC
.L080C6924: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080C6928: .4byte sub_080D977C
.L080C692C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C6930: .4byte gUnknown_080005DC
.L080C6934: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080C6938: .4byte 0x0200F7F0 @ EWRAM+0xF7F0
.L080C693C: .4byte gUnknown_080C6940
	.global gUnknown_080C6940
gUnknown_080C6940:
.L080C6940: @ jump table
	.4byte .L080C6958
	.4byte .L080C6990
	.4byte .L080C69C8
	.4byte .L080C6A00
	.4byte .L080C6A3E
	.4byte .L080C6A7C
.L080C6958:
	movs r0, #0
	movs r1, #0xc
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #1
	movs r1, #0x59
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #2
	movs r1, #0xa6
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #3
	movs r1, #0xc
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #4
	movs r1, #0x59
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #5
	movs r1, #0xa6
	b .L080C6A74
.L080C6990:
	movs r0, #1
	movs r1, #0x59
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #2
	movs r1, #0xa6
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #3
	movs r1, #0xc
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #4
	movs r1, #0x59
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #5
	movs r1, #0xa6
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #0
	movs r1, #0xc
	b .L080C6A36
.L080C69C8:
	movs r0, #2
	movs r1, #0xa6
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #3
	movs r1, #0xc
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #4
	movs r1, #0x59
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #5
	movs r1, #0xa6
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #0
	movs r1, #0xc
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #1
	movs r1, #0x59
	b .L080C6A36
.L080C6A00:
	movs r0, #3
	movs r1, #0xc
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #4
	movs r1, #0x59
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #5
	movs r1, #0xa6
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #0
	movs r1, #0xc
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #1
	movs r1, #0x59
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #2
	movs r1, #0xa6
.L080C6A36:
	movs r2, #0x6b
	bl sub_080C6BE0
	b .L080C6AB8
.L080C6A3E:
	movs r0, #4
	movs r1, #0x59
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #5
	movs r1, #0xa6
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #0
	movs r1, #0xc
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #1
	movs r1, #0x59
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #2
	movs r1, #0xa6
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #3
	movs r1, #0xc
.L080C6A74:
	movs r2, #0x87
	bl sub_080C6BE0
	b .L080C6AB8
.L080C6A7C:
	movs r0, #5
	movs r1, #0xa6
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #0
	movs r1, #0xc
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #1
	movs r1, #0x59
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #2
	movs r1, #0xa6
	movs r2, #0x6b
	bl sub_080C6BE0
	movs r0, #3
	movs r1, #0xc
	movs r2, #0x87
	bl sub_080C6BE0
	movs r0, #4
	movs r1, #0x59
	movs r2, #0x87
	bl sub_080C6BE0
.L080C6AB8:
	ldr r0, .L080C6AD0
	ldr r0, [r0]
	cmp r0, #1
	bne .L080C6AC8
	ldr r0, .L080C6AD4
	movs r1, #1
	bl VBlankTask_AddCounted
.L080C6AC8:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C6AD0: .4byte 0x0200F7F0 @ EWRAM+0xF7F0
.L080C6AD4: .4byte sub_080C8440

	thumb_func_start sub_080C6AD8
sub_080C6AD8: @ 0x080C6AD8
.L080C6AD8:
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0xc
	adds r4, r0, #0
	mov r8, r1
	mov sb, r2
	adds r5, r3, #0
	ldr r6, [sp, #0x24]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r0, sb
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	adds r0, r4, #0
	bl sub_080C6FB8
	adds r2, r0, #0
	subs r2, #1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, .L080C6B3C
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r0, [r4]
	movs r1, #0
	str r1, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	mov r1, r8
	mov r3, sb
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C6B3C: .4byte gUnknown_0834A254

	thumb_func_start sub_080C6B40
sub_080C6B40: @ 0x080C6B40
.L080C6B40:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r4, [sp, #0x18]
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov ip, r1
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r3, r1, #0x10
	movs r1, #0
	ldr r0, .L080C6BA4
	movs r7, #0xa2
	lsls r7, r7, #4
	adds r2, r0, r7
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, r3
	beq .L080C6B86
.L080C6B74:
	adds r1, #1
	cmp r1, #5
	bhi .L080C6B86
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r3
	bne .L080C6B74
.L080C6B86:
	cmp r1, #6
	beq .L080C6B9A
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	str r4, [sp]
	mov r1, ip
	adds r2, r6, #0
	adds r3, r5, #0
	bl sub_080C6AD8
.L080C6B9A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C6BA4: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_080C6BA8
sub_080C6BA8: @ 0x080C6BA8
.L080C6BA8:
	push {r4, lr}
	ldr r4, .L080C6BC4
	ldr r1, .L080C6BC8
	adds r2, r1, #0
	ldr r0, .L080C6BCC
	adds r3, r1, r0
.L080C6BB4:
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080C6BD0
	ldr r0, [r1, #0x20]
	cmp r0, r4
	bne .L080C6BD0
	adds r0, r2, #0
	b .L080C6BDA
.L080C6BC4: .4byte sub_080D2F60
.L080C6BC8: .4byte 0x02009004 @ EWRAM+0x9004
.L080C6BCC: .4byte 0x0000189C
.L080C6BD0:
	adds r1, #0x64
	adds r2, #0x64
	cmp r1, r3
	bls .L080C6BB4
	movs r0, #0
.L080C6BDA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C6BE0
sub_080C6BE0: @ 0x080C6BE0
.L080C6BE0:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r2, r4, #1
	ldr r0, .L080C6C4C
	adds r6, r2, r0
	adds r1, r0, #0
	adds r1, #0xc
	adds r5, r2, r1
	subs r0, #0xc
	adds r2, r2, r0
	ldrh r0, [r2]
	cmp r0, #1
	bne .L080C6C10
	b .L080C6E18
.L080C6C10:
	ldr r0, .L080C6C50
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r0, r4, r0
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080C6C58
	ldr r0, .L080C6C54
	movs r4, #0
	str r4, [sp]
	mov r1, r8
	adds r1, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	adds r1, r7, #7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #7
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	strh r4, [r6]
	b .L080C6E18
.L080C6C4C: .4byte 0x0200E81C @ EWRAM+0xE81C
.L080C6C50: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C6C54: .4byte gUnknown_0800082C
.L080C6C58:
	adds r0, r4, #0
	bl sub_080C0148
	mov sb, r0
	movs r2, #0
	mov r8, r2
	movs r7, #0
	ldrh r0, [r6]
	cmp r0, #0
	beq .L080C6C94
	ldr r0, .L080C6DC8
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L080C6C8C
	ldrh r0, [r5]
	rsbs r0, r0, #0
	strh r0, [r5]
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C6C8C
	strh r7, [r5]
.L080C6C8C:
	ldrh r0, [r5]
	adds r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L080C6C94:
	ldr r0, .L080C6DCC
	ldrh r0, [r0, #0x3e]
	cmp r0, #1
	bne .L080C6CA4
	bl sub_080C6BA8
	cmp r0, #0
	bne .L080C6CD6
.L080C6CA4:
	ldr r0, .L080C6DD0
	lsls r3, r4, #2
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldr r2, .L080C6DD4
	adds r1, r3, r2
	ldrh r1, [r1]
	add r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	adds r2, #2
	adds r3, r3, r2
	ldrh r1, [r3]
	adds r1, r7, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #7
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080C6CD6:
	ldr r0, .L080C6DCC
	ldrh r0, [r0, #0x3e]
	cmp r0, #1
	bne .L080C6CE2
	cmp r4, #2
	beq .L080C6D08
.L080C6CE2:
	ldr r1, .L080C6DD8
	lsls r2, r4, #2
	adds r0, r2, r1
	ldrh r3, [r0]
	add r3, r8
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r1, #2
	adds r2, r2, r1
	ldrh r0, [r2]
	adds r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl sub_080C6AD8
.L080C6D08:
	ldr r0, .L080C6DCC
	ldrh r0, [r0, #0x3e]
	cmp r0, #1
	bne .L080C6D1C
	cmp r4, #0
	beq .L080C6D48
	cmp r4, #3
	beq .L080C6D48
	cmp r4, #4
	beq .L080C6D48
.L080C6D1C:
	ldr r1, .L080C6DDC
	lsls r3, r4, #2
	adds r0, r3, r1
	ldrh r2, [r0]
	add r2, r8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, #2
	adds r3, r3, r1
	ldrh r3, [r3]
	adds r3, r7, r3
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r1, sb
	ldrh r0, [r1, #0x1a]
	str r0, [sp]
	ldrh r0, [r1, #0x18]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	bl sub_080C8214
.L080C6D48:
	mov r2, sb
	movs r1, #0x1e
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq .L080C6D7E
	ldr r1, .L080C6DE0
	lsls r3, r4, #2
	adds r0, r3, r1
	ldrh r2, [r0]
	add r2, r8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, #2
	adds r3, r3, r1
	ldrh r3, [r3]
	adds r3, r7, r3
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r1, sb
	ldrh r0, [r1, #0x1e]
	str r0, [sp]
	ldrh r0, [r1, #0x1c]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #1
	bl sub_080C8214
.L080C6D7E:
	ldr r0, .L080C6DCC
	ldrh r0, [r0, #0x3e]
	cmp r0, #1
	bne .L080C6D8E
	cmp r4, #0
	beq .L080C6E18
	cmp r4, #2
	beq .L080C6E18
.L080C6D8E:
	mov r2, sb
	movs r0, #0x1e
	ldrsh r1, [r2, r0]
	cmp r1, #0
	beq .L080C6DEC
	ldr r0, .L080C6DE4
	movs r1, #0
	str r1, [sp]
	ldr r2, .L080C6DE8
	lsls r3, r4, #2
	adds r1, r3, r2
	ldrh r1, [r1]
	add r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	adds r2, #2
	adds r3, r3, r2
	ldrh r1, [r3]
	adds r1, r7, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #7
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	b .L080C6E18
.L080C6DC8: .4byte 0x030031BC @ IWRAM+0x31BC
.L080C6DCC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C6DD0: .4byte gUnknown_0834A23C
.L080C6DD4: .4byte gUnknown_0834A274
.L080C6DD8: .4byte gUnknown_0834A28C
.L080C6DDC: .4byte gUnknown_0834A2BC
.L080C6DE0: .4byte gUnknown_0834A2D4
.L080C6DE4: .4byte gUnknown_080005EC
.L080C6DE8: .4byte gUnknown_0834A2A4
.L080C6DEC:
	ldr r0, .L080C6E28
	str r1, [sp]
	ldr r2, .L080C6E2C
	lsls r3, r4, #2
	adds r1, r3, r2
	ldrh r1, [r1]
	add r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	adds r2, #2
	adds r3, r3, r2
	ldrh r1, [r3]
	adds r1, r7, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #7
	movs r2, #0
	movs r3, #1
	bl Sprite_DrawSingle
.L080C6E18:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C6E28: .4byte gUnknown_0834A26C
.L080C6E2C: .4byte gUnknown_0834A2A4

	thumb_func_start sub_080C6E30
sub_080C6E30: @ 0x080C6E30
.L080C6E30:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L080C6E50
	strh r0, [r2, #0x3c]
	strh r0, [r2, #0x3e]
	adds r1, r2, #0
	adds r1, #0x40
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080C6E50: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C6E54
sub_080C6E54: @ 0x080C6E54
	ldr r1, .L080C6E68
	ldr r0, .L080C6E6C
	str r0, [r1]
	ldr r0, .L080C6E70
	str r0, [r1, #4]
	ldr r0, .L080C6E74
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C6E68: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C6E6C: .4byte 0x020399E4 @ EWRAM+0x399E4
.L080C6E70: .4byte 0x06010C00 @ VRAM+0x10C00
.L080C6E74: .4byte 0x84000180

	thumb_func_start Party_BuildMemberNameTiles
Party_BuildMemberNameTiles: @ 0x080C6E78
.L080C6E78:
	push {r4, r5, r6, r7, lr}
	movs r4, #0
.L080C6E7C:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r6, r4, #1
	cmp r0, #0
	beq .L080C6EE6
	adds r5, r0, #0
	lsls r1, r4, #8
	ldr r0, .L080C6EC8
	adds r2, r1, r0
	movs r4, #0
	movs r3, #0
	ldr r7, .L080C6ECC
.L080C6E98:
	adds r1, r5, r4
	ldrb r0, [r1]
	cmp r0, #0xff
	beq .L080C6ED0
	adds r1, r0, #0
	lsls r1, r1, #5
	adds r1, r1, r7
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
	b .L080C6EE0
.L080C6EC8: .4byte 0x020399E4 @ EWRAM+0x399E4
.L080C6ECC: .4byte gUnknown_081AF7B8
.L080C6ED0:
	stm r2!, {r3}
	stm r2!, {r3}
	stm r2!, {r3}
	stm r2!, {r3}
	stm r2!, {r3}
	stm r2!, {r3}
	stm r2!, {r3}
	stm r2!, {r3}
.L080C6EE0:
	adds r4, #1
	cmp r4, #7
	ble .L080C6E98
.L080C6EE6:
	adds r4, r6, #0
	cmp r4, #5
	ble .L080C6E7C
	ldr r0, .L080C6EFC
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C6EFC: .4byte sub_080C6E54

	thumb_func_start sub_080C6F00
sub_080C6F00: @ 0x080C6F00
	ldr r1, .L080C6F1C
	ldr r0, .L080C6F20
	str r0, [r1]
	ldr r0, .L080C6F24
	str r0, [r1, #4]
	ldr r0, .L080C6F28
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080C6F2C
	adds r0, #0x6e
	movs r1, #0
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C6F1C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C6F20: .4byte 0x02039FE4 @ EWRAM+0x39FE4
.L080C6F24: .4byte 0x06011200 @ VRAM+0x11200
.L080C6F28: .4byte 0x840000C0
.L080C6F2C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C6F30
sub_080C6F30: @ 0x080C6F30
.L080C6F30:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r5, #0
	bl sub_080C0148
	cmp r0, #0
	beq .L080C6F9E
	ldr r6, .L080C6FA4
	lsls r1, r5, #7
	ldr r0, .L080C6FA8
	adds r4, r1, r0
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	bl sub_080C86B4
	ldr r1, .L080C6FAC
	lsls r0, r0, #0x10
	asrs r0, r0, #0xd
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r6, r0, r6
	movs r1, #0
.L080C6F60:
	ldm r6!, {r0}
	stm r4!, {r0}
	ldm r6!, {r0}
	stm r4!, {r0}
	ldm r6!, {r0}
	stm r4!, {r0}
	ldm r6!, {r0}
	stm r4!, {r0}
	ldm r6!, {r0}
	stm r4!, {r0}
	ldm r6!, {r0}
	stm r4!, {r0}
	ldm r6!, {r0}
	stm r4!, {r0}
	ldm r6!, {r0}
	stm r4!, {r0}
	adds r1, #1
	cmp r1, #3
	bls .L080C6F60
	ldr r0, .L080C6FB0
	adds r4, r0, #0
	adds r4, #0x6e
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080C6F9E
	ldr r0, .L080C6FB4
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #1
	strh r0, [r4]
.L080C6F9E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C6FA4: .4byte gUnknown_081A81B8
.L080C6FA8: .4byte 0x02039FE4 @ EWRAM+0x39FE4
.L080C6FAC: .4byte gUnknown_0834A2EC
.L080C6FB0: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C6FB4: .4byte sub_080C6F00

	thumb_func_start sub_080C6FB8
sub_080C6FB8: @ 0x080C6FB8
.L080C6FB8:
	push {r4, lr}
	ldr r4, .L080C6FD4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080C86B4
	lsls r0, r0, #0x10
	asrs r0, r0, #0xd
	adds r4, #4
	adds r0, r0, r4
	ldr r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
.L080C6FD4: .4byte gUnknown_0834A2EC
