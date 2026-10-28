	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start Dict_BuildList
Dict_BuildList: @ 0x080DB4A8
.L080DB4A8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r1, #0
	mov sl, r2
	ldr r0, .L080DB520
	mov sb, r0
	ldr r2, .L080DB524
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0
	strh r4, [r0]
	adds r0, #2
	mov r3, sl
	strh r3, [r0]
	strh r1, [r2, #0x3c]
	strh r1, [r2, #0x3e]
	mov r0, sp
	ldr r1, .L080DB528
	mov r8, r1
	strh r1, [r0]
	ldr r2, .L080DB52C
	mov r1, sb
	bl CpuSet
	cmp r4, #0
	bne .L080DB534
	movs r5, #0
.L080DB4E6:
	lsls r0, r5, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080C2600
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r5
	bne .L080DB510
	adds r0, r4, #0
	bl sub_080DD248
	cmp r0, #0
	beq .L080DB510
	adds r0, r4, #0
	bl sub_080C2600
	mov r2, sb
	strh r0, [r2]
	movs r3, #2
	add sb, r3
.L080DB510:
	adds r5, #1
	ldr r0, .L080DB530
	cmp r5, r0
	bls .L080DB4E6
	ldr r1, .L080DB524
	movs r0, #1
	strh r0, [r1, #0x3e]
	b .L080DB88C
.L080DB520: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DB524: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DB528: .4byte 0x0000FFFF
.L080DB52C: .4byte 0x01000180
.L080DB530: .4byte 0x0000017B
.L080DB534:
	cmp r4, #1
	beq .L080DB53A
	b .L080DB644
.L080DB53A:
	movs r6, #0
.L080DB53C:
	movs r5, #0
	adds r0, r6, #1
	mov r8, r0
.L080DB542:
	lsls r0, r5, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080BF648
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r6
	bne .L080DB57C
	adds r0, r4, #0
	bl sub_080C2600
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r5
	bne .L080DB57C
	adds r0, r4, #0
	bl sub_080DD248
	cmp r0, #0
	beq .L080DB57C
	adds r0, r4, #0
	bl sub_080C2600
	mov r1, sb
	strh r0, [r1]
	movs r2, #2
	add sb, r2
.L080DB57C:
	adds r5, #1
	ldr r0, .L080DB5C4
	cmp r5, r0
	bls .L080DB542
	mov r6, r8
	cmp r6, #0x2c
	bls .L080DB53C
	ldr r3, .L080DB5C8
	mov sb, r3
	mov r0, sl
	cmp r0, #0x28
	bls .L080DB598
	movs r1, #1
	add sl, r1
.L080DB598:
	movs r5, #0
	ldr r7, .L080DB5CC
	ldr r6, .L080DB5D0
	mov r4, sb
.L080DB5A0:
	ldrh r1, [r4]
	cmp r1, r7
	beq .L080DB5D8
	ldr r2, .L080DB5D4
	adds r0, r2, #0
	ands r0, r1
	bl sub_080BF648
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, sl
	bne .L080DB5DE
	strh r5, [r6, #0x3c]
	movs r0, #1
	strh r0, [r6, #0x3e]
	b .L080DB5E8
	.byte 0x00, 0x00
.L080DB5C4: .4byte 0x0000017B
.L080DB5C8: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DB5CC: .4byte 0x0000FFFF
.L080DB5D0: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DB5D4: .4byte 0x00007FFF
.L080DB5D8:
	movs r0, #0
	strh r0, [r6, #0x3c]
	b .L080DB5E8
.L080DB5DE:
	adds r4, #2
	adds r5, #1
	ldr r0, .L080DB634
	cmp r5, r0
	bls .L080DB5A0
.L080DB5E8:
	ldr r3, .L080DB638
	mov sb, r3
	movs r5, #0
	ldrh r0, [r3]
	ldr r1, .L080DB63C
	cmp r0, r1
	bne .L080DB5F8
	b .L080DB88C
.L080DB5F8:
	adds r7, r1, #0
	mov r4, sb
	ldr r0, .L080DB640
	adds r6, r0, #0
.L080DB600:
	ldrh r0, [r4]
	ands r0, r6
	bl sub_080BF648
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, sl
	beq .L080DB61E
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
.L080DB61E:
	adds r4, #2
	adds r5, #1
	ldr r0, .L080DB634
	cmp r5, r0
	bls .L080DB62A
	b .L080DB88C
.L080DB62A:
	ldrh r0, [r4]
	cmp r0, r7
	bne .L080DB600
	b .L080DB88C
	.byte 0x00, 0x00
.L080DB634: .4byte 0x0000017B
.L080DB638: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DB63C: .4byte 0x0000FFFF
.L080DB640: .4byte 0x00007FFF
.L080DB644:
	cmp r4, #2
	bne .L080DB6E4
	movs r7, #0
	movs r6, #0
	movs r5, #0
	ldr r0, .L080DB6D0
	ldrh r4, [r0]
	cmp r4, r8
	bne .L080DB658
	b .L080DB88C
.L080DB658:
	mov r8, r0
.L080DB65A:
	adds r0, r4, #0
	bl sub_080C2600
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r4
	bne .L080DB6B2
	adds r0, r4, #0
	bl sub_080DD248
	cmp r0, #0
	beq .L080DB6B2
	adds r0, r4, #0
	bl sub_080C2600
	adds r1, r0, #0
	mov r3, sb
	strh r1, [r3]
	lsls r0, r5, #2
	ldr r2, .L080DB6D4
	adds r0, r0, r2
	ldrh r2, [r0]
	cmp r2, sl
	beq .L080DB696
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r0, r1
	mov r1, sb
	strh r0, [r1]
.L080DB696:
	movs r3, #2
	add sb, r3
	cmp r7, #0
	bne .L080DB6AC
	cmp r2, sl
	bne .L080DB6AC
	ldr r1, .L080DB6D8
	strh r6, [r1, #0x3c]
	movs r0, #1
	strh r0, [r1, #0x3e]
	movs r7, #1
.L080DB6AC:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080DB6B2:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L080DB6DC
	cmp r5, r0
	bls .L080DB6C0
	b .L080DB88C
.L080DB6C0:
	lsls r0, r5, #2
	add r0, r8
	ldrh r4, [r0]
	ldr r0, .L080DB6E0
	cmp r4, r0
	bne .L080DB65A
	b .L080DB88C
	.byte 0x00, 0x00
.L080DB6D0: .4byte gUnknown_08585C34
.L080DB6D4: .4byte gUnknown_08585C36
.L080DB6D8: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DB6DC: .4byte 0x0000017B
.L080DB6E0: .4byte 0x0000FFFF
.L080DB6E4:
	cmp r4, #3
	beq .L080DB6EA
	b .L080DB88C
.L080DB6EA:
	movs r6, #0
	mov r0, sl
	adds r0, #1
	str r0, [sp, #8]
.L080DB6F2:
	movs r1, #0xb
	subs r1, r1, r6
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0x11
	ldr r1, .L080DB70C
	adds r0, r0, r1
	lsrs r7, r0, #0x10
	cmp r6, #0xa
	bne .L080DB710
	movs r2, #1
	str r2, [sp, #4]
	b .L080DB71E
.L080DB70C: .4byte 0xFFFF0000
.L080DB710:
	movs r1, #0xa
	subs r1, r1, r6
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
.L080DB71E:
	cmp r7, #0x64
	bls .L080DB724
	movs r7, #0xc8
.L080DB724:
	movs r5, #0
	adds r6, #1
	mov r8, r6
.L080DB72A:
	lsls r0, r5, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080BF648
	ldrb r0, [r0, #1]
	ldr r3, [sp, #4]
	cmp r0, r3
	blo .L080DB766
	cmp r0, r7
	bhi .L080DB766
	adds r0, r4, #0
	bl sub_080C2600
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r5
	bne .L080DB766
	adds r0, r4, #0
	bl sub_080DD248
	cmp r0, #0
	beq .L080DB766
	adds r0, r4, #0
	bl sub_080C2600
	mov r1, sb
	strh r0, [r1]
	movs r2, #2
	add sb, r2
.L080DB766:
	adds r5, #1
	ldr r0, .L080DB7B4
	cmp r5, r0
	bls .L080DB72A
	mov r6, r8
	cmp r6, #0xa
	bls .L080DB6F2
	ldr r3, .L080DB7B8
	mov sb, r3
	movs r5, #0
	mov r7, sb
	ldr r6, [sp, #8]
	mov r1, sl
	lsls r0, r1, #2
	add r0, sl
	lsls r0, r0, #0x11
	mov r8, r0
.L080DB788:
	ldrh r1, [r7]
	ldr r2, .L080DB7BC
	cmp r1, r2
	beq .L080DB7E8
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #0x11
	ldr r3, .L080DB7C0
	adds r0, r0, r3
	lsrs r4, r0, #0x10
	ldr r2, .L080DB7C4
	adds r0, r2, #0
	ands r0, r1
	bl sub_080BF648
	ldrb r0, [r0, #1]
	mov r3, sl
	cmp r3, #0
	bne .L080DB7C8
	movs r1, #1
	b .L080DB7CC
	.byte 0x00, 0x00
.L080DB7B4: .4byte 0x0000017B
.L080DB7B8: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DB7BC: .4byte 0x0000FFFF
.L080DB7C0: .4byte 0xFFFF0000
.L080DB7C4: .4byte 0x00007FFF
.L080DB7C8:
	mov r2, r8
	lsrs r1, r2, #0x10
.L080DB7CC:
	cmp r4, #0x64
	bls .L080DB7D2
	movs r4, #0xc8
.L080DB7D2:
	cmp r0, r1
	blo .L080DB7F4
	cmp r0, r4
	bhi .L080DB7F4
	ldr r1, .L080DB7E4
	strh r5, [r1, #0x3c]
	movs r0, #1
	strh r0, [r1, #0x3e]
	b .L080DB7FE
.L080DB7E4: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DB7E8:
	ldr r1, .L080DB7F0
	movs r0, #0
	strh r0, [r1, #0x3c]
	b .L080DB7FE
.L080DB7F0: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DB7F4:
	adds r7, #2
	adds r5, #1
	ldr r0, .L080DB858
	cmp r5, r0
	bls .L080DB788
.L080DB7FE:
	movs r5, #0
	ldr r3, [sp, #8]
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #0x11
	lsrs r6, r0, #0x10
	mov r1, sb
	ldrh r0, [r1]
	ldr r1, .L080DB85C
	cmp r0, r1
	beq .L080DB88C
	mov r8, r3
	mov r4, sb
.L080DB818:
	cmp r6, #0x64
	bls .L080DB81E
	movs r6, #0xc8
.L080DB81E:
	ldrh r1, [r4]
	ldr r7, .L080DB860
	adds r0, r7, #0
	ands r0, r1
	bl sub_080BF648
	ldrb r0, [r0, #1]
	cmp r0, r6
	bhs .L080DB864
	mov r2, sl
	cmp r2, #0
	beq .L080DB870
	ldrh r1, [r4]
	adds r0, r7, #0
	ands r0, r1
	bl sub_080BF648
	ldrb r1, [r0, #1]
	mov r3, sl
	lsls r0, r3, #2
	add r0, sl
	lsls r0, r0, #1
	cmp r1, r0
	bhs .L080DB870
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	b .L080DB86C
.L080DB858: .4byte 0x0000017B
.L080DB85C: .4byte 0x0000FFFF
.L080DB860: .4byte 0x00007FFF
.L080DB864:
	ldrh r0, [r4]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
.L080DB86C:
	orrs r0, r1
	strh r0, [r4]
.L080DB870:
	adds r4, #2
	adds r5, #1
	ldr r0, .L080DB89C
	cmp r5, r0
	bhi .L080DB88C
	mov r1, r8
	lsls r0, r1, #2
	add r0, r8
	lsls r0, r0, #0x11
	lsrs r6, r0, #0x10
	ldrh r0, [r4]
	ldr r2, .L080DB8A0
	cmp r0, r2
	bne .L080DB818
.L080DB88C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080DB89C: .4byte 0x0000017B
.L080DB8A0: .4byte 0x0000FFFF
