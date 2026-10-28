	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_081316FC
sub_081316FC: @ 0x081316FC
.L081316FC:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl sub_080C3100
	mov r8, r0
	ldr r0, .L08131760
	ldr r7, [r0]
	ldr r6, .L08131764
	ldrh r1, [r6]
	movs r0, #0xff
	bl Party_CountEquipped
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, r4, #0
	ldrh r0, [r6]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, r2, #0
	ldr r0, .L08131768
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x2a
	beq .L08131736
	b .L08131908
.L08131736:
	ldr r0, .L0813176C
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #1
	beq .L08131742
	b .L08131854
.L08131742:
	ldr r5, .L08131770
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0x63
	bne .L08131780
	ldr r1, .L08131774
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131778
	ldr r0, .L0813177C
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L08131A68
	.byte 0x00, 0x00
.L08131760: .4byte 0x03006694 @ IWRAM+0x6694
.L08131764: .4byte 0x030069A8 @ IWRAM+0x69A8
.L08131768: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813176C: .4byte 0x030068BC @ IWRAM+0x68BC
.L08131770: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131774: .4byte 0x03006848 @ IWRAM+0x6848
.L08131778: .4byte 0x03006680 @ IWRAM+0x6680
.L0813177C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131780:
	cmp r0, #1
	bgt .L081317D8
	ldrh r0, [r6]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi .L0813179C
	ldr r1, .L08131798
	movs r0, #0
	b .L081317C6
.L08131798: .4byte 0x03006848 @ IWRAM+0x6848
.L0813179C:
	movs r2, #0
	ldrsh r0, [r5, r2]
	adds r0, #1
	muls r0, r7, r0
	add r0, r8
	ldr r1, .L081317B4
	cmp r0, r1
	bls .L081317BC
	ldr r1, .L081317B8
	movs r0, #0
	b .L081317C6
	.byte 0x00, 0x00
.L081317B4: .4byte 0x000F423F
.L081317B8: .4byte 0x03006848 @ IWRAM+0x6848
.L081317BC:
	ldr r1, .L081317CC
	ldr r0, .L081317D0
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
.L081317C6:
	strh r0, [r1]
	ldr r1, .L081317D4
	b .L08131A66
.L081317CC: .4byte 0x03006848 @ IWRAM+0x6848
.L081317D0: .4byte 0x0300696C @ IWRAM+0x696C
.L081317D4: .4byte 0x03006680 @ IWRAM+0x6680
.L081317D8:
	movs r3, #0
	ldrsh r4, [r5, r3]
	ldrh r0, [r6]
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bge .L08131834
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r0, #1
	muls r0, r7, r0
	add r0, r8
	ldr r1, .L08131804
	cmp r0, r1
	bls .L08131810
	ldr r1, .L08131808
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L0813180C
	b .L0813181E
.L08131804: .4byte 0x000F423F
.L08131808: .4byte 0x03006848 @ IWRAM+0x6848
.L0813180C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131810:
	ldr r2, .L08131828
	ldr r1, .L0813182C
	ldrh r0, [r1]
	lsls r0, r0, #1
	adds r0, #2
	strh r0, [r2]
	adds r0, r1, #0
.L0813181E:
	ldr r1, .L08131830
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L08131A68
.L08131828: .4byte 0x03006848 @ IWRAM+0x6848
.L0813182C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131830: .4byte 0x03006680 @ IWRAM+0x6680
.L08131834:
	ldr r1, .L08131848
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L0813184C
	ldr r0, .L08131850
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L08131A68
	.byte 0x00, 0x00
.L08131848: .4byte 0x03006848 @ IWRAM+0x6848
.L0813184C: .4byte 0x03006680 @ IWRAM+0x6680
.L08131850: .4byte 0x0300696C @ IWRAM+0x696C
.L08131854:
	ldr r0, .L081318A8
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov sb, r0
	cmp r1, #0x59
	bgt .L081318E8
	mov r0, sb
	movs r1, #0
	ldrsh r5, [r0, r1]
	cmp r5, r2
	beq .L081318E8
	adds r5, #1
	ldrh r0, [r6]
	bl sub_080C32D4
	adds r4, r0, #0
	ldrh r1, [r6]
	movs r0, #0xff
	bl Party_CountEquipped
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r0
	cmp r5, r4
	bgt .L081318E8
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, #1
	muls r0, r7, r0
	add r0, r8
	ldr r1, .L081318AC
	cmp r0, r1
	bls .L081318B8
	ldr r1, .L081318B0
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L081318B4
	b .L081318C6
	.byte 0x00, 0x00
.L081318A8: .4byte 0x030065FC @ IWRAM+0x65FC
.L081318AC: .4byte 0x000F423F
.L081318B0: .4byte 0x03006848 @ IWRAM+0x6848
.L081318B4: .4byte 0x0300696C @ IWRAM+0x696C
.L081318B8:
	ldr r2, .L081318D8
	ldr r1, .L081318DC
	ldrh r0, [r1]
	lsls r0, r0, #1
	adds r0, #3
	strh r0, [r2]
	adds r0, r1, #0
.L081318C6:
	ldr r1, .L081318E0
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	strh r0, [r1]
	ldr r0, .L081318E4
	mov sb, r0
	b .L08131A5C
	.byte 0x00, 0x00
.L081318D8: .4byte 0x03006848 @ IWRAM+0x6848
.L081318DC: .4byte 0x0300696C @ IWRAM+0x696C
.L081318E0: .4byte 0x03006680 @ IWRAM+0x6680
.L081318E4: .4byte 0x030065FC @ IWRAM+0x65FC
.L081318E8:
	ldr r1, .L081318FC
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131900
	ldr r0, .L08131904
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	b .L08131A5A
	.byte 0x00, 0x00
.L081318FC: .4byte 0x03006848 @ IWRAM+0x6848
.L08131900: .4byte 0x03006680 @ IWRAM+0x6680
.L08131904: .4byte 0x0300696C @ IWRAM+0x696C
.L08131908:
	ldr r0, .L08131930
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L081319C4
	ldr r0, .L08131934
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov sb, r0
	cmp r1, #0x63
	bne .L08131944
	ldr r1, .L08131938
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L0813193C
	ldr r0, .L08131940
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L081319AA
.L08131930: .4byte 0x030068BC @ IWRAM+0x68BC
.L08131934: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131938: .4byte 0x03006848 @ IWRAM+0x6848
.L0813193C: .4byte 0x03006680 @ IWRAM+0x6680
.L08131940: .4byte 0x0300696C @ IWRAM+0x696C
.L08131944:
	adds r0, r4, r2
	mov r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	cmp r0, #0x62
	ble .L08131970
	ldr r1, .L08131964
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131968
	ldr r0, .L0813196C
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L081319AA
	.byte 0x00, 0x00
.L08131964: .4byte 0x03006848 @ IWRAM+0x6848
.L08131968: .4byte 0x03006680 @ IWRAM+0x6680
.L0813196C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131970:
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, #1
	muls r0, r7, r0
	cmp r0, r8
	bls .L0813199C
	ldr r1, .L08131990
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131994
	ldr r0, .L08131998
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	b .L081319AA
.L08131990: .4byte 0x03006848 @ IWRAM+0x6848
.L08131994: .4byte 0x03006680 @ IWRAM+0x6680
.L08131998: .4byte 0x0300696C @ IWRAM+0x696C
.L0813199C:
	ldr r1, .L081319B8
	ldr r0, .L081319BC
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #2
	strh r0, [r1]
	ldr r1, .L081319C0
.L081319AA:
	strh r0, [r1]
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #1
	bgt .L08131A6A
	b .L08131A66
.L081319B8: .4byte 0x03006848 @ IWRAM+0x6848
.L081319BC: .4byte 0x0300696C @ IWRAM+0x696C
.L081319C0: .4byte 0x03006680 @ IWRAM+0x6680
.L081319C4:
	ldr r0, .L081319E4
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov sb, r0
	cmp r1, #0x63
	bne .L081319F4
	ldr r1, .L081319E8
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L081319EC
	ldr r0, .L081319F0
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	b .L08131A5A
	.byte 0x00, 0x00
.L081319E4: .4byte 0x030065FC @ IWRAM+0x65FC
.L081319E8: .4byte 0x03006848 @ IWRAM+0x6848
.L081319EC: .4byte 0x03006680 @ IWRAM+0x6680
.L081319F0: .4byte 0x0300696C @ IWRAM+0x696C
.L081319F4:
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r0, #1
	muls r0, r7, r0
	cmp r0, r8
	bls .L08131A20
	ldr r1, .L08131A14
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131A18
	ldr r0, .L08131A1C
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	b .L08131A5A
.L08131A14: .4byte 0x03006848 @ IWRAM+0x6848
.L08131A18: .4byte 0x03006680 @ IWRAM+0x6680
.L08131A1C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131A20:
	adds r0, r5, r3
	mov r3, sb
	ldrh r3, [r3]
	adds r0, r0, r3
	cmp r0, #0x62
	ble .L08131A4C
	ldr r1, .L08131A40
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08131A44
	ldr r0, .L08131A48
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	b .L08131A5A
	.byte 0x00, 0x00
.L08131A40: .4byte 0x03006848 @ IWRAM+0x6848
.L08131A44: .4byte 0x03006680 @ IWRAM+0x6680
.L08131A48: .4byte 0x0300696C @ IWRAM+0x696C
.L08131A4C:
	ldr r1, .L08131A78
	ldr r0, .L08131A7C
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, #3
	strh r0, [r1]
	ldr r1, .L08131A80
.L08131A5A:
	strh r0, [r1]
.L08131A5C:
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #1
	bne .L08131A6A
.L08131A66:
	movs r0, #0
.L08131A68:
	strh r0, [r1]
.L08131A6A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08131A78: .4byte 0x03006848 @ IWRAM+0x6848
.L08131A7C: .4byte 0x0300696C @ IWRAM+0x696C
.L08131A80: .4byte 0x03006680 @ IWRAM+0x6680
