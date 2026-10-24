	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080AD444
sub_080AD444: @ 0x080AD444
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080AD448
sub_080AD448: @ 0x080AD448
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r1, .L080AD474
	ldr r4, [r1]
	ldm r4!, {r6}
	str r4, [r1]
	ldr r1, [r0, #0x10]
	adds r1, #6
	str r1, [r0, #0x10]
	ldr r1, [r4]
	ldr r2, [r4, #4]
	ldr r3, [r4, #8]
	ldr r5, [r4, #0xc]
	str r5, [sp]
	ldr r4, [r4, #0x10]
	str r4, [sp, #4]
	bl _call_via_r6
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080AD474: .4byte 0x03003B84 @ IWRAM+0x3B84

	thumb_func_start sub_080AD478
sub_080AD478: @ 0x080AD478
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080AD47C
sub_080AD47C: @ 0x080AD47C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r1, .L080AD4AC
	ldr r4, [r1]
	ldm r4!, {r6}
	str r4, [r1]
	ldr r1, [r0, #0x10]
	adds r1, #7
	str r1, [r0, #0x10]
	ldr r1, [r4]
	ldr r2, [r4, #4]
	ldr r3, [r4, #8]
	ldr r5, [r4, #0xc]
	str r5, [sp]
	ldr r5, [r4, #0x10]
	str r5, [sp, #4]
	ldr r4, [r4, #0x14]
	str r4, [sp, #8]
	bl _call_via_r6
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080AD4AC: .4byte 0x03003B84 @ IWRAM+0x3B84

	thumb_func_start sub_080AD4B0
sub_080AD4B0: @ 0x080AD4B0
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080AD4B4
sub_080AD4B4: @ 0x080AD4B4
	ldr r3, .L080AD4C8
	ldr r2, [r3]
	ldm r2!, {r1}
	strh r1, [r0, #0x1e]
	str r2, [r3]
	ldr r1, [r0, #0x10]
	adds r1, #1
	str r1, [r0, #0x10]
	bx lr
	.byte 0x00, 0x00
.L080AD4C8: .4byte 0x03003B84 @ IWRAM+0x3B84

	thumb_func_start sub_080AD4CC
sub_080AD4CC: @ 0x080AD4CC
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080AD4D0
sub_080AD4D0: @ 0x080AD4D0
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r1, .L080AD4F4
	ldr r4, [r1]
	ldm r4!, {r2}
	str r4, [r1]
	adds r0, r4, #0
	ldm r0!, {r5}
	str r0, [r1]
	cmp r2, #1
	beq .L080AD504
	cmp r2, #1
	blo .L080AD4F8
	cmp r2, #2
	beq .L080AD510
	cmp r2, #3
	beq .L080AD51C
	b .L080AD530
.L080AD4F4: .4byte 0x03003B84 @ IWRAM+0x3B84
.L080AD4F8:
	ldrh r1, [r3, #0x1e]
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bne .L080AD530
	b .L080AD526
.L080AD504:
	ldrh r1, [r3, #0x1e]
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	beq .L080AD530
	b .L080AD526
.L080AD510:
	ldrh r1, [r3, #0x1e]
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	blo .L080AD530
	b .L080AD526
.L080AD51C:
	ldrh r1, [r3, #0x1e]
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bhs .L080AD530
.L080AD526:
	ldr r1, [r4, #4]
	adds r0, r3, #0
	bl Task_GotoLabel
	b .L080AD536
.L080AD530:
	ldr r0, [r3, #0x10]
	adds r0, #3
	str r0, [r3, #0x10]
.L080AD536:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080AD53C
sub_080AD53C: @ 0x080AD53C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080AD540
sub_080AD540: @ 0x080AD540
	ldr r1, .L080AD550
	ldr r1, [r1]
	ldr r1, [r1]
	str r1, [r0, #0x20]
	ldr r1, [r0, #0x10]
	adds r1, #1
	str r1, [r0, #0x10]
	bx lr
.L080AD550: .4byte 0x03003B84 @ IWRAM+0x3B84

	thumb_func_start sub_080AD554
sub_080AD554: @ 0x080AD554
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080AD558
sub_080AD558: @ 0x080AD558
	push {lr}
	ldr r2, .L080AD570
	ldr r1, [r2]
	ldm r1!, {r3}
	str r1, [r2]
	ldr r1, [r0, #0x10]
	adds r1, #1
	str r1, [r0, #0x10]
	bl _call_via_r3
	pop {r0}
	bx r0
.L080AD570: .4byte 0x03003B84 @ IWRAM+0x3B84

	thumb_func_start sub_080AD574
sub_080AD574: @ 0x080AD574
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080AD578
sub_080AD578: @ 0x080AD578
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080AD594
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r1, [r4, #2]
	bl Task_Create
	ldr r0, [r4, #0x10]
	adds r0, #1
	str r0, [r4, #0x10]
	pop {r4}
	pop {r0}
	bx r0
.L080AD594: .4byte 0x03003B84 @ IWRAM+0x3B84

	thumb_func_start sub_080AD598
sub_080AD598: @ 0x080AD598
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080AD59C
sub_080AD59C: @ 0x080AD59C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080AD5B8
	ldr r0, [r0]
	ldrh r0, [r0]
	bl sub_080C5170
	ldr r0, [r4, #0x10]
	adds r0, #1
	str r0, [r4, #0x10]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AD5B8: .4byte 0x03003B84 @ IWRAM+0x3B84

	thumb_func_start sub_080AD5BC
sub_080AD5BC: @ 0x080AD5BC
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080AD5C0
sub_080AD5C0: @ 0x080AD5C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080AD5DC
	ldr r0, [r0]
	ldrh r0, [r0]
	bl sub_080C51D4
	ldr r0, [r4, #0x10]
	adds r0, #1
	str r0, [r4, #0x10]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AD5DC: .4byte 0x03003B84 @ IWRAM+0x3B84

	thumb_func_start sub_080AD5E0
sub_080AD5E0: @ 0x080AD5E0
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080AD5E4
sub_080AD5E4: @ 0x080AD5E4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080AD600
	ldr r0, [r0]
	ldrh r0, [r0]
	bl m4aSongNumStop
	ldr r0, [r4, #0x10]
	adds r0, #1
	str r0, [r4, #0x10]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AD600: .4byte 0x03003B84 @ IWRAM+0x3B84

	thumb_func_start sub_080AD604
sub_080AD604: @ 0x080AD604
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080AD608
sub_080AD608: @ 0x080AD608
.L080AD608:
	push {r4, lr}
	sub sp, #4
	ldr r1, .L080AD64C
	ldrh r0, [r1, #0x12]
	ldrh r1, [r1, #0x14]
	mov r4, sp
	adds r4, #2
	mov r2, sp
	adds r3, r4, #0
	bl sub_080C1F50
	ldr r2, .L080AD650
	mov r0, sp
	ldrh r1, [r0]
	lsrs r1, r1, #2
	ldrh r0, [r4]
	lsrs r0, r0, #2
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r2
	ldrb r0, [r1]
	ldr r1, .L080AD654
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_080C5E44
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080AD64C: .4byte 0x03004550 @ IWRAM+0x4550
.L080AD650: .4byte gUnknown_0815EFB4
.L080AD654: .4byte gUnknown_0815F1B4

	thumb_func_start sub_080AD658
sub_080AD658: @ 0x080AD658
	push {lr}
	ldr r0, .L080AD674
	ldrh r0, [r0]
	ldr r1, .L080AD678
	ldrh r1, [r1]
	bl sub_080AD608
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C5170
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AD674: .4byte 0x03004614 @ IWRAM+0x4614
.L080AD678: .4byte 0x03004514 @ IWRAM+0x4514

	thumb_func_start sub_080AD67C
sub_080AD67C: @ 0x080AD67C
.L080AD67C:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #0
	ldr r3, .L080AD6B0
	ldrh r0, [r3]
	ldr r4, .L080AD6B4
	cmp r0, r2
	beq .L080AD69E
.L080AD68E:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne .L080AD68E
.L080AD69E:
	lsls r0, r1, #3
	adds r4, r0, r4
	ldrh r0, [r4]
	bl Flag_Test
	cmp r0, #0
	beq .L080AD6B8
	ldrh r0, [r4, #4]
	b .L080AD6BA
.L080AD6B0: .4byte gUnknown_087DF93C
.L080AD6B4: .4byte gUnknown_0815F214
.L080AD6B8:
	ldrh r0, [r4, #2]
.L080AD6BA:
	bl sub_080C5E44
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080AD6C8
sub_080AD6C8: @ 0x080AD6C8
	push {lr}
	ldr r0, .L080AD6E0
	ldrh r0, [r0, #8]
	bl sub_080AD67C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C5170
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AD6E0: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start sub_080AD6E4
sub_080AD6E4: @ 0x080AD6E4
.L080AD6E4:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	movs r1, #0
	bl sub_080B2EFC
	movs r1, #0x21
	bl sub_080B3038
	adds r5, r0, #0
	cmp r5, #0
	bne .L080AD728
	ldr r4, .L080AD724
	strh r6, [r4, #0x32]
	movs r0, #0x10
	bl Field_SetState
	strh r5, [r4, #0x1e]
	adds r4, #0x50
	ldrh r0, [r4]
	cmp r0, #1
	bne .L080AD716
	movs r0, #2
	strh r0, [r4]
.L080AD716:
	cmp r6, #0
	bne .L080AD73E
	movs r0, #0x65
	bl sub_080C51D4
	b .L080AD73E
	.byte 0x00, 0x00
.L080AD724: .4byte 0x03004550 @ IWRAM+0x4550
.L080AD728:
	ldr r4, .L080AD744
	movs r5, #0
	strh r6, [r4, #0x32]
	ldr r0, .L080AD748
	ldr r1, .L080AD74C
	bl Task_Create
	movs r0, #0x1a
	bl Field_SetState
	strh r5, [r4, #0x1e]
.L080AD73E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080AD744: .4byte 0x03004550 @ IWRAM+0x4550
.L080AD748: .4byte gUnknown_08165598
.L080AD74C: .4byte 0x0000FFFF

	thumb_func_start sub_080AD750
sub_080AD750: @ 0x080AD750
.L080AD750:
	push {lr}
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	movs r1, #0
	subs r0, #2
	cmp r0, #1
	bhi .L080AD766
	movs r1, #1
.L080AD766:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start sub_080AD76C
sub_080AD76C: @ 0x080AD76C
.L080AD76C:
	push {lr}
	bl sub_080C5E58
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L080AD788
	cmp r1, r0
	beq .L080AD782
	adds r0, r1, #0
	bl sub_080B6568
.L080AD782:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AD788: .4byte 0x0000FFFF

	thumb_func_start Field_SetState
Field_SetState: @ 0x080AD78C
.L080AD78C:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L080AD7D0
	strh r4, [r0]
	cmp r4, #1
	bne .L080AD7A6
	bl sub_080AD750
	cmp r0, #1
	bne .L080AD7A6
	bl sub_080AD76C
.L080AD7A6:
	cmp r4, #0x10
	bne .L080AD7B8
	ldr r0, .L080AD7D4
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080AD7D8
	strh r1, [r0]
	ldr r0, .L080AD7DC
	strh r1, [r0]
.L080AD7B8:
	cmp r4, #3
	bne .L080AD7C2
	movs r0, #0
	bl sub_080B3878
.L080AD7C2:
	ldr r1, .L080AD7E0
	movs r0, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AD7D0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AD7D4: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080AD7D8: .4byte 0x0200DFCE @ EWRAM+0xDFCE
.L080AD7DC: .4byte 0x0200DFD0 @ EWRAM+0xDFD0
.L080AD7E0: .4byte 0x03003FF4 @ IWRAM+0x3FF4

	thumb_func_start sub_080AD7E4
sub_080AD7E4: @ 0x080AD7E4
.L080AD7E4:
	ldr r0, .L080AD7EC
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080AD7EC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080AD7F0
sub_080AD7F0: @ 0x080AD7F0
.L080AD7F0:
	ldr r1, .L080AD7F8
	movs r0, #1
	str r0, [r1]
	bx lr
.L080AD7F8: .4byte 0x03003FF8 @ IWRAM+0x3FF8

	thumb_func_start sub_080AD7FC
sub_080AD7FC: @ 0x080AD7FC
.L080AD7FC:
	ldr r0, .L080AD804
	ldr r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080AD804: .4byte 0x03003FF8 @ IWRAM+0x3FF8

	thumb_func_start sub_080AD808
sub_080AD808: @ 0x080AD808
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080AD7FC
	cmp r0, #0
	beq .L080AD818
	movs r0, #0
	b .L080AD81A
.L080AD818:
	movs r0, #1
.L080AD81A:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080AD824
sub_080AD824: @ 0x080AD824
.L080AD824:
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080C8B10
	ldr r1, .L080AD860
	ldr r2, .L080AD864
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0xe8
	muls r1, r2, r1
	adds r1, #0x98
	adds r4, r0, r1
	ldr r0, [r6]
	cmp r0, #0
	bne .L080AD84E
	b .L080ADCC2
.L080AD84E:
	subs r0, #1
	cmp r0, #0x26
	bls .L080AD856
	b .L080ADCB8
.L080AD856:
	lsls r0, r0, #2
	ldr r1, .L080AD868
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080AD860: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080AD864: .4byte 0x00000A38
.L080AD868: .4byte gUnknown_080AD86C
	.global gUnknown_080AD86C
gUnknown_080AD86C:
.L080AD86C: @ jump table
	.4byte .L080AD908
	.4byte .L080AD924
	.4byte .L080AD938
	.4byte .L080AD94C
	.4byte .L080AD960
	.4byte .L080AD974
	.4byte .L080AD988
	.4byte .L080AD99C
	.4byte .L080AD9B0
	.4byte .L080AD9D0
	.4byte .L080AD9E8
	.4byte .L080ADA00
	.4byte .L080ADA18
	.4byte .L080ADA30
	.4byte .L080ADA48
	.4byte .L080ADA64
	.4byte .L080ADA78
	.4byte .L080ADA8C
	.4byte .L080ADAA0
	.4byte .L080ADAB4
	.4byte .L080ADAC8
	.4byte .L080ADADC
	.4byte .L080ADAF8
	.4byte .L080ADB0C
	.4byte .L080ADB20
	.4byte .L080ADB34
	.4byte .L080ADB54
	.4byte .L080ADB6C
	.4byte .L080ADB84
	.4byte .L080ADB9C
	.4byte .L080ADBB4
	.4byte .L080ADBCC
	.4byte .L080ADBF4
	.4byte .L080ADC08
	.4byte .L080ADC1C
	.4byte .L080ADC30
	.4byte .L080ADC6C
	.4byte .L080ADC74
	.4byte .L080ADC90
.L080AD908:
	movs r0, #0
	str r0, [sp]
	ldr r5, .L080AD91C
	ldr r2, .L080AD920
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	ldr r0, [r4, #0x60]
	b .L080ADBDE
.L080AD91C: .4byte 0x0200F874 @ EWRAM+0xF874
.L080AD920: .4byte 0x05002000
.L080AD924:
	ldr r0, [r4, #0x64]
	cmp r0, #0
	bne .L080AD92C
	b .L080ADCBC
.L080AD92C:
	ldr r1, .L080AD934
	bl LZ77UnCompWram
	b .L080ADCBC
.L080AD934: .4byte 0x02010874 @ EWRAM+0x10874
.L080AD938:
	ldr r0, [r4, #0x68]
	cmp r0, #0
	bne .L080AD940
	b .L080ADCBC
.L080AD940:
	ldr r1, .L080AD948
	bl LZ77UnCompWram
	b .L080ADCBC
.L080AD948: .4byte 0x02011874 @ EWRAM+0x11874
.L080AD94C:
	ldr r0, [r4, #0x6c]
	cmp r0, #0
	bne .L080AD954
	b .L080ADCBC
.L080AD954:
	ldr r1, .L080AD95C
	bl LZ77UnCompWram
	b .L080ADCBC
.L080AD95C: .4byte 0x02012874 @ EWRAM+0x12874
.L080AD960:
	ldr r0, [r4, #0x70]
	cmp r0, #0
	bne .L080AD968
	b .L080ADCBC
.L080AD968:
	ldr r1, .L080AD970
	bl LZ77UnCompWram
	b .L080ADCBC
.L080AD970: .4byte 0x02013874 @ EWRAM+0x13874
.L080AD974:
	ldr r0, [r4, #0x74]
	cmp r0, #0
	bne .L080AD97C
	b .L080ADCBC
.L080AD97C:
	ldr r1, .L080AD984
	bl LZ77UnCompWram
	b .L080ADCBC
.L080AD984: .4byte 0x02014874 @ EWRAM+0x14874
.L080AD988:
	ldr r0, [r4, #0x78]
	cmp r0, #0
	bne .L080AD990
	b .L080ADCBC
.L080AD990:
	ldr r1, .L080AD998
	bl LZ77UnCompWram
	b .L080ADCBC
.L080AD998: .4byte 0x02015874 @ EWRAM+0x15874
.L080AD99C:
	ldr r0, [r4, #0x7c]
	cmp r0, #0
	bne .L080AD9A4
	b .L080ADCBC
.L080AD9A4:
	ldr r1, .L080AD9AC
	bl LZ77UnCompWram
	b .L080ADCBC
.L080AD9AC: .4byte 0x02016874 @ EWRAM+0x16874
.L080AD9B0:
	movs r0, #0
	str r0, [sp, #4]
	add r0, sp, #4
	ldr r5, .L080AD9C8
	ldr r2, .L080AD9CC
	adds r1, r5, #0
	bl CpuSet
	adds r0, r4, #0
	adds r0, #0x80
	ldr r0, [r0]
	b .L080ADBDE
.L080AD9C8: .4byte 0x02017874 @ EWRAM+0x17874
.L080AD9CC: .4byte 0x05001800
.L080AD9D0:
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	cmp r0, #0
	bne .L080AD9DC
	b .L080ADCBC
.L080AD9DC:
	ldr r1, .L080AD9E4
	bl LZ77UnCompWram
	b .L080ADCBC
.L080AD9E4: .4byte 0x02018874 @ EWRAM+0x18874
.L080AD9E8:
	adds r0, r4, #0
	adds r0, #0x88
	ldr r0, [r0]
	cmp r0, #0
	bne .L080AD9F4
	b .L080ADCBC
.L080AD9F4:
	ldr r1, .L080AD9FC
	bl LZ77UnCompWram
	b .L080ADCBC
.L080AD9FC: .4byte 0x02019874 @ EWRAM+0x19874
.L080ADA00:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	cmp r0, #0
	bne .L080ADA0C
	b .L080ADCBC
.L080ADA0C:
	ldr r1, .L080ADA14
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADA14: .4byte 0x0201A874 @ EWRAM+0x1A874
.L080ADA18:
	adds r0, r4, #0
	adds r0, #0x90
	ldr r0, [r0]
	cmp r0, #0
	bne .L080ADA24
	b .L080ADCBC
.L080ADA24:
	ldr r1, .L080ADA2C
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADA2C: .4byte 0x0201B874 @ EWRAM+0x1B874
.L080ADA30:
	adds r0, r4, #0
	adds r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	bne .L080ADA3C
	b .L080ADCBC
.L080ADA3C:
	ldr r1, .L080ADA44
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADA44: .4byte 0x0201C874 @ EWRAM+0x1C874
.L080ADA48:
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	ldr r5, .L080ADA5C
	ldr r2, .L080ADA60
	adds r1, r5, #0
	bl CpuSet
	ldr r0, [r4]
	b .L080ADBDE
.L080ADA5C: .4byte 0x0201D874 @ EWRAM+0x1D874
.L080ADA60: .4byte 0x05001A00
.L080ADA64:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne .L080ADA6C
	b .L080ADCBC
.L080ADA6C:
	ldr r1, .L080ADA74
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADA74: .4byte 0x0201E874 @ EWRAM+0x1E874
.L080ADA78:
	ldr r0, [r4, #8]
	cmp r0, #0
	bne .L080ADA80
	b .L080ADCBC
.L080ADA80:
	ldr r1, .L080ADA88
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADA88: .4byte 0x0201F874 @ EWRAM+0x1F874
.L080ADA8C:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	bne .L080ADA94
	b .L080ADCBC
.L080ADA94:
	ldr r1, .L080ADA9C
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADA9C: .4byte 0x02020874 @ EWRAM+0x20874
.L080ADAA0:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne .L080ADAA8
	b .L080ADCBC
.L080ADAA8:
	ldr r1, .L080ADAB0
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADAB0: .4byte 0x02021874 @ EWRAM+0x21874
.L080ADAB4:
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bne .L080ADABC
	b .L080ADCBC
.L080ADABC:
	ldr r1, .L080ADAC4
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADAC4: .4byte 0x02022874 @ EWRAM+0x22874
.L080ADAC8:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	bne .L080ADAD0
	b .L080ADCBC
.L080ADAD0:
	ldr r1, .L080ADAD8
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADAD8: .4byte 0x02023874 @ EWRAM+0x23874
.L080ADADC:
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldr r5, .L080ADAF0
	ldr r2, .L080ADAF4
	adds r1, r5, #0
	bl CpuSet
	ldr r0, [r4, #0x20]
	b .L080ADBDE
.L080ADAF0: .4byte 0x02024074 @ EWRAM+0x24074
.L080ADAF4: .4byte 0x05001000
.L080ADAF8:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	bne .L080ADB00
	b .L080ADCBC
.L080ADB00:
	ldr r1, .L080ADB08
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADB08: .4byte 0x02025074 @ EWRAM+0x25074
.L080ADB0C:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne .L080ADB14
	b .L080ADCBC
.L080ADB14:
	ldr r1, .L080ADB1C
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADB1C: .4byte 0x02026074 @ EWRAM+0x26074
.L080ADB20:
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne .L080ADB28
	b .L080ADCBC
.L080ADB28:
	ldr r1, .L080ADB30
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADB30: .4byte 0x02027074 @ EWRAM+0x27074
.L080ADB34:
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	ldr r5, .L080ADB4C
	ldr r2, .L080ADB50
	adds r1, r5, #0
	bl CpuSet
	adds r0, r4, #0
	adds r0, #0xa0
	ldr r0, [r0]
	b .L080ADBDE
.L080ADB4C: .4byte 0x02028074 @ EWRAM+0x28074
.L080ADB50: .4byte 0x05001600
.L080ADB54:
	adds r0, r4, #0
	adds r0, #0xa4
	ldr r0, [r0]
	cmp r0, #0
	bne .L080ADB60
	b .L080ADCBC
.L080ADB60:
	ldr r1, .L080ADB68
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADB68: .4byte 0x02029074 @ EWRAM+0x29074
.L080ADB6C:
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	bne .L080ADB78
	b .L080ADCBC
.L080ADB78:
	ldr r1, .L080ADB80
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADB80: .4byte 0x0202A074 @ EWRAM+0x2A074
.L080ADB84:
	adds r0, r4, #0
	adds r0, #0xac
	ldr r0, [r0]
	cmp r0, #0
	bne .L080ADB90
	b .L080ADCBC
.L080ADB90:
	ldr r1, .L080ADB98
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADB98: .4byte 0x0202B074 @ EWRAM+0x2B074
.L080ADB9C:
	adds r0, r4, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	bne .L080ADBA8
	b .L080ADCBC
.L080ADBA8:
	ldr r1, .L080ADBB0
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADBB0: .4byte 0x0202C074 @ EWRAM+0x2C074
.L080ADBB4:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne .L080ADBC0
	b .L080ADCBC
.L080ADBC0:
	ldr r1, .L080ADBC8
	bl LZ77UnCompWram
	b .L080ADCBC
.L080ADBC8: .4byte 0x0202D074 @ EWRAM+0x2D074
.L080ADBCC:
	movs r0, #0
	str r0, [sp, #0x14]
	add r0, sp, #0x14
	ldr r5, .L080ADBEC
	ldr r2, .L080ADBF0
	adds r1, r5, #0
	bl CpuSet
	ldr r0, [r4, #0x40]
.L080ADBDE:
	cmp r0, #0
	beq .L080ADCBC
	adds r1, r5, #0
	bl LZ77UnCompWram
	b .L080ADCBC
	.byte 0x00, 0x00
.L080ADBEC: .4byte 0x0202D874 @ EWRAM+0x2D874
.L080ADBF0: .4byte 0x05000D00
.L080ADBF4:
	ldr r0, [r4, #0x44]
	cmp r0, #0
	beq .L080ADCBC
	ldr r1, .L080ADC04
	bl LZ77UnCompWram
	b .L080ADCBC
	.byte 0x00, 0x00
.L080ADC04: .4byte 0x0202E874 @ EWRAM+0x2E874
.L080ADC08:
	ldr r0, [r4, #0x48]
	cmp r0, #0
	beq .L080ADCBC
	ldr r1, .L080ADC18
	bl LZ77UnCompWram
	b .L080ADCBC
	.byte 0x00, 0x00
.L080ADC18: .4byte 0x0202F874 @ EWRAM+0x2F874
.L080ADC1C:
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L080ADCBC
	ldr r1, .L080ADC2C
	bl LZ77UnCompWram
	b .L080ADCBC
	.byte 0x00, 0x00
.L080ADC2C: .4byte 0x02030874 @ EWRAM+0x30874
.L080ADC30:
	movs r0, #0
	str r0, [sp, #0x18]
	ldr r1, .L080ADC54
	add r0, sp, #0x18
	str r0, [r1]
	ldr r0, .L080ADC58
	str r0, [r1, #4]
	ldr r0, .L080ADC5C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, .L080ADC60
	ldr r0, .L080ADC64
	str r0, [r1]
	ldr r0, .L080ADC68
	bl sub_080B6F28
	b .L080ADCBC
	.byte 0x00, 0x00
.L080ADC54: .4byte 0x040000D4 @ REG_DMA3SAD
.L080ADC58: .4byte 0x02030C74 @ EWRAM+0x30C74
.L080ADC5C: .4byte 0x85001500
.L080ADC60: .4byte 0x03004604 @ IWRAM+0x4604
.L080ADC64: .4byte 0x0202D874 @ EWRAM+0x2D874
.L080ADC68: .4byte gUnknown_0815F264
.L080ADC6C:
	ldr r4, .L080ADC70
	b .L080ADC76
.L080ADC70: .4byte gUnknown_0815F264
.L080ADC74:
	ldr r4, .L080ADC8C
.L080ADC76:
	adds r0, r4, #0
	bl sub_080B6F40
	cmp r0, #1
	beq .L080ADC9A
	adds r0, r4, #0
	adds r0, #0x1c
	bl sub_080B6F28
	b .L080ADCBC
	.byte 0x00, 0x00
.L080ADC8C: .4byte gUnknown_0815F280
.L080ADC90:
	ldr r0, .L080ADCA4
	bl sub_080B6F40
	cmp r0, #1
	bne .L080ADCA8
.L080ADC9A:
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
	b .L080ADCBC
	.byte 0x00, 0x00
.L080ADCA4: .4byte gUnknown_0815F29C
.L080ADCA8:
	ldr r1, .L080ADCB0
	ldr r0, .L080ADCB4
	str r0, [r1]
	b .L080ADCBC
.L080ADCB0: .4byte 0x03003FCC @ IWRAM+0x3FCC
.L080ADCB4: .4byte 0x02030C74 @ EWRAM+0x30C74
.L080ADCB8:
	movs r0, #0
	b .L080ADCC0
.L080ADCBC:
	ldr r0, [r6]
	adds r0, #1
.L080ADCC0:
	str r0, [r6]
.L080ADCC2:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080ADCCC
sub_080ADCCC: @ 0x080ADCCC
.L080ADCCC:
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080C8B10
	ldr r1, .L080ADD2C
	ldr r2, .L080ADD30
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0xe8
	muls r1, r2, r1
	adds r1, #0x98
	adds r4, r0, r1
	ldr r1, .L080ADD34
	ldr r0, .L080ADD38
	str r0, [r1]
	ldr r1, .L080ADD3C
	ldr r0, .L080ADD40
	str r0, [r1]
	ldr r1, .L080ADD44
	ldr r0, .L080ADD48
	str r0, [r1]
	ldr r1, .L080ADD4C
	ldr r0, [r4, #0x40]
	str r0, [r1]
	ldr r1, .L080ADD50
	ldr r0, .L080ADD54
	str r0, [r1]
	ldr r1, .L080ADD58
	ldr r0, .L080ADD5C
	str r0, [r1]
	cmp r5, #0x1a
	bne .L080ADD64
	movs r0, #0x11
	bl Flag_Test
	cmp r0, #0
	bne .L080ADD64
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, [r0]
	adds r1, #0x80
	ldr r0, .L080ADD60
	b .L080ADD6C
	.byte 0x00, 0x00
.L080ADD2C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080ADD30: .4byte 0x00000A38
.L080ADD34: .4byte 0x03003FC0 @ IWRAM+0x3FC0
.L080ADD38: .4byte 0x0201D874 @ EWRAM+0x1D874
.L080ADD3C: .4byte 0x03003BB0 @ IWRAM+0x3BB0
.L080ADD40: .4byte 0x02024074 @ EWRAM+0x24074
.L080ADD44: .4byte 0x03004604 @ IWRAM+0x4604
.L080ADD48: .4byte 0x0202D874 @ EWRAM+0x2D874
.L080ADD4C: .4byte 0x03003BB4 @ IWRAM+0x3BB4
.L080ADD50: .4byte 0x03003B90 @ IWRAM+0x3B90
.L080ADD54: .4byte 0x0200F874 @ EWRAM+0xF874
.L080ADD58: .4byte 0x03004620 @ IWRAM+0x4620
.L080ADD5C: .4byte 0x02017874 @ EWRAM+0x17874
.L080ADD60: .4byte 0x03004510 @ IWRAM+0x4510
.L080ADD64:
	ldr r0, .L080ADD9C
	adds r1, r4, #0
	adds r1, #0xc0
	ldr r1, [r1]
.L080ADD6C:
	str r1, [r0]
	ldr r1, .L080ADDA0
	ldr r0, .L080ADDA4
	str r0, [r1]
	ldr r1, .L080ADDA8
	adds r0, r4, #0
	adds r0, #0xa0
	ldr r0, [r0]
	str r0, [r1]
	cmp r5, #0x1a
	bne .L080ADDB0
	movs r0, #0x11
	bl Flag_Test
	cmp r0, #0
	bne .L080ADDB0
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, .L080ADDAC
	b .L080ADDB8
.L080ADD9C: .4byte 0x03004510 @ IWRAM+0x4510
.L080ADDA0: .4byte 0x03003B94 @ IWRAM+0x3B94
.L080ADDA4: .4byte 0x02028074 @ EWRAM+0x28074
.L080ADDA8: .4byte 0x0300462C @ IWRAM+0x462C
.L080ADDAC: .4byte 0x03004630 @ IWRAM+0x4630
.L080ADDB0:
	ldr r0, .L080ADDF4
	adds r1, r4, #0
	adds r1, #0xc4
	ldr r1, [r1]
.L080ADDB8:
	str r1, [r0]
	ldr r1, .L080ADDF8
	adds r0, r4, #0
	adds r0, #0xcc
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, .L080ADDFC
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, .L080ADE00
	adds r0, r4, #0
	adds r0, #0xdc
	ldr r0, [r0]
	str r0, [r1]
	cmp r5, #0x1a
	bne .L080ADE08
	movs r0, #0x11
	bl Flag_Test
	cmp r0, #0
	bne .L080ADE08
	adds r0, r4, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r1, #0x80
	ldr r0, .L080ADE04
	b .L080ADE10
	.byte 0x00, 0x00
.L080ADDF4: .4byte 0x03004630 @ IWRAM+0x4630
.L080ADDF8: .4byte 0x0300461C @ IWRAM+0x461C
.L080ADDFC: .4byte 0x03003FE4 @ IWRAM+0x3FE4
.L080ADE00: .4byte 0x03003FE8 @ IWRAM+0x3FE8
.L080ADE04: .4byte 0x03003FC8 @ IWRAM+0x3FC8
.L080ADE08:
	ldr r0, .L080ADE3C
	adds r1, r4, #0
	adds r1, #0xc8
	ldr r1, [r1]
.L080ADE10:
	str r1, [r0]
	ldr r0, .L080ADE40
	ldr r0, [r0]
	ldr r1, .L080ADE44
	movs r2, #0x10
	bl sub_080ADE54
	ldr r0, .L080ADE48
	ldr r0, [r0]
	ldr r1, .L080ADE4C
	movs r2, #0x20
	bl sub_080ADE54
	ldr r0, .L080ADE3C
	ldr r0, [r0]
	ldr r1, .L080ADE50
	movs r2, #0x10
	bl sub_080ADE54
	pop {r4, r5}
	pop {r0}
	bx r0
.L080ADE3C: .4byte 0x03003FC8 @ IWRAM+0x3FC8
.L080ADE40: .4byte 0x03004510 @ IWRAM+0x4510
.L080ADE44: .4byte 0x0200F7F4 @ EWRAM+0xF7F4
.L080ADE48: .4byte 0x03004630 @ IWRAM+0x4630
.L080ADE4C: .4byte 0x0200F814 @ EWRAM+0xF814
.L080ADE50: .4byte 0x0200F854 @ EWRAM+0xF854

	thumb_func_start sub_080ADE54
sub_080ADE54: @ 0x080ADE54
.L080ADE54:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r1, #0
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	movs r5, #0x12
	ldr r3, .L080ADEB4
	str r0, [r3]
	str r4, [r3, #4]
	lsls r0, r6, #1
	asrs r0, r0, #2
	movs r1, #0x84
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r0, .L080ADEB8
	ldr r0, [r0]
	cmp r0, #0x4d
	bne .L080ADE84
	movs r5, #0x17
.L080ADE84:
	movs r2, #0
	cmp r2, r6
	bhs .L080ADF04
	ldr r0, .L080ADEBC
	mov sl, r0
	movs r3, #0xf8
	lsls r3, r3, #2
	mov sb, r3
	ldr r0, .L080ADEC0
	mov r8, r0
	movs r3, #0xf8
	lsls r3, r3, #7
	mov ip, r3
	ldr r7, .L080ADEC4
.L080ADEA0:
	ldrh r1, [r4]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, r5
	blo .L080ADEC8
	subs r0, r1, r5
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b .L080ADECC
	.byte 0x00, 0x00
.L080ADEB4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080ADEB8: .4byte 0x03004614 @ IWRAM+0x4614
.L080ADEBC: .4byte 0x0000FFE0
.L080ADEC0: .4byte 0x0000FC1F
.L080ADEC4: .4byte 0x000083FF
.L080ADEC8:
	mov r0, sl
	ands r1, r0
.L080ADECC:
	adds r0, r1, #0
	mov r3, sb
	ands r0, r3
	lsls r3, r5, #5
	cmp r0, r3
	blt .L080ADEE0
	subs r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b .L080ADEE4
.L080ADEE0:
	mov r0, r8
	ands r1, r0
.L080ADEE4:
	adds r0, r1, #0
	mov r3, ip
	ands r0, r3
	lsls r3, r5, #0xa
	cmp r0, r3
	blt .L080ADEF8
	subs r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b .L080ADEFA
.L080ADEF8:
	ands r1, r7
.L080ADEFA:
	strh r1, [r4]
	adds r2, #1
	adds r4, #2
	cmp r2, r6
	blo .L080ADEA0
.L080ADF04:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080ADF14
sub_080ADF14: @ 0x080ADF14
.L080ADF14:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, .L080ADF28
	ldr r2, .L080ADF2C
.L080ADF1E:
	ldrh r1, [r2]
	cmp r1, r3
	bne .L080ADF30
	movs r0, #0
	b .L080ADF3A
.L080ADF28: .4byte 0x0000FFFF
.L080ADF2C: .4byte gUnknown_0815F2B8
.L080ADF30:
	cmp r1, r0
	beq .L080ADF38
	adds r2, #2
	b .L080ADF1E
.L080ADF38:
	movs r0, #1
.L080ADF3A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080ADF40
sub_080ADF40: @ 0x080ADF40
.L080ADF40:
	push {lr}
	movs r1, #0
	ldr r0, .L080ADF5C
	ldr r0, [r0]
	cmp r0, #0x4a
	bne .L080ADF56
	ldr r0, .L080ADF60
	ldr r0, [r0]
	cmp r0, #4
	bne .L080ADF56
	movs r1, #1
.L080ADF56:
	adds r0, r1, #0
	pop {r1}
	bx r1
.L080ADF5C: .4byte 0x03004614 @ IWRAM+0x4614
.L080ADF60: .4byte 0x03004514 @ IWRAM+0x4514

	thumb_func_start sub_080ADF64
sub_080ADF64: @ 0x080ADF64
.L080ADF64:
	push {lr}
	ldr r0, .L080ADF80
	ldrh r0, [r0]
	bl sub_080ADF14
	cmp r0, #1
	bne .L080ADF94
	ldr r1, .L080ADF84
	ldr r0, .L080ADF88
	str r0, [r1]
	ldr r0, .L080ADF8C
	str r0, [r1, #4]
	ldr r0, .L080ADF90
	b .L080ADFC8
.L080ADF80: .4byte 0x03004614 @ IWRAM+0x4614
.L080ADF84: .4byte 0x040000D4 @ REG_DMA3SAD
.L080ADF88: .4byte gUnknown_081C2270
.L080ADF8C: .4byte 0x06003000 @ VRAM+0x3000
.L080ADF90: .4byte 0x84000140
.L080ADF94:
	bl sub_080ADF40
	cmp r0, #1
	bne .L080ADFBC
	ldr r1, .L080ADFAC
	ldr r0, .L080ADFB0
	str r0, [r1]
	ldr r0, .L080ADFB4
	str r0, [r1, #4]
	ldr r0, .L080ADFB8
	b .L080ADFC8
	.byte 0x00, 0x00
.L080ADFAC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080ADFB0: .4byte gUnknown_0848DE60
.L080ADFB4: .4byte 0x06003000 @ VRAM+0x3000
.L080ADFB8: .4byte 0x84000140
.L080ADFBC:
	ldr r1, .L080ADFD8
	ldr r0, .L080ADFDC
	str r0, [r1]
	ldr r0, .L080ADFE0
	str r0, [r1, #4]
	ldr r0, .L080ADFE4
.L080ADFC8:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, .L080ADFE8
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080ADFD8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080ADFDC: .4byte gUnknown_081C0A70
.L080ADFE0: .4byte 0x06003000 @ VRAM+0x3000
.L080ADFE4: .4byte 0x84000200
.L080ADFE8: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080ADFEC
sub_080ADFEC: @ 0x080ADFEC
.L080ADFEC:
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080AE08C
	ldr r0, [r0]
	ldr r1, .L080AE090
	ldr r1, [r1]
	bl sub_080ADCCC
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, .L080AE094
	add r0, sp, #4
	str r0, [r1]
	ldr r0, .L080AE098
	str r0, [r1, #4]
	ldr r0, .L080AE09C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080AE0A0
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L080AE0A4
	str r0, [r1, #4]
	ldr r0, .L080AE0A8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080AE0AC
	ldr r1, [r0]
	ldr r6, .L080AE0B0
	ldrh r0, [r1]
	strh r0, [r6]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r0, .L080AE0B4
	ldr r1, [r0]
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r6, r0
	str r5, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl sub_080ADF64
	bl sub_080AE1C4
	ldr r0, .L080AE0B8
	ldr r1, [r0]
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	subs r4, #2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #1
	bhi .L080AE082
	bl sub_080B437C
.L080AE082:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AE08C: .4byte 0x03004614 @ IWRAM+0x4614
.L080AE090: .4byte 0x03004514 @ IWRAM+0x4514
.L080AE094: .4byte 0x040000D4 @ REG_DMA3SAD
.L080AE098: .4byte 0x02028074 @ EWRAM+0x28074
.L080AE09C: .4byte 0x85000008
.L080AE0A0: .4byte 0x03003B94 @ IWRAM+0x3B94
.L080AE0A4: .4byte 0x06004000 @ VRAM+0x4000
.L080AE0A8: .4byte 0x84000800
.L080AE0AC: .4byte 0x03004630 @ IWRAM+0x4630
.L080AE0B0: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080AE0B4: .4byte 0x03004510 @ IWRAM+0x4510
.L080AE0B8: .4byte 0x03003FC8 @ IWRAM+0x3FC8

	thumb_func_start sub_080AE0BC
sub_080AE0BC: @ 0x080AE0BC
	push {lr}
	sub sp, #8
	ldr r0, .L080AE0D4
	ldrh r0, [r0]
	cmp r0, #5
	bhi .L080AE196
	lsls r0, r0, #2
	ldr r1, .L080AE0D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080AE0D4: .4byte 0x03003BBC @ IWRAM+0x3BBC
.L080AE0D8: .4byte gUnknown_080AE0DC
	.global gUnknown_080AE0DC
gUnknown_080AE0DC:
.L080AE0DC: @ jump table
	.4byte .L080AE0F4
	.4byte .L080AE134
	.4byte .L080AE15C
	.4byte .L080AE178
	.4byte .L080AE17E
	.4byte .L080AE184
.L080AE0F4:
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, .L080AE11C
	add r0, sp, #4
	str r0, [r1]
	ldr r0, .L080AE120
	str r0, [r1, #4]
	ldr r0, .L080AE124
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080AE128
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L080AE12C
	str r0, [r1, #4]
	ldr r0, .L080AE130
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b .L080AE1B0
	.byte 0x00, 0x00
.L080AE11C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080AE120: .4byte 0x02028074 @ EWRAM+0x28074
.L080AE124: .4byte 0x85000008
.L080AE128: .4byte 0x03003B94 @ IWRAM+0x3B94
.L080AE12C: .4byte 0x06004000 @ VRAM+0x4000
.L080AE130: .4byte 0x84000800
.L080AE134:
	ldr r0, .L080AE154
	ldr r1, [r0]
	ldr r2, .L080AE158
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	b .L080AE1B0
	.byte 0x00, 0x00
.L080AE154: .4byte 0x03004630 @ IWRAM+0x4630
.L080AE158: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080AE15C:
	ldr r0, .L080AE170
	ldr r1, [r0]
	ldr r2, .L080AE174
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	b .L080AE1B0
.L080AE170: .4byte 0x03004510 @ IWRAM+0x4510
.L080AE174: .4byte 0x03002B50 @ IWRAM+0x2B50
.L080AE178:
	bl sub_080ADF64
	b .L080AE1B0
.L080AE17E:
	bl sub_080AE1C4
	b .L080AE1B0
.L080AE184:
	ldr r0, .L080AE1A0
	ldr r1, [r0]
	ldr r2, .L080AE1A4
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
.L080AE196:
	ldr r1, .L080AE1A8
	ldr r2, .L080AE1AC
	adds r0, r2, #0
	b .L080AE1B6
	.byte 0x00, 0x00
.L080AE1A0: .4byte 0x03003FC8 @ IWRAM+0x3FC8
.L080AE1A4: .4byte 0x03002D50 @ IWRAM+0x2D50
.L080AE1A8: .4byte 0x03003BBC @ IWRAM+0x3BBC
.L080AE1AC: .4byte 0x0000FFFF
.L080AE1B0:
	ldr r1, .L080AE1C0
	ldrh r0, [r1]
	adds r0, #1
.L080AE1B6:
	strh r0, [r1]
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AE1C0: .4byte 0x03003BBC @ IWRAM+0x3BBC

	thumb_func_start sub_080AE1C4
sub_080AE1C4: @ 0x080AE1C4
.L080AE1C4:
	push {lr}
	ldr r0, .L080AE1E8
	ldr r0, [r0]
	cmp r0, #0
	beq .L080AE1D4
	ldr r1, .L080AE1EC
	bl LZ77UnCompWram
.L080AE1D4:
	ldr r1, .L080AE1F0
	ldr r0, .L080AE1EC
	str r0, [r1]
	ldr r0, .L080AE1F4
	str r0, [r1, #4]
	ldr r0, .L080AE1F8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r0}
	bx r0
.L080AE1E8: .4byte 0x0300461C @ IWRAM+0x461C
.L080AE1EC: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080AE1F0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080AE1F4: .4byte 0x06015000 @ VRAM+0x15000
.L080AE1F8: .4byte 0x84000400

	thumb_func_start sub_080AE1FC
sub_080AE1FC: @ 0x080AE1FC
	push {lr}
	ldr r0, .L080AE220
	ldr r0, [r0]
	cmp r0, #0
	beq .L080AE20C
	ldr r1, .L080AE224
	bl LZ77UnCompWram
.L080AE20C:
	ldr r1, .L080AE228
	ldr r0, .L080AE224
	str r0, [r1]
	ldr r0, .L080AE22C
	str r0, [r1, #4]
	ldr r0, .L080AE230
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r0}
	bx r0
.L080AE220: .4byte 0x03003FE4 @ IWRAM+0x3FE4
.L080AE224: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080AE228: .4byte 0x040000D4 @ REG_DMA3SAD
.L080AE22C: .4byte 0x06015000 @ VRAM+0x15000
.L080AE230: .4byte 0x84000400

	thumb_func_start sub_080AE234
sub_080AE234: @ 0x080AE234
.L080AE234:
	push {r4, lr}
	sub sp, #8
	ldr r0, .L080AE27C
	ldrh r0, [r0]
	ldr r1, .L080AE280
	ldrh r1, [r1]
	bl sub_080C8B10
	adds r0, #0x90
	ldr r0, [r0]
	ldr r1, .L080AE284
	ldrh r2, [r0]
	movs r4, #0
	strh r2, [r1, #0x1a]
	adds r0, #2
	ldrh r2, [r0]
	strh r2, [r1, #0x1c]
	adds r0, #2
	str r0, [r1, #0x20]
	str r4, [sp]
	adds r1, #0x64
	ldr r2, .L080AE288
	mov r0, sp
	bl CpuSet
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r1, .L080AE28C
	ldr r2, .L080AE290
	bl CpuSet
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AE27C: .4byte 0x03004614 @ IWRAM+0x4614
.L080AE280: .4byte 0x03004514 @ IWRAM+0x4514
.L080AE284: .4byte 0x03004550 @ IWRAM+0x4550
.L080AE288: .4byte 0x05000010 @ PLTT+0x10
.L080AE28C: .4byte 0x0203A3E8 @ EWRAM+0x3A3E8
.L080AE290: .4byte 0x05000014 @ PLTT+0x14

	thumb_func_start sub_080AE294
sub_080AE294: @ 0x080AE294
.L080AE294:
	push {lr}
	movs r0, #0x11
	rsbs r0, r0, #0
	bl sub_080F3F58
	movs r0, #0
	bl sub_080C2230
	pop {r0}
	bx r0

	thumb_func_start sub_080AE2A8
sub_080AE2A8: @ 0x080AE2A8
.L080AE2A8:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, .L080AE2BC
	strh r0, [r2, #0x12]
	strh r0, [r2, #0x16]
	strh r1, [r2, #0x14]
	strh r1, [r2, #0x18]
	bx lr
.L080AE2BC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080AE2C0
sub_080AE2C0: @ 0x080AE2C0
.L080AE2C0:
	ldr r0, .L080AE2CC
	ldrh r1, [r0, #0x12]
	strh r1, [r0, #0x16]
	ldrh r1, [r0, #0x14]
	strh r1, [r0, #0x18]
	bx lr
.L080AE2CC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080AE2D0
sub_080AE2D0: @ 0x080AE2D0
.L080AE2D0:
	push {r4, r5, lr}
	sub sp, #8
	movs r4, #0
	str r4, [sp]
	ldr r1, .L080AE2F8
	ldr r5, .L080AE2FC
	mov r0, sp
	adds r2, r5, #0
	bl CpuSet
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r1, .L080AE300
	adds r2, r5, #0
	bl CpuSet
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
.L080AE2F8: .4byte 0x02036074 @ EWRAM+0x36074
.L080AE2FC: .4byte 0x05000008 @ PLTT+0x8
.L080AE300: .4byte 0x02036094 @ EWRAM+0x36094

	thumb_func_start sub_080AE304
sub_080AE304: @ 0x080AE304
.L080AE304:
	push {r4, lr}
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	ldr r4, .L080AE328
.L080AE312:
	bl sub_080B2CC0
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	bne .L080AE312
	ldr r0, .L080AE32C
	bl sub_080AE494
	pop {r4}
	pop {r0}
	bx r0
.L080AE328: .4byte 0x03004550 @ IWRAM+0x4550
.L080AE32C: .4byte sub_080B2880

	thumb_func_start sub_080AE330
sub_080AE330: @ 0x080AE330
.L080AE330:
	push {lr}
	ldr r0, .L080AE34C
	ldr r1, .L080AE350
	ldr r2, .L080AE354
	bl CpuSet
	ldr r0, .L080AE358
	ldr r1, .L080AE35C
	ldr r2, .L080AE360
	bl CpuSet
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AE34C: .4byte sub_080B210C
.L080AE350: .4byte 0x03003BC0 @ IWRAM+0x3BC0
.L080AE354: .4byte 0x04000100 @ REG_TM0CNT
.L080AE358: .4byte sub_080B23D0
.L080AE35C: .4byte 0x03004010 @ IWRAM+0x4010
.L080AE360: .4byte 0x04000140 @ IO+0x140

	thumb_func_start sub_080AE364
sub_080AE364: @ 0x080AE364
.L080AE364:
	push {r4, r5, lr}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L080AE3BC
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080AE3C0
	strh r1, [r0]
	bl sub_080AE2D0
	bl sub_080AE330
	cmp r4, #0
	beq .L080AE38A
	cmp r4, #4
	beq .L080AE38A
	cmp r4, #6
	bne .L080AE480
.L080AE38A:
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, .L080AE3C4
	add r0, sp, #4
	str r0, [r1]
	ldr r5, .L080AE3C8
	str r5, [r1, #4]
	ldr r0, .L080AE3CC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080AE234
	cmp r4, #0
	bne .L080AE3D4
	movs r0, #0
	movs r1, #0
	bl sub_080AE2A8
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	ldr r0, .L080AE3D0
	ldrh r0, [r0]
	bl sub_080B30A0
	b .L080AE3E4
.L080AE3BC: .4byte 0x03003B9C @ IWRAM+0x3B9C
.L080AE3C0: .4byte 0x03004608 @ IWRAM+0x4608
.L080AE3C4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080AE3C8: .4byte 0x03004550 @ IWRAM+0x4550
.L080AE3CC: .4byte 0x85000029
.L080AE3D0: .4byte 0x03004614 @ IWRAM+0x4614
.L080AE3D4:
	ldr r4, .L080AE464
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #6]
	bl sub_080AE2A8
	ldrh r0, [r4, #8]
	strh r0, [r5, #2]
	strh r0, [r5, #4]
.L080AE3E4:
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl sub_080B3078
	cmp r0, #1
	bne .L080AE432
	ldr r1, .L080AE468
	ldr r5, .L080AE46C
	ldrh r0, [r1]
	strh r0, [r5]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r1, .L080AE470
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r5, r0
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080AE474
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
.L080AE432:
	ldr r4, .L080AE478
	ldrh r0, [r4, #0x12]
	ldrh r1, [r4, #0x14]
	bl sub_080AF4EC
	ldrh r0, [r4, #0x12]
	ldrh r1, [r4, #0x14]
	ldrh r2, [r4, #2]
	bl sub_080AF5B8
	ldr r1, .L080AE47C
	movs r0, #1
	str r0, [r1]
	movs r0, #0xa
	strh r0, [r4]
	bl sub_080AE304
	bl sub_080C20C8
	ldr r0, .L080AE46C
	movs r1, #7
	bl sub_080C67C0
	b .L080AE486
	.byte 0x00, 0x00
.L080AE464: .4byte 0x03003FD0 @ IWRAM+0x3FD0
.L080AE468: .4byte 0x0200F814 @ EWRAM+0xF814
.L080AE46C: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080AE470: .4byte 0x0200F7F4 @ EWRAM+0xF7F4
.L080AE474: .4byte 0x0200F854 @ EWRAM+0xF854
.L080AE478: .4byte 0x03004550 @ IWRAM+0x4550
.L080AE47C: .4byte 0x030045FC @ IWRAM+0x45FC
.L080AE480:
	ldr r1, .L080AE490
	movs r0, #0xa
	strh r0, [r1]
.L080AE486:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AE490: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080AE494
sub_080AE494: @ 0x080AE494
.L080AE494:
	push {lr}
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r1, .L080AE4A8
	movs r0, #1
	strh r0, [r1, #0xc]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AE4A8: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080AE4AC
sub_080AE4AC: @ 0x080AE4AC
.L080AE4AC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r8, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r5, r1, #0
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	lsls r0, r4, #0x10
	cmp r0, #0
	blt .L080AE4E4
	ldr r3, .L080AE4F8
	ldrh r0, [r3, #0x1a]
	cmp r4, r0
	bhs .L080AE4E4
	lsls r0, r1, #0x10
	cmp r0, #0
	blt .L080AE4E4
	ldrh r0, [r3, #0x1c]
	cmp r1, r0
	blo .L080AE500
.L080AE4E4:
	ldr r2, .L080AE4FC
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	movs r1, #0x6c
	muls r1, r7, r1
	adds r0, r0, r1
	adds r0, r0, r2
	movs r1, #0
	b .L080AE55C
.L080AE4F8: .4byte 0x03004550 @ IWRAM+0x4550
.L080AE4FC: .4byte 0x0200AB08 @ EWRAM+0xAB08
.L080AE500:
	ldrh r2, [r3, #2]
	ldrh r0, [r3, #0x1a]
	muls r0, r5, r0
	add r0, r8
	ldr r1, [r3, #0x20]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r8, r0
	movs r5, #0
	ldr r1, .L080AE56C
	mov sl, r1
	lsls r0, r6, #1
	mov ip, r0
	adds r1, r0, r6
	lsls r1, r1, #2
	movs r0, #0x6c
	muls r0, r7, r0
	adds r0, #4
	adds r1, r1, r0
	mov r0, sl
	adds r3, r1, r0
	ldr r1, .L080AE570
	mov sb, r1
	movs r4, #3
.L080AE532:
	lsls r1, r2, #1
	add r1, sb
	mov r0, r8
	ldrh r1, [r1]
	asrs r0, r1
	ands r0, r4
	strh r0, [r3]
	adds r2, #1
	ands r2, r4
	adds r3, #2
	adds r5, #1
	cmp r5, #3
	bls .L080AE532
	mov r1, ip
	adds r0, r1, r6
	lsls r0, r0, #2
	movs r1, #0x6c
	muls r1, r7, r1
	adds r0, r0, r1
	add r0, sl
	movs r1, #1
.L080AE55C:
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080AE56C: .4byte 0x0200AB08 @ EWRAM+0xAB08
.L080AE570: .4byte gUnknown_0815F2E6

	thumb_func_start sub_080AE574
sub_080AE574: @ 0x080AE574
.L080AE574:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	str r1, [sp, #4]
	ldr r0, .L080AE5B4
	ldrh r7, [r0, #0x12]
	ldrh r6, [r0, #0x14]
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080AE5B8
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080AE5BC
	str r0, [r1, #4]
	ldr r0, .L080AE5C0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r1, r8
	cmp r1, #1
	beq .L080AE5CE
	cmp r1, #1
	blo .L080AE5C4
	cmp r1, #2
	beq .L080AE5D8
	cmp r1, #3
	beq .L080AE5E2
	b .L080AE5EE
	.byte 0x00, 0x00
.L080AE5B4: .4byte 0x03004550 @ IWRAM+0x4550
.L080AE5B8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080AE5BC: .4byte 0x0200AB08 @ EWRAM+0xAB08
.L080AE5C0: .4byte 0x850000F3
.L080AE5C4:
	subs r0, r7, #4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	subs r0, r6, #5
	b .L080AE5EA
.L080AE5CE:
	adds r0, r7, #5
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	subs r0, r6, #4
	b .L080AE5EA
.L080AE5D8:
	adds r0, r7, #4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r6, #5
	b .L080AE5EA
.L080AE5E2:
	subs r0, r7, #5
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r6, #4
.L080AE5EA:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080AE5EE:
	movs r5, #0
	cmp r5, #9
	bhs .L080AE674
.L080AE5F4:
	movs r4, #0
	adds r2, r5, #1
	str r2, [sp, #8]
	cmp r4, #9
	bhs .L080AE66A
	adds r0, r6, r5
	lsls r0, r0, #0x10
	mov sl, r0
	subs r0, r7, r5
	lsls r0, r0, #0x10
	mov sb, r0
.L080AE60A:
	mov r3, r8
	cmp r3, #1
	beq .L080AE62A
	cmp r3, #1
	blo .L080AE61E
	cmp r3, #2
	beq .L080AE636
	cmp r3, #3
	beq .L080AE64C
	b .L080AE660
.L080AE61E:
	adds r0, r7, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, sl
	lsrs r1, r2, #0x10
	b .L080AE642
.L080AE62A:
	adds r1, r6, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, sb
	lsrs r0, r3, #0x10
	b .L080AE642
.L080AE636:
	subs r0, r7, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r6, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
.L080AE642:
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080AE4AC
	b .L080AE660
.L080AE64C:
	adds r0, r7, r5
	lsls r0, r0, #0x10
	subs r1, r6, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsrs r0, r0, #0x10
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080AE4AC
.L080AE660:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #9
	blo .L080AE60A
.L080AE66A:
	ldr r1, [sp, #8]
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #9
	blo .L080AE5F4
.L080AE674:
	ldr r2, [sp, #4]
	cmp r2, #0
	beq .L080AE67C
	b .L080AECB0
.L080AE67C:
	bl sub_080ADF40
	cmp r0, #0
	beq .L080AE686
	b .L080AECB0
.L080AE686:
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE6A2
	ldr r2, .L080AE9B8
	movs r0, #3
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE6F8
.L080AE6A2:
	ldr r4, .L080AE9B8
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE6C0
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE6F8
.L080AE6C0:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE6DC
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE6F8
.L080AE6DC:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE70A
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE70A
.L080AE6F8:
	ldr r2, .L080AE9BC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r1, #0
	strh r1, [r0]
	subs r3, #0x68
	adds r0, r2, r3
	strh r1, [r0]
.L080AE70A:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE726
	ldr r2, .L080AE9B8
	movs r0, #1
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE77A
.L080AE726:
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE742
	ldr r2, .L080AE9B8
	movs r0, #1
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE77A
.L080AE742:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE75E
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE77A
.L080AE75E:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE78E
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE78E
.L080AE77A:
	ldr r2, .L080AE9BC
	movs r1, #0xf8
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
.L080AE78E:
	ldr r4, .L080AE9B8
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE7AC
	ldr r2, .L080AE9C0
	movs r0, #3
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE800
.L080AE7AC:
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE7C8
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE800
.L080AE7C8:
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE7E4
	movs r0, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE800
.L080AE7E4:
	movs r0, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE814
	ldr r2, .L080AE9C0
	movs r0, #3
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE814
.L080AE800:
	ldr r2, .L080AE9BC
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
.L080AE814:
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE830
	ldr r2, .L080AE9B8
	movs r0, #3
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE8A2
.L080AE830:
	ldr r4, .L080AE9B8
	movs r0, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE84E
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE8A2
.L080AE84E:
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE86A
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE8A2
.L080AE86A:
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE886
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE8A2
.L080AE886:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE8B2
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE8B2
.L080AE8A2:
	ldr r0, .L080AE9BC
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	adds r0, #0xf8
	strh r2, [r0]
.L080AE8B2:
	ldr r4, .L080AE9B8
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE8D0
	ldr r2, .L080AE9C0
	movs r0, #1
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE924
.L080AE8D0:
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE8EC
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE924
.L080AE8EC:
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE908
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE924
.L080AE908:
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE936
	ldr r2, .L080AE9C0
	movs r0, #1
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE936
.L080AE924:
	ldr r2, .L080AE9BC
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r1, #0
	strh r1, [r0]
	subs r3, #0x68
	adds r0, r2, r3
	strh r1, [r0]
.L080AE936:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE952
	ldr r2, .L080AE9B8
	movs r0, #1
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE9D4
.L080AE952:
	ldr r4, .L080AE9B8
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE970
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE9D4
.L080AE970:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE98C
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE9D4
.L080AE98C:
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE9A8
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AE9D4
.L080AE9A8:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	b .L080AE9C4
	.byte 0x00, 0x00
.L080AE9B8: .4byte 0x0000FFFF
.L080AE9BC: .4byte 0x0200AB08 @ EWRAM+0xAB08
.L080AE9C0: .4byte 0x0000FFFE
.L080AE9C4:
	beq .L080AE9E8
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AE9E8
.L080AE9D4:
	ldr r2, .L080AECC0
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
.L080AE9E8:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEA04
	ldr r1, .L080AECC4
	movs r0, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AEA3E
.L080AEA04:
	ldr r4, .L080AECC4
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEA22
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AEA3E
.L080AEA22:
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEA52
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEA52
.L080AEA3E:
	ldr r1, .L080AECC0
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
.L080AEA52:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEA6E
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AEAA6
.L080AEA6E:
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEA8A
	ldr r2, .L080AECC4
	movs r0, #1
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AEAA6
.L080AEA8A:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEABA
	ldr r2, .L080AECC4
	movs r0, #1
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEABA
.L080AEAA6:
	ldr r1, .L080AECC0
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r0, #0
	strh r0, [r2]
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
.L080AEABA:
	ldr r4, .L080AECC4
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEAD8
	movs r0, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AEB1E
.L080AEAD8:
	movs r0, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEAF4
	ldr r2, .L080AECC8
	movs r0, #3
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AEB1E
.L080AEAF4:
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEB10
	ldr r2, .L080AECC8
	movs r0, #3
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AEB1E
.L080AEB10:
	ldr r2, .L080AECC8
	movs r0, #0
	adds r1, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEB2E
.L080AEB1E:
	ldr r0, .L080AECC0
	movs r3, #0x83
	lsls r3, r3, #1
	adds r2, r0, r3
	movs r1, #0
	strh r1, [r2]
	adds r0, #0xf6
	strh r1, [r0]
.L080AEB2E:
	ldr r4, .L080AECC4
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEB4C
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AEB92
.L080AEB4C:
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEB68
	ldr r2, .L080AECC8
	movs r0, #1
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AEB92
.L080AEB68:
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEB84
	ldr r2, .L080AECC8
	movs r0, #1
	movs r1, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080AEB92
.L080AEB84:
	ldr r2, .L080AECC8
	movs r0, #0
	movs r1, #1
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEBA6
.L080AEB92:
	ldr r1, .L080AECC0
	movs r0, #0x8d
	lsls r0, r0, #1
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	movs r2, #0x95
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
.L080AEBA6:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEBE0
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEBE0
	ldr r2, .L080AECC0
	movs r3, #0xb9
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #0
	strh r0, [r1]
	subs r3, #0x10
	adds r1, r2, r3
	strh r0, [r1]
	subs r3, #2
	adds r1, r2, r3
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0xf8
	strh r0, [r1]
.L080AEBE0:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEC1C
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEC1C
	ldr r2, .L080AECC0
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r1, r2, r3
	strh r0, [r1]
	subs r3, #6
	adds r1, r2, r3
	strh r0, [r1]
	subs r3, #0x68
	adds r1, r2, r3
	strh r0, [r1]
.L080AEC1C:
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEC3C
	ldr r0, .L080AECC0
	ldr r2, .L080AECCC
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r2, [r0]
.L080AEC3C:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEC5C
	ldr r0, .L080AECC0
	ldr r2, .L080AECD0
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r2, [r0]
.L080AEC5C:
	ldr r4, .L080AECC4
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEC86
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AEC86
	ldr r0, .L080AECC0
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0
	strh r0, [r1]
.L080AEC86:
	ldr r4, .L080AECC4
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AECB0
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080AECB0
	ldr r0, .L080AECC0
	movs r3, #0x8d
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #0
	strh r0, [r1]
.L080AECB0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080AECC0: .4byte 0x0200AB08 @ EWRAM+0xAB08
.L080AECC4: .4byte 0x0000FFFF
.L080AECC8: .4byte 0x0000FFFE
.L080AECCC: .4byte 0x0000024A
.L080AECD0: .4byte 0x0000025E

	thumb_func_start sub_080AECD4
sub_080AECD4: @ 0x080AECD4
.L080AECD4:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r3, #2
	adds r4, r4, r3
	lsls r4, r4, #2
	adds r4, r4, r3
	lsls r4, r4, #4
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	ldr r2, .L080AED20
	adds r1, r1, r2
	adds r4, r4, r1
	lsrs r1, r0, #0x10
	mov r8, r1
	cmp r0, #0
	blt .L080AED1C
	ldr r6, .L080AED24
	ldrh r2, [r6, #0x1a]
	cmp r8, r2
	bhs .L080AED1C
	lsls r0, r5, #0x10
	cmp r0, #0
	blt .L080AED1C
	ldrh r0, [r6, #0x1c]
	cmp r5, r0
	blo .L080AED28
.L080AED1C:
	movs r0, #0
	b .L080AEDA2
.L080AED20: .4byte 0x02005000 @ EWRAM+0x5000
.L080AED24: .4byte 0x03004550 @ IWRAM+0x4550
.L080AED28:
	mov r0, r8
	adds r1, r5, #0
	bl sub_080AF620
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080AEDA4
	bl sub_080B447C
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r6, #0x1a]
	muls r0, r5, r0
	add r0, r8
	ldr r1, [r6, #0x20]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	mov ip, r0
	movs r6, #0
	ldr r1, .L080AEDB0
	mov sb, r1
	movs r7, #3
	adds r2, r4, #4
.L080AED58:
	lsls r0, r3, #1
	add r0, sb
	mov r1, ip
	ldrh r0, [r0]
	asrs r1, r0
	ands r1, r7
	strh r1, [r2]
	mov r0, r8
	strb r0, [r4, #2]
	strb r5, [r4, #3]
	ldrh r0, [r2]
	cmp r0, #3
	bne .L080AED76
	movs r0, #2
	strh r0, [r2]
.L080AED76:
	adds r3, #1
	ands r3, r7
	adds r2, #2
	adds r6, #1
	cmp r6, #3
	bls .L080AED58
	movs r0, #1
	strh r0, [r4]
	mov r0, r8
	adds r1, r5, #0
	bl sub_080B3000
	movs r1, #6
	bl sub_080B3038
	cmp r0, #0
	beq .L080AEDA4
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r0, r1
.L080AEDA2:
	strh r0, [r4]
.L080AEDA4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080AEDB0: .4byte gUnknown_0815F2E6

	thumb_func_start sub_080AEDB4
sub_080AEDB4: @ 0x080AEDB4
.L080AEDB4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	ldr r0, .L080AEDF8
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080AEDFC
	strh r1, [r0]
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080AEE00
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080AEE04
	str r0, [r1, #4]
	ldr r0, .L080AEE08
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r1, r8
	cmp r1, #1
	beq .L080AEE12
	cmp r1, #1
	blo .L080AEE0C
	cmp r1, #2
	beq .L080AEE18
	cmp r1, #3
	beq .L080AEE1E
	b .L080AEE22
.L080AEDF8: .4byte 0x0200DFC8 @ EWRAM+0xDFC8
.L080AEDFC: .4byte 0x0200DFCA @ EWRAM+0xDFCA
.L080AEE00: .4byte 0x040000D4 @ REG_DMA3SAD
.L080AEE04: .4byte 0x02005000 @ EWRAM+0x5000
.L080AEE08: .4byte 0x8500039C
.L080AEE0C:
	subs r7, #0xd
	subs r6, #5
	b .L080AEE22
.L080AEE12:
	adds r7, #5
	subs r6, #0xd
	b .L080AEE22
.L080AEE18:
	adds r7, #0xd
	adds r6, #5
	b .L080AEE22
.L080AEE1E:
	subs r7, #5
	adds r6, #0xd
.L080AEE22:
	movs r5, #0
	cmp r5, #0xb
	bhs .L080AEEBA
.L080AEE28:
	movs r4, #0
	adds r2, r5, #1
	mov sl, r2
	cmp r4, #0x1c
	bhs .L080AEEB0
	ldr r3, .L080AEE4C
	mov sb, r3
.L080AEE36:
	mov r0, r8
	cmp r0, #1
	beq .L080AEE60
	cmp r0, #1
	blo .L080AEE50
	cmp r0, #2
	beq .L080AEE70
	cmp r0, #3
	beq .L080AEE8C
	b .L080AEEA6
	.byte 0x00, 0x00
.L080AEE4C: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080AEE50:
	adds r0, r4, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, r6
	mov r3, sb
	ldrh r2, [r3]
	subs r1, r1, r2
	b .L080AEE7E
.L080AEE60:
	subs r0, r7, r5
	mov r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, r6
	b .L080AEE7E
.L080AEE70:
	subs r0, r7, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r6, r5
	mov r2, sb
	ldrh r2, [r2]
	adds r1, r1, r2
.L080AEE7E:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080AECD4
	b .L080AEEA6
.L080AEE8C:
	adds r0, r5, r7
	mov r3, sb
	ldrh r1, [r3]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r6, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080AECD4
.L080AEEA6:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x1c
	blo .L080AEE36
.L080AEEB0:
	mov r1, sl
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xb
	blo .L080AEE28
.L080AEEBA:
	mov r2, r8
	cmp r2, #1
	beq .L080AEEEC
	cmp r2, #1
	blo .L080AEECE
	cmp r2, #2
	beq .L080AEF28
	cmp r2, #3
	beq .L080AEF5C
	b .L080AEF8A
.L080AEECE:
	ldr r1, .L080AEEE4
	ldrh r0, [r1, #0x1c]
	cmp r0, #0xb
	bls .L080AEF8A
	ldr r0, .L080AEEE8
	ldrh r0, [r0]
	subs r0, r6, r0
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	ldrh r0, [r1, #0x1c]
	b .L080AEF70
.L080AEEE4: .4byte 0x03004550 @ IWRAM+0x4550
.L080AEEE8: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080AEEEC:
	ldr r2, .L080AEF18
	ldrh r0, [r2, #0x1a]
	cmp r0, #0xb
	bls .L080AEF8A
	ldr r0, .L080AEF1C
	ldrh r0, [r0]
	adds r0, r0, r7
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #8
	ble .L080AEF08
	ldr r0, .L080AEF20
	mov r3, r8
	strh r3, [r0]
.L080AEF08:
	ldrh r0, [r2, #0x1a]
	adds r0, #1
	cmp r1, r0
	bge .L080AEF8A
	ldr r0, .L080AEF24
	mov r1, r8
	strh r1, [r0]
	b .L080AEF8A
.L080AEF18: .4byte 0x03004550 @ IWRAM+0x4550
.L080AEF1C: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080AEF20: .4byte 0x0200DFC8 @ EWRAM+0xDFC8
.L080AEF24: .4byte 0x0200DFCA @ EWRAM+0xDFCA
.L080AEF28:
	ldr r3, .L080AEF50
	ldrh r0, [r3, #0x1c]
	cmp r0, #0xb
	bls .L080AEF8A
	ldr r0, .L080AEF54
	ldrh r0, [r0]
	adds r0, r0, r6
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #8
	ble .L080AEF44
	ldr r1, .L080AEF58
	movs r0, #1
	strh r0, [r1]
.L080AEF44:
	ldrh r0, [r3, #0x1c]
	adds r0, #1
	cmp r2, r0
	bge .L080AEF8A
	b .L080AEF84
	.byte 0x00, 0x00
.L080AEF50: .4byte 0x03004550 @ IWRAM+0x4550
.L080AEF54: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080AEF58: .4byte 0x0200DFC8 @ EWRAM+0xDFC8
.L080AEF5C:
	ldr r1, .L080AEF9C
	ldrh r0, [r1, #0x1a]
	cmp r0, #0xb
	bls .L080AEF8A
	ldr r0, .L080AEFA0
	ldrh r0, [r0]
	subs r0, r7, r0
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	ldrh r0, [r1, #0x1a]
.L080AEF70:
	subs r0, #9
	cmp r2, r0
	bge .L080AEF7C
	ldr r1, .L080AEFA4
	movs r0, #1
	strh r0, [r1]
.L080AEF7C:
	movs r0, #2
	rsbs r0, r0, #0
	cmp r2, r0
	ble .L080AEF8A
.L080AEF84:
	ldr r1, .L080AEFA8
	movs r0, #1
	strh r0, [r1]
.L080AEF8A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AEF9C: .4byte 0x03004550 @ IWRAM+0x4550
.L080AEFA0: .4byte 0x0200DFCC @ EWRAM+0xDFCC
.L080AEFA4: .4byte 0x0200DFC8 @ EWRAM+0xDFC8
.L080AEFA8: .4byte 0x0200DFCA @ EWRAM+0xDFCA

	thumb_func_start sub_080AEFAC
sub_080AEFAC: @ 0x080AEFAC
	ldr r1, .L080AEFC0
	ldr r0, .L080AEFC4
	str r0, [r1]
	ldr r0, .L080AEFC8
	str r0, [r1, #4]
	ldr r0, .L080AEFCC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080AEFC0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080AEFC4: .4byte gUnknown_081B28B8
.L080AEFC8: .4byte 0x06011500 @ VRAM+0x11500
.L080AEFCC: .4byte 0x84000100

	thumb_func_start sub_080AEFD0
sub_080AEFD0: @ 0x080AEFD0
.L080AEFD0:
	push {lr}
	movs r0, #0x16
	bl Field_SetState
	ldr r0, .L080AEFF4
	movs r1, #0
	strh r1, [r0, #0x1e]
	bl sub_080C7234
	bl sub_080C7430
	ldr r0, .L080AEFF8
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AEFF4: .4byte 0x03004550 @ IWRAM+0x4550
.L080AEFF8: .4byte sub_080AEFAC

	thumb_func_start sub_080AEFFC
sub_080AEFFC: @ 0x080AEFFC
.L080AEFFC:
	push {lr}
	movs r0, #0
	bl sub_080C2230
	bl sub_080AEFD0
	ldr r0, .L080AF014
	adds r0, #0x44
	movs r1, #0
	strh r1, [r0]
	pop {r0}
	bx r0
.L080AF014: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080AF018
sub_080AF018: @ 0x080AF018
.L080AF018:
	push {lr}
	movs r0, #0
	bl sub_080C2230
	bl sub_080AEFD0
	ldr r0, .L080AF030
	adds r0, #0x44
	movs r1, #1
	strh r1, [r0]
	pop {r0}
	bx r0
.L080AF030: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080AF034
sub_080AF034: @ 0x080AF034
.L080AF034:
	push {lr}
	ldr r1, .L080AF044
	movs r0, #0
	str r0, [r1]
	bl sub_080B628C
	pop {r0}
	bx r0
.L080AF044: .4byte 0x03003BB8 @ IWRAM+0x3BB8

	thumb_func_start sub_080AF048
sub_080AF048: @ 0x080AF048
	push {lr}
	movs r0, #0x14
	bl Field_SetState
	ldr r1, .L080AF05C
	movs r0, #0
	strh r0, [r1, #0x1e]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AF05C: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080AF060
sub_080AF060: @ 0x080AF060
.L080AF060:
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L080AF07C
	cmp r4, r0
	bne .L080AF08A
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r5, #0
	bl Flag_Test
	cmp r0, #0
	beq .L080AF084
	ldr r4, .L080AF080
	b .L080AF08A
.L080AF07C: .4byte gUnknown_08072766
.L080AF080: .4byte gUnknown_08072B3A
.L080AF084:
	adds r0, r5, #0
	bl Flag_Set
.L080AF08A:
	cmp r4, #0
	bne .L080AF09C
	ldr r0, .L080AF098
	movs r1, #0
	bl sub_0813E184
	b .L080AF0A4
.L080AF098: .4byte gUnknown_0815F2EE
.L080AF09C:
	adds r0, r4, #0
	movs r1, #0
	bl sub_0813E184
.L080AF0A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080AF0AC
sub_080AF0AC: @ 0x080AF0AC
.L080AF0AC:
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0
	bl sub_080B2EFC
	movs r1, #0x23
	bl sub_080B3038
	bl sub_080B721C
	cmp r0, #0
	bne .L080AF170
	ldr r0, .L080AF124
	cmp r4, r0
	bne .L080AF0DA
	movs r0, #0x80
	lsls r0, r0, #1
	bl Flag_Test
	cmp r0, #0
	beq .L080AF0DA
	ldr r4, .L080AF128
.L080AF0DA:
	ldr r0, .L080AF12C
	cmp r4, r0
	bne .L080AF130
	movs r5, #0
	movs r4, #4
.L080AF0E4:
	adds r0, r4, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L080AF0F0
	adds r5, #1
.L080AF0F0:
	adds r4, #1
	cmp r4, #0xf
	ble .L080AF0E4
	cmp r5, #0
	beq .L080AF154
	bl sub_0814E8B0
	cmp r0, #0
	beq .L080AF154
	movs r0, #0xca
	bl Flag_Test
	cmp r0, #0
	bne .L080AF154
	movs r0, #0xca
	bl Flag_Set
	bl sub_080C2244
	movs r1, #0xff
	ands r1, r0
	cmp r1, #7
	bhi .L080AF154
	movs r0, #2
	b .L080AF172
	.byte 0x00, 0x00
.L080AF124: .4byte gUnknown_08072766
.L080AF128: .4byte gUnknown_08072B3A
.L080AF12C: .4byte gUnknown_080775A6
.L080AF130:
	ldr r0, .L080AF158
	cmp r4, r0
	bne .L080AF142
	bl sub_080C2244
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L080AF154
.L080AF142:
	ldr r0, .L080AF15C
	cmp r4, r0
	bne .L080AF160
	bl sub_080C2244
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	beq .L080AF160
.L080AF154:
	movs r0, #0
	b .L080AF172
.L080AF158: .4byte gUnknown_08052210
.L080AF15C: .4byte gUnknown_080522F8
.L080AF160:
	cmp r4, #0
	beq .L080AF170
	adds r0, r4, #0
	bl ScriptVM_RunAlt
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L080AF172
.L080AF170:
	movs r0, #1
.L080AF172:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080AF178
sub_080AF178: @ 0x080AF178
.L080AF178:
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r1, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	bl sub_0813EB78
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L080AF1B2
	ldr r0, .L080AF1BC
	str r4, [r0]
	ldr r0, .L080AF1C0
	str r5, [r0]
	str r4, [sp]
	ldr r1, .L080AF1C4
	ldr r2, .L080AF1C8
	mov r0, sp
	bl CpuSet
	ldr r0, .L080AF1CC
	strh r4, [r0]
	adds r0, r6, #0
	bl sub_080AF060
	movs r0, #0x19
	bl Field_SetState
.L080AF1B2:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AF1BC: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080AF1C0: .4byte 0x03004530 @ IWRAM+0x4530
.L080AF1C4: .4byte 0x02036094 @ EWRAM+0x36094
.L080AF1C8: .4byte 0x05000008 @ PLTT+0x8
.L080AF1CC: .4byte 0x0203DB7A @ EWRAM+0x3DB7A

	thumb_func_start sub_080AF1D0
sub_080AF1D0: @ 0x080AF1D0
.L080AF1D0:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, .L080AF1E4
	movs r2, #0
	str r2, [r3]
	bl sub_080B6308
	pop {r0}
	bx r0
.L080AF1E4: .4byte 0x03003BB8 @ IWRAM+0x3BB8

	thumb_func_start sub_080AF1E8
sub_080AF1E8: @ 0x080AF1E8
.L080AF1E8:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L080AF20C
	movs r3, #0
	str r3, [r2]
	ldr r2, .L080AF210
	str r0, [r2]
	ldr r0, .L080AF214
	strh r3, [r0]
	adds r0, r1, #0
	bl sub_080AF060
	movs r0, #0x19
	bl Field_SetState
	pop {r0}
	bx r0
.L080AF20C: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080AF210: .4byte 0x03004530 @ IWRAM+0x4530
.L080AF214: .4byte 0x0203DB7A @ EWRAM+0x3DB7A

	thumb_func_start sub_080AF218
sub_080AF218: @ 0x080AF218
.L080AF218:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, .L080AF240
	movs r2, #0
	str r2, [r3]
	ldr r2, .L080AF244
	str r0, [r2]
	ldr r2, .L080AF248
	movs r0, #1
	strh r0, [r2]
	adds r0, r1, #0
	bl sub_080AF060
	movs r0, #0x19
	bl Field_SetState
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AF240: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080AF244: .4byte 0x03004530 @ IWRAM+0x4530
.L080AF248: .4byte 0x0203DB7A @ EWRAM+0x3DB7A

	thumb_func_start sub_080AF24C
sub_080AF24C: @ 0x080AF24C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, .L080AF274
	movs r2, #0
	str r2, [r3]
	ldr r2, .L080AF278
	str r0, [r2]
	ldr r2, .L080AF27C
	movs r0, #2
	strh r0, [r2]
	adds r0, r1, #0
	bl sub_080AF060
	movs r0, #0x19
	bl Field_SetState
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AF274: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080AF278: .4byte 0x03004530 @ IWRAM+0x4530
.L080AF27C: .4byte 0x0203DB7A @ EWRAM+0x3DB7A

	thumb_func_start sub_080AF280
sub_080AF280: @ 0x080AF280
.L080AF280:
	push {r4, lr}
	sub sp, #4
	movs r4, #0
	str r4, [sp]
	ldr r1, .L080AF2AC
	ldr r2, .L080AF2B0
	mov r0, sp
	bl CpuSet
	ldr r0, .L080AF2B4
	strh r4, [r0]
	ldr r0, .L080AF2B8
	ldr r0, [r0]
	bl sub_080AF060
	movs r0, #0x19
	bl Field_SetState
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080AF2AC: .4byte 0x02036094 @ EWRAM+0x36094
.L080AF2B0: .4byte 0x05000008 @ PLTT+0x8
.L080AF2B4: .4byte 0x0203DB7A @ EWRAM+0x3DB7A
.L080AF2B8: .4byte 0x0300453C @ IWRAM+0x453C

	thumb_func_start sub_080AF2BC
sub_080AF2BC: @ 0x080AF2BC
.L080AF2BC:
	push {r4, lr}
	movs r4, #0
	movs r0, #0
	movs r1, #0
	movs r2, #0x13
	bl sub_080B3078
	cmp r0, #1
	beq .L080AF2DC
	movs r0, #0
	movs r1, #0
	movs r2, #0x1e
	bl sub_080B3078
	cmp r0, #1
	bne .L080AF2DE
.L080AF2DC:
	movs r4, #1
.L080AF2DE:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080AF2E8
sub_080AF2E8: @ 0x080AF2E8
.L080AF2E8:
	push {lr}
	ldr r0, .L080AF2FC
	bl Flag_Clear
	movs r0, #1
	bl Field_SetState
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AF2FC: .4byte 0x00000101

	thumb_func_start sub_080AF300
sub_080AF300: @ 0x080AF300
.L080AF300:
	push {lr}
	movs r0, #1
	bl sub_080C3818
	ldr r0, .L080AF338
	ldrh r0, [r0]
	ldr r1, .L080AF33C
	ldrh r1, [r1]
	bl sub_080AD608
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C5170
	bl sub_080AE234
	ldr r0, .L080AF340
	ldrh r0, [r0, #2]
	movs r1, #0
	bl sub_080AE574
	bl sub_080B098C
	cmp r0, #1
	bne .L080AF344
.L080AF332:
	bl sub_080AF2E8
	b .L080AF3F8
.L080AF338: .4byte 0x03004614 @ IWRAM+0x4614
.L080AF33C: .4byte 0x03004514 @ IWRAM+0x4514
.L080AF340: .4byte 0x03004550 @ IWRAM+0x4550
.L080AF344:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #1
	bne .L080AF380
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #1
	bne .L080AF380
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #1
	bne .L080AF380
	ldr r0, .L080AF37C
	bl Flag_Test
	cmp r0, #0
	beq .L080AF3D8
	b .L080AF332
	.byte 0x00, 0x00
.L080AF37C: .4byte 0x00000101
.L080AF380:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #3
	bne .L080AF3B0
	bl sub_080AF2BC
	cmp r0, #1
	bne .L080AF332
	bl sub_080B78DC
	cmp r0, #0
	bne .L080AF332
	ldr r0, .L080AF3AC
	bl Flag_Test
	cmp r0, #0
	beq .L080AF3D8
	b .L080AF332
	.byte 0x00, 0x00
.L080AF3AC: .4byte 0x00000101
.L080AF3B0:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #2
	bne .L080AF3F4
	bl sub_080B78DC
	cmp r0, #0
	bne .L080AF3F4
	bl sub_080AF2BC
	cmp r0, #1
	bne .L080AF332
	ldr r0, .L080AF3E8
	bl Flag_Test
	cmp r0, #0
	bne .L080AF332
.L080AF3D8:
	ldr r0, .L080AF3EC
	ldr r1, .L080AF3F0
	bl Task_Create
	movs r0, #0x1a
	bl Field_SetState
	b .L080AF3F8
.L080AF3E8: .4byte 0x00000101
.L080AF3EC: .4byte gUnknown_0816499C
.L080AF3F0: .4byte 0x0000FFFF
.L080AF3F4:
	bl sub_080AF2E8
.L080AF3F8:
	pop {r0}
	bx r0

	thumb_func_start sub_080AF3FC
sub_080AF3FC: @ 0x080AF3FC
.L080AF3FC:
	push {r4, lr}
	ldr r1, .L080AF42C
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L080AF430
	ldr r0, [r0]
	cmp r0, #1
	bne .L080AF458
	bl sub_080E54D4
	cmp r0, #0
	bne .L080AF448
	movs r0, #1
	bl sub_080C3818
	bl sub_080B78A4
	cmp r0, #0
	bne .L080AF434
	movs r0, #0x1d
	bl Field_SetState
	b .L080AF43A
	.byte 0x00, 0x00
.L080AF42C: .4byte 0x0203DB6A @ EWRAM+0x3DB6A
.L080AF430: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080AF434:
	movs r0, #0xa
	bl Field_SetState
.L080AF43A:
	ldr r1, .L080AF444
	movs r0, #0
	strh r0, [r1, #0x1e]
	b .L080AF4B0
	.byte 0x00, 0x00
.L080AF444: .4byte 0x03004550 @ IWRAM+0x4550
.L080AF448:
	ldr r0, .L080AF454
	ldrh r0, [r0]
	bl Field_SetState
	b .L080AF4B0
	.byte 0x00, 0x00
.L080AF454: .4byte 0x03004530 @ IWRAM+0x4530
.L080AF458:
	ldr r4, .L080AF46C
	ldr r0, [r4]
	cmp r0, #0x19
	bne .L080AF470
	movs r0, #1
	str r0, [r4]
	bl sub_080AF300
	b .L080AF4B0
	.byte 0x00, 0x00
.L080AF46C: .4byte 0x03004530 @ IWRAM+0x4530
.L080AF470:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Field_SetState
	ldr r0, [r4]
	cmp r0, #0xc
	bne .L080AF4B0
	ldr r0, .L080AF4A0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080AF4AC
	bl sub_080B0820
	ldr r1, .L080AF4A4
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	movs r2, #0
	strh r0, [r1, #0x1e]
	ldr r0, .L080AF4A8
	strh r2, [r0]
	b .L080AF4B0
.L080AF4A0: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080AF4A4: .4byte 0x03004550 @ IWRAM+0x4550
.L080AF4A8: .4byte 0x0300460C @ IWRAM+0x460C
.L080AF4AC:
	bl sub_080AF300
.L080AF4B0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080AF4B8
sub_080AF4B8: @ 0x080AF4B8
.L080AF4B8:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	movs r3, #1
	movs r5, #7
	lsrs r0, r0, #0x13
	ldr r2, .L080AF4E4
	lsrs r1, r1, #0xc
	adds r0, r0, r1
	ldr r1, .L080AF4E8
	adds r2, r2, r1
	adds r0, r0, r2
	ands r4, r5
	lsls r3, r4
	ldrb r1, [r0]
	orrs r3, r1
	strb r3, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AF4E4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080AF4E8: .4byte 0x00001188

	thumb_func_start sub_080AF4EC
sub_080AF4EC: @ 0x080AF4EC
.L080AF4EC:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080AF530
	ldrh r0, [r0]
	ldr r1, .L080AF534
	ldrh r1, [r1]
	bl sub_080C8B10
	ldrh r1, [r0, #8]
	adds r4, r4, r1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrh r1, [r0, #0xa]
	adds r5, r5, r1
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r1, r4, #0
	adds r2, r5, #0
	bl sub_080B7944
	cmp r0, #0
	beq .L080AF52A
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080AF4B8
.L080AF52A:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080AF530: .4byte 0x03004614 @ IWRAM+0x4614
.L080AF534: .4byte 0x03004514 @ IWRAM+0x4514

	thumb_func_start sub_080AF538
sub_080AF538: @ 0x080AF538
.L080AF538:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	movs r4, #1
	movs r5, #7
	lsrs r0, r0, #0x13
	ldr r2, .L080AF564
	lsrs r1, r1, #0xc
	adds r0, r0, r1
	ldr r1, .L080AF568
	adds r2, r2, r1
	adds r0, r0, r2
	ands r3, r5
	lsls r4, r3
	ldrb r1, [r0]
	bics r1, r4
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AF564: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080AF568: .4byte 0x00001188

	thumb_func_start sub_080AF56C
sub_080AF56C: @ 0x080AF56C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080AF5B0
	ldrh r0, [r0]
	ldr r1, .L080AF5B4
	ldrh r1, [r1]
	bl sub_080C8B10
	ldrh r1, [r0, #8]
	adds r4, r4, r1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrh r1, [r0, #0xa]
	adds r5, r5, r1
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r1, r4, #0
	adds r2, r5, #0
	bl sub_080B7944
	cmp r0, #0
	beq .L080AF5AA
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080AF538
.L080AF5AA:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080AF5B0: .4byte 0x03004614 @ IWRAM+0x4614
.L080AF5B4: .4byte 0x03004514 @ IWRAM+0x4514

	thumb_func_start sub_080AF5B8
sub_080AF5B8: @ 0x080AF5B8
.L080AF5B8:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	cmp r2, #1
	beq .L080AF5E4
	cmp r2, #1
	bgt .L080AF5D6
	cmp r2, #0
	beq .L080AF5E0
	b .L080AF5F6
.L080AF5D6:
	cmp r0, #2
	beq .L080AF5E8
	cmp r0, #3
	beq .L080AF5F0
	b .L080AF5F6
.L080AF5E0:
	adds r0, r1, #1
	b .L080AF5EA
.L080AF5E4:
	subs r0, r3, #1
	b .L080AF5F2
.L080AF5E8:
	subs r0, r1, #1
.L080AF5EA:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b .L080AF5F6
.L080AF5F0:
	adds r0, r3, #1
.L080AF5F2:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L080AF5F6:
	lsls r0, r3, #0x10
	cmp r0, #0
	blt .L080AF616
	lsls r0, r1, #0x10
	cmp r0, #0
	blt .L080AF616
	ldr r0, .L080AF61C
	ldrh r2, [r0, #0x1a]
	cmp r3, r2
	bhs .L080AF616
	ldrh r0, [r0, #0x1c]
	cmp r1, r0
	bhs .L080AF616
	adds r0, r3, #0
	bl sub_080AF4EC
.L080AF616:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080AF61C: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080AF620
sub_080AF620: @ 0x080AF620
.L080AF620:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080AF674
	ldrh r0, [r0]
	ldr r1, .L080AF678
	ldrh r1, [r1]
	bl sub_080C8B10
	ldrh r1, [r0, #8]
	adds r4, r4, r1
	lsls r6, r4, #0x10
	lsrs r4, r6, #0x10
	ldrh r1, [r0, #0xa]
	adds r5, r5, r1
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r1, r4, #0
	adds r2, r5, #0
	bl sub_080B7944
	cmp r0, #0
	beq .L080AF684
	movs r3, #7
	lsrs r0, r6, #0x13
	ldr r1, .L080AF67C
	lsls r2, r5, #4
	adds r0, r0, r2
	ldr r2, .L080AF680
	adds r1, r1, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	ands r3, r4
	movs r1, #1
	lsls r1, r3
	ands r0, r1
	b .L080AF686
	.byte 0x00, 0x00
.L080AF674: .4byte 0x03004614 @ IWRAM+0x4614
.L080AF678: .4byte 0x03004514 @ IWRAM+0x4514
.L080AF67C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080AF680: .4byte 0x00001188
.L080AF684:
	movs r0, #0
.L080AF686:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_080AF68C
sub_080AF68C: @ 0x080AF68C
.L080AF68C:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r6, #1
	ldr r0, .L080AF6D4
	ldrh r0, [r0]
	ldr r1, .L080AF6D8
	ldrh r1, [r1]
	bl sub_080C8B10
	ldrh r1, [r0, #8]
	adds r4, r4, r1
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	ldrh r0, [r0, #0xa]
	adds r5, r5, r0
	lsls r5, r5, #0x10
	movs r2, #7
	lsrs r4, r4, #0x13
	ldr r0, .L080AF6DC
	lsrs r5, r5, #0xc
	adds r4, r4, r5
	ldr r3, .L080AF6E0
	adds r0, r0, r3
	adds r4, r4, r0
	ldrb r0, [r4]
	ands r1, r2
	lsls r6, r1
	ands r0, r6
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080AF6D4: .4byte 0x03004614 @ IWRAM+0x4614
.L080AF6D8: .4byte 0x03004514 @ IWRAM+0x4514
.L080AF6DC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080AF6E0: .4byte 0x00001188

	thumb_func_start sub_080AF6E4
sub_080AF6E4: @ 0x080AF6E4
.L080AF6E4:
	ldr r2, .L080AF6F0
	str r0, [r2]
	ldr r0, .L080AF6F4
	str r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080AF6F0: .4byte 0x03004538 @ IWRAM+0x4538
.L080AF6F4: .4byte 0x03004000 @ IWRAM+0x4000

	thumb_func_start sub_080AF6F8
sub_080AF6F8: @ 0x080AF6F8
.L080AF6F8:
	push {r4, r5, lr}
	adds r4, r2, #0
	ldr r5, [r1, #4]
	bl sub_080AF6E4
	ldr r1, .L080AF718
	movs r0, #0
	strh r0, [r1, #0x1e]
	cmp r4, #0
	bne .L080AF71C
	movs r0, #0xc
	adds r1, r5, #0
	bl sub_080AF178
	b .L080AF724
	.byte 0x00, 0x00
.L080AF718: .4byte 0x03004550 @ IWRAM+0x4550
.L080AF71C:
	movs r0, #0xc
	adds r1, r5, #0
	bl sub_080AF1D0
.L080AF724:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080AF72C
sub_080AF72C: @ 0x080AF72C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r0, #0
	movs r1, #0
	bl sub_080B2EFC
	movs r1, #0x24
	bl sub_080B3038
	adds r3, r0, #0
	cmp r3, #0
	beq .L080AF7DC
	ldr r1, .L080AF798
	ldrh r7, [r1, #0x12]
	ldrh r5, [r1, #0x14]
	ldrh r6, [r1, #0x16]
	ldrh r4, [r1, #0x18]
	mov r0, r8
	ldrh r2, [r0, #8]
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq .L080AF766
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq .L080AF792
.L080AF766:
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r0, r2
	cmp r0, #0
	beq .L080AF776
	ldrh r0, [r1, #2]
	cmp r0, #1
	beq .L080AF792
.L080AF776:
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	beq .L080AF784
	ldrh r0, [r1, #2]
	cmp r0, #2
	beq .L080AF792
.L080AF784:
	movs r0, #0xf
	ands r0, r2
	cmp r0, #0
	beq .L080AF79C
	ldrh r0, [r1, #2]
	cmp r0, #3
	bne .L080AF79C
.L080AF792:
	movs r0, #2
	b .L080AF7DE
	.byte 0x00, 0x00
.L080AF798: .4byte 0x03004550 @ IWRAM+0x4550
.L080AF79C:
	cmp r7, r6
	bne .L080AF7B6
	cmp r5, r4
	bhs .L080AF7AC
	ldrh r1, [r3, #2]
	movs r0, #0x80
	lsls r0, r0, #5
	b .L080AF7D2
.L080AF7AC:
	cmp r5, r4
	bls .L080AF7B6
	ldrh r1, [r3, #2]
	movs r0, #0x10
	b .L080AF7D2
.L080AF7B6:
	cmp r7, r6
	bhs .L080AF7C4
	cmp r5, r4
	bne .L080AF7C4
	ldrh r1, [r3, #2]
	movs r0, #1
	b .L080AF7D2
.L080AF7C4:
	cmp r7, r6
	bls .L080AF7DC
	cmp r5, r4
	bne .L080AF7DC
	ldrh r1, [r3, #2]
	movs r0, #0x80
	lsls r0, r0, #1
.L080AF7D2:
	ands r0, r1
	cmp r0, #0
	beq .L080AF7DC
	movs r0, #0
	b .L080AF7DE
.L080AF7DC:
	movs r0, #1
.L080AF7DE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080AF7E8
sub_080AF7E8: @ 0x080AF7E8
.L080AF7E8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r4, .L080AF824
	ldrh r0, [r4, #0x12]
	ldrh r1, [r4, #0x14]
	ldrh r2, [r4, #2]
	mov r3, sp
	bl sub_080C9084
	adds r7, r0, #0
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_080AF6E4
	movs r0, #0
	strh r0, [r4, #0x1e]
	mov r0, r8
	cmp r0, #0
	bne .L080AF828
	ldr r1, [r7, #4]
	movs r0, #0xc
	bl sub_080AF178
	b .L080AF830
	.byte 0x00, 0x00
.L080AF824: .4byte 0x03004550 @ IWRAM+0x4550
.L080AF828:
	ldr r1, [r7, #4]
	movs r0, #0xc
	bl sub_080AF1D0
.L080AF830:
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, .L080AF854
	cmp r1, r0
	beq .L080AF842
	mov r0, sp
	ldrh r0, [r0]
	bl sub_080C24B8
.L080AF842:
	ldr r1, .L080AF858
	movs r0, #1
	strh r0, [r1, #0x3e]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080AF854: .4byte 0x0000FFFF
.L080AF858: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080AF85C
sub_080AF85C: @ 0x080AF85C
.L080AF85C:
	push {r4, lr}
	adds r2, r1, #0
	subs r0, #0x30
	cmp r0, #4
	bhi .L080AF8AA
	lsls r0, r0, #2
	ldr r1, .L080AF870
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080AF870: .4byte gUnknown_080AF874
	.global gUnknown_080AF874
gUnknown_080AF874:
.L080AF874: @ jump table
	.4byte .L080AF888
	.4byte .L080AF890
	.4byte .L080AF898
	.4byte .L080AF8A0
	.4byte .L080AF8A8
.L080AF888:
	ldr r4, .L080AF88C
	b .L080AF8AA
.L080AF88C: .4byte gUnknown_08073AD0
.L080AF890:
	ldr r4, .L080AF894
	b .L080AF8AA
.L080AF894: .4byte gUnknown_08073AB2
.L080AF898:
	ldr r4, .L080AF89C
	b .L080AF8AA
.L080AF89C: .4byte gUnknown_08073ABC
.L080AF8A0:
	ldr r4, .L080AF8A4
	b .L080AF8AA
.L080AF8A4: .4byte gUnknown_08073AC6
.L080AF8A8:
	ldr r4, .L080AF8C8
.L080AF8AA:
	adds r0, r2, #0
	adds r1, r2, #0
	bl sub_080AF6E4
	ldr r1, .L080AF8CC
	movs r0, #0
	strh r0, [r1, #0x1e]
	movs r0, #0xc
	adds r1, r4, #0
	bl sub_080AF178
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
.L080AF8C8: .4byte gUnknown_08073AA8
.L080AF8CC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080AF8D0
sub_080AF8D0: @ 0x080AF8D0
.L080AF8D0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x70
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	movs r0, #0
	movs r1, #0
	bl sub_080B2EFC
	adds r4, r0, #0
	movs r1, #4
	bl sub_080B3038
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0x15
	bl sub_080B3038
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #1
	bl sub_080B3038
	str r0, [sp, #0x10]
	adds r0, r4, #0
	movs r1, #2
	bl sub_080B3038
	str r0, [sp, #0x14]
	adds r0, r4, #0
	movs r1, #0x1b
	bl sub_080B3038
	str r0, [sp, #0x18]
	adds r0, r4, #0
	movs r1, #0x1c
	bl sub_080B3038
	str r0, [sp, #0x1c]
	adds r0, r4, #0
	movs r1, #0x10
	bl sub_080B3038
	str r0, [sp, #0x20]
	adds r0, r4, #0
	movs r1, #0x13
	bl sub_080B3038
	adds r6, r0, #0
	adds r0, r4, #0
	movs r1, #0x1d
	bl sub_080B3038
	str r0, [sp, #0x24]
	adds r0, r4, #0
	movs r1, #0x1e
	bl sub_080B3038
	str r0, [sp, #0x28]
	adds r0, r4, #0
	movs r1, #3
	bl sub_080B3038
	str r0, [sp, #0x2c]
	adds r0, r4, #0
	movs r1, #9
	bl sub_080B3038
	str r0, [sp, #0x30]
	adds r0, r4, #0
	movs r1, #8
	bl sub_080B3038
	str r0, [sp, #0x34]
	adds r0, r4, #0
	movs r1, #0x19
	bl sub_080B3038
	str r0, [sp, #0x38]
	adds r0, r4, #0
	movs r1, #5
	bl sub_080B3038
	str r0, [sp, #0x3c]
	adds r0, r4, #0
	movs r1, #0xb
	bl sub_080B3038
	str r0, [sp, #0x40]
	adds r0, r4, #0
	movs r1, #0xc
	bl sub_080B3038
	str r0, [sp, #0x44]
	adds r0, r4, #0
	movs r1, #0xd
	bl sub_080B3038
	str r0, [sp, #0x48]
	adds r0, r4, #0
	movs r1, #0xe
	bl sub_080B3038
	str r0, [sp, #0x4c]
	adds r0, r4, #0
	movs r1, #0xf
	bl sub_080B3038
	str r0, [sp, #0x50]
	adds r0, r4, #0
	movs r1, #0x25
	bl sub_080B3038
	str r0, [sp, #0x54]
	adds r0, r4, #0
	movs r1, #0x26
	bl sub_080B3038
	str r0, [sp, #0x58]
	adds r0, r4, #0
	movs r1, #0x27
	bl sub_080B3038
	str r0, [sp, #0x5c]
	ldr r2, .L080AFA58
	ldrh r0, [r2, #0x12]
	ldrh r1, [r2, #0x14]
	ldrh r2, [r2, #2]
	mov r3, sp
	bl sub_080C9084
	adds r7, r0, #0
	adds r0, r4, #0
	movs r1, #0x14
	bl sub_080B3038
	str r0, [sp, #0x60]
	adds r0, r4, #0
	movs r1, #0x1f
	bl sub_080B3038
	adds r5, r0, #0
	adds r0, r4, #0
	movs r1, #0x16
	bl sub_080B3038
	mov sl, r0
	adds r0, r4, #0
	movs r1, #0x17
	bl sub_080B3038
	str r0, [sp, #0x64]
	adds r0, r4, #0
	movs r1, #0x18
	bl sub_080B3038
	str r0, [sp, #0x68]
	adds r0, r4, #0
	movs r1, #0x1a
	bl sub_080B3038
	str r0, [sp, #0x6c]
	ldr r0, .L080AFA5C
	movs r1, #0
	str r1, [r0]
	ldr r0, .L080AFA60
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080AFA38
	b .L080B0102
.L080AFA38:
	cmp r5, #0
	beq .L080AFA8C
	ldrh r0, [r5, #4]
	bl sub_080C57CC
	cmp r0, #1
	bne .L080AFA8C
	mov r2, r8
	cmp r2, #1
	bne .L080AFA76
	mov r3, sb
	cmp r3, #1
	bne .L080AFA64
	adds r0, r5, #0
	b .L080B0080
	.byte 0x00, 0x00
.L080AFA58: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFA5C: .4byte 0x03004538 @ IWRAM+0x4538
.L080AFA60: .4byte 0x03003FF4 @ IWRAM+0x3FF4
.L080AFA64:
	mov r0, sb
	cmp r0, #2
	bne .L080AFA76
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080AF6E4
	adds r0, r5, #0
	b .L080B00DA
.L080AFA76:
	mov r1, r8
	cmp r1, #2
	beq .L080AFA7E
	b .L080B0102
.L080AFA7E:
	mov r2, sb
	cmp r2, #2
	beq .L080AFA86
	b .L080B0102
.L080AFA86:
	adds r0, r4, #0
	adds r1, r5, #0
	b .L080B00A0
.L080AFA8C:
	ldr r3, [sp, #8]
	cmp r3, #0
	beq .L080AFAAC
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	movs r0, #0xb
	bl Field_SetState
	ldr r1, .L080AFAA8
	movs r0, #0
	strh r0, [r1, #0x1e]
	b .L080B0102
.L080AFAA8: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFAAC:
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq .L080AFAD8
	adds r0, r4, #0
	ldr r1, [sp, #0xc]
	bl sub_080AF6E4
	movs r0, #0xc
	bl Field_SetState
	ldr r0, .L080AFAD0
	mov r1, sp
	ldrh r1, [r1, #8]
	strh r1, [r0, #0x1e]
	ldr r1, .L080AFAD4
	ldr r2, [sp, #0xc]
	b .L080AFE6C
	.byte 0x00, 0x00
.L080AFAD0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFAD4: .4byte 0x03004534 @ IWRAM+0x4534
.L080AFAD8:
	ldr r3, [sp, #0x10]
	cmp r3, #0
	beq .L080AFB14
	ldrh r0, [r3, #2]
	cmp r0, #0
	beq .L080AFB14
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	movs r0, #0xd
	bl Field_SetState
	ldr r0, .L080AFB08
	mov r1, sp
	ldrh r1, [r1, #0xc]
	strh r1, [r0, #0x1e]
	ldr r1, .L080AFB0C
	ldr r2, [sp, #0x10]
	ldrh r0, [r2, #2]
	strh r0, [r1]
	ldr r0, .L080AFB10
	ldr r3, [sp, #0xc]
	b .L080B0100
.L080AFB08: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFB0C: .4byte 0x03004534 @ IWRAM+0x4534
.L080AFB10: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080AFB14:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq .L080AFB44
	movs r1, #0
	cmp r1, #0
	bne .L080AFB44
	cmp r6, #0
	bne .L080AFB44
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	bl sub_080AF6E4
	movs r0, #0x21
	bl Field_SetState
	ldr r0, .L080AFB3C
	strh r6, [r0, #0x1e]
	ldr r1, .L080AFB40
	ldr r2, [sp, #0x18]
	b .L080AFBB4
.L080AFB3C: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFB40: .4byte 0x03004534 @ IWRAM+0x4534
.L080AFB44:
	ldr r3, [sp, #0x14]
	cmp r3, #0
	beq .L080AFB8E
	ldrh r0, [r3, #2]
	cmp r0, #0
	beq .L080AFB80
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	movs r0, #0xe
	bl Field_SetState
	ldr r0, .L080AFB74
	movs r2, #0
	strh r2, [r0, #0x1e]
	ldr r1, .L080AFB78
	ldr r3, [sp, #0x14]
	ldrh r0, [r3, #2]
	strh r0, [r1]
	ldr r0, .L080AFB7C
	str r2, [r0]
	b .L080B0102
	.byte 0x00, 0x00
.L080AFB74: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFB78: .4byte 0x03004534 @ IWRAM+0x4534
.L080AFB7C: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080AFB80:
	adds r0, r4, #0
	ldr r1, [sp, #0x14]
	bl sub_080AF6E4
	bl sub_080B5FD8
	b .L080B0102
.L080AFB8E:
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq .L080AFBCC
	movs r1, #0
	cmp r1, #0
	bne .L080AFBCC
	cmp r6, #0
	bne .L080AFBCC
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	bl sub_080AF6E4
	movs r0, #0x22
	bl Field_SetState
	ldr r0, .L080AFBC0
	strh r6, [r0, #0x1e]
	ldr r1, .L080AFBC4
	ldr r2, [sp, #0x1c]
.L080AFBB4:
	ldrh r0, [r2, #2]
	strh r0, [r1]
	ldr r0, .L080AFBC8
	str r6, [r0]
	b .L080B0102
	.byte 0x00, 0x00
.L080AFBC0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFBC4: .4byte 0x03004534 @ IWRAM+0x4534
.L080AFBC8: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080AFBCC:
	ldr r3, [sp, #0x20]
	cmp r3, #0
	beq .L080AFBEC
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080AFBE4
	movs r1, #0
	strh r1, [r0, #0x1e]
	ldr r1, .L080AFBE8
	b .L080B005E
.L080AFBE4: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFBE8: .4byte gUnknown_0805A65E
.L080AFBEC:
	cmp r6, #0
	beq .L080AFC62
	ldr r0, [r6, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFC0E
	ldr r0, [r6, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFC0E
	b .L080B0102
.L080AFC0E:
	adds r0, r4, #0
	adds r1, r6, #0
	bl sub_080AF6E4
	ldr r0, .L080AFC3C
	mov r1, sp
	ldrh r1, [r1, #0x20]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #4]
	cmp r2, #0
	bne .L080AFC4A
	movs r0, #0
	movs r1, #0
	movs r2, #0x28
	bl sub_080B3078
	cmp r0, #1
	bne .L080AFC40
	ldr r1, [r6, #4]
	movs r0, #0xc
	bl sub_080AF1D0
	b .L080AFC52
.L080AFC3C: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFC40:
	ldr r1, [r6, #4]
	movs r0, #0xc
	bl sub_080AF178
	b .L080AFC52
.L080AFC4A:
	ldr r1, [r6, #4]
	movs r0, #0xc
	bl sub_080AF1D0
.L080AFC52:
	ldr r3, [sp, #0x6c]
	cmp r3, #0
	bne .L080AFC5A
	b .L080B0102
.L080AFC5A:
	ldrh r0, [r3, #2]
	bl sub_080B011C
	b .L080B0102
.L080AFC62:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq .L080AFCEC
	ldrh r6, [r0, #2]
	cmp r6, #0
	bne .L080AFCEC
	bl sub_080B6170
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L080AFCCC
	cmp r1, r0
	bne .L080AFC80
	ldr r0, .L080AFCD0
	ldrh r1, [r0, #2]
.L080AFC80:
	lsls r1, r1, #2
	ldr r0, [sp, #0x24]
	adds r0, #4
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	bne .L080AFC90
	b .L080B0102
.L080AFC90:
	adds r0, r5, #0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFCAE
	adds r0, r5, #0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFCAE
	b .L080B0102
.L080AFCAE:
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	bl sub_080AF6E4
	ldr r0, .L080AFCD0
	strh r6, [r0, #0x1e]
	ldr r1, [sp, #4]
	cmp r1, #0
	bne .L080AFCD4
	movs r0, #0xc
	adds r1, r5, #0
	bl sub_080AF178
	b .L080AFCDC
	.byte 0x00, 0x00
.L080AFCCC: .4byte 0x0000FFFF
.L080AFCD0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFCD4:
	movs r0, #0xc
	adds r1, r5, #0
	bl sub_080AF1D0
.L080AFCDC:
	ldr r2, [sp, #0x6c]
	cmp r2, #0
	bne .L080AFCE4
	b .L080B0102
.L080AFCE4:
	ldrh r0, [r2, #2]
	bl sub_080B011C
	b .L080B0102
.L080AFCEC:
	ldr r3, [sp, #0x28]
	cmp r3, #0
	beq .L080AFD4E
	movs r0, #0
	bl sub_080C06BC
	lsls r0, r0, #2
	ldr r1, [sp, #0x28]
	adds r1, #4
	adds r1, r1, r0
	ldr r5, [r1]
	adds r0, r5, #0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFD20
	adds r0, r5, #0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFD20
	b .L080B0102
.L080AFD20:
	adds r0, r4, #0
	ldr r1, [sp, #0x28]
	bl sub_080AF6E4
	ldr r1, .L080AFD40
	movs r0, #0
	strh r0, [r1, #0x1e]
	ldr r0, [sp, #4]
	cmp r0, #0
	bne .L080AFD44
	movs r0, #0xc
	adds r1, r5, #0
	bl sub_080AF178
	b .L080B0102
	.byte 0x00, 0x00
.L080AFD40: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFD44:
	movs r0, #0xc
	adds r1, r5, #0
	bl sub_080AF1D0
	b .L080B0102
.L080AFD4E:
	cmp r7, #0
	beq .L080AFDC0
	ldr r1, [r7, #4]
	ldr r0, .L080AFD74
	cmp r1, r0
	bne .L080AFD78
	bl sub_080B098C
	cmp r0, #0
	bne .L080AFD78
	bl sub_080C9100
	cmp r0, #0
	bne .L080AFD6C
	b .L080B0102
.L080AFD6C:
	adds r1, r7, #0
	bl sub_080AF85C
	b .L080B0102
.L080AFD74: .4byte gUnknown_08073A00
.L080AFD78:
	ldr r0, [r7, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFD96
	ldr r0, [r7, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFD96
	b .L080B0102
.L080AFD96:
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, .L080AFDBC
	cmp r1, r0
	bne .L080AFDA2
	b .L080B0102
.L080AFDA2:
	mov r0, sp
	ldrh r0, [r0]
	bl sub_080C2480
	cmp r0, #1
	bne .L080AFDB0
	b .L080B0102
.L080AFDB0:
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl sub_080AF7E8
	b .L080B0102
.L080AFDBC: .4byte 0x0000FFFF
.L080AFDC0:
	mov r1, sl
	cmp r1, #0
	beq .L080AFDF0
	ldr r0, [r1, #4]
	cmp r0, #0
	beq .L080AFDF0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFDEA
	mov r2, sl
	ldr r0, [r2, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFDEA
	b .L080B0102
.L080AFDEA:
	adds r0, r4, #0
	mov r1, sl
	b .L080AFE4E
.L080AFDF0:
	ldr r3, [sp, #0x64]
	cmp r3, #0
	beq .L080AFE20
	ldr r0, [r3, #4]
	cmp r0, #0
	beq .L080AFE20
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFE1A
	ldr r1, [sp, #0x64]
	ldr r0, [r1, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFE1A
	b .L080B0102
.L080AFE1A:
	adds r0, r4, #0
	ldr r1, [sp, #0x64]
	b .L080AFE4E
.L080AFE20:
	ldr r2, [sp, #0x68]
	cmp r2, #0
	beq .L080AFE56
	ldr r0, [r2, #4]
	cmp r0, #0
	beq .L080AFE56
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	beq .L080AFE4A
	ldr r3, [sp, #0x68]
	ldr r0, [r3, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, sb
	beq .L080AFE4A
	b .L080B0102
.L080AFE4A:
	adds r0, r4, #0
	ldr r1, [sp, #0x68]
.L080AFE4E:
	ldr r2, [sp, #4]
	bl sub_080AF6F8
	b .L080B0102
.L080AFE56:
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq .L080AFE78
	adds r0, r4, #0
	ldr r1, [sp, #0x2c]
	bl sub_080AF6E4
	bl sub_080BA070
	ldr r1, .L080AFE74
	ldr r2, [sp, #0x2c]
.L080AFE6C:
	ldrh r0, [r2, #2]
	strh r0, [r1]
	b .L080B0102
	.byte 0x00, 0x00
.L080AFE74: .4byte 0x03003B9C @ IWRAM+0x3B9C
.L080AFE78:
	ldr r3, [sp, #0x30]
	cmp r3, #0
	beq .L080AFE8C
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	bl sub_080B5E50
	b .L080B0102
.L080AFE8C:
	ldr r0, [sp, #0x34]
	cmp r0, #0
	beq .L080AFEB8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq .L080AFEA6
	ldr r1, [sp, #0x34]
	ldrh r0, [r1, #2]
	subs r0, #1
	ldr r1, .L080AFEB4
	ldrh r1, [r1, #2]
	cmp r0, r1
	beq .L080AFEB8
.L080AFEA6:
	adds r0, r4, #0
	ldr r1, [sp, #0x34]
	bl sub_080AF6E4
	bl sub_080B614C
	b .L080B0102
.L080AFEB4: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFEB8:
	ldr r2, [sp, #0x38]
	cmp r2, #0
	beq .L080AFEFC
	mov r0, r8
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080AFECC
	b .L080B0102
.L080AFECC:
	mov r3, sb
	cmp r3, #2
	beq .L080AFED4
	b .L080B0102
.L080AFED4:
	ldr r0, .L080AFEF8
	ldrh r1, [r0, #0x3a]
	movs r2, #0
	strh r2, [r0, #0x3a]
	ldrh r1, [r0, #0x38]
	movs r1, #0x40
	strh r1, [r0, #0x38]
	ldrh r1, [r0, #0x3c]
	strh r2, [r0, #0x3c]
	ldrh r0, [r0, #0x38]
	bl sub_080B1C18
	adds r0, r4, #0
	ldr r1, [sp, #0x38]
	bl sub_080AF6E4
	b .L080B0102
	.byte 0x00, 0x00
.L080AFEF8: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFEFC:
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	beq .L080AFF5A
	bl sub_080F3F44
	movs r1, #0x50
	ands r1, r0
	cmp r1, #0
	beq .L080AFF10
	b .L080B0102
.L080AFF10:
	mov r1, r8
	cmp r1, #1
	bne .L080AFF44
	mov r2, sb
	cmp r2, #2
	bne .L080AFF34
	adds r0, r4, #0
	ldr r1, [sp, #0x3c]
	bl sub_080AF6E4
	ldr r0, [sp, #0x3c]
	movs r1, #0
	bl sub_080B8FF0
	movs r0, #0x20
	bl Field_SetState
	b .L080B0102
.L080AFF34:
	mov r3, sb
	cmp r3, #1
	bne .L080AFF44
	ldr r0, [sp, #0x3c]
	movs r1, #1
	bl sub_080B8FF0
	b .L080B0084
.L080AFF44:
	mov r0, r8
	cmp r0, #2
	beq .L080AFF4C
	b .L080B0102
.L080AFF4C:
	mov r1, sb
	cmp r1, #2
	beq .L080AFF54
	b .L080B0102
.L080AFF54:
	adds r0, r4, #0
	ldr r1, [sp, #0x3c]
	b .L080B00A0
.L080AFF5A:
	ldr r2, [sp, #0x40]
	cmp r2, #0
	beq .L080AFF7C
	adds r0, r4, #0
	adds r1, r2, #0
	bl sub_080AF6E4
	ldr r0, .L080AFF78
	mov r3, sp
	ldrh r3, [r3, #0x3c]
	strh r3, [r0, #0x1e]
	ldr r0, [sp, #0x40]
	ldr r1, [r0, #4]
	b .L080B005E
	.byte 0x00, 0x00
.L080AFF78: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFF7C:
	ldr r1, [sp, #0x44]
	cmp r1, #0
	beq .L080AFFA4
	ldr r0, [r1, #4]
	cmp r0, #0
	bne .L080AFF8A
	b .L080B0102
.L080AFF8A:
	adds r0, r4, #0
	bl sub_080AF6E4
	ldr r0, .L080AFFA0
	add r2, sp, #0x40
	ldrh r2, [r2]
	strh r2, [r0, #0x1e]
	ldr r3, [sp, #0x44]
	ldr r1, [r3, #4]
	b .L080B005E
	.byte 0x00, 0x00
.L080AFFA0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFFA4:
	ldr r0, [sp, #0x48]
	cmp r0, #0
	beq .L080AFFC4
	adds r0, r4, #0
	ldr r1, [sp, #0x48]
	bl sub_080AF6E4
	ldr r0, .L080AFFC0
	add r1, sp, #0x44
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x48]
	b .L080B005C
	.byte 0x00, 0x00
.L080AFFC0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFFC4:
	ldr r3, [sp, #0x4c]
	cmp r3, #0
	beq .L080AFFE4
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080AFFE0
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x4c]
	b .L080B005C
	.byte 0x00, 0x00
.L080AFFE0: .4byte 0x03004550 @ IWRAM+0x4550
.L080AFFE4:
	ldr r3, [sp, #0x50]
	cmp r3, #0
	beq .L080B0004
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080B0000
	add r1, sp, #0x4c
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x50]
	b .L080B005C
	.byte 0x00, 0x00
.L080B0000: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0004:
	ldr r3, [sp, #0x54]
	cmp r3, #0
	beq .L080B0024
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080B0020
	add r1, sp, #0x50
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x54]
	b .L080B005C
	.byte 0x00, 0x00
.L080B0020: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0024:
	ldr r3, [sp, #0x58]
	cmp r3, #0
	beq .L080B0044
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080B0040
	add r1, sp, #0x54
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x58]
	b .L080B005C
	.byte 0x00, 0x00
.L080B0040: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0044:
	ldr r3, [sp, #0x5c]
	cmp r3, #0
	beq .L080B006C
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_080AF6E4
	ldr r0, .L080B0068
	add r1, sp, #0x58
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	ldr r2, [sp, #0x5c]
.L080B005C:
	ldr r1, [r2, #4]
.L080B005E:
	movs r0, #0xc
	bl sub_080AF178
	b .L080B0102
	.byte 0x00, 0x00
.L080B0068: .4byte 0x03004550 @ IWRAM+0x4550
.L080B006C:
	ldr r3, [sp, #0x60]
	cmp r3, #0
	beq .L080B00F0
	mov r0, r8
	cmp r0, #1
	bne .L080B0090
	mov r1, sb
	cmp r1, #1
	bne .L080B0090
	adds r0, r3, #0
.L080B0080:
	bl sub_080B8994
.L080B0084:
	ldr r1, .L080B008C
	str r0, [r1]
	b .L080B0102
	.byte 0x00, 0x00
.L080B008C: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080B0090:
	mov r2, r8
	cmp r2, #2
	bne .L080B00C4
	mov r3, sb
	cmp r3, #2
	bne .L080B00C4
	adds r0, r4, #0
	ldr r1, [sp, #0x60]
.L080B00A0:
	bl sub_080AF6E4
	ldr r1, .L080B00BC
	movs r0, #0
	strh r0, [r1, #0x1e]
	movs r0, #0x20
	bl Field_SetState
	ldr r0, .L080B00C0
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0xc]
	b .L080B0102
	.byte 0x00, 0x00
.L080B00BC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B00C0: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080B00C4:
	mov r0, r8
	cmp r0, #1
	bne .L080B0102
	mov r1, sb
	cmp r1, #2
	bne .L080B0102
	adds r0, r4, #0
	ldr r1, [sp, #0x60]
	bl sub_080AF6E4
	ldr r0, [sp, #0x60]
.L080B00DA:
	bl sub_080B8994
	ldr r1, .L080B00EC
	str r0, [r1]
	movs r0, #0x1a
	bl Field_SetState
	b .L080B0102
	.byte 0x00, 0x00
.L080B00EC: .4byte 0x03003FEC @ IWRAM+0x3FEC
.L080B00F0:
	ldr r2, [sp, #0x6c]
	cmp r2, #0
	beq .L080B0102
	ldrh r0, [r2, #2]
	bl sub_080B011C
	ldr r0, .L080B0118
	ldr r3, [sp, #0x60]
.L080B0100:
	str r3, [r0]
.L080B0102:
	ldr r0, .L080B0118
	ldr r0, [r0]
	add sp, #0x70
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B0118: .4byte 0x03004538 @ IWRAM+0x4538

	thumb_func_start sub_080B011C
sub_080B011C: @ 0x080B011C
.L080B011C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	cmp r0, #1
	beq .L080B0140
	cmp r0, #1
	bgt .L080B0132
	cmp r0, #0
	beq .L080B0138
	b .L080B014E
.L080B0132:
	cmp r1, #2
	beq .L080B0148
	b .L080B014E
.L080B0138:
	movs r0, #0xec
	bl Flag_Set
	b .L080B014E
.L080B0140:
	movs r0, #0xed
	bl Flag_Clear
	b .L080B014E
.L080B0148:
	ldr r0, .L080B0154
	bl Flag_Set
.L080B014E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B0154: .4byte 0x00000101

	thumb_func_start sub_080B0158
sub_080B0158: @ 0x080B0158
	push {lr}
	bl sub_080ADF40
	cmp r0, #0
	bne .L080B0174
	ldr r0, .L080B017C
	ldr r0, [r0]
	ldr r1, .L080B0180
	str r0, [r1]
	ldr r0, .L080B0184
	str r0, [r1, #4]
	ldr r0, .L080B0188
	str r0, [r1, #8]
	ldr r0, [r1, #8]
.L080B0174:
	bl sub_080B2880
	pop {r0}
	bx r0
.L080B017C: .4byte 0x03003B94 @ IWRAM+0x3B94
.L080B0180: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B0184: .4byte 0x06004000 @ VRAM+0x4000
.L080B0188: .4byte 0x84000800

	thumb_func_start sub_080B018C
sub_080B018C: @ 0x080B018C
	push {lr}
	bl sub_080ADF40
	cmp r0, #0
	bne .L080B01AE
	ldr r0, .L080B01B8
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, .L080B01BC
	str r0, [r1]
	ldr r0, .L080B01C0
	str r0, [r1, #4]
	ldr r0, .L080B01C4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
.L080B01AE:
	bl sub_080B2880
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B01B8: .4byte 0x03003B94 @ IWRAM+0x3B94
.L080B01BC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B01C0: .4byte 0x06004400 @ VRAM+0x4400
.L080B01C4: .4byte 0x84000700

	thumb_func_start sub_080B01C8
sub_080B01C8: @ 0x080B01C8
	push {lr}
	bl sub_080ADF40
	cmp r0, #0
	bne .L080B01EA
	ldr r0, .L080B01F4
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, .L080B01F8
	str r0, [r1]
	ldr r0, .L080B01FC
	str r0, [r1, #4]
	ldr r0, .L080B0200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
.L080B01EA:
	bl sub_080B2880
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B01F4: .4byte 0x03003B94 @ IWRAM+0x3B94
.L080B01F8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B01FC: .4byte 0x06004400 @ VRAM+0x4400
.L080B0200: .4byte 0x84000700

	thumb_func_start sub_080B0204
sub_080B0204: @ 0x080B0204
.L080B0204:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	ldr r2, .L080B021C
	cmp r0, #1
	beq .L080B022E
	cmp r0, #1
	bgt .L080B0220
	cmp r0, #0
	beq .L080B022A
	b .L080B0240
.L080B021C: .4byte 0x0200AD54 @ EWRAM+0xAD54
.L080B0220:
	cmp r1, #2
	beq .L080B0232
	cmp r1, #3
	beq .L080B0236
	b .L080B0240
.L080B022A:
	ldrh r0, [r2, #4]
	b .L080B0238
.L080B022E:
	ldrh r0, [r2, #6]
	b .L080B0238
.L080B0232:
	ldrh r0, [r2, #8]
	b .L080B0238
.L080B0236:
	ldrh r0, [r2, #0xa]
.L080B0238:
	cmp r0, #0
	bne .L080B0240
	movs r0, #1
	b .L080B0242
.L080B0240:
	movs r0, #0
.L080B0242:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B0248
sub_080B0248: @ 0x080B0248
.L080B0248:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r4, r3, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x6c
	muls r2, r0, r2
	ldr r0, .L080B0278
	adds r2, r2, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	cmp r3, #1
	beq .L080B028A
	cmp r3, #1
	bgt .L080B027C
	cmp r3, #0
	beq .L080B0286
	b .L080B0298
	.byte 0x00, 0x00
.L080B0278: .4byte 0x0200AD54 @ EWRAM+0xAD54
.L080B027C:
	cmp r4, #2
	beq .L080B028E
	cmp r4, #3
	beq .L080B0292
	b .L080B0298
.L080B0286:
	ldrh r0, [r2, #4]
	b .L080B0294
.L080B028A:
	ldrh r0, [r2, #6]
	b .L080B0294
.L080B028E:
	ldrh r0, [r2, #8]
	b .L080B0294
.L080B0292:
	ldrh r0, [r2, #0xa]
.L080B0294:
	cmp r0, #0
	bne .L080B029A
.L080B0298:
	movs r0, #0
.L080B029A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080B02A0
sub_080B02A0: @ 0x080B02A0
.L080B02A0:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, r4, #0
	bl sub_080AE2C0
	cmp r4, #1
	beq .L080B02E4
	cmp r4, #1
	bgt .L080B02C0
	cmp r4, #0
	beq .L080B02D0
	ldr r1, .L080B02BC
	b .L080B0332
.L080B02BC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B02C0:
	cmp r5, #2
	beq .L080B02F8
	cmp r5, #3
	beq .L080B0324
	ldr r1, .L080B02CC
	b .L080B0332
.L080B02CC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B02D0:
	ldr r0, .L080B02E0
	ldrh r2, [r0, #0x14]
	adds r1, r0, #0
	cmp r2, #0
	beq .L080B0332
	subs r0, r2, #1
	strh r0, [r1, #0x14]
	b .L080B0332
.L080B02E0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B02E4:
	ldr r1, .L080B02F4
	ldrh r2, [r1, #0x12]
	ldrh r0, [r1, #0x1a]
	subs r0, #1
	cmp r2, r0
	beq .L080B0332
	adds r0, r2, #1
	b .L080B0330
.L080B02F4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B02F8:
	bl sub_080ADF40
	cmp r0, #0
	bne .L080B0318
	ldr r1, .L080B0314
	ldrh r2, [r1, #0x14]
	ldrh r0, [r1, #0x1c]
	subs r0, #1
	cmp r2, r0
	beq .L080B0332
	adds r0, r2, #1
	strh r0, [r1, #0x14]
	b .L080B0332
	.byte 0x00, 0x00
.L080B0314: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0318:
	ldr r1, .L080B0320
	movs r0, #0
	b .L080B033E
	.byte 0x00, 0x00
.L080B0320: .4byte 0x03003FF4 @ IWRAM+0x3FF4
.L080B0324:
	ldr r0, .L080B0348
	ldrh r2, [r0, #0x12]
	adds r1, r0, #0
	cmp r2, #0
	beq .L080B0332
	subs r0, r2, #1
.L080B0330:
	strh r0, [r1, #0x12]
.L080B0332:
	ldrh r0, [r1, #0x12]
	ldrh r1, [r1, #0x14]
	bl sub_080AF4EC
	ldr r1, .L080B034C
	movs r0, #1
.L080B033E:
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B0348: .4byte 0x03004550 @ IWRAM+0x4550
.L080B034C: .4byte 0x03003FF4 @ IWRAM+0x3FF4

	thumb_func_start sub_080B0350
sub_080B0350: @ 0x080B0350
.L080B0350:
	push {r4, lr}
	bl sub_080C1D9C
	adds r4, r0, #0
	movs r0, #0xf0
	ands r4, r0
	bl sub_080C1D9C
	adds r1, r0, #0
	movs r0, #0xff
	ands r1, r0
	cmp r4, #0
	bne .L080B0384
	bl sub_080F3F44
	movs r1, #0x80
	lsls r1, r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L080B03B0
	ldr r0, .L080B0380
	bl sub_080F3F58
	b .L080B03B0
.L080B0380: .4byte 0xFFFFFEFF
.L080B0384:
	cmp r1, #0x80
	bne .L080B03B0
	bl sub_080F3F44
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0
	beq .L080B039C
	movs r0, #0x21
	rsbs r0, r0, #0
	bl sub_080F3F58
.L080B039C:
	bl sub_080F3F44
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0
	beq .L080B03B0
	movs r0, #0x41
	rsbs r0, r0, #0
	bl sub_080F3F58
.L080B03B0:
	bl sub_080C1AB0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080B03BC
sub_080B03BC: @ 0x080B03BC
.L080B03BC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	bl sub_080C221C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r4, sp
	adds r4, #2
	mov r0, sp
	adds r1, r4, #0
	bl sub_080C1B74
	adds r6, r0, #0
	ldr r0, .L080B0408
	ldrh r0, [r0]
	adds r7, r4, #0
	cmp r0, #0
	beq .L080B04A8
	bl sub_080C1E20
	adds r4, r0, #0
	bl sub_080C20EC
	cmp r5, #1
	bne .L080B0410
	bl sub_080BE76C
	cmp r0, #1
	bne .L080B0410
	ldr r1, .L080B040C
	movs r0, #0x1a
	strh r0, [r1]
	b .L080B04AE
.L080B0408: .4byte 0x03003FF4 @ IWRAM+0x3FF4
.L080B040C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0410:
	cmp r4, #0
	beq .L080B041C
	adds r0, r4, #0
	bl sub_080B9274
	b .L080B0444
.L080B041C:
	cmp r6, #0
	beq .L080B042E
	mov r0, sp
	ldrh r1, [r0]
	ldrh r2, [r7]
	adds r0, r6, #0
	bl sub_080BEC3C
	b .L080B0444
.L080B042E:
	bl sub_080B0350
	cmp r0, #0
	bne .L080B0440
	ldr r0, .L080B0450
	adds r0, #0x5c
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B0454
.L080B0440:
	bl sub_080B90F4
.L080B0444:
	movs r0, #0x1a
	bl Field_SetState
	movs r0, #1
	b .L080B04B0
	.byte 0x00, 0x00
.L080B0450: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0454:
	bl sub_080BEE24
	cmp r0, #0
	beq .L080B0460
	movs r0, #1
	b .L080B04B0
.L080B0460:
	movs r0, #0
	bl sub_080C2280
	cmp r0, #1
	bne .L080B04A8
	movs r0, #0
	movs r1, #0
	movs r2, #1
	bl sub_080B0248
	adds r4, r0, #0
	bl sub_080B6170
	lsls r0, r0, #0x10
	ldr r1, .L080B049C
	cmp r0, r1
	bne .L080B04A0
	subs r0, r4, #2
	cmp r0, #1
	bhi .L080B04A0
	movs r0, #0
	movs r1, #1
	bl sub_080B2EFC
	cmp r0, #0
	beq .L080B04A0
	mov r0, r8
	bl sub_080C2230
	b .L080B04A8
.L080B049C: .4byte 0xFFFF0000
.L080B04A0:
	bl sub_080AF034
	movs r0, #1
	b .L080B04B0
.L080B04A8:
	adds r0, r5, #0
	bl Field_SetState
.L080B04AE:
	movs r0, #0
.L080B04B0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
