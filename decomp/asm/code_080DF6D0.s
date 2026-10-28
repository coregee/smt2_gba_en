	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080DF6D0
sub_080DF6D0: @ 0x080DF6D0
.L080DF6D0:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r4, #0
	movs r2, #0
	cmp r4, r3
	bhs .L080DF6F2
.L080DF6DE:
	ldrb r0, [r1]
	adds r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r1, #1
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r3
	blo .L080DF6DE
.L080DF6F2:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080DF6FC
sub_080DF6FC: @ 0x080DF6FC
.L080DF6FC:
	push {r4, r5, r6, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r1, #0
	ldr r5, .L080DF724
	movs r2, #1
	movs r4, #0
.L080DF70C:
	cmp r1, #1
	bhi .L080DF728
	lsls r0, r1, #4
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, r3
	beq .L080DF728
	mov r6, sp
	adds r0, r6, r1
	strb r4, [r0]
	b .L080DF72E
	.byte 0x00, 0x00
.L080DF724: .4byte 0x03006340 @ IWRAM+0x6340
.L080DF728:
	mov r6, sp
	adds r0, r6, r1
	strb r2, [r0]
.L080DF72E:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls .L080DF70C
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #1
	bne .L080DF754
	mov r0, sp
	ldrb r0, [r0, #1]
	adds r1, r0, #0
	cmp r1, #1
	bne .L080DF754
	mov r0, sp
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	movs r0, #1
	b .L080DF756
.L080DF754:
	movs r0, #0
.L080DF756:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080DF760
sub_080DF760: @ 0x080DF760
.L080DF760:
	push {r4, r5, r6, r7, lr}
	ldr r3, .L080DF794
	ldr r0, .L080DF798
	ldrb r1, [r3, #2]
	movs r4, #0xe3
	lsls r4, r4, #8
	adds r2, r4, #0
	adds r1, r1, r2
	strh r1, [r0]
	ldr r1, [r3, #0x18]
	adds r2, r0, #2
	movs r5, #0
	movs r4, #0
	movs r6, #0
.L080DF77C:
	ldrh r0, [r3, #6]
	ldrh r7, [r3, #8]
	cmp r0, r7
	bls .L080DF79C
	ldrb r0, [r1]
	strb r0, [r2]
	adds r1, #1
	adds r2, #1
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	b .L080DF7A2
.L080DF794: .4byte 0x03006300 @ IWRAM+0x6300
.L080DF798: .4byte 0x03006380 @ IWRAM+0x6380
.L080DF79C:
	strb r6, [r2]
	adds r2, #1
	movs r5, #0xff
.L080DF7A2:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xb
	bls .L080DF77C
	str r1, [r3, #0x18]
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080DF7B8
sub_080DF7B8: @ 0x080DF7B8
.L080DF7B8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r7, .L080DF7E4
	movs r1, #0xe3
	lsls r1, r1, #8
	adds r0, r1, #0
	ldrh r4, [r7, #2]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080DF6FC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L080DF7E8
	movs r0, #0
	b .L080DF866
.L080DF7E4: .4byte 0x03006300 @ IWRAM+0x6300
.L080DF7E8:
	movs r6, #1
	mov r8, r6
	movs r4, #0
	ldr r0, .L080DF830
	mov sb, r0
	movs r1, #0x1c
	adds r1, r1, r7
	mov ip, r1
.L080DF7F8:
	lsls r0, r4, #4
	mov r6, sb
	adds r5, r0, r6
	lsls r2, r4, #2
	mov r1, ip
	adds r0, r1, r2
	ldr r3, [r0]
	lsls r0, r4, #1
	mov r6, sp
	adds r1, r6, r0
	ldrh r0, [r7, #0xa]
	strh r0, [r1]
	movs r6, #0
	adds r4, #1
	mov sl, r4
.L080DF816:
	ldrh r0, [r7, #6]
	ldrh r4, [r1]
	cmp r0, r4
	bls .L080DF834
	ldrb r0, [r5]
	strb r0, [r3]
	adds r5, #1
	adds r3, #1
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b .L080DF838
	.byte 0x00, 0x00
.L080DF830: .4byte 0x03006342 @ IWRAM+0x6342
.L080DF834:
	movs r0, #0xff
	mov r8, r0
.L080DF838:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0xb
	bls .L080DF816
	mov r1, ip
	adds r0, r1, r2
	str r3, [r0]
	mov r4, sl
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #1
	bls .L080DF7F8
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r7, #0xa]
	mov r6, r8
	cmp r6, #1
	bne .L080DF864
	ldrh r0, [r7, #2]
	adds r0, #1
	strh r0, [r7, #2]
.L080DF864:
	mov r0, r8
.L080DF866:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080DF878
sub_080DF878: @ 0x080DF878
.L080DF878:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r1
	str r2, [sp]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r4, .L080DF944
	ldr r1, .L080DF948
	ldr r7, .L080DF94C
	movs r3, #0
	mov r8, r1
	movs r5, #0
	movs r2, #0
.L080DF89A:
	strb r5, [r1]
	adds r1, #1
	stm r7!, {r2}
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0xff
	bls .L080DF89A
	ldrh r0, [r4]
	adds r0, #1
	movs r1, #0
	strh r0, [r4]
	strh r6, [r4, #6]
	strh r1, [r4, #8]
	strh r1, [r4, #0xa]
	mov r1, ip
	mov r2, r8
	movs r3, #0
	adds r5, r4, #0
	adds r5, #0xe
	movs r0, #0x1c
	adds r0, r0, r4
	mov sb, r0
	movs r0, #0x2c
	adds r0, r0, r4
	mov sl, r0
	cmp r3, r6
	bhs .L080DF8E6
.L080DF8D2:
	ldrb r0, [r1]
	strb r0, [r2]
	adds r1, #1
	adds r2, #1
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r4, #6]
	cmp r3, r0
	blo .L080DF8D2
.L080DF8E6:
	ldrh r0, [r4, #6]
	ldr r1, .L080DF948
	bl sub_080DF6D0
	movs r1, #0
	strh r0, [r4, #0xc]
	strh r1, [r4, #4]
	strh r1, [r4, #2]
	movs r3, #0
	adds r7, r5, #0
	mov r8, r3
	mov r6, sb
	ldr r1, .L080DF94C
	mov ip, r1
	mov r5, sl
.L080DF904:
	lsls r0, r3, #1
	adds r0, r7, r0
	mov r1, r8
	strh r1, [r0]
	lsls r1, r3, #2
	adds r2, r6, r1
	lsls r0, r3, #8
	add r0, ip
	str r0, [r2]
	adds r2, r5, r1
	ldr r0, [sp]
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #1
	bls .L080DF904
	ldr r0, .L080DF948
	str r0, [r4, #0x18]
	ldr r1, .L080DF950
	movs r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080DF944: .4byte 0x03006300 @ IWRAM+0x6300
.L080DF948: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L080DF94C: .4byte 0x0203BD74 @ EWRAM+0x3BD74
.L080DF950: .4byte 0x0300636C @ IWRAM+0x636C

	thumb_func_start sub_080DF954
sub_080DF954: @ 0x080DF954
.L080DF954:
	push {lr}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, .L080DF970
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	cmp r0, #0
	bne .L080DF978
	ldr r0, .L080DF974
	str r0, [sp]
	str r2, [sp, #4]
	b .L080DF97E
.L080DF970: .4byte 0x04000128 @ REG_SIOCNT
.L080DF974: .4byte 0x0203BC74 @ EWRAM+0x3BC74
.L080DF978:
	ldr r0, .L080DF98C
	str r0, [sp, #4]
	str r2, [sp]
.L080DF97E:
	adds r0, r3, #0
	mov r2, sp
	bl sub_080DF878
	add sp, #8
	pop {r0}
	bx r0
.L080DF98C: .4byte 0x0203BC74 @ EWRAM+0x3BC74

	thumb_func_start sub_080DF990
sub_080DF990: @ 0x080DF990
.L080DF990:
	push {r4, r5, r6, r7, lr}
	ldr r5, .L080DF9E4
	movs r7, #0
	movs r6, #0
.L080DF998:
	lsls r1, r6, #8
	ldr r0, .L080DF9E8
	adds r4, r1, r0
	ldrh r0, [r5, #6]
	adds r1, r4, #0
	bl sub_080DF6D0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r6, #1
	adds r1, r5, #0
	adds r1, #0xe
	adds r1, r1, r2
	ldrh r1, [r1]
	cmp r1, r0
	bne .L080DF9EC
	lsls r1, r6, #2
	adds r0, r5, #0
	adds r0, #0x2c
	adds r0, r0, r1
	ldr r3, [r0]
	movs r1, #0
	adds r2, r6, #1
	ldrh r0, [r5, #6]
	cmp r1, r0
	bhs .L080DF9F0
.L080DF9CC:
	ldrb r0, [r4]
	strb r0, [r3]
	adds r4, #1
	adds r3, #1
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldrh r0, [r5, #6]
	cmp r1, r0
	blo .L080DF9CC
	b .L080DF9F0
	.byte 0x00, 0x00
.L080DF9E4: .4byte 0x03006300 @ IWRAM+0x6300
.L080DF9E8: .4byte 0x0203BD74 @ EWRAM+0x3BD74
.L080DF9EC:
	movs r7, #0xff
	adds r2, r6, #1
.L080DF9F0:
	lsls r0, r2, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #1
	bls .L080DF998
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080DFA00
sub_080DFA00: @ 0x080DFA00
.L080DFA00:
	push {r4, r5, r6, r7, lr}
	ldr r4, .L080DFA20
	movs r7, #0
	movs r5, #0
	ldr r0, .L080DFA24
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #5
	bls .L080DFA14
	b .L080DFB3E
.L080DFA14:
	lsls r0, r1, #2
	ldr r1, .L080DFA28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080DFA20: .4byte 0x03006300 @ IWRAM+0x6300
.L080DFA24: .4byte 0x0300636C @ IWRAM+0x636C
.L080DFA28: .4byte gUnknown_080DFA2C
	.global gUnknown_080DFA2C
gUnknown_080DFA2C:
.L080DFA2C: @ jump table
	.4byte .L080DFB3C
	.4byte .L080DFA44
	.4byte .L080DFA5C
	.4byte .L080DFAA0
	.4byte .L080DFACE
	.4byte .L080DFB18
.L080DFA44:
	ldr r1, .L080DFA58
	movs r0, #0xe1
	lsls r0, r0, #8
	strh r0, [r1]
	ldrh r0, [r4, #0xc]
	strh r0, [r1, #2]
	movs r0, #2
	strb r0, [r6]
	b .L080DFB3C
	.byte 0x00, 0x00
.L080DFA58: .4byte 0x03006380 @ IWRAM+0x6380
.L080DFA5C:
	movs r5, #1
	movs r0, #0xe1
	lsls r0, r0, #8
	bl sub_080DF6FC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080DFB3E
	movs r2, #0
	ldr r6, .L080DFA98
	adds r3, r4, #0
	adds r3, #0xe
	ldr r4, .L080DFA9C
.L080DFA78:
	lsls r1, r2, #1
	adds r1, r3, r1
	lsls r0, r2, #4
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #1
	bls .L080DFA78
	movs r0, #3
	strb r0, [r6]
	bl sub_080DF760
	b .L080DFB3C
.L080DFA98: .4byte 0x0300636C @ IWRAM+0x636C
.L080DFA9C: .4byte 0x03006342 @ IWRAM+0x6342
.L080DFAA0:
	movs r5, #1
	bl sub_080DF7B8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne .L080DFAC4
	ldr r1, .L080DFABC
	movs r0, #0xe4
	lsls r0, r0, #8
	strh r0, [r1]
	ldr r1, .L080DFAC0
	movs r0, #4
	b .L080DFB3A
.L080DFABC: .4byte 0x03006380 @ IWRAM+0x6380
.L080DFAC0: .4byte 0x0300636C @ IWRAM+0x636C
.L080DFAC4:
	cmp r0, #1
	bne .L080DFB3E
	bl sub_080DF760
	b .L080DFB3C
.L080DFACE:
	movs r5, #1
	movs r0, #0xe4
	lsls r0, r0, #8
	bl sub_080DF6FC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080DFB3E
	bl sub_080DF990
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne .L080DFB00
	ldr r0, .L080DFAF8
	strb r1, [r0]
	movs r7, #1
	ldr r0, .L080DFAFC
	strh r1, [r0]
	b .L080DFB3E
.L080DFAF8: .4byte 0x0300636C @ IWRAM+0x636C
.L080DFAFC: .4byte 0x03006380 @ IWRAM+0x6380
.L080DFB00:
	ldr r1, .L080DFB10
	movs r0, #5
	strb r0, [r1]
	ldr r1, .L080DFB14
	movs r0, #0xe5
	lsls r0, r0, #8
	strh r0, [r1]
	b .L080DFB3E
.L080DFB10: .4byte 0x0300636C @ IWRAM+0x636C
.L080DFB14: .4byte 0x03006380 @ IWRAM+0x6380
.L080DFB18:
	movs r5, #1
	movs r0, #0xe5
	lsls r0, r0, #8
	bl sub_080DF6FC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080DFB3E
	ldr r1, .L080DFB5C
	movs r0, #0xe1
	lsls r0, r0, #8
	strh r0, [r1]
	ldrh r0, [r4, #0xc]
	strh r0, [r1, #2]
	ldr r1, .L080DFB60
	movs r0, #2
.L080DFB3A:
	strb r0, [r1]
.L080DFB3C:
	movs r5, #0
.L080DFB3E:
	bl sub_080DFB98
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080DFB4A
	movs r5, #1
.L080DFB4A:
	cmp r5, #0
	beq .L080DFB68
	ldr r1, .L080DFB64
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r0, r1, #0
	b .L080DFB6C
	.byte 0x00, 0x00
.L080DFB5C: .4byte 0x03006380 @ IWRAM+0x6380
.L080DFB60: .4byte 0x0300636C @ IWRAM+0x636C
.L080DFB64: .4byte 0x03006390 @ IWRAM+0x6390
.L080DFB68:
	ldr r0, .L080DFB78
	strh r5, [r0]
.L080DFB6C:
	ldrh r1, [r0]
	ldr r0, .L080DFB7C
	cmp r1, r0
	bhi .L080DFB80
	adds r0, r7, #0
	b .L080DFB82
.L080DFB78: .4byte 0x03006390 @ IWRAM+0x6390
.L080DFB7C: .4byte 0x00000257
.L080DFB80:
	movs r0, #0xff
.L080DFB82:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080DFB88
sub_080DFB88: @ 0x080DFB88
	ldr r0, .L080DFB94
	ldr r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	bx lr
	.byte 0x00, 0x00
.L080DFB94: .4byte 0x04000128 @ REG_SIOCNT

	thumb_func_start sub_080DFB98
sub_080DFB98: @ 0x080DFB98
.L080DFB98:
	push {lr}
	movs r3, #0
	ldr r0, .L080DFBB0
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r2
	cmp r0, #0
	beq .L080DFBB4
	movs r3, #0x10
	b .L080DFBDA
	.byte 0x00, 0x00
.L080DFBB0: .4byte 0x03006360 @ IWRAM+0x6360
.L080DFBB4:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq .L080DFBC2
	movs r3, #0x20
	b .L080DFBDA
.L080DFBC2:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq .L080DFBDA
	lsls r1, r2, #0x1c
	lsrs r1, r1, #0x1c
	lsls r0, r2, #0x14
	lsrs r0, r0, #0x1c
	cmp r1, r0
	beq .L080DFBDA
	movs r3, #0xff
.L080DFBDA:
	adds r0, r3, #0
	pop {r1}
	bx r1

	thumb_func_start sub_080DFBE0
sub_080DFBE0: @ 0x080DFBE0
	push {lr}
	ldr r0, .L080DFBF0
	ldrh r0, [r0]
	cmp r0, #0x78
	bhi .L080DFBF4
	movs r0, #0
	b .L080DFBF6
	.byte 0x00, 0x00
.L080DFBF0: .4byte 0x03006390 @ IWRAM+0x6390
.L080DFBF4:
	movs r0, #1
.L080DFBF6:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080DFBFC
sub_080DFBFC: @ 0x080DFBFC
	push {r4, r5, lr}
	sub sp, #4
	ldr r4, .L080DFC4C
	movs r5, #0
	str r5, [sp]
	ldr r2, .L080DFC50
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	ldr r0, .L080DFC54
	str r0, [r4]
	str r5, [r4, #8]
	str r5, [r4, #4]
	str r5, [r4, #0x14]
	adds r0, r4, #0
	bl sub_080E0DC8
	adds r0, r4, #0
	bl sub_080E1610
	str r5, [r4, #0xc]
	bl sub_080C3100
	str r0, [r4, #0x10]
	bl sub_080C3168
	str r0, [r4, #0x18]
	strb r5, [r4, #0x1c]
	movs r0, #0xff
	str r0, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x54
	strh r5, [r0]
	adds r4, #0x56
	strh r5, [r4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080DFC4C: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DFC50: .4byte 0x05000034 @ PLTT+0x34
.L080DFC54: .4byte 0x15273950

	thumb_func_start sub_080DFC58
sub_080DFC58: @ 0x080DFC58
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	ldr r0, .L080DFCA8
	mov r8, r0
	ldr r5, .L080DFCAC
	movs r0, #0
	str r0, [sp]
	movs r4, #8
	str r4, [sp, #4]
	mov r0, r8
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl DigitFont_DrawStringTinted
	movs r6, #4
	str r6, [sp]
	str r4, [sp, #4]
	mov r0, r8
	adds r1, r5, #0
	movs r2, #0x50
	movs r3, #0
	bl DigitFont_DrawStringTinted
	ldr r0, .L080DFCB0
	str r6, [sp]
	str r4, [sp, #4]
	adds r1, r5, #0
	movs r2, #0xa0
	movs r3, #0
	bl DigitFont_DrawStringTinted
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080DFCA8: .4byte gUnknown_08589C94
.L080DFCAC: .4byte 0x02001000 @ EWRAM+0x1000
.L080DFCB0: .4byte gUnknown_08589CA0

	thumb_func_start sub_080DFCB4
sub_080DFCB4: @ 0x080DFCB4
	ldr r1, .L080DFCC8
	ldr r0, .L080DFCCC
	str r0, [r1]
	ldr r0, .L080DFCD0
	str r0, [r1, #4]
	ldr r0, .L080DFCD4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080DFCC8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080DFCCC: .4byte 0x02001000 @ EWRAM+0x1000
.L080DFCD0: .4byte 0x06016000 @ VRAM+0x16000
.L080DFCD4: .4byte 0x84000400

	thumb_func_start sub_080DFCD8
sub_080DFCD8: @ 0x080DFCD8
	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r4, .L080DFD00
	ldrh r1, [r4]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080DFD04
	ldrh r0, [r2, #0x24]
	adds r0, #1
	strh r0, [r2, #0x1e]
	strh r3, [r2, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	b .L080DFD66
	.byte 0x00, 0x00
.L080DFD00: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080DFD04:
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080DFD1C
	movs r0, #0xff
	strh r0, [r2, #0x1e]
	strh r3, [r2, #0x1c]
	movs r0, #0x66
	bl sub_080C51D4
	b .L080DFD66
.L080DFD1C:
	ldr r0, .L080DFD44
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq .L080DFD48
	ldrh r0, [r2, #0x24]
	cmp r0, #0
	bne .L080DFD36
	movs r0, #5
	strh r0, [r2, #0x24]
.L080DFD36:
	ldrh r0, [r2, #0x24]
	subs r0, #1
	strh r0, [r2, #0x24]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080DFD66
.L080DFD44: .4byte 0x03003964 @ IWRAM+0x3964
.L080DFD48:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080DFD66
	ldrh r0, [r2, #0x24]
	adds r0, #1
	strh r0, [r2, #0x24]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls .L080DFD60
	strh r3, [r2, #0x24]
.L080DFD60:
	movs r0, #0x64
	bl sub_080C51D4
.L080DFD66:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080DFD6C
sub_080DFD6C: @ 0x080DFD6C
	push {lr}
	sub sp, #8
	bl Task_GetParent
	ldr r1, .L080DFD98
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
.L080DFD98: .4byte gUnknown_08589CA8

	thumb_func_start sub_080DFD9C
sub_080DFD9C: @ 0x080DFD9C
	push {lr}
	sub sp, #4
	ldr r1, .L080DFDBC
	ldr r2, .L080DFDC0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0xc0
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080DFDBC: .4byte gUnknown_08580F80
.L080DFDC0: .4byte 0x030030F0 @ IWRAM+0x30F0

	thumb_func_start sub_080DFDC4
sub_080DFDC4: @ 0x080DFDC4
.L080DFDC4:
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r1, .L080DFE08
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	cmp r2, #0x3f
	bhi .L080DFE00
	lsrs r1, r0, #0x15
	lsls r1, r1, #5
	adds r1, r2, r1
	lsls r1, r1, #0x10
	ldr r0, .L080DFE0C
	adds r1, r1, r0
	lsrs r1, r1, #0x10
	ldr r0, .L080DFE10
	str r1, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	adds r2, r5, #0
	movs r3, #0
	bl Sprite_Draw
.L080DFE00:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L080DFE08: .4byte 0xFFE00000
.L080DFE0C: .4byte 0x02FA0000
.L080DFE10: .4byte gUnknown_080087C8

	thumb_func_start sub_080DFE14
sub_080DFE14: @ 0x080DFE14
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	ldr r1, .L080DFEFC
	adds r4, r1, #0
	adds r4, #0xb0
	movs r0, #5
	strb r0, [r4]
	ldr r5, [r1, #4]
	str r5, [r4, #0x10]
	ldr r6, [r1, #8]
	str r6, [r4, #0x14]
	ldr r0, [r1, #0xc]
	str r0, [r4, #0x18]
	ldr r0, [r1, #0x10]
	str r0, [r4, #0x1c]
	ldr r0, .L080DFF00
	mov sl, r0
	adds r0, r5, #0
	mov r1, sl
	bl __udivsi3
	strb r0, [r4, #1]
	ldr r0, .L080DFF04
	mov sb, r0
	adds r0, r5, #0
	mov r1, sb
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #2]
	movs r0, #0xfa
	lsls r0, r0, #2
	mov r8, r0
	adds r0, r5, #0
	mov r1, r8
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #3]
	adds r0, r5, #0
	movs r1, #0x64
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #4]
	adds r0, r5, #0
	movs r1, #0xa
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #5]
	adds r0, r5, #0
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #6]
	adds r0, r6, #0
	mov r1, sl
	bl __udivsi3
	strb r0, [r4, #7]
	adds r0, r6, #0
	mov r1, sb
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #8]
	adds r0, r6, #0
	mov r1, r8
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #9]
	adds r0, r6, #0
	movs r1, #0x64
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #0xa]
	adds r0, r6, #0
	movs r1, #0xa
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #0xb]
	adds r0, r6, #0
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #0xc]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080DFEFC: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080DFF00: .4byte 0x000186A0
.L080DFF04: .4byte 0x00002710

	thumb_func_start sub_080DFF08
sub_080DFF08: @ 0x080DFF08
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r6, .L080E0010
	movs r0, #0xb0
	rsbs r0, r0, #0
	adds r0, r0, r6
	mov r8, r0
	movs r3, #0
	movs r0, #0
	strh r0, [r5, #0x1e]
	strh r0, [r5, #0x1c]
	ldr r2, .L080E0014
	ldrh r1, [r2]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E0020
	movs r0, #0x65
	bl sub_080C51D4
	strh r7, [r5, #0x1c]
	ldr r1, [r6, #0x18]
	ldr r0, [r6, #0x10]
	cmp r1, r0
	bhs .L080DFF44
	str r1, [r6, #0x10]
.L080DFF44:
	ldr r7, [r6, #0x10]
	mov r0, r8
	str r7, [r0, #4]
	ldr r1, [r6, #0x1c]
	ldr r0, [r6, #0x14]
	cmp r1, r0
	bhs .L080DFF54
	str r1, [r6, #0x14]
.L080DFF54:
	ldr r4, [r6, #0x14]
	mov r0, r8
	str r4, [r0, #8]
	ldr r0, .L080E0018
	mov r8, r0
	adds r0, r7, #0
	mov r1, r8
	bl __udivsi3
	strb r0, [r6, #1]
	ldr r0, .L080E001C
	mov sb, r0
	adds r0, r7, #0
	mov r1, sb
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r6, #2]
	movs r5, #0xfa
	lsls r5, r5, #2
	adds r0, r7, #0
	adds r1, r5, #0
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r6, #3]
	adds r0, r7, #0
	movs r1, #0x64
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r6, #4]
	adds r0, r7, #0
	movs r1, #0xa
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r6, #5]
	adds r0, r7, #0
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r6, #6]
	adds r0, r4, #0
	mov r1, r8
	bl __udivsi3
	strb r0, [r6, #7]
	adds r0, r4, #0
	mov r1, sb
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r6, #8]
	adds r0, r4, #0
	adds r1, r5, #0
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r6, #9]
	adds r0, r4, #0
	movs r1, #0x64
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r6, #0xa]
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r6, #0xb]
	adds r0, r4, #0
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r6, #0xc]
	b .L080E0118
.L080E0010: .4byte 0x0203B604 @ EWRAM+0x3B604
.L080E0014: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E0018: .4byte 0x000186A0
.L080E001C: .4byte 0x00002710
.L080E0020:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L080E003C
	movs r0, #0x66
	bl sub_080C51D4
	strh r7, [r5, #0x1c]
	movs r0, #0xff
	strh r0, [r5, #0x1e]
	b .L080E0118
.L080E003C:
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L080E0072
	movs r0, #0x66
	bl sub_080C51D4
	str r4, [r6, #0x10]
	str r4, [r6, #0x14]
	mov r0, r8
	str r4, [r0, #4]
	str r4, [r0, #8]
	movs r1, #0
	adds r3, r6, #1
	movs r2, #0
.L080E005C:
	adds r0, r3, r1
	strb r2, [r0]
	adds r0, r1, #6
	adds r0, r3, r0
	strb r2, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #5
	bls .L080E005C
	b .L080E0118
.L080E0072:
	ldr r0, .L080E0094
	ldrh r1, [r0]
	movs r0, #0x88
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080E0098
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge .L080E00DE
	movs r0, #5
	strb r0, [r6]
	b .L080E00DE
	.byte 0x00, 0x00
.L080E0094: .4byte 0x03003964 @ IWRAM+0x3964
.L080E0098:
	movs r0, #0x88
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E00B4
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	ble .L080E00DE
	strb r3, [r6]
	b .L080E00DE
.L080E00B4:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080E00E6
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r1, #6
	adds r2, r6, #1
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r0, #6
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #9
	ble .L080E00DE
	strb r3, [r1]
.L080E00DE:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080E0118
.L080E00E6:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080E0118
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r1, #6
	adds r2, r6, #1
	adds r1, r1, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r0, #6
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge .L080E0112
	movs r0, #9
	strb r0, [r1]
.L080E0112:
	movs r0, #0x64
	bl sub_080C51D4
.L080E0118:
	movs r0, #1
	ldrsb r0, [r6, r0]
	ldr r5, .L080E01A4
	adds r2, r0, #0
	muls r2, r5, r2
	movs r0, #2
	ldrsb r0, [r6, r0]
	ldr r4, .L080E01A8
	muls r0, r4, r0
	adds r2, r2, r0
	movs r1, #3
	ldrsb r1, [r6, r1]
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	movs r0, #4
	ldrsb r0, [r6, r0]
	movs r3, #0x64
	muls r0, r3, r0
	adds r2, r2, r0
	movs r1, #5
	ldrsb r1, [r6, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #6
	ldrsb r0, [r6, r0]
	adds r2, r2, r0
	str r2, [r6, #0x10]
	movs r0, #7
	ldrsb r0, [r6, r0]
	adds r2, r0, #0
	muls r2, r5, r2
	movs r0, #8
	ldrsb r0, [r6, r0]
	muls r0, r4, r0
	adds r2, r2, r0
	movs r1, #9
	ldrsb r1, [r6, r1]
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	movs r0, #0xa
	ldrsb r0, [r6, r0]
	muls r0, r3, r0
	adds r2, r2, r0
	movs r1, #0xb
	ldrsb r1, [r6, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #0xc
	ldrsb r0, [r6, r0]
	adds r2, r2, r0
	str r2, [r6, #0x14]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E01A4: .4byte 0x000186A0
.L080E01A8: .4byte 0x00002710

	thumb_func_start sub_080E01AC
sub_080E01AC: @ 0x080E01AC
	push {r4, r5, r6, r7, lr}
	bl Task_GetParent
	ldr r7, .L080E0208
	movs r0, #0x5e
	movs r1, #0xa
	movs r2, #0x58
	movs r3, #0xe
	bl sub_080DFDC4
	ldr r0, [r7, #0x14]
	bl NumberToDigits
	adds r5, r0, #0
	movs r6, #5
.L080E01CA:
	movs r1, #0
	ldrsb r1, [r7, r1]
	lsls r0, r6, #0x18
	asrs r2, r0, #0x18
	cmp r1, r2
	bne .L080E020C
	ldrb r0, [r5]
	adds r0, #0x30
	lsls r4, r2, #0x13
	movs r1, #0xc4
	lsls r1, r1, #0xf
	adds r4, r4, r1
	lsrs r4, r4, #0x10
	movs r1, #0xc
	adds r2, r4, #0
	movs r3, #0xe
	bl sub_080DFDC4
	movs r0, #0x3e
	movs r1, #0xa
	adds r2, r4, #0
	movs r3, #3
	bl sub_080DFDC4
	movs r0, #0x3c
	movs r1, #0xa
	adds r2, r4, #0
	movs r3, #0x15
	bl sub_080DFDC4
	b .L080E0222
.L080E0208: .4byte 0x0203B604 @ EWRAM+0x3B604
.L080E020C:
	ldrb r0, [r5]
	adds r0, #0x30
	lsls r2, r2, #0x13
	movs r1, #0xc4
	lsls r1, r1, #0xf
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #0xa
	movs r3, #0xe
	bl sub_080DFDC4
.L080E0222:
	adds r5, #1
	lsls r0, r6, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r6, r0, #0x18
	cmp r0, #0
	bge .L080E01CA
	movs r0, #0x54
	movs r1, #0xc
	movs r2, #0x56
	movs r3, #0x25
	bl sub_080DFDC4
	movs r0, #0x4f
	movs r1, #0xc
	movs r2, #0x5e
	movs r3, #0x25
	bl sub_080DFDC4
	movs r0, #0x54
	movs r1, #0xc
	movs r2, #0x66
	movs r3, #0x25
	bl sub_080DFDC4
	movs r0, #0x41
	movs r1, #0xc
	movs r2, #0x6e
	movs r3, #0x25
	bl sub_080DFDC4
	movs r0, #0x4c
	movs r1, #0xc
	movs r2, #0x76
	movs r3, #0x25
	bl sub_080DFDC4
	movs r0, #0x5e
	movs r1, #0xa
	movs r2, #0x58
	movs r3, #0x31
	bl sub_080DFDC4
	ldr r0, [r7, #0x1c]
	bl NumberToDigits
	adds r5, r0, #0
	movs r6, #5
.L080E0284:
	ldrb r0, [r5]
	adds r0, #0x30
	lsls r4, r6, #0x18
	asrs r4, r4, #0x18
	lsls r2, r4, #0x13
	movs r1, #0xc4
	lsls r1, r1, #0xf
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #0xa
	movs r3, #0x31
	bl sub_080DFDC4
	adds r5, #1
	subs r4, #1
	lsls r4, r4, #0x18
	lsrs r6, r4, #0x18
	cmp r4, #0
	bge .L080E0284
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080E02B0
sub_080E02B0: @ 0x080E02B0
.L080E02B0:
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	adds r4, r1, #0
	movs r1, #0xff
	strb r1, [r4]
	ldr r5, [r0, #4]
	str r5, [r4, #0x10]
	ldr r6, [r0, #8]
	str r6, [r4, #0x14]
	ldr r1, [r0, #0xc]
	str r1, [r4, #0x18]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x1c]
	ldr r0, .L080E0394
	mov sl, r0
	adds r0, r5, #0
	mov r1, sl
	bl __udivsi3
	strb r0, [r4, #1]
	ldr r0, .L080E0398
	mov sb, r0
	adds r0, r5, #0
	mov r1, sb
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #2]
	movs r0, #0xfa
	lsls r0, r0, #2
	mov r8, r0
	adds r0, r5, #0
	mov r1, r8
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #3]
	adds r0, r5, #0
	movs r1, #0x64
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #4]
	adds r0, r5, #0
	movs r1, #0xa
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #5]
	adds r0, r5, #0
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #6]
	adds r0, r6, #0
	mov r1, sl
	bl __udivsi3
	strb r0, [r4, #7]
	adds r0, r6, #0
	mov r1, sb
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #8]
	adds r0, r6, #0
	mov r1, r8
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #9]
	adds r0, r6, #0
	movs r1, #0x64
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #0xa]
	adds r0, r6, #0
	movs r1, #0xa
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #0xb]
	adds r0, r6, #0
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #0xc]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080E0394: .4byte 0x000186A0
.L080E0398: .4byte 0x00002710

	thumb_func_start sub_080E039C
sub_080E039C: @ 0x080E039C
	push {lr}
	ldr r0, .L080E03AC
	adds r1, r0, #0
	adds r1, #0xb0
	bl sub_080E02B0
	pop {r0}
	bx r0
.L080E03AC: .4byte 0x0203B554 @ EWRAM+0x3B554

	thumb_func_start sub_080E03B0
sub_080E03B0: @ 0x080E03B0
	push {lr}
	ldr r0, .L080E03C0
	adds r1, r0, #0
	adds r1, #0x58
	bl sub_080E02B0
	pop {r0}
	bx r0
.L080E03C0: .4byte 0x0203B5AC @ EWRAM+0x3B5AC

	thumb_func_start sub_080E03C4
sub_080E03C4: @ 0x080E03C4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L080E042C
	adds r4, #0x50
	movs r0, #4
	strb r0, [r4]
	ldr r5, [r1, #0x14]
	str r5, [r4, #8]
	ldr r0, [r1, #0x18]
	str r0, [r4, #0xc]
	ldr r1, .L080E0430
	adds r0, r5, #0
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, #0
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #2]
	adds r0, r5, #0
	movs r1, #0x64
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #3]
	adds r0, r5, #0
	movs r1, #0xa
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #4]
	adds r0, r5, #0
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E042C: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E0430: .4byte 0x00002710

	thumb_func_start sub_080E0434
sub_080E0434: @ 0x080E0434
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x50
	ldr r0, .L080E04C0
	mov r8, r0
	movs r3, #0
	movs r0, #0
	strh r0, [r6, #0x1e]
	strh r0, [r6, #0x1c]
	ldr r2, .L080E04C4
	ldrh r1, [r2]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E04CC
	movs r0, #0x65
	bl sub_080C51D4
	strh r7, [r6, #0x1c]
	ldr r1, [r5, #0xc]
	ldr r0, [r5, #8]
	cmp r1, r0
	bhs .L080E046C
	str r1, [r5, #8]
.L080E046C:
	ldr r4, [r5, #8]
	mov r0, r8
	str r4, [r0, #0x14]
	ldr r1, .L080E04C8
	adds r0, r4, #0
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r5, #1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r5, #2]
	adds r0, r4, #0
	movs r1, #0x64
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r5, #3]
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r5, #4]
	adds r0, r4, #0
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r5, #5]
	b .L080E05B8
.L080E04C0: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E04C4: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E04C8: .4byte 0x00002710
.L080E04CC:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L080E04E8
	movs r0, #0x66
	bl sub_080C51D4
	strh r7, [r6, #0x1c]
	movs r0, #0xff
	strh r0, [r6, #0x1e]
	b .L080E05B8
.L080E04E8:
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L080E0516
	movs r0, #0x66
	bl sub_080C51D4
	str r4, [r5, #8]
	mov r0, r8
	str r4, [r0, #0x14]
	movs r1, #0
	adds r2, r6, #0
	adds r2, #0x51
	movs r3, #0
.L080E0506:
	adds r0, r2, r1
	strb r3, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #4
	bls .L080E0506
	b .L080E05B8
.L080E0516:
	ldr r0, .L080E0538
	ldrh r1, [r0]
	movs r0, #0x88
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080E053C
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge .L080E0580
	movs r0, #4
	strb r0, [r5]
	b .L080E0580
	.byte 0x00, 0x00
.L080E0538: .4byte 0x03003964 @ IWRAM+0x3964
.L080E053C:
	movs r0, #0x88
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E0558
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	ble .L080E0580
	strb r3, [r5]
	b .L080E0580
.L080E0558:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080E0588
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r2, r6, #0
	adds r2, #0x51
	adds r1, r2, r1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r5, r0]
	adds r2, r2, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #9
	ble .L080E0580
	strb r3, [r2]
.L080E0580:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080E05B8
.L080E0588:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080E05B8
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r2, r6, #0
	adds r2, #0x51
	adds r1, r2, r1
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r5, r0]
	adds r2, r2, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bge .L080E05B2
	movs r0, #9
	strb r0, [r2]
.L080E05B2:
	movs r0, #0x64
	bl sub_080C51D4
.L080E05B8:
	movs r1, #1
	ldrsb r1, [r5, r1]
	ldr r0, .L080E05FC
	adds r2, r1, #0
	muls r2, r0, r2
	movs r1, #2
	ldrsb r1, [r5, r1]
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	movs r1, #3
	ldrsb r1, [r5, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r2, r2, r0
	movs r1, #4
	ldrsb r1, [r5, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #5
	ldrsb r0, [r5, r0]
	adds r2, r2, r0
	str r2, [r5, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E05FC: .4byte 0x00002710

	thumb_func_start sub_080E0600
sub_080E0600: @ 0x080E0600
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl Task_GetParent
	adds r7, r4, #0
	adds r7, #0x50
	ldr r0, [r7, #8]
	bl NumberToDigits
	adds r5, r0, #0
	movs r6, #4
.L080E0616:
	movs r1, #0
	ldrsb r1, [r7, r1]
	lsls r0, r6, #0x18
	asrs r2, r0, #0x18
	cmp r1, r2
	bne .L080E0654
	ldrb r0, [r5]
	adds r0, #0x30
	lsls r4, r2, #0x13
	movs r1, #0xc4
	lsls r1, r1, #0xf
	adds r4, r4, r1
	lsrs r4, r4, #0x10
	movs r1, #0xc
	adds r2, r4, #0
	movs r3, #0xe
	bl sub_080DFDC4
	movs r0, #0x3e
	movs r1, #0xa
	adds r2, r4, #0
	movs r3, #3
	bl sub_080DFDC4
	movs r0, #0x3c
	movs r1, #0xa
	adds r2, r4, #0
	movs r3, #0x15
	bl sub_080DFDC4
	b .L080E066A
.L080E0654:
	ldrb r0, [r5]
	adds r0, #0x30
	lsls r2, r2, #0x13
	movs r1, #0xc4
	lsls r1, r1, #0xf
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #0xa
	movs r3, #0xe
	bl sub_080DFDC4
.L080E066A:
	adds r5, #1
	lsls r0, r6, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r6, r0, #0x18
	cmp r0, #0
	bge .L080E0616
	movs r0, #0x54
	movs r1, #0xc
	movs r2, #0x56
	movs r3, #0x25
	bl sub_080DFDC4
	movs r0, #0x4f
	movs r1, #0xc
	movs r2, #0x5e
	movs r3, #0x25
	bl sub_080DFDC4
	movs r0, #0x54
	movs r1, #0xc
	movs r2, #0x66
	movs r3, #0x25
	bl sub_080DFDC4
	movs r0, #0x41
	movs r1, #0xc
	movs r2, #0x6e
	movs r3, #0x25
	bl sub_080DFDC4
	movs r0, #0x4c
	movs r1, #0xc
	movs r2, #0x76
	movs r3, #0x25
	bl sub_080DFDC4
	ldr r0, [r7, #0xc]
	bl NumberToDigits
	adds r5, r0, #0
	movs r6, #4
.L080E06C0:
	ldrb r0, [r5]
	adds r0, #0x30
	lsls r4, r6, #0x18
	asrs r4, r4, #0x18
	lsls r2, r4, #0x13
	movs r1, #0xc4
	lsls r1, r1, #0xf
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #0xa
	movs r3, #0x31
	bl sub_080DFDC4
	adds r5, #1
	subs r4, #1
	lsls r4, r4, #0x18
	lsrs r6, r4, #0x18
	cmp r4, #0
	bge .L080E06C0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080E06EC
sub_080E06EC: @ 0x080E06EC
.L080E06EC:
	push {r4, r5, lr}
	adds r4, r1, #0
	movs r1, #0xff
	strb r1, [r4]
	ldr r5, [r0, #0x14]
	str r5, [r4, #8]
	ldr r0, [r0, #0x18]
	str r0, [r4, #0xc]
	ldr r1, .L080E0750
	adds r0, r5, #0
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, #0
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #2]
	adds r0, r5, #0
	movs r1, #0x64
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #3]
	adds r0, r5, #0
	movs r1, #0xa
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #4]
	adds r0, r5, #0
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E0750: .4byte 0x00002710

	thumb_func_start sub_080E0754
sub_080E0754: @ 0x080E0754
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080E0764
	adds r1, #0x50
	bl sub_080E06EC
	pop {r0}
	bx r0
.L080E0764: .4byte 0x0203B554 @ EWRAM+0x3B554

	thumb_func_start sub_080E0768
sub_080E0768: @ 0x080E0768
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080E0778
	adds r1, #0x50
	bl sub_080E06EC
	pop {r0}
	bx r0
.L080E0778: .4byte 0x0203B5AC @ EWRAM+0x3B5AC

	thumb_func_start sub_080E077C
sub_080E077C: @ 0x080E077C
	push {r4, lr}
	ldr r3, .L080E07C8
	adds r2, r0, #0
	adds r2, #0x50
	movs r0, #1
	strb r0, [r2]
	ldr r0, .L080E07CC
	strh r0, [r2, #6]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r2, #4]
	movs r1, #0
	movs r0, #0x58
	adds r0, r0, r3
	mov ip, r0
	movs r4, #0
.L080E079C:
	adds r0, r2, r1
	strb r4, [r0, #1]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	bls .L080E079C
	adds r0, r3, #0
	adds r0, #0x54
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	mov r0, ip
	adds r0, #0x54
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E07C8: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E07CC: .4byte 0x0000FFFF

	thumb_func_start sub_080E07D0
sub_080E07D0: @ 0x080E07D0
	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r4, .L080E07F8
	ldrh r1, [r4]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E07FC
	ldrh r0, [r2, #0x24]
	adds r0, #1
	strh r0, [r2, #0x1e]
	strh r3, [r2, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	b .L080E085E
	.byte 0x00, 0x00
.L080E07F8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E07FC:
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080E0814
	movs r0, #0xff
	strh r0, [r2, #0x1e]
	strh r3, [r2, #0x1c]
	movs r0, #0x66
	bl sub_080C51D4
	b .L080E085E
.L080E0814:
	ldr r0, .L080E083C
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq .L080E0840
	ldrh r0, [r2, #0x24]
	cmp r0, #0
	bne .L080E082E
	movs r0, #6
	strh r0, [r2, #0x24]
.L080E082E:
	ldrh r0, [r2, #0x24]
	subs r0, #1
	strh r0, [r2, #0x24]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080E085E
.L080E083C: .4byte 0x03003964 @ IWRAM+0x3964
.L080E0840:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080E085E
	ldrh r0, [r2, #0x24]
	adds r0, #1
	strh r0, [r2, #0x24]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls .L080E0858
	strh r3, [r2, #0x24]
.L080E0858:
	movs r0, #0x64
	bl sub_080C51D4
.L080E085E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080E0864
sub_080E0864: @ 0x080E0864
.L080E0864:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldr r0, .L080E08C4
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r7, r0, r1
	movs r2, #0
	movs r1, #0
	ldr r3, .L080E08C8
	mov sl, r3
.L080E0882:
	lsls r0, r1, #2
	ldr r3, .L080E08CC
	adds r0, r0, r3
	ldrh r5, [r0]
	adds r4, r5, #0
	ldrh r6, [r0, #2]
	mov r8, r6
	cmp r6, #0
	beq .L080E08FC
	mov r0, sb
	cmp r0, #0x80
	bne .L080E08D4
	adds r0, r5, #0
	str r1, [sp]
	str r2, [sp, #4]
	bl Item_GetSlotMask
	mov r3, sb
	ands r0, r3
	ldr r1, [sp]
	ldr r2, [sp, #4]
	cmp r0, #0
	beq .L080E08FC
	ldr r3, .L080E08D0
	adds r0, r5, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi .L080E08FC
	strh r5, [r7]
	strh r6, [r7, #2]
	b .L080E08F4
	.byte 0x00, 0x00
.L080E08C4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E08C8: .4byte 0x00000159
.L080E08CC: .4byte 0x030051AC @ IWRAM+0x51AC
.L080E08D0: .4byte 0xFFFFFEE0
.L080E08D4:
	adds r0, r4, #0
	str r1, [sp]
	str r2, [sp, #4]
	bl Item_GetSlotMask
	mov r3, sb
	ands r0, r3
	ldr r1, [sp]
	ldr r2, [sp, #4]
	cmp r0, #0
	beq .L080E08FC
	cmp r4, #0xfe
	bhi .L080E08FC
	strh r4, [r7]
	mov r0, r8
	strh r0, [r7, #2]
.L080E08F4:
	adds r7, #4
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L080E08FC:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, sl
	bls .L080E0882
	ldr r0, .L080E0924
	strh r0, [r7]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r7, #2]
	adds r0, r2, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080E0924: .4byte 0x0000FFFF

	thumb_func_start sub_080E0928
sub_080E0928: @ 0x080E0928
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r1, .L080E0950
	ldrh r0, [r4, #0x24]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl sub_080E0864
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r5, r3, #0
	cmp r3, #0
	bne .L080E0954
	movs r0, #0xff
	strh r0, [r4, #0x1e]
	b .L080E0976
.L080E0950: .4byte gUnknown_0858A818
.L080E0954:
	cmp r3, #4
	bhi .L080E0966
	str r3, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #1
	bl sub_08126928
	b .L080E0976
.L080E0966:
	movs r0, #5
	str r0, [sp]
	movs r0, #1
	movs r1, #0x10
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
.L080E0976:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E0980
sub_080E0980: @ 0x080E0980
	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r4, .L080E09A0
	ldrh r1, [r4]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E09A4
	strh r3, [r2, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	b .L080E09B6
.L080E09A0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E09A4:
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080E09B6
	strh r3, [r2, #0x1c]
	movs r0, #0x66
	bl sub_080C51D4
.L080E09B6:
	movs r0, #0x4e
	movs r1, #0xf
	movs r2, #0x7c
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x4f
	movs r1, #0xf
	movs r2, #0x84
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x54
	movs r1, #0xf
	movs r2, #0x8c
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x48
	movs r1, #0xf
	movs r2, #0x94
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x49
	movs r1, #0xf
	movs r2, #0x9c
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x4e
	movs r1, #0xf
	movs r2, #0xa4
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x47
	movs r1, #0xf
	movs r2, #0xac
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x21
	movs r1, #0xf
	movs r2, #0xb4
	movs r3, #0x28
	bl sub_080DFDC4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Battle_DrawItemListPage
Battle_DrawItemListPage: @ 0x080E0A1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x24
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0x12
	bl memset
	ldr r0, .L080E0AD8
	mov sl, r0
	ldr r0, [r6, #0x18]
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
	str r1, [sp]
	movs r4, #0x10
	str r4, [sp, #4]
	ldrh r2, [r5, #0x24]
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
	ldr r0, [r6, #0x14]
	movs r1, #0
	str r1, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	movs r0, #1
	bl sub_08126D1C
	adds r6, r0, #0
	ldr r0, .L080E0ADC
	mov r1, r8
	str r1, [sp]
	movs r1, #0x52
	str r1, [sp, #4]
	ldrh r2, [r6, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #0x14
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r6, #0xa]
	cmp r0, #5
	bls .L080E0AE0
	ldrh r0, [r6, #0xc]
	cmp r0, #0
	beq .L080E0AB6
	movs r0, #0x3c
	movs r1, #0xa
	movs r2, #0xd9
	movs r3, #0xb
	bl sub_080DFDC4
.L080E0AB6:
	ldrh r0, [r6, #0xc]
	adds r0, #5
	ldrh r1, [r6, #0xa]
	cmp r0, r1
	beq .L080E0ACC
	movs r0, #0x3e
	movs r1, #0xa
	movs r2, #0xd9
	movs r3, #0x49
	bl sub_080DFDC4
.L080E0ACC:
	ldrh r0, [r6, #0xa]
	cmp r0, #5
	bls .L080E0AE0
	movs r0, #5
	mov sb, r0
	b .L080E0AE4
.L080E0AD8: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E0ADC: .4byte gUnknown_0800853C
.L080E0AE0:
	ldrb r1, [r6, #0xa]
	mov sb, r1
.L080E0AE4:
	movs r4, #0
	cmp r4, sb
	bhs .L080E0BE2
.L080E0AEA:
	ldrh r0, [r6, #0xc]
	adds r0, r4, r0
	lsls r0, r0, #2
	ldr r1, .L080E0B04
	adds r0, r0, r1
	ldrh r5, [r0]
	ldrh r7, [r0, #2]
	cmp r5, #0x7f
	bhi .L080E0B08
	adds r0, r5, #0
	bl Item_GetRecord
	b .L080E0B12
.L080E0B04: .4byte 0x0203C4D0 @ EWRAM+0x3C4D0
.L080E0B08:
	cmp r5, #0xcf
	bhi .L080E0B18
	adds r0, r5, #0
	bl Equipment_GetRecord36_MidRange
.L080E0B12:
	adds r3, r0, #0
	adds r3, #0x14
	b .L080E0B22
.L080E0B18:
	adds r0, r5, #0
	bl Action_GetRecord
	adds r3, r0, #0
	adds r3, #0xc
.L080E0B22:
	movs r2, #0
	adds r0, r4, #1
	mov r8, r0
.L080E0B28:
	lsls r0, r2, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #0xc
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls .L080E0B28
	lsls r0, r2, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #0xc
	movs r0, #0
	strh r0, [r1]
	mov r0, sl
	adds r1, r5, #0
	bl sub_080E0CDC
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E0B78
	movs r0, #0xd
	muls r0, r4, r0
	adds r0, #0x13
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0x52
	bl Text_DrawSpriteStringTinted
	b .L080E0B90
.L080E0B78:
	movs r0, #0xd
	muls r0, r4, r0
	adds r0, #0x13
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0x52
	bl Text_DrawSpriteString
.L080E0B90:
	movs r0, #0xd
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0x14
	str r0, [sp]
	movs r0, #0x3e
	movs r1, #0
	movs r2, #0
	movs r3, #0xb9
	bl FontSprite_DrawGlyph
	adds r0, r7, #0
	movs r1, #0xa
	bl __udivsi3
	adds r0, #0x30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, #0x12
	movs r1, #0xa
	movs r2, #0xc6
	adds r3, r4, #0
	bl sub_080DFDC4
	adds r0, r7, #0
	movs r1, #0xa
	bl __umodsi3
	adds r0, #0x30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	movs r2, #0xce
	adds r3, r4, #0
	bl sub_080DFDC4
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r4, r0, #0x18
	cmp r4, sb
	blo .L080E0AEA
.L080E0BE2:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E0BF4
sub_080E0BF4: @ 0x080E0BF4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #1
	bl sub_08126D1C
	adds r6, r0, #0
	movs r0, #1
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r0, .L080E0C2C
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0
	beq .L080E0C30
	movs r0, #0xff
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080E0CA4
.L080E0C2C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E0C30:
	ldrb r0, [r6]
	cmp r0, #3
	bne .L080E0CA4
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r1, .L080E0C70
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r5, r4, #0
	adds r5, #0x50
	ldr r7, .L080E0C74
	ldrh r0, [r6, #0x12]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r5, #4]
	ldrh r1, [r5, #4]
	adds r0, r7, #0
	bl sub_080E0CDC
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq .L080E0C78
	ldrh r1, [r5, #4]
	adds r0, r7, #0
	bl sub_080E0D74
	mov r0, r8
	strh r0, [r4, #0x1c]
	b .L080E0CA4
.L080E0C70: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E0C74: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E0C78:
	adds r0, r7, #0
	bl sub_080E0D08
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq .L080E0C90
	movs r0, #0x66
	bl sub_080C51D4
	strh r6, [r4, #0x1c]
	b .L080E0CA4
.L080E0C90:
	strh r0, [r5, #6]
	movs r1, #0
	movs r2, #0
.L080E0C96:
	adds r0, r5, r1
	strb r2, [r0, #1]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	bls .L080E0C96
.L080E0CA4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E0CB0
sub_080E0CB0: @ 0x080E0CB0
	push {lr}
	ldr r1, .L080E0CC0
	str r1, [r0, #0x20]
	movs r0, #1
	bl sub_081269B0
	pop {r0}
	bx r0
.L080E0CC0: .4byte sub_080D9B64

	thumb_func_start sub_080E0CC4
sub_080E0CC4: @ 0x080E0CC4
	push {lr}
	ldr r3, .L080E0CD8
	adds r0, #0x50
	ldrh r1, [r0, #4]
	ldrh r2, [r0, #6]
	adds r0, r3, #0
	bl sub_080E0D1C
	pop {r0}
	bx r0
.L080E0CD8: .4byte 0x0203B554 @ EWRAM+0x3B554

	thumb_func_start sub_080E0CDC
sub_080E0CDC: @ 0x080E0CDC
.L080E0CDC:
	push {lr}
	adds r3, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0
.L080E0CE6:
	lsls r0, r2, #2
	adds r0, r3, r0
	adds r0, #0x40
	ldrh r0, [r0]
	cmp r0, r1
	bne .L080E0CF6
	movs r0, #1
	b .L080E0D02
.L080E0CF6:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #4
	bls .L080E0CE6
	movs r0, #0
.L080E0D02:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080E0D08
sub_080E0D08: @ 0x080E0D08
.L080E0D08:
	push {lr}
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #4
	bhi .L080E0D16
	movs r0, #0
	b .L080E0D18
.L080E0D16:
	movs r0, #1
.L080E0D18:
	pop {r1}
	bx r1

	thumb_func_start sub_080E0D1C
sub_080E0D1C: @ 0x080E0D1C
.L080E0D1C:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	bl sub_080E0D08
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E0D4A
	b .L080E0D66
.L080E0D34:
	strh r6, [r1]
	adds r0, r2, #0
	adds r0, #0x42
	strh r7, [r0]
	adds r1, r4, #0
	adds r1, #0x25
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #1
	b .L080E0D68
.L080E0D4A:
	movs r3, #0
	ldr r5, .L080E0D70
.L080E0D4E:
	lsls r0, r3, #2
	adds r2, r4, r0
	adds r1, r2, #0
	adds r1, #0x40
	ldrh r0, [r1]
	cmp r0, r5
	beq .L080E0D34
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #4
	bls .L080E0D4E
.L080E0D66:
	movs r0, #0
.L080E0D68:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080E0D70: .4byte 0x0000FFFF

	thumb_func_start sub_080E0D74
sub_080E0D74: @ 0x080E0D74
.L080E0D74:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r3, #0
	ldr r0, .L080E0DB0
	adds r5, r0, #0
	movs r1, #0x25
	adds r1, r1, r4
	mov ip, r1
.L080E0D88:
	lsls r0, r3, #2
	adds r1, r4, r0
	adds r2, r1, #0
	adds r2, #0x40
	ldrh r0, [r2]
	cmp r0, r6
	bne .L080E0DB4
	adds r1, #0x42
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	ldrh r0, [r2]
	orrs r0, r5
	strh r0, [r2]
	mov r1, ip
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #1
	b .L080E0DC0
.L080E0DB0: .4byte 0x0000FFFF
.L080E0DB4:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #4
	bls .L080E0D88
	movs r0, #0
.L080E0DC0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080E0DC8
sub_080E0DC8: @ 0x080E0DC8
.L080E0DC8:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	ldr r0, .L080E0E00
	adds r5, r0, #0
.L080E0DDA:
	lsls r1, r3, #2
	adds r1, r4, r1
	adds r2, r1, #0
	adds r2, #0x42
	ldrh r0, [r2]
	orrs r0, r5
	strh r0, [r2]
	adds r1, #0x40
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #4
	bls .L080E0DDA
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E0E00: .4byte 0x0000FFFF

	thumb_func_start sub_080E0E04
sub_080E0E04: @ 0x080E0E04
.L080E0E04:
	push {r4, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r3, #0
.L080E0E0E:
	lsls r2, r3, #2
	adds r0, r4, r2
	adds r0, #0x40
	ldrh r0, [r0]
	cmp r0, r1
	bne .L080E0E22
	adds r0, r2, #0
	adds r0, #0x40
	adds r0, r4, r0
	b .L080E0E2E
.L080E0E22:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #4
	bls .L080E0E0E
	movs r0, #0
.L080E0E2E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080E0E34
sub_080E0E34: @ 0x080E0E34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	bl Task_GetParent
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x50
	movs r0, #1
	bl sub_08126D1C
	mov sb, r0
	ldr r0, .L080E0E88
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r1, r1, r0
	mov sl, r1
	movs r3, #0
	movs r0, #0
	mov r8, r0
	mov r1, r8
	strh r1, [r5, #0x1e]
	strh r1, [r5, #0x1c]
	strh r1, [r7, #0x1e]
	ldr r2, .L080E0E8C
	ldrh r1, [r2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E0EC4
	ldrh r0, [r4, #6]
	cmp r0, #0
	bne .L080E0E90
	movs r0, #0x66
	bl sub_080C51D4
	b .L080E0F80
	.byte 0x00, 0x00
.L080E0E88: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E0E8C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E0E90:
	movs r0, #0x65
	bl sub_080C51D4
	strh r6, [r5, #0x1c]
	mov r1, sb
	ldrh r0, [r1, #0x12]
	lsls r0, r0, #2
	add r0, sl
	ldrh r1, [r0, #2]
	ldrh r0, [r4, #6]
	cmp r0, r1
	bls .L080E0EBE
	strh r1, [r4, #6]
	ldrh r0, [r4, #6]
	movs r1, #0xa
	bl __udivsi3
	strb r0, [r4, #1]
	ldrh r0, [r4, #6]
	movs r1, #0xa
	bl __umodsi3
	strb r0, [r4, #2]
.L080E0EBE:
	mov r0, r8
	strh r0, [r7, #0x1e]
	b .L080E0F80
.L080E0EC4:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080E0EE8
	movs r0, #0x66
	bl sub_080C51D4
	strh r6, [r5, #0x1c]
	movs r0, #0xff
	strh r0, [r7, #0x1e]
	strh r0, [r5, #0x1e]
	ldr r0, .L080E0EE4
	strh r0, [r4, #4]
	b .L080E0F80
	.byte 0x00, 0x00
.L080E0EE4: .4byte 0x0000FFFF
.L080E0EE8:
	ldr r0, .L080E0F08
	ldrh r1, [r0]
	movs r0, #0x88
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080E0F0C
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge .L080E0F4C
	movs r0, #1
	strb r0, [r4]
	b .L080E0F4C
.L080E0F08: .4byte 0x03003964 @ IWRAM+0x3964
.L080E0F0C:
	movs r0, #0x88
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E0F28
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble .L080E0F4C
	strb r3, [r4]
	b .L080E0F4C
.L080E0F28:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080E0F54
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r1, r4, r1
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r1, r4, r0
	movs r0, #1
	ldrsb r0, [r1, r0]
	cmp r0, #9
	ble .L080E0F4C
	strb r3, [r1, #1]
.L080E0F4C:
	movs r0, #0x64
	bl sub_080C51D4
	b .L080E0F80
.L080E0F54:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080E0F80
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r1, r4, r1
	ldrb r0, [r1, #1]
	subs r0, #1
	strb r0, [r1, #1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r1, r4, r0
	movs r0, #1
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge .L080E0F7A
	movs r0, #9
	strb r0, [r1, #1]
.L080E0F7A:
	movs r0, #0x64
	bl sub_080C51D4
.L080E0F80:
	movs r0, #1
	ldrsb r0, [r4, r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	movs r0, #2
	ldrsb r0, [r4, r0]
	adds r0, r0, r1
	strh r0, [r4, #6]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080E0FA0
sub_080E0FA0: @ 0x080E0FA0
	push {r4, r5, r6, lr}
	bl Task_GetParent
	adds r5, r0, #0
	adds r5, #0x50
	movs r2, #0
.L080E0FAC:
	movs r3, #0
	ldrsb r3, [r5, r3]
	lsls r2, r2, #0x18
	asrs r1, r2, #0x18
	movs r0, #1
	subs r4, r0, r1
	adds r6, r2, #0
	cmp r3, r4
	bne .L080E0FFA
	adds r0, r5, r4
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x13
	movs r1, #0xd2
	lsls r1, r1, #0x10
	adds r4, r4, r1
	lsrs r4, r4, #0x10
	movs r1, #0xc
	adds r2, r4, #0
	movs r3, #0x61
	bl sub_080DFDC4
	movs r0, #0x3e
	movs r1, #0xa
	adds r2, r4, #0
	movs r3, #0x56
	bl sub_080DFDC4
	movs r0, #0x3c
	movs r1, #0xa
	adds r2, r4, #0
	movs r3, #0x68
	bl sub_080DFDC4
	b .L080E101A
.L080E0FFA:
	adds r0, r5, r4
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r4, #0x13
	movs r1, #0xd2
	lsls r1, r1, #0x10
	adds r2, r2, r1
	lsrs r2, r2, #0x10
	movs r1, #0xa
	movs r3, #0x61
	bl sub_080DFDC4
.L080E101A:
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r6, r1
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble .L080E0FAC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E1030
sub_080E1030: @ 0x080E1030
.L080E1030:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov sl, r0
	str r1, [sp, #0x20]
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0x12
	bl memset
	movs r6, #0
	mov r0, sl
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080E10B8
	movs r0, #0x4e
	movs r1, #0xf
	movs r2, #0x7c
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x4f
	movs r1, #0xf
	movs r2, #0x84
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x54
	movs r1, #0xf
	movs r2, #0x8c
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x48
	movs r1, #0xf
	movs r2, #0x94
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x49
	movs r1, #0xf
	movs r2, #0x9c
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x4e
	movs r1, #0xf
	movs r2, #0xa4
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x47
	movs r1, #0xf
	movs r2, #0xac
	movs r3, #0x28
	bl sub_080DFDC4
	movs r0, #0x21
	movs r1, #0xf
	movs r2, #0xb4
	movs r3, #0x28
	bl sub_080DFDC4
	b .L080E11DE
.L080E10B8:
	movs r5, #0
.L080E10BA:
	lsls r0, r5, #2
	add r0, sl
	adds r1, r0, #0
	adds r1, #0x40
	ldrh r1, [r1]
	adds r2, r1, #0
	adds r0, #0x42
	ldrh r0, [r0]
	mov r8, r0
	ldr r0, .L080E10E4
	adds r7, r5, #1
	cmp r1, r0
	bne .L080E10D6
	b .L080E11D4
.L080E10D6:
	cmp r1, #0x7f
	bhi .L080E10E8
	adds r0, r1, #0
	bl Item_GetRecord
	b .L080E10F2
	.byte 0x00, 0x00
.L080E10E4: .4byte 0x0000FFFF
.L080E10E8:
	cmp r1, #0xcf
	bhi .L080E10F8
	adds r0, r1, #0
	bl Equipment_GetRecord36_MidRange
.L080E10F2:
	adds r3, r0, #0
	adds r3, #0x14
	b .L080E1102
.L080E10F8:
	adds r0, r2, #0
	bl Action_GetRecord
	adds r3, r0, #0
	adds r3, #0xc
.L080E1102:
	movs r2, #0
	ldr r4, [sp, #0x20]
	adds r4, #0x54
	adds r0, r6, #1
	mov sb, r0
	adds r7, r5, #1
.L080E110E:
	lsls r0, r2, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #0xc
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #7
	bls .L080E110E
	lsls r0, r2, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #0xc
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r4]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E1160
	movs r0, #0xd
	muls r0, r6, r0
	adds r0, #0x13
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0x52
	bl Text_DrawSpriteStringTinted
	b .L080E117C
.L080E1160:
	movs r0, #0xd
	muls r0, r6, r0
	adds r0, #0x13
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0x52
	bl Text_DrawSpriteString
.L080E117C:
	movs r0, #0xd
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0x14
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0x3e
	movs r1, #0
	movs r2, #0
	movs r3, #0xb9
	bl FontSprite_DrawGlyph
	mov r0, r8
	movs r1, #0xa
	bl __udivsi3
	adds r0, #0x30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, #0x12
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r1, #0xa
	movs r2, #0xc6
	adds r3, r4, #0
	bl sub_080DFDC4
	mov r0, r8
	movs r1, #0xa
	bl __umodsi3
	adds r0, #0x30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	movs r2, #0xce
	adds r3, r4, #0
	bl sub_080DFDC4
	mov r1, sb
	lsls r0, r1, #0x10
	lsrs r6, r0, #0x10
.L080E11D4:
	lsls r0, r7, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #4
	bhi .L080E11DE
	b .L080E10BA
.L080E11DE:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E11F0
sub_080E11F0: @ 0x080E11F0
	push {lr}
	ldr r0, .L080E1200
	adds r1, r0, #0
	adds r1, #0x58
	bl sub_080E1030
	pop {r0}
	bx r0
.L080E1200: .4byte 0x0203B554 @ EWRAM+0x3B554

	thumb_func_start sub_080E1204
sub_080E1204: @ 0x080E1204
	push {lr}
	ldr r0, .L080E1214
	adds r1, r0, #0
	subs r1, #0x58
	bl sub_080E1030
	pop {r0}
	bx r0
.L080E1214: .4byte 0x0203B5AC @ EWRAM+0x3B5AC

	thumb_func_start sub_080E1218
sub_080E1218: @ 0x080E1218
	adds r0, #0x24
	movs r1, #0
	strb r1, [r0]
	ldr r1, .L080E1224
	strh r1, [r0, #2]
	bx lr
.L080E1224: .4byte 0x0000FFFF

	thumb_func_start sub_080E1228
sub_080E1228: @ 0x080E1228
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1e]
	movs r0, #8
	bl BattleMenu_BuildMemberList
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r5, r3, #0
	cmp r3, #0
	bne .L080E1248
	movs r0, #0xff
	strh r0, [r4, #0x1e]
	b .L080E1274
.L080E1248:
	cmp r3, #4
	bhi .L080E125A
	str r3, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #1
	bl sub_08126928
	b .L080E126A
.L080E125A:
	movs r0, #5
	str r0, [sp]
	movs r0, #1
	movs r1, #0x10
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
.L080E126A:
	movs r0, #1
	bl sub_08126D1C
	ldr r1, .L080E127C
	strh r1, [r0, #0x1e]
.L080E1274:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E127C: .4byte 0x0000FFFF

	thumb_func_start sub_080E1280
sub_080E1280: @ 0x080E1280
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x24
	ldr r0, .L080E12BC
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r7, r0, r1
	movs r0, #1
	bl sub_08126D1C
	adds r5, r0, #0
	movs r0, #1
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r0, .L080E12C0
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080E12C4
	movs r0, #0xff
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080E1342
	.byte 0x00, 0x00
.L080E12BC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E12C0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E12C4:
	ldrb r0, [r5]
	cmp r0, #3
	bne .L080E1342
	ldrh r1, [r5, #0x12]
	lsls r1, r1, #1
	adds r1, r1, r7
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r4, [r0, #0x12]
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	movs r1, #0
	bl sub_0815B8F8
	rsbs r1, r0, #0
	orrs r1, r0
	cmp r1, #0
	bge .L080E133C
	strh r4, [r6, #2]
	ldr r4, .L080E1314
	ldrh r1, [r6, #2]
	adds r0, r4, #0
	bl sub_080E1540
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E1318
	ldrh r1, [r6, #2]
	adds r0, r4, #0
	bl sub_080E15CC
	b .L080E1334
	.byte 0x00, 0x00
.L080E1314: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E1318:
	adds r0, r4, #0
	bl sub_080E156C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E132C
	movs r0, #0x66
	bl sub_080C51D4
	b .L080E1342
.L080E132C:
	ldrh r1, [r6, #2]
	adds r0, r4, #0
	bl sub_080E1580
.L080E1334:
	movs r0, #0x65
	bl sub_080C51D4
	b .L080E1342
.L080E133C:
	movs r0, #0x66
	bl sub_080C51D4
.L080E1342:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080E1348
sub_080E1348: @ 0x080E1348
	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r4, .L080E1368
	ldrh r1, [r4]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E136C
	strh r3, [r2, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	b .L080E137E
.L080E1368: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E136C:
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080E137E
	strh r3, [r2, #0x1c]
	movs r0, #0x66
	bl sub_080C51D4
.L080E137E:
	movs r0, #0x4e
	movs r1, #0xf
	movs r2, #0x6c
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x4f
	movs r1, #0xf
	movs r2, #0x74
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x54
	movs r1, #0xf
	movs r2, #0x7c
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x48
	movs r1, #0xf
	movs r2, #0x84
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x49
	movs r1, #0xf
	movs r2, #0x8c
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x4e
	movs r1, #0xf
	movs r2, #0x94
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x47
	movs r1, #0xf
	movs r2, #0x9c
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x21
	movs r1, #0xf
	movs r2, #0xa4
	movs r3, #0x2a
	bl sub_080DFDC4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080E13E4
sub_080E13E4: @ 0x080E13E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r0, .L080E1470
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r1, r1, r0
	mov sl, r1
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0x12
	bl memset
	ldr r2, .L080E1474
	mov sb, r2
	movs r0, #1
	bl sub_08126D1C
	adds r6, r0, #0
	ldr r0, .L080E1478
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x51
	str r1, [sp, #4]
	ldrh r2, [r6, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #0x14
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r6, #0xa]
	cmp r0, #5
	bls .L080E1462
	ldrh r0, [r6, #0xc]
	cmp r0, #0
	beq .L080E144C
	movs r0, #0x3c
	movs r1, #0xa
	movs r2, #0xb9
	movs r3, #0xb
	bl sub_080DFDC4
.L080E144C:
	ldrh r0, [r6, #0xc]
	adds r0, #5
	ldrh r1, [r6, #0xa]
	cmp r0, r1
	beq .L080E1462
	movs r0, #0x3e
	movs r1, #0xa
	movs r2, #0xb9
	movs r3, #0x49
	bl sub_080DFDC4
.L080E1462:
	ldrh r0, [r6, #0xa]
	cmp r0, #4
	bls .L080E147C
	movs r2, #5
	mov r8, r2
	b .L080E1482
	.byte 0x00, 0x00
.L080E1470: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080E1474: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E1478: .4byte gUnknown_0800853C
.L080E147C:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
.L080E1482:
	movs r5, #0
	cmp r5, r8
	bhs .L080E1522
.L080E1488:
	ldrh r1, [r6, #0xc]
	adds r1, r5, r1
	lsls r1, r1, #1
	add r1, sl
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r4, [r0, #0x12]
	adds r0, r4, #0
	bl Demon_GetRecord
	adds r3, r0, #0
	adds r3, #0x22
	movs r2, #0
	adds r7, r5, #1
.L080E14B2:
	lsls r0, r2, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #0xc
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls .L080E14B2
	lsls r0, r2, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #0xc
	movs r0, #0
	strh r0, [r1]
	mov r0, sb
	adds r1, r4, #0
	bl sub_080E1540
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E1502
	movs r0, #0xd
	muls r0, r5, r0
	adds r0, #0x13
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0x51
	bl Text_DrawSpriteStringTinted
	b .L080E151A
.L080E1502:
	movs r0, #0xd
	muls r0, r5, r0
	adds r0, #0x13
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0x51
	bl Text_DrawSpriteString
.L080E151A:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	cmp r5, r8
	blo .L080E1488
.L080E1522:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E1534
sub_080E1534: @ 0x080E1534
	push {lr}
	movs r0, #1
	bl sub_081269B0
	pop {r0}
	bx r0

	thumb_func_start sub_080E1540
sub_080E1540: @ 0x080E1540
.L080E1540:
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0
	adds r3, r0, #0
	adds r3, #0x26
.L080E154C:
	lsls r0, r2, #1
	adds r0, r3, r0
	ldrh r0, [r0]
	cmp r0, r1
	bne .L080E155A
	movs r0, #1
	b .L080E1566
.L080E155A:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xb
	bls .L080E154C
	movs r0, #0
.L080E1566:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080E156C
sub_080E156C: @ 0x080E156C
.L080E156C:
	push {lr}
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0xb
	bhi .L080E157A
	movs r0, #0
	b .L080E157C
.L080E157A:
	movs r0, #1
.L080E157C:
	pop {r1}
	bx r1

	thumb_func_start sub_080E1580
sub_080E1580: @ 0x080E1580
.L080E1580:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	bl sub_080E156C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E15A4
	b .L080E15C0
.L080E1594:
	strh r6, [r1]
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #1
	b .L080E15C2
.L080E15A4:
	movs r2, #0
	adds r3, r4, #0
	adds r3, #0x26
	ldr r5, .L080E15C8
.L080E15AC:
	lsls r0, r2, #1
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, r5
	beq .L080E1594
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xb
	bls .L080E15AC
.L080E15C0:
	movs r0, #0
.L080E15C2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080E15C8: .4byte 0x0000FFFF

	thumb_func_start sub_080E15CC
sub_080E15CC: @ 0x080E15CC
.L080E15CC:
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	movs r3, #0
	adds r4, r0, #0
	adds r4, #0x26
	ldr r1, .L080E15F8
	adds r6, r1, #0
	adds r1, r0, #0
	adds r1, #0x24
.L080E15E0:
	lsls r0, r3, #1
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, r5
	bne .L080E15FC
	orrs r0, r6
	strh r0, [r2]
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #1
	b .L080E1608
.L080E15F8: .4byte 0x0000FFFF
.L080E15FC:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0xb
	bls .L080E15E0
	movs r0, #0
.L080E1608:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080E1610
sub_080E1610: @ 0x080E1610
.L080E1610:
	push {r4, lr}
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0
	strb r1, [r2]
	movs r2, #0
	adds r3, r0, #0
	adds r3, #0x26
	ldr r0, .L080E1640
	adds r4, r0, #0
.L080E1624:
	lsls r0, r2, #1
	adds r0, r3, r0
	ldrh r1, [r0]
	orrs r1, r4
	strh r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xb
	bls .L080E1624
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E1640: .4byte 0x0000FFFF

	thumb_func_start sub_080E1644
sub_080E1644: @ 0x080E1644
.L080E1644:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	mov sl, r1
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0x12
	bl memset
	movs r7, #0
	mov r0, sb
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080E16CC
	movs r0, #0x4e
	movs r1, #0xf
	movs r2, #0x6c
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x4f
	movs r1, #0xf
	movs r2, #0x74
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x54
	movs r1, #0xf
	movs r2, #0x7c
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x48
	movs r1, #0xf
	movs r2, #0x84
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x49
	movs r1, #0xf
	movs r2, #0x8c
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x4e
	movs r1, #0xf
	movs r2, #0x94
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x47
	movs r1, #0xf
	movs r2, #0x9c
	movs r3, #0x2a
	bl sub_080DFDC4
	movs r0, #0x21
	movs r1, #0xf
	movs r2, #0xa4
	movs r3, #0x2a
	bl sub_080DFDC4
	b .L080E17E2
.L080E16CC:
	movs r0, #1
	bl sub_08126D1C
	adds r5, r0, #0
	ldr r0, .L080E17AC
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #0x51
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #0x14
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L080E1726
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L080E1710
	movs r0, #0x3c
	movs r1, #0xa
	movs r2, #0xb9
	movs r3, #0xb
	bl sub_080DFDC4
.L080E1710:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r1, [r5, #0xa]
	cmp r0, r1
	beq .L080E1726
	movs r0, #0x3e
	movs r1, #0xa
	movs r2, #0xb9
	movs r3, #0x49
	bl sub_080DFDC4
.L080E1726:
	ldrh r4, [r5, #0xc]
	adds r0, r4, #5
	adds r2, r4, #0
	cmp r4, r0
	bge .L080E17E2
.L080E1730:
	lsls r0, r4, #1
	mov r1, sb
	adds r1, #0x26
	adds r1, r1, r0
	ldrh r1, [r1]
	ldr r0, .L080E17B0
	adds r3, r4, #1
	mov r8, r3
	cmp r1, r0
	beq .L080E17D6
	adds r0, r1, #0
	bl Demon_GetRecord
	adds r3, r0, #0
	adds r3, #0x22
	movs r2, #0
	movs r0, #0x56
	add r0, sl
	mov ip, r0
	adds r6, r7, #1
.L080E1758:
	lsls r0, r2, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #0xc
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #7
	bls .L080E1758
	lsls r0, r2, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #0xc
	movs r0, #0
	strh r0, [r1]
	mov r1, ip
	ldrh r0, [r1]
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080E17B4
	movs r0, #0xd
	muls r0, r7, r0
	adds r0, #0x13
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0x51
	bl Text_DrawSpriteStringTinted
	b .L080E17D0
.L080E17AC: .4byte gUnknown_0800853C
.L080E17B0: .4byte 0x0000FFFF
.L080E17B4:
	movs r0, #0xd
	muls r0, r7, r0
	adds r0, #0x13
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	add r0, sp, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0x51
	bl Text_DrawSpriteString
.L080E17D0:
	lsls r0, r6, #0x10
	lsrs r7, r0, #0x10
	ldrh r2, [r5, #0xc]
.L080E17D6:
	mov r3, r8
	lsls r0, r3, #0x10
	lsrs r4, r0, #0x10
	adds r0, r2, #5
	cmp r4, r0
	blt .L080E1730
.L080E17E2:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080E17F4
sub_080E17F4: @ 0x080E17F4
	push {lr}
	ldr r0, .L080E1804
	adds r1, r0, #0
	adds r1, #0x58
	bl sub_080E1644
	pop {r0}
	bx r0
.L080E1804: .4byte 0x0203B554 @ EWRAM+0x3B554

	thumb_func_start sub_080E1808
sub_080E1808: @ 0x080E1808
	push {lr}
	ldr r0, .L080E1818
	adds r1, r0, #0
	subs r1, #0x58
	bl sub_080E1644
	pop {r0}
	bx r0
.L080E1818: .4byte 0x0203B5AC @ EWRAM+0x3B5AC

	thumb_func_start sub_080E181C
sub_080E181C: @ 0x080E181C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	bl sub_08126D1C
	movs r0, #1
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldr r3, .L080E1848
	ldrh r1, [r3]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E184C
	strh r2, [r4, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	b .L080E185E
.L080E1848: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E184C:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080E185E
	strh r2, [r4, #0x1c]
	movs r0, #0x66
	bl sub_080C51D4
.L080E185E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080E1864
sub_080E1864: @ 0x080E1864
.L080E1864:
	push {r4, lr}
	sub sp, #4
	adds r0, #0x24
	ldrb r3, [r0]
	adds r4, r3, #0
	cmp r3, #0
	beq .L080E189E
	cmp r3, #4
	bhi .L080E1884
	str r3, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #1
	bl sub_08126928
	b .L080E1894
.L080E1884:
	movs r0, #5
	str r0, [sp]
	movs r0, #1
	movs r1, #0x10
	movs r2, #1
	adds r3, r4, #0
	bl sub_08126928
.L080E1894:
	movs r0, #1
	bl sub_08126D1C
	ldr r1, .L080E18A8
	strh r1, [r0, #0x1e]
.L080E189E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E18A8: .4byte 0x0000FFFF

	thumb_func_start sub_080E18AC
sub_080E18AC: @ 0x080E18AC
	push {lr}
	ldr r0, .L080E18B8
	bl sub_080E1864
	pop {r0}
	bx r0
.L080E18B8: .4byte 0x0203B554 @ EWRAM+0x3B554

	thumb_func_start sub_080E18BC
sub_080E18BC: @ 0x080E18BC
	push {lr}
	ldr r0, .L080E18C8
	bl sub_080E1864
	pop {r0}
	bx r0
.L080E18C8: .4byte 0x0203B5AC @ EWRAM+0x3B5AC

	thumb_func_start sub_080E18CC
sub_080E18CC: @ 0x080E18CC
	push {lr}
	movs r0, #1
	bl sub_081269B0
	pop {r0}
	bx r0

	thumb_func_start sub_080E18D8
sub_080E18D8: @ 0x080E18D8
	push {r4, lr}
	ldr r1, .L080E190C
	adds r4, r1, #0
	adds r4, #0x58
	movs r0, #0
	str r0, [r1, #0x58]
	str r0, [r4, #8]
	str r0, [r4, #4]
	str r0, [r4, #0x14]
	str r0, [r4, #0xc]
	str r0, [r4, #0x10]
	str r0, [r4, #0x18]
	strb r0, [r4, #0x1c]
	ldr r0, .L080E1910
	str r0, [r4, #0x20]
	str r0, [r1, #0x20]
	adds r0, r4, #0
	bl sub_080E0DC8
	adds r0, r4, #0
	bl sub_080E1610
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E190C: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E1910: .4byte 0x000001BF

	thumb_func_start sub_080E1914
sub_080E1914: @ 0x080E1914
	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r3, .L080E193C
	ldrh r1, [r3]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E1940
	ldrh r0, [r2, #0x24]
	adds r0, #1
	strh r0, [r2, #0x1e]
	strh r4, [r2, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	b .L080E1996
	.byte 0x00, 0x00
.L080E193C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E1940:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L080E1996
	ldr r0, .L080E1974
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq .L080E1978
	ldrh r0, [r2, #0x24]
	cmp r0, #0
	bne .L080E1964
	movs r0, #5
	strh r0, [r2, #0x24]
.L080E1964:
	ldrh r0, [r2, #0x24]
	subs r0, #1
	strh r0, [r2, #0x24]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080E1996
	.byte 0x00, 0x00
.L080E1974: .4byte 0x03003964 @ IWRAM+0x3964
.L080E1978:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080E1996
	ldrh r0, [r2, #0x24]
	adds r0, #1
	strh r0, [r2, #0x24]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls .L080E1990
	strh r3, [r2, #0x24]
.L080E1990:
	movs r0, #0x64
	bl sub_080C51D4
.L080E1996:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080E199C
sub_080E199C: @ 0x080E199C
	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r3, .L080E19C4
	ldrh r1, [r3]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E19C8
	ldrh r0, [r2, #0x24]
	adds r0, #1
	strh r0, [r2, #0x1e]
	strh r4, [r2, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	b .L080E1A1E
	.byte 0x00, 0x00
.L080E19C4: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E19C8:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L080E1A1E
	ldr r0, .L080E19FC
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq .L080E1A00
	ldrh r0, [r2, #0x24]
	cmp r0, #0
	bne .L080E19EC
	movs r0, #6
	strh r0, [r2, #0x24]
.L080E19EC:
	ldrh r0, [r2, #0x24]
	subs r0, #1
	strh r0, [r2, #0x24]
	movs r0, #0x64
	bl sub_080C51D4
	b .L080E1A1E
	.byte 0x00, 0x00
.L080E19FC: .4byte 0x03003964 @ IWRAM+0x3964
.L080E1A00:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080E1A1E
	ldrh r0, [r2, #0x24]
	adds r0, #1
	strh r0, [r2, #0x24]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls .L080E1A18
	strh r3, [r2, #0x24]
.L080E1A18:
	movs r0, #0x64
	bl sub_080C51D4
.L080E1A1E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080E1A24
sub_080E1A24: @ 0x080E1A24
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	movs r5, #0
	strh r5, [r4, #0x1e]
	strh r5, [r4, #0x1c]
	bl sub_080DF388
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	bne .L080E1A48
	strh r1, [r4, #0x1c]
	ldr r0, .L080E1A44
	strh r1, [r0]
	b .L080E1A62
.L080E1A44: .4byte 0x03006394 @ IWRAM+0x6394
.L080E1A48:
	ldrh r0, [r4, #0x24]
	subs r0, #1
	strh r0, [r4, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L080E1A62
	movs r0, #0xff
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	strh r5, [r4, #0x24]
	ldr r0, .L080E1A68
	strh r5, [r0]
.L080E1A62:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080E1A68: .4byte 0x03006394 @ IWRAM+0x6394

	thumb_func_start sub_080E1A6C
sub_080E1A6C: @ 0x080E1A6C
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, .L080E1A84
	ldrh r1, [r2, #2]
	bl Task_Create
	strh r4, [r0, #0x24]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E1A84: .4byte gUnknown_0858B180

	thumb_func_start sub_080E1A88
sub_080E1A88: @ 0x080E1A88
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, .L080E1AA0
	ldrh r1, [r2, #2]
	bl Task_Create
	strh r4, [r0, #0x24]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E1AA0: .4byte gUnknown_0858B1BC

	thumb_func_start sub_080E1AA4
sub_080E1AA4: @ 0x080E1AA4
	ldr r1, .L080E1AAC
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	bx lr
.L080E1AAC: .4byte 0x03006394 @ IWRAM+0x6394

	thumb_func_start sub_080E1AB0
sub_080E1AB0: @ 0x080E1AB0
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080DF4B8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r0, r1, #0
	movs r2, #0
	strh r2, [r4, #0x1c]
	strh r2, [r4, #0x1e]
	cmp r1, #1
	bne .L080E1AD4
	strh r1, [r4, #0x1c]
	ldr r0, .L080E1AD0
	strh r1, [r0]
	b .L080E1AE2
.L080E1AD0: .4byte 0x03006394 @ IWRAM+0x6394
.L080E1AD4:
	cmp r0, #0xff
	bne .L080E1AE2
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r0, .L080E1AE8
	strh r2, [r0]
.L080E1AE2:
	pop {r4}
	pop {r0}
	bx r0
.L080E1AE8: .4byte 0x03006394 @ IWRAM+0x6394

	thumb_func_start sub_080E1AEC
sub_080E1AEC: @ 0x080E1AEC
	push {lr}
	ldr r2, .L080E1AFC
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	bl Task_Create
	pop {r0}
	bx r0
.L080E1AFC: .4byte gUnknown_0858B1F8

	thumb_func_start sub_080E1B00
sub_080E1B00: @ 0x080E1B00
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080DFA00
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r0, r1, #0
	movs r2, #0
	strh r2, [r4, #0x1c]
	strh r2, [r4, #0x1e]
	cmp r1, #1
	bne .L080E1B24
	strh r1, [r4, #0x1c]
	ldr r0, .L080E1B20
	strh r1, [r0]
	b .L080E1B32
.L080E1B20: .4byte 0x03006394 @ IWRAM+0x6394
.L080E1B24:
	cmp r0, #0xff
	bne .L080E1B32
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r0, .L080E1B38
	strh r2, [r0]
.L080E1B32:
	pop {r4}
	pop {r0}
	bx r0
.L080E1B38: .4byte 0x03006394 @ IWRAM+0x6394

	thumb_func_start sub_080E1B3C
sub_080E1B3C: @ 0x080E1B3C
	push {lr}
	ldr r2, .L080E1B4C
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	bl Task_Create
	pop {r0}
	bx r0
.L080E1B4C: .4byte gUnknown_0858B228

	thumb_func_start sub_080E1B50
sub_080E1B50: @ 0x080E1B50
	push {lr}
	ldr r1, .L080E1B64
	adds r2, r1, #0
	adds r2, #0x58
	movs r0, #0x58
	bl sub_080DF954
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E1B64: .4byte 0x0203B554 @ EWRAM+0x3B554

	thumb_func_start sub_080E1B68
sub_080E1B68: @ 0x080E1B68
	push {lr}
	sub sp, #8
	ldr r0, .L080E1B88
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
.L080E1B88: .4byte gUnknown_0800980C

	thumb_func_start sub_080E1B8C
sub_080E1B8C: @ 0x080E1B8C
	push {lr}
	sub sp, #8
	ldr r1, .L080E1BB4
	ldr r0, .L080E1BB8
	ldrb r0, [r0]
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
.L080E1BB4: .4byte gUnknown_0858B250
.L080E1BB8: .4byte 0x03006398 @ IWRAM+0x6398

	thumb_func_start sub_080E1BBC
sub_080E1BBC: @ 0x080E1BBC
	ldr r0, .L080E1BC4
	strb r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080E1BC4: .4byte 0x03006398 @ IWRAM+0x6398

	thumb_func_start sub_080E1BC8
sub_080E1BC8: @ 0x080E1BC8
	push {lr}
	ldr r1, .L080E1BDC
	ldrh r0, [r0, #0x1e]
	cmp r0, #0
	beq .L080E1BD4
	movs r0, #1
.L080E1BD4:
	strb r0, [r1, #0x1c]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E1BDC: .4byte 0x0203B554 @ EWRAM+0x3B554

	thumb_func_start sub_080E1BE0
sub_080E1BE0: @ 0x080E1BE0
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080E1C00
	adds r3, r0, #0
	adds r3, #0x58
	movs r1, #0
	strh r1, [r2, #0x1e]
	ldrb r0, [r0, #0x1c]
	cmp r0, #0
	bne .L080E1C10
	ldrb r0, [r3, #0x1c]
	cmp r0, #0
	bne .L080E1C04
	movs r0, #1
	strh r0, [r2, #0x1e]
	b .L080E1C16
.L080E1C00: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E1C04:
	ldr r1, .L080E1C0C
	movs r0, #3
	b .L080E1C14
	.byte 0x00, 0x00
.L080E1C0C: .4byte 0x03006398 @ IWRAM+0x6398
.L080E1C10:
	ldr r1, .L080E1C1C
	movs r0, #0xa
.L080E1C14:
	strb r0, [r1]
.L080E1C16:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E1C1C: .4byte 0x03006398 @ IWRAM+0x6398

	thumb_func_start sub_080E1C20
sub_080E1C20: @ 0x080E1C20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r2, r0, #0
	ldr r0, .L080E1C44
	mov sl, r0
	movs r4, #0
	strh r4, [r2, #0x1e]
	ldr r1, [r0, #0x58]
	ldr r0, .L080E1C48
	cmp r1, r0
	beq .L080E1C4C
	movs r0, #0xff
	strh r0, [r2, #0x1e]
	b .L080E1FF8
.L080E1C44: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E1C48: .4byte 0x15273950
.L080E1C4C:
	mov r1, sl
	str r4, [r1, #0x20]
	bl sub_080C3168
	mov r2, sl
	ldr r1, [r2, #0x14]
	subs r0, r0, r1
	ldr r3, .L080E1C94
	ldr r1, [r3, #0x14]
	adds r0, r0, r1
	ldr r1, .L080E1C98
	cmp r0, r1
	bhi .L080E1C6E
	ldr r0, [r2, #0x20]
	movs r1, #4
	orrs r0, r1
	str r0, [r2, #0x20]
.L080E1C6E:
	mov r1, sl
	adds r1, #0x54
	strh r4, [r1]
	mov r0, sl
	adds r0, #0x7d
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080E1C9C
	mov r1, sl
	ldr r0, [r1, #0x20]
	movs r1, #8
	orrs r0, r1
	mov r2, sl
	str r0, [r2, #0x20]
	movs r3, #0x7c
	add r3, sl
	mov sb, r3
	b .L080E1D28
	.byte 0x00, 0x00
.L080E1C94: .4byte 0x0203B5AC @ EWRAM+0x3B5AC
.L080E1C98: .4byte 0x0001869F
.L080E1C9C:
	movs r7, #0
	movs r0, #0x7c
	add r0, sl
	mov sb, r0
	ldr r1, .L080E1D4C
	mov r8, r1
.L080E1CA8:
	lsls r0, r7, #2
	ldr r3, .L080E1D50
	adds r2, r3, r0
	adds r0, r2, #0
	adds r0, #0x40
	ldrh r1, [r0]
	adds r6, r1, #0
	ldr r0, .L080E1D54
	cmp r1, r0
	beq .L080E1D0A
	adds r0, r2, #0
	adds r0, #0x42
	ldrh r5, [r0]
	mov r0, sl
	bl sub_080E0E04
	cmp r0, #0
	beq .L080E1CD4
	ldrh r0, [r0, #2]
	subs r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L080E1CD4:
	adds r0, r6, #0
	bl sub_080C32D4
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0xff
	adds r1, r6, #0
	bl sub_08131AB0
	adds r0, r0, r4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x63
	ble .L080E1D0A
	movs r0, #1
	lsls r0, r7
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2]
.L080E1D0A:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #4
	bls .L080E1CA8
	ldr r3, .L080E1D4C
	ldrh r0, [r3]
	cmp r0, #0
	bne .L080E1D28
	mov r1, sl
	ldr r0, [r1, #0x20]
	movs r1, #8
	orrs r0, r1
	mov r2, sl
	str r0, [r2, #0x20]
.L080E1D28:
	movs r0, #0
	ldr r3, .L080E1D58
	strh r0, [r3]
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne .L080E1D5C
	mov r2, sl
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	orrs r0, r1
	movs r1, #0x20
	orrs r0, r1
	movs r1, #0x80
	orrs r0, r1
	adds r1, #0x80
	orrs r0, r1
	b .L080E1F6C
.L080E1D4C: .4byte 0x0203B5A8 @ EWRAM+0x3B5A8
.L080E1D50: .4byte 0x0203B5AC @ EWRAM+0x3B5AC
.L080E1D54: .4byte 0x0000FFFF
.L080E1D58: .4byte 0x0203B5AA @ EWRAM+0x3B5AA
.L080E1D5C:
	ldr r0, .L080E1FA8
	ldr r3, .L080E1FAC
	adds r0, r0, r3
	ldrb r0, [r0]
	str r0, [sp]
	mov r0, sb
	ldrb r7, [r0]
	movs r1, #1
	str r1, [sp, #8]
	movs r6, #0
	ldr r2, .L080E1FB0
	adds r2, #0x26
	str r2, [sp, #0x10]
	ldr r4, .L080E1FB4
.L080E1D78:
	lsls r0, r6, #1
	ldr r3, [sp, #0x10]
	adds r0, r3, r0
	ldrh r5, [r0]
	cmp r5, r4
	beq .L080E1D9A
	mov r0, sl
	adds r1, r5, #0
	bl sub_080E1540
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080E1D9A
	lsls r0, r7, #0x10
	ldr r1, .L080E1FB8
	adds r0, r0, r1
	lsrs r7, r0, #0x10
.L080E1D9A:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0xb
	bls .L080E1D78
	movs r4, #4
	ldr r2, [sp]
	adds r2, #4
	str r2, [sp, #0xc]
	cmp r4, r2
	bge .L080E1DE0
	movs r3, #0x80
	lsls r3, r3, #8
	adds r5, r3, #0
.L080E1DB6:
	adds r0, r4, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r1, r0, #0
	ldrh r0, [r1, #0xe]
	ands r0, r5
	cmp r0, #0
	beq .L080E1DD4
	lsls r0, r7, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r7, r0, #0x10
.L080E1DD4:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r2, [sp, #0xc]
	cmp r4, r2
	blt .L080E1DB6
.L080E1DE0:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	ldr r3, [sp]
	cmp r3, r0
	blt .L080E1DF6
	mov r1, sl
	ldr r0, [r1, #0x20]
	movs r1, #0x20
	orrs r0, r1
	mov r2, sl
	str r0, [r2, #0x20]
.L080E1DF6:
	mov r3, sb
	ldrb r0, [r3]
	subs r0, r7, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	movs r6, #0
	ldr r0, .L080E1FBC
	mov r8, r0
.L080E1E08:
	lsls r0, r6, #1
	ldr r1, [sp, #0x10]
	adds r0, r1, r0
	ldrh r5, [r0]
	ldr r0, .L080E1FB4
	cmp r5, r0
	beq .L080E1EA8
	movs r4, #4
	ldr r2, [sp, #0xc]
	cmp r4, r2
	bge .L080E1E72
	movs r3, #0x80
	lsls r3, r3, #8
	mov sb, r3
	ldr r7, .L080E1FBC
	movs r2, #1
	lsls r2, r6
.L080E1E2A:
	mov r1, sb
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r2, [sp, #0x14]
	bl Battle_GetCombatant
	adds r1, r0, #0
	ldrh r0, [r1, #0xe]
	mov r3, sb
	ands r0, r3
	ldr r2, [sp, #0x14]
	cmp r0, #0
	beq .L080E1E66
	movs r3, #0x12
	ldrsh r0, [r1, r3]
	cmp r0, r5
	bne .L080E1E66
	mov r0, sl
	adds r1, r5, #0
	bl sub_080E1540
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, [sp, #0x14]
	cmp r0, #1
	beq .L080E1E66
	ldrh r0, [r7]
	adds r0, r0, r2
	strh r0, [r7]
.L080E1E66:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, [sp, #0xc]
	cmp r4, r0
	blt .L080E1E2A
.L080E1E72:
	adds r0, r5, #0
	bl sub_08134C3C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080E1E8C
	lsls r0, r6
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2]
.L080E1E8C:
	adds r0, r5, #0
	bl sub_0815BA28
	cmp r0, #0
	bne .L080E1EA8
	movs r0, #1
	lsls r0, r6
	mov r3, r8
	ldrh r3, [r3]
	adds r0, r0, r3
	mov r1, r8
	strh r0, [r1]
	movs r2, #0
	str r2, [sp, #8]
.L080E1EA8:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0xb
	bls .L080E1E08
	ldr r3, .L080E1FBC
	ldrh r0, [r3]
	cmp r0, #0
	bne .L080E1EC6
	mov r1, sl
	ldr r0, [r1, #0x20]
	movs r1, #0x10
	orrs r0, r1
	mov r2, sl
	str r0, [r2, #0x20]
.L080E1EC6:
	ldr r3, [sp, #8]
	cmp r3, #1
	bne .L080E1EDA
	mov r1, sl
	ldr r0, [r1, #0x20]
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	mov r2, sl
	str r0, [r2, #0x20]
.L080E1EDA:
	movs r6, #0
	ldr r3, [sp, #0x10]
	ldr r7, .L080E1FB4
	ldr r2, .L080E1FBC
	movs r4, #1
.L080E1EE4:
	lsls r0, r6, #1
	adds r0, r3, r0
	ldrh r5, [r0]
	cmp r5, r7
	beq .L080E1F0A
	ldr r0, [sp, #4]
	ldr r1, [sp]
	cmp r0, r1
	bls .L080E1F00
	adds r0, r4, #0
	lsls r0, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
.L080E1F00:
	ldr r0, [sp, #4]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
.L080E1F0A:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0xb
	bls .L080E1EE4
	movs r2, #0
	mov r8, r2
	movs r6, #0
	ldr r3, .L080E1FB4
	mov sb, r3
	ldr r7, .L080E1FBC
.L080E1F20:
	lsls r0, r6, #1
	ldr r1, [sp, #0x10]
	adds r0, r1, r0
	ldrh r5, [r0]
	cmp r5, sb
	beq .L080E1F52
	movs r0, #0
	bl Combatant_GetLevel
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r5, #0
	bl Demon_GetRecord
	ldrb r0, [r0, #1]
	cmp r4, r0
	bge .L080E1F52
	movs r2, #1
	mov r8, r2
	mov r0, r8
	lsls r0, r6
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
.L080E1F52:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0xb
	bls .L080E1F20
	mov r3, r8
	cmp r3, #0
	bne .L080E1F6E
	mov r1, sl
	ldr r0, [r1, #0x20]
	movs r1, #0x80
	orrs r0, r1
	mov r2, sl
.L080E1F6C:
	str r0, [r2, #0x20]
.L080E1F6E:
	ldr r3, .L080E1FB0
	ldr r4, [r3, #4]
	cmp r4, #0
	beq .L080E1FD0
	mov r1, sl
	ldr r0, [r1, #0x20]
	movs r1, #0x40
	orrs r0, r1
	mov r2, sl
	str r0, [r2, #0x20]
	adds r0, r4, #0
	bl sub_0815DBB4
	cmp r4, #0
	bge .L080E1F94
	ldr r2, .L080E1FC0
	ldr r3, .L080E1FC4
	bl sub_0815D428
.L080E1F94:
	ldr r2, .L080E1FC8
	ldr r3, .L080E1FCC
	bl sub_0815D490
	bl sub_0815DCF4
	bl sub_0815E5B4
	adds r4, r0, #0
	b .L080E1FD4
.L080E1FA8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E1FAC: .4byte 0x00000AC3
.L080E1FB0: .4byte 0x0203B5AC @ EWRAM+0x3B5AC
.L080E1FB4: .4byte 0x0000FFFF
.L080E1FB8: .4byte 0xFFFF0000
.L080E1FBC: .4byte 0x0203B5AA @ EWRAM+0x3B5AA
.L080E1FC0: .4byte 0x41F00000
.L080E1FC4: .4byte 0x00000000
.L080E1FC8: .4byte 0x3FB47AE1
.L080E1FCC: .4byte 0x47AE147B
.L080E1FD0:
	ldr r3, .L080E2008
	ldr r4, [r3, #8]
.L080E1FD4:
	bl sub_080C3100
	mov r2, sl
	ldr r1, [r2, #8]
	subs r0, r0, r1
	adds r0, r0, r4
	ldr r1, .L080E200C
	cmp r0, r1
	bgt .L080E1FEE
	ldr r0, [r2, #0x20]
	movs r1, #2
	orrs r0, r1
	str r0, [r2, #0x20]
.L080E1FEE:
	mov r3, sl
	ldr r0, [r3, #0x20]
	movs r1, #1
	orrs r0, r1
	str r0, [r3, #0x20]
.L080E1FF8:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E2008: .4byte 0x0203B5AC @ EWRAM+0x3B5AC
.L080E200C: .4byte 0x000F423F

	thumb_func_start sub_080E2010
sub_080E2010: @ 0x080E2010
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r3, .L080E2028
	adds r5, r3, #0
	adds r5, #0x58
	movs r0, #0
	strh r0, [r4, #0x1e]
	cmp r2, #0
	bne .L080E202C
	adds r0, r3, #0
	b .L080E2032
	.byte 0x00, 0x00
.L080E2028: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E202C:
	cmp r2, #1
	bne .L080E203E
	adds r0, r5, #0
.L080E2032:
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq .L080E203E
	movs r0, #1
	strh r0, [r4, #0x1e]
.L080E203E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080E2044
sub_080E2044: @ 0x080E2044
	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r4, .L080E2064
	ldrh r1, [r4]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L080E2068
	strh r3, [r2, #0x1c]
	movs r0, #0x65
	bl sub_080C51D4
	b .L080E207A
.L080E2064: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080E2068:
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080E207A
	strh r3, [r2, #0x1c]
	movs r0, #0x66
	bl sub_080C51D4
.L080E207A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080E2080
sub_080E2080: @ 0x080E2080
.L080E2080:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r5, #0
	movs r2, #0xff
.L080E2090:
	mov r0, sp
	adds r1, r0, r5
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r5, #1
	cmp r5, #5
	bls .L080E2090
	movs r5, #0
	ldr r2, .L080E20E0
.L080E20A4:
	mov r1, sp
	adds r0, r1, r5
	adds r1, r5, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r5, #1
	cmp r5, #5
	bls .L080E20A4
	movs r5, #0
	movs r2, #1
	rsbs r2, r2, #0
	mov sl, r2
	mov r4, sp
.L080E20BE:
	ldrb r0, [r4]
	mov sb, r0
	ldrb r1, [r4, #3]
	mov r8, r1
	lsls r0, r0, #0x18
	asrs r2, r0, #0x18
	cmp r2, sl
	bne .L080E20E4
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	beq .L080E2116
	strb r1, [r4]
	movs r0, #0xff
	strb r0, [r4, #3]
	b .L080E2116
	.byte 0x00, 0x00
.L080E20E0: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080E20E4:
	mov r3, r8
	lsls r0, r3, #0x18
	asrs r6, r0, #0x18
	cmp r6, #0
	blt .L080E2116
	adds r0, r2, #0
	bl Combatant_GetStatus
	movs r7, #0xa0
	lsls r7, r7, #8
	adds r1, r7, #0
	ands r1, r0
	cmp r1, #0
	beq .L080E2116
	adds r0, r6, #0
	bl Combatant_GetStatus
	adds r1, r7, #0
	ands r1, r0
	cmp r1, #0
	bne .L080E2116
	mov r0, r8
	strb r0, [r4]
	mov r1, sb
	strb r1, [r4, #3]
.L080E2116:
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	bls .L080E20BE
	movs r5, #0
	ldr r2, .L080E2144
.L080E2122:
	adds r0, r5, r2
	mov r3, sp
	adds r1, r3, r5
	ldrb r1, [r1]
	strb r1, [r0]
	adds r5, #1
	cmp r5, #5
	bls .L080E2122
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080E2144: .4byte 0x030050E0 @ IWRAM+0x50E0

	thumb_func_start sub_080E2148
sub_080E2148: @ 0x080E2148
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, .L080E21A8
	mov r8, r0
	movs r1, #0x58
	add r1, r8
	mov sb, r1
	ldr r1, [r0, #0x20]
	movs r0, #3
	ands r1, r0
	cmp r1, #3
	bne .L080E21C4
	mov r2, sb
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #3
	bne .L080E21C4
	mov r1, r8
	ldr r0, [r1, #8]
	rsbs r0, r0, #0
	bl sub_080C30AC
	mov r2, sb
	ldr r4, [r2, #4]
	cmp r4, #0
	beq .L080E21BC
	adds r0, r4, #0
	bl sub_0815DBB4
	cmp r4, #0
	bge .L080E2194
	ldr r2, .L080E21AC
	ldr r3, .L080E21B0
	bl sub_0815D428
.L080E2194:
	ldr r2, .L080E21B4
	ldr r3, .L080E21B8
	bl sub_0815D490
	bl sub_0815DCF4
	bl sub_0815E5B4
	b .L080E21C0
	.byte 0x00, 0x00
.L080E21A8: .4byte 0x0203B554 @ EWRAM+0x3B554
.L080E21AC: .4byte 0x41F00000
.L080E21B0: .4byte 0x00000000
.L080E21B4: .4byte 0x3FB47AE1
.L080E21B8: .4byte 0x47AE147B
.L080E21BC:
	mov r1, sb
	ldr r0, [r1, #8]
.L080E21C0:
	bl sub_080C30AC
.L080E21C4:
	mov r2, r8
	ldr r0, [r2, #0x20]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq .L080E21EC
	mov r2, sb
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq .L080E21EC
	mov r1, r8
	ldr r0, [r1, #0x14]
	rsbs r0, r0, #0
	bl sub_080C3114
	mov r2, sb
	ldr r0, [r2, #0x14]
	bl sub_080C3114
.L080E21EC:
	mov r1, r8
	ldr r0, [r1, #0x20]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080E2272
	mov r2, sb
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq .L080E2272
	movs r7, #0
	ldr r0, .L080E22E0
	mov sl, r0
.L080E2208:
	lsls r0, r7, #2
	add r0, r8
	adds r1, r0, #0
	adds r1, #0x40
	ldrh r6, [r1]
	adds r0, #0x42
	ldrh r5, [r0]
	cmp r6, sl
	beq .L080E2230
	movs r4, #0
	cmp r4, r5
	bhs .L080E2230
.L080E2220:
	adds r0, r6, #0
	bl sub_080C33AC
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	blo .L080E2220
.L080E2230:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #4
	bls .L080E2208
	movs r7, #0
	ldr r1, .L080E22E0
	mov sl, r1
.L080E2240:
	lsls r0, r7, #2
	add r0, sb
	adds r1, r0, #0
	adds r1, #0x40
	ldrh r6, [r1]
	adds r0, #0x42
	ldrh r5, [r0]
	adds r7, #1
	cmp r6, sl
	beq .L080E226A
	movs r4, #0
	cmp r4, r5
	bhs .L080E226A
.L080E225A:
	adds r0, r6, #0
	bl sub_080C3328
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	blo .L080E225A
.L080E226A:
	lsls r0, r7, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #4
	bls .L080E2240
.L080E2272:
	mov r0, r8
	ldr r2, [r0, #0x20]
	movs r3, #0x10
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq .L080E233E
	mov r0, sb
	ldr r1, [r0, #0x20]
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq .L080E233E
	movs r3, #0x20
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq .L080E233E
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq .L080E233E
	movs r3, #0x80
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq .L080E233E
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq .L080E233E
	movs r0, #0x80
	lsls r0, r0, #1
	ands r2, r0
	cmp r2, #0
	beq .L080E233E
	ands r1, r0
	cmp r1, #0
	beq .L080E233E
	movs r6, #0
	mov r7, r8
	adds r7, #0x26
	movs r1, #0x26
	add r1, sb
	mov r8, r1
	ldr r2, .L080E22E0
	mov sb, r2
.L080E22D0:
	lsls r0, r6, #1
	adds r0, r7, r0
	ldrh r5, [r0]
	cmp r5, sb
	beq .L080E230C
	movs r4, #4
	b .L080E22EA
	.byte 0x00, 0x00
.L080E22E0: .4byte 0x0000FFFF
.L080E22E4:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L080E22EA:
	cmp r4, #0xf
	bhi .L080E2304
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	movs r2, #0x12
	ldrsh r0, [r0, r2]
	cmp r0, r5
	bne .L080E22E4
.L080E2304:
	adds r0, r4, #0
	movs r1, #1
	bl Party_Remove
.L080E230C:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0xb
	bls .L080E22D0
	movs r6, #0
	ldr r4, .L080E2358
.L080E231A:
	lsls r0, r6, #1
	add r0, r8
	ldrh r5, [r0]
	cmp r5, r4
	beq .L080E2330
	adds r0, r5, #0
	bl Stock_AddDemon
	adds r0, r5, #0
	bl sub_080C29E8
.L080E2330:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0xb
	bls .L080E231A
	bl sub_080E2080
.L080E233E:
	ldr r1, .L080E235C
	ldr r2, .L080E2360
	adds r0, r1, r2
	ldr r0, [r0]
	bl SaveSlot_Write
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080E2358: .4byte 0x0000FFFF
.L080E235C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080E2360: .4byte 0x000018B0

	thumb_func_start umul3232H32
umul3232H32: @ 0x080E2364
.L080E2364:
	add r2, pc, #0
	bx r2
	.arm
	umull r2, r3, r0, r1
	add r0, r3, #0
	bx lr
	.thumb

	thumb_func_start SoundMain
SoundMain: @ 0x080E2374
.L080E2374:
	ldr r0, .L080E23E0
	ldr r0, [r0]
	ldr r2, .L080E23E4
	ldr r3, [r0]
	cmp r2, r3
	beq .L080E2382
	bx lr
.L080E2382:
	adds r3, #1
	str r3, [r0]
	push {r4, r5, r6, r7, lr}
	mov r1, r8
	mov r2, sb
	mov r3, sl
	mov r4, fp
	push {r0, r1, r2, r3, r4}
	sub sp, #0x18
	ldrb r1, [r0, #0xc]
	cmp r1, #0
	beq .L080E23A6
	ldr r2, .L080E23EC
	ldrb r2, [r2]
	cmp r2, #0xa0
	bhs .L080E23A4
	adds r2, #0xe4
.L080E23A4:
	adds r1, r1, r2
.L080E23A6:
	str r1, [sp, #0x14]
	ldr r3, [r0, #0x20]
	cmp r3, #0
	beq .L080E23B6
	ldr r0, [r0, #0x24]
	bl sub_080E2722
	ldr r0, [sp, #0x18]
.L080E23B6:
	ldr r3, [r0, #0x28]
	bl sub_080E2722
	ldr r0, [sp, #0x18]
	ldr r3, [r0, #0x10]
	mov r8, r3
	ldr r5, .L080E23F0
	adds r5, r5, r0
	ldrb r4, [r0, #4]
	subs r7, r4, #1
	bls .L080E23D6
	ldrb r1, [r0, #0xb]
	subs r1, r1, r7
	mov r2, r8
	muls r2, r1, r2
	adds r5, r5, r2
.L080E23D6:
	str r5, [sp, #8]
	ldr r6, .L080E23F4
	ldr r3, .L080E23E8
	bx r3
	.byte 0x00, 0x00
.L080E23E0: .4byte 0x03007FF0 @ IWRAM+0x7FF0
.L080E23E4: .4byte 0x68736D53
.L080E23E8: .4byte 0x03007001 @ IWRAM+0x7001
.L080E23EC: .4byte 0x04000006 @ REG_VCOUNT
.L080E23F0: .4byte 0x00000350
.L080E23F4: .4byte 0x00000630

	thumb_func_start SoundMainRAM
SoundMainRAM: @ 0x080E23F8
	ldrb r3, [r0, #5]
	cmp r3, #0
	beq .L080E2444
	add r1, pc, #4
	bx r1
	.byte 0x00, 0x00
	.arm
	cmp r4, #2
	addeq r7, r0, #0x350
	addne r7, r5, r8
	mov r4, r8
.L080E2414:
	ldrsb r0, [r5]
	ldrsb r1, [r7], #1
	add r0, r0, r1
	mul r1, r0, r3
	asr r0, r1, #8
	tst r0, #0x80
	addne r0, r0, #1
	strb r0, [r5], #1
	subs r4, r4, #1
	bgt .L080E2414
	add r0, pc, #0x1f
	bx r0
	.thumb
.L080E2444:
	movs r0, #0
	mov r1, r8
	lsrs r1, r1, #3
	blo .L080E244E
	stm r5!, {r0}
.L080E244E:
	lsrs r1, r1, #1
	blo .L080E2456
	stm r5!, {r0}
	stm r5!, {r0}
.L080E2456:
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	subs r1, #1
	bgt .L080E2456
	ldr r4, [sp, #0x18]
	ldr r0, [r4, #0x18]
	mov ip, r0
	ldrb r0, [r4, #6]
	adds r4, #0x50
.L080E246C:
	str r0, [sp, #4]
	ldr r3, [r4, #0x24]
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq .L080E248C
	ldr r1, .L080E2488
	ldrb r1, [r1]
	cmp r1, #0xa0
	bhs .L080E2480
	adds r1, #0xe4
.L080E2480:
	cmp r1, r0
	blo .L080E248C
	b .L080E270E
	.byte 0x00, 0x00
.L080E2488: .4byte 0x04000006 @ REG_VCOUNT
.L080E248C:
	ldrb r6, [r4]
	movs r0, #0xc7
	tst r0, r6
	bne .L080E2496
	b .L080E2704
.L080E2496:
	movs r0, #0x80
	tst r0, r6
	beq .L080E24C6
	movs r0, #0x40
	tst r0, r6
	bne .L080E24D6
	movs r6, #3
	strb r6, [r4]
	adds r0, r3, #0
	adds r0, #0x10
	str r0, [r4, #0x28]
	ldr r0, [r3, #0xc]
	str r0, [r4, #0x18]
	movs r5, #0
	strb r5, [r4, #9]
	str r5, [r4, #0x1c]
	ldrb r2, [r3, #3]
	movs r0, #0xc0
	tst r0, r2
	beq .L080E251E
	movs r0, #0x10
	orrs r6, r0
	strb r6, [r4]
	b .L080E251E
.L080E24C6:
	ldrb r5, [r4, #9]
	movs r0, #4
	tst r0, r6
	beq .L080E24DC
	ldrb r0, [r4, #0xd]
	subs r0, #1
	strb r0, [r4, #0xd]
	bhi .L080E252C
.L080E24D6:
	movs r0, #0
	strb r0, [r4]
	b .L080E2704
.L080E24DC:
	movs r0, #0x40
	tst r0, r6
	beq .L080E24FC
	ldrb r0, [r4, #7]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #0xc]
	cmp r5, r0
	bhi .L080E252C
.L080E24EE:
	ldrb r5, [r4, #0xc]
	cmp r5, #0
	beq .L080E24D6
	movs r0, #4
	orrs r6, r0
	strb r6, [r4]
	b .L080E252C
.L080E24FC:
	movs r2, #3
	ands r2, r6
	cmp r2, #2
	bne .L080E251A
	ldrb r0, [r4, #5]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #6]
	cmp r5, r0
	bhi .L080E252C
	adds r5, r0, #0
	beq .L080E24EE
	subs r6, #1
	strb r6, [r4]
	b .L080E252C
.L080E251A:
	cmp r2, #3
	bne .L080E252C
.L080E251E:
	ldrb r0, [r4, #4]
	adds r5, r5, r0
	cmp r5, #0xff
	blo .L080E252C
	movs r5, #0xff
	subs r6, #1
	strb r6, [r4]
.L080E252C:
	strb r5, [r4, #9]
	ldr r0, [sp, #0x18]
	ldrb r0, [r0, #7]
	adds r0, #1
	muls r0, r5, r0
	lsrs r5, r0, #4
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	adds r0, r0, r1
	muls r0, r5, r0
	lsrs r0, r0, #9
	strb r0, [r4, #0xa]
	movs r0, #0x10
	ands r0, r6
	str r0, [sp, #0x10]
	beq .L080E255C
	adds r0, r3, #0
	adds r0, #0x10
	ldr r1, [r3, #8]
	adds r0, r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r3, #0xc]
	subs r0, r0, r1
	str r0, [sp, #0x10]
.L080E255C:
	ldr r5, [sp, #8]
	ldr r2, [r4, #0x18]
	ldr r3, [r4, #0x28]
	add r0, pc, #4
	bx r0
	.byte 0x00, 0x00
	.arm
	str r8, [sp]
	ldrb sl, [r4, #0xa]
	lsl sl, sl, #0x10
	ldrb r0, [r4, #1]
	tst r0, #8
	beq .L080E2670
.L080E2580:
	cmp r2, #4
	ble .L080E25DC
	subs r2, r2, r8
	movgt lr, #0
	bgt .L080E25AC
	mov lr, r8
	add r2, r2, r8
	sub r8, r2, #4
	sub lr, lr, r8
	ands r2, r2, #3
	moveq r2, #4
.L080E25AC:
	ldr r6, [r5]
.L080E25B0:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	adds r5, r5, #0x40000000
	blo .L080E25B0
	str r6, [r5], #4
	subs r8, r8, #4
	bgt .L080E25AC
	adds r8, r8, lr
	beq .L080E26F0
.L080E25DC:
	ldr r6, [r5]
.L080E25E0:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	subs r2, r2, #1
	beq .L080E2640
.L080E25F8:
	adds r5, r5, #0x40000000
	blo .L080E25E0
	str r6, [r5], #4
	subs r8, r8, #4
	bgt .L080E2580
	b .L080E26F0
.L080E2610:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq .L080E2634
	ldr r3, [sp, #0x14]
	rsb sb, r2, #0
.L080E2624:
	adds r2, r0, r2
	bgt .L080E26C4
	sub sb, sb, r0
	b .L080E2624
.L080E2634:
	pop {r4, ip}
	mov r2, #0
	b .L080E2650
.L080E2640:
	ldr r2, [sp, #0x10]
	cmp r2, #0
	ldrne r3, [sp, #0xc]
	bne .L080E25F8
.L080E2650:
	strb r2, [r4]
	lsr r0, r5, #0x1e
	bic r5, r5, #0xc0000000
	rsb r0, r0, #3
	lsl r0, r0, #3
	ror r6, r6, r0
	str r6, [r5], #4
	b .L080E26F8
.L080E2670:
	push {r4, ip}
	ldr lr, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	mul r4, ip, r1
	ldrsb r0, [r3]
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
.L080E268C:
	ldr r6, [r5]
.L080E2690:
	mul sb, lr, r1
	add sb, r0, sb, asr #23
	mul ip, sl, sb
	bic ip, ip, #0xff0000
	add r6, ip, r6, ror #8
	add lr, lr, r4
	lsrs sb, lr, #0x17
	beq .L080E26D0
	bic lr, lr, #0x3f800000
	subs r2, r2, sb
	ble .L080E2610
	subs sb, sb, #1
	addeq r0, r0, r1
.L080E26C4:
	ldrsbne r0, [r3, sb]!
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
.L080E26D0:
	adds r5, r5, #0x40000000
	blo .L080E2690
	str r6, [r5], #4
	subs r8, r8, #4
	bgt .L080E268C
	sub r3, r3, #1
	pop {r4, ip}
	str lr, [r4, #0x1c]
.L080E26F0:
	str r2, [r4, #0x18]
	str r3, [r4, #0x28]
.L080E26F8:
	ldr r8, [sp]
	add r0, pc, #1
	bx r0
	.thumb
.L080E2704:
	ldr r0, [sp, #4]
	subs r0, #1
	ble .L080E270E
	adds r4, #0x40
	b .L080E246C
.L080E270E:
	ldr r0, [sp, #0x18]
	ldr r3, .L080E2724
	str r3, [r0]
	add sp, #0x1c
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r3}

	thumb_func_start sub_080E2722
sub_080E2722: @ 0x080E2722
.L080E2722:
	bx r3
.L080E2724: .4byte 0x68736D53

	thumb_func_start SoundMainBTM
SoundMainBTM: @ 0x080E2728
	mov ip, r4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	movs r4, #0
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	mov r4, ip
	bx lr
	.byte 0x00, 0x00
