	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080B6B58
sub_080B6B58: @ 0x080B6B58
.L080B6B58:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, .L080B6BA4
	ldr r1, .L080B6BA8
	bl Task_Create
	adds r2, r0, #0
	adds r5, r2, #0
	adds r5, #0x24
	str r4, [r2, #0x24]
	ldr r1, .L080B6BAC
	adds r3, r1, #0
	adds r3, #0x48
	ldrh r0, [r3]
	cmp r0, #1
	bne .L080B6B7E
	movs r0, #2
	strh r0, [r3]
.L080B6B7E:
	adds r3, r1, #0
	adds r3, #0x4c
	ldrh r0, [r3]
	cmp r0, #1
	bne .L080B6B8C
	movs r0, #2
	strh r0, [r3]
.L080B6B8C:
	adds r1, #0x50
	ldrh r0, [r1]
	cmp r0, #1
	bne .L080B6B98
	movs r0, #2
	strh r0, [r1]
.L080B6B98:
	str r6, [r5, #8]
	adds r0, r2, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B6BA4: .4byte gUnknown_08163BE8
.L080B6BA8: .4byte 0x0000FFFF
.L080B6BAC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B6BB0
sub_080B6BB0: @ 0x080B6BB0
.L080B6BB0:
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080B6BF4
	ldr r1, .L080B6BF8
	bl Task_Create
	adds r3, r0, #0
	str r4, [r3, #0x24]
	ldr r1, .L080B6BFC
	adds r2, r1, #0
	adds r2, #0x48
	ldrh r0, [r2]
	cmp r0, #1
	bne .L080B6BD0
	movs r0, #2
	strh r0, [r2]
.L080B6BD0:
	adds r2, r1, #0
	adds r2, #0x4c
	ldrh r0, [r2]
	cmp r0, #1
	bne .L080B6BDE
	movs r0, #2
	strh r0, [r2]
.L080B6BDE:
	adds r1, #0x50
	ldrh r0, [r1]
	cmp r0, #1
	bne .L080B6BEA
	movs r0, #2
	strh r0, [r1]
.L080B6BEA:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B6BF4: .4byte gUnknown_08163E78
.L080B6BF8: .4byte 0x0000FFFF
.L080B6BFC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B6C00
sub_080B6C00: @ 0x080B6C00
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #4
	bhi .L080B6C68
	lsls r0, r1, #2
	ldr r1, .L080B6C14
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080B6C14: .4byte gUnknown_080B6C18
	.global gUnknown_080B6C18
gUnknown_080B6C18:
.L080B6C18: @ jump table
	.4byte .L080B6C2C
	.4byte .L080B6C34
	.4byte .L080B6C48
	.4byte .L080B6C50
	.4byte .L080B6C60
.L080B6C2C:
	ldr r0, .L080B6C30
	b .L080B6C52
.L080B6C30: .4byte sub_080B3E8C
.L080B6C34:
	movs r0, #0
	bl sub_080B3EA4
	cmp r0, #0
	bne .L080B6C42
	strh r0, [r4, #0x1c]
	b .L080B6C68
.L080B6C42:
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080B6C68
.L080B6C48:
	ldr r0, .L080B6C4C
	b .L080B6C52
.L080B6C4C: .4byte sub_080B3ED0
.L080B6C50:
	ldr r0, .L080B6C5C
.L080B6C52:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B6C68
	.byte 0x00, 0x00
.L080B6C5C: .4byte sub_080B3F1C
.L080B6C60:
	ldr r0, .L080B6C70
	movs r1, #1
	bl VBlankTask_AddCounted
.L080B6C68:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B6C70: .4byte sub_080B41B0

	thumb_func_start sub_080B6C74
sub_080B6C74: @ 0x080B6C74
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, .L080B6CA4
	bl Flag_Test
	cmp r0, #0
	beq .L080B6CD2
	bl sub_080B4140
	ldr r0, .L080B6CA8
	ldrh r0, [r0]
	cmp r0, #0xda
	bne .L080B6CB4
	ldr r1, .L080B6CAC
	ldr r2, .L080B6CB0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	b .L080B6CC6
	.byte 0x00, 0x00
.L080B6CA4: .4byte 0x0000010F
.L080B6CA8: .4byte 0x03004534 @ IWRAM+0x4534
.L080B6CAC: .4byte 0x03002A90 @ IWRAM+0x2A90
.L080B6CB0: .4byte 0x03002E90 @ IWRAM+0x2E90
.L080B6CB4:
	ldr r1, .L080B6CDC
	ldr r2, .L080B6CE0
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
.L080B6CC6:
	bl Palette_MarkDirty
	ldr r0, .L080B6CE4
	bl Flag_Clear
	movs r0, #1
.L080B6CD2:
	strh r0, [r4, #0x1c]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080B6CDC: .4byte 0x03002AB0 @ IWRAM+0x2AB0
.L080B6CE0: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080B6CE4: .4byte 0x0000010F

	thumb_func_start sub_080B6CE8
sub_080B6CE8: @ 0x080B6CE8
	ldr r1, .L080B6CF4
	ldrh r0, [r1]
	adds r0, #0xff
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080B6CF4: .4byte 0x03000042 @ IWRAM+0x42

	thumb_func_start sub_080B6CF8
sub_080B6CF8: @ 0x080B6CF8
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080B6D1C
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080B6D20
	str r0, [r1, #4]
	ldr r0, .L080B6D24
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xc8
	ldr r2, .L080B6D28
	adds r0, r2, #0
	strh r0, [r1]
	add sp, #4
	bx lr
	.byte 0x00, 0x00
.L080B6D1C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6D20: .4byte 0x06001000 @ VRAM+0x1000
.L080B6D24: .4byte 0x85000400
.L080B6D28: .4byte 0x0000840A

	thumb_func_start sub_080B6D2C
sub_080B6D2C: @ 0x080B6D2C
	push {lr}
	bl sub_080C1440
	ldr r0, .L080B6D40
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B6D40: .4byte sub_080B6CF8

	thumb_func_start sub_080B6D44
sub_080B6D44: @ 0x080B6D44
	ldr r1, .L080B6D58
	ldr r0, .L080B6D5C
	str r0, [r1]
	ldr r0, .L080B6D60
	str r0, [r1, #4]
	ldr r0, .L080B6D64
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B6D58: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6D5C: .4byte 0x02000000 @ EWRAM
.L080B6D60: .4byte 0x06002000 @ VRAM+0x2000
.L080B6D64: .4byte 0x84000140

	thumb_func_start sub_080B6D68
sub_080B6D68: @ 0x080B6D68
	push {lr}
	ldr r1, .L080B6D88
	ldr r0, .L080B6D8C
	str r0, [r1]
	ldr r0, .L080B6D90
	str r0, [r1, #4]
	ldr r0, .L080B6D94
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080B6D98
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B6D88: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B6D8C: .4byte gUnknown_0857D9C0
.L080B6D90: .4byte 0x02000000 @ EWRAM
.L080B6D94: .4byte 0x84000140
.L080B6D98: .4byte sub_080B6D44

	thumb_func_start sub_080B6D9C
sub_080B6D9C: @ 0x080B6D9C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080B38A8
	cmp r0, #1
	beq .L080B6DAA
	movs r0, #0
.L080B6DAA:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B6DB4
sub_080B6DB4: @ 0x080B6DB4
.L080B6DB4:
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, .L080B6DCC
	ldr r1, [r0]
	ldr r0, .L080B6DD0
	cmp r1, r0
	bne .L080B6E4C
	cmp r4, #0x6d
	bne .L080B6DD8
	ldr r0, .L080B6DD4
	b .L080B6DDE
.L080B6DCC: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080B6DD0: .4byte sub_080D977C
.L080B6DD4: .4byte gUnknown_0834A0D4
.L080B6DD8:
	cmp r4, #0x2e
	bne .L080B6DFC
	ldr r0, .L080B6DF0
.L080B6DDE:
	ldr r1, .L080B6DF4
	bl Task_Create
	adds r6, r0, #0
	ldr r1, .L080B6DF8
	movs r0, #0
	strh r0, [r1, #0x1e]
	b .L080B6E06
	.byte 0x00, 0x00
.L080B6DF0: .4byte gUnknown_0834A01C
.L080B6DF4: .4byte 0x0000FFFF
.L080B6DF8: .4byte 0x03004550 @ IWRAM+0x4550
.L080B6DFC:
	ldr r0, .L080B6E30
	ldr r1, .L080B6E34
	bl Task_Create
	adds r6, r0, #0
.L080B6E06:
	ldr r0, .L080B6E38
	strh r4, [r0]
	ldr r0, .L080B6E3C
	bl Flag_Test
	adds r5, r0, #0
	cmp r5, #0
	bne .L080B6EFE
	mov r0, sp
	strh r5, [r0]
	ldr r4, .L080B6E40
	ldr r2, .L080B6E44
	adds r1, r4, #0
	bl CpuSet
	ldr r1, .L080B6E48
	adds r0, r4, r1
	strh r5, [r0]
	bl Palette_MarkDirty
	b .L080B6EFE
.L080B6E30: .4byte gUnknown_08164074
.L080B6E34: .4byte 0x0000FFFF
.L080B6E38: .4byte 0x03004534 @ IWRAM+0x4534
.L080B6E3C: .4byte 0x0000010F
.L080B6E40: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080B6E44: .4byte 0x01000080
.L080B6E48: .4byte 0xFFFFFF00
.L080B6E4C:
	ldr r0, .L080B6E70
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080B6E80
	ldr r0, .L080B6E74
	ldrh r0, [r0]
	cmp r0, r4
	bne .L080B6E80
	ldr r0, .L080B6E78
	ldr r1, .L080B6E7C
	bl Task_Create
	adds r6, r0, #0
	b .L080B6EFE
	.byte 0x00, 0x00
.L080B6E70: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080B6E74: .4byte 0x03004534 @ IWRAM+0x4534
.L080B6E78: .4byte gUnknown_081641A8
.L080B6E7C: .4byte 0x0000FFFF
.L080B6E80:
	cmp r4, #0x2e
	bne .L080B6E8C
	ldr r0, .L080B6E88
	b .L080B6E9E
.L080B6E88: .4byte gUnknown_0834A01C
.L080B6E8C:
	cmp r4, #0x6d
	bne .L080B6E98
	ldr r0, .L080B6E94
	b .L080B6E9E
.L080B6E94: .4byte gUnknown_0834A0D4
.L080B6E98:
	cmp r4, #0x5d
	bne .L080B6EC4
	ldr r0, .L080B6EB4
.L080B6E9E:
	ldr r1, .L080B6EB8
	bl Task_Create
	adds r6, r0, #0
	ldr r1, .L080B6EBC
	movs r0, #0
	strh r0, [r1, #0x1e]
	ldr r0, .L080B6EC0
	strh r4, [r0]
	b .L080B6EFE
	.byte 0x00, 0x00
.L080B6EB4: .4byte gUnknown_0834A174
.L080B6EB8: .4byte 0x0000FFFF
.L080B6EBC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B6EC0: .4byte 0x03004534 @ IWRAM+0x4534
.L080B6EC4:
	ldr r0, .L080B6F08
	ldr r1, .L080B6F0C
	bl Task_Create
	adds r6, r0, #0
	ldr r0, .L080B6F10
	movs r5, #0
	strh r5, [r0, #0x1e]
	ldr r0, .L080B6F14
	strh r4, [r0]
	ldr r0, .L080B6F18
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080B6EFE
	mov r0, sp
	strh r5, [r0]
	ldr r4, .L080B6F1C
	ldr r2, .L080B6F20
	adds r1, r4, #0
	bl CpuSet
	ldr r1, .L080B6F24
	adds r0, r4, r1
	strh r5, [r0]
	bl Palette_MarkDirty
.L080B6EFE:
	adds r0, r6, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080B6F08: .4byte gUnknown_0816417C
.L080B6F0C: .4byte 0x0000FFFF
.L080B6F10: .4byte 0x03004550 @ IWRAM+0x4550
.L080B6F14: .4byte 0x03004534 @ IWRAM+0x4534
.L080B6F18: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080B6F1C: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080B6F20: .4byte 0x01000080
.L080B6F24: .4byte 0xFFFFFF00

	thumb_func_start sub_080B6F28
sub_080B6F28: @ 0x080B6F28
.L080B6F28:
	ldr r2, .L080B6F3C
	movs r3, #0
	strh r3, [r2, #2]
	ldrh r1, [r0, #0xa]
	strh r1, [r2, #8]
	ldrh r0, [r0, #0xe]
	strh r0, [r2, #0xa]
	strh r3, [r2, #4]
	strh r3, [r2, #6]
	bx lr
.L080B6F3C: .4byte 0x03004520 @ IWRAM+0x4520

	thumb_func_start sub_080B6F40
sub_080B6F40: @ 0x080B6F40
.L080B6F40:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	ldrh r1, [r0, #8]
	str r1, [sp]
	ldr r2, .L080B6F8C
	ldrh r3, [r2, #8]
	mov sb, r3
	ldrh r1, [r0, #0xc]
	str r1, [sp, #4]
	ldrh r3, [r2, #0xa]
	ldrh r1, [r0, #0x10]
	str r1, [sp, #8]
	ldrh r1, [r0, #0x12]
	str r1, [sp, #0xc]
	ldrh r1, [r0, #0x18]
	mov r8, r1
	ldrh r1, [r0, #0x1a]
	str r1, [sp, #0x10]
	ldr r1, [r0]
	ldr r1, [r1]
	str r1, [sp, #0x18]
	ldr r0, [r0, #4]
	str r0, [sp, #0x1c]
	ldrh r7, [r2, #4]
	ldrh r1, [r2, #6]
	movs r4, #0
.L080B6F7C:
	ldr r2, .L080B6F8C
	ldrh r0, [r2, #2]
	ldr r2, [sp, #0x10]
	cmp r0, r2
	blo .L080B6F90
	movs r0, #0
	b .L080B70A8
	.byte 0x00, 0x00
.L080B6F8C: .4byte 0x03004520 @ IWRAM+0x4520
.L080B6F90:
	ldr r5, [sp]
	ldr r6, [sp, #4]
	movs r0, #0
	str r0, [sp, #0x14]
	adds r2, r3, #1
	str r2, [sp, #0x2c]
	ldr r0, [sp, #0xc]
	adds r1, r1, r0
	str r1, [sp, #0x28]
	adds r4, #1
	str r4, [sp, #0x30]
	ldr r1, [sp, #0x14]
	cmp r1, r8
	bhs .L080B706A
	lsrs r0, r3, #3
	lsls r0, r0, #0xa
	ldr r2, [sp, #0x1c]
	adds r0, r2, r0
	str r0, [sp, #0x20]
	movs r0, #7
	mov sl, r0
	ands r3, r0
	lsls r3, r3, #2
	str r3, [sp, #0x24]
.L080B6FC0:
	lsrs r1, r6, #3
	lsls r1, r1, #5
	ldr r2, [sp, #0x20]
	adds r1, r2, r1
	ldr r3, [sp, #0x24]
	adds r1, r1, r3
	adds r0, r6, #0
	mov r2, sl
	ands r0, r2
	lsrs r0, r0, #1
	adds r1, r1, r0
	mov ip, r1
	ldrb r4, [r1]
	mov r3, sb
	lsrs r0, r3, #3
	lsls r0, r0, #0xa
	lsrs r3, r5, #3
	lsls r3, r3, #5
	str r3, [sp, #0x34]
	mov r2, sb
	mov r1, sl
	ands r2, r1
	lsls r2, r2, #2
	adds r1, r5, #0
	mov r3, sl
	ands r1, r3
	lsrs r1, r1, #1
	ldr r3, [sp, #0x18]
	adds r0, r3, r0
	ldr r3, [sp, #0x34]
	adds r0, r0, r3
	adds r0, r0, r2
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r2, r1, #0
	adds r0, r6, #0
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	bne .L080B7026
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	bne .L080B7020
	movs r0, #0xf
	ands r1, r0
	orrs r4, r1
	b .L080B7040
.L080B7020:
	lsrs r0, r1, #4
	orrs r4, r0
	b .L080B7040
.L080B7026:
	adds r0, r5, #0
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	bne .L080B703A
	lsls r0, r1, #4
	orrs r4, r0
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
	b .L080B7040
.L080B703A:
	movs r0, #0xf0
	ands r2, r0
	orrs r4, r2
.L080B7040:
	mov r0, ip
	strb r4, [r0]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r1, [sp, #8]
	adds r7, r7, r1
	cmp r7, r8
	blo .L080B705C
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r2, r8
	subs r7, r7, r2
.L080B705C:
	ldr r0, [sp, #0x14]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x14]
	cmp r0, r8
	blo .L080B6FC0
.L080B706A:
	ldr r3, [sp, #0x2c]
	lsls r0, r3, #0x10
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0x28]
	ldr r0, [sp, #0x10]
	cmp r1, r0
	blo .L080B7086
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	ldr r2, [sp, #0x10]
	subs r1, r1, r2
.L080B7086:
	ldr r2, [sp, #0x30]
	lsls r0, r2, #0x10
	lsrs r4, r0, #0x10
	ldr r2, .L080B70B8
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
	cmp r4, #0xf
	bhi .L080B709A
	b .L080B6F7C
.L080B709A:
	adds r0, r2, #0
	strh r7, [r0, #4]
	strh r1, [r0, #6]
	mov r1, sb
	strh r1, [r0, #8]
	strh r3, [r0, #0xa]
	movs r0, #1
.L080B70A8:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080B70B8: .4byte 0x03004520 @ IWRAM+0x4520

	thumb_func_start sub_080B70BC
sub_080B70BC: @ 0x080B70BC
.L080B70BC:
	push {r4, r5, r6, r7, lr}
	ldr r6, [sp, #0x14]
	ldr r7, [sp, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, .L080B70F4
	movs r5, #0
	strh r2, [r4, #4]
	strh r3, [r4, #6]
	strh r6, [r4, #8]
	str r7, [r4, #0xc]
	ldr r2, .L080B70F8
	str r5, [r2]
	ldr r2, .L080B70FC
	str r1, [r2]
	ldr r1, .L080B7100
	str r0, [r1]
	ldr r1, .L080B7104
	movs r0, #4
	str r0, [r1]
	ldr r0, .L080B7108
	bl SetMainCallback
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B70F4: .4byte 0x03003FD0 @ IWRAM+0x3FD0
.L080B70F8: .4byte 0x03004610 @ IWRAM+0x4610
.L080B70FC: .4byte 0x03004514 @ IWRAM+0x4514
.L080B7100: .4byte 0x03004614 @ IWRAM+0x4614
.L080B7104: .4byte 0x03004544 @ IWRAM+0x4544
.L080B7108: .4byte sub_080C1560

	thumb_func_start sub_080B710C
sub_080B710C: @ 0x080B710C
.L080B710C:
	push {r4, r5, r6, r7, lr}
	ldr r6, [sp, #0x14]
	ldr r7, [sp, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, .L080B7144
	movs r5, #0
	strh r2, [r4, #4]
	strh r3, [r4, #6]
	strh r6, [r4, #8]
	str r7, [r4, #0xc]
	ldr r2, .L080B7148
	str r5, [r2]
	ldr r2, .L080B714C
	str r1, [r2]
	ldr r1, .L080B7150
	str r0, [r1]
	ldr r1, .L080B7154
	movs r0, #6
	str r0, [r1]
	ldr r0, .L080B7158
	bl SetMainCallback
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B7144: .4byte 0x03003FD0 @ IWRAM+0x3FD0
.L080B7148: .4byte 0x03004610 @ IWRAM+0x4610
.L080B714C: .4byte 0x03004514 @ IWRAM+0x4514
.L080B7150: .4byte 0x03004614 @ IWRAM+0x4614
.L080B7154: .4byte 0x03004544 @ IWRAM+0x4544
.L080B7158: .4byte sub_080C1560

	thumb_func_start sub_080B715C
sub_080B715C: @ 0x080B715C
	strh r1, [r0, #0x24]
	bx lr

	thumb_func_start sub_080B7160
sub_080B7160: @ 0x080B7160
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0813EB78
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B7172
	movs r0, #1
	b .L080B7174
.L080B7172:
	movs r0, #0
.L080B7174:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B717C
sub_080B717C: @ 0x080B717C
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L080B718C
	ands r0, r1
	strh r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080B718C: .4byte 0x0000F7FF

	thumb_func_start sub_080B7190
sub_080B7190: @ 0x080B7190
	ldr r1, .L080B71AC
	ldr r2, .L080B71B0
	adds r0, r2, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080B71AC: .4byte 0x0400000E @ REG_BG3CNT
.L080B71B0: .4byte 0x00008607

	thumb_func_start sub_080B71B4
sub_080B71B4: @ 0x080B71B4
	push {lr}
	cmp r1, #1
	beq .L080B71E8
	cmp r1, #1
	blo .L080B71C8
	cmp r1, #2
	beq .L080B71F4
	cmp r1, #3
	beq .L080B7204
	b .L080B7212
.L080B71C8:
	ldr r0, .L080B71DC
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r2, .L080B71E0
	ldr r0, [r2]
	ldr r1, .L080B71E4
	ands r0, r1
	str r0, [r2]
	b .L080B7212
.L080B71DC: .4byte sub_080B717C
.L080B71E0: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080B71E4: .4byte 0xFFFF7FFF
.L080B71E8:
	bl sub_080C14FC
	ldr r0, .L080B71F0
	b .L080B71F6
.L080B71F0: .4byte sub_080C153C
.L080B71F4:
	ldr r0, .L080B7200
.L080B71F6:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B7212
	.byte 0x00, 0x00
.L080B7200: .4byte sub_080ADF64
.L080B7204:
	ldr r0, .L080B7218
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #1
	bl sub_080C3818
.L080B7212:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B7218: .4byte sub_080B7190

	thumb_func_start sub_080B721C
sub_080B721C: @ 0x080B721C
.L080B721C:
	push {lr}
	cmp r0, #0
	beq .L080B7240
	ldrh r0, [r0, #2]
	cmp r0, #0xe
	beq .L080B723C
	cmp r0, #0x24
	beq .L080B723C
	cmp r0, #0x25
	beq .L080B723C
	cmp r0, #0x26
	beq .L080B723C
	cmp r0, #0x27
	beq .L080B723C
	cmp r0, #0x28
	bne .L080B7240
.L080B723C:
	movs r0, #1
	b .L080B7242
.L080B7240:
	movs r0, #0
.L080B7242:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B7248
sub_080B7248: @ 0x080B7248
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r1, #0
	cmp r6, #0
	bne .L080B7344
	ldr r1, .L080B7334
	ldr r4, .L080B7338
	ldrh r0, [r4]
	str r0, [r1]
	ldr r2, .L080B733C
	ldrh r1, [r4, #2]
	str r1, [r2]
	bl sub_080ADCCC
	bl sub_080AE234
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #6]
	bl sub_080AE2A8
	ldr r5, .L080B7340
	ldrh r0, [r4, #8]
	strh r0, [r5, #2]
	bl sub_080AD7F0
	strh r6, [r5, #0x34]
	movs r0, #0
	movs r1, #1
	bl sub_080B2EFC
	adds r4, r0, #0
	movs r1, #4
	bl sub_080B3038
	adds r5, r0, #0
	adds r0, r4, #0
	movs r1, #0x23
	bl sub_080B3038
	mov sl, r0
	adds r0, r4, #0
	movs r1, #1
	bl sub_080B3038
	mov sb, r0
	adds r0, r4, #0
	movs r1, #2
	bl sub_080B3038
	mov r8, r0
	adds r0, r4, #0
	movs r1, #0x1b
	bl sub_080B3038
	adds r7, r0, #0
	adds r0, r4, #0
	movs r1, #0x1c
	bl sub_080B3038
	adds r6, r0, #0
	adds r0, r4, #0
	movs r1, #0xc
	bl sub_080B3038
	cmp r5, #0
	bne .L080B72F4
	mov r1, sb
	cmp r1, #0
	bne .L080B72F4
	mov r1, r8
	cmp r1, #0
	bne .L080B72F4
	cmp r7, #0
	bne .L080B72F4
	cmp r6, #0
	bne .L080B72F4
	cmp r0, #0
	bne .L080B72F4
	mov r0, sl
	bl sub_080B721C
	cmp r0, #0
	beq .L080B7300
.L080B72F4:
	ldr r2, .L080B7340
	ldrh r0, [r2, #0x12]
	ldrh r1, [r2, #0x14]
	ldrh r2, [r2, #2]
	bl sub_080AF5B8
.L080B7300:
	ldr r4, .L080B7340
	ldrh r0, [r4, #0x12]
	ldrh r1, [r4, #0x14]
	bl sub_080AF4EC
	ldr r0, .L080B7334
	ldr r0, [r0]
	cmp r0, #0x4a
	bne .L080B7356
	ldr r0, .L080B733C
	ldr r0, [r0]
	cmp r0, #3
	bne .L080B7356
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne .L080B7356
	ldrh r0, [r4, #0x14]
	cmp r0, #1
	bne .L080B7356
	ldrh r0, [r4, #0x12]
	ldrh r1, [r4, #0x14]
	ldrh r2, [r4, #2]
	bl sub_080AF5B8
	b .L080B7356
	.byte 0x00, 0x00
.L080B7334: .4byte 0x03004614 @ IWRAM+0x4614
.L080B7338: .4byte 0x03003FD0 @ IWRAM+0x3FD0
.L080B733C: .4byte 0x03004514 @ IWRAM+0x4514
.L080B7340: .4byte 0x03004550 @ IWRAM+0x4550
.L080B7344:
	ldr r0, .L080B7364
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
.L080B7356:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B7364: .4byte sub_080ADF64

	thumb_func_start sub_080B7368
sub_080B7368: @ 0x080B7368
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080B7378
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B737C
	movs r0, #1
	b .L080B737E
.L080B7378: .4byte 0x03003FF8 @ IWRAM+0x3FF8
.L080B737C:
	movs r0, #0
.L080B737E:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080B7384
sub_080B7384: @ 0x080B7384
	push {r4, lr}
	movs r0, #0
	movs r1, #0
	movs r2, #0x19
	bl sub_080B3078
	adds r4, r0, #0
	cmp r4, #1
	bne .L080B73AC
	movs r0, #0
	movs r1, #0
	bl sub_080B2EFC
	movs r1, #0x19
	bl sub_080B3038
	ldr r1, .L080B73B4
	ldrh r0, [r0, #2]
	strh r0, [r1, #0x36]
	strh r4, [r1, #0x34]
.L080B73AC:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B73B4: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B73B8
sub_080B73B8: @ 0x080B73B8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, .L080B73E4
	movs r0, #1
	strh r0, [r1]
	bl sub_0813EB78
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B73E8
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	movs r2, #0
	bl sub_080AF8D0
	cmp r0, #0
	beq .L080B73E8
	movs r0, #1
	b .L080B73EA
	.byte 0x00, 0x00
.L080B73E4: .4byte 0x03003FF4 @ IWRAM+0x3FF4
.L080B73E8:
	movs r0, #0
.L080B73EA:
	strh r0, [r5, #0x1c]
	ldr r1, .L080B73F8
	movs r0, #0
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080B73F8: .4byte 0x03003FF4 @ IWRAM+0x3FF4

	thumb_func_start sub_080B73FC
sub_080B73FC: @ 0x080B73FC
	push {lr}
	bl sub_0813EB78
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B740E
	movs r0, #1
	bl Field_SetState
.L080B740E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B7414
sub_080B7414: @ 0x080B7414
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080B7418
sub_080B7418: @ 0x080B7418
	push {lr}
	movs r0, #1
	bl sub_080C3818
	pop {r0}
	bx r0

	thumb_func_start sub_080B7424
sub_080B7424: @ 0x080B7424
	ldr r1, .L080B742C
	movs r0, #0
	strh r0, [r1, #0x34]
	bx lr
.L080B742C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080B7430
sub_080B7430: @ 0x080B7430
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r7, .L080B7488
	movs r6, #0
	ldr r4, .L080B748C
	strh r4, [r7]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r5, #0x10
	str r5, [sp]
	movs r0, #3
	adds r1, r4, #0
	movs r3, #0x40
	bl Palette_FillWithEffect
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r7, r0
	str r5, [sp]
	movs r0, #3
	adds r1, r4, #0
	movs r3, #0x20
	bl Palette_FillWithEffect
	movs r0, #0
	movs r1, #1
	movs r2, #1
	bl PalFade_FadeRangeInFromBlack
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #1
	bl PalFade_FadeRangeInFromBlack
	ldr r1, .L080B7490
	str r0, [r1]
	ldr r0, .L080B7494
	adds r0, #0x60
	strh r6, [r0]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B7488: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B748C: .4byte 0x00007FFF
.L080B7490: .4byte 0x0300452C @ IWRAM+0x452C
.L080B7494: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B7498
sub_080B7498: @ 0x080B7498
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L080B74EC
	ldr r1, [r0]
	ldr r5, .L080B74F0
	ldrh r0, [r1]
	strh r0, [r5]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r0, .L080B74F4
	ldr r1, [r0]
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r5, r0
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #8
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	ldr r1, .L080B74F8
	str r0, [r1]
	ldr r0, .L080B74FC
	adds r0, #0x60
	movs r1, #1
	strh r1, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080B74EC: .4byte 0x03004630 @ IWRAM+0x4630
.L080B74F0: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B74F4: .4byte 0x03004510 @ IWRAM+0x4510
.L080B74F8: .4byte 0x0300452C @ IWRAM+0x452C
.L080B74FC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B7500
sub_080B7500: @ 0x080B7500
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldr r0, .L080B7528
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne .L080B7522
	bl sub_080B04BC
	movs r0, #1
	bl PalFade_FadeInFromBlack
	ldr r1, .L080B752C
	str r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080B7522:
	pop {r4}
	pop {r0}
	bx r0
.L080B7528: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080B752C: .4byte 0x0300452C @ IWRAM+0x452C

	thumb_func_start sub_080B7530
sub_080B7530: @ 0x080B7530
.L080B7530:
	push {lr}
	ldr r0, .L080B7540
	ldrh r0, [r0]
	cmp r0, #0x2e
	bne .L080B7548
	ldr r0, .L080B7544
	b .L080B754E
	.byte 0x00, 0x00
.L080B7540: .4byte 0x03004534 @ IWRAM+0x4534
.L080B7544: .4byte gUnknown_0834A0B0
.L080B7548:
	cmp r0, #0x6d
	bne .L080B7560
	ldr r0, .L080B7558
.L080B754E:
	ldr r1, .L080B755C
	bl Task_Create
	b .L080B756C
	.byte 0x00, 0x00
.L080B7558: .4byte gUnknown_0834A150
.L080B755C: .4byte 0x0000FFFF
.L080B7560:
	cmp r0, #0x5d
	bne .L080B756C
	ldr r0, .L080B7570
	ldr r1, .L080B7574
	bl Task_Create
.L080B756C:
	pop {r0}
	bx r0
.L080B7570: .4byte gUnknown_0834A1F0
.L080B7574: .4byte 0x0000FFFF

	thumb_func_start sub_080B7578
sub_080B7578: @ 0x080B7578
	push {lr}
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x2e
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B758C
sub_080B758C: @ 0x080B758C
.L080B758C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r4, [sp, #0x18]
	ldr r7, [sp, #0x1c]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	ldr r6, .L080B75D8
	ldr r4, .L080B75DC
	strh r5, [r4]
	str r5, [r6]
	ldr r5, .L080B75E0
	strh r1, [r4, #2]
	str r1, [r5]
	ldr r1, .L080B75E4
	strh r2, [r4, #4]
	strh r2, [r1, #0x12]
	strh r3, [r4, #6]
	strh r3, [r1, #0x14]
	mov r2, r8
	strh r2, [r4, #8]
	strh r2, [r1, #2]
	str r7, [r4, #0xc]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080B75D8: .4byte 0x03004614 @ IWRAM+0x4614
.L080B75DC: .4byte 0x03003FD0 @ IWRAM+0x3FD0
.L080B75E0: .4byte 0x03004514 @ IWRAM+0x4514
.L080B75E4: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B75E8
sub_080B75E8: @ 0x080B75E8
.L080B75E8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r4, [sp, #0x28]
	ldr r7, [sp, #0x2c]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080B7640
	ldr r1, .L080B7644
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	bl Task_Create
	mov r8, r0
	str r4, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	adds r1, r6, #0
	ldr r2, [sp, #8]
	ldr r3, [sp, #0xc]
	bl sub_080B758C
	ldr r1, .L080B7648
	movs r0, #1
	strh r0, [r1, #0xa]
	mov r0, r8
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B7640: .4byte gUnknown_081641B4
.L080B7644: .4byte 0x0000FFFF
.L080B7648: .4byte 0x03003FD0 @ IWRAM+0x3FD0

	thumb_func_start sub_080B764C
sub_080B764C: @ 0x080B764C
.L080B764C:
	push {r4, r5, lr}
	sub sp, #8
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp]
	str r5, [sp, #4]
	bl sub_080B75E8
	ldr r2, .L080B7680
	movs r1, #1
	strh r1, [r2, #0xa]
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B7680: .4byte 0x03003FD0 @ IWRAM+0x3FD0

	thumb_func_start sub_080B7684
sub_080B7684: @ 0x080B7684
	push {r4, r5, lr}
	ldr r0, .L080B76C4
	ldrb r0, [r0, #8]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	movs r2, #3
	bl sub_080C2CD8
	movs r5, #0x84
	lsls r5, r5, #1
	adds r0, r5, #0
	bl Flag_Test
	cmp r0, #0
	beq .L080B76BE
	ldr r0, .L080B76C8
	adds r4, r0, #0
	adds r4, #0x50
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080B76BE
	bl sub_080B0C7C
	movs r0, #0
	strh r0, [r4]
	adds r0, r5, #0
	bl Flag_Clear
.L080B76BE:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080B76C4: .4byte 0x030069F0 @ IWRAM+0x69F0
.L080B76C8: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B76CC
sub_080B76CC: @ 0x080B76CC
	ldr r1, .L080B76D4
	movs r0, #1
	strh r0, [r1, #0x34]
	bx lr
.L080B76D4: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080B76D8
sub_080B76D8: @ 0x080B76D8
	push {lr}
	movs r0, #0xae
	bl Flag_Test
	cmp r0, #0
	beq .L080B7728
	movs r0, #0x5e
	bl Flag_Test
	cmp r0, #0
	beq .L080B76F8
	ldr r1, .L080B76F4
	b .L080B7704
	.byte 0x00, 0x00
.L080B76F4: .4byte gUnknown_0804C354
.L080B76F8:
	movs r0, #0x5f
	bl Flag_Test
	cmp r0, #0
	beq .L080B7710
	ldr r1, .L080B770C
.L080B7704:
	movs r0, #0xc
	bl sub_080AF178
	b .L080B7718
.L080B770C: .4byte gUnknown_0804C564
.L080B7710:
	ldr r1, .L080B772C
	movs r0, #0xc
	bl sub_080AF178
.L080B7718:
	ldr r0, .L080B7730
	movs r1, #0
	str r1, [r0]
	ldr r0, .L080B7734
	movs r2, #0xac
	lsls r2, r2, #4
	adds r0, r0, r2
	strh r1, [r0]
.L080B7728:
	pop {r0}
	bx r0
.L080B772C: .4byte gUnknown_0804CB9C
.L080B7730: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B7734: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_080B7738
sub_080B7738: @ 0x080B7738
.L080B7738:
	push {r4, r5, r6, lr}
	ldr r0, [sp, #0x10]
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0xae
	bl Flag_Test
	cmp r0, #0
	beq .L080B775C
	ldr r0, .L080B7758
	b .L080B775E
	.byte 0x00, 0x00
.L080B7758: .4byte gUnknown_08164460
.L080B775C:
	ldr r0, .L080B7780
.L080B775E:
	ldr r1, .L080B7784
	bl Task_Create
	adds r2, r0, #0
	ldr r0, .L080B7788
	movs r1, #0x7f
	ands r1, r5
	strh r1, [r0, #4]
	strh r6, [r0, #6]
	strh r4, [r0, #8]
	movs r1, #1
	strh r1, [r0, #0xa]
	adds r0, r2, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B7780: .4byte gUnknown_081643D0
.L080B7784: .4byte 0x0000FFFF
.L080B7788: .4byte 0x03003FD0 @ IWRAM+0x3FD0

	thumb_func_start sub_080B778C
sub_080B778C: @ 0x080B778C
.L080B778C:
	push {r4, r5, lr}
	sub sp, #8
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp]
	str r5, [sp, #4]
	bl sub_080B7738
	ldr r2, .L080B77C0
	movs r1, #1
	strh r1, [r2, #0xa]
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B77C0: .4byte 0x03003FD0 @ IWRAM+0x3FD0

	thumb_func_start sub_080B77C4
sub_080B77C4: @ 0x080B77C4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x28]
	cmp r0, #2
	bne .L080B77FC
	movs r6, #0
	movs r5, #1
	strh r5, [r4, #0x1c]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080B77F0
	strh r6, [r4, #0x1e]
	ldr r1, .L080B77EC
	movs r0, #0x1a
	str r0, [r1]
	b .L080B7800
.L080B77EC: .4byte 0x03004530 @ IWRAM+0x4530
.L080B77F0:
	ldr r0, .L080B77F8
	strh r6, [r0, #0x2e]
	strh r5, [r4, #0x1e]
	b .L080B7800
.L080B77F8: .4byte 0x03004550 @ IWRAM+0x4550
.L080B77FC:
	movs r0, #0
	strh r0, [r4, #0x1c]
.L080B7800:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B7808
sub_080B7808: @ 0x080B7808
	push {r4, lr}
	movs r0, #1
	bl sub_080C3818
	ldr r4, .L080B7828
	ldrh r1, [r4, #2]
	movs r0, #0xc
	bl sub_080B1AD8
	adds r4, #0x46
	movs r0, #1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B7828: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B782C
sub_080B782C: @ 0x080B782C
	push {lr}
	movs r0, #1
	bl sub_080C3818
	ldr r0, .L080B7848
	ldr r1, .L080B784C
	bl Task_Create
	movs r0, #0x1a
	bl Field_SetState
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B7848: .4byte gUnknown_0816499C
.L080B784C: .4byte 0x0000FFFF

	thumb_func_start sub_080B7850
sub_080B7850: @ 0x080B7850
	push {lr}
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	pop {r0}
	bx r0

	thumb_func_start sub_080B7860
sub_080B7860: @ 0x080B7860
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080B7870
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne .L080B7874
	movs r0, #1
	b .L080B7876
.L080B7870: .4byte 0x03004550 @ IWRAM+0x4550
.L080B7874:
	movs r0, #0
.L080B7876:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080B787C
sub_080B787C: @ 0x080B787C
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080B7894
	adds r2, r0, #0
	adds r2, #0x5e
	ldrh r0, [r2]
	cmp r0, #0
	bne .L080B7898
	movs r0, #1
	strh r0, [r1, #0x1c]
	b .L080B789E
	.byte 0x00, 0x00
.L080B7894: .4byte 0x03004550 @ IWRAM+0x4550
.L080B7898:
	movs r0, #0
	strh r0, [r1, #0x1c]
	strh r0, [r2]
.L080B789E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B78A4
sub_080B78A4: @ 0x080B78A4
.L080B78A4:
	push {r4, lr}
	ldr r4, .L080B78C0
	ldr r1, .L080B78C4
	adds r2, r1, #0
	ldr r0, .L080B78C8
	adds r3, r1, r0
.L080B78B0:
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080B78CC
	ldr r0, [r1, #0x20]
	cmp r0, r4
	bne .L080B78CC
	adds r0, r2, #0
	b .L080B78D6
.L080B78C0: .4byte sub_080B7414
.L080B78C4: .4byte 0x02009004 @ EWRAM+0x9004
.L080B78C8: .4byte 0x0000189C
.L080B78CC:
	adds r1, #0x64
	adds r2, #0x64
	cmp r1, r3
	bls .L080B78B0
	movs r0, #0
.L080B78D6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080B78DC
sub_080B78DC: @ 0x080B78DC
.L080B78DC:
	push {r4, lr}
	ldr r4, .L080B78F8
	ldr r1, .L080B78FC
	adds r2, r1, #0
	ldr r0, .L080B7900
	adds r3, r1, r0
.L080B78E8:
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080B7904
	ldr r0, [r1, #0x20]
	cmp r0, r4
	bne .L080B7904
	adds r0, r2, #0
	b .L080B790E
.L080B78F8: .4byte sub_080B2AB0
.L080B78FC: .4byte 0x02009004 @ EWRAM+0x9004
.L080B7900: .4byte 0x0000189C
.L080B7904:
	adds r1, #0x64
	adds r2, #0x64
	cmp r1, r3
	bls .L080B78E8
	movs r0, #0
.L080B790E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080B7914
sub_080B7914: @ 0x080B7914
.L080B7914:
	push {lr}
	adds r3, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldrh r0, [r3]
	cmp r0, r1
	bhi .L080B793C
	ldrh r0, [r3, #2]
	cmp r0, r2
	bhi .L080B793C
	ldrh r0, [r3, #4]
	cmp r0, r1
	blo .L080B793C
	ldrh r0, [r3, #6]
	cmp r0, r2
	blo .L080B793C
	movs r0, #0
	b .L080B793E
.L080B793C:
	movs r0, #1
.L080B793E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B7944
sub_080B7944: @ 0x080B7944
.L080B7944:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bne .L080B7958
	b .L080B7AEE
.L080B7958:
	adds r0, r4, #0
	adds r0, #0x10
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B796C
	b .L080B7AF2
.L080B796C:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	bne .L080B7974
	b .L080B7AEE
.L080B7974:
	adds r0, r4, #0
	adds r0, #0x18
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B7988
	b .L080B7AF2
.L080B7988:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	bne .L080B7990
	b .L080B7AEE
.L080B7990:
	adds r0, r4, #0
	adds r0, #0x20
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B79A4
	b .L080B7AF2
.L080B79A4:
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne .L080B79AC
	b .L080B7AEE
.L080B79AC:
	adds r0, r4, #0
	adds r0, #0x28
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B79C0
	b .L080B7AF2
.L080B79C0:
	ldr r0, [r4, #0x34]
	cmp r0, #0
	bne .L080B79C8
	b .L080B7AEE
.L080B79C8:
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B79DC
	b .L080B7AF2
.L080B79DC:
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	bne .L080B79E4
	b .L080B7AEE
.L080B79E4:
	adds r0, r4, #0
	adds r0, #0x38
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B7AF2
	ldr r0, [r4, #0x44]
	cmp r0, #0
	beq .L080B7AEE
	adds r0, r4, #0
	adds r0, #0x40
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B7AF2
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L080B7AEE
	adds r0, r4, #0
	adds r0, #0x48
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B7AF2
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq .L080B7AEE
	adds r0, r4, #0
	adds r0, #0x50
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B7AF2
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	beq .L080B7AEE
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B7AF2
	ldr r0, [r4, #0x64]
	cmp r0, #0
	beq .L080B7AEE
	adds r0, r4, #0
	adds r0, #0x60
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B7AF2
	ldr r0, [r4, #0x6c]
	cmp r0, #0
	beq .L080B7AEE
	adds r0, r4, #0
	adds r0, #0x68
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B7AF2
	ldr r0, [r4, #0x74]
	cmp r0, #0
	beq .L080B7AEE
	adds r0, r4, #0
	adds r0, #0x70
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B7AF2
	ldr r0, [r4, #0x7c]
	cmp r0, #0
	beq .L080B7AEE
	adds r0, r4, #0
	adds r0, #0x78
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B7AF2
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	cmp r0, #0
	beq .L080B7AEE
	adds r0, r4, #0
	adds r0, #0x80
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B7AF2
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	cmp r0, #0
	beq .L080B7AEE
	adds r0, r4, #0
	adds r0, #0x88
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080B7914
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B7AF2
.L080B7AEE:
	movs r0, #1
	b .L080B7AF4
.L080B7AF2:
	movs r0, #0
.L080B7AF4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B7AFC
sub_080B7AFC: @ 0x080B7AFC
.L080B7AFC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r4, [sp, #0x3c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0xc]
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	mov r8, r6
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080B7B48
	movs r1, #0xac
	lsls r1, r1, #4
	adds r7, r0, r1
	ldrh r2, [r7]
	str r2, [sp, #0x18]
	ldr r0, .L080B7B4C
	ldr r1, [r0]
	ldr r0, .L080B7B50
	cmp r1, r0
	bne .L080B7B54
	mov r0, sl
	ldr r1, [sp, #0xc]
	bl sub_080BF300
	b .L080B7D30
	.byte 0x00, 0x00
.L080B7B48: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B7B4C: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080B7B50: .4byte sub_080D977C
.L080B7B54:
	ldr r5, .L080B7B94
	ldr r0, [r5]
	cmp r0, #1
	bne .L080B7B64
	movs r0, #0
	str r0, [r5]
	bl sub_080C2CC0
.L080B7B64:
	cmp r4, #1
	bne .L080B7BAC
	str r4, [r5]
	movs r5, #0
	strh r4, [r7]
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne .L080B7B7A
	movs r0, #0
	bl sub_080C2230
.L080B7B7A:
	ldr r1, [sp, #8]
	cmp r1, #1
	bne .L080B7B98
	str r6, [sp]
	str r5, [sp, #4]
	movs r0, #0
	movs r1, #0
	mov r2, sl
	ldr r3, [sp, #0xc]
	bl sub_080B7738
	b .L080B7D30
	.byte 0x00, 0x00
.L080B7B94: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B7B98:
	mov r2, r8
	str r2, [sp]
	str r5, [sp, #4]
	movs r0, #0
	movs r1, #0
	mov r2, sl
	ldr r3, [sp, #0xc]
	bl sub_080B778C
	b .L080B7D30
.L080B7BAC:
	mov r7, sl
	movs r0, #0x3f
	ldr r1, [sp, #0xc]
	ands r1, r0
	mov sb, r1
	movs r2, #0
	mov r8, r2
	b .L080B7C22
.L080B7BBC:
	mov r0, r8
	str r0, [sp, #0x10]
	str r5, [sp, #0x14]
	ldrh r0, [r4, #8]
	subs r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrh r0, [r4, #0xa]
	mov r1, sb
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	b .L080B7C14
.L080B7BD8:
	movs r5, #0
	cmp r5, r6
	bhs .L080B7C14
.L080B7BDE:
	ldrh r0, [r4, #8]
	cmp r0, r7
	bhi .L080B7C04
	ldrh r0, [r4, #0xa]
	cmp r0, sb
	bhi .L080B7C04
	ldrh r0, [r4, #0xc]
	cmp r0, r7
	blo .L080B7C04
	ldrh r0, [r4, #0xe]
	cmp r0, sb
	blo .L080B7C04
	adds r0, r4, #0
	adds r1, r7, #0
	mov r2, sb
	bl sub_080B7944
	cmp r0, #1
	beq .L080B7BBC
.L080B7C04:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r4, r4, r2
	cmp r5, r6
	blo .L080B7BDE
.L080B7C14:
	cmp r5, r6
	bne .L080B7C38
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
.L080B7C22:
	mov r0, r8
	bl sub_080C8B3C
	adds r6, r0, #0
	mov r0, r8
	movs r1, #0
	bl sub_080C8B10
	adds r4, r0, #0
	cmp r4, #0
	bne .L080B7BD8
.L080B7C38:
	movs r4, #0x3f
	ldr r0, [sp, #0xc]
	ands r4, r0
	mov r0, sl
	adds r1, r4, #0
	bl sub_080AF4B8
	mov r1, sl
	cmp r1, #0x14
	bne .L080B7C58
	cmp r4, #0xd
	bne .L080B7C58
	movs r0, #0x14
	movs r1, #0xe
	bl sub_080AF4B8
.L080B7C58:
	mov r2, sl
	cmp r2, #0x77
	bne .L080B7C70
	movs r0, #0x3f
	ldr r1, [sp, #0xc]
	ands r0, r1
	cmp r0, #0xa
	bne .L080B7C70
	movs r0, #0x77
	movs r1, #0xb
	bl sub_080AF4B8
.L080B7C70:
	ldr r0, .L080B7CF0
	movs r2, #0xac
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrh r2, [r0]
	ldr r1, [sp, #0xc]
	lsrs r0, r1, #5
	movs r1, #6
	ands r0, r1
	lsrs r4, r0, #1
	cmp r2, #1
	bne .L080B7C94
	bl sub_080B098C
	cmp r0, #1
	bne .L080B7C94
	bl sub_080C1384
.L080B7C94:
	ldr r2, [sp, #0x18]
	cmp r2, #1
	bne .L080B7CA0
	movs r0, #0
	bl sub_080C2230
.L080B7CA0:
	ldr r1, .L080B7CF4
	movs r0, #0x19
	str r0, [r1]
	ldr r0, .L080B7CF8
	movs r1, #0
	str r1, [r0]
	ldr r0, .L080B7CF0
	movs r2, #0xac
	lsls r2, r2, #4
	adds r0, r0, r2
	strh r1, [r0]
	ldr r0, .L080B7CFC
	ldr r0, [r0]
	ldr r1, [sp, #0x10]
	cmp r0, r1
	beq .L080B7CC4
	bl sub_080C2CC0
.L080B7CC4:
	ldr r2, [sp, #0x18]
	cmp r2, #1
	bne .L080B7CDC
	mov r0, sl
	lsls r1, r0, #0x18
	lsrs r1, r1, #0x18
	ldr r0, [sp, #0xc]
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x18
	ldr r0, [sp, #0x10]
	bl sub_080B7F2C
.L080B7CDC:
	bl sub_080AE294
	ldr r0, [sp, #0x10]
	bl sub_080C8AF8
	cmp r0, #1
	bne .L080B7D00
	bl sub_080C7C94
	b .L080B7D04
.L080B7CF0: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B7CF4: .4byte 0x03004530 @ IWRAM+0x4530
.L080B7CF8: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B7CFC: .4byte 0x03004614 @ IWRAM+0x4614
.L080B7D00:
	bl sub_080C7C60
.L080B7D04:
	ldr r1, [sp, #8]
	cmp r1, #1
	beq .L080B7D1E
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	adds r2, r7, #0
	mov r3, sb
	bl sub_080B764C
	b .L080B7D30
.L080B7D1E:
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	adds r2, r7, #0
	mov r3, sb
	bl sub_080B75E8
.L080B7D30:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080B7D40
sub_080B7D40: @ 0x080B7D40
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	mov r8, r0
	ldr r5, .L080B7D88
	ldrh r0, [r5, #0x12]
	ldrh r1, [r5, #0x14]
	mov r4, sp
	adds r4, #2
	mov r2, sp
	adds r3, r4, #0
	bl sub_080C1F50
	ldr r0, .L080B7D8C
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L080B7DEA
	ldrh r0, [r5, #2]
	cmp r0, #1
	beq .L080B7DC2
	cmp r0, #1
	bgt .L080B7D90
	cmp r0, #0
	beq .L080B7D9A
	b .L080B7DEA
	.byte 0x00, 0x00
.L080B7D88: .4byte 0x03004550 @ IWRAM+0x4550
.L080B7D8C: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080B7D90:
	cmp r0, #2
	beq .L080B7D9A
	cmp r0, #3
	beq .L080B7DC2
	b .L080B7DEA
.L080B7D9A:
	ldrh r0, [r4]
	subs r0, r0, r6
	cmp r0, #1
	bne .L080B7DAE
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, r7
	bne .L080B7DAE
	movs r0, #0
	mov r8, r0
.L080B7DAE:
	ldrh r0, [r4]
	subs r0, r6, r0
	cmp r0, #1
	bne .L080B7DEA
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, r7
	bne .L080B7DEA
	movs r0, #2
	b .L080B7DE8
.L080B7DC2:
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r0, r7
	cmp r0, #1
	bne .L080B7DD6
	ldrh r0, [r4]
	cmp r0, r6
	bne .L080B7DD6
	movs r0, #3
	mov r8, r0
.L080B7DD6:
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r7, r0
	cmp r0, #1
	bne .L080B7DEA
	ldrh r0, [r4]
	cmp r0, r6
	bne .L080B7DEA
	movs r0, #1
.L080B7DE8:
	mov r8, r0
.L080B7DEA:
	mov r0, r8
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080B7DF8
sub_080B7DF8: @ 0x080B7DF8
.L080B7DF8:
	push {lr}
	movs r1, #0
	ldrh r0, [r0, #0x24]
	cmp r0, #1
	bne .L080B7E04
	movs r1, #1
.L080B7E04:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B7E0C
sub_080B7E0C: @ 0x080B7E0C
.L080B7E0C:
	push {r4, lr}
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B7E18
	movs r4, #2
	b .L080B7E1E
.L080B7E18:
	ldr r0, .L080B7E30
	movs r4, #0x1a
	str r4, [r0]
.L080B7E1E:
	ldr r0, .L080B7E34
	ldr r1, .L080B7E38
	bl Task_Create
	strh r4, [r0, #0x28]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B7E30: .4byte 0x03004530 @ IWRAM+0x4530
.L080B7E34: .4byte gUnknown_081644B4
.L080B7E38: .4byte 0x0000FFFF

	thumb_func_start sub_080B7E3C
sub_080B7E3C: @ 0x080B7E3C
.L080B7E3C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sl, r2
	lsrs r6, r1, #0x10
	movs r0, #0x3f
	mov r1, sl
	ands r1, r0
	mov r8, r1
	movs r0, #0
	b .L080B7EC6
.L080B7E5E:
	mov r1, sb
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	ldrh r0, [r5, #8]
	subs r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldrh r0, [r5, #0xa]
	mov r1, r8
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	b .L080B7EBA
.L080B7E7A:
	movs r4, #0
	cmp r4, r7
	bhs .L080B7EBA
.L080B7E80:
	ldrh r0, [r5, #8]
	cmp r0, r6
	bhi .L080B7EAA
	ldrh r0, [r5, #0xa]
	cmp r0, r8
	bhi .L080B7EAA
	ldrh r0, [r5, #0xc]
	cmp r0, r6
	blo .L080B7EAA
	ldrh r0, [r5, #0xe]
	cmp r0, r8
	blo .L080B7EAA
	adds r0, r5, #0
	adds r1, r6, #0
	mov r2, r8
	str r3, [sp, #0x10]
	bl sub_080B7944
	ldr r3, [sp, #0x10]
	cmp r0, #1
	beq .L080B7E5E
.L080B7EAA:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r5, r5, r0
	cmp r4, r7
	blo .L080B7E80
.L080B7EBA:
	cmp r4, r7
	bne .L080B7EE2
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080B7EC6:
	mov sb, r0
	mov r0, sb
	bl sub_080C8B3C
	adds r7, r0, #0
	mov r0, sb
	movs r1, #0
	bl sub_080C8B10
	adds r5, r0, #0
	mov r1, sl
	lsrs r3, r1, #5
	cmp r5, #0
	bne .L080B7E7A
.L080B7EE2:
	movs r0, #6
	ands r3, r0
	lsrs r4, r3, #1
	bl sub_080C2CC0
	ldr r0, .L080B7F20
	ldr r1, .L080B7F24
	bl Task_Create
	adds r5, r0, #0
	str r4, [sp]
	ldr r0, [sp, #0x34]
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	adds r2, r6, #0
	mov r3, r8
	bl sub_080B758C
	ldr r1, .L080B7F28
	movs r0, #1
	strh r0, [r1, #0xa]
	adds r0, r5, #0
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080B7F20: .4byte gUnknown_08164670
.L080B7F24: .4byte 0x0000FFFF
.L080B7F28: .4byte 0x03003FD0 @ IWRAM+0x3FD0

	thumb_func_start sub_080B7F2C
sub_080B7F2C: @ 0x080B7F2C
.L080B7F2C:
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, .L080B7F60
	ldrh r0, [r0]
	adds r1, r3, #0
	bl sub_080C2D48
	ldr r0, .L080B7F64
	ldr r2, .L080B7F68
	adds r1, r0, r2
	strb r4, [r1]
	ldr r1, .L080B7F6C
	adds r0, r0, r1
	strb r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B7F60: .4byte 0x03003FC4 @ IWRAM+0x3FC4
.L080B7F64: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B7F68: .4byte 0x000018C2
.L080B7F6C: .4byte 0x000018C3

	thumb_func_start sub_080B7F70
sub_080B7F70: @ 0x080B7F70
	ldr r1, .L080B7F78
	movs r0, #0
	strb r0, [r1]
	bx lr
.L080B7F78: .4byte 0x0300003C @ IWRAM+0x3C

	thumb_func_start sub_080B7F7C
sub_080B7F7C: @ 0x080B7F7C
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldrh r0, [r1, #2]
	subs r0, #1
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B7FDA
	movs r0, #3
	strh r0, [r1, #2]
	ldrh r0, [r2, #0x24]
	cmp r0, #0
	bne .L080B7FC4
	ldr r1, .L080B7FBC
	ldrb r0, [r1]
	adds r0, #0x10
	strb r0, [r1]
	ldrb r1, [r1]
	lsls r0, r3, #4
	cmp r1, r0
	bls .L080B7FDA
	movs r0, #1
	strh r0, [r2, #0x24]
	ldr r0, .L080B7FC0
	bl sub_080C51D4
	b .L080B7FDA
.L080B7FBC: .4byte 0x0300003C @ IWRAM+0x3C
.L080B7FC0: .4byte 0x00000153
.L080B7FC4:
	ldr r1, .L080B7FE4
	ldrb r0, [r1]
	subs r0, #0x10
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne .L080B7FDA
	strh r0, [r2, #0x24]
	movs r0, #1
	strh r0, [r2, #0x1c]
.L080B7FDA:
	bl sub_080B0AE0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B7FE4: .4byte 0x0300003C @ IWRAM+0x3C

	thumb_func_start sub_080B7FE8
sub_080B7FE8: @ 0x080B7FE8
	push {lr}
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #6
	bl PalFade_FadeRangeToWhite
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #6
	bl PalFade_FadeRangeToWhite
	pop {r0}
	bx r0

	thumb_func_start sub_080B8004
sub_080B8004: @ 0x080B8004
	push {lr}
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #6
	bl PalFade_FadeRangeToBlack
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #6
	bl PalFade_FadeRangeToBlack
	pop {r0}
	bx r0

	thumb_func_start sub_080B8020
sub_080B8020: @ 0x080B8020
.L080B8020:
	push {lr}
	ldr r0, .L080B803C
	ldr r1, .L080B8040
	bl Task_Create
	adds r2, r0, #0
	movs r1, #3
	strh r1, [r2, #0x26]
	ldr r2, .L080B8044
	movs r1, #0x77
	strh r1, [r2]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B803C: .4byte gUnknown_081646C0
.L080B8040: .4byte 0x0000FFFF
.L080B8044: .4byte 0x03004534 @ IWRAM+0x4534

	thumb_func_start sub_080B8048
sub_080B8048: @ 0x080B8048
	push {r4, lr}
	adds r4, r1, #0
	cmp r4, #0
	bne .L080B8078
	ldr r0, .L080B806C
	ldr r0, [r0]
	ldr r1, .L080B8070
	ldr r1, [r1]
	bl sub_080ADCCC
	bl sub_080AE234
	bl sub_080AD7F0
	ldr r0, .L080B8074
	strh r4, [r0, #0x34]
	b .L080B8082
	.byte 0x00, 0x00
.L080B806C: .4byte 0x03004614 @ IWRAM+0x4614
.L080B8070: .4byte 0x03004514 @ IWRAM+0x4514
.L080B8074: .4byte 0x03004550 @ IWRAM+0x4550
.L080B8078:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
.L080B8082:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B8088
sub_080B8088: @ 0x080B8088
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	strh r5, [r4, #0x1c]
	cmp r1, #0
	bne .L080B80CC
	ldr r2, .L080B80BC
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080B80EE
	ldr r0, .L080B80C0
	strh r5, [r0]
	ldr r0, .L080B80C4
	ands r1, r0
	str r1, [r2]
	bl sub_080C14FC
	ldr r0, .L080B80C8
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B80D6
	.byte 0x00, 0x00
.L080B80BC: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080B80C0: .4byte 0x03003BBC @ IWRAM+0x3BBC
.L080B80C4: .4byte 0xFFFF7FFF
.L080B80C8: .4byte sub_080C153C
.L080B80CC:
	ldr r0, .L080B80DC
	ldrh r1, [r0]
	ldr r0, .L080B80E0
	cmp r1, r0
	bne .L080B80E4
.L080B80D6:
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080B80EE
.L080B80DC: .4byte 0x03003BBC @ IWRAM+0x3BBC
.L080B80E0: .4byte 0x0000FFFF
.L080B80E4:
	ldr r0, .L080B80F4
	movs r1, #1
	bl VBlankTask_AddCounted
	strh r5, [r4, #0x1c]
.L080B80EE:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080B80F4: .4byte sub_080AE0BC

	thumb_func_start sub_080B80F8
sub_080B80F8: @ 0x080B80F8
.L080B80F8:
	push {r4, r5, lr}
	bl sub_080B78A4
	adds r5, r0, #0
	cmp r5, #0
	beq .L080B8120
	ldr r0, .L080B8118
	ldr r1, .L080B811C
	bl Task_Create
	adds r4, r0, #0
	adds r0, r5, #0
	bl Task_End
	b .L080B814E
	.byte 0x00, 0x00
.L080B8118: .4byte gUnknown_08164788
.L080B811C: .4byte 0x0000FFFF
.L080B8120:
	bl sub_080B098C
	cmp r0, #0
	bne .L080B8144
	ldr r0, .L080B813C
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L080B8144
	ldr r0, .L080B8140
	b .L080B8146
	.byte 0x00, 0x00
.L080B813C: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080B8140: .4byte gUnknown_08164990
.L080B8144:
	ldr r0, .L080B8158
.L080B8146:
	ldr r1, .L080B815C
	bl Task_Create
	adds r4, r0, #0
.L080B814E:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B8158: .4byte gUnknown_081648AC
.L080B815C: .4byte 0x0000FFFF

	thumb_func_start sub_080B8160
sub_080B8160: @ 0x080B8160
.L080B8160:
	push {lr}
	movs r1, #0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B816C
	movs r1, #1
.L080B816C:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B8174
sub_080B8174: @ 0x080B8174
	push {r4, r5, r6, lr}
	movs r6, #0xc
	ldr r5, .L080B8194
	ldrh r4, [r5, #2]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #3
	bne .L080B8198
	movs r0, #0xc
	adds r1, r4, #0
	bl sub_080B1A30
	b .L080B81BA
.L080B8194: .4byte 0x03004550 @ IWRAM+0x4550
.L080B8198:
	cmp r0, #2
	bne .L080B81A6
	strh r6, [r5, #0xa]
	movs r0, #0xc
	adds r1, r4, #0
	movs r2, #3
	b .L080B81AE
.L080B81A6:
	strh r6, [r5, #0xa]
	movs r0, #0xc
	adds r1, r4, #0
	movs r2, #2
.L080B81AE:
	bl sub_080B2030
	adds r1, r5, #0
	adds r1, #0x46
	movs r0, #1
	strh r0, [r1]
.L080B81BA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080B81C0
sub_080B81C0: @ 0x080B81C0
	push {r4, lr}
	sub sp, #0xc
	adds r2, r0, #0
	adds r4, r2, #0
	adds r4, #0x24
	ldrh r0, [r4, #2]
	cmp r0, #0x52
	beq .L080B81F0
	ldr r0, .L080B81EC
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r2, #0x24]
	str r1, [sp, #4]
	ldrh r1, [r4, #2]
	str r1, [sp, #8]
	movs r1, #9
	movs r2, #0
	movs r3, #3
	bl Sprite_DrawBlended
	b .L080B8212
	.byte 0x00, 0x00
.L080B81EC: .4byte gUnknown_0800107C
.L080B81F0:
	ldr r0, [r4, #4]
	lsrs r1, r0, #4
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne .L080B8212
	ldr r0, .L080B8228
	str r1, [sp]
	ldrh r1, [r2, #0x24]
	str r1, [sp, #4]
	ldrh r1, [r4, #2]
	str r1, [sp, #8]
	movs r1, #9
	movs r2, #0
	movs r3, #3
	bl Sprite_DrawBlended
.L080B8212:
	ldrh r0, [r4, #2]
	cmp r0, #0x52
	bne .L080B821E
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
.L080B821E:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B8228: .4byte gUnknown_0800107C

	thumb_func_start sub_080B822C
sub_080B822C: @ 0x080B822C
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r2, #0
	adds r4, #0x24
	movs r3, #1
	strh r3, [r2, #0x1e]
	ldrh r0, [r4, #2]
	cmp r0, #0x52
	bne .L080B825C
	ldr r0, .L080B8254
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080B825C
	strh r3, [r2, #0x1c]
	ldr r0, .L080B8258
	strh r3, [r0, #0x3e]
	b .L080B8270
	.byte 0x00, 0x00
.L080B8254: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080B8258: .4byte 0x03004550 @ IWRAM+0x4550
.L080B825C:
	ldr r0, .L080B8268
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B826C
	movs r0, #0
	b .L080B826E
.L080B8268: .4byte 0x03004550 @ IWRAM+0x4550
.L080B826C:
	movs r0, #1
.L080B826E:
	strh r0, [r2, #0x1c]
.L080B8270:
	ldrh r0, [r4, #2]
	cmp r0, #0x52
	beq .L080B827A
	subs r0, #2
	strh r0, [r4, #2]
.L080B827A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B8280
sub_080B8280: @ 0x080B8280
	ldr r1, .L080B8288
	movs r0, #0
	str r0, [r1, #0x40]
	bx lr
.L080B8288: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B828C
sub_080B828C: @ 0x080B828C
.L080B828C:
	push {r4, lr}
	ldr r0, .L080B82AC
	ldr r1, .L080B82B0
	bl Task_Create
	adds r4, r0, #0
	movs r0, #0x60
	strh r0, [r4, #0x24]
	movs r0, #0x6a
	strh r0, [r4, #0x26]
	bl sub_080C51D4
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
.L080B82AC: .4byte gUnknown_08164A48
.L080B82B0: .4byte 0x0000FFFF

	thumb_func_start sub_080B82B4
sub_080B82B4: @ 0x080B82B4
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	ldr r2, [r4, #0x24]
	ldrh r1, [r2, #4]
	ldr r0, .L080B82E4
	cmp r1, r0
	bne .L080B82E8
	ldrh r0, [r2, #8]
	bl sub_080C2414
	cmp r0, #0
	bne .L080B82F4
	bl sub_080C1D9C
	adds r2, r0, #0
	movs r0, #0xf0
	ands r2, r0
	cmp r2, #0
	bne .L080B82F4
	b .L080B8304
	.byte 0x00, 0x00
.L080B82E4: .4byte 0x0000011F
.L080B82E8:
	ldrh r0, [r2, #8]
	bl sub_080C2414
	adds r2, r0, #0
	cmp r2, #0
	beq .L080B8304
.L080B82F4:
	ldr r0, [r4, #0x24]
	ldrh r0, [r0, #2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #1
	strh r0, [r5, #0x14]
	b .L080B830A
.L080B8304:
	ldr r0, [r4, #0x24]
	ldrh r1, [r0, #2]
	strh r2, [r5, #0x14]
.L080B830A:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r2, #0x50
	movs r3, #5
	bl sub_080C4618
	str r0, [r5, #4]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B8324
sub_080B8324: @ 0x080B8324
	ldrh r1, [r0, #0x38]
	strh r1, [r0, #0x1e]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080B832C
sub_080B832C: @ 0x080B832C
.L080B832C:
	push {lr}
	movs r0, #0x20
	bl sub_080AF1E8
	pop {r0}
	bx r0

	thumb_func_start sub_080B8338
sub_080B8338: @ 0x080B8338
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080B8348
	ldrh r0, [r0]
	cmp r0, #0x20
	bne .L080B834C
	movs r0, #1
	b .L080B834E
.L080B8348: .4byte 0x03004550 @ IWRAM+0x4550
.L080B834C:
	movs r0, #0
.L080B834E:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080B8354
sub_080B8354: @ 0x080B8354
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x24]
	ldr r1, [r0, #4]
	movs r0, #0xf0
	lsls r0, r0, #0x18
	ands r0, r1
	cmp r0, #0
	bne .L080B837C
	ldr r0, .L080B8378
	cmp r1, r0
	bls .L080B837C
	adds r0, #0xc
	cmp r1, r0
	bhi .L080B837C
	movs r0, #1
	b .L080B837E
	.byte 0x00, 0x00
.L080B8378: .4byte 0x0000011F
.L080B837C:
	movs r0, #0
.L080B837E:
	strh r0, [r2, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080B8384
sub_080B8384: @ 0x080B8384
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x24]
	ldr r0, [r0, #4]
	ldr r3, .L080B83A0
	adds r0, r0, r3
	cmp r0, #0xb
	bhi .L080B8432
	lsls r0, r0, #2
	ldr r1, .L080B83A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080B83A0: .4byte 0xFFFFFEE0
.L080B83A4: .4byte gUnknown_080B83A8
	.global gUnknown_080B83A8
gUnknown_080B83A8:
.L080B83A8: @ jump table
	.4byte .L080B83E0
	.4byte .L080B83E8
	.4byte .L080B83F8
	.4byte .L080B8410
	.4byte .L080B8420
	.4byte .L080B83D8
	.4byte .L080B8418
	.4byte .L080B83F0
	.4byte .L080B8430
	.4byte .L080B8428
	.4byte .L080B8400
	.4byte .L080B8408
.L080B83D8:
	ldr r1, .L080B83DC
	b .L080B8432
.L080B83DC: .4byte gUnknown_0805C0BA
.L080B83E0:
	ldr r1, .L080B83E4
	b .L080B8432
.L080B83E4: .4byte gUnknown_0805C088
.L080B83E8:
	ldr r1, .L080B83EC
	b .L080B8432
.L080B83EC: .4byte gUnknown_0805C092
.L080B83F0:
	ldr r1, .L080B83F4
	b .L080B8432
.L080B83F4: .4byte gUnknown_0805C0CE
.L080B83F8:
	ldr r1, .L080B83FC
	b .L080B8432
.L080B83FC: .4byte gUnknown_0805C09C
.L080B8400:
	ldr r1, .L080B8404
	b .L080B8432
.L080B8404: .4byte gUnknown_0805C0EC
.L080B8408:
	ldr r1, .L080B840C
	b .L080B8432
.L080B840C: .4byte gUnknown_0805C0F6
.L080B8410:
	ldr r1, .L080B8414
	b .L080B8432
.L080B8414: .4byte gUnknown_0805C0A6
.L080B8418:
	ldr r1, .L080B841C
	b .L080B8432
.L080B841C: .4byte gUnknown_0805C0C4
.L080B8420:
	ldr r1, .L080B8424
	b .L080B8432
.L080B8424: .4byte gUnknown_0805C0B0
.L080B8428:
	ldr r1, .L080B842C
	b .L080B8432
.L080B842C: .4byte gUnknown_0805C0E2
.L080B8430:
	ldr r1, .L080B843C
.L080B8432:
	adds r0, r2, #0
	bl sub_080B832C
	pop {r0}
	bx r0
.L080B843C: .4byte gUnknown_0805C0D8

	thumb_func_start sub_080B8440
sub_080B8440: @ 0x080B8440
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r2, #0
	adds r4, #0x24
	ldr r0, [r2, #0x24]
	ldr r0, [r0, #4]
	movs r1, #0xf0
	lsls r1, r1, #0x18
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0x18
	cmp r0, r1
	bne .L080B8460
	movs r0, #1
	b .L080B8462
.L080B8460:
	movs r0, #0
.L080B8462:
	strh r0, [r2, #0x1e]
	ldr r0, [r4]
	ldrh r1, [r0, #2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	movs r2, #0x50
	movs r3, #5
	bl sub_080C4618
	str r0, [r4, #8]
	movs r0, #0x73
	bl sub_080C51D4
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B8490
sub_080B8490: @ 0x080B8490
.L080B8490:
	push {r4, lr}
	adds r2, r0, #0
	ldr r4, .L080B84C0
	ldrh r0, [r2]
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080B84C4
	cmp r0, r1
	beq .L080B84B8
	adds r3, r1, #0
	adds r1, r2, #0
	adds r2, r4, #0
.L080B84AA:
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1]
	cmp r0, r3
	bne .L080B84AA
.L080B84B8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B84C0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080B84C4: .4byte 0x00000301

	thumb_func_start sub_080B84C8
sub_080B84C8: @ 0x080B84C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x24
	ldr r0, [r5, #0x24]
	ldr r4, [r0, #4]
	movs r1, #0xf0
	lsls r1, r1, #0x18
	ands r1, r4
	movs r0, #0
	strh r0, [r5, #0x1e]
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r1, r0
	bne .L080B84F0
	bl sub_080C7430
	movs r0, #1
	strh r0, [r5, #0x1e]
	b .L080B856A
.L080B84F0:
	movs r0, #0x90
	lsls r0, r0, #0x18
	cmp r1, r0
	bne .L080B8502
	bl sub_080C7648
	movs r0, #2
	strh r0, [r5, #0x1e]
	b .L080B856A
.L080B8502:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C32FC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080B8528
	ldr r1, .L080B8520
	adds r0, r5, #0
	bl sub_080B832C
	ldr r0, .L080B8524
	strh r4, [r0]
	b .L080B856A
.L080B8520: .4byte gUnknown_08003502
.L080B8524: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L080B8528:
	ldr r4, .L080B8570
	ldr r0, .L080B8574
	bl sub_080B8490
	ldr r0, [r5, #0x24]
	ldr r0, [r0, #4]
	strh r0, [r4, #2]
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080B832C
	ldr r1, [r5, #0x24]
	ldr r0, [r1, #4]
	ldr r2, .L080B8578
	adds r0, r0, r2
	cmp r0, #0x2d
	bls .L080B8562
	ldrh r0, [r1, #8]
	bl sub_080C2438
	ldr r0, [r5, #0x24]
	ldrh r0, [r0, #8]
	cmp r0, #0xff
	bne .L080B8562
	ldr r0, .L080B857C
	ldr r1, .L080B8580
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
.L080B8562:
	ldr r0, [r6]
	ldrh r0, [r0, #4]
	bl sub_080C3328
.L080B856A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080B8570: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080B8574: .4byte gUnknown_080033A0
.L080B8578: .4byte 0xFFFFFED4
.L080B857C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B8580: .4byte 0x000018D4

	thumb_func_start sub_080B8584
sub_080B8584: @ 0x080B8584
	push {lr}
	ldr r1, [r0, #0x24]
	ldr r2, [r1, #4]
	movs r3, #0xf0
	lsls r3, r3, #0x18
	ands r3, r2
	movs r1, #0
	strh r1, [r0, #0x1e]
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r3, r0
	bne .L080B85AC
	ldr r0, .L080B85A8
	ands r2, r0
	adds r0, r2, #0
	bl sub_080C3114
	b .L080B85BE
.L080B85A8: .4byte 0x0FFFFFFF
.L080B85AC:
	movs r0, #0x90
	lsls r0, r0, #0x18
	cmp r3, r0
	bne .L080B85BE
	ldr r0, .L080B85C4
	ands r2, r0
	adds r0, r2, #0
	bl sub_080C30AC
.L080B85BE:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B85C4: .4byte 0x0FFFFFFF

	thumb_func_start sub_080B85C8
sub_080B85C8: @ 0x080B85C8
	push {lr}
	ldr r1, [r0, #0x24]
	ldr r2, [r1, #4]
	movs r1, #0xf0
	lsls r1, r1, #0x18
	ands r2, r1
	movs r1, #0
	strh r1, [r0, #0x1e]
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r2, r0
	bne .L080B85E6
	bl sub_080C7414
	b .L080B85F2
.L080B85E6:
	movs r0, #0x90
	lsls r0, r0, #0x18
	cmp r2, r0
	bne .L080B85F2
	bl sub_080C762C
.L080B85F2:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B85F8
sub_080B85F8: @ 0x080B85F8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x24]
	ldr r2, [r0, #4]
	movs r1, #0xf0
	lsls r1, r1, #0x18
	ands r1, r2
	movs r0, #0
	strh r0, [r5, #0x1e]
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r1, r0
	bne .L080B8624
	ldr r4, .L080B861C
	ands r4, r2
	ldr r0, .L080B8620
	b .L080B8632
	.byte 0x00, 0x00
.L080B861C: .4byte 0x0FFFFFFF
.L080B8620: .4byte gUnknown_080033D6
.L080B8624:
	movs r0, #0x90
	lsls r0, r0, #0x18
	cmp r1, r0
	bne .L080B864A
	ldr r4, .L080B8650
	ands r4, r2
	ldr r0, .L080B8654
.L080B8632:
	bl sub_080B8490
	ldr r1, .L080B8658
	adds r0, r5, #0
	bl sub_080B832C
	ldr r0, [r5, #0x24]
	ldrh r0, [r0, #8]
	bl sub_080C2438
	ldr r0, .L080B865C
	str r4, [r0]
.L080B864A:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080B8650: .4byte 0x0FFFFFFF
.L080B8654: .4byte gUnknown_080033BA
.L080B8658: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080B865C: .4byte 0x0203DB2C @ EWRAM+0x3DB2C

	thumb_func_start sub_080B8660
sub_080B8660: @ 0x080B8660
.L080B8660:
	push {r4, r5, lr}
	sub sp, #4
	ldr r4, .L080B8694
	ldr r1, .L080B8698
	ldrh r0, [r1, #0x12]
	ldrh r1, [r1, #0x14]
	mov r5, sp
	adds r5, #2
	mov r2, sp
	adds r3, r5, #0
	bl sub_080C1F50
	ldrh r1, [r4]
	cmp r1, #0xff
	beq .L080B86A4
	mov r0, sp
	ldrh r2, [r0]
	adds r3, r5, #0
.L080B8684:
	cmp r1, r2
	bne .L080B869C
	ldrh r0, [r4, #2]
	ldrh r1, [r3]
	cmp r0, r1
	bne .L080B869C
	ldrh r0, [r4, #4]
	b .L080B86A6
.L080B8694: .4byte gUnknown_08164A7C
.L080B8698: .4byte 0x03004550 @ IWRAM+0x4550
.L080B869C:
	adds r4, #8
	ldrh r1, [r4]
	cmp r1, #0xff
	bne .L080B8684
.L080B86A4:
	movs r0, #0
.L080B86A6:
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B86B0
sub_080B86B0: @ 0x080B86B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x24]
	ldrh r0, [r0, #8]
	bl sub_080C2438
	movs r0, #0
	strh r0, [r7, #0x1c]
	ldr r0, .L080B86F8
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r2, r6, r0
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080B86DE
	b .L080B87E0
.L080B86DE:
	adds r5, r1, #0
	bl sub_080B8660
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080B8740
	cmp r0, #1
	bgt .L080B86FC
	cmp r0, #0
	beq .L080B8706
	b .L080B87E0
	.byte 0x00, 0x00
.L080B86F8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B86FC:
	cmp r0, #2
	beq .L080B8780
	cmp r0, #3
	beq .L080B87B6
	b .L080B87E0
.L080B8706:
	adds r0, r5, #0
	bl sub_080C09B0
	mov r8, r0
	cmp r0, #1
	bne .L080B87E0
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080B87E0
	adds r0, r5, #0
	bl sub_080F401C
	asrs r4, r0, #2
	cmp r4, #0
	bne .L080B872A
	movs r4, #1
.L080B872A:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080C0C70
	lsls r1, r6, #1
	adds r0, r7, #0
	adds r0, #0x3c
	adds r0, r0, r1
	strh r4, [r0]
	mov r0, r8
	b .L080B87AC
.L080B8740:
	cmp r6, #2
	bhi .L080B87E0
	adds r0, r5, #0
	bl sub_080C09B0
	mov r8, r0
	cmp r0, #1
	bne .L080B87E0
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080B87E0
	adds r0, r5, #0
	bl sub_080F401C
	asrs r4, r0, #1
	cmp r4, #0
	bne .L080B8768
	movs r4, #1
.L080B8768:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080C0C70
	lsls r1, r6, #1
	adds r0, r7, #0
	adds r0, #0x3c
	adds r0, r0, r1
	strh r4, [r0]
	mov r1, r8
	strh r1, [r7, #0x1c]
	b .L080B87AE
.L080B8780:
	cmp r6, #2
	bhi .L080B87E0
	adds r0, r5, #0
	bl sub_080C09B0
	adds r4, r0, #0
	cmp r4, #1
	bne .L080B87AA
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080B87AA
	adds r0, r5, #0
	movs r1, #4
	bl sub_080C08F8
	strh r4, [r7, #0x1c]
	adds r0, r6, #0
	bl sub_080C8490
.L080B87AA:
	movs r0, #1
.L080B87AC:
	strh r0, [r7, #0x1c]
.L080B87AE:
	adds r0, r6, #0
	bl sub_080C8490
	b .L080B87E0
.L080B87B6:
	cmp r6, #2
	bls .L080B87E0
	adds r0, r5, #0
	bl sub_080C09B0
	adds r4, r0, #0
	cmp r4, #1
	bne .L080B87E0
	adds r0, r5, #0
	bl sub_080C0830
	cmp r0, #0
	bne .L080B87E0
	adds r0, r5, #0
	movs r1, #2
	bl sub_080C08F8
	strh r4, [r7, #0x1c]
	adds r0, r6, #0
	bl sub_080C8490
.L080B87E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B87EC
sub_080B87EC: @ 0x080B87EC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r4, #0
	adds r7, #0x24
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C0148
	adds r5, r0, #0
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	beq .L080B8824
	cmp r0, #1
	bgt .L080B8810
	cmp r0, #0
	beq .L080B881A
	b .L080B8844
.L080B8810:
	cmp r0, #2
	beq .L080B882C
	cmp r0, #3
	beq .L080B8834
	b .L080B8844
.L080B881A:
	ldr r1, .L080B8820
	b .L080B8836
	.byte 0x00, 0x00
.L080B8820: .4byte gUnknown_08003432
.L080B8824:
	ldr r1, .L080B8828
	b .L080B8836
.L080B8828: .4byte gUnknown_08003452
.L080B882C:
	ldr r1, .L080B8830
	b .L080B8836
.L080B8830: .4byte gUnknown_08003472
.L080B8834:
	ldr r1, .L080B8840
.L080B8836:
	adds r0, r4, #0
	bl sub_080B832C
	b .L080B8852
	.byte 0x00, 0x00
.L080B8840: .4byte gUnknown_08003492
.L080B8844:
	ldr r1, .L080B8868
	adds r0, r4, #0
	bl sub_080B832C
	ldr r1, .L080B886C
	ldrh r0, [r5, #0x12]
	strh r0, [r1]
.L080B8852:
	ldr r2, .L080B8870
	lsls r1, r6, #1
	adds r0, r7, #0
	adds r0, #0x18
	adds r0, r0, r1
	ldrh r0, [r0]
	str r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B8868: .4byte gUnknown_080034B2
.L080B886C: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L080B8870: .4byte 0x0203DB2C @ EWRAM+0x3DB2C

	thumb_func_start sub_080B8874
sub_080B8874: @ 0x080B8874
.L080B8874:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	cmp r1, #0
	bne .L080B8890
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r3, #0x10
	lsrs r1, r1, #0x10
	bl sub_080B8AE0
	str r0, [r5, #0xc]
	b .L080B889E
.L080B8890:
	ldr r0, [r5, #0xc]
	bl sub_080B8B08
	cmp r0, #1
	beq .L080B889C
	movs r0, #0
.L080B889C:
	strh r0, [r4, #0x1c]
.L080B889E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080B88A4
sub_080B88A4: @ 0x080B88A4
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r4, #0x24
	ldr r3, .L080B88C8
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #5
	movs r1, #0xf5
	movs r2, #0x50
	bl sub_080C4618
	str r0, [r4, #0x10]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
.L080B88C8: .4byte 0x0000FFED

	thumb_func_start sub_080B88CC
sub_080B88CC: @ 0x080B88CC
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x34]
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B88DC
	movs r0, #1
	b .L080B88DE
.L080B88DC:
	movs r0, #0
.L080B88DE:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080B88E4
sub_080B88E4: @ 0x080B88E4
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r0, [r4, #4]
	cmp r0, #0
	beq .L080B88FA
	movs r1, #0
	bl sub_080C48F0
	movs r0, #0
	str r0, [r4, #4]
.L080B88FA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B8900
sub_080B8900: @ 0x080B8900
	push {lr}
	ldr r0, [r0, #0x2c]
	cmp r0, #0
	beq .L080B890E
	movs r1, #0
	bl sub_080C48F0
.L080B890E:
	movs r0, #1
	bl sub_080C3818
	movs r0, #1
	bl Field_SetState
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B8920
sub_080B8920: @ 0x080B8920
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080B895C
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080B895C
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	beq .L080B895C
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #0
	bne .L080B8960
.L080B895C:
	movs r0, #1
	b .L080B8962
.L080B8960:
	movs r0, #0
.L080B8962:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B896C
sub_080B896C: @ 0x080B896C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080B098C
	cmp r0, #0
	bne .L080B897C
	movs r0, #1
	b .L080B897E
.L080B897C:
	movs r0, #0
.L080B897E:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B8988
sub_080B8988: @ 0x080B8988
	push {lr}
	movs r0, #0x1a
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_080B8994
sub_080B8994: @ 0x080B8994
.L080B8994:
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080B89A8
	ldr r1, .L080B89AC
	bl Task_Create
	str r4, [r0, #0x24]
	pop {r4}
	pop {r1}
	bx r1
.L080B89A8: .4byte gUnknown_08164AD4
.L080B89AC: .4byte 0x0000FFFF
