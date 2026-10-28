	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_08134250
sub_08134250: @ 0x08134250
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r7, #0
	ldr r0, .L0813427C
	strh r7, [r0]
	ldr r0, .L08134280
	movs r1, #1
	strh r1, [r0]
	mov r0, r8
	cmp r0, #0
	bne .L08134288
	ldr r0, .L08134284
	strh r7, [r0]
	b .L081342A4
	.byte 0x00, 0x00
.L0813427C: .4byte 0x0300669C @ IWRAM+0x669C
.L08134280: .4byte 0x0300699C @ IWRAM+0x699C
.L08134284: .4byte 0x03006848 @ IWRAM+0x6848
.L08134288:
	mov r3, r8
	cmp r3, #9
	bne .L081342A0
	ldr r0, .L08134298
	strh r1, [r0]
	ldr r0, .L0813429C
	strh r7, [r0]
	b .L081342A8
.L08134298: .4byte 0x03006848 @ IWRAM+0x6848
.L0813429C: .4byte 0x03006680 @ IWRAM+0x6680
.L081342A0:
	ldr r0, .L081342C8
	strh r1, [r0]
.L081342A4:
	ldr r0, .L081342CC
	strh r1, [r0]
.L081342A8:
	movs r4, #0
	ldr r2, .L081342D0
	movs r1, #0
.L081342AE:
	lsls r0, r4, #1
	adds r0, r0, r2
	strh r1, [r0]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x63
	bls .L081342AE
	mov r4, r8
	adds r0, r4, #3
	cmp r4, r0
	bge .L0813437A
	b .L0813436C
.L081342C8: .4byte 0x03006848 @ IWRAM+0x6848
.L081342CC: .4byte 0x03006680 @ IWRAM+0x6680
.L081342D0: .4byte 0x0203DA00 @ EWRAM+0x3DA00
.L081342D4:
	lsls r0, r4, #2
	ldr r3, .L0813438C
	adds r1, r0, r3
	ldr r1, [r1]
	movs r7, #4
	mov sb, r0
	cmp r1, #0
	beq .L081342E6
	movs r7, #0
.L081342E6:
	adds r0, r2, #0
	bl Action_GetRecord
	adds r3, r0, #0
	adds r3, #0xc
	movs r2, #0
	adds r0, r4, #1
	str r0, [sp]
	mov r1, r8
	subs r5, r4, r1
	movs r0, #3
	add r0, r8
	mov sl, r0
	ldr r4, .L08134390
	movs r1, #0
.L08134304:
	lsls r0, r2, #1
	adds r0, r0, r4
	strh r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xf
	bls .L08134304
	movs r2, #0
	ldr r6, .L08134394
	ldr r4, .L08134390
.L0813431A:
	lsls r0, r2, #1
	adds r0, r0, r4
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, #2
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #7
	bls .L0813431A
	lsls r4, r5, #1
	adds r0, r4, r6
	ldrh r1, [r0]
	movs r0, #0x27
	adds r2, r7, #0
	movs r3, #8
	bl sub_08133724
	lsls r1, r5, #4
	ldr r3, .L08134398
	adds r2, r1, r3
	movs r0, #1
	strh r0, [r2]
	ldr r0, .L0813439C
	adds r1, r1, r0
	ldr r0, .L0813438C
	add r0, sb
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0x80
	strh r0, [r2, #8]
	ldr r0, .L081343A0
	adds r4, r4, r0
	ldrh r0, [r4]
	strh r0, [r2, #0xa]
	strh r7, [r2, #0xc]
	ldr r1, [sp]
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, sl
	bge .L0813437A
.L0813436C:
	ldr r0, .L081343A4
	lsls r1, r4, #1
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, .L081343A8
	cmp r2, r0
	bne .L081342D4
.L0813437A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813438C: .4byte 0x0203BD74 @ EWRAM+0x3BD74
.L08134390: .4byte 0x0203DB08 @ EWRAM+0x3DB08
.L08134394: .4byte gUnknown_0879038A
.L08134398: .4byte 0x03006620 @ IWRAM+0x6620
.L0813439C: .4byte 0x03006624 @ IWRAM+0x6624
.L081343A0: .4byte gUnknown_0878FC64
.L081343A4: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L081343A8: .4byte 0x0000FFFF

	thumb_func_start ScriptOp_33B
ScriptOp_33B: @ 0x081343AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r3, .L0813451C
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08134520
	ldr r4, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r5, [r0]
	adds r2, r1, #1
	strh r2, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	orrs r0, r5
	ldr r5, .L08134524
	str r0, [r5]
	adds r0, r2, #1
	strh r0, [r3]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xf
	adds r2, r2, r4
	ldrh r2, [r2]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	orrs r0, r2
	str r0, [r5, #4]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r2, [r1]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	orrs r0, r2
	str r0, [r5, #8]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r2, [r1]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	orrs r0, r2
	str r0, [r5, #0xc]
	movs r0, #0
	str r0, [r5, #0x10]
	movs r5, #0
	ldr r7, .L08134528
	ldr r0, .L0813452C
	mov r8, r0
	ldr r1, .L08134530
	mov ip, r1
	ldr r6, .L08134534
	ldr r0, .L08134538
	adds r4, r0, #0
	ldr r3, .L0813453C
	movs r2, #1
	rsbs r2, r2, #0
.L08134450:
	lsls r1, r5, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	lsls r0, r5, #2
	adds r0, r0, r3
	str r2, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xff
	bls .L08134450
	mov r1, ip
	ldrh r0, [r1]
	lsls r0, r0, #6
	add r0, r8
	ldrh r0, [r0]
	adds r0, #1
	strh r0, [r7]
	movs r5, #0
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r5, r0
	bge .L081344B8
	mov r7, r8
	ldr r6, .L08134534
.L08134486:
	lsls r2, r5, #1
	adds r2, r2, r6
	adds r4, r5, #1
	lsls r1, r4, #1
	ldr r0, .L08134530
	ldrh r0, [r0]
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r7
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r2]
	bl sub_080C4C60
	ldr r2, .L0813453C
	lsls r1, r5, #2
	adds r1, r1, r2
	str r0, [r1]
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	ldr r0, .L08134528
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt .L08134486
.L081344B8:
	ldr r1, .L08134540
	movs r0, #0x22
	strh r0, [r1]
	movs r5, #0
	ldr r4, .L08134544
	ldr r6, .L08134548
	ldr r7, .L0813454C
	ldr r3, .L08134550
	ldr r2, .L08134554
.L081344CA:
	lsls r1, r5, #1
	adds r1, r1, r3
	lsls r0, r5, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xe
	bls .L081344CA
	movs r0, #0
	strh r0, [r4]
	strh r0, [r6]
	strh r0, [r7]
	movs r0, #0
	movs r1, #0
	bl Shop_InitItemList
	ldr r0, .L08134558
	ldrh r1, [r0]
	ldr r0, .L08134534
	ldrh r2, [r0]
	movs r0, #1
	bl sub_080D3400
	ldr r1, .L0813455C
	str r0, [r1]
	ldr r0, .L08134560
	ldr r1, .L08134538
	bl Task_Create
	ldr r1, .L08134564
	movs r0, #1
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813451C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134520: .4byte 0x03006950 @ IWRAM+0x6950
.L08134524: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08134528: .4byte 0x03006688 @ IWRAM+0x6688
.L0813452C: .4byte gUnknown_0878EFB8
.L08134530: .4byte 0x03006914 @ IWRAM+0x6914
.L08134534: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08134538: .4byte 0x0000FFFF
.L0813453C: .4byte 0x0203BD74 @ EWRAM+0x3BD74
.L08134540: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08134544: .4byte 0x03006940 @ IWRAM+0x6940
.L08134548: .4byte 0x0300696C @ IWRAM+0x696C
.L0813454C: .4byte 0x030065E4 @ IWRAM+0x65E4
.L08134550: .4byte 0x03006820 @ IWRAM+0x6820
.L08134554: .4byte 0x0203D800 @ EWRAM+0x3D800
.L08134558: .4byte 0x03006898 @ IWRAM+0x6898
.L0813455C: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08134560: .4byte gUnknown_0878FD58
.L08134564: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_33C
ScriptOp_33C: @ 0x08134568
	push {r4, r5, lr}
	ldr r3, .L081345B8
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L081345BC
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r4, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r0, [r1]
	lsls r5, r0, #0x10
	orrs r5, r4
	ldr r0, .L081345C0
	ldrh r1, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xcf
	bgt .L081345B0
	ldr r0, .L081345C4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_080CDB74
	cmp r0, #0
	bne .L081345B0
	ldr r0, .L081345C8
	str r5, [r0]
.L081345B0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081345B8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081345BC: .4byte 0x03006950 @ IWRAM+0x6950
.L081345C0: .4byte 0x030069A8 @ IWRAM+0x69A8
.L081345C4: .4byte 0x03006898 @ IWRAM+0x6898
.L081345C8: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_33D
ScriptOp_33D: @ 0x081345CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	movs r2, #0
	ldr r5, .L081347F4
	ldr r6, .L081347F8
	ldr r1, .L081347FC
	mov sl, r1
	ldr r7, .L08134800
	ldr r4, .L08134804
	ldr r3, .L08134808
.L081345EC:
	lsls r1, r2, #1
	adds r1, r1, r4
	lsls r0, r2, #3
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xe
	bls .L081345EC
	ldr r2, .L0813480C
	mov sb, r2
	adds r2, r5, #0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, [r6]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, sb
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	bne .L0813462C
	movs r0, #1
	strh r0, [r3]
	movs r4, #1
	str r4, [sp]
.L0813462C:
	ldr r1, .L08134810
	movs r0, #0x25
	strh r0, [r1]
	ldr r2, [sp]
	cmp r2, #0
	beq .L0813463C
	movs r0, #0x2a
	strh r0, [r1]
.L0813463C:
	mov r3, sl
	ldrh r0, [r3]
	ldrh r1, [r7]
	bl Shop_InitItemList
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	lsls r0, r0, #0x10
	ldr r3, [r6]
	lsrs r0, r0, #0xf
	adds r0, r0, r3
	ldrh r4, [r0]
	adds r2, r1, #1
	strh r2, [r5]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r3
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	orrs r0, r4
	ldr r4, .L08134814
	str r0, [r4]
	adds r0, r2, #1
	strh r0, [r5]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xf
	adds r2, r2, r3
	ldrh r2, [r2]
	adds r1, r0, #1
	strh r1, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	orrs r0, r2
	str r0, [r4, #4]
	adds r0, r1, #1
	strh r0, [r5]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r3
	ldrh r2, [r1]
	adds r1, r0, #1
	strh r1, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	orrs r0, r2
	str r0, [r4, #8]
	ldr r4, .L08134818
	ldr r3, .L0813481C
	movs r6, #0
	ldrsh r0, [r3, r6]
	lsls r0, r0, #3
	adds r0, r0, r4
	movs r5, #0
	movs r1, #0x3e
	strh r1, [r0]
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #2
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0xbc
	strh r1, [r0]
	movs r2, #0
	ldrsh r1, [r3, r2]
	lsls r1, r1, #2
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r4
	ldr r2, .L08134820
	ldr r7, .L08134824
	movs r6, #0
	ldrsh r0, [r7, r6]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #2
	adds r0, #3
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r5, [r0]
	movs r0, #0x19
	strh r0, [r3]
	ldr r6, .L08134828
	movs r2, #1
	mov r8, r2
	mov r3, r8
	strh r3, [r6, #0x30]
	mov r4, sb
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r6, #0x34]
	movs r0, #0x98
	strh r0, [r6, #0x38]
	ldr r4, .L0813482C
	movs r2, #0
	ldrsh r0, [r7, r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r6, #0x3a]
	strh r5, [r6, #0x3c]
	adds r0, r6, #0
	adds r0, #0x40
	mov r3, r8
	strh r3, [r0]
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r6, #0x44]
	adds r1, r6, #0
	adds r1, #0x48
	movs r0, #0x90
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r7, r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x4c
	strh r5, [r0]
	ldr r0, .L08134830
	ldrh r1, [r0]
	ldr r5, .L08134834
	movs r4, #0
	ldrsh r0, [r7, r4]
	mov r6, sl
	movs r3, #0
	ldrsh r2, [r6, r3]
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	movs r0, #2
	bl sub_080D3400
	ldr r1, .L08134838
	str r0, [r1]
	movs r4, #0
	ldrsh r0, [r7, r4]
	movs r2, #0
	ldrsh r1, [r6, r2]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	bl sub_080C4C60
	ldr r4, .L0813483C
	str r0, [r4]
	movs r6, #0x25
	ldr r3, .L08134810
	strh r6, [r3]
	ldr r0, [sp]
	cmp r0, #0
	beq .L081347BE
	movs r0, #0x2a
	strh r0, [r3]
	movs r1, #0
	ldrsh r0, [r7, r1]
	mov r2, sl
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	bl sub_080C4C7C
	str r0, [r4]
.L081347BE:
	ldr r2, .L08134840
	ldr r6, .L0813480C
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r1, [r4]
	muls r0, r1, r0
	str r0, [r2]
	ldr r1, .L08134844
	cmp r0, r1
	bls .L081347D4
	str r1, [r2]
.L081347D4:
	ldr r0, .L08134848
	ldr r1, .L0813484C
	bl Task_Create
	ldr r0, .L08134850
	mov r2, r8
	strh r2, [r0]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081347F4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081347F8: .4byte 0x03006950 @ IWRAM+0x6950
.L081347FC: .4byte 0x03006940 @ IWRAM+0x6940
.L08134800: .4byte 0x030065E4 @ IWRAM+0x65E4
.L08134804: .4byte 0x03006820 @ IWRAM+0x6820
.L08134808: .4byte 0x0203D800 @ EWRAM+0x3D800
.L0813480C: .4byte 0x030065FC @ IWRAM+0x65FC
.L08134810: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08134814: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08134818: .4byte 0x0203DA00 @ EWRAM+0x3DA00
.L0813481C: .4byte 0x0300669C @ IWRAM+0x669C
.L08134820: .4byte gUnknown_0879038A
.L08134824: .4byte 0x0300696C @ IWRAM+0x696C
.L08134828: .4byte 0x03006620 @ IWRAM+0x6620
.L0813482C: .4byte gUnknown_0878FC64
.L08134830: .4byte 0x03006898 @ IWRAM+0x6898
.L08134834: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08134838: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813483C: .4byte 0x03006694 @ IWRAM+0x6694
.L08134840: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L08134844: .4byte 0x000F423F
.L08134848: .4byte gUnknown_0878FF8C
.L0813484C: .4byte 0x0000FFFF
.L08134850: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_33E
ScriptOp_33E: @ 0x08134854
	push {r4, r5, lr}
	ldr r3, .L081348A4
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L081348A8
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r4, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r5, [r1]
	lsls r5, r5, #0x10
	orrs r5, r4
	ldr r1, .L081348AC
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0xcf
	ble .L08134888
	ldr r0, .L081348B0
	str r5, [r0]
.L08134888:
	ldr r0, .L081348B4
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrb r1, [r1]
	bl sub_080CDB74
	cmp r0, #0
	bne .L0813489C
	ldr r0, .L081348B0
	str r5, [r0]
.L0813489C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081348A4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081348A8: .4byte 0x03006950 @ IWRAM+0x6950
.L081348AC: .4byte 0x030069A8 @ IWRAM+0x69A8
.L081348B0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081348B4: .4byte 0x03006898 @ IWRAM+0x6898

	thumb_func_start ScriptOp_33F
ScriptOp_33F: @ 0x081348B8
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r1, .L081348F0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r4, r0
	bge .L081348DE
	ldr r6, .L081348F4
	adds r5, r1, #0
.L081348CA:
	ldrh r0, [r6]
	bl sub_080C3328
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt .L081348CA
.L081348DE:
	ldr r0, .L081348F8
	ldrh r0, [r0]
	ldr r1, .L081348F4
	ldrh r1, [r1]
	bl sub_080CDFBC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L081348F0: .4byte 0x030065FC @ IWRAM+0x65FC
.L081348F4: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L081348F8: .4byte 0x03006898 @ IWRAM+0x6898

	thumb_func_start ScriptOp_340
ScriptOp_340: @ 0x081348FC
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_Choice
ScriptOp_Choice: @ 0x08134900
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, .L08134A14
	ldr r2, .L08134A18
	adds r0, r2, #0
	strh r0, [r1]
	ldr r2, .L08134A1C
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08134A20
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	lsrs r5, r1, #8
	movs r0, #0xff
	ands r0, r1
	ldr r1, .L08134A24
	strh r0, [r1]
	cmp r0, #3
	ble .L08134938
	movs r0, #0
	strh r0, [r1]
.L08134938:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #1
	beq .L08134944
	cmp r0, #3
	bne .L08134948
.L08134944:
	bl sub_0812F198
.L08134948:
	movs r1, #0
	ldr r6, .L08134A28
	ldr r0, .L08134A2C
	mov sb, r0
	ldr r2, .L08134A30
	mov sl, r2
	ldr r4, .L08134A34
	ldr r7, .L08134A18
	adds r3, r7, #0
.L0813495A:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #1
	adds r2, r2, r4
	ldrh r1, [r2]
	orrs r1, r3
	strh r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	ble .L0813495A
	strh r5, [r6]
	movs r1, #0
	movs r2, #0
	ldrsh r0, [r6, r2]
	adds r0, #1
	cmp r1, r0
	bge .L081349DE
	ldr r7, .L08134A34
	mov r8, r7
	ldr r5, .L08134A1C
	ldr r0, .L08134A20
	mov ip, r0
.L0813498C:
	lsls r3, r1, #0x10
	asrs r3, r3, #0x10
	lsls r1, r3, #1
	add r1, r8
	ldrh r0, [r5]
	adds r2, r0, #1
	strh r2, [r5]
	lsls r0, r0, #0x10
	mov r7, ip
	ldr r4, [r7]
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, r2, #1
	strh r1, [r5]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xf
	adds r2, r2, r4
	ldrh r2, [r2]
	adds r0, r1, #1
	strh r0, [r5]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	orrs r1, r2
	lsls r0, r3, #2
	ldr r2, .L08134A38
	adds r0, r0, r2
	str r1, [r0]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x10
	asrs r3, r3, #0x10
	movs r7, #0
	ldrsh r0, [r6, r7]
	adds r0, #1
	cmp r3, r0
	blt .L0813498C
.L081349DE:
	movs r0, #0
	mov r1, sb
	strh r0, [r1]
	mov r2, sl
	strh r0, [r2]
	ldr r7, .L08134A24
	ldrh r0, [r7]
	bl sub_0812F2B4
	ldr r1, .L08134A3C
	movs r0, #1
	strh r0, [r1]
	ldr r0, .L08134A40
	ldr r1, .L08134A18
	bl Task_Create
	ldr r1, .L08134A44
	movs r0, #0xd
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08134A14: .4byte 0x030065E0 @ IWRAM+0x65E0
.L08134A18: .4byte 0x0000FFFF
.L08134A1C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134A20: .4byte 0x03006950 @ IWRAM+0x6950
.L08134A24: .4byte 0x03006844 @ IWRAM+0x6844
.L08134A28: .4byte 0x03006604 @ IWRAM+0x6604
.L08134A2C: .4byte 0x03006940 @ IWRAM+0x6940
.L08134A30: .4byte 0x0300696C @ IWRAM+0x696C
.L08134A34: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L08134A38: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08134A3C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08134A40: .4byte gUnknown_0878FC80
.L08134A44: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start ScriptOp_352
ScriptOp_352: @ 0x08134A48
	push {lr}
	ldr r2, .L08134A68
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08134A6C
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x63
	bhi .L08134A70
	bl sub_080C5170
	b .L08134A74
.L08134A68: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134A6C: .4byte 0x03006950 @ IWRAM+0x6950
.L08134A70:
	bl sub_080C51D4
.L08134A74:
	pop {r0}
	bx r0

	thumb_func_start ScriptOp_353
ScriptOp_353: @ 0x08134A78
	push {r4, lr}
	ldr r2, .L08134AB0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08134AB4
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r4, [r0]
	lsls r4, r4, #8
	ldr r0, .L08134AB8
	cmp r4, r0
	ble .L08134A9A
	ldr r0, .L08134ABC
	orrs r4, r0
.L08134A9A:
	movs r0, #0
	adds r1, r4, #0
	bl Combatant_AddAlignment
	movs r0, #1
	adds r1, r4, #0
	bl Combatant_AddAlignment
	pop {r4}
	pop {r0}
	bx r0
.L08134AB0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134AB4: .4byte 0x03006950 @ IWRAM+0x6950
.L08134AB8: .4byte 0x00007FFF
.L08134ABC: .4byte 0xFFFF0000

	thumb_func_start ScriptOp_354
ScriptOp_354: @ 0x08134AC0
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_355
ScriptOp_355: @ 0x08134AC4
	push {lr}
	movs r0, #0
	bl Combatant_GetAlignment
	cmp r0, #0
	bne .L08134AF8
	ldr r2, .L08134AF0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08134AF4
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r3, [r0]
	ldrh r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	b .L08134B0C
	.byte 0x00, 0x00
.L08134AF0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134AF4: .4byte 0x03006950 @ IWRAM+0x6950
.L08134AF8:
	cmp r0, #2
	bne .L08134B24
	ldr r0, .L08134B18
	ldrh r0, [r0]
	ldr r1, .L08134B1C
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r3, [r0, #4]
	ldrh r1, [r0, #6]
.L08134B0C:
	lsls r1, r1, #0x10
	orrs r1, r3
	ldr r0, .L08134B20
	str r1, [r0]
	b .L08134B2C
	.byte 0x00, 0x00
.L08134B18: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134B1C: .4byte 0x03006950 @ IWRAM+0x6950
.L08134B20: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08134B24:
	ldr r1, .L08134B30
	ldrh r0, [r1]
	adds r0, #4
	strh r0, [r1]
.L08134B2C:
	pop {r0}
	bx r0
.L08134B30: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_356
ScriptOp_356: @ 0x08134B34
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r5, .L08134B9C
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	lsls r0, r0, #0x10
	ldr r1, .L08134BA0
	mov r8, r1
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r1, #0xff
	adds r0, r4, #0
	ands r0, r1
	adds r6, r0, #1
	lsrs r4, r4, #8
	ands r4, r1
	movs r0, #0
	bl sub_080C0794
	lsrs r7, r0, #8
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	lsls r0, r0, #0x10
	mov r3, r8
	ldr r2, [r3]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r3, [r0]
	adds r0, r1, #1
	strh r0, [r5]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r0, [r1]
	lsls r1, r0, #0x10
	orrs r1, r3
	cmp r7, r4
	blo .L08134B92
	cmp r7, r6
	bhs .L08134B92
	ldr r0, .L08134BA4
	str r1, [r0]
.L08134B92:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08134B9C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134BA0: .4byte 0x03006950 @ IWRAM+0x6950
.L08134BA4: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_357
ScriptOp_357: @ 0x08134BA8
	push {r4, r5, r6, lr}
	ldr r3, .L08134BF4
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08134BF8
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r5, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r4, [r1]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r6, r0, #0x10
	orrs r6, r4
	movs r0, #0
	bl Combatant_GetLevel
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r5
	bgt .L08134BEC
	ldr r0, .L08134BFC
	str r6, [r0]
.L08134BEC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08134BF4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134BF8: .4byte 0x03006950 @ IWRAM+0x6950
.L08134BFC: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_358
ScriptOp_358: @ 0x08134C00
	ldr r3, .L08134C28
	ldr r2, .L08134C2C
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08134C30
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r3]
	ldr r1, .L08134C34
	movs r0, #0xf
	strh r0, [r1]
	ldr r1, .L08134C38
	movs r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08134C28: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L08134C2C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134C30: .4byte 0x03006950 @ IWRAM+0x6950
.L08134C34: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08134C38: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start sub_08134C3C
sub_08134C3C: @ 0x08134C3C
.L08134C3C:
	movs r0, #0
	bx lr

	thumb_func_start ScriptOp_359
ScriptOp_359: @ 0x08134C40
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r2, .L08134C6C
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08134C70
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, .L08134C74
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r7, [r0]
	bl Stock_GetCapacity
	adds r5, r0, #0
	movs r4, #4
	b .L08134C94
.L08134C6C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134C70: .4byte 0x03006950 @ IWRAM+0x6950
.L08134C74: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L08134C78:
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08134C92
	adds r0, r4, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	bne .L08134C92
	adds r6, #1
.L08134C92:
	adds r4, #1
.L08134C94:
	adds r0, r5, #4
	cmp r4, r0
	blo .L08134C78
	cmp r6, #0
	beq .L08134CAC
	ldr r1, .L08134CA8
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	b .L08134CD0
.L08134CA8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134CAC:
	ldr r2, .L08134CD8
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08134CDC
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r3, [r0]
	ldrh r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	orrs r0, r3
	ldr r1, .L08134CE0
	str r0, [r1]
.L08134CD0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08134CD8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134CDC: .4byte 0x03006950 @ IWRAM+0x6950
.L08134CE0: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_35A
ScriptOp_35A: @ 0x08134CE4
	push {r4, r5, r6, lr}
	ldr r3, .L08134D30
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08134D34
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r4, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r6, [r1]
	lsls r6, r6, #0x10
	orrs r6, r4
	bl Stock_GetCapacity
	adds r5, r0, #0
	movs r4, #0
	cmp r4, r5
	bhs .L08134D26
.L08134D16:
	adds r0, r4, #4
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08134D2A
	adds r4, #1
	cmp r4, r5
	blo .L08134D16
.L08134D26:
	ldr r0, .L08134D38
	str r6, [r0]
.L08134D2A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08134D30: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134D34: .4byte 0x03006950 @ IWRAM+0x6950
.L08134D38: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_35B
ScriptOp_35B: @ 0x08134D3C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_35C
ScriptOp_35C: @ 0x08134D40
	push {r4, r5, r6, lr}
	bl Stock_GetCapacity
	adds r5, r0, #0
	ldr r3, .L08134DA8
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08134DAC
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r4, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r6, [r1]
	cmp r4, #0xff
	bne .L08134DB0
	movs r4, #0
	adds r5, #4
	cmp r4, r5
	bge .L08134DB8
.L08134D74:
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08134D9A
	adds r0, r4, #0
	bl Combatant_IsDead
	cmp r0, #0
	bne .L08134D9A
	adds r0, r4, #0
	bl sub_080F3EC8
	cmp r0, #0
	beq .L08134D9A
	adds r0, r4, #0
	rsbs r1, r6, #0
	bl Combatant_ChangeHpPercent
.L08134D9A:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	blt .L08134D74
	b .L08134DB8
	.byte 0x00, 0x00
.L08134DA8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134DAC: .4byte 0x03006950 @ IWRAM+0x6950
.L08134DB0:
	rsbs r1, r6, #0
	adds r0, r4, #0
	bl Combatant_ChangeHpPercent
.L08134DB8:
	bl sub_080C84A0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_35D
ScriptOp_35D: @ 0x08134DC4
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_08134DC8
sub_08134DC8: @ 0x08134DC8
.L08134DC8:
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1

	thumb_func_start sub_08134DE0
sub_08134DE0: @ 0x08134DE0
.L08134DE0:
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x1a
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1

	thumb_func_start sub_08134DF8
sub_08134DF8: @ 0x08134DF8
.L08134DF8:
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x1c
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1

	thumb_func_start sub_08134E10
sub_08134E10: @ 0x08134E10
.L08134E10:
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r1, #0x1e
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1

	thumb_func_start ScriptOp_35E
ScriptOp_35E: @ 0x08134E28
	push {r4, r5, r6, lr}
	bl Stock_GetCapacity
	adds r5, r0, #0
	ldr r2, .L08134E68
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08134E6C
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r3, [r0]
	movs r1, #0xff
	adds r0, r3, #0
	ands r0, r1
	lsrs r2, r3, #8
	ands r2, r1
	adds r3, r2, #0
	ldr r1, .L08134E70
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r6, [r0]
	cmp r2, #1
	beq .L08134EEC
	cmp r2, #1
	bgt .L08134E74
	cmp r2, #0
	beq .L08134E7A
	b .L08134F5A
	.byte 0x00, 0x00
.L08134E68: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08134E6C: .4byte 0x03006950 @ IWRAM+0x6950
.L08134E70: .4byte gUnknown_08790398
.L08134E74:
	cmp r3, #2
	beq .L08134EB6
	b .L08134F5A
.L08134E7A:
	movs r0, #0
	bl Combatant_IsAlive
	cmp r0, #0
	bne .L08134E86
	b .L08134FAE
.L08134E86:
	movs r0, #0
	adds r1, r6, #0
	bl sub_080C08E8
	movs r0, #0
	bl Combatant_GetStatus
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	bne .L08134EA0
	b .L08134FAE
.L08134EA0:
	movs r0, #0
	bl sub_08134DC8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	rsbs r1, r1, #0
	movs r0, #0
	bl Combatant_ChangeHp
	b .L08134FAE
.L08134EB6:
	movs r0, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L08134EEC
	movs r0, #0
	adds r1, r6, #0
	bl sub_080C08E8
	movs r0, #0
	bl Combatant_GetStatus
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L08134EEC
	movs r0, #0
	bl sub_08134DC8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	rsbs r1, r1, #0
	movs r0, #0
	bl Combatant_ChangeHp
.L08134EEC:
	movs r0, #1
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L08134F22
	movs r0, #1
	adds r1, r6, #0
	bl sub_080C08E8
	movs r0, #1
	bl Combatant_GetStatus
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L08134F22
	movs r0, #1
	bl sub_08134DC8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	rsbs r1, r1, #0
	movs r0, #1
	bl Combatant_ChangeHp
.L08134F22:
	movs r0, #2
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L08134FAE
	movs r0, #2
	adds r1, r6, #0
	bl sub_080C08E8
	movs r0, #2
	bl Combatant_GetStatus
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L08134FAE
	movs r0, #2
	bl sub_08134DC8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	rsbs r1, r1, #0
	movs r0, #2
	bl Combatant_ChangeHp
	b .L08134FAE
.L08134F5A:
	movs r4, #0
	adds r5, #4
	cmp r4, r5
	bge .L08134FAE
.L08134F62:
	adds r0, r4, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L08134FA4
	adds r0, r4, #0
	bl sub_080F3EC8
	cmp r0, #0
	beq .L08134FA4
	adds r0, r4, #0
	adds r1, r6, #0
	bl sub_080C08E8
	adds r0, r4, #0
	bl Combatant_GetStatus
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L08134FA4
	adds r0, r4, #0
	bl sub_08134DC8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	rsbs r1, r1, #0
	adds r0, r4, #0
	bl Combatant_ChangeHp
.L08134FA4:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	blt .L08134F62
.L08134FAE:
	bl sub_080C84A0
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ScriptOp_35F
ScriptOp_35F: @ 0x08134FB8
	push {r4, r5, lr}
	ldr r0, .L08134FFC
	movs r4, #0
	strh r4, [r0]
	ldr r0, .L08135000
	strh r4, [r0]
	ldr r0, .L08135004
	strh r4, [r0]
	ldr r5, .L08135008
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq .L08134FDE
	ldr r0, .L0813500C
	ldr r0, [r0]
	movs r1, #1
	bl Window_Close
	strh r4, [r5]
.L08134FDE:
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r1, .L08135010
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, .L08135014
	ldrh r0, [r0]
	cmp r0, #2
	bne .L08135018
	movs r0, #2
	b .L0813503E
	.byte 0x00, 0x00
.L08134FFC: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L08135000: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L08135004: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L08135008: .4byte 0x0203DB6C @ EWRAM+0x3DB6C
.L0813500C: .4byte 0x03006968 @ IWRAM+0x6968
.L08135010: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08135014: .4byte 0x030068A8 @ IWRAM+0x68A8
.L08135018:
	cmp r0, #3
	bne .L08135020
	movs r0, #3
	b .L0813503E
.L08135020:
	cmp r0, #1
	bne .L08135028
	movs r0, #4
	b .L0813503E
.L08135028:
	cmp r0, #4
	bne .L08135030
	movs r0, #1
	b .L0813503E
.L08135030:
	cmp r0, #5
	bne .L08135038
	movs r0, #5
	b .L0813503E
.L08135038:
	cmp r0, #6
	bne .L08135046
	movs r0, #6
.L0813503E:
	bl sub_08155F94
	ldr r1, .L08135058
	str r0, [r1]
.L08135046:
	ldr r1, .L0813505C
	movs r0, #0x2c
	strh r0, [r1]
	ldr r1, .L08135060
	movs r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08135058: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813505C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135060: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start sub_08135064
sub_08135064: @ 0x08135064
.L08135064:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r5, #0
	cmp r4, #1
	bhi .L0813508E
	ldr r1, .L081350C8
	lsls r0, r6, #7
	adds r0, r0, r1
	ldrh r1, [r0, #0x10]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L0813508E
	adds r0, r6, #0
	bl sub_08135200
	adds r5, r0, #0
.L0813508E:
	cmp r4, #2
	beq .L08135096
	cmp r4, #0
	bne .L0813509E
.L08135096:
	adds r0, r6, #0
	bl sub_081352F8
	adds r5, r5, r0
.L0813509E:
	cmp r4, #3
	beq .L081350A6
	cmp r4, #0
	bne .L081350AE
.L081350A6:
	adds r0, r6, #0
	bl sub_08135320
	adds r5, r5, r0
.L081350AE:
	cmp r4, #4
	beq .L081350B6
	cmp r4, #0
	bne .L081350BE
.L081350B6:
	adds r0, r6, #0
	bl sub_08135348
	adds r5, r5, r0
.L081350BE:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L081350C8: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_081350CC
sub_081350CC: @ 0x081350CC
.L081350CC:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #4
	bhi .L08135170
	lsls r0, r0, #2
	ldr r1, .L081350E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L081350E4: .4byte gUnknown_081350E8
	.global gUnknown_081350E8
gUnknown_081350E8:
.L081350E8: @ jump table
	.4byte .L0813513C
	.4byte .L08135114
	.4byte .L081350FC
	.4byte .L0813510C
	.4byte .L08135128
.L081350FC:
	adds r0, r4, #0
	ldr r1, .L08135108
	bl Combatant_ClearStatus
	b .L08135170
	.byte 0x00, 0x00
.L08135108: .4byte 0x00008C01
.L0813510C:
	ldr r1, .L08135124
	adds r0, r4, #0
	bl Combatant_ClearStatus
.L08135114:
	adds r0, r4, #0
	bl Combatant_RestoreHp
	adds r0, r4, #0
	bl Combatant_RestoreMp
	b .L08135170
	.byte 0x00, 0x00
.L08135124: .4byte 0x00007FFF
.L08135128:
	ldr r1, .L08135138
	adds r0, r4, #0
	bl Combatant_ClearStatus
	adds r0, r4, #0
	bl sub_081360D4
	b .L08135170
.L08135138: .4byte 0x0000F3FE
.L0813513C:
	adds r0, r4, #0
	bl Combatant_GetStatus
	ldr r2, .L08135178
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	beq .L0813515C
	ldr r1, .L0813517C
	eors r1, r2
	adds r0, r4, #0
	bl Combatant_ClearStatus
	adds r0, r4, #0
	bl sub_081360D4
.L0813515C:
	adds r0, r4, #0
	movs r1, #0
	bl Combatant_ClearStatus
	adds r0, r4, #0
	bl Combatant_RestoreHp
	adds r0, r4, #0
	bl Combatant_RestoreMp
.L08135170:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08135178: .4byte 0x00000C01
.L0813517C: .4byte 0x0000FFFF

	thumb_func_start sub_08135180
sub_08135180: @ 0x08135180
.L08135180:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r5, #0
	bl sub_0812DBF0
	adds r7, r0, #0
	bl Stock_GetCapacity
	cmp r4, #0
	bne .L081351E8
	movs r4, #4
	adds r6, r0, #4
	cmp r4, r6
	bge .L081351D4
	ldr r0, .L081351E0
	mov r8, r0
.L081351A6:
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L081351CA
	adds r0, r4, #0
	bl Combatant_GetStatus
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne .L081351CA
	lsls r0, r5, #1
	adds r0, r0, r7
	strh r4, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L081351CA:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r6
	blt .L081351A6
.L081351D4:
	lsls r0, r5, #1
	adds r0, r0, r7
	ldr r2, .L081351E4
	adds r1, r2, #0
	strh r1, [r0]
	b .L081351F2
.L081351E0: .4byte 0x0000B160
.L081351E4: .4byte 0x0000FFFF
.L081351E8:
	cmp r4, #1
	bne .L081351F2
	ldr r1, .L081351FC
	adds r0, r1, #0
	strh r0, [r7]
.L081351F2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L081351FC: .4byte 0x0000FFFF

	thumb_func_start sub_08135200
sub_08135200: @ 0x08135200
.L08135200:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_08134DE0
	adds r6, r0, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	adds r0, r4, #0
	bl sub_08134DC8
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r4, #0
	bl sub_08134E10
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r4, #0
	bl sub_08134DF8
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	lsls r5, r5, #0x10
	asrs r0, r5, #0x10
	cmp r6, r0
	bge .L08135244
	movs r5, #0
	b .L0813524A
.L08135244:
	subs r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0813524A:
	lsls r0, r7, #0x10
	asrs r1, r0, #0x10
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bge .L0813525A
	movs r3, #0
	b .L08135260
.L0813525A:
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L08135260:
	ldr r0, .L08135284
	ldrh r0, [r0]
	movs r1, #3
	ands r1, r0
	ldr r0, .L08135288
	lsls r1, r1, #1
	adds r0, r1, r0
	ldrh r0, [r0]
	muls r0, r5, r0
	ldr r2, .L0813528C
	adds r1, r1, r2
	ldrh r1, [r1]
	muls r1, r3, r1
	adds r0, r0, r1
	lsrs r0, r0, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L08135284: .4byte 0x0203DB72 @ EWRAM+0x3DB72
.L08135288: .4byte gUnknown_087903B8
.L0813528C: .4byte gUnknown_087903BE

	thumb_func_start sub_08135290
sub_08135290: @ 0x08135290
.L08135290:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	movs r7, #0
	movs r5, #0
	movs r0, #0x80
	lsls r0, r0, #8
	mov sb, r0
.L081352AC:
	adds r0, r6, #0
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq .L081352CC
	ldr r1, .L081352F0
	lsls r0, r5, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	mov r0, r8
	bl Combatant_GetLevel
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r4, r0
	adds r7, r7, r0
.L081352CC:
	lsls r0, r6, #0x11
	lsrs r6, r0, #0x10
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xf
	bls .L081352AC
	ldr r0, .L081352F4
	cmp r7, r0
	bls .L081352E2
	adds r7, r0, #0
.L081352E2:
	adds r0, r7, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L081352F0: .4byte gUnknown_087903C4
.L081352F4: .4byte 0x0001869F

	thumb_func_start sub_081352F8
sub_081352F8: @ 0x081352F8
.L081352F8:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Combatant_GetStatus
	adds r1, r0, #0
	lsls r1, r1, #0x10
	ldr r0, .L0813531C
	ands r0, r1
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl sub_08135290
	pop {r4}
	pop {r1}
	bx r1
.L0813531C: .4byte 0x33FE0000

	thumb_func_start sub_08135320
sub_08135320: @ 0x08135320
.L08135320:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl sub_08135290
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_08135348
sub_08135348: @ 0x08135348
.L08135348:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Combatant_GetStatus
	adds r1, r0, #0
	lsls r1, r1, #0x10
	ldr r0, .L0813536C
	ands r0, r1
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl sub_08135290
	pop {r4}
	pop {r1}
	bx r1
.L0813536C: .4byte 0x0C010000

	thumb_func_start sub_08135370
sub_08135370: @ 0x08135370
.L08135370:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r6, #0
	bl sub_0812DBF0
	mov r8, r0
	bl sub_0812DC00
	mov sb, r0
	bl Stock_GetCapacity
	adds r7, r0, #0
	movs r5, #0
	adds r0, r7, #4
	cmp r6, r0
	bge .L081353EE
.L08135394:
	adds r0, r5, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L081353E2
	adds r0, r5, #0
	bl sub_08134DE0
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_08134DC8
	lsls r4, r4, #0x10
	lsls r0, r0, #0x10
	cmp r4, r0
	bgt .L081353CA
	adds r0, r5, #0
	bl sub_08134E10
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_08134DF8
	lsls r4, r4, #0x10
	lsls r0, r0, #0x10
	cmp r4, r0
	ble .L081353E2
.L081353CA:
	lsls r0, r6, #1
	add r0, r8
	strh r5, [r0]
	adds r0, r5, #0
	bl sub_08135200
	lsls r1, r6, #2
	add r1, sb
	str r0, [r1]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L081353E2:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r7, #4
	cmp r5, r0
	blt .L08135394
.L081353EE:
	lsls r0, r6, #1
	add r0, r8
	ldr r2, .L0813540C
	adds r1, r2, #0
	strh r1, [r0]
	lsls r0, r6, #2
	add r0, sb
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [r0]
	cmp r6, #0
	beq .L08135410
	movs r0, #0
	b .L08135412
	.byte 0x00, 0x00
.L0813540C: .4byte 0x0000FFFF
.L08135410:
	movs r0, #1
.L08135412:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08135420
sub_08135420: @ 0x08135420
.L08135420:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r5, #0
	bl sub_0812DBF0
	adds r7, r0, #0
	bl sub_0812DC00
	mov r8, r0
	bl Stock_GetCapacity
	adds r6, r0, #0
	movs r4, #0
	adds r0, r6, #4
	cmp r5, r0
	bge .L08135480
.L08135442:
	adds r0, r4, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L08135474
	adds r0, r4, #0
	bl Combatant_GetStatus
	ldr r2, .L0813549C
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	beq .L08135474
	lsls r0, r5, #1
	adds r0, r0, r7
	strh r4, [r0]
	adds r0, r4, #0
	bl sub_081352F8
	lsls r1, r5, #2
	add r1, r8
	str r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L08135474:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r6, #4
	cmp r4, r0
	blt .L08135442
.L08135480:
	lsls r0, r5, #1
	adds r0, r0, r7
	ldr r2, .L081354A0
	adds r1, r2, #0
	strh r1, [r0]
	lsls r0, r5, #2
	add r0, r8
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [r0]
	cmp r5, #0
	beq .L081354A4
	movs r0, #0
	b .L081354A6
.L0813549C: .4byte 0x000033FE
.L081354A0: .4byte 0x0000FFFF
.L081354A4:
	movs r0, #1
.L081354A6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_081354B0
sub_081354B0: @ 0x081354B0
.L081354B0:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r5, #0
	bl sub_0812DBF0
	adds r7, r0, #0
	bl sub_0812DC00
	mov r8, r0
	bl Stock_GetCapacity
	adds r6, r0, #0
	movs r4, #0
	adds r0, r6, #4
	cmp r5, r0
	bge .L08135512
.L081354D2:
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135506
	adds r0, r4, #0
	bl Combatant_GetStatus
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L08135506
	lsls r0, r5, #1
	adds r0, r0, r7
	strh r4, [r0]
	adds r0, r4, #0
	bl sub_08135320
	lsls r1, r5, #2
	add r1, r8
	str r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L08135506:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r6, #4
	cmp r4, r0
	blt .L081354D2
.L08135512:
	lsls r0, r5, #1
	adds r0, r0, r7
	ldr r2, .L08135530
	adds r1, r2, #0
	strh r1, [r0]
	lsls r0, r5, #2
	add r0, r8
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [r0]
	cmp r5, #0
	beq .L08135534
	movs r0, #0
	b .L08135536
	.byte 0x00, 0x00
.L08135530: .4byte 0x0000FFFF
.L08135534:
	movs r0, #1
.L08135536:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_08135540
sub_08135540: @ 0x08135540
.L08135540:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r5, #0
	bl sub_0812DBF0
	adds r7, r0, #0
	bl sub_0812DC00
	mov r8, r0
	bl Stock_GetCapacity
	adds r6, r0, #0
	movs r4, #0
	adds r0, r6, #4
	cmp r5, r0
	bge .L081355A0
.L08135562:
	adds r0, r4, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L08135594
	adds r0, r4, #0
	bl Combatant_GetStatus
	ldr r2, .L081355BC
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	beq .L08135594
	lsls r0, r5, #1
	adds r0, r0, r7
	strh r4, [r0]
	adds r0, r4, #0
	bl sub_08135348
	lsls r1, r5, #2
	add r1, r8
	str r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L08135594:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r6, #4
	cmp r4, r0
	blt .L08135562
.L081355A0:
	lsls r0, r5, #1
	adds r0, r0, r7
	ldr r2, .L081355C0
	adds r1, r2, #0
	strh r1, [r0]
	lsls r0, r5, #2
	add r0, r8
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [r0]
	cmp r5, #0
	beq .L081355C4
	movs r0, #0
	b .L081355C6
.L081355BC: .4byte 0x00000C01
.L081355C0: .4byte 0x0000FFFF
.L081355C4:
	movs r0, #1
.L081355C6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_081355D0
sub_081355D0: @ 0x081355D0
.L081355D0:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_08135200
	adds r5, r0, #0
	adds r0, r4, #0
	bl sub_081352F8
	mov r8, r0
	adds r0, r4, #0
	bl sub_08135320
	adds r6, r0, #0
	adds r0, r4, #0
	bl sub_08135348
	add r5, r8
	adds r5, r5, r6
	adds r5, r5, r0
	adds r0, r5, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_0813560C
sub_0813560C: @ 0x0813560C
.L0813560C:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r6, #0
	bl sub_0812DBF0
	mov r8, r0
	bl sub_0812DC00
	mov sb, r0
	bl Stock_GetCapacity
	adds r7, r0, #0
	movs r5, #0
	adds r0, r7, #4
	cmp r6, r0
	bge .L08135696
.L08135630:
	adds r0, r5, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813568A
	adds r0, r5, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08135672
	adds r0, r5, #0
	bl sub_08134DE0
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_08134DC8
	lsls r4, r4, #0x10
	lsls r0, r0, #0x10
	cmp r4, r0
	bgt .L08135672
	adds r0, r5, #0
	bl sub_08134E10
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_08134DF8
	lsls r4, r4, #0x10
	lsls r0, r0, #0x10
	cmp r4, r0
	ble .L0813568A
.L08135672:
	lsls r0, r6, #1
	add r0, r8
	strh r5, [r0]
	adds r0, r5, #0
	bl sub_081355D0
	lsls r1, r6, #2
	add r1, sb
	str r0, [r1]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0813568A:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r7, #4
	cmp r5, r0
	blt .L08135630
.L08135696:
	lsls r0, r6, #1
	add r0, r8
	ldr r2, .L081356B4
	adds r1, r2, #0
	strh r1, [r0]
	lsls r0, r6, #2
	add r0, sb
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [r0]
	cmp r6, #0
	beq .L081356B8
	movs r0, #0
	b .L081356BA
	.byte 0x00, 0x00
.L081356B4: .4byte 0x0000FFFF
.L081356B8:
	movs r0, #1
.L081356BA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_360
ScriptOp_360: @ 0x081356C8
	push {r4, lr}
	ldr r3, .L0813570C
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08135710
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r4, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	orrs r0, r4
	ldr r1, .L08135714
	str r0, [r1]
	ldr r0, .L08135718
	movs r4, #1
	strh r4, [r0]
	bl sub_0812DC24
	ldr r1, .L0813571C
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, .L08135720
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
.L0813570C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08135710: .4byte 0x03006950 @ IWRAM+0x6950
.L08135714: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08135718: .4byte 0x0300668C @ IWRAM+0x668C
.L0813571C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135720: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_361
ScriptOp_361: @ 0x08135724
	push {r4, lr}
	ldr r3, .L0813576C
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08135770
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r4, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	orrs r0, r4
	ldr r1, .L08135774
	str r0, [r1]
	ldr r1, .L08135778
	movs r0, #2
	strh r0, [r1]
	bl sub_0812DC24
	ldr r1, .L0813577C
	movs r0, #0x1e
	strh r0, [r1]
	ldr r1, .L08135780
	movs r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813576C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08135770: .4byte 0x03006950 @ IWRAM+0x6950
.L08135774: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08135778: .4byte 0x0300668C @ IWRAM+0x668C
.L0813577C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135780: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_362
ScriptOp_362: @ 0x08135784
	push {r4, r5, lr}
	ldr r3, .L08135808
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813580C
	ldr r4, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r5, [r0]
	adds r2, r1, #1
	strh r2, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	orrs r0, r5
	ldr r5, .L08135810
	str r0, [r5]
	adds r0, r2, #1
	strh r0, [r3]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xf
	adds r2, r2, r4
	ldrh r2, [r2]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	orrs r0, r2
	str r0, [r5, #4]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r2, [r1]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	orrs r0, r2
	str r0, [r5, #8]
	ldr r1, .L08135814
	movs r0, #3
	strh r0, [r1]
	bl sub_0812DC24
	ldr r1, .L08135818
	movs r0, #0x1e
	strh r0, [r1]
	ldr r1, .L0813581C
	movs r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08135808: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813580C: .4byte 0x03006950 @ IWRAM+0x6950
.L08135810: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08135814: .4byte 0x0300668C @ IWRAM+0x668C
.L08135818: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813581C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_363
ScriptOp_363: @ 0x08135820
	push {r4, lr}
	ldr r3, .L08135868
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813586C
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r4, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	orrs r0, r4
	ldr r1, .L08135870
	str r0, [r1]
	ldr r1, .L08135874
	movs r0, #4
	strh r0, [r1]
	bl sub_0812DC24
	ldr r1, .L08135878
	movs r0, #0x1e
	strh r0, [r1]
	ldr r1, .L0813587C
	movs r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08135868: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813586C: .4byte 0x03006950 @ IWRAM+0x6950
.L08135870: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08135874: .4byte 0x0300668C @ IWRAM+0x668C
.L08135878: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813587C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_364
ScriptOp_364: @ 0x08135880
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_365
ScriptOp_365: @ 0x08135884
	ldr r1, .L08135890
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08135890: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_370_371
ScriptOp_370_371: @ 0x08135894
	ldr r1, .L081358A0
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L081358A0: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_366
ScriptOp_366: @ 0x081358A4
	push {r4, r5, r6, lr}
	ldr r3, .L081358F4
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L081358F8
	ldr r4, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r2, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r5, [r1]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	lsls r6, r0, #0x10
	orrs r6, r5
	ldr r0, .L081358FC
	lsls r2, r2, #1
	adds r2, r2, r0
	ldrh r4, [r2]
	movs r0, #0
	bl Combatant_GetStatus
	ands r4, r0
	cmp r4, #0
	beq .L081358EE
	ldr r0, .L08135900
	str r6, [r0]
.L081358EE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L081358F4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081358F8: .4byte 0x03006950 @ IWRAM+0x6950
.L081358FC: .4byte gUnknown_08790398
.L08135900: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_367
ScriptOp_367: @ 0x08135904
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_368
ScriptOp_368: @ 0x08135908
	push {r4, lr}
	ldr r4, .L0813592C
	ldr r3, .L08135930
	ldr r2, .L08135934
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08135938
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r3]
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
.L0813592C: .4byte 0x0203DB74 @ EWRAM+0x3DB74
.L08135930: .4byte 0x0203DB72 @ EWRAM+0x3DB72
.L08135934: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08135938: .4byte 0x03006950 @ IWRAM+0x6950

	thumb_func_start ScriptOp_369
ScriptOp_369: @ 0x0813593C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_36B
ScriptOp_36B: @ 0x08135940
	push {r4, lr}
	sub sp, #4
	ldr r4, .L08135984
	ldrh r0, [r4]
	adds r3, r0, #1
	strh r3, [r4]
	lsls r0, r0, #0x10
	ldr r1, .L08135988
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r2, [r0]
	adds r3, #1
	strh r3, [r4]
	lsrs r1, r2, #8
	movs r0, #0xff
	ands r2, r0
	ldr r3, .L0813598C
	movs r0, #0x14
	strh r0, [r3]
	movs r0, #0
	str r0, [sp]
	movs r3, #0
	bl Warp_ToWorldPosition
	ldr r1, .L08135990
	str r0, [r1]
	ldr r1, .L08135994
	movs r0, #1
	strh r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L08135984: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08135988: .4byte 0x03006950 @ IWRAM+0x6950
.L0813598C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135990: .4byte 0x03006954 @ IWRAM+0x6954
.L08135994: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_36C
ScriptOp_36C: @ 0x08135998
	push {r4, lr}
	sub sp, #4
	ldr r4, .L081359D0
	ldrh r0, [r4]
	adds r3, r0, #1
	strh r3, [r4]
	lsls r0, r0, #0x10
	ldr r1, .L081359D4
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r2, [r0]
	adds r3, #1
	strh r3, [r4]
	lsrs r1, r2, #8
	movs r0, #0xff
	ands r2, r0
	movs r0, #0
	str r0, [sp]
	movs r3, #0
	bl Warp_ToWorldPosition
	ldr r1, .L081359D8
	str r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L081359D0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081359D4: .4byte 0x03006950 @ IWRAM+0x6950
.L081359D8: .4byte 0x03006954 @ IWRAM+0x6954

	thumb_func_start ScriptOp_36D
ScriptOp_36D: @ 0x081359DC
	push {r4, lr}
	ldr r2, .L08135A08
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08135A0C
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r2, r1, #0
	ldr r4, .L08135A10
	movs r0, #0x32
	strh r0, [r4]
	cmp r1, #1
	beq .L08135A4A
	cmp r1, #1
	bgt .L08135A14
	cmp r1, #0
	beq .L08135A1E
	b .L08135A7A
.L08135A08: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08135A0C: .4byte 0x03006950 @ IWRAM+0x6950
.L08135A10: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135A14:
	cmp r2, #2
	beq .L08135A1E
	cmp r2, #3
	beq .L08135A6A
	b .L08135A7A
.L08135A1E:
	ldr r0, .L08135A38
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L08135A3C
	bl BgPicture_LoadPalette
	bl sub_080B0778
	b .L08135A7A
	.byte 0x00, 0x00
.L08135A38: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L08135A3C:
	bl sub_080B78A4
	cmp r0, #0
	bne .L08135A7A
	bl sub_080B05A4
	b .L08135A7A
.L08135A4A:
	ldr r0, .L08135A60
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L08135A64
	bl sub_080B0820
	b .L08135A7A
	.byte 0x00, 0x00
.L08135A60: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L08135A64:
	bl sub_080B0620
	b .L08135A7A
.L08135A6A:
	ldr r0, .L08135A88
	movs r1, #1
	bl sub_080B8AE0
	ldr r1, .L08135A8C
	str r0, [r1]
	movs r0, #0x33
	strh r0, [r4]
.L08135A7A:
	ldr r1, .L08135A90
	movs r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08135A88: .4byte 0x0000FFFF
.L08135A8C: .4byte 0x03006964 @ IWRAM+0x6964
.L08135A90: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start sub_08135A94
sub_08135A94: @ 0x08135A94
.L08135A94:
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_08157238
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_36F
ScriptOp_36F: @ 0x08135AA8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl Stock_GetCapacity
	mov r8, r0
	ldr r3, .L08135B40
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08135B44
	ldr r4, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	adds r2, r1, #1
	strh r2, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r5, [r1]
	lsls r5, r5, #0x10
	orrs r5, r0
	adds r0, r2, #1
	strh r0, [r3]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xf
	adds r2, r2, r4
	ldrh r2, [r2]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r6, [r0]
	lsls r6, r6, #0x10
	orrs r6, r2
	movs r7, #0
	movs r4, #4
	mov r0, r8
	adds r0, #4
	cmp r4, r0
	bge .L08135B32
	ldr r0, .L08135B48
	mov sb, r0
.L08135B06:
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135B24
	adds r0, r4, #0
	bl Combatant_GetStatus
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	bne .L08135B24
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08135B24:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r0, r8
	adds r0, #4
	cmp r4, r0
	blt .L08135B06
.L08135B32:
	ldr r0, .L08135B4C
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08135B50
	movs r0, #3
	b .L08135B70
	.byte 0x00, 0x00
.L08135B40: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08135B44: .4byte 0x03006950 @ IWRAM+0x6950
.L08135B48: .4byte 0x0000B160
.L08135B4C: .4byte 0x030068A8 @ IWRAM+0x68A8
.L08135B50:
	cmp r0, #4
	bne .L08135B66
	cmp r7, #0
	beq .L08135B8C
	movs r0, #2
	bl sub_08135A94
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08135B90
	b .L08135B7C
.L08135B66:
	cmp r0, #5
	bne .L08135B88
	cmp r7, #0
	beq .L08135B8C
	movs r0, #4
.L08135B70:
	bl sub_08135A94
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L08135B90
.L08135B7C:
	ldr r0, .L08135B84
	str r6, [r0]
	b .L08135B90
	.byte 0x00, 0x00
.L08135B84: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08135B88:
	cmp r7, r0
	bhs .L08135B90
.L08135B8C:
	ldr r0, .L08135B9C
	str r5, [r0]
.L08135B90:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08135B9C: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_372
ScriptOp_372: @ 0x08135BA0
	push {r4, r5, r6, lr}
	ldr r3, .L08135BD4
	ldrh r0, [r3]
	adds r2, r0, #1
	strh r2, [r3]
	lsls r0, r0, #0x10
	ldr r1, .L08135BD8
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r4, [r0]
	adds r2, #1
	strh r2, [r3]
	cmp r4, #0
	bne .L08135BE8
	ldr r1, .L08135BDC
	movs r0, #0x14
	strh r0, [r1]
	movs r0, #1
	bl sub_080B7E0C
	ldr r1, .L08135BE0
	str r0, [r1]
	ldr r1, .L08135BE4
	movs r0, #1
	b .L08135DFA
.L08135BD4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08135BD8: .4byte 0x03006950 @ IWRAM+0x6950
.L08135BDC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135BE0: .4byte 0x03006954 @ IWRAM+0x6954
.L08135BE4: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08135BE8:
	cmp r4, #1
	bne .L08135C10
	ldr r1, .L08135C04
	movs r0, #0x14
	strh r0, [r1]
	movs r0, #0
	bl sub_080B7E0C
	ldr r1, .L08135C08
	str r0, [r1]
	ldr r0, .L08135C0C
	strh r4, [r0]
	b .L08135DFC
	.byte 0x00, 0x00
.L08135C04: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135C08: .4byte 0x03006954 @ IWRAM+0x6954
.L08135C0C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08135C10:
	cmp r4, #9
	bne .L08135C2C
	bl sub_080B08AC
	ldr r1, .L08135C24
	movs r0, #0x44
	strh r0, [r1]
	ldr r1, .L08135C28
	movs r0, #1
	b .L08135DFA
.L08135C24: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135C28: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08135C2C:
	cmp r4, #0xa
	bne .L08135C48
	bl sub_080B0888
	ldr r1, .L08135C40
	movs r0, #0x45
	strh r0, [r1]
	ldr r1, .L08135C44
	movs r0, #1
	b .L08135DFA
.L08135C40: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135C44: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08135C48:
	cmp r4, #0xb
	bne .L08135C6C
	bl sub_080B9510
	ldr r1, .L08135C60
	str r0, [r1]
	ldr r1, .L08135C64
	movs r0, #0x46
	strh r0, [r1]
	ldr r1, .L08135C68
	movs r0, #1
	b .L08135DFA
.L08135C60: .4byte 0x03006954 @ IWRAM+0x6954
.L08135C64: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135C68: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08135C6C:
	cmp r4, #0xc
	bne .L08135CBC
	ldr r0, .L08135CA0
	ldrh r1, [r0]
	ldr r3, .L08135CA4
	ldr r0, .L08135CA8
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r2, .L08135CAC
	movs r4, #0
	ldrsh r2, [r2, r4]
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r0, #2
	bl sub_080D3400
	ldr r1, .L08135CB0
	str r0, [r1]
	ldr r1, .L08135CB4
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08135CB8
	movs r0, #1
	b .L08135DFA
.L08135CA0: .4byte 0x03006898 @ IWRAM+0x6898
.L08135CA4: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08135CA8: .4byte 0x0300696C @ IWRAM+0x696C
.L08135CAC: .4byte 0x03006940 @ IWRAM+0x6940
.L08135CB0: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08135CB4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135CB8: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08135CBC:
	cmp r4, #0xd
	bne .L08135CEC
	ldr r5, .L08135CE0
	ldr r4, [r5]
	cmp r4, #0
	beq .L08135CCA
	b .L08135DFC
.L08135CCA:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080D3400
	str r0, [r5]
	ldr r0, .L08135CE4
	strh r4, [r0]
	ldr r1, .L08135CE8
	movs r0, #1
	b .L08135DFA
.L08135CE0: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08135CE4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135CE8: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08135CEC:
	cmp r4, #0xe
	bne .L08135D18
	ldr r4, .L08135D0C
	ldr r0, [r4]
	cmp r0, #0
	beq .L08135D00
	bl sub_080D34F0
	movs r0, #0
	str r0, [r4]
.L08135D00:
	ldr r1, .L08135D10
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08135D14
	movs r0, #1
	b .L08135DFA
.L08135D0C: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08135D10: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08135D14: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08135D18:
	cmp r4, #0xf
	bne .L08135D68
	ldr r4, .L08135D38
	ldrh r0, [r4]
	bl sub_080C4C7C
	adds r6, r0, #0
	adds r5, r6, #0
	ldrh r0, [r4]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r6, r0, r6
	adds r6, r6, r5
	b .L08135D42
.L08135D38: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08135D3C:
	ldrh r0, [r4]
	bl sub_080C33AC
.L08135D42:
	ldrh r0, [r4]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08135D3C
	ldr r0, .L08135D60
	ldrh r0, [r0]
	bl sub_080D2268
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L08135D64
	b .L08135DBA
	.byte 0x00, 0x00
.L08135D60: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08135D64: .4byte 0x03006898 @ IWRAM+0x6898
.L08135D68:
	cmp r4, #0x10
	bne .L08135DD8
	ldr r4, .L08135D8C
	ldrh r0, [r4]
	bl sub_080C4C7C
	adds r6, r0, #0
	adds r5, r6, #0
	ldrh r0, [r4]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r6, r0, r6
	adds r6, r6, r5
	adds r6, r6, r5
	b .L08135D96
	.byte 0x00, 0x00
.L08135D8C: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08135D90:
	ldrh r0, [r4]
	bl sub_080C33AC
.L08135D96:
	ldrh r0, [r4]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08135D90
	ldr r0, .L08135DCC
	ldrh r0, [r0]
	bl sub_080D2268
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L08135DD0
	ldrh r0, [r0]
	adds r1, r4, #0
	bl sub_080CDFF8
	ldr r0, .L08135DD4
.L08135DBA:
	ldrh r0, [r0]
	adds r1, r4, #0
	bl sub_080CDFF8
	adds r0, r6, #0
	bl sub_080C30AC
	b .L08135DFC
	.byte 0x00, 0x00
.L08135DCC: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08135DD0: .4byte 0x03006898 @ IWRAM+0x6898
.L08135DD4: .4byte 0x03006940 @ IWRAM+0x6940
.L08135DD8:
	cmp r4, #0x11
	bne .L08135DE8
	ldr r1, .L08135DE4
	movs r0, #0
	b .L08135DFA
	.byte 0x00, 0x00
.L08135DE4: .4byte 0x0300699C @ IWRAM+0x699C
.L08135DE8:
	cmp r4, #0x12
	bne .L08135DFC
	ldr r0, .L08135E04
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L08135E08
	strh r1, [r0]
	ldr r1, .L08135E0C
	movs r0, #0
.L08135DFA:
	strh r0, [r1]
.L08135DFC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08135E04: .4byte 0x03006958 @ IWRAM+0x6958
.L08135E08: .4byte 0x0300699C @ IWRAM+0x699C
.L08135E0C: .4byte 0x03006678 @ IWRAM+0x6678

	thumb_func_start ScriptOp_373
ScriptOp_373: @ 0x08135E10
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_374
ScriptOp_374: @ 0x08135E14
	push {r4, r5, lr}
	bl Stock_GetCapacity
	adds r3, r0, #0
	ldr r2, .L08135E54
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08135E58
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, #0
	cmp r0, #0
	bne .L08135E5C
	movs r0, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135EE0
	movs r0, #0
	bl Combatant_IsDead
	cmp r0, #0
	bne .L08135EE0
	movs r0, #0
	bl Combatant_RestoreHp
	b .L08135EE0
	.byte 0x00, 0x00
.L08135E54: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08135E58: .4byte 0x03006950 @ IWRAM+0x6950
.L08135E5C:
	cmp r0, #1
	beq .L08135E7E
	cmp r1, #2
	bne .L08135EB4
	movs r0, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135E7E
	movs r0, #0
	bl Combatant_IsDead
	cmp r0, #0
	bne .L08135E7E
	movs r0, #0
	bl Combatant_RestoreHp
.L08135E7E:
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135E98
	movs r0, #1
	bl Combatant_IsDead
	cmp r0, #0
	bne .L08135E98
	movs r0, #1
	bl Combatant_RestoreHp
.L08135E98:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135EE0
	movs r0, #2
	bl Combatant_IsDead
	cmp r0, #0
	bne .L08135EE0
	movs r0, #2
	bl Combatant_RestoreHp
	b .L08135EE0
.L08135EB4:
	movs r4, #0
	adds r5, r3, #4
	cmp r4, r5
	bge .L08135EE0
.L08135EBC:
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135ED6
	adds r0, r4, #0
	bl Combatant_IsDead
	cmp r0, #0
	bne .L08135ED6
	adds r0, r4, #0
	bl Combatant_RestoreHp
.L08135ED6:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	blt .L08135EBC
.L08135EE0:
	bl sub_080C84A0
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_375
ScriptOp_375: @ 0x08135EEC
	push {r4, r5, lr}
	bl Stock_GetCapacity
	adds r3, r0, #0
	ldr r2, .L08135F2C
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08135F30
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, #0
	cmp r0, #0
	bne .L08135F34
	movs r0, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135FB8
	movs r0, #0
	bl Combatant_IsDead
	cmp r0, #0
	bne .L08135FB8
	movs r0, #0
	bl Combatant_RestoreMp
	b .L08135FB8
	.byte 0x00, 0x00
.L08135F2C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08135F30: .4byte 0x03006950 @ IWRAM+0x6950
.L08135F34:
	cmp r0, #1
	beq .L08135F56
	cmp r1, #2
	bne .L08135F8C
	movs r0, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135F56
	movs r0, #0
	bl Combatant_IsDead
	cmp r0, #0
	bne .L08135F56
	movs r0, #0
	bl Combatant_RestoreMp
.L08135F56:
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135F70
	movs r0, #1
	bl Combatant_IsDead
	cmp r0, #0
	bne .L08135F70
	movs r0, #1
	bl Combatant_RestoreMp
.L08135F70:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135FB8
	movs r0, #2
	bl Combatant_IsDead
	cmp r0, #0
	bne .L08135FB8
	movs r0, #2
	bl Combatant_RestoreMp
	b .L08135FB8
.L08135F8C:
	movs r4, #0
	adds r5, r3, #4
	cmp r4, r5
	bge .L08135FB8
.L08135F94:
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08135FAE
	adds r0, r4, #0
	bl Combatant_IsDead
	cmp r0, #0
	bne .L08135FAE
	adds r0, r4, #0
	bl Combatant_RestoreMp
.L08135FAE:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	blt .L08135F94
.L08135FB8:
	bl sub_080C84A0
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08135FC4
sub_08135FC4: @ 0x08135FC4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0
	bl Combatant_GetEquip
	adds r1, r0, #0
	cmp r1, #0xff
	beq .L08135FF2
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L08135FF2
	adds r0, r1, #0
	movs r1, #6
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L081360C4
.L08135FF2:
	adds r0, r4, #0
	movs r1, #1
	bl Combatant_GetEquip
	adds r1, r0, #0
	cmp r1, #0xff
	beq .L0813601C
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0813601C
	adds r0, r1, #0
	movs r1, #6
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L081360C4
.L0813601C:
	adds r0, r4, #0
	movs r1, #2
	bl Combatant_GetEquip
	adds r1, r0, #0
	cmp r1, #0xff
	beq .L08136046
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L08136046
	adds r0, r1, #0
	movs r1, #6
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L081360C4
.L08136046:
	adds r0, r4, #0
	movs r1, #3
	bl Combatant_GetEquip
	adds r1, r0, #0
	cmp r1, #0xff
	beq .L08136070
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L08136070
	adds r0, r1, #0
	movs r1, #6
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L081360C4
.L08136070:
	adds r0, r4, #0
	movs r1, #4
	bl Combatant_GetEquip
	adds r1, r0, #0
	cmp r1, #0xff
	beq .L0813609A
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0813609A
	adds r0, r1, #0
	movs r1, #6
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L081360C4
.L0813609A:
	adds r0, r4, #0
	movs r1, #5
	bl Combatant_GetEquip
	adds r1, r0, #0
	cmp r1, #0xff
	beq .L081360C8
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L081360C8
	adds r0, r1, #0
	movs r1, #6
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L081360C8
.L081360C4:
	movs r0, #1
	b .L081360CA
.L081360C8:
	movs r0, #0
.L081360CA:
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_081360D4
sub_081360D4: @ 0x081360D4
.L081360D4:
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0
	bl Combatant_GetEquip
	adds r1, r0, #0
	cmp r1, #0xff
	beq .L0813610C
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0813610C
	adds r0, r1, #0
	movs r1, #6
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L0813610C
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080CDFF8
.L0813610C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_08136114
sub_08136114: @ 0x08136114
.L08136114:
	push {r4, lr}
	sub sp, #4
	movs r0, #1
	movs r1, #0
	bl Combatant_GetEquip
	adds r4, r0, #0
	cmp r4, #0xff
	beq .L08136152
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L08136152
	adds r0, r4, #0
	movs r1, #6
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L08136152
	movs r0, #1
	movs r1, #0
	bl sub_080CDFF8
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C3328
.L08136152:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_376
ScriptOp_376: @ 0x0813615C
	push {r4, r5, lr}
	bl Stock_GetCapacity
	adds r3, r0, #0
	ldr r2, .L0813618C
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08136190
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, #0
	cmp r0, #0
	bne .L08136194
	movs r0, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L081361F8
	movs r0, #0
	b .L081361CC
.L0813618C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08136190: .4byte 0x03006950 @ IWRAM+0x6950
.L08136194:
	cmp r0, #1
	beq .L081361AE
	cmp r1, #2
	bne .L081361D4
	movs r0, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L081361AE
	movs r0, #0
	movs r1, #1
	bl Combatant_ClearStatus
.L081361AE:
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L081361C0
	movs r0, #1
	movs r1, #1
	bl Combatant_ClearStatus
.L081361C0:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L081361F8
	movs r0, #2
.L081361CC:
	movs r1, #1
	bl Combatant_ClearStatus
	b .L081361F8
.L081361D4:
	movs r4, #0
	adds r5, r3, #4
	cmp r4, r5
	bge .L081361F8
.L081361DC:
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L081361EE
	adds r0, r4, #0
	movs r1, #1
	bl Combatant_ClearStatus
.L081361EE:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	blt .L081361DC
.L081361F8:
	bl sub_080C84A0
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08136204
sub_08136204: @ 0x08136204
.L08136204:
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r4, r2, #0
	movs r5, #0
	ldr r1, .L0813622C
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	adds r2, #0x28
	cmp r6, #5
	bhi .L08136266
	lsls r0, r6, #2
	ldr r1, .L08136230
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L0813622C: .4byte 0xFFFF8000
.L08136230: .4byte gUnknown_08136234
	.global gUnknown_08136234
gUnknown_08136234:
.L08136234: @ jump table
	.4byte .L0813624C
	.4byte .L08136250
	.4byte .L08136254
	.4byte .L08136258
	.4byte .L0813625C
	.4byte .L08136260
.L0813624C:
	strb r4, [r2]
	b .L08136262
.L08136250:
	strb r4, [r2, #1]
	b .L08136262
.L08136254:
	strb r4, [r2, #2]
	b .L08136262
.L08136258:
	strb r4, [r2, #3]
	b .L08136262
.L0813625C:
	strb r4, [r2, #4]
	b .L08136262
.L08136260:
	strb r4, [r2, #5]
.L08136262:
	lsls r0, r4, #0x18
	asrs r5, r0, #0x18
.L08136266:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08136270
sub_08136270: @ 0x08136270
.L08136270:
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r4, r2, #0
	movs r5, #0
	ldr r1, .L08136298
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	adds r2, #0x38
	cmp r6, #5
	bhi .L081362D2
	lsls r0, r6, #2
	ldr r1, .L0813629C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L08136298: .4byte 0xFFFF8000
.L0813629C: .4byte gUnknown_081362A0
	.global gUnknown_081362A0
gUnknown_081362A0:
.L081362A0: @ jump table
	.4byte .L081362B8
	.4byte .L081362BC
	.4byte .L081362C0
	.4byte .L081362C4
	.4byte .L081362C8
	.4byte .L081362CC
.L081362B8:
	strb r4, [r2]
	b .L081362CE
.L081362BC:
	strb r4, [r2, #1]
	b .L081362CE
.L081362C0:
	strb r4, [r2, #2]
	b .L081362CE
.L081362C4:
	strb r4, [r2, #3]
	b .L081362CE
.L081362C8:
	strb r4, [r2, #4]
	b .L081362CE
.L081362CC:
	strb r4, [r2, #5]
.L081362CE:
	lsls r0, r4, #0x18
	asrs r5, r0, #0x18
.L081362D2:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_081362DC
sub_081362DC: @ 0x081362DC
.L081362DC:
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L08136418
	bl Battle_GetCombatant
	ldr r0, .L0813641C
	bl Battle_GetCombatant
	cmp r4, #0
	beq .L081362F2
	b .L0813642C
.L081362F2:
	movs r0, #1
	movs r1, #0x12
	bl Combatant_SetLevel
	ldr r1, .L08136420
	movs r0, #1
	bl sub_080C0F70
	movs r0, #1
	movs r1, #0
	movs r2, #6
	bl Combatant_SetEquip
	movs r0, #1
	movs r1, #1
	movs r2, #0x58
	bl Combatant_SetEquip
	movs r0, #1
	movs r1, #6
	movs r2, #0x70
	bl Combatant_SetEquip
	movs r0, #1
	movs r1, #2
	movs r2, #0x81
	bl Combatant_SetEquip
	movs r0, #1
	movs r1, #3
	movs r2, #0x96
	bl Combatant_SetEquip
	movs r0, #1
	movs r1, #4
	movs r2, #0xaa
	bl Combatant_SetEquip
	movs r0, #1
	movs r1, #5
	movs r2, #0xbf
	bl Combatant_SetEquip
	bl Random_Byte
	movs r1, #3
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r5, r1, #1
	ldr r4, .L08136424
	adds r0, r5, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #1
	movs r1, #0
	bl sub_08136204
	adds r0, r5, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #1
	movs r1, #1
	bl sub_08136204
	adds r0, r5, #2
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #1
	movs r1, #2
	bl sub_08136204
	adds r0, r5, #3
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #1
	movs r1, #3
	bl sub_08136204
	adds r0, r5, #4
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #1
	movs r1, #4
	bl sub_08136204
	adds r0, r5, #5
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #1
	movs r1, #5
	bl sub_08136204
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_08136270
	movs r0, #1
	movs r1, #1
	movs r2, #0
	bl sub_08136270
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl sub_08136270
	movs r0, #1
	movs r1, #3
	movs r2, #0
	bl sub_08136270
	movs r0, #1
	movs r1, #4
	movs r2, #0
	bl sub_08136270
	movs r0, #1
	movs r1, #5
	movs r2, #0
	bl sub_08136270
	movs r0, #1
	bl Combatant_RecalcStats
	bl sub_080CDC34
	ldr r2, .L08136428
	adds r0, r2, #0
	adds r0, #0x9a
	ldrh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r0, #6
	ldrh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	movs r0, #1
	bl sub_080F4260
	b .L081365BE
.L08136418: .4byte 0x00008002
.L0813641C: .4byte 0x00008001
.L08136420: .4byte 0x000025DA
.L08136424: .4byte gUnknown_087903EE
.L08136428: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813642C:
	cmp r4, #1
	beq .L08136432
	b .L08136578
.L08136432:
	movs r0, #2
	movs r1, #0x18
	bl Combatant_SetLevel
	ldr r1, .L0813656C
	movs r0, #2
	bl sub_080C0F70
	movs r0, #2
	movs r1, #0
	movs r2, #2
	bl Combatant_SetEquip
	movs r0, #2
	movs r1, #1
	movs r2, #0x58
	bl Combatant_SetEquip
	movs r0, #2
	movs r1, #6
	movs r2, #0x70
	bl Combatant_SetEquip
	movs r0, #2
	movs r1, #2
	movs r2, #0x82
	bl Combatant_SetEquip
	movs r0, #2
	movs r1, #3
	movs r2, #0x98
	bl Combatant_SetEquip
	movs r0, #2
	movs r1, #4
	movs r2, #0xac
	bl Combatant_SetEquip
	movs r0, #2
	movs r1, #5
	movs r2, #0xbf
	bl Combatant_SetEquip
	bl Random_Byte
	movs r1, #3
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x11
	movs r0, #0xc0
	lsls r0, r0, #0xd
	adds r1, r1, r0
	lsrs r5, r1, #0x10
	ldr r4, .L08136570
	adds r0, r5, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #2
	movs r1, #0
	bl sub_08136204
	adds r0, r5, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #2
	movs r1, #1
	bl sub_08136204
	adds r0, r5, #2
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #2
	movs r1, #2
	bl sub_08136204
	adds r0, r5, #3
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #2
	movs r1, #3
	bl sub_08136204
	adds r0, r5, #4
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #2
	movs r1, #4
	bl sub_08136204
	adds r0, r5, #5
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #2
	movs r1, #5
	bl sub_08136204
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl sub_08136270
	movs r0, #2
	movs r1, #1
	movs r2, #0
	bl sub_08136270
	movs r0, #2
	movs r1, #2
	movs r2, #0
	bl sub_08136270
	movs r0, #2
	movs r1, #3
	movs r2, #0
	bl sub_08136270
	movs r0, #2
	movs r1, #4
	movs r2, #0
	bl sub_08136270
	movs r0, #2
	movs r1, #5
	movs r2, #0
	bl sub_08136270
	movs r0, #2
	bl Combatant_RecalcStats
	bl sub_080CDC34
	ldr r2, .L08136574
	movs r1, #0x8d
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	movs r0, #2
	bl sub_080F4260
	b .L081365BE
.L0813656C: .4byte 0x000059D8
.L08136570: .4byte gUnknown_087903EE
.L08136574: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08136578:
	movs r0, #1
	bl Combatant_GetStatus
	ldr r2, .L081365C4
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	beq .L08136598
	ldr r1, .L081365C8
	eors r1, r2
	movs r0, #1
	bl Combatant_ClearStatus
	movs r0, #1
	bl sub_081360D4
.L08136598:
	movs r0, #1
	movs r1, #0
	bl Combatant_ClearStatus
	bl sub_08136114
	ldr r2, .L081365CC
	adds r0, r2, #0
	adds r0, #0x9a
	ldrh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r0, #6
	ldrh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	movs r0, #1
	bl sub_080F4260
.L081365BE:
	pop {r4, r5}
	pop {r0}
	bx r0
.L081365C4: .4byte 0x00000C01
.L081365C8: .4byte 0x0000FFFF
.L081365CC: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start ScriptOp_377
ScriptOp_377: @ 0x081365D0
	push {r4, r5, r6, lr}
	ldr r2, .L081365F4
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L081365F8
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r5, [r0]
	cmp r5, #3
	bhi .L08136686
	cmp r5, #1
	bne .L081365FC
	movs r5, #2
	b .L08136602
	.byte 0x00, 0x00
.L081365F4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081365F8: .4byte 0x03006950 @ IWRAM+0x6950
.L081365FC:
	cmp r5, #0
	bne .L08136602
	movs r5, #1
.L08136602:
	adds r0, r5, #0
	bl Party_Add
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08136630
	movs r4, #5
	ldr r2, .L0813662C
	movs r0, #0xa2
	lsls r0, r0, #4
	adds r1, r2, r0
.L08136618:
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bgt .L08136674
	subs r4, #1
	cmp r4, #0
	bge .L08136618
	b .L08136638
.L0813662C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08136630:
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
.L08136638:
	cmp r5, #1
	bne .L08136656
	movs r0, #0xf
	bl Flag_Test
	cmp r0, #0
	beq .L0813664E
	movs r0, #2
	bl sub_081362DC
	b .L0813665C
.L0813664E:
	movs r0, #0
	bl sub_081362DC
	b .L0813665C
.L08136656:
	movs r0, #1
	bl sub_081362DC
.L0813665C:
	movs r0, #0xe3
	bl Flag_Clear
	movs r0, #0xe2
	bl Flag_Test
	cmp r0, #0
	bne .L08136710
	movs r0, #0xcf
	bl Flag_Clear
	b .L08136710
.L08136674:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl Party_Remove
	adds r0, r5, #0
	bl Party_Add
	b .L081366F8
.L08136686:
	bl Stock_GetCapacity
	adds r6, r0, #0
	movs r4, #4
	adds r0, r6, #4
	cmp r4, r0
	bge .L08136710
	movs r5, #0x80
	lsls r5, r5, #0xb
.L08136698:
	adds r0, r4, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L08136702
	adds r0, r4, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L081366C8
	ldrh r1, [r1]
	cmp r0, r1
	bne .L08136702
	lsrs r0, r5, #0x10
	bl Party_Add
	lsls r0, r0, #0x10
	adds r4, r5, #0
	cmp r0, #0
	bne .L081366F8
	movs r1, #5
	ldr r2, .L081366CC
	b .L081366D6
.L081366C8: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L081366CC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L081366D0:
	subs r1, #1
	cmp r1, #0
	blt .L081366F8
.L081366D6:
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r0, r2, r3
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble .L081366D0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl Party_Remove
	lsrs r0, r4, #0x10
	bl Party_Add
.L081366F8:
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	b .L08136710
.L08136702:
	movs r0, #0x80
	lsls r0, r0, #9
	adds r5, r5, r0
	adds r4, #1
	adds r0, r6, #4
	cmp r4, r0
	blt .L08136698
.L08136710:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_378
ScriptOp_378: @ 0x08136718
	push {r4, lr}
	ldr r2, .L08136744
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08136748
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r2, [r0]
	adds r4, r2, #0
	cmp r2, #3
	bgt .L08136762
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813674C
	movs r4, #1
	b .L08136758
	.byte 0x00, 0x00
.L08136744: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08136748: .4byte 0x03006950 @ IWRAM+0x6950
.L0813674C:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08136758
	movs r4, #2
.L08136758:
	adds r0, r4, #0
	movs r1, #0
	bl Party_Remove
	b .L08136780
.L08136762:
	ldr r1, .L0813678C
	movs r0, #1
	ands r2, r0
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl Stock_FindDemonIndex
	cmp r0, #0
	blt .L08136780
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl Party_Remove
.L08136780:
	bl sub_080C366C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813678C: .4byte 0x0203DB28 @ EWRAM+0x3DB28

	thumb_func_start ScriptOp_379
ScriptOp_379: @ 0x08136790
	push {r4, r5, r6, lr}
	ldr r0, .L081367C4
	movs r1, #0
	strh r1, [r0]
	ldr r1, .L081367C8
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq .L081367D0
	movs r4, #0
	cmp r4, r0
	bge .L081367D8
	ldr r6, .L081367CC
	adds r5, r1, #0
.L081367AC:
	ldrh r0, [r6]
	bl sub_080C3328
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt .L081367AC
	b .L081367D8
	.byte 0x00, 0x00
.L081367C4: .4byte 0x030068A0 @ IWRAM+0x68A0
.L081367C8: .4byte 0x030065FC @ IWRAM+0x65FC
.L081367CC: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L081367D0:
	ldr r0, .L081367E0
	ldrh r0, [r0]
	bl sub_080C3328
.L081367D8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081367E0: .4byte 0x0203DB50 @ EWRAM+0x3DB50

	thumb_func_start ScriptOp_37A
ScriptOp_37A: @ 0x081367E4
	push {r4, r5, r6, r7, lr}
	ldr r0, .L08136814
	movs r1, #0
	strh r1, [r0]
	ldr r1, .L08136818
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble .L08136874
	movs r6, #0
	cmp r6, r0
	bge .L0813687C
	ldr r7, .L0813681C
.L081367FE:
	ldrh r0, [r7]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08136820
	ldrh r0, [r7]
	bl sub_080C33AC
	adds r6, #1
	b .L0813685E
.L08136814: .4byte 0x030068A0 @ IWRAM+0x68A0
.L08136818: .4byte 0x030065FC @ IWRAM+0x65FC
.L0813681C: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08136820:
	ldrh r0, [r7]
	bl sub_080D2268
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r4, #0
	adds r6, #1
	b .L08136836
.L08136830:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L08136836:
	cmp r4, #3
	bhi .L0813685E
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08136830
	adds r0, r4, #0
	adds r1, r5, #0
	bl Combatant_GetEquip
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r7]
	cmp r0, r1
	bne .L08136830
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080CDFF8
.L0813685E:
	lsls r0, r6, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L08136870
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt .L081367FE
	b .L0813687C
	.byte 0x00, 0x00
.L08136870: .4byte 0x030065FC @ IWRAM+0x65FC
.L08136874:
	ldr r0, .L08136884
	ldrh r0, [r0]
	bl sub_080C33AC
.L0813687C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08136884: .4byte 0x0203DB50 @ EWRAM+0x3DB50

	thumb_func_start ScriptOp_37B
ScriptOp_37B: @ 0x08136888
	push {lr}
	ldr r0, .L081368A8
	ldrh r0, [r0]
	bl BgPicture_StartTask
	ldr r1, .L081368AC
	str r0, [r1]
	ldr r1, .L081368B0
	movs r0, #2
	strh r0, [r1]
	ldr r1, .L081368B4
	movs r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081368A8: .4byte 0x03004534 @ IWRAM+0x4534
.L081368AC: .4byte 0x030068B0 @ IWRAM+0x68B0
.L081368B0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L081368B4: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_37D
ScriptOp_37D: @ 0x081368B8
	push {r4, r5, lr}
	ldr r2, .L081368D8
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L081368DC
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne .L081368E0
	movs r0, #0x80
	lsls r0, r0, #8
	b .L081368F2
.L081368D8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081368DC: .4byte 0x03006950 @ IWRAM+0x6950
.L081368E0:
	cmp r0, #4
	bne .L081368EC
	ldr r0, .L081368E8
	b .L081368F2
.L081368E8: .4byte 0x00008001
.L081368EC:
	cmp r0, #5
	bne .L081368F2
	ldr r0, .L08136938
.L081368F2:
	bl NameEntry_Open
	ldr r1, .L0813693C
	str r0, [r1]
	ldr r1, .L08136940
	movs r0, #0x17
	strh r0, [r1]
	ldr r0, .L08136944
	movs r4, #0
	strh r4, [r0]
	ldr r0, .L08136948
	strh r4, [r0]
	ldr r0, .L0813694C
	strh r4, [r0]
	ldr r5, .L08136950
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq .L08136924
	ldr r0, .L08136954
	ldr r0, [r0]
	movs r1, #1
	bl Window_Close
	strh r4, [r5]
.L08136924:
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r1, .L08136958
	movs r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08136938: .4byte 0x00008002
.L0813693C: .4byte 0x030068E0 @ IWRAM+0x68E0
.L08136940: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08136944: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L08136948: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813694C: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L08136950: .4byte 0x0203DB6C @ EWRAM+0x3DB6C
.L08136954: .4byte 0x03006968 @ IWRAM+0x6968
.L08136958: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_37F
ScriptOp_37F: @ 0x0813695C
	push {r4, r5, r6, lr}
	ldr r3, .L081369B0
	ldrh r0, [r3]
	adds r2, r0, #1
	strh r2, [r3]
	lsls r0, r0, #0x10
	ldr r1, .L081369B4
	ldr r4, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	adds r1, r2, #1
	strh r1, [r3]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xf
	adds r2, r2, r4
	ldrh r5, [r2]
	adds r2, r1, #1
	strh r2, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r6, [r1]
	adds r1, r2, #1
	strh r1, [r3]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xf
	adds r2, r2, r4
	ldrh r1, [r2]
	lsls r4, r1, #0x10
	orrs r4, r6
	bl Combatant_GetStatus
	ands r5, r0
	cmp r5, #0
	beq .L081369A8
	ldr r0, .L081369B8
	str r4, [r0]
.L081369A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081369B0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081369B4: .4byte 0x03006950 @ IWRAM+0x6950
.L081369B8: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_380
ScriptOp_380: @ 0x081369BC
	ldr r1, .L081369C8
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L081369C8: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_381
ScriptOp_381: @ 0x081369CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl Stock_GetCapacity
	mov ip, r0
	ldr r3, .L08136A7C
	ldrh r0, [r3]
	adds r2, r0, #1
	strh r2, [r3]
	lsls r0, r0, #0x10
	ldr r1, .L08136A80
	ldr r4, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r6, [r0]
	mov sb, r6
	adds r1, r2, #1
	strh r1, [r3]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xf
	adds r2, r2, r4
	ldrh r5, [r2]
	adds r7, r5, #0
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r2, [r1]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	mov r8, r0
	lsls r0, r0, #0x10
	orrs r0, r2
	mov r8, r0
	cmp r6, #1
	bne .L08136A94
	cmp r5, #0
	bne .L08136A28
	b .L08136BB8
.L08136A28:
	cmp r5, #3
	bne .L08136A88
	movs r2, #0
	mov sb, r2
	movs r4, #4
	mov r7, ip
	adds r7, #4
	cmp r4, r7
	bge .L08136A72
.L08136A3A:
	lsls r4, r4, #0x10
	asrs r5, r4, #0x10
	adds r0, r5, #0
	bl Combatant_IsUsed
	adds r6, r4, #0
	cmp r0, #0
	beq .L08136A64
	adds r0, r5, #0
	bl Combatant_GetStatus
	ldr r2, .L08136A84
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	bne .L08136A64
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
.L08136A64:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r6, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	blt .L08136A3A
.L08136A72:
	mov r2, sb
	cmp r2, #0
	beq .L08136A7A
	b .L08136BBE
.L08136A7A:
	b .L08136BB8
.L08136A7C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08136A80: .4byte 0x03006950 @ IWRAM+0x6950
.L08136A84: .4byte 0x0000B160
.L08136A88:
	ldr r0, .L08136A90
	mov r2, r8
	str r2, [r0]
	b .L08136BBE
.L08136A90: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08136A94:
	cmp r6, #2
	bne .L08136AF8
	cmp r5, #0
	bne .L08136AC0
	ldr r0, .L08136AB4
	strh r5, [r0]
	movs r0, #0
	bl sub_08135180
	ldr r0, .L08136AB8
	mov r1, r8
	str r1, [r0]
	ldr r1, .L08136ABC
	movs r0, #0x40
	b .L08136B38
	.byte 0x00, 0x00
.L08136AB4: .4byte 0x030065E8 @ IWRAM+0x65E8
.L08136AB8: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08136ABC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08136AC0:
	cmp r5, #1
	bne .L08136AD4
	ldr r0, .L08136AD0
	strh r5, [r0]
	movs r0, #1
	bl sub_08135180
	b .L08136ADE
.L08136AD0: .4byte 0x030065E8 @ IWRAM+0x65E8
.L08136AD4:
	ldr r0, .L08136AEC
	strh r6, [r0]
	movs r0, #1
	bl sub_08135180
.L08136ADE:
	ldr r0, .L08136AF0
	mov r2, r8
	str r2, [r0]
	ldr r1, .L08136AF4
	movs r0, #0x40
	b .L08136B38
	.byte 0x00, 0x00
.L08136AEC: .4byte 0x030065E8 @ IWRAM+0x65E8
.L08136AF0: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08136AF4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08136AF8:
	mov r0, sb
	cmp r0, #3
	bne .L08136B72
	ldr r0, .L08136B44
	movs r4, #0
	strh r4, [r0]
	ldr r0, .L08136B48
	strh r4, [r0]
	ldr r0, .L08136B4C
	strh r4, [r0]
	ldr r0, .L08136B50
	strh r4, [r0]
	ldr r5, .L08136B54
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq .L08136B26
	ldr r0, .L08136B58
	ldr r0, [r0]
	movs r1, #1
	bl Window_Close
	strh r4, [r5]
.L08136B26:
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L08136B5C
	mov r2, r8
	str r2, [r0]
	ldr r1, .L08136B60
	movs r0, #0x41
.L08136B38:
	strh r0, [r1]
	ldr r1, .L08136B64
	movs r0, #1
	strh r0, [r1]
	b .L08136BBE
	.byte 0x00, 0x00
.L08136B44: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L08136B48: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L08136B4C: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L08136B50: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L08136B54: .4byte 0x0203DB6C @ EWRAM+0x3DB6C
.L08136B58: .4byte 0x03006968 @ IWRAM+0x6968
.L08136B5C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08136B60: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08136B64: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08136B68:
	lsrs r0, r6, #0x10
	movs r1, #1
	bl Party_Remove
	b .L08136BB4
.L08136B72:
	cmp r7, #0
	bne .L08136BB4
	movs r4, #4
	mov r7, ip
	adds r7, #4
	cmp r4, r7
	bge .L08136BB4
.L08136B80:
	lsls r4, r4, #0x10
	asrs r5, r4, #0x10
	adds r0, r5, #0
	bl Combatant_IsUsed
	adds r6, r4, #0
	cmp r0, #0
	beq .L08136BA8
	adds r0, r5, #0
	bl Combatant_GetDemonId
	adds r4, r0, #0
	ldr r0, .L08136BCC
	ldrh r0, [r0]
	bl Combatant_GetDemonId
	lsls r4, r4, #0x10
	lsls r0, r0, #0x10
	cmp r4, r0
	beq .L08136B68
.L08136BA8:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	blt .L08136B80
.L08136BB4:
	bl sub_080C84A0
.L08136BB8:
	ldr r0, .L08136BD0
	mov r1, r8
	str r1, [r0]
.L08136BBE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08136BCC: .4byte 0x03006944 @ IWRAM+0x6944
.L08136BD0: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_382
ScriptOp_382: @ 0x08136BD4
	push {r4, lr}
	ldr r4, .L08136C30
	ldr r3, .L08136C34
	ldr r2, .L08136C38
	ldr r1, .L08136C3C
	movs r0, #0
	strh r0, [r1]
	strh r0, [r2]
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r1, .L08136C40
	ldrh r0, [r1]
	adds r2, r0, #1
	strh r2, [r1]
	lsls r0, r0, #0x10
	ldr r4, .L08136C44
	ldr r1, [r4]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r3, [r0]
	lsls r0, r3, #0x11
	lsrs r3, r0, #0x10
	ldr r0, .L08136C48
	str r1, [r0]
	ldr r0, .L08136C4C
	strh r2, [r0]
	ldr r1, .L08136C50
	movs r0, #1
	strh r0, [r1]
	ldr r1, .L08136C54
	ldrh r2, [r1]
	cmp r2, #0xff
	bls .L08136C5C
	ldr r0, .L08136C58
	str r0, [r4]
	movs r1, #0xff
	ands r1, r2
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	b .L08136C68
	.byte 0x00, 0x00
.L08136C30: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L08136C34: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L08136C38: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L08136C3C: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L08136C40: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08136C44: .4byte 0x03006950 @ IWRAM+0x6950
.L08136C48: .4byte 0x030068D0 @ IWRAM+0x68D0
.L08136C4C: .4byte 0x03006610 @ IWRAM+0x6610
.L08136C50: .4byte 0x03006910 @ IWRAM+0x6910
.L08136C54: .4byte 0x03006914 @ IWRAM+0x6914
.L08136C58: .4byte gUnknown_08035ABC
.L08136C5C:
	ldr r0, .L08136C88
	str r0, [r4]
	ldrh r1, [r1]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
.L08136C68:
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, .L08136C8C
	ldr r1, [r0]
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	orrs r0, r1
	ldr r1, .L08136C90
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L08136C88: .4byte gUnknown_0803534C
.L08136C8C: .4byte 0x03006950 @ IWRAM+0x6950
.L08136C90: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_388
ScriptOp_388: @ 0x08136C94
	push {lr}
	bl sub_080B80F8
	ldr r1, .L08136CB0
	str r0, [r1]
	ldr r1, .L08136CB4
	movs r0, #0x15
	strh r0, [r1]
	ldr r1, .L08136CB8
	movs r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08136CB0: .4byte 0x03006938 @ IWRAM+0x6938
.L08136CB4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08136CB8: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_389
ScriptOp_389: @ 0x08136CBC
	push {lr}
	ldr r0, .L08136CD4
	ldrh r0, [r0]
	subs r0, #0x1c
	cmp r0, #5
	bhi .L08136D4A
	lsls r0, r0, #2
	ldr r1, .L08136CD8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L08136CD4: .4byte 0x03006914 @ IWRAM+0x6914
.L08136CD8: .4byte gUnknown_08136CDC
	.global gUnknown_08136CDC
gUnknown_08136CDC:
.L08136CDC: @ jump table
	.4byte .L08136CF4
	.4byte .L08136D04
	.4byte .L08136D14
	.4byte .L08136D24
	.4byte .L08136D34
	.4byte .L08136D44
.L08136CF4:
	ldr r1, .L08136CFC
	ldr r0, .L08136D00
	b .L08136D48
	.byte 0x00, 0x00
.L08136CFC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08136D00: .4byte gUnknown_08073C5E
.L08136D04:
	ldr r1, .L08136D0C
	ldr r0, .L08136D10
	b .L08136D48
	.byte 0x00, 0x00
.L08136D0C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08136D10: .4byte gUnknown_08074C28
.L08136D14:
	ldr r1, .L08136D1C
	ldr r0, .L08136D20
	b .L08136D48
	.byte 0x00, 0x00
.L08136D1C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08136D20: .4byte gUnknown_08075BE8
.L08136D24:
	ldr r1, .L08136D2C
	ldr r0, .L08136D30
	b .L08136D48
	.byte 0x00, 0x00
.L08136D2C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08136D30: .4byte gUnknown_08076C3C
.L08136D34:
	ldr r1, .L08136D3C
	ldr r0, .L08136D40
	b .L08136D48
	.byte 0x00, 0x00
.L08136D3C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08136D40: .4byte gUnknown_08076F80
.L08136D44:
	ldr r1, .L08136D50
	ldr r0, .L08136D54
.L08136D48:
	str r0, [r1]
.L08136D4A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08136D50: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08136D54: .4byte gUnknown_08077338
