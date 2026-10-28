	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_08130D24
sub_08130D24: @ 0x08130D24
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	ldr r4, .L08130DDC
	ldrh r5, [r4]
	movs r7, #0xf
	ands r7, r5
	mov sl, r7
	ldr r2, .L08130DE0
	ldr r3, .L08130DE4
	ldr r6, .L08130DE8
	movs r1, #0
	ldrsh r0, [r6, r1]
	lsls r0, r0, #2
	lsls r1, r7, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r0, #8
	strh r0, [r2]
	ldr r2, .L08130DEC
	mov r8, r2
	movs r2, #0
	ldrsh r0, [r6, r2]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r3, r8
	strh r0, [r3]
	ldr r1, .L08130DF0
	movs r0, #0x13
	strh r0, [r1]
	ldr r1, .L08130DF4
	movs r0, #1
	strh r0, [r1]
	ldr r0, .L08130DF8
	mov ip, r0
	ldrh r0, [r0]
	mov r8, r6
	mov r2, ip
	cmp r0, #0
	beq .L08130D8A
	subs r0, #1
	strh r0, [r2]
.L08130D8A:
	ldr r0, .L08130DFC
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L08130D9A
	b .L08130EEC
.L08130D9A:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq .L08130E10
	movs r2, #0
	strh r2, [r6]
	cmp r7, #0
	beq .L08130DAC
	b .L08131280
.L08130DAC:
	movs r0, #0xf0
	ands r0, r5
	cmp r0, #0
	beq .L08130DB6
	b .L0813125C
.L08130DB6:
	ldr r5, .L08130E00
	ldr r4, .L08130E04
	movs r3, #0
	ldrsh r0, [r4, r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r3, .L08130E08
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08130E0C
	ldr r0, [r0]
	movs r2, #0
	ldrsh r1, [r6, r2]
	b .L08131234
	.byte 0x00, 0x00
.L08130DDC: .4byte 0x03006844 @ IWRAM+0x6844
.L08130DE0: .4byte 0x0300689C @ IWRAM+0x689C
.L08130DE4: .4byte gUnknown_0878FBA4
.L08130DE8: .4byte 0x0300696C @ IWRAM+0x696C
.L08130DEC: .4byte 0x0300695C @ IWRAM+0x695C
.L08130DF0: .4byte 0x030066A0 @ IWRAM+0x66A0
.L08130DF4: .4byte 0x03006958 @ IWRAM+0x6958
.L08130DF8: .4byte 0x030068AC @ IWRAM+0x68AC
.L08130DFC: .4byte 0x03003964 @ IWRAM+0x3964
.L08130E00: .4byte gUnknown_0878FDB4
.L08130E04: .4byte 0x03006940 @ IWRAM+0x6940
.L08130E08: .4byte 0x0000FFFF
.L08130E0C: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130E10:
	ldr r1, .L08130E38
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne .L08130E1E
	b .L0813134E
.L08130E1E:
	movs r0, #3
	mov r3, ip
	strh r0, [r3]
	cmp r7, #1
	bne .L08130E42
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r0, #3
	cmp r0, #0
	blt .L08130E3C
	subs r0, r2, #3
	strh r0, [r1]
	b .L08130ED4
.L08130E38: .4byte 0x03006940 @ IWRAM+0x6940
.L08130E3C:
	movs r0, #0
	strh r0, [r1]
	b .L08130ED4
.L08130E42:
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, #4
	cmp r0, #0
	blt .L08130E50
	subs r0, r2, #4
	b .L08130E52
.L08130E50:
	movs r0, #0
.L08130E52:
	strh r0, [r1]
	ldrh r1, [r4]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne .L08130EB0
	ldr r5, .L08130EA0
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r4, .L08130EA4
	movs r3, #0
	ldrsh r1, [r4, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r3, .L08130EA8
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08130EAC
	ldr r0, [r0]
	mov r2, r8
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r3, #0
	ldrsh r2, [r4, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r3, [r1]
	movs r1, #3
	movs r2, #0
	bl sub_080D34A4
	b .L08130ED4
.L08130EA0: .4byte gUnknown_0878FDB4
.L08130EA4: .4byte 0x03006940 @ IWRAM+0x6940
.L08130EA8: .4byte 0x0000FFFF
.L08130EAC: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130EB0:
	bl sub_08130C6C
	ldr r4, .L08130EE0
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	ldrh r3, [r4, #6]
	ldrh r4, [r4, #8]
	str r4, [sp]
	bl sub_080D347C
	ldr r0, .L08130EE4
	ldr r0, [r0]
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl sub_080D34A4
.L08130ED4:
	ldr r0, .L08130EE8
	ldrh r0, [r0]
	bl sub_08133F14
	b .L08131280
	.byte 0x00, 0x00
.L08130EE0: .4byte 0x03006980 @ IWRAM+0x6980
.L08130EE4: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130EE8: .4byte 0x03006940 @ IWRAM+0x6940
.L08130EEC:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08130EF8
	b .L08131078
.L08130EF8:
	cmp r7, #1
	bne .L08130F4E
	ldrh r4, [r6]
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #2
	bne .L08130F48
	ldr r2, .L08130F28
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	adds r0, #3
	cmp r0, #0xa
	bgt .L08130F2C
	movs r0, #3
	mov r4, ip
	strh r0, [r4]
	ldrh r0, [r2]
	adds r0, #3
.L08130F1E:
	strh r0, [r2]
	ldrh r0, [r2]
	bl sub_08133F14
	b .L08131280
.L08130F28: .4byte 0x03006940 @ IWRAM+0x6940
.L08130F2C:
	ldrh r3, [r2]
	adds r1, r4, r3
	movs r0, #0xb
	subs r0, r0, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bne .L08130F3E
	b .L0813134E
.L08130F3E:
	movs r0, #3
	mov r4, ip
	strh r0, [r4]
	adds r0, r1, r3
	b .L08130F1E
.L08130F48:
	movs r0, #2
	strh r0, [r6]
	b .L08131280
.L08130F4E:
	ldrh r7, [r6]
	movs r0, #0
	ldrsh r2, [r6, r0]
	cmp r2, #3
	bne .L08131034
	adds r0, r2, #0
	ldr r5, .L08130FB8
	movs r3, #0
	ldrsh r1, [r5, r3]
	adds r0, r0, r1
	adds r0, #4
	cmp r0, #0xa
	bgt .L08130FC8
	mov r0, ip
	strh r2, [r0]
	ldrh r0, [r5]
	adds r0, #4
	strh r0, [r5]
	ldrh r0, [r5]
	bl sub_08133F14
	ldrh r1, [r4]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq .L08130F84
	b .L0813125C
.L08130F84:
	ldr r4, .L08130FBC
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r3, .L08130FC0
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08130FC4
	ldr r0, [r0]
	movs r3, #0
	ldrsh r1, [r6, r3]
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	b .L0813123E
	.byte 0x00, 0x00
.L08130FB8: .4byte 0x03006940 @ IWRAM+0x6940
.L08130FBC: .4byte gUnknown_0878FDB4
.L08130FC0: .4byte 0x0000FFFF
.L08130FC4: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130FC8:
	ldrh r3, [r5]
	adds r1, r7, r3
	movs r0, #0xb
	subs r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne .L08130FDA
	b .L0813134E
.L08130FDA:
	mov r1, ip
	strh r2, [r1]
	adds r0, r0, r3
	strh r0, [r5]
	ldrh r0, [r5]
	bl sub_08133F14
	ldrh r1, [r4]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq .L08130FF4
	b .L0813125C
.L08130FF4:
	ldr r4, .L08131028
	movs r2, #0
	ldrsh r0, [r6, r2]
	movs r3, #0
	ldrsh r1, [r5, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r3, .L0813102C
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08131030
	ldr r0, [r0]
	movs r2, #0
	ldrsh r1, [r6, r2]
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	b .L0813123E
	.byte 0x00, 0x00
.L08131028: .4byte gUnknown_0878FDB4
.L0813102C: .4byte 0x0000FFFF
.L08131030: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08131034:
	movs r0, #3
	strh r0, [r6]
	movs r0, #0xf0
	ands r0, r5
	cmp r0, #0
	beq .L08131042
	b .L0813125C
.L08131042:
	ldr r5, .L08131068
	ldr r4, .L0813106C
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, #3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r3, .L08131070
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08131074
	ldr r0, [r0]
	movs r2, #0
	ldrsh r1, [r6, r2]
	b .L08131234
.L08131068: .4byte gUnknown_0878FDB4
.L0813106C: .4byte 0x03006940 @ IWRAM+0x6940
.L08131070: .4byte 0x0000FFFF
.L08131074: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08131078:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L0813114C
	ldrh r1, [r6]
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #0
	beq .L081310D8
	subs r0, r1, #1
	strh r0, [r6]
	cmp r7, #0
	beq .L08131094
	b .L08131280
.L08131094:
	movs r0, #0xf0
	ands r0, r5
	cmp r0, #0
	beq .L0813109E
	b .L0813125C
.L0813109E:
	ldr r5, .L081310C8
	movs r3, #0
	ldrsh r0, [r6, r3]
	ldr r4, .L081310CC
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r3, .L081310D0
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L081310D4
	ldr r0, [r0]
	movs r3, #0
	ldrsh r1, [r6, r3]
	b .L08131234
.L081310C8: .4byte gUnknown_0878FDB4
.L081310CC: .4byte 0x03006940 @ IWRAM+0x6940
.L081310D0: .4byte 0x0000FFFF
.L081310D4: .4byte 0x030068A4 @ IWRAM+0x68A4
.L081310D8:
	ldr r5, .L0813113C
	ldrh r1, [r5]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bne .L081310E6
	b .L0813134E
.L081310E6:
	movs r0, #3
	mov r3, ip
	strh r0, [r3]
	subs r0, r1, #1
	strh r0, [r5]
	ldrh r0, [r5]
	bl sub_08133F14
	cmp r7, #0
	beq .L081310FC
	b .L08131280
.L081310FC:
	ldrh r1, [r4]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq .L08131108
	b .L0813125C
.L08131108:
	ldr r4, .L08131140
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r3, .L08131144
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08131148
	ldr r0, [r0]
	movs r3, #0
	ldrsh r1, [r6, r3]
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	b .L0813123E
	.byte 0x00, 0x00
.L0813113C: .4byte 0x03006940 @ IWRAM+0x6940
.L08131140: .4byte gUnknown_0878FDB4
.L08131144: .4byte 0x0000FFFF
.L08131148: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813114C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne .L08131156
	b .L08131290
.L08131156:
	cmp r7, #1
	bne .L08131162
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #2
	beq .L0813116E
.L08131162:
	cmp r7, #0
	bne .L081311F0
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #3
	bne .L081311F0
.L0813116E:
	mov r4, r8
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r5, .L081311DC
	movs r3, #0
	ldrsh r1, [r5, r3]
	adds r0, r0, r1
	cmp r0, #0xa
	ble .L08131182
	b .L0813134E
.L08131182:
	movs r0, #3
	strh r0, [r2]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ldrh r0, [r5]
	bl sub_08133F14
	mov r4, sl
	cmp r4, #0
	bne .L08131280
	ldr r0, .L081311E0
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne .L0813125C
	ldr r4, .L081311E4
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r3, #0
	ldrsh r1, [r5, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r3, .L081311E8
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L081311EC
	ldr r0, [r0]
	mov r2, r8
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	b .L0813123E
	.byte 0x00, 0x00
.L081311DC: .4byte 0x03006940 @ IWRAM+0x6940
.L081311E0: .4byte 0x03006844 @ IWRAM+0x6844
.L081311E4: .4byte gUnknown_0878FDB4
.L081311E8: .4byte 0x0000FFFF
.L081311EC: .4byte 0x030068A4 @ IWRAM+0x68A4
.L081311F0:
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	mov r2, sl
	cmp r2, #0
	bne .L08131280
	ldrh r1, [r4]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne .L0813125C
	ldr r5, .L0813124C
	mov r3, r8
	movs r4, #0
	ldrsh r0, [r3, r4]
	ldr r4, .L08131250
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r3, .L08131254
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	ldr r0, .L08131258
	ldr r0, [r0]
	mov r3, r8
	movs r2, #0
	ldrsh r1, [r3, r2]
.L08131234:
	movs r3, #0
	ldrsh r2, [r4, r3]
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r5
.L0813123E:
	ldrh r3, [r1]
	movs r1, #3
	movs r2, #0
	bl sub_080D34A4
	b .L08131280
	.byte 0x00, 0x00
.L0813124C: .4byte gUnknown_0878FDB4
.L08131250: .4byte 0x03006940 @ IWRAM+0x6940
.L08131254: .4byte 0x0000FFFF
.L08131258: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813125C:
	bl sub_08130C6C
	ldr r4, .L08131288
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	ldrh r3, [r4, #6]
	ldrh r4, [r4, #8]
	str r4, [sp]
	bl sub_080D347C
	ldr r0, .L0813128C
	ldr r0, [r0]
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl sub_080D34A4
.L08131280:
	movs r0, #0x64
	bl Sound_Play
	b .L0813134E
.L08131288: .4byte 0x03006980 @ IWRAM+0x6980
.L0813128C: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08131290:
	ldr r2, .L081312E4
	ldrh r1, [r2]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L08131334
	mov r1, ip
	ldrh r0, [r1]
	cmp r0, #0
	bne .L0813134E
	ldr r7, .L081312E8
	movs r2, #0
	ldrsh r0, [r6, r2]
	ldr r5, .L081312EC
	movs r3, #0
	ldrsh r1, [r5, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	bl Inventory_GetCount
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08131304
	mov r0, sl
	cmp r0, #0
	bne .L081312FC
	ldr r1, .L081312F0
	ldr r0, .L081312F4
	ldr r0, [r0, #4]
	str r0, [r1]
	mov r1, sb
	strh r4, [r1, #0x1c]
	ldr r1, .L081312F8
	movs r0, #0x30
	strh r0, [r1]
	movs r0, #0x66
	bl Sound_Play
	b .L0813134E
.L081312E4: .4byte 0x030031C4 @ IWRAM+0x31C4
.L081312E8: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L081312EC: .4byte 0x03006940 @ IWRAM+0x6940
.L081312F0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081312F4: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L081312F8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L081312FC:
	movs r0, #0x68
	bl Sound_Play
	b .L0813134E
.L08131304:
	mov r2, sb
	strh r4, [r2, #0x1c]
	ldr r1, .L0813132C
	movs r0, #0x30
	strh r0, [r1]
	ldr r2, .L08131330
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r4, #0
	ldrsh r1, [r5, r4]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	strh r0, [r2]
	movs r0, #0x65
	bl Sound_Play
	b .L0813134E
	.byte 0x00, 0x00
.L0813132C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08131330: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08131334:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0813134E
	mov r0, sb
	strh r4, [r0, #0x1c]
	ldr r1, .L08131360
	movs r0, #0x2f
	strh r0, [r1]
	movs r0, #0x66
	bl Sound_Play
.L0813134E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08131360: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
