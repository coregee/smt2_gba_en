	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080EEB94
sub_080EEB94: @ 0x080EEB94
.L080EEB94:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov sl, r1
	movs r0, #0
	str r0, [sp]
	ldr r0, [r5]
	mov sb, r0
	ldr r7, [r5, #4]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #8]
	mov r0, sb
	bl Combatant_GetIntelligence
	adds r4, r0, #0
	mov r0, sl
	bl sub_080ED7A4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	muls r4, r0, r4
	adds r0, r7, #0
	bl Combatant_GetIntelligence
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne .L080EEBD8
	movs r1, #1
.L080EEBD8:
	adds r0, r4, #0
	bl __divsi3
	adds r6, r0, #0
	ldr r0, .L080EEC90
	bl sub_080EDA7C
	mov r0, sb
	bl sub_080EFE60
	adds r1, r0, #0
	adds r0, r7, #0
	bl Combatant_GetAffinity
	adds r4, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	bl Battle_ApplyAffinity
	adds r6, r0, #0
	adds r0, r4, #0
	subs r0, #0xc
	cmp r0, #1
	bhi .L080EEC94
.L080EEC08:
	mov r7, sb
	ldr r0, [r5]
	str r0, [r5, #4]
	movs r0, #0xb7
	lsls r0, r0, #1
	str r0, [r5, #8]
	cmp r7, #0xf
	bgt .L080EEC1C
	adds r0, #1
	str r0, [r5, #8]
.L080EEC1C:
	mov r0, sl
	bl sub_080ED794
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L080EECE4
	adds r0, r7, #0
	bl Combatant_GetIntelligence
	adds r4, r0, #0
	mov r0, sl
	bl sub_080ED7A4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	muls r4, r0, r4
	adds r0, r7, #0
	bl Combatant_GetIntelligence
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne .L080EEC50
	movs r1, #1
.L080EEC50:
	adds r0, r4, #0
	bl __divsi3
	adds r6, r0, #0
	adds r0, r7, #0
	bl sub_080EFE60
	adds r1, r0, #0
	adds r0, r7, #0
	bl Combatant_GetAffinity
	adds r4, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	bl Battle_ApplyAffinity
	adds r6, r0, #0
	adds r0, r4, #0
	subs r0, #0xc
	cmp r0, #1
	bls .L080EEC86
	cmp r4, #0xf
	beq .L080EEC86
	cmp r4, #0xe
	beq .L080EEC86
	cmp r4, #0
	bne .L080EECE4
.L080EEC86:
	movs r6, #0
	movs r0, #0
	bl sub_080EDA7C
	b .L080EECE4
.L080EEC90: .4byte 0x0000FFFF
.L080EEC94:
	adds r0, r4, #0
	subs r0, #0xe
	cmp r0, #1
	bls .L080EECA0
	cmp r4, #0
	bne .L080EECE4
.L080EECA0:
	mov r0, sb
	bl sub_080C35E4
	adds r4, r0, #0
	mov r0, sb
	bl Combatant_GetChosenSkill
	mov r8, r0
	adds r0, r7, #0
	bl sub_080EFAB0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r4, #7
	bne .L080EECC6
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L080EEC08
.L080EECC6:
	cmp r4, #0xb
	bne .L080EECDC
	mov r0, r8
	cmp r0, #0x3f
	ble .L080EECDC
	cmp r0, #0x67
	bgt .L080EECDC
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L080EEC08
.L080EECDC:
	movs r6, #0
	movs r0, #0
	bl sub_080EDA7C
.L080EECE4:
	adds r0, r7, #0
	bl Combatant_GetStatus
	adds r4, r0, #0
	mov r0, sl
	bl sub_080ED794
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ands r4, r0
	cmp r4, #0
	beq .L080EED00
	movs r0, #1
	str r0, [sp]
.L080EED00:
	cmp r6, #0
	beq .L080EED50
	bl Random_Byte
	movs r1, #0x1f
	ands r1, r0
	cmp r1, r6
	bhs .L080EED50
	mov r0, sl
	bl sub_080ED6A4
	cmp r0, #7
	bne .L080EED1E
	cmp r7, #2
	ble .L080EED50
.L080EED1E:
	mov r0, sl
	bl sub_080ED794
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, r4, #0
	adds r0, r7, #0
	adds r1, r4, #0
	bl sub_080F3214
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080EED50
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq .L080EED4A
	adds r0, r7, #0
	bl Battle_GetMaxMp
	cmp r0, #0
	beq .L080EED50
.L080EED4A:
	adds r0, r5, #0
	bl sub_080EDA7C
.L080EED50:
	ldr r0, [sp]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
