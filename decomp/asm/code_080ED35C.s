	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080ED35C
sub_080ED35C: @ 0x080ED35C
.L080ED35C:
	push {r4, r5, lr}
	adds r5, r1, #0
	lsls r4, r2, #0x18
	lsrs r4, r4, #0x16
	ldr r1, .L080ED38C
	adds r4, r4, r1
	ldrb r1, [r4, #1]
	str r1, [r0]
	ldrb r1, [r4]
	movs r0, #0xf
	ands r0, r1
	bl sub_080ED600
	adds r0, #1
	str r0, [r5]
	ldr r0, .L080ED390
	ldr r1, .L080ED394
	adds r0, r0, r1
	ldrb r1, [r4]
	str r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080ED38C: .4byte gUnknown_0876E978
.L080ED390: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ED394: .4byte 0x00000984
