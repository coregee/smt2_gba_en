	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_0812F2B4
sub_0812F2B4: @ 0x0812F2B4
.L0812F2B4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #0xc]
	bl Money_Get
	str r0, [sp, #0x10]
	ldr r1, .L0812F38C
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, .L0812F390
	ldrh r4, [r0]
	ldr r0, .L0812F394
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r0, .L0812F398
	mov r2, sp
	ldrh r2, [r2, #0xc]
	strh r2, [r0]
	ldr r0, .L0812F39C
	mov r3, sp
	ldrh r3, [r3, #0xc]
	strh r3, [r0]
	ldr r0, .L0812F3A0
	mov r5, sp
	ldrh r5, [r5, #0xc]
	strh r5, [r0]
	ldr r0, .L0812F3A4
	mov r7, sp
	ldrh r7, [r7, #0xc]
	strh r7, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L0812F3A8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq .L0812F31C
	cmp r0, #3
	beq .L0812F31C
	cmp r0, #4
	bne .L0812F320
.L0812F31C:
	bl MsgWindow_RestoreGlyphs
.L0812F320:
	movs r2, #0
	mov sb, r2
	ldr r1, .L0812F3AC
	lsls r2, r4, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	ldr r3, .L0812F3B0
	adds r5, r1, #0
	cmp r0, r3
	bne .L0812F336
	b .L0812F50C
.L0812F336:
	lsls r6, r6, #5
	str r6, [sp, #0x14]
.L0812F33A:
	ldr r3, [sp]
	lsls r0, r3, #1
	ldr r7, [sp, #0x14]
	adds r0, r0, r7
	ldr r1, .L0812F3B4
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r7, .L0812F3B0
	cmp r0, r7
	bne .L0812F350
	b .L0812F50C
.L0812F350:
	adds r0, r3, #0
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	adds r1, r0, #0
	lsls r0, r3, #1
	ldr r3, [sp, #0x14]
	adds r0, r0, r3
	ldr r7, .L0812F3B4
	adds r0, r0, r7
	ldrh r6, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsls r1, r1, #1
	adds r1, r1, r3
	adds r1, r1, r7
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldr r0, .L0812F3B8
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0812F3C0
	ldr r0, .L0812F3BC
	ldr r1, .L0812F394
	str r0, [r1]
	b .L0812F3E2
	.byte 0x00, 0x00
.L0812F38C: .4byte 0x030068B8 @ IWRAM+0x68B8
.L0812F390: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F394: .4byte 0x03006950 @ IWRAM+0x6950
.L0812F398: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0812F39C: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0812F3A0: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0812F3A4: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0812F3A8: .4byte 0x03006844 @ IWRAM+0x6844
.L0812F3AC: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F3B0: .4byte 0x0000FFFF
.L0812F3B4: .4byte gUnknown_0878FBA4
.L0812F3B8: .4byte 0x030069CC @ IWRAM+0x69CC
.L0812F3BC: .4byte gUnknown_08036666
.L0812F3C0:
	ldr r0, .L0812F3D0
	ldrh r0, [r0]
	cmp r0, #1
	bne .L0812F3DC
	ldr r0, .L0812F3D4
	ldr r3, .L0812F3D8
	str r0, [r3]
	b .L0812F3E2
.L0812F3D0: .4byte 0x03006670 @ IWRAM+0x6670
.L0812F3D4: .4byte gUnknown_08036156
.L0812F3D8: .4byte 0x03006950 @ IWRAM+0x6950
.L0812F3DC:
	ldr r0, .L0812F524
	ldr r7, .L0812F528
	str r0, [r7]
.L0812F3E2:
	adds r0, r2, r5
	ldrh r3, [r0]
	lsls r0, r3, #0x11
	ldr r2, .L0812F528
	ldr r1, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	str r0, [sp, #0x18]
	mov r8, r0
	ldr r0, .L0812F52C
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bne .L0812F422
	adds r0, r3, #0
	subs r0, #0x9d
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_0812F188
	str r0, [sp, #0xc]
	ldr r2, [sp, #0x10]
	cmp r2, r0
	bhs .L0812F422
	movs r3, #4
	mov r8, r3
.L0812F422:
	ldr r1, [sp, #0x18]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	ldr r2, .L0812F528
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r3, [r1]
	ldr r0, .L0812F530
	mov r5, sb
	lsls r5, r5, #0x10
	mov ip, r5
	adds r4, #1
	mov sl, r4
	cmp r3, r0
	beq .L0812F4AE
	ldr r5, .L0812F534
	ldr r4, .L0812F538
	mov sb, r0
.L0812F44C:
	ldrh r2, [r5]
	lsls r0, r2, #0x12
	lsrs r0, r0, #0x10
	movs r1, #1
	orrs r1, r0
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r3, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsls r1, r1, #1
	adds r1, r1, r4
	strh r6, [r1]
	movs r7, #0x80
	lsls r7, r7, #9
	adds r1, r0, r7
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	mov r3, sp
	ldrh r3, [r3, #4]
	strh r3, [r0]
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	mov r7, r8
	strh r7, [r1]
	adds r2, #1
	strh r2, [r5]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r2, #0x3f
	bls .L0812F48E
	movs r0, #0x3f
	strh r0, [r5]
.L0812F48E:
	adds r0, r6, #0
	adds r0, #0xd
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r1, [sp, #0x18]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	ldr r2, .L0812F528
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r3, [r1]
	cmp r3, sb
	bne .L0812F44C
.L0812F4AE:
	ldr r3, .L0812F52C
	movs r5, #0
	ldrsh r0, [r3, r5]
	cmp r0, #4
	bne .L0812F4E4
	mov r7, ip
	asrs r4, r7, #0x10
	cmp r4, #2
	bgt .L0812F4E4
	ldr r1, .L0812F53C
	lsls r2, r4, #4
	adds r3, r2, r1
	movs r0, #1
	strh r0, [r3]
	adds r1, #4
	adds r2, r2, r1
	ldr r0, [sp, #0xc]
	str r0, [r2]
	movs r0, #0x80
	strh r0, [r3, #8]
	ldr r1, .L0812F540
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r3, #0xa]
	mov r1, r8
	strh r1, [r3, #0xc]
.L0812F4E4:
	mov r2, sl
	lsls r0, r2, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, ip
	lsrs r3, r0, #0x10
	mov sb, r3
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt .L0812F50C
	ldr r1, .L0812F544
	lsls r2, r4, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r5, r1, #0
	ldr r7, .L0812F548
	cmp r0, r7
	beq .L0812F50C
	b .L0812F33A
.L0812F50C:
	ldr r0, [sp, #8]
	ldr r1, .L0812F528
	str r0, [r1]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812F524: .4byte gUnknown_0803631E
.L0812F528: .4byte 0x03006950 @ IWRAM+0x6950
.L0812F52C: .4byte 0x03006844 @ IWRAM+0x6844
.L0812F530: .4byte 0x00000301
.L0812F534: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0812F538: .4byte 0x0203D800 @ EWRAM+0x3D800
.L0812F53C: .4byte 0x03006620 @ IWRAM+0x6620
.L0812F540: .4byte gUnknown_0878FC64
.L0812F544: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F548: .4byte 0x0000FFFF

	thumb_func_start sub_0812F54C
sub_0812F54C: @ 0x0812F54C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	ldr r4, .L0812F5A4
	ldr r5, .L0812F5A8
	ldr r3, .L0812F5AC
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r1, r1, #2
	ldr r2, .L0812F5B0
	movs r6, #0
	ldrsh r0, [r2, r6]
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r5
	ldrh r0, [r1]
	strh r0, [r4]
	ldr r4, .L0812F5B4
	movs r7, #0
	ldrsh r0, [r3, r7]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	movs r6, #0
	ldrsh r1, [r2, r6]
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r4]
	ldrh r1, [r2]
	subs r0, r1, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r6, r3, #0
	mov ip, r2
	cmp r0, #1
	bhi .L0812F5BC
	ldr r1, .L0812F5B8
	movs r0, #0xa
	b .L0812F5D4
	.byte 0x00, 0x00
.L0812F5A4: .4byte 0x0300689C @ IWRAM+0x689C
.L0812F5A8: .4byte gUnknown_0878FBA4
.L0812F5AC: .4byte 0x0300696C @ IWRAM+0x696C
.L0812F5B0: .4byte 0x03006844 @ IWRAM+0x6844
.L0812F5B4: .4byte 0x0300695C @ IWRAM+0x695C
.L0812F5B8: .4byte 0x030066A0 @ IWRAM+0x66A0
.L0812F5BC:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne .L0812F5D0
	ldr r1, .L0812F5CC
	movs r0, #0x14
	b .L0812F5D4
	.byte 0x00, 0x00
.L0812F5CC: .4byte 0x030066A0 @ IWRAM+0x66A0
.L0812F5D0:
	ldr r1, .L0812F614
	movs r0, #0x13
.L0812F5D4:
	strh r0, [r1]
	ldr r0, .L0812F618
	movs r2, #1
	strh r2, [r0]
	ldr r0, .L0812F61C
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L0812F5EC
	b .L0812F780
.L0812F5EC:
	mov r7, ip
	movs r0, #0
	ldrsh r1, [r7, r0]
	cmp r1, #0
	bne .L0812F64E
	ldr r0, .L0812F620
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #3
	bgt .L0812F604
	bl .L08130146
.L0812F604:
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #0
	beq .L0812F624
	strh r1, [r6]
	bl .L0813013A
	.byte 0x00, 0x00
.L0812F614: .4byte 0x030066A0 @ IWRAM+0x66A0
.L0812F618: .4byte 0x03006958 @ IWRAM+0x6958
.L0812F61C: .4byte 0x03003964 @ IWRAM+0x3964
.L0812F620: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F624:
	ldr r2, .L0812F640
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	bne .L0812F634
	bl .L08130146
.L0812F634:
	subs r0, #4
	cmp r0, #0
	blt .L0812F644
	subs r0, r3, #4
	strh r0, [r2]
	b .L0812F646
.L0812F640: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F644:
	strh r1, [r2]
.L0812F646:
	mov r6, ip
	ldrh r0, [r6]
	bl .L08130136
.L0812F64E:
	cmp r1, #4
	beq .L0812F656
	cmp r1, #1
	bne .L0812F6A2
.L0812F656:
	ldr r0, .L0812F674
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #2
	bgt .L0812F664
	bl .L08130146
.L0812F664:
	movs r0, #0
	ldrsh r2, [r6, r0]
	cmp r2, #0
	beq .L0812F678
	movs r0, #0
	strh r0, [r6]
	bl .L0813013A
.L0812F674: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F678:
	ldr r1, .L0812F694
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bne .L0812F688
	bl .L08130146
.L0812F688:
	subs r0, #3
	cmp r0, #0
	blt .L0812F698
	subs r0, r3, #3
	strh r0, [r1]
	b .L0812F69A
.L0812F694: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F698:
	strh r2, [r1]
.L0812F69A:
	mov r6, ip
	ldrh r0, [r6]
	bl .L08130136
.L0812F6A2:
	cmp r1, #2
	bne .L0812F710
	ldr r0, .L0812F6E0
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #7
	bgt .L0812F6B4
	bl .L08130146
.L0812F6B4:
	ldrh r0, [r6]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #1
	bhi .L0812F6F4
	ldr r1, .L0812F6E4
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne .L0812F6CE
	bl .L08130146
.L0812F6CE:
	subs r0, #6
	cmp r0, #0
	blt .L0812F6E8
	subs r0, r2, #6
	strh r0, [r1]
	mov r5, ip
	ldrh r0, [r5]
	bl .L08130136
.L0812F6E0: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F6E4: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F6E8:
	movs r0, #0
	strh r0, [r1]
	mov r6, ip
	ldrh r0, [r6]
	bl .L08130136
.L0812F6F4:
	asrs r0, r1, #0x10
	cmp r0, #2
	beq .L0812F702
	cmp r0, #4
	beq .L0812F702
	cmp r0, #6
	bne .L0812F70A
.L0812F702:
	movs r0, #0
	strh r0, [r6]
	bl .L0813013A
.L0812F70A:
	strh r2, [r6]
	bl .L0813013A
.L0812F710:
	cmp r1, #3
	beq .L0812F718
	bl .L08130146
.L0812F718:
	ldr r0, .L0812F754
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #5
	bgt .L0812F726
	bl .L08130146
.L0812F726:
	ldrh r0, [r6]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #1
	bhi .L0812F768
	ldr r1, .L0812F758
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne .L0812F740
	bl .L08130146
.L0812F740:
	subs r0, #6
	cmp r0, #0
	blt .L0812F75C
	subs r0, r2, #6
	strh r0, [r1]
	mov r5, ip
	ldrh r0, [r5]
	bl .L08130136
	.byte 0x00, 0x00
.L0812F754: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F758: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F75C:
	movs r0, #0
	strh r0, [r1]
	mov r6, ip
	ldrh r0, [r6]
	bl .L08130136
.L0812F768:
	asrs r0, r1, #0x10
	cmp r0, #2
	beq .L0812F772
	cmp r0, #4
	bne .L0812F77A
.L0812F772:
	movs r0, #0
	strh r0, [r6]
	bl .L0813013A
.L0812F77A:
	strh r2, [r6]
	bl .L0813013A
.L0812F780:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0812F78C
	b .L0812FC24
.L0812F78C:
	mov r7, ip
	movs r0, #0
	ldrsh r4, [r7, r0]
	cmp r4, #0
	bne .L0812F7F0
	ldr r3, .L0812F7B8
	ldrh r4, [r3]
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #3
	bgt .L0812F7A6
	bl .L08130146
.L0812F7A6:
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #3
	beq .L0812F7BC
	movs r0, #3
	strh r0, [r6]
	bl .L0813013A
	.byte 0x00, 0x00
.L0812F7B8: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F7BC:
	movs r5, #0
	ldrsh r1, [r6, r5]
	ldr r2, .L0812F7E0
	movs r6, #0
	ldrsh r0, [r2, r6]
	adds r1, r1, r0
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bne .L0812F7D4
	bl .L08130146
.L0812F7D4:
	subs r0, #3
	cmp r1, r0
	bge .L0812F7E4
	ldrh r0, [r2]
	adds r0, #4
	b .L0812F7E6
.L0812F7E0: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F7E4:
	subs r0, r4, #3
.L0812F7E6:
	strh r0, [r2]
	mov r1, ip
	ldrh r0, [r1]
	bl .L08130136
.L0812F7F0:
	cmp r4, #4
	beq .L0812F7F8
	cmp r4, #1
	bne .L0812F850
.L0812F7F8:
	ldr r3, .L0812F818
	ldrh r4, [r3]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #2
	bgt .L0812F808
	bl .L08130146
.L0812F808:
	movs r5, #0
	ldrsh r0, [r6, r5]
	cmp r0, #2
	beq .L0812F81C
	movs r0, #2
	strh r0, [r6]
	bl .L0813013A
.L0812F818: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F81C:
	movs r7, #0
	ldrsh r1, [r6, r7]
	ldr r2, .L0812F840
	movs r5, #0
	ldrsh r0, [r2, r5]
	adds r1, r1, r0
	movs r6, #0
	ldrsh r0, [r3, r6]
	cmp r1, r0
	bne .L0812F834
	bl .L08130146
.L0812F834:
	subs r0, #2
	cmp r1, r0
	bge .L0812F844
	ldrh r0, [r2]
	adds r0, #3
	b .L0812F846
.L0812F840: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F844:
	subs r0, r4, #2
.L0812F846:
	strh r0, [r2]
	mov r7, ip
	ldrh r0, [r7]
	bl .L08130136
.L0812F850:
	cmp r4, #2
	beq .L0812F856
	b .L0812FA64
.L0812F856:
	ldr r0, .L0812F8B0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #7
	bgt .L0812F864
	bl .L08130146
.L0812F864:
	movs r2, #0
	ldrsh r4, [r6, r2]
	cmp r4, #7
	bne .L0812F8DE
	movs r5, #2
	ldr r3, .L0812F8B4
	mov sb, r3
	ldr r2, .L0812F8B8
	mov r7, sb
	movs r4, #0
	ldrsh r1, [r7, r4]
	adds r3, r6, #0
	movs r6, #0
	ldrsh r0, [r3, r6]
	adds r1, r1, r0
	ldr r0, .L0812F8BC
	mov r8, r0
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r6, r0, r2
.L0812F88C:
	adds r0, r1, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r4, [r0]
	cmp r4, r8
	bne .L0812F8C0
	cmp r5, #2
	bne .L0812F8A6
	ldrh r0, [r6]
	cmp r0, r4
	beq .L0812F8A6
	bl .L08130114
.L0812F8A6:
	subs r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b .L0812F8CA
	.byte 0x00, 0x00
.L0812F8B0: .4byte 0x03006604 @ IWRAM+0x6604
.L0812F8B4: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F8B8: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F8BC: .4byte 0x0000FFFF
.L0812F8C0:
	adds r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bls .L0812F88C
.L0812F8CA:
	cmp r5, #0
	bne .L0812F8D2
	bl .L08130146
.L0812F8D2:
	mov r1, sb
	ldrh r0, [r1]
	adds r0, r5, r0
	strh r0, [r1]
	bl .L08130132
.L0812F8DE:
	cmp r4, #6
	bne .L0812F958
	movs r5, #2
	ldr r3, .L0812F94C
	ldr r2, .L0812F950
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r7, #0
	ldrsh r1, [r6, r7]
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, .L0812F954
	mov sb, r2
	adds r2, r3, #0
	cmp r1, r0
	bne .L0812F908
	bl .L08130146
.L0812F908:
	adds r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bhi .L0812F932
	mov r1, sb
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r4, #0
	ldrsh r1, [r6, r4]
	adds r0, r0, r1
	adds r0, r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812F954
	cmp r1, r0
	bne .L0812F908
	subs r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0812F932:
	cmp r5, #0
	bne .L0812F93A
	bl .L08130146
.L0812F93A:
	mov r6, sb
	ldrh r0, [r6]
	adds r0, r5, r0
	strh r0, [r6]
	mov r7, ip
	ldrh r0, [r7]
	bl .L08130136
	.byte 0x00, 0x00
.L0812F94C: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F950: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F954: .4byte 0x0000FFFF
.L0812F958:
	cmp r4, #0
	beq .L0812F964
	cmp r4, #2
	beq .L0812F964
	cmp r4, #4
	bne .L0812F9D4
.L0812F964:
	ldr r2, .L0812F984
	ldr r1, .L0812F988
	movs r0, #0
	ldrsh r5, [r1, r0]
	adds r0, r5, #6
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r4, [r0]
	ldr r0, .L0812F98C
	mov sb, r1
	cmp r4, r0
	beq .L0812F990
	movs r0, #6
	strh r0, [r6]
	bl .L0813013A
.L0812F984: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F988: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F98C: .4byte 0x0000FFFF
.L0812F990:
	adds r0, r5, #4
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r4
	beq .L0812F9AA
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt .L0812F9AA
	movs r0, #4
	strh r0, [r6]
	b .L0813013A
.L0812F9AA:
	mov r3, sb
	movs r4, #0
	ldrsh r0, [r3, r4]
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812F9D0
	cmp r1, r0
	bne .L0812F9C0
	b .L08130146
.L0812F9C0:
	movs r5, #0
	ldrsh r0, [r6, r5]
	cmp r0, #1
	ble .L0812F9CA
	b .L08130146
.L0812F9CA:
	movs r0, #2
	strh r0, [r6]
	b .L0813013A
.L0812F9D0: .4byte 0x0000FFFF
.L0812F9D4:
	ldr r2, .L0812F9F4
	ldr r1, .L0812F9F8
	movs r7, #0
	ldrsh r3, [r1, r7]
	adds r0, r3, #7
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r5, [r0]
	ldr r0, .L0812F9FC
	mov sb, r1
	cmp r5, r0
	beq .L0812FA00
	movs r0, #7
	strh r0, [r6]
	b .L0813013A
	.byte 0x00, 0x00
.L0812F9F4: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812F9F8: .4byte 0x03006940 @ IWRAM+0x6940
.L0812F9FC: .4byte 0x0000FFFF
.L0812FA00:
	adds r0, r3, #5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r5
	beq .L0812FA16
	cmp r4, #4
	bgt .L0812FA16
	movs r0, #5
	strh r0, [r6]
	b .L0813013A
.L0812FA16:
	mov r1, sb
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r0, #3
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FA38
	cmp r1, r0
	beq .L0812FA3C
	movs r4, #0
	ldrsh r0, [r6, r4]
	cmp r0, #2
	bgt .L0812FA3C
	movs r0, #3
	strh r0, [r6]
	b .L0813013A
.L0812FA38: .4byte 0x0000FFFF
.L0812FA3C:
	mov r5, sb
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r3, #0
	ldrsh r1, [r6, r3]
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FA60
	cmp r1, r0
	bne .L0812FA58
	b .L08130146
.L0812FA58:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	b .L0813013A
.L0812FA60: .4byte 0x0000FFFF
.L0812FA64:
	cmp r4, #3
	beq .L0812FA6A
	b .L08130146
.L0812FA6A:
	ldr r0, .L0812FAC0
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #5
	bgt .L0812FA76
	b .L08130146
.L0812FA76:
	movs r7, #0
	ldrsh r5, [r6, r7]
	cmp r5, #5
	bne .L0812FAF4
	movs r5, #2
	ldr r0, .L0812FAC4
	mov sb, r0
	ldr r2, .L0812FAC8
	mov r7, sb
	movs r3, #0
	ldrsh r1, [r7, r3]
	adds r3, r6, #0
	movs r4, #0
	ldrsh r0, [r3, r4]
	adds r1, r1, r0
	ldr r6, .L0812FACC
	mov r8, r6
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r6, r0, r2
.L0812FA9E:
	adds r0, r1, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r4, [r0]
	cmp r4, r8
	bne .L0812FAD0
	cmp r5, #2
	bne .L0812FAB6
	ldrh r0, [r6]
	cmp r0, r4
	beq .L0812FAB6
	b .L08130126
.L0812FAB6:
	subs r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b .L0812FADA
	.byte 0x00, 0x00
.L0812FAC0: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FAC4: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FAC8: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FACC: .4byte 0x0000FFFF
.L0812FAD0:
	adds r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bls .L0812FA9E
.L0812FADA:
	cmp r5, #8
	bne .L0812FAE0
	movs r5, #6
.L0812FAE0:
	cmp r5, #0
	bne .L0812FAE6
	b .L08130146
.L0812FAE6:
	mov r7, sb
	ldrh r0, [r7]
	adds r0, r5, r0
	strh r0, [r7]
	mov r1, ip
	ldrh r0, [r1]
	b .L08130136
.L0812FAF4:
	cmp r5, #4
	bne .L0812FB74
	movs r5, #2
	ldr r3, .L0812FB20
	ldr r2, .L0812FB24
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r7, #0
	ldrsh r1, [r6, r7]
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, .L0812FB28
	mov sb, r2
	adds r2, r3, #0
	cmp r1, r0
	bne .L0812FB2C
	movs r5, #0
	b .L0812FB56
	.byte 0x00, 0x00
.L0812FB20: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FB24: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FB28: .4byte 0x0000FFFF
.L0812FB2C:
	adds r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #7
	bhi .L0812FB56
	mov r1, sb
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r4, #0
	ldrsh r1, [r6, r4]
	adds r0, r0, r1
	adds r0, r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FB70
	cmp r1, r0
	bne .L0812FB2C
	subs r0, r5, #2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0812FB56:
	cmp r5, #8
	bne .L0812FB5C
	movs r5, #6
.L0812FB5C:
	cmp r5, #0
	bne .L0812FB62
	b .L08130146
.L0812FB62:
	mov r6, sb
	ldrh r0, [r6]
	adds r0, r5, r0
	strh r0, [r6]
	mov r7, ip
	ldrh r0, [r7]
	b .L08130136
.L0812FB70: .4byte 0x0000FFFF
.L0812FB74:
	cmp r5, #0
	beq .L0812FB7C
	cmp r5, #2
	bne .L0812FBBE
.L0812FB7C:
	ldr r3, .L0812FB98
	ldr r0, .L0812FB9C
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r0, r2, #4
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, .L0812FBA0
	cmp r1, r0
	beq .L0812FBA4
	movs r0, #4
	strh r0, [r6]
	b .L0813013A
.L0812FB98: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FB9C: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FBA0: .4byte 0x0000FFFF
.L0812FBA4:
	adds r0, r2, #2
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, r1
	bne .L0812FBB2
	b .L08130146
.L0812FBB2:
	cmp r5, #1
	ble .L0812FBB8
	b .L08130146
.L0812FBB8:
	movs r0, #2
	strh r0, [r6]
	b .L0813013A
.L0812FBBE:
	ldr r2, .L0812FBDC
	ldr r1, .L0812FBE0
	movs r3, #0
	ldrsh r7, [r1, r3]
	adds r0, r7, #5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r3, [r0]
	ldr r0, .L0812FBE4
	mov sb, r1
	cmp r3, r0
	beq .L0812FBE8
	movs r0, #5
	strh r0, [r6]
	b .L0813013A
.L0812FBDC: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FBE0: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FBE4: .4byte 0x0000FFFF
.L0812FBE8:
	adds r0, r7, #3
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r3
	beq .L0812FBFC
	cmp r5, #2
	bgt .L0812FBFC
	strh r4, [r6]
	b .L0813013A
.L0812FBFC:
	mov r4, sb
	movs r5, #0
	ldrsh r0, [r4, r5]
	movs r7, #0
	ldrsh r1, [r6, r7]
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FC20
	cmp r1, r0
	bne .L0812FC18
	b .L08130146
.L0812FC18:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	b .L0813013A
.L0812FC20: .4byte 0x0000FFFF
.L0812FC24:
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	beq .L0812FCD6
	mov r1, ip
	ldrh r0, [r1]
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	cmp r0, #1
	bls .L0812FC42
	asrs r0, r2, #0x10
	cmp r0, #4
	bne .L0812FCAC
.L0812FC42:
	ldrh r1, [r6]
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #0
	bne .L0812FCA6
	ldr r1, .L0812FC74
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bne .L0812FCA0
	asrs r0, r2, #0x10
	cmp r0, #0
	bne .L0812FC7C
	ldr r0, .L0812FC78
	ldrh r1, [r0]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #3
	ble .L0812FC6C
	b .L08130146
.L0812FC6C:
	strh r1, [r6]
	mov r6, ip
	ldrh r0, [r6]
	b .L08130136
.L0812FC74: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FC78: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FC7C:
	cmp r0, #1
	beq .L0812FC86
	cmp r0, #4
	beq .L0812FC86
	b .L08130146
.L0812FC86:
	ldr r0, .L0812FC9C
	ldrh r1, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #2
	ble .L0812FC94
	b .L08130146
.L0812FC94:
	strh r1, [r6]
	mov r1, ip
	ldrh r0, [r1]
	b .L08130136
.L0812FC9C: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FCA0:
	subs r0, r3, #1
	strh r0, [r1]
	b .L08130132
.L0812FCA6:
	subs r0, r1, #1
	strh r0, [r6]
	b .L0813013A
.L0812FCAC:
	ldrh r0, [r6]
	cmp r0, #1
	bhi .L0812FCD0
	ldr r1, .L0812FCCC
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #1
	bgt .L0812FCC0
	b .L08130146
.L0812FCC0:
	subs r0, r2, #2
	strh r0, [r1]
	mov r4, ip
	ldrh r0, [r4]
	b .L08130136
	.byte 0x00, 0x00
.L0812FCCC: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FCD0:
	subs r0, #2
	strh r0, [r6]
	b .L0813013A
.L0812FCD6:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne .L0812FCE0
	b .L0812FFCC
.L0812FCE0:
	mov r5, ip
	movs r0, #0
	ldrsh r3, [r5, r0]
	cmp r3, #0
	bne .L0812FD5A
	ldr r0, .L0812FD28
	movs r1, #0
	ldrsh r4, [r0, r1]
	cmp r4, #2
	ble .L0812FD46
	ldrh r1, [r6]
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #3
	bne .L0812FD40
	ldr r2, .L0812FD2C
	ldr r5, .L0812FD30
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r7, #0
	ldrsh r1, [r6, r7]
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FD34
	cmp r1, r0
	bne .L0812FD38
	cmp r4, #3
	beq .L0812FD20
	b .L08130146
.L0812FD20:
	strh r3, [r6]
	mov r1, ip
	ldrh r0, [r1]
	b .L08130136
.L0812FD28: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FD2C: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FD30: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FD34: .4byte 0x0000FFFF
.L0812FD38:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b .L08130132
.L0812FD40:
	adds r0, r1, #1
	strh r0, [r6]
	b .L0813013A
.L0812FD46:
	ldrh r1, [r6]
	movs r5, #0
	ldrsh r0, [r6, r5]
	cmp r0, r4
	bne .L0812FD54
	strh r3, [r6]
	b .L0813013A
.L0812FD54:
	adds r0, r1, #1
	strh r0, [r6]
	b .L0813013A
.L0812FD5A:
	cmp r3, #1
	beq .L0812FD62
	cmp r3, #4
	bne .L0812FDE4
.L0812FD62:
	ldr r0, .L0812FDA8
	movs r1, #0
	ldrsh r4, [r0, r1]
	cmp r4, #1
	ble .L0812FDCA
	ldrh r1, [r6]
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #2
	bne .L0812FDC4
	ldr r5, .L0812FDAC
	mov r8, r5
	ldr r5, .L0812FDB0
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r2, #0
	ldrsh r1, [r6, r2]
	adds r0, r0, r1
	adds r0, #1
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r0]
	ldr r0, .L0812FDB4
	cmp r1, r0
	bne .L0812FDB8
	cmp r3, #1
	beq .L0812FD9E
	cmp r3, #4
	beq .L0812FD9E
	b .L08130146
.L0812FD9E:
	cmp r4, #2
	beq .L0812FDA4
	b .L08130146
.L0812FDA4:
	strh r7, [r6]
	b .L0813013A
.L0812FDA8: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FDAC: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FDB0: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FDB4: .4byte 0x0000FFFF
.L0812FDB8:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	mov r3, ip
	ldrh r0, [r3]
	b .L08130136
.L0812FDC4:
	adds r0, r1, #1
	strh r0, [r6]
	b .L0813013A
.L0812FDCA:
	ldrh r1, [r6]
	movs r5, #0
	ldrsh r0, [r6, r5]
	cmp r0, r4
	bne .L0812FDDE
	cmp r3, #1
	beq .L0812FDDA
	b .L08130146
.L0812FDDA:
	strh r7, [r6]
	b .L0813013A
.L0812FDDE:
	adds r0, r1, #1
	strh r0, [r6]
	b .L0813013A
.L0812FDE4:
	cmp r3, #2
	bne .L0812FED4
	ldr r0, .L0812FE28
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #6
	ble .L0812FEA2
	ldrh r5, [r6]
	movs r0, #0
	ldrsh r3, [r6, r0]
	cmp r3, #5
	ble .L0812FE58
	ldr r4, .L0812FE2C
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, #0xf
	ble .L0812FE0C
	b .L08130146
.L0812FE0C:
	ldr r7, .L0812FE30
	adds r0, r1, #2
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	ldr r0, .L0812FE34
	cmp r2, r0
	beq .L0812FE38
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
	mov r1, ip
	ldrh r0, [r1]
	b .L08130136
.L0812FE28: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FE2C: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FE30: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FE34: .4byte 0x0000FFFF
.L0812FE38:
	cmp r3, #7
	beq .L0812FE3E
	b .L08130146
.L0812FE3E:
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, r2
	bne .L0812FE4C
	b .L08130146
.L0812FE4C:
	subs r0, r5, #1
	strh r0, [r6]
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
	b .L08130132
.L0812FE58:
	ldr r4, .L0812FE7C
	ldr r0, .L0812FE80
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r2, #0
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	adds r0, r1, #2
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r2, [r0]
	ldr r0, .L0812FE84
	cmp r2, r0
	beq .L0812FE88
	adds r0, r5, #2
	strh r0, [r6]
	b .L0813013A
	.byte 0x00, 0x00
.L0812FE7C: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FE80: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FE84: .4byte 0x0000FFFF
.L0812FE88:
	cmp r3, #7
	beq .L0812FE8E
	b .L08130146
.L0812FE8E:
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r2
	bne .L0812FE9C
	b .L08130146
.L0812FE9C:
	adds r0, r5, #1
	strh r0, [r6]
	b .L0813013A
.L0812FEA2:
	ldr r2, .L0812FEC8
	ldr r0, .L0812FECC
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #0
	ldrsh r1, [r6, r4]
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FED0
	cmp r1, r0
	bne .L0812FEC0
	b .L08130146
.L0812FEC0:
	ldrh r0, [r6]
	adds r0, #2
	strh r0, [r6]
	b .L0813013A
.L0812FEC8: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FECC: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FED0: .4byte 0x0000FFFF
.L0812FED4:
	cmp r3, #3
	beq .L0812FEDA
	b .L08130146
.L0812FEDA:
	ldr r0, .L0812FF1C
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #4
	ble .L0812FF9A
	ldrh r5, [r6]
	movs r7, #0
	ldrsh r3, [r6, r7]
	cmp r3, #3
	ble .L0812FF50
	ldr r4, .L0812FF20
	movs r0, #0
	ldrsh r1, [r4, r0]
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, #0xf
	ble .L0812FEFE
	b .L08130146
.L0812FEFE:
	ldr r7, .L0812FF24
	adds r0, r1, #2
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	ldr r0, .L0812FF28
	cmp r2, r0
	beq .L0812FF2C
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
	mov r3, ip
	ldrh r0, [r3]
	b .L08130136
	.byte 0x00, 0x00
.L0812FF1C: .4byte 0x03006604 @ IWRAM+0x6604
.L0812FF20: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FF24: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FF28: .4byte 0x0000FFFF
.L0812FF2C:
	cmp r3, #5
	beq .L0812FF32
	b .L08130146
.L0812FF32:
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, r2
	bne .L0812FF40
	b .L08130146
.L0812FF40:
	subs r0, r5, #1
	strh r0, [r6]
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
	mov r4, ip
	ldrh r0, [r4]
	b .L08130136
.L0812FF50:
	ldr r4, .L0812FF74
	ldr r0, .L0812FF78
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r2, #0
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	adds r0, r1, #2
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r2, [r0]
	ldr r0, .L0812FF7C
	cmp r2, r0
	beq .L0812FF80
	adds r0, r5, #2
	strh r0, [r6]
	b .L0813013A
	.byte 0x00, 0x00
.L0812FF74: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FF78: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FF7C: .4byte 0x0000FFFF
.L0812FF80:
	cmp r3, #5
	beq .L0812FF86
	b .L08130146
.L0812FF86:
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r2
	bne .L0812FF94
	b .L08130146
.L0812FF94:
	adds r0, r5, #1
	strh r0, [r6]
	b .L0813013A
.L0812FF9A:
	ldr r2, .L0812FFC0
	ldr r0, .L0812FFC4
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #0
	ldrsh r1, [r6, r4]
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, .L0812FFC8
	cmp r1, r0
	bne .L0812FFB8
	b .L08130146
.L0812FFB8:
	ldrh r0, [r6]
	adds r0, #2
	strh r0, [r6]
	b .L0813013A
.L0812FFC0: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0812FFC4: .4byte 0x03006940 @ IWRAM+0x6940
.L0812FFC8: .4byte 0x0000FFFF
.L0812FFCC:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L08130028
	mov r5, ip
	ldrh r0, [r5]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L0812FFE4
	b .L08130146
.L0812FFE4:
	ldrh r2, [r6]
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r0, #1
	beq .L0812FFFA
	cmp r0, #3
	beq .L0812FFFA
	cmp r0, #5
	beq .L0812FFFA
	cmp r0, #7
	bne .L08130002
.L0812FFFA:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	b .L0813013A
.L08130002:
	ldr r0, .L08130020
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0
	ldrsh r0, [r6, r4]
	adds r1, r1, r0
	ldr r0, .L08130024
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	blt .L0813001A
	b .L08130146
.L0813001A:
	adds r0, r2, #1
	strh r0, [r6]
	b .L0813013A
.L08130020: .4byte 0x03006940 @ IWRAM+0x6940
.L08130024: .4byte 0x03006604 @ IWRAM+0x6604
.L08130028:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L08130082
	mov r7, ip
	ldrh r0, [r7]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L08130040
	b .L08130146
.L08130040:
	ldrh r0, [r6]
	movs r2, #0
	ldrsh r1, [r6, r2]
	cmp r1, #0
	beq .L08130056
	cmp r1, #2
	beq .L08130056
	cmp r1, #4
	beq .L08130056
	cmp r1, #6
	bne .L0813007C
.L08130056:
	ldr r0, .L08130074
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0
	ldrsh r0, [r6, r4]
	adds r1, r1, r0
	ldr r0, .L08130078
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	bge .L08130146
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	b .L0813013A
.L08130074: .4byte 0x03006940 @ IWRAM+0x6940
.L08130078: .4byte 0x03006604 @ IWRAM+0x6604
.L0813007C:
	subs r0, #1
	strh r0, [r6]
	b .L0813013A
.L08130082:
	ldr r3, .L081300C4
	ldrh r1, [r3]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L081300E0
	mov r6, r8
	strh r2, [r6, #0x1c]
	movs r0, #0x65
	bl Sound_Play
	ldr r3, .L081300C8
	ldr r2, .L081300CC
	ldr r0, .L081300D0
	movs r7, #0
	ldrsh r0, [r0, r7]
	ldr r1, .L081300D4
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r3]
	ldr r1, .L081300D8
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0x18
	bne .L081300DC
	movs r0, #0x19
	b .L08130144
	.byte 0x00, 0x00
.L081300C4: .4byte 0x030031C4 @ IWRAM+0x31C4
.L081300C8: .4byte 0x030065E0 @ IWRAM+0x65E0
.L081300CC: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L081300D0: .4byte 0x03006940 @ IWRAM+0x6940
.L081300D4: .4byte 0x0300696C @ IWRAM+0x696C
.L081300D8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L081300DC:
	movs r0, #0xe
	b .L08130144
.L081300E0:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08130146
	ldr r0, .L0813010C
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08130146
	mov r6, r8
	strh r2, [r6, #0x1c]
	movs r0, #0x66
	bl Sound_Play
	ldr r1, .L08130110
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #0x18
	bne .L08130142
	movs r0, #0x37
	b .L08130144
	.byte 0x00, 0x00
.L0813010C: .4byte 0x03006670 @ IWRAM+0x6670
.L08130110: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08130114:
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	ldrh r0, [r7]
	adds r0, #2
	strh r0, [r7]
	mov r1, ip
	ldrh r0, [r1]
	b .L08130136
.L08130126:
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	ldrh r0, [r7]
	adds r0, #2
	strh r0, [r7]
.L08130132:
	mov r2, ip
	ldrh r0, [r2]
.L08130136:
	bl sub_0812F2B4
.L0813013A:
	movs r0, #0x64
	bl Sound_Play
	b .L08130146
.L08130142:
	movs r0, #0x1c
.L08130144:
	strh r0, [r1]
.L08130146:
	bl sub_0812F010
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
