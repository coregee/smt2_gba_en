	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080DE2C0
sub_080DE2C0: @ 0x080DE2C0
.L080DE2C0:
	push {r4, lr}
	ldr r0, .L080DE2DC
	movs r2, #0x34
	ldrsh r1, [r0, r2]
	adds r3, r0, #0
	cmp r1, #0x6f
	bls .L080DE2D0
	b .L080DE5E0
.L080DE2D0:
	lsls r0, r1, #2
	ldr r1, .L080DE2E0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080DE2DC: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DE2E0: .4byte gUnknown_080DE2E4
	.global gUnknown_080DE2E4
gUnknown_080DE2E4:
.L080DE2E4: @ jump table
	.4byte .L080DE4A4
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE4B0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE4BC
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE4C8
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE4D4
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE4E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE4EC
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE4F8
	.4byte .L080DE538
	.4byte .L080DE544
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE51C
	.4byte .L080DE544
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE580
	.4byte .L080DE528
	.4byte .L080DE570
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE5E0
	.4byte .L080DE562
	.4byte .L080DE5CC
.L080DE4A4:
	ldr r1, .L080DE4AC
	movs r0, #9
	strb r0, [r1]
	b .L080DE606
.L080DE4AC: .4byte 0x03000037 @ IWRAM+0x37
.L080DE4B0:
	ldr r1, .L080DE4B8
	movs r0, #0x11
	strb r0, [r1]
	b .L080DE606
.L080DE4B8: .4byte 0x03000037 @ IWRAM+0x37
.L080DE4BC:
	ldr r1, .L080DE4C4
	movs r0, #0x1f
	strb r0, [r1]
	b .L080DE606
.L080DE4C4: .4byte 0x03000037 @ IWRAM+0x37
.L080DE4C8:
	ldr r1, .L080DE4D0
	movs r0, #0x27
	strb r0, [r1]
	b .L080DE606
.L080DE4D0: .4byte 0x03000037 @ IWRAM+0x37
.L080DE4D4:
	ldr r1, .L080DE4DC
	movs r0, #0x2e
	strb r0, [r1]
	b .L080DE606
.L080DE4DC: .4byte 0x03000037 @ IWRAM+0x37
.L080DE4E0:
	ldr r1, .L080DE4E8
	movs r0, #0x3c
	strb r0, [r1]
	b .L080DE606
.L080DE4E8: .4byte 0x03000037 @ IWRAM+0x37
.L080DE4EC:
	ldr r1, .L080DE4F4
	movs r0, #0x4a
	strb r0, [r1]
	b .L080DE606
.L080DE4F4: .4byte 0x03000037 @ IWRAM+0x37
.L080DE4F8:
	ldr r1, .L080DE518
	movs r0, #0x51
	strb r0, [r1]
	movs r0, #2
	strh r0, [r3, #0x28]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3, #6]
	b .L080DE606
.L080DE518: .4byte 0x03000037 @ IWRAM+0x37
.L080DE51C:
	ldr r1, .L080DE524
	movs r0, #0x5c
	strb r0, [r1]
	b .L080DE606
.L080DE524: .4byte 0x03000037 @ IWRAM+0x37
.L080DE528:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L080DE534
	b .L080DE602
	.byte 0x00, 0x00
.L080DE534: .4byte 0x0000BFFF
.L080DE538:
	ldrh r0, [r3, #0x1e]
	cmp r0, #0xff
	bhi .L080DE606
	movs r0, #0x50
	strh r0, [r3, #6]
	b .L080DE65E
.L080DE544:
	ldrh r0, [r3, #0x22]
	cmp r0, #1
	bne .L080DE552
	movs r0, #0
	strh r0, [r3, #0x22]
	movs r0, #0x28
.L080DE550:
	strh r0, [r3, #6]
.L080DE552:
	ldrh r0, [r3, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne .L080DE5EE
	b .L080DE5FC
.L080DE562:
	ldrh r0, [r3, #0x22]
	cmp r0, #1
	bne .L080DE552
	movs r0, #0
	strh r0, [r3, #0x22]
	movs r0, #0x78
	b .L080DE550
.L080DE570:
	ldrh r0, [r3, #0x22]
	cmp r0, #1
	bne .L080DE606
	movs r0, #0
	strh r0, [r3, #0x22]
	movs r0, #0x50
	strh r0, [r3, #6]
	b .L080DE606
.L080DE580:
	ldr r2, .L080DE5B8
	ldrh r0, [r2]
	cmp r0, #0
	bne .L080DE59A
	ldr r0, .L080DE5BC
	movs r1, #0x9f
	strb r1, [r0]
	ldr r0, .L080DE5C0
	strb r1, [r0]
	ldr r1, .L080DE5C4
	ldr r4, .L080DE5C8
	adds r0, r4, #0
	strh r0, [r1]
.L080DE59A:
	ldrh r0, [r2]
	cmp r0, #0x9f
	bhi .L080DE606
	adds r0, #0x14
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x50
	bls .L080DE65E
	ldr r1, .L080DE5BC
	ldrb r0, [r1]
	subs r0, #0x14
	strb r0, [r1]
	b .L080DE65E
	.byte 0x00, 0x00
.L080DE5B8: .4byte 0x03000006 @ IWRAM+0x6
.L080DE5BC: .4byte 0x03000037 @ IWRAM+0x37
.L080DE5C0: .4byte 0x03000035 @ IWRAM+0x35
.L080DE5C4: .4byte 0x03000002 @ IWRAM+0x2
.L080DE5C8: .4byte 0x0000FF61
.L080DE5CC:
	movs r0, #1
	bl PalFade_FadeToBlack
	ldr r1, .L080DE5DC
	str r0, [r1]
	movs r0, #1
	strh r0, [r1, #4]
	b .L080DE65E
.L080DE5DC: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DE5E0:
	ldrh r0, [r3, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq .L080DE5FC
.L080DE5EE:
	ldr r1, .L080DE5F8
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	b .L080DE606
.L080DE5F8: .4byte 0x03000038 @ IWRAM+0x38
.L080DE5FC:
	ldr r2, .L080DE664
	ldrh r1, [r2]
	ldr r0, .L080DE668
.L080DE602:
	ands r0, r1
	strh r0, [r2]
.L080DE606:
	ldrh r0, [r3, #6]
	subs r0, #1
	strh r0, [r3, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080DE65E
	movs r0, #8
	strh r0, [r3, #6]
	movs r0, #1
	strh r0, [r3, #0x22]
	ldrh r0, [r3, #0x34]
	adds r0, #1
	strh r0, [r3, #0x34]
	ldr r2, .L080DE66C
	ldr r1, .L080DE670
	movs r4, #0x34
	ldrsh r0, [r3, r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r2, .L080DE674
	movs r4, #0x34
	ldrsh r0, [r3, r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	strb r0, [r2]
	ldr r2, .L080DE678
	movs r4, #0x34
	ldrsh r0, [r3, r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	rsbs r0, r0, #0
	strh r0, [r2]
	ldr r2, .L080DE67C
	movs r4, #0x34
	ldrsh r0, [r3, r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	rsbs r0, r0, #0
	strh r0, [r2]
.L080DE65E:
	pop {r4}
	pop {r0}
	bx r0
.L080DE664: .4byte 0x03000038 @ IWRAM+0x38
.L080DE668: .4byte 0x0000FFFE
.L080DE66C: .4byte 0x03000031 @ IWRAM+0x31
.L080DE670: .4byte gUnknown_085864B0
.L080DE674: .4byte 0x03000035 @ IWRAM+0x35
.L080DE678: .4byte 0x03000000 @ IWRAM
.L080DE67C: .4byte 0x03000002 @ IWRAM+0x2
