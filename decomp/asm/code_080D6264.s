	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080D6264
sub_080D6264: @ 0x080D6264
	push {lr}
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C5170
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D6274
sub_080D6274: @ 0x080D6274
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r2, .L080D629C
	strh r1, [r2]
	movs r0, #0x14
	strh r0, [r2, #4]
	ldr r1, .L080D62A0
	ldr r0, [r1]
	strh r0, [r2, #2]
	ldrh r0, [r2]
	adds r3, r1, #0
	cmp r0, #0x81
	bls .L080D6292
	b .L080D6780
.L080D6292:
	lsls r0, r0, #2
	ldr r1, .L080D62A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080D629C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D62A0: .4byte 0x0203BB68 @ EWRAM+0x3BB68
.L080D62A4: .4byte gUnknown_080D62A8
	.global gUnknown_080D62A8
gUnknown_080D62A8:
.L080D62A8: @ jump table
	.4byte .L080D66A0
	.4byte .L080D66B8
	.4byte .L080D6780
	.4byte .L080D66CC
	.4byte .L080D6728
	.4byte .L080D6764
	.4byte .L080D677A
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D64B0
	.4byte .L080D64B8
	.4byte .L080D6780
	.4byte .L080D64C0
	.4byte .L080D6780
	.4byte .L080D64F4
	.4byte .L080D6780
	.4byte .L080D6508
	.4byte .L080D6538
	.4byte .L080D6780
	.4byte .L080D654C
	.4byte .L080D656C
	.4byte .L080D65A8
	.4byte .L080D6780
	.4byte .L080D65D8
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D65F0
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6780
	.4byte .L080D6604
	.4byte .L080D668C
	.4byte .L080D6780
.L080D64B0:
	ldr r0, .L080D64B4
	b .L080D66BA
.L080D64B4: .4byte gUnknown_084F9CD0
.L080D64B8:
	ldr r0, .L080D64BC
	b .L080D654E
.L080D64BC: .4byte gUnknown_0850485C
.L080D64C0:
	ldr r1, .L080D64E8
	ldr r4, .L080D64EC
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080D64F0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r4, r4, r0
	movs r3, #0x90
	lsls r3, r3, #1
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	b .L080D674A
	.byte 0x00, 0x00
.L080D64E8: .4byte gUnknown_084FA4E0
.L080D64EC: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080D64F0: .4byte gUnknown_084FA500
.L080D64F4:
	ldr r0, .L080D6500
	ldr r4, .L080D6504
	adds r1, r4, #0
	bl HuffUnComp
	b .L080D6556
.L080D6500: .4byte gUnknown_084FD060
.L080D6504: .4byte 0x02001000 @ EWRAM+0x1000
.L080D6508:
	ldr r1, .L080D652C
	ldr r4, .L080D6530
	movs r6, #0x80
	lsls r6, r6, #2
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	adds r3, r6, #0
	bl Palette_CopyWithEffect
	ldr r1, .L080D6534
	adds r4, r4, r6
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	adds r3, r6, #0
	b .L080D674A
.L080D652C: .4byte gUnknown_084FA660
.L080D6530: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080D6534: .4byte gUnknown_084FA500
.L080D6538:
	ldr r0, .L080D6544
	ldr r4, .L080D6548
	adds r1, r4, #0
	bl HuffUnComp
	b .L080D6556
.L080D6544: .4byte gUnknown_085029CC
.L080D6548: .4byte 0x02001000 @ EWRAM+0x1000
.L080D654C:
	ldr r0, .L080D6560
.L080D654E:
	ldr r4, .L080D6564
	adds r1, r4, #0
	bl LZ77UnCompWram
.L080D6556:
	ldr r1, .L080D6568
	adds r0, r4, #0
	bl RLUnCompWram
	b .L080D6780
.L080D6560: .4byte gUnknown_08508AC0
.L080D6564: .4byte 0x02001000 @ EWRAM+0x1000
.L080D6568: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D656C:
	ldr r1, .L080D6590
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, .L080D6594
	movs r2, #0
	strb r2, [r0]
	ldr r1, .L080D6598
	movs r0, #0x96
	strb r0, [r1]
	ldr r0, .L080D659C
	strb r2, [r0]
	ldr r0, .L080D65A0
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080D65A4
	strb r1, [r0]
	b .L080D6780
	.byte 0x00, 0x00
.L080D6590: .4byte 0x03000030 @ IWRAM+0x30
.L080D6594: .4byte 0x03000031 @ IWRAM+0x31
.L080D6598: .4byte 0x03000034 @ IWRAM+0x34
.L080D659C: .4byte 0x03000035 @ IWRAM+0x35
.L080D65A0: .4byte 0x03000038 @ IWRAM+0x38
.L080D65A4: .4byte 0x0300003A @ IWRAM+0x3A
.L080D65A8:
	ldr r1, .L080D65CC
	ldr r4, .L080D65D0
	movs r6, #0x80
	lsls r6, r6, #2
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	adds r3, r6, #0
	bl Palette_CopyWithEffect
	ldr r1, .L080D65D4
	adds r4, r4, r6
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	adds r3, r6, #0
	b .L080D674A
.L080D65CC: .4byte gUnknown_084FA660
.L080D65D0: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080D65D4: .4byte gUnknown_084FA620
.L080D65D8:
	ldr r1, .L080D65E8
	movs r0, #0
	strb r0, [r1]
	ldr r1, .L080D65EC
	movs r0, #0x10
	strb r0, [r1]
	b .L080D6780
	.byte 0x00, 0x00
.L080D65E8: .4byte 0x03000042 @ IWRAM+0x42
.L080D65EC: .4byte 0x03000043 @ IWRAM+0x43
.L080D65F0:
	ldr r1, .L080D65FC
	ldr r2, .L080D6600
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	b .L080D6748
.L080D65FC: .4byte gUnknown_081B6C30
.L080D6600: .4byte 0x03002BB0 @ IWRAM+0x2BB0
.L080D6604:
	ldr r1, .L080D6658
	movs r0, #0x3f
	strb r0, [r1]
	ldr r1, .L080D665C
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, .L080D6660
	movs r0, #0
	strb r0, [r1]
	ldr r1, .L080D6664
	movs r0, #0x78
	strb r0, [r1]
	ldr r1, .L080D6668
	movs r0, #0x9f
	strb r0, [r1]
	ldr r1, .L080D666C
	movs r0, #0x2f
	strb r0, [r1]
	ldr r1, .L080D6670
	ldr r2, .L080D6674
	movs r3, #0x80
	lsls r3, r3, #2
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	ldr r1, .L080D6678
	ldr r2, .L080D667C
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L080D6680
	ldr r2, .L080D6684
	ldrh r0, [r2]
	strb r0, [r1]
	ldr r1, .L080D6688
	ldrh r0, [r2, #2]
	strb r0, [r1]
	b .L080D6780
	.byte 0x00, 0x00
.L080D6658: .4byte 0x0300003A @ IWRAM+0x3A
.L080D665C: .4byte 0x03000030 @ IWRAM+0x30
.L080D6660: .4byte 0x03000031 @ IWRAM+0x31
.L080D6664: .4byte 0x03000035 @ IWRAM+0x35
.L080D6668: .4byte 0x03000034 @ IWRAM+0x34
.L080D666C: .4byte 0x03000038 @ IWRAM+0x38
.L080D6670: .4byte gUnknown_084FA620
.L080D6674: .4byte 0x03002FB0 @ IWRAM+0x2FB0
.L080D6678: .4byte 0x03000040 @ IWRAM+0x40
.L080D667C: .4byte 0x00002E50
.L080D6680: .4byte 0x03000042 @ IWRAM+0x42
.L080D6684: .4byte gUnknown_08509648
.L080D6688: .4byte 0x03000043 @ IWRAM+0x43
.L080D668C:
	ldr r1, .L080D6698
	ldr r4, .L080D669C
	adds r0, r4, #0
	strh r0, [r1]
	b .L080D6780
	.byte 0x00, 0x00
.L080D6698: .4byte 0x03000040 @ IWRAM+0x40
.L080D669C: .4byte 0x00003C42
.L080D66A0:
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, .L080D66B0
	ldr r2, .L080D66B4
	add r0, sp, #4
	bl CpuSet
	b .L080D6780
.L080D66B0: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D66B4: .4byte 0x05002000
.L080D66B8:
	ldr r0, .L080D66C4
.L080D66BA:
	ldr r1, .L080D66C8
	bl LZ77UnCompWram
	b .L080D6780
	.byte 0x00, 0x00
.L080D66C4: .4byte gUnknown_081B5DD4
.L080D66C8: .4byte 0x0200F874 @ EWRAM+0xF874
.L080D66CC:
	ldr r0, .L080D6704
	movs r2, #0
	strh r2, [r0]
	ldr r1, .L080D6708
	ldr r4, .L080D670C
	adds r0, r4, #0
	strh r0, [r1]
	ldr r1, .L080D6710
	adds r4, #8
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, [r3]
	cmp r0, #0
	bne .L080D6780
	ldr r1, .L080D6714
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, .L080D6718
	strb r2, [r0]
	ldr r1, .L080D671C
	movs r0, #0x3c
	strb r0, [r1]
	ldr r0, .L080D6720
	strb r2, [r0]
	ldr r1, .L080D6724
	movs r0, #0x3d
	strb r0, [r1]
	b .L080D6780
.L080D6704: .4byte 0x03000040 @ IWRAM+0x40
.L080D6708: .4byte 0x03000004 @ IWRAM+0x4
.L080D670C: .4byte 0x0000FFE8
.L080D6710: .4byte 0x03000006 @ IWRAM+0x6
.L080D6714: .4byte 0x03000030 @ IWRAM+0x30
.L080D6718: .4byte 0x03000031 @ IWRAM+0x31
.L080D671C: .4byte 0x03000034 @ IWRAM+0x34
.L080D6720: .4byte 0x03000035 @ IWRAM+0x35
.L080D6724: .4byte 0x03000038 @ IWRAM+0x38
.L080D6728:
	ldr r1, .L080D6758
	ldr r4, .L080D675C
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r1, .L080D6760
	movs r0, #0x80
	lsls r0, r0, #2
	adds r4, r4, r0
	str r5, [sp]
	movs r0, #3
	adds r2, r4, #0
.L080D6748:
	movs r3, #0x40
.L080D674A:
	bl Palette_CopyWithEffect
	movs r0, #1
	bl PalFade_FadeInFromBlack
	b .L080D6780
	.byte 0x00, 0x00
.L080D6758: .4byte gUnknown_081B7110
.L080D675C: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080D6760: .4byte gUnknown_081B7130
.L080D6764:
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080D6774
	strh r0, [r4, #0x1c]
	b .L080D6780
.L080D6774:
	movs r0, #0
	strh r0, [r4, #0x1c]
	b .L080D6780
.L080D677A:
	movs r0, #1
	bl PalFade_FadeToBlack
.L080D6780:
	ldr r0, .L080D6790
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D6790: .4byte sub_080D5C20

	thumb_func_start sub_080D6794
sub_080D6794: @ 0x080D6794
	push {lr}
	sub sp, #0xc
	ldr r0, .L080D67B8
	movs r1, #0
	str r1, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x40
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D67B8: .4byte gUnknown_0813EBD4

	thumb_func_start Intro_DrawDisclaimer
Intro_DrawDisclaimer: @ 0x080D67BC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r6, #0
	movs r5, #0
	movs r4, #0
	ldr r7, .L080D6868
.L080D67C8:
	adds r1, r6, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	movs r1, #0x38
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl FontSprite_DrawGlyph
	adds r0, r5, #0
	adds r0, #0xd
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x10
	bls .L080D67C8
	movs r5, #0xd
	movs r4, #0
	ldr r7, .L080D6868
.L080D67FC:
	adds r1, r6, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	movs r1, #0x45
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl FontSprite_DrawGlyph
	adds r0, r5, #0
	adds r0, #0xd
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xf
	bls .L080D67FC
	movs r5, #8
	movs r4, #0
	ldr r7, .L080D6868
.L080D6830:
	adds r1, r6, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	movs r1, #0x52
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl FontSprite_DrawGlyph
	adds r0, r5, #0
	adds r0, #0xd
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x10
	bls .L080D6830
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D6868: .4byte gUnknown_085096C4

	thumb_func_start sub_080D686C
sub_080D686C: @ 0x080D686C
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r0, .L080D68BC
	movs r4, #0
	str r4, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x18
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D68C0
	str r4, [sp]
	movs r1, #0x42
	str r1, [sp, #4]
	movs r5, #0x90
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D68C4
	str r4, [sp]
	movs r1, #0x80
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D68BC: .4byte gUnknown_0813EE88
.L080D68C0: .4byte gUnknown_0813EE20
.L080D68C4: .4byte gUnknown_0813EE3C

	thumb_func_start sub_080D68C8
sub_080D68C8: @ 0x080D68C8
	movs r1, #0
	strh r1, [r0, #0x1c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D68D0
sub_080D68D0: @ 0x080D68D0
	push {lr}
	adds r2, r0, #0
	ldr r3, .L080D68FC
	adds r1, r2, #0
	adds r1, #0x42
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080D68EA
	movs r0, #1
	strh r0, [r2, #0x1c]
.L080D68EA:
	movs r0, #0x10
	ldrsh r1, [r3, r0]
	cmp r1, #1
	bne .L080D68F8
	movs r0, #0
	strh r0, [r3, #0x10]
	strh r1, [r2, #0x1c]
.L080D68F8:
	pop {r0}
	bx r0
.L080D68FC: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D6900
sub_080D6900: @ 0x080D6900
	push {lr}
	adds r2, r0, #0
	ldr r3, .L080D6928
	adds r1, r2, #0
	adds r1, #0x42
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080D691A
	movs r0, #1
	strh r0, [r2, #0x1c]
.L080D691A:
	movs r1, #0x10
	ldrsh r0, [r3, r1]
	cmp r0, #1
	bne .L080D6924
	strh r0, [r2, #0x1e]
.L080D6924:
	pop {r0}
	bx r0
.L080D6928: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D692C
sub_080D692C: @ 0x080D692C
	ldr r2, .L080D6938
	ldrb r0, [r2]
	subs r0, r0, r1
	strb r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080D6938: .4byte 0x03000034 @ IWRAM+0x34

	thumb_func_start sub_080D693C
sub_080D693C: @ 0x080D693C
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, .L080D69C4
	ldr r0, .L080D69C8
	movs r5, #0
	str r5, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x18
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080D6974
	movs r0, #0x14
	strh r0, [r4, #4]
	ldrh r0, [r4, #6]
	adds r0, #1
	movs r1, #1
	ands r0, r1
	strh r0, [r4, #6]
.L080D6974:
	ldrh r0, [r4, #6]
	cmp r0, #0
	bne .L080D6990
	ldr r0, .L080D69CC
	str r5, [sp]
	movs r1, #0x38
	str r1, [sp, #4]
	movs r1, #0x70
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D6990:
	ldr r0, .L080D69D0
	str r5, [sp]
	movs r1, #0x42
	str r1, [sp, #4]
	movs r4, #0x90
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D69D4
	str r5, [sp]
	movs r1, #0x80
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D69C4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D69C8: .4byte gUnknown_0813EE88
.L080D69CC: .4byte gUnknown_080017A4
.L080D69D0: .4byte gUnknown_0813EE20
.L080D69D4: .4byte gUnknown_0813EE3C

	thumb_func_start sub_080D69D8
sub_080D69D8: @ 0x080D69D8
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r0, .L080D6A28
	movs r4, #0
	str r4, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x18
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D6A2C
	str r4, [sp]
	movs r1, #0x42
	str r1, [sp, #4]
	movs r5, #0x90
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D6A30
	str r4, [sp]
	movs r1, #0x80
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D6A28: .4byte gUnknown_0813EE88
.L080D6A2C: .4byte gUnknown_0813EE20
.L080D6A30: .4byte gUnknown_0813EE3C

	thumb_func_start sub_080D6A34
sub_080D6A34: @ 0x080D6A34
.L080D6A34:
	push {r4, r5, lr}
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080D6A60
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L080D6A60
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080D6A64
.L080D6A60:
	movs r0, #1
	b .L080D6A90
.L080D6A64:
	movs r4, #0
	ldr r5, .L080D6A98
.L080D6A68:
	adds r0, r4, #0
	bl sub_080C2644
	cmp r0, #0
	bne .L080D6A60
	adds r4, #1
	cmp r4, r5
	bls .L080D6A68
	movs r4, #0
.L080D6A7A:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, r1
	bl sub_080C2734
	cmp r0, #0
	bne .L080D6A60
	adds r4, #1
	cmp r4, #0x3f
	bls .L080D6A7A
	movs r0, #0
.L080D6A90:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080D6A98: .4byte 0x0000017B

	thumb_func_start sub_080D6A9C
sub_080D6A9C: @ 0x080D6A9C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r6, .L080D6AEC
	ldr r0, .L080D6AF0
	movs r5, #0
	str r5, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	movs r1, #0x18
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D6AF4
	str r5, [sp]
	movs r1, #0x58
	str r1, [sp, #4]
	movs r4, #0x54
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r6, #8]
	cmp r0, #1
	bne .L080D6AFC
	ldr r0, .L080D6AF8
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0x5f
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L080D6B10
.L080D6AEC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D6AF0: .4byte gUnknown_0813EE88
.L080D6AF4: .4byte gUnknown_0813ED6C
.L080D6AF8: .4byte gUnknown_0813ED84
.L080D6AFC:
	ldr r0, .L080D6B30
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0x5f
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D6B10:
	ldrh r0, [r6, #0xa]
	cmp r0, #1
	bne .L080D6B38
	ldr r0, .L080D6B34
	movs r1, #0
	str r1, [sp]
	movs r1, #0x58
	str r1, [sp, #4]
	movs r1, #0x6a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L080D6B50
.L080D6B30: .4byte gUnknown_0813EDF0
.L080D6B34: .4byte gUnknown_0813ED9C
.L080D6B38:
	ldr r0, .L080D6B88
	movs r1, #0
	str r1, [sp]
	movs r1, #0x58
	str r1, [sp, #4]
	movs r1, #0x6a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D6B50:
	bl sub_080D6A34
	cmp r0, #1
	bne .L080D6B94
	ldr r0, .L080D6B8C
	movs r4, #0
	str r4, [sp]
	movs r1, #0x50
	str r1, [sp, #4]
	movs r1, #0x75
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D6B90
	str r4, [sp]
	movs r1, #0x60
	str r1, [sp, #4]
	movs r1, #0x80
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L080D6BAC
.L080D6B88: .4byte gUnknown_0813EE08
.L080D6B8C: .4byte gUnknown_0813EDC0
.L080D6B90: .4byte gUnknown_0813EDD8
.L080D6B94:
	ldr r0, .L080D6BE8
	movs r1, #0
	str r1, [sp]
	movs r1, #0x60
	str r1, [sp, #4]
	movs r1, #0x75
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D6BAC:
	ldr r0, .L080D6BEC
	movs r5, #0
	str r5, [sp]
	movs r1, #0x42
	str r1, [sp, #4]
	movs r4, #0x90
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D6BF0
	str r5, [sp]
	movs r1, #0x80
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r6, #2]
	cmp r0, #4
	bhi .L080D6C80
	lsls r0, r0, #2
	ldr r1, .L080D6BF4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080D6BE8: .4byte gUnknown_0813EDD8
.L080D6BEC: .4byte gUnknown_0813EE20
.L080D6BF0: .4byte gUnknown_0813EE3C
.L080D6BF4: .4byte gUnknown_080D6BF8
	.global gUnknown_080D6BF8
gUnknown_080D6BF8:
.L080D6BF8: @ jump table
	.4byte .L080D6C0C
	.4byte .L080D6C20
	.4byte .L080D6C34
	.4byte .L080D6C48
	.4byte .L080D6C68
.L080D6C0C:
	ldr r0, .L080D6C1C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x48
	str r1, [sp, #4]
	movs r1, #0x50
	b .L080D6C54
	.byte 0x00, 0x00
.L080D6C1C: .4byte gUnknown_0813EE58
.L080D6C20:
	ldr r0, .L080D6C30
	movs r1, #0
	str r1, [sp]
	movs r1, #0x48
	str r1, [sp, #4]
	movs r1, #0x5b
	b .L080D6C54
	.byte 0x00, 0x00
.L080D6C30: .4byte gUnknown_0813EE58
.L080D6C34:
	ldr r0, .L080D6C44
	movs r1, #0
	str r1, [sp]
	movs r1, #0x48
	str r1, [sp, #4]
	movs r1, #0x66
	b .L080D6C54
	.byte 0x00, 0x00
.L080D6C44: .4byte gUnknown_0813EE58
.L080D6C48:
	ldr r0, .L080D6C64
	movs r1, #0
	str r1, [sp]
	movs r1, #0x48
	str r1, [sp, #4]
	movs r1, #0x71
.L080D6C54:
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L080D6C80
	.byte 0x00, 0x00
.L080D6C64: .4byte gUnknown_0813EE58
.L080D6C68:
	ldr r0, .L080D6C88
	movs r1, #0
	str r1, [sp]
	movs r1, #0x48
	str r1, [sp, #4]
	movs r1, #0x7c
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D6C80:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D6C88: .4byte gUnknown_0813EE58

	thumb_func_start sub_080D6C8C
sub_080D6C8C: @ 0x080D6C8C
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r4, .L080D6CA8
	movs r5, #0
	strh r5, [r2, #0x1e]
	ldrh r0, [r4, #0xc]
	subs r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080D6CAC
	movs r0, #2
	strh r0, [r2, #0x1e]
	b .L080D6CE4
.L080D6CA8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D6CAC:
	ldr r0, .L080D6CD0
	ldrh r1, [r0]
	ldr r0, .L080D6CD4
	ands r0, r1
	cmp r0, #0
	beq .L080D6CE4
	movs r0, #1
	strh r0, [r2, #0x1e]
	movs r0, #0x65
	bl sub_080C51D4
	ldrh r0, [r4, #0xa]
	cmp r0, #1
	bne .L080D6CD8
	movs r0, #2
	strh r0, [r4, #2]
	b .L080D6CE4
	.byte 0x00, 0x00
.L080D6CD0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D6CD4: .4byte 0x000003FF
.L080D6CD8:
	ldrh r0, [r4, #8]
	cmp r0, #1
	bne .L080D6CE2
	strh r0, [r4, #2]
	b .L080D6CE4
.L080D6CE2:
	strh r5, [r4, #2]
.L080D6CE4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D6CEC
sub_080D6CEC: @ 0x080D6CEC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, .L080D6D14
	movs r6, #5
	bl sub_080D6A34
	cmp r0, #0
	bne .L080D6CFE
	movs r6, #4
.L080D6CFE:
	movs r0, #0
	strh r0, [r5, #0x1e]
	ldrh r0, [r4, #0xc]
	subs r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080D6D18
	movs r0, #0x80
	strh r0, [r5, #0x1e]
	b .L080D6DC8
.L080D6D14: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D6D18:
	ldr r2, .L080D6D5C
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080D6D60
	ldrh r2, [r4, #2]
	adds r1, r2, #0
	cmp r1, #2
	bne .L080D6D32
	ldrh r0, [r4, #0xa]
	cmp r0, #0
	beq .L080D6DC8
.L080D6D32:
	cmp r1, #1
	bne .L080D6D3C
	ldrh r0, [r4, #8]
	cmp r0, #0
	beq .L080D6DC8
.L080D6D3C:
	adds r0, r2, #1
	strh r0, [r5, #0x1e]
	bl sub_080D6A34
	cmp r0, #0
	bne .L080D6D52
	ldrh r0, [r5, #0x1e]
	cmp r0, #4
	bne .L080D6D52
	movs r0, #5
	strh r0, [r5, #0x1e]
.L080D6D52:
	movs r0, #0x65
	bl sub_080C51D4
	b .L080D6DC8
	.byte 0x00, 0x00
.L080D6D5C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D6D60:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080D6D76
	movs r0, #0xa
	strh r0, [r5, #0x1e]
	movs r0, #0x66
	bl sub_080C51D4
	b .L080D6DC8
.L080D6D76:
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq .L080D6DA2
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r4, #0xc]
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq .L080D6D9C
	subs r0, #1
	strh r0, [r4, #2]
	b .L080D6DC8
.L080D6D9C:
	subs r0, r6, #1
	strh r0, [r4, #2]
	b .L080D6DC8
.L080D6DA2:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080D6DC8
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r4, #0xc]
	movs r0, #0x64
	bl sub_080C51D4
	ldrh r1, [r4, #2]
	subs r0, r6, #1
	cmp r1, r0
	beq .L080D6DC6
	adds r0, r1, #1
	strh r0, [r4, #2]
	b .L080D6DC8
.L080D6DC6:
	strh r5, [r4, #2]
.L080D6DC8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D6DD0
sub_080D6DD0: @ 0x080D6DD0
	push {lr}
	sub sp, #8
	bl sub_080C10F4
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r1, #0
	movs r2, #2
	movs r3, #6
	bl sub_080B70BC
	add sp, #8
	pop {r0}
	bx r0

	thumb_func_start sub_080D6DF0
sub_080D6DF0: @ 0x080D6DF0
	push {lr}
	movs r0, #0
	movs r1, #0
	bl SaveScreen_Open
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D6E00
sub_080D6E00: @ 0x080D6E00
	push {lr}
	movs r0, #1
	movs r1, #0
	bl SaveScreen_Open
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D6E10
sub_080D6E10: @ 0x080D6E10
	push {lr}
	ldr r0, .L080D6E1C
	bl SetMainCallback
	pop {r0}
	bx r0
.L080D6E1C: .4byte sub_080DDEDC

	thumb_func_start sub_080D6E20
sub_080D6E20: @ 0x080D6E20
	push {lr}
	movs r0, #0
	bl sub_080CFFE0
	pop {r0}
	bx r0

	thumb_func_start sub_080D6E2C
sub_080D6E2C: @ 0x080D6E2C
	ldr r0, .L080D6E38
	ldr r1, .L080D6E3C
	ldrh r0, [r0, #2]
	str r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L080D6E38: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D6E3C: .4byte 0x0203BB68 @ EWRAM+0x3BB68

	thumb_func_start sub_080D6E40
sub_080D6E40: @ 0x080D6E40
	push {lr}
	movs r0, #8
	bl sub_080C51BC
	pop {r0}
	bx r0

	thumb_func_start sub_080D6E4C
sub_080D6E4C: @ 0x080D6E4C
	push {lr}
	cmp r1, #1
	beq .L080D6E64
	cmp r1, #1
	blo .L080D6E5C
	cmp r1, #2
	beq .L080D6E74
	b .L080D6E78
.L080D6E5C:
	ldr r0, .L080D6E60
	b .L080D6E66
.L080D6E60: .4byte sub_080C1450
.L080D6E64:
	ldr r0, .L080D6E70
.L080D6E66:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080D6E78
	.byte 0x00, 0x00
.L080D6E70: .4byte sub_080C1328
.L080D6E74:
	bl sub_080C1384
.L080D6E78:
	pop {r0}
	bx r0

	thumb_func_start sub_080D6E7C
sub_080D6E7C: @ 0x080D6E7C
	ldr r1, .L080D6E88
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r1, #0xc]
	bx lr
	.byte 0x00, 0x00
.L080D6E88: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D6E8C
sub_080D6E8C: @ 0x080D6E8C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D6E90
sub_080D6E90: @ 0x080D6E90
	ldr r2, .L080D6E9C
	movs r1, #0
	strh r1, [r0, #0x1c]
	strh r1, [r0, #0x1e]
	strh r1, [r2, #0xe]
	bx lr
.L080D6E9C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D6EA0
sub_080D6EA0: @ 0x080D6EA0
	push {lr}
	sub sp, #0xc
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080D6EB6
	subs r0, #1
	strb r0, [r1]
	b .L080D6F1C
.L080D6EB6:
	ldr r0, .L080D6EC8
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080D6ECC
	movs r0, #1
	strh r0, [r3, #0x1e]
	b .L080D6F1C
.L080D6EC8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D6ECC:
	adds r1, r3, #0
	adds r1, #0x26
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080D6EE0
	subs r0, #1
	strb r0, [r1]
	adds r2, r3, #0
	adds r2, #0x24
	b .L080D6EF0
.L080D6EE0:
	movs r0, #3
	strb r0, [r1]
	adds r1, r3, #0
	adds r1, #0x24
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r2, r1, #0
.L080D6EF0:
	ldrb r0, [r2]
	cmp r0, #0
	bne .L080D6EFC
	movs r0, #1
	strh r0, [r3, #0x1c]
	b .L080D6F1C
.L080D6EFC:
	ldr r1, .L080D6F24
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrb r2, [r2]
	adds r1, r1, r2
	ldr r0, .L080D6F28
	movs r2, #0
	str r2, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r2, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl Sprite_Draw
.L080D6F1C:
	add sp, #0xc
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D6F24: .4byte 0x0000FFCE
.L080D6F28: .4byte gUnknown_0813EC98

	thumb_func_start sub_080D6F2C
sub_080D6F2C: @ 0x080D6F2C
	adds r3, r0, #0
	ldr r1, .L080D6F7C
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, .L080D6F80
	movs r0, #0
	strb r0, [r1]
	ldr r1, .L080D6F84
	movs r0, #0x96
	strb r0, [r1]
	ldr r1, .L080D6F88
	movs r0, #0x70
	strb r0, [r1]
	ldr r2, .L080D6F8C
	ldrb r1, [r2]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0xa0
	strb r0, [r1]
	adds r1, #2
	movs r0, #3
	strb r0, [r1]
	subs r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	movs r1, #0
	strh r2, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	bx lr
.L080D6F7C: .4byte 0x03000030 @ IWRAM+0x30
.L080D6F80: .4byte 0x03000031 @ IWRAM+0x31
.L080D6F84: .4byte 0x03000034 @ IWRAM+0x34
.L080D6F88: .4byte 0x03000035 @ IWRAM+0x35
.L080D6F8C: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080D6F90
sub_080D6F90: @ 0x080D6F90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r3, r0, #0
	ldr r0, .L080D6FAC
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080D6FB0
	movs r0, #1
	strh r0, [r3, #0x1e]
	b .L080D7096
.L080D6FAC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D6FB0:
	adds r1, r3, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080D6FC0
	subs r0, #1
	strb r0, [r1]
	b .L080D7096
.L080D6FC0:
	adds r1, r3, #0
	adds r1, #0x26
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080D6FD6
	subs r0, #1
	strb r0, [r1]
	subs r1, #2
	adds r5, r3, #0
	adds r5, #0x28
	b .L080D7010
.L080D6FD6:
	movs r0, #3
	strb r0, [r1]
	adds r1, r3, #0
	adds r1, #0x24
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x28
	ldrb r4, [r0]
	adds r2, r4, #0
	adds r5, r0, #0
	cmp r2, #0xff
	beq .L080D6FF8
	adds r0, r4, #1
	strb r0, [r5]
	b .L080D7010
.L080D6FF8:
	adds r2, r3, #0
	adds r2, #0x29
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bne .L080D7010
	movs r0, #1
	strh r0, [r3, #0x1c]
	b .L080D7096
.L080D7010:
	ldrb r4, [r1]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt .L080D7030
	ldr r0, .L080D70A4
	movs r1, #0
	str r1, [sp]
	movs r1, #0x78
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D7030:
	adds r1, r4, #0
	adds r1, #0x40
	movs r0, #0xff
	mov r8, r0
	ands r1, r0
	ldr r0, .L080D70A8
	movs r7, #0
	str r7, [sp]
	movs r6, #0x78
	str r6, [sp, #4]
	lsls r4, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrb r0, [r5]
	cmp r0, #0x40
	bls .L080D7096
	movs r1, #0x80
	lsls r1, r1, #0xf
	adds r0, r4, r1
	asrs r1, r0, #0x10
	mov r0, r8
	ands r1, r0
	ldr r0, .L080D70AC
	str r7, [sp]
	str r6, [sp, #4]
	lsls r4, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r1, #0x80
	lsls r1, r1, #0xf
	adds r4, r4, r1
	asrs r4, r4, #0x10
	ldr r0, .L080D70B0
	str r7, [sp]
	str r6, [sp, #4]
	mov r1, r8
	ands r4, r1
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D7096:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D70A4: .4byte gUnknown_0813ECB4
.L080D70A8: .4byte gUnknown_0813ECD0
.L080D70AC: .4byte gUnknown_0813ECEC
.L080D70B0: .4byte gUnknown_0813ED2C

	thumb_func_start sub_080D70B4
sub_080D70B4: @ 0x080D70B4
	ldr r1, .L080D70C4
	movs r2, #0
	strh r2, [r1]
	ldr r1, .L080D70C8
	strh r2, [r1]
	movs r1, #0
	strh r1, [r0, #0x1e]
	bx lr
.L080D70C4: .4byte 0x03000004 @ IWRAM+0x4
.L080D70C8: .4byte 0x03000008 @ IWRAM+0x8

	thumb_func_start sub_080D70CC
sub_080D70CC: @ 0x080D70CC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, .L080D7170
	ldrh r1, [r4]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080D70EA
	ldr r0, .L080D7174
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #0x1f
	ands r1, r2
	strb r1, [r0]
.L080D70EA:
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080D7100
	ldr r0, .L080D7174
	ldrb r1, [r0]
	subs r1, #1
	movs r2, #0x1f
	ands r1, r2
	strb r1, [r0]
.L080D7100:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L080D7118
	ldr r0, .L080D7178
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #0x1f
	ands r1, r2
	strb r1, [r0]
.L080D7118:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L080D7130
	ldr r0, .L080D7178
	ldrb r1, [r0]
	subs r1, #1
	movs r2, #0x1f
	ands r1, r2
	strb r1, [r0]
.L080D7130:
	ldr r3, .L080D717C
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L080D7148
	ldr r0, .L080D7180
	ldrh r1, [r0]
	adds r1, #1
	movs r2, #0xff
	ands r1, r2
	strh r1, [r0]
.L080D7148:
	ldrh r1, [r3]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080D715E
	ldr r0, .L080D7180
	ldrh r1, [r0]
	subs r1, #1
	movs r2, #0xff
	ands r1, r2
	strh r1, [r0]
.L080D715E:
	ldrh r1, [r4]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080D716A
	strh r6, [r5, #0x1e]
.L080D716A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D7170: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080D7174: .4byte 0x03000042 @ IWRAM+0x42
.L080D7178: .4byte 0x03000043 @ IWRAM+0x43
.L080D717C: .4byte 0x030031D0 @ IWRAM+0x31D0
.L080D7180: .4byte 0x03000004 @ IWRAM+0x4

	thumb_func_start sub_080D7184
sub_080D7184: @ 0x080D7184
	push {r4, lr}
	ldr r4, .L080D71EC
	ldr r1, .L080D71F0
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, .L080D71F4
	movs r2, #0
	strb r2, [r0]
	ldr r1, .L080D71F8
	movs r0, #0xa0
	strb r0, [r1]
	ldr r0, .L080D71FC
	strb r2, [r0]
	ldr r1, .L080D7200
	movs r0, #0x3f
	strb r0, [r1]
	ldr r0, .L080D7204
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080D7208
	strh r1, [r0]
	ldr r0, .L080D720C
	strh r1, [r0]
	ldr r0, .L080D7210
	ldr r1, [r0]
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080D71C2
	adds r0, r1, #0
	bl Task_End
.L080D71C2:
	ldr r0, .L080D7214
	ldr r1, [r0]
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080D71D2
	adds r0, r1, #0
	bl Task_End
.L080D71D2:
	ldr r0, .L080D7218
	ldr r1, [r0]
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080D71E2
	adds r0, r1, #0
	bl Task_End
.L080D71E2:
	movs r0, #1
	strh r0, [r4, #0xe]
	pop {r4}
	pop {r0}
	bx r0
.L080D71EC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D71F0: .4byte 0x03000030 @ IWRAM+0x30
.L080D71F4: .4byte 0x03000031 @ IWRAM+0x31
.L080D71F8: .4byte 0x03000034 @ IWRAM+0x34
.L080D71FC: .4byte 0x03000035 @ IWRAM+0x35
.L080D7200: .4byte 0x0300003A @ IWRAM+0x3A
.L080D7204: .4byte 0x0300000C @ IWRAM+0xC
.L080D7208: .4byte 0x03000008 @ IWRAM+0x8
.L080D720C: .4byte 0x03000004 @ IWRAM+0x4
.L080D7210: .4byte 0x03006968 @ IWRAM+0x6968
.L080D7214: .4byte 0x03006954 @ IWRAM+0x6954
.L080D7218: .4byte 0x03006938 @ IWRAM+0x6938

	thumb_func_start sub_080D721C
sub_080D721C: @ 0x080D721C
	movs r2, #0
	movs r1, #0
	strh r1, [r0, #0x1c]
	adds r1, r0, #0
	adds r1, #0x25
	strb r2, [r1]
	adds r0, #0x26
	strb r2, [r0]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D7230
sub_080D7230: @ 0x080D7230
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, .L080D7294
	adds r1, r4, #0
	adds r1, #0x25
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bne .L080D7284
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x26
	adds r0, r0, r4
	mov ip, r0
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r2, .L080D7298
	ldr r3, .L080D729C
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r2]
	ldr r2, .L080D72A0
	mov r6, ip
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x10
	bne .L080D7284
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080D7284:
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	cmp r0, #1
	bne .L080D728E
	strh r0, [r4, #0x1e]
.L080D728E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D7294: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D7298: .4byte 0x03000042 @ IWRAM+0x42
.L080D729C: .4byte gUnknown_08509680
.L080D72A0: .4byte 0x03000043 @ IWRAM+0x43

	thumb_func_start sub_080D72A4
sub_080D72A4: @ 0x080D72A4
	adds r2, r0, #0
	movs r0, #0
	movs r1, #0
	strh r1, [r2, #0x1c]
	adds r1, r2, #0
	adds r1, #0x25
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	bx lr

	thumb_func_start sub_080D72C0
sub_080D72C0: @ 0x080D72C0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, .L080D7324
	adds r1, r4, #0
	adds r1, #0x25
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne .L080D7314
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x26
	adds r0, r0, r4
	mov ip, r0
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r2, .L080D7328
	ldr r3, .L080D732C
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r2]
	ldr r2, .L080D7330
	mov r6, ip
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x10
	bne .L080D7314
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080D7314:
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	cmp r0, #1
	bne .L080D731E
	strh r0, [r4, #0x1e]
.L080D731E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D7324: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D7328: .4byte 0x03000042 @ IWRAM+0x42
.L080D732C: .4byte gUnknown_08509680
.L080D7330: .4byte 0x03000043 @ IWRAM+0x43

	thumb_func_start sub_080D7334
sub_080D7334: @ 0x080D7334
	movs r2, #0
	movs r1, #0
	strh r1, [r0, #0x1c]
	adds r1, r0, #0
	adds r1, #0x24
	strb r2, [r1]
	adds r0, #0x25
	strb r2, [r0]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D7348
sub_080D7348: @ 0x080D7348
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, .L080D7394
	adds r1, r3, #0
	adds r1, #0x25
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne .L080D7382
	movs r0, #0
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x24
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r2, .L080D7398
	movs r0, #0x9f
	subs r0, r0, r1
	strb r0, [r2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x10
	bne .L080D7382
	movs r0, #1
	strh r0, [r3, #0x1c]
.L080D7382:
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r0, #1
	bne .L080D738C
	strh r0, [r3, #0x1e]
.L080D738C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D7394: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D7398: .4byte 0x03000034 @ IWRAM+0x34

	thumb_func_start sub_080D739C
sub_080D739C: @ 0x080D739C
	adds r3, r0, #0
	ldr r1, .L080D73D8
	movs r0, #0x64
	strb r0, [r1]
	ldr r0, .L080D73DC
	movs r2, #0
	strb r2, [r0]
	ldr r1, .L080D73E0
	movs r0, #0x6c
	strb r0, [r1]
	ldr r0, .L080D73E4
	strb r2, [r0]
	ldr r1, .L080D73E8
	movs r0, #0x3f
	strb r0, [r1]
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x64
	strb r0, [r1]
	adds r1, #2
	movs r0, #5
	strb r0, [r1]
	subs r1, #1
	movs r0, #8
	strb r0, [r1]
	strh r2, [r3, #0x1c]
	strh r2, [r3, #0x1e]
	bx lr
	.byte 0x00, 0x00
.L080D73D8: .4byte 0x03000032 @ IWRAM+0x32
.L080D73DC: .4byte 0x03000033 @ IWRAM+0x33
.L080D73E0: .4byte 0x03000036 @ IWRAM+0x36
.L080D73E4: .4byte 0x03000037 @ IWRAM+0x37
.L080D73E8: .4byte 0x03000039 @ IWRAM+0x39

	thumb_func_start sub_080D73EC
sub_080D73EC: @ 0x080D73EC
	push {lr}
	sub sp, #0xc
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080D7406
	subs r0, #1
	strb r0, [r1]
	adds r2, r3, #0
	adds r2, #0x24
	b .L080D7444
.L080D7406:
	adds r1, r3, #0
	adds r1, #0x26
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080D741A
	subs r0, #1
	strb r0, [r1]
	adds r2, r3, #0
	adds r2, #0x24
	b .L080D7432
.L080D741A:
	movs r0, #5
	strb r0, [r1]
	adds r1, r3, #0
	adds r1, #0x24
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r2, .L080D7440
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	adds r2, r1, #0
.L080D7432:
	ldrb r0, [r2]
	cmp r0, #0
	bne .L080D7444
	movs r0, #1
	strh r0, [r3, #0x1c]
	b .L080D7466
	.byte 0x00, 0x00
.L080D7440: .4byte 0x03000032 @ IWRAM+0x32
.L080D7444:
	ldr r1, .L080D746C
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrb r2, [r2]
	adds r1, r1, r2
	ldr r0, .L080D7470
	movs r2, #0
	str r2, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #8
	str r1, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl Sprite_Draw
.L080D7466:
	add sp, #0xc
	pop {r0}
	bx r0
.L080D746C: .4byte 0x0000FFCE
.L080D7470: .4byte gUnknown_0813EC98

	thumb_func_start sub_080D7474
sub_080D7474: @ 0x080D7474
	adds r3, r0, #0
	ldr r1, .L080D74C4
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, .L080D74C8
	movs r0, #0
	strb r0, [r1]
	ldr r1, .L080D74CC
	movs r0, #0x96
	strb r0, [r1]
	ldr r1, .L080D74D0
	movs r0, #0x70
	strb r0, [r1]
	ldr r2, .L080D74D4
	ldrb r1, [r2]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0xa0
	strb r0, [r1]
	adds r1, #2
	movs r0, #6
	strb r0, [r1]
	subs r1, #1
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #2
	movs r0, #0x78
	strb r0, [r1]
	movs r1, #0
	strh r2, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	bx lr
.L080D74C4: .4byte 0x03000030 @ IWRAM+0x30
.L080D74C8: .4byte 0x03000031 @ IWRAM+0x31
.L080D74CC: .4byte 0x03000034 @ IWRAM+0x34
.L080D74D0: .4byte 0x03000035 @ IWRAM+0x35
.L080D74D4: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080D74D8
sub_080D74D8: @ 0x080D74D8
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r0, #0x30
	ldrb r1, [r0]
	adds r0, #1
	ldrb r0, [r0]
	lsls r4, r1, #8
	orrs r4, r0
	adds r1, r5, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #0
	bne .L080D74FE
	adds r1, r5, #0
	adds r1, #0x27
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080D7504
.L080D74FE:
	subs r0, #1
	strb r0, [r1]
	b .L080D75D2
.L080D7504:
	adds r1, r5, #0
	adds r1, #0x26
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080D7514
	subs r0, #1
	strb r0, [r1]
	b .L080D751E
.L080D7514:
	movs r0, #6
	strb r0, [r1]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L080D751E:
	cmp r4, #0x7f
	bhi .L080D7540
	movs r1, #0xa0
	subs r1, r1, r4
	ldr r0, .L080D75DC
	movs r2, #0
	str r2, [sp]
	movs r2, #0x78
	str r2, [sp, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D7540:
	adds r0, r4, #0
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bhi .L080D756A
	movs r1, #0xe0
	subs r1, r1, r4
	ldr r0, .L080D75E0
	movs r2, #0
	str r2, [sp]
	movs r2, #0x78
	str r2, [sp, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D756A:
	adds r0, r4, #0
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bhi .L080D7598
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r0, #0
	subs r1, r1, r4
	ldr r0, .L080D75E4
	movs r2, #0
	str r2, [sp]
	movs r2, #0x78
	str r2, [sp, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D7598:
	adds r0, r4, #0
	subs r0, #0xc0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x75
	bhi .L080D75C6
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r0, #0
	subs r1, r1, r4
	ldr r0, .L080D75E8
	movs r2, #0
	str r2, [sp]
	movs r2, #0x78
	str r2, [sp, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080D75C6:
	lsrs r1, r4, #8
	adds r0, r5, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r0, #1
	strb r4, [r0]
.L080D75D2:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D75DC: .4byte gUnknown_0813ECB4
.L080D75E0: .4byte gUnknown_0813ECD0
.L080D75E4: .4byte gUnknown_0813ECEC
.L080D75E8: .4byte gUnknown_0813ED2C

	thumb_func_start sub_080D75EC
sub_080D75EC: @ 0x080D75EC
	adds r3, r0, #0
	adds r0, #0x24
	movs r2, #0
	movs r1, #0x20
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	strh r2, [r3, #0x1c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D7600
sub_080D7600: @ 0x080D7600
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x24
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080D7654
	movs r0, #0x20
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x18
	beq .L080D7650
	ldr r1, .L080D7644
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r1, .L080D7648
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r1, .L080D764C
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b .L080D7654
	.byte 0x00, 0x00
.L080D7644: .4byte 0x0300000C @ IWRAM+0xC
.L080D7648: .4byte 0x03000008 @ IWRAM+0x8
.L080D764C: .4byte 0x03000004 @ IWRAM+0x4
.L080D7650:
	movs r0, #1
	strh r0, [r2, #0x1c]
.L080D7654:
	pop {r0}
	bx r0

	thumb_func_start sub_080D7658
sub_080D7658: @ 0x080D7658
	push {r4, lr}
	ldr r1, .L080D7694
	movs r0, #0
	strh r0, [r1, #0xe]
	ldr r0, .L080D7698
	ldr r4, .L080D769C
	adds r1, r4, #0
	bl Task_Create
	ldr r1, .L080D76A0
	str r0, [r1]
	ldr r0, .L080D76A4
	adds r1, r4, #0
	bl Task_Create
	ldr r1, .L080D76A8
	str r0, [r1]
	ldr r0, .L080D76AC
	adds r1, r4, #0
	bl Task_Create
	ldr r1, .L080D76B0
	str r0, [r1]
	ldr r0, .L080D76B4
	adds r1, r4, #0
	bl Task_Create
	pop {r4}
	pop {r0}
	bx r0
.L080D7694: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D7698: .4byte gUnknown_08509764
.L080D769C: .4byte 0x0000FFFF
.L080D76A0: .4byte 0x03006968 @ IWRAM+0x6968
.L080D76A4: .4byte gUnknown_085097A0
.L080D76A8: .4byte 0x03006938 @ IWRAM+0x6938
.L080D76AC: .4byte gUnknown_08509728
.L080D76B0: .4byte 0x03006954 @ IWRAM+0x6954
.L080D76B4: .4byte gUnknown_085097DC

	thumb_func_start sub_080D76B8
sub_080D76B8: @ 0x080D76B8
	movs r1, #0
	strh r1, [r0, #0x1c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D76C0
sub_080D76C0: @ 0x080D76C0
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080D76D4
	movs r2, #0xe
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bne .L080D76D0
	strh r0, [r1, #0x1c]
.L080D76D0:
	pop {r0}
	bx r0
.L080D76D4: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D76D8
sub_080D76D8: @ 0x080D76D8
	push {lr}
	ldr r0, .L080D76F0
	ldr r1, [r0]
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080D76EA
	adds r0, r1, #0
	bl Task_End
.L080D76EA:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D76F0: .4byte 0x030069E4 @ IWRAM+0x69E4

	thumb_func_start sub_080D76F4
sub_080D76F4: @ 0x080D76F4
	push {r4, lr}
	ldr r4, .L080D7710
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080D770A
	ldr r0, .L080D7714
	ldr r1, .L080D7718
	bl Task_Create
	str r0, [r4]
.L080D770A:
	pop {r4}
	pop {r0}
	bx r0
.L080D7710: .4byte 0x030069E4 @ IWRAM+0x69E4
.L080D7714: .4byte gUnknown_08509CD0
.L080D7718: .4byte 0x0000FFFF

	thumb_func_start sub_080D771C
sub_080D771C: @ 0x080D771C
	ldr r1, .L080D7724
	movs r0, #0
	strh r0, [r1, #0x10]
	bx lr
.L080D7724: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_080D7728
sub_080D7728: @ 0x080D7728
	push {lr}
	ldr r2, .L080D7740
	ldr r0, .L080D7744
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L080D773C
	movs r0, #1
	strh r0, [r2, #0x10]
.L080D773C:
	pop {r0}
	bx r0
.L080D7740: .4byte 0x0203A454 @ EWRAM+0x3A454
.L080D7744: .4byte 0x030031B8 @ IWRAM+0x31B8

	thumb_func_start sub_080D7748
sub_080D7748: @ 0x080D7748
	push {lr}
	ldr r0, .L080D7758
	ldr r0, [r0]
	cmp r1, #1
	bne .L080D775C
	bl Task_Pause
	b .L080D7760
.L080D7758: .4byte 0x030065F4 @ IWRAM+0x65F4
.L080D775C:
	bl Task_Resume
.L080D7760:
	pop {r0}
	bx r0

	thumb_func_start sub_080D7764
sub_080D7764: @ 0x080D7764
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	ldrh r0, [r0, #0x2a]
	bl sub_080D95F4
	lsls r1, r5, #2
	lsls r4, r4, #3
	adds r1, r1, r4
	adds r0, #4
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r5, r5, #0xc
	ldr r1, .L080D7790
	adds r5, r5, r1
	adds r1, r5, #0
	bl LZ77UnCompWram
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D7790: .4byte 0x02001000 @ EWRAM+0x1000

	thumb_func_start sub_080D7794
sub_080D7794: @ 0x080D7794
	ldr r1, .L080D77A8
	ldr r0, .L080D77AC
	str r0, [r1]
	ldr r0, .L080D77B0
	str r0, [r1, #4]
	ldr r0, .L080D77B4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D77A8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D77AC: .4byte 0x02001000 @ EWRAM+0x1000
.L080D77B0: .4byte 0x06016000 @ VRAM+0x16000
.L080D77B4: .4byte 0x84000800

	thumb_func_start sub_080D77B8
sub_080D77B8: @ 0x080D77B8
	push {lr}
	ldr r0, .L080D77C8
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D77C8: .4byte sub_080D7794

	thumb_func_start sub_080D77CC
sub_080D77CC: @ 0x080D77CC
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r4, #0x24
	ldrh r0, [r4, #6]
	bl sub_080D95F4
	ldr r1, [r0, #0x24]
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl sub_080C3F4C
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080D77F4
sub_080D77F4: @ 0x080D77F4
	movs r1, #1
	strh r1, [r0, #0x28]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D77FC
sub_080D77FC: @ 0x080D77FC
.L080D77FC:
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r4, r3, #0
	ldr r6, [sp, #0x1c]
	adds r5, #0x24
	ldrh r0, [r5, #6]
	bl sub_080D95F4
	lsls r4, r4, #1
	adds r4, r4, r6
	lsls r4, r4, #2
	add r4, r8
	ldr r1, [r4]
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	mov r2, sb
	adds r3, r6, #0
	bl sub_080C4080
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D7840
sub_080D7840: @ 0x080D7840
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r4, .L080D7868
.L080D7846:
	ldr r1, [r4]
	cmp r1, #0
	beq .L080D7858
	ldrh r0, [r1, #0x2a]
	cmp r0, r6
	bne .L080D7858
	adds r0, r1, #0
	bl Task_Signal
.L080D7858:
	adds r4, #4
	adds r5, #1
	cmp r5, #5
	bls .L080D7846
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D7868: .4byte 0x02036094 @ EWRAM+0x36094

	thumb_func_start sub_080D786C
sub_080D786C: @ 0x080D786C
	push {lr}
	movs r1, #0
	bl sub_080C48F0
	pop {r0}
	bx r0

	thumb_func_start sub_080D7878
sub_080D7878: @ 0x080D7878
	ldr r1, .L080D788C
	ldr r0, .L080D7890
	str r0, [r1]
	ldr r0, .L080D7894
	str r0, [r1, #4]
	ldr r0, .L080D7898
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D788C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D7890: .4byte 0x02001000 @ EWRAM+0x1000
.L080D7894: .4byte 0x06016000 @ VRAM+0x16000
.L080D7898: .4byte 0x84000200

	thumb_func_start sub_080D789C
sub_080D789C: @ 0x080D789C
	ldr r1, .L080D78B0
	ldr r0, .L080D78B4
	str r0, [r1]
	ldr r0, .L080D78B8
	str r0, [r1, #4]
	ldr r0, .L080D78BC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D78B0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D78B4: .4byte 0x02001800 @ EWRAM+0x1800
.L080D78B8: .4byte 0x06016800 @ VRAM+0x16800
.L080D78BC: .4byte 0x84000200

	thumb_func_start sub_080D78C0
sub_080D78C0: @ 0x080D78C0
	ldr r1, .L080D78D4
	ldr r0, .L080D78D8
	str r0, [r1]
	ldr r0, .L080D78DC
	str r0, [r1, #4]
	ldr r0, .L080D78E0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D78D4: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D78D8: .4byte 0x02002000 @ EWRAM+0x2000
.L080D78DC: .4byte 0x06017000 @ VRAM+0x17000
.L080D78E0: .4byte 0x84000200

	thumb_func_start sub_080D78E4
sub_080D78E4: @ 0x080D78E4
	ldr r1, .L080D78F8
	ldr r0, .L080D78FC
	str r0, [r1]
	ldr r0, .L080D7900
	str r0, [r1, #4]
	ldr r0, .L080D7904
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D78F8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D78FC: .4byte 0x02002800 @ EWRAM+0x2800
.L080D7900: .4byte 0x06017800 @ VRAM+0x17800
.L080D7904: .4byte 0x84000200

	thumb_func_start sub_080D7908
sub_080D7908: @ 0x080D7908
	ldr r1, .L080D791C
	ldr r0, .L080D7920
	str r0, [r1]
	ldr r0, .L080D7924
	str r0, [r1, #4]
	ldr r0, .L080D7928
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D791C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D7920: .4byte 0x02003000 @ EWRAM+0x3000
.L080D7924: .4byte 0x06015000 @ VRAM+0x15000
.L080D7928: .4byte 0x84000200

	thumb_func_start sub_080D792C
sub_080D792C: @ 0x080D792C
	ldr r1, .L080D7940
	ldr r0, .L080D7944
	str r0, [r1]
	ldr r0, .L080D7948
	str r0, [r1, #4]
	ldr r0, .L080D794C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D7940: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D7944: .4byte 0x02003800 @ EWRAM+0x3800
.L080D7948: .4byte 0x06015800 @ VRAM+0x15800
.L080D794C: .4byte 0x84000200

	thumb_func_start sub_080D7950
sub_080D7950: @ 0x080D7950
.L080D7950:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r4, r0, #0
	mov r8, r1
	mov sb, r2
	ldrh r0, [r4, #6]
	bl sub_080D95F4
	adds r7, r0, #0
	ldrh r1, [r4, #2]
	ldrh r0, [r4, #4]
	cmp r0, #0
	beq .L080D79A6
	ldr r0, .L080D79B4
	lsls r6, r1, #2
	adds r0, r6, r0
	ldr r5, [r0]
	lsls r1, r1, #0xb
	ldr r0, .L080D79B8
	adds r1, r1, r0
	mov r0, r8
	bl LZ77UnCompWram
	mov r0, sb
	cmp r0, #0
	bne .L080D799A
	ldr r1, [r7, #0x24]
	ldr r0, [sp, #0x20]
	str r0, [sp]
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl sub_080C3F4C
.L080D799A:
	ldr r0, .L080D79BC
	adds r0, r6, r0
	ldr r0, [r0]
	movs r1, #1
	bl VBlankTask_AddCounted
.L080D79A6:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080D79B4: .4byte gUnknown_0855FA84
.L080D79B8: .4byte 0x02001000 @ EWRAM+0x1000
.L080D79BC: .4byte gUnknown_0855FA9C

	thumb_func_start sub_080D79C0
sub_080D79C0: @ 0x080D79C0
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
	bl sub_080D95F4
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
	bl sub_080D7950
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D7A04
sub_080D7A04: @ 0x080D7A04
.L080D7A04:
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0
	bl sub_080B2EFC
	movs r1, #0x23
	bl sub_080B3038
	adds r1, r0, #0
	ldr r0, .L080D7A34
	movs r2, #0xac
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080D7A38
	cmp r1, #0
	beq .L080D7A38
	ldrh r0, [r1, #2]
	cmp r0, #4
	bne .L080D7A38
	movs r0, #1
	b .L080D7A3A
.L080D7A34: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080D7A38:
	movs r0, #0
.L080D7A3A:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D7A44
sub_080D7A44: @ 0x080D7A44
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080D7A04
	ldrh r0, [r4, #0x1c]
	cmp r0, #0
	bne .L080D7A5A
	adds r0, r4, #0
	bl sub_080C41F4
	b .L080D7A78
.L080D7A5A:
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r0, #2]
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq .L080D7A78
	ldr r0, .L080D7A80
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl PalFade_FadeRangeToBlackTagged
.L080D7A78:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D7A80: .4byte gUnknown_0855FA84

	thumb_func_start sub_080D7A84
sub_080D7A84: @ 0x080D7A84
.L080D7A84:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	ldrh r6, [r5, #2]
	mov sb, r6
	adds r0, r5, #0
	str r1, [sp, #0x10]
	bl sub_080C4388
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov sl, r2
	ldrh r0, [r5, #0xa]
	mov r8, r0
	ldr r0, .L080D7AE0
	ldrh r0, [r0]
	mov r3, r8
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r8, r7
	adds r0, r4, #0
	str r2, [sp, #0x14]
	bl sub_080D7A04
	ldrh r0, [r4, #0x1c]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	cmp r0, #0
	bne .L080D7AEE
	cmp r6, #0
	beq .L080D7AF2
	cmp r6, #1
	bne .L080D7AE4
	ldrh r0, [r5, #0x10]
	str r0, [sp]
	movs r0, #0xe0
	lsls r0, r0, #2
	b .L080D7B18
	.byte 0x00, 0x00
.L080D7AE0: .4byte 0x0300000E @ IWRAM+0xE
.L080D7AE4:
	ldrh r0, [r5, #0x10]
	str r0, [sp]
	movs r0, #0xa0
	lsls r0, r0, #2
	b .L080D7B36
.L080D7AEE:
	cmp r6, #0
	bne .L080D7B0C
.L080D7AF2:
	ldrh r0, [r5, #0x10]
	str r0, [sp]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r5, #8]
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r5, #0
	movs r3, #0xe
	bl sub_080C44CC
	b .L080D7BA2
.L080D7B0C:
	cmp r6, #1
	bne .L080D7B2A
	ldrh r0, [r5, #0x10]
	str r0, [sp]
	movs r0, #0xd0
	lsls r0, r0, #2
.L080D7B18:
	str r0, [sp, #4]
	ldrh r0, [r5, #8]
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r5, #0
	movs r3, #0xf
	bl sub_080C44CC
	b .L080D7BA2
.L080D7B2A:
	cmp r6, #2
	bne .L080D7B48
	ldrh r0, [r5, #0x10]
	str r0, [sp]
	movs r0, #0xe0
	lsls r0, r0, #2
.L080D7B36:
	str r0, [sp, #4]
	ldrh r0, [r5, #8]
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r5, #0
	movs r3, #0xd
	bl sub_080C44CC
	b .L080D7BA2
.L080D7B48:
	cmp r6, #3
	bne .L080D7B66
	ldrh r0, [r5, #0x10]
	str r0, [sp]
	movs r0, #0xf0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r5, #8]
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r5, #0
	movs r3, #0xc
	bl sub_080C44CC
	b .L080D7BA2
.L080D7B66:
	mov r0, sb
	cmp r0, #4
	bne .L080D7B86
	ldrh r0, [r5, #0x10]
	str r0, [sp]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r5, #8]
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r5, #0
	movs r3, #0xb
	bl sub_080C44CC
	b .L080D7BA2
.L080D7B86:
	ldrh r0, [r5, #0x10]
	str r0, [sp]
	movs r0, #0xb0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r5, #8]
	str r0, [sp, #8]
	mov r3, r8
	str r3, [sp, #0xc]
	adds r0, r5, #0
	mov r2, sl
	movs r3, #0xa
	bl sub_080C44CC
.L080D7BA2:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D7BB4
sub_080D7BB4: @ 0x080D7BB4
	push {lr}
	ldr r1, .L080D7BC0
	bl sub_080D7A84
	pop {r0}
	bx r0
.L080D7BC0: .4byte gUnknown_080050C4

	thumb_func_start sub_080D7BC4
sub_080D7BC4: @ 0x080D7BC4
	strh r1, [r0, #0x2e]
	bx lr

	thumb_func_start sub_080D7BC8
sub_080D7BC8: @ 0x080D7BC8
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldr r2, .L080D7BE0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	bl Task_Create
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
.L080D7BE0: .4byte gUnknown_0855FAB4

	thumb_func_start sub_080D7BE4
sub_080D7BE4: @ 0x080D7BE4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x24
	ldrh r0, [r4, #6]
	bl sub_080D95F4
	ldr r5, [r0, #0x28]
	ldrh r0, [r5, #0xc]
	strh r0, [r4, #0x1a]
	ldrh r4, [r5, #0x14]
	cmp r4, #1
	bne .L080D7C28
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl sub_080D77FC
	str r4, [sp]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl sub_080D77FC
	ldrh r0, [r5, #0x16]
	cmp r0, #0
	beq .L080D7C28
	bl sub_080C51D4
.L080D7C28:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_080D7C30
sub_080D7C30: @ 0x080D7C30
.L080D7C30:
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x24
	ldrh r2, [r6, #2]
	ldrh r4, [r1, #0x10]
	ldrh r5, [r1, #0x12]
	ldr r0, .L080D7CA0
	cmp r4, r0
	bne .L080D7C56
	movs r4, #0xc0
	lsls r4, r4, #2
	cmp r2, #0
	beq .L080D7C56
	subs r4, #0x80
	cmp r2, #1
	bne .L080D7C56
	movs r4, #0xe0
	lsls r4, r4, #2
.L080D7C56:
	ldr r0, .L080D7CA0
	cmp r5, r0
	bne .L080D7C6A
	movs r5, #0xe
	cmp r2, #0
	beq .L080D7C6A
	movs r5, #0xd
	cmp r2, #1
	bne .L080D7C6A
	movs r5, #0xf
.L080D7C6A:
	ldr r1, [r1, #8]
	ldr r0, .L080D7CA4
	cmp r1, r0
	bne .L080D7C7A
	adds r0, r6, #0
	bl sub_080C43B4
	adds r1, r0, #0
.L080D7C7A:
	ldrh r2, [r6, #6]
	adds r0, r2, #0
	subs r0, #0xaa
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L080D7C8C
	cmp r2, #0xf5
	bne .L080D7C90
.L080D7C8C:
	movs r0, #1
	strh r0, [r6, #0x10]
.L080D7C90:
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080C43F8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080D7CA0: .4byte 0x0000FFFF
.L080D7CA4: .4byte gUnknown_08004FF8

	thumb_func_start sub_080D7CA8
sub_080D7CA8: @ 0x080D7CA8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	ldrh r0, [r5, #6]
	bl sub_080D95F4
	adds r7, r0, #0
	ldr r4, [r7, #0x28]
	ldrh r0, [r5, #0x1a]
	subs r0, #1
	strh r0, [r5, #0x1a]
	ldr r1, .L080D7CF0
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne .L080D7D44
	ldrh r0, [r5, #0x18]
	adds r0, #1
	strh r0, [r5, #0x18]
	ldrh r1, [r5, #0x18]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r4, r4, r0
	ldrh r1, [r4, #0xc]
	cmp r1, r3
	bne .L080D7CF4
	adds r0, r6, #0
	movs r1, #0
	bl sub_080C48F0
	b .L080D7D56
	.byte 0x00, 0x00
.L080D7CF0: .4byte 0x0000FFFF
.L080D7CF4:
	ldr r0, .L080D7D40
	cmp r1, r0
	bne .L080D7CFE
	strh r2, [r5, #0x18]
	ldr r4, [r7, #0x28]
.L080D7CFE:
	ldrh r0, [r4, #0xc]
	strh r0, [r5, #0x1a]
	ldr r0, [r4]
	cmp r0, #0
	beq .L080D7D34
	ldrh r5, [r4, #0x14]
	cmp r5, #1
	bne .L080D7D34
	str r2, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #0
	bl sub_080D77FC
	str r5, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #0
	bl sub_080D77FC
	ldrh r0, [r4, #0x16]
	cmp r0, #0
	beq .L080D7D34
	bl sub_080C51D4
.L080D7D34:
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080D7C30
	b .L080D7D56
	.byte 0x00, 0x00
.L080D7D40: .4byte 0x0000FFFE
.L080D7D44:
	ldrh r1, [r5, #0x18]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r4, r4, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_080D7C30
.L080D7D56:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D7D60
sub_080D7D60: @ 0x080D7D60
.L080D7D60:
	ldr r1, .L080D7D84
	str r0, [r1]
	ldr r2, .L080D7D88
	str r2, [r1, #4]
	ldr r2, .L080D7D8C
	str r2, [r1, #8]
	ldr r2, [r1, #8]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, .L080D7D90
	str r0, [r1, #4]
	ldr r0, .L080D7D94
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D7D84: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D7D88: .4byte 0x06005C40 @ VRAM+0x5C40
.L080D7D8C: .4byte 0x840000F0
.L080D7D90: .4byte 0x06008040 @ VRAM+0x8040
.L080D7D94: .4byte 0x84000370

	thumb_func_start sub_080D7D98
sub_080D7D98: @ 0x080D7D98
.L080D7D98:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r3, r0, #0
	ldr r0, .L080D7E10
	mov ip, r0
	ldr r1, .L080D7E14
	ldr r0, .L080D7E18
	str r0, [r1]
	mov r7, ip
	str r7, [r1, #4]
	ldr r0, .L080D7E1C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
	movs r1, #0x80
	lsls r1, r1, #2
	add r1, ip
	mov r8, r1
	movs r7, #0xf
	mov sb, r7
	ldr r6, .L080D7E20
.L080D7DC6:
	movs r4, #0
	adds r5, r0, #1
	lsls r0, r0, #6
	mov r1, ip
	adds r2, r0, r1
.L080D7DD0:
	ldrb r0, [r3]
	adds r3, #1
	mov r7, sb
	ands r0, r7
	adds r0, #8
	adds r1, r2, r6
	lsls r0, r0, #0xc
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	adds r2, #2
	adds r4, #1
	cmp r4, #0x1b
	bls .L080D7DD0
	adds r0, r5, #0
	cmp r0, #4
	bls .L080D7DC6
	ldr r1, .L080D7E14
	mov r0, r8
	str r0, [r1]
	ldr r0, .L080D7E24
	str r0, [r1, #4]
	ldr r0, .L080D7E28
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D7E10: .4byte 0x02000000 @ EWRAM
.L080D7E14: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D7E18: .4byte gUnknown_081C25F4
.L080D7E1C: .4byte 0x84000400
.L080D7E20: .4byte 0x00000202
.L080D7E24: .4byte 0x06003200 @ VRAM+0x3200
.L080D7E28: .4byte 0x84000050

	thumb_func_start sub_080D7E2C
sub_080D7E2C: @ 0x080D7E2C
	push {lr}
	ldr r0, .L080D7E40
	bl sub_080D7D60
	ldr r0, .L080D7E44
	bl sub_080D7D98
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D7E40: .4byte gUnknown_0855FBA4
.L080D7E44: .4byte gUnknown_08563024

	thumb_func_start sub_080D7E48
sub_080D7E48: @ 0x080D7E48
	push {lr}
	ldr r0, .L080D7E5C
	bl sub_080D7D60
	ldr r0, .L080D7E60
	bl sub_080D7D98
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D7E5C: .4byte gUnknown_08560D24
.L080D7E60: .4byte gUnknown_085630B0

	thumb_func_start sub_080D7E64
sub_080D7E64: @ 0x080D7E64
	push {lr}
	ldr r0, .L080D7E78
	bl sub_080D7D60
	ldr r0, .L080D7E7C
	bl sub_080D7D98
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D7E78: .4byte gUnknown_08561EA4
.L080D7E7C: .4byte gUnknown_0856313C

	thumb_func_start sub_080D7E80
sub_080D7E80: @ 0x080D7E80
	adds r0, #0x24
	movs r1, #0
	str r1, [r0, #0x24]
	movs r1, #8
	str r1, [r0, #0x28]
	bx lr

	thumb_func_start sub_080D7E8C
sub_080D7E8C: @ 0x080D7E8C
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080D7EF2
	bl sub_080B098C
	cmp r0, #1
	beq .L080D7EF2
	ldr r0, [r4, #0x28]
	subs r0, #1
	str r0, [r4, #0x28]
	cmp r0, #0
	bne .L080D7EF2
	movs r0, #8
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x24]
	cmp r0, #1
	beq .L080D7ECC
	cmp r0, #1
	blo .L080D7EC2
	cmp r0, #2
	beq .L080D7EDC
	b .L080D7EE4
.L080D7EC2:
	ldr r0, .L080D7EC8
	b .L080D7ECE
	.byte 0x00, 0x00
.L080D7EC8: .4byte sub_080D7E2C
.L080D7ECC:
	ldr r0, .L080D7ED8
.L080D7ECE:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L080D7EE4
	.byte 0x00, 0x00
.L080D7ED8: .4byte sub_080D7E48
.L080D7EDC:
	ldr r0, .L080D7EF8
	movs r1, #1
	bl VBlankTask_AddCounted
.L080D7EE4:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
	cmp r0, #2
	bls .L080D7EF2
	movs r0, #0
	str r0, [r4, #0x24]
.L080D7EF2:
	pop {r4}
	pop {r0}
	bx r0
.L080D7EF8: .4byte sub_080D7E64

	thumb_func_start sub_080D7EFC
sub_080D7EFC: @ 0x080D7EFC
	ldr r1, .L080D7F10
	ldr r0, .L080D7F14
	str r0, [r1]
	ldr r0, .L080D7F18
	str r0, [r1, #4]
	ldr r0, .L080D7F1C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D7F10: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D7F14: .4byte 0x02001000 @ EWRAM+0x1000
.L080D7F18: .4byte 0x06015000 @ VRAM+0x15000
.L080D7F1C: .4byte 0x84000400

	thumb_func_start sub_080D7F20
sub_080D7F20: @ 0x080D7F20
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	ldr r0, .L080D7F80
	ldr r4, .L080D7F84
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080D7F88
	ldr r0, .L080D7F8C
	str r0, [r1]
	movs r0, #0xfc
	lsls r0, r0, #4
	adds r4, r4, r0
	str r4, [r1, #4]
	ldr r0, .L080D7F90
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, .L080D7F94
	ldr r2, .L080D7F98
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
	ldr r0, .L080D7F9C
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r1, #0
	strh r1, [r5, #8]
	movs r0, #0x18
	strh r0, [r5, #0xa]
	strh r1, [r6, #0x1e]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D7F80: .4byte gUnknown_085632F4
.L080D7F84: .4byte 0x02001000 @ EWRAM+0x1000
.L080D7F88: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D7F8C: .4byte gUnknown_08563A5C
.L080D7F90: .4byte 0x84000010
.L080D7F94: .4byte gUnknown_08563AC0
.L080D7F98: .4byte 0x03002D50 @ IWRAM+0x2D50
.L080D7F9C: .4byte sub_080D7EFC

	thumb_func_start sub_080D7FA0
sub_080D7FA0: @ 0x080D7FA0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x24
	ldr r0, .L080D8020
	movs r4, #0xa0
	lsls r4, r4, #2
	str r4, [sp]
	ldrh r2, [r6, #8]
	movs r1, #0x58
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrh r1, [r6, #0xa]
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080D8024
	str r4, [sp]
	ldrh r1, [r6, #8]
	adds r1, #0x78
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrh r1, [r6, #0xa]
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	ldrh r2, [r5, #0x1e]
	cmp r2, #0
	beq .L080D8052
	ldr r0, .L080D8028
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080D8052
	cmp r2, #1
	bne .L080D8034
	ldr r0, .L080D802C
	ldr r1, .L080D8030
	str r1, [sp]
	movs r1, #0x64
	str r1, [sp, #4]
	ldrh r1, [r6, #0xa]
	subs r1, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
	b .L080D8052
.L080D8020: .4byte gUnknown_08002C88
.L080D8024: .4byte gUnknown_08002C70
.L080D8028: .4byte 0x030031BC @ IWRAM+0x31BC
.L080D802C: .4byte gUnknown_08002CBC
.L080D8030: .4byte 0x000002FE
.L080D8034:
	ldr r0, .L080D805C
	ldr r1, .L080D8060
	str r1, [sp]
	movs r1, #0x64
	str r1, [sp, #4]
	ldrh r1, [r6, #0xa]
	subs r1, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0xd
	movs r3, #0
	bl Sprite_Draw
.L080D8052:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D805C: .4byte gUnknown_08002CCC
.L080D8060: .4byte 0x000002FE

	thumb_func_start sub_080D8064
sub_080D8064: @ 0x080D8064
	adds r0, #0x24
	ldrh r2, [r0, #0xa]
	adds r2, r2, r1
	strh r2, [r0, #0xa]
	ldr r2, .L080D8078
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080D8078: .4byte 0x0300000E @ IWRAM+0xE

	thumb_func_start sub_080D807C
sub_080D807C: @ 0x080D807C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	movs r0, #0
	bl sub_080B29A8
	movs r0, #0
	strh r0, [r5, #8]
	strh r0, [r4, #0x1e]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080D8098
sub_080D8098: @ 0x080D8098
	adds r0, #0x24
	ldrh r1, [r0, #8]
	adds r1, #1
	strh r1, [r0, #8]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D80A4
sub_080D80A4: @ 0x080D80A4
	movs r1, #0
	strh r1, [r0, #0x1e]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080D80AC
sub_080D80AC: @ 0x080D80AC
	ldr r0, .L080D80BC
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L080D80C0
	strb r1, [r0]
	ldr r0, .L080D80C4
	strb r1, [r0]
	bx lr
.L080D80BC: .4byte 0x03000038 @ IWRAM+0x38
.L080D80C0: .4byte 0x03000039 @ IWRAM+0x39
.L080D80C4: .4byte 0x0300003A @ IWRAM+0x3A

	thumb_func_start sub_080D80C8
sub_080D80C8: @ 0x080D80C8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	ldr r0, .L080D8128
	ldr r4, .L080D812C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080D8130
	ldr r0, .L080D8134
	str r0, [r1]
	movs r0, #0xfc
	lsls r0, r0, #4
	adds r4, r4, r0
	str r4, [r1, #4]
	ldr r0, .L080D8138
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, .L080D813C
	ldr r2, .L080D8140
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
	ldr r0, .L080D8144
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r1, #0
	strh r1, [r5, #8]
	movs r0, #0x18
	strh r0, [r5, #0xa]
	strh r1, [r6, #0x1e]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080D8128: .4byte gUnknown_08563BD8
.L080D812C: .4byte 0x02001000 @ EWRAM+0x1000
.L080D8130: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D8134: .4byte gUnknown_08564358
.L080D8138: .4byte 0x84000010
.L080D813C: .4byte gUnknown_085643BC
.L080D8140: .4byte 0x03002D50 @ IWRAM+0x2D50
.L080D8144: .4byte sub_080D7EFC

	thumb_func_start sub_080D8148
sub_080D8148: @ 0x080D8148
	ldr r1, .L080D815C
	ldr r0, .L080D8160
	str r0, [r1]
	ldr r0, .L080D8164
	str r0, [r1, #4]
	ldr r0, .L080D8168
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080D815C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080D8160: .4byte 0x02001000 @ EWRAM+0x1000
.L080D8164: .4byte 0x06016000 @ VRAM+0x16000
.L080D8168: .4byte 0x84000400

	thumb_func_start sub_080D816C
sub_080D816C: @ 0x080D816C
	push {r4, lr}
	sub sp, #4
	ldr r0, .L080D81A8
	ldr r4, .L080D81AC
	adds r1, r4, #0
	bl HuffUnComp
	ldr r1, .L080D81B0
	adds r0, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080D81B4
	ldr r2, .L080D81B8
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_FillWithEffect
	bl Palette_MarkDirty
	ldr r0, .L080D81BC
	movs r1, #1
	bl VBlankTask_AddCounted
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080D81A8: .4byte gUnknown_086BF890
.L080D81AC: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L080D81B0: .4byte 0x02001000 @ EWRAM+0x1000
.L080D81B4: .4byte 0x00007FFF
.L080D81B8: .4byte 0x03003170 @ IWRAM+0x3170
.L080D81BC: .4byte sub_080D8148

	thumb_func_start sub_080D81C0
sub_080D81C0: @ 0x080D81C0
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl sub_080C4388
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, .L080D820C
	ldr r0, [r0]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L080D8214
	ldr r1, .L080D8210
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldrh r0, [r4, #0xa]
	subs r0, #0x13
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0xe
	bl sub_080C44CC
	b .L080D823C
	.byte 0x00, 0x00
.L080D820C: .4byte 0x030031BC @ IWRAM+0x31BC
.L080D8210: .4byte gUnknown_08118CC4
.L080D8214:
	ldr r1, .L080D8244
	ldrh r0, [r4, #0x10]
	str r0, [sp]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [sp, #4]
	ldrh r0, [r4, #8]
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldrh r0, [r4, #0xa]
	subs r0, #0x13
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0xe
	bl sub_080C44CC
.L080D823C:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
.L080D8244: .4byte gUnknown_08118CE0
