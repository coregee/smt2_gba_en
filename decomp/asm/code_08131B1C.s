	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_08131B1C
sub_08131B1C: @ 0x08131B1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	bl Money_Get
	adds r6, r0, #0
	ldr r0, .L08131B78
	ldr r7, [r0]
	ldr r0, .L08131B7C
	mov r8, r0
	ldrh r1, [r0]
	movs r0, #0xff
	bl Party_CountEquipped
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r1, sb
	str r1, [sp, #4]
	mov r2, r8
	ldrh r0, [r2]
	bl Inventory_GetCount
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov sl, r4
	ldr r1, .L08131B80
	movs r0, #0x15
	strh r0, [r1]
	movs r5, #1
	ldr r3, .L08131B84
	strh r5, [r3]
	ldr r1, .L08131B88
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq .L08131B8C
	subs r0, r2, #1
	strh r0, [r1]
	b .L0813216E
	.byte 0x00, 0x00
.L08131B78: .4byte 0x03006694 @ IWRAM+0x6694
.L08131B7C: .4byte 0x030069A8 @ IWRAM+0x69A8
.L08131B80: .4byte 0x030066A0 @ IWRAM+0x66A0
.L08131B84: .4byte 0x03006958 @ IWRAM+0x6958
.L08131B88: .4byte 0x030068D4 @ IWRAM+0x68D4
.L08131B8C:
	ldr r3, .L08131BAC
	ldrh r1, [r3]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L08131BB4
	ldr r0, .L08131BB0
	ldrh r1, [r0]
	eors r1, r5
	strh r1, [r0]
	mov r4, r8
	ldrh r0, [r4]
	bl sub_081305D8
	b .L0813216E
	.byte 0x00, 0x00
.L08131BAC: .4byte 0x030031C4 @ IWRAM+0x31C4
.L08131BB0: .4byte 0x030065E4 @ IWRAM+0x65E4
.L08131BB4:
	ldr r0, .L08131C40
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne .L08131BC6
	b .L08131F4C
.L08131BC6:
	ldr r0, .L08131C44
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x2a
	beq .L08131BD2
	b .L08131D68
.L08131BD2:
	ldr r0, .L08131C48
	movs r2, #0
	ldrsh r3, [r0, r2]
	adds r1, r7, #0
	muls r1, r3, r1
	adds r1, r1, r6
	ldr r2, .L08131C4C
	mov r8, r0
	cmp r1, r2
	bls .L08131BE8
	b .L08131EB4
.L08131BE8:
	ldr r0, .L08131C50
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne .L08131C88
	adds r0, r3, #1
	cmp r0, r4
	bgt .L08131C5C
	muls r0, r7, r0
	adds r0, r0, r6
	ldr r1, .L08131C54
	cmp r0, r1
	bls .L08131C04
	b .L08131EB4
.L08131C04:
	mov r2, r8
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x63
	ble .L08131C18
	movs r0, #0x63
	strh r0, [r2]
.L08131C18:
	ldr r4, .L08131C58
	mov r3, r8
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
	.byte 0x00, 0x00
.L08131C40: .4byte 0x03003964 @ IWRAM+0x3964
.L08131C44: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08131C48: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131C4C: .4byte 0x000F423E
.L08131C50: .4byte 0x030068BC @ IWRAM+0x68BC
.L08131C54: .4byte 0x000F423F
.L08131C58: .4byte 0x03006620 @ IWRAM+0x6620
.L08131C5C:
	mov r0, r8
	strh r4, [r0]
	ldr r4, .L08131C84
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131C84: .4byte 0x03006620 @ IWRAM+0x6620
.L08131C88:
	adds r0, r3, #0
	adds r0, #0xa
	cmp r0, r4
	bgt .L08131D2C
	muls r0, r7, r0
	adds r0, r0, r6
	ldr r1, .L08131CC8
	cmp r0, r1
	bhi .L08131CD0
	mov r4, r8
	ldrh r0, [r4]
	adds r0, #0xa
	strh r0, [r4]
	ldr r4, .L08131CCC
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r3, r8
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131CC8: .4byte 0x000F423F
.L08131CCC: .4byte 0x03006620 @ IWRAM+0x6620
.L08131CD0:
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r2, r7, #0
	muls r2, r0, r2
	movs r3, #0
	adds r1, r2, r6
	ldr r0, .L08131CE4
	ldr r4, .L08131CE8
	b .L08131CF8
.L08131CE4: .4byte 0x000F423F
.L08131CE8: .4byte 0x03006620 @ IWRAM+0x6620
.L08131CEC:
	adds r2, r2, r7
	adds r3, #1
	cmp r3, #9
	bhi .L08131CFE
	adds r1, r2, r6
	ldr r0, .L08131D28
.L08131CF8:
	cmp r1, r0
	bls .L08131CEC
	subs r3, #1
.L08131CFE:
	mov r1, r8
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r3, r8
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131D28: .4byte 0x000F423F
.L08131D2C:
	adds r0, r4, #0
	muls r0, r7, r0
	adds r0, r0, r6
	ldr r1, .L08131D60
	cmp r0, r1
	bhi .L08131CD0
	mov r2, r8
	strh r4, [r2]
	ldr r4, .L08131D64
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131D60: .4byte 0x000F423F
.L08131D64: .4byte 0x03006620 @ IWRAM+0x6620
.L08131D68:
	ldr r0, .L08131DD0
	ldrh r3, [r0]
	mov ip, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r8, r0
	cmp r1, #0x63
	bne .L08131D7A
	b .L08131EB4
.L08131D7A:
	ldr r1, .L08131DD4
	ldrh r5, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xa
	bne .L08131E64
	mov r0, sb
	adds r3, r4, r0
	mov r4, r8
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r0, r3, r2
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r0, r0, r1
	cmp r0, #0x63
	bgt .L08131E24
	adds r0, r2, r1
	muls r0, r7, r0
	cmp r0, r6
	bhi .L08131DDC
	mov r1, ip
	adds r0, r1, r5
	mov r2, r8
	strh r0, [r2]
	ldr r4, .L08131DD8
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131DD0: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131DD4: .4byte 0x030068BC @ IWRAM+0x68BC
.L08131DD8: .4byte 0x03006620 @ IWRAM+0x6620
.L08131DDC:
	mov r3, r8
	movs r4, #0
	ldrsh r0, [r3, r4]
	adds r2, r7, #0
	muls r2, r0, r2
	movs r3, #0
	ldr r4, .L08131E20
.L08131DEA:
	adds r3, #1
	adds r2, r2, r7
	cmp r2, r6
	bls .L08131DEA
	subs r0, r3, #1
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L08131E54
.L08131E20: .4byte 0x03006620 @ IWRAM+0x6620
.L08131E24:
	movs r0, #0x63
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r7, #0
	muls r0, r5, r0
	cmp r0, r6
	bhi .L08131DDC
	mov r3, r8
	strh r5, [r3]
	ldr r4, .L08131E60
	adds r0, r5, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r4, #0x34]
	adds r0, r5, #0
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L08131E54:
	str r0, [r4, #0x44]
	movs r0, #0x64
	bl Sound_Play
	b .L08131EB4
	.byte 0x00, 0x00
.L08131E60: .4byte 0x03006620 @ IWRAM+0x6620
.L08131E64:
	ldr r0, [sp, #4]
	add r0, sl
	mov r4, r8
	movs r3, #0
	ldrsh r2, [r4, r3]
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r0, r0, r1
	cmp r0, #0x63
	bgt .L08131EB4
	adds r0, r2, r1
	muls r0, r7, r0
	cmp r0, r6
	bhi .L08131EB4
	mov r1, ip
	adds r0, r1, r5
	mov r2, r8
	strh r0, [r2]
	ldr r4, .L08131F20
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x44]
	movs r0, #0x64
	bl Sound_Play
.L08131EB4:
	bl sub_081316FC
	ldr r2, .L08131F24
	ldr r0, .L08131F28
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	str r0, [r2]
	ldr r1, .L08131F2C
	cmp r0, r1
	bhi .L08131ECC
	b .L0813216E
.L08131ECC:
	str r1, [r2]
	ldr r2, .L08131F30
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0x2a
	beq .L08131EDA
	b .L0813216E
.L08131EDA:
	ldr r1, .L08131F34
	movs r0, #0
	strh r0, [r1]
	movs r4, #0
	movs r0, #1
	ldr r1, [sp]
	strh r0, [r1, #0x1c]
	movs r0, #0x47
	strh r0, [r2]
	ldr r0, .L08131F38
	strh r4, [r0]
	ldr r0, .L08131F3C
	strh r4, [r0]
	ldr r0, .L08131F40
	ldr r0, [r0]
	bl sub_080D34F0
	ldr r1, .L08131F20
	ldr r0, .L08131F44
	strh r4, [r0, #0x10]
	strh r4, [r0, #8]
	strh r4, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	strh r4, [r0]
	strh r4, [r1, #0x30]
	strh r4, [r1, #0x20]
	strh r4, [r1, #0x10]
	strh r4, [r1]
	ldr r0, .L08131F48
	strh r4, [r0]
	movs r0, #0x66
	bl Sound_Play
	b .L0813216E
.L08131F20: .4byte 0x03006620 @ IWRAM+0x6620
.L08131F24: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L08131F28: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131F2C: .4byte 0x000F423F
.L08131F30: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08131F34: .4byte 0x030068A0 @ IWRAM+0x68A0
.L08131F38: .4byte 0x0300699C @ IWRAM+0x699C
.L08131F3C: .4byte 0x0300669C @ IWRAM+0x669C
.L08131F40: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08131F44: .4byte 0x03006920 @ IWRAM+0x6920
.L08131F48: .4byte 0x03006958 @ IWRAM+0x6958
.L08131F4C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08132000
	ldr r0, .L08131F80
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0xa
	bne .L08131F8C
	ldr r0, .L08131F84
	movs r4, #0
	ldrsh r1, [r0, r4]
	mov r8, r0
	cmp r1, #0xa
	bgt .L08131F9E
	strh r5, [r0]
	ldr r1, .L08131F88
	movs r0, #1
	str r0, [r1, #0x34]
	str r2, [r1, #0x44]
	movs r0, #0x64
	bl Sound_Play
	b .L08131FD4
	.byte 0x00, 0x00
.L08131F80: .4byte 0x030068BC @ IWRAM+0x68BC
.L08131F84: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131F88: .4byte 0x03006620 @ IWRAM+0x6620
.L08131F8C:
	ldr r0, .L08131FF0
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	mov r8, r0
	cmp r1, #0
	ble .L08131FD4
.L08131F9E:
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r3]
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2]
	ldr r4, .L08131FF4
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x34]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r4, #0x44]
	movs r0, #0x64
	bl Sound_Play
.L08131FD4:
	bl sub_081316FC
	ldr r2, .L08131FF8
	ldr r0, .L08131FF0
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	str r0, [r2]
	ldr r1, .L08131FFC
	cmp r0, r1
	bhi .L08131FEC
	b .L0813216E
.L08131FEC:
	str r1, [r2]
	b .L0813216E
.L08131FF0: .4byte 0x030065FC @ IWRAM+0x65FC
.L08131FF4: .4byte 0x03006620 @ IWRAM+0x6620
.L08131FF8: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L08131FFC: .4byte 0x000F423F
.L08132000:
	ldrh r1, [r3]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L08132014
	ldr r0, .L08132010
	strh r5, [r0]
	b .L08132024
.L08132010: .4byte 0x030068BC @ IWRAM+0x68BC
.L08132014:
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L08132034
	ldr r1, .L08132030
	movs r0, #0xa
	strh r0, [r1]
.L08132024:
	bl sub_081316FC
	movs r0, #0x64
	bl Sound_Play
	b .L0813216E
.L08132030: .4byte 0x030068BC @ IWRAM+0x68BC
.L08132034:
	ldrh r0, [r3]
	movs r2, #1
	adds r4, r2, #0
	ands r4, r0
	cmp r4, #0
	beq .L08132124
	ldr r4, [sp]
	strh r2, [r4, #0x1c]
	ldr r4, .L08132060
	movs r0, #0
	ldrsh r1, [r4, r0]
	cmp r1, #0
	bne .L0813206C
	ldr r0, .L08132064
	strh r1, [r0]
	ldr r1, .L08132068
	movs r0, #0x35
	strh r0, [r1]
	movs r0, #0x66
	bl Sound_Play
	b .L081320C6
.L08132060: .4byte 0x030065FC @ IWRAM+0x65FC
.L08132064: .4byte 0x030068A0 @ IWRAM+0x68A0
.L08132068: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813206C:
	ldr r0, .L08132094
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x2a
	bne .L081320A0
	ldr r5, .L08132098
	mov r2, r8
	ldrh r0, [r2]
	bl sub_080C4C7C
	movs r3, #0
	ldrsh r1, [r4, r3]
	muls r0, r1, r0
	str r0, [r5]
	ldr r1, .L0813209C
	cmp r0, r1
	bls .L081320B2
	str r1, [r5]
	b .L081320B2
	.byte 0x00, 0x00
.L08132094: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08132098: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813209C: .4byte 0x000F423F
.L081320A0:
	ldr r2, .L081320F8
	movs r1, #0
	ldrsh r0, [r4, r1]
	muls r0, r7, r0
	str r0, [r2]
	ldr r1, .L081320FC
	cmp r0, r1
	bls .L081320B2
	str r1, [r2]
.L081320B2:
	movs r0, #0x65
	bl Sound_Play
	ldr r1, .L08132100
	movs r0, #0x27
	strh r0, [r1]
	ldr r1, .L08132104
	ldr r0, .L08132108
	ldrh r0, [r0]
	strh r0, [r1]
.L081320C6:
	ldr r0, .L0813210C
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L08132110
	strh r1, [r0]
	ldr r0, .L08132114
	ldr r0, [r0]
	bl sub_080D34F0
	ldr r2, .L08132118
	ldr r1, .L0813211C
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
	ldr r1, .L08132120
	strh r0, [r1]
	b .L0813216E
.L081320F8: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L081320FC: .4byte 0x000F423F
.L08132100: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08132104: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L08132108: .4byte 0x030069A8 @ IWRAM+0x69A8
.L0813210C: .4byte 0x0300699C @ IWRAM+0x699C
.L08132110: .4byte 0x0300669C @ IWRAM+0x669C
.L08132114: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08132118: .4byte 0x03006620 @ IWRAM+0x6620
.L0813211C: .4byte 0x03006920 @ IWRAM+0x6920
.L08132120: .4byte 0x03006958 @ IWRAM+0x6958
.L08132124:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0813216E
	ldr r0, .L08132180
	strh r4, [r0]
	ldr r3, [sp]
	strh r2, [r3, #0x1c]
	ldr r1, .L08132184
	movs r0, #0x26
	strh r0, [r1]
	ldr r0, .L08132188
	strh r4, [r0]
	ldr r0, .L0813218C
	strh r4, [r0]
	ldr r0, .L08132190
	ldr r0, [r0]
	bl sub_080D34F0
	ldr r1, .L08132194
	ldr r0, .L08132198
	strh r4, [r0, #0x10]
	strh r4, [r0, #8]
	strh r4, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	strh r4, [r0]
	strh r4, [r1, #0x30]
	strh r4, [r1, #0x20]
	strh r4, [r1, #0x10]
	strh r4, [r1]
	ldr r0, .L0813219C
	strh r4, [r0]
	movs r0, #0x66
	bl Sound_Play
.L0813216E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08132180: .4byte 0x030068A0 @ IWRAM+0x68A0
.L08132184: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08132188: .4byte 0x0300699C @ IWRAM+0x699C
.L0813218C: .4byte 0x0300669C @ IWRAM+0x669C
.L08132190: .4byte 0x030068A4 @ IWRAM+0x68A4
.L08132194: .4byte 0x03006620 @ IWRAM+0x6620
.L08132198: .4byte 0x03006920 @ IWRAM+0x6920
.L0813219C: .4byte 0x03006958 @ IWRAM+0x6958
