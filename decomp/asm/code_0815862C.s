	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

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
