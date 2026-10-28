	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080BF908
sub_080BF908: @ 0x080BF908
.L080BF908:
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L080BF932
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl Equipment_GetRecord36_MidRange
	ldrh r1, [r4]
	ldrb r2, [r0, #1]
	adds r1, r1, r2
	strh r1, [r4]
	ldrh r1, [r5]
	ldrb r0, [r0, #2]
	adds r1, r1, r0
	strh r1, [r5]
.L080BF932:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080BF938
sub_080BF938: @ 0x080BF938
.L080BF938:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r1, .L080BF9BC
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r5, r0, #0
	adds r0, #0x20
	adds r4, r5, #0
	adds r4, #0x30
	adds r1, r4, #0
	bl sub_080BFDC4
	adds r0, r5, #0
	bl sub_080BFEA8
	adds r0, r5, #0
	bl sub_080BFF0C
	ldrb r0, [r5, #0xc]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #4
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	mov sb, r1
	mov r2, sb
	str r2, [sp]
	mov r3, sb
	str r3, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	mov sl, sb
	cmp r0, #0
	beq .L080BF9C0
	movs r1, #0x28
	str r1, [sp, #0xc]
	adds r2, r5, #0
	adds r2, #0x40
	str r2, [sp, #0x10]
	adds r3, r5, #0
	adds r3, #0x41
	str r3, [sp, #0x14]
	adds r4, #0x12
	str r4, [sp, #0x18]
	adds r0, r5, #0
	adds r0, #0x43
	str r0, [sp, #0x1c]
	adds r1, r5, #0
	adds r1, #0x44
	str r1, [sp, #0x20]
	movs r2, #0x45
	adds r2, r2, r5
	mov r8, r2
	b .L080BFAE2
	.byte 0x00, 0x00
.L080BF9BC: .4byte 0xFFFF8000
.L080BF9C0:
	adds r0, r5, #0
	adds r0, #0x28
	ldrb r0, [r0]
	ldrb r1, [r4]
	adds r2, r5, #0
	adds r2, #0x38
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	str r2, [sp]
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x31
	ldrb r1, [r1]
	adds r2, r5, #0
	adds r2, #0x39
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r2, r2, r0
	mov sb, r2
	adds r0, r5, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x32
	ldrb r1, [r1]
	adds r2, r5, #0
	adds r2, #0x3a
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	str r2, [sp, #4]
	adds r0, r5, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x33
	ldrb r1, [r1]
	adds r2, r5, #0
	adds r2, #0x3b
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	str r2, [sp, #8]
	adds r0, r5, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	adds r0, #8
	ldrb r0, [r0]
	adds r2, r5, #0
	adds r2, #0x3c
	adds r1, r1, r0
	ldrb r2, [r2]
	adds r2, r1, r2
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x35
	ldrb r1, [r1]
	adds r2, r5, #0
	adds r2, #0x3d
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r2, r2, r0
	mov sl, r2
	ldrb r0, [r5, #0xc]
	adds r3, r5, #0
	adds r3, #0x40
	str r3, [sp, #0x10]
	adds r4, r5, #0
	adds r4, #0x41
	str r4, [sp, #0x14]
	adds r1, r5, #0
	adds r1, #0x42
	str r1, [sp, #0x18]
	adds r2, r5, #0
	adds r2, #0x43
	str r2, [sp, #0x1c]
	adds r3, #4
	str r3, [sp, #0x20]
	movs r4, #0x45
	adds r4, r4, r5
	mov r8, r4
	cmp r0, #0
	bne .L080BFAE2
	movs r6, #0
	ldr r0, .L080BFC88
	movs r7, #0xf
	adds r4, r0, #1
.L080BFA7A:
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r6, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls .L080BFADA
	ldrb r1, [r4]
	lsrs r0, r1, #4
	ldr r2, [sp]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ands r1, r7
	add r1, sb
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	ldrb r1, [r4, #1]
	lsrs r0, r1, #4
	ldr r3, [sp, #4]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ands r1, r7
	ldr r0, [sp, #8]
	adds r1, r0, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	ldrb r1, [r4, #2]
	lsrs r0, r1, #4
	ldr r2, [sp, #0xc]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	ands r1, r7
	add r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
.L080BFADA:
	adds r4, #4
	adds r6, #1
	cmp r6, #0xb
	bls .L080BFA7A
.L080BFAE2:
	movs r1, #0
	mov r3, sp
	ldrb r4, [r3]
	ldr r3, [sp, #0x10]
	strb r4, [r3]
	mov r2, sb
	ldr r0, [sp, #0x14]
	strb r2, [r0]
	mov r3, sp
	ldrb r4, [r3, #4]
	ldr r3, [sp, #0x18]
	strb r4, [r3]
	mov r0, sp
	ldrb r2, [r0, #8]
	ldr r0, [sp, #0x1c]
	strb r2, [r0]
	mov r3, sp
	ldrb r4, [r3, #0xc]
	ldr r3, [sp, #0x20]
	strb r4, [r3]
	mov r2, sl
	mov r0, r8
	strb r2, [r0]
	ldrb r0, [r5, #0xc]
	cmp r0, #3
	bls .L080BFB18
	b .L080BFD02
.L080BFB18:
	adds r6, r5, #0
	adds r6, #0x4a
	strh r1, [r6]
	adds r4, r5, #0
	adds r4, #0x48
	strh r1, [r4]
	adds r2, r5, #0
	adds r2, #0x20
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L080BFB66
	adds r0, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF32C
	adds r2, r0, #0
	ldrb r1, [r2, #1]
	ldr r3, [sp]
	adds r1, r3, r1
	strh r1, [r4]
	ldrb r0, [r5, #0xd]
	lsrs r0, r0, #1
	adds r1, r1, r0
	strh r1, [r4]
	adds r0, r3, #0
	add r0, sl
	asrs r0, r0, #2
	ldr r4, [sp, #0xc]
	adds r0, r4, r0
	ldrb r2, [r2, #2]
	adds r0, r0, r2
	strh r0, [r6]
	ldrb r1, [r5, #0xd]
	adds r0, r0, r1
	strh r0, [r6]
.L080BFB66:
	movs r0, #0x4e
	adds r0, r0, r5
	mov r8, r0
	movs r0, #0
	mov r1, r8
	strh r0, [r1]
	adds r6, r5, #0
	adds r6, #0x4c
	strh r0, [r6]
	adds r1, r5, #0
	adds r1, #0x21
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, r2
	beq .L080BFBE2
	adds r7, r5, #0
	adds r7, #0x26
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, r2
	beq .L080BFBE2
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF32C
	adds r4, r0, #0
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF32C
	ldrb r2, [r4, #1]
	strh r2, [r6]
	ldrb r1, [r0, #1]
	adds r2, r2, r1
	strh r2, [r6]
	ldrb r1, [r5, #0xd]
	lsrs r1, r1, #1
	adds r2, r2, r1
	strh r2, [r6]
	ldrb r1, [r4, #2]
	mov r2, r8
	strh r1, [r2]
	ldrb r0, [r0, #2]
	adds r1, r1, r0
	strh r1, [r2]
	ldr r0, [sp]
	add r0, sl
	asrs r0, r0, #2
	ldr r3, [sp, #0xc]
	adds r0, r3, r0
	adds r0, r1, r0
	mov r4, r8
	strh r0, [r4]
	ldrb r1, [r5, #0xd]
	adds r0, r0, r1
	strh r0, [r4]
.L080BFBE2:
	adds r4, r5, #0
	adds r4, #0x50
	movs r0, #0
	strh r0, [r4]
	adds r6, r5, #0
	adds r6, #0x52
	strh r0, [r6]
	adds r0, r5, #0
	adds r0, #0x22
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r4, #0
	adds r2, r6, #0
	bl sub_080BF908
	adds r0, r5, #0
	adds r0, #0x23
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r4, #0
	adds r2, r6, #0
	bl sub_080BF908
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r4, #0
	adds r2, r6, #0
	bl sub_080BF908
	adds r0, r5, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r4, #0
	adds r2, r6, #0
	bl sub_080BF908
	ldr r0, [sp, #0xc]
	ldr r2, [sp, #8]
	adds r1, r0, r2
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	ldrb r0, [r5, #0xd]
	lsrs r0, r0, #2
	adds r0, r0, r1
	ldrh r3, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	mov r0, sb
	add r0, sl
	asrs r1, r0, #2
	ldr r4, [sp, #0xc]
	adds r1, r4, r1
	ldrb r0, [r5, #0xd]
	adds r1, r1, r0
	ldrh r0, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	ldrb r2, [r5, #0xc]
	cmp r2, #0
	bne .L080BFC8C
	ldrb r0, [r5, #0xd]
	adds r0, #1
	ldr r3, [sp]
	ldr r4, [sp, #8]
	adds r1, r3, r4
	muls r0, r1, r0
	cmp r0, #0
	bge .L080BFC7C
	adds r0, #3
.L080BFC7C:
	asrs r0, r0, #2
	adds r0, #0xe
	strh r0, [r5, #0x1a]
	strh r2, [r5, #0x1e]
	b .L080BFCB8
	.byte 0x00, 0x00
.L080BFC88: .4byte gUnknown_081A6ED4
.L080BFC8C:
	ldr r0, [sp]
	ldr r2, [sp, #8]
	adds r1, r0, r2
	ldrb r0, [r5, #0xd]
	adds r0, #1
	muls r0, r1, r0
	movs r1, #5
	bl __divsi3
	adds r0, #0xa
	strh r0, [r5, #0x1a]
	ldrb r0, [r5, #0xd]
	adds r0, #4
	ldr r1, [sp, #4]
	add r1, sb
	muls r0, r1, r0
	cmp r0, #0
	bge .L080BFCB2
	adds r0, #7
.L080BFCB2:
	asrs r0, r0, #3
	adds r0, #4
	strh r0, [r5, #0x1e]
.L080BFCB8:
	movs r3, #0x1a
	ldrsh r0, [r5, r3]
	ldr r1, .L080BFD14
	cmp r0, r1
	ble .L080BFCC6
	ldr r0, .L080BFD18
	strh r0, [r5, #0x1a]
.L080BFCC6:
	movs r4, #0x1e
	ldrsh r0, [r5, r4]
	cmp r0, r1
	ble .L080BFCD2
	ldr r0, .L080BFD18
	strh r0, [r5, #0x1e]
.L080BFCD2:
	movs r2, #0x18
	ldrsh r0, [r5, r2]
	cmp r0, r1
	ble .L080BFCDE
	ldr r0, .L080BFD18
	strh r0, [r5, #0x18]
.L080BFCDE:
	movs r3, #0x1c
	ldrsh r0, [r5, r3]
	cmp r0, r1
	ble .L080BFCEA
	ldr r0, .L080BFD18
	strh r0, [r5, #0x1c]
.L080BFCEA:
	mov r4, sb
	lsrs r0, r4, #2
	ldr r1, [sp, #4]
	adds r0, r1, r0
	adds r1, r5, #0
	adds r1, #0x54
	strh r0, [r1]
	ldr r2, [sp, #4]
	lsrs r0, r2, #2
	add r0, sb
	adds r1, #2
	strh r0, [r1]
.L080BFD02:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BFD14: .4byte 0x000003E6
.L080BFD18: .4byte 0x000003E7

	thumb_func_start sub_080BFD1C
sub_080BFD1C: @ 0x080BFD1C
.L080BFD1C:
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080BFD90
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r3, r0, #0
	cmp r4, #1
	bne .L080BFD8A
	adds r2, r3, #0
	adds r2, #0x4a
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	cmp r0, #0
	bge .L080BFD44
	adds r0, #7
.L080BFD44:
	asrs r0, r0, #3
	strh r0, [r2]
	adds r2, r3, #0
	adds r2, #0x4e
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	cmp r0, #0
	bge .L080BFD5A
	adds r0, #7
.L080BFD5A:
	asrs r0, r0, #3
	strh r0, [r2]
	adds r2, r3, #0
	adds r2, #0x50
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	cmp r0, #0
	bge .L080BFD70
	adds r0, #7
.L080BFD70:
	asrs r0, r0, #3
	strh r0, [r2]
	adds r2, r3, #0
	adds r2, #0x52
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	cmp r0, #0
	bge .L080BFD86
	adds r0, #7
.L080BFD86:
	asrs r0, r0, #3
	strh r0, [r2]
.L080BFD8A:
	pop {r4}
	pop {r0}
	bx r0
.L080BFD90: .4byte 0xFFFF8000

	thumb_func_start sub_080BFD94
sub_080BFD94: @ 0x080BFD94
.L080BFD94:
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080BFDC0
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, r4, #0
	bl sub_080BF938
	adds r0, r4, #0
	bl sub_080BFFF0
	adds r1, r0, #0
	adds r0, r4, #0
	bl sub_080BFD1C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BFDC0: .4byte 0xFFFF8000

	thumb_func_start sub_080BFDC4
sub_080BFDC4: @ 0x080BFDC4
.L080BFDC4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r7, r1, #0
	add r2, sp, #0x10
	movs r1, #0
	strh r1, [r2]
	ldr r1, .L080BFE7C
	str r2, [r1]
	str r7, [r1, #4]
	ldr r2, .L080BFE80
	str r2, [r1, #8]
	ldr r1, [r1, #8]
	mov r2, sp
	movs r1, #0
	ldrsb r1, [r0, r1]
	strh r1, [r2]
	movs r1, #2
	.2byte 0x4469 @ add r1, sp, r1
	mov r8, r1
	movs r1, #1
	ldrsb r1, [r0, r1]
	mov r2, r8
	strh r1, [r2]
	add r6, sp, #4
	movs r1, #2
	ldrsb r1, [r0, r1]
	strh r1, [r6]
	mov r5, sp
	adds r5, #6
	movs r1, #3
	ldrsb r1, [r0, r1]
	strh r1, [r5]
	add r4, sp, #8
	movs r1, #4
	ldrsb r1, [r0, r1]
	strh r1, [r4]
	mov r3, sp
	adds r3, #0xa
	movs r1, #5
	ldrsb r1, [r0, r1]
	strh r1, [r3]
	add r2, sp, #0xc
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r2]
	mov r1, sp
	mov r0, sp
	ldrb r0, [r0]
	strh r0, [r1]
	mov r1, r8
	ldrb r0, [r1]
	strh r0, [r1]
	ldrb r0, [r6]
	strh r0, [r6]
	ldrb r0, [r5]
	strh r0, [r5]
	ldrb r0, [r4]
	strh r0, [r4]
	ldrb r0, [r3]
	strh r0, [r3]
	ldrb r0, [r2]
	strh r0, [r2]
	add r5, sp, #0x14
	mov r4, sp
	movs r6, #6
.L080BFE4C:
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0xff
	beq .L080BFE66
	movs r1, #5
	adds r2, r5, #0
	bl sub_080BF468
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl sub_080BFF8C
.L080BFE66:
	adds r4, #2
	subs r6, #1
	cmp r6, #0
	bge .L080BFE4C
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BFE7C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BFE80: .4byte 0x81000004

	thumb_func_start sub_080BFE84
sub_080BFE84: @ 0x080BFE84
.L080BFE84:
	push {lr}
	adds r0, r0, r1
	subs r0, #0x46
	cmp r0, #0
	ble .L080BFE90
	subs r1, r1, r0
.L080BFE90:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080BFE98
sub_080BFE98: @ 0x080BFE98
.L080BFE98:
	push {lr}
	adds r0, r0, r1
	adds r0, r0, r2
	subs r0, #0x46
	adds r0, r2, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080BFEA8
sub_080BFEA8: @ 0x080BFEA8
.L080BFEA8:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x28
	adds r4, #0x30
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl sub_080BFE84
	strb r0, [r4]
	movs r0, #1
	ldrsb r0, [r5, r0]
	movs r1, #1
	ldrsb r1, [r4, r1]
	bl sub_080BFE84
	strb r0, [r4, #1]
	movs r0, #2
	ldrsb r0, [r5, r0]
	movs r1, #2
	ldrsb r1, [r4, r1]
	bl sub_080BFE84
	strb r0, [r4, #2]
	movs r0, #3
	ldrsb r0, [r5, r0]
	movs r1, #3
	ldrsb r1, [r4, r1]
	bl sub_080BFE84
	strb r0, [r4, #3]
	movs r0, #4
	ldrsb r0, [r5, r0]
	movs r1, #4
	ldrsb r1, [r4, r1]
	bl sub_080BFE84
	strb r0, [r4, #4]
	movs r0, #5
	ldrsb r0, [r5, r0]
	movs r1, #5
	ldrsb r1, [r4, r1]
	bl sub_080BFE84
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080BFF0C
sub_080BFF0C: @ 0x080BFF0C
.L080BFF0C:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r5, #0x28
	adds r6, r0, #0
	adds r6, #0x30
	adds r4, r0, #0
	adds r4, #0x38
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #0
	ldrsb r1, [r6, r1]
	movs r2, #0
	ldrsb r2, [r4, r2]
	bl sub_080BFE98
	strb r0, [r4]
	movs r0, #1
	ldrsb r0, [r5, r0]
	movs r1, #1
	ldrsb r1, [r6, r1]
	movs r2, #1
	ldrsb r2, [r4, r2]
	bl sub_080BFE98
	strb r0, [r4, #1]
	movs r0, #2
	ldrsb r0, [r5, r0]
	movs r1, #2
	ldrsb r1, [r6, r1]
	movs r2, #2
	ldrsb r2, [r4, r2]
	bl sub_080BFE98
	strb r0, [r4, #2]
	movs r0, #3
	ldrsb r0, [r5, r0]
	movs r1, #3
	ldrsb r1, [r6, r1]
	movs r2, #3
	ldrsb r2, [r4, r2]
	bl sub_080BFE98
	strb r0, [r4, #3]
	movs r0, #4
	ldrsb r0, [r5, r0]
	movs r1, #4
	ldrsb r1, [r6, r1]
	movs r2, #4
	ldrsb r2, [r4, r2]
	bl sub_080BFE98
	strb r0, [r4, #4]
	movs r0, #5
	ldrsb r0, [r5, r0]
	movs r1, #5
	ldrsb r1, [r6, r1]
	movs r2, #5
	ldrsb r2, [r4, r2]
	bl sub_080BFE98
	strb r0, [r4, #5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080BFF8C
sub_080BFF8C: @ 0x080BFF8C
.L080BFF8C:
	push {r4, lr}
	ldrb r3, [r1]
	ldrb r4, [r0]
	adds r3, r3, r4
	strb r3, [r2]
	ldrb r3, [r1, #1]
	ldrb r4, [r0, #1]
	adds r3, r3, r4
	strb r3, [r2, #1]
	ldrb r3, [r1, #2]
	ldrb r4, [r0, #2]
	adds r3, r3, r4
	strb r3, [r2, #2]
	ldrb r3, [r1, #3]
	ldrb r4, [r0, #3]
	adds r3, r3, r4
	strb r3, [r2, #3]
	ldrb r3, [r1, #4]
	ldrb r4, [r0, #4]
	adds r3, r3, r4
	strb r3, [r2, #4]
	ldrb r1, [r1, #5]
	ldrb r0, [r0, #5]
	adds r1, r1, r0
	strb r1, [r2, #5]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080BFFC4
sub_080BFFC4: @ 0x080BFFC4
.L080BFFC4:
	push {lr}
	adds r2, r0, #0
	movs r1, #0
	ldr r3, .L080BFFDC
.L080BFFCC:
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	bne .L080BFFE0
	adds r0, r1, #0
	b .L080BFFEA
.L080BFFDC: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080BFFE0:
	adds r1, #1
	cmp r1, #5
	ble .L080BFFCC
	movs r0, #1
	rsbs r0, r0, #0
.L080BFFEA:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080BFFF0
sub_080BFFF0: @ 0x080BFFF0
.L080BFFF0:
	push {lr}
	bl sub_080BFFC4
	cmp r0, #0
	bge .L080C0000
	movs r0, #1
	rsbs r0, r0, #0
	b .L080C000A
.L080C0000:
	cmp r0, #2
	bgt .L080C0008
	movs r0, #0
	b .L080C000A
.L080C0008:
	movs r0, #1
.L080C000A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C0010
sub_080C0010: @ 0x080C0010
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	strb r0, [r1, #3]
	strb r0, [r1, #4]
	strb r0, [r1, #5]
	strb r0, [r1, #6]
	strb r0, [r1, #7]
	adds r6, r1, #0
	movs r7, #0
	movs r5, #0
.L080C0036:
	mov r0, r8
	adds r1, r5, #0
	bl sub_080C00DC
	adds r4, r0, #0
	cmp r4, #0xff
	beq .L080C005E
	cmp r5, #6
	beq .L080C005E
	movs r1, #6
	mov r2, sp
	bl sub_080BF468
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080C005E
	strh r4, [r6]
	movs r7, #1
.L080C005E:
	adds r6, #2
	adds r5, #1
	cmp r5, #6
	bls .L080C0036
	adds r0, r7, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080C0074
sub_080C0074: @ 0x080C0074
.L080C0074:
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r1, .L080C0098
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	adds r2, #0x20
	cmp r5, #6
	bhi .L080C00D6
	lsls r0, r5, #2
	ldr r1, .L080C009C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080C0098: .4byte 0xFFFF8000
.L080C009C: .4byte gUnknown_080C00A0
	.global gUnknown_080C00A0
gUnknown_080C00A0:
.L080C00A0: @ jump table
	.4byte .L080C00BC
	.4byte .L080C00C0
	.4byte .L080C00C4
	.4byte .L080C00C8
	.4byte .L080C00CC
	.4byte .L080C00D0
	.4byte .L080C00D4
.L080C00BC:
	strb r4, [r2]
	b .L080C00D6
.L080C00C0:
	strb r4, [r2, #1]
	b .L080C00D6
.L080C00C4:
	strb r4, [r2, #2]
	b .L080C00D6
.L080C00C8:
	strb r4, [r2, #3]
	b .L080C00D6
.L080C00CC:
	strb r4, [r2, #4]
	b .L080C00D6
.L080C00D0:
	strb r4, [r2, #5]
	b .L080C00D6
.L080C00D4:
	strb r4, [r2, #6]
.L080C00D6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080C00DC
sub_080C00DC: @ 0x080C00DC
.L080C00DC:
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080C0100
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	adds r2, #0x20
	cmp r4, #6
	bhi .L080C0140
	lsls r0, r4, #2
	ldr r1, .L080C0104
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080C0100: .4byte 0xFFFF8000
.L080C0104: .4byte gUnknown_080C0108
	.global gUnknown_080C0108
gUnknown_080C0108:
.L080C0108: @ jump table
	.4byte .L080C0124
	.4byte .L080C0128
	.4byte .L080C012C
	.4byte .L080C0130
	.4byte .L080C0134
	.4byte .L080C0138
	.4byte .L080C013C
.L080C0124:
	ldrb r0, [r2]
	b .L080C0142
.L080C0128:
	ldrb r0, [r2, #1]
	b .L080C0142
.L080C012C:
	ldrb r0, [r2, #2]
	b .L080C0142
.L080C0130:
	ldrb r0, [r2, #3]
	b .L080C0142
.L080C0134:
	ldrb r0, [r2, #4]
	b .L080C0142
.L080C0138:
	ldrb r0, [r2, #5]
	b .L080C0142
.L080C013C:
	ldrb r0, [r2, #6]
	b .L080C0142
.L080C0140:
	movs r0, #0
.L080C0142:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C0148
sub_080C0148: @ 0x080C0148
.L080C0148:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L080C0182
	ldr r3, .L080C0174
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r0, r3, r2
	adds r2, r1, r0
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080C0178
	movs r0, #0
	b .L080C018C
	.byte 0x00, 0x00
.L080C0174: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C0178:
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #7
	adds r0, r0, r3
	b .L080C018C
.L080C0182:
	ldr r0, .L080C0190
	ands r0, r1
	lsls r0, r0, #7
	ldr r1, .L080C0194
	adds r0, r0, r1
.L080C018C:
	pop {r1}
	bx r1
.L080C0190: .4byte 0x00007FFF
.L080C0194: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_080C0198
sub_080C0198: @ 0x080C0198
.L080C0198:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r5, #0
	ldr r7, .L080C01C4
.L080C01A2:
	adds r0, r5, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #1
	bne .L080C01C8
	lsls r0, r4, #7
	adds r1, r0, r7
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	cmp r0, r6
	bne .L080C01C8
	adds r0, r1, #0
	b .L080C01D4
	.byte 0x00, 0x00
.L080C01C4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C01C8:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xb
	bls .L080C01A2
	movs r0, #0
.L080C01D4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C01DC
sub_080C01DC: @ 0x080C01DC
.L080C01DC:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	movs r3, #0
	ldr r1, .L080C022C
	movs r6, #1
	rsbs r6, r6, #0
	ldr r0, .L080C0230
	adds r0, r0, r1
	mov ip, r0
	movs r7, #0xc0
	lsls r7, r7, #8
.L080C0202:
	adds r2, r3, r1
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, r6
	bne .L080C0234
	movs r0, #0
	strb r5, [r2]
	strh r7, [r4, #0xe]
	cmp r5, #3
	bhi .L080C0226
	strh r0, [r4, #0x10]
	cmp r5, #0
	beq .L080C0226
	mov r0, ip
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x58
	strh r1, [r0]
.L080C0226:
	movs r0, #1
	b .L080C0240
	.byte 0x00, 0x00
.L080C022C: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080C0230: .4byte 0xFFFFF638
.L080C0234:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #5
	bls .L080C0202
	movs r0, #0
.L080C0240:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C0248
sub_080C0248: @ 0x080C0248
.L080C0248:
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsrs r5, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r2, r0, #0
	ldr r0, .L080C027C
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r4, r4, r0
	movs r1, #0
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L080C0280
	movs r0, #0
	b .L080C028A
.L080C027C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C0280:
	strb r5, [r4]
	movs r0, #0xc0
	lsls r0, r0, #8
	strh r0, [r2, #0xe]
	movs r0, #1
.L080C028A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080C0290
sub_080C0290: @ 0x080C0290
.L080C0290:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsrs r5, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	movs r2, #0
	ldr r3, .L080C02F8
.L080C02AC:
	adds r1, r2, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r5
	bne .L080C030E
	movs r0, #0xff
	strb r0, [r1]
	cmp r6, #0
	bne .L080C02FC
	cmp r5, #3
	bls .L080C0320
	movs r5, #0x80
	lsls r5, r5, #8
	strh r5, [r4, #0xe]
	ldrb r0, [r4, #0xc]
	bl sub_080C0818
	movs r2, #0x80
	lsls r2, r2, #7
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080C02EA
	ldrb r0, [r4, #0xc]
	movs r1, #0
	bl sub_080C08F8
	ldrb r0, [r4, #0xc]
	adds r1, r5, #0
	bl sub_080C08F8
.L080C02EA:
	ldrb r0, [r4, #0xc]
	movs r1, #0xb0
	lsls r1, r1, #8
	bl sub_080C08BC
	b .L080C033C
	.byte 0x00, 0x00
.L080C02F8: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080C02FC:
	movs r0, #0
	strh r0, [r4, #0xe]
	cmp r5, #3
	bls .L080C033C
	movs r1, #0x12
	ldrsh r0, [r4, r1]
	bl sub_080C2A1C
	b .L080C033C
.L080C030E:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #5
	bls .L080C02AC
	cmp r6, #0
	bne .L080C032C
	cmp r5, #3
	bhi .L080C0324
.L080C0320:
	strh r6, [r4, #0xe]
	b .L080C033C
.L080C0324:
	movs r0, #0x80
	lsls r0, r0, #8
	strh r0, [r4, #0xe]
	b .L080C033C
.L080C032C:
	movs r0, #0
	strh r0, [r4, #0xe]
	cmp r5, #3
	bls .L080C033C
	movs r2, #0x12
	ldrsh r0, [r4, r2]
	bl sub_080C2A1C
.L080C033C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start Combatant_DecodeName
Combatant_DecodeName: @ 0x080C0344
.L080C0344:
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r5, #0
	ldr r4, .L080C0358
.L080C034E:
	ldrb r0, [r2]
	cmp r0, #0xff
	bne .L080C035C
	strh r5, [r1]
	b .L080C0366
.L080C0358: .4byte gUnknown_081A5A6C
.L080C035C:
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
.L080C0366:
	adds r3, #1
	adds r1, #2
	adds r2, #1
	cmp r3, #7
	bls .L080C034E
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C0378
sub_080C0378: @ 0x080C0378
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, #0
	beq .L080C03A0
	cmp r0, #0xff
	beq .L080C03A0
	ldr r3, .L080C03A4
.L080C0388:
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	ldrb r0, [r2]
	cmp r0, #0
	beq .L080C03A0
	cmp r0, #0xff
	bne .L080C0388
.L080C03A0:
	pop {r0}
	bx r0
.L080C03A4: .4byte gUnknown_081A5A6C

	thumb_func_start sub_080C03A8
sub_080C03A8: @ 0x080C03A8
.L080C03A8:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r2, #1
	ldr r0, .L080C03CC
	ldrh r1, [r0, #2]
	adds r3, r0, #0
	cmp r1, #0
	beq .L080C03E0
	adds r1, r3, #0
.L080C03BC:
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r4
	bne .L080C03D0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	b .L080C03E2
.L080C03CC: .4byte gUnknown_081A5A6C
.L080C03D0:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080C03BC
.L080C03E0:
	movs r0, #0
.L080C03E2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C03E8
sub_080C03E8: @ 0x080C03E8
.L080C03E8:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne .L080C03F6
	movs r0, #0xff
	b .L080C0416
.L080C03F6:
	movs r1, #0
	ldr r3, .L080C041C
	ldrh r0, [r3]
	cmp r0, r2
	beq .L080C0414
.L080C0400:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xdf
	bhi .L080C0414
	lsls r0, r1, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne .L080C0400
.L080C0414:
	adds r0, r1, #0
.L080C0416:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C041C: .4byte gUnknown_081A5A6C

	thumb_func_start sub_080C0420
sub_080C0420: @ 0x080C0420
.L080C0420:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r6, #0
.L080C0428:
	ldrh r0, [r5]
	bl sub_080C03E8
	strb r0, [r4]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r5, #2
	adds r4, #1
	cmp r6, #7
	bls .L080C0428
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080C0444
sub_080C0444: @ 0x080C0444
.L080C0444:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF648
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r0, .L080C0548
	mov r1, sp
	str r1, [r0]
	str r6, [r0, #4]
	ldr r1, .L080C054C
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	strb r5, [r6, #0xc]
	strh r4, [r6, #0x12]
	movs r0, #0x80
	lsls r0, r0, #8
	strh r0, [r6, #0xe]
	movs r0, #0
	ldrsb r0, [r7, r0]
	strh r0, [r6, #0x14]
	ldrh r0, [r7, #2]
	strh r0, [r6, #0x18]
	ldrh r0, [r7, #2]
	strh r0, [r6, #0x1a]
	ldrh r0, [r7, #4]
	strh r0, [r6, #0x1c]
	ldrh r0, [r7, #4]
	strh r0, [r6, #0x1e]
	ldrb r0, [r7, #1]
	strb r0, [r6, #0xd]
	ldrb r0, [r7, #0xc]
	lsls r0, r0, #8
	adds r4, r6, #0
	adds r4, #0x58
	strh r0, [r4]
	adds r0, r7, #0
	adds r0, #0x22
	adds r1, r6, #0
	bl sub_080C0420
	adds r0, r5, #0
	movs r1, #0xa
	bl sub_080C35C4
	adds r0, r5, #0
	movs r1, #0xa
	bl sub_080C3600
	ldrb r1, [r7, #6]
	adds r0, r6, #0
	adds r0, #0x40
	strb r1, [r0]
	ldrb r0, [r7, #7]
	adds r1, r6, #0
	adds r1, #0x41
	strb r0, [r1]
	ldrb r0, [r7, #8]
	adds r1, #1
	strb r0, [r1]
	ldrb r0, [r7, #9]
	adds r1, #1
	strb r0, [r1]
	ldrb r1, [r7, #0xa]
	adds r0, r6, #0
	adds r0, #0x44
	strb r1, [r0]
	ldrb r0, [r7, #0xb]
	adds r1, r6, #0
	adds r1, #0x45
	strb r0, [r1]
	ldr r0, [r6, #0x40]
	ldr r1, [r6, #0x44]
	str r0, [r6, #0x28]
	str r1, [r6, #0x2c]
	ldrb r0, [r7, #0xc]
	lsls r0, r0, #8
	strh r0, [r4]
	movs r4, #0
	adds r2, r6, #0
	adds r2, #0x5d
	movs r3, #0xff
	mov ip, r2
.L080C04FA:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0x1f
	ble .L080C04FA
	movs r5, #0
	movs r4, #0
	movs r0, #0x40
	adds r0, r0, r6
	mov r8, r0
	adds r2, r6, #0
	adds r2, #0x48
	adds r1, r7, #0
	adds r1, #0x11
	mov r7, ip
.L080C051C:
	adds r0, r1, r4
	ldrb r3, [r0]
	adds r0, r3, #0
	cmp r0, #0xff
	beq .L080C052C
	adds r0, r7, r5
	strb r3, [r0]
	adds r5, #1
.L080C052C:
	adds r4, #1
	cmp r4, #6
	ble .L080C051C
	ldrb r0, [r6, #0xd]
	mov r1, r8
	bl sub_080C0574
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C0548: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C054C: .4byte 0x85000020

	thumb_func_start sub_080C0550
sub_080C0550: @ 0x080C0550
.L080C0550:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L080C0570
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r1, r4, #0
	adds r2, r5, #0
	bl sub_080C0444
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C0570: .4byte 0xFFFF8000

	thumb_func_start sub_080C0574
sub_080C0574: @ 0x080C0574
.L080C0574:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r4, r0
	lsls r0, r0, #1
	strh r0, [r2]
	lsrs r0, r4, #0x1f
	adds r0, r4, r0
	asrs r0, r0, #1
	adds r6, r4, r0
	movs r0, #4
	ldrsb r0, [r3, r0]
	adds r5, r0, r6
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #5
	ldrsb r0, [r3, r0]
	adds r0, r1, r0
	cmp r0, #0
	bge .L080C05A2
	adds r0, #3
.L080C05A2:
	asrs r0, r0, #2
	adds r0, r5, r0
	strh r0, [r2, #2]
	movs r0, #3
	ldrsb r0, [r3, r0]
	adds r0, r4, r0
	lsls r0, r0, #1
	strh r0, [r2, #8]
	movs r0, #4
	ldrsb r0, [r3, r0]
	adds r4, r0, r6
	movs r1, #1
	ldrsb r1, [r3, r1]
	movs r0, #5
	ldrsb r0, [r3, r0]
	adds r0, r1, r0
	cmp r0, #0
	bge .L080C05C8
	adds r0, #3
.L080C05C8:
	asrs r0, r0, #2
	adds r0, r4, r0
	strh r0, [r2, #0xa]
	movs r0, #1
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge .L080C05D8
	adds r0, #3
.L080C05D8:
	asrs r0, r0, #2
	movs r1, #2
	ldrsb r1, [r3, r1]
	adds r0, r0, r1
	strh r0, [r2, #0xc]
	movs r0, #2
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge .L080C05EC
	adds r0, #3
.L080C05EC:
	asrs r0, r0, #2
	movs r1, #1
	ldrsb r1, [r3, r1]
	adds r0, r0, r1
	strh r0, [r2, #0xe]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080C05FC
sub_080C05FC: @ 0x080C05FC
.L080C05FC:
	push {lr}
	adds r2, r0, #0
	ldrh r1, [r2, #0x10]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	cmp r0, #0
	bne .L080C061A
	ldrb r0, [r2, #0xd]
	adds r1, r2, #0
	adds r1, #0x40
	adds r2, #0x48
	bl sub_080C0574
	b .L080C0624
.L080C061A:
	ldrb r0, [r2, #0xd]
	ldr r1, .L080C0628
	adds r2, #0x48
	bl sub_080C0574
.L080C0624:
	pop {r0}
	bx r0
.L080C0628: .4byte gUnknown_081A5C2C

	thumb_func_start sub_080C062C
sub_080C062C: @ 0x080C062C
.L080C062C:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r5, #0
	bl sub_080C351C
	cmp r0, #0
	bne .L080C0642
	movs r0, #1
	rsbs r0, r0, #0
	b .L080C0680
.L080C0642:
	movs r4, #0
	b .L080C0648
.L080C0646:
	adds r4, #1
.L080C0648:
	cmp r4, #0xb
	bhi .L080C065E
	ldr r1, .L080C0688
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne .L080C0646
.L080C065E:
	adds r4, #4
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080C0550
	movs r0, #0xe5
	bl Flag_Test
	cmp r0, #0
	beq .L080C0678
	adds r0, r5, #0
	bl sub_080C2674
.L080C0678:
	adds r0, r5, #0
	bl sub_080C28F8
	adds r0, r4, #0
.L080C0680:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0688: .4byte 0x00008004

	thumb_func_start Race_GetName
Race_GetName: @ 0x080C068C
.L080C068C:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xc
	ldr r1, .L080C0698
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
.L080C0698: .4byte gUnknown_081A5C34

	thumb_func_start ParentRace_GetName
ParentRace_GetName: @ 0x080C069C
.L080C069C:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xc
	ldr r1, .L080C06A8
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
.L080C06A8: .4byte gUnknown_081A5F24

	thumb_func_start sub_080C06AC
sub_080C06AC: @ 0x080C06AC
.L080C06AC:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xc
	ldr r1, .L080C06B8
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
.L080C06B8: .4byte gUnknown_081A6014

	thumb_func_start sub_080C06BC
sub_080C06BC: @ 0x080C06BC
.L080C06BC:
	push {lr}
	ldr r1, .L080C06D8
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x58
	ldrh r0, [r0]
	lsrs r0, r0, #8
	cmp r0, #0x6f
	bhi .L080C06DC
	movs r0, #0
	b .L080C06E6
.L080C06D8: .4byte 0xFFFF8000
.L080C06DC:
	cmp r0, #0x8f
	bls .L080C06E4
	movs r0, #2
	b .L080C06E6
.L080C06E4:
	movs r0, #1
.L080C06E6:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C06EC
sub_080C06EC: @ 0x080C06EC
.L080C06EC:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, .L080C071C
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	movs r0, #0xe0
	bl Flag_Test
	cmp r0, #0
	bne .L080C072A
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r1, [r0]
	adds r1, r1, r6
	cmp r1, #0
	bge .L080C0720
	movs r1, #0
	b .L080C0728
	.byte 0x00, 0x00
.L080C071C: .4byte 0xFFFF8000
.L080C0720:
	ldr r2, .L080C0748
	cmp r1, r2
	ble .L080C0728
	adds r1, r2, #0
.L080C0728:
	strh r1, [r0]
.L080C072A:
	cmp r5, #0
	bne .L080C0750
	ldr r3, .L080C074C
	adds r2, r4, #0
	adds r2, #0x58
	ldrh r1, [r2]
	adds r0, r3, #0
	adds r0, #0xd8
	strh r1, [r0]
	ldrh r1, [r2]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r3, r2
	b .L080C0760
	.byte 0x00, 0x00
.L080C0748: .4byte 0x0000FFFF
.L080C074C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C0750:
	subs r0, r5, #1
	cmp r0, #1
	bhi .L080C0762
	ldr r0, .L080C0770
	adds r0, #0x58
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x58
.L080C0760:
	strh r1, [r0]
.L080C0762:
	adds r0, r5, #0
	bl sub_080C06BC
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0770: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_080C0774
sub_080C0774: @ 0x080C0774
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080C0790
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x58
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C0790: .4byte 0xFFFF8000

	thumb_func_start sub_080C0794
sub_080C0794: @ 0x080C0794
.L080C0794:
	push {lr}
	ldr r1, .L080C07AC
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x58
	ldrh r0, [r0]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C07AC: .4byte 0xFFFF8000

	thumb_func_start sub_080C07B0
sub_080C07B0: @ 0x080C07B0
.L080C07B0:
	push {r4, r5, lr}
	adds r4, r1, #0
	bl sub_080C06BC
	adds r5, r0, #0
	adds r0, r4, #0
	bl sub_080C06BC
	cmp r5, #0
	bne .L080C07CC
	cmp r0, #2
	bne .L080C07D8
	movs r0, #0
	b .L080C07DA
.L080C07CC:
	cmp r5, #2
	bne .L080C07D8
	cmp r0, #0
	bne .L080C07D8
	movs r0, #0
	b .L080C07DA
.L080C07D8:
	movs r0, #1
.L080C07DA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080C07E0
sub_080C07E0: @ 0x080C07E0
.L080C07E0:
	push {lr}
	ldr r1, .L080C07F8
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C07F8: .4byte 0xFFFF8000

	thumb_func_start sub_080C07FC
sub_080C07FC: @ 0x080C07FC
.L080C07FC:
	push {lr}
	ldr r1, .L080C0814
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x14
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0814: .4byte 0xFFFF8000

	thumb_func_start sub_080C0818
sub_080C0818: @ 0x080C0818
.L080C0818:
	push {lr}
	ldr r1, .L080C082C
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r0, [r0, #0x10]
	pop {r1}
	bx r1
.L080C082C: .4byte 0xFFFF8000

	thumb_func_start sub_080C0830
sub_080C0830: @ 0x080C0830
.L080C0830:
	push {lr}
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	bne .L080C0844
	movs r0, #0
	b .L080C0846
.L080C0844:
	movs r0, #1
.L080C0846:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C084C
sub_080C084C: @ 0x080C084C
.L080C084C:
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r1, .L080C087C
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq .L080C0880
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080C0888
	b .L080C08B4
.L080C087C: .4byte 0xFFFF8000
.L080C0880:
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080C08B4
.L080C0888:
	cmp r5, #3
	bgt .L080C0894
	adds r0, r5, #0
	bl sub_080BF938
	b .L080C089A
.L080C0894:
	adds r0, r4, #0
	bl sub_080C05FC
.L080C089A:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r7
	cmp r0, #0
	bne .L080C08B0
	cmp r5, #3
	bgt .L080C08B0
	ldrh r0, [r4, #0x1a]
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
.L080C08B0:
	bl sub_080C65C8
.L080C08B4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C08BC
sub_080C08BC: @ 0x080C08BC
.L080C08BC:
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	ldr r1, .L080C08E4
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r2, [r0, #0x10]
	ands r4, r2
	strh r4, [r0, #0x10]
	ldrh r1, [r0, #0x10]
	adds r0, r5, #0
	bl sub_080C084C
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C08E4: .4byte 0xFFFF8000

	thumb_func_start sub_080C08E8
sub_080C08E8: @ 0x080C08E8
.L080C08E8:
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080C08F8
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C08F8
sub_080C08F8: @ 0x080C08F8
.L080C08F8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	ldr r0, .L080C092C
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r7, r0, #0
	mov r4, r8
	movs r5, #0
	ldrh r0, [r7, #0x10]
	mov sl, r0
	cmp r4, #0
	bne .L080C0930
	strh r5, [r7, #0x10]
	movs r0, #0
	b .L080C0992
.L080C092C: .4byte 0xFFFF8000
.L080C0930:
	movs r6, #0xf
	movs r3, #1
.L080C0934:
	adds r0, r4, #0
	ands r0, r3
	cmp r0, #0
	beq .L080C0988
	lsrs r4, r4, #1
	ldrh r1, [r7, #0x10]
	adds r0, r1, #0
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq .L080C094E
	orrs r5, r3
	b .L080C098A
.L080C094E:
	ldr r0, .L080C0964
	lsls r2, r6, #1
	adds r0, r2, r0
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq .L080C0968
	movs r0, #2
	orrs r5, r0
	b .L080C098A
	.byte 0x00, 0x00
.L080C0964: .4byte gUnknown_081A6044
.L080C0968:
	ldr r0, .L080C0984
	adds r0, r2, r0
	ldrh r0, [r0]
	ands r1, r0
	mov r0, r8
	orrs r1, r0
	strh r1, [r7, #0x10]
	mov r0, sb
	mov r2, sl
	str r3, [sp]
	bl sub_080C084C
	ldr r3, [sp]
	b .L080C098A
.L080C0984: .4byte gUnknown_081A6064
.L080C0988:
	lsrs r4, r4, #1
.L080C098A:
	subs r6, #1
	cmp r6, #0
	bge .L080C0934
	adds r0, r5, #0
.L080C0992:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start Race_GetParentId
Race_GetParentId: @ 0x080C09A4
.L080C09A4:
	ldr r1, .L080C09AC
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
.L080C09AC: .4byte gUnknown_081A6084

	thumb_func_start sub_080C09B0
sub_080C09B0: @ 0x080C09B0
.L080C09B0:
	push {lr}
	ldr r1, .L080C09C8
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne .L080C09CC
	movs r0, #0
	b .L080C09CE
.L080C09C8: .4byte 0xFFFF8000
.L080C09CC:
	movs r0, #1
.L080C09CE:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C09D4
sub_080C09D4: @ 0x080C09D4
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080C09F8
	adds r0, r4, #0
	bl sub_080C0818
	ldr r1, .L080C09F4
	ands r1, r0
	cmp r1, #0
	bne .L080C09F8
	movs r0, #1
	b .L080C09FA
	.byte 0x00, 0x00
.L080C09F4: .4byte 0x0000B160
.L080C09F8:
	movs r0, #0
.L080C09FA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C0A00
sub_080C0A00: @ 0x080C0A00
.L080C0A00:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080C0A1A
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080C0A1A
	movs r0, #1
	b .L080C0A1C
.L080C0A1A:
	movs r0, #0
.L080C0A1C:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C0A24
sub_080C0A24: @ 0x080C0A24
.L080C0A24:
	push {lr}
	ldr r1, .L080C0A44
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r2, #0x18
	ldrsh r1, [r0, r2]
	movs r2, #0x1a
	ldrsh r0, [r0, r2]
	cmp r1, r0
	blt .L080C0A48
	movs r0, #1
	b .L080C0A4A
	.byte 0x00, 0x00
.L080C0A44: .4byte 0xFFFF8000
.L080C0A48:
	movs r0, #0
.L080C0A4A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C0A50
sub_080C0A50: @ 0x080C0A50
.L080C0A50:
	push {lr}
	ldr r1, .L080C0A70
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r2, #0x1e
	ldrsh r0, [r0, r2]
	cmp r1, r0
	blt .L080C0A74
	movs r0, #1
	b .L080C0A76
	.byte 0x00, 0x00
.L080C0A70: .4byte 0xFFFF8000
.L080C0A74:
	movs r0, #0
.L080C0A76:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C0A7C
sub_080C0A7C: @ 0x080C0A7C
.L080C0A7C:
	push {r4, lr}
	ldr r1, .L080C0AA4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	movs r4, #0x18
	ldrsh r1, [r2, r4]
	ldrh r3, [r2, #0x1a]
	movs r4, #0x1a
	ldrsh r0, [r2, r4]
	cmp r1, r0
	bge .L080C0A9C
	strh r3, [r2, #0x18]
.L080C0A9C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C0AA4: .4byte 0xFFFF8000

	thumb_func_start sub_080C0AA8
sub_080C0AA8: @ 0x080C0AA8
.L080C0AA8:
	push {r4, lr}
	ldr r1, .L080C0AD0
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	movs r4, #0x1c
	ldrsh r1, [r2, r4]
	ldrh r3, [r2, #0x1e]
	movs r4, #0x1e
	ldrsh r0, [r2, r4]
	cmp r1, r0
	bge .L080C0AC8
	strh r3, [r2, #0x1c]
.L080C0AC8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C0AD0: .4byte 0xFFFF8000

	thumb_func_start sub_080C0AD4
sub_080C0AD4: @ 0x080C0AD4
.L080C0AD4:
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, .L080C0AFC
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	cmp r4, #0
	ble .L080C0B00
	movs r3, #0x18
	ldrsh r1, [r2, r3]
	movs r3, #0x1a
	ldrsh r0, [r2, r3]
	cmp r1, r0
	ble .L080C0B00
	adds r0, r1, #0
	b .L080C0B24
.L080C0AFC: .4byte 0xFFFF8000
.L080C0B00:
	ldrh r0, [r2, #0x18]
	adds r0, r0, r4
	strh r0, [r2, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge .L080C0B14
	movs r0, #0
	strh r0, [r2, #0x18]
	b .L080C0B20
.L080C0B14:
	cmp r5, #0xf
	bgt .L080C0B20
	ldr r3, .L080C0B2C
	cmp r0, r3
	ble .L080C0B20
	strh r3, [r2, #0x18]
.L080C0B20:
	movs r3, #0x18
	ldrsh r0, [r2, r3]
.L080C0B24:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0B2C: .4byte 0x000003E7

	thumb_func_start sub_080C0B30
sub_080C0B30: @ 0x080C0B30
.L080C0B30:
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, .L080C0B6C
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	movs r7, #0
	movs r2, #0x18
	ldrsh r1, [r4, r2]
	movs r3, #0x1a
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble .L080C0B54
	movs r7, #1
.L080C0B54:
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_080C0AD4
	movs r0, #0x18
	ldrsh r1, [r4, r0]
	cmp r1, #0
	bge .L080C0B70
	movs r0, #0
	strh r0, [r4, #0x18]
	b .L080C0B80
	.byte 0x00, 0x00
.L080C0B6C: .4byte 0xFFFF8000
.L080C0B70:
	ldrh r2, [r4, #0x1a]
	movs r3, #0x1a
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble .L080C0B80
	cmp r7, #0
	bne .L080C0B80
	strh r2, [r4, #0x18]
.L080C0B80:
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C0B8C
sub_080C0B8C: @ 0x080C0B8C
.L080C0B8C:
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, .L080C0BB8
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	movs r1, #0x64
	bl __divsi3
	adds r1, r0, #0
	adds r0, r5, #0
	bl sub_080C0AD4
	pop {r4, r5}
	pop {r1}
	bx r1
.L080C0BB8: .4byte 0xFFFF8000

	thumb_func_start sub_080C0BBC
sub_080C0BBC: @ 0x080C0BBC
.L080C0BBC:
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080C0BE4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	cmp r4, #0
	ble .L080C0BE8
	movs r3, #0x1c
	ldrsh r1, [r2, r3]
	movs r3, #0x1e
	ldrsh r0, [r2, r3]
	cmp r1, r0
	ble .L080C0BE8
	adds r0, r1, #0
	b .L080C0C08
	.byte 0x00, 0x00
.L080C0BE4: .4byte 0xFFFF8000
.L080C0BE8:
	ldrh r0, [r2, #0x1c]
	adds r0, r0, r4
	strh r0, [r2, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge .L080C0BFC
	movs r0, #0
	strh r0, [r2, #0x1c]
	b .L080C0C04
.L080C0BFC:
	ldr r1, .L080C0C10
	cmp r0, r1
	ble .L080C0C04
	strh r1, [r2, #0x1c]
.L080C0C04:
	movs r3, #0x1c
	ldrsh r0, [r2, r3]
.L080C0C08:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0C10: .4byte 0x000003E7

	thumb_func_start sub_080C0C14
sub_080C0C14: @ 0x080C0C14
.L080C0C14:
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, .L080C0C50
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	movs r7, #0
	movs r2, #0x1c
	ldrsh r1, [r4, r2]
	movs r3, #0x1e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble .L080C0C38
	movs r7, #1
.L080C0C38:
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_080C0BBC
	movs r0, #0x1c
	ldrsh r1, [r4, r0]
	cmp r1, #0
	bge .L080C0C54
	movs r0, #0
	strh r0, [r4, #0x1c]
	b .L080C0C64
	.byte 0x00, 0x00
.L080C0C50: .4byte 0xFFFF8000
.L080C0C54:
	ldrh r2, [r4, #0x1e]
	movs r3, #0x1e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble .L080C0C64
	cmp r7, #0
	bne .L080C0C64
	strh r2, [r4, #0x1c]
.L080C0C64:
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C0C70
sub_080C0C70: @ 0x080C0C70
.L080C0C70:
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl sub_080F401C
	rsbs r4, r4, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080C0AD4
	cmp r0, #0
	bgt .L080C0CA6
	adds r0, r5, #0
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r5, #0
	bl sub_080C08F8
	cmp r5, #3
	ble .L080C0CA2
	adds r0, r5, #0
	bl sub_080F4190
.L080C0CA2:
	bl sub_080C366C
.L080C0CA6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080C0CAC
sub_080C0CAC: @ 0x080C0CAC
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080C0CC4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	cmp r4, #0
	beq .L080C0CC8
	adds r0, #0x4c
	b .L080C0CCA
.L080C0CC4: .4byte 0xFFFF8000
.L080C0CC8:
	adds r0, #0x48
.L080C0CCA:
	ldrh r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C0CD4
sub_080C0CD4: @ 0x080C0CD4
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080C0CEC
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	cmp r4, #0
	beq .L080C0CF0
	adds r0, #0x4e
	b .L080C0CF2
.L080C0CEC: .4byte 0xFFFF8000
.L080C0CF0:
	adds r0, #0x4a
.L080C0CF2:
	ldrh r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C0CFC
sub_080C0CFC: @ 0x080C0CFC
	push {lr}
	ldr r1, .L080C0D14
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x54
	ldrh r0, [r0]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0D14: .4byte 0xFFFF8000

	thumb_func_start sub_080C0D18
sub_080C0D18: @ 0x080C0D18
	push {lr}
	ldr r1, .L080C0D30
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x56
	ldrh r0, [r0]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0D30: .4byte 0xFFFF8000

	thumb_func_start sub_080C0D34
sub_080C0D34: @ 0x080C0D34
	push {lr}
	ldr r1, .L080C0D4C
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x52
	ldrh r0, [r0]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0D4C: .4byte 0xFFFF8000

	thumb_func_start sub_080C0D50
sub_080C0D50: @ 0x080C0D50
	push {lr}
	ldr r1, .L080C0D68
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x50
	ldrh r0, [r0]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0D68: .4byte 0xFFFF8000

	thumb_func_start sub_080C0D6C
sub_080C0D6C: @ 0x080C0D6C
.L080C0D6C:
	push {lr}
	ldr r1, .L080C0D8C
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x40
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0D8C: .4byte 0xFFFF8000

	thumb_func_start sub_080C0D90
sub_080C0D90: @ 0x080C0D90
.L080C0D90:
	push {lr}
	ldr r1, .L080C0DB0
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x41
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0DB0: .4byte 0xFFFF8000

	thumb_func_start sub_080C0DB4
sub_080C0DB4: @ 0x080C0DB4
.L080C0DB4:
	push {lr}
	ldr r1, .L080C0DD4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x42
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0DD4: .4byte 0xFFFF8000

	thumb_func_start sub_080C0DD8
sub_080C0DD8: @ 0x080C0DD8
.L080C0DD8:
	push {lr}
	ldr r1, .L080C0DF8
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x43
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0DF8: .4byte 0xFFFF8000

	thumb_func_start sub_080C0DFC
sub_080C0DFC: @ 0x080C0DFC
.L080C0DFC:
	push {lr}
	ldr r1, .L080C0E1C
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x44
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0E1C: .4byte 0xFFFF8000

	thumb_func_start sub_080C0E20
sub_080C0E20: @ 0x080C0E20
.L080C0E20:
	push {lr}
	ldr r1, .L080C0E40
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r0, #0x45
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0E40: .4byte 0xFFFF8000

	thumb_func_start sub_080C0E44
sub_080C0E44: @ 0x080C0E44
.L080C0E44:
	push {lr}
	adds r2, r0, #0
	cmp r1, #5
	bhi .L080C0EA6
	lsls r0, r1, #2
	ldr r1, .L080C0E58
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080C0E58: .4byte gUnknown_080C0E5C
	.global gUnknown_080C0E5C
gUnknown_080C0E5C:
.L080C0E5C: @ jump table
	.4byte .L080C0E74
	.4byte .L080C0E7C
	.4byte .L080C0E84
	.4byte .L080C0E8C
	.4byte .L080C0E94
	.4byte .L080C0E9C
.L080C0E74:
	adds r0, r2, #0
	bl sub_080C0D6C
	b .L080C0EA2
.L080C0E7C:
	adds r0, r2, #0
	bl sub_080C0D90
	b .L080C0EA2
.L080C0E84:
	adds r0, r2, #0
	bl sub_080C0DB4
	b .L080C0EA2
.L080C0E8C:
	adds r0, r2, #0
	bl sub_080C0DD8
	b .L080C0EA2
.L080C0E94:
	adds r0, r2, #0
	bl sub_080C0DFC
	b .L080C0EA2
.L080C0E9C:
	adds r0, r2, #0
	bl sub_080C0E20
.L080C0EA2:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L080C0EA6:
	adds r0, r3, #0
	pop {r1}
	bx r1

	thumb_func_start sub_080C0EAC
sub_080C0EAC: @ 0x080C0EAC
.L080C0EAC:
	push {lr}
	cmp r0, #0
	bge .L080C0EB6
	movs r0, #0
	b .L080C0EBC
.L080C0EB6:
	cmp r0, #0x28
	ble .L080C0EBC
	movs r0, #0x28
.L080C0EBC:
	pop {r1}
	bx r1

	thumb_func_start sub_080C0EC0
sub_080C0EC0: @ 0x080C0EC0
.L080C0EC0:
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	adds r6, r2, #0
	ldr r1, .L080C0EE4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	adds r4, #0x28
	cmp r7, #5
	bhi .L080C0F5A
	lsls r0, r7, #2
	ldr r1, .L080C0EE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080C0EE4: .4byte 0xFFFF8000
.L080C0EE8: .4byte gUnknown_080C0EEC
	.global gUnknown_080C0EEC
gUnknown_080C0EEC:
.L080C0EEC: @ jump table
	.4byte .L080C0F04
	.4byte .L080C0F12
	.4byte .L080C0F20
	.4byte .L080C0F2E
	.4byte .L080C0F3C
	.4byte .L080C0F4A
.L080C0F04:
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r0, r0, r6
	bl sub_080C0EAC
	strb r0, [r4]
	b .L080C0F56
.L080C0F12:
	movs r0, #1
	ldrsb r0, [r4, r0]
	adds r0, r0, r6
	bl sub_080C0EAC
	strb r0, [r4, #1]
	b .L080C0F56
.L080C0F20:
	movs r0, #2
	ldrsb r0, [r4, r0]
	adds r0, r0, r6
	bl sub_080C0EAC
	strb r0, [r4, #2]
	b .L080C0F56
.L080C0F2E:
	movs r0, #3
	ldrsb r0, [r4, r0]
	adds r0, r0, r6
	bl sub_080C0EAC
	strb r0, [r4, #3]
	b .L080C0F56
.L080C0F3C:
	movs r0, #4
	ldrsb r0, [r4, r0]
	adds r0, r0, r6
	bl sub_080C0EAC
	strb r0, [r4, #4]
	b .L080C0F56
.L080C0F4A:
	movs r0, #5
	ldrsb r0, [r4, r0]
	adds r0, r0, r6
	bl sub_080C0EAC
	strb r0, [r4, #5]
.L080C0F56:
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
.L080C0F5A:
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C0F64
sub_080C0F64: @ 0x080C0F64
.L080C0F64:
	push {lr}
	movs r2, #0
	bl sub_080C0EC0
	pop {r1}
	bx r1

	thumb_func_start sub_080C0F70
sub_080C0F70: @ 0x080C0F70
.L080C0F70:
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080C0F88
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	str r4, [r0, #8]
	pop {r4}
	pop {r0}
	bx r0
.L080C0F88: .4byte 0xFFFF8000

	thumb_func_start sub_080C0F8C
sub_080C0F8C: @ 0x080C0F8C
.L080C0F8C:
	push {lr}
	ldr r1, .L080C0FA0
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrb r0, [r0, #0xd]
	pop {r1}
	bx r1
.L080C0FA0: .4byte 0xFFFF8000

	thumb_func_start sub_080C0FA4
sub_080C0FA4: @ 0x080C0FA4
.L080C0FA4:
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080C0FBC
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	strb r4, [r0, #0xd]
	pop {r4}
	pop {r0}
	bx r0
.L080C0FBC: .4byte 0xFFFF8000

	thumb_func_start sub_080C0FC0
sub_080C0FC0: @ 0x080C0FC0
.L080C0FC0:
	push {lr}
	movs r2, #0
	movs r1, #0
	ldr r3, .L080C0FE4
.L080C0FC8:
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt .L080C0FD6
	adds r2, #1
.L080C0FD6:
	adds r1, #1
	cmp r1, #5
	ble .L080C0FC8
	adds r0, r2, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C0FE4: .4byte 0x030050E0 @ IWRAM+0x50E0

	thumb_func_start sub_080C0FE8
sub_080C0FE8: @ 0x080C0FE8
.L080C0FE8:
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #4
.L080C0FEE:
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080C100A
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r5
	bne .L080C100A
	adds r0, r4, #0
	b .L080C1014
.L080C100A:
	adds r4, #1
	cmp r4, #0xf
	ble .L080C0FEE
	movs r0, #1
	rsbs r0, r0, #0
.L080C1014:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C101C
sub_080C101C: @ 0x080C101C
.L080C101C:
	push {r4, r5, lr}
	bl sub_080C104C
	movs r4, #4
	adds r0, #4
	cmp r4, r0
	bge .L080C1040
	adds r5, r0, #0
.L080C102C:
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	bne .L080C103A
	adds r0, r4, #0
	b .L080C1044
.L080C103A:
	adds r4, #1
	cmp r4, r5
	blt .L080C102C
.L080C1040:
	movs r0, #1
	rsbs r0, r0, #0
.L080C1044:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C104C
sub_080C104C: @ 0x080C104C
.L080C104C:
	push {r4, lr}
	movs r4, #6
	movs r0, #0xe6
	bl Flag_Test
	cmp r0, #0
	beq .L080C105C
	movs r4, #9
.L080C105C:
	movs r0, #0xe7
	bl Flag_Test
	cmp r0, #0
	beq .L080C1068
	adds r4, #3
.L080C1068:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C1070
sub_080C1070: @ 0x080C1070
.L080C1070:
	push {lr}
	adds r3, r0, #0
	movs r1, #1
	ldr r0, .L080C1084
	adds r2, r0, #4
.L080C107A:
	ldr r0, [r2]
	cmp r0, r3
	ble .L080C1088
	adds r0, r1, #0
	b .L080C1092
.L080C1084: .4byte gUnknown_081A60B4
.L080C1088:
	adds r2, #4
	adds r1, #1
	cmp r1, #0x63
	ble .L080C107A
	movs r0, #0x63
.L080C1092:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C1098
sub_080C1098: @ 0x080C1098
.L080C1098:
	ldr r1, .L080C10A4
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
.L080C10A4: .4byte gUnknown_081A60B4

	thumb_func_start sub_080C10A8
sub_080C10A8: @ 0x080C10A8
.L080C10A8:
	push {lr}
	bl sub_080ED560
	lsls r0, r0, #5
	pop {r1}
	bx r1

	thumb_func_start sub_080C10B4
sub_080C10B4: @ 0x080C10B4
.L080C10B4:
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C32D4
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0xff
	ands r5, r0
	movs r0, #0xff
	adds r1, r5, #0
	bl sub_08131AB0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r0
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080C10E0
sub_080C10E0: @ 0x080C10E0
	movs r0, #0
	bx lr

	thumb_func_start sub_080C10E4
sub_080C10E4: @ 0x080C10E4
.L080C10E4:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xd
	ldr r1, .L080C10F0
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
.L080C10F0: .4byte 0x030050C0 @ IWRAM+0x50C0

	thumb_func_start sub_080C10F4
sub_080C10F4: @ 0x080C10F4
.L080C10F4:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080C1278
	mov r0, sp
	str r0, [r1]
	ldr r2, .L080C127C
	str r2, [r1, #4]
	ldr r0, .L080C1280
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r5, #0
	adds r4, r2, #0
.L080C1110:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080BF748
	adds r4, #0x80
	adds r5, #1
	cmp r5, #3
	bls .L080C1110
	movs r0, #0
	bl sub_080BF938
	bl sub_080C104C
	ldr r2, .L080C127C
	ldr r3, .L080C1284
	adds r1, r2, r3
	strb r0, [r1]
	movs r5, #0
	ldr r7, .L080C1288
	movs r0, #0xa0
	lsls r0, r0, #4
	adds r6, r2, r0
.L080C113C:
	movs r4, #0
	lsls r0, r5, #3
	adds r3, r0, r7
	adds r1, r0, r6
.L080C1144:
	ldrb r0, [r3]
	strb r0, [r1]
	adds r3, #1
	adds r1, #1
	adds r4, #1
	cmp r4, #7
	bls .L080C1144
	adds r5, #1
	cmp r5, #3
	bls .L080C113C
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r1, r2, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r0, .L080C128C
	adds r1, r2, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r3, #2
	adds r1, r2, r3
	strb r0, [r1]
	ldr r0, .L080C1290
	adds r1, r2, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r3, #2
	adds r1, r2, r3
	strb r0, [r1]
	ldr r0, .L080C1294
	adds r1, r2, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r5, #0
	adds r4, r2, #0
	adds r4, #0x18
.L080C1192:
	adds r0, r5, #0
	bl sub_080BF8D8
	ldrh r0, [r4, #2]
	strh r0, [r4]
	ldrh r0, [r4, #6]
	strh r0, [r4, #4]
	adds r4, #0x80
	adds r5, #1
	cmp r5, #3
	bls .L080C1192
	movs r0, #0
	bl sub_080C01DC
	ldr r1, .L080C127C
	ldr r2, .L080C1298
	adds r0, r1, r2
	movs r2, #0xff
	strh r2, [r0]
	ldr r3, .L080C129C
	adds r0, r1, r3
	strh r2, [r0]
	adds r3, #8
	adds r0, r1, r3
	strh r2, [r0]
	adds r3, #8
	adds r0, r1, r3
	strh r2, [r0]
	adds r3, #8
	adds r0, r1, r3
	strh r2, [r0]
	adds r3, #8
	adds r0, r1, r3
	strh r2, [r0]
	adds r3, #8
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, .L080C12A0
	adds r1, r1, r0
	strh r2, [r1]
	movs r5, #0
.L080C11E4:
	movs r4, #0xc
	adds r6, r5, #1
	lsls r5, r5, #0x10
.L080C11EA:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	lsrs r1, r5, #0x10
	bl Automap_SetVisitedRaw
	adds r4, #1
	cmp r4, #0xf
	bls .L080C11EA
	adds r5, r6, #0
	cmp r5, #0xb
	bls .L080C11E4
	movs r0, #0xd
	movs r1, #1
	bl Automap_ClearVisitedRaw
	movs r0, #0xd
	movs r1, #5
	bl Automap_ClearVisitedRaw
	movs r0, #0xc
	movs r1, #0xa
	bl Automap_ClearVisitedRaw
	movs r0, #0xc
	movs r1, #0xb
	bl Automap_ClearVisitedRaw
	movs r0, #0xd
	movs r1, #0xb
	bl Automap_ClearVisitedRaw
	ldr r4, .L080C127C
	ldr r2, .L080C12A4
	adds r1, r4, r2
	movs r2, #0
	movs r5, #0
	movs r0, #0x80
	strh r0, [r1]
	ldr r3, .L080C12A8
	adds r0, r4, r3
	strb r2, [r0]
	ldr r0, .L080C12AC
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, .L080C12B0
	adds r0, r4, r1
	strb r2, [r0]
	bl sub_080E4520
	bl sub_080C271C
	bl sub_080C27F0
	bl sub_080C2968
	bl ComboBits_Clear
	ldr r2, .L080C12B4
	adds r1, r4, r2
	ldr r0, .L080C12B8
	strh r0, [r1]
	movs r3, #0xac
	lsls r3, r3, #4
	adds r4, r4, r3
	strh r5, [r4]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C1278: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C127C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C1280: .4byte 0x8500063E
.L080C1284: .4byte 0x00000AC3
.L080C1288: .4byte gUnknown_081A6244
.L080C128C: .4byte 0x00000A21
.L080C1290: .4byte 0x00000A23
.L080C1294: .4byte 0x00000A25
.L080C1298: .4byte 0x0000114C
.L080C129C: .4byte 0x00001154
.L080C12A0: .4byte 0x00001184
.L080C12A4: .4byte 0x00000A28
.L080C12A8: .4byte 0x000018B4
.L080C12AC: .4byte 0x000018B5
.L080C12B0: .4byte 0x000018B6
.L080C12B4: .4byte 0x000018A6
.L080C12B8: .4byte 0x0000FFFF

	thumb_func_start sub_080C12BC
sub_080C12BC: @ 0x080C12BC
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080C12C0
sub_080C12C0: @ 0x080C12C0
.L080C12C0:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, .L080C12EC
	str r0, [r3]
	ldr r0, .L080C12F0
	str r1, [r0]
	ldr r0, .L080C12F4
	str r2, [r0]
	ldr r1, .L080C12F8
	movs r0, #0
	str r0, [r1]
	ldr r0, .L080C12FC
	bl SetMainCallback
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C12EC: .4byte 0x03004610 @ IWRAM+0x4610
.L080C12F0: .4byte 0x03004514 @ IWRAM+0x4514
.L080C12F4: .4byte 0x03004614 @ IWRAM+0x4614
.L080C12F8: .4byte 0x03004544 @ IWRAM+0x4544
.L080C12FC: .4byte sub_080C1560

	thumb_func_start sub_080C1300
sub_080C1300: @ 0x080C1300
.L080C1300:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L080C131C
	movs r1, #2
	str r1, [r2]
	ldr r1, .L080C1320
	str r0, [r1]
	ldr r0, .L080C1324
	bl SetMainCallback
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C131C: .4byte 0x03004544 @ IWRAM+0x4544
.L080C1320: .4byte 0x030045FC @ IWRAM+0x45FC
.L080C1324: .4byte sub_080C1560

	thumb_func_start sub_080C1328
sub_080C1328: @ 0x080C1328
.L080C1328:
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080C1360
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080C1364
	str r0, [r1, #4]
	ldr r0, .L080C1368
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080C136C
	str r0, [r1]
	ldr r0, .L080C1370
	str r0, [r1, #4]
	ldr r0, .L080C1374
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080C1378
	str r0, [r1]
	ldr r0, .L080C137C
	str r0, [r1, #4]
	ldr r0, .L080C1380
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	bx lr
	.byte 0x00, 0x00
.L080C1360: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C1364: .4byte 0x06008000 @ VRAM+0x8000
.L080C1368: .4byte 0x85000F00
.L080C136C: .4byte gUnknown_081A91B8
.L080C1370: .4byte 0x0600BC00 @ VRAM+0xBC00
.L080C1374: .4byte 0x84001100
.L080C1378: .4byte gUnknown_081B13B8
.L080C137C: .4byte 0x06010000 @ VRAM+0x10000
.L080C1380: .4byte 0x84000800

	thumb_func_start sub_080C1384
sub_080C1384: @ 0x080C1384
.L080C1384:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r1, .L080C13D4
	ldr r7, .L080C13D8
	movs r0, #0x80
	lsls r0, r0, #2
	mov r8, r0
	movs r6, #0x20
	str r6, [sp]
	movs r0, #3
	adds r2, r7, #0
	mov r3, r8
	bl Palette_CopyWithEffect
	movs r5, #0
	strh r5, [r7]
	ldr r1, .L080C13DC
	movs r0, #0x80
	lsls r0, r0, #2
	adds r4, r7, r0
	str r6, [sp]
	movs r0, #3
	adds r2, r4, #0
	mov r3, r8
	bl Palette_CopyWithEffect
	strh r5, [r4]
	ldr r0, .L080C13E0
	ldr r0, [r0]
	ldr r1, .L080C13E4
	ands r0, r1
	cmp r0, #0
	bne .L080C13E8
	adds r0, r7, #0
	movs r1, #7
	bl sub_080C67C0
	b .L080C13F0
.L080C13D4: .4byte gUnknown_081B6E30
.L080C13D8: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080C13DC: .4byte gUnknown_081B6C30
.L080C13E0: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080C13E4: .4byte 0x00007FFF
.L080C13E8:
	adds r0, r7, #0
	movs r1, #0xc
	bl sub_080C67C0
.L080C13F0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080C13FC
sub_080C13FC: @ 0x080C13FC
	ldrh r2, [r0]
	ldr r1, .L080C1408
	ands r1, r2
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C1408: .4byte 0x0000FFBF
