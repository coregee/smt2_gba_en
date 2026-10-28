	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080B89B0
sub_080B89B0: @ 0x080B89B0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	cmp r1, #0
	bne .L080B89E4
	ldrh r1, [r6, #0x24]
	ldr r4, .L080B89E0
	movs r5, #0x10
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x40
	bl Palette_FillWithEffect
	ldrh r1, [r6, #0x24]
	subs r4, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_FillWithEffect
	b .L080B8AB0
	.byte 0x00, 0x00
.L080B89E0: .4byte 0x03002F70 @ IWRAM+0x2F70
.L080B89E4:
	cmp r1, #1
	bne .L080B8A50
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl FieldMap_HasRecordRel
	cmp r0, #0
	bne .L080B8A24
	ldr r0, .L080B8A18
	ldr r1, [r0]
	ldr r4, .L080B8A1C
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r0, .L080B8A20
	ldr r1, [r0]
	subs r4, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	b .L080B8A90
.L080B8A18: .4byte 0x03004630 @ IWRAM+0x4630
.L080B8A1C: .4byte 0x03002F70 @ IWRAM+0x2F70
.L080B8A20: .4byte 0x03004510 @ IWRAM+0x4510
.L080B8A24:
	ldr r1, .L080B8A44
	ldr r4, .L080B8A48
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r1, .L080B8A4C
	subs r4, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	b .L080B8A90
	.byte 0x00, 0x00
.L080B8A44: .4byte 0x0200F814 @ EWRAM+0xF814
.L080B8A48: .4byte 0x03002F70 @ IWRAM+0x2F70
.L080B8A4C: .4byte 0x0200F7F4 @ EWRAM+0xF7F4
.L080B8A50:
	cmp r1, #2
	bne .L080B8A78
	add r1, sp, #4
	ldrh r0, [r6, #0x24]
	strh r0, [r1]
	ldr r1, .L080B8A6C
	add r0, sp, #4
	str r0, [r1]
	ldr r0, .L080B8A70
	str r0, [r1, #4]
	ldr r0, .L080B8A74
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b .L080B8AB0
.L080B8A6C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B8A70: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080B8A74: .4byte 0x81000080
.L080B8A78:
	ldr r4, .L080B8A98
	ldrh r0, [r4]
	bl sub_080C5F60
	adds r1, r0, #0
	ldrh r0, [r4]
	cmp r0, #0xda
	bne .L080B8AA0
	ldr r2, .L080B8A9C
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
.L080B8A90:
	movs r3, #0x20
	bl Palette_CopyWithEffect
	b .L080B8AB0
.L080B8A98: .4byte 0x03004534 @ IWRAM+0x4534
.L080B8A9C: .4byte 0x03002E90 @ IWRAM+0x2E90
.L080B8AA0:
	ldr r2, .L080B8ABC
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
.L080B8AB0:
	bl Palette_MarkDirty
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080B8ABC: .4byte 0x03002EB0 @ IWRAM+0x2EB0

	thumb_func_start sub_080B8AC0
sub_080B8AC0: @ 0x080B8AC0
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x24
	ldrh r0, [r1, #2]
	subs r0, #1
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B8AD8
	movs r0, #1
	b .L080B8ADA
.L080B8AD8:
	movs r0, #0
.L080B8ADA:
	strh r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080B8AE0
sub_080B8AE0: @ 0x080B8AE0
.L080B8AE0:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080B8B00
	ldr r1, .L080B8B04
	bl Task_Create
	strh r4, [r0, #0x24]
	strh r5, [r0, #0x26]
	pop {r4, r5}
	pop {r1}
	bx r1
.L080B8B00: .4byte gUnknown_08164EDC
.L080B8B04: .4byte 0x0000FFFF

	thumb_func_start sub_080B8B08
sub_080B8B08: @ 0x080B8B08
.L080B8B08:
	push {lr}
	movs r1, #0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B8B14
	movs r1, #1
.L080B8B14:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B8B1C
sub_080B8B1C: @ 0x080B8B1C
	push {lr}
	sub sp, #4
	ldr r2, .L080B8B34
	cmp r1, #0
	bne .L080B8B38
	movs r1, #0xf8
	lsls r1, r1, #2
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	b .L080B8B44
	.byte 0x00, 0x00
.L080B8B34: .4byte 0x03003110 @ IWRAM+0x3110
.L080B8B38:
	cmp r1, #1
	bne .L080B8B4C
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r1, #0x1f
.L080B8B44:
	movs r3, #0x20
	bl Palette_FillWithEffect
	b .L080B8B5A
.L080B8B4C:
	ldr r1, .L080B8B64
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
.L080B8B5A:
	bl Palette_MarkDirty
	add sp, #4
	pop {r0}
	bx r0
.L080B8B64: .4byte gUnknown_081BB7B0

	thumb_func_start sub_080B8B68
sub_080B8B68: @ 0x080B8B68
.L080B8B68:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080B8B88
	ldr r1, .L080B8B8C
	bl Task_Create
	strh r4, [r0, #0x24]
	strh r5, [r0, #0x26]
	pop {r4, r5}
	pop {r1}
	bx r1
.L080B8B88: .4byte gUnknown_08164F78
.L080B8B8C: .4byte 0x0000FFFF

	thumb_func_start sub_080B8B90
sub_080B8B90: @ 0x080B8B90
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x28]
	cmp r0, #0
	bne .L080B8B9E
	movs r0, #1
	b .L080B8BA0
.L080B8B9E:
	movs r0, #0
.L080B8BA0:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B8BA8
sub_080B8BA8: @ 0x080B8BA8
	push {lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x24]
	ldrh r0, [r0, #2]
	cmp r0, #4
	bhi .L080B8BE8
	lsls r0, r0, #2
	ldr r1, .L080B8BC0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080B8BC0: .4byte gUnknown_080B8BC4
	.global gUnknown_080B8BC4
gUnknown_080B8BC4:
.L080B8BC4: @ jump table
	.4byte .L080B8BD8
	.4byte .L080B8BE0
	.4byte .L080B8BE6
	.4byte .L080B8BD8
	.4byte .L080B8BD8
.L080B8BD8:
	ldr r2, .L080B8BDC
	b .L080B8BE8
.L080B8BDC: .4byte 0x00007C1F
.L080B8BE0:
	movs r2, #0xf8
	lsls r2, r2, #7
	b .L080B8BE8
.L080B8BE6:
	movs r2, #0x1f
.L080B8BE8:
	adds r0, r3, #0
	movs r1, #0
	movs r3, #1
	bl sub_080B8874
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B8BF8
sub_080B8BF8: @ 0x080B8BF8
	ldr r1, [r0, #0x24]
	ldrh r1, [r1, #2]
	strh r1, [r0, #0x1e]
	bx lr

	thumb_func_start sub_080B8C00
sub_080B8C00: @ 0x080B8C00
	push {lr}
	movs r1, #0
	movs r2, #0
	adds r0, #0x2c
.L080B8C08:
	strh r2, [r0]
	adds r0, #2
	adds r1, #1
	cmp r1, #5
	bls .L080B8C08
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B8C18
sub_080B8C18: @ 0x080B8C18
.L080B8C18:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r6, .L080B8C4C
	movs r7, #0
	movs r5, #0
.L080B8C2A:
	adds r0, r5, #0
	bl sub_080C0148
	adds r4, r0, #0
	cmp r4, #0
	beq .L080B8C66
	ldrb r0, [r4, #0xc]
	bl sub_080C0830
	cmp r0, #0
	bne .L080B8C66
	mov r0, r8
	cmp r0, #0
	bne .L080B8C50
	adds r0, r4, #0
	adds r0, #0x44
	b .L080B8C54
.L080B8C4C: .4byte 0x00007FFF
.L080B8C50:
	adds r0, r4, #0
	adds r0, #0x40
.L080B8C54:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r6, r0
	blo .L080B8C66
	adds r6, r0, #0
	ldrb r7, [r4, #0xc]
.L080B8C66:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #5
	bls .L080B8C2A
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080B8C7C
sub_080B8C7C: @ 0x080B8C7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r7, r1, #0
	mov sb, r2
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r0, #0
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x1c]
	cmp r1, #0
	bne .L080B8CA0
	b .L080B8E7A
.L080B8CA0:
	ldrb r5, [r1, #0xc]
	adds r6, r5, #0
	ldr r0, [r2, #0x24]
	ldrh r0, [r0, #2]
	adds r1, r0, #0
	cmp r1, #0
	bne .L080B8D0C
	adds r0, r5, #0
	bl sub_080C09B0
	adds r4, r0, #0
	cmp r4, #1
	beq .L080B8CBC
	b .L080B8E7A
.L080B8CBC:
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	beq .L080B8CC8
	b .L080B8E7A
.L080B8CC8:
	mov r0, sb
	cmp r0, #0
	beq .L080B8CD0
	b .L080B8E7A
.L080B8CD0:
	movs r0, #0
	bl sub_080B8C18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r5
	beq .L080B8CE0
	b .L080B8E7A
.L080B8CE0:
	adds r0, r5, #0
	bl sub_080C0818
	movs r1, #4
	ands r1, r0
	cmp r1, #0
	beq .L080B8CF0
	b .L080B8E7A
.L080B8CF0:
	bl sub_080C2244
	ands r0, r4
	cmp r0, #0
	bne .L080B8CFC
	b .L080B8E7A
.L080B8CFC:
	adds r0, r5, #0
	movs r1, #4
	bl sub_080C08F8
	adds r0, r7, #0
	bl sub_080C8490
	b .L080B8D6C
.L080B8D0C:
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L080B8DB8
	movs r4, #0
	cmp r1, #1
	bne .L080B8D1E
	movs r4, #2
.L080B8D1E:
	adds r0, r5, #0
	bl sub_080C09B0
	cmp r0, #1
	beq .L080B8D2A
	b .L080B8E7A
.L080B8D2A:
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	beq .L080B8D36
	b .L080B8E7A
.L080B8D36:
	mov r1, sb
	cmp r1, #0
	bne .L080B8D78
	adds r0, r5, #0
	bl sub_080C06BC
	cmp r0, r4
	bne .L080B8D48
	b .L080B8E7A
.L080B8D48:
	adds r0, r5, #0
	bl sub_080F4038
	movs r1, #0x26
	muls r0, r1, r0
	asrs r4, r0, #7
	cmp r4, #0
	bne .L080B8D5A
	movs r4, #1
.L080B8D5A:
	adds r0, r5, #0
	bl sub_080F401C
	cmp r4, r0
	ble .L080B8D6C
	adds r0, r5, #0
	bl sub_080F401C
	adds r4, r0, #0
.L080B8D6C:
	lsls r1, r7, #1
	mov r0, r8
	adds r0, #0x2c
	adds r0, r0, r1
	strh r4, [r0]
	b .L080B8E7A
.L080B8D78:
	lsls r1, r7, #1
	mov r0, r8
	adds r0, #0x2c
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, #0
	beq .L080B8E7A
	adds r0, r5, #0
	bl sub_080F401C
	cmp r0, #1
	bne .L080B8D9A
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080C0C70
	b .L080B8DA2
.L080B8D9A:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080C0C70
.L080B8DA2:
	adds r0, r7, #0
	bl sub_080C8490
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C86F4
	movs r0, #1
	mov r2, r8
	strh r0, [r2, #0x1c]
	b .L080B8E7A
.L080B8DB8:
	cmp r1, #3
	bne .L080B8E18
	adds r0, r5, #0
	bl sub_080C09B0
	adds r6, r0, #0
	cmp r6, #1
	bne .L080B8E7A
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080B8E7A
	mov r0, sb
	cmp r0, #0
	bne .L080B8DE4
	lsls r1, r7, #1
	mov r0, r8
	adds r0, #0x2c
	adds r0, r0, r1
	strh r6, [r0]
	b .L080B8E7A
.L080B8DE4:
	adds r0, r5, #0
	bl sub_080F4038
	adds r4, r0, #0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	asrs r4, r0, #7
	cmp r4, #0
	bne .L080B8DFA
	movs r4, #1
.L080B8DFA:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080C0C70
	lsls r1, r7, #1
	mov r0, r8
	adds r0, #0x2c
	adds r0, r0, r1
	strh r4, [r0]
	mov r1, r8
	strh r6, [r1, #0x1c]
	adds r0, r7, #0
	bl sub_080C8490
	b .L080B8E7A
.L080B8E18:
	cmp r1, #4
	bne .L080B8E7A
	adds r0, r6, #0
	bl sub_080C09B0
	adds r5, r0, #0
	cmp r5, #1
	bne .L080B8E7A
	adds r0, r6, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080B8E7A
	mov r2, sb
	cmp r2, #0
	bne .L080B8E7A
	movs r0, #1
	bl sub_080B8C18
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r6
	bne .L080B8E7A
	adds r0, r4, #0
	bl sub_080C0818
	movs r6, #0x80
	lsls r6, r6, #5
	adds r1, r6, #0
	ands r1, r0
	cmp r1, #0
	bne .L080B8E7A
	bl sub_080C2244
	ands r0, r5
	cmp r0, #0
	beq .L080B8E7A
	adds r0, r4, #0
	adds r1, r6, #0
	bl sub_080C08F8
	adds r0, r7, #0
	bl sub_080C8490
	lsls r1, r7, #1
	mov r0, r8
	adds r0, #0x2c
	adds r0, r0, r1
	strh r5, [r0]
.L080B8E7A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B8E88
sub_080B8E88: @ 0x080B8E88
	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	movs r1, #0
	adds r3, r2, #0
	adds r3, #0x2c
	movs r4, #1
.L080B8E98:
	lsls r0, r1, #1
	adds r0, r3, r0
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B8EA6
	strh r4, [r2, #0x1c]
	b .L080B8EB0
.L080B8EA6:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #5
	bls .L080B8E98
.L080B8EB0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B8EB8
sub_080B8EB8: @ 0x080B8EB8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r7, r1, #0
	movs r0, #0x24
	adds r0, r0, r4
	mov r8, r0
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r6, r0, #0
	ldr r5, .L080B8EF4
	ldr r0, .L080B8EF8
	bl sub_080B8490
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080B832C
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	beq .L080B8F10
	cmp r0, #1
	bgt .L080B8EFC
	cmp r0, #0
	beq .L080B8F06
	b .L080B8F2A
	.byte 0x00, 0x00
.L080B8EF4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080B8EF8: .4byte gUnknown_080034EA
.L080B8EFC:
	cmp r0, #2
	beq .L080B8F18
	cmp r0, #3
	beq .L080B8F20
	b .L080B8F2A
.L080B8F06:
	ldr r1, .L080B8F0C
	b .L080B8F24
	.byte 0x00, 0x00
.L080B8F0C: .4byte 0x0000031A
.L080B8F10:
	ldr r1, .L080B8F14
	b .L080B8F24
.L080B8F14: .4byte 0x0000031D
.L080B8F18:
	ldr r1, .L080B8F1C
	b .L080B8F24
.L080B8F1C: .4byte 0x0000031B
.L080B8F20:
	movs r1, #0xc7
	lsls r1, r1, #2
.L080B8F24:
	adds r0, r1, #0
	strh r0, [r5]
	b .L080B8F36
.L080B8F2A:
	ldr r1, .L080B8F50
	adds r0, r1, #0
	strh r0, [r5]
	ldr r1, .L080B8F54
	ldrh r0, [r6, #0x12]
	strh r0, [r1]
.L080B8F36:
	ldr r2, .L080B8F58
	lsls r1, r7, #1
	mov r0, r8
	adds r0, #8
	adds r0, r0, r1
	ldrh r0, [r0]
	str r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B8F50: .4byte 0x0000031E
.L080B8F54: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080B8F58: .4byte 0x0203DB2C @ EWRAM+0x3DB2C

	thumb_func_start sub_080B8F5C
sub_080B8F5C: @ 0x080B8F5C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r4, #0
	adds r7, #0x24
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r5, r0, #0
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	beq .L080B8F94
	cmp r0, #1
	bgt .L080B8F80
	cmp r0, #0
	beq .L080B8F8A
	b .L080B8FB4
.L080B8F80:
	cmp r0, #2
	beq .L080B8F9C
	cmp r0, #3
	beq .L080B8FA4
	b .L080B8FB4
.L080B8F8A:
	ldr r1, .L080B8F90
	b .L080B8FA6
	.byte 0x00, 0x00
.L080B8F90: .4byte gUnknown_08003432
.L080B8F94:
	ldr r1, .L080B8F98
	b .L080B8FA6
.L080B8F98: .4byte gUnknown_08003452
.L080B8F9C:
	ldr r1, .L080B8FA0
	b .L080B8FA6
.L080B8FA0: .4byte gUnknown_08003472
.L080B8FA4:
	ldr r1, .L080B8FB0
.L080B8FA6:
	adds r0, r4, #0
	bl sub_080B832C
	b .L080B8FC2
	.byte 0x00, 0x00
.L080B8FB0: .4byte gUnknown_08003492
.L080B8FB4:
	ldr r1, .L080B8FD8
	adds r0, r4, #0
	bl sub_080B832C
	ldr r1, .L080B8FDC
	ldrh r0, [r5, #0x12]
	strh r0, [r1]
.L080B8FC2:
	ldr r2, .L080B8FE0
	lsls r1, r6, #1
	adds r0, r7, #0
	adds r0, #8
	adds r0, r0, r1
	ldrh r0, [r0]
	str r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B8FD8: .4byte gUnknown_080034B2
.L080B8FDC: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080B8FE0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C

	thumb_func_start sub_080B8FE4
sub_080B8FE4: @ 0x080B8FE4
	push {lr}
	movs r0, #1
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_080B8FF0
sub_080B8FF0: @ 0x080B8FF0
.L080B8FF0:
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080B900C
	ldr r1, .L080B9010
	bl Task_Create
	str r5, [r0, #0x24]
	strh r4, [r0, #0x28]
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B900C: .4byte gUnknown_08164FD0
.L080B9010: .4byte 0x0000FFFF

	thumb_func_start sub_080B9014
sub_080B9014: @ 0x080B9014
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080B9030
	ldr r1, .L080B9034
	bl Task_Create
	str r5, [r0, #0x24]
	strh r4, [r0, #0x28]
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B9030: .4byte gUnknown_0816514C
.L080B9034: .4byte 0x0000FFFF

	thumb_func_start sub_080B9038
sub_080B9038: @ 0x080B9038
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r1, .L080B9054
	movs r0, #1
	strh r0, [r1, #0x34]
	movs r0, #4
	bl PalFade_FadeToBlack
	str r0, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9054: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080B9058
sub_080B9058: @ 0x080B9058
.L080B9058:
	push {lr}
	ldr r0, .L080B9068
	ldr r1, .L080B906C
	bl Task_Create
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9068: .4byte gUnknown_081651B4
.L080B906C: .4byte 0x0000FFFF

	thumb_func_start sub_080B9070
sub_080B9070: @ 0x080B9070
	push {lr}
	ldr r0, .L080B907C
	bl sub_080AF060
	pop {r0}
	bx r0
.L080B907C: .4byte gUnknown_0807CF14

	thumb_func_start sub_080B9080
sub_080B9080: @ 0x080B9080
.L080B9080:
	push {lr}
	ldr r0, .L080B9090
	ldr r1, .L080B9094
	bl Task_Create
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9090: .4byte gUnknown_081651E8
.L080B9094: .4byte 0x0000FFFF

	thumb_func_start sub_080B9098
sub_080B9098: @ 0x080B9098
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080B90B4
	adds r0, #0x5c
	ldrh r3, [r0]
	adds r2, r3, #0
	ands r2, r1
	cmp r2, #0
	beq .L080B90B8
	bics r3, r1
	strh r3, [r0]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080B90BA
.L080B90B4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B90B8:
	strh r2, [r4, #0x1c]
.L080B90BA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B90C0
sub_080B90C0: @ 0x080B90C0
	push {lr}
	movs r0, #0x1a
	bl sub_080AF1E8
	pop {r0}
	bx r0

	thumb_func_start sub_080B90CC
sub_080B90CC: @ 0x080B90CC
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080B90DC
	ldrh r0, [r0]
	cmp r0, #0x1a
	bne .L080B90E0
	movs r0, #1
	b .L080B90E2
.L080B90DC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B90E0:
	movs r0, #0
.L080B90E2:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080B90E8
sub_080B90E8: @ 0x080B90E8
	push {lr}
	movs r0, #1
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_080B90F4
sub_080B90F4: @ 0x080B90F4
.L080B90F4:
	push {lr}
	ldr r0, .L080B9104
	ldr r1, .L080B9108
	bl Task_Create
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9104: .4byte gUnknown_0816522C
.L080B9108: .4byte 0x0000FFFF

	thumb_func_start sub_080B910C
sub_080B910C: @ 0x080B910C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x24
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #2
	bl Window_Create
	str r0, [r4, #8]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B9130
sub_080B9130: @ 0x080B9130
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x28]
	movs r3, #1
	adds r0, r3, #0
	lsls r0, r1
	ldr r1, [r2, #0x24]
	ands r1, r0
	cmp r1, #0
	beq .L080B9148
	strh r3, [r2, #0x1c]
	b .L080B914A
.L080B9148:
	strh r1, [r2, #0x1c]
.L080B914A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B9150
sub_080B9150: @ 0x080B9150
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r2, r0, #0
	movs r6, #0x12
	movs r7, #0x59
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldr r0, .L080B91C0
	ldrh r1, [r0]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080B9180
	strh r3, [r4, #0x1c]
.L080B9180:
	ldrb r0, [r2, #0xc]
	cmp r0, #3
	bhi .L080B91C4
	adds r0, r2, #0
	add r1, sp, #8
	bl Combatant_DecodeName
	add r0, sp, #8
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B91FC
	add r4, sp, #8
.L080B9198:
	ldrh r0, [r4]
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl FontSprite_DrawGlyph
	adds r0, r6, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r4, #2
	mov r0, sp
	adds r0, #0x16
	cmp r4, r0
	bhi .L080B91FC
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080B9198
	b .L080B91FC
.L080B91C0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080B91C4:
	ldrh r0, [r2, #0x12]
	bl sub_080BF648
	movs r5, #0
	adds r1, r0, #0
	adds r1, #0x22
	ldrh r0, [r0, #0x22]
	cmp r0, #0
	beq .L080B91FC
	adds r4, r1, #0
.L080B91D8:
	ldrh r0, [r4]
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl FontSprite_DrawGlyph
	adds r0, r6, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r4, #2
	adds r5, #1
	cmp r5, #7
	bhi .L080B91FC
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080B91D8
.L080B91FC:
	ldr r0, .L080B9218
	str r7, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl Text_DrawSpriteString
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9218: .4byte gUnknown_081652D8

	thumb_func_start sub_080B921C
sub_080B921C: @ 0x080B921C
	adds r0, #0x24
	ldr r1, [r0, #4]
	adds r1, #1
	str r1, [r0, #4]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080B9228
sub_080B9228: @ 0x080B9228
	push {lr}
	ldr r0, [r0, #0x2c]
	movs r1, #0
	bl Window_Close
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B9238
sub_080B9238: @ 0x080B9238
	push {lr}
	movs r0, #1
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_080B9244
sub_080B9244: @ 0x080B9244
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C5108
	cmp r0, #0
	bne .L080B9268
	movs r0, #1
	bl Flag_Test
	cmp r0, #0
	beq .L080B9260
	bl sub_080B9080
	b .L080B9264
.L080B9260:
	bl sub_080B9058
.L080B9264:
	movs r0, #1
	b .L080B926A
.L080B9268:
	movs r0, #0
.L080B926A:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B9274
sub_080B9274: @ 0x080B9274
.L080B9274:
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080B9288
	ldr r1, .L080B928C
	bl Task_Create
	str r4, [r0, #0x24]
	pop {r4}
	pop {r0}
	bx r0
.L080B9288: .4byte gUnknown_081652E4
.L080B928C: .4byte 0x0000FFFF

	thumb_func_start sub_080B9290
sub_080B9290: @ 0x080B9290
	push {lr}
	ldr r0, .L080B92A8
	ldrh r0, [r0, #2]
	bl sub_080B1A1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Field_Step
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B92A8: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B92AC
sub_080B92AC: @ 0x080B92AC
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080B80F8
	str r0, [r4, #0x24]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B92BC
sub_080B92BC: @ 0x080B92BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x24]
	bl sub_080B8160
	cmp r0, #1
	beq .L080B92CC
	movs r0, #0
.L080B92CC:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B92D4
sub_080B92D4: @ 0x080B92D4
	push {r4, r5, lr}
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	adds r4, r0, #0
	bl sub_080B2938
	adds r5, r0, #0
	cmp r4, #2
	bne .L080B9318
	ldr r0, .L080B92FC
	movs r1, #1
	bl VBlankTask_AddCounted
	cmp r5, #2
	bne .L080B9304
	ldr r0, .L080B9300
	b .L080B930A
.L080B92FC: .4byte sub_080AE1C4
.L080B9300: .4byte sub_080B34E8
.L080B9304:
	cmp r5, #3
	bne .L080B9320
	ldr r0, .L080B9314
.L080B930A:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B9320
	.byte 0x00, 0x00
.L080B9314: .4byte sub_080B350C
.L080B9318:
	ldr r0, .L080B932C
	movs r1, #1
	bl VBlankTask_AddCounted
.L080B9320:
	ldr r1, .L080B9330
	movs r0, #0x21
	strh r0, [r1, #0x2e]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080B932C: .4byte sub_080AE1FC
.L080B9330: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B9334
sub_080B9334: @ 0x080B9334
	push {lr}
	bl sub_080B2AB0
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B9340
sub_080B9340: @ 0x080B9340
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #2
	rsbs r0, r0, #0
	bl sub_080B343C
	ldr r0, .L080B9358
	ldrh r0, [r0, #0x2e]
	cmp r0, #0
	bne .L080B935C
	movs r0, #1
	b .L080B935E
.L080B9358: .4byte 0x03004550 @ IWRAM+0x4550
.L080B935C:
	movs r0, #0
.L080B935E:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B9368
sub_080B9368: @ 0x080B9368
	push {lr}
	ldr r0, .L080B9384
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080B9388
	strb r1, [r0]
	ldr r0, .L080B938C
	strb r1, [r0]
	movs r0, #1
	bl Field_SetState
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9384: .4byte 0x03000038 @ IWRAM+0x38
.L080B9388: .4byte 0x03000039 @ IWRAM+0x39
.L080B938C: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080B9390
sub_080B9390: @ 0x080B9390
	push {r4, lr}
	sub sp, #4
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r4, .L080B93E0
	adds r4, r4, r2
	movs r3, #0
	str r3, [sp]
	ldr r1, .L080B93E4
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080B93E8
	str r0, [r1, #4]
	ldr r0, .L080B93EC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xd0
	lsls r0, r0, #6
	subs r2, r0, r2
	str r3, [sp]
	mov r0, sp
	str r0, [r1]
	ldr r3, .L080B93F0
	str r3, [r1, #4]
	ldr r0, .L080B93F4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	str r4, [r1]
	str r3, [r1, #4]
	lsrs r2, r2, #2
	movs r0, #0x84
	lsls r0, r0, #0x18
	orrs r2, r0
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B93E0: .4byte 0x02005004 @ EWRAM+0x5004
.L080B93E4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B93E8: .4byte 0x06003800 @ VRAM+0x3800
.L080B93EC: .4byte 0x85000200
.L080B93F0: .4byte 0x06008800 @ VRAM+0x8800
.L080B93F4: .4byte 0x85000D00

	thumb_func_start sub_080B93F8
sub_080B93F8: @ 0x080B93F8
	push {lr}
	ldr r0, .L080B940C
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080B9410
	movs r0, #8
	strh r0, [r1]
	pop {r0}
	bx r0
.L080B940C: .4byte sub_080B9390
.L080B9410: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080B9414
sub_080B9414: @ 0x080B9414
	push {r4, lr}
	sub sp, #4
	movs r3, #0x80
	lsls r3, r3, #3
	ldr r4, .L080B9464
	movs r1, #0
	str r1, [sp]
	ldr r2, .L080B9468
	mov r0, sp
	str r0, [r2]
	ldr r0, .L080B946C
	str r0, [r2, #4]
	ldr r0, .L080B9470
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	str r1, [sp]
	mov r0, sp
	str r0, [r2]
	ldr r1, .L080B9474
	str r1, [r2, #4]
	ldr r0, .L080B9478
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	str r4, [r2]
	adds r1, r3, r1
	str r1, [r2, #4]
	movs r0, #0xd0
	lsls r0, r0, #6
	subs r0, r0, r3
	lsrs r0, r0, #2
	movs r1, #0x84
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9464: .4byte 0x02005004 @ EWRAM+0x5004
.L080B9468: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B946C: .4byte 0x06003800 @ VRAM+0x3800
.L080B9470: .4byte 0x85000200
.L080B9474: .4byte 0x06008800 @ VRAM+0x8800
.L080B9478: .4byte 0x85000D00

	thumb_func_start sub_080B947C
sub_080B947C: @ 0x080B947C
	push {lr}
	ldr r0, .L080B9494
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080B9498
	ldr r2, .L080B949C
	adds r0, r2, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9494: .4byte sub_080B9414
.L080B9498: .4byte 0x0300000E @ IWRAM+0xE
.L080B949C: .4byte 0x0000FFF8

	thumb_func_start sub_080B94A0
sub_080B94A0: @ 0x080B94A0
	push {lr}
	ldr r0, .L080B94B4
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080B94B8
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
.L080B94B4: .4byte sub_080B2880
.L080B94B8: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080B94BC
sub_080B94BC: @ 0x080B94BC
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080B94D4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080B94D8
	movs r0, #0
	b .L080B94DA
	.byte 0x00, 0x00
.L080B94D4: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080B94D8:
	movs r0, #1
.L080B94DA:
	strh r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080B94E0
sub_080B94E0: @ 0x080B94E0
	ldr r1, .L080B94EC
	ldrh r0, [r1]
	adds r0, #4
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080B94EC: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080B94F0
sub_080B94F0: @ 0x080B94F0
	ldr r1, .L080B94FC
	ldrh r0, [r1]
	subs r0, #4
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080B94FC: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080B9500
sub_080B9500: @ 0x080B9500
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080B9504
sub_080B9504: @ 0x080B9504
	ldr r1, .L080B950C
	ldrh r1, [r1]
	strh r1, [r0, #0x24]
	bx lr
.L080B950C: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080B9510
sub_080B9510: @ 0x080B9510
.L080B9510:
	push {lr}
	ldr r0, .L080B9520
	ldr r1, .L080B9524
	bl Task_Create
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B9520: .4byte gUnknown_08165444
.L080B9524: .4byte 0x0000FFFF

	thumb_func_start sub_080B9528
sub_080B9528: @ 0x080B9528
.L080B9528:
	push {lr}
	movs r1, #0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B9534
	movs r1, #1
.L080B9534:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B953C
sub_080B953C: @ 0x080B953C
.L080B953C:
	push {lr}
	movs r0, #0
	movs r1, #0
	bl FieldMap_CellRecordsRel
	movs r1, #0x21
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080B9554
	movs r0, #0
	b .L080B9562
.L080B9554:
	bl sub_080F3190
	movs r1, #0
	cmp r0, #0
	bne .L080B9560
	movs r1, #1
.L080B9560:
	adds r0, r1, #0
.L080B9562:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B9568
sub_080B9568: @ 0x080B9568
.L080B9568:
	movs r0, #1
	bx lr

	thumb_func_start sub_080B956C
sub_080B956C: @ 0x080B956C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #2
	bl Window_Create
	str r0, [r4, #0x24]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B958C
sub_080B958C: @ 0x080B958C
	push {lr}
	sub sp, #8
	ldr r0, .L080B95B8
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	movs r0, #0
	movs r1, #0
	movs r2, #0xd6
	movs r3, #0x5e
	bl sub_080C4AB0
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B95B8: .4byte gUnknown_08165574

	thumb_func_start sub_080B95BC
sub_080B95BC: @ 0x080B95BC
	push {r4, lr}
	adds r3, r0, #0
	movs r0, #0
	strh r0, [r3, #0x1c]
	ldr r2, .L080B95E4
	ldrh r1, [r2]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne .L080B95DC
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080B95DE
.L080B95DC:
	strh r4, [r3, #0x1c]
.L080B95DE:
	pop {r4}
	pop {r0}
	bx r0
.L080B95E4: .4byte 0x030031B8 @ IWRAM+0x31B8

	thumb_func_start sub_080B95E8
sub_080B95E8: @ 0x080B95E8
	push {lr}
	ldr r0, [r0, #0x24]
	movs r1, #0
	bl Window_Close
	movs r0, #0x12
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_080B95FC
sub_080B95FC: @ 0x080B95FC
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L080B9678
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B966E
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl FieldMap_HasRecordRel
	cmp r0, #1
	beq .L080B966E
	ldr r0, .L080B967C
	ldr r1, [r0]
	ldr r5, .L080B9680
	ldrh r0, [r1]
	strh r0, [r5]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r0, .L080B9684
	ldr r1, [r0]
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r5, r0
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #1
	movs r3, #0x10
	bl PalFade_FadeRangeWithDuration
	ldr r1, .L080B9688
	str r0, [r1]
	ldrh r0, [r5]
	cmp r0, #0
	beq .L080B966E
	movs r0, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0x10
	bl PalFade_FadeRangeWithDuration
.L080B966E:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9678: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B967C: .4byte 0x03004630 @ IWRAM+0x4630
.L080B9680: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B9684: .4byte 0x03004510 @ IWRAM+0x4510
.L080B9688: .4byte 0x0300452C @ IWRAM+0x452C

	thumb_func_start Location_GetNameCellFromCoords
Location_GetNameCellFromCoords: @ 0x080B968C
.L080B968C:
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r6, .L080B9704
	ldrh r4, [r6]
	mov sb, r4
	ldr r5, .L080B9708
	ldrh r4, [r5]
	mov r8, r4
	str r0, [r6]
	str r1, [r5]
	mov r4, sp
	adds r4, #2
	adds r0, r2, #0
	adds r1, r3, #0
	mov r2, sp
	adds r3, r4, #0
	bl sub_080C1F50
	ldrh r1, [r4]
	lsrs r0, r1, #2
	movs r3, #3
	ands r0, r3
	lsrs r1, r1, #4
	lsls r1, r1, #5
	adds r0, r0, r1
	mov r1, sp
	ldrh r2, [r1]
	lsrs r1, r2, #4
	lsls r1, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	lsrs r2, r2, #2
	ands r2, r3
	lsls r2, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #1
	ldr r1, .L080B970C
	adds r0, r0, r1
	mov r1, sb
	str r1, [r6]
	mov r4, r8
	str r4, [r5]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080B9704: .4byte 0x03004614 @ IWRAM+0x4614
.L080B9708: .4byte 0x03004514 @ IWRAM+0x4514
.L080B970C: .4byte gUnknown_080A54AC

	thumb_func_start sub_080B9710
sub_080B9710: @ 0x080B9710
.L080B9710:
	ldr r1, .L080B971C
	ldrh r0, [r0, #0x1a]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
.L080B971C: .4byte gUnknown_081655F8

	thumb_func_start sub_080B9720
sub_080B9720: @ 0x080B9720
.L080B9720:
	push {r4, lr}
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	bl sub_080B9710
	adds r0, #2
	lsls r4, r4, #2
	adds r0, r0, r4
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B9738
sub_080B9738: @ 0x080B9738
.L080B9738:
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080B9720
	ldrh r2, [r0]
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	bl sub_080C8B10
	pop {r1}
	bx r1

	thumb_func_start sub_080B9750
sub_080B9750: @ 0x080B9750
.L080B9750:
	push {lr}
	movs r0, #0
	movs r1, #0
	bl FieldMap_CellRecordsRel
	movs r1, #3
	bl FieldMap_FindRecord
	pop {r1}
	bx r1

	thumb_func_start sub_080B9764
sub_080B9764: @ 0x080B9764
.L080B9764:
	push {lr}
	bl sub_080B9750
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq .L080B9774
	movs r0, #0x5b
	b .L080B9776
.L080B9774:
	movs r0, #0x5a
.L080B9776:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B977C
sub_080B977C: @ 0x080B977C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080B9764
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5a
	beq .L080B9798
	bl sub_080B9764
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5b
	bne .L080B979C
.L080B9798:
	movs r0, #1
	b .L080B979E
.L080B979C:
	movs r0, #0
.L080B979E:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B97A8
sub_080B97A8: @ 0x080B97A8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	cmp r1, #0
	bne .L080B97B8
	movs r0, #1
	str r0, [r5, #0x14]
.L080B97B8:
	bl sub_080B9764
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r4, #0
	adds r2, #0x38
	movs r1, #0
	bl Map_LoadGraphicsStep
	ldr r0, [r5, #0x14]
	cmp r0, #0
	beq .L080B97D4
	movs r0, #0
	b .L080B97D6
.L080B97D4:
	movs r0, #1
.L080B97D6:
	strh r0, [r4, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B97E0
sub_080B97E0: @ 0x080B97E0
	ldr r1, .L080B97F4
	ldr r0, .L080B97F8
	str r0, [r1]
	ldr r0, .L080B97FC
	str r0, [r1, #4]
	ldr r0, .L080B9800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B97F4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B97F8: .4byte gUnknown_081C1270
.L080B97FC: .4byte 0x06003000 @ VRAM+0x3000
.L080B9800: .4byte 0x84000400

	thumb_func_start sub_080B9804
sub_080B9804: @ 0x080B9804
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080B9808
sub_080B9808: @ 0x080B9808
	push {lr}
	bl sub_080B9764
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl Map_SetGraphicsPointers
	ldr r1, .L080B9824
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9824: .4byte 0x03003BBC @ IWRAM+0x3BBC

	thumb_func_start sub_080B9828
sub_080B9828: @ 0x080B9828
	ldr r1, .L080B983C
	ldr r0, .L080B9840
	str r0, [r1]
	ldr r0, .L080B9844
	str r0, [r1, #4]
	ldr r0, .L080B9848
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B983C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B9840: .4byte gUnknown_08165614
.L080B9844: .4byte 0x06016000 @ VRAM+0x16000
.L080B9848: .4byte 0x84000400

	thumb_func_start sub_080B984C
sub_080B984C: @ 0x080B984C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080B987C
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080B9880
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080B9884
	ldrh r1, [r0]
	ldr r0, .L080B9888
	cmp r1, r0
	bne .L080B988C
	movs r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	b .L080B9890
	.byte 0x00, 0x00
.L080B987C: .4byte Field_LoadGraphicsStep
.L080B9880: .4byte sub_080B9828
.L080B9884: .4byte 0x03003BBC @ IWRAM+0x3BBC
.L080B9888: .4byte 0x0000FFFF
.L080B988C:
	movs r0, #0
	strh r0, [r4, #0x1c]
.L080B9890:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B9898
sub_080B9898: @ 0x080B9898
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080B98B0
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne .L080B98B8
	movs r0, #1
	strh r0, [r1, #0x1c]
	ldr r0, .L080B98B4
	bl sub_080AE494
	b .L080B98BC
.L080B98B0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B98B4: .4byte sub_080B0158
.L080B98B8:
	movs r0, #0
	strh r0, [r1, #0x1c]
.L080B98BC:
	pop {r0}
	bx r0

	thumb_func_start sub_080B98C0
sub_080B98C0: @ 0x080B98C0
	push {lr}
	bl sub_080C7218
	bl sub_080C7414
	bl sub_080C6FF0
	ldr r0, .L080B98D8
	bl sub_080AE494
	pop {r0}
	bx r0
.L080B98D8: .4byte sub_080B0158

	thumb_func_start sub_080B98DC
sub_080B98DC: @ 0x080B98DC
.L080B98DC:
	push {lr}
	adds r1, r0, #0
	adds r1, #0x24
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	bne .L080B98EC
	ldrh r0, [r1, #0x1c]
	b .L080B98F4
.L080B98EC:
	adds r0, r1, #0
	bl sub_080B9710
	ldrh r0, [r0]
.L080B98F4:
	pop {r1}
	bx r1

	thumb_func_start sub_080B98F8
sub_080B98F8: @ 0x080B98F8
.L080B98F8:
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	adds r5, r1, #0
	adds r5, #0x24
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	beq .L080B9948
	adds r0, r1, #0
	bl sub_080B98DC
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L080B993C
	ldrh r0, [r0]
	ldr r1, .L080B9940
	ldrh r1, [r1]
	bl sub_080C8B10
	adds r7, r0, #0
	movs r4, #0
	cmp r4, r6
	bhs .L080B994C
.L080B9924:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080B9738
	cmp r0, r7
	beq .L080B9944
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r6
	blo .L080B9924
	b .L080B994C
.L080B993C: .4byte 0x03004614 @ IWRAM+0x4614
.L080B9940: .4byte 0x03004514 @ IWRAM+0x4514
.L080B9944:
	str r4, [r5, #8]
	b .L080B994C
.L080B9948:
	ldrh r0, [r5, #0x1e]
	str r0, [r5, #8]
.L080B994C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B9954
sub_080B9954: @ 0x080B9954
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x24
	bl sub_080B98DC
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xf
	cmp r4, #0xb
	bls .L080B996C
	movs r4, #0xb
.L080B996C:
	cmp r4, #4
	bne .L080B9972
	movs r4, #5
.L080B9972:
	adds r0, r5, #0
	bl sub_080B98F8
	lsls r3, r4, #0x10
	lsrs r3, r3, #0x10
	movs r4, #1
	str r4, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #9
	bl TextWindow_Create
	str r0, [r5, #0x24]
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #8
	bl Window_Create
	str r0, [r6, #4]
	ldr r0, .L080B99AC
	strh r4, [r0, #0x30]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B99AC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080B99B0
sub_080B99B0: @ 0x080B99B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x24]
	bl TextWindow_IsDone
	cmp r0, #1
	beq .L080B99C0
	movs r0, #0
.L080B99C0:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B99C8
sub_080B99C8: @ 0x080B99C8
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, [r0, #0x24]
	movs r1, #0
	bl TextWindow_Close
	ldr r0, [r4, #4]
	movs r1, #0
	bl Window_Close
	ldr r1, .L080B99EC
	movs r0, #0
	strh r0, [r1, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B99EC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080B99F0
sub_080B99F0: @ 0x080B99F0
	push {lr}
	cmp r1, #0
	bne .L080B9A10
	ldr r0, .L080B9A0C
	ldrh r0, [r0, #2]
	bl sub_080B1A1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl sub_080B2064
	b .L080B9A1A
	.byte 0x00, 0x00
.L080B9A0C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B9A10:
	ldr r1, .L080B9A20
	ldrh r0, [r1, #6]
	ldrh r1, [r1, #8]
	bl sub_080B2064
.L080B9A1A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9A20: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B9A24
sub_080B9A24: @ 0x080B9A24
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080B2090
	movs r2, #0
	strh r2, [r4, #0x1c]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L080B9A40
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r0, .L080B9A48
	strh r2, [r0, #0x2e]
.L080B9A40:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9A48: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B9A4C
sub_080B9A4C: @ 0x080B9A4C
.L080B9A4C:
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r1, #0
	adds r4, r2, #0
	bl sub_080B98DC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xd
	adds r1, r0, #0
	muls r1, r2, r1
	adds r0, r4, #0
	muls r0, r2, r0
	adds r0, #0xa
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	adds r7, r6, #0
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge .L080B9B18
	ldrh r4, [r5, #6]
	rsbs r4, r4, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl NumberToDigits
	adds r5, r0, #0
	ldr r0, .L080B9ADC
	str r6, [sp]
	movs r7, #0xc
	str r7, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x9c
	bl Text_DrawSpriteString
	cmp r4, #9
	bls .L080B9AE8
	ldr r4, .L080B9AE0
	ldrb r0, [r5, #1]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	str r6, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0xb4
	bl FontSprite_DrawGlyph
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	str r6, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0xc0
	bl FontSprite_DrawGlyph
	ldr r0, .L080B9AE4
	str r6, [sp]
	str r7, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0xcc
	bl Text_DrawSpriteString
	b .L080B9B94
	.byte 0x00, 0x00
.L080B9ADC: .4byte gUnknown_08165674
.L080B9AE0: .4byte gUnknown_0816567E
.L080B9AE4: .4byte gUnknown_0816567A
.L080B9AE8:
	ldr r1, .L080B9B10
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	str r6, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0xb4
	bl FontSprite_DrawGlyph
	ldr r0, .L080B9B14
	str r6, [sp]
	str r7, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0xc0
	bl Text_DrawSpriteString
	b .L080B9B94
.L080B9B10: .4byte gUnknown_0816567E
.L080B9B14: .4byte gUnknown_0816567A
.L080B9B18:
	ldrh r4, [r5, #6]
	adds r0, r4, #0
	bl NumberToDigits
	adds r5, r0, #0
	cmp r4, #9
	bls .L080B9B6C
	ldr r4, .L080B9B64
	ldrb r0, [r5, #1]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	str r6, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0x9c
	bl FontSprite_DrawGlyph
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	str r6, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0xa8
	bl FontSprite_DrawGlyph
	ldr r0, .L080B9B68
	str r6, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0xb4
	bl Text_DrawSpriteString
	b .L080B9B94
.L080B9B64: .4byte gUnknown_0816567E
.L080B9B68: .4byte gUnknown_0816567A
.L080B9B6C:
	ldr r1, .L080B9B9C
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0x9c
	bl FontSprite_DrawGlyph
	ldr r0, .L080B9BA0
	str r7, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0xa8
	bl Text_DrawSpriteString
.L080B9B94:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B9B9C: .4byte gUnknown_0816567E
.L080B9BA0: .4byte gUnknown_0816567A

	thumb_func_start sub_080B9BA4
sub_080B9BA4: @ 0x080B9BA4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r7, #0
	adds r5, #0x24
	ldr r0, .L080B9BFC
	ldrh r0, [r0]
	movs r1, #0
	bl sub_080C8B10
	bl sub_080B9750
	mov r8, r0
	adds r0, r7, #0
	bl sub_080B98DC
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, [r5, #0x10]
	cmp r0, #1
	bne .L080B9C40
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	beq .L080B9C00
	movs r4, #0
	cmp r4, r6
	bhs .L080B9C2C
.L080B9BDE:
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl sub_080B9738
	adds r1, r0, #0
	adds r0, r7, #0
	adds r2, r4, #0
	bl sub_080B9A4C
	adds r4, #1
	cmp r4, r6
	blo .L080B9BDE
	b .L080B9C2C
	.byte 0x00, 0x00
.L080B9BFC: .4byte 0x03004614 @ IWRAM+0x4614
.L080B9C00:
	movs r4, #0
	ldrh r0, [r5, #0x1c]
	cmp r4, r0
	bhs .L080B9C2C
.L080B9C08:
	ldr r0, .L080B9C50
	ldrh r0, [r0]
	lsls r2, r4, #1
	adds r1, r5, #0
	adds r1, #0x20
	adds r1, r1, r2
	ldrh r1, [r1]
	bl sub_080C8B10
	adds r1, r0, #0
	adds r0, r7, #0
	adds r2, r4, #0
	bl sub_080B9A4C
	adds r4, #1
	ldrh r1, [r5, #0x1c]
	cmp r4, r1
	blo .L080B9C08
.L080B9C2C:
	ldr r0, .L080B9C54
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
.L080B9C40:
	mov r1, r8
	ldrh r0, [r1, #2]
	cmp r0, #1
	bhi .L080B9C58
	bl sub_080B2AB0
	b .L080B9C5E
	.byte 0x00, 0x00
.L080B9C50: .4byte 0x03004614 @ IWRAM+0x4614
.L080B9C54: .4byte gUnknown_08165654
.L080B9C58:
	adds r0, r7, #0
	bl sub_080BA2F0
.L080B9C5E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B9C6C
sub_080B9C6C: @ 0x080B9C6C
	movs r1, #1
	str r1, [r0, #0x34]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080B9C74
sub_080B9C74: @ 0x080B9C74
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	bl sub_080B98DC
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r5, r4, #0
	adds r5, #0x24
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r2, .L080B9C9C
	ldrh r1, [r2, #0x3a]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080B9CA0
	movs r0, #0x65
	b .L080B9CAE
.L080B9C9C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B9CA0:
	ldrh r1, [r2, #0x3a]
	movs r6, #2
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080B9CB6
	movs r0, #0x66
.L080B9CAE:
	bl sub_080C51D4
	strh r6, [r4, #0x1e]
	b .L080B9CEE
.L080B9CB6:
	ldrh r1, [r2, #0x3c]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080B9CD4
	subs r0, r7, #1
	ldr r1, [r5, #8]
	cmp r1, r0
	beq .L080B9CEE
	adds r0, r1, #1
	str r0, [r5, #8]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080B9CEE
.L080B9CD4:
	ldrh r1, [r2, #0x3c]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080B9CEE
	ldr r0, [r5, #8]
	cmp r0, #0
	beq .L080B9CEE
	subs r0, #1
	str r0, [r5, #8]
	movs r0, #0x64
	bl sub_080C51D4
.L080B9CEE:
	movs r2, #0xd
	adds r1, r7, #0
	muls r1, r2, r1
	ldr r0, [r5, #8]
	muls r0, r2, r0
	adds r0, #0xa
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	movs r0, #6
	movs r1, #0
	movs r2, #0
	movs r3, #0x9c
	bl sub_080C49EC
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B9D18
sub_080B9D18: @ 0x080B9D18
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	ldr r0, .L080B9D78
	ldr r1, .L080B9D7C
	mov r8, r1
	ldr r2, [r1]
	str r2, [r5, #0xc]
	strh r2, [r0]
	ldrh r3, [r5, #0x18]
	cmp r3, #0
	beq .L080B9D8E
	ldrh r7, [r5, #8]
	adds r0, r6, #0
	bl sub_080B98F8
	ldr r0, [r5, #8]
	cmp r7, r0
	beq .L080B9D88
	adds r0, r5, #0
	adds r1, r7, #0
	bl sub_080B9720
	ldr r4, .L080B9D80
	ldrh r1, [r0]
	str r1, [r4]
	ldrh r0, [r0, #2]
	mov r1, r8
	str r0, [r1]
	bl sub_080AE234
	bl sub_080AE294
	ldrh r0, [r4]
	ldr r1, .L080B9D84
	ldr r1, [r1]
	ldrh r2, [r1, #4]
	movs r1, #3
	bl sub_080B31C4
	ldr r0, [r5, #8]
	str r0, [r5, #0xc]
	str r7, [r5, #8]
	b .L080B9DBA
	.byte 0x00, 0x00
.L080B9D78: .4byte 0x03004634 @ IWRAM+0x4634
.L080B9D7C: .4byte 0x03004514 @ IWRAM+0x4514
.L080B9D80: .4byte 0x03004614 @ IWRAM+0x4614
.L080B9D84: .4byte 0x03004000 @ IWRAM+0x4000
.L080B9D88:
	movs r0, #0
	strh r0, [r6, #0x1c]
	b .L080B9DCA
.L080B9D8E:
	ldr r1, [r5, #8]
	lsls r1, r1, #1
	adds r0, r6, #0
	adds r0, #0x44
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r2, r0
	beq .L080B9DC8
	mov r1, r8
	str r0, [r1]
	bl sub_080AE234
	bl sub_080AE294
	ldr r0, .L080B9DC0
	ldrh r0, [r0]
	ldr r1, .L080B9DC4
	ldr r1, [r1]
	ldrh r2, [r1, #4]
	movs r1, #3
	bl sub_080B31C4
.L080B9DBA:
	movs r0, #1
	strh r0, [r6, #0x1c]
	b .L080B9DCA
.L080B9DC0: .4byte 0x03004614 @ IWRAM+0x4614
.L080B9DC4: .4byte 0x03004000 @ IWRAM+0x4000
.L080B9DC8:
	strh r3, [r6, #0x1c]
.L080B9DCA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080B9DD4
sub_080B9DD4: @ 0x080B9DD4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r5, #0
	adds r3, #0x24
	ldrh r0, [r3, #0x18]
	cmp r0, #0
	beq .L080B9E08
	ldrh r1, [r3, #8]
	adds r0, r3, #0
	bl sub_080B9738
	adds r4, r0, #0
	ldr r0, .L080B9E00
	ldrh r0, [r0]
	ldr r1, .L080B9E04
	ldrh r1, [r1]
	bl sub_080C8B10
	cmp r4, r0
	bne .L080B9E24
	movs r0, #1
	b .L080B9E3E
.L080B9E00: .4byte 0x03004614 @ IWRAM+0x4614
.L080B9E04: .4byte 0x03004514 @ IWRAM+0x4514
.L080B9E08:
	ldr r2, .L080B9E20
	ldr r0, [r3, #8]
	lsls r0, r0, #1
	adds r1, r5, #0
	adds r1, #0x44
	adds r1, r1, r0
	ldr r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	bne .L080B9E24
	movs r0, #1
	b .L080B9E3E
.L080B9E20: .4byte 0x03004514 @ IWRAM+0x4514
.L080B9E24:
	movs r0, #2
	rsbs r0, r0, #0
	bl sub_080B343C
	ldr r0, .L080B9E38
	ldrh r0, [r0, #0x2e]
	cmp r0, #0
	bne .L080B9E3C
	movs r0, #1
	b .L080B9E3E
.L080B9E38: .4byte 0x03004550 @ IWRAM+0x4550
.L080B9E3C:
	movs r0, #0
.L080B9E3E:
	strh r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B9E48
sub_080B9E48: @ 0x080B9E48
	push {r4, r5, lr}
	adds r4, r1, #0
	bl sub_080C7234
	bl sub_080C7430
	bl sub_080C700C
	ldr r5, .L080B9E74
	ldrh r0, [r5, #0xa]
	ldrh r1, [r5, #2]
	movs r2, #3
	bl sub_080B2030
	cmp r4, #1
	bne .L080B9E6C
	movs r0, #0x21
	strh r0, [r5, #0x2e]
.L080B9E6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9E74: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B9E78
sub_080B9E78: @ 0x080B9E78
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r5, #0
	adds r4, #0x24
	bl sub_080B9764
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5a
	bne .L080B9EFC
	cmp r6, #0
	bne .L080B9F3E
	ldr r1, .L080B9EB8
	ldrh r0, [r1, #0x12]
	ldrh r1, [r1, #0x14]
	mov r5, sp
	adds r5, #0xe
	add r2, sp, #0xc
	adds r3, r5, #0
	bl sub_080C1F50
	add r0, sp, #0xc
	ldrh r0, [r0]
	cmp r0, #0x40
	bne .L080B9EC0
	ldrh r0, [r5]
	cmp r0, #0xc
	bne .L080B9EC0
	ldr r0, .L080B9EBC
	b .L080B9EDE
.L080B9EB8: .4byte 0x03004550 @ IWRAM+0x4550
.L080B9EBC: .4byte gUnknown_08002CBC
.L080B9EC0:
	ldr r0, [r4, #8]
	lsls r0, r0, #1
	adds r1, r4, #0
	adds r1, #0x20
	adds r1, r1, r0
	ldr r0, [r4, #0xc]
	ldrh r1, [r1]
	cmp r0, r1
	bhs .L080B9EDC
	ldr r0, .L080B9ED8
	b .L080B9EDE
	.byte 0x00, 0x00
.L080B9ED8: .4byte gUnknown_08002CBC
.L080B9EDC:
	ldr r0, .L080B9EF8
.L080B9EDE:
	movs r1, #0xc0
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0x64
	str r1, [sp, #4]
	movs r1, #8
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	b .L080B9F3E
.L080B9EF8: .4byte gUnknown_08002CCC
.L080B9EFC:
	ldr r7, .L080B9F24
	ldr r3, .L080B9F28
	ldr r0, [r4, #8]
	lsls r0, r0, #1
	adds r1, r5, #0
	adds r1, #0x44
	adds r1, r1, r0
	ldr r0, [r4, #0xc]
	movs r2, #0xde
	ldrh r1, [r1]
	cmp r0, r1
	bhs .L080B9F16
	movs r2, #0xd7
.L080B9F16:
	cmp r6, #0
	bne .L080B9F2C
	lsls r0, r2, #1
	adds r0, r0, r3
	movs r1, #0x1f
	strh r1, [r0]
	b .L080B9F3A
.L080B9F24: .4byte gUnknown_084C0D50
.L080B9F28: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080B9F2C:
	lsls r0, r2, #1
	adds r1, r0, r3
	adds r0, r0, r7
	ldr r2, .L080B9F48
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
.L080B9F3A:
	bl Palette_MarkDirty
.L080B9F3E:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B9F48: .4byte 0xFFFFFE80

	thumb_func_start sub_080B9F4C
sub_080B9F4C: @ 0x080B9F4C
	push {lr}
	adds r2, r1, #0
	adds r0, #0x24
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	cmp r1, r0
	bhs .L080B9F68
	ldr r1, .L080B9F64
	ldrh r0, [r1]
	subs r0, r0, r2
	b .L080B9F6E
	.byte 0x00, 0x00
.L080B9F64: .4byte 0x0300000E @ IWRAM+0xE
.L080B9F68:
	ldr r1, .L080B9F74
	ldrh r0, [r1]
	adds r0, r0, r2
.L080B9F6E:
	strh r0, [r1]
	pop {r0}
	bx r0
.L080B9F74: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080B9F78
sub_080B9F78: @ 0x080B9F78
.L080B9F78:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp]
	ldr r7, .L080B9FC8
	ldrh r0, [r7]
	mov sl, r0
	ldr r6, .L080B9FCC
	ldrh r1, [r6, #0x12]
	str r1, [sp, #4]
	ldrh r2, [r6, #0x14]
	str r2, [sp, #8]
	ldr r0, .L080B9FD0
	ldrh r0, [r0]
	bl sub_080C8B3C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [r7]
	strh r0, [r6, #0x12]
	strh r0, [r6, #0x14]
	movs r5, #0
	ldr r0, [sp, #0xc]
	cmp r5, r0
	bhs .L080BA03E
	mov r8, r7
.L080B9FB8:
	bl sub_080AE234
	movs r6, #0
	ldr r0, .L080B9FCC
	adds r5, #1
	mov sb, r5
	b .L080BA028
	.byte 0x00, 0x00
.L080B9FC8: .4byte 0x03004514 @ IWRAM+0x4514
.L080B9FCC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B9FD0: .4byte 0x03004614 @ IWRAM+0x4614
.L080B9FD4:
	movs r5, #0
	adds r7, r6, #1
	b .L080BA01C
.L080B9FDA:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FieldMap_CellRecordsOffset
	movs r1, #3
	bl FieldMap_FindRecord
	cmp r0, #0
	beq .L080BA014
	ldrh r0, [r0, #4]
	ldr r2, [sp]
	ldrh r2, [r2, #4]
	cmp r0, r2
	bne .L080BA014
	ldrh r0, [r4, #0x1c]
	lsls r0, r0, #1
	adds r1, r4, #0
	adds r1, #0x20
	adds r1, r1, r0
	mov r2, r8
	ldr r0, [r2]
	strh r0, [r1]
	cmp sl, r0
	bne .L080BA00E
	ldrh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
.L080BA00E:
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
.L080BA014:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L080BA068
.L080BA01C:
	ldrh r0, [r0, #0x1a]
	cmp r5, r0
	blo .L080B9FDA
	lsls r0, r7, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L080BA068
.L080BA028:
	ldrh r1, [r0, #0x1c]
	cmp r6, r1
	blo .L080B9FD4
	mov r2, r8
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	mov r5, sb
	ldr r0, [sp, #0xc]
	cmp r5, r0
	blo .L080B9FB8
.L080BA03E:
	ldr r0, .L080BA06C
	mov r1, sl
	str r1, [r0]
	ldr r0, .L080BA068
	mov r2, sp
	ldrh r2, [r2, #4]
	strh r2, [r0, #0x12]
	mov r1, sp
	ldrh r1, [r1, #8]
	strh r1, [r0, #0x14]
	bl sub_080AE234
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BA068: .4byte 0x03004550 @ IWRAM+0x4550
.L080BA06C: .4byte 0x03004514 @ IWRAM+0x4514

	thumb_func_start sub_080BA070
sub_080BA070: @ 0x080BA070
.L080BA070:
	push {r4, lr}
	bl sub_080B9750
	adds r4, r0, #0
	ldrh r0, [r4, #2]
	cmp r0, #1
	bhi .L080BA088
	ldr r0, .L080BA084
	b .L080BA08A
	.byte 0x00, 0x00
.L080BA084: .4byte gUnknown_08165694
.L080BA088:
	ldr r0, .L080BA0C0
.L080BA08A:
	ldr r1, .L080BA0C4
	bl Task_Create
	ldr r1, .L080BA0C8
	str r0, [r1]
	ldr r0, .L080BA0C8
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x24
	ldrh r0, [r4, #2]
	cmp r0, #2
	bne .L080BA0AC
	movs r0, #0
	strh r0, [r2, #0x30]
	movs r0, #0x80
	lsls r0, r0, #8
	strh r0, [r2, #0x32]
.L080BA0AC:
	ldrh r0, [r4, #4]
	cmp r0, #0x7f
	bls .L080BA0CC
	movs r0, #1
	strh r0, [r2, #0x18]
	ldrh r1, [r4, #4]
	movs r0, #0x7f
	ands r0, r1
	strh r0, [r2, #0x1a]
	b .L080BA0D4
.L080BA0C0: .4byte gUnknown_08173594
.L080BA0C4: .4byte 0x0000FFFF
.L080BA0C8: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080BA0CC:
	adds r0, r2, #0
	adds r1, r4, #0
	bl sub_080B9F78
.L080BA0D4:
	movs r0, #0x1a
	bl Field_SetState
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080BA0E0
sub_080BA0E0: @ 0x080BA0E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, .L080BA150
	lsls r6, r5, #2
	lsls r0, r4, #4
	adds r0, r6, r0
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq .L080BA106
	lsls r1, r5, #0xc
	ldr r0, .L080BA154
	adds r1, r1, r0
	adds r0, r2, #0
	bl LZ77UnCompWram
.L080BA106:
	ldr r0, .L080BA158
	mov r8, r0
	lsls r7, r4, #2
	adds r0, r7, r4
	lsls r4, r0, #2
	adds r0, r6, r4
	add r0, r8
	ldr r2, [r0]
	cmp r2, #0
	beq .L080BA126
	lsls r1, r5, #0xc
	ldr r0, .L080BA15C
	adds r1, r1, r0
	adds r0, r2, #0
	bl LZ77UnCompWram
.L080BA126:
	cmp r5, #3
	bne .L080BA144
	ldr r1, .L080BA160
	mov r0, r8
	adds r0, #0x10
	adds r0, r4, r0
	ldr r0, [r0]
	strh r0, [r1]
	ldr r0, .L080BA164
	adds r0, r7, r0
	ldr r0, [r0]
	ldr r1, .L080BA168
	ldr r2, .L080BA16C
	bl CpuSet
.L080BA144:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BA150: .4byte gUnknown_08173488
.L080BA154: .4byte 0x02001000 @ EWRAM+0x1000
.L080BA158: .4byte gUnknown_081734E8
.L080BA15C: .4byte 0x02005000 @ EWRAM+0x5000
.L080BA160: .4byte 0x0300000E @ IWRAM+0xE
.L080BA164: .4byte gUnknown_08173560
.L080BA168: .4byte 0x02000000 @ EWRAM
.L080BA16C: .4byte 0x04000400

	thumb_func_start sub_080BA170
sub_080BA170: @ 0x080BA170
	ldr r1, .L080BA190
	ldr r0, .L080BA194
	str r0, [r1]
	ldr r0, .L080BA198
	str r0, [r1, #4]
	ldr r0, .L080BA19C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080BA1A0
	str r0, [r1]
	ldr r0, .L080BA1A4
	str r0, [r1, #4]
	ldr r0, .L080BA1A8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L080BA190: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BA194: .4byte 0x02005000 @ EWRAM+0x5000
.L080BA198: .4byte 0x06004000 @ VRAM+0x4000
.L080BA19C: .4byte 0x84000D00
.L080BA1A0: .4byte 0x02000000 @ EWRAM
.L080BA1A4: .4byte 0x06003000 @ VRAM+0x3000
.L080BA1A8: .4byte 0x84000400
