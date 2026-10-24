	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080D38D0
sub_080D38D0: @ 0x080D38D0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x24
	ldr r0, .L080D392C
	mov ip, r0
	ldrh r5, [r2, #8]
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	adds r6, r5, #0
	cmp r5, #5
	bls .L080D38EC
	movs r6, #6
.L080D38EC:
	ldr r3, .L080D3930
	ldrh r1, [r3]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq .L080D394C
	ldrh r0, [r2, #4]
	ldrh r1, [r2, #6]
	adds r0, r0, r1
	lsls r0, r0, #1
	add r0, ip
	ldrh r6, [r0]
	adds r0, r6, #0
	bl sub_080C5B10
	adds r5, r0, #0
	cmp r5, #0
	bne .L080D3944
	movs r0, #0x65
	bl sub_080C51D4
	strh r7, [r4, #0x1e]
	strh r7, [r4, #0x1c]
	ldr r0, .L080D3934
	str r5, [r0]
	ldr r0, .L080D3938
	strh r6, [r0]
	ldr r1, .L080D393C
	ldr r0, .L080D3940
	str r0, [r1]
	b .L080D3A42
.L080D392C: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080D3930: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D3934: .4byte 0x030031CC @ IWRAM+0x31CC
.L080D3938: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L080D393C: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L080D3940: .4byte 0x00002710
.L080D3944:
	movs r0, #0x66
	bl sub_080C51D4
	b .L080D3A42
.L080D394C:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080D3970
	movs r0, #0x66
	bl sub_080C51D4
	strh r7, [r4, #0x1c]
	ldr r0, .L080D3968
	strh r0, [r4, #0x1e]
	ldr r0, .L080D396C
	str r7, [r0]
	b .L080D3A42
.L080D3968: .4byte 0x0000FFFF
.L080D396C: .4byte 0x030031CC @ IWRAM+0x31CC
.L080D3970:
	ldr r1, .L080D3988
	ldrh r3, [r1]
	movs r0, #0x40
	ands r0, r3
	cmp r0, #0
	beq .L080D3998
	ldrh r0, [r2, #4]
	cmp r0, #0
	beq .L080D398C
	subs r0, #1
	strh r0, [r2, #4]
	b .L080D39F8
.L080D3988: .4byte 0x03003964 @ IWRAM+0x3964
.L080D398C:
	ldrh r0, [r2, #6]
	cmp r0, #0
	beq .L080D3A42
	subs r0, #1
	strh r0, [r2, #6]
	b .L080D39F8
.L080D3998:
	movs r0, #0x80
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L080D39C8
	ldrh r1, [r2, #4]
	subs r0, r6, #1
	cmp r1, r0
	beq .L080D39B2
	adds r0, r1, #1
	strh r0, [r2, #4]
	b .L080D39F8
.L080D39B2:
	cmp r1, #5
	bne .L080D3A42
	ldrh r3, [r2, #6]
	adds r0, r1, r3
	adds r0, #1
	subs r1, r5, #1
	cmp r0, r1
	bgt .L080D3A42
	adds r0, r3, #1
	strh r0, [r2, #6]
	b .L080D39F8
.L080D39C8:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r3
	cmp r0, #0
	beq .L080D3A00
	cmp r5, #6
	bls .L080D3A00
	ldrh r3, [r2, #4]
	ldrh r1, [r2, #6]
	adds r0, r3, #0
	cmp r0, #0
	beq .L080D39E4
	strh r4, [r2, #4]
	b .L080D39EC
.L080D39E4:
	cmp r1, #4
	bls .L080D39EA
	subs r0, r1, #5
.L080D39EA:
	strh r0, [r2, #6]
.L080D39EC:
	ldrh r0, [r2, #4]
	cmp r3, r0
	bne .L080D39F8
	ldrh r2, [r2, #6]
	cmp r1, r2
	beq .L080D3A42
.L080D39F8:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080D3A42
.L080D3A00:
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080D3A42
	cmp r5, #6
	bls .L080D3A42
	ldrh r3, [r2, #4]
	ldrh r4, [r2, #6]
	cmp r3, #5
	beq .L080D3A1E
	movs r0, #5
	strh r0, [r2, #4]
	b .L080D3A30
.L080D3A1E:
	adds r0, r3, r4
	adds r0, #6
	subs r1, r5, #1
	cmp r0, r1
	bge .L080D3A2C
	adds r0, r4, #6
	b .L080D3A2E
.L080D3A2C:
	subs r0, r5, #6
.L080D3A2E:
	strh r0, [r2, #6]
.L080D3A30:
	ldrh r0, [r2, #4]
	cmp r3, r0
	bne .L080D3A3C
	ldrh r2, [r2, #6]
	cmp r4, r2
	beq .L080D3A42
.L080D3A3C:
	movs r0, #0x64
	bl sub_080C51D4
.L080D3A42:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080D3A48
sub_080D3A48: @ 0x080D3A48
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r1, .L080D3A74
	movs r0, #8
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0x15
	movs r3, #0
	bl Tilemap_FillRect
	ldr r0, [r4, #0x24]
	movs r1, #1
	bl TextWindow_Close
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D3A74: .4byte 0x0200DFD4 @ EWRAM+0xDFD4

	thumb_func_start sub_080D3A78
sub_080D3A78: @ 0x080D3A78
	ldrb r1, [r0, #6]
	strh r1, [r0, #0x1c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D3A80
sub_080D3A80: @ 0x080D3A80
.L080D3A80:
	push {lr}
	ldr r0, .L080D3A94
	ldr r1, .L080D3A98
	bl Task_Create
	ldr r1, .L080D3A9C
	str r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D3A94: .4byte gUnknown_084F3228
.L080D3A98: .4byte 0x0000FFFF
.L080D3A9C: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D3AA0
sub_080D3AA0: @ 0x080D3AA0
.L080D3AA0:
	push {r4, r5, lr}
	adds r5, r0, #0
	cmp r5, #0
	bne .L080D3AC4
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L080D3AC0
	ldr r0, [r0]
	ldrh r0, [r0, #0x1e]
	cmp r0, #0
	beq .L080D3AF2
	movs r0, #1
	b .L080D3AF4
	.byte 0x00, 0x00
.L080D3AC0: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080D3AC4:
	cmp r5, #1
	bne .L080D3AE0
	ldr r4, .L080D3ADC
	ldr r0, [r4]
	bl Task_Signal
	ldr r1, [r4]
	movs r0, #0
	strh r0, [r1, #0x1e]
	strb r5, [r1, #6]
	b .L080D3AF2
	.byte 0x00, 0x00
.L080D3ADC: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080D3AE0:
	ldr r4, .L080D3AFC
	ldr r0, [r4]
	bl Task_Signal
	ldr r1, [r4]
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #0x1e]
	strb r2, [r1, #6]
.L080D3AF2:
	movs r0, #0
.L080D3AF4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080D3AFC: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D3B00
sub_080D3B00: @ 0x080D3B00
	ldr r1, .L080D3B08
	movs r0, #0
	str r0, [r1]
	bx lr
.L080D3B08: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D3B0C
sub_080D3B0C: @ 0x080D3B0C
	ldr r0, .L080D3B14
	str r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080D3B14: .4byte 0x030031CC @ IWRAM+0x31CC

	thumb_func_start sub_080D3B18
sub_080D3B18: @ 0x080D3B18
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r5, .L080D3B4C
	ldr r0, .L080D3B50
	adds r1, r5, #0
	stm r1!, {r0}
	movs r4, #0
	str r4, [sp]
	ldr r6, .L080D3B54
	mov r0, sp
	adds r2, r6, #0
	bl CpuSet
	str r4, [r5, #0x34]
	str r4, [sp, #4]
	add r0, sp, #4
	adds r5, #0x38
	adds r1, r5, #0
	adds r2, r6, #0
	bl CpuSet
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D3B4C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D3B50: .4byte 0x13240800
.L080D3B54: .4byte 0x05000002 @ PLTT+0x2

	thumb_func_start sub_080D3B58
sub_080D3B58: @ 0x080D3B58
.L080D3B58:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	ldr r2, .L080D3B8C
	adds r2, #0x38
	ldr r1, .L080D3B90
	adds r0, r0, r1
	lsrs r1, r0, #3
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #7
	ands r0, r2
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq .L080D3B86
	adds r0, r3, #0
	bl Flag_Set
	movs r0, #0
.L080D3B86:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080D3B8C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D3B90: .4byte 0xFFFFFF00

	thumb_func_start sub_080D3B94
sub_080D3B94: @ 0x080D3B94
	push {r4, lr}
	movs r2, #1
	ldr r0, .L080D3BB0
	ldrh r0, [r0]
	ldr r1, .L080D3BB4
	adds r0, r0, r1
	cmp r0, #0x12
	bhi .L080D3C62
	lsls r0, r0, #2
	ldr r1, .L080D3BB8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080D3BB0: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L080D3BB4: .4byte 0xFFFFFEC3
.L080D3BB8: .4byte gUnknown_080D3BBC
	.global gUnknown_080D3BBC
gUnknown_080D3BBC:
.L080D3BBC: @ jump table
	.4byte .L080D3C08
	.4byte .L080D3C62
	.4byte .L080D3C62
	.4byte .L080D3C62
	.4byte .L080D3C62
	.4byte .L080D3C62
	.4byte .L080D3C62
	.4byte .L080D3C62
	.4byte .L080D3C62
	.4byte .L080D3C18
	.4byte .L080D3C22
	.4byte .L080D3C62
	.4byte .L080D3C62
	.4byte .L080D3C30
	.4byte .L080D3C3C
	.4byte .L080D3C62
	.4byte .L080D3C48
	.4byte .L080D3C62
	.4byte .L080D3C58
.L080D3C08:
	ldr r0, .L080D3C10
	ldr r1, .L080D3C14
	b .L080D3C5C
	.byte 0x00, 0x00
.L080D3C10: .4byte 0x00000117
.L080D3C14: .4byte 0x00000131
.L080D3C18:
	movs r0, #0x8f
	lsls r0, r0, #1
	movs r1, #0x9d
	lsls r1, r1, #1
	b .L080D3C5C
.L080D3C22:
	ldr r0, .L080D3C28
	ldr r1, .L080D3C2C
	b .L080D3C5C
.L080D3C28: .4byte 0x0000010F
.L080D3C2C: .4byte 0x0000013B
.L080D3C30:
	ldr r0, .L080D3C38
	movs r1, #0x9f
	lsls r1, r1, #1
	b .L080D3C5C
.L080D3C38: .4byte 0x00000101
.L080D3C3C:
	movs r0, #0x8b
	lsls r0, r0, #1
	ldr r1, .L080D3C44
	b .L080D3C5C
.L080D3C44: .4byte 0x0000013F
.L080D3C48:
	ldr r0, .L080D3C50
	ldr r1, .L080D3C54
	b .L080D3C5C
	.byte 0x00, 0x00
.L080D3C50: .4byte 0x00000115
.L080D3C54: .4byte 0x00000141
.L080D3C58:
	ldr r0, .L080D3C90
	ldr r1, .L080D3C94
.L080D3C5C:
	bl sub_080D3B58
	adds r2, r0, #0
.L080D3C62:
	ldr r0, .L080D3C98
	str r2, [r0]
	cmp r2, #1
	bne .L080D3C88
	ldr r4, .L080D3C9C
	ldr r1, .L080D3CA0
	ldr r0, .L080D3CA4
	adds r3, r1, r0
	ldr r2, .L080D3CA8
.L080D3C74:
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080D3C82
	ldr r0, [r1, #0x20]
	cmp r0, r4
	bne .L080D3C82
	str r2, [r1, #0x20]
.L080D3C82:
	adds r1, #0x64
	cmp r1, r3
	bls .L080D3C74
.L080D3C88:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D3C90: .4byte 0x0000011B
.L080D3C94: .4byte 0x00000143
.L080D3C98: .4byte 0x030031CC @ IWRAM+0x31CC
.L080D3C9C: .4byte sub_080DA5DC
.L080D3CA0: .4byte 0x02009004 @ EWRAM+0x9004
.L080D3CA4: .4byte 0x0000189C
.L080D3CA8: .4byte sub_080DA608

	thumb_func_start sub_080D3CAC
sub_080D3CAC: @ 0x080D3CAC
.L080D3CAC:
	push {lr}
	ldr r0, .L080D3CC0
	ldr r1, .L080D3CC4
	bl Task_Create
	ldr r1, .L080D3CC8
	str r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D3CC0: .4byte gUnknown_084F32B4
.L080D3CC4: .4byte 0x0000FFFF
.L080D3CC8: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D3CCC
sub_080D3CCC: @ 0x080D3CCC
.L080D3CCC:
	push {lr}
	movs r1, #0
	ldr r0, .L080D3CE0
	ldr r0, [r0]
	cmp r0, #0
	bne .L080D3CDA
	movs r1, #1
.L080D3CDA:
	adds r0, r1, #0
	pop {r1}
	bx r1
.L080D3CE0: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D3CE4
sub_080D3CE4: @ 0x080D3CE4
.L080D3CE4:
	ldr r0, .L080D3CEC
	ldr r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080D3CEC: .4byte 0x030031CC @ IWRAM+0x31CC

	thumb_func_start sub_080D3CF0
sub_080D3CF0: @ 0x080D3CF0
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r5, .L080D3D24
	ldr r0, .L080D3D28
	adds r1, r5, #0
	stm r1!, {r0}
	movs r4, #0
	str r4, [sp]
	ldr r6, .L080D3D2C
	mov r0, sp
	adds r2, r6, #0
	bl CpuSet
	str r4, [r5, #0x34]
	str r4, [sp, #4]
	add r0, sp, #4
	adds r5, #0x38
	adds r1, r5, #0
	adds r2, r6, #0
	bl CpuSet
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D3D24: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D3D28: .4byte 0x10570010
.L080D3D2C: .4byte 0x0500000A @ PLTT+0xA

	thumb_func_start sub_080D3D30
sub_080D3D30: @ 0x080D3D30
	push {lr}
	ldr r1, .L080D3D44
	adds r2, r1, #0
	adds r2, #0x34
	movs r0, #0x2c
	bl sub_080DF954
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D3D44: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D3D48
sub_080D3D48: @ 0x080D3D48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #1
	ldr r0, .L080D3DE0
	adds r0, #0x38
	mov r8, r0
	movs r5, #0
	ldr r0, .L080D3DE4
	bl sub_080C32D4
	ldr r4, .L080D3DE8
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L080D3DD0
	adds r7, r1, #0
.L080D3D6E:
	ldrh r0, [r4, #2]
	bl sub_080C3560
	cmp r0, #0
	bne .L080D3DC0
	ldrh r0, [r4, #4]
	cmp r0, #0
	beq .L080D3D86
	bl sub_080C3560
	cmp r0, #0
	bne .L080D3DC0
.L080D3D86:
	ldrh r0, [r4, #6]
	cmp r0, #0
	beq .L080D3D94
	bl sub_080C3560
	cmp r0, #0
	bne .L080D3DC0
.L080D3D94:
	ldrh r0, [r4, #8]
	cmp r0, #0
	beq .L080D3DC0
	adds r2, r0, #0
	lsrs r0, r2, #3
	add r0, r8
	ldrb r1, [r0]
	movs r0, #7
	ands r2, r0
	asrs r1, r2
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq .L080D3DC0
	adds r0, r5, #0
	bl sub_080D3E24
	movs r6, #0
	movs r0, #0xb1
	lsls r0, r0, #1
	bl Flag_Set
.L080D3DC0:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r4, #0xc
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, r7
	bne .L080D3D6E
.L080D3DD0:
	ldr r0, .L080D3DEC
	str r6, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D3DE0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D3DE4: .4byte 0x0000011F
.L080D3DE8: .4byte gUnknown_084F3754
.L080D3DEC: .4byte 0x030031CC @ IWRAM+0x31CC

	thumb_func_start sub_080D3DF0
sub_080D3DF0: @ 0x080D3DF0
.L080D3DF0:
	push {lr}
	ldr r0, .L080D3E04
	ldr r1, .L080D3E08
	bl Task_Create
	ldr r1, .L080D3E0C
	str r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D3E04: .4byte gUnknown_084F3498
.L080D3E08: .4byte 0x0000FFFF
.L080D3E0C: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D3E10
sub_080D3E10: @ 0x080D3E10
.L080D3E10:
	ldr r1, .L080D3E20
	movs r0, #0
	strb r0, [r1, #3]
	strb r0, [r1, #2]
	strb r0, [r1, #1]
	strb r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080D3E20: .4byte 0x0203BB6C @ EWRAM+0x3BB6C

	thumb_func_start sub_080D3E24
sub_080D3E24: @ 0x080D3E24
.L080D3E24:
	lsls r0, r0, #0x10
	ldr r1, .L080D3E40
	lsrs r2, r0, #0x13
	adds r2, r2, r1
	movs r1, #0xe0
	lsls r1, r1, #0xb
	ands r1, r0
	lsrs r1, r1, #0x10
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	bx lr
.L080D3E40: .4byte 0x0203BB6C @ EWRAM+0x3BB6C

	thumb_func_start sub_080D3E44
sub_080D3E44: @ 0x080D3E44
.L080D3E44:
	adds r2, r0, #0
	lsls r2, r2, #0x10
	ldr r1, .L080D3E60
	lsrs r0, r2, #0x13
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #0xe0
	lsls r1, r1, #0xb
	ands r1, r2
	lsrs r1, r1, #0x10
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	bx lr
.L080D3E60: .4byte 0x0203BB6C @ EWRAM+0x3BB6C

	thumb_func_start sub_080D3E64
sub_080D3E64: @ 0x080D3E64
.L080D3E64:
	ldr r1, .L080D3E84
	ldr r0, .L080D3E88
	str r0, [r1]
	ldr r0, .L080D3E8C
	str r0, [r1, #4]
	ldr r0, .L080D3E90
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080D3E94
	str r0, [r1]
	ldr r0, .L080D3E98
	str r0, [r1, #4]
	ldr r0, .L080D3E9C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L080D3E84: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D3E88: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D3E8C: .4byte 0x06006000 @ VRAM+0x6000
.L080D3E90: .4byte 0x84000800
.L080D3E94: .4byte gUnknown_081B5810
.L080D3E98: .4byte 0x06012F00 @ VRAM+0x12F00
.L080D3E9C: .4byte 0x84000018

	thumb_func_start sub_080D3EA0
sub_080D3EA0: @ 0x080D3EA0
	push {lr}
	ldr r1, .L080D3EBC
	ldr r0, .L080D3EC0
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080D3EC4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080D3E64
	pop {r0}
	bx r0
.L080D3EBC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D3EC0: .4byte 0x02000800 @ EWRAM+0x800
.L080D3EC4: .4byte 0x84000060

	thumb_func_start sub_080D3EC8
sub_080D3EC8: @ 0x080D3EC8
	sub sp, #4
	movs r2, #0
	str r2, [sp]
	ldr r0, .L080D3EF4
	mov r1, sp
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, .L080D3EF8
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r2, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080D3EFC
	str r1, [r0, #4]
	ldr r1, .L080D3F00
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	add sp, #4
	bx lr
.L080D3EF4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D3EF8: .4byte 0x85000060
.L080D3EFC: .4byte 0x06006000 @ VRAM+0x6000
.L080D3F00: .4byte 0x85000800

	thumb_func_start sub_080D3F04
sub_080D3F04: @ 0x080D3F04
.L080D3F04:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r1, #0
	str r2, [sp, #0x18]
	movs r0, #0x8a
	mov r8, r0
	movs r6, #0xd
	lsls r4, r5, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_080BF648
	adds r7, r0, #0
	adds r0, r5, #0
	bl sub_0815B864
	mov sb, r0
	adds r0, r4, #0
	bl sub_080D45B8
	mov sl, r0
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r1, .L080D3F8C
	ldr r2, .L080D3F90
	add r0, sp, #0x10
	bl CpuSet
	str r4, [sp, #0x14]
	add r0, sp, #0x14
	ldr r5, .L080D3F94
	ldr r2, .L080D3F98
	adds r1, r5, #0
	bl CpuSet
	ldr r0, .L080D3F9C
	movs r2, #0x80
	lsls r2, r2, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x1e
	str r1, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080D3FA0
	movs r1, #0x8a
	movs r2, #0xd
	movs r3, #4
	bl sub_080CCE5C
	ldrb r0, [r7, #1]
	cmp r0, #9
	bhi .L080D3FA4
	movs r1, #0xdc
	movs r2, #0xd
	movs r3, #0
	bl sub_080CCF44
	b .L080D3FB0
	.byte 0x00, 0x00
.L080D3F8C: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D3F90: .4byte 0x05000800
.L080D3F94: .4byte 0x02000800 @ EWRAM+0x800
.L080D3F98: .4byte 0x05000200 @ PLTT+0x200
.L080D3F9C: .4byte gUnknown_081B93B0
.L080D3FA0: .4byte gUnknown_084F367C
.L080D3FA4:
	ldrb r0, [r7, #1]
	movs r1, #0xdc
	movs r2, #0xd
	movs r3, #0
	bl sub_080CCF44
.L080D3FB0:
	adds r0, r6, #0
	adds r0, #0xa
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L080D3FD4
	mov r1, r8
	adds r2, r6, #0
	movs r3, #4
	bl sub_080CCE5C
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0xc
	bgt .L080D3FDC
	ldr r0, .L080D3FD8
	mov r1, r8
	adds r1, #0x32
	b .L080D3FE6
.L080D3FD4: .4byte gUnknown_084F3680
.L080D3FD8: .4byte gUnknown_084F3684
.L080D3FDC:
	cmp r0, #0x1a
	bgt .L080D3FF4
	ldr r0, .L080D3FF0
	mov r1, r8
	adds r1, #0x22
.L080D3FE6:
	adds r2, r6, #0
	movs r3, #0
	bl sub_080CCE5C
	b .L080D4002
.L080D3FF0: .4byte gUnknown_084F368C
.L080D3FF4:
	ldr r0, .L080D4018
	mov r1, r8
	adds r1, #0x3a
	adds r2, r6, #0
	movs r3, #0
	bl sub_080CCE5C
.L080D4002:
	adds r0, r6, #0
	adds r0, #0xa
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r0, sb
	cmp r0, #0
	bne .L080D4020
	ldr r0, .L080D401C
	mov r1, r8
	adds r1, #0x42
	b .L080D402C
.L080D4018: .4byte gUnknown_084F3694
.L080D401C: .4byte gUnknown_084F369C
.L080D4020:
	mov r0, sb
	cmp r0, #1
	bne .L080D403C
	ldr r0, .L080D4038
	mov r1, r8
	adds r1, #0x22
.L080D402C:
	adds r2, r6, #0
	movs r3, #0
	bl sub_080CCE5C
	b .L080D4050
	.byte 0x00, 0x00
.L080D4038: .4byte gUnknown_084F368C
.L080D403C:
	mov r0, sb
	cmp r0, #2
	bne .L080D4050
	ldr r0, .L080D4084
	mov r1, r8
	adds r1, #0x32
	adds r2, r6, #0
	movs r3, #0
	bl sub_080CCE5C
.L080D4050:
	adds r0, r6, #0
	adds r0, #0xa
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L080D4088
	mov r1, r8
	adds r2, r6, #0
	movs r3, #4
	bl sub_080CCE5C
	mov r1, r8
	adds r1, #0x52
	mov r0, sl
	adds r2, r6, #0
	movs r3, #0
	bl sub_080CCF44
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne .L080D4090
	ldr r0, .L080D408C
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080D4098
	.byte 0x00, 0x00
.L080D4084: .4byte gUnknown_084F36A0
.L080D4088: .4byte gUnknown_084F36A8
.L080D408C: .4byte sub_080D3EA0
.L080D4090:
	ldr r0, .L080D40A8
	movs r1, #1
	bl VBlankTask_AddCounted
.L080D4098:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080D40A8: .4byte sub_080D3E64

	thumb_func_start sub_080D40AC
sub_080D40AC: @ 0x080D40AC
	ldr r1, .L080D40CC
	ldr r0, .L080D40D0
	str r0, [r1]
	ldr r0, .L080D40D4
	str r0, [r1, #4]
	ldr r0, .L080D40D8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080D40DC
	str r0, [r1]
	ldr r0, .L080D40E0
	str r0, [r1, #4]
	ldr r0, .L080D40E4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L080D40CC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D40D0: .4byte 0x02000000 @ EWRAM
.L080D40D4: .4byte 0x06001000 @ VRAM+0x1000
.L080D40D8: .4byte 0x84000200
.L080D40DC: .4byte gUnknown_081B5810
.L080D40E0: .4byte 0x06012F00 @ VRAM+0x12F00
.L080D40E4: .4byte 0x84000018

	thumb_func_start sub_080D40E8
sub_080D40E8: @ 0x080D40E8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x1c
	mov r8, r0
	mov r5, r8
	adds r5, #0x24
	ldr r6, .L080D4174
	movs r4, #0
	str r4, [sp, #0x14]
	ldr r2, .L080D4178
	add r0, sp, #0x14
	adds r1, r6, #0
	bl CpuSet
	ldrh r1, [r5, #0xe]
	adds r0, r6, #0
	bl sub_080D45F0
	strh r0, [r5, #0xc]
	str r4, [sp, #0x18]
	add r0, sp, #0x18
	ldr r5, .L080D417C
	ldr r2, .L080D4180
	adds r1, r5, #0
	bl CpuSet
	ldr r0, .L080D4184
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r2, #0x1c
	str r2, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectStride
	ldr r0, .L080D4188
	movs r1, #0x16
	str r1, [sp]
	movs r1, #6
	str r1, [sp, #4]
	movs r1, #8
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080D418C
	movs r1, #1
	bl VBlankTask_AddCounted
	ldrh r1, [r6]
	mov r0, r8
	movs r2, #0
	bl sub_080D3F04
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D4174: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080D4178: .4byte 0x05000040 @ PLTT+0x40
.L080D417C: .4byte 0x02000000 @ EWRAM
.L080D4180: .4byte 0x05000200 @ PLTT+0x200
.L080D4184: .4byte gUnknown_08770A24
.L080D4188: .4byte gUnknown_081B8170
.L080D418C: .4byte sub_080D40AC

	thumb_func_start sub_080D4190
sub_080D4190: @ 0x080D4190
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r0, #0x24
	mov sb, r0
	ldrh r0, [r0, #0xc]
	mov sl, r0
	mov r0, sb
	ldrh r1, [r0, #8]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0
	movs r2, #0
	movs r3, #0xc
	bl sub_080C49EC
	movs r4, #0
.L080D41C4:
	mov r1, sb
	ldrh r0, [r1, #0xa]
	adds r0, r0, r4
	lsls r0, r0, #1
	ldr r1, .L080D4290
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r4, #1
	mov r8, r1
	mov r1, sl
	subs r1, #1
	str r1, [sp, #0xc]
	cmp r0, #0
	beq .L080D4216
	bl sub_080BF648
	movs r6, #0
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, #2
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	movs r1, #0xc
	lsls r5, r1, #0x10
	adds r4, r0, #0
	adds r4, #0x22
.L080D41FA:
	ldrh r0, [r4]
	lsrs r3, r5, #0x10
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
	movs r0, #0xc0
	lsls r0, r0, #0xc
	adds r5, r5, r0
	adds r4, #2
	adds r6, #1
	cmp r6, #7
	bls .L080D41FA
.L080D4216:
	mov r4, r8
	cmp r4, #5
	bls .L080D41C4
	ldr r0, .L080D4294
	movs r1, #0xb8
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0xb2
	str r1, [sp, #4]
	movs r1, #0x35
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D4298
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xb8
	movs r2, #0x35
	movs r3, #0
	bl sub_080C8048
	mov r1, sb
	ldrh r0, [r1, #0xa]
	cmp r0, #0
	beq .L080D4262
	movs r2, #0xc
	adds r2, #0x6e
	movs r3, #2
	adds r3, #2
	movs r0, #0
	movs r1, #0
	bl sub_080C4A4C
.L080D4262:
	mov r1, sb
	ldrh r0, [r1, #0xa]
	adds r0, #6
	ldr r1, [sp, #0xc]
	cmp r0, r1
	bgt .L080D427E
	movs r2, #0xc
	adds r2, #0x6e
	movs r3, #2
	adds r3, #0x44
	movs r0, #0
	movs r1, #0
	bl sub_080C4AB0
.L080D427E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D4290: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080D4294: .4byte gUnknown_08002A94
.L080D4298: .4byte 0x0000011F

	thumb_func_start sub_080D429C
sub_080D429C: @ 0x080D429C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	ldr r0, .L080D430C
	mov sb, r0
	ldrh r6, [r4, #0xc]
	movs r1, #0
	mov r8, r1
	mov r0, r8
	strh r0, [r5, #0x1c]
	strh r0, [r5, #0x1e]
	mov sl, r6
	cmp r6, #5
	bls .L080D42C6
	movs r1, #6
	mov sl, r1
.L080D42C6:
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080D42D2
	b .L080D4492
.L080D42D2:
	bl sub_080B098C
	cmp r0, #1
	bne .L080D42DC
	b .L080D4492
.L080D42DC:
	ldr r2, .L080D4310
	ldrh r1, [r2]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq .L080D431C
	ldrh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	adds r0, r0, r1
	lsls r0, r0, #1
	add r0, sb
	ldrh r4, [r0]
	movs r0, #0x65
	bl sub_080C51D4
	strh r7, [r5, #0x1e]
	strh r7, [r5, #0x1c]
	ldr r0, .L080D4314
	mov r1, r8
	str r1, [r0]
	ldr r0, .L080D4318
	strh r4, [r0]
	b .L080D4492
.L080D430C: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080D4310: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D4314: .4byte 0x030031CC @ IWRAM+0x31CC
.L080D4318: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080D431C:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080D4348
	movs r0, #0x66
	bl sub_080C51D4
	strh r7, [r5, #0x1c]
	ldr r0, .L080D4340
	strh r0, [r5, #0x1e]
	ldr r0, .L080D4344
	str r7, [r0]
	movs r0, #0xb1
	lsls r0, r0, #1
	bl Flag_Clear
	b .L080D4492
.L080D4340: .4byte 0x0000FFFF
.L080D4344: .4byte 0x030031CC @ IWRAM+0x31CC
.L080D4348:
	ldr r1, .L080D4360
	ldrh r2, [r1]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L080D436E
	ldrh r0, [r4, #8]
	cmp r0, #0
	beq .L080D4364
	subs r0, #1
	b .L080D4386
	.byte 0x00, 0x00
.L080D4360: .4byte 0x03003964 @ IWRAM+0x3964
.L080D4364:
	ldrh r0, [r4, #0xa]
	cmp r0, #0
	beq .L080D43AA
	subs r0, #1
	b .L080D43A2
.L080D436E:
	movs r0, #0x80
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq .L080D43C0
	ldrh r1, [r4, #8]
	mov r0, sl
	subs r0, #1
	cmp r1, r0
	beq .L080D4390
	adds r0, r1, #1
.L080D4386:
	strh r0, [r4, #8]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080D43AA
.L080D4390:
	cmp r1, #5
	bne .L080D43AA
	ldrh r2, [r4, #0xa]
	adds r0, r1, r2
	adds r0, #1
	subs r1, r6, #1
	cmp r0, r1
	bgt .L080D43AA
	adds r0, r2, #1
.L080D43A2:
	strh r0, [r4, #0xa]
	movs r0, #0x64
	bl sub_080C51D4
.L080D43AA:
	ldrh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	adds r0, r0, r1
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	adds r0, r5, #0
	movs r2, #0
	bl sub_080D3F04
	b .L080D4492
.L080D43C0:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080D4420
	cmp r6, #6
	bls .L080D4420
	ldrh r6, [r4, #8]
	ldrh r7, [r4, #0xa]
	adds r1, r6, #0
	adds r2, r6, #0
	adds r0, r7, #0
	cmp r1, #0
	beq .L080D43E0
	strh r3, [r4, #8]
	b .L080D43EC
.L080D43E0:
	cmp r0, #4
	bls .L080D43FC
	subs r0, #5
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #0xa]
	adds r0, r2, r0
.L080D43EC:
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	adds r0, r5, #0
	movs r2, #0
	bl sub_080D3F04
	b .L080D440C
.L080D43FC:
	strh r1, [r4, #0xa]
	lsls r0, r2, #1
	add r0, sb
	ldrh r1, [r0]
	adds r0, r5, #0
	movs r2, #0
	bl sub_080D3F04
.L080D440C:
	ldrh r0, [r4, #8]
	cmp r6, r0
	bne .L080D4418
	ldrh r4, [r4, #0xa]
	cmp r7, r4
	beq .L080D4492
.L080D4418:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080D4492
.L080D4420:
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080D4492
	cmp r6, #6
	bls .L080D4492
	ldrh r7, [r4, #8]
	ldrh r1, [r4, #0xa]
	mov r8, r1
	cmp r7, #5
	beq .L080D4444
	movs r0, #5
	strh r0, [r4, #8]
	mov r0, r8
	adds r0, #5
	b .L080D445A
.L080D4444:
	mov r1, r8
	adds r0, r7, r1
	adds r0, #6
	subs r1, r6, #1
	cmp r0, r1
	bge .L080D446A
	mov r0, r8
	adds r0, #6
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #0xa]
	adds r0, r7, r0
.L080D445A:
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	adds r0, r5, #0
	movs r2, #0
	bl sub_080D3F04
	b .L080D4480
.L080D446A:
	subs r0, r6, #6
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #0xa]
	adds r0, r7, r0
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	adds r0, r5, #0
	movs r2, #0
	bl sub_080D3F04
.L080D4480:
	ldrh r0, [r4, #8]
	cmp r7, r0
	bne .L080D448C
	ldrh r4, [r4, #0xa]
	cmp r8, r4
	beq .L080D4492
.L080D448C:
	movs r0, #0x64
	bl sub_080C51D4
.L080D4492:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080D44A0
sub_080D44A0: @ 0x080D44A0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, .L080D44D4
	ldr r1, .L080D44D8
	bl Task_Create
	adds r6, r0, #0
	ldr r5, .L080D44DC
	movs r0, #0
	str r0, [sp]
	ldr r2, .L080D44E0
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	ldrh r0, [r4, #0xa]
	ldrh r1, [r4, #8]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	bne .L080D44E4
	movs r0, #0xb
	b .L080D44E6
.L080D44D4: .4byte gUnknown_084F1514
.L080D44D8: .4byte 0x0000FFFF
.L080D44DC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D44E0: .4byte 0x05000200 @ PLTT+0x200
.L080D44E4:
	movs r0, #0xc
.L080D44E6:
	strh r0, [r5]
	movs r1, #0
	strh r1, [r5, #0x22]
	str r6, [r4, #4]
	ldr r0, .L080D44FC
	str r1, [r0]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D44FC: .4byte 0x03003BB4 @ IWRAM+0x3BB4

	thumb_func_start sub_080D4500
sub_080D4500: @ 0x080D4500
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x28]
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080D4510
	movs r0, #1
	b .L080D4512
.L080D4510:
	movs r0, #0
.L080D4512:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080D4518
sub_080D4518: @ 0x080D4518
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080D4548
	ldr r2, .L080D454C
	mov r0, sp
	bl CpuSet
	ldr r0, .L080D4550
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080D4554
	movs r1, #1
	bl VBlankTask_AddCounted
	bl sub_080C6558
	bl sub_080C6764
	add sp, #4
	pop {r0}
	bx r0
.L080D4548: .4byte 0x02000000 @ EWRAM
.L080D454C: .4byte 0x05000200 @ PLTT+0x200
.L080D4550: .4byte sub_080D40AC
.L080D4554: .4byte sub_080D3EC8

	thumb_func_start sub_080D4558
sub_080D4558: @ 0x080D4558
	ldrb r1, [r0, #6]
	strh r1, [r0, #0x1c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D4560
sub_080D4560: @ 0x080D4560
.L080D4560:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080D4584
	ldr r1, .L080D4588
	bl Task_Create
	ldr r1, .L080D458C
	str r0, [r1]
	movs r1, #0
	strh r4, [r0, #0x32]
	ldr r0, .L080D4590
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D4584: .4byte gUnknown_084F36B0
.L080D4588: .4byte 0x0000FFFF
.L080D458C: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080D4590: .4byte 0x03003BB4 @ IWRAM+0x3BB4

	thumb_func_start sub_080D4594
sub_080D4594: @ 0x080D4594
.L080D4594:
	push {lr}
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	movs r1, #0
	ldr r0, .L080D45B4
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080D45AC
	movs r1, #1
.L080D45AC:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080D45B4: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D45B8
sub_080D45B8: @ 0x080D45B8
.L080D45B8:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r2, .L080D45DC
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x11
	bhi .L080D45E8
	ldr r2, .L080D45E0
	ldr r0, .L080D45E4
	adds r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	b .L080D45EC
.L080D45DC: .4byte 0xFE960000
.L080D45E0: .4byte gUnknown_084F3754
.L080D45E4: .4byte 0xFFFFFE96
.L080D45E8:
	movs r0, #1
	rsbs r0, r0, #0
.L080D45EC:
	pop {r1}
	bx r1

	thumb_func_start sub_080D45F0
sub_080D45F0: @ 0x080D45F0
.L080D45F0:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	lsls r1, r1, #0x10
	movs r5, #0
	movs r6, #0
	ldr r4, .L080D466C
	cmp r1, #0
	bne .L080D46D8
	ldr r0, .L080D4670
	bl sub_080C32D4
	movs r0, #0xb1
	lsls r0, r0, #1
	bl Flag_Test
	cmp r0, #0
	bne .L080D4674
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L080D4708
	adds r6, r1, #0
.L080D4624:
	ldrh r0, [r4, #2]
	bl sub_080C3560
	cmp r0, #0
	bne .L080D465E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne .L080D465E
	ldrh r0, [r4, #4]
	cmp r0, #0
	beq .L080D4642
	bl sub_080C3560
	cmp r0, #0
	bne .L080D465E
.L080D4642:
	ldrh r0, [r4, #6]
	cmp r0, #0
	beq .L080D4650
	bl sub_080C3560
	cmp r0, #0
	bne .L080D465E
.L080D4650:
	lsls r0, r5, #1
	adds r0, r0, r7
	ldrh r1, [r4, #2]
	strh r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080D465E:
	adds r4, #0xc
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, r6
	bne .L080D4624
	b .L080D4708
	.byte 0x00, 0x00
.L080D466C: .4byte gUnknown_084F3754
.L080D4670: .4byte 0x0000011F
.L080D4674:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L080D4708
	mov r8, r1
.L080D4682:
	ldrh r0, [r4, #2]
	bl sub_080C3560
	cmp r0, #0
	bne .L080D46C6
	ldrh r0, [r4, #8]
	cmp r0, #0
	beq .L080D46C6
	ldrh r0, [r4, #4]
	cmp r0, #0
	beq .L080D46A0
	bl sub_080C3560
	cmp r0, #0
	bne .L080D46C6
.L080D46A0:
	ldrh r0, [r4, #6]
	cmp r0, #0
	beq .L080D46AE
	bl sub_080C3560
	cmp r0, #0
	bne .L080D46C6
.L080D46AE:
	adds r0, r6, #0
	bl sub_080D3E44
	cmp r0, #0
	beq .L080D46C6
	lsls r0, r5, #1
	adds r0, r0, r7
	ldrh r1, [r4, #2]
	strh r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080D46C6:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r4, #0xc
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, r8
	bne .L080D4682
	b .L080D4708
.L080D46D8:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L080D4708
	adds r6, r1, #0
.L080D46E6:
	ldrh r0, [r4, #2]
	bl sub_080C3560
	cmp r0, #0
	beq .L080D46FE
	lsls r0, r5, #1
	adds r0, r0, r7
	ldrh r1, [r4, #2]
	strh r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080D46FE:
	adds r4, #0xc
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, r6
	bne .L080D46E6
.L080D4708:
	adds r0, r5, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080D4714
sub_080D4714: @ 0x080D4714
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r1, [r0, #0x1e]
	movs r2, #0
	strh r1, [r0, #0x24]
	strh r2, [r4, #2]
	bl sub_080C2244
	movs r1, #0xff
	ands r1, r0
	cmp r1, #0
	bne .L080D473C
	movs r0, #0xfb
	bl sub_080C3560
	cmp r0, #0
	bne .L080D473C
	movs r0, #0xfb
	strh r0, [r4, #2]
.L080D473C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D4744
sub_080D4744: @ 0x080D4744
	push {r4, lr}
	adds r4, r0, #0
	bl Task_GetParent
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080D4756
	movs r0, #0
	b .L080D4758
.L080D4756:
	movs r0, #1
.L080D4758:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080D4760
sub_080D4760: @ 0x080D4760
	push {lr}
	movs r0, #0xd1
	movs r1, #0
	movs r2, #0x81
	movs r3, #0
	bl sub_080ECA60
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D4774
sub_080D4774: @ 0x080D4774
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080ECB10
	cmp r0, #1
	beq .L080D4782
	movs r0, #0
.L080D4782:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D478C
sub_080D478C: @ 0x080D478C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	movs r0, #0x86
	lsls r0, r0, #1
	bl Flag_Set
	ldrh r1, [r5, #2]
	cmp r1, #0
	bne .L080D47B0
	ldr r1, .L080D47AC
	ldrh r0, [r4, #0x24]
	strh r0, [r1]
	b .L080D47B4
.L080D47AC: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080D47B0:
	ldr r0, .L080D47D0
	strh r1, [r0]
.L080D47B4:
	ldr r1, .L080D47D4
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r2, #0x50
	movs r3, #4
	bl sub_080C4618
	str r0, [r5, #8]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D47D0: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080D47D4: .4byte 0x000001C1

	thumb_func_start sub_080D47D8
sub_080D47D8: @ 0x080D47D8
	push {lr}
	movs r0, #0xf0
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D47EC
sub_080D47EC: @ 0x080D47EC
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x26]
	cmp r0, #0
	bne .L080D4814
	ldr r0, .L080D480C
	ldrh r1, [r1, #0x24]
	ldr r2, .L080D4810
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #0x1a
	bl sub_080AF178
	b .L080D481C
.L080D480C: .4byte gUnknown_084F3838
.L080D4810: .4byte 0xFFFFFE96
.L080D4814:
	ldr r1, .L080D4820
	movs r0, #0x1a
	bl sub_080AF178
.L080D481C:
	pop {r0}
	bx r0
.L080D4820: .4byte gUnknown_0815C090

	thumb_func_start sub_080D4824
sub_080D4824: @ 0x080D4824
	push {lr}
	bl sub_080C6558
	bl sub_080C6764
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D4834
sub_080D4834: @ 0x080D4834
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080D4844
	ldrh r0, [r0]
	cmp r0, #0x1a
	bne .L080D4848
	movs r0, #1
	b .L080D484A
.L080D4844: .4byte 0x03004550 @ IWRAM+0x4550
.L080D4848:
	movs r0, #0
.L080D484A:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080D4850
sub_080D4850: @ 0x080D4850
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	ldrh r0, [r4, #0x24]
	bl sub_080D45B8
	adds r6, r0, #0
	ldrh r0, [r4, #0x24]
	bl sub_081571DC
	rsbs r0, r0, #0
	bl sub_080C30AC
	cmp r6, #0
	ble .L080D487E
	adds r4, r6, #0
.L080D4872:
	ldr r0, .L080D488C
	bl sub_080C33AC
	subs r4, #1
	cmp r4, #0
	bne .L080D4872
.L080D487E:
	ldrh r0, [r5, #2]
	cmp r0, #0
	bne .L080D4890
	ldrh r0, [r5]
	bl sub_080C062C
	b .L080D4896
.L080D488C: .4byte 0x0000011F
.L080D4890:
	ldrh r0, [r5, #2]
	bl sub_080C062C
.L080D4896:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080D489C
sub_080D489C: @ 0x080D489C
	push {lr}
	ldr r0, [r0, #0x2c]
	cmp r0, #0
	beq .L080D48AA
	movs r1, #0
	bl sub_080C48F0
.L080D48AA:
	ldr r1, .L080D48B8
	movs r0, #0xc
	bl sub_080AF178
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D48B8: .4byte gUnknown_0805C3D0

	thumb_func_start sub_080D48BC
sub_080D48BC: @ 0x080D48BC
	push {lr}
	movs r0, #1
	bl sub_080C51BC
	pop {r0}
	bx r0

	thumb_func_start sub_080D48C8
sub_080D48C8: @ 0x080D48C8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	ldrh r0, [r4, #0x24]
	bl sub_080D45B8
	adds r6, r0, #0
	ldrh r0, [r4, #0x24]
	bl sub_080C3560
	adds r7, r0, #0
	ldrh r0, [r4, #0x24]
	bl sub_081571DC
	rsbs r0, r0, #0
	bl sub_080C30AC
	ldrh r0, [r5, #2]
	cmp r0, #0
	bne .L080D4904
	cmp r6, #0
	ble .L080D4904
	adds r4, r6, #0
.L080D48F8:
	ldr r0, .L080D4914
	bl sub_080C3328
	subs r4, #1
	cmp r4, #0
	bne .L080D48F8
.L080D4904:
	ldrb r0, [r7, #0xc]
	movs r1, #1
	bl sub_080C0290
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D4914: .4byte 0x0000011F

	thumb_func_start sub_080D4918
sub_080D4918: @ 0x080D4918
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x26]
	cmp r0, #0
	bne .L080D4940
	ldr r1, .L080D4938
	movs r0, #0x1a
	bl sub_080AF178
	ldr r4, .L080D493C
	ldrh r0, [r5, #0x24]
	bl sub_080D45B8
	str r0, [r4]
	b .L080D4948
	.byte 0x00, 0x00
.L080D4938: .4byte gUnknown_0815C0DE
.L080D493C: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L080D4940:
	ldr r1, .L080D4950
	movs r0, #0x1a
	bl sub_080AF178
.L080D4948:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D4950: .4byte gUnknown_0815C110

	thumb_func_start sub_080D4954
sub_080D4954: @ 0x080D4954
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	movs r0, #0x86
	lsls r0, r0, #1
	bl Flag_Set
	ldr r1, .L080D4988
	ldrh r0, [r4, #0x24]
	movs r2, #0
	strh r0, [r1]
	ldr r1, .L080D498C
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0
	movs r2, #0x50
	movs r3, #4
	bl sub_080C4618
	str r0, [r5, #8]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D4988: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080D498C: .4byte 0x000001C1

	thumb_func_start sub_080D4990
sub_080D4990: @ 0x080D4990
	ldr r1, .L080D49A4
	ldr r0, .L080D49A8
	str r0, [r1]
	ldr r0, .L080D49AC
	str r0, [r1, #4]
	ldr r0, .L080D49B0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D49A4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D49A8: .4byte 0x06016000 @ VRAM+0x16000
.L080D49AC: .4byte 0x02001000 @ EWRAM+0x1000
.L080D49B0: .4byte 0x84000400

	thumb_func_start sub_080D49B4
sub_080D49B4: @ 0x080D49B4
	push {lr}
	ldr r0, .L080D49C4
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D49C4: .4byte sub_080D4990

	thumb_func_start sub_080D49C8
sub_080D49C8: @ 0x080D49C8
	ldr r1, .L080D49DC
	ldr r0, .L080D49E0
	str r0, [r1]
	ldr r0, .L080D49E4
	str r0, [r1, #4]
	ldr r0, .L080D49E8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D49DC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D49E0: .4byte 0x02001000 @ EWRAM+0x1000
.L080D49E4: .4byte 0x06016000 @ VRAM+0x16000
.L080D49E8: .4byte 0x84000400

	thumb_func_start sub_080D49EC
sub_080D49EC: @ 0x080D49EC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x24
	ldrh r0, [r4, #4]
	cmp r0, #3
	bhi .L080D4A78
	ldr r3, .L080D4A6C
	movs r5, #0
	ldr r0, .L080D4A70
	mov ip, r0
	ldr r7, .L080D4A74
.L080D4A04:
	ldrh r0, [r4, #4]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldm r2!, {r1}
	ands r0, r1
	stm r3!, {r0}
	ldr r0, [r3]
	ldr r1, [r2]
	ands r0, r1
	stm r3!, {r0}
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x77
	bls .L080D4A04
	mov r0, ip
	movs r1, #1
	bl VBlankTask_AddCounted
	ldrh r0, [r4, #4]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #4]
	strh r1, [r6, #0x1c]
	b .L080D4A7C
	.byte 0x00, 0x00
.L080D4A6C: .4byte 0x02001000 @ EWRAM+0x1000
.L080D4A70: .4byte sub_080D49C8
.L080D4A74: .4byte gUnknown_087F02B8
.L080D4A78:
	movs r0, #1
	strh r0, [r6, #0x1c]
.L080D4A7C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D4A84
sub_080D4A84: @ 0x080D4A84
	ldr r1, .L080D4A98
	ldr r0, .L080D4A9C
	str r0, [r1]
	ldr r0, .L080D4AA0
	str r0, [r1, #4]
	ldr r0, .L080D4AA4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D4A98: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D4A9C: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080D4AA0: .4byte 0x06015000 @ VRAM+0x15000
.L080D4AA4: .4byte 0x84000400

	thumb_func_start sub_080D4AA8
sub_080D4AA8: @ 0x080D4AA8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	ldr r0, .L080D4B24
	mov r8, r0
	ldr r0, .L080D4B28
	ldr r4, .L080D4B2C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080D4B30
	ldr r0, .L080D4B34
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #4
	adds r4, r4, r0
	str r4, [r1, #4]
	ldr r0, .L080D4B38
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r4, .L080D4B3C
	ldr r5, .L080D4B40
	movs r6, #0x10
	str r6, [sp]
	movs r0, #3
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0x60
	bl Palette_CopyWithEffect
	adds r4, #0x60
	adds r5, #0x80
	str r6, [sp]
	movs r0, #3
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080D4B44
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #2
	bl Window_Create
	mov r1, r8
	str r0, [r1, #0x14]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D4B24: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D4B28: .4byte gUnknown_084F3AF0
.L080D4B2C: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080D4B30: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D4B34: .4byte gUnknown_081B5710
.L080D4B38: .4byte 0x84000040
.L080D4B3C: .4byte gUnknown_084F3F30
.L080D4B40: .4byte 0x03003110 @ IWRAM+0x3110
.L080D4B44: .4byte sub_080D4A84

	thumb_func_start sub_080D4B48
sub_080D4B48: @ 0x080D4B48
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, .L080D4B7C
	ldrh r4, [r5, #0xc]
	cmp r4, #1
	bne .L080D4B74
	str r4, [sp]
	movs r0, #0x17
	movs r1, #0
	movs r2, #6
	movs r3, #3
	bl TextWindow_CreateOpen
	str r0, [r5, #0x28]
	str r4, [sp]
	movs r0, #0x17
	movs r1, #6
	movs r2, #6
	movs r3, #5
	bl TextWindow_CreateOpen
	str r0, [r5, #0x2c]
.L080D4B74:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D4B7C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D4B80
sub_080D4B80: @ 0x080D4B80
.L080D4B80:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r2, .L080D4BA0
	movs r3, #0xc
	ldrh r0, [r2, #0xa]
	cmp r0, #0
	beq .L080D4B92
	movs r3, #0xd
.L080D4B92:
	cmp r1, #0xa
	bhi .L080D4C50
	lsls r0, r1, #2
	ldr r1, .L080D4BA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080D4BA0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D4BA4: .4byte gUnknown_080D4BA8
	.global gUnknown_080D4BA8
gUnknown_080D4BA8:
.L080D4BA8: @ jump table
	.4byte .L080D4BD4
	.4byte .L080D4BDC
	.4byte .L080D4BE4
	.4byte .L080D4BEC
	.4byte .L080D4BFC
	.4byte .L080D4C04
	.4byte .L080D4C0C
	.4byte .L080D4C1A
	.4byte .L080D4C22
	.4byte .L080D4C2A
	.4byte .L080D4C38
.L080D4BD4:
	ldrh r0, [r2, #0xe]
	cmp r0, #0
	bne .L080D4C50
	b .L080D4C4A
.L080D4BDC:
	ldrh r0, [r2, #0xe]
	cmp r0, #0
	bne .L080D4C50
	b .L080D4BF2
.L080D4BE4:
	ldrh r0, [r2, #0xe]
	cmp r0, #1
	bne .L080D4C50
	b .L080D4BF2
.L080D4BEC:
	ldrh r0, [r2, #0xe]
	cmp r0, #2
	bne .L080D4C50
.L080D4BF2:
	ldrh r0, [r2, #0x10]
	cmp r0, #2
	bne .L080D4C50
.L080D4BF8:
	adds r0, r3, #0
	b .L080D4C52
.L080D4BFC:
	ldrh r0, [r2, #0xe]
	cmp r0, #0
	bne .L080D4C50
	b .L080D4C12
.L080D4C04:
	ldrh r0, [r2, #0xe]
	cmp r0, #1
	bne .L080D4C50
	b .L080D4C12
.L080D4C0C:
	ldrh r0, [r2, #0xe]
	cmp r0, #2
	bne .L080D4C50
.L080D4C12:
	ldrh r0, [r2, #0x10]
	cmp r0, #1
	bne .L080D4C50
	b .L080D4BF8
.L080D4C1A:
	ldrh r0, [r2, #0xe]
	cmp r0, #0
	bne .L080D4C50
	b .L080D4C30
.L080D4C22:
	ldrh r0, [r2, #0xe]
	cmp r0, #1
	bne .L080D4C50
	b .L080D4C30
.L080D4C2A:
	ldrh r0, [r2, #0xe]
	cmp r0, #2
	bne .L080D4C50
.L080D4C30:
	ldrh r0, [r2, #0x10]
	cmp r0, #0
	bne .L080D4C50
	b .L080D4BF8
.L080D4C38:
	ldrh r0, [r2, #0xe]
	adds r1, r0, #0
	cmp r1, #1
	bne .L080D4C46
	ldrh r0, [r2, #0x10]
	cmp r0, #3
	beq .L080D4BF8
.L080D4C46:
	cmp r1, #2
	bne .L080D4C50
.L080D4C4A:
	ldrh r0, [r2, #0x10]
	cmp r0, #3
	beq .L080D4BF8
.L080D4C50:
	movs r0, #0xb
.L080D4C52:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080D4C58
sub_080D4C58: @ 0x080D4C58
.L080D4C58:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r6, .L080D4CF4
	ldr r0, .L080D4CF8
	movs r5, #0xbe
	lsls r5, r5, #2
	str r5, [sp]
	movs r4, #0xba
	str r4, [sp, #4]
	movs r1, #3
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_080C31F0
	movs r1, #0xb8
	movs r2, #0xb
	movs r3, #0
	bl sub_080C8048
	ldr r0, .L080D4CFC
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0x33
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D4D00
	movs r1, #1
	str r1, [sp]
	movs r1, #0xb8
	str r1, [sp, #4]
	movs r1, #0x3b
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D4D04
	ldr r1, .L080D4D08
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xb8
	movs r2, #0x3b
	movs r3, #0
	bl sub_080C8048
	ldr r0, .L080D4D0C
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D4D10
	ldr r1, [r0]
	ldr r0, [r6, #0x18]
	muls r0, r1, r0
	movs r1, #0xb8
	movs r2, #0x4b
	movs r3, #0
	bl sub_080C8048
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D4CF4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D4CF8: .4byte gUnknown_08002A4C
.L080D4CFC: .4byte gUnknown_08002A64
.L080D4D00: .4byte gUnknown_0800080C
.L080D4D04: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080D4D08: .4byte 0x00000AD8
.L080D4D0C: .4byte gUnknown_08002A7C
.L080D4D10: .4byte 0x030037F0 @ IWRAM+0x37F0

	thumb_func_start sub_080D4D14
sub_080D4D14: @ 0x080D4D14
.L080D4D14:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r0, #0
.L080D4D22:
	movs r6, #0
	lsls r1, r0, #1
	adds r2, r0, #1
	mov r8, r2
	adds r0, r1, r0
	lsls r0, r0, #2
	movs r5, #0xc8
	lsls r5, r5, #0xf
	adds r4, r1, r2
	movs r1, #0x82
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L080D4D3C:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080D4B80
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, .L080D4DEC
	mov sb, r0
	lsls r0, r4, #2
	add r0, sb
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #2
	mov sl, r1
	str r1, [sp]
	lsrs r1, r5, #0x10
	str r1, [sp, #4]
	str r7, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl Sprite_Draw
	movs r2, #0xc0
	lsls r2, r2, #0xc
	adds r5, r5, r2
	adds r4, #1
	adds r6, #1
	cmp r6, #2
	bls .L080D4D3C
	mov r0, r8
	cmp r0, #2
	bls .L080D4D22
	movs r0, #0
	bl sub_080D4B80
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r1, sb
	ldr r0, [r1]
	mov r1, sl
	str r1, [sp]
	movs r1, #0x64
	str r1, [sp, #4]
	movs r4, #0x8e
	str r4, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl Sprite_Draw
	movs r0, #0xa
	bl sub_080D4B80
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r1, sb
	ldr r0, [r1, #0x28]
	mov r1, sl
	str r1, [sp]
	movs r1, #0x6e
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D4DF0
	mov r2, sl
	str r2, [sp]
	movs r1, #0x60
	str r1, [sp, #4]
	movs r1, #0x68
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080D4DEC: .4byte gUnknown_084F3FB0
.L080D4DF0: .4byte gUnknown_08002A3C

	thumb_func_start sub_080D4DF4
sub_080D4DF4: @ 0x080D4DF4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r5, .L080D4E68
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	bne .L080D4E78
	ldr r1, [r6, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L080D4E1E
	adds r0, r6, #0
	bl sub_080D4D14
.L080D4E1E:
	ldr r0, .L080D4E6C
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x10
	bl Text_DrawSpriteString
	movs r4, #0
	ldr r0, .L080D4E70
	mov r8, r0
	movs r6, #0xf8
	lsls r6, r6, #0xf
	ldr r7, .L080D4E74
.L080D4E3E:
	ldrh r0, [r5]
	cmp r0, r8
	beq .L080D4E58
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	lsrs r3, r6, #0x10
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
.L080D4E58:
	movs r0, #0xc0
	lsls r0, r0, #0xc
	adds r6, r6, r0
	adds r5, #2
	adds r4, #1
	cmp r4, #3
	bls .L080D4E3E
	b .L080D4F0C
.L080D4E68: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D4E6C: .4byte gUnknown_084F3FDC
.L080D4E70: .4byte 0x0000FFFF
.L080D4E74: .4byte gUnknown_084F4014
.L080D4E78:
	adds r0, r6, #0
	bl sub_080D4D14
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	beq .L080D4EBC
	ldr r0, .L080D4EB4
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x10
	bl Text_DrawSpriteString
	ldr r0, .L080D4EB8
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080D4F06
	movs r0, #0
	movs r1, #0
	movs r2, #0xd6
	movs r3, #0x61
	bl sub_080C4AB0
	b .L080D4F06
.L080D4EB4: .4byte gUnknown_084F3FFC
.L080D4EB8: .4byte 0x030031BC @ IWRAM+0x31BC
.L080D4EBC:
	ldr r0, .L080D4F18
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x10
	bl Text_DrawSpriteString
	movs r4, #0
	adds r5, #0x20
	mov r8, r5
	ldr r7, .L080D4F1C
	movs r5, #0x98
	lsls r5, r5, #0xf
.L080D4EDC:
	mov r0, r8
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0xff
	beq .L080D4EFA
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	lsrs r3, r5, #0x10
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
.L080D4EFA:
	movs r0, #0xc0
	lsls r0, r0, #0xc
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #7
	bls .L080D4EDC
.L080D4F06:
	adds r0, r6, #0
	bl sub_080D4C58
.L080D4F0C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080D4F18: .4byte gUnknown_084F3FF0
.L080D4F1C: .4byte gUnknown_084F4014

	thumb_func_start sub_080D4F20
sub_080D4F20: @ 0x080D4F20
.L080D4F20:
	push {lr}
	ldr r0, .L080D4F38
	movs r1, #0
	adds r2, r0, #0
	adds r2, #0x20
.L080D4F2A:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L080D4F3C
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	b .L080D4F44
.L080D4F38: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D4F3C:
	adds r1, #1
	cmp r1, #7
	bls .L080D4F2A
	movs r0, #0
.L080D4F44:
	pop {r1}
	bx r1

	thumb_func_start sub_080D4F48
sub_080D4F48: @ 0x080D4F48
.L080D4F48:
	push {r4, lr}
	ldr r0, .L080D4F78
	movs r2, #1
	movs r4, #0
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0x27
.L080D4F56:
	ldrb r0, [r1]
	cmp r0, #0xff
	beq .L080D4F66
	muls r0, r2, r0
	adds r4, r4, r0
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r2, r0, #1
.L080D4F66:
	subs r1, #1
	adds r3, #1
	cmp r3, #7
	bls .L080D4F56
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080D4F78: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D4F7C
sub_080D4F7C: @ 0x080D4F7C
.L080D4F7C:
	push {r4, lr}
	ldr r2, .L080D4F9C
	movs r3, #0
	ldr r1, .L080D4FA0
	ldr r4, .L080D4FA4
	adds r1, r1, r4
	ldr r2, [r2, #0x18]
	muls r2, r0, r2
	ldr r0, [r1]
	cmp r0, r2
	blo .L080D4F94
	movs r3, #1
.L080D4F94:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
.L080D4F9C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D4FA0: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080D4FA4: .4byte 0x00000AD8

	thumb_func_start sub_080D4FA8
sub_080D4FA8: @ 0x080D4FA8
.L080D4FA8:
	push {r4, r5, lr}
	movs r5, #0
.L080D4FAC:
	lsls r0, r5, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl sub_080D4B80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	beq .L080D4FC2
	adds r0, r4, #0
	b .L080D4FCA
.L080D4FC2:
	adds r5, #1
	cmp r5, #0xa
	bls .L080D4FAC
	movs r0, #0xa
.L080D4FCA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080D4FD0
sub_080D4FD0: @ 0x080D4FD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r5, .L080D5004
	movs r0, #0
	strh r0, [r7, #0x1c]
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	bne .L080D5078
	ldrh r0, [r5, #0xa]
	cmp r0, #0
	beq .L080D5016
	subs r0, #1
	strh r0, [r5, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080D4FF6
	b .L080D5270
.L080D4FF6:
	ldrh r0, [r5, #8]
	cmp r0, #3
	beq .L080D5008
	adds r0, #1
	strh r0, [r5, #8]
	b .L080D5270
	.byte 0x00, 0x00
.L080D5004: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D5008:
	movs r4, #1
	strh r4, [r7, #0x1c]
	adds r0, r7, #0
	bl Task_GetParent
	str r4, [r0, #0xc]
	b .L080D5270
.L080D5016:
	ldr r2, .L080D503C
	ldrh r1, [r2]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L080D5052
	bl sub_080D4FA8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa
	bne .L080D5040
	strh r4, [r7, #0x1c]
	adds r0, r7, #0
	bl Task_GetParent
	str r4, [r0, #0xc]
	b .L080D515E
.L080D503C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D5040:
	bl sub_080D4FA8
	ldrh r1, [r5, #8]
	lsls r1, r1, #1
	adds r1, r1, r5
	strh r0, [r1]
	movs r0, #0xa
	strh r0, [r5, #0xa]
	b .L080D515E
.L080D5052:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L080D505E
	b .L080D51C4
.L080D505E:
	ldrh r0, [r5, #8]
	cmp r0, #0
	beq .L080D5068
	subs r0, #1
	strh r0, [r5, #8]
.L080D5068:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldr r1, .L080D5074
	strh r1, [r0]
	b .L080D51B8
.L080D5074: .4byte 0x0000FFFF
.L080D5078:
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	beq .L080D50C0
	ldr r0, .L080D50B8
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L080D508C
	b .L080D5270
.L080D508C:
	bl sub_080D4F48
	ldr r1, [r5, #0x18]
	muls r0, r1, r0
	bl sub_080C30AC
	movs r2, #0
	adds r4, r5, #0
	adds r4, #0x20
	movs r3, #0xff
.L080D50A0:
	adds r1, r4, r2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r2, #1
	cmp r2, #7
	bls .L080D50A0
	ldr r1, .L080D50BC
	movs r0, #0
	str r0, [r1]
	strh r0, [r5, #0x1c]
	b .L080D515E
.L080D50B8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D50BC: .4byte 0x030037F0 @ IWRAM+0x37F0
.L080D50C0:
	ldrh r0, [r5, #0xa]
	cmp r0, #0
	beq .L080D50D2
	subs r0, #1
	strh r0, [r5, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080D50D2
	b .L080D5270
.L080D50D2:
	ldr r2, .L080D50F4
	ldrh r1, [r2]
	movs r0, #1
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	beq .L080D5170
	bl sub_080D4FA8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa
	bne .L080D50F8
	mov r0, r8
	strh r0, [r7, #0x1c]
	b .L080D515E
	.byte 0x00, 0x00
.L080D50F4: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D50F8:
	bl sub_080D4F20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl sub_080D4FA8
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r4, #0
	bne .L080D5110
	cmp r6, #0
	beq .L080D515E
.L080D5110:
	bl sub_080D4F48
	ldr r1, [r5, #0x18]
	muls r0, r1, r0
	bl sub_080C30AC
	adds r0, r5, #0
	adds r0, #0x20
	adds r4, r4, r0
	strb r6, [r4]
	bl sub_080D4F48
	bl sub_080D4F7C
	cmp r0, #0
	bne .L080D513A
	movs r0, #0xff
	strb r0, [r4]
	mov r0, r8
	strh r0, [r5, #0x1c]
	b .L080D5150
.L080D513A:
	movs r0, #0xa
	strh r0, [r5, #0xa]
	bl sub_080D4F48
	ldr r1, .L080D5168
	str r0, [r1]
	ldr r1, .L080D516C
	cmp r0, r1
	bls .L080D5150
	mov r0, r8
	strh r0, [r7, #0x1c]
.L080D5150:
	bl sub_080D4F48
	ldr r1, [r5, #0x18]
	muls r0, r1, r0
	rsbs r0, r0, #0
	bl sub_080C30AC
.L080D515E:
	movs r0, #0x65
	bl sub_080C51D4
	b .L080D5270
	.byte 0x00, 0x00
.L080D5168: .4byte 0x030037F0 @ IWRAM+0x37F0
.L080D516C: .4byte 0x0000C34F
.L080D5170:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080D51C4
	bl sub_080D4F20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L080D518C
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L080D518C:
	bl sub_080D4F48
	ldr r1, [r5, #0x18]
	muls r0, r1, r0
	bl sub_080C30AC
	adds r0, r5, #0
	adds r0, #0x20
	adds r0, r4, r0
	movs r1, #0xff
	strb r1, [r0]
	bl sub_080D4F48
	ldr r1, [r5, #0x18]
	muls r0, r1, r0
	rsbs r0, r0, #0
	bl sub_080C30AC
	bl sub_080D4F48
	ldr r1, .L080D51C0
	str r0, [r1]
.L080D51B8:
	movs r0, #0x66
	bl sub_080C51D4
	b .L080D5270
.L080D51C0: .4byte 0x030037F0 @ IWRAM+0x37F0
.L080D51C4:
	ldr r0, .L080D51E0
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L080D51F0
	ldrh r0, [r5, #0x10]
	cmp r0, #0
	beq .L080D51E4
	subs r0, #1
	b .L080D51E6
	.byte 0x00, 0x00
.L080D51E0: .4byte 0x03003964 @ IWRAM+0x3964
.L080D51E4:
	movs r0, #3
.L080D51E6:
	strh r0, [r5, #0x10]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080D520C
.L080D51F0:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080D520C
	ldrh r0, [r5, #0x10]
	cmp r0, #3
	beq .L080D5204
	adds r0, #1
	strh r0, [r5, #0x10]
	b .L080D5206
.L080D5204:
	strh r2, [r5, #0x10]
.L080D5206:
	movs r0, #0x64
	bl sub_080C51D4
.L080D520C:
	ldr r0, .L080D5238
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L080D5248
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	beq .L080D523C
	subs r1, r0, #1
	strh r1, [r5, #0xe]
	ldrh r0, [r5, #0x10]
	cmp r0, #3
	bne .L080D5240
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080D5240
	movs r0, #0
	b .L080D523E
.L080D5238: .4byte 0x03003964 @ IWRAM+0x3964
.L080D523C:
	movs r0, #2
.L080D523E:
	strh r0, [r5, #0xe]
.L080D5240:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080D5270
.L080D5248:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080D5270
	ldrh r0, [r5, #0xe]
	cmp r0, #2
	beq .L080D5268
	adds r1, r0, #1
	strh r1, [r5, #0xe]
	ldrh r0, [r5, #0x10]
	cmp r0, #3
	bne .L080D526A
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bne .L080D526A
.L080D5268:
	strh r2, [r5, #0xe]
.L080D526A:
	movs r0, #0x64
	bl sub_080C51D4
.L080D5270:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D527C
sub_080D527C: @ 0x080D527C
	push {r4, lr}
	ldr r4, .L080D5298
	ldr r0, [r4, #0x28]
	movs r1, #1
	bl TextWindow_Close
	ldr r0, [r4, #0x2c]
	movs r1, #1
	bl TextWindow_Close
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D5298: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D529C
sub_080D529C: @ 0x080D529C
	push {r4, r5, r6, r7, lr}
	ldr r5, .L080D52E4
	cmp r1, #0
	bne .L080D52AC
	ldr r0, [r5, #0x14]
	movs r1, #0
	bl Window_Close
.L080D52AC:
	ldrh r1, [r5, #0xc]
	cmp r1, #0
	bne .L080D52FA
	ldr r0, .L080D52E8
	str r1, [r0]
	movs r3, #0
	mov ip, r0
	ldr r7, .L080D52EC
	mov r4, ip
	ldr r6, .L080D52F0
.L080D52C0:
	lsls r0, r3, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	cmp r1, r7
	beq .L080D52F4
	adds r0, r0, r6
	ldrh r0, [r0]
	muls r1, r0, r1
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #3
	bls .L080D52C0
	b .L080D530E
	.byte 0x00, 0x00
.L080D52E4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D52E8: .4byte 0x030031CC @ IWRAM+0x31CC
.L080D52EC: .4byte 0x0000FFFF
.L080D52F0: .4byte gUnknown_084F404C
.L080D52F4:
	mov r0, ip
	str r1, [r0]
	b .L080D530E
.L080D52FA:
	bl sub_080D4F48
	ldr r1, .L080D5314
	str r0, [r1]
	ldr r0, .L080D5318
	ldr r1, .L080D531C
	bl Task_Create
	ldr r1, .L080D5320
	str r0, [r1]
.L080D530E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080D5314: .4byte 0x030037F0 @ IWRAM+0x37F0
.L080D5318: .4byte gUnknown_084F4028
.L080D531C: .4byte 0x0000FFFF
.L080D5320: .4byte 0x03003FF0 @ IWRAM+0x3FF0

	thumb_func_start Door_KeypadInitInputState
Door_KeypadInitInputState: @ 0x080D5324
.L080D5324:
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r2, .L080D5364
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	bl Task_Create
	adds r6, r0, #0
	ldr r4, .L080D5368
	movs r5, #0
	str r5, [sp]
	ldr r2, .L080D536C
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	strh r5, [r4, #0xc]
	ldr r0, .L080D5370
	strh r0, [r4]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r4, #2]
	strh r0, [r4, #4]
	strh r0, [r4, #6]
	movs r0, #1
	strh r0, [r4, #0xe]
	strh r0, [r4, #0x10]
	adds r0, r6, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080D5364: .4byte gUnknown_084F4054
.L080D5368: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D536C: .4byte 0x05000200 @ PLTT+0x200
.L080D5370: .4byte 0x0000FFFF

	thumb_func_start sub_080D5374
sub_080D5374: @ 0x080D5374
.L080D5374:
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, .L080D53C8
	ldr r1, .L080D53CC
	bl Task_Create
	adds r6, r0, #0
	ldr r5, .L080D53D0
	movs r0, #0
	str r0, [sp]
	ldr r2, .L080D53D4
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	movs r0, #1
	strh r0, [r5, #0xc]
	str r4, [r5, #0x18]
	movs r2, #0
	adds r4, r5, #0
	adds r4, #0x20
	movs r3, #0xff
.L080D53A2:
	adds r1, r4, r2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r2, #1
	cmp r2, #7
	bls .L080D53A2
	movs r1, #0
	movs r0, #1
	strh r0, [r5, #0xe]
	strh r0, [r5, #0x10]
	ldr r0, .L080D53D8
	str r1, [r0]
	ldr r0, .L080D53DC
	str r6, [r0]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D53C8: .4byte gUnknown_084F40D8
.L080D53CC: .4byte 0x0000FFFF
.L080D53D0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D53D4: .4byte 0x05000200 @ PLTT+0x200
.L080D53D8: .4byte 0x030037F0 @ IWRAM+0x37F0
.L080D53DC: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D53E0
sub_080D53E0: @ 0x080D53E0
.L080D53E0:
	push {lr}
	movs r1, #0
	ldr r0, .L080D53F8
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080D53F0
	movs r1, #1
.L080D53F0:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080D53F8: .4byte 0x03003FEC @ IWRAM+0x3FEC

	thumb_func_start sub_080D53FC
sub_080D53FC: @ 0x080D53FC
.L080D53FC:
	ldr r0, .L080D5408
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0xc]
	bx lr
	.byte 0x00, 0x00
.L080D5408: .4byte 0x03003FF0 @ IWRAM+0x3FF0

	thumb_func_start sub_080D540C
sub_080D540C: @ 0x080D540C
	push {r4, lr}
	bl sub_080C1450
	ldr r0, .L080D5498
	movs r4, #0
	strh r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r2, [r1]
	ldr r0, .L080D549C
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, .L080D54A0
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, .L080D54A4
	ands r0, r2
	strh r0, [r1]
	ldr r2, .L080D54A8
	ldrh r1, [r2]
	ldr r0, .L080D54AC
	ands r0, r1
	strh r0, [r2]
	ldr r0, .L080D54B0
	strb r4, [r0]
	ldr r1, .L080D54B4
	ldr r0, .L080D54B8
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080D54BC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, .L080D54C0
	ldr r2, .L080D54C4
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080D54C8
	movs r0, #0x18
	strh r0, [r1]
	ldr r1, .L080D54CC
	movs r0, #1
	strh r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	bl Task_ClearAll
	bl VBlankTasks_Init
	ldr r0, .L080D54D0
	ldr r1, .L080D54D4
	bl Task_Create
	movs r0, #0x1c
	bl sub_080C5170
	ldr r0, .L080D54D8
	strh r4, [r0]
	ldr r0, .L080D54DC
	bl SetMainCallback
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D5498: .4byte 0x03000040 @ IWRAM+0x40
.L080D549C: .4byte 0x0000FEFF
.L080D54A0: .4byte 0x0000FBFF
.L080D54A4: .4byte 0x0000F7FF
.L080D54A8: .4byte 0x0400000A @ REG_BG1CNT
.L080D54AC: .4byte 0x0000FFBF
.L080D54B0: .4byte 0x0300003C @ IWRAM+0x3C
.L080D54B4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D54B8: .4byte 0x02000000 @ EWRAM
.L080D54BC: .4byte 0x84001000
.L080D54C0: .4byte 0x04000200 @ REG_IE
.L080D54C4: .4byte 0x00002003
.L080D54C8: .4byte 0x04000004 @ REG_DISPSTAT
.L080D54CC: .4byte 0x04000208 @ REG_IME
.L080D54D0: .4byte gUnknown_084F9A28
.L080D54D4: .4byte 0x0000FFFF
.L080D54D8: .4byte 0x0203DB6A @ EWRAM+0x3DB6A
.L080D54DC: .4byte sub_080D54F0

	thumb_func_start sub_080D54E0
sub_080D54E0: @ 0x080D54E0
	push {lr}
	ldr r0, .L080D54EC
	bl SetMainCallback
	pop {r0}
	bx r0
.L080D54EC: .4byte sub_080D540C

	thumb_func_start sub_080D54F0
sub_080D54F0: @ 0x080D54F0
	push {lr}
	bl Task_RunAll
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D54FC
sub_080D54FC: @ 0x080D54FC
	ldr r1, .L080D5530
	ldr r2, .L080D5534
	str r2, [r1]
	ldr r0, .L080D5538
	str r0, [r1, #4]
	ldr r0, .L080D553C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xa0
	lsls r0, r0, #7
	adds r2, r2, r0
	str r2, [r1]
	ldr r0, .L080D5540
	str r0, [r1, #4]
	ldr r0, .L080D5544
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080D5548
	str r0, [r1]
	ldr r0, .L080D554C
	str r0, [r1, #4]
	ldr r0, .L080D5550
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D5530: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5534: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D5538: .4byte 0x06008000 @ VRAM+0x8000
.L080D553C: .4byte 0x840012C0
.L080D5540: .4byte 0x06010000 @ VRAM+0x10000
.L080D5544: .4byte 0x84000800
.L080D5548: .4byte 0x02000000 @ EWRAM
.L080D554C: .4byte 0x06001000 @ VRAM+0x1000
.L080D5550: .4byte 0x84000140

	thumb_func_start sub_080D5554
sub_080D5554: @ 0x080D5554
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	cmp r1, #8
	bls .L080D5566
	b .L080D56CA
.L080D5566:
	lsls r0, r1, #2
	ldr r1, .L080D5570
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080D5570: .4byte gUnknown_080D5574
	.global gUnknown_080D5574
gUnknown_080D5574:
.L080D5574: @ jump table
	.4byte .L080D5598
	.4byte .L080D55AC
	.4byte .L080D55C0
	.4byte .L080D55D4
	.4byte .L080D55E8
	.4byte .L080D55FC
	.4byte .L080D5624
	.4byte .L080D56BC
	.4byte .L080D56C4
.L080D5598:
	ldr r0, .L080D55A4
	ldr r1, .L080D55A8
	bl LZ77UnCompWram
	b .L080D56CA
	.byte 0x00, 0x00
.L080D55A4: .4byte gUnknown_084F4140
.L080D55A8: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D55AC:
	ldr r0, .L080D55B8
	ldr r1, .L080D55BC
	bl LZ77UnCompWram
	b .L080D56CA
	.byte 0x00, 0x00
.L080D55B8: .4byte gUnknown_084F5214
.L080D55BC: .4byte 0x02010874 @ EWRAM+0x10874
.L080D55C0:
	ldr r0, .L080D55CC
	ldr r1, .L080D55D0
	bl LZ77UnCompWram
	b .L080D56CA
	.byte 0x00, 0x00
.L080D55CC: .4byte gUnknown_084F6108
.L080D55D0: .4byte 0x02011874 @ EWRAM+0x11874
.L080D55D4:
	ldr r0, .L080D55E0
	ldr r1, .L080D55E4
	bl LZ77UnCompWram
	b .L080D56CA
	.byte 0x00, 0x00
.L080D55E0: .4byte gUnknown_084F6F7C
.L080D55E4: .4byte 0x02012874 @ EWRAM+0x12874
.L080D55E8:
	ldr r0, .L080D55F4
	ldr r1, .L080D55F8
	bl LZ77UnCompWram
	b .L080D56CA
	.byte 0x00, 0x00
.L080D55F4: .4byte gUnknown_084F7C5C
.L080D55F8: .4byte 0x02013874 @ EWRAM+0x13874
.L080D55FC:
	ldr r0, .L080D5618
	ldr r4, .L080D561C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L080D5620
	movs r1, #0x80
	lsls r1, r1, #5
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	b .L080D56CA
	.byte 0x00, 0x00
.L080D5618: .4byte gUnknown_084F89E0
.L080D561C: .4byte 0x02014874 @ EWRAM+0x14874
.L080D5620: .4byte gUnknown_084F8FF0
.L080D5624:
	ldr r7, .L080D56A0
	ldr r0, .L080D56A4
	mov sb, r0
	ldr r0, .L080D56A8
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x1e
	str r1, [sp, #8]
	movs r1, #0x14
	str r1, [sp, #0xc]
	mov r1, sb
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	movs r0, #0
	ldr r1, .L080D56AC
	mov sl, r1
	movs r1, #0xf
	mov ip, r1
	ldr r1, .L080D56B0
	mov r8, r1
.L080D5652:
	movs r4, #0
	adds r6, r0, #1
	lsls r5, r0, #5
.L080D5658:
	adds r2, r5, r4
	lsls r2, r2, #1
	add r2, sb
	ldrb r1, [r7]
	adds r7, #1
	mov r0, ip
	ands r1, r0
	ldrh r3, [r2]
	mov r0, r8
	ands r0, r3
	lsls r1, r1, #0xc
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x1d
	bls .L080D5658
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls .L080D5652
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	mov r1, sl
	ldr r2, .L080D56B4
	bl Palette_CopyWithEffect
	ldr r0, .L080D56B8
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080D56CA
.L080D56A0: .4byte gUnknown_084F8760
.L080D56A4: .4byte 0x02000000 @ EWRAM
.L080D56A8: .4byte gUnknown_084F9528
.L080D56AC: .4byte gUnknown_084F93E8
.L080D56B0: .4byte 0x00000FFF
.L080D56B4: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080D56B8: .4byte sub_080D54FC
.L080D56BC:
	movs r0, #4
	bl PalFade_FadeInFromBlack
	b .L080D56CA
.L080D56C4:
	movs r0, #4
	bl PalFade_FadeToBlack
.L080D56CA:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D56DC
sub_080D56DC: @ 0x080D56DC
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r0, [r0, #0x24]
	cmp r0, #1
	bne .L080D5702
	ldr r0, .L080D5728
	movs r1, #0
	str r1, [sp]
	movs r1, #0x68
	str r1, [sp, #4]
	movs r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D5702:
	ldrh r0, [r4, #2]
	cmp r0, #1
	bne .L080D5720
	ldr r0, .L080D572C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x64
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D5720:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
.L080D5728: .4byte gUnknown_08002AB0
.L080D572C: .4byte gUnknown_08002AF8

	thumb_func_start sub_080D5730
sub_080D5730: @ 0x080D5730
	push {lr}
	movs r0, #0
	bl sub_080D5B8C
	pop {r0}
	bx r0

	thumb_func_start sub_080D573C
sub_080D573C: @ 0x080D573C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x24
	cmp r1, #7
	bls .L080D574A
	b .L080D584C
.L080D574A:
	lsls r0, r1, #2
	ldr r1, .L080D5754
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080D5754: .4byte gUnknown_080D5758
	.global gUnknown_080D5758
gUnknown_080D5758:
.L080D5758: @ jump table
	.4byte .L080D5778
	.4byte .L080D5798
	.4byte .L080D57B4
	.4byte .L080D57D8
	.4byte .L080D57F8
	.4byte .L080D5818
	.4byte .L080D581E
	.4byte .L080D5848
.L080D5778:
	ldr r1, .L080D5790
	ldr r2, .L080D5794
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_FillWithEffect
	bl Palette_MarkDirty
	movs r0, #1
	b .L080D584A
.L080D5790: .4byte 0x00007FFF
.L080D5794: .4byte 0x03002FB0 @ IWRAM+0x2FB0
.L080D5798:
	ldr r1, .L080D57AC
	ldr r2, .L080D57B0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	b .L080D582E
	.byte 0x00, 0x00
.L080D57AC: .4byte gUnknown_084F94E8
.L080D57B0: .4byte 0x03002BB0 @ IWRAM+0x2BB0
.L080D57B4:
	ldr r1, .L080D57D0
	ldr r2, .L080D57D4
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_FillWithEffect
	bl Palette_MarkDirty
	movs r0, #1
	strh r0, [r4, #2]
	b .L080D584C
	.byte 0x00, 0x00
.L080D57D0: .4byte 0x00007FFF
.L080D57D4: .4byte 0x03002FD0 @ IWRAM+0x2FD0
.L080D57D8:
	ldr r1, .L080D57F0
	ldr r2, .L080D57F4
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0x88
	lsls r0, r0, #1
	b .L080D5832
	.byte 0x00, 0x00
.L080D57F0: .4byte gUnknown_084F9508
.L080D57F4: .4byte 0x03002BD0 @ IWRAM+0x2BD0
.L080D57F8:
	ldr r1, .L080D5810
	ldr r2, .L080D5814
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_FillWithEffect
	movs r0, #0x88
	lsls r0, r0, #1
	b .L080D5832
	.byte 0x00, 0x00
.L080D5810: .4byte 0x00007FFF
.L080D5814: .4byte 0x03002BD0 @ IWRAM+0x2BD0
.L080D5818:
	movs r0, #0
	strh r0, [r4, #2]
	b .L080D584C
.L080D581E:
	ldr r1, .L080D5840
	ldr r2, .L080D5844
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_FillWithEffect
.L080D582E:
	movs r0, #0x80
	lsls r0, r0, #1
.L080D5832:
	movs r1, #0x10
	movs r2, #6
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	b .L080D584C
	.byte 0x00, 0x00
.L080D5840: .4byte 0x00007FFF
.L080D5844: .4byte 0x03002BB0 @ IWRAM+0x2BB0
.L080D5848:
	movs r0, #0
.L080D584A:
	strh r0, [r4]
.L080D584C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080D5854
sub_080D5854: @ 0x080D5854
	push {lr}
	sub sp, #4
	adds r3, r1, #0
	cmp r3, #0
	bne .L080D5878
	ldr r2, .L080D5870
	ldrh r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	ldr r0, .L080D5874
	strb r3, [r0]
	b .L080D5896
	.byte 0x00, 0x00
.L080D5870: .4byte 0x0400000A @ REG_BG1CNT
.L080D5874: .4byte 0x0300003C @ IWRAM+0x3C
.L080D5878:
	ldr r1, .L080D589C
	ldr r2, .L080D58A0
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl Palette_FillWithEffect
	movs r0, #0
	movs r1, #0x80
	movs r2, #0x10
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
.L080D5896:
	add sp, #4
	pop {r0}
	bx r0
.L080D589C: .4byte 0x00007FFF
.L080D58A0: .4byte 0x030029B0 @ IWRAM+0x29B0

	thumb_func_start sub_080D58A4
sub_080D58A4: @ 0x080D58A4
	push {lr}
	ldr r0, .L080D58C8
	ldr r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne .L080D58C4
	ldr r2, .L080D58CC
	ldrb r1, [r2]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0xf
	beq .L080D58C4
	adds r0, r1, #0
	adds r0, #0x11
	strb r0, [r2]
.L080D58C4:
	pop {r0}
	bx r0
.L080D58C8: .4byte 0x030031BC @ IWRAM+0x31BC
.L080D58CC: .4byte 0x0300003C @ IWRAM+0x3C

	thumb_func_start sub_080D58D0
sub_080D58D0: @ 0x080D58D0
	push {lr}
	movs r0, #4
	bl PalFade_FadeToBlack
	ldr r1, .L080D58E4
	movs r0, #1
	strh r0, [r1, #0x34]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D58E4: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080D58E8
sub_080D58E8: @ 0x080D58E8
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080D5908
	ldr r2, .L080D590C
	mov r0, sp
	bl CpuSet
	ldr r0, .L080D5910
	ldr r1, .L080D5914
	bl Task_Create
	add sp, #4
	pop {r0}
	bx r0
.L080D5908: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D590C: .4byte 0x05000200 @ PLTT+0x200
.L080D5910: .4byte gUnknown_084F9C94
.L080D5914: .4byte 0x0000FFFF

	thumb_func_start sub_080D5918
sub_080D5918: @ 0x080D5918
	push {r4, r5, r6, lr}
	ldr r0, .L080D59CC
	ldr r1, .L080D59D0
	adds r0, r0, r1
	movs r1, #0xc
	strb r1, [r0]
	movs r4, #0
	ldr r5, .L080D59D4
.L080D5928:
	adds r0, r4, r5
	ldrb r2, [r0]
	movs r0, #0
	adds r1, r4, #0
	bl sub_080C0074
	movs r0, #0
	bl sub_080BF938
	adds r4, #1
	cmp r4, #6
	bls .L080D5928
	ldr r0, .L080D59CC
	movs r1, #0x32
	strb r1, [r0, #0xd]
	ldr r1, .L080D59D8
	str r1, [r0, #8]
	movs r4, #0
.L080D594C:
	movs r5, #0
	adds r6, r4, #1
	lsls r4, r4, #0x10
.L080D5952:
	lsrs r0, r4, #0x10
	bl sub_080C3328
	adds r5, #1
	cmp r5, #0x31
	bls .L080D5952
	adds r4, r6, #0
	cmp r4, #0xfe
	bls .L080D594C
	movs r0, #0x6e
	bl sub_080C062C
	movs r0, #0x71
	bl sub_080C062C
	movs r0, #0x40
	bl sub_080C062C
	movs r0, #0x64
	bl sub_080C062C
	movs r0, #0xae
	bl sub_080C062C
	movs r0, #0x7d
	bl sub_080C062C
	movs r0, #0x59
	bl sub_080C062C
	movs r0, #0xb
	bl sub_080C062C
	movs r0, #0x4d
	bl sub_080C062C
	movs r0, #0x9c
	bl sub_080C062C
	movs r0, #0x6b
	bl sub_080C062C
	movs r0, #0x76
	bl sub_080C062C
	ldr r1, .L080D59CC
	ldr r2, .L080D59DC
	adds r0, r1, r2
	ldr r2, .L080D59E0
	str r2, [r0]
	ldr r3, .L080D59E4
	adds r0, r1, r3
	str r2, [r0]
	movs r0, #0xae
	lsls r0, r0, #4
	adds r1, r1, r0
	str r2, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D59CC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080D59D0: .4byte 0x00000AC3
.L080D59D4: .4byte gUnknown_08509640
.L080D59D8: .4byte 0x00032D7A
.L080D59DC: .4byte 0x00000ADC
.L080D59E0: .4byte 0x00002710
.L080D59E4: .4byte 0x00000AD8

	thumb_func_start sub_080D59E8
sub_080D59E8: @ 0x080D59E8
.L080D59E8:
	push {r4, lr}
	ldr r0, .L080D5A20
	movs r3, #0
	strh r3, [r0]
	ldr r1, .L080D5A24
	ldr r2, .L080D5A28
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L080D5A2C
	ldr r4, .L080D5A30
	adds r2, r4, #0
	strh r2, [r0]
	ldr r0, .L080D5A34
	adds r4, #8
	adds r1, r4, #0
	strh r1, [r0]
	ldr r0, .L080D5A38
	strh r2, [r0]
	ldr r0, .L080D5A3C
	strh r1, [r0]
	ldr r0, .L080D5A40
	strh r3, [r0]
	ldr r0, .L080D5A44
	strh r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D5A20: .4byte 0x03000000 @ IWRAM
.L080D5A24: .4byte 0x03000002 @ IWRAM+0x2
.L080D5A28: .4byte 0x0000FFFF
.L080D5A2C: .4byte 0x03000004 @ IWRAM+0x4
.L080D5A30: .4byte 0x0000FFE0
.L080D5A34: .4byte 0x03000006 @ IWRAM+0x6
.L080D5A38: .4byte 0x03000008 @ IWRAM+0x8
.L080D5A3C: .4byte 0x0300000A @ IWRAM+0xA
.L080D5A40: .4byte 0x0300000C @ IWRAM+0xC
.L080D5A44: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080D5A48
sub_080D5A48: @ 0x080D5A48
	push {r4, r5, lr}
	sub sp, #0xc
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xfe
	lsls r2, r2, #7
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #8
	ldr r2, .L080D5B0C
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, .L080D5B10
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, .L080D5B14
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, .L080D5B18
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L080D5B1C
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080D5B20
	strb r1, [r0]
	ldr r0, .L080D5B24
	strb r1, [r0]
	bl sub_080D59E8
	bl sub_080C1440
	movs r0, #0
	bl PalFade_Init
	movs r4, #0
	str r4, [sp]
	ldr r1, .L080D5B28
	ldr r2, .L080D5B2C
	mov r0, sp
	bl CpuSet
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r1, .L080D5B30
	ldr r5, .L080D5B34
	adds r2, r5, #0
	bl CpuSet
	ldr r1, .L080D5B38
	ldr r2, .L080D5B3C
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080D5B40
	movs r0, #0x18
	strh r0, [r1]
	ldr r1, .L080D5B44
	movs r0, #1
	strh r0, [r1]
	movs r0, #0
	bl sub_080C5170
	ldr r0, .L080D5B48
	strh r4, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	bl Task_ClearAll
	str r4, [sp, #8]
	add r0, sp, #8
	ldr r1, .L080D5B4C
	adds r2, r5, #0
	bl CpuSet
	ldr r0, .L080D5B50
	ldr r4, .L080D5B54
	adds r1, r4, #0
	bl Task_Create
	ldr r0, .L080D5B58
	adds r1, r4, #0
	bl Task_Create
	ldr r1, .L080D5B5C
	str r0, [r1]
	ldr r0, .L080D5B60
	bl SetMainCallback
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D5B0C: .4byte 0x00008004
.L080D5B10: .4byte 0x0000820D
.L080D5B14: .4byte 0x0000840E
.L080D5B18: .4byte 0x00004607
.L080D5B1C: .4byte 0x03000038 @ IWRAM+0x38
.L080D5B20: .4byte 0x03000039 @ IWRAM+0x39
.L080D5B24: .4byte 0x0300003A @ IWRAM+0x3A
.L080D5B28: .4byte 0x020381DC @ EWRAM+0x381DC
.L080D5B2C: .4byte 0x05000400
.L080D5B30: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080D5B34: .4byte 0x05000200 @ PLTT+0x200
.L080D5B38: .4byte 0x04000200 @ REG_IE
.L080D5B3C: .4byte 0x00002003
.L080D5B40: .4byte 0x04000004 @ REG_DISPSTAT
.L080D5B44: .4byte 0x04000208 @ REG_IME
.L080D5B48: .4byte 0x0203DB6A @ EWRAM+0x3DB6A
.L080D5B4C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D5B50: .4byte gUnknown_08509CF8
.L080D5B54: .4byte 0x0000FFFF
.L080D5B58: .4byte gUnknown_08509CD0
.L080D5B5C: .4byte 0x030069E4 @ IWRAM+0x69E4
.L080D5B60: .4byte sub_080D5BE4

	thumb_func_start sub_080D5B64
sub_080D5B64: @ 0x080D5B64
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080D5B84
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080D5B88
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	bx lr
	.byte 0x00, 0x00
.L080D5B84: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5B88: .4byte 0x81002000

	thumb_func_start sub_080D5B8C
sub_080D5B8C: @ 0x080D5B8C
.L080D5B8C:
	push {r4, r5, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r5, .L080D5BD0
	str r4, [r5]
	bl sub_080D6A34
	cmp r0, #0
	bne .L080D5BA8
	cmp r4, #4
	bne .L080D5BA8
	movs r0, #3
	str r0, [r5]
.L080D5BA8:
	ldr r0, .L080D5BD4
	bl SetMainCallback
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080D5BD8
	ldr r2, .L080D5BDC
	mov r0, sp
	bl CpuSet
	bl Palette_MarkDirty
	ldr r0, .L080D5BE0
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D5BD0: .4byte 0x0203BB68 @ EWRAM+0x3BB68
.L080D5BD4: .4byte sub_080D5A48
.L080D5BD8: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080D5BDC: .4byte 0x05000100 @ PLTT+0x100
.L080D5BE0: .4byte sub_080D5B64

	thumb_func_start sub_080D5BE4
sub_080D5BE4: @ 0x080D5BE4
	push {lr}
	bl Task_RunAll
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D5BF0
sub_080D5BF0: @ 0x080D5BF0
	ldr r1, .L080D5BF8
	ldr r1, [r1]
	strh r1, [r0, #0x1e]
	bx lr
.L080D5BF8: .4byte 0x0203BB68 @ EWRAM+0x3BB68

	thumb_func_start sub_080D5BFC
sub_080D5BFC: @ 0x080D5BFC
	push {r4, lr}
	ldr r4, .L080D5C1C
	bl SaveSlot_AnyValid
	cmp r0, #1
	bne .L080D5C0A
	strh r0, [r4, #8]
.L080D5C0A:
	movs r0, #3
	bl SaveSlot_IsValid
	cmp r0, #1
	bne .L080D5C16
	strh r0, [r4, #0xa]
.L080D5C16:
	pop {r4}
	pop {r0}
	bx r0
.L080D5C1C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D5C20
sub_080D5C20: @ 0x080D5C20
	push {lr}
	sub sp, #4
	ldr r0, .L080D5C38
	ldrh r0, [r0]
	cmp r0, #0x81
	bls .L080D5C2E
	b .L080D6234
.L080D5C2E:
	lsls r0, r0, #2
	ldr r1, .L080D5C3C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080D5C38: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D5C3C: .4byte gUnknown_080D5C40
	.global gUnknown_080D5C40
gUnknown_080D5C40:
.L080D5C40: @ jump table
	.4byte .L080D61CC
	.4byte .L080D61EC
	.4byte .L080D620C
	.4byte .L080D6224
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D6234
	.4byte .L080D5E48
	.4byte .L080D5E68
	.4byte .L080D5EB0
	.4byte .L080D6234
	.4byte .L080D5ECC
	.4byte .L080D5EE8
	.4byte .L080D5F08
	.4byte .L080D6234
	.4byte .L080D5F48
	.4byte .L080D5F68
	.4byte .L080D5F88
	.4byte .L080D5FA8
	.4byte .L080D6234
	.4byte .L080D5F28
	.4byte .L080D6234
	.4byte .L080D5FC4
	.4byte .L080D5FE4
	.4byte .L080D6004
	.4byte .L080D6024
	.4byte .L080D6044
	.4byte .L080D6064
	.4byte .L080D606E
	.4byte .L080D608C
	.4byte .L080D60CC
	.4byte .L080D610C
	.4byte .L080D612C
	.4byte .L080D614C
	.4byte .L080D6234
	.4byte .L080D616C
	.4byte .L080D6188
.L080D5E48:
	ldr r1, .L080D5E58
	ldr r0, .L080D5E5C
	str r0, [r1]
	ldr r0, .L080D5E60
	str r0, [r1, #4]
	ldr r0, .L080D5E64
	b .L080D6230
	.byte 0x00, 0x00
.L080D5E58: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5E5C: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D5E60: .4byte 0x06004000 @ VRAM+0x4000
.L080D5E64: .4byte 0x84002000
.L080D5E68:
	ldr r1, .L080D5E94
	ldr r0, .L080D5E98
	str r0, [r1]
	ldr r0, .L080D5E9C
	str r0, [r1, #4]
	ldr r0, .L080D5EA0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080D59E8
	ldr r1, .L080D5EA4
	ldr r2, .L080D5EA8
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, .L080D5EAC
	adds r0, r2, #0
	strh r0, [r1]
	bl sub_080C1440
	b .L080D6234
	.byte 0x00, 0x00
.L080D5E94: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5E98: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D5E9C: .4byte 0x06010000 @ VRAM+0x10000
.L080D5EA0: .4byte 0x84002000
.L080D5EA4: .4byte 0x0400000A @ REG_BG1CNT
.L080D5EA8: .4byte 0x0000820D
.L080D5EAC: .4byte 0x0000840E
.L080D5EB0:
	ldr r1, .L080D5EC0
	ldr r0, .L080D5EC4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080D5EC8
	b .L080D6230
.L080D5EC0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5EC4: .4byte gUnknown_084F9FE0
.L080D5EC8: .4byte 0x84000140
.L080D5ECC:
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080D5EE0
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080D5EE4
	b .L080D6230
.L080D5EE0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5EE4: .4byte 0x85000140
.L080D5EE8:
	ldr r1, .L080D5EF8
	ldr r0, .L080D5EFC
	str r0, [r1]
	ldr r0, .L080D5F00
	str r0, [r1, #4]
	ldr r0, .L080D5F04
	b .L080D6230
	.byte 0x00, 0x00
.L080D5EF8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5EFC: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D5F00: .4byte 0x06004000 @ VRAM+0x4000
.L080D5F04: .4byte 0x84002000
.L080D5F08:
	ldr r1, .L080D5F18
	ldr r0, .L080D5F1C
	str r0, [r1]
	ldr r0, .L080D5F20
	str r0, [r1, #4]
	ldr r0, .L080D5F24
	b .L080D6230
	.byte 0x00, 0x00
.L080D5F18: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5F1C: .4byte gUnknown_084FA860
.L080D5F20: .4byte 0x06003000 @ VRAM+0x3000
.L080D5F24: .4byte 0x84000140
.L080D5F28:
	ldr r1, .L080D5F38
	ldr r0, .L080D5F3C
	str r0, [r1]
	ldr r0, .L080D5F40
	str r0, [r1, #4]
	ldr r0, .L080D5F44
	b .L080D6230
	.byte 0x00, 0x00
.L080D5F38: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5F3C: .4byte gUnknown_084FB760
.L080D5F40: .4byte 0x06001000 @ VRAM+0x1000
.L080D5F44: .4byte 0x84000140
.L080D5F48:
	ldr r1, .L080D5F58
	ldr r0, .L080D5F5C
	str r0, [r1]
	ldr r0, .L080D5F60
	str r0, [r1, #4]
	ldr r0, .L080D5F64
	b .L080D6230
	.byte 0x00, 0x00
.L080D5F58: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5F5C: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D5F60: .4byte 0x0600C000 @ VRAM+0xC000
.L080D5F64: .4byte 0x84001000
.L080D5F68:
	ldr r1, .L080D5F78
	ldr r0, .L080D5F7C
	str r0, [r1]
	ldr r0, .L080D5F80
	str r0, [r1, #4]
	ldr r0, .L080D5F84
	b .L080D6230
	.byte 0x00, 0x00
.L080D5F78: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5F7C: .4byte gUnknown_084FB260
.L080D5F80: .4byte 0x06001000 @ VRAM+0x1000
.L080D5F84: .4byte 0x84000140
.L080D5F88:
	ldr r1, .L080D5F98
	ldr r0, .L080D5F9C
	str r0, [r1]
	ldr r0, .L080D5FA0
	str r0, [r1, #4]
	ldr r0, .L080D5FA4
	b .L080D6230
	.byte 0x00, 0x00
.L080D5F98: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5F9C: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D5FA0: .4byte 0x06010000 @ VRAM+0x10000
.L080D5FA4: .4byte 0x84002000
.L080D5FA8:
	ldr r1, .L080D5FB8
	ldr r0, .L080D5FBC
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080D5FC0
	b .L080D6230
.L080D5FB8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5FBC: .4byte gUnknown_084FCB60
.L080D5FC0: .4byte 0x84000140
.L080D5FC4:
	ldr r1, .L080D5FD4
	ldr r0, .L080D5FD8
	str r0, [r1]
	ldr r0, .L080D5FDC
	str r0, [r1, #4]
	ldr r0, .L080D5FE0
	b .L080D6230
	.byte 0x00, 0x00
.L080D5FD4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5FD8: .4byte gUnknown_084FB760
.L080D5FDC: .4byte 0x06002000 @ VRAM+0x2000
.L080D5FE0: .4byte 0x84000140
.L080D5FE4:
	ldr r1, .L080D5FF4
	ldr r0, .L080D5FF8
	str r0, [r1]
	ldr r0, .L080D5FFC
	str r0, [r1, #4]
	ldr r0, .L080D6000
	b .L080D6230
	.byte 0x00, 0x00
.L080D5FF4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D5FF8: .4byte gUnknown_084FBC60
.L080D5FFC: .4byte 0x06001000 @ VRAM+0x1000
.L080D6000: .4byte 0x84000140
.L080D6004:
	ldr r1, .L080D6014
	ldr r0, .L080D6018
	str r0, [r1]
	ldr r0, .L080D601C
	str r0, [r1, #4]
	ldr r0, .L080D6020
	b .L080D6230
	.byte 0x00, 0x00
.L080D6014: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D6018: .4byte gUnknown_084FB260
.L080D601C: .4byte 0x06002000 @ VRAM+0x2000
.L080D6020: .4byte 0x84000140
.L080D6024:
	ldr r1, .L080D6034
	ldr r0, .L080D6038
	str r0, [r1]
	ldr r0, .L080D603C
	str r0, [r1, #4]
	ldr r0, .L080D6040
	b .L080D6230
	.byte 0x00, 0x00
.L080D6034: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D6038: .4byte gUnknown_084FBC60
.L080D603C: .4byte 0x06002000 @ VRAM+0x2000
.L080D6040: .4byte 0x84000140
.L080D6044:
	ldr r1, .L080D6054
	ldr r0, .L080D6058
	str r0, [r1]
	ldr r0, .L080D605C
	str r0, [r1, #4]
	ldr r0, .L080D6060
	b .L080D6230
	.byte 0x00, 0x00
.L080D6054: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D6058: .4byte gUnknown_084FC160
.L080D605C: .4byte 0x06001000 @ VRAM+0x1000
.L080D6060: .4byte 0x84000140
.L080D6064:
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	b .L080D6234
.L080D606E:
	ldr r1, .L080D607C
	ldr r0, .L080D6080
	str r0, [r1]
	ldr r0, .L080D6084
	str r0, [r1, #4]
	ldr r0, .L080D6088
	b .L080D6230
.L080D607C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D6080: .4byte gUnknown_084FC160
.L080D6084: .4byte 0x06002000 @ VRAM+0x2000
.L080D6088: .4byte 0x84000140
.L080D608C:
	ldr r1, .L080D60AC
	ldr r2, .L080D60B0
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L080D60B4
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080D60B8
	strh r1, [r0]
	ldr r1, .L080D60BC
	ldr r0, .L080D60C0
	str r0, [r1]
	ldr r0, .L080D60C4
	str r0, [r1, #4]
	ldr r0, .L080D60C8
	b .L080D6230
.L080D60AC: .4byte 0x0400000A @ REG_BG1CNT
.L080D60B0: .4byte 0x00008205
.L080D60B4: .4byte 0x03000006 @ IWRAM+0x6
.L080D60B8: .4byte 0x03000004 @ IWRAM+0x4
.L080D60BC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D60C0: .4byte gUnknown_084FC660
.L080D60C4: .4byte 0x06001000 @ VRAM+0x1000
.L080D60C8: .4byte 0x84000140
.L080D60CC:
	ldr r1, .L080D60EC
	ldr r2, .L080D60F0
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L080D60F4
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080D60F8
	strh r1, [r0]
	ldr r1, .L080D60FC
	ldr r0, .L080D6100
	str r0, [r1]
	ldr r0, .L080D6104
	str r0, [r1, #4]
	ldr r0, .L080D6108
	b .L080D6230
.L080D60EC: .4byte 0x0400000C @ REG_BG2CNT
.L080D60F0: .4byte 0x00008406
.L080D60F4: .4byte 0x0300000A @ IWRAM+0xA
.L080D60F8: .4byte 0x03000008 @ IWRAM+0x8
.L080D60FC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D6100: .4byte gUnknown_084FC660
.L080D6104: .4byte 0x06002000 @ VRAM+0x2000
.L080D6108: .4byte 0x84000140
.L080D610C:
	ldr r1, .L080D611C
	ldr r0, .L080D6120
	str r0, [r1]
	ldr r0, .L080D6124
	str r0, [r1, #4]
	ldr r0, .L080D6128
	b .L080D6230
	.byte 0x00, 0x00
.L080D611C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D6120: .4byte gUnknown_084FCB60
.L080D6124: .4byte 0x06001000 @ VRAM+0x1000
.L080D6128: .4byte 0x84000140
.L080D612C:
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080D6140
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080D6144
	str r0, [r1, #4]
	ldr r0, .L080D6148
	b .L080D6230
	.byte 0x00, 0x00
.L080D6140: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D6144: .4byte 0x06003000 @ VRAM+0x3000
.L080D6148: .4byte 0x85000140
.L080D614C:
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080D6160
	mov r2, sp
	str r2, [r1]
	ldr r0, .L080D6164
	str r0, [r1, #4]
	ldr r0, .L080D6168
	b .L080D6230
	.byte 0x00, 0x00
.L080D6160: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D6164: .4byte 0x06002000 @ VRAM+0x2000
.L080D6168: .4byte 0x85000140
.L080D616C:
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080D6180
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080D6184
	b .L080D6230
.L080D6180: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D6184: .4byte 0x85001000
.L080D6188:
	ldr r1, .L080D61AC
	ldr r0, .L080D61B0
	str r0, [r1]
	ldr r0, .L080D61B4
	str r0, [r1, #4]
	ldr r0, .L080D61B8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, .L080D61BC
	movs r0, #0x18
	strh r0, [r1]
	ldr r0, .L080D61C0
	ldr r2, .L080D61C4
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, .L080D61C8
	strh r1, [r0]
	b .L080D6234
.L080D61AC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D61B0: .4byte gUnknown_084FAD60
.L080D61B4: .4byte 0x06003800 @ VRAM+0x3800
.L080D61B8: .4byte 0x84000140
.L080D61BC: .4byte 0x0300000C @ IWRAM+0xC
.L080D61C0: .4byte 0x03000008 @ IWRAM+0x8
.L080D61C4: .4byte 0x0000FFF8
.L080D61C8: .4byte 0x03000004 @ IWRAM+0x4
.L080D61CC:
	ldr r1, .L080D61DC
	ldr r0, .L080D61E0
	str r0, [r1]
	ldr r0, .L080D61E4
	str r0, [r1, #4]
	ldr r0, .L080D61E8
	b .L080D6230
	.byte 0x00, 0x00
.L080D61DC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D61E0: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D61E4: .4byte 0x06008000 @ VRAM+0x8000
.L080D61E8: .4byte 0x84002000
.L080D61EC:
	ldr r1, .L080D61FC
	ldr r0, .L080D6200
	str r0, [r1]
	ldr r0, .L080D6204
	str r0, [r1, #4]
	ldr r0, .L080D6208
	b .L080D6230
	.byte 0x00, 0x00
.L080D61FC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D6200: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D6204: .4byte 0x06010000 @ VRAM+0x10000
.L080D6208: .4byte 0x84002000
.L080D620C:
	ldr r1, .L080D6218
	ldr r0, .L080D621C
	str r0, [r1]
	ldr r0, .L080D6220
	b .L080D622C
	.byte 0x00, 0x00
.L080D6218: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D621C: .4byte gUnknown_081B9BB0
.L080D6220: .4byte 0x06001000 @ VRAM+0x1000
.L080D6224:
	ldr r1, .L080D623C
	ldr r0, .L080D6240
	str r0, [r1]
	ldr r0, .L080D6244
.L080D622C:
	str r0, [r1, #4]
	ldr r0, .L080D6248
.L080D6230:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
.L080D6234:
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D623C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D6240: .4byte gUnknown_081BA3B0
.L080D6244: .4byte 0x06002000 @ VRAM+0x2000
.L080D6248: .4byte 0x84000200

	thumb_func_start sub_080D624C
sub_080D624C: @ 0x080D624C
	adds r0, #0x24
	adds r0, r0, r1
	strb r2, [r0]
	bx lr

	thumb_func_start sub_080D6254
sub_080D6254: @ 0x080D6254
	ldr r0, .L080D6260
	lsls r1, r1, #1
	adds r0, #0xe
	adds r1, r1, r0
	strh r2, [r1]
	bx lr
.L080D6260: .4byte 0x0203A454 @ EWRAM+0x3A454
