	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080DBA1C
sub_080DBA1C: @ 0x080DBA1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x24
	movs r0, #0
	mov r8, r0
	mov r0, r8
	strh r0, [r6, #0x1c]
	strh r0, [r6, #0x1e]
	ldrh r0, [r4, #0x10]
	cmp r0, #0
	bne .L080DBAD8
	ldr r3, .L080DBA6C
	ldrh r1, [r3]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DBA74
	ldrh r0, [r6, #0x24]
	adds r0, #1
	strh r0, [r6, #0x1e]
	movs r0, #0x65
	bl sub_080C51D4
	strh r5, [r6, #0x1c]
	ldr r1, .L080DBA70
	ldrh r2, [r4, #0xc]
	adds r0, r1, #0
	adds r0, #0x44
	strh r2, [r0]
	ldrh r0, [r4, #0xe]
	adds r1, #0x46
	strh r0, [r1]
	b .L080DBC5E
	.byte 0x00, 0x00
.L080DBA6C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DBA70: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DBA74:
	ldrh r1, [r3]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DBA8E
	strh r2, [r6, #0x1e]
	strh r5, [r6, #0x24]
	movs r0, #0x66
	bl sub_080C51D4
	strh r5, [r6, #0x1c]
	b .L080DBC5E
.L080DBA8E:
	ldr r0, .L080DBAA8
	ldrh r2, [r0]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L080DBAB0
	ldrh r0, [r6, #0x24]
	cmp r0, #0
	beq .L080DBAAC
	subs r0, #1
	strh r0, [r6, #0x24]
	b .L080DBC0E
	.byte 0x00, 0x00
.L080DBAA8: .4byte 0x03003964 @ IWRAM+0x3964
.L080DBAAC:
	strh r5, [r6, #0x24]
	b .L080DBC0E
.L080DBAB0:
	ldrh r1, [r3]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080DBABE
	strh r5, [r4, #0x10]
	b .L080DBC0E
.L080DBABE:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	bne .L080DBAC8
	b .L080DBC5E
.L080DBAC8:
	ldrh r0, [r6, #0x24]
	cmp r0, #1
	beq .L080DBAD2
	adds r0, #1
	b .L080DBAD4
.L080DBAD2:
	mov r0, r8
.L080DBAD4:
	strh r0, [r6, #0x24]
	b .L080DBC0E
.L080DBAD8:
	bl Dict_CountListed
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L080DBB34
	ldrh r3, [r0, #0x3e]
	cmp r3, #0
	bne .L080DBAEA
	movs r5, #1
.L080DBAEA:
	mov ip, r5
	cmp r5, #5
	bls .L080DBAF4
	movs r0, #6
	mov ip, r0
.L080DBAF4:
	ldr r2, .L080DBB38
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq .L080DBB4C
	cmp r3, #1
	bne .L080DBB4C
	ldr r2, .L080DBB3C
	ldrh r0, [r4, #0xc]
	ldrh r1, [r4, #0xe]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L080DBB40
	ands r0, r1
	bl sub_080C2644
	cmp r0, #0
	beq .L080DBB44
	movs r0, #1
	mov r8, r0
	movs r0, #0x65
	bl sub_080C51D4
	movs r0, #3
	strh r0, [r6, #0x1e]
	mov r0, r8
	strh r0, [r6, #0x1c]
	b .L080DBC5E
.L080DBB34: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DBB38: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DBB3C: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DBB40: .4byte 0x00007FFF
.L080DBB44:
	movs r0, #0x66
	bl sub_080C51D4
	b .L080DBC5E
.L080DBB4C:
	mov r0, sb
	ldrh r1, [r0]
	movs r7, #2
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DBB68
	movs r0, #0x66
	bl sub_080C51D4
	strh r7, [r6, #0x1e]
	movs r0, #1
	strh r0, [r6, #0x1c]
	b .L080DBC5E
.L080DBB68:
	ldr r1, .L080DBB84
	ldrh r3, [r1]
	movs r0, #0x40
	ands r0, r3
	mov sl, r1
	cmp r0, #0
	beq .L080DBB94
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	beq .L080DBB88
	subs r0, #1
	strh r0, [r4, #0xc]
	b .L080DBC0A
	.byte 0x00, 0x00
.L080DBB84: .4byte 0x03003964 @ IWRAM+0x3964
.L080DBB88:
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	beq .L080DBC5E
	subs r0, #1
	strh r0, [r4, #0xe]
	b .L080DBC0A
.L080DBB94:
	movs r0, #0x80
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L080DBBC6
	ldrh r1, [r4, #0xc]
	mov r0, ip
	subs r0, #1
	cmp r1, r0
	beq .L080DBBB0
	adds r0, r1, #1
	strh r0, [r4, #0xc]
	b .L080DBC0A
.L080DBBB0:
	cmp r1, #5
	bne .L080DBC5E
	ldrh r2, [r4, #0xe]
	adds r0, r1, r2
	adds r0, #1
	subs r1, r5, #1
	cmp r0, r1
	bgt .L080DBC5E
	adds r0, r2, #1
	strh r0, [r4, #0xe]
	b .L080DBC0A
.L080DBBC6:
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	beq .L080DBBDA
	strh r2, [r4, #0x10]
	b .L080DBC0E
.L080DBBDA:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r3
	cmp r0, #0
	beq .L080DBC16
	cmp r5, #6
	bls .L080DBC16
	ldrh r2, [r4, #0xc]
	ldrh r1, [r4, #0xe]
	adds r0, r2, #0
	cmp r0, #0
	beq .L080DBBF6
	strh r7, [r4, #0xc]
	b .L080DBBFE
.L080DBBF6:
	cmp r1, #4
	bls .L080DBBFC
	subs r0, r1, #5
.L080DBBFC:
	strh r0, [r4, #0xe]
.L080DBBFE:
	ldrh r0, [r4, #0xc]
	cmp r2, r0
	bne .L080DBC0A
	ldrh r0, [r4, #0xe]
	cmp r1, r0
	beq .L080DBC5E
.L080DBC0A:
	movs r0, #1
	mov r8, r0
.L080DBC0E:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DBC5E
.L080DBC16:
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080DBC5E
	cmp r5, #6
	bls .L080DBC5E
	ldrh r2, [r4, #0xc]
	ldrh r3, [r4, #0xe]
	cmp r2, #5
	beq .L080DBC36
	movs r0, #5
	strh r0, [r4, #0xc]
	b .L080DBC48
.L080DBC36:
	adds r0, r2, r3
	adds r0, #6
	subs r1, r5, #1
	cmp r0, r1
	bge .L080DBC44
	adds r0, r3, #6
	b .L080DBC46
.L080DBC44:
	subs r0, r5, #6
.L080DBC46:
	strh r0, [r4, #0xe]
.L080DBC48:
	ldrh r0, [r4, #0xc]
	cmp r2, r0
	bne .L080DBC54
	ldrh r0, [r4, #0xe]
	cmp r3, r0
	beq .L080DBC5E
.L080DBC54:
	movs r0, #1
	mov r8, r0
	movs r0, #0x64
	bl sub_080C51D4
.L080DBC5E:
	mov r0, r8
	cmp r0, #1
	bne .L080DBC90
	ldr r1, .L080DBCA0
	ldrh r2, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	adds r2, r2, r0
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, .L080DBCA4
	ands r0, r1
	ldr r1, .L080DBCA8
	strh r2, [r1, #0x3c]
	str r0, [r1, #0x38]
	ldrh r2, [r4, #0xc]
	adds r0, r1, #0
	adds r0, #0x44
	strh r2, [r0]
	ldrh r0, [r4, #0xe]
	adds r1, #0x46
	strh r0, [r1]
	adds r0, r6, #0
	bl sub_080DB464
.L080DBC90:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DBCA0: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DBCA4: .4byte 0x00007FFF
.L080DBCA8: .4byte 0x020399E0 @ EWRAM+0x399E0
