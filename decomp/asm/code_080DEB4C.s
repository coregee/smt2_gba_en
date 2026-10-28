	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080DEB4C
sub_080DEB4C: @ 0x080DEB4C
.L080DEB4C:
	push {r4, lr}
	ldr r0, .L080DEB70
	movs r2, #0x34
	ldrsh r1, [r0, r2]
	adds r4, r0, #0
	cmp r1, #0x41
	beq .L080DEBE0
	cmp r1, #0x41
	bgt .L080DEB7E
	cmp r1, #0x20
	beq .L080DEBBC
	cmp r1, #0x20
	bgt .L080DEB74
	cmp r1, #0
	beq .L080DEBA4
	cmp r1, #0x13
	beq .L080DEBB0
	b .L080DEC4C
.L080DEB70: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DEB74:
	cmp r1, #0x2f
	beq .L080DEBC8
	cmp r1, #0x32
	beq .L080DEBD4
	b .L080DEC4C
.L080DEB7E:
	cmp r1, #0x65
	beq .L080DEC04
	cmp r1, #0x65
	bgt .L080DEB90
	cmp r1, #0x4e
	beq .L080DEBEC
	cmp r1, #0x58
	beq .L080DEBF8
	b .L080DEC4C
.L080DEB90:
	cmp r1, #0x89
	beq .L080DEC20
	cmp r1, #0x89
	bgt .L080DEB9E
	cmp r1, #0x6e
	beq .L080DEC10
	b .L080DEC4C
.L080DEB9E:
	cmp r1, #0x8a
	beq .L080DEC3E
	b .L080DEC4C
.L080DEBA4:
	ldr r1, .L080DEBAC
	movs r0, #9
	strb r0, [r1]
	b .L080DEC72
.L080DEBAC: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBB0:
	ldr r1, .L080DEBB8
	movs r0, #0x10
	strb r0, [r1]
	b .L080DEC72
.L080DEBB8: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBBC:
	ldr r1, .L080DEBC4
	movs r0, #0x17
	strb r0, [r1]
	b .L080DEC72
.L080DEBC4: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBC8:
	ldr r1, .L080DEBD0
	movs r0, #0x1e
	strb r0, [r1]
	b .L080DEC72
.L080DEBD0: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBD4:
	ldr r1, .L080DEBDC
	movs r0, #0x2c
	strb r0, [r1]
	b .L080DEC72
.L080DEBDC: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBE0:
	ldr r1, .L080DEBE8
	movs r0, #0x33
	strb r0, [r1]
	b .L080DEC72
.L080DEBE8: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBEC:
	ldr r1, .L080DEBF4
	movs r0, #0x3a
	strb r0, [r1]
	b .L080DEC72
.L080DEBF4: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBF8:
	ldr r1, .L080DEC00
	movs r0, #0x48
	strb r0, [r1]
	b .L080DEC72
.L080DEC00: .4byte 0x03000037 @ IWRAM+0x37
.L080DEC04:
	ldr r1, .L080DEC0C
	movs r0, #0x4f
	strb r0, [r1]
	b .L080DEC72
.L080DEC0C: .4byte 0x03000037 @ IWRAM+0x37
.L080DEC10:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L080DEC1C
	b .L080DEC6E
	.byte 0x00, 0x00
.L080DEC1C: .4byte 0x0000BFFF
.L080DEC20:
	ldrh r0, [r4, #0x22]
	cmp r0, #1
	bne .L080DEC2E
	movs r0, #0
	strh r0, [r4, #0x22]
	movs r0, #0x28
	strh r0, [r4, #6]
.L080DEC2E:
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne .L080DEC5A
	b .L080DEC68
.L080DEC3E:
	movs r0, #1
	bl PalFade_FadeToBlack
	str r0, [r4]
	movs r0, #1
	strh r0, [r4, #4]
	b .L080DECCA
.L080DEC4C:
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq .L080DEC68
.L080DEC5A:
	ldr r1, .L080DEC64
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	b .L080DEC72
.L080DEC64: .4byte 0x03000038 @ IWRAM+0x38
.L080DEC68:
	ldr r2, .L080DECD0
	ldrh r1, [r2]
	ldr r0, .L080DECD4
.L080DEC6E:
	ands r0, r1
	strh r0, [r2]
.L080DEC72:
	ldrh r0, [r4, #6]
	subs r0, #1
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080DECCA
	movs r0, #8
	strh r0, [r4, #6]
	movs r0, #1
	strh r0, [r4, #0x22]
	ldrh r0, [r4, #0x34]
	adds r0, #1
	strh r0, [r4, #0x34]
	ldr r2, .L080DECD8
	ldr r1, .L080DECDC
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r2, .L080DECE0
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	strb r0, [r2]
	ldr r2, .L080DECE4
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	rsbs r0, r0, #0
	strh r0, [r2]
	ldr r2, .L080DECE8
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	rsbs r0, r0, #0
	strh r0, [r2]
.L080DECCA:
	pop {r4}
	pop {r0}
	bx r0
.L080DECD0: .4byte 0x03000038 @ IWRAM+0x38
.L080DECD4: .4byte 0x0000FFFE
.L080DECD8: .4byte 0x03000031 @ IWRAM+0x31
.L080DECDC: .4byte gUnknown_08586670
.L080DECE0: .4byte 0x03000035 @ IWRAM+0x35
.L080DECE4: .4byte 0x03000000 @ IWRAM
.L080DECE8: .4byte 0x03000002 @ IWRAM+0x2
