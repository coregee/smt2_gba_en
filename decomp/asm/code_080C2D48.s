	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080C2D48
sub_080C2D48: @ 0x080C2D48
.L080C2D48:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, .L080C2D6C
	movs r4, #0xff
	ands r0, r4
	ldr r5, .L080C2D70
	adds r2, r3, r5
	strh r0, [r2]
	ands r1, r4
	ldr r0, .L080C2D74
	adds r3, r3, r0
	strh r1, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C2D6C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C2D70: .4byte 0x000018AC
.L080C2D74: .4byte 0x000018AE

	thumb_func_start sub_080C2D78
sub_080C2D78: @ 0x080C2D78
.L080C2D78:
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	asrs r0, r0, #8
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x18
	asrs r4, r4, #8
	lsrs r4, r4, #0x10
	movs r1, #0
	adds r2, r4, #0
	bl sub_080C12C0
	ldr r0, .L080C2DB8
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	movs r0, #0
	bl Encounter_SetCounter
	ldr r0, .L080C2DBC
	ldrh r0, [r0]
	adds r1, r4, #0
	bl sub_080C2D48
	bl sub_080C2CC0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2DB8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C2DBC: .4byte 0x03003FC4 @ IWRAM+0x3FC4

	thumb_func_start sub_080C2DC0
sub_080C2DC0: @ 0x080C2DC0
.L080C2DC0:
	push {lr}
	ldr r1, .L080C2DD8
	strh r0, [r1]
	movs r0, #0x14
	bl sub_080C1300
	ldr r1, .L080C2DDC
	movs r0, #0
	strh r0, [r1, #0x1e]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2DD8: .4byte 0x03004534 @ IWRAM+0x4534
.L080C2DDC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080C2DE0
sub_080C2DE0: @ 0x080C2DE0
.L080C2DE0:
	push {lr}
	ldr r2, .L080C2E00
	strh r0, [r2]
	ldr r0, .L080C2E04
	str r1, [r0]
	movs r0, #0x1c
	bl sub_080C1300
	ldr r1, .L080C2E08
	movs r0, #5
	str r0, [r1]
	ldr r1, .L080C2E0C
	movs r0, #0
	strh r0, [r1, #0x1e]
	pop {r0}
	bx r0
.L080C2E00: .4byte 0x03004534 @ IWRAM+0x4534
.L080C2E04: .4byte 0x0300453C @ IWRAM+0x453C
.L080C2E08: .4byte 0x03004544 @ IWRAM+0x4544
.L080C2E0C: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080C2E10
sub_080C2E10: @ 0x080C2E10
.L080C2E10:
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, .L080C2E34
	strh r0, [r2]
	ldr r0, .L080C2E38
	str r1, [r0]
	movs r0, #0x1b
	bl sub_080C1300
	ldr r1, .L080C2E3C
	movs r0, #0
	strh r0, [r1, #0x1e]
	ldr r1, .L080C2E40
	movs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
.L080C2E34: .4byte 0x03004534 @ IWRAM+0x4534
.L080C2E38: .4byte 0x03004628 @ IWRAM+0x4628
.L080C2E3C: .4byte 0x03004550 @ IWRAM+0x4550
.L080C2E40: .4byte 0x03003BB8 @ IWRAM+0x3BB8

	thumb_func_start sub_080C2E44
sub_080C2E44: @ 0x080C2E44
.L080C2E44:
	push {lr}
	ldr r2, .L080C2E64
	strh r0, [r2]
	ldr r0, .L080C2E68
	str r1, [r0]
	movs r0, #0x25
	bl sub_080C1300
	ldr r1, .L080C2E6C
	movs r0, #0
	strh r0, [r1, #0x1e]
	ldr r1, .L080C2E70
	movs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
.L080C2E64: .4byte 0x03004534 @ IWRAM+0x4534
.L080C2E68: .4byte 0x03004628 @ IWRAM+0x4628
.L080C2E6C: .4byte 0x03004550 @ IWRAM+0x4550
.L080C2E70: .4byte 0x03003BB8 @ IWRAM+0x3BB8

	thumb_func_start sub_080C2E74
sub_080C2E74: @ 0x080C2E74
.L080C2E74:
	push {r4, r5, lr}
	sub sp, #4
	ldr r1, .L080C2ED0
	ldr r0, .L080C2ED4
	str r0, [r1]
	ldr r0, .L080C2ED8
	str r0, [r1, #4]
	ldr r0, .L080C2EDC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080C2EE0
	str r0, [r1]
	ldr r0, .L080C2EE4
	str r0, [r1, #4]
	ldr r0, .L080C2EE8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, .L080C2EEC
	ldr r4, .L080C2EF0
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080C2EF4
	adds r2, r4, #0
	adds r2, #0x20
	str r5, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080C2EF8
	subs r4, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C2ED0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C2ED4: .4byte gUnknown_081BABB0
.L080C2ED8: .4byte 0x06011C00 @ VRAM+0x11C00
.L080C2EDC: .4byte 0x84000300
.L080C2EE0: .4byte gUnknown_081BB850
.L080C2EE4: .4byte 0x06012400 @ VRAM+0x12400
.L080C2EE8: .4byte 0x84000080
.L080C2EEC: .4byte gUnknown_081BB7B0
.L080C2EF0: .4byte 0x03002D10 @ IWRAM+0x2D10
.L080C2EF4: .4byte gUnknown_081BB7D0
.L080C2EF8: .4byte gUnknown_081BBA50

	thumb_func_start sub_080C2EFC
sub_080C2EFC: @ 0x080C2EFC
.L080C2EFC:
	push {r4, lr}
	ldr r4, .L080C2F28
	movs r0, #0
	strh r0, [r4]
	ldr r1, .L080C2F2C
	strh r0, [r1]
	movs r0, #0
	bl Combatant_GetAlignment
	cmp r0, #1
	bne .L080C2F16
	movs r0, #4
	strh r0, [r4]
.L080C2F16:
	ldr r1, .L080C2F30
	movs r0, #9
	strh r0, [r1]
	bl sub_080C2E74
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C2F28: .4byte 0x0203A448 @ EWRAM+0x3A448
.L080C2F2C: .4byte 0x0203A44A @ EWRAM+0x3A44A
.L080C2F30: .4byte 0x0203A44C @ EWRAM+0x3A44C

	thumb_func_start sub_080C2F34
sub_080C2F34: @ 0x080C2F34
	ldr r2, .L080C2F40
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080C2F40: .4byte 0x0203A44C @ EWRAM+0x3A44C

	thumb_func_start sub_080C2F44
sub_080C2F44: @ 0x080C2F44
.L080C2F44:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, .L080C2FC0
	ldrh r0, [r0, #0x36]
	cmp r0, #0
	bne .L080C303C
	ldr r1, .L080C2FC4
	ldr r5, .L080C2FC8
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, #0xe0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r2, .L080C2FCC
	ldrh r0, [r2]
	cmp r0, #9
	beq .L080C2F9E
	ldr r1, .L080C2FD0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r3, [sp]
	adds r1, r4, #0
	subs r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	adds r1, r6, #0
	subs r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xb
	adds r3, r7, #0
	bl Sprite_Draw
.L080C2F9E:
	ldr r0, .L080C2FD4
	ldr r4, [r0]
	movs r0, #3
	ands r4, r0
	cmp r4, #0
	bne .L080C3082
	movs r0, #0
	bl Combatant_GetAlignment
	adds r1, r0, #0
	cmp r1, #1
	beq .L080C2FF0
	cmp r1, #1
	bgt .L080C2FD8
	cmp r1, #0
	beq .L080C2FDE
	b .L080C3082
.L080C2FC0: .4byte 0x030069F0 @ IWRAM+0x69F0
.L080C2FC4: .4byte gUnknown_081A62F4
.L080C2FC8: .4byte 0x0203A448 @ EWRAM+0x3A448
.L080C2FCC: .4byte 0x0203A44C @ EWRAM+0x3A44C
.L080C2FD0: .4byte gUnknown_081A62B0
.L080C2FD4: .4byte 0x030031BC @ IWRAM+0x31BC
.L080C2FD8:
	cmp r1, #2
	beq .L080C302A
	b .L080C3082
.L080C2FDE:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L080C3082
	movs r0, #0xa
	strh r0, [r5]
	b .L080C3082
.L080C2FF0:
	ldr r2, .L080C3010
	ldrh r0, [r2]
	cmp r0, #0
	bne .L080C3014
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls .L080C3082
	movs r0, #0xa
	strh r0, [r5]
	strh r1, [r2]
	b .L080C3082
	.byte 0x00, 0x00
.L080C3010: .4byte 0x0203A44A @ EWRAM+0x3A44A
.L080C3014:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi .L080C3082
	movs r0, #8
	strh r0, [r5]
	strh r4, [r2]
	b .L080C3082
.L080C302A:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls .L080C3082
	strh r4, [r5]
	b .L080C3082
.L080C303C:
	ldr r3, .L080C308C
	ldr r0, .L080C3090
	ldr r2, [r0]
	lsrs r2, r2, #3
	movs r0, #7
	ands r2, r0
	lsls r1, r2, #1
	adds r1, r1, r3
	movs r3, #0x90
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, .L080C3094
	lsls r2, r2, #2
	adds r2, r2, r0
	ldr r0, [r2]
	str r3, [sp]
	adds r1, r4, #0
	subs r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	adds r1, r6, #0
	subs r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xa
	movs r3, #0
	bl Sprite_Draw
.L080C3082:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C308C: .4byte gUnknown_081A630C
.L080C3090: .4byte 0x030031BC @ IWRAM+0x31BC
.L080C3094: .4byte gUnknown_081A62D4

	thumb_func_start sub_080C3098
sub_080C3098: @ 0x080C3098
	push {lr}
	bl ScriptVM_RunAlt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C30A8
sub_080C30A8: @ 0x080C30A8
	movs r0, #0
	bx lr

	thumb_func_start sub_080C30AC
sub_080C30AC: @ 0x080C30AC
.L080C30AC:
	push {lr}
	adds r2, r0, #0
	cmp r2, #0
	ble .L080C30D8
	ldr r1, .L080C30CC
	ldr r0, .L080C30D0
	adds r3, r1, r0
	ldr r0, [r3]
	adds r0, r0, r2
	str r0, [r3]
	ldr r2, .L080C30D4
	cmp r0, r2
	bls .L080C30EC
	str r2, [r3]
	b .L080C30EC
	.byte 0x00, 0x00
.L080C30CC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C30D0: .4byte 0x00000AD8
.L080C30D4: .4byte 0x000F423F
.L080C30D8:
	ldr r1, .L080C30F8
	ldr r0, .L080C30FC
	adds r3, r1, r0
	ldr r0, [r3]
	adds r0, r0, r2
	str r0, [r3]
	cmp r0, #0
	bge .L080C30EC
	movs r0, #0
	str r0, [r3]
.L080C30EC:
	ldr r2, .L080C30FC
	adds r0, r1, r2
	ldr r0, [r0]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C30F8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C30FC: .4byte 0x00000AD8

	thumb_func_start sub_080C3100
sub_080C3100: @ 0x080C3100
.L080C3100:
	ldr r0, .L080C310C
	ldr r1, .L080C3110
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C310C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C3110: .4byte 0x00000AD8

	thumb_func_start sub_080C3114
sub_080C3114: @ 0x080C3114
.L080C3114:
	push {lr}
	adds r2, r0, #0
	cmp r2, #0
	ble .L080C3140
	ldr r1, .L080C3134
	ldr r0, .L080C3138
	adds r3, r1, r0
	ldr r0, [r3]
	adds r0, r0, r2
	str r0, [r3]
	ldr r2, .L080C313C
	cmp r0, r2
	bls .L080C3154
	str r2, [r3]
	b .L080C3154
	.byte 0x00, 0x00
.L080C3134: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C3138: .4byte 0x00000ADC
.L080C313C: .4byte 0x0001869F
.L080C3140:
	ldr r1, .L080C3160
	ldr r0, .L080C3164
	adds r3, r1, r0
	ldr r0, [r3]
	adds r0, r0, r2
	str r0, [r3]
	cmp r0, #0
	bge .L080C3154
	movs r0, #0
	str r0, [r3]
.L080C3154:
	ldr r2, .L080C3164
	adds r0, r1, r2
	ldr r0, [r0]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C3160: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C3164: .4byte 0x00000ADC

	thumb_func_start sub_080C3168
sub_080C3168: @ 0x080C3168
.L080C3168:
	ldr r0, .L080C3174
	ldr r1, .L080C3178
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C3174: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C3178: .4byte 0x00000ADC

	thumb_func_start sub_080C317C
sub_080C317C: @ 0x080C317C
.L080C317C:
	push {lr}
	ldr r0, .L080C3194
	ldr r0, [r0]
	cmp r0, #0x26
	beq .L080C31A8
	cmp r0, #0x26
	bls .L080C31A8
	cmp r0, #0x30
	beq .L080C3198
	cmp r0, #0x40
	beq .L080C31A0
	b .L080C31A8
.L080C3194: .4byte 0x03004614 @ IWRAM+0x4614
.L080C3198:
	ldr r0, .L080C319C
	b .L080C31AA
.L080C319C: .4byte 0x03005F8C @ IWRAM+0x5F8C
.L080C31A0:
	ldr r0, .L080C31A4
	b .L080C31AA
.L080C31A4: .4byte 0x03005F90 @ IWRAM+0x5F90
.L080C31A8:
	ldr r0, .L080C31B0
.L080C31AA:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C31B0: .4byte 0x03005F88 @ IWRAM+0x5F88

	thumb_func_start sub_080C31B4
sub_080C31B4: @ 0x080C31B4
.L080C31B4:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C317C
	adds r1, r0, #0
	cmp r4, #0
	ble .L080C31D8
	ldr r0, [r1]
	adds r0, r0, r4
	str r0, [r1]
	ldr r2, .L080C31D4
	cmp r0, r2
	bls .L080C31E6
	str r2, [r1]
	b .L080C31E6
	.byte 0x00, 0x00
.L080C31D4: .4byte 0x000F423F
.L080C31D8:
	ldr r0, [r1]
	adds r0, r0, r4
	str r0, [r1]
	cmp r0, #0
	bge .L080C31E6
	movs r0, #0
	str r0, [r1]
.L080C31E6:
	ldr r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C31F0
sub_080C31F0: @ 0x080C31F0
.L080C31F0:
	push {lr}
	bl sub_080C317C
	ldr r0, [r0]
	pop {r1}
	bx r1

	thumb_func_start sub_080C31FC
sub_080C31FC: @ 0x080C31FC
.L080C31FC:
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080C317C
	str r4, [r0]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080C320C
sub_080C320C: @ 0x080C320C
.L080C320C:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, .L080C3238
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq .L080C3222
	movs r0, #0xff
	ands r2, r0
.L080C3222:
	movs r3, #0
	ldr r4, .L080C323C
.L080C3226:
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq .L080C3240
	ldrh r0, [r1]
	cmp r0, r2
	bne .L080C3240
	adds r0, r1, #0
	b .L080C324A
	.byte 0x00, 0x00
.L080C3238: .4byte 0x030051AC @ IWRAM+0x51AC
.L080C323C: .4byte 0x00000159
.L080C3240:
	adds r3, #1
	adds r1, #4
	cmp r3, r4
	bls .L080C3226
	movs r0, #0
.L080C324A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C3250
sub_080C3250: @ 0x080C3250
.L080C3250:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq .L080C3264
	movs r0, #0xff
	ands r2, r0
.L080C3264:
	movs r1, #0
	ldr r0, .L080C3284
	ldr r3, .L080C3288
	adds r4, r0, r3
	adds r3, r0, #0
	ldr r6, .L080C328C
	ldr r5, .L080C3290
.L080C3272:
	ldrh r0, [r4]
	cmp r0, r2
	bne .L080C3294
	adds r0, r3, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080C3294
	adds r0, r1, #0
	b .L080C32A0
.L080C3284: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C3288: .4byte 0x00000AEC
.L080C328C: .4byte 0x00000AEE
.L080C3290: .4byte 0x00000159
.L080C3294:
	adds r4, #4
	adds r3, #4
	adds r1, #1
	cmp r1, r5
	bls .L080C3272
	movs r0, #0
.L080C32A0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C32A8
sub_080C32A8: @ 0x080C32A8
.L080C32A8:
	push {lr}
	ldr r1, .L080C32BC
	movs r2, #0
	ldr r3, .L080C32C0
.L080C32B0:
	ldrh r0, [r1, #2]
	cmp r0, #0
	bne .L080C32C4
	adds r0, r1, #0
	b .L080C32CE
	.byte 0x00, 0x00
.L080C32BC: .4byte 0x030051AC @ IWRAM+0x51AC
.L080C32C0: .4byte 0x00000159
.L080C32C4:
	adds r2, #1
	adds r1, #4
	cmp r2, r3
	bls .L080C32B0
	movs r0, #0
.L080C32CE:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C32D4
sub_080C32D4: @ 0x080C32D4
.L080C32D4:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080C32E8
	movs r0, #0xff
	ands r1, r0
.L080C32E8:
	adds r0, r1, #0
	bl sub_080C320C
	cmp r0, #0
	beq .L080C32F6
	ldrb r0, [r0, #2]
	b .L080C32F8
.L080C32F6:
	movs r0, #0
.L080C32F8:
	pop {r1}
	bx r1

	thumb_func_start sub_080C32FC
sub_080C32FC: @ 0x080C32FC
.L080C32FC:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080C3310
	movs r0, #0xff
	ands r1, r0
.L080C3310:
	adds r0, r1, #0
	bl sub_080C32D4
	movs r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x63
	bne .L080C3322
	movs r1, #1
.L080C3322:
	adds r0, r1, #0
	pop {r1}
	bx r1

	thumb_func_start sub_080C3328
sub_080C3328: @ 0x080C3328
.L080C3328:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080C333C
	movs r0, #0xff
	ands r5, r0
.L080C333C:
	adds r0, r5, #0
	bl sub_080C320C
	adds r4, r0, #0
	cmp r4, #0
	beq .L080C336C
	cmp r5, #0xcf
	bls .L080C3354
	ldrh r0, [r4, #2]
	cmp r0, #0x63
	beq .L080C337A
	b .L080C3376
.L080C3354:
	movs r0, #0xff
	adds r1, r5, #0
	bl sub_08131AB0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #2]
	adds r0, r1, r0
	cmp r0, #0x62
	bgt .L080C337A
	adds r0, r1, #1
	b .L080C3378
.L080C336C:
	bl sub_080C32A8
	adds r4, r0, #0
	strh r5, [r4]
	ldrh r0, [r4, #2]
.L080C3376:
	adds r0, #1
.L080C3378:
	strh r0, [r4, #2]
.L080C337A:
	ldr r1, .L080C33A4
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2d
	bhi .L080C338C
	adds r0, r5, #0
	bl sub_080C2764
.L080C338C:
	ldr r1, .L080C33A8
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi .L080C339E
	movs r0, #0
	bl Combatant_RecalcStats
.L080C339E:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C33A4: .4byte 0xFFFFFED4
.L080C33A8: .4byte 0xFFFFFEE0

	thumb_func_start sub_080C33AC
sub_080C33AC: @ 0x080C33AC
.L080C33AC:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L080C33C0
	movs r0, #0xff
	ands r5, r0
.L080C33C0:
	adds r0, r5, #0
	bl sub_080C320C
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_080C3250
	adds r1, r0, #0
	cmp r4, #0
	beq .L080C3404
	ldrh r0, [r4, #2]
	subs r0, #1
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C3400
	ldr r0, .L080C3430
	subs r2, r0, r1
	movs r1, #0
	cmp r1, r2
	bhs .L080C33FA
.L080C33EA:
	ldrh r0, [r4, #4]
	strh r0, [r4]
	ldrh r0, [r4, #6]
	strh r0, [r4, #2]
	adds r4, #4
	adds r1, #1
	cmp r1, r2
	blo .L080C33EA
.L080C33FA:
	movs r0, #0
	strh r0, [r4]
	strh r0, [r4, #2]
.L080C3400:
	cmp r4, #0
	bne .L080C3416
.L080C3404:
	ldr r1, .L080C3434
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2d
	bhi .L080C3416
	adds r0, r5, #0
	bl sub_080C2790
.L080C3416:
	ldr r1, .L080C3438
	adds r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi .L080C3428
	movs r0, #0
	bl Combatant_RecalcStats
.L080C3428:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C3430: .4byte 0x00000159
.L080C3434: .4byte 0xFFFFFED4
.L080C3438: .4byte 0xFFFFFEE0

	thumb_func_start sub_080C343C
sub_080C343C: @ 0x080C343C
.L080C343C:
	push {lr}
	adds r2, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #6
	bhi .L080C34AA
	lsls r0, r1, #2
	ldr r1, .L080C3454
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080C3454: .4byte gUnknown_080C3458
	.global gUnknown_080C3458
gUnknown_080C3458:
.L080C3458: @ jump table
	.4byte .L080C3474
	.4byte .L080C347C
	.4byte .L080C3484
	.4byte .L080C348C
	.4byte .L080C3494
	.4byte .L080C349C
	.4byte .L080C34A4
.L080C3474:
	adds r0, r2, #0
	adds r0, #0x20
	ldrb r0, [r0]
	b .L080C34AA
.L080C347C:
	adds r0, r2, #0
	adds r0, #0x21
	ldrb r0, [r0]
	b .L080C34AA
.L080C3484:
	adds r0, r2, #0
	adds r0, #0x22
	ldrb r0, [r0]
	b .L080C34AA
.L080C348C:
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r0, [r0]
	b .L080C34AA
.L080C3494:
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	b .L080C34AA
.L080C349C:
	adds r0, r2, #0
	adds r0, #0x25
	ldrb r0, [r0]
	b .L080C34AA
.L080C34A4:
	adds r0, r2, #0
	adds r0, #0x26
	ldrb r0, [r0]
.L080C34AA:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C34B0
sub_080C34B0: @ 0x080C34B0
.L080C34B0:
	push {lr}
	adds r3, r0, #0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r0, #6
	bhi .L080C3516
	lsls r0, r0, #2
	ldr r1, .L080C34CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080C34CC: .4byte gUnknown_080C34D0
	.global gUnknown_080C34D0
gUnknown_080C34D0:
.L080C34D0: @ jump table
	.4byte .L080C34EC
	.4byte .L080C34F2
	.4byte .L080C34F8
	.4byte .L080C34FE
	.4byte .L080C3504
	.4byte .L080C350A
	.4byte .L080C3510
.L080C34EC:
	adds r0, r3, #0
	adds r0, #0x20
	b .L080C3514
.L080C34F2:
	adds r0, r3, #0
	adds r0, #0x21
	b .L080C3514
.L080C34F8:
	adds r0, r3, #0
	adds r0, #0x22
	b .L080C3514
.L080C34FE:
	adds r0, r3, #0
	adds r0, #0x23
	b .L080C3514
.L080C3504:
	adds r0, r3, #0
	adds r0, #0x24
	b .L080C3514
.L080C350A:
	adds r0, r3, #0
	adds r0, #0x25
	b .L080C3514
.L080C3510:
	adds r0, r3, #0
	adds r0, #0x26
.L080C3514:
	strb r2, [r0]
.L080C3516:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C351C
sub_080C351C: @ 0x080C351C
.L080C351C:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, .L080C355C
	bl Party_GetMember
	adds r1, r0, #0
	movs r3, #0
	movs r4, #0
	movs r2, #0
.L080C3530:
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	beq .L080C3542
	adds r3, #1
	movs r6, #0x12
	ldrsh r0, [r1, r6]
	cmp r0, r5
	bne .L080C3542
	adds r4, #1
.L080C3542:
	adds r2, #1
	adds r1, #0x80
	cmp r2, #0xb
	bls .L080C3530
	movs r0, #0
	cmp r3, #0xc
	beq .L080C3556
	cmp r4, #0
	bne .L080C3556
	movs r0, #1
.L080C3556:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080C355C: .4byte 0x00008004

	thumb_func_start sub_080C3560
sub_080C3560: @ 0x080C3560
.L080C3560:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L080C3584
	bl Party_GetMember
	adds r1, r0, #0
	movs r2, #0
.L080C3570:
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	beq .L080C3588
	movs r3, #0x12
	ldrsh r0, [r1, r3]
	cmp r0, r4
	bne .L080C3588
	adds r0, r1, #0
	b .L080C3592
	.byte 0x00, 0x00
.L080C3584: .4byte 0x00008004
.L080C3588:
	adds r2, #1
	adds r1, #0x80
	cmp r2, #0xb
	bls .L080C3570
	movs r0, #0
.L080C3592:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080C3598
sub_080C3598: @ 0x080C3598
	push {lr}
	lsls r0, r0, #0x10
	ldr r1, .L080C35BC
	ldr r2, .L080C35C0
	adds r1, r1, r2
	lsrs r0, r0, #0x10
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bls .L080C35B6
	movs r0, #0xc
	strb r0, [r1]
.L080C35B6:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C35BC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C35C0: .4byte 0x00000AC3

	thumb_func_start sub_080C35C4
sub_080C35C4: @ 0x080C35C4
.L080C35C4:
	push {r4, lr}
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	ldr r1, .L080C35E0
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	strb r4, [r0, #0x17]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C35E0: .4byte 0xFFFF8000

	thumb_func_start sub_080C35E4
sub_080C35E4: @ 0x080C35E4
.L080C35E4:
	push {lr}
	ldr r1, .L080C35FC
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrb r0, [r0, #0x17]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
.L080C35FC: .4byte 0xFFFF8000

	thumb_func_start sub_080C3600
sub_080C3600: @ 0x080C3600
.L080C3600:
	push {r4, lr}
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	ldr r1, .L080C361C
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	strb r4, [r0, #0x16]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C361C: .4byte 0xFFFF8000

	thumb_func_start sub_080C3620
sub_080C3620: @ 0x080C3620
.L080C3620:
	push {lr}
	ldr r1, .L080C3638
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	ldrb r0, [r0, #0x16]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
.L080C3638: .4byte 0xFFFF8000

	thumb_func_start sub_080C363C
sub_080C363C: @ 0x080C363C
.L080C363C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, .L080C3668
	movs r3, #0xa2
	lsls r3, r3, #4
	adds r2, r2, r3
	adds r1, r1, r2
	movs r3, #0
	ldrsb r3, [r1, r3]
	adds r0, r0, r2
	ldrb r2, [r0]
	strb r2, [r1]
	strb r3, [r0]
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	pop {r0}
	bx r0
.L080C3668: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_080C366C
sub_080C366C: @ 0x080C366C
.L080C366C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r5, #0
	movs r2, #0xff
.L080C367C:
	mov r0, sp
	adds r1, r0, r5
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r5, #1
	cmp r5, #5
	bls .L080C367C
	movs r5, #0
	ldr r2, .L080C36CC
.L080C3690:
	mov r1, sp
	adds r0, r1, r5
	adds r1, r5, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r5, #1
	cmp r5, #5
	bls .L080C3690
	movs r5, #0
	movs r2, #1
	rsbs r2, r2, #0
	mov sl, r2
	mov r4, sp
.L080C36AA:
	ldrb r0, [r4]
	mov sb, r0
	ldrb r1, [r4, #3]
	mov r8, r1
	lsls r0, r0, #0x18
	asrs r2, r0, #0x18
	cmp r2, sl
	bne .L080C36D0
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	beq .L080C3702
	strb r1, [r4]
	movs r0, #0xff
	strb r0, [r4, #3]
	b .L080C3702
	.byte 0x00, 0x00
.L080C36CC: .4byte 0x030050E0 @ IWRAM+0x50E0
.L080C36D0:
	mov r3, r8
	lsls r0, r3, #0x18
	asrs r6, r0, #0x18
	cmp r6, #0
	blt .L080C3702
	adds r0, r2, #0
	bl Combatant_GetStatus
	movs r7, #0xa0
	lsls r7, r7, #8
	adds r1, r7, #0
	ands r1, r0
	cmp r1, #0
	beq .L080C3702
	adds r0, r6, #0
	bl Combatant_GetStatus
	adds r1, r7, #0
	ands r1, r0
	cmp r1, #0
	bne .L080C3702
	mov r0, r8
	strb r0, [r4]
	mov r1, sb
	strb r1, [r4, #3]
.L080C3702:
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	bls .L080C36AA
	movs r5, #0
	ldr r2, .L080C3738
.L080C370E:
	adds r0, r5, r2
	mov r3, sp
	adds r1, r3, r5
	ldrb r1, [r1]
	strb r1, [r0]
	adds r5, #1
	cmp r5, #5
	bls .L080C370E
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C3738: .4byte 0x030050E0 @ IWRAM+0x50E0

	thumb_func_start sub_080C373C
sub_080C373C: @ 0x080C373C
.L080C373C:
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	movs r3, #0
	ldr r4, .L080C3764
	adds r6, r4, #2
.L080C3748:
	lsls r0, r3, #2
	adds r2, r0, r4
	ldrh r1, [r2]
	cmp r1, #0
	beq .L080C3768
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, r5
	bne .L080C3768
	adds r0, r1, #1
	strh r0, [r2]
	adds r0, r3, #0
	b .L080C37B8
	.byte 0x00, 0x00
.L080C3764: .4byte 0x02036074 @ EWRAM+0x36074
.L080C3768:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #7
	bls .L080C3748
	ldr r2, .L080C37A4
	ldr r1, [r2, #0x18]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r1, r0, #0x1f
	ldr r0, [r2, #0x1c]
	cmp r0, #0
	beq .L080C3784
	adds r1, #1
.L080C3784:
	adds r3, r1, #0
	cmp r3, #5
	bhi .L080C37B6
	ldr r4, .L080C37A8
	adds r6, r4, #2
.L080C378E:
	lsls r2, r3, #2
	adds r1, r2, r4
	ldrh r0, [r1]
	cmp r0, #0
	bne .L080C37AC
	adds r0, #1
	strh r0, [r1]
	adds r0, r2, r6
	strh r5, [r0]
	adds r0, r3, #0
	b .L080C37B8
.L080C37A4: .4byte 0x02036094 @ EWRAM+0x36094
.L080C37A8: .4byte 0x02036074 @ EWRAM+0x36074
.L080C37AC:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #5
	bls .L080C378E
.L080C37B6:
	movs r0, #0
.L080C37B8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C37C0
sub_080C37C0: @ 0x080C37C0
.L080C37C0:
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r4, .L080C37D8
.L080C37C8:
	lsls r0, r2, #2
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0
	bne .L080C37DC
	str r3, [r1]
	b .L080C37E6
	.byte 0x00, 0x00
.L080C37D8: .4byte 0x02036094 @ EWRAM+0x36094
.L080C37DC:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #7
	bls .L080C37C8
.L080C37E6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080C37EC
sub_080C37EC: @ 0x080C37EC
.L080C37EC:
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r4, .L080C3804
	movs r5, #0
.L080C37F6:
	lsls r0, r2, #2
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, r3
	bne .L080C3808
	str r5, [r1]
	b .L080C3812
.L080C3804: .4byte 0x02036094 @ EWRAM+0x36094
.L080C3808:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #7
	bls .L080C37F6
.L080C3812:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080C3818
sub_080C3818: @ 0x080C3818
.L080C3818:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C388E
	movs r5, #0
	ldr r6, .L080C384C
	movs r7, #0
.L080C3826:
	subs r4, r5, #6
	cmp r4, #1
	bhi .L080C3854
	ldr r0, [r6]
	cmp r0, #0
	beq .L080C3884
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	bl sub_080E9044
	ldr r1, .L080C3850
	lsls r0, r4, #2
	adds r1, r0, r1
	ldr r0, [r1]
	cmp r0, #0
	beq .L080C3848
	str r7, [r1]
.L080C3848:
	str r7, [r6]
	b .L080C3884
.L080C384C: .4byte 0x02036094 @ EWRAM+0x36094
.L080C3850: .4byte 0x030069C0 @ IWRAM+0x69C0
.L080C3854:
	ldr r1, [r6]
	ldr r2, .L080C3878
	adds r0, r2, #0
	ldrh r2, [r1, #0x2a]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L080C387C
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeToBlackTagged
	b .L080C3884
	.byte 0x00, 0x00
.L080C3878: .4byte 0xFFFFFE3E
.L080C387C:
	cmp r1, #0
	beq .L080C3884
	movs r0, #1
	str r0, [r1, #0xc]
.L080C3884:
	adds r6, #4
	adds r5, #1
	cmp r5, #7
	bls .L080C3826
	b .L080C38CE
.L080C388E:
	movs r5, #0
	ldr r4, .L080C38AC
	ldr r6, .L080C38B0
.L080C3894:
	subs r0, r5, #6
	cmp r0, #1
	bhi .L080C38B4
	ldr r0, [r4]
	cmp r0, #0
	beq .L080C38C0
	lsrs r1, r6, #0x10
	bl sub_080E9044
	movs r0, #0
	str r0, [r4]
	b .L080C38C0
.L080C38AC: .4byte 0x02036094 @ EWRAM+0x36094
.L080C38B0: .4byte 0xFFFA0000
.L080C38B4:
	ldr r0, [r4]
	cmp r0, #0
	beq .L080C38C0
	movs r1, #0
	bl sub_080C48F0
.L080C38C0:
	adds r4, #4
	movs r0, #0x80
	lsls r0, r0, #9
	adds r6, r6, r0
	adds r5, #1
	cmp r5, #7
	bls .L080C3894
.L080C38CE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080C38D4
sub_080C38D4: @ 0x080C38D4
.L080C38D4:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r1, #0
	ldr r0, .L080C38F4
	adds r3, r0, #2
	adds r2, r0, #0
.L080C38E2:
	ldrh r0, [r2]
	cmp r0, #1
	bls .L080C38F8
	ldrh r0, [r3]
	cmp r0, r4
	bne .L080C38F8
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	b .L080C3904
.L080C38F4: .4byte 0x02036074 @ EWRAM+0x36074
.L080C38F8:
	adds r3, #4
	adds r2, #4
	adds r1, #1
	cmp r1, #7
	bls .L080C38E2
	ldr r0, .L080C390C
.L080C3904:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C390C: .4byte 0x0000FFFF

	thumb_func_start sub_080C3910
sub_080C3910: @ 0x080C3910
	ldr r1, .L080C3924
	ldr r0, .L080C3928
	str r0, [r1]
	ldr r0, .L080C392C
	str r0, [r1, #4]
	ldr r0, .L080C3930
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C3924: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C3928: .4byte 0x02001000 @ EWRAM+0x1000
.L080C392C: .4byte 0x06016000 @ VRAM+0x16000
.L080C3930: .4byte 0x84000400

	thumb_func_start sub_080C3934
sub_080C3934: @ 0x080C3934
	ldr r1, .L080C3948
	ldr r0, .L080C394C
	str r0, [r1]
	ldr r0, .L080C3950
	str r0, [r1, #4]
	ldr r0, .L080C3954
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C3948: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C394C: .4byte 0x02002000 @ EWRAM+0x2000
.L080C3950: .4byte 0x06017000 @ VRAM+0x17000
.L080C3954: .4byte 0x84000400

	thumb_func_start sub_080C3958
sub_080C3958: @ 0x080C3958
	ldr r1, .L080C396C
	ldr r0, .L080C3970
	str r0, [r1]
	ldr r0, .L080C3974
	str r0, [r1, #4]
	ldr r0, .L080C3978
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C396C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C3970: .4byte 0x02003000 @ EWRAM+0x3000
.L080C3974: .4byte 0x06015000 @ VRAM+0x15000
.L080C3978: .4byte 0x84000400

	thumb_func_start Demon_LoadGfxForTask
Demon_LoadGfxForTask: @ 0x080C397C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r1, #0
	adds r4, r2, #0
	adds r5, r3, #0
	bl Task_GetParent
	adds r0, #0x24
	ldrh r2, [r0, #6]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	ldr r2, .L080C39C8
	adds r6, r1, r2
	lsls r2, r5, #2
	lsls r4, r4, #3
	adds r2, r2, r4
	adds r1, r6, #0
	adds r1, #0xc
	adds r1, r1, r2
	ldr r2, [r1]
	ldrh r1, [r0, #2]
	ldrh r0, [r0, #4]
	cmp r0, #0
	bne .L080C39B0
	b .L080C3B6E
.L080C39B0:
	cmp r1, #0
	beq .L080C39B8
	cmp r1, #3
	bne .L080C3A4C
.L080C39B8:
	cmp r5, #0
	bne .L080C39D0
	ldr r1, .L080C39CC
	adds r0, r2, #0
	bl HuffUnComp
	b .L080C39D8
	.byte 0x00, 0x00
.L080C39C8: .4byte gDemonGfxRecords
.L080C39CC: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080C39D0:
	ldr r0, .L080C3A10
	ldr r1, .L080C3A14
	bl LZ77UnCompWram
.L080C39D8:
	cmp r5, #1
	beq .L080C39DE
	b .L080C3B6E
.L080C39DE:
	cmp r7, #0
	bne .L080C3A3E
	bl Palette_IsBg13Black
	cmp r0, #0
	bne .L080C3A20
	ldr r1, [r6, #4]
	ldr r2, .L080C3A18
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, [r6, #4]
	ldr r2, .L080C3A1C
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	b .L080C3A3E
	.byte 0x00, 0x00
.L080C3A10: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080C3A14: .4byte 0x02001000 @ EWRAM+0x1000
.L080C3A18: .4byte 0x03002D70 @ IWRAM+0x2D70
.L080C3A1C: .4byte 0x03003170 @ IWRAM+0x3170
.L080C3A20:
	ldr r1, [r6, #4]
	ldr r2, .L080C3A44
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xf0
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
.L080C3A3E:
	ldr r0, .L080C3A48
	b .L080C3AD4
	.byte 0x00, 0x00
.L080C3A44: .4byte 0x03002D70 @ IWRAM+0x2D70
.L080C3A48: .4byte sub_080C3910
.L080C3A4C:
	cmp r1, #1
	bne .L080C3AE4
	cmp r5, #0
	bne .L080C3A64
	ldr r1, .L080C3A60
	adds r0, r2, #0
	bl HuffUnComp
	b .L080C3A6C
	.byte 0x00, 0x00
.L080C3A60: .4byte 0x0200BFC8 @ EWRAM+0xBFC8
.L080C3A64:
	ldr r0, .L080C3AA4
	ldr r1, .L080C3AA8
	bl LZ77UnCompWram
.L080C3A6C:
	cmp r5, #1
	beq .L080C3A72
	b .L080C3B6E
.L080C3A72:
	cmp r7, #0
	bne .L080C3AD2
	bl Palette_IsBg13Black
	cmp r0, #0
	bne .L080C3AB4
	ldr r1, [r6, #4]
	ldr r2, .L080C3AAC
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, [r6, #4]
	ldr r2, .L080C3AB0
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	b .L080C3AD2
	.byte 0x00, 0x00
.L080C3AA4: .4byte 0x0200BFC8 @ EWRAM+0xBFC8
.L080C3AA8: .4byte 0x02002000 @ EWRAM+0x2000
.L080C3AAC: .4byte 0x03002D90 @ IWRAM+0x2D90
.L080C3AB0: .4byte 0x03003190 @ IWRAM+0x3190
.L080C3AB4:
	ldr r1, [r6, #4]
	ldr r2, .L080C3ADC
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xf8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
.L080C3AD2:
	ldr r0, .L080C3AE0
.L080C3AD4:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080C3B6E
.L080C3ADC: .4byte 0x03002D90 @ IWRAM+0x2D90
.L080C3AE0: .4byte sub_080C3934
.L080C3AE4:
	cmp r1, #2
	bne .L080C3B6E
	cmp r5, #0
	bne .L080C3AFC
	ldr r1, .L080C3AF8
	adds r0, r2, #0
	bl HuffUnComp
	b .L080C3B04
	.byte 0x00, 0x00
.L080C3AF8: .4byte 0x0200CFC8 @ EWRAM+0xCFC8
.L080C3AFC:
	ldr r0, .L080C3B38
	ldr r1, .L080C3B3C
	bl LZ77UnCompWram
.L080C3B04:
	cmp r5, #1
	bne .L080C3B6E
	cmp r7, #0
	bne .L080C3B66
	bl Palette_IsBg13Black
	cmp r0, #0
	bne .L080C3B48
	ldr r1, [r6, #4]
	ldr r2, .L080C3B40
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, [r6, #4]
	ldr r2, .L080C3B44
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	b .L080C3B66
.L080C3B38: .4byte 0x0200CFC8 @ EWRAM+0xCFC8
.L080C3B3C: .4byte 0x02003000 @ EWRAM+0x3000
.L080C3B40: .4byte 0x03002D50 @ IWRAM+0x2D50
.L080C3B44: .4byte 0x03003150 @ IWRAM+0x3150
.L080C3B48:
	ldr r1, [r6, #4]
	ldr r2, .L080C3B78
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
.L080C3B66:
	ldr r0, .L080C3B7C
	movs r1, #1
	bl VBlankTask_AddCounted
.L080C3B6E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C3B78: .4byte 0x03002D50 @ IWRAM+0x2D50
.L080C3B7C: .4byte sub_080C3958

	thumb_func_start sub_080C3B80
sub_080C3B80: @ 0x080C3B80
	push {lr}
	adds r0, #0x24
	ldrh r1, [r0, #2]
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq .L080C3BC0
	cmp r1, #0
	beq .L080C3B94
	cmp r1, #3
	bne .L080C3B9A
.L080C3B94:
	movs r0, #0xf0
	lsls r0, r0, #1
	b .L080C3BA2
.L080C3B9A:
	cmp r1, #1
	bne .L080C3BAE
	movs r0, #0xf8
	lsls r0, r0, #1
.L080C3BA2:
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeToBlackTagged
	b .L080C3BC0
.L080C3BAE:
	cmp r1, #2
	bne .L080C3BC0
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeToBlackTagged
.L080C3BC0:
	pop {r0}
	bx r0

	thumb_func_start sub_080C3BC4
sub_080C3BC4: @ 0x080C3BC4
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r5, [r4, #2]
	ldrb r0, [r4, #2]
	bl sub_080E8AA0
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq .L080C3C60
	cmp r5, #0
	beq .L080C3BE2
	cmp r5, #3
	bne .L080C3C0A
.L080C3BE2:
	ldrh r3, [r4, #0x10]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [sp]
	ldrh r0, [r4, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r4, #0xa]
	adds r0, #0x58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r1, #0
	movs r1, #1
	movs r2, #0xe
	bl Sprite_Draw
	b .L080C3C60
.L080C3C0A:
	cmp r5, #1
	bne .L080C3C36
	ldrh r3, [r4, #0x10]
	movs r0, #0xe0
	lsls r0, r0, #2
	str r0, [sp]
	ldrh r0, [r4, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r4, #0xa]
	adds r0, #0x58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r1, #0
	movs r1, #1
	movs r2, #0xf
	bl Sprite_Draw
	b .L080C3C60
.L080C3C36:
	cmp r5, #2
	bne .L080C3C60
	ldrh r3, [r4, #0x10]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp]
	ldrh r0, [r4, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r4, #0xa]
	adds r0, #0x58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r1, #0
	movs r1, #1
	movs r2, #0xd
	bl Sprite_Draw
.L080C3C60:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080C3C68
sub_080C3C68: @ 0x080C3C68
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r5, r0, #0
	adds r5, #0x24
	ldrh r6, [r5, #2]
	adds r7, r6, #0
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl sub_080E8AA0
	adds r4, r0, #0
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq .L080C3D54
	ldrh r0, [r4, #0x12]
	bl Demon_GetGfxRecord
	movs r2, #0
	movs r1, #1
	strb r1, [r4, #1]
	strb r2, [r4, #2]
	ldr r0, [r0, #8]
	ldr r0, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0xc]
	ldr r1, .L080C3CF0
	cmp r6, #2
	bne .L080C3CA2
	ldr r1, .L080C3CF4
.L080C3CA2:
	ldr r0, [r0]
	str r0, [sp, #0x10]
	ldr r0, [r1, #4]
	str r0, [sp, #0x14]
	add r0, sp, #0x10
	bl sub_081583F4
	ldr r1, .L080C3CF0
	cmp r6, #2
	bne .L080C3CB8
	ldr r1, .L080C3CF4
.L080C3CB8:
	ldr r0, .L080C3CF8
	str r0, [sp, #0x10]
	ldr r0, [r1, #4]
	str r0, [sp, #0x14]
	cmp r6, #0
	bne .L080C3CFC
	ldrh r3, [r5, #0x10]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [sp]
	ldrh r0, [r5, #8]
	subs r0, #0xd5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5, #0xa]
	adds r0, #0x88
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r2, #0xe
	bl Sprite_DrawSharedAffine
	b .L080C3D54
	.byte 0x00, 0x00
.L080C3CF0: .4byte gUnknown_08002C20
.L080C3CF4: .4byte gUnknown_08002C58
.L080C3CF8: .4byte 0x03003800 @ IWRAM+0x3800
.L080C3CFC:
	cmp r7, #1
	bne .L080C3D2A
	ldrh r3, [r5, #0x10]
	movs r0, #0xe0
	lsls r0, r0, #2
	str r0, [sp]
	ldrh r0, [r5, #8]
	subs r0, #0xd9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5, #0xa]
	adds r0, #0x88
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r2, #0xf
	bl Sprite_DrawSharedAffine
	b .L080C3D54
.L080C3D2A:
	ldrh r3, [r5, #0x10]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp]
	ldrh r0, [r5, #8]
	subs r0, #0xd6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r5, #0xa]
	adds r0, #0x88
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r2, #0xd
	bl Sprite_DrawSharedAffine
.L080C3D54:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080C3D5C
sub_080C3D5C: @ 0x080C3D5C
	push {r4, lr}
	adds r4, r0, #0
	bl Task_GetParent
	ldrh r0, [r0, #0x26]
	movs r1, #0
	strh r1, [r4, #0x1c]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_080E88C0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080C3D7C
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080C3D7C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C3D84
sub_080C3D84: @ 0x080C3D84
.L080C3D84:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r0, [sp, #0x24]
	ldr r2, [sp, #0x28]
	mov sb, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r1, sb
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	ldr r0, .L080C3E08
	ldr r1, .L080C3E0C
	bl Task_Create
	mov sl, r0
	mov r7, sl
	adds r7, #0x24
	ldr r1, [sp]
	bl sub_080C373C
	strh r0, [r7, #2]
	mov r0, sl
	bl sub_080C37C0
	mov r2, sl
	strh r4, [r2, #0x24]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r7, #6]
	strh r5, [r7, #8]
	strh r6, [r7, #0xa]
	mov r1, r8
	strh r1, [r7, #0xc]
	mov r2, sb
	strh r2, [r7, #0xe]
	movs r0, #2
	strh r0, [r7, #0x10]
	movs r0, #1
	strh r0, [r7, #4]
	ldr r0, [sp]
	bl sub_080E8AC0
	ldr r1, .L080C3E0C
	cmp r0, r1
	bne .L080C3E14
	ldr r0, .L080C3E10
	b .L080C3E16
	.byte 0x00, 0x00
.L080C3E08: .4byte gUnknown_081A647C
.L080C3E0C: .4byte 0x0000FFFF
.L080C3E10: .4byte gUnknown_081A631C
.L080C3E14:
	ldr r0, .L080C3E3C
.L080C3E16:
	mov r2, sl
	ldrh r1, [r2, #2]
	bl Task_Create
	str r0, [r7, #0x14]
	ldrb r0, [r7, #2]
	ldr r1, [sp]
	bl sub_080E8A28
	mov r0, sl
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C3E3C: .4byte gUnknown_081A6420

	thumb_func_start sub_080C3E40
sub_080C3E40: @ 0x080C3E40
.L080C3E40:
	strh r1, [r0, #0x34]
	bx lr

	thumb_func_start sub_080C3E44
sub_080C3E44: @ 0x080C3E44
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	adds r0, #0x24
	lsrs r1, r1, #0x10
	ldrh r3, [r0, #8]
	adds r1, r1, r3
	strh r1, [r0, #8]
	lsrs r2, r2, #0x10
	ldrh r1, [r0, #0xa]
	adds r2, r2, r1
	strh r2, [r0, #0xa]
	bx lr

	thumb_func_start sub_080C3E5C
sub_080C3E5C: @ 0x080C3E5C
.L080C3E5C:
	adds r0, #0x24
	strh r1, [r0, #8]
	strh r2, [r0, #0xa]
	bx lr

	thumb_func_start sub_080C3E64
sub_080C3E64: @ 0x080C3E64
.L080C3E64:
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq .L080C3E78
	bl Task_End
	movs r0, #0
	str r0, [r4, #0x14]
.L080C3E78:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C3E80
sub_080C3E80: @ 0x080C3E80
.L080C3E80:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	ldr r1, .L080C3EB8
	ldrh r0, [r5, #2]
	lsls r0, r0, #2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080C3E9A
	subs r0, #1
	strh r0, [r1]
.L080C3E9A:
	adds r0, r4, #0
	bl sub_080C37EC
	ldr r0, [r5, #0x14]
	cmp r0, #0
	beq .L080C3EAA
	bl Task_End
.L080C3EAA:
	adds r0, r4, #0
	bl Task_End
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C3EB8: .4byte 0x02036074 @ EWRAM+0x36074

	thumb_func_start sub_080C3EBC
sub_080C3EBC: @ 0x080C3EBC
	ldr r1, .L080C3ED0
	ldr r0, .L080C3ED4
	str r0, [r1]
	ldr r0, .L080C3ED8
	str r0, [r1, #4]
	ldr r0, .L080C3EDC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C3ED0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C3ED4: .4byte 0x02001000 @ EWRAM+0x1000
.L080C3ED8: .4byte 0x06016000 @ VRAM+0x16000
.L080C3EDC: .4byte 0x84000400

	thumb_func_start sub_080C3EE0
sub_080C3EE0: @ 0x080C3EE0
	ldr r1, .L080C3EF4
	ldr r0, .L080C3EF8
	str r0, [r1]
	ldr r0, .L080C3EFC
	str r0, [r1, #4]
	ldr r0, .L080C3F00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C3EF4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C3EF8: .4byte 0x02002000 @ EWRAM+0x2000
.L080C3EFC: .4byte 0x06017000 @ VRAM+0x17000
.L080C3F00: .4byte 0x84000400

	thumb_func_start sub_080C3F04
sub_080C3F04: @ 0x080C3F04
	ldr r1, .L080C3F18
	ldr r0, .L080C3F1C
	str r0, [r1]
	ldr r0, .L080C3F20
	str r0, [r1, #4]
	ldr r0, .L080C3F24
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C3F18: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C3F1C: .4byte 0x02003000 @ EWRAM+0x3000
.L080C3F20: .4byte 0x06015000 @ VRAM+0x15000
.L080C3F24: .4byte 0x84000400

	thumb_func_start sub_080C3F28
sub_080C3F28: @ 0x080C3F28
	ldr r1, .L080C3F3C
	ldr r0, .L080C3F40
	str r0, [r1]
	ldr r0, .L080C3F44
	str r0, [r1, #4]
	ldr r0, .L080C3F48
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C3F3C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C3F40: .4byte 0x02004000 @ EWRAM+0x4000
.L080C3F44: .4byte 0x06012000 @ VRAM+0x12000
.L080C3F48: .4byte 0x84000400

	thumb_func_start sub_080C3F4C
sub_080C3F4C: @ 0x080C3F4C
.L080C3F4C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	adds r5, r3, #0
	movs r0, #0
	mov r8, r0
	bl Palette_IsBg13Black
	cmp r0, #0
	bne .L080C4010
	ldrh r0, [r7, #0x1c]
	cmp r0, #0
	beq .L080C3F9C
	lsls r2, r4, #1
	ldr r0, .L080C3F98
	adds r2, r2, r0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r6, #0
	adds r3, r5, #0
	bl Palette_CopyWithEffect
	ldr r1, [sp, #0x1c]
	cmp r1, #1
	bne .L080C403C
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r5, #0xf
	lsrs r1, r1, #0x10
	movs r2, #3
	bl PalFade_FadeRangeInFromBlack
	b .L080C403A
.L080C3F98: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080C3F9C:
	ldrh r0, [r7, #0x1e]
	cmp r0, #0
	beq .L080C3FF0
	lsls r7, r4, #1
	ldr r2, .L080C3FE4
	adds r2, r7, r2
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r6, #0
	adds r3, r5, #0
	bl Palette_CopyWithEffect
	ldr r0, [sp, #0x1c]
	cmp r0, #1
	bne .L080C403C
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r5, #0xf
	lsrs r1, r1, #0x10
	movs r2, #3
	bl PalFade_FadeRangeInFromBlack
	mov r8, r0
	ldr r1, .L080C3FE8
	ldr r2, .L080C3FEC
	adds r2, r7, r2
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	adds r3, r5, #0
	bl Palette_FillWithEffect
	bl Palette_MarkDirty
	b .L080C403C
.L080C3FE4: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080C3FE8: .4byte 0x00007FFF
.L080C3FEC: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080C3FF0:
	lsls r2, r4, #1
	ldr r0, .L080C400C
	adds r2, r2, r0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r6, #0
	adds r3, r5, #0
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	b .L080C403C
	.byte 0x00, 0x00
.L080C400C: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080C4010:
	lsls r2, r4, #1
	ldr r0, .L080C407C
	adds r2, r2, r0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r6, #0
	adds r3, r5, #0
	bl Palette_CopyWithEffect
	ldr r1, [sp, #0x1c]
	cmp r1, #1
	bne .L080C403C
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r5, #0xf
	lsrs r1, r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeInFromBlackTagged
.L080C403A:
	mov r8, r0
.L080C403C:
	mov r0, r8
	cmp r0, #0
	beq .L080C405C
	movs r4, #0x87
	lsls r4, r4, #1
	adds r0, r4, #0
	bl Flag_Test
	cmp r0, #0
	beq .L080C405C
	movs r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	adds r0, r4, #0
	bl Flag_Clear
.L080C405C:
	movs r0, #0xfd
	bl Flag_Test
	cmp r0, #0
	beq .L080C406E
	movs r0, #0xa
	mov r1, r8
	strh r0, [r1, #4]
	strh r0, [r1, #6]
.L080C406E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C407C: .4byte 0x030029B0 @ IWRAM+0x29B0

	thumb_func_start Char_LoadGfxHalf
Char_LoadGfxHalf: @ 0x080C4080
.L080C4080:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	adds r4, r3, #0
	ldrh r0, [r5, #6]
	bl Char_GetRecord
	mov r8, r0
	ldrh r1, [r5, #2]
	adds r2, r1, #0
	ldrh r0, [r5, #4]
	cmp r0, #0
	beq .L080C4194
	cmp r1, #0
	bne .L080C40DC
	lsls r1, r4, #0xb
	ldr r0, .L080C40D4
	adds r1, r1, r0
	adds r0, r6, #0
	bl LZ77UnCompWram
	cmp r4, #1
	bne .L080C4194
	cmp r7, #0
	bne .L080C40CE
	mov r0, r8
	ldr r1, [r0, #0x24]
	movs r2, #0xf0
	lsls r2, r2, #1
	ldr r0, [sp, #0x1c]
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #0x20
	bl sub_080C3F4C
.L080C40CE:
	ldr r0, .L080C40D8
	b .L080C4142
	.byte 0x00, 0x00
.L080C40D4: .4byte 0x02001000 @ EWRAM+0x1000
.L080C40D8: .4byte sub_080C3EBC
.L080C40DC:
	cmp r1, #1
	bne .L080C4114
	lsls r1, r4, #0xb
	ldr r0, .L080C410C
	adds r1, r1, r0
	adds r0, r6, #0
	bl LZ77UnCompWram
	cmp r4, #1
	bne .L080C4194
	cmp r7, #0
	bne .L080C4108
	mov r0, r8
	ldr r1, [r0, #0x24]
	movs r2, #0xf8
	lsls r2, r2, #1
	ldr r0, [sp, #0x1c]
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #0x20
	bl sub_080C3F4C
.L080C4108:
	ldr r0, .L080C4110
	b .L080C4142
.L080C410C: .4byte 0x02002000 @ EWRAM+0x2000
.L080C4110: .4byte sub_080C3EE0
.L080C4114:
	cmp r2, #2
	bne .L080C4154
	lsls r1, r4, #0xb
	ldr r0, .L080C414C
	adds r1, r1, r0
	adds r0, r6, #0
	bl LZ77UnCompWram
	cmp r4, #1
	bne .L080C4194
	cmp r7, #0
	bne .L080C4140
	mov r0, r8
	ldr r1, [r0, #0x24]
	movs r2, #0xe8
	lsls r2, r2, #1
	ldr r0, [sp, #0x1c]
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #0x20
	bl sub_080C3F4C
.L080C4140:
	ldr r0, .L080C4150
.L080C4142:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080C4194
	.byte 0x00, 0x00
.L080C414C: .4byte 0x02003000 @ EWRAM+0x3000
.L080C4150: .4byte sub_080C3F04
.L080C4154:
	lsls r1, r4, #0xb
	ldr r0, .L080C41A0
	adds r1, r1, r0
	adds r0, r6, #0
	bl LZ77UnCompWram
	cmp r4, #1
	bne .L080C4194
	cmp r7, #0
	bne .L080C417C
	mov r0, r8
	ldr r1, [r0, #0x24]
	movs r2, #0xe0
	lsls r2, r2, #1
	ldr r0, [sp, #0x1c]
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #0x20
	bl sub_080C3F4C
.L080C417C:
	ldr r0, .L080C41A4
	ldr r1, [r0]
	ldr r0, .L080C41A8
	cmp r1, r0
	bne .L080C418C
	ldrh r0, [r5, #6]
	cmp r0, #0x2a
	beq .L080C4194
.L080C418C:
	ldr r0, .L080C41AC
	movs r1, #1
	bl VBlankTask_AddCounted
.L080C4194:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080C41A0: .4byte 0x02004000 @ EWRAM+0x4000
.L080C41A4: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080C41A8: .4byte sub_080D977C
.L080C41AC: .4byte sub_080C3F28

	thumb_func_start sub_080C41B0
sub_080C41B0: @ 0x080C41B0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	mov r8, r1
	adds r5, r2, #0
	adds r6, r3, #0
	bl Task_GetParent
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r0, [r4, #6]
	bl Char_GetRecord
	lsls r1, r6, #2
	lsls r5, r5, #3
	adds r1, r1, r5
	adds r0, #4
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	mov r2, r8
	adds r3, r6, #0
	bl Char_LoadGfxHalf
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C41F4
sub_080C41F4: @ 0x080C41F4
.L080C41F4:
	push {lr}
	adds r0, #0x24
	ldrh r1, [r0, #2]
	adds r2, r1, #0
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq .L080C4238
	cmp r1, #0
	bne .L080C420C
	movs r0, #0xf0
	lsls r0, r0, #1
	b .L080C421E
.L080C420C:
	cmp r1, #1
	bne .L080C4216
	movs r0, #0xf8
	lsls r0, r0, #1
	b .L080C421E
.L080C4216:
	cmp r2, #2
	bne .L080C422A
	movs r0, #0xe8
	lsls r0, r0, #1
.L080C421E:
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeToBlackTagged
	b .L080C4238
.L080C422A:
	movs r0, #0xe0
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeToBlackTagged
.L080C4238:
	pop {r0}
	bx r0

	thumb_func_start sub_080C423C
sub_080C423C: @ 0x080C423C
.L080C423C:
	movs r0, #0
	bx lr

	thumb_func_start sub_080C4240
sub_080C4240: @ 0x080C4240
.L080C4240:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	cmp r2, #0
	bne .L080C4260
	cmp r0, #0
	bne .L080C4258
	movs r0, #0
	b .L080C426E
.L080C4258:
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b .L080C426E
.L080C4260:
	cmp r0, r1
	blo .L080C4268
	adds r0, r1, #0
	b .L080C426E
.L080C4268:
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080C426E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C4274
sub_080C4274: @ 0x080C4274
.L080C4274:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldrh r0, [r7, #0x12]
	cmp r0, #1
	bne .L080C436E
	ldr r0, .L080C4380
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne .L080C436E
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080C436E
	ldrh r0, [r7, #6]
	bl Char_GetRecord
	lsls r2, r4, #5
	ldr r1, .L080C4384
	adds r2, r2, r1
	mov sb, r2
	ldr r0, [r0, #0x24]
	mov sl, r0
	movs r0, #2
	add sl, r0
	movs r1, #0
	str r1, [sp, #4]
.L080C42BE:
	mov r2, sb
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	movs r3, #0xf8
	lsls r3, r3, #2
	ands r3, r1
	lsrs r3, r3, #5
	movs r2, #0xf8
	lsls r2, r2, #7
	mov r8, r2
	ands r2, r1
	lsrs r2, r2, #0xa
	mov r8, r2
	mov r1, sl
	ldrh r2, [r1]
	movs r1, #0x1f
	ands r1, r2
	movs r4, #0xf8
	lsls r4, r4, #2
	ands r4, r2
	lsrs r4, r4, #5
	movs r6, #0xf8
	lsls r6, r6, #7
	ands r6, r2
	lsrs r6, r6, #0xa
	ldrh r2, [r7, #0x14]
	str r3, [sp, #8]
	bl sub_080C4240
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldrh r2, [r7, #0x14]
	ldr r3, [sp, #8]
	adds r0, r3, #0
	adds r1, r4, #0
	bl sub_080C4240
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrh r2, [r7, #0x14]
	mov r0, r8
	adds r1, r6, #0
	bl sub_080C4240
	lsls r0, r0, #0x10
	lsls r4, r4, #5
	orrs r5, r4
	lsrs r0, r0, #6
	orrs r5, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r5, #0
	mov r2, sb
	movs r3, #2
	bl Palette_FillWithEffect
	ldr r0, [sp, #4]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r2, #2
	add sb, r2
	add sl, r2
	cmp r0, #0xe
	bls .L080C42BE
	bl Palette_MarkDirty
	ldrh r0, [r7, #0x16]
	adds r0, #1
	strh r0, [r7, #0x16]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bls .L080C436E
	movs r0, #0
	strh r0, [r7, #0x16]
	ldrh r0, [r7, #0x14]
	adds r0, #1
	movs r1, #1
	ands r0, r1
	strh r0, [r7, #0x14]
.L080C436E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C4380: .4byte 0x030031BC @ IWRAM+0x31BC
.L080C4384: .4byte 0x03002FB2 @ IWRAM+0x2FB2

	thumb_func_start sub_080C4388
sub_080C4388: @ 0x080C4388
.L080C4388:
	push {lr}
	adds r2, r0, #0
	ldrh r1, [r2, #6]
	adds r0, r1, #0
	subs r0, #0xaa
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080C439E
	cmp r1, #0xf5
	bne .L080C43A2
.L080C439E:
	movs r0, #0
	b .L080C43B0
.L080C43A2:
	ldrh r0, [r2]
	movs r1, #7
	ands r1, r0
	movs r0, #8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080C43B0:
	pop {r1}
	bx r1

	thumb_func_start sub_080C43B4
sub_080C43B4: @ 0x080C43B4
.L080C43B4:
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #6]
	bl Char_GetRecord
	adds r2, r0, #0
	ldrh r1, [r4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne .L080C43EC
	ldrh r0, [r2, #2]
	cmp r0, #0
	beq .L080C43EC
	ldr r0, .L080C43E4
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080C43EC
	ldr r0, .L080C43E8
	b .L080C43EE
	.byte 0x00, 0x00
.L080C43E4: .4byte 0x030031BC @ IWRAM+0x31BC
.L080C43E8: .4byte gUnknown_08005028
.L080C43EC:
	ldr r0, .L080C43F4
.L080C43EE:
	pop {r4}
	pop {r1}
	bx r1
.L080C43F4: .4byte gUnknown_08004FF8

	thumb_func_start sub_080C43F8
sub_080C43F8: @ 0x080C43F8
.L080C43F8:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov sb, r1
	adds r6, r2, #0
	mov r8, r3
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r5, [r4, #2]
	adds r0, r4, #0
	bl sub_080C4388
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	ldrh r7, [r4, #0xa]
	ldr r0, .L080C4430
	ldrh r0, [r0]
	subs r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r6, #0
	beq .L080C4434
	lsls r0, r6, #0x10
	lsrs r2, r0, #0x10
	b .L080C444A
.L080C4430: .4byte 0x0300000E @ IWRAM+0xE
.L080C4434:
	movs r2, #0
	cmp r5, #0
	beq .L080C444A
	movs r2, #0x80
	cmp r5, #1
	beq .L080C444A
	movs r2, #0xfe
	lsls r2, r2, #8
	cmp r5, #2
	bne .L080C444A
	ldr r2, .L080C4458
.L080C444A:
	mov r0, r8
	cmp r0, #0
	beq .L080C445C
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b .L080C4470
	.byte 0x00, 0x00
.L080C4458: .4byte 0x0000FF80
.L080C445C:
	movs r3, #0xe
	cmp r5, #0
	beq .L080C4470
	movs r3, #0xf
	cmp r5, #1
	beq .L080C4470
	movs r3, #0xc
	cmp r5, #2
	bne .L080C4470
	movs r3, #0xd
.L080C4470:
	ldr r0, .L080C44A8
	ldr r1, [r0]
	ldr r0, .L080C44AC
	cmp r1, r0
	bne .L080C4482
	ldrh r0, [r4, #6]
	cmp r0, #0x2a
	bne .L080C4482
	movs r2, #0
.L080C4482:
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	str r2, [sp, #4]
	ldrh r0, [r4, #8]
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	mov r2, ip
	bl sub_080C44CC
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C44A8: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080C44AC: .4byte sub_080D977C

	thumb_func_start sub_080C44B0
sub_080C44B0: @ 0x080C44B0
.L080C44B0:
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x24
	bl sub_080C43B4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl sub_080C43F8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080C44CC
sub_080C44CC: @ 0x080C44CC
.L080C44CC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r6, r0, #0
	str r1, [sp, #0xc]
	ldr r0, [sp, #0x44]
	ldr r1, [sp, #0x48]
	ldr r4, [sp, #0x4c]
	ldr r5, [sp, #0x50]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x14]
	str r2, [sp, #0x10]
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	str r7, [sp, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	str r0, [sp, #0x1c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	str r1, [sp, #0x20]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov sl, r5
	adds r0, r6, #0
	bl sub_080C423C
	cmp r0, #1
	beq .L080C456A
	adds r0, r6, #0
	adds r1, r7, #0
	bl sub_080C4274
	movs r0, #0x83
	lsls r0, r0, #1
	bl Flag_Test
	cmp r0, #0
	beq .L080C4534
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r4, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L080C4534:
	ldrh r1, [r6]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L080C4554
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x14]
	adds r2, r7, #0
	mov r3, sb
	bl Sprite_Draw
	b .L080C456A
.L080C4554:
	ldr r1, [sp, #0x20]
	str r1, [sp]
	str r4, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl Sprite_DrawBlended
.L080C456A:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C457C
sub_080C457C: @ 0x080C457C
.L080C457C:
	strh r1, [r0, #0x36]
	bx lr

	thumb_func_start sub_080C4580
sub_080C4580: @ 0x080C4580
.L080C4580:
	push {lr}
	movs r1, #1
	bl sub_080C457C
	pop {r0}
	bx r0

	thumb_func_start sub_080C458C
sub_080C458C: @ 0x080C458C
	push {lr}
	movs r1, #0
	bl sub_080C457C
	pop {r0}
	bx r0

	thumb_func_start sub_080C4598
sub_080C4598: @ 0x080C4598
.L080C4598:
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r4, #0
	ldr r1, .L080C45AC
.L080C45A2:
	ldr r0, [r1]
	cmp r0, r3
	bne .L080C45B0
	str r4, [r1]
	b .L080C45B8
.L080C45AC: .4byte 0x030068F0 @ IWRAM+0x68F0
.L080C45B0:
	adds r1, #4
	adds r2, #1
	cmp r2, #7
	bls .L080C45A2
.L080C45B8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C45C0
sub_080C45C0: @ 0x080C45C0
.L080C45C0:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	movs r1, #0xe0
	lsls r1, r1, #0xb
	ands r1, r0
	lsrs r6, r1, #0x10
	movs r5, #0
	ldr r4, .L080C45F4
.L080C45D4:
	ldr r2, [r4]
	cmp r2, #0
	beq .L080C4602
	adds r3, r2, #0
	adds r3, #0x24
	ldrh r1, [r2, #0x24]
	movs r0, #7
	ands r0, r1
	cmp r0, r6
	bne .L080C4602
	ldrh r0, [r3, #6]
	cmp r0, r7
	bne .L080C45F8
	adds r0, r2, #0
	b .L080C460C
	.byte 0x00, 0x00
.L080C45F4: .4byte 0x02036094 @ EWRAM+0x36094
.L080C45F8:
	adds r0, r2, #0
	movs r1, #0
	bl sub_080C48F0
	b .L080C460A
.L080C4602:
	adds r4, #4
	adds r5, #1
	cmp r5, #5
	bls .L080C45D4
.L080C460A:
	movs r0, #0
.L080C460C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C4614
sub_080C4614: @ 0x080C4614
.L080C4614:
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080C4618
sub_080C4618: @ 0x080C4618
.L080C4618:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r4, [sp, #0x30]
	ldr r5, [sp, #0x34]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0xc]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov r0, r8
	bl Char_GetRecord
	adds r4, r0, #0
	mov r0, sb
	mov r1, r8
	bl sub_080C45C0
	adds r7, r0, #0
	cmp r7, #0
	bne .L080C4662
	b .L080C476A
.L080C4662:
	adds r6, r7, #0
	adds r6, #0x24
	movs r0, #0x40
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	bne .L080C4730
	mov r0, r8
	bl Char_GetRecord
	ldr r5, [r0, #0x24]
	ldr r0, .L080C4684
	cmp r8, r0
	bne .L080C468C
	ldr r0, .L080C4688
	ldrh r0, [r0]
	b .L080C4698
.L080C4684: .4byte 0x000001C1
.L080C4688: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080C468C:
	movs r0, #0xe0
	lsls r0, r0, #1
	cmp r8, r0
	bne .L080C469E
	ldr r0, .L080C46B8
	ldrh r0, [r0, #2]
.L080C4698:
	bl sub_080D8248
	ldr r5, [r0, #4]
.L080C469E:
	ldrh r0, [r6, #2]
	cmp r0, #0
	bne .L080C46C4
	ldr r2, .L080C46BC
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r2, .L080C46C0
	b .L080C4716
.L080C46B8: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080C46BC: .4byte 0x03003170 @ IWRAM+0x3170
.L080C46C0: .4byte 0x03002D70 @ IWRAM+0x2D70
.L080C46C4:
	cmp r0, #1
	bne .L080C46E4
	ldr r2, .L080C46DC
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r2, .L080C46E0
	b .L080C4716
.L080C46DC: .4byte 0x03003190 @ IWRAM+0x3190
.L080C46E0: .4byte 0x03002D90 @ IWRAM+0x2D90
.L080C46E4:
	cmp r0, #2
	bne .L080C4704
	ldr r2, .L080C46FC
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r2, .L080C4700
	b .L080C4716
.L080C46FC: .4byte 0x03003150 @ IWRAM+0x3150
.L080C4700: .4byte 0x03002D50 @ IWRAM+0x2D50
.L080C4704:
	ldr r2, .L080C4728
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r2, .L080C472C
.L080C4716:
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	b .L080C4894
.L080C4728: .4byte 0x03003130 @ IWRAM+0x3130
.L080C472C: .4byte 0x03002D30 @ IWRAM+0x2D30
.L080C4730:
	ldrh r0, [r6, #2]
	cmp r0, #0
	bne .L080C473C
	movs r0, #0xf0
	lsls r0, r0, #1
	b .L080C474E
.L080C473C:
	cmp r0, #1
	bne .L080C4746
	movs r0, #0xf8
	lsls r0, r0, #1
	b .L080C474E
.L080C4746:
	cmp r0, #2
	bne .L080C475A
	movs r0, #0xe8
	lsls r0, r0, #1
.L080C474E:
	movs r1, #0x10
	movs r2, #1
	movs r3, #3
	bl PalFade_FadeRangeToBlackWithDuration
	b .L080C4894
.L080C475A:
	movs r0, #0xe0
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #3
	bl PalFade_FadeRangeToBlackWithDuration
	b .L080C4894
.L080C476A:
	mov r0, sb
	bl sub_080C4614
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080C4794
	ldr r0, .L080C4788
	ldr r1, .L080C478C
	bl Task_Create
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x24
	ldr r0, .L080C4790
	b .L080C47A8
.L080C4788: .4byte gUnknown_081A65B8
.L080C478C: .4byte 0x0000FFFF
.L080C4790: .4byte gUnknown_081A64A8
.L080C4794:
	cmp r0, #1
	bne .L080C47C0
	ldr r0, .L080C47B4
	ldr r1, .L080C47B8
	bl Task_Create
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x24
	ldr r0, .L080C47BC
.L080C47A8:
	ldrh r1, [r7, #2]
	bl Task_Create
	str r0, [r6, #0x20]
	b .L080C47DA
	.byte 0x00, 0x00
.L080C47B4: .4byte gUnknown_081A65B8
.L080C47B8: .4byte 0x0000FFFF
.L080C47BC: .4byte gUnknown_081A64F8
.L080C47C0:
	cmp r0, #2
	bne .L080C47C8
	ldr r0, [r4, #0x28]
	b .L080C47CE
.L080C47C8:
	cmp r0, #3
	bne .L080C47DA
	ldr r0, .L080C4800
.L080C47CE:
	ldr r1, .L080C4804
	bl Task_Create
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x24
.L080C47DA:
	mov r0, sb
	strh r0, [r6]
	adds r0, r7, #0
	mov r1, r8
	bl sub_080C373C
	strh r0, [r6, #2]
	ldr r4, .L080C4808
	adds r0, r4, #0
	bl Flag_Test
	cmp r0, #0
	beq .L080C480C
	movs r0, #1
	strh r0, [r6, #0x1c]
	adds r0, r4, #0
	bl Flag_Clear
	b .L080C4824
.L080C4800: .4byte gUnknown_0855FB78
.L080C4804: .4byte 0x0000FFFF
.L080C4808: .4byte 0x0000010B
.L080C480C:
	movs r4, #0x86
	lsls r4, r4, #1
	adds r0, r4, #0
	bl Flag_Test
	cmp r0, #0
	beq .L080C4824
	movs r0, #1
	strh r0, [r6, #0x1e]
	adds r0, r4, #0
	bl Flag_Clear
.L080C4824:
	ldr r0, [r6, #0x1c]
	cmp r0, #0
	bne .L080C4858
	movs r0, #0xc6
	bl Flag_Test
	cmp r0, #0
	bne .L080C4858
	ldr r2, .L080C48A8
	ldrh r0, [r2, #0x12]
	ldrh r1, [r2, #0x14]
	ldrh r2, [r2, #2]
	add r3, sp, #4
	bl sub_080C9084
	cmp r0, #0
	beq .L080C4858
	ldr r0, [r0, #4]
	bl ScriptVM_RunAlt
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L080C4858
	movs r0, #1
	strh r0, [r6, #0x1c]
.L080C4858:
	adds r0, r7, #0
	bl sub_080C37C0
	mov r1, r8
	strh r1, [r6, #6]
	mov r0, sp
	ldrh r0, [r0, #8]
	strh r0, [r6, #8]
	mov r1, sl
	strh r1, [r6, #0xa]
	mov r0, sp
	ldrh r0, [r0, #0xc]
	strh r0, [r6, #0xc]
	strh r5, [r6, #0xe]
	movs r0, #2
	strh r0, [r6, #0x10]
	mov r1, sl
	cmp r1, #0x3f
	bls .L080C4882
	movs r0, #3
	strh r0, [r6, #0x10]
.L080C4882:
	mov r0, r8
	bl sub_080C38D4
	lsls r0, r0, #0x10
	ldr r1, .L080C48AC
	cmp r0, r1
	bne .L080C4894
	movs r0, #1
	strh r0, [r6, #4]
.L080C4894:
	adds r0, r7, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C48A8: .4byte 0x03004550 @ IWRAM+0x4550
.L080C48AC: .4byte 0xFFFF0000

	thumb_func_start sub_080C48B0
sub_080C48B0: @ 0x080C48B0
	strh r1, [r0, #0x34]
	bx lr

	thumb_func_start sub_080C48B4
sub_080C48B4: @ 0x080C48B4
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	adds r0, #0x24
	lsrs r1, r1, #0x10
	ldrh r3, [r0, #8]
	adds r1, r1, r3
	strh r1, [r0, #8]
	lsrs r2, r2, #0x10
	ldrh r1, [r0, #0xa]
	adds r2, r2, r1
	strh r2, [r0, #0xa]
	bx lr

	thumb_func_start sub_080C48CC
sub_080C48CC: @ 0x080C48CC
.L080C48CC:
	adds r0, #0x24
	strh r1, [r0, #8]
	strh r2, [r0, #0xa]
	bx lr

	thumb_func_start sub_080C48D4
sub_080C48D4: @ 0x080C48D4
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq .L080C48E8
	bl Task_End
	movs r0, #0
	str r0, [r4, #0x20]
.L080C48E8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C48F0
sub_080C48F0: @ 0x080C48F0
.L080C48F0:
	push {r4, r5, lr}
	adds r5, r0, #0
	cmp r5, #0
	beq .L080C492C
	ldrh r0, [r5]
	cmp r0, #0
	beq .L080C492C
	adds r4, r5, #0
	adds r4, #0x24
	ldr r0, .L080C4934
	ldrh r1, [r4, #2]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	adds r0, r5, #0
	bl sub_080C37EC
	adds r0, r5, #0
	bl sub_080C4598
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq .L080C4926
	bl Task_End
.L080C4926:
	adds r0, r5, #0
	bl Task_End
.L080C492C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C4934: .4byte 0x02036074 @ EWRAM+0x36074

	thumb_func_start sub_080C4938
sub_080C4938: @ 0x080C4938
.L080C4938:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r6, r5, #0x10
	movs r5, #0
	cmp r5, sl
	bhs .L080C49D6
.L080C496C:
	cmp r5, #0
	bne .L080C498C
	str r5, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	ldr r0, .L080C4988
	mov r1, sb
	mov r2, r8
	adds r3, r7, #0
	bl Sprite_DrawSingle
	adds r0, r4, #0
	adds r0, #0x10
	b .L080C49C8
.L080C4988: .4byte gUnknown_081A65DC
.L080C498C:
	mov r0, sl
	subs r0, #1
	cmp r5, r0
	bne .L080C49B0
	movs r0, #0
	str r0, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	ldr r0, .L080C49AC
	mov r1, sb
	mov r2, r8
	adds r3, r7, #0
	bl Sprite_DrawSingle
	b .L080C49CC
	.byte 0x00, 0x00
.L080C49AC: .4byte gUnknown_081A65EC
.L080C49B0:
	movs r0, #0
	str r0, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	ldr r0, .L080C49E8
	mov r1, sb
	mov r2, r8
	adds r3, r7, #0
	bl Sprite_DrawSingle
	adds r0, r4, #0
	adds r0, #8
.L080C49C8:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L080C49CC:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, sl
	blo .L080C496C
.L080C49D6:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C49E8: .4byte gUnknown_081A65E4

	thumb_func_start sub_080C49EC
sub_080C49EC: @ 0x080C49EC
.L080C49EC:
	push {r4, lr}
	sub sp, #8
	adds r4, r2, #0
	ldr r2, [sp, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	str r2, [sp, #4]
	movs r2, #3
	adds r3, r4, #0
	bl sub_080C4938
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080C4A1C
sub_080C4A1C: @ 0x080C4A1C
	push {r4, lr}
	sub sp, #8
	adds r4, r2, #0
	ldr r2, [sp, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	str r2, [sp, #4]
	movs r2, #6
	adds r3, r4, #0
	bl sub_080C4938
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080C4A4C
sub_080C4A4C: @ 0x080C4A4C
.L080C4A4C:
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, .L080C4A80
	ldr r1, [r0]
	ldr r0, .L080C4A84
	cmp r1, r0
	beq .L080C4A8C
	ldr r0, .L080C4A88
	movs r1, #0
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	adds r1, r4, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	b .L080C4AA2
.L080C4A80: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080C4A84: .4byte sub_080D977C
.L080C4A88: .4byte gUnknown_08000FF0
.L080C4A8C:
	ldr r0, .L080C4AAC
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	adds r1, r4, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
.L080C4AA2:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C4AAC: .4byte gUnknown_08008660

	thumb_func_start sub_080C4AB0
sub_080C4AB0: @ 0x080C4AB0
.L080C4AB0:
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, .L080C4AE4
	ldr r1, [r0]
	ldr r0, .L080C4AE8
	cmp r1, r0
	beq .L080C4AF0
	ldr r0, .L080C4AEC
	movs r1, #0
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	adds r1, r4, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	b .L080C4B06
.L080C4AE4: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080C4AE8: .4byte sub_080D977C
.L080C4AEC: .4byte gUnknown_08001000
.L080C4AF0:
	ldr r0, .L080C4B10
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	adds r1, r4, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
.L080C4B06:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C4B10: .4byte gUnknown_08008670

	thumb_func_start sub_080C4B14
sub_080C4B14: @ 0x080C4B14
.L080C4B14:
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, .L080C4B48
	ldr r1, [r0]
	ldr r0, .L080C4B4C
	cmp r1, r0
	beq .L080C4B54
	ldr r0, .L080C4B50
	movs r1, #0
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	adds r1, r4, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	b .L080C4B6A
.L080C4B48: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080C4B4C: .4byte sub_080D977C
.L080C4B50: .4byte gUnknown_0800108C
.L080C4B54:
	ldr r0, .L080C4B74
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	adds r1, r4, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
.L080C4B6A:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C4B74: .4byte gUnknown_0800876C

	thumb_func_start sub_080C4B78
sub_080C4B78: @ 0x080C4B78
.L080C4B78:
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, .L080C4BAC
	ldr r1, [r0]
	ldr r0, .L080C4BB0
	cmp r1, r0
	beq .L080C4BB8
	ldr r0, .L080C4BB4
	movs r1, #0
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	adds r1, r4, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	b .L080C4BCE
.L080C4BAC: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080C4BB0: .4byte sub_080D977C
.L080C4BB4: .4byte gUnknown_0800109C
.L080C4BB8:
	ldr r0, .L080C4BD8
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	adds r1, r4, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
.L080C4BCE:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C4BD8: .4byte gUnknown_08008750

	thumb_func_start sub_080C4BDC
sub_080C4BDC: @ 0x080C4BDC
	movs r0, #0
	bx lr

	thumb_func_start sub_080C4BE0
sub_080C4BE0: @ 0x080C4BE0
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080C4BE4
sub_080C4BE4: @ 0x080C4BE4
	ldr r2, .L080C4BF8
	ldr r1, .L080C4BFC
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	bx lr
	.byte 0x00, 0x00
.L080C4BF8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C4BFC: .4byte 0x00000AC8

	thumb_func_start sub_080C4C00
sub_080C4C00: @ 0x080C4C00
	movs r1, #1
	lsls r1, r0
	ldr r0, .L080C4C10
	ldr r2, .L080C4C14
	adds r0, r0, r2
	ldrh r0, [r0]
	bics r0, r1
	bx lr
.L080C4C10: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C4C14: .4byte 0x00000AC8
