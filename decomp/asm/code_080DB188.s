	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080DB188
sub_080DB188: @ 0x080DB188
	push {lr}
	sub sp, #0x10
	ldr r0, .L080DB1C8
	ldr r2, [r0, #0x78]
	adds r1, r0, #0
	adds r1, #0x80
	ldr r1, [r1]
	str r1, [r2, #0x20]
	ldr r1, [r0, #0x7c]
	adds r0, #0x84
	ldr r0, [r0]
	str r0, [r1, #0x20]
	ldr r0, .L080DB1CC
	ldr r1, .L080DB1D0
	movs r2, #1
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0xb
	str r2, [sp, #8]
	movs r2, #5
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r0, .L080DB1D4
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #0x10
	pop {r0}
	bx r0
.L080DB1C8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080DB1CC: .4byte gUnknown_0857F500
.L080DB1D0: .4byte 0x02024074 @ EWRAM+0x24074
.L080DB1D4: .4byte sub_080D9BAC

	thumb_func_start sub_080DB1D8
sub_080DB1D8: @ 0x080DB1D8
	ldr r0, .L080DB1E0
	str r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080DB1E0: .4byte 0x0300609C @ IWRAM+0x609C

	thumb_func_start sub_080DB1E4
sub_080DB1E4: @ 0x080DB1E4
	ldr r0, .L080DB1F8
	movs r2, #0
	str r2, [r0, #0x48]
	adds r1, r0, #0
	adds r1, #0x44
	strh r2, [r1]
	adds r0, #0x46
	strh r2, [r0]
	bx lr
	.byte 0x00, 0x00
.L080DB1F8: .4byte 0x020399E0 @ EWRAM+0x399E0

	thumb_func_start sub_080DB1FC
sub_080DB1FC: @ 0x080DB1FC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	ldr r2, .L080DB240
	ldrh r1, [r2]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DB260
	ldrh r0, [r4, #0x24]
	adds r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #0x65
	bl sub_080C51D4
	strh r5, [r4, #0x1c]
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne .L080DB2BA
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl Dict_BuildList
	bl sub_080DB8A4
	cmp r0, #0
	bne .L080DB244
	movs r0, #3
	strh r0, [r4, #0x1e]
	b .L080DB2BA
.L080DB240: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DB244:
	ldr r0, .L080DB254
	ldr r2, .L080DB258
	ldrh r1, [r0]
	ldr r0, .L080DB25C
	ands r0, r1
	str r0, [r2, #0x38]
	b .L080DB2BA
	.byte 0x00, 0x00
.L080DB254: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DB258: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DB25C: .4byte 0x00007FFF
.L080DB260:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DB274
	movs r0, #0x66
	bl sub_080C51D4
	strh r5, [r4, #0x1c]
	b .L080DB2BA
.L080DB274:
	ldr r0, .L080DB290
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L080DB29E
	ldrh r0, [r4, #0x24]
	cmp r0, #0
	beq .L080DB294
	subs r0, #1
	strh r0, [r4, #0x24]
	b .L080DB296
.L080DB290: .4byte 0x03003964 @ IWRAM+0x3964
.L080DB294:
	strh r5, [r4, #0x24]
.L080DB296:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DB2BA
.L080DB29E:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080DB2BA
	ldrh r0, [r4, #0x24]
	cmp r0, #1
	beq .L080DB2B2
	adds r0, #1
	strh r0, [r4, #0x24]
	b .L080DB2B4
.L080DB2B2:
	strh r2, [r4, #0x24]
.L080DB2B4:
	movs r0, #0x64
	bl sub_080C51D4
.L080DB2BA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start DDS_DrawMenuRow
DDS_DrawMenuRow: @ 0x080DB2C0
	push {lr}
	sub sp, #8
	bl Task_GetParent
	ldr r1, .L080DB2EC
	ldrh r0, [r0, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x64
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x14
	bl Text_DrawSpriteString
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DB2EC: .4byte gUnknown_08582D28

	thumb_func_start sub_080DB2F0
sub_080DB2F0: @ 0x080DB2F0
	push {lr}
	sub sp, #8
	ldr r0, .L080DB310
	movs r1, #0x64
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x14
	bl Text_DrawSpriteString
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DB310: .4byte gUnknown_080095B4

	thumb_func_start sub_080DB314
sub_080DB314: @ 0x080DB314
	push {r4, lr}
	sub sp, #4
	ldr r4, .L080DB344
	ldr r0, .L080DB348
	adds r1, r4, #0
	stm r1!, {r0}
	ldr r0, .L080DB34C
	ldr r2, .L080DB350
	bl CpuSet
	movs r0, #0
	str r0, [r4, #0x34]
	str r0, [sp]
	adds r4, #0x38
	ldr r2, .L080DB354
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DB344: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080DB348: .4byte 0x10570010
.L080DB34C: .4byte 0x03004690 @ IWRAM+0x4690
.L080DB350: .4byte 0x0400000C @ REG_BG2CNT
.L080DB354: .4byte 0x0500000C @ PLTT+0xC

	thumb_func_start sub_080DB358
sub_080DB358: @ 0x080DB358
	push {lr}
	ldr r1, .L080DB36C
	adds r2, r1, #0
	adds r2, #0x34
	movs r0, #0x34
	bl sub_080DF954
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DB36C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080DB370
sub_080DB370: @ 0x080DB370
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080DB384
	ldr r1, [r0, #0x34]
	ldr r0, .L080DB388
	cmp r1, r0
	bne .L080DB38C
	movs r0, #1
	b .L080DB38E
	.byte 0x00, 0x00
.L080DB384: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080DB388: .4byte 0x10570010
.L080DB38C:
	movs r0, #0
.L080DB38E:
	strh r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080DB394
sub_080DB394: @ 0x080DB394
	push {r4, r5, lr}
	ldr r0, .L080DB3D4
	adds r5, r0, #0
	adds r5, #0x38
	movs r4, #0
.L080DB39E:
	lsrs r0, r4, #3
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r4
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq .L080DB3B8
	adds r0, r4, #0
	bl sub_080C2674
.L080DB3B8:
	adds r4, #1
	ldr r0, .L080DB3D8
	cmp r4, r0
	bls .L080DB39E
	ldr r1, .L080DB3DC
	ldr r2, .L080DB3E0
	adds r0, r1, r2
	ldr r0, [r0]
	bl SaveSlot_Write
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DB3D4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080DB3D8: .4byte 0x0000017B
.L080DB3DC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080DB3E0: .4byte 0x000018B0

	thumb_func_start sub_080DB3E4
sub_080DB3E4: @ 0x080DB3E4
.L080DB3E4:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #0
	ldr r4, .L080DB400
	ldr r3, .L080DB404
.L080DB3F0:
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r3
	bne .L080DB408
	movs r0, #0x20
	b .L080DB416
	.byte 0x00, 0x00
.L080DB400: .4byte gUnknown_08583258
.L080DB404: .4byte 0x0000FFFF
.L080DB408:
	cmp r0, r2
	beq .L080DB414
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b .L080DB3F0
.L080DB414:
	movs r0, #0
.L080DB416:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080DB41C
sub_080DB41C: @ 0x080DB41C
	push {r4, r5, lr}
	ldr r5, .L080DB460
	ldr r0, [r5, #0x48]
	cmp r0, #0
	bne .L080DB45A
	ldrh r0, [r5, #0x38]
	bl sub_080C263C
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #1
	bl sub_080C3818
	movs r0, #0
	adds r1, r4, #0
	bl sub_080E8E00
	str r0, [r5, #0x48]
	adds r0, r4, #0
	bl sub_080DB3E4
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r2, #0x58
	movs r0, #0
	movs r1, #0x78
	movs r3, #3
	bl sub_080E8F80
.L080DB45A:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080DB460: .4byte 0x020399E0 @ EWRAM+0x399E0

	thumb_func_start sub_080DB464
sub_080DB464: @ 0x080DB464
.L080DB464:
	push {r4, r5, lr}
	ldr r5, .L080DB4A4
	ldrh r0, [r5, #0x38]
	bl sub_080C263C
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #1
	bl sub_080C3818
	movs r0, #0
	adds r1, r4, #0
	bl sub_080E8E00
	str r0, [r5, #0x48]
	adds r0, r4, #0
	bl sub_080DB3E4
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r2, #0x58
	movs r0, #0
	movs r1, #0x78
	movs r3, #3
	bl sub_080E8F80
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DB4A4: .4byte 0x020399E0 @ EWRAM+0x399E0

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

	thumb_func_start sub_080DB8A4
sub_080DB8A4: @ 0x080DB8A4
.L080DB8A4:
	push {r4, r5, lr}
	movs r3, #0
	movs r2, #0
	ldr r5, .L080DB8C8
	ldr r4, .L080DB8CC
	ldr r1, .L080DB8D0
.L080DB8B0:
	ldrh r0, [r1]
	cmp r0, r5
	beq .L080DB8B8
	adds r3, #1
.L080DB8B8:
	adds r1, #2
	adds r2, #1
	cmp r2, r4
	bls .L080DB8B0
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
.L080DB8C8: .4byte 0x0000FFFF
.L080DB8CC: .4byte 0x0000017B
.L080DB8D0: .4byte 0x0203B554 @ EWRAM+0x3B554

	thumb_func_start sub_080DB8D4
sub_080DB8D4: @ 0x080DB8D4
.L080DB8D4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #0
	movs r5, #0
	ldr r0, .L080DB910
	mov r8, r0
	ldr r4, .L080DB914
	ldr r0, .L080DB918
	adds r7, r0, #0
.L080DB8E8:
	ldrh r0, [r4]
	cmp r0, r8
	beq .L080DB8FA
	ands r0, r7
	bl sub_080C2644
	cmp r0, #0
	beq .L080DB8FA
	adds r6, #1
.L080DB8FA:
	adds r4, #2
	adds r5, #1
	ldr r0, .L080DB91C
	cmp r5, r0
	bls .L080DB8E8
	adds r0, r6, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080DB910: .4byte 0x0000FFFF
.L080DB914: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DB918: .4byte 0x00007FFF
.L080DB91C: .4byte 0x0000017B

	thumb_func_start sub_080DB920
sub_080DB920: @ 0x080DB920
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080DB8A4
	cmp r0, #0
	beq .L080DB92E
	movs r0, #1
.L080DB92E:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080DB938
sub_080DB938: @ 0x080DB938
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r4, .L080DB9A4
	ldrh r0, [r4, #0x38]
	bl sub_080BF648
	adds r6, r0, #0
	movs r7, #0x7e
	movs r0, #7
	mov r8, r0
	ldr r0, [r4, #0x38]
	bl sub_080C2644
	ldr r5, .L080DB9A8
	cmp r0, #0
	beq .L080DB960
	adds r5, r6, #0
	adds r5, #0x22
.L080DB960:
	movs r4, #0
	ldrh r0, [r5]
	cmp r0, #0
	beq .L080DB998
.L080DB968:
	lsls r0, r4, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	mov r1, r8
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r7, #0
	bl FontSprite_DrawGlyph
	adds r0, r7, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #7
	bhi .L080DB998
	lsls r0, r4, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080DB968
.L080DB998:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080DB9A4: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DB9A8: .4byte gUnknown_0858325A

	thumb_func_start sub_080DB9AC
sub_080DB9AC: @ 0x080DB9AC
	push {lr}
	ldr r0, .L080DB9BC
	ldr r1, .L080DB9C0
	bl Task_Create
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DB9BC: .4byte gUnknown_0858326C
.L080DB9C0: .4byte 0x0000FFFF

	thumb_func_start sub_080DB9C4
sub_080DB9C4: @ 0x080DB9C4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
.L080DB9CA:
	movs r0, #0x64
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, .L080DB9FC
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq .L080DB9E8
	ldr r1, [r2, #0x20]
	ldr r0, .L080DBA00
	cmp r1, r0
	bne .L080DB9E8
	adds r0, r2, #0
	bl Task_End
.L080DB9E8:
	adds r4, #1
	cmp r4, #0x3f
	bls .L080DB9CA
	adds r0, r5, #0
	bl sub_080D9D8C
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DB9FC: .4byte 0x02009004 @ EWRAM+0x9004
.L080DBA00: .4byte sub_080DB938

	thumb_func_start sub_080DBA04
sub_080DBA04: @ 0x080DBA04
	adds r0, #0x24
	ldr r1, .L080DBA18
	adds r2, r1, #0
	adds r2, #0x44
	ldrh r2, [r2]
	strh r2, [r0, #0xc]
	adds r1, #0x46
	ldrh r1, [r1]
	strh r1, [r0, #0xe]
	bx lr
.L080DBA18: .4byte 0x020399E0 @ EWRAM+0x399E0

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
	bl sub_080DB8A4
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

	thumb_func_start sub_080DBCAC
sub_080DBCAC: @ 0x080DBCAC
	push {lr}
	sub sp, #8
	bl Task_GetParent
	ldr r1, .L080DBCD8
	ldrh r0, [r0, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x64
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x14
	bl Text_DrawSpriteString
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DBCD8: .4byte gUnknown_0858329C

	thumb_func_start sub_080DBCDC
sub_080DBCDC: @ 0x080DBCDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r0, #0x24
	mov sb, r0
	movs r0, #0x10
	mov sl, r0
	bl sub_080DB8A4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r1, sb
	ldrh r0, [r1, #0x10]
	cmp r0, #0
	beq .L080DBD2A
	ldr r0, .L080DBD70
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x5a
	str r1, [sp, #4]
	mov r1, sb
	ldrh r2, [r1, #0xc]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0x88
	lsls r2, r2, #0xd
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
.L080DBD2A:
	ldr r0, .L080DBD74
	ldrh r0, [r0, #0x3e]
	cmp r0, #1
	bne .L080DBE00
	movs r5, #0
	subs r4, #1
	str r4, [sp, #0xc]
.L080DBD38:
	mov r1, sb
	ldrh r0, [r1, #0xe]
	adds r0, r0, r5
	lsls r0, r0, #1
	ldr r2, .L080DBD78
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L080DBD7C
	adds r2, r5, #1
	mov r8, r2
	cmp r1, r0
	beq .L080DBDBA
	ldr r2, .L080DBD80
	adds r0, r2, #0
	adds r4, r0, #0
	ands r4, r1
	adds r0, r4, #0
	bl sub_080C2644
	cmp r0, #0
	beq .L080DBD84
	adds r0, r4, #0
	bl sub_080BF648
	adds r1, r0, #0
	adds r1, #0x22
	b .L080DBD86
	.byte 0x00, 0x00
.L080DBD70: .4byte gUnknown_0800853C
.L080DBD74: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DBD78: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DBD7C: .4byte 0x0000FFFF
.L080DBD80: .4byte 0x00007FFF
.L080DBD84:
	ldr r1, .L080DBDFC
.L080DBD86:
	movs r6, #0
	lsls r0, r5, #1
	adds r2, r5, #1
	mov r8, r2
	adds r0, r0, r5
	lsls r0, r0, #2
	add r0, sl
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r0, #0x5c
	lsls r5, r0, #0x10
	adds r4, r1, #0
.L080DBD9E:
	ldrh r0, [r4]
	lsrs r3, r5, #0x10
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r5, r5, r1
	adds r4, #2
	adds r6, #1
	cmp r6, #7
	bls .L080DBD9E
.L080DBDBA:
	mov r5, r8
	cmp r5, #5
	bls .L080DBD38
	mov r2, sb
	ldrh r0, [r2, #0xe]
	cmp r0, #0
	beq .L080DBDDC
	movs r2, #0x5c
	adds r2, #0x60
	mov r3, sl
	subs r3, #4
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0
	movs r1, #0
	bl sub_080C4A4C
.L080DBDDC:
	mov r1, sb
	ldrh r0, [r1, #0xe]
	adds r0, #6
	ldr r2, [sp, #0xc]
	cmp r0, r2
	bgt .L080DBE14
	movs r2, #0x5c
	adds r2, #0x60
	mov r3, sl
	adds r3, #0x4c
	movs r0, #0
	movs r1, #0
	bl sub_080C4AB0
	b .L080DBE14
	.byte 0x00, 0x00
.L080DBDFC: .4byte gUnknown_0858325A
.L080DBE00:
	ldr r0, .L080DBE80
	mov r1, sl
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x5c
	bl Text_DrawSpriteString
.L080DBE14:
	bl sub_080DB8D4
	adds r4, r0, #0
	bl sub_080DB8A4
	adds r1, r0, #0
	movs r2, #0x81
	movs r3, #0x6a
	adds r0, r4, #0
	bl sub_080DA764
	mov r2, sb
	ldrh r0, [r2, #0x10]
	cmp r0, #0
	bne .L080DBE56
	ldr r0, [r2, #0x18]
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x10
	str r1, [sp, #4]
	ldrh r2, [r2]
	movs r1, #0xb
	muls r1, r2, r1
	adds r1, #0xe
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
.L080DBE56:
	mov r1, sb
	ldr r0, [r1, #0x14]
	movs r1, #0
	str r1, [sp]
	movs r1, #0x10
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DBE80: .4byte gUnknown_0800974E

	thumb_func_start sub_080DBE84
sub_080DBE84: @ 0x080DBE84
	push {r4, lr}
	bl Task_GetParent
	adds r4, r0, #0
	movs r0, #1
	bl sub_080C3818
	movs r0, #1
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080DBE9C
sub_080DBE9C: @ 0x080DBE9C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r1, #0x24
	adds r1, r1, r0
	mov sb, r1
	ldr r2, .L080DBF78
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x52
	str r1, [sp, #4]
	ldrh r1, [r0, #0x24]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x12
	movs r1, #0x88
	lsls r1, r1, #0xd
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r2, #0
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	movs r4, #0
.L080DBEDA:
	mov r2, sb
	ldrh r0, [r2, #2]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bls .L080DBEEE
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080DBEEE:
	bl Race_GetName
	movs r6, #0
	lsls r1, r4, #1
	adds r2, r4, #1
	mov r8, r2
	movs r2, #0x2b
	subs r2, #1
	mov sl, r2
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, #0x10
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	movs r1, #0x54
	lsls r5, r1, #0x10
	adds r4, r0, #0
.L080DBF10:
	ldrh r0, [r4]
	lsrs r3, r5, #0x10
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
	movs r2, #0xc0
	lsls r2, r2, #0xc
	adds r5, r5, r2
	adds r4, #2
	adds r6, #1
	cmp r6, #7
	bls .L080DBF10
	mov r4, r8
	cmp r4, #5
	bls .L080DBEDA
	mov r1, sb
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq .L080DBF4E
	movs r2, #0x54
	adds r2, #0x60
	movs r3, #0x10
	subs r3, #4
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0
	movs r1, #0
	bl sub_080C4A4C
.L080DBF4E:
	mov r2, sb
	ldrh r0, [r2, #2]
	adds r0, #6
	cmp r0, sl
	bgt .L080DBF68
	movs r2, #0x54
	adds r2, #0x60
	movs r3, #0x10
	adds r3, #0x4c
	movs r0, #0
	movs r1, #0
	bl sub_080C4AB0
.L080DBF68:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080DBF78: .4byte gUnknown_0800853C

	thumb_func_start sub_080DBF7C
sub_080DBF7C: @ 0x080DBF7C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x24
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r7, r5, #0
	cmp r5, #5
	bls .L080DBF90
	movs r7, #6
.L080DBF90:
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	ldr r3, .L080DBFB0
	ldrh r1, [r3]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DBFB4
	ldrh r0, [r4, #0x24]
	adds r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #0x65
	b .L080DBFC0
	.byte 0x00, 0x00
.L080DBFB0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DBFB4:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DBFC8
	movs r0, #0x66
.L080DBFC0:
	bl sub_080C51D4
	strh r6, [r4, #0x1c]
	b .L080DC09A
.L080DBFC8:
	ldr r1, .L080DBFE0
	ldrh r3, [r1]
	movs r0, #0x40
	ands r0, r3
	cmp r0, #0
	beq .L080DBFF0
	ldrh r0, [r4, #0x24]
	cmp r0, #0
	beq .L080DBFE4
	subs r0, #1
	strh r0, [r4, #0x24]
	b .L080DC050
.L080DBFE0: .4byte 0x03003964 @ IWRAM+0x3964
.L080DBFE4:
	ldrh r0, [r2, #2]
	cmp r0, #0
	beq .L080DC09A
	subs r0, #1
	strh r0, [r2, #2]
	b .L080DC050
.L080DBFF0:
	movs r0, #0x80
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq .L080DC020
	ldrh r1, [r4, #0x24]
	subs r0, r7, #1
	cmp r1, r0
	beq .L080DC00A
	adds r0, r1, #1
	strh r0, [r4, #0x24]
	b .L080DC050
.L080DC00A:
	cmp r1, #5
	bne .L080DC09A
	ldrh r3, [r2, #2]
	adds r0, r1, r3
	adds r0, #1
	subs r1, r5, #1
	cmp r0, r1
	bgt .L080DC09A
	adds r0, r3, #1
	strh r0, [r2, #2]
	b .L080DC050
.L080DC020:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r3
	cmp r0, #0
	beq .L080DC058
	cmp r5, #6
	bls .L080DC058
	ldrh r3, [r4, #0x24]
	ldrh r1, [r2, #2]
	adds r0, r3, #0
	cmp r0, #0
	beq .L080DC03C
	strh r6, [r4, #0x24]
	b .L080DC044
.L080DC03C:
	cmp r1, #4
	bls .L080DC042
	subs r0, r1, #5
.L080DC042:
	strh r0, [r2, #2]
.L080DC044:
	ldrh r0, [r2]
	cmp r3, r0
	bne .L080DC050
	ldrh r2, [r2, #2]
	cmp r1, r2
	beq .L080DC09A
.L080DC050:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DC09A
.L080DC058:
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080DC09A
	cmp r5, #6
	bls .L080DC09A
	ldrh r3, [r2]
	ldrh r4, [r2, #2]
	cmp r3, #5
	beq .L080DC076
	movs r0, #5
	strh r0, [r2]
	b .L080DC088
.L080DC076:
	adds r0, r3, r4
	adds r0, #6
	subs r1, r5, #1
	cmp r0, r1
	bge .L080DC084
	adds r0, r4, #6
	b .L080DC086
.L080DC084:
	subs r0, r5, #6
.L080DC086:
	strh r0, [r2, #2]
.L080DC088:
	ldrh r0, [r2]
	cmp r3, r0
	bne .L080DC094
	ldrh r2, [r2, #2]
	cmp r4, r2
	beq .L080DC09A
.L080DC094:
	movs r0, #0x64
	bl sub_080C51D4
.L080DC09A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080DC0A0
sub_080DC0A0: @ 0x080DC0A0
	push {lr}
	ldrh r2, [r0, #0x24]
	ldrh r3, [r0, #0x26]
	adds r2, r2, r3
	bl Dict_BuildList
	pop {r0}
	bx r0

	thumb_func_start sub_080DC0B0
sub_080DC0B0: @ 0x080DC0B0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl Task_GetParent
	adds r4, r0, #0
	bl Task_GetParent
	adds r1, r0, #0
	ldrb r0, [r5, #6]
	cmp r0, #0
	bne .L080DC0E4
	ldr r0, .L080DC0E0
	ldrh r1, [r1, #2]
	bl Task_Create
	adds r0, r4, #0
	bl sub_080D9B34
	adds r0, r4, #0
	bl Task_End
	movs r0, #1
	b .L080DC0E6
	.byte 0x00, 0x00
.L080DC0E0: .4byte gUnknown_08583CA0
.L080DC0E4:
	movs r0, #0
.L080DC0E6:
	strh r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080DC0F0
sub_080DC0F0: @ 0x080DC0F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r1, #0x24
	adds r1, r1, r0
	mov sl, r1
	ldr r2, .L080DC1CC
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x52
	str r1, [sp, #4]
	ldrh r1, [r0, #0x24]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x12
	movs r1, #0x88
	lsls r1, r1, #0xd
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r2, #0
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	movs r1, #0
	ldr r2, .L080DC1D0
	mov sb, r2
.L080DC132:
	mov r2, sl
	ldrh r0, [r2, #2]
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, .L080DC1D4
	adds r0, r0, r2
	ldr r6, [r0]
	ldrh r0, [r6]
	adds r2, r1, #1
	mov r8, r2
	cmp r0, sb
	beq .L080DC17E
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r4, r6, #0
	movs r0, #0x54
	lsls r5, r0, #0x10
.L080DC15C:
	ldrh r0, [r4]
	lsrs r3, r5, #0x10
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
	adds r4, #2
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r5, r5, r1
	adds r0, r6, #4
	cmp r4, r0
	bhi .L080DC17E
	ldrh r0, [r4]
	cmp r0, sb
	bne .L080DC15C
.L080DC17E:
	mov r1, r8
	cmp r1, #5
	bls .L080DC132
	mov r2, sl
	ldrh r0, [r2, #2]
	cmp r0, #0
	beq .L080DC1A0
	movs r2, #0x54
	adds r2, #0x60
	movs r3, #0x10
	subs r3, #4
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0
	movs r1, #0
	bl sub_080C4A4C
.L080DC1A0:
	mov r1, sl
	ldrh r0, [r1, #2]
	adds r0, #6
	cmp r0, #9
	bgt .L080DC1BA
	movs r2, #0x54
	adds r2, #0x60
	movs r3, #0x10
	adds r3, #0x4c
	movs r0, #0
	movs r1, #0
	bl sub_080C4AB0
.L080DC1BA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DC1CC: .4byte gUnknown_0800853C
.L080DC1D0: .4byte 0x00000301
.L080DC1D4: .4byte gUnknown_0858367C

	thumb_func_start sub_080DC1D8
sub_080DC1D8: @ 0x080DC1D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r1, #0x24
	adds r1, r1, r0
	mov sb, r1
	movs r3, #0x54
	mov sl, r3
	ldr r2, .L080DC2A8
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x52
	str r1, [sp, #4]
	ldrh r1, [r0, #0x24]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x12
	movs r1, #0x88
	lsls r1, r1, #0xd
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r2, #0
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	movs r2, #0
.L080DC21A:
	mov r3, sb
	ldrh r1, [r3, #2]
	adds r1, r1, r2
	lsls r1, r1, #2
	ldr r0, .L080DC2AC
	adds r1, r1, r0
	movs r6, #0
	lsls r0, r2, #1
	adds r3, r2, #1
	mov r8, r3
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r0, sl
	lsls r5, r0, #0x10
	ldr r4, [r1]
.L080DC23E:
	ldrh r0, [r4]
	lsrs r3, r5, #0x10
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r5, r5, r1
	adds r4, #2
	adds r6, #1
	cmp r6, #7
	bls .L080DC23E
	mov r2, r8
	cmp r2, #5
	bls .L080DC21A
	mov r3, sb
	ldrh r0, [r3, #2]
	cmp r0, #0
	beq .L080DC27C
	mov r2, sl
	adds r2, #0x60
	movs r3, #0x10
	subs r3, #4
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0
	movs r1, #0
	bl sub_080C4A4C
.L080DC27C:
	mov r1, sb
	ldrh r0, [r1, #2]
	adds r0, #6
	cmp r0, #0xa
	bgt .L080DC296
	mov r2, sl
	adds r2, #0x60
	movs r3, #0x10
	adds r3, #0x4c
	movs r0, #0
	movs r1, #0
	bl sub_080C4AB0
.L080DC296:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DC2A8: .4byte gUnknown_0800853C
.L080DC2AC: .4byte gUnknown_08583788

	thumb_func_start sub_080DC2B0
sub_080DC2B0: @ 0x080DC2B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #0x24
	adds r0, r0, r4
	mov sl, r0
	bl sub_080DB8A4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L080DC338
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x52
	str r1, [sp, #4]
	ldrh r2, [r4, #0x24]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0x88
	lsls r2, r2, #0xd
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DC33C
	ldrh r0, [r0, #0x3e]
	cmp r0, #1
	bne .L080DC3EE
	movs r5, #0
	subs r6, #1
	str r6, [sp, #0xc]
.L080DC302:
	mov r1, sl
	ldrh r0, [r1, #2]
	adds r0, r0, r5
	lsls r0, r0, #1
	ldr r2, .L080DC340
	adds r0, r0, r2
	ldrh r6, [r0]
	ldr r0, .L080DC344
	adds r1, r5, #1
	mov sb, r1
	cmp r6, r0
	beq .L080DC3AE
	ldr r2, .L080DC348
	adds r0, r2, #0
	adds r4, r6, #0
	ands r4, r0
	adds r0, r4, #0
	bl sub_080C2644
	cmp r0, #0
	beq .L080DC34C
	adds r0, r4, #0
	bl sub_080BF648
	adds r0, #0x22
	b .L080DC34E
	.byte 0x00, 0x00
.L080DC338: .4byte gUnknown_0800853C
.L080DC33C: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DC340: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DC344: .4byte 0x0000FFFF
.L080DC348: .4byte 0x00007FFF
.L080DC34C:
	ldr r0, .L080DC388
.L080DC34E:
	mov r8, r0
	lsls r0, r5, #1
	adds r1, r5, #1
	mov sb, r1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r2, #0x54
	lsls r5, r2, #0x10
	mov r4, r8
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
	ands r6, r0
	lsls r0, r6, #0x10
	lsrs r6, r0, #0x10
.L080DC372:
	cmp r6, #0
	bne .L080DC38C
	ldrh r0, [r4]
	lsrs r3, r5, #0x10
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyph
	b .L080DC39E
	.byte 0x00, 0x00
.L080DC388: .4byte gUnknown_0858325A
.L080DC38C:
	ldrh r0, [r4]
	lsrs r3, r5, #0x10
	str r7, [sp]
	movs r1, #1
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	bl FontSprite_DrawGlyphTinted
.L080DC39E:
	movs r2, #0xc0
	lsls r2, r2, #0xc
	adds r5, r5, r2
	adds r4, #2
	mov r0, r8
	adds r0, #0xe
	cmp r4, r0
	bls .L080DC372
.L080DC3AE:
	mov r5, sb
	cmp r5, #5
	bls .L080DC302
	mov r1, sl
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq .L080DC3D0
	movs r2, #0x54
	adds r2, #0x60
	movs r3, #0x10
	subs r3, #4
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0
	movs r1, #0
	bl sub_080C4A4C
.L080DC3D0:
	mov r2, sl
	ldrh r0, [r2, #2]
	adds r0, #6
	ldr r1, [sp, #0xc]
	cmp r0, r1
	bgt .L080DC402
	movs r2, #0x54
	adds r2, #0x60
	movs r3, #0x10
	adds r3, #0x4c
	movs r0, #0
	movs r1, #0
	bl sub_080C4AB0
	b .L080DC402
.L080DC3EE:
	ldr r0, .L080DC414
	movs r2, #0x10
	str r2, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x54
	bl Text_DrawSpriteString
.L080DC402:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DC414: .4byte gUnknown_0800974E

	thumb_func_start sub_080DC418
sub_080DC418: @ 0x080DC418
.L080DC418:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r5, .L080DC454
	ldr r1, .L080DC458
	mov ip, r1
	ldrh r2, [r0, #0x24]
	ldrh r3, [r4, #2]
	adds r1, r2, r3
	mov r6, ip
	strh r1, [r6, #0x3c]
	mov r1, ip
	adds r1, #0x44
	strh r2, [r1]
	adds r1, #2
	strh r3, [r1]
	ldrh r1, [r0, #0x24]
	ldrh r2, [r4, #2]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	ldr r1, .L080DC45C
	ands r1, r2
	str r1, [r6, #0x38]
	bl sub_080DB464
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080DC454: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DC458: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DC45C: .4byte 0x00007FFF

	thumb_func_start sub_080DC460
sub_080DC460: @ 0x080DC460
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x24
	bl Task_GetParent
	mov r8, r0
	bl sub_080DB8A4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r7, #0
	ldr r0, .L080DC4B8
	ldrh r3, [r0, #0x3e]
	cmp r3, #0
	bne .L080DC486
	movs r5, #1
.L080DC486:
	mov ip, r5
	cmp r5, #5
	bls .L080DC490
	movs r0, #6
	mov ip, r0
.L080DC490:
	strh r7, [r6, #0x1c]
	strh r7, [r6, #0x1e]
	ldr r2, .L080DC4BC
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080DC4C0
	cmp r3, #1
	bne .L080DC4C0
	movs r7, #1
	movs r0, #0x65
	bl sub_080C51D4
	strh r7, [r6, #0x1c]
	movs r0, #0
	mov r1, r8
	strb r0, [r1, #6]
	b .L080DC5B4
	.byte 0x00, 0x00
.L080DC4B8: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DC4BC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DC4C0:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DC4DC
	movs r0, #0x66
	bl sub_080C51D4
	movs r1, #1
	movs r0, #1
	strh r0, [r6, #0x1c]
	mov r0, r8
	strb r1, [r0, #6]
	b .L080DC5B4
.L080DC4DC:
	ldr r1, .L080DC4F4
	ldrh r2, [r1]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L080DC504
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080DC4F8
	subs r0, #1
	strh r0, [r4]
	b .L080DC566
.L080DC4F4: .4byte 0x03003964 @ IWRAM+0x3964
.L080DC4F8:
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq .L080DC5B4
	subs r0, #1
	strh r0, [r4, #2]
	b .L080DC566
.L080DC504:
	movs r0, #0x80
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq .L080DC536
	ldrh r1, [r4]
	mov r0, ip
	subs r0, #1
	cmp r1, r0
	beq .L080DC520
	adds r0, r1, #1
	strh r0, [r4]
	b .L080DC566
.L080DC520:
	cmp r1, #5
	bne .L080DC5B4
	ldrh r2, [r4, #2]
	adds r0, r1, r2
	adds r0, #1
	subs r1, r5, #1
	cmp r0, r1
	bgt .L080DC5B4
	adds r0, r2, #1
	strh r0, [r4, #2]
	b .L080DC566
.L080DC536:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080DC570
	cmp r5, #6
	bls .L080DC570
	ldrh r2, [r4]
	ldrh r1, [r4, #2]
	adds r0, r2, #0
	cmp r0, #0
	beq .L080DC552
	strh r3, [r4]
	b .L080DC55A
.L080DC552:
	cmp r1, #4
	bls .L080DC558
	subs r0, r1, #5
.L080DC558:
	strh r0, [r4, #2]
.L080DC55A:
	ldrh r0, [r4]
	cmp r2, r0
	bne .L080DC566
	ldrh r4, [r4, #2]
	cmp r1, r4
	beq .L080DC5B4
.L080DC566:
	movs r7, #1
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DC5B4
.L080DC570:
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080DC5B4
	cmp r5, #6
	bls .L080DC5B4
	ldrh r2, [r4]
	ldrh r3, [r4, #2]
	cmp r2, #5
	beq .L080DC58E
	movs r0, #5
	strh r0, [r4]
	b .L080DC5A0
.L080DC58E:
	adds r0, r2, r3
	adds r0, #6
	subs r1, r5, #1
	cmp r0, r1
	bge .L080DC59C
	adds r0, r3, #6
	b .L080DC59E
.L080DC59C:
	subs r0, r5, #6
.L080DC59E:
	strh r0, [r4, #2]
.L080DC5A0:
	ldrh r1, [r4]
	cmp r2, r1
	bne .L080DC5AC
	ldrh r4, [r4, #2]
	cmp r3, r4
	beq .L080DC5B4
.L080DC5AC:
	movs r7, #1
	movs r0, #0x64
	bl sub_080C51D4
.L080DC5B4:
	cmp r7, #1
	bne .L080DC5BE
	adds r0, r6, #0
	bl sub_080DC418
.L080DC5BE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080DC5C8
sub_080DC5C8: @ 0x080DC5C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	ldr r6, .L080DC5EC
	ldrh r0, [r6, #0x3e]
	cmp r0, #1
	bne .L080DC60C
	bl sub_080DB8A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r0, #0
	cmp r2, #6
	bhi .L080DC5F0
	ldrh r0, [r6, #0x3c]
	strh r0, [r5, #0x24]
	b .L080DC610
.L080DC5EC: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DC5F0:
	ldrh r1, [r6, #0x3c]
	subs r0, r2, #7
	cmp r1, r0
	ble .L080DC608
	adds r0, r1, #6
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r1, r0
	strh r1, [r4, #2]
	strh r0, [r5, #0x24]
	b .L080DC610
.L080DC608:
	strh r1, [r4, #2]
	b .L080DC610
.L080DC60C:
	movs r0, #0
	strh r0, [r4, #2]
.L080DC610:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080DC618
sub_080DC618: @ 0x080DC618
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	ldr r2, .L080DC63C
	ldrh r1, [r2]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DC640
	ldrh r0, [r4, #0x24]
	adds r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #0x65
	b .L080DC64E
	.byte 0x00, 0x00
.L080DC63C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DC640:
	ldrh r1, [r2]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DC656
	movs r0, #0x66
.L080DC64E:
	bl sub_080C51D4
	strh r5, [r4, #0x1c]
	b .L080DC69E
.L080DC656:
	ldr r0, .L080DC674
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L080DC682
	ldrh r0, [r4, #0x24]
	cmp r0, #0
	beq .L080DC678
	subs r0, #1
	strh r0, [r4, #0x24]
	b .L080DC67A
	.byte 0x00, 0x00
.L080DC674: .4byte 0x03003964 @ IWRAM+0x3964
.L080DC678:
	strh r3, [r4, #0x24]
.L080DC67A:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DC69E
.L080DC682:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080DC69E
	ldrh r0, [r4, #0x24]
	cmp r0, #2
	beq .L080DC696
	adds r0, #1
	strh r0, [r4, #0x24]
	b .L080DC698
.L080DC696:
	strh r2, [r4, #0x24]
.L080DC698:
	movs r0, #0x64
	bl sub_080C51D4
.L080DC69E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080DC6A4
sub_080DC6A4: @ 0x080DC6A4
	ldr r1, .L080DC6B8
	ldr r0, .L080DC6BC
	str r0, [r1]
	ldr r0, .L080DC6C0
	str r0, [r1, #4]
	ldr r0, .L080DC6C4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080DC6B8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DC6BC: .4byte 0x0200F874 @ EWRAM+0xF874
.L080DC6C0: .4byte 0x06010000 @ VRAM+0x10000
.L080DC6C4: .4byte 0x84001400

	thumb_func_start sub_080DC6C8
sub_080DC6C8: @ 0x080DC6C8
.L080DC6C8:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080DC6D0
sub_080DC6D0: @ 0x080DC6D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r1, #0
	movs r0, #0
	mov sb, r0
	ldr r5, .L080DC7B4
	ldrh r0, [r5, #0x38]
	bl sub_080DC6C8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF648
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x11
	str r1, [sp, #0x14]
	ldr r2, .L080DC7B8
	ldrb r0, [r2]
	movs r1, #0x3f
	orrs r0, r1
	strb r0, [r2]
	mov r6, sb
	str r6, [sp, #0x10]
	ldr r0, .L080DC7BC
	mov sl, r0
	ldr r2, .L080DC7C0
	add r0, sp, #0x10
	mov r1, sl
	bl CpuSet
	cmp r4, #0
	beq .L080DC71C
	b .L080DC8C4
.L080DC71C:
	ldr r0, .L080DC7C4
	movs r1, #0
	movs r2, #2
	movs r3, #4
	bl sub_080CCE5C
	movs r0, #0
	ldrsb r0, [r7, r0]
	bl Race_GetParentId
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl ParentRace_GetName
	adds r1, r0, #0
	cmp r1, #0
	beq .L080DC750
	str r6, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	adds r0, r1, #0
	mov r1, sl
	movs r2, #4
	movs r3, #0xe
	bl Text_DrawStringTinted
.L080DC750:
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Race_GetName
	adds r1, r0, #0
	cmp r1, #0
	beq .L080DC776
	mov r6, sb
	str r6, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	adds r0, r1, #0
	mov r1, sl
	movs r2, #4
	movs r3, #0x1d
	bl Text_DrawStringTinted
.L080DC776:
	movs r5, #0
	movs r0, #0xb0
	lsls r0, r0, #0xe
	mov r8, r0
	movs r1, #4
	mov sl, r1
	adds r4, r7, #0
	adds r4, #0x22
.L080DC786:
	ldrh r0, [r4]
	mov r6, sl
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0
	str r1, [sp]
	ldr r1, .L080DC7BC
	mov r6, r8
	lsrs r3, r6, #0x10
	bl Font_DrawGlyphTinted
	movs r0, #0xc
	add sl, r0
	adds r4, #2
	adds r5, #1
	cmp r5, #7
	bls .L080DC786
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0xc
	bgt .L080DC7CC
	ldr r1, .L080DC7C8
	b .L080DC7D4
.L080DC7B4: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DC7B8: .4byte 0x03000038 @ IWRAM+0x38
.L080DC7BC: .4byte 0x0200F874 @ EWRAM+0xF874
.L080DC7C0: .4byte 0x05002000
.L080DC7C4: .4byte gUnknown_08583A58
.L080DC7C8: .4byte gUnknown_08583A28
.L080DC7CC:
	ldr r1, .L080DC8B0
	cmp r0, #0x1a
	bgt .L080DC7D4
	subs r1, #0x10
.L080DC7D4:
	ldr r7, .L080DC8B4
	movs r4, #4
	movs r3, #0x3b
	movs r6, #0
	str r6, [sp]
	movs r5, #0xc
	str r5, [sp, #4]
	adds r0, r1, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl Text_DrawStringTinted
	ldr r0, .L080DC8B8
	ldr r0, [r0, #0x38]
	bl sub_0815B864
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C06AC
	adds r1, r0, #0
	cmp r1, #0
	beq .L080DC810
	movs r3, #0x4b
	str r6, [sp]
	str r5, [sp, #4]
	adds r1, r7, #0
	adds r2, r4, #0
	bl Text_DrawStringTinted
.L080DC810:
	ldr r0, .L080DC8BC
	movs r1, #0x6a
	movs r2, #2
	movs r3, #4
	bl sub_080CCE5C
	movs r5, #0
.L080DC81E:
	ldr r1, [sp, #0x14]
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #0xff
	beq .L080DC840
	mov r2, sb
	adds r2, #0xe
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0x6e
	bl sub_080CD1F8
	mov r0, sb
	adds r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
.L080DC840:
	adds r5, #1
	cmp r5, #6
	bls .L080DC81E
	movs r5, #0
	ldr r2, .L080DC8B4
.L080DC84A:
	ldr r6, [sp, #0x14]
	adds r0, r6, r5
	ldrb r0, [r0]
	adds r5, #1
	mov r8, r5
	cmp r0, #0xff
	bne .L080DC88C
	movs r5, #0
	mov r0, sb
	adds r0, #0xe
	mov r7, sb
	adds r7, #0xf
	lsls r6, r0, #0x10
	movs r0, #0x6e
	lsls r4, r0, #0x10
.L080DC868:
	lsrs r2, r4, #0x10
	movs r0, #0
	str r0, [sp]
	movs r0, #0x3c
	ldr r1, .L080DC8B4
	lsrs r3, r6, #0x10
	bl Font_DrawGlyphTinted
	movs r1, #0xc0
	lsls r1, r1, #0xc
	adds r4, r4, r1
	adds r5, #1
	cmp r5, #7
	bls .L080DC868
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	ldr r2, .L080DC8B4
.L080DC88C:
	mov r5, r8
	cmp r5, #6
	bls .L080DC84A
	ldr r0, .L080DC8C0
	movs r1, #0x96
	str r1, [sp]
	movs r1, #0x80
	str r1, [sp, #4]
	movs r1, #8
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r2, #0
	movs r2, #0
	movs r3, #0
	bl Canvas_BlitOr
	b .L080DCB68
	.byte 0x00, 0x00
.L080DC8B0: .4byte gUnknown_08583A48
.L080DC8B4: .4byte 0x0200F874 @ EWRAM+0xF874
.L080DC8B8: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DC8BC: .4byte gUnknown_08583A60
.L080DC8C0: .4byte gUnknown_081B1DB8
.L080DC8C4:
	ldr r6, .L080DCB94
	str r6, [sp, #0x18]
	adds r4, r6, #0
	adds r4, #0x88
	ldrh r0, [r5, #0x38]
	bl sub_080DC6C8
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r1, #4
	bl sub_080C0444
	ldr r0, .L080DCB98
	movs r1, #0
	movs r2, #2
	movs r3, #4
	bl sub_080CCE5C
	ldr r0, .L080DCB9C
	movs r4, #4
	movs r1, #4
	movs r2, #0x10
	movs r3, #4
	bl sub_080CCEC8
	ldrb r0, [r7, #1]
	movs r1, #0x45
	movs r2, #0x10
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBA0
	movs r1, #4
	movs r2, #0x1f
	movs r3, #4
	bl sub_080CCEC8
	movs r1, #2
	ldrsh r0, [r7, r1]
	movs r1, #0x45
	movs r2, #0x1f
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBA4
	movs r1, #4
	movs r2, #0x2e
	movs r3, #4
	bl sub_080CCEC8
	movs r6, #4
	ldrsh r0, [r7, r6]
	movs r1, #0x45
	movs r2, #0x2e
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBA8
	movs r1, #4
	movs r2, #0x3d
	movs r3, #4
	bl sub_080CCEC8
	ldrb r0, [r7, #0x1d]
	movs r1, #0x45
	movs r2, #0x3d
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBAC
	mov r8, r0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x55
	movs r3, #0xe
	bl Font_DrawGlyphTinted
	movs r0, #6
	ldrsb r0, [r7, r0]
	movs r1, #0x6d
	movs r2, #0x11
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBB0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x7e
	movs r3, #0xe
	bl Font_DrawGlyphTinted
	movs r0, #7
	ldrsb r0, [r7, r0]
	movs r1, #0x96
	mov sb, r1
	movs r2, #0x11
	movs r3, #0
	bl sub_080CCFC4
	ldr r6, .L080DCBB4
	str r4, [sp]
	adds r0, r6, #0
	mov r1, sl
	movs r2, #0x55
	movs r3, #0x1d
	bl Font_DrawGlyphTinted
	movs r0, #8
	ldrsb r0, [r7, r0]
	movs r1, #0x6d
	movs r2, #0x20
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBB8
	str r4, [sp]
	mov r1, sl
	movs r2, #0x7e
	movs r3, #0x1d
	bl Font_DrawGlyphTinted
	movs r0, #9
	ldrsb r0, [r7, r0]
	movs r1, #0x96
	movs r2, #0x20
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBBC
	str r4, [sp]
	mov r1, sl
	movs r2, #0x55
	movs r3, #0x2c
	bl Font_DrawGlyphTinted
	movs r0, #0xa
	ldrsb r0, [r7, r0]
	movs r1, #0x6d
	movs r2, #0x2f
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBC0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x7e
	movs r3, #0x2c
	bl Font_DrawGlyphTinted
	movs r0, #0xb
	ldrsb r0, [r7, r0]
	movs r1, #0x96
	movs r2, #0x2f
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBC4
	str r4, [sp]
	mov r1, sl
	movs r2, #4
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBC8
	str r4, [sp]
	mov r1, sl
	movs r2, #0x10
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xd0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x45
	movs r2, #0x52
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBCC
	str r4, [sp]
	mov r1, sl
	movs r2, #4
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBD0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x10
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xd2
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x45
	movs r2, #0x61
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBD4
	str r4, [sp]
	mov r1, sl
	movs r2, #4
	movs r3, #0x6e
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBD8
	str r4, [sp]
	mov r1, sl
	movs r2, #0x10
	movs r3, #0x6e
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xd8
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x45
	movs r2, #0x70
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBDC
	str r4, [sp]
	mov r1, sl
	movs r2, #4
	movs r3, #0x7d
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBE0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x10
	movs r3, #0x7d
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xda
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x45
	movs r2, #0x7f
	movs r3, #0
	bl sub_080CCFC4
	str r4, [sp]
	adds r0, r6, #0
	mov r1, sl
	movs r2, #0x55
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	ldr r5, .L080DCBE4
	str r4, [sp]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x61
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBE8
	str r4, [sp]
	mov r1, sl
	movs r2, #0x6d
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	str r4, [sp]
	mov r0, r8
	mov r1, sl
	movs r2, #0x79
	movs r3, #0x50
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xdc
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x96
	movs r2, #0x52
	movs r3, #0
	bl sub_080CCFC4
	str r4, [sp]
	adds r0, r6, #0
	mov r1, sl
	movs r2, #0x55
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	str r4, [sp]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x61
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBEC
	str r4, [sp]
	mov r1, sl
	movs r2, #0x6d
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	ldr r0, .L080DCBF0
	str r4, [sp]
	mov r1, sl
	movs r2, #0x79
	movs r3, #0x5f
	bl Font_DrawGlyphTinted
	ldr r0, [sp, #0x18]
	adds r0, #0xde
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r1, #0x96
	movs r2, #0x61
	movs r3, #0
	bl sub_080CCFC4
	ldr r0, .L080DCBF4
	mov r1, sb
	str r1, [sp]
	movs r1, #5
	str r1, [sp, #4]
	movs r1, #8
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, sl
	movs r2, #0
	movs r3, #0
	bl Canvas_BlitOr
.L080DCB68:
	ldr r1, .L080DCBF8
	ldr r2, .L080DCBFC
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080DCC00
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080DCB94: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080DCB98: .4byte gUnknown_08583A68
.L080DCB9C: .4byte gUnknown_08583A70
.L080DCBA0: .4byte gUnknown_08583A74
.L080DCBA4: .4byte gUnknown_08583A78
.L080DCBA8: .4byte gUnknown_08583A7C
.L080DCBAC: .4byte 0x000010CB
.L080DCBB0: .4byte 0x00000CBA
.L080DCBB4: .4byte 0x00000FC3
.L080DCBB8: .4byte 0x00000C5C
.L080DCBBC: .4byte 0x00000C3C
.L080DCBC0: .4byte 0x00000606
.L080DCBC4: .4byte 0x000008F1
.L080DCBC8: .4byte 0x00000861
.L080DCBCC: .4byte 0x00000FFE
.L080DCBD0: .4byte 0x00000CD3
.L080DCBD4: .4byte 0x00000FA9
.L080DCBD8: .4byte 0x000008C3
.L080DCBDC: .4byte 0x00000699
.L080DCBE0: .4byte 0x00000EB7
.L080DCBE4: .4byte 0x00000F81
.L080DCBE8: .4byte 0x000005BB
.L080DCBEC: .4byte 0x000008D7
.L080DCBF0: .4byte 0x00000672
.L080DCBF4: .4byte gUnknown_081B1D98
.L080DCBF8: .4byte gUnknown_081B6ED0
.L080DCBFC: .4byte 0x030030B0 @ IWRAM+0x30B0
.L080DCC00: .4byte sub_080DC6A4

	thumb_func_start sub_080DCC04
sub_080DCC04: @ 0x080DCC04
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	ldr r2, .L080DCC34
	ldrh r1, [r2]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne .L080DCC72
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DCC38
	movs r0, #0x66
	bl sub_080C51D4
	strh r5, [r4, #0x1c]
	b .L080DCC72
	.byte 0x00, 0x00
.L080DCC34: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DCC38:
	ldr r2, .L080DCC54
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080DCC58
	cmp r3, #1
	bne .L080DCC58
	strh r3, [r4, #0x1c]
	strh r3, [r4, #0x1e]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DCC72
.L080DCC54: .4byte 0x03003964 @ IWRAM+0x3964
.L080DCC58:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080DCC72
	cmp r3, #0
	bne .L080DCC72
	movs r0, #1
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	movs r0, #0x64
	bl sub_080C51D4
.L080DCC72:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080DCC78
sub_080DCC78: @ 0x080DCC78
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0xc
	movs r0, #0x10
	mov sb, r0
	movs r4, #8
	ldr r0, .L080DCD50
	movs r5, #0
	str r5, [sp]
	mov r1, sb
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DCD54
	str r5, [sp]
	movs r1, #0x50
	mov r8, r1
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DCD58
	str r5, [sp]
	movs r6, #0x90
	str r6, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DCD5C
	str r5, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r4, #0x48
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DCD60
	str r5, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DCD64
	str r5, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DCD68
	str r5, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r4, #0x88
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DCD6C
	str r5, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DCD70
	str r5, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DCD50: .4byte gUnknown_08008C54
.L080DCD54: .4byte gUnknown_08008C64
.L080DCD58: .4byte gUnknown_08008C7C
.L080DCD5C: .4byte gUnknown_08008C8C
.L080DCD60: .4byte gUnknown_08008C9C
.L080DCD64: .4byte gUnknown_08008CB4
.L080DCD68: .4byte gUnknown_08008CC4
.L080DCD6C: .4byte gUnknown_08008CD4
.L080DCD70: .4byte gUnknown_08008CEC

	thumb_func_start sub_080DCD74
sub_080DCD74: @ 0x080DCD74
	push {lr}
	ldr r1, .L080DCD9C
	ldr r0, .L080DCDA0
	str r0, [r1]
	ldr r0, .L080DCDA4
	str r0, [r1, #4]
	ldr r0, .L080DCDA8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080DCDAC
	str r0, [r1]
	ldr r0, .L080DCDB0
	str r0, [r1, #4]
	ldr r0, .L080DCDB4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080D9D24
	pop {r0}
	bx r0
.L080DCD9C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DCDA0: .4byte 0x02003000 @ EWRAM+0x3000
.L080DCDA4: .4byte 0x0600EC00 @ VRAM+0xEC00
.L080DCDA8: .4byte 0x84000500
.L080DCDAC: .4byte gUnknown_0857D5C0
.L080DCDB0: .4byte 0x06012F00 @ VRAM+0x12F00
.L080DCDB4: .4byte 0x84000020

	thumb_func_start sub_080DCDB8
sub_080DCDB8: @ 0x080DCDB8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x10
	mov r8, r0
	ldr r2, .L080DCE30
	ldrb r0, [r2]
	movs r1, #0x3f
	orrs r0, r1
	strb r0, [r2]
	ldr r0, .L080DCE34
	ldr r1, .L080DCE38
	movs r2, #0xd8
	lsls r2, r2, #2
	movs r6, #4
	str r6, [sp]
	movs r3, #1
	str r3, [sp, #4]
	movs r3, #0x16
	str r3, [sp, #8]
	movs r3, #0xb
	str r3, [sp, #0xc]
	movs r3, #7
	bl Tilemap_CopyRect
	ldr r1, .L080DCE3C
	ldr r4, .L080DCE40
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080DCE44
	movs r0, #0x90
	lsls r0, r0, #2
	adds r4, r4, r0
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080DCE48
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0
	mov r1, r8
	strh r0, [r1, #0x24]
	strh r6, [r1, #0x26]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080DCE30: .4byte 0x03000038 @ IWRAM+0x38
.L080DCE34: .4byte gUnknown_085805C0
.L080DCE38: .4byte 0x0201D874 @ EWRAM+0x1D874
.L080DCE3C: .4byte gUnknown_08581140
.L080DCE40: .4byte 0x03002E90 @ IWRAM+0x2E90
.L080DCE44: .4byte gUnknown_08581240
.L080DCE48: .4byte sub_080DCD74

	thumb_func_start sub_080DCE4C
sub_080DCE4C: @ 0x080DCE4C
	push {lr}
	ldr r0, .L080DCE68
	ldr r1, [r0, #0x38]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L080DCE6C
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x24
	bl sub_080AF218
	pop {r0}
	bx r0
.L080DCE68: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DCE6C: .4byte gUnknown_08583E84

	thumb_func_start sub_080DCE70
sub_080DCE70: @ 0x080DCE70
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080DCE80
	ldrh r0, [r0]
	cmp r0, #0x24
	bne .L080DCE84
	movs r0, #1
	b .L080DCE86
.L080DCE80: .4byte 0x03004550 @ IWRAM+0x4550
.L080DCE84:
	movs r0, #0
.L080DCE86:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080DCE8C
sub_080DCE8C: @ 0x080DCE8C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r2, r0, #0
	adds r6, r2, #0
	adds r6, #0x24
	ldr r0, .L080DCF10
	ldr r1, [r0, #0x38]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L080DCF14
	adds r7, r0, r1
	ldrh r0, [r6, #2]
	subs r0, #1
	strh r0, [r6, #2]
	ldr r1, .L080DCF18
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne .L080DCEC8
	movs r0, #4
	strh r0, [r6, #2]
	ldrh r0, [r2, #0x24]
	adds r0, #1
	strh r0, [r2, #0x24]
	ands r0, r3
	cmp r0, #3
	bne .L080DCEC8
	strh r1, [r2, #0x24]
.L080DCEC8:
	ldr r5, .L080DCF1C
	ldrh r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	str r4, [sp]
	ldrh r1, [r7, #4]
	str r1, [sp, #4]
	ldrh r1, [r7, #8]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #9
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	str r4, [sp]
	ldrh r1, [r7, #0xc]
	str r1, [sp, #4]
	ldrh r1, [r7, #0x10]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #9
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DCF10: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DCF14: .4byte gUnknown_08583E84
.L080DCF18: .4byte 0x0000FFFF
.L080DCF1C: .4byte gUnknown_08583BEC

	thumb_func_start sub_080DCF20
sub_080DCF20: @ 0x080DCF20
.L080DCF20:
	push {lr}
	bl sub_080DB8A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	cmp r1, #6
	bhi .L080DCF48
	ldr r0, .L080DCF44
	ldrh r2, [r0, #0x3c]
	adds r1, r0, #0
	adds r1, #0x44
	movs r3, #0
	strh r2, [r1]
	adds r0, #0x46
	strh r3, [r0]
	b .L080DCF7C
	.byte 0x00, 0x00
.L080DCF44: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DCF48:
	ldr r3, .L080DCF6C
	ldrh r2, [r3, #0x3c]
	subs r0, r1, #7
	cmp r2, r0
	ble .L080DCF70
	adds r0, r2, #6
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r2, r0
	adds r2, r3, #0
	adds r2, #0x46
	strh r1, [r2]
	adds r1, r3, #0
	adds r1, #0x44
	strh r0, [r1]
	b .L080DCF7C
	.byte 0x00, 0x00
.L080DCF6C: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DCF70:
	adds r0, r3, #0
	adds r0, #0x46
	movs r1, #0
	strh r2, [r0]
	subs r0, #2
	strh r1, [r0]
.L080DCF7C:
	pop {r0}
	bx r0

	thumb_func_start sub_080DCF80
sub_080DCF80: @ 0x080DCF80
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	bl sub_080DB8A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	movs r7, #0
	strh r7, [r5, #0x1c]
	strh r7, [r5, #0x1e]
	ldr r0, .L080DCFCC
	ldrh r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DCFDC
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne .L080DCFDC
	ldr r0, .L080DCFD0
	ldr r0, [r0, #0x38]
	bl sub_080C2644
	cmp r0, #0
	beq .L080DCFD4
	ldrh r0, [r5, #0x24]
	adds r0, #1
	strh r0, [r5, #0x1e]
	movs r0, #0x65
	bl sub_080C51D4
	strh r6, [r5, #0x1c]
	b .L080DD0A0
	.byte 0x00, 0x00
.L080DCFCC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DCFD0: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DCFD4:
	movs r0, #0x66
	bl sub_080C51D4
	b .L080DD0A0
.L080DCFDC:
	ldr r0, .L080DCFFC
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DD000
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne .L080DD000
	movs r0, #0x66
	bl sub_080C51D4
	movs r0, #1
	strh r0, [r5, #0x1c]
	b .L080DD0A0
	.byte 0x00, 0x00
.L080DCFFC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DD000:
	ldr r2, .L080DD01C
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080DD024
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne .L080DD024
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080DD020
	subs r0, #1
	b .L080DD03C
.L080DD01C: .4byte 0x03003964 @ IWRAM+0x3964
.L080DD020:
	movs r0, #1
	b .L080DD03C
.L080DD024:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080DD04A
	ldrh r1, [r4, #0x12]
	cmp r1, #0
	bne .L080DD04A
	ldrh r0, [r4]
	cmp r0, #1
	beq .L080DD040
	adds r0, #1
.L080DD03C:
	strh r0, [r4]
	b .L080DD042
.L080DD040:
	strh r1, [r4]
.L080DD042:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DD0A0
.L080DD04A:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080DD078
	ldrh r3, [r4, #0x12]
	cmp r3, #0
	bne .L080DD078
	ldr r2, .L080DD070
	ldrh r1, [r2, #0x3c]
	mov r0, ip
	subs r0, #1
	cmp r1, r0
	beq .L080DD074
	adds r0, r1, #1
	strh r0, [r2, #0x3c]
	b .L080DD098
	.byte 0x00, 0x00
.L080DD070: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DD074:
	strh r3, [r2, #0x3c]
	b .L080DD098
.L080DD078:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DD0A0
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne .L080DD0A0
	ldr r1, .L080DD108
	ldrh r0, [r1, #0x3c]
	cmp r0, #0
	bne .L080DD094
	mov r0, ip
.L080DD094:
	subs r0, #1
	strh r0, [r1, #0x3c]
.L080DD098:
	adds r0, r5, #0
	bl sub_080DCF20
	movs r7, #1
.L080DD0A0:
	cmp r7, #1
	bne .L080DD0C0
	ldr r1, .L080DD10C
	ldr r2, .L080DD108
	ldrh r0, [r2, #0x3c]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, .L080DD110
	ands r0, r1
	str r0, [r2, #0x38]
	adds r0, r5, #0
	bl sub_080DB464
	movs r0, #0x1e
	strh r0, [r4, #0x12]
.L080DD0C0:
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	beq .L080DD0CA
	subs r0, #1
	strh r0, [r4, #0x12]
.L080DD0CA:
	ldr r0, .L080DD114
	ldr r0, [r0]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080DD120
	ldr r0, .L080DD118
	movs r5, #0x80
	lsls r5, r5, #1
	str r5, [sp]
	movs r1, #0x10
	str r1, [sp, #4]
	movs r4, #0x78
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DD11C
	str r5, [sp]
	movs r1, #0xc9
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	b .L080DD14E
.L080DD108: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DD10C: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DD110: .4byte 0x00007FFF
.L080DD114: .4byte 0x030031BC @ IWRAM+0x31BC
.L080DD118: .4byte gUnknown_08008784
.L080DD11C: .4byte gUnknown_08008750
.L080DD120:
	ldr r0, .L080DD158
	movs r5, #0x80
	lsls r5, r5, #1
	str r5, [sp]
	movs r1, #0x10
	str r1, [sp, #4]
	movs r4, #0x78
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DD15C
	str r5, [sp]
	movs r1, #0xc9
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
.L080DD14E:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DD158: .4byte gUnknown_080087A0
.L080DD15C: .4byte gUnknown_0800876C

	thumb_func_start sub_080DD160
sub_080DD160: @ 0x080DD160
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	ldr r2, .L080DD180
	ldrh r1, [r2]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DD184
	ldrh r0, [r4, #0x24]
	strh r0, [r4, #0x1e]
	movs r0, #0x65
	b .L080DD190
.L080DD180: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DD184:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DD198
	movs r0, #0x66
.L080DD190:
	bl sub_080C51D4
	strh r5, [r4, #0x1c]
	b .L080DD1DE
.L080DD198:
	ldr r0, .L080DD1B4
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L080DD1C2
	ldrh r0, [r4, #0x24]
	cmp r0, #0
	beq .L080DD1B8
	subs r0, #1
	strh r0, [r4, #0x24]
	b .L080DD1BA
.L080DD1B4: .4byte 0x03003964 @ IWRAM+0x3964
.L080DD1B8:
	strh r5, [r4, #0x24]
.L080DD1BA:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DD1DE
.L080DD1C2:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080DD1DE
	ldrh r0, [r4, #0x24]
	cmp r0, #1
	beq .L080DD1D6
	adds r0, #1
	strh r0, [r4, #0x24]
	b .L080DD1D8
.L080DD1D6:
	strh r2, [r4, #0x24]
.L080DD1D8:
	movs r0, #0x64
	bl sub_080C51D4
.L080DD1DE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080DD1E4
sub_080DD1E4: @ 0x080DD1E4
	push {r4, r5, lr}
	bl Task_GetParent
	adds r4, r0, #0
	bl Task_GetParent
	adds r5, r0, #0
	movs r0, #1
	bl sub_080C3818
	adds r0, r4, #0
	bl Task_End
	movs r0, #1
	str r0, [r5, #0xc]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080DD208
sub_080DD208: @ 0x080DD208
	push {lr}
	movs r0, #0xf0
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080DD21C
sub_080DD21C: @ 0x080DD21C
.L080DD21C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, .L080DD238
	cmp r2, r0
	bhi .L080DD240
	ldr r0, .L080DD23C
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	b .L080DD242
	.byte 0x00, 0x00
.L080DD238: .4byte 0x0000017B
.L080DD23C: .4byte gUnknown_08583E84
.L080DD240:
	movs r0, #0
.L080DD242:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080DD248
sub_080DD248: @ 0x080DD248
.L080DD248:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L080DD258
	cmp r1, r0
	bls .L080DD25C
	movs r0, #0
	b .L080DD272
.L080DD258: .4byte 0x0000017B
.L080DD25C:
	adds r0, r1, #0
	bl sub_080C2600
	adds r1, r0, #0
	cmp r1, #0xfe
	bls .L080DD270
	adds r0, r1, #0
	bl sub_080DD21C
	b .L080DD272
.L080DD270:
	movs r0, #1
.L080DD272:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080DD278
sub_080DD278: @ 0x080DD278
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x24
	movs r4, #0
	strb r4, [r0]
	movs r1, #1
	strb r1, [r0, #1]
	strb r1, [r0, #2]
	movs r1, #0
	movs r2, #0xff
	strh r2, [r0, #0x12]
	strb r1, [r0, #3]
	strb r1, [r0, #4]
	strb r1, [r0, #5]
	strb r1, [r0, #6]
	strb r1, [r0, #7]
	strb r1, [r0, #8]
	strb r1, [r0, #9]
	strb r1, [r0, #0xa]
	strb r1, [r0, #0xb]
	strb r1, [r0, #0xe]
	strb r1, [r0, #0xd]
	strb r1, [r0, #0xc]
	strh r4, [r0, #0x10]
	adds r0, #0x30
	strb r1, [r0]
	bl m4aMPlayAllStop
	ldr r0, .L080DD2C0
	strh r4, [r0]
	adds r0, r5, #0
	bl sub_080DDE2C
	pop {r4, r5}
	pop {r0}
	bx r0
.L080DD2C0: .4byte 0x030031B4 @ IWRAM+0x31B4

	thumb_func_start sub_080DD2C4
sub_080DD2C4: @ 0x080DD2C4
	push {lr}
	sub sp, #4
	ldr r1, .L080DD2E0
	ldr r2, .L080DD2E4
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DD2E0: .4byte gUnknown_08580E40
.L080DD2E4: .4byte 0x03002D70 @ IWRAM+0x2D70

	thumb_func_start sub_080DD2E8
sub_080DD2E8: @ 0x080DD2E8
	ldr r1, .L080DD2FC
	ldr r0, .L080DD300
	str r0, [r1]
	ldr r0, .L080DD304
	str r0, [r1, #4]
	ldr r0, .L080DD308
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080DD2FC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DD300: .4byte 0x02001000 @ EWRAM+0x1000
.L080DD304: .4byte 0x06012800 @ VRAM+0x12800
.L080DD308: .4byte 0x84001200

	thumb_func_start sub_080DD30C
sub_080DD30C: @ 0x080DD30C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x24
	movs r1, #0
	strh r1, [r5, #0x1c]
	strh r1, [r5, #0x1e]
	ldrb r0, [r6]
	cmp r0, #3
	bne .L080DD332
	ldrb r0, [r6, #0xb]
	cmp r0, #0
	beq .L080DD32C
	b .L080DD7BE
.L080DD32C:
	movs r0, #1
	strh r0, [r5, #0x1c]
	b .L080DD7BE
.L080DD332:
	cmp r0, #2
	bne .L080DD34A
	ldrh r0, [r6, #0x10]
	adds r0, #1
	strh r0, [r6, #0x10]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble .L080DD34A
	strh r1, [r6, #0x10]
	movs r0, #0
	strb r0, [r6]
.L080DD34A:
	ldr r3, .L080DD374
	ldrh r0, [r3]
	movs r4, #1
	ands r4, r0
	cmp r4, #0
	bne .L080DD358
	b .L080DD4E2
.L080DD358:
	movs r0, #0x65
	bl sub_080C51D4
	movs r0, #1
	ldrsb r0, [r6, r0]
	cmp r0, #6
	bls .L080DD368
	b .L080DD6E0
.L080DD368:
	lsls r0, r0, #2
	ldr r1, .L080DD378
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080DD374: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DD378: .4byte gUnknown_080DD37C
	.global gUnknown_080DD37C
gUnknown_080DD37C:
.L080DD37C: @ jump table
	.4byte .L080DD398
	.4byte .L080DD3EC
	.4byte .L080DD418
	.4byte .L080DD450
	.4byte .L080DD4AC
	.4byte .L080DD4C4
	.4byte .L080DD4D8
.L080DD398:
	movs r0, #0xf
	strb r0, [r6, #5]
	ldrb r0, [r6, #0x14]
	subs r0, #1
	strb r0, [r6, #0x14]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge .L080DD3AC
	movs r0, #0x1a
	strb r0, [r6, #0x14]
.L080DD3AC:
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	adds r0, r6, #0
	adds r0, #0x15
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #2]
	ldr r1, .L080DD3E4
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r5, #0
	strh r0, [r6, #0x12]
	ldrb r0, [r6]
	adds r4, r0, #0
	adds r3, r0, #0
	cmp r4, #1
	beq .L080DD3D6
	b .L080DD710
.L080DD3D6:
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r1, .L080DD3E8
	movs r0, #0
	strh r0, [r1]
	b .L080DD49A
.L080DD3E4: .4byte gUnknown_085861C8
.L080DD3E8: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD3EC:
	movs r4, #0
	movs r0, #0xf
	strb r0, [r6, #6]
	strb r4, [r6, #7]
	ldrb r0, [r6]
	adds r3, r0, #0
	cmp r3, #1
	beq .L080DD3FE
	b .L080DD710
.L080DD3FE:
	strb r4, [r6]
	ldrh r0, [r6, #0x12]
	bl m4aSongNumStop
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	ldr r0, .L080DD414
	strh r4, [r0]
	b .L080DD6E0
	.byte 0x00, 0x00
.L080DD414: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD418:
	movs r5, #0
	movs r0, #0xf
	strb r0, [r6, #7]
	strb r5, [r6, #6]
	ldr r1, .L080DD448
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r4, #0
	strh r0, [r6, #0x12]
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD44C
	strh r5, [r0]
	movs r0, #1
	strb r0, [r6]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	b .L080DD6E0
	.byte 0x00, 0x00
.L080DD448: .4byte gUnknown_085861C8
.L080DD44C: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD450:
	movs r7, #0
	movs r0, #0xf
	strb r0, [r6, #8]
	ldrb r0, [r6, #0x14]
	adds r0, #1
	strb r0, [r6, #0x14]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1a
	ble .L080DD466
	strb r7, [r6, #0x14]
.L080DD466:
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	adds r0, r6, #0
	adds r0, #0x15
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #2]
	ldr r1, .L080DD4A4
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r5, #0
	strh r0, [r6, #0x12]
	ldrb r0, [r6]
	adds r4, r0, #0
	adds r3, r0, #0
	cmp r4, #1
	beq .L080DD490
	b .L080DD710
.L080DD490:
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD4A8
	strh r7, [r0]
.L080DD49A:
	strb r4, [r6]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xd]
	strb r5, [r6, #0xc]
	b .L080DD6E0
.L080DD4A4: .4byte gUnknown_085861C8
.L080DD4A8: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD4AC:
	movs r0, #0xf
	strb r0, [r6, #9]
	ldrb r1, [r6, #3]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r6, #3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080DD4C2
	b .L080DD6E0
.L080DD4C2:
	b .L080DD4D0
.L080DD4C4:
	movs r0, #0xf
	strb r0, [r6, #0xa]
	ldrb r1, [r6, #4]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r6, #4]
.L080DD4D0:
	adds r0, r5, #0
	bl sub_080DDE2C
	b .L080DD6E0
.L080DD4D8:
	movs r0, #0xf
	strb r0, [r6, #0xb]
	movs r0, #3
	strb r0, [r6]
	b .L080DD6E0
.L080DD4E2:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq .L080DD51C
	movs r0, #0xf
	strb r0, [r6, #6]
	strb r4, [r6, #7]
	ldrb r0, [r6]
	cmp r0, #1
	bne .L080DD50E
	strb r4, [r6]
	ldrh r0, [r6, #0x12]
	bl m4aSongNumStop
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	ldr r0, .L080DD518
	strh r4, [r0]
.L080DD50E:
	movs r0, #0x66
	bl sub_080C51D4
	b .L080DD6E0
	.byte 0x00, 0x00
.L080DD518: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD51C:
	ldrh r1, [r3]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L080DD560
	movs r0, #0xf
	strb r0, [r6, #7]
	strb r5, [r6, #6]
	ldr r1, .L080DD558
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r4, #0
	strh r0, [r6, #0x12]
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD55C
	strh r5, [r0]
	movs r0, #1
	strb r0, [r6]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	b .L080DD672
	.byte 0x00, 0x00
.L080DD558: .4byte gUnknown_085861C8
.L080DD55C: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD560:
	ldrh r1, [r3]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq .L080DD584
	adds r1, r6, #0
	adds r1, #0x30
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls .L080DD610
	strb r2, [r1]
	b .L080DD610
.L080DD584:
	ldr r0, .L080DD5A4
	ldrh r2, [r0]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq .L080DD5B0
	ldrb r0, [r6, #1]
	adds r0, #1
	strb r0, [r6, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne .L080DD5A8
	strb r1, [r6, #1]
	b .L080DD610
	.byte 0x00, 0x00
.L080DD5A4: .4byte 0x03003964 @ IWRAM+0x3964
.L080DD5A8:
	cmp r0, #7
	bne .L080DD610
	movs r0, #4
	b .L080DD60E
.L080DD5B0:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq .L080DD5D2
	ldrb r0, [r6, #1]
	subs r0, #1
	strb r0, [r6, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge .L080DD5CA
	movs r0, #3
	b .L080DD60E
.L080DD5CA:
	cmp r0, #3
	bne .L080DD610
	movs r0, #6
	b .L080DD60E
.L080DD5D2:
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080DD5EC
	ldrb r1, [r6, #1]
	movs r0, #1
	ldrsb r0, [r6, r0]
	cmp r0, #3
	bgt .L080DD5E8
	b .L080DD6E0
.L080DD5E8:
	subs r0, r1, #4
	b .L080DD60E
.L080DD5EC:
	ldrh r1, [r3]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	beq .L080DD618
	ldrb r0, [r6, #1]
	movs r1, #1
	ldrsb r1, [r6, r1]
	cmp r1, #3
	bne .L080DD608
	movs r0, #6
	b .L080DD60E
.L080DD608:
	cmp r1, #3
	bgt .L080DD6E0
	adds r0, #4
.L080DD60E:
	strb r0, [r6, #1]
.L080DD610:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DD6E0
.L080DD618:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0
	beq .L080DD684
	movs r0, #0xf
	strb r0, [r6, #8]
	ldrb r0, [r6, #0x14]
	adds r0, #1
	strb r0, [r6, #0x14]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1a
	ble .L080DD63C
	strb r7, [r6, #0x14]
.L080DD63C:
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	adds r0, r6, #0
	adds r0, #0x15
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #2]
	ldr r1, .L080DD67C
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r5, #0
	strh r0, [r6, #0x12]
	ldrb r4, [r6]
	cmp r4, #1
	bne .L080DD672
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD680
	strh r7, [r0]
	strb r4, [r6]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xd]
	strb r5, [r6, #0xc]
.L080DD672:
	movs r0, #0x65
	bl sub_080C51D4
	b .L080DD6E0
	.byte 0x00, 0x00
.L080DD67C: .4byte gUnknown_085861C8
.L080DD680: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD684:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080DD6E0
	movs r0, #0xf
	strb r0, [r6, #5]
	ldrb r0, [r6, #0x14]
	subs r0, #1
	strb r0, [r6, #0x14]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge .L080DD6A2
	movs r0, #0x1a
	strb r0, [r6, #0x14]
.L080DD6A2:
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	adds r0, r6, #0
	adds r0, #0x15
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #2]
	ldr r1, .L080DD73C
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r5, #0
	strh r0, [r6, #0x12]
	ldrb r4, [r6]
	cmp r4, #1
	bne .L080DD6DA
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD740
	mov r1, r8
	strh r1, [r0]
	strb r4, [r6]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xd]
	strb r5, [r6, #0xc]
.L080DD6DA:
	movs r0, #0x65
	bl sub_080C51D4
.L080DD6E0:
	ldrb r0, [r6]
	adds r3, r0, #0
	cmp r3, #1
	bne .L080DD710
	ldrb r0, [r6, #0xe]
	adds r0, #1
	movs r1, #0
	strb r0, [r6, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls .L080DD710
	strb r1, [r6, #0xe]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls .L080DD710
	strb r1, [r6, #0xd]
	ldrb r0, [r6, #0xc]
	adds r0, #1
	strb r0, [r6, #0xc]
.L080DD710:
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	ldr r1, .L080DD73C
	adds r2, r0, r1
	ldrb r0, [r6, #0xc]
	adds r4, r1, #0
	ldrb r1, [r2, #2]
	cmp r0, r1
	bne .L080DD744
	ldrb r1, [r6, #0xd]
	ldrb r0, [r2, #3]
	subs r0, #2
	cmp r1, r0
	bne .L080DD744
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne .L080DD744
	movs r0, #8
	bl sub_080C51BC
	b .L080DD7BE
.L080DD73C: .4byte gUnknown_085861C8
.L080DD740: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD744:
	ldrh r0, [r6, #0xc]
	ldrh r2, [r2, #2]
	cmp r0, r2
	bne .L080DD7BE
	ldrb r0, [r6, #0xe]
	cmp r0, #0xa
	bls .L080DD7BE
	ldrb r5, [r6, #3]
	cmp r5, #1
	bne .L080DD7A0
	ldrb r0, [r6, #0x14]
	adds r0, #1
	movs r7, #0
	strb r0, [r6, #0x14]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1a
	ble .L080DD76A
	strb r7, [r6, #0x14]
.L080DD76A:
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	adds r0, r6, #0
	adds r0, #0x15
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #2]
	movs r0, #2
	ldrsb r0, [r6, r0]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r4, #0
	strh r0, [r6, #0x12]
	ldrh r0, [r6, #0x12]
	bl sub_080C5170
	ldr r0, .L080DD79C
	strh r7, [r0]
	strb r5, [r6]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	b .L080DD7BE
	.byte 0x00, 0x00
.L080DD79C: .4byte 0x030031B4 @ IWRAM+0x31B4
.L080DD7A0:
	movs r4, #0
	movs r0, #0xf
	strb r0, [r6, #6]
	strb r4, [r6, #7]
	cmp r3, #1
	bne .L080DD7BE
	strb r4, [r6]
	ldrh r0, [r6, #0x12]
	bl m4aSongNumStop
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xc]
	ldr r0, .L080DD7C8
	strh r4, [r0]
.L080DD7BE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080DD7C8: .4byte 0x030031B4 @ IWRAM+0x31B4

	thumb_func_start sub_080DD7CC
sub_080DD7CC: @ 0x080DD7CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0x24
	adds r0, r0, r5
	mov sb, r0
	movs r4, #2
	ldrsb r4, [r0, r4]
	adds r0, r4, #0
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r7, #2
	ldr r1, .L080DD974
	adds r0, r0, r1
	ldr r0, [r0]
	movs r3, #0xa0
	lsls r3, r3, #1
	mov sl, r3
	str r3, [sp]
	movs r1, #0x31
	str r1, [sp, #4]
	movs r4, #0x2b
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r0, r6, #2
	ldr r1, .L080DD974
	adds r0, r0, r1
	ldr r0, [r0]
	mov r3, sl
	str r3, [sp]
	movs r1, #0x39
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DD978
	mov r1, sl
	str r1, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	mov r3, sb
	ldrb r2, [r3, #4]
	lsls r1, r2, #3
	adds r1, r1, r2
	adds r1, #0x20
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	movs r0, #0xf0
	lsls r0, r0, #2
	bl Font_ResetGlyphSpriteCache
	ldr r4, .L080DD97C
	mov r1, sb
	movs r0, #2
	ldrsb r0, [r1, r0]
	lsls r0, r0, #3
	adds r1, r4, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x3a
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0xe
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0x15
	bl Text_DrawSpriteStringTinted
	mov r3, sb
	ldrb r0, [r3, #3]
	cmp r0, #1
	bne .L080DD8C2
	ldr r2, .L080DD980
	ldr r0, .L080DD984
	mov r1, sl
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080DD988
	mov r3, sl
	str r3, [sp]
	movs r1, #0x66
	str r1, [sp, #4]
	movs r1, #0x41
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DD8C2:
	adds r0, r5, #0
	adds r0, #0x54
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080DD98C
	mov r0, sb
	ldrb r4, [r0, #0xc]
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r7, #2
	ldr r1, .L080DD974
	adds r0, r0, r1
	ldr r0, [r0]
	mov r3, sl
	str r3, [sp]
	movs r1, #0x3b
	str r1, [sp, #4]
	movs r1, #0x43
	mov r8, r1
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r0, r6, #2
	ldr r3, .L080DD974
	adds r0, r0, r3
	ldr r0, [r0]
	mov r1, sl
	str r1, [sp]
	mov r3, r8
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	mov r0, sb
	ldrb r4, [r0, #0xd]
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r7, #2
	ldr r1, .L080DD974
	adds r0, r0, r1
	ldr r0, [r0]
	mov r3, sl
	str r3, [sp]
	movs r1, #0x53
	str r1, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r0, r6, #2
	ldr r3, .L080DD974
	adds r0, r0, r3
	ldr r0, [r0]
	mov r1, sl
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	b .L080DDBF4
.L080DD974: .4byte gUnknown_085861A0
.L080DD978: .4byte gUnknown_080087B8
.L080DD97C: .4byte gUnknown_085861C8
.L080DD980: .4byte gUnknown_0858617C
.L080DD984: .4byte gUnknown_08008958
.L080DD988: .4byte gUnknown_08008C44
.L080DD98C:
	cmp r0, #1
	bne .L080DDA7C
	mov r1, sb
	movs r0, #2
	ldrsb r0, [r1, r0]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldrb r2, [r0, #2]
	ldrb r1, [r1, #0xc]
	subs r2, r2, r1
	lsls r2, r2, #0x18
	ldrb r0, [r0, #3]
	mov r3, sb
	ldrb r1, [r3, #0xd]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsrs r4, r2, #0x18
	asrs r2, r2, #0x18
	cmp r2, #0
	ble .L080DD9CC
	lsls r0, r5, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	bge .L080DD9CC
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r1, #0
	adds r0, #0x3c
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L080DD9CC:
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, .L080DDA78
	mov r8, r0
	lsls r0, r7, #2
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x3b
	str r1, [sp, #4]
	movs r3, #0x43
	mov sl, r3
	str r3, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r0, r6, #2
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	mov r3, sl
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r4, r5, #0x18
	asrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r7, #2
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x53
	str r1, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	lsls r0, r6, #2
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	b .L080DDBF4
.L080DDA78: .4byte gUnknown_085861A0
.L080DDA7C:
	cmp r0, #2
	beq .L080DDA82
	b .L080DDC24
.L080DDA82:
	mov r1, sb
	ldrb r0, [r1, #0xd]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x11
	adds r0, r0, r3
	lsrs r4, r0, #0x18
	cmp r4, #9
	bls .L080DDA9E
	movs r4, #0
.L080DDA9E:
	mov r0, sb
	ldrb r1, [r0, #0xe]
	cmp r1, #0xb
	bhi .L080DDAAC
	movs r1, #0
	mov r8, r1
	b .L080DDAF8
.L080DDAAC:
	adds r0, r1, #0
	subs r0, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bhi .L080DDABE
	movs r3, #1
	mov r8, r3
	b .L080DDB20
.L080DDABE:
	adds r0, r1, #0
	subs r0, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bhi .L080DDAD0
	movs r0, #2
	mov r8, r0
	b .L080DDB20
.L080DDAD0:
	adds r0, r1, #0
	subs r0, #0x24
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bhi .L080DDAE2
	movs r1, #3
	mov r8, r1
	b .L080DDB20
.L080DDAE2:
	adds r0, r1, #0
	subs r0, #0x30
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bhi .L080DDAF2
	movs r3, #4
	mov r8, r3
.L080DDAF2:
	mov r0, r8
	cmp r0, #0
	bne .L080DDB20
.L080DDAF8:
	ldr r1, .L080DDB1C
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x3b
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDB40
	.byte 0x00, 0x00
.L080DDB1C: .4byte gUnknown_085861A0
.L080DDB20:
	ldr r1, .L080DDB68
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x3b
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDB40:
	mov r1, r8
	cmp r1, #1
	bhi .L080DDB6C
	ldr r1, .L080DDB68
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x43
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDB8A
	.byte 0x00, 0x00
.L080DDB68: .4byte gUnknown_085861A0
.L080DDB6C:
	ldr r1, .L080DDBB4
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x43
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDB8A:
	mov r3, r8
	cmp r3, #2
	bhi .L080DDBB8
	ldr r1, .L080DDBB4
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x53
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDBD8
	.byte 0x00, 0x00
.L080DDBB4: .4byte gUnknown_085861A0
.L080DDBB8:
	ldr r1, .L080DDC00
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x53
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDBD8:
	mov r0, r8
	cmp r0, #3
	bhi .L080DDC04
	ldr r1, .L080DDC00
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
.L080DDBF4:
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDC24
.L080DDC00: .4byte gUnknown_085861A0
.L080DDC04:
	ldr r1, .L080DDC98
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x5b
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDC24:
	movs r3, #0
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne .L080DDC34
	movs r3, #1
.L080DDC34:
	ldr r0, .L080DDC9C
	cmp r1, r0
	bne .L080DDC44
	mov r1, sb
	ldrb r0, [r1, #7]
	cmp r0, #0x3b
	bhi .L080DDC44
	movs r3, #1
.L080DDC44:
	mov r1, sb
	ldr r0, [r1]
	ldr r1, .L080DDCA0
	ands r0, r1
	ldr r1, .L080DDCA4
	cmp r0, r1
	bne .L080DDC54
	movs r3, #1
.L080DDC54:
	mov r1, sb
	movs r0, #1
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bne .L080DDC66
	ldrb r0, [r1, #4]
	cmp r0, #1
	bne .L080DDC66
	movs r3, #1
.L080DDC66:
	mov r1, sb
	movs r0, #1
	ldrsb r0, [r1, r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, .L080DDCA8
	adds r2, r1, r0
	cmp r3, #1
	bne .L080DDCAC
	ldr r0, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDCC6
	.byte 0x00, 0x00
.L080DDC98: .4byte gUnknown_085861A0
.L080DDC9C: .4byte 0x00000201
.L080DDCA0: .4byte 0xFF00FF00
.L080DDCA4: .4byte 0x01000400
.L080DDCA8: .4byte gUnknown_0858614C
.L080DDCAC:
	ldr r0, [r2, #4]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDCC6:
	mov r3, sb
	ldrb r0, [r3, #5]
	cmp r0, #0
	beq .L080DDCEE
	subs r0, #1
	strb r0, [r3, #5]
	ldr r2, .L080DDD48
	ldr r0, .L080DDD4C
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDCEE:
	mov r1, sb
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq .L080DDD16
	subs r0, #1
	strb r0, [r1, #8]
	ldr r2, .L080DDD50
	ldr r0, .L080DDD54
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDD16:
	mov r3, sb
	ldrb r0, [r3, #7]
	cmp r0, #0
	beq .L080DDD60
	subs r0, #1
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x2c
	bhi .L080DDD6C
	ldr r2, .L080DDD58
	ldr r0, .L080DDD5C
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
	b .L080DDD6C
.L080DDD48: .4byte gUnknown_0858614C
.L080DDD4C: .4byte gUnknown_08008890
.L080DDD50: .4byte gUnknown_08586170
.L080DDD54: .4byte gUnknown_08008928
.L080DDD58: .4byte gUnknown_08586164
.L080DDD5C: .4byte gUnknown_080088F0
.L080DDD60:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #1
	bne .L080DDD6C
	movs r0, #0x5a
	strb r0, [r1, #7]
.L080DDD6C:
	mov r3, sb
	ldrb r0, [r3, #6]
	cmp r0, #0
	beq .L080DDD90
	ldr r2, .L080DDE18
	ldr r0, .L080DDE1C
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDD90:
	mov r1, sb
	ldrb r0, [r1, #0xb]
	cmp r0, #0
	beq .L080DDDB8
	subs r0, #1
	strb r0, [r1, #0xb]
	ldr r2, .L080DDE20
	ldr r0, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDDB8:
	mov r3, sb
	ldrb r0, [r3, #9]
	cmp r0, #0
	beq .L080DDDE0
	subs r0, #1
	strb r0, [r3, #9]
	ldr r2, .L080DDE24
	ldr r0, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDDE0:
	mov r1, sb
	ldrb r0, [r1, #0xa]
	cmp r0, #0
	beq .L080DDE08
	subs r0, #1
	strb r0, [r1, #0xa]
	ldr r2, .L080DDE28
	ldr r0, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #1
	str r1, [sp]
	ldrh r1, [r2]
	str r1, [sp, #4]
	ldrh r1, [r2, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xe
	movs r3, #0
	bl Sprite_Draw
.L080DDE08:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080DDE18: .4byte gUnknown_08586158
.L080DDE1C: .4byte gUnknown_080088C0
.L080DDE20: .4byte gUnknown_08586194
.L080DDE24: .4byte gUnknown_0858617C
.L080DDE28: .4byte gUnknown_08586188

	thumb_func_start sub_080DDE2C
sub_080DDE2C: @ 0x080DDE2C
.L080DDE2C:
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	adds r5, r1, #0
	adds r5, #0x24
	ldrb r0, [r5, #4]
	cmp r0, #1
	bne .L080DDEA2
	movs r4, #0
	adds r7, r1, #0
	adds r7, #0x39
	adds r2, r7, #0
.L080DDE42:
	adds r1, r2, r4
	adds r0, r4, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x1a
	bls .L080DDE42
	movs r4, #0
	adds r6, r7, #0
.L080DDE54:
	bl sub_080C2244
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080DDE7A
	bl sub_080C2244
	movs r1, #0x1f
	ands r0, r1
	adds r0, #1
	cmp r0, #0x1a
	bhi .L080DDE7A
	adds r2, r6, r4
	ldrb r3, [r2]
	adds r1, r6, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
.L080DDE7A:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x1a
	bls .L080DDE54
	movs r4, #0
	movs r2, #2
	ldrsb r2, [r5, r2]
	adds r1, r7, #0
.L080DDE8C:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r2, r0
	bne .L080DDE96
	strb r4, [r5, #0x14]
.L080DDE96:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x1a
	bls .L080DDE8C
	b .L080DDEC0
.L080DDEA2:
	movs r4, #0
	adds r2, r1, #0
	adds r2, #0x39
.L080DDEA8:
	adds r0, r2, r4
	adds r1, r4, #1
	strb r1, [r0]
	movs r0, #2
	ldrsb r0, [r5, r0]
	cmp r0, r1
	bne .L080DDEB8
	strb r4, [r5, #0x14]
.L080DDEB8:
	lsls r0, r1, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x1a
	bls .L080DDEA8
.L080DDEC0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080DDEC8
sub_080DDEC8: @ 0x080DDEC8
	adds r0, #0x24
	movs r1, #0xf
	strb r1, [r0, #6]
	bx lr

	thumb_func_start sub_080DDED0
sub_080DDED0: @ 0x080DDED0
	push {lr}
	movs r0, #0xd
	bl sub_080C5170
	pop {r0}
	bx r0

	thumb_func_start sub_080DDEDC
sub_080DDEDC: @ 0x080DDEDC
	push {lr}
	sub sp, #4
	ldr r0, .L080DDF68
	movs r2, #1
	str r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r3, .L080DDF6C
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #8
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	ldr r3, .L080DDF70
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, .L080DDF74
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, .L080DDF78
	movs r1, #0xf0
	strh r1, [r0]
	ldr r0, .L080DDF7C
	strh r1, [r0]
	ldr r0, .L080DDF80
	movs r1, #0xa0
	strh r1, [r0]
	ldr r0, .L080DDF84
	strh r1, [r0]
	ldr r1, .L080DDF88
	subs r3, #0x86
	adds r0, r3, #0
	strh r0, [r1]
	ldr r1, .L080DDF8C
	ldr r3, .L080DDF90
	adds r0, r3, #0
	strh r0, [r1]
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080DDF94
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080DDF98
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, .L080DDF9C
	adds r3, #0xe4
	adds r0, r3, #0
	strh r0, [r1]
	ldr r1, .L080DDFA0
	movs r0, #0x18
	strh r0, [r1]
	ldr r0, .L080DDFA4
	strh r2, [r0]
	bl Task_ClearAll
	bl sub_080DDFAC
	ldr r0, .L080DDFA8
	bl SetMainCallback
	add sp, #4
	pop {r0}
	bx r0
.L080DDF68: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080DDF6C: .4byte 0x00006301
.L080DDF70: .4byte 0x00008205
.L080DDF74: .4byte 0x0000048A
.L080DDF78: .4byte 0x03000030 @ IWRAM+0x30
.L080DDF7C: .4byte 0x03000032 @ IWRAM+0x32
.L080DDF80: .4byte 0x03000034 @ IWRAM+0x34
.L080DDF84: .4byte 0x03000036 @ IWRAM+0x36
.L080DDF88: .4byte 0x03000038 @ IWRAM+0x38
.L080DDF8C: .4byte 0x0300003A @ IWRAM+0x3A
.L080DDF90: .4byte 0x00001F1F
.L080DDF94: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DDF98: .4byte 0x81002000
.L080DDF9C: .4byte 0x04000200 @ REG_IE
.L080DDFA0: .4byte 0x04000004 @ REG_DISPSTAT
.L080DDFA4: .4byte 0x04000208 @ REG_IME
.L080DDFA8: .4byte sub_080DE0DC

	thumb_func_start sub_080DDFAC
sub_080DDFAC: @ 0x080DDFAC
.L080DDFAC:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r0, .L080DE090
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080DE094
	strh r1, [r0]
	ldr r0, .L080DE098
	strh r1, [r0]
	ldr r0, .L080DE09C
	strh r1, [r0]
	ldr r0, .L080DE0A0
	strh r1, [r0]
	ldr r0, .L080DE0A4
	strh r1, [r0]
	ldr r0, .L080DE0A8
	strh r1, [r0]
	ldr r0, .L080DE0AC
	strh r1, [r0]
	ldr r0, .L080DE0B0
	movs r2, #0x80
	lsls r2, r2, #3
	movs r1, #0
	bl memset
	ldr r0, .L080DE0B4
	movs r1, #0
	movs r2, #0x40
	bl sub_08153378
	ldr r5, .L080DE0B8
	movs r2, #0xa8
	lsls r2, r2, #7
	adds r0, r5, #0
	movs r1, #0
	bl memset
	ldr r1, .L080DE0BC
	adds r0, r5, #0
	movs r2, #4
	bl memcpy
	ldr r4, .L080DE0C0
	str r5, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, .L080DE0C4
	mov r8, r0
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, .L080DE0C8
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, #0
	bl memcpy
	str r5, [r4]
	ldr r0, .L080DE0CC
	str r0, [r4, #4]
	mov r0, r8
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, .L080DE0D0
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r5, #0
	adds r2, r6, #0
	bl memcpy
	str r5, [r4]
	ldr r0, .L080DE0D4
	str r0, [r4, #4]
	mov r0, r8
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, .L080DE0D8
	movs r2, #0
	movs r1, #4
	strh r1, [r0, #6]
	strh r2, [r0, #0x34]
	strh r2, [r0, #0x22]
	str r2, [r0, #0x10]
	str r2, [r0, #0x14]
	strh r6, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r6, [r0, #0xe]
	movs r1, #0x38
	strh r1, [r0, #0x18]
	movs r1, #8
	strh r1, [r0, #0x1a]
	strh r1, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r2, [r0, #0x1c]
	movs r1, #0x78
	strh r1, [r0, #0x24]
	movs r1, #0x48
	strh r1, [r0, #0x26]
	strh r2, [r0, #0x28]
	movs r1, #0x80
	strh r1, [r0, #0x2a]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [r0, #0x2c]
	str r1, [r0, #0x30]
	strh r2, [r0, #0x36]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DE090: .4byte 0x03000000 @ IWRAM
.L080DE094: .4byte 0x03000004 @ IWRAM+0x4
.L080DE098: .4byte 0x03000008 @ IWRAM+0x8
.L080DE09C: .4byte 0x0300000C @ IWRAM+0xC
.L080DE0A0: .4byte 0x03000002 @ IWRAM+0x2
.L080DE0A4: .4byte 0x03000006 @ IWRAM+0x6
.L080DE0A8: .4byte 0x0300000A @ IWRAM+0xA
.L080DE0AC: .4byte 0x0300000E @ IWRAM+0xE
.L080DE0B0: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080DE0B4: .4byte gUnknown_08589C3C
.L080DE0B8: .4byte 0x02030C74 @ EWRAM+0x30C74
.L080DE0BC: .4byte gUnknown_08589C7C
.L080DE0C0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DE0C4: .4byte 0x84000400
.L080DE0C8: .4byte gUnknown_08587830
.L080DE0CC: .4byte 0x06001000 @ VRAM+0x1000
.L080DE0D0: .4byte gUnknown_08589B3C
.L080DE0D4: .4byte 0x06002000 @ VRAM+0x2000
.L080DE0D8: .4byte 0x020399E0 @ EWRAM+0x399E0

	thumb_func_start sub_080DE0DC
sub_080DE0DC: @ 0x080DE0DC
	push {lr}
	bl sub_080DE0F8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080DE0F4
	bl sub_080DE208
	bl Task_RunAll
	bl sub_080C22E4
.L080DE0F4:
	pop {r0}
	bx r0

	thumb_func_start sub_080DE0F8
sub_080DE0F8: @ 0x080DE0F8
.L080DE0F8:
	push {r4, lr}
	ldr r0, .L080DE110
	movs r1, #0x36
	ldrsh r0, [r0, r1]
	cmp r0, #5
	bhi .L080DE1E4
	lsls r0, r0, #2
	ldr r1, .L080DE114
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080DE110: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DE114: .4byte gUnknown_080DE118
	.global gUnknown_080DE118
gUnknown_080DE118:
.L080DE118: @ jump table
	.4byte .L080DE130
	.4byte .L080DE140
	.4byte .L080DE178
	.4byte .L080DE188
	.4byte .L080DE198
	.4byte .L080DE1B8
.L080DE130:
	ldr r0, .L080DE138
	ldr r1, .L080DE13C
	b .L080DE19C
	.byte 0x00, 0x00
.L080DE138: .4byte gUnknown_08587130
.L080DE13C: .4byte 0x02001000 @ EWRAM+0x1000
.L080DE140:
	ldr r0, .L080DE160
	ldr r4, .L080DE164
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080DE168
	ldr r0, .L080DE16C
	adds r4, r4, r0
	str r4, [r1]
	ldr r0, .L080DE170
	str r0, [r1, #4]
	ldr r0, .L080DE174
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b .L080DE1A0
	.byte 0x00, 0x00
.L080DE160: .4byte gUnknown_085874EC
.L080DE164: .4byte 0x02002000 @ EWRAM+0x2000
.L080DE168: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DE16C: .4byte 0xFFFFF000
.L080DE170: .4byte 0x06004000 @ VRAM+0x4000
.L080DE174: .4byte 0x84000800
.L080DE178:
	ldr r0, .L080DE180
	ldr r1, .L080DE184
	b .L080DE19C
	.byte 0x00, 0x00
.L080DE180: .4byte gUnknown_08588050
.L080DE184: .4byte 0x02001000 @ EWRAM+0x1000
.L080DE188:
	ldr r0, .L080DE190
	ldr r1, .L080DE194
	b .L080DE19C
	.byte 0x00, 0x00
.L080DE190: .4byte gUnknown_085887D4
.L080DE194: .4byte 0x02002000 @ EWRAM+0x2000
.L080DE198:
	ldr r0, .L080DE1AC
	ldr r1, .L080DE1B0
.L080DE19C:
	bl LZ77UnCompWram
.L080DE1A0:
	ldr r1, .L080DE1B4
	ldrh r0, [r1, #0x36]
	adds r0, #1
	strh r0, [r1, #0x36]
	movs r0, #0
	b .L080DE1E6
.L080DE1AC: .4byte gUnknown_08588FA4
.L080DE1B0: .4byte 0x02003000 @ EWRAM+0x3000
.L080DE1B4: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DE1B8:
	ldr r0, .L080DE1EC
	ldr r4, .L080DE1F0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080DE1F4
	ldr r0, .L080DE1F8
	adds r4, r4, r0
	str r4, [r1]
	ldr r0, .L080DE1FC
	str r0, [r1, #4]
	ldr r0, .L080DE200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r4, .L080DE204
	ldrh r0, [r4, #0x36]
	adds r0, #1
	strh r0, [r4, #0x36]
	movs r0, #1
	bl PalFade_FadeInFromBlack
	str r0, [r4]
.L080DE1E4:
	movs r0, #1
.L080DE1E6:
	pop {r4}
	pop {r1}
	bx r1
.L080DE1EC: .4byte gUnknown_0858979C
.L080DE1F0: .4byte 0x02004000 @ EWRAM+0x4000
.L080DE1F4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DE1F8: .4byte 0xFFFFD000
.L080DE1FC: .4byte 0x06008000 @ VRAM+0x8000
.L080DE200: .4byte 0x84000E00
.L080DE204: .4byte 0x020399E0 @ EWRAM+0x399E0

	thumb_func_start sub_080DE208
sub_080DE208: @ 0x080DE208
.L080DE208:
	push {lr}
	bl sub_080DE21C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080DE218
	bl sub_080DE258
.L080DE218:
	pop {r0}
	bx r0

	thumb_func_start sub_080DE21C
sub_080DE21C: @ 0x080DE21C
.L080DE21C:
	push {lr}
	ldr r1, .L080DE22C
	ldr r0, [r1]
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080DE230
	movs r0, #0
	b .L080DE24C
.L080DE22C: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DE230:
	ldrh r0, [r1, #4]
	cmp r0, #0
	beq .L080DE23C
	cmp r0, #1
	beq .L080DE240
	b .L080DE246
.L080DE23C:
	movs r0, #1
	b .L080DE24C
.L080DE240:
	ldr r0, .L080DE250
	bl SetMainCallback
.L080DE246:
	ldr r1, .L080DE254
	movs r0, #0
	strh r0, [r1, #4]
.L080DE24C:
	pop {r1}
	bx r1
.L080DE250: .4byte sub_080D9608
.L080DE254: .4byte 0x020399E0 @ EWRAM+0x399E0

	thumb_func_start sub_080DE258
sub_080DE258: @ 0x080DE258
.L080DE258:
	push {r4, lr}
	ldr r0, .L080DE29C
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080DE2B0
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L080DE2A0
	ands r0, r1
	strh r0, [r2]
	ldr r2, .L080DE2A4
	ldr r1, [r2]
	movs r0, #1
	strh r0, [r1]
	strh r0, [r2, #4]
	ldr r0, .L080DE2A8
	movs r4, #0x80
	lsls r4, r4, #3
	movs r1, #0
	adds r2, r4, #0
	bl memset
	ldr r0, .L080DE2AC
	movs r1, #0
	adds r2, r4, #0
	bl memset
	bl Palette_MarkDirty
	b .L080DE2B8
	.byte 0x00, 0x00
.L080DE29C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DE2A0: .4byte 0x0000F0FF
.L080DE2A4: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DE2A8: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080DE2AC: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080DE2B0:
	bl sub_080DE2C0
	bl sub_080DE680
.L080DE2B8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

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

	thumb_func_start sub_080DE680
sub_080DE680: @ 0x080DE680
.L080DE680:
	push {r4, r5, r6, lr}
	ldr r0, .L080DE780
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r6, .L080DE784
	ldrh r0, [r6, #0x28]
	ldrh r2, [r6, #0x1e]
	adds r1, r0, r2
	strh r1, [r6, #0x1e]
	ldrh r3, [r6, #0x20]
	adds r0, r0, r3
	strh r0, [r6, #0x20]
	ldr r5, .L080DE788
	ldrh r0, [r6, #0x1c]
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r4, [r0, r1]
	movs r2, #0x1e
	ldrsh r0, [r6, r2]
	bl FixedInverse8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMul8
	strh r0, [r6, #8]
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r4, [r0, r3]
	movs r1, #0x1e
	ldrsh r0, [r6, r1]
	bl FixedInverse8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMul8
	strh r0, [r6, #0xa]
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	rsbs r4, r4, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	movs r2, #0x20
	ldrsh r0, [r6, r2]
	bl FixedInverse8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMul8
	strh r0, [r6, #0xc]
	ldrh r0, [r6, #0x1c]
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r4, [r0, r3]
	movs r1, #0x20
	ldrsh r0, [r6, r1]
	bl FixedInverse8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMul8
	strh r0, [r6, #0xe]
	movs r3, #0x24
	ldrsh r2, [r6, r3]
	movs r4, #0x18
	ldrsh r0, [r6, r4]
	subs r0, r2, r0
	lsls r0, r0, #8
	movs r3, #8
	ldrsh r1, [r6, r3]
	muls r1, r2, r1
	subs r0, r0, r1
	movs r4, #0xa
	ldrsh r2, [r6, r4]
	movs r3, #0x26
	ldrsh r1, [r6, r3]
	muls r1, r2, r1
	subs r0, r0, r1
	str r0, [r6, #0x10]
	movs r4, #0x26
	ldrsh r3, [r6, r4]
	movs r1, #0x1a
	ldrsh r0, [r6, r1]
	subs r0, r3, r0
	lsls r0, r0, #8
	movs r4, #0xc
	ldrsh r2, [r6, r4]
	movs r4, #0x24
	ldrsh r1, [r6, r4]
	muls r1, r2, r1
	subs r0, r0, r1
	movs r2, #0xe
	ldrsh r1, [r6, r2]
	muls r1, r3, r1
	subs r0, r0, r1
	str r0, [r6, #0x14]
	ldrh r0, [r6, #0x1e]
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bls .L080DE77A
	movs r0, #0
	strh r0, [r6, #0x28]
	strh r1, [r6, #0x1e]
	strh r1, [r6, #0x20]
.L080DE77A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080DE780: .4byte sub_080DEDD8
.L080DE784: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DE788: .4byte gSineTable

	thumb_func_start sub_080DE78C
sub_080DE78C: @ 0x080DE78C
	push {lr}
	sub sp, #4
	ldr r0, .L080DE818
	movs r2, #1
	str r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r3, .L080DE81C
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #8
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	ldr r3, .L080DE820
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, .L080DE824
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, .L080DE828
	movs r1, #0xf0
	strh r1, [r0]
	ldr r0, .L080DE82C
	strh r1, [r0]
	ldr r0, .L080DE830
	movs r1, #0xa0
	strh r1, [r0]
	ldr r0, .L080DE834
	strh r1, [r0]
	ldr r1, .L080DE838
	subs r3, #0x86
	adds r0, r3, #0
	strh r0, [r1]
	ldr r1, .L080DE83C
	ldr r3, .L080DE840
	adds r0, r3, #0
	strh r0, [r1]
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080DE844
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080DE848
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, .L080DE84C
	adds r3, #0xe4
	adds r0, r3, #0
	strh r0, [r1]
	ldr r1, .L080DE850
	movs r0, #0x18
	strh r0, [r1]
	ldr r0, .L080DE854
	strh r2, [r0]
	bl Task_ClearAll
	bl sub_080DE85C
	ldr r0, .L080DE858
	bl SetMainCallback
	add sp, #4
	pop {r0}
	bx r0
.L080DE818: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080DE81C: .4byte 0x00006701
.L080DE820: .4byte 0x00000205
.L080DE824: .4byte 0x0000048A
.L080DE828: .4byte 0x03000030 @ IWRAM+0x30
.L080DE82C: .4byte 0x03000032 @ IWRAM+0x32
.L080DE830: .4byte 0x03000034 @ IWRAM+0x34
.L080DE834: .4byte 0x03000036 @ IWRAM+0x36
.L080DE838: .4byte 0x03000038 @ IWRAM+0x38
.L080DE83C: .4byte 0x0300003A @ IWRAM+0x3A
.L080DE840: .4byte 0x00001F1F
.L080DE844: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DE848: .4byte 0x81002000
.L080DE84C: .4byte 0x04000200 @ REG_IE
.L080DE850: .4byte 0x04000004 @ REG_DISPSTAT
.L080DE854: .4byte 0x04000208 @ REG_IME
.L080DE858: .4byte sub_080DE98C

	thumb_func_start sub_080DE85C
sub_080DE85C: @ 0x080DE85C
.L080DE85C:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r0, .L080DE940
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080DE944
	strh r1, [r0]
	ldr r0, .L080DE948
	strh r1, [r0]
	ldr r0, .L080DE94C
	strh r1, [r0]
	ldr r0, .L080DE950
	strh r1, [r0]
	ldr r0, .L080DE954
	strh r1, [r0]
	ldr r0, .L080DE958
	strh r1, [r0]
	ldr r0, .L080DE95C
	strh r1, [r0]
	ldr r0, .L080DE960
	movs r2, #0x80
	lsls r2, r2, #3
	movs r1, #0
	bl memset
	ldr r0, .L080DE964
	movs r1, #0
	movs r2, #0x40
	bl sub_08153378
	ldr r5, .L080DE968
	movs r2, #0xa8
	lsls r2, r2, #7
	adds r0, r5, #0
	movs r1, #0
	bl memset
	ldr r1, .L080DE96C
	adds r0, r5, #0
	movs r2, #4
	bl memcpy
	ldr r4, .L080DE970
	str r5, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, .L080DE974
	mov r8, r0
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, .L080DE978
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r5, #0
	bl memcpy
	str r5, [r4]
	ldr r0, .L080DE97C
	str r0, [r4, #4]
	mov r0, r8
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, .L080DE980
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r5, #0
	adds r2, r6, #0
	bl memcpy
	str r5, [r4]
	ldr r0, .L080DE984
	str r0, [r4, #4]
	mov r0, r8
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, .L080DE988
	movs r2, #0
	movs r1, #4
	strh r1, [r0, #6]
	strh r2, [r0, #0x34]
	strh r2, [r0, #0x22]
	str r2, [r0, #0x10]
	str r2, [r0, #0x14]
	strh r6, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r6, [r0, #0xe]
	movs r1, #0x38
	strh r1, [r0, #0x18]
	movs r1, #8
	strh r1, [r0, #0x1a]
	strh r6, [r0, #0x1e]
	strh r6, [r0, #0x20]
	strh r2, [r0, #0x1c]
	movs r1, #0x78
	strh r1, [r0, #0x24]
	movs r1, #0x48
	strh r1, [r0, #0x26]
	strh r2, [r0, #0x28]
	movs r1, #0x80
	strh r1, [r0, #0x2a]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [r0, #0x2c]
	str r1, [r0, #0x30]
	strh r2, [r0, #0x36]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DE940: .4byte 0x03000000 @ IWRAM
.L080DE944: .4byte 0x03000004 @ IWRAM+0x4
.L080DE948: .4byte 0x03000008 @ IWRAM+0x8
.L080DE94C: .4byte 0x0300000C @ IWRAM+0xC
.L080DE950: .4byte 0x03000002 @ IWRAM+0x2
.L080DE954: .4byte 0x03000006 @ IWRAM+0x6
.L080DE958: .4byte 0x0300000A @ IWRAM+0xA
.L080DE95C: .4byte 0x0300000E @ IWRAM+0xE
.L080DE960: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080DE964: .4byte gUnknown_08589C3C
.L080DE968: .4byte 0x02030C74 @ EWRAM+0x30C74
.L080DE96C: .4byte gUnknown_0858712C
.L080DE970: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DE974: .4byte 0x84000400
.L080DE978: .4byte gUnknown_08586C2C
.L080DE97C: .4byte 0x06001000 @ VRAM+0x1000
.L080DE980: .4byte gUnknown_08589B3C
.L080DE984: .4byte 0x06002000 @ VRAM+0x2000
.L080DE988: .4byte 0x020399E0 @ EWRAM+0x399E0

	thumb_func_start sub_080DE98C
sub_080DE98C: @ 0x080DE98C
	push {lr}
	bl sub_080DE9A8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080DE9A4
	bl sub_080DEA9C
	bl Task_RunAll
	bl sub_080C22E4
.L080DE9A4:
	pop {r0}
	bx r0

	thumb_func_start sub_080DE9A8
sub_080DE9A8: @ 0x080DE9A8
.L080DE9A8:
	push {r4, lr}
	ldr r0, .L080DE9C0
	movs r1, #0x36
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bhi .L080DEA78
	lsls r0, r0, #2
	ldr r1, .L080DE9C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080DE9C0: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DE9C4: .4byte gUnknown_080DE9C8
	.global gUnknown_080DE9C8
gUnknown_080DE9C8:
.L080DE9C8: @ jump table
	.4byte .L080DE9DC
	.4byte .L080DEA0C
	.4byte .L080DEA1C
	.4byte .L080DEA2C
	.4byte .L080DEA4C
.L080DE9DC:
	ldr r0, .L080DE9F8
	ldr r4, .L080DE9FC
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080DEA00
	str r4, [r1]
	ldr r0, .L080DEA04
	str r0, [r1, #4]
	ldr r0, .L080DEA08
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b .L080DEA34
	.byte 0x00, 0x00
.L080DE9F8: .4byte gUnknown_0858689C
.L080DE9FC: .4byte 0x02001000 @ EWRAM+0x1000
.L080DEA00: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DEA04: .4byte 0x06004000 @ VRAM+0x4000
.L080DEA08: .4byte 0x84000400
.L080DEA0C:
	ldr r0, .L080DEA14
	ldr r1, .L080DEA18
	b .L080DEA30
	.byte 0x00, 0x00
.L080DEA14: .4byte gUnknown_08588050
.L080DEA18: .4byte 0x02001000 @ EWRAM+0x1000
.L080DEA1C:
	ldr r0, .L080DEA24
	ldr r1, .L080DEA28
	b .L080DEA30
	.byte 0x00, 0x00
.L080DEA24: .4byte gUnknown_085887D4
.L080DEA28: .4byte 0x02002000 @ EWRAM+0x2000
.L080DEA2C:
	ldr r0, .L080DEA40
	ldr r1, .L080DEA44
.L080DEA30:
	bl LZ77UnCompWram
.L080DEA34:
	ldr r1, .L080DEA48
	ldrh r0, [r1, #0x36]
	adds r0, #1
	strh r0, [r1, #0x36]
	movs r0, #0
	b .L080DEA7A
.L080DEA40: .4byte gUnknown_08588FA4
.L080DEA44: .4byte 0x02003000 @ EWRAM+0x3000
.L080DEA48: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DEA4C:
	ldr r0, .L080DEA80
	ldr r4, .L080DEA84
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080DEA88
	ldr r0, .L080DEA8C
	adds r4, r4, r0
	str r4, [r1]
	ldr r0, .L080DEA90
	str r0, [r1, #4]
	ldr r0, .L080DEA94
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r4, .L080DEA98
	ldrh r0, [r4, #0x36]
	adds r0, #1
	strh r0, [r4, #0x36]
	movs r0, #1
	bl PalFade_FadeInFromBlack
	str r0, [r4]
.L080DEA78:
	movs r0, #1
.L080DEA7A:
	pop {r4}
	pop {r1}
	bx r1
.L080DEA80: .4byte gUnknown_0858979C
.L080DEA84: .4byte 0x02004000 @ EWRAM+0x4000
.L080DEA88: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DEA8C: .4byte 0xFFFFD000
.L080DEA90: .4byte 0x06008000 @ VRAM+0x8000
.L080DEA94: .4byte 0x84000E00
.L080DEA98: .4byte 0x020399E0 @ EWRAM+0x399E0

	thumb_func_start sub_080DEA9C
sub_080DEA9C: @ 0x080DEA9C
.L080DEA9C:
	push {lr}
	bl sub_080DEAB0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080DEAAC
	bl sub_080DEAE4
.L080DEAAC:
	pop {r0}
	bx r0

	thumb_func_start sub_080DEAB0
sub_080DEAB0: @ 0x080DEAB0
.L080DEAB0:
	push {lr}
	ldr r1, .L080DEAC0
	ldr r0, [r1]
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080DEAC4
.L080DEABC:
	movs r0, #1
	b .L080DEADA
.L080DEAC0: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DEAC4:
	ldrh r0, [r1, #4]
	cmp r0, #0
	beq .L080DEABC
	cmp r0, #1
	bne .L080DEAD4
	movs r0, #3
	bl sub_080D5B8C
.L080DEAD4:
	ldr r1, .L080DEAE0
	movs r0, #0
	strh r0, [r1, #4]
.L080DEADA:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080DEAE0: .4byte 0x020399E0 @ EWRAM+0x399E0

	thumb_func_start sub_080DEAE4
sub_080DEAE4: @ 0x080DEAE4
.L080DEAE4:
	push {r4, lr}
	ldr r0, .L080DEB28
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080DEB3C
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L080DEB2C
	ands r0, r1
	strh r0, [r2]
	ldr r2, .L080DEB30
	ldr r1, [r2]
	movs r0, #1
	strh r0, [r1]
	strh r0, [r2, #4]
	ldr r0, .L080DEB34
	movs r4, #0x80
	lsls r4, r4, #3
	movs r1, #0
	adds r2, r4, #0
	bl memset
	ldr r0, .L080DEB38
	movs r1, #0
	adds r2, r4, #0
	bl memset
	bl Palette_MarkDirty
	b .L080DEB44
	.byte 0x00, 0x00
.L080DEB28: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DEB2C: .4byte 0x0000F0FF
.L080DEB30: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DEB34: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080DEB38: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080DEB3C:
	bl sub_080DEB4C
	bl sub_080DECEC
.L080DEB44:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080DEB4C
sub_080DEB4C: @ 0x080DEB4C
.L080DEB4C:
	push {r4, lr}
	ldr r0, .L080DEB70
	movs r2, #0x34
	ldrsh r1, [r0, r2]
	adds r4, r0, #0
	cmp r1, #0x41
	beq .L080DEBE0
	cmp r1, #0x41
	bgt .L080DEB7E
	cmp r1, #0x20
	beq .L080DEBBC
	cmp r1, #0x20
	bgt .L080DEB74
	cmp r1, #0
	beq .L080DEBA4
	cmp r1, #0x13
	beq .L080DEBB0
	b .L080DEC4C
.L080DEB70: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DEB74:
	cmp r1, #0x2f
	beq .L080DEBC8
	cmp r1, #0x32
	beq .L080DEBD4
	b .L080DEC4C
.L080DEB7E:
	cmp r1, #0x65
	beq .L080DEC04
	cmp r1, #0x65
	bgt .L080DEB90
	cmp r1, #0x4e
	beq .L080DEBEC
	cmp r1, #0x58
	beq .L080DEBF8
	b .L080DEC4C
.L080DEB90:
	cmp r1, #0x89
	beq .L080DEC20
	cmp r1, #0x89
	bgt .L080DEB9E
	cmp r1, #0x6e
	beq .L080DEC10
	b .L080DEC4C
.L080DEB9E:
	cmp r1, #0x8a
	beq .L080DEC3E
	b .L080DEC4C
.L080DEBA4:
	ldr r1, .L080DEBAC
	movs r0, #9
	strb r0, [r1]
	b .L080DEC72
.L080DEBAC: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBB0:
	ldr r1, .L080DEBB8
	movs r0, #0x10
	strb r0, [r1]
	b .L080DEC72
.L080DEBB8: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBBC:
	ldr r1, .L080DEBC4
	movs r0, #0x17
	strb r0, [r1]
	b .L080DEC72
.L080DEBC4: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBC8:
	ldr r1, .L080DEBD0
	movs r0, #0x1e
	strb r0, [r1]
	b .L080DEC72
.L080DEBD0: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBD4:
	ldr r1, .L080DEBDC
	movs r0, #0x2c
	strb r0, [r1]
	b .L080DEC72
.L080DEBDC: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBE0:
	ldr r1, .L080DEBE8
	movs r0, #0x33
	strb r0, [r1]
	b .L080DEC72
.L080DEBE8: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBEC:
	ldr r1, .L080DEBF4
	movs r0, #0x3a
	strb r0, [r1]
	b .L080DEC72
.L080DEBF4: .4byte 0x03000037 @ IWRAM+0x37
.L080DEBF8:
	ldr r1, .L080DEC00
	movs r0, #0x48
	strb r0, [r1]
	b .L080DEC72
.L080DEC00: .4byte 0x03000037 @ IWRAM+0x37
.L080DEC04:
	ldr r1, .L080DEC0C
	movs r0, #0x4f
	strb r0, [r1]
	b .L080DEC72
.L080DEC0C: .4byte 0x03000037 @ IWRAM+0x37
.L080DEC10:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L080DEC1C
	b .L080DEC6E
	.byte 0x00, 0x00
.L080DEC1C: .4byte 0x0000BFFF
.L080DEC20:
	ldrh r0, [r4, #0x22]
	cmp r0, #1
	bne .L080DEC2E
	movs r0, #0
	strh r0, [r4, #0x22]
	movs r0, #0x28
	strh r0, [r4, #6]
.L080DEC2E:
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne .L080DEC5A
	b .L080DEC68
.L080DEC3E:
	movs r0, #1
	bl PalFade_FadeToBlack
	str r0, [r4]
	movs r0, #1
	strh r0, [r4, #4]
	b .L080DECCA
.L080DEC4C:
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq .L080DEC68
.L080DEC5A:
	ldr r1, .L080DEC64
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	b .L080DEC72
.L080DEC64: .4byte 0x03000038 @ IWRAM+0x38
.L080DEC68:
	ldr r2, .L080DECD0
	ldrh r1, [r2]
	ldr r0, .L080DECD4
.L080DEC6E:
	ands r0, r1
	strh r0, [r2]
.L080DEC72:
	ldrh r0, [r4, #6]
	subs r0, #1
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080DECCA
	movs r0, #8
	strh r0, [r4, #6]
	movs r0, #1
	strh r0, [r4, #0x22]
	ldrh r0, [r4, #0x34]
	adds r0, #1
	strh r0, [r4, #0x34]
	ldr r2, .L080DECD8
	ldr r1, .L080DECDC
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r2, .L080DECE0
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	strb r0, [r2]
	ldr r2, .L080DECE4
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	rsbs r0, r0, #0
	strh r0, [r2]
	ldr r2, .L080DECE8
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	rsbs r0, r0, #0
	strh r0, [r2]
.L080DECCA:
	pop {r4}
	pop {r0}
	bx r0
.L080DECD0: .4byte 0x03000038 @ IWRAM+0x38
.L080DECD4: .4byte 0x0000FFFE
.L080DECD8: .4byte 0x03000031 @ IWRAM+0x31
.L080DECDC: .4byte gUnknown_08586670
.L080DECE0: .4byte 0x03000035 @ IWRAM+0x35
.L080DECE4: .4byte 0x03000000 @ IWRAM
.L080DECE8: .4byte 0x03000002 @ IWRAM+0x2

	thumb_func_start sub_080DECEC
sub_080DECEC: @ 0x080DECEC
.L080DECEC:
	push {r4, r5, r6, lr}
	ldr r0, .L080DEDCC
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r6, .L080DEDD0
	ldr r5, .L080DEDD4
	ldrh r0, [r5, #0x1c]
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r4, [r0, r1]
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	bl FixedInverse8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMul8
	strh r0, [r5, #8]
	ldrh r0, [r5, #0x1c]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r4, [r0, r3]
	movs r1, #0x1e
	ldrsh r0, [r5, r1]
	bl FixedInverse8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMul8
	strh r0, [r5, #0xa]
	ldrh r0, [r5, #0x1c]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r4, [r0]
	rsbs r4, r4, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	movs r2, #0x20
	ldrsh r0, [r5, r2]
	bl FixedInverse8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMul8
	strh r0, [r5, #0xc]
	ldrh r0, [r5, #0x1c]
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r4, [r0, r3]
	movs r1, #0x20
	ldrsh r0, [r5, r1]
	bl FixedInverse8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMul8
	strh r0, [r5, #0xe]
	movs r3, #0x24
	ldrsh r2, [r5, r3]
	movs r4, #0x18
	ldrsh r0, [r5, r4]
	subs r0, r2, r0
	lsls r0, r0, #8
	movs r3, #8
	ldrsh r1, [r5, r3]
	muls r1, r2, r1
	subs r0, r0, r1
	movs r4, #0xa
	ldrsh r2, [r5, r4]
	movs r3, #0x26
	ldrsh r1, [r5, r3]
	muls r1, r2, r1
	subs r0, r0, r1
	str r0, [r5, #0x10]
	movs r4, #0x26
	ldrsh r3, [r5, r4]
	movs r1, #0x1a
	ldrsh r0, [r5, r1]
	subs r0, r3, r0
	lsls r0, r0, #8
	movs r4, #0xc
	ldrsh r2, [r5, r4]
	movs r4, #0x24
	ldrsh r1, [r5, r4]
	muls r1, r2, r1
	subs r0, r0, r1
	movs r2, #0xe
	ldrsh r1, [r5, r2]
	muls r1, r3, r1
	subs r0, r0, r1
	str r0, [r5, #0x14]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080DEDCC: .4byte sub_080DEDD8
.L080DEDD0: .4byte gSineTable
.L080DEDD4: .4byte 0x020399E0 @ EWRAM+0x399E0

	thumb_func_start sub_080DEDD8
sub_080DEDD8: @ 0x080DEDD8
	ldr r1, .L080DEE14
	ldr r2, .L080DEE18
	ldrh r0, [r2, #8]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0xa]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0xc]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0xe]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [r2, #0x10]
	strh r0, [r1]
	adds r1, #2
	ldr r3, .L080DEE1C
	ands r0, r3
	asrs r0, r0, #0x10
	strh r0, [r1]
	adds r1, #2
	ldr r0, [r2, #0x14]
	strh r0, [r1]
	adds r1, #2
	ands r0, r3
	asrs r0, r0, #0x10
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080DEE14: .4byte 0x04000020 @ REG_BG2PA
.L080DEE18: .4byte 0x020399E0 @ EWRAM+0x399E0
.L080DEE1C: .4byte 0x0FFF0000

	thumb_func_start sub_080DEE20
sub_080DEE20: @ 0x080DEE20
.L080DEE20:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r5, .L080DEEB0
	movs r2, #0
	strh r2, [r5]
	ldr r4, .L080DEEB4
	ldrh r1, [r4]
	ldr r0, .L080DEEB8
	ands r0, r1
	strh r0, [r4]
	movs r0, #1
	mov r8, r0
	strh r0, [r5]
	ldr r0, .L080DEEBC
	strh r2, [r0]
	ldr r2, .L080DEEC0
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r3, .L080DEEC4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0
	str r6, [sp]
	ldr r7, .L080DEEC8
	ldr r2, .L080DEECC
	mov r0, sp
	adds r1, r7, #0
	bl CpuSet
	ldr r0, .L080DEED0
	ldr r1, .L080DEED4
	ldr r2, .L080DEED8
	bl CpuSet
	ldr r0, .L080DEEDC
	ldr r1, .L080DEEE0
	ldr r2, .L080DEEE4
	bl CpuSet
	movs r0, #0xb
	str r0, [r7, #0x14]
	str r0, [r7, #0x18]
	adds r0, r7, #0
	adds r0, #0x30
	str r0, [r7, #0x1c]
	adds r0, #0x18
	str r0, [r7, #0x20]
	adds r0, #0x18
	str r0, [r7, #0x24]
	adds r0, #0x30
	str r0, [r7, #0x28]
	adds r0, #0x30
	str r0, [r7, #0x2c]
	strh r6, [r5]
	ldrh r0, [r4]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r4]
	mov r0, r8
	strh r0, [r5]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080DEEB0: .4byte 0x04000208 @ REG_IME
.L080DEEB4: .4byte 0x04000200 @ REG_IE
.L080DEEB8: .4byte 0x0000FF3F
.L080DEEBC: .4byte 0x04000134 @ REG_RCNT
.L080DEEC0: .4byte 0x04000128 @ REG_SIOCNT
.L080DEEC4: .4byte 0x00004003
.L080DEEC8: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DEECC: .4byte 0x0500003C @ PLTT+0x3C
.L080DEED0: .4byte arm_08032B7C
.L080DEED4: .4byte 0x030062B0 @ IWRAM+0x62B0
.L080DEED8: .4byte 0x04000010 @ REG_BG0HOFS
.L080DEEDC: .4byte SerialTimer3Intr
.L080DEEE0: .4byte 0x030060A0 @ IWRAM+0x60A0
.L080DEEE4: .4byte 0x04000048 @ REG_WININ

	thumb_func_start sub_080DEEE8
sub_080DEEE8: @ 0x080DEEE8
.L080DEEE8:
	push {lr}
	ldr r1, .L080DEEFC
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080DEEF6
	movs r0, #1
	strb r0, [r1, #6]
.L080DEEF6:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DEEFC: .4byte 0x030061C0 @ IWRAM+0x61C0

	thumb_func_start sub_080DEF00
sub_080DEF00: @ 0x080DEF00
.L080DEF00:
	push {r4, lr}
	ldr r3, .L080DEF34
	movs r4, #0
	strh r4, [r3]
	ldr r2, .L080DEF38
	ldrh r1, [r2]
	ldr r0, .L080DEF3C
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r1, .L080DEF40
	ldr r2, .L080DEF44
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #0x1c
	ldr r0, .L080DEF48
	str r0, [r1]
	adds r1, #0xf6
	movs r0, #0xc0
	strh r0, [r1]
	ldr r0, .L080DEF4C
	strb r4, [r0, #6]
	pop {r4}
	pop {r0}
	bx r0
.L080DEF34: .4byte 0x04000208 @ REG_IME
.L080DEF38: .4byte 0x04000200 @ REG_IE
.L080DEF3C: .4byte 0x0000FF3F
.L080DEF40: .4byte 0x04000128 @ REG_SIOCNT
.L080DEF44: .4byte 0x00002003
.L080DEF48: .4byte 0x0000ABFB
.L080DEF4C: .4byte 0x030061C0 @ IWRAM+0x61C0

	thumb_func_start sub_080DEF50
sub_080DEF50: @ 0x080DEF50
.L080DEF50:
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r5, .L080DEF6C
	ldr r6, [r5]
	ldr r0, .L080DEF70
	ldrb r2, [r0, #1]
	adds r7, r0, #0
	cmp r2, #1
	beq .L080DEFCE
	cmp r2, #1
	bgt .L080DEF74
	cmp r2, #0
	beq .L080DEF7A
	b .L080DF006
.L080DEF6C: .4byte 0x04000128 @ REG_SIOCNT
.L080DEF70: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DEF74:
	cmp r2, #2
	beq .L080DF000
	b .L080DF006
.L080DEF7A:
	ldr r0, [r7, #0x18]
	cmp r0, #0xb
	bne .L080DEFCA
	movs r0, #0x88
	adds r4, r6, #0
	ands r4, r0
	cmp r4, #8
	bne .L080DF006
	movs r1, #4
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne .L080DEFCA
	ldr r3, .L080DEFE4
	strh r0, [r3]
	ldr r2, .L080DEFE8
	ldrh r1, [r2]
	ldr r0, .L080DEFEC
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldrb r1, [r5, #1]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r5, #1]
	ldr r1, .L080DEFF0
	ldr r0, .L080DEFF4
	str r0, [r1]
	adds r1, #0xf6
	movs r0, #0xc0
	strh r0, [r1]
	strb r4, [r7]
.L080DEFCA:
	movs r0, #1
	strb r0, [r7, #1]
.L080DEFCE:
	ldr r1, .L080DEFF8
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq .L080DF000
	ldrb r0, [r1, #8]
	cmp r0, #7
	bhi .L080DEFFC
	adds r0, #1
	strb r0, [r1, #8]
	b .L080DF000
	.byte 0x00, 0x00
.L080DEFE4: .4byte 0x04000208 @ REG_IME
.L080DEFE8: .4byte 0x04000200 @ REG_IE
.L080DEFEC: .4byte 0x0000FF7F
.L080DEFF0: .4byte 0x0400010C @ REG_TM3CNT
.L080DEFF4: .4byte 0x0000ABFB
.L080DEFF8: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DEFFC:
	movs r0, #2
	strb r0, [r1, #1]
.L080DF000:
	mov r0, ip
	bl sub_080DF0AC
.L080DF006:
	ldr r1, .L080DF024
	ldrb r0, [r1, #0xb]
	adds r0, #1
	strb r0, [r1, #0xb]
	ldrb r3, [r1, #3]
	ldrb r0, [r1, #2]
	lsls r2, r0, #8
	ldrb r0, [r1]
	adds r7, r1, #0
	cmp r0, #8
	bne .L080DF028
	movs r0, #0x80
	orrs r0, r2
	orrs r0, r3
	b .L080DF02C
.L080DF024: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DF028:
	adds r0, r3, #0
	orrs r0, r2
.L080DF02C:
	adds r2, r0, #0
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq .L080DF03A
	movs r0, #0x80
	lsls r0, r0, #5
	orrs r2, r0
.L080DF03A:
	ldrb r0, [r7, #8]
	lsrs r0, r0, #3
	lsls r1, r0, #0xf
	lsls r0, r6, #0x1a
	lsrs r0, r0, #0x1e
	cmp r0, #1
	bls .L080DF052
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r0, r1
	orrs r0, r2
	b .L080DF056
.L080DF052:
	adds r0, r2, #0
	orrs r0, r1
.L080DF056:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080DF05C
sub_080DF05C: @ 0x080DF05C
.L080DF05C:
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, .L080DF0A4
	ldr r2, [r4, #0x1c]
	ldrb r1, [r4, #0xb]
	strb r1, [r2]
	ldr r3, [r4, #0x1c]
	ldrb r1, [r4, #2]
	ldrb r2, [r4, #3]
	eors r1, r2
	strb r1, [r3, #1]
	ldr r1, [r4, #0x1c]
	strh r5, [r1, #2]
	ldr r1, [r4, #0x1c]
	adds r1, #4
	ldr r2, .L080DF0A8
	bl CpuSet
	movs r2, #0
	ldr r1, [r4, #0x1c]
.L080DF084:
	ldrh r0, [r1]
	adds r5, r5, r0
	adds r1, #2
	adds r2, #1
	cmp r2, #9
	bls .L080DF084
	ldr r0, [r4, #0x1c]
	mvns r1, r5
	subs r1, #0xc
	strh r1, [r0, #2]
	movs r0, #1
	strb r0, [r4, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DF0A4: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DF0A8: .4byte 0x04000004 @ REG_DISPSTAT

	thumb_func_start sub_080DF0AC
sub_080DF0AC: @ 0x080DF0AC
.L080DF0AC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldr r0, .L080DF14C
	movs r4, #0
	str r4, [sp]
	bl _call_via_r0
	lsls r0, r0, #0x18
	ldr r1, .L080DF150
	strb r4, [r1, #3]
	cmp r0, #0
	beq .L080DF12E
	movs r5, #0
	add r0, sp, #4
	mov r8, r0
	adds r7, r1, #0
	movs r0, #0xd
	rsbs r0, r0, #0
	mov sl, r0
.L080DF0DC:
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, [r7, #0x2c]
	adds r1, r1, r0
	movs r4, #0
	movs r3, #0
	adds r6, r5, #1
	adds r2, r1, #0
.L080DF0EE:
	ldrh r0, [r2]
	adds r4, r4, r0
	adds r2, #2
	adds r3, #1
	cmp r3, #9
	bls .L080DF0EE
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	adds r4, r1, #4
	cmp r0, sl
	bne .L080DF11A
	lsls r1, r5, #4
	add r1, sb
	adds r0, r4, #0
	ldr r2, .L080DF154
	bl CpuSet
	movs r0, #1
	lsls r0, r5
	ldrb r1, [r7, #3]
	orrs r0, r1
	strb r0, [r7, #3]
.L080DF11A:
	movs r0, #0
	str r0, [sp, #4]
	mov r0, r8
	adds r1, r4, #0
	ldr r2, .L080DF158
	bl CpuSet
	adds r5, r6, #0
	cmp r5, #1
	ble .L080DF0DC
.L080DF12E:
	ldr r1, .L080DF150
	ldrb r0, [r1, #2]
	ldrb r2, [r1, #3]
	orrs r0, r2
	strb r0, [r1, #2]
	ldrb r0, [r1, #3]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080DF14C: .4byte 0x030062B0 @ IWRAM+0x62B0
.L080DF150: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DF154: .4byte 0x04000004 @ REG_DISPSTAT
.L080DF158: .4byte 0x05000004 @ PLTT+0x4

	thumb_func_start sub_080DF15C
sub_080DF15C: @ 0x080DF15C
.L080DF15C:
	push {r4, r5, lr}
	ldr r4, .L080DF1B4
	ldrb r5, [r4]
	cmp r5, #0
	beq .L080DF1C4
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq .L080DF1DE
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq .L080DF1DE
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #0x24]
	str r0, [r4, #0x28]
	str r1, [r4, #0x24]
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq .L080DF194
	ldr r1, [r4, #0x20]
	ldr r0, [r4, #0x1c]
	str r0, [r4, #0x20]
	str r1, [r4, #0x1c]
	movs r0, #0
	strb r0, [r4, #4]
	str r0, [r4, #0x14]
.L080DF194:
	ldr r2, .L080DF1B8
	ldr r0, [r2]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1f
	strb r0, [r4, #7]
	ldr r0, .L080DF1BC
	strh r0, [r2, #2]
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	ldr r1, .L080DF1C0
	movs r0, #0xc0
	strh r0, [r1]
	b .L080DF1DE
	.byte 0x00, 0x00
.L080DF1B4: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DF1B8: .4byte 0x04000128 @ REG_SIOCNT
.L080DF1BC: .4byte 0x0000FEFE
.L080DF1C0: .4byte 0x0400010E @ IO+0x10E
.L080DF1C4:
	ldrb r0, [r4, #9]
	cmp r0, #0
	bne .L080DF1DC
	ldr r3, .L080DF1E4
	strh r5, [r3]
	ldr r2, .L080DF1E8
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
.L080DF1DC:
	strb r5, [r4, #9]
.L080DF1DE:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080DF1E4: .4byte 0x04000208 @ REG_IME
.L080DF1E8: .4byte 0x03007FF8 @ IWRAM+0x7FF8

	thumb_func_start SerialTimer3Intr
SerialTimer3Intr: @ 0x080DF1EC
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, .L080DF2CC
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, .L080DF2D0
	ldr r0, .L080DF2D4
	ldr r0, [r0]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1f
	movs r5, #0
	strb r0, [r2, #7]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, .L080DF2D8
	adds r4, r2, #0
	cmp r1, r0
	bne .L080DF24C
	ldr r0, [r4, #0x18]
	cmp r0, #9
	ble .L080DF24C
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #0x24]
	str r0, [r4, #0x28]
	str r1, [r4, #0x24]
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq .L080DF23A
	ldr r1, [r4, #0x20]
	ldr r0, [r4, #0x1c]
	str r0, [r4, #0x20]
	str r1, [r4, #0x1c]
	strb r5, [r4, #4]
	str r5, [r4, #0x14]
.L080DF23A:
	ldr r3, .L080DF2DC
	strh r5, [r3]
	ldr r2, .L080DF2E0
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
.L080DF24C:
	ldr r0, [r4, #0x14]
	cmp r0, #9
	bgt .L080DF25E
	ldr r2, .L080DF2D4
	ldr r1, [r4, #0x20]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2, #2]
.L080DF25E:
	ldr r0, [r4, #0x14]
	cmp r0, #0xa
	bgt .L080DF268
	adds r0, #1
	str r0, [r4, #0x14]
.L080DF268:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	blt .L080DF290
	ldr r1, [r4, #0x24]
	mov r2, sp
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r3, #1
.L080DF278:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #0x18
	subs r3, #1
	cmp r3, #0
	bge .L080DF278
	ldr r0, [r4, #0x18]
	cmp r0, #9
	bne .L080DF290
	movs r0, #1
	strb r0, [r4, #5]
.L080DF290:
	ldr r0, [r4, #0x18]
	cmp r0, #9
	bgt .L080DF29A
	adds r0, #1
	str r0, [r4, #0x18]
.L080DF29A:
	ldrb r2, [r4]
	cmp r2, #0
	beq .L080DF2A6
	ldr r1, .L080DF2E4
	movs r0, #0
	strh r0, [r1]
.L080DF2A6:
	ldr r0, [r4, #0x14]
	cmp r0, #0xa
	bgt .L080DF2C0
	cmp r2, #0
	beq .L080DF2C0
	ldr r2, .L080DF2D4
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	ldr r1, .L080DF2E4
	movs r0, #0xc0
	strh r0, [r1]
.L080DF2C0:
	movs r0, #1
	strb r0, [r4, #9]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
.L080DF2CC: .4byte 0x04000120 @ REG_SIODATA32
.L080DF2D0: .4byte 0x030061C0 @ IWRAM+0x61C0
.L080DF2D4: .4byte 0x04000128 @ REG_SIOCNT
.L080DF2D8: .4byte 0x0000FEFE
.L080DF2DC: .4byte 0x04000208 @ REG_IME
.L080DF2E0: .4byte 0x03007FF8 @ IWRAM+0x7FF8
.L080DF2E4: .4byte 0x0400010E @ IO+0x10E

	thumb_func_start sub_080DF2E8
sub_080DF2E8: @ 0x080DF2E8
.L080DF2E8:
	push {lr}
	bl sub_080DEE20
	ldr r1, .L080DF30C
	movs r3, #0
	movs r2, #0
	movs r0, #0xc8
	strh r0, [r1]
	ldr r0, .L080DF310
	str r2, [r0]
	ldr r0, .L080DF314
	strb r3, [r0]
	ldr r1, .L080DF318
	movs r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DF30C: .4byte 0x03006380 @ IWRAM+0x6380
.L080DF310: .4byte 0x03006360 @ IWRAM+0x6360
.L080DF314: .4byte 0x03006368 @ IWRAM+0x6368
.L080DF318: .4byte 0x030062F0 @ IWRAM+0x62F0

	thumb_func_start sub_080DF31C
sub_080DF31C: @ 0x080DF31C
	push {lr}
	bl sub_080DEF00
	ldr r1, .L080DF32C
	movs r0, #0
	strb r0, [r1]
	pop {r0}
	bx r0
.L080DF32C: .4byte 0x03003970 @ IWRAM+0x3970

	thumb_func_start sub_080DF330
sub_080DF330: @ 0x080DF330
	push {lr}
	bl sub_080DEEE8
	ldr r2, .L080DF350
	movs r0, #0
	strh r0, [r2]
	ldr r1, .L080DF354
	ldr r3, .L080DF358
	adds r0, r3, #0
	strh r0, [r1]
	movs r1, #1
	strh r1, [r2]
	ldr r0, .L080DF35C
	strb r1, [r0]
	pop {r0}
	bx r0
.L080DF350: .4byte 0x04000208 @ REG_IME
.L080DF354: .4byte 0x04000200 @ REG_IE
.L080DF358: .4byte 0x000020C3
.L080DF35C: .4byte 0x03003970 @ IWRAM+0x3970

	thumb_func_start sub_080DF360
sub_080DF360: @ 0x080DF360
.L080DF360:
	push {lr}
	ldr r0, .L080DF36C
	bl sub_080DF05C
	pop {r0}
	bx r0
.L080DF36C: .4byte 0x03006380 @ IWRAM+0x6380

	thumb_func_start sub_080DF370
sub_080DF370: @ 0x080DF370
.L080DF370:
	push {lr}
	ldr r0, .L080DF380
	bl sub_080DEF50
	ldr r1, .L080DF384
	str r0, [r1]
	pop {r0}
	bx r0
.L080DF380: .4byte 0x03006340 @ IWRAM+0x6340
.L080DF384: .4byte 0x03006360 @ IWRAM+0x6360

	thumb_func_start sub_080DF388
sub_080DF388: @ 0x080DF388
.L080DF388:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	mov r8, r0
	ldr r2, .L080DF3A8
	ldrb r0, [r2]
	cmp r0, #1
	beq .L080DF3AC
	cmp r0, #1
	ble .L080DF480
	cmp r0, #2
	beq .L080DF3F8
	b .L080DF480
.L080DF3A8: .4byte 0x030062F0 @ IWRAM+0x62F0
.L080DF3AC:
	ldr r0, .L080DF3C0
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq .L080DF3C4
	movs r0, #0
	b .L080DF482
	.byte 0x00, 0x00
.L080DF3C0: .4byte 0x03006360 @ IWRAM+0x6360
.L080DF3C4:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	beq .L080DF480
	movs r0, #2
	strb r0, [r2]
	ldr r1, .L080DF3F4
	movs r0, #0xc1
	lsls r0, r0, #8
	strh r0, [r1]
	adds r5, r1, #2
	movs r2, #0
.L080DF3DE:
	ldrb r0, [r4]
	strb r0, [r5]
	adds r4, #1
	adds r5, #1
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls .L080DF3DE
	b .L080DF480
	.byte 0x00, 0x00
.L080DF3F4: .4byte 0x03006380 @ IWRAM+0x6380
.L080DF3F8:
	movs r0, #0xc1
	lsls r0, r0, #8
	bl sub_080DF6FC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080DF480
	mov r3, sp
	mov r2, sp
	mov r1, sp
	mov r0, sp
	mov r5, r8
	strb r5, [r0, #3]
	strb r5, [r1, #2]
	strb r5, [r2, #1]
	strb r5, [r3]
	movs r3, #0
	ldr r0, .L080DF490
	mov ip, r0
	movs r7, #1
.L080DF422:
	lsls r0, r3, #4
	mov r1, ip
	adds r5, r0, r1
	mov r0, sp
	adds r1, r0, r3
	movs r0, #0
	strb r0, [r1]
	movs r2, #0
	adds r6, r3, #1
	adds r3, r1, #0
.L080DF436:
	adds r0, r4, r2
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq .L080DF444
	strb r7, [r3]
.L080DF444:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls .L080DF436
	lsls r0, r6, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls .L080DF422
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080DF480
	mov r0, sp
	ldrb r0, [r0, #1]
	cmp r0, #0
	bne .L080DF480
	mov r0, sp
	ldrb r0, [r0, #2]
	cmp r0, #0
	bne .L080DF480
	mov r0, sp
	ldrb r0, [r0, #3]
	adds r1, r0, #0
	cmp r1, #0
	bne .L080DF480
	movs r5, #1
	mov r8, r5
	ldr r0, .L080DF494
	strh r1, [r0]
.L080DF480:
	mov r0, r8
.L080DF482:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080DF490: .4byte 0x03006342 @ IWRAM+0x6342
.L080DF494: .4byte 0x03006380 @ IWRAM+0x6380

	thumb_func_start sub_080DF498
sub_080DF498: @ 0x080DF498
	ldr r1, .L080DF4AC
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L080DF4B0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080DF4B4
	strb r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080DF4AC: .4byte 0x030062F4 @ IWRAM+0x62F4
.L080DF4B0: .4byte 0x03006364 @ IWRAM+0x6364
.L080DF4B4: .4byte 0x03006370 @ IWRAM+0x6370

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
