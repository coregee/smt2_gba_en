	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080BD878
sub_080BD878: @ 0x080BD878
	push {lr}
	movs r2, #0
	movs r3, #8
	ldr r1, .L080BD894
.L080BD880:
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080BD888
	strh r3, [r1, #4]
.L080BD888:
	adds r1, #0x50
	adds r2, #1
	cmp r2, #7
	bls .L080BD880
	pop {r0}
	bx r0
.L080BD894: .4byte 0x03002730 @ IWRAM+0x2730

	thumb_func_start sub_080BD898
sub_080BD898: @ 0x080BD898
	push {lr}
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BD8AC
sub_080BD8AC: @ 0x080BD8AC
	push {lr}
	ldr r0, .L080BD8C4
	ldrh r0, [r0]
	cmp r0, #0x1c
	bne .L080BD8C0
	movs r0, #0x70
	movs r1, #0x10
	movs r2, #1
	bl PalFade_FadeRangeToBlack
.L080BD8C0:
	pop {r0}
	bx r0
.L080BD8C4: .4byte 0x03004534 @ IWRAM+0x4534

	thumb_func_start sub_080BD8C8
sub_080BD8C8: @ 0x080BD8C8
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080BD8E4
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080BD8E8
	str r0, [r1, #4]
	ldr r0, .L080BD8EC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	bx lr
	.byte 0x00, 0x00
.L080BD8E4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BD8E8: .4byte 0x06001000 @ VRAM+0x1000
.L080BD8EC: .4byte 0x85000400

	thumb_func_start sub_080BD8F0
sub_080BD8F0: @ 0x080BD8F0
	push {lr}
	ldr r0, .L080BD904
	ldrh r0, [r0]
	cmp r0, #0x1c
	bne .L080BD90C
	ldr r0, .L080BD908
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080BD928
.L080BD904: .4byte 0x03004534 @ IWRAM+0x4534
.L080BD908: .4byte sub_080BD8C8
.L080BD90C:
	ldr r0, .L080BD92C
	ldr r1, [r0]
	ldr r0, .L080BD930
	cmp r1, r0
	bne .L080BD928
	ldr r0, .L080BD934
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080BD938
	strh r1, [r0]
	ldr r0, .L080BD93C
	movs r1, #1
	bl VBlankTask_AddCounted
.L080BD928:
	pop {r0}
	bx r0
.L080BD92C: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080BD930: .4byte sub_080D977C
.L080BD934: .4byte 0x0300000E @ IWRAM+0xE
.L080BD938: .4byte 0x03000006 @ IWRAM+0x6
.L080BD93C: .4byte sub_080BD8C8

	thumb_func_start sub_080BD940
sub_080BD940: @ 0x080BD940
	push {lr}
	movs r0, #0xfd
	bl Flag_Set
	pop {r0}
	bx r0

	thumb_func_start sub_080BD94C
sub_080BD94C: @ 0x080BD94C
	push {lr}
	adds r1, r0, #0
	movs r0, #1
	movs r2, #0
	bl sub_08157EB0
	pop {r0}
	bx r0

	thumb_func_start sub_080BD95C
sub_080BD95C: @ 0x080BD95C
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x24
	ldr r0, .L080BD974
	ldrh r0, [r0]
	cmp r0, #0x86
	bne .L080BD978
	movs r0, #0xc1
	lsls r0, r0, #1
	b .L080BD986
	.byte 0x00, 0x00
.L080BD974: .4byte 0x03004534 @ IWRAM+0x4534
.L080BD978:
	subs r0, #0x8a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi .L080BD988
	movs r0, #0xc7
	lsls r0, r0, #1
.L080BD986:
	strh r0, [r1, #0x24]
.L080BD988:
	ldrh r0, [r2]
	bl Char_FindById
	adds r1, r0, #0
	cmp r1, #0
	beq .L080BD998
	movs r0, #1
	str r0, [r1, #0xc]
.L080BD998:
	pop {r0}
	bx r0

	thumb_func_start sub_080BD99C
sub_080BD99C: @ 0x080BD99C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldrh r0, [r4, #0x24]
	bl Char_FindById
	cmp r0, #0
	bne .L080BD9B2
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080BD9B2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080BD9B8
sub_080BD9B8: @ 0x080BD9B8
	push {lr}
	ldr r0, .L080BD9C8
	ldrh r0, [r0]
	bl sub_080C33AC
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BD9C8: .4byte 0x0203DB50 @ EWRAM+0x3DB50

	thumb_func_start sub_080BD9CC
sub_080BD9CC: @ 0x080BD9CC
	push {lr}
	ldr r0, .L080BD9DC
	ldrh r0, [r0]
	bl sub_080C3328
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BD9DC: .4byte 0x0203DB50 @ EWRAM+0x3DB50

	thumb_func_start sub_080BD9E0
sub_080BD9E0: @ 0x080BD9E0
	ldr r1, .L080BD9E8
	ldrh r0, [r1]
	strh r0, [r1, #2]
	bx lr
.L080BD9E8: .4byte 0x0203DB28 @ EWRAM+0x3DB28

	thumb_func_start sub_080BD9EC
sub_080BD9EC: @ 0x080BD9EC
	push {lr}
	movs r0, #0x1f
	movs r1, #1
	bl sub_080B8AE0
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BD9FC
sub_080BD9FC: @ 0x080BD9FC
	push {lr}
	ldr r0, .L080BDA0C
	movs r1, #1
	bl sub_080B8AE0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BDA0C: .4byte 0x000003FF

	thumb_func_start sub_080BDA10
sub_080BDA10: @ 0x080BDA10
	push {lr}
	cmp r1, #1
	bne .L080BDA20
	movs r0, #0x84
	lsls r0, r0, #1
	bl Flag_Set
	b .L080BDA28
.L080BDA20:
	movs r0, #0x84
	lsls r0, r0, #1
	bl Flag_Clear
.L080BDA28:
	ldr r0, .L080BDA34
	adds r0, #0x52
	movs r1, #0
	strh r1, [r0]
	pop {r0}
	bx r0
.L080BDA34: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080BDA38
sub_080BDA38: @ 0x080BDA38
	push {lr}
	ldr r2, .L080BDA6C
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	ldr r2, .L080BDA70
	ldrh r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2]
	ldr r0, .L080BDA74
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080BDA68
	ldr r0, .L080BDA78
	adds r0, #0x52
	ldrh r1, [r0]
	adds r1, #1
	movs r2, #0x3f
	ands r1, r2
	strh r1, [r0]
.L080BDA68:
	pop {r0}
	bx r0
.L080BDA6C: .4byte 0x04000200 @ REG_IE
.L080BDA70: .4byte 0x04000004 @ REG_DISPSTAT
.L080BDA74: .4byte 0x030031BC @ IWRAM+0x31BC
.L080BDA78: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080BDA7C
sub_080BDA7C: @ 0x080BDA7C
	ldr r2, .L080BDA98
	ldrh r1, [r2]
	ldr r0, .L080BDA9C
	ands r0, r1
	strh r0, [r2]
	ldr r2, .L080BDAA0
	ldrh r1, [r2]
	ldr r0, .L080BDAA4
	ands r0, r1
	strh r0, [r2]
	ldr r1, .L080BDAA8
	ldr r0, .L080BDAAC
	str r0, [r1, #4]
	bx lr
.L080BDA98: .4byte 0x04000200 @ REG_IE
.L080BDA9C: .4byte 0x0000FFFD
.L080BDAA0: .4byte 0x04000004 @ REG_DISPSTAT
.L080BDAA4: .4byte 0x0000FFEF
.L080BDAA8: .4byte 0x030020F0 @ IWRAM+0x20F0
.L080BDAAC: .4byte IntrDummy

	thumb_func_start sub_080BDAB0
sub_080BDAB0: @ 0x080BDAB0
	push {r4, r5, r6, lr}
	ldr r0, .L080BDAFC
	ldrb r1, [r0]
	adds r4, r1, #0
	cmp r1, #0x63
	bhi .L080BDB0C
	ldr r5, .L080BDB00
	ldr r0, .L080BDB04
	adds r3, r0, #0
	adds r3, #0x52
	ldrh r0, [r3]
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r6, #0
	ldrsh r1, [r0, r6]
	cmp r1, #0
	bge .L080BDADC
	adds r1, #0x1f
.L080BDADC:
	asrs r1, r1, #5
	ldr r0, .L080BDB08
	strh r1, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	lsls r0, r0, #2
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge .L080BDAF8
	adds r0, #0x1f
.L080BDAF8:
	asrs r1, r0, #5
	b .L080BDB12
.L080BDAFC: .4byte 0x04000006 @ REG_VCOUNT
.L080BDB00: .4byte gSineTable
.L080BDB04: .4byte 0x03004550 @ IWRAM+0x4550
.L080BDB08: .4byte 0x0400001C @ REG_BG3HOFS
.L080BDB0C:
	ldr r0, .L080BDB1C
	movs r1, #0
	strh r1, [r0]
.L080BDB12:
	ldr r0, .L080BDB20
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BDB1C: .4byte 0x0400001C @ REG_BG3HOFS
.L080BDB20: .4byte 0x04000014 @ REG_BG1HOFS

	thumb_func_start sub_080BDB24
sub_080BDB24: @ 0x080BDB24
.L080BDB24:
	push {lr}
	ldr r0, .L080BDB38
	ldr r1, .L080BDB3C
	str r1, [r0, #4]
	ldr r0, .L080BDB40
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	pop {r0}
	bx r0
.L080BDB38: .4byte 0x030020F0 @ IWRAM+0x20F0
.L080BDB3C: .4byte sub_080BDAB0
.L080BDB40: .4byte sub_080BDA38

	thumb_func_start sub_080BDB44
sub_080BDB44: @ 0x080BDB44
.L080BDB44:
	push {lr}
	ldr r0, .L080BDB54
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BDB54: .4byte sub_080BDA7C

	thumb_func_start sub_080BDB58
sub_080BDB58: @ 0x080BDB58
.L080BDB58:
	push {r4, r5, lr}
	movs r0, #0x84
	lsls r0, r0, #1
	bl Flag_Test
	adds r4, r0, #0
	cmp r4, #0
	beq .L080BDB8E
	ldr r0, .L080BDB84
	adds r1, r0, #0
	adds r1, #0x50
	ldrh r0, [r1]
	cmp r0, #0
	bne .L080BDB78
	movs r0, #1
	strh r0, [r1]
.L080BDB78:
	ldrh r0, [r1]
	cmp r0, #1
	bne .L080BDB88
	bl sub_080BDB24
	b .L080BDBA0
.L080BDB84: .4byte 0x03004550 @ IWRAM+0x4550
.L080BDB88:
	bl sub_080BDB44
	b .L080BDBA0
.L080BDB8E:
	ldr r0, .L080BDBA8
	adds r5, r0, #0
	adds r5, #0x50
	ldrh r0, [r5]
	cmp r0, #0
	beq .L080BDBA0
	bl sub_080BDB44
	strh r4, [r5]
.L080BDBA0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BDBA8: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080BDBAC
sub_080BDBAC: @ 0x080BDBAC
	ldr r0, .L080BDBB4
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080BDBB4: .4byte 0x0300000C @ IWRAM+0xC

	thumb_func_start sub_080BDBB8
sub_080BDBB8: @ 0x080BDBB8
	push {lr}
	ldr r0, .L080BDBC4
	bl Flag_Set
	pop {r0}
	bx r0
.L080BDBC4: .4byte 0x0000010F

	thumb_func_start sub_080BDBC8
sub_080BDBC8: @ 0x080BDBC8
	push {lr}
	bl Palette_IsBg13Black
	cmp r0, #0
	bne .L080BDBE0
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #2
	movs r3, #6
	bl PalFade_FadeRangeToBlackWithDuration
	b .L080BDBE6
.L080BDBE0:
	ldr r0, .L080BDBEC
	bl Flag_Set
.L080BDBE6:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BDBEC: .4byte 0x0000010D

	thumb_func_start sub_080BDBF0
sub_080BDBF0: @ 0x080BDBF0
	push {lr}
	sub sp, #4
	ldr r0, .L080BDC20
	ldrh r0, [r0]
	bl sub_080C5F60
	adds r1, r0, #0
	ldr r2, .L080BDC24
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #1
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	add sp, #4
	pop {r0}
	bx r0
.L080BDC20: .4byte 0x03004534 @ IWRAM+0x4534
.L080BDC24: .4byte 0x03002AB0 @ IWRAM+0x2AB0

	thumb_func_start sub_080BDC28
sub_080BDC28: @ 0x080BDC28
	push {lr}
	bl Palette_IsBg13Black
	cmp r0, #0
	bne .L080BDC42
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #2
	movs r3, #6
	bl PalFade_FadeRangeToBlackWithDuration
	b .L080BDC4A
.L080BDC42:
	movs r0, #0x87
	lsls r0, r0, #1
	bl Flag_Set
.L080BDC4A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BDC50
sub_080BDC50: @ 0x080BDC50
	push {r4, lr}
	ldr r0, .L080BDC90
	movs r3, #0xe8
	strb r3, [r0]
	ldr r0, .L080BDC94
	movs r2, #8
	strb r2, [r0]
	ldr r1, .L080BDC98
	movs r0, #0xa0
	strb r0, [r1]
	ldr r1, .L080BDC9C
	movs r0, #0x60
	strb r0, [r1]
	ldr r1, .L080BDCA0
	movs r4, #0x3d
	movs r0, #0x35
	strb r0, [r1]
	ldr r0, .L080BDCA4
	strb r3, [r0]
	ldr r0, .L080BDCA8
	strb r2, [r0]
	ldr r0, .L080BDCAC
	strb r2, [r0]
	ldr r1, .L080BDCB0
	movs r0, #0
	strb r0, [r1]
	ldr r0, .L080BDCB4
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BDC90: .4byte 0x03000030 @ IWRAM+0x30
.L080BDC94: .4byte 0x03000031 @ IWRAM+0x31
.L080BDC98: .4byte 0x03000034 @ IWRAM+0x34
.L080BDC9C: .4byte 0x03000035 @ IWRAM+0x35
.L080BDCA0: .4byte 0x03000038 @ IWRAM+0x38
.L080BDCA4: .4byte 0x03000032 @ IWRAM+0x32
.L080BDCA8: .4byte 0x03000033 @ IWRAM+0x33
.L080BDCAC: .4byte 0x03000036 @ IWRAM+0x36
.L080BDCB0: .4byte 0x03000037 @ IWRAM+0x37
.L080BDCB4: .4byte 0x03000039 @ IWRAM+0x39

	thumb_func_start sub_080BDCB8
sub_080BDCB8: @ 0x080BDCB8
	push {lr}
	ldr r0, .L080BDCC4
	bl m4aSongNumStop
	pop {r0}
	bx r0
.L080BDCC4: .4byte 0x0000013F

	thumb_func_start sub_080BDCC8
sub_080BDCC8: @ 0x080BDCC8
	sub sp, #4
	movs r3, #0
	str r3, [sp]
	ldr r0, .L080BDCF0
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080BDCF4
	str r1, [r0, #4]
	ldr r2, .L080BDCF8
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, .L080BDCFC
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	add sp, #4
	bx lr
.L080BDCF0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BDCF4: .4byte 0x06001000 @ VRAM+0x1000
.L080BDCF8: .4byte 0x85000400
.L080BDCFC: .4byte 0x06003000 @ VRAM+0x3000

	thumb_func_start sub_080BDD00
sub_080BDD00: @ 0x080BDD00
	push {lr}
	ldr r0, .L080BDD20
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080BDD24
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080BDD28
	strh r1, [r0]
	ldr r0, .L080BDD2C
	strh r1, [r0]
	ldr r0, .L080BDD30
	strh r1, [r0]
	pop {r0}
	bx r0
.L080BDD20: .4byte sub_080BDCC8
.L080BDD24: .4byte 0x03000006 @ IWRAM+0x6
.L080BDD28: .4byte 0x03000004 @ IWRAM+0x4
.L080BDD2C: .4byte 0x0300000E @ IWRAM+0xE
.L080BDD30: .4byte 0x0300000C @ IWRAM+0xC

	thumb_func_start sub_080BDD34
sub_080BDD34: @ 0x080BDD34
	push {r4, r5, lr}
	movs r0, #0xc6
	bl Flag_Test
	adds r5, r0, #0
	cmp r5, #0
	bne .L080BDD52
	ldr r4, .L080BDD58
	ldr r0, [r4]
	movs r1, #1
	bl Window_Close
	str r5, [r4]
	ldr r0, .L080BDD5C
	strh r5, [r0]
.L080BDD52:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BDD58: .4byte 0x03006968 @ IWRAM+0x6968
.L080BDD5C: .4byte 0x0203DB6C @ EWRAM+0x3DB6C

	thumb_func_start sub_080BDD60
sub_080BDD60: @ 0x080BDD60
	push {lr}
	sub sp, #4
	movs r0, #0xc6
	bl Flag_Test
	cmp r0, #0
	bne .L080BDD86
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #8
	bl Window_Create
	ldr r1, .L080BDD8C
	str r0, [r1]
	ldr r1, .L080BDD90
	movs r0, #1
	strh r0, [r1]
.L080BDD86:
	add sp, #4
	pop {r0}
	bx r0
.L080BDD8C: .4byte 0x03006968 @ IWRAM+0x6968
.L080BDD90: .4byte 0x0203DB6C @ EWRAM+0x3DB6C

	thumb_func_start sub_080BDD94
sub_080BDD94: @ 0x080BDD94
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	ldr r0, .L080BDDCC
	bl Char_FindById
	ldrh r2, [r0, #0x24]
	movs r1, #0x20
	orrs r1, r2
	strh r1, [r0, #0x24]
	ldr r0, .L080BDDD0
	strh r0, [r4, #0x24]
	movs r1, #8
	strh r1, [r5, #2]
	movs r3, #0x10
	strh r3, [r5, #4]
	ldr r2, .L080BDDD4
	lsls r1, r1, #8
	ldrh r0, [r4, #0x24]
	orrs r1, r0
	strh r1, [r2]
	ldr r0, .L080BDDD8
	strh r3, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BDDCC: .4byte 0x0000014D
.L080BDDD0: .4byte 0x0000FFFF
.L080BDDD4: .4byte 0x03000042 @ IWRAM+0x42
.L080BDDD8: .4byte 0x03000044 @ IWRAM+0x44

	thumb_func_start sub_080BDDDC
sub_080BDDDC: @ 0x080BDDDC
	adds r3, r0, #0
	adds r3, #0x24
	ldrh r1, [r0, #0x24]
	subs r1, #1
	strh r1, [r0, #0x24]
	ldr r2, .L080BDDF8
	ldrh r0, [r3, #2]
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r2]
	ldr r1, .L080BDDFC
	ldrh r0, [r3, #4]
	strh r0, [r1]
	bx lr
.L080BDDF8: .4byte 0x03000042 @ IWRAM+0x42
.L080BDDFC: .4byte 0x03000044 @ IWRAM+0x44

	thumb_func_start sub_080BDE00
sub_080BDE00: @ 0x080BDE00
	push {lr}
	cmp r1, #0
	bne .L080BDE14
	ldr r1, .L080BDE10
	bl Char_EndById
	b .L080BDE18
	.byte 0x00, 0x00
.L080BDE10: .4byte 0x0000014D
.L080BDE14:
	bl sub_080C1440
.L080BDE18:
	pop {r0}
	bx r0

	thumb_func_start sub_080BDE1C
sub_080BDE1C: @ 0x080BDE1C
.L080BDE1C:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x85
	lsls r0, r0, #1
	bl Flag_Test
	cmp r0, #0
	bne .L080BDE30
	b .L080BDF36
.L080BDE30:
	ldr r1, .L080BDE44
	adds r0, r4, r1
	cmp r0, #0x2c
	bls .L080BDE3A
	b .L080BDF36
.L080BDE3A:
	lsls r0, r0, #2
	ldr r1, .L080BDE48
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080BDE44: .4byte 0xFFFFFEFD
.L080BDE48: .4byte gUnknown_080BDE4C
	.global gUnknown_080BDE4C
gUnknown_080BDE4C:
.L080BDE4C: @ jump table
	.4byte .L080BDF1C
	.4byte .L080BDF36
	.4byte .L080BDF36
	.4byte .L080BDF36
	.4byte .L080BDF36
	.4byte .L080BDF36
	.4byte .L080BDF36
	.4byte .L080BDF36
	.4byte .L080BDF36
	.4byte .L080BDF36
	.4byte .L080BDF36
	.4byte .L080BDF36
	.4byte .L080BDF00
	.4byte .L080BDF06
	.4byte .L080BDF1C
	.4byte .L080BDF36
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF36
	.4byte .L080BDF36
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF0C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF14
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF1C
	.4byte .L080BDF2A
	.4byte .L080BDF1C
	.4byte .L080BDF1C
.L080BDF00:
	movs r0, #1
	movs r1, #0xa1
	b .L080BDF20
.L080BDF06:
	movs r0, #0
	movs r1, #0x50
	b .L080BDF20
.L080BDF0C:
	movs r0, #0
	movs r1, #0x78
	movs r2, #0x6a
	b .L080BDF22
.L080BDF14:
	movs r0, #0
	movs r1, #0x78
	movs r2, #0x6a
	b .L080BDF22
.L080BDF1C:
	movs r0, #0
	movs r1, #0x78
.L080BDF20:
	movs r2, #0x56
.L080BDF22:
	movs r3, #3
	bl sub_080E8F80
	b .L080BDF36
.L080BDF2A:
	movs r0, #0
	movs r1, #0x78
	movs r2, #0x56
	movs r3, #3
	bl sub_080E8F80
.L080BDF36:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080BDF3C
sub_080BDF3C: @ 0x080BDF3C
.L080BDF3C:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x85
	lsls r0, r0, #1
	bl Flag_Test
	cmp r0, #0
	bne .L080BDF50
	b .L080BE10A
.L080BDF50:
	adds r0, r4, #0
	subs r0, #0x22
	cmp r0, #0x4e
	bls .L080BDF5A
	b .L080BE10A
.L080BDF5A:
	lsls r0, r0, #2
	ldr r1, .L080BDF64
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080BDF64: .4byte gUnknown_080BDF68
	.global gUnknown_080BDF68
gUnknown_080BDF68:
.L080BDF68: @ jump table
	.4byte .L080BE0A4
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE0B0
	.4byte .L080BE104
	.4byte .L080BE104
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE104
	.4byte .L080BE0BC
	.4byte .L080BE10A
	.4byte .L080BE0D4
	.4byte .L080BE0F8
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE0E0
	.4byte .L080BE0EC
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE10A
	.4byte .L080BE0C8
.L080BE0A4:
	ldr r1, .L080BE0AC
	movs r0, #0x48
	b .L080BE108
	.byte 0x00, 0x00
.L080BE0AC: .4byte 0x0300000E @ IWRAM+0xE
.L080BE0B0:
	ldr r1, .L080BE0B8
	movs r0, #0x68
	b .L080BE108
	.byte 0x00, 0x00
.L080BE0B8: .4byte 0x0300000E @ IWRAM+0xE
.L080BE0BC:
	ldr r1, .L080BE0C4
	movs r0, #0x40
	b .L080BE108
	.byte 0x00, 0x00
.L080BE0C4: .4byte 0x0300000E @ IWRAM+0xE
.L080BE0C8:
	ldr r1, .L080BE0D0
	movs r0, #0x20
	b .L080BE108
	.byte 0x00, 0x00
.L080BE0D0: .4byte 0x0300000E @ IWRAM+0xE
.L080BE0D4:
	ldr r1, .L080BE0DC
	movs r0, #0x40
	b .L080BE108
	.byte 0x00, 0x00
.L080BE0DC: .4byte 0x0300000E @ IWRAM+0xE
.L080BE0E0:
	ldr r1, .L080BE0E8
	movs r0, #0x40
	b .L080BE108
	.byte 0x00, 0x00
.L080BE0E8: .4byte 0x0300000E @ IWRAM+0xE
.L080BE0EC:
	ldr r1, .L080BE0F4
	movs r0, #0x40
	b .L080BE108
	.byte 0x00, 0x00
.L080BE0F4: .4byte 0x0300000E @ IWRAM+0xE
.L080BE0F8:
	ldr r1, .L080BE100
	movs r0, #0x40
	b .L080BE108
	.byte 0x00, 0x00
.L080BE100: .4byte 0x0300000E @ IWRAM+0xE
.L080BE104:
	ldr r1, .L080BE110
	movs r0, #0x60
.L080BE108:
	strh r0, [r1]
.L080BE10A:
	pop {r4}
	pop {r0}
	bx r0
.L080BE110: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080BE114
sub_080BE114: @ 0x080BE114
	push {lr}
	movs r0, #0x80
	movs r1, #0x80
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	pop {r0}
	bx r0

	thumb_func_start sub_080BE130
sub_080BE130: @ 0x080BE130
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r3, .L080BE16C
	ldr r1, .L080BE170
	ldrh r1, [r1]
	movs r2, #0
	strh r1, [r0, #0x24]
	strh r2, [r4, #2]
	movs r0, #4
	strh r0, [r4, #4]
	strh r0, [r4, #6]
	movs r0, #2
	strh r0, [r4, #8]
	strh r0, [r4, #0xa]
	movs r0, #0x99
	lsls r0, r0, #4
	adds r3, r3, r0
	ldr r0, [r3]
	ldr r1, .L080BE174
	adds r0, r0, r1
	cmp r0, #0x2c
	bls .L080BE160
	b .L080BE28C
.L080BE160:
	lsls r0, r0, #2
	ldr r1, .L080BE178
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080BE16C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080BE170: .4byte 0x0300000E @ IWRAM+0xE
.L080BE174: .4byte 0xFFFFFEFD
.L080BE178: .4byte gUnknown_080BE17C
	.global gUnknown_080BE17C
gUnknown_080BE17C:
.L080BE17C: @ jump table
	.4byte .L080BE230
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE230
	.4byte .L080BE230
	.4byte .L080BE282
	.4byte .L080BE28C
	.4byte .L080BE282
	.4byte .L080BE26A
	.4byte .L080BE236
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE266
	.4byte .L080BE262
	.4byte .L080BE25E
	.4byte .L080BE25A
	.4byte .L080BE256
	.4byte .L080BE252
	.4byte .L080BE24E
	.4byte .L080BE24A
	.4byte .L080BE246
	.4byte .L080BE242
	.4byte .L080BE23E
	.4byte .L080BE23A
	.4byte .L080BE282
	.4byte .L080BE28C
	.4byte .L080BE26E
	.4byte .L080BE27A
	.4byte .L080BE27E
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE282
	.4byte .L080BE28C
	.4byte .L080BE28C
	.4byte .L080BE276
.L080BE230:
	movs r0, #0x28
	strh r0, [r4, #2]
	b .L080BE28C
.L080BE236:
	movs r0, #5
	b .L080BE284
.L080BE23A:
	movs r0, #0x1e
	b .L080BE284
.L080BE23E:
	movs r0, #0x23
	b .L080BE284
.L080BE242:
	movs r0, #0x23
	b .L080BE284
.L080BE246:
	movs r0, #0x23
	b .L080BE284
.L080BE24A:
	movs r0, #0x23
	b .L080BE284
.L080BE24E:
	movs r0, #0x23
	b .L080BE284
.L080BE252:
	movs r0, #0x23
	b .L080BE284
.L080BE256:
	movs r0, #0x23
	b .L080BE284
.L080BE25A:
	movs r0, #0x23
	b .L080BE284
.L080BE25E:
	movs r0, #0x23
	b .L080BE284
.L080BE262:
	movs r0, #0x23
	b .L080BE284
.L080BE266:
	movs r0, #0x23
	b .L080BE284
.L080BE26A:
	movs r0, #0x25
	b .L080BE284
.L080BE26E:
	movs r0, #0x1e
	strh r0, [r4, #2]
	movs r0, #8
	b .L080BE288
.L080BE276:
	movs r0, #0x24
	b .L080BE284
.L080BE27A:
	movs r0, #0x23
	b .L080BE284
.L080BE27E:
	movs r0, #0xf
	b .L080BE284
.L080BE282:
	movs r0, #0x22
.L080BE284:
	strh r0, [r4, #2]
	movs r0, #7
.L080BE288:
	strh r0, [r4, #0xa]
	strh r0, [r4, #8]
.L080BE28C:
	ldr r0, .L080BE2A4
	ldrh r0, [r0]
	subs r0, #0x22
	cmp r0, #0x4e
	bls .L080BE298
	b .L080BE3EE
.L080BE298:
	lsls r0, r0, #2
	ldr r1, .L080BE2A8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080BE2A4: .4byte 0x03004534 @ IWRAM+0x4534
.L080BE2A8: .4byte gUnknown_080BE2AC
	.global gUnknown_080BE2AC
gUnknown_080BE2AC:
.L080BE2AC: @ jump table
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3E8
	.4byte .L080BE3E8
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
	.4byte .L080BE3EE
.L080BE3E8:
	movs r0, #1
	strh r0, [r4, #4]
	strh r0, [r4, #6]
.L080BE3EE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080BE3F4
sub_080BE3F4: @ 0x080BE3F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x24
	ldr r5, .L080BE474
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldrh r0, [r2, #6]
	subs r0, #1
	strh r0, [r2, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080BE424
	ldrh r0, [r2, #4]
	strh r0, [r2, #6]
	ldrh r3, [r4, #0x24]
	cmp r3, #0
	beq .L080BE424
	ldr r0, .L080BE478
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	subs r0, r3, #1
	strh r0, [r4, #0x24]
.L080BE424:
	ldrh r0, [r2, #0xa]
	subs r0, #1
	strh r0, [r2, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080BE464
	ldrh r0, [r2, #8]
	strh r0, [r2, #0xa]
	ldrh r0, [r2, #2]
	cmp r0, #0
	beq .L080BE464
	ldr r0, .L080BE47C
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldrh r0, [r2, #2]
	subs r0, #1
	strh r0, [r2, #2]
	movs r1, #0x99
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r0, #0x88
	lsls r0, r0, #1
	cmp r1, r0
	bne .L080BE464
	ldr r0, .L080BE480
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L080BE464:
	ldr r0, [r2]
	cmp r0, #0
	bne .L080BE46E
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080BE46E:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080BE474: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080BE478: .4byte 0x0300000E @ IWRAM+0xE
.L080BE47C: .4byte 0x00000DAA
.L080BE480: .4byte 0x00000DEA

	thumb_func_start sub_080BE484
sub_080BE484: @ 0x080BE484
	push {lr}
	movs r0, #1
	bl sub_080C51BC
	pop {r0}
	bx r0

	thumb_func_start sub_080BE490
sub_080BE490: @ 0x080BE490
	push {lr}
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x30
	movs r2, #4
	bl PalFade_FadeRangeToWhite
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BE4A4
sub_080BE4A4: @ 0x080BE4A4
	ldr r1, .L080BE4AC
	movs r0, #0
	str r0, [r1]
	bx lr
.L080BE4AC: .4byte 0x0200AB04 @ EWRAM+0xAB04

	thumb_func_start sub_080BE4B0
sub_080BE4B0: @ 0x080BE4B0
	push {lr}
	movs r0, #1
	bl sub_080C3818
	movs r0, #0
	bl PalFade_Init
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BE4C4
sub_080BE4C4: @ 0x080BE4C4
.L080BE4C4:
	ldr r0, .L080BE4D0
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0xc]
	bx lr
	.byte 0x00, 0x00
.L080BE4D0: .4byte 0x0300463C @ IWRAM+0x463C

	thumb_func_start sub_080BE4D4
sub_080BE4D4: @ 0x080BE4D4
	push {lr}
	movs r0, #1
	bl PalFade_FadeToBlack
	ldr r1, .L080BE4E8
	movs r0, #1
	strh r0, [r1, #0x34]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BE4E8: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080BE4EC
sub_080BE4EC: @ 0x080BE4EC
	push {lr}
	ldrh r2, [r0, #0x24]
	movs r0, #0xf0
	ands r0, r2
	lsrs r0, r0, #4
	movs r1, #0xf
	ands r1, r2
	bl sub_0813EE90
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BE504
sub_080BE504: @ 0x080BE504
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080BE528
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L080BE52C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080C1450
	add sp, #4
	pop {r0}
	bx r0
.L080BE528: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BE52C: .4byte 0x85001000

	thumb_func_start sub_080BE530
sub_080BE530: @ 0x080BE530
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080BE564
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080BE568
	str r0, [r1, #4]
	ldr r0, .L080BE56C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080BE570
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L080BE574
	str r0, [r1, #4]
	ldr r0, .L080BE578
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080ADF64
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BE564: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BE568: .4byte 0x02028074 @ EWRAM+0x28074
.L080BE56C: .4byte 0x85000008
.L080BE570: .4byte 0x03003B94 @ IWRAM+0x3B94
.L080BE574: .4byte 0x06004000 @ VRAM+0x4000
.L080BE578: .4byte 0x84000800

	thumb_func_start sub_080BE57C
sub_080BE57C: @ 0x080BE57C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	cmp r1, #3
	beq .L080BE5EA
	cmp r1, #3
	bls .L080BE5A2
	cmp r1, #5
	beq .L080BE650
	cmp r1, #5
	blo .L080BE608
	cmp r1, #6
	bne .L080BE596
	b .L080BE6B6
.L080BE596:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne .L080BE5A0
	b .L080BE6C8
.L080BE5A0:
	b .L080BE6D4
.L080BE5A2:
	cmp r1, #1
	beq .L080BE5C4
	cmp r1, #1
	bhi .L080BE5D8
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	bl sub_080C1328
	bl sub_080C1384
	ldr r0, .L080BE5C0
	b .L080BE5CA
	.byte 0x00, 0x00
.L080BE5C0: .4byte sub_080BE504
.L080BE5C4:
	bl sub_080C14FC
	ldr r0, .L080BE5D4
.L080BE5CA:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080BE6D4
	.byte 0x00, 0x00
.L080BE5D4: .4byte sub_080C153C
.L080BE5D8:
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	bl sub_080C65C8
	bl sub_080C6764
	b .L080BE6D4
.L080BE5EA:
	add r0, sp, #4
	movs r2, #0
	movs r1, #8
	strh r1, [r0, #6]
	strh r2, [r0, #0xe]
	str r1, [sp]
	movs r1, #2
	movs r2, #0xb
	movs r3, #0x1a
	bl Window_DrawFrame
	movs r0, #0
	bl WindowMap_QueueUpload
	b .L080BE6D4
.L080BE608:
	movs r6, #0
	movs r7, #0
.L080BE60C:
	ldr r1, .L080BE64C
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L080BE640
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r0, [r4, #6]
	bl Char_GetRecord
	adds r5, r0, #0
	ldr r1, [r5, #4]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl Char_LoadGfxHalf
	ldr r1, [r5, #8]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #1
	bl Char_LoadGfxHalf
.L080BE640:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #3
	bls .L080BE60C
	b .L080BE6D4
.L080BE64C: .4byte 0x02036094 @ EWRAM+0x36094
.L080BE650:
	ldr r0, .L080BE69C
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L080BE6B0
	ldr r0, .L080BE6A0
	ldr r1, [r0]
	ldr r5, .L080BE6A4
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
	ldr r0, .L080BE6A8
	ldr r1, [r0]
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r5, r0
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r0, .L080BE6AC
	movs r1, #1
	bl VBlankTask_AddCounted
	bl sub_080AE304
	b .L080BE6D4
.L080BE69C: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080BE6A0: .4byte 0x03004630 @ IWRAM+0x4630
.L080BE6A4: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080BE6A8: .4byte 0x03004510 @ IWRAM+0x4510
.L080BE6AC: .4byte sub_080BE530
.L080BE6B0:
	bl BgPicture_LoadAll
	b .L080BE6D4
.L080BE6B6:
	ldr r1, .L080BE6C4
	movs r0, #0
	strh r0, [r1, #0x34]
	bl sub_080C1440
	b .L080BE6D4
	.byte 0x00, 0x00
.L080BE6C4: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080BE6C8:
	movs r0, #1
	bl PalFade_FadeInFromBlack
	ldr r0, .L080BE6DC
	bl SetMainCallback
.L080BE6D4:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080BE6DC: .4byte sub_080C1850

	thumb_func_start sub_080BE6E0
sub_080BE6E0: @ 0x080BE6E0
.L080BE6E0:
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080BE700
	ldr r1, .L080BE704
	bl Task_Create
	adds r2, r0, #0
	ldr r1, .L080BE708
	str r2, [r1]
	strh r4, [r2, #0x24]
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080BE700: .4byte gUnknown_08198128
.L080BE704: .4byte 0x0000FFFF
.L080BE708: .4byte 0x0300463C @ IWRAM+0x463C

	thumb_func_start sub_080BE70C
sub_080BE70C: @ 0x080BE70C
.L080BE70C:
	push {r4, lr}
	sub sp, #4
	ldr r1, .L080BE730
	ldrh r0, [r1, #0x12]
	ldrh r1, [r1, #0x14]
	mov r4, sp
	adds r4, #2
	mov r2, sp
	adds r3, r4, #0
	bl sub_080C1F50
	ldr r2, .L080BE734
.L080BE724:
	ldrb r1, [r2]
	cmp r1, #0xff
	bne .L080BE738
	movs r0, #0
	b .L080BE762
	.byte 0x00, 0x00
.L080BE730: .4byte 0x03004550 @ IWRAM+0x4550
.L080BE734: .4byte gUnknown_08198278
.L080BE738:
	mov r0, sp
	ldrb r0, [r0]
	cmp r1, r0
	bne .L080BE758
	ldrb r1, [r2, #1]
	movs r0, #0x3f
	ands r0, r1
	ldrb r1, [r4]
	cmp r0, r1
	bne .L080BE758
	ldrb r0, [r2, #1]
	ldr r1, .L080BE75C
	lsrs r0, r0, #6
	ldrb r1, [r1, #2]
	cmp r0, r1
	beq .L080BE760
.L080BE758:
	adds r2, #4
	b .L080BE724
.L080BE75C: .4byte 0x03004550 @ IWRAM+0x4550
.L080BE760:
	adds r0, r2, #0
.L080BE762:
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080BE76C
sub_080BE76C: @ 0x080BE76C
.L080BE76C:
	push {lr}
	bl sub_080BE70C
	adds r2, r0, #0
	ldrb r0, [r2, #2]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #1
	beq .L080BE78C
	cmp r1, #1
	ble .L080BE7C8
	cmp r1, #2
	beq .L080BE794
	cmp r1, #3
	beq .L080BE79C
	b .L080BE7C8
.L080BE78C:
	ldr r0, .L080BE790
	b .L080BE7AE
.L080BE790: .4byte gUnknown_08198554
.L080BE794:
	ldr r0, .L080BE798
	b .L080BE7AE
.L080BE798: .4byte gUnknown_08198648
.L080BE79C:
	ldrb r0, [r2, #3]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r0, r1
	bl Flag_Test
	cmp r0, #0
	bne .L080BE7C8
	ldr r0, .L080BE7C0
.L080BE7AE:
	ldr r1, .L080BE7C4
	bl Task_Create
	movs r0, #0x1a
	bl Field_SetState
	movs r0, #1
	b .L080BE7CA
	.byte 0x00, 0x00
.L080BE7C0: .4byte gUnknown_08198328
.L080BE7C4: .4byte 0x0000FFFF
.L080BE7C8:
	movs r0, #0
.L080BE7CA:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080BE7D0
sub_080BE7D0: @ 0x080BE7D0
	push {r4, lr}
	adds r4, r0, #0
	bl Door_KeypadInitInputState
	str r0, [r4, #0x24]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080BE7E0
sub_080BE7E0: @ 0x080BE7E0
	ldr r1, [r0, #0x24]
	movs r0, #1
	str r0, [r1, #0xc]
	bx lr

	thumb_func_start sub_080BE7E8
sub_080BE7E8: @ 0x080BE7E8
	ldr r1, .L080BE7F8
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	ldr r0, .L080BE7FC
	strh r2, [r0]
	bx lr
	.byte 0x00, 0x00
.L080BE7F8: .4byte 0x03004550 @ IWRAM+0x4550
.L080BE7FC: .4byte 0x03003FF4 @ IWRAM+0x3FF4

	thumb_func_start sub_080BE800
sub_080BE800: @ 0x080BE800
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x24
	bl sub_080BE70C
	adds r6, r0, #0
	ldrb r0, [r6, #3]
	lsls r0, r0, #2
	ldr r1, .L080BE854
	adds r4, r0, r1
	ldr r0, .L080BE858
	ldr r0, [r0]
	bl NumberToDigits
	adds r1, r0, #0
	ldrb r0, [r1, #3]
	ldrb r2, [r4]
	cmp r0, r2
	bne .L080BE85C
	ldrb r0, [r1, #2]
	ldrb r2, [r4, #1]
	cmp r0, r2
	bne .L080BE85C
	ldrb r0, [r1, #1]
	ldrb r2, [r4, #2]
	cmp r0, r2
	bne .L080BE85C
	ldrb r0, [r1]
	ldrb r4, [r4, #3]
	cmp r0, r4
	bne .L080BE85C
	movs r0, #0
	strh r0, [r5, #0x1e]
	ldrb r0, [r6, #3]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r0, r1
	bl Flag_Set
	b .L080BE86E
	.byte 0x00, 0x00
.L080BE854: .4byte gUnknown_081982FD
.L080BE858: .4byte 0x030031CC @ IWRAM+0x31CC
.L080BE85C:
	ldr r0, [r7, #4]
	adds r0, #1
	str r0, [r7, #4]
	cmp r0, #3
	bne .L080BE86A
	movs r0, #2
	b .L080BE86C
.L080BE86A:
	movs r0, #1
.L080BE86C:
	strh r0, [r5, #0x1e]
.L080BE86E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080BE874
sub_080BE874: @ 0x080BE874
	ldr r1, .L080BE87C
	ldr r1, [r1]
	strh r1, [r0, #0x1e]
	bx lr
.L080BE87C: .4byte 0x030031CC @ IWRAM+0x31CC

	thumb_func_start sub_080BE880
sub_080BE880: @ 0x080BE880
	push {r4, lr}
	cmp r1, #0
	bne .L080BE8A0
	ldr r4, .L080BE89C
	ldrh r0, [r4, #2]
	bl sub_080B1A1C
	strh r0, [r4, #2]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	b .L080BE8A8
.L080BE89C: .4byte 0x03004550 @ IWRAM+0x4550
.L080BE8A0:
	ldr r0, .L080BE8B0
	movs r1, #1
	bl VBlankTask_AddCounted
.L080BE8A8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BE8B0: .4byte sub_080B0158

	thumb_func_start sub_080BE8B4
sub_080BE8B4: @ 0x080BE8B4
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #8
	bl sub_080C0148
	adds r4, r0, #0
	bl sub_080BE70C
	adds r6, r0, #0
	mov r1, sp
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	strb r0, [r1, #1]
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	strb r0, [r1, #2]
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	strb r0, [r1, #3]
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	strb r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	strb r0, [r1, #5]
	ldrb r0, [r4, #0xc]
	bl sub_080C0818
	movs r1, #0x80
	lsls r1, r1, #4
	ands r1, r0
	cmp r1, #0
	beq .L080BE920
	mov r0, sp
	movs r1, #1
	strb r1, [r0]
	strb r1, [r0, #1]
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	strb r1, [r0, #4]
	mov r1, sp
	movs r0, #0x28
	strb r0, [r1, #5]
.L080BE920:
	ldrh r1, [r6, #2]
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x14
	movs r0, #0xf
	ands r2, r0
	mov r3, sp
	adds r0, r3, r2
	ldrb r0, [r0]
	lsrs r1, r1, #0x18
	cmp r0, r1
	blo .L080BE948
	ldr r1, .L080BE944
	adds r0, r5, #0
	bl sub_080B832C
	movs r0, #1
	b .L080BE958
	.byte 0x00, 0x00
.L080BE944: .4byte gUnknown_08002EFE
.L080BE948:
	ldr r1, .L080BE964
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl sub_080B832C
	movs r0, #0
.L080BE958:
	strh r0, [r5, #0x1c]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BE964: .4byte gUnknown_0819853C

	thumb_func_start sub_080BE968
sub_080BE968: @ 0x080BE968
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #8
	bl sub_080C0148
	adds r4, r0, #0
	bl sub_080BE70C
	adds r1, r0, #0
	adds r4, #0x58
	ldrh r2, [r4]
	movs r4, #0
	ldr r0, .L080BE998
	cmp r2, r0
	bhi .L080BE99C
	ldrh r1, [r1, #2]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r4, r0, #0x1f
	b .L080BE9B8
.L080BE998: .4byte 0x00006FFF
.L080BE99C:
	ldr r0, .L080BE9A8
	cmp r2, r0
	bhi .L080BE9AC
	ldrh r1, [r1, #2]
	movs r0, #0x10
	b .L080BE9B0
.L080BE9A8: .4byte 0x00008FFF
.L080BE9AC:
	ldrh r1, [r1, #2]
	movs r0, #0x20
.L080BE9B0:
	ands r0, r1
	cmp r0, #0
	beq .L080BE9B8
	movs r4, #1
.L080BE9B8:
	cmp r4, #1
	bne .L080BE9CC
	ldr r1, .L080BE9C8
	adds r0, r5, #0
	bl sub_080B832C
	strh r4, [r5, #0x1c]
	b .L080BE9D8
.L080BE9C8: .4byte gUnknown_08002EFE
.L080BE9CC:
	ldr r1, .L080BE9E0
	adds r0, r5, #0
	bl sub_080B832C
	movs r0, #0
	strh r0, [r5, #0x1c]
.L080BE9D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BE9E0: .4byte gUnknown_08003192

	thumb_func_start sub_080BE9E4
sub_080BE9E4: @ 0x080BE9E4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x24
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1a
	movs r3, #2
	bl Window_Create
	str r0, [r4, #0xc]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BEA08
sub_080BEA08: @ 0x080BEA08
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x24
	movs r0, #0
	strh r0, [r2, #0x1c]
	movs r4, #1
	adds r1, r4, #0
	ldrh r0, [r3, #8]
	lsls r1, r0
	ldr r0, [r2, #0x24]
	ands r0, r1
	cmp r0, #0
	bne .L080BEA2C
	strh r4, [r2, #0x1c]
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
.L080BEA2C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BEA34
sub_080BEA34: @ 0x080BEA34
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x24
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldr r0, .L080BEA5C
	ldrh r1, [r0]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L080BEA56
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	strh r4, [r2, #0x1c]
.L080BEA56:
	pop {r4}
	pop {r0}
	bx r0
.L080BEA5C: .4byte 0x030031B8 @ IWRAM+0x31B8

	thumb_func_start Status_ShowAfflictionMessage
Status_ShowAfflictionMessage: @ 0x080BEA60
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x24
	ldrh r0, [r1, #8]
	cmp r0, #0
	bne .L080BEA84
	ldrh r4, [r1, #4]
	ldr r0, [r2, #0x24]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080BEA7E
	b .L080BEC1A
.L080BEA7E:
	movs r0, #0x80
	lsls r0, r0, #8
	b .L080BEAA0
.L080BEA84:
	ldrh r4, [r1, #6]
	ldr r0, [r2, #0x24]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne .L080BEA92
	b .L080BEC1A
.L080BEA92:
	bl sub_080C1B50
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080BEAA0:
	bl Battle_GetCombatant
	adds r1, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r4, r0
	beq .L080BEB68
	cmp r4, r0
	bgt .L080BEAE6
	cmp r4, #0x10
	beq .L080BEB88
	cmp r4, #0x10
	bgt .L080BEAD2
	cmp r4, #4
	bne .L080BEAC0
	b .L080BEB98
.L080BEAC0:
	cmp r4, #4
	bgt .L080BEACC
	cmp r4, #2
	bne .L080BEACA
	b .L080BEBA0
.L080BEACA:
	b .L080BEBA2
.L080BEACC:
	cmp r4, #8
	beq .L080BEB90
	b .L080BEBA2
.L080BEAD2:
	cmp r4, #0x40
	beq .L080BEB78
	cmp r4, #0x40
	bgt .L080BEAE0
	cmp r4, #0x20
	beq .L080BEB80
	b .L080BEBA2
.L080BEAE0:
	cmp r4, #0x80
	beq .L080BEB70
	b .L080BEBA2
.L080BEAE6:
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r4, r0
	beq .L080BEB48
	cmp r4, r0
	bgt .L080BEB12
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r4, r0
	beq .L080BEB58
	cmp r4, r0
	bgt .L080BEB08
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r4, r0
	beq .L080BEB60
	b .L080BEBA2
.L080BEB08:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r4, r0
	beq .L080BEB50
	b .L080BEBA2
.L080BEB12:
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r4, r0
	beq .L080BEB38
	cmp r4, r0
	bgt .L080BEB28
	movs r0, #0x80
	lsls r0, r0, #6
	cmp r4, r0
	beq .L080BEB40
	b .L080BEBA2
.L080BEB28:
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r4, r0
	bne .L080BEBA2
	ldr r6, .L080BEB34
	b .L080BEBA2
.L080BEB34: .4byte gUnknown_0819873C
.L080BEB38:
	ldr r6, .L080BEB3C
	b .L080BEBA2
.L080BEB3C: .4byte gUnknown_08198748
.L080BEB40:
	ldr r6, .L080BEB44
	b .L080BEBA2
.L080BEB44: .4byte gUnknown_0819875E
.L080BEB48:
	ldr r6, .L080BEB4C
	b .L080BEBA2
.L080BEB4C: .4byte gUnknown_0819876C
.L080BEB50:
	ldr r6, .L080BEB54
	b .L080BEBA2
.L080BEB54: .4byte gUnknown_08198780
.L080BEB58:
	ldr r6, .L080BEB5C
	b .L080BEBA2
.L080BEB5C: .4byte gUnknown_08198794
.L080BEB60:
	ldr r6, .L080BEB64
	b .L080BEBA2
.L080BEB64: .4byte gUnknown_081987A8
.L080BEB68:
	ldr r6, .L080BEB6C
	b .L080BEBA2
.L080BEB6C: .4byte gUnknown_081987BA
.L080BEB70:
	ldr r6, .L080BEB74
	b .L080BEBA2
.L080BEB74: .4byte gUnknown_081987C8
.L080BEB78:
	ldr r6, .L080BEB7C
	b .L080BEBA2
.L080BEB7C: .4byte gUnknown_081987D4
.L080BEB80:
	ldr r6, .L080BEB84
	b .L080BEBA2
.L080BEB84: .4byte gUnknown_081987E6
.L080BEB88:
	ldr r6, .L080BEB8C
	b .L080BEBA2
.L080BEB8C: .4byte gUnknown_081987FC
.L080BEB90:
	ldr r6, .L080BEB94
	b .L080BEBA2
.L080BEB94: .4byte gUnknown_0819880E
.L080BEB98:
	ldr r6, .L080BEB9C
	b .L080BEBA2
.L080BEB9C: .4byte gUnknown_08198822
.L080BEBA0:
	ldr r6, .L080BEBB4
.L080BEBA2:
	movs r5, #0x10
	adds r0, r1, #0
	add r1, sp, #8
	bl Combatant_DecodeName
	movs r4, #0
	add r0, sp, #8
	b .L080BEBE6
	.byte 0x00, 0x00
.L080BEBB4: .4byte gUnknown_08198834
.L080BEBB8:
	lsls r0, r4, #1
	.2byte 0x4468 @ add r0, sp, r0
	adds r0, #8
	ldrh r0, [r0]
	movs r1, #0x59
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl FontSprite_DrawGlyph
	adds r0, r5, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #7
	bhi .L080BEBEC
	lsls r0, r4, #1
	.2byte 0x4468 @ add r0, sp, r0
	adds r0, #8
.L080BEBE6:
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080BEBB8
.L080BEBEC:
	movs r0, #0x59
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Text_DrawSpriteString
	ldr r0, .L080BEC24
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080BEC1A
	movs r0, #0
	movs r1, #0
	movs r2, #0xd6
	movs r3, #0x61
	bl sub_080C4AB0
.L080BEC1A:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BEC24: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_080BEC28
sub_080BEC28: @ 0x080BEC28
	push {lr}
	ldr r0, [r0, #0x30]
	movs r1, #1
	bl Window_Close
	movs r0, #1
	bl Field_SetState
	pop {r0}
	bx r0

	thumb_func_start sub_080BEC3C
sub_080BEC3C: @ 0x080BEC3C
.L080BEC3C:
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080BEC64
	ldr r1, .L080BEC68
	bl Task_Create
	adds r1, r0, #0
	adds r1, #0x24
	str r6, [r0, #0x24]
	strh r4, [r1, #4]
	strh r5, [r1, #6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BEC64: .4byte gUnknown_08198848
.L080BEC68: .4byte 0x0000FFFF

	thumb_func_start sub_080BEC6C
sub_080BEC6C: @ 0x080BEC6C
	adds r3, r0, #0
	adds r3, #0x24
	ldr r2, .L080BEC80
	ldr r1, [r2, #0x2c]
	str r1, [r0, #0x24]
	ldrh r0, [r2, #0x30]
	strh r0, [r3, #4]
	ldrh r0, [r2, #0x32]
	strh r0, [r3, #6]
	bx lr
.L080BEC80: .4byte 0x030069F0 @ IWRAM+0x69F0

	thumb_func_start sub_080BEC84
sub_080BEC84: @ 0x080BEC84
	push {lr}
	ldr r0, [r0, #0x30]
	movs r1, #1
	bl Window_Close
	ldr r1, .L080BECA0
	movs r0, #0
	strh r0, [r1, #0x1e]
	movs r0, #0x1e
	bl Field_SetState
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BECA0: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080BECA4
sub_080BECA4: @ 0x080BECA4
.L080BECA4:
	push {lr}
	bl sub_080C1D9C
	adds r1, r0, #0
	movs r0, #0xf0
	ands r1, r0
	cmp r1, #0x8f
	bls .L080BECC4
	adds r0, r1, #0
	adds r0, #0x80
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r0, #0x80
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
.L080BECC4:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080BECCC
sub_080BECCC: @ 0x080BECCC
.L080BECCC:
	push {r4, lr}
	bl sub_080BECA4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0x1d
	bl Flag_Test
	cmp r0, #0
	bne .L080BECF2
	cmp r4, #0x80
	beq .L080BED08
	bl sub_080C2244
	movs r1, #0xff
	ands r1, r0
	cmp r1, #0x1f
	bls .L080BED08
	b .L080BED54
.L080BECF2:
	movs r0, #0x23
	bl Flag_Test
	cmp r0, #0
	bne .L080BED0C
	bl sub_080C2244
	movs r1, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bhi .L080BED54
.L080BED08:
	movs r0, #2
	b .L080BED5A
.L080BED0C:
	movs r0, #0x68
	bl Flag_Test
	cmp r0, #0
	bne .L080BED24
	bl sub_080C2244
	movs r1, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bls .L080BED44
	b .L080BED54
.L080BED24:
	movs r0, #0x96
	bl Flag_Test
	cmp r0, #0
	bne .L080BED48
	movs r0, #0x7d
	bl Flag_Test
	cmp r0, #0
	bne .L080BED48
	bl sub_080C2244
	movs r1, #0xff
	ands r1, r0
	cmp r1, #0x1f
	bhi .L080BED54
.L080BED44:
	movs r0, #3
	b .L080BED5A
.L080BED48:
	bl sub_080C2244
	movs r1, #0xff
	ands r1, r0
	cmp r1, #0x3f
	bls .L080BED58
.L080BED54:
	movs r0, #1
	b .L080BED5A
.L080BED58:
	movs r0, #4
.L080BED5A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080BED60
sub_080BED60: @ 0x080BED60
.L080BED60:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, .L080BEDF8
	ldrh r0, [r4, #0x12]
	ldrh r1, [r4, #0x14]
	mov r5, sp
	adds r5, #2
	mov r2, sp
	adds r3, r5, #0
	bl sub_080C1F50
	adds r4, #0x62
	movs r0, #0
	strh r0, [r4]
	mov r8, r0
	mov sl, r5
	ldr r5, .L080BEDFC
	mov sb, r5
	movs r7, #0
.L080BED8E:
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5]
	cmp r0, r1
	bne .L080BEE04
	mov r0, sb
	adds r0, #2
	adds r0, r7, r0
	mov r2, sl
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne .L080BEE04
	ldr r6, .L080BEDF8
	ldrh r0, [r6, #2]
	ldrh r1, [r5, #4]
	cmp r0, r1
	bne .L080BEE12
	movs r0, #0xae
	bl Flag_Test
	cmp r0, #0
	bne .L080BEDF4
	movs r0, #0x65
	bl Flag_Test
	cmp r0, #0
	bne .L080BEDF4
	movs r0, #0x9c
	bl Flag_Test
	adds r4, r0, #0
	cmp r4, #0
	bne .L080BEDF4
	movs r0, #0x16
	bl Flag_Test
	cmp r0, #0
	beq .L080BEE04
	bl sub_080BECCC
	adds r1, r0, #0
	adds r2, r6, #0
	adds r2, #0x62
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080BEE00
	subs r0, r1, #2
	strh r0, [r2]
.L080BEDF4:
	movs r0, #1
	b .L080BEE14
.L080BEDF8: .4byte 0x03004550 @ IWRAM+0x4550
.L080BEDFC: .4byte gUnknown_08198978
.L080BEE00:
	strh r4, [r2]
	b .L080BEE12
.L080BEE04:
	adds r5, #6
	adds r7, #6
	movs r2, #1
	add r8, r2
	mov r0, r8
	cmp r0, #0x2f
	bls .L080BED8E
.L080BEE12:
	movs r0, #0
.L080BEE14:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080BEE24
sub_080BEE24: @ 0x080BEE24
.L080BEE24:
	push {r4, r5, lr}
	bl sub_080BED60
	adds r5, r0, #0
	cmp r5, #0
	beq .L080BEE62
	ldr r1, .L080BEE6C
	ldr r0, .L080BEE70
	adds r0, #0x62
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r4, #0
	bl ScriptVM_RunAlt
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L080BEE5A
	adds r0, r4, #0
	bl ScriptVM_RunAlt
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L080BEE62
.L080BEE5A:
	movs r0, #0xc
	adds r1, r4, #0
	bl sub_080AF178
.L080BEE62:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080BEE6C: .4byte gUnknown_08198A98
.L080BEE70: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080BEE74
sub_080BEE74: @ 0x080BEE74
	ldr r1, .L080BEE94
	ldr r0, .L080BEE98
	str r0, [r1]
	ldr r0, .L080BEE9C
	str r0, [r1, #4]
	ldr r0, .L080BEEA0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080BEEA4
	str r0, [r1]
	ldr r0, .L080BEEA8
	str r0, [r1, #4]
	ldr r0, .L080BEEAC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L080BEE94: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BEE98: .4byte 0x06004040 @ VRAM+0x4040
.L080BEE9C: .4byte 0x0600CC00 @ VRAM+0xCC00
.L080BEEA0: .4byte 0x840007F0
.L080BEEA4: .4byte 0x06008040 @ VRAM+0x8040
.L080BEEA8: .4byte 0x0600EBC0 @ VRAM+0xEBC0
.L080BEEAC: .4byte 0x84000440

	thumb_func_start sub_080BEEB0
sub_080BEEB0: @ 0x080BEEB0
	ldr r0, .L080BEED0
	ldr r1, .L080BEED4
	str r1, [r0]
	ldr r1, .L080BEED8
	str r1, [r0, #4]
	ldr r2, .L080BEEDC
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, .L080BEEE0
	str r1, [r0]
	ldr r1, .L080BEEE4
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	bx lr
	.byte 0x00, 0x00
.L080BEED0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BEED4: .4byte 0x06004040 @ VRAM+0x4040
.L080BEED8: .4byte 0x0600CC00 @ VRAM+0xCC00
.L080BEEDC: .4byte 0x840005B8
.L080BEEE0: .4byte 0x06008E00 @ VRAM+0x8E00
.L080BEEE4: .4byte 0x0600E2E0 @ VRAM+0xE2E0

	thumb_func_start sub_080BEEE8
sub_080BEEE8: @ 0x080BEEE8
	push {lr}
	ldr r0, .L080BEF04
	ldrh r0, [r0]
	movs r1, #8
	bl sub_080C5F04
	cmp r0, #0
	bne .L080BEF0C
	ldr r0, .L080BEF08
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080BEF14
	.byte 0x00, 0x00
.L080BEF04: .4byte 0x03004534 @ IWRAM+0x4534
.L080BEF08: .4byte sub_080BEE74
.L080BEF0C:
	ldr r0, .L080BEF18
	movs r1, #1
	bl VBlankTask_AddCounted
.L080BEF14:
	pop {r0}
	bx r0
.L080BEF18: .4byte sub_080BEEB0

	thumb_func_start sub_080BEF1C
sub_080BEF1C: @ 0x080BEF1C
	ldr r1, .L080BEF38
	ldr r0, .L080BEF3C
	str r0, [r1]
	ldr r0, .L080BEF40
	str r0, [r1, #4]
	ldr r0, .L080BEF44
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xc8
	ldr r2, .L080BEF48
	adds r0, r2, #0
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080BEF38: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BEF3C: .4byte 0x02000000 @ EWRAM
.L080BEF40: .4byte 0x06001000 @ VRAM+0x1000
.L080BEF44: .4byte 0x84000400
.L080BEF48: .4byte 0x00008408

	thumb_func_start sub_080BEF4C
sub_080BEF4C: @ 0x080BEF4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, .L080BEFE4
	mov sb, r0
	movs r7, #0x98
	lsls r7, r7, #2
	ldr r4, .L080BEFE8
	ldrh r0, [r4]
	movs r1, #0
	bl sub_080C5F40
	adds r5, r0, #0
	ldrh r0, [r4]
	movs r1, #1
	bl sub_080C5F40
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp]
	ldr r0, .L080BEFEC
	mov r1, sp
	str r1, [r0]
	mov r3, sb
	str r3, [r0, #4]
	ldr r1, .L080BEFF0
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldrh r0, [r4]
	movs r1, #8
	bl sub_080C5F04
	cmp r0, #0
	bne .L080BF034
	ldrh r1, [r4]
	adds r0, r1, #0
	subs r0, #0xd9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L080BEFF8
	movs r4, #8
	cmp r1, #0xda
	bne .L080BEFAC
	movs r4, #7
.L080BEFAC:
	movs r0, #0
	ldr r6, .L080BEFF4
	mov sl, r6
	movs r3, #0xf
.L080BEFB4:
	movs r2, #0
	adds r1, r0, #1
	mov ip, r1
	lsls r0, r0, #6
	mov r6, sb
	adds r1, r0, r6
.L080BEFC0:
	ldrb r0, [r5]
	adds r5, #1
	ands r0, r3
	adds r0, r0, r4
	lsls r0, r0, #0xc
	adds r0, r7, r0
	strh r0, [r1]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r1, #2
	adds r2, #1
	cmp r2, #0x1d
	bls .L080BEFC0
	mov r0, ip
	cmp r0, #0xc
	bls .L080BEFB4
	b .L080BF08E
.L080BEFE4: .4byte 0x02000000 @ EWRAM
.L080BEFE8: .4byte 0x03004534 @ IWRAM+0x4534
.L080BEFEC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BEFF0: .4byte 0x85000400
.L080BEFF4: .4byte sub_080BEF1C
.L080BEFF8:
	movs r0, #0
	ldr r1, .L080BF030
	mov sl, r1
	movs r3, #0xf
.L080BF000:
	movs r2, #0
	adds r4, r0, #1
	mov ip, r4
	lsls r0, r0, #6
	mov r6, sb
	adds r1, r0, r6
.L080BF00C:
	ldrb r0, [r5]
	adds r5, #1
	ands r0, r3
	adds r0, #8
	lsls r0, r0, #0xc
	adds r0, r7, r0
	strh r0, [r1, #2]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r1, #2
	adds r2, #1
	cmp r2, #0x1b
	bls .L080BF00C
	mov r0, ip
	cmp r0, #0xc
	bls .L080BF000
	b .L080BF08E
.L080BF030: .4byte sub_080BEF1C
.L080BF034:
	movs r0, #0
	ldr r1, .L080BF0B4
	mov sl, r1
	movs r3, #0xf
	mov r8, r3
.L080BF03E:
	movs r2, #0
	lsls r1, r0, #5
	adds r4, r0, #1
	mov ip, r4
	adds r1, #0x1c
	lsls r0, r0, #6
	mov r6, sb
	adds r4, r0, r6
	lsls r1, r1, #1
	adds r3, r1, r6
.L080BF052:
	ldrb r1, [r5]
	adds r5, #1
	ldr r6, [sp, #4]
	ldrb r0, [r6]
	adds r6, #1
	str r6, [sp, #4]
	mov r6, r8
	ands r1, r6
	adds r1, #8
	ands r0, r6
	adds r0, #8
	lsls r1, r1, #0xc
	adds r1, r7, r1
	strh r1, [r4, #2]
	lsls r0, r0, #0xc
	adds r0, r7, r0
	ldr r1, .L080BF0B8
	adds r0, r0, r1
	strh r0, [r3]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	subs r3, #2
	adds r4, #2
	adds r2, #1
	cmp r2, #0xd
	bls .L080BF052
	mov r0, ip
	cmp r0, #0x19
	bls .L080BF03E
.L080BF08E:
	mov r0, sl
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0x10
	movs r1, #0
	bl sub_080C140C
	ldr r1, .L080BF0BC
	movs r0, #8
	strh r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080BF0B4: .4byte sub_080BEF1C
.L080BF0B8: .4byte 0x000004B7
.L080BF0BC: .4byte 0x03000044 @ IWRAM+0x44

	thumb_func_start sub_080BF0C0
sub_080BF0C0: @ 0x080BF0C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r0, #0x24
	mov sb, r0
	ldrh r6, [r0, #6]
	ldrh r0, [r0, #8]
	movs r3, #0x3f
	ands r3, r0
	movs r0, #0
	b .L080BF13E
.L080BF0DC:
	mov sl, r8
	str r5, [sp, #4]
	ldrh r0, [r4, #8]
	subs r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldrh r0, [r4, #0xa]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b .L080BF132
.L080BF0F2:
	movs r5, #0
	cmp r5, r7
	bhs .L080BF132
.L080BF0F8:
	ldrh r0, [r4, #8]
	cmp r0, r6
	bhi .L080BF122
	ldrh r0, [r4, #0xa]
	cmp r0, r3
	bhi .L080BF122
	ldrh r0, [r4, #0xc]
	cmp r0, r6
	blo .L080BF122
	ldrh r0, [r4, #0xe]
	cmp r0, r3
	blo .L080BF122
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r3, #0
	str r3, [sp, #8]
	bl SubMap_IsOutsideExclusions
	ldr r3, [sp, #8]
	cmp r0, #1
	beq .L080BF0DC
.L080BF122:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r4, r4, r1
	cmp r5, r7
	blo .L080BF0F8
.L080BF132:
	cmp r5, r7
	bne .L080BF15A
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L080BF13E:
	mov r8, r0
	mov r0, r8
	str r3, [sp, #8]
	bl sub_080C8B3C
	adds r7, r0, #0
	mov r0, r8
	movs r1, #0
	bl DungeonMap_GetFloor
	adds r4, r0, #0
	ldr r3, [sp, #8]
	cmp r4, #0
	bne .L080BF0F2
.L080BF15A:
	ldr r5, .L080BF1A4
	mov r0, sl
	str r0, [r5]
	ldr r4, .L080BF1A8
	ldr r1, [sp, #4]
	str r1, [r4]
	ldr r2, .L080BF1AC
	movs r7, #0
	strh r6, [r2, #0x12]
	strh r3, [r2, #0x14]
	mov r1, sb
	ldrh r0, [r1, #8]
	lsrs r0, r0, #5
	movs r1, #6
	ands r0, r1
	lsrs r0, r0, #1
	strh r0, [r2, #2]
	str r7, [sp]
	ldr r1, .L080BF1B0
	ldr r2, .L080BF1B4
	mov r0, sp
	bl CpuSet
	bl sub_080AE234
	ldr r0, [r5]
	ldr r1, [r4]
	bl Map_SetGraphicsPointers
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080BF1A4: .4byte 0x03004614 @ IWRAM+0x4614
.L080BF1A8: .4byte 0x03004514 @ IWRAM+0x4514
.L080BF1AC: .4byte 0x03004550 @ IWRAM+0x4550
.L080BF1B0: .4byte 0x02005004 @ EWRAM+0x5004
.L080BF1B4: .4byte 0x05001000

	thumb_func_start sub_080BF1B8
sub_080BF1B8: @ 0x080BF1B8
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080BF1E4
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080BF1E8
	str r0, [r1, #4]
	ldr r0, .L080BF1EC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080BF1F0
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L080BF1F4
	str r0, [r1, #4]
	ldr r0, .L080BF1F8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	bx lr
	.byte 0x00, 0x00
.L080BF1E4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BF1E8: .4byte 0x02028074 @ EWRAM+0x28074
.L080BF1EC: .4byte 0x85000008
.L080BF1F0: .4byte 0x03003B94 @ IWRAM+0x3B94
.L080BF1F4: .4byte 0x06004000 @ VRAM+0x4000
.L080BF1F8: .4byte 0x84000800

	thumb_func_start sub_080BF1FC
sub_080BF1FC: @ 0x080BF1FC
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, .L080BF21C
	ldr r1, [r2]
	cmp r1, #0
	beq .L080BF228
	ldr r0, .L080BF220
	ldrh r0, [r0]
	ldr r1, .L080BF224
	ldrh r1, [r1]
	bl Map_LoadGraphicsStep
	movs r0, #0
	strh r0, [r4, #0x1c]
	b .L080BF240
	.byte 0x00, 0x00
.L080BF21C: .4byte 0x03003FF8 @ IWRAM+0x3FF8
.L080BF220: .4byte 0x03004614 @ IWRAM+0x4614
.L080BF224: .4byte 0x03004514 @ IWRAM+0x4514
.L080BF228:
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r0, .L080BF248
	strh r1, [r0, #0xe]
	ldr r0, .L080BF24C
	movs r1, #1
	bl VBlankTask_AddCounted
	ldr r0, .L080BF250
	movs r1, #1
	bl VBlankTask_AddCounted
.L080BF240:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BF248: .4byte 0x03004550 @ IWRAM+0x4550
.L080BF24C: .4byte sub_080ADF64
.L080BF250: .4byte sub_080BF1B8

	thumb_func_start sub_080BF254
sub_080BF254: @ 0x080BF254
	ldr r1, .L080BF268
	ldr r0, .L080BF26C
	str r0, [r1]
	ldr r0, .L080BF270
	str r0, [r1, #4]
	ldr r0, .L080BF274
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080BF268: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BF26C: .4byte 0x02000000 @ EWRAM
.L080BF270: .4byte 0x06002000 @ VRAM+0x2000
.L080BF274: .4byte 0x84000140

	thumb_func_start sub_080BF278
sub_080BF278: @ 0x080BF278
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r6, .L080BF2E8
	ldr r5, .L080BF2EC
	ldr r1, .L080BF2F0
	ldr r0, .L080BF2F4
	str r0, [r1]
	str r5, [r1, #4]
	ldr r0, .L080BF2F8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
	adds r7, r5, #0
.L080BF292:
	movs r2, #0
	adds r4, r0, #1
	lsls r3, r0, #5
.L080BF298:
	adds r0, r3, r2
	lsls r0, r0, #1
	adds r1, r0, r5
	adds r1, #0x42
	adds r0, r0, r6
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x1b
	bls .L080BF298
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls .L080BF292
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1c
	str r0, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0xd
	movs r3, #1
	bl Tilemap_OffsetRect
	bl Field_CopyIwramCode
	ldr r0, .L080BF2FC
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080BF2E8: .4byte gUnknown_081B8370
.L080BF2EC: .4byte 0x02000000 @ EWRAM
.L080BF2F0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BF2F4: .4byte gUnknown_0857D9C0
.L080BF2F8: .4byte 0x84000140
.L080BF2FC: .4byte sub_080BF254

	thumb_func_start sub_080BF300
sub_080BF300: @ 0x080BF300
.L080BF300:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080BF324
	ldr r1, .L080BF328
	bl Task_Create
	adds r1, r0, #0
	adds r1, #0x24
	strh r4, [r1, #6]
	strh r5, [r1, #8]
	pop {r4, r5}
	pop {r1}
	bx r1
.L080BF324: .4byte gUnknown_08198AD0
.L080BF328: .4byte 0x0000FFFF

	thumb_func_start sub_080BF32C
sub_080BF32C: @ 0x080BF32C
.L080BF32C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080BF340
	movs r0, #0xff
	ands r1, r0
.L080BF340:
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L080BF350
	adds r0, r0, r1
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080BF350: .4byte gUnknown_08198B74

	thumb_func_start Equipment_GetRecord36_MidRange
Equipment_GetRecord36_MidRange: @ 0x080BF354
.L080BF354:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080BF368
	movs r0, #0xff
	ands r1, r0
.L080BF368:
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L080BF378
	adds r0, r0, r1
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080BF378: .4byte gUnknown_08198B74

	thumb_func_start sub_080BF37C
sub_080BF37C: @ 0x080BF37C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, [sp, #0x24]
	ldr r5, [sp, #0x28]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sb, r2
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r6
	cmp r0, #0
	beq .L080BF3B8
	movs r0, #0xff
	ands r6, r0
.L080BF3B8:
	cmp r6, #0xcf
	bls .L080BF3C8
	adds r0, r6, #0
	bl Action_GetRecord
	adds r4, r0, #0
	adds r4, #0xc
	b .L080BF3DE
.L080BF3C8:
	cmp r6, #0x7f
	bls .L080BF3D4
	adds r0, r6, #0
	bl Equipment_GetRecord36_MidRange
	b .L080BF3DA
.L080BF3D4:
	adds r0, r6, #0
	bl sub_080BF32C
.L080BF3DA:
	adds r4, r0, #0
	adds r4, #0x14
.L080BF3DE:
	movs r6, #0
	b .L080BF400
.L080BF3E2:
	ldrh r0, [r4]
	mov r1, r8
	str r1, [sp]
	mov r1, sl
	mov r2, sb
	adds r3, r7, #0
	bl FontSprite_DrawGlyph
	adds r4, #2
	adds r0, r7, r5
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r6, #1
	cmp r6, #7
	bhi .L080BF406
.L080BF400:
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080BF3E2
.L080BF406:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start Action_GetRecord
Action_GetRecord: @ 0x080BF418
.L080BF418:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080BF42C
	movs r0, #0xff
	ands r1, r0
.L080BF42C:
	lsls r0, r1, #5
	ldr r1, .L080BF438
	adds r0, r0, r1
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080BF438: .4byte gUnknown_08198EB4

	thumb_func_start sub_080BF43C
sub_080BF43C: @ 0x080BF43C
.L080BF43C:
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r5, #0xf
	movs r6, #0xf
	movs r4, #2
.L080BF448:
	ldrb r0, [r3]
	lsrs r1, r0, #4
	ands r1, r5
	strb r1, [r2]
	adds r2, #1
	adds r1, r6, #0
	ands r1, r0
	strb r1, [r2]
	adds r3, #1
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bge .L080BF448
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080BF468
sub_080BF468: @ 0x080BF468
.L080BF468:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r4
	cmp r0, #0
	beq .L080BF47E
	movs r0, #0xff
	ands r4, r0
.L080BF47E:
	cmp r4, #0x7f
	bgt .L080BF4C8
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BF32C
	adds r2, r0, #0
	cmp r5, #7
	bls .L080BF492
	b .L080BF5B2
.L080BF492:
	lsls r0, r5, #2
	ldr r1, .L080BF49C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080BF49C: .4byte gUnknown_080BF4A0
	.global gUnknown_080BF4A0
gUnknown_080BF4A0:
.L080BF4A0: @ jump table
	.4byte .L080BF574
	.4byte .L080BF57C
	.4byte .L080BF510
	.4byte .L080BF514
	.4byte .L080BF5AE
	.4byte .L080BF4C0
	.4byte .L080BF51C
	.4byte .L080BF4C4
.L080BF4C0:
	adds r0, r2, #4
	b .L080BF5A6
.L080BF4C4:
	ldrb r1, [r2, #0xb]
	b .L080BF5B6
.L080BF4C8:
	cmp r4, #0xcf
	bgt .L080BF520
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl Equipment_GetRecord36_MidRange
	adds r2, r0, #0
	cmp r5, #9
	bhi .L080BF5B2
	lsls r0, r5, #2
	ldr r1, .L080BF4E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080BF4E4: .4byte gUnknown_080BF4E8
	.global gUnknown_080BF4E8
gUnknown_080BF4E8:
.L080BF4E8: @ jump table
	.4byte .L080BF574
	.4byte .L080BF57C
	.4byte .L080BF5B2
	.4byte .L080BF5B2
	.4byte .L080BF5B2
	.4byte .L080BF518
	.4byte .L080BF51C
	.4byte .L080BF5AE
	.4byte .L080BF510
	.4byte .L080BF514
.L080BF510:
	ldrb r1, [r2, #1]
	b .L080BF5B6
.L080BF514:
	ldrb r1, [r2, #2]
	b .L080BF5B6
.L080BF518:
	adds r0, r2, #4
	b .L080BF5A6
.L080BF51C:
	ldrh r1, [r2, #8]
	b .L080BF5B6
.L080BF520:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl Action_GetRecord
	adds r2, r0, #0
	subs r0, r5, #1
	cmp r0, #0xc
	bhi .L080BF5B2
	lsls r0, r0, #2
	ldr r1, .L080BF53C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080BF53C: .4byte gUnknown_080BF540
	.global gUnknown_080BF540
gUnknown_080BF540:
.L080BF540: @ jump table
	.4byte .L080BF57C
	.4byte .L080BF5B2
	.4byte .L080BF5B2
	.4byte .L080BF5B2
	.4byte .L080BF5A4
	.4byte .L080BF5B2
	.4byte .L080BF5B2
	.4byte .L080BF5B2
	.4byte .L080BF5B2
	.4byte .L080BF574
	.4byte .L080BF584
	.4byte .L080BF58A
	.4byte .L080BF5AE
.L080BF574:
	ldrb r0, [r2]
	movs r1, #0xf0
	ands r1, r0
	b .L080BF5B6
.L080BF57C:
	ldrb r0, [r2]
	movs r1, #0xf
	ands r1, r0
	b .L080BF5B6
.L080BF584:
	movs r1, #1
	ldrsb r1, [r2, r1]
	b .L080BF5B6
.L080BF58A:
	ldrb r1, [r2, #2]
	cmp r4, #0xf0
	bne .L080BF596
	bl sub_080F6278
	b .L080BF59E
.L080BF596:
	cmp r4, #0xf8
	bne .L080BF5B6
	bl sub_080F6390
.L080BF59E:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b .L080BF5B6
.L080BF5A4:
	adds r0, r2, #1
.L080BF5A6:
	adds r1, r6, #0
	bl sub_080BF43C
	b .L080BF5B8
.L080BF5AE:
	ldrb r1, [r2, #3]
	b .L080BF5B6
.L080BF5B2:
	movs r1, #1
	rsbs r1, r1, #0
.L080BF5B6:
	str r1, [r6]
.L080BF5B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BF5C0
sub_080BF5C0: @ 0x080BF5C0
.L080BF5C0:
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L080BF5D4
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
.L080BF5D4: .4byte gUnknown_0819B9F4

	thumb_func_start sub_080BF5D8
sub_080BF5D8: @ 0x080BF5D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, [sp, #0x24]
	ldr r5, [sp, #0x28]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sb, r2
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	lsls r5, r5, #0x10
	lsrs r7, r5, #0x10
	bl sub_080BF5C0
	adds r4, r0, #6
	movs r5, #0
	ldrh r0, [r0, #6]
	cmp r0, #0
	beq .L080BF638
.L080BF614:
	ldrh r0, [r4]
	mov r1, r8
	str r1, [sp]
	mov r1, sl
	mov r2, sb
	adds r3, r6, #0
	bl FontSprite_DrawGlyph
	adds r4, #2
	adds r0, r6, r7
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r5, #1
	cmp r5, #7
	bhi .L080BF638
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080BF614
.L080BF638:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080BF648
sub_080BF648: @ 0x080BF648
.L080BF648:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r7, r4, #0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	ldr r1, .L080BF68C
	adds r6, r0, r1
	ldr r5, .L080BF690
	ldr r2, .L080BF694
	adds r0, r6, #0
	adds r1, r5, #0
	bl CpuSet
	movs r0, #0x83
	lsls r0, r0, #1
	cmp r4, r0
	beq .L080BF67A
	adds r0, #3
	cmp r4, r0
	beq .L080BF67A
	adds r0, #3
	cmp r4, r0
	bne .L080BF6A0
.L080BF67A:
	ldr r0, .L080BF698
	ldr r4, .L080BF69C
	adds r1, r4, #0
	bl Combatant_DecodeName
	adds r0, r4, #0
	subs r0, #0x22
	b .L080BF6C8
	.byte 0x00, 0x00
.L080BF68C: .4byte gUnknown_0819CB74
.L080BF690: .4byte 0x03005FC0 @ IWRAM+0x5FC0
.L080BF694: .4byte 0x04000018 @ REG_BG2HOFS
.L080BF698: .4byte 0x030050C8 @ IWRAM+0x50C8
.L080BF69C: .4byte 0x03005FE2 @ IWRAM+0x5FE2
.L080BF6A0:
	movs r0, #0x84
	lsls r0, r0, #1
	cmp r4, r0
	bne .L080BF6B0
	ldr r0, .L080BF6AC
	b .L080BF6BE
.L080BF6AC: .4byte 0x030050D0 @ IWRAM+0x50D0
.L080BF6B0:
	movs r0, #0x87
	lsls r0, r0, #1
	cmp r7, r0
	beq .L080BF6BC
	adds r0, r6, #0
	b .L080BF6C8
.L080BF6BC:
	ldr r0, .L080BF6D0
.L080BF6BE:
	adds r1, r5, #0
	adds r1, #0x22
	bl Combatant_DecodeName
	adds r0, r5, #0
.L080BF6C8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080BF6D0: .4byte 0x030050C0 @ IWRAM+0x50C0

	thumb_func_start sub_080BF6D4
sub_080BF6D4: @ 0x080BF6D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, [sp, #0x24]
	ldr r5, [sp, #0x28]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sb, r2
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	lsls r5, r5, #0x10
	lsrs r7, r5, #0x10
	bl sub_080BF648
	adds r4, r0, #0
	adds r4, #0x22
	movs r5, #0
	ldrh r0, [r0, #0x22]
	cmp r0, #0
	beq .L080BF736
.L080BF712:
	ldrh r0, [r4]
	mov r1, r8
	str r1, [sp]
	mov r1, sl
	mov r2, sb
	adds r3, r6, #0
	bl FontSprite_DrawGlyph
	adds r4, #2
	adds r0, r6, r7
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r5, #1
	cmp r5, #7
	bhi .L080BF736
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080BF712
.L080BF736:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080BF748
sub_080BF748: @ 0x080BF748
.L080BF748:
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0
	str r0, [sp]
	ldr r0, .L080BF7D8
	mov r1, sp
	str r1, [r0]
	str r4, [r0, #4]
	ldr r1, .L080BF7DC
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, .L080BF7E0
	lsls r2, r6, #3
	adds r0, r2, r1
	ldrb r0, [r0]
	strb r0, [r4]
	adds r0, r1, #1
	adds r0, r2, r0
	ldrb r0, [r0]
	strb r0, [r4, #1]
	adds r0, r1, #2
	adds r0, r2, r0
	ldrb r0, [r0]
	strb r0, [r4, #2]
	adds r0, r1, #3
	adds r0, r2, r0
	ldrb r0, [r0]
	strb r0, [r4, #3]
	adds r0, r1, #4
	adds r0, r2, r0
	ldrb r0, [r0]
	strb r0, [r4, #4]
	adds r0, r1, #5
	adds r0, r2, r0
	ldrb r0, [r0]
	strb r0, [r4, #5]
	adds r0, r1, #6
	adds r0, r2, r0
	ldrb r0, [r0]
	strb r0, [r4, #6]
	adds r1, #7
	adds r2, r2, r1
	ldrb r0, [r2]
	strb r0, [r4, #7]
	cmp r6, #0
	bne .L080BF7E4
	movs r1, #6
	strb r1, [r4, #0xd]
	movs r0, #0xaf
	lsls r0, r0, #1
	str r0, [r4, #8]
	adds r0, r4, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x29
	movs r0, #5
	strb r0, [r2]
	adds r2, #1
	movs r0, #4
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x2b
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #3
	b .L080BF850
.L080BF7D8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080BF7DC: .4byte 0x85000020
.L080BF7E0: .4byte gUnknown_081A5A00
.L080BF7E4:
	cmp r6, #1
	bne .L080BF80C
	bl sub_080C2244
	movs r1, #3
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, .L080BF804
	adds r1, r1, r0
	movs r0, #0x12
	strb r0, [r4, #0xd]
	ldr r0, .L080BF808
	b .L080BF824
	.byte 0x00, 0x00
.L080BF804: .4byte gUnknown_081A5A20
.L080BF808: .4byte 0x000025DA
.L080BF80C:
	bl sub_080C2244
	movs r1, #3
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, .L080BF8C4
	adds r1, r1, r0
	movs r0, #0x18
	strb r0, [r4, #0xd]
	ldr r0, .L080BF8C8
.L080BF824:
	str r0, [r4, #8]
	ldrb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x28
	strb r2, [r0]
	ldrb r0, [r1, #1]
	adds r2, r4, #0
	adds r2, #0x29
	strb r0, [r2]
	ldrb r0, [r1, #2]
	adds r2, #1
	strb r0, [r2]
	ldrb r0, [r1, #3]
	adds r2, #1
	strb r0, [r2]
	ldrb r2, [r1, #4]
	adds r0, r4, #0
	adds r0, #0x2c
	strb r2, [r0]
	ldrb r0, [r1, #5]
	adds r1, r4, #0
	adds r1, #0x2d
.L080BF850:
	strb r0, [r1]
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x2c]
	str r0, [r4, #0x40]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x21
	movs r0, #0xff
	strb r0, [r1]
	subs r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r1, #3
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	adds r1, #3
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	adds r1, #2
	strb r0, [r1]
	strb r6, [r4, #0xc]
	movs r2, #0
	adds r3, r4, #0
	adds r3, #0x5d
	movs r5, #0xff
.L080BF888:
	adds r1, r3, r2
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r2, #1
	cmp r2, #0x1f
	bls .L080BF888
	ldrb r0, [r4, #0xc]
	bl sub_080F4260
	cmp r6, #3
	bgt .L080BF8BC
	ldr r0, .L080BF8CC
	adds r0, r6, r0
	ldrb r0, [r0]
	strh r0, [r4, #0x14]
	ldr r1, .L080BF8D0
	lsls r0, r6, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x58
	strh r1, [r0]
	ldr r1, .L080BF8D4
	adds r0, r6, r1
	strh r0, [r4, #0x12]
.L080BF8BC:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BF8C4: .4byte gUnknown_081A5A38
.L080BF8C8: .4byte 0x000059D8
.L080BF8CC: .4byte gUnknown_081A59FC
.L080BF8D0: .4byte gUnknown_081A59F4
.L080BF8D4: .4byte 0xFFFF8000

	thumb_func_start sub_080BF8D8
sub_080BF8D8: @ 0x080BF8D8
.L080BF8D8:
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r1, .L080BF904
	lsls r0, r6, #3
	subs r0, r0, r6
	adds r4, r0, r1
.L080BF8E6:
	ldrb r2, [r4]
	adds r0, r6, #0
	adds r1, r5, #0
	bl sub_080C0074
	adds r4, #1
	adds r5, #1
	cmp r5, #6
	ble .L080BF8E6
	adds r0, r6, #0
	bl sub_080BF938
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080BF904: .4byte gUnknown_081A5A50
