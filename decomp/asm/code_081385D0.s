	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start ScriptOp_44C
ScriptOp_44C: @ 0x081385D0
	push {lr}
	ldr r2, .L081385F0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L081385F4
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_08138390
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081385F0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081385F4: .4byte 0x03006950 @ IWRAM+0x6950

	thumb_func_start ScriptOp_412
ScriptOp_412: @ 0x081385F8
	push {lr}
	ldr r2, .L0813862C
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08138630
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_0813848C
	ldr r0, .L08138634
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L08138638
	strh r1, [r0]
	ldr r0, .L0813863C
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	pop {r0}
	bx r0
.L0813862C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138630: .4byte 0x03006950 @ IWRAM+0x6950
.L08138634: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L08138638: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813863C: .4byte 0x0203DB3A @ EWRAM+0x3DB3A

	thumb_func_start sub_08138640
sub_08138640: @ 0x08138640
.L08138640:
	push {r4, r5, lr}
	movs r4, #0x96
	lsls r4, r4, #1
	ldr r5, .L08138658
.L08138648:
	adds r0, r4, #0
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0813865C
	movs r0, #1
	b .L08138668
.L08138658: .4byte 0x00000159
.L0813865C:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	bls .L08138648
	movs r0, #0
.L08138668:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08138670
sub_08138670: @ 0x08138670
.L08138670:
	push {lr}
	ldr r0, .L08138684
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08138688
	movs r0, #0
	b .L0813868A
	.byte 0x00, 0x00
.L08138684: .4byte 0x0000011F
.L08138688:
	movs r0, #1
.L0813868A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08138690
sub_08138690: @ 0x08138690
.L08138690:
	push {r4, r5, r6, lr}
	bl Stock_GetCapacity
	adds r5, r0, #0
	movs r4, #4
	adds r0, r5, #4
	cmp r4, r0
	bge .L081386D4
	ldr r0, .L081386C8
	adds r6, r0, #0
.L081386A4:
	adds r0, r4, #0
	bl Combatant_IsAlive
	cmp r0, #0
	beq .L081386CC
	adds r0, r4, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x11
	bhi .L081386CC
	movs r0, #1
	b .L081386D6
	.byte 0x00, 0x00
.L081386C8: .4byte 0xFFFFFE96
.L081386CC:
	adds r4, #1
	adds r0, r5, #4
	cmp r4, r0
	blt .L081386A4
.L081386D4:
	movs r0, #0
.L081386D6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Negotiate_SelectResponse
Negotiate_SelectResponse: @ 0x081386DC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x80
	ldr r4, .L08138758
	ldrh r0, [r4]
	adds r1, r0, #1
	strh r1, [r4]
	lsls r0, r0, #0x10
	ldr r1, .L0813875C
	ldr r2, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r1, [r0]
	lsrs r0, r1, #8
	adds r7, r0, #1
	movs r5, #0xff
	ands r5, r1
	movs r3, #0
	cmp r3, r7
	bhs .L08138734
	adds r6, r4, #0
	adds r4, r2, #0
.L08138706:
	ldrh r0, [r6]
	adds r1, r0, #1
	strh r1, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r2, [r0]
	adds r0, r1, #1
	strh r0, [r6]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	orrs r1, r2
	lsls r0, r3, #2
	.2byte 0x4468 @ add r0, sp, r0
	str r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r7
	blo .L08138706
.L08138734:
	cmp r5, #1
	bne .L08138770
	movs r0, #0x40
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08138746
	b .L08138B88
.L08138746:
	movs r0, #0x40
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138764
	ldr r1, .L08138760
	ldr r0, [sp, #8]
	b .L08138B8C
.L08138758: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813875C: .4byte 0x03006950 @ IWRAM+0x6950
.L08138760: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138764:
	ldr r1, .L0813876C
	ldr r0, [sp, #4]
	b .L08138B8C
	.byte 0x00, 0x00
.L0813876C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138770:
	cmp r5, #2
	bne .L081387E0
	movs r0, #1
	bl sub_08137720
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138782
	b .L08138B88
.L08138782:
	movs r0, #9
	bl Flag_Test
	cmp r0, #0
	beq .L081387C8
.L0813878C:
	movs r0, #1
	bl sub_0813C4FC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081387BC
	movs r0, #0x80
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081387B0
	ldr r1, .L081387AC
	ldr r0, [sp, #4]
	b .L08138B8C
	.byte 0x00, 0x00
.L081387AC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081387B0:
	ldr r1, .L081387B8
	ldr r0, [sp, #8]
	b .L08138B8C
	.byte 0x00, 0x00
.L081387B8: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081387BC:
	ldr r1, .L081387C4
	ldr r0, [sp, #0x10]
	b .L08138B8C
	.byte 0x00, 0x00
.L081387C4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081387C8:
	movs r0, #1
	bl sub_081379CC
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0813878C
	ldr r1, .L081387DC
	ldr r0, [sp, #0xc]
	b .L08138B8C
	.byte 0x00, 0x00
.L081387DC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081387E0:
	cmp r5, #3
	bne .L08138844
	movs r0, #1
	bl sub_08137720
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081387F2
	b .L08138B88
.L081387F2:
	movs r0, #1
	bl sub_0813C4FC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138808
	ldr r1, .L08138804
	ldr r0, [sp, #4]
	b .L08138B8C
.L08138804: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138808:
	movs r0, #0x40
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138820
	ldr r1, .L0813881C
	ldr r0, [sp, #8]
	b .L08138B8C
	.byte 0x00, 0x00
.L0813881C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138820:
	movs r0, #0x80
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138838
	ldr r1, .L08138834
	ldr r0, [sp, #0xc]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138834: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138838:
	ldr r1, .L08138840
	ldr r0, [sp, #0x10]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138840: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138844:
	cmp r5, #4
	bne .L081388AC
	movs r0, #1
	bl sub_08137720
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138856
	b .L08138B88
.L08138856:
	movs r0, #2
	bl sub_08137720
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813886C
	ldr r1, .L08138868
	ldr r0, [sp, #4]
	b .L08138B8C
.L08138868: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813886C:
	movs r0, #2
	bl sub_0813821C
	movs r0, #0x80
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138888
	ldr r1, .L08138884
	ldr r0, [sp, #8]
	b .L08138B8C
.L08138884: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138888:
	movs r0, #0x40
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081388A0
	ldr r1, .L0813889C
	ldr r0, [sp, #0xc]
	b .L08138B8C
	.byte 0x00, 0x00
.L0813889C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081388A0:
	ldr r1, .L081388A8
	ldr r0, [sp, #0x10]
	b .L08138B8C
	.byte 0x00, 0x00
.L081388A8: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081388AC:
	cmp r5, #5
	bne .L08138914
	movs r0, #1
	bl sub_08137720
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081388BE
	b .L08138B88
.L081388BE:
	movs r0, #2
	bl sub_08137720
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081388D4
	ldr r1, .L081388D0
	ldr r0, [sp, #4]
	b .L08138B8C
.L081388D0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081388D4:
	movs r0, #2
	bl sub_0813821C
	movs r0, #0x80
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081388F0
	ldr r1, .L081388EC
	ldr r0, [sp, #8]
	b .L08138B8C
.L081388EC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081388F0:
	movs r0, #0x80
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138908
	ldr r1, .L08138904
	ldr r0, [sp, #0xc]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138904: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138908:
	ldr r1, .L08138910
	ldr r0, [sp, #0x10]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138910: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138914:
	cmp r5, #6
	bne .L08138988
	movs r0, #1
	bl sub_08137720
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138926
	b .L08138B88
.L08138926:
	movs r0, #2
	bl sub_0813C4FC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813893C
	ldr r1, .L08138938
	ldr r0, [sp, #4]
	b .L08138B8C
.L08138938: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813893C:
	movs r0, #3
	bl sub_0813C4FC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138954
	ldr r1, .L08138950
	ldr r0, [sp, #8]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138950: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138954:
	bl sub_0813AC98
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #1
	bne .L0813896C
	ldr r1, .L08138968
	ldr r0, [sp, #0xc]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138968: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813896C:
	cmp r3, #2
	bne .L0813897C
	ldr r1, .L08138978
	ldr r0, [sp, #0x10]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138978: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813897C:
	ldr r1, .L08138984
	ldr r0, [sp, #0x14]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138984: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138988:
	cmp r5, #7
	bne .L081389F0
	movs r0, #1
	bl sub_08137720
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0813899A
	b .L08138B88
.L0813899A:
	movs r0, #2
	bl sub_08137720
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081389C8
	movs r0, #0x80
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081389BC
	ldr r1, .L081389B8
	ldr r0, [sp, #0xc]
	b .L08138B8C
.L081389B8: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081389BC:
	ldr r1, .L081389C4
	ldr r0, [sp, #0x10]
	b .L08138B8C
	.byte 0x00, 0x00
.L081389C4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081389C8:
	movs r0, #2
	bl sub_0813821C
	movs r0, #0x40
	bl sub_081376AC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L081389E4
	ldr r1, .L081389E0
	ldr r0, [sp, #4]
	b .L08138B8C
.L081389E0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081389E4:
	ldr r1, .L081389EC
	ldr r0, [sp, #8]
	b .L08138B8C
	.byte 0x00, 0x00
.L081389EC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081389F0:
	cmp r5, #8
	bne .L08138AB0
	movs r0, #1
	bl sub_08137720
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138A64
	bl sub_08138338
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne .L08138A0E
	b .L08138B88
.L08138A0E:
	cmp r3, #1
	bne .L08138A1C
	ldr r1, .L08138A18
	ldr r0, [sp, #4]
	b .L08138B8C
.L08138A18: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138A1C:
	cmp r3, #2
	bne .L08138A2C
	ldr r1, .L08138A28
	ldr r0, [sp, #8]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138A28: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138A2C:
	cmp r3, #3
	bne .L08138A64
	bl sub_0813BF78
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138A44
	ldr r1, .L08138A40
	ldr r0, [sp, #0xc]
	b .L08138B8C
.L08138A40: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138A44:
	bl sub_0813BF58
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138A58
	ldr r1, .L08138A54
	ldr r0, [sp, #0x14]
	b .L08138B8C
.L08138A54: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138A58:
	ldr r1, .L08138A60
	ldr r0, [sp, #0x10]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138A60: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138A64:
	movs r0, #2
	bl sub_0813C4FC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138A7C
	ldr r1, .L08138A78
	ldr r0, [sp, #0x18]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138A78: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138A7C:
	bl sub_0813AC98
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #1
	bne .L08138A94
	ldr r1, .L08138A90
	ldr r0, [sp, #0x1c]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138A90: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138A94:
	cmp r3, #2
	bne .L08138AA4
	ldr r1, .L08138AA0
	ldr r0, [sp, #0x20]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138AA0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138AA4:
	ldr r1, .L08138AAC
	ldr r0, [sp, #0x24]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138AAC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138AB0:
	cmp r5, #0xa
	bne .L08138ACC
	ldr r1, .L08138AC4
	ldr r0, .L08138AC8
	ldrh r0, [r0]
	lsls r0, r0, #2
	.2byte 0x4468 @ add r0, sp, r0
	ldr r0, [r0]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138AC4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138AC8: .4byte 0x0203DB72 @ EWRAM+0x3DB72
.L08138ACC:
	cmp r5, #0xb
	bne .L08138B8E
	movs r0, #0
	bl Combatant_GetLevel
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	bgt .L08138AF4
	bl sub_08138640
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138B88
	ldr r1, .L08138AF0
	ldr r0, [sp, #4]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138AF0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138AF4:
	bl sub_08138640
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138B48
	bl sub_08138670
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138B28
	bl sub_08138690
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138B1C
	ldr r1, .L08138B18
	ldr r0, [sp, #0x14]
	b .L08138B8C
.L08138B18: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138B1C:
	ldr r1, .L08138B24
	ldr r0, [sp, #0x18]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138B24: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138B28:
	bl sub_08138690
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138B3C
	ldr r1, .L08138B38
	ldr r0, [sp, #0x1c]
	b .L08138B8C
.L08138B38: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138B3C:
	ldr r1, .L08138B44
	ldr r0, [sp, #4]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138B44: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138B48:
	bl sub_08138670
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138B74
	bl sub_08138690
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138B68
	ldr r1, .L08138B64
	ldr r0, [sp, #0x10]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138B64: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138B68:
	ldr r1, .L08138B70
	ldr r0, [sp, #8]
	b .L08138B8C
	.byte 0x00, 0x00
.L08138B70: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138B74:
	bl sub_08138690
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L08138B88
	ldr r1, .L08138B84
	ldr r0, [sp, #0xc]
	b .L08138B8C
.L08138B84: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08138B88:
	ldr r1, .L08138B98
	ldr r0, [sp]
.L08138B8C:
	str r0, [r1]
.L08138B8E:
	add sp, #0x80
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08138B98: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3E3
ScriptOp_3E3: @ 0x08138B9C
	push {r4, r5, r6, r7, lr}
	ldr r3, .L08138BF0
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08138BF4
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r7, [r0]
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
	ldrh r5, [r0]
	lsls r5, r5, #0x10
	orrs r5, r4
	ldr r0, .L08138BF8
	ldrh r0, [r0]
	movs r1, #9
	bl Demon_GetField
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r6, r4, #0
	cmp r7, #1
	bne .L08138BFC
	bl Random_Byte
	movs r1, #3
	ands r0, r1
	adds r0, r0, r4
	lsls r0, r0, #0x10
	b .L08138C20
.L08138BF0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138BF4: .4byte 0x03006950 @ IWRAM+0x6950
.L08138BF8: .4byte 0x0203DB7C @ EWRAM+0x3DB7C
.L08138BFC:
	cmp r7, #2
	bne .L08138C0E
	bl Random_Byte
	movs r1, #7
	ands r0, r1
	adds r0, r0, r4
	lsls r0, r0, #0x10
	b .L08138C20
.L08138C0E:
	bl Random_Byte
	movs r1, #7
	ands r0, r1
	adds r0, r0, r6
	lsls r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0xa
	adds r0, r0, r1
.L08138C20:
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L08138C2C
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L08138C2C:
	movs r0, #0
	movs r1, #4
	bl Combatant_GetStat
	cmp r4, r0
	blt .L08138C3C
	ldr r0, .L08138C44
	str r5, [r0]
.L08138C3C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08138C44: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOp_3E4
ScriptOp_3E4: @ 0x08138C48
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_3E5
ScriptOp_3E5: @ 0x08138C4C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_08138C50
sub_08138C50: @ 0x08138C50
.L08138C50:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r1, .L08138C70
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L08138C74
	strh r4, [r0]
	adds r0, r4, #0
	bl sub_080EFA88
	cmp r4, #1
	beq .L08138C78
	cmp r4, #2
	beq .L08138C82
	b .L08138C8A
.L08138C70: .4byte 0x03006670 @ IWRAM+0x6670
.L08138C74: .4byte 0x0203DB70 @ EWRAM+0x3DB70
.L08138C78:
	movs r0, #2
	rsbs r0, r0, #0
	bl sub_080EFA20
	b .L08138C8A
.L08138C82:
	movs r0, #2
	rsbs r0, r0, #0
	bl sub_080EFA44
.L08138C8A:
	ldr r0, .L08138CC8
	movs r4, #0
	strh r4, [r0]
	ldr r0, .L08138CCC
	strh r4, [r0]
	ldr r0, .L08138CD0
	strh r4, [r0]
	ldr r0, .L08138CD4
	strh r4, [r0]
	ldr r0, .L08138CD8
	movs r5, #1
	strh r5, [r0]
	movs r0, #0
	bl sub_0813EB6C
	ldr r0, .L08138CDC
	strh r4, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r0, .L08138CE0
	ldr r0, [r0]
	bl Task_End
	ldr r0, .L08138CE4
	strh r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08138CC8: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L08138CCC: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L08138CD0: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L08138CD4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138CD8: .4byte 0x0203DB46 @ EWRAM+0x3DB46
.L08138CDC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08138CE0: .4byte 0x030069E4 @ IWRAM+0x69E4
.L08138CE4: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start sub_08138CE8
sub_08138CE8: @ 0x08138CE8
.L08138CE8:
	push {lr}
	bl Battle_IsPartyDefeated
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L08138D00
	movs r0, #7
	bl sub_08138C50
	movs r0, #2
	b .L08138D14
.L08138D00:
	bl sub_080ED9F4
	cmp r0, #0
	beq .L08138D0C
	movs r0, #0
	b .L08138D14
.L08138D0C:
	movs r0, #0xc
	bl sub_08138C50
	movs r0, #1
.L08138D14:
	pop {r1}
	bx r1

	thumb_func_start ScriptOp_3E6
ScriptOp_3E6: @ 0x08138D18
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, .L08138D44
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08138D48
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_08138C50
	ldr r1, .L08138D4C
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
.L08138D44: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138D48: .4byte 0x03006950 @ IWRAM+0x6950
.L08138D4C: .4byte 0x0203DB86 @ EWRAM+0x3DB86

	thumb_func_start ScriptOp_401
ScriptOp_401: @ 0x08138D50
	push {r4, lr}
	ldr r2, .L08138D90
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08138D94
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	orrs r1, r0
	ldr r4, .L08138D98
	strh r1, [r4]
	ldr r3, .L08138D9C
	movs r2, #1
	strh r2, [r3]
	ldr r0, .L08138DA0
	strh r2, [r0]
	movs r0, #0x88
	lsls r0, r0, #1
	cmp r1, r0
	bne .L08138DA8
	subs r0, #1
	strh r0, [r4, #2]
	strh r2, [r3, #2]
	ldr r0, .L08138DA4
	strh r2, [r0]
	b .L08138DAE
.L08138D90: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138D94: .4byte 0x03006950 @ IWRAM+0x6950
.L08138D98: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L08138D9C: .4byte 0x03006970 @ IWRAM+0x6970
.L08138DA0: .4byte 0x0203DB66 @ EWRAM+0x3DB66
.L08138DA4: .4byte 0x0203DB68 @ EWRAM+0x3DB68
.L08138DA8:
	ldr r1, .L08138DB4
	movs r0, #0
	strh r0, [r1]
.L08138DAE:
	pop {r4}
	pop {r0}
	bx r0
.L08138DB4: .4byte 0x0203DB68 @ EWRAM+0x3DB68

	thumb_func_start sub_08138DB8
sub_08138DB8: @ 0x08138DB8
	ldr r1, .L08138DC4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08138DC4: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_402
ScriptOp_402: @ 0x08138DC8
	push {r4, r5, lr}
	ldr r3, .L08138E48
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08138E4C
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
	ldr r5, .L08138E50
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
	ldr r0, .L08138E54
	ldrh r0, [r0]
	bl Keypad_OpenNumberEntry
	ldr r1, .L08138E58
	movs r0, #0x4d
	strh r0, [r1]
	ldr r1, .L08138E5C
	movs r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08138E48: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138E4C: .4byte 0x03006950 @ IWRAM+0x6950
.L08138E50: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08138E54: .4byte 0x0203DB84 @ EWRAM+0x3DB84
.L08138E58: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08138E5C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOpAlt_402
ScriptOpAlt_402: @ 0x08138E60
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_403
ScriptOp_403: @ 0x08138E64
	push {lr}
	ldr r2, .L08138E90
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08138E94
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_080BE6E0
	ldr r1, .L08138E98
	movs r0, #0x4a
	strh r0, [r1]
	ldr r1, .L08138E9C
	movs r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08138E90: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138E94: .4byte 0x03006950 @ IWRAM+0x6950
.L08138E98: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08138E9C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOpAlt_403
ScriptOpAlt_403: @ 0x08138EA0
	ldr r1, .L08138EAC
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08138EAC: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_404
ScriptOp_404: @ 0x08138EB0
	push {r4, r5, r6, r7, lr}
	ldr r3, .L08138F08
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08138F0C
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r7, [r0]
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
	ldrh r5, [r0]
	lsls r5, r5, #0x10
	orrs r5, r4
	bl Stock_GetCapacity
	adds r6, r0, #0
	movs r4, #0
	cmp r4, r6
	bhs .L08138F1A
	ldr r1, .L08138F10
	subs r0, r7, #1
	lsls r0, r0, #1
	adds r7, r0, r1
.L08138EF6:
	adds r0, r4, #4
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L08138F14
	ldrh r0, [r7]
	bl Stock_AddDemon
	b .L08138F1E
.L08138F08: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138F0C: .4byte 0x03006950 @ IWRAM+0x6950
.L08138F10: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L08138F14:
	adds r4, #1
	cmp r4, r6
	blo .L08138EF6
.L08138F1A:
	ldr r0, .L08138F24
	str r5, [r0]
.L08138F1E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08138F24: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOpAlt_404
ScriptOpAlt_404: @ 0x08138F28
	ldr r1, .L08138F34
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08138F34: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_405
ScriptOp_405: @ 0x08138F38
	push {r4, r5, r6, lr}
	ldr r3, .L08138F64
	ldr r2, .L08138F68
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08138F6C
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r6, [r0]
	bl Stock_GetCapacity
	adds r5, r0, #0
	movs r4, #4
	b .L08138F76
	.byte 0x00, 0x00
.L08138F64: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L08138F68: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138F6C: .4byte 0x03006950 @ IWRAM+0x6950
.L08138F70:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
.L08138F76:
	adds r0, r5, #4
	cmp r4, r0
	bge .L08138F9C
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L08138F70
	adds r0, r4, #0
	bl Combatant_GetDemonId
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r6
	bne .L08138F70
	adds r0, r4, #0
	movs r1, #1
	bl Party_Remove
.L08138F9C:
	bl sub_080C366C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_405
ScriptOpAlt_405: @ 0x08138FA8
	ldr r1, .L08138FB4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08138FB4: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_406
ScriptOp_406: @ 0x08138FB8
	push {lr}
	ldr r2, .L08138FE0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08138FE4
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0
	bl SceneEffect_Start
	ldr r1, .L08138FE8
	movs r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08138FE0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08138FE4: .4byte 0x03006950 @ IWRAM+0x6950
.L08138FE8: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOpAlt_406
ScriptOpAlt_406: @ 0x08138FEC
	ldr r1, .L08138FF8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08138FF8: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_407
ScriptOp_407: @ 0x08138FFC
	push {lr}
	ldr r2, .L08139024
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08139028
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0
	bl SceneEffect_End
	ldr r1, .L0813902C
	movs r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08139024: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139028: .4byte 0x03006950 @ IWRAM+0x6950
.L0813902C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOpAlt_407
ScriptOpAlt_407: @ 0x08139030
	ldr r1, .L0813903C
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813903C: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_408
ScriptOp_408: @ 0x08139040
	push {lr}
	ldr r2, .L0813906C
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08139070
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #1
	bl SceneEffect_Start
	ldr r1, .L08139074
	movs r0, #0x4a
	strh r0, [r1]
	ldr r1, .L08139078
	movs r0, #1
	strh r0, [r1]
	pop {r0}
	bx r0
.L0813906C: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139070: .4byte 0x03006950 @ IWRAM+0x6950
.L08139074: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08139078: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOpAlt_408
ScriptOpAlt_408: @ 0x0813907C
	ldr r1, .L08139088
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08139088: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_409
ScriptOp_409: @ 0x0813908C
	push {r4, r5, lr}
	ldr r3, .L08139124
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08139128
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
	ldr r5, .L0813912C
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
	ldr r1, .L08139130
	movs r0, #0x48
	strh r0, [r1]
	bl sub_0812F198
	ldr r0, .L08139134
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L08139138
	strh r1, [r0]
	ldr r0, .L0813913C
	movs r4, #1
	strh r4, [r0]
	movs r0, #0
	bl CasinoPrize_DrawList
	ldr r0, .L08139140
	ldr r1, .L08139144
	bl Task_Create
	ldr r0, .L08139148
	strh r4, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
.L08139124: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139128: .4byte 0x03006950 @ IWRAM+0x6950
.L0813912C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08139130: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08139134: .4byte 0x03006940 @ IWRAM+0x6940
.L08139138: .4byte 0x0300696C @ IWRAM+0x696C
.L0813913C: .4byte 0x03006844 @ IWRAM+0x6844
.L08139140: .4byte gUnknown_0878FF48
.L08139144: .4byte 0x0000FFFF
.L08139148: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start CasinoPrize_DrawList
CasinoPrize_DrawList: @ 0x0813914C
.L0813914C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x20]
	bl sub_081394B4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, .L081391A0
	movs r4, #0
	strh r4, [r0]
	ldr r0, .L081391A4
	strh r4, [r0]
	ldr r0, .L081391A8
	strh r4, [r0]
	ldr r0, .L081391AC
	strh r4, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	ldr r5, .L081391B0
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #1
	bne .L0813918E
	bl sub_0812F1E4
.L0813918E:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	bne .L081391BC
	ldr r0, .L081391B4
	strh r2, [r0]
	ldr r1, .L081391B8
	movs r0, #1
	strh r0, [r1]
	b .L081391F6
.L081391A0: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L081391A4: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L081391A8: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L081391AC: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L081391B0: .4byte 0x03006844 @ IWRAM+0x6844
.L081391B4: .4byte 0x03006848 @ IWRAM+0x6848
.L081391B8: .4byte 0x03006680 @ IWRAM+0x6680
.L081391BC:
	ldr r1, .L081391E0
	lsls r0, r6, #5
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #3
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	ldr r3, [sp, #0x20]
	cmp r3, r0
	bne .L081391EC
	ldr r0, .L081391E4
	movs r1, #1
	strh r1, [r0]
	ldr r0, .L081391E8
	strh r4, [r0]
	b .L081391F6
	.byte 0x00, 0x00
.L081391E0: .4byte gUnknown_0878FEA8
.L081391E4: .4byte 0x03006848 @ IWRAM+0x6848
.L081391E8: .4byte 0x03006680 @ IWRAM+0x6680
.L081391EC:
	ldr r0, .L08139240
	movs r1, #1
	strh r1, [r0]
	ldr r0, .L08139244
	strh r1, [r0]
.L081391F6:
	ldr r0, .L08139248
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #3
	str r1, [sp, #0x24]
	cmp r0, #0
	bne .L08139208
	movs r2, #4
	str r2, [sp, #0x24]
.L08139208:
	ldr r4, [sp, #0x20]
	ldr r3, [sp, #0x24]
	adds r0, r4, r3
	cmp r4, r0
	blt .L08139214
	b .L0813947A
.L08139214:
	ldr r3, .L0813924C
	lsls r0, r4, #1
	adds r0, #1
	lsls r0, r0, #1
	lsls r1, r6, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r2, [r0]
	ldr r0, .L08139250
	str r1, [sp, #0x28]
	cmp r2, r0
	bne .L0813922E
	b .L0813947A
.L0813922E:
	cmp r2, #0xcf
	bls .L08139254
	adds r0, r2, #0
	bl Action_GetRecord
	adds r2, r0, #0
	adds r2, #0xc
	b .L0813926A
	.byte 0x00, 0x00
.L08139240: .4byte 0x03006848 @ IWRAM+0x6848
.L08139244: .4byte 0x03006680 @ IWRAM+0x6680
.L08139248: .4byte 0x03006844 @ IWRAM+0x6844
.L0813924C: .4byte gUnknown_0878FEA8
.L08139250: .4byte 0x0000FFFF
.L08139254:
	cmp r2, #0x7f
	bls .L08139260
	adds r0, r2, #0
	bl Equipment_GetRecord36_MidRange
	b .L08139266
.L08139260:
	adds r0, r2, #0
	bl Item_GetRecord
.L08139266:
	adds r2, r0, #0
	adds r2, #0x14
.L0813926A:
	movs r6, #0
	ldr r5, [sp, #0x20]
	subs r5, r4, r5
	mov sb, r5
	lsls r5, r4, #1
	mov r0, sp
	adds r0, #0x10
	str r0, [sp, #0x30]
	adds r4, #1
	str r4, [sp, #0x34]
	ldr r1, [sp, #0x20]
	ldr r3, [sp, #0x24]
	adds r1, r1, r3
	str r1, [sp, #0x2c]
	ldr r3, .L0813948C
	movs r1, #0
.L0813928A:
	lsls r0, r6, #1
	adds r0, r0, r3
	strh r1, [r0]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0xf
	bls .L0813928A
	movs r6, #0
	ldr r3, .L0813948C
.L0813929E:
	lsls r0, r6, #1
	adds r0, r0, r3
	ldrh r1, [r2]
	strh r1, [r0]
	adds r2, #2
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #7
	bls .L0813929E
	ldr r7, .L08139490
	ldr r4, .L08139494
	movs r1, #0
	ldrsh r0, [r4, r1]
	add r0, sb
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r1, [r0]
	movs r0, #0x1a
	movs r2, #0
	movs r3, #8
	bl MsgGlyphQueue_PushSubstClamped
	adds r0, r5, #2
	lsls r0, r0, #1
	ldr r2, [sp, #0x28]
	adds r0, r0, r2
	ldr r3, .L08139498
	adds r0, r0, r3
	ldr r1, .L0813949C
	ldrh r5, [r0]
	cmp r5, r1
	bne .L081392E2
	ldr r5, .L081394A0
.L081392E2:
	movs r6, #0
	adds r2, r1, #0
.L081392E6:
	lsls r0, r6, #1
	mov r3, sp
	adds r1, r3, r0
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #7
	bls .L081392E6
	movs r6, #0
	cmp r5, #0
	beq .L08139332
	ldr r7, .L081394A4
.L08139304:
	lsls r0, r6, #1
	mov r1, sp
	adds r4, r1, r0
	adds r0, r5, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #0xa
	bl __udivsi3
	adds r5, r0, #0
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #7
	bhi .L08139332
	cmp r5, #0
	bne .L08139304
.L08139332:
	movs r7, #0
	movs r0, #7
	ldr r3, [sp, #0x30]
.L08139338:
	lsls r2, r7, #1
	adds r2, r3, r2
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	.2byte 0x4468 @ add r0, sp, r0
	ldrh r0, [r0]
	strh r0, [r2]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	subs r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r1, #0
	bge .L08139338
	movs r7, #0
	movs r6, #0
	ldr r2, .L081394A8
	mov ip, r2
	ldr r4, .L081394AC
	mov sl, r6
	mov r8, sb
.L08139366:
	lsls r0, r6, #1
	ldr r3, [sp, #0x30]
	adds r0, r3, r0
	ldrh r2, [r0]
	ldr r5, .L0813949C
	cmp r2, r5
	beq .L081393E0
	mov r0, ip
	ldrh r3, [r0]
	lsls r0, r3, #0x12
	lsrs r5, r0, #0x10
	adds r0, r5, #0
	movs r1, #1
	orrs r5, r1
	adds r1, r5, #0
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r2, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r2, r5, #0
	lsls r1, r1, #1
	adds r1, r1, r4
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #1
	adds r0, #0x8d
	strh r0, [r1]
	adds r1, r2, #1
	lsls r1, r1, #0x10
	lsls r2, r2, #1
	adds r2, r2, r4
	str r2, [sp, #0x38]
	ldr r2, .L08139494
	movs r5, #0
	ldrsh r0, [r2, r5]
	add r0, r8
	lsls r0, r0, #1
	ldr r2, .L08139490
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r5, [sp, #0x38]
	strh r0, [r5]
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	mov r0, sl
	strh r0, [r1]
	adds r3, #1
	mov r1, ip
	strh r3, [r1]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	cmp r3, #0x3f
	bls .L081393E0
	movs r0, #0x3f
	ldr r2, .L081394A8
	strh r0, [r2]
.L081393E0:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #7
	bls .L08139366
	ldr r3, .L081394A8
	ldrh r4, [r3]
	lsls r0, r4, #0x12
	lsrs r5, r0, #0x10
	adds r1, r5, #0
	movs r0, #1
	orrs r5, r0
	adds r2, r5, #0
	lsls r1, r1, #1
	ldr r5, .L081394AC
	adds r1, r1, r5
	ldr r0, .L081394B0
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r3, r5, #0
	lsls r2, r2, #1
	ldr r0, .L081394AC
	adds r2, r2, r0
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #1
	adds r0, #0x8f
	strh r0, [r2]
	adds r1, r3, #1
	lsls r1, r1, #0x10
	lsls r3, r3, #1
	ldr r2, .L081394AC
	adds r3, r3, r2
	ldr r5, .L08139494
	movs r2, #0
	ldrsh r0, [r5, r2]
	add r0, sb
	lsls r0, r0, #1
	ldr r5, .L08139490
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r3]
	lsrs r1, r1, #0xf
	ldr r0, .L081394AC
	adds r1, r1, r0
	movs r2, #0
	strh r2, [r1]
	adds r4, #1
	ldr r3, .L081394A8
	strh r4, [r3]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #0x3f
	bls .L08139456
	movs r0, #0x3f
	adds r5, r3, #0
	strh r0, [r5]
.L08139456:
	ldr r1, [sp, #0x34]
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	ldr r2, [sp, #0x2c]
	cmp r4, r2
	bge .L0813947A
	lsls r0, r4, #1
	adds r0, #1
	lsls r0, r0, #1
	ldr r3, [sp, #0x28]
	adds r0, r0, r3
	ldr r5, .L08139498
	adds r0, r0, r5
	ldrh r2, [r0]
	ldr r0, .L0813949C
	cmp r2, r0
	beq .L0813947A
	b .L0813922E
.L0813947A:
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813948C: .4byte 0x0203DB08 @ EWRAM+0x3DB08
.L08139490: .4byte gUnknown_08790390
.L08139494: .4byte 0x03006844 @ IWRAM+0x6844
.L08139498: .4byte gUnknown_0878FEA8
.L0813949C: .4byte 0x0000FFFF
.L081394A0: .4byte 0x000186A0
.L081394A4: .4byte gScriptDigitGlyphs
.L081394A8: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L081394AC: .4byte 0x0203D800 @ EWRAM+0x3D800
.L081394B0: .4byte 0x00000FC8

	thumb_func_start sub_081394B4
sub_081394B4: @ 0x081394B4
.L081394B4:
	push {lr}
	movs r0, #0xb9
	bl Flag_Test
	cmp r0, #1
	bne .L081394D4
	ldr r0, .L081394D0
	bl sub_080C57CC
	cmp r0, #1
	bne .L081394FA
	movs r0, #4
	b .L08139500
	.byte 0x00, 0x00
.L081394D0: .4byte 0x00000157
.L081394D4:
	movs r0, #0xc7
	bl Flag_Test
	cmp r0, #1
	bne .L081394E2
	movs r0, #1
	b .L08139500
.L081394E2:
	movs r0, #0xbc
	bl Flag_Test
	cmp r0, #1
	bne .L081394F0
	movs r0, #2
	b .L08139500
.L081394F0:
	movs r0, #0xc8
	bl Flag_Test
	cmp r0, #1
	beq .L081394FE
.L081394FA:
	movs r0, #0
	b .L08139500
.L081394FE:
	movs r0, #3
.L08139500:
	pop {r1}
	bx r1

	thumb_func_start ScriptOpAlt_409
ScriptOpAlt_409: @ 0x08139504
	ldr r1, .L08139510
	ldrh r0, [r1]
	adds r0, #6
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08139510: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_40A
ScriptOp_40A: @ 0x08139514
	push {r4, lr}
	ldr r2, .L08139550
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08139554
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrb r4, [r0]
	lsrs r1, r1, #8
	cmp r1, #0
	bne .L0813959C
	cmp r4, #0
	bne .L08139564
	bl sub_080C700C
	ldr r1, .L08139558
	movs r0, #0x5a
	strh r0, [r1]
	ldr r1, .L0813955C
	movs r0, #0xf
	strh r0, [r1]
	ldr r1, .L08139560
	movs r0, #1
	strh r0, [r1]
	b .L08139580
	.byte 0x00, 0x00
.L08139550: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139554: .4byte 0x03006950 @ IWRAM+0x6950
.L08139558: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L0813955C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08139560: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08139564:
	cmp r4, #1
	bne .L08139580
	bl sub_080D3740
	ldr r1, .L0813958C
	str r0, [r1]
	ldr r1, .L08139590
	movs r0, #2
	strh r0, [r1]
	ldr r1, .L08139594
	movs r0, #0xf
	strh r0, [r1]
	ldr r0, .L08139598
	strh r4, [r0]
.L08139580:
	cmp r4, #6
	bne .L081395FA
	bl sub_080C7648
	b .L081395E8
	.byte 0x00, 0x00
.L0813958C: .4byte 0x03006954 @ IWRAM+0x6954
.L08139590: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L08139594: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08139598: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L0813959C:
	cmp r4, #0
	bne .L081395C4
	bl sub_080C6FF0
	ldr r1, .L081395B8
	movs r0, #0x5a
	strh r0, [r1]
	ldr r1, .L081395BC
	movs r0, #0xf
	strh r0, [r1]
	ldr r1, .L081395C0
	movs r0, #1
	strh r0, [r1]
	b .L081395E0
.L081395B8: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L081395BC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L081395C0: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L081395C4:
	cmp r4, #1
	bne .L081395E0
	ldr r0, .L08139600
	ldr r0, [r0]
	bl sub_080D3758
	ldr r1, .L08139604
	movs r0, #2
	strh r0, [r1]
	ldr r1, .L08139608
	movs r0, #0xf
	strh r0, [r1]
	ldr r0, .L0813960C
	strh r4, [r0]
.L081395E0:
	cmp r4, #6
	bne .L081395FA
	bl sub_080C762C
.L081395E8:
	ldr r1, .L08139604
	movs r0, #2
	strh r0, [r1]
	ldr r1, .L08139608
	movs r0, #0xf
	strh r0, [r1]
	ldr r1, .L0813960C
	movs r0, #1
	strh r0, [r1]
.L081395FA:
	pop {r4}
	pop {r0}
	bx r0
.L08139600: .4byte 0x03006954 @ IWRAM+0x6954
.L08139604: .4byte 0x0203DB5C @ EWRAM+0x3DB5C
.L08139608: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813960C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOpAlt_40A
ScriptOpAlt_40A: @ 0x08139610
	ldr r1, .L0813961C
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813961C: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_40C
ScriptOp_40C: @ 0x08139620
	ldr r2, .L08139644
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08139648
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	orrs r0, r1
	ldr r1, .L0813964C
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08139644: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139648: .4byte 0x03006950 @ IWRAM+0x6950
.L0813964C: .4byte 0x0203DB50 @ EWRAM+0x3DB50

	thumb_func_start ScriptOp_40B
ScriptOp_40B: @ 0x08139650
	push {r4, r5, r6, lr}
	ldr r3, .L081396A4
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L081396A8
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
	lsls r6, r0, #0x10
	orrs r6, r5
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
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	orrs r1, r2
	ldr r3, .L081396AC
	ldrh r0, [r3]
	ldr r2, .L081396B0
	cmp r0, r2
	bne .L081396B8
	ldr r0, .L081396B4
	str r6, [r0]
	b .L081396CE
	.byte 0x00, 0x00
.L081396A4: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L081396A8: .4byte 0x03006950 @ IWRAM+0x6950
.L081396AC: .4byte 0x03006990 @ IWRAM+0x6990
.L081396B0: .4byte 0x0000FFFF
.L081396B4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L081396B8:
	ldrh r0, [r3, #2]
	cmp r0, r2
	bne .L081396CE
	ldr r2, .L081396D4
	str r1, [r2, #0x3c]
	ldr r1, .L081396D8
	movs r0, #1
	strh r0, [r1]
	ldr r1, .L081396DC
	ldr r0, [r2, #0x28]
	str r0, [r1]
.L081396CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L081396D4: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L081396D8: .4byte 0x030069CC @ IWRAM+0x69CC
.L081396DC: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOpAlt_40B
ScriptOpAlt_40B: @ 0x081396E0
	ldr r1, .L081396EC
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L081396EC: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_40D
ScriptOp_40D: @ 0x081396F0
	push {r4, r5, lr}
	ldr r2, .L08139750
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08139754
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r4, [r0]
	lsrs r5, r4, #8
	movs r0, #0xff
	ands r4, r0
	cmp r4, #1
	bne .L08139726
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	bne .L08139726
	movs r0, #1
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0813974A
	movs r4, #2
.L08139726:
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl Combatant_AddBaseStat
	adds r0, r4, #0
	bl Combatant_RecalcStats
	cmp r4, #1
	bne .L08139746
	movs r0, #1
	bl Combatant_RestoreHp
	movs r0, #1
	bl Combatant_RestoreMp
.L08139746:
	bl sub_080CDC34
.L0813974A:
	pop {r4, r5}
	pop {r0}
	bx r0
.L08139750: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139754: .4byte 0x03006950 @ IWRAM+0x6950

	thumb_func_start ScriptOpAlt_40D
ScriptOpAlt_40D: @ 0x08139758
	ldr r1, .L08139764
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08139764: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_40E
ScriptOp_40E: @ 0x08139768
	push {lr}
	ldr r2, .L08139790
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08139794
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #2
	bne .L08139798
	adds r0, #0xfc
	bl Flag_Set
	b .L081397A4
	.byte 0x00, 0x00
.L08139790: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139794: .4byte 0x03006950 @ IWRAM+0x6950
.L08139798:
	cmp r1, #4
	bne .L081397A4
	movs r0, #0x86
	lsls r0, r0, #1
	bl Flag_Set
.L081397A4:
	pop {r0}
	bx r0

	thumb_func_start ScriptOpAlt_40E
ScriptOpAlt_40E: @ 0x081397A8
	ldr r1, .L081397B4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L081397B4: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start sub_081397B8
sub_081397B8: @ 0x081397B8
	ldr r1, .L081397C4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L081397C4: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOpAlt_40F
ScriptOpAlt_40F: @ 0x081397C8
	ldr r1, .L081397D4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L081397D4: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start sub_081397D8
sub_081397D8: @ 0x081397D8
.L081397D8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	bl Random_Byte
	movs r1, #0x1f
	ands r0, r1
	ldr r1, .L08139800
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r0, .L08139804
	ldrh r0, [r0, #6]
	cmp r0, r2
	bne .L0813980E
	cmp r2, #9
	bne .L08139808
	movs r2, #0
	b .L0813980E
	.byte 0x00, 0x00
.L08139800: .4byte gUnknown_08790AE6
.L08139804: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08139808:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L0813980E:
	ldr r0, .L081398A4
	strh r2, [r0, #6]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	ldrh r1, [r0, #2]
	ldrh r0, [r0, #4]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x11
	movs r3, #0
	cmp r1, #0
	beq .L08139832
	movs r3, #0x64
	cmp r1, #1
	bne .L08139832
	movs r3, #0x32
.L08139832:
	adds r0, r3, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r4, .L081398A8
	movs r0, #0x96
	adds r2, r5, #0
	muls r2, r0, r2
	adds r0, r3, r2
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r6, r0, #0
	adds r0, r2, #1
	adds r0, r3, r0
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r1, .L081398AC
	mov r8, r1
	strh r0, [r1]
	adds r0, r2, #2
	adds r0, r3, r0
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r1, .L081398B0
	ldr r5, .L081398B4
	mov ip, r5
	strh r0, [r5]
	ldr r7, .L081398B8
	adds r5, r7, #0
	str r0, [r1]
	ldr r0, .L081398BC
	movs r7, #1
	strh r7, [r0]
	cmp r6, #2
	bne .L08139898
	adds r0, r2, #3
	adds r0, r3, r0
	adds r0, r0, r4
	ldrb r0, [r0]
	mov r1, r8
	strh r0, [r1, #2]
	adds r0, r2, #4
	adds r0, r3, r0
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r1, .L081398C0
	mov r2, ip
	strh r0, [r2, #2]
	ands r0, r5
	str r0, [r1]
	ldr r0, .L081398C4
	strh r7, [r0]
.L08139898:
	adds r0, r6, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L081398A4: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L081398A8: .4byte gUnknown_0879050A
.L081398AC: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L081398B0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L081398B4: .4byte 0x03006970 @ IWRAM+0x6970
.L081398B8: .4byte 0x0000FFFF
.L081398BC: .4byte 0x0203DB66 @ EWRAM+0x3DB66
.L081398C0: .4byte 0x0203DB30 @ EWRAM+0x3DB30
.L081398C4: .4byte 0x0203DB68 @ EWRAM+0x3DB68

	thumb_func_start sub_081398C8
sub_081398C8: @ 0x081398C8
.L081398C8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	bl Random_Byte
	movs r1, #0x1f
	ands r0, r1
	ldr r1, .L08139974
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L08139978
	ldrh r2, [r0, #2]
	ldrh r0, [r0, #4]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r3, #0
	cmp r2, #0
	beq .L08139900
	movs r3, #0x64
	cmp r2, #1
	bne .L08139900
	movs r3, #0x32
.L08139900:
	adds r0, r3, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r4, .L0813997C
	movs r0, #0x96
	adds r2, r5, #0
	muls r2, r0, r2
	adds r0, r3, r2
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r6, r0, #0
	adds r0, r2, #1
	adds r0, r3, r0
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r1, .L08139980
	mov r8, r1
	strh r0, [r1]
	adds r0, r2, #2
	adds r0, r3, r0
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r1, .L08139984
	ldr r5, .L08139988
	mov ip, r5
	strh r0, [r5]
	ldr r7, .L0813998C
	adds r5, r7, #0
	str r0, [r1]
	ldr r0, .L08139990
	movs r7, #1
	strh r7, [r0]
	cmp r6, #2
	bne .L08139966
	adds r0, r2, #3
	adds r0, r3, r0
	adds r0, r0, r4
	ldrb r0, [r0]
	mov r1, r8
	strh r0, [r1, #2]
	adds r0, r2, #4
	adds r0, r3, r0
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r1, .L08139994
	mov r2, ip
	strh r0, [r2, #2]
	ands r0, r5
	str r0, [r1]
	ldr r0, .L08139998
	strh r7, [r0]
.L08139966:
	adds r0, r6, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08139974: .4byte gUnknown_08790AE6
.L08139978: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L0813997C: .4byte gUnknown_087907F8
.L08139980: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L08139984: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L08139988: .4byte 0x03006970 @ IWRAM+0x6970
.L0813998C: .4byte 0x0000FFFF
.L08139990: .4byte 0x0203DB66 @ EWRAM+0x3DB66
.L08139994: .4byte 0x0203DB30 @ EWRAM+0x3DB30
.L08139998: .4byte 0x0203DB68 @ EWRAM+0x3DB68

	thumb_func_start sub_0813999C
sub_0813999C: @ 0x0813999C
.L0813999C:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L081399D8
	ldrh r3, [r1, #2]
	cmp r0, #3
	bne .L081399D2
	ldrh r0, [r1, #4]
	ldr r1, .L081399DC
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r0, .L081399E0
	strh r1, [r0]
	movs r2, #8
	cmp r3, #0
	beq .L081399C4
	movs r2, #2
	cmp r3, #1
	bne .L081399C4
	movs r2, #4
.L081399C4:
	ldr r1, .L081399E4
	ldr r0, .L081399E8
	strh r2, [r0]
	str r2, [r1]
	ldr r1, .L081399EC
	movs r0, #1
	strh r0, [r1]
.L081399D2:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081399D8: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L081399DC: .4byte gUnknown_08790B26
.L081399E0: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L081399E4: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L081399E8: .4byte 0x03006970 @ IWRAM+0x6970
.L081399EC: .4byte 0x0203DB66 @ EWRAM+0x3DB66

	thumb_func_start ScriptOp_410
ScriptOp_410: @ 0x081399F0
	push {r4, r5, r6, r7, lr}
	ldr r3, .L08139A58
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08139A5C
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
	ldrh r6, [r0]
	lsls r6, r6, #0x10
	orrs r6, r4
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
	bne .L08139A6C
	ldr r1, .L08139A60
	ldr r0, .L08139A64
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #4
	bhi .L08139A54
	b .L08139DA8
.L08139A54:
	ldr r0, .L08139A68
	b .L08139DCA
.L08139A58: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139A5C: .4byte 0x03006950 @ IWRAM+0x6950
.L08139A60: .4byte gUnknown_08790C1C
.L08139A64: .4byte 0x03006914 @ IWRAM+0x6914
.L08139A68: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08139A6C:
	cmp r5, #2
	bne .L08139A8C
	ldr r1, .L08139A84
	ldr r0, .L08139A88
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #2
	beq .L08139A82
	b .L08139DCC
.L08139A82:
	b .L08139DA8
.L08139A84: .4byte gUnknown_08790C1C
.L08139A88: .4byte 0x03006914 @ IWRAM+0x6914
.L08139A8C:
	cmp r5, #3
	bne .L08139AAC
	ldr r1, .L08139AA4
	ldr r0, .L08139AA8
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #3
	beq .L08139AA2
	b .L08139DCC
.L08139AA2:
	b .L08139DA8
.L08139AA4: .4byte gUnknown_08790C1C
.L08139AA8: .4byte 0x03006914 @ IWRAM+0x6914
.L08139AAC:
	cmp r5, #4
	bne .L08139ACC
	ldr r1, .L08139AC4
	ldr r0, .L08139AC8
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #4
	beq .L08139AC2
	b .L08139DCC
.L08139AC2:
	b .L08139DA8
.L08139AC4: .4byte gUnknown_08790C1C
.L08139AC8: .4byte 0x03006914 @ IWRAM+0x6914
.L08139ACC:
	cmp r5, #5
	bne .L08139AEC
	ldr r1, .L08139AE4
	ldr r0, .L08139AE8
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #5
	beq .L08139AE2
	b .L08139DCC
.L08139AE2:
	b .L08139DA8
.L08139AE4: .4byte gUnknown_08790C1C
.L08139AE8: .4byte 0x03006914 @ IWRAM+0x6914
.L08139AEC:
	cmp r5, #6
	bne .L08139B0C
	ldr r1, .L08139B04
	ldr r0, .L08139B08
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #6
	beq .L08139B02
	b .L08139DCC
.L08139B02:
	b .L08139DA8
.L08139B04: .4byte gUnknown_08790C1C
.L08139B08: .4byte 0x03006914 @ IWRAM+0x6914
.L08139B0C:
	cmp r5, #7
	bne .L08139B2C
	ldr r1, .L08139B24
	ldr r0, .L08139B28
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #7
	beq .L08139B22
	b .L08139DCC
.L08139B22:
	b .L08139DA8
.L08139B24: .4byte gUnknown_08790C1C
.L08139B28: .4byte 0x03006914 @ IWRAM+0x6914
.L08139B2C:
	cmp r5, #8
	bne .L08139B62
	movs r0, #0
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L08139B40
	b .L08139DA8
.L08139B40:
	movs r0, #1
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L08139B50
	b .L08139DA8
.L08139B50:
	movs r0, #2
	bl sub_080C2A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L08139B60
	b .L08139DCC
.L08139B60:
	b .L08139DA8
.L08139B62:
	cmp r5, #9
	bne .L08139B80
	bl sub_080D3A80
	ldr r0, .L08139B78
	str r6, [r0]
	ldr r1, .L08139B7C
	movs r0, #0x50
	strh r0, [r1]
	b .L08139D84
	.byte 0x00, 0x00
.L08139B78: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08139B7C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08139B80:
	cmp r5, #0xa
	bne .L08139BA0
	ldr r0, .L08139B98
	str r6, [r0]
	movs r0, #2
	bl sub_080D3AA0
	ldr r1, .L08139B9C
	movs r0, #0x50
	strh r0, [r1]
	b .L08139D84
	.byte 0x00, 0x00
.L08139B98: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08139B9C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08139BA0:
	cmp r5, #0xb
	bne .L08139BC0
	ldr r0, .L08139BB8
	str r6, [r0]
	str r7, [r0, #4]
	bl sub_080D3CAC
	ldr r1, .L08139BBC
	movs r0, #0x51
	strh r0, [r1]
	b .L08139D84
	.byte 0x00, 0x00
.L08139BB8: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08139BBC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08139BC0:
	cmp r5, #0xc
	bne .L08139BE8
	movs r4, #0x96
	lsls r4, r4, #1
	ldr r5, .L08139BE4
.L08139BCA:
	adds r0, r4, #0
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08139BD8
	b .L08139DCC
.L08139BD8:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	bls .L08139BCA
	b .L08139DA8
.L08139BE4: .4byte 0x00000159
.L08139BE8:
	cmp r5, #0xd
	bne .L08139C00
	bl sub_080C3100
	ldr r1, .L08139BFC
	ldr r1, [r1]
	cmp r0, r1
	blo .L08139BFA
	b .L08139DCC
.L08139BFA:
	b .L08139DA8
.L08139BFC: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L08139C00:
	cmp r5, #0xe
	bne .L08139C28
	movs r0, #0
	bl Combatant_GetLevel
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	bgt .L08139C14
	b .L08139DCC
.L08139C14:
	ldr r0, .L08139C24
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08139C22
	b .L08139DCC
.L08139C22:
	b .L08139DA8
.L08139C24: .4byte 0x0000011F
.L08139C28:
	cmp r5, #0xf
	bne .L08139C48
	ldr r0, .L08139C40
	str r6, [r0]
	str r7, [r0, #4]
	bl sub_080D3DF0
	ldr r1, .L08139C44
	movs r0, #0x51
	strh r0, [r1]
	b .L08139D84
	.byte 0x00, 0x00
.L08139C40: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08139C44: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08139C48:
	cmp r5, #0x10
	bne .L08139C84
	ldr r0, .L08139C5C
	ldrh r0, [r0]
	cmp r0, #2
	bne .L08139C60
	movs r0, #3
	bl sub_0813999C
	b .L08139DCC
.L08139C5C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08139C60:
	cmp r0, #1
	bne .L08139C74
	bl sub_081398C8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L08139C72
	b .L08139DCC
.L08139C72:
	b .L08139DA8
.L08139C74:
	bl sub_081397D8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	beq .L08139C82
	b .L08139DCC
.L08139C82:
	b .L08139DA8
.L08139C84:
	cmp r5, #0x11
	bne .L08139CB4
	ldr r0, .L08139C9C
	ldrh r4, [r0, #4]
	ldrh r0, [r0]
	cmp r0, #2
	bne .L08139CA0
	cmp r4, #0xf3
	beq .L08139C98
	b .L08139DCC
.L08139C98:
	b .L08139DA8
	.byte 0x00, 0x00
.L08139C9C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08139CA0:
	cmp r0, #0
	bne .L08139CAC
	cmp r4, #0xa
	beq .L08139CAA
	b .L08139DCC
.L08139CAA:
	b .L08139DA8
.L08139CAC:
	cmp r4, #5
	beq .L08139CB2
	b .L08139DCC
.L08139CB2:
	b .L08139DA8
.L08139CB4:
	cmp r5, #0x12
	bne .L08139CD4
	ldr r0, .L08139CCC
	ldrh r4, [r0]
	cmp r4, #0
	beq .L08139DA8
	cmp r4, #1
	beq .L08139CC6
	b .L08139DCC
.L08139CC6:
	ldr r0, .L08139CD0
	b .L08139DCA
	.byte 0x00, 0x00
.L08139CCC: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08139CD0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08139CD4:
	cmp r5, #0x13
	bne .L08139CF0
	ldr r0, .L08139CE8
	ldrh r4, [r0, #2]
	cmp r4, #0
	beq .L08139DA8
	cmp r4, #1
	bne .L08139DCC
	ldr r0, .L08139CEC
	b .L08139DCA
.L08139CE8: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08139CEC: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08139CF0:
	cmp r5, #0x14
	bne .L08139D14
	ldr r0, .L08139D0C
	ldrh r4, [r0, #4]
	adds r0, r4, #0
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08139DCC
	ldr r0, .L08139D10
	b .L08139DCA
	.byte 0x00, 0x00
.L08139D0C: .4byte 0x0203BB74 @ EWRAM+0x3BB74
.L08139D10: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08139D14:
	cmp r5, #0x15
	bne .L08139D6C
	ldr r0, .L08139D64
	bl sub_080C32D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08139DCC
	movs r0, #0
	bl Combatant_IsAlive
	cmp r0, #1
	bne .L08139DCC
	movs r0, #0
	bl Combatant_GetLevel
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	ble .L08139DCC
	movs r4, #0
.L08139D3E:
	adds r0, r4, #4
	bl Combatant_IsUsed
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0xb
	bls .L08139D3E
	movs r0, #0xd4
	bl Flag_Test
	cmp r0, #1
	beq .L08139DCC
	movs r0, #0xd4
	bl Flag_Set
	ldr r0, .L08139D68
	b .L08139DCA
	.byte 0x00, 0x00
.L08139D64: .4byte 0x0000011F
.L08139D68: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08139D6C:
	cmp r5, #0x16
	bne .L08139D9C
	ldr r0, .L08139D8C
	str r6, [r0]
	ldr r1, .L08139D90
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #1
	bl YesNo_Create
	ldr r1, .L08139D94
	str r0, [r1]
.L08139D84:
	ldr r1, .L08139D98
	movs r0, #1
	strh r0, [r1]
	b .L08139DCC
.L08139D8C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L08139D90: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L08139D94: .4byte 0x030068E0 @ IWRAM+0x68E0
.L08139D98: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08139D9C:
	cmp r5, #0x17
	bne .L08139DC4
	bl sub_080C5C50
	cmp r0, #0
	bne .L08139DB4
.L08139DA8:
	ldr r0, .L08139DB0
	str r6, [r0]
	b .L08139DCC
	.byte 0x00, 0x00
.L08139DB0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08139DB4:
	bl sub_080C5C7C
	cmp r0, #2
	bls .L08139DCC
	ldr r0, .L08139DC0
	b .L08139DCA
.L08139DC0: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08139DC4:
	ldr r0, .L08139DD4
	str r6, [r0]
	ldr r0, .L08139DD8
.L08139DCA:
	str r7, [r0]
.L08139DCC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08139DD4: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08139DD8: .4byte 0x03006840 @ IWRAM+0x6840

	thumb_func_start ScriptOpAlt_410
ScriptOpAlt_410: @ 0x08139DDC
	ldr r1, .L08139DE8
	ldrh r0, [r1]
	adds r0, #5
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08139DE8: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_411
ScriptOp_411: @ 0x08139DEC
	ldr r1, .L08139E00
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, .L08139E04
	ldr r0, .L08139E08
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08139E00: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139E04: .4byte 0x030068E4 @ IWRAM+0x68E4
.L08139E08: .4byte 0x03006840 @ IWRAM+0x6840

	thumb_func_start ScriptOpAlt_411
ScriptOpAlt_411: @ 0x08139E0C
	ldr r1, .L08139E18
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08139E18: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_421
ScriptOp_421: @ 0x08139E1C
	push {lr}
	ldr r2, .L08139E40
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08139E44
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r1, #0
	cmp r1, #3
	bne .L08139E4C
	ldr r1, .L08139E48
	movs r0, #2
	b .L08139E60
	.byte 0x00, 0x00
.L08139E40: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139E44: .4byte 0x03006950 @ IWRAM+0x6950
.L08139E48: .4byte 0x0203DB82 @ EWRAM+0x3DB82
.L08139E4C:
	cmp r1, #2
	bhi .L08139E5C
	ldr r1, .L08139E58
	movs r0, #1
	b .L08139E60
	.byte 0x00, 0x00
.L08139E58: .4byte 0x0203DB82 @ EWRAM+0x3DB82
.L08139E5C:
	ldr r1, .L08139E68
	subs r0, #2
.L08139E60:
	strh r0, [r1]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08139E68: .4byte 0x0203DB82 @ EWRAM+0x3DB82

	thumb_func_start ScriptOpAlt_421
ScriptOpAlt_421: @ 0x08139E6C
	ldr r1, .L08139E78
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08139E78: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_422
ScriptOp_422: @ 0x08139E7C
	push {r4, r5, r6, lr}
	ldr r2, .L08139ED8
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08139EDC
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r5, [r0]
	movs r0, #0xff
	adds r4, r5, #0
	ands r4, r0
	adds r6, r4, #0
	lsrs r2, r5, #8
	ands r2, r0
	adds r5, r2, #0
	ldr r1, .L08139EE0
	movs r0, #1
	strh r0, [r1]
	cmp r2, #0x10
	bne .L08139EE4
	movs r0, #0
	bl Combatant_IsAlive
	cmp r0, #1
	bne .L08139F1A
	movs r0, #0
	bl sub_08134DE0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	muls r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r1, r0, #0
	movs r0, #0
	bl Combatant_ChangeHp
	b .L08139F1A
.L08139ED8: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139EDC: .4byte 0x03006950 @ IWRAM+0x6950
.L08139EE0: .4byte 0x0203DB6E @ EWRAM+0x3DB6E
.L08139EE4:
	cmp r2, #0xff
	bne .L08139EEE
	bl sub_080C366C
	b .L08139F1A
.L08139EEE:
	adds r0, r5, #0
	bl Combatant_IsAlive
	cmp r0, #1
	bne .L08139F1A
	adds r0, r5, #0
	bl sub_08134DE0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	muls r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r1, r0, #0
	adds r0, r5, #0
	bl Combatant_ChangeHp
.L08139F1A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ScriptOpAlt_422
ScriptOpAlt_422: @ 0x08139F20
	ldr r1, .L08139F2C
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08139F2C: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_423
ScriptOp_423: @ 0x08139F30
	push {r4, r5, r6, lr}
	ldr r3, .L08139F94
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L08139F98
	ldr r2, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r2
	ldrh r6, [r0]
	lsls r0, r6, #0x14
	lsrs r6, r0, #0x10
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
	ldrh r5, [r0]
	lsls r5, r5, #0x10
	orrs r5, r4
	bl Moon_GetPhase
	adds r1, r0, #0
	movs r0, #0xf0
	ands r1, r0
	cmp r1, #0x8f
	bls .L08139F84
	adds r0, r1, #0
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x80
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
.L08139F84:
	cmp r1, r6
	beq .L08139F8C
	ldr r0, .L08139F9C
	str r5, [r0]
.L08139F8C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08139F94: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139F98: .4byte 0x03006950 @ IWRAM+0x6950
.L08139F9C: .4byte 0x030068E4 @ IWRAM+0x68E4

	thumb_func_start ScriptOpAlt_423
ScriptOpAlt_423: @ 0x08139FA0
	ldr r1, .L08139FAC
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L08139FAC: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_424
ScriptOp_424: @ 0x08139FB0
	push {r4, lr}
	ldr r2, .L08139FF0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L08139FF4
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xff
	adds r2, r1, #0
	ands r2, r0
	lsrs r1, r1, #8
	ands r1, r0
	ldr r4, .L08139FF8
	ldr r3, .L08139FFC
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, .L0813A000
	adds r0, r4, r1
	strb r2, [r0]
	bl Moon_GetPhase
	ldr r3, .L0813A004
	adds r4, r4, r3
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08139FF0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L08139FF4: .4byte 0x03006950 @ IWRAM+0x6950
.L08139FF8: .4byte 0x030046C0 @ IWRAM+0x46C0
.L08139FFC: .4byte 0x000018B5
.L0813A000: .4byte 0x000018B6
.L0813A004: .4byte 0x000018B4

	thumb_func_start ScriptOpAlt_424
ScriptOpAlt_424: @ 0x0813A008
	ldr r1, .L0813A014
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A014: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_425
ScriptOp_425: @ 0x0813A018
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_425
ScriptOpAlt_425: @ 0x0813A01C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_426
ScriptOp_426: @ 0x0813A020
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	movs r1, #0
	ldr r3, .L0813A064
	movs r2, #0
.L0813A02E:
	lsls r0, r1, #2
	adds r0, r0, r3
	str r2, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xf
	bls .L0813A02E
	ldr r0, .L0813A068
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L0813A04E
	b .L0813A1C2
.L0813A04E:
	adds r0, r1, #0
	movs r1, #0x82
	lsls r1, r1, #1
	cmp r0, r1
	bne .L0813A06C
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x15
	b .L0813A082
	.byte 0x00, 0x00
.L0813A064: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813A068: .4byte 0x03006914 @ IWRAM+0x6914
.L0813A06C:
	cmp r0, r1
	bls .L0813A07A
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0xef
	b .L0813A082
.L0813A07A:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0xa
.L0813A082:
	movs r2, #0x50
	movs r3, #3
	bl sub_080C4618
	ldr r1, .L0813A134
	str r0, [r1]
	ldr r1, .L0813A138
	ldr r0, .L0813A13C
	strh r0, [r1, #8]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1, #6]
	strh r0, [r1, #4]
	strh r0, [r1, #2]
	strh r0, [r1]
	ldr r7, .L0813A140
	ldr r0, .L0813A144
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrh r2, [r0]
	ldrh r1, [r0, #2]
	lsls r7, r1, #0x10
	orrs r7, r2
	movs r6, #0
.L0813A0B4:
	lsls r0, r6, #2
	adds r0, r0, r7
	ldrh r2, [r0]
	ldrh r1, [r0, #2]
	lsls r5, r1, #0x10
	orrs r5, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	bl Flag_Test
	cmp r0, #1
	beq .L0813A0D0
	cmp r4, #0xff
	bne .L0813A14C
.L0813A0D0:
	movs r6, #1
	movs r4, #0
	ldrh r0, [r5, #2]
	ldr r1, .L0813A138
	mov r8, r1
	cmp r0, #0xff
	beq .L0813A154
	mov ip, r8
	ldr r7, .L0813A148
.L0813A0E2:
	lsls r3, r4, #1
	add r3, ip
	adds r1, r6, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r2, r6, #0
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	strh r0, [r3]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r1, r6, #0
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r2, [r2]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	orrs r1, r2
	adds r0, r4, #0
	adds r0, #0xa
	lsls r0, r0, #2
	adds r0, r0, r7
	str r1, [r0]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r0, r6, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0xff
	bne .L0813A0E2
	b .L0813A154
	.byte 0x00, 0x00
.L0813A134: .4byte 0x030068F0 @ IWRAM+0x68F0
.L0813A138: .4byte 0x03006990 @ IWRAM+0x6990
.L0813A13C: .4byte 0x0000FFFF
.L0813A140: .4byte gUnknown_08035BB8
.L0813A144: .4byte 0x03006914 @ IWRAM+0x6914
.L0813A148: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8
.L0813A14C:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	b .L0813A0B4
.L0813A154:
	movs r3, #0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0xff
	beq .L0813A17A
	mov r2, r8
	movs r4, #0xff
.L0813A162:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #3
	bhi .L0813A17A
	lsls r0, r3, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0xff
	bne .L0813A162
.L0813A17A:
	movs r2, #0
	ldr r0, .L0813A1D0
	mov r8, r0
	movs r5, #0
	subs r0, r3, #1
	lsls r7, r0, #2
.L0813A186:
	ldr r1, .L0813A1D4
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrb r6, [r0]
	adds r4, r2, #1
	cmp r6, #0xff
	beq .L0813A1BA
	ldr r1, .L0813A1D8
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, r2
	add r0, r8
	ldrb r2, [r0]
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	str r5, [sp]
	str r5, [sp, #4]
	movs r3, #0
	bl sub_080C4618
	ldr r2, .L0813A1DC
	lsls r1, r4, #2
	adds r1, r1, r2
	str r0, [r1]
.L0813A1BA:
	lsls r0, r4, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #3
	bls .L0813A186
.L0813A1C2:
	ldr r0, .L0813A1E0
	ldrh r1, [r0]
	ldr r0, .L0813A1E4
	cmp r1, r0
	bhi .L0813A1E8
	movs r6, #8
	b .L0813A1F4
.L0813A1D0: .4byte gUnknown_08790C8A
.L0813A1D4: .4byte 0x03006990 @ IWRAM+0x6990
.L0813A1D8: .4byte gUnknown_08790C9A
.L0813A1DC: .4byte 0x030068F0 @ IWRAM+0x68F0
.L0813A1E0: .4byte 0x03006914 @ IWRAM+0x6914
.L0813A1E4: .4byte 0x00000103
.L0813A1E8:
	movs r0, #0x82
	lsls r0, r0, #1
	movs r6, #0x57
	cmp r1, r0
	bne .L0813A1F4
	movs r6, #0x12
.L0813A1F4:
	adds r0, r6, #0
	bl BgPicture_StartTask
	ldr r1, .L0813A218
	str r0, [r1]
	ldr r1, .L0813A21C
	movs r0, #2
	strh r0, [r1]
	ldr r1, .L0813A220
	movs r0, #1
	strh r0, [r1]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813A218: .4byte 0x030068B0 @ IWRAM+0x68B0
.L0813A21C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813A220: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start sub_0813A224
sub_0813A224: @ 0x0813A224
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_427
ScriptOp_427: @ 0x0813A228
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_427
ScriptOpAlt_427: @ 0x0813A22C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_428
ScriptOp_428: @ 0x0813A230
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_428
ScriptOpAlt_428: @ 0x0813A234
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_429
ScriptOp_429: @ 0x0813A238
	push {r4, lr}
	sub sp, #4
	ldr r3, .L0813A284
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813A288
	ldr r4, [r2]
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r2, [r0]
	adds r0, r1, #1
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r1, r1, r4
	ldrh r3, [r1]
	lsrs r1, r2, #8
	movs r0, #0xff
	ands r2, r0
	ldr r4, .L0813A28C
	movs r0, #0x14
	strh r0, [r4]
	movs r4, #1
	str r4, [sp]
	movs r0, #0
	bl Warp_ToWorldPosition
	ldr r1, .L0813A290
	str r0, [r1]
	ldr r0, .L0813A294
	strh r4, [r0]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813A284: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813A288: .4byte 0x03006950 @ IWRAM+0x6950
.L0813A28C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A
.L0813A290: .4byte 0x03006954 @ IWRAM+0x6954
.L0813A294: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start sub_0813A298
sub_0813A298: @ 0x0813A298
	ldr r1, .L0813A2A4
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A2A4: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_42A
ScriptOp_42A: @ 0x0813A2A8
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_42A
ScriptOpAlt_42A: @ 0x0813A2AC
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_42B
ScriptOp_42B: @ 0x0813A2B0
	ldr r1, .L0813A2C0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, .L0813A2C4
	movs r0, #1
	strh r0, [r1]
	bx lr
.L0813A2C0: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813A2C4: .4byte 0x0203DB6E @ EWRAM+0x3DB6E

	thumb_func_start ScriptOpAlt_42B
ScriptOpAlt_42B: @ 0x0813A2C8
	ldr r1, .L0813A2D4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A2D4: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_42C
ScriptOp_42C: @ 0x0813A2D8
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_42C
ScriptOpAlt_42C: @ 0x0813A2DC
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_42D
ScriptOp_42D: @ 0x0813A2E0
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_42D
ScriptOpAlt_42D: @ 0x0813A2E4
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_42E
ScriptOp_42E: @ 0x0813A2E8
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_42E
ScriptOpAlt_42E: @ 0x0813A2EC
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_42F
ScriptOp_42F: @ 0x0813A2F0
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_42F
ScriptOpAlt_42F: @ 0x0813A2F4
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_430
ScriptOp_430: @ 0x0813A2F8
	push {lr}
	bl sub_080C5DE0
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_430
ScriptOpAlt_430: @ 0x0813A304
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_431
ScriptOp_431: @ 0x0813A308
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_431
ScriptOpAlt_431: @ 0x0813A30C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_432
ScriptOp_432: @ 0x0813A310
	push {r4, lr}
	ldr r1, .L0813A380
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0x31
	strb r1, [r0]
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0x7c
	strb r1, [r0, #1]
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0x65
	strb r1, [r0, #2]
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #0xff
	strb r1, [r0, #3]
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #1
	rsbs r1, r1, #0
	strb r1, [r0, #4]
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #1
	rsbs r1, r1, #0
	strb r1, [r0, #5]
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #1
	rsbs r1, r1, #0
	strb r1, [r0, #6]
	adds r0, r4, #0
	bl Battle_GetCombatant
	movs r1, #1
	rsbs r1, r1, #0
	strb r1, [r0, #7]
	bl sub_080C366C
	pop {r4}
	pop {r0}
	bx r0
.L0813A380: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOpAlt_432
ScriptOpAlt_432: @ 0x0813A384
	ldr r1, .L0813A390
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A390: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_433
ScriptOp_433: @ 0x0813A394
	push {lr}
	bl sub_080C5DB0
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_433
ScriptOpAlt_433: @ 0x0813A3A0
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0813A3A4
sub_0813A3A4: @ 0x0813A3A4
.L0813A3A4:
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0813A3BC
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0813A3B6
	adds r0, r1, #0
	bl sub_080C30AC
.L0813A3B6:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0813A3BC: .4byte 0x030065F0 @ IWRAM+0x65F0

	thumb_func_start ScriptOp_434
ScriptOp_434: @ 0x0813A3C0
	push {r4, r5, lr}
	ldr r3, .L0813A408
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x10
	ldr r2, .L0813A40C
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
	ldr r2, .L0813A410
	ldr r1, .L0813A414
	ldr r0, .L0813A418
	ldrh r0, [r0]
	subs r0, #0x61
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	str r4, [r2]
	bl sub_080C3100
	cmp r0, r4
	bhs .L0813A420
	ldr r0, .L0813A41C
	str r5, [r0]
	b .L0813A426
	.byte 0x00, 0x00
.L0813A408: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813A40C: .4byte 0x03006950 @ IWRAM+0x6950
.L0813A410: .4byte 0x0203DB2C @ EWRAM+0x3DB2C
.L0813A414: .4byte gUnknown_08790CC8
.L0813A418: .4byte 0x030065E0 @ IWRAM+0x65E0
.L0813A41C: .4byte 0x030068E4 @ IWRAM+0x68E4
.L0813A420:
	rsbs r0, r4, #0
	bl sub_0813A3A4
.L0813A426:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start ScriptOp_435
ScriptOp_435: @ 0x0813A42C
	push {r4, r5, lr}
	movs r4, #0
	ldr r2, .L0813A460
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	ldr r1, .L0813A464
	ldr r1, [r1]
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, #0
	cmp r0, #1
	bne .L0813A474
	ldr r2, .L0813A468
	ldr r1, .L0813A46C
	ldrh r0, [r2]
	ldr r3, .L0813A470
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	b .L0813A562
	.byte 0x00, 0x00
.L0813A460: .4byte 0x0203DB40 @ EWRAM+0x3DB40
.L0813A464: .4byte 0x03006950 @ IWRAM+0x6950
.L0813A468: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813A46C: .4byte gUnknown_0878FDB4
.L0813A470: .4byte 0xFFFFFEE0
.L0813A474:
	cmp r0, #2
	bne .L0813A4C8
	ldr r1, .L0813A4B4
	ldr r0, .L0813A4B8
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r1, .L0813A4BC
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #0
	ldr r3, .L0813A4C0
	adds r4, r3, #0
	ldr r5, .L0813A4C4
	ldrh r0, [r3]
	cmp r2, r0
	blo .L0813A4A8
.L0813A498:
	adds r0, r1, #2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r2, r0
	bhs .L0813A498
.L0813A4A8:
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r5]
	b .L0813A562
.L0813A4B4: .4byte 0x030068D8 @ IWRAM+0x68D8
.L0813A4B8: .4byte 0x0203DB50 @ EWRAM+0x3DB50
.L0813A4BC: .4byte 0xFFFFFDC0
.L0813A4C0: .4byte gUnknown_0878FDCC
.L0813A4C4: .4byte 0x0203DB28 @ EWRAM+0x3DB28
.L0813A4C8:
	cmp r0, #3
	bne .L0813A4D8
	ldr r1, .L0813A4D4
	movs r0, #0x64
	strh r0, [r1]
	b .L0813A562
.L0813A4D4: .4byte 0x0203DB84 @ EWRAM+0x3DB84
.L0813A4D8:
	cmp r0, #4
	bne .L0813A4E8
	ldr r1, .L0813A4E4
	movs r0, #0xa
	strh r0, [r1]
	b .L0813A562
.L0813A4E4: .4byte 0x0203DB84 @ EWRAM+0x3DB84
.L0813A4E8:
	cmp r0, #5
	bne .L0813A4FC
	ldr r0, .L0813A4F8
	ldr r0, [r0]
	bl sub_080C31B4
	b .L0813A562
	.byte 0x00, 0x00
.L0813A4F8: .4byte 0x030037F0 @ IWRAM+0x37F0
.L0813A4FC:
	cmp r0, #6
	bne .L0813A506
	bl sub_080D53FC
	b .L0813A562
.L0813A506:
	cmp r0, #7
	bne .L0813A54C
	ldr r0, .L0813A534
	strh r4, [r0]
	ldr r0, .L0813A538
	strh r4, [r0]
	ldr r0, .L0813A53C
	strh r4, [r0]
	ldr r0, .L0813A540
	strh r4, [r0]
	ldr r5, .L0813A544
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq .L0813A562
	ldr r0, .L0813A548
	ldr r0, [r0]
	movs r1, #1
	bl Window_Close
	strh r4, [r5]
	b .L0813A562
	.byte 0x00, 0x00
.L0813A534: .4byte 0x0203DB3E @ EWRAM+0x3DB3E
.L0813A538: .4byte 0x0203DB38 @ EWRAM+0x3DB38
.L0813A53C: .4byte 0x0203DB3A @ EWRAM+0x3DB3A
.L0813A540: .4byte 0x0203DB4A @ EWRAM+0x3DB4A
.L0813A544: .4byte 0x0203DB6C @ EWRAM+0x3DB6C
.L0813A548: .4byte 0x03006968 @ IWRAM+0x6968
.L0813A54C:
	cmp r1, #8
	bne .L0813A562
	ldr r2, .L0813A568
	ldr r0, .L0813A56C
	ldrh r1, [r0]
	ldr r0, [r2]
	adds r4, r0, #0
	muls r4, r1, r4
	adds r0, r4, #0
	bl sub_080C30AC
.L0813A562:
	pop {r4, r5}
	pop {r0}
	bx r0
.L0813A568: .4byte 0x030037F0 @ IWRAM+0x37F0
.L0813A56C: .4byte 0x0203DB84 @ EWRAM+0x3DB84

	thumb_func_start ScriptOpAlt_435
ScriptOpAlt_435: @ 0x0813A570
	ldr r1, .L0813A57C
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bx lr
	.byte 0x00, 0x00
.L0813A57C: .4byte 0x0203DB40 @ EWRAM+0x3DB40

	thumb_func_start ScriptOp_436
ScriptOp_436: @ 0x0813A580
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_436
ScriptOpAlt_436: @ 0x0813A584
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOp_437
ScriptOp_437: @ 0x0813A588
	bx lr
	.byte 0x00, 0x00

	thumb_func_start ScriptOpAlt_437
ScriptOpAlt_437: @ 0x0813A58C
	bx lr
	.byte 0x00, 0x00
