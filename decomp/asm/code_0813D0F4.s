	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_0813D0F4
sub_0813D0F4: @ 0x0813D0F4
	push {lr}
	bl sub_080B092C
	adds r1, r0, #0
	cmp r1, #1
	beq .L0813D106
	ldr r0, .L0813D110
	movs r1, #0
	strh r1, [r0]
.L0813D106:
	ldr r0, .L0813D114
	strh r1, [r0]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D110: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D114: .4byte 0x03006858 @ IWRAM+0x6858
