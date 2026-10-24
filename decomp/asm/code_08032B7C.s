	.include "asm/macros.inc"

	.syntax unified
	.text

	.arm

	arm_func_start arm_08032B7C
arm_08032B7C: @ 0x08032B7C
	push {r8, sb, sl, fp}
	mov ip, #0x4000000
	ldr fp, .L08032BB8
	add sl, fp, #0x28
	mov sb, #1
	mov r8, #0
	strb r8, [ip, #0x208]
	ldm sl, {r0, r1}
	stm sl!, {r1}
	stm sl!, {r0}
	ldrb r0, [fp, #5]
	strb r8, [fp, #5]
	strb sb, [ip, #0x208]
	pop {r8, sb, sl, fp}
	bx lr
.L08032BB8: .4byte 0x030061C0 @ IWRAM+0x61C0
