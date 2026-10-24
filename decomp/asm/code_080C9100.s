	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080C9100
sub_080C9100: @ 0x080C9100
.L080C9100:
	push {r4, r5, lr}
	bl sub_080C1D9C
	adds r4, r0, #0
	movs r0, #0xf0
	ands r4, r0
	cmp r4, #0x8f
	bls .L080C9120
	adds r0, r4, #0
	adds r0, #0x80
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0x80
	subs r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
.L080C9120:
	movs r0, #0xd8
	bl Flag_Test
	cmp r0, #0
	bne .L080C91B8
	movs r0, #0xc4
	bl Flag_Test
	cmp r0, #0
	bne .L080C915E
	movs r0, #0xc4
	bl Flag_Set
	bl sub_080C2244
	movs r5, #0xff
	ands r0, r5
	cmp r0, #0x7f
	bls .L080C9178
	bl sub_080C2244
	ands r0, r5
	cmp r0, #0x7f
	bls .L080C9162
	bl sub_080C2244
	ands r0, r5
	cmp r0, #0x7f
	bhi .L080C918C
	cmp r4, #0x10
	bne .L080C91AC
.L080C915E:
	movs r0, #0
	b .L080C9208
.L080C9162:
	bl sub_080C2244
	ands r0, r5
	cmp r0, #0x7f
	bls .L080C9172
	cmp r4, #0x20
	bne .L080C91AC
	b .L080C915E
.L080C9172:
	cmp r4, #0x30
	bne .L080C91AC
	b .L080C915E
.L080C9178:
	bl sub_080C2244
	ands r0, r5
	cmp r0, #0x7f
	bls .L080C9198
	bl sub_080C2244
	ands r0, r5
	cmp r0, #0x7f
	bls .L080C9192
.L080C918C:
	cmp r4, #0
	bne .L080C91AC
	b .L080C915E
.L080C9192:
	cmp r4, #0x50
	bne .L080C91AC
	b .L080C915E
.L080C9198:
	bl sub_080C2244
	ands r0, r5
	cmp r0, #0x7f
	bls .L080C91A8
	cmp r4, #0x60
	bne .L080C91AC
	b .L080C915E
.L080C91A8:
	cmp r4, #0x70
	beq .L080C915E
.L080C91AC:
	bl sub_080C2244
	movs r1, #0xff
	ands r1, r0
	cmp r1, #0x1f
	bhi .L080C915E
.L080C91B8:
	bl sub_080C2244
	movs r4, #0xff
	ands r0, r4
	cmp r0, #0x7f
	bls .L080C91F2
	bl sub_080C2244
	ands r0, r4
	cmp r0, #0x7f
	bls .L080C91E0
	bl sub_080C2244
	ands r0, r4
	cmp r0, #0x7f
	bls .L080C91DC
	movs r0, #0x34
	b .L080C9208
.L080C91DC:
	movs r0, #0x31
	b .L080C9208
.L080C91E0:
	bl sub_080C2244
	ands r0, r4
	cmp r0, #0x7f
	bls .L080C91EE
	movs r0, #0x32
	b .L080C9208
.L080C91EE:
	movs r0, #0x33
	b .L080C9208
.L080C91F2:
	movs r0, #0xd8
	bl Flag_Test
	cmp r0, #0
	bne .L080C9206
	bl sub_080C2244
	ands r0, r4
	cmp r0, #0x3f
	bls .L080C915E
.L080C9206:
	movs r0, #0x30
.L080C9208:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C9210
sub_080C9210: @ 0x080C9210
.L080C9210:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	cmp r0, #1
	bne .L080C9224
	ldr r0, .L080C9220
	b .L080C923E
.L080C9220: .4byte gUnknown_084EEAE4
.L080C9224:
	cmp r0, #2
	bne .L080C9230
	ldr r0, .L080C922C
	b .L080C923E
.L080C922C: .4byte gUnknown_084EEF28
.L080C9230:
	cmp r1, #3
	beq .L080C923C
	ldr r0, .L080C9238
	b .L080C923E
.L080C9238: .4byte gUnknown_084EF7B0
.L080C923C:
	ldr r0, .L080C9244
.L080C923E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C9244: .4byte gUnknown_084EF368

	thumb_func_start sub_080C9248
sub_080C9248: @ 0x080C9248
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	bl sub_080C9210
	ldr r2, .L080C9264
.L080C9258:
	ldrh r1, [r0]
	cmp r1, r2
	bne .L080C9268
	movs r0, #0
	b .L080C9270
	.byte 0x00, 0x00
.L080C9264: .4byte 0x0000FFFF
.L080C9268:
	cmp r1, r4
	beq .L080C9270
	adds r0, #4
	b .L080C9258
.L080C9270:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C9278
sub_080C9278: @ 0x080C9278
.L080C9278:
	lsls r0, r0, #0x10
	ldr r1, .L080C9288
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, .L080C928C
	ands r0, r1
	bx lr
.L080C9288: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080C928C: .4byte 0x00007FFF

	thumb_func_start sub_080C9290
sub_080C9290: @ 0x080C9290
.L080C9290:
	lsls r0, r0, #0x10
	ldr r1, .L080C92A8
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bx lr
	.byte 0x00, 0x00
.L080C92A8: .4byte 0x0203B554 @ EWRAM+0x3B554

	thumb_func_start sub_080C92AC
sub_080C92AC: @ 0x080C92AC
.L080C92AC:
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0
	ldr r2, .L080C92C4
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x19
	bhi .L080C92BE
	movs r1, #1
.L080C92BE:
	adds r0, r1, #0
	pop {r1}
	bx r1
.L080C92C4: .4byte 0xFEB00000

	thumb_func_start sub_080C92C8
sub_080C92C8: @ 0x080C92C8
.L080C92C8:
	push {r4, r5, r6, lr}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r5, .L080C92F0
	adds r0, r4, #0
	bl sub_080C9290
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C92F8
	adds r0, r4, #0
	bl sub_080C9278
	lsls r0, r0, #0x10
	lsrs r0, r0, #9
	ldr r1, .L080C92F4
	adds r0, r0, r1
	b .L080C937E
	.byte 0x00, 0x00
.L080C92F0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C92F4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C92F8:
	adds r6, r5, #0
	adds r6, #0x54
	ldrh r0, [r5, #2]
	bl sub_080C9278
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	movs r1, #4
	bl sub_080C0444
	adds r4, r5, #0
	adds r4, #0x66
	ldrh r0, [r4]
	bl sub_080C92AC
	cmp r0, #1
	bne .L080C937C
	ldrh r0, [r4]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r4, sp
	movs r1, #5
	mov r2, sp
	bl sub_080BF468
	mov r0, sp
	ldrb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x94
	movs r2, #0
	strb r1, [r0]
	ldrb r0, [r4, #1]
	adds r1, r5, #0
	adds r1, #0x95
	strb r0, [r1]
	ldrb r0, [r4, #2]
	adds r1, #1
	strb r0, [r1]
	ldrb r0, [r4, #3]
	adds r1, #1
	strb r0, [r1]
	ldrb r1, [r4, #4]
	adds r0, r5, #0
	adds r0, #0x98
	strb r1, [r0]
	ldrb r0, [r4, #5]
	adds r1, r5, #0
	adds r1, #0x99
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x7c
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
.L080C937C:
	adds r0, r6, #0
.L080C937E:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C9388
sub_080C9388: @ 0x080C9388
.L080C9388:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r5, #0
	adds r0, r4, #0
	bl sub_080C9290
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C93AC
	adds r0, r4, #0
	bl sub_080C9278
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi .L080C93AC
	movs r5, #1
.L080C93AC:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080C93B4
sub_080C93B4: @ 0x080C93B4
.L080C93B4:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r5, #0
	adds r0, r4, #0
	bl sub_080C9290
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C93D6
	adds r0, r4, #0
	bl sub_080C9278
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C93D6
	movs r5, #1
.L080C93D6:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C93E0
sub_080C93E0: @ 0x080C93E0
	ldr r1, .L080C93F4
	ldr r0, .L080C93F8
	str r0, [r1]
	ldr r0, .L080C93FC
	str r0, [r1, #4]
	ldr r0, .L080C9400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C93F4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C93F8: .4byte 0x0200F874 @ EWRAM+0xF874
.L080C93FC: .4byte 0x06014000 @ VRAM+0x14000
.L080C9400: .4byte 0x84000400

	thumb_func_start sub_080C9404
sub_080C9404: @ 0x080C9404
	push {lr}
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C9414
sub_080C9414: @ 0x080C9414
.L080C9414:
	push {r4, r5, r6, lr}
	ldr r6, .L080C9474
	ldrh r0, [r6]
	cmp r0, #5
	bne .L080C946E
	ldrh r0, [r6, #2]
	bl sub_080C92C8
	adds r5, r0, #0
	adds r1, r6, #0
	adds r1, #0x54
	ldr r4, .L080C9478
	adds r2, r4, #0
	bl CpuSet
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldrb r0, [r5, #0xc]
	bl sub_080BF938
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r6, r0
	adds r0, r5, #0
	adds r2, r4, #0
	bl CpuSet
.L080C946E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C9474: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C9478: .4byte 0x04000020 @ REG_BG2PA

	thumb_func_start sub_080C947C
sub_080C947C: @ 0x080C947C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r7, .L080C94B0
	ldr r0, .L080C94B4
	mov sb, r0
	movs r5, #0
	mov r8, r5
	ldr r0, .L080C94B8
	ldr r1, .L080C94BC
	bl LZ77UnCompWram
	ldr r0, .L080C94C0
	movs r1, #1
	bl VBlankTask_AddCounted
	ldrh r0, [r7]
	cmp r0, #0xa
	bls .L080C94A6
	b .L080C9622
.L080C94A6:
	lsls r0, r0, #2
	ldr r1, .L080C94C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080C94B0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C94B4: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080C94B8: .4byte gUnknown_081B5870
.L080C94BC: .4byte 0x0200F874 @ EWRAM+0xF874
.L080C94C0: .4byte sub_080C93E0
.L080C94C4: .4byte gUnknown_080C94C8
	.global gUnknown_080C94C8
gUnknown_080C94C8:
.L080C94C8: @ jump table
	.4byte .L080C94F4
	.4byte .L080C9520
	.4byte .L080C9622
	.4byte .L080C9598
	.4byte .L080C95C4
	.4byte .L080C95C4
	.4byte .L080C95F4
	.4byte .L080C9622
	.4byte .L080C960C
	.4byte .L080C960C
	.4byte .L080C960C
.L080C94F4:
	movs r6, #0
	ldr r1, .L080C951C
.L080C94F8:
	lsls r0, r6, #7
	adds r0, r0, r1
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	beq .L080C950E
	lsls r0, r5, #1
	add r0, sb
	strh r6, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080C950E:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0xf
	bls .L080C94F8
	strh r5, [r7, #0x24]
	b .L080C9622
.L080C951C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C9520:
	movs r6, #0
	b .L080C9576
.L080C9524:
	movs r0, #0xb6
	bl Flag_Test
	cmp r0, #0
	bne .L080C953C
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne .L080C9570
	b .L080C9548
.L080C953C:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne .L080C9562
.L080C9548:
	lsls r0, r5, #1
	add r0, sb
	adds r1, r4, r1
	strh r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	b .L080C9570
.L080C9562:
	lsls r0, r5, #1
	add r0, sb
	orrs r4, r1
	strh r4, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080C9570:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080C9576:
	cmp r6, #0xff
	bhi .L080C958A
	adds r0, r6, #0
	bl sub_0812ACCC
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L080C9594
	cmp r4, r0
	bne .L080C9524
.L080C958A:
	strh r5, [r7, #0x24]
	mov r1, r8
	strh r1, [r7, #0x26]
	b .L080C9622
	.byte 0x00, 0x00
.L080C9594: .4byte 0x0000FFFF
.L080C9598:
	movs r6, #0
	ldr r1, .L080C95C0
.L080C959C:
	lsls r0, r6, #7
	adds r0, r0, r1
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	beq .L080C95B2
	lsls r0, r5, #1
	add r0, sb
	strh r6, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080C95B2:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #3
	bls .L080C959C
	strh r5, [r7, #0x24]
	b .L080C9622
.L080C95C0: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C95C4:
	ldrh r0, [r7, #2]
	lsls r0, r0, #7
	ldr r1, .L080C95EC
	adds r0, r0, r1
	adds r1, r7, #0
	adds r1, #0xd4
	ldr r2, .L080C95F0
	bl CpuSet
	ldrh r0, [r7, #2]
	mov r2, sb
	strh r0, [r2]
	movs r1, #0
	movs r0, #1
	strh r0, [r7, #0x24]
	strh r1, [r7, #2]
	bl sub_080C9414
	b .L080C9622
	.byte 0x00, 0x00
.L080C95EC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C95F0: .4byte 0x04000020 @ REG_BG2PA
.L080C95F4:
	ldr r1, .L080C9608
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ldrh r1, [r1, #6]
	adds r0, r0, r1
	mov r1, sb
	strh r0, [r1]
	b .L080C961A
	.byte 0x00, 0x00
.L080C9608: .4byte 0x0203B854 @ EWRAM+0x3B854
.L080C960C:
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ldrh r1, [r7, #2]
	adds r0, r0, r1
	mov r2, sb
	strh r0, [r2]
.L080C961A:
	movs r1, #0
	movs r0, #1
	strh r0, [r7, #0x24]
	strh r1, [r7, #2]
.L080C9622:
	movs r4, #0
	strh r4, [r7, #0x10]
	ldrh r0, [r7, #2]
	bl sub_080C9388
	cmp r0, #1
	bne .L080C9634
	strh r0, [r7, #0x16]
	b .L080C9636
.L080C9634:
	strh r4, [r7, #0x16]
.L080C9636:
	movs r1, #0
	movs r0, #1
	strh r0, [r7, #0x18]
	strh r1, [r7, #0x1c]
	strh r1, [r7, #0x1e]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080C964C
sub_080C964C: @ 0x080C964C
.L080C964C:
	push {lr}
	lsls r0, r0, #0x10
	ldr r1, .L080C965C
	cmp r0, #0
	bne .L080C9660
	ldrh r0, [r1, #0x24]
	b .L080C966C
	.byte 0x00, 0x00
.L080C965C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C9660:
	ldrh r0, [r1]
	cmp r0, #1
	beq .L080C966A
	ldrh r0, [r1, #0x24]
	b .L080C966C
.L080C966A:
	ldrh r0, [r1, #0x26]
.L080C966C:
	pop {r1}
	bx r1

	thumb_func_start sub_080C9670
sub_080C9670: @ 0x080C9670
	push {lr}
	movs r0, #0
	bl sub_0812CC70
	pop {r0}
	bx r0

	thumb_func_start sub_080C967C
sub_080C967C: @ 0x080C967C
	push {lr}
	movs r0, #1
	bl sub_08128B84
	pop {r0}
	bx r0

	thumb_func_start sub_080C9688
sub_080C9688: @ 0x080C9688
	push {lr}
	movs r0, #2
	bl sub_08128B84
	pop {r0}
	bx r0

	thumb_func_start sub_080C9694
sub_080C9694: @ 0x080C9694
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080C9698
sub_080C9698: @ 0x080C9698
	push {lr}
	movs r0, #0x19
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_080C96A4
sub_080C96A4: @ 0x080C96A4
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080C96A8
sub_080C96A8: @ 0x080C96A8
	push {r4, lr}
	ldr r4, .L080C96BC
	ldrh r0, [r4]
	cmp r0, #0xc
	bhi .L080C973A
	lsls r0, r0, #2
	ldr r1, .L080C96C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080C96BC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C96C0: .4byte gUnknown_080C96C4
	.global gUnknown_080C96C4
gUnknown_080C96C4:
.L080C96C4: @ jump table
	.4byte .L080C96F8
	.4byte .L080C9700
	.4byte .L080C973A
	.4byte .L080C9708
	.4byte .L080C9710
	.4byte .L080C9718
	.4byte .L080C9720
	.4byte .L080C973A
	.4byte .L080C9728
	.4byte .L080C9728
	.4byte .L080C9728
	.4byte .L080C9730
	.4byte .L080C9730
.L080C96F8:
	ldr r0, .L080C96FC
	b .L080C9732
.L080C96FC: .4byte sub_080C9670
.L080C9700:
	ldr r0, .L080C9704
	b .L080C9732
.L080C9704: .4byte sub_080C9688
.L080C9708:
	ldr r0, .L080C970C
	b .L080C9732
.L080C970C: .4byte sub_080C967C
.L080C9710:
	ldr r0, .L080C9714
	b .L080C9732
.L080C9714: .4byte sub_080EA178
.L080C9718:
	ldr r0, .L080C971C
	b .L080C9732
.L080C971C: .4byte sub_080C9694
.L080C9720:
	ldr r0, .L080C9724
	b .L080C9732
.L080C9724: .4byte sub_080C9698
.L080C9728:
	ldr r0, .L080C972C
	b .L080C9732
.L080C972C: .4byte sub_080C9698
.L080C9730:
	ldr r0, .L080C9740
.L080C9732:
	movs r1, #0
	bl sub_080B6B58
	str r0, [r4, #0x38]
.L080C973A:
	pop {r4}
	pop {r0}
	bx r0
.L080C9740: .4byte sub_080C96A4

	thumb_func_start sub_080C9744
sub_080C9744: @ 0x080C9744
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L080C9780
	ldrh r0, [r4, #2]
	bl sub_080C92C8
	ldr r0, [r4, #0x38]
	ldr r1, [r0, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080C9788
	movs r0, #1
	strh r0, [r5, #0x1c]
	ldrh r0, [r4, #2]
	bl sub_080C9388
	cmp r0, #1
	beq .L080C978C
	ldr r2, .L080C9784
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0x10
	strh r1, [r0]
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
	b .L080C978C
.L080C9780: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C9784: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080C9788:
	movs r0, #0
	strh r0, [r5, #0x1c]
.L080C978C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C9794
sub_080C9794: @ 0x080C9794
	ldr r0, .L080C97A0
	ldr r1, [r0, #0x38]
	movs r0, #1
	str r0, [r1, #0xc]
	bx lr
	.byte 0x00, 0x00
.L080C97A0: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080C97A4
sub_080C97A4: @ 0x080C97A4
.L080C97A4:
	push {lr}
	adds r3, r0, #0
	movs r2, #0
.L080C97AA:
	ldm r3!, {r0}
	stm r1!, {r0}
	adds r2, #1
	cmp r2, #0x17
	bls .L080C97AA
	pop {r0}
	bx r0

	thumb_func_start sub_080C97B8
sub_080C97B8: @ 0x080C97B8
.L080C97B8:
	push {r4, r5, r6, lr}
	lsls r5, r0, #1
	adds r5, r5, r0
	lsls r5, r5, #5
	ldr r4, .L080C97E8
	adds r0, r5, r4
	ldr r6, .L080C97EC
	adds r1, r6, #0
	bl sub_080C97A4
	movs r0, #0x80
	lsls r0, r0, #3
	adds r4, r4, r0
	adds r0, r5, r4
	movs r1, #0x80
	lsls r1, r1, #3
	adds r6, r6, r1
	adds r1, r6, #0
	bl sub_080C97A4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C97E8: .4byte gUnknown_081B4F10
.L080C97EC: .4byte 0x0200FC74 @ EWRAM+0xFC74

	thumb_func_start sub_080C97F0
sub_080C97F0: @ 0x080C97F0
.L080C97F0:
	push {r4, lr}
	adds r4, r1, #0
	ldr r0, .L080C9818
	ldrh r0, [r0, #0x22]
	cmp r0, #1
	beq .L080C9810
	movs r0, #1
	bl sub_080C964C
	cmp r0, #1
	beq .L080C9810
	adds r0, r4, #0
	bl sub_080C97B8
	bl sub_080C9994
.L080C9810:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C9818: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080C981C
sub_080C981C: @ 0x080C981C
.L080C981C:
	push {r4, r5, r6, lr}
	lsls r5, r0, #1
	adds r5, r5, r0
	lsls r5, r5, #5
	ldr r4, .L080C984C
	adds r0, r5, r4
	ldr r6, .L080C9850
	adds r1, r6, #0
	bl sub_080C97A4
	movs r0, #0x80
	lsls r0, r0, #3
	adds r4, r4, r0
	adds r0, r5, r4
	movs r1, #0x80
	lsls r1, r1, #3
	adds r6, r6, r1
	adds r1, r6, #0
	bl sub_080C97A4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C984C: .4byte gUnknown_081B4FD0
.L080C9850: .4byte 0x0200FFD4 @ EWRAM+0xFFD4

	thumb_func_start sub_080C9854
sub_080C9854: @ 0x080C9854
.L080C9854:
	push {r4, lr}
	adds r4, r1, #0
	ldr r0, .L080C987C
	ldrh r0, [r0, #0x22]
	cmp r0, #1
	beq .L080C9874
	movs r0, #1
	bl sub_080C964C
	cmp r0, #1
	beq .L080C9874
	adds r0, r4, #0
	bl sub_080C981C
	bl sub_080C9994
.L080C9874:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C987C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080C9880
sub_080C9880: @ 0x080C9880
.L080C9880:
	lsls r0, r0, #0x10
	movs r3, #0x80
	lsls r3, r3, #5
	lsrs r0, r0, #0xf
	ldr r1, .L080C9898
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, .L080C989C
	ands r1, r2
	orrs r1, r3
	strh r1, [r0]
	bx lr
.L080C9898: .4byte 0x06001000 @ VRAM+0x1000
.L080C989C: .4byte 0x00000FFF

	thumb_func_start sub_080C98A0
sub_080C98A0: @ 0x080C98A0
.L080C98A0:
	ldr r2, .L080C98C8
	ldrh r1, [r2]
	ldr r0, .L080C98CC
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, .L080C98D0
	ldr r2, .L080C98D4
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080C98D8
	ldr r3, .L080C98DC
	adds r0, r3, #0
	strh r0, [r1]
	bx lr
.L080C98C8: .4byte 0x0400000C @ REG_BG2CNT
.L080C98CC: .4byte 0x00003FFF
.L080C98D0: .4byte 0x0400000A @ REG_BG1CNT
.L080C98D4: .4byte 0x00004205
.L080C98D8: .4byte 0x03000040 @ IWRAM+0x40
.L080C98DC: .4byte 0x00003844

	thumb_func_start sub_080C98E0
sub_080C98E0: @ 0x080C98E0
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, .L080C996C
	bl sub_080C98A0
	ldr r1, .L080C9970
	ldr r0, .L080C9974
	str r0, [r1]
	ldr r0, .L080C9978
	str r0, [r1, #4]
	ldr r0, .L080C997C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080C9980
	str r0, [r1, #4]
	ldr r0, .L080C9984
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080C9988
	str r0, [r1]
	ldr r0, .L080C998C
	str r0, [r1, #4]
	ldr r0, .L080C9990
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
	bl sub_080C9880
	movs r0, #1
	bl sub_080C9880
	movs r0, #2
	bl sub_080C9880
	movs r0, #0x20
	bl sub_080C9880
	movs r0, #0x21
	bl sub_080C9880
	movs r0, #0x22
	bl sub_080C9880
	movs r0, #0x1b
	bl sub_080C9880
	movs r0, #0x1c
	bl sub_080C9880
	movs r0, #0x1d
	bl sub_080C9880
	movs r0, #0x3b
	bl sub_080C9880
	movs r0, #0x3c
	bl sub_080C9880
	movs r0, #0x3d
	bl sub_080C9880
	strh r4, [r5, #0xc]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C996C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C9970: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C9974: .4byte gUnknown_081B93B0
.L080C9978: .4byte 0x06001000 @ VRAM+0x1000
.L080C997C: .4byte 0x84000200
.L080C9980: .4byte 0x06001800 @ VRAM+0x1800
.L080C9984: .4byte 0x85000200
.L080C9988: .4byte 0x0200F874 @ EWRAM+0xF874
.L080C998C: .4byte 0x06004000 @ VRAM+0x4000
.L080C9990: .4byte 0x84001F00

	thumb_func_start sub_080C9994
sub_080C9994: @ 0x080C9994
.L080C9994:
	push {r4, lr}
	ldr r4, .L080C99B0
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne .L080C99AA
	ldr r0, .L080C99B4
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #1
	strh r0, [r4, #0xc]
.L080C99AA:
	pop {r4}
	pop {r0}
	bx r0
.L080C99B0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C99B4: .4byte sub_080C98E0

	thumb_func_start sub_080C99B8
sub_080C99B8: @ 0x080C99B8
.L080C99B8:
	push {lr}
	ldrb r0, [r0, #0xc]
	movs r0, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start Status_DrawDemonInfo
Status_DrawDemonInfo: @ 0x080C99C4
.L080C99C4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	ldr r5, .L080C9A50
	ldrh r0, [r5, #2]
	bl sub_080C92C8
	adds r7, r0, #0
	ldrh r0, [r7, #0x12]
	bl sub_080BF648
	mov sl, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Race_GetName
	mov r8, r0
	movs r0, #8
	mov sb, r0
	movs r4, #0
	str r4, [sp, #0x28]
	add r0, sp, #0x28
	ldr r6, .L080C9A54
	ldr r2, .L080C9A58
	adds r1, r6, #0
	bl CpuSet
	str r4, [sp, #0x2c]
	add r0, sp, #0x2c
	ldr r2, .L080C9A5C
	add r1, sp, #8
	bl CpuSet
	ldrh r0, [r5, #2]
	bl sub_080C9388
	cmp r0, #0
	bne .L080C9AE4
	ldrh r0, [r7, #0x12]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	cmp r0, #0x6f
	bne .L080C9A6C
	ldr r0, .L080C9A60
	movs r4, #6
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x18
	movs r3, #8
	bl Font_DrawGlyphTinted
	ldr r0, .L080C9A64
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #8
	bl Font_DrawGlyphTinted
	ldr r0, .L080C9A68
	b .L080C9AB4
	.byte 0x00, 0x00
.L080C9A50: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C9A54: .4byte 0x0200F874 @ EWRAM+0xF874
.L080C9A58: .4byte 0x05002000
.L080C9A5C: .4byte 0x05000008 @ PLTT+0x8
.L080C9A60: .4byte 0x00000923
.L080C9A64: .4byte 0x00000C5C
.L080C9A68: .4byte 0x00000A7B
.L080C9A6C:
	cmp r0, #0x93
	bne .L080C9A78
	ldr r0, .L080C9A74
	b .L080C9A96
.L080C9A74: .4byte 0x00000DB4
.L080C9A78:
	cmp r0, #0xa7
	bne .L080C9A84
	ldr r0, .L080C9A80
	b .L080C9A96
.L080C9A80: .4byte 0x00000DC1
.L080C9A84:
	cmp r0, #0xbb
	bne .L080C9A90
	ldr r0, .L080C9A8C
	b .L080C9A96
.L080C9A8C: .4byte 0x0000112D
.L080C9A90:
	cmp r1, #0xcf
	bne .L080C9AD0
	ldr r0, .L080C9AC4
.L080C9A96:
	movs r4, #6
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x18
	movs r3, #8
	bl Font_DrawGlyphTinted
	ldr r0, .L080C9AC8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #8
	bl Font_DrawGlyphTinted
	ldr r0, .L080C9ACC
.L080C9AB4:
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0x30
	movs r3, #8
	bl Font_DrawGlyphTinted
	b .L080C9AE4
	.byte 0x00, 0x00
.L080C9AC4: .4byte 0x00000794
.L080C9AC8: .4byte 0x00000FA9
.L080C9ACC: .4byte 0x00000811
.L080C9AD0:
	movs r0, #6
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0x18
	movs r3, #8
	bl Text_DrawStringTinted
.L080C9AE4:
	ldrh r0, [r7, #0x12]
	bl sub_080C92AC
	cmp r0, #1
	beq .L080C9B54
	adds r0, r7, #0
	bl sub_080C99B8
	cmp r0, #1
	bne .L080C9B20
	ldr r0, .L080C9B18
	mov r4, sb
	adds r4, #2
	movs r1, #0x54
	adds r2, r4, #0
	movs r3, #0
	bl sub_080CCEC8
	ldr r0, .L080C9B1C
	movs r1, #0x64
	adds r2, r4, #0
	movs r3, #4
	bl sub_080CCEC8
	b .L080C9B54
	.byte 0x00, 0x00
.L080C9B18: .4byte gUnknown_084EFAD4
.L080C9B1C: .4byte gUnknown_084EFAD8
.L080C9B20:
	ldr r0, .L080C9B44
	mov r1, sb
	adds r1, #2
	adds r4, r1, #0
	movs r1, #0x54
	adds r2, r4, #0
	movs r3, #0
	bl sub_080CCEC8
	ldrb r0, [r7, #0xd]
	cmp r0, #9
	bhi .L080C9B48
	movs r1, #0x64
	adds r2, r4, #0
	movs r3, #4
	bl sub_080CCFC4
	b .L080C9B54
.L080C9B44: .4byte gUnknown_084EFAD4
.L080C9B48:
	ldrb r0, [r7, #0xd]
	movs r1, #0x6c
	adds r2, r4, #0
	movs r3, #4
	bl sub_080CCFC4
.L080C9B54:
	ldrb r0, [r7, #0xc]
	cmp r0, #3
	bhi .L080C9B90
	adds r0, r7, #0
	add r1, sp, #8
	bl Combatant_DecodeName
	movs r6, #0
	movs r5, #0xf0
	lsls r5, r5, #0xf
	add r4, sp, #8
.L080C9B6A:
	ldrh r0, [r4]
	lsrs r2, r5, #0x10
	movs r1, #0
	str r1, [sp]
	ldr r1, .L080C9B8C
	mov r3, sb
	bl Font_DrawGlyphTinted
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r5, r5, r1
	adds r4, #2
	adds r6, #1
	cmp r6, #7
	bls .L080C9B6A
	b .L080C9BB8
	.byte 0x00, 0x00
.L080C9B8C: .4byte 0x0200F874 @ EWRAM+0xF874
.L080C9B90:
	movs r6, #0
	movs r5, #0xf0
	lsls r5, r5, #0xf
	mov r4, sl
	adds r4, #0x22
.L080C9B9A:
	ldrh r0, [r4]
	lsrs r2, r5, #0x10
	movs r1, #0
	str r1, [sp]
	ldr r1, .L080C9BC8
	mov r3, sb
	bl Font_DrawGlyphTinted
	movs r0, #0xc0
	lsls r0, r0, #0xc
	adds r5, r5, r0
	adds r4, #2
	adds r6, #1
	cmp r6, #7
	bls .L080C9B9A
.L080C9BB8:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080C9BC8: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080C9BCC
sub_080C9BCC: @ 0x080C9BCC
.L080C9BCC:
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, .L080C9BFC
	movs r0, #0
	strh r0, [r5, #0x10]
	strh r0, [r5, #0x1c]
	strh r0, [r5, #0x1e]
	adds r0, r4, #0
	movs r1, #0
	bl sub_080C97F0
	adds r0, r4, #0
	movs r1, #0
	bl sub_080C9854
	ldrh r0, [r5, #4]
	cmp r0, #5
	bhi .L080C9CC4
	lsls r0, r0, #2
	ldr r1, .L080C9C00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080C9BFC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C9C00: .4byte gUnknown_080C9C04
	.global gUnknown_080C9C04
gUnknown_080C9C04:
.L080C9C04: @ jump table
	.4byte .L080C9C1C
	.4byte .L080C9C44
	.4byte .L080C9C52
	.4byte .L080C9C5C
	.4byte .L080C9C66
	.4byte .L080C9C9C
.L080C9C1C:
	movs r0, #0
	adds r1, r4, #0
	bl sub_080CB0B8
	ldr r2, [r5, #0x3c]
	cmp r2, #0
	beq .L080C9CC4
	ldr r0, .L080C9C40
	ldrh r1, [r0]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r2, #0
	movs r2, #0x18
	bl sub_080C3E5C
	b .L080C9CC4
	.byte 0x00, 0x00
.L080C9C40: .4byte 0x03000004 @ IWRAM+0x4
.L080C9C44:
	movs r0, #0
	adds r1, r4, #0
	bl sub_080CB71C
	movs r0, #1
	strh r0, [r5, #0x10]
	b .L080C9CC4
.L080C9C52:
	movs r0, #0
	adds r1, r4, #0
	bl sub_080CB7A0
	b .L080C9CC4
.L080C9C5C:
	movs r0, #0
	adds r1, r4, #0
	bl sub_080CB8C8
	b .L080C9CC4
.L080C9C66:
	movs r0, #0
	adds r1, r4, #0
	bl sub_080CB928
	ldr r2, [r5, #0x3c]
	cmp r2, #0
	beq .L080C9C8A
	ldr r0, .L080C9C94
	ldrh r0, [r0]
	ldr r3, .L080C9C98
	adds r1, r3, #0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r2, #0
	movs r2, #0x18
	bl sub_080C3E5C
.L080C9C8A:
	movs r0, #1
	strh r0, [r5, #0x1e]
	strh r0, [r5, #0x10]
	b .L080C9CC4
	.byte 0x00, 0x00
.L080C9C94: .4byte 0x03000004 @ IWRAM+0x4
.L080C9C98: .4byte 0xFFFFFF00
.L080C9C9C:
	movs r0, #0
	adds r1, r4, #0
	bl Status_DrawDropItem
	ldr r2, [r5, #0x3c]
	cmp r2, #0
	beq .L080C9CC0
	ldr r0, .L080C9CD0
	ldrh r0, [r0]
	ldr r3, .L080C9CD4
	adds r1, r3, #0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r2, #0
	movs r2, #0x18
	bl sub_080C3E5C
.L080C9CC0:
	movs r0, #1
	strh r0, [r5, #0x1c]
.L080C9CC4:
	bl sub_080C9994
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C9CD0: .4byte 0x03000004 @ IWRAM+0x4
.L080C9CD4: .4byte 0xFFFFFF00

	thumb_func_start sub_080C9CD8
sub_080C9CD8: @ 0x080C9CD8
.L080C9CD8:
	push {lr}
	sub sp, #8
	ldr r1, .L080C9CFC
	movs r0, #0xa0
	str r0, [sp]
	movs r0, #0x6a
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0x1c
	bl Canvas_FillRect
	bl sub_080C9994
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C9CFC: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080C9D00
sub_080C9D00: @ 0x080C9D00
.L080C9D00:
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, .L080C9D1C
	ldrh r0, [r5, #2]
	bl sub_080C92C8
	ldrh r0, [r5, #6]
	cmp r0, #1
	beq .L080C9D30
	cmp r0, #1
	bgt .L080C9D20
	cmp r0, #0
	beq .L080C9D26
	b .L080C9D42
.L080C9D1C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C9D20:
	cmp r0, #2
	beq .L080C9D3A
	b .L080C9D42
.L080C9D26:
	movs r0, #0
	adds r1, r4, #0
	bl sub_080CBC8C
	b .L080C9D42
.L080C9D30:
	movs r0, #0
	adds r1, r4, #0
	bl sub_080CC630
	b .L080C9D42
.L080C9D3A:
	movs r0, #0
	adds r1, r4, #0
	bl sub_080CC694
.L080C9D42:
	ldrh r0, [r5, #2]
	bl sub_080C9388
	cmp r0, #1
	beq .L080C9D4E
	movs r0, #0
.L080C9D4E:
	strh r0, [r5, #0x16]
	bl sub_080C9994
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C9D5C
sub_080C9D5C: @ 0x080C9D5C
.L080C9D5C:
	push {lr}
	sub sp, #8
	ldr r1, .L080C9D80
	movs r0, #0x1c
	str r0, [sp]
	movs r0, #0x6a
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0xd4
	movs r3, #0x1c
	bl Canvas_FillRect
	bl sub_080C9994
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C9D80: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080C9D84
sub_080C9D84: @ 0x080C9D84
.L080C9D84:
	push {r4, r5, lr}
	sub sp, #4
	adds r3, r0, #0
	ldr r4, .L080C9DB0
	ldr r2, .L080C9DB4
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x2e]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r5, [r0]
	movs r0, #0
	strh r0, [r4, #0x32]
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #8]
	cmp r0, #1
	beq .L080C9DCC
	cmp r0, #1
	bgt .L080C9DB8
	cmp r0, #0
	beq .L080C9DC2
	b .L080C9DFA
.L080C9DB0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C9DB4: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080C9DB8:
	cmp r0, #2
	beq .L080C9DD6
	cmp r0, #3
	beq .L080C9DEE
	b .L080C9DFA
.L080C9DC2:
	movs r0, #0
	adds r1, r3, #0
	bl sub_080CC844
	b .L080C9DF6
.L080C9DCC:
	movs r0, #0
	adds r1, r3, #0
	bl sub_080CCA10
	b .L080C9DFA
.L080C9DD6:
	movs r0, #0
	adds r1, r3, #0
	bl sub_080CCAB4
	adds r0, r5, #0
	movs r1, #0
	mov r2, sp
	bl sub_080BF468
	ldr r0, [sp]
	strh r0, [r4, #0x32]
	b .L080C9DFA
.L080C9DEE:
	movs r0, #0
	adds r1, r3, #0
	bl sub_080CCD5C
.L080C9DF6:
	movs r0, #1
	strh r0, [r4, #0x18]
.L080C9DFA:
	bl sub_080C9994
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C9E08
sub_080C9E08: @ 0x080C9E08
.L080C9E08:
	push {lr}
	sub sp, #8
	ldr r1, .L080C9E2C
	movs r0, #0xf0
	str r0, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0x88
	bl Canvas_FillRect
	bl sub_080C9994
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C9E2C: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080C9E30
sub_080C9E30: @ 0x080C9E30
.L080C9E30:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r6, .L080C9EA4
	movs r0, #0
	str r0, [sp, #8]
	ldr r1, .L080C9EA8
	ldr r2, .L080C9EAC
	add r0, sp, #8
	bl CpuSet
	movs r4, #2
	str r4, [sp]
	ldr r0, .L080C9EB0
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #2
	movs r2, #0x14
	movs r3, #0xe
	bl TextWindow_CreateOpenWithFrame
	str r0, [r6, #0x40]
	str r4, [sp]
	ldr r0, .L080C9EB4
	str r0, [sp, #4]
	movs r0, #0x14
	movs r1, #2
	movs r2, #0xa
	movs r3, #0xe
	bl TextWindow_CreateOpenWithFrame
	str r0, [r6, #0x44]
	str r4, [sp]
	ldr r0, .L080C9EB8
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #4
	bl TextWindow_CreateOpenWithFrame
	str r0, [r6, #0x48]
	adds r0, r5, #0
	bl Status_DrawDemonInfo
	adds r0, r5, #0
	bl sub_080C9BCC
	adds r0, r5, #0
	bl sub_080C9D00
	adds r0, r5, #0
	bl sub_080C9D84
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C9EA4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C9EA8: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C9EAC: .4byte 0x05000200 @ PLTT+0x200
.L080C9EB0: .4byte gUnknown_084EFA9C
.L080C9EB4: .4byte gUnknown_084EFAAE
.L080C9EB8: .4byte gUnknown_084EFAC0

	thumb_func_start sub_080C9EBC
sub_080C9EBC: @ 0x080C9EBC
	ldr r2, .L080C9EE8
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r2, .L080C9EEC
	ldrh r1, [r2]
	movs r0, #0xff
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r3, .L080C9EF0
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, .L080C9EF4
	movs r1, #0
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C9EE8: .4byte 0x04000200 @ REG_IE
.L080C9EEC: .4byte 0x04000004 @ REG_DISPSTAT
.L080C9EF0: .4byte 0x00008024
.L080C9EF4: .4byte 0x04000014 @ REG_BG1HOFS

	thumb_func_start sub_080C9EF8
sub_080C9EF8: @ 0x080C9EF8
	ldr r0, .L080C9F08
	ldr r1, .L080C9F0C
	ldrh r2, [r0, #0x1a]
	strh r2, [r1]
	ldr r0, .L080C9F10
	strh r2, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C9F08: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C9F0C: .4byte 0x04000014 @ REG_BG1HOFS
.L080C9F10: .4byte 0x04000018 @ REG_BG2HOFS

	thumb_func_start sub_080C9F14
sub_080C9F14: @ 0x080C9F14
	push {lr}
	ldr r3, .L080C9F30
	ldr r2, .L080C9F34
	ldr r0, .L080C9F38
	str r0, [r2, #8]
	ldrh r0, [r3, #0x1a]
	adds r0, r0, r1
	strh r0, [r3, #0x1a]
	ldr r0, .L080C9F3C
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	pop {r0}
	bx r0
.L080C9F30: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080C9F34: .4byte 0x030020F0 @ IWRAM+0x20F0
.L080C9F38: .4byte sub_080C9EF8
.L080C9F3C: .4byte sub_080C9EBC

	thumb_func_start sub_080C9F40
sub_080C9F40: @ 0x080C9F40
	ldr r2, .L080C9F68
	ldrh r1, [r2]
	ldr r0, .L080C9F6C
	ands r0, r1
	strh r0, [r2]
	ldr r2, .L080C9F70
	ldrh r1, [r2]
	ldr r0, .L080C9F74
	ands r0, r1
	strh r0, [r2]
	ldr r0, .L080C9F78
	movs r1, #0
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	ldr r1, .L080C9F7C
	ldr r0, .L080C9F80
	str r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C9F68: .4byte 0x04000200 @ REG_IE
.L080C9F6C: .4byte 0x0000FFFB
.L080C9F70: .4byte 0x04000004 @ REG_DISPSTAT
.L080C9F74: .4byte 0x0000FFDB
.L080C9F78: .4byte 0x04000014 @ REG_BG1HOFS
.L080C9F7C: .4byte 0x030020F0 @ IWRAM+0x20F0
.L080C9F80: .4byte IntrDummy

	thumb_func_start sub_080C9F84
sub_080C9F84: @ 0x080C9F84
	push {lr}
	ldr r0, .L080C9F94
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C9F94: .4byte sub_080C9F40

	thumb_func_start sub_080C9F98
sub_080C9F98: @ 0x080C9F98
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	str r0, [sp, #0x10]
	ldr r0, .L080CA040
	mov sb, r0
	ldrh r0, [r0, #2]
	bl sub_080C92C8
	adds r7, r0, #0
	mov r1, sb
	ldrh r0, [r1, #0x16]
	cmp r0, #1
	bne .L080C9FDE
	ldr r0, .L080CA044
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA048
	ldrh r2, [r1]
	movs r1, #0xa0
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x18
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080C9FDE:
	mov r2, sb
	ldrh r0, [r2, #0x1c]
	cmp r0, #1
	bne .L080C9FF2
	movs r0, #0
	movs r1, #0
	movs r2, #0x92
	movs r3, #0x14
	bl sub_080C4A4C
.L080C9FF2:
	mov r3, sb
	ldrh r0, [r3, #0x1e]
	cmp r0, #1
	bne .L080CA006
	movs r0, #0
	movs r1, #0
	movs r2, #0x92
	movs r3, #0x76
	bl sub_080C4AB0
.L080CA006:
	mov r1, sb
	ldrh r0, [r1, #2]
	bl sub_080C9388
	cmp r0, #1
	bne .L080CA050
	mov r2, sb
	ldrh r0, [r2, #0x10]
	cmp r0, #1
	bne .L080CA0B0
	ldr r0, .L080CA04C
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA048
	ldrh r2, [r1]
	movs r1, #8
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x11
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #2
	bl Sprite_Draw
	b .L080CA0B0
.L080CA040: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CA044: .4byte gUnknown_0800146C
.L080CA048: .4byte 0x03000004 @ IWRAM+0x4
.L080CA04C: .4byte gUnknown_080014A0
.L080CA050:
	mov r3, sb
	ldrh r0, [r3, #0x10]
	cmp r0, #1
	bne .L080CA0B0
	ldrh r0, [r3, #0x12]
	cmp r0, #0
	beq .L080CA082
	ldr r0, .L080CA0C8
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA0CC
	ldrh r2, [r1]
	movs r1, #8
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrh r1, [r3, #0x12]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080CA082:
	mov r1, sb
	ldrh r0, [r1, #0x14]
	cmp r0, #0
	beq .L080CA0B0
	ldr r0, .L080CA0D0
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA0CC
	ldrh r2, [r1]
	movs r1, #8
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	mov r2, sb
	ldrh r1, [r2, #0x14]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080CA0B0:
	mov r3, sb
	ldrh r0, [r3, #0x18]
	cmp r0, #1
	beq .L080CA0BA
	b .L080CA51E
.L080CA0BA:
	ldrh r0, [r3, #0x1a]
	cmp r0, #0
	bne .L080CA0D4
	ldr r0, .L080CA0CC
	ldrh r2, [r0]
	b .L080CA0D8
	.byte 0x00, 0x00
.L080CA0C8: .4byte gUnknown_08001630
.L080CA0CC: .4byte 0x03000004 @ IWRAM+0x4
.L080CA0D0: .4byte gUnknown_08001780
.L080CA0D4:
	mov r0, sb
	ldrh r2, [r0, #0x1a]
.L080CA0D8:
	ldr r0, .L080CA1D4
	movs r1, #0x80
	lsls r1, r1, #2
	mov sl, r1
	str r1, [sp]
	movs r1, #0x77
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x81
	str r1, [sp, #8]
	movs r1, #3
	movs r2, #0
	movs r3, #2
	bl Sprite_Draw
	ldrh r0, [r7, #0x12]
	bl sub_080C92AC
	cmp r0, #1
	beq .L080CA106
	b .L080CA224
.L080CA106:
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0x16
	mov r8, r2
	str r2, [sp]
	movs r4, #0x86
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x41
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r6, #0x63
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x42
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r5, #0xb0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x43
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, r8
	str r3, [sp]
	movs r4, #0x93
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x44
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x45
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl sub_080CD9C8
	ldrh r0, [r7, #0x12]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	add r2, sp, #0xc
	bl sub_080BF468
	ldr r0, [sp, #0xc]
	cmp r0, #0x80
	beq .L080CA1EC
	cmp r0, #0x80
	bgt .L080CA1D8
	cmp r0, #0x40
	beq .L080CA1F8
	b .L080CA51E
	.byte 0x00, 0x00
.L080CA1D4: .4byte gUnknown_08001620
.L080CA1D8:
	cmp r0, #0xc0
	beq .L080CA1DE
	b .L080CA51E
.L080CA1DE:
	ldr r0, .L080CA1E8
	mov r1, sl
	str r1, [sp]
	b .L080CA1FE
	.byte 0x00, 0x00
.L080CA1E8: .4byte gUnknown_080014D8
.L080CA1EC:
	ldr r0, .L080CA1F4
	mov r2, sl
	str r2, [sp]
	b .L080CA1FE
.L080CA1F4: .4byte gUnknown_080014B0
.L080CA1F8:
	ldr r0, .L080CA21C
	mov r3, sl
	str r3, [sp]
.L080CA1FE:
	ldr r1, .L080CA220
	ldrh r2, [r1]
	movs r1, #0xd8
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x45
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	b .L080CA51E
.L080CA21C: .4byte gUnknown_080014C0
.L080CA220: .4byte 0x03000004 @ IWRAM+0x4
.L080CA224:
	adds r0, r7, #0
	bl sub_080C99B8
	cmp r0, #1
	bne .L080CA230
	b .L080CA51E
.L080CA230:
	movs r0, #0
	mov sl, r0
	movs r1, #0
	str r1, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x18]
	movs r3, #0
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, .L080CA3FC
	ldrh r0, [r0]
	ldr r1, .L080CA400
	ands r1, r0
	movs r2, #0x30
	adds r2, r2, r7
	mov r8, r2
	adds r3, r7, #0
	adds r3, #0x38
	str r3, [sp, #0x44]
	adds r0, r7, #0
	adds r0, #0x31
	str r0, [sp, #0x30]
	adds r2, r7, #0
	adds r2, #0x39
	str r2, [sp, #0x48]
	subs r3, #6
	str r3, [sp, #0x34]
	adds r0, #9
	str r0, [sp, #0x4c]
	subs r2, #6
	str r2, [sp, #0x38]
	adds r3, #9
	str r3, [sp, #0x50]
	subs r0, #6
	str r0, [sp, #0x3c]
	adds r2, #9
	str r2, [sp, #0x54]
	subs r3, #6
	str r3, [sp, #0x40]
	adds r0, #9
	str r0, [sp, #0x58]
	cmp r1, #0
	bne .L080CA30E
	ldrb r0, [r7, #0xc]
	cmp r0, #0
	bne .L080CA30E
	movs r4, #0
	ldr r6, .L080CA404
	movs r5, #0xf
.L080CA294:
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls .L080CA304
	lsls r2, r4, #2
	adds r0, r2, #1
	adds r0, r0, r6
	ldrb r1, [r0]
	lsrs r0, r1, #4
	add r0, sl
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ands r1, r5
	ldr r3, [sp, #0x14]
	adds r1, r3, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	adds r0, r2, #2
	adds r0, r0, r6
	ldrb r1, [r0]
	lsrs r0, r1, #4
	ldr r3, [sp, #0x18]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	ands r1, r5
	ldr r0, [sp, #0x1c]
	adds r1, r0, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x1c]
	adds r2, #3
	adds r2, r2, r6
	ldrb r1, [r2]
	lsrs r0, r1, #4
	ldr r2, [sp, #0x20]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x20]
	ands r1, r5
	ldr r3, [sp, #0x24]
	adds r1, r3, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x24]
.L080CA304:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xb
	bls .L080CA294
.L080CA30E:
	ldrh r1, [r7, #0x10]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #7
	bne .L080CA320
	ldrh r0, [r7, #0x12]
	bl sub_080C3560
	ldrh r1, [r0, #0x10]
.L080CA320:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r1, r0
	cmp r1, #0
	beq .L080CA408
	mov r3, r8
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x44]
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0x16
	mov r8, r3
	str r3, [sp]
	movs r4, #0x86
	str r4, [sp, #4]
	movs r0, #1
	mov r3, sl
	bl sub_080CD9C8
	ldr r0, [sp, #0x30]
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x48]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r6, #0x63
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #1
	ldr r3, [sp, #0x14]
	bl sub_080CD9C8
	ldr r0, [sp, #0x34]
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x4c]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r5, #0xb0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #1
	ldr r3, [sp, #0x18]
	bl sub_080CD9C8
	ldr r0, [sp, #0x38]
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x50]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, r8
	str r0, [sp]
	movs r4, #0x93
	str r4, [sp, #4]
	movs r0, #1
	ldr r3, [sp, #0x1c]
	bl sub_080CD9C8
	ldr r2, [sp, #0x3c]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x54]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0x28
	ldr r3, [sp, #0x20]
	bl sub_080CD9C8
	ldr r0, [sp, #0x40]
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x58]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #1
	ldr r3, [sp, #0x24]
	bl sub_080CD9C8
	b .L080CA51E
	.byte 0x00, 0x00
.L080CA3FC: .4byte 0x03000004 @ IWRAM+0x4
.L080CA400: .4byte 0x000001FF
.L080CA404: .4byte gUnknown_081A6ED4
.L080CA408:
	adds r0, r7, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, r8
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x44]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0x16
	mov r8, r3
	str r3, [sp]
	movs r4, #0x86
	str r4, [sp, #4]
	mov r3, sl
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x30]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x48]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r6, #0x63
	str r6, [sp]
	str r4, [sp, #4]
	ldr r3, [sp, #0x14]
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x34]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x4c]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r5, #0xb0
	str r5, [sp]
	str r4, [sp, #4]
	ldr r3, [sp, #0x18]
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x38]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x50]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r3, r8
	str r3, [sp]
	movs r4, #0x93
	str r4, [sp, #4]
	ldr r3, [sp, #0x1c]
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x3c]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x54]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r6, [sp]
	str r4, [sp, #4]
	ldr r3, [sp, #0x20]
	bl sub_080CD9C8
	adds r0, r7, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x40]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [sp, #0x58]
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r5, [sp]
	str r4, [sp, #4]
	ldr r3, [sp, #0x24]
	bl sub_080CD9C8
.L080CA51E:
	mov r1, sb
	ldrh r0, [r1, #0x32]
	cmp r0, #0x80
	beq .L080CA53C
	cmp r0, #0x80
	bgt .L080CA530
	cmp r0, #0x40
	beq .L080CA56C
	b .L080CA590
.L080CA530:
	cmp r0, #0xc0
	bne .L080CA590
	ldr r0, .L080CA538
	b .L080CA53E
.L080CA538: .4byte gUnknown_080014D8
.L080CA53C:
	ldr r0, .L080CA564
.L080CA53E:
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA568
	ldrh r2, [r1]
	movs r1, #0xd0
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x8c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	b .L080CA590
	.byte 0x00, 0x00
.L080CA564: .4byte gUnknown_080014B0
.L080CA568: .4byte 0x03000004 @ IWRAM+0x4
.L080CA56C:
	ldr r0, .L080CA5B8
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r1, .L080CA5BC
	ldrh r2, [r1]
	movs r1, #0xd0
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x8c
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080CA590:
	ldr r0, .L080CA5C0
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne .L080CA5EA
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #3
	beq .L080CA5C4
	ldrh r0, [r2, #4]
	cmp r0, #0
	bne .L080CA5D8
	ldrh r4, [r2, #0x20]
	adds r0, r4, #1
	movs r1, #1
	ands r0, r1
	strh r0, [r2, #0x20]
	b .L080CA5DA
	.byte 0x00, 0x00
.L080CA5B8: .4byte gUnknown_080014C0
.L080CA5BC: .4byte 0x03000004 @ IWRAM+0x4
.L080CA5C0: .4byte 0x030031BC @ IWRAM+0x31BC
.L080CA5C4:
	mov r3, sb
	ldrh r0, [r3, #4]
	cmp r0, #1
	bne .L080CA5D8
	ldrh r4, [r3, #0x20]
	adds r0, r4, #1
	movs r1, #1
	ands r0, r1
	strh r0, [r3, #0x20]
	b .L080CA5DA
.L080CA5D8:
	movs r4, #0
.L080CA5DA:
	ldr r0, [sp, #0x10]
	adds r1, r4, #0
	bl sub_080C97F0
	ldr r0, [sp, #0x10]
	adds r1, r4, #0
	bl sub_080C9854
.L080CA5EA:
	mov r1, sb
	ldrh r0, [r1]
	subs r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L080CA670
	ldrh r0, [r1, #0x2c]
	cmp r0, #5
	bhi .L080CA650
	lsls r0, r0, #2
	ldr r1, .L080CA608
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080CA608: .4byte gUnknown_080CA60C
	.global gUnknown_080CA60C
gUnknown_080CA60C:
.L080CA60C: @ jump table
	.4byte .L080CA624
	.4byte .L080CA628
	.4byte .L080CA630
	.4byte .L080CA63A
	.4byte .L080CA63E
	.4byte .L080CA648
.L080CA624:
	movs r2, #5
	b .L080CA632
.L080CA628:
	movs r0, #0x52
	str r0, [sp, #0x28]
	movs r1, #0x82
	b .L080CA64E
.L080CA630:
	movs r2, #0x9f
.L080CA632:
	str r2, [sp, #0x28]
	movs r3, #0x82
	str r3, [sp, #0x2c]
	b .L080CA650
.L080CA63A:
	movs r0, #5
	b .L080CA64A
.L080CA63E:
	movs r2, #0x52
	str r2, [sp, #0x28]
	movs r3, #0x8f
	str r3, [sp, #0x2c]
	b .L080CA650
.L080CA648:
	movs r0, #0x9f
.L080CA64A:
	str r0, [sp, #0x28]
	movs r1, #0x8f
.L080CA64E:
	str r1, [sp, #0x2c]
.L080CA650:
	ldr r0, .L080CA680
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp]
	ldr r2, [sp, #0x28]
	str r2, [sp, #4]
	ldr r1, [sp, #0x2c]
	adds r1, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #2
	bl Sprite_Draw
.L080CA670:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CA680: .4byte gUnknown_08001770

	thumb_func_start sub_080CA684
sub_080CA684: @ 0x080CA684
.L080CA684:
	ldr r1, .L080CA690
	movs r0, #0
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	strh r0, [r1, #8]
	bx lr
.L080CA690: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CA694
sub_080CA694: @ 0x080CA694
.L080CA694:
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r4, .L080CA6AC
	lsls r0, r0, #0x10
	cmp r0, #0
	ble .L080CA6D8
.L080CA6A0:
	ldrh r1, [r4, #2]
	subs r0, r5, #1
	cmp r1, r0
	beq .L080CA6B0
	adds r0, r1, #1
	b .L080CA6B2
.L080CA6AC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CA6B0:
	movs r0, #0
.L080CA6B2:
	strh r0, [r4, #2]
	ldrh r0, [r4]
	cmp r0, #1
	bne .L080CA70E
	movs r0, #0xb6
	bl Flag_Test
	cmp r0, #0
	beq .L080CA708
	ldrh r0, [r4, #2]
	bl sub_080C92C8
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	bl sub_080C2554
	cmp r0, #0
	bne .L080CA708
	b .L080CA6A0
.L080CA6D8:
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq .L080CA6E2
	subs r0, #1
	b .L080CA6E4
.L080CA6E2:
	subs r0, r5, #1
.L080CA6E4:
	strh r0, [r4, #2]
	ldrh r0, [r4]
	cmp r0, #1
	bne .L080CA70E
	movs r0, #0xb6
	bl Flag_Test
	cmp r0, #0
	beq .L080CA708
	ldrh r0, [r4, #2]
	bl sub_080C92C8
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	bl sub_080C2554
	cmp r0, #0
	beq .L080CA6D8
.L080CA708:
	ldr r1, .L080CA714
	ldrh r0, [r4, #2]
	strh r0, [r1, #0x12]
.L080CA70E:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080CA714: .4byte 0x03006450 @ IWRAM+0x6450

	thumb_func_start sub_080CA718
sub_080CA718: @ 0x080CA718
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r7, .L080CA750
	ldrh r0, [r7, #2]
	bl sub_080C92C8
	movs r0, #0
	bl sub_080C964C
	mov sb, r0
	movs r0, #1
	bl sub_080C964C
	mov r8, r0
	movs r0, #0
	strh r0, [r5, #0x1e]
	ldrh r0, [r7, #2]
	bl sub_080C9388
	cmp r0, #1
	bne .L080CA754
	movs r4, #1
	movs r6, #0x65
	b .L080CA764
	.byte 0x00, 0x00
.L080CA750: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CA754:
	movs r4, #0x80
	movs r6, #0x64
	movs r0, #0
	movs r1, #0
	movs r2, #0x92
	movs r3, #0x76
	bl sub_080C4AB0
.L080CA764:
	ldr r1, .L080CA788
	ldrh r0, [r1]
	ands r4, r0
	adds r2, r1, #0
	cmp r4, #0
	beq .L080CA7BC
	ldrh r0, [r7, #2]
	bl sub_080C93B4
	cmp r0, #1
	bne .L080CA790
	adds r0, r6, #0
	bl sub_080C51D4
	ldr r0, .L080CA78C
	strh r0, [r5, #0x1e]
	b .L080CA83E
	.byte 0x00, 0x00
.L080CA788: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CA78C: .4byte 0x00008001
.L080CA790:
	ldrh r0, [r7, #2]
	bl sub_080C9388
	cmp r0, #1
	bne .L080CA7AC
	adds r0, r6, #0
	bl sub_080C51D4
	ldr r0, .L080CA7A8
	strh r0, [r5, #0x1e]
	b .L080CA83E
	.byte 0x00, 0x00
.L080CA7A8: .4byte 0x00008002
.L080CA7AC:
	adds r0, r6, #0
	bl sub_080C51D4
	ldr r0, .L080CA7B8
	strh r0, [r5, #0x1e]
	b .L080CA83E
.L080CA7B8: .4byte 0x00008003
.L080CA7BC:
	ldrh r1, [r2]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CA7D4
	movs r0, #0x66
	bl sub_080C51D4
	movs r0, #3
	strh r0, [r5, #0x1e]
	b .L080CA83E
.L080CA7D4:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CA80C
	ldrh r0, [r7, #0x22]
	cmp r0, #0
	bne .L080CA80C
	mov r0, r8
	cmp r0, #1
	beq .L080CA80C
	movs r0, #0x64
	bl sub_080C51D4
	movs r0, #1
	rsbs r0, r0, #0
	mov r1, sb
	bl sub_080CA694
	ldr r0, .L080CA808
	strh r0, [r7, #0xa]
	strh r4, [r5, #0x1e]
	bl sub_080CA684
	b .L080CA83E
.L080CA808: .4byte 0x0000FFF0
.L080CA80C:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080CA83E
	ldrh r0, [r7, #0x22]
	cmp r0, #0
	bne .L080CA83E
	mov r0, r8
	cmp r0, #1
	beq .L080CA83E
	movs r0, #0x64
	bl sub_080C51D4
	movs r0, #1
	mov r1, sb
	bl sub_080CA694
	movs r0, #0x10
	strh r0, [r7, #0xa]
	movs r0, #2
	strh r0, [r5, #0x1e]
	bl sub_080CA684
.L080CA83E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CA84C
sub_080CA84C: @ 0x080CA84C
.L080CA84C:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r0, .L080CA898
	mov ip, r0
	movs r1, #0
	movs r3, #0
	ldr r7, .L080CA89C
	ldr r6, .L080CA8A0
.L080CA862:
	lsls r0, r3, #2
	adds r2, r0, r6
	ldrh r0, [r2, #2]
	cmp r0, #0
	beq .L080CA884
	ldrh r2, [r2]
	adds r0, r2, #0
	cmp r0, r5
	blo .L080CA884
	cmp r0, r4
	bhi .L080CA884
	lsls r0, r1, #1
	add r0, ip
	strh r2, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
.L080CA884:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r7
	bls .L080CA862
	adds r0, r1, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080CA898: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080CA89C: .4byte 0x00000159
.L080CA8A0: .4byte 0x030051AC @ IWRAM+0x51AC

	thumb_func_start sub_080CA8A4
sub_080CA8A4: @ 0x080CA8A4
.L080CA8A4:
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r6, .L080CA8DC
	mov r1, sp
	ldr r2, .L080CA8E0
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080CA8E4
	ldr r2, .L080CA8E8
	mov r0, sp
	bl CpuSet
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080CA84C
	strh r0, [r6, #0x28]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CA8DC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CA8E0: .4byte 0x0000FFFF
.L080CA8E4: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080CA8E8: .4byte 0x01000080

	thumb_func_start sub_080CA8EC
sub_080CA8EC: @ 0x080CA8EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r4, .L080CA920
	movs r0, #0
	strh r0, [r6, #0x1e]
	ldr r2, .L080CA924
	ldrh r1, [r2]
	movs r0, #1
	mov sb, r0
	ands r0, r1
	cmp r0, #0
	beq .L080CA98E
	ldrh r0, [r4, #0x2c]
	cmp r0, #1
	beq .L080CA944
	cmp r0, #1
	bgt .L080CA928
	cmp r0, #0
	beq .L080CA932
	b .L080CA968
	.byte 0x00, 0x00
.L080CA920: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CA924: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CA928:
	cmp r0, #2
	beq .L080CA954
	cmp r0, #3
	beq .L080CA95E
	b .L080CA968
.L080CA932:
	movs r0, #0x90
	lsls r0, r0, #1
	ldr r1, .L080CA940
	bl sub_080CA8A4
	b .L080CA968
	.byte 0x00, 0x00
.L080CA940: .4byte 0x0000012B
.L080CA944:
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r1, .L080CA950
	bl sub_080CA8A4
	b .L080CA968
.L080CA950: .4byte 0x0000011F
.L080CA954:
	movs r0, #0xd0
	movs r1, #0xff
	bl sub_080CA8A4
	b .L080CA968
.L080CA95E:
	movs r0, #0x96
	lsls r0, r0, #1
	ldr r1, .L080CA978
	bl sub_080CA8A4
.L080CA968:
	ldrh r0, [r4, #0x28]
	cmp r0, #0
	bne .L080CA97C
	movs r0, #0x68
	bl sub_080C51D4
	b .L080CAA68
	.byte 0x00, 0x00
.L080CA978: .4byte 0x00000159
.L080CA97C:
	movs r0, #0x65
	bl sub_080C51D4
	movs r1, #0
	movs r0, #1
	strh r0, [r6, #0x1e]
	strh r1, [r4, #0x2e]
	strh r1, [r4, #0x2c]
	b .L080CAA68
.L080CA98E:
	ldrh r1, [r2]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	beq .L080CA9A8
	movs r0, #0x66
	bl sub_080C51D4
	strh r5, [r6, #0x1e]
	b .L080CAA22
.L080CA9A8:
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne .L080CA9BC
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080CA9DE
.L080CA9BC:
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	beq .L080CAA20
	cmp r0, #1
	beq .L080CA9FE
	cmp r0, #2
	bne .L080CA9D4
	strh r7, [r4, #0x2c]
	b .L080CAA22
.L080CA9D4:
	cmp r0, #3
	bne .L080CAA22
	mov r0, sb
	strh r0, [r4, #0x2c]
	b .L080CAA22
.L080CA9DE:
	ldrh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq .L080CAA04
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	beq .L080CA9FE
	subs r0, #1
	strh r0, [r4, #0x2c]
	b .L080CAA22
.L080CA9FE:
	movs r0, #3
	strh r0, [r4, #0x2c]
	b .L080CAA22
.L080CAA04:
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080CAA22
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r4, #0x2c]
	cmp r0, #3
	beq .L080CAA20
	adds r0, #1
	strh r0, [r4, #0x2c]
	b .L080CAA22
.L080CAA20:
	strh r5, [r4, #0x2c]
.L080CAA22:
	ldrh r0, [r4, #0x2c]
	cmp r0, #1
	beq .L080CAA44
	cmp r0, #1
	bgt .L080CAA32
	cmp r0, #0
	beq .L080CAA3C
	b .L080CAA58
.L080CAA32:
	cmp r0, #2
	beq .L080CAA4C
	cmp r0, #3
	beq .L080CAA50
	b .L080CAA58
.L080CAA3C:
	movs r0, #6
	mov r8, r0
	movs r0, #0x82
	b .L080CAA56
.L080CAA44:
	movs r0, #0x84
	mov r8, r0
	movs r0, #0x82
	b .L080CAA56
.L080CAA4C:
	movs r0, #6
	b .L080CAA52
.L080CAA50:
	movs r0, #0x84
.L080CAA52:
	mov r8, r0
	movs r0, #0x8e
.L080CAA56:
	mov sl, r0
.L080CAA58:
	mov r0, sl
	str r0, [sp]
	movs r0, #0xa
	movs r1, #0
	movs r2, #2
	mov r3, r8
	bl sub_080C49EC
.L080CAA68:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080CAA78
sub_080CAA78: @ 0x080CAA78
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	ldr r6, .L080CAAB8
	ldrh r4, [r6, #0x28]
	movs r7, #0
	strh r7, [r0, #0x1e]
	mov r8, r4
	cmp r4, #6
	bls .L080CAA96
	movs r0, #7
	mov r8, r0
.L080CAA96:
	ldr r2, .L080CAABC
	ldrh r1, [r2]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CAAC0
	movs r0, #0x65
	bl sub_080C51D4
	mov r0, sb
	strh r5, [r0, #0x1e]
	strh r7, [r6, #0x1c]
	strh r7, [r6, #0x1e]
	subs r5, r4, #1
	b .L080CABB0
	.byte 0x00, 0x00
.L080CAAB8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CAABC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CAAC0:
	ldrh r1, [r2]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CAADA
	movs r0, #0x66
	bl sub_080C51D4
	mov r0, sb
	strh r5, [r0, #0x1e]
	subs r5, r4, #1
	b .L080CABB0
.L080CAADA:
	ldr r1, .L080CAAF8
	ldrh r2, [r1]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L080CAB08
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r6, #0x2c]
	cmp r0, #0
	beq .L080CAAFC
	subs r0, #1
	b .L080CAB22
	.byte 0x00, 0x00
.L080CAAF8: .4byte 0x03003964 @ IWRAM+0x3964
.L080CAAFC:
	ldrh r0, [r6, #0x2e]
	subs r5, r4, #1
	cmp r0, #0
	beq .L080CABB0
	subs r0, #1
	b .L080CAB3A
.L080CAB08:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq .L080CAB40
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r1, [r6, #0x2c]
	mov r0, r8
	subs r0, #1
	cmp r1, r0
	beq .L080CAB28
	adds r0, r1, #1
.L080CAB22:
	strh r0, [r6, #0x2c]
	subs r5, r4, #1
	b .L080CABB0
.L080CAB28:
	subs r5, r4, #1
	cmp r1, #6
	bne .L080CABB0
	ldrh r2, [r6, #0x2e]
	adds r0, r1, r2
	adds r0, #1
	cmp r0, r5
	bgt .L080CABB0
	adds r0, r2, #1
.L080CAB3A:
	strh r0, [r6, #0x2e]
	movs r7, #1
	b .L080CABB0
.L080CAB40:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080CAB76
	cmp r4, #7
	bls .L080CAB76
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r1, [r6, #0x2c]
	cmp r1, #0
	beq .L080CAB60
	strh r7, [r6, #0x2c]
	subs r5, r4, #1
	b .L080CABB0
.L080CAB60:
	movs r7, #1
	ldrh r0, [r6, #0x2e]
	cmp r0, #5
	bls .L080CAB70
	subs r0, #6
	strh r0, [r6, #0x2e]
	subs r5, r4, #1
	b .L080CABB0
.L080CAB70:
	strh r1, [r6, #0x2e]
	subs r5, r4, #1
	b .L080CABB0
.L080CAB76:
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	subs r5, r4, #1
	cmp r0, #0
	beq .L080CABB0
	cmp r4, #7
	bls .L080CABB0
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r6, #0x2c]
	cmp r0, #6
	beq .L080CAB9A
	movs r0, #6
	strh r0, [r6, #0x2c]
	b .L080CABB0
.L080CAB9A:
	movs r7, #1
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r6, #0x2e]
	adds r0, r0, r1
	adds r0, #7
	cmp r0, r5
	bge .L080CABAC
	adds r0, r1, #7
	b .L080CABAE
.L080CABAC:
	subs r0, r4, #7
.L080CABAE:
	strh r0, [r6, #0x2e]
.L080CABB0:
	cmp r7, #1
	bne .L080CABC0
	mov r0, sb
	bl sub_080C9CD8
	mov r0, sb
	bl sub_080C9BCC
.L080CABC0:
	ldrh r0, [r6, #0x2c]
	lsls r1, r0, #4
	subs r1, r1, r0
	adds r1, #0x14
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	movs r0, #0xf
	movs r1, #0
	movs r2, #2
	movs r3, #0xa
	bl sub_080C49EC
	ldrh r0, [r6, #0x2e]
	cmp r0, #0
	beq .L080CABE4
	movs r0, #1
	strh r0, [r6, #0x1c]
.L080CABE4:
	ldrh r0, [r6, #0x2e]
	adds r0, #7
	cmp r0, r5
	bgt .L080CABF0
	movs r0, #1
	strh r0, [r6, #0x1e]
.L080CABF0:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CAC00
sub_080CAC00: @ 0x080CAC00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, .L080CAC90
	mov r8, r0
	ldrh r0, [r0, #2]
	bl sub_080C92C8
	adds r6, r0, #0
	movs r5, #0
	strh r5, [r7, #0x1e]
	ldr r2, .L080CAC94
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080CACA4
	add r1, sp, #4
	ldr r2, .L080CAC98
	adds r0, r2, #0
	strh r0, [r1]
	ldr r4, .L080CAC9C
	ldr r2, .L080CACA0
	adds r0, r1, #0
	adds r1, r4, #0
	bl CpuSet
	movs r2, #0
	adds r0, r6, #0
	adds r0, #0x5d
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0xff
	beq .L080CAC74
	adds r6, r3, #0
	mov ip, r4
.L080CAC4C:
	lsls r1, r5, #1
	adds r1, r1, r4
	adds r0, r6, r2
	ldrb r0, [r0]
	strh r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	strh r5, [r0, #0x28]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x1f
	bhi .L080CAC74
	mov r4, ip
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L080CAC4C
.L080CAC74:
	mov r1, r8
	ldrh r0, [r1, #0x28]
	cmp r0, #0
	beq .L080CACC8
	movs r0, #0x65
	bl sub_080C51D4
	movs r1, #0
	movs r0, #1
	strh r0, [r7, #0x1e]
	mov r2, r8
	strh r1, [r2, #0x2e]
	strh r1, [r2, #0x2c]
	b .L080CACC8
.L080CAC90: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CAC94: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CAC98: .4byte 0x0000FFFF
.L080CAC9C: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080CACA0: .4byte 0x01000080
.L080CACA4:
	ldrh r1, [r2]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CACB8
	movs r0, #0x66
	bl sub_080C51D4
	strh r4, [r7, #0x1e]
.L080CACB8:
	movs r0, #0x82
	str r0, [sp]
	movs r0, #0xa
	movs r1, #0
	movs r2, #2
	movs r3, #6
	bl sub_080C49EC
.L080CACC8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080CACD4
sub_080CACD4: @ 0x080CACD4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	ldr r6, .L080CAD14
	ldrh r4, [r6, #0x28]
	movs r0, #0
	mov r8, r0
	mov r0, r8
	mov r1, sb
	strh r0, [r1, #0x1e]
	adds r7, r4, #0
	cmp r4, #6
	bls .L080CACF6
	movs r7, #7
.L080CACF6:
	ldr r2, .L080CAD18
	ldrh r1, [r2]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CAD1C
	movs r0, #0x65
	bl sub_080C51D4
	mov r1, sb
	strh r5, [r1, #0x1e]
	subs r5, r4, #1
	b .L080CAE18
	.byte 0x00, 0x00
.L080CAD14: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CAD18: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CAD1C:
	ldrh r1, [r2]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CAD36
	movs r0, #0x66
	bl sub_080C51D4
	mov r0, sb
	strh r5, [r0, #0x1e]
	subs r5, r4, #1
	b .L080CAE18
.L080CAD36:
	ldr r1, .L080CAD54
	ldrh r2, [r1]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L080CAD6A
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r6, #0x2c]
	cmp r0, #0
	beq .L080CAD58
	subs r0, #1
	b .L080CAD82
	.byte 0x00, 0x00
.L080CAD54: .4byte 0x03003964 @ IWRAM+0x3964
.L080CAD58:
	ldrh r0, [r6, #0x2e]
	subs r5, r4, #1
	cmp r0, #0
	beq .L080CAE18
	subs r0, #1
	strh r0, [r6, #0x2e]
	movs r1, #1
	mov r8, r1
	b .L080CAE18
.L080CAD6A:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq .L080CADA2
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r1, [r6, #0x2c]
	subs r0, r7, #1
	cmp r1, r0
	beq .L080CAD88
	adds r0, r1, #1
.L080CAD82:
	strh r0, [r6, #0x2c]
	subs r5, r4, #1
	b .L080CAE18
.L080CAD88:
	subs r5, r4, #1
	cmp r1, #6
	bne .L080CAE18
	ldrh r2, [r6, #0x2e]
	adds r0, r1, r2
	adds r0, #1
	cmp r0, r5
	bgt .L080CAE18
	adds r0, r2, #1
	strh r0, [r6, #0x2e]
	movs r0, #1
	mov r8, r0
	b .L080CAE18
.L080CADA2:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080CADDC
	cmp r4, #7
	bls .L080CADDC
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r1, [r6, #0x2c]
	cmp r1, #0
	beq .L080CADC4
	mov r1, r8
	strh r1, [r6, #0x2c]
	subs r5, r4, #1
	b .L080CAE18
.L080CADC4:
	movs r0, #1
	mov r8, r0
	ldrh r0, [r6, #0x2e]
	cmp r0, #5
	bls .L080CADD6
	subs r0, #6
	strh r0, [r6, #0x2e]
	subs r5, r4, #1
	b .L080CAE18
.L080CADD6:
	strh r1, [r6, #0x2e]
	subs r5, r4, #1
	b .L080CAE18
.L080CADDC:
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	subs r5, r4, #1
	cmp r0, #0
	beq .L080CAE18
	cmp r4, #7
	bls .L080CAE18
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r6, #0x2c]
	cmp r0, #6
	beq .L080CAE00
	movs r0, #6
	strh r0, [r6, #0x2c]
	b .L080CAE18
.L080CAE00:
	movs r1, #1
	mov r8, r1
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r6, #0x2e]
	adds r0, r0, r1
	adds r0, #7
	cmp r0, r5
	bge .L080CAE14
	adds r0, r1, #7
	b .L080CAE16
.L080CAE14:
	subs r0, r4, #7
.L080CAE16:
	strh r0, [r6, #0x2e]
.L080CAE18:
	mov r0, r8
	cmp r0, #1
	bne .L080CAE2A
	mov r0, sb
	bl sub_080C9CD8
	mov r0, sb
	bl sub_080C9BCC
.L080CAE2A:
	ldrh r0, [r6, #0x2c]
	lsls r1, r0, #4
	subs r1, r1, r0
	adds r1, #0x14
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	movs r0, #0xf
	movs r1, #0
	movs r2, #2
	movs r3, #0xa
	bl sub_080C49EC
	ldrh r0, [r6, #0x2e]
	cmp r0, #0
	beq .L080CAE4E
	movs r0, #1
	strh r0, [r6, #0x1c]
.L080CAE4E:
	ldrh r0, [r6, #0x2e]
	adds r0, #7
	cmp r0, r5
	bgt .L080CAE5A
	movs r0, #1
	strh r0, [r6, #0x1e]
.L080CAE5A:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080CAE68
sub_080CAE68: @ 0x080CAE68
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r2, .L080CAE88
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080CAE8C
	movs r0, #0x64
	bl sub_080C51D4
	movs r0, #1
	strh r0, [r4, #0x1e]
	b .L080CAEAE
.L080CAE88: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CAE8C:
	ldrh r1, [r2]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CAE9C
	movs r0, #0x66
	b .L080CAEA8
.L080CAE9C:
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080CAEAE
	movs r0, #0x64
.L080CAEA8:
	bl sub_080C51D4
	strh r5, [r4, #0x1e]
.L080CAEAE:
	movs r0, #0
	movs r1, #0
	movs r2, #0x92
	movs r3, #0x14
	bl sub_080C4A4C
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080CAEC0
sub_080CAEC0: @ 0x080CAEC0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r2, .L080CAEEC
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L080CAF04
	ldrh r1, [r2]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CAEF0
	movs r0, #0x66
	bl sub_080C51D4
	strh r5, [r4, #0x1e]
	b .L080CAF04
	.byte 0x00, 0x00
.L080CAEEC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CAEF0:
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080CAF04
	movs r0, #0x64
	bl sub_080C51D4
	movs r0, #3
	strh r0, [r4, #0x1e]
.L080CAF04:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CAF0C
sub_080CAF0C: @ 0x080CAF0C
	push {r4, lr}
	ldr r0, .L080CAF3C
	ldr r3, [r0, #0x3c]
	ldr r1, .L080CAF40
	ldrh r0, [r0, #0xa]
	ldrh r4, [r1]
	adds r2, r0, r4
	strh r2, [r1]
	ldr r1, .L080CAF44
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	cmp r3, #0
	beq .L080CAF36
	rsbs r1, r2, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r3, #0
	movs r2, #0x18
	bl sub_080C3E5C
.L080CAF36:
	pop {r4}
	pop {r0}
	bx r0
.L080CAF3C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CAF40: .4byte 0x03000004 @ IWRAM+0x4
.L080CAF44: .4byte 0x03000008 @ IWRAM+0x8

	thumb_func_start sub_080CAF48
sub_080CAF48: @ 0x080CAF48
	ldr r0, .L080CAF50
	strh r1, [r0, #4]
	bx lr
	.byte 0x00, 0x00
.L080CAF50: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CAF54
sub_080CAF54: @ 0x080CAF54
	ldr r0, .L080CAF5C
	strh r1, [r0, #6]
	bx lr
	.byte 0x00, 0x00
.L080CAF5C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CAF60
sub_080CAF60: @ 0x080CAF60
	ldr r0, .L080CAF68
	strh r1, [r0, #8]
	bx lr
	.byte 0x00, 0x00
.L080CAF68: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CAF6C
sub_080CAF6C: @ 0x080CAF6C
	push {r4, lr}
	ldr r4, .L080CAFAC
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	beq .L080CAF80
	movs r1, #0
	bl sub_080C3E80
	movs r0, #0
	str r0, [r4, #0x3c]
.L080CAF80:
	ldr r0, [r4, #0x40]
	movs r1, #1
	bl TextWindow_Close
	ldr r0, [r4, #0x44]
	movs r1, #1
	bl TextWindow_Close
	ldr r0, [r4, #0x48]
	movs r1, #1
	bl TextWindow_Close
	ldr r1, [r4, #0x38]
	movs r0, #1
	str r0, [r1, #0xc]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	pop {r4}
	pop {r0}
	bx r0
.L080CAFAC: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CAFB0
sub_080CAFB0: @ 0x080CAFB0
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080CAFC4
	ldr r0, [r0, #0x38]
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080CAFC8
	movs r0, #0
	b .L080CAFCA
	.byte 0x00, 0x00
.L080CAFC4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CAFC8:
	movs r0, #1
.L080CAFCA:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080CAFD0
sub_080CAFD0: @ 0x080CAFD0
.L080CAFD0:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	lsls r6, r1, #0x10
	lsrs r6, r6, #0x10
	ldr r0, .L080CB00C
	ldr r1, .L080CB010
	bl Task_Create
	mov r8, r0
	ldr r4, .L080CB014
	movs r5, #0
	str r5, [sp]
	ldr r2, .L080CB018
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	strh r6, [r4, #2]
	strh r5, [r4]
	strh r5, [r4, #0x22]
	mov r0, r8
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080CB00C: .4byte gUnknown_084EFB44
.L080CB010: .4byte 0x0000FFFF
.L080CB014: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CB018: .4byte 0x05000200 @ PLTT+0x200

	thumb_func_start sub_080CB01C
sub_080CB01C: @ 0x080CB01C
.L080CB01C:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	lsls r5, r1, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080CB058
	ldr r1, .L080CB05C
	bl Task_Create
	mov r8, r0
	ldr r4, .L080CB060
	movs r6, #0
	str r6, [sp]
	ldr r2, .L080CB064
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	strh r5, [r4, #2]
	movs r0, #1
	strh r0, [r4]
	strh r6, [r4, #0x22]
	mov r0, r8
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080CB058: .4byte gUnknown_084EFB44
.L080CB05C: .4byte 0x0000FFFF
.L080CB060: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CB064: .4byte 0x05000200 @ PLTT+0x200

	thumb_func_start sub_080CB068
sub_080CB068: @ 0x080CB068
.L080CB068:
	push {r4, r5, lr}
	sub sp, #8
	ldr r5, .L080CB0AC
	ldr r4, .L080CB0B0
	movs r0, #0x6c
	str r0, [sp]
	movs r0, #0xe
	str r0, [sp, #4]
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0x30
	movs r3, #0x74
	bl Canvas_FillRect
	ldr r0, .L080CB0B4
	movs r1, #0xc
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0x30
	movs r3, #0x74
	bl Text_DrawString
	ldrh r0, [r5, #0x36]
	movs r1, #0x88
	movs r2, #0x77
	movs r3, #0
	bl sub_080CCFC4
	bl sub_080C9994
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
.L080CB0AC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CB0B0: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CB0B4: .4byte gUnknown_084F00C8

	thumb_func_start sub_080CB0B8
sub_080CB0B8: @ 0x080CB0B8
.L080CB0B8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r0, .L080CB180
	mov r8, r0
	ldrh r0, [r0, #2]
	bl sub_080C92C8
	adds r7, r0, #0
	mov r1, r8
	ldr r0, [r1, #0x3c]
	cmp r0, #0
	beq .L080CB0E0
	movs r1, #0
	bl sub_080C3E80
	movs r0, #0
	mov r2, r8
	str r0, [r2, #0x3c]
.L080CB0E0:
	mov r3, r8
	ldrh r0, [r3, #2]
	bl sub_080C9388
	adds r6, r0, #0
	cmp r6, #1
	beq .L080CB0F0
	b .L080CB368
.L080CB0F0:
	ldrb r0, [r7, #0xc]
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L080CB184
	movs r1, #0xa
	movs r2, #0x20
	movs r3, #0
	bl sub_080CCE5C
	movs r1, #0x18
	ldrsh r0, [r7, r1]
	movs r1, #0x60
	movs r2, #0x20
	movs r3, #4
	bl sub_080CCF44
	ldr r4, .L080CB188
	adds r0, r4, #0
	movs r1, #0x68
	movs r2, #0x20
	movs r3, #4
	bl sub_080CCE5C
	movs r2, #0x1a
	ldrsh r0, [r7, r2]
	movs r1, #0x80
	movs r2, #0x20
	movs r3, #4
	bl sub_080CCF44
	ldr r0, .L080CB18C
	movs r1, #0xa
	movs r2, #0x2c
	movs r3, #0
	bl sub_080CCE5C
	movs r3, #0x1c
	ldrsh r0, [r7, r3]
	movs r1, #0x60
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CCF44
	adds r0, r4, #0
	movs r1, #0x68
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CCE5C
	movs r1, #0x1e
	ldrsh r0, [r7, r1]
	movs r1, #0x80
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CCF44
	ldr r0, .L080CB190
	movs r1, #0xa
	movs r2, #0x38
	movs r3, #0
	bl sub_080CCE5C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080CB198
	ldr r0, .L080CB194
	b .L080CB292
	.byte 0x00, 0x00
.L080CB180: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CB184: .4byte gUnknown_084F00D8
.L080CB188: .4byte gUnknown_084F00DC
.L080CB18C: .4byte gUnknown_084F00E0
.L080CB190: .4byte gUnknown_084F00E4
.L080CB194: .4byte gUnknown_084F00E8
.L080CB198:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r5
	cmp r0, #0
	beq .L080CB1AC
	ldr r0, .L080CB1A8
	b .L080CB292
	.byte 0x00, 0x00
.L080CB1A8: .4byte gUnknown_084F00F0
.L080CB1AC:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r5
	cmp r0, #0
	beq .L080CB1C0
	ldr r0, .L080CB1BC
	movs r1, #0x58
	b .L080CB294
.L080CB1BC: .4byte gUnknown_084F00F8
.L080CB1C0:
	movs r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080CB1D4
	ldr r0, .L080CB1D0
	movs r1, #0x58
	b .L080CB294
	.byte 0x00, 0x00
.L080CB1D0: .4byte gUnknown_084F0100
.L080CB1D4:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080CB1E8
	ldr r0, .L080CB1E4
	movs r1, #0x70
	b .L080CB294
.L080CB1E4: .4byte gUnknown_084F0108
.L080CB1E8:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r5
	cmp r0, #0
	beq .L080CB1FC
	ldr r0, .L080CB1F8
	movs r1, #0x58
	b .L080CB294
.L080CB1F8: .4byte gUnknown_084F010C
.L080CB1FC:
	ands r6, r5
	cmp r6, #0
	beq .L080CB20C
	ldr r0, .L080CB208
	b .L080CB292
	.byte 0x00, 0x00
.L080CB208: .4byte gUnknown_084F0114
.L080CB20C:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080CB220
	ldr r0, .L080CB21C
	b .L080CB292
	.byte 0x00, 0x00
.L080CB21C: .4byte gUnknown_084F011C
.L080CB220:
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0
	beq .L080CB230
	ldr r0, .L080CB22C
	b .L080CB292
.L080CB22C: .4byte gUnknown_084F0124
.L080CB230:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L080CB244
	ldr r0, .L080CB240
	movs r1, #0x68
	b .L080CB294
	.byte 0x00, 0x00
.L080CB240: .4byte gUnknown_084F012C
.L080CB244:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080CB258
	ldr r0, .L080CB254
	movs r1, #0x58
	b .L080CB294
.L080CB254: .4byte gUnknown_084F0134
.L080CB258:
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0
	beq .L080CB268
	ldr r0, .L080CB264
	b .L080CB292
.L080CB264: .4byte gUnknown_084F013C
.L080CB268:
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080CB278
	ldr r0, .L080CB274
	b .L080CB292
.L080CB274: .4byte gUnknown_084F0144
.L080CB278:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L080CB288
	ldr r0, .L080CB284
	b .L080CB292
.L080CB284: .4byte gUnknown_084F014C
.L080CB288:
	movs r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080CB2A4
	ldr r0, .L080CB2A0
.L080CB292:
	movs r1, #0x60
.L080CB294:
	movs r2, #0x38
	movs r3, #4
	bl sub_080CCE5C
	b .L080CB2B0
	.byte 0x00, 0x00
.L080CB2A0: .4byte gUnknown_084F0154
.L080CB2A4:
	ldr r0, .L080CB34C
	movs r1, #0x68
	movs r2, #0x38
	movs r3, #4
	bl sub_080CCE5C
.L080CB2B0:
	ldr r0, .L080CB350
	movs r1, #0xa
	movs r2, #0x44
	movs r3, #0
	bl sub_080CCE5C
	ldr r0, [r7, #8]
	movs r1, #0x80
	movs r2, #0x44
	movs r3, #4
	bl sub_080CCF44
	ldr r0, .L080CB354
	movs r1, #0xa
	movs r2, #0x50
	movs r3, #0
	bl sub_080CCE5C
	ldrb r0, [r7, #0xd]
	cmp r0, #0x63
	beq .L080CB2EE
	adds r0, #1
	bl sub_080C1098
	ldr r1, [r7, #8]
	subs r0, r0, r1
	movs r1, #0x80
	movs r2, #0x50
	movs r3, #4
	bl sub_080CCF44
.L080CB2EE:
	mov r2, r8
	ldrh r0, [r2, #2]
	bl sub_080C93B4
	cmp r0, #1
	beq .L080CB2FC
	b .L080CB700
.L080CB2FC:
	ldr r0, .L080CB358
	movs r1, #0xa
	movs r2, #0x5c
	movs r3, #0
	bl sub_080CCE5C
	ldr r0, .L080CB35C
	ldr r3, .L080CB360
	adds r0, r0, r3
	ldrb r0, [r0]
	movs r1, #0x80
	movs r2, #0x5c
	movs r3, #4
	bl sub_080CCF44
	ldr r0, .L080CB364
	movs r1, #0x70
	movs r2, #0x5c
	movs r3, #4
	bl sub_080CCE5C
	movs r5, #0
	movs r4, #4
.L080CB32A:
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080CB336
	adds r5, #1
.L080CB336:
	adds r4, #1
	cmp r4, #0xf
	ble .L080CB32A
	adds r0, r5, #0
	movs r1, #0x68
	movs r2, #0x5c
	movs r3, #4
	bl sub_080CCF44
	b .L080CB700
	.byte 0x00, 0x00
.L080CB34C: .4byte gUnknown_084F015C
.L080CB350: .4byte gUnknown_084F0164
.L080CB354: .4byte gUnknown_084F0168
.L080CB358: .4byte gUnknown_084F0170
.L080CB35C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080CB360: .4byte 0x00000AC3
.L080CB364: .4byte gUnknown_084F00DC
.L080CB368:
	ldrh r0, [r7, #0x12]
	bl sub_080C92AC
	cmp r0, #1
	bne .L080CB374
	b .L080CB6CA
.L080CB374:
	adds r0, r7, #0
	bl sub_080C99B8
	cmp r0, #1
	bne .L080CB454
	ldr r0, .L080CB430
	movs r1, #0x56
	movs r2, #0x1e
	movs r3, #0
	bl sub_080CCE5C
	ldr r0, .L080CB434
	movs r1, #0x60
	movs r2, #0x28
	movs r3, #4
	bl sub_080CCE5C
	ldr r0, .L080CB438
	movs r1, #0x56
	movs r2, #0x32
	movs r3, #0
	bl sub_080CCE5C
	ldr r4, .L080CB43C
	adds r0, r4, #0
	movs r1, #0x62
	movs r2, #0x3c
	movs r3, #4
	bl sub_080CCE5C
	ldr r5, .L080CB440
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0x3c
	movs r3, #4
	bl sub_080CCE5C
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x3c
	movs r3, #4
	bl sub_080CCE5C
	ldr r0, .L080CB444
	movs r1, #0x56
	movs r2, #0x46
	movs r3, #0
	bl sub_080CCE5C
	adds r0, r4, #0
	movs r1, #0x62
	movs r2, #0x50
	movs r3, #4
	bl sub_080CCE5C
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0x50
	movs r3, #4
	bl sub_080CCE5C
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x50
	movs r3, #4
	bl sub_080CCE5C
	ldr r0, .L080CB448
	movs r1, #0x56
	movs r2, #0x5a
	movs r3, #0
	bl sub_080CCE5C
	ldr r4, .L080CB44C
	adds r0, r4, #0
	movs r1, #0x78
	movs r2, #0x64
	movs r3, #4
	bl sub_080CCE5C
	ldr r0, .L080CB450
	movs r1, #0x56
	movs r2, #0x6e
	movs r3, #0
	bl sub_080CCE5C
	adds r0, r4, #0
	movs r1, #0x78
	movs r2, #0x78
	movs r3, #4
	bl sub_080CCE5C
	b .L080CB6CA
	.byte 0x00, 0x00
.L080CB430: .4byte gUnknown_084F0178
.L080CB434: .4byte gUnknown_084F017C
.L080CB438: .4byte gUnknown_084F00D8
.L080CB43C: .4byte gUnknown_084F0184
.L080CB440: .4byte gUnknown_084F00DC
.L080CB444: .4byte gUnknown_084F00E0
.L080CB448: .4byte gUnknown_084F00E4
.L080CB44C: .4byte gUnknown_084F0188
.L080CB450: .4byte gUnknown_084F0190
.L080CB454:
	ldrh r0, [r7, #0x12]
	bl sub_080C3560
	cmp r0, #0
	beq .L080CB46A
	ldrb r0, [r0, #0xc]
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b .L080CB46C
.L080CB46A:
	movs r5, #0
.L080CB46C:
	ldr r0, .L080CB4A0
	movs r1, #0x56
	movs r2, #0x1e
	movs r3, #0
	bl sub_080CCE5C
	ldrh r0, [r7, #0x12]
	movs r1, #0x60
	movs r2, #0x28
	bl sub_080CD044
	ldrh r4, [r7, #0x18]
	ldrh r6, [r7, #0x1c]
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #7
	bne .L080CB4A4
	ldrh r0, [r7, #0x12]
	bl sub_080C3560
	ldrh r4, [r0, #0x18]
	ldrh r0, [r7, #0x12]
	bl sub_080C3560
	ldrh r6, [r0, #0x1c]
	b .L080CB500
.L080CB4A0: .4byte gUnknown_084F0178
.L080CB4A4:
	cmp r0, #6
	bne .L080CB500
	ldr r0, .L080CB584
	ldrh r0, [r0, #8]
	cmp r0, #2
	bne .L080CB500
	bl sub_08157C2C
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq .L080CB500
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080CB4DE
	movs r2, #0x1a
	ldrsh r0, [r7, r2]
	cmp r0, #0
	bge .L080CB4CE
	adds r0, #3
.L080CB4CE:
	asrs r0, r0, #2
	adds r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L080CB588
	cmp r4, r0
	bls .L080CB4DE
	adds r4, r0, #0
.L080CB4DE:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CB500
	movs r3, #0x1e
	ldrsh r0, [r7, r3]
	cmp r0, #0
	bge .L080CB4F0
	adds r0, #3
.L080CB4F0:
	asrs r0, r0, #2
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L080CB588
	cmp r6, r0
	bls .L080CB500
	adds r6, r0, #0
.L080CB500:
	ldr r0, .L080CB58C
	movs r1, #0x56
	movs r2, #0x32
	movs r3, #0
	bl sub_080CCE5C
	adds r0, r4, #0
	movs r1, #0x70
	movs r2, #0x3c
	movs r3, #4
	bl sub_080CCF44
	ldr r4, .L080CB590
	adds r0, r4, #0
	movs r1, #0x78
	movs r2, #0x3c
	movs r3, #4
	bl sub_080CCE5C
	movs r1, #0x1a
	ldrsh r0, [r7, r1]
	movs r1, #0x90
	movs r2, #0x3c
	movs r3, #4
	bl sub_080CCF44
	ldr r0, .L080CB594
	movs r1, #0x56
	movs r2, #0x46
	movs r3, #0
	bl sub_080CCE5C
	adds r0, r6, #0
	movs r1, #0x70
	movs r2, #0x50
	movs r3, #4
	bl sub_080CCF44
	adds r0, r4, #0
	movs r1, #0x78
	movs r2, #0x50
	movs r3, #4
	bl sub_080CCE5C
	movs r2, #0x1e
	ldrsh r0, [r7, r2]
	movs r1, #0x90
	movs r2, #0x50
	movs r3, #4
	bl sub_080CCF44
	ldr r0, .L080CB598
	movs r1, #0x56
	movs r2, #0x5a
	movs r3, #0
	bl sub_080CCE5C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080CB5A0
	ldr r0, .L080CB59C
	movs r1, #0x78
	b .L080CB69C
	.byte 0x00, 0x00
.L080CB584: .4byte 0x0203B854 @ EWRAM+0x3B854
.L080CB588: .4byte 0x000003E7
.L080CB58C: .4byte gUnknown_084F00D8
.L080CB590: .4byte gUnknown_084F00DC
.L080CB594: .4byte gUnknown_084F00E0
.L080CB598: .4byte gUnknown_084F00E4
.L080CB59C: .4byte gUnknown_084F0194
.L080CB5A0:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r5
	cmp r0, #0
	beq .L080CB5B4
	ldr r0, .L080CB5B0
	b .L080CB69A
	.byte 0x00, 0x00
.L080CB5B0: .4byte gUnknown_084F00F0
.L080CB5B4:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r5
	cmp r0, #0
	beq .L080CB5C8
	ldr r0, .L080CB5C4
	movs r1, #0x68
	b .L080CB69C
.L080CB5C4: .4byte gUnknown_084F00F8
.L080CB5C8:
	movs r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080CB5DC
	ldr r0, .L080CB5D8
	movs r1, #0x68
	b .L080CB69C
	.byte 0x00, 0x00
.L080CB5D8: .4byte gUnknown_084F0100
.L080CB5DC:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080CB5F0
	ldr r0, .L080CB5EC
	movs r1, #0x80
	b .L080CB69C
.L080CB5EC: .4byte gUnknown_084F0108
.L080CB5F0:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r5
	cmp r0, #0
	beq .L080CB604
	ldr r0, .L080CB600
	movs r1, #0x68
	b .L080CB69C
.L080CB600: .4byte gUnknown_084F010C
.L080CB604:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080CB614
	ldr r0, .L080CB610
	b .L080CB69A
.L080CB610: .4byte gUnknown_084F0114
.L080CB614:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080CB628
	ldr r0, .L080CB624
	b .L080CB69A
	.byte 0x00, 0x00
.L080CB624: .4byte gUnknown_084F011C
.L080CB628:
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0
	beq .L080CB638
	ldr r0, .L080CB634
	b .L080CB69A
.L080CB634: .4byte gUnknown_084F0124
.L080CB638:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L080CB64C
	ldr r0, .L080CB648
	movs r1, #0x78
	b .L080CB69C
	.byte 0x00, 0x00
.L080CB648: .4byte gUnknown_084F012C
.L080CB64C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080CB660
	ldr r0, .L080CB65C
	movs r1, #0x68
	b .L080CB69C
.L080CB65C: .4byte gUnknown_084F0134
.L080CB660:
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0
	beq .L080CB670
	ldr r0, .L080CB66C
	b .L080CB69A
.L080CB66C: .4byte gUnknown_084F013C
.L080CB670:
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080CB680
	ldr r0, .L080CB67C
	b .L080CB69A
.L080CB67C: .4byte gUnknown_084F0144
.L080CB680:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L080CB690
	ldr r0, .L080CB68C
	b .L080CB69A
.L080CB68C: .4byte gUnknown_084F014C
.L080CB690:
	movs r0, #8
	ands r5, r0
	cmp r5, #0
	beq .L080CB6AC
	ldr r0, .L080CB6A8
.L080CB69A:
	movs r1, #0x70
.L080CB69C:
	movs r2, #0x64
	movs r3, #4
	bl sub_080CCE5C
	b .L080CB6B8
	.byte 0x00, 0x00
.L080CB6A8: .4byte gUnknown_084F0154
.L080CB6AC:
	ldr r0, .L080CB70C
	movs r1, #0x78
	movs r2, #0x64
	movs r3, #4
	bl sub_080CCE5C
.L080CB6B8:
	ldr r0, .L080CB710
	movs r1, #0x56
	movs r2, #0x6e
	movs r3, #0
	bl sub_080CCE5C
	ldrh r0, [r7, #0x12]
	bl sub_080CD0E4
.L080CB6CA:
	ldrh r1, [r7, #0x12]
	ldr r0, .L080CB714
	ldrh r2, [r0]
	rsbs r2, r2, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r3, #0x18
	bl sub_080C3D84
	mov r3, r8
	str r0, [r3, #0x3c]
	movs r1, #1
	bl sub_080C3E40
	ldr r2, .L080CB718
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0x10
	strh r1, [r0]
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
.L080CB700:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CB70C: .4byte gUnknown_084F015C
.L080CB710: .4byte gUnknown_084F0190
.L080CB714: .4byte 0x03000004 @ IWRAM+0x4
.L080CB718: .4byte 0x03002DB0 @ IWRAM+0x2DB0

	thumb_func_start sub_080CB71C
sub_080CB71C: @ 0x080CB71C
.L080CB71C:
	push {r4, lr}
	ldr r0, .L080CB79C
	ldrh r0, [r0, #2]
	bl sub_080C92C8
	adds r4, r0, #0
	adds r0, #0x20
	ldrb r0, [r0]
	movs r1, #0x24
	movs r2, #0x1c
	movs r3, #0
	bl sub_080CD100
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r0, [r0]
	movs r1, #0x24
	movs r2, #0x2b
	movs r3, #0
	bl sub_080CD100
	adds r0, r4, #0
	adds r0, #0x22
	ldrb r0, [r0]
	movs r1, #0x24
	movs r2, #0x3a
	movs r3, #0
	bl sub_080CD100
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r0, [r0]
	movs r1, #0x24
	movs r2, #0x49
	movs r3, #0
	bl sub_080CD100
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	movs r1, #0x24
	movs r2, #0x58
	movs r3, #0
	bl sub_080CD100
	adds r0, r4, #0
	adds r0, #0x25
	ldrb r0, [r0]
	movs r1, #0x24
	movs r2, #0x67
	movs r3, #0
	bl sub_080CD100
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r0, [r0]
	movs r1, #0x24
	movs r2, #0x76
	movs r3, #0
	bl sub_080CD100
	pop {r4}
	pop {r0}
	bx r0
.L080CB79C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CB7A0
sub_080CB7A0: @ 0x080CB7A0
.L080CB7A0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0x1c
	mov r8, r0
	ldr r1, .L080CB808
	ldrh r0, [r1, #2]
	bl sub_080C92C8
	str r0, [sp]
	movs r2, #0
	mov sl, r2
	movs r0, #0xf8
	lsls r0, r0, #0xd
	mov sb, r0
.L080CB7C4:
	movs r7, #0
	ldr r0, .L080CB80C
	ldr r2, .L080CB808
	ldrh r1, [r2, #0x2e]
	add r1, sl
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r5, [r1]
	ldr r0, .L080CB810
	cmp r5, r0
	beq .L080CB8AA
	cmp r5, #0xcf
	bhi .L080CB84C
	ldrh r1, [r2, #0x30]
	ldr r0, [sp]
	bl sub_080C343C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r5
	bne .L080CB818
	movs r7, #6
	mov r4, r8
	adds r4, #2
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	ldr r0, .L080CB814
	movs r1, #2
	movs r3, #6
	bl sub_080CCE5C
	adds r6, r4, #0
	b .L080CB82E
	.byte 0x00, 0x00
.L080CB808: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CB80C: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080CB810: .4byte 0x0000FFFF
.L080CB814: .4byte gUnknown_084F019C
.L080CB818:
	ldr r1, [sp]
	ldrb r0, [r1, #0xc]
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	bl sub_080CDB74
	mov r6, r8
	adds r6, #2
	cmp r0, #1
	beq .L080CB82E
	movs r7, #2
.L080CB82E:
	ldr r2, .L080CB848
	adds r1, r2, #0
	adds r0, r5, #0
	ands r0, r1
	mov r1, r8
	lsls r2, r1, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0xa
	adds r3, r7, #0
	bl sub_080CD100
	lsls r4, r5, #0x10
	b .L080CB862
.L080CB848: .4byte 0x00007FFF
.L080CB84C:
	lsls r4, r5, #0x10
	lsrs r0, r4, #0x10
	mov r1, r8
	lsls r2, r1, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0xa
	movs r3, #0
	bl sub_080CD1A0
	mov r6, r8
	adds r6, #2
.L080CB862:
	lsrs r0, r4, #0x10
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x63
	bls .L080CB884
	mov r0, sb
	lsrs r2, r0, #0x10
	ldr r0, .L080CB880
	movs r1, #0x6d
	adds r3, r7, #0
	bl sub_080CCE5C
	b .L080CB892
.L080CB880: .4byte gUnknown_084F01A0
.L080CB884:
	mov r1, sb
	lsrs r2, r1, #0x10
	ldr r0, .L080CB8C4
	movs r1, #0x75
	adds r3, r7, #0
	bl sub_080CCE5C
.L080CB892:
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r1, #0x87
	adds r3, r7, #0
	bl sub_080CCFC4
	movs r2, #0xf0
	lsls r2, r2, #0xc
	add sb, r2
	movs r0, #0xf
	add r8, r0
.L080CB8AA:
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #6
	bls .L080CB7C4
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CB8C4: .4byte gUnknown_084F01A0

	thumb_func_start sub_080CB8C8
sub_080CB8C8: @ 0x080CB8C8
.L080CB8C8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, .L080CB91C
	mov r8, r0
	movs r6, #0x1c
	movs r5, #0
	ldr r7, .L080CB920
.L080CB8D8:
	mov r1, r8
	ldrh r0, [r1, #0x2e]
	adds r0, r5, r0
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r1, [r0]
	ldr r0, .L080CB924
	cmp r1, r0
	beq .L080CB90A
	movs r4, #0xff
	ands r4, r1
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_080CD1F8
	adds r3, r6, #3
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	movs r1, #0x6c
	movs r2, #0x87
	bl sub_080CD260
.L080CB90A:
	adds r6, #0xf
	adds r5, #1
	cmp r5, #6
	bls .L080CB8D8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CB91C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CB920: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080CB924: .4byte 0x0000FFFF

	thumb_func_start sub_080CB928
sub_080CB928: @ 0x080CB928
.L080CB928:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r1, .L080CB964
	ldrh r0, [r1, #2]
	bl sub_080C92C8
	str r0, [sp, #8]
	movs r0, #0
	mov r8, r0
	movs r6, #0x1e
	movs r1, #0
	str r1, [sp, #0xc]
	movs r0, #0xe
	mov sl, r0
	ldr r1, .L080CB964
	ldrh r0, [r1]
	cmp r0, #7
	bne .L080CB968
	ldr r1, [sp, #8]
	ldrh r0, [r1, #0x12]
	bl sub_080C3560
	adds r7, r0, #0
	adds r7, #0x5d
	b .L080CB97C
	.byte 0x00, 0x00
.L080CB964: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CB968:
	cmp r0, #6
	beq .L080CB97A
	ldr r7, [sp, #8]
	adds r7, #0x5d
	cmp r0, #1
	beq .L080CB980
	movs r1, #1
	str r1, [sp, #0xc]
	b .L080CB980
.L080CB97A:
	ldr r7, .L080CB9F8
.L080CB97C:
	movs r0, #1
	str r0, [sp, #0xc]
.L080CB980:
	movs r0, #0
	ldr r1, .L080CB9FC
	strh r0, [r1, #0x12]
	strh r0, [r1, #0x14]
	mov sb, r6
	movs r5, #0
	ldrb r0, [r7]
	cmp r0, #0xff
	beq .L080CB9B4
.L080CB992:
	cmp r0, #0x3f
	bhi .L080CB9A6
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0x24
	bl sub_080CD1F8
	add r6, sl
	movs r0, #1
	add r8, r0
.L080CB9A6:
	adds r5, #1
	cmp r5, #6
	bhi .L080CB9B4
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L080CB992
.L080CB9B4:
	cmp r6, sb
	beq .L080CB9C0
	mov r0, sb
	subs r0, #8
	ldr r1, .L080CB9FC
	strh r0, [r1, #0x12]
.L080CB9C0:
	mov sb, r6
	movs r5, #0
	ldrb r4, [r7]
	cmp r4, #0xff
	beq .L080CBA24
.L080CB9CA:
	ldr r0, [sp, #0xc]
	cmp r0, #1
	bne .L080CBA00
	cmp r4, #0x3f
	bls .L080CBA16
	ldr r0, [sp, #8]
	ldrh r1, [r0, #0x12]
	adds r0, r4, #0
	bl sub_0812C4E0
	cmp r0, #0
	bne .L080CBA16
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r1, #0x24
	bl sub_080CD1F8
	add r6, sl
	movs r1, #1
	add r8, r1
	b .L080CBA16
	.byte 0x00, 0x00
.L080CB9F8: .4byte 0x0203B860 @ EWRAM+0x3B860
.L080CB9FC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CBA00:
	cmp r4, #0x3f
	bls .L080CBA16
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r1, #0x24
	bl sub_080CD1F8
	add r6, sl
	movs r0, #1
	add r8, r0
.L080CBA16:
	adds r5, #1
	cmp r5, #6
	bhi .L080CBA24
	adds r0, r7, r5
	ldrb r4, [r0]
	cmp r4, #0xff
	bne .L080CB9CA
.L080CBA24:
	cmp r6, sb
	beq .L080CBA30
	mov r0, sb
	subs r0, #8
	ldr r1, .L080CBA70
	strh r0, [r1, #0x14]
.L080CBA30:
	movs r0, #7
	mov r1, r8
	subs r1, r0, r1
	mov r8, r1
	cmp r1, #0
	beq .L080CBA60
	movs r5, #0
	cmp r5, r8
	bhs .L080CBA60
.L080CBA42:
	lsls r3, r6, #0x10
	lsrs r3, r3, #0x10
	movs r0, #2
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	ldr r0, .L080CBA74
	ldr r1, .L080CBA78
	movs r2, #0x24
	bl Text_DrawStringTinted
	add r6, sl
	adds r5, #1
	cmp r5, r8
	blo .L080CBA42
.L080CBA60:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CBA70: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CBA74: .4byte gUnknown_084F01A2
.L080CBA78: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start Status_DrawDropItem
Status_DrawDropItem: @ 0x080CBA7C
.L080CBA7C:
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r0, .L080CBB00
	ldrh r0, [r0, #2]
	bl sub_080C92C8
	adds r4, r0, #0
	ldrh r0, [r4, #0x12]
	bl sub_080BF648
	ldrh r5, [r0, #0x1a]
	adds r6, r5, #0
	ldrh r0, [r4, #0x12]
	movs r1, #0xc
	movs r2, #0x1c
	bl sub_080CD2A0
	movs r0, #0xff
	ands r0, r5
	cmp r0, #0xff
	bne .L080CBB08
	ldr r5, .L080CBB04
	movs r4, #6
	str r4, [sp]
	movs r0, #0xea
	adds r1, r5, #0
	movs r2, #0xc
	movs r3, #0x49
	bl Font_DrawGlyphTinted
	str r4, [sp]
	movs r0, #0xeb
	adds r1, r5, #0
	movs r2, #0x18
	movs r3, #0x49
	bl Font_DrawGlyphTinted
	str r4, [sp]
	movs r0, #0xe5
	adds r1, r5, #0
	movs r2, #0x30
	movs r3, #0x49
	bl Font_DrawGlyphTinted
	str r4, [sp]
	movs r0, #0xf0
	adds r1, r5, #0
	movs r2, #0x3c
	movs r3, #0x49
	bl Font_DrawGlyphTinted
	str r4, [sp]
	movs r0, #0xe1
	adds r1, r5, #0
	movs r2, #0x48
	movs r3, #0x49
	bl Font_DrawGlyphTinted
	str r4, [sp]
	movs r0, #0xe9
	adds r1, r5, #0
	movs r2, #0x54
	movs r3, #0x49
	bl Font_DrawGlyphTinted
	b .L080CBB28
.L080CBB00: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CBB04: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CBB08:
	cmp r5, #0xcf
	bhi .L080CBB18
	movs r1, #0xc
	movs r2, #0x49
	movs r3, #6
	bl sub_080CD100
	b .L080CBB28
.L080CBB18:
	ldr r0, .L080CBB30
	ands r6, r0
	adds r0, r6, #0
	movs r1, #0xc
	movs r2, #0x49
	movs r3, #6
	bl sub_080CD1A0
.L080CBB28:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080CBB30: .4byte 0x000001FF

	thumb_func_start sub_080CBB34
sub_080CBB34: @ 0x080CBB34
.L080CBB34:
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r0, .L080CBC50
	ldrh r0, [r0, #2]
	bl sub_080C92C8
	ldr r0, .L080CBC54
	mov sb, r0
	ldr r4, .L080CBC58
	adds r1, r4, #0
	movs r2, #0xb2
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CBC5C
	mov r8, r0
	adds r1, r4, #0
	movs r2, #0xbe
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r6, .L080CBC60
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb2
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r5, .L080CBC64
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xbe
	movs r3, #0x29
	bl Font_DrawGlyph
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0xb2
	movs r3, #0x36
	bl Font_DrawGlyph
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0xbe
	movs r3, #0x36
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb2
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xbe
	movs r3, #0x43
	bl Font_DrawGlyph
	ldr r0, .L080CBC68
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r0, .L080CBC6C
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r0, .L080CBC70
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x5d
	bl Font_DrawGlyph
	ldr r0, .L080CBC74
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x5d
	bl Font_DrawGlyph
	subs r6, #0x3b
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x6a
	bl Font_DrawGlyph
	ldr r5, .L080CBC78
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x6a
	bl Font_DrawGlyph
	ldr r0, .L080CBC7C
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x6a
	bl Font_DrawGlyph
	ldr r0, .L080CBC80
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x6a
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x77
	bl Font_DrawGlyph
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x77
	bl Font_DrawGlyph
	ldr r0, .L080CBC84
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x77
	bl Font_DrawGlyph
	ldr r0, .L080CBC88
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x77
	bl Font_DrawGlyph
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CBC50: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CBC54: .4byte 0x000008F1
.L080CBC58: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CBC5C: .4byte 0x00000861
.L080CBC60: .4byte 0x00000FFE
.L080CBC64: .4byte 0x00000CD3
.L080CBC68: .4byte 0x00000FA9
.L080CBC6C: .4byte 0x000008C3
.L080CBC70: .4byte 0x00000699
.L080CBC74: .4byte 0x00000EB7
.L080CBC78: .4byte 0x00000F81
.L080CBC7C: .4byte 0x000005BB
.L080CBC80: .4byte 0x000010CB
.L080CBC84: .4byte 0x000008D7
.L080CBC88: .4byte 0x00000672

	thumb_func_start sub_080CBC8C
sub_080CBC8C: @ 0x080CBC8C
.L080CBC8C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r5, .L080CBD40
	ldrh r0, [r5, #2]
	bl sub_080C92C8
	adds r4, r0, #0
	ldrh r0, [r5, #2]
	bl sub_080C9388
	cmp r0, #1
	bne .L080CBD44
	bl sub_080CBB34
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CCFC4
	adds r0, r4, #0
	adds r0, #0x4a
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CCFC4
	adds r0, r4, #0
	adds r0, #0x4c
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x39
	movs r3, #4
	bl sub_080CCFC4
	adds r0, r4, #0
	adds r0, #0x4e
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x46
	movs r3, #4
	bl sub_080CCFC4
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x53
	movs r3, #4
	bl sub_080CCFC4
	adds r0, r4, #0
	adds r0, #0x52
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x60
	movs r3, #4
	bl sub_080CCFC4
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x6d
	movs r3, #4
	bl sub_080CCFC4
	adds r0, r4, #0
	adds r0, #0x56
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x7a
	movs r3, #4
	bl sub_080CCFC4
	b .L080CC46A
	.byte 0x00, 0x00
.L080CBD40: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CBD44:
	ldrh r0, [r4, #0x12]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x93
	bne .L080CBE3C
	ldr r0, .L080CBE10
	mov r8, r0
	ldr r4, .L080CBE14
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CBE18
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	movs r0, #0x93
	movs r1, #0xce
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CD668
	ldr r0, .L080CBE1C
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CBE20
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	movs r0, #0x93
	movs r1, #0xce
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CD6C4
	ldr r0, .L080CBE24
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r6, .L080CBE28
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CBE2C
	movs r5, #4
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xbe
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBE30
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xca
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	str r5, [sp]
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0xd6
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBE34
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xe2
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBE38
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	movs r0, #0x93
	b .L080CC198
	.byte 0x00, 0x00
.L080CBE10: .4byte 0x00000FA9
.L080CBE14: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CBE18: .4byte 0x000008C3
.L080CBE1C: .4byte 0x00000699
.L080CBE20: .4byte 0x00000EB7
.L080CBE24: .4byte 0x00000C1A
.L080CBE28: .4byte 0x00000B7E
.L080CBE2C: .4byte 0x00000B32
.L080CBE30: .4byte 0x00000B8C
.L080CBE34: .4byte 0x00000811
.L080CBE38: .4byte 0x00000C3E
.L080CBE3C:
	cmp r7, #0xa7
	bne .L080CBF28
	ldr r0, .L080CBEFC
	ldr r4, .L080CBF00
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CBF04
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	movs r0, #0xa7
	movs r1, #0xce
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CD668
	ldr r0, .L080CBF08
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CBF0C
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	movs r0, #0xa7
	movs r1, #0xce
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CD6C4
	ldr r0, .L080CBF10
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r6, .L080CBF14
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CBF18
	movs r5, #4
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xbe
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBF1C
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xca
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	str r5, [sp]
	movs r0, #5
	adds r1, r4, #0
	movs r2, #0xd6
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBF20
	str r5, [sp]
	adds r1, r4, #0
	movs r2, #0xe2
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBF24
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	movs r0, #0xa7
	b .L080CC198
	.byte 0x00, 0x00
.L080CBEFC: .4byte 0x00000FA9
.L080CBF00: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CBF04: .4byte 0x000008C3
.L080CBF08: .4byte 0x00000699
.L080CBF0C: .4byte 0x00000EB7
.L080CBF10: .4byte 0x00000C1A
.L080CBF14: .4byte 0x00000B7E
.L080CBF18: .4byte 0x00000C5E
.L080CBF1C: .4byte 0x00000D6E
.L080CBF20: .4byte 0x00000AEB
.L080CBF24: .4byte 0x00000C3E
.L080CBF28:
	cmp r7, #0xbb
	bne .L080CC004
	ldr r0, .L080CBFD8
	ldr r5, .L080CBFDC
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CBFE0
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	movs r0, #0xbb
	movs r1, #0xce
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CD668
	ldr r0, .L080CBFE4
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CBFE8
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	movs r0, #0xbb
	movs r1, #0xce
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CD6C4
	ldr r0, .L080CBFEC
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r6, .L080CBFF0
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CBFF4
	movs r4, #4
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xca
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBFF8
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xd6
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CBFFC
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xe2
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CC000
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	movs r0, #0xbb
	b .L080CC198
.L080CBFD8: .4byte 0x00000FA9
.L080CBFDC: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CBFE0: .4byte 0x000008C3
.L080CBFE4: .4byte 0x00000699
.L080CBFE8: .4byte 0x00000EB7
.L080CBFEC: .4byte 0x00000C1A
.L080CBFF0: .4byte 0x00000B7E
.L080CBFF4: .4byte 0x00000C5E
.L080CBFF8: .4byte 0x00000EDC
.L080CBFFC: .4byte 0x0000086A
.L080CC000: .4byte 0x00000C3E
.L080CC004:
	cmp r7, #0xcf
	bne .L080CC0E0
	ldr r0, .L080CC0B4
	ldr r5, .L080CC0B8
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CC0BC
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	movs r0, #0xcf
	movs r1, #0xce
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CD668
	ldr r0, .L080CC0C0
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CC0C4
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	movs r0, #0xcf
	movs r1, #0xce
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CD6C4
	ldr r0, .L080CC0C8
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r6, .L080CC0CC
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CC0D0
	movs r4, #4
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xca
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CC0D4
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xd6
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CC0D8
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0xe2
	movs r3, #0x36
	bl Font_DrawGlyphTinted
	ldr r0, .L080CC0DC
	adds r1, r5, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	movs r0, #0xcf
	b .L080CC198
.L080CC0B4: .4byte 0x00000FA9
.L080CC0B8: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CC0BC: .4byte 0x000008C3
.L080CC0C0: .4byte 0x00000699
.L080CC0C4: .4byte 0x00000EB7
.L080CC0C8: .4byte 0x00000C1A
.L080CC0CC: .4byte 0x00000B7E
.L080CC0D0: .4byte 0x00000C5E
.L080CC0D4: .4byte 0x00000676
.L080CC0D8: .4byte 0x00000632
.L080CC0DC: .4byte 0x00000C3E
.L080CC0E0:
	ldrh r0, [r4, #0x12]
	bl sub_080C92AC
	cmp r0, #1
	bne .L080CC1C8
	ldrh r0, [r4, #0x12]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r6, .L080CC1A4
	ldr r4, .L080CC1A8
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r5, .L080CC1AC
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0xce
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CD330
	ldr r0, .L080CC1B0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CC1B4
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0xce
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CD38C
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CC1B8
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CC1BC
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x36
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0xd6
	movs r2, #0x39
	movs r3, #4
	bl sub_080CD3E8
	ldr r0, .L080CC1C0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	ldr r0, .L080CC1C4
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r7, #0
.L080CC198:
	movs r1, #0xd6
	movs r2, #0x46
	bl sub_080CD45C
	b .L080CC46A
	.byte 0x00, 0x00
.L080CC1A4: .4byte 0x000008F1
.L080CC1A8: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CC1AC: .4byte 0x00000861
.L080CC1B0: .4byte 0x00000FFE
.L080CC1B4: .4byte 0x00000CD3
.L080CC1B8: .4byte 0x00000699
.L080CC1BC: .4byte 0x00000B67
.L080CC1C0: .4byte 0x00000C3E
.L080CC1C4: .4byte 0x00000B7E
.L080CC1C8:
	adds r0, r4, #0
	bl sub_080C99B8
	cmp r0, #1
	beq .L080CC1D4
	b .L080CC328
.L080CC1D4:
	ldr r0, .L080CC2E8
	ldr r4, .L080CC2EC
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CC2F0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r5, .L080CC2F4
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CCEC8
	ldr r0, .L080CC2F8
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CC2FC
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CCEC8
	ldr r0, .L080CC300
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CC304
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x39
	movs r3, #4
	bl sub_080CCEC8
	ldr r0, .L080CC308
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	ldr r0, .L080CC30C
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x46
	movs r3, #4
	bl sub_080CCEC8
	ldr r1, .L080CC310
	mov r8, r1
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r6, .L080CC314
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r0, .L080CC318
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r0, .L080CC31C
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x50
	bl Font_DrawGlyph
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x53
	movs r3, #4
	bl sub_080CCEC8
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x5d
	bl Font_DrawGlyph
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x5d
	bl Font_DrawGlyph
	ldr r0, .L080CC320
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x5d
	bl Font_DrawGlyph
	ldr r0, .L080CC324
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x5d
	bl Font_DrawGlyph
	adds r0, r5, #0
	movs r1, #0xd6
	movs r2, #0x60
	movs r3, #4
	bl sub_080CCEC8
	b .L080CC46A
.L080CC2E8: .4byte 0x000008F1
.L080CC2EC: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CC2F0: .4byte 0x00000861
.L080CC2F4: .4byte gUnknown_084F01B4
.L080CC2F8: .4byte 0x00000FFE
.L080CC2FC: .4byte 0x00000CD3
.L080CC300: .4byte 0x00000FA9
.L080CC304: .4byte 0x000008C3
.L080CC308: .4byte 0x00000699
.L080CC30C: .4byte 0x00000EB7
.L080CC310: .4byte 0x00000FC3
.L080CC314: .4byte 0x00000F81
.L080CC318: .4byte 0x000005BB
.L080CC31C: .4byte 0x000010CB
.L080CC320: .4byte 0x000008D7
.L080CC324: .4byte 0x00000672
.L080CC328:
	adds r7, r4, #0
	ldrh r0, [r5]
	cmp r0, #7
	bne .L080CC338
	ldrh r0, [r7, #0x12]
	bl sub_080C3560
	adds r7, r0, #0
.L080CC338:
	ldr r0, .L080CC478
	ldr r4, .L080CC47C
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x1c
	bl Font_DrawGlyph
	ldr r0, .L080CC480
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x1c
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CCFC4
	ldr r0, .L080CC484
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x29
	bl Font_DrawGlyph
	ldr r0, .L080CC488
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x29
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x4a
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x2c
	movs r3, #4
	bl sub_080CCFC4
	ldr r0, .L080CC48C
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x36
	bl Font_DrawGlyph
	ldr r0, .L080CC490
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x36
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x50
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x39
	movs r3, #4
	bl sub_080CCFC4
	ldr r0, .L080CC494
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x43
	bl Font_DrawGlyph
	ldr r0, .L080CC498
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x43
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x52
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x46
	movs r3, #4
	bl sub_080CCFC4
	ldr r6, .L080CC49C
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r5, .L080CC4A0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r0, .L080CC4A4
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x50
	bl Font_DrawGlyph
	ldr r0, .L080CC4A8
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x50
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x54
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x53
	movs r3, #4
	bl sub_080CCFC4
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0xa4
	movs r3, #0x5d
	bl Font_DrawGlyph
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xb0
	movs r3, #0x5d
	bl Font_DrawGlyph
	ldr r0, .L080CC4AC
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x5d
	bl Font_DrawGlyph
	ldr r0, .L080CC4B0
	adds r1, r4, #0
	movs r2, #0xc8
	movs r3, #0x5d
	bl Font_DrawGlyph
	adds r0, r7, #0
	adds r0, #0x56
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x60
	movs r3, #4
	bl sub_080CCFC4
.L080CC46A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CC478: .4byte 0x000008F1
.L080CC47C: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CC480: .4byte 0x00000861
.L080CC484: .4byte 0x00000FFE
.L080CC488: .4byte 0x00000CD3
.L080CC48C: .4byte 0x00000FA9
.L080CC490: .4byte 0x000008C3
.L080CC494: .4byte 0x00000699
.L080CC498: .4byte 0x00000EB7
.L080CC49C: .4byte 0x00000FC3
.L080CC4A0: .4byte 0x00000F81
.L080CC4A4: .4byte 0x000005BB
.L080CC4A8: .4byte 0x000010CB
.L080CC4AC: .4byte 0x000008D7
.L080CC4B0: .4byte 0x00000672

	thumb_func_start sub_080CC4B4
sub_080CC4B4: @ 0x080CC4B4
.L080CC4B4:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, .L080CC4DC
	ldrh r0, [r0, #2]
	bl sub_080C92C8
	adds r4, r0, #0
	movs r3, #4
	adds r0, #0x48
	adds r1, r5, #0
	adds r1, #0x48
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r2, r0
	ble .L080CC4E0
	movs r3, #8
	b .L080CC4E6
	.byte 0x00, 0x00
.L080CC4DC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CC4E0:
	cmp r2, r0
	bge .L080CC4E6
	movs r3, #0xa
.L080CC4E6:
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x1f
	bl sub_080CCFC4
	movs r3, #4
	adds r0, r4, #0
	adds r0, #0x4a
	adds r1, r5, #0
	adds r1, #0x4a
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r6, #0
	ldrsh r1, [r1, r6]
	cmp r2, r1
	ble .L080CC510
	movs r3, #8
	b .L080CC516
.L080CC510:
	cmp r2, r1
	bge .L080CC516
	movs r3, #0xa
.L080CC516:
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x2c
	bl sub_080CCFC4
	movs r3, #4
	adds r1, r4, #0
	adds r1, #0x4c
	adds r0, r5, #0
	adds r0, #0x4c
	movs r6, #0
	ldrsh r2, [r1, r6]
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r2, r0
	ble .L080CC53C
	movs r3, #8
	b .L080CC542
.L080CC53C:
	cmp r2, r0
	bge .L080CC542
	movs r3, #0xa
.L080CC542:
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xe6
	movs r2, #0x39
	bl sub_080CCFC4
	movs r3, #4
	adds r0, r4, #0
	adds r0, #0x4e
	adds r1, r5, #0
	adds r1, #0x4e
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r6, #0
	ldrsh r1, [r1, r6]
	cmp r2, r1
	ble .L080CC568
	movs r3, #8
	b .L080CC56E
.L080CC568:
	cmp r2, r1
	bge .L080CC56E
	movs r3, #0xa
.L080CC56E:
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x46
	bl sub_080CCFC4
	movs r3, #4
	adds r1, r4, #0
	adds r1, #0x50
	adds r0, r5, #0
	adds r0, #0x50
	movs r6, #0
	ldrsh r2, [r1, r6]
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r2, r0
	ble .L080CC594
	movs r3, #8
	b .L080CC59A
.L080CC594:
	cmp r2, r0
	bge .L080CC59A
	movs r3, #0xa
.L080CC59A:
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xe6
	movs r2, #0x53
	bl sub_080CCFC4
	movs r3, #4
	adds r0, r4, #0
	adds r0, #0x52
	adds r1, r5, #0
	adds r1, #0x52
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r6, #0
	ldrsh r1, [r1, r6]
	cmp r2, r1
	ble .L080CC5C0
	movs r3, #8
	b .L080CC5C6
.L080CC5C0:
	cmp r2, r1
	bge .L080CC5C6
	movs r3, #0xa
.L080CC5C6:
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xe6
	movs r2, #0x60
	bl sub_080CCFC4
	movs r3, #4
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r5, #0
	adds r0, #0x54
	movs r6, #0
	ldrsh r2, [r1, r6]
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r2, r0
	ble .L080CC5EC
	movs r3, #8
	b .L080CC5F2
.L080CC5EC:
	cmp r2, r0
	bge .L080CC5F2
	movs r3, #0xa
.L080CC5F2:
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xe6
	movs r2, #0x6d
	bl sub_080CCFC4
	movs r3, #4
	adds r1, r4, #0
	adds r1, #0x56
	adds r0, r5, #0
	adds r0, #0x56
	movs r4, #0
	ldrsh r2, [r1, r4]
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r2, r0
	ble .L080CC618
	movs r3, #8
	b .L080CC61E
.L080CC618:
	cmp r2, r0
	bge .L080CC61E
	movs r3, #0xa
.L080CC61E:
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xe6
	movs r2, #0x7a
	bl sub_080CCFC4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080CC630
sub_080CC630: @ 0x080CC630
.L080CC630:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r4, .L080CC688
	ldrh r0, [r4, #2]
	bl sub_080C92C8
	adds r5, r0, #0
	adds r6, r4, #0
	adds r6, #0xd4
	ldr r0, .L080CC68C
	mov r8, r0
	adds r0, r5, #0
	adds r1, r6, #0
	mov r2, r8
	bl CpuSet
	ldr r2, .L080CC690
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x2e]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	ldrh r1, [r4, #0x30]
	ldrb r0, [r5, #0xc]
	bl sub_080C0074
	ldrb r0, [r5, #0xc]
	bl sub_080BF938
	adds r0, r6, #0
	bl sub_080CC4B4
	adds r0, r6, #0
	adds r1, r5, #0
	mov r2, r8
	bl CpuSet
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080CC688: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CC68C: .4byte 0x04000020 @ REG_BG2PA
.L080CC690: .4byte 0x0203B454 @ EWRAM+0x3B454

	thumb_func_start sub_080CC694
sub_080CC694: @ 0x080CC694
.L080CC694:
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r6, .L080CC6FC
	ldrh r0, [r6, #2]
	bl sub_080C92C8
	adds r4, r0, #0
	ldrb r0, [r4, #0xc]
	bl sub_080BF938
	ldrh r0, [r4, #0x1a]
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldrh r0, [r6]
	cmp r0, #5
	bne .L080CC704
	adds r1, r6, #0
	adds r1, #0x54
	ldr r2, .L080CC700
	adds r0, r4, #0
	bl CpuSet
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldrb r0, [r4, #0xc]
	bl sub_080BF938
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r6, r1
	bl sub_080CC4B4
	b .L080CC70C
.L080CC6FC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CC700: .4byte 0x04000020 @ REG_BG2PA
.L080CC704:
	adds r0, r6, #0
	adds r0, #0xd4
	bl sub_080CC4B4
.L080CC70C:
	ldr r1, .L080CC738
	movs r0, #0x60
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0x40
	movs r3, #0x1c
	bl Canvas_FillRect
	movs r5, #4
	adds r0, r6, #0
	adds r0, #0xee
	movs r2, #0x1a
	ldrsh r1, [r4, r2]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble .L080CC73C
	movs r5, #8
	b .L080CC742
	.byte 0x00, 0x00
.L080CC738: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CC73C:
	cmp r1, r0
	bge .L080CC742
	movs r5, #0xa
.L080CC742:
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	movs r1, #0x60
	movs r2, #0x20
	adds r3, r5, #0
	bl sub_080CCF44
	ldr r0, .L080CC780
	movs r1, #0x68
	movs r2, #0x20
	adds r3, r5, #0
	bl sub_080CCE5C
	movs r2, #0x1a
	ldrsh r0, [r4, r2]
	movs r1, #0x80
	movs r2, #0x20
	adds r3, r5, #0
	bl sub_080CCF44
	movs r5, #4
	adds r0, r6, #0
	adds r0, #0xf2
	movs r2, #0x1e
	ldrsh r1, [r4, r2]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble .L080CC784
	movs r5, #8
	b .L080CC78A
.L080CC780: .4byte gUnknown_084F00DC
.L080CC784:
	cmp r1, r0
	bge .L080CC78A
	movs r5, #0xa
.L080CC78A:
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r1, #0x60
	movs r2, #0x2c
	adds r3, r5, #0
	bl sub_080CCF44
	ldr r0, .L080CC7CC
	movs r1, #0x68
	movs r2, #0x2c
	adds r3, r5, #0
	bl sub_080CCE5C
	movs r2, #0x1e
	ldrsh r0, [r4, r2]
	movs r1, #0x80
	movs r2, #0x2c
	adds r3, r5, #0
	bl sub_080CCF44
	ldrh r0, [r6]
	cmp r0, #5
	bne .L080CC7C4
	adds r0, r6, #0
	adds r0, #0x54
	ldr r2, .L080CC7D0
	adds r1, r4, #0
	bl CpuSet
.L080CC7C4:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080CC7CC: .4byte gUnknown_084F00DC
.L080CC7D0: .4byte 0x04000020 @ REG_BG2PA

	thumb_func_start sub_080CC7D4
sub_080CC7D4: @ 0x080CC7D4
.L080CC7D4:
	push {r4, lr}
	ldr r0, .L080CC828
	ldr r4, .L080CC82C
	adds r1, r4, #0
	movs r2, #8
	movs r3, #0x8a
	bl Font_DrawGlyph
	ldr r0, .L080CC830
	adds r1, r4, #0
	movs r2, #0x55
	movs r3, #0x8a
	bl Font_DrawGlyph
	ldr r0, .L080CC834
	adds r1, r4, #0
	movs r2, #0xa2
	movs r3, #0x8a
	bl Font_DrawGlyph
	ldr r0, .L080CC838
	adds r1, r4, #0
	movs r2, #8
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CC83C
	adds r1, r4, #0
	movs r2, #0x55
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CC840
	adds r1, r4, #0
	movs r2, #0xa2
	movs r3, #0x98
	bl Font_DrawGlyph
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CC828: .4byte 0x000010CB
.L080CC82C: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CC830: .4byte 0x00000CBA
.L080CC834: .4byte 0x00000FC3
.L080CC838: .4byte 0x00000C5C
.L080CC83C: .4byte 0x00000C3C
.L080CC840: .4byte 0x00000606

	thumb_func_start sub_080CC844
sub_080CC844: @ 0x080CC844
.L080CC844:
	push {r4, r5, lr}
	ldr r4, .L080CC8D0
	ldrh r0, [r4, #2]
	bl sub_080C92C8
	adds r5, r0, #0
	bl sub_080CC7D4
	ldrh r0, [r5, #0x12]
	bl sub_080C92AC
	cmp r0, #1
	beq .L080CC86A
	adds r0, r5, #0
	bl sub_080C99B8
	cmp r0, #0
	beq .L080CC86A
	b .L080CC9BC
.L080CC86A:
	ldrh r1, [r5, #0x10]
	ldrh r0, [r4]
	cmp r0, #7
	bne .L080CC87A
	ldrh r0, [r5, #0x12]
	bl sub_080C3560
	ldrh r1, [r0, #0x10]
.L080CC87A:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r1, r0
	cmp r1, #0
	beq .L080CC8D4
	movs r0, #1
	movs r1, #0x48
	movs r2, #0x8d
	movs r3, #0
	bl sub_080CCFC4
	movs r0, #1
	movs r1, #0x95
	movs r2, #0x8d
	movs r3, #0
	bl sub_080CCFC4
	movs r0, #1
	movs r1, #0xe2
	movs r2, #0x8d
	movs r3, #0
	bl sub_080CCFC4
	movs r0, #1
	movs r1, #0x48
	movs r2, #0x9a
	movs r3, #0
	bl sub_080CCFC4
	movs r0, #0x28
	movs r1, #0x95
	movs r2, #0x9a
	movs r3, #0
	bl sub_080CCFC4
	movs r0, #1
	movs r1, #0xe2
	movs r2, #0x9a
	movs r3, #0
	bl sub_080CCFC4
	b .L080CCA06
	.byte 0x00, 0x00
.L080CC8D0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CC8D4:
	adds r0, r5, #0
	adds r0, #0x28
	adds r2, r5, #0
	adds r2, #0x40
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	movs r4, #8
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0x48
	movs r2, #0x8d
	bl sub_080CCFC4
	adds r0, r5, #0
	adds r0, #0x29
	adds r2, r5, #0
	adds r2, #0x41
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0x95
	movs r2, #0x8d
	bl sub_080CCFC4
	adds r0, r5, #0
	adds r0, #0x2a
	adds r2, r5, #0
	adds r2, #0x42
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0xe2
	movs r2, #0x8d
	bl sub_080CCFC4
	adds r0, r5, #0
	adds r0, #0x2b
	adds r2, r5, #0
	adds r2, #0x43
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0x48
	movs r2, #0x9a
	bl sub_080CCFC4
	adds r0, r5, #0
	adds r0, #0x2c
	adds r2, r5, #0
	adds r2, #0x44
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0x95
	movs r2, #0x9a
	bl sub_080CCFC4
	adds r0, r5, #0
	adds r0, #0x2d
	adds r2, r5, #0
	adds r2, #0x45
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0xe2
	movs r2, #0x9a
	bl sub_080CCFC4
	b .L080CCA06
.L080CC9BC:
	ldr r4, .L080CCA0C
	adds r0, r4, #0
	movs r1, #0x3f
	movs r2, #0x8d
	movs r3, #0
	bl sub_080CCEC8
	adds r0, r4, #0
	movs r1, #0x8c
	movs r2, #0x8d
	movs r3, #0
	bl sub_080CCEC8
	adds r0, r4, #0
	movs r1, #0xd9
	movs r2, #0x8d
	movs r3, #0
	bl sub_080CCEC8
	adds r0, r4, #0
	movs r1, #0x3f
	movs r2, #0x9a
	movs r3, #0
	bl sub_080CCEC8
	adds r0, r4, #0
	movs r1, #0x8c
	movs r2, #0x9a
	movs r3, #0
	bl sub_080CCEC8
	adds r0, r4, #0
	movs r1, #0xd9
	movs r2, #0x9a
	movs r3, #0
	bl sub_080CCEC8
.L080CCA06:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080CCA0C: .4byte gUnknown_084EFAD8

	thumb_func_start sub_080CCA10
sub_080CCA10: @ 0x080CCA10
.L080CCA10:
	push {r4, r5, lr}
	ldr r5, .L080CCA78
	ldrh r0, [r5, #2]
	bl sub_080C92C8
	ldrh r0, [r5, #2]
	bl sub_080C93B4
	cmp r0, #1
	bne .L080CCA90
	ldr r0, .L080CCA7C
	movs r1, #0xa
	movs r2, #0x8e
	movs r3, #0
	bl sub_080CCE5C
	ldr r4, .L080CCA80
	adds r0, r4, #0
	movs r1, #0x42
	movs r2, #0x8e
	movs r3, #0
	bl sub_080CCE5C
	ldr r0, .L080CCA84
	movs r1, #0xa
	movs r2, #0x9a
	movs r3, #0
	bl sub_080CCE5C
	adds r0, r4, #0
	movs r1, #0x42
	movs r2, #0x9a
	movs r3, #0
	bl sub_080CCE5C
	ldr r0, .L080CCA88
	movs r1, #0x88
	movs r2, #0x8e
	movs r3, #0
	bl sub_080CCE5C
	adds r0, r4, #0
	movs r1, #0xc0
	movs r2, #0x8e
	movs r3, #0
	bl sub_080CCE5C
	ldr r0, .L080CCA8C
	movs r1, #0x88
	movs r2, #0x9a
	b .L080CCAA0
	.byte 0x00, 0x00
.L080CCA78: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CCA7C: .4byte gUnknown_084F01B8
.L080CCA80: .4byte gUnknown_084F01C0
.L080CCA84: .4byte gUnknown_084F01C8
.L080CCA88: .4byte gUnknown_084F01D0
.L080CCA8C: .4byte gUnknown_084F01D8
.L080CCA90:
	ldrh r0, [r5, #2]
	bl sub_080C9388
	cmp r0, #1
	bne .L080CCAAA
	ldr r0, .L080CCAB0
	movs r1, #0xa
	movs r2, #0x8e
.L080CCAA0:
	movs r3, #0
	bl sub_080CCE5C
	movs r0, #0
	strh r0, [r5, #0x2c]
.L080CCAAA:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080CCAB0: .4byte gUnknown_084F01E4

	thumb_func_start sub_080CCAB4
sub_080CCAB4: @ 0x080CCAB4
.L080CCAB4:
	push {r4, r5, r6, r7, lr}
	ldr r4, .L080CCBA8
	ldrh r0, [r4, #2]
	bl sub_080C92C8
	ldr r2, .L080CCBAC
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x2e]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r7, [r0]
	cmp r7, #0x7f
	bls .L080CCAD2
	b .L080CCC5C
.L080CCAD2:
	ldr r5, .L080CCBB0
	ldr r6, .L080CCBB4
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #9
	movs r3, #0x8b
	bl Font_DrawGlyph
	ldr r4, .L080CCBB8
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x15
	movs r3, #0x8b
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0x24
	movs r2, #0x8e
	movs r3, #4
	bl sub_080CD330
	ldr r0, .L080CCBBC
	adds r1, r6, #0
	movs r2, #9
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCBC0
	adds r1, r6, #0
	movs r2, #0x15
	movs r3, #0x98
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0x24
	movs r2, #0x9b
	movs r3, #4
	bl sub_080CD38C
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x49
	movs r3, #0x8b
	bl Font_DrawGlyph
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x55
	movs r3, #0x8b
	bl Font_DrawGlyph
	ldr r0, .L080CCBC4
	adds r1, r6, #0
	movs r2, #0x61
	movs r3, #0x8b
	bl Font_DrawGlyph
	ldr r0, .L080CCBC8
	adds r1, r6, #0
	movs r2, #0x6d
	movs r3, #0x8b
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0x95
	movs r2, #0x8e
	movs r3, #4
	bl sub_080CD3E8
	adds r0, r7, #0
	subs r0, #0x58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bhi .L080CCBE0
	ldr r0, .L080CCBCC
	adds r1, r6, #0
	movs r2, #0x49
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCBD0
	adds r1, r6, #0
	movs r2, #0x55
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCBD4
	adds r1, r6, #0
	movs r2, #0x61
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCBD8
	adds r1, r6, #0
	movs r2, #0x6d
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCBDC
	movs r1, #0x7e
	movs r2, #0x9b
	movs r3, #4
	bl sub_080CCEC8
	b .L080CCC1A
	.byte 0x00, 0x00
.L080CCBA8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CCBAC: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080CCBB0: .4byte 0x000008F1
.L080CCBB4: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CCBB8: .4byte 0x00000861
.L080CCBBC: .4byte 0x00000FFE
.L080CCBC0: .4byte 0x00000CD3
.L080CCBC4: .4byte 0x00000699
.L080CCBC8: .4byte 0x00000B67
.L080CCBCC: .4byte 0x00000D14
.L080CCBD0: .4byte 0x00000669
.L080CCBD4: .4byte 0x000008D7
.L080CCBD8: .4byte 0x00000672
.L080CCBDC: .4byte gUnknown_084F01EC
.L080CCBE0:
	ldr r0, .L080CCC40
	adds r1, r6, #0
	movs r2, #0x49
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCC44
	adds r1, r6, #0
	movs r2, #0x55
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCC48
	adds r1, r6, #0
	movs r2, #0x61
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCC4C
	adds r1, r6, #0
	movs r2, #0x6d
	movs r3, #0x98
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0x7e
	movs r2, #0x9b
	bl sub_080CD50C
.L080CCC1A:
	ldr r0, .L080CCC50
	ldr r4, .L080CCC54
	adds r1, r4, #0
	movs r2, #0xb2
	movs r3, #0x8b
	bl Font_DrawGlyph
	ldr r0, .L080CCC58
	adds r1, r4, #0
	movs r2, #0xbe
	movs r3, #0x8b
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0xcc
	movs r2, #0x8e
	bl sub_080CD45C
	b .L080CCD26
.L080CCC40: .4byte 0x00000D14
.L080CCC44: .4byte 0x00000669
.L080CCC48: .4byte 0x000008D7
.L080CCC4C: .4byte 0x00000672
.L080CCC50: .4byte 0x00000C3E
.L080CCC54: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CCC58: .4byte 0x00000B7E
.L080CCC5C:
	ldr r0, .L080CCD2C
	ldr r4, .L080CCD30
	adds r1, r4, #0
	movs r2, #9
	movs r3, #0x8b
	bl Font_DrawGlyph
	ldr r0, .L080CCD34
	adds r1, r4, #0
	movs r2, #0x15
	movs r3, #0x8b
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0x24
	movs r2, #0x8e
	movs r3, #4
	bl sub_080CD668
	ldr r0, .L080CCD38
	adds r1, r4, #0
	movs r2, #9
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCD3C
	adds r1, r4, #0
	movs r2, #0x15
	movs r3, #0x98
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0x24
	movs r2, #0x9b
	movs r3, #4
	bl sub_080CD6C4
	ldr r0, .L080CCD40
	adds r1, r4, #0
	movs r2, #0x49
	movs r3, #0x8b
	bl Font_DrawGlyph
	ldr r5, .L080CCD44
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x55
	movs r3, #0x8b
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0x65
	movs r2, #0x8b
	bl sub_080CD87C
	ldr r0, .L080CCD48
	adds r1, r4, #0
	movs r2, #0x49
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCD4C
	adds r1, r4, #0
	movs r2, #0x55
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCD50
	adds r1, r4, #0
	movs r2, #0x61
	movs r3, #0x98
	bl Font_DrawGlyph
	ldr r0, .L080CCD54
	adds r1, r4, #0
	movs r2, #0x6d
	movs r3, #0x98
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0x7e
	movs r2, #0x9b
	bl sub_080CD720
	ldr r0, .L080CCD58
	adds r1, r4, #0
	movs r2, #0xb3
	movs r3, #0x8b
	bl Font_DrawGlyph
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xbe
	movs r3, #0x8b
	bl Font_DrawGlyph
	adds r0, r7, #0
	movs r1, #0xcc
	movs r2, #0x8e
	bl sub_080CD45C
.L080CCD26:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CCD2C: .4byte 0x00000FA9
.L080CCD30: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CCD34: .4byte 0x000008C3
.L080CCD38: .4byte 0x00000699
.L080CCD3C: .4byte 0x00000EB7
.L080CCD40: .4byte 0x00000C1A
.L080CCD44: .4byte 0x00000B7E
.L080CCD48: .4byte 0x00000D14
.L080CCD4C: .4byte 0x00000669
.L080CCD50: .4byte 0x000008D7
.L080CCD54: .4byte 0x00000672
.L080CCD58: .4byte 0x00000C3E

	thumb_func_start sub_080CCD5C
sub_080CCD5C: @ 0x080CCD5C
.L080CCD5C:
	push {r4, r5, lr}
	ldr r0, .L080CCE58
	ldrh r0, [r0, #2]
	bl sub_080C92C8
	adds r5, r0, #0
	bl sub_080CC7D4
	adds r0, r5, #0
	adds r0, #0x28
	adds r2, r5, #0
	adds r2, #0x40
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	movs r4, #8
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0x48
	movs r2, #0x8d
	bl sub_080CCFC4
	adds r0, r5, #0
	adds r0, #0x29
	adds r2, r5, #0
	adds r2, #0x41
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0x95
	movs r2, #0x8d
	bl sub_080CCFC4
	adds r0, r5, #0
	adds r0, #0x2a
	adds r2, r5, #0
	adds r2, #0x42
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0xe2
	movs r2, #0x8d
	bl sub_080CCFC4
	adds r0, r5, #0
	adds r0, #0x2b
	adds r2, r5, #0
	adds r2, #0x43
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0x48
	movs r2, #0x9a
	bl sub_080CCFC4
	adds r0, r5, #0
	adds r0, #0x2c
	adds r2, r5, #0
	adds r2, #0x44
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0x95
	movs r2, #0x9a
	bl sub_080CCFC4
	adds r0, r5, #0
	adds r0, #0x2d
	adds r2, r5, #0
	adds r2, #0x45
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r2, r1]
	eors r0, r1
	rsbs r3, r0, #0
	orrs r3, r0
	asrs r3, r3, #0x1f
	ands r3, r4
	adds r0, r1, #0
	movs r1, #0xe2
	movs r2, #0x9a
	bl sub_080CCFC4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080CCE58: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CCE5C
sub_080CCE5C: @ 0x080CCE5C
.L080CCE5C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldrb r0, [r4]
	cmp r0, #0
	beq .L080CCEB4
	ldr r0, .L080CCEC0
	mov r8, r0
	lsls r0, r3, #0x18
	lsrs r6, r0, #0x18
	lsls r5, r1, #0x10
.L080CCE82:
	ldrb r1, [r4]
	adds r0, r1, #0
	subs r0, #0x2b
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	cmp r1, #0x3f
	bne .L080CCE94
	movs r0, #0x13
.L080CCE94:
	cmp r1, #0x2d
	bne .L080CCE9A
	movs r0, #6
.L080CCE9A:
	lsrs r2, r5, #0x10
	str r6, [sp]
	ldr r1, .L080CCEC4
	adds r3, r7, #0
	bl SmallFont_DrawGlyphTinted
	movs r0, #0x80
	lsls r0, r0, #0xc
	adds r5, r5, r0
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080CCE82
.L080CCEB4:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CCEC0: .4byte gUnknown_084F01F4
.L080CCEC4: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080CCEC8
sub_080CCEC8: @ 0x080CCEC8
.L080CCEC8:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r5, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq .L080CCF2C
	ldr r0, .L080CCF3C
	mov sb, r0
	lsls r0, r3, #0x18
	lsrs r6, r0, #0x18
.L080CCEF2:
	ldrb r1, [r4]
	adds r0, r1, #0
	subs r0, #0x2b
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	cmp r1, #0x3f
	bne .L080CCF04
	movs r0, #0x1f
.L080CCF04:
	cmp r1, #0x2d
	bne .L080CCF0A
	movs r0, #0xd
.L080CCF0A:
	cmp r1, #0x5c
	bne .L080CCF10
	movs r0, #0x3e
.L080CCF10:
	mov r1, r8
	adds r2, r1, r5
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r6, [sp]
	ldr r1, .L080CCF40
	adds r3, r7, #0
	bl DigitFont_DrawGlyphTinted
	adds r5, #8
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080CCEF2
.L080CCF2C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CCF3C: .4byte gUnknown_084F0254
.L080CCF40: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080CCF44
sub_080CCF44: @ 0x080CCF44
.L080CCF44:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r4, r1, #0
	adds r5, r3, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	bl NumberToDigits
	adds r7, r0, #0
	movs r2, #0
	subs r4, #0x38
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x10
	movs r4, #0
	ldr r0, .L080CCFBC
	mov sb, r0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
.L080CCF78:
	adds r0, r7, #7
	subs r0, r0, r4
	ldrb r1, [r0]
	adds r0, r1, #5
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	cmp r4, #7
	beq .L080CCF92
	cmp r2, #1
	beq .L080CCF92
	cmp r1, #0
	beq .L080CCFA0
.L080CCF92:
	str r5, [sp]
	ldr r1, .L080CCFC0
	adds r2, r6, #0
	mov r3, r8
	bl SmallFont_DrawGlyphTinted
	movs r2, #1
.L080CCFA0:
	adds r0, r6, #0
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r4, #1
	cmp r4, #7
	bls .L080CCF78
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CCFBC: .4byte gUnknown_084F01F4
.L080CCFC0: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080CCFC4
sub_080CCFC4: @ 0x080CCFC4
.L080CCFC4:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r4, r1, #0
	adds r5, r3, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	bl NumberToDigits
	adds r7, r0, #0
	movs r2, #0
	subs r4, #0x38
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x10
	movs r4, #0
	ldr r0, .L080CD03C
	mov sb, r0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
.L080CCFF8:
	adds r0, r7, #7
	subs r0, r0, r4
	ldrb r1, [r0]
	adds r0, r1, #5
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	cmp r4, #7
	beq .L080CD012
	cmp r2, #1
	beq .L080CD012
	cmp r1, #0
	beq .L080CD020
.L080CD012:
	str r5, [sp]
	ldr r1, .L080CD040
	adds r2, r6, #0
	mov r3, r8
	bl DigitFont_DrawGlyphTinted
	movs r2, #1
.L080CD020:
	adds r0, r6, #0
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r4, #1
	cmp r4, #7
	bls .L080CCFF8
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CD03C: .4byte gUnknown_084F0254
.L080CD040: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080CD044
sub_080CD044: @ 0x080CD044
.L080CD044:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	adds r6, r1, #0
	adds r6, #0x20
	adds r0, r4, #0
	bl sub_080BF648
	adds r5, r0, #0
	adds r0, r4, #0
	bl sub_0815B864
	adds r4, r0, #0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0xc
	bgt .L080CD078
	ldr r0, .L080CD074
	b .L080CD07E
.L080CD074: .4byte gUnknown_084F02B4
.L080CD078:
	cmp r0, #0x1a
	bgt .L080CD090
	ldr r0, .L080CD08C
.L080CD07E:
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	adds r2, r7, #0
	movs r3, #4
	bl sub_080CCE5C
	b .L080CD09E
.L080CD08C: .4byte gUnknown_084F02B8
.L080CD090:
	ldr r0, .L080CD0A8
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	adds r2, r7, #0
	movs r3, #4
	bl sub_080CCE5C
.L080CD09E:
	adds r6, #0x10
	cmp r4, #0
	bne .L080CD0B0
	ldr r0, .L080CD0AC
	b .L080CD0B6
.L080CD0A8: .4byte gUnknown_084F02BC
.L080CD0AC: .4byte gUnknown_084F02C0
.L080CD0B0:
	cmp r4, #1
	bne .L080CD0C8
	ldr r0, .L080CD0C4
.L080CD0B6:
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	adds r2, r7, #0
	movs r3, #4
	bl sub_080CCE5C
	b .L080CD0DA
.L080CD0C4: .4byte gUnknown_084F02C4
.L080CD0C8:
	cmp r4, #2
	bne .L080CD0DA
	ldr r0, .L080CD0E0
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	adds r2, r7, #0
	movs r3, #4
	bl sub_080CCE5C
.L080CD0DA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CD0E0: .4byte gUnknown_084F02C8

	thumb_func_start sub_080CD0E4
sub_080CD0E4: @ 0x080CD0E4
.L080CD0E4:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF648
	ldrb r0, [r0, #0x1d]
	movs r1, #0x90
	movs r2, #0x78
	movs r3, #4
	bl sub_080CCF44
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CD100
sub_080CD100: @ 0x080CD100
.L080CD100:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	lsrs r4, r1, #0x10
	cmp r0, #0xff
	bne .L080CD13C
	ldr r0, .L080CD134
	ldr r1, .L080CD138
	adds r2, r4, #0
	movs r3, #2
	str r3, [sp]
	movs r3, #0xc
	str r3, [sp, #4]
	adds r3, r7, #0
	bl Text_DrawStringTinted
	b .L080CD190
	.byte 0x00, 0x00
.L080CD134: .4byte gUnknown_084F02CA
.L080CD138: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CD13C:
	bl Equipment_GetRecord36_MidRange
	adds r5, r0, #0
	adds r5, #0x14
	ldrh r0, [r0, #0x14]
	cmp r0, #0
	bne .L080CD16C
	movs r5, #7
.L080CD14C:
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	movs r0, #2
	str r0, [sp]
	movs r0, #0x3c
	ldr r1, .L080CD168
	adds r3, r7, #0
	bl Font_DrawGlyphTinted
	adds r4, #0xc
	subs r5, #1
	cmp r5, #0
	bge .L080CD14C
	b .L080CD190
.L080CD168: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CD16C:
	lsls r6, r6, #0x18
	mov r8, r6
	movs r6, #7
.L080CD172:
	ldrh r0, [r5]
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	mov r3, r8
	lsrs r1, r3, #0x18
	str r1, [sp]
	ldr r1, .L080CD19C
	adds r3, r7, #0
	bl Font_DrawGlyphTinted
	adds r4, #0xc
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bge .L080CD172
.L080CD190:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CD19C: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080CD1A0
sub_080CD1A0: @ 0x080CD1A0
.L080CD1A0:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	lsrs r5, r1, #0x10
	bl Action_GetRecord
	adds r4, r0, #0
	adds r4, #0xc
	ldrh r0, [r0, #0xc]
	cmp r0, #0
	beq .L080CD1E8
	lsls r7, r6, #0x18
	movs r6, #7
.L080CD1CC:
	ldrh r0, [r4]
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	lsrs r1, r7, #0x18
	str r1, [sp]
	ldr r1, .L080CD1F4
	mov r3, r8
	bl Font_DrawGlyphTinted
	adds r5, #0xc
	adds r4, #2
	subs r6, #1
	cmp r6, #0
	bge .L080CD1CC
.L080CD1E8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CD1F4: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080CD1F8
sub_080CD1F8: @ 0x080CD1F8
.L080CD1F8:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsrs r4, r1, #0x10
	bl sub_080BF5C0
	adds r5, r0, #6
	ldrh r0, [r0, #6]
	cmp r0, #0
	bne .L080CD238
	movs r5, #7
.L080CD216:
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	movs r0, #2
	str r0, [sp]
	movs r0, #0x3c
	ldr r1, .L080CD234
	adds r3, r7, #0
	bl Font_DrawGlyphTinted
	adds r4, #0xc
	subs r5, #1
	cmp r5, #0
	bge .L080CD216
	b .L080CD252
	.byte 0x00, 0x00
.L080CD234: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CD238:
	movs r6, #7
.L080CD23A:
	ldrh r0, [r5]
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	ldr r1, .L080CD25C
	adds r3, r7, #0
	bl Font_DrawGlyph
	adds r4, #0xc
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bge .L080CD23A
.L080CD252:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CD25C: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080CD260
sub_080CD260: @ 0x080CD260
.L080CD260:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	bl sub_080BF5C0
	ldrb r4, [r0, #3]
	cmp r4, #0
	beq .L080CD294
	ldr r0, .L080CD29C
	adds r1, r5, #0
	adds r2, r6, #0
	movs r3, #0
	bl sub_080CCEC8
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	movs r3, #0
	bl sub_080CCFC4
.L080CD294:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CD29C: .4byte gUnknown_084F00E0

	thumb_func_start sub_080CD2A0
sub_080CD2A0: @ 0x080CD2A0
.L080CD2A0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	mov r5, sb
	movs r0, #0xf
	add r0, r8
	mov sl, r0
	adds r0, r4, #0
	bl sub_080BF648
	adds r6, r0, #0
	adds r6, #0x32
	adds r0, r4, #0
	bl sub_080BF648
	adds r4, r0, #0
	adds r4, #0x48
	movs r7, #0xa
.L080CD2DA:
	ldrh r0, [r6]
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	ldr r1, .L080CD32C
	mov r3, r8
	bl Font_DrawGlyph
	adds r5, #0xc
	adds r6, #2
	subs r7, #1
	cmp r7, #0
	bge .L080CD2DA
	mov r5, sb
	movs r7, #0
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080CD31E
	mov r0, sl
	lsls r6, r0, #0x10
.L080CD300:
	ldrh r0, [r4]
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	ldr r1, .L080CD32C
	lsrs r3, r6, #0x10
	bl Font_DrawGlyph
	adds r5, #0xc
	adds r4, #2
	adds r7, #1
	cmp r7, #0xa
	bgt .L080CD31E
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080CD300
.L080CD31E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CD32C: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080CD330
sub_080CD330: @ 0x080CD330
.L080CD330:
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	adds r4, r5, #0
	adds r4, #0x18
	bl sub_080BF32C
	ldrb r0, [r0, #1]
	mov sb, r0
	ldr r0, .L080CD388
	adds r1, r5, #0
	adds r2, r6, #0
	mov r3, r8
	bl sub_080CCEC8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r0, sb
	adds r1, r4, #0
	adds r2, r6, #0
	mov r3, r8
	bl sub_080CCFC4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CD388: .4byte gUnknown_084F02DC

	thumb_func_start sub_080CD38C
sub_080CD38C: @ 0x080CD38C
.L080CD38C:
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	adds r4, r5, #0
	adds r4, #0x18
	bl sub_080BF32C
	ldrb r0, [r0, #2]
	mov sb, r0
	ldr r0, .L080CD3E4
	adds r1, r5, #0
	adds r2, r6, #0
	mov r3, r8
	bl sub_080CCEC8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r0, sb
	adds r1, r4, #0
	adds r2, r6, #0
	mov r3, r8
	bl sub_080CCFC4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CD3E4: .4byte gUnknown_084F02DC
