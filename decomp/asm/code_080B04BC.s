	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080B04BC
sub_080B04BC: @ 0x080B04BC
.L080B04BC:
	push {r4, r5, lr}
	sub sp, #4
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl sub_080B3078
	cmp r0, #0
	bne .L080B0538
	ldr r0, .L080B0520
	ldr r1, [r0]
	ldr r5, .L080B0524
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
	ldr r0, .L080B0528
	ldr r1, [r0]
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r5, r0
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r0, .L080B052C
	ldr r1, [r0]
	ldr r0, .L080B0530
	cmp r1, r0
	beq .L080B0582
	ldr r0, .L080B0534
	ldr r1, [r0]
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	b .L080B0582
.L080B0520: .4byte 0x03004630 @ IWRAM+0x4630
.L080B0524: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B0528: .4byte 0x03004510 @ IWRAM+0x4510
.L080B052C: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080B0530: .4byte sub_080D977C
.L080B0534: .4byte 0x03003FC8 @ IWRAM+0x3FC8
.L080B0538:
	ldr r1, .L080B058C
	ldr r5, .L080B0590
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
	ldr r1, .L080B0594
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r5, r0
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r0, .L080B0598
	ldr r1, [r0]
	ldr r0, .L080B059C
	cmp r1, r0
	beq .L080B0582
	ldr r1, .L080B05A0
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
.L080B0582:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B058C: .4byte 0x0200F814 @ EWRAM+0xF814
.L080B0590: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B0594: .4byte 0x0200F7F4 @ EWRAM+0xF7F4
.L080B0598: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080B059C: .4byte sub_080D977C
.L080B05A0: .4byte 0x0200F854 @ EWRAM+0xF854

	thumb_func_start sub_080B05A4
sub_080B05A4: @ 0x080B05A4
.L080B05A4:
	push {r4, lr}
	movs r4, #1
	bl sub_080B098C
	adds r1, r0, #0
	cmp r1, #0
	bne .L080B05BC
	ldr r0, .L080B05B8
	str r1, [r0]
	b .L080B060A
.L080B05B8: .4byte 0x0300452C @ IWRAM+0x452C
.L080B05BC:
	bl sub_080B04BC
	ldr r0, .L080B0610
	bl Flag_Test
	cmp r0, #0
	beq .L080B05DC
	movs r0, #0x81
	lsls r0, r0, #1
	bl Flag_Set
	movs r0, #0x83
	lsls r0, r0, #1
	bl Flag_Set
	movs r4, #4
.L080B05DC:
	ldr r3, .L080B0614
	movs r0, #0xd0
	movs r1, #0x30
	adds r2, r4, #0
	bl PalFade_FadeRangeInFromBlackTagged
	ldr r1, .L080B0618
	str r0, [r1]
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x10
	adds r2, r4, #0
	bl PalFade_FadeRangeInFromBlack
	ldr r0, .L080B061C
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B060A
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl PalFade_FadeRangeInFromBlack
.L080B060A:
	pop {r4}
	pop {r0}
	bx r0
.L080B0610: .4byte 0x00000105
.L080B0614: .4byte 0x00008001
.L080B0618: .4byte 0x0300452C @ IWRAM+0x452C
.L080B061C: .4byte 0x030029B0 @ IWRAM+0x29B0

	thumb_func_start sub_080B0620
sub_080B0620: @ 0x080B0620
.L080B0620:
	push {lr}
	bl sub_080B098C
	cmp r0, #1
	bne .L080B0638
	ldr r1, .L080B0634
	movs r0, #0
	str r0, [r1]
	b .L080B0666
	.byte 0x00, 0x00
.L080B0634: .4byte 0x0300452C @ IWRAM+0x452C
.L080B0638:
	ldr r3, .L080B066C
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #1
	bl PalFade_FadeRangeToBlackTagged
	ldr r1, .L080B0670
	str r0, [r1]
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	ldr r0, .L080B0674
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B0666
	movs r0, #0
	movs r1, #1
	movs r2, #1
	bl PalFade_FadeRangeToBlack
.L080B0666:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B066C: .4byte 0x00008001
.L080B0670: .4byte 0x0300452C @ IWRAM+0x452C
.L080B0674: .4byte 0x03002DB0 @ IWRAM+0x2DB0

	thumb_func_start sub_080B0678
sub_080B0678: @ 0x080B0678
.L080B0678:
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L080B06E8
	ldr r1, [r0]
	ldr r5, .L080B06EC
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
	ldr r0, .L080B06F0
	ldr r1, [r0]
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r5, r0
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r0, .L080B06F4
	ldr r1, [r0]
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #1
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	ldr r1, .L080B06F8
	str r0, [r1]
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080B06E8: .4byte 0x03004630 @ IWRAM+0x4630
.L080B06EC: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B06F0: .4byte 0x03004510 @ IWRAM+0x4510
.L080B06F4: .4byte 0x03003FC8 @ IWRAM+0x3FC8
.L080B06F8: .4byte 0x0300452C @ IWRAM+0x452C

	thumb_func_start sub_080B06FC
sub_080B06FC: @ 0x080B06FC
.L080B06FC:
	push {r4, r5, lr}
	sub sp, #4
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	ldr r1, .L080B0764
	str r0, [r1]
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #1
	bl PalFade_FadeRangeToBlack
	ldr r1, .L080B0768
	ldr r5, .L080B076C
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
	ldr r1, .L080B0770
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r5, r0
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080B0774
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B0764: .4byte 0x0300452C @ IWRAM+0x452C
.L080B0768: .4byte 0x0200F814 @ EWRAM+0xF814
.L080B076C: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B0770: .4byte 0x0200F7F4 @ EWRAM+0xF7F4
.L080B0774: .4byte 0x0200F854 @ EWRAM+0xF854

	thumb_func_start sub_080B0778
sub_080B0778: @ 0x080B0778
.L080B0778:
	push {r4, lr}
	movs r4, #1
	bl sub_080B098C
	adds r1, r0, #0
	cmp r1, #0
	bne .L080B0790
	ldr r0, .L080B078C
	str r1, [r0]
	b .L080B080C
.L080B078C: .4byte 0x0300452C @ IWRAM+0x452C
.L080B0790:
	ldr r0, .L080B07BC
	bl Flag_Test
	cmp r0, #0
	beq .L080B07AC
	movs r0, #0x81
	lsls r0, r0, #1
	bl Flag_Set
	movs r0, #0x83
	lsls r0, r0, #1
	bl Flag_Set
	movs r4, #4
.L080B07AC:
	ldr r0, .L080B07C0
	ldrh r0, [r0]
	cmp r0, #0xda
	bne .L080B07C8
	ldr r3, .L080B07C4
	movs r0, #0x70
	movs r1, #0x10
	b .L080B07CE
.L080B07BC: .4byte 0x00000105
.L080B07C0: .4byte 0x03004534 @ IWRAM+0x4534
.L080B07C4: .4byte 0x00008001
.L080B07C8:
	ldr r3, .L080B0814
	movs r0, #0x80
	movs r1, #0x80
.L080B07CE:
	adds r2, r4, #0
	bl PalFade_FadeRangeInFromBlackTagged
	ldr r1, .L080B0818
	str r0, [r1]
	ldr r4, .L080B081C
	adds r0, r4, #0
	bl Flag_Test
	cmp r0, #0
	beq .L080B07F2
	ldr r0, .L080B0818
	ldr r1, [r0]
	movs r0, #8
	strh r0, [r1, #2]
	adds r0, r4, #0
	bl Flag_Clear
.L080B07F2:
	movs r0, #0xfd
	bl Flag_Test
	cmp r0, #0
	beq .L080B080C
	ldr r0, .L080B0818
	ldr r1, [r0]
	movs r0, #0xa
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	movs r0, #0xfd
	bl Flag_Clear
.L080B080C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B0814: .4byte 0x00008001
.L080B0818: .4byte 0x0300452C @ IWRAM+0x452C
.L080B081C: .4byte 0x0000010D

	thumb_func_start sub_080B0820
sub_080B0820: @ 0x080B0820
.L080B0820:
	push {lr}
	bl sub_080B098C
	cmp r0, #1
	bne .L080B0838
	ldr r1, .L080B0834
	movs r0, #0
	str r0, [r1]
	b .L080B0878
	.byte 0x00, 0x00
.L080B0834: .4byte 0x0300452C @ IWRAM+0x452C
.L080B0838:
	ldr r0, .L080B0848
	ldrh r0, [r0]
	cmp r0, #0xda
	bne .L080B0850
	ldr r3, .L080B084C
	movs r0, #0x70
	movs r1, #0x10
	b .L080B0856
.L080B0848: .4byte 0x03004534 @ IWRAM+0x4534
.L080B084C: .4byte 0x00008001
.L080B0850:
	ldr r3, .L080B087C
	movs r0, #0x80
	movs r1, #0x80
.L080B0856:
	movs r2, #1
	bl PalFade_FadeRangeToBlackTagged
	ldr r1, .L080B0880
	str r0, [r1]
	movs r0, #0
	bl sub_080C3818
	ldr r0, .L080B0884
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B0878
	movs r0, #0
	movs r1, #1
	movs r2, #1
	bl PalFade_FadeRangeToBlack
.L080B0878:
	pop {r0}
	bx r0
.L080B087C: .4byte 0x00008001
.L080B0880: .4byte 0x0300452C @ IWRAM+0x452C
.L080B0884: .4byte 0x03002DB0 @ IWRAM+0x2DB0

	thumb_func_start sub_080B0888
sub_080B0888: @ 0x080B0888
.L080B0888:
	push {lr}
	ldr r0, .L080B08A8
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L080B08A4
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #1
	movs r3, #6
	bl PalFade_FadeRangeToBlackWithDuration
.L080B08A4:
	pop {r0}
	bx r0
.L080B08A8: .4byte 0x0200AB04 @ EWRAM+0xAB04

	thumb_func_start sub_080B08AC
sub_080B08AC: @ 0x080B08AC
.L080B08AC:
	push {r4, lr}
	sub sp, #4
	ldr r0, .L080B08E4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L080B0914
	ldr r4, .L080B08E8
	ldrh r0, [r4]
	bl sub_080C5F60
	adds r1, r0, #0
	ldrh r0, [r4]
	cmp r0, #0xda
	bne .L080B08F0
	ldr r2, .L080B08EC
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0x70
	movs r1, #0x10
	b .L080B0904
	.byte 0x00, 0x00
.L080B08E4: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080B08E8: .4byte 0x03004534 @ IWRAM+0x4534
.L080B08EC: .4byte 0x03002A90 @ IWRAM+0x2A90
.L080B08F0:
	ldr r2, .L080B0910
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	movs r0, #0x80
	movs r1, #0x80
.L080B0904:
	movs r2, #1
	movs r3, #0x10
	bl PalFade_FadeRangeWithDuration
	b .L080B0924
	.byte 0x00, 0x00
.L080B0910: .4byte 0x03002AB0 @ IWRAM+0x2AB0
.L080B0914:
	bl sub_080B04BC
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #1
	movs r3, #0x10
	bl PalFade_FadeRangeWithDuration
.L080B0924:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B092C
sub_080B092C: @ 0x080B092C
.L080B092C:
	push {r4, r5, lr}
	ldr r0, .L080B093C
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B0940
	movs r0, #0
	b .L080B0970
	.byte 0x00, 0x00
.L080B093C: .4byte 0x0300452C @ IWRAM+0x452C
.L080B0940:
	bl PalFade_IsActive
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L080B096E
	ldr r5, .L080B0978
	adds r0, r5, #0
	bl Flag_Test
	cmp r0, #0
	beq .L080B096E
	movs r0, #0x81
	lsls r0, r0, #1
	bl Flag_Clear
	movs r0, #0x83
	lsls r0, r0, #1
	bl Flag_Clear
	adds r0, r5, #0
	bl Flag_Clear
.L080B096E:
	adds r0, r4, #0
.L080B0970:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B0978: .4byte 0x00000105

	thumb_func_start sub_080B097C
sub_080B097C: @ 0x080B097C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080B092C
	strh r0, [r4, #0x1e]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B098C
sub_080B098C: @ 0x080B098C
.L080B098C:
	push {lr}
	ldr r2, .L080B099C
	movs r1, #0
.L080B0992:
	ldrb r0, [r2]
	cmp r0, #0
	beq .L080B09A0
	movs r0, #0
	b .L080B09AE
.L080B099C: .4byte 0x03002F50 @ IWRAM+0x2F50
.L080B09A0:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r2, #1
	cmp r1, #0x1f
	bls .L080B0992
	movs r0, #1
.L080B09AE:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B09B4
sub_080B09B4: @ 0x080B09B4
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080B098C
	strh r0, [r4, #0x1e]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B09C4
sub_080B09C4: @ 0x080B09C4
.L080B09C4:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl sub_080B3078
	cmp r0, #1
	bne .L080B09F0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #6
	bl sub_080B3078
	cmp r0, #0
	bne .L080B0A02
	bl sub_080B0678
	b .L080B0A02
.L080B09F0:
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #6
	bl sub_080B3078
	cmp r0, #1
	bne .L080B0A02
	bl sub_080B06FC
.L080B0A02:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080B0A08
sub_080B0A08: @ 0x080B0A08
.L080B0A08:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	bl sub_080B092C
	cmp r0, #0
	bne .L080B0A6A
	ldr r4, .L080B0A40
	strh r0, [r4, #0x2e]
	ldr r0, .L080B0A44
	movs r1, #1
	strh r1, [r0]
	movs r0, #2
	movs r1, #2
	movs r2, #0
	bl sub_080AF8D0
	cmp r0, #0
	bne .L080B0A4E
	adds r0, r4, #0
	adds r0, #0x46
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B0A48
	movs r0, #1
	bl Field_SetState
	b .L080B0A4E
.L080B0A40: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0A44: .4byte 0x03003FF4 @ IWRAM+0x3FF4
.L080B0A48:
	movs r0, #1
	bl sub_080B03BC
.L080B0A4E:
	ldr r2, .L080B0A70
	adds r0, r2, #0
	adds r0, #0x46
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080B0A74
	strh r1, [r0]
	cmp r5, #1
	bne .L080B0A6A
	ldrh r0, [r2, #0x12]
	ldrh r1, [r2, #0x14]
	ldrh r2, [r2, #2]
	bl sub_080AF5B8
.L080B0A6A:
	pop {r4, r5}
	pop {r0}
	bx r0
.L080B0A70: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0A74: .4byte 0x03003FF4 @ IWRAM+0x3FF4

	thumb_func_start sub_080B0A78
sub_080B0A78: @ 0x080B0A78
	ldr r2, .L080B0AAC
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r2, .L080B0AB0
	ldrh r1, [r2]
	movs r0, #0xff
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r3, .L080B0AB4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, .L080B0AB8
	ldrh r0, [r1]
	movs r2, #0x40
	orrs r0, r2
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080B0AAC: .4byte 0x04000200 @ REG_IE
.L080B0AB0: .4byte 0x04000004 @ REG_DISPSTAT
.L080B0AB4: .4byte 0x00006724
.L080B0AB8: .4byte 0x0400000C @ REG_BG2CNT

	thumb_func_start sub_080B0ABC
sub_080B0ABC: @ 0x080B0ABC
	ldr r3, .L080B0AD4
	ldrh r2, [r3]
	ldr r1, .L080B0AD8
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r2, .L080B0ADC
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	bx lr
	.byte 0x00, 0x00
.L080B0AD4: .4byte 0x0400000C @ REG_BG2CNT
.L080B0AD8: .4byte 0x0000FFBF
.L080B0ADC: .4byte 0x0400000E @ REG_BG3CNT

	thumb_func_start sub_080B0AE0
sub_080B0AE0: @ 0x080B0AE0
.L080B0AE0:
	push {lr}
	ldr r0, .L080B0AF4
	ldr r1, .L080B0AF8
	str r1, [r0, #8]
	ldr r0, .L080B0AFC
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	pop {r0}
	bx r0
.L080B0AF4: .4byte 0x030020F0 @ IWRAM+0x20F0
.L080B0AF8: .4byte sub_080B0ABC
.L080B0AFC: .4byte sub_080B0A78

	thumb_func_start sub_080B0B00
sub_080B0B00: @ 0x080B0B00
	ldr r2, .L080B0B30
	ldrh r1, [r2]
	ldr r0, .L080B0B34
	ands r0, r1
	strh r0, [r2]
	ldr r2, .L080B0B38
	ldrh r1, [r2]
	ldr r0, .L080B0B3C
	ands r0, r1
	strh r0, [r2]
	ldr r3, .L080B0B40
	ldrh r2, [r3]
	ldr r1, .L080B0B44
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r2, .L080B0B48
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	ldr r1, .L080B0B4C
	ldr r0, .L080B0B50
	str r0, [r1, #8]
	bx lr
.L080B0B30: .4byte 0x04000200 @ REG_IE
.L080B0B34: .4byte 0x0000FFFB
.L080B0B38: .4byte 0x04000004 @ REG_DISPSTAT
.L080B0B3C: .4byte 0x0000FFDB
.L080B0B40: .4byte 0x0400000C @ REG_BG2CNT
.L080B0B44: .4byte 0x0000FFBF
.L080B0B48: .4byte 0x0400000E @ REG_BG3CNT
.L080B0B4C: .4byte 0x030020F0 @ IWRAM+0x20F0
.L080B0B50: .4byte IntrDummy

	thumb_func_start sub_080B0B54
sub_080B0B54: @ 0x080B0B54
.L080B0B54:
	push {lr}
	ldr r0, .L080B0B64
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B0B64: .4byte sub_080B0B00

	thumb_func_start sub_080B0B68
sub_080B0B68: @ 0x080B0B68
	ldr r2, .L080B0B80
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	ldr r2, .L080B0B84
	ldrh r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080B0B80: .4byte 0x04000200 @ REG_IE
.L080B0B84: .4byte 0x04000004 @ REG_DISPSTAT

	thumb_func_start sub_080B0B88
sub_080B0B88: @ 0x080B0B88
	ldr r2, .L080B0BA4
	ldrh r1, [r2]
	ldr r0, .L080B0BA8
	ands r0, r1
	strh r0, [r2]
	ldr r2, .L080B0BAC
	ldrh r1, [r2]
	ldr r0, .L080B0BB0
	ands r0, r1
	strh r0, [r2]
	ldr r1, .L080B0BB4
	ldr r0, .L080B0BB8
	str r0, [r1, #4]
	bx lr
.L080B0BA4: .4byte 0x04000200 @ REG_IE
.L080B0BA8: .4byte 0x0000FFFD
.L080B0BAC: .4byte 0x04000004 @ REG_DISPSTAT
.L080B0BB0: .4byte 0x0000FFEF
.L080B0BB4: .4byte 0x030020F0 @ IWRAM+0x20F0
.L080B0BB8: .4byte IntrDummy

	thumb_func_start sub_080B0BBC
sub_080B0BBC: @ 0x080B0BBC
	push {r4, r5, r6, lr}
	ldr r0, .L080B0C10
	ldrb r1, [r0]
	adds r5, r1, #0
	cmp r1, #0x63
	bhi .L080B0C24
	ldr r6, .L080B0C14
	ldr r0, .L080B0C18
	adds r4, r0, #0
	adds r4, #0x52
	ldrh r0, [r4]
	adds r0, r0, r1
	movs r3, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge .L080B0BE6
	adds r0, #3
.L080B0BE6:
	asrs r0, r0, #2
	movs r2, #3
	ands r0, r2
	ldr r1, .L080B0C1C
	strh r0, [r1]
	ldrh r0, [r4]
	adds r0, r0, r5
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge .L080B0C04
	adds r0, #3
.L080B0C04:
	asrs r0, r0, #2
	ands r0, r2
	ldr r1, .L080B0C20
	strh r0, [r1]
	b .L080B0C2E
	.byte 0x00, 0x00
.L080B0C10: .4byte 0x04000006 @ REG_VCOUNT
.L080B0C14: .4byte gSineTable
.L080B0C18: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0C1C: .4byte 0x0400001A @ REG_BG2VOFS
.L080B0C20: .4byte 0x0400001E @ REG_BG3VOFS
.L080B0C24:
	ldr r0, .L080B0C34
	movs r1, #0
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
.L080B0C2E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080B0C34: .4byte 0x0400001A @ REG_BG2VOFS

	thumb_func_start sub_080B0C38
sub_080B0C38: @ 0x080B0C38
.L080B0C38:
	push {lr}
	ldr r1, .L080B0C68
	ldr r0, .L080B0C6C
	str r0, [r1, #4]
	ldr r0, .L080B0C70
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne .L080B0C5A
	ldr r0, .L080B0C74
	adds r0, #0x52
	ldrh r1, [r0]
	adds r1, #1
	movs r2, #0xff
	ands r1, r2
	strh r1, [r0]
.L080B0C5A:
	ldr r0, .L080B0C78
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B0C68: .4byte 0x030020F0 @ IWRAM+0x20F0
.L080B0C6C: .4byte sub_080B0BBC
.L080B0C70: .4byte 0x030031BC @ IWRAM+0x31BC
.L080B0C74: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0C78: .4byte sub_080B0B68

	thumb_func_start sub_080B0C7C
sub_080B0C7C: @ 0x080B0C7C
.L080B0C7C:
	push {lr}
	ldr r0, .L080B0C8C
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B0C8C: .4byte sub_080B0B88

	thumb_func_start sub_080B0C90
sub_080B0C90: @ 0x080B0C90
.L080B0C90:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r1, .L080B0CD0
	ldr r0, .L080B0CD4
	ldrh r0, [r0]
	ldrh r2, [r1, #0x38]
	strh r0, [r1, #0x38]
	ldr r0, .L080B0CD8
	ldrh r0, [r0]
	ldrh r2, [r1, #0x3a]
	strh r0, [r1, #0x3a]
	ldr r0, .L080B0CDC
	ldrh r0, [r0]
	ldrh r2, [r1, #0x3c]
	strh r0, [r1, #0x3c]
	ldr r2, .L080B0CE0
	ldr r0, [r2]
	cmp r0, #0
	beq .L080B0CEC
	ldr r0, .L080B0CE4
	ldrh r0, [r0]
	ldr r1, .L080B0CE8
	ldrh r1, [r1]
	bl sub_080AD824
	bl .L080B1A0A
	.byte 0x00, 0x00
.L080B0CD0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0CD4: .4byte 0x030031D0 @ IWRAM+0x31D0
.L080B0CD8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080B0CDC: .4byte 0x03003964 @ IWRAM+0x3964
.L080B0CE0: .4byte 0x03003FF8 @ IWRAM+0x3FF8
.L080B0CE4: .4byte 0x03004614 @ IWRAM+0x4614
.L080B0CE8: .4byte 0x03004514 @ IWRAM+0x4514
.L080B0CEC:
	ldr r0, .L080B0D20
	ldr r1, [r0]
	cmp r1, #0
	blt .L080B0D38
	ldr r0, .L080B0D24
	ldrh r0, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080C8B10
	ldr r1, .L080B0D28
	ldr r2, .L080B0D2C
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0xe8
	muls r1, r2, r1
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L080B0D30
	bl _call_via_r0
	b .L080B0D38
.L080B0D20: .4byte 0x03004514 @ IWRAM+0x4514
.L080B0D24: .4byte 0x03004614 @ IWRAM+0x4614
.L080B0D28: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B0D2C: .4byte 0x00000A38
.L080B0D30:
	movs r0, #0x84
	lsls r0, r0, #1
	bl Flag_Clear
.L080B0D38:
	movs r0, #0x81
	lsls r0, r0, #1
	bl Flag_Test
	adds r4, r0, #0
	cmp r4, #0
	beq .L080B0DBC
	ldr r3, .L080B0D84
	adds r1, r3, #0
	adds r1, #0x48
	ldrh r0, [r1]
	cmp r0, #0
	bne .L080B0D56
	movs r0, #1
	strh r0, [r1]
.L080B0D56:
	ldrh r4, [r1]
	cmp r4, #1
	bne .L080B0DAC
	ldr r0, .L080B0D88
	ldr r2, [r0]
	movs r0, #0xf
	ands r2, r0
	cmp r2, #0
	bne .L080B0DA2
	adds r3, #0x4a
	ldrh r0, [r3]
	cmp r0, #0
	bne .L080B0D90
	ldr r1, .L080B0D8C
	ldrb r0, [r1]
	adds r0, #0x10
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls .L080B0DA2
	strh r4, [r3]
	b .L080B0DA2
.L080B0D84: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0D88: .4byte 0x030031BC @ IWRAM+0x31BC
.L080B0D8C: .4byte 0x0300003C @ IWRAM+0x3C
.L080B0D90:
	ldr r1, .L080B0DA8
	ldrb r0, [r1]
	subs r0, #0x10
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne .L080B0DA2
	strh r2, [r3]
.L080B0DA2:
	bl sub_080B0AE0
	b .L080B0DCE
.L080B0DA8: .4byte 0x0300003C @ IWRAM+0x3C
.L080B0DAC:
	ldr r0, .L080B0DB8
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	b .L080B0DCE
	.byte 0x00, 0x00
.L080B0DB8: .4byte sub_080B0ABC
.L080B0DBC:
	ldr r0, .L080B0E1C
	adds r5, r0, #0
	adds r5, #0x48
	ldrh r0, [r5]
	cmp r0, #0
	beq .L080B0DCE
	bl sub_080B0B54
	strh r4, [r5]
.L080B0DCE:
	movs r0, #0x83
	lsls r0, r0, #1
	bl Flag_Test
	adds r1, r0, #0
	cmp r1, #0
	beq .L080B0E40
	ldr r3, .L080B0E1C
	adds r1, r3, #0
	adds r1, #0x4c
	ldrh r0, [r1]
	cmp r0, #0
	bne .L080B0DEC
	movs r0, #1
	strh r0, [r1]
.L080B0DEC:
	ldrh r4, [r1]
	cmp r4, #1
	bne .L080B0E46
	ldr r0, .L080B0E20
	ldr r2, [r0]
	movs r0, #0xf
	ands r2, r0
	cmp r2, #0
	bne .L080B0E46
	adds r3, #0x4e
	ldrh r0, [r3]
	cmp r0, #0
	bne .L080B0E28
	ldr r1, .L080B0E24
	ldrb r0, [r1]
	adds r0, #0x10
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls .L080B0E46
	strh r4, [r3]
	b .L080B0E46
	.byte 0x00, 0x00
.L080B0E1C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0E20: .4byte 0x030031BC @ IWRAM+0x31BC
.L080B0E24: .4byte 0x0300003D @ IWRAM+0x3D
.L080B0E28:
	ldr r1, .L080B0E3C
	ldrb r0, [r1]
	subs r0, #0x10
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne .L080B0E46
	strh r2, [r3]
	b .L080B0E46
.L080B0E3C: .4byte 0x0300003D @ IWRAM+0x3D
.L080B0E40:
	ldr r0, .L080B0E70
	adds r0, #0x4c
	strh r1, [r0]
.L080B0E46:
	movs r0, #0x84
	lsls r0, r0, #1
	bl Flag_Test
	adds r4, r0, #0
	cmp r4, #0
	beq .L080B0E7A
	ldr r0, .L080B0E70
	adds r1, r0, #0
	adds r1, #0x50
	ldrh r0, [r1]
	cmp r0, #0
	bne .L080B0E64
	movs r0, #1
	strh r0, [r1]
.L080B0E64:
	ldrh r0, [r1]
	cmp r0, #1
	bne .L080B0E74
	bl sub_080B0C38
	b .L080B0E8C
.L080B0E70: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0E74:
	bl sub_080B0C7C
	b .L080B0E8C
.L080B0E7A:
	ldr r0, .L080B0EA8
	adds r5, r0, #0
	adds r5, #0x50
	ldrh r0, [r5]
	cmp r0, #0
	beq .L080B0E8C
	bl sub_080B0C7C
	strh r4, [r5]
.L080B0E8C:
	ldr r1, .L080B0EA8
	ldrh r0, [r1]
	subs r0, #1
	adds r5, r1, #0
	cmp r0, #0x24
	bls .L080B0E9C
	bl .L080B1A06
.L080B0E9C:
	lsls r0, r0, #2
	ldr r1, .L080B0EAC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080B0EA8: .4byte 0x03004550 @ IWRAM+0x4550
.L080B0EAC: .4byte gUnknown_080B0EB0
	.global gUnknown_080B0EB0
gUnknown_080B0EB0:
.L080B0EB0: @ jump table
	.4byte .L080B0F44
	.4byte .L080B0F94
	.4byte .L080B1A06
	.4byte .L080B1078
	.4byte .L080B1082
	.4byte .L080B1124
	.4byte .L080B1242
	.4byte .L080B1254
	.4byte .L080B1A06
	.4byte .L080B1A06
	.4byte .L080B1354
	.4byte .L080B1420
	.4byte .L080B1426
	.4byte .L080B14EC
	.4byte .L080B1644
	.4byte .L080B1680
	.4byte .L080B1686
	.4byte .L080B16E0
	.4byte .L080B1712
	.4byte .L080B1798
	.4byte .L080B1A06
	.4byte .L080B17C0
	.4byte .L080B1A06
	.4byte .L080B18D0
	.4byte .L080B1A06
	.4byte .L080B1A06
	.4byte .L080B1930
	.4byte .L080B196C
	.4byte .L080B1984
	.4byte .L080B1984
	.4byte .L080B19D0
	.4byte .L080B1A06
	.4byte .L080B1426
	.4byte .L080B14EC
	.4byte .L080B1A06
	.4byte .L080B1A06
	.4byte .L080B1910
.L080B0F44:
	ldrh r0, [r5, #0x34]
	cmp r0, #1
	bne .L080B0F8A
	ldrh r0, [r5, #0x36]
	adds r1, r0, #0
	cmp r1, #0
	beq .L080B0F7C
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, .L080B0F78
	lsls r2, r0, #1
	ldrh r1, [r5, #2]
	lsls r1, r1, #3
	adds r2, r2, r1
	adds r2, r2, r3
	ldrh r1, [r2]
	movs r2, #0
	strh r2, [r5, #0x36]
	bl sub_080B2064
	movs r0, #6
	bl Field_SetState
	bl .L080B1A0A
.L080B0F78: .4byte gUnknown_08163258
.L080B0F7C:
	ldrh r0, [r5, #0x3a]
	strh r1, [r5, #0x3a]
	ldrh r0, [r5, #0x38]
	movs r0, #0x40
	strh r0, [r5, #0x38]
	ldrh r0, [r5, #0x3c]
	strh r1, [r5, #0x3c]
.L080B0F8A:
	ldrh r0, [r5, #0x38]
	bl sub_080B1C18
	bl .L080B1A06
.L080B0F94:
	ldrh r2, [r5, #0x1e]
	subs r0, r2, #1
	strh r0, [r5, #0x1e]
	ldrh r1, [r5, #0xa]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r1, r1, #1
	cmp r0, r1
	bne .L080B0FD8
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	beq .L080B0FAE
	b .L080B10C4
.L080B0FAE:
	ldr r0, .L080B0FD0
	bl sub_080AE494
	movs r0, #0
	bl sub_080B0204
	cmp r0, #1
	beq .L080B0FC2
	bl .L080B1A06
.L080B0FC2:
	ldr r1, .L080B0FD4
	movs r0, #0
	bl sub_080B09C4
	bl .L080B1A06
	.byte 0x00, 0x00
.L080B0FD0: .4byte sub_080B018C
.L080B0FD4: .4byte 0x0000FFFF
.L080B0FD8:
	ldrh r2, [r5, #0x1e]
	subs r0, r1, #1
	cmp r2, r0
	bne .L080B0FFA
	movs r0, #0
	bl sub_080B0204
	cmp r0, #1
	bne .L080B0FF2
	ldrh r0, [r5, #2]
	bl sub_080B02A0
	b .L080B16AC
.L080B0FF2:
	movs r0, #0x69
	bl sub_080C51D4
	b .L080B16AC
.L080B0FFA:
	adds r1, r2, #0
	cmp r1, #0
	bne .L080B100E
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	beq .L080B10B4
	adds r0, r2, #1
	strh r0, [r5, #0x1e]
	bl .L080B1A06
.L080B100E:
	ldr r0, .L080B1048
	cmp r1, r0
	beq .L080B1018
	bl .L080B1A06
.L080B1018:
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080B1028
	bl .L080B19F8
.L080B1028:
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl sub_080AF8D0
	cmp r0, #0
	bne .L080B1066
	adds r0, r5, #0
	adds r0, #0x46
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B104C
	movs r0, #1
	bl Field_SetState
	b .L080B1052
.L080B1048: .4byte 0x0000FFFF
.L080B104C:
	movs r0, #1
	bl sub_080B03BC
.L080B1052:
	ldr r0, .L080B106C
	ldrh r0, [r0]
	ldr r1, .L080B1070
	ldrh r1, [r1]
	bl sub_080AD608
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C5170
.L080B1066:
	ldr r0, .L080B1074
	adds r0, #0x46
	b .L080B1116
.L080B106C: .4byte 0x03004614 @ IWRAM+0x4614
.L080B1070: .4byte 0x03004514 @ IWRAM+0x4514
.L080B1074: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1078:
	movs r0, #1
	bl sub_080B0A08
	bl .L080B1A06
.L080B1082:
	ldrh r2, [r5, #0x1e]
	subs r0, r2, #1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #6
	bne .L080B10A4
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	bne .L080B10C4
	movs r1, #8
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq .L080B10A2
	bl .L080B1A06
.L080B10A2:
	b .L080B169A
.L080B10A4:
	cmp r1, #5
	bne .L080B10AA
	b .L080B16AC
.L080B10AA:
	cmp r1, #0
	bne .L080B10CA
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	bne .L080B10C4
.L080B10B4:
	ldr r0, .L080B10C0
	bl sub_080AE494
	bl .L080B1A06
	.byte 0x00, 0x00
.L080B10C0: .4byte sub_080B0158
.L080B10C4:
	strh r2, [r5, #0x1e]
	bl .L080B1A06
.L080B10CA:
	ldr r0, .L080B1108
	cmp r1, r0
	beq .L080B10D4
	bl .L080B1A06
.L080B10D4:
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080B10E4
	bl .L080B19F8
.L080B10E4:
	movs r0, #1
	movs r1, #2
	movs r2, #1
	bl sub_080AF8D0
	cmp r0, #0
	beq .L080B10F6
	bl .L080B1A06
.L080B10F6:
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B110C
	movs r0, #1
	bl Field_SetState
	b .L080B1112
.L080B1108: .4byte 0x0000FFFF
.L080B110C:
	movs r0, #1
	bl sub_080B03BC
.L080B1112:
	ldr r0, .L080B1120
	adds r0, #0x44
.L080B1116:
	movs r1, #0
	strh r1, [r0]
	bl .L080B1A06
	.byte 0x00, 0x00
.L080B1120: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1124:
	bl sub_080B2090
	adds r6, r0, #0
	cmp r6, #1
	beq .L080B1130
	b .L080B1230
.L080B1130:
	movs r0, #0
	movs r1, #0
	bl sub_080B2EFC
	adds r7, r0, #0
	movs r1, #0x1d
	bl sub_080B3038
	adds r5, r0, #0
	ldr r2, .L080B1180
	mov r8, r2
	ldrh r0, [r2, #0x12]
	ldrh r1, [r2, #0x14]
	ldrh r2, [r2, #2]
	add r3, sp, #4
	bl sub_080C9084
	adds r4, r0, #0
	movs r3, #0
	mov sb, r3
	mov sl, r3
	cmp r5, #0
	beq .L080B1184
	mov r0, r8
	ldrh r1, [r0, #2]
	lsls r1, r1, #2
	adds r0, r5, #4
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	adds r0, r7, #0
	movs r1, #0x1a
	bl sub_080B3038
	cmp r0, #0
	beq .L080B11F4
	ldrh r0, [r0, #2]
	bl sub_080B011C
	b .L080B11F4
.L080B1180: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1184:
	cmp r4, #0
	beq .L080B11F4
	add r0, sp, #4
	ldrh r1, [r0]
	ldr r0, .L080B11BC
	cmp r1, r0
	beq .L080B11F4
	add r0, sp, #4
	ldrh r0, [r0]
	bl sub_080C2480
	cmp r0, #1
	beq .L080B11F4
	ldr r1, [r4, #4]
	ldr r0, .L080B11C0
	cmp r1, r0
	bne .L080B11C4
	bl sub_080C9100
	mov sl, r0
	cmp r0, #0
	beq .L080B11F4
	adds r1, r4, #0
	bl sub_080AF85C
	mov sb, r0
	b .L080B11F4
	.byte 0x00, 0x00
.L080B11BC: .4byte 0x0000FFFF
.L080B11C0: .4byte gUnknown_08073A00
.L080B11C4:
	adds r0, r1, #0
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B11F4
	ldr r1, [r4, #4]
	mov sb, r1
	add r0, sp, #4
	ldrh r0, [r0]
	bl sub_080C24B8
	mov r2, r8
	strh r6, [r2, #0x3e]
	ldr r0, [r4, #4]
	bl ScriptVM_RunAlt
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L080B11F4
	ldr r0, .L080B1210
	bl Flag_Set
.L080B11F4:
	mov r3, sb
	cmp r3, #0
	beq .L080B1214
	mov r0, sl
	cmp r0, #0
	beq .L080B1204
	bl .L080B1A06
.L080B1204:
	movs r0, #0xc
	mov r1, sb
	bl sub_080AF178
	bl .L080B1A06
.L080B1210: .4byte 0x0000010B
.L080B1214:
	movs r0, #1
	bl Field_SetState
	bl sub_080BE76C
	cmp r0, #1
	beq .L080B1226
	bl .L080B1A06
.L080B1226:
	movs r0, #0x1a
	bl Field_SetState
	bl .L080B1A06
.L080B1230:
	cmp r6, #7
	beq .L080B1238
	bl .L080B1A06
.L080B1238:
	movs r0, #7
	bl Field_SetState
	bl .L080B1A06
.L080B1242:
	ldrh r0, [r5, #6]
	ldrh r1, [r5, #8]
	bl sub_080B2064
	movs r0, #6
	bl Field_SetState
	bl .L080B1A06
.L080B1254:
	ldrh r1, [r5, #0x1e]
	subs r0, r1, #1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #6
	bne .L080B12D0
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	beq .L080B126A
	b .L080B16DC
.L080B126A:
	ldr r0, .L080B1294
	bl sub_080AE494
	movs r1, #8
	ldrsh r0, [r5, r1]
	cmp r0, #1
	bne .L080B12A0
	ldr r2, .L080B1298
	ldr r1, .L080B129C
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	movs r0, #1
	bl sub_080B0204
	cmp r0, #1
	beq .L080B1290
	b .L080B1A06
.L080B1290:
	movs r0, #1
	b .L080B12BA
.L080B1294: .4byte sub_080B0158
.L080B1298: .4byte 0x0300000C @ IWRAM+0xC
.L080B129C: .4byte 0x03004540 @ IWRAM+0x4540
.L080B12A0:
	ldr r2, .L080B12C4
	ldr r1, .L080B12C8
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	movs r0, #3
	bl sub_080B0204
	cmp r0, #1
	beq .L080B12B8
	b .L080B1A06
.L080B12B8:
	ldr r0, .L080B12CC
.L080B12BA:
	movs r1, #0
	bl sub_080B09C4
	b .L080B1A06
	.byte 0x00, 0x00
.L080B12C4: .4byte 0x0300000C @ IWRAM+0xC
.L080B12C8: .4byte 0x03004540 @ IWRAM+0x4540
.L080B12CC: .4byte 0x0000FFFF
.L080B12D0:
	cmp r4, #5
	bne .L080B1308
	movs r2, #8
	ldrsh r0, [r5, r2]
	cmp r0, #1
	bne .L080B12EE
	movs r0, #1
	bl sub_080B0204
	cmp r0, #1
	beq .L080B12F8
	movs r0, #0x69
	bl sub_080C51D4
	b .L080B16AC
.L080B12EE:
	movs r0, #3
	bl sub_080B0204
	cmp r0, #1
	bne .L080B1300
.L080B12F8:
	ldrh r0, [r5, #6]
	bl sub_080B02A0
	b .L080B16AC
.L080B1300:
	movs r0, #0x69
	bl sub_080C51D4
	b .L080B16AC
.L080B1308:
	cmp r4, #0
	bne .L080B1328
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	beq .L080B1314
	b .L080B16DC
.L080B1314:
	ldr r0, .L080B1320
	bl sub_080AE494
	ldr r0, .L080B1324
	strh r4, [r0]
	b .L080B1A06
.L080B1320: .4byte sub_080B0158
.L080B1324: .4byte 0x0300000C @ IWRAM+0xC
.L080B1328:
	ldr r0, .L080B1350
	cmp r4, r0
	beq .L080B1330
	b .L080B1A06
.L080B1330:
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080B133E
	b .L080B19F8
.L080B133E:
	movs r0, #1
	movs r1, #2
	movs r2, #1
	bl sub_080AF8D0
	cmp r0, #0
	beq .L080B134E
	b .L080B1A06
.L080B134E:
	b .L080B16F6
.L080B1350: .4byte 0x0000FFFF
.L080B1354:
	movs r0, #0xae
	bl Flag_Test
	cmp r0, #0
	beq .L080B1394
	movs r0, #0x5e
	bl Flag_Test
	cmp r0, #0
	beq .L080B1370
	ldr r1, .L080B136C
	b .L080B1386
.L080B136C: .4byte gUnknown_0804C354
.L080B1370:
	movs r0, #0x5f
	bl Flag_Test
	cmp r0, #0
	beq .L080B1384
	ldr r1, .L080B1380
	b .L080B1386
	.byte 0x00, 0x00
.L080B1380: .4byte gUnknown_0804C564
.L080B1384:
	ldr r1, .L080B1390
.L080B1386:
	movs r0, #0xc
	bl sub_080AF178
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1390: .4byte gUnknown_0804CB9C
.L080B1394:
	ldr r0, .L080B13C8
	ldr r4, [r0]
	movs r0, #0
	bl sub_080C2230
	movs r0, #4
	ldrsb r0, [r4, r0]
	movs r1, #6
	ldrsb r1, [r4, r1]
	movs r2, #0
	bl sub_080C2CD8
	ldr r0, .L080B13CC
	ldrh r3, [r0, #0x12]
	ldrh r1, [r0, #0x14]
	movs r2, #0x3f
	ands r2, r1
	ldrh r0, [r0, #2]
	cmp r0, #1
	beq .L080B13DE
	cmp r0, #1
	bgt .L080B13D0
	cmp r0, #0
	beq .L080B13DA
	b .L080B13F0
	.byte 0x00, 0x00
.L080B13C8: .4byte 0x03004000 @ IWRAM+0x4000
.L080B13CC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B13D0:
	cmp r0, #2
	beq .L080B13E2
	cmp r0, #3
	beq .L080B13EA
	b .L080B13F0
.L080B13DA:
	adds r0, r2, #1
	b .L080B13E4
.L080B13DE:
	subs r0, r3, #1
	b .L080B13EC
.L080B13E2:
	subs r0, r2, #1
.L080B13E4:
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	b .L080B13F0
.L080B13EA:
	adds r0, r3, #1
.L080B13EC:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L080B13F0:
	mov r4, sp
	adds r4, #6
	add r5, sp, #8
	adds r0, r3, #0
	adds r1, r2, #0
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080C1F50
	ldrh r0, [r4]
	ldrh r1, [r5]
	bl sub_0815341C
	ldr r2, .L080B141C
	movs r3, #0xc6
	lsls r3, r3, #5
	adds r2, r2, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	b .L080B1A06
.L080B141C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B1420:
	bl sub_080B38A8
	b .L080B1A06
.L080B1426:
	ldr r4, .L080B1464
	ldrh r0, [r4]
	cmp r0, #0x97
	bne .L080B143E
	movs r0, #0x11
	bl Flag_Test
	cmp r0, #0
	beq .L080B143E
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
.L080B143E:
	bl sub_080B38A8
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, r5
	bne .L080B1474
	ldr r5, .L080B1468
	ldrh r0, [r5]
	cmp r0, #0
	bne .L080B1454
	b .L080B1A06
.L080B1454:
	ldr r4, .L080B146C
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r1, .L080B1470
	ldr r0, [r1]
	adds r0, #1
	b .L080B1528
	.byte 0x00, 0x00
.L080B1464: .4byte 0x03004534 @ IWRAM+0x4534
.L080B1468: .4byte 0x0300460C @ IWRAM+0x460C
.L080B146C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1470: .4byte 0x03004514 @ IWRAM+0x4514
.L080B1474:
	cmp r0, #1
	beq .L080B147A
	b .L080B1A06
.L080B147A:
	ldr r0, .L080B1498
	ldr r1, [r0]
	cmp r1, #0
	bne .L080B14A4
	ldr r2, .L080B149C
	ldrh r0, [r2, #0x34]
	cmp r0, #0
	beq .L080B148C
	b .L080B1590
.L080B148C:
	ldrh r0, [r2]
	ldr r1, .L080B14A0
	bl sub_080AF178
	b .L080B1594
	.byte 0x00, 0x00
.L080B1498: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080B149C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B14A0: .4byte gUnknown_08124DBC
.L080B14A4:
	ldr r0, .L080B14D0
	ldr r0, [r0]
	cmp r0, #0
	beq .L080B14AE
	b .L080B1628
.L080B14AE:
	bl sub_080B0820
	movs r0, #0x6e
	bl sub_080C51D4
	ldr r4, .L080B14D4
	ldrh r0, [r4]
	cmp r0, #0xd
	bne .L080B14DC
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	ldr r1, .L080B14D8
	movs r0, #2
	strh r0, [r1]
	b .L080B15C8
	.byte 0x00, 0x00
.L080B14D0: .4byte 0x030031CC @ IWRAM+0x31CC
.L080B14D4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B14D8: .4byte 0x0300460C @ IWRAM+0x460C
.L080B14DC:
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	ldr r1, .L080B14E8
	movs r0, #0x1c
	b .L080B15F2
.L080B14E8: .4byte 0x0300460C @ IWRAM+0x460C
.L080B14EC:
	ldr r4, .L080B154C
	ldrh r0, [r4]
	cmp r0, #0x98
	bne .L080B1504
	movs r0, #0x11
	bl Flag_Test
	cmp r0, #0
	beq .L080B1504
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
.L080B1504:
	bl sub_080B38A8
	adds r5, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L080B1564
	ldr r5, .L080B1550
	ldrh r0, [r5]
	cmp r0, #0
	bne .L080B151C
	b .L080B1A06
.L080B151C:
	ldr r4, .L080B1554
	movs r0, #0
	strh r0, [r4, #0x1e]
	ldr r1, .L080B1558
	ldr r0, [r1]
	subs r0, #1
.L080B1528:
	str r0, [r1]
	ldrh r0, [r4, #2]
	bl sub_080B1A1C
	strh r0, [r4, #2]
	bl sub_080AE234
	bl sub_080AE294
	ldr r0, .L080B155C
	ldrh r0, [r0]
	ldrh r1, [r5]
	ldr r2, .L080B1560
	ldrh r2, [r2]
	bl sub_080B31C4
	b .L080B1A06
	.byte 0x00, 0x00
.L080B154C: .4byte 0x03004534 @ IWRAM+0x4534
.L080B1550: .4byte 0x0300460C @ IWRAM+0x460C
.L080B1554: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1558: .4byte 0x03004514 @ IWRAM+0x4514
.L080B155C: .4byte 0x03004614 @ IWRAM+0x4614
.L080B1560: .4byte 0x03003BA8 @ IWRAM+0x3BA8
.L080B1564:
	cmp r5, #1
	beq .L080B156A
	b .L080B1A06
.L080B156A:
	ldr r0, .L080B1584
	ldr r1, [r0]
	cmp r1, #0
	bne .L080B15A4
	ldr r2, .L080B1588
	ldrh r0, [r2, #0x34]
	cmp r0, #0
	bne .L080B1590
	ldrh r0, [r2]
	ldr r1, .L080B158C
	bl sub_080AF178
	b .L080B1594
.L080B1584: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080B1588: .4byte 0x03004550 @ IWRAM+0x4550
.L080B158C: .4byte gUnknown_08124DD8
.L080B1590:
	ldr r0, .L080B159C
	str r1, [r0]
.L080B1594:
	ldr r1, .L080B15A0
	movs r0, #1
	str r0, [r1]
	b .L080B1A06
.L080B159C: .4byte 0x030031CC @ IWRAM+0x31CC
.L080B15A0: .4byte 0x03003B98 @ IWRAM+0x3B98
.L080B15A4:
	ldr r0, .L080B15D4
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B1628
	bl sub_080B0820
	movs r0, #0x6e
	bl sub_080C51D4
	ldr r4, .L080B15D8
	ldrh r0, [r4]
	cmp r0, #0xe
	bne .L080B15E8
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	ldr r0, .L080B15DC
	strh r5, [r0]
.L080B15C8:
	ldr r1, .L080B15E0
	ldr r0, .L080B15E4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	strh r0, [r1]
	b .L080B1A06
.L080B15D4: .4byte 0x030031CC @ IWRAM+0x31CC
.L080B15D8: .4byte 0x03004550 @ IWRAM+0x4550
.L080B15DC: .4byte 0x0300460C @ IWRAM+0x460C
.L080B15E0: .4byte 0x03003BA8 @ IWRAM+0x3BA8
.L080B15E4: .4byte 0x03004000 @ IWRAM+0x4000
.L080B15E8:
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	ldr r1, .L080B1614
	movs r0, #0x1b
.L080B15F2:
	strh r0, [r1]
	ldr r2, .L080B1618
	ldr r0, .L080B161C
	ldr r1, [r0]
	ldrh r0, [r1, #6]
	strh r0, [r2]
	ldr r2, .L080B1620
	ldrh r0, [r1, #4]
	str r0, [r2]
	ldr r0, .L080B1624
	str r5, [r0]
	ldrh r0, [r1, #8]
	bl sub_080B1A1C
	strh r0, [r4, #2]
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1614: .4byte 0x0300460C @ IWRAM+0x460C
.L080B1618: .4byte 0x03003BA8 @ IWRAM+0x3BA8
.L080B161C: .4byte 0x03004000 @ IWRAM+0x4000
.L080B1620: .4byte 0x03004614 @ IWRAM+0x4614
.L080B1624: .4byte 0x03004514 @ IWRAM+0x4514
.L080B1628:
	bl sub_080B0820
	ldr r1, .L080B163C
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	movs r2, #0
	strh r0, [r1, #0x1e]
	ldr r0, .L080B1640
	strh r2, [r0]
	b .L080B1A06
.L080B163C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1640: .4byte 0x0300460C @ IWRAM+0x460C
.L080B1644:
	bl sub_080B092C
	cmp r0, #0
	beq .L080B164E
	b .L080B1A06
.L080B164E:
	bl sub_080AE234
	ldr r0, .L080B1670
	ldrh r0, [r0]
	ldr r1, .L080B1674
	ldrh r1, [r1]
	ldr r2, .L080B1678
	ldrh r2, [r2]
	bl sub_080B31C4
	ldr r1, .L080B167C
	ldrh r0, [r1, #0xa]
	ldrh r1, [r1, #2]
	movs r2, #3
	bl sub_080B2030
	b .L080B1A06
.L080B1670: .4byte 0x03004614 @ IWRAM+0x4614
.L080B1674: .4byte 0x0300460C @ IWRAM+0x460C
.L080B1678: .4byte 0x03003BA8 @ IWRAM+0x3BA8
.L080B167C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1680:
	bl sub_080B4C48
	b .L080B1A06
.L080B1686:
	ldrh r1, [r5, #0x1e]
	subs r0, r1, #1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bne .L080B16A8
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	bne .L080B16DC
.L080B169A:
	ldr r0, .L080B16A4
	bl sub_080AE494
	b .L080B1A06
	.byte 0x00, 0x00
.L080B16A4: .4byte sub_080B018C
.L080B16A8:
	cmp r0, #3
	bne .L080B16B8
.L080B16AC:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	b .L080B1A06
.L080B16B8:
	cmp r0, #0
	beq .L080B16BE
	b .L080B1A06
.L080B16BE:
	ldrh r4, [r5, #0xe]
	cmp r4, #0
	bne .L080B16DC
	ldr r0, .L080B16D8
	bl sub_080AE494
	bl sub_080B05A4
	strh r4, [r5, #0x2e]
	movs r0, #0x12
	bl Field_SetState
	b .L080B1A06
.L080B16D8: .4byte sub_080B0158
.L080B16DC:
	strh r1, [r5, #0x1e]
	b .L080B1A06
.L080B16E0:
	bl sub_080B092C
	adds r1, r0, #0
	cmp r1, #0
	beq .L080B16EC
	b .L080B1A06
.L080B16EC:
	ldr r0, .L080B1700
	strh r1, [r0, #0x2e]
	ldrh r0, [r0, #0x32]
	cmp r0, #0
	bne .L080B1704
.L080B16F6:
	movs r0, #1
	bl sub_080B03BC
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1700: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1704:
	movs r0, #4
	bl sub_08128B84
	movs r0, #0xa
	bl Field_SetState
	b .L080B1A06
.L080B1712:
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl sub_080B3078
	cmp r0, #1
	bne .L080B1738
	ldr r1, .L080B1734
	movs r0, #0
	str r0, [r1]
	bl sub_080E4554
	movs r0, #0x15
	bl Field_SetState
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1734: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B1738:
	ldr r4, .L080B176C
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne .L080B1778
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #4
	movs r3, #4
	bl PalFade_FadeRangeToBlackWithDuration
	ldr r1, .L080B1770
	str r0, [r1]
	ldr r0, .L080B1774
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B1764
	movs r0, #0
	movs r1, #1
	movs r2, #4
	movs r3, #4
	bl PalFade_FadeRangeToBlackWithDuration
.L080B1764:
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	b .L080B17B4
.L080B176C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1770: .4byte 0x0300452C @ IWRAM+0x452C
.L080B1774: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080B1778:
	bl sub_080B092C
	adds r1, r0, #0
	cmp r1, #0
	bne .L080B17B4
	ldr r0, .L080B1794
	str r1, [r0]
	bl sub_080E4554
	movs r0, #0x15
	bl Field_SetState
	b .L080B17B4
	.byte 0x00, 0x00
.L080B1794: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B1798:
	ldr r1, .L080B17BC
	movs r0, #1
	str r0, [r1]
	bl sub_080E4554
	bl sub_080B0888
	movs r0, #0x15
	bl Field_SetState
	bl sub_080C7218
	bl sub_080C7414
.L080B17B4:
	movs r0, #1
	bl sub_080C51BC
	b .L080B1A06
.L080B17BC: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B17C0:
	ldr r0, .L080B17F0
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B18A6
	ldr r0, .L080B17F4
	ldrh r1, [r5, #2]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r4, [r1]
	adds r6, r4, #0
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl sub_080B3078
	cmp r0, #1
	bne .L080B17F8
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B189E
	adds r0, r4, #0
	b .L080B1896
.L080B17F0: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B17F4: .4byte gUnknown_0815F31C
.L080B17F8:
	ldrh r0, [r5, #0x1e]
	cmp r0, #0
	bne .L080B1880
	ldr r0, .L080B186C
	ldr r1, [r0]
	ldr r6, .L080B1870
	ldrh r0, [r1]
	strh r0, [r6]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r4, #0x20
	str r4, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r0, .L080B1874
	ldr r1, [r0]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r2, r6, r3
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r0, .L080B1878
	ldr r1, [r0]
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #1
	movs r3, #0x10
	bl PalFade_FadeRangeWithDuration
	ldr r1, .L080B187C
	str r0, [r1]
	ldrh r0, [r6]
	cmp r0, #0
	bne .L080B185C
	b .L080B19F8
.L080B185C:
	movs r0, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0x10
	bl PalFade_FadeRangeWithDuration
	b .L080B19F8
	.byte 0x00, 0x00
.L080B186C: .4byte 0x03004630 @ IWRAM+0x4630
.L080B1870: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B1874: .4byte 0x03004510 @ IWRAM+0x4510
.L080B1878: .4byte 0x03003FC8 @ IWRAM+0x3FC8
.L080B187C: .4byte 0x0300452C @ IWRAM+0x452C
.L080B1880:
	bl sub_080B092C
	cmp r0, #0
	beq .L080B188A
	b .L080B1A06
.L080B188A:
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080B189E
	adds r0, r6, #0
.L080B1896:
	movs r1, #1
	bl sub_080B1A4C
	b .L080B1A06
.L080B189E:
	movs r0, #1
	bl Field_SetState
	b .L080B1A06
.L080B18A6:
	ldrh r0, [r5, #0x1e]
	cmp r0, #0
	bne .L080B18C4
	ldr r1, .L080B18BC
	movs r0, #1
	strh r0, [r1, #0x34]
	bl PalFade_FadeToBlack
	ldr r1, .L080B18C0
	str r0, [r1]
	b .L080B19F8
.L080B18BC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080B18C0: .4byte 0x0300452C @ IWRAM+0x452C
.L080B18C4:
	bl sub_080B092C
	cmp r0, #0
	beq .L080B18CE
	b .L080B1A06
.L080B18CE:
	b .L080B19AE
.L080B18D0:
	bl sub_080B38A8
	adds r1, r0, #0
	cmp r1, #1
	beq .L080B18DC
	b .L080B1A06
.L080B18DC:
	ldr r4, .L080B1908
	ldrh r0, [r4, #0x3a]
	adds r5, r0, #0
	ands r5, r1
	cmp r5, #0
	beq .L080B18EA
	b .L080B1A06
.L080B18EA:
	ldrh r1, [r4, #0x3a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L080B18F6
	b .L080B1A06
.L080B18F6:
	bl sub_080B0820
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	ldr r0, .L080B190C
	strh r5, [r0]
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1908: .4byte 0x03004550 @ IWRAM+0x4550
.L080B190C: .4byte 0x0300460C @ IWRAM+0x460C
.L080B1910:
	ldrh r0, [r5, #0x1e]
	cmp r0, #0
	beq .L080B1918
	b .L080B1A06
.L080B1918:
	ldr r0, .L080B1928
	ldr r0, [r0]
	ldr r1, .L080B192C
	bl Task_Create
	movs r0, #1
	strh r0, [r5, #0x1e]
	b .L080B1A06
.L080B1928: .4byte 0x03004628 @ IWRAM+0x4628
.L080B192C: .4byte 0x0000FFFF
.L080B1930:
	ldrh r0, [r5, #0x1e]
	cmp r0, #0
	bne .L080B1A06
	ldr r0, .L080B1948
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B194C
	movs r0, #0
	bl sub_08128B84
	b .L080B195C
	.byte 0x00, 0x00
.L080B1948: .4byte 0x03004628 @ IWRAM+0x4628
.L080B194C:
	cmp r0, #1
	bne .L080B1958
	movs r0, #0
	bl sub_0812D0FC
	b .L080B195C
.L080B1958:
	bl sub_0812A730
.L080B195C:
	ldr r1, .L080B1968
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	strh r0, [r1, #0x1e]
	b .L080B1A06
	.byte 0x00, 0x00
.L080B1968: .4byte 0x03004550 @ IWRAM+0x4550
.L080B196C:
	ldr r1, .L080B1980
	movs r0, #1
	str r0, [r1]
	bl sub_080AF280
	bl sub_080C7218
	bl sub_080C7414
	b .L080B1A06
.L080B1980: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B1984:
	ldrh r0, [r5, #0x1e]
	cmp r0, #0
	bne .L080B19A4
	ldr r1, .L080B199C
	movs r0, #1
	strh r0, [r1, #0x34]
	bl PalFade_FadeToBlack
	ldr r1, .L080B19A0
	str r0, [r1]
	b .L080B19F8
	.byte 0x00, 0x00
.L080B199C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080B19A0: .4byte 0x0300452C @ IWRAM+0x452C
.L080B19A4:
	bl sub_080B092C
	cmp r0, #0
	bne .L080B1A06
	ldrh r0, [r5]
.L080B19AE:
	ldr r0, .L080B19C8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, .L080B19CC
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #1
	bl sub_080C2CD8
	b .L080B1A06
	.byte 0x00, 0x00
.L080B19C8: .4byte 0x03003FC4 @ IWRAM+0x3FC4
.L080B19CC: .4byte 0x03004618 @ IWRAM+0x4618
.L080B19D0:
	adds r4, r5, #0
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne .L080B19F0
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	bne .L080B1A06
	ldr r0, .L080B19EC
	bl sub_080AE494
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	b .L080B1A06
.L080B19EC: .4byte sub_080B0158
.L080B19F0:
	cmp r0, #1
	bne .L080B1A00
	bl sub_080B05A4
.L080B19F8:
	ldrh r0, [r5, #0x1e]
	adds r0, #1
	strh r0, [r5, #0x1e]
	b .L080B1A06
.L080B1A00:
	movs r0, #0
	bl sub_080B0A08
.L080B1A06:
	bl sub_080B2CC0
.L080B1A0A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B1A1C
sub_080B1A1C: @ 0x080B1A1C
.L080B1A1C:
	lsls r0, r0, #0x10
	ldr r1, .L080B1A2C
	lsrs r0, r0, #0xd
	adds r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L080B1A2C: .4byte gUnknown_0815F2FC

	thumb_func_start sub_080B1A30
sub_080B1A30: @ 0x080B1A30
.L080B1A30:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, .L080B1A48
	strh r0, [r2, #0xa]
	movs r2, #3
	bl sub_080B2030
	pop {r0}
	bx r0
.L080B1A48: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B1A4C
sub_080B1A4C: @ 0x080B1A4C
.L080B1A4C:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r0, #2
	bl sub_080B0204
	adds r5, r0, #0
	cmp r5, #1
	bne .L080B1A88
	movs r0, #0
	movs r1, #1
	bl sub_080B09C4
	adds r0, r6, #0
	bl sub_080B02A0
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	ldr r0, .L080B1A84
	movs r1, #0
	strh r5, [r0, #8]
	strh r1, [r0, #0x3e]
	b .L080B1AB4
.L080B1A84: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1A88:
	cmp r4, #1
	bne .L080B1AA4
	ldr r0, .L080B1A9C
	ldr r1, .L080B1AA0
	bl Task_Create
	movs r0, #0x1a
	bl Field_SetState
	b .L080B1AC8
.L080B1A9C: .4byte gUnknown_08165380
.L080B1AA0: .4byte 0x0000FFFF
.L080B1AA4:
	ldr r4, .L080B1AD0
	movs r0, #0
	strh r0, [r4, #8]
	movs r0, #0x69
	bl sub_080C51D4
	movs r0, #1
	strh r0, [r4, #0x3e]
.L080B1AB4:
	ldr r1, .L080B1AD0
	movs r0, #0xc
	strh r0, [r1, #0x1e]
	strh r6, [r1, #6]
	ldr r4, .L080B1AD4
	ldrh r5, [r4]
	movs r0, #5
	bl Field_SetState
	strh r5, [r4]
.L080B1AC8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B1AD0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1AD4: .4byte 0x03003FF4 @ IWRAM+0x3FF4

	thumb_func_start sub_080B1AD8
sub_080B1AD8: @ 0x080B1AD8
.L080B1AD8:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r7, r4, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	mov r8, r5
	ldr r0, .L080B1B0C
	mov sb, r0
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	adds r6, r0, #0
	cmp r6, #3
	bne .L080B1B10
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080B1A30
	b .L080B1B32
	.byte 0x00, 0x00
.L080B1B0C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1B10:
	cmp r6, #2
	bne .L080B1B24
	mov r0, sb
	strh r4, [r0, #0xa]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl sub_080B2030
	b .L080B1B32
.L080B1B24:
	mov r0, sb
	strh r7, [r0, #0xa]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #2
	bl sub_080B2030
.L080B1B32:
	cmp r6, #1
	beq .L080B1B44
	ldr r1, .L080B1B40
	movs r0, #0
	strh r0, [r1, #0x3e]
	b .L080B1B48
	.byte 0x00, 0x00
.L080B1B40: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1B44:
	ldr r0, .L080B1B54
	strh r6, [r0, #0x3e]
.L080B1B48:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B1B54: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B1B58
sub_080B1B58: @ 0x080B1B58
.L080B1B58:
	push {lr}
	ldr r0, .L080B1BB4
	ldrh r0, [r0]
	bl sub_080C8AF8
	cmp r0, #1
	bne .L080B1B6E
	ldr r0, .L080B1BB8
	ldrh r0, [r0, #4]
	cmp r0, #0
	bne .L080B1BBC
.L080B1B6E:
	ldr r0, .L080B1BB4
	ldrh r0, [r0]
	bl sub_080C8AF8
	cmp r0, #1
	bne .L080B1B82
	ldr r0, .L080B1BB8
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B1BBC
.L080B1B82:
	ldr r0, .L080B1BB4
	ldrh r0, [r0]
	bl sub_080C8AF8
	cmp r0, #1
	bne .L080B1B96
	ldr r0, .L080B1BB8
	ldrh r0, [r0, #6]
	cmp r0, #0
	bne .L080B1BBC
.L080B1B96:
	bl sub_080B78A4
	cmp r0, #0
	bne .L080B1BBC
	bl sub_080B098C
	cmp r0, #1
	beq .L080B1BBC
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B1BBC
	movs r0, #1
	b .L080B1BBE
.L080B1BB4: .4byte 0x03004614 @ IWRAM+0x4614
.L080B1BB8: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080B1BBC:
	movs r0, #0
.L080B1BBE:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B1BC4
sub_080B1BC4: @ 0x080B1BC4
.L080B1BC4:
	push {lr}
	movs r0, #0xa
	bl Field_SetState
	ldr r1, .L080B1BD8
	movs r0, #0
	str r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B1BD8: .4byte 0x03003BB8 @ IWRAM+0x3BB8

	thumb_func_start sub_080B1BDC
sub_080B1BDC: @ 0x080B1BDC
.L080B1BDC:
	push {lr}
	bl sub_080B953C
	cmp r0, #1
	bne .L080B1C08
	movs r0, #0
	bl sub_080AD6E4
	ldr r0, .L080B1C04
	movs r1, #0
	strh r1, [r0, #0x1e]
	movs r1, #0x22
	strh r1, [r0, #0x2e]
	bl sub_080C7218
	bl sub_080C6FF0
	bl sub_080C7414
	b .L080B1C14
.L080B1C04: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1C08:
	bl sub_080F3190
	cmp r0, #0
	beq .L080B1C14
	bl sub_0812A730
.L080B1C14:
	pop {r0}
	bx r0

	thumb_func_start sub_080B1C18
sub_080B1C18: @ 0x080B1C18
.L080B1C18:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r1, sp
	strh r0, [r1]
	ldr r0, .L080B1C84
	mov r8, r0
	ldr r5, .L080B1C88
	ldrh r7, [r5, #2]
	movs r2, #0
	mov sb, r2
	mov sl, r2
	ldrh r0, [r5, #0x12]
	ldrh r1, [r5, #0x14]
	bl sub_080AF4EC
	ldr r0, [r5, #0x40]
	cmp r0, #0
	bne .L080B1C8C
	ldrh r0, [r5, #0x3e]
	cmp r0, #0
	bne .L080B1C8C
	ldrh r0, [r5, #0x12]
	ldrh r1, [r5, #0x14]
	ldrh r2, [r5, #2]
	mov r4, sp
	adds r4, #2
	adds r3, r4, #0
	bl sub_080C9084
	adds r6, r0, #0
	cmp r6, #0
	beq .L080B1C8C
	ldrh r0, [r4]
	cmp r0, r8
	beq .L080B1C8C
	bl sub_080C2480
	cmp r0, #1
	bne .L080B1C8C
	ldr r0, [r6, #4]
	bl sub_080AF0AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080B1C8C
	bl sub_080B828C
	str r0, [r5, #0x40]
	b .L080B1FFC
	.byte 0x00, 0x00
.L080B1C84: .4byte 0x0000FFFF
.L080B1C88: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1C8C:
	bl sub_080B1B58
	adds r1, r0, #0
	cmp r1, #1
	bne .L080B1D88
	ldr r2, .L080B1CC8
	ldrh r0, [r2, #0x3a]
	adds r4, r0, #0
	ands r4, r1
	cmp r4, #0
	beq .L080B1CE6
	ldr r0, [r2, #0x40]
	cmp r0, #0
	beq .L080B1CCC
	ldrh r0, [r0, #0x1e]
	cmp r0, #0
	bne .L080B1CB0
	b .L080B1FFC
.L080B1CB0:
	ldrh r0, [r2, #0x12]
	ldrh r1, [r2, #0x14]
	ldrh r2, [r2, #2]
	add r3, sp, #4
	bl sub_080C9084
	adds r1, r0, #0
	movs r2, #0
	bl sub_080AF7E8
	b .L080B1FFC
	.byte 0x00, 0x00
.L080B1CC8: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1CCC:
	movs r0, #0xae
	bl Flag_Test
	cmp r0, #0
	beq .L080B1CD8
	b .L080B1FFC
.L080B1CD8:
	movs r0, #0
	bl sub_08128B84
	movs r0, #0xa
	bl Field_SetState
	b .L080B1FFC
.L080B1CE6:
	ldrh r1, [r2, #0x3a]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080B1D54
	bl sub_080B9568
	cmp r0, #1
	bne .L080B1D54
	movs r0, #0x67
	bl sub_080C51D4
	movs r0, #0
	bl sub_0812D0FC
	movs r0, #0xa
	bl Field_SetState
	ldr r0, .L080B1D48
	str r4, [r0]
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl sub_080B3078
	cmp r0, #1
	bne .L080B1D1E
	b .L080B1FFC
.L080B1D1E:
	movs r0, #0xd0
	movs r1, #0x30
	movs r2, #4
	movs r3, #4
	bl PalFade_FadeRangeToBlackWithDuration
	ldr r1, .L080B1D4C
	str r0, [r1]
	ldr r0, .L080B1D50
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B1D38
	b .L080B1FFC
.L080B1D38:
	movs r0, #0
	movs r1, #1
	movs r2, #4
	movs r3, #4
	bl PalFade_FadeRangeToBlackWithDuration
	b .L080B1FFC
	.byte 0x00, 0x00
.L080B1D48: .4byte 0x03003BB8 @ IWRAM+0x3BB8
.L080B1D4C: .4byte 0x0300452C @ IWRAM+0x452C
.L080B1D50: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080B1D54:
	ldr r0, .L080B1D84
	ldrh r1, [r0, #0x3a]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080B1D88
	bl sub_0812A730
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080B1D6E
	b .L080B1FFC
.L080B1D6E:
	bl sub_080F3190
	cmp r0, #0
	bne .L080B1D7C
	movs r0, #0x65
	bl sub_080C51D4
.L080B1D7C:
	bl sub_080B1BC4
	b .L080B1FFC
	.byte 0x00, 0x00
.L080B1D84: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1D88:
	bl sub_080F3F44
	movs r1, #0x80
	lsls r1, r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L080B1DA4
	ldr r4, .L080B1DD8
	ldr r0, [r4, #0x58]
	cmp r0, #0
	bne .L080B1DA4
	bl sub_080C57B4
	str r0, [r4, #0x58]
.L080B1DA4:
	bl sub_080B1B58
	cmp r0, #1
	beq .L080B1DAE
	b .L080B1EEA
.L080B1DAE:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080B1E60
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080B1DE0
	ldr r1, .L080B1DDC
	lsls r0, r7, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r8, r0
	movs r0, #1
	mov sb, r0
	b .L080B1EEA
	.byte 0x00, 0x00
.L080B1DD8: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1DDC: .4byte gUnknown_0815F324
.L080B1DE0:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080B1E04
	ldr r0, .L080B1E00
	lsls r1, r7, #2
	adds r0, #2
	adds r1, r1, r0
	ldrh r1, [r1]
	mov r8, r1
	movs r2, #2
	mov sb, r2
	b .L080B1EEA
	.byte 0x00, 0x00
.L080B1E00: .4byte gUnknown_0815F324
.L080B1E04:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080B1E24
	ldr r1, .L080B1E20
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r8, r0
	movs r0, #1
	mov sl, r0
	b .L080B1EEA
.L080B1E20: .4byte gUnknown_0815F31C
.L080B1E24:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080B1E4C
	ldr r1, .L080B1E44
	lsls r0, r7, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r8, r0
	ldr r1, .L080B1E48
	movs r0, #8
	strh r0, [r1, #0xa]
	b .L080B1EEA
	.byte 0x00, 0x00
.L080B1E44: .4byte gUnknown_0815F2FC
.L080B1E48: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1E4C:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080B1EEA
	bl sub_080B1BDC
	b .L080B1EEA
.L080B1E60:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080B1E78
	ldr r0, .L080B1E74
	lsls r1, r7, #3
	adds r0, #6
	b .L080B1EA2
.L080B1E74: .4byte gUnknown_0815F2FC
.L080B1E78:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080B1E90
	ldr r0, .L080B1E8C
	lsls r1, r7, #3
	adds r0, #4
	b .L080B1EA2
.L080B1E8C: .4byte gUnknown_0815F2FC
.L080B1E90:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080B1EB0
	ldr r0, .L080B1EAC
	lsls r1, r7, #3
	adds r0, #2
.L080B1EA2:
	adds r1, r1, r0
	ldrh r1, [r1]
	mov r8, r1
	b .L080B1EEA
	.byte 0x00, 0x00
.L080B1EAC: .4byte gUnknown_0815F2FC
.L080B1EB0:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080B1ED8
	ldr r1, .L080B1ED0
	lsls r0, r7, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r8, r0
	ldr r1, .L080B1ED4
	movs r0, #0xc
	strh r0, [r1, #0xa]
	b .L080B1EEA
	.byte 0x00, 0x00
.L080B1ED0: .4byte gUnknown_0815F2FC
.L080B1ED4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1ED8:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080B1EEA
	bl sub_080B1BDC
.L080B1EEA:
	ldr r2, .L080B1F2C
	cmp r8, r2
	bne .L080B1EF2
	b .L080B1FFC
.L080B1EF2:
	mov r0, sb
	cmp r0, #0
	beq .L080B1F88
	ldr r5, .L080B1F30
	movs r4, #0
	movs r0, #0xc
	strh r0, [r5, #0x1e]
	mov r2, sb
	strh r2, [r5, #8]
	mov r0, r8
	strh r0, [r5, #6]
	movs r0, #8
	bl Field_SetState
	strh r4, [r5, #0x3e]
	movs r2, #8
	ldrsh r4, [r5, r2]
	cmp r4, #1
	bne .L080B1F54
	movs r0, #1
	bl sub_080B0204
	cmp r0, #1
	bne .L080B1F3C
	ldr r1, .L080B1F34
	ldr r2, .L080B1F38
	adds r0, r2, #0
	b .L080B1F62
	.byte 0x00, 0x00
.L080B1F2C: .4byte 0x0000FFFF
.L080B1F30: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1F34: .4byte 0x03004540 @ IWRAM+0x4540
.L080B1F38: .4byte 0x0000FFF0
.L080B1F3C:
	ldr r1, .L080B1F4C
	ldr r2, .L080B1F50
	adds r0, r2, #0
	strh r0, [r1]
	strh r4, [r5, #0x3e]
	adds r0, r1, #0
	b .L080B1F76
	.byte 0x00, 0x00
.L080B1F4C: .4byte 0x03004540 @ IWRAM+0x4540
.L080B1F50: .4byte 0x0000FFF8
.L080B1F54:
	movs r0, #3
	bl sub_080B0204
	cmp r0, #1
	bne .L080B1F6C
	ldr r1, .L080B1F68
	movs r0, #0x10
.L080B1F62:
	strh r0, [r1]
	adds r0, r1, #0
	b .L080B1F76
.L080B1F68: .4byte 0x03004540 @ IWRAM+0x4540
.L080B1F6C:
	ldr r0, .L080B1F84
	movs r1, #8
	strh r1, [r0]
	movs r1, #1
	strh r1, [r5, #0x3e]
.L080B1F76:
	ldrh r1, [r0]
	movs r0, #3
	movs r2, #0
	bl sub_080B2840
	b .L080B1FFC
	.byte 0x00, 0x00
.L080B1F84: .4byte 0x03004540 @ IWRAM+0x4540
.L080B1F88:
	mov r0, sl
	cmp r0, #1
	bne .L080B1F98
	mov r0, r8
	movs r1, #0
	bl sub_080B1A4C
	b .L080B1FFC
.L080B1F98:
	ldr r1, .L080B1FB4
	ldrh r0, [r1, #2]
	cmp r8, r0
	beq .L080B1FF4
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080B1FB8
	movs r2, #1
	mov sb, r2
	b .L080B1FD8
	.byte 0x00, 0x00
.L080B1FB4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1FB8:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080B1FC8
	mov sb, r2
	b .L080B1FD8
.L080B1FC8:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080B1FD8
	movs r0, #1
	mov sb, r0
.L080B1FD8:
	mov r0, r8
	mov r1, sb
	bl sub_080B2064
	movs r0, #6
	bl Field_SetState
	ldr r1, .L080B1FF0
	movs r0, #0
	strh r0, [r1, #0x3e]
	b .L080B1FFC
	.byte 0x00, 0x00
.L080B1FF0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B1FF4:
	ldrh r0, [r1, #0xa]
	ldrh r1, [r1, #2]
	bl sub_080B1AD8
.L080B1FFC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080B200C
sub_080B200C: @ 0x080B200C
.L080B200C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080B2020
	ldrh r2, [r1, #2]
	cmp r0, r2
	bne .L080B2024
	movs r0, #1
	b .L080B202A
	.byte 0x00, 0x00
.L080B2020: .4byte 0x03004550 @ IWRAM+0x4550
.L080B2024:
	strh r2, [r1, #4]
	strh r0, [r1, #2]
	movs r0, #0
.L080B202A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B2030
sub_080B2030: @ 0x080B2030
.L080B2030:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	ldr r0, .L080B2060
	strh r4, [r0, #0x1e]
	strh r5, [r0, #6]
	adds r0, r6, #0
	bl Field_SetState
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080B2060: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B2064
sub_080B2064: @ 0x080B2064
.L080B2064:
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	ldr r0, .L080B208C
	movs r1, #0x10
	strh r1, [r0, #0x1e]
	strh r4, [r0, #8]
	strh r5, [r0, #6]
	pop {r4, r5}
	pop {r0}
	bx r0
.L080B208C: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B2090
sub_080B2090: @ 0x080B2090
.L080B2090:
	push {r4, r5, lr}
	ldr r4, .L080B20B4
	ldrh r1, [r4, #0x1e]
	subs r0, r1, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bne .L080B20BC
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	bne .L080B2100
	ldr r0, .L080B20B8
	bl sub_080AE494
	movs r0, #0x22
	strh r0, [r4, #0x2e]
	b .L080B2102
.L080B20B4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B20B8: .4byte sub_080B01C8
.L080B20BC:
	cmp r0, #7
	bne .L080B20DA
	ldrh r0, [r4, #8]
	ldrh r4, [r4, #2]
	adds r0, r0, r4
	movs r1, #3
	ands r0, r1
	bl sub_080B200C
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	b .L080B2102
.L080B20DA:
	cmp r0, #0
	bne .L080B2102
	ldrh r5, [r4, #0xe]
	cmp r5, #0
	bne .L080B2100
	ldr r0, .L080B20F8
	bl sub_080AE494
	strh r5, [r4, #0x2e]
	ldrh r0, [r4, #2]
	ldrh r4, [r4, #6]
	cmp r0, r4
	bne .L080B20FC
	movs r0, #1
	b .L080B2106
.L080B20F8: .4byte sub_080B0158
.L080B20FC:
	movs r0, #7
	b .L080B2106
.L080B2100:
	strh r1, [r4, #0x1e]
.L080B2102:
	movs r0, #1
	rsbs r0, r0, #0
.L080B2106:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080B210C
sub_080B210C: @ 0x080B210C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	ldrh r1, [r0, #8]
	str r1, [sp]
	ldrh r2, [r0, #0xa]
	str r2, [sp, #4]
	ldrh r3, [r0, #0xc]
	str r3, [sp, #8]
	ldrh r5, [r0, #0xe]
	str r5, [sp, #0xc]
	ldrh r1, [r0, #0x10]
	mov sl, r1
	ldrh r2, [r0, #0x12]
	str r2, [sp, #0x10]
	ldrh r3, [r0, #0x14]
	str r3, [sp, #0x14]
	ldr r1, [r0]
	ldr r1, [r1]
	str r1, [sp, #0x18]
	ldr r0, [r0, #4]
	str r0, [sp, #0x1c]
	ldr r1, .L080B2194
	movs r0, #1
	str r0, [r1]
	ldr r0, .L080B2198
	ldr r0, [r0]
	cmp r0, #0x4a
	bne .L080B2154
	ldr r0, .L080B219C
	ldr r0, [r0]
	cmp r0, #4
	beq .L080B21FC
.L080B2154:
	ldr r0, .L080B21A0
	ldrh r0, [r0, #0x28]
	ldr r5, [sp, #8]
	adds r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bne .L080B21B8
	ldr r1, [sp, #8]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt .L080B21A4
	movs r0, #8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	ldr r2, [sp]
	adds r1, r2, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	mov r3, sl
	subs r0, r3, r0
	b .L080B21F6
	.byte 0x00, 0x00
.L080B2194: .4byte 0x030045F4 @ IWRAM+0x45F4
.L080B2198: .4byte 0x03004614 @ IWRAM+0x4614
.L080B219C: .4byte 0x03004514 @ IWRAM+0x4514
.L080B21A0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B21A4:
	ldr r0, [sp, #8]
	add r0, sl
	cmp r0, #0xe8
	ble .L080B21FC
	subs r0, #0xe8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r5, sl
	subs r0, r5, r0
	b .L080B21F6
.L080B21B8:
	ldr r0, [sp, #8]
	mov r2, sl
	subs r1, r0, r2
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt .L080B21D2
	movs r0, #8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r0, r2, r0
	b .L080B21F6
.L080B21D2:
	ldr r3, [sp, #8]
	cmp r3, #0xe8
	bls .L080B21FC
	adds r0, r3, #0
	subs r0, #0xe8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r3, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	ldr r5, [sp]
	adds r1, r5, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	mov r1, sl
	subs r0, r1, r0
.L080B21F6:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
.L080B21FC:
	mov r2, sl
	lsls r0, r2, #0x10
	cmp r0, #0
	bgt .L080B2206
	b .L080B23B8
.L080B2206:
	movs r0, #0
	ldr r3, [sp, #0x10]
	cmp r0, r3
	blo .L080B2210
	b .L080B23B2
.L080B2210:
	ldr r7, [sp]
	ldr r4, [sp, #8]
	movs r5, #0
	mov sb, r5
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #0x28]
	ldr r2, [sp, #0xc]
	adds r2, #1
	str r2, [sp, #0x2c]
	adds r0, #1
	str r0, [sp, #0x30]
	cmp sb, sl
	blo .L080B222E
	b .L080B2394
.L080B222E:
	ldr r3, [sp, #4]
	lsrs r0, r3, #3
	lsls r0, r0, #0xa
	ldr r5, [sp, #0x18]
	adds r0, r5, r0
	str r0, [sp, #0x20]
	ldr r1, [sp, #0xc]
	lsrs r0, r1, #3
	lsls r0, r0, #0xa
	str r0, [sp, #0x24]
.L080B2242:
	adds r0, r4, #0
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne .L080B22D8
	lsls r1, r7, #0xd
	lsrs r1, r1, #0x10
	lsls r1, r1, #5
	movs r3, #7
	mov r8, r3
	ldr r2, [sp, #4]
	ands r2, r3
	lsls r2, r2, #2
	adds r0, r7, #0
	ands r0, r3
	lsrs r0, r0, #1
	ldr r5, [sp, #0x20]
	adds r1, r5, r1
	adds r1, r1, r2
	adds r1, r1, r0
	ldrb r6, [r1]
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x24]
	adds r0, r0, r1
	mov ip, r0
	lsls r1, r4, #0xd
	lsrs r1, r1, #0x10
	lsls r1, r1, #5
	add r1, ip
	ldr r0, [sp, #0xc]
	ands r0, r3
	lsls r5, r0, #2
	adds r1, r1, r5
	adds r0, r4, #0
	ands r0, r3
	lsrs r0, r0, #1
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r3, #0xf
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	bne .L080B22A4
	adds r0, r6, #0
	ands r0, r3
	orrs r2, r0
	movs r3, #1
	ldr r0, .L080B22D4
	str r3, [r0]
.L080B22A4:
	strb r2, [r1]
	ldr r1, [sp, #0x14]
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsrs r0, r0, #0x13
	lsls r0, r0, #5
	add r0, ip
	adds r0, r0, r5
	adds r1, r4, #0
	mov r2, r8
	ands r1, r2
	lsrs r1, r1, #1
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r3, #0xf0
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	bne .L080B2364
	ands r6, r3
	orrs r2, r6
	b .L080B235E
	.byte 0x00, 0x00
.L080B22D4: .4byte 0x030045F4 @ IWRAM+0x45F4
.L080B22D8:
	lsls r1, r7, #0xd
	lsrs r1, r1, #0x10
	lsls r1, r1, #5
	movs r0, #7
	mov r8, r0
	ldr r2, [sp, #4]
	ands r2, r0
	lsls r2, r2, #2
	adds r0, r7, #0
	mov r3, r8
	ands r0, r3
	lsrs r0, r0, #1
	ldr r5, [sp, #0x20]
	adds r1, r5, r1
	adds r1, r1, r2
	adds r1, r1, r0
	ldrb r6, [r1]
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x24]
	adds r0, r0, r1
	mov ip, r0
	lsls r1, r4, #0xd
	lsrs r1, r1, #0x10
	lsls r1, r1, #5
	add r1, ip
	ldr r0, [sp, #0xc]
	ands r0, r3
	lsls r3, r0, #2
	adds r1, r1, r3
	adds r0, r4, #0
	mov r2, r8
	ands r0, r2
	lsrs r0, r0, #1
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	bne .L080B2334
	movs r0, #0xf
	ands r0, r6
	lsls r0, r0, #4
	orrs r2, r0
	movs r5, #1
	ldr r0, .L080B23C8
	str r5, [r0]
.L080B2334:
	strb r2, [r1]
	ldr r1, [sp, #0x14]
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsrs r0, r0, #0x13
	lsls r0, r0, #5
	add r0, ip
	adds r0, r0, r3
	adds r1, r4, #0
	mov r2, r8
	ands r1, r2
	lsrs r1, r1, #1
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, #0xf
	ands r0, r2
	cmp r0, #0
	bne .L080B2364
	lsrs r0, r6, #4
	orrs r2, r0
.L080B235E:
	movs r3, #1
	ldr r5, .L080B23C8
	str r3, [r5]
.L080B2364:
	strb r2, [r1]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r1, [sp, #0x14]
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp sb, sl
	bhs .L080B2394
	b .L080B2242
.L080B2394:
	ldr r2, [sp, #0x28]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldr r3, [sp, #0x2c]
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	ldr r5, [sp, #0x30]
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	cmp r0, r1
	bhs .L080B23B2
	b .L080B2210
.L080B23B2:
	movs r0, #0
	ldr r2, .L080B23CC
	strh r0, [r2, #0x2c]
.L080B23B8:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B23C8: .4byte 0x030045F4 @ IWRAM+0x45F4
.L080B23CC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B23D0
sub_080B23D0: @ 0x080B23D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp]
	ldrh r5, [r0, #0x10]
	lsrs r0, r5, #3
	str r0, [sp, #4]
	ldr r1, [sp]
	ldrh r3, [r1, #0x12]
	lsrs r2, r3, #3
	str r2, [sp, #8]
	ldr r2, .L080B247C
	ldrh r1, [r2, #0x28]
	ldr r4, [sp]
	ldrh r4, [r4, #0xc]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	adds r6, r4, #0
	ldr r7, [sp]
	ldrh r0, [r7, #8]
	lsrs r0, r0, #3
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	lsrs r1, r1, #0x13
	lsls r1, r1, #0x15
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	ldr r0, [r7]
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldr r0, [r7, #4]
	str r0, [sp, #0x1c]
	movs r1, #7
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq .L080B242A
	ldr r2, [sp, #4]
	adds r2, #1
	str r2, [sp, #4]
.L080B242A:
	ands r3, r1
	cmp r3, #0
	beq .L080B243A
	ldr r0, [sp, #8]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
.L080B243A:
	ldr r3, [sp]
	ldrh r0, [r3, #0x14]
	adds r7, r0, #0
	cmp r7, #1
	bne .L080B249A
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt .L080B2480
	movs r0, #8
	subs r0, r0, r4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	adds r0, r1, #0
	cmp r1, #0
	bge .L080B245C
	adds r0, r1, #7
.L080B245C:
	asrs r3, r0, #3
	lsls r2, r3, #5
	ldr r4, [sp, #0x14]
	adds r0, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x14]
	ldr r4, [sp, #0x10]
	adds r0, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r1, [sp, #4]
	subs r0, r1, r3
	b .L080B24EA
	.byte 0x00, 0x00
.L080B247C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B2480:
	adds r0, r4, r5
	cmp r0, #0xe8
	ble .L080B24F0
	subs r0, #0xe8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge .L080B2492
	adds r0, #7
.L080B2492:
	asrs r0, r0, #3
	ldr r2, [sp, #4]
	subs r0, r2, r0
	b .L080B24EA
.L080B249A:
	subs r1, r4, r5
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bgt .L080B24BA
	movs r0, #8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge .L080B24B2
	adds r0, #7
.L080B24B2:
	asrs r0, r0, #3
	ldr r3, [sp, #4]
	subs r0, r3, r0
	b .L080B24EA
.L080B24BA:
	cmp r6, #0xe8
	bls .L080B24F0
	adds r0, r6, #0
	subs r0, #0xe8
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, #0
	cmp r2, #0
	bge .L080B24CE
	adds r0, r2, #7
.L080B24CE:
	asrs r1, r0, #3
	lsls r3, r1, #5
	ldr r4, [sp, #0x14]
	subs r0, r4, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x14]
	ldr r4, [sp, #0x10]
	adds r0, r4, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r2, [sp, #4]
	subs r0, r2, r1
.L080B24EA:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
.L080B24F0:
	ldr r3, [sp, #4]
	lsls r0, r3, #0x10
	cmp r0, #0
	bgt .L080B24FA
	b .L080B282C
.L080B24FA:
	cmp r7, #1
	bne .L080B2578
	movs r4, #0
	ldr r7, [sp, #8]
	cmp r4, r7
	blo .L080B2508
	b .L080B2806
.L080B2508:
	ldr r1, [sp]
	ldrh r0, [r1, #0xa]
	lsls r2, r4, #3
	adds r0, r0, r2
	asrs r0, r0, #3
	lsls r0, r0, #0xa
	ldr r3, [sp, #0x18]
	adds r0, r3, r0
	ldrh r1, [r1, #0xe]
	adds r1, r1, r2
	asrs r1, r1, #3
	lsls r1, r1, #0xa
	ldr r7, [sp, #0x1c]
	adds r1, r7, r1
	ldr r2, [sp, #0x10]
	adds r3, r0, r2
	ldr r7, [sp, #0x14]
	adds r1, r1, r7
	movs r0, #0
	str r0, [sp, #0xc]
	adds r4, #1
	str r4, [sp, #0x20]
	ldr r2, [sp, #4]
	cmp r0, r2
	bhs .L080B256A
.L080B253A:
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldr r0, [sp, #0xc]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	ldr r4, [sp, #4]
	cmp r0, r4
	blo .L080B253A
.L080B256A:
	ldr r7, [sp, #0x20]
	lsls r0, r7, #0x10
	lsrs r4, r0, #0x10
	ldr r0, [sp, #8]
	cmp r4, r0
	blo .L080B2508
	b .L080B2806
.L080B2578:
	movs r4, #0
	ldr r1, [sp, #8]
	cmp r4, r1
	blo .L080B2582
	b .L080B2806
.L080B2582:
	ldr r2, [sp]
	ldrh r0, [r2, #0xa]
	lsls r2, r4, #3
	adds r0, r0, r2
	asrs r0, r0, #3
	lsls r0, r0, #0xa
	ldr r3, [sp, #0x18]
	adds r0, r3, r0
	ldr r7, [sp]
	ldrh r1, [r7, #0xe]
	adds r1, r1, r2
	asrs r1, r1, #3
	lsls r1, r1, #0xa
	ldr r2, [sp, #0x1c]
	adds r1, r2, r1
	ldr r3, [sp, #0x10]
	adds r5, r0, r3
	ldr r7, [sp, #0x14]
	adds r2, r1, r7
	movs r0, #0
	str r0, [sp, #0xc]
	adds r4, #1
	str r4, [sp, #0x20]
	ldr r1, [sp, #4]
	cmp r0, r1
	blo .L080B25B8
	b .L080B27F8
.L080B25B8:
	movs r3, #0xf0
	lsls r3, r3, #0x14
	mov sl, r3
	movs r4, #0xf0
	lsls r4, r4, #0x10
	mov sb, r4
	movs r7, #0xf0
	lsls r7, r7, #0xc
	mov r8, r7
	movs r0, #0xf0
	lsls r0, r0, #8
	mov ip, r0
	movs r6, #0xf0
	movs r4, #0xf
.L080B25D4:
	ldm r5!, {r3}
	lsls r1, r3, #0x1c
	movs r7, #0xf0
	lsls r7, r7, #0x18
	ands r1, r7
	lsls r0, r3, #0x14
	mov r7, sl
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #0xc
	mov r7, sb
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #4
	mov r7, r8
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #4
	mov r7, ip
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0xc
	movs r7, #0xf0
	lsls r7, r7, #4
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0x14
	ands r0, r6
	orrs r1, r0
	lsrs r0, r3, #0x1c
	ands r0, r4
	orrs r1, r0
	stm r2!, {r1}
	ldm r5!, {r3}
	lsls r1, r3, #0x1c
	movs r0, #0xf0
	lsls r0, r0, #0x18
	ands r1, r0
	lsls r0, r3, #0x14
	mov r7, sl
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #0xc
	mov r7, sb
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #4
	mov r7, r8
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #4
	mov r7, ip
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0xc
	movs r7, #0xf0
	lsls r7, r7, #4
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0x14
	ands r0, r6
	orrs r1, r0
	lsrs r0, r3, #0x1c
	ands r0, r4
	orrs r1, r0
	stm r2!, {r1}
	ldm r5!, {r3}
	lsls r1, r3, #0x1c
	movs r0, #0xf0
	lsls r0, r0, #0x18
	ands r1, r0
	lsls r0, r3, #0x14
	mov r7, sl
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #0xc
	mov r7, sb
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #4
	mov r7, r8
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #4
	mov r7, ip
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0xc
	movs r7, #0xf0
	lsls r7, r7, #4
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0x14
	ands r0, r6
	orrs r1, r0
	lsrs r0, r3, #0x1c
	ands r0, r4
	orrs r1, r0
	stm r2!, {r1}
	ldm r5!, {r3}
	lsls r1, r3, #0x1c
	movs r0, #0xf0
	lsls r0, r0, #0x18
	ands r1, r0
	lsls r0, r3, #0x14
	mov r7, sl
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #0xc
	mov r7, sb
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #4
	mov r7, r8
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #4
	mov r7, ip
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0xc
	movs r7, #0xf0
	lsls r7, r7, #4
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0x14
	ands r0, r6
	orrs r1, r0
	lsrs r0, r3, #0x1c
	ands r0, r4
	orrs r1, r0
	stm r2!, {r1}
	ldm r5!, {r3}
	lsls r1, r3, #0x1c
	movs r0, #0xf0
	lsls r0, r0, #0x18
	ands r1, r0
	lsls r0, r3, #0x14
	mov r7, sl
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #0xc
	mov r7, sb
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #4
	mov r7, r8
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #4
	mov r7, ip
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0xc
	movs r7, #0xf0
	lsls r7, r7, #4
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0x14
	ands r0, r6
	orrs r1, r0
	lsrs r0, r3, #0x1c
	ands r0, r4
	orrs r1, r0
	stm r2!, {r1}
	ldm r5!, {r3}
	lsls r1, r3, #0x1c
	movs r0, #0xf0
	lsls r0, r0, #0x18
	ands r1, r0
	lsls r0, r3, #0x14
	mov r7, sl
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #0xc
	mov r7, sb
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #4
	mov r7, r8
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #4
	mov r7, ip
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0xc
	movs r7, #0xf0
	lsls r7, r7, #4
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0x14
	ands r0, r6
	orrs r1, r0
	lsrs r0, r3, #0x1c
	ands r0, r4
	orrs r1, r0
	stm r2!, {r1}
	ldm r5!, {r3}
	lsls r1, r3, #0x1c
	movs r0, #0xf0
	lsls r0, r0, #0x18
	ands r1, r0
	lsls r0, r3, #0x14
	mov r7, sl
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #0xc
	mov r7, sb
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #4
	mov r7, r8
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #4
	mov r7, ip
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0xc
	movs r7, #0xf0
	lsls r7, r7, #4
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0x14
	ands r0, r6
	orrs r1, r0
	lsrs r0, r3, #0x1c
	ands r0, r4
	orrs r1, r0
	stm r2!, {r1}
	ldm r5!, {r3}
	lsls r1, r3, #0x1c
	movs r0, #0xf0
	lsls r0, r0, #0x18
	ands r1, r0
	lsls r0, r3, #0x14
	mov r7, sl
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #0xc
	mov r7, sb
	ands r0, r7
	orrs r1, r0
	lsls r0, r3, #4
	mov r7, r8
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #4
	mov r7, ip
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0xc
	movs r7, #0xf0
	lsls r7, r7, #4
	ands r0, r7
	orrs r1, r0
	lsrs r0, r3, #0x14
	ands r0, r6
	orrs r1, r0
	lsrs r0, r3, #0x1c
	ands r0, r4
	orrs r1, r0
	stm r2!, {r1}
	subs r2, #0x40
	ldr r0, [sp, #0xc]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	ldr r1, [sp, #4]
	cmp r0, r1
	bhs .L080B27F8
	b .L080B25D4
.L080B27F8:
	ldr r2, [sp, #0x20]
	lsls r0, r2, #0x10
	lsrs r4, r0, #0x10
	ldr r3, [sp, #8]
	cmp r4, r3
	bhs .L080B2806
	b .L080B2582
.L080B2806:
	ldr r2, .L080B2818
	ldrh r0, [r2, #0x2c]
	adds r1, r0, #0
	cmp r1, #0
	bne .L080B281C
	adds r0, #1
	strh r0, [r2, #0x2c]
	b .L080B282C
	.byte 0x00, 0x00
.L080B2818: .4byte 0x03004550 @ IWRAM+0x4550
.L080B281C:
	cmp r1, #2
	bls .L080B2826
	movs r0, #0
	strh r0, [r2, #0x2c]
	b .L080B282C
.L080B2826:
	adds r0, #1
	ldr r4, .L080B283C
	strh r0, [r4, #0x2c]
.L080B282C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B283C: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B2840
sub_080B2840: @ 0x080B2840
.L080B2840:
	push {r4, lr}
	sub sp, #4
	ldr r3, .L080B2870
	str r0, [r3, #0x24]
	movs r4, #0
	strh r1, [r3, #0x28]
	strh r2, [r3, #0x2a]
	str r4, [sp]
	ldr r1, .L080B2874
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080B2878
	str r0, [r1, #4]
	ldr r0, .L080B287C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #1
	strh r0, [r3, #0xe]
	strh r4, [r3, #0x2c]
	strh r4, [r3, #0xc]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L080B2870: .4byte 0x03004550 @ IWRAM+0x4550
.L080B2874: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B2878: .4byte 0x02005004 @ EWRAM+0x5004
.L080B287C: .4byte 0x85001000

	thumb_func_start sub_080B2880
sub_080B2880: @ 0x080B2880
.L080B2880:
	push {lr}
	sub sp, #4
	bl sub_080ADF40
	cmp r0, #0
	bne .L080B2894
	ldr r1, .L080B2890
	b .L080B28B8
.L080B2890: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B2894:
	movs r2, #0
	str r2, [sp]
	ldr r1, .L080B28D4
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080B28D8
	str r0, [r1, #4]
	ldr r0, .L080B28DC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	str r2, [sp]
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080B28E0
	str r0, [r1, #4]
	ldr r0, .L080B28E4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
.L080B28B8:
	ldr r0, .L080B28E8
	str r0, [r1]
	ldr r0, .L080B28EC
	str r0, [r1, #4]
	ldr r0, .L080B28F0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, .L080B28F4
	movs r0, #0
	strh r0, [r1, #0xc]
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B28D4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B28D8: .4byte 0x06003000 @ VRAM+0x3000
.L080B28DC: .4byte 0x85000400
.L080B28E0: .4byte 0x06004000 @ VRAM+0x4000
.L080B28E4: .4byte 0x85001000
.L080B28E8: .4byte 0x02005004 @ EWRAM+0x5004
.L080B28EC: .4byte 0x06008800 @ VRAM+0x8800
.L080B28F0: .4byte 0x84000D00
.L080B28F4: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B28F8
sub_080B28F8: @ 0x080B28F8
.L080B28F8:
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r4, .L080B2904
	b .L080B291C
	.byte 0x00, 0x00
.L080B2904: .4byte 0x03004550 @ IWRAM+0x4550
.L080B2908:
	cmp r1, #1
	bne .L080B2912
	ldrh r0, [r4, #0xe]
	adds r0, #1
	b .L080B2930
.L080B2912:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	adds r6, #0x20
	adds r5, #0x20
.L080B291C:
	adds r0, r6, #0
	adds r1, r5, #0
	bl sub_080B2D94
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080B2908
	movs r0, #0
.L080B2930:
	strh r0, [r4, #0xe]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080B2938
sub_080B2938: @ 0x080B2938
.L080B2938:
	push {r4, lr}
	ldr r0, .L080B2968
	ldrh r0, [r0]
	ldr r1, .L080B296C
	ldrh r1, [r1]
	bl sub_080C8B10
	adds r4, r0, #0
	bl sub_080B9750
	cmp r0, #0
	bne .L080B2978
	ldr r0, .L080B2970
	ldr r1, .L080B2974
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xe8
	muls r1, r0, r1
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r0, r0, r1
	ldr r0, [r0]
	b .L080B297A
.L080B2968: .4byte 0x03004614 @ IWRAM+0x4614
.L080B296C: .4byte 0x03004514 @ IWRAM+0x4514
.L080B2970: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B2974: .4byte 0x00000A38
.L080B2978:
	movs r0, #0
.L080B297A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080B2980
sub_080B2980: @ 0x080B2980
.L080B2980:
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	adds r1, r3, #0
	bl sub_080B0248
	movs r1, #0
	subs r0, #2
	cmp r0, #1
	bhi .L080B29A0
	movs r1, #1
.L080B29A0:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B29A8
sub_080B29A8: @ 0x080B29A8
.L080B29A8:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq .L080B29B6
	cmp r0, #2
	bne .L080B2A20
.L080B29B6:
	ldr r1, .L080B29F4
	movs r0, #0x5a
	strb r0, [r1]
	ldr r1, .L080B29F8
	movs r0, #0x38
	strb r0, [r1]
	ldr r0, .L080B29FC
	movs r4, #0x58
	strb r4, [r0]
	ldr r0, .L080B2A00
	movs r3, #0x18
	strb r3, [r0]
	ldr r0, .L080B2A04
	movs r5, #0x3f
	movs r2, #0x2f
	strb r2, [r0]
	ldr r1, .L080B2A08
	movs r0, #0xb8
	strb r0, [r1]
	ldr r1, .L080B2A0C
	movs r0, #0x96
	strb r0, [r1]
	ldr r0, .L080B2A10
	strb r4, [r0]
	ldr r0, .L080B2A14
	strb r3, [r0]
	ldr r0, .L080B2A18
	strb r2, [r0]
	ldr r0, .L080B2A1C
	strb r5, [r0]
	b .L080B2A9E
.L080B29F4: .4byte 0x03000030 @ IWRAM+0x30
.L080B29F8: .4byte 0x03000031 @ IWRAM+0x31
.L080B29FC: .4byte 0x03000034 @ IWRAM+0x34
.L080B2A00: .4byte 0x03000035 @ IWRAM+0x35
.L080B2A04: .4byte 0x03000038 @ IWRAM+0x38
.L080B2A08: .4byte 0x03000032 @ IWRAM+0x32
.L080B2A0C: .4byte 0x03000033 @ IWRAM+0x33
.L080B2A10: .4byte 0x03000036 @ IWRAM+0x36
.L080B2A14: .4byte 0x03000037 @ IWRAM+0x37
.L080B2A18: .4byte 0x03000039 @ IWRAM+0x39
.L080B2A1C: .4byte 0x0300003A @ IWRAM+0x3A
.L080B2A20:
	cmp r0, #1
	bne .L080B2A8C
	ldr r0, .L080B2A60
	movs r5, #0x98
	strb r5, [r0]
	ldr r0, .L080B2A64
	movs r4, #0x58
	strb r4, [r0]
	ldr r0, .L080B2A68
	movs r3, #0x18
	strb r3, [r0]
	ldr r0, .L080B2A6C
	movs r2, #0
	strb r2, [r0]
	ldr r0, .L080B2A70
	movs r6, #0x3f
	movs r1, #0x2f
	strb r1, [r0]
	ldr r0, .L080B2A74
	strb r5, [r0]
	ldr r0, .L080B2A78
	strb r4, [r0]
	ldr r0, .L080B2A7C
	strb r3, [r0]
	ldr r0, .L080B2A80
	strb r2, [r0]
	ldr r0, .L080B2A84
	strb r1, [r0]
	ldr r0, .L080B2A88
	strb r6, [r0]
	b .L080B2A9E
	.byte 0x00, 0x00
.L080B2A60: .4byte 0x03000030 @ IWRAM+0x30
.L080B2A64: .4byte 0x03000031 @ IWRAM+0x31
.L080B2A68: .4byte 0x03000034 @ IWRAM+0x34
.L080B2A6C: .4byte 0x03000035 @ IWRAM+0x35
.L080B2A70: .4byte 0x03000038 @ IWRAM+0x38
.L080B2A74: .4byte 0x03000032 @ IWRAM+0x32
.L080B2A78: .4byte 0x03000033 @ IWRAM+0x33
.L080B2A7C: .4byte 0x03000036 @ IWRAM+0x36
.L080B2A80: .4byte 0x03000037 @ IWRAM+0x37
.L080B2A84: .4byte 0x03000039 @ IWRAM+0x39
.L080B2A88: .4byte 0x0300003A @ IWRAM+0x3A
.L080B2A8C:
	cmp r0, #3
	bne .L080B2A9E
	ldr r0, .L080B2AA4
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080B2AA8
	strb r1, [r0]
	ldr r0, .L080B2AAC
	strb r1, [r0]
.L080B2A9E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080B2AA4: .4byte 0x03000038 @ IWRAM+0x38
.L080B2AA8: .4byte 0x03000039 @ IWRAM+0x39
.L080B2AAC: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080B2AB0
sub_080B2AB0: @ 0x080B2AB0
.L080B2AB0:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	movs r4, #0
	movs r7, #0
	bl sub_080AD7E4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne .L080B2AD4
	ldr r1, .L080B2B54
	ldr r0, [r1, #0x24]
	cmp r0, #1
	bne .L080B2AD4
	ldrh r0, [r1, #0xc]
	cmp r0, #0
	bne .L080B2AD4
	ldr r4, .L080B2B58
.L080B2AD4:
	movs r0, #0
	adds r1, r4, #0
	bl sub_080B2980
	cmp r0, #1
	beq .L080B2AE2
	b .L080B2CA8
.L080B2AE2:
	ldr r0, .L080B2B54
	ldrh r0, [r0, #0x2e]
	cmp r0, #0x21
	bhi .L080B2B0C
	ldr r0, .L080B2B5C
	ldr r0, [r0]
	cmp r0, #0
	beq .L080B2B0C
	ldr r0, .L080B2B60
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0x58
	str r1, [sp, #4]
	movs r1, #0x18
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
.L080B2B0C:
	ldr r6, .L080B2B54
	ldrh r0, [r6, #0x2e]
	cmp r0, #0x20
	bls .L080B2B16
	b .L080B2CA8
.L080B2B16:
	bl sub_080B2938
	adds r4, r0, #0
	ldrh r0, [r6, #0x2e]
	cmp r0, #0
	beq .L080B2B2A
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080B29A8
.L080B2B2A:
	ldr r0, .L080B2B5C
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B2B34
	b .L080B2CA8
.L080B2B34:
	cmp r4, #0
	bne .L080B2B68
	ldr r0, .L080B2B64
	movs r5, #0xa0
	lsls r5, r5, #2
	str r5, [sp]
	adds r1, r7, #0
	adds r1, #0x58
	ldrh r2, [r6, #0x2e]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r4, #0x18
	b .L080B2C04
	.byte 0x00, 0x00
.L080B2B54: .4byte 0x03004550 @ IWRAM+0x4550
.L080B2B58: .4byte 0x0000FFFF
.L080B2B5C: .4byte 0x0300461C @ IWRAM+0x461C
.L080B2B60: .4byte gUnknown_08002CAC
.L080B2B64: .4byte gUnknown_08002C88
.L080B2B68:
	cmp r4, #1
	bne .L080B2BAC
	ldr r0, .L080B2BA4
	movs r5, #0xa0
	lsls r5, r5, #2
	str r5, [sp]
	movs r1, #0x58
	str r1, [sp, #4]
	ldrh r1, [r6, #0x2e]
	lsls r1, r1, #1
	movs r4, #0x18
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080B2BA8
	str r5, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	ldrh r1, [r6, #0x2e]
	lsls r1, r1, #1
	subs r4, r4, r1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	b .L080B2C1E
.L080B2BA4: .4byte gUnknown_08002C88
.L080B2BA8: .4byte gUnknown_08002C70
.L080B2BAC:
	cmp r4, #2
	bne .L080B2C3C
	ldr r0, .L080B2C2C
	movs r5, #0xc0
	lsls r5, r5, #2
	str r5, [sp]
	ldrh r1, [r6, #0x2e]
	subs r1, r7, r1
	adds r1, #0x78
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r4, #0x18
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080B2C30
	str r5, [sp]
	ldrh r1, [r6, #0x2e]
	adds r1, #0x78
	adds r1, r7, r1
	subs r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080B2C34
	subs r5, #0x80
	str r5, [sp]
	adds r1, r7, #0
	adds r1, #0x58
	ldrh r2, [r6, #0x2e]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
.L080B2C04:
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080B2C38
	str r5, [sp]
	ldrh r1, [r6, #0x2e]
	adds r1, #0x78
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
.L080B2C1E:
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	b .L080B2CA8
.L080B2C2C: .4byte gUnknown_08002D78
.L080B2C30: .4byte gUnknown_08002DAC
.L080B2C34: .4byte gUnknown_08002C88
.L080B2C38: .4byte gUnknown_08002C70
.L080B2C3C:
	cmp r4, #3
	bne .L080B2CA8
	ldr r0, .L080B2CB0
	movs r5, #0xa0
	lsls r5, r5, #2
	str r5, [sp]
	adds r1, r7, #0
	adds r1, #0x58
	ldrh r2, [r6, #0x2e]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r4, #0x18
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080B2CB4
	str r5, [sp]
	ldrh r1, [r6, #0x2e]
	adds r1, #0x78
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080B2CB8
	adds r5, #0x80
	str r5, [sp]
	movs r1, #0x3a
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080B2CBC
	str r5, [sp]
	movs r1, #0x96
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
.L080B2CA8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B2CB0: .4byte gUnknown_08002C88
.L080B2CB4: .4byte gUnknown_08002C70
.L080B2CB8: .4byte gUnknown_08002DE8
.L080B2CBC: .4byte gUnknown_08002E24

	thumb_func_start sub_080B2CC0
sub_080B2CC0: @ 0x080B2CC0
.L080B2CC0:
	push {r4, r5, lr}
	ldr r5, .L080B2CFC
	ldr r4, [r5, #0x24]
	ldrh r0, [r5, #2]
	movs r1, #0
	bl sub_080AE574
	ldrh r0, [r5]
	cmp r0, #3
	bne .L080B2CD8
	bl sub_080B2AB0
.L080B2CD8:
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	beq .L080B2D8C
	bl sub_080ADF40
	cmp r0, #0
	bne .L080B2D80
	cmp r4, #0
	bne .L080B2D04
	ldrh r1, [r5, #0xe]
	lsls r1, r1, #5
	ldr r0, .L080B2D00
	adds r1, r1, r0
	adds r0, r1, #0
	bl sub_080B28F8
	b .L080B2D8C
	.byte 0x00, 0x00
.L080B2CFC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B2D00: .4byte gUnknown_08160A0C
.L080B2D04:
	cmp r4, #1
	bne .L080B2D24
	ldrh r1, [r5, #0xe]
	lsls r1, r1, #5
	ldr r0, .L080B2D1C
	adds r0, r1, r0
	ldr r2, .L080B2D20
	adds r1, r1, r2
	bl sub_080B28F8
	b .L080B2D8C
	.byte 0x00, 0x00
.L080B2D1C: .4byte gUnknown_08160E0C
.L080B2D20: .4byte gUnknown_08160A0C
.L080B2D24:
	cmp r4, #2
	bne .L080B2D4C
	movs r0, #8
	ldrsh r1, [r5, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080B2D40
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #5
	ldr r1, .L080B2D3C
	b .L080B2D6A
.L080B2D3C: .4byte gUnknown_0816120C
.L080B2D40:
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #5
	ldr r1, .L080B2D48
	b .L080B2D6A
.L080B2D48: .4byte gUnknown_0816160C
.L080B2D4C:
	cmp r4, #3
	bne .L080B2D8C
	movs r1, #8
	ldrsh r0, [r5, r1]
	cmp r0, #1
	bne .L080B2D64
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #5
	ldr r1, .L080B2D60
	b .L080B2D6A
.L080B2D60: .4byte gUnknown_08161E0C
.L080B2D64:
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #5
	ldr r1, .L080B2D78
.L080B2D6A:
	adds r2, r0, r1
	ldr r1, .L080B2D7C
	adds r1, r0, r1
	adds r0, r2, #0
	bl sub_080B28F8
	b .L080B2D8C
.L080B2D78: .4byte gUnknown_08161A0C
.L080B2D7C: .4byte gUnknown_08160A0C
.L080B2D80:
	lsls r4, r4, #0x10
.L080B2D82:
	lsrs r0, r4, #0x10
	bl sub_080BA6B4
	cmp r0, #1
	bne .L080B2D82
.L080B2D8C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B2D94
sub_080B2D94: @ 0x080B2D94
.L080B2D94:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, .L080B2DB8
	ldrh r0, [r0]
	ldr r1, .L080B2DBC
	ldrh r1, [r1]
	bl sub_080C8B10
	ldr r1, [r6]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080B2DC0
	adds r0, r1, #0
	b .L080B2EF2
.L080B2DB8: .4byte 0x03004614 @ IWRAM+0x4614
.L080B2DBC: .4byte 0x03004514 @ IWRAM+0x4514
.L080B2DC0:
	cmp r1, #0
	bne .L080B2DC6
	b .L080B2EF0
.L080B2DC6:
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq .L080B2DD4
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B2DD4
	b .L080B2EF0
.L080B2DD4:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq .L080B2DE2
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B2DE2
	b .L080B2EF0
.L080B2DE2:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq .L080B2DF0
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080B2DF0
	b .L080B2EF0
.L080B2DF0:
	ldr r0, [r4, #0x10]
	ldrh r7, [r0]
	cmp r7, #0
	bne .L080B2DFA
	b .L080B2EF0
.L080B2DFA:
	ldr r0, .L080B2E34
	ldr r0, [r0]
	cmp r0, #0
	beq .L080B2E1C
	cmp r7, #3
	beq .L080B2E0C
	mov r0, r8
	cmp r0, #3
	bne .L080B2E1C
.L080B2E0C:
	ldr r0, [r6, #0xc]
	cmp r0, #0
	bne .L080B2E1C
	ldr r4, [r6, #8]
	ldr r5, .L080B2E38
	adds r0, r4, #0
	bl _call_via_r5
.L080B2E1C:
	cmp r7, #3
	beq .L080B2E30
	mov r0, r8
	cmp r0, #3
	beq .L080B2E30
	cmp r7, #2
	beq .L080B2E30
	mov r0, r8
	cmp r0, #2
	bne .L080B2E3C
.L080B2E30:
	ldr r4, [r6, #4]
	b .L080B2E3E
.L080B2E34: .4byte 0x03003FE8 @ IWRAM+0x3FE8
.L080B2E38: .4byte 0x03003BC1 @ IWRAM+0x3BC1
.L080B2E3C:
	ldr r4, [r6]
.L080B2E3E:
	ldr r0, [r6, #0xc]
	cmp r0, #0
	bne .L080B2E60
	ldr r5, .L080B2E58
	adds r0, r4, #0
	bl _call_via_r5
	ldr r0, .L080B2E5C
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B2EB6
	b .L080B2EF0
	.byte 0x00, 0x00
.L080B2E58: .4byte 0x03003BC1 @ IWRAM+0x3BC1
.L080B2E5C: .4byte 0x030045F4 @ IWRAM+0x45F4
.L080B2E60:
	cmp r0, #1
	bne .L080B2EB0
	ldr r5, .L080B2E7C
	adds r0, r4, #0
	bl _call_via_r5
	ldr r1, .L080B2E80
	cmp r4, r1
	bne .L080B2E88
	ldr r0, .L080B2E84
	bl _call_via_r5
	b .L080B2EB6
	.byte 0x00, 0x00
.L080B2E7C: .4byte 0x03004011 @ IWRAM+0x4011
.L080B2E80: .4byte gUnknown_0815FD7C
.L080B2E84: .4byte gUnknown_0815FDD0
.L080B2E88:
	adds r0, r1, #0
	adds r0, #0x1c
	cmp r4, r0
	bne .L080B2E9C
	ldr r0, .L080B2E98
	bl _call_via_r5
	b .L080B2EB6
.L080B2E98: .4byte gUnknown_0815FDEC
.L080B2E9C:
	adds r0, r1, #0
	adds r0, #0x38
	cmp r4, r0
	bne .L080B2EB6
	ldr r0, .L080B2EAC
	bl _call_via_r5
	b .L080B2EB6
.L080B2EAC: .4byte gUnknown_0815FE08
.L080B2EB0:
	adds r0, r4, #0
	bl sub_080B6F40
.L080B2EB6:
	ldr r0, .L080B2EE4
	ldr r0, [r0]
	cmp r0, #0
	beq .L080B2ED8
	cmp r7, #3
	beq .L080B2EC8
	mov r0, r8
	cmp r0, #3
	bne .L080B2ED8
.L080B2EC8:
	ldr r0, [r6, #0xc]
	cmp r0, #1
	bne .L080B2ED8
	ldr r4, [r6, #8]
	ldr r5, .L080B2EE8
	adds r0, r4, #0
	bl _call_via_r5
.L080B2ED8:
	ldr r0, .L080B2EEC
	ldrh r0, [r0, #0x2c]
	cmp r0, #0
	bne .L080B2EF0
	movs r0, #1
	b .L080B2EF2
.L080B2EE4: .4byte 0x03003FE8 @ IWRAM+0x3FE8
.L080B2EE8: .4byte 0x03004011 @ IWRAM+0x4011
.L080B2EEC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B2EF0:
	movs r0, #0
.L080B2EF2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080B2EFC
sub_080B2EFC: @ 0x080B2EFC
.L080B2EFC:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r0, .L080B2F2C
	ldrh r0, [r0]
	ldr r1, .L080B2F30
	ldrh r1, [r1]
	bl sub_080C8B10
	adds r0, #0x94
	ldr r3, [r0]
	ldr r0, .L080B2F34
	ldrh r4, [r0, #0x12]
	ldrh r1, [r0, #0x14]
	ldrh r0, [r0, #2]
	cmp r0, #1
	beq .L080B2F4C
	cmp r0, #1
	bgt .L080B2F38
	cmp r0, #0
	beq .L080B2F42
	b .L080B2F6C
.L080B2F2C: .4byte 0x03004614 @ IWRAM+0x4614
.L080B2F30: .4byte 0x03004514 @ IWRAM+0x4514
.L080B2F34: .4byte 0x03004550 @ IWRAM+0x4550
.L080B2F38:
	cmp r0, #2
	beq .L080B2F56
	cmp r0, #3
	beq .L080B2F60
	b .L080B2F6C
.L080B2F42:
	adds r0, r4, r6
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r1, r5
	b .L080B2F68
.L080B2F4C:
	subs r0, r4, r5
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r1, r6
	b .L080B2F68
.L080B2F56:
	subs r0, r4, r6
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	subs r0, r1, r5
	b .L080B2F68
.L080B2F60:
	adds r0, r4, r5
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	subs r0, r1, r6
.L080B2F68:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
.L080B2F6C:
	lsls r0, r4, #0x10
	cmp r0, #0
	blt .L080B2F90
	lsls r0, r1, #0x10
	cmp r0, #0
	blt .L080B2F90
	ldr r0, .L080B2F94
	ldrh r2, [r0, #0x1a]
	cmp r4, r2
	bhs .L080B2F90
	ldrh r0, [r0, #0x1c]
	cmp r1, r0
	bhs .L080B2F90
.L080B2F86:
	ldr r2, [r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L080B2F98
.L080B2F90:
	movs r0, #0
	b .L080B2FD4
.L080B2F94: .4byte 0x03004550 @ IWRAM+0x4550
.L080B2F98:
	cmp r2, r4
	bne .L080B2FA8
	ldr r0, [r3, #4]
	cmp r0, r1
	bne .L080B2FA8
	adds r0, r3, #0
	adds r0, #8
	b .L080B2FD4
.L080B2FA8:
	adds r3, #8
	ldr r6, .L080B2FCC
	ldr r5, .L080B2FD0
	movs r2, #2
	rsbs r2, r2, #0
.L080B2FB2:
	ldr r0, [r3]
	ands r0, r5
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r3, r3, r0
	ldr r0, [r3]
	cmp r0, r2
	bne .L080B2FB2
	adds r3, #4
	b .L080B2F86
	.byte 0x00, 0x00
.L080B2FCC: .4byte gUnknown_0816222C
.L080B2FD0: .4byte 0x0000FFFF
.L080B2FD4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B2FDC
sub_080B2FDC: @ 0x080B2FDC
.L080B2FDC:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, .L080B2FFC
	ldrh r5, [r4, #2]
	movs r2, #0
	strh r2, [r4, #2]
	bl sub_080B2EFC
	strh r5, [r4, #2]
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B2FFC: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B3000
sub_080B3000: @ 0x080B3000
.L080B3000:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r4, .L080B3034
	ldrh r5, [r4, #2]
	ldrh r6, [r4, #0x12]
	ldrh r2, [r4, #0x14]
	mov r8, r2
	movs r2, #0
	strh r2, [r4, #2]
	strh r0, [r4, #0x12]
	strh r1, [r4, #0x14]
	movs r0, #0
	movs r1, #0
	bl sub_080B2EFC
	strh r5, [r4, #2]
	strh r6, [r4, #0x12]
	mov r1, r8
	strh r1, [r4, #0x14]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B3034: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B3038
sub_080B3038: @ 0x080B3038
.L080B3038:
	push {r4, lr}
	adds r3, r0, #0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r3, #0
	beq .L080B304E
.L080B3044:
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L080B3052
.L080B304E:
	movs r0, #0
	b .L080B3072
.L080B3052:
	ldr r1, .L080B3068
	ands r1, r2
	cmp r1, r4
	beq .L080B3070
	ldr r0, .L080B306C
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	lsls r0, r0, #2
	adds r3, r3, r0
	b .L080B3044
.L080B3068: .4byte 0x0000FFFF
.L080B306C: .4byte gUnknown_0816222C
.L080B3070:
	adds r0, r3, #0
.L080B3072:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_080B3078
sub_080B3078: @ 0x080B3078
.L080B3078:
	push {r4, lr}
	adds r4, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_080B2EFC
	adds r1, r4, #0
	bl sub_080B3038
	cmp r0, #0
	beq .L080B3098
	movs r0, #1
.L080B3098:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B30A0
sub_080B30A0: @ 0x080B30A0
.L080B30A0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, .L080B3160
	ldrh r0, [r4]
	bl sub_080C8B3C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	ldr r0, .L080B3164
	ldr r2, .L080B3168
	adds r1, r0, r2
	ldrb r5, [r1]
	ldr r1, .L080B316C
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0x3f
	ands r6, r0
	ldrh r0, [r4]
	movs r1, #0
	bl sub_080C8B10
	adds r4, r0, #0
	movs r7, #0
	cmp r7, sb
	bhs .L080B31AC
	ldr r2, .L080B3170
	mov r8, r2
	ldr r0, .L080B3174
	mov sl, r0
.L080B30E4:
	ldrh r0, [r4, #8]
	cmp r0, r5
	bhi .L080B3180
	ldrh r0, [r4, #0xa]
	cmp r0, r6
	bhi .L080B3180
	ldrh r0, [r4, #0xc]
	cmp r0, r5
	blo .L080B3180
	ldrh r0, [r4, #0xe]
	cmp r0, r6
	blo .L080B3180
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl sub_080B7944
	cmp r0, #1
	bne .L080B3180
	ldrh r0, [r4, #8]
	subs r0, r5, r0
	mov r1, r8
	strh r0, [r1, #0x12]
	ldrh r0, [r4, #0xa]
	subs r0, r6, r0
	strh r0, [r1, #0x14]
	ldr r0, .L080B3164
	ldr r2, .L080B316C
	adds r0, r0, r2
	ldrb r0, [r0]
	lsrs r0, r0, #6
	strh r0, [r1, #4]
	strh r0, [r1, #2]
	bl sub_080AE2C0
	ldr r0, .L080B3178
	ldr r1, [r0]
	ldrh r0, [r1]
	mov r2, sl
	strh r0, [r2]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, sl
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r0, .L080B317C
	ldr r1, [r0]
	movs r2, #0x20
	str r2, [sp]
	movs r0, #3
	movs r2, #0xd0
	lsls r2, r2, #1
	add r2, sl
	movs r3, #0x20
	bl Palette_CopyWithEffect
	b .L080B31AC
	.byte 0x00, 0x00
.L080B3160: .4byte 0x03004614 @ IWRAM+0x4614
.L080B3164: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B3168: .4byte 0x000018C2
.L080B316C: .4byte 0x000018C3
.L080B3170: .4byte 0x03004550 @ IWRAM+0x4550
.L080B3174: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B3178: .4byte 0x03004630 @ IWRAM+0x4630
.L080B317C: .4byte 0x03004510 @ IWRAM+0x4510
.L080B3180:
	mov r0, sb
	subs r0, #1
	ldr r2, .L080B31BC
	ldr r1, [r2]
	cmp r0, r1
	beq .L080B31AC
	adds r0, r1, #1
	str r0, [r2]
	ldr r0, .L080B31C0
	ldrh r0, [r0]
	bl sub_080ADFEC
	bl sub_080AE234
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r4, r4, r0
	cmp r7, sb
	blo .L080B30E4
.L080B31AC:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B31BC: .4byte 0x03004514 @ IWRAM+0x4514
.L080B31C0: .4byte 0x03004544 @ IWRAM+0x4544

	thumb_func_start sub_080B31C4
sub_080B31C4: @ 0x080B31C4
.L080B31C4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080B322C
	mov r8, r1
	mov sl, r0
	ldr r0, .L080B3230
	mov sb, r0
.L080B31E6:
	mov r0, sl
	mov r1, r8
	strh r0, [r1, #0x12]
	strh r0, [r1, #0x14]
	movs r6, #0
	ldr r2, .L080B322C
	ldrh r1, [r1, #0x1c]
	cmp r6, r1
	bhs .L080B3272
.L080B31F8:
	movs r5, #0
	ldrh r0, [r2, #0x1a]
	cmp r5, r0
	bhs .L080B3266
	ldr r2, .L080B322C
.L080B3202:
	adds r0, r5, #0
	adds r1, r6, #0
	str r2, [sp, #4]
	bl sub_080B2FDC
	adds r1, r4, #0
	bl sub_080B3038
	adds r1, r0, #0
	ldr r2, [sp, #4]
	cmp r1, #0
	beq .L080B3258
	cmp r4, #1
	beq .L080B3240
	cmp r4, #2
	beq .L080B3240
	cmp r4, #0x1b
	bne .L080B3234
	ldrh r0, [r1, #6]
	b .L080B3242
	.byte 0x00, 0x00
.L080B322C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B3230: .4byte 0x03004514 @ IWRAM+0x4514
.L080B3234:
	cmp r4, #0x1c
	bne .L080B323C
	ldrh r0, [r1, #6]
	b .L080B3242
.L080B323C:
	cmp r4, #3
	bne .L080B3248
.L080B3240:
	ldrh r0, [r1, #4]
.L080B3242:
	cmp r0, r7
	beq .L080B3254
	b .L080B3258
.L080B3248:
	cmp r4, #0xa
	bne .L080B3254
	ldrh r0, [r1, #2]
	cmp r0, r7
	beq .L080B3254
	movs r1, #0
.L080B3254:
	cmp r1, #0
	bne .L080B330A
.L080B3258:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r1, r8
	ldrh r1, [r1, #0x1a]
	cmp r5, r1
	blo .L080B3202
.L080B3266:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldrh r0, [r2, #0x1c]
	cmp r6, r0
	blo .L080B31F8
.L080B3272:
	cmp r4, #1
	bne .L080B327E
	mov r1, sb
	ldr r0, [r1]
	subs r0, #1
	b .L080B3294
.L080B327E:
	cmp r4, #2
	beq .L080B328E
	adds r0, r4, #0
	subs r0, #0x1b
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L080B329C
.L080B328E:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
.L080B3294:
	str r0, [r1]
.L080B3296:
	bl sub_080AE234
	b .L080B31E6
.L080B329C:
	cmp r4, #3
	bne .L080B32BE
	ldr r2, .L080B32B0
	ldr r0, .L080B32B4
	ldr r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bls .L080B32B8
	adds r0, r1, #1
	b .L080B32BA
.L080B32B0: .4byte 0x03004514 @ IWRAM+0x4514
.L080B32B4: .4byte 0x03004634 @ IWRAM+0x4634
.L080B32B8:
	subs r0, r1, #1
.L080B32BA:
	str r0, [r2]
	b .L080B3296
.L080B32BE:
	cmp r4, #0xa
	bne .L080B3334
	ldr r0, [sp]
	cmp r0, #0
	bne .L080B32D2
	mov r1, sb
	str r0, [r1]
	movs r0, #1
	str r0, [sp]
	b .L080B3296
.L080B32D2:
	ldr r6, .L080B32F8
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	ldr r5, .L080B32FC
	ldrh r0, [r5]
	bl sub_080C8B3C
	ldr r1, [r6]
	cmp r0, r1
	bne .L080B3296
	ldr r0, [r5]
	cmp r0, #0x4f
	bne .L080B3300
	mov r1, sl
	str r1, [r5]
	str r1, [r6]
	b .L080B3296
	.byte 0x00, 0x00
.L080B32F8: .4byte 0x03004514 @ IWRAM+0x4514
.L080B32FC: .4byte 0x03004614 @ IWRAM+0x4614
.L080B3300:
	adds r0, #1
	str r0, [r5]
	mov r0, sl
	str r0, [r6]
	b .L080B3296
.L080B330A:
	mov r1, r8
	ldrh r0, [r1, #0x12]
	adds r0, r5, r0
	strh r0, [r1, #0x12]
	ldrh r0, [r1, #0x14]
	adds r0, r6, r0
	strh r0, [r1, #0x14]
	bl sub_080AE2C0
	ldr r0, .L080B332C
	ldr r1, .L080B3330
	adds r0, r0, r1
	mov r1, sl
	strh r1, [r0]
	movs r0, #1
	b .L080B3336
	.byte 0x00, 0x00
.L080B332C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B3330: .4byte 0x00000A38
.L080B3334:
	movs r0, #0
.L080B3336:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080B3348
sub_080B3348: @ 0x080B3348
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	ldr r0, .L080B3430
	ldrh r0, [r0]
	str r0, [sp, #8]
	ldr r0, .L080B3434
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	ldr r4, .L080B3438
	ldrh r0, [r4, #0x12]
	str r0, [sp, #0x10]
	ldrh r1, [r4, #0x14]
	str r1, [sp, #0x14]
	movs r2, #0
	mov sb, r2
	mov r0, sl
	bl sub_080C8B3C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #0
	mov r8, r0
	ldr r1, [sp, #4]
	cmp sb, r1
	bhs .L080B3400
.L080B3390:
	mov r0, sl
	mov r1, r8
	bl sub_080C8B10
	ldr r0, .L080B3430
	mov r2, sl
	str r2, [r0]
	ldr r0, .L080B3434
	mov r1, r8
	str r1, [r0]
	bl sub_080AE234
	movs r0, #0
	ldr r2, .L080B3438
	strh r0, [r2, #0x12]
	strh r0, [r2, #0x14]
	movs r5, #0
	ldrh r0, [r2, #0x1c]
	cmp r5, r0
	bhs .L080B33F0
	adds r6, r2, #0
.L080B33BA:
	movs r4, #0
	ldr r7, .L080B3438
	ldrh r1, [r6, #0x1a]
	cmp r4, r1
	bhs .L080B33E4
.L080B33C4:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080B2FDC
	ldr r1, [sp]
	bl sub_080B3038
	mov sb, r0
	cmp r0, #0
	bne .L080B3400
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldrh r2, [r6, #0x1a]
	cmp r4, r2
	blo .L080B33C4
.L080B33E4:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrh r7, [r7, #0x1c]
	cmp r5, r7
	blo .L080B33BA
.L080B33F0:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [sp, #4]
	cmp r8, r0
	blo .L080B3390
.L080B3400:
	ldr r0, .L080B3430
	ldr r1, [sp, #8]
	str r1, [r0]
	ldr r0, .L080B3434
	ldr r2, [sp, #0xc]
	str r2, [r0]
	ldr r0, .L080B3438
	mov r1, sp
	ldrh r1, [r1, #0x10]
	strh r1, [r0, #0x12]
	mov r2, sp
	ldrh r2, [r2, #0x14]
	strh r2, [r0, #0x14]
	bl sub_080AE234
	mov r0, sb
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L080B3430: .4byte 0x03004614 @ IWRAM+0x4614
.L080B3434: .4byte 0x03004514 @ IWRAM+0x4514
.L080B3438: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B343C
sub_080B343C: @ 0x080B343C
.L080B343C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L080B345C
	ldr r1, .L080B3458
	ldrh r0, [r1, #0x2e]
	adds r0, r0, r2
	strh r0, [r1, #0x2e]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L080B3470
	movs r0, #0
	b .L080B346E
.L080B3458: .4byte 0x03004550 @ IWRAM+0x4550
.L080B345C:
	ldr r1, .L080B3474
	ldrh r0, [r1, #0x2e]
	adds r0, r0, r2
	strh r0, [r1, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x21
	bls .L080B3470
	movs r0, #0x21
.L080B346E:
	strh r0, [r1, #0x2e]
.L080B3470:
	pop {r0}
	bx r0
.L080B3474: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B3478
sub_080B3478: @ 0x080B3478
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne .L080B34C6
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	cmp r0, #2
	bne .L080B3496
	movs r0, #2
	bl sub_080B343C
	b .L080B34A8
.L080B3496:
	ldr r0, .L080B34B8
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L080B34A8
	movs r0, #1
	bl sub_080B343C
.L080B34A8:
	ldr r0, .L080B34BC
	ldrh r0, [r0, #0x2e]
	cmp r0, #0x20
	bhi .L080B34C0
	movs r0, #0
	strh r0, [r4, #0x1c]
	b .L080B34D4
	.byte 0x00, 0x00
.L080B34B8: .4byte 0x030031BC @ IWRAM+0x31BC
.L080B34BC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B34C0:
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L080B34D4
.L080B34C6:
	ldr r0, .L080B34DC
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080B34E0
	strb r1, [r0]
	ldr r0, .L080B34E4
	strb r1, [r0]
.L080B34D4:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B34DC: .4byte 0x03000038 @ IWRAM+0x38
.L080B34E0: .4byte 0x03000039 @ IWRAM+0x39
.L080B34E4: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080B34E8
sub_080B34E8: @ 0x080B34E8
	ldr r1, .L080B34FC
	ldr r0, .L080B3500
	str r0, [r1]
	ldr r0, .L080B3504
	str r0, [r1, #4]
	ldr r0, .L080B3508
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B34FC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3500: .4byte gUnknown_081622D0
.L080B3504: .4byte 0x06016000 @ VRAM+0x16000
.L080B3508: .4byte 0x84000070

	thumb_func_start sub_080B350C
sub_080B350C: @ 0x080B350C
	push {lr}
	ldr r0, .L080B3544
	ldrh r0, [r0]
	ldr r1, .L080B3548
	ldrh r1, [r1]
	bl sub_080C8B10
	ldr r1, .L080B354C
	ldr r2, .L080B3550
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0xe8
	muls r1, r2, r1
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, .L080B3554
	str r0, [r1]
	ldr r0, .L080B3558
	str r0, [r1, #4]
	ldr r0, .L080B355C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B3544: .4byte 0x03004614 @ IWRAM+0x4614
.L080B3548: .4byte 0x03004514 @ IWRAM+0x4514
.L080B354C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B3550: .4byte 0x00000A38
.L080B3554: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3558: .4byte 0x06016000 @ VRAM+0x16000
.L080B355C: .4byte 0x84000100

	thumb_func_start sub_080B3560
sub_080B3560: @ 0x080B3560
.L080B3560:
	push {lr}
	ldr r0, .L080B3574
	ldr r0, [r0]
	cmp r0, #0x42
	beq .L080B3578
	movs r0, #0x6b
	bl sub_080C51D4
	b .L080B357E
	.byte 0x00, 0x00
.L080B3574: .4byte 0x03004614 @ IWRAM+0x4614
.L080B3578:
	movs r0, #0x6c
	bl sub_080C51D4
.L080B357E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B3584
sub_080B3584: @ 0x080B3584
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B0248
	adds r4, r0, #0
	bl sub_080B2938
	adds r5, r0, #0
	cmp r4, #2
	bne .L080B35D4
	ldr r0, .L080B35B8
	movs r1, #1
	bl VBlankTask_AddCounted
	adds r0, r6, #0
	bl sub_080B3560
	cmp r5, #2
	bne .L080B35C0
	ldr r0, .L080B35BC
	b .L080B35C6
	.byte 0x00, 0x00
.L080B35B8: .4byte sub_080AE1C4
.L080B35BC: .4byte sub_080B34E8
.L080B35C0:
	cmp r5, #3
	bne .L080B35E2
	ldr r0, .L080B35D0
.L080B35C6:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B35E2
	.byte 0x00, 0x00
.L080B35D0: .4byte sub_080B350C
.L080B35D4:
	ldr r0, .L080B3600
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0x6d
	bl sub_080C51D4
.L080B35E2:
	bl sub_080B098C
	cmp r0, #0
	bne .L080B3624
	movs r0, #0
	movs r1, #0
	movs r2, #6
	bl sub_080B3078
	cmp r0, #0
	bne .L080B3608
	ldr r0, .L080B3604
	ldr r1, [r0]
	b .L080B360A
	.byte 0x00, 0x00
.L080B3600: .4byte sub_080AE1FC
.L080B3604: .4byte 0x03003FC8 @ IWRAM+0x3FC8
.L080B3608:
	ldr r1, .L080B361C
.L080B360A:
	ldr r2, .L080B3620
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	b .L080B3634
	.byte 0x00, 0x00
.L080B361C: .4byte 0x0200F854 @ EWRAM+0xF854
.L080B3620: .4byte 0x03003150 @ IWRAM+0x3150
.L080B3624:
	ldr r2, .L080B3640
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r3, #0x20
	bl Palette_FillWithEffect
.L080B3634:
	bl Palette_MarkDirty
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080B3640: .4byte 0x03003150 @ IWRAM+0x3150

	thumb_func_start sub_080B3644
sub_080B3644: @ 0x080B3644
	push {lr}
	adds r0, r1, #0
	bl sub_080AE494
	pop {r0}
	bx r0

	thumb_func_start sub_080B3650
sub_080B3650: @ 0x080B3650
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080B3660
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	beq .L080B3664
	movs r0, #0
	b .L080B3666
.L080B3660: .4byte 0x03004550 @ IWRAM+0x4550
.L080B3664:
	movs r0, #1
.L080B3666:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_080B366C
sub_080B366C: @ 0x080B366C
	push {r4, lr}
	ldr r1, .L080B3698
	movs r0, #0
	movs r2, #4
	bl sub_080B3078
	adds r4, r0, #0
	cmp r4, #1
	bne .L080B36AA
	movs r0, #0xae
	bl Flag_Test
	cmp r0, #0
	bne .L080B36A4
	movs r0, #1
	bl PalFade_FadeToBlack
	ldr r1, .L080B369C
	str r0, [r1]
	ldr r0, .L080B36A0
	strh r4, [r0, #0x34]
	b .L080B36AE
.L080B3698: .4byte 0x0000FFFF
.L080B369C: .4byte 0x0300452C @ IWRAM+0x452C
.L080B36A0: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080B36A4:
	bl sub_080B0620
	b .L080B36AE
.L080B36AA:
	bl sub_080B0620
.L080B36AE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080B36B4
sub_080B36B4: @ 0x080B36B4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r6, .L080B3738
	ldrh r0, [r6]
	ldr r5, .L080B373C
	ldrh r1, [r5]
	bl sub_080C8B10
	adds r4, r0, #0
	ldr r1, .L080B3740
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080B3744
	movs r0, #0
	bl sub_080B2EFC
	movs r1, #0x20
	bl sub_080B3038
	adds r1, r0, #0
	cmp r1, #0
	beq .L080B36F2
	ldr r0, .L080B3748
	ldrh r1, [r1, #2]
	ldr r2, .L080B374C
	adds r0, r0, r2
	movs r2, #0
	strh r1, [r0]
	ldr r0, .L080B3750
	str r2, [r0]
.L080B36F2:
	ldr r2, .L080B3750
	ldr r0, .L080B3748
	ldr r1, .L080B374C
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xe8
	adds r3, r1, #0
	muls r3, r0, r3
	adds r0, r4, #0
	adds r0, #0xd8
	adds r0, r0, r3
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	bne .L080B3722
	ldr r1, .L080B3754
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r0, r0, r3
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	beq .L080B3758
.L080B3722:
	ldr r0, [r6]
	ldr r1, [r5]
	bl sub_080ADCCC
	bl sub_080AE234
	bl sub_080AD7F0
	movs r0, #0
	b .L080B3796
	.byte 0x00, 0x00
.L080B3738: .4byte 0x03004614 @ IWRAM+0x4614
.L080B373C: .4byte 0x03004514 @ IWRAM+0x4514
.L080B3740: .4byte 0x0300000E @ IWRAM+0xE
.L080B3744: .4byte 0x0000FFFF
.L080B3748: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080B374C: .4byte 0x00000A38
.L080B3750: .4byte 0x03003BB4 @ IWRAM+0x3BB4
.L080B3754: .4byte 0x0300462C @ IWRAM+0x462C
.L080B3758:
	ldr r0, [r6]
	ldr r1, [r5]
	bl sub_080ADCCC
	bl sub_080AE234
	ldr r0, .L080B37A0
	ldr r1, [r0]
	ldr r5, .L080B37A4
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
	ldr r0, .L080B37A8
	ldr r1, [r0]
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r5, r0
	str r4, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	movs r0, #1
.L080B3796:
	strh r0, [r7, #0x1c]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B37A0: .4byte 0x03004630 @ IWRAM+0x4630
.L080B37A4: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B37A8: .4byte 0x03004510 @ IWRAM+0x4510

	thumb_func_start sub_080B37AC
sub_080B37AC: @ 0x080B37AC
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne .L080B37C0
	ldr r0, .L080B37BC
	strh r1, [r0]
	b .L080B37E4
	.byte 0x00, 0x00
.L080B37BC: .4byte 0x03003BBC @ IWRAM+0x3BBC
.L080B37C0:
	ldr r0, .L080B37D0
	ldrh r1, [r0]
	ldr r0, .L080B37D4
	cmp r1, r0
	bne .L080B37D8
	movs r0, #1
	b .L080B37E2
	.byte 0x00, 0x00
.L080B37D0: .4byte 0x03003BBC @ IWRAM+0x3BBC
.L080B37D4: .4byte 0x0000FFFF
.L080B37D8:
	ldr r0, .L080B37EC
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #0
.L080B37E2:
	strh r0, [r4, #0x1c]
.L080B37E4:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B37EC: .4byte sub_080AE0BC

	thumb_func_start sub_080B37F0
sub_080B37F0: @ 0x080B37F0
	push {r4, lr}
	adds r4, r1, #0
	ldr r0, .L080B3810
	ldrh r0, [r0, #2]
	bl sub_080B02A0
	cmp r4, #0
	bne .L080B380A
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
.L080B380A:
	pop {r4}
	pop {r0}
	bx r0
.L080B3810: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B3814
sub_080B3814: @ 0x080B3814
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	movs r0, #1
	movs r1, #1
	movs r2, #0
	bl sub_080AF8D0
	adds r4, r0, #0
	cmp r4, #0
	bne .L080B3860
	ldr r0, .L080B3850
	bl sub_080AE494
	bl sub_080B05A4
	ldr r5, .L080B3854
	strh r4, [r5, #0x2e]
	movs r0, #4
	bl Field_SetState
	movs r0, #0
	movs r1, #1
	bl sub_080B2EFC
	cmp r0, #0
	bne .L080B3858
	adds r0, r5, #0
	adds r0, #0x46
	strh r6, [r0]
	b .L080B3860
.L080B3850: .4byte sub_080B0158
.L080B3854: .4byte 0x03004550 @ IWRAM+0x4550
.L080B3858:
	adds r1, r5, #0
	adds r1, #0x46
	movs r0, #1
	strh r0, [r1]
.L080B3860:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B3868
sub_080B3868: @ 0x080B3868
	ldr r0, .L080B3874
	adds r0, #0x5e
	movs r1, #0
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080B3874: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B3878
sub_080B3878: @ 0x080B3878
.L080B3878:
	push {lr}
	lsls r0, r0, #0x10
	ldr r2, .L080B3898
	cmp r0, #0
	bne .L080B3884
	ldr r2, .L080B389C
.L080B3884:
	ldr r1, .L080B38A0
	adds r0, r2, #0
	bl Task_Create
	ldr r2, .L080B38A4
	movs r1, #0
	strh r1, [r2, #0x2e]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B3898: .4byte gUnknown_081625D0
.L080B389C: .4byte gUnknown_08162490
.L080B38A0: .4byte 0x0000FFFF
.L080B38A4: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B38A8
sub_080B38A8: @ 0x080B38A8
.L080B38A8:
	push {r4, r5, lr}
	sub sp, #0xc
	movs r5, #0
	ldr r0, .L080B38C4
	ldrh r0, [r0, #0x1e]
	cmp r0, #0x1c
	bls .L080B38B8
	b .L080B3AC4
.L080B38B8:
	lsls r0, r0, #2
	ldr r1, .L080B38C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L080B38C4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B38C8: .4byte gUnknown_080B38CC
	.global gUnknown_080B38CC
gUnknown_080B38CC:
.L080B38CC: @ jump table
	.4byte .L080B3940
	.4byte .L080B3AC4
	.4byte .L080B398C
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B39A8
	.4byte .L080B39F2
	.4byte .L080B3A3C
	.4byte .L080B3A40
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3AC4
	.4byte .L080B3A60
.L080B3940:
	bl sub_080C14FC
	ldr r1, .L080B3978
	movs r0, #0x1c
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #1
	movs r3, #0
	bl Tilemap_FillRect
	add r1, sp, #8
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L080B397C
	add r0, sp, #8
	str r0, [r1]
	ldr r0, .L080B3980
	str r0, [r1, #4]
	ldr r0, .L080B3984
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080B3988
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B3ACC
.L080B3978: .4byte 0x02000000 @ EWRAM
.L080B397C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3980: .4byte 0x03002EB0 @ IWRAM+0x2EB0
.L080B3984: .4byte 0x81000080
.L080B3988: .4byte sub_080B41F8
.L080B398C:
	movs r0, #0
	bl sub_080B3EA4
	cmp r0, #1
	beq .L080B3998
	b .L080B3ACC
.L080B3998:
	ldr r1, .L080B39A4
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	strh r0, [r1, #0x1e]
	b .L080B3ACC
	.byte 0x00, 0x00
.L080B39A4: .4byte 0x03004550 @ IWRAM+0x4550
.L080B39A8:
	bl sub_080B0778
	ldr r0, .L080B39BC
	ldrh r1, [r0, #0x1e]
	adds r1, #1
	strh r1, [r0, #0x1e]
	ldr r2, .L080B39C0
	movs r1, #0
	b .L080B39D0
	.byte 0x00, 0x00
.L080B39BC: .4byte 0x03004550 @ IWRAM+0x4550
.L080B39C0: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L080B39C4:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r2, #1
	cmp r1, #0x1f
	bhi .L080B39D6
.L080B39D0:
	ldrb r0, [r2]
	cmp r0, #0
	beq .L080B39C4
.L080B39D6:
	cmp r1, #0x20
	bne .L080B3ACC
	movs r0, #0
	movs r1, #0x80
	movs r2, #1
	bl PalFade_FadeRangeInFromBlack
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xd0
	movs r2, #1
	bl PalFade_FadeRangeInFromBlack
	b .L080B3ACC
.L080B39F2:
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080B3ACC
	ldr r1, .L080B3A30
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	movs r2, #0
	strh r0, [r1, #0x1e]
	ldr r0, .L080B3A34
	strh r2, [r0, #0x34]
	ldr r4, .L080B3A38
	adds r0, r4, #0
	bl Flag_Test
	cmp r0, #0
	beq .L080B3ACC
	movs r0, #0x81
	lsls r0, r0, #1
	bl Flag_Clear
	movs r0, #0x83
	lsls r0, r0, #1
	bl Flag_Clear
	adds r0, r4, #0
	bl Flag_Clear
	b .L080B3ACC
.L080B3A30: .4byte 0x03004550 @ IWRAM+0x4550
.L080B3A34: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080B3A38: .4byte 0x00000105
.L080B3A3C:
	movs r5, #1
	b .L080B3ACC
.L080B3A40:
	bl sub_080B092C
	cmp r0, #0
	bne .L080B3ACC
	bl sub_080C14FC
	ldr r1, .L080B3A5C
	movs r0, #0x14
	strh r0, [r1, #0x1e]
	movs r0, #0
	bl sub_080B7530
	b .L080B3ACC
	.byte 0x00, 0x00
.L080B3A5C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B3A60:
	movs r0, #1
	bl sub_080C3818
	movs r0, #0
	bl sub_080B0204
	cmp r0, #0
	bne .L080B3AA0
	movs r0, #1
	bl sub_080B0204
	cmp r0, #0
	bne .L080B3AA0
	movs r0, #3
	bl sub_080B0204
	cmp r0, #0
	bne .L080B3AA0
	ldr r4, .L080B3A9C
	ldrh r0, [r4, #2]
	bl sub_080B1A1C
	strh r0, [r4, #2]
	ldrh r0, [r4, #0xa]
	ldrh r1, [r4, #2]
	movs r2, #3
	bl sub_080B2030
	b .L080B3ABA
	.byte 0x00, 0x00
.L080B3A9C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B3AA0:
	bl sub_080B05A4
	movs r0, #0x1f
	bl Field_SetState
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl sub_080B2840
	ldr r1, .L080B3AC0
	movs r0, #0
	strh r0, [r1, #0x1e]
.L080B3ABA:
	movs r5, #1
	rsbs r5, r5, #0
	b .L080B3ACC
.L080B3AC0: .4byte 0x03004550 @ IWRAM+0x4550
.L080B3AC4:
	ldr r0, .L080B3AD8
	movs r1, #1
	bl VBlankTask_AddCounted
.L080B3ACC:
	adds r0, r5, #0
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080B3AD8: .4byte sub_080B41F8

	thumb_func_start sub_080B3ADC
sub_080B3ADC: @ 0x080B3ADC
	ldr r0, .L080B3AF0
	ldr r1, .L080B3AF4
	str r0, [r1]
	ldr r0, .L080B3AF8
	str r0, [r1, #4]
	ldr r0, .L080B3AFC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B3AF0: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B3AF4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3AF8: .4byte 0x06004040 @ VRAM+0x4040
.L080B3AFC: .4byte 0x84000400

	thumb_func_start sub_080B3B00
sub_080B3B00: @ 0x080B3B00
	ldr r2, .L080B3B24
	ldr r0, .L080B3B28
	str r2, [r0]
	ldr r1, .L080B3B2C
	str r1, [r0, #4]
	ldr r1, .L080B3B30
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	movs r1, #0xfc
	lsls r1, r1, #4
	adds r2, r2, r1
	str r2, [r0]
	ldr r1, .L080B3B34
	str r1, [r0, #4]
	ldr r1, .L080B3B38
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	bx lr
.L080B3B24: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B3B28: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3B2C: .4byte 0x06005040 @ VRAM+0x5040
.L080B3B30: .4byte 0x840003F0
.L080B3B34: .4byte 0x06008040 @ VRAM+0x8040
.L080B3B38: .4byte 0x84000010

	thumb_func_start sub_080B3B3C
sub_080B3B3C: @ 0x080B3B3C
	ldr r0, .L080B3B50
	ldr r1, .L080B3B54
	str r0, [r1]
	ldr r0, .L080B3B58
	str r0, [r1, #4]
	ldr r0, .L080B3B5C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080B3B50: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B3B54: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3B58: .4byte 0x06008080 @ VRAM+0x8080
.L080B3B5C: .4byte 0x84000400

	thumb_func_start sub_080B3B60
sub_080B3B60: @ 0x080B3B60
	push {lr}
	ldr r2, .L080B3B74
	ldr r0, .L080B3B78
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B3B84
	ldr r1, .L080B3B7C
	str r2, [r1]
	ldr r0, .L080B3B80
	b .L080B3B8A
.L080B3B74: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B3B78: .4byte 0x03003BA0 @ IWRAM+0x3BA0
.L080B3B7C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3B80: .4byte 0x06009080 @ VRAM+0x9080
.L080B3B84:
	ldr r1, .L080B3B98
	str r2, [r1]
	ldr r0, .L080B3B9C
.L080B3B8A:
	str r0, [r1, #4]
	ldr r0, .L080B3BA0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B3B98: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3B9C: .4byte 0x06008E00 @ VRAM+0x8E00
.L080B3BA0: .4byte 0x84000400

	thumb_func_start sub_080B3BA4
sub_080B3BA4: @ 0x080B3BA4
	push {lr}
	ldr r2, .L080B3BB8
	ldr r0, .L080B3BBC
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B3BC8
	ldr r1, .L080B3BC0
	str r2, [r1]
	ldr r0, .L080B3BC4
	b .L080B3BCE
.L080B3BB8: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B3BBC: .4byte 0x03003BA0 @ IWRAM+0x3BA0
.L080B3BC0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3BC4: .4byte 0x0600A080 @ VRAM+0xA080
.L080B3BC8:
	ldr r1, .L080B3BDC
	str r2, [r1]
	ldr r0, .L080B3BE0
.L080B3BCE:
	str r0, [r1, #4]
	ldr r0, .L080B3BE4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B3BDC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3BE0: .4byte 0x06009E00 @ VRAM+0x9E00
.L080B3BE4: .4byte 0x84000400

	thumb_func_start sub_080B3BE8
sub_080B3BE8: @ 0x080B3BE8
	push {lr}
	ldr r2, .L080B3C00
	ldr r0, .L080B3C04
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B3C14
	ldr r1, .L080B3C08
	str r2, [r1]
	ldr r0, .L080B3C0C
	str r0, [r1, #4]
	ldr r0, .L080B3C10
	b .L080B3C1E
.L080B3C00: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B3C04: .4byte 0x03003BA0 @ IWRAM+0x3BA0
.L080B3C08: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3C0C: .4byte 0x0600B080 @ VRAM+0xB080
.L080B3C10: .4byte 0x840002C0
.L080B3C14:
	ldr r1, .L080B3C28
	str r2, [r1]
	ldr r0, .L080B3C2C
	str r0, [r1, #4]
	ldr r0, .L080B3C30
.L080B3C1E:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B3C28: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3C2C: .4byte 0x0600AE00 @ VRAM+0xAE00
.L080B3C30: .4byte 0x84000360

	thumb_func_start sub_080B3C34
sub_080B3C34: @ 0x080B3C34
.L080B3C34:
	push {lr}
	adds r2, r1, #0
	ldr r1, .L080B3C50
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L080B3C58
	cmp r2, #0
	bne .L080B3C54
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080B3C58
.L080B3C50: .4byte gUnknown_081625D4
.L080B3C54:
	bl _call_via_r0
.L080B3C58:
	pop {r0}
	bx r0

	thumb_func_start sub_080B3C5C
sub_080B3C5C: @ 0x080B3C5C
.L080B3C5C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	ldr r7, .L080B3CA0
	ldrh r0, [r7]
	bl sub_080C5EF0
	mov r8, r0
	ldr r0, .L080B3CA4
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B3D24
	ldr r5, .L080B3CA8
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #8
	mov sl, r0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq .L080B3CB8
	ldr r0, .L080B3CAC
	ands r0, r1
	strh r0, [r5]
	ldr r0, .L080B3CB0
	ldr r2, .L080B3CB4
	adds r1, r0, r2
	b .L080B3CE0
	.byte 0x00, 0x00
.L080B3CA0: .4byte 0x03004534 @ IWRAM+0x4534
.L080B3CA4: .4byte 0x03003BA0 @ IWRAM+0x3BA0
.L080B3CA8: .4byte 0x03003BAC @ IWRAM+0x3BAC
.L080B3CAC: .4byte 0x00007FFF
.L080B3CB0: .4byte 0x0200BFC8 @ EWRAM+0xBFC8
.L080B3CB4: .4byte 0xFFFFF000
.L080B3CB8:
	ldrh r0, [r7]
	ldrh r1, [r5]
	bl sub_080C5F04
	adds r4, r0, #0
	cmp r4, #0
	beq .L080B3D18
	str r6, [sp]
	ldr r6, .L080B3CF4
	ldr r2, .L080B3CF8
	mov r0, sp
	adds r1, r6, #0
	bl CpuFastSet
	mov r1, r8
	ldr r0, [r1]
	cmp r0, #1
	bne .L080B3CFC
	adds r0, r4, #0
	adds r1, r6, #0
.L080B3CE0:
	bl LZ77UnCompWram
	ldrh r0, [r5]
	mov r1, sb
	bl sub_080B3C34
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b .L080B3E28
.L080B3CF4: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B3CF8: .4byte 0x01000400
.L080B3CFC:
	cmp r0, #2
	beq .L080B3D02
	b .L080B3E28
.L080B3D02:
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r6, r2
	adds r0, r4, #0
	bl HuffUnComp
	ldrh r1, [r5]
	mov r0, sl
	orrs r0, r1
	strh r0, [r5]
	b .L080B3E28
.L080B3D18:
	ldr r1, .L080B3D20
	adds r0, r1, #0
	strh r0, [r5]
	b .L080B3E28
.L080B3D20: .4byte 0x0000FFFF
.L080B3D24:
	ldr r4, .L080B3D58
	ldrh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #8
	mov sl, r2
	mov r0, sl
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq .L080B3D80
	ldr r0, .L080B3D5C
	ands r0, r1
	strh r0, [r4]
	ldr r0, .L080B3D60
	ldr r2, .L080B3D64
	adds r1, r0, r2
	bl LZ77UnCompWram
	ldrh r0, [r4]
	cmp r0, #7
	bhi .L080B3D68
	mov r1, sb
	bl sub_080B3C34
	b .L080B3D72
.L080B3D58: .4byte 0x03003BAC @ IWRAM+0x3BAC
.L080B3D5C: .4byte 0x00007FFF
.L080B3D60: .4byte 0x0200BFC8 @ EWRAM+0xBFC8
.L080B3D64: .4byte 0xFFFFF000
.L080B3D68:
	ldrh r0, [r4]
	subs r0, #5
	mov r1, sb
	bl sub_080B3C34
.L080B3D72:
	ldr r1, .L080B3D7C
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b .L080B3E28
.L080B3D7C: .4byte 0x03003BAC @ IWRAM+0x3BAC
.L080B3D80:
	ldrh r0, [r7]
	ldrh r1, [r4]
	bl sub_080C5F04
	adds r5, r0, #0
	cmp r5, #0
	beq .L080B3E18
	str r6, [sp]
	ldr r6, .L080B3DC0
	ldr r2, .L080B3DC4
	mov r0, sp
	adds r1, r6, #0
	bl CpuFastSet
	ldrh r0, [r4]
	cmp r0, #7
	bhi .L080B3DE0
	mov r1, r8
	ldr r0, [r1]
	cmp r0, #1
	bne .L080B3DC8
	adds r0, r5, #0
	adds r1, r6, #0
	bl LZ77UnCompWram
	ldrh r0, [r4]
	mov r1, sb
	bl sub_080B3C34
	ldrh r0, [r4]
	adds r0, #1
	b .L080B3E26
.L080B3DC0: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080B3DC4: .4byte 0x01000400
.L080B3DC8:
	cmp r0, #2
	bne .L080B3E28
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r6, r2
	adds r0, r5, #0
	bl HuffUnComp
	ldrh r1, [r4]
	mov r0, sl
	orrs r0, r1
	b .L080B3E26
.L080B3DE0:
	mov r1, r8
	ldr r0, [r1]
	cmp r0, #1
	bne .L080B3E00
	adds r0, r5, #0
	adds r1, r6, #0
	bl LZ77UnCompWram
	ldrh r0, [r4]
	subs r0, #5
	mov r1, sb
	bl sub_080B3C34
	ldrh r0, [r4]
	adds r0, #1
	b .L080B3E26
.L080B3E00:
	cmp r0, #2
	bne .L080B3E28
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r6, r2
	adds r0, r5, #0
	bl HuffUnComp
	ldrh r1, [r4]
	mov r0, sl
	orrs r0, r1
	b .L080B3E26
.L080B3E18:
	ldrh r0, [r4]
	cmp r0, #7
	bhi .L080B3E22
	movs r0, #8
	b .L080B3E26
.L080B3E22:
	ldr r1, .L080B3E38
	adds r0, r1, #0
.L080B3E26:
	strh r0, [r4]
.L080B3E28:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B3E38: .4byte 0x0000FFFF

	thumb_func_start sub_080B3E3C
sub_080B3E3C: @ 0x080B3E3C
.L080B3E3C:
	push {r4, lr}
	ldr r2, .L080B3E6C
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r2]
	ldr r0, .L080B3E70
	movs r1, #0
	strh r1, [r0]
	ldr r4, .L080B3E74
	strh r1, [r4]
	ldr r0, .L080B3E78
	ldrh r0, [r0]
	movs r1, #8
	bl sub_080C5F04
	cmp r0, #0
	beq .L080B3E66
	movs r0, #1
	strh r0, [r4]
.L080B3E66:
	pop {r4}
	pop {r0}
	bx r0
.L080B3E6C: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080B3E70: .4byte 0x03003BAC @ IWRAM+0x3BAC
.L080B3E74: .4byte 0x03003BA0 @ IWRAM+0x3BA0
.L080B3E78: .4byte 0x03004534 @ IWRAM+0x4534

	thumb_func_start sub_080B3E7C
sub_080B3E7C: @ 0x080B3E7C
.L080B3E7C:
	push {lr}
	bl sub_080C153C
	bl sub_080B3E3C
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B3E8C
sub_080B3E8C: @ 0x080B3E8C
.L080B3E8C:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L080B3E9C
	ands r0, r1
	strh r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080B3E9C: .4byte 0x0000F7FF

	thumb_func_start sub_080B3EA0
sub_080B3EA0: @ 0x080B3EA0
.L080B3EA0:
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080B3EA4
sub_080B3EA4: @ 0x080B3EA4
.L080B3EA4:
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080B3EBC
	ldrh r1, [r0]
	ldr r0, .L080B3EC0
	cmp r1, r0
	bne .L080B3EC4
	bl sub_080B3EA0
	movs r0, #1
	b .L080B3ECC
	.byte 0x00, 0x00
.L080B3EBC: .4byte 0x03003BAC @ IWRAM+0x3BAC
.L080B3EC0: .4byte 0x0000FFFF
.L080B3EC4:
	adds r0, r2, #0
	bl sub_080B3C5C
	movs r0, #0
.L080B3ECC:
	pop {r1}
	bx r1

	thumb_func_start sub_080B3ED0
sub_080B3ED0: @ 0x080B3ED0
.L080B3ED0:
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, .L080B3F18
	ldrh r0, [r0]
	bl sub_080C5EF0
	adds r4, r0, #0
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	beq .L080B3F0E
	movs r5, #0x50
	movs r0, #0xca
	lsls r0, r0, #1
	cmp r1, r0
	bne .L080B3EFA
	movs r0, #0x37
	bl Flag_Test
	cmp r0, #0
	beq .L080B3EFA
	movs r5, #0x20
.L080B3EFA:
	ldr r1, [r4, #0x4c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r2, r5, #0
	movs r3, #5
	bl sub_080C4618
.L080B3F0E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080B3F18: .4byte 0x03004534 @ IWRAM+0x4534

	thumb_func_start sub_080B3F1C
sub_080B3F1C: @ 0x080B3F1C
.L080B3F1C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r6, .L080B3F48
	ldrh r0, [r6]
	bl sub_080C5EF0
	mov sb, r0
	ldr r0, [r0]
	cmp r0, #0
	bne .L080B3F68
	ldr r0, .L080B3F4C
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B3F58
	ldr r1, .L080B3F50
	ldr r0, .L080B3F54
	str r0, [r1]
	b .L080B40B8
.L080B3F48: .4byte 0x03004534 @ IWRAM+0x4534
.L080B3F4C: .4byte 0x03003BA0 @ IWRAM+0x3BA0
.L080B3F50: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3F54: .4byte gUnknown_081C25F0
.L080B3F58:
	ldr r1, .L080B3F60
	ldr r0, .L080B3F64
	str r0, [r1]
	b .L080B40B8
.L080B3F60: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3F64: .4byte gUnknown_081C32F4
.L080B3F68:
	ldr r0, .L080B3FD4
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080B4038
	ldrh r0, [r6]
	movs r1, #0
	bl sub_080C5F40
	adds r3, r0, #0
	ldr r7, .L080B3FD8
	ldrh r1, [r6]
	adds r0, r1, #0
	subs r0, #0xd9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L080B3FE8
	movs r0, #8
	mov r8, r0
	cmp r1, #0xda
	bne .L080B3F96
	movs r1, #7
	mov r8, r1
.L080B3F96:
	ldr r1, .L080B3FDC
	ldr r0, .L080B3FE0
	str r0, [r1]
	str r7, [r1, #4]
	ldr r0, .L080B3FE4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
	mov sl, r7
	movs r5, #0xf
.L080B3FAA:
	movs r2, #0
	adds r4, r0, #1
	lsls r0, r0, #6
	adds r1, r0, r7
.L080B3FB2:
	ldrb r0, [r3]
	adds r3, #1
	ands r0, r5
	add r0, r8
	lsls r0, r0, #0xc
	ldrh r6, [r1]
	adds r0, r0, r6
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #0x1d
	bls .L080B3FB2
	adds r0, r4, #0
	cmp r0, #0x19
	bls .L080B3FAA
	b .L080B4024
	.byte 0x00, 0x00
.L080B3FD4: .4byte 0x03003BA0 @ IWRAM+0x3BA0
.L080B3FD8: .4byte 0x02000000 @ EWRAM
.L080B3FDC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B3FE0: .4byte gUnknown_081C2C74
.L080B3FE4: .4byte 0x84000400
.L080B3FE8:
	ldr r1, .L080B402C
	ldr r0, .L080B4030
	str r0, [r1]
	str r7, [r1, #4]
	ldr r0, .L080B4034
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
	mov sl, r7
	movs r5, #0xf
.L080B3FFC:
	movs r2, #0
	adds r4, r0, #1
	lsls r1, r0, #6
	adds r0, r7, #2
	adds r1, r1, r0
.L080B4006:
	ldrb r0, [r3]
	adds r3, #1
	ands r0, r5
	adds r0, #8
	lsls r0, r0, #0xc
	ldrh r6, [r1]
	adds r0, r0, r6
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #0x1b
	bls .L080B4006
	adds r0, r4, #0
	cmp r0, #0x19
	bls .L080B3FFC
.L080B4024:
	ldr r1, .L080B402C
	mov r7, sl
	str r7, [r1]
	b .L080B40B8
.L080B402C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B4030: .4byte gUnknown_081C25F4
.L080B4034: .4byte 0x84000400
.L080B4038:
	ldrh r0, [r6]
	movs r1, #0
	bl sub_080C5F40
	adds r5, r0, #0
	ldrh r0, [r6]
	movs r1, #1
	bl sub_080C5F40
	adds r4, r0, #0
	ldr r0, .L080B40D8
	mov r8, r0
	ldr r1, .L080B40DC
	ldr r0, .L080B40E0
	str r0, [r1]
	mov r7, r8
	str r7, [r1, #4]
	ldr r0, .L080B40E4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0
	mov sl, r8
	movs r0, #0xf
	mov ip, r0
.L080B4068:
	movs r6, #0
	lsls r0, r2, #5
	adds r1, r2, #1
	str r1, [sp]
	adds r0, #0x1c
	lsls r2, r2, #6
	mov r1, r8
	adds r1, #2
	adds r2, r2, r1
	lsls r0, r0, #1
	mov r7, r8
	adds r3, r0, r7
.L080B4080:
	ldrb r0, [r5]
	adds r5, #1
	ldrb r1, [r4]
	adds r4, #1
	mov r7, ip
	ands r0, r7
	adds r0, #8
	ands r1, r7
	adds r1, #8
	lsls r0, r0, #0xc
	ldrh r7, [r2]
	adds r0, r0, r7
	strh r0, [r2]
	lsls r1, r1, #0xc
	ldrh r0, [r3]
	adds r1, r1, r0
	strh r1, [r3]
	subs r3, #2
	adds r2, #2
	adds r6, #1
	cmp r6, #0xd
	bls .L080B4080
	ldr r2, [sp]
	cmp r2, #0x19
	bls .L080B4068
	ldr r1, .L080B40DC
	mov r6, sl
	str r6, [r1]
.L080B40B8:
	ldr r0, .L080B40E8
	str r0, [r1, #4]
	ldr r0, .L080B40E4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r7, .L080B40EC
	ldrh r0, [r7]
	cmp r0, #1
	bne .L080B40F8
	ldr r0, .L080B40F0
	ldrh r0, [r0]
	ldr r1, .L080B40F4
	strh r0, [r1]
	movs r0, #0
	strh r0, [r7]
	b .L080B4120
.L080B40D8: .4byte 0x02000000 @ EWRAM
.L080B40DC: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B40E0: .4byte gUnknown_081C32F8
.L080B40E4: .4byte 0x84000400
.L080B40E8: .4byte 0x06003000 @ VRAM+0x3000
.L080B40EC: .4byte 0x03004608 @ IWRAM+0x4608
.L080B40F0: .4byte 0x03004600 @ IWRAM+0x4600
.L080B40F4: .4byte 0x0300000E @ IWRAM+0xE
.L080B40F8:
	ldr r0, .L080B410C
	ldr r1, [r0]
	ldr r0, .L080B4110
	cmp r1, r0
	bne .L080B4118
	movs r0, #0x50
	ldr r6, .L080B4114
	strh r0, [r6]
	b .L080B4120
	.byte 0x00, 0x00
.L080B410C: .4byte 0x030020E4 @ IWRAM+0x20E4
.L080B4110: .4byte sub_0815C380
.L080B4114: .4byte 0x0300000E @ IWRAM+0xE
.L080B4118:
	mov r7, sb
	ldr r0, [r7, #0x58]
	ldr r1, .L080B4138
	strh r0, [r1]
.L080B4120:
	ldr r6, .L080B413C
	ldrh r0, [r6]
	bl sub_080BDF3C
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080B4138: .4byte 0x0300000E @ IWRAM+0xE
.L080B413C: .4byte 0x03004534 @ IWRAM+0x4534

	thumb_func_start sub_080B4140
sub_080B4140: @ 0x080B4140
.L080B4140:
	push {r4, lr}
	sub sp, #8
	ldr r4, .L080B4168
	ldrh r0, [r4]
	bl sub_080C5F60
	adds r1, r0, #0
	ldrh r0, [r4]
	cmp r0, #0x77
	beq .L080B4188
	cmp r0, #0xda
	bne .L080B4170
	ldr r2, .L080B416C
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	b .L080B419C
.L080B4168: .4byte 0x03004534 @ IWRAM+0x4534
.L080B416C: .4byte 0x03002A90 @ IWRAM+0x2A90
.L080B4170:
	ldr r2, .L080B4184
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	b .L080B419C
	.byte 0x00, 0x00
.L080B4184: .4byte 0x03002AB0 @ IWRAM+0x2AB0
.L080B4188:
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, .L080B41A4
	add r0, sp, #4
	str r0, [r1]
	ldr r0, .L080B41A8
	str r0, [r1, #4]
	ldr r0, .L080B41AC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
.L080B419C:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
.L080B41A4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B41A8: .4byte 0x03002AB0 @ IWRAM+0x2AB0
.L080B41AC: .4byte 0x85000040

	thumb_func_start sub_080B41B0
sub_080B41B0: @ 0x080B41B0
.L080B41B0:
	push {lr}
	bl sub_080B4140
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r0]
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080B41CC
sub_080B41CC: @ 0x080B41CC
.L080B41CC:
	ldr r1, .L080B41E8
	ldr r2, .L080B41EC
	adds r0, r2, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, .L080B41F0
	ands r0, r1
	strh r0, [r2]
	ldr r1, .L080B41F4
	movs r0, #0
	strh r0, [r1]
	bx lr
.L080B41E8: .4byte 0x0400000E @ REG_BG3CNT
.L080B41EC: .4byte 0x00008607
.L080B41F0: .4byte 0x0000F7FF
.L080B41F4: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080B41F8
sub_080B41F8: @ 0x080B41F8
	push {lr}
	sub sp, #8
	ldr r0, .L080B4218
	ldrh r0, [r0]
	bl sub_080C5EF0
	ldr r0, .L080B421C
	ldrh r0, [r0, #0x1e]
	cmp r0, #0x1b
	bls .L080B420E
	b .L080B4362
.L080B420E:
	lsls r0, r0, #2
	ldr r1, .L080B4220
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080B4218: .4byte 0x03004534 @ IWRAM+0x4534
.L080B421C: .4byte 0x03004550 @ IWRAM+0x4550
.L080B4220: .4byte gUnknown_080B4224
	.global gUnknown_080B4224
gUnknown_080B4224:
.L080B4224: @ jump table
	.4byte .L080B4294
	.4byte .L080B429A
	.4byte .L080B4362
	.4byte .L080B42A0
	.4byte .L080B42A6
	.4byte .L080B42AC
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4362
	.4byte .L080B4342
	.4byte .L080B42B2
	.4byte .L080B42B8
	.4byte .L080B42F8
	.4byte .L080B4320
	.4byte .L080B433C
	.4byte .L080B4342
	.4byte .L080B4348
.L080B4294:
	bl sub_080B3E7C
	b .L080B4362
.L080B429A:
	bl sub_080B3E8C
	b .L080B4362
.L080B42A0:
	bl sub_080B3ED0
	b .L080B4362
.L080B42A6:
	bl sub_080B3F1C
	b .L080B4362
.L080B42AC:
	bl sub_080B41B0
	b .L080B4362
.L080B42B2:
	bl sub_080B41CC
	b .L080B4362
.L080B42B8:
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, .L080B42E0
	add r0, sp, #4
	str r0, [r1]
	ldr r0, .L080B42E4
	str r0, [r1, #4]
	ldr r0, .L080B42E8
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L080B42EC
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, .L080B42F0
	str r0, [r1, #4]
	ldr r0, .L080B42F4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b .L080B4362
	.byte 0x00, 0x00
.L080B42E0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080B42E4: .4byte 0x02028074 @ EWRAM+0x28074
.L080B42E8: .4byte 0x85000008
.L080B42EC: .4byte 0x03003B94 @ IWRAM+0x3B94
.L080B42F0: .4byte 0x06004000 @ VRAM+0x4000
.L080B42F4: .4byte 0x84000800
.L080B42F8:
	ldr r0, .L080B4318
	ldr r1, [r0]
	ldr r2, .L080B431C
	ldrh r0, [r1]
	strh r0, [r2]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r2, r2, r3
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	b .L080B4362
	.byte 0x00, 0x00
.L080B4318: .4byte 0x03004630 @ IWRAM+0x4630
.L080B431C: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080B4320:
	ldr r0, .L080B4334
	ldr r1, [r0]
	ldr r2, .L080B4338
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	b .L080B4362
.L080B4334: .4byte 0x03004510 @ IWRAM+0x4510
.L080B4338: .4byte 0x03002B50 @ IWRAM+0x2B50
.L080B433C:
	bl sub_080ADF64
	b .L080B4362
.L080B4342:
	bl sub_080C153C
	b .L080B4362
.L080B4348:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, .L080B4370
	ldr r0, [r2]
	ldr r1, .L080B4374
	ands r0, r1
	str r0, [r2]
.L080B4362:
	ldr r1, .L080B4378
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	strh r0, [r1, #0x1e]
	add sp, #8
	pop {r0}
	bx r0
.L080B4370: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080B4374: .4byte 0xFFFF7FFF
.L080B4378: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080B437C
sub_080B437C: @ 0x080B437C
.L080B437C:
	push {lr}
	sub sp, #8
	bl sub_080C14FC
	ldr r1, .L080B43BC
	movs r0, #0x1c
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #1
	movs r3, #0
	bl Tilemap_FillRect
	bl sub_080B3E7C
	bl sub_080B3E8C
.L080B43A0:
	movs r0, #1
	bl sub_080B3EA4
	cmp r0, #1
	bne .L080B43A0
	bl sub_080B3ED0
	bl sub_080B3F1C
	bl sub_080B41B0
	add sp, #8
	pop {r0}
	bx r0
.L080B43BC: .4byte 0x02000000 @ EWRAM

	thumb_func_start sub_080B43C0
sub_080B43C0: @ 0x080B43C0
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x24
	movs r5, #0
	strh r5, [r2, #0x1c]
	ldr r0, .L080B43F4
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080B4412
	ldrh r0, [r2, #0x24]
	cmp r0, #0
	beq .L080B4410
	ldrh r1, [r3, #2]
	cmp r1, #1
	bne .L080B43FC
	ldr r4, .L080B43F8
	ldrh r0, [r4]
	cmp r0, #0
	beq .L080B4404
	subs r0, r0, r1
	strh r0, [r4]
	b .L080B4404
	.byte 0x00, 0x00
.L080B43F4: .4byte 0x030031BC @ IWRAM+0x31BC
.L080B43F8: .4byte 0x0300000E @ IWRAM+0xE
.L080B43FC:
	ldr r1, .L080B440C
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L080B4404:
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	b .L080B4412
.L080B440C: .4byte 0x0300000E @ IWRAM+0xE
.L080B4410:
	movs r5, #1
.L080B4412:
	cmp r5, #1
	bne .L080B441A
	movs r0, #1
	strh r0, [r2, #0x1c]
.L080B441A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080B4420
sub_080B4420: @ 0x080B4420
.L080B4420:
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080B4440
	ldr r1, .L080B4444
	bl Task_Create
	strh r4, [r0, #0x24]
	strh r5, [r0, #0x26]
	pop {r4, r5}
	pop {r1}
	bx r1
.L080B4440: .4byte gUnknown_081625F4
.L080B4444: .4byte 0x0000FFFF

	thumb_func_start sub_080B4448
sub_080B4448: @ 0x080B4448
.L080B4448:
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r2, .L080B4464
	movs r4, #0
	ldr r5, [r3, #4]
.L080B4452:
	ldr r0, [r2]
	cmp r5, r0
	bne .L080B4468
	ldr r1, [r3, #8]
	ldr r0, [r2, #4]
	cmp r1, r0
	bne .L080B4468
	ldrh r0, [r2, #8]
	b .L080B4474
.L080B4464: .4byte gUnknown_08162618
.L080B4468:
	adds r2, #0xc
	adds r4, #1
	cmp r4, #0x50
	bls .L080B4452
	movs r0, #0xed
	lsls r0, r0, #2
.L080B4474:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
