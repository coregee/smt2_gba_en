	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_08130694
sub_08130694: @ 0x08130694
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, .L081306E8
	ldr r2, .L081306EC
	ldr r6, .L081306F0
	movs r3, #0
	ldrsh r0, [r6, r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #0xe
	strh r0, [r1]
	ldr r1, .L081306F4
	movs r4, #0
	ldrsh r0, [r6, r4]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, .L081306F8
	movs r0, #0x13
	strh r0, [r1]
	ldr r1, .L081306FC
	movs r5, #1
	strh r5, [r1]
	ldr r4, .L08130700
	ldrh r2, [r4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	mov r8, r6
	mov sb, r1
	cmp r0, #0
	beq .L08130704
	subs r0, r2, #1
	strh r0, [r4]
	b .L08130C1A
.L081306E8: .4byte 0x0300689C @ IWRAM+0x689C
.L081306EC: .4byte gUnknown_0878FCC4
.L081306F0: .4byte 0x0300696C @ IWRAM+0x696C
.L081306F4: .4byte 0x0300695C @ IWRAM+0x695C
.L081306F8: .4byte 0x030066A0 @ IWRAM+0x66A0
.L081306FC: .4byte 0x03006958 @ IWRAM+0x6958
.L08130700: .4byte 0x030068D4 @ IWRAM+0x68D4
.L08130704:
	ldr r3, .L0813072C
	ldrh r1, [r3]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L08130738
	ldr r1, .L08130730
	ldrh r0, [r1]
	eors r0, r5
	strh r0, [r1]
	ldr r0, .L08130734
	ldrh r0, [r0]
	ldrh r1, [r1]
	bl Shop_InitItemList
	strh r5, [r4]
	b .L08130C1A
	.byte 0x00, 0x00
.L0813072C: .4byte 0x030031C4 @ IWRAM+0x31C4
.L08130730: .4byte 0x030065E4 @ IWRAM+0x65E4
.L08130734: .4byte 0x03006940 @ IWRAM+0x6940
.L08130738:
	ldr r0, .L08130768
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L081307C0
	movs r4, #0
	ldrsh r1, [r6, r4]
	cmp r1, #0
	beq .L0813077C
	strh r2, [r6]
	ldr r0, .L0813076C
	ldr r0, [r0]
	ldr r1, .L08130770
	ldrh r2, [r1]
	ldr r3, .L08130774
	ldr r1, .L08130778
	movs r5, #0
	ldrsh r1, [r1, r5]
	lsls r1, r1, #1
	adds r1, r1, r3
	b .L08130990
	.byte 0x00, 0x00
.L08130768: .4byte 0x03003964 @ IWRAM+0x3964
.L0813076C: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130770: .4byte 0x03006898 @ IWRAM+0x6898
.L08130774: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130778: .4byte 0x03006940 @ IWRAM+0x6940
.L0813077C:
	ldr r3, .L08130790
	movs r2, #0
	ldrsh r0, [r3, r2]
	subs r0, #3
	cmp r0, #0
	blt .L08130794
	ldrh r0, [r3]
	subs r0, #3
	b .L08130976
	.byte 0x00, 0x00
.L08130790: .4byte 0x03006940 @ IWRAM+0x6940
.L08130794:
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	bne .L0813079E
	b .L081309FA
.L0813079E:
	strh r1, [r3]
	ldr r0, .L081307B4
	ldr r0, [r0]
	ldr r1, .L081307B8
	ldrh r2, [r1]
	ldr r3, .L081307BC
	movs r4, #0
	ldrsh r1, [r6, r4]
	lsls r1, r1, #1
	adds r1, r1, r3
	b .L081309EC
.L081307B4: .4byte 0x030068A4 @ IWRAM+0x68A4
.L081307B8: .4byte 0x03006898 @ IWRAM+0x6898
.L081307BC: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L081307C0:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08130880
	movs r5, #0
	ldrsh r0, [r6, r5]
	cmp r0, #2
	beq .L0813082C
	ldr r0, .L081307E4
	ldrh r1, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	bgt .L081307E8
	subs r0, r1, #1
	b .L081307EA
	.byte 0x00, 0x00
.L081307E4: .4byte 0x03006688 @ IWRAM+0x6688
.L081307E8:
	movs r0, #2
.L081307EA:
	strh r0, [r6]
	movs r0, #0x64
	bl Sound_Play
	ldr r0, .L08130818
	ldr r0, [r0]
	ldr r1, .L0813081C
	ldrh r2, [r1]
	ldr r4, .L08130820
	ldr r1, .L08130824
	movs r3, #0
	ldrsh r1, [r1, r3]
	ldr r3, .L08130828
	movs r5, #0
	ldrsh r3, [r3, r5]
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r3, [r1]
	movs r1, #1
	bl sub_080D34A4
	b .L081309FA
.L08130818: .4byte 0x030068A4 @ IWRAM+0x68A4
.L0813081C: .4byte 0x03006898 @ IWRAM+0x6898
.L08130820: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130824: .4byte 0x0300696C @ IWRAM+0x696C
.L08130828: .4byte 0x03006940 @ IWRAM+0x6940
.L0813082C:
	movs r0, #0
	ldrsh r1, [r6, r0]
	ldr r3, .L0813084C
	movs r4, #0
	ldrsh r2, [r3, r4]
	adds r1, r1, r2
	ldr r4, .L08130850
	movs r5, #0
	ldrsh r0, [r4, r5]
	subs r0, #3
	cmp r1, r0
	bge .L08130854
	ldrh r0, [r3]
	adds r0, #3
	b .L08130976
	.byte 0x00, 0x00
.L0813084C: .4byte 0x03006940 @ IWRAM+0x6940
.L08130850: .4byte 0x03006688 @ IWRAM+0x6688
.L08130854:
	cmp r2, r0
	bne .L0813085A
	b .L081309FA
.L0813085A:
	ldrh r0, [r4]
	subs r0, #3
	strh r0, [r3]
	ldr r0, .L08130874
	ldr r0, [r0]
	ldr r1, .L08130878
	ldrh r2, [r1]
	ldr r4, .L0813087C
	movs r5, #0
	ldrsh r1, [r6, r5]
	movs r6, #0
	ldrsh r3, [r3, r6]
	b .L081309E6
.L08130874: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130878: .4byte 0x03006898 @ IWRAM+0x6898
.L0813087C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130880:
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L0813090C
	ldrh r1, [r6]
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #0
	beq .L081308C0
	subs r0, r1, #1
	strh r0, [r6]
	ldr r0, .L081308B0
	ldr r0, [r0]
	ldr r1, .L081308B4
	ldrh r2, [r1]
	ldr r4, .L081308B8
	movs r3, #0
	ldrsh r1, [r6, r3]
	ldr r3, .L081308BC
	movs r5, #0
	ldrsh r3, [r3, r5]
	b .L0813098A
.L081308B0: .4byte 0x030068A4 @ IWRAM+0x68A4
.L081308B4: .4byte 0x03006898 @ IWRAM+0x6898
.L081308B8: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L081308BC: .4byte 0x03006940 @ IWRAM+0x6940
.L081308C0:
	ldr r3, .L081308D0
	ldrh r1, [r3]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	beq .L081308D4
	subs r0, r1, #1
	b .L08130976
.L081308D0: .4byte 0x03006940 @ IWRAM+0x6940
.L081308D4:
	ldr r0, .L081308FC
	ldrh r1, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #3
	ble .L081308E2
	b .L081309FA
.L081308E2:
	subs r0, r1, #1
	strh r0, [r6]
	ldr r0, .L08130900
	ldr r0, [r0]
	ldr r1, .L08130904
	ldrh r2, [r1]
	ldr r4, .L08130908
	movs r5, #0
	ldrsh r1, [r6, r5]
	movs r6, #0
	ldrsh r3, [r3, r6]
	b .L081309E6
	.byte 0x00, 0x00
.L081308FC: .4byte 0x03006688 @ IWRAM+0x6688
.L08130900: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130904: .4byte 0x03006898 @ IWRAM+0x6898
.L08130908: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813090C:
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne .L0813091A
	b .L08130A28
.L0813091A:
	ldrh r4, [r6]
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #2
	bne .L081309B0
	ldr r4, .L08130948
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r0, #3
	bne .L0813095C
	strh r2, [r6]
	ldr r0, .L0813094C
	ldr r0, [r0]
	ldr r1, .L08130950
	ldrh r2, [r1]
	ldr r3, .L08130954
	ldr r1, .L08130958
	movs r4, #0
	ldrsh r1, [r1, r4]
	lsls r1, r1, #1
	adds r1, r1, r3
	b .L08130990
	.byte 0x00, 0x00
.L08130948: .4byte 0x03006688 @ IWRAM+0x6688
.L0813094C: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130950: .4byte 0x03006898 @ IWRAM+0x6898
.L08130954: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130958: .4byte 0x03006940 @ IWRAM+0x6940
.L0813095C:
	movs r5, #0
	ldrsh r1, [r6, r5]
	ldr r3, .L081309A0
	movs r2, #0
	ldrsh r0, [r3, r2]
	adds r1, r1, r0
	movs r5, #0
	ldrsh r0, [r4, r5]
	subs r0, #1
	cmp r1, r0
	bge .L081309FA
	ldrh r0, [r3]
	adds r0, #1
.L08130976:
	strh r0, [r3]
	ldr r0, .L081309A4
	ldr r0, [r0]
	ldr r1, .L081309A8
	ldrh r2, [r1]
	ldr r4, .L081309AC
	movs r5, #0
	ldrsh r1, [r6, r5]
	movs r6, #0
	ldrsh r3, [r3, r6]
.L0813098A:
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, r1, r4
.L08130990:
	ldrh r3, [r1]
	movs r1, #1
	bl sub_080D34A4
	movs r0, #0x64
	bl Sound_Play
	b .L081309FA
.L081309A0: .4byte 0x03006940 @ IWRAM+0x6940
.L081309A4: .4byte 0x030068A4 @ IWRAM+0x68A4
.L081309A8: .4byte 0x03006898 @ IWRAM+0x6898
.L081309AC: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L081309B0:
	ldr r3, .L081309C8
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #2
	bgt .L081309CC
	movs r5, #0
	ldrsh r1, [r6, r5]
	subs r0, #1
	cmp r1, r0
	blt .L081309CC
	strh r2, [r6]
	b .L081309D0
.L081309C8: .4byte 0x03006688 @ IWRAM+0x6688
.L081309CC:
	adds r0, r4, #1
	strh r0, [r6]
.L081309D0:
	ldr r0, .L08130A10
	ldr r0, [r0]
	ldr r1, .L08130A14
	ldrh r2, [r1]
	ldr r4, .L08130A18
	mov r6, r8
	movs r3, #0
	ldrsh r1, [r6, r3]
	ldr r3, .L08130A1C
	movs r5, #0
	ldrsh r3, [r3, r5]
.L081309E6:
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, r1, r4
.L081309EC:
	ldrh r3, [r1]
	movs r1, #1
	bl sub_080D34A4
	movs r0, #0x64
	bl Sound_Play
.L081309FA:
	ldr r0, .L08130A1C
	ldrh r0, [r0]
	ldr r1, .L08130A20
	ldrh r1, [r1]
	bl Shop_InitItemList
	ldr r1, .L08130A24
	movs r0, #1
	strh r0, [r1]
	b .L08130C1A
	.byte 0x00, 0x00
.L08130A10: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130A14: .4byte 0x03006898 @ IWRAM+0x6898
.L08130A18: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130A1C: .4byte 0x03006940 @ IWRAM+0x6940
.L08130A20: .4byte 0x030065E4 @ IWRAM+0x65E4
.L08130A24: .4byte 0x030068D4 @ IWRAM+0x68D4
.L08130A28:
	ldrh r0, [r3]
	movs r1, #1
	mov r8, r1
	mov r2, r8
	ands r2, r0
	cmp r2, #0
	bne .L08130A38
	b .L08130BB4
.L08130A38:
	mov r2, r8
	strh r2, [r7, #0x1c]
	ldr r3, .L08130AA0
	mov sl, r3
	ldr r0, [r3]
	bl sub_080D34F0
	ldr r7, .L08130AA4
	movs r4, #0
	ldrsh r0, [r7, r4]
	cmp r0, #0x28
	bne .L08130AC0
	movs r0, #0x29
	strh r0, [r7]
	ldr r0, .L08130AA8
	mov r8, r0
	ldr r2, .L08130AAC
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r4, .L08130AB0
	movs r3, #0
	ldrsh r1, [r4, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	bl Money_Get
	ldr r3, .L08130AB4
	movs r2, #0
	ldrsh r1, [r6, r2]
	movs r6, #0
	ldrsh r2, [r4, r6]
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r1, [r1]
	adds r0, r0, r1
	ldr r1, .L08130AB8
	cmp r0, r1
	bls .L08130B82
	ldr r0, .L08130ABC
	ldr r1, [r0, #8]
	str r1, [r0, #0x10]
	movs r0, #0x23
	strh r0, [r7]
	mov r0, sb
	strh r5, [r0]
	b .L08130B2A
	.byte 0x00, 0x00
.L08130AA0: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08130AA4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08130AA8: .4byte 0x030069A8 @ IWRAM+0x69A8
.L08130AAC: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130AB0: .4byte 0x03006940 @ IWRAM+0x6940
.L08130AB4: .4byte 0x0203BD74 @ EWRAM+0x3BD74
.L08130AB8: .4byte 0x000F423F
.L08130ABC: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08130AC0:
	movs r0, #0x23
	strh r0, [r7]
	ldr r2, .L08130B04
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r1, .L08130B08
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r6, [r0]
	adds r0, r6, #0
	bl Inventory_GetCount
	adds r4, r0, #0
	movs r0, #0xff
	adds r1, r6, #0
	bl Party_CountEquipped
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r0
	cmp r4, #0x62
	ble .L08130B10
	ldr r1, .L08130B0C
	ldr r0, [r1, #8]
	str r0, [r1, #0x10]
	mov r4, sb
	strh r5, [r4]
	b .L08130B2A
	.byte 0x00, 0x00
.L08130B04: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08130B08: .4byte 0x03006940 @ IWRAM+0x6940
.L08130B0C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08130B10:
	adds r0, r6, #0
	bl sub_080C4C60
	adds r4, r0, #0
	bl Money_Get
	cmp r4, r0
	bls .L08130B38
	ldr r1, .L08130B34
	ldr r0, [r1]
	str r0, [r1, #0x10]
	mov r6, sb
	strh r5, [r6]
.L08130B2A:
	movs r0, #0x66
	bl Sound_Play
	b .L08130C1A
	.byte 0x00, 0x00
.L08130B34: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08130B38:
	ldr r0, .L08130B8C
	str r5, [r0, #0x10]
	ldr r4, .L08130B90
	strh r6, [r4]
	ldr r0, .L08130B94
	mov r1, r8
	strh r1, [r0]
	ldrh r0, [r4]
	bl sub_080C4C60
	ldr r1, .L08130B98
	str r0, [r1]
	ldr r1, .L08130B9C
	ldrh r0, [r4]
	strh r0, [r1]
	ldr r1, .L08130BA0
	ldr r0, .L08130BA4
	strh r5, [r0, #0x10]
	strh r5, [r0, #8]
	strh r5, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	strh r5, [r0]
	strh r5, [r1, #0x30]
	strh r5, [r1, #0x20]
	strh r5, [r1, #0x10]
	strh r5, [r1]
	ldr r0, .L08130BA8
	strh r5, [r0]
	ldr r0, .L08130BAC
	strh r5, [r0]
	mov r2, sl
	ldr r0, [r2]
	bl sub_080D34F0
	ldr r0, .L08130BB0
	strh r5, [r0]
.L08130B82:
	movs r0, #0x65
	bl Sound_Play
	b .L08130C1A
	.byte 0x00, 0x00
.L08130B8C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08130B90: .4byte 0x030069A8 @ IWRAM+0x69A8
.L08130B94: .4byte 0x030065FC @ IWRAM+0x65FC
.L08130B98: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L08130B9C: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08130BA0: .4byte 0x03006620 @ IWRAM+0x6620
.L08130BA4: .4byte 0x03006920 @ IWRAM+0x6920
.L08130BA8: .4byte 0x0300699C @ IWRAM+0x699C
.L08130BAC: .4byte 0x0300669C @ IWRAM+0x669C
.L08130BB0: .4byte 0x03006958 @ IWRAM+0x6958
.L08130BB4:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08130C1A
	mov r3, r8
	strh r3, [r7, #0x1c]
	ldr r1, .L08130BD8
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0x28
	bne .L08130BE4
	strh r2, [r1]
	ldr r0, .L08130BDC
	ldr r1, .L08130BE0
	ldr r1, [r1, #4]
	str r1, [r0]
	b .L08130BE8
.L08130BD8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08130BDC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08130BE0: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08130BE4:
	movs r0, #0x24
	strh r0, [r1]
.L08130BE8:
	ldr r1, .L08130C28
	movs r0, #0
	strh r0, [r1]
	ldr r2, .L08130C2C
	ldr r1, .L08130C30
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
	mov r5, sb
	strh r0, [r5]
	ldr r0, .L08130C34
	ldr r0, [r0]
	bl sub_080D34F0
	movs r0, #0x66
	bl Sound_Play
.L08130C1A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08130C28: .4byte 0x0300699C @ IWRAM+0x699C
.L08130C2C: .4byte 0x03006620 @ IWRAM+0x6620
.L08130C30: .4byte 0x03006920 @ IWRAM+0x6920
.L08130C34: .4byte 0x030068A4 @ IWRAM+0x68A4
