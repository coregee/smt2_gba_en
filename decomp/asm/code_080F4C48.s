	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080F4C48
sub_080F4C48: @ 0x080F4C48
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #1
	bl sub_080EFD5C
	adds r1, r4, #0
	bl sub_080F49D4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4C60
sub_080F4C60: @ 0x080F4C60
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #1
	bl sub_080EFDA4
	adds r1, r4, #0
	bl sub_080F49D4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4C78
sub_080F4C78: @ 0x080F4C78
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #1
	bl sub_080EFDEC
	adds r1, r4, #0
	bl sub_080F49D4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4C90
sub_080F4C90: @ 0x080F4C90
.L080F4C90:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r5]
	bl sub_080EFAB0
	lsls r0, r0, #0x10
	lsls r4, r4, #0x10
	asrs r1, r4, #0x10
	ands r4, r0
	cmp r4, #0
	beq .L080F4CB8
	movs r0, #0x96
	str r0, [r5, #8]
	movs r0, #0
	str r0, [r5, #0xc]
	b .L080F4CCE
.L080F4CB8:
	ldr r0, [r5]
	bl sub_080EFAD0
	cmp r6, #0
	blt .L080F4CCE
	str r6, [r5, #8]
	ldr r0, [r5]
	cmp r0, #0xf
	ble .L080F4CCE
	adds r0, r6, #1
	str r0, [r5, #8]
.L080F4CCE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4CD4
sub_080F4CD4: @ 0x080F4CD4
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080F3F44
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq .L080F4CF0
	movs r0, #0x96
	str r0, [r4, #8]
	movs r0, #0
	str r0, [r4, #0xc]
	b .L080F4D04
.L080F4CF0:
	adds r0, r1, #0
	bl sub_080F3F74
	movs r0, #0xcb
	str r0, [r4, #8]
	ldr r0, [r4]
	cmp r0, #0xf
	ble .L080F4D04
	movs r0, #0xcc
	str r0, [r4, #8]
.L080F4D04:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F4D0C
sub_080F4D0C: @ 0x080F4D0C
	push {lr}
	movs r1, #1
	movs r2, #0xcd
	bl sub_080F4C90
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F4D1C
sub_080F4D1C: @ 0x080F4D1C
	push {lr}
	movs r1, #2
	movs r2, #0xcf
	bl sub_080F4C90
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F4D2C
sub_080F4D2C: @ 0x080F4D2C
.L080F4D2C:
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, .L080F4D60
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	ldrh r0, [r2, #0x18]
	adds r0, r0, r4
	strh r0, [r2, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r2, #0x1a]
	movs r4, #0x1a
	ldrsh r1, [r2, r4]
	cmp r0, r1
	ble .L080F4D54
	strh r3, [r2, #0x18]
.L080F4D54:
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080F4D60: .4byte 0xFFFF8000

	thumb_func_start sub_080F4D64
sub_080F4D64: @ 0x080F4D64
.L080F4D64:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r6, r0
	beq .L080F4DAE
	ldr r0, [r4, #4]
	ldr r4, [r4]
	bl sub_080C0E20
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x11
	adds r0, r4, #0
	bl sub_080C0D90
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #2
	bl sub_080C1F94
	adds r5, r5, r0
	adds r0, r4, #0
	bl sub_080C0DB4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r5, r5, r0
	bl sub_080C2244
	adds r2, r5, #0
	lsls r2, r6
	movs r1, #7
	ands r1, r0
	adds r5, r2, r1
	adds r0, r5, #0
	b .L080F4DB0
.L080F4DAE:
	ldr r0, .L080F4DB8
.L080F4DB0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080F4DB8: .4byte 0x000003E7

	thumb_func_start sub_080F4DBC
sub_080F4DBC: @ 0x080F4DBC
.L080F4DBC:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r4, [r5, #4]
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F4E14
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	adds r0, r4, #0
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	cmp r1, #0
	bne .L080F4E0A
	adds r0, r4, #0
	bl sub_080C0A24
	cmp r0, #0
	bne .L080F4E14
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_080F4D64
	adds r1, r0, #0
	adds r0, r4, #0
	bl sub_080F4D2C
	movs r0, #1
	b .L080F4E16
.L080F4E0A:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C0290
.L080F4E14:
	movs r0, #0
.L080F4E16:
	str r0, [r5, #0xc]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F4E20
sub_080F4E20: @ 0x080F4E20
	push {lr}
	movs r1, #0
	bl sub_080F4DBC
	pop {r0}
	bx r0

	thumb_func_start sub_080F4E2C
sub_080F4E2C: @ 0x080F4E2C
	push {lr}
	movs r1, #2
	bl sub_080F4DBC
	pop {r0}
	bx r0

	thumb_func_start sub_080F4E38
sub_080F4E38: @ 0x080F4E38
	push {lr}
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_080F4DBC
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F4E48
sub_080F4E48: @ 0x080F4E48
.L080F4E48:
	push {r4, r5, r6, r7, lr}
	sub sp, #0x20
	adds r7, r0, #0
	adds r6, r1, #0
	movs r5, #0
	mov r0, sp
	adds r1, r7, #0
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3}
	stm r0!, {r2, r3}
	ldr r0, [r7]
	cmp r0, #0xf
	ble .L080F4E8E
	movs r4, #0x10
.L080F4E6A:
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080F4E86
	str r4, [sp, #4]
	mov r0, sp
	adds r1, r6, #0
	bl sub_080F4DBC
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq .L080F4E86
	adds r5, #1
.L080F4E86:
	adds r4, #1
	cmp r4, #0x17
	ble .L080F4E6A
	b .L080F4EB2
.L080F4E8E:
	movs r4, #0
.L080F4E90:
	adds r0, r4, #0
	bl sub_080F40EC
	str r0, [sp, #4]
	cmp r0, #0
	blt .L080F4EAC
	mov r0, sp
	adds r1, r6, #0
	bl sub_080F4DBC
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq .L080F4EAC
	adds r5, #1
.L080F4EAC:
	adds r4, #1
	cmp r4, #5
	ble .L080F4E90
.L080F4EB2:
	cmp r5, #0
	bne .L080F4EB8
	str r5, [r7, #0xc]
.L080F4EB8:
	add sp, #0x20
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4EC0
sub_080F4EC0: @ 0x080F4EC0
	push {lr}
	movs r1, #0
	bl sub_080F4E48
	pop {r0}
	bx r0

	thumb_func_start sub_080F4ECC
sub_080F4ECC: @ 0x080F4ECC
	push {lr}
	movs r1, #2
	bl sub_080F4E48
	pop {r0}
	bx r0

	thumb_func_start sub_080F4ED8
sub_080F4ED8: @ 0x080F4ED8
	push {lr}
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_080F4E48
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F4EE8
sub_080F4EE8: @ 0x080F4EE8
.L080F4EE8:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	bl sub_080ED794
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r4, [r5, #4]
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F4F2E
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	adds r0, r4, #0
	bl sub_080C0818
	adds r1, r6, #0
	ands r1, r0
	cmp r1, #0
	beq .L080F4F2E
	mvns r1, r6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_080C08BC
	movs r0, #1
	b .L080F4F30
.L080F4F2E:
	movs r0, #0
.L080F4F30:
	str r0, [r5, #0xc]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080F4F38
sub_080F4F38: @ 0x080F4F38
	push {lr}
	movs r1, #0x31
	bl sub_080F4EE8
	pop {r0}
	bx r0

	thumb_func_start sub_080F4F44
sub_080F4F44: @ 0x080F4F44
	push {lr}
	movs r1, #0x33
	bl sub_080F4EE8
	pop {r0}
	bx r0

	thumb_func_start sub_080F4F50
sub_080F4F50: @ 0x080F4F50
	push {lr}
	movs r1, #0x34
	bl sub_080F4EE8
	pop {r0}
	bx r0

	thumb_func_start sub_080F4F5C
sub_080F4F5C: @ 0x080F4F5C
	push {lr}
	movs r1, #0x35
	bl sub_080F4EE8
	pop {r0}
	bx r0

	thumb_func_start sub_080F4F68
sub_080F4F68: @ 0x080F4F68
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r6, r0, #0
	movs r5, #0
	mov r0, sp
	adds r1, r6, #0
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3}
	stm r0!, {r2, r3}
	ldr r0, [r6]
	cmp r0, #0xf
	ble .L080F4FAC
	movs r4, #0x10
.L080F4F88:
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080F4FA4
	str r4, [sp, #4]
	mov r0, sp
	movs r1, #0x31
	bl sub_080F4EE8
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq .L080F4FA4
	adds r5, #1
.L080F4FA4:
	adds r4, #1
	cmp r4, #0x17
	ble .L080F4F88
	b .L080F4FD0
.L080F4FAC:
	movs r4, #0
.L080F4FAE:
	adds r0, r4, #0
	bl sub_080F40EC
	str r0, [sp, #4]
	cmp r0, #0
	blt .L080F4FCA
	mov r0, sp
	movs r1, #0x31
	bl sub_080F4EE8
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq .L080F4FCA
	adds r5, #1
.L080F4FCA:
	adds r4, #1
	cmp r4, #5
	ble .L080F4FAE
.L080F4FD0:
	cmp r5, #0
	bne .L080F4FD6
	str r5, [r6, #0xc]
.L080F4FD6:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F4FE0
sub_080F4FE0: @ 0x080F4FE0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #4]
	adds r0, r4, #0
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq .L080F5032
	adds r0, r4, #0
	movs r1, #1
	bl sub_080C08BC
	adds r0, r4, #0
	bl sub_080C0A7C
	movs r1, #0x4b
	rsbs r1, r1, #0
	adds r0, r4, #0
	bl sub_080C0B8C
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	movs r0, #0xe5
	str r0, [r5, #8]
	cmp r4, #0xf
	ble .L080F5030
	movs r0, #0xe6
	str r0, [r5, #8]
.L080F5030:
	movs r0, #1
.L080F5032:
	str r0, [r5, #0xc]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F503C
sub_080F503C: @ 0x080F503C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #4]
	adds r0, r4, #0
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq .L080F5088
	movs r0, #1
	str r0, [r5, #0xc]
	adds r0, r4, #0
	movs r1, #1
	bl sub_080C08BC
	adds r0, r4, #0
	bl sub_080C0A7C
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	movs r0, #0xe5
	str r0, [r5, #8]
	cmp r4, #0xf
	ble .L080F508A
	movs r0, #0xe6
	str r0, [r5, #8]
	b .L080F508A
.L080F5088:
	str r0, [r5, #0xc]
.L080F508A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080F5090
sub_080F5090: @ 0x080F5090
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r7, #0
	ldr r6, [r0]
	cmp r6, #0xf
	ble .L080F50CA
	movs r5, #0x10
.L080F50A2:
	adds r0, r5, #0
	bl sub_080C0A00
	cmp r0, #0
	beq .L080F50C2
	cmp r5, r6
	beq .L080F50C2
	adds r0, r5, #0
	bl sub_080C0A24
	cmp r0, #0
	bne .L080F50C2
	adds r0, r5, #0
	bl sub_080C0A7C
	adds r7, #1
.L080F50C2:
	adds r5, #1
	cmp r5, #0x17
	ble .L080F50A2
	b .L080F50FC
.L080F50CA:
	movs r5, #0
.L080F50CC:
	adds r0, r5, #0
	bl sub_080F40EC
	adds r4, r0, #0
	cmp r4, #0
	blt .L080F50F6
	bl sub_080C0830
	cmp r0, #0
	bne .L080F50F6
	cmp r4, r6
	beq .L080F50F6
	adds r0, r4, #0
	bl sub_080C0A24
	cmp r0, #0
	bne .L080F50F6
	adds r0, r4, #0
	bl sub_080C0A7C
	adds r7, #1
.L080F50F6:
	adds r5, #1
	cmp r5, #5
	ble .L080F50CC
.L080F50FC:
	cmp r7, #0
	beq .L080F514A
	movs r0, #0xd9
	mov r1, r8
	str r0, [r1, #8]
	cmp r6, #0xf
	ble .L080F510E
	movs r0, #0xda
	str r0, [r1, #8]
.L080F510E:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r6, #0
	bl sub_080C08E8
	adds r0, r6, #0
	movs r1, #0
	bl sub_080F4054
	adds r0, r6, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	subs r0, r6, #4
	cmp r0, #0xb
	bhi .L080F513A
	adds r0, r6, #0
	bl sub_080F4190
.L080F513A:
	bl sub_080C366C
	movs r0, #1
	mov r1, r8
	str r0, [r1, #0xc]
	bl sub_080E760C
	b .L080F514E
.L080F514A:
	mov r0, r8
	str r7, [r0, #0xc]
.L080F514E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080F5158
sub_080F5158: @ 0x080F5158
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080F5180
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080F5184
	bl sub_080F3DD8
	cmp r0, #0
	beq .L080F5184
	movs r0, #0x80
	lsls r0, r0, #1
	bl sub_080F3F74
	movs r0, #1
	b .L080F518C
	.byte 0x00, 0x00
.L080F5180: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F5184:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #8]
	movs r0, #0
.L080F518C:
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F5194
sub_080F5194: @ 0x080F5194
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_080C5240
	adds r4, r0, #0
	cmp r4, #1
	bne .L080F51AA
	bl sub_080C5224
	str r4, [r5, #0xc]
	b .L080F51AE
.L080F51AA:
	movs r0, #0
	str r0, [r5, #0xc]
.L080F51AE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080F51B4
sub_080F51B4: @ 0x080F51B4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_080C5320
	adds r4, r0, #0
	cmp r4, #1
	bne .L080F51CA
	bl sub_080C5304
	str r4, [r5, #0xc]
	b .L080F51CE
.L080F51CA:
	movs r0, #0
	str r0, [r5, #0xc]
.L080F51CE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080F51D4
sub_080F51D4: @ 0x080F51D4
.L080F51D4:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L080F51F2
	movs r0, #0xb3
	lsls r0, r0, #1
	bl Flag_Test
	cmp r0, #0
	beq .L080F51F6
.L080F51F2:
	movs r0, #0
	b .L080F5200
.L080F51F6:
	movs r0, #0x80
	lsls r0, r0, #6
	bl sub_080ED90C
	movs r0, #1
.L080F5200:
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F5208
sub_080F5208: @ 0x080F5208
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080F3F44
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq .L080F521E
	movs r0, #0x96
	str r0, [r4, #8]
	b .L080F5236
.L080F521E:
	movs r0, #0x80
	bl sub_080F3F74
	bl sub_080C1D9C
	ldr r2, .L080F5240
	movs r1, #0xf0
	ands r0, r1
	adds r0, #1
	ldr r1, .L080F5244
	adds r2, r2, r1
	strb r0, [r2]
.L080F5236:
	movs r0, #1
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
.L080F5240: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080F5244: .4byte 0x000018BB

	thumb_func_start sub_080F5248
sub_080F5248: @ 0x080F5248
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F524C
sub_080F524C: @ 0x080F524C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F5250
sub_080F5250: @ 0x080F5250
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F5254
sub_080F5254: @ 0x080F5254
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	ldr r0, [r0]
	bl sub_080F3F14
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r0, sb
	ldr r6, [r0, #4]
	movs r5, #0
	str r5, [r0, #0xc]
	movs r1, #1
	rsbs r1, r1, #0
	mov r8, r1
	str r1, [r0, #8]
	adds r0, r6, #0
	bl sub_080EFAB0
	mov r0, sb
	str r5, [r0, #0xc]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x54
	bne .L080F5294
	subs r0, r6, #1
	cmp r0, #1
	bls .L080F5294
	b .L080F53E0
.L080F5294:
	cmp r4, #0x5e
	bne .L080F529E
	cmp r6, #0
	beq .L080F529E
	b .L080F53E0
.L080F529E:
	adds r0, r6, #0
	bl sub_080C0818
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	bne .L080F52B2
	b .L080F53C8
.L080F52B2:
	cmp r6, #3
	ble .L080F52B8
	b .L080F53E0
.L080F52B8:
	bl sub_080F3F44
	lsls r1, r0, #0x10
	lsrs r7, r1, #0x10
	movs r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq .L080F5316
	mov r4, r8
	adds r0, r6, #0
	bl sub_080C06BC
	adds r5, r0, #0
	movs r0, #4
	ands r0, r7
	cmp r0, #0
	beq .L080F52E8
	cmp r5, #2
	bne .L080F52E8
	movs r0, #5
	rsbs r0, r0, #0
	bl sub_080F3F58
	movs r4, #0xe0
.L080F52E8:
	movs r0, #8
	ands r0, r7
	cmp r0, #0
	beq .L080F5302
	cmp r4, #0
	bge .L080F5306
	cmp r5, #0
	bne .L080F5302
	movs r0, #9
	rsbs r0, r0, #0
	bl sub_080F3F58
	movs r4, #0xf4
.L080F5302:
	cmp r4, #0
	blt .L080F5316
.L080F5306:
	adds r0, r4, #0
	bl sub_080F3E38
	movs r0, #0x9c
	lsls r0, r0, #1
	mov r1, sb
	str r0, [r1, #8]
	b .L080F53E0
.L080F5316:
	bl sub_080F3F44
	movs r1, #0x80
	lsls r1, r1, #4
	ands r1, r0
	cmp r1, #0
	beq .L080F5344
	ldr r0, .L080F533C
	mov r1, sb
	str r0, [r1, #8]
	cmp r6, #0xf
	bgt .L080F5332
	adds r0, #1
	str r0, [r1, #8]
.L080F5332:
	ldr r0, .L080F5340
	bl sub_080F3F58
	b .L080F53E0
	.byte 0x00, 0x00
.L080F533C: .4byte 0x00000153
.L080F5340: .4byte 0xFFFFF7FF
.L080F5344:
	adds r0, r6, #0
	bl sub_080C0F8C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r4, r0, #1
	cmp r4, #0
	ble .L080F53E0
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080C0FA4
	adds r0, r4, #0
	bl sub_080C1098
	adds r1, r0, #0
	adds r0, r6, #0
	bl sub_080C0F70
	movs r0, #0
	mov r8, r0
	movs r7, #0
	movs r4, #0
.L080F5372:
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080C0F64
	adds r5, r0, #0
	cmp r5, r7
	ble .L080F5384
	adds r7, r5, #0
	mov r8, r4
.L080F5384:
	adds r4, #1
	cmp r4, #5
	ble .L080F5372
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r6, #0
	mov r1, r8
	bl sub_080C0EC0
	adds r0, r6, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	ldr r0, .L080F53BC
	mov r1, sb
	str r0, [r1, #8]
	ldr r0, .L080F53C0
	bl sub_080EDA7C
	ldr r1, .L080F53C4
	adds r0, r6, #0
	bl sub_080C08BC
	b .L080F53D6
	.byte 0x00, 0x00
.L080F53BC: .4byte 0x00000119
.L080F53C0: .4byte 0x0000FFFF
.L080F53C4: .4byte 0x0000EFFF
.L080F53C8:
	ldr r0, .L080F53EC
	mov r1, sb
	str r0, [r1, #8]
	adds r0, r6, #0
	adds r1, r2, #0
	bl sub_080C08E8
.L080F53D6:
	bl sub_080C6FD8
	movs r0, #1
	mov r1, sb
	str r0, [r1, #0xc]
.L080F53E0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F53EC: .4byte 0x0000039A

	thumb_func_start sub_080F53F0
sub_080F53F0: @ 0x080F53F0
	push {lr}
	ldr r0, [r0, #4]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_080EFDA4
	pop {r0}
	bx r0

	thumb_func_start sub_080F5400
sub_080F5400: @ 0x080F5400
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	bl sub_080EFAB0
	ldr r0, [r4]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	cmp r1, #0
	bne .L080F5422
	ldr r0, [r4]
	ldr r1, [r4, #0x18]
	bl sub_080F4D2C
.L080F5422:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F5428
sub_080F5428: @ 0x080F5428
	push {lr}
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #8
	bl sub_080F4C90
	pop {r0}
	bx r0

	thumb_func_start sub_080F5438
sub_080F5438: @ 0x080F5438
	push {lr}
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0x10
	bl sub_080F4C90
	pop {r0}
	bx r0

	thumb_func_start sub_080F5448
sub_080F5448: @ 0x080F5448
	push {lr}
	ldr r0, [r0]
	movs r1, #9
	bl sub_080C35C4
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F5458
sub_080F5458: @ 0x080F5458
	push {r4, lr}
	ldr r4, [r0]
	adds r0, r4, #0
	bl sub_080F4104
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	bl sub_080C08F8
	movs r0, #1
	rsbs r0, r0, #0
	bl sub_08126834
	bl sub_080ED9F4
	cmp r0, #0
	bne .L080F5484
	movs r0, #0x80
	lsls r0, r0, #2
	bl sub_080ED90C
.L080F5484:
	bl sub_080E760C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F5490
sub_080F5490: @ 0x080F5490
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0xf
	ble .L080F54EC
	bl sub_080C2244
	movs r1, #7
	ands r1, r0
	cmp r1, #0
	beq .L080F54EC
	movs r1, #0
	ldr r0, [r4]
	cmp r0, #0x13
	ble .L080F54B0
	movs r1, #1
.L080F54B0:
	adds r0, r1, #0
	bl sub_080EDA24
	adds r5, r0, #0
	bl Battle_IsTwoSided
	movs r1, #8
	cmp r0, #0
	beq .L080F54C4
	movs r1, #4
.L080F54C4:
	cmp r5, r1
	bge .L080F54EC
	ldr r0, [r4]
	movs r1, #1
	bl sub_080EF224
	cmp r0, #0
	beq .L080F54EC
	ldr r0, [r4]
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	ldr r0, .L080F54E8
	b .L080F54F4
	.byte 0x00, 0x00
.L080F54E8: .4byte 0x00000139
.L080F54EC:
	movs r0, #0
	str r0, [r4, #0xc]
	movs r0, #0x8e
	lsls r0, r0, #1
.L080F54F4:
	str r0, [r4, #8]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080F54FC
sub_080F54FC: @ 0x080F54FC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, [r5]
	movs r0, #1
	movs r2, #1
	bl Battle_AddModifierClamped
	adds r4, r0, #0
	ldr r1, [r5]
	movs r0, #3
	movs r2, #1
	bl Battle_AddModifierClamped
	cmp r4, #0
	beq .L080F5526
	cmp r0, #0
	beq .L080F5526
	movs r0, #0x96
	str r0, [r5, #8]
	movs r0, #0
	str r0, [r5, #0xc]
.L080F5526:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080F552C
sub_080F552C: @ 0x080F552C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, [r5]
	movs r0, #2
	movs r2, #1
	bl Battle_AddModifierClamped
	adds r4, r0, #0
	ldr r1, [r5]
	movs r0, #4
	movs r2, #1
	bl Battle_AddModifierClamped
	cmp r4, #0
	beq .L080F5556
	cmp r0, #0
	beq .L080F5556
	movs r0, #0x96
	str r0, [r5, #8]
	movs r0, #0
	str r0, [r5, #0xc]
.L080F5556:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080F555C
sub_080F555C: @ 0x080F555C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl sub_080C2244
	movs r1, #0xf0
	ands r0, r1
	ldr r1, .L080F5580
	str r1, [r6, #0x18]
	movs r1, #0
	str r1, [r6, #0xc]
	cmp r0, #0
	bne .L080F5584
	ldr r0, [r6]
	movs r1, #0x10
	bl sub_080C08F8
	b .L080F55EE
	.byte 0x00, 0x00
.L080F5580: .4byte 0x0000FFFF
.L080F5584:
	ldr r0, [r6]
	cmp r0, #0xf
	ble .L080F55C2
	movs r5, #0
.L080F558C:
	adds r0, r5, #0
	bl sub_080F40EC
	adds r4, r0, #0
	cmp r4, #0
	blt .L080F55BA
	bl sub_080C0830
	cmp r0, #0
	bne .L080F55BA
	adds r0, r4, #0
	movs r1, #0x10
	bl sub_080C08F8
	adds r0, r4, #0
	bl sub_080C0818
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0
	beq .L080F55BA
	movs r0, #1
	str r0, [r6, #0xc]
.L080F55BA:
	adds r5, #1
	cmp r5, #5
	bls .L080F558C
	b .L080F55EE
.L080F55C2:
	movs r5, #0x10
.L080F55C4:
	adds r0, r5, #0
	bl sub_080C0A00
	cmp r0, #0
	beq .L080F55E8
	adds r0, r5, #0
	movs r1, #0x10
	bl sub_080C08F8
	adds r0, r5, #0
	bl sub_080C0818
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0
	beq .L080F55E8
	movs r0, #1
	str r0, [r6, #0xc]
.L080F55E8:
	adds r5, #1
	cmp r5, #0x17
	bls .L080F55C4
.L080F55EE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080F55F4
sub_080F55F4: @ 0x080F55F4
.L080F55F4:
	push {r4, r5, lr}
	adds r4, r1, #0
	bl sub_080C06BC
	adds r5, r0, #0
	adds r0, r4, #0
	bl sub_080C06BC
	movs r1, #0
	cmp r0, #1
	beq .L080F560E
	cmp r0, r5
	bne .L080F5610
.L080F560E:
	movs r1, #1
.L080F5610:
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080F5618
sub_080F5618: @ 0x080F5618
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4]
	ldr r1, [r4, #4]
	bl sub_080F55F4
	cmp r0, #1
	bne .L080F562C
	movs r0, #0
	b .L080F565A
.L080F562C:
	ldr r0, [r4]
	cmp r0, #0xf
	bgt .L080F563A
	ldr r0, [r4, #4]
	cmp r0, #0xf
	ble .L080F5640
	b .L080F564E
.L080F563A:
	ldr r0, [r4, #4]
	cmp r0, #0xf
	ble .L080F564E
.L080F5640:
	bl sub_080F401C
	cmp r0, #0
	bge .L080F564A
	adds r0, #7
.L080F564A:
	asrs r0, r0, #3
	b .L080F565A
.L080F564E:
	bl sub_080F401C
	cmp r0, #0
	bge .L080F5658
	adds r0, #3
.L080F5658:
	asrs r0, r0, #2
.L080F565A:
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F5664
sub_080F5664: @ 0x080F5664
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_080EDAD0
	cmp r0, #0
	bne .L080F5688
	bl sub_080C2244
	adds r4, r0, #0
	movs r0, #3
	ands r4, r0
	cmp r4, #0
	bne .L080F5688
	movs r0, #0x40
	bl sub_080C1D00
	str r4, [r5, #0x18]
	str r4, [r5, #0xc]
.L080F5688:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F5690
sub_080F5690: @ 0x080F5690
	push {r4, r5, lr}
	ldr r5, [r0]
	ldr r1, .L080F5710
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	ldrh r0, [r4, #0x12]
	bl Demon_GetRecord
	ldrh r1, [r0, #2]
	movs r2, #0
	strh r1, [r4, #0x18]
	ldrh r1, [r0, #2]
	strh r1, [r4, #0x1a]
	ldrh r1, [r0, #4]
	strh r1, [r4, #0x1c]
	ldrh r0, [r0, #4]
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x10]
	bl sub_080E760C
	adds r0, r5, #0
	bl sub_080EFBFC
	cmp r0, #0
	beq .L080F56D2
	rsbs r1, r0, #0
	adds r0, r5, #0
	bl sub_080EFD14
.L080F56D2:
	adds r0, r5, #0
	bl sub_080EFD3C
	cmp r0, #0
	beq .L080F56E4
	rsbs r1, r0, #0
	adds r0, r5, #0
	bl sub_080EFD5C
.L080F56E4:
	adds r0, r5, #0
	bl sub_080EFD84
	cmp r0, #0
	beq .L080F56F6
	rsbs r1, r0, #0
	adds r0, r5, #0
	bl sub_080EFDA4
.L080F56F6:
	adds r0, r5, #0
	bl sub_080EFDCC
	cmp r0, #0
	beq .L080F5708
	rsbs r1, r0, #0
	adds r0, r5, #0
	bl sub_080EFDEC
.L080F5708:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F5710: .4byte 0xFFFF8000

	thumb_func_start sub_080F5714
sub_080F5714: @ 0x080F5714
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	cmp r0, #3
	bgt .L080F5722
	movs r0, #0
	b .L080F5750
.L080F5722:
	bl sub_080BFFF0
	cmp r0, #0
	bne .L080F5738
	ldr r0, [r4, #4]
	bl sub_080F401C
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	b .L080F5746
.L080F5738:
	ldr r0, [r4, #4]
	bl sub_080F401C
	cmp r0, #0
	bge .L080F5744
	adds r0, #3
.L080F5744:
	asrs r0, r0, #2
.L080F5746:
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x18]
	cmp r0, #0
	bne .L080F5752
	movs r0, #1
.L080F5750:
	str r0, [r4, #0x18]
.L080F5752:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080F5758
sub_080F5758: @ 0x080F5758
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0
	str r0, [r7, #0xc]
	movs r6, #0
.L080F5762:
	adds r0, r6, #0
	bl sub_080F40EC
	adds r4, r0, #0
	cmp r4, #0
	blt .L080F57E0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F57E0
	adds r0, r4, #0
	movs r1, #1
	bl sub_080C0E44
	cmp r0, #0x13
	bgt .L080F57E0
	cmp r0, #9
	ble .L080F57A8
	bl sub_080C2244
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0
	bne .L080F57E0
	adds r0, r4, #0
	bl sub_080C0818
	movs r5, #0x20
	adds r1, r5, #0
	ands r1, r0
	cmp r1, #0
	bne .L080F57E0
	adds r0, r4, #0
	movs r1, #0x20
	b .L080F57CA
.L080F57A8:
	bl sub_080C2244
	movs r1, #0xe0
	ands r1, r0
	cmp r1, #0
	bne .L080F57E0
	adds r0, r4, #0
	bl sub_080C0818
	movs r5, #0x80
	lsls r5, r5, #5
	adds r1, r5, #0
	ands r1, r0
	cmp r1, #0
	bne .L080F57E0
	adds r0, r4, #0
	adds r1, r5, #0
.L080F57CA:
	bl sub_080C08F8
	adds r0, r4, #0
	bl sub_080C0818
	adds r1, r5, #0
	ands r1, r0
	cmp r1, #0
	beq .L080F57E0
	movs r0, #1
	str r0, [r7, #0xc]
.L080F57E0:
	adds r6, #1
	cmp r6, #5
	bls .L080F5762
	ldr r0, .L080F57F0
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F57F0: .4byte 0x0000FFFF

	thumb_func_start sub_080F57F4
sub_080F57F4: @ 0x080F57F4
.L080F57F4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	movs r7, #0x64
	movs r0, #1
	rsbs r0, r0, #0
	mov r8, r0
	movs r6, #0
.L080F5810:
	adds r0, r6, #0
	bl sub_080F40EC
	adds r4, r0, #0
	cmp r4, #0
	blt .L080F5842
	bl sub_080C0830
	cmp r0, #0
	bne .L080F5842
	adds r0, r4, #0
	mov r1, sl
	bl sub_080C0E44
	adds r5, r0, #0
	cmp r7, r5
	ble .L080F5842
	adds r0, r4, #0
	mov r1, sb
	bl sub_080F3214
	cmp r0, #1
	bne .L080F5842
	adds r7, r5, #0
	mov r8, r4
.L080F5842:
	adds r6, #1
	cmp r6, #5
	bls .L080F5810
	mov r0, r8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080F5858
sub_080F5858: @ 0x080F5858
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0
	movs r1, #0x20
	bl sub_080F57F4
	adds r4, r0, #0
	movs r0, #0
	str r0, [r5, #0xc]
	subs r0, #1
	cmp r4, r0
	beq .L080F5894
	adds r0, r4, #0
	bl sub_080C0818
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0
	bne .L080F5894
	movs r0, #0x20
	bl sub_080EDA7C
	str r4, [r5, #4]
	ldr r0, .L080F5890
	str r0, [r5, #0x18]
	movs r0, #1
	str r0, [r5, #0xc]
	b .L080F5898
.L080F5890: .4byte 0x0000FFFF
.L080F5894:
	movs r0, #0
	str r0, [r5, #0x18]
.L080F5898:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F58A0
sub_080F58A0: @ 0x080F58A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0x80
	lsls r6, r6, #5
	movs r0, #4
	adds r1, r6, #0
	bl sub_080F57F4
	adds r4, r0, #0
	movs r0, #0
	str r0, [r5, #0xc]
	subs r0, #1
	cmp r4, r0
	beq .L080F58E0
	adds r0, r4, #0
	bl sub_080C0818
	adds r1, r6, #0
	ands r1, r0
	cmp r1, #0
	bne .L080F58E0
	adds r0, r6, #0
	bl sub_080EDA7C
	str r4, [r5, #4]
	ldr r0, .L080F58DC
	str r0, [r5, #0x18]
	movs r0, #1
	str r0, [r5, #0xc]
	b .L080F58E4
.L080F58DC: .4byte 0x0000FFFF
.L080F58E0:
	movs r0, #0
	str r0, [r5, #0x18]
.L080F58E4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F58EC
sub_080F58EC: @ 0x080F58EC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0x80
	lsls r6, r6, #6
	movs r0, #5
	adds r1, r6, #0
	bl sub_080F57F4
	adds r4, r0, #0
	movs r0, #0
	str r0, [r5, #0xc]
	subs r0, #1
	cmp r4, r0
	beq .L080F592C
	adds r0, r4, #0
	bl sub_080C0818
	adds r1, r6, #0
	ands r1, r0
	cmp r1, #0
	bne .L080F592C
	adds r0, r6, #0
	bl sub_080EDA7C
	str r4, [r5, #4]
	ldr r0, .L080F5928
	str r0, [r5, #0x18]
	movs r0, #1
	str r0, [r5, #0xc]
	b .L080F5930
.L080F5928: .4byte 0x0000FFFF
.L080F592C:
	movs r0, #0
	str r0, [r5, #0x18]
.L080F5930:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F5938
sub_080F5938: @ 0x080F5938
.L080F5938:
	push {lr}
	movs r1, #0x80
	lsls r1, r1, #8
	movs r0, #2
	bl sub_080F57F4
	pop {r1}
	bx r1

	thumb_func_start sub_080F5948
sub_080F5948: @ 0x080F5948
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_080F5938
	adds r4, r0, #0
	movs r0, #0
	str r0, [r5, #0xc]
	subs r0, #1
	cmp r4, r0
	beq .L080F597A
	adds r0, r4, #0
	bl sub_080C0818
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	bne .L080F597A
	adds r0, r2, #0
	bl sub_080EDA7C
	str r4, [r5, #4]
	movs r0, #1
	str r0, [r5, #0xc]
.L080F597A:
	ldr r0, .L080F5984
	str r0, [r5, #0x18]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080F5984: .4byte 0x0000FFFF

	thumb_func_start sub_080F5988
sub_080F5988: @ 0x080F5988
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0x80
	lsls r6, r6, #8
	movs r0, #1
	adds r1, r6, #0
	bl sub_080F57F4
	adds r4, r0, #0
	movs r0, #0
	str r0, [r5, #0xc]
	subs r0, #1
	cmp r4, r0
	beq .L080F59BE
	adds r0, r4, #0
	bl sub_080C0818
	adds r1, r6, #0
	ands r1, r0
	cmp r1, #0
	bne .L080F59BE
	adds r0, r6, #0
	bl sub_080EDA7C
	str r4, [r5, #4]
	movs r0, #1
	str r0, [r5, #0xc]
.L080F59BE:
	ldr r0, .L080F59C8
	str r0, [r5, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080F59C8: .4byte 0x0000FFFF

	thumb_func_start sub_080F59CC
sub_080F59CC: @ 0x080F59CC
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C3168
	adds r1, r0, #0
	cmp r1, #0
	beq .L080F59EE
	lsrs r0, r1, #0x1f
	adds r0, r1, r0
	asrs r1, r0, #1
	cmp r1, #0
	bne .L080F59E6
	movs r1, #1
.L080F59E6:
	rsbs r0, r1, #0
	bl sub_080C3114
	b .L080F59F0
.L080F59EE:
	str r1, [r4, #0xc]
.L080F59F0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F59F8
sub_080F59F8: @ 0x080F59F8
	push {r4, lr}
	adds r3, r0, #0
	ldr r2, [r3]
	ldr r0, .L080F5A08
	cmp r2, #0xf
	bgt .L080F5A10
	ldr r1, .L080F5A0C
	b .L080F5A12
.L080F5A08: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F5A0C: .4byte 0x000011AC
.L080F5A10:
	ldr r1, .L080F5A20
.L080F5A12:
	adds r4, r0, r1
	ldrh r1, [r4]
	ldr r0, .L080F5A24
	cmp r1, r0
	bne .L080F5A28
	strh r2, [r4]
	b .L080F5A30
.L080F5A20: .4byte 0x000011AE
.L080F5A24: .4byte 0x0000FFFF
.L080F5A28:
	movs r0, #0x7e
	str r0, [r3, #8]
	movs r0, #0
	str r0, [r3, #0xc]
.L080F5A30:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F5A38
sub_080F5A38: @ 0x080F5A38
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r5, [r6]
	bl sub_080C2244
	adds r4, r0, #0
	movs r0, #7
	ands r4, r0
	bl sub_080ED9F4
	cmp r0, #1
	ble .L080F5A58
	cmp r4, #0
	beq .L080F5A62
.L080F5A58:
	movs r0, #0x7e
	str r0, [r6, #8]
	movs r0, #0
	str r0, [r6, #0xc]
	b .L080F5B26
.L080F5A62:
	movs r0, #0x10
	mov r8, r0
.L080F5A66:
	cmp r8, r5
	beq .L080F5B14
	mov r0, r8
	bl sub_080C0A00
	cmp r0, #0
	beq .L080F5B14
	adds r0, r5, #0
	bl sub_080C07E0
	adds r4, r0, #0
	mov r0, r8
	bl sub_080C07E0
	lsls r4, r4, #0x10
	lsls r0, r0, #0x10
	cmp r4, r0
	bne .L080F5B14
	adds r0, r5, #0
	bl sub_080F401C
	adds r4, r0, #0
	mov r0, r8
	bl sub_080F401C
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	adds r0, r5, #0
	bl sub_080F4070
	adds r4, r0, #0
	mov r0, r8
	bl sub_080F4070
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x10
	lsls r4, r7, #0x10
	asrs r4, r4, #0x10
	adds r0, r5, #0
	bl sub_080F4038
	cmp r4, r0
	ble .L080F5ACA
	adds r0, r5, #0
	bl sub_080F4038
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L080F5ACA:
	lsls r4, r6, #0x10
	asrs r4, r4, #0x10
	adds r0, r5, #0
	bl sub_080F40A8
	cmp r4, r0
	ble .L080F5AE2
	adds r0, r5, #0
	bl sub_080F40A8
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080F5AE2:
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	adds r0, r5, #0
	bl sub_080F4054
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	adds r0, r5, #0
	bl sub_080F408C
	mov r0, r8
	bl sub_080F4104
	mov r0, r8
	movs r1, #0x80
	lsls r1, r1, #8
	bl sub_080C08F8
	movs r0, #1
	rsbs r0, r0, #0
	bl sub_08126834
	bl sub_080E760C
	b .L080F5B26
.L080F5B14:
	movs r0, #1
	add r8, r0
	mov r0, r8
	cmp r0, #0x17
	ble .L080F5A66
	movs r0, #0
	str r0, [r6, #0xc]
	movs r0, #0x7e
	str r0, [r6, #8]
.L080F5B26:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080F5B30
sub_080F5B30: @ 0x080F5B30
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080F51D4
	ldr r0, [r4, #0xc]
	cmp r0, #1
	bne .L080F5B42
	ldr r0, .L080F5B68
	str r0, [r4, #8]
.L080F5B42:
	ldr r4, [r4]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	bl sub_080C08F8
	adds r0, r4, #0
	movs r1, #0
	bl sub_080F4054
	subs r0, r4, #4
	cmp r0, #0xb
	bhi .L080F5B62
	adds r0, r4, #0
	bl sub_080F4190
.L080F5B62:
	pop {r4}
	pop {r0}
	bx r0
.L080F5B68: .4byte 0x00000389

	thumb_func_start sub_080F5B6C
sub_080F5B6C: @ 0x080F5B6C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r5, r0, #1
	ldr r0, [r4]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	cmp r1, #0
	bne .L080F5B90
	ldr r0, [r4]
	adds r1, r5, #0
	bl sub_080F4D2C
.L080F5B90:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F5B98
sub_080F5B98: @ 0x080F5B98
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L080F5BFA
	ldr r4, [r5, #4]
	cmp r4, #3
	ble .L080F5BFA
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F5BFA
	subs r0, r4, #4
	cmp r0, #0xb
	bhi .L080F5BCC
	adds r0, r4, #0
	bl sub_080F4190
	bl sub_080C366C
	b .L080F5BFE
.L080F5BCC:
	adds r0, r4, #0
	bl sub_080F4104
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	bl sub_080C08F8
	movs r0, #1
	rsbs r0, r0, #0
	bl sub_08126834
	bl sub_080ED9F4
	cmp r0, #0
	bne .L080F5BF4
	movs r0, #0x80
	lsls r0, r0, #2
	bl sub_080ED90C
.L080F5BF4:
	bl sub_080E760C
	b .L080F5BFE
.L080F5BFA:
	movs r0, #0
	str r0, [r5, #0xc]
.L080F5BFE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080F5C04
sub_080F5C04: @ 0x080F5C04
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, [r5]
	adds r0, r4, #0
	bl sub_080F3F14
	adds r6, r0, #0
	bl sub_080C2244
	movs r1, #0xf
	ands r1, r0
	cmp r1, #0
	beq .L080F5C5E
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	adds r0, r4, #0
	bl sub_080C0A24
	cmp r0, #0
	bne .L080F5C66
	adds r0, r4, #0
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	cmp r1, #0
	bne .L080F5C66
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r0, [r0, #3]
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r0, r4, #0
	bl sub_080F4D2C
	movs r0, #1
	b .L080F5C68
.L080F5C5E:
	adds r0, r4, #0
	movs r1, #0x40
	bl sub_080C08E8
.L080F5C66:
	movs r0, #0
.L080F5C68:
	str r0, [r5, #0xc]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080F5C70
sub_080F5C70: @ 0x080F5C70
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x18]
	asrs r1, r1, #1
	ldr r0, [r4, #4]
	rsbs r1, r1, #0
	bl sub_080C0C14
	movs r0, #0
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F5C8C
sub_080F5C8C: @ 0x080F5C8C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F5C90
sub_080F5C90: @ 0x080F5C90
.L080F5C90:
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r0, r1, #0
	movs r1, #0xc
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	adds r2, r0, #0
	subs r2, #0x80
	cmp r2, #0
	blt .L080F5CC4
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #8]
	movs r0, #1
	str r0, [r4, #0xc]
	str r2, [r4, #0x10]
	ldr r1, .L080F5CCC
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
.L080F5CC4:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080F5CCC: .4byte gUnknown_0876FA58

	thumb_func_start sub_080F5CD0
sub_080F5CD0: @ 0x080F5CD0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #4]
	adds r0, r4, #0
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	cmp r1, #0
	beq .L080F5CF2
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C0290
	b .L080F5D1C
.L080F5CF2:
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F5D1C
	adds r0, r4, #0
	bl sub_080C0A24
	cmp r0, #0
	bne .L080F5D1C
	adds r0, r4, #0
	bl sub_080F4038
	cmp r0, #0
	bge .L080F5D12
	adds r0, #3
.L080F5D12:
	asrs r1, r0, #2
	adds r0, r4, #0
	bl sub_080C0B30
	b .L080F5D20
.L080F5D1C:
	movs r0, #0
	str r0, [r5, #0xc]
.L080F5D20:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F5D28
sub_080F5D28: @ 0x080F5D28
.L080F5D28:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	ldr r6, [r5, #4]
	adds r0, r6, #0
	bl sub_080F4038
	adds r7, r0, #0
	adds r0, r6, #0
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r4, #0
	beq .L080F5D64
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C0290
	movs r0, #0
	str r0, [r5, #0xc]
	b .L080F5DF6
.L080F5D64:
	adds r0, r6, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F5DF4
	mov r0, r8
	cmp r0, #4
	bne .L080F5D9C
	bl sub_080C2244
	adds r4, r0, #0
	adds r0, r6, #0
	bl sub_080F401C
	adds r5, r0, #0
	adds r0, r6, #0
	bl sub_080C0F8C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #2
	bl sub_080C1F94
	movs r1, #7
	ands r1, r4
	adds r1, #1
	lsls r1, r1, #2
	b .L080F5DC6
.L080F5D9C:
	bl sub_080C2244
	adds r4, r0, #0
	adds r0, r6, #0
	bl sub_080F401C
	adds r5, r0, #0
	adds r0, r6, #0
	bl sub_080C0F8C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #2
	bl sub_080C1F94
	movs r2, #7
	ands r2, r4
	adds r2, #1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
.L080F5DC6:
	adds r1, r1, r5
	adds r4, r1, r0
	ldr r0, .L080F5DF0
	cmp r4, r0
	bgt .L080F5DD6
	lsls r0, r7, #1
	cmp r4, r0
	ble .L080F5DE4
.L080F5DD6:
	lsrs r0, r7, #0x1f
	adds r0, r7, r0
	asrs r4, r0, #1
	adds r0, r6, #0
	mov r1, r8
	bl sub_080C08E8
.L080F5DE4:
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080F4054
	b .L080F5DF6
	.byte 0x00, 0x00
.L080F5DF0: .4byte 0x000003E6
.L080F5DF4:
	str r4, [r5, #0xc]
.L080F5DF6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080F5E00
sub_080F5E00: @ 0x080F5E00
	push {lr}
	movs r1, #4
	bl sub_080F5D28
	pop {r0}
	bx r0

	thumb_func_start sub_080F5E0C
sub_080F5E0C: @ 0x080F5E0C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F5E10
sub_080F5E10: @ 0x080F5E10
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r6, #4]
	movs r5, #0
	adds r0, r4, #0
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	cmp r1, #0
	beq .L080F5E34
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C0290
	b .L080F5ECE
.L080F5E34:
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F5ECA
	adds r0, r4, #0
	bl sub_080C0A24
	cmp r0, #0
	bne .L080F5E82
	bl sub_080C2244
	adds r5, r0, #0
	movs r0, #7
	ands r5, r0
	adds r0, r4, #0
	bl sub_080F4038
	movs r1, #8
	bl sub_080C1F94
	adds r5, r5, r0
	adds r0, r4, #0
	bl sub_080F401C
	adds r5, r5, r0
	adds r0, r4, #0
	bl sub_080F4038
	cmp r5, r0
	ble .L080F5E7A
	adds r0, r4, #0
	bl sub_080F4038
	adds r5, r0, #0
.L080F5E7A:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080F4054
.L080F5E82:
	adds r0, r4, #0
	bl sub_080C0A50
	cmp r0, #0
	bne .L080F5ECA
	bl sub_080C2244
	adds r5, r0, #0
	movs r0, #0xe
	ands r5, r0
	adds r0, r4, #0
	bl sub_080C0F8C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #4
	bl sub_080C1F94
	adds r5, r5, r0
	adds r0, r4, #0
	bl sub_080F4070
	adds r5, r5, r0
	adds r0, r4, #0
	bl sub_080F40A8
	cmp r5, r0
	ble .L080F5EC2
	adds r0, r4, #0
	bl sub_080F40A8
	adds r5, r0, #0
.L080F5EC2:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080F408C
.L080F5ECA:
	cmp r5, #0
	bne .L080F5ED0
.L080F5ECE:
	str r5, [r6, #0xc]
.L080F5ED0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F5ED8
sub_080F5ED8: @ 0x080F5ED8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r6, #4]
	movs r5, #0
	adds r0, r4, #0
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	cmp r1, #0
	beq .L080F5EFC
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C0290
	b .L080F5F48
.L080F5EFC:
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F5F44
	adds r0, r4, #0
	bl sub_080C0A24
	cmp r0, #0
	bne .L080F5F18
	adds r0, r4, #0
	bl sub_080C0A7C
	movs r5, #1
.L080F5F18:
	adds r0, r4, #0
	bl sub_080C0A50
	cmp r0, #0
	bne .L080F5F2A
	adds r0, r4, #0
	bl sub_080C0AA8
	adds r5, #1
.L080F5F2A:
	adds r0, r4, #0
	bl sub_080C0818
	lsls r0, r0, #0x10
	ldr r1, .L080F5F50
	ands r1, r0
	cmp r1, #0
	beq .L080F5F44
	ldr r1, .L080F5F54
	adds r0, r4, #0
	bl sub_080C08BC
	adds r5, #1
.L080F5F44:
	cmp r5, #0
	bne .L080F5F4A
.L080F5F48:
	str r5, [r6, #0xc]
.L080F5F4A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080F5F50: .4byte 0x73FE0000
.L080F5F54: .4byte 0x00008C01

	thumb_func_start sub_080F5F58
sub_080F5F58: @ 0x080F5F58
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, [r5, #4]
	adds r0, r4, #0
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r6, #0x80
	lsls r6, r6, #8
	ands r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq .L080F5FC8
	bl sub_080C2244
	movs r1, #0x3f
	ands r1, r0
	cmp r1, #0
	beq .L080F5FBA
	adds r0, r4, #0
	movs r1, #1
	bl sub_080C08BC
	adds r0, r4, #0
	bl sub_080F4038
	cmp r0, #0
	bge .L080F5F96
	adds r0, #7
.L080F5F96:
	asrs r1, r0, #3
	cmp r1, #0
	bne .L080F5F9E
	movs r1, #1
.L080F5F9E:
	adds r0, r4, #0
	bl sub_080F4054
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	movs r0, #0x92
	lsls r0, r0, #1
	str r0, [r5, #8]
	b .L080F5FCA
.L080F5FBA:
	adds r0, r4, #0
	adds r1, r6, #0
	bl sub_080C08E8
	movs r0, #0x95
	str r0, [r5, #8]
	b .L080F5FCA
.L080F5FC8:
	str r0, [r5, #0xc]
.L080F5FCA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080F5FD0
sub_080F5FD0: @ 0x080F5FD0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #4]
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	beq .L080F6008
	adds r0, r4, #0
	movs r1, #1
	bl sub_080C08BC
	adds r0, r4, #0
	bl sub_080C0A7C
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	ldr r0, .L080F6004
	str r0, [r5, #8]
	b .L080F600A
	.byte 0x00, 0x00
.L080F6004: .4byte 0x00000125
.L080F6008:
	str r0, [r5, #0xc]
.L080F600A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080F6010
sub_080F6010: @ 0x080F6010
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F6014
sub_080F6014: @ 0x080F6014
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r4, [r6, #4]
	movs r7, #0
	movs r0, #0
	mov r8, r0
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F607A
	ldr r0, .L080F609C
	ldr r1, [r6, #0x10]
	subs r1, #8
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r5, [r1]
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080C0F64
	cmp r0, #0x27
	bgt .L080F605A
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl sub_080C0EC0
	adds r0, r4, #0
	bl sub_080BFD94
	movs r0, #1
	mov r8, r0
.L080F605A:
	adds r0, r4, #0
	bl sub_080C0A24
	cmp r0, #0
	bne .L080F607A
	adds r0, r4, #0
	bl sub_080C0A7C
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F40C4
	movs r7, #1
.L080F607A:
	mov r0, r8
	cmp r0, #0
	bne .L080F608E
	cmp r7, #1
	bne .L080F6088
	ldr r0, .L080F60A0
	str r0, [r6, #8]
.L080F6088:
	cmp r7, #0
	bne .L080F608E
	str r7, [r6, #0xc]
.L080F608E:
	bl sub_080C65C8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080F609C: .4byte gUnknown_0876FB2C
.L080F60A0: .4byte 0x0000011F

	thumb_func_start sub_080F60A4
sub_080F60A4: @ 0x080F60A4
.L080F60A4:
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r5, [r6, #4]
	movs r0, #0
	str r0, [r6, #0xc]
	adds r0, r5, #0
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r4, #0
	beq .L080F60CA
	movs r0, #3
	str r0, [r6, #0xc]
	b .L080F615A
.L080F60CA:
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080F6158
	adds r0, r5, #0
	bl sub_080C06BC
	cmp r0, r7
	bne .L080F6114
	adds r0, r5, #0
	bl sub_080C0A24
	cmp r0, #0
	bne .L080F60EE
	adds r0, r5, #0
	bl sub_080C0A7C
.L080F60EE:
	adds r0, r5, #0
	bl sub_080C0818
	lsls r0, r0, #0x10
	ldr r1, .L080F610C
	ands r1, r0
	cmp r1, #0
	beq .L080F6106
	ldr r1, .L080F6110
	adds r0, r5, #0
	bl sub_080C08BC
.L080F6106:
	movs r0, #1
	str r0, [r6, #0xc]
	b .L080F615A
.L080F610C: .4byte 0x33FE0000
.L080F6110: .4byte 0x0000CC01
.L080F6114:
	adds r0, r5, #0
	bl sub_080C06BC
	cmp r0, #1
	bne .L080F6128
	adds r0, r5, #0
	bl sub_080F401C
	movs r1, #8
	b .L080F6130
.L080F6128:
	adds r0, r5, #0
	bl sub_080F401C
	movs r1, #2
.L080F6130:
	bl sub_080C1F94
	adds r4, r0, #0
	str r4, [r6, #0x18]
	adds r0, r5, #0
	bl sub_080F401C
	subs r4, r0, r4
	cmp r4, #0
	ble .L080F614E
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080F4054
	b .L080F6152
.L080F614E:
	movs r0, #0
	str r0, [r6, #0x18]
.L080F6152:
	movs r0, #2
	str r0, [r6, #0xc]
	b .L080F615A
.L080F6158:
	str r4, [r6, #0xc]
.L080F615A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080F6160
sub_080F6160: @ 0x080F6160
	push {lr}
	movs r1, #0
	bl sub_080F60A4
	pop {r0}
	bx r0

	thumb_func_start sub_080F616C
sub_080F616C: @ 0x080F616C
	push {lr}
	movs r1, #2
	bl sub_080F60A4
	pop {r0}
	bx r0

	thumb_func_start sub_080F6178
sub_080F6178: @ 0x080F6178
.L080F6178:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	bl sub_080F3F44
	ands r0, r4
	cmp r0, #0
	beq .L080F6192
	movs r0, #0x96
	str r0, [r5, #8]
	b .L080F619A
.L080F6192:
	adds r0, r4, #0
	bl sub_080F3F74
	str r6, [r5, #8]
.L080F619A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080F61A0
sub_080F61A0: @ 0x080F61A0
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F61A4
sub_080F61A4: @ 0x080F61A4
	push {lr}
	movs r2, #0x98
	lsls r2, r2, #1
	movs r1, #2
	bl sub_080F6178
	pop {r0}
	bx r0

	thumb_func_start sub_080F61B4
sub_080F61B4: @ 0x080F61B4
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F61B8
sub_080F61B8: @ 0x080F61B8
	push {lr}
	movs r2, #0x99
	lsls r2, r2, #1
	movs r1, #8
	bl sub_080F6178
	pop {r0}
	bx r0

	thumb_func_start sub_080F61C8
sub_080F61C8: @ 0x080F61C8
	push {lr}
	ldr r2, .L080F61D8
	movs r1, #0x10
	bl sub_080F6178
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F61D8: .4byte 0x00000133

	thumb_func_start sub_080F61DC
sub_080F61DC: @ 0x080F61DC
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F61E0
sub_080F61E0: @ 0x080F61E0
	push {lr}
	ldr r2, .L080F61F0
	movs r1, #0x40
	bl sub_080F6178
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080F61F0: .4byte 0x00000135

	thumb_func_start sub_080F61F4
sub_080F61F4: @ 0x080F61F4
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F61F8
sub_080F61F8: @ 0x080F61F8
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F61FC
sub_080F61FC: @ 0x080F61FC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, .L080F625C
	bl sub_080EDAD0
	cmp r0, #0
	bne .L080F6264
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L080F6264
	ldr r0, [r5]
	ldr r2, .L080F6260
	adds r1, r4, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl sub_080EFFF8
	adds r4, r0, #0
	bl sub_080F4104
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	bl sub_080C08F8
	movs r6, #1
	rsbs r6, r6, #0
	adds r0, r6, #0
	bl sub_08126834
	bl sub_080ED9F4
	cmp r0, #0
	bne .L080F6250
	movs r0, #0x80
	lsls r0, r0, #2
	bl sub_080ED90C
.L080F6250:
	bl sub_080E760C
	str r4, [r5, #4]
	str r6, [r5, #8]
	b .L080F6268
	.byte 0x00, 0x00
.L080F625C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F6260: .4byte 0x00000F66
.L080F6264:
	movs r0, #0
	str r0, [r5, #0xc]
.L080F6268:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F6270
sub_080F6270: @ 0x080F6270
	movs r1, #0
	str r1, [r0, #0xc]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080F6278
sub_080F6278: @ 0x080F6278
.L080F6278:
	push {r4, lr}
	ldr r4, .L080F6290
	bl sub_080C2244
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrh r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
.L080F6290: .4byte gUnknown_0876FB44

	thumb_func_start sub_080F6294
sub_080F6294: @ 0x080F6294
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r5, .L080F6354
	bl sub_080EDAD0
	cmp r0, #0
	bne .L080F6368
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L080F6368
	bl sub_080C2244
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	bne .L080F6368
	movs r4, #0x10
	movs r6, #0xfb
.L080F62C0:
	adds r0, r4, #0
	bl sub_080C0A00
	cmp r0, #0
	beq .L080F62FE
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r5, r1
	str r6, [r0]
	ldr r2, .L080F6358
	adds r0, r5, r2
	str r6, [r0]
	adds r0, r4, #0
	subs r0, #0x10
	movs r1, #0xfb
	bl Battle_InitEnemyUnit
	adds r0, r4, #0
	bl sub_080F4038
	adds r1, r0, #0
	adds r0, r4, #0
	bl sub_080F4054
	adds r0, r4, #0
	bl sub_080F40A8
	adds r1, r0, #0
	adds r0, r4, #0
	bl sub_080F408C
.L080F62FE:
	adds r4, #1
	cmp r4, #0x17
	ble .L080F62C0
	bl Battle_IsTwoSided
	cmp r0, #0
	beq .L080F6322
	ldr r0, .L080F635C
	adds r1, r5, r0
	ldr r2, .L080F6360
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0
	bl sub_080ED938
.L080F6322:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r4, r5, r0
	ldrh r0, [r4]
	bl Demon_GetRecord
	adds r0, #0x21
	ldrb r0, [r0]
	bl sub_080EF8F8
	ldr r0, [r5, #4]
	bl Task_End
	ldrh r0, [r4]
	ldr r1, .L080F6364
	movs r2, #1
	bl sub_080E8C58
	bl sub_080E760C
	movs r0, #0xc9
	lsls r0, r0, #2
	str r0, [r7, #8]
	b .L080F6370
	.byte 0x00, 0x00
.L080F6354: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080F6358: .4byte 0x00000994
.L080F635C: .4byte 0x00000998
.L080F6360: .4byte 0x0000099A
.L080F6364: .4byte 0x0000FFFF
.L080F6368:
	movs r0, #0x7e
	str r0, [r7, #8]
	movs r0, #0
	str r0, [r7, #0xc]
.L080F6370:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080F6378
sub_080F6378: @ 0x080F6378
	push {lr}
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_080F5D28
	pop {r0}
	bx r0
	.byte 0x00, 0x00
