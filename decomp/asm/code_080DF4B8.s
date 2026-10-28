	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080DF4B8
sub_080DF4B8: @ 0x080DF4B8
.L080DF4B8:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, .L080DF4D4
	ldrb r1, [r0]
	adds r6, r0, #0
	ldr r7, .L080DF4D8
	cmp r1, #5
	bls .L080DF4CA
	b .L080DF656
.L080DF4CA:
	lsls r0, r1, #2
	ldr r1, .L080DF4DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080DF4D4: .4byte 0x030062F4 @ IWRAM+0x62F4
.L080DF4D8: .4byte 0x03006364 @ IWRAM+0x6364
.L080DF4DC: .4byte gUnknown_080DF4E0
	.global gUnknown_080DF4E0
gUnknown_080DF4E0:
.L080DF4E0: @ jump table
	.4byte .L080DF656
	.4byte .L080DF4F8
	.4byte .L080DF510
	.4byte .L080DF57C
	.4byte .L080DF5E8
	.4byte .L080DF656
.L080DF4F8:
	ldr r0, .L080DF508
	movs r1, #0xf1
	lsls r1, r1, #8
	strh r1, [r0]
	movs r0, #2
	strb r0, [r6]
	ldr r7, .L080DF50C
	b .L080DF656
.L080DF508: .4byte 0x03006380 @ IWRAM+0x6380
.L080DF50C: .4byte 0x03006364 @ IWRAM+0x6364
.L080DF510:
	movs r1, #0
	ldr r7, .L080DF538
	ldr r0, .L080DF53C
	mov ip, r0
	movs r4, #0xf1
	lsls r4, r4, #8
	movs r2, #1
	movs r3, #0
.L080DF520:
	cmp r1, #1
	bhi .L080DF540
	lsls r0, r1, #4
	add r0, ip
	ldrh r0, [r0]
	cmp r0, r4
	beq .L080DF540
	mov r5, sp
	adds r0, r5, r1
	strb r3, [r0]
	b .L080DF546
	.byte 0x00, 0x00
.L080DF538: .4byte 0x03006364 @ IWRAM+0x6364
.L080DF53C: .4byte 0x03006340 @ IWRAM+0x6340
.L080DF540:
	mov r5, sp
	adds r0, r5, r1
	strb r2, [r0]
.L080DF546:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls .L080DF520
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #1
	beq .L080DF55A
	b .L080DF650
.L080DF55A:
	mov r0, sp
	ldrb r0, [r0, #1]
	adds r1, r0, #0
	cmp r1, #1
	bne .L080DF650
	mov r0, sp
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	ldr r1, .L080DF578
	movs r0, #0xf2
	lsls r0, r0, #8
	strh r0, [r1]
	movs r0, #3
	strb r0, [r6]
	b .L080DF656
.L080DF578: .4byte 0x03006380 @ IWRAM+0x6380
.L080DF57C:
	movs r1, #0
	ldr r7, .L080DF5A4
	ldr r0, .L080DF5A8
	mov ip, r0
	movs r4, #0xf2
	lsls r4, r4, #8
	movs r2, #1
	movs r3, #0
.L080DF58C:
	cmp r1, #1
	bhi .L080DF5AC
	lsls r0, r1, #4
	add r0, ip
	ldrh r0, [r0]
	cmp r0, r4
	beq .L080DF5AC
	mov r5, sp
	adds r0, r5, r1
	strb r3, [r0]
	b .L080DF5B2
	.byte 0x00, 0x00
.L080DF5A4: .4byte 0x03006364 @ IWRAM+0x6364
.L080DF5A8: .4byte 0x03006340 @ IWRAM+0x6340
.L080DF5AC:
	mov r5, sp
	adds r0, r5, r1
	strb r2, [r0]
.L080DF5B2:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls .L080DF58C
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #1
	bne .L080DF650
	mov r0, sp
	ldrb r0, [r0, #1]
	adds r1, r0, #0
	cmp r1, #1
	bne .L080DF650
	mov r0, sp
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	ldr r1, .L080DF5E4
	movs r0, #0xf3
	lsls r0, r0, #8
	strh r0, [r1]
	movs r0, #4
	strb r0, [r6]
	b .L080DF656
	.byte 0x00, 0x00
.L080DF5E4: .4byte 0x03006380 @ IWRAM+0x6380
.L080DF5E8:
	movs r1, #0
	ldr r7, .L080DF610
	ldr r0, .L080DF614
	mov ip, r0
	movs r4, #0xf3
	lsls r4, r4, #8
	movs r2, #1
	movs r3, #0
.L080DF5F8:
	cmp r1, #1
	bhi .L080DF618
	lsls r0, r1, #4
	add r0, ip
	ldrh r0, [r0]
	cmp r0, r4
	beq .L080DF618
	mov r5, sp
	adds r0, r5, r1
	strb r3, [r0]
	b .L080DF61E
	.byte 0x00, 0x00
.L080DF610: .4byte 0x03006364 @ IWRAM+0x6364
.L080DF614: .4byte 0x03006340 @ IWRAM+0x6340
.L080DF618:
	mov r5, sp
	adds r0, r5, r1
	strb r2, [r0]
.L080DF61E:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls .L080DF5F8
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #1
	bne .L080DF650
	mov r0, sp
	ldrb r0, [r0, #1]
	adds r2, r0, #0
	cmp r2, #1
	bne .L080DF650
	mov r0, sp
	movs r1, #0
	strb r2, [r0, #2]
	strb r2, [r0, #3]
	movs r0, #5
	strb r0, [r6]
	ldr r0, .L080DF64C
	strh r1, [r0]
	b .L080DF656
.L080DF64C: .4byte 0x03006380 @ IWRAM+0x6380
.L080DF650:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
.L080DF656:
	ldrh r0, [r7]
	cmp r0, #0x3c
	bls .L080DF674
	ldr r1, .L080DF694
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bhi .L080DF6A8
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
	strh r0, [r7]
.L080DF674:
	bl sub_080DFB98
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	cmp r1, #0
	beq .L080DF69C
	ldr r1, .L080DF698
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r0, r1, #0
	b .L080DF6A0
	.byte 0x00, 0x00
.L080DF694: .4byte 0x03006370 @ IWRAM+0x6370
.L080DF698: .4byte 0x03006390 @ IWRAM+0x6390
.L080DF69C:
	ldr r0, .L080DF6AC
	strh r1, [r0]
.L080DF6A0:
	ldrh r1, [r0]
	ldr r0, .L080DF6B0
	cmp r1, r0
	bls .L080DF6B4
.L080DF6A8:
	movs r0, #0xff
	b .L080DF6C6
.L080DF6AC: .4byte 0x03006390 @ IWRAM+0x6390
.L080DF6B0: .4byte 0x00000257
.L080DF6B4:
	ldr r0, .L080DF6C0
	ldrb r0, [r0]
	cmp r0, #5
	bne .L080DF6C4
	movs r0, #1
	b .L080DF6C6
.L080DF6C0: .4byte 0x030062F4 @ IWRAM+0x62F4
.L080DF6C4:
	movs r0, #0
.L080DF6C6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
