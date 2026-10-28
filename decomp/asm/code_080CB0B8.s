	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080CB0B8
sub_080CB0B8: @ 0x080CB0B8
.L080CB0B8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r0, .L080CB180
	mov r8, r0
	ldrh r0, [r0, #2]
	bl Status_GetCombatant
	adds r7, r0, #0
	mov r1, r8
	ldr r0, [r1, #0x3c]
	cmp r0, #0
	beq .L080CB0E0
	movs r1, #0
	bl DemonObj_End
	movs r0, #0
	mov r2, r8
	str r0, [r2, #0x3c]
.L080CB0E0:
	mov r3, r8
	ldrh r0, [r3, #2]
	bl sub_080C9388
	adds r6, r0, #0
	cmp r6, #1
	beq .L080CB0F0
	b .L080CB368
.L080CB0F0:
	ldrb r0, [r7, #0xc]
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L080CB184
	movs r1, #0xa
	movs r2, #0x20
	movs r3, #0
	bl SmallFont_DrawAscii
	movs r1, #0x18
	ldrsh r0, [r7, r1]
	movs r1, #0x60
	movs r2, #0x20
	movs r3, #4
	bl SmallFont_DrawNumber
	ldr r4, .L080CB188
	adds r0, r4, #0
	movs r1, #0x68
	movs r2, #0x20
	movs r3, #4
	bl SmallFont_DrawAscii
	movs r2, #0x1a
	ldrsh r0, [r7, r2]
	movs r1, #0x80
	movs r2, #0x20
	movs r3, #4
	bl SmallFont_DrawNumber
	ldr r0, .L080CB18C
	movs r1, #0xa
	movs r2, #0x2c
	movs r3, #0
	bl SmallFont_DrawAscii
	movs r3, #0x1c
	ldrsh r0, [r7, r3]
	movs r1, #0x60
	movs r2, #0x2c
	movs r3, #4
	bl SmallFont_DrawNumber
	adds r0, r4, #0
	movs r1, #0x68
	movs r2, #0x2c
	movs r3, #4
	bl SmallFont_DrawAscii
	movs r1, #0x1e
	ldrsh r0, [r7, r1]
	movs r1, #0x80
	movs r2, #0x2c
	movs r3, #4
	bl SmallFont_DrawNumber
	ldr r0, .L080CB190
	movs r1, #0xa
	movs r2, #0x38
	movs r3, #0
	bl SmallFont_DrawAscii
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080CB198
	ldr r0, .L080CB194
	b .L080CB292
	.byte 0x00, 0x00
.L080CB180: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080CB184: .4byte gUnknown_084F00D8
.L080CB188: .4byte gUnknown_084F00DC
.L080CB18C: .4byte gUnknown_084F00E0
.L080CB190: .4byte gUnknown_084F00E4
.L080CB194: .4byte gUnknown_084F00E8
.L080CB198:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r5
	cmp r0, #0
	beq .L080CB1AC
	ldr r0, .L080CB1A8
	b .L080CB292
	.byte 0x00, 0x00
.L080CB1A8: .4byte gUnknown_084F00F0
.L080CB1AC:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r5
	cmp r0, #0
	beq .L080CB1C0
	ldr r0, .L080CB1BC
	movs r1, #0x58
	b .L080CB294
.L080CB1BC: .4byte gUnknown_084F00F8
.L080CB1C0:
	movs r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080CB1D4
	ldr r0, .L080CB1D0
	movs r1, #0x58
	b .L080CB294
	.byte 0x00, 0x00
.L080CB1D0: .4byte gUnknown_084F0100
.L080CB1D4:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080CB1E8
	ldr r0, .L080CB1E4
	movs r1, #0x70
	b .L080CB294
.L080CB1E4: .4byte gUnknown_084F0108
.L080CB1E8:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r5
	cmp r0, #0
	beq .L080CB1FC
	ldr r0, .L080CB1F8
	movs r1, #0x58
	b .L080CB294
.L080CB1F8: .4byte gUnknown_084F010C
.L080CB1FC:
	ands r6, r5
	cmp r6, #0
	beq .L080CB20C
	ldr r0, .L080CB208
	b .L080CB292
	.byte 0x00, 0x00
.L080CB208: .4byte gUnknown_084F0114
.L080CB20C:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080CB220
	ldr r0, .L080CB21C
	b .L080CB292
	.byte 0x00, 0x00
.L080CB21C: .4byte gUnknown_084F011C
.L080CB220:
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0
	beq .L080CB230
	ldr r0, .L080CB22C
	b .L080CB292
.L080CB22C: .4byte gUnknown_084F0124
.L080CB230:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L080CB244
	ldr r0, .L080CB240
	movs r1, #0x68
	b .L080CB294
	.byte 0x00, 0x00
.L080CB240: .4byte gUnknown_084F012C
.L080CB244:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080CB258
	ldr r0, .L080CB254
	movs r1, #0x58
	b .L080CB294
.L080CB254: .4byte gUnknown_084F0134
.L080CB258:
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0
	beq .L080CB268
	ldr r0, .L080CB264
	b .L080CB292
.L080CB264: .4byte gUnknown_084F013C
.L080CB268:
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080CB278
	ldr r0, .L080CB274
	b .L080CB292
.L080CB274: .4byte gUnknown_084F0144
.L080CB278:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L080CB288
	ldr r0, .L080CB284
	b .L080CB292
.L080CB284: .4byte gUnknown_084F014C
.L080CB288:
	movs r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080CB2A4
	ldr r0, .L080CB2A0
.L080CB292:
	movs r1, #0x60
.L080CB294:
	movs r2, #0x38
	movs r3, #4
	bl SmallFont_DrawAscii
	b .L080CB2B0
	.byte 0x00, 0x00
.L080CB2A0: .4byte gUnknown_084F0154
.L080CB2A4:
	ldr r0, .L080CB34C
	movs r1, #0x68
	movs r2, #0x38
	movs r3, #4
	bl SmallFont_DrawAscii
.L080CB2B0:
	ldr r0, .L080CB350
	movs r1, #0xa
	movs r2, #0x44
	movs r3, #0
	bl SmallFont_DrawAscii
	ldr r0, [r7, #8]
	movs r1, #0x80
	movs r2, #0x44
	movs r3, #4
	bl SmallFont_DrawNumber
	ldr r0, .L080CB354
	movs r1, #0xa
	movs r2, #0x50
	movs r3, #0
	bl SmallFont_DrawAscii
	ldrb r0, [r7, #0xd]
	cmp r0, #0x63
	beq .L080CB2EE
	adds r0, #1
	bl Exp_GetForLevel
	ldr r1, [r7, #8]
	subs r0, r0, r1
	movs r1, #0x80
	movs r2, #0x50
	movs r3, #4
	bl SmallFont_DrawNumber
.L080CB2EE:
	mov r2, r8
	ldrh r0, [r2, #2]
	bl sub_080C93B4
	cmp r0, #1
	beq .L080CB2FC
	b .L080CB700
.L080CB2FC:
	ldr r0, .L080CB358
	movs r1, #0xa
	movs r2, #0x5c
	movs r3, #0
	bl SmallFont_DrawAscii
	ldr r0, .L080CB35C
	ldr r3, .L080CB360
	adds r0, r0, r3
	ldrb r0, [r0]
	movs r1, #0x80
	movs r2, #0x5c
	movs r3, #4
	bl SmallFont_DrawNumber
	ldr r0, .L080CB364
	movs r1, #0x70
	movs r2, #0x5c
	movs r3, #4
	bl SmallFont_DrawAscii
	movs r5, #0
	movs r4, #4
.L080CB32A:
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L080CB336
	adds r5, #1
.L080CB336:
	adds r4, #1
	cmp r4, #0xf
	ble .L080CB32A
	adds r0, r5, #0
	movs r1, #0x68
	movs r2, #0x5c
	movs r3, #4
	bl SmallFont_DrawNumber
	b .L080CB700
	.byte 0x00, 0x00
.L080CB34C: .4byte gUnknown_084F015C
.L080CB350: .4byte gUnknown_084F0164
.L080CB354: .4byte gUnknown_084F0168
.L080CB358: .4byte gUnknown_084F0170
.L080CB35C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080CB360: .4byte 0x00000AC3
.L080CB364: .4byte gUnknown_084F00DC
.L080CB368:
	ldrh r0, [r7, #0x12]
	bl sub_080C92AC
	cmp r0, #1
	bne .L080CB374
	b .L080CB6CA
.L080CB374:
	adds r0, r7, #0
	bl sub_080C99B8
	cmp r0, #1
	bne .L080CB454
	ldr r0, .L080CB430
	movs r1, #0x56
	movs r2, #0x1e
	movs r3, #0
	bl SmallFont_DrawAscii
	ldr r0, .L080CB434
	movs r1, #0x60
	movs r2, #0x28
	movs r3, #4
	bl SmallFont_DrawAscii
	ldr r0, .L080CB438
	movs r1, #0x56
	movs r2, #0x32
	movs r3, #0
	bl SmallFont_DrawAscii
	ldr r4, .L080CB43C
	adds r0, r4, #0
	movs r1, #0x62
	movs r2, #0x3c
	movs r3, #4
	bl SmallFont_DrawAscii
	ldr r5, .L080CB440
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0x3c
	movs r3, #4
	bl SmallFont_DrawAscii
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x3c
	movs r3, #4
	bl SmallFont_DrawAscii
	ldr r0, .L080CB444
	movs r1, #0x56
	movs r2, #0x46
	movs r3, #0
	bl SmallFont_DrawAscii
	adds r0, r4, #0
	movs r1, #0x62
	movs r2, #0x50
	movs r3, #4
	bl SmallFont_DrawAscii
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0x50
	movs r3, #4
	bl SmallFont_DrawAscii
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x50
	movs r3, #4
	bl SmallFont_DrawAscii
	ldr r0, .L080CB448
	movs r1, #0x56
	movs r2, #0x5a
	movs r3, #0
	bl SmallFont_DrawAscii
	ldr r4, .L080CB44C
	adds r0, r4, #0
	movs r1, #0x78
	movs r2, #0x64
	movs r3, #4
	bl SmallFont_DrawAscii
	ldr r0, .L080CB450
	movs r1, #0x56
	movs r2, #0x6e
	movs r3, #0
	bl SmallFont_DrawAscii
	adds r0, r4, #0
	movs r1, #0x78
	movs r2, #0x78
	movs r3, #4
	bl SmallFont_DrawAscii
	b .L080CB6CA
	.byte 0x00, 0x00
.L080CB430: .4byte gUnknown_084F0178
.L080CB434: .4byte gUnknown_084F017C
.L080CB438: .4byte gUnknown_084F00D8
.L080CB43C: .4byte gUnknown_084F0184
.L080CB440: .4byte gUnknown_084F00DC
.L080CB444: .4byte gUnknown_084F00E0
.L080CB448: .4byte gUnknown_084F00E4
.L080CB44C: .4byte gUnknown_084F0188
.L080CB450: .4byte gUnknown_084F0190
.L080CB454:
	ldrh r0, [r7, #0x12]
	bl Stock_FindByDemonId
	cmp r0, #0
	beq .L080CB46A
	ldrb r0, [r0, #0xc]
	bl Combatant_GetStatus
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b .L080CB46C
.L080CB46A:
	movs r5, #0
.L080CB46C:
	ldr r0, .L080CB4A0
	movs r1, #0x56
	movs r2, #0x1e
	movs r3, #0
	bl SmallFont_DrawAscii
	ldrh r0, [r7, #0x12]
	movs r1, #0x60
	movs r2, #0x28
	bl sub_080CD044
	ldrh r4, [r7, #0x18]
	ldrh r6, [r7, #0x1c]
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #7
	bne .L080CB4A4
	ldrh r0, [r7, #0x12]
	bl Stock_FindByDemonId
	ldrh r4, [r0, #0x18]
	ldrh r0, [r7, #0x12]
	bl Stock_FindByDemonId
	ldrh r6, [r0, #0x1c]
	b .L080CB500
.L080CB4A0: .4byte gUnknown_084F0178
.L080CB4A4:
	cmp r0, #6
	bne .L080CB500
	ldr r0, .L080CB584
	ldrh r0, [r0, #8]
	cmp r0, #2
	bne .L080CB500
	bl sub_08157C2C
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq .L080CB500
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080CB4DE
	movs r2, #0x1a
	ldrsh r0, [r7, r2]
	cmp r0, #0
	bge .L080CB4CE
	adds r0, #3
.L080CB4CE:
	asrs r0, r0, #2
	adds r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L080CB588
	cmp r4, r0
	bls .L080CB4DE
	adds r4, r0, #0
.L080CB4DE:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080CB500
	movs r3, #0x1e
	ldrsh r0, [r7, r3]
	cmp r0, #0
	bge .L080CB4F0
	adds r0, #3
.L080CB4F0:
	asrs r0, r0, #2
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L080CB588
	cmp r6, r0
	bls .L080CB500
	adds r6, r0, #0
.L080CB500:
	ldr r0, .L080CB58C
	movs r1, #0x56
	movs r2, #0x32
	movs r3, #0
	bl SmallFont_DrawAscii
	adds r0, r4, #0
	movs r1, #0x70
	movs r2, #0x3c
	movs r3, #4
	bl SmallFont_DrawNumber
	ldr r4, .L080CB590
	adds r0, r4, #0
	movs r1, #0x78
	movs r2, #0x3c
	movs r3, #4
	bl SmallFont_DrawAscii
	movs r1, #0x1a
	ldrsh r0, [r7, r1]
	movs r1, #0x90
	movs r2, #0x3c
	movs r3, #4
	bl SmallFont_DrawNumber
	ldr r0, .L080CB594
	movs r1, #0x56
	movs r2, #0x46
	movs r3, #0
	bl SmallFont_DrawAscii
	adds r0, r6, #0
	movs r1, #0x70
	movs r2, #0x50
	movs r3, #4
	bl SmallFont_DrawNumber
	adds r0, r4, #0
	movs r1, #0x78
	movs r2, #0x50
	movs r3, #4
	bl SmallFont_DrawAscii
	movs r2, #0x1e
	ldrsh r0, [r7, r2]
	movs r1, #0x90
	movs r2, #0x50
	movs r3, #4
	bl SmallFont_DrawNumber
	ldr r0, .L080CB598
	movs r1, #0x56
	movs r2, #0x5a
	movs r3, #0
	bl SmallFont_DrawAscii
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080CB5A0
	ldr r0, .L080CB59C
	movs r1, #0x78
	b .L080CB69C
	.byte 0x00, 0x00
.L080CB584: .4byte 0x0203B854 @ EWRAM+0x3B854
.L080CB588: .4byte 0x000003E7
.L080CB58C: .4byte gUnknown_084F00D8
.L080CB590: .4byte gUnknown_084F00DC
.L080CB594: .4byte gUnknown_084F00E0
.L080CB598: .4byte gUnknown_084F00E4
.L080CB59C: .4byte gUnknown_084F0194
.L080CB5A0:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r5
	cmp r0, #0
	beq .L080CB5B4
	ldr r0, .L080CB5B0
	b .L080CB69A
	.byte 0x00, 0x00
.L080CB5B0: .4byte gUnknown_084F00F0
.L080CB5B4:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r5
	cmp r0, #0
	beq .L080CB5C8
	ldr r0, .L080CB5C4
	movs r1, #0x68
	b .L080CB69C
.L080CB5C4: .4byte gUnknown_084F00F8
.L080CB5C8:
	movs r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080CB5DC
	ldr r0, .L080CB5D8
	movs r1, #0x68
	b .L080CB69C
	.byte 0x00, 0x00
.L080CB5D8: .4byte gUnknown_084F0100
.L080CB5DC:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080CB5F0
	ldr r0, .L080CB5EC
	movs r1, #0x80
	b .L080CB69C
.L080CB5EC: .4byte gUnknown_084F0108
.L080CB5F0:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r5
	cmp r0, #0
	beq .L080CB604
	ldr r0, .L080CB600
	movs r1, #0x68
	b .L080CB69C
.L080CB600: .4byte gUnknown_084F010C
.L080CB604:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080CB614
	ldr r0, .L080CB610
	b .L080CB69A
.L080CB610: .4byte gUnknown_084F0114
.L080CB614:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080CB628
	ldr r0, .L080CB624
	b .L080CB69A
	.byte 0x00, 0x00
.L080CB624: .4byte gUnknown_084F011C
.L080CB628:
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0
	beq .L080CB638
	ldr r0, .L080CB634
	b .L080CB69A
.L080CB634: .4byte gUnknown_084F0124
.L080CB638:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L080CB64C
	ldr r0, .L080CB648
	movs r1, #0x78
	b .L080CB69C
	.byte 0x00, 0x00
.L080CB648: .4byte gUnknown_084F012C
.L080CB64C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L080CB660
	ldr r0, .L080CB65C
	movs r1, #0x68
	b .L080CB69C
.L080CB65C: .4byte gUnknown_084F0134
.L080CB660:
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0
	beq .L080CB670
	ldr r0, .L080CB66C
	b .L080CB69A
.L080CB66C: .4byte gUnknown_084F013C
.L080CB670:
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080CB680
	ldr r0, .L080CB67C
	b .L080CB69A
.L080CB67C: .4byte gUnknown_084F0144
.L080CB680:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L080CB690
	ldr r0, .L080CB68C
	b .L080CB69A
.L080CB68C: .4byte gUnknown_084F014C
.L080CB690:
	movs r0, #8
	ands r5, r0
	cmp r5, #0
	beq .L080CB6AC
	ldr r0, .L080CB6A8
.L080CB69A:
	movs r1, #0x70
.L080CB69C:
	movs r2, #0x64
	movs r3, #4
	bl SmallFont_DrawAscii
	b .L080CB6B8
	.byte 0x00, 0x00
.L080CB6A8: .4byte gUnknown_084F0154
.L080CB6AC:
	ldr r0, .L080CB70C
	movs r1, #0x78
	movs r2, #0x64
	movs r3, #4
	bl SmallFont_DrawAscii
.L080CB6B8:
	ldr r0, .L080CB710
	movs r1, #0x56
	movs r2, #0x6e
	movs r3, #0
	bl SmallFont_DrawAscii
	ldrh r0, [r7, #0x12]
	bl sub_080CD0E4
.L080CB6CA:
	ldrh r1, [r7, #0x12]
	ldr r0, .L080CB714
	ldrh r2, [r0]
	rsbs r2, r2, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r3, #0x18
	bl DemonObj_Create
	mov r3, r8
	str r0, [r3, #0x3c]
	movs r1, #1
	bl sub_080C3E40
	ldr r2, .L080CB718
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0x10
	strh r1, [r0]
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
.L080CB700:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080CB70C: .4byte gUnknown_084F015C
.L080CB710: .4byte gUnknown_084F0190
.L080CB714: .4byte 0x03000004 @ IWRAM+0x4
.L080CB718: .4byte 0x03002DB0 @ IWRAM+0x2DB0
