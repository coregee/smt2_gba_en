	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start ScriptOp_438
ScriptOp_438: @ 0x0813A590
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r3, .L0813A5DC
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813A5E0
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r5, [r0]
	mov ip, r5
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
	ldrh r7, [r0]
	lsls r7, r7, #0x10
	orrs r7, r4
	cmp r5, #1
	bne .L0813A5E4
	bl sub_081354B0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L0813A5D8
	b .L0813A828
.L0813A5D8:
	b .L0813A824
	.byte 0x00, 0x00
.L0813A5DC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813A5E0: .4byte 0x03006950 @ IWRAM+0x6950
.L0813A5E4:
	cmp r5, #2
	bne .L0813A5F8
	bl sub_08135370
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L0813A5F6
	b .L0813A828
.L0813A5F6:
	b .L0813A824
.L0813A5F8:
	cmp r5, #3
	bne .L0813A60C
	bl sub_08135420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L0813A60A
	b .L0813A828
.L0813A60A:
	b .L0813A824
.L0813A60C:
	cmp r5, #4
	bne .L0813A620
	bl sub_08135540
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L0813A61E
	b .L0813A828
.L0813A61E:
	b .L0813A824
.L0813A620:
	cmp r5, #5
	bne .L0813A634
	bl sub_0813560C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L0813A632
	b .L0813A828
.L0813A632:
	b .L0813A824
.L0813A634:
	cmp r5, #6
	beq .L0813A63A
	b .L0813A758
.L0813A63A:
	movs r0, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L0813A696
	movs r0, #0
	movs r1, #0x9d
	bl sub_08130364
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	movs r1, #0x9e
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	movs r1, #0xa5
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	movs r1, #0xa0
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	movs r1, #0xa1
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	movs r1, #0xa2
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0813A696:
	movs r0, #1
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L0813A6F4
	movs r0, #1
	movs r1, #0x9d
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #1
	movs r1, #0x9e
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #1
	movs r1, #0xa5
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #1
	movs r1, #0xa0
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #1
	movs r1, #0xa1
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #1
	movs r1, #0xa2
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0813A6F4:
	movs r0, #2
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L0813A752
	movs r0, #2
	movs r1, #0x9d
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #2
	movs r1, #0x9e
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #2
	movs r1, #0xa5
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #2
	movs r1, #0xa0
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #2
	movs r1, #0xa1
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #2
	movs r1, #0xa2
	bl sub_08130364
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0813A752:
	cmp r6, #0
	beq .L0813A828
	b .L0813A824
.L0813A758:
	cmp r5, #7
	bne .L0813A7A4
	movs r0, #0
	bl Combatant_IsAlive
	cmp r0, #1
	bne .L0813A76C
	ldr r0, .L0813A7A0
	strh r6, [r0]
	movs r6, #1
.L0813A76C:
	movs r0, #1
	bl Combatant_IsAlive
	adds r1, r0, #0
	cmp r1, #1
	bne .L0813A782
	ldr r0, .L0813A7A0
	strh r1, [r0]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0813A782:
	movs r0, #2
	bl Combatant_IsAlive
	cmp r0, #1
	bne .L0813A798
	ldr r1, .L0813A7A0
	movs r0, #2
	strh r0, [r1]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0813A798:
	cmp r6, #1
	bhi .L0813A828
	b .L0813A824
	.byte 0x00, 0x00
.L0813A7A0: .4byte 0x03006898 @ IWRAM+0x6898
.L0813A7A4:
	cmp r5, #8
	bne .L0813A7E8
	ldr r4, .L0813A7D8
	ldrh r0, [r4]
	bl sub_080C32FC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0813A824
	ldrh r0, [r4]
	bl sub_080C3328
	ldr r2, .L0813A7DC
	ldr r0, .L0813A7E0
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, .L0813A7E4
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	bl sub_080C33AC
	b .L0813A828
.L0813A7D8: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813A7DC: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0813A7E0: .4byte 0x0300696C @ IWRAM+0x696C
.L0813A7E4: .4byte 0x03006940 @ IWRAM+0x6940
.L0813A7E8:
	mov r0, ip
	cmp r0, #9
	bne .L0813A828
	movs r0, #0
	bl Combatant_IsAlive
	movs r0, #1
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L0813A800
	movs r6, #1
.L0813A800:
	movs r0, #2
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L0813A80C
	movs r6, #2
.L0813A80C:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L0813A830
	ldrh r1, [r1]
	bl sub_08130364
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813A828
	movs r0, #0x68
	bl sub_080C51D4
.L0813A824:
	ldr r0, .L0813A834
	str r7, [r0]
.L0813A828:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813A830: .4byte 0x030065E0 @ IWRAM+0x65E0
.L0813A834: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOpAlt_438
ScriptOpAlt_438: @ 0x0813A838
	ldr r1, .L0813A844
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A844: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_439
ScriptOp_439: @ 0x0813A848
	push {r4, lr}
	ldr r1, .L0813A874
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	ldr r0, .L0813A878
	ldrh r1, [r0]
	movs r4, #1
	ldrh r0, [r0, #2]
	bl sub_080B4420
	ldr r1, .L0813A87C
	str r0, [r1]
	ldr r0, .L0813A880
	strh r4, [r0]
	ldr r1, .L0813A884
	movs r0, #0x34
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813A874: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813A878: .4byte gUnknown_0879041E
.L0813A87C: .4byte 0x03006964 @ IWRAM+0x6964
.L0813A880: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L0813A884: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start ScriptOpAlt_439
ScriptOpAlt_439: @ 0x0813A888
	ldr r1, .L0813A894
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A894: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_43A
ScriptOp_43A: @ 0x0813A898
	ldr r1, .L0813A8A4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A8A4: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOpAlt_43A
ScriptOpAlt_43A: @ 0x0813A8A8
	ldr r1, .L0813A8B4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A8B4: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_43B
ScriptOp_43B: @ 0x0813A8B8
	push {lr}
	ldr r1, .L0813A8DC
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #1
	movs r1, #1
	bl SceneEffect_Start
	ldr r1, .L0813A8E0
	movs r0, #0x4a
	strh r0, [r1]
	ldr r1, .L0813A8E4
	movs r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813A8DC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813A8E0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813A8E4: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOpAlt_43B
ScriptOpAlt_43B: @ 0x0813A8E8
	ldr r1, .L0813A8F4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A8F4: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_43C
ScriptOp_43C: @ 0x0813A8F8
	ldr r1, .L0813A904
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A904: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOpAlt_43C
ScriptOpAlt_43C: @ 0x0813A908
	ldr r1, .L0813A914
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A914: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_43D
ScriptOp_43D: @ 0x0813A918
	push {r4, r5, r6, r7, lr}
	ldr r3, .L0813A94C
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813A950
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
	ldr r0, .L0813A954
	ldrh r7, [r0]
	bl Stock_GetCapacity
	adds r6, r0, #0
	movs r4, #4
	b .L0813A972
.L0813A94C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813A950: .4byte 0x03006950 @ IWRAM+0x6950
.L0813A954: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L0813A958:
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813A970
	adds r0, r4, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	beq .L0813A97C
.L0813A970:
	adds r4, #1
.L0813A972:
	adds r0, r6, #4
	cmp r4, r0
	blo .L0813A958
	ldr r0, .L0813A984
	str r5, [r0]
.L0813A97C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813A984: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOpAlt_43D
ScriptOpAlt_43D: @ 0x0813A988
	ldr r1, .L0813A994
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A994: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_43E
ScriptOp_43E: @ 0x0813A998
	push {r4, r5, r6, r7, lr}
	ldr r3, .L0813A9C8
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813A9CC
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r4, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r2
	ldrh r6, [r1]
	lsls r6, r6, #0x10
	orrs r6, r4
	bl Stock_GetCapacity
	adds r7, r0, #0
	movs r5, #4
	b .L0813AA12
.L0813A9C8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813A9CC: .4byte 0x03006950 @ IWRAM+0x6950
.L0813A9D0:
	adds r0, r5, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813AA10
	adds r0, r5, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, #0
	beq .L0813AA10
	cmp r4, #0xde
	beq .L0813AA10
	movs r2, #0xa0
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	bne .L0813AA10
	cmp r4, #0x8b
	bne .L0813AA1C
	movs r0, #0x23
	bl Flag_Test
	cmp r0, #0
	bne .L0813AA1C
.L0813AA10:
	adds r5, #1
.L0813AA12:
	adds r0, r7, #4
	cmp r5, r0
	blo .L0813A9D0
	ldr r0, .L0813AA24
	str r6, [r0]
.L0813AA1C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813AA24: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOpAlt_43E
ScriptOpAlt_43E: @ 0x0813AA28
	ldr r1, .L0813AA34
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813AA34: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_43F
ScriptOp_43F: @ 0x0813AA38
	push {r4, r5, lr}
	ldr r3, .L0813AAF0
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813AAF4
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
	ldr r5, .L0813AAF8
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
	str r0, [r5, #0xc]
	bl MsgWindow_SaveGlyphs
	ldr r1, .L0813AAFC
	movs r0, #3
	strh r0, [r1]
	ldr r0, .L0813AB00
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813AB04
	strh r1, [r0]
	movs r0, #3
	bl sub_0812F2B4
	ldr r1, .L0813AB08
	movs r0, #1
	strh r0, [r1]
	ldr r0, .L0813AB0C
	ldr r1, .L0813AB10
	bl Task_Create
	ldr r1, .L0813AB14
	movs r0, #0x18
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
.L0813AAF0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813AAF4: .4byte 0x03006950 @ IWRAM+0x6950
.L0813AAF8: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813AAFC: .4byte 0x03006844 @ IWRAM+0x6844
.L0813AB00: .4byte 0x03006940 @ IWRAM+0x6940
.L0813AB04: .4byte 0x0300696C @ IWRAM+0x696C
.L0813AB08: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L0813AB0C: .4byte gUnknown_0878FC80
.L0813AB10: .4byte 0x0000FFFF
.L0813AB14: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start ScriptOpAlt_43F
ScriptOpAlt_43F: @ 0x0813AB18
	ldr r1, .L0813AB24
	ldrh r0, [r1]
	adds r0, #8
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813AB24: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_440
ScriptOp_440: @ 0x0813AB28
	push {r4, r5, lr}
	ldr r2, .L0813AB64
	ldrh r0, [r2]
	adds r0, #1
	ldr r1, .L0813AB68
	ldr r3, [r1]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r3
	ldrh r4, [r0]
	adds r0, r1, #1
	strh r0, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r3
	ldrh r0, [r1]
	lsls r5, r0, #0x10
	orrs r5, r4
	movs r0, #0x35
	bl sub_080F4360
	cmp r0, #0
	bne .L0813AB5E
	ldr r0, .L0813AB6C
	str r5, [r0]
.L0813AB5E:
	pop {r4, r5}
	pop {r0}
	bx r0
.L0813AB64: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813AB68: .4byte 0x03006950 @ IWRAM+0x6950
.L0813AB6C: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOpAlt_440
ScriptOpAlt_440: @ 0x0813AB70
	ldr r1, .L0813AB7C
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813AB7C: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_441
ScriptOp_441: @ 0x0813AB80
	push {r4, r5, r6, r7, lr}
	ldr r3, .L0813AC50
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813AC54
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
	ldr r5, .L0813AC58
	str r0, [r5, #0x38]
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
	str r0, [r5, #0x3c]
	ldr r1, .L0813AC5C
	movs r0, #1
	strh r0, [r1]
	bl MsgWindow_SaveGlyphs
	movs r3, #0
	movs r2, #0
	ldr r4, .L0813AC60
	movs r5, #0xff
.L0813ABDA:
	lsls r0, r2, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0xff
	beq .L0813ABF2
	lsls r0, r3, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r3, r0, #0x10
.L0813ABF2:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #4
	bls .L0813ABDA
	ldr r1, .L0813AC64
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	subs r0, #1
	strh r0, [r1]
	movs r2, #0
	ldr r5, .L0813AC68
	ldr r6, .L0813AC6C
	ldr r7, .L0813AC70
	ldr r4, .L0813AC74
	ldr r3, .L0813AC60
.L0813AC12:
	lsls r0, r2, #1
	adds r1, r0, r4
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #4
	bls .L0813AC12
	movs r0, #0
	strh r0, [r5]
	strh r0, [r6]
	movs r0, #1
	strh r0, [r7]
	movs r4, #1
	movs r0, #1
	bl sub_0812F2B4
	ldr r0, .L0813AC78
	strh r4, [r0]
	ldr r0, .L0813AC7C
	ldr r1, .L0813AC80
	bl Task_Create
	ldr r1, .L0813AC84
	movs r0, #0xd
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0813AC50: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813AC54: .4byte 0x03006950 @ IWRAM+0x6950
.L0813AC58: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813AC5C: .4byte 0x030069CC @ IWRAM+0x69CC
.L0813AC60: .4byte 0x03006990 @ IWRAM+0x6990
.L0813AC64: .4byte 0x03006604 @ IWRAM+0x6604
.L0813AC68: .4byte 0x03006940 @ IWRAM+0x6940
.L0813AC6C: .4byte 0x0300696C @ IWRAM+0x696C
.L0813AC70: .4byte 0x03006844 @ IWRAM+0x6844
.L0813AC74: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0813AC78: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L0813AC7C: .4byte gUnknown_0878FC80
.L0813AC80: .4byte 0x0000FFFF
.L0813AC84: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start ScriptOpAlt_441
ScriptOpAlt_441: @ 0x0813AC88
	ldr r1, .L0813AC94
	ldrh r0, [r1]
	adds r0, #4
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813AC94: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start sub_0813AC98
sub_0813AC98: @ 0x0813AC98
.L0813AC98:
	push {r4, lr}
	bl Moon_GetPhase
	movs r4, #0xff
	ands r4, r0
	lsrs r4, r4, #4
	ldr r0, .L0813ACC8
	ldrh r0, [r0]
	movs r1, #0xc
	bl Demon_GetField
	movs r1, #0xf
	ands r1, r0
	lsrs r1, r1, #3
	adds r4, r4, r1
	ldr r0, .L0813ACCC
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #0x12
	bhi .L0813ACD4
	cmp r0, #0xd
	bls .L0813ACD0
	movs r0, #0
	b .L0813ACD6
.L0813ACC8: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813ACCC: .4byte gUnknown_08790CF0
.L0813ACD0:
	movs r0, #2
	b .L0813ACD6
.L0813ACD4:
	movs r0, #1
.L0813ACD6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start ScriptOp_442
ScriptOp_442: @ 0x0813ACDC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	movs r6, #0
	ldr r3, .L0813AD4C
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813AD50
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r5, [r0]
	mov ip, r5
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
	mov r8, r0
	lsls r0, r0, #0x10
	orrs r0, r4
	mov r8, r0
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
	ldrh r7, [r0]
	lsls r7, r7, #0x10
	orrs r7, r4
	cmp r5, #0
	bne .L0813ADC4
	bl Stock_GetCapacity
	adds r5, r0, #0
	movs r6, #4
	adds r5, #4
	adds r4, r5, #0
	b .L0813AD5A
	.byte 0x00, 0x00
.L0813AD4C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813AD50: .4byte 0x03006950 @ IWRAM+0x6950
.L0813AD54:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0813AD5A:
	cmp r6, r4
	blt .L0813AD60
	b .L0813B118
.L0813AD60:
	adds r0, r6, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813AD54
	adds r0, r6, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L0813ADBC
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0813AD54
	cmp r6, r5
	blt .L0813AD82
	b .L0813B118
.L0813AD82:
	adds r0, r6, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r4
	cmp r0, #0
	beq .L0813AD98
	b .L0813B0D2
.L0813AD98:
	cmp r4, #0
	beq .L0813AD9E
	b .L0813B0BA
.L0813AD9E:
	ldr r0, .L0813ADC0
	lsls r2, r6, #7
	adds r2, r2, r0
	movs r1, #0x1a
	ldrsh r0, [r2, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	lsls r0, r0, #0xf
	lsrs r4, r0, #0x10
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	cmp r4, r0
	bge .L0813ADBA
	b .L0813B118
.L0813ADBA:
	b .L0813B0BA
.L0813ADBC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813ADC0: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813ADC4:
	cmp r5, #1
	bne .L0813ADE8
	ldr r0, .L0813ADE4
	ldrh r0, [r0]
	movs r1, #0xb
	bl Demon_GetField
	movs r4, #0xff
	ands r4, r0
	cmp r4, #0x6f
	bhi .L0813ADDC
	b .L0813B0BA
.L0813ADDC:
	cmp r4, #0x8f
	bhi .L0813ADE2
	b .L0813B118
.L0813ADE2:
	b .L0813B0D2
.L0813ADE4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813ADE8:
	cmp r5, #2
	bne .L0813AE08
	bl sub_0813AC98
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L0813ADFA
	b .L0813B118
.L0813ADFA:
	cmp r4, #1
	bne .L0813AE00
	b .L0813B0BA
.L0813AE00:
	cmp r4, #2
	beq .L0813AE06
	b .L0813B118
.L0813AE06:
	b .L0813B0D2
.L0813AE08:
	cmp r5, #3
	bne .L0813AE38
	movs r0, #0
	bl sub_080C0794
	adds r4, r0, #0
	movs r1, #0xff
	lsls r1, r1, #8
	adds r0, r1, #0
	ands r4, r0
	ldr r0, .L0813AE30
	cmp r4, r0
	bhi .L0813AE24
	b .L0813B0BA
.L0813AE24:
	ldr r0, .L0813AE34
	cmp r4, r0
	bhi .L0813AE2C
	b .L0813B118
.L0813AE2C:
	b .L0813B0D2
	.byte 0x00, 0x00
.L0813AE30: .4byte 0x00006FFF
.L0813AE34: .4byte 0x00008FFF
.L0813AE38:
	subs r0, r5, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0813AEC4
	ldr r0, .L0813AE7C
	mov r1, r8
	str r1, [r0]
	str r7, [r0, #4]
	ldr r1, .L0813AE80
	movs r0, #0xff
	strh r0, [r1]
	cmp r5, #4
	bne .L0813AE90
	movs r0, #0
	bl sub_0813BECC
	ldr r0, .L0813AE84
	ldrh r4, [r0]
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl sub_080D3400
	ldr r1, .L0813AE88
	str r0, [r1]
	ldr r3, .L0813AE8C
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_080D347C
	b .L0813B07A
.L0813AE7C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813AE80: .4byte 0x030068D8 @ IWRAM+0x68D8
.L0813AE84: .4byte gUnknown_0878FDB4
.L0813AE88: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813AE8C: .4byte 0x0000FFFF
.L0813AE90:
	movs r0, #0x10
	bl sub_0813BECC
	bl sub_08130C6C
	movs r0, #4
	movs r1, #0
	movs r2, #0
	bl sub_080D3400
	ldr r1, .L0813AEBC
	str r0, [r1]
	ldr r4, .L0813AEC0
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	ldrh r3, [r4, #6]
	ldrh r4, [r4, #8]
	str r4, [sp]
	bl sub_080D347C
	b .L0813B07A
.L0813AEBC: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813AEC0: .4byte 0x03006980 @ IWRAM+0x6980
.L0813AEC4:
	cmp r5, #6
	bne .L0813AF18
	ldr r0, .L0813AF04
	mov r1, r8
	str r1, [r0]
	str r7, [r0, #4]
	ldr r1, .L0813AF08
	ldr r0, .L0813AF0C
	ldrh r0, [r0]
	strh r0, [r1]
	movs r0, #0xf0
	bl sub_0813BECC
	bl sub_08130C6C
	movs r0, #4
	movs r1, #0
	movs r2, #0
	bl sub_080D3400
	ldr r1, .L0813AF10
	str r0, [r1]
	ldr r4, .L0813AF14
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	ldrh r3, [r4, #6]
	ldrh r4, [r4, #8]
	str r4, [sp]
	bl sub_080D347C
	b .L0813B07A
.L0813AF04: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813AF08: .4byte 0x030068D8 @ IWRAM+0x68D8
.L0813AF0C: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813AF10: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813AF14: .4byte 0x03006980 @ IWRAM+0x6980
.L0813AF18:
	cmp r5, #7
	bne .L0813AF58
	ldr r0, .L0813AF54
	ldrh r0, [r0]
	bl sub_0813E804
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813AF2C
	b .L0813B0D2
.L0813AF2C:
	bl Stock_GetCapacity
	adds r5, r0, #0
	movs r4, #0
	cmp r6, r5
	blt .L0813AF3A
	b .L0813B0BA
.L0813AF3A:
	adds r0, r4, #4
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L0813AF46
	b .L0813B0E0
.L0813AF46:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	blt .L0813AF3A
	b .L0813B0BA
	.byte 0x00, 0x00
.L0813AF54: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L0813AF58:
	cmp r5, #8
	beq .L0813AF5E
	b .L0813B098
.L0813AF5E:
	ldr r0, .L0813AFAC
	mov r1, r8
	str r1, [r0]
	str r7, [r0, #4]
	movs r3, #0
	ldr r5, .L0813AFB0
	ldr r2, .L0813AFB4
	movs r1, #0
.L0813AF6E:
	lsls r0, r3, #1
	adds r0, r0, r2
	strh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0xf
	bls .L0813AF6E
	ldr r4, .L0813AFB4
	adds r0, r5, #0
	adds r1, r4, #0
	bl Combatant_DecodeName
	movs r3, #0xe
	movs r2, #0xc6
	lsls r2, r2, #2
.L0813AF8E:
	lsls r0, r3, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0813AFB8
	adds r0, r3, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	cmp r1, #0
	beq .L0813AFA8
	cmp r1, r2
	bne .L0813AFB8
.L0813AFA8:
	strh r2, [r0]
	b .L0813AFC2
.L0813AFAC: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813AFB0: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813AFB4: .4byte 0x0203DB08 @ EWRAM+0x3DB08
.L0813AFB8:
	subs r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne .L0813AF8E
.L0813AFC2:
	ldr r0, .L0813B000
	ldrh r1, [r0]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0x27
	movs r2, #0
	bl MsgGlyphQueue_PushSubstClamped
	movs r3, #0
	ldr r2, .L0813B004
	movs r1, #0
.L0813AFDA:
	lsls r0, r3, #1
	adds r0, r0, r2
	strh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0xf
	bls .L0813AFDA
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813B00C
	ldr r0, .L0813B008
	ldr r1, .L0813B004
	bl Combatant_DecodeName
	b .L0813B014
	.byte 0x00, 0x00
.L0813B000: .4byte gUnknown_0879038A
.L0813B004: .4byte 0x0203DB08 @ EWRAM+0x3DB08
.L0813B008: .4byte 0x03004740 @ IWRAM+0x4740
.L0813B00C:
	ldr r0, .L0813B040
	ldr r1, .L0813B044
	bl Combatant_DecodeName
.L0813B014:
	movs r3, #0xe
	ldr r4, .L0813B044
	ldr r6, .L0813B048
	adds r5, r4, #0
	movs r2, #0xc6
	lsls r2, r2, #2
.L0813B020:
	lsls r0, r3, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0813B04C
	adds r0, r3, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	cmp r1, #0
	beq .L0813B03A
	cmp r1, r2
	bne .L0813B04C
.L0813B03A:
	strh r2, [r0]
	b .L0813B056
	.byte 0x00, 0x00
.L0813B040: .4byte 0x030047C0 @ IWRAM+0x47C0
.L0813B044: .4byte 0x0203DB08 @ EWRAM+0x3DB08
.L0813B048: .4byte gUnknown_0879038A
.L0813B04C:
	subs r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne .L0813B020
.L0813B056:
	ldrh r1, [r6, #2]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0x27
	movs r2, #0
	bl MsgGlyphQueue_PushSubstClamped
	ldr r1, .L0813B084
	movs r0, #0x48
	strh r0, [r1]
	ldr r1, .L0813B088
	movs r0, #2
	strh r0, [r1]
	ldr r0, .L0813B08C
	ldr r1, .L0813B090
	bl Task_Create
.L0813B07A:
	ldr r1, .L0813B094
	movs r0, #1
	strh r0, [r1]
	b .L0813B118
	.byte 0x00, 0x00
.L0813B084: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813B088: .4byte 0x03006688 @ IWRAM+0x6688
.L0813B08C: .4byte gUnknown_0878FD14
.L0813B090: .4byte 0x0000FFFF
.L0813B094: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L0813B098:
	mov r0, ip
	cmp r0, #9
	bne .L0813B118
	movs r0, #0x3a
	bl sub_08132350
	movs r4, #0x80
	lsls r4, r4, #2
	movs r0, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, #0
	ands r0, r4
	cmp r0, #0
	beq .L0813B0C8
.L0813B0BA:
	ldr r0, .L0813B0C4
	mov r1, r8
	str r1, [r0]
	b .L0813B118
	.byte 0x00, 0x00
.L0813B0C4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813B0C8:
	ldr r0, .L0813B0D8
	ldrh r0, [r0, #0xc]
	ands r0, r6
	cmp r0, #0
	beq .L0813B108
.L0813B0D2:
	ldr r0, .L0813B0DC
	str r7, [r0]
	b .L0813B118
.L0813B0D8: .4byte gUnknown_08790D80
.L0813B0DC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813B0E0:
	ldr r0, .L0813B0FC
	ldrh r0, [r0]
	bl sub_080C33AC
	ldr r0, .L0813B100
	ldrh r0, [r0]
	bl sub_080C33AC
	ldr r0, .L0813B104
	ldrh r0, [r0]
	bl Stock_AddDemon
	b .L0813B118
	.byte 0x00, 0x00
.L0813B0FC: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813B100: .4byte 0x030068D8 @ IWRAM+0x68D8
.L0813B104: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L0813B108:
	ldr r0, .L0813B124
	ldrh r0, [r0, #0xc]
	ands r6, r0
	orrs r6, r4
	movs r0, #0
	adds r1, r6, #0
	bl Combatant_SetStatus
.L0813B118:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0813B124: .4byte gUnknown_08790DA0

	thumb_func_start ScriptOpAlt_442
ScriptOpAlt_442: @ 0x0813B128
	ldr r1, .L0813B134
	ldrh r0, [r1]
	adds r0, #5
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813B134: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_443
ScriptOp_443: @ 0x0813B138
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r3, .L0813B1CC
	ldrh r0, [r3]
	adds r0, #1
	ldr r1, .L0813B1D0
	ldr r4, [r1]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
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
	mov r8, r0
	orrs r0, r5
	mov r8, r0
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
	ldrh r7, [r0]
	lsls r7, r7, #0x10
	orrs r7, r2
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
	ldrh r4, [r0]
	lsls r4, r4, #0x10
	orrs r4, r2
	ldr r6, .L0813B1D4
	ldrh r0, [r6]
	bl sub_0815B9DC
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x22
	bne .L0813B1E0
	ldr r4, .L0813B1D8
	ldrh r0, [r6]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	str r1, [r4]
	ldr r0, .L0813B1DC
	mov r1, r8
	str r1, [r0]
	b .L0813B244
	.byte 0x00, 0x00
.L0813B1CC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813B1D0: .4byte 0x03006950 @ IWRAM+0x6950
.L0813B1D4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B1D8: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813B1DC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813B1E0:
	bl Random_Byte
	adds r5, r0, #0
	movs r0, #7
	ands r5, r0
	cmp r5, #0
	bne .L0813B240
	ldr r2, .L0813B220
	mov r8, r2
	ldrh r0, [r6]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	mov r3, r8
	str r1, [r3]
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	bl Battle_GetCombatant
	ldr r1, [r0, #8]
	mov r2, r8
	ldr r0, [r2]
	cmp r1, r0
	bhi .L0813B224
	adds r0, r4, #0
	bl Battle_GetCombatant
	str r5, [r0, #8]
	b .L0813B234
.L0813B220: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813B224:
	adds r0, r4, #0
	bl Battle_GetCombatant
	ldr r1, [r0, #8]
	mov r3, r8
	ldr r2, [r3]
	subs r1, r1, r2
	str r1, [r0, #8]
.L0813B234:
	ldr r0, .L0813B23C
	str r7, [r0]
	b .L0813B244
	.byte 0x00, 0x00
.L0813B23C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813B240:
	ldr r0, .L0813B250
	str r4, [r0]
.L0813B244:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813B250: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOpAlt_443
ScriptOpAlt_443: @ 0x0813B254
	ldr r1, .L0813B260
	ldrh r0, [r1]
	adds r0, #7
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813B260: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start sub_0813B264
sub_0813B264: @ 0x0813B264
.L0813B264:
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813B268
sub_0813B268: @ 0x0813B268
.L0813B268:
	push {r4, r5, lr}
	ldr r5, .L0813B2B0
	ldr r0, .L0813B2B4
	adds r4, r0, #0
	ldrh r1, [r5]
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_0813756C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x62
	bhi .L0813B2B8
	ldrh r1, [r5]
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl sub_08137518
	ldrh r5, [r5]
	adds r0, r4, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_0813756C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bne .L0813B2AA
	bl sub_0813B264
.L0813B2AA:
	movs r0, #1
	b .L0813B2BA
	.byte 0x00, 0x00
.L0813B2B0: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813B2B4: .4byte 0xFFFFFEE0
.L0813B2B8:
	movs r0, #0
.L0813B2BA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start ScriptOp_444
ScriptOp_444: @ 0x0813B2C0
	push {r4, r5, lr}
	ldr r3, .L0813B308
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813B30C
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
	ldr r1, .L0813B310
	ldr r2, .L0813B314
	adds r0, r2, #0
	strh r0, [r1]
	bl sub_0813B268
	cmp r0, #0
	beq .L0813B300
	ldr r0, .L0813B318
	ldr r1, .L0813B31C
	str r1, [r0]
	ldr r0, .L0813B320
	str r5, [r0]
.L0813B300:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813B308: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813B30C: .4byte 0x03006950 @ IWRAM+0x6950
.L0813B310: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813B314: .4byte 0x00000127
.L0813B318: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813B31C: .4byte gUnknown_080A0BC6
.L0813B320: .4byte 0x03006840 @ IWRAM+0x6840

	thumb_func_start ScriptOpAlt_444
ScriptOpAlt_444: @ 0x0813B324
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813B328
sub_0813B328: @ 0x0813B328
.L0813B328:
	ldr r1, .L0813B344
	ldr r2, .L0813B348
	str r2, [r1]
	lsls r0, r0, #0x11
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r1, [r0]
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	orrs r0, r1
	ldr r1, .L0813B34C
	str r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813B344: .4byte 0x03006950 @ IWRAM+0x6950
.L0813B348: .4byte gUnknown_08032BBC
.L0813B34C: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start sub_0813B350
sub_0813B350: @ 0x0813B350
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	mov r5, r8
	movs r6, #0xf
.L0813B364:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L0813B3EC
	lsrs r5, r5, #1
	adds r0, r7, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq .L0813B386
	movs r0, #0
	b .L0813B3DE
.L0813B386:
	ldr r0, .L0813B398
	lsls r4, r6, #1
	adds r0, r4, r0
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq .L0813B39C
	movs r0, #1
	b .L0813B3DE
.L0813B398: .4byte gUnknown_08790D80
.L0813B39C:
	ldr r0, .L0813B3C4
	adds r0, r4, r0
	ldrh r0, [r0]
	ands r1, r0
	mov r0, r8
	orrs r1, r0
	adds r0, r7, #0
	bl Combatant_SetStatus
	cmp r6, #0
	bne .L0813B3C8
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r7, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	strh r6, [r0, #0x18]
	b .L0813B3EE
.L0813B3C4: .4byte gUnknown_08790DA0
.L0813B3C8:
	cmp r6, #0xe
	bgt .L0813B3EE
	cmp r7, #0xf
	bls .L0813B3D8
	ldr r0, .L0813B3D4
	b .L0813B3DA
.L0813B3D4: .4byte gUnknown_08790DC0
.L0813B3D8:
	ldr r0, .L0813B3E8
.L0813B3DA:
	adds r0, r4, r0
	ldrh r0, [r0]
.L0813B3DE:
	cmp r6, #1
	beq .L0813B3EE
	bl sub_0813B328
	b .L0813B3EE
.L0813B3E8: .4byte gUnknown_08790DDE
.L0813B3EC:
	lsrs r5, r5, #1
.L0813B3EE:
	subs r6, #1
	cmp r6, #0
	bge .L0813B364
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0813B400
sub_0813B400: @ 0x0813B400
.L0813B400:
	push {r4, lr}
	ldr r0, .L0813B430
	ldr r2, .L0813B434
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	adds r0, r4, #0
	bl sub_0813756C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0813B42A
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r4, #0
	bl sub_08137518
	bl sub_0813B264
.L0813B42A:
	pop {r4}
	pop {r0}
	bx r0
.L0813B430: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813B434: .4byte 0xFFFFFEE0

	thumb_func_start sub_0813B438
sub_0813B438: @ 0x0813B438
.L0813B438:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r2, r0, #0
	adds r2, #0x28
	ldr r0, .L0813B464
	ldrh r0, [r0]
	subs r0, #0x9d
	cmp r0, #8
	bhi .L0813B512
	lsls r0, r0, #2
	ldr r1, .L0813B468
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L0813B464: .4byte 0x030065E0 @ IWRAM+0x65E0
.L0813B468: .4byte gUnknown_0813B46C
	.global gUnknown_0813B46C
gUnknown_0813B46C:
.L0813B46C: @ jump table
	.4byte .L0813B490
	.4byte .L0813B4A6
	.4byte .L0813B4BC
	.4byte .L0813B4D2
	.4byte .L0813B4E8
	.4byte .L0813B4FE
	.4byte .L0813B490
	.4byte .L0813B4A6
	.4byte .L0813B4BC
.L0813B490:
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	lsrs r0, r2, #0x1f
	adds r2, r2, r0
	asrs r2, r2, #1
	adds r0, r4, #0
	movs r1, #0
	bl sub_08136270
	b .L0813B512
.L0813B4A6:
	ldrb r2, [r2, #1]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	lsrs r0, r2, #0x1f
	adds r2, r2, r0
	asrs r2, r2, #1
	adds r0, r4, #0
	movs r1, #1
	bl sub_08136270
	b .L0813B512
.L0813B4BC:
	ldrb r2, [r2, #2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	lsrs r0, r2, #0x1f
	adds r2, r2, r0
	asrs r2, r2, #1
	adds r0, r4, #0
	movs r1, #2
	bl sub_08136270
	b .L0813B512
.L0813B4D2:
	ldrb r2, [r2, #3]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	lsrs r0, r2, #0x1f
	adds r2, r2, r0
	asrs r2, r2, #1
	adds r0, r4, #0
	movs r1, #3
	bl sub_08136270
	b .L0813B512
.L0813B4E8:
	ldrb r2, [r2, #4]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	lsrs r0, r2, #0x1f
	adds r2, r2, r0
	asrs r2, r2, #1
	adds r0, r4, #0
	movs r1, #4
	bl sub_08136270
	b .L0813B512
.L0813B4FE:
	ldrb r2, [r2, #5]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	lsrs r0, r2, #0x1f
	adds r2, r2, r0
	asrs r2, r2, #1
	adds r0, r4, #0
	movs r1, #5
	bl sub_08136270
.L0813B512:
	adds r0, r4, #0
	bl Combatant_RecalcStats
	bl sub_080CDC34
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_445
ScriptOp_445: @ 0x0813B524
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r2, .L0813B5AC
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L0813B5B0
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #3
	bne .L0813B5CA
	bl Stock_GetCapacity
	adds r7, r0, #0
	movs r6, #4
	adds r0, r7, #4
	cmp r6, r0
	blt .L0813B550
	b .L0813BC20
.L0813B550:
	adds r0, r6, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813B5BC
	adds r0, r6, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L0813B5B4
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0813B5BC
	adds r0, r6, #0
	bl Combatant_GetStatus
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0813B580
	b .L0813BBEA
.L0813B580:
	ldr r1, .L0813B5B8
	lsls r0, r6, #7
	adds r4, r0, r1
	movs r3, #0x1a
	ldrsh r0, [r4, r3]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	movs r2, #0x18
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt .L0813B59A
	b .L0813BC20
.L0813B59A:
	adds r0, r6, #0
	movs r1, #1
	bl Combatant_ClearStatus
	ldrh r0, [r4, #0x1a]
	strh r0, [r4, #0x18]
.L0813B5A6:
	bl sub_080C84A0
	b .L0813BC20
.L0813B5AC: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813B5B0: .4byte 0x03006950 @ IWRAM+0x6950
.L0813B5B4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B5B8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B5BC:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r7, #4
	cmp r6, r0
	blt .L0813B550
	b .L0813BC20
.L0813B5CA:
	cmp r1, #4
	bne .L0813B5E8
	movs r0, #0
	movs r1, #0
	bl sub_0812EE8C
	ldr r1, .L0813B5E0
	str r0, [r1]
	ldr r1, .L0813B5E4
	movs r0, #0x4f
	b .L0813BA0E
.L0813B5E0: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813B5E4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813B5E8:
	cmp r1, #5
	beq .L0813B5A6
	cmp r1, #6
	bne .L0813B600
	movs r0, #0
	movs r1, #1
	bl Combatant_ClearStatus
	movs r0, #0
	bl Combatant_RestoreHp
	b .L0813B5A6
.L0813B600:
	cmp r1, #7
	bne .L0813B620
	bl sub_080EF954
	adds r2, r0, #0
	bl sub_080EF930
	ldr r0, .L0813B618
	ldr r1, .L0813B61C
	ldrb r1, [r1]
	strb r1, [r0]
	b .L0813BC20
.L0813B618: .4byte 0x030068B4 @ IWRAM+0x68B4
.L0813B61C: .4byte 0x030069E8 @ IWRAM+0x69E8
.L0813B620:
	cmp r1, #8
	bne .L0813B658
	ldr r0, .L0813B650
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	ldr r2, .L0813B654
	ldrh r0, [r2, #0x18]
	subs r0, r0, r1
	strh r0, [r2, #0x18]
	movs r3, #0x18
	ldrsh r0, [r2, r3]
	subs r0, #1
	lsls r0, r0, #0x10
	cmp r0, #0
	ble .L0813B648
	b .L0813BC20
.L0813B648:
	movs r0, #1
	strh r0, [r2, #0x18]
	b .L0813BC20
	.byte 0x00, 0x00
.L0813B650: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B654: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B658:
	cmp r1, #9
	bne .L0813B694
	bl Random_Byte
	movs r1, #7
	ands r0, r1
	adds r5, r0, #1
	ldr r0, .L0813B68C
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	adds r0, r5, r0
	lsls r0, r0, #0x10
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r1, r0
	lsrs r5, r1, #0x10
	ldr r1, .L0813B690
	ldrh r0, [r1, #0x18]
	subs r0, r0, r5
	strh r0, [r1, #0x18]
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	b .L0813B6B4
	.byte 0x00, 0x00
.L0813B68C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B690: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B694:
	cmp r1, #0xa
	bne .L0813B6CC
	ldr r0, .L0813B6C4
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	lsls r5, r1, #1
	ldr r1, .L0813B6C8
	ldrh r0, [r1, #0x18]
	subs r0, r0, r5
	strh r0, [r1, #0x18]
	movs r3, #0x18
	ldrsh r0, [r1, r3]
.L0813B6B4:
	subs r0, #1
	lsls r0, r0, #0x10
	cmp r0, #0
	ble .L0813B6BE
	b .L0813BC20
.L0813B6BE:
	movs r0, #1
	strh r0, [r1, #0x18]
	b .L0813BC20
.L0813B6C4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B6C8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B6CC:
	cmp r1, #0xb
	bne .L0813B724
	ldr r0, .L0813B6F0
	ldrh r0, [r0]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	lsrs r1, r1, #2
	adds r5, r1, #1
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813B6F4
	movs r6, #1
	b .L0813B702
.L0813B6F0: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B6F4:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L0813B700
	b .L0813BC20
.L0813B700:
	movs r6, #2
.L0813B702:
	ldr r1, .L0813B720
	lsls r0, r6, #7
	adds r1, r0, r1
	ldrh r0, [r1, #0x1c]
	subs r0, r0, r5
	strh r0, [r1, #0x1c]
	movs r2, #0x1c
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble .L0813B718
	b .L0813B5A6
.L0813B718:
	movs r0, #0
	strh r0, [r1, #0x1c]
	b .L0813B5A6
	.byte 0x00, 0x00
.L0813B720: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B724:
	cmp r1, #0xc
	bne .L0813B740
	ldr r2, .L0813B738
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L0813B73C
	movs r0, #0xf7
	b .L0813B752
.L0813B738: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B73C:
	movs r0, #8
	b .L0813B75E
.L0813B740:
	cmp r1, #0xd
	bne .L0813B764
	ldr r2, .L0813B758
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L0813B75C
	movs r0, #0xef
.L0813B752:
	ands r0, r1
	strb r0, [r2]
	b .L0813BC20
.L0813B758: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B75C:
	movs r0, #0x10
.L0813B75E:
	orrs r0, r1
	strb r0, [r2]
	b .L0813BC20
.L0813B764:
	cmp r1, #0xe
	bne .L0813B774
	ldr r0, .L0813B770
	ldrb r1, [r0]
	movs r2, #1
	b .L0813B78E
.L0813B770: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B774:
	cmp r1, #0xf
	bne .L0813B784
	ldr r0, .L0813B780
	ldrb r1, [r0]
	movs r2, #4
	b .L0813B78E
.L0813B780: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B784:
	cmp r1, #0x10
	bne .L0813B798
	ldr r0, .L0813B794
	ldrb r1, [r0]
	movs r2, #2
.L0813B78E:
	orrs r1, r2
	strb r1, [r0]
	b .L0813BC20
.L0813B794: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B798:
	cmp r1, #0x11
	bne .L0813B7EA
	bl Stock_GetCapacity
	adds r7, r0, #0
	movs r6, #0
	adds r0, r7, #4
	cmp r6, r0
	blt .L0813B7AC
	b .L0813BC20
.L0813B7AC:
	adds r0, r6, #0
	bl Combatant_IsAlive
	cmp r0, #1
	bne .L0813B7DC
	movs r3, #0x80
	lsls r3, r3, #8
	adds r4, r6, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	adds r5, r0, #0
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r2, #0x18
	ldrsh r1, [r5, r2]
	movs r3, #0x1a
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge .L0813B7DC
	b .L0813BC04
.L0813B7DC:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r7, #4
	cmp r6, r0
	blt .L0813B7AC
	b .L0813BC20
.L0813B7EA:
	cmp r1, #0x12
	bne .L0813B844
	ldr r4, .L0813B838
	ldr r0, .L0813B83C
	ldrh r0, [r0]
	movs r1, #5
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	str r1, [r4]
	movs r0, #0x41
	bl sub_08132350
	movs r1, #0
	ldr r0, .L0813B840
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r2, r0, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq .L0813B82E
.L0813B818:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #4
	bhi .L0813B82E
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0813B818
.L0813B82E:
	adds r0, r1, #0
	movs r1, #1
	bl sub_080C8890
	b .L0813BA10
.L0813B838: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813B83C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B840: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813B844:
	cmp r1, #0x13
	bne .L0813B868
	movs r0, #0x16
	bl sub_08132350
	movs r0, #0x1f
	movs r1, #1
	bl sub_080B8AE0
	ldr r1, .L0813B860
	str r0, [r1]
	ldr r1, .L0813B864
	movs r0, #0x4c
	b .L0813BA0E
.L0813B860: .4byte 0x03006964 @ IWRAM+0x6964
.L0813B864: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813B868:
	cmp r1, #0x14
	bne .L0813B874
	movs r0, #0x39
	bl sub_08132350
	b .L0813BC20
.L0813B874:
	cmp r1, #0x15
	bne .L0813B8E4
	movs r0, #0x40
	bl sub_08132350
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r2, #0x18
	ldrsh r1, [r0, r2]
	ldr r5, .L0813B8E0
	ldr r0, [r5]
	cmp r1, r0
	bhs .L0813B8A2
	adds r0, r4, #0
	bl Battle_GetCombatant
	ldr r2, [r5]
	ldrh r1, [r0, #0x18]
	subs r1, r1, r2
	strh r1, [r0, #0x18]
.L0813B8A2:
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r3, #0x18
	ldrsh r0, [r0, r3]
	ands r0, r4
	cmp r0, #0
	bne .L0813B8C2
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble .L0813B8C2
	b .L0813BC20
.L0813B8C2:
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0
	strh r1, [r0, #0x18]
	movs r0, #0
	movs r1, #1
	bl Combatant_ClearStatus
	movs r0, #0
	adds r1, r4, #0
	bl sub_080C08E8
	b .L0813B980
	.byte 0x00, 0x00
.L0813B8E0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813B8E4:
	cmp r1, #0x17
	bne .L0813B92C
	bl sub_0813B400
	bl sub_0813BE70
	ldr r2, .L0813B918
	ldrb r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r0, .L0813B91C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813B920
	strh r1, [r0]
	ldr r0, .L0813B924
	strh r1, [r0]
	ldr r0, .L0813B928
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	b .L0813BC20
	.byte 0x00, 0x00
.L0813B918: .4byte 0x0300684C @ IWRAM+0x684C
.L0813B91C: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813B920: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813B924: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813B928: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0813B92C:
	cmp r1, #0x18
	bne .L0813B97C
	ldr r0, .L0813B96C
	ldrh r0, [r0]
	subs r0, #0x9d
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_0812F188
	rsbs r0, r0, #0
	bl sub_080C30AC
	bl Moon_GetPhase
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x80
	beq .L0813B956
	movs r0, #0xcf
	bl Flag_Set
.L0813B956:
	ldr r0, .L0813B970
	ldrh r4, [r0]
	adds r0, r4, #0
	bl sub_0813B438
	cmp r4, #0
	bne .L0813B974
	movs r0, #0xe2
	bl Flag_Set
	b .L0813BC20
.L0813B96C: .4byte 0x030065E0 @ IWRAM+0x65E0
.L0813B970: .4byte 0x03006898 @ IWRAM+0x6898
.L0813B974:
	movs r0, #0xe3
	bl Flag_Set
	b .L0813BC20
.L0813B97C:
	cmp r1, #0x19
	bne .L0813B992
.L0813B980:
	bl sub_08138CE8
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813B98C
	b .L0813BC20
.L0813B98C:
	movs r0, #1
	strh r0, [r6, #0x1c]
	b .L0813BC20
.L0813B992:
	cmp r1, #0x1a
	bne .L0813B9D4
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r2, #0x18
	ldrsh r1, [r0, r2]
	ldr r5, .L0813B9C0
	ldr r0, [r5]
	cmp r1, r0
	bhi .L0813B9C4
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0
	strh r1, [r0, #0x18]
	movs r0, #0
	adds r1, r4, #0
	bl sub_080C08E8
	b .L0813B5A6
.L0813B9C0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813B9C4:
	adds r0, r4, #0
	bl Battle_GetCombatant
	ldr r2, [r5]
	ldrh r1, [r0, #0x18]
	subs r1, r1, r2
	strh r1, [r0, #0x18]
	b .L0813B5A6
.L0813B9D4:
	cmp r1, #0x1b
	bne .L0813B9EC
	ldr r0, .L0813B9E4
	ldr r1, .L0813B9E8
	ldrh r1, [r1]
	strh r1, [r0]
	b .L0813BC20
	.byte 0x00, 0x00
.L0813B9E4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813B9E8: .4byte 0x0203DB80 @ EWRAM+0x3DB80
.L0813B9EC:
	cmp r1, #0x1c
	bne .L0813B9F8
	movs r0, #1
	bl sub_080D3AA0
	b .L0813BC20
.L0813B9F8:
	cmp r1, #0x1d
	bne .L0813BA00
	movs r0, #0
	b .L0813BA06
.L0813BA00:
	cmp r1, #0x1e
	bne .L0813BA20
	movs r0, #1
.L0813BA06:
	bl sub_080D4560
	ldr r1, .L0813BA18
	movs r0, #0x52
.L0813BA0E:
	strh r0, [r1]
.L0813BA10:
	ldr r1, .L0813BA1C
	movs r0, #1
	strh r0, [r1]
	b .L0813BC20
.L0813BA18: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813BA1C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L0813BA20:
	cmp r1, #0x1f
	bne .L0813BA30
	ldr r1, .L0813BA2C
	movs r0, #0
	strh r0, [r1, #2]
	b .L0813BC20
.L0813BA2C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA30:
	cmp r1, #0x20
	bne .L0813BA40
	ldr r1, .L0813BA3C
	movs r0, #1
	strh r0, [r1, #2]
	b .L0813BC20
.L0813BA3C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA40:
	cmp r1, #0x21
	bne .L0813BA50
	ldr r1, .L0813BA4C
	movs r0, #2
	strh r0, [r1, #2]
	b .L0813BC20
.L0813BA4C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA50:
	cmp r1, #0x22
	bne .L0813BA60
	ldr r1, .L0813BA5C
	movs r0, #0
	strh r0, [r1]
	b .L0813BC20
.L0813BA5C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA60:
	cmp r1, #0x23
	bne .L0813BA70
	ldr r1, .L0813BA6C
	movs r0, #1
	strh r0, [r1]
	b .L0813BC20
.L0813BA6C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA70:
	cmp r1, #0x24
	bne .L0813BA80
	ldr r1, .L0813BA7C
	movs r0, #2
	strh r0, [r1]
	b .L0813BC20
.L0813BA7C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BA80:
	cmp r1, #0x25
	bne .L0813BAA0
	ldr r1, .L0813BA9C
	movs r0, #0
	strh r0, [r1, #4]
	movs r0, #0xff
	strh r0, [r1, #6]
	ldrh r0, [r1]
	cmp r0, #1
	beq .L0813BA96
	b .L0813BC20
.L0813BA96:
	bl sub_080C5B3C
	b .L0813BC20
.L0813BA9C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BAA0:
	cmp r1, #0x26
	bne .L0813BABC
	ldr r0, .L0813BAB4
	ldrh r1, [r0, #4]
	adds r1, #1
	strh r1, [r0, #4]
	ldrh r1, [r0, #4]
	ldr r0, .L0813BAB8
	str r1, [r0]
	b .L0813BC20
.L0813BAB4: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BAB8: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813BABC:
	cmp r1, #0x27
	bne .L0813BAD4
	ldr r0, .L0813BAD0
	ldrh r0, [r0]
	cmp r0, #1
	beq .L0813BACA
	b .L0813BC20
.L0813BACA:
	bl sub_080C5BCC
	b .L0813BC20
.L0813BAD0: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813BAD4:
	cmp r1, #0x28
	beq .L0813BADA
	b .L0813BC20
.L0813BADA:
	movs r0, #0
	bl Combatant_GetLevel
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #6
	bhi .L0813BAEA
	b .L0813BC20
.L0813BAEA:
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0
	adds r1, r4, #0
	bl Combatant_SetLevel
	adds r0, r4, #0
	bl Exp_GetForLevel
	adds r1, r0, #0
	movs r0, #0
	bl sub_080C0F70
	bl Random_Byte
	adds r6, r0, #0
	movs r0, #3
	ands r6, r0
	bl Random_Byte
	movs r4, #1
	ands r0, r4
	adds r6, r6, r0
	bl Random_Byte
	ands r0, r4
	adds r6, r6, r0
	movs r5, #0
.L0813BB24:
	cmp r6, #0
	bne .L0813BB46
	movs r0, #0
	movs r1, #0
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #6
	bgt .L0813BB3A
	movs r6, #1
	b .L0813BBDE
.L0813BB3A:
	subs r2, #1
	movs r0, #0
	movs r1, #0
	bl sub_08136204
	b .L0813BC16
.L0813BB46:
	cmp r6, #1
	bne .L0813BB68
	movs r0, #0
	movs r1, #1
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #5
	bgt .L0813BB5C
	movs r6, #2
	b .L0813BBDE
.L0813BB5C:
	subs r2, #1
	movs r0, #0
	movs r1, #1
	bl sub_08136204
	b .L0813BC16
.L0813BB68:
	cmp r6, #2
	bne .L0813BB8A
	movs r0, #0
	movs r1, #2
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #4
	bgt .L0813BB7E
	movs r6, #3
	b .L0813BBDE
.L0813BB7E:
	subs r2, #1
	movs r0, #0
	movs r1, #2
	bl sub_08136204
	b .L0813BC16
.L0813BB8A:
	cmp r6, #3
	bne .L0813BBAC
	movs r0, #0
	movs r1, #3
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #6
	bgt .L0813BBA0
	movs r6, #4
	b .L0813BBDE
.L0813BBA0:
	subs r2, #1
	movs r0, #0
	movs r1, #3
	bl sub_08136204
	b .L0813BC16
.L0813BBAC:
	cmp r6, #4
	bne .L0813BBCE
	movs r0, #0
	movs r1, #4
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #6
	bgt .L0813BBC2
	movs r6, #5
	b .L0813BBDE
.L0813BBC2:
	subs r2, #1
	movs r0, #0
	movs r1, #4
	bl sub_08136204
	b .L0813BC16
.L0813BBCE:
	movs r0, #0
	movs r1, #5
	bl Combatant_GetBaseStat
	adds r2, r0, #0
	cmp r2, #3
	bgt .L0813BC0C
	movs r6, #0
.L0813BBDE:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #5
	bhi .L0813BC20
	b .L0813BB24
.L0813BBEA:
	adds r0, r6, #0
	movs r1, #1
	bl Combatant_ClearStatus
	ldr r0, .L0813BC00
	lsls r1, r6, #7
	adds r1, r1, r0
	ldrh r0, [r1, #0x1a]
	strh r0, [r1, #0x18]
	b .L0813B5A6
	.byte 0x00, 0x00
.L0813BC00: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0813BC04:
	adds r0, r6, #0
	bl Combatant_RestoreHp
	b .L0813BC20
.L0813BC0C:
	subs r2, #1
	movs r0, #0
	movs r1, #5
	bl sub_08136204
.L0813BC16:
	ldr r1, .L0813BC28
	ldrh r0, [r1, #0x1a]
	strh r0, [r1, #0x18]
	bl sub_080CDC34
.L0813BC20:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813BC28: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start ScriptOpAlt_445
ScriptOpAlt_445: @ 0x0813BC2C
	ldr r1, .L0813BC38
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813BC38: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_446
ScriptOp_446: @ 0x0813BC3C
	push {r4, r5, r6, r7, lr}
	ldr r2, .L0813BC7C
	ldrh r1, [r2]
	adds r0, r1, #1
	strh r0, [r2]
	lsls r1, r1, #0x10
	ldr r0, .L0813BC80
	ldr r0, [r0]
	lsrs r1, r1, #0xf
	adds r1, r1, r0
	ldrh r0, [r1]
	ldrb r4, [r1]
	lsrs r0, r0, #8
	ldr r1, .L0813BC84
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	cmp r4, #0
	bne .L0813BC88
	movs r0, #0
	adds r1, r5, #0
	bl sub_080C08E8
	movs r0, #0x80
	lsls r0, r0, #8
	ands r5, r0
	cmp r5, #0
	beq .L0813BCE8
	bl Battle_GetCombatant
	strh r4, [r0, #0x18]
	b .L0813BCE8
.L0813BC7C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813BC80: .4byte 0x03006950 @ IWRAM+0x6950
.L0813BC84: .4byte gUnknown_08790DFC
.L0813BC88:
	cmp r4, #2
	bne .L0813BCEE
	movs r4, #0x10
	b .L0813BC96
.L0813BC90:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L0813BC96:
	cmp r4, #0x17
	bhi .L0813BCB6
	adds r0, r4, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L0813BC90
	adds r0, r4, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L0813BCD0
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0813BC90
.L0813BCB6:
	movs r7, #0x80
	lsls r7, r7, #8
	adds r0, r5, #0
	ands r0, r7
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq .L0813BCD4
	adds r0, r4, #0
	bl sub_080EF20C
	b .L0813BD3C
	.byte 0x00, 0x00
.L0813BCD0: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813BCD4:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080C08E8
	adds r0, r4, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	strh r6, [r0, #0x18]
.L0813BCE8:
	bl sub_080C84A0
	b .L0813BD3C
.L0813BCEE:
	cmp r4, #3
	bne .L0813BD3C
	movs r4, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r5, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0813BD02:
	adds r0, r4, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L0813BD2E
	adds r0, r4, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L0813BD44
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0813BD2E
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080C08E8
	cmp r6, #0
	beq .L0813BD2E
	bl sub_080C84A0
.L0813BD2E:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x17
	bls .L0813BD02
	bl sub_080C84A0
.L0813BD3C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813BD44: .4byte 0x0203DB7C @ EWRAM+0x3DB7C

	thumb_func_start ScriptOpAlt_446
ScriptOpAlt_446: @ 0x0813BD48
	ldr r1, .L0813BD54
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813BD54: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start sub_0813BD58
sub_0813BD58: @ 0x0813BD58
.L0813BD58:
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L0813BD90
	ldrh r0, [r0]
	mov r2, sp
	adds r2, #1
	mov r1, sp
	bl sub_0815B9B8
	mov r0, sp
	ldrb r4, [r0]
	lsls r0, r4, #0x1a
	lsrs r4, r0, #0x18
	movs r5, #0
.L0813BD74:
	bl Random_Byte
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, .L0813BD94
	adds r1, r4, r5
	adds r1, r1, r2
	ldrb r1, [r1]
	cmp r0, r1
	bls .L0813BD98
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b .L0813BD74
.L0813BD90: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813BD94: .4byte gUnknown_08790E1C
.L0813BD98:
	adds r0, r5, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0813BDA4
sub_0813BDA4: @ 0x0813BDA4
.L0813BDA4:
	push {r4, r5, lr}
	ldr r4, .L0813BDC8
	bl Random_Byte
	movs r5, #0xf
	ands r0, r5
	strh r0, [r4]
	bl Random_Byte
	ands r0, r5
	ldrh r1, [r4]
	adds r0, r0, r1
	adds r0, #8
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813BDC8: .4byte 0x03006690 @ IWRAM+0x6690

	thumb_func_start sub_0813BDCC
sub_0813BDCC: @ 0x0813BDCC
.L0813BDCC:
	push {r4, r5, lr}
	ldr r4, .L0813BDF4
	ldrh r0, [r4]
	movs r1, #0x1a
	bl Demon_GetField
	movs r1, #0xf0
	ands r1, r0
	lsrs r5, r1, #4
	ldrh r0, [r4]
	movs r1, #0
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	lsls r0, r1, #3
	cmp r5, #7
	bhi .L0813BDF8
	muls r0, r5, r0
	b .L0813BE02
.L0813BDF4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813BDF8:
	adds r1, r5, #0
	bl sub_08137B78
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L0813BE02:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_0813BE08
sub_0813BE08: @ 0x0813BE08
.L0813BE08:
	push {lr}
	bl sub_080C3168
	ldr r1, .L0813BE1C
	ldr r1, [r1]
	cmp r0, r1
	bhs .L0813BE20
	movs r0, #1
	b .L0813BE28
	.byte 0x00, 0x00
.L0813BE1C: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813BE20:
	rsbs r0, r1, #0
	bl sub_080C3114
	movs r0, #0
.L0813BE28:
	pop {r1}
	bx r1

	thumb_func_start sub_0813BE2C
sub_0813BE2C: @ 0x0813BE2C
.L0813BE2C:
	push {lr}
	bl sub_080C3100
	ldr r1, .L0813BE40
	ldr r1, [r1]
	cmp r0, r1
	bhs .L0813BE44
	movs r0, #1
	b .L0813BE4C
	.byte 0x00, 0x00
.L0813BE40: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813BE44:
	rsbs r0, r1, #0
	bl sub_080C30AC
	movs r0, #0
.L0813BE4C:
	pop {r1}
	bx r1

	thumb_func_start sub_0813BE50
sub_0813BE50: @ 0x0813BE50
.L0813BE50:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080EF90C
	adds r0, r0, r4
	cmp r0, #0x1f
	ble .L0813BE64
	movs r0, #0x1f
.L0813BE64:
	bl sub_080EF930
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0813BE70
sub_0813BE70: @ 0x0813BE70
.L0813BE70:
	push {lr}
	ldr r0, .L0813BE8C
	ldrh r0, [r0]
	ldr r1, .L0813BE90
	adds r0, r0, r1
	lsls r0, r0, #0x12
	lsrs r0, r0, #0x10
	ldr r1, .L0813BE94
	adds r0, r0, r1
	ldrb r0, [r0]
	bl sub_0813BE50
	pop {r0}
	bx r0
.L0813BE8C: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813BE90: .4byte 0xFFFFFEE0
.L0813BE94: .4byte gUnknown_081A6ED4

	thumb_func_start sub_0813BE98
sub_0813BE98: @ 0x0813BE98
.L0813BE98:
	push {lr}
	ldr r0, .L0813BEB4
	ldrb r1, [r0]
	adds r1, #2
	movs r0, #0x28
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_0813BE50
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813BEB4: .4byte 0x03006690 @ IWRAM+0x6690

	thumb_func_start sub_0813BEB8
sub_0813BEB8: @ 0x0813BEB8
.L0813BEB8:
	push {lr}
	bl Random_Byte
	movs r1, #3
	ands r0, r1
	adds r0, #1
	bl sub_0813BE50
	pop {r0}
	bx r0

	thumb_func_start sub_0813BECC
sub_0813BECC: @ 0x0813BECC
.L0813BECC:
	push {r4, r5, r6, r7, lr}
	ldr r1, .L0813BF38
	strh r0, [r1]
	bl MsgWindow_SaveGlyphs
	movs r2, #0
	ldr r4, .L0813BF3C
	ldr r0, .L0813BF40
	adds r3, r0, #0
.L0813BEDE:
	lsls r0, r2, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	orrs r1, r3
	strh r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x13
	bls .L0813BEDE
	movs r1, #0
	movs r2, #0x90
	lsls r2, r2, #1
	ldr r5, .L0813BF44
	ldr r6, .L0813BF48
	ldr r7, .L0813BF4C
	ldr r4, .L0813BF3C
	ldr r3, .L0813BF50
.L0813BF02:
	adds r0, r1, #0
	adds r1, r0, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r2, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r3
	bls .L0813BF02
	movs r0, #0x48
	strh r0, [r5]
	movs r0, #0
	strh r0, [r6]
	strh r0, [r7]
	movs r0, #0
	bl sub_08133F14
	ldr r0, .L0813BF54
	ldr r1, .L0813BF40
	bl Task_Create
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0813BF38: .4byte 0x03006844 @ IWRAM+0x6844
.L0813BF3C: .4byte 0x0203DB88 @ EWRAM+0x3DB88
.L0813BF40: .4byte 0x0000FFFF
.L0813BF44: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813BF48: .4byte 0x03006940 @ IWRAM+0x6940
.L0813BF4C: .4byte 0x0300696C @ IWRAM+0x696C
.L0813BF50: .4byte 0x0000012B
.L0813BF54: .4byte gUnknown_0878FE64

	thumb_func_start sub_0813BF58
sub_0813BF58: @ 0x0813BF58
.L0813BF58:
	push {lr}
	ldr r0, .L0813BF6C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0813BF70
	movs r0, #0
	b .L0813BF72
	.byte 0x00, 0x00
.L0813BF6C: .4byte 0x0300684C @ IWRAM+0x684C
.L0813BF70:
	movs r0, #1
.L0813BF72:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0813BF78
sub_0813BF78: @ 0x0813BF78
.L0813BF78:
	push {lr}
	ldr r0, .L0813BF8C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L0813BF90
	movs r0, #0
	b .L0813BF92
	.byte 0x00, 0x00
.L0813BF8C: .4byte 0x0300684C @ IWRAM+0x684C
.L0813BF90:
	movs r0, #1
.L0813BF92:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_447
ScriptOp_447: @ 0x0813BF98
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
	ldr r3, .L0813BFE8
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813BFEC
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
	mov r8, r0
	lsls r0, r0, #0x10
	orrs r0, r4
	mov r8, r0
	cmp r5, #0
	bne .L0813BFF8
	ldr r0, .L0813BFF0
	ldr r1, .L0813BFF4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0813BFE6
	b .L0813C4DE
.L0813BFE6:
	b .L0813C4C0
.L0813BFE8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813BFEC: .4byte 0x03006950 @ IWRAM+0x6950
.L0813BFF0: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813BFF4: .4byte 0x0203DB7E @ EWRAM+0x3DB7E
.L0813BFF8:
	cmp r5, #1
	bne .L0813C054
	ldr r4, .L0813C03C
	ldrh r0, [r4]
	bl sub_0815B9DC
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0x1a
	bls .L0813C00E
	b .L0813C4CC
.L0813C00E:
	ldrh r0, [r4]
	movs r1, #0xb
	bl Demon_GetField
	movs r4, #0xff
	adds r6, r4, #0
	ands r6, r0
	cmp r6, #0x6f
	bls .L0813C040
	cmp r6, #0x8f
	bhi .L0813C026
	b .L0813C4DE
.L0813C026:
	movs r0, #0
	bl sub_080C0794
	lsls r0, r0, #8
	lsrs r5, r0, #0x10
	ands r5, r4
	cmp r5, #0x6f
	bhi .L0813C038
	b .L0813C4CC
.L0813C038:
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C03C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C040:
	movs r0, #0
	bl sub_080C0794
	lsls r0, r0, #8
	lsrs r5, r0, #0x10
	ands r5, r4
	cmp r5, #0x8f
	bhi .L0813C052
	b .L0813C4DE
.L0813C052:
	b .L0813C4CC
.L0813C054:
	cmp r5, #2
	bne .L0813C088
	bl Stock_GetCapacity
	adds r4, r0, #0
	ldr r0, .L0813C084
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0813C068
	b .L0813C4DE
.L0813C068:
	movs r6, #0
	cmp r7, r4
	blt .L0813C070
	b .L0813C4C0
.L0813C070:
	adds r0, r6, #4
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L0813C07C
	b .L0813C4DE
.L0813C07C:
	adds r6, #1
	cmp r6, r4
	blt .L0813C070
	b .L0813C4C0
.L0813C084: .4byte 0x0203DB86 @ EWRAM+0x3DB86
.L0813C088:
	cmp r5, #3
	bne .L0813C0B0
	ldr r0, .L0813C0A8
	ldrb r5, [r0]
	cmp r5, #0x8f
	bls .L0813C096
	b .L0813C4DE
.L0813C096:
	ldr r0, .L0813C0AC
	ldrh r0, [r0]
	bl sub_0813E804
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813C0A6
	b .L0813C4DE
.L0813C0A6:
	b .L0813C4CC
.L0813C0A8: .4byte 0x0300685C @ IWRAM+0x685C
.L0813C0AC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C0B0:
	cmp r5, #4
	bne .L0813C10C
	movs r6, #0x10
.L0813C0B6:
	adds r0, r6, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C0FA
	adds r0, r6, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L0813C104
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0813C0FA
	ldr r0, .L0813C108
	adds r4, r6, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	ldrh r0, [r0, #0x1a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x12
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt .L0813C0FA
	b .L0813C4C0
.L0813C0FA:
	adds r6, #1
	cmp r6, #0x17
	ble .L0813C0B6
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C104: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C108: .4byte 0xFFFF8000
.L0813C10C:
	cmp r5, #5
	bne .L0813C154
	movs r6, #0x10
.L0813C112:
	adds r0, r6, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C146
	adds r0, r6, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L0813C150
	ldrh r1, [r1]
	cmp r0, r1
	bne .L0813C146
	adds r0, r6, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	ands r1, r0
	cmp r1, #0
	beq .L0813C146
	b .L0813C4CC
.L0813C146:
	adds r6, #1
	cmp r6, #0x17
	ble .L0813C112
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C150: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C154:
	cmp r5, #6
	bne .L0813C19A
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C178
	movs r0, #1
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	movs r1, #0xa0
	lsls r1, r1, #0x18
	ands r1, r0
	cmp r1, #0
	beq .L0813C176
	b .L0813C4DE
.L0813C176:
	b .L0813C4C0
.L0813C178:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L0813C184
	b .L0813C4C0
.L0813C184:
	movs r0, #2
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	movs r1, #0xa0
	lsls r1, r1, #0x18
	ands r1, r0
	cmp r1, #0
	beq .L0813C198
	b .L0813C4DE
.L0813C198:
	b .L0813C4CC
.L0813C19A:
	cmp r5, #7
	bne .L0813C1AC
	bl sub_0813BF58
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813C1AA
	b .L0813C4DE
.L0813C1AA:
	b .L0813C4CC
.L0813C1AC:
	cmp r5, #8
	bne .L0813C1BE
	bl sub_0813BF78
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813C1BC
	b .L0813C4DE
.L0813C1BC:
	b .L0813C4C0
.L0813C1BE:
	cmp r5, #9
	bne .L0813C22C
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C1D0
	movs r6, #1
	b .L0813C1DE
.L0813C1D0:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L0813C1DC
	b .L0813C4DE
.L0813C1DC:
	movs r6, #2
.L0813C1DE:
	adds r0, r6, #0
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #4
	ands r1, r0
	cmp r1, #0
	beq .L0813C1F6
	movs r6, #1
	b .L0813C204
.L0813C1F6:
	adds r0, r6, #0
	movs r1, #2
	bl Combatant_GetStat
	adds r6, r0, #0
	movs r0, #0xff
	ands r6, r0
.L0813C204:
	bl Random_Byte
	adds r5, r0, #0
	movs r0, #0xf
	ands r5, r0
	ldr r0, .L0813C228
	ldrh r0, [r0]
	movs r1, #7
	bl Demon_GetField
	movs r1, #0xff
	ands r1, r0
	adds r5, r5, r1
	cmp r5, r6
	bhs .L0813C224
	b .L0813C4DE
.L0813C224:
	b .L0813C4CC
	.byte 0x00, 0x00
.L0813C228: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C22C:
	cmp r5, #0xa
	bne .L0813C254
	bl sub_0812A640
	ldr r1, .L0813C248
	str r0, [r1]
	ldr r0, .L0813C24C
	mov r1, r8
	str r1, [r0]
	ldr r1, .L0813C250
	movs r0, #0x4e
	strh r0, [r1]
	b .L0813C32E
	.byte 0x00, 0x00
.L0813C248: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813C24C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813C250: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813C254:
	cmp r5, #0xb
	bne .L0813C2EA
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C266
	movs r6, #1
	b .L0813C274
.L0813C266:
	movs r0, #2
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L0813C272
	b .L0813C4C0
.L0813C272:
	movs r6, #2
.L0813C274:
	adds r0, r6, #0
	bl Combatant_GetStatus
	movs r1, #0xc0
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L0813C286
	b .L0813C4C0
.L0813C286:
	movs r6, #0x10
.L0813C288:
	adds r0, r6, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813C2D0
	ldr r0, .L0813C2DC
	ldrh r4, [r0]
	adds r0, r6, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	bne .L0813C2D0
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r6, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0x1a
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge .L0813C2BE
	adds r0, #3
.L0813C2BE:
	lsls r0, r0, #0xe
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r2, #0x18
	ldrsh r0, [r0, r2]
	cmp r5, r0
	bge .L0813C2E0
.L0813C2D0:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0x17
	bls .L0813C288
	b .L0813C4C0
.L0813C2DC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C2E0:
	bl Random_Byte
	movs r1, #3
	ands r0, r1
	b .L0813C316
.L0813C2EA:
	cmp r5, #0xc
	bne .L0813C31E
	movs r1, #0xb
.L0813C2F0:
	lsls r4, r1, #0x10
	lsrs r0, r4, #0x10
	bl sub_0813756C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0813C310
	ldr r2, .L0813C30C
	adds r0, r4, r2
	lsrs r1, r0, #0x10
	cmp r0, #0
	bge .L0813C2F0
	b .L0813C4C0
	.byte 0x00, 0x00
.L0813C30C: .4byte 0xFFFF0000
.L0813C310:
	bl sub_0813BD58
	lsls r0, r0, #0x10
.L0813C316:
	cmp r0, #0
	bne .L0813C31C
	b .L0813C4DE
.L0813C31C:
	b .L0813C4C0
.L0813C31E:
	cmp r5, #0xd
	bne .L0813C340
	ldr r0, .L0813C338
	mov r2, r8
	str r2, [r0]
	movs r0, #1
	bl sub_0813BECC
.L0813C32E:
	ldr r1, .L0813C33C
	movs r0, #1
	strh r0, [r1]
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C338: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813C33C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L0813C340:
	cmp r5, #0xe
	bne .L0813C38C
	bl sub_0813BD58
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r7, r5, #0
	cmp r7, #1
	beq .L0813C354
	b .L0813C4C0
.L0813C354:
	bl sub_0813BDA4
	bl sub_0813BDCC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xc
	ldr r1, .L0813C384
	ldrh r4, [r1]
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsrs r5, r4, #2
	adds r0, r6, r5
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L0813C388
	ldrb r0, [r0]
	ands r7, r0
	cmp r7, #0
	beq .L0813C3E0
	b .L0813C3DC
	.byte 0x00, 0x00
.L0813C384: .4byte 0x03006690 @ IWRAM+0x6690
.L0813C388: .4byte 0x0300684C @ IWRAM+0x684C
.L0813C38C:
	cmp r5, #0xf
	bne .L0813C39C
	bl sub_0813BE2C
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813C402
	b .L0813C4CC
.L0813C39C:
	cmp r5, #0x10
	bne .L0813C3F4
	bl sub_0813BD58
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #2
	beq .L0813C3AE
	b .L0813C4C0
.L0813C3AE:
	bl sub_0813BDA4
	bl sub_08137BB8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xc
	ldr r1, .L0813C3E8
	ldrh r4, [r1]
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsrs r5, r4, #2
	adds r0, r6, r5
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L0813C3EC
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0813C3E0
.L0813C3DC:
	lsls r0, r6, #0x11
	lsrs r6, r0, #0x10
.L0813C3E0:
	ldr r0, .L0813C3F0
	str r6, [r0]
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C3E8: .4byte 0x03006690 @ IWRAM+0x6690
.L0813C3EC: .4byte 0x0300684C @ IWRAM+0x684C
.L0813C3F0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813C3F4:
	cmp r5, #0x11
	bne .L0813C418
	bl sub_0813BE08
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813C4CC
.L0813C402:
	ldr r0, .L0813C414
	ldrb r1, [r0]
	movs r2, #0x40
	orrs r1, r2
	strb r1, [r0]
	bl sub_0813BE98
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C414: .4byte 0x0300684C @ IWRAM+0x684C
.L0813C418:
	cmp r5, #0x12
	bne .L0813C440
	ldr r4, .L0813C43C
	movs r0, #0xe5
	strh r0, [r4]
	movs r0, #0xe5
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0813C4C0
	ldrh r0, [r4]
	bl sub_080C33AC
	bl sub_0813BEB8
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C43C: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813C440:
	cmp r5, #0x13
	bne .L0813C470
	ldr r0, .L0813C46C
	ldrh r0, [r0]
	movs r1, #0x1b
	bl Demon_GetField
	lsls r0, r0, #0x10
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r1, r0
	lsrs r7, r1, #0x11
	adds r7, #1
	bl sub_080C3168
	cmp r0, r7
	blo .L0813C4CC
	rsbs r0, r7, #0
	bl sub_080C3114
	b .L0813C4DE
	.byte 0x00, 0x00
.L0813C46C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C470:
	cmp r5, #0x14
	beq .L0813C4A0
	cmp r5, #0x15
	bne .L0813C4DE
	ldr r0, .L0813C49C
	mov r2, r8
	str r2, [r0]
	movs r0, #0xe5
	bl Flag_Test
	cmp r0, #0
	beq .L0813C4D8
	movs r0, #0
	bl sub_0812A668
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813C4D8
	movs r0, #0x2d
	bl sub_0813B328
	b .L0813C4DE
.L0813C49C: .4byte 0x03006840 @ IWRAM+0x6840
.L0813C4A0:
	movs r0, #0
	movs r1, #1
	bl Combatant_GetEquip
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xff
	beq .L0813C4C0
	movs r0, #0
	movs r1, #6
	bl Combatant_GetEquip
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xff
	bne .L0813C4DE
.L0813C4C0:
	ldr r0, .L0813C4C8
	mov r1, r8
	str r1, [r0]
	b .L0813C4DE
.L0813C4C8: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813C4CC:
	ldr r0, .L0813C4D4
	mov r2, r8
	str r2, [r0]
	b .L0813C4DE
.L0813C4D4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813C4D8:
	movs r0, #0x2e
	bl sub_0813B328
.L0813C4DE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start ScriptOpAlt_447
ScriptOpAlt_447: @ 0x0813C4E8
	ldr r1, .L0813C4F4
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813C4F4: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start sub_0813C4F8
sub_0813C4F8: @ 0x0813C4F8
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813C4FC
sub_0813C4FC: @ 0x0813C4FC
.L0813C4FC:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L0813C514
	bl Random_Byte
	adds r4, r0, #0
	movs r0, #0x1f
	ands r4, r0
	adds r4, #0x3b
	b .L0813C532
.L0813C514:
	cmp r0, #2
	bne .L0813C526
	bl Random_Byte
	adds r4, r0, #0
	movs r0, #0x1f
	ands r4, r0
	adds r4, #0x54
	b .L0813C532
.L0813C526:
	bl Random_Byte
	adds r4, r0, #0
	movs r0, #0xf
	ands r4, r0
	adds r4, #0x77
.L0813C532:
	ldr r0, .L0813C548
	ldrh r0, [r0]
	bl sub_0813E854
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r4
	blo .L0813C54C
	movs r0, #0
	b .L0813C54E
	.byte 0x00, 0x00
.L0813C548: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C54C:
	movs r0, #1
.L0813C54E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start ScriptOp_448
ScriptOp_448: @ 0x0813C554
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r3, .L0813C5A4
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813C5A8
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
	ldrh r7, [r0]
	lsls r7, r7, #0x10
	orrs r7, r4
	lsrs r0, r5, #8
	adds r1, r0, #0
	movs r4, #0xff
	ands r4, r5
	cmp r0, #0
	bne .L0813C5B0
	ldr r0, .L0813C5AC
	ldrb r0, [r0]
	cmp r0, r4
	bne .L0813C5A0
	b .L0813C7DA
.L0813C5A0:
	b .L0813C7D6
	.byte 0x00, 0x00
.L0813C5A4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813C5A8: .4byte 0x03006950 @ IWRAM+0x6950
.L0813C5AC: .4byte 0x0300685C @ IWRAM+0x685C
.L0813C5B0:
	cmp r0, #1
	bne .L0813C644
	movs r0, #0
	movs r1, #1
	bl Combatant_GetStat
	cmp r4, #1
	bne .L0813C5E0
	ldr r0, .L0813C5DC
	ldrh r0, [r0]
	movs r1, #6
	bl Demon_GetField
	adds r4, r0, #0
	bl Random_Byte
	movs r1, #3
	ands r0, r1
	adds r4, r4, r0
	subs r4, #1
	b .L0813C606
	.byte 0x00, 0x00
.L0813C5DC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C5E0:
	cmp r4, #2
	bne .L0813C610
	bl Random_Byte
	adds r5, r0, #0
	movs r0, #7
	ands r5, r0
	ldr r0, .L0813C60C
	ldrh r0, [r0]
	movs r1, #6
	bl Demon_GetField
	adds r4, r0, #0
	bl Random_Byte
	movs r1, #3
	ands r0, r1
	subs r4, r4, r0
	adds r4, r5, r4
.L0813C606:
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	b .L0813C62A
.L0813C60C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C610:
	bl Random_Byte
	adds r5, r0, #0
	movs r0, #7
	ands r5, r0
	ldr r0, .L0813C640
	ldrh r0, [r0]
	movs r1, #6
	bl Demon_GetField
	adds r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0813C62A:
	movs r0, #0xff
	ands r5, r0
	movs r0, #0
	movs r1, #1
	bl Combatant_GetStat
	cmp r5, r0
	bge .L0813C63C
	b .L0813C7DA
.L0813C63C:
	b .L0813C7D6
	.byte 0x00, 0x00
.L0813C640: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C644:
	cmp r0, #2
	bne .L0813C6EA
	movs r0, #0
	movs r1, #2
	bl Combatant_GetStat
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, .L0813C68C
	ldrh r0, [r0]
	movs r1, #7
	bl Demon_GetField
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r4, #1
	bne .L0813C694
	bl Random_Byte
	movs r1, #3
	ands r0, r1
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #2
	bls .L0813C682
	lsls r0, r5, #0x10
	ldr r1, .L0813C690
	adds r0, r0, r1
	lsrs r5, r0, #0x10
.L0813C682:
	cmp r5, r8
	bhs .L0813C688
	b .L0813C7DA
.L0813C688:
	b .L0813C7D6
	.byte 0x00, 0x00
.L0813C68C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C690: .4byte 0xFFFE0000
.L0813C694:
	cmp r4, #2
	bne .L0813C6CE
	bl Random_Byte
	adds r5, r0, #0
	movs r4, #7
	ands r5, r4
	bl Random_Byte
	ands r0, r4
	subs r0, r6, r0
	adds r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L0813C6BC
	b .L0813C7DA
.L0813C6BC:
	cmp r5, #0
	beq .L0813C6C6
	subs r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0813C6C6:
	cmp r5, r8
	bhs .L0813C6CC
	b .L0813C7DA
.L0813C6CC:
	b .L0813C7D6
.L0813C6CE:
	cmp r4, #3
	beq .L0813C6D4
	b .L0813C7DA
.L0813C6D4:
	bl Random_Byte
	movs r1, #7
	ands r0, r1
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, r8
	bhs .L0813C6E8
	b .L0813C7DA
.L0813C6E8:
	b .L0813C7D6
.L0813C6EA:
	cmp r0, #3
	bne .L0813C6FC
	adds r0, r4, #0
	bl sub_0813C4FC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813C7DA
	b .L0813C7D6
.L0813C6FC:
	cmp r0, #4
	bne .L0813C73C
	ldr r0, .L0813C714
	ldrh r0, [r0]
	cmp r0, #0xb
	bhi .L0813C7D6
	cmp r4, #0
	bne .L0813C718
	bl sub_0813BDCC
	b .L0813C71C
	.byte 0x00, 0x00
.L0813C714: .4byte 0x03006690 @ IWRAM+0x6690
.L0813C718:
	bl sub_08137BB8
.L0813C71C:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L0813C738
	ldrh r1, [r0]
	cmp r1, #0
	beq .L0813C732
	adds r0, r5, #0
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0813C732:
	cmp r5, #2
	bhi .L0813C7DA
	b .L0813C7D6
.L0813C738: .4byte 0x03006690 @ IWRAM+0x6690
.L0813C73C:
	cmp r0, #5
	bne .L0813C770
	cmp r4, #1
	bne .L0813C758
	ldr r0, .L0813C754
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L0813C7DA
	b .L0813C7D6
	.byte 0x00, 0x00
.L0813C754: .4byte 0x0300684C @ IWRAM+0x684C
.L0813C758:
	cmp r4, #2
	bne .L0813C7DA
	ldr r0, .L0813C76C
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L0813C7DA
	b .L0813C7D6
	.byte 0x00, 0x00
.L0813C76C: .4byte 0x0300684C @ IWRAM+0x684C
.L0813C770:
	cmp r0, #6
	bne .L0813C7BC
	ldr r0, .L0813C794
	strh r4, [r0]
	adds r0, r4, #0
	bl sub_080C32FC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0813C7A4
	adds r0, r4, #0
	bl sub_080C3328
	ldr r0, .L0813C798
	ldr r1, .L0813C79C
	str r1, [r0]
	ldr r0, .L0813C7A0
	b .L0813C7D8
.L0813C794: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813C798: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813C79C: .4byte gUnknown_080A0BC6
.L0813C7A0: .4byte 0x03006840 @ IWRAM+0x6840
.L0813C7A4:
	ldr r0, .L0813C7B0
	ldr r1, .L0813C7B4
	str r1, [r0]
	ldr r0, .L0813C7B8
	b .L0813C7D8
	.byte 0x00, 0x00
.L0813C7B0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813C7B4: .4byte gUnknown_080A0C0A
.L0813C7B8: .4byte 0x03006840 @ IWRAM+0x6840
.L0813C7BC:
	cmp r1, #7
	bne .L0813C7DA
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r1, #0
	orrs r4, r0
	ldr r0, .L0813C7E4
	strh r4, [r0]
	adds r0, r4, #0
	bl sub_080C5C14
	cmp r0, #0
	bne .L0813C7DA
.L0813C7D6:
	ldr r0, .L0813C7E8
.L0813C7D8:
	str r7, [r0]
.L0813C7DA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0813C7E4: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813C7E8: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_44A
ScriptOp_44A: @ 0x0813C7EC
	push {lr}
	ldr r2, .L0813C81C
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L0813C820
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #0xef
	bls .L0813C828
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L0813C824
	ldrh r0, [r0]
	bl sub_0815BB18
	b .L0813C830
.L0813C81C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813C820: .4byte 0x03006950 @ IWRAM+0x6950
.L0813C824: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L0813C828:
	ldr r0, .L0813C834
	ldrh r0, [r0]
	bl sub_0815BAC8
.L0813C830:
	pop {r0}
	bx r0
.L0813C834: .4byte 0x0203DB7C @ EWRAM+0x3DB7C

	thumb_func_start ScriptOpAlt_44A
ScriptOpAlt_44A: @ 0x0813C838
	ldr r1, .L0813C844
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813C844: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_44B
ScriptOp_44B: @ 0x0813C848
	push {r4, lr}
	ldr r2, .L0813C89C
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L0813C8A0
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #0xe0
	bl Flag_Test
	cmp r0, #0
	bne .L0813C8DA
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r1, #0
	ands r0, r4
	cmp r0, #0
	bne .L0813C8A4
	subs r0, r1, #1
	ands r0, r4
	cmp r0, #0
	bne .L0813C8C4
.L0813C882:
	movs r0, #0
	bl sub_080C0794
	movs r2, #0xff
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	cmp r0, r1
	beq .L0813C8DA
	movs r1, #0x80
	lsls r1, r1, #1
	b .L0813C8B8
	.byte 0x00, 0x00
.L0813C89C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813C8A0: .4byte 0x03006950 @ IWRAM+0x6950
.L0813C8A4:
	movs r0, #0
	bl sub_080C0794
	movs r2, #0xff
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0813C8DA
	ldr r1, .L0813C8C0
.L0813C8B8:
	movs r0, #0
	bl Combatant_AddAlignment
	b .L0813C8DA
.L0813C8C0: .4byte 0xFFFFFF00
.L0813C8C4:
	movs r0, #0
	bl sub_080C0794
	movs r2, #0xff
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	ands r0, r4
	cmp r0, #0
	bne .L0813C8A4
	b .L0813C882
.L0813C8DA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start ScriptOpAlt_44B
ScriptOpAlt_44B: @ 0x0813C8E0
	ldr r1, .L0813C8EC
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813C8EC: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start sub_0813C8F0
sub_0813C8F0: @ 0x0813C8F0
	ldr r1, .L0813C8FC
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813C8FC: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOpAlt_44C
ScriptOpAlt_44C: @ 0x0813C900
	ldr r1, .L0813C90C
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813C90C: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start sub_0813C910
sub_0813C910: @ 0x0813C910
	ldr r1, .L0813C918
	movs r0, #0
	strh r0, [r1]
	bx lr
.L0813C918: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813C91C
sub_0813C91C: @ 0x0813C91C
	push {lr}
	ldr r0, .L0813C934
	ldr r0, [r0]
	bl Window_IsIdle
	cmp r0, #0
	bne .L0813C93C
	ldr r1, .L0813C938
	movs r0, #1
	strh r0, [r1]
	b .L0813C946
	.byte 0x00, 0x00
.L0813C934: .4byte 0x03006968 @ IWRAM+0x6968
.L0813C938: .4byte 0x03006858 @ IWRAM+0x6858
.L0813C93C:
	ldr r0, .L0813C94C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813C950
	strh r1, [r0]
.L0813C946:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813C94C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813C950: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813C954
sub_0813C954: @ 0x0813C954
	push {lr}
	ldr r0, .L0813C96C
	ldr r0, [r0]
	bl Task_GetState
	adds r1, r0, #0
	cmp r1, #0
	beq .L0813C974
	ldr r1, .L0813C970
	movs r0, #1
	strh r0, [r1]
	b .L0813C97C
.L0813C96C: .4byte 0x030068B0 @ IWRAM+0x68B0
.L0813C970: .4byte 0x03006858 @ IWRAM+0x6858
.L0813C974:
	ldr r0, .L0813C980
	strh r1, [r0]
	ldr r0, .L0813C984
	strh r1, [r0]
.L0813C97C:
	pop {r0}
	bx r0
.L0813C980: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813C984: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813C988
sub_0813C988: @ 0x0813C988
	ldr r1, .L0813C99C
	ldr r0, .L0813C9A0
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L0813C9A4
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813C9A8
	strh r1, [r0]
	bx lr
.L0813C99C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813C9A0: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813C9A4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813C9A8: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813C9AC
sub_0813C9AC: @ 0x0813C9AC
	ldr r0, .L0813C9C0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813C9C4
	strh r1, [r0]
	ldr r0, .L0813C9C8
	strh r1, [r0]
	ldr r0, .L0813C9CC
	strh r1, [r0]
	bx lr
.L0813C9C0: .4byte 0x0203DB56 @ EWRAM+0x3DB56
.L0813C9C4: .4byte 0x0203DB52 @ EWRAM+0x3DB52
.L0813C9C8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813C9CC: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813C9D0
sub_0813C9D0: @ 0x0813C9D0
	ldr r0, .L0813C9DC
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813C9E0
	strh r1, [r0]
	bx lr
.L0813C9DC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813C9E0: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813C9E4
sub_0813C9E4: @ 0x0813C9E4
	ldr r0, .L0813C9F0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813C9F4
	strh r1, [r0]
	bx lr
.L0813C9F0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813C9F4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813C9F8
sub_0813C9F8: @ 0x0813C9F8
	push {r4, lr}
	ldr r0, .L0813CA0C
	ldr r0, [r0]
	bl Task_IsFree
	cmp r0, #0
	bne .L0813CA14
	ldr r1, .L0813CA10
	movs r0, #1
	b .L0813CA80
.L0813CA0C: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813CA10: .4byte 0x03006858 @ IWRAM+0x6858
.L0813CA14:
	ldr r0, .L0813CA4C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813CA50
	strh r1, [r0]
	ldr r0, .L0813CA54
	strh r1, [r0]
	ldr r0, .L0813CA58
	strh r1, [r0]
	ldr r0, .L0813CA5C
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r4, .L0813CA60
	bl ScriptVM_GetTextSpeed
	strh r0, [r4]
	ldr r0, .L0813CA64
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813CA6C
	ldr r0, .L0813CA68
	ldr r0, [r0]
	cmp r0, #0
	beq .L0813CA7C
	b .L0813CA74
.L0813CA4C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CA50: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813CA54: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813CA58: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813CA5C: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0813CA60: .4byte 0x0203DB48 @ EWRAM+0x3DB48
.L0813CA64: .4byte 0x03006670 @ IWRAM+0x6670
.L0813CA68: .4byte 0x030031CC @ IWRAM+0x31CC
.L0813CA6C:
	ldr r0, .L0813CA88
	ldr r0, [r0]
	cmp r0, #0
	bne .L0813CA7C
.L0813CA74:
	ldr r0, .L0813CA8C
	ldr r1, .L0813CA90
	ldr r1, [r1]
	str r1, [r0]
.L0813CA7C:
	ldr r1, .L0813CA94
	movs r0, #0
.L0813CA80:
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L0813CA88: .4byte 0x030031CC @ IWRAM+0x31CC
.L0813CA8C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CA90: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CA94: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CA98
sub_0813CA98: @ 0x0813CA98
	push {lr}
	ldr r1, .L0813CAC0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813CAB4
	ldr r0, .L0813CAC4
	ldr r0, [r0]
	strh r0, [r1]
	ldr r1, .L0813CAC8
	movs r0, #0x39
	strh r0, [r1]
.L0813CAB4:
	ldr r1, .L0813CACC
	movs r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813CAC0: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L0813CAC4: .4byte 0x030068C8 @ IWRAM+0x68C8
.L0813CAC8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CACC: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CAD0
sub_0813CAD0: @ 0x0813CAD0
	push {r4, lr}
	ldr r4, .L0813CAFC
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	ldr r0, .L0813CB00
	bl sub_080C30AC
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L0813CB12
	bl sub_080C3100
	cmp r0, #0
	beq .L0813CB08
	movs r1, #1
	strh r1, [r4]
	ldr r0, .L0813CB04
	strh r1, [r0]
	b .L0813CB18
	.byte 0x00, 0x00
.L0813CAFC: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L0813CB00: .4byte 0xFFFFFC18
.L0813CB04: .4byte 0x03006858 @ IWRAM+0x6858
.L0813CB08:
	ldr r0, .L0813CB20
	movs r1, #0x3a
	strh r1, [r0]
	movs r0, #0x3c
	strh r0, [r4]
.L0813CB12:
	ldr r1, .L0813CB24
	movs r0, #1
	strh r0, [r1]
.L0813CB18:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813CB20: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CB24: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CB28
sub_0813CB28: @ 0x0813CB28
	push {r4, lr}
	ldr r4, .L0813CB54
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813CB46
	bl sub_080C762C
	ldr r0, .L0813CB58
	movs r1, #0xf
	strh r1, [r0]
	movs r0, #0x3c
	strh r0, [r4]
.L0813CB46:
	ldr r1, .L0813CB5C
	movs r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813CB54: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L0813CB58: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CB5C: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CB60
sub_0813CB60: @ 0x0813CB60
	push {r4, lr}
	ldr r4, .L0813CB90
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813CB84
	ldr r1, .L0813CB94
	movs r0, #0x11
	strh r0, [r1]
	ldr r0, .L0813CB98
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_080C30AC
	movs r0, #0x1e
	strh r0, [r4]
.L0813CB84:
	ldr r1, .L0813CB9C
	movs r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L0813CB90: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L0813CB94: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CB98: .4byte 0x0203DB62 @ EWRAM+0x3DB62
.L0813CB9C: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CBA0
sub_0813CBA0: @ 0x0813CBA0
	push {r4, lr}
	ldr r4, .L0813CBCC
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813CBBE
	bl sub_080C762C
	ldr r0, .L0813CBD0
	movs r1, #0xf
	strh r1, [r0]
	movs r0, #0x3c
	strh r0, [r4]
.L0813CBBE:
	ldr r1, .L0813CBD4
	movs r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813CBCC: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L0813CBD0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CBD4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CBD8
sub_0813CBD8: @ 0x0813CBD8
	push {lr}
	ldr r1, .L0813CBFC
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	ldr r2, .L0813CC00
	cmp r1, #0
	bne .L0813CBF2
	ldr r0, .L0813CC04
	strh r1, [r0]
	strh r1, [r2]
.L0813CBF2:
	movs r0, #1
	strh r0, [r2]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813CBFC: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L0813CC00: .4byte 0x03006858 @ IWRAM+0x6858
.L0813CC04: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start sub_0813CC08
sub_0813CC08: @ 0x0813CC08
	push {lr}
	bl sub_0812685C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	beq .L0813CC1C
	cmp r0, #5
	beq .L0813CC30
	b .L0813CC34
.L0813CC1C:
	ldr r0, .L0813CC28
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813CC2C
	strh r1, [r0]
	b .L0813CC3A
.L0813CC28: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CC2C: .4byte 0x03006858 @ IWRAM+0x6858
.L0813CC30:
	bl sub_08132890
.L0813CC34:
	ldr r1, .L0813CC40
	movs r0, #1
	strh r0, [r1]
.L0813CC3A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813CC40: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CC44
sub_0813CC44: @ 0x0813CC44
	ldr r0, .L0813CC50
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813CC54
	strh r1, [r0]
	bx lr
.L0813CC50: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CC54: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CC58
sub_0813CC58: @ 0x0813CC58
	push {r4, lr}
	ldr r0, .L0813CCA0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813CCA4
	strh r1, [r0]
	ldr r0, .L0813CCA8
	strh r1, [r0]
	ldr r0, .L0813CCAC
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L0813CCB0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bne .L0813CCC0
	bl sub_080C3100
	adds r4, r0, #0
	ldr r0, .L0813CCB4
	ldrh r0, [r0]
	subs r0, #0x9d
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_0812F188
	cmp r4, r0
	bhs .L0813CD0E
	ldr r0, .L0813CCB8
	ldr r1, .L0813CCBC
	ldr r1, [r1]
	str r1, [r0]
	b .L0813CD0E
.L0813CCA0: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813CCA4: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813CCA8: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813CCAC: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0813CCB0: .4byte 0x03006844 @ IWRAM+0x6844
.L0813CCB4: .4byte 0x030065E0 @ IWRAM+0x65E0
.L0813CCB8: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CCBC: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CCC0:
	ldr r0, .L0813CCE0
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0813CCF4
	ldr r3, .L0813CCE4
	ldr r2, .L0813CCE8
	ldr r0, .L0813CCEC
	movs r4, #0
	ldrsh r0, [r0, r4]
	ldr r1, .L0813CCF0
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r0, r0, r1
	adds r0, #0xa
	b .L0813CD06
	.byte 0x00, 0x00
.L0813CCE0: .4byte 0x030069CC @ IWRAM+0x69CC
.L0813CCE4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CCE8: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CCEC: .4byte 0x03006940 @ IWRAM+0x6940
.L0813CCF0: .4byte 0x0300696C @ IWRAM+0x696C
.L0813CCF4:
	ldr r3, .L0813CD20
	ldr r2, .L0813CD24
	ldr r0, .L0813CD28
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, .L0813CD2C
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r0, r0, r1
.L0813CD06:
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r3]
.L0813CD0E:
	ldr r0, .L0813CD30
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813CD34
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813CD20: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CD24: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CD28: .4byte 0x03006940 @ IWRAM+0x6940
.L0813CD2C: .4byte 0x0300696C @ IWRAM+0x696C
.L0813CD30: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CD34: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CD38
sub_0813CD38: @ 0x0813CD38
	push {r4, lr}
	ldr r0, .L0813CD68
	movs r4, #0
	strh r4, [r0]
	ldr r0, .L0813CD6C
	strh r4, [r0]
	ldr r0, .L0813CD70
	strh r4, [r0]
	ldr r0, .L0813CD74
	strh r4, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L0813CD78
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bne .L0813CD84
	ldr r0, .L0813CD7C
	ldr r1, .L0813CD80
	ldr r1, [r1, #4]
	str r1, [r0]
	b .L0813CD96
.L0813CD68: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813CD6C: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813CD70: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813CD74: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0813CD78: .4byte 0x03006844 @ IWRAM+0x6844
.L0813CD7C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CD80: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CD84:
	ldr r2, .L0813CDA8
	ldrh r0, [r2]
	cmp r0, #0
	beq .L0813CD96
	ldr r0, .L0813CDAC
	ldr r1, .L0813CDB0
	ldr r1, [r1, #0x38]
	str r1, [r0]
	strh r4, [r2]
.L0813CD96:
	ldr r0, .L0813CDB4
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813CDB8
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813CDA8: .4byte 0x030069CC @ IWRAM+0x69CC
.L0813CDAC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CDB0: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CDB4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CDB8: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CDBC
sub_0813CDBC: @ 0x0813CDBC
	push {lr}
	bl sub_0813DA6C
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813CDD4
	ldr r1, .L0813CDD0
	movs r0, #0
	b .L0813CDD8
	.byte 0x00, 0x00
.L0813CDD0: .4byte 0x03006858 @ IWRAM+0x6858
.L0813CDD4:
	ldr r1, .L0813CDE0
	movs r0, #1
.L0813CDD8:
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813CDE0: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CDE4
sub_0813CDE4: @ 0x0813CDE4
	ldr r0, .L0813CDF0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813CDF4
	strh r1, [r0]
	bx lr
.L0813CDF0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CDF4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CDF8
sub_0813CDF8: @ 0x0813CDF8
	push {r4, lr}
	ldr r0, .L0813CE40
	movs r4, #0
	strh r4, [r0]
	ldr r0, .L0813CE44
	ldr r1, [r0, #0x10]
	cmp r1, #0
	beq .L0813CE36
	ldr r0, .L0813CE48
	str r1, [r0]
	ldr r2, .L0813CE4C
	ldr r1, .L0813CE50
	movs r0, #0
	strh r0, [r1, #0x10]
	strh r0, [r1, #8]
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0x40
	strh r0, [r1]
	strh r0, [r2, #0x30]
	strh r0, [r2, #0x20]
	strh r0, [r2, #0x10]
	strh r0, [r2]
	ldr r1, .L0813CE54
	strh r0, [r1]
	ldr r1, .L0813CE58
	strh r0, [r1]
	ldr r0, .L0813CE5C
	ldr r0, [r0]
	bl sub_080D34F0
.L0813CE36:
	ldr r0, .L0813CE60
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
.L0813CE40: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CE44: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CE48: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CE4C: .4byte 0x03006620 @ IWRAM+0x6620
.L0813CE50: .4byte 0x03006920 @ IWRAM+0x6920
.L0813CE54: .4byte 0x0300699C @ IWRAM+0x699C
.L0813CE58: .4byte 0x0300669C @ IWRAM+0x669C
.L0813CE5C: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813CE60: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CE64
sub_0813CE64: @ 0x0813CE64
	push {r4, lr}
	ldr r0, .L0813CEA8
	movs r1, #0
	strh r1, [r0]
	movs r4, #0
	movs r0, #0
	bl Combatant_IsAlive
	cmp r0, #1
	bne .L0813CE7A
	movs r4, #1
.L0813CE7A:
	movs r0, #1
	bl Combatant_IsAlive
	cmp r0, #1
	bne .L0813CE8A
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L0813CE8A:
	movs r0, #2
	bl Combatant_IsAlive
	cmp r0, #1
	bne .L0813CE9A
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L0813CE9A:
	cmp r4, #1
	bne .L0813CEB4
	ldr r0, .L0813CEAC
	ldr r1, .L0813CEB0
	ldr r1, [r1, #0xc]
	b .L0813CEBA
	.byte 0x00, 0x00
.L0813CEA8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CEAC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CEB0: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CEB4:
	ldr r0, .L0813CEC8
	ldr r1, .L0813CECC
	ldr r1, [r1, #4]
.L0813CEBA:
	str r1, [r0]
	ldr r1, .L0813CED0
	movs r0, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L0813CEC8: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CECC: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CED0: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CED4
sub_0813CED4: @ 0x0813CED4
	ldr r0, .L0813CEE0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813CEE4
	strh r1, [r0]
	bx lr
.L0813CEE0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CEE4: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CEE8
sub_0813CEE8: @ 0x0813CEE8
	ldr r0, .L0813CEFC
	movs r2, #0
	strh r2, [r0]
	ldr r1, .L0813CF00
	ldr r0, .L0813CF04
	ldr r0, [r0, #4]
	str r0, [r1]
	ldr r0, .L0813CF08
	strh r2, [r0]
	bx lr
.L0813CEFC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CF00: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CF04: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CF08: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CF0C
sub_0813CF0C: @ 0x0813CF0C
	ldr r0, .L0813CF20
	movs r2, #0
	strh r2, [r0]
	ldr r1, .L0813CF24
	ldr r0, .L0813CF28
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L0813CF2C
	strh r2, [r0]
	bx lr
.L0813CF20: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CF24: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CF28: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CF2C: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CF30
sub_0813CF30: @ 0x0813CF30
	ldr r0, .L0813CF3C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813CF40
	strh r1, [r0]
	bx lr
.L0813CF3C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CF40: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CF44
sub_0813CF44: @ 0x0813CF44
	ldr r0, .L0813CF58
	movs r2, #0
	strh r2, [r0]
	ldr r1, .L0813CF5C
	ldr r0, .L0813CF60
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L0813CF64
	strh r2, [r0]
	bx lr
.L0813CF58: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813CF5C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813CF60: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813CF64: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CF68
sub_0813CF68: @ 0x0813CF68
	ldr r1, .L0813CF70
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813CF70: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CF74
sub_0813CF74: @ 0x0813CF74
	ldr r1, .L0813CF7C
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813CF7C: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CF80
sub_0813CF80: @ 0x0813CF80
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r0, .L0813CFBC
	ldr r1, .L0813CFC0
	mov r8, r1
	movs r6, #1
	strh r6, [r1]
	ldr r4, .L0813CFC4
	ldrb r5, [r4]
	ldr r1, .L0813CFC8
	strh r0, [r1]
	movs r1, #0x1f
	bl Demon_GetField
	strb r0, [r4]
	movs r0, #0
	bl Negotiate_CallReply
	strb r5, [r4]
	ldr r1, .L0813CFCC
	movs r0, #0
	strh r0, [r1]
	mov r0, r8
	strh r6, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0813CFBC: .4byte 0x0000FFFF
.L0813CFC0: .4byte 0x03006858 @ IWRAM+0x6858
.L0813CFC4: .4byte 0x0300685C @ IWRAM+0x685C
.L0813CFC8: .4byte 0x0203DB7E @ EWRAM+0x3DB7E
.L0813CFCC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A

	thumb_func_start sub_0813CFD0
sub_0813CFD0: @ 0x0813CFD0
	ldr r1, .L0813CFD8
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813CFD8: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813CFDC
sub_0813CFDC: @ 0x0813CFDC
	push {lr}
	ldr r0, .L0813CFF4
	ldr r0, [r0]
	bl sub_080CE74C
	cmp r0, #0
	bne .L0813CFFC
	ldr r1, .L0813CFF8
	movs r0, #1
	strh r0, [r1]
	b .L0813D006
	.byte 0x00, 0x00
.L0813CFF4: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813CFF8: .4byte 0x03006858 @ IWRAM+0x6858
.L0813CFFC:
	ldr r0, .L0813D00C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D010
	strh r1, [r0]
.L0813D006:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D00C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D010: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D014
sub_0813D014: @ 0x0813D014
	push {lr}
	ldr r0, .L0813D02C
	ldr r0, [r0]
	bl sub_080CE74C
	cmp r0, #0
	bne .L0813D034
	ldr r1, .L0813D030
	movs r0, #1
	strh r0, [r1]
	b .L0813D03E
	.byte 0x00, 0x00
.L0813D02C: .4byte 0x030068E0 @ IWRAM+0x68E0
.L0813D030: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D034:
	ldr r0, .L0813D044
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D048
	strh r1, [r0]
.L0813D03E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D044: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D048: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D04C
sub_0813D04C: @ 0x0813D04C
	push {lr}
	ldr r0, .L0813D064
	ldr r0, [r0]
	bl sub_080CE74C
	cmp r0, #0
	bne .L0813D06C
	ldr r1, .L0813D068
	movs r0, #1
	strh r0, [r1]
	b .L0813D076
	.byte 0x00, 0x00
.L0813D064: .4byte 0x03006964 @ IWRAM+0x6964
.L0813D068: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D06C:
	ldr r0, .L0813D07C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D080
	strh r1, [r0]
.L0813D076:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D07C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D080: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D084
sub_0813D084: @ 0x0813D084
	push {lr}
	ldr r0, .L0813D09C
	ldr r0, [r0]
	bl sub_080CE74C
	cmp r0, #0
	bne .L0813D0A4
	ldr r1, .L0813D0A0
	movs r0, #1
	strh r0, [r1]
	b .L0813D0AE
	.byte 0x00, 0x00
.L0813D09C: .4byte 0x03006964 @ IWRAM+0x6964
.L0813D0A0: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D0A4:
	ldr r0, .L0813D0B4
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D0B8
	strh r1, [r0]
.L0813D0AE:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D0B4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D0B8: .4byte 0x03006858 @ IWRAM+0x6858

	thumb_func_start sub_0813D0BC
sub_0813D0BC: @ 0x0813D0BC
	push {lr}
	ldr r0, .L0813D0D4
	ldr r0, [r0]
	bl sub_080CE74C
	cmp r0, #0
	bne .L0813D0DC
	ldr r1, .L0813D0D8
	movs r0, #1
	strh r0, [r1]
	b .L0813D0E6
	.byte 0x00, 0x00
.L0813D0D4: .4byte 0x03006964 @ IWRAM+0x6964
.L0813D0D8: .4byte 0x03006858 @ IWRAM+0x6858
.L0813D0DC:
	ldr r0, .L0813D0EC
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0813D0F0
	strh r1, [r0]
.L0813D0E6:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813D0EC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813D0F0: .4byte 0x03006858 @ IWRAM+0x6858
