	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080ED5B4
sub_080ED5B4: @ 0x080ED5B4
.L080ED5B4:
	push {r4, lr}
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #3
	ldr r0, .L080ED5D4
	adds r2, r2, r0
	ldr r0, .L080ED5D8
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrb r3, [r1]
	movs r1, #0
	ldrb r0, [r2]
	cmp r3, r0
	bhi .L080ED5DC
	movs r4, #0
	b .L080ED5F0
.L080ED5D4: .4byte gUnknown_0876EBA8
.L080ED5D8: .4byte 0x0203A450 @ EWRAM+0x3A450
.L080ED5DC:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #7
	bhi .L080ED5F0
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r3, r0
	bhi .L080ED5DC
	adds r4, r1, #0
.L080ED5F0:
	lsls r0, r4, #1
	adds r1, r2, #0
	adds r1, #8
	adds r1, r1, r0
	ldrh r0, [r1]
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080ED600
sub_080ED600: @ 0x080ED600
.L080ED600:
	push {lr}
	adds r1, r0, #0
	movs r0, #0
	bl sub_080ED3FC
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080ED610
sub_080ED610: @ 0x080ED610
.L080ED610:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF648
	ldrb r0, [r0, #0xd]
	lsrs r0, r0, #4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #7
	ble .L080ED62C
	movs r0, #7
	ands r0, r2
	b .L080ED664
.L080ED62C:
	lsrs r4, r0, #0x10
	bl sub_080C2244
	movs r1, #3
	ands r0, r1
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #0x10
	cmp r1, #0
	blt .L080ED648
	asrs r0, r1, #0x11
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080ED648:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0
	blt .L080ED662
	cmp r1, #7
	ble .L080ED664
	b .L080ED674
.L080ED662:
	movs r0, #0
.L080ED664:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne .L080ED670
	movs r0, #1
	b .L080ED676
.L080ED670:
	cmp r0, #8
	ble .L080ED676
.L080ED674:
	movs r0, #7
.L080ED676:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080ED67C
sub_080ED67C: @ 0x080ED67C
.L080ED67C:
	push {r4, lr}
	ldr r4, .L080ED690
	bl sub_080ED464
	adds r0, r0, r4
	ldrb r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080ED690: .4byte gUnknown_0876F688

	thumb_func_start sub_080ED694
sub_080ED694: @ 0x080ED694
.L080ED694:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r0, [r0, #2]
	pop {r1}
	bx r1

	thumb_func_start sub_080ED6A4
sub_080ED6A4: @ 0x080ED6A4
.L080ED6A4:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	pop {r1}
	bx r1

	thumb_func_start sub_080ED6B8
sub_080ED6B8: @ 0x080ED6B8
.L080ED6B8:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	pop {r1}
	bx r1

	thumb_func_start sub_080ED6CC
sub_080ED6CC: @ 0x080ED6CC
.L080ED6CC:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r0, [r0, #3]
	pop {r1}
	bx r1

	thumb_func_start sub_080ED6DC
sub_080ED6DC: @ 0x080ED6DC
.L080ED6DC:
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	cmp r6, #0x67
	bgt .L080ED70A
	bl sub_080F4070
	adds r4, r0, #0
	adds r0, r6, #0
	bl sub_080ED6CC
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	cmp r4, #0
	bge .L080ED6FE
	movs r1, #0
.L080ED6FE:
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r7, #0
	bl sub_080F408C
	b .L080ED73E
.L080ED70A:
	adds r0, r7, #0
	bl sub_080F401C
	adds r4, r0, #0
	adds r0, r7, #0
	bl sub_080F4038
	adds r5, r0, #0
	adds r0, r6, #0
	bl sub_080ED6CC
	muls r0, r5, r0
	movs r1, #0x64
	bl __udivsi3
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	cmp r4, #0
	bge .L080ED734
	movs r1, #0
.L080ED734:
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r7, #0
	bl sub_080F4054
.L080ED73E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080ED744
sub_080ED744: @ 0x080ED744
.L080ED744:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	cmp r6, #0x67
	bgt .L080ED766
	bl sub_080F4070
	adds r4, r0, #0
	adds r0, r6, #0
	bl sub_080ED6CC
	subs r4, r4, r0
	lsls r4, r4, #0x10
	cmp r4, #0
	blt .L080ED78C
.L080ED762:
	movs r0, #1
	b .L080ED78E
.L080ED766:
	adds r0, r5, #0
	bl sub_080F401C
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080F4038
	adds r5, r0, #0
	adds r0, r6, #0
	bl sub_080ED6CC
	muls r0, r5, r0
	movs r1, #0x64
	bl __udivsi3
	subs r4, r4, r0
	lsls r4, r4, #0x10
	cmp r4, #0
	bgt .L080ED762
.L080ED78C:
	movs r0, #0
.L080ED78E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_080ED794
sub_080ED794: @ 0x080ED794
.L080ED794:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrh r0, [r0, #4]
	pop {r1}
	bx r1

	thumb_func_start sub_080ED7A4
sub_080ED7A4: @ 0x080ED7A4
.L080ED7A4:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r0, [r0, #1]
	pop {r1}
	bx r1

	thumb_func_start sub_080ED7B4
sub_080ED7B4: @ 0x080ED7B4
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080ED7B8
sub_080ED7B8: @ 0x080ED7B8
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080ED7BC
sub_080ED7BC: @ 0x080ED7BC
.L080ED7BC:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, .L080ED828
	ldr r4, .L080ED82C
	ldr r2, .L080ED830
	adds r1, r0, r2
	str r1, [r4]
	ldr r2, .L080ED834
	ldr r3, .L080ED838
	adds r0, r0, r3
	str r0, [r2]
	movs r0, #0
	str r0, [sp]
	ldr r2, .L080ED83C
	mov r0, sp
	bl CpuSet
	movs r3, #0
	adds r7, r4, #0
	movs r6, #0x94
	lsls r6, r6, #1
	movs r5, #0x96
	lsls r5, r5, #1
	movs r4, #8
.L080ED7EC:
	ldr r0, [r7]
	lsls r2, r3, #1
	adds r1, r0, r6
	adds r1, r1, r2
	adds r0, r0, r5
	adds r0, r0, r2
	strh r4, [r0]
	strh r4, [r1]
	adds r3, #1
	cmp r3, #1
	ble .L080ED7EC
	movs r3, #0
	ldr r4, .L080ED82C
	ldr r0, .L080ED840
	adds r2, r0, #0
.L080ED80A:
	ldr r0, [r4]
	lsls r1, r3, #1
	adds r0, #0x56
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r1, r2
	strh r1, [r0]
	adds r3, #1
	cmp r3, #7
	ble .L080ED80A
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080ED828: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ED82C: .4byte 0x03006434 @ IWRAM+0x6434
.L080ED830: .4byte 0x00000F6C
.L080ED834: .4byte 0x03006438 @ IWRAM+0x6438
.L080ED838: .4byte 0x00001128
.L080ED83C: .4byte 0x05000068 @ PLTT+0x68
.L080ED840: .4byte 0x0000FFFF

	thumb_func_start sub_080ED844
sub_080ED844: @ 0x080ED844
	push {r4, r5, r6, r7, lr}
	movs r3, #0
	ldr r7, .L080ED870
	movs r6, #0x94
	lsls r6, r6, #1
	movs r5, #0x96
	lsls r5, r5, #1
	movs r4, #8
.L080ED854:
	ldr r0, [r7]
	lsls r2, r3, #1
	adds r1, r0, r6
	adds r1, r1, r2
	adds r0, r0, r5
	adds r0, r0, r2
	strh r4, [r0]
	strh r4, [r1]
	adds r3, #1
	cmp r3, #1
	ble .L080ED854
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080ED870: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080ED874
sub_080ED874: @ 0x080ED874
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080ED878
sub_080ED878: @ 0x080ED878
.L080ED878:
	push {r4, r5, lr}
	ldr r3, .L080ED8B8
	ldr r1, [r3]
	movs r0, #0
	strh r0, [r1, #4]
	ldrh r2, [r1]
	ldr r0, .L080ED8BC
	ands r0, r2
	strh r0, [r1]
	movs r1, #0
	adds r5, r3, #0
	movs r4, #0
.L080ED890:
	lsls r0, r1, #3
	adds r3, r1, #1
	subs r0, r0, r1
	lsls r1, r0, #2
	movs r2, #0xd
.L080ED89A:
	ldr r0, [r5]
	adds r0, #0x78
	adds r0, r0, r1
	strh r4, [r0]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge .L080ED89A
	adds r1, r3, #0
	cmp r1, #5
	ble .L080ED890
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080ED8B8: .4byte 0x03006434 @ IWRAM+0x6434
.L080ED8BC: .4byte 0x0000FF7F

	thumb_func_start sub_080ED8C0
sub_080ED8C0: @ 0x080ED8C0
.L080ED8C0:
	push {lr}
	adds r2, r0, #0
	cmp r2, #0xf
	bgt .L080ED8EC
	movs r1, #0
	ldr r3, .L080ED8E4
.L080ED8CC:
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r2, r0
	beq .L080ED8E8
	adds r1, #1
	cmp r1, #5
	bls .L080ED8CC
	movs r0, #0
	b .L080ED8F0
	.byte 0x00, 0x00
.L080ED8E4: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080ED8E8:
	adds r0, r1, #0
	b .L080ED8F0
.L080ED8EC:
	adds r0, r2, #0
	subs r0, #0xa
.L080ED8F0:
	pop {r1}
	bx r1

	thumb_func_start sub_080ED8F4
sub_080ED8F4: @ 0x080ED8F4
.L080ED8F4:
	ldr r0, .L080ED8FC
	ldr r0, [r0]
	ldrh r0, [r0]
	bx lr
.L080ED8FC: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080ED900
sub_080ED900: @ 0x080ED900
.L080ED900:
	ldr r1, .L080ED908
	ldr r1, [r1]
	strh r0, [r1]
	bx lr
.L080ED908: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080ED90C
sub_080ED90C: @ 0x080ED90C
.L080ED90C:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080ED91C
	ldr r2, [r1]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bx lr
.L080ED91C: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080ED920
sub_080ED920: @ 0x080ED920
.L080ED920:
	ldr r1, .L080ED928
	ldr r1, [r1]
	strh r0, [r1, #2]
	bx lr
.L080ED928: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080ED92C
sub_080ED92C: @ 0x080ED92C
.L080ED92C:
	ldr r0, .L080ED934
	ldr r0, [r0]
	ldrh r0, [r0, #2]
	bx lr
.L080ED934: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080ED938
sub_080ED938: @ 0x080ED938
.L080ED938:
	ldr r1, .L080ED940
	ldr r1, [r1]
	strh r0, [r1, #6]
	bx lr
.L080ED940: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080ED944
sub_080ED944: @ 0x080ED944
	ldr r0, .L080ED950
	ldr r0, [r0]
	movs r1, #0x28
	ldrsh r0, [r0, r1]
	bx lr
	.byte 0x00, 0x00
.L080ED950: .4byte 0x03006438 @ IWRAM+0x6438

	thumb_func_start sub_080ED954
sub_080ED954: @ 0x080ED954
.L080ED954:
	push {lr}
	ldr r0, .L080ED968
	ldr r0, [r0]
	movs r1, #6
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080ED96C
	movs r0, #0
	b .L080ED96E
	.byte 0x00, 0x00
.L080ED968: .4byte 0x03006434 @ IWRAM+0x6434
.L080ED96C:
	movs r0, #1
.L080ED96E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080ED974
sub_080ED974: @ 0x080ED974
.L080ED974:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080ED954
	cmp r0, #0
	beq .L080ED988
	cmp r4, #0x13
	ble .L080ED988
	movs r0, #1
	b .L080ED98A
.L080ED988:
	movs r0, #0
.L080ED98A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080ED990
sub_080ED990: @ 0x080ED990
.L080ED990:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080ED954
	cmp r0, #0
	beq .L080ED9A4
	cmp r4, #1
	bne .L080ED9A4
	movs r0, #0x14
	b .L080ED9A6
.L080ED9A4:
	movs r0, #0x10
.L080ED9A6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080ED9AC
sub_080ED9AC: @ 0x080ED9AC
.L080ED9AC:
	push {r4, r5, r6, lr}
	ldr r2, .L080ED9EC
	movs r4, #0
	adds r3, r0, #0
	adds r1, r3, r1
	cmp r3, r1
	bge .L080ED9E2
	movs r5, #0x80
	lsls r5, r5, #8
	lsls r0, r3, #7
	ldr r6, .L080ED9F0
	adds r0, r0, r6
	adds r2, r0, r2
	subs r3, r1, r3
.L080ED9C8:
	ldrh r0, [r2]
	cmp r0, #0
	beq .L080ED9DA
	ldrh r1, [r2, #2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne .L080ED9DA
	adds r4, #1
.L080ED9DA:
	adds r2, #0x80
	subs r3, #1
	cmp r3, #0
	bne .L080ED9C8
.L080ED9E2:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080ED9EC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ED9F0: .4byte 0x000009AE

	thumb_func_start sub_080ED9F4
sub_080ED9F4: @ 0x080ED9F4
.L080ED9F4:
	push {lr}
	movs r0, #0
	movs r1, #8
	bl sub_080ED9AC
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EDA04
sub_080EDA04: @ 0x080EDA04
.L080EDA04:
	push {r4, lr}
	movs r4, #0x10
.L080EDA08:
	adds r0, r4, #0
	movs r1, #0x80
	lsls r1, r1, #8
	bl sub_080C08F8
	adds r0, r4, #0
	bl sub_080F4104
	adds r4, #1
	cmp r4, #0x17
	ble .L080EDA08
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080EDA24
sub_080EDA24: @ 0x080EDA24
.L080EDA24:
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	bl sub_080ED954
	cmp r0, #0
	beq .L080EDA3C
	movs r1, #4
	cmp r4, #1
	bne .L080EDA3E
	movs r5, #4
	b .L080EDA3E
.L080EDA3C:
	movs r1, #8
.L080EDA3E:
	adds r0, r5, #0
	bl sub_080ED9AC
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EDA4C
sub_080EDA4C: @ 0x080EDA4C
.L080EDA4C:
	ldr r2, .L080EDA60
	ldr r2, [r2]
	lsls r0, r0, #2
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r2, r2, r3
	adds r2, r2, r0
	str r1, [r2]
	bx lr
	.byte 0x00, 0x00
.L080EDA60: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EDA64
sub_080EDA64: @ 0x080EDA64
.L080EDA64:
	ldr r1, .L080EDA78
	ldr r1, [r1]
	lsls r0, r0, #2
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080EDA78: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EDA7C
sub_080EDA7C: @ 0x080EDA7C
.L080EDA7C:
	ldr r1, .L080EDA8C
	ldr r1, [r1]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080EDA8C: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EDA90
sub_080EDA90: @ 0x080EDA90
.L080EDA90:
	ldr r0, .L080EDAA0
	ldr r0, [r0]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080EDAA0: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EDAA4
sub_080EDAA4: @ 0x080EDAA4
	ldr r1, .L080EDAB4
	ldr r1, [r1]
	movs r2, #0xad
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080EDAB4: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EDAB8
sub_080EDAB8: @ 0x080EDAB8
	ldr r1, .L080EDACC
	ldr r1, [r1]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080EDACC: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EDAD0
sub_080EDAD0: @ 0x080EDAD0
.L080EDAD0:
	push {lr}
	movs r0, #0x10
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	bgt .L080EDAE4
	movs r0, #0
	b .L080EDAE6
.L080EDAE4:
	movs r0, #1
.L080EDAE6:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EDAEC
sub_080EDAEC: @ 0x080EDAEC
.L080EDAEC:
	push {lr}
	movs r1, #0
	ldr r2, .L080EDB00
	adds r0, r0, r2
	cmp r0, #4
	bhi .L080EDAFA
	movs r1, #1
.L080EDAFA:
	adds r0, r1, #0
	pop {r1}
	bx r1
.L080EDB00: .4byte 0xFFFFFED0

	thumb_func_start sub_080EDB04
sub_080EDB04: @ 0x080EDB04
.L080EDB04:
	push {lr}
	sub sp, #0x10
	ldr r1, .L080EDB28
	mov r0, sp
	movs r2, #0x10
	bl memcpy
	bl sub_080C1D9C
	lsrs r0, r0, #4
	movs r1, #0xf
	ands r0, r1
	.2byte 0x4468 @ add r0, sp, r0
	ldrb r0, [r0]
	add sp, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080EDB28: .4byte gUnknown_0876F6B4

	thumb_func_start sub_080EDB2C
sub_080EDB2C: @ 0x080EDB2C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r1, #1
	lsls r1, r3
	bics r0, r1
	cmp r0, #0
	beq .L080EDB62
	movs r1, #1
	movs r5, #1
	b .L080EDB44
.L080EDB42:
	adds r1, #1
.L080EDB44:
	cmp r1, #0x1f
	bhi .L080EDB62
	adds r3, r3, r2
	cmp r3, #0x1f
	ble .L080EDB52
	movs r3, #0
	b .L080EDB58
.L080EDB52:
	cmp r3, #0
	bge .L080EDB58
	movs r3, #0x1f
.L080EDB58:
	adds r0, r5, #0
	lsls r0, r3
	ands r0, r4
	cmp r0, #0
	beq .L080EDB42
.L080EDB62:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EDB6C
sub_080EDB6C: @ 0x080EDB6C
.L080EDB6C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r2, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov ip, r1
	adds r3, r4, #1
	cmp r3, ip
	bge .L080EDBC0
.L080EDB84:
	lsls r0, r3, #2
	adds r0, r0, r5
	ldr r1, [r0]
	mov r8, r1
	movs r7, #2
	ldrsh r2, [r0, r7]
	subs r1, r3, #1
	adds r6, r3, #1
	cmp r1, r4
	blt .L080EDBB2
	lsls r0, r1, #2
	adds r3, r0, r5
	b .L080EDBAA
.L080EDB9E:
	ldr r0, [r3]
	str r0, [r3, #4]
	subs r3, #4
	subs r1, #1
	cmp r1, r4
	blt .L080EDBB2
.L080EDBAA:
	movs r7, #2
	ldrsh r0, [r3, r7]
	cmp r0, r2
	bgt .L080EDB9E
.L080EDBB2:
	lsls r0, r1, #2
	adds r0, r0, r5
	mov r1, r8
	str r1, [r0, #4]
	adds r3, r6, #0
	cmp r3, ip
	blt .L080EDB84
.L080EDBC0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080EDBCC
sub_080EDBCC: @ 0x080EDBCC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x88
	mov sb, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x80]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	str r0, [sp, #0x84]
	adds r1, r0, #0
	add r1, sl
	subs r1, #1
	lsls r1, r1, #0x10
	movs r0, #0
	mov r8, r0
	lsrs r2, r1, #0x10
	mov ip, r2
	asrs r1, r1, #0x10
	ldr r3, [sp, #0x84]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	cmp r1, #0xa
	bgt .L080EDC22
	b .L080EDD00
.L080EDC08:
	movs r7, #1
	rsbs r7, r7, #0
	add r8, r7
	add r0, sp, #0x40
	mov r2, r8
	lsls r1, r2, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	str r0, [sp, #0x84]
	mov r3, sp
	adds r0, r3, r1
	ldrh r0, [r0]
	mov ip, r0
.L080EDC22:
	ldr r7, [sp, #0x84]
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	mov r0, ip
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	adds r0, r3, r2
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	lsls r0, r0, #2
	add r0, sb
	movs r1, #2
	ldrsh r6, [r0, r1]
	subs r4, r3, #1
	adds r5, r2, #1
	lsls r0, r5, #2
	mov r2, sb
	adds r3, r0, r2
	lsls r0, r4, #2
	adds r2, r0, r2
	b .L080EDC56
.L080EDC4E:
	ldr r1, [r2]
	ldr r0, [r3]
	str r0, [r2]
	str r1, [r3]
.L080EDC56:
	adds r2, #4
	adds r4, #1
	movs r7, #2
	ldrsh r0, [r2, r7]
	cmp r0, r6
	ble .L080EDC74
	lsls r1, r4, #2
	add r1, sb
.L080EDC66:
	adds r1, #4
	adds r2, #4
	adds r4, #1
	movs r7, #2
	ldrsh r0, [r1, r7]
	cmp r0, r6
	bgt .L080EDC66
.L080EDC74:
	lsls r1, r5, #2
	add r1, sb
.L080EDC78:
	subs r1, #4
	subs r3, #4
	subs r5, #1
	movs r7, #2
	ldrsh r0, [r1, r7]
	cmp r0, r6
	blt .L080EDC78
	cmp r4, r5
	blo .L080EDC4E
	ldr r1, [sp, #0x84]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	subs r1, r4, r0
	mov r2, ip
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r0, r0, r5
	cmp r1, r0
	bls .L080EDCC4
	cmp r1, #0xa
	bls .L080EDCBA
	add r0, sp, #0x40
	mov r3, r8
	lsls r1, r3, #1
	adds r0, r0, r1
	add r7, sp, #0x84
	ldrh r7, [r7]
	strh r7, [r0]
	.2byte 0x4469 @ add r1, sp, r1
	subs r0, r4, #1
	strh r0, [r1]
	movs r0, #1
	add r8, r0
.L080EDCBA:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x84]
	b .L080EDCE8
.L080EDCC4:
	cmp r0, #0xa
	bls .L080EDCE0
	add r1, sp, #0x40
	mov r3, r8
	lsls r2, r3, #1
	adds r1, r1, r2
	adds r0, r5, #1
	strh r0, [r1]
	mov r7, sp
	adds r0, r7, r2
	mov r1, ip
	strh r1, [r0]
	movs r2, #1
	add r8, r2
.L080EDCE0:
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
.L080EDCE8:
	mov r3, ip
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	ldr r7, [sp, #0x84]
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	cmp r1, #0xa
	bgt .L080EDC22
	mov r0, r8
	cmp r0, #0
	bne .L080EDC08
.L080EDD00:
	ldr r0, [sp, #0x80]
	mov r1, sl
	mov r2, sb
	bl sub_080EDB6C
	add sp, #0x88
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080EDD1C
sub_080EDD1C: @ 0x080EDD1C
.L080EDD1C:
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, .L080EDD88
	adds r0, r6, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	adds r0, r6, #0
	bl sub_080C35E4
	adds r7, r0, #0
	adds r0, r4, #0
	adds r0, #0x44
	movs r5, #0
	ldrsb r5, [r0, r5]
	ldrh r1, [r4, #0x10]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L080EDD4C
	movs r5, #0x3c
.L080EDD4C:
	movs r4, #0
	cmp r6, #0xf
	bgt .L080EDD66
	adds r0, r6, #0
	bl sub_080BFFF0
	cmp r0, #0
	bne .L080EDD66
	adds r0, r5, #0
	movs r1, #2
	bl sub_080C1F94
	adds r4, r0, #0
.L080EDD66:
	bl sub_080C2244
	lsls r2, r5, #1
	adds r2, r2, r4
	movs r1, #0xf
	ands r1, r0
	adds r5, r2, r1
	cmp r7, #7
	bne .L080EDD80
	bl sub_080EDB04
	lsrs r0, r0, #1
	adds r5, r5, r0
.L080EDD80:
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080EDD88: .4byte 0xFFFF8000

	thumb_func_start sub_080EDD8C
sub_080EDD8C: @ 0x080EDD8C
.L080EDD8C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, .L080EDE5C
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r1, r1, r0
	mov r8, r1
	ldr r0, .L080EDE60
	ldr r0, [r0]
	movs r2, #0xc
	adds r2, r2, r0
	mov sl, r2
	mov r5, sl
	ldrh r1, [r0, #2]
	mov sb, r1
	movs r7, #0
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne .L080EDE06
	movs r0, #0xc0
	lsls r0, r0, #8
	cmp sb, r0
	beq .L080EDE06
	movs r6, #5
.L080EDDC8:
	mov r2, r8
	movs r4, #0
	ldrsb r4, [r2, r4]
	movs r0, #1
	add r8, r0
	subs r0, #2
	cmp r4, r0
	beq .L080EDE00
	ldr r1, .L080EDE64
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	ldrh r1, [r0, #0x10]
	ldr r2, .L080EDE68
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne .L080EDE00
	strh r4, [r5]
	adds r0, r4, #0
	bl sub_080EDD1C
	rsbs r0, r0, #0
	strh r0, [r5, #2]
	adds r5, #4
	adds r7, #1
.L080EDE00:
	subs r6, #1
	cmp r6, #0
	bge .L080EDDC8
.L080EDE06:
	movs r0, #0x80
	lsls r0, r0, #8
	cmp sb, r0
	beq .L080EDE3E
	movs r6, #0x10
.L080EDE10:
	ldr r1, .L080EDE64
	adds r0, r6, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	beq .L080EDE38
	adds r0, r6, #0
	bl sub_080EDD1C
	strh r6, [r5]
	adds r0, r6, #0
	bl sub_080EDD1C
	rsbs r0, r0, #0
	strh r0, [r5, #2]
	adds r5, #4
	adds r7, #1
.L080EDE38:
	adds r6, #1
	cmp r6, #0x17
	ble .L080EDE10
.L080EDE3E:
	ldr r0, .L080EDE6C
	strh r0, [r5]
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	mov r2, sl
	bl sub_080EDB6C
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080EDE5C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080EDE60: .4byte 0x03006434 @ IWRAM+0x6434
.L080EDE64: .4byte 0xFFFF8000
.L080EDE68: .4byte 0x0000B160
.L080EDE6C: .4byte 0x0000FFFF

	thumb_func_start sub_080EDE70
sub_080EDE70: @ 0x080EDE70
.L080EDE70:
	push {r4, r5, r6, lr}
	bl sub_080F3F44
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0
	bne .L080EDF02
	bl sub_080EDB04
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #5
	bl sub_080F43A4
	adds r6, r0, #0
	movs r0, #4
	bl sub_080F43A4
	lsrs r1, r6, #0x1f
	adds r6, r6, r1
	asrs r6, r6, #1
	adds r6, r6, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r6, r6, r4
	movs r0, #5
	bl sub_080F43E0
	adds r5, r0, #0
	movs r0, #4
	bl sub_080F43E0
	lsrs r1, r5, #0x1f
	adds r5, r5, r1
	asrs r5, r5, #1
	adds r5, r5, r0
	movs r0, #0xf
	eors r4, r0
	subs r4, #7
	movs r0, #0xff
	ands r4, r0
	adds r5, r5, r4
	subs r6, r6, r5
	lsls r6, r6, #0x10
	asrs r4, r6, #0x10
	ldr r1, .L080EDEF4
	lsrs r6, r6, #0x10
	ands r6, r1
	adds r0, r6, #0
	cmp r0, #0
	beq .L080EDEF0
	cmp r4, #0
	bge .L080EDEE0
	eors r0, r1
	adds r6, r0, #1
.L080EDEE0:
	bl sub_080C2244
	movs r1, #0x3f
	ands r1, r0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	blo .L080EDEF8
.L080EDEF0:
	movs r0, #0
	b .L080EDF06
.L080EDEF4: .4byte 0x00007FFF
.L080EDEF8:
	cmp r4, #0
	bge .L080EDF02
	movs r0, #0xc0
	lsls r0, r0, #8
	b .L080EDF06
.L080EDF02:
	movs r0, #0x80
	lsls r0, r0, #8
.L080EDF06:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_080EDF0C
sub_080EDF0C: @ 0x080EDF0C
.L080EDF0C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl sub_080EDAD0
	cmp r0, #0
	bne .L080EE00A
	bl sub_080ED8F4
	movs r1, #0x80
	lsls r1, r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L080EE00A
	movs r0, #0xb3
	lsls r0, r0, #1
	bl Flag_Test
	cmp r0, #0
	bne .L080EE00A
	ldr r0, .L080EDF5C
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080EDF60
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #1
	bne .L080EDF60
	movs r0, #0xa3
	lsls r0, r0, #1
	b .L080EE018
	.byte 0x00, 0x00
.L080EDF5C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080EDF60:
	bl sub_080ED92C
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	beq .L080EE014
	movs r0, #0
	mov r8, r0
	mov sb, r0
	movs r6, #0
	ldr r1, .L080EDFB8
	mov sl, r1
.L080EDF78:
	mov r1, sl
	adds r0, r6, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	cmp r5, #0
	blt .L080EDFAC
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080EDFAC
	movs r0, #1
	add r8, r0
	adds r0, r5, #0
	bl sub_080C0DFC
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080C0E20
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r0
	add sb, r4
.L080EDFAC:
	adds r6, #1
	cmp r6, #5
	ble .L080EDF78
	movs r6, #0
	b .L080EDFBE
	.byte 0x00, 0x00
.L080EDFB8: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080EDFBC:
	adds r6, #1
.L080EDFBE:
	cmp r6, #7
	bgt .L080EDFEA
	adds r4, r6, #0
	adds r4, #0x10
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080EDFBC
	adds r5, r4, #0
	adds r0, r5, #0
	bl sub_080C0DFC
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080C0E20
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r7, r4, r0
.L080EDFEA:
	mov r1, r8
	muls r1, r7, r1
	adds r7, r1, #0
	bl sub_080C2244
	movs r1, #7
	ands r1, r0
	adds r7, r7, r1
	cmp r7, sb
	blt .L080EE014
	bl sub_080C2244
	movs r1, #0xf
	ands r1, r0
	cmp r1, #0
	beq .L080EE014
.L080EE00A:
	ldr r0, .L080EE010
	b .L080EE018
	.byte 0x00, 0x00
.L080EE010: .4byte 0x00000145
.L080EE014:
	movs r0, #0xa2
	lsls r0, r0, #1
.L080EE018:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EE028
sub_080EE028: @ 0x080EE028
.L080EE028:
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, .L080EE09C
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	cmp r2, #0
	beq .L080EE104
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq .L080EE0FA
	ldr r0, .L080EE0A0
	adds r5, r0, #0
	adds r0, r1, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	ldrh r1, [r4, #0x10]
	ldr r0, .L080EE0A4
	ands r0, r1
	cmp r0, #0
	bne .L080EE0FA
	adds r0, r6, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r1, r0, #0
	movs r3, #0x17
	ldrsb r3, [r1, r3]
	cmp r3, #8
	beq .L080EE0FA
	cmp r3, #0xb
	beq .L080EE07A
	cmp r3, #7
	bne .L080EE0A8
.L080EE07A:
	adds r0, r4, #0
	adds r0, #0x41
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	subs r0, #1
	adds r1, #0x56
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	adds r0, #0x10
	lsls r4, r0, #1
	cmp r4, #0xff
	bgt .L080EE0FA
	b .L080EE0F2
	.byte 0x00, 0x00
.L080EE09C: .4byte 0x03006434 @ IWRAM+0x6434
.L080EE0A0: .4byte 0xFFFF8000
.L080EE0A4: .4byte 0x00003160
.L080EE0A8:
	adds r0, r4, #0
	adds r0, #0x52
	movs r2, #0
	ldrsh r4, [r0, r2]
	cmp r3, #4
	beq .L080EE0B8
	cmp r3, #0xa
	bne .L080EE0C2
.L080EE0B8:
	adds r0, r1, #0
	adds r0, #0x4a
	movs r1, #0
	ldrsh r0, [r0, r1]
	b .L080EE0CA
.L080EE0C2:
	adds r0, r1, #0
	adds r0, #0x4e
	movs r2, #0
	ldrsh r0, [r0, r2]
.L080EE0CA:
	subs r4, r4, r0
	adds r4, #0x10
	cmp r4, #0
	blt .L080EE0FA
	adds r0, r4, #0
	muls r0, r4, r0
	adds r4, r0, #0
	asrs r4, r4, #5
	adds r0, r6, #0
	bl sub_080EFD84
	adds r0, #4
	lsls r2, r4, #3
	ldr r1, .L080EE100
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	bl __divsi3
	adds r4, r0, #0
.L080EE0F2:
	bl sub_080C2244
	cmp r0, r4
	ble .L080EE104
.L080EE0FA:
	movs r0, #1
	b .L080EE106
	.byte 0x00, 0x00
.L080EE100: .4byte gUnknown_0876F78E
.L080EE104:
	movs r0, #0
.L080EE106:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_080EE10C
sub_080EE10C: @ 0x080EE10C
.L080EE10C:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r0, .L080EE238
	ldr r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r7, [r0]
	movs r0, #0
	mov r8, r0
	subs r2, #0x2c
	adds r1, r1, r2
	ldr r0, .L080EE23C
	strh r0, [r1]
	ldr r1, .L080EE240
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	movs r0, #0x17
	ldrsb r0, [r4, r0]
	cmp r0, #0xb
	bne .L080EE1F4
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	cmp r0, #0x5c
	bne .L080EE1F4
	movs r6, #0
.L080EE150:
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	cmp r4, #0
	beq .L080EE18C
	adds r0, r6, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080EE18C
	ldrb r1, [r4, #0xc]
	adds r0, r5, #0
	bl sub_080F55F4
	cmp r0, #0
	bne .L080EE18C
	ldr r0, .L080EE238
	ldr r1, [r0]
	mov r2, r8
	lsls r0, r2, #2
	adds r1, r1, r0
	ldrb r0, [r4, #0xc]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
	movs r0, #1
	add r8, r0
.L080EE18C:
	adds r6, #1
	cmp r6, #5
	ble .L080EE150
	movs r6, #0x10
.L080EE194:
	ldr r1, .L080EE240
	adds r0, r6, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r0, r6, #0
	bl sub_080C09B0
	cmp r0, #1
	bne .L080EE1D6
	adds r0, r6, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080EE1D6
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_080F55F4
	cmp r0, #0
	bne .L080EE1D6
	ldr r0, .L080EE238
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, #2
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r6, [r0]
	movs r2, #1
	add r8, r2
.L080EE1D6:
	adds r6, #1
	cmp r6, #0x17
	ble .L080EE194
	ldr r0, .L080EE238
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, #2
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, .L080EE23C
	strh r1, [r0]
	cmp r2, #0
	bne .L080EE2D2
.L080EE1F4:
	adds r0, r7, #1
	cmp r0, #1
	bls .L080EE2D2
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r7, r0
	bne .L080EE244
	movs r6, #0
.L080EE204:
	adds r0, r6, #0
	bl sub_080F40EC
	adds r5, r0, #0
	cmp r5, #0
	blt .L080EE22E
	bl sub_080C0830
	cmp r0, #0
	bne .L080EE22E
	ldr r0, .L080EE238
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, #2
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r5, [r0]
	movs r2, #1
	add r8, r2
.L080EE22E:
	adds r6, #1
	cmp r6, #5
	ble .L080EE204
	b .L080EE2BE
	.byte 0x00, 0x00
.L080EE238: .4byte 0x03006434 @ IWRAM+0x6434
.L080EE23C: .4byte 0x0000FFFF
.L080EE240: .4byte 0xFFFF8000
.L080EE244:
	movs r6, #0
.L080EE246:
	adds r0, r6, #0
	bl sub_080F40EC
	adds r5, r0, #0
	cmp r5, #0
	blt .L080EE2A2
	bl sub_080C0830
	cmp r0, #0
	bne .L080EE2A2
	ldr r0, .L080EE2E0
	mov sb, r0
	ldr r0, [r0]
	mov r1, r8
	lsls r7, r1, #2
	adds r0, r0, r7
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r5, [r0]
	bl sub_080C2244
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080BFFF0
	cmp r0, #1
	bne .L080EE28E
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r0, r1, #4
	subs r0, r0, r1
	movs r1, #0x64
	bl __divsi3
	adds r4, r0, #0
.L080EE28E:
	mov r1, sb
	ldr r0, [r1]
	adds r0, r0, r7
	rsbs r1, r4, #0
	movs r2, #0x99
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r1, [r0]
	movs r0, #1
	add r8, r0
.L080EE2A2:
	adds r6, #1
	cmp r6, #5
	ble .L080EE246
	mov r2, r8
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	ldr r0, .L080EE2E0
	ldr r2, [r0]
	movs r0, #0x98
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #0
	bl sub_080EDB6C
.L080EE2BE:
	ldr r0, .L080EE2E0
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, #2
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, .L080EE2E4
	strh r1, [r0]
.L080EE2D2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EE2E0: .4byte 0x03006434 @ IWRAM+0x6434
.L080EE2E4: .4byte 0x0000FFFF

	thumb_func_start sub_080EE2E8
sub_080EE2E8: @ 0x080EE2E8
.L080EE2E8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	ldr r0, .L080EE4DC
	ldr r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r6, [r0]
	movs r7, #0
	movs r4, #0x98
	lsls r4, r4, #1
	adds r1, r1, r4
	ldr r0, .L080EE4E0
	strh r0, [r1]
	ldr r1, [sp]
	ldr r2, .L080EE4E4
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r4, r0, #0
	movs r0, #0x17
	ldrsb r0, [r4, r0]
	cmp r0, #0xb
	bne .L080EE3D0
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	cmp r0, #0x5c
	bne .L080EE3D0
	movs r5, #0
.L080EE332:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	cmp r4, #0
	beq .L080EE36A
	ldrb r0, [r4, #0xc]
	bl sub_080C0830
	cmp r0, #0
	bne .L080EE36A
	ldrb r1, [r4, #0xc]
	ldr r0, [sp]
	bl sub_080F55F4
	cmp r0, #0
	bne .L080EE36A
	ldr r0, .L080EE4DC
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r1, r1, r0
	ldrb r0, [r4, #0xc]
	movs r4, #0x98
	lsls r4, r4, #1
	adds r1, r1, r4
	strh r0, [r1]
	adds r7, #1
.L080EE36A:
	adds r5, #1
	cmp r5, #5
	ble .L080EE332
	movs r5, #0x10
.L080EE372:
	ldr r1, .L080EE4E4
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080C09B0
	cmp r0, #1
	bne .L080EE3B2
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080EE3B2
	ldr r0, [sp]
	adds r1, r5, #0
	bl sub_080F55F4
	cmp r0, #0
	bne .L080EE3B2
	ldr r0, .L080EE4DC
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, r0, r1
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r5, [r0]
	adds r7, #1
.L080EE3B2:
	adds r5, #1
	cmp r5, #0x17
	ble .L080EE372
	ldr r0, .L080EE4DC
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, .L080EE4E0
	strh r1, [r0]
	cmp r7, #0
	beq .L080EE3D0
	b .L080EE69E
.L080EE3D0:
	movs r0, #0x17
	ldrsb r0, [r4, r0]
	cmp r0, #8
	bne .L080EE44A
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	adds r0, #0xf
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi .L080EE44A
	movs r5, #0
.L080EE3EA:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	cmp r4, #0
	beq .L080EE424
	ldrb r0, [r4, #0xc]
	bl sub_080C0830
	cmp r0, #0
	bne .L080EE424
	ldrh r0, [r4, #0x10]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	bne .L080EE424
	ldr r0, .L080EE4DC
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r1, r1, r0
	ldrb r0, [r4, #0xc]
	movs r4, #0x98
	lsls r4, r4, #1
	adds r1, r1, r4
	strh r0, [r1]
	adds r7, #1
.L080EE424:
	adds r5, #1
	cmp r5, #5
	ble .L080EE3EA
	ldr r0, .L080EE4DC
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r0, r2
	str r7, [r1]
	lsls r1, r7, #2
	adds r0, r0, r1
	movs r4, #0x98
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r1, .L080EE4E0
	strh r1, [r0]
	cmp r7, #0
	beq .L080EE44A
	b .L080EE69E
.L080EE44A:
	adds r0, r6, #1
	cmp r0, #1
	bhi .L080EE452
	b .L080EE69E
.L080EE452:
	ldr r0, .L080EE4DC
	mov r8, r0
	ldr r0, [r0]
	ldr r2, [sp]
	lsls r1, r2, #2
	movs r4, #0xb0
	lsls r4, r4, #1
	adds r0, r0, r4
	adds r0, r0, r1
	ldr r0, [r0]
	bl sub_080ED974
	adds r4, r0, #0
	bl sub_080EDA24
	cmp r0, #0
	bne .L080EE478
	movs r0, #1
	eors r4, r0
.L080EE478:
	adds r0, r4, #0
	bl sub_080ED990
	mov sl, r0
	mov r5, sl
	subs r5, #0x10
	bl sub_080ED954
	movs r1, #8
	str r1, [sp, #4]
	cmp r0, #0
	beq .L080EE494
	movs r2, #4
	str r2, [sp, #4]
.L080EE494:
	adds r0, r4, #0
	bl sub_080EDA24
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r6, r0
	bne .L080EE4EC
	movs r4, #0x10
	mov sl, r4
	movs r5, #0x10
	ldr r0, .L080EE4E8
	movs r1, #0x9a
	lsls r1, r1, #4
	adds r2, r0, r1
	mov r4, r8
	movs r3, #0x98
	lsls r3, r3, #1
.L080EE4B6:
	ldrh r1, [r2, #0x10]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne .L080EE4CC
	ldr r0, [r4]
	lsls r1, r7, #2
	adds r0, r0, r1
	adds r0, r0, r3
	strh r5, [r0]
	adds r7, #1
.L080EE4CC:
	adds r2, #0x80
	adds r5, #1
	mov r0, sl
	adds r0, #8
	cmp r5, r0
	blt .L080EE4B6
	b .L080EE68C
	.byte 0x00, 0x00
.L080EE4DC: .4byte 0x03006434 @ IWRAM+0x6434
.L080EE4E0: .4byte 0x0000FFFF
.L080EE4E4: .4byte 0xFFFF8000
.L080EE4E8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EE4EC:
	ldr r2, [sp]
	ldr r4, .L080EE570
	adds r0, r2, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r4, r0, #0
	adds r4, #0x40
	lsls r6, r5, #7
	ldr r1, .L080EE574
	adds r0, r6, r1
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r2, r2, r0
	mov r8, r2
	movs r0, #4
	ldrsb r0, [r4, r0]
	movs r1, #2
	bl sub_080C1F94
	adds r5, r0, #0
	movs r0, #5
	ldrsb r0, [r4, r0]
	movs r1, #4
	bl sub_080C1F94
	movs r1, #1
	ldrsb r1, [r4, r1]
	lsls r1, r1, #1
	adds r1, r1, r5
	adds r1, r1, r0
	mov sb, r1
	ldr r4, [sp]
	cmp r4, #3
	ble .L080EE578
	bl sub_080C2244
	movs r6, #7
	ands r0, r6
	add sb, r0
	mov r1, r8
	movs r0, #4
	ldrsb r0, [r1, r0]
	movs r1, #2
	bl sub_080C1F94
	adds r5, r0, #0
	mov r2, r8
	movs r0, #5
	ldrsb r0, [r2, r0]
	movs r1, #4
	bl sub_080C1F94
	adds r4, r0, #0
	bl sub_080C2244
	mov r2, r8
	movs r1, #1
	ldrsb r1, [r2, r1]
	lsls r1, r1, #1
	adds r1, r1, r5
	adds r1, r1, r4
	ands r0, r6
	adds r0, r1, r0
	b .L080EE592
.L080EE570: .4byte 0xFFFF8000
.L080EE574: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EE578:
	bl sub_080C2244
	ldr r4, .L080EE5C4
	adds r1, r4, r6
	ldr r2, .L080EE5C8
	adds r1, r1, r2
	ldrb r2, [r1]
	lsrs r2, r2, #1
	movs r1, #0xf
	ands r1, r0
	adds r2, r2, r1
	adds r0, r2, #0
	adds r0, #0xe
.L080EE592:
	cmp r0, sb
	bge .L080EE61C
	mov r5, sl
	ldr r4, [sp, #4]
	adds r0, r5, r4
	ldr r1, .L080EE5CC
	mov r8, r1
	cmp r5, r0
	bge .L080EE678
	ldr r3, .L080EE5D0
	ldrh r6, [r3]
.L080EE5A8:
	lsls r0, r5, #7
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r1, .L080EE5C4
	adds r4, r1, r0
	ldrh r1, [r4, #0x10]
	adds r2, r1, #0
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne .L080EE5D4
	movs r2, #0
	b .L080EE5EE
.L080EE5C4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EE5C8: .4byte 0x000009AD
.L080EE5CC: .4byte 0x03006434 @ IWRAM+0x6434
.L080EE5D0: .4byte gUnknown_0876F6C4
.L080EE5D4:
	ldrh r0, [r3, #2]
	ands r1, r0
	cmp r1, #0
	bne .L080EE5E4
	ldr r2, .L080EE5E0
	b .L080EE5EE
.L080EE5E0: .4byte 0x00002706
.L080EE5E4:
	ldrh r0, [r3, #4]
	ands r2, r0
	cmp r2, #0
	bne .L080EE60C
	ldr r2, .L080EE618
.L080EE5EE:
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	adds r2, r2, r0
	mov r4, r8
	ldr r1, [r4]
	lsls r0, r7, #2
	adds r1, r1, r0
	movs r4, #0x98
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r5, [r0]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	adds r7, #1
.L080EE60C:
	adds r5, #1
	ldr r0, [sp, #4]
	add r0, sl
	cmp r5, r0
	blt .L080EE5A8
	b .L080EE678
.L080EE618: .4byte 0x00004E0C
.L080EE61C:
	mov r5, sl
	ldr r1, [sp, #4]
	adds r0, r5, r1
	cmp r5, r0
	bge .L080EE678
	ldr r2, .L080EE6B0
	mov r8, r2
	lsls r0, r5, #7
	movs r4, #0xd0
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r1, .L080EE6B4
	adds r6, r0, r1
.L080EE636:
	ldrh r0, [r6, #0x10]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	bne .L080EE66C
	mov r4, r8
	ldr r0, [r4]
	lsls r4, r7, #2
	adds r0, r0, r4
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r5, [r0]
	bl sub_080C2244
	bl sub_080C2244
	mov r2, r8
	ldr r1, [r2]
	adds r1, r1, r4
	movs r4, #0x99
	lsls r4, r4, #1
	adds r1, r1, r4
	strh r0, [r1]
	adds r7, #1
.L080EE66C:
	adds r6, #0x80
	adds r5, #1
	ldr r0, [sp, #4]
	add r0, sl
	cmp r5, r0
	blt .L080EE636
.L080EE678:
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	ldr r0, .L080EE6B0
	ldr r2, [r0]
	movs r0, #0x98
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #0
	bl sub_080EDB6C
.L080EE68C:
	ldr r0, .L080EE6B0
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, .L080EE6B8
	strh r1, [r0]
.L080EE69E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EE6B0: .4byte 0x03006434 @ IWRAM+0x6434
.L080EE6B4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EE6B8: .4byte 0x0000FFFF

	thumb_func_start sub_080EE6BC
sub_080EE6BC: @ 0x080EE6BC
.L080EE6BC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	mov r8, r1
	adds r5, r2, #0
	bl sub_080EDB04
	adds r4, r0, #0
	ldr r7, .L080EE6EC
	ldr r0, .L080EE6F0
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x12
	ldrsh r0, [r6, r1]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080EE6F4
	movs r2, #0
	b .L080EE700
	.byte 0x00, 0x00
.L080EE6EC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EE6F0: .4byte 0x000011B0
.L080EE6F4:
	ldrh r0, [r6, #0x12]
	bl sub_080BF648
	ldrb r0, [r0, #0xd]
	movs r2, #0xf
	ands r2, r0
.L080EE700:
	ldr r1, .L080EE750
	lsls r0, r2, #3
	adds r0, r0, r2
	adds r0, r0, r4
	adds r0, r0, r1
	ldrb r0, [r0]
	muls r0, r5, r0
	lsls r0, r0, #0xc
	lsrs r5, r0, #0x10
	adds r1, r4, #0
	movs r0, #0x12
	ldrsh r2, [r6, r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r2, r0
	cmp r2, #0
	bne .L080EE726
	movs r0, #8
	subs r1, r0, r1
.L080EE726:
	lsls r4, r1, #1
	adds r0, r6, #0
	adds r0, #0x45
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r4, r0
	adds r0, r6, #0
	adds r0, #0x44
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r4, r0
	cmp r2, #0
	bne .L080EE754
	ldrh r0, [r6, #0x12]
	bl sub_080BF648
	ldrb r1, [r0, #0x18]
	b .L080EE756
	.byte 0x00, 0x00
.L080EE750: .4byte gUnknown_0876F6CA
.L080EE754:
	movs r1, #0
.L080EE756:
	lsls r0, r1, #3
	adds r4, r4, r0
	ldrb r1, [r6, #0x17]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls .L080EE780
	cmp r1, #0xa
	beq .L080EE780
	movs r0, #0x17
	ldrsb r0, [r6, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	adds r1, #0x5c
	ldrb r1, [r1]
	bl sub_080EED64
	cmp r0, #1
	bne .L080EE7B2
.L080EE780:
	bl sub_080C2244
	cmp r0, r4
	blo .L080EE7B2
	bl sub_080C2244
	adds r1, r0, #0
	cmp r1, #3
	bhi .L080EE7A4
	lsls r0, r5, #1
	adds r5, r0, r5
	ldr r0, .L080EE7A0
	adds r1, r7, r0
	movs r0, #1
	b .L080EE7B0
	.byte 0x00, 0x00
.L080EE7A0: .4byte 0x000011B0
.L080EE7A4:
	cmp r1, #0xf
	bhi .L080EE7B2
	lsls r5, r5, #1
	ldr r0, .L080EE80C
	adds r1, r7, r0
	movs r0, #2
.L080EE7B0:
	strh r0, [r1]
.L080EE7B2:
	mov r1, r8
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #9
	bne .L080EE7C2
	lsrs r0, r5, #0x1f
	adds r0, r5, r0
	asrs r5, r0, #1
.L080EE7C2:
	bl sub_080C2244
	movs r1, #0x1f
	ands r1, r0
	muls r1, r5, r1
	lsrs r4, r1, #7
	subs r1, r5, r4
	cmp r1, #0
	beq .L080EE7DE
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080EE7E8
.L080EE7DE:
	bl sub_080C2244
	adds r1, r0, #0
	movs r0, #1
	ands r1, r0
.L080EE7E8:
	adds r5, r1, #0
	cmp r5, #0
	bgt .L080EE7F0
	movs r5, #1
.L080EE7F0:
	mov r0, r8
	ldrh r1, [r0, #0x10]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	beq .L080EE800
	movs r5, #0
.L080EE800:
	adds r0, r5, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080EE80C: .4byte 0x000011B0

	thumb_func_start sub_080EE810
sub_080EE810: @ 0x080EE810
.L080EE810:
	push {r4, r5, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r2, #0
	ldr r3, .L080EE84C
.L080EE81C:
	lsls r1, r2, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, r4
	bne .L080EE850
	adds r0, r3, #2
	adds r0, r1, r0
	ldrh r1, [r0]
	adds r0, r5, #0
	bl sub_080F3F90
	adds r1, r0, #0
	subs r0, #0xc
	cmp r0, #1
	bls .L080EE85A
	adds r0, r1, #0
	subs r0, #0xe
	cmp r0, #1
	bls .L080EE85A
	cmp r1, #0
	beq .L080EE85A
	movs r0, #1
	b .L080EE85C
	.byte 0x00, 0x00
.L080EE84C: .4byte gUnknown_0876F75A
.L080EE850:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xb
	bls .L080EE81C
.L080EE85A:
	movs r0, #0
.L080EE85C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EE864
sub_080EE864: @ 0x080EE864
.L080EE864:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, .L080EE8A8
	adds r4, r0, #0
	adds r0, r7, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	mov r8, r0
	adds r4, r6, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	mov sl, r0
	mov r1, r8
	ldrb r1, [r1, #0x17]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sb, r1
	cmp r7, #3
	ble .L080EE8AC
	mov r0, r8
	adds r0, #0x48
	b .L080EE95A
	.byte 0x00, 0x00
.L080EE8A8: .4byte 0xFFFF8000
.L080EE8AC:
	mov r0, sb
	cmp r0, #4
	bne .L080EE910
	bl sub_080C2244
	cmp r0, #0x3f
	bhi .L080EE900
	adds r0, r7, #0
	movs r1, #0
	bl sub_080C00DC
	str r0, [sp]
	cmp r0, #0xff
	beq .L080EE900
	movs r1, #6
	mov r2, sp
	bl sub_080BF468
	ldr r1, [sp]
	lsls r1, r1, #0x10
	ldr r0, .L080EE90C
	ands r0, r1
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L080EE900
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080F3214
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080EE900
	adds r0, r4, #0
	adds r1, r6, #0
	bl sub_080EE810
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080EE900
	adds r0, r4, #0
	bl sub_080EDA7C
.L080EE900:
	mov r0, r8
	adds r0, #0x48
	movs r1, #0
	ldrsh r5, [r0, r1]
	b .L080EE95E
	.byte 0x00, 0x00
.L080EE90C: .4byte 0xFFFE0000
.L080EE910:
	bl sub_080C2244
	cmp r0, #0x3f
	bhi .L080EE956
	adds r0, r7, #0
	movs r1, #6
	bl sub_080C00DC
	str r0, [sp]
	cmp r0, #0xff
	beq .L080EE956
	movs r1, #6
	mov r2, sp
	bl sub_080BF468
	ldr r0, [sp]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080F3214
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080EE956
	adds r0, r4, #0
	adds r1, r6, #0
	bl sub_080EE810
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080EE956
	adds r0, r4, #0
	bl sub_080EDA7C
.L080EE956:
	mov r0, r8
	adds r0, #0x4c
.L080EE95A:
	movs r3, #0
	ldrsh r5, [r0, r3]
.L080EE95E:
	mov r0, r8
	ldrh r1, [r0, #0x10]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L080EE96C
	asrs r5, r5, #1
.L080EE96C:
	adds r0, r7, #0
	bl sub_080EFBFC
	adds r2, r0, #4
	ldr r4, .L080EE9F4
	adds r0, r2, r4
	ldrb r0, [r0]
	muls r0, r5, r0
	cmp r0, #0
	bge .L080EE982
	adds r0, #7
.L080EE982:
	asrs r5, r0, #3
	adds r0, r6, #0
	bl sub_080EFD3C
	adds r2, r0, #4
	mov r0, sl
	adds r0, #0x50
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r0, r2, r4
	ldrb r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	bge .L080EE9A0
	adds r0, #7
.L080EE9A0:
	asrs r4, r0, #3
	adds r0, r5, #0
	movs r1, #4
	bl sub_080C1F94
	adds r0, #4
	muls r5, r0, r5
	adds r0, r5, #0
	adds r1, r4, #0
	bl __divsi3
	adds r5, r0, #0
	mov r0, sb
	cmp r0, #0xb
	bne .L080EE9D8
	adds r0, r7, #0
	bl sub_080F3F14
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r0, [r0, #1]
	muls r0, r5, r0
	movs r1, #0x64
	bl __divsi3
	adds r5, r5, r0
.L080EE9D8:
	mov r0, r8
	mov r1, sl
	adds r2, r5, #0
	bl sub_080EE6BC
	adds r5, r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080EE9F4: .4byte gUnknown_0876F78E

	thumb_func_start sub_080EE9F8
sub_080EE9F8: @ 0x080EE9F8
.L080EE9F8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, [r7]
	mov r8, r0
	ldr r1, [r7, #4]
	mov sb, r1
	bl sub_080F3F14
	adds r6, r0, #0
	bl sub_080ED794
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r2, .L080EEA94
	adds r4, r2, #0
	mov r1, r8
	adds r0, r1, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	str r0, [sp, #4]
	add r4, sb
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	mov sl, r0
	adds r2, r6, #0
	subs r2, #0x9b
	str r2, [sp, #8]
	cmp r2, #1
	bls .L080EEA4C
	cmp r6, #0x67
	bgt .L080EEAF4
.L080EEA4C:
	mov r0, sl
	adds r0, #0x54
	ldrh r4, [r0]
	mov r0, sb
	bl sub_080EFDCC
	adds r1, r0, #4
	ldr r2, .L080EEA98
	adds r0, r1, r2
	ldrb r0, [r0]
	muls r0, r4, r0
	lsls r0, r0, #0xd
	lsrs r5, r0, #0x10
	mov r0, sl
	adds r0, #0x50
	ldrh r4, [r0]
	mov r0, sb
	bl sub_080EFD3C
	adds r1, r0, #4
	ldr r2, .L080EEA98
	adds r0, r1, r2
	ldrb r0, [r0]
	muls r0, r4, r0
	lsls r0, r0, #0xd
	lsrs r0, r0, #0x12
	adds r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [sp, #8]
	cmp r0, #1
	bhi .L080EEA9C
	ldr r0, [sp, #4]
	adds r0, #0x48
	b .L080EEAA0
	.byte 0x00, 0x00
.L080EEA94: .4byte 0xFFFF8000
.L080EEA98: .4byte gUnknown_0876F78E
.L080EEA9C:
	ldr r0, [sp, #4]
	adds r0, #0x54
.L080EEAA0:
	ldrh r4, [r0]
	mov r0, r8
	bl sub_080EFDCC
	adds r1, r0, #4
	ldr r0, .L080EEAF0
	adds r0, r1, r0
	ldrb r0, [r0]
	muls r0, r4, r0
	lsls r0, r0, #0xd
	lsrs r4, r0, #0x10
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r0, [r0, #1]
	muls r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r5, #0xff
	bls .L080EEACC
	movs r5, #0xff
.L080EEACC:
	adds r0, r4, #0
	adds r1, r5, #0
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r4
	cmp r0, #0
	beq .L080EEAE4
	movs r4, #0
.L080EEAE4:
	ldr r0, [sp, #4]
	mov r1, sl
	adds r2, r4, #0
	bl sub_080EE6BC
	b .L080EEAFC
.L080EEAF0: .4byte gUnknown_0876F78E
.L080EEAF4:
	mov r0, r8
	mov r1, sb
	bl sub_080EE864
.L080EEAFC:
	adds r4, r0, #0
	bl sub_080C2244
	cmp r0, #0x3f
	bhi .L080EEB28
	mov r0, sb
	ldr r1, [sp]
	bl sub_080F3214
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080EEB28
	ldr r0, [sp]
	mov r1, sb
	bl sub_080EE810
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080EEB28
	ldr r0, [sp]
	bl sub_080EDA7C
.L080EEB28:
	movs r5, #0
	adds r0, r6, #0
	subs r0, #0x5c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
.L080EEB34:
	ldr r0, .L080EEB8C
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r6, r0
	bne .L080EEB72
	str r4, [r7, #0x18]
	adds r0, r7, #0
	adds r1, r5, #0
	bl sub_080F49B4
	ldr r4, [r7, #0x18]
	mov r1, r8
	cmp r1, #1
	bls .L080EEB72
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x54
	beq .L080EEB72
	cmp r0, #0x55
	beq .L080EEB72
	cmp r0, #0x5e
	beq .L080EEB72
	cmp r0, #0x61
	beq .L080EEB72
	cmp r0, #0x98
	beq .L080EEB72
	cmp r0, #0x9b
	beq .L080EEB72
	cmp r0, #0x9c
	beq .L080EEB72
	ldr r4, .L080EEB90
.L080EEB72:
	adds r5, #1
	cmp r5, #0x1f
	bls .L080EEB34
	str r4, [r7, #0x18]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080EEB8C: .4byte gUnknown_0876F79E
.L080EEB90: .4byte 0x0000FFFF

	thumb_func_start sub_080EEB94
sub_080EEB94: @ 0x080EEB94
.L080EEB94:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov sl, r1
	movs r0, #0
	str r0, [sp]
	ldr r0, [r5]
	mov sb, r0
	ldr r7, [r5, #4]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #8]
	mov r0, sb
	bl sub_080C0D90
	adds r4, r0, #0
	mov r0, sl
	bl sub_080ED7A4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	muls r4, r0, r4
	adds r0, r7, #0
	bl sub_080C0D90
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne .L080EEBD8
	movs r1, #1
.L080EEBD8:
	adds r0, r4, #0
	bl __divsi3
	adds r6, r0, #0
	ldr r0, .L080EEC90
	bl sub_080EDA7C
	mov r0, sb
	bl sub_080EFE60
	adds r1, r0, #0
	adds r0, r7, #0
	bl sub_080F3F90
	adds r4, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080EEEE8
	adds r6, r0, #0
	adds r0, r4, #0
	subs r0, #0xc
	cmp r0, #1
	bhi .L080EEC94
.L080EEC08:
	mov r7, sb
	ldr r0, [r5]
	str r0, [r5, #4]
	movs r0, #0xb7
	lsls r0, r0, #1
	str r0, [r5, #8]
	cmp r7, #0xf
	bgt .L080EEC1C
	adds r0, #1
	str r0, [r5, #8]
.L080EEC1C:
	mov r0, sl
	bl sub_080ED794
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L080EECE4
	adds r0, r7, #0
	bl sub_080C0D90
	adds r4, r0, #0
	mov r0, sl
	bl sub_080ED7A4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	muls r4, r0, r4
	adds r0, r7, #0
	bl sub_080C0D90
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne .L080EEC50
	movs r1, #1
.L080EEC50:
	adds r0, r4, #0
	bl __divsi3
	adds r6, r0, #0
	adds r0, r7, #0
	bl sub_080EFE60
	adds r1, r0, #0
	adds r0, r7, #0
	bl sub_080F3F90
	adds r4, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080EEEE8
	adds r6, r0, #0
	adds r0, r4, #0
	subs r0, #0xc
	cmp r0, #1
	bls .L080EEC86
	cmp r4, #0xf
	beq .L080EEC86
	cmp r4, #0xe
	beq .L080EEC86
	cmp r4, #0
	bne .L080EECE4
.L080EEC86:
	movs r6, #0
	movs r0, #0
	bl sub_080EDA7C
	b .L080EECE4
.L080EEC90: .4byte 0x0000FFFF
.L080EEC94:
	adds r0, r4, #0
	subs r0, #0xe
	cmp r0, #1
	bls .L080EECA0
	cmp r4, #0
	bne .L080EECE4
.L080EECA0:
	mov r0, sb
	bl sub_080C35E4
	adds r4, r0, #0
	mov r0, sb
	bl sub_080F3F14
	mov r8, r0
	adds r0, r7, #0
	bl sub_080EFAB0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r4, #7
	bne .L080EECC6
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L080EEC08
.L080EECC6:
	cmp r4, #0xb
	bne .L080EECDC
	mov r0, r8
	cmp r0, #0x3f
	ble .L080EECDC
	cmp r0, #0x67
	bgt .L080EECDC
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L080EEC08
.L080EECDC:
	movs r6, #0
	movs r0, #0
	bl sub_080EDA7C
.L080EECE4:
	adds r0, r7, #0
	bl sub_080C0818
	adds r4, r0, #0
	mov r0, sl
	bl sub_080ED794
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ands r4, r0
	cmp r4, #0
	beq .L080EED00
	movs r0, #1
	str r0, [sp]
.L080EED00:
	cmp r6, #0
	beq .L080EED50
	bl sub_080C2244
	movs r1, #0x1f
	ands r1, r0
	cmp r1, r6
	bhs .L080EED50
	mov r0, sl
	bl sub_080ED6A4
	cmp r0, #7
	bne .L080EED1E
	cmp r7, #2
	ble .L080EED50
.L080EED1E:
	mov r0, sl
	bl sub_080ED794
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, r4, #0
	adds r0, r7, #0
	adds r1, r4, #0
	bl sub_080F3214
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080EED50
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq .L080EED4A
	adds r0, r7, #0
	bl sub_080F40A8
	cmp r0, #0
	beq .L080EED50
.L080EED4A:
	adds r0, r5, #0
	bl sub_080EDA7C
.L080EED50:
	ldr r0, [sp]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EED64
sub_080EED64: @ 0x080EED64
.L080EED64:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r0, #0xb
	bne .L080EED82
	adds r0, r1, #0
	subs r0, #0x68
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2b
	bhi .L080EED82
	movs r0, #1
	b .L080EED84
.L080EED82:
	movs r0, #0
.L080EED84:
	pop {r1}
	bx r1

	thumb_func_start sub_080EED88
sub_080EED88: @ 0x080EED88
.L080EED88:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	ldr r0, [r0]
	mov r8, r0
	mov r1, sb
	ldr r1, [r1, #4]
	mov sl, r1
	mov r2, sb
	ldr r4, [r2, #0x18]
	ldr r0, .L080EEDF4
	ldr r0, [r0]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r7, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r2, #8]
	mov r0, sl
	bl sub_080EFAB0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r0, r8
	bl sub_080C35E4
	adds r5, r0, #0
	cmp r4, #0
	blt .L080EEE7C
	ldr r0, .L080EEDF8
	cmp r7, r0
	beq .L080EEE7C
	mov r0, r8
	bl sub_080F3F14
	str r0, [sp]
	cmp r5, #7
	beq .L080EEDE2
	cmp r5, #0xb
	bne .L080EEDEA
.L080EEDE2:
	movs r0, #0x20
	ands r0, r6
	cmp r0, #0
	bne .L080EEEC0
.L080EEDEA:
	cmp r5, #7
	bne .L080EEDFC
	movs r0, #1
	b .L080EEE08
	.byte 0x00, 0x00
.L080EEDF4: .4byte 0x03006434 @ IWRAM+0x6434
.L080EEDF8: .4byte 0x0000FFFF
.L080EEDFC:
	subs r0, r5, #4
	cmp r0, #1
	bls .L080EEE06
	cmp r5, #0xa
	bne .L080EEE0E
.L080EEE06:
	movs r0, #2
.L080EEE08:
	ands r0, r6
	cmp r0, #0
	bne .L080EEEB6
.L080EEE0E:
	cmp r5, #0xb
	bne .L080EEE24
	ldr r0, [sp]
	cmp r0, #0x3f
	ble .L080EEE24
	cmp r0, #0x67
	bgt .L080EEE24
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	bne .L080EEEB6
.L080EEE24:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	ldrh r1, [r1]
	bl sub_080EED64
	cmp r0, #1
	bne .L080EEE3C
	movs r0, #2
	ands r0, r6
	cmp r0, #0
	bne .L080EEEB6
.L080EEE3C:
	mov r2, sl
	cmp r2, #0xf
	bgt .L080EEE5C
	bl sub_080F3F44
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L080EEE5C
	cmp r5, #7
	bne .L080EEE60
	movs r0, #2
	rsbs r0, r0, #0
	bl sub_080F3F58
	b .L080EEEB6
.L080EEE5C:
	cmp r5, #7
	beq .L080EEE68
.L080EEE60:
	cmp r5, #0xb
	beq .L080EEE68
	cmp r5, #8
	bne .L080EEE7C
.L080EEE68:
	cmp r5, #8
	bne .L080EEE76
	ldr r0, [sp]
	movs r1, #0xc
	mov r2, sp
	bl sub_080BF468
.L080EEE76:
	ldr r1, [sp]
	cmp r1, #0x7f
	ble .L080EEE80
.L080EEE7C:
	movs r0, #0
	b .L080EEED4
.L080EEE80:
	movs r0, #8
	ands r0, r6
	cmp r0, #0
	beq .L080EEE98
	adds r0, r1, #0
	bl sub_080ED6A4
	cmp r0, #2
	bne .L080EEE98
	movs r1, #9
	rsbs r1, r1, #0
	b .L080EEEAE
.L080EEE98:
	movs r0, #0x10
	ands r0, r6
	cmp r0, #0
	beq .L080EEE7C
	ldr r0, [sp]
	bl sub_080ED6A4
	cmp r0, #3
	bne .L080EEE7C
	movs r1, #0x11
	rsbs r1, r1, #0
.L080EEEAE:
	mov r0, sl
	bl sub_080EFB8C
	b .L080EEEC0
.L080EEEB6:
	movs r0, #0xb7
	lsls r0, r0, #1
	mov r1, sb
	str r0, [r1, #8]
	b .L080EEED2
.L080EEEC0:
	movs r1, #0
	mov r2, sb
	str r1, [r2, #0x18]
	ldr r0, .L080EEEE4
	ldr r0, [r0]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r1, [r0]
.L080EEED2:
	movs r0, #1
.L080EEED4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080EEEE4: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EEEE8
sub_080EEEE8: @ 0x080EEEE8
.L080EEEE8:
	push {lr}
	adds r3, r0, #0
	cmp r1, #0xc
	beq .L080EEF8C
	cmp r1, #0xd
	beq .L080EEEFC
	cmp r1, #0xe
	beq .L080EEF8C
	cmp r1, #0xf
	bne .L080EEF00
.L080EEEFC:
	adds r0, r3, #0
	b .L080EEF92
.L080EEF00:
	cmp r1, #8
	bgt .L080EEF12
	adds r0, r3, #0
	muls r0, r1, r0
	cmp r0, #0
	bge .L080EEF0E
	adds r0, #7
.L080EEF0E:
	asrs r0, r0, #3
	b .L080EEF92
.L080EEF12:
	adds r2, r3, #0
	cmp r1, #0xc
	bhi .L080EEF5C
	lsls r0, r1, #2
	ldr r1, .L080EEF24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080EEF24: .4byte gUnknown_080EEF28
	.global gUnknown_080EEF28
gUnknown_080EEF28:
.L080EEF28: @ jump table
	.4byte .L080EEF5C
	.4byte .L080EEF60
	.4byte .L080EEF62
	.4byte .L080EEF68
	.4byte .L080EEF64
	.4byte .L080EEF6E
	.4byte .L080EEF76
	.4byte .L080EEF74
	.4byte .L080EEF88
	.4byte .L080EEF84
	.4byte .L080EEF86
	.4byte .L080EEF7E
	.4byte .L080EEF8C
.L080EEF5C:
	movs r0, #0
	b .L080EEF92
.L080EEF60:
	asrs r2, r2, #1
.L080EEF62:
	asrs r2, r2, #1
.L080EEF64:
	asrs r2, r2, #1
	b .L080EEF88
.L080EEF68:
	asrs r2, r2, #1
	adds r2, r2, r3
	b .L080EEF62
.L080EEF6E:
	asrs r2, r2, #1
	adds r2, r2, r3
	b .L080EEF76
.L080EEF74:
	asrs r2, r2, #1
.L080EEF76:
	asrs r1, r2, #2
	subs r0, r3, #1
	subs r2, r0, r1
	b .L080EEF88
.L080EEF7E:
	asrs r2, r2, #1
	adds r2, r2, r3
	b .L080EEF86
.L080EEF84:
	asrs r2, r2, #1
.L080EEF86:
	adds r2, r2, r3
.L080EEF88:
	adds r0, r2, #0
	b .L080EEF92
.L080EEF8C:
	lsrs r0, r3, #0x1f
	adds r0, r3, r0
	asrs r0, r0, #1
.L080EEF92:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080EEF98
sub_080EEF98: @ 0x080EEF98
.L080EEF98:
	push {r4, r5, lr}
	ldr r0, .L080EEFB8
	ldr r0, [r0]
	movs r1, #0x93
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xd
	bls .L080EEFAE
	b .L080EF0CA
.L080EEFAE:
	lsls r0, r0, #2
	ldr r1, .L080EEFBC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080EEFB8: .4byte 0x03006434 @ IWRAM+0x6434
.L080EEFBC: .4byte gUnknown_080EEFC0
	.global gUnknown_080EEFC0
gUnknown_080EEFC0:
.L080EEFC0: @ jump table
	.4byte .L080EF0CA
	.4byte .L080EEFF8
	.4byte .L080EF000
	.4byte .L080EF00A
	.4byte .L080EF014
	.4byte .L080EF01E
	.4byte .L080EF054
	.4byte .L080EF054
	.4byte .L080EF078
	.4byte .L080EF08C
	.4byte .L080EF08C
	.4byte .L080EF08C
	.4byte .L080EF054
	.4byte .L080EF0CA
.L080EEFF8:
	movs r0, #0x80
	bl sub_080ED90C
	b .L080EF0CA
.L080EF000:
	movs r0, #0xc0
	lsls r0, r0, #8
	bl sub_080ED920
	b .L080EF0CA
.L080EF00A:
	movs r0, #0x80
	lsls r0, r0, #8
	bl sub_080ED920
	b .L080EF0CA
.L080EF014:
	movs r0, #0x80
	lsls r0, r0, #6
	bl sub_080ED90C
	b .L080EF064
.L080EF01E:
	bl sub_080EF878
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #8
	bl sub_080C08F8
	adds r0, r4, #0
	bl sub_080F4104
	movs r0, #1
	rsbs r0, r0, #0
	bl sub_08126834
	bl sub_080E760C
	bl sub_080ED9F4
	cmp r0, #0
	bne .L080EF0CA
	ldr r0, .L080EF070
	ldr r0, [r0]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #7
	strh r0, [r1]
.L080EF054:
	movs r0, #0x80
	lsls r0, r0, #2
	bl sub_080ED90C
	bl sub_080EDA04
	bl sub_080E74DC
.L080EF064:
	ldr r0, .L080EF070
	ldr r1, [r0]
	ldr r0, .L080EF074
	strh r0, [r1, #4]
	b .L080EF0CA
	.byte 0x00, 0x00
.L080EF070: .4byte 0x03006434 @ IWRAM+0x6434
.L080EF074: .4byte 0x0000FFFF
.L080EF078:
	bl sub_080ED9F4
	cmp r0, #7
	bgt .L080EF0CA
	bl sub_080EF828
	movs r1, #1
	bl sub_080EF224
	b .L080EF0CA
.L080EF08C:
	movs r0, #0x80
	lsls r0, r0, #3
	bl sub_080ED90C
	ldr r0, .L080EF0D0
	ldr r1, .L080EF0D4
	adds r4, r0, r1
	ldrh r0, [r4]
	ldr r5, .L080EF0D8
	cmp r0, r5
	beq .L080EF0B2
	bl sub_080F41B0
	bl sub_080C366C
	ldrh r1, [r4]
	adds r0, r5, #0
	orrs r0, r1
	strh r0, [r4]
.L080EF0B2:
	ldr r0, .L080EF0DC
	ldrh r0, [r0]
	bl sub_080C062C
	bl sub_080C101C
	ldr r0, .L080EF0E0
	ldr r2, [r0]
	ldrh r1, [r2, #4]
	adds r0, r5, #0
	orrs r0, r1
	strh r0, [r2, #4]
.L080EF0CA:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080EF0D0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080EF0D4: .4byte 0x0000118E
.L080EF0D8: .4byte 0x0000FFFF
.L080EF0DC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L080EF0E0: .4byte 0x03006434 @ IWRAM+0x6434

	thumb_func_start sub_080EF0E4
sub_080EF0E4: @ 0x080EF0E4
.L080EF0E4:
	push {r4, r5, lr}
	adds r5, r0, #0
	cmp r5, #0xf
	ble .L080EF0F0
.L080EF0EC:
	movs r0, #0
	b .L080EF13E
.L080EF0F0:
	bl sub_080F3F44
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #0
	bl sub_080C06BC
	adds r5, r0, #0
	bl sub_080EDA90
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq .L080EF120
	subs r0, r5, #1
	cmp r0, #1
	bhi .L080EF120
	ldr r0, .L080EF11C
	ands r4, r0
	movs r0, #0xf3
	b .L080EF132
	.byte 0x00, 0x00
.L080EF11C: .4byte 0x0000FFFD
.L080EF120:
	movs r0, #8
	ands r0, r4
	cmp r0, #0
	beq .L080EF0EC
	cmp r5, #0
	bne .L080EF0EC
	ldr r0, .L080EF144
	ands r4, r0
	movs r0, #0xf4
.L080EF132:
	bl sub_080F3E38
	adds r0, r4, #0
	bl sub_080F3F30
	movs r0, #1
.L080EF13E:
	pop {r4, r5}
	pop {r1}
	bx r1
.L080EF144: .4byte 0x0000FFF7

	thumb_func_start sub_080EF148
sub_080EF148: @ 0x080EF148
.L080EF148:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r4, #0
	bge .L080EF154
	movs r4, #0
.L080EF154:
	adds r0, r4, #0
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	bl sub_080C08F8
	adds r0, r4, #0
	bl sub_080C07E0
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	adds r0, r4, #0
	movs r1, #0
	bl sub_080F4054
	adds r0, r6, #0
	bl sub_080F40C4
	cmp r4, #0xf
	ble .L080EF1F0
	adds r7, r4, #0
	subs r7, #0x10
	cmp r5, #1
	bne .L080EF1D8
	movs r5, #0
.L080EF18A:
	adds r0, r5, #0
	bl sub_080F40EC
	adds r4, r0, #0
	cmp r4, #3
	bhi .L080EF1B4
	bl sub_080C0F8C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r6, #0
	bl sub_080EF494
	ldr r1, .L080EF1EC
	ldr r2, [r1]
	lsls r1, r4, #2
	adds r2, #0x68
	adds r2, r2, r1
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r2]
.L080EF1B4:
	adds r5, #1
	cmp r5, #5
	ble .L080EF18A
	adds r0, r6, #0
	bl sub_080EF538
	ldr r4, .L080EF1EC
	ldr r2, [r4]
	ldr r1, [r2, #0x4c]
	adds r1, r1, r0
	str r1, [r2, #0x4c]
	adds r0, r6, #0
	bl sub_080EF580
	ldr r2, [r4]
	ldr r1, [r2, #0x50]
	adds r1, r1, r0
	str r1, [r2, #0x50]
.L080EF1D8:
	adds r0, r6, #0
	bl sub_080EF6B4
	bl sub_080ED8F4
	adds r0, r7, #0
	movs r1, #2
	bl sub_080E7538
	b .L080EF206
.L080EF1EC: .4byte 0x03006434 @ IWRAM+0x6434
.L080EF1F0:
	cmp r4, #3
	ble .L080EF1FC
	adds r0, r4, #0
	bl sub_080F4190
	b .L080EF206
.L080EF1FC:
	adds r0, r4, #0
	bl sub_080BFFC4
	bl sub_080C8490
.L080EF206:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080EF20C
sub_080EF20C: @ 0x080EF20C
.L080EF20C:
	push {lr}
	movs r1, #0
	bl sub_080EF148
	pop {r0}
	bx r0
