	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080E8D88
sub_080E8D88: @ 0x080E8D88
.L080E8D88:
	ldr r1, .L080E8D94
	ldr r2, .L080E8D98
	adds r1, r1, r2
	strb r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080E8D94: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E8D98: .4byte 0x00000EC3

	thumb_func_start sub_080E8D9C
sub_080E8D9C: @ 0x080E8D9C
	push {lr}
	movs r0, #1
	bl sub_080E8D88
	pop {r0}
	bx r0

	thumb_func_start sub_080E8DA8
sub_080E8DA8: @ 0x080E8DA8
	push {lr}
	movs r0, #0
	bl sub_080E8D88
	pop {r0}
	bx r0

	thumb_func_start sub_080E8DB4
sub_080E8DB4: @ 0x080E8DB4
.L080E8DB4:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r3, .L080E8DE4
	lsls r0, r2, #2
	movs r4, #0x99
	lsls r4, r4, #4
	adds r1, r3, r4
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L080E8DE8
	cmp r1, r0
	beq .L080E8DDC
	lsls r0, r2, #6
	movs r1, #0xda
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0, #4]
.L080E8DDC:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E8DE4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E8DE8: .4byte 0x0000FFFF

	thumb_func_start sub_080E8DEC
sub_080E8DEC: @ 0x080E8DEC
.L080E8DEC:
	push {lr}
	movs r0, #0
	bl sub_080E8DB4
	movs r0, #1
	bl sub_080E8DB4
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E8E00
sub_080E8E00: @ 0x080E8E00
.L080E8E00:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	ldr r5, .L080E8E34
	movs r1, #0xf0
	ands r1, r0
	lsrs r1, r1, #4
	mov sl, r1
	movs r7, #0xf
	ands r7, r0
	ldr r1, .L080E8E38
	ldr r2, .L080E8E3C
	adds r0, r5, r2
	str r0, [r1]
	cmp r7, #2
	bls .L080E8E40
	movs r0, #0
	b .L080E8F4E
	.byte 0x00, 0x00
.L080E8E34: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E8E38: .4byte 0x03006434 @ IWRAM+0x6434
.L080E8E3C: .4byte 0x00000F6C
.L080E8E40:
	adds r0, r7, #0
	mov r1, r8
	bl sub_080C45C0
	ldr r0, .L080E8EC0
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080E8EC4
	mov sb, r1
	lsls r6, r7, #2
	cmp r8, sb
	beq .L080E8F48
	movs r2, #0x99
	lsls r2, r2, #4
	adds r1, r5, r2
	adds r2, r6, r1
	ldr r0, [r2]
	cmp r0, r8
	beq .L080E8F48
	mov r0, r8
	str r0, [r2]
	cmp r7, #0
	bne .L080E8EE0
	ldr r1, [r1]
	movs r0, #0
	bl sub_080F0200
	movs r0, #0
	bl sub_080ED938
	ldr r0, .L080E8EC8
	bl VBlankTask_Add
	ldr r2, .L080E8ECC
	adds r1, r5, r2
	str r0, [r1]
	ldr r0, .L080E8ED0
	bl sub_080E5668
	ldr r1, .L080E8ED4
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r0, .L080E8ED8
	mov r1, sb
	bl Task_Create
	str r0, [r5, #4]
	movs r4, #0
	mov r0, sl
	cmp r0, #0
	beq .L080E8F16
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl sub_080E845C
	ldr r2, .L080E8EDC
	adds r1, r5, r2
	movs r0, #2
	strb r0, [r1]
	adds r4, r7, #0
	b .L080E8F16
.L080E8EC0: .4byte 0x0000118C
.L080E8EC4: .4byte 0x0000FFFF
.L080E8EC8: .4byte sub_080E55BC
.L080E8ECC: .4byte 0x00001118
.L080E8ED0: .4byte sub_080E5674
.L080E8ED4: .4byte 0x00000DA3
.L080E8ED8: .4byte gUnknown_086BEA18
.L080E8EDC: .4byte 0x00000DA4
.L080E8EE0:
	movs r0, #4
	mov r1, r8
	bl sub_080F0200
	movs r0, #1
	bl sub_080ED938
	ldr r0, .L080E8F5C
	bl VBlankTask_Add
	ldr r2, .L080E8F60
	adds r1, r5, r2
	adds r1, r6, r1
	str r0, [r1]
	lsls r4, r7, #6
	adds r0, r4, r5
	ldr r1, .L080E8F64
	adds r0, r0, r1
	movs r2, #0
	strb r2, [r0]
	ldr r0, .L080E8F68
	mov r1, sb
	bl Task_Create
	ldr r2, .L080E8F6C
	adds r1, r6, r2
	str r0, [r1]
.L080E8F16:
	adds r0, r5, r4
	ldr r2, .L080E8F70
	adds r1, r0, r2
	ldr r2, .L080E8F74
	strh r2, [r1]
	ldr r1, .L080E8F78
	adds r0, r0, r1
	strh r2, [r0]
	mov r0, r8
	movs r1, #0
	bl sub_080BDE1C
	ldr r1, .L080E8F7C
	adds r0, r7, #6
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, .L080E8F6C
	adds r1, r2, r6
	ldr r1, [r1]
	str r1, [r0]
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #0
	bl sub_080C08F8
.L080E8F48:
	ldr r1, .L080E8F6C
	adds r0, r1, r6
	ldr r0, [r0]
.L080E8F4E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080E8F5C: .4byte sub_080E5610
.L080E8F60: .4byte 0x00001118
.L080E8F64: .4byte 0x00000DA3
.L080E8F68: .4byte gUnknown_086BEB18
.L080E8F6C: .4byte 0x0203C204 @ EWRAM+0x3C204
.L080E8F70: .4byte 0x00000DA8
.L080E8F74: .4byte 0x00007FFF
.L080E8F78: .4byte 0x00000DAA
.L080E8F7C: .4byte 0x02036094 @ EWRAM+0x36094

	thumb_func_start sub_080E8F80
sub_080E8F80: @ 0x080E8F80
.L080E8F80:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	ldr r4, .L080E8F9C
	lsrs r0, r0, #0x12
	movs r5, #0xda
	lsls r5, r5, #4
	adds r0, r0, r5
	adds r0, r0, r4
	strh r1, [r0, #8]
	strh r2, [r0, #0xa]
	strb r3, [r0, #0x10]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E8F9C: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_080E8FA0
sub_080E8FA0: @ 0x080E8FA0
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #1
	beq .L080E8FD4
	cmp r0, #1
	bgt .L080E8FBA
	cmp r0, #0
	beq .L080E8FC0
	b .L080E8FE2
.L080E8FBA:
	cmp r1, #2
	beq .L080E8FDC
	b .L080E8FE2
.L080E8FC0:
	bl sub_080ED954
	cmp r0, #0
	bne .L080E8FCC
	movs r0, #0x78
	b .L080E8FCE
.L080E8FCC:
	movs r0, #0x50
.L080E8FCE:
	strh r0, [r4]
	movs r0, #0x56
	b .L080E8FE0
.L080E8FD4:
	movs r0, #0xa1
	strh r0, [r4]
	movs r0, #0x56
	b .L080E8FE0
.L080E8FDC:
	movs r0, #0
	strh r0, [r4]
.L080E8FE0:
	strh r0, [r5]
.L080E8FE2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080E8FE8
sub_080E8FE8: @ 0x080E8FE8
	lsls r0, r0, #0x18
	ldr r1, .L080E9000
	lsrs r0, r0, #0x12
	movs r2, #0xda
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r1, .L080E9004
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	bx lr
	.byte 0x00, 0x00
.L080E9000: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E9004: .4byte 0x00007FFF

	thumb_func_start sub_080E9008
sub_080E9008: @ 0x080E9008
.L080E9008:
	push {r4, lr}
	ldr r4, .L080E9038
	ldr r0, [r4, #4]
	bl Task_End
	movs r0, #0
	str r0, [r4, #4]
	ldr r1, .L080E903C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #2]
	movs r0, #0x99
	lsls r0, r0, #4
	adds r1, r4, r0
	adds r0, #4
	adds r4, r4, r0
	ldr r0, .L080E9040
	str r0, [r4]
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E9038: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E903C: .4byte 0x00001114
.L080E9040: .4byte 0x0000FFFF

	thumb_func_start sub_080E9044
sub_080E9044: @ 0x080E9044
.L080E9044:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r5, .L080E9098
	cmp r4, #0
	beq .L080E905C
	bl sub_080C37EC
	adds r0, r4, #0
	bl Task_End
.L080E905C:
	lsls r2, r6, #2
	adds r0, r5, #4
	adds r0, r2, r0
	movs r1, #0
	str r1, [r0]
	ldr r1, .L080E909C
	adds r0, r5, r1
	adds r0, r2, r0
	ldr r1, [r0]
	movs r3, #0
	movs r0, #1
	strh r0, [r1, #2]
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r2, r2, r0
	ldr r0, .L080E90A0
	str r0, [r2]
	lsls r0, r6, #6
	adds r0, r0, r5
	ldr r2, .L080E90A4
	adds r1, r0, r2
	strb r3, [r1]
	ldr r1, .L080E90A8
	adds r0, r0, r1
	strb r3, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E9098: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E909C: .4byte 0x00001118
.L080E90A0: .4byte 0x0000FFFF
.L080E90A4: .4byte 0x00000DA3
.L080E90A8: .4byte 0x00000DA4

	thumb_func_start sub_080E90AC
sub_080E90AC: @ 0x080E90AC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	ldr r6, .L080E90D4
	movs r1, #0
	strh r1, [r0, #0x1c]
	ldr r0, .L080E90D8
	adds r5, r6, r0
	movs r2, #0
	ldrsh r4, [r5, r2]
	cmp r4, #1
	beq .L080E911C
	cmp r4, #1
	bgt .L080E90DC
	cmp r4, #0
	beq .L080E90E2
	b .L080E91DC
	.byte 0x00, 0x00
.L080E90D4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E90D8: .4byte 0x0000097A
.L080E90DC:
	cmp r4, #2
	beq .L080E9160
	b .L080E91DC
.L080E90E2:
	ldr r0, .L080E9114
	strh r1, [r0]
	ldr r0, .L080E9118
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	bl sub_080C2BA4
	movs r7, #0xf6
	lsls r7, r7, #4
	adds r1, r6, r7
	strh r0, [r1]
	movs r0, #2
	strh r0, [r5]
	movs r0, #1
	bl BattleMsg_SetLocked
	b .L080E91DC
.L080E9114: .4byte 0x03000052 @ IWRAM+0x52
.L080E9118: .4byte gUnknown_08126368
.L080E911C:
	ldr r0, .L080E9154
	ldrh r1, [r0]
	movs r0, #2
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	beq .L080E913E
	movs r0, #0x80
	lsls r0, r0, #7
	bl sub_080F00FC
	ldr r2, .L080E9158
	adds r1, r6, r2
	movs r0, #6
	strh r0, [r1]
	mov r7, sb
	strh r4, [r7, #0x1c]
.L080E913E:
	ldr r1, .L080E915C
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	ble .L080E91DC
	mov r0, r8
	strh r0, [r5]
	b .L080E91DC
.L080E9154: .4byte 0x030031D0 @ IWRAM+0x31D0
.L080E9158: .4byte 0x00000978
.L080E915C: .4byte 0x03000052 @ IWRAM+0x52
.L080E9160:
	ldr r0, .L080E91AC
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #7
	bl sub_080ED90C
	movs r4, #0
	movs r5, #0
.L080E9170:
	adds r0, r4, #0
	bl sub_080F3EC8
	cmp r0, #0
	beq .L080E91B6
	adds r0, r4, #0
	bl sub_080F3040
	cmp r0, #0
	beq .L080E91B6
	movs r1, #0xf6
	lsls r1, r1, #4
	adds r3, r6, r1
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	beq .L080E91B0
	asrs r0, r5, #0x10
	lsls r2, r4, #1
	movs r7, #0xf3
	lsls r7, r7, #4
	adds r1, r6, r7
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r7, #0
	ldrsh r2, [r3, r7]
	bl sub_080E926C
	b .L080E91B6
.L080E91AC: .4byte 0x03000052 @ IWRAM+0x52
.L080E91B0:
	asrs r0, r5, #0x10
	bl sub_080E91F0
.L080E91B6:
	movs r0, #0x80
	lsls r0, r0, #9
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #0xf
	ble .L080E9170
	bl sub_080C84C0
	ldr r2, .L080E91E8
	adds r1, r6, r2
	movs r2, #0
	movs r0, #0xa
	strh r0, [r1]
	ldr r7, .L080E91EC
	adds r0, r6, r7
	strh r2, [r0]
	movs r0, #1
	mov r1, sb
	strh r0, [r1, #0x1c]
.L080E91DC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E91E8: .4byte 0x00000978
.L080E91EC: .4byte 0x0000097A

	thumb_func_start sub_080E91F0
sub_080E91F0: @ 0x080E91F0
.L080E91F0:
	push {r4, r5, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	bl sub_080C2244
	movs r1, #1
	ands r1, r0
	lsls r1, r1, #2
	adds r1, #0x10
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080EDA4C
	cmp r4, #3
	bgt .L080E925C
	adds r0, r4, #0
	bl sub_080C3620
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bne .L080E9238
	adds r0, r4, #0
	movs r1, #5
	mov r2, sp
	bl sub_080EF740
	cmp r0, #0
	beq .L080E9238
	adds r0, r4, #0
	movs r1, #5
	bl sub_080C35C4
	b .L080E9264
.L080E9238:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	movs r1, #0
	bl sub_080C00DC
	cmp r0, #0xff
	beq .L080E9252
	adds r0, r4, #0
	movs r1, #4
	bl sub_080C35C4
	b .L080E9264
.L080E9252:
	adds r0, r4, #0
	movs r1, #9
	bl sub_080C35C4
	b .L080E9264
.L080E925C:
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_080C35C4
.L080E9264:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080E926C
sub_080E926C: @ 0x080E926C
.L080E926C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	lsrs r1, r0, #0x10
	mov r8, r1
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080F3F14
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r4, #0
	bl sub_080C3620
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	bl sub_080C2244
	movs r1, #1
	ands r1, r0
	lsls r1, r1, #2
	adds r1, #0x10
	adds r0, r4, #0
	bl sub_080EDA4C
	lsls r0, r7, #0x10
	asrs r5, r0, #0x10
	cmp r5, #8
	bne .L080E92C6
	bl sub_0812B37C
	cmp r0, #0
	beq .L080E92C6
	b .L080E93EC
.L080E92C6:
	subs r0, r5, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080E92D4
	cmp r5, #0xa
	bne .L080E92DC
.L080E92D4:
	adds r0, r4, #0
	bl sub_080E91F0
	b .L080E940A
.L080E92DC:
	cmp r5, #7
	bne .L080E9348
	adds r0, r4, #0
	bl sub_080F4070
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r2, [sp, #8]
	lsls r0, r2, #0x10
	asrs r5, r0, #0x10
	adds r0, r5, #0
	bl sub_080ED6CC
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #0
	bl sub_080ED694
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r5, #0x3e
	beq .L080E93EC
	cmp r5, #0x3f
	beq .L080E93EC
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x10
	cmp r0, #0
	blt .L080E93EC
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x80
	beq .L080E9328
	cmp r0, #0x82
	bne .L080E9348
.L080E9328:
	ldr r0, [sp]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0xf
	bhi .L080E93EC
	asrs r5, r1, #0x10
	adds r0, r5, #0
	bl sub_080F3EC8
	cmp r0, #0
	beq .L080E93EC
	adds r0, r5, #0
	bl sub_080C0A00
	cmp r0, #0
	beq .L080E93EC
.L080E9348:
	lsls r0, r7, #0x10
	asrs r1, r0, #0x10
	mov r2, r8
	lsls r2, r2, #0x10
	mov sl, r2
	mov sb, r0
	cmp r1, #8
	bne .L080E93CE
	movs r6, #0
	ldr r0, [sp, #8]
	lsls r4, r0, #0x10
	ldr r1, .L080E93E4
	adds r0, r4, r1
	lsrs r0, r0, #0x10
	bl Action_GetRecord
	adds r7, r0, #0
	movs r1, #0
	ldr r3, .L080E93E8
	mov r0, sl
	asrs r2, r0, #0x10
.L080E9372:
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	bne .L080E9380
	adds r6, r1, #0
.L080E9380:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #5
	bls .L080E9372
	asrs r5, r4, #0x10
	adds r0, r5, #0
	bl sub_080C10B4
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_0812B1E0
	subs r4, r4, r0
	lsls r4, r4, #0x10
	cmp r4, #0
	ble .L080E93EC
	ldrb r0, [r7, #3]
	cmp r0, #0x80
	beq .L080E93AE
	cmp r0, #0x82
	bne .L080E93CE
.L080E93AE:
	ldr r2, [sp]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0xf
	bhi .L080E93EC
	asrs r4, r1, #0x10
	adds r0, r4, #0
	bl sub_080F3EC8
	cmp r0, #0
	beq .L080E93EC
	adds r0, r4, #0
	bl sub_080C0A00
	cmp r0, #0
	beq .L080E93EC
.L080E93CE:
	mov r1, sb
	asrs r0, r1, #0x10
	cmp r0, #6
	beq .L080E93EC
	mov r2, sl
	asrs r0, r2, #0x10
	lsrs r1, r1, #0x10
	bl sub_080C35C4
	b .L080E940A
	.byte 0x00, 0x00
.L080E93E4: .4byte 0xFF300000
.L080E93E8: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080E93EC:
	ldr r0, [sp, #4]
	cmp r0, #1
	bne .L080E93FE
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	bl sub_080E91F0
	b .L080E940A
.L080E93FE:
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r1, #9
	bl sub_080C35C4
.L080E940A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E941C
sub_080E941C: @ 0x080E941C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, .L080E9440
	movs r0, #0
	strh r0, [r7, #0x1c]
	ldr r1, .L080E9444
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #4
	bls .L080E9434
	b .L080E976C
.L080E9434:
	lsls r0, r0, #2
	ldr r1, .L080E9448
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080E9440: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E9444: .4byte 0x0000097A
.L080E9448: .4byte gUnknown_080E944C
	.global gUnknown_080E944C
gUnknown_080E944C:
.L080E944C: @ jump table
	.4byte .L080E9460
	.4byte .L080E948C
	.4byte .L080E94E4
	.4byte .L080E9510
	.4byte .L080E976C
.L080E9460:
	ldr r3, .L080E94B8
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	bl sub_080F3120
	bl sub_080F2D4C
	bl sub_080EDD8C
	bl sub_080F2F14
	ldr r4, .L080E94BC
	adds r1, r6, r4
	strh r0, [r1]
	ldr r0, .L080E94C0
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, .L080E94C4
	bl sub_080F3F58
.L080E948C:
	ldr r1, .L080E94B8
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	bl sub_080EFFC4
	lsls r0, r0, #0x10
	movs r3, #0x80
	lsls r3, r3, #0x18
	adds r0, r0, r3
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r0, [r0, #0x10]
	ldr r2, .L080E94C8
	ands r2, r0
	cmp r2, #0
	beq .L080E94CC
	ldr r4, .L080E94C0
	adds r1, r6, r4
	movs r0, #3
	b .L080E976A
.L080E94B8: .4byte 0x00000ECE
.L080E94BC: .4byte 0x00000ECC
.L080E94C0: .4byte 0x0000097A
.L080E94C4: .4byte 0xFFFFFBFF
.L080E94C8: .4byte 0x0000B1E0
.L080E94CC:
	ldr r1, .L080E94DC
	adds r0, r6, r1
	movs r1, #2
	strh r1, [r0]
	ldr r3, .L080E94E0
	adds r0, r6, r3
	strh r2, [r0]
	b .L080E976C
.L080E94DC: .4byte 0x0000097A
.L080E94E0: .4byte 0x0000097C
.L080E94E4:
	ldr r4, .L080E9508
	adds r0, r6, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_080EFFC4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_080F0434
	cmp r0, #0
	bne .L080E94FE
	b .L080E976C
.L080E94FE:
	ldr r2, .L080E950C
	adds r1, r6, r2
	movs r0, #3
	b .L080E976A
	.byte 0x00, 0x00
.L080E9508: .4byte 0x00000ECE
.L080E950C: .4byte 0x0000097A
.L080E9510:
	bl sub_080C366C
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	movs r5, #0
.L080E951E:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_080BFD94
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble .L080E951E
	ldr r3, .L080E95B4
	adds r0, r6, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	bl sub_080EFFC4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0xf
	bgt .L080E957A
	movs r1, #0
	ldr r0, .L080E95B8
	movs r4, #0xa2
	lsls r4, r4, #4
	adds r3, r0, r4
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, r2
	beq .L080E9570
.L080E955A:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #5
	bhi .L080E957A
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	bne .L080E955A
.L080E9570:
	cmp r1, #5
	bhi .L080E957A
	adds r0, r1, #0
	bl sub_080C8490
.L080E957A:
	bl sub_080ED9F4
	adds r4, r0, #0
	cmp r4, #0
	bne .L080E95CC
	bl sub_080C84A0
	ldr r1, .L080E95BC
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, .L080E95C0
	adds r1, r6, r2
	movs r0, #0xe
	strh r0, [r1]
	ldr r1, .L080E95C4
	movs r0, #4
	strh r0, [r1]
	movs r0, #1
	strh r0, [r7, #0x1c]
	ldr r3, .L080E95C8
	adds r0, r6, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080E95AE
	b .L080E976C
.L080E95AE:
	strh r4, [r1, #0xa]
	b .L080E976C
	.byte 0x00, 0x00
.L080E95B4: .4byte 0x00000ECE
.L080E95B8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E95BC: .4byte 0x0000097A
.L080E95C0: .4byte 0x00000978
.L080E95C4: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E95C8: .4byte 0x00000F6A
.L080E95CC:
	bl sub_080F3144
	cmp r0, #0
	beq .L080E9620
	movs r0, #0x80
	lsls r0, r0, #6
	bl sub_080ED90C
	ldr r3, .L080E9610
	adds r0, r6, r3
	movs r5, #0
	strh r5, [r0]
	ldr r0, .L080E9614
	adds r4, r6, r0
	movs r0, #0xe
	strh r0, [r4]
	movs r0, #1
	strh r0, [r7, #0x1c]
	bl sub_080C84A0
	ldr r1, .L080E9618
	movs r0, #3
	strh r0, [r1]
	movs r0, #0xf
	strh r0, [r4]
	ldr r2, .L080E961C
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne .L080E960C
	b .L080E976C
.L080E960C:
	strh r5, [r1, #0xa]
	b .L080E976C
.L080E9610: .4byte 0x0000097A
.L080E9614: .4byte 0x00000978
.L080E9618: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E961C: .4byte 0x00000F6A
.L080E9620:
	bl sub_080ED8F4
	movs r4, #0x88
	lsls r4, r4, #6
	ands r4, r0
	cmp r4, #0
	beq .L080E9688
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #6
	ands r1, r0
	cmp r1, #0
	beq .L080E9648
	ldr r1, .L080E967C
	ldrh r0, [r1, #0xc]
	cmp r0, #2
	bne .L080E9648
	movs r0, #1
	strh r0, [r1, #0x14]
.L080E9648:
	movs r1, #0
	movs r0, #1
	strh r0, [r7, #0x1c]
	ldr r4, .L080E9680
	adds r0, r6, r4
	strh r1, [r0]
	ldr r0, .L080E9684
	adds r1, r6, r0
	movs r0, #0xe
	strh r0, [r1]
	movs r5, #0
.L080E965E:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	movs r2, #0
	bl sub_080E7538
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble .L080E965E
	b .L080E976C
.L080E967C: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E9680: .4byte 0x0000097A
.L080E9684: .4byte 0x00000978
.L080E9688:
	ldr r3, .L080E970C
	adds r2, r6, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	subs r3, #2
	adds r1, r6, r3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0
	ldrsh r1, [r1, r3]
	cmp r0, r1
	ble .L080E9764
	strh r4, [r2]
	movs r1, #0xec
	lsls r1, r1, #4
	adds r0, r6, r1
	movs r5, #1
	strb r5, [r0]
	ldr r2, .L080E9710
	adds r1, r6, r2
	ldr r0, .L080E9714
	strh r0, [r1]
	ldr r3, .L080E9718
	adds r1, r6, r3
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	bl sub_080EF2A0
	bl sub_080C84A0
	ldr r0, .L080E971C
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bne .L080E96DC
	strh r4, [r1]
.L080E96DC:
	ldr r0, .L080E9720
	ldr r1, [r0]
	strh r4, [r1, #2]
	ldrh r2, [r1]
	ldr r0, .L080E9724
	ands r0, r2
	strh r0, [r1]
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #7
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0
	beq .L080E9730
	ldr r1, .L080E9728
	adds r0, r6, r1
	strh r5, [r0]
	ldr r2, .L080E972C
	adds r1, r6, r2
	movs r0, #0xd
	b .L080E973C
	.byte 0x00, 0x00
.L080E970C: .4byte 0x00000ECE
.L080E9710: .4byte 0x000011AC
.L080E9714: .4byte 0x0000FFFF
.L080E9718: .4byte 0x000011AE
.L080E971C: .4byte 0x000011A4
.L080E9720: .4byte 0x03006434 @ IWRAM+0x6434
.L080E9724: .4byte 0x0000FF7F
.L080E9728: .4byte 0x0000097A
.L080E972C: .4byte 0x00000978
.L080E9730:
	ldr r3, .L080E9754
	adds r0, r6, r3
	strh r1, [r0]
	ldr r4, .L080E9758
	adds r1, r6, r4
	movs r0, #6
.L080E973C:
	strh r0, [r1]
	strh r5, [r7, #0x1c]
	ldr r1, .L080E975C
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq .L080E976C
	ldr r1, .L080E9760
	movs r0, #0
	strh r0, [r1, #0xa]
	b .L080E976C
.L080E9754: .4byte 0x0000097A
.L080E9758: .4byte 0x00000978
.L080E975C: .4byte 0x00000F6A
.L080E9760: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E9764:
	ldr r3, .L080E9774
	adds r1, r6, r3
	movs r0, #1
.L080E976A:
	strh r0, [r1]
.L080E976C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E9774: .4byte 0x0000097A

	thumb_func_start sub_080E9778
sub_080E9778: @ 0x080E9778
	ldr r1, .L080E978C
	ldr r0, .L080E9790
	adds r2, r1, r0
	movs r3, #0
	movs r0, #0xa
	strh r0, [r2]
	ldr r0, .L080E9794
	adds r1, r1, r0
	strh r3, [r1]
	bx lr
.L080E978C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E9790: .4byte 0x00000978
.L080E9794: .4byte 0x0000097A

	thumb_func_start sub_080E9798
sub_080E9798: @ 0x080E9798
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r1, .L080E97B4
	movs r5, #0
	strh r5, [r3, #0x1c]
	ldr r4, .L080E97B8
	ldrh r2, [r4, #0xa]
	cmp r2, #1
	beq .L080E97E6
	cmp r2, #1
	bgt .L080E97BC
	cmp r2, #0
	beq .L080E97C2
	b .L080E9804
.L080E97B4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E97B8: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E97BC:
	cmp r2, #2
	beq .L080E9800
	b .L080E9804
.L080E97C2:
	ldr r2, .L080E97D4
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080E97D8
	movs r0, #1
	strh r0, [r3, #0x1c]
	b .L080E9804
.L080E97D4: .4byte 0x00000F6A
.L080E97D8:
	ldrh r0, [r4]
	cmp r0, #1
	bne .L080E97E2
	movs r0, #5
	strh r0, [r4, #6]
.L080E97E2:
	movs r0, #2
	b .L080E9802
.L080E97E6:
	ldrh r0, [r4, #6]
	cmp r0, #5
	bne .L080E97F6
	ldr r0, .L080E97FC
	adds r1, r1, r0
	movs r0, #0x10
	strh r0, [r1]
	strh r2, [r3, #0x1c]
.L080E97F6:
	strh r2, [r3, #0x1c]
	strh r5, [r4, #0xa]
	b .L080E9804
.L080E97FC: .4byte 0x00000978
.L080E9800:
	movs r0, #1
.L080E9802:
	strh r0, [r4, #0xa]
.L080E9804:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E980C
sub_080E980C: @ 0x080E980C
.L080E980C:
	push {r4, r5, r6, r7, lr}
	ldr r0, .L080E9868
	ldr r1, .L080E986C
	adds r0, r0, r1
	ldrh r4, [r0]
	bl sub_080F0168
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r6, r1, #0x1f
	movs r5, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	cmp r5, r4
	bhs .L080E9840
	movs r7, #1
	rsbs r7, r7, #0
.L080E982E:
	adds r0, r5, #0
	bl sub_080F01EC
	cmp r0, r7
	beq .L080E983A
	movs r6, #1
.L080E983A:
	adds r5, #1
	cmp r5, r4
	blo .L080E982E
.L080E9840:
	movs r5, #0
.L080E9842:
	adds r0, r5, #0
	bl sub_080F0194
	cmp r0, #0
	beq .L080E984E
	movs r6, #1
.L080E984E:
	adds r5, #1
	cmp r5, #3
	bls .L080E9842
	bl sub_080F0168
	cmp r0, #0
	beq .L080E985E
	movs r6, #1
.L080E985E:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080E9868: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E986C: .4byte 0x0000099C

	thumb_func_start sub_080E9870
sub_080E9870: @ 0x080E9870
.L080E9870:
	push {r4, r5, lr}
	ldr r5, .L080E988C
	movs r4, #0
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	beq .L080E9890
	bl BattleMenu_Reset
	movs r0, #0
	b .L080E98EC
.L080E988C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E9890:
	bl sub_080ED954
	cmp r0, #1
	bne .L080E98B8
	bl sub_080E980C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L080E98AE
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	beq .L080E98DE
.L080E98AE:
	ldr r4, .L080E98B4
	b .L080E98DE
	.byte 0x00, 0x00
.L080E98B4: .4byte gUnknown_086BEC18
.L080E98B8:
	bl sub_080E980C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L080E98CE
	movs r0, #0xd5
	bl Flag_Test
	cmp r0, #0
	beq .L080E98DE
.L080E98CE:
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, .L080E98F4
	bl MessageBox_ComposeRaceNameText
	adds r4, r0, #0
.L080E98DE:
	cmp r4, #0
	beq .L080E98EA
	movs r0, #3
	adds r1, r4, #0
	bl BattleMenu_SetMode
.L080E98EA:
	adds r0, r4, #0
.L080E98EC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080E98F4: .4byte gUnknown_08124284

	thumb_func_start sub_080E98F8
sub_080E98F8: @ 0x080E98F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r6, .L080E993C
	ldr r1, .L080E9940
	adds r0, r6, r1
	ldrh r7, [r0]
	movs r2, #0
	mov sb, r2
	movs r0, #0xe5
	bl Flag_Test
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r3, sb
	strh r3, [r4, #0x1c]
	ldr r1, .L080E9944
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0x14
	bls .L080E9930
	bl .L080EA168
.L080E9930:
	lsls r0, r0, #2
	ldr r1, .L080E9948
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080E993C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E9940: .4byte 0x0000099C
.L080E9944: .4byte 0x0000097A
.L080E9948: .4byte gUnknown_080E994C
	.global gUnknown_080E994C
gUnknown_080E994C:
.L080E994C: @ jump table
	.4byte .L080E99A0
	.4byte .L080E9ADC
	.4byte .L080E9BD4
	.4byte .L080E9C18
	.4byte .L080E9C48
	.4byte .L080E9C6C
	.4byte .L080E9D0C
	.4byte .L080E9D80
	.4byte .L080E9DD8
	.4byte .L080E9E3C
	.4byte .L080E9F88
	.4byte .L080EA120
	.4byte .L080E9FDC
	.4byte .L080EA02C
	.4byte .L080E9D64
	.4byte .L080E9DBC
	.4byte .L080E9E24
	.4byte .L080E9CD4
	.4byte .L080EA0B0
	.4byte .L080EA120
	.4byte .L080EA158
.L080E99A0:
	movs r0, #0x80
	lsls r0, r0, #7
	bl sub_080F00FC
	movs r0, #0
	bl BattleMsg_SetLocked
	bl sub_080E51FC
	movs r0, #0xb3
	lsls r0, r0, #1
	bl Flag_Clear
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #6
	ands r1, r0
	cmp r1, #0
	beq .L080E99E0
	bl sub_080EF364
	ldr r3, .L080E99DC
	adds r0, r6, r3
	movs r1, #0x10
	strh r1, [r0]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080E9B06
	.byte 0x00, 0x00
.L080E99DC: .4byte 0x00000978
.L080E99E0:
	bl sub_080ED954
	cmp r0, #0
	bne .L080E9A30
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	bne .L080E9A60
	cmp r5, #0
	beq .L080E9A06
	movs r5, #0x99
	lsls r5, r5, #4
	adds r0, r6, r5
	ldr r0, [r0]
	bl sub_080C2584
.L080E9A06:
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r6, r1
	ldrh r0, [r0]
	ldr r2, .L080E9A28
	adds r1, r6, r2
	ldrh r1, [r1]
	ldr r2, .L080E9A2C
	bl Battle_BuildRaceCountText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r3, #1
	mov sb, r3
	b .L080E9A60
.L080E9A28: .4byte 0x00000998
.L080E9A2C: .4byte gUnknown_08124270
.L080E9A30:
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	bne .L080E9A60
	cmp r5, #0
	beq .L080E9A60
	movs r5, #0x99
	lsls r5, r5, #4
	adds r0, r6, r5
	ldr r0, [r0]
	bl sub_080C2584
	ldr r1, .L080E9ACC
	adds r0, r6, r1
	ldr r0, [r0]
	bl sub_080C2584
	ldr r2, .L080E9AD0
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
.L080E9A60:
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	bne .L080E9AB6
	movs r3, #0x99
	lsls r3, r3, #4
	adds r0, r6, r3
	ldr r0, [r0]
	bl sub_080EF3C8
	adds r4, r0, #0
	movs r5, #1
	rsbs r5, r5, #0
	cmp r4, r5
	beq .L080E9A8E
	bl sub_080C10B4
	cmp r0, #0x62
	ble .L080E9A8E
	adds r4, r5, #0
.L080E9A8E:
	ldr r5, .L080E9AD4
	adds r0, r6, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r0, #1
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	bl sub_080F01D8
	movs r2, #0x99
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	bl sub_080EF434
	cmp r0, #0
	beq .L080E9AB6
	movs r0, #1
	bl sub_080F0150
.L080E9AB6:
	ldr r3, .L080E9AD8
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	mov r5, sb
	cmp r5, #0
	beq .L080E9B06
	movs r0, #0x14
	bl sub_080E5A18
	b .L080E9B06
.L080E9ACC: .4byte 0x00000994
.L080E9AD0: .4byte 0x000007E4
.L080E9AD4: .4byte 0x0000099E
.L080E9AD8: .4byte 0x0000097A
.L080E9ADC:
	ldr r0, .L080E9B0C
	adds r1, r6, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble .L080E9B18
	ldr r2, .L080E9B10
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
	bl sub_080C2244
	ldr r4, .L080E9B14
	strh r0, [r4]
	bl sub_080C2244
	strh r0, [r4, #2]
	bl sub_080EF364
.L080E9B06:
	bl sub_080C84A0
	b .L080EA168
.L080E9B0C: .4byte 0x0000099E
.L080E9B10: .4byte 0x0000097A
.L080E9B14: .4byte 0x0203A450 @ EWRAM+0x3A450
.L080E9B18:
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #2
	ands r1, r0
	cmp r1, #0
	beq .L080E9B9A
	movs r5, #0x10
	movs r7, #0x80
	lsls r7, r7, #8
.L080E9B2C:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080C0A00
	cmp r0, #0
	beq .L080E9B68
	adds r0, r4, #0
	bl sub_080C0818
	adds r1, r7, #0
	adds r0, r4, #0
	bl sub_080C08F8
	adds r0, r4, #0
	movs r1, #0
	bl sub_080F4054
	adds r0, r4, #0
	movs r1, #0
	bl sub_080F408C
	adds r0, r5, #0
	subs r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	movs r2, #0
	bl sub_080E7538
.L080E9B68:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x17
	ble .L080E9B2C
	bl sub_080E980C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E9B9A
	ldr r3, .L080E9BC4
	adds r4, r6, r3
	ldr r0, [r4]
	cmp r0, #0
	bne .L080E9B9A
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #2
	bl sub_080AB890
	str r0, [r4]
.L080E9B9A:
	bl sub_080EF364
	bl sub_080C84A0
	ldr r5, .L080E9BC8
	adds r0, r6, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080E9BB4
	movs r0, #9
	bl sub_080ECF60
.L080E9BB4:
	ldr r1, .L080E9BCC
	movs r0, #9
	strh r0, [r1, #0x10]
	ldr r2, .L080E9BD0
	adds r1, r6, r2
	movs r0, #4
	strh r0, [r1]
	b .L080EA168
.L080E9BC4: .4byte 0x00000974
.L080E9BC8: .4byte 0x00000F6A
.L080E9BCC: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E9BD0: .4byte 0x0000097A
.L080E9BD4:
	ldr r3, .L080E9C08
	adds r0, r6, r3
	movs r4, #0
	strh r4, [r0]
	movs r0, #4
	bl sub_080C51BC
	ldr r0, .L080E9C0C
	strh r4, [r0]
	bl BattleMenu_Reset
	bl BattleMsg_Close
	bl sub_080E9008
	ldr r1, .L080E9C10
	movs r0, #1
	strh r0, [r1]
	bl sub_080C7C60
	ldr r5, .L080E9C14
	adds r1, r6, r5
	movs r0, #3
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080E9C08: .4byte 0x00000F68
.L080E9C0C: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080E9C10: .4byte 0x030063A0 @ IWRAM+0x63A0
.L080E9C14: .4byte 0x0000097A
.L080E9C18:
	ldr r1, .L080E9C3C
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080E9C34
	ldr r0, .L080E9C40
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080E9C34
	cmp r0, #2
	beq .L080E9C34
	bl sub_080C700C
.L080E9C34:
	ldr r3, .L080E9C44
	adds r0, r6, r3
	movs r1, #0
	b .L080EA138
.L080E9C3C: .4byte 0x00000F6A
.L080E9C40: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080E9C44: .4byte 0x00000978
.L080E9C48:
	bl sub_080E9870
	cmp r0, #0
	beq .L080E9C54
	movs r5, #1
	mov sb, r5
.L080E9C54:
	ldr r0, .L080E9C64
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, .L080E9C68
	adds r1, r6, r2
	movs r0, #5
	b .L080E9F66
.L080E9C64: .4byte 0x00000ECE
.L080E9C68: .4byte 0x0000097A
.L080E9C6C:
	ldr r0, .L080E9CA8
	adds r5, r6, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl sub_080F01EC
	adds r4, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L080E9CB4
	adds r0, r4, #0
	movs r1, #1
	bl sub_080F3E54
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080E9CAC
	bl Battle_BuildItemDropText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	ldr r2, .L080E9CB0
	adds r1, r6, r2
	movs r0, #0x11
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080E9CA8: .4byte 0x00000ECE
.L080E9CAC: .4byte gUnknown_08124452
.L080E9CB0: .4byte 0x0000097A
.L080E9CB4:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsls r1, r7, #0x10
	cmp r0, r1
	bge .L080E9CC4
	b .L080EA168
.L080E9CC4:
	ldr r3, .L080E9CD0
	adds r1, r6, r3
	movs r0, #6
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080E9CD0: .4byte 0x0000097A
.L080E9CD4:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9CE2
	b .L080EA168
.L080E9CE2:
	ldr r5, .L080E9D04
	adds r2, r6, r5
	movs r0, #5
	strh r0, [r2]
	ldr r0, .L080E9D08
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsls r1, r7, #0x10
	cmp r0, r1
	bge .L080E9CFE
	b .L080EA168
.L080E9CFE:
	movs r0, #6
	strh r0, [r2]
	b .L080EA168
.L080E9D04: .4byte 0x0000097A
.L080E9D08: .4byte 0x00000ECE
.L080E9D0C:
	bl sub_080F0168
	adds r4, r0, #0
	ldr r1, .L080E9D58
	adds r6, r6, r1
	movs r5, #7
	strh r5, [r6]
	cmp r4, #0
	bne .L080E9D20
	b .L080EA168
.L080E9D20:
	bl sub_080C2244
	ands r0, r5
	movs r1, #0xdb
	cmp r0, #0
	beq .L080E9D2E
	movs r1, #0xe5
.L080E9D2E:
	adds r0, r1, #0
	ldr r5, .L080E9D5C
	cmp r0, #0xe5
	bne .L080E9D38
	ldr r5, .L080E9D60
.L080E9D38:
	adds r1, r4, #0
	bl sub_080F3E54
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl Battle_BuildValueRewardText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	movs r0, #0xe
	strh r0, [r6]
	b .L080EA168
	.byte 0x00, 0x00
.L080E9D58: .4byte 0x0000097A
.L080E9D5C: .4byte gUnknown_0812443C
.L080E9D60: .4byte gUnknown_08124426
.L080E9D64:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9D72
	b .L080EA168
.L080E9D72:
	ldr r2, .L080E9D7C
	adds r1, r6, r2
	movs r0, #7
	strh r0, [r1]
	b .L080EA168
.L080E9D7C: .4byte 0x0000097A
.L080E9D80:
	bl sub_080F0124
	adds r4, r0, #0
	ldr r3, .L080E9DB4
	adds r5, r6, r3
	movs r0, #8
	strh r0, [r5]
	cmp r4, #0
	bne .L080E9D94
	b .L080EA168
.L080E9D94:
	adds r0, r4, #0
	bl sub_080F3E20
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080E9DB8
	bl Battle_BuildValueRewardText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	movs r0, #0xf
	strh r0, [r5]
	b .L080EA168
	.byte 0x00, 0x00
.L080E9DB4: .4byte 0x0000097A
.L080E9DB8: .4byte gUnknown_081243EE
.L080E9DBC:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9DCA
	b .L080EA168
.L080E9DCA:
	ldr r5, .L080E9DD4
	adds r1, r6, r5
	movs r0, #8
	strh r0, [r1]
	b .L080EA168
.L080E9DD4: .4byte 0x0000097A
.L080E9DD8:
	bl sub_080F0144
	adds r4, r0, #0
	ldr r0, .L080E9E14
	adds r5, r6, r0
	movs r7, #0
	movs r0, #9
	strh r0, [r5]
	cmp r4, #0
	beq .L080E9E08
	adds r0, r4, #0
	bl sub_080F3E2C
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080E9E18
	bl Battle_BuildValueRewardText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	movs r0, #0x10
	strh r0, [r5]
.L080E9E08:
	ldr r0, .L080E9E1C
	strh r7, [r0]
	ldr r1, .L080E9E20
	adds r0, r6, r1
	strh r7, [r0]
	b .L080EA168
.L080E9E14: .4byte 0x0000097A
.L080E9E18: .4byte gUnknown_0812440A
.L080E9E1C: .4byte 0x03000056 @ IWRAM+0x56
.L080E9E20: .4byte 0x00000ECE
.L080E9E24:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9E32
	b .L080EA168
.L080E9E32:
	ldr r2, .L080E9E38
	adds r1, r6, r2
	b .L080EA14C
.L080E9E38: .4byte 0x0000097A
.L080E9E3C:
	ldr r3, .L080E9F30
	adds r5, r6, r3
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl sub_080F3EC8
	cmp r0, #0
	bne .L080E9E4E
	b .L080E9F7C
.L080E9E4E:
	movs r2, #0
	ldrsh r0, [r5, r2]
	bl sub_080C0A00
	cmp r0, #0
	bne .L080E9E5C
	b .L080E9F7C
.L080E9E5C:
	ldr r3, .L080E9F34
	adds r0, r3, #0
	ldrh r1, [r5]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	movs r2, #0
	ldrsh r0, [r5, r2]
	bl sub_080F0194
	adds r7, r0, #0
	ldr r0, [r4, #8]
	bl sub_080C1070
	mov sl, r0
	ldr r1, .L080E9F38
	movs r0, #0
	strh r0, [r1]
	movs r5, #0
	movs r3, #0x5d
	adds r3, r3, r4
	mov ip, r3
	ldr r0, .L080E9F3C
	mov r8, r0
.L080E9E92:
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	mov r3, ip
	adds r0, r3, r2
	ldrb r3, [r0]
	adds r0, r3, #0
	cmp r0, #0xff
	beq .L080E9EAE
	mov r5, r8
	adds r0, r2, r5
	strb r3, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L080E9EAE:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble .L080E9E92
	cmp r7, #0
	beq .L080E9EE4
	ldr r0, [r4, #8]
	adds r0, r0, r7
	str r0, [r4, #8]
	ldr r1, .L080E9F40
	cmp r0, r1
	ble .L080E9ECE
	ldr r0, .L080E9F44
	str r0, [r4, #8]
.L080E9ECE:
	ldr r2, .L080E9F48
	adds r0, r4, #0
	adds r1, r7, #0
	bl Battle_BuildRewardText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	movs r0, #1
	mov sb, r0
.L080E9EE4:
	ldr r0, [r4, #8]
	bl sub_080C1070
	adds r4, r0, #0
	ldr r1, .L080E9F30
	adds r5, r6, r1
	movs r2, #0
	ldrsh r0, [r5, r2]
	adds r1, r4, #0
	bl sub_080C0FA4
	ldr r0, .L080E9F4C
	mov r3, sl
	subs r4, r4, r3
	strh r4, [r0]
	lsls r0, r4, #0x10
	cmp r0, #0
	beq .L080E9F60
	ldr r1, .L080E9F50
	movs r0, #1
	strh r0, [r1]
	ldr r0, .L080E9F54
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, .L080E9F58
	adds r1, r6, r2
	movs r0, #0xa
	strh r0, [r1]
	ldr r3, .L080E9F5C
	adds r0, r6, r3
	strh r4, [r0]
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl sub_080BF938
	b .L080EA168
	.byte 0x00, 0x00
.L080E9F30: .4byte 0x00000ECE
.L080E9F34: .4byte 0xFFFF8000
.L080E9F38: .4byte 0x0300005C @ IWRAM+0x5C
.L080E9F3C: .4byte 0x03000060 @ IWRAM+0x60
.L080E9F40: .4byte 0x0098967E
.L080E9F44: .4byte 0x0098967F
.L080E9F48: .4byte gUnknown_0812428E
.L080E9F4C: .4byte 0x03000054 @ IWRAM+0x54
.L080E9F50: .4byte 0x03000056 @ IWRAM+0x56
.L080E9F54: .4byte 0x0000097C
.L080E9F58: .4byte 0x0000097A
.L080E9F5C: .4byte 0x00001178
.L080E9F60:
	ldr r2, .L080E9F78
	adds r1, r6, r2
	movs r0, #0xb
.L080E9F66:
	strh r0, [r1]
	mov r3, sb
	cmp r3, #0
	bne .L080E9F70
	b .L080EA168
.L080E9F70:
	movs r0, #0x14
	bl sub_080E5A18
	b .L080EA168
.L080E9F78: .4byte 0x0000097A
.L080E9F7C:
	ldr r5, .L080E9F84
	adds r1, r6, r5
	b .L080EA0F6
	.byte 0x00, 0x00
.L080E9F84: .4byte 0x0000097A
.L080E9F88:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9F96
	b .L080EA168
.L080E9F96:
	ldr r0, .L080E9FCC
	adds r1, r6, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, .L080E9FD0
	adds r1, r6, r2
	ldr r3, .L080E9FD4
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080E9FD8
	bl Battle_BuildNamePrefixText
	adds r1, r0, #0
	movs r0, #7
	bl BattleMenu_SetMode
	movs r0, #0xb
	bl sub_080ECF60
	movs r0, #0x67
	bl sub_080ECF70
	b .L080EA168
	.byte 0x00, 0x00
.L080E9FCC: .4byte 0x0000097A
.L080E9FD0: .4byte 0x00000ECE
.L080E9FD4: .4byte 0xFFFF8000
.L080E9FD8: .4byte gUnknown_0812434A
.L080E9FDC:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080E9FEA
	b .L080EA168
.L080E9FEA:
	ldr r5, .L080EA01C
	adds r1, r6, r5
	ldr r2, .L080EA020
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	ldrb r0, [r4, #0xc]
	ldr r3, .L080EA024
	adds r1, r6, r3
	ldrh r1, [r1]
	bl sub_080CE62C
	bl BattleMsg_Close
	ldr r5, .L080EA028
	adds r1, r6, r5
	movs r0, #0xd
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080EA01C: .4byte 0x00000ECE
.L080EA020: .4byte 0xFFFF8000
.L080EA024: .4byte 0x00001178
.L080EA028: .4byte 0x0000097A
.L080EA02C:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080EA03A
	b .L080EA168
.L080EA03A:
	ldr r0, .L080EA090
	adds r5, r6, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl sub_080F4260
	ldr r7, .L080EA094
	movs r2, #0
	ldrsh r4, [r7, r2]
	movs r3, #0
	ldrsh r0, [r5, r3]
	bl sub_080F41F4
	cmp r4, r0
	bge .L080EA0A4
	ldr r1, .L080EA098
	adds r0, r1, #0
	ldrh r5, [r5]
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r2, .L080EA09C
	movs r1, #0
	strh r1, [r2]
	movs r2, #0
	ldrsh r1, [r7, r2]
	adds r0, #0x5d
	adds r0, r0, r1
	ldrb r0, [r0]
	bl sub_080EB008
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	ldr r3, .L080EA0A0
	adds r1, r6, r3
	movs r0, #0x12
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080EA090: .4byte 0x00000ECE
.L080EA094: .4byte 0x0300005C @ IWRAM+0x5C
.L080EA098: .4byte 0xFFFF8000
.L080EA09C: .4byte 0x0300005E @ IWRAM+0x5E
.L080EA0A0: .4byte 0x0000097A
.L080EA0A4:
	ldr r5, .L080EA0AC
	adds r1, r6, r5
	b .L080EA0F6
	.byte 0x00, 0x00
.L080EA0AC: .4byte 0x0000097A
.L080EA0B0:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080EA168
	ldr r0, .L080EA0FC
	adds r1, r6, r0
	ldr r2, .L080EA100
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldr r2, .L080EA104
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	ldr r1, .L080EA108
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r5, #0
	ldrsh r2, [r2, r5]
	adds r1, r1, r2
	adds r0, #0x5d
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0xff
	bne .L080EA110
	bl BattleMenu_Reset
	ldr r0, .L080EA10C
	adds r1, r6, r0
.L080EA0F6:
	movs r0, #0xb
	strh r0, [r1]
	b .L080EA168
.L080EA0FC: .4byte 0x00000ECE
.L080EA100: .4byte 0xFFFF8000
.L080EA104: .4byte 0x0300005E @ IWRAM+0x5E
.L080EA108: .4byte 0x0300005C @ IWRAM+0x5C
.L080EA10C: .4byte 0x0000097A
.L080EA110:
	ldrb r0, [r1]
	bl sub_080EB008
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	b .L080EA168
.L080EA120:
	ldr r2, .L080EA140
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble .L080EA148
	ldr r3, .L080EA144
	adds r0, r6, r3
	movs r1, #0x10
.L080EA138:
	strh r1, [r0]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080EA168
.L080EA140: .4byte 0x00000ECE
.L080EA144: .4byte 0x00000978
.L080EA148:
	ldr r5, .L080EA154
	adds r1, r6, r5
.L080EA14C:
	movs r0, #9
	strh r0, [r1]
	b .L080EA168
	.byte 0x00, 0x00
.L080EA154: .4byte 0x0000097A
.L080EA158:
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080EA168
	bl sub_080E5A3C
.L080EA168:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080EA178
sub_080EA178: @ 0x080EA178
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r7, .L080EA1D8
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r0, r0, r7
	mov r8, r0
	ldr r1, .L080EA1DC
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r5, r0, #1
	movs r6, #0
	ldr r1, .L080EA1E0
	movs r2, #0
	ldrsh r4, [r1, r2]
	bl sub_080F41F4
	cmp r4, r0
	blt .L080EA1E8
	cmp r5, #3
	bgt .L080EA1C2
.L080EA1A6:
	adds r0, r5, #0
	bl sub_080F3EC8
	cmp r0, #0
	beq .L080EA1BC
	adds r0, r5, #0
	bl sub_080C0A00
	cmp r0, #0
	beq .L080EA1BC
	movs r6, #1
.L080EA1BC:
	adds r5, #1
	cmp r5, #3
	ble .L080EA1A6
.L080EA1C2:
	cmp r6, #0
	bne .L080EA1E8
	ldr r1, .L080EA1E4
	adds r0, r7, r1
	movs r1, #0x13
	strh r1, [r0]
	movs r0, #1
	mov r2, r8
	strb r0, [r2, #4]
	strb r0, [r2]
	b .L080EA200
.L080EA1D8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EA1DC: .4byte 0x00000ECE
.L080EA1E0: .4byte 0x0300005C @ IWRAM+0x5C
.L080EA1E4: .4byte 0x0000097A
.L080EA1E8:
	bl sub_080EA210
	bl sub_080E9870
	movs r0, #1
	mov r1, r8
	strb r0, [r1, #4]
	strb r0, [r1]
	ldr r2, .L080EA20C
	adds r1, r7, r2
	movs r0, #0xd
	strh r0, [r1]
.L080EA200:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EA20C: .4byte 0x0000097A

	thumb_func_start sub_080EA210
sub_080EA210: @ 0x080EA210
.L080EA210:
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r4, .L080EA26C
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r7, r4, r0
	movs r6, #0
	str r6, [sp, #4]
	ldr r2, .L080EA270
	add r0, sp, #4
	adds r1, r7, #0
	bl CpuSet
	movs r0, #0x97
	lsls r0, r0, #4
	adds r5, r4, r0
	ldr r0, [r5]
	cmp r0, #0
	bne .L080EA240
	ldr r0, .L080EA274
	ldr r1, .L080EA278
	bl Task_Create
	str r0, [r5]
.L080EA240:
	ldr r0, .L080EA27C
	adds r4, r4, r0
	ldr r0, [r4]
	cmp r0, #0
	bne .L080EA25A
	str r6, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #2
	bl sub_080AB890
	str r0, [r4]
.L080EA25A:
	strb r6, [r7, #5]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080EA26C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EA270: .4byte 0x05000064 @ PLTT+0x64
.L080EA274: .4byte gUnknown_086BF708
.L080EA278: .4byte 0x0000FFFF
.L080EA27C: .4byte 0x00000974

	thumb_func_start sub_080EA280
sub_080EA280: @ 0x080EA280
.L080EA280:
	push {r4, r5, lr}
	sub sp, #4
	ldr r4, .L080EA2A4
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r4, r4, r0
	movs r5, #0
	str r5, [sp]
	ldr r2, .L080EA2A8
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	strb r5, [r4, #5]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080EA2A4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EA2A8: .4byte 0x05000066 @ PLTT+0x66

	thumb_func_start sub_080EA2AC
sub_080EA2AC: @ 0x080EA2AC
.L080EA2AC:
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r4, .L080EA300
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r6, r4, r0
	movs r5, #0
	str r5, [sp, #4]
	ldr r2, .L080EA304
	add r0, sp, #4
	adds r1, r6, #0
	bl CpuSet
	ldr r0, .L080EA308
	ldr r1, .L080EA30C
	bl Task_Create
	movs r2, #0x97
	lsls r2, r2, #4
	adds r1, r4, r2
	str r0, [r1]
	str r5, [sp]
	movs r0, #2
	movs r1, #0xd
	movs r2, #0x1a
	movs r3, #2
	bl sub_080AB890
	ldr r1, .L080EA310
	adds r4, r4, r1
	str r0, [r4]
	movs r0, #1
	strb r0, [r6, #5]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EA300: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EA304: .4byte 0x05000066 @ PLTT+0x66
.L080EA308: .4byte gUnknown_086BF708
.L080EA30C: .4byte 0x0000FFFF
.L080EA310: .4byte 0x00000974

	thumb_func_start sub_080EA314
sub_080EA314: @ 0x080EA314
.L080EA314:
	push {r4, r5, r6, lr}
	ldr r6, .L080EA358
	adds r2, r0, #0
	movs r4, #1
	ldrh r1, [r2]
	adds r0, r1, #0
	cmp r0, #0
	beq .L080EA346
	ldr r3, .L080EA35C
	cmp r0, r3
	beq .L080EA346
	movs r5, #0xc0
	lsls r5, r5, #2
.L080EA32E:
	cmp r1, r5
	bne .L080EA338
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
.L080EA338:
	adds r2, #2
	ldrh r1, [r2]
	adds r0, r1, #0
	cmp r0, #0
	beq .L080EA346
	cmp r0, r3
	bne .L080EA32E
.L080EA346:
	cmp r4, #4
	bne .L080EA364
	ldr r1, .L080EA360
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #7
	bl Window_SetHeight
	b .L080EA370
.L080EA358: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EA35C: .4byte 0x00000301
.L080EA360: .4byte 0x00000974
.L080EA364:
	ldr r1, .L080EA378
	adds r0, r6, r1
	ldr r0, [r0]
	lsls r1, r4, #1
	bl Window_SetHeight
.L080EA370:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080EA378: .4byte 0x00000974
