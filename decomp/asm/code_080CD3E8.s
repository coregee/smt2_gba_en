	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080CD3E8
sub_080CD3E8: @ 0x080CD3E8
.L080CD3E8:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	mov sb, r6
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	mov r8, r5
	adds r7, r4, #0
	adds r7, #0x10
	bl Item_GetRecord
	ldrb r0, [r0, #3]
	adds r1, r0, #0
	cmp r0, #0xf
	bne .L080CD420
	ldr r0, .L080CD41C
	adds r1, r4, #0
	b .L080CD42E
	.byte 0x00, 0x00
.L080CD41C: .4byte gUnknown_084F0320
.L080CD420:
	cmp r0, #1
	bhi .L080CD43C
	lsls r0, r0, #2
	ldr r1, .L080CD438
	adds r0, r0, r1
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
.L080CD42E:
	adds r2, r6, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	b .L080CD44C
.L080CD438: .4byte gUnknown_084F02DE
.L080CD43C:
	lsls r0, r1, #2
	ldr r1, .L080CD458
	adds r0, r0, r1
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl sub_080CCEC8
.L080CD44C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CD458: .4byte gUnknown_084F02DE

	thumb_func_start sub_080CD45C
sub_080CD45C: @ 0x080CD45C
.L080CD45C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r7, r5, #0
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	mov r8, r6
	adds r4, r5, #0
	adds r4, #0x10
	movs r1, #1
	mov r2, sp
	bl Item_GetAttribute
	ldr r1, [sp]
	movs r0, #7
	ands r1, r0
	str r1, [sp]
	adds r0, r1, #0
	cmp r0, #1
	bne .L080CD498
	ldr r0, .L080CD494
	lsls r1, r4, #0x10
	b .L080CD4D4
.L080CD494: .4byte gUnknown_084F02C0
.L080CD498:
	cmp r0, #2
	bne .L080CD4A8
	ldr r0, .L080CD4A4
	lsls r1, r4, #0x10
	b .L080CD4D4
	.byte 0x00, 0x00
.L080CD4A4: .4byte gUnknown_084F02C4
.L080CD4A8:
	cmp r0, #4
	bne .L080CD4B8
	ldr r0, .L080CD4B4
	lsls r1, r4, #0x10
	b .L080CD4D4
	.byte 0x00, 0x00
.L080CD4B4: .4byte gUnknown_084F02C8
.L080CD4B8:
	cmp r0, #7
	bne .L080CD4C8
	ldr r0, .L080CD4C4
	adds r1, r5, #0
	b .L080CD4D6
	.byte 0x00, 0x00
.L080CD4C4: .4byte gUnknown_084F0320
.L080CD4C8:
	cmp r0, #3
	bne .L080CD4E4
	ldr r0, .L080CD4E0
	adds r1, r5, #0
	adds r1, #8
	lsls r1, r1, #0x10
.L080CD4D4:
	lsrs r1, r1, #0x10
.L080CD4D6:
	adds r2, r6, #0
	movs r3, #4
	bl sub_080CCEC8
	b .L080CD4FA
.L080CD4E0: .4byte gUnknown_084F0324
.L080CD4E4:
	cmp r1, #6
	bne .L080CD4FA
	ldr r0, .L080CD508
	adds r1, r7, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r2, r8
	movs r3, #4
	bl sub_080CCEC8
.L080CD4FA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CD508: .4byte gUnknown_084F0328

	thumb_func_start sub_080CD50C
sub_080CD50C: @ 0x080CD50C
.L080CD50C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	adds r6, r5, #0
	adds r6, #8
	movs r1, #0x10
	adds r1, r1, r5
	mov r8, r1
	adds r7, r5, #0
	adds r7, #0x18
	bl Item_GetRecord
	adds r2, r0, #0
	adds r2, #8
	ldrh r1, [r0, #8]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080CD54C
	ldr r0, .L080CD548
	mov r2, r8
	lsls r1, r2, #0x10
	b .L080CD63C
.L080CD548: .4byte gUnknown_084F0194
.L080CD54C:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq .L080CD560
	ldr r0, .L080CD55C
	b .L080CD63A
	.byte 0x00, 0x00
.L080CD55C: .4byte gUnknown_084F00F0
.L080CD560:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	beq .L080CD574
	ldr r0, .L080CD570
	adds r1, r5, #0
	b .L080CD63E
.L080CD570: .4byte gUnknown_084F00F8
.L080CD574:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L080CD588
	ldr r0, .L080CD584
	adds r1, r5, #0
	b .L080CD63E
	.byte 0x00, 0x00
.L080CD584: .4byte gUnknown_084F0100
.L080CD588:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L080CD59C
	ldr r0, .L080CD598
	lsls r1, r7, #0x10
	b .L080CD63C
.L080CD598: .4byte gUnknown_084F0108
.L080CD59C:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	beq .L080CD5B0
	ldr r0, .L080CD5AC
	adds r1, r5, #0
	b .L080CD63E
.L080CD5AC: .4byte gUnknown_084F010C
.L080CD5B0:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CD5C4
	ldr r0, .L080CD5C0
	b .L080CD63A
	.byte 0x00, 0x00
.L080CD5C0: .4byte gUnknown_084F011C
.L080CD5C4:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080CD5D4
	ldr r0, .L080CD5D0
	b .L080CD63A
.L080CD5D0: .4byte gUnknown_084F0124
.L080CD5D4:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080CD5E8
	ldr r0, .L080CD5E4
	mov r2, r8
	lsls r1, r2, #0x10
	b .L080CD63C
.L080CD5E4: .4byte gUnknown_084F012C
.L080CD5E8:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080CD5FC
	ldr r0, .L080CD5F8
	adds r1, r5, #0
	b .L080CD63E
.L080CD5F8: .4byte gUnknown_084F0134
.L080CD5FC:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080CD610
	ldr r0, .L080CD60C
	b .L080CD63A
	.byte 0x00, 0x00
.L080CD60C: .4byte gUnknown_084F013C
.L080CD610:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CD620
	ldr r0, .L080CD61C
	b .L080CD63A
.L080CD61C: .4byte gUnknown_084F0144
.L080CD620:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080CD630
	ldr r0, .L080CD62C
	b .L080CD63A
.L080CD62C: .4byte gUnknown_084F014C
.L080CD630:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080CD64C
	ldr r0, .L080CD648
.L080CD63A:
	lsls r1, r6, #0x10
.L080CD63C:
	lsrs r1, r1, #0x10
.L080CD63E:
	adds r2, r4, #0
	movs r3, #4
	bl sub_080CCEC8
	b .L080CD658
.L080CD648: .4byte gUnknown_084F0154
.L080CD64C:
	ldr r0, .L080CD664
	adds r1, r5, #0
	adds r2, r4, #0
	movs r3, #4
	bl sub_080CCEC8
.L080CD658:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CD664: .4byte gUnknown_084F01EC

	thumb_func_start sub_080CD668
sub_080CD668: @ 0x080CD668
.L080CD668:
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r4, r1, #0
	adds r6, r2, #0
	mov r8, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	adds r5, r4, #0
	adds r5, #0x18
	bl Equipment_GetRecord36_MidRange
	ldrb r0, [r0, #1]
	mov sb, r0
	ldr r0, .L080CD6C0
	adds r1, r4, #0
	adds r2, r6, #0
	mov r3, r8
	bl sub_080CCEC8
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov r0, sb
	adds r1, r5, #0
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
.L080CD6C0: .4byte gUnknown_084F02DC

	thumb_func_start sub_080CD6C4
sub_080CD6C4: @ 0x080CD6C4
.L080CD6C4:
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r4, r1, #0
	adds r6, r2, #0
	mov r8, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	adds r5, r4, #0
	adds r5, #0x18
	bl Equipment_GetRecord36_MidRange
	ldrb r0, [r0, #2]
	mov sb, r0
	ldr r0, .L080CD71C
	adds r1, r4, #0
	adds r2, r6, #0
	mov r3, r8
	bl sub_080CCEC8
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov r0, sb
	adds r1, r5, #0
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
.L080CD71C: .4byte gUnknown_084F02DC

	thumb_func_start sub_080CD720
sub_080CD720: @ 0x080CD720
.L080CD720:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	adds r6, r5, #0
	adds r6, #8
	movs r1, #0x10
	adds r1, r1, r5
	mov r8, r1
	adds r7, r5, #0
	adds r7, #0x18
	bl Equipment_GetRecord36_MidRange
	adds r2, r0, #0
	adds r2, #8
	ldrh r1, [r0, #8]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080CD760
	ldr r0, .L080CD75C
	mov r2, r8
	lsls r1, r2, #0x10
	b .L080CD850
.L080CD75C: .4byte gUnknown_084F0194
.L080CD760:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq .L080CD774
	ldr r0, .L080CD770
	b .L080CD84E
	.byte 0x00, 0x00
.L080CD770: .4byte gUnknown_084F00F0
.L080CD774:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	beq .L080CD788
	ldr r0, .L080CD784
	adds r1, r5, #0
	b .L080CD852
.L080CD784: .4byte gUnknown_084F00F8
.L080CD788:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L080CD79C
	ldr r0, .L080CD798
	adds r1, r5, #0
	b .L080CD852
	.byte 0x00, 0x00
.L080CD798: .4byte gUnknown_084F0100
.L080CD79C:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L080CD7B0
	ldr r0, .L080CD7AC
	lsls r1, r7, #0x10
	b .L080CD850
.L080CD7AC: .4byte gUnknown_084F0108
.L080CD7B0:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	beq .L080CD7C4
	ldr r0, .L080CD7C0
	adds r1, r5, #0
	b .L080CD852
.L080CD7C0: .4byte gUnknown_084F010C
.L080CD7C4:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CD7D8
	ldr r0, .L080CD7D4
	b .L080CD84E
	.byte 0x00, 0x00
.L080CD7D4: .4byte gUnknown_084F011C
.L080CD7D8:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080CD7E8
	ldr r0, .L080CD7E4
	b .L080CD84E
.L080CD7E4: .4byte gUnknown_084F0124
.L080CD7E8:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080CD7FC
	ldr r0, .L080CD7F8
	mov r2, r8
	lsls r1, r2, #0x10
	b .L080CD850
.L080CD7F8: .4byte gUnknown_084F012C
.L080CD7FC:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080CD810
	ldr r0, .L080CD80C
	adds r1, r5, #0
	b .L080CD852
.L080CD80C: .4byte gUnknown_084F0134
.L080CD810:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080CD824
	ldr r0, .L080CD820
	b .L080CD84E
	.byte 0x00, 0x00
.L080CD820: .4byte gUnknown_084F013C
.L080CD824:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CD834
	ldr r0, .L080CD830
	b .L080CD84E
.L080CD830: .4byte gUnknown_084F0144
.L080CD834:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080CD844
	ldr r0, .L080CD840
	b .L080CD84E
.L080CD840: .4byte gUnknown_084F014C
.L080CD844:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080CD860
	ldr r0, .L080CD85C
.L080CD84E:
	lsls r1, r6, #0x10
.L080CD850:
	lsrs r1, r1, #0x10
.L080CD852:
	adds r2, r4, #0
	movs r3, #4
	bl sub_080CCEC8
	b .L080CD86C
.L080CD85C: .4byte gUnknown_084F0154
.L080CD860:
	ldr r0, .L080CD878
	adds r1, r5, #0
	adds r2, r4, #0
	movs r3, #4
	bl sub_080CCEC8
.L080CD86C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CD878: .4byte gUnknown_084F01EC

	thumb_func_start sub_080CD87C
sub_080CD87C: @ 0x080CD87C
.L080CD87C:
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	bl Equipment_GetRecord36_MidRange
	ldrb r1, [r0, #3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	ldr r1, .L080CD8BC
	adds r0, r0, r1
	ldr r1, .L080CD8C0
	movs r2, #4
	str r2, [sp]
	movs r2, #0xc
	str r2, [sp, #4]
	adds r2, r4, #0
	adds r3, r5, #0
	bl Text_DrawStringTinted
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CD8BC: .4byte gUnknown_084F032C
.L080CD8C0: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080CD8C4
sub_080CD8C4: @ 0x080CD8C4
.L080CD8C4:
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	bl Equipment_GetRecord36_MidRange
	ldrb r1, [r0, #3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, .L080CD904
	adds r0, r0, r1
	ldr r1, .L080CD908
	movs r2, #4
	str r2, [sp]
	movs r2, #0xc
	str r2, [sp, #4]
	adds r2, r4, #0
	adds r3, r5, #0
	bl Text_DrawStringTinted
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CD904: .4byte gUnknown_084F06D6
.L080CD908: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080CD90C
sub_080CD90C: @ 0x080CD90C
.L080CD90C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r4, [sp, #0x30]
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0xc]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sl, r2
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	cmp r7, #0
	beq .L080CD9B2
	lsrs r6, r0, #0x13
	movs r0, #7
	mov sb, r0
	mov r1, sb
	ands r1, r7
	mov sb, r1
	cmp r6, #0
	beq .L080CD982
	movs r4, #0
	cmp r4, r6
	bhs .L080CD982
	ldr r2, [sp, #0xc]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r2, r3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L080CD95A:
	str r7, [sp]
	str r5, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	ldr r1, .L080CD9C4
	ldr r0, [r1, #0x1c]
	movs r1, #1
	mov r2, sl
	movs r3, #1
	bl Sprite_Draw
	adds r0, r5, #0
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r6
	blo .L080CD95A
.L080CD982:
	mov r2, sb
	cmp r2, #0
	beq .L080CD9B2
	ldr r1, .L080CD9C4
	mov r0, sb
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r3, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	str r5, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	movs r1, #1
	mov r2, sl
	movs r3, #1
	bl Sprite_Draw
.L080CD9B2:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CD9C4: .4byte gUnknown_084F0974

	thumb_func_start sub_080CD9C8
sub_080CD9C8: @ 0x080CD9C8
.L080CD9C8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	adds r5, r1, #0
	adds r6, r2, #0
	mov sl, r3
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldr r1, .L080CDA10
	movs r7, #0
	movs r0, #0xff
	mov r2, r8
	ands r2, r0
	mov r8, r2
	ands r5, r0
	ands r6, r0
	mov r2, sl
	ands r2, r0
	mov sl, r2
	ldrh r0, [r1, #0x1a]
	cmp r0, #0
	bne .L080CDA18
	ldr r0, .L080CDA14
	ldrh r0, [r0]
	mov sb, r0
	b .L080CDA1C
	.byte 0x00, 0x00
.L080CDA10: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CDA14: .4byte 0x03000004 @ IWRAM+0x4
.L080CDA18:
	ldrh r1, [r1, #0x1a]
	mov sb, r1
.L080CDA1C:
	mov r0, sb
	subs r3, r4, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r1, [sp, #4]
	str r1, [sp]
	mov r0, r8
	movs r1, #0
	movs r2, #0
	bl sub_080CD90C
	mov r2, r8
	adds r0, r4, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r7, r2
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r7, r5
	cmp r0, #0x28
	ble .L080CDA4E
	movs r0, #0x28
	subs r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080CDA4E:
	ldr r0, .L080CDADC
	mov r8, r0
	mov r1, sb
	subs r3, r4, r1
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r2, [sp, #4]
	str r2, [sp]
	adds r0, r5, #0
	movs r1, #0
	mov r2, r8
	bl sub_080CD90C
	adds r0, r4, r5
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r7, r5
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r7, r6
	cmp r0, #0x28
	ble .L080CDA82
	movs r0, #0x28
	subs r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080CDA82:
	ldr r2, .L080CDAE0
	mov r0, sb
	subs r3, r4, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r1, [sp, #4]
	str r1, [sp]
	adds r0, r6, #0
	movs r1, #0
	bl sub_080CD90C
	adds r0, r4, r6
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r7, r6
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r2, sl
	adds r0, r7, r2
	cmp r0, #0x28
	ble .L080CDAB6
	movs r0, #0x28
	subs r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
.L080CDAB6:
	mov r0, sb
	subs r3, r4, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r1, [sp, #4]
	str r1, [sp]
	mov r0, sl
	movs r1, #0x20
	mov r2, r8
	bl sub_080CD90C
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CDADC: .4byte 0x0000FFF9
.L080CDAE0: .4byte 0x0000FFF8

	thumb_func_start sub_080CDAE4
sub_080CDAE4: @ 0x080CDAE4
.L080CDAE4:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r1, #0x80
	beq .L080CDB00
	cmp r1, #0x80
	bgt .L080CDAF8
	cmp r1, #0x40
	beq .L080CDB08
	b .L080CDB10
.L080CDAF8:
	cmp r1, #0xc0
	bne .L080CDB10
	movs r0, #1
	b .L080CDB12
.L080CDB00:
	cmp r0, #0
	bne .L080CDB10
	movs r0, #1
	b .L080CDB12
.L080CDB08:
	cmp r0, #1
	bne .L080CDB10
	movs r0, #1
	b .L080CDB12
.L080CDB10:
	movs r0, #0
.L080CDB12:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080CDB18
sub_080CDB18: @ 0x080CDB18
.L080CDB18:
	push {lr}
	adds r2, r0, #0
	subs r0, r1, #1
	cmp r0, #6
	bhi .L080CDB6C
	lsls r0, r0, #2
	ldr r1, .L080CDB2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080CDB2C: .4byte gUnknown_080CDB30
	.global gUnknown_080CDB30
gUnknown_080CDB30:
.L080CDB30: @ jump table
	.4byte .L080CDB4C
	.4byte .L080CDB54
	.4byte .L080CDB60
	.4byte .L080CDB5A
	.4byte .L080CDB6C
	.4byte .L080CDB66
	.4byte .L080CDB50
.L080CDB4C:
	cmp r2, #0
	bne .L080CDB6C
.L080CDB50:
	movs r0, #1
	b .L080CDB6E
.L080CDB54:
	cmp r2, #1
	bne .L080CDB6C
	b .L080CDB50
.L080CDB5A:
	cmp r2, #2
	bne .L080CDB6C
	b .L080CDB50
.L080CDB60:
	cmp r2, #1
	bhi .L080CDB6C
	b .L080CDB50
.L080CDB66:
	subs r0, r2, #1
	cmp r0, #1
	bls .L080CDB50
.L080CDB6C:
	movs r0, #0
.L080CDB6E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080CDB74
sub_080CDB74: @ 0x080CDB74
.L080CDB74:
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	lsls r4, r1, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #0
	mov r2, sp
	bl Item_GetAttribute
	add r2, sp, #4
	adds r0, r4, #0
	movs r1, #1
	bl Item_GetAttribute
	adds r0, r5, #0
	bl sub_080C07FC
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	bl sub_080C06BC
	adds r5, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r1, [sp]
	adds r0, r4, #0
	bl sub_080CDAE4
	cmp r0, #1
	bne .L080CDBCA
	ldr r1, [sp, #4]
	movs r0, #7
	ands r1, r0
	adds r0, r5, #0
	bl sub_080CDB18
	cmp r0, #1
	bne .L080CDBCA
	movs r0, #1
	b .L080CDBCC
.L080CDBCA:
	movs r0, #0
.L080CDBCC:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080CDBD4
sub_080CDBD4: @ 0x080CDBD4
.L080CDBD4:
	ldr r0, .L080CDBE4
	movs r2, #0
	movs r1, #1
	strh r1, [r0, #4]
	strh r2, [r0, #6]
	strh r2, [r0, #8]
	strh r2, [r0, #0x30]
	bx lr
.L080CDBE4: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CDBE8
sub_080CDBE8: @ 0x080CDBE8
.L080CDBE8:
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r6, .L080CDC24
	ldrh r0, [r6, #2]
	bl sub_080C92C8
	mov r1, sp
	ldr r2, .L080CDC28
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080CDC2C
	ldr r2, .L080CDC30
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
.L080CDC24: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CDC28: .4byte 0x0000FFFF
.L080CDC2C: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080CDC30: .4byte 0x01000080

	thumb_func_start sub_080CDC34
sub_080CDC34: @ 0x080CDC34
.L080CDC34:
	push {lr}
	movs r1, #0
	movs r2, #0xa0
	lsls r2, r2, #7
	ldr r0, .L080CDC50
.L080CDC3E:
	strh r2, [r0]
	strh r2, [r0, #2]
	adds r0, #4
	adds r1, #1
	cmp r1, #5
	bls .L080CDC3E
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CDC50: .4byte 0x0200F7D8 @ EWRAM+0xF7D8

	thumb_func_start sub_080CDC54
sub_080CDC54: @ 0x080CDC54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r5, .L080CDD04
	ldrh r0, [r5, #2]
	bl sub_080C92C8
	adds r4, r0, #0
	movs r0, #0
	bl sub_080C964C
	adds r7, r0, #0
	movs r0, #0
	mov sb, r0
	mov r1, sb
	strh r1, [r6, #0x1e]
	ldr r2, .L080CDD08
	ldrh r1, [r2]
	movs r3, #1
	mov sl, r3
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq .L080CDD78
	ldrh r1, [r5, #0x30]
	adds r0, r4, #0
	bl sub_080C343C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #0x65
	bl sub_080C51D4
	mov r0, sb
	strh r0, [r5, #0x2c]
	strh r0, [r5, #0x2e]
	ldr r2, .L080CDD0C
	ldrh r1, [r5, #0x30]
	lsls r1, r1, #2
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r2, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	bl sub_080CDBE8
	mov r1, r8
	cmp r1, #0xff
	beq .L080CDD10
	mov r0, r8
	bl sub_080D2268
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r0, r8
	movs r1, #6
	add r2, sp, #4
	bl Item_GetAttribute
	ldr r0, [sp, #4]
	mov r3, sl
	ands r0, r3
	cmp r0, #0
	beq .L080CDD10
	cmp r7, #6
	beq .L080CDD10
	movs r0, #4
	strh r0, [r6, #0x1e]
	mov r0, sb
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #7
	bl Window_CreateOpen
	str r0, [r5, #0x50]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	b .L080CDE74
	.byte 0x00, 0x00
.L080CDD04: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CDD08: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CDD0C: .4byte gUnknown_084F0994
.L080CDD10:
	ldrh r0, [r5, #0x28]
	cmp r0, #0
	bne .L080CDD6E
	ldrb r0, [r4, #0xc]
	ldrh r1, [r5, #0x30]
	bl sub_080CDFD0
	bl sub_080CDC34
	ldrb r0, [r4, #0xc]
	bl sub_080BF938
	ldrh r2, [r4, #0x1a]
	movs r3, #0x1a
	ldrsh r1, [r4, r3]
	movs r3, #0x18
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge .L080CDD38
	strh r2, [r4, #0x18]
.L080CDD38:
	movs r0, #0xff
	mov r1, r8
	ands r0, r1
	cmp r0, #0xff
	beq .L080CDD48
	mov r0, r8
	bl sub_080C3328
.L080CDD48:
	adds r0, r6, #0
	bl sub_080C9CD8
	adds r0, r6, #0
	bl sub_080C9BCC
	adds r0, r6, #0
	bl sub_080C9D5C
	adds r0, r6, #0
	bl sub_080C9D00
	adds r0, r6, #0
	bl sub_080C9E08
	adds r0, r6, #0
	bl sub_080C9D84
	b .L080CDE5A
.L080CDD6E:
	ldr r0, .L080CDD74
	strh r0, [r6, #0x1e]
	b .L080CDE74
.L080CDD74: .4byte 0x00008001
.L080CDD78:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CDD8E
	movs r0, #0x66
	bl sub_080C51D4
	movs r0, #3
	strh r0, [r6, #0x1e]
	b .L080CDE5A
.L080CDD8E:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CDDC8
	ldrh r0, [r5, #0x22]
	cmp r0, #0
	bne .L080CDDC8
	movs r0, #0
	bl sub_080C964C
	cmp r0, #1
	beq .L080CDDC8
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r5, #2]
	cmp r0, #0
	beq .L080CDDBA
	subs r0, #1
	b .L080CDDBC
.L080CDDBA:
	subs r0, r7, #1
.L080CDDBC:
	strh r0, [r5, #2]
	ldr r0, .L080CDDC4
	b .L080CDE04
	.byte 0x00, 0x00
.L080CDDC4: .4byte 0x0000FFF0
.L080CDDC8:
	ldr r0, .L080CDDFC
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080CDE10
	ldrh r4, [r5, #0x22]
	cmp r4, #0
	bne .L080CDE10
	movs r0, #0
	bl sub_080C964C
	cmp r0, #1
	beq .L080CDE10
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r1, [r5, #2]
	subs r0, r7, #1
	cmp r1, r0
	beq .L080CDE00
	adds r0, r1, #1
	strh r0, [r5, #2]
	b .L080CDE02
	.byte 0x00, 0x00
.L080CDDFC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CDE00:
	strh r4, [r5, #2]
.L080CDE02:
	movs r0, #0x10
.L080CDE04:
	strh r0, [r5, #0xa]
	movs r0, #2
	strh r0, [r6, #0x1e]
	bl sub_080CDBD4
	b .L080CDE5A
.L080CDE10:
	ldr r0, .L080CDE34
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L080CDE3E
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r5, #0x30]
	cmp r0, #0
	beq .L080CDE38
	subs r0, #1
	strh r0, [r5, #0x30]
	b .L080CDE5A
	.byte 0x00, 0x00
.L080CDE34: .4byte 0x03003964 @ IWRAM+0x3964
.L080CDE38:
	movs r0, #6
	strh r0, [r5, #0x30]
	b .L080CDE5A
.L080CDE3E:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080CDE5A
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r5, #0x30]
	cmp r0, #6
	beq .L080CDE58
	adds r0, #1
	strh r0, [r5, #0x30]
	b .L080CDE5A
.L080CDE58:
	strh r4, [r5, #0x30]
.L080CDE5A:
	ldrh r1, [r5, #0x30]
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r0, #0x13
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0xf
	movs r1, #3
	movs r2, #2
	movs r3, #0xa
	bl sub_080C49EC
.L080CDE74:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080CDE84
sub_080CDE84: @ 0x080CDE84
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r2, .L080CDEDC
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldr r0, .L080CDEE0
	ldrh r1, [r0]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CDEA8
	ldr r0, [r2, #0x50]
	movs r1, #1
	bl Window_Close
	strh r5, [r4, #0x1c]
.L080CDEA8:
	ldr r0, .L080CDEE4
	movs r1, #0x5b
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	ldr r0, .L080CDEE8
	ldr r0, [r0]
	lsrs r0, r0, #4
	ands r0, r5
	cmp r0, #0
	bne .L080CDED4
	movs r0, #0
	movs r1, #0
	movs r2, #0xd5
	movs r3, #0x85
	bl sub_080C4AB0
.L080CDED4:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
.L080CDEDC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CDEE0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CDEE4: .4byte gUnknown_084F09B0
.L080CDEE8: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_080CDEEC
sub_080CDEEC: @ 0x080CDEEC
.L080CDEEC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	movs r1, #0x80
	lsls r1, r1, #8
	adds r4, r1, #0
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r6, r0, #0
	adds r0, r5, #0
	ands r0, r4
	cmp r0, #0
	beq .L080CDF20
	movs r0, #0xff
	ands r5, r0
.L080CDF20:
	adds r0, r5, #0
	bl sub_080D2268
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080C343C
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r5, #0
	movs r1, #6
	mov r2, sp
	bl Item_GetAttribute
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080CDF58
	cmp r4, #6
	beq .L080CDF58
	ldrb r0, [r6, #0xc]
	bl sub_080C08E8
	bl sub_080C84A0
.L080CDF58:
	cmp r5, r7
	bne .L080CDF7A
	mov r3, r8
	cmp r3, #0
	bne .L080CDF7A
	ldrb r0, [r6, #0xc]
	adds r1, r4, #0
	bl sub_080CDFD0
	movs r0, #0xff
	ands r0, r7
	cmp r0, #0xff
	beq .L080CDF98
	adds r0, r7, #0
	bl sub_080C3328
	b .L080CDF98
.L080CDF7A:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl sub_080C34B0
	adds r0, r5, #0
	bl sub_080C33AC
	movs r0, #0xff
	ands r0, r7
	cmp r0, #0xff
	beq .L080CDF98
	adds r0, r7, #0
	bl sub_080C3328
.L080CDF98:
	ldrb r0, [r6, #0xc]
	bl sub_080BF938
	ldrh r2, [r6, #0x1a]
	movs r0, #0x1a
	ldrsh r1, [r6, r0]
	movs r3, #0x18
	ldrsh r0, [r6, r3]
	cmp r1, r0
	bge .L080CDFAE
	strh r2, [r6, #0x18]
.L080CDFAE:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CDFBC
sub_080CDFBC: @ 0x080CDFBC
.L080CDFBC:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #1
	bl sub_080CDEEC
	pop {r0}
	bx r0

	thumb_func_start sub_080CDFD0
sub_080CDFD0: @ 0x080CDFD0
.L080CDFD0:
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl sub_080C0148
	ldr r2, .L080CDFF4
	adds r1, r4, #0
	bl sub_080C34B0
	pop {r4}
	pop {r0}
	bx r0
.L080CDFF4: .4byte 0x0000FFFF

	thumb_func_start sub_080CDFF8
sub_080CDFF8: @ 0x080CDFF8
.L080CDFF8:
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r5, r0, #0
	ldrb r0, [r5, #0xc]
	adds r1, r4, #0
	bl sub_080CDFD0
	ldrb r0, [r5, #0xc]
	bl sub_080BF938
	ldrh r2, [r5, #0x1a]
	movs r3, #0x1a
	ldrsh r1, [r5, r3]
	movs r3, #0x18
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bge .L080CE02E
	strh r2, [r5, #0x18]
.L080CE02E:
	bl sub_080CDC34
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080CE038
sub_080CE038: @ 0x080CE038
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r7, .L080CE0C4
	ldrh r0, [r7, #2]
	bl sub_080C92C8
	mov r8, r0
	ldrh r5, [r7, #0x28]
	movs r0, #0
	mov sl, r0
	mov r1, sl
	strh r1, [r6, #0x1e]
	mov sb, r5
	cmp r5, #6
	bls .L080CE064
	movs r0, #7
	mov sb, r0
.L080CE064:
	ldr r2, .L080CE0C8
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080CE0D8
	ldrh r1, [r7, #0x30]
	mov r0, r8
	bl sub_080C343C
	ldr r2, .L080CE0CC
	ldrh r0, [r7, #0x2c]
	ldrh r1, [r7, #0x2e]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r4, [r0]
	ldrh r1, [r7, #0x30]
	mov r0, r8
	bl sub_080C343C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, r0
	beq .L080CE0A6
	mov r1, r8
	ldrb r0, [r1, #0xc]
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	bl sub_080CDB74
	cmp r0, #1
	bne .L080CE0D0
.L080CE0A6:
	movs r0, #0x65
	bl sub_080C51D4
	mov r1, r8
	ldrb r0, [r1, #0xc]
	adds r1, r4, #0
	movs r2, #0
	bl sub_080CDEEC
	bl sub_080CDC34
	movs r0, #2
	strh r0, [r6, #0x1e]
	b .L080CE246
	.byte 0x00, 0x00
.L080CE0C4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CE0C8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CE0CC: .4byte 0x0203B454 @ EWRAM+0x3B454
.L080CE0D0:
	movs r0, #0x66
	bl sub_080C51D4
	b .L080CE246
.L080CE0D8:
	ldrh r1, [r2]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CE0F0
	movs r0, #0x66
	bl sub_080C51D4
	strh r4, [r6, #0x1e]
	subs r4, r5, #1
	b .L080CE1EC
.L080CE0F0:
	ldr r1, .L080CE10C
	ldrh r2, [r1]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L080CE122
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r7, #0x2c]
	cmp r0, #0
	beq .L080CE110
	subs r0, #1
	b .L080CE140
.L080CE10C: .4byte 0x03003964 @ IWRAM+0x3964
.L080CE110:
	ldrh r0, [r7, #0x2e]
	subs r4, r5, #1
	cmp r0, #0
	beq .L080CE1EC
	subs r0, #1
	strh r0, [r7, #0x2e]
	movs r0, #1
	mov sl, r0
	b .L080CE1EC
.L080CE122:
	movs r0, #0x80
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L080CE178
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r1, [r7, #0x2c]
	mov r0, sb
	subs r0, #1
	cmp r1, r0
	beq .L080CE15E
	adds r0, r1, #1
.L080CE140:
	strh r0, [r7, #0x2c]
	adds r0, r6, #0
	bl sub_080C9D5C
	adds r0, r6, #0
	bl sub_080C9D00
	adds r0, r6, #0
	bl sub_080C9E08
	adds r0, r6, #0
	bl sub_080C9D84
	subs r4, r5, #1
	b .L080CE1EC
.L080CE15E:
	subs r4, r5, #1
	cmp r1, #6
	bne .L080CE1EC
	ldrh r2, [r7, #0x2e]
	adds r0, r1, r2
	adds r0, #1
	cmp r0, r4
	bgt .L080CE1EC
	adds r0, r2, #1
	strh r0, [r7, #0x2e]
	movs r1, #1
	mov sl, r1
	b .L080CE1EC
.L080CE178:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080CE1B0
	cmp r5, #7
	bls .L080CE1B0
	movs r0, #0x64
	bl sub_080C51D4
	movs r0, #1
	mov sl, r0
	ldrh r1, [r7, #0x2c]
	cmp r1, #0
	beq .L080CE19C
	strh r4, [r7, #0x2c]
	subs r4, r5, #1
	b .L080CE1EC
.L080CE19C:
	ldrh r0, [r7, #0x2e]
	cmp r0, #5
	bls .L080CE1AA
	subs r0, #6
	strh r0, [r7, #0x2e]
	subs r4, r5, #1
	b .L080CE1EC
.L080CE1AA:
	strh r1, [r7, #0x2e]
	subs r4, r5, #1
	b .L080CE1EC
.L080CE1B0:
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	subs r4, r5, #1
	cmp r0, #0
	beq .L080CE1EC
	cmp r5, #7
	bls .L080CE1EC
	movs r0, #0x64
	bl sub_080C51D4
	movs r1, #1
	mov sl, r1
	ldrh r0, [r7, #0x2c]
	cmp r0, #6
	beq .L080CE1D8
	movs r0, #6
	strh r0, [r7, #0x2c]
	b .L080CE1EC
.L080CE1D8:
	ldrh r0, [r7, #0x2c]
	ldrh r1, [r7, #0x2e]
	adds r0, r0, r1
	adds r0, #7
	cmp r0, r4
	bge .L080CE1E8
	adds r0, r1, #7
	b .L080CE1EA
.L080CE1E8:
	subs r0, r5, #7
.L080CE1EA:
	strh r0, [r7, #0x2e]
.L080CE1EC:
	mov r0, sl
	cmp r0, #1
	bne .L080CE216
	adds r0, r6, #0
	bl sub_080C9CD8
	adds r0, r6, #0
	bl sub_080C9BCC
	adds r0, r6, #0
	bl sub_080C9D5C
	adds r0, r6, #0
	bl sub_080C9D00
	adds r0, r6, #0
	bl sub_080C9E08
	adds r0, r6, #0
	bl sub_080C9D84
.L080CE216:
	ldrh r0, [r7, #0x2c]
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
	ldrh r0, [r7, #0x2e]
	cmp r0, #0
	beq .L080CE23A
	movs r0, #1
	strh r0, [r7, #0x1c]
.L080CE23A:
	ldrh r0, [r7, #0x2e]
	adds r0, #7
	cmp r0, r4
	bgt .L080CE246
	movs r0, #1
	strh r0, [r7, #0x1e]
.L080CE246:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CE258
sub_080CE258: @ 0x080CE258
.L080CE258:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	lsls r5, r1, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080CE298
	ldr r1, .L080CE29C
	bl Task_Create
	mov r8, r0
	ldr r4, .L080CE2A0
	movs r6, #0
	str r6, [sp]
	ldr r2, .L080CE2A4
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	strh r5, [r4, #2]
	movs r0, #1
	strh r0, [r4, #4]
	movs r0, #3
	strh r0, [r4]
	strh r6, [r4, #0x22]
	mov r0, r8
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080CE298: .4byte gUnknown_084F09C8
.L080CE29C: .4byte 0x0000FFFF
.L080CE2A0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CE2A4: .4byte 0x05000200 @ PLTT+0x200

	thumb_func_start sub_080CE2A8
sub_080CE2A8: @ 0x080CE2A8
.L080CE2A8:
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xc]
	movs r1, #0
	bl sub_080C0F64
	cmp r0, #0x28
	bne .L080CE2F8
	ldrb r0, [r4, #0xc]
	movs r1, #1
	bl sub_080C0F64
	cmp r0, #0x28
	bne .L080CE2F8
	ldrb r0, [r4, #0xc]
	movs r1, #2
	bl sub_080C0F64
	cmp r0, #0x28
	bne .L080CE2F8
	ldrb r0, [r4, #0xc]
	movs r1, #3
	bl sub_080C0F64
	cmp r0, #0x28
	bne .L080CE2F8
	ldrb r0, [r4, #0xc]
	movs r1, #4
	bl sub_080C0F64
	cmp r0, #0x28
	bne .L080CE2F8
	ldrb r0, [r4, #0xc]
	movs r1, #5
	bl sub_080C0F64
	cmp r0, #0x28
	bne .L080CE2F8
	movs r0, #0
	b .L080CE2FA
.L080CE2F8:
	movs r0, #1
.L080CE2FA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080CE300
sub_080CE300: @ 0x080CE300
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r4, .L080CE358
	ldrh r0, [r4, #2]
	bl sub_080C92C8
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	mov r1, sb
	strh r1, [r7, #0x1e]
	ldr r0, .L080CE35C
	ldrh r1, [r0]
	movs r0, #1
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	beq .L080CE3A4
	ldrb r0, [r6, #0xc]
	ldrh r1, [r4, #0x2c]
	bl sub_080C0F64
	adds r5, r0, #0
	movs r0, #0xff
	ands r5, r0
	adds r0, r6, #0
	bl sub_080CE2A8
	cmp r0, #0
	bne .L080CE360
	mov r1, r8
	strh r1, [r7, #0x1e]
	movs r0, #0
	bl YesNo_Create
	str r0, [r4, #0x4c]
	mov r0, sb
	str r0, [sp]
	b .L080CE38E
	.byte 0x00, 0x00
.L080CE358: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CE35C: .4byte 0x03003964 @ IWRAM+0x3964
.L080CE360:
	cmp r5, #0x28
	beq .L080CE39C
	ldrb r0, [r6, #0xc]
	ldrh r1, [r4, #0x2c]
	movs r2, #1
	bl sub_080C0EC0
	ldrh r0, [r4, #0x36]
	subs r0, #1
	strh r0, [r4, #0x36]
	movs r1, #1
	mov sb, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne .L080CE39C
	mov r0, sb
	strh r0, [r7, #0x1e]
	movs r0, #0
	bl YesNo_Create
	str r0, [r4, #0x4c]
	str r5, [sp]
.L080CE38E:
	movs r0, #1
	movs r1, #0xc
	movs r2, #0x12
	movs r3, #4
	bl Window_CreateOpen
	str r0, [r4, #0x50]
.L080CE39C:
	movs r0, #0x65
	bl sub_080C51D4
	b .L080CE4A0
.L080CE3A4:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CE438
	ldrb r0, [r6, #0xc]
	ldrh r1, [r4, #0x2c]
	bl sub_080C0F64
	adds r2, r0, #0
	ldrh r0, [r4, #0x2c]
	cmp r0, #5
	bhi .L080CE40A
	lsls r0, r0, #2
	ldr r1, .L080CE3C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080CE3C8: .4byte gUnknown_080CE3CC
	.global gUnknown_080CE3CC
gUnknown_080CE3CC:
.L080CE3CC: @ jump table
	.4byte .L080CE3E4
	.4byte .L080CE3EA
	.4byte .L080CE3F0
	.4byte .L080CE3F6
	.4byte .L080CE3FC
	.4byte .L080CE402
.L080CE3E4:
	adds r0, r4, #0
	adds r0, #0xfc
	b .L080CE406
.L080CE3EA:
	adds r0, r4, #0
	adds r0, #0xfd
	b .L080CE406
.L080CE3F0:
	adds r0, r4, #0
	adds r0, #0xfe
	b .L080CE406
.L080CE3F6:
	adds r0, r4, #0
	adds r0, #0xff
	b .L080CE406
.L080CE3FC:
	movs r1, #0x80
	lsls r1, r1, #1
	b .L080CE404
.L080CE402:
	ldr r1, .L080CE434
.L080CE404:
	adds r0, r4, r1
.L080CE406:
	movs r5, #0
	ldrsb r5, [r0, r5]
.L080CE40A:
	movs r0, #0xff
	ands r5, r0
	ands r2, r0
	cmp r5, r2
	beq .L080CE4A0
	ldrb r0, [r6, #0xc]
	ldrh r1, [r4, #0x2c]
	movs r2, #1
	rsbs r2, r2, #0
	bl sub_080C0EC0
	ldrh r0, [r4, #0x36]
	adds r0, #1
	strh r0, [r4, #0x36]
	movs r0, #1
	mov sb, r0
	movs r0, #0x66
	bl sub_080C51D4
	b .L080CE4A0
	.byte 0x00, 0x00
.L080CE434: .4byte 0x00000101
.L080CE438:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080CE44E
	ldrh r0, [r4, #0x2c]
	cmp r0, #2
	bls .L080CE44A
	subs r0, #3
	b .L080CE478
.L080CE44A:
	adds r0, #3
	b .L080CE478
.L080CE44E:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080CE464
	ldrh r0, [r4, #0x2c]
	cmp r0, #2
	bls .L080CE460
	subs r0, #3
	b .L080CE478
.L080CE460:
	adds r0, #3
	b .L080CE478
.L080CE464:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080CE482
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	beq .L080CE476
	subs r0, #1
	b .L080CE478
.L080CE476:
	movs r0, #5
.L080CE478:
	strh r0, [r4, #0x2c]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080CE4A0
.L080CE482:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080CE4A0
	ldrh r0, [r4, #0x2c]
	cmp r0, #5
	beq .L080CE496
	adds r0, #1
	strh r0, [r4, #0x2c]
	b .L080CE49A
.L080CE496:
	mov r1, sb
	strh r1, [r4, #0x2c]
.L080CE49A:
	movs r0, #0x64
	bl sub_080C51D4
.L080CE4A0:
	mov r0, sb
	cmp r0, #1
	bne .L080CE4C2
	bl sub_080CB068
	adds r0, r7, #0
	bl sub_080C9D5C
	adds r0, r7, #0
	bl sub_080C9D00
	adds r0, r7, #0
	bl sub_080C9E08
	adds r0, r7, #0
	bl sub_080C9D84
.L080CE4C2:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080CE4D0
sub_080CE4D0: @ 0x080CE4D0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, .L080CE4FC
	ldrh r0, [r5, #2]
	bl sub_080C92C8
	adds r6, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r0, [r5, #0x4c]
	bl Task_IsFree
	adds r1, r0, #0
	cmp r1, #1
	bne .L080CE540
	ldr r0, .L080CE500
	ldr r0, [r0]
	cmp r0, #0
	bne .L080CE504
	strh r1, [r4, #0x1e]
	b .L080CE538
.L080CE4FC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CE500: .4byte 0x030031CC @ IWRAM+0x31CC
.L080CE504:
	movs r0, #2
	strh r0, [r4, #0x1e]
	ldrh r0, [r5, #0x34]
	strh r0, [r5, #0x36]
	adds r0, r5, #0
	adds r0, #0xd4
	ldr r2, .L080CE55C
	adds r1, r6, #0
	bl CpuSet
	bl sub_080C9414
	bl sub_080CB068
	adds r0, r4, #0
	bl sub_080C9D5C
	adds r0, r4, #0
	bl sub_080C9D00
	adds r0, r4, #0
	bl sub_080C9E08
	adds r0, r4, #0
	bl sub_080C9D84
.L080CE538:
	ldr r0, [r5, #0x50]
	movs r1, #1
	bl Window_Close
.L080CE540:
	ldr r0, .L080CE560
	movs r1, #0x62
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0xa
	bl Text_DrawSpriteString
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080CE55C: .4byte 0x04000020 @ REG_BG2PA
.L080CE560: .4byte gUnknown_084F0CA0

	thumb_func_start sub_080CE564
sub_080CE564: @ 0x080CE564
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080CE574
	ldrh r0, [r0]
	cmp r0, #4
	bne .L080CE578
	movs r0, #1
	b .L080CE57A
.L080CE574: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CE578:
	movs r0, #0
.L080CE57A:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080CE580
sub_080CE580: @ 0x080CE580
.L080CE580:
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r3, .L080CE59C
	ldr r4, .L080CE5A0
	movs r6, #0
.L080CE58A:
	ldr r2, [r4]
	cmp r2, #0
	beq .L080CE5AA
	cmp r1, #0
	bne .L080CE5A4
	ldr r0, [r2, #0x20]
	str r0, [r3]
	str r1, [r2, #0x20]
	b .L080CE5AA
.L080CE59C: .4byte 0x020360B4 @ EWRAM+0x360B4
.L080CE5A0: .4byte 0x02036094 @ EWRAM+0x36094
.L080CE5A4:
	ldr r0, [r3]
	str r0, [r2, #0x20]
	str r6, [r3]
.L080CE5AA:
	adds r3, #4
	adds r4, #4
	adds r5, #1
	cmp r5, #7
	bls .L080CE58A
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CE5BC
sub_080CE5BC: @ 0x080CE5BC
	push {r4, lr}
	ldr r4, .L080CE5DC
	ldrh r0, [r4, #2]
	bl sub_080C92C8
	adds r1, r0, #0
	ldrh r0, [r4]
	cmp r0, #5
	bne .L080CE5D4
	ldrb r0, [r1, #0xc]
	bl sub_080BF8D8
.L080CE5D4:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CE5DC: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CE5E0
sub_080CE5E0: @ 0x080CE5E0
	push {lr}
	ldr r0, .L080CE608
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne .L080CE602
	ldr r0, .L080CE60C
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080CE602
	ldr r0, .L080CE610
	str r2, [r0]
.L080CE602:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CE608: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080CE60C: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080CE610: .4byte 0x03003BB4 @ IWRAM+0x3BB4

	thumb_func_start sub_080CE614
sub_080CE614: @ 0x080CE614
	ldr r1, .L080CE61C
	movs r0, #0
	strh r0, [r1]
	bx lr
.L080CE61C: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080CE620
sub_080CE620: @ 0x080CE620
	ldr r1, .L080CE628
	movs r0, #1
	strh r0, [r1]
	bx lr
.L080CE628: .4byte 0x03004608 @ IWRAM+0x4608

	thumb_func_start sub_080CE62C
sub_080CE62C: @ 0x080CE62C
.L080CE62C:
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080CE6A8
	ldr r1, .L080CE6AC
	mov sb, r1
	bl Task_Create
	mov sl, r0
	ldr r5, .L080CE6B0
	movs r0, #0
	mov r8, r0
	str r0, [sp]
	ldr r2, .L080CE6B4
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	strh r4, [r5, #0x36]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r1, sb
	ands r4, r1
	strh r4, [r5, #0x34]
	strh r6, [r5, #2]
	movs r0, #4
	strh r0, [r5]
	mov r0, r8
	strh r0, [r5, #0x22]
	movs r0, #2
	strh r0, [r5, #6]
	movs r0, #3
	strh r0, [r5, #8]
	ldr r1, .L080CE6B8
	ldr r0, .L080CE6BC
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, .L080CE6C0
	ldrh r0, [r5, #2]
	lsls r0, r0, #7
	adds r0, r0, r1
	ldrb r0, [r0, #0xc]
	bl sub_080F4260
	mov r0, sl
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080CE6A8: .4byte gUnknown_084F0CBC
.L080CE6AC: .4byte 0x0000FFFF
.L080CE6B0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CE6B4: .4byte 0x05000200 @ PLTT+0x200
.L080CE6B8: .4byte 0x03004600 @ IWRAM+0x4600
.L080CE6BC: .4byte 0x0300000E @ IWRAM+0xE
.L080CE6C0: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_080CE6C4
sub_080CE6C4: @ 0x080CE6C4
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080CE734
	ldr r1, .L080CE738
	mov sb, r1
	bl Task_Create
	mov sl, r0
	ldr r5, .L080CE73C
	movs r0, #0
	mov r8, r0
	str r0, [sp]
	ldr r2, .L080CE740
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	strh r4, [r5, #0x36]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r1, sb
	ands r4, r1
	strh r4, [r5, #0x34]
	strh r6, [r5, #2]
	movs r0, #5
	strh r0, [r5]
	mov r0, r8
	strh r0, [r5, #0x22]
	movs r0, #2
	strh r0, [r5, #6]
	movs r0, #3
	strh r0, [r5, #8]
	ldr r1, .L080CE744
	ldr r0, .L080CE748
	ldrh r0, [r0]
	strh r0, [r1]
	mov r0, sl
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080CE734: .4byte gUnknown_084F0CBC
.L080CE738: .4byte 0x0000FFFF
.L080CE73C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CE740: .4byte 0x05000200 @ PLTT+0x200
.L080CE744: .4byte 0x03004600 @ IWRAM+0x4600
.L080CE748: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080CE74C
sub_080CE74C: @ 0x080CE74C
.L080CE74C:
	push {lr}
	movs r1, #0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080CE758
	movs r1, #1
.L080CE758:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080CE760
sub_080CE760: @ 0x080CE760
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r7, .L080CE7D0
	movs r0, #0x80
	lsls r0, r0, #8
	bl sub_080C0148
	mov r8, r0
	ldr r5, .L080CE7D4
	ldrh r0, [r5, #8]
	adds r2, r0, #0
	movs r1, #0
	strh r1, [r6, #0x1c]
	cmp r4, #0
	beq .L080CE788
	b .L080CE88C
.L080CE788:
	ldrh r7, [r5, #6]
	cmp r0, #1
	beq .L080CE796
	cmp r0, #4
	beq .L080CE796
	cmp r0, #5
	bne .L080CE7D8
.L080CE796:
	ldr r0, .L080CE7D4
	ldrh r0, [r0, #6]
	bl sub_08154968
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r5, #0
	bl sub_080C32D4
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0xff
	adds r1, r5, #0
	bl sub_08131AB0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r0
	cmp r4, #0x62
	bgt .L080CE7C4
	b .L080CEAB4
.L080CE7C4:
	movs r0, #1
	strh r0, [r6, #0x1c]
	movs r0, #3
	strh r0, [r6, #0x1e]
	b .L080CEAB4
	.byte 0x00, 0x00
.L080CE7D0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CE7D4: .4byte 0x0203B854 @ EWRAM+0x3B854
.L080CE7D8:
	cmp r2, #6
	bne .L080CE816
	adds r0, r7, #0
	bl sub_080C3560
	cmp r0, #0
	bne .L080CE832
	movs r5, #0
	movs r4, #0
.L080CE7EA:
	adds r0, r4, #4
	bl sub_080C09B0
	cmp r0, #0
	beq .L080CE7FA
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080CE7FA:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xb
	bls .L080CE7EA
	bl sub_080C104C
	cmp r5, r0
	blt .L080CE83A
	movs r0, #1
	strh r0, [r6, #0x1c]
	movs r0, #4
	strh r0, [r6, #0x1e]
	b .L080CEAB4
.L080CE816:
	adds r0, r7, #0
	bl sub_080C3560
	cmp r0, #0
	beq .L080CE83A
	ldrh r0, [r5]
	cmp r0, r7
	beq .L080CE83A
	ldrh r0, [r5, #2]
	cmp r0, r7
	beq .L080CE83A
	ldrh r0, [r5, #4]
	cmp r0, r7
	beq .L080CE83A
.L080CE832:
	movs r0, #1
	strh r0, [r6, #0x1c]
	strh r0, [r6, #0x1e]
	b .L080CEAB4
.L080CE83A:
	ldr r2, .L080CE86C
	ldrh r0, [r2, #8]
	cmp r0, #3
	bne .L080CE870
	ldrh r0, [r2]
	ldrh r1, [r2, #2]
	ldrh r2, [r2, #4]
	bl sub_081546E8
	adds r5, r0, #0
	cmp r5, #1
	bne .L080CE870
	mov r0, r8
	ldrb r4, [r0, #0xd]
	adds r4, #9
	adds r0, r7, #0
	bl Demon_GetRecord
	ldrb r0, [r0, #1]
	cmp r4, r0
	blt .L080CE866
	b .L080CEAB4
.L080CE866:
	strh r5, [r6, #0x1c]
	b .L080CE886
	.byte 0x00, 0x00
.L080CE86C: .4byte 0x0203B854 @ EWRAM+0x3B854
.L080CE870:
	adds r0, r7, #0
	bl Demon_GetRecord
	mov r2, r8
	ldrb r1, [r2, #0xd]
	ldrb r0, [r0, #1]
	cmp r1, r0
	blo .L080CE882
	b .L080CEAB4
.L080CE882:
	movs r0, #1
	strh r0, [r6, #0x1c]
.L080CE886:
	movs r0, #2
	strh r0, [r6, #0x1e]
	b .L080CEAB4
.L080CE88C:
	cmp r4, #1
	bne .L080CE892
	b .L080CE9CC
.L080CE892:
	cmp r4, #2
	bne .L080CE928
	ldr r0, .L080CE8BC
	ldrh r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CE8C4
	strh r2, [r6, #0x1c]
	ldr r0, .L080CE8C0
	str r2, [r0]
	ldr r0, [r7, #0x50]
	movs r1, #1
	bl Window_Close
	movs r0, #0x65
	bl sub_080C51D4
	b .L080CEAB4
	.byte 0x00, 0x00
.L080CE8BC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CE8C0: .4byte 0x030031CC @ IWRAM+0x31CC
.L080CE8C4:
	ldrh r0, [r6, #0x1e]
	cmp r0, #1
	bne .L080CE8D4
	ldr r0, .L080CE8D0
	b .L080CE8E6
	.byte 0x00, 0x00
.L080CE8D0: .4byte gUnknown_0815BF4A
.L080CE8D4:
	cmp r0, #2
	bne .L080CE8E0
	ldr r0, .L080CE8DC
	b .L080CE8E6
.L080CE8DC: .4byte gUnknown_0815BF0E
.L080CE8E0:
	cmp r0, #3
	bne .L080CE900
	ldr r0, .L080CE8FC
.L080CE8E6:
	movs r1, #0x5b
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	b .L080CE914
	.byte 0x00, 0x00
.L080CE8FC: .4byte gUnknown_0815BF62
.L080CE900:
	ldr r0, .L080CE920
	movs r1, #0x5b
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
.L080CE914:
	ldr r0, .L080CE924
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	b .L080CEA1C
.L080CE920: .4byte gUnknown_0815BF7C
.L080CE924: .4byte 0x030031BC @ IWRAM+0x31BC
.L080CE928:
	cmp r4, #3
	bne .L080CE946
	str r1, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #7
	bl Window_CreateOpen
	str r0, [r7, #0x50]
	movs r0, #0
	bl YesNo_Create
	str r0, [r7, #0x4c]
	b .L080CE9DC
.L080CE946:
	cmp r4, #4
	bne .L080CE960
	ldr r0, [r7, #0x4c]
	bl Task_IsFree
	cmp r0, #1
	bne .L080CE956
	b .L080CEA56
.L080CE956:
	ldr r0, .L080CE95C
	b .L080CE9AE
	.byte 0x00, 0x00
.L080CE95C: .4byte gUnknown_0815BED4
.L080CE960:
	cmp r4, #5
	bne .L080CE99E
	mov r1, r8
	ldrb r0, [r1, #0xc]
	bl sub_080C06BC
	adds r4, r0, #0
	ldrh r0, [r5, #6]
	bl sub_0815B864
	ldrh r1, [r5, #8]
	cmp r1, #1
	bne .L080CE97C
	b .L080CEAB4
.L080CE97C:
	cmp r1, #4
	bne .L080CE982
	b .L080CEAB4
.L080CE982:
	cmp r1, #5
	bne .L080CE988
	b .L080CEAB4
.L080CE988:
	cmp r4, #0
	bne .L080CE990
	cmp r0, #2
	beq .L080CEA42
.L080CE990:
	cmp r4, #2
	beq .L080CE996
	b .L080CEAB4
.L080CE996:
	cmp r0, #0
	beq .L080CE99C
	b .L080CEAB4
.L080CE99C:
	b .L080CEA42
.L080CE99E:
	cmp r4, #6
	bne .L080CE9C8
	ldr r0, [r7, #0x4c]
	bl Task_IsFree
	cmp r0, #1
	beq .L080CEA56
	ldr r0, .L080CE9C4
.L080CE9AE:
	movs r1, #0x5b
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	b .L080CEAB4
	.byte 0x00, 0x00
.L080CE9C4: .4byte gUnknown_0815BF36
.L080CE9C8:
	cmp r4, #7
	bne .L080CE9E6
.L080CE9CC:
	str r1, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #7
	bl Window_CreateOpen
	str r0, [r7, #0x50]
.L080CE9DC:
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	b .L080CEAB4
.L080CE9E6:
	cmp r4, #8
	bne .L080CEA38
	ldr r0, .L080CE9FC
	ldrh r1, [r0]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CEA00
	strh r4, [r6, #0x1c]
	b .L080CEA58
.L080CE9FC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CEA00:
	ldr r0, .L080CEA30
	movs r1, #0x5b
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	ldr r0, .L080CEA34
	ldr r0, [r0]
	lsrs r0, r0, #4
	ands r0, r4
.L080CEA1C:
	cmp r0, #0
	bne .L080CEAB4
	movs r0, #0
	movs r1, #0
	movs r2, #0xd5
	movs r3, #0x85
	bl sub_080C4AB0
	b .L080CEAB4
	.byte 0x00, 0x00
.L080CEA30: .4byte gUnknown_0815BEFA
.L080CEA34: .4byte 0x030031BC @ IWRAM+0x31BC
.L080CEA38:
	cmp r4, #9
	bne .L080CEA48
	ldrh r0, [r5, #8]
	cmp r0, #6
	bne .L080CEAB4
.L080CEA42:
	movs r0, #1
	strh r0, [r6, #0x1c]
	b .L080CEAB4
.L080CEA48:
	cmp r4, #0xa
	bne .L080CEAB4
	ldr r0, [r7, #0x4c]
	bl Task_IsFree
	cmp r0, #1
	bne .L080CEA62
.L080CEA56:
	strh r0, [r6, #0x1c]
.L080CEA58:
	ldr r0, [r7, #0x50]
	movs r1, #1
	bl Window_Close
	b .L080CEAB4
.L080CEA62:
	ldr r0, .L080CEAC0
	movs r1, #0x5b
	str r1, [sp]
	movs r4, #0xc
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	ldr r0, .L080CEAC4
	ldrh r0, [r0, #6]
	bl sub_081571DC
	movs r5, #0x67
	movs r1, #0x12
	movs r2, #0x67
	bl Comp_DrawSummonCost
	adds r3, r0, #0
	lsls r3, r3, #0x10
	ldr r0, .L080CEAC8
	movs r2, #0xc0
	lsls r2, r2, #0xc
	adds r3, r3, r2
	lsrs r3, r3, #0x10
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	bl Text_DrawSpriteString
	ldr r0, .L080CEACC
	movs r1, #0x73
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
.L080CEAB4:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CEAC0: .4byte gUnknown_0815BFBE
.L080CEAC4: .4byte 0x0203B854 @ EWRAM+0x3B854
.L080CEAC8: .4byte gUnknown_0815BFCC
.L080CEACC: .4byte gUnknown_0815BFD6

	thumb_func_start Comp_DrawSummonCost
Comp_DrawSummonCost: @ 0x080CEAD0
.L080CEAD0:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	bl NumberToDigits
	mov r8, r0
	movs r7, #0
	str r6, [sp]
	movs r0, #0x52
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl FontSprite_DrawGlyph
	adds r0, r5, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r2, #0
	ldr r0, .L080CEB5C
	mov sb, r0
.L080CEB06:
	mov r1, r8
	adds r1, #7
	lsls r4, r2, #0x18
	cmp r7, #1
	beq .L080CEB1A
	asrs r0, r4, #0x18
	subs r0, r1, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080CEB3C
.L080CEB1A:
	asrs r0, r4, #0x18
	subs r0, r1, r0
	ldrb r0, [r0]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	str r6, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl FontSprite_DrawGlyph
	movs r7, #1
	adds r0, r5, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080CEB3C:
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r4, r1
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	ble .L080CEB06
	adds r0, r5, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080CEB5C: .4byte gUnknown_084F0EAC

	thumb_func_start sub_080CEB60
sub_080CEB60: @ 0x080CEB60
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, .L080CEBAC
	ldrh r0, [r5, #2]
	bl sub_080C92C8
	movs r0, #0
	bl sub_080C964C
	movs r6, #0
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r0, .L080CEBB0
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080CEBE8
	ldr r0, .L080CEBB4
	ldrh r0, [r0, #8]
	cmp r0, #1
	beq .L080CEBE8
	cmp r0, #4
	beq .L080CEBE8
	cmp r0, #5
	beq .L080CEBE8
	ldrh r0, [r5, #2]
	bl sub_080C93B4
	cmp r0, #1
	bne .L080CEBBC
	movs r0, #0x64
	bl sub_080C51D4
	ldr r0, .L080CEBB8
	strh r0, [r4, #0x1e]
	b .L080CEC20
	.byte 0x00, 0x00
.L080CEBAC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CEBB0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CEBB4: .4byte 0x0203B854 @ EWRAM+0x3B854
.L080CEBB8: .4byte 0x00008001
.L080CEBBC:
	ldrh r0, [r5, #2]
	bl sub_080C9388
	cmp r0, #1
	bne .L080CEBD8
	movs r0, #0x64
	bl sub_080C51D4
	ldr r0, .L080CEBD4
	strh r0, [r4, #0x1e]
	b .L080CEC20
	.byte 0x00, 0x00
.L080CEBD4: .4byte 0x00008002
.L080CEBD8:
	movs r0, #0x64
	bl sub_080C51D4
	ldr r0, .L080CEBE4
	strh r0, [r4, #0x1e]
	b .L080CEC20
.L080CEBE4: .4byte 0x00008003
.L080CEBE8:
	ldr r2, .L080CEC04
	ldrh r1, [r2]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CEC08
	movs r0, #0x65
	bl sub_080C51D4
	movs r0, #2
	strh r0, [r4, #0x1e]
	b .L080CEC20
	.byte 0x00, 0x00
.L080CEC04: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CEC08:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CEC20
	movs r0, #0x66
	bl sub_080C51D4
	movs r0, #3
	strh r0, [r4, #0x1e]
	ldr r0, .L080CEC44
	str r5, [r0]
.L080CEC20:
	ldr r0, .L080CEC48
	ldrh r0, [r0, #8]
	cmp r0, #1
	beq .L080CEC3C
	cmp r0, #4
	beq .L080CEC3C
	cmp r0, #5
	beq .L080CEC3C
	movs r0, #0
	movs r1, #0
	movs r2, #0x92
	movs r3, #0x76
	bl sub_080C4AB0
.L080CEC3C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CEC44: .4byte 0x030031CC @ IWRAM+0x31CC
.L080CEC48: .4byte 0x0203B854 @ EWRAM+0x3B854

	thumb_func_start sub_080CEC4C
sub_080CEC4C: @ 0x080CEC4C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L080CEC90
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	beq .L080CEC62
	movs r1, #0
	bl sub_080C3E80
	movs r0, #0
	str r0, [r4, #0x3c]
.L080CEC62:
	ldr r0, [r4, #0x40]
	movs r1, #1
	bl TextWindow_Close
	ldr r0, [r4, #0x44]
	movs r1, #1
	bl TextWindow_Close
	ldr r0, [r4, #0x48]
	movs r1, #1
	bl TextWindow_Close
	ldr r0, .L080CEC94
	ldrh r0, [r0, #8]
	cmp r0, #6
	beq .L080CEC98
	ldr r2, [r4, #0x38]
	movs r0, #0
	adds r1, r5, #0
	bl sub_08157EB0
	b .L080CECA2
	.byte 0x00, 0x00
.L080CEC90: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CEC94: .4byte 0x0203B854 @ EWRAM+0x3B854
.L080CEC98:
	ldr r2, [r4, #0x38]
	movs r0, #3
	adds r1, r5, #0
	bl sub_08157EB0
.L080CECA2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080CECA8
sub_080CECA8: @ 0x080CECA8
	push {r4, lr}
	ldr r4, .L080CECEC
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	beq .L080CECBC
	movs r1, #0
	bl sub_080C3E80
	movs r0, #0
	str r0, [r4, #0x3c]
.L080CECBC:
	ldr r0, [r4, #0x40]
	movs r1, #1
	bl TextWindow_Close
	ldr r0, [r4, #0x44]
	movs r1, #1
	bl TextWindow_Close
	ldr r0, [r4, #0x48]
	movs r1, #1
	bl TextWindow_Close
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	movs r0, #0
	bl sub_08156000
	ldr r1, .L080CECF0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L080CECEC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CECF0: .4byte 0x030068E0 @ IWRAM+0x68E0

	thumb_func_start sub_080CECF4
sub_080CECF4: @ 0x080CECF4
	push {lr}
	bl sub_080C1384
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CED00
sub_080CED00: @ 0x080CED00
.L080CED00:
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r0, .L080CED30
	ldr r1, .L080CED34
	bl Task_Create
	adds r6, r0, #0
	ldr r4, .L080CED38
	movs r5, #0
	str r5, [sp]
	ldr r2, .L080CED3C
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	strh r5, [r4, #2]
	movs r0, #6
	strh r0, [r4]
	strh r5, [r4, #0x22]
	adds r0, r6, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080CED30: .4byte gUnknown_084F0EC0
.L080CED34: .4byte 0x0000FFFF
.L080CED38: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CED3C: .4byte 0x05000200 @ PLTT+0x200

	thumb_func_start sub_080CED40
sub_080CED40: @ 0x080CED40
	push {r4, r5, lr}
	ldr r5, .L080CED7C
	ldr r4, .L080CED80
	ldr r0, .L080CED84
	ldr r1, .L080CED88
	bl LZ77UnCompWram
	ldr r0, .L080CED8C
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r4]
	movs r4, #0
	movs r0, #1
	strh r0, [r5, #0x24]
	strh r4, [r5, #2]
	strh r4, [r5, #0x10]
	movs r0, #0
	bl sub_080C9388
	cmp r0, #1
	bne .L080CED90
	strh r0, [r5, #0x16]
	b .L080CED92
	.byte 0x00, 0x00
.L080CED7C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CED80: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080CED84: .4byte gUnknown_081B5870
.L080CED88: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CED8C: .4byte sub_080C93E0
.L080CED90:
	strh r4, [r5, #0x16]
.L080CED92:
	movs r1, #0
	movs r0, #1
	strh r0, [r5, #0x18]
	strh r1, [r5, #0x1c]
	strh r1, [r5, #0x1e]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CEDA4
sub_080CEDA4: @ 0x080CEDA4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r7, .L080CEDEC
	ldrh r0, [r7, #2]
	bl sub_080C92C8
	adds r4, r0, #0
	movs r0, #0
	bl sub_080C964C
	ldrh r0, [r4, #0x12]
	bl sub_080C92AC
	adds r6, r0, #0
	movs r0, #0
	strh r0, [r5, #0x1e]
	adds r0, r4, #0
	bl sub_080C99B8
	cmp r0, #1
	bne .L080CEDD0
	movs r6, #1
.L080CEDD0:
	ldr r2, .L080CEDF0
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080CEDF8
	cmp r6, #0
	bne .L080CEDF8
	movs r0, #0x64
	bl sub_080C51D4
	ldr r0, .L080CEDF4
	strh r0, [r5, #0x1e]
	b .L080CEE1E
.L080CEDEC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CEDF0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CEDF4: .4byte 0x00008003
.L080CEDF8:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L080CEE0E
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CEE1E
.L080CEE0E:
	movs r0, #0x66
	bl sub_080C51D4
	movs r0, #3
	strh r0, [r5, #0x1e]
	ldr r1, .L080CEE48
	movs r0, #1
	str r0, [r1]
.L080CEE1E:
	ldrh r0, [r7, #4]
	movs r1, #0
	cmp r0, #0
	bne .L080CEE28
	ldrh r1, [r7, #0x20]
.L080CEE28:
	adds r0, r1, #0
	bl sub_080C981C
	bl sub_080C9994
	cmp r6, #0
	bne .L080CEE42
	movs r0, #0
	movs r1, #0
	movs r2, #0x92
	movs r3, #0x76
	bl sub_080C4AB0
.L080CEE42:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CEE48: .4byte 0x030031CC @ IWRAM+0x31CC

	thumb_func_start sub_080CEE4C
sub_080CEE4C: @ 0x080CEE4C
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080CEE60
sub_080CEE60: @ 0x080CEE60
	push {lr}
	bl sub_080C9E30
	ldr r0, .L080CEE74
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CEE74: .4byte sub_080CEE4C

	thumb_func_start sub_080CEE78
sub_080CEE78: @ 0x080CEE78
	push {lr}
	sub sp, #4
	bl sub_08154EC0
	movs r3, #0
	str r3, [sp]
	ldr r0, .L080CEEB8
	mov r1, sp
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, .L080CEEBC
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080CEEC0
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080CEEC4
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	add sp, #4
	pop {r0}
	bx r0
.L080CEEB8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080CEEBC: .4byte 0x85000400
.L080CEEC0: .4byte 0x06001000 @ VRAM+0x1000
.L080CEEC4: .4byte 0x06002000 @ VRAM+0x2000

	thumb_func_start sub_080CEEC8
sub_080CEEC8: @ 0x080CEEC8
	push {r4, lr}
	ldr r4, .L080CEEE4
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	beq .L080CEEDC
	movs r1, #0
	bl sub_080C3E80
	movs r0, #0
	str r0, [r4, #0x3c]
.L080CEEDC:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CEEE4: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CEEE8
sub_080CEEE8: @ 0x080CEEE8
	push {r4, lr}
	ldr r4, .L080CEF2C
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	beq .L080CEEFC
	movs r1, #0
	bl sub_080C3E80
	movs r0, #0
	str r0, [r4, #0x3c]
.L080CEEFC:
	ldr r0, [r4, #0x40]
	movs r1, #1
	bl TextWindow_Close
	ldr r0, [r4, #0x44]
	movs r1, #1
	bl TextWindow_Close
	ldr r0, [r4, #0x48]
	movs r1, #1
	bl TextWindow_Close
	ldr r0, .L080CEF30
	ldr r2, .L080CEF34
	adds r1, r4, #0
	bl CpuSet
	ldr r0, .L080CEF38
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r4}
	pop {r0}
	bx r0
.L080CEF2C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CEF30: .4byte 0x0203AC54 @ EWRAM+0x3AC54
.L080CEF34: .4byte 0x04000200 @ REG_IE
.L080CEF38: .4byte sub_080CEE78

	thumb_func_start sub_080CEF3C
sub_080CEF3C: @ 0x080CEF3C
	push {lr}
	ldr r0, .L080CEF54
	ldr r1, .L080CEF58
	bl LZ77UnCompWram
	ldr r0, .L080CEF5C
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CEF54: .4byte gUnknown_081B5870
.L080CEF58: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CEF5C: .4byte sub_080C93E0

	thumb_func_start sub_080CEF60
sub_080CEF60: @ 0x080CEF60
	push {r4, r5, r6, lr}
	ldr r4, .L080CEF74
	ldr r6, .L080CEF78
	ldrh r0, [r4]
	cmp r0, #0xb
	beq .L080CEF7C
	cmp r0, #0xc
	beq .L080CEF80
	b .L080CEF82
	.byte 0x00, 0x00
.L080CEF74: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CEF78: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080CEF7C:
	movs r1, #0
	b .L080CEF82
.L080CEF80:
	movs r1, #1
.L080CEF82:
	adds r0, r6, #0
	bl sub_080D45F0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r2, #0
	cmp r2, r3
	bhs .L080CEFAC
	movs r0, #0x80
	lsls r0, r0, #8
	adds r5, r0, #0
.L080CEF98:
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	orrs r1, r5
	strh r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r3
	blo .L080CEF98
.L080CEFAC:
	movs r5, #0
	strh r3, [r4, #0x24]
	strh r5, [r4, #0x10]
	ldrh r0, [r4, #2]
	bl sub_080C9388
	cmp r0, #1
	bne .L080CEFC0
	strh r0, [r4, #0x16]
	b .L080CEFC2
.L080CEFC0:
	strh r5, [r4, #0x16]
.L080CEFC2:
	movs r1, #0
	movs r0, #1
	strh r0, [r4, #0x18]
	strh r1, [r4, #0x1c]
	strh r1, [r4, #0x1e]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CEFD4
sub_080CEFD4: @ 0x080CEFD4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, .L080CF008
	movs r4, #0
.L080CEFDC:
	movs r0, #0x64
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, .L080CF00C
	adds r1, r1, r0
	ldr r0, [r6, #0x38]
	cmp r0, r1
	beq .L080CEFFC
	cmp r5, r1
	beq .L080CEFFC
	ldrh r0, [r1]
	cmp r0, #1
	bne .L080CEFFC
	adds r0, r1, #0
	bl Task_Pause
.L080CEFFC:
	adds r4, #1
	cmp r4, #0x3f
	bls .L080CEFDC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080CF008: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CF00C: .4byte 0x02009004 @ EWRAM+0x9004

	thumb_func_start sub_080CF010
sub_080CF010: @ 0x080CF010
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r6, .L080CF06C
	ldrh r0, [r6, #2]
	bl sub_080C92C8
	adds r7, r0, #0
	movs r2, #0
	movs r4, #0
	ldr r0, .L080CF070
	mov r8, r0
.L080CF02A:
	movs r0, #0x64
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, .L080CF074
	adds r1, r1, r0
	ldr r0, [r6, #0x38]
	cmp r0, r1
	beq .L080CF04C
	cmp r5, r1
	beq .L080CF04C
	ldrh r0, [r1]
	cmp r0, r8
	bne .L080CF04C
	adds r0, r1, #0
	bl Task_Resume
	movs r2, #1
.L080CF04C:
	adds r4, #1
	cmp r4, #0x3f
	bls .L080CF02A
	cmp r2, #1
	bne .L080CF062
	movs r0, #0x12
	ldrsh r1, [r7, r0]
	adds r0, r5, #0
	movs r2, #1
	bl sub_080D3F04
.L080CF062:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CF06C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CF070: .4byte 0x0000FFFF
.L080CF074: .4byte 0x02009004 @ EWRAM+0x9004

	thumb_func_start sub_080CF078
sub_080CF078: @ 0x080CF078
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r5, .L080CF0A8
	ldrh r0, [r5, #2]
	bl sub_080C92C8
	movs r0, #0
	bl sub_080C964C
	mov sb, r0
	movs r0, #0
	strh r0, [r7, #0x1e]
	ldrh r0, [r5, #2]
	bl sub_080C9388
	cmp r0, #1
	bne .L080CF0AC
	movs r4, #1
	movs r0, #0x65
	mov r8, r0
	b .L080CF0BE
.L080CF0A8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CF0AC:
	movs r4, #0x80
	movs r0, #0x64
	mov r8, r0
	movs r0, #0
	movs r1, #0
	movs r2, #0x92
	movs r3, #0x76
	bl sub_080C4AB0
.L080CF0BE:
	ldr r2, .L080CF0D8
	ldrh r1, [r2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CF0DC
	movs r0, #0x65
	bl sub_080C51D4
	strh r6, [r7, #0x1e]
	b .L080CF19A
	.byte 0x00, 0x00
.L080CF0D8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CF0DC:
	ldrh r0, [r2]
	ands r4, r0
	cmp r4, #0
	beq .L080CF0F4
	mov r0, r8
	bl sub_080C51D4
	ldr r0, .L080CF0F0
	strh r0, [r7, #0x1e]
	b .L080CF19A
.L080CF0F0: .4byte 0x00008003
.L080CF0F4:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CF114
	movs r0, #0x66
	bl sub_080C51D4
	movs r0, #3
	strh r0, [r7, #0x1e]
	ldr r0, .L080CF110
	str r6, [r0]
	b .L080CF19A
	.byte 0x00, 0x00
.L080CF110: .4byte 0x030031CC @ IWRAM+0x31CC
.L080CF114:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CF154
	ldrh r0, [r5, #0x22]
	cmp r0, #0
	bne .L080CF154
	movs r0, #0
	bl sub_080C964C
	cmp r0, #1
	beq .L080CF154
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r5, #2]
	cmp r0, #0
	bne .L080CF13E
	mov r0, sb
.L080CF13E:
	subs r0, #1
	strh r0, [r5, #2]
	ldr r0, .L080CF150
	strh r0, [r5, #0xa]
	movs r0, #2
	strh r0, [r7, #0x1e]
	bl sub_080CA684
	b .L080CF19A
.L080CF150: .4byte 0x0000FFF0
.L080CF154:
	ldr r0, .L080CF188
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080CF19A
	ldrh r4, [r5, #0x22]
	cmp r4, #0
	bne .L080CF19A
	movs r0, #0
	bl sub_080C964C
	cmp r0, #1
	beq .L080CF19A
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r1, [r5, #2]
	mov r0, sb
	subs r0, #1
	cmp r1, r0
	beq .L080CF18C
	adds r0, r1, #1
	strh r0, [r5, #2]
	b .L080CF18E
.L080CF188: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CF18C:
	strh r4, [r5, #2]
.L080CF18E:
	movs r0, #0x10
	strh r0, [r5, #0xa]
	movs r0, #2
	strh r0, [r7, #0x1e]
	bl sub_080CA684
.L080CF19A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CF1A8
sub_080CF1A8: @ 0x080CF1A8
	push {r4, lr}
	sub sp, #4
	ldr r4, .L080CF1D8
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #8
	bl Window_CreateOpen
	str r0, [r4, #0x50]
	movs r0, #0
	bl YesNo_Create
	str r0, [r4, #0x4c]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080CF1D8: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CF1DC
sub_080CF1DC: @ 0x080CF1DC
.L080CF1DC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	bl NumberToDigits
	adds r6, r0, #0
	movs r3, #0
	movs r2, #0
	ldr r0, .L080CF24C
	mov r8, r0
.L080CF1FA:
	adds r1, r6, #7
	lsls r4, r2, #0x18
	cmp r3, #1
	beq .L080CF20C
	asrs r0, r4, #0x18
	subs r0, r1, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080CF22E
.L080CF20C:
	asrs r0, r4, #0x18
	subs r0, r1, r0
	ldrb r0, [r0]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	str r7, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl FontSprite_DrawGlyph
	movs r3, #1
	adds r0, r5, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080CF22E:
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r4, r1
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	ble .L080CF1FA
	adds r0, r5, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080CF24C: .4byte gUnknown_084F0EAC

	thumb_func_start sub_080CF250
sub_080CF250: @ 0x080CF250
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, .L080CF2B8
	ldrh r0, [r4, #2]
	bl sub_080C92C8
	ldrh r7, [r0, #0x12]
	movs r0, #0
	strh r0, [r5, #0x1c]
	ldr r0, [r4, #0x4c]
	bl Task_IsFree
	cmp r0, #1
	bne .L080CF288
	strh r0, [r5, #0x1c]
	ldr r0, .L080CF2BC
	ldr r0, [r0]
	cmp r0, #1
	bne .L080CF288
	ldr r0, [r4, #0x50]
	movs r1, #1
	bl Window_Close
.L080CF288:
	ldrh r0, [r4]
	ldr r6, .L080CF2C0
	cmp r0, #0xb
	bne .L080CF292
	ldr r6, .L080CF2C4
.L080CF292:
	movs r4, #0x12
	movs r5, #0x5b
	mov sl, r4
	ldrh r0, [r6]
	ldr r1, .L080CF2C8
	cmp r0, r1
	beq .L080CF312
	movs r2, #0xc0
	lsls r2, r2, #2
	mov sb, r2
	mov r8, r1
.L080CF2A8:
	cmp r0, sb
	bne .L080CF2CC
	mov r4, sl
	adds r0, r5, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b .L080CF30A
.L080CF2B8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CF2BC: .4byte 0x030031CC @ IWRAM+0x31CC
.L080CF2C0: .4byte gUnknown_0815C0AA
.L080CF2C4: .4byte gUnknown_0815BFEA
.L080CF2C8: .4byte 0x00000301
.L080CF2CC:
	cmp r0, #0xcc
	bne .L080CF2E0
	adds r0, r7, #0
	bl sub_080D45B8
	adds r1, r4, #0
	adds r2, r5, #0
	bl sub_080CF1DC
	b .L080CF306
.L080CF2E0:
	cmp r0, #0xcd
	bne .L080CF2F4
	adds r0, r7, #0
	bl sub_081571DC
	adds r1, r4, #0
	adds r2, r5, #0
	bl sub_080CF1DC
	b .L080CF306
.L080CF2F4:
	ldrh r0, [r6]
	str r5, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r4, #0
	bl FontSprite_DrawGlyph
	adds r0, r4, #0
	adds r0, #0xc
.L080CF306:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L080CF30A:
	adds r6, #2
	ldrh r0, [r6]
	cmp r0, r8
	bne .L080CF2A8
.L080CF312:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CF324
sub_080CF324: @ 0x080CF324
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r0, .L080CF370
	mov sb, r0
	movs r0, #0x80
	lsls r0, r0, #8
	bl sub_080C0148
	mov r8, r0
	mov r1, sb
	ldrh r0, [r1, #2]
	bl sub_080C92C8
	ldrh r7, [r0, #0x12]
	movs r0, #0
	strh r0, [r6, #0x1e]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #0xb
	bne .L080CF3E8
	ldr r0, .L080CF374
	bl sub_080C32D4
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r7, #0
	bl sub_080D45B8
	cmp r4, r0
	bge .L080CF378
	movs r0, #1
	strh r0, [r6, #0x1e]
	b .L080CF408
	.byte 0x00, 0x00
.L080CF370: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CF374: .4byte 0x0000011F
.L080CF378:
	bl sub_080C3100
	adds r4, r0, #0
	adds r0, r7, #0
	bl sub_081571DC
	cmp r4, r0
	blo .L080CF3F8
	movs r5, #0
	movs r4, #0
.L080CF38C:
	adds r0, r4, #4
	bl sub_080C09B0
	cmp r0, #0
	beq .L080CF398
	adds r5, #1
.L080CF398:
	adds r4, #1
	cmp r4, #0xb
	ble .L080CF38C
	bl sub_080C104C
	cmp r5, r0
	blt .L080CF3AC
	movs r0, #3
	strh r0, [r6, #0x1e]
	b .L080CF408
.L080CF3AC:
	adds r0, r7, #0
	bl Demon_GetRecord
	mov r2, r8
	ldrb r1, [r2, #0xd]
	ldrb r0, [r0, #1]
	cmp r1, r0
	bhs .L080CF3C2
	movs r0, #4
	strh r0, [r6, #0x1e]
	b .L080CF408
.L080CF3C2:
	mov r1, r8
	ldrb r0, [r1, #0xc]
	bl sub_080C06BC
	adds r4, r0, #0
	adds r0, r7, #0
	bl sub_0815B864
	cmp r4, #0
	bne .L080CF3DA
	cmp r0, #2
	beq .L080CF3E2
.L080CF3DA:
	cmp r4, #2
	bne .L080CF3FE
	cmp r0, #0
	bne .L080CF3FE
.L080CF3E2:
	movs r0, #5
	strh r0, [r6, #0x1e]
	b .L080CF408
.L080CF3E8:
	bl sub_080C3100
	adds r4, r0, #0
	adds r0, r7, #0
	bl sub_081571DC
	cmp r4, r0
	bhs .L080CF3FE
.L080CF3F8:
	movs r0, #2
	strh r0, [r6, #0x1e]
	b .L080CF408
.L080CF3FE:
	mov r2, sb
	ldr r0, [r2, #0x50]
	movs r1, #1
	bl Window_Close
.L080CF408:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080CF414
sub_080CF414: @ 0x080CF414
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	ldr r4, .L080CF444
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r0, .L080CF448
	ldrh r1, [r0]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CF450
	strh r3, [r2, #0x1c]
	ldr r0, .L080CF44C
	str r3, [r0]
	ldr r0, [r4, #0x50]
	movs r1, #1
	bl Window_Close
	movs r0, #0x65
	bl sub_080C51D4
	b .L080CF4CA
.L080CF444: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CF448: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CF44C: .4byte 0x030031CC @ IWRAM+0x31CC
.L080CF450:
	ldrh r0, [r2, #0x1e]
	cmp r0, #1
	bne .L080CF460
	ldr r0, .L080CF45C
	b .L080CF47E
	.byte 0x00, 0x00
.L080CF45C: .4byte gUnknown_0815C02C
.L080CF460:
	cmp r0, #2
	bne .L080CF46C
	ldr r0, .L080CF468
	b .L080CF47E
.L080CF468: .4byte gUnknown_0815C048
.L080CF46C:
	cmp r0, #3
	bne .L080CF478
	ldr r0, .L080CF474
	b .L080CF47E
.L080CF474: .4byte gUnknown_0815C05A
.L080CF478:
	cmp r0, #4
	bne .L080CF498
	ldr r0, .L080CF494
.L080CF47E:
	movs r1, #0x5b
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
	b .L080CF4B0
	.byte 0x00, 0x00
.L080CF494: .4byte gUnknown_0815C06E
.L080CF498:
	cmp r0, #5
	bne .L080CF4B0
	ldr r0, .L080CF4D4
	movs r1, #0x5b
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0x12
	bl Text_DrawSpriteString
.L080CF4B0:
	ldr r0, .L080CF4D8
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080CF4CA
	movs r0, #0
	movs r1, #0
	movs r2, #0xd5
	movs r3, #0x8d
	bl sub_080C4AB0
.L080CF4CA:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CF4D4: .4byte gUnknown_0815C082
.L080CF4D8: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_080CF4DC
sub_080CF4DC: @ 0x080CF4DC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r4, #0
	add r7, sp, #4
	ldr r6, .L080CF558
.L080CF4E8:
	movs r0, #0x64
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, .L080CF55C
	adds r1, r1, r0
	cmp r5, r1
	beq .L080CF502
	ldrh r0, [r1]
	cmp r0, r6
	bne .L080CF502
	adds r0, r1, #0
	bl Task_End
.L080CF502:
	adds r4, #1
	cmp r4, #0x3f
	bls .L080CF4E8
	ldr r1, .L080CF560
	movs r0, #0
	strh r0, [r1]
	bl sub_080AE2D0
	ldr r0, .L080CF564
	movs r5, #0
	str r5, [r0]
	ldr r0, .L080CF568
	str r5, [r0]
	movs r0, #0
	bl sub_080C6E30
	ldr r1, .L080CF56C
	movs r0, #1
	strh r0, [r1, #0x30]
	str r5, [sp]
	ldr r4, .L080CF570
	ldr r6, .L080CF574
	mov r0, sp
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuSet
	str r5, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuSet
	ldr r1, .L080CF578
	movs r0, #0xbe
	strh r0, [r1]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CF558: .4byte 0x0000FFFF
.L080CF55C: .4byte 0x02009004 @ EWRAM+0x9004
.L080CF560: .4byte 0x0203DB6A @ EWRAM+0x3DB6A
.L080CF564: .4byte 0x020391DC @ EWRAM+0x391DC
.L080CF568: .4byte 0x0200E8D4 @ EWRAM+0xE8D4
.L080CF56C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080CF570: .4byte 0x02017874 @ EWRAM+0x17874
.L080CF574: .4byte 0x05000200 @ PLTT+0x200
.L080CF578: .4byte 0x03004534 @ IWRAM+0x4534

	thumb_func_start sub_080CF57C
sub_080CF57C: @ 0x080CF57C
	push {r4, r5, lr}
	ldr r4, .L080CF59C
	ldrh r0, [r4, #2]
	bl sub_080C92C8
	adds r5, r0, #0
	ldrh r0, [r4]
	cmp r0, #0xb
	bne .L080CF5A4
	movs r0, #0xb1
	lsls r0, r0, #1
	bl Flag_Clear
	ldr r0, .L080CF5A0
	b .L080CF5A6
	.byte 0x00, 0x00
.L080CF59C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CF5A0: .4byte gUnknown_084F3880
.L080CF5A4:
	ldr r0, .L080CF5BC
.L080CF5A6:
	ldr r1, [r4, #0x38]
	ldrh r1, [r1, #2]
	bl Task_Create
	adds r1, r0, #0
	ldrh r0, [r5, #0x12]
	strh r0, [r1, #0x1e]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CF5BC: .4byte gUnknown_084F39B4

	thumb_func_start sub_080CF5C0
sub_080CF5C0: @ 0x080CF5C0
	push {lr}
	movs r0, #1
	bl sub_0812D0FC
	pop {r0}
	bx r0

	thumb_func_start sub_080CF5CC
sub_080CF5CC: @ 0x080CF5CC
	push {r4, lr}
	ldr r4, .L080CF5E0
	ldr r0, .L080CF5E4
	movs r1, #0
	bl sub_080B6B58
	str r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
.L080CF5E0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CF5E4: .4byte sub_080CF5C0

	thumb_func_start sub_080CF5E8
sub_080CF5E8: @ 0x080CF5E8
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080CF600
	ldr r0, [r0, #8]
	ldr r1, [r0, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080CF604
	movs r0, #1
	b .L080CF606
	.byte 0x00, 0x00
.L080CF600: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CF604:
	movs r0, #0
.L080CF606:
	strh r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080CF60C
sub_080CF60C: @ 0x080CF60C
	ldr r0, .L080CF618
	ldr r1, [r0, #8]
	movs r0, #1
	str r0, [r1, #0xc]
	bx lr
	.byte 0x00, 0x00
.L080CF618: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080CF61C
sub_080CF61C: @ 0x080CF61C
	ldr r1, .L080CF658
	ldr r2, .L080CF65C
	adds r0, r2, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L080CF660
	ands r0, r1
	strh r0, [r2]
	ldr r1, .L080CF664
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080CF668
	ldr r0, .L080CF66C
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080CF670
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080CF674
	str r0, [r1]
	ldr r0, .L080CF678
	str r0, [r1, #4]
	ldr r0, .L080CF67C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L080CF658: .4byte 0x0400000A @ REG_BG1CNT
.L080CF65C: .4byte 0x00008205
.L080CF660: .4byte 0x0000FBFF
.L080CF664: .4byte 0x03000040 @ IWRAM+0x40
.L080CF668: .4byte 0x040000D4 @ REG_DMA3SAD
.L080CF66C: .4byte gUnknown_081B93B0
.L080CF670: .4byte 0x84000200
.L080CF674: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CF678: .4byte 0x06004000 @ VRAM+0x4000
.L080CF67C: .4byte 0x84001800

	thumb_func_start sub_080CF680
sub_080CF680: @ 0x080CF680
.L080CF680:
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #7
	bhi .L080CF704
	lsls r0, r1, #2
	ldr r1, .L080CF698
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080CF698: .4byte gUnknown_080CF69C
	.global gUnknown_080CF69C
gUnknown_080CF69C:
.L080CF69C: @ jump table
	.4byte .L080CF6BC
	.4byte .L080CF6C6
	.4byte .L080CF6D0
	.4byte .L080CF6DA
	.4byte .L080CF6E4
	.4byte .L080CF6EE
	.4byte .L080CF6F8
	.4byte .L080CF702
.L080CF6BC:
	bl sub_080C2AFC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L080CF704
.L080CF6C6:
	bl Settings_GetBattleMsgSpeed
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L080CF704
.L080CF6D0:
	bl sub_080C2B6C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L080CF704
.L080CF6DA:
	bl sub_080C2BA4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L080CF704
.L080CF6E4:
	bl sub_080C2BF0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L080CF704
.L080CF6EE:
	bl sub_080C2C30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L080CF704
.L080CF6F8:
	bl sub_080C2C70
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L080CF704
.L080CF702:
	movs r0, #0
.L080CF704:
	pop {r1}
	bx r1

	thumb_func_start sub_080CF708
sub_080CF708: @ 0x080CF708
.L080CF708:
	push {r4, r5, r6, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r0, #6
	bhi .L080CF7C4
	lsls r0, r0, #2
	ldr r1, .L080CF724
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080CF724: .4byte gUnknown_080CF728
	.global gUnknown_080CF728
gUnknown_080CF728:
.L080CF728: @ jump table
	.4byte .L080CF744
	.4byte .L080CF74C
	.4byte .L080CF754
	.4byte .L080CF75C
	.4byte .L080CF764
	.4byte .L080CF76C
	.4byte .L080CF774
.L080CF744:
	adds r0, r2, #0
	bl sub_080C2B14
	b .L080CF7C4
.L080CF74C:
	adds r0, r2, #0
	bl sub_080C2B4C
	b .L080CF7C4
.L080CF754:
	adds r0, r2, #0
	bl sub_080C2B84
	b .L080CF7C4
.L080CF75C:
	adds r0, r2, #0
	bl sub_080C2BCC
	b .L080CF7C4
.L080CF764:
	adds r0, r2, #0
	bl sub_080C2C0C
	b .L080CF7C4
.L080CF76C:
	adds r0, r2, #0
	bl sub_080C2C4C
	b .L080CF7C4
.L080CF774:
	adds r0, r2, #0
	bl sub_080C2C9C
	bl sub_080C1384
	ldr r0, .L080CF794
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080CF798
	bl BgPicture_LoadPalette
	b .L080CF79C
	.byte 0x00, 0x00
.L080CF794: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080CF798:
	bl sub_080B04BC
.L080CF79C:
	ldr r5, .L080CF7CC
	ldr r2, .L080CF7D0
	movs r6, #0x80
	lsls r6, r6, #3
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	adds r3, r6, #0
	bl Palette_CopyWithEffect
	ldr r2, .L080CF7D4
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	adds r3, r6, #0
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
.L080CF7C4:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080CF7CC: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080CF7D0: .4byte 0x0201B874 @ EWRAM+0x1B874
.L080CF7D4: .4byte 0x03002DB0 @ IWRAM+0x2DB0

	thumb_func_start sub_080CF7D8
sub_080CF7D8: @ 0x080CF7D8
.L080CF7D8:
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r4, r1, #0
	ldr r6, .L080CF830
	movs r5, #0
	ldr r7, .L080CF834
	add r0, sp, #8
	movs r1, #2
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	adds r1, r0, #0
	movs r0, #8
	strh r0, [r1, #6]
	ldrh r0, [r6]
	cmp r0, r4
	bne .L080CF810
	ldrh r0, [r6, #4]
	cmp r0, #0
	bne .L080CF802
	movs r5, #4
.L080CF802:
	add r1, sp, #8
	movs r0, #4
	strh r0, [r1, #6]
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080D0020
.L080CF810:
	ldrh r1, [r6, #2]
	movs r2, #0x10
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	ands r2, r0
	adds r3, r1, #0
	cmp r4, #7
	bls .L080CF824
	b .L080CFBDA
.L080CF824:
	lsls r0, r4, #2
	ldr r1, .L080CF838
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080CF830: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CF834: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CF838: .4byte gUnknown_080CF83C
	.global gUnknown_080CF83C
gUnknown_080CF83C:
.L080CF83C: @ jump table
	.4byte .L080CF85C
	.4byte .L080CF8D4
	.4byte .L080CF958
	.4byte .L080CF9CC
	.4byte .L080CFA50
	.4byte .L080CFAC4
	.4byte .L080CFB38
	.4byte .L080CFBB4
.L080CF85C:
	cmp r3, #0
	beq .L080CF862
	b .L080CFBDA
.L080CF862:
	movs r0, #0xe0
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	movs r0, #0
	adds r1, r7, #0
	movs r2, #0xc
	movs r3, #0x1b
	bl Canvas_FillRect
	ldr r0, .L080CF8C4
	movs r1, #0xc
	movs r2, #0x1b
	adds r3, r5, #0
	bl sub_080CCEC8
	ldr r0, .L080CF8C8
	movs r1, #0x2a
	movs r2, #0x1b
	adds r3, r5, #0
	bl sub_080CCEC8
	movs r0, #0
	bl sub_080CF680
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	mov r1, sp
	adds r1, r1, r0
	adds r1, #8
	add r0, sp, #8
	ldrh r0, [r0, #6]
	strh r0, [r1]
	ldr r0, .L080CF8CC
	add r1, sp, #8
	ldrh r3, [r1]
	movs r1, #0x7c
	movs r2, #0x1b
	bl sub_080CCEC8
	ldr r0, .L080CF8D0
	add r1, sp, #8
	ldrh r3, [r1, #2]
	movs r1, #0xb4
	movs r2, #0x1b
	bl sub_080CCEC8
	b .L080CFBDA
	.byte 0x00, 0x00
.L080CF8C4: .4byte gUnknown_084F18A0
.L080CF8C8: .4byte gUnknown_084F18A4
.L080CF8CC: .4byte gUnknown_084F18AC
.L080CF8D0: .4byte gUnknown_084F18B4
.L080CF8D4:
	movs r4, #0x2b
	subs r4, r4, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0xe0
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	movs r0, #0
	adds r1, r7, #0
	movs r2, #0xc
	adds r3, r4, #0
	bl Canvas_FillRect
	ldr r0, .L080CF944
	movs r1, #0xc
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	ldr r0, .L080CF948
	movs r1, #0x2a
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	ldr r0, .L080CF94C
	movs r1, #0x48
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	movs r0, #1
	bl sub_080CF680
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	mov r1, sp
	adds r1, r1, r0
	adds r1, #8
	add r0, sp, #8
	ldrh r0, [r0, #6]
	strh r0, [r1]
	ldr r0, .L080CF950
	add r1, sp, #8
	ldrh r3, [r1]
	movs r1, #0x7c
	adds r2, r4, #0
	bl sub_080CCEC8
	ldr r0, .L080CF954
	add r1, sp, #8
	ldrh r3, [r1, #2]
	movs r1, #0xb4
	b .L080CFB9A
	.byte 0x00, 0x00
.L080CF944: .4byte gUnknown_084F18BC
.L080CF948: .4byte gUnknown_084F18A0
.L080CF94C: .4byte gUnknown_084F18A4
.L080CF950: .4byte gUnknown_084F18AC
.L080CF954: .4byte gUnknown_084F18B4
.L080CF958:
	movs r4, #0x3b
	subs r4, r4, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0xe0
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	movs r0, #0
	adds r1, r7, #0
	movs r2, #0xc
	adds r3, r4, #0
	bl Canvas_FillRect
	ldr r0, .L080CF9BC
	movs r1, #0xc
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	ldr r0, .L080CF9C0
	movs r1, #0x2a
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	movs r0, #2
	bl sub_080CF680
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	mov r1, sp
	adds r1, r1, r0
	adds r1, #8
	add r0, sp, #8
	ldrh r0, [r0, #6]
	strh r0, [r1]
	ldr r0, .L080CF9C4
	add r1, sp, #8
	ldrh r3, [r1]
	movs r1, #0x8c
	adds r2, r4, #0
	bl sub_080CCEC8
	ldr r0, .L080CF9C8
	add r1, sp, #8
	ldrh r3, [r1, #2]
	movs r1, #0xbc
	b .L080CFB9A
	.byte 0x00, 0x00
.L080CF9BC: .4byte gUnknown_084F18BC
.L080CF9C0: .4byte gUnknown_084F18C0
.L080CF9C4: .4byte gUnknown_084F18C8
.L080CF9C8: .4byte gUnknown_084F18CC
.L080CF9CC:
	movs r4, #0x4b
	subs r4, r4, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0xe0
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	movs r0, #0
	adds r1, r7, #0
	movs r2, #0xc
	adds r3, r4, #0
	bl Canvas_FillRect
	ldr r0, .L080CFA3C
	movs r1, #0xc
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	ldr r0, .L080CFA40
	movs r1, #0x32
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	movs r0, #3
	bl sub_080CF680
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	mov r1, sp
	adds r1, r1, r0
	adds r1, #8
	add r0, sp, #8
	ldrh r0, [r0, #6]
	strh r0, [r1]
	ldr r0, .L080CFA44
	add r1, sp, #8
	ldrh r3, [r1]
	movs r1, #0x5e
	adds r2, r4, #0
	bl sub_080CCEC8
	ldr r0, .L080CFA48
	add r1, sp, #8
	ldrh r3, [r1, #2]
	movs r1, #0x8e
	adds r2, r4, #0
	bl sub_080CCEC8
	ldr r0, .L080CFA4C
	add r1, sp, #8
	ldrh r3, [r1, #4]
	movs r1, #0xbe
	b .L080CFB9A
.L080CFA3C: .4byte gUnknown_084F18D0
.L080CFA40: .4byte gUnknown_084F18BC
.L080CFA44: .4byte gUnknown_084F18D8
.L080CFA48: .4byte gUnknown_084F18E0
.L080CFA4C: .4byte gUnknown_084F18E8
.L080CFA50:
	movs r4, #0x5b
	subs r4, r4, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0xe0
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	movs r0, #0
	adds r1, r7, #0
	movs r2, #0xc
	adds r3, r4, #0
	bl Canvas_FillRect
	ldr r0, .L080CFAB4
	movs r1, #0xc
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	ldr r0, .L080CFAB8
	movs r1, #0x32
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	movs r0, #4
	bl sub_080CF680
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	mov r1, sp
	adds r1, r1, r0
	adds r1, #8
	add r0, sp, #8
	ldrh r0, [r0, #6]
	strh r0, [r1]
	ldr r0, .L080CFABC
	add r1, sp, #8
	ldrh r3, [r1]
	movs r1, #0x88
	adds r2, r4, #0
	bl sub_080CCEC8
	ldr r0, .L080CFAC0
	add r1, sp, #8
	ldrh r3, [r1, #2]
	movs r1, #0xb8
	b .L080CFB9A
	.byte 0x00, 0x00
.L080CFAB4: .4byte gUnknown_084F18D0
.L080CFAB8: .4byte gUnknown_084F18F0
.L080CFABC: .4byte gUnknown_084F18F4
.L080CFAC0: .4byte gUnknown_084F18F8
.L080CFAC4:
	movs r4, #0x6b
	subs r4, r4, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0xe0
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	movs r0, #0
	adds r1, r7, #0
	movs r2, #0xc
	adds r3, r4, #0
	bl Canvas_FillRect
	ldr r0, .L080CFB28
	movs r1, #0xc
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	ldr r0, .L080CFB2C
	movs r1, #0x32
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	movs r0, #5
	bl sub_080CF680
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	mov r1, sp
	adds r1, r1, r0
	adds r1, #8
	add r0, sp, #8
	ldrh r0, [r0, #6]
	strh r0, [r1]
	ldr r0, .L080CFB30
	add r1, sp, #8
	ldrh r3, [r1]
	movs r1, #0x84
	adds r2, r4, #0
	bl sub_080CCEC8
	ldr r0, .L080CFB34
	add r1, sp, #8
	ldrh r3, [r1, #2]
	movs r1, #0xb4
	b .L080CFB9A
	.byte 0x00, 0x00
.L080CFB28: .4byte gUnknown_084F18D0
.L080CFB2C: .4byte gUnknown_084F1900
.L080CFB30: .4byte gUnknown_084F1908
.L080CFB34: .4byte gUnknown_084F1910
.L080CFB38:
	movs r4, #0x7b
	subs r4, r4, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0xe0
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	movs r0, #0
	adds r1, r7, #0
	movs r2, #0xc
	adds r3, r4, #0
	bl Canvas_FillRect
	ldr r0, .L080CFBA4
	movs r1, #0xc
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCEC8
	movs r0, #6
	bl sub_080CF680
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	mov r1, sp
	adds r1, r1, r0
	adds r1, #8
	add r0, sp, #8
	ldrh r0, [r0, #6]
	strh r0, [r1]
	ldr r0, .L080CFBA8
	add r1, sp, #8
	ldrh r3, [r1]
	movs r1, #0x5e
	adds r2, r4, #0
	bl sub_080CCEC8
	ldr r0, .L080CFBAC
	add r1, sp, #8
	ldrh r3, [r1, #2]
	movs r1, #0xa2
	adds r2, r4, #0
	bl sub_080CCEC8
	ldr r0, .L080CFBB0
	add r1, sp, #8
	ldrh r3, [r1, #4]
	movs r1, #0xc8
.L080CFB9A:
	adds r2, r4, #0
	bl sub_080CCEC8
	b .L080CFBDA
	.byte 0x00, 0x00
.L080CFBA4: .4byte gUnknown_084F1918
.L080CFBA8: .4byte gUnknown_084F18AC
.L080CFBAC: .4byte gUnknown_084F1920
.L080CFBB0: .4byte gUnknown_084F1924
.L080CFBB4:
	lsls r0, r3, #0x10
	cmp r0, #0
	beq .L080CFBDA
	movs r0, #0xe0
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	movs r0, #0
	adds r1, r7, #0
	movs r2, #0xc
	movs r3, #0x7b
	bl Canvas_FillRect
	ldr r0, .L080CFBE4
	movs r1, #0x68
	movs r2, #0x7b
	adds r3, r5, #0
	bl sub_080CCEC8
.L080CFBDA:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CFBE4: .4byte gUnknown_084F1928

	thumb_func_start sub_080CFBE8
sub_080CFBE8: @ 0x080CFBE8
.L080CFBE8:
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
.L080CFBEE:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080CF7D8
	adds r4, #1
	cmp r4, #7
	bls .L080CFBEE
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CFC04
sub_080CFC04: @ 0x080CFC04
.L080CFC04:
	push {lr}
	bl sub_080CFBE8
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CFC10
sub_080CFC10: @ 0x080CFC10
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r5, .L080CFCE8
	movs r4, #1
	str r4, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0x1c
	movs r3, #2
	bl Window_CreateOpen
	str r0, [r5, #0xc]
	str r4, [sp]
	movs r0, #1
	movs r1, #2
	movs r2, #0x1c
	movs r3, #2
	bl Window_CreateOpen
	str r0, [r5, #0x10]
	str r4, [sp]
	movs r0, #1
	movs r1, #4
	movs r2, #0x1c
	movs r3, #2
	bl Window_CreateOpen
	str r0, [r5, #0x14]
	str r4, [sp]
	movs r0, #1
	movs r1, #6
	movs r2, #0x1c
	movs r3, #2
	bl Window_CreateOpen
	str r0, [r5, #0x18]
	str r4, [sp]
	movs r0, #1
	movs r1, #8
	movs r2, #0x1c
	movs r3, #2
	bl Window_CreateOpen
	str r0, [r5, #0x1c]
	str r4, [sp]
	movs r0, #1
	movs r1, #0xa
	movs r2, #0x1c
	movs r3, #2
	bl Window_CreateOpen
	str r0, [r5, #0x20]
	str r4, [sp]
	movs r0, #1
	movs r1, #0xc
	movs r2, #0x1c
	movs r3, #2
	bl Window_CreateOpen
	str r0, [r5, #0x24]
	str r4, [sp]
	movs r0, #1
	movs r1, #0xe
	movs r2, #0x1c
	movs r3, #2
	bl Window_CreateOpen
	str r0, [r5, #0x28]
	str r4, [sp]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1a
	movs r3, #4
	bl Window_CreateOpen
	str r0, [r5, #0x2c]
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, .L080CFCEC
	add r0, sp, #4
	str r0, [r1]
	ldr r0, .L080CFCF0
	str r0, [r1, #4]
	ldr r0, .L080CFCF4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080CFCF8
	movs r1, #0x60
	movs r2, #0xc
	movs r3, #4
	bl sub_080CCEC8
	adds r0, r6, #0
	bl sub_080CFBE8
	movs r0, #0
	bl sub_080D0020
	ldr r0, .L080CFCFC
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CFCE8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CFCEC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080CFCF0: .4byte 0x0200F874 @ EWRAM+0xF874
.L080CFCF4: .4byte 0x85002000
.L080CFCF8: .4byte gUnknown_084F1930
.L080CFCFC: .4byte sub_080CF61C

	thumb_func_start sub_080CFD00
sub_080CFD00: @ 0x080CFD00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r6, .L080CFD4C
	movs r0, #0
	mov r8, r0
	ldrh r0, [r6]
	lsls r2, r0, #3
	ldr r1, .L080CFD50
	adds r2, r2, r1
	mov sb, r2
	ldrh r1, [r2]
	mov sl, r1
	bl sub_080CF680
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r0, r8
	strh r0, [r7, #0x1c]
	ldr r0, .L080CFD54
	ldrh r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080CFD58
	ldrh r0, [r6]
	cmp r0, #7
	bne .L080CFD58
	strh r2, [r7, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	b .L080CFEA4
	.byte 0x00, 0x00
.L080CFD4C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CFD50: .4byte gUnknown_084F1938
.L080CFD54: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CFD58:
	ldr r2, .L080CFD84
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov ip, r2
	cmp r5, #0
	beq .L080CFD96
	ldrh r1, [r6]
	movs r0, #7
	strh r0, [r6]
	ldrh r0, [r6, #2]
	cmp r0, #0
	bne .L080CFD88
	movs r0, #1
	strh r0, [r6, #2]
	adds r0, r7, #0
	bl sub_080CFC04
	b .L080CFD8E
	.byte 0x00, 0x00
.L080CFD84: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080CFD88:
	adds r0, r7, #0
	bl sub_080CF7D8
.L080CFD8E:
	movs r0, #0x66
	bl sub_080C51D4
	b .L080CFEA4
.L080CFD96:
	ldr r2, .L080CFDC4
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080CFDF6
	ldrh r0, [r6]
	adds r3, r0, #0
	adds r1, r0, #0
	cmp r3, #0
	beq .L080CFDF6
	cmp r3, #1
	bne .L080CFDC8
	ldrh r0, [r6, #2]
	cmp r0, #0
	beq .L080CFDC8
	strh r5, [r6]
	strh r5, [r6, #2]
	adds r0, r7, #0
	bl sub_080CFC04
	b .L080CFDEA
	.byte 0x00, 0x00
.L080CFDC4: .4byte 0x03003964 @ IWRAM+0x3964
.L080CFDC8:
	lsls r0, r1, #0x10
	cmp r0, #0
	beq .L080CFDDE
	subs r0, r1, #1
	strh r0, [r6]
	ldrh r1, [r6]
	adds r1, #1
	adds r0, r7, #0
	bl sub_080CF7D8
	b .L080CFDEA
.L080CFDDE:
	movs r0, #7
	strh r0, [r6]
	adds r0, r7, #0
	movs r1, #0
	bl sub_080CF7D8
.L080CFDEA:
	movs r0, #0x64
	bl sub_080C51D4
	movs r1, #1
	mov r8, r1
	b .L080CFEA4
.L080CFDF6:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080CFE30
	ldrh r1, [r6]
	cmp r1, #7
	beq .L080CFE30
	ldr r0, [r6]
	cmp r0, #6
	bne .L080CFE1C
	movs r0, #7
	strh r0, [r6]
	movs r0, #1
	strh r0, [r6, #2]
	adds r0, r7, #0
	bl sub_080CFC04
	b .L080CFE2A
.L080CFE1C:
	adds r0, r1, #1
	strh r0, [r6]
	ldrh r1, [r6]
	subs r1, #1
	adds r0, r7, #0
	bl sub_080CF7D8
.L080CFE2A:
	movs r0, #1
	mov r8, r0
	b .L080CFE62
.L080CFE30:
	mov r0, ip
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080CFE6A
	ldrh r0, [r6]
	cmp r0, #7
	beq .L080CFE6A
	cmp r4, #0
	beq .L080CFE4A
	subs r0, r4, #1
	b .L080CFE4E
.L080CFE4A:
	mov r0, sl
	subs r0, #1
.L080CFE4E:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldrh r0, [r6]
	lsls r1, r4, #1
	add r1, sb
	ldrh r1, [r1, #2]
	bl sub_080CF708
	movs r1, #1
	mov r8, r1
.L080CFE62:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080CFEA4
.L080CFE6A:
	mov r0, ip
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080CFEA4
	ldrh r0, [r6]
	cmp r0, #7
	beq .L080CFEA4
	mov r0, sl
	subs r0, #1
	cmp r4, r0
	beq .L080CFE8C
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b .L080CFE8E
.L080CFE8C:
	movs r4, #0
.L080CFE8E:
	ldrh r0, [r6]
	lsls r1, r4, #1
	add r1, sb
	ldrh r1, [r1, #2]
	bl sub_080CF708
	movs r1, #1
	mov r8, r1
	movs r0, #0x64
	bl sub_080C51D4
.L080CFEA4:
	ldr r4, .L080CFEF4
	ldr r0, [r4]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L080CFEBE
	ldrh r0, [r6, #4]
	adds r0, #1
	movs r1, #1
	ands r0, r1
	strh r0, [r6, #4]
	movs r0, #1
	mov r8, r0
.L080CFEBE:
	mov r1, r8
	cmp r1, #1
	bne .L080CFED4
	ldrh r1, [r6]
	adds r0, r7, #0
	bl sub_080CF7D8
	ldr r0, .L080CFEF8
	movs r1, #1
	bl VBlankTask_AddCounted
.L080CFED4:
	ldr r0, [r4]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080CFF08
	ldrh r0, [r6, #2]
	cmp r0, #0
	beq .L080CFEFC
	movs r0, #0
	movs r1, #0
	movs r2, #0xe8
	movs r3, #0xa
	bl sub_080C4A4C
	b .L080CFF08
.L080CFEF4: .4byte 0x030031BC @ IWRAM+0x31BC
.L080CFEF8: .4byte sub_080CF61C
.L080CFEFC:
	movs r0, #0
	movs r1, #0
	movs r2, #0xe8
	movs r3, #0x80
	bl sub_080C4AB0
.L080CFF08:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080CFF18
sub_080CFF18: @ 0x080CFF18
	push {r4, lr}
	ldr r4, .L080CFF74
	ldr r0, [r4, #0xc]
	movs r1, #1
	bl Window_Close
	ldr r0, [r4, #0x10]
	movs r1, #1
	bl Window_Close
	ldr r0, [r4, #0x14]
	movs r1, #1
	bl Window_Close
	ldr r0, [r4, #0x18]
	movs r1, #1
	bl Window_Close
	ldr r0, [r4, #0x1c]
	movs r1, #1
	bl Window_Close
	ldr r0, [r4, #0x20]
	movs r1, #1
	bl Window_Close
	ldr r0, [r4, #0x24]
	movs r1, #1
	bl Window_Close
	ldr r0, [r4, #0x28]
	movs r1, #1
	bl Window_Close
	ldr r0, [r4, #0x2c]
	movs r1, #1
	bl Window_Close
	ldrh r0, [r4, #6]
	cmp r0, #0
	beq .L080CFF78
	ldr r1, [r4, #8]
	movs r0, #1
	str r0, [r1, #0xc]
	b .L080CFF7E
	.byte 0x00, 0x00
.L080CFF74: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CFF78:
	movs r0, #4
	bl sub_080D5B8C
.L080CFF7E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080CFF84
sub_080CFF84: @ 0x080CFF84
	sub sp, #4
	mov r0, sp
	movs r3, #0
	strh r3, [r0]
	ldr r1, .L080CFFBC
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r2, .L080CFFC0
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	mov r0, sp
	strh r3, [r0]
	str r0, [r1]
	ldr r0, .L080CFFC4
	str r0, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	mov r0, sp
	strh r3, [r0]
	str r0, [r1]
	ldr r0, .L080CFFC8
	str r0, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	bx lr
.L080CFFBC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080CFFC0: .4byte 0x81000800
.L080CFFC4: .4byte 0x06001000 @ VRAM+0x1000
.L080CFFC8: .4byte 0x06002000 @ VRAM+0x2000

	thumb_func_start sub_080CFFCC
sub_080CFFCC: @ 0x080CFFCC
	push {lr}
	ldr r0, .L080CFFDC
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080CFFDC: .4byte sub_080CFF84

	thumb_func_start sub_080CFFE0
sub_080CFFE0: @ 0x080CFFE0
.L080CFFE0:
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080D0010
	ldr r1, .L080D0014
	bl Task_Create
	adds r6, r0, #0
	ldr r5, .L080D0018
	movs r0, #0
	str r0, [sp]
	ldr r2, .L080D001C
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	strh r4, [r5, #6]
	adds r0, r6, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080D0010: .4byte gUnknown_084F1970
.L080D0014: .4byte 0x0000FFFF
.L080D0018: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D001C: .4byte 0x05000200 @ PLTT+0x200

	thumb_func_start sub_080D0020
sub_080D0020: @ 0x080D0020
.L080D0020:
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r6, .L080D0074
	adds r0, r4, #0
	bl sub_080CF680
	lsls r0, r0, #0x10
	ldr r2, .L080D0078
	lsrs r0, r0, #0xe
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r0, r0, r2
	ldr r5, [r0]
	cmp r4, #7
	bne .L080D004C
	ldrh r0, [r6, #6]
	cmp r0, #0
	bne .L080D004C
	ldr r5, [r2, #0x74]
.L080D004C:
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, .L080D007C
	ldr r2, .L080D0080
	add r0, sp, #4
	bl CpuSet
	movs r0, #0xc
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0x12
	movs r3, #0x8c
	bl Text_DrawString
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D0074: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D0078: .4byte gUnknown_084F1D5C
.L080D007C: .4byte 0x02013C74 @ EWRAM+0x13C74
.L080D0080: .4byte 0x05000400

	thumb_func_start sub_080D0084
sub_080D0084: @ 0x080D0084
.L080D0084:
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r6, r2, #0
	ldr r5, .L080D00C8
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	str r4, [r5, #0x2c]
	movs r0, #1
	str r0, [r5, #0x28]
	ldr r0, [r5, #0x20]
	cmp r0, #0
	bne .L080D00B2
	str r0, [sp]
	movs r0, #1
	movs r1, #0xd
	movs r2, #0x1c
	movs r3, #7
	bl Window_CreateOpen
	str r0, [r5, #0x20]
.L080D00B2:
	cmp r6, #1
	bne .L080D00BE
	movs r0, #1
	bl YesNo_Create
	str r0, [r5, #0x24]
.L080D00BE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D00C8: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D00CC
sub_080D00CC: @ 0x080D00CC
	push {r4, r5, lr}
	ldr r4, .L080D00E8
	movs r5, #0
	str r5, [r4, #0x28]
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq .L080D00E2
	movs r1, #1
	bl Window_Close
	str r5, [r4, #0x20]
.L080D00E2:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080D00E8: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D00EC
sub_080D00EC: @ 0x080D00EC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080D0108
	ldr r0, [r0, #0x24]
	bl Task_IsFree
	cmp r0, #1
	beq .L080D00FE
	movs r0, #0
.L080D00FE:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D0108: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D010C
sub_080D010C: @ 0x080D010C
	ldr r1, .L080D0114
	ldr r1, [r1]
	strh r1, [r0, #0x1e]
	bx lr
.L080D0114: .4byte 0x030031CC @ IWRAM+0x31CC

	thumb_func_start sub_080D0118
sub_080D0118: @ 0x080D0118
	push {lr}
	ldr r1, .L080D012C
	ldrh r0, [r1, #2]
	cmp r0, #2
	bne .L080D0130
	movs r0, #0x1a
	bl Field_SetState
	b .L080D0150
	.byte 0x00, 0x00
.L080D012C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D0130:
	ldrh r0, [r1]
	cmp r0, #4
	bne .L080D013E
	movs r0, #3
	bl sub_080D5B8C
	b .L080D0150
.L080D013E:
	cmp r0, #3
	beq .L080D014A
	movs r0, #1
	bl sub_0812D0FC
	b .L080D0150
.L080D014A:
	movs r0, #0x19
	bl Field_SetState
.L080D0150:
	pop {r0}
	bx r0

	thumb_func_start sub_080D0154
sub_080D0154: @ 0x080D0154
	push {r4, lr}
	ldr r4, .L080D0168
	ldr r0, .L080D016C
	movs r1, #0
	bl sub_080B6B58
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
.L080D0168: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D016C: .4byte sub_080D0118

	thumb_func_start sub_080D0170
sub_080D0170: @ 0x080D0170
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080D0188
	ldr r0, [r0, #0xc]
	ldr r1, [r0, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080D018C
	movs r0, #1
	b .L080D018E
	.byte 0x00, 0x00
.L080D0188: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D018C:
	movs r0, #0
.L080D018E:
	strh r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080D0194
sub_080D0194: @ 0x080D0194
	ldr r0, .L080D01A0
	ldr r1, [r0, #0xc]
	movs r0, #1
	str r0, [r1, #0xc]
	bx lr
	.byte 0x00, 0x00
.L080D01A0: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D01A4
sub_080D01A4: @ 0x080D01A4
	ldr r1, .L080D01AC
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	bx lr
.L080D01AC: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D01B0
sub_080D01B0: @ 0x080D01B0
.L080D01B0:
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x10
	mov r8, r0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrb r0, [r0]
	bl NumberToDigits
	adds r2, r0, #0
	add r1, sp, #8
	ldrb r0, [r2, #2]
	adds r0, #0x30
	movs r3, #0
	mov sb, r3
	strb r0, [r1]
	ldrb r0, [r2, #1]
	adds r0, #0x30
	strb r0, [r1, #1]
	ldrb r0, [r2]
	adds r0, #0x30
	strb r0, [r1, #2]
	movs r0, #0x3a
	strb r0, [r1, #3]
	mov r1, r8
	ldrb r0, [r1, #1]
	bl NumberToDigits
	adds r2, r0, #0
	add r1, sp, #8
	ldrb r0, [r2, #1]
	adds r0, #0x30
	strb r0, [r1, #4]
	ldrb r0, [r2]
	adds r0, #0x30
	strb r0, [r1, #5]
	adds r0, r1, #0
	mov r3, sb
	strb r3, [r0, #6]
	ldr r1, .L080D0234
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	movs r0, #8
	str r0, [sp, #4]
	add r0, sp, #8
	adds r2, r5, #0
	adds r3, r6, #0
	bl SmallFont_DrawAsciiTinted
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D0234: .4byte 0x0200F874 @ EWRAM+0xF874

	thumb_func_start sub_080D0238
sub_080D0238: @ 0x080D0238
	ldr r2, .L080D0250
	ldr r1, .L080D0254
	ldr r0, .L080D0258
	str r0, [r1]
	ldr r0, .L080D025C
	str r0, [r1, #4]
	ldr r0, .L080D0260
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
	strh r0, [r2, #4]
	bx lr
.L080D0250: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D0254: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D0258: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D025C: .4byte 0x06004000 @ VRAM+0x4000
.L080D0260: .4byte 0x84001800

	thumb_func_start sub_080D0264
sub_080D0264: @ 0x080D0264
.L080D0264:
	push {r4, lr}
	ldr r4, .L080D0280
	ldrh r0, [r4, #4]
	cmp r0, #0
	bne .L080D027A
	ldr r0, .L080D0284
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #1
	strh r0, [r4, #4]
.L080D027A:
	pop {r4}
	pop {r0}
	bx r0
.L080D0280: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D0284: .4byte sub_080D0238
