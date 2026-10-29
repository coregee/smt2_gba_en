	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start __lshrdi3
__lshrdi3: @ 0x0815E684
.L0815E684:
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r5, r0, #0
	cmp r2, #0
	beq .L0815E6B4
	movs r0, #0x20
	subs r0, r0, r2
	cmp r0, #0
	bgt .L0815E6A0
	movs r4, #0
	rsbs r0, r0, #0
	adds r3, r6, #0
	lsrs r3, r0
	b .L0815E6B0
.L0815E6A0:
	adds r1, r6, #0
	lsls r1, r0
	adds r4, r6, #0
	lsrs r4, r2
	adds r0, r5, #0
	lsrs r0, r2
	adds r3, r0, #0
	orrs r3, r1
.L0815E6B0:
	adds r1, r4, #0
	adds r0, r3, #0
.L0815E6B4:
	pop {r4, r5, r6, pc}
	.byte 0x00, 0x00

	thumb_func_start __muldi3
__muldi3: @ 0x0815E6B8
.L0815E6B8:
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r3, [sp]
	ldr r0, .L0815E724
	mov ip, r0
	adds r2, r3, #0
	ands r2, r0
	lsrs r3, r3, #0x10
	ldr r1, [sp, #8]
	adds r0, r1, #0
	mov r4, ip
	ands r0, r4
	lsrs r1, r1, #0x10
	adds r5, r2, #0
	muls r5, r0, r5
	adds r4, r2, #0
	muls r4, r1, r4
	adds r2, r3, #0
	muls r2, r0, r2
	muls r3, r1, r3
	lsrs r0, r5, #0x10
	adds r4, r4, r0
	adds r4, r4, r2
	cmp r4, r2
	bhs .L0815E6F8
	movs r0, #0x80
	lsls r0, r0, #9
	adds r3, r3, r0
.L0815E6F8:
	lsrs r0, r4, #0x10
	adds r7, r3, r0
	mov r1, ip
	ands r4, r1
	lsls r0, r4, #0x10
	ands r5, r1
	adds r6, r0, #0
	orrs r6, r5
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r3, [sp]
	ldr r4, [sp, #0xc]
	adds r2, r3, #0
	muls r2, r4, r2
	ldr r5, [sp, #4]
	ldr r4, [sp, #8]
	adds r3, r5, #0
	muls r3, r4, r3
	adds r2, r2, r3
	adds r1, r7, r2
	add sp, #0x10
	pop {r4, r5, r6, r7, pc}
.L0815E724: .4byte 0x0000FFFF

	thumb_func_start __negdi2
__negdi2: @ 0x0815E728
.L0815E728:
	push {r4, lr}
	rsbs r2, r0, #0
	adds r3, r2, #0
	rsbs r1, r1, #0
	cmp r2, #0
	beq .L0815E736
	subs r1, #1
.L0815E736:
	adds r4, r1, #0
	adds r1, r4, #0
	adds r0, r3, #0
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start memcpy
memcpy: @ 0x0815E740
.L0815E740:
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r3, r1, #0
	cmp r2, #0xf
	bls .L0815E780
	adds r0, r3, #0
	orrs r0, r5
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L0815E780
	adds r1, r5, #0
.L0815E75A:
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, #0x10
	cmp r2, #0xf
	bhi .L0815E75A
	cmp r2, #3
	bls .L0815E77E
.L0815E774:
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, #4
	cmp r2, #3
	bhi .L0815E774
.L0815E77E:
	adds r4, r1, #0
.L0815E780:
	subs r2, #1
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq .L0815E79A
	adds r1, r0, #0
.L0815E78C:
	ldrb r0, [r3]
	strb r0, [r4]
	adds r3, #1
	adds r4, #1
	subs r2, #1
	cmp r2, r1
	bne .L0815E78C
.L0815E79A:
	adds r0, r5, #0
	pop {r4, r5, pc}
	.byte 0x00, 0x00

	thumb_func_start memset
memset: @ 0x0815E7A0
.L0815E7A0:
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r5, #0
	cmp r2, #3
	bls .L0815E7E6
	movs r0, #3
	ands r0, r5
	cmp r0, #0
	bne .L0815E7E6
	adds r1, r5, #0
	movs r0, #0xff
	ands r4, r0
	lsls r3, r4, #8
	orrs r3, r4
	lsls r0, r3, #0x10
	orrs r3, r0
	cmp r2, #0xf
	bls .L0815E7DA
.L0815E7C6:
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	subs r2, #0x10
	cmp r2, #0xf
	bhi .L0815E7C6
	b .L0815E7DA
.L0815E7D6:
	stm r1!, {r3}
	subs r2, #4
.L0815E7DA:
	cmp r2, #3
	bhi .L0815E7D6
	adds r3, r1, #0
	b .L0815E7E6
.L0815E7E2:
	strb r4, [r3]
	adds r3, #1
.L0815E7E6:
	adds r0, r2, #0
	subs r2, #1
	cmp r0, #0
	bne .L0815E7E2
	adds r0, r5, #0
	pop {r4, r5, pc}
	.byte 0x00, 0x00

	thumb_func_start srand
srand: @ 0x0815E7F4
	ldr r1, .L0815E7FC
	ldr r1, [r1]
	str r0, [r1, #0x58]
	bx lr
.L0815E7FC: .4byte 0x0203DE9C @ EWRAM+0x3DE9C

	thumb_func_start rand
rand: @ 0x0815E800
.L0815E800:
	ldr r0, .L0815E818
	ldr r2, [r0]
	ldr r1, [r2, #0x58]
	ldr r0, .L0815E81C
	muls r0, r1, r0
	ldr r1, .L0815E820
	adds r0, r0, r1
	str r0, [r2, #0x58]
	ldr r1, .L0815E824
	ands r0, r1
	bx lr
	.byte 0x00, 0x00
.L0815E818: .4byte 0x0203DE9C @ EWRAM+0x3DE9C
.L0815E81C: .4byte 0x41C64E6D
.L0815E820: .4byte 0x00003039
.L0815E824: .4byte 0x7FFFFFFF
