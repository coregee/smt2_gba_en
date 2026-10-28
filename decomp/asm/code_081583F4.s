	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_081583F4
sub_081583F4: @ 0x081583F4
.L081583F4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldm r0!, {r7}
	ldr r0, [r0]
	ldrh r1, [r7]
	mov sl, r1
	adds r7, #2
	adds r0, #2
	ldr r4, .L08158500
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	ldr r0, .L08158504
	mov r2, sl
	strh r2, [r0]
	movs r3, #0
	mov ip, r3
	cmp ip, sl
	bhs .L081584EE
	mov sb, r4
.L08158428:
	mov r6, ip
	lsls r0, r6, #1
	add r0, ip
	lsls r0, r0, #1
	ldr r1, .L08158508
	adds r0, r0, r1
	mov r8, r0
	ldrh r1, [r7]
	strh r1, [r0]
	adds r7, #2
	adds r0, #2
	ldrh r1, [r7]
	strh r1, [r0]
	adds r7, #2
	ldrh r1, [r7]
	strh r1, [r0, #2]
	adds r7, #2
	mov r2, r8
	ldrb r5, [r2, #1]
	lsrs r5, r5, #6
	lsls r5, r5, #4
	ldrb r0, [r2, #3]
	lsrs r0, r0, #6
	lsls r0, r0, #2
	ldr r3, .L0815850C
	adds r0, r0, r3
	adds r5, r5, r0
	ldrh r1, [r2, #2]
	lsls r0, r1, #0x17
	lsrs r0, r0, #0x17
	subs r0, #0x80
	ldr r6, .L08158510
	ands r0, r6
	ldr r4, .L08158514
	ands r4, r1
	orrs r4, r0
	strh r4, [r2, #2]
	lsls r2, r4, #0x17
	lsrs r2, r2, #0x17
	ldrh r6, [r5]
	lsrs r6, r6, #1
	str r6, [sp]
	adds r2, r2, r6
	ldrh r3, [r5, #2]
	lsrs r3, r3, #1
	mov r0, r8
	ldrb r0, [r0]
	adds r3, r3, r0
	mov r1, sb
	movs r6, #0
	ldrsh r0, [r1, r6]
	adds r1, r0, #0
	muls r1, r2, r1
	str r1, [sp, #4]
	mov r6, sb
	movs r1, #2
	ldrsh r0, [r6, r1]
	muls r0, r3, r0
	ldr r6, [sp, #4]
	adds r1, r6, r0
	mov r0, sb
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r6, r2, #0
	muls r6, r0, r6
	str r6, [sp, #0xc]
	mov r2, sb
	movs r6, #6
	ldrsh r0, [r2, r6]
	muls r0, r3, r0
	ldr r3, [sp, #0xc]
	adds r2, r3, r0
	ldr r6, .L08158518
	ands r1, r6
	asrs r1, r1, #8
	ldr r0, [sp]
	subs r1, r1, r0
	ldr r3, .L08158510
	ands r1, r3
	ldr r6, .L08158514
	ands r4, r6
	orrs r4, r1
	mov r0, r8
	strh r4, [r0, #2]
	ldr r1, .L08158518
	ands r2, r1
	asrs r2, r2, #8
	ldrh r0, [r5, #2]
	lsrs r0, r0, #1
	subs r2, r2, r0
	mov r3, r8
	strb r2, [r3]
	mov r0, ip
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	cmp ip, sl
	blo .L08158428
.L081584EE:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08158500: .4byte 0x03006A30 @ IWRAM+0x6A30
.L08158504: .4byte 0x03003800 @ IWRAM+0x3800
.L08158508: .4byte 0x03003802 @ IWRAM+0x3802
.L0815850C: .4byte gUnknown_087F1494
.L08158510: .4byte 0x000001FF
.L08158514: .4byte 0xFFFFFE00
.L08158518: .4byte 0x0001FF00

	thumb_func_start sub_0815851C
sub_0815851C: @ 0x0815851C
.L0815851C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldm r0!, {r7}
	ldr r0, [r0]
	ldrh r1, [r7]
	mov sl, r1
	adds r7, #2
	adds r0, #2
	ldr r4, .L08158614
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	ldr r0, .L08158618
	mov r2, sl
	strh r2, [r0]
	movs r3, #0
	mov ip, r3
	cmp ip, sl
	bhs .L08158604
	mov sb, r4
.L08158550:
	mov r5, ip
	lsls r0, r5, #1
	add r0, ip
	lsls r0, r0, #1
	ldr r1, .L0815861C
	adds r0, r0, r1
	adds r6, r0, #0
	ldrh r1, [r7]
	strh r1, [r0]
	adds r7, #2
	adds r0, #2
	ldrh r1, [r7]
	strh r1, [r0]
	adds r7, #2
	ldrh r1, [r7]
	strh r1, [r0, #2]
	adds r7, #2
	ldrb r4, [r6, #1]
	lsrs r4, r4, #6
	lsls r4, r4, #4
	ldrb r0, [r6, #3]
	lsrs r0, r0, #6
	lsls r0, r0, #2
	ldr r2, .L08158620
	adds r0, r0, r2
	adds r4, r4, r0
	ldrh r3, [r6, #2]
	mov r8, r3
	mov r5, r8
	lsls r2, r5, #0x17
	lsrs r2, r2, #0x17
	ldrh r5, [r4]
	lsrs r5, r5, #1
	str r5, [sp]
	adds r2, r2, r5
	ldrh r3, [r4, #2]
	lsrs r3, r3, #1
	ldrb r0, [r6]
	adds r3, r3, r0
	mov r1, sb
	movs r5, #0
	ldrsh r0, [r1, r5]
	adds r1, r0, #0
	muls r1, r2, r1
	str r1, [sp, #4]
	mov r5, sb
	movs r1, #2
	ldrsh r0, [r5, r1]
	muls r0, r3, r0
	ldr r5, [sp, #4]
	adds r1, r5, r0
	mov r0, sb
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r2, #0
	muls r5, r0, r5
	str r5, [sp, #0xc]
	mov r2, sb
	movs r5, #6
	ldrsh r0, [r2, r5]
	muls r0, r3, r0
	ldr r3, [sp, #0xc]
	adds r2, r3, r0
	movs r0, #0xff
	lsls r0, r0, #8
	ands r1, r0
	asrs r1, r1, #8
	ldr r5, [sp]
	subs r1, r1, r5
	ldr r3, .L08158624
	adds r0, r3, #0
	ands r1, r0
	ldr r0, .L08158628
	mov r5, r8
	ands r0, r5
	orrs r0, r1
	strh r0, [r6, #2]
	lsls r2, r2, #0xf
	lsrs r2, r2, #0x17
	ldrh r0, [r4, #2]
	lsrs r0, r0, #1
	subs r2, r2, r0
	strb r2, [r6]
	mov r0, ip
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	cmp ip, sl
	blo .L08158550
.L08158604:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08158614: .4byte 0x03006A30 @ IWRAM+0x6A30
.L08158618: .4byte 0x03003800 @ IWRAM+0x3800
.L0815861C: .4byte 0x03003802 @ IWRAM+0x3802
.L08158620: .4byte gUnknown_087F1494
.L08158624: .4byte 0x000001FF
.L08158628: .4byte 0xFFFFFE00

	thumb_func_start sub_0815862C
sub_0815862C: @ 0x0815862C
.L0815862C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #8]
	ldm r0!, {r1}
	mov sb, r1
	ldr r0, [r0]
	ldrh r2, [r1]
	str r2, [sp, #0xc]
	movs r1, #2
	add sb, r1
	adds r0, #2
	ldr r1, .L08158700
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	ldr r0, .L08158704
	mov r2, sp
	ldrh r2, [r2, #0xc]
	strh r2, [r0]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r1, [sp, #0xc]
	cmp r0, r1
	blo .L08158678
	b .L08158812
.L08158678:
	ldr r2, [sp, #0x10]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #1
	ldr r1, .L08158708
	adds r7, r0, r1
	mov r1, sb
	ldrh r0, [r1]
	strh r0, [r7]
	movs r2, #2
	add sb, r2
	mov r1, sb
	ldrh r0, [r1]
	strh r0, [r7, #2]
	add sb, r2
	mov r2, sb
	ldrh r0, [r2]
	strh r0, [r7, #4]
	movs r0, #2
	add sb, r0
	ldrb r2, [r7, #1]
	lsrs r3, r2, #6
	lsls r3, r3, #4
	ldrb r0, [r7, #3]
	lsrs r0, r0, #6
	lsls r0, r0, #2
	ldr r1, .L0815870C
	adds r0, r0, r1
	adds r3, r3, r0
	ldrh r6, [r3]
	ldrh r3, [r3, #2]
	lsls r2, r2, #0x1e
	lsrs r2, r2, #0x1e
	movs r0, #2
	ands r2, r0
	cmp r2, #0
	bne .L081586C6
	lsrs r6, r6, #1
	lsrs r3, r3, #1
.L081586C6:
	ldrh r2, [r7, #2]
	lsls r0, r2, #0x17
	lsrs r0, r0, #0x17
	adds r4, r6, r0
	ldr r1, .L08158710
	adds r0, r1, #0
	ands r4, r0
	ldrb r1, [r7]
	adds r5, r3, r1
	movs r0, #0xff
	ands r5, r0
	mov sl, r2
	str r1, [sp, #0x14]
	ldr r2, [sp, #8]
	cmp r2, #0
	bne .L08158714
	ldr r1, [sp]
	adds r0, r1, #0
	muls r0, r6, r0
	cmp r0, #0
	bge .L081586F2
	adds r0, #0xff
.L081586F2:
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	mov ip, r0
	ldr r2, [sp, #4]
	adds r0, r2, #0
	muls r0, r3, r0
	b .L08158730
.L08158700: .4byte 0x03006A30 @ IWRAM+0x6A30
.L08158704: .4byte 0x03003800 @ IWRAM+0x3800
.L08158708: .4byte 0x03003802 @ IWRAM+0x3802
.L0815870C: .4byte gUnknown_087F1494
.L08158710: .4byte 0x000001FF
.L08158714:
	ldr r1, [sp]
	ldr r2, [sp, #8]
	adds r0, r1, #0
	muls r0, r2, r0
	cmp r0, #0
	bge .L08158722
	adds r0, #0xff
.L08158722:
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	mov ip, r0
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	adds r0, r1, #0
	muls r0, r2, r0
.L08158730:
	cmp r0, #0
	bge .L08158736
	adds r0, #0xff
.L08158736:
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r0, #0
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L08158750
	rsbs r4, r4, #0
	movs r0, #0x7f
	ands r4, r0
.L08158750:
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0
	beq .L0815875E
	rsbs r5, r5, #0
	movs r0, #0x7f
	ands r5, r0
.L0815875E:
	ldr r1, [sp, #8]
	cmp r1, #0
	bne .L08158788
	mov r0, ip
	muls r0, r4, r0
	adds r1, r6, #0
	str r3, [sp, #0x18]
	bl __divsi3
	adds r4, r0, #0
	ldr r2, .L08158784
	adds r0, r2, #0
	ands r4, r0
	mov r0, r8
	muls r0, r5, r0
	ldr r3, [sp, #0x18]
	adds r1, r3, #0
	b .L081587A2
	.byte 0x00, 0x00
.L08158784: .4byte 0x000001FF
.L08158788:
	mov r0, ip
	muls r0, r4, r0
	ldr r1, [sp, #8]
	str r3, [sp, #0x18]
	bl __divsi3
	adds r4, r0, #0
	ldr r1, .L081587CC
	adds r0, r1, #0
	ands r4, r0
	mov r0, r8
	muls r0, r5, r0
	ldr r1, [sp, #8]
.L081587A2:
	bl __divsi3
	adds r5, r0, #0
	movs r0, #0xff
	ands r5, r0
	ldr r3, [sp, #0x18]
	mov r2, sl
	lsls r0, r2, #0x17
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L081587D0
	rsbs r1, r4, #0
	ldr r0, .L081587CC
	ands r1, r0
	subs r1, r1, r6
	b .L081587D4
	.byte 0x00, 0x00
.L081587CC: .4byte 0x000001FF
.L081587D0:
	subs r1, r4, r6
	ldr r0, .L081587F4
.L081587D4:
	ands r1, r0
	ldr r2, .L081587F8
	adds r0, r2, #0
	mov r2, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #2]
	ldr r1, [sp, #0x14]
	adds r0, r1, r3
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L081587FC
	rsbs r0, r5, #0
	subs r0, r0, r3
	b .L081587FE
.L081587F4: .4byte 0x000001FF
.L081587F8: .4byte 0xFFFFFE00
.L081587FC:
	subs r0, r5, r3
.L081587FE:
	strb r0, [r7]
	ldr r0, [sp, #0x10]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r2, [sp, #0xc]
	cmp r0, r2
	bhs .L08158812
	b .L08158678
.L08158812:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08158824
sub_08158824: @ 0x08158824
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	ldm r0!, {r5}
	ldr r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	adds r5, #2
	adds r0, #2
	ldr r4, .L08158954
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	ldr r0, .L08158958
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r0]
	movs r3, #0
	mov sb, r3
	ldr r7, [sp]
	cmp sb, r7
	bhs .L08158942
	mov sl, r4
.L0815885C:
	mov r1, sb
	lsls r0, r1, #1
	add r0, sb
	lsls r0, r0, #1
	ldr r2, .L0815895C
	adds r4, r0, r2
	ldrh r0, [r5]
	strh r0, [r4]
	adds r5, #2
	ldrh r0, [r5]
	strh r0, [r4, #2]
	adds r5, #2
	ldrh r0, [r5]
	strh r0, [r4, #4]
	adds r5, #2
	ldrb r2, [r4, #1]
	lsrs r1, r2, #6
	lsls r1, r1, #4
	ldrb r0, [r4, #3]
	lsrs r0, r0, #6
	lsls r0, r0, #2
	ldr r3, .L08158960
	adds r0, r0, r3
	adds r1, r1, r0
	ldrh r6, [r1]
	ldrh r1, [r1, #2]
	str r1, [sp, #4]
	lsls r2, r2, #0x1e
	lsrs r2, r2, #0x1e
	movs r0, #2
	ands r2, r0
	cmp r2, #0
	bne .L081588A4
	lsrs r6, r6, #1
	lsrs r1, r1, #1
	str r1, [sp, #4]
.L081588A4:
	ldrh r7, [r4, #2]
	mov ip, r7
	mov r1, ip
	lsls r0, r1, #0x17
	lsrs r0, r0, #0x17
	adds r2, r0, r6
	ldr r3, .L08158964
	mov r8, r3
	ands r2, r3
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq .L081588C4
	ldr r7, .L08158968
	orrs r2, r7
.L081588C4:
	ldrb r0, [r4]
	ldr r1, [sp, #4]
	adds r3, r0, r1
	movs r0, #0xff
	ands r3, r0
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq .L081588DA
	ldr r7, .L08158968
	orrs r3, r7
.L081588DA:
	mov r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r7, r0, #0
	muls r7, r2, r7
	str r7, [sp, #0xc]
	mov r0, sl
	movs r1, #2
	ldrsh r0, [r0, r1]
	adds r7, r0, #0
	adds r0, r7, #0
	muls r0, r3, r0
	ldr r7, [sp, #0xc]
	adds r1, r7, r0
	mov r0, sl
	movs r7, #4
	ldrsh r0, [r0, r7]
	adds r7, r2, #0
	muls r7, r0, r7
	str r7, [sp, #0x10]
	mov r0, sl
	movs r2, #6
	ldrsh r0, [r0, r2]
	adds r7, r0, #0
	adds r0, r7, #0
	muls r0, r3, r0
	ldr r3, [sp, #0x10]
	adds r2, r3, r0
	ldr r7, .L08158968
	ands r1, r7
	lsrs r1, r1, #8
	subs r1, r1, r6
	mov r0, r8
	ands r1, r0
	ldr r0, .L0815896C
	mov r3, ip
	ands r0, r3
	orrs r0, r1
	strh r0, [r4, #2]
	ands r2, r7
	lsrs r2, r2, #8
	ldr r7, [sp, #4]
	subs r2, r2, r7
	strb r2, [r4]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	ldr r0, [sp]
	cmp sb, r0
	blo .L0815885C
.L08158942:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08158954: .4byte 0x03006A30 @ IWRAM+0x6A30
.L08158958: .4byte 0x03003800 @ IWRAM+0x3800
.L0815895C: .4byte 0x03003802 @ IWRAM+0x3802
.L08158960: .4byte gUnknown_087F1494
.L08158964: .4byte 0x000001FF
.L08158968: .4byte 0xFFFFFF00
.L0815896C: .4byte 0xFFFFFE00

	thumb_func_start sub_08158970
sub_08158970: @ 0x08158970
.L08158970:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, .L08158A2C
	adds r5, r4, #0
	adds r5, #0x90
	ldrh r1, [r5]
	movs r2, #0
	ldr r0, .L08158A30
	strh r1, [r0]
	adds r6, r4, #0
	adds r6, #0x92
	ldrh r3, [r6]
	movs r7, #0x8c
	adds r7, r7, r4
	mov sb, r7
	strh r3, [r7]
	movs r0, #0x94
	adds r0, r0, r4
	mov sl, r0
	ldrh r0, [r0]
	movs r7, #0x8e
	adds r7, r7, r4
	mov r8, r7
	strh r0, [r7]
	adds r0, r4, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r7, r4, #0
	adds r7, #0xa6
	strb r2, [r7]
	lsls r1, r1, #0x10
	lsls r0, r3, #0x10
	cmp r1, r0
	bls .L081589C0
	ldrh r0, [r5]
	strh r3, [r5]
	strh r0, [r6]
.L081589C0:
	bl sub_08158A40
	adds r2, r0, #0
	ldr r1, .L08158A30
	ldrh r0, [r1]
	strh r0, [r5]
	mov r1, sb
	ldrh r0, [r1]
	strh r0, [r6]
	mov r1, r8
	ldrh r0, [r1]
	mov r1, sl
	strh r0, [r1]
	ldrb r1, [r7]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0x30
	beq .L08158A1C
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne .L08158A1C
	adds r0, r4, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	subs r0, #0x32
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi .L08158A06
	movs r0, #3
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r7]
.L08158A06:
	adds r0, r4, #0
	adds r0, #0xa2
	ldrb r0, [r0]
	cmp r0, #0x1a
	bls .L08158A1C
	ldrb r0, [r7]
	movs r1, #3
	ands r1, r0
	movs r0, #0x20
	orrs r1, r0
	strb r1, [r7]
.L08158A1C:
	adds r0, r2, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L08158A2C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08158A30: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2

	thumb_func_start sub_08158A34
sub_08158A34: @ 0x08158A34
.L08158A34:
	push {lr}
	bl sub_08158A40
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08158A40
sub_08158A40: @ 0x08158A40
.L08158A40:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, .L08158AB4
	adds r5, r4, #0
	adds r5, #0x90
	ldrh r1, [r5]
	adds r0, r4, #0
	adds r0, #0x84
	strh r1, [r0]
	adds r6, r4, #0
	adds r6, #0x92
	ldrh r3, [r6]
	adds r0, #2
	strh r3, [r0]
	adds r0, #0xe
	ldrh r2, [r0]
	subs r0, #0xc
	strh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0xff
	beq .L08158A92
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	beq .L08158A92
	ldrh r0, [r5]
	movs r1, #0
	bl sub_0815B8F8
	cmp r0, #0
	beq .L08158A92
	ldrh r0, [r6]
	movs r1, #0
	bl sub_0815B8F8
	cmp r0, #0
	bne .L08158AB8
.L08158A92:
	ldr r2, .L08158AB4
	adds r1, r2, #0
	adds r1, #0xa0
	movs r0, #0xff
	strh r0, [r1]
	adds r1, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r1, #3
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
	b .L08158B8C
	.byte 0x00, 0x00
.L08158AB4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08158AB8:
	ldrh r0, [r5]
	movs r1, #0x99
	adds r1, r1, r4
	mov sl, r1
	movs r1, #0x96
	adds r1, r1, r4
	mov r8, r1
	mov r1, sl
	mov r2, r8
	bl sub_0815B9B8
	ldrh r0, [r6]
	movs r1, #0x9a
	adds r1, r1, r4
	mov sb, r1
	adds r7, r4, #0
	adds r7, #0x97
	adds r2, r7, #0
	bl sub_0815B9B8
	ldrh r0, [r5]
	bl sub_0815B9A0
	adds r1, r4, #0
	adds r1, #0x9c
	strb r0, [r1]
	ldrh r0, [r6]
	bl sub_0815B9A0
	adds r1, r4, #0
	adds r1, #0x9d
	strb r0, [r1]
	bl sub_08158B9C
	cmp r0, #0
	beq .L08158B06
	bl sub_08158D08
	b .L08158B8C
.L08158B06:
	ldrh r0, [r5]
	cmp r0, #0xfb
	beq .L08158B12
	ldrh r0, [r6]
	cmp r0, #0xfb
	bne .L08158B18
.L08158B12:
	bl sub_081593EC
	b .L08158B8C
.L08158B18:
	mov r5, r8
	ldrb r2, [r5]
	ldrb r3, [r7]
	cmp r2, r3
	bne .L08158B28
	bl sub_08158E78
	b .L08158B8C
.L08158B28:
	mov r0, sl
	ldrb r1, [r0]
	mov r5, sb
	ldrb r0, [r5]
	cmp r1, r0
	bne .L08158B3A
	bl sub_081590CC
	b .L08158B8C
.L08158B3A:
	cmp r1, #0xb
	beq .L08158B42
	cmp r0, #0xb
	bne .L08158B48
.L08158B42:
	bl sub_0815915C
	b .L08158B8C
.L08158B48:
	cmp r2, #8
	beq .L08158B50
	cmp r3, #8
	bne .L08158B62
.L08158B50:
	adds r2, r4, #0
	adds r2, #0xa6
	ldrb r1, [r2]
	movs r0, #3
	ands r0, r1
	strb r0, [r2]
	bl sub_081592AC
	b .L08158B8C
.L08158B62:
	cmp r2, #0x1a
	bhi .L08158B6A
	cmp r3, #0x1a
	bls .L08158B7C
.L08158B6A:
	adds r2, r4, #0
	adds r2, #0xa6
	ldrb r1, [r2]
	movs r0, #3
	ands r0, r1
	strb r0, [r2]
	bl sub_08158FA4
	b .L08158B8C
.L08158B7C:
	adds r2, r4, #0
	adds r2, #0xa6
	ldrb r1, [r2]
	movs r0, #3
	ands r0, r1
	strb r0, [r2]
	bl sub_0815937C
.L08158B8C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08158B9C
sub_08158B9C: @ 0x08158B9C
.L08158B9C:
	push {r4, r5, r6, lr}
	movs r2, #0
	ldr r0, .L08158BDC
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0xff
	beq .L08158BEE
	ldr r0, .L08158BE0
	ldrh r3, [r0]
	adds r5, r0, #2
	adds r6, r0, #0
	adds r6, #0x10
.L08158BB4:
	cmp r1, r3
	beq .L08158BBE
	ldrh r0, [r5]
	cmp r1, r0
	bne .L08158BE4
.L08158BBE:
	adds r0, r2, #1
	adds r0, r0, r4
	ldrb r1, [r0]
	cmp r1, r3
	beq .L08158BCE
	ldrh r0, [r5]
	cmp r1, r0
	bne .L08158BE4
.L08158BCE:
	adds r0, r2, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	strh r0, [r6]
	movs r0, #1
	b .L08158BF0
	.byte 0x00, 0x00
.L08158BDC: .4byte gUnknown_087F1AD3
.L08158BE0: .4byte 0x0203B8F8 @ EWRAM+0x3B8F8
.L08158BE4:
	adds r2, #3
	adds r0, r2, r4
	ldrb r1, [r0]
	cmp r1, #0xff
	bne .L08158BB4
.L08158BEE:
	movs r0, #0
.L08158BF0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08158BF8
sub_08158BF8: @ 0x08158BF8
.L08158BF8:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0
	ldr r2, .L08158C78
	ldrb r0, [r2]
	ldr r3, .L08158C7C
	cmp r0, #0xff
	beq .L08158C8E
	adds r5, r3, #0
	adds r5, #0x90
	ldrh r4, [r5]
	mov r8, r4
	movs r6, #0x92
	adds r6, r6, r3
	mov ip, r6
	adds r4, r3, #0
	adds r4, #0x94
	movs r7, #0xa0
	adds r7, r7, r3
	mov sb, r7
.L08158C24:
	cmp r0, r8
	beq .L08158C36
	mov r6, ip
	ldrh r6, [r6]
	cmp r0, r6
	beq .L08158C36
	ldrh r7, [r4]
	cmp r0, r7
	bne .L08158C80
.L08158C36:
	adds r0, r1, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	ldrh r6, [r5]
	cmp r0, r6
	beq .L08158C50
	mov r7, ip
	ldrh r7, [r7]
	cmp r0, r7
	beq .L08158C50
	ldrh r6, [r4]
	cmp r0, r6
	bne .L08158C80
.L08158C50:
	adds r0, r1, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	ldrh r7, [r5]
	cmp r0, r7
	beq .L08158C6A
	mov r6, ip
	ldrh r6, [r6]
	cmp r0, r6
	beq .L08158C6A
	ldrh r7, [r4]
	cmp r0, r7
	bne .L08158C80
.L08158C6A:
	adds r0, r1, #3
	adds r0, r0, r2
	ldrb r0, [r0]
	mov r1, sb
	strh r0, [r1]
	movs r0, #1
	b .L08158C98
.L08158C78: .4byte gUnknown_087F1AF2
.L08158C7C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08158C80:
	adds r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L08158C24
.L08158C8E:
	adds r1, r3, #0
	adds r1, #0xa6
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
.L08158C98:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_08158CA4
sub_08158CA4: @ 0x08158CA4
.L08158CA4:
	push {lr}
	ldr r0, .L08158CB8
	adds r0, #0xa0
	movs r1, #0xfb
	strh r1, [r0]
	bl sub_08158CBC
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08158CB8: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_08158CBC
sub_08158CBC: @ 0x08158CBC
.L08158CBC:
	push {r4, lr}
	ldr r4, .L08158CEC
	adds r3, r4, #0
	adds r3, #0xa4
	ldrb r0, [r3]
	movs r2, #0xfc
	ands r2, r0
	strb r2, [r3]
	adds r0, r4, #0
	adds r0, #0xa0
	ldrh r1, [r0]
	ldr r0, .L08158CF0
	cmp r1, r0
	beq .L08158CF4
	movs r0, #0x7f
	ands r0, r2
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0xa8
	movs r0, #1
	strh r0, [r1]
	bl sub_08158D20
	b .L08158D02
.L08158CEC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08158CF0: .4byte 0x0000FFFF
.L08158CF4:
	bl sub_08158E00
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
.L08158D02:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_08158D08
sub_08158D08: @ 0x08158D08
.L08158D08:
	push {lr}
	ldr r0, .L08158D1C
	adds r0, #0xa8
	movs r1, #0
	strh r1, [r0]
	bl sub_08158D20
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08158D1C: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_08158D20
sub_08158D20: @ 0x08158D20
.L08158D20:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, .L08158D64
	adds r5, r4, #0
	adds r5, #0xa0
	movs r0, #0xff
	mov r8, r0
	ldrb r0, [r5]
	strh r0, [r5]
	ldrh r0, [r5]
	adds r7, r4, #0
	adds r7, #0xa3
	adds r6, r4, #0
	adds r6, #0xa2
	adds r1, r7, #0
	adds r2, r6, #0
	bl sub_0815B9B8
	ldrh r0, [r5]
	bl sub_0815BA28
	cmp r0, #0
	bne .L08158D68
	mov r0, r8
	strh r0, [r5]
	movs r0, #0xff
	strb r0, [r6]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r7]
	adds r1, r4, #0
	b .L08158DE6
	.byte 0x00, 0x00
.L08158D64: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08158D68:
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8e
	ldrh r2, [r0]
	adds r0, #6
	strh r2, [r0]
	adds r0, #0x10
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne .L08158DF4
	adds r0, r4, #0
	adds r0, #0xa8
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08158DB8
	ldrh r1, [r5]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bne .L08158DB8
	mov r0, r8
	strh r0, [r5]
	movs r0, #0xff
	strb r0, [r6]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r7]
	adds r1, r4, #0
	b .L08158DE6
.L08158DB8:
	ldr r1, .L08158DF0
	adds r3, r1, #0
	adds r3, #0xa0
	adds r0, r1, #0
	adds r0, #0x92
	ldrh r2, [r3]
	ldrh r0, [r0]
	cmp r2, r0
	beq .L08158DD4
	adds r0, r1, #0
	adds r0, #0x90
	ldrh r0, [r0]
	cmp r2, r0
	bne .L08158DF4
.L08158DD4:
	movs r0, #0xff
	strh r0, [r3]
	adds r2, r1, #0
	adds r2, #0xa2
	strb r0, [r2]
	adds r2, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2]
.L08158DE6:
	adds r1, #0xa6
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
	b .L08158DF6
.L08158DF0: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08158DF4:
	movs r0, #1
.L08158DF6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_08158E00
sub_08158E00: @ 0x08158E00
.L08158E00:
	push {r4, lr}
	ldr r2, .L08158E2C
	adds r4, r2, #0
	adds r4, #0xa4
	ldrb r3, [r4]
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq .L08158E30
	adds r1, r2, #0
	adds r1, #0xa0
	movs r0, #0xfb
	strh r0, [r1]
	movs r0, #0x7f
	ands r0, r3
	strb r0, [r4]
	adds r1, #8
	movs r0, #1
	strh r0, [r1]
	bl sub_08158D20
	b .L08158E4C
.L08158E2C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08158E30:
	adds r1, r2, #0
	adds r1, #0xa0
	movs r0, #0xff
	strh r0, [r1]
	adds r1, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r1, #3
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
.L08158E4C:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08158E54
sub_08158E54: @ 0x08158E54
.L08158E54:
	ldr r2, .L08158E74
	adds r1, r2, #0
	adds r1, #0xa0
	movs r0, #0xff
	strh r0, [r1]
	adds r1, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r1, #3
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
	bx lr
.L08158E74: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_08158E78
sub_08158E78: @ 0x08158E78
.L08158E78:
	push {r4, lr}
	ldr r4, .L08158E8C
	adds r2, r4, #0
	adds r2, #0x96
	ldrb r0, [r2]
	cmp r0, #0x1a
	bls .L08158E90
	bl sub_08158F48
	b .L08158EC8
.L08158E8C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08158E90:
	ldr r1, .L08158EA4
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne .L08158EA8
	bl sub_08158ED0
	b .L08158EC8
	.byte 0x00, 0x00
.L08158EA4: .4byte gUnknown_087F15E0
.L08158EA8:
	cmp r1, #0xff
	beq .L08158EBA
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xa0
	strh r0, [r1]
	bl sub_08158D08
	b .L08158EC8
.L08158EBA:
	bl sub_08158E54
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
.L08158EC8:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08158ED0
sub_08158ED0: @ 0x08158ED0
.L08158ED0:
	push {r4, lr}
	ldr r4, .L08158F08
	adds r0, r4, #0
	adds r0, #0x90
	ldrh r1, [r0]
	subs r1, #0x32
	lsls r1, r1, #0x10
	adds r0, #2
	ldrh r0, [r0]
	subs r0, #0x32
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r1, r1, #0xd
	adds r1, r1, r0
	ldr r0, .L08158F0C
	adds r1, r1, r0
	ldrb r1, [r1]
	adds r0, r1, #0
	cmp r0, #0xff
	bne .L08158F10
	bl sub_08158E54
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
	b .L08158F42
.L08158F08: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08158F0C: .4byte gUnknown_087F15A0
.L08158F10:
	adds r0, r4, #0
	adds r0, #0xa2
	strb r1, [r0]
	ldr r0, .L08158F1C
	ldrb r4, [r0, #0xd]
	b .L08158F22
.L08158F1C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08158F20:
	subs r4, #1
.L08158F22:
	cmp r4, #0
	ble .L08158F34
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_08159438
	lsls r0, r0, #0x10
	cmp r0, #0
	blt .L08158F20
.L08158F34:
	cmp r4, #0
	beq .L08158F3E
	bl sub_08158D08
	b .L08158F42
.L08158F3E:
	bl sub_08158CA4
.L08158F42:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_08158F48
sub_08158F48: @ 0x08158F48
.L08158F48:
	push {r4, r5, lr}
	ldr r2, .L08158F70
	ldr r1, .L08158F74
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	subs r1, #5
	ldrb r1, [r1]
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r4, r0, #2
	adds r5, r2, #0
	adds r5, #0xa0
	b .L08158F7A
	.byte 0x00, 0x00
.L08158F70: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08158F74: .4byte gUnknown_087F15E0
.L08158F78:
	adds r4, #1
.L08158F7A:
	cmp r4, #0x62
	bgt .L08158F90
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_08159438
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt .L08158F78
	strh r0, [r5]
.L08158F90:
	cmp r4, #0x63
	beq .L08158F9A
	bl sub_08158D08
	b .L08158F9E
.L08158F9A:
	bl sub_08158CA4
.L08158F9E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_08158FA4
sub_08158FA4: @ 0x08158FA4
.L08158FA4:
	push {r4, r5, r6, lr}
	ldr r1, .L08158FC8
	adds r0, r1, #0
	adds r0, #0x96
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0x1a
	bhi .L08158FCC
	adds r0, r2, #0
	adds r0, #0x90
	ldrb r3, [r0]
	adds r0, #0xc
	ldrb r1, [r0]
	subs r0, #0xa
	ldrb r6, [r0]
	adds r0, #0xb
	b .L08158FEC
	.byte 0x00, 0x00
.L08158FC8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08158FCC:
	adds r0, r2, #0
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #0x1a
	bls .L08158FDC
	bl sub_08159098
	b .L08159090
.L08158FDC:
	adds r0, r2, #0
	adds r0, #0x92
	ldrb r3, [r0]
	adds r0, #0xb
	ldrb r1, [r0]
	subs r0, #0xd
	ldrb r6, [r0]
	adds r0, #0xc
.L08158FEC:
	ldrb r0, [r0]
	cmp r0, r1
	bls .L08159016
	adds r0, r2, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x9d
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L0815908C
	adds r0, r6, #0
	movs r1, #1
	bl sub_08159634
	bl sub_08158D08
	b .L08159090
.L08159016:
	adds r5, r2, #0
	adds r5, #0xa0
	strh r3, [r5]
	adds r0, r2, #0
	adds r0, #0x9c
	ldrb r1, [r0]
	adds r0, #1
	ldrb r0, [r0]
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #7
	bl __modsi3
	cmp r0, #0
	bne .L08159042
	ldrh r0, [r5]
	movs r1, #2
	bl sub_08159634
	bl sub_08158D08
	b .L08159090
.L08159042:
	adds r0, r4, #0
	movs r1, #5
	bl __modsi3
	cmp r0, #0
	bne .L0815905C
	ldrh r0, [r5]
	movs r1, #1
	bl sub_08159634
	bl sub_08158D08
	b .L08159090
.L0815905C:
	adds r0, r4, #0
	movs r1, #3
	bl __modsi3
	cmp r0, #0
	bne .L08159076
	ldrh r0, [r5]
	movs r1, #1
	bl sub_08159690
	bl sub_08158D08
	b .L08159090
.L08159076:
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	bne .L0815908C
	adds r0, r6, #0
	movs r1, #1
	bl sub_08159634
	bl sub_08158D08
	b .L08159090
.L0815908C:
	bl sub_08158CA4
.L08159090:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08159098
sub_08159098: @ 0x08159098
.L08159098:
	push {lr}
	ldr r1, .L081590B4
	adds r0, r1, #0
	adds r0, #0x9c
	adds r2, r1, #0
	adds r2, #0x9d
	ldrb r0, [r0]
	ldrb r2, [r2]
	cmp r0, r2
	blo .L081590B8
	adds r0, r1, #0
	adds r0, #0x90
	b .L081590BC
	.byte 0x00, 0x00
.L081590B4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081590B8:
	adds r0, r1, #0
	adds r0, #0x92
.L081590BC:
	ldrh r0, [r0]
	movs r1, #1
	bl sub_08159634
	bl sub_08158D08
	pop {r1}
	bx r1

	thumb_func_start sub_081590CC
sub_081590CC: @ 0x081590CC
.L081590CC:
	push {r4, lr}
	ldr r1, .L081590EC
	adds r0, r1, #0
	adds r0, #0x96
	ldrb r0, [r0]
	cmp r0, #0x1a
	bhi .L081590E4
	adds r0, r1, #0
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #0x1a
	bls .L081590F6
.L081590E4:
	bl sub_08158FA4
	b .L08159138
	.byte 0x00, 0x00
.L081590EC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081590F0:
	bl sub_08158D08
	b .L08159138
.L081590F6:
	adds r0, r1, #0
	adds r0, #0x99
	ldrb r0, [r0]
	adds r2, r1, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	adds r1, #0x9d
	ldrb r1, [r1]
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r4, r0, #3
	cmp r4, #0x62
	bgt .L0815912A
.L08159116:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_081594B4
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L081590F0
	adds r4, #1
	cmp r4, #0x62
	ble .L08159116
.L0815912A:
	bl sub_08158E54
	ldr r0, .L08159140
	adds r0, #0xa6
	movs r1, #0x40
	strb r1, [r0]
	movs r0, #0
.L08159138:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08159140: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_08159144
sub_08159144: @ 0x08159144
.L08159144:
	push {lr}
	bl Random_Byte
	adds r1, r0, #0
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0xff
	bne .L08159156
	movs r1, #0xfb
.L08159156:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start sub_0815915C
sub_0815915C: @ 0x0815915C
.L0815915C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, .L081591BC
	movs r0, #1
	str r0, [r1]
	ldr r4, .L081591C0
	adds r2, r4, #0
	adds r2, #0xa4
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	adds r2, #2
	ldrb r1, [r2]
	movs r0, #3
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x9d
	ldrb r1, [r1]
	ldr r2, .L081591C4
	adds r0, r0, r1
	ldrb r2, [r2, #0xd]
	adds r0, r0, r2
	movs r1, #3
	bl __divsi3
	adds r0, #4
	mov sl, r0
	adds r0, r4, #0
	adds r0, #0x99
	ldrb r0, [r0]
	cmp r0, #0xb
	bne .L081591CE
	adds r0, r4, #0
	adds r0, #0x90
	ldrh r5, [r0]
	adds r0, #2
	b .L081591D6
	.byte 0x00, 0x00
.L081591BC: .4byte 0x03006A38 @ IWRAM+0x6A38
.L081591C0: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081591C4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L081591C8:
	bl sub_08158D08
	b .L0815928C
.L081591CE:
	adds r0, r4, #0
	adds r0, #0x92
	ldrh r5, [r0]
	subs r0, #2
.L081591D6:
	ldrh r4, [r0]
	adds r0, r5, #0
	bl sub_0815B958
	movs r6, #3
	adds r1, r6, #0
	ands r1, r0
	cmp r1, #0
	beq .L081591EA
	movs r1, #1
.L081591EA:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	bl sub_0815B958
	adds r1, r6, #0
	ands r1, r0
	adds r7, r1, r5
	ldr r0, .L0815929C
	adds r0, r7, r0
	ldrb r0, [r0]
	mov r8, r6
	mov r1, r8
	ands r1, r0
	mov r8, r1
	movs r7, #0
	ldr r2, .L081592A0
	mov sb, r2
.L08159212:
	movs r6, #0
.L08159214:
	bl sub_08159144
	adds r1, r0, #0
	cmp r1, #0xff
	beq .L08159244
	ldr r5, .L081592A4
	adds r4, r5, #0
	adds r4, #0xa0
	strh r1, [r4]
	ldrh r0, [r4]
	bl sub_0815BA28
	cmp r0, #0
	beq .L08159244
	ldrh r1, [r4]
	mov r0, sb
	ldrh r0, [r0]
	cmp r1, r0
	beq .L08159244
	adds r0, r5, #0
	adds r0, #0x92
	ldrh r0, [r0]
	cmp r1, r0
	bne .L0815924C
.L08159244:
	adds r6, #1
	ldr r0, .L081592A8
	cmp r6, r0
	ble .L08159214
.L0815924C:
	ldr r5, .L081592A4
	adds r4, r5, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	bl sub_0815B9A0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, sl
	bge .L08159282
	ldrh r0, [r4]
	bl sub_0815B958
	movs r1, #3
	ands r1, r0
	cmp r1, r8
	bne .L08159282
	ldrh r1, [r4]
	mov r2, sb
	ldrh r2, [r2]
	cmp r1, r2
	beq .L08159282
	adds r0, r5, #0
	adds r0, #0x92
	ldrh r0, [r0]
	cmp r1, r0
	bne .L081591C8
.L08159282:
	adds r7, #1
	cmp r7, #0x1f
	ble .L08159212
	bl sub_08158CA4
.L0815928C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815929C: .4byte gUnknown_087F160B
.L081592A0: .4byte 0x0203B8F8 @ EWRAM+0x3B8F8
.L081592A4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081592A8: .4byte 0x000003E7

	thumb_func_start sub_081592AC
sub_081592AC: @ 0x081592AC
.L081592AC:
	push {r4, lr}
	ldr r1, .L081592CC
	adds r4, r1, #0
	adds r4, #0x96
	ldrb r0, [r4]
	cmp r0, #8
	bne .L081592D0
	adds r0, r1, #0
	adds r0, #0x90
	ldrh r2, [r0]
	adds r0, #2
	ldrh r3, [r0]
	adds r0, #5
	ldrb r1, [r0]
	b .L081592DC
	.byte 0x00, 0x00
.L081592CC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081592D0:
	adds r0, r1, #0
	adds r0, #0x92
	ldrh r2, [r0]
	subs r0, #2
	ldrh r3, [r0]
	ldrb r1, [r4]
.L081592DC:
	adds r0, r2, #0
	subs r0, #0x32
	asrs r4, r0, #1
	lsls r0, r1, #2
	adds r0, r0, r4
	ldr r1, .L08159300
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0xff
	bne .L08159308
	bl sub_08158E54
	ldr r0, .L08159304
	adds r0, #0xa6
	movs r1, #0x40
	strb r1, [r0]
	movs r0, #0
	b .L08159372
.L08159300: .4byte gUnknown_087F1611
.L08159304: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159308:
	ldrb r4, [r1]
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	bne .L08159314
	asrs r4, r4, #4
.L08159314:
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq .L08159348
	adds r0, r3, #0
	movs r1, #3
	ands r4, r1
	adds r1, r4, #0
	bl sub_08159634
	ldr r1, .L08159344
	adds r3, r1, #0
	adds r3, #0xa4
	adds r4, #1
	ldrb r2, [r3]
	adds r0, r4, #0
	orrs r0, r2
	strb r0, [r3]
	adds r1, #0xa6
	ldrb r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	orrs r0, r4
	b .L0815936C
.L08159344: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159348:
	adds r0, r3, #0
	movs r1, #0xf
	ands r4, r1
	adds r1, r4, #1
	bl sub_08159690
	ldr r1, .L08159378
	adds r2, r1, #0
	adds r2, #0xa4
	ldrb r0, [r2]
	movs r3, #1
	orrs r0, r3
	strb r0, [r2]
	adds r1, #0xa6
	ldrb r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	orrs r0, r3
.L0815936C:
	strb r0, [r1]
	bl sub_08158D08
.L08159372:
	pop {r4}
	pop {r1}
	bx r1
.L08159378: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815937C
sub_0815937C: @ 0x0815937C
.L0815937C:
	push {r4, lr}
	ldr r2, .L081593AC
	ldr r4, .L081593B0
	adds r0, r4, #0
	adds r0, #0x96
	ldrb r1, [r0]
	movs r0, #0x1a
	adds r3, r4, #0
	adds r3, #0x97
	muls r0, r1, r0
	ldrb r3, [r3]
	adds r0, r0, r3
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L081593B4
	bl sub_08158E54
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
	b .L081593E6
.L081593AC: .4byte gUnknown_087F16BD
.L081593B0: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081593B4:
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x9c
	ldrb r0, [r2]
	subs r1, #5
	ldrb r1, [r1]
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, #3
	strb r0, [r2]
	adds r4, r2, #0
	b .L081593D6
.L081593D0:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
.L081593D6:
	ldrb r0, [r4]
	bl sub_08159438
	lsls r0, r0, #0x10
	cmp r0, #0
	blt .L081593D0
	bl sub_08158D08
.L081593E6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_081593EC
sub_081593EC: @ 0x081593EC
.L081593EC:
	push {r4, lr}
	ldr r2, .L08159434
	adds r0, r2, #0
	adds r0, #0x90
	ldrh r1, [r0]
	movs r4, #0xff
	adds r0, r4, #0
	ands r0, r1
	adds r3, r2, #0
	adds r3, #0xa0
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0xfb
	bne .L08159416
	adds r0, r2, #0
	adds r0, #0x92
	ldrh r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r3]
.L08159416:
	ldrh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xa5
	strb r0, [r1]
	adds r2, #0xa4
	ldrb r1, [r2]
	movs r0, #0x80
	orrs r0, r1
	strb r0, [r2]
	bl sub_08158D08
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08159434: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_08159438
sub_08159438: @ 0x08159438
.L08159438:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, .L08159494
	adds r0, #0xa2
	ldrb r4, [r0]
	ldr r1, .L08159498
	adds r0, r4, r1
	ldrb r6, [r0]
	subs r0, r4, #1
	adds r0, r0, r1
	ldrb r5, [r0]
	cmp r4, #1
	beq .L08159458
	cmp r4, #0x23
	bne .L0815945E
.L08159458:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0815945E:
	movs r4, #0xff
	ands r4, r5
	adds r0, r4, #0
	bl Demon_GetRecord
	ldrb r0, [r0, #1]
	cmp r0, r7
	blo .L0815949C
.L0815946E:
	adds r0, r4, #0
	bl Demon_GetRecord
	ldrb r0, [r0, #1]
	cmp r0, r7
	beq .L08159488
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r4, #0xff
	ands r4, r5
	cmp r5, r6
	bne .L0815946E
.L08159488:
	cmp r5, r6
	bne .L0815949C
	movs r0, #1
	rsbs r0, r0, #0
	b .L081594AA
	.byte 0x00, 0x00
.L08159494: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159498: .4byte gUnknown_087F1514
.L0815949C:
	ldr r0, .L081594B0
	movs r1, #0xff
	ands r5, r1
	adds r0, #0xa0
	strh r5, [r0]
	movs r1, #0
	ldrsh r0, [r0, r1]
.L081594AA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L081594B0: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_081594B4
sub_081594B4: @ 0x081594B4
.L081594B4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r7, #0
	ldr r2, .L08159518
	movs r0, #0xff
	strb r0, [r2]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2, #1]
	strb r0, [r2, #2]
	strb r0, [r2, #0x10]
	strb r0, [r2, #0x11]
	strb r0, [r2, #0x12]
	adds r0, r2, #0
	adds r0, #0xa3
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r3, r0, r1
	movs r6, #0
	ldr r1, .L0815951C
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #0xff
	beq .L0815953E
.L081594EE:
	adds r0, r3, r4
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0xa2
	strb r1, [r0]
	mov r4, r8
	adds r5, r3, #1
	adds r6, #1
.L081594FE:
	adds r0, r4, #0
	bl sub_08159438
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L08159520
	ldr r0, .L08159518
	adds r0, r7, r0
	strb r1, [r0]
	adds r7, #1
	b .L0815952A
	.byte 0x00, 0x00
.L08159518: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815951C: .4byte gUnknown_087F1961
.L08159520:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x62
	bls .L081594FE
.L0815952A:
	adds r3, r5, #0
	ldr r2, .L08159550
	cmp r6, #2
	bgt .L0815953E
	ldr r0, .L08159554
	adds r1, r5, r0
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #0xff
	bne .L081594EE
.L0815953E:
	ldrb r0, [r2]
	cmp r0, #0xff
	beq .L08159558
	mov r0, r8
	bl sub_08159568
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L0815955C
.L08159550: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159554: .4byte gUnknown_087F1961
.L08159558:
	movs r0, #1
	rsbs r0, r0, #0
.L0815955C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08159568
sub_08159568: @ 0x08159568
.L08159568:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r4, .L081595E8
	ldrb r0, [r4]
	bl sub_0815B9A0
	strb r0, [r4, #0x10]
	ldrb r0, [r4, #1]
	cmp r0, #0xff
	beq .L08159590
	bl sub_0815B9A0
	strb r0, [r4, #0x11]
	ldrb r0, [r4, #2]
	cmp r0, #0xff
	beq .L08159590
	bl sub_0815B9A0
	strb r0, [r4, #0x12]
.L08159590:
	ldr r4, .L081595E8
	ldrb r0, [r4, #0x11]
	ldrb r1, [r4, #0x10]
	cmp r0, r1
	bhs .L081595A2
	movs r0, #1
	movs r1, #0
	bl sub_08159604
.L081595A2:
	ldrb r0, [r4, #0x12]
	ldrb r1, [r4, #0x11]
	cmp r0, r1
	bhs .L081595B2
	movs r0, #2
	movs r1, #1
	bl sub_08159604
.L081595B2:
	ldrb r0, [r4, #0x11]
	ldrb r1, [r4, #0x10]
	cmp r0, r1
	bhs .L081595C2
	movs r0, #1
	movs r1, #0
	bl sub_08159604
.L081595C2:
	movs r1, #0
	ldrb r0, [r4, #0x10]
	cmp r0, r5
	bhs .L081595EC
	ldrb r0, [r4, #0x11]
	cmp r0, #0xff
	beq .L081595EC
	movs r1, #1
	cmp r0, r5
	bhs .L081595EC
	ldrb r0, [r4, #0x12]
	cmp r0, #0xff
	beq .L081595EC
	movs r1, #2
	cmp r0, r5
	bhs .L081595EC
	movs r0, #1
	rsbs r0, r0, #0
	b .L081595FA
.L081595E8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081595EC:
	ldr r0, .L08159600
	adds r1, r1, r0
	adds r0, #0xa0
	ldrb r1, [r1]
	strh r1, [r0]
	movs r1, #0
	ldrsh r0, [r0, r1]
.L081595FA:
	pop {r4, r5}
	pop {r1}
	bx r1
.L08159600: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_08159604
sub_08159604: @ 0x08159604
.L08159604:
	push {r4, r5, r6, lr}
	ldr r5, .L08159630
	adds r4, r1, #0
	adds r4, #0x10
	adds r4, r4, r5
	ldrb r6, [r4]
	adds r2, r0, #0
	adds r2, #0x10
	adds r2, r2, r5
	ldrb r3, [r2]
	strb r3, [r4]
	strb r6, [r2]
	adds r1, r1, r5
	ldrb r3, [r1]
	adds r0, r0, r5
	ldrb r2, [r0]
	strb r2, [r1]
	strb r3, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08159630: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_08159634
sub_08159634: @ 0x08159634
.L08159634:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r2, .L08159688
	movs r1, #0xff
	ands r0, r1
	adds r6, r2, #0
	adds r6, #0xa0
	strh r0, [r6]
	ldr r4, .L0815968C
	ldrh r0, [r6]
	bl sub_0815B9DC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r0, #1
	adds r0, r0, r4
	ldrb r1, [r0]
	cmp r5, #0
	beq .L08159682
	ldrh r0, [r6]
	cmp r0, r1
	beq .L08159682
	adds r2, r6, #0
	adds r3, r1, #0
.L0815966A:
	ldrh r0, [r2]
	subs r1, r0, #1
	strh r1, [r2]
	subs r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq .L08159682
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	bne .L0815966A
.L08159682:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08159688: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815968C: .4byte gUnknown_087F1514

	thumb_func_start sub_08159690
sub_08159690: @ 0x08159690
.L08159690:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r2, .L081596E8
	movs r1, #0xff
	ands r0, r1
	adds r5, r2, #0
	adds r5, #0xa0
	strh r0, [r5]
	ldrh r0, [r5]
	bl sub_0815B9DC
	ldr r1, .L081596EC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r4, #0
	beq .L081596E2
	ldrh r0, [r5]
	cmp r0, r1
	beq .L081596E2
	adds r2, r5, #0
	adds r3, r1, #0
.L081596CA:
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L081596E2
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	bne .L081596CA
.L081596E2:
	pop {r4, r5}
	pop {r0}
	bx r0
.L081596E8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081596EC: .4byte gUnknown_087F1514

	thumb_func_start sub_081596F0
sub_081596F0: @ 0x081596F0
.L081596F0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, .L08159794
	adds r6, r4, #0
	adds r6, #0x90
	ldrh r1, [r6]
	adds r0, r4, #0
	adds r0, #0x8a
	movs r3, #0
	strh r1, [r0]
	adds r7, r4, #0
	adds r7, #0x92
	ldrh r5, [r7]
	adds r0, #2
	strh r5, [r0]
	movs r0, #0x94
	adds r0, r0, r4
	mov r8, r0
	ldrh r2, [r0]
	adds r0, r4, #0
	adds r0, #0x8e
	strh r2, [r0]
	subs r0, #0xa
	strh r1, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #0x1c
	strb r3, [r0]
	movs r0, #0xa6
	adds r0, r0, r4
	mov sb, r0
	strb r3, [r0]
	lsls r1, r1, #0x10
	lsls r0, r5, #0x10
	cmp r1, r0
	bls .L08159748
	ldrh r0, [r6]
	strh r5, [r6]
	strh r0, [r7]
.L08159748:
	mov r5, r8
	ldrh r1, [r5]
	ldrh r0, [r6]
	cmp r0, r1
	bls .L08159756
	strh r1, [r6]
	strh r0, [r5]
.L08159756:
	mov r0, r8
	ldrh r1, [r0]
	ldrh r0, [r7]
	cmp r0, r1
	bls .L08159766
	strh r1, [r7]
	mov r1, r8
	strh r0, [r1]
.L08159766:
	ldrh r0, [r6]
	movs r1, #0
	bl sub_0815B8F8
	cmp r0, #0
	beq .L0815978C
	ldrh r0, [r7]
	movs r1, #0
	bl sub_0815B8F8
	cmp r0, #0
	beq .L0815978C
	mov r5, r8
	ldrh r0, [r5]
	movs r1, #0
	bl sub_0815B8F8
	cmp r0, #0
	bne .L08159798
.L0815978C:
	bl sub_08158E00
	b .L081598C2
	.byte 0x00, 0x00
.L08159794: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159798:
	ldrh r0, [r6]
	ldr r1, .L081597F8
	ldr r2, .L081597FC
	bl sub_0815B9B8
	ldrh r0, [r7]
	movs r1, #0x97
	adds r1, r1, r4
	mov sl, r1
	ldr r1, .L08159800
	mov r2, sl
	bl sub_0815B9B8
	mov r5, r8
	ldrh r0, [r5]
	adds r5, r4, #0
	adds r5, #0x98
	ldr r1, .L08159804
	adds r2, r5, #0
	bl sub_0815B9B8
	ldrh r0, [r6]
	bl sub_0815B9A0
	adds r1, r4, #0
	adds r1, #0x9c
	strb r0, [r1]
	ldrh r0, [r7]
	bl sub_0815B9A0
	adds r1, r4, #0
	adds r1, #0x9d
	strb r0, [r1]
	mov r1, r8
	ldrh r0, [r1]
	bl sub_0815B9A0
	adds r1, r4, #0
	adds r1, #0x9e
	strb r0, [r1]
	bl sub_08158BF8
	cmp r0, #0
	beq .L08159808
	bl sub_08158D08
	b .L081598C2
	.byte 0x00, 0x00
.L081597F8: .4byte 0x0203B901 @ EWRAM+0x3B901
.L081597FC: .4byte 0x0203B8FE @ EWRAM+0x3B8FE
.L08159800: .4byte 0x0203B902 @ EWRAM+0x3B902
.L08159804: .4byte 0x0203B903 @ EWRAM+0x3B903
.L08159808:
	ldr r0, .L08159830
	ldrb r3, [r0]
	cmp r3, #8
	beq .L0815981E
	mov r0, sl
	ldrb r1, [r0]
	cmp r1, #8
	beq .L0815981E
	ldrb r2, [r5]
	cmp r2, #8
	bne .L08159838
.L0815981E:
	ldr r0, .L08159834
	adds r0, #0xa6
	ldrb r2, [r0]
	movs r1, #3
	ands r1, r2
	strb r1, [r0]
	bl sub_0815993C
	b .L081598C2
.L08159830: .4byte 0x0203B8FE @ EWRAM+0x3B8FE
.L08159834: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159838:
	cmp r3, #0x1a
	bls .L0815984C
	mov r5, sb
	ldrb r1, [r5]
	movs r0, #3
	ands r0, r1
	strb r0, [r5]
	bl sub_08159E9C
	b .L081598C2
.L0815984C:
	cmp r1, #0x1a
	bls .L08159862
	mov r0, sb
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	mov r1, sb
	strb r0, [r1]
	bl sub_08159DF0
	b .L081598C2
.L08159862:
	cmp r2, #0x1a
	bls .L08159876
	mov r5, sb
	ldrb r1, [r5]
	movs r0, #3
	ands r0, r1
	strb r0, [r5]
	bl sub_08159D50
	b .L081598C2
.L08159876:
	ldr r5, .L08159894
	ldrb r0, [r5]
	cmp r0, #0xb
	beq .L0815988E
	ldr r5, .L08159898
	ldrb r0, [r5]
	cmp r0, #0xb
	beq .L0815988E
	ldr r5, .L0815989C
	ldrb r0, [r5]
	cmp r0, #0xb
	bne .L081598A0
.L0815988E:
	bl sub_08159F18
	b .L081598C2
.L08159894: .4byte 0x0203B901 @ EWRAM+0x3B901
.L08159898: .4byte 0x0203B902 @ EWRAM+0x3B902
.L0815989C: .4byte 0x0203B903 @ EWRAM+0x3B903
.L081598A0:
	cmp r3, #0x16
	beq .L081598AC
	cmp r1, #0x16
	beq .L081598AC
	cmp r2, #0x16
	bne .L081598B2
.L081598AC:
	bl sub_0815A150
	b .L081598C2
.L081598B2:
	adds r2, r4, #0
	adds r2, #0xa6
	ldrb r1, [r2]
	movs r0, #3
	ands r0, r1
	strb r0, [r2]
	bl sub_0815A30C
.L081598C2:
	adds r3, r0, #0
	ldr r2, .L08159938
	adds r0, r2, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x8e
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	adds r0, #0xc
	ldrh r1, [r0]
	cmp r1, #0xff
	beq .L08159926
	adds r5, r2, #0
	adds r5, #0xa6
	ldrb r4, [r5]
	movs r0, #0x30
	ands r0, r4
	cmp r0, #0x30
	beq .L08159926
	adds r0, r1, #0
	subs r0, #0x32
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi .L08159910
	movs r0, #3
	ands r0, r4
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5]
.L08159910:
	adds r0, r2, #0
	adds r0, #0xa2
	ldrb r0, [r0]
	cmp r0, #0x1a
	bls .L08159926
	ldrb r0, [r5]
	movs r1, #3
	ands r1, r0
	movs r0, #0x20
	orrs r1, r0
	strb r1, [r5]
.L08159926:
	adds r0, r3, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08159938: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815993C
sub_0815993C: @ 0x0815993C
.L0815993C:
	push {lr}
	movs r2, #0
	ldr r3, .L0815997C
	adds r1, r3, #0
	adds r1, #0x96
	ldrb r1, [r1]
	cmp r1, #8
	bne .L0815994E
	movs r2, #1
.L0815994E:
	adds r1, r3, #0
	adds r1, #0x97
	ldrb r1, [r1]
	cmp r1, #8
	bne .L0815995E
	adds r1, r2, #1
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
.L0815995E:
	adds r1, r3, #0
	adds r1, #0x98
	ldrb r1, [r1]
	cmp r1, #8
	bne .L0815996E
	adds r1, r2, #1
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
.L0815996E:
	cmp r2, #2
	beq .L0815998C
	cmp r2, #2
	bgt .L08159980
	cmp r2, #1
	beq .L08159986
	b .L08159996
.L0815997C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159980:
	cmp r2, #3
	beq .L08159992
	b .L08159996
.L08159986:
	bl sub_0815999C
	b .L08159996
.L0815998C:
	bl sub_08159A60
	b .L08159996
.L08159992:
	bl sub_08159BFC
.L08159996:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815999C
sub_0815999C: @ 0x0815999C
.L0815999C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, .L081599CC
	adds r5, r0, #0
	adds r5, #0x96
	ldrb r4, [r5]
	adds r7, r0, #0
	cmp r4, #8
	bne .L081599D0
	adds r2, r7, #0
	adds r2, #0x94
	ldrb r3, [r2]
	adds r1, r7, #0
	adds r1, #0x90
	ldrh r0, [r1]
	strh r0, [r2]
	strh r3, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	b .L081599EC
	.byte 0x00, 0x00
.L081599CC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L081599D0:
	adds r5, r7, #0
	adds r5, #0x97
	ldrb r4, [r5]
	cmp r4, #8
	bne .L081599F2
	adds r0, r7, #0
	adds r0, #0x94
	ldrb r3, [r0]
	adds r2, r7, #0
	adds r2, #0x92
	ldrh r1, [r2]
	strh r1, [r0]
	strh r3, [r2]
	adds r0, #4
.L081599EC:
	ldrb r3, [r0]
	strb r4, [r0]
	strb r3, [r5]
.L081599F2:
	movs r0, #0x90
	adds r0, r0, r7
	mov sb, r0
	ldrh r6, [r0]
	movs r1, #0x92
	adds r1, r1, r7
	mov sl, r1
	ldrh r5, [r1]
	movs r0, #0x94
	adds r0, r0, r7
	mov r8, r0
	ldrh r4, [r0]
	bl sub_08158A34
	mov r1, sb
	strh r6, [r1]
	mov r0, sl
	strh r5, [r0]
	mov r1, r8
	strh r4, [r1]
	adds r5, r7, #0
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L08159A4E
	adds r4, r7, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	movs r1, #1
	bl sub_08159634
	ldrh r0, [r4]
	mov r1, sb
	strh r0, [r1]
	mov r1, r8
	ldrh r0, [r1]
	mov r1, sl
	strh r0, [r1]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L08159A4E
	bl sub_08158CBC
	b .L08159A52
.L08159A4E:
	bl sub_08158E00
.L08159A52:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_08159A60
sub_08159A60: @ 0x08159A60
.L08159A60:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, .L08159A8C
	adds r5, r0, #0
	adds r5, #0x97
	ldrb r4, [r5]
	adds r7, r0, #0
	cmp r4, #8
	beq .L08159A90
	adds r1, r7, #0
	adds r1, #0x90
	ldrb r3, [r1]
	adds r2, r7, #0
	adds r2, #0x92
	ldrh r0, [r2]
	strh r0, [r1]
	strh r3, [r2]
	b .L08159AAA
	.byte 0x00, 0x00
.L08159A8C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159A90:
	adds r5, r7, #0
	adds r5, #0x98
	ldrb r4, [r5]
	cmp r4, #8
	beq .L08159AB4
	adds r2, r7, #0
	adds r2, #0x90
	ldrb r3, [r2]
	adds r1, r7, #0
	adds r1, #0x94
	ldrh r0, [r1]
	strh r0, [r2]
	strh r3, [r1]
.L08159AAA:
	adds r0, r7, #0
	adds r0, #0x96
	ldrb r3, [r0]
	strb r4, [r0]
	strb r3, [r5]
.L08159AB4:
	mov r8, r7
	ldr r1, .L08159B5C
	ldrh r0, [r1]
	adds r3, r0, #0
	subs r3, #0x32
	movs r2, #3
	adds r1, r3, #0
	ands r1, r2
	movs r0, #0x94
	add r0, r8
	mov sl, r0
	ldrh r4, [r0]
	adds r5, r4, #0
	subs r5, #0x32
	adds r0, r5, #0
	ands r0, r2
	cmp r1, r0
	bne .L08159B8A
	mov r0, r8
	adds r0, #0x96
	ldrb r2, [r0]
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r7, .L08159B60
	adds r0, r0, r7
	ldrb r3, [r0]
	movs r6, #1
	ands r1, r6
	cmp r1, #0
	bne .L08159AFC
	lsrs r3, r3, #4
.L08159AFC:
	movs r4, #0xf
	ands r3, r4
	adds r0, r3, #0
	cmp r0, #0
	bne .L08159B0C
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L08159B0C:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	adds r0, r0, r2
	adds r0, r0, r7
	ldrb r2, [r0]
	ands r1, r6
	cmp r1, #0
	bne .L08159B24
	lsrs r2, r2, #4
.L08159B24:
	ands r2, r4
	adds r0, r2, #0
	cmp r0, #0
	bne .L08159B32
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L08159B32:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r1
	adds r0, #1
	lsls r2, r0, #0x10
	asrs r1, r2, #0x10
	cmp r1, #0
	bge .L08159B64
	rsbs r1, r1, #0
	mov r0, r8
	adds r0, #0x90
	ldrh r0, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_08159690
	bl sub_08158CBC
	b .L08159BEC
.L08159B5C: .4byte 0x0203B8FA @ EWRAM+0x3B8FA
.L08159B60: .4byte gUnknown_087F1611
.L08159B64:
	cmp r1, #0
	ble .L08159B7A
	mov r0, r8
	adds r0, #0x90
	ldrh r0, [r0]
	lsrs r1, r2, #0x10
	bl sub_08159634
	bl sub_08158CBC
	b .L08159BEC
.L08159B7A:
	mov r0, r8
	adds r0, #0x90
	ldrh r1, [r0]
	adds r0, #0x10
	strh r1, [r0]
	bl sub_08158CBC
	b .L08159BEC
.L08159B8A:
	movs r1, #0x90
	add r1, r8
	mov sb, r1
	ldrb r3, [r1]
	strh r4, [r1]
	mov r0, sl
	strh r3, [r0]
	ldrh r4, [r1]
	ldr r1, .L08159BE4
	ldrh r5, [r1]
	ldrh r6, [r0]
	bl sub_08158A34
	mov r0, sb
	strh r4, [r0]
	ldr r1, .L08159BE4
	strh r5, [r1]
	mov r0, sl
	strh r6, [r0]
	mov r5, r8
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L08159BE8
	adds r4, r7, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	movs r1, #1
	bl sub_08159634
	ldrh r0, [r4]
	mov r1, sb
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1]
	ldr r1, .L08159BE4
	strh r0, [r1]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L08159BE8
	bl sub_08158CBC
	b .L08159BEC
.L08159BE4: .4byte 0x0203B8FA @ EWRAM+0x3B8FA
.L08159BE8:
	bl sub_08158E00
.L08159BEC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08159BFC
sub_08159BFC: @ 0x08159BFC
.L08159BFC:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, .L08159C18
	adds r2, r0, #0
	adds r2, #0x90
	ldrh r1, [r2]
	mov r8, r0
	cmp r1, #0x35
	bls .L08159C1C
	movs r2, #0x36
	b .L08159CEE
.L08159C18: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159C1C:
	movs r0, #0x92
	add r0, r8
	mov sb, r0
	ldrh r0, [r0]
	cmp r0, #0x35
	bls .L08159C94
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r4, r8
	adds r4, #0x94
	ldrh r0, [r4]
	strh r0, [r2]
	strh r1, [r4]
	ldrh r5, [r2]
	mov r1, sb
	ldrh r6, [r1]
	ldrh r7, [r4]
	str r2, [sp]
	bl sub_08158A34
	ldr r2, [sp]
	strh r5, [r2]
	mov r3, sb
	strh r6, [r3]
	strh r7, [r4]
	adds r4, #0xe
	ldrb r0, [r4]
	cmp r0, #0xff
	bne .L08159C5C
	bl sub_08158E00
	b .L08159D38
.L08159C5C:
	mov r5, r8
	adds r5, #0xa0
	ldrh r0, [r5]
	strh r0, [r2]
	mov r0, sb
	strh r7, [r0]
	bl sub_08158A34
	ldrb r0, [r4]
	cmp r0, #0xff
	bne .L08159C78
	bl sub_08158E00
	b .L08159D38
.L08159C78:
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #1
	bl sub_08159634
	ldrh r0, [r5]
	cmp r0, r4
	bne .L08159D34
	ldr r0, .L08159C90
	strh r0, [r5]
	b .L08159D34
	.byte 0x00, 0x00
.L08159C90: .4byte 0x0000FFFF
.L08159C94:
	mov r4, r8
	adds r4, #0x94
	ldrh r0, [r4]
	cmp r0, #0x35
	bls .L08159CEC
	ldrh r5, [r2]
	mov r1, sb
	ldrh r6, [r1]
	adds r7, r0, #0
	str r2, [sp]
	bl sub_08158A34
	ldr r2, [sp]
	strh r5, [r2]
	mov r3, sb
	strh r6, [r3]
	strh r7, [r4]
	mov r5, r8
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	bne .L08159CC6
	bl sub_08158E00
	b .L08159D38
.L08159CC6:
	mov r4, r8
	adds r4, #0xa0
	ldrh r0, [r4]
	strh r0, [r2]
	mov r0, sb
	strh r7, [r0]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	bne .L08159CE2
	bl sub_08158E00
	b .L08159D38
.L08159CE2:
	ldrh r0, [r4]
	movs r1, #1
	bl sub_08159634
	b .L08159D34
.L08159CEC:
	movs r2, #0x32
.L08159CEE:
	lsls r1, r2, #0x10
	asrs r0, r1, #0x10
	ldr r6, .L08159D48
	cmp r0, #0x39
	bgt .L08159D24
	ldr r0, .L08159D4C
	ldrh r3, [r0]
	adds r5, r0, #4
	adds r4, r0, #2
.L08159D00:
	asrs r1, r1, #0x10
	cmp r3, r1
	beq .L08159D12
	ldrh r0, [r4]
	cmp r0, r1
	beq .L08159D12
	ldrh r0, [r5]
	cmp r0, r1
	bne .L08159D24
.L08159D12:
	lsls r0, r2, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	lsls r1, r2, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0x39
	ble .L08159D00
.L08159D24:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r0, #0x32
	adds r0, r0, r6
	mov r1, r8
	adds r1, #0xa0
	ldrb r0, [r0]
	strh r0, [r1]
.L08159D34:
	bl sub_08158CBC
.L08159D38:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08159D48: .4byte gUnknown_087F198B
.L08159D4C: .4byte 0x0203B8F8 @ EWRAM+0x3B8F8

	thumb_func_start sub_08159D50
sub_08159D50: @ 0x08159D50
.L08159D50:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
.L08159D5A:
	movs r0, #0
	ldr r1, .L08159DC0
	str r0, [r1]
	ldr r7, .L08159DC4
	movs r2, #0x90
	adds r2, r2, r7
	mov sb, r2
	ldrh r6, [r2]
	movs r0, #0x92
	adds r0, r0, r7
	mov sl, r0
	ldrh r5, [r0]
	movs r1, #0x94
	adds r1, r1, r7
	mov r8, r1
	ldrh r4, [r1]
	bl sub_08158A34
	mov r2, sb
	strh r6, [r2]
	mov r0, sl
	strh r5, [r0]
	mov r1, r8
	strh r4, [r1]
	adds r5, r7, #0
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L08159DB8
	adds r4, r7, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	movs r1, #1
	bl sub_08159634
	ldrh r0, [r4]
	mov r2, sb
	strh r0, [r2]
	mov r1, r8
	ldrh r0, [r1]
	mov r2, sl
	strh r0, [r2]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	bne .L08159DC8
.L08159DB8:
	bl sub_08158E00
	b .L08159DDC
	.byte 0x00, 0x00
.L08159DC0: .4byte 0x03006A38 @ IWRAM+0x6A38
.L08159DC4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159DC8:
	bl sub_08158CBC
	adds r1, r0, #0
	ldr r2, .L08159DEC
	ldr r0, [r2]
	cmp r0, #0
	beq .L08159DDA
	cmp r1, #0
	beq .L08159D5A
.L08159DDA:
	adds r0, r1, #0
.L08159DDC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08159DEC: .4byte 0x03006A38 @ IWRAM+0x6A38

	thumb_func_start sub_08159DF0
sub_08159DF0: @ 0x08159DF0
.L08159DF0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
.L08159DFA:
	movs r0, #0
	ldr r1, .L08159E6C
	str r0, [r1]
	ldr r7, .L08159E70
	movs r2, #0x90
	adds r2, r2, r7
	mov sb, r2
	ldrh r1, [r2]
	movs r0, #0x94
	adds r0, r0, r7
	mov r8, r0
	ldrh r0, [r0]
	strh r0, [r2]
	mov r2, r8
	strh r1, [r2]
	mov r0, sb
	ldrh r6, [r0]
	movs r1, #0x92
	adds r1, r1, r7
	mov sl, r1
	ldrh r4, [r1]
	ldrh r5, [r2]
	bl sub_08158A34
	mov r2, sb
	strh r6, [r2]
	mov r0, sl
	strh r4, [r0]
	mov r1, r8
	strh r5, [r1]
	adds r5, r7, #0
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L08159E64
	adds r4, r7, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	movs r1, #1
	bl sub_08159634
	ldrh r0, [r4]
	mov r2, sb
	strh r0, [r2]
	mov r1, r8
	ldrh r0, [r1]
	mov r2, sl
	strh r0, [r2]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	bne .L08159E74
.L08159E64:
	bl sub_08158E00
	b .L08159E88
	.byte 0x00, 0x00
.L08159E6C: .4byte 0x03006A38 @ IWRAM+0x6A38
.L08159E70: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159E74:
	bl sub_08158CBC
	adds r1, r0, #0
	ldr r2, .L08159E98
	ldr r0, [r2]
	cmp r0, #0
	beq .L08159E86
	cmp r1, #0
	beq .L08159DFA
.L08159E86:
	adds r0, r1, #0
.L08159E88:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08159E98: .4byte 0x03006A38 @ IWRAM+0x6A38

	thumb_func_start sub_08159E9C
sub_08159E9C: @ 0x08159E9C
.L08159E9C:
	push {r4, lr}
.L08159E9E:
	ldr r4, .L08159ED0
	movs r0, #0
	str r0, [r4]
	ldr r3, .L08159ED4
	adds r2, r3, #0
	adds r2, #0xa4
	ldrb r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x9c
	adds r1, r3, #0
	adds r1, #0x9d
	ldrb r2, [r0]
	ldrb r1, [r1]
	cmp r2, r1
	bhs .L08159ED8
	adds r0, #2
	ldrb r0, [r0]
	cmp r1, r0
	blo .L08159EE2
	adds r0, r3, #0
	adds r0, #0x92
	b .L08159EE6
.L08159ED0: .4byte 0x03006A38 @ IWRAM+0x6A38
.L08159ED4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159ED8:
	adds r0, r3, #0
	adds r0, #0x9e
	ldrb r0, [r0]
	cmp r2, r0
	bhs .L08159EF4
.L08159EE2:
	adds r0, r3, #0
	adds r0, #0x94
.L08159EE6:
	ldrh r0, [r0]
	movs r1, #3
	bl sub_08159634
	bl sub_08158CBC
	b .L08159F12
.L08159EF4:
	adds r0, r3, #0
	adds r0, #0x90
	ldrh r0, [r0]
	movs r1, #3
	bl sub_08159634
	bl sub_08158CBC
	adds r1, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	beq .L08159F10
	cmp r1, #0
	beq .L08159E9E
.L08159F10:
	adds r0, r1, #0
.L08159F12:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_08159F18
sub_08159F18: @ 0x08159F18
.L08159F18:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	movs r0, #0
	ldr r3, .L08159F5C
	adds r1, r3, #0
	adds r1, #0x99
	ldrb r6, [r1]
	cmp r6, #0xb
	bne .L08159F30
	movs r0, #1
.L08159F30:
	adds r1, r3, #0
	adds r1, #0x9a
	ldrb r5, [r1]
	cmp r5, #0xb
	bne .L08159F40
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
.L08159F40:
	adds r1, r3, #0
	adds r1, #0x9b
	ldrb r4, [r1]
	cmp r4, #0xb
	bne .L08159F50
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
.L08159F50:
	cmp r0, #1
	bls .L08159F60
	bl sub_08158E00
	b .L0815A050
	.byte 0x00, 0x00
.L08159F5C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159F60:
	adds r2, r3, #0
	adds r2, #0xa4
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	adds r2, #2
	ldrb r1, [r2]
	movs r0, #3
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	strb r0, [r2]
	cmp r6, #0xb
	beq .L08159F98
	cmp r5, #0xb
	bne .L08159F8C
	movs r0, #1
	movs r1, #0
	bl sub_0815A060
	b .L08159F98
.L08159F8C:
	cmp r4, #0xb
	bne .L08159F98
	movs r0, #2
	movs r1, #0
	bl sub_0815A060
.L08159F98:
	ldr r4, .L0815A000
	adds r0, r4, #0
	adds r0, #0x9d
	adds r1, r4, #0
	adds r1, #0x9e
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	blo .L08159FB2
	movs r0, #1
	movs r1, #2
	bl sub_0815A060
.L08159FB2:
	adds r1, r4, #0
	adds r1, #0x90
	movs r0, #0x92
	adds r0, r0, r4
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0x94
.L08159FC0:
	ldrh r4, [r1]
	mov r2, r8
	ldrh r5, [r2]
	ldrh r6, [r7]
	str r1, [sp]
	bl sub_08158A34
	ldr r1, [sp]
	strh r4, [r1]
	mov r2, r8
	strh r5, [r2]
	strh r6, [r7]
	cmp r0, #0
	beq .L08159FC0
	ldr r4, .L0815A000
	adds r5, r4, #0
	adds r5, #0xa0
	ldrh r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	strh r1, [r0]
	adds r0, #4
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	bl sub_08158A34
	cmp r0, #0
	bne .L0815A004
	adds r0, r4, #0
	b .L0815A046
.L0815A000: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A004:
	ldrh r0, [r5]
	movs r1, #1
	bl sub_08159634
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r5]
	ldrh r0, [r0]
	cmp r1, r0
	beq .L0815A044
	adds r0, r4, #0
	adds r0, #0x8c
	ldrh r0, [r0]
	cmp r1, r0
	beq .L0815A044
	adds r0, r4, #0
	adds r0, #0x8e
	ldrh r0, [r0]
	cmp r1, r0
	beq .L0815A044
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x30
	strb r0, [r1]
	ldrh r0, [r5]
	bl sub_0815BA28
	cmp r0, #0
	beq .L0815A044
	bl sub_08158CBC
	b .L0815A050
.L0815A044:
	ldr r0, .L0815A05C
.L0815A046:
	adds r0, #0xa6
	movs r1, #0x30
	strb r1, [r0]
	bl sub_08158CA4
.L0815A050:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L0815A05C: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815A060
sub_0815A060: @ 0x0815A060
.L0815A060:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r3, #0
	bne .L0815A070
	ldr r5, .L0815A120
.L0815A070:
	cmp r3, #1
	bne .L0815A076
	ldr r5, .L0815A124
.L0815A076:
	cmp r3, #2
	bne .L0815A07C
	ldr r5, .L0815A128
.L0815A07C:
	cmp r1, #0
	bne .L0815A082
	ldr r4, .L0815A120
.L0815A082:
	cmp r1, #1
	bne .L0815A088
	ldr r4, .L0815A124
.L0815A088:
	cmp r1, #2
	bne .L0815A08E
	ldr r4, .L0815A128
.L0815A08E:
	ldrb r2, [r4]
	ldrb r0, [r5]
	strb r0, [r4]
	strb r2, [r5]
	cmp r3, #0
	bne .L0815A09C
	ldr r5, .L0815A12C
.L0815A09C:
	cmp r3, #1
	bne .L0815A0A2
	ldr r5, .L0815A130
.L0815A0A2:
	cmp r3, #2
	bne .L0815A0A8
	ldr r5, .L0815A134
.L0815A0A8:
	cmp r1, #0
	bne .L0815A0AE
	ldr r4, .L0815A12C
.L0815A0AE:
	cmp r1, #1
	bne .L0815A0B4
	ldr r4, .L0815A130
.L0815A0B4:
	cmp r1, #2
	bne .L0815A0BA
	ldr r4, .L0815A134
.L0815A0BA:
	ldrb r2, [r4]
	ldrb r0, [r5]
	strb r0, [r4]
	strb r2, [r5]
	cmp r3, #0
	bne .L0815A0C8
	ldr r5, .L0815A138
.L0815A0C8:
	cmp r3, #1
	bne .L0815A0CE
	ldr r5, .L0815A13C
.L0815A0CE:
	cmp r3, #2
	bne .L0815A0D4
	ldr r5, .L0815A140
.L0815A0D4:
	cmp r1, #0
	bne .L0815A0DA
	ldr r4, .L0815A138
.L0815A0DA:
	cmp r1, #1
	bne .L0815A0E0
	ldr r4, .L0815A13C
.L0815A0E0:
	cmp r1, #2
	bne .L0815A0E6
	ldr r4, .L0815A140
.L0815A0E6:
	ldrb r2, [r4]
	ldrb r0, [r5]
	strb r0, [r4]
	strb r2, [r5]
	cmp r3, #0
	bne .L0815A0F4
	ldr r7, .L0815A144
.L0815A0F4:
	cmp r3, #1
	bne .L0815A0FA
	ldr r7, .L0815A148
.L0815A0FA:
	cmp r3, #2
	bne .L0815A100
	ldr r7, .L0815A14C
.L0815A100:
	cmp r1, #0
	bne .L0815A106
	ldr r6, .L0815A144
.L0815A106:
	cmp r1, #1
	bne .L0815A10C
	ldr r6, .L0815A148
.L0815A10C:
	cmp r1, #2
	bne .L0815A112
	ldr r6, .L0815A14C
.L0815A112:
	ldrh r1, [r6]
	ldrh r0, [r7]
	strh r0, [r6]
	strh r1, [r7]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0815A120: .4byte 0x0203B901 @ EWRAM+0x3B901
.L0815A124: .4byte 0x0203B902 @ EWRAM+0x3B902
.L0815A128: .4byte 0x0203B903 @ EWRAM+0x3B903
.L0815A12C: .4byte 0x0203B8FE @ EWRAM+0x3B8FE
.L0815A130: .4byte 0x0203B8FF @ EWRAM+0x3B8FF
.L0815A134: .4byte 0x0203B900 @ EWRAM+0x3B900
.L0815A138: .4byte 0x0203B904 @ EWRAM+0x3B904
.L0815A13C: .4byte 0x0203B905 @ EWRAM+0x3B905
.L0815A140: .4byte 0x0203B906 @ EWRAM+0x3B906
.L0815A144: .4byte 0x0203B8F8 @ EWRAM+0x3B8F8
.L0815A148: .4byte 0x0203B8FA @ EWRAM+0x3B8FA
.L0815A14C: .4byte 0x0203B8FC @ EWRAM+0x3B8FC

	thumb_func_start sub_0815A150
sub_0815A150: @ 0x0815A150
.L0815A150:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r2, #0
	ldr r1, .L0815A194
	adds r0, r1, #0
	adds r0, #0x96
	ldrb r4, [r0]
	cmp r4, #0x16
	bne .L0815A16A
	movs r2, #1
.L0815A16A:
	adds r0, r1, #0
	adds r0, #0x97
	ldrb r3, [r0]
	cmp r3, #0x16
	bne .L0815A17A
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
.L0815A17A:
	adds r0, r1, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0x16
	bne .L0815A18A
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
.L0815A18A:
	cmp r2, #3
	bne .L0815A198
	bl sub_0815A2F4
	b .L0815A220
.L0815A194: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A198:
	cmp r2, #2
	bne .L0815A1A2
	bl sub_0815A230
	b .L0815A220
.L0815A1A2:
	cmp r4, #0x16
	bne .L0815A1B0
	movs r0, #0
	movs r1, #2
	bl sub_0815A060
	b .L0815A1BC
.L0815A1B0:
	cmp r3, #0x16
	bne .L0815A1BC
	movs r0, #1
	movs r1, #2
	bl sub_0815A060
.L0815A1BC:
	ldr r7, .L0815A218
	movs r0, #0x90
	adds r0, r0, r7
	mov sb, r0
	ldrh r6, [r0]
	movs r1, #0x92
	adds r1, r1, r7
	mov r8, r1
	ldrh r5, [r1]
	adds r4, r7, #0
	adds r4, #0x94
	ldrh r0, [r4]
	mov sl, r0
	bl sub_08158A34
	mov r1, sb
	strh r6, [r1]
	mov r0, r8
	strh r5, [r0]
	mov r1, sl
	strh r1, [r4]
	adds r5, r7, #0
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L0815A21C
	adds r4, r7, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	mov r1, sb
	strh r0, [r1]
	mov r1, sl
	mov r0, r8
	strh r1, [r0]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L0815A21C
	ldrh r0, [r4]
	movs r1, #1
	bl sub_08159634
	bl sub_08158CBC
	b .L0815A220
.L0815A218: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A21C:
	bl sub_08158E00
.L0815A220:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815A230
sub_0815A230: @ 0x0815A230
.L0815A230:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, .L0815A25C
	adds r0, r1, #0
	adds r0, #0x96
	ldrb r0, [r0]
	cmp r0, #0x16
	bne .L0815A268
	adds r0, r1, #0
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #0x16
	beq .L0815A260
	movs r0, #0
	movs r1, #1
	bl sub_0815A060
	b .L0815A268
	.byte 0x00, 0x00
.L0815A25C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A260:
	movs r0, #0
	movs r1, #2
	bl sub_0815A060
.L0815A268:
	ldr r7, .L0815A2DC
	adds r0, r7, #0
	adds r0, #0x9d
	adds r1, r7, #0
	adds r1, #0x9e
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs .L0815A282
	movs r0, #1
	movs r1, #2
	bl sub_0815A060
.L0815A282:
	movs r0, #0x90
	adds r0, r0, r7
	mov sb, r0
	ldrh r6, [r0]
	movs r1, #0x92
	adds r1, r1, r7
	mov r8, r1
	ldrh r5, [r1]
	adds r4, r7, #0
	adds r4, #0x94
	ldrh r0, [r4]
	mov sl, r0
	bl sub_08158A34
	mov r1, sb
	strh r6, [r1]
	mov r0, r8
	strh r5, [r0]
	mov r1, sl
	strh r1, [r4]
	adds r5, r7, #0
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L0815A2E0
	adds r4, r7, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	mov r1, sb
	strh r0, [r1]
	mov r1, sl
	mov r0, r8
	strh r1, [r0]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L0815A2E0
	ldrh r0, [r4]
	movs r1, #1
	bl sub_08159634
	bl sub_08158CBC
	b .L0815A2E4
.L0815A2DC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A2E0:
	bl sub_08158E00
.L0815A2E4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815A2F4
sub_0815A2F4: @ 0x0815A2F4
.L0815A2F4:
	push {lr}
	ldr r0, .L0815A308
	adds r0, #0xa0
	movs r1, #0x35
	strh r1, [r0]
	bl sub_08158CBC
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815A308: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815A30C
sub_0815A30C: @ 0x0815A30C
.L0815A30C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r7, #0
	ldr r1, .L0815A3D0
	adds r0, r1, #0
	adds r0, #0x96
	ldrb r0, [r0]
	adds r6, r1, #0
	cmp r0, #0xc
	bhi .L0815A32A
	movs r7, #1
.L0815A32A:
	ldr r0, .L0815A3D4
	ldrb r0, [r0]
	mov r8, r0
	mov r1, r8
	cmp r1, #0xc
	bhi .L0815A340
	lsls r0, r7, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r7, r0, #0x10
.L0815A340:
	adds r3, r6, #0
	adds r3, #0x98
	ldrb r0, [r3]
	cmp r0, #0xc
	bhi .L0815A354
	lsls r0, r7, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r7, r0, #0x10
.L0815A354:
	lsls r0, r7, #0x12
	ldr r1, .L0815A3D8
	adds r0, r0, r1
	lsrs r7, r0, #0x10
	adds r0, r6, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	movs r1, #0x9d
	adds r1, r1, r6
	mov sl, r1
	ldrb r5, [r1]
	adds r0, r0, r5
	movs r1, #0x9e
	adds r1, r1, r6
	mov sb, r1
	ldrb r4, [r1]
	adds r0, r0, r4
	movs r1, #3
	str r3, [sp, #4]
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r3, [sp, #4]
	cmp r4, r5
	bls .L0815A3DC
	ldrb r2, [r3]
	mov r0, r8
	strb r0, [r3]
	ldr r1, .L0815A3D4
	strb r2, [r1]
	adds r3, r6, #0
	adds r3, #0x9b
	ldrb r2, [r3]
	adds r1, r6, #0
	adds r1, #0x9a
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r0, sb
	ldrb r2, [r0]
	mov r1, sl
	ldrb r0, [r1]
	mov r1, sb
	strb r0, [r1]
	mov r0, sl
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0x94
	ldrh r2, [r1]
	subs r3, #9
	ldrh r0, [r3]
	strh r0, [r1]
	strh r2, [r3]
	b .L0815A420
	.byte 0x00, 0x00
.L0815A3D0: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A3D4: .4byte 0x0203B8FF @ EWRAM+0x3B8FF
.L0815A3D8: .4byte 0xFFFC0000
.L0815A3DC:
	cmp r4, r5
	bne .L0815A420
	adds r4, r6, #0
	adds r4, #0x94
	adds r7, r6, #0
	adds r7, #0x92
	ldrh r5, [r7]
	ldrh r0, [r4]
	cmp r0, r5
	bhs .L0815A420
	ldrb r2, [r3]
	mov r1, r8
	strb r1, [r3]
	ldr r0, .L0815A46C
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x9b
	ldrb r2, [r3]
	adds r1, r6, #0
	adds r1, #0x9a
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r1, sb
	ldrb r2, [r1]
	mov r1, sl
	ldrb r0, [r1]
	mov r1, sb
	strb r0, [r1]
	mov r0, sl
	strb r2, [r0]
	ldrh r2, [r4]
	strh r5, [r4]
	strh r2, [r7]
.L0815A420:
	movs r1, #0x9d
	adds r1, r1, r6
	mov ip, r1
	movs r0, #0x9c
	adds r0, r0, r6
	mov r8, r0
	ldrb r4, [r0]
	ldrb r1, [r1]
	adds r0, r4, #0
	cmp r1, r0
	bls .L0815A470
	adds r3, r6, #0
	adds r3, #0x97
	ldrb r2, [r3]
	adds r1, r6, #0
	adds r1, #0x96
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	adds r3, #3
	ldrb r2, [r3]
	adds r1, #3
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r1, ip
	ldrb r2, [r1]
	strb r4, [r1]
	mov r0, r8
	strb r2, [r0]
	subs r3, #8
	ldrh r2, [r3]
	adds r1, r6, #0
	adds r1, #0x90
	ldrh r0, [r1]
	strh r0, [r3]
	strh r2, [r1]
	b .L0815A4B4
.L0815A46C: .4byte 0x0203B8FF @ EWRAM+0x3B8FF
.L0815A470:
	cmp r1, r0
	bne .L0815A4B4
	adds r5, r6, #0
	adds r5, #0x92
	movs r1, #0x90
	adds r1, r1, r6
	mov sb, r1
	ldrh r7, [r1]
	ldrh r0, [r5]
	cmp r0, r7
	bhs .L0815A4B4
	adds r3, r6, #0
	adds r3, #0x97
	ldrb r2, [r3]
	adds r1, r6, #0
	adds r1, #0x96
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	adds r3, #3
	ldrb r2, [r3]
	adds r1, #3
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r0, ip
	ldrb r2, [r0]
	strb r4, [r0]
	mov r1, r8
	strb r2, [r1]
	ldrh r2, [r5]
	strh r7, [r5]
	mov r0, sb
	strh r2, [r0]
.L0815A4B4:
	movs r1, #0x9e
	adds r1, r1, r6
	mov ip, r1
	movs r0, #0x9d
	adds r0, r0, r6
	mov r8, r0
	ldrb r4, [r0]
	ldrb r1, [r1]
	adds r0, r4, #0
	cmp r1, r0
	bls .L0815A500
	adds r1, r6, #0
	adds r1, #0x98
	ldrb r2, [r1]
	adds r3, r6, #0
	adds r3, #0x97
	ldrb r0, [r3]
	strb r0, [r1]
	strb r2, [r3]
	adds r3, #4
	ldrb r2, [r3]
	adds r1, #2
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r1, ip
	ldrb r2, [r1]
	strb r4, [r1]
	mov r0, r8
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0x94
	ldrh r2, [r1]
	subs r3, #9
	ldrh r0, [r3]
	strh r0, [r1]
	strh r2, [r3]
	b .L0815A546
.L0815A500:
	cmp r1, r0
	bne .L0815A546
	adds r5, r6, #0
	adds r5, #0x94
	movs r1, #0x92
	adds r1, r1, r6
	mov sb, r1
	ldrh r7, [r1]
	ldrh r0, [r5]
	cmp r0, r7
	bhs .L0815A546
	adds r0, r6, #0
	adds r0, #0x98
	ldrb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x97
	ldrb r1, [r3]
	strb r1, [r0]
	strb r2, [r3]
	adds r3, #4
	ldrb r2, [r3]
	adds r1, r6, #0
	adds r1, #0x9a
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r0, ip
	ldrb r2, [r0]
	strb r4, [r0]
	mov r1, r8
	strb r2, [r1]
	ldrh r2, [r5]
	strh r7, [r5]
	mov r0, sb
	strh r2, [r0]
.L0815A546:
	adds r0, r6, #0
	adds r0, #0x99
	adds r1, r6, #0
	adds r1, #0x9a
	ldrb r2, [r0]
	ldrb r1, [r1]
	cmp r2, r1
	bne .L0815A55E
	adds r0, #2
	ldrb r0, [r0]
	cmp r2, r0
	beq .L0815A59E
.L0815A55E:
	adds r7, r6, #0
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	adds r5, r7, #0
	adds r5, #0x9a
	adds r2, r7, #0
	adds r2, #0x97
	adds r1, r5, #0
	bl sub_0815B9B8
	adds r0, r7, #0
	adds r0, #0x94
	ldrh r0, [r0]
	adds r4, r7, #0
	adds r4, #0x9b
	adds r2, r7, #0
	adds r2, #0x98
	adds r1, r4, #0
	bl sub_0815B9B8
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldrb r4, [r4]
	adds r2, r0, r4
	ldr r0, .L0815A5A4
	adds r0, r2, r0
	ldrb r5, [r0]
	cmp r5, #0xff
	bne .L0815A5A8
.L0815A59E:
	bl sub_0815A670
	b .L0815A658
.L0815A5A4: .4byte gUnknown_087F1993
.L0815A5A8:
	adds r0, r7, #0
	adds r0, #0x90
	ldrh r0, [r0]
	adds r4, r7, #0
	adds r4, #0x99
	adds r2, r7, #0
	adds r2, #0x96
	adds r1, r4, #0
	bl sub_0815B9B8
	ldrb r1, [r4]
	movs r0, #0x16
	muls r0, r1, r0
	adds r2, r5, r0
	ldr r0, .L0815A5EC
	adds r0, r2, r0
	ldrb r0, [r0]
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
	cmp r0, #0xff
	beq .L0815A5FC
.L0815A5D4:
	ldr r1, [sp]
	lsls r4, r1, #0x10
	lsrs r0, r4, #0x10
	bl sub_08159438
	lsls r0, r0, #0x10
	cmp r0, #0
	blt .L0815A5F0
	bl sub_08158CBC
	b .L0815A658
	.byte 0x00, 0x00
.L0815A5EC: .4byte gUnknown_087F1A23
.L0815A5F0:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	b .L0815A5D4
.L0815A5FC:
	adds r2, r6, #0
	adds r2, #0xa4
	ldrb r0, [r2]
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	adds r2, #2
	ldrb r1, [r2]
	movs r0, #3
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	strb r0, [r2]
.L0815A616:
	bl sub_08159144
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xff
	beq .L0815A616
	ldr r0, .L0815A668
	adds r4, r0, #0
	adds r4, #0xa0
	strh r1, [r4]
	ldrh r0, [r4]
	bl sub_0815BA28
	cmp r0, #0
	beq .L0815A616
	ldrh r0, [r4]
	bl sub_0815B9A0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L0815A66C
	ldrb r1, [r1, #0xd]
	cmp r0, r1
	bhs .L0815A616
	bl sub_08158CBC
	adds r1, r0, #0
	cmp r1, #0
	beq .L0815A616
	ldrh r0, [r4]
	cmp r0, #0xfe
	bhi .L0815A616
	adds r0, r1, #0
.L0815A658:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L0815A668: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A66C: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_0815A670
sub_0815A670: @ 0x0815A670
.L0815A670:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r7, .L0815A6D8
	ldr r0, .L0815A6DC
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x90
	ldrh r0, [r2]
	ldr r3, .L0815A6DC
	strh r0, [r3]
	strh r1, [r2]
	ldrh r6, [r2]
	movs r0, #0x92
	adds r0, r0, r7
	mov r8, r0
	ldrh r5, [r0]
	ldrh r4, [r3]
	str r2, [sp]
	bl sub_08158A34
	ldr r2, [sp]
	strh r6, [r2]
	mov r3, r8
	strh r5, [r3]
	ldr r0, .L0815A6DC
	strh r4, [r0]
	adds r6, r7, #0
	adds r6, #0xa2
	ldrb r0, [r6]
	cmp r0, #0xff
	beq .L0815A6E0
	adds r5, r7, #0
	adds r5, #0xa0
	ldrh r0, [r5]
	strh r0, [r2]
	mov r3, r8
	strh r4, [r3]
	bl sub_08158A34
	ldrb r0, [r6]
	cmp r0, #0xff
	beq .L0815A6E0
	ldrh r0, [r5]
	movs r1, #1
	bl sub_08159634
	bl sub_08158CBC
	b .L0815A6E4
	.byte 0x00, 0x00
.L0815A6D8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A6DC: .4byte 0x0203B8FC @ EWRAM+0x3B8FC
.L0815A6E0:
	bl sub_08158E00
.L0815A6E4:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0815A6F0
sub_0815A6F0: @ 0x0815A6F0
.L0815A6F0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r5, .L0815A7BC
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r7, [r0]
	adds r0, r7, #0
	bl Demon_GetRecord
	ldrb r1, [r0, #0x1e]
	movs r0, #0xf
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0x80
	movs r3, #0
	strb r0, [r1]
	movs r0, #0x94
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r0, #0xff
	strb r0, [r4]
	ldr r2, .L0815A7C0
	adds r1, r5, r2
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2]
	ldr r0, .L0815A7C4
	adds r1, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x81
	strb r3, [r1]
	adds r0, r5, #0
	adds r0, #0x82
	strb r3, [r0]
	movs r6, #0
	mov sb, r5
	movs r3, #0x83
	add r3, sb
	mov r8, r3
	adds r3, r0, #0
	mov sl, r4
	adds r4, r2, #0
	adds r5, r1, #0
.L0815A760:
	adds r0, r7, #0
	str r3, [sp]
	bl Demon_GetRecord
	adds r0, #0x11
	adds r0, r0, r6
	ldrb r0, [r0]
	mov r1, r8
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, [sp]
	cmp r0, #0xff
	beq .L0815A7E6
	cmp r0, #0x3f
	bhi .L0815A79A
	ldrb r0, [r1]
	bl sub_0815AE68
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r3, [sp]
	cmp r1, #0xf
	beq .L0815A79A
	mov r0, sb
	adds r0, #0x80
	ldrb r0, [r0]
	cmp r1, r0
	beq .L0815A7C8
.L0815A79A:
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r4
	mov r2, r8
	ldrb r1, [r2]
	strb r1, [r0]
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, #1
	adds r0, r0, r4
	movs r1, #0xff
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	b .L0815A7E6
	.byte 0x00, 0x00
.L0815A7BC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A7C0: .4byte 0x00000251
.L0815A7C4: .4byte 0x00000271
.L0815A7C8:
	movs r0, #0
	ldrsb r0, [r5, r0]
	add r0, sl
	mov r2, r8
	ldrb r1, [r2]
	strb r1, [r0]
	movs r0, #0
	ldrsb r0, [r5, r0]
	adds r0, #1
	add r0, sl
	movs r1, #0xff
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
.L0815A7E6:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #5
	bls .L0815A760
	ldr r4, .L0815A85C
	adds r5, r4, #0
	adds r5, #0x81
	movs r0, #0
	strb r0, [r5]
	adds r1, r4, #0
	adds r1, #0x82
	strb r0, [r1]
	adds r1, #0x2e
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r6, r4, r3
	strb r0, [r6]
	ldr r0, .L0815A860
	adds r1, r4, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, .L0815A864
	adds r1, r4, r3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	bl sub_0815ABA8
	adds r0, r4, #0
	adds r0, #0x92
	ldrh r0, [r0]
	bl sub_0815ABA8
	adds r0, r4, #0
	adds r0, #0x90
	ldrh r0, [r0]
	bl sub_0815ABA8
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bne .L0815A876
	bl sub_0815A99C
	b .L0815A984
	.byte 0x00, 0x00
.L0815A85C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A860: .4byte 0x00000181
.L0815A864: .4byte 0x00000291
.L0815A868:
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	bl sub_0815AA30
	b .L0815A984
.L0815A876:
	movs r7, #0
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0xff
	beq .L0815A8BA
	adds r2, r5, #0
	adds r4, r6, #0
	adds r3, r1, #0
	movs r5, #0xff
.L0815A88C:
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r1, r1, r4
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r1]
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r1, #1
	adds r1, r1, r4
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A88C
.L0815A8BA:
	adds r4, r6, #0
	adds r0, r4, #0
	bl sub_0815AB38
	movs r7, #0
	movs r6, #0
	adds r1, r4, #0
	adds r1, #0xf0
	ldrb r0, [r1]
	cmp r0, #0xff
	beq .L0815A8FA
	subs r4, #0xd0
	adds r3, r1, #0
	movs r5, #0xff
.L0815A8D6:
	adds r1, r6, r4
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, r6, #1
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A8D6
.L0815A8FA:
	movs r6, #0
	ldr r0, .L0815A994
	adds r2, r0, #0
	adds r2, #0xb0
	ldrb r1, [r2]
	adds r3, r0, #0
	cmp r1, #0xff
	beq .L0815A91A
	adds r1, r2, #0
.L0815A90C:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A90C
.L0815A91A:
	movs r7, #0
	cmp r6, #6
	beq .L0815A976
	movs r1, #0xff
	mov r8, r1
	ldr r5, .L0815A998
.L0815A926:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	adds r0, r7, r0
	ldrb r2, [r0]
	adds r1, r2, #0
	mov r3, r8
	ands r1, r3
	cmp r1, #0xff
	beq .L0815A868
	adds r0, r6, r5
	strb r2, [r0]
	adds r1, r6, #1
	adds r1, r1, r5
	ldrb r2, [r1]
	mov r0, r8
	orrs r0, r2
	strb r0, [r1]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r4, r5, #0
	adds r0, r4, #0
	bl sub_0815AAC8
	movs r6, #0
	ldrb r0, [r4]
	cmp r0, #0xff
	beq .L0815A970
	adds r1, r4, #0
.L0815A962:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A962
.L0815A970:
	ldr r3, .L0815A994
	cmp r6, #6
	bne .L0815A926
.L0815A976:
	adds r0, r3, #0
	adds r0, #0xb0
	adds r0, r6, r0
	movs r1, #0xff
	strb r1, [r0]
	bl sub_0815AAC4
.L0815A984:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0815A994: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A998: .4byte 0x0203B918 @ EWRAM+0x3B918

	thumb_func_start sub_0815A99C
sub_0815A99C: @ 0x0815A99C
.L0815A99C:
	push {r4, r5, r6, lr}
	ldr r4, .L0815AA24
	adds r0, r4, #0
	adds r0, #0x20
	bl sub_0815AB38
	movs r3, #0
	movs r2, #0
	ldrb r0, [r4]
	cmp r0, #0xff
	beq .L0815A9DC
	ldr r0, .L0815AA28
	adds r5, r4, r0
	movs r6, #0xff
.L0815A9B8:
	adds r1, r2, r5
	adds r0, r3, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, #1
	adds r1, r2, r5
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A9B8
.L0815A9DC:
	movs r3, #0
	ldr r1, .L0815AA2C
	movs r0, #0x94
	lsls r0, r0, #2
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0xff
	beq .L0815AA16
	adds r5, r1, #0
	adds r5, #0xb0
	movs r6, #0xff
.L0815A9F2:
	adds r1, r2, r5
	adds r0, r3, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, #1
	adds r1, r2, r5
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A9F2
.L0815AA16:
	adds r0, r3, #0
	adds r1, r2, #0
	bl sub_0815AA30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0815AA24: .4byte 0x0203BAD8 @ EWRAM+0x3BAD8
.L0815AA28: .4byte 0xFFFFFE40
.L0815AA2C: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815AA30
sub_0815AA30: @ 0x0815AA30
.L0815AA30:
	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r4, .L0815AAB8
	adds r0, r4, #0
	adds r0, #0x20
	bl sub_0815AB38
	ldr r0, .L0815AABC
	adds r4, r4, r0
	adds r0, r4, #0
	bl sub_0815AAC8
	movs r3, #0
	ldrb r0, [r4]
	cmp r0, #0xff
	beq .L0815AA60
	adds r1, r4, #0
.L0815AA52:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815AA52
.L0815AA60:
	ldr r6, .L0815AAC0
	cmp r3, #5
	bhi .L0815AAA2
	adds r2, r5, #0
	adds r2, #0x20
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	beq .L0815AAA2
	adds r4, r1, #0
	adds r7, r6, #0
	adds r7, #0xb0
.L0815AA7E:
	adds r1, r3, r7
	adds r0, r2, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #5
	bhi .L0815AAA2
	adds r2, r5, #0
	adds r2, #0x20
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815AA7E
.L0815AAA2:
	adds r0, r6, #0
	adds r0, #0xb0
	adds r0, r3, r0
	movs r1, #0xff
	strb r1, [r0]
	bl sub_0815AAC4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815AAB8: .4byte 0x0203BAD8 @ EWRAM+0x3BAD8
.L0815AABC: .4byte 0xFFFFFE40
.L0815AAC0: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815AAC4
sub_0815AAC4: @ 0x0815AAC4
.L0815AAC4:
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0815AAC8
sub_0815AAC8: @ 0x0815AAC8
.L0815AAC8:
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldrb r0, [r3]
	cmp r0, #0xff
	beq .L0815AB32
	ldrb r0, [r3, #1]
	cmp r0, #0xff
	beq .L0815AB32
	movs r7, #0
	movs r5, #0
.L0815AADC:
	adds r0, r5, r3
	ldrb r0, [r0, #1]
	adds r1, r7, #1
	mov ip, r1
	cmp r0, #0xff
	beq .L0815AB22
.L0815AAE8:
	adds r2, r3, r7
	adds r6, r5, r3
	ldrb r4, [r6, #1]
	ldrb r1, [r2]
	adds r0, r4, #0
	cmp r1, r0
	bne .L0815AB0A
	adds r2, r5, #0
.L0815AAF8:
	adds r0, r2, r3
	ldrb r1, [r0, #2]
	strb r1, [r0, #1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r1, #0xff
	bne .L0815AAF8
	b .L0815AADC
.L0815AB0A:
	cmp r1, r0
	bls .L0815AB14
	ldrb r1, [r2]
	strb r4, [r2]
	strb r1, [r6, #1]
.L0815AB14:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r5, r3
	ldrb r0, [r0, #1]
	cmp r0, #0xff
	bne .L0815AAE8
.L0815AB22:
	mov r1, ip
	lsls r0, r1, #0x18
	lsrs r7, r0, #0x18
	adds r5, r7, #0
	adds r0, r7, r3
	ldrb r0, [r0, #1]
	cmp r0, #0xff
	bne .L0815AADC
.L0815AB32:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0815AB38
sub_0815AB38: @ 0x0815AB38
.L0815AB38:
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldrb r0, [r3]
	cmp r0, #0xff
	beq .L0815ABA2
	ldrb r0, [r3, #1]
	cmp r0, #0xff
	beq .L0815ABA2
	movs r7, #0
	movs r4, #0
.L0815AB4C:
	adds r0, r4, r3
	ldrb r0, [r0, #1]
	adds r1, r7, #1
	mov ip, r1
	cmp r0, #0xff
	beq .L0815AB7C
.L0815AB58:
	adds r2, r3, r7
	adds r6, r4, r3
	ldrb r5, [r6, #1]
	ldrb r1, [r2]
	adds r0, r5, #0
	cmp r1, r0
	beq .L0815AB8E
	cmp r1, r0
	bhs .L0815AB6E
	strb r5, [r2]
	strb r1, [r6, #1]
.L0815AB6E:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, r3
	ldrb r0, [r0, #1]
	cmp r0, #0xff
	bne .L0815AB58
.L0815AB7C:
	mov r1, ip
	lsls r0, r1, #0x18
	lsrs r4, r0, #0x18
	adds r7, r4, #0
	adds r0, r4, r3
	ldrb r0, [r0, #1]
	cmp r0, #0xff
	bne .L0815AB4C
	b .L0815ABA2
.L0815AB8E:
	adds r2, r4, #0
.L0815AB90:
	adds r0, r2, r3
	ldrb r1, [r0, #2]
	strb r1, [r0, #1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r1, #0xff
	bne .L0815AB90
	b .L0815AB4C
.L0815ABA2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0815ABA8
sub_0815ABA8: @ 0x0815ABA8
.L0815ABA8:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L0815ABE4
	cmp r4, r0
	bne .L0815ABB6
	b .L0815AD80
.L0815ABB6:
	adds r0, r4, #0
	bl sub_080C3560
	adds r5, r0, #0
	cmp r5, #0
	bne .L0815ABC4
	b .L0815AD80
.L0815ABC4:
	movs r0, #0xff
	ands r0, r4
	bl Demon_GetRecord
	ldrb r1, [r0, #0x1e]
	ldr r0, .L0815ABE8
	adds r0, #0x80
	ldrb r0, [r0]
	cmp r1, r0
	bne .L0815ACA6
	movs r7, #0
.L0815ABDA:
	lsls r0, r7, #2
	ldr r1, .L0815ABEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L0815ABE4: .4byte 0x0000FFFF
.L0815ABE8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ABEC: .4byte gUnknown_0815ABF0
	.global gUnknown_0815ABF0
gUnknown_0815ABF0:
.L0815ABF0: @ jump table
	.4byte .L0815AC08
	.4byte .L0815AC14
	.4byte .L0815AC20
	.4byte .L0815AC2C
	.4byte .L0815AC38
	.4byte .L0815AC44
.L0815AC08:
	ldr r0, .L0815AC10
	adds r1, r5, #0
	adds r1, #0x5d
	b .L0815AC4A
.L0815AC10: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AC14:
	ldr r0, .L0815AC1C
	adds r1, r5, #0
	adds r1, #0x5e
	b .L0815AC4A
.L0815AC1C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AC20:
	ldr r0, .L0815AC28
	adds r1, r5, #0
	adds r1, #0x5f
	b .L0815AC4A
.L0815AC28: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AC2C:
	ldr r0, .L0815AC34
	adds r1, r5, #0
	adds r1, #0x60
	b .L0815AC4A
.L0815AC34: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AC38:
	ldr r0, .L0815AC40
	adds r1, r5, #0
	adds r1, #0x61
	b .L0815AC4A
.L0815AC40: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AC44:
	ldr r0, .L0815ACB4
	adds r1, r5, #0
	adds r1, #0x62
.L0815AC4A:
	ldrb r1, [r1]
	adds r0, #0x83
	strb r1, [r0]
	ldr r4, .L0815ACB4
	adds r6, r4, #0
	adds r6, #0x83
	ldrb r0, [r6]
	cmp r0, #0x3f
	bhi .L0815AC9C
	bl sub_0815AE68
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r4, #0
	adds r0, #0x80
	ldrb r0, [r0]
	cmp r1, r0
	bne .L0815AC9C
	bl sub_0815ADCC
	cmp r0, #0
	bne .L0815AC9C
	adds r3, r4, #0
	adds r3, #0x81
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r4, r0
	adds r1, r1, r2
	ldrb r0, [r6]
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, #1
	adds r0, r0, r2
	movs r1, #0xff
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
.L0815AC9C:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #5
	bls .L0815ABDA
.L0815ACA6:
	movs r7, #0
.L0815ACA8:
	lsls r0, r7, #2
	ldr r1, .L0815ACB8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L0815ACB4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ACB8: .4byte gUnknown_0815ACBC
	.global gUnknown_0815ACBC
gUnknown_0815ACBC:
.L0815ACBC: @ jump table
	.4byte .L0815ACD4
	.4byte .L0815ACE0
	.4byte .L0815ACEC
	.4byte .L0815ACF8
	.4byte .L0815AD10
	.4byte .L0815AD1C
.L0815ACD4:
	ldr r1, .L0815ACDC
	adds r0, r5, #0
	adds r0, #0x5d
	b .L0815AD22
.L0815ACDC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ACE0:
	ldr r1, .L0815ACE8
	adds r0, r5, #0
	adds r0, #0x5e
	b .L0815AD22
.L0815ACE8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ACEC:
	ldr r1, .L0815ACF4
	adds r0, r5, #0
	adds r0, #0x5f
	b .L0815AD22
.L0815ACF4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ACF8:
	ldr r0, .L0815AD0C
	adds r1, r5, #0
	adds r1, #0x60
	ldrb r1, [r1]
	adds r3, r0, #0
	adds r3, #0x83
	strb r1, [r3]
	adds r6, r0, #0
	b .L0815AD2C
	.byte 0x00, 0x00
.L0815AD0C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AD10:
	ldr r1, .L0815AD18
	adds r0, r5, #0
	adds r0, #0x61
	b .L0815AD22
.L0815AD18: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AD1C:
	ldr r1, .L0815AD88
	adds r0, r5, #0
	adds r0, #0x62
.L0815AD22:
	ldrb r0, [r0]
	adds r3, r1, #0
	adds r3, #0x83
	strb r0, [r3]
	adds r6, r1, #0
.L0815AD2C:
	adds r4, r6, #0
	adds r4, #0x83
	ldrb r0, [r4]
	subs r0, #0x24
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x15
	bhi .L0815AD76
	ldrb r0, [r4]
	bl sub_0815AD8C
	cmp r0, #0
	bne .L0815AD76
	bl sub_0815AE18
	cmp r0, #0
	bne .L0815AD76
	adds r3, r6, #0
	adds r3, #0x82
	movs r1, #0
	ldrsb r1, [r3, r1]
	adds r1, #0x20
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r2, r6, r0
	adds r1, r1, r2
	ldrb r0, [r4]
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, #0x21
	adds r0, r0, r2
	movs r1, #0xff
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
.L0815AD76:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #5
	bls .L0815ACA8
.L0815AD80:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815AD88: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815AD8C
sub_0815AD8C: @ 0x0815AD8C
.L0815AD8C:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r2, #0
	ldr r0, .L0815ADAC
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #0xff
	beq .L0815ADC2
	adds r4, r0, #0
.L0815ADA4:
	cmp r1, r3
	bne .L0815ADB0
	movs r0, #1
	b .L0815ADC4
.L0815ADAC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ADB0:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #5
	bhi .L0815ADC2
	adds r0, r2, r4
	ldrb r1, [r0]
	cmp r1, #0xff
	bne .L0815ADA4
.L0815ADC2:
	movs r0, #0
.L0815ADC4:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815ADCC
sub_0815ADCC: @ 0x0815ADCC
.L0815ADCC:
	push {lr}
	ldr r2, .L0815ADE4
	adds r0, r2, #0
	adds r0, #0x81
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0815ADEC
	b .L0815AE12
	.byte 0x00, 0x00
.L0815ADE4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ADE8:
	movs r0, #1
	b .L0815AE14
.L0815ADEC:
	subs r0, r1, #1
	lsls r1, r0, #0x18
	cmp r1, #0
	blt .L0815AE12
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r3, r2, r0
	adds r0, r2, #0
	adds r0, #0x83
	ldrb r2, [r0]
.L0815AE00:
	asrs r1, r1, #0x18
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	beq .L0815ADE8
	subs r0, r1, #1
	lsls r1, r0, #0x18
	cmp r1, #0
	bge .L0815AE00
.L0815AE12:
	movs r0, #0
.L0815AE14:
	pop {r1}
	bx r1

	thumb_func_start sub_0815AE18
sub_0815AE18: @ 0x0815AE18
.L0815AE18:
	push {lr}
	ldr r2, .L0815AE30
	adds r0, r2, #0
	adds r0, #0x82
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0815AE38
	b .L0815AE62
	.byte 0x00, 0x00
.L0815AE30: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AE34:
	movs r0, #1
	b .L0815AE64
.L0815AE38:
	subs r0, r1, #1
	lsls r1, r0, #0x18
	cmp r1, #0
	blt .L0815AE62
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r3, r2, r0
	adds r0, r2, #0
	adds r0, #0x83
	ldrb r2, [r0]
.L0815AE4C:
	asrs r1, r1, #0x18
	adds r0, r1, #0
	adds r0, #0x20
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, r2
	beq .L0815AE34
	subs r0, r1, #1
	lsls r1, r0, #0x18
	cmp r1, #0
	bge .L0815AE4C
.L0815AE62:
	movs r0, #0
.L0815AE64:
	pop {r1}
	bx r1

	thumb_func_start sub_0815AE68
sub_0815AE68: @ 0x0815AE68
.L0815AE68:
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r1
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	pop {r1}
	bx r1

	thumb_func_start sub_0815AE84
sub_0815AE84: @ 0x0815AE84
.L0815AE84:
	push {lr}
	ldr r1, .L0815AEB8
	adds r0, r1, #0
	adds r0, #0x90
	ldrh r0, [r0]
	adds r2, r1, #0
	adds r2, #0x8a
	strh r0, [r2]
	adds r0, r1, #0
	adds r0, #0x92
	ldrh r2, [r0]
	subs r0, #6
	strh r2, [r0]
	adds r0, #8
	ldrh r0, [r0]
	adds r1, #0x8e
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L0815AEBC
	cmp r0, r1
	bne .L0815AEC0
	bl sub_0815B08C
	b .L0815AED2
	.byte 0x00, 0x00
.L0815AEB8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AEBC: .4byte 0x0000FFFF
.L0815AEC0:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bne .L0815AECE
	bl sub_0815AFB0
	b .L0815AED2
.L0815AECE:
	bl sub_0815AF00
.L0815AED2:
	adds r3, r0, #0
	ldr r2, .L0815AEFC
	adds r0, r2, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x8e
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	adds r0, r3, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815AEFC: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815AF00
sub_0815AF00: @ 0x0815AF00
.L0815AF00:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r4, #0
	ldr r6, .L0815AF7C
	ldr r3, .L0815AF80
	adds r0, r3, #0
	adds r0, #0x94
	ldrh r0, [r0]
	mov r8, r0
	movs r0, #0xa0
	adds r0, r0, r3
	mov sl, r0
	movs r1, #0x92
	adds r1, r1, r3
	mov ip, r1
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r5, r5, r3
	mov sb, r5
.L0815AF2E:
	adds r0, r4, #2
	ldr r7, .L0815AF7C
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, r8
	bne .L0815AF84
	adds r0, r4, r6
	ldrb r0, [r0]
	adds r2, r0, #0
	adds r0, r4, #1
	adds r0, r0, r6
	ldrb r1, [r0]
	str r1, [sp]
	adds r0, r3, #0
	adds r0, #0x90
	ldrh r0, [r0]
	cmp r2, r0
	bne .L0815AF5A
	mov r5, ip
	ldrh r5, [r5]
	cmp r1, r5
	beq .L0815AF68
.L0815AF5A:
	mov r7, ip
	ldrh r7, [r7]
	cmp r2, r7
	bne .L0815AF84
	ldr r1, [sp]
	cmp r1, r0
	bne .L0815AF84
.L0815AF68:
	adds r0, r4, #3
	ldr r5, .L0815AF7C
	adds r0, r0, r5
	ldrb r0, [r0]
	mov r7, sb
	strh r0, [r7]
	mov r1, sl
	strh r0, [r1]
	movs r0, #1
	b .L0815AFA0
.L0815AF7C: .4byte gUnknown_087F1C53
.L0815AF80: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AF84:
	adds r0, r4, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x77
	bls .L0815AF2E
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r0, r3, r5
	movs r1, #0xff
	strh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xa0
	strh r1, [r0]
	movs r0, #0
.L0815AFA0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0815AFB0
sub_0815AFB0: @ 0x0815AFB0
.L0815AFB0:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r3, .L0815B014
	adds r0, r3, #0
	adds r0, #0x90
	ldrh r1, [r0]
	subs r1, #0x40
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0x11
	lsrs r2, r0, #0x10
	movs r6, #0
	adds r5, r3, #0
	mov sb, r5
	movs r0, #0xa2
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x94
.L0815AFDA:
	ldr r0, .L0815B018
	adds r0, r2, r0
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L0815B030
	movs r4, #0xa4
	lsls r4, r4, #2
	add r4, sb
	strh r2, [r4]
	movs r0, #0x3f
	ands r1, r0
	mov r2, r8
	strb r1, [r2]
	ldrh r0, [r7]
	bl sub_0815B9DC
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov r0, r8
	ldrb r0, [r0]
	cmp r2, r0
	beq .L0815B020
	ldrh r2, [r4]
	ldr r1, .L0815B01C
	adds r5, r4, r1
	b .L0815B054
	.byte 0x00, 0x00
.L0815B014: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B018: .4byte gUnknown_087F1B13
.L0815B01C: .4byte 0xFFFFFD70
.L0815B020:
	ldrh r2, [r4]
	ldr r0, .L0815B02C
	adds r0, r2, r0
	ldrb r1, [r0]
	strh r1, [r4]
	b .L0815B044
.L0815B02C: .4byte gUnknown_087F1BB3
.L0815B030:
	ldrh r0, [r7]
	cmp r1, r0
	bne .L0815B054
	ldr r0, .L0815B050
	adds r0, r2, r0
	ldrb r1, [r0]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
.L0815B044:
	adds r0, r5, #0
	adds r0, #0xa0
	strh r1, [r0]
	movs r0, #1
	b .L0815B07E
	.byte 0x00, 0x00
.L0815B050: .4byte gUnknown_087F1BB3
.L0815B054:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #4
	bls .L0815AFDA
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #0xff
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0xa0
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa6
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
.L0815B07E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815B08C
sub_0815B08C: @ 0x0815B08C
.L0815B08C:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r3, .L0815B0E0
	adds r0, r3, #0
	adds r0, #0x90
	ldrh r1, [r0]
	subs r1, #0x40
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0x11
	lsrs r5, r0, #0x10
	movs r2, #5
	ldr r0, .L0815B0E4
	mov r8, r0
	adds r0, r3, #0
	adds r0, #0x92
	ldrh r4, [r0]
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r1, r1, r3
	mov ip, r1
	ldr r6, .L0815B0E8
	movs r7, #0xa0
	adds r7, r7, r3
	mov sb, r7
.L0815B0C2:
	adds r1, r5, r2
	mov r7, r8
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, r4
	bne .L0815B0EC
	adds r0, r1, r6
	ldrb r0, [r0]
	mov r1, ip
	strh r0, [r1]
	mov r7, sb
	strh r0, [r7]
	movs r0, #1
	b .L0815B110
	.byte 0x00, 0x00
.L0815B0E0: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B0E4: .4byte gUnknown_087F1B13
.L0815B0E8: .4byte gUnknown_087F1BB3
.L0815B0EC:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #9
	bls .L0815B0C2
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r1, #0xff
	strh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xa0
	strh r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa6
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
.L0815B110:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0815B11C
sub_0815B11C: @ 0x0815B11C
.L0815B11C:
	push {r4, r5, r6, lr}
	bl Random_Byte
	adds r4, r0, #0
	movs r0, #0xff
	ands r4, r0
	movs r0, #0xd8
	bl Flag_Test
	cmp r0, #0
	bne .L0815B140
	cmp r4, #0
	beq .L0815B140
	ldr r0, .L0815B13C
	b .L0815B23C
	.byte 0x00, 0x00
.L0815B13C: .4byte 0x0000FFFF
.L0815B140:
	ldr r3, .L0815B170
	adds r2, r3, #0
	adds r2, #0xa4
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, .L0815B174
	ldrb r2, [r0, #0xd]
	adds r0, r3, #0
	adds r0, #0x8e
	ldrh r1, [r0]
	ldr r0, .L0815B178
	cmp r1, r0
	bne .L0815B194
	cmp r2, #0x3a
	bhi .L0815B17C
	adds r1, r2, #0
	adds r1, #0x10
	adds r0, r3, #0
	adds r0, #0x9c
	strb r1, [r0]
	b .L0815B184
	.byte 0x00, 0x00
.L0815B170: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B174: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815B178: .4byte 0x0000FFFF
.L0815B17C:
	adds r1, r3, #0
	adds r1, #0x9c
	movs r0, #0x4b
	strb r0, [r1]
.L0815B184:
	adds r0, r3, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #0x19
	bls .L0815B1C2
	adds r1, r0, #0
	subs r1, #0x19
	b .L0815B1BA
.L0815B194:
	cmp r2, #0x30
	bhi .L0815B1A4
	adds r1, r2, #0
	adds r1, #0x1a
	adds r0, r3, #0
	adds r0, #0x9c
	strb r1, [r0]
	b .L0815B1AC
.L0815B1A4:
	adds r1, r3, #0
	adds r1, #0x9c
	movs r0, #0x4b
	strb r0, [r1]
.L0815B1AC:
	adds r0, r3, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #0x28
	bls .L0815B1C2
	adds r1, r0, #0
	subs r1, #0x28
.L0815B1BA:
	adds r0, r3, #0
	adds r0, #0x9d
	strb r1, [r0]
	b .L0815B1CA
.L0815B1C2:
	adds r1, r3, #0
	adds r1, #0x9d
	movs r0, #0
	strb r0, [r1]
.L0815B1CA:
	movs r4, #0
.L0815B1CC:
	bl sub_08159144
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xff
	beq .L0815B20E
	adds r6, r2, #0
	adds r0, r6, #0
	bl sub_0815BA28
	cmp r0, #0
	beq .L0815B20E
	adds r0, r6, #0
	bl sub_0815B9A0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, .L0815B244
	adds r0, r1, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r2, r0
	bhs .L0815B20E
	adds r0, r1, #0
	adds r0, #0x9d
	ldrb r0, [r0]
	cmp r2, r0
	blo .L0815B20E
	adds r0, r6, #0
	bl sub_080C3560
	cmp r0, #0
	beq .L0815B218
.L0815B20E:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x1f
	bls .L0815B1CC
.L0815B218:
	cmp r4, #0x20
	bne .L0815B228
	movs r6, #0xfb
	movs r0, #0xfb
	bl sub_080C3560
	cmp r0, #0
	bne .L0815B1CA
.L0815B228:
	ldr r4, .L0815B244
	adds r5, r4, #0
	adds r5, #0xa0
	strh r6, [r5]
	ldrh r0, [r5]
	bl sub_0815B9DC
	adds r4, #0xa2
	strb r0, [r4]
	ldrh r0, [r5]
.L0815B23C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815B244: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815B248
sub_0815B248: @ 0x0815B248
.L0815B248:
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0815B24C
sub_0815B24C: @ 0x0815B24C
	push {lr}
	ldr r0, .L0815B25C
	adds r0, #0xa5
	ldrb r0, [r0]
	bl sub_080C3560
	pop {r1}
	bx r1
.L0815B25C: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815B260
sub_0815B260: @ 0x0815B260
.L0815B260:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r5, .L0815B2E0
	adds r6, r5, #0
	adds r6, #0x90
	ldrh r1, [r6]
	ldr r0, .L0815B2E4
	strh r1, [r0]
	movs r2, #0x92
	adds r2, r2, r5
	mov r8, r2
	ldrh r2, [r2]
	ldr r3, .L0815B2E8
	strh r2, [r3]
	movs r0, #0x94
	adds r0, r0, r5
	mov sb, r0
	ldrh r0, [r0]
	ldr r3, .L0815B2EC
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsls r0, r2, #0x10
	cmp r1, r0
	bls .L0815B29E
	ldrh r0, [r6]
	strh r2, [r6]
	mov r1, r8
	strh r0, [r1]
.L0815B29E:
	mov r2, sb
	ldrh r1, [r2]
	ldrh r0, [r6]
	cmp r0, r1
	bls .L0815B2AC
	strh r1, [r6]
	strh r0, [r2]
.L0815B2AC:
	mov r3, sb
	ldrh r1, [r3]
	mov r2, r8
	ldrh r0, [r2]
	cmp r0, r1
	bls .L0815B2BC
	strh r1, [r2]
	strh r0, [r3]
.L0815B2BC:
	adds r7, r5, #0
	adds r7, #0xa0
	ldrh r1, [r7]
	ldr r0, .L0815B2F0
	cmp r1, r0
	bne .L0815B2CA
	b .L0815B3C0
.L0815B2CA:
	bl sub_0815A6F0
	bl sub_0815B248
	ldrh r0, [r7]
	bl sub_080C3560
	cmp r0, #0
	beq .L0815B2F4
	movs r0, #4
	b .L0815B3D8
.L0815B2E0: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B2E4: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B2E8: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B2EC: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6
.L0815B2F0: .4byte 0x0000FFFF
.L0815B2F4:
	ldrh r4, [r7]
	adds r0, r4, #0
	bl Demon_GetRecord
	movs r3, #0xff
	mov sl, r3
	ldrb r2, [r0, #1]
	ldr r0, .L0815B334
	ldrb r4, [r0, #0xd]
	adds r0, r5, #0
	adds r0, #0xa4
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L0815B316
	adds r4, #9
.L0815B316:
	cmp r4, r2
	bhs .L0815B344
	ldr r1, .L0815B338
	ldrh r0, [r1]
	strh r0, [r6]
	ldr r2, .L0815B33C
	ldrh r0, [r2]
	mov r3, r8
	strh r0, [r3]
	ldr r1, .L0815B340
	ldrh r0, [r1]
	mov r2, sb
	strh r0, [r2]
	movs r0, #3
	b .L0815B3D8
.L0815B334: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815B338: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B33C: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B340: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6
.L0815B344:
	ldrh r0, [r7]
	bl sub_0815B958
	mov r4, sl
	ands r4, r0
	ldr r0, .L0815B388
	adds r0, #0x58
	ldrh r0, [r0]
	lsrs r2, r0, #8
	adds r0, r2, #0
	bl sub_0815B970
	mov r2, sl
	ands r2, r0
	cmp r4, #1
	beq .L0815B398
	cmp r2, #1
	beq .L0815B398
	cmp r2, r4
	beq .L0815B398
	ldr r3, .L0815B38C
	ldrh r0, [r3]
	strh r0, [r6]
	ldr r1, .L0815B390
	ldrh r0, [r1]
	mov r2, r8
	strh r0, [r2]
	ldr r3, .L0815B394
	ldrh r0, [r3]
	mov r1, sb
	strh r0, [r1]
	movs r0, #2
	b .L0815B3D8
	.byte 0x00, 0x00
.L0815B388: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815B38C: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B390: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B394: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6
.L0815B398:
	ldr r2, .L0815B3BC
	adds r0, r2, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x8e
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	movs r0, #1
	b .L0815B3D8
.L0815B3BC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B3C0:
	ldr r2, .L0815B3E8
	ldrh r0, [r2]
	strh r0, [r6]
	ldr r3, .L0815B3EC
	ldrh r0, [r3]
	mov r1, r8
	strh r0, [r1]
	ldr r2, .L0815B3F0
	ldrh r0, [r2]
	mov r3, sb
	strh r0, [r3]
	movs r0, #0
.L0815B3D8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815B3E8: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B3EC: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B3F0: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6

	thumb_func_start sub_0815B3F4
sub_0815B3F4: @ 0x0815B3F4
.L0815B3F4:
	push {r4, r5, lr}
	ldr r4, .L0815B464
	adds r1, r4, #0
	adds r1, #0x90
	ldrh r0, [r1]
	ldr r5, .L0815B468
	cmp r0, r5
	beq .L0815B40A
	movs r1, #2
	bl sub_0815BB18
.L0815B40A:
	adds r1, r4, #0
	adds r1, #0x92
	ldrh r0, [r1]
	cmp r0, r5
	beq .L0815B41A
	movs r1, #2
	bl sub_0815BB18
.L0815B41A:
	adds r1, r4, #0
	adds r1, #0x94
	ldrh r0, [r1]
	cmp r0, r5
	beq .L0815B42A
	movs r1, #2
	bl sub_0815BB18
.L0815B42A:
	adds r4, #0xa0
	ldrh r0, [r4]
	movs r1, #4
	bl sub_0815BAC8
	movs r0, #0xe0
	bl Flag_Test
	cmp r0, #0
	bne .L0815B4AC
	ldrh r0, [r4]
	bl sub_0815B958
	movs r2, #3
	ands r2, r0
	cmp r2, #0
	bne .L0815B474
	ldr r0, .L0815B46C
	adds r3, r0, #0
	adds r3, #0x58
	ldrh r1, [r3]
	adds r4, r0, #0
	cmp r1, #0x19
	bls .L0815B470
	adds r0, r1, #0
	subs r0, #0x1a
	strh r0, [r3]
	b .L0815B49A
	.byte 0x00, 0x00
.L0815B464: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B468: .4byte 0x0000FFFF
.L0815B46C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815B470:
	strh r2, [r3]
	b .L0815B49A
.L0815B474:
	ldr r4, .L0815B48C
	cmp r2, #2
	bne .L0815B49A
	adds r2, r4, #0
	adds r2, #0x58
	ldrh r1, [r2]
	ldr r0, .L0815B490
	cmp r1, r0
	bhi .L0815B494
	adds r0, r1, #0
	adds r0, #0x1a
	b .L0815B498
.L0815B48C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815B490: .4byte 0x0000FFE6
.L0815B494:
	adds r0, r5, #0
	orrs r0, r1
.L0815B498:
	strh r0, [r2]
.L0815B49A:
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r1, [r0]
	adds r0, #0x80
	strh r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
.L0815B4AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0815B4B4
sub_0815B4B4: @ 0x0815B4B4
.L0815B4B4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r5, .L0815B5B4
	adds r4, r5, #0
	adds r4, #0x90
	ldrh r1, [r4]
	ldr r0, .L0815B5B8
	strh r1, [r0]
	movs r2, #0x92
	adds r2, r2, r5
	mov sb, r2
	ldrh r2, [r2]
	ldr r3, .L0815B5BC
	strh r2, [r3]
	adds r6, r5, #0
	adds r6, #0x94
	ldrh r0, [r6]
	ldr r3, .L0815B5C0
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsls r0, r2, #0x10
	cmp r1, r0
	bls .L0815B4F2
	ldrh r0, [r4]
	strh r2, [r4]
	mov r1, sb
	strh r0, [r1]
.L0815B4F2:
	ldrh r1, [r6]
	ldrh r0, [r4]
	cmp r0, r1
	bls .L0815B4FE
	strh r1, [r4]
	strh r0, [r6]
.L0815B4FE:
	ldrh r1, [r6]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, r1
	bls .L0815B50C
	strh r1, [r2]
	strh r0, [r6]
.L0815B50C:
	ldrh r0, [r4]
	adds r2, r5, #0
	adds r2, #0x96
	ldr r1, .L0815B5C4
	bl sub_0815B9B8
	mov r3, sb
	ldrh r0, [r3]
	movs r1, #0x9a
	adds r1, r1, r5
	mov sl, r1
	adds r2, r5, #0
	adds r2, #0x97
	bl sub_0815B9B8
	ldrh r1, [r6]
	ldr r0, .L0815B5C8
	cmp r1, r0
	bne .L0815B534
	b .L0815B772
.L0815B534:
	adds r0, r1, #0
	adds r4, r5, #0
	adds r4, #0x9b
	adds r2, r5, #0
	adds r2, #0x98
	adds r1, r4, #0
	bl sub_0815B9B8
	ldr r2, .L0815B5C4
	ldrb r0, [r2]
	cmp r0, #0xb
	bne .L0815B55C
	mov r3, sl
	ldrb r0, [r3]
	cmp r0, #0xb
	beq .L0815B566
	ldrb r0, [r4]
	adds r4, r5, #0
	cmp r0, #0xb
	bne .L0815B59C
.L0815B55C:
	mov r1, sl
	ldrb r0, [r1]
	adds r4, r5, #0
	cmp r0, #0xb
	bne .L0815B57E
.L0815B566:
	ldr r1, .L0815B5B4
	adds r0, r1, #0
	adds r0, #0x9b
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #0xb
	beq .L0815B588
	adds r0, r4, #0
	adds r0, #0x99
	ldrb r0, [r0]
	cmp r0, #0xb
	bne .L0815B59C
.L0815B57E:
	adds r0, r4, #0
	adds r0, #0x9b
	ldrb r0, [r0]
	cmp r0, #0xb
	bne .L0815B5CC
.L0815B588:
	adds r0, r4, #0
	adds r0, #0x99
	ldrb r0, [r0]
	cmp r0, #0xb
	beq .L0815B5CC
	adds r0, r4, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	cmp r0, #0xb
	beq .L0815B5CC
.L0815B59C:
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r4, #0
	b .L0815B7DC
.L0815B5B4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B5B8: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B5BC: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B5C0: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6
.L0815B5C4: .4byte 0x0203B901 @ EWRAM+0x3B901
.L0815B5C8: .4byte 0x0000FFFF
.L0815B5CC:
	adds r0, r4, #0
	adds r0, #0x96
	ldrb r0, [r0]
	cmp r0, #0x1a
	bhi .L0815B5EA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #0x1a
	bhi .L0815B5EA
	adds r0, r4, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0x1a
	bls .L0815B602
.L0815B5EA:
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r4, #0
	b .L0815B804
.L0815B602:
	adds r0, r4, #0
	adds r0, #0x90
	ldrh r0, [r0]
	bl sub_0815B9A0
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r4, #0
	adds r0, #0x92
	ldrh r0, [r0]
	bl sub_0815B9A0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	bl sub_0815B9A0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r6, r5
	blo .L0815B65C
	cmp r6, r0
	blo .L0815B65C
	adds r1, r4, #0
	adds r1, #0x99
	ldrb r1, [r1]
	str r1, [sp]
	cmp r5, r0
	blo .L0815B64E
	adds r0, r4, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x9b
	b .L0815B6C4
.L0815B64E:
	adds r0, r4, #0
	adds r0, #0x9b
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x9a
	b .L0815B6C4
.L0815B65C:
	cmp r5, r6
	blo .L0815B68E
	cmp r5, r0
	blo .L0815B68E
	ldr r1, .L0815B684
	adds r2, r1, #0
	adds r2, #0x9a
	ldrb r2, [r2]
	str r2, [sp]
	adds r4, r1, #0
	cmp r6, r0
	blo .L0815B688
	adds r0, r4, #0
	adds r0, #0x99
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x9b
	b .L0815B6C4
	.byte 0x00, 0x00
.L0815B684: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B688:
	adds r0, r4, #0
	adds r0, #0x9b
	b .L0815B6BC
.L0815B68E:
	ldr r4, .L0815B6B4
	cmp r0, r6
	blo .L0815B6C6
	cmp r0, r5
	blo .L0815B6C6
	adds r0, r4, #0
	adds r0, #0x9b
	ldrb r0, [r0]
	str r0, [sp]
	cmp r6, r5
	blo .L0815B6B8
	adds r0, r4, #0
	adds r0, #0x99
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x9a
	b .L0815B6C4
	.byte 0x00, 0x00
.L0815B6B4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B6B8:
	adds r0, r4, #0
	adds r0, #0x9a
.L0815B6BC:
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x99
.L0815B6C4:
	ldrb r7, [r0]
.L0815B6C6:
	ldr r2, [sp]
	cmp r2, #3
	bne .L0815B6E0
	mov r3, r8
	cmp r3, #3
	bne .L0815B6D6
	cmp r7, #2
	beq .L0815B742
.L0815B6D6:
	mov r0, r8
	cmp r0, #2
	bne .L0815B6E0
	cmp r7, #3
	beq .L0815B742
.L0815B6E0:
	ldr r1, [sp]
	cmp r1, #7
	bne .L0815B70E
	mov r2, r8
	cmp r2, #7
	bne .L0815B6F0
	cmp r7, #5
	beq .L0815B742
.L0815B6F0:
	mov r3, r8
	cmp r3, #5
	bne .L0815B6FA
	cmp r7, #7
	beq .L0815B742
.L0815B6FA:
	mov r0, r8
	cmp r0, #1
	bne .L0815B704
	cmp r7, #5
	beq .L0815B742
.L0815B704:
	mov r1, r8
	cmp r1, #5
	bne .L0815B70E
	cmp r7, #1
	beq .L0815B742
.L0815B70E:
	ldr r2, [sp]
	cmp r2, #6
	bne .L0815B728
	mov r3, r8
	cmp r3, #1
	bne .L0815B71E
	cmp r7, #7
	beq .L0815B742
.L0815B71E:
	mov r0, r8
	cmp r0, #7
	bne .L0815B728
	cmp r7, #1
	beq .L0815B742
.L0815B728:
	ldr r1, [sp]
	cmp r1, #5
	bne .L0815B75A
	mov r2, r8
	cmp r2, #5
	bne .L0815B738
	cmp r7, #3
	beq .L0815B742
.L0815B738:
	mov r3, r8
	cmp r3, #3
	bne .L0815B75A
	cmp r7, #5
	bne .L0815B75A
.L0815B742:
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r4, #0
	b .L0815B7DC
.L0815B75A:
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r4, #0
	b .L0815B804
.L0815B772:
	ldrh r0, [r4]
	cmp r0, #0xfb
	beq .L0815B780
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0xfb
	bne .L0815B7A4
.L0815B780:
	ldr r2, .L0815B798
	ldrh r0, [r2]
	strh r0, [r4]
	ldr r3, .L0815B79C
	ldrh r0, [r3]
	mov r1, sb
	strh r0, [r1]
	ldr r2, .L0815B7A0
	ldrh r0, [r2]
	strh r0, [r6]
	b .L0815B80C
	.byte 0x00, 0x00
.L0815B798: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B79C: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B7A0: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6
.L0815B7A4:
	ldr r3, .L0815B7B8
	ldrb r0, [r3]
	cmp r0, #0xb
	bne .L0815B7BC
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0xb
	bne .L0815B7C4
	b .L0815B7EC
	.byte 0x00, 0x00
.L0815B7B8: .4byte 0x0203B901 @ EWRAM+0x3B901
.L0815B7BC:
	mov r2, sl
	ldrb r0, [r2]
	cmp r0, #0xb
	bne .L0815B7EC
.L0815B7C4:
	ldr r2, .L0815B7E8
	adds r0, r2, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r2, #0
.L0815B7DC:
	adds r0, #0x8e
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	movs r0, #1
	b .L0815B80E
.L0815B7E8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B7EC:
	ldr r2, .L0815B820
	adds r0, r2, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r2, #0
.L0815B804:
	adds r0, #0x8e
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
.L0815B80C:
	movs r0, #0
.L0815B80E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815B820: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815B824
sub_0815B824: @ 0x0815B824
.L0815B824:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Demon_GetRecord
	adds r0, #0x21
	ldrb r2, [r0]
	ldr r1, .L0815B858
	movs r0, #0xf0
	ands r0, r2
	lsrs r0, r0, #2
	ldr r3, .L0815B85C
	adds r1, r1, r3
	strh r0, [r1]
	movs r1, #0xf
	ands r2, r1
	adds r0, r0, r2
	ldr r1, .L0815B860
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815B852
	movs r0, #0xf
.L0815B852:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815B858: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B85C: .4byte 0x00000292
.L0815B860: .4byte gUnknown_087F1CCC

	thumb_func_start sub_0815B864
sub_0815B864: @ 0x0815B864
.L0815B864:
	push {lr}
	bl sub_080ED550
	cmp r0, #0x6f
	bhi .L0815B872
	movs r0, #0
	b .L0815B87C
.L0815B872:
	cmp r0, #0x8f
	bls .L0815B87A
	movs r0, #2
	b .L0815B87C
.L0815B87A:
	movs r0, #1
.L0815B87C:
	pop {r1}
	bx r1

	thumb_func_start sub_0815B880
sub_0815B880: @ 0x0815B880
.L0815B880:
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0815B884
sub_0815B884: @ 0x0815B884
.L0815B884:
	push {r4, r5, r6, r7, lr}
	adds r7, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	bl sub_08154968
	ldr r5, .L0815B8B4
	adds r1, r5, #0
	adds r1, #0x90
	strh r0, [r1]
	ldr r0, .L0815B8B8
	cmp r4, r0
	beq .L0815B8BC
	adds r0, r4, #0
	bl sub_08154968
	adds r1, r5, #0
	adds r1, #0x92
	strh r0, [r1]
	b .L0815B8C8
.L0815B8B4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B8B8: .4byte 0x0000FFFF
.L0815B8BC:
	adds r2, r5, #0
	adds r2, #0x92
	ldrh r1, [r2]
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
.L0815B8C8:
	ldr r4, .L0815B8F4
	adds r0, r4, #0
	adds r0, #0x94
	strh r6, [r0]
	bl sub_0815AE84
	adds r4, #0xa0
	ldrh r0, [r4]
	cmp r0, #0xff
	beq .L0815B8E0
	bl sub_08154980
.L0815B8E0:
	strh r0, [r7]
	ldr r0, .L0815B8F4
	adds r0, #0xa0
	ldrh r1, [r0]
	ldr r0, [sp, #0x14]
	strh r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815B8F4: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815B8F8
sub_0815B8F8: @ 0x0815B8F8
.L0815B8F8:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	movs r2, #0
	ldr r0, .L0815B928
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0xff
	beq .L0815B942
.L0815B90E:
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r4, r0
	beq .L0815B92C
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815B90E
	b .L0815B942
	.byte 0x00, 0x00
.L0815B928: .4byte gUnknown_087F1D01
.L0815B92C:
	adds r0, r2, #1
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq .L0815B93E
	bl Flag_Test
	cmp r0, #0
	bne .L0815B950
.L0815B93E:
	movs r0, #0
	b .L0815B952
.L0815B942:
	cmp r5, #0
	bne .L0815B950
	adds r0, r4, #0
	bl sub_0815BA7C
	cmp r0, #0
	beq .L0815B93E
.L0815B950:
	movs r0, #1
.L0815B952:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_0815B958
sub_0815B958: @ 0x0815B958
.L0815B958:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Demon_GetRecord
	ldrb r0, [r0, #0xc]
	bl sub_0815B970
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1

	thumb_func_start sub_0815B970
sub_0815B970: @ 0x0815B970
.L0815B970:
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r1, r0
	lsrs r0, r1, #0x10
	adds r1, r0, #0
	cmp r0, #0x6f
	bhi .L0815B986
	lsls r0, r0, #8
	b .L0815B99A
.L0815B986:
	cmp r0, #0x8f
	bls .L0815B992
	lsls r0, r0, #8
	movs r1, #2
	orrs r0, r1
	b .L0815B99A
.L0815B992:
	lsls r0, r1, #8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L0815B99A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815B9A0
sub_0815B9A0: @ 0x0815B9A0
.L0815B9A0:
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r1
	lsrs r0, r0, #0x10
	bl Demon_GetRecord
	ldrb r0, [r0, #1]
	pop {r1}
	bx r1

	thumb_func_start sub_0815B9B8
sub_0815B9B8: @ 0x0815B9B8
.L0815B9B8:
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_0815B9DC
	strb r0, [r4]
	ldr r1, .L0815B9D8
	ldrb r0, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
.L0815B9D8: .4byte gUnknown_087F153D

	thumb_func_start sub_0815B9DC
sub_0815B9DC: @ 0x0815B9DC
.L0815B9DC:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq .L0815B9FC
	ldr r0, .L0815B9F8
	movs r1, #0xff
	ands r1, r2
	adds r1, r1, r0
	ldrb r0, [r1]
	b .L0815BA20
.L0815B9F8: .4byte gUnknown_087F1569
.L0815B9FC:
	cmp r2, #0xff
	bne .L0815BA04
	movs r0, #0xff
	b .L0815BA20
.L0815BA04:
	movs r1, #0
	ldr r0, .L0815BA24
	ldrb r3, [r0]
	cmp r2, r3
	blo .L0815BA1E
	adds r3, r0, #0
.L0815BA10:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r2, r0
	bhs .L0815BA10
.L0815BA1E:
	adds r0, r1, #0
.L0815BA20:
	pop {r1}
	bx r1
.L0815BA24: .4byte gUnknown_087F1514

	thumb_func_start sub_0815BA28
sub_0815BA28: @ 0x0815BA28
.L0815BA28:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r2, #0
	cmp r4, #0xfe
	bhi .L0815BA6E
	ldr r0, .L0815BA58
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0xff
	beq .L0815BA72
.L0815BA3E:
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r4, r0
	beq .L0815BA5C
	adds r0, r2, #2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815BA3E
	b .L0815BA72
	.byte 0x00, 0x00
.L0815BA58: .4byte gUnknown_087F1D22
.L0815BA5C:
	adds r0, r2, #1
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq .L0815BA6E
	bl Flag_Test
	cmp r0, #0
	bne .L0815BA72
.L0815BA6E:
	movs r0, #0
	b .L0815BA74
.L0815BA72:
	movs r0, #1
.L0815BA74:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815BA7C
sub_0815BA7C: @ 0x0815BA7C
.L0815BA7C:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r2, #0
	ldr r0, .L0815BAA4
	ldrh r1, [r0]
	ldr r3, .L0815BAA8
	adds r4, r0, #0
	cmp r1, r3
	beq .L0815BABC
	adds r6, r4, #0
	adds r1, r3, #0
.L0815BA94:
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, r5
	bne .L0815BAAC
	movs r0, #0
	b .L0815BABE
	.byte 0x00, 0x00
.L0815BAA4: .4byte gUnknown_087F1D72
.L0815BAA8: .4byte 0x0000FFFF
.L0815BAAC:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r2, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r1
	bne .L0815BA94
.L0815BABC:
	movs r0, #1
.L0815BABE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_0815BAC4
sub_0815BAC4: @ 0x0815BAC4
.L0815BAC4:
	movs r0, #1
	bx lr

	thumb_func_start sub_0815BAC8
sub_0815BAC8: @ 0x0815BAC8
.L0815BAC8:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	bl sub_0815BB70
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L0815BB04
	cmp r1, r0
	beq .L0815BB10
	ldr r0, .L0815BB08
	ldr r2, .L0815BB0C
	adds r0, r0, r2
	adds r2, r1, r0
	ldrb r1, [r2]
	adds r0, r1, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L0815BAFC
	movs r1, #0xff
.L0815BAFC:
	strb r1, [r2]
	movs r0, #1
	b .L0815BB12
	.byte 0x00, 0x00
.L0815BB04: .4byte 0x0000FFFF
.L0815BB08: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815BB0C: .4byte 0x00001074
.L0815BB10:
	movs r0, #0
.L0815BB12:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_0815BB18
sub_0815BB18: @ 0x0815BB18
.L0815BB18:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	bl sub_0815BB70
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, .L0815BB48
	cmp r3, r0
	beq .L0815BB68
	ldr r1, .L0815BB4C
	ldr r2, .L0815BB50
	adds r0, r1, r2
	adds r0, r3, r0
	ldrb r2, [r0]
	cmp r2, r4
	bls .L0815BB54
	subs r0, r2, r4
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	b .L0815BB56
	.byte 0x00, 0x00
.L0815BB48: .4byte 0x0000FFFF
.L0815BB4C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815BB50: .4byte 0x00001074
.L0815BB54:
	movs r2, #0
.L0815BB56:
	ldr r4, .L0815BB64
	adds r0, r1, r4
	adds r0, r3, r0
	strb r2, [r0]
	movs r0, #1
	b .L0815BB6A
	.byte 0x00, 0x00
.L0815BB64: .4byte 0x00001074
.L0815BB68:
	movs r0, #0
.L0815BB6A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_0815BB70
sub_0815BB70: @ 0x0815BB70
.L0815BB70:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x53
	bls .L0815BB86
	cmp r0, #0xb1
	bhi .L0815BB86
	subs r0, #0x54
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L0815BB88
.L0815BB86:
	ldr r0, .L0815BB8C
.L0815BB88:
	pop {r1}
	bx r1
.L0815BB8C: .4byte 0x0000FFFF
	.global gUnknown_0815BB90
gUnknown_0815BB90: @ 0x0815BB90
	.incbin "baserom.gba", 0x15BB90, 0x2C0
	.global gUnknown_0815BE50
gUnknown_0815BE50: @ 0x0815BE50
	.byte 0x59, 0x01, 0x35, 0x01, 0xCD, 0x00, 0x5C, 0x0C, 0x1B, 0x10, 0x4A, 0x01, 0x44, 0x01, 0x67, 0x01
	.byte 0x33, 0x01, 0x5E, 0x01, 0x08, 0x00, 0x01, 0x03
	.global gUnknown_0815BE68
gUnknown_0815BE68: @ 0x0815BE68
	.byte 0xCE, 0x00, 0x5C, 0x0C, 0x1B, 0x10, 0x4A, 0x01, 0x44, 0x01, 0x1F, 0x01, 0x3F, 0x01, 0x33, 0x01
	.byte 0x5E, 0x01, 0x08, 0x00, 0x01, 0x03
	.global gUnknown_0815BE7E
gUnknown_0815BE7E: @ 0x0815BE7E
	.byte 0xCF, 0x00, 0x5C, 0x0C, 0x1B, 0x10, 0x4A, 0x01, 0x3B, 0x01, 0x67, 0x01, 0x33, 0x01, 0x5E, 0x01
	.byte 0x08, 0x00, 0x01, 0x03
	.global gUnknown_0815BE92
gUnknown_0815BE92: @ 0x0815BE92
	.byte 0xCD, 0x00, 0xBC, 0x0F, 0x1B, 0x10, 0x4A, 0x01, 0x44, 0x01, 0x67, 0x01, 0x33, 0x01, 0x5E, 0x01
	.byte 0x08, 0x00, 0x01, 0x03
	.global gUnknown_0815BEA6
gUnknown_0815BEA6: @ 0x0815BEA6
	.byte 0x42, 0x01, 0x4A, 0x01, 0xCE, 0x00, 0xBC, 0x0F, 0x1B, 0x10, 0x4A, 0x01, 0x45, 0x01, 0x6E, 0x01
	.byte 0x33, 0x01, 0x5E, 0x01, 0x08, 0x00, 0x01, 0x03
	.global gUnknown_0815BEBE
gUnknown_0815BEBE: @ 0x0815BEBE
	.byte 0x42, 0x01, 0x4A, 0x01, 0xD4, 0x0C, 0xC3, 0x0F, 0x4A, 0x01, 0x3B, 0x01, 0x67, 0x01, 0x33, 0x01
	.byte 0x5E, 0x01, 0x08, 0x00, 0x01, 0x03
	.global gUnknown_0815BED4
gUnknown_0815BED4: @ 0x0815BED4
	.byte 0x2E, 0x01, 0x67, 0x01, 0x42, 0x01, 0x1F, 0x01, 0x1F, 0x01, 0x26, 0x01, 0x48, 0x01, 0x08, 0x00
	.byte 0x01, 0x03, 0x23, 0x09, 0x5C, 0x0C, 0x30, 0x01, 0x36, 0x01, 0x41, 0x01, 0x63, 0x01, 0x1F, 0x01
	.byte 0x26, 0x01, 0x08, 0x00, 0x01, 0x03
	.global gUnknown_0815BEFA
gUnknown_0815BEFA: @ 0x0815BEFA
	.byte 0x42, 0x01, 0x4A, 0x01, 0x3F, 0x00, 0x23, 0x09, 0x5C, 0x0C, 0x30, 0x01, 0x36, 0x01, 0x66, 0x01
	.byte 0x39, 0x01, 0x01, 0x03
	.global gUnknown_0815BF0E
gUnknown_0815BF0E: @ 0x0815BF0E
	.byte 0xBC, 0x09, 0x16, 0x0E, 0x3B, 0x01, 0x27, 0x01, 0x23, 0x00, 0x25, 0x01, 0xDF, 0x0B, 0x49, 0x01
	.byte 0xC6, 0x01, 0xB2, 0x01, 0xC5, 0x01, 0x42, 0x01, 0x4A, 0x01, 0x00, 0x03, 0x1D, 0x01, 0x3F, 0x01
	.byte 0x26, 0x01, 0x23, 0x01, 0x6E, 0x01, 0x01, 0x03
	.global gUnknown_0815BF36
gUnknown_0815BF36: @ 0x0815BF36
	.byte 0x3E, 0x0C, 0x7E, 0x0B, 0x27, 0x01, 0xCC, 0x05, 0x21, 0x01, 0x27, 0x01, 0x63, 0x01, 0x1F, 0x01
	.byte 0x26, 0x01, 0x01, 0x03
	.global gUnknown_0815BF4A
gUnknown_0815BF4A: @ 0x0815BF4A
	.byte 0xB9, 0x0D, 0x33, 0x01, 0xD4, 0x0C, 0xC3, 0x0F, 0x27, 0x01, 0x25, 0x01, 0x66, 0x01, 0x63, 0x01
	.byte 0x21, 0x01, 0x3B, 0x01, 0x45, 0x01, 0x01, 0x03
	.global gUnknown_0815BF62
gUnknown_0815BF62: @ 0x0815BF62
	.byte 0x7B, 0x01, 0x7D, 0x01, 0x9F, 0x01, 0xBA, 0x01, 0x27, 0x01, 0x1F, 0x01, 0x3E, 0x01, 0x4C, 0x01
	.byte 0x1F, 0x01, 0x33, 0x01, 0x5E, 0x01, 0x23, 0x00, 0x01, 0x03
	.global gUnknown_0815BF7C
gUnknown_0815BF7C: @ 0x0815BF7C
	.byte 0xD4, 0x0C, 0xC3, 0x0F, 0x27, 0x01, 0x1F, 0x01, 0x3E, 0x01, 0x4C, 0x01, 0x1F, 0x01, 0x33, 0x01
	.byte 0x5E, 0x01, 0x23, 0x00, 0x01, 0x03
	.global gUnknown_0815BF92
gUnknown_0815BF92: @ 0x0815BF92
	.byte 0x2E, 0x01, 0x67, 0x01, 0x27, 0x01, 0x3F, 0x00, 0x1E, 0x03, 0x3F, 0x00, 0x33, 0x01, 0x5E, 0x01
	.byte 0x00, 0x03, 0xF6, 0x09, 0x3E, 0x01, 0x41, 0x01, 0x61, 0x01, 0x2A, 0x01, 0x27, 0x01, 0x63, 0x01
	.byte 0x1F, 0x01, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x00, 0x03, 0x01, 0x03
	.global gUnknown_0815BFBE
gUnknown_0815BFBE: @ 0x0815BFBE
	.byte 0xB8, 0x0A, 0x10, 0x07, 0x34, 0x01, 0x66, 0x01, 0x49, 0x01, 0x46, 0x01, 0x01, 0x03
	.global gUnknown_0815BFCC
gUnknown_0815BFCC: @ 0x0815BFCC
	.byte 0x26, 0x01, 0x26, 0x01, 0x66, 0x01, 0x27, 0x01, 0x01, 0x03
	.global gUnknown_0815BFD6
gUnknown_0815BFD6: @ 0x0815BFD6
	.byte 0x2E, 0x01, 0x67, 0x01, 0x42, 0x01, 0x63, 0x01, 0x1F, 0x01, 0x49, 0x01, 0x3B, 0x01, 0x45, 0x01
	.byte 0x08, 0x00, 0x01, 0x03
	.global gUnknown_0815BFEA
gUnknown_0815BFEA: @ 0x0815BFEA
	.incbin "baserom.gba", 0x15BFEA, 0x42
	.global gUnknown_0815C02C
gUnknown_0815C02C: @ 0x0815C02C
	.byte 0xBB, 0x01, 0xBC, 0x01, 0xC4, 0x01, 0x1B, 0x00, 0x9A, 0x01, 0x9C, 0x01, 0xB0, 0x01, 0x27, 0x01
	.byte 0x3B, 0x0C, 0x65, 0x01, 0x45, 0x01, 0x1F, 0x01, 0x63, 0x01, 0x01, 0x03
	.global gUnknown_0815C048
gUnknown_0815C048: @ 0x0815C048
	.byte 0x25, 0x01, 0x02, 0x08, 0x27, 0x01, 0x3B, 0x0C, 0x65, 0x01, 0x45, 0x01, 0x1F, 0x01, 0x63, 0x01
	.byte 0x01, 0x03
	.global gUnknown_0815C05A
gUnknown_0815C05A: @ 0x0815C05A
	.byte 0xD4, 0x0C, 0xC3, 0x0F, 0x27, 0x01, 0x1F, 0x01, 0x3E, 0x01, 0x4C, 0x01, 0x1F, 0x01, 0x3B, 0x01
	.byte 0x63, 0x01, 0x01, 0x03
	.global gUnknown_0815C06E
gUnknown_0815C06E: @ 0x0815C06E
	.byte 0xC6, 0x01, 0xB2, 0x01, 0xC5, 0x01, 0x27, 0x01, 0x3B, 0x0C, 0x65, 0x01, 0x45, 0x01, 0x1F, 0x01
	.byte 0x63, 0x01, 0x01, 0x03
	.global gUnknown_0815C082
gUnknown_0815C082: @ 0x0815C082
	.byte 0x3E, 0x0C, 0x7E, 0x0B, 0x27, 0x01, 0xCC, 0x05, 0x21, 0x01, 0x63, 0x01, 0x01, 0x03
	.global gUnknown_0815C090
gUnknown_0815C090: @ 0x0815C090
	.byte 0xD7, 0x0C, 0x85, 0x0A, 0x46, 0x01, 0x11, 0x0A, 0x3A, 0x0E, 0x32, 0x01, 0x59, 0x01, 0x32, 0x01
	.byte 0x3A, 0x01, 0x09, 0x00, 0x09, 0x00, 0x16, 0x03, 0x01, 0x03
	.global gUnknown_0815C0AA
gUnknown_0815C0AA: @ 0x0815C0AA
	.byte 0x2E, 0x01, 0x49, 0x01, 0x96, 0x05, 0xC3, 0x0F, 0x6D, 0x01, 0x37, 0x07, 0x92, 0x08, 0x34, 0x01
	.byte 0x66, 0x01, 0x49, 0x01, 0x46, 0x01, 0x00, 0x03, 0x52, 0x00, 0xCD, 0x00, 0x3F, 0x00, 0x26, 0x01
	.byte 0x26, 0x01, 0x66, 0x01, 0x27, 0x01, 0x00, 0x03, 0x1F, 0x01, 0x1F, 0x01, 0x26, 0x01, 0x1F, 0x01
	.byte 0x08, 0x00, 0x01, 0x03
	.global gUnknown_0815C0DE
gUnknown_0815C0DE: @ 0x0815C0DE
	.byte 0x37, 0x07, 0x92, 0x08, 0x7F, 0x0B, 0xD6, 0x08, 0x09, 0x00, 0x00, 0x03, 0xBB, 0x01, 0xBC, 0x01
	.byte 0xC4, 0x01, 0x1B, 0x00, 0x9A, 0x01, 0x9C, 0x01, 0xB0, 0x01, 0x6D, 0x01, 0x3F, 0x00, 0x23, 0x03
	.byte 0xC8, 0x0F, 0x00, 0x03, 0x41, 0x0A, 0x46, 0x01, 0x06, 0x0E, 0x67, 0x01, 0x3A, 0x01, 0x16, 0x03
	.byte 0x01, 0x03
	.global gUnknown_0815C110
gUnknown_0815C110: @ 0x0815C110
	.byte 0x37, 0x07, 0x92, 0x08, 0x11, 0x0A, 0x3A, 0x0E, 0x09, 0x00, 0x09, 0x00, 0x00, 0x03, 0xBB, 0x01
	.byte 0xBC, 0x01, 0xC4, 0x01, 0x1B, 0x00, 0x9A, 0x01, 0x9C, 0x01, 0xB0, 0x01, 0x6D, 0x01, 0x11, 0x0A
	.byte 0x3E, 0x01, 0x3A, 0x01, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x16, 0x03, 0x01, 0x03, 0x00, 0x00
