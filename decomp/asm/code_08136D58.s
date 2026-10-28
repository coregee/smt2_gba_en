	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start ScriptOp_38A
ScriptOp_38A: @ 0x08136D58
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_38B
ScriptOp_38B: @ 0x08136D5C
	push {r4, lr}
	ldr r3, .L08136DB8
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08136DBC
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r4, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r1, [r1]
	ldr r2, .L08136DC0
	lsls r0, r1, #1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	bl sub_080B4420
	ldr r1, .L08136DC4
	str r0, [r1]
	movs r0, #0xf0
	ands r4, r0
	cmp r4, #0
	beq .L08136DA4
	bl sub_080ECF80
.L08136DA4:
	ldr r1, .L08136DC8
	movs r0, #1
	strh r0, [r1]
	ldr r1, .L08136DCC
	movs r0, #0x34
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08136DB8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08136DBC: .4byte 0x03006950 @ IWRAM+0x6950
.L08136DC0: .4byte gUnknown_0879041E
.L08136DC4: .4byte 0x03006964 @ IWRAM+0x6964
.L08136DC8: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08136DCC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start ScriptOp_38C
ScriptOp_38C: @ 0x08136DD0
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_38D
ScriptOp_38D: @ 0x08136DD4
	push {r4, r5, r6, r7, lr}
	ldr r6, .L08136E24
	ldrh r0, [r6]
	bl sub_080C32D4
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r3, .L08136E28
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08136E2C
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r5, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r0, [r1]
	lsls r7, r0, #0x10
	orrs r7, r5
	ldrh r1, [r6]
	movs r0, #0xff
	bl sub_08131AB0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r0
	cmp r4, #0x62
	ble .L08136E1E
	ldr r0, .L08136E30
	str r7, [r0]
.L08136E1E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08136E24: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08136E28: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08136E2C: .4byte 0x03006950 @ IWRAM+0x6950
.L08136E30: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_390
ScriptOp_390: @ 0x08136E34
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_391
ScriptOp_391: @ 0x08136E38
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_392
ScriptOp_392: @ 0x08136E3C
	push {r4, r5, lr}
	ldr r0, .L08136E90
	movs r4, #0
	strh r4, [r0]
	ldr r0, .L08136E94
	strh r4, [r0]
	ldr r0, .L08136E98
	strh r4, [r0]
	ldr r0, .L08136E9C
	strh r4, [r0]
	ldr r0, .L08136EA0
	strh r4, [r0]
	ldr r5, .L08136EA4
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq .L08136E6A
	ldr r0, .L08136EA8
	ldr r0, [r0]
	movs r1, #1
	bl Window_Close
	strh r4, [r5]
.L08136E6A:
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	movs r0, #3
	movs r1, #1
	bl SaveScreen_Open
	ldr r1, .L08136EAC
	str r0, [r1]
	ldr r1, .L08136EB0
	movs r0, #0x2b
	strh r0, [r1]
	ldr r1, .L08136EB4
	movs r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08136E90: .4byte 0x0203DB58 @ EWRAM+0x3DB58
.L08136E94: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L08136E98: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L08136E9C: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L08136EA0: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L08136EA4: .4byte 0x0203DB6C @ EWRAM+0x3DB6C
.L08136EA8: .4byte 0x03006968 @ IWRAM+0x6968
.L08136EAC: .4byte 0x030068E0 @ IWRAM+0x68E0
.L08136EB0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08136EB4: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_394
ScriptOp_394: @ 0x08136EB8
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_395
ScriptOp_395: @ 0x08136EBC
	push {lr}
	ldr r3, .L08136EEC
	ldrh r0, [r3]
	adds r2, r0, #1
	strh r2, [r3]
	lsls r0, r0, #0x10
	ldr r1, .L08136EF0
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, #1
	strh r2, [r3]
	ldr r2, .L08136EF4
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl sub_080C4580
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08136EEC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08136EF0: .4byte 0x03006950 @ IWRAM+0x6950
.L08136EF4: .4byte 0x030068F0 @ IWRAM+0x68F0

	thumb_func_start ScriptOp_396
ScriptOp_396: @ 0x08136EF8
	ldr r1, .L08136F04
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08136F04: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_398
ScriptOp_398: @ 0x08136F08
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_399
ScriptOp_399: @ 0x08136F0C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_39A
ScriptOp_39A: @ 0x08136F10
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_39B
ScriptOp_39B: @ 0x08136F14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl sub_0812F198
	ldr r3, .L08137020
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08137024
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
	ldr r5, .L08137028
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
	movs r3, #0
	ldr r4, .L0813702C
	ldr r0, .L08137030
	adds r2, r0, #0
.L08136F70:
	lsls r0, r3, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	orrs r1, r2
	strh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x13
	bls .L08136F70
	ldr r0, .L08137034
	ldrb r1, [r0]
	cmp r1, #1
	beq .L08136F8E
	movs r1, #0
.L08136F8E:
	ldr r2, .L08137038
	ldr r5, .L0813703C
	movs r4, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #2
	adds r0, r1, r5
	ldrh r0, [r0]
	strh r0, [r2]
	movs r3, #0
	movs r6, #0
	ldrsh r0, [r2, r6]
	adds r0, #1
	ldr r6, .L08137040
	mov r8, r6
	ldr r6, .L08137044
	mov sb, r6
	ldr r6, .L08137048
	mov sl, r6
	cmp r3, r0
	bge .L08136FE8
	ldr r0, .L0813702C
	mov ip, r0
	adds r7, r5, #0
	adds r5, r1, #0
	adds r6, r2, #0
.L08136FC2:
	lsls r2, r3, #1
	add r2, ip
	adds r1, r4, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #1
	adds r1, r1, r5
	adds r1, r1, r7
	ldrh r0, [r1]
	strh r0, [r2]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r1, #0
	ldrsh r0, [r6, r1]
	adds r0, #1
	cmp r3, r0
	blt .L08136FC2
.L08136FE8:
	movs r0, #0
	mov r6, r8
	strh r0, [r6]
	mov r1, sb
	strh r0, [r1]
	movs r0, #4
	mov r6, sl
	strh r0, [r6]
	movs r0, #4
	bl sub_0812F2B4
	ldr r0, .L0813704C
	ldr r1, .L08137030
	bl Task_Create
	ldr r1, .L08137050
	movs r0, #1
	strh r0, [r1]
	ldr r1, .L08137054
	movs r0, #0xd
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08137020: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08137024: .4byte 0x03006950 @ IWRAM+0x6950
.L08137028: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813702C: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L08137030: .4byte 0x0000FFFF
.L08137034: .4byte 0x03006914 @ IWRAM+0x6914
.L08137038: .4byte 0x03006604 @ IWRAM+0x6604
.L0813703C: .4byte gUnknown_0878EEDC
.L08137040: .4byte 0x03006940 @ IWRAM+0x6940
.L08137044: .4byte 0x0300696C @ IWRAM+0x696C
.L08137048: .4byte 0x03006844 @ IWRAM+0x6844
.L0813704C: .4byte gUnknown_0878FC80
.L08137050: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08137054: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start ScriptOp_39C
ScriptOp_39C: @ 0x08137058
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_39F
ScriptOp_39F: @ 0x0813705C
	push {r4, r5, r6, r7, lr}
	ldr r1, .L081370A0
	ldr r3, .L081370A4
	ldrh r0, [r3]
	adds r5, r0, #1
	strh r5, [r3]
	lsls r0, r0, #0x10
	ldr r6, .L081370A8
	ldr r4, [r6]
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r2, .L081370AC
	movs r7, #0x80
	lsls r7, r7, #1
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, .L081370B0
	str r4, [r0]
	ldr r0, .L081370B4
	strh r5, [r0]
	ldr r1, .L081370B8
	movs r0, #1
	strh r0, [r1]
	ldr r0, .L081370BC
	str r0, [r6]
	movs r0, #0
	strh r0, [r3]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081370A0: .4byte 0x03006698 @ IWRAM+0x6698
.L081370A4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081370A8: .4byte 0x03006950 @ IWRAM+0x6950
.L081370AC: .4byte 0x03006914 @ IWRAM+0x6914
.L081370B0: .4byte 0x03006674 @ IWRAM+0x6674
.L081370B4: .4byte 0x030069E0 @ IWRAM+0x69E0
.L081370B8: .4byte 0x03006600 @ IWRAM+0x6600
.L081370BC: .4byte gUnknown_0803BAD6

	thumb_func_start ScriptOp_3A3
ScriptOp_3A3: @ 0x081370C0
	push {lr}
	ldr r0, .L081370D0
	ldr r0, [r0]
	rsbs r0, r0, #0
	bl sub_080C30AC
	pop {r0}
	bx r0
.L081370D0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C

	thumb_func_start ScriptOp_3A4
ScriptOp_3A4: @ 0x081370D4
	push {lr}
	ldr r1, .L081370E8
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L081370EC
	ldr r0, [r0]
	bl sub_080C30AC
	pop {r0}
	bx r0
.L081370E8: .4byte 0x0300699C @ IWRAM+0x699C
.L081370EC: .4byte 0x0203DB2C @ EWRAM+0x3DB2C

	thumb_func_start ScriptOp_3A5
ScriptOp_3A5: @ 0x081370F0
	push {r4, r5, lr}
	ldr r3, .L0813711C
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08137120
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
	movs r4, #0
	b .L0813712A
	.byte 0x00, 0x00
.L0813711C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08137120: .4byte 0x03006950 @ IWRAM+0x6950
.L08137124:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L0813712A:
	cmp r4, #0xff
	bhi .L0813713A
	adds r0, r4, #0
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08137124
.L0813713A:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r4, r0
	bne .L08137146
	ldr r0, .L0813714C
	str r5, [r0]
.L08137146:
	pop {r4, r5}
	pop {r0}
	bx r0
.L0813714C: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3A6
ScriptOp_3A6: @ 0x08137150
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3A8
ScriptOp_3A8: @ 0x08137154
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3A9
ScriptOp_3A9: @ 0x08137158
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3AB
ScriptOp_3AB: @ 0x0813715C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3AC
ScriptOp_3AC: @ 0x08137160
	push {lr}
	bl sub_080B8020
	ldr r1, .L0813717C
	str r0, [r1]
	ldr r1, .L08137180
	movs r0, #0x36
	strh r0, [r1]
	ldr r1, .L08137184
	movs r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813717C: .4byte 0x03006964 @ IWRAM+0x6964
.L08137180: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08137184: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOp_3AE
ScriptOp_3AE: @ 0x08137188
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3B1
ScriptOp_3B1: @ 0x0813718C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3B2
ScriptOp_3B2: @ 0x08137190
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3B3
ScriptOp_3B3: @ 0x08137194
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3B6
ScriptOp_3B6: @ 0x08137198
	push {r4, r5, r6, lr}
	ldr r3, .L081371EC
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L081371F0
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
	movs r6, #0
	movs r4, #0x40
.L081371C2:
	adds r0, r4, #0
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L081371D4
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L081371D4:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x4f
	bls .L081371C2
	cmp r6, #0
	beq .L081371E6
	ldr r0, .L081371F4
	str r5, [r0]
.L081371E6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L081371EC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081371F0: .4byte 0x03006950 @ IWRAM+0x6950
.L081371F4: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3B9
ScriptOp_3B9: @ 0x081371F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r3, .L0813728C
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08137290
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r4, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r7, [r1]
	lsls r7, r7, #0x10
	orrs r7, r4
	movs r5, #0
	ldr r4, .L08137294
	ldr r3, .L08137298
	ldr r0, .L0813729C
	adds r2, r0, #0
.L0813722C:
	lsls r0, r5, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	orrs r1, r2
	strh r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x13
	bls .L0813722C
	ldrh r0, [r4]
	movs r6, #0xf
	ands r6, r0
	movs r0, #0xf0
	orrs r6, r0
	movs r4, #0xf0
	movs r5, #0
	ldr r2, .L08137298
	mov r8, r2
.L08137252:
	adds r0, r4, #0
	bl Flag_Test
	cmp r0, #0
	beq .L08137272
	cmp r4, r6
	beq .L08137272
	adds r0, r5, #0
	adds r1, r0, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r0, r0, #1
	add r0, r8
	ldr r2, .L081372A0
	adds r1, r4, r2
	strh r1, [r0]
.L08137272:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xfc
	bls .L08137252
	ldr r0, .L08137298
	ldrh r1, [r0]
	ldr r0, .L0813729C
	cmp r1, r0
	bne .L081372A8
	ldr r0, .L081372A4
	str r7, [r0]
	b .L081372AE
.L0813728C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08137290: .4byte 0x03006950 @ IWRAM+0x6950
.L08137294: .4byte 0x0203DB72 @ EWRAM+0x3DB72
.L08137298: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0813729C: .4byte 0x0000FFFF
.L081372A0: .4byte 0x0000FFA0
.L081372A4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081372A8:
	ldr r1, .L081372B8
	subs r0, r5, #1
	strh r0, [r1]
.L081372AE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L081372B8: .4byte 0x03006604 @ IWRAM+0x6604

	thumb_func_start ScriptOp_3BA
ScriptOp_3BA: @ 0x081372BC
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3BB
ScriptOp_3BB: @ 0x081372C0
	ldr r1, .L081372D8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, .L081372DC
	movs r0, #1
	strh r0, [r1]
	ldr r1, .L081372E0
	movs r0, #0x3f
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L081372D8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081372DC: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L081372E0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start ScriptOp_3BD
ScriptOp_3BD: @ 0x081372E4
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3BE
ScriptOp_3BE: @ 0x081372E8
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3BF
ScriptOp_3BF: @ 0x081372EC
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3C0
ScriptOp_3C0: @ 0x081372F0
	push {lr}
	movs r0, #0x23
	bl Flag_Test
	cmp r0, #0
	beq .L08137304
	ldr r0, .L08137318
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08137312
.L08137304:
	ldr r0, .L08137318
	ldrh r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r0, #0xf0
	bl Flag_Set
.L08137312:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08137318: .4byte 0x0203DB72 @ EWRAM+0x3DB72

	thumb_func_start ScriptOp_3C2
ScriptOp_3C2: @ 0x0813731C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3C4
ScriptOp_3C4: @ 0x08137320
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3C5
ScriptOp_3C5: @ 0x08137324
	push {r4, r5, lr}
	ldr r3, .L081373A8
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L081373AC
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
	ldr r5, .L081373B0
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
	ldr r1, .L081373B4
	movs r0, #0
	strh r0, [r1]
	bl sub_0812DC24
	ldr r1, .L081373B8
	movs r0, #0x1e
	strh r0, [r1]
	ldr r1, .L081373BC
	movs r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081373A8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081373AC: .4byte 0x03006950 @ IWRAM+0x6950
.L081373B0: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L081373B4: .4byte 0x0300668C @ IWRAM+0x668C
.L081373B8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L081373BC: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start sub_081373C0
sub_081373C0: @ 0x081373C0
.L081373C0:
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #8
	ldr r0, .L081373D8
	cmp r1, r0
	bls .L081373D0
	ldr r0, .L081373DC
	orrs r1, r0
.L081373D0:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L081373D8: .4byte 0x00007FFF
.L081373DC: .4byte 0xFFFF0000

	thumb_func_start ScriptOp_3C7
ScriptOp_3C7: @ 0x081373E0
	push {r4, r5, lr}
	movs r4, #0
	ldr r2, .L08137404
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08137408
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r2, r1, #0
	cmp r1, #0
	bne .L08137410
	ldr r0, .L0813740C
	str r4, [r0]
	b .L08137472
.L08137404: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08137408: .4byte 0x03006950 @ IWRAM+0x6950
.L0813740C: .4byte 0x0203DB34 @ EWRAM+0x3DB34
.L08137410:
	ldr r0, .L08137424
	ldr r0, [r0]
	cmp r0, #0
	beq .L08137472
	cmp r1, #1
	bne .L08137428
	movs r4, #1
	rsbs r4, r4, #0
	adds r5, r4, #0
	b .L08137452
.L08137424: .4byte 0x0203DB34 @ EWRAM+0x3DB34
.L08137428:
	cmp r2, #2
	bne .L08137432
	movs r4, #1
	movs r5, #1
	b .L08137452
.L08137432:
	movs r0, #0
	bl sub_080C0794
	lsrs r0, r0, #8
	movs r5, #1
	cmp r0, #0x7f
	bls .L08137442
	subs r5, #2
.L08137442:
	movs r0, #1
	bl sub_080C0794
	lsrs r0, r0, #8
	movs r4, #1
	cmp r0, #0x7f
	bls .L08137452
	subs r4, #2
.L08137452:
	adds r0, r5, #0
	bl sub_081373C0
	adds r5, r0, #0
	adds r0, r4, #0
	bl sub_081373C0
	adds r4, r0, #0
	movs r0, #0
	adds r1, r5, #0
	bl sub_080C06EC
	movs r0, #1
	adds r1, r4, #0
	bl sub_080C06EC
.L08137472:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start ScriptOp_3C6
ScriptOp_3C6: @ 0x08137478
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r3, .L081374EC
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L081374F0
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r6, [r0]
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
	ldrh r5, [r0]
	lsls r5, r5, #0x10
	orrs r5, r4
	cmp r6, #0x65
	bne .L081374FC
	ldr r0, .L081374F4
	ldrh r0, [r0]
	bl sub_080D2268
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #6
	beq .L08137508
	ldr r0, .L081374F8
	movs r2, #0
	ldrsh r0, [r0, r2]
	bl sub_080C00DC
	adds r1, r0, #0
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0xff
	beq .L08137508
	adds r0, r1, #0
	movs r1, #6
	mov r2, sp
	bl sub_080BF468
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L08137508
	b .L08137504
	.byte 0x00, 0x00
.L081374EC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081374F0: .4byte 0x03006950 @ IWRAM+0x6950
.L081374F4: .4byte 0x030069A8 @ IWRAM+0x69A8
.L081374F8: .4byte 0x03006898 @ IWRAM+0x6898
.L081374FC:
	ldr r0, .L08137510
	ldrh r0, [r0, #2]
	cmp r0, r6
	bne .L08137508
.L08137504:
	ldr r0, .L08137514
	str r5, [r0]
.L08137508:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08137510: .4byte 0x03004550 @ IWRAM+0x4550
.L08137514: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start sub_08137518
sub_08137518: @ 0x08137518
.L08137518:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	movs r2, #0x90
	lsls r2, r2, #0x11
	adds r0, r0, r2
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt .L08137546
	movs r4, #0
	cmp r4, r0
	bge .L08137564
	adds r5, r0, #0
.L08137534:
	adds r0, r6, #0
	bl sub_080C3328
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	blt .L08137534
	b .L08137564
.L08137546:
	rsbs r0, r0, #0
	movs r4, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	bge .L08137564
	adds r5, r0, #0
.L08137554:
	adds r0, r6, #0
	bl sub_080C33AC
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	blt .L08137554
.L08137564:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0813756C
sub_0813756C: @ 0x0813756C
.L0813756C:
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0x90
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl sub_080C32D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start ScriptOp_3CA
ScriptOp_3CA: @ 0x08137584
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3CB
ScriptOp_3CB: @ 0x08137588
	push {r4, r5, lr}
	ldr r3, .L081375C4
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L081375C8
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
	bl sub_080C1D9C
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x80
	bne .L081375BE
	ldr r0, .L081375CC
	str r5, [r0]
.L081375BE:
	pop {r4, r5}
	pop {r0}
	bx r0
.L081375C4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081375C8: .4byte 0x03006950 @ IWRAM+0x6950
.L081375CC: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3CC
ScriptOp_3CC: @ 0x081375D0
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3CD
ScriptOp_3CD: @ 0x081375D4
	push {r4, r5, r6, r7, lr}
	ldr r2, .L08137638
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L0813763C
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r7, [r0]
	ldr r0, .L08137640
	ldrb r0, [r0]
	cmp r0, #0x3f
	bhi .L08137654
	ldr r0, .L08137644
	ldrh r0, [r0]
	movs r1, #0xb
	bl Demon_GetField
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	bl sub_0815B958
	movs r4, #0xff
	adds r5, r4, #0
	ands r5, r0
	adds r6, r5, #0
	movs r0, #0
	bl sub_080C0794
	movs r2, #0xff
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	lsrs r1, r0, #8
	adds r0, r1, #0
	bl sub_0815B970
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #1
	beq .L08137654
	cmp r1, #0
	bne .L08137648
	cmp r5, #2
	bne .L08137654
	b .L0813764C
	.byte 0x00, 0x00
.L08137638: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813763C: .4byte 0x03006950 @ IWRAM+0x6950
.L08137640: .4byte 0x0300685C @ IWRAM+0x685C
.L08137644: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L08137648:
	cmp r6, #0
	bne .L08137654
.L0813764C:
	ldr r1, .L08137668
	ldrb r0, [r1]
	adds r0, #0x40
	strb r0, [r1]
.L08137654:
	ldr r0, .L08137668
	ldrb r4, [r0]
	lsrs r4, r4, #4
	lsls r4, r4, #1
	cmp r7, #0
	beq .L0813766C
	movs r0, #1
	orrs r4, r0
	b .L0813767C
	.byte 0x00, 0x00
.L08137668: .4byte 0x0300685C @ IWRAM+0x685C
.L0813766C:
	movs r0, #0
	cmp r0, #0
	bne .L0813767C
	ldr r0, .L0813769C
	ldrh r0, [r0]
	movs r1, #1
	bl sub_0815BAC8
.L0813767C:
	lsls r0, r4, #0x11
	ldr r1, .L081376A0
	ldr r2, .L081376A4
	str r2, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	orrs r0, r1
	ldr r1, .L081376A8
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813769C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L081376A0: .4byte 0x03006950 @ IWRAM+0x6950
.L081376A4: .4byte gUnknown_08032D7C
.L081376A8: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start sub_081376AC
sub_081376AC: @ 0x081376AC
.L081376AC:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080C2244
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r4
	blo .L081376C4
	movs r0, #0
	b .L081376C6
.L081376C4:
	movs r0, #1
.L081376C6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start ScriptOp_3CE
ScriptOp_3CE: @ 0x081376CC
	push {r4, r5, lr}
	ldr r3, .L08137714
	ldrh r0, [r3]
	adds r2, r0, #1
	strh r2, [r3]
	lsls r0, r0, #0x10
	ldr r1, .L08137718
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
	ldrh r1, [r1]
	lsls r4, r1, #0x10
	orrs r4, r5
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813770C
	ldr r0, .L0813771C
	str r4, [r0]
.L0813770C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08137714: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08137718: .4byte 0x03006950 @ IWRAM+0x6950
.L0813771C: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start sub_08137720
sub_08137720: @ 0x08137720
.L08137720:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0
	bl sub_080C0F8C
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r5, #2
	beq .L0813775C
	cmp r5, #2
	ble .L0813773E
	cmp r5, #3
	beq .L08137780
	b .L081377A0
.L0813773E:
	cmp r5, #0
	blt .L081377A0
	ldr r0, .L08137758
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	cmp r6, r1
	blt .L081377C4
.L08137754:
	movs r0, #0
	b .L081377C6
.L08137758: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813775C:
	ldr r0, .L0813777C
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	adds r4, r0, #0
	bl sub_080C2244
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r1, #3
	ands r1, r0
	adds r4, r4, r1
	adds r4, #1
	b .L081377BC
	.byte 0x00, 0x00
.L0813777C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L08137780:
	ldr r0, .L0813779C
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	adds r4, r0, #0
	bl sub_080C2244
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ands r0, r5
	adds r4, r4, r0
	adds r4, #6
	b .L081377BC
.L0813779C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L081377A0:
	ldr r0, .L081377CC
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	adds r4, r0, #0
	bl sub_080C2244
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r1, #3
	ands r1, r0
	adds r4, r4, r1
	subs r4, #1
.L081377BC:
	movs r0, #0xff
	ands r4, r0
	cmp r6, r4
	bgt .L08137754
.L081377C4:
	movs r0, #1
.L081377C6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L081377CC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C

	thumb_func_start ScriptOp_3CF
ScriptOp_3CF: @ 0x081377D0
	push {r4, r5, lr}
	ldr r3, .L08137818
	ldrh r0, [r3]
	adds r2, r0, #1
	strh r2, [r3]
	lsls r0, r0, #0x10
	ldr r1, .L0813781C
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
	ldrh r1, [r1]
	lsls r4, r1, #0x10
	orrs r4, r5
	bl sub_08137720
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08137810
	ldr r0, .L08137820
	str r4, [r0]
.L08137810:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08137818: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813781C: .4byte 0x03006950 @ IWRAM+0x6950
.L08137820: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3D0
ScriptOp_3D0: @ 0x08137824
	push {r4, r5, r6, lr}
	ldr r3, .L0813786C
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08137870
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
	movs r1, #1
	bl sub_080C0E44
	cmp r0, r5
	bhi .L08137866
	ldr r0, .L08137874
	str r6, [r0]
.L08137866:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0813786C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08137870: .4byte 0x03006950 @ IWRAM+0x6950
.L08137874: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3D1
ScriptOp_3D1: @ 0x08137878
	push {r4, r5, r6, lr}
	ldr r3, .L081378C4
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L081378C8
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r6, [r0]
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
	ldrh r5, [r0]
	lsls r5, r5, #0x10
	orrs r5, r4
	cmp r6, #1
	bne .L081378CC
	bl sub_080C2244
	adds r4, r0, #0
	movs r0, #7
	ands r4, r0
	cmp r4, #0
	beq .L081378E6
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b .L081378E6
.L081378C4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081378C8: .4byte 0x03006950 @ IWRAM+0x6950
.L081378CC:
	cmp r6, #2
	bne .L081378DC
	bl sub_080C2244
	movs r1, #7
	ands r0, r1
	adds r4, r0, #3
	b .L081378E6
.L081378DC:
	bl sub_080C2244
	adds r4, r0, #0
	movs r0, #0xf
	ands r4, r0
.L081378E6:
	movs r0, #0xff
	ands r4, r0
	movs r0, #0
	bl sub_080C0E20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, r0
	blo .L081378FC
	ldr r0, .L08137904
	str r5, [r0]
.L081378FC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08137904: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3D2
ScriptOp_3D2: @ 0x08137908
	push {r4, r5, r6, lr}
	ldr r3, .L08137950
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08137954
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
	movs r1, #2
	bl sub_080C0E44
	cmp r0, r5
	bhi .L0813794A
	ldr r0, .L08137958
	str r6, [r0]
.L0813794A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08137950: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08137954: .4byte 0x03006950 @ IWRAM+0x6950
.L08137958: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3D3
ScriptOp_3D3: @ 0x0813795C
	push {r4, r5, r6, lr}
	ldr r3, .L081379BC
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L081379C0
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
	lsls r6, r0, #0x10
	orrs r6, r4
	bl sub_080C2244
	adds r4, r0, #0
	movs r5, #7
	ands r4, r5
	bl sub_080C2244
	ands r0, r5
	adds r4, r4, r0
	bl sub_080C2244
	ands r0, r5
	adds r4, r4, r0
	subs r4, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0
	bl sub_080C0D6C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, r0
	blo .L081379B4
	ldr r0, .L081379C4
	str r6, [r0]
.L081379B4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081379BC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081379C0: .4byte 0x03006950 @ IWRAM+0x6950
.L081379C4: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3D4
ScriptOp_3D4: @ 0x081379C8
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_081379CC
sub_081379CC: @ 0x081379CC
.L081379CC:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r6, r4, #0
	bl sub_080EF90C
	adds r5, r0, #0
	cmp r4, #1
	bne .L081379EA
	bl sub_080C2244
	movs r1, #3
	ands r1, r0
	adds r1, #6
	b .L081379F8
.L081379EA:
	cmp r4, #2
	bne .L08137A00
	bl sub_080C2244
	movs r1, #7
	ands r1, r0
	adds r1, #5
.L081379F8:
	cmp r1, r5
	blt .L08137A12
	movs r0, #1
	b .L08137A18
.L08137A00:
	cmp r6, #3
	bne .L08137A18
	bl sub_080C2244
	movs r1, #7
	ands r1, r0
	adds r1, #0xa
	cmp r1, r5
	bge .L08137A16
.L08137A12:
	movs r0, #0
	b .L08137A18
.L08137A16:
	movs r0, #1
.L08137A18:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3D5
ScriptOp_3D5: @ 0x08137A20
	push {r4, r5, lr}
	ldr r3, .L08137A68
	ldrh r0, [r3]
	adds r2, r0, #1
	strh r2, [r3]
	lsls r0, r0, #0x10
	ldr r1, .L08137A6C
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
	ldrh r1, [r1]
	lsls r4, r1, #0x10
	orrs r4, r5
	bl sub_081379CC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08137A60
	ldr r0, .L08137A70
	str r4, [r0]
.L08137A60:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08137A68: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08137A6C: .4byte 0x03006950 @ IWRAM+0x6950
.L08137A70: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3D6
ScriptOp_3D6: @ 0x08137A74
	push {r4, r5, r6, r7, lr}
	bl sub_080EF954
	adds r7, r0, #0
	ldr r3, .L08137AC0
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08137AC4
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r6, [r0]
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
	ldrh r5, [r0]
	lsls r5, r5, #0x10
	orrs r5, r4
	cmp r6, #1
	bne .L08137AC8
	bl sub_080C2244
	adds r1, r0, #0
	movs r0, #3
	ands r1, r0
	adds r1, #6
	b .L08137AE6
	.byte 0x00, 0x00
.L08137AC0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08137AC4: .4byte 0x03006950 @ IWRAM+0x6950
.L08137AC8:
	cmp r6, #2
	bne .L08137ADA
	bl sub_080C2244
	adds r1, r0, #0
	movs r0, #7
	ands r1, r0
	adds r1, #5
	b .L08137AE6
.L08137ADA:
	bl sub_080C2244
	adds r1, r0, #0
	movs r0, #7
	ands r1, r0
	adds r1, #9
.L08137AE6:
	cmp r1, r7
	blt .L08137AEE
	ldr r0, .L08137AF4
	str r5, [r0]
.L08137AEE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08137AF4: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start sub_08137AF8
sub_08137AF8: @ 0x08137AF8
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C2244
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r2, r2, #1
	movs r1, #0xf
	ands r1, r0
	adds r4, r2, r1
	cmp r4, #0
	bne .L08137B12
	movs r4, #1
.L08137B12:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08137B1C
sub_08137B1C: @ 0x08137B1C
.L08137B1C:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080C2244
	movs r1, #0xf
	ands r0, r1
	adds r0, #1
	muls r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc
	bl __udivsi3
	lsls r0, r0, #0x10
	movs r1, #0xa0
	lsls r1, r1, #0xc
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08137B4C
sub_08137B4C: @ 0x08137B4C
.L08137B4C:
	push {r4, lr}
	bl sub_0813BDCC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, .L08137B74
	bl sub_08137B1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r4]
	bl sub_080C30AC
	movs r0, #0x23
	bl sub_0813B328
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08137B74: .4byte 0x0203DB2C @ EWRAM+0x3DB2C

	thumb_func_start sub_08137B78
sub_08137B78: @ 0x08137B78
.L08137B78:
	push {lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsrs r3, r0, #0x13
	movs r2, #0
	cmp r1, #6
	bls .L08137B98
.L08137B88:
	adds r0, r2, r3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #6
	bhi .L08137B88
.L08137B98:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08137BA0
sub_08137BA0: @ 0x08137BA0
.L08137BA0:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_08137B78
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08137BB8
sub_08137BB8: @ 0x08137BB8
.L08137BB8:
	push {r4, r5, lr}
	ldr r4, .L08137BE0
	ldrh r0, [r4]
	movs r1, #0x1a
	bl Demon_GetField
	movs r5, #0xf
	ands r5, r0
	ldrh r0, [r4]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	lsls r0, r1, #2
	cmp r5, #7
	bhi .L08137BE4
	muls r0, r5, r0
	b .L08137BEE
	.byte 0x00, 0x00
.L08137BE0: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L08137BE4:
	adds r1, r5, #0
	bl sub_08137BA0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L08137BEE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_08137BF4
sub_08137BF4: @ 0x08137BF4
.L08137BF4:
	push {r4, lr}
	bl sub_08137BB8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, .L08137C1C
	bl sub_08137B1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r4]
	bl sub_080C3114
	movs r0, #0x24
	bl sub_0813B328
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08137C1C: .4byte 0x0203DB2C @ EWRAM+0x3DB2C

	thumb_func_start sub_08137C20
sub_08137C20: @ 0x08137C20
.L08137C20:
	push {lr}
	ldr r1, .L08137C34
	movs r0, #0xdb
	strh r0, [r1]
	movs r0, #0x25
	bl sub_0813B328
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08137C34: .4byte 0x0203DB50 @ EWRAM+0x3DB50

	thumb_func_start sub_08137C38
sub_08137C38: @ 0x08137C38
.L08137C38:
	push {lr}
	movs r0, #0x27
	bl sub_0813B328
	pop {r0}
	bx r0

	thumb_func_start sub_08137C44
sub_08137C44: @ 0x08137C44
.L08137C44:
	push {r4, r5, lr}
	ldr r5, .L08137C88
	ldrh r0, [r5]
	movs r1, #0x19
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	cmp r1, #0xff
	beq .L08137C80
	ldr r4, .L08137C8C
	strh r1, [r4]
	ldrh r0, [r5]
	movs r1, #0x1d
	bl Demon_GetField
	movs r1, #1
	ands r1, r0
	lsls r1, r1, #8
	ldrh r0, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	lsls r1, r1, #0x10
	ldr r0, .L08137C90
	cmp r1, r0
	bls .L08137C94
	bl sub_0813B268
	cmp r0, #0
	bne .L08137CA8
.L08137C80:
	bl sub_08137C38
	b .L08137CAE
	.byte 0x00, 0x00
.L08137C88: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L08137C8C: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08137C90: .4byte 0x011F0000
.L08137C94:
	ldrh r0, [r4]
	bl sub_080C32FC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq .L08137C80
	ldrh r0, [r4]
	bl sub_080C3328
.L08137CA8:
	movs r0, #0x26
	bl sub_0813B328
.L08137CAE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_08137CB4
sub_08137CB4: @ 0x08137CB4
.L08137CB4:
	push {lr}
	bl sub_080C2244
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L08137CE0
	movs r2, #0x90
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r0, [r1]
	bl sub_0813B268
	cmp r0, #0
	beq .L08137CE4
	movs r0, #0x26
	bl sub_0813B328
	b .L08137CE8
	.byte 0x00, 0x00
.L08137CE0: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08137CE4:
	bl sub_08137C44
.L08137CE8:
	pop {r0}
	bx r0

	thumb_func_start sub_08137CEC
sub_08137CEC: @ 0x08137CEC
.L08137CEC:
	push {r4, lr}
	ldr r4, .L08137D10
	movs r0, #0xe5
	strh r0, [r4]
	movs r0, #0xe5
	bl sub_080C32FC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08137D14
	ldrh r0, [r4]
	bl sub_080C3328
	movs r0, #0x26
	bl sub_0813B328
	b .L08137D18
	.byte 0x00, 0x00
.L08137D10: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08137D14:
	bl sub_08137CB4
.L08137D18:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08137D20
sub_08137D20: @ 0x08137D20
.L08137D20:
	push {lr}
	movs r0, #0x28
	bl sub_0813B328
	pop {r0}
	bx r0

	thumb_func_start sub_08137D2C
sub_08137D2C: @ 0x08137D2C
.L08137D2C:
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r4, .L08137D84
	ldrh r0, [r4]
	movs r1, #0x18
	bl Demon_GetField
	movs r1, #0xf0
	ands r1, r0
	lsrs r6, r1, #4
	ldrh r0, [r4]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	adds r4, r1, #0
	lsls r0, r4, #0x12
	cmp r6, #7
	bls .L08137D5C
	lsrs r1, r0, #0x13
	subs r0, r6, #7
	adds r5, r1, #0
	muls r5, r0, r5
.L08137D5C:
	movs r0, #0
	bl sub_080C0F8C
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r4
	blt .L08137D88
	subs r0, r1, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #3
	bls .L08137DBE
	lsrs r1, r0, #0x12
	adds r0, r5, #0
	bl __udivsi3
	adds r5, r0, #0
	b .L08137DC0
	.byte 0x00, 0x00
.L08137D84: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L08137D88:
	subs r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #3
	bls .L08137DBE
	lsrs r1, r0, #0x12
	adds r2, r1, #0
	cmp r2, #5
	bls .L08137D9C
	movs r2, #5
.L08137D9C:
	movs r1, #0
	cmp r1, r2
	bhs .L08137DBE
	lsls r5, r5, #1
	movs r3, #0x80
	lsls r3, r3, #8
	b .L08137DB6
.L08137DAA:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r2
	bhs .L08137DBE
	lsls r5, r5, #1
.L08137DB6:
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	beq .L08137DAA
.L08137DBE:
	adds r0, r5, #0
.L08137DC0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08137DC8
sub_08137DC8: @ 0x08137DC8
.L08137DC8:
	push {r4, r5, r6, lr}
	bl sub_08137D2C
	adds r5, r0, #0
	ldr r4, .L08137E0C
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_08137B1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x11
	str r0, [r4]
	movs r6, #0x80
	lsls r6, r6, #8
	adds r0, r6, #0
	bl Battle_GetCombatant
	ldr r5, [r0, #8]
	ldr r0, [r4]
	adds r5, r5, r0
	ldr r0, .L08137E10
	cmp r5, r0
	bls .L08137DF8
	adds r5, r0, #0
.L08137DF8:
	adds r0, r6, #0
	bl Battle_GetCombatant
	str r5, [r0, #8]
	movs r0, #0x2b
	bl sub_0813B328
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08137E0C: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L08137E10: .4byte 0x001994D4

	thumb_func_start sub_08137E14
sub_08137E14: @ 0x08137E14
.L08137E14:
	push {lr}
	ldr r0, .L08137E50
	ldrh r0, [r0]
	movs r1, #0x1f
	bl Demon_GetField
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x20
	beq .L08137E72
	cmp r1, #0x60
	beq .L08137E72
	movs r0, #1
	bl sub_080C09B0
	cmp r0, #0
	bne .L08137E40
	movs r0, #2
	bl sub_080C09B0
	cmp r0, #0
	beq .L08137E64
.L08137E40:
	movs r0, #1
	bl sub_080C09B0
	cmp r0, #0
	beq .L08137E54
	movs r0, #1
	b .L08137E56
	.byte 0x00, 0x00
.L08137E50: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L08137E54:
	movs r0, #2
.L08137E56:
	bl sub_080C0818
	movs r1, #0xb0
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L08137E6A
.L08137E64:
	bl sub_08137DC8
	b .L08137E78
.L08137E6A:
	movs r0, #0x29
	bl sub_0813B328
	b .L08137E78
.L08137E72:
	movs r0, #0x2a
	bl sub_0813B328
.L08137E78:
	pop {r0}
	bx r0

	thumb_func_start sub_08137E7C
sub_08137E7C: @ 0x08137E7C
.L08137E7C:
	push {r4, r5, r6, r7, lr}
	bl sub_080C104C
	adds r7, r0, #0
	movs r6, #0
	b .L08137ECE
.L08137E88:
	adds r0, r6, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L08137EC8
	adds r0, r6, #0
	bl sub_080C0818
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	bne .L08137EC8
	adds r0, r6, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r5, #0
	bl Battle_GetCombatant
	ldrh r0, [r0, #0x1a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #0
	bl Battle_GetCombatant
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r4, r0
	bge .L08137F7C
.L08137EC8:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L08137ECE:
	adds r0, r7, #4
	cmp r6, r0
	blt .L08137E88
	movs r6, #0
	adds r7, #4
	cmp r6, r7
	bge .L08137F12
.L08137EDC:
	adds r0, r6, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L08137F08
	adds r0, r6, #0
	bl sub_080C0818
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0xc0
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne .L08137F08
	ldr r1, .L08137F78
	adds r0, r1, #0
	ands r4, r0
	cmp r4, #0
	bne .L08137F90
.L08137F08:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, r7
	blt .L08137EDC
.L08137F12:
	movs r6, #0
	cmp r6, r7
	bge .L08137F70
.L08137F18:
	adds r0, r6, #0
	bl sub_080C09B0
	cmp r0, #0
	beq .L08137F66
	adds r0, r6, #0
	bl sub_080C0818
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	bne .L08137F66
	adds r0, r6, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r5, #0
	bl Battle_GetCombatant
	movs r1, #0x1e
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08137F66
	adds r0, r5, #0
	bl Battle_GetCombatant
	ldrh r0, [r0, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #0
	bl Battle_GetCombatant
	movs r1, #0x1c
	ldrsh r0, [r0, r1]
	cmp r4, r0
	bge .L08137FAC
.L08137F66:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, r7
	blt .L08137F18
.L08137F70:
	bl sub_08137B4C
	b .L08137FC4
	.byte 0x00, 0x00
.L08137F78: .4byte 0x00003FFE
.L08137F7C:
	adds r0, r5, #0
	bl Battle_GetCombatant
	adds r4, r0, #0
	adds r0, r5, #0
	bl Battle_GetCombatant
	ldrh r0, [r0, #0x1a]
	strh r0, [r4, #0x18]
	b .L08137FBE
.L08137F90:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r6, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrh r2, [r0, #0x10]
	ldr r1, .L08137FA8
	ands r1, r2
	strh r1, [r0, #0x10]
	b .L08137FBE
.L08137FA8: .4byte 0x0000C001
.L08137FAC:
	adds r0, r5, #0
	bl Battle_GetCombatant
	adds r4, r0, #0
	adds r0, r5, #0
	bl Battle_GetCombatant
	ldrh r0, [r0, #0x1e]
	strh r0, [r4, #0x1c]
.L08137FBE:
	movs r0, #0x2c
	bl sub_0813B328
.L08137FC4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08137FCC
sub_08137FCC: @ 0x08137FCC
.L08137FCC:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L08137FE4
	ldrb r4, [r0]
	cmp r1, #0xa
	bhi .L08138058
	lsls r0, r1, #2
	ldr r1, .L08137FE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08137FE4: .4byte 0x0300685C @ IWRAM+0x685C
.L08137FE8: .4byte gUnknown_08137FEC
	.global gUnknown_08137FEC
gUnknown_08137FEC:
.L08137FEC: @ jump table
	.4byte .L08138018
	.4byte .L0813801E
	.4byte .L08138024
	.4byte .L0813802A
	.4byte .L08138030
	.4byte .L08138036
	.4byte .L0813803C
	.4byte .L08138042
	.4byte .L08138048
	.4byte .L0813804E
	.4byte .L08138054
.L08138018:
	bl sub_08137E7C
	b .L08138058
.L0813801E:
	bl sub_08137B4C
	b .L08138058
.L08138024:
	bl sub_08137BF4
	b .L08138058
.L0813802A:
	bl sub_08137C20
	b .L08138058
.L08138030:
	bl sub_08137CEC
	b .L08138058
.L08138036:
	bl sub_08137CB4
	b .L08138058
.L0813803C:
	bl sub_08137C44
	b .L08138058
.L08138042:
	bl sub_08137C38
	b .L08138058
.L08138048:
	bl sub_08137D20
	b .L08138058
.L0813804E:
	bl sub_08137E14
	b .L08138058
.L08138054:
	bl sub_08137DC8
.L08138058:
	ldr r0, .L0813806C
	strb r4, [r0]
	ldr r0, .L08138070
	ldrh r0, [r0]
	movs r1, #1
	bl sub_0815BAC8
	pop {r4}
	pop {r0}
	bx r0
.L0813806C: .4byte 0x0300685C @ IWRAM+0x685C
.L08138070: .4byte 0x0203DB7C @ EWRAM+0x3DB7C

	thumb_func_start sub_08138074
sub_08138074: @ 0x08138074
.L08138074:
	push {r4, lr}
	sub sp, #4
	ldr r0, .L081380AC
	ldrh r0, [r0]
	mov r2, sp
	adds r2, #1
	mov r1, sp
	bl sub_0815B9B8
	mov r0, sp
	ldrb r1, [r0]
	movs r0, #0xb
	adds r4, r1, #0
	muls r4, r0, r4
	bl sub_080C2244
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
.L08138098:
	ldr r0, .L081380B0
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, r1
	bhs .L081380B4
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b .L08138098
	.byte 0x00, 0x00
.L081380AC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L081380B0: .4byte gUnknown_08790458
.L081380B4:
	adds r0, r4, #0
	movs r1, #0xb
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_08137FCC
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_081380CC
sub_081380CC: @ 0x081380CC
.L081380CC:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_08137FCC
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3D7
ScriptOp_3D7: @ 0x081380DC
	push {r4, r5, r6, lr}
	ldr r3, .L08138120
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08138124
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r5, [r0]
	adds r6, r5, #0
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
	lsls r0, r0, #0x10
	orrs r0, r4
	ldr r1, .L08138128
	str r0, [r1]
	cmp r5, #0
	bne .L0813812C
	bl sub_08138074
	b .L0813814E
	.byte 0x00, 0x00
.L08138120: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138124: .4byte 0x03006950 @ IWRAM+0x6950
.L08138128: .4byte 0x03006840 @ IWRAM+0x6840
.L0813812C:
	cmp r5, #1
	bne .L08138138
	movs r0, #1
	bl sub_081380CC
	b .L0813814E
.L08138138:
	cmp r5, #2
	bne .L08138144
	movs r0, #2
	bl sub_081380CC
	b .L0813814E
.L08138144:
	cmp r6, #6
	bne .L0813814E
	movs r0, #6
	bl sub_081380CC
.L0813814E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ScriptOp_3D8
ScriptOp_3D8: @ 0x08138154
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3D9
ScriptOp_3D9: @ 0x08138158
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3DA
ScriptOp_3DA: @ 0x0813815C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3DB
ScriptOp_3DB: @ 0x08138160
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3DC
ScriptOp_3DC: @ 0x08138164
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3DD
ScriptOp_3DD: @ 0x08138168
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3DE
ScriptOp_3DE: @ 0x0813816C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3DF
ScriptOp_3DF: @ 0x08138170
	push {lr}
	ldr r2, .L0813819C
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L081381A0
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r1, #0
	cmp r1, #0xff
	bne .L081381B0
	ldr r2, .L081381A4
	ldr r1, .L081381A8
	ldrb r0, [r1]
	cmp r0, #1
	bhi .L081381AC
	movs r0, #0
	b .L081381F8
	.byte 0x00, 0x00
.L0813819C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081381A0: .4byte 0x03006950 @ IWRAM+0x6950
.L081381A4: .4byte 0x0000FFFF
.L081381A8: .4byte 0x030068B4 @ IWRAM+0x68B4
.L081381AC:
	subs r0, #1
	b .L081381F8
.L081381B0:
	cmp r1, #0xfe
	bne .L081381D0
	ldr r2, .L081381C4
	ldr r1, .L081381C8
	ldrb r0, [r1]
	cmp r0, #2
	bhi .L081381CC
	movs r0, #0
	b .L081381F8
	.byte 0x00, 0x00
.L081381C4: .4byte 0x0000FFFE
.L081381C8: .4byte 0x030068B4 @ IWRAM+0x68B4
.L081381CC:
	subs r0, #2
	b .L081381F8
.L081381D0:
	cmp r1, #0xfd
	bne .L081381F0
	ldr r2, .L081381E4
	ldr r1, .L081381E8
	ldrb r0, [r1]
	cmp r0, #3
	bhi .L081381EC
	movs r0, #0
	b .L081381F8
	.byte 0x00, 0x00
.L081381E4: .4byte 0x0000FFFD
.L081381E8: .4byte 0x030068B4 @ IWRAM+0x68B4
.L081381EC:
	subs r0, #3
	b .L081381F8
.L081381F0:
	adds r2, r0, #0
	ldr r1, .L08138218
	ldrb r0, [r1]
	adds r0, r0, r2
.L081381F8:
	strb r0, [r1]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	bl sub_080EFA20
	ldr r2, .L08138218
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08138212
	movs r0, #0
	strb r0, [r2]
.L08138212:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08138218: .4byte 0x030068B4 @ IWRAM+0x68B4

	thumb_func_start sub_0813821C
sub_0813821C: @ 0x0813821C
.L0813821C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	cmp r0, #0xff
	bne .L08138244
	ldr r2, .L08138238
	ldr r1, .L0813823C
	ldrb r0, [r1]
	cmp r0, #1
	bhi .L08138240
	movs r0, #0
	b .L081382EC
	.byte 0x00, 0x00
.L08138238: .4byte 0x0000FFFF
.L0813823C: .4byte 0x030069E8 @ IWRAM+0x69E8
.L08138240:
	subs r0, #1
	b .L081382EC
.L08138244:
	cmp r0, #0xfe
	bne .L08138264
	ldr r2, .L08138258
	ldr r1, .L0813825C
	ldrb r0, [r1]
	cmp r0, #2
	bhi .L08138260
	movs r0, #0
	b .L081382EC
	.byte 0x00, 0x00
.L08138258: .4byte 0x0000FFFE
.L0813825C: .4byte 0x030069E8 @ IWRAM+0x69E8
.L08138260:
	subs r0, #2
	b .L081382EC
.L08138264:
	cmp r0, #0xfd
	bne .L08138284
	ldr r2, .L08138278
	ldr r1, .L0813827C
	ldrb r0, [r1]
	cmp r0, #3
	bhi .L08138280
	movs r0, #0
	b .L081382EC
	.byte 0x00, 0x00
.L08138278: .4byte 0x0000FFFD
.L0813827C: .4byte 0x030069E8 @ IWRAM+0x69E8
.L08138280:
	subs r0, #3
	b .L081382EC
.L08138284:
	cmp r0, #0xfc
	bne .L081382A4
	ldr r2, .L08138298
	ldr r1, .L0813829C
	ldrb r0, [r1]
	cmp r0, #4
	bhi .L081382A0
	movs r0, #0
	b .L081382EC
	.byte 0x00, 0x00
.L08138298: .4byte 0x0000FFFC
.L0813829C: .4byte 0x030069E8 @ IWRAM+0x69E8
.L081382A0:
	subs r0, #4
	b .L081382EC
.L081382A4:
	cmp r0, #0xfb
	bne .L081382C4
	ldr r2, .L081382B8
	ldr r1, .L081382BC
	ldrb r0, [r1]
	cmp r0, #5
	bhi .L081382C0
	movs r0, #0
	b .L081382EC
	.byte 0x00, 0x00
.L081382B8: .4byte 0x0000FFFB
.L081382BC: .4byte 0x030069E8 @ IWRAM+0x69E8
.L081382C0:
	subs r0, #5
	b .L081382EC
.L081382C4:
	cmp r0, #0xfa
	bne .L081382E4
	ldr r2, .L081382D8
	ldr r1, .L081382DC
	ldrb r0, [r1]
	cmp r0, #6
	bhi .L081382E0
	movs r0, #0
	b .L081382EC
	.byte 0x00, 0x00
.L081382D8: .4byte 0x0000FFFA
.L081382DC: .4byte 0x030069E8 @ IWRAM+0x69E8
.L081382E0:
	subs r0, #6
	b .L081382EC
.L081382E4:
	adds r2, r1, #0
	ldr r1, .L0813830C
	ldrb r0, [r1]
	adds r0, r0, r2
.L081382EC:
	strb r0, [r1]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	bl sub_080EFA44
	ldr r2, .L0813830C
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08138306
	movs r0, #0
	strb r0, [r2]
.L08138306:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813830C: .4byte 0x030069E8 @ IWRAM+0x69E8

	thumb_func_start ScriptOp_3E0
ScriptOp_3E0: @ 0x08138310
	push {lr}
	ldr r2, .L08138330
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08138334
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_0813821C
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08138330: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138334: .4byte 0x03006950 @ IWRAM+0x6950

	thumb_func_start sub_08138338
sub_08138338: @ 0x08138338
.L08138338:
	push {lr}
	bl sub_080C2244
	adds r1, r0, #0
	lsls r1, r1, #0x10
	movs r0, #0xc0
	lsls r0, r0, #0xa
	ands r0, r1
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3E1
ScriptOp_3E1: @ 0x08138350
	push {lr}
	bl sub_08138338
	lsls r0, r0, #0x11
	ldr r2, .L08138384
	lsrs r0, r0, #0x10
	ldrh r1, [r2]
	adds r0, r0, r1
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08138388
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
	ldr r1, .L0813838C
	str r0, [r1]
	pop {r0}
	bx r0
.L08138384: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138388: .4byte 0x03006950 @ IWRAM+0x6950
.L0813838C: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start sub_08138390
sub_08138390: @ 0x08138390
.L08138390:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L081383D0
	ldr r4, .L081383D4
	ldr r1, [r4]
	str r1, [r2]
	ldr r2, .L081383D8
	ldr r1, .L081383DC
	ldrh r1, [r1]
	strh r1, [r2]
	ldr r2, .L081383E0
	movs r1, #1
	strh r1, [r2]
	ldr r1, .L081383E4
	ldrb r3, [r1]
	lsrs r5, r3, #4
	ldr r2, .L081383E8
	lsls r1, r5, #1
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0xf
	ands r1, r3
	muls r0, r2, r0
	adds r1, r1, r0
	lsls r1, r1, #0x11
	lsrs r2, r1, #0x10
	cmp r5, #0
	bne .L081383F0
	ldr r0, .L081383EC
	b .L0813846A
	.byte 0x00, 0x00
.L081383D0: .4byte 0x030068C4 @ IWRAM+0x68C4
.L081383D4: .4byte 0x03006950 @ IWRAM+0x6950
.L081383D8: .4byte 0x03006818 @ IWRAM+0x6818
.L081383DC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081383E0: .4byte 0x0203DB64 @ EWRAM+0x3DB64
.L081383E4: .4byte 0x0300685C @ IWRAM+0x685C
.L081383E8: .4byte gUnknown_087904F2
.L081383EC: .4byte gUnknown_0803473C
.L081383F0:
	cmp r5, #1
	bne .L081383FC
	ldr r0, .L081383F8
	b .L0813846A
.L081383F8: .4byte gUnknown_08033560
.L081383FC:
	cmp r5, #2
	bne .L08138408
	ldr r0, .L08138404
	b .L0813846A
.L08138404: .4byte gUnknown_08032DE0
.L08138408:
	cmp r5, #3
	bne .L08138414
	ldr r0, .L08138410
	b .L0813846A
.L08138410: .4byte gUnknown_080341EC
.L08138414:
	cmp r5, #4
	bne .L08138420
	ldr r0, .L0813841C
	b .L0813846A
.L0813841C: .4byte gUnknown_0803473C
.L08138420:
	cmp r5, #5
	bne .L0813842C
	ldr r0, .L08138428
	b .L0813846A
.L08138428: .4byte gUnknown_08033560
.L0813842C:
	cmp r5, #6
	bne .L08138438
	ldr r0, .L08138434
	b .L0813846A
.L08138434: .4byte gUnknown_08032DE0
.L08138438:
	cmp r5, #7
	bne .L08138444
	ldr r0, .L08138440
	b .L0813846A
.L08138440: .4byte gUnknown_080341EC
.L08138444:
	cmp r5, #8
	bne .L08138450
	ldr r0, .L0813844C
	b .L0813846A
.L0813844C: .4byte gUnknown_08034094
.L08138450:
	cmp r5, #9
	bne .L0813845C
	ldr r0, .L08138458
	b .L0813846A
.L08138458: .4byte gUnknown_0803526C
.L0813845C:
	cmp r5, #0xa
	bne .L08138468
	ldr r0, .L08138464
	b .L0813846A
.L08138464: .4byte gUnknown_080340B8
.L08138468:
	ldr r0, .L08138484
.L0813846A:
	str r0, [r4]
	ldr r1, [r4]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	orrs r0, r1
	ldr r1, .L08138488
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08138484: .4byte gUnknown_08034138
.L08138488: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start sub_0813848C
sub_0813848C: @ 0x0813848C
.L0813848C:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L081384CC
	ldr r4, .L081384D0
	ldr r1, [r4]
	str r1, [r2]
	ldr r2, .L081384D4
	ldr r1, .L081384D8
	ldrh r1, [r1]
	strh r1, [r2]
	ldr r2, .L081384DC
	movs r1, #1
	strh r1, [r2]
	ldr r1, .L081384E0
	ldrb r3, [r1]
	lsrs r5, r3, #4
	ldr r2, .L081384E4
	lsls r1, r5, #1
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0xf
	ands r1, r3
	muls r0, r2, r0
	adds r1, r1, r0
	lsls r1, r1, #0x11
	lsrs r2, r1, #0x10
	cmp r5, #0
	bne .L081384EC
	ldr r0, .L081384E8
	b .L08138566
	.byte 0x00, 0x00
.L081384CC: .4byte 0x030068C4 @ IWRAM+0x68C4
.L081384D0: .4byte 0x03006950 @ IWRAM+0x6950
.L081384D4: .4byte 0x03006818 @ IWRAM+0x6818
.L081384D8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081384DC: .4byte 0x0203DB64 @ EWRAM+0x3DB64
.L081384E0: .4byte 0x0300685C @ IWRAM+0x685C
.L081384E4: .4byte gUnknown_087904F2
.L081384E8: .4byte gUnknown_080367F2
.L081384EC:
	cmp r5, #1
	bne .L081384F8
	ldr r0, .L081384F4
	b .L08138566
.L081384F4: .4byte gUnknown_080366C2
.L081384F8:
	cmp r5, #2
	bne .L08138504
	ldr r0, .L08138500
	b .L08138566
.L08138500: .4byte gUnknown_080366C2
.L08138504:
	cmp r5, #3
	bne .L08138510
	ldr r0, .L0813850C
	b .L08138566
.L0813850C: .4byte gUnknown_080367E2
.L08138510:
	cmp r5, #4
	bne .L0813851C
	ldr r0, .L08138518
	b .L08138566
.L08138518: .4byte gUnknown_080367F2
.L0813851C:
	cmp r5, #5
	bne .L08138528
	ldr r0, .L08138524
	b .L08138566
.L08138524: .4byte gUnknown_080366C2
.L08138528:
	cmp r5, #6
	bne .L08138534
	ldr r0, .L08138530
	b .L08138566
.L08138530: .4byte gUnknown_080366C2
.L08138534:
	cmp r5, #7
	bne .L08138540
	ldr r0, .L0813853C
	b .L08138566
.L0813853C: .4byte gUnknown_080367E2
.L08138540:
	cmp r5, #8
	bne .L0813854C
	ldr r0, .L08138548
	b .L08138566
.L08138548: .4byte gUnknown_080367E2
.L0813854C:
	cmp r5, #9
	bne .L08138558
	ldr r0, .L08138554
	b .L08138566
.L08138554: .4byte gUnknown_08037322
.L08138558:
	cmp r5, #0xa
	bne .L08138564
	ldr r0, .L08138560
	b .L08138566
.L08138560: .4byte gUnknown_080367E2
.L08138564:
	ldr r0, .L08138580
.L08138566:
	str r0, [r4]
	ldr r1, [r4]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	orrs r0, r1
	ldr r1, .L08138584
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08138580: .4byte gUnknown_080367E2
.L08138584: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3E2_40F
ScriptOp_3E2_40F: @ 0x08138588
	push {lr}
	ldr r2, .L081385BC
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L081385C0
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_08138390
	ldr r0, .L081385C4
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L081385C8
	strh r1, [r0]
	ldr r0, .L081385CC
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	pop {r0}
	bx r0
.L081385BC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081385C0: .4byte 0x03006950 @ IWRAM+0x6950
.L081385C4: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L081385C8: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L081385CC: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
