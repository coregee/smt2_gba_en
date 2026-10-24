	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start ScriptOp_32A
ScriptOp_32A: @ 0x081332BC
	ldr r3, .L081332E0
	ldr r2, .L081332E4
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L081332E8
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r3, #2]
	ldr r0, .L081332EC
	movs r1, #1
	strh r1, [r0, #2]
	ldr r0, .L081332F0
	strh r1, [r0]
	bx lr
.L081332E0: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L081332E4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081332E8: .4byte 0x03006950 @ IWRAM+0x6950
.L081332EC: .4byte 0x03006970 @ IWRAM+0x6970
.L081332F0: .4byte 0x0203DB68 @ EWRAM+0x3DB68

	thumb_func_start ScriptOp_32B
ScriptOp_32B: @ 0x081332F4
	push {r4, r5, lr}
	ldr r2, .L08133318
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L0813331C
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #0xff
	bne .L08133320
	movs r0, #1
	bl sub_080C3818
	b .L08133370
	.byte 0x00, 0x00
.L08133318: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813331C: .4byte 0x03006950 @ IWRAM+0x6950
.L08133320:
	movs r0, #0xf
	ands r1, r0
	cmp r1, #1
	bls .L08133340
	ldr r0, .L0813333C
	lsls r4, r1, #2
	adds r4, r4, r0
	ldr r0, [r4]
	movs r1, #0
	bl sub_080C48F0
	movs r0, #0
	str r0, [r4]
	b .L08133370
.L0813333C: .4byte 0x030068F0 @ IWRAM+0x68F0
.L08133340:
	ldr r0, .L0813335C
	lsls r2, r1, #2
	adds r5, r2, r0
	ldr r4, [r5]
	cmp r4, #0
	beq .L08133360
	adds r0, r4, #0
	movs r1, #0
	bl sub_080C48F0
	movs r0, #0
	str r0, [r5]
	b .L08133370
	.byte 0x00, 0x00
.L0813335C: .4byte 0x030068F0 @ IWRAM+0x68F0
.L08133360:
	ldr r0, .L08133378
	adds r5, r2, r0
	ldr r0, [r5]
	cmp r0, #0
	beq .L08133370
	bl sub_080E9044
	str r4, [r5]
.L08133370:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08133378: .4byte 0x030069C0 @ IWRAM+0x69C0

	thumb_func_start sub_0813337C
sub_0813337C: @ 0x0813337C
	ldr r1, .L08133384
	movs r0, #0x13
	strh r0, [r1]
	bx lr
.L08133384: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start sub_08133388
sub_08133388: @ 0x08133388
	movs r1, #0
	strh r1, [r0, #0x1c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_08133390
sub_08133390: @ 0x08133390
	movs r1, #1
	strh r1, [r0, #0x1c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_08133398
sub_08133398: @ 0x08133398
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813339C
sub_0813339C: @ 0x0813339C
	adds r3, r0, #0
	adds r3, #0x25
	movs r2, #0
	movs r1, #0xc8
	strb r1, [r3]
	strh r2, [r0, #0x1c]
	ldr r1, .L081333B0
	movs r0, #0x13
	strh r0, [r1]
	bx lr
.L081333B0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start sub_081333B4
sub_081333B4: @ 0x081333B4
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #0
	beq .L081333CC
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L081333DC
.L081333CC:
	ldr r0, .L081333E0
	ldrh r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L081333DC
	strh r2, [r3, #0x1c]
.L081333DC:
	pop {r0}
	bx r0
.L081333E0: .4byte 0x030031C4 @ IWRAM+0x31C4
