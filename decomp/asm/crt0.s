	.include "asm/macros.inc"

	.syntax unified
	.text

	.incbin "baserom.gba", 0x0, 0xC0
	.arm

	arm_func_start Start
Start: @ 0x080000C0
	mov r0, #0x12
	msr cpsr_fc, r0
	ldr sp, .L080000F8
	mov r0, #0x1f
	msr cpsr_fc, r0
	ldr sp, .L080000F4
	ldr r1, .L080001C4
	add r0, pc, #0x18
	str r0, [r1]
	ldr r1, .L080001C8
	mov lr, pc
	bx r1
	.byte 0xF2, 0xFF, 0xFF, 0xEA
.L080000F4: .4byte 0x03007E60 @ IWRAM+0x7E60
.L080000F8: .4byte 0x03007FA0 @ IWRAM+0x7FA0

	arm_func_start IntrMain
IntrMain: @ 0x080000FC
	mov r3, #0x4000000
	add r3, r3, #0x200
	ldr r2, [r3]
	and r1, r2, r2, lsr #16
	ands r0, r1, #0x2000
	strbne r0, [r3, #-0x17c]
.L08000114:
	bne .L08000114
	mov r2, #0
	ands r0, r1, #1
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #2
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #4
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #8
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #0x10
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #0x20
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #0x40
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #0x80
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #0x100
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #0x200
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #0x400
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #0x800
	bne .L080001B0
	add r2, r2, #4
	ands r0, r1, #0x1000
.L080001B0:
	strh r0, [r3, #2]
	ldr r1, .L080001CC
	add r1, r1, r2
	ldr r0, [r1]
	bx r0
.L080001C4: .4byte 0x03007FFC @ IWRAM+0x7FFC
.L080001C8: .4byte AgbMain
.L080001CC: .4byte 0x030020F0 @ IWRAM+0x20F0
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x51, 0xD0, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x20, 0x88, 0x51, 0xE0, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0x51, 0xF0, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00
