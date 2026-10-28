	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_0815201C
sub_0815201C: @ 0x0815201C
.L0815201C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r4, .L08152044
	ldrh r0, [r4, #8]
	bl FieldMap_GetArea
	adds r5, r0, #0
	ldr r0, [r4]
	cmp r0, #0x10
	bls .L0815203A
	b .L0815213A
.L0815203A:
	lsls r0, r0, #2
	ldr r1, .L08152048
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08152044: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152048: .4byte gUnknown_0815204C
	.global gUnknown_0815204C
gUnknown_0815204C:
.L0815204C: @ jump table
	.4byte .L08152090
	.4byte .L08152098
	.4byte .L081520C4
	.4byte .L081520CA
	.4byte .L081520D4
	.4byte .L0815211C
	.4byte .L08152124
	.4byte .L0815212C
	.4byte .L081520DC
	.4byte .L081520E4
	.4byte .L081520EC
	.4byte .L081520F4
	.4byte .L08152114
	.4byte .L081520C4
	.4byte .L0815213A
	.4byte .L0815213A
	.4byte .L0815213A
.L08152090:
	ldr r0, .L08152094
	b .L0815212E
.L08152094: .4byte gUnknown_087DFBA0
.L08152098:
	bl sub_08152F80
	bl sub_081529E0
	ldr r3, .L081520C0
	ldrh r2, [r3, #0xc]
	lsrs r2, r2, #4
	ldrh r1, [r3, #0xe]
	lsrs r1, r1, #4
	lsls r1, r1, #6
	adds r2, r2, r1
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsrs r0, r0, #4
	strh r0, [r3, #0x26]
	b .L0815213A
	.byte 0x00, 0x00
.L081520C0: .4byte 0x030069F0 @ IWRAM+0x69F0
.L081520C4:
	bl sub_0815300C
	b .L0815213A
.L081520CA:
	ldr r0, .L081520D0
	b .L0815212E
	.byte 0x00, 0x00
.L081520D0: .4byte gUnknown_087DFEF0
.L081520D4:
	ldr r0, .L081520D8
	b .L0815212E
.L081520D8: .4byte gUnknown_087DFF58
.L081520DC:
	ldr r0, .L081520E0
	b .L0815212E
.L081520E0: .4byte gUnknown_087DFFC0
.L081520E4:
	ldr r0, .L081520E8
	b .L0815212E
.L081520E8: .4byte gUnknown_087E0998
.L081520EC:
	ldr r0, .L081520F0
	b .L081520F6
.L081520F0: .4byte gUnknown_087E0DA0
.L081520F4:
	ldr r0, .L08152108
.L081520F6:
	ldr r1, .L0815210C
	bl Task_Create
	ldr r1, .L08152110
	movs r0, #0x10
	str r0, [r1]
	movs r0, #1
	strh r0, [r1, #0x36]
	b .L0815213A
.L08152108: .4byte gUnknown_087E0F54
.L0815210C: .4byte 0x0000FFFF
.L08152110: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152114:
	ldr r0, .L08152118
	b .L0815212E
.L08152118: .4byte gUnknown_087E0DD0
.L0815211C:
	ldr r0, .L08152120
	b .L0815212E
.L08152120: .4byte gUnknown_087E0028
.L08152124:
	ldr r0, .L08152128
	b .L0815212E
.L08152128: .4byte gUnknown_087E0090
.L0815212C:
	ldr r0, .L0815214C
.L0815212E:
	ldr r1, .L08152150
	bl Task_Create
	ldr r1, .L08152154
	movs r0, #0x10
	str r0, [r1]
.L0815213A:
	ldr r0, .L08152154
	ldrh r1, [r0, #0xc]
	mov r8, r0
	cmp r1, #0x78
	bhi .L08152158
	adds r2, r1, #0
	str r2, [sp]
	b .L0815217E
	.byte 0x00, 0x00
.L0815214C: .4byte gUnknown_087E0120
.L08152150: .4byte 0x0000FFFF
.L08152154: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152158:
	mov r7, r8
	ldrh r3, [r7, #0xc]
	adds r0, r3, #0
	subs r0, #0x78
	adds r1, r5, #0
	adds r1, #0xc8
	ldrh r2, [r1]
	adds r1, r2, #0
	subs r1, #0xf0
	cmp r0, r1
	blt .L0815217A
	adds r0, r3, #0
	adds r0, #0xf0
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L0815217C
.L0815217A:
	movs r0, #0x78
.L0815217C:
	str r0, [sp]
.L0815217E:
	mov r1, r8
	ldrh r0, [r1, #0xe]
	cmp r0, #0x50
	bhi .L0815218C
	adds r2, r0, #0
	mov sl, r2
	b .L081521B0
.L0815218C:
	mov r7, r8
	ldrh r3, [r7, #0xe]
	adds r0, r3, #0
	subs r0, #0x50
	adds r1, r5, #0
	adds r1, #0xca
	ldrh r2, [r1]
	adds r1, r2, #0
	subs r1, #0xa0
	cmp r0, r1
	blt .L081521AC
	adds r0, #0xf0
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L081521AE
.L081521AC:
	movs r0, #0x50
.L081521AE:
	mov sl, r0
.L081521B0:
	ldr r7, .L08152220
	ldrh r0, [r7, #8]
	bl FieldMap_GetArea
	mov sb, r0
	ldr r0, [r7]
	cmp r0, #2
	beq .L081521C4
	cmp r0, #0xd
	bne .L08152232
.L081521C4:
	ldrh r1, [r7, #0x10]
	lsrs r1, r1, #3
	mov r8, r1
	ldrh r4, [r7, #0x12]
	lsrs r4, r4, #3
	movs r0, #0
	bl sub_08151FD8
	adds r1, r0, #0
	mov r6, sb
	adds r6, #0xc8
	ldrh r0, [r6]
	lsrs r0, r0, #3
	muls r0, r4, r0
	add r0, r8
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	ldr r4, .L08152224
	adds r2, r4, #0
	ands r2, r0
	str r2, [sp, #4]
	ldrh r0, [r7, #0x14]
	lsrs r0, r0, #3
	mov sb, r0
	ldrh r0, [r7, #0x16]
	lsrs r5, r0, #3
	movs r0, #0
	bl sub_08151FD8
	adds r1, r0, #0
	ldrh r0, [r6]
	lsrs r0, r0, #3
	muls r0, r5, r0
	add r0, sb
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	ands r4, r0
	mov r8, r6
	ldr r0, [sp, #4]
	cmp r4, r0
	bne .L08152228
	mov r6, sb
	adds r4, r5, #0
	b .L08152240
.L08152220: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152224: .4byte 0x000001FF
.L08152228:
	ldrh r0, [r7, #0xc]
	lsrs r6, r0, #3
	ldrh r0, [r7, #0xe]
	lsrs r4, r0, #3
	b .L08152240
.L08152232:
	ldrh r0, [r7, #0xc]
	lsrs r6, r0, #3
	ldrh r0, [r7, #0xe]
	lsrs r4, r0, #3
	movs r1, #0xc8
	add r1, sb
	mov r8, r1
.L08152240:
	movs r0, #0
	bl sub_08151FD8
	adds r1, r0, #0
	mov r2, r8
	ldrh r0, [r2]
	lsrs r0, r0, #3
	muls r0, r4, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	ldr r0, .L08152290
	ands r0, r1
	cmp r0, #0
	beq .L0815226A
	ldr r0, .L08152294
	ldrh r1, [r0, #0x1c]
	mov r8, r0
	cmp r1, #0
	beq .L081522C0
.L0815226A:
	ldr r4, .L08152298
	movs r0, #0
	strb r0, [r4]
	ldr r3, .L0815229C
	strb r0, [r3]
	ldr r2, .L081522A0
	strb r0, [r2]
	ldr r1, .L081522A4
	strb r0, [r1]
	movs r7, #2
	mov sb, r7
	ldr r0, .L08152294
	mov r8, r0
	mov ip, r3
	adds r6, r2, #0
	adds r5, r1, #0
	mov r3, sl
	subs r3, #0x10
	b .L081522EC
.L08152290: .4byte 0x000001FF
.L08152294: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152298: .4byte 0x03000030 @ IWRAM+0x30
.L0815229C: .4byte 0x03000031 @ IWRAM+0x31
.L081522A0: .4byte 0x03000034 @ IWRAM+0x34
.L081522A4: .4byte 0x03000035 @ IWRAM+0x35
.L081522A8:
	movs r0, #0
	ldr r1, .L081522BC
	strb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	strb r0, [r6]
	strb r0, [r5]
	movs r7, #2
	mov sb, r7
	b .L08152320
.L081522BC: .4byte 0x03000030 @ IWRAM+0x30
.L081522C0:
	ldr r6, .L08152368
	movs r0, #0x88
	strb r0, [r6]
	ldr r7, .L0815236C
	movs r0, #0x68
	strb r0, [r7]
	ldr r4, .L08152370
	mov r0, sl
	adds r0, #0x10
	strb r0, [r4]
	ldr r2, .L08152374
	mov r3, sl
	subs r3, #0x10
	strb r3, [r2]
	ldr r1, .L08152378
	movs r0, #0x3f
	strb r0, [r1]
	movs r0, #3
	mov sb, r0
	mov ip, r7
	adds r6, r4, #0
	adds r5, r2, #0
.L081522EC:
	mov r1, r8
	ldrh r0, [r1, #8]
	ldr r4, [sp]
	subs r4, #0x10
	cmp r0, #2
	bne .L08152320
	ldr r1, .L0815237C
	ldrh r0, [r1]
	ldr r2, .L08152380
	cmp r0, r2
	beq .L08152320
	mov r7, r8
	ldrh r7, [r7, #0xc]
	str r7, [sp, #8]
.L08152308:
	ldr r7, [sp, #8]
	cmp r7, r0
	bne .L08152318
	mov r7, r8
	ldrh r0, [r7, #0xe]
	ldrh r7, [r1, #2]
	cmp r0, r7
	beq .L081522A8
.L08152318:
	adds r1, #4
	ldrh r0, [r1]
	cmp r0, r2
	bne .L08152308
.L08152320:
	mov r1, r8
	ldrh r0, [r1, #8]
	cmp r0, #8
	bne .L08152340
	ldrh r0, [r1, #0xe]
	cmp r0, #0x5f
	bhi .L08152340
	movs r0, #0
	ldr r2, .L08152368
	strb r0, [r2]
	mov r7, ip
	strb r0, [r7]
	strb r0, [r6]
	strb r0, [r5]
	movs r0, #2
	mov sb, r0
.L08152340:
	mov r1, r8
	strh r4, [r1, #0x1e]
	strh r3, [r1, #0x20]
	ldr r0, [sp]
	mov r1, sl
	mov r2, sb
	bl sub_080C2F44
	bl sub_08153C98
	bl sub_08153D88
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08152368: .4byte 0x03000030 @ IWRAM+0x30
.L0815236C: .4byte 0x03000031 @ IWRAM+0x31
.L08152370: .4byte 0x03000034 @ IWRAM+0x34
.L08152374: .4byte 0x03000035 @ IWRAM+0x35
.L08152378: .4byte 0x03000038 @ IWRAM+0x38
.L0815237C: .4byte gUnknown_087DF95C
.L08152380: .4byte 0x0000FFFF

	thumb_func_start sub_08152384
sub_08152384: @ 0x08152384
	push {r4, lr}
	ldr r2, .L081523BC
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r3, .L081523C0
	ldrh r1, [r3]
	movs r0, #0xff
	ands r0, r1
	strh r0, [r3]
	ldr r2, .L081523C4
	ldrh r4, [r2, #0x20]
	lsls r0, r4, #8
	movs r1, #0x24
	orrs r0, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0
	strh r0, [r2, #0x1a]
	ldrh r0, [r2, #0x1e]
	strh r0, [r2, #0x22]
	strh r4, [r2, #0x24]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081523BC: .4byte 0x04000200 @ REG_IE
.L081523C0: .4byte 0x04000004 @ REG_DISPSTAT
.L081523C4: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start sub_081523C8
sub_081523C8: @ 0x081523C8
	push {r4, lr}
	ldr r4, .L08152410
	ldrh r3, [r4, #0x1a]
	cmp r3, #0x20
	beq .L08152408
	ldrh r1, [r4, #0x22]
	ldrh r2, [r4, #0x1a]
	lsls r2, r2, #2
	ldr r0, .L08152414
	adds r2, r2, r0
	ldrh r0, [r2]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	ldrh r2, [r2, #2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, .L08152418
	lsrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2]
	adds r0, r3, #1
	strh r0, [r4, #0x1a]
	ldr r3, .L0815241C
	ldrh r1, [r4, #0x24]
	adds r1, r1, r0
	lsls r1, r1, #8
	ldrh r2, [r3]
	movs r0, #0xff
	ands r0, r2
	orrs r1, r0
	strh r1, [r3]
.L08152408:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08152410: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152414: .4byte gUnknown_087DFA58
.L08152418: .4byte 0x04000040 @ REG_WIN0H
.L0815241C: .4byte 0x04000004 @ REG_DISPSTAT

	thumb_func_start sub_08152420
sub_08152420: @ 0x08152420
.L08152420:
	push {lr}
	ldr r0, .L08152434
	ldr r1, .L08152438
	str r1, [r0, #8]
	ldr r0, .L0815243C
	bl VBlankTask_AddAlways
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08152434: .4byte 0x030020F0 @ IWRAM+0x20F0
.L08152438: .4byte sub_081523C8
.L0815243C: .4byte sub_08152384

	thumb_func_start sub_08152440
sub_08152440: @ 0x08152440
.L08152440:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	mov sl, r1
	ldr r4, [sp, #0x28]
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	lsls r4, r4, #0x10
	ldr r0, .L08152478
	ldrh r0, [r0, #8]
	bl FieldMap_GetArea
	adds r1, r0, #0
	lsrs r4, r4, #0x13
	str r4, [sp, #4]
	cmp r5, #0x78
	bls .L0815247C
	adds r0, r5, #0
	subs r0, #0x78
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	b .L0815247E
.L08152478: .4byte 0x030069F0 @ IWRAM+0x69F0
.L0815247C:
	movs r6, #0
.L0815247E:
	adds r0, r1, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	subs r0, #0xf0
	cmp r6, r0
	ble .L0815248E
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0815248E:
	lsrs r6, r6, #3
	cmp r7, #0x50
	bls .L0815249E
	adds r0, r7, #0
	subs r0, #0x50
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b .L081524A0
.L0815249E:
	movs r5, #0
.L081524A0:
	adds r0, r1, #0
	adds r0, #0xca
	ldrh r0, [r0]
	subs r0, #0xa0
	cmp r5, r0
	ble .L081524B0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L081524B0:
	lsrs r5, r5, #3
	movs r0, #0x1f
	mov ip, r6
	mov r1, ip
	ands r1, r0
	mov ip, r1
	mov r8, r5
	mov r2, r8
	ands r2, r0
	mov r8, r2
	movs r1, #0
	movs r3, #0x1f
	mov sb, r3
.L081524CA:
	adds r0, r5, r1
	ldr r4, [sp, #4]
	muls r0, r4, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	ldr r3, [sp]
	adds r2, r3, r0
	movs r3, #0
	mov r4, r8
	adds r0, r4, r1
	adds r7, r1, #1
	mov r1, sb
	ands r0, r1
	lsls r4, r0, #5
.L081524E6:
	mov r1, ip
	adds r0, r1, r3
	mov r1, sb
	ands r0, r1
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sl
	ldrh r1, [r2]
	strh r1, [r0]
	adds r2, #2
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x1f
	bls .L081524E6
	lsls r0, r7, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x1f
	bls .L081524CA
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0815251C
sub_0815251C: @ 0x0815251C
.L0815251C:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0815255C
	ldrh r1, [r2, #0xc]
	lsrs r6, r1, #4
	ldrh r1, [r2, #0xe]
	lsrs r5, r1, #4
	ldr r3, .L08152560
	adds r4, r2, #0
	adds r1, r3, #6
	adds r1, r0, r1
.L08152534:
	ldrb r0, [r3]
	cmp r0, #0xff
	beq .L08152570
	adds r2, r4, #0
	ldrh r7, [r2, #8]
	cmp r0, r7
	bne .L0815256A
	ldrh r0, [r3, #2]
	cmp r6, r0
	bne .L0815256A
	ldrh r7, [r3, #4]
	cmp r5, r7
	bne .L0815256A
	ldrb r0, [r3, #1]
	cmp r0, #0
	bne .L08152564
	ldrb r0, [r3, #6]
	strh r0, [r2, #0x1c]
	b .L08152570
	.byte 0x00, 0x00
.L0815255C: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152560: .4byte gUnknown_087DFAD8
.L08152564:
	ldrb r0, [r1]
	strh r0, [r4, #0x1c]
	b .L08152570
.L0815256A:
	adds r1, #0x10
	adds r3, #0x10
	b .L08152534
.L08152570:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08152578
sub_08152578: @ 0x08152578
	ldr r0, .L08152580
	str r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L08152580: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start FieldMap_LoadTiles
FieldMap_LoadTiles: @ 0x08152584
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r0, .L081525C8
	ldrh r0, [r0, #8]
	bl FieldMap_GetArea
	adds r4, r0, #0
	ldr r6, .L081525CC
	lsls r0, r5, #0xc
	adds r6, r0, r6
	movs r0, #0
	str r0, [sp]
	ldr r2, .L081525D0
	mov r0, sp
	adds r1, r6, #0
	bl CpuSet
	lsls r5, r5, #2
	adds r4, r4, r5
	ldr r0, [r4]
	ldr r4, .L081525D4
	adds r1, r4, #0
	bl HuffUnComp
	adds r0, r4, #0
	adds r1, r6, #0
	bl LZ77UnCompWram
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081525C8: .4byte 0x030069F0 @ IWRAM+0x69F0
.L081525CC: .4byte 0x02001000 @ EWRAM+0x1000
.L081525D0: .4byte 0x05000400
.L081525D4: .4byte 0x0200AFC8 @ EWRAM+0xAFC8

	thumb_func_start FieldMap_LoadBlockData
FieldMap_LoadBlockData: @ 0x081525D8
	push {r4, r5, lr}
	adds r4, r1, #0
	ldr r0, .L0815260C
	ldrh r0, [r0, #8]
	bl FieldMap_GetArea
	lsls r1, r4, #2
	adds r0, #0xa8
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L08152626
	ldr r5, .L08152610
	adds r1, r5, #0
	bl HuffUnComp
	cmp r4, #3
	bhi .L08152618
	lsls r1, r4, #0xc
	ldr r0, .L08152614
	adds r1, r1, r0
	adds r0, r5, #0
	bl LZ77UnCompWram
	b .L08152626
	.byte 0x00, 0x00
.L0815260C: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152610: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L08152614: .4byte 0x02005004 @ EWRAM+0x5004
.L08152618:
	subs r1, r4, #4
	lsls r1, r1, #0xc
	ldr r0, .L0815262C
	adds r1, r1, r0
	adds r0, r5, #0
	bl LZ77UnCompWram
.L08152626:
	pop {r4, r5}
	pop {r0}
	bx r0
.L0815262C: .4byte 0x02030C74 @ EWRAM+0x30C74

	thumb_func_start FieldMap_LoadMapChunk
FieldMap_LoadMapChunk: @ 0x08152630
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r1, #0
	ldr r0, .L081526C0
	ldrh r0, [r0, #8]
	bl FieldMap_GetArea
	adds r6, r0, #0
	ldr r5, .L081526C4
	lsls r0, r7, #0xc
	adds r5, r0, r5
	movs r0, #0
	str r0, [sp]
	ldr r2, .L081526C8
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	ldr r0, [r6, #0x24]
	cmp r0, #0
	beq .L08152678
	lsls r1, r7, #2
	adds r0, r6, #0
	adds r0, #0x20
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L08152678
	ldr r4, .L081526CC
	adds r1, r4, #0
	bl HuffUnComp
	adds r0, r4, #0
	adds r1, r5, #0
	bl LZ77UnCompWram
.L08152678:
	ldr r5, .L081526C4
	lsls r0, r7, #0xc
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	adds r5, r0, r5
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #4
	ldr r2, .L081526C8
	adds r1, r5, #0
	bl CpuSet
	ldr r0, [r6, #0x64]
	cmp r0, #0
	beq .L081526B6
	lsls r1, r7, #2
	adds r0, r6, #0
	adds r0, #0x60
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L081526B6
	ldr r4, .L081526CC
	adds r1, r4, #0
	bl HuffUnComp
	adds r0, r4, #0
	adds r1, r5, #0
	bl LZ77UnCompWram
.L081526B6:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081526C0: .4byte 0x030069F0 @ IWRAM+0x69F0
.L081526C4: .4byte 0x0200F874 @ EWRAM+0xF874
.L081526C8: .4byte 0x05000400
.L081526CC: .4byte 0x0200AFC8 @ EWRAM+0xAFC8

	thumb_func_start sub_081526D0
sub_081526D0: @ 0x081526D0
	ldr r1, .L081526E4
	ldr r0, .L081526E8
	str r0, [r1]
	ldr r0, .L081526EC
	str r0, [r1, #4]
	ldr r0, .L081526F0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L081526E4: .4byte 0x040000D4 @ REG_DMA3SAD
.L081526E8: .4byte 0x02001000 @ EWRAM+0x1000
.L081526EC: .4byte 0x06004000 @ VRAM+0x4000
.L081526F0: .4byte 0x84002000

	thumb_func_start sub_081526F4
sub_081526F4: @ 0x081526F4
	push {lr}
	ldr r0, .L08152704
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08152704: .4byte sub_081526D0

	thumb_func_start sub_08152708
sub_08152708: @ 0x08152708
	ldr r1, .L0815271C
	ldr r0, .L08152720
	str r0, [r1]
	ldr r0, .L08152724
	str r0, [r1, #4]
	ldr r0, .L08152728
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L0815271C: .4byte 0x040000D4 @ REG_DMA3SAD
.L08152720: .4byte 0x02000000 @ EWRAM
.L08152724: .4byte 0x06002000 @ VRAM+0x2000
.L08152728: .4byte 0x84000200

	thumb_func_start sub_0815272C
sub_0815272C: @ 0x0815272C
	ldr r1, .L08152740
	ldr r0, .L08152744
	str r0, [r1]
	ldr r0, .L08152748
	str r0, [r1, #4]
	ldr r0, .L0815274C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L08152740: .4byte 0x040000D4 @ REG_DMA3SAD
.L08152744: .4byte 0x02000800 @ EWRAM+0x800
.L08152748: .4byte 0x06003000 @ VRAM+0x3000
.L0815274C: .4byte 0x84000200

	thumb_func_start sub_08152750
sub_08152750: @ 0x08152750
.L08152750:
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r1, #0
	adds r4, r2, #0
	ldr r6, .L0815276C
	ldrh r0, [r6, #8]
	bl FieldMap_GetArea
	adds r5, r0, #0
	cmp r4, #2
	beq .L08152770
	cmp r4, #3
	beq .L081527A4
	b .L081527CE
.L0815276C: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152770:
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	bl sub_08151FD8
	ldr r1, .L0815279C
	ldrh r2, [r6, #0xc]
	ldrh r3, [r6, #0xe]
	adds r4, r5, #0
	adds r4, #0xc8
	ldrh r4, [r4]
	str r4, [sp]
	adds r4, r5, #0
	adds r4, #0xca
	ldrh r4, [r4]
	str r4, [sp, #4]
	bl sub_08152440
	ldr r0, .L081527A0
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L081527CE
.L0815279C: .4byte 0x02000000 @ EWRAM
.L081527A0: .4byte sub_08152708
.L081527A4:
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	bl sub_08151FD8
	ldr r1, .L081527D8
	ldrh r2, [r6, #0xc]
	ldrh r3, [r6, #0xe]
	adds r4, r5, #0
	adds r4, #0xc8
	ldrh r4, [r4]
	str r4, [sp]
	adds r4, r5, #0
	adds r4, #0xca
	ldrh r4, [r4]
	str r4, [sp, #4]
	bl sub_08152440
	ldr r0, .L081527DC
	movs r1, #1
	bl VBlankTask_AddCounted
.L081527CE:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081527D8: .4byte 0x02000800 @ EWRAM+0x800
.L081527DC: .4byte sub_0815272C

	thumb_func_start sub_081527E0
sub_081527E0: @ 0x081527E0
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L0815281C
	ldrh r0, [r0, #8]
	bl FieldMap_GetArea
	adds r4, r0, #0
	ldr r5, .L08152820
	adds r0, r5, #0
	movs r1, #0xc
	bl sub_080C67C0
	adds r4, #0xa0
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r5, r0
	adds r3, r0, #0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	movs r0, #0
	strh r0, [r5, #2]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815281C: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152820: .4byte 0x030029B0 @ IWRAM+0x29B0

	thumb_func_start sub_08152824
sub_08152824: @ 0x08152824
	ldr r1, .L08152838
	ldr r0, .L0815283C
	str r0, [r1]
	ldr r0, .L08152840
	str r0, [r1, #4]
	ldr r0, .L08152844
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L08152838: .4byte 0x040000D4 @ REG_DMA3SAD
.L0815283C: .4byte 0x02001000 @ EWRAM+0x1000
.L08152840: .4byte 0x06015000 @ VRAM+0x15000
.L08152844: .4byte 0x84000800

	thumb_func_start sub_08152848
sub_08152848: @ 0x08152848
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L08152898
	ldr r5, .L0815289C
	adds r1, r5, #0
	bl HuffUnComp
	ldr r4, .L081528A0
	adds r0, r5, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L081528A4
	adds r1, r5, #0
	bl HuffUnComp
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L081528A8
	ldr r2, .L081528AC
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x60
	bl Palette_CopyWithEffect
	ldr r0, .L081528B0
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08152898: .4byte gUnknown_087DDE08
.L0815289C: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L081528A0: .4byte 0x02001000 @ EWRAM+0x1000
.L081528A4: .4byte gUnknown_087DE4C8
.L081528A8: .4byte gUnknown_087DE8C4
.L081528AC: .4byte 0x03002D50 @ IWRAM+0x2D50
.L081528B0: .4byte sub_08152824

	thumb_func_start sub_081528B4
sub_081528B4: @ 0x081528B4
	push {r4, r5, lr}
	movs r0, #0x69
	bl Flag_Test
	cmp r0, #0
	beq .L081528DC
	ldr r0, .L081528D4
	bl Flag_Test
	cmp r0, #0
	bne .L081528DC
	ldr r1, .L081528D8
	movs r0, #9
	str r0, [r1]
	b .L081529D8
	.byte 0x00, 0x00
.L081528D4: .4byte 0x00000109
.L081528D8: .4byte 0x030069F0 @ IWRAM+0x69F0
.L081528DC:
	ldr r0, .L08152900
	ldrh r1, [r0, #8]
	adds r5, r0, #0
	cmp r1, #6
	bne .L08152950
	movs r0, #0x61
	bl Flag_Test
	cmp r0, #0
	beq .L08152904
	movs r0, #0x79
	bl Flag_Test
	cmp r0, #0
	bne .L08152904
	movs r0, #0xa
	b .L081529D6
	.byte 0x00, 0x00
.L08152900: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152904:
	ldr r0, .L08152928
	ldrh r1, [r0, #8]
	adds r5, r0, #0
	cmp r1, #6
	bne .L08152950
	movs r0, #0x79
	bl Flag_Test
	cmp r0, #0
	beq .L0815292C
	movs r0, #0x63
	bl Flag_Test
	cmp r0, #0
	bne .L0815292C
	movs r0, #0xb
	b .L081529D6
	.byte 0x00, 0x00
.L08152928: .4byte 0x030069F0 @ IWRAM+0x69F0
.L0815292C:
	ldr r0, .L0815294C
	ldrh r1, [r0, #8]
	adds r5, r0, #0
	cmp r1, #6
	bne .L08152950
	ldrh r0, [r5, #0xc]
	lsrs r0, r0, #4
	cmp r0, #0x1f
	bne .L08152950
	ldrh r0, [r5, #0xe]
	lsrs r0, r0, #4
	cmp r0, #0x47
	bne .L08152950
	movs r0, #0xc
	b .L081529D6
	.byte 0x00, 0x00
.L0815294C: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152950:
	ldr r0, .L08152978
	ldr r2, .L0815297C
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r2, #1
	adds r0, r0, r2
	ldrb r2, [r0]
	adds r4, r5, #0
	ldrh r0, [r4, #4]
	cmp r0, #0
	bne .L081529A8
	cmp r1, #4
	bne .L08152984
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #0x3b
	bne .L08152984
	ldr r0, .L08152980
	b .L0815298C
	.byte 0x00, 0x00
.L08152978: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815297C: .4byte 0x000018C2
.L08152980: .4byte gUnknown_087DFB88
.L08152984:
	ldr r1, .L081529A0
	lsrs r0, r2, #6
	lsls r0, r0, #1
	adds r0, r0, r1
.L0815298C:
	ldrh r0, [r0]
	bl sub_08152A04
	ldr r0, .L081529A4
	movs r1, #1
	strh r1, [r0, #0x18]
	movs r1, #0xd
	str r1, [r0]
	b .L081529D8
	.byte 0x00, 0x00
.L081529A0: .4byte gUnknown_087DFB88
.L081529A4: .4byte 0x030069F0 @ IWRAM+0x69F0
.L081529A8:
	cmp r0, #3
	bne .L081529D4
	ldr r2, .L081529CC
	ldr r0, .L081529D0
	ldrh r1, [r0, #8]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	bl sub_08152A04
	movs r0, #1
	strh r0, [r4, #0x18]
	movs r0, #0xd
	str r0, [r4]
	b .L081529D8
	.byte 0x00, 0x00
.L081529CC: .4byte gUnknown_087DFB90
.L081529D0: .4byte 0x03003FD0 @ IWRAM+0x3FD0
.L081529D4:
	movs r0, #1
.L081529D6:
	str r0, [r5]
.L081529D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081529E0
sub_081529E0: @ 0x081529E0
.L081529E0:
	push {lr}
	ldr r0, .L081529F0
	ldrh r0, [r0, #0x1c]
	cmp r0, #0
	beq .L081529F8
	ldr r0, .L081529F4
	b .L081529FA
	.byte 0x00, 0x00
.L081529F0: .4byte 0x030069F0 @ IWRAM+0x69F0
.L081529F4: .4byte 0x02030C74 @ EWRAM+0x30C74
.L081529F8:
	ldr r0, .L08152A00
.L081529FA:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08152A00: .4byte 0x02005004 @ EWRAM+0x5004

	thumb_func_start sub_08152A04
sub_08152A04: @ 0x08152A04
.L08152A04:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	bl sub_081529E0
	adds r5, r0, #0
	movs r7, #0
	movs r0, #0
	mov r8, r0
	ldr r0, .L08152A74
	ldrh r2, [r0, #0xc]
	lsrs r4, r2, #4
	ldrh r1, [r0, #0xe]
	lsrs r6, r1, #4
	strh r2, [r0, #0x14]
	strh r1, [r0, #0x16]
	movs r2, #0
	ldr r3, .L08152A78
	movs r1, #0xf0
	ldrh r0, [r3]
	mov ip, r0
	mov r0, sb
	ands r1, r0
	cmp ip, r1
	beq .L08152A54
.L08152A40:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #7
	bhi .L08152A54
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, r1
	bne .L08152A40
.L08152A54:
	adds r0, r2, #0
	bl sub_0815251C
	subs r2, r6, #1
	lsls r0, r2, #6
	subs r0, #1
	adds r0, r4, r0
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne .L08152A7C
	movs r0, #1
	b .L08152A7E
	.byte 0x00, 0x00
.L08152A74: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152A78: .4byte gUnknown_087DFB90
.L08152A7C:
	movs r0, #0
.L08152A7E:
	str r0, [sp]
	lsls r0, r2, #6
	adds r0, r4, r0
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne .L08152A94
	movs r0, #1
	b .L08152A96
.L08152A94:
	movs r0, #0
.L08152A96:
	str r0, [sp, #4]
	lsls r0, r2, #6
	adds r0, #1
	adds r0, r4, r0
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne .L08152AAE
	movs r0, #1
	b .L08152AB0
.L08152AAE:
	movs r0, #0
.L08152AB0:
	str r0, [sp, #8]
	lsls r2, r6, #6
	adds r0, r2, #1
	adds r0, r4, r0
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r3, r2, #0
	cmp r0, #0
	bne .L08152ACA
	movs r0, #1
	b .L08152ACC
.L08152ACA:
	movs r0, #0
.L08152ACC:
	str r0, [sp, #0xc]
	adds r2, r6, #1
	lsls r0, r2, #6
	adds r0, #1
	adds r0, r4, r0
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne .L08152AE6
	movs r0, #1
	b .L08152AE8
.L08152AE6:
	movs r0, #0
.L08152AE8:
	str r0, [sp, #0x10]
	lsls r0, r2, #6
	adds r0, r4, r0
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne .L08152AFE
	movs r0, #1
	b .L08152B00
.L08152AFE:
	movs r0, #0
.L08152B00:
	str r0, [sp, #0x14]
	lsls r0, r2, #6
	subs r0, #1
	adds r0, r4, r0
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne .L08152B18
	movs r0, #1
	b .L08152B1A
.L08152B18:
	movs r0, #0
.L08152B1A:
	str r0, [sp, #0x18]
	subs r0, r3, #1
	adds r0, r4, r0
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne .L08152B30
	movs r0, #1
	b .L08152B32
.L08152B30:
	movs r0, #0
.L08152B32:
	str r0, [sp, #0x1c]
	ldr r5, [sp, #4]
	lsls r0, r5, #4
	ldr r1, [sp]
	adds r1, r1, r0
	ldr r0, [sp, #8]
	lsls r0, r0, #8
	adds r1, r1, r0
	ldr r4, [sp, #0xc]
	lsls r0, r4, #0xc
	adds r1, r1, r0
	ldr r0, [sp, #0x10]
	lsls r0, r0, #0x10
	adds r1, r1, r0
	ldr r3, [sp, #0x14]
	lsls r0, r3, #0x14
	adds r1, r1, r0
	ldr r0, [sp, #0x18]
	lsls r0, r0, #0x18
	adds r1, r1, r0
	ldr r2, [sp, #0x1c]
	lsls r0, r2, #0x1c
	adds r6, r1, r0
	movs r0, #0x40
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq .L08152B6C
	adds r7, #1
.L08152B6C:
	movs r0, #0x80
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq .L08152B78
	adds r7, #2
.L08152B78:
	movs r0, #0x20
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq .L08152B84
	adds r7, #4
.L08152B84:
	movs r0, #0x10
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq .L08152B90
	adds r7, #8
.L08152B90:
	subs r0, r7, #1
	cmp r0, #9
	bls .L08152B98
	b .L08152E74
.L08152B98:
	lsls r0, r0, #2
	ldr r1, .L08152BA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L08152BA4: .4byte gUnknown_08152BA8
	.global gUnknown_08152BA8
gUnknown_08152BA8:
.L08152BA8: @ jump table
	.4byte .L08152BD0
	.4byte .L08152C50
	.4byte .L08152E74
	.4byte .L08152CC8
	.4byte .L08152DB0
	.4byte .L08152E0C
	.4byte .L08152E74
	.4byte .L08152D3C
	.4byte .L08152DDC
	.4byte .L08152E44
.L08152BD0:
	ldr r1, .L08152BEC
	ands r1, r6
	ldr r0, .L08152BF0
	cmp r1, r0
	beq .L08152C14
	cmp r1, r0
	bhi .L08152BF4
	cmp r1, #0x11
	beq .L08152C28
	movs r0, #0x88
	lsls r0, r0, #1
	cmp r1, r0
	beq .L08152C14
	b .L08152C3C
.L08152BEC: .4byte 0xF000FFFF
.L08152BF0: .4byte 0x00001010
.L08152BF4:
	ldr r0, .L08152C0C
	cmp r1, r0
	beq .L08152C14
	cmp r1, r0
	blo .L08152C3C
	ldr r0, .L08152C10
	cmp r1, r0
	bhi .L08152C3C
	subs r0, #1
	cmp r1, r0
	blo .L08152C3C
	b .L08152C28
.L08152C0C: .4byte 0x00001110
.L08152C10: .4byte 0x10000011
.L08152C14:
	ldr r0, .L08152C24
	ldrh r1, [r0, #0x14]
	subs r1, #0x10
	strh r1, [r0, #0x14]
	ldrh r1, [r0, #0x16]
	subs r1, #0x10
	b .L08152E36
	.byte 0x00, 0x00
.L08152C24: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152C28:
	ldr r0, .L08152C38
	ldrh r1, [r0, #0x14]
	adds r1, #0x10
	strh r1, [r0, #0x14]
	ldrh r1, [r0, #0x16]
	subs r1, #0x10
	b .L08152E6E
	.byte 0x00, 0x00
.L08152C38: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152C3C:
	cmp r5, #0
	beq .L08152C42
	b .L08152E74
.L08152C42:
	ldr r1, .L08152C4C
	ldrh r0, [r1, #0x16]
	subs r0, #0x10
	strh r0, [r1, #0x16]
	b .L08152E38
.L08152C4C: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152C50:
	ldr r1, .L08152C70
	ands r1, r6
	ldr r0, .L08152C74
	cmp r1, r0
	beq .L08152C9C
	cmp r1, r0
	bhi .L08152C7C
	ldr r0, .L08152C78
	cmp r1, r0
	beq .L08152C9C
	movs r0, #0x88
	lsls r0, r0, #0xd
	cmp r1, r0
	beq .L08152C9C
	b .L08152CB4
	.byte 0x00, 0x00
.L08152C70: .4byte 0xFFFFF000
.L08152C74: .4byte 0x00111000
.L08152C78: .4byte 0x00101000
.L08152C7C:
	ldr r0, .L08152C8C
	cmp r1, r0
	beq .L08152CA8
	cmp r1, r0
	bhi .L08152C90
	movs r0, #0x88
	lsls r0, r0, #0x11
	b .L08152C92
.L08152C8C: .4byte 0x10100000
.L08152C90:
	ldr r0, .L08152C98
.L08152C92:
	cmp r1, r0
	beq .L08152CA8
	b .L08152CB4
.L08152C98: .4byte 0x11100000
.L08152C9C:
	ldr r0, .L08152CA4
	ldrh r1, [r0, #0x14]
	subs r1, #0x10
	b .L08152E68
.L08152CA4: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152CA8:
	ldr r0, .L08152CB0
	ldrh r1, [r0, #0x14]
	adds r1, #0x10
	b .L08152E30
.L08152CB0: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152CB4:
	cmp r3, #0
	beq .L08152CBA
	b .L08152E74
.L08152CBA:
	ldr r1, .L08152CC4
	ldrh r0, [r1, #0x16]
	adds r0, #0x10
	strh r0, [r1, #0x16]
	b .L08152E70
.L08152CC4: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152CC8:
	ldr r1, .L08152CE0
	ands r1, r6
	ldr r0, .L08152CE4
	cmp r1, r0
	bhi .L08152CE8
	subs r0, #1
	cmp r1, r0
	bhs .L08152D1C
	subs r0, #0xf
	cmp r1, r0
	beq .L08152D1C
	b .L08152D28
.L08152CE0: .4byte 0xFFF000FF
.L08152CE4: .4byte 0x10000011
.L08152CE8:
	movs r0, #0x88
	lsls r0, r0, #0x15
	cmp r1, r0
	beq .L08152D06
	cmp r1, r0
	bhi .L08152D00
	ldr r0, .L08152CFC
	cmp r1, r0
	beq .L08152D06
	b .L08152D28
.L08152CFC: .4byte 0x10100000
.L08152D00:
	ldr r0, .L08152D14
	cmp r1, r0
	bne .L08152D28
.L08152D06:
	ldr r0, .L08152D18
	ldrh r1, [r0, #0x14]
	subs r1, #0x10
	strh r1, [r0, #0x14]
	ldrh r1, [r0, #0x16]
	subs r1, #0x10
	b .L08152E36
.L08152D14: .4byte 0x11100000
.L08152D18: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152D1C:
	ldr r0, .L08152D24
	ldrh r1, [r0, #0x14]
	subs r1, #0x10
	b .L08152E68
.L08152D24: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152D28:
	cmp r2, #0
	beq .L08152D2E
	b .L08152E74
.L08152D2E:
	ldr r1, .L08152D38
	ldrh r0, [r1, #0x14]
	subs r0, #0x10
	strh r0, [r1, #0x14]
	b .L08152E38
.L08152D38: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152D3C:
	ldr r1, .L08152D60
	ands r1, r6
	ldr r0, .L08152D64
	cmp r1, r0
	bne .L08152D48
	b .L08152E62
.L08152D48:
	cmp r1, r0
	bhi .L08152D6C
	ldr r0, .L08152D68
	cmp r1, r0
	bne .L08152D54
	b .L08152E62
.L08152D54:
	adds r0, #0xf0
	cmp r1, r0
	bne .L08152D5C
	b .L08152E62
.L08152D5C:
	b .L08152D9C
	.byte 0x00, 0x00
.L08152D60: .4byte 0x00FFFFF0
.L08152D64: .4byte 0x00001110
.L08152D68: .4byte 0x00001010
.L08152D6C:
	ldr r0, .L08152D7C
	cmp r1, r0
	beq .L08152D86
	cmp r1, r0
	bhi .L08152D80
	movs r0, #0x88
	lsls r0, r0, #9
	b .L08152D82
.L08152D7C: .4byte 0x00101000
.L08152D80:
	ldr r0, .L08152D94
.L08152D82:
	cmp r1, r0
	bne .L08152D9C
.L08152D86:
	ldr r0, .L08152D98
	ldrh r1, [r0, #0x14]
	adds r1, #0x10
	strh r1, [r0, #0x14]
	ldrh r1, [r0, #0x16]
	subs r1, #0x10
	b .L08152E36
.L08152D94: .4byte 0x00111000
.L08152D98: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152D9C:
	cmp r4, #0
	bne .L08152E74
	ldr r1, .L08152DAC
	ldrh r0, [r1, #0x14]
	adds r0, #0x10
	strh r0, [r1, #0x14]
	b .L08152E70
	.byte 0x00, 0x00
.L08152DAC: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152DB0:
	movs r0, #0xf
	ands r0, r6
	cmp r0, #0
	bne .L08152E74
	movs r0, #0xf0
	lsls r0, r0, #0x18
	ands r0, r6
	cmp r0, #0
	beq .L08152DCA
	movs r0, #0xf0
	ands r6, r0
	cmp r6, #0
	bne .L08152E74
.L08152DCA:
	ldr r0, .L08152DD8
	ldrh r1, [r0, #0x14]
	subs r1, #0x10
	strh r1, [r0, #0x14]
	ldrh r1, [r0, #0x16]
	subs r1, #0x10
	b .L08152E36
.L08152DD8: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152DDC:
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r0, r6
	cmp r0, #0
	bne .L08152E74
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r6
	cmp r0, #0
	beq .L08152DF8
	movs r0, #0xf0
	ands r6, r0
	cmp r6, #0
	bne .L08152E74
.L08152DF8:
	ldr r0, .L08152E08
	ldrh r1, [r0, #0x14]
	adds r1, #0x10
	strh r1, [r0, #0x14]
	ldrh r1, [r0, #0x16]
	subs r1, #0x10
	b .L08152E6E
	.byte 0x00, 0x00
.L08152E08: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152E0C:
	movs r0, #0xf0
	lsls r0, r0, #0x14
	ands r0, r6
	cmp r0, #0
	bne .L08152E74
	movs r0, #0xf0
	lsls r0, r0, #0x18
	ands r0, r6
	cmp r0, #0
	beq .L08152E2A
	movs r0, #0xf0
	lsls r0, r0, #0x10
	ands r6, r0
	cmp r6, #0
	bne .L08152E74
.L08152E2A:
	ldr r0, .L08152E40
	ldrh r1, [r0, #0x14]
	subs r1, #0x10
.L08152E30:
	strh r1, [r0, #0x14]
	ldrh r1, [r0, #0x16]
	adds r1, #0x10
.L08152E36:
	strh r1, [r0, #0x16]
.L08152E38:
	movs r0, #1
	mov r8, r0
	b .L08152E74
	.byte 0x00, 0x00
.L08152E40: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152E44:
	movs r0, #0xf0
	lsls r0, r0, #0xc
	ands r0, r6
	cmp r0, #0
	bne .L08152E74
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r6
	cmp r0, #0
	beq .L08152E62
	movs r0, #0xf0
	lsls r0, r0, #0x10
	ands r6, r0
	cmp r6, #0
	bne .L08152E74
.L08152E62:
	ldr r0, .L08152EB4
	ldrh r1, [r0, #0x14]
	adds r1, #0x10
.L08152E68:
	strh r1, [r0, #0x14]
	ldrh r1, [r0, #0x16]
	adds r1, #0x10
.L08152E6E:
	strh r1, [r0, #0x16]
.L08152E70:
	movs r1, #1
	mov r8, r1
.L08152E74:
	mov r0, r8
	cmp r0, #1
	bne .L08152EE4
	ldr r4, .L08152EB4
	ldrh r0, [r4, #8]
	cmp r0, #2
	bne .L08152EDA
	movs r0, #0x68
	bl Flag_Test
	cmp r0, #0
	beq .L08152EDA
	ldrh r6, [r4, #0x14]
	ldrh r0, [r4, #0x16]
	subs r0, #8
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	add r5, sp, #0x20
	mov r4, sp
	adds r4, #0x22
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_08153C14
	ldrh r0, [r4]
	subs r0, #0x30
	strh r0, [r4]
	ldrh r0, [r5]
	cmp r0, r6
	bls .L08152EB8
	subs r0, r0, r6
	b .L08152EBA
.L08152EB4: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152EB8:
	subs r0, r6, r0
.L08152EBA:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrh r0, [r4]
	cmp r0, r7
	bls .L08152EC8
	subs r0, r0, r7
	b .L08152ECA
.L08152EC8:
	subs r0, r7, r0
.L08152ECA:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r5, #0x17
	bhi .L08152EDA
	cmp r0, #0x27
	bhi .L08152EDA
	movs r0, #0
	b .L08152EE6
.L08152EDA:
	ldr r0, .L08152EF4
	ldrh r1, [r0, #0xc]
	strh r1, [r0, #0x10]
	ldrh r1, [r0, #0xe]
	strh r1, [r0, #0x12]
.L08152EE4:
	mov r0, r8
.L08152EE6:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L08152EF4: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start sub_08152EF8
sub_08152EF8: @ 0x08152EF8
.L08152EF8:
	push {r4, r5, lr}
	ldr r4, .L08152F14
	ldrh r0, [r4, #8]
	bl FieldMap_GetArea
	adds r5, r0, #0
	ldrh r0, [r4, #0xc]
	cmp r0, #0x78
	bls .L08152F18
	subs r0, #0x78
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b .L08152F1A
	.byte 0x00, 0x00
.L08152F14: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152F18:
	movs r3, #0
.L08152F1A:
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	subs r0, #0xf0
	cmp r3, r0
	ble .L08152F2A
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L08152F2A:
	ldr r2, .L08152F48
	ldr r1, .L08152F4C
	movs r0, #0xff
	ands r0, r3
	strh r0, [r1]
	strh r0, [r2]
	ldr r0, .L08152F50
	ldrh r0, [r0, #0xe]
	cmp r0, #0x50
	bls .L08152F54
	subs r0, #0x50
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b .L08152F56
	.byte 0x00, 0x00
.L08152F48: .4byte 0x03000008 @ IWRAM+0x8
.L08152F4C: .4byte 0x0300000C @ IWRAM+0xC
.L08152F50: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152F54:
	movs r3, #0
.L08152F56:
	adds r0, r5, #0
	adds r0, #0xca
	ldrh r0, [r0]
	subs r0, #0xa0
	cmp r3, r0
	ble .L08152F66
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L08152F66:
	ldr r2, .L08152F78
	ldr r1, .L08152F7C
	movs r0, #0xff
	ands r0, r3
	strh r0, [r1]
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08152F78: .4byte 0x0300000A @ IWRAM+0xA
.L08152F7C: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_08152F80
sub_08152F80: @ 0x08152F80
.L08152F80:
	push {r4, r5, lr}
	ldr r4, .L08152FA0
	ldrh r0, [r4, #8]
	bl FieldMap_GetArea
	bl sub_081529E0
	ldr r2, .L08152FA4
	ldrh r1, [r2]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L08152FA8
	movs r0, #0
	b .L08152FCC
.L08152FA0: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08152FA4: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08152FA8:
	ldrh r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L08152FB6
	strh r3, [r4, #6]
	b .L08152FCE
.L08152FB6:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08152FD4
	bl sub_0812A7C4
	cmp r0, #1
	bne .L08152FD4
	movs r0, #2
.L08152FCC:
	strh r0, [r4, #6]
.L08152FCE:
	movs r0, #5
	str r0, [r4]
	b .L08153006
.L08152FD4:
	ldr r5, .L08152FF8
	ldrh r0, [r5]
	bl sub_08152A04
	adds r4, r0, #0
	cmp r4, #1
	bne .L08153006
	ldr r3, .L08152FFC
	movs r2, #2
	str r2, [r3]
	ldrh r1, [r5]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L08153000
	strh r2, [r3, #0x18]
	b .L08153002
	.byte 0x00, 0x00
.L08152FF8: .4byte 0x030031D0 @ IWRAM+0x31D0
.L08152FFC: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153000:
	strh r4, [r3, #0x18]
.L08153002:
	bl sub_0815300C
.L08153006:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0815300C
sub_0815300C: @ 0x0815300C
.L0815300C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl sub_081529E0
	ldr r3, .L08153030
	ldrh r1, [r3, #0xc]
	adds r2, r1, #0
	ldrh r0, [r3, #0x14]
	cmp r2, r0
	bls .L08153034
	ldrh r0, [r3, #0x18]
	subs r0, r1, r0
	b .L0815303C
	.byte 0x00, 0x00
.L08153030: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153034:
	cmp r2, r0
	bhs .L0815303E
	ldrh r0, [r3, #0x18]
	adds r0, r1, r0
.L0815303C:
	strh r0, [r3, #0xc]
.L0815303E:
	ldr r3, .L08153050
	ldrh r1, [r3, #0xe]
	adds r2, r1, #0
	ldrh r0, [r3, #0x16]
	cmp r2, r0
	bls .L08153054
	ldrh r0, [r3, #0x18]
	subs r0, r1, r0
	b .L0815305C
.L08153050: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153054:
	cmp r2, r0
	bhs .L0815305E
	ldrh r0, [r3, #0x18]
	adds r0, r1, r0
.L0815305C:
	strh r0, [r3, #0xe]
.L0815305E:
	bl sub_08152EF8
	movs r0, #0
	movs r1, #0
	movs r2, #2
	bl sub_08152750
	movs r0, #0
	movs r1, #1
	movs r2, #3
	bl sub_08152750
	ldr r1, .L08153094
	ldrh r0, [r1, #8]
	cmp r0, #6
	bne .L08153098
	ldrh r0, [r1, #0xc]
	lsrs r0, r0, #4
	cmp r0, #0x1f
	bne .L08153098
	ldrh r0, [r1, #0xe]
	lsrs r0, r0, #4
	cmp r0, #0x47
	bne .L08153098
	movs r0, #0xc
	str r0, [r1]
	b .L081531C2
.L08153094: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153098:
	ldr r4, .L081530C4
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x14]
	cmp r1, r0
	beq .L081530A4
	b .L081531C2
.L081530A4:
	ldr r0, [r4]
	cmp r0, #0xd
	bne .L081530CE
	ldrh r0, [r4, #0xc]
	lsrs r0, r0, #4
	ldrh r1, [r4, #0xe]
	lsrs r1, r1, #4
	ldrh r2, [r4, #8]
	bl sub_08153458
	cmp r0, #0
	beq .L081530C8
	movs r0, #4
	str r0, [r4]
	b .L081531C2
	.byte 0x00, 0x00
.L081530C4: .4byte 0x030069F0 @ IWRAM+0x69F0
.L081530C8:
	movs r0, #1
	str r0, [r4]
	b .L081531C2
.L081530CE:
	ldrh r0, [r4, #0xc]
	lsrs r0, r0, #4
	mov r8, r0
	ldrh r0, [r4, #0xe]
	lsrs r7, r0, #4
	ldrh r2, [r4, #8]
	mov r0, r8
	adds r1, r7, #0
	bl sub_08153458
	adds r5, r0, #0
	mov r4, sp
	adds r4, #2
	mov r0, sp
	adds r1, r4, #0
	bl sub_080C1B74
	adds r6, r0, #0
	bl sub_0815374C
	mov sb, r0
	mov sl, r4
	cmp r5, #0
	beq .L08153134
	ldr r1, [r5, #4]
	ldr r0, .L0815312C
	cmp r1, r0
	bne .L0815311E
	movs r0, #0x12
	bl Flag_Test
	cmp r0, #0
	bne .L0815311C
	bl sub_080C2244
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L0815311E
.L0815311C:
	movs r5, #0
.L0815311E:
	cmp r5, #0
	beq .L08153134
	ldr r1, .L08153130
	movs r0, #4
	str r0, [r1]
	b .L081531C2
	.byte 0x00, 0x00
.L0815312C: .4byte gUnknown_0803AE54
.L08153130: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153134:
	bl sub_081537C4
	cmp r0, #1
	bne .L08153148
	ldr r1, .L08153144
	movs r0, #9
	str r0, [r1]
	b .L081531C2
.L08153144: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153148:
	ldr r0, .L08153168
	ldrh r1, [r0, #8]
	adds r5, r0, #0
	cmp r1, #6
	bne .L0815316C
	ldrh r0, [r5, #0xc]
	lsrs r0, r0, #4
	cmp r0, #0x1f
	bne .L0815316C
	ldrh r0, [r5, #0xe]
	lsrs r0, r0, #4
	cmp r0, #0x47
	bne .L0815316C
	movs r0, #0xc
	b .L081531C0
	.byte 0x00, 0x00
.L08153168: .4byte 0x030069F0 @ IWRAM+0x69F0
.L0815316C:
	adds r4, r5, #0
	ldrh r2, [r4, #8]
	mov r0, r8
	adds r1, r7, #0
	bl sub_081533DC
	cmp r0, #0
	beq .L08153182
	movs r0, #3
	str r0, [r4]
	b .L081531C2
.L08153182:
	cmp r6, #0
	beq .L0815319A
	str r6, [r4, #0x2c]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4, #0x30]
	mov r1, sl
	ldrh r0, [r1]
	strh r0, [r4, #0x32]
	movs r0, #7
	str r0, [r4]
	b .L081531C2
.L0815319A:
	mov r0, sb
	cmp r0, #0
	beq .L081531A6
	movs r0, #8
	str r0, [r4]
	b .L081531C2
.L081531A6:
	movs r0, #1
	bl sub_080C2280
	cmp r0, #1
	bne .L081531B6
	movs r0, #6
	str r0, [r4]
	b .L081531C2
.L081531B6:
	bl sub_080C2168
	bl sub_080C1DE0
	movs r0, #1
.L081531C0:
	str r0, [r5]
.L081531C2:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081531D4
sub_081531D4: @ 0x081531D4
.L081531D4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0
	mov r8, r0
	ldr r1, .L0815324C
	ldr r2, .L08153250
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r7, #0x7f
	ands r7, r0
	ldr r0, .L08153254
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r5, #0x3f
	ands r5, r0
.L081531F4:
	mov r0, r8
	bl sub_080C8B3C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r4, #0
	cmp r4, r6
	bhs .L0815323E
.L08153204:
	mov r0, r8
	adds r1, r4, #0
	bl DungeonMap_GetFloor
	adds r1, r0, #0
	ldrh r0, [r1, #8]
	cmp r0, r7
	bhi .L08153234
	ldrh r0, [r1, #0xa]
	cmp r0, r5
	bhi .L08153234
	ldrh r0, [r1, #0xc]
	cmp r0, r7
	blo .L08153234
	ldrh r0, [r1, #0xe]
	cmp r0, r5
	blo .L08153234
	adds r0, r1, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl SubMap_IsOutsideExclusions
	cmp r0, #1
	beq .L08153258
.L08153234:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r6
	blo .L08153204
.L0815323E:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	b .L081531F4
	.byte 0x00, 0x00
.L0815324C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08153250: .4byte 0x000018C2
.L08153254: .4byte 0x000018C3
.L08153258:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_08153264
sub_08153264: @ 0x08153264
	push {r4, lr}
	ldr r2, .L081532A8
	ldrh r0, [r2, #0xc]
	lsrs r0, r0, #4
	ldrh r1, [r2, #0xe]
	lsrs r1, r1, #4
	ldrh r2, [r2, #8]
	bl sub_081533DC
	ldr r2, .L081532AC
	movs r1, #0xc6
	lsls r1, r1, #5
	adds r2, r2, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	bl sub_08153668
	adds r4, r0, #0
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	bl sub_081531D4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_080C2D78
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081532A8: .4byte 0x030069F0 @ IWRAM+0x69F0
.L081532AC: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_081532B0
sub_081532B0: @ 0x081532B0
	push {r4, lr}
	ldr r2, .L081532D8
	ldrh r0, [r2, #0xc]
	lsrs r0, r0, #4
	ldrh r1, [r2, #0xe]
	lsrs r1, r1, #4
	ldrh r2, [r2, #8]
	bl sub_08153458
	adds r4, r0, #0
	bl sub_08153668
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	bl sub_080C2DE0
	pop {r4}
	pop {r0}
	bx r0
.L081532D8: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start sub_081532DC
sub_081532DC: @ 0x081532DC
	push {lr}
	bl sub_08153668
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L081532F0
	bl sub_080C2DE0
	pop {r0}
	bx r0
.L081532F0: .4byte gUnknown_0804AE3C

	thumb_func_start sub_081532F4
sub_081532F4: @ 0x081532F4
	push {lr}
	bl sub_08153668
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L0815330C
	ldrh r1, [r1, #6]
	bl sub_080C2E10
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815330C: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start sub_08153310
sub_08153310: @ 0x08153310
	push {lr}
	bl sub_08153668
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C2DC0
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08153324
sub_08153324: @ 0x08153324
	push {lr}
	sub sp, #4
	ldr r0, .L08153358
	ldrh r0, [r0, #8]
	bl FieldMap_GetArea
	adds r0, #0xa4
	ldr r1, [r0]
	ldr r2, .L0815335C
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #1
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08153358: .4byte 0x030069F0 @ IWRAM+0x69F0
.L0815335C: .4byte 0x03002AB0 @ IWRAM+0x2AB0

	thumb_func_start sub_08153360
sub_08153360: @ 0x08153360
	push {lr}
	bl sub_08153668
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L08153374
	bl sub_080C2E44
	pop {r0}
	bx r0
.L08153374: .4byte gUnknown_081988DC

	thumb_func_start sub_08153378
sub_08153378: @ 0x08153378
.L08153378:
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	lsls r4, r4, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsrs r4, r4, #0xb
	ldr r0, .L081533A4
	adds r4, r4, r0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r5, #0
	adds r2, r4, #0
	bl Palette_CopyWithEffect
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L081533A4: .4byte 0x030029B0 @ IWRAM+0x29B0

	thumb_func_start sub_081533A8
sub_081533A8: @ 0x081533A8
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	lsls r4, r4, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsrs r4, r4, #0xb
	ldr r0, .L081533D8
	adds r4, r4, r0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r5, #0
	adds r2, r4, #0
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L081533D8: .4byte 0x03002DB0 @ IWRAM+0x2DB0

	thumb_func_start sub_081533DC
sub_081533DC: @ 0x081533DC
.L081533DC:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, .L081533F8
.L081533EC:
	ldrb r0, [r3]
	cmp r0, #0xff
	bne .L081533FC
	movs r0, #0
	b .L08153416
	.byte 0x00, 0x00
.L081533F8: .4byte gUnknown_087DF344
.L081533FC:
	ldrb r0, [r3, #6]
	cmp r0, r2
	bne .L08153412
	ldrb r0, [r3]
	cmp r0, r4
	bne .L08153412
	ldrb r0, [r3, #1]
	cmp r0, r1
	bne .L08153412
	adds r0, r3, #0
	b .L08153416
.L08153412:
	adds r3, #8
	b .L081533EC
.L08153416:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_0815341C
sub_0815341C: @ 0x0815341C
.L0815341C:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	ldr r2, .L08153434
.L08153428:
	ldrb r0, [r2, #2]
	cmp r0, #0xff
	bne .L08153438
	movs r0, #0
	b .L08153450
	.byte 0x00, 0x00
.L08153434: .4byte gUnknown_087DF344
.L08153438:
	ldrb r0, [r2, #2]
	cmp r0, r4
	bne .L0815344C
	ldrb r1, [r2, #3]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, r3
	bne .L0815344C
	adds r0, r2, #0
	b .L08153450
.L0815344C:
	adds r2, #8
	b .L08153428
.L08153450:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08153458
sub_08153458: @ 0x08153458
.L08153458:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r4, .L08153504
	ldr r0, .L08153508
	ldrh r0, [r0, #8]
	bl FieldMap_GetArea
	adds r1, r0, #0
	adds r1, #0xcc
	ldrh r1, [r1]
	adds r1, r6, r1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	adds r0, #0xce
	ldrh r0, [r0]
	adds r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L08153486:
	ldrb r1, [r4]
	adds r0, r1, #0
	cmp r0, #0xff
	beq .L081534FE
	ldrb r0, [r4, #2]
	cmp r0, r7
	bne .L08153534
	movs r0, #0x7f
	ands r0, r1
	cmp r0, r6
	bne .L08153534
	ldrb r0, [r4, #1]
	cmp r0, r5
	bne .L08153534
	ldr r0, .L08153508
	ldrh r0, [r0, #0x1c]
	ldrb r1, [r4, #3]
	cmp r0, r1
	bne .L08153534
	ldr r0, [r4, #4]
	bl ScriptVM_RunAlt
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08153534
	movs r0, #0x69
	bl Flag_Test
	cmp r0, #0
	beq .L08153530
	ldr r0, .L0815350C
	bl Flag_Test
	cmp r0, #0
	beq .L08153530
	ldr r1, [r4, #4]
	ldr r0, .L08153510
	cmp r1, r0
	beq .L081534FE
	ldr r0, .L08153514
	cmp r1, r0
	beq .L081534FE
	ldr r0, .L08153518
	cmp r1, r0
	beq .L081534FE
	ldr r0, .L0815351C
	cmp r1, r0
	beq .L081534FE
	ldr r0, .L08153520
	cmp r1, r0
	beq .L081534FE
	ldr r0, .L08153524
	cmp r1, r0
	beq .L081534FE
	ldr r0, .L08153528
	cmp r1, r0
	beq .L081534FE
	ldr r0, .L0815352C
	cmp r1, r0
	bne .L08153530
.L081534FE:
	movs r0, #0
	b .L08153538
	.byte 0x00, 0x00
.L08153504: .4byte gUnknown_087DF54C
.L08153508: .4byte 0x030069F0 @ IWRAM+0x69F0
.L0815350C: .4byte 0x00000109
.L08153510: .4byte gUnknown_080560B6
.L08153514: .4byte gUnknown_08056154
.L08153518: .4byte gUnknown_080561F2
.L0815351C: .4byte gUnknown_08056290
.L08153520: .4byte gUnknown_0805632E
.L08153524: .4byte gUnknown_080563CC
.L08153528: .4byte gUnknown_0805646A
.L0815352C: .4byte gUnknown_08056508
.L08153530:
	adds r0, r4, #0
	b .L08153538
.L08153534:
	adds r4, #8
	b .L08153486
.L08153538:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08153540
sub_08153540: @ 0x08153540
.L08153540:
	push {r4, lr}
	ldr r1, .L08153558
	ldrh r4, [r1, #0xc]
	ldrh r2, [r1, #0xe]
	ldrh r3, [r1, #0x10]
	ldrh r1, [r1, #0x12]
	cmp r4, r3
	bne .L0815355C
	cmp r2, r1
	bhs .L0815355C
	movs r0, #0
	b .L0815359E
.L08153558: .4byte 0x030069F0 @ IWRAM+0x69F0
.L0815355C:
	cmp r4, r3
	bls .L08153578
	cmp r2, r1
	bhs .L08153568
	movs r0, #1
	b .L0815359E
.L08153568:
	cmp r2, r1
	bne .L08153570
	movs r0, #2
	b .L0815359E
.L08153570:
	cmp r2, r1
	bls .L08153578
	movs r0, #3
	b .L0815359E
.L08153578:
	cmp r4, r3
	bne .L08153584
	cmp r2, r1
	bls .L08153584
	movs r0, #4
	b .L0815359E
.L08153584:
	cmp r4, r3
	bhs .L0815359E
	cmp r2, r1
	bls .L08153590
	movs r0, #5
	b .L0815359E
.L08153590:
	cmp r2, r1
	bne .L08153598
	movs r0, #6
	b .L0815359E
.L08153598:
	cmp r2, r1
	bhs .L0815359E
	movs r0, #7
.L0815359E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_081535A4
sub_081535A4: @ 0x081535A4
.L081535A4:
	push {r4, r5, lr}
	sub sp, #8
	bl sub_081529E0
	ldr r1, .L08153664
	ldrh r4, [r1, #0xc]
	lsrs r4, r4, #4
	ldrh r3, [r1, #0xe]
	lsrs r3, r3, #4
	mov r5, sp
	subs r2, r3, #1
	lsls r2, r2, #6
	subs r1, r2, #1
	adds r1, r4, r1
	adds r1, r0, r1
	ldrb r1, [r1]
	lsrs r1, r1, #4
	strb r1, [r5]
	adds r1, r4, r2
	adds r1, r0, r1
	ldrb r1, [r1]
	lsrs r1, r1, #4
	strb r1, [r5, #1]
	adds r2, #1
	adds r2, r4, r2
	adds r2, r0, r2
	ldrb r1, [r2]
	lsrs r1, r1, #4
	strb r1, [r5, #2]
	mov r2, sp
	lsls r5, r3, #6
	adds r1, r5, #1
	adds r1, r4, r1
	adds r1, r0, r1
	ldrb r1, [r1]
	lsrs r1, r1, #4
	strb r1, [r2, #3]
	adds r3, #1
	lsls r3, r3, #6
	adds r1, r3, #1
	adds r1, r4, r1
	adds r1, r0, r1
	ldrb r1, [r1]
	lsrs r1, r1, #4
	strb r1, [r2, #4]
	adds r1, r4, r3
	adds r1, r0, r1
	ldrb r1, [r1]
	lsrs r1, r1, #4
	strb r1, [r2, #5]
	subs r3, #1
	adds r3, r4, r3
	adds r3, r0, r3
	ldrb r1, [r3]
	lsrs r1, r1, #4
	strb r1, [r2, #6]
	mov r1, sp
	subs r5, #1
	adds r4, r4, r5
	adds r0, r0, r4
	ldrb r0, [r0]
	lsrs r0, r0, #4
	strb r0, [r1, #7]
	mov r0, sp
	ldrb r0, [r0, #1]
	lsls r0, r0, #4
	ldrb r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #8
	adds r0, r0, r1
	mov r1, sp
	ldrb r1, [r1, #3]
	lsls r1, r1, #0xc
	adds r0, r0, r1
	mov r1, sp
	ldrb r1, [r1, #4]
	lsls r1, r1, #0x10
	adds r0, r0, r1
	mov r1, sp
	ldrb r1, [r1, #5]
	lsls r1, r1, #0x14
	adds r0, r0, r1
	mov r1, sp
	ldrb r1, [r1, #6]
	lsls r1, r1, #0x18
	adds r0, r0, r1
	mov r1, sp
	ldrb r1, [r1, #7]
	lsls r1, r1, #0x1c
	adds r0, r0, r1
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
.L08153664: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start sub_08153668
sub_08153668: @ 0x08153668
.L08153668:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, .L08153698
	ldrh r0, [r0, #8]
	bl FieldMap_GetArea
	adds r4, r0, #0
	bl sub_081535A4
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0xd0
	bl sub_08153540
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi .L081536EE
	lsls r0, r0, #2
	ldr r1, .L0815369C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08153698: .4byte 0x030069F0 @ IWRAM+0x69F0
.L0815369C: .4byte gUnknown_081536A0
	.global gUnknown_081536A0
gUnknown_081536A0:
.L081536A0: @ jump table
	.4byte .L081536C0
	.4byte .L081536C6
	.4byte .L081536CC
	.4byte .L081536D2
	.4byte .L081536D8
	.4byte .L081536DE
	.4byte .L081536E4
	.4byte .L081536EA
.L081536C0:
	movs r6, #0
	movs r5, #8
	b .L081536EE
.L081536C6:
	movs r6, #4
	movs r5, #0xc
	b .L081536EE
.L081536CC:
	movs r6, #8
	movs r5, #0x10
	b .L081536EE
.L081536D2:
	movs r6, #0xc
	movs r5, #0x14
	b .L081536EE
.L081536D8:
	movs r6, #0x10
	movs r5, #0x18
	b .L081536EE
.L081536DE:
	movs r6, #0x14
	movs r5, #0x1c
	b .L081536EE
.L081536E4:
	movs r6, #0x18
	movs r5, #0
	b .L081536EE
.L081536EA:
	movs r6, #0x1c
	movs r5, #4
.L081536EE:
	mov r1, r8
	lsrs r1, r6
	movs r0, #0xf
	ands r1, r0
	mov r4, r8
	lsrs r4, r5
	ands r4, r0
	cmp r1, #0
	bne .L08153704
	ldrb r1, [r7]
	b .L0815370A
.L08153704:
	adds r0, r1, r7
	subs r0, #1
	ldrb r1, [r0]
.L0815370A:
	cmp r4, #0
	bne .L08153718
	ldrb r4, [r7]
	b .L0815371E
.L08153712:
	ldrb r0, [r5, #2]
	adds r0, #0xe0
	b .L0815373C
.L08153718:
	adds r0, r4, r7
	subs r0, #1
	ldrb r4, [r0]
.L0815371E:
	movs r3, #0
	ldr r2, .L08153748
	adds r5, r2, #0
.L08153724:
	ldrb r0, [r2]
	cmp r0, r1
	bne .L08153730
	ldrb r0, [r2, #1]
	cmp r0, r4
	beq .L08153712
.L08153730:
	adds r2, #4
	adds r5, #4
	adds r3, #1
	cmp r3, #0xab
	bls .L08153724
	movs r0, #0
.L0815373C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08153748: .4byte gUnknown_087E0188

	thumb_func_start sub_0815374C
sub_0815374C: @ 0x0815374C
.L0815374C:
	push {r4, r5, r6, r7, lr}
	ldr r4, .L081537AC
	ldrh r0, [r4, #8]
	bl FieldMap_GetArea
	ldrh r1, [r4, #0xc]
	adds r2, r0, #0
	adds r2, #0xcc
	lsrs r1, r1, #4
	ldrh r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	ldrh r1, [r4, #0xe]
	adds r0, #0xce
	lsrs r1, r1, #4
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r0, #2
	bl Flag_Test
	cmp r0, #0
	beq .L081537BC
	movs r0, #0x16
	bl Flag_Test
	cmp r0, #0
	beq .L081537BC
	movs r5, #0
	ldr r4, .L081537B0
.L0815378C:
	ldrh r0, [r4]
	cmp r7, r0
	bne .L081537B4
	ldrh r0, [r4, #2]
	cmp r6, r0
	bne .L081537B4
	bl sub_080C2244
	movs r1, #5
	bl __umodsi3
	cmp r0, #0
	bne .L081537B4
	movs r0, #1
	b .L081537BE
	.byte 0x00, 0x00
.L081537AC: .4byte 0x030069F0 @ IWRAM+0x69F0
.L081537B0: .4byte gUnknown_087E043C
.L081537B4:
	adds r4, #4
	adds r5, #1
	cmp r5, #0x19
	bls .L0815378C
.L081537BC:
	movs r0, #0
.L081537BE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_081537C4
sub_081537C4: @ 0x081537C4
.L081537C4:
	push {lr}
	movs r0, #0x69
	bl Flag_Test
	cmp r0, #0
	beq .L08153808
	ldr r0, .L081537E8
	bl Flag_Test
	cmp r0, #0
	beq .L08153808
	ldr r1, .L081537EC
	ldrh r0, [r1, #8]
	cmp r0, #5
	bne .L081537F4
	ldr r1, [r1, #0xc]
	ldr r0, .L081537F0
	b .L081537FC
.L081537E8: .4byte 0x00000109
.L081537EC: .4byte 0x030069F0 @ IWRAM+0x69F0
.L081537F0: .4byte 0x037001C8
.L081537F4:
	cmp r0, #6
	bne .L08153808
	ldr r1, [r1, #0xc]
	ldr r0, .L08153804
.L081537FC:
	cmp r1, r0
	bne .L08153808
	movs r0, #1
	b .L0815380A
.L08153804: .4byte 0x07800238
.L08153808:
	movs r0, #0
.L0815380A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08153810
sub_08153810: @ 0x08153810
.L08153810:
	ldr r1, .L08153824
	ldr r0, .L08153828
	str r0, [r1]
	ldr r0, .L0815382C
	str r0, [r1, #4]
	ldr r0, .L08153830
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L08153824: .4byte 0x040000D4 @ REG_DMA3SAD
.L08153828: .4byte 0x02000000 @ EWRAM
.L0815382C: .4byte 0x06001000 @ VRAM+0x1000
.L08153830: .4byte 0x84000200

	thumb_func_start sub_08153834
sub_08153834: @ 0x08153834
	push {lr}
	ldr r1, .L08153850
	ldr r0, .L08153854
	str r0, [r1]
	ldr r0, .L08153858
	str r0, [r1, #4]
	ldr r0, .L0815385C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_08153810
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08153850: .4byte 0x040000D4 @ REG_DMA3SAD
.L08153854: .4byte 0x02001000 @ EWRAM+0x1000
.L08153858: .4byte 0x0600E000 @ VRAM+0xE000
.L0815385C: .4byte 0x84000200

	thumb_func_start sub_08153860
sub_08153860: @ 0x08153860
	sub sp, #4
	mov r1, sp
	ldr r2, .L08153880
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L08153884
	mov r0, sp
	str r0, [r1]
	ldr r0, .L08153888
	str r0, [r1, #4]
	ldr r0, .L0815388C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	bx lr
	.byte 0x00, 0x00
.L08153880: .4byte 0x000003B3
.L08153884: .4byte 0x040000D4 @ REG_DMA3SAD
.L08153888: .4byte 0x06001000 @ VRAM+0x1000
.L0815388C: .4byte 0x81000400

	thumb_func_start sub_08153890
sub_08153890: @ 0x08153890
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r0, .L08153910
	ldr r1, .L08153914
	bl LZ77UnCompWram
	ldr r0, .L08153918
	ldr r5, .L0815391C
	adds r1, r5, #0
	bl LZ77UnCompWram
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0
	str r0, [sp]
	movs r4, #0x20
	str r4, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r2, #7
	movs r3, #0
	bl Tilemap_OffsetRect
	ldr r1, .L08153920
	ldr r2, .L08153924
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0x70
	movs r1, #0x10
	movs r2, #4
	bl PalFade_FadeRangeInFromBlack
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #4
	movs r3, #8
	bl PalFade_FadeRangeToBlackWithDuration
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #4
	movs r3, #8
	bl PalFade_FadeRangeToBlackWithDuration
	ldr r1, .L08153928
	ldr r2, .L0815392C
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L08153930
	adds r2, #0x24
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L08153934
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L08153910: .4byte gUnknown_087E04A4
.L08153914: .4byte 0x02001000 @ EWRAM+0x1000
.L08153918: .4byte gUnknown_087E0788
.L0815391C: .4byte 0x02000000 @ EWRAM
.L08153920: .4byte gUnknown_087E0978
.L08153924: .4byte 0x03002A90 @ IWRAM+0x2A90
.L08153928: .4byte 0x03000004 @ IWRAM+0x4
.L0815392C: .4byte 0x0000FFCC
.L08153930: .4byte 0x03000006 @ IWRAM+0x6
.L08153934: .4byte sub_08153834

	thumb_func_start sub_08153938
sub_08153938: @ 0x08153938
	sub sp, #4
	mov r0, sp
	movs r3, #0
	strh r3, [r0]
	ldr r0, .L08153964
	mov r1, sp
	str r1, [r0]
	ldr r1, .L08153968
	str r1, [r0, #4]
	ldr r2, .L0815396C
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, sp
	strh r3, [r1]
	str r1, [r0]
	ldr r1, .L08153970
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	add sp, #4
	bx lr
	.byte 0x00, 0x00
.L08153964: .4byte 0x040000D4 @ REG_DMA3SAD
.L08153968: .4byte 0x06002000 @ VRAM+0x2000
.L0815396C: .4byte 0x81000800
.L08153970: .4byte 0x06003000 @ VRAM+0x3000

	thumb_func_start sub_08153974
sub_08153974: @ 0x08153974
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0815398C
	bl Flag_Test
	cmp r0, #0
	beq .L08153984
	movs r0, #1
.L08153984:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
.L0815398C: .4byte 0x00000109

	thumb_func_start sub_08153990
sub_08153990: @ 0x08153990
	push {r4, lr}
	cmp r1, #4
	bls .L08153998
	b .L08153A8A
.L08153998:
	lsls r0, r1, #2
	ldr r1, .L081539A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L081539A4: .4byte gUnknown_081539A8
	.global gUnknown_081539A8
gUnknown_081539A8:
.L081539A8: @ jump table
	.4byte .L081539BC
	.4byte .L081539C8
	.4byte .L081539E8
	.4byte .L08153A06
	.4byte .L08153A70
.L081539BC:
	movs r0, #0x70
	movs r1, #0x10
	movs r2, #4
	bl PalFade_FadeRangeToBlack
	b .L08153A8A
.L081539C8:
	ldr r0, .L081539DC
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L081539E0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L081539E4
	strh r1, [r0]
	b .L08153A8A
.L081539DC: .4byte sub_08153860
.L081539E0: .4byte 0x03000004 @ IWRAM+0x4
.L081539E4: .4byte 0x03000006 @ IWRAM+0x6
.L081539E8:
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #4
	bl PalFade_FadeRangeToBlack
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #4
	bl PalFade_FadeRangeToBlack
	movs r0, #2
	bl sub_080C51BC
	b .L08153A8A
.L08153A06:
	ldr r4, .L08153A38
	ldrh r0, [r4, #8]
	cmp r0, #5
	bne .L08153A3C
	movs r0, #6
	strh r0, [r4, #8]
	movs r0, #0x8e
	lsls r0, r0, #2
	strh r0, [r4, #0x10]
	strh r0, [r4, #0xc]
	movs r0, #0xf2
	lsls r0, r0, #3
	strh r0, [r4, #0x12]
	strh r0, [r4, #0xe]
	bl sub_08152EF8
	ldrh r0, [r4, #8]
	bl sub_080AD67C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C5170
	b .L08153A62
	.byte 0x00, 0x00
.L08153A38: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153A3C:
	movs r0, #5
	strh r0, [r4, #8]
	movs r0, #0xe4
	lsls r0, r0, #1
	strh r0, [r4, #0x10]
	strh r0, [r4, #0xc]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r4, #0x12]
	strh r0, [r4, #0xe]
	bl sub_08152EF8
	ldrh r0, [r4, #8]
	bl sub_080AD67C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C5170
.L08153A62:
	ldr r0, .L08153A6C
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L08153A8A
.L08153A6C: .4byte sub_08153938
.L08153A70:
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #4
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #4
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
.L08153A8A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_08153A90
sub_08153A90: @ 0x08153A90
	push {lr}
	sub sp, #0x14
	cmp r1, #0
	bne .L08153AB0
	ldr r0, .L08153AA8
	movs r1, #1
	strh r1, [r0, #0x34]
	ldr r0, .L08153AAC
	bl VBlankTask_AddCounted
	b .L08153AEA
	.byte 0x00, 0x00
.L08153AA8: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153AAC: .4byte sub_08153860
.L08153AB0:
	ldr r0, .L08153AF0
	movs r3, #0
	strh r3, [r0, #0x34]
	add r1, sp, #0x10
	ldr r2, .L08153AF4
	adds r0, r2, #0
	strh r0, [r1]
	ldr r2, .L08153AF8
	str r1, [r2]
	ldr r1, .L08153AFC
	str r1, [r2, #4]
	ldr r0, .L08153B00
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, .L08153B04
	movs r2, #1
	str r2, [sp]
	str r3, [sp, #4]
	movs r2, #7
	str r2, [sp, #8]
	movs r2, #3
	str r2, [sp, #0xc]
	movs r2, #0
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L08153B08
	movs r1, #1
	bl VBlankTask_AddCounted
.L08153AEA:
	add sp, #0x14
	pop {r0}
	bx r0
.L08153AF0: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153AF4: .4byte 0x000003B3
.L08153AF8: .4byte 0x040000D4 @ REG_DMA3SAD
.L08153AFC: .4byte 0x02000000 @ EWRAM
.L08153B00: .4byte 0x81000800
.L08153B04: .4byte gUnknown_081B8270
.L08153B08: .4byte sub_08153810

	thumb_func_start sub_08153B0C
sub_08153B0C: @ 0x08153B0C
	push {lr}
	ldr r0, .L08153B20
	bl Flag_Set
	ldr r1, .L08153B24
	movs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08153B20: .4byte 0x00000109
.L08153B24: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start sub_08153B28
sub_08153B28: @ 0x08153B28
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	mov r8, r3
	bl sub_081529E0
	movs r0, #0
	mov sb, r0
	mov r0, sb
	strh r0, [r7, #0x1c]
	ldr r6, .L08153B9C
	ldrh r0, [r6, #0xc]
	adds r0, r0, r4
	strh r0, [r6, #0xc]
	ldrh r0, [r6, #0xe]
	adds r0, r0, r5
	strh r0, [r6, #0xe]
	bl sub_08152EF8
	movs r0, #0
	movs r1, #0
	movs r2, #2
	bl sub_08152750
	movs r0, #0
	movs r1, #1
	movs r2, #3
	bl sub_08152750
	ldrh r0, [r6, #0xc]
	lsrs r0, r0, #4
	ldrh r1, [r6, #0xe]
	lsrs r1, r1, #4
	ldrh r2, [r6, #8]
	bl sub_08153458
	cmp r0, #0
	beq .L08153B8E
	ldr r0, [r0, #4]
	cmp r0, r8
	bne .L08153B8E
	movs r0, #4
	str r0, [r6]
	movs r0, #1
	strh r0, [r7, #0x1c]
	mov r0, sb
	strh r0, [r6, #0x36]
.L08153B8E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08153B9C: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start sub_08153BA0
sub_08153BA0: @ 0x08153BA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	bl sub_081529E0
	movs r0, #0
	mov r1, r8
	strh r0, [r1, #0x1c]
	ldr r7, .L08153C10
	ldrh r0, [r7, #0xc]
	adds r0, r0, r4
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #0xe]
	adds r0, r0, r5
	strh r0, [r7, #0xe]
	bl sub_08152EF8
	movs r0, #0
	movs r1, #0
	movs r2, #2
	bl sub_08152750
	movs r0, #0
	movs r1, #1
	movs r2, #3
	bl sub_08152750
	ldrh r0, [r7, #0xc]
	lsrs r3, r0, #4
	cmp r3, r6
	bne .L08153C06
	ldrh r0, [r7, #0xe]
	lsrs r1, r0, #4
	ldr r0, [sp, #0x18]
	cmp r1, r0
	bne .L08153C06
	ldrh r2, [r7, #8]
	adds r0, r3, #0
	bl sub_081533DC
	cmp r0, #0
	beq .L08153C00
	movs r0, #3
	str r0, [r7]
.L08153C00:
	movs r0, #1
	mov r1, r8
	strh r0, [r1, #0x1c]
.L08153C06:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08153C10: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start sub_08153C14
sub_08153C14: @ 0x08153C14
.L08153C14:
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, .L08153C38
	ldrh r0, [r2]
	ldr r3, .L08153C3C
	cmp r0, r3
	beq .L08153C48
.L08153C22:
	cmp r0, #2
	bne .L08153C40
	ldrh r0, [r2, #6]
	cmp r0, #0x68
	bne .L08153C40
	ldrh r0, [r2, #2]
	strh r0, [r4]
	ldrh r0, [r2, #4]
	strh r0, [r1]
	b .L08153C48
	.byte 0x00, 0x00
.L08153C38: .4byte gUnknown_087E0F84
.L08153C3C: .4byte 0x0000FFFF
.L08153C40:
	adds r2, #0x10
	ldrh r0, [r2]
	cmp r0, r3
	bne .L08153C22
.L08153C48:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08153C50
sub_08153C50: @ 0x08153C50
.L08153C50:
	push {r4, r5, lr}
	adds r5, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	ldr r4, .L08153C94
	ldrh r1, [r4, #0xc]
	subs r0, r0, r1
	strh r0, [r2]
	adds r0, #0x20
	lsls r0, r0, #0x10
	movs r1, #0xa6
	lsls r1, r1, #0x11
	cmp r0, r1
	bls .L08153C78
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
	strh r0, [r2]
.L08153C78:
	ldrh r0, [r4, #0xe]
	subs r0, r3, r0
	strh r0, [r5]
	adds r0, #0x20
	lsls r0, r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #0x11
	cmp r0, r1
	bls .L08153C8E
	movs r0, #0xf0
	strh r0, [r5]
.L08153C8E:
	pop {r4, r5}
	pop {r0}
	bx r0
.L08153C94: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start sub_08153C98
sub_08153C98: @ 0x08153C98
.L08153C98:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	ldr r5, .L08153D28
	ldrh r1, [r5]
	ldr r0, .L08153D2C
	cmp r1, r0
	beq .L08153D1A
	ldr r2, .L08153D30
	mov r8, r2
	mov r6, sp
	adds r6, #0xe
	adds r7, r0, #0
.L08153CB4:
	ldr r0, .L08153D34
	ldrh r0, [r0, #8]
	cmp r1, r0
	bne .L08153D12
	ldrh r0, [r5, #6]
	bl Flag_Test
	cmp r0, #0
	beq .L08153D12
	ldr r4, [r5, #8]
	ldr r0, .L08153D38
	cmp r4, r0
	bne .L08153CDE
	ldr r0, .L08153D3C
	ldr r0, [r0]
	lsrs r0, r0, #2
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	add r0, r8
	ldr r4, [r0]
.L08153CDE:
	ldrh r0, [r5, #2]
	adds r0, #0x78
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r5, #4]
	adds r1, #0x50
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r2, sp, #0xc
	adds r3, r6, #0
	bl sub_08153C50
	ldrh r2, [r5, #0xc]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp]
	add r0, sp, #0xc
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldrh r0, [r6]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #4
	movs r3, #2
	bl Sprite_Draw
.L08153D12:
	adds r5, #0x10
	ldrh r1, [r5]
	cmp r1, r7
	bne .L08153CB4
.L08153D1A:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08153D28: .4byte gUnknown_087E0F84
.L08153D2C: .4byte 0x0000FFFF
.L08153D30: .4byte gUnknown_087E0FD4
.L08153D34: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153D38: .4byte gUnknown_0800790C
.L08153D3C: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_08153D40
sub_08153D40: @ 0x08153D40
	ldr r1, .L08153D54
	ldr r0, .L08153D58
	str r0, [r1]
	ldr r0, .L08153D5C
	str r0, [r1, #4]
	ldr r0, .L08153D60
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L08153D54: .4byte 0x040000D4 @ REG_DMA3SAD
.L08153D58: .4byte 0x02034C74 @ EWRAM+0x34C74
.L08153D5C: .4byte 0x06008000 @ VRAM+0x8000
.L08153D60: .4byte 0x84000400

	thumb_func_start sub_08153D64
sub_08153D64: @ 0x08153D64
	ldr r1, .L08153D78
	ldr r0, .L08153D7C
	str r0, [r1]
	ldr r0, .L08153D80
	str r0, [r1, #4]
	ldr r0, .L08153D84
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L08153D78: .4byte 0x040000D4 @ REG_DMA3SAD
.L08153D7C: .4byte 0x0202F874 @ EWRAM+0x2F874
.L08153D80: .4byte 0x06008000 @ VRAM+0x8000
.L08153D84: .4byte 0x84000400

	thumb_func_start sub_08153D88
sub_08153D88: @ 0x08153D88
.L08153D88:
	push {lr}
	ldr r0, .L08153DBC
	ldrh r0, [r0, #8]
	cmp r0, #6
	bne .L08153DD0
	movs r0, #0x65
	bl Flag_Test
	cmp r0, #0
	bne .L08153DD0
	ldr r0, .L08153DC0
	ldr r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne .L08153DD0
	lsrs r0, r1, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L08153DC8
	ldr r0, .L08153DC4
	bl VBlankTask_AddCounted
	b .L08153DD0
	.byte 0x00, 0x00
.L08153DBC: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153DC0: .4byte 0x030031BC @ IWRAM+0x31BC
.L08153DC4: .4byte sub_08153D40
.L08153DC8:
	ldr r0, .L08153DD4
	movs r1, #1
	bl VBlankTask_AddCounted
.L08153DD0:
	pop {r0}
	bx r0
.L08153DD4: .4byte sub_08153D64

	thumb_func_start sub_08153DD8
sub_08153DD8: @ 0x08153DD8
	push {r4, lr}
	ldr r0, .L08153E0C
	ldrh r0, [r0, #8]
	cmp r0, #6
	bne .L08153E04
	ldr r0, .L08153E10
	ldr r4, .L08153E14
	adds r1, r4, #0
	bl HuffUnComp
	ldr r1, .L08153E18
	adds r0, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L08153E1C
	adds r1, r4, #0
	bl HuffUnComp
	ldr r1, .L08153E20
	adds r0, r4, #0
	bl LZ77UnCompWram
.L08153E04:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08153E0C: .4byte 0x030069F0 @ IWRAM+0x69F0
.L08153E10: .4byte gUnknown_087C5E10
.L08153E14: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L08153E18: .4byte 0x02034C74 @ EWRAM+0x34C74
.L08153E1C: .4byte gUnknown_087C6358
.L08153E20: .4byte 0x0202F874 @ EWRAM+0x2F874

	thumb_func_start sub_08153E24
sub_08153E24: @ 0x08153E24
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, .L08153E54
	movs r2, #0
	adds r6, r0, #0
	adds r6, #0x1c
	ldr r1, .L08153E58
	adds r5, r0, r1
	adds r1, #2
	adds r4, r0, r1
.L08153E3A:
	lsls r1, r2, #2
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L08153E5C
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, r3
	bne .L08153E5C
	adds r0, r4, r1
	ldrh r0, [r0]
	b .L08153E68
	.byte 0x00, 0x00
.L08153E54: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08153E58: .4byte 0x0000066C
.L08153E5C:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xb
	bls .L08153E3A
	movs r0, #0
.L08153E68:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08153E70
sub_08153E70: @ 0x08153E70
.L08153E70:
	push {r4, r5, r6, lr}
	movs r6, #0
	movs r5, #0
.L08153E76:
	adds r4, r5, #4
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L08153E8E
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L08153E8E
	adds r6, #1
.L08153E8E:
	adds r5, #1
	cmp r5, #0xb
	ble .L08153E76
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_08153E9C
sub_08153E9C: @ 0x08153E9C
.L08153E9C:
	push {lr}
	ldr r0, .L08153EB4
	movs r1, #0
	movs r2, #0
	adds r0, #0x1c
.L08153EA6:
	stm r0!, {r2}
	adds r1, #1
	cmp r1, #0xb
	bls .L08153EA6
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08153EB4: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08153EB8
sub_08153EB8: @ 0x08153EB8
.L08153EB8:
	push {r4, r5, r6, r7, lr}
	ldr r7, .L08153F00
	movs r6, #0
	movs r5, #0
.L08153EC0:
	adds r4, r5, #4
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L08153EEC
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L08153EEC
	lsls r0, r6, #2
	adds r2, r7, #0
	adds r2, #0x1c
	adds r2, r2, r0
	lsls r0, r5, #7
	ldr r1, .L08153F04
	adds r0, r0, r1
	str r0, [r2]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L08153EEC:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xb
	bls .L08153EC0
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08153F00: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08153F04: .4byte 0x030048C0 @ IWRAM+0x48C0

	thumb_func_start sub_08153F08
sub_08153F08: @ 0x08153F08
	push {r4, r5, lr}
	ldr r4, .L08153F30
	bl sub_08153E9C
	bl sub_08153EB8
	movs r5, #0
	movs r1, #1
	strh r1, [r4, #2]
	ldr r1, .L08153F34
	adds r4, r4, r1
	strh r0, [r4]
	ldrh r0, [r4]
	bl sub_0815B880
	ldr r0, .L08153F38
	str r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08153F30: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08153F34: .4byte 0x0000065E
.L08153F38: .4byte 0x03003BB4 @ IWRAM+0x3BB4

	thumb_func_start sub_08153F3C
sub_08153F3C: @ 0x08153F3C
.L08153F3C:
	push {lr}
	ldr r0, .L08153F68
	movs r2, #0
	movs r1, #0
	adds r3, r0, #0
	adds r3, #0x1c
.L08153F48:
	lsls r0, r1, #2
	adds r0, r3, r0
	ldr r0, [r0]
	cmp r0, #0
	beq .L08153F58
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L08153F58:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bls .L08153F48
	adds r0, r2, #0
	pop {r1}
	bx r1
.L08153F68: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08153F6C
sub_08153F6C: @ 0x08153F6C
.L08153F6C:
	lsls r0, r0, #0x10
	ldr r2, .L08153F88
	ldrh r3, [r2, #8]
	lsls r3, r3, #2
	adds r1, r2, #0
	adds r1, #0x4c
	adds r3, r3, r1
	lsrs r0, r0, #0xe
	adds r2, #0x1c
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r3]
	bx lr
	.byte 0x00, 0x00
.L08153F88: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08153F8C
sub_08153F8C: @ 0x08153F8C
.L08153F8C:
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r5, [sp, #0x20]
	lsls r0, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsrs r0, r0, #0xb
	ldr r4, .L08153FC4
	adds r0, r0, r4
	str r2, [sp]
	str r3, [sp, #4]
	movs r2, #8
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	str r5, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl Canvas_BlitOrTinted
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08153FC4: .4byte gUnknown_087E0FE4

	thumb_func_start sub_08153FC8
sub_08153FC8: @ 0x08153FC8
.L08153FC8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r1
	ldr r1, [sp, #0x2c]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	cmp r4, #0x1b
	bne .L08153FEA
	ldr r4, .L08154034
.L08153FEA:
	cmp r4, #5
	bne .L08153FF8
	movs r4, #0x81
	lsls r4, r4, #1
	adds r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L08153FF8:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Font_GetGlyphBitmap
	adds r1, r6, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	adds r1, r5, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0xe
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	str r7, [sp, #0x10]
	mov r1, r8
	movs r2, #2
	movs r3, #2
	bl Canvas_BlitOrTinted
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08154034: .4byte 0x00000101

	thumb_func_start sub_08154038
sub_08154038: @ 0x08154038
.L08154038:
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r1, .L0815406C
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, .L08154070
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp]
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_08153F8C
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815406C: .4byte gUnknown_087E1BE4
.L08154070: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_08154074
sub_08154074: @ 0x08154074
.L08154074:
	push {lr}
	ldr r1, .L081540B4
	adds r3, r1, #0
	adds r3, #0x90
	movs r0, #0x92
	adds r0, r0, r1
	mov ip, r0
	ldrh r2, [r0]
	ldrh r0, [r3]
	cmp r0, r2
	bls .L08154090
	strh r2, [r3]
	mov r2, ip
	strh r0, [r2]
.L08154090:
	adds r2, r1, #0
	adds r2, #0x94
	ldrh r1, [r2]
	ldrh r0, [r3]
	cmp r0, r1
	bls .L081540A0
	strh r1, [r3]
	strh r0, [r2]
.L081540A0:
	ldrh r1, [r2]
	mov r3, ip
	ldrh r0, [r3]
	cmp r0, r1
	bls .L081540AE
	strh r1, [r3]
	strh r0, [r2]
.L081540AE:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081540B4: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_081540B8
sub_081540B8: @ 0x081540B8
.L081540B8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov sb, r4
	ldr r0, .L08154110
	mov sl, r0
	lsls r0, r4, #2
	mov r1, sl
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r6, [r0]
	movs r1, #0
	str r1, [sp, #4]
	mov r2, sl
	ldrh r0, [r2]
	cmp r0, #2
	bne .L0815411C
	ldr r1, .L08154114
	adds r0, r1, #0
	adds r0, #0x90
	strh r5, [r0]
	ldrh r0, [r6, #0x12]
	adds r2, r1, #0
	adds r2, #0x92
	strh r0, [r2]
	adds r1, #0x94
	ldr r0, .L08154118
	strh r0, [r1]
	bl sub_0815B4B4
	mov r8, r0
	bl sub_08158970
	bl sub_0815B260
	b .L0815421C
	.byte 0x00, 0x00
.L08154110: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08154114: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08154118: .4byte 0x0000FFFF
.L0815411C:
	cmp r0, #3
	bne .L08154154
	ldr r2, .L0815414C
	ldr r0, .L08154150
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x90
	strh r1, [r0]
	adds r0, #2
	strh r5, [r0]
	ldrh r1, [r6, #0x12]
	adds r0, #2
	strh r1, [r0]
	bl sub_08154074
	bl sub_0815B4B4
	mov r8, r0
	bl sub_081596F0
	bl sub_0815B260
	b .L0815421C
	.byte 0x00, 0x00
.L0815414C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08154150: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08154154:
	cmp r0, #1
	bne .L08154194
	adds r0, r5, #0
	bl sub_08154968
	ldr r2, .L08154188
	adds r1, r2, #0
	adds r1, #0x90
	strh r0, [r1]
	adds r1, #2
	ldr r0, .L0815418C
	strh r0, [r1]
	ldr r1, .L08154190
	adds r0, r4, #4
	lsls r0, r0, #7
	adds r0, r0, r1
	ldrh r1, [r0, #0x12]
	adds r0, r2, #0
	adds r0, #0x94
	strh r1, [r0]
	bl sub_0815AE84
	adds r1, r0, #0
.L08154182:
	cmp r1, #0
	bne .L0815420C
	b .L0815423C
.L08154188: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815418C: .4byte 0x0000FFFF
.L08154190: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08154194:
	cmp r0, #4
	bne .L081541D0
	adds r0, r5, #0
	bl sub_08154968
	ldr r4, .L081541C8
	adds r1, r4, #0
	adds r1, #0x90
	strh r0, [r1]
	ldrh r0, [r6, #0x12]
	bl sub_08154968
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r1, #2
	ldr r0, .L081541CC
	strh r0, [r1]
	bl sub_0815AE84
	adds r1, r0, #0
	movs r2, #0x12
	ldrsh r0, [r6, r2]
	cmp r5, r0
	beq .L08154224
	b .L08154182
.L081541C8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081541CC: .4byte 0x0000FFFF
.L081541D0:
	cmp r0, #5
	bne .L0815421C
	ldr r0, .L08154210
	ldrh r0, [r0]
	bl sub_08154968
	ldr r4, .L08154214
	adds r1, r4, #0
	adds r1, #0x90
	strh r0, [r1]
	adds r0, r5, #0
	bl sub_08154968
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	ldr r1, .L08154218
	mov r0, sb
	adds r0, #4
	lsls r0, r0, #7
	adds r0, r0, r1
	ldrh r1, [r0, #0x12]
	adds r0, r4, #0
	adds r0, #0x94
	strh r1, [r0]
	bl sub_0815AE84
	adds r1, r0, #0
	cmp r1, #0
	beq .L0815423C
.L0815420C:
	movs r0, #0x10
	b .L081542FC
.L08154210: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08154214: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08154218: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815421C:
	movs r1, #0x12
	ldrsh r0, [r6, r1]
	cmp r5, r0
	bne .L08154228
.L08154224:
	movs r0, #0x18
	b .L081542FC
.L08154228:
	ldr r1, .L08154240
	adds r2, r1, #0
	adds r2, #0xa6
	ldrb r0, [r2]
	cmp r0, #0x40
	beq .L0815423C
	adds r1, #0xa0
	ldrh r0, [r1]
	cmp r0, #0xff
	bne .L08154244
.L0815423C:
	movs r0, #0x16
	b .L081542FC
.L08154240: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08154244:
	mov r0, r8
	cmp r0, #0
	beq .L0815424E
	movs r0, #0x30
	strb r0, [r2]
.L0815424E:
	ldrh r0, [r1]
	bl sub_0815B958
	movs r1, #0xff
	ands r1, r0
	cmp r1, #1
	beq .L08154272
	cmp r1, #1
	bgt .L08154266
	cmp r1, #0
	beq .L0815426C
	b .L0815427C
.L08154266:
	cmp r1, #2
	beq .L08154278
	b .L0815427C
.L0815426C:
	movs r1, #0
	str r1, [sp]
	b .L0815427C
.L08154272:
	movs r2, #0x10
	str r2, [sp]
	b .L0815427C
.L08154278:
	movs r0, #0x20
	str r0, [sp]
.L0815427C:
	mov r1, sl
	ldrh r0, [r1]
	cmp r0, #2
	bne .L081542B4
	ldr r0, .L0815429C
	adds r0, #0xa6
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #2
	beq .L081542AA
	cmp r1, #2
	bgt .L081542A0
	cmp r1, #1
	beq .L081542A6
	b .L081542B4
.L0815429C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081542A0:
	cmp r1, #3
	beq .L081542AE
	b .L081542B4
.L081542A6:
	movs r7, #4
	b .L081542F4
.L081542AA:
	movs r7, #2
	b .L081542F4
.L081542AE:
	movs r7, #3
	movs r2, #1
	str r2, [sp, #4]
.L081542B4:
	ldr r0, [sp, #4]
	cmp r0, #0
	bne .L081542F4
	ldr r0, .L081542D0
	adds r0, #0xa6
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	beq .L081542DE
	cmp r0, #2
	bgt .L081542D4
	cmp r0, #1
	beq .L081542DA
	b .L081542EC
.L081542D0: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081542D4:
	cmp r0, #3
	beq .L081542E2
	b .L081542EC
.L081542DA:
	movs r7, #1
	b .L081542F4
.L081542DE:
	movs r7, #7
	b .L081542F4
.L081542E2:
	movs r7, #5
	movs r1, #0x10
	str r1, [sp]
	movs r2, #1
	str r2, [sp, #4]
.L081542EC:
	ldr r0, [sp, #4]
	cmp r0, #0
	bne .L081542F4
	movs r7, #0
.L081542F4:
	ldr r1, [sp]
	orrs r7, r1
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
.L081542FC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0815430C
sub_0815430C: @ 0x0815430C
.L0815430C:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, .L08154330
	movs r1, #0
	adds r2, r0, #0
	adds r2, #0x1c
.L0815431A:
	ldr r0, [r2]
	cmp r0, #0
	beq .L08154334
	movs r4, #0x12
	ldrsh r0, [r0, r4]
	cmp r0, r3
	bne .L08154334
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	b .L0815433E
	.byte 0x00, 0x00
.L08154330: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08154334:
	adds r2, #4
	adds r1, #1
	cmp r1, #0xb
	bls .L0815431A
	movs r0, #0
.L0815433E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_08154344
sub_08154344: @ 0x08154344
.L08154344:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r5, #0
.L0815434C:
	adds r4, r5, #4
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L0815437C
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L0815437C
	lsls r0, r5, #7
	ldr r1, .L08154378
	adds r0, r0, r1
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	cmp r0, r6
	bne .L0815437C
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	b .L08154384
	.byte 0x00, 0x00
.L08154378: .4byte 0x030048C0 @ IWRAM+0x48C0
.L0815437C:
	adds r5, #1
	cmp r5, #0xb
	bls .L0815434C
	movs r0, #0
.L08154384:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815438C
sub_0815438C: @ 0x0815438C
.L0815438C:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r4, r3, #0x10
	bl sub_081540B8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xf
	ands r1, r0
	movs r3, #0
	lsrs r0, r0, #4
	cmp r0, #1
	beq .L081543C8
	cmp r0, #1
	bgt .L081543BC
	cmp r0, #0
	beq .L081543C2
	b .L081543C8
.L081543BC:
	cmp r0, #2
	beq .L081543C6
	b .L081543C8
.L081543C2:
	movs r3, #8
	b .L081543C8
.L081543C6:
	movs r3, #0xa
.L081543C8:
	cmp r1, #6
	beq .L081543D4
	cmp r1, #8
	beq .L081543D4
	cmp r1, #5
	bne .L081543D6
.L081543D4:
	movs r3, #0
.L081543D6:
	adds r0, r1, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl sub_08154038
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081543E8
sub_081543E8: @ 0x081543E8
.L081543E8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sb, r2
	movs r7, #0x96
	bl sub_08153F3C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldrh r0, [r4]
	cmp r0, #1
	beq .L0815441A
	cmp r0, #5
	bne .L0815445A
	ldrh r0, [r4, #8]
	cmp r0, #1
	bne .L0815445A
.L0815441A:
	movs r5, #0
	lsls r1, r6, #2
	adds r0, r4, #0
	adds r0, #0x1c
	adds r6, r0, r1
.L08154424:
	adds r4, r5, #4
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L0815444E
	adds r0, r4, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L0815444E
	ldr r0, [r6]
	ldrh r0, [r0, #0x12]
	adds r1, r5, #0
	adds r2, r7, #0
	mov r3, sb
	bl sub_0815438C
	adds r0, r7, #6
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L0815444E:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xb
	bls .L08154424
	b .L0815449C
.L0815445A:
	movs r5, #0
	cmp r5, r8
	bhs .L0815449C
	lsls r0, r6, #2
	adds r6, r4, #0
	adds r6, #0x1c
	adds r0, r0, r6
	mov sl, r0
.L0815446A:
	mov r1, sl
	ldr r0, [r1]
	ldrh r4, [r0, #0x12]
	lsls r0, r5, #2
	adds r0, r6, r0
	ldr r0, [r0]
	ldrh r0, [r0, #0x12]
	bl sub_0815430C
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	adds r2, r7, #0
	mov r3, sb
	bl sub_0815438C
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r7, #6
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r5, r8
	blo .L0815446A
.L0815449C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081544AC
sub_081544AC: @ 0x081544AC
.L081544AC:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	bl sub_08153F3C
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r5, .L081544F8
	ldrh r0, [r5]
	cmp r0, #2
	bne .L081544FC
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne .L081544FC
	movs r4, #0
	cmp r4, r7
	blo .L081544D0
	b .L08154678
.L081544D0:
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_081540B8
	lsls r0, r0, #0x18
	movs r1, #0xf0
	lsls r1, r1, #0x14
	ands r1, r0
	lsrs r1, r1, #0x18
	cmp r1, #6
	beq .L081544EC
	cmp r1, #8
	beq .L081544EC
	b .L08154684
.L081544EC:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r7
	blo .L081544D0
	b .L08154678
.L081544F8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081544FC:
	ldrh r0, [r5]
	adds r1, r0, #0
	cmp r1, #3
	bne .L08154554
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne .L0815454E
	movs r4, #0
	cmp r4, r7
	blo .L08154512
	b .L08154678
.L08154512:
	lsls r1, r4, #2
	adds r0, r5, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, #0x12]
	bl sub_0815430C
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl sub_081540B8
	lsls r0, r0, #0x18
	movs r1, #0xf0
	lsls r1, r1, #0x14
	ands r1, r0
	lsrs r1, r1, #0x18
	cmp r1, #6
	beq .L08154542
	cmp r1, #8
	beq .L08154542
	b .L08154684
.L08154542:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r7
	blo .L08154512
	b .L08154678
.L0815454E:
	cmp r0, #0
	bne .L08154554
	b .L08154684
.L08154554:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bne .L0815458E
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne .L0815458E
	ldr r0, [r5, #0x4c]
	ldrh r4, [r0, #0x12]
	adds r0, r6, #0
	bl sub_0815430C
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_081540B8
	lsls r0, r0, #0x18
	movs r1, #0xf0
	lsls r1, r1, #0x14
	ands r1, r0
	lsrs r1, r1, #0x18
	cmp r1, #6
	beq .L08154678
	cmp r1, #8
	beq .L0815458C
	b .L08154684
.L0815458C:
	b .L08154678
.L0815458E:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bne .L081545C6
	ldrh r0, [r5, #8]
	cmp r0, #2
	bne .L081545C6
	ldr r0, [r5, #0x50]
	ldrh r4, [r0, #0x12]
	adds r0, r6, #0
	bl sub_0815430C
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_081540B8
	lsls r0, r0, #0x18
	movs r1, #0xf0
	lsls r1, r1, #0x14
	ands r1, r0
	lsrs r1, r1, #0x18
	cmp r1, #6
	beq .L08154678
	cmp r1, #8
	bne .L08154684
	b .L08154678
.L081545C6:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bne .L08154604
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne .L08154604
	ldr r0, .L08154600
	ldrh r4, [r0]
	adds r0, r6, #0
	bl sub_0815430C
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_081540B8
	lsls r0, r0, #0x18
	movs r1, #0xf0
	lsls r1, r1, #0x14
	ands r1, r0
	lsrs r1, r1, #0x18
	cmp r1, #6
	beq .L08154678
	cmp r1, #8
	bne .L08154684
	b .L08154678
	.byte 0x00, 0x00
.L08154600: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08154604:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L08154640
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne .L08154640
	ldr r0, .L0815463C
	ldrh r4, [r0]
	adds r0, r6, #0
	bl sub_08154344
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_081540B8
	lsls r0, r0, #0x18
	movs r1, #0xf0
	lsls r1, r1, #0x14
	ands r1, r0
	lsrs r1, r1, #0x18
	cmp r1, #6
	beq .L08154678
	cmp r1, #8
	bne .L08154684
	b .L08154678
.L0815463C: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08154640:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne .L08154684
	ldrh r0, [r5, #8]
	cmp r0, #2
	bne .L08154684
	ldr r4, .L0815467C
	ldrh r0, [r4]
	bl sub_08154968
	ldr r5, .L08154680
	adds r1, r5, #0
	adds r1, #0x90
	strh r0, [r1]
	ldrh r0, [r4, #2]
	bl sub_08154968
	adds r1, r5, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x94
	strh r6, [r0]
	bl sub_0815AE84
	cmp r0, #0
	bne .L08154684
.L08154678:
	movs r0, #0
	b .L08154686
.L0815467C: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08154680: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08154684:
	movs r0, #1
.L08154686:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0815468C
sub_0815468C: @ 0x0815468C
	push {lr}
	movs r0, #0x19
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_08154698
sub_08154698: @ 0x08154698
	push {r4, lr}
	ldr r4, .L081546AC
	ldr r0, .L081546B0
	movs r1, #0
	bl sub_080B6B58
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
.L081546AC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081546B0: .4byte sub_0815468C

	thumb_func_start sub_081546B4
sub_081546B4: @ 0x081546B4
	push {lr}
	adds r2, r0, #0
	ldr r0, .L081546CC
	ldr r0, [r0, #0xc]
	ldr r1, [r0, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L081546D0
	movs r0, #1
	b .L081546D2
	.byte 0x00, 0x00
.L081546CC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081546D0:
	movs r0, #0
.L081546D2:
	strh r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_081546D8
sub_081546D8: @ 0x081546D8
	ldr r0, .L081546E4
	ldr r1, [r0, #0xc]
	movs r0, #1
	str r0, [r1, #0xc]
	bx lr
	.byte 0x00, 0x00
.L081546E4: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081546E8
sub_081546E8: @ 0x081546E8
.L081546E8:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	bl sub_080C0148
	adds r0, r4, #0
	bl sub_080BF648
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1a
	ble .L08154734
	adds r0, r5, #0
	bl sub_080BF648
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1a
	ble .L08154734
	adds r0, r6, #0
	bl sub_080BF648
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1a
	ble .L08154734
	movs r0, #1
	b .L08154736
.L08154734:
	movs r0, #0
.L08154736:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_0815473C
sub_0815473C: @ 0x0815473C
.L0815473C:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	bl sub_080C0148
	mov r8, r0
	ldr r0, .L081547B4
	mov sb, r0
	adds r0, r5, #0
	bl sub_080C3560
	cmp r0, #0
	beq .L08154778
	cmp r7, r5
	beq .L08154778
	cmp r6, r5
	beq .L08154778
	cmp r4, r5
	bne .L081547AE
.L08154778:
	adds r0, r5, #0
	bl sub_08134C3C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L081547AE
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #3
	bne .L081547B8
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl sub_081546E8
	cmp r0, #1
	bne .L081547B8
	mov r2, r8
	ldrb r4, [r2, #0xd]
	adds r4, #9
	adds r0, r5, #0
	bl sub_080BF648
	ldrb r0, [r0, #1]
	cmp r4, r0
	bge .L081547C8
.L081547AE:
	movs r0, #0
	b .L081547CA
	.byte 0x00, 0x00
.L081547B4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081547B8:
	adds r0, r5, #0
	bl sub_080BF648
	mov r2, r8
	ldrb r1, [r2, #0xd]
	ldrb r0, [r0, #1]
	cmp r1, r0
	blo .L081547AE
.L081547C8:
	movs r0, #1
.L081547CA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_081547D8
sub_081547D8: @ 0x081547D8
.L081547D8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	adds r0, r6, #0
	bl sub_080BF648
	adds r5, r0, #0
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Race_GetName
	movs r4, #0
	adds r1, r5, #0
	adds r1, #0x22
	ldrh r0, [r5, #0x22]
	cmp r0, #0
	beq .L081548EA
	mov r2, sl
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	adds r0, r7, #5
	lsls r0, r0, #0x10
	str r0, [sp, #4]
.L08154826:
	cmp r6, #0xff
	beq .L081548D2
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0x2c
	beq .L08154868
	lsls r0, r4, #1
	adds r0, r1, r0
	ldrh r0, [r0]
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r2, r2, #1
	add r2, sb
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r3, r8
	str r3, [sp]
	ldr r1, .L08154864
	adds r3, r7, #0
	bl sub_08153FC8
	cmp r4, #0
	bne .L081548D2
	ldrb r0, [r5, #1]
	movs r1, #0xe0
	ldr r3, [sp, #4]
	lsrs r2, r3, #0x10
	mov r3, sl
	bl sub_081549BC
	b .L081548D2
.L08154864: .4byte 0x0200F874 @ EWRAM+0xF874
.L08154868:
	movs r0, #0xa8
	lsls r0, r0, #1
	cmp r6, r0
	beq .L08154882
	adds r0, #5
	cmp r6, r0
	beq .L08154882
	adds r0, #0x13
	cmp r6, r0
	beq .L08154882
	adds r0, #1
	cmp r6, r0
	bne .L081548B0
.L08154882:
	lsls r1, r4, #1
	adds r0, r5, #0
	adds r0, #0x22
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r2, r2, #1
	add r2, sb
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	subs r3, r7, #1
	lsls r3, r3, #0x10
	mov r1, r8
	str r1, [sp]
	ldr r1, .L081548AC
	lsrs r3, r3, #0x10
	bl sub_08153FC8
	b .L081548D2
	.byte 0x00, 0x00
.L081548AC: .4byte 0x0200F874 @ EWRAM+0xF874
.L081548B0:
	lsls r2, r4, #1
	adds r0, r5, #0
	adds r0, #0x22
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r2, r2, r4
	lsls r2, r2, #2
	add r2, sb
	adds r2, #4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r3, r8
	str r3, [sp]
	ldr r1, .L081548FC
	adds r3, r7, #0
	bl Font_DrawGlyphTinted
.L081548D2:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #7
	bhi .L081548EA
	lsls r0, r4, #1
	adds r1, r5, #0
	adds r1, #0x22
	adds r0, r1, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08154826
.L081548EA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081548FC: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_08154900
sub_08154900: @ 0x08154900
.L08154900:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r4, #0
	adds r1, #2
	lsls r6, r1, #0x10
	adds r7, r1, #0
.L08154914:
	lsls r2, r4, #3
	adds r2, r5, r2
	adds r2, #3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	movs r0, #8
	ldr r1, .L08154964
	lsrs r3, r6, #0x10
	bl Font_DrawGlyphTinted
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #7
	bls .L08154914
	movs r4, #0
	lsls r6, r7, #0x10
.L0815493A:
	lsls r2, r4, #3
	adds r2, r5, r2
	adds r2, #0x55
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	movs r0, #8
	ldr r1, .L08154964
	lsrs r3, r6, #0x10
	bl Font_DrawGlyphTinted
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #1
	bls .L0815493A
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08154964: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_08154968
sub_08154968: @ 0x08154968
.L08154968:
	lsls r0, r0, #0x10
	ldr r1, .L08154978
	lsrs r0, r0, #0xf
	ldr r2, .L0815497C
	adds r0, r0, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
.L08154978: .4byte gUnknown_087E1BF6
.L0815497C: .4byte 0xFFFFFD60

	thumb_func_start sub_08154980
sub_08154980: @ 0x08154980
.L08154980:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #0
	ldr r5, .L081549A8
	ldr r3, .L081549AC
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r4, r0, #0
.L08154992:
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, r3
	beq .L081549B6
	cmp r0, r2
	beq .L081549B0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b .L08154992
.L081549A8: .4byte gUnknown_087E1BF6
.L081549AC: .4byte 0x0000FFFF
.L081549B0:
	adds r0, r1, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L081549B6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_081549BC
sub_081549BC: @ 0x081549BC
.L081549BC:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	adds r0, r4, #0
	bl NumberToDigits
	cmp r4, #9
	bls .L081549F8
	add r1, sp, #8
	ldr r2, .L081549F4
	ldrb r0, [r2, #1]
	adds r0, #0x30
	movs r3, #0
	strb r0, [r1]
	ldrb r0, [r2]
	adds r0, #0x30
	strb r0, [r1, #1]
	adds r0, r1, #0
	strb r3, [r0, #2]
	b .L08154A10
.L081549F4: .4byte 0x030020E8 @ IWRAM+0x20E8
.L081549F8:
	add r2, sp, #8
	ldr r0, .L08154A30
	ldrb r0, [r0]
	adds r0, #0x30
	movs r1, #0
	strb r0, [r2]
	adds r0, r2, #0
	strb r1, [r0, #1]
	adds r0, r5, #0
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L08154A10:
	ldr r1, .L08154A34
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	add r0, sp, #8
	adds r2, r5, #0
	adds r3, r7, #0
	bl DigitFont_DrawStringTinted
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08154A30: .4byte 0x030020E8 @ IWRAM+0x20E8
.L08154A34: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_08154A38
sub_08154A38: @ 0x08154A38
.L08154A38:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x20]
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r1, r1, #2
	adds r0, #0x1c
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	movs r6, #0
	cmp r0, #0
	bne .L08154A62
	b .L08154EB0
.L08154A62:
	ldrh r0, [r0, #0x12]
	bl sub_080BF648
	mov sl, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Race_GetName
	str r0, [sp, #0x24]
	mov r1, r8
	ldrh r0, [r1, #0x12]
	bl sub_081544AC
	cmp r0, #0
	bne .L08154A88
	movs r6, #2
.L08154A88:
	ldr r2, [sp, #0x20]
	lsls r0, r2, #5
	ldr r1, .L08154B28
	adds r0, r0, r1
	ldr r1, .L08154B2C
	movs r2, #0
	str r2, [sp]
	str r7, [sp, #4]
	movs r2, #8
	str r2, [sp, #8]
	movs r2, #0xd
	str r2, [sp, #0xc]
	movs r2, #4
	str r2, [sp, #0x10]
	movs r2, #0
	movs r3, #3
	bl Canvas_BlitOrTinted
	movs r4, #0
	lsls r6, r6, #0x18
	mov sb, r6
	mov r3, sl
	adds r3, #0x22
	str r3, [sp, #0x2c]
.L08154AB8:
	lsls r2, r4, #1
	ldr r6, [sp, #0x24]
	adds r0, r2, r6
	ldrh r0, [r0]
	adds r2, r2, r4
	lsls r2, r2, #0x12
	movs r1, #0xa0
	lsls r1, r1, #0xc
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	mov r3, sb
	lsrs r1, r3, #0x18
	str r1, [sp]
	ldr r1, .L08154B2C
	adds r3, r7, #0
	bl Font_DrawGlyphTinted
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #2
	bls .L08154AB8
	movs r4, #0
	ldr r1, [sp, #0x2c]
	mov r6, sl
	ldrh r0, [r6, #0x22]
	cmp r0, #0
	beq .L08154B9E
	subs r0, r7, #2
	lsls r0, r0, #0x10
	str r0, [sp, #0x28]
.L08154AF6:
	mov r2, sl
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0x2c
	beq .L08154B30
	lsls r0, r4, #1
	adds r0, r1, r0
	ldrh r0, [r0]
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r2, r2, #0x11
	movs r3, #0xb0
	lsls r3, r3, #0xe
	adds r2, r2, r3
	lsrs r2, r2, #0x10
	mov r6, sb
	lsrs r1, r6, #0x18
	str r1, [sp]
	ldr r1, .L08154B2C
	ldr r6, [sp, #0x28]
	lsrs r3, r6, #0x10
	bl sub_08153FC8
	b .L08154B88
	.byte 0x00, 0x00
.L08154B28: .4byte gUnknown_087E13E4
.L08154B2C: .4byte 0x0200F874 @ EWRAM+0xF874
.L08154B30:
	mov r1, r8
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	bl sub_0815BAC4
	cmp r0, #1
	bne .L08154B68
	lsls r2, r4, #1
	ldr r3, [sp, #0x2c]
	adds r0, r3, r2
	ldrh r0, [r0]
	adds r2, r2, r4
	lsls r2, r2, #0x12
	movs r6, #0xc0
	lsls r6, r6, #0xe
	adds r2, r2, r6
	lsrs r2, r2, #0x10
	mov r3, sb
	lsrs r1, r3, #0x18
	str r1, [sp]
	ldr r1, .L08154B64
	adds r3, r7, #0
	bl Font_DrawGlyphTinted
	b .L08154B88
	.byte 0x00, 0x00
.L08154B64: .4byte 0x0200F874 @ EWRAM+0xF874
.L08154B68:
	lsls r2, r4, #1
	ldr r6, [sp, #0x2c]
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r2, r2, r4
	lsls r2, r2, #0x12
	movs r1, #0xc0
	lsls r1, r1, #0xe
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #4
	str r1, [sp]
	ldr r1, .L08154BE0
	adds r3, r7, #0
	bl Font_DrawGlyphTinted
.L08154B88:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #7
	bhi .L08154B9E
	lsls r0, r4, #1
	ldr r1, [sp, #0x2c]
	adds r0, r1, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08154AF6
.L08154B9E:
	ldrh r0, [r5]
	adds r1, r0, #0
	cmp r1, #1
	beq .L08154BAE
	cmp r1, #4
	beq .L08154BAE
	cmp r1, #5
	bne .L08154BBC
.L08154BAE:
	ldrh r1, [r5, #8]
	cmp r1, #0
	beq .L08154BD2
	cmp r0, #5
	bne .L08154BBC
	cmp r1, #1
	beq .L08154BD2
.L08154BBC:
	ldrh r1, [r5]
	cmp r1, #2
	bne .L08154BC8
	ldrh r0, [r5, #8]
	cmp r0, #0
	beq .L08154BD2
.L08154BC8:
	cmp r1, #3
	bne .L08154C18
	ldrh r0, [r5, #8]
	cmp r0, #2
	beq .L08154C18
.L08154BD2:
	mov r2, sl
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0x2c
	beq .L08154BE4
	ldrb r4, [r2, #1]
	b .L08154C08
.L08154BE0: .4byte 0x0200F874 @ EWRAM+0xF874
.L08154BE4:
	mov r3, r8
	ldrh r0, [r3, #0x12]
	bl sub_08154968
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, .L08154C70
	ldr r1, .L08154C74
	movs r2, #0
	str r2, [sp]
	movs r2, #0x76
	adds r3, r7, #0
	bl Font_DrawGlyphTinted
.L08154C08:
	adds r2, r7, #3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r1, #0x82
	movs r3, #0
	bl sub_081549BC
.L08154C18:
	ldrh r0, [r5]
	cmp r0, #1
	bne .L08154C80
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne .L08154C26
	b .L08154DE2
.L08154C26:
	ldr r4, .L08154C78
	ldrh r0, [r4]
	ldr r1, .L08154C7C
	mov r6, r8
	ldrh r2, [r6, #0x12]
	mov r5, sp
	adds r5, #0x16
	str r5, [sp]
	add r3, sp, #0x14
	bl sub_0815B884
	add r0, sp, #0x14
	ldrh r0, [r0]
	strh r0, [r4, #6]
	add r0, sp, #0x14
	ldrh r0, [r0]
	movs r1, #0x7c
	adds r2, r7, #0
	movs r3, #0
	bl sub_081547D8
	add r0, sp, #0x14
	ldrh r0, [r0]
	cmp r0, #0xff
	bne .L08154C5A
	b .L08154EB0
.L08154C5A:
	ldr r0, .L08154C70
	ldr r1, .L08154C74
	movs r2, #0
	str r2, [sp]
	movs r2, #0xce
	adds r3, r7, #0
	bl Font_DrawGlyphTinted
	ldrh r0, [r5]
	b .L08154CFC
	.byte 0x00, 0x00
.L08154C70: .4byte 0x00000115
.L08154C74: .4byte 0x0200F874 @ EWRAM+0xF874
.L08154C78: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08154C7C: .4byte 0x0000FFFF
.L08154C80:
	cmp r0, #4
	bne .L08154CA8
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne .L08154C8C
	b .L08154DE2
.L08154C8C:
	ldr r5, .L08154CA0
	ldrh r0, [r5]
	mov r2, r8
	ldrh r1, [r2, #0x12]
	ldr r2, .L08154CA4
	add r4, sp, #0x18
	mov r6, sp
	adds r6, #0x1a
	b .L08154CCA
	.byte 0x00, 0x00
.L08154CA0: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08154CA4: .4byte 0x0000FFFF
.L08154CA8:
	cmp r0, #5
	bne .L08154D20
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne .L08154CB4
	b .L08154DE2
.L08154CB4:
	cmp r0, #2
	beq .L08154CBA
	b .L08154EB0
.L08154CBA:
	ldr r5, .L08154D14
	ldrh r0, [r5]
	ldrh r1, [r5, #2]
	mov r3, r8
	ldrh r2, [r3, #0x12]
	add r4, sp, #0x1c
	mov r6, sp
	adds r6, #0x1e
.L08154CCA:
	str r6, [sp]
	adds r3, r4, #0
	bl sub_0815B884
	ldrh r0, [r4]
	strh r0, [r5, #6]
	ldrh r0, [r4]
	movs r1, #0x7c
	adds r2, r7, #0
	movs r3, #0
	bl sub_081547D8
	ldrh r0, [r4]
	cmp r0, #0xff
	bne .L08154CEA
	b .L08154EB0
.L08154CEA:
	ldr r0, .L08154D18
	ldr r1, .L08154D1C
	movs r2, #0
	str r2, [sp]
	movs r2, #0xce
	adds r3, r7, #0
	bl Font_DrawGlyphTinted
	ldrh r0, [r6]
.L08154CFC:
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r7, #3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0xda
	movs r3, #0
	bl sub_081549BC
	b .L08154EB0
.L08154D14: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08154D18: .4byte 0x00000115
.L08154D1C: .4byte 0x0200F874 @ EWRAM+0xF874
.L08154D20:
	cmp r0, #2
	bne .L08154DD8
	ldrh r0, [r5, #8]
	cmp r0, #0
	beq .L08154DE2
	ldr r4, .L08154DCC
	ldr r0, [r5, #0x4c]
	ldrh r1, [r0, #0x12]
	adds r0, r4, #0
	adds r0, #0x90
	strh r1, [r0]
	mov r6, r8
	ldrh r0, [r6, #0x12]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r1, #2
	ldr r0, .L08154DD0
	strh r0, [r1]
	bl sub_0815B4B4
	bl sub_08158970
	ldr r1, .L08154DD4
	adds r6, r4, #0
	adds r6, #0xa0
	ldrh r0, [r6]
	strh r0, [r1, #6]
	ldr r0, [r5, #0x4c]
	ldrh r4, [r0, #0x12]
	mov r1, r8
	ldrh r0, [r1, #0x12]
	bl sub_0815430C
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r3, r7, #4
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	movs r2, #0x82
	bl sub_0815438C
	ldr r0, [r5, #0x4c]
	ldrh r4, [r0, #0x12]
	mov r2, r8
	ldrh r0, [r2, #0x12]
	bl sub_0815430C
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_081540B8
	lsls r0, r0, #0x18
	movs r1, #0xf0
	lsls r1, r1, #0x14
	ands r1, r0
	lsrs r1, r1, #0x18
	cmp r1, #5
	beq .L08154E6C
	movs r4, #0
	ldr r0, [r5, #0x4c]
	ldrh r0, [r0, #0x12]
	mov r3, r8
	ldrh r2, [r3, #0x12]
	ldrh r3, [r6]
	adds r1, r2, #0
	bl sub_0815473C
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08154DB8
	movs r4, #4
.L08154DB8:
	ldrh r0, [r6]
	subs r2, r7, #2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0x8a
	adds r3, r4, #0
	bl sub_081547D8
	b .L08154EB0
	.byte 0x00, 0x00
.L08154DCC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08154DD0: .4byte 0x0000FFFF
.L08154DD4: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08154DD8:
	cmp r0, #3
	bne .L08154EB0
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne .L08154DF2
.L08154DE2:
	adds r2, r7, #4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	ldr r1, [sp, #0x20]
	bl sub_081543E8
	b .L08154EB0
.L08154DF2:
	cmp r0, #2
	bne .L08154EB0
	mov r6, r8
	ldrh r0, [r6, #0x12]
	bl sub_0815430C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r4, .L08154E7C
	ldr r0, [r5, #0x4c]
	ldrh r1, [r0, #0x12]
	adds r0, r4, #0
	adds r0, #0x90
	strh r1, [r0]
	ldr r0, [r5, #0x50]
	ldrh r0, [r0, #0x12]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	mov r0, r8
	ldrh r1, [r0, #0x12]
	adds r0, r4, #0
	adds r0, #0x94
	strh r1, [r0]
	bl sub_08154074
	bl sub_0815B4B4
	bl sub_081596F0
	ldr r1, .L08154E80
	adds r4, #0xa0
	ldrh r0, [r4]
	strh r0, [r1, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xfe
	bls .L08154E42
	movs r0, #0xfb
	strh r0, [r1, #6]
.L08154E42:
	ldr r0, [r5, #0x50]
	ldrh r0, [r0, #0x12]
	adds r3, r7, #4
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r1, r6, #0
	movs r2, #0x82
	bl sub_0815438C
	ldr r0, [r5, #0x50]
	ldrh r0, [r0, #0x12]
	adds r1, r6, #0
	bl sub_081540B8
	lsls r0, r0, #0x18
	movs r1, #0xf0
	lsls r1, r1, #0x14
	ands r1, r0
	lsrs r1, r1, #0x18
	cmp r1, #5
	bne .L08154E84
.L08154E6C:
	subs r1, r7, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x8a
	bl sub_08154900
	b .L08154EB0
	.byte 0x00, 0x00
.L08154E7C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08154E80: .4byte 0x0203B854 @ EWRAM+0x3B854
.L08154E84:
	movs r6, #0
	ldr r0, [r5, #0x4c]
	ldrh r0, [r0, #0x12]
	ldr r1, [r5, #0x50]
	ldrh r1, [r1, #0x12]
	mov r3, r8
	ldrh r2, [r3, #0x12]
	ldrh r3, [r4]
	bl sub_0815473C
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08154EA0
	movs r6, #4
.L08154EA0:
	ldrh r0, [r4]
	subs r2, r7, #2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0x8a
	adds r3, r6, #0
	bl sub_081547D8
.L08154EB0:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08154EC0
sub_08154EC0: @ 0x08154EC0
.L08154EC0:
	ldr r1, .L08154EDC
	ldr r2, .L08154EE0
	adds r0, r2, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L08154EE4
	ands r0, r1
	strh r0, [r2]
	ldr r1, .L08154EE8
	movs r0, #0
	strh r0, [r1]
	bx lr
.L08154EDC: .4byte 0x0400000A @ REG_BG1CNT
.L08154EE0: .4byte 0x00008205
.L08154EE4: .4byte 0x0000FBFF
.L08154EE8: .4byte 0x03000040 @ IWRAM+0x40

	thumb_func_start sub_08154EEC
sub_08154EEC: @ 0x08154EEC
	push {lr}
	bl sub_08154EC0
	ldr r1, .L08154F28
	ldr r0, .L08154F2C
	str r0, [r1]
	ldr r0, .L08154F30
	str r0, [r1, #4]
	ldr r0, .L08154F34
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, .L08154F38
	str r2, [r1]
	ldr r0, .L08154F3C
	str r0, [r1, #4]
	ldr r0, .L08154F40
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xe0
	lsls r0, r0, #7
	adds r2, r2, r0
	str r2, [r1]
	ldr r0, .L08154F44
	str r0, [r1, #4]
	ldr r0, .L08154F48
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08154F28: .4byte 0x040000D4 @ REG_DMA3SAD
.L08154F2C: .4byte gUnknown_081B93B0
.L08154F30: .4byte 0x06001000 @ VRAM+0x1000
.L08154F34: .4byte 0x84000200
.L08154F38: .4byte 0x0200F874 @ EWRAM+0xF874
.L08154F3C: .4byte 0x06004000 @ VRAM+0x4000
.L08154F40: .4byte 0x84001800
.L08154F44: .4byte 0x06012F00 @ VRAM+0x12F00
.L08154F48: .4byte 0x84000020

	thumb_func_start sub_08154F4C
sub_08154F4C: @ 0x08154F4C
.L08154F4C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	bl sub_08153F3C
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r7, .L08154F94
	ldr r0, .L08154F98
	ldr r1, .L08154F9C
	mov r8, r1
	movs r4, #4
	str r4, [sp]
	movs r6, #8
	str r6, [sp, #4]
	movs r2, #0xa
	movs r3, #0x44
	bl SmallFont_DrawAsciiTinted
	ldr r0, .L08154FA0
	str r4, [sp]
	str r6, [sp, #4]
	mov r1, r8
	movs r2, #0x32
	movs r3, #0x44
	bl SmallFont_DrawAsciiTinted
	ldrh r0, [r7]
	cmp r0, #1
	bne .L08154FE8
	ldrh r0, [r7, #8]
	cmp r0, #0
	beq .L08154FA8
	ldr r0, .L08154FA4
	b .L08155110
.L08154F94: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08154F98: .4byte gUnknown_087E1C2C
.L08154F9C: .4byte 0x0200F874 @ EWRAM+0xF874
.L08154FA0: .4byte gUnknown_087E1C34
.L08154FA4: .4byte gUnknown_087E1C3C
.L08154FA8:
	bl sub_08153E70
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0
	cmp r0, r5
	blo .L08154FB8
	b .L08155194
.L08154FB8:
	adds r4, r0, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #0x11
	movs r0, #0x96
	lsls r0, r0, #0x10
	adds r2, r2, r0
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	ldr r1, .L08154FE4
	movs r3, #0x44
	bl sub_08153F8C
	adds r0, r4, #0
	cmp r0, r5
	blo .L08154FB8
	b .L08155194
	.byte 0x00, 0x00
.L08154FE4: .4byte 0x0200F874 @ EWRAM+0xF874
.L08154FE8:
	cmp r0, #4
	bne .L08155034
	ldrh r0, [r7, #8]
	cmp r0, #0
	beq .L08154FFC
	ldr r0, .L08154FF8
	b .L08155110
	.byte 0x00, 0x00
.L08154FF8: .4byte gUnknown_087E1C3C
.L08154FFC:
	movs r0, #0
	cmp r0, r5
	blo .L08155004
	b .L08155194
.L08155004:
	adds r4, r0, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #0x11
	movs r1, #0x96
	lsls r1, r1, #0x10
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	ldr r1, .L08155030
	movs r3, #0x44
	bl sub_08153F8C
	adds r0, r4, #0
	cmp r0, r5
	blo .L08155004
	b .L08155194
	.byte 0x00, 0x00
.L08155030: .4byte 0x0200F874 @ EWRAM+0xF874
.L08155034:
	cmp r0, #5
	bne .L0815508C
	ldrh r0, [r7, #8]
	cmp r0, #2
	bne .L08155048
	ldr r0, .L08155044
	b .L08155110
	.byte 0x00, 0x00
.L08155044: .4byte gUnknown_087E1C3C
.L08155048:
	cmp r0, #1
	beq .L0815504E
	b .L08155194
.L0815504E:
	bl sub_08153E70
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0
	cmp r0, r5
	blo .L0815505E
	b .L08155194
.L0815505E:
	adds r4, r0, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #0x11
	movs r0, #0x96
	lsls r0, r0, #0x10
	adds r2, r2, r0
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	ldr r1, .L08155088
	movs r3, #0x44
	bl sub_08153F8C
	adds r0, r4, #0
	cmp r0, r5
	blo .L0815505E
	b .L08155194
.L08155088: .4byte 0x0200F874 @ EWRAM+0xF874
.L0815508C:
	cmp r0, #2
	bne .L08155104
	ldrh r0, [r7, #8]
	cmp r0, #0
	bne .L081550E0
	ldr r0, .L081550D8
	str r4, [sp]
	str r6, [sp, #4]
	mov r1, r8
	movs r2, #0x82
	movs r3, #0x44
	bl SmallFont_DrawAsciiTinted
	movs r0, #0
	cmp r0, r5
	bhs .L08155194
.L081550AC:
	adds r4, r0, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #0x11
	movs r1, #0x96
	lsls r1, r1, #0x10
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	ldr r1, .L081550DC
	movs r3, #0x44
	bl sub_08153F8C
	adds r0, r4, #0
	cmp r0, r5
	blo .L081550AC
	b .L08155194
	.byte 0x00, 0x00
.L081550D8: .4byte gUnknown_087E1C44
.L081550DC: .4byte 0x0200F874 @ EWRAM+0xF874
.L081550E0:
	ldr r0, .L081550FC
	str r4, [sp]
	str r6, [sp, #4]
	mov r1, r8
	movs r2, #0x82
	movs r3, #0x44
	bl SmallFont_DrawAsciiTinted
	ldr r0, .L08155100
	str r4, [sp]
	str r6, [sp, #4]
	mov r1, r8
	movs r2, #0xe0
	b .L08155118
.L081550FC: .4byte gUnknown_087E1C3C
.L08155100: .4byte gUnknown_087E1C44
.L08155104:
	cmp r0, #3
	bne .L08155194
	ldrh r0, [r7, #8]
	cmp r0, #0
	bne .L08155124
	ldr r0, .L08155120
.L08155110:
	str r4, [sp]
	str r6, [sp, #4]
	mov r1, r8
	movs r2, #0x82
.L08155118:
	movs r3, #0x44
	bl SmallFont_DrawAsciiTinted
	b .L08155194
.L08155120: .4byte gUnknown_087E1C44
.L08155124:
	cmp r0, #1
	bne .L08155170
	ldr r0, .L08155168
	str r4, [sp]
	str r6, [sp, #4]
	mov r1, r8
	movs r2, #0x82
	movs r3, #0x44
	bl SmallFont_DrawAsciiTinted
	movs r0, #0
	cmp r0, r5
	bhs .L08155194
.L0815513E:
	adds r4, r0, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #0x11
	movs r0, #0x96
	lsls r0, r0, #0x10
	adds r2, r2, r0
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	ldr r1, .L0815516C
	movs r3, #0x44
	bl sub_08153F8C
	adds r0, r4, #0
	cmp r0, r5
	blo .L0815513E
	b .L08155194
.L08155168: .4byte gUnknown_087E1C44
.L0815516C: .4byte 0x0200F874 @ EWRAM+0xF874
.L08155170:
	cmp r0, #2
	bne .L08155194
	ldr r0, .L081551A0
	str r4, [sp]
	str r6, [sp, #4]
	mov r1, r8
	movs r2, #0x82
	movs r3, #0x44
	bl SmallFont_DrawAsciiTinted
	ldr r0, .L081551A4
	str r4, [sp]
	str r6, [sp, #4]
	mov r1, r8
	movs r2, #0xe0
	movs r3, #0x44
	bl SmallFont_DrawAsciiTinted
.L08155194:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L081551A0: .4byte gUnknown_087E1C3C
.L081551A4: .4byte gUnknown_087E1C44

	thumb_func_start sub_081551A8
sub_081551A8: @ 0x081551A8
.L081551A8:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r5, .L081551EC
	ldr r1, .L081551F0
	adds r0, r5, r1
	ldrh r0, [r0]
	bl sub_0815B880
	movs r4, #0
.L081551BC:
	adds r1, r6, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0xd
	adds r2, r4, #0
	muls r2, r0, r2
	adds r2, #0x4c
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	bl sub_08154A38
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #5
	bls .L081551BC
	ldr r0, .L081551F4
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L081551EC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081551F0: .4byte 0x0000065E
.L081551F4: .4byte sub_08154EEC
