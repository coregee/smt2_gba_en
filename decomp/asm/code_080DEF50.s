	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080DEF50
sub_080DEF50: @ 0x080DEF50
.L080DEF50:
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r5, .L080DEF6C
	ldr r6, [r5]
	ldr r0, .L080DEF70
	ldrb r2, [r0, #1]
	adds r7, r0, #0
	cmp r2, #1
	beq .L080DEFCE
	cmp r2, #1
	bgt .L080DEF74
	cmp r2, #0
	beq .L080DEF7A
	b .L080DF006
.L080DEF6C: .4byte 0x04000128 @ REG_SIOCNT
.L080DEF70: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DEF74:
	cmp r2, #2
	beq .L080DF000
	b .L080DF006
.L080DEF7A:
	ldr r0, [r7, #0x18]
	cmp r0, #0xb
	bne .L080DEFCA
	movs r0, #0x88
	adds r4, r6, #0
	ands r4, r0
	cmp r4, #8
	bne .L080DF006
	movs r1, #4
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne .L080DEFCA
	ldr r3, .L080DEFE4
	strh r0, [r3]
	ldr r2, .L080DEFE8
	ldrh r1, [r2]
	ldr r0, .L080DEFEC
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldrb r1, [r5, #1]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r5, #1]
	ldr r1, .L080DEFF0
	ldr r0, .L080DEFF4
	str r0, [r1]
	adds r1, #0xf6
	movs r0, #0xc0
	strh r0, [r1]
	strb r4, [r7]
.L080DEFCA:
	movs r0, #1
	strb r0, [r7, #1]
.L080DEFCE:
	ldr r1, .L080DEFF8
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq .L080DF000
	ldrb r0, [r1, #8]
	cmp r0, #7
	bhi .L080DEFFC
	adds r0, #1
	strb r0, [r1, #8]
	b .L080DF000
	.byte 0x00, 0x00
.L080DEFE4: .4byte 0x04000208 @ REG_IME
.L080DEFE8: .4byte 0x04000200 @ REG_IE
.L080DEFEC: .4byte 0x0000FF7F
.L080DEFF0: .4byte 0x0400010C @ REG_TM3CNT
.L080DEFF4: .4byte 0x0000ABFB
.L080DEFF8: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DEFFC:
	movs r0, #2
	strb r0, [r1, #1]
.L080DF000:
	mov r0, ip
	bl sub_080DF0AC
.L080DF006:
	ldr r1, .L080DF024
	ldrb r0, [r1, #0xb]
	adds r0, #1
	strb r0, [r1, #0xb]
	ldrb r3, [r1, #3]
	ldrb r0, [r1, #2]
	lsls r2, r0, #8
	ldrb r0, [r1]
	adds r7, r1, #0
	cmp r0, #8
	bne .L080DF028
	movs r0, #0x80
	orrs r0, r2
	orrs r0, r3
	b .L080DF02C
.L080DF024: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DF028:
	adds r0, r3, #0
	orrs r0, r2
.L080DF02C:
	adds r2, r0, #0
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq .L080DF03A
	movs r0, #0x80
	lsls r0, r0, #5
	orrs r2, r0
.L080DF03A:
	ldrb r0, [r7, #8]
	lsrs r0, r0, #3
	lsls r1, r0, #0xf
	lsls r0, r6, #0x1a
	lsrs r0, r0, #0x1e
	cmp r0, #1
	bls .L080DF052
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r0, r1
	orrs r0, r2
	b .L080DF056
.L080DF052:
	adds r0, r2, #0
	orrs r0, r1
.L080DF056:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080DF05C
sub_080DF05C: @ 0x080DF05C
.L080DF05C:
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, .L080DF0A4
	ldr r2, [r4, #0x1c]
	ldrb r1, [r4, #0xb]
	strb r1, [r2]
	ldr r3, [r4, #0x1c]
	ldrb r1, [r4, #2]
	ldrb r2, [r4, #3]
	eors r1, r2
	strb r1, [r3, #1]
	ldr r1, [r4, #0x1c]
	strh r5, [r1, #2]
	ldr r1, [r4, #0x1c]
	adds r1, #4
	ldr r2, .L080DF0A8
	bl CpuSet
	movs r2, #0
	ldr r1, [r4, #0x1c]
.L080DF084:
	ldrh r0, [r1]
	adds r5, r5, r0
	adds r1, #2
	adds r2, #1
	cmp r2, #9
	bls .L080DF084
	ldr r0, [r4, #0x1c]
	mvns r1, r5
	subs r1, #0xc
	strh r1, [r0, #2]
	movs r0, #1
	strb r0, [r4, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DF0A4: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DF0A8: .4byte 0x04000004 @ REG_DISPSTAT

	thumb_func_start sub_080DF0AC
sub_080DF0AC: @ 0x080DF0AC
.L080DF0AC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldr r0, .L080DF14C
	movs r4, #0
	str r4, [sp]
	bl _call_via_r0
	lsls r0, r0, #0x18
	ldr r1, .L080DF150
	strb r4, [r1, #3]
	cmp r0, #0
	beq .L080DF12E
	movs r5, #0
	add r0, sp, #4
	mov r8, r0
	adds r7, r1, #0
	movs r0, #0xd
	rsbs r0, r0, #0
	mov sl, r0
.L080DF0DC:
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, [r7, #0x2c]
	adds r1, r1, r0
	movs r4, #0
	movs r3, #0
	adds r6, r5, #1
	adds r2, r1, #0
.L080DF0EE:
	ldrh r0, [r2]
	adds r4, r4, r0
	adds r2, #2
	adds r3, #1
	cmp r3, #9
	bls .L080DF0EE
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	adds r4, r1, #4
	cmp r0, sl
	bne .L080DF11A
	lsls r1, r5, #4
	add r1, sb
	adds r0, r4, #0
	ldr r2, .L080DF154
	bl CpuSet
	movs r0, #1
	lsls r0, r5
	ldrb r1, [r7, #3]
	orrs r0, r1
	strb r0, [r7, #3]
.L080DF11A:
	movs r0, #0
	str r0, [sp, #4]
	mov r0, r8
	adds r1, r4, #0
	ldr r2, .L080DF158
	bl CpuSet
	adds r5, r6, #0
	cmp r5, #1
	ble .L080DF0DC
.L080DF12E:
	ldr r1, .L080DF150
	ldrb r0, [r1, #2]
	ldrb r2, [r1, #3]
	orrs r0, r2
	strb r0, [r1, #2]
	ldrb r0, [r1, #3]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080DF14C: .4byte 0x030062B0 @ IWRAM+0x62B0
.L080DF150: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DF154: .4byte 0x04000004 @ REG_DISPSTAT
.L080DF158: .4byte 0x05000004 @ PLTT+0x4

	thumb_func_start sub_080DF15C
sub_080DF15C: @ 0x080DF15C
.L080DF15C:
	push {r4, r5, lr}
	ldr r4, .L080DF1B4
	ldrb r5, [r4]
	cmp r5, #0
	beq .L080DF1C4
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq .L080DF1DE
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq .L080DF1DE
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #0x24]
	str r0, [r4, #0x28]
	str r1, [r4, #0x24]
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq .L080DF194
	ldr r1, [r4, #0x20]
	ldr r0, [r4, #0x1c]
	str r0, [r4, #0x20]
	str r1, [r4, #0x1c]
	movs r0, #0
	strb r0, [r4, #4]
	str r0, [r4, #0x14]
.L080DF194:
	ldr r2, .L080DF1B8
	ldr r0, [r2]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1f
	strb r0, [r4, #7]
	ldr r0, .L080DF1BC
	strh r0, [r2, #2]
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	ldr r1, .L080DF1C0
	movs r0, #0xc0
	strh r0, [r1]
	b .L080DF1DE
	.byte 0x00, 0x00
.L080DF1B4: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DF1B8: .4byte 0x04000128 @ REG_SIOCNT
.L080DF1BC: .4byte 0x0000FEFE
.L080DF1C0: .4byte 0x0400010E @ IO+0x10E
.L080DF1C4:
	ldrb r0, [r4, #9]
	cmp r0, #0
	bne .L080DF1DC
	ldr r3, .L080DF1E4
	strh r5, [r3]
	ldr r2, .L080DF1E8
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
.L080DF1DC:
	strb r5, [r4, #9]
.L080DF1DE:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080DF1E4: .4byte 0x04000208 @ REG_IME
.L080DF1E8: .4byte 0x03007FF8 @ IWRAM+0x7FF8

	thumb_func_start SerialTimer3Intr
SerialTimer3Intr: @ 0x080DF1EC
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, .L080DF2CC
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, .L080DF2D0
	ldr r0, .L080DF2D4
	ldr r0, [r0]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1f
	movs r5, #0
	strb r0, [r2, #7]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, .L080DF2D8
	adds r4, r2, #0
	cmp r1, r0
	bne .L080DF24C
	ldr r0, [r4, #0x18]
	cmp r0, #9
	ble .L080DF24C
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #0x24]
	str r0, [r4, #0x28]
	str r1, [r4, #0x24]
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq .L080DF23A
	ldr r1, [r4, #0x20]
	ldr r0, [r4, #0x1c]
	str r0, [r4, #0x20]
	str r1, [r4, #0x1c]
	strb r5, [r4, #4]
	str r5, [r4, #0x14]
.L080DF23A:
	ldr r3, .L080DF2DC
	strh r5, [r3]
	ldr r2, .L080DF2E0
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
.L080DF24C:
	ldr r0, [r4, #0x14]
	cmp r0, #9
	bgt .L080DF25E
	ldr r2, .L080DF2D4
	ldr r1, [r4, #0x20]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2, #2]
.L080DF25E:
	ldr r0, [r4, #0x14]
	cmp r0, #0xa
	bgt .L080DF268
	adds r0, #1
	str r0, [r4, #0x14]
.L080DF268:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	blt .L080DF290
	ldr r1, [r4, #0x24]
	mov r2, sp
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r3, #1
.L080DF278:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #0x18
	subs r3, #1
	cmp r3, #0
	bge .L080DF278
	ldr r0, [r4, #0x18]
	cmp r0, #9
	bne .L080DF290
	movs r0, #1
	strb r0, [r4, #5]
.L080DF290:
	ldr r0, [r4, #0x18]
	cmp r0, #9
	bgt .L080DF29A
	adds r0, #1
	str r0, [r4, #0x18]
.L080DF29A:
	ldrb r2, [r4]
	cmp r2, #0
	beq .L080DF2A6
	ldr r1, .L080DF2E4
	movs r0, #0
	strh r0, [r1]
.L080DF2A6:
	ldr r0, [r4, #0x14]
	cmp r0, #0xa
	bgt .L080DF2C0
	cmp r2, #0
	beq .L080DF2C0
	ldr r2, .L080DF2D4
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	ldr r1, .L080DF2E4
	movs r0, #0xc0
	strh r0, [r1]
.L080DF2C0:
	movs r0, #1
	strb r0, [r4, #9]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
.L080DF2CC: .4byte 0x04000120 @ REG_SIODATA32
.L080DF2D0: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DF2D4: .4byte 0x04000128 @ REG_SIOCNT
.L080DF2D8: .4byte 0x0000FEFE
.L080DF2DC: .4byte 0x04000208 @ REG_IME
.L080DF2E0: .4byte 0x03007FF8 @ IWRAM+0x7FF8
.L080DF2E4: .4byte 0x0400010E @ IO+0x10E
