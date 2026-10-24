	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_0815C140
sub_0815C140: @ 0x0815C140
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L0815C160
	ldr r2, .L0815C164
	mov r0, sp
	bl CpuSet
	ldr r0, .L0815C168
	bl SetMainCallback
	add sp, #4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815C160: .4byte 0x0203B454 @ EWRAM+0x3B454
.L0815C164: .4byte 0x05000040 @ PLTT+0x40
.L0815C168: .4byte sub_0815C1A8

	thumb_func_start sub_0815C16C
sub_0815C16C: @ 0x0815C16C
.L0815C16C:
	ldr r1, .L0815C18C
	ldr r0, .L0815C190
	str r0, [r1]
	ldr r0, .L0815C194
	str r0, [r1, #4]
	ldr r0, .L0815C198
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, .L0815C19C
	str r0, [r1]
	ldr r0, .L0815C1A0
	str r0, [r1, #4]
	ldr r0, .L0815C1A4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
.L0815C18C: .4byte 0x040000D4 @ REG_DMA3SAD
.L0815C190: .4byte 0x0200F874 @ EWRAM+0xF874
.L0815C194: .4byte 0x06008000 @ VRAM+0x8000
.L0815C198: .4byte 0x84002000
.L0815C19C: .4byte 0x02000000 @ EWRAM
.L0815C1A0: .4byte 0x06001000 @ VRAM+0x1000
.L0815C1A4: .4byte 0x84000200

	thumb_func_start sub_0815C1A8
sub_0815C1A8: @ 0x0815C1A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r7, .L0815C314
	movs r6, #0
	str r6, [sp, #4]
	ldr r2, .L0815C318
	add r0, sp, #4
	adds r1, r7, #0
	bl CpuSet
	bl sub_080C1450
	ldr r1, .L0815C31C
	ldr r2, .L0815C320
	adds r0, r2, #0
	strh r0, [r1]
	bl sub_080C1384
	ldr r4, .L0815C324
	ldr r0, .L0815C328
	str r0, [r4]
	ldr r0, .L0815C32C
	str r0, [r4, #4]
	ldr r0, .L0815C330
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	bl Palette_MarkDirty
	str r6, [sp, #8]
	add r0, sp, #8
	mov r8, r0
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, .L0815C334
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, .L0815C338
	ldr r5, .L0815C33C
	adds r1, r5, #0
	bl LZ77UnCompWram
	ldr r0, .L0815C340
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r5, r2
	bl LZ77UnCompWram
	ldr r0, .L0815C344
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r5, r2
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, .L0815C348
	str r0, [r4, #4]
	ldr r0, .L0815C34C
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	str r6, [sp, #8]
	mov r0, r8
	str r0, [r4]
	str r5, [r4, #4]
	ldr r0, .L0815C350
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r5, .L0815C354
	movs r4, #0
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r3, r2, #0
	ldr r2, .L0815C358
.L0815C240:
	lsls r0, r4, #1
	adds r0, r0, r5
	adds r1, r4, r3
	strh r1, [r0]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r2
	bls .L0815C240
	movs r0, #1
	str r0, [r7, #4]
	bl sub_0815C16C
	ldr r2, .L0815C35C
	ldr r0, [r7, #4]
	subs r0, #0xa0
	movs r1, #0xff
	ands r0, r1
	strh r0, [r2]
	ldr r0, .L0815C360
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0815C364
	strh r1, [r0]
	bl Task_ClearAll
	bl Windows_Init
	movs r4, #0
	ldr r3, .L0815C368
	adds r5, r3, #0
	adds r5, #0x1c
.L0815C280:
	lsls r2, r4, #4
	adds r2, r7, r2
	lsls r1, r4, #5
	adds r0, r1, r3
	ldr r0, [r0]
	strh r0, [r2, #0x2c]
	adds r0, r3, #4
	adds r0, r1, r0
	ldr r0, [r0]
	strh r0, [r2, #0x2e]
	adds r0, r3, #0
	adds r0, #8
	adds r0, r1, r0
	ldr r0, [r0]
	strh r0, [r2, #0x30]
	adds r0, r3, #0
	adds r0, #0xc
	adds r0, r1, r0
	ldr r0, [r0]
	strh r0, [r2, #0x32]
	adds r0, r3, #0
	adds r0, #0x10
	adds r0, r1, r0
	ldr r0, [r0]
	strh r0, [r2, #0x34]
	adds r0, r3, #0
	adds r0, #0x14
	adds r0, r1, r0
	ldr r0, [r0]
	strh r0, [r2, #0x36]
	adds r0, r3, #0
	adds r0, #0x18
	adds r0, r1, r0
	ldr r0, [r0]
	strh r0, [r2, #0x38]
	adds r1, r1, r5
	ldr r0, [r1]
	strh r0, [r2, #0x3a]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #8
	bls .L0815C280
	ldrh r0, [r7, #0x2c]
	ldrh r1, [r7, #0x2e]
	ldrh r2, [r7, #0x30]
	ldrh r3, [r7, #0x32]
	lsls r4, r4, #4
	adds r4, r7, r4
	ldrh r4, [r4, #0x38]
	str r4, [sp]
	bl sub_0815C75C
	ldrh r0, [r7, #0x38]
	strh r0, [r7, #0x26]
	ldr r0, .L0815C36C
	bl SetMainCallback
	ldr r1, .L0815C370
	ldr r2, .L0815C374
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, .L0815C378
	movs r0, #0x18
	strh r0, [r1]
	ldr r1, .L0815C37C
	movs r0, #1
	strh r0, [r1]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0815C314: .4byte 0x0203B454 @ EWRAM+0x3B454
.L0815C318: .4byte 0x05000040 @ PLTT+0x40
.L0815C31C: .4byte 0x0400000A @ REG_BG1CNT
.L0815C320: .4byte 0x00000209
.L0815C324: .4byte 0x040000D4 @ REG_DMA3SAD
.L0815C328: .4byte 0x030029B0 @ IWRAM+0x29B0
.L0815C32C: .4byte 0x03002DB0 @ IWRAM+0x2DB0
.L0815C330: .4byte 0x84000100
.L0815C334: .4byte 0x85001000
.L0815C338: .4byte gUnknown_081B6270
.L0815C33C: .4byte 0x0200F874 @ EWRAM+0xF874
.L0815C340: .4byte gUnknown_081B6594
.L0815C344: .4byte gUnknown_081B68BC
.L0815C348: .4byte 0x06010400 @ VRAM+0x10400
.L0815C34C: .4byte 0x84000A00
.L0815C350: .4byte 0x85002000
.L0815C354: .4byte 0x02000000 @ EWRAM
.L0815C358: .4byte 0x000003FF
.L0815C35C: .4byte 0x03000006 @ IWRAM+0x6
.L0815C360: .4byte 0x03000040 @ IWRAM+0x40
.L0815C364: .4byte 0x0203DB6A @ EWRAM+0x3DB6A
.L0815C368: .4byte gUnknown_087F2C50
.L0815C36C: .4byte sub_0815C380
.L0815C370: .4byte 0x04000200 @ REG_IE
.L0815C374: .4byte 0x00002003
.L0815C378: .4byte 0x04000004 @ REG_DISPSTAT
.L0815C37C: .4byte 0x04000208 @ REG_IME

	thumb_func_start sub_0815C380
sub_0815C380: @ 0x0815C380
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	ldr r5, .L0815C3D8
	adds r0, r5, #0
	adds r0, #0xac
	ldr r0, [r0]
	adds r6, r0, #0
	adds r6, #0x24
	bl Task_RunAll
	ldrh r0, [r5, #0x28]
	cmp r0, #6
	bls .L0815C3A2
	b .L0815C5C6
.L0815C3A2:
	ldr r0, [r5, #0x14]
	ldrh r3, [r5, #0x28]
	cmp r0, #0
	bne .L0815C404
	lsls r0, r3, #4
	adds r0, r0, r5
	ldrh r2, [r0, #0x34]
	ldrh r0, [r0, #0x2e]
	subs r2, r2, r0
	strh r2, [r5, #0x14]
	adds r0, r3, #0
	lsls r0, r0, #4
	adds r0, r0, r5
	ldrh r1, [r0, #0x36]
	ldrh r0, [r0, #0x30]
	subs r1, r1, r0
	strh r1, [r5, #0x16]
	lsls r2, r2, #0x10
	cmp r2, #0
	bge .L0815C3E0
	ldr r0, .L0815C3DC
	strh r0, [r5, #0x1c]
	movs r1, #0x14
	ldrsh r0, [r5, r1]
	rsbs r0, r0, #0
	strh r0, [r5, #0x14]
	b .L0815C3E4
.L0815C3D8: .4byte 0x0203B454 @ EWRAM+0x3B454
.L0815C3DC: .4byte 0x0000FFFF
.L0815C3E0:
	movs r0, #1
	strh r0, [r5, #0x1c]
.L0815C3E4:
	movs r2, #0x16
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bge .L0815C400
	ldr r0, .L0815C3FC
	strh r0, [r5, #0x1e]
	movs r4, #0x16
	ldrsh r0, [r5, r4]
	rsbs r0, r0, #0
	strh r0, [r5, #0x16]
	b .L0815C404
	.byte 0x00, 0x00
.L0815C3FC: .4byte 0x0000FFFF
.L0815C400:
	movs r0, #1
	strh r0, [r5, #0x1e]
.L0815C404:
	movs r7, #0x14
	ldrsh r1, [r5, r7]
	movs r2, #0x16
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt .L0815C4B0
	lsls r0, r3, #4
	adds r2, r5, r0
	movs r4, #8
	ldrsh r1, [r6, r4]
	movs r7, #0x34
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bne .L0815C466
	movs r0, #0xa
	ldrsh r1, [r6, r0]
	movs r4, #0x36
	ldrsh r0, [r2, r4]
	cmp r1, r0
	bne .L0815C466
	adds r1, r3, #0
	cmp r1, #0
	bne .L0815C442
	adds r0, r3, #1
	strh r0, [r5, #0x28]
	strh r1, [r5, #0x1a]
	strh r1, [r5, #0x18]
	strh r1, [r5, #0x20]
	strh r1, [r5, #0x16]
	strh r1, [r5, #0x14]
	b .L0815C5C6
.L0815C442:
	cmp r1, #6
	bne .L0815C45E
	adds r0, r3, #1
	movs r4, #0
	strh r0, [r5, #0x28]
	bl sub_0815C7CC
	strh r4, [r5, #0x24]
	strh r4, [r5, #0x1a]
	strh r4, [r5, #0x18]
	strh r4, [r5, #0x20]
	strh r4, [r5, #0x16]
	strh r4, [r5, #0x14]
	b .L0815C564
.L0815C45E:
	ldrh r0, [r5, #0x22]
	cmp r0, #0
	beq .L0815C532
	b .L0815C53C
.L0815C466:
	ldrh r0, [r5, #0x18]
	ldrh r1, [r5, #0x1a]
	ldrh r2, [r5, #0x26]
	bl sub_0815C7E0
	ldrh r0, [r5, #0x1c]
	movs r1, #0
	strh r0, [r5, #0x18]
	strh r1, [r5, #0x1a]
	ldrh r0, [r5, #0x16]
	ldrh r6, [r5, #0x20]
	adds r0, r0, r6
	strh r0, [r5, #0x20]
	ldr r0, [r5, #0x10]
	movs r1, #3
	bl __umodsi3
	cmp r0, #0
	bne .L0815C49A
	ldrh r0, [r5, #0x28]
	lsls r0, r0, #4
	adds r0, r5, r0
	ldrh r0, [r0, #0x3a]
	ldrh r7, [r5, #0x26]
	adds r0, r0, r7
	strh r0, [r5, #0x26]
.L0815C49A:
	ldrh r1, [r5, #0x20]
	movs r2, #0x14
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge .L0815C4A6
	b .L0815C5C6
.L0815C4A6:
	ldrh r0, [r5, #0x1e]
	strh r0, [r5, #0x1a]
	ldrh r0, [r5, #0x20]
	ldrh r1, [r5, #0x14]
	b .L0815C5C2
.L0815C4B0:
	adds r2, r3, #0
	lsls r0, r2, #4
	adds r4, r5, r0
	movs r7, #8
	ldrsh r1, [r6, r7]
	movs r7, #0x34
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bne .L0815C57C
	movs r0, #0xa
	ldrsh r1, [r6, r0]
	movs r6, #0x36
	ldrsh r0, [r4, r6]
	cmp r1, r0
	bne .L0815C57C
	lsls r0, r2, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne .L0815C4E8
	adds r0, r2, #1
	strh r0, [r5, #0x28]
	strh r1, [r5, #0x1a]
	strh r1, [r5, #0x18]
	strh r1, [r5, #0x20]
	strh r1, [r5, #0x16]
	strh r1, [r5, #0x14]
	strh r1, [r5, #0x22]
	b .L0815C5C6
.L0815C4E8:
	cmp r1, #6
	bne .L0815C52C
	adds r0, r3, #1
	movs r4, #0
	strh r0, [r5, #0x28]
	bl sub_0815C7CC
	strh r4, [r5, #0x24]
	strh r4, [r5, #0x1a]
	strh r4, [r5, #0x18]
	strh r4, [r5, #0x20]
	strh r4, [r5, #0x16]
	strh r4, [r5, #0x14]
	ldrh r4, [r5, #0x28]
	lsls r4, r4, #4
	adds r4, r5, r4
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x2e]
	ldrh r2, [r4, #0x30]
	ldrh r3, [r4, #0x32]
	ldrh r4, [r4, #0x38]
	str r4, [sp]
	bl sub_0815C75C
	ldr r0, .L0815C524
	ldr r1, .L0815C528
	bl Task_Create
	b .L0815C5C6
	.byte 0x00, 0x00
.L0815C524: .4byte gUnknown_087F2DD4
.L0815C528: .4byte 0x0000FFFF
.L0815C52C:
	ldrh r0, [r5, #0x22]
	cmp r0, #0
	bne .L0815C53C
.L0815C532:
	bl sub_0815C7CC
	bl sub_0815C828
	b .L0815C5C6
.L0815C53C:
	movs r1, #0
	strh r1, [r5, #0x22]
	ldrh r0, [r5, #0x28]
	adds r0, #1
	strh r0, [r5, #0x28]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi .L0815C5C6
	strh r1, [r5, #0x24]
	strh r1, [r5, #0x1a]
	strh r1, [r5, #0x18]
	strh r1, [r5, #0x20]
	strh r1, [r5, #0x16]
	strh r1, [r5, #0x14]
	ldrh r0, [r5, #0x28]
	lsls r0, r0, #4
	adds r0, r5, r0
	ldrh r0, [r0, #0x38]
	strh r0, [r5, #0x26]
.L0815C564:
	ldrh r4, [r5, #0x28]
	lsls r4, r4, #4
	adds r4, r5, r4
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x2e]
	ldrh r2, [r4, #0x30]
	ldrh r3, [r4, #0x32]
	ldrh r4, [r4, #0x38]
	str r4, [sp]
	bl sub_0815C75C
	b .L0815C5C6
.L0815C57C:
	ldrh r0, [r5, #0x18]
	ldrh r1, [r5, #0x1a]
	ldrh r2, [r5, #0x26]
	bl sub_0815C7E0
	ldrh r0, [r5, #0x1e]
	movs r1, #0
	strh r0, [r5, #0x1a]
	strh r1, [r5, #0x18]
	ldrh r0, [r5, #0x14]
	ldrh r7, [r5, #0x20]
	adds r0, r0, r7
	strh r0, [r5, #0x20]
	ldr r0, [r5, #0x10]
	movs r1, #3
	bl __umodsi3
	cmp r0, #0
	bne .L0815C5B0
	ldrh r0, [r5, #0x28]
	lsls r0, r0, #4
	adds r0, r5, r0
	ldrh r0, [r0, #0x3a]
	ldrh r1, [r5, #0x26]
	adds r0, r0, r1
	strh r0, [r5, #0x26]
.L0815C5B0:
	ldrh r1, [r5, #0x20]
	movs r2, #0x16
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt .L0815C5C6
	ldrh r0, [r5, #0x1c]
	strh r0, [r5, #0x18]
	ldrh r0, [r5, #0x20]
	ldrh r1, [r5, #0x16]
.L0815C5C2:
	subs r0, r0, r1
	strh r0, [r5, #0x20]
.L0815C5C6:
	ldr r0, [r5, #0x10]
	movs r4, #1
	mov r8, r4
	ands r0, r4
	cmp r0, #0
	bne .L0815C690
	ldr r3, [r5, #4]
	lsrs r0, r3, #4
	lsls r0, r0, #3
	ldr r4, .L0815C648
	adds r6, r0, r4
	ldr r1, [r6]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0815C5E8
	b .L0815C748
.L0815C5E8:
	adds r7, r3, #1
	str r7, [r5, #4]
	ldr r2, .L0815C64C
	adds r0, r3, #0
	subs r0, #0x9f
	movs r1, #0xff
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xf
	ands r0, r7
	cmp r0, #0
	bne .L0815C690
	ldr r0, [r5]
	cmp r0, #0
	bne .L0815C65C
	lsrs r0, r7, #4
	lsls r0, r0, #3
	adds r6, r0, r4
	ldr r0, [r6]
	cmp r0, #0
	bne .L0815C654
	ldr r4, [r6, #4]
	movs r6, #0
	movs r0, #0xff
	mov r8, r0
	mov r1, r8
	ands r1, r7
	mov r8, r1
	ldrh r0, [r4]
	cmp r0, #0
	beq .L0815C65C
.L0815C626:
	ldrh r0, [r4]
	movs r1, #0
	str r1, [sp]
	ldr r1, .L0815C650
	adds r2, r6, #0
	mov r3, r8
	bl Font_DrawGlyphTinted
	adds r4, #2
	adds r0, r6, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldrh r0, [r4]
	cmp r0, #0
	bne .L0815C626
	b .L0815C65C
.L0815C648: .4byte gUnknown_087F28B0
.L0815C64C: .4byte 0x03000006 @ IWRAM+0x6
.L0815C650: .4byte 0x0200F874 @ EWRAM+0xF874
.L0815C654:
	cmp r0, #0
	bge .L0815C65C
	mov r2, r8
	str r2, [r5]
.L0815C65C:
	ldr r0, [r5, #4]
	cmp r0, #0xaf
	bls .L0815C688
	subs r0, #0xb0
	movs r1, #0xff
	ands r0, r1
	lsrs r0, r0, #3
	lsls r0, r0, #0xa
	ldr r1, .L0815C6C4
	adds r0, r0, r1
	movs r1, #0
	str r1, [sp, #0xc]
	ldr r1, .L0815C6C8
	add r4, sp, #0xc
	str r4, [r1]
	str r0, [r1, #4]
	ldr r0, .L0815C6CC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
.L0815C688:
	ldr r0, .L0815C6D0
	movs r1, #1
	bl VBlankTask_AddCounted
.L0815C690:
	ldr r1, [r5, #8]
	lsls r2, r1, #3
	ldr r0, .L0815C6D4
	adds r6, r2, r0
	lsls r1, r1, #4
	adds r1, #0xa0
	movs r2, #0xff
	ldrb r0, [r5, #4]
	subs r4, r1, r0
	ands r4, r2
	mov sb, r4
	movs r7, #0
	mov r8, r7
	ldr r1, [r6]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0815C742
	movs r7, #0x20
.L0815C6B6:
	ldr r0, [r6]
	cmp r0, #1
	bne .L0815C6D8
	ldr r0, [r6, #4]
	str r7, [sp]
	movs r1, #4
	b .L0815C6E2
.L0815C6C4: .4byte 0x0200F874 @ EWRAM+0xF874
.L0815C6C8: .4byte 0x040000D4 @ REG_DMA3SAD
.L0815C6CC: .4byte 0x85000200
.L0815C6D0: .4byte sub_0815C16C
.L0815C6D4: .4byte gUnknown_087F28B0
.L0815C6D8:
	cmp r0, #2
	bne .L0815C6F8
	ldr r0, [r6, #4]
	str r7, [sp]
	movs r1, #0x78
.L0815C6E2:
	str r1, [sp, #4]
	subs r1, r4, #4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0815C716
.L0815C6F8:
	cmp r0, #3
	bne .L0815C716
	ldr r0, [r6, #4]
	str r7, [sp]
	movs r1, #0x6c
	str r1, [sp, #4]
	subs r1, r4, #4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0815C716:
	adds r4, #0x10
	ldr r1, .L0815C758
	adds r0, r1, #0
	ands r4, r0
	mov r2, sb
	cmp r2, #0x9f
	bhi .L0815C728
	cmp r4, #0x9f
	bhi .L0815C742
.L0815C728:
	adds r6, #8
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0xa
	bhi .L0815C742
	ldr r1, [r6]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0815C6B6
.L0815C742:
	ldr r0, [r5, #0x10]
	adds r0, #1
	str r0, [r5, #0x10]
.L0815C748:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815C758: .4byte 0x000001FF

	thumb_func_start sub_0815C75C
sub_0815C75C: @ 0x0815C75C
.L0815C75C:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r0, [sp, #0x24]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r4, .L0815C7C8
	str r3, [sp]
	movs r0, #0
	mov sb, r0
	str r0, [sp, #4]
	adds r1, r5, #0
	adds r2, r6, #0
	mov r3, r8
	bl sub_080C4618
	adds r4, #0xac
	str r0, [r4]
	adds r1, r0, #0
	adds r1, #0x48
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r7, r0
	bls .L0815C7AC
	adds r7, r0, #0
.L0815C7AC:
	movs r0, #1
	strh r0, [r1]
	strh r7, [r1, #2]
	strh r7, [r1, #4]
	mov r0, sb
	strh r0, [r1, #6]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815C7C8: .4byte 0x0203B454 @ EWRAM+0x3B454

	thumb_func_start sub_0815C7CC
sub_0815C7CC: @ 0x0815C7CC
.L0815C7CC:
	push {lr}
	ldr r0, .L0815C7DC
	adds r0, #0xac
	ldr r0, [r0]
	bl Task_End
	pop {r0}
	bx r0
.L0815C7DC: .4byte 0x0203B454 @ EWRAM+0x3B454

	thumb_func_start sub_0815C7E0
sub_0815C7E0: @ 0x0815C7E0
.L0815C7E0:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	ldr r2, .L0815C824
	adds r2, #0xac
	ldr r2, [r2]
	adds r3, r2, #0
	adds r3, #0x24
	adds r2, #0x48
	lsrs r0, r0, #0x10
	ldrh r5, [r3, #8]
	adds r0, r0, r5
	strh r0, [r3, #8]
	lsrs r1, r1, #0x10
	ldrh r0, [r3, #0xa]
	adds r1, r1, r0
	strh r1, [r3, #0xa]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r4, r0
	bls .L0815C810
	adds r4, r0, #0
.L0815C810:
	movs r0, #1
	strh r0, [r2]
	strh r4, [r2, #2]
	strh r4, [r2, #4]
	movs r0, #0
	strh r0, [r2, #6]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815C824: .4byte 0x0203B454 @ EWRAM+0x3B454

	thumb_func_start sub_0815C828
sub_0815C828: @ 0x0815C828
.L0815C828:
	push {lr}
	ldr r1, .L0815C840
	ldrh r0, [r1, #0x28]
	cmp r0, #5
	bne .L0815C844
	ldrh r2, [r1, #0x24]
	movs r0, #0x96
	lsls r0, r0, #2
	cmp r2, r0
	beq .L0815C852
	b .L0815C858
	.byte 0x00, 0x00
.L0815C840: .4byte 0x0203B454 @ EWRAM+0x3B454
.L0815C844:
	cmp r0, #6
	beq .L0815C852
	ldrh r2, [r1, #0x24]
	movs r0, #0xaf
	lsls r0, r0, #1
	cmp r2, r0
	bne .L0815C858
.L0815C852:
	movs r0, #1
	strh r0, [r1, #0x22]
	b .L0815C85C
.L0815C858:
	adds r0, r2, #1
	strh r0, [r1, #0x24]
.L0815C85C:
	pop {r0}
	bx r0

	thumb_func_start sub_0815C860
sub_0815C860: @ 0x0815C860
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L0815C87C
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L0815C880
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	bx lr
.L0815C87C: .4byte 0x040000D4 @ REG_DMA3SAD
.L0815C880: .4byte 0x85001000

	thumb_func_start sub_0815C884
sub_0815C884: @ 0x0815C884
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x3a
	bl sub_080B6DB4
	str r0, [r4, #0x24]
	ldr r0, .L0815C8D4
	movs r4, #0xe8
	strb r4, [r0]
	ldr r0, .L0815C8D8
	movs r3, #8
	strb r3, [r0]
	ldr r0, .L0815C8DC
	movs r1, #0x80
	strb r1, [r0]
	ldr r0, .L0815C8E0
	movs r2, #0x18
	strb r2, [r0]
	ldr r0, .L0815C8E4
	strb r4, [r0]
	ldr r0, .L0815C8E8
	strb r3, [r0]
	ldr r0, .L0815C8EC
	strb r1, [r0]
	ldr r0, .L0815C8F0
	strb r2, [r0]
	ldr r1, .L0815C8F4
	movs r0, #0
	strb r0, [r1]
	ldr r1, .L0815C8F8
	ldr r0, .L0815C8FC
	strb r2, [r0]
	strb r2, [r1]
	ldr r0, .L0815C900
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r4}
	pop {r0}
	bx r0
.L0815C8D4: .4byte 0x03000030 @ IWRAM+0x30
.L0815C8D8: .4byte 0x03000031 @ IWRAM+0x31
.L0815C8DC: .4byte 0x03000034 @ IWRAM+0x34
.L0815C8E0: .4byte 0x03000035 @ IWRAM+0x35
.L0815C8E4: .4byte 0x03000032 @ IWRAM+0x32
.L0815C8E8: .4byte 0x03000033 @ IWRAM+0x33
.L0815C8EC: .4byte 0x03000036 @ IWRAM+0x36
.L0815C8F0: .4byte 0x03000037 @ IWRAM+0x37
.L0815C8F4: .4byte 0x0300003A @ IWRAM+0x3A
.L0815C8F8: .4byte 0x03000038 @ IWRAM+0x38
.L0815C8FC: .4byte 0x03000039 @ IWRAM+0x39
.L0815C900: .4byte sub_0815C860

	thumb_func_start sub_0815C904
sub_0815C904: @ 0x0815C904
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x24]
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0815C914
	movs r0, #0
	b .L0815C916
.L0815C914:
	movs r0, #1
.L0815C916:
	strh r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start sub_0815C91C
sub_0815C91C: @ 0x0815C91C
	push {lr}
	sub sp, #4
	ldr r1, .L0815C944
	ldr r2, .L0815C948
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	movs r0, #0xe8
	lsls r0, r0, #1
	movs r1, #0x10
	movs r2, #8
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	add sp, #4
	pop {r0}
	bx r0
.L0815C944: .4byte gUnknown_085426E0
.L0815C948: .4byte 0x03002D50 @ IWRAM+0x2D50

	thumb_func_start sub_0815C94C
sub_0815C94C: @ 0x0815C94C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x24
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	movs r1, #8
	movs r2, #0x1c
	movs r3, #8
	bl Window_CreateOpen
	str r0, [r4, #0x24]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Font_ResetGlyphSpriteCache
	movs r0, #0
	bl YesNo_Create
	str r0, [r5, #4]
	ldr r1, .L0815C998
	ldr r2, .L0815C99C
	movs r3, #0x80
	lsls r3, r3, #3
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl Palette_CopyWithEffect
	bl Palette_MarkDirty
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815C998: .4byte 0x030029B0 @ IWRAM+0x29B0
.L0815C99C: .4byte 0x03002DB0 @ IWRAM+0x2DB0

	thumb_func_start sub_0815C9A0
sub_0815C9A0: @ 0x0815C9A0
	push {lr}
	ldr r0, [r0, #0x24]
	movs r1, #1
	bl Window_Close
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0815C9B0
sub_0815C9B0: @ 0x0815C9B0
	push {lr}
	movs r0, #0x5e
	bl Flag_Test
	cmp r0, #0
	beq .L0815C9C0
	movs r0, #0
	b .L0815C9CC
.L0815C9C0:
	movs r0, #0x5f
	bl Flag_Test
	cmp r0, #0
	beq .L0815C9D4
	movs r0, #2
.L0815C9CC:
	movs r1, #1
	bl sub_080C2A50
	b .L0815C9DC
.L0815C9D4:
	movs r0, #1
	movs r1, #1
	bl sub_080C2A50
.L0815C9DC:
	pop {r0}
	bx r0

	thumb_func_start sub_0815C9E0
sub_0815C9E0: @ 0x0815C9E0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	bl Task_IsFree
	cmp r0, #1
	bne .L0815C9FC
	strh r0, [r4, #0x1c]
	ldr r0, .L0815C9F8
	ldr r0, [r0]
	strh r0, [r4, #0x1e]
	b .L0815CA00
.L0815C9F8: .4byte 0x030031CC @ IWRAM+0x31CC
.L0815C9FC:
	movs r0, #0
	strh r0, [r4, #0x1c]
.L0815CA00:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0815CA08
sub_0815CA08: @ 0x0815CA08
	push {lr}
	bl sub_080C10F4
	movs r0, #0xee
	bl Flag_Set
	movs r0, #2
	bl Flag_Set
	movs r0, #0x80
	lsls r0, r0, #1
	bl Flag_Set
	ldr r0, .L0815CA48
	movs r1, #0
	str r1, [r0]
	ldr r0, .L0815CA4C
	str r1, [r0]
	ldr r1, .L0815CA50
	movs r0, #2
	strh r0, [r1, #0x12]
	movs r0, #6
	strh r0, [r1, #0x14]
	movs r0, #3
	movs r1, #4
	bl SaveScreen_Open
	ldr r0, .L0815CA54
	bl SetMainCallback
	pop {r0}
	bx r0
.L0815CA48: .4byte 0x03004614 @ IWRAM+0x4614
.L0815CA4C: .4byte 0x03004514 @ IWRAM+0x4514
.L0815CA50: .4byte 0x03004550 @ IWRAM+0x4550
.L0815CA54: .4byte sub_0815CAB4

	thumb_func_start sub_0815CA58
sub_0815CA58: @ 0x0815CA58
	push {lr}
	sub sp, #8
	ldr r0, .L0815CA78
	movs r1, #0x46
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #0
	movs r3, #0xc
	bl Text_DrawSpriteString
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815CA78: .4byte gUnknown_087F2D50

	thumb_func_start sub_0815CA7C
sub_0815CA7C: @ 0x0815CA7C
	push {lr}
	ldr r0, .L0815CA98
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L0815CA9C
	strb r1, [r0]
	ldr r0, .L0815CAA0
	strb r1, [r0]
	ldr r0, .L0815CAA4
	movs r1, #1
	bl VBlankTask_AddCounted
	pop {r0}
	bx r0
.L0815CA98: .4byte 0x03000038 @ IWRAM+0x38
.L0815CA9C: .4byte 0x03000039 @ IWRAM+0x39
.L0815CAA0: .4byte 0x0300003A @ IWRAM+0x3A
.L0815CAA4: .4byte sub_0815C860

	thumb_func_start sub_0815CAA8
sub_0815CAA8: @ 0x0815CAA8
	push {lr}
	movs r0, #0
	bl sub_080D5B8C
	pop {r0}
	bx r0

	thumb_func_start sub_0815CAB4
sub_0815CAB4: @ 0x0815CAB4
	push {lr}
	ldr r1, .L0815CAD4
	movs r0, #0
	str r0, [r1]
	ldr r0, .L0815CAD8
	movs r1, #0x3f
	strb r1, [r0]
	ldr r0, .L0815CADC
	strb r1, [r0]
	ldr r0, .L0815CAE0
	strb r1, [r0]
	ldr r0, .L0815CAE4
	bl SetMainCallback
	pop {r0}
	bx r0
.L0815CAD4: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L0815CAD8: .4byte 0x03000038 @ IWRAM+0x38
.L0815CADC: .4byte 0x03000039 @ IWRAM+0x39
.L0815CAE0: .4byte 0x0300003A @ IWRAM+0x3A
.L0815CAE4: .4byte sub_0815CAE8

	thumb_func_start sub_0815CAE8
sub_0815CAE8: @ 0x0815CAE8
	push {lr}
	bl Task_RunAll
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start CpuFastSet
CpuFastSet: @ 0x0815CAF4
.L0815CAF4:
	svc #0xc
	bx lr

	thumb_func_start CpuSet
CpuSet: @ 0x0815CAF8
.L0815CAF8:
	svc #0xb
	bx lr

	thumb_func_start HuffUnComp
HuffUnComp: @ 0x0815CAFC
.L0815CAFC:
	svc #0x13
	bx lr

	thumb_func_start LZ77UnCompWram
LZ77UnCompWram: @ 0x0815CB00
.L0815CB00:
	svc #0x11
	bx lr

	thumb_func_start ObjAffineSet
ObjAffineSet: @ 0x0815CB04
.L0815CB04:
	svc #0xf
	bx lr

	thumb_func_start RLUnCompWram
RLUnCompWram: @ 0x0815CB08
.L0815CB08:
	svc #0x14
	bx lr

	thumb_func_start SoftReset
SoftReset: @ 0x0815CB0C
.L0815CB0C:
	ldr r3, .L0815CB1C
	movs r2, #0
	strb r2, [r3]
	ldr r1, .L0815CB20
	mov sp, r1
	svc #1
	svc #0
	.byte 0x00, 0x00
.L0815CB1C: .4byte 0x04000208 @ REG_IME
.L0815CB20: .4byte 0x03007F00 @ IWRAM+0x7F00

	thumb_func_start VBlankIntrWait
VBlankIntrWait: @ 0x0815CB24
.L0815CB24:
	movs r2, #0
	svc #5
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0815CB2C
sub_0815CB2C: @ 0x0815CB2C
	push {r4, lr}
	adds r4, r0, #0
	subs r3, r2, #1
	cmp r2, #0
	beq .L0815CB48
	movs r2, #1
	rsbs r2, r2, #0
.L0815CB3A:
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, #1
	adds r1, #1
	subs r3, #1
	cmp r3, r2
	bne .L0815CB3A
.L0815CB48:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0815CB50
sub_0815CB50: @ 0x0815CB50
.L0815CB50:
	push {r4, r5, r6, lr}
	sub sp, #0x80
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r2, .L0815CB7C
	ldrh r0, [r2]
	ldr r1, .L0815CB80
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	strh r0, [r2]
	ldr r3, .L0815CB84
	movs r0, #1
	bics r3, r0
	mov r2, sp
	ldr r0, .L0815CB88
	ldr r1, .L0815CB84
	subs r0, r0, r1
	lsls r0, r0, #0xf
	b .L0815CB98
	.byte 0x00, 0x00
.L0815CB7C: .4byte 0x04000204 @ REG_WAITCNT
.L0815CB80: .4byte 0x0000FFFC
.L0815CB84: .4byte sub_0815CB2C
.L0815CB88: .4byte sub_0815CB50
.L0815CB8C:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r0, r1, #1
	lsls r0, r0, #0x10
.L0815CB98:
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne .L0815CB8C
	mov r3, sp
	adds r3, #1
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl _call_via_r3
	add sp, #0x80
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_0815CBB4
sub_0815CBB4: @ 0x0815CBB4
.L0815CBB4:
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	ldr r2, .L0815CBEC
	ldrh r0, [r2]
	ldr r1, .L0815CBF0
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	strh r0, [r2]
	subs r3, #1
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	beq .L0815CBE4
	adds r1, r0, #0
.L0815CBD6:
	ldrb r0, [r5]
	strb r0, [r4]
	adds r5, #1
	adds r4, #1
	subs r3, #1
	cmp r3, r1
	bne .L0815CBD6
.L0815CBE4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815CBEC: .4byte 0x04000204 @ REG_WAITCNT
.L0815CBF0: .4byte 0x0000FFFC

	thumb_func_start sub_0815CBF4
sub_0815CBF4: @ 0x0815CBF4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	subs r4, r2, #1
	cmp r2, #0
	beq .L0815CC1A
	movs r2, #1
	rsbs r2, r2, #0
.L0815CC04:
	ldrb r1, [r3]
	ldrb r0, [r5]
	adds r5, #1
	adds r3, #1
	cmp r1, r0
	beq .L0815CC14
	subs r0, r3, #1
	b .L0815CC1C
.L0815CC14:
	subs r4, #1
	cmp r4, r2
	bne .L0815CC04
.L0815CC1A:
	movs r0, #0
.L0815CC1C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815CC24
sub_0815CC24: @ 0x0815CC24
.L0815CC24:
	push {r4, r5, r6, lr}
	sub sp, #0xc0
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r2, .L0815CC50
	ldrh r0, [r2]
	ldr r1, .L0815CC54
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	strh r0, [r2]
	ldr r3, .L0815CC58
	movs r0, #1
	bics r3, r0
	mov r2, sp
	ldr r0, .L0815CC5C
	ldr r1, .L0815CC58
	subs r0, r0, r1
	lsls r0, r0, #0xf
	b .L0815CC6C
	.byte 0x00, 0x00
.L0815CC50: .4byte 0x04000204 @ REG_WAITCNT
.L0815CC54: .4byte 0x0000FFFC
.L0815CC58: .4byte sub_0815CBF4
.L0815CC5C: .4byte sub_0815CC24
.L0815CC60:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r0, r1, #1
	lsls r0, r0, #0x10
.L0815CC6C:
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne .L0815CC60
	mov r3, sp
	adds r3, #1
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl _call_via_r3
	add sp, #0xc0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_0815CC88
sub_0815CC88: @ 0x0815CC88
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	movs r7, #0
	b .L0815CC9A
.L0815CC94:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
.L0815CC9A:
	cmp r7, #2
	bhi .L0815CCB8
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl sub_0815CBB4
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl sub_0815CC24
	adds r3, r0, #0
	cmp r3, #0
	bne .L0815CC94
.L0815CCB8:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start _call_via_r0
_call_via_r0: @ 0x0815CCC0
.L0815CCC0:
	bx r0
	.byte 0xC0, 0x46

	thumb_func_start _call_via_r1
_call_via_r1: @ 0x0815CCC4
.L0815CCC4:
	bx r1
	.byte 0xC0, 0x46

	thumb_func_start _call_via_r2
_call_via_r2: @ 0x0815CCC8
.L0815CCC8:
	bx r2
	.byte 0xC0, 0x46

	thumb_func_start _call_via_r3
_call_via_r3: @ 0x0815CCCC
.L0815CCCC:
	bx r3
	.byte 0xC0, 0x46

	thumb_func_start _call_via_r4
_call_via_r4: @ 0x0815CCD0
.L0815CCD0:
	bx r4
	.byte 0xC0, 0x46

	thumb_func_start _call_via_r5
_call_via_r5: @ 0x0815CCD4
.L0815CCD4:
	bx r5
	.byte 0xC0, 0x46

	thumb_func_start _call_via_r6
_call_via_r6: @ 0x0815CCD8
.L0815CCD8:
	bx r6
	.byte 0xC0, 0x46

	thumb_func_start _call_via_r7
_call_via_r7: @ 0x0815CCDC
	bx r7
	.byte 0xC0, 0x46

	thumb_func_start _call_via_r8
_call_via_r8: @ 0x0815CCE0
	bx r8
	.byte 0xC0, 0x46

	thumb_func_start _call_via_sb
_call_via_sb: @ 0x0815CCE4
	bx sb
	.byte 0xC0, 0x46

	thumb_func_start _call_via_sl
_call_via_sl: @ 0x0815CCE8
	bx sl
	.byte 0xC0, 0x46

	thumb_func_start _call_via_fp
_call_via_fp: @ 0x0815CCEC
	bx fp
	.byte 0xC0, 0x46

	thumb_func_start _call_via_ip
_call_via_ip: @ 0x0815CCF0
	bx ip
	.byte 0xC0, 0x46

	thumb_func_start _call_via_sp
_call_via_sp: @ 0x0815CCF4
	bx sp
	.byte 0xC0, 0x46

	thumb_func_start _call_via_lr
_call_via_lr: @ 0x0815CCF8
	bx lr
	.byte 0xC0, 0x46

	thumb_func_start __divsi3
__divsi3: @ 0x0815CCFC
.L0815CCFC:
	cmp r1, #0
	beq .L0815CD84
	push {r4}
	adds r4, r0, #0
	eors r4, r1
	mov ip, r4
	movs r3, #1
	movs r2, #0
	cmp r1, #0
	bpl .L0815CD12
	rsbs r1, r1, #0
.L0815CD12:
	cmp r0, #0
	bpl .L0815CD18
	rsbs r0, r0, #0
.L0815CD18:
	cmp r0, r1
	blo .L0815CD76
	movs r4, #1
	lsls r4, r4, #0x1c
.L0815CD20:
	cmp r1, r4
	bhs .L0815CD2E
	cmp r1, r0
	bhs .L0815CD2E
	lsls r1, r1, #4
	lsls r3, r3, #4
	b .L0815CD20
.L0815CD2E:
	lsls r4, r4, #3
.L0815CD30:
	cmp r1, r4
	bhs .L0815CD3E
	cmp r1, r0
	bhs .L0815CD3E
	lsls r1, r1, #1
	lsls r3, r3, #1
	b .L0815CD30
.L0815CD3E:
	cmp r0, r1
	blo .L0815CD46
	subs r0, r0, r1
	orrs r2, r3
.L0815CD46:
	lsrs r4, r1, #1
	cmp r0, r4
	blo .L0815CD52
	subs r0, r0, r4
	lsrs r4, r3, #1
	orrs r2, r4
.L0815CD52:
	lsrs r4, r1, #2
	cmp r0, r4
	blo .L0815CD5E
	subs r0, r0, r4
	lsrs r4, r3, #2
	orrs r2, r4
.L0815CD5E:
	lsrs r4, r1, #3
	cmp r0, r4
	blo .L0815CD6A
	subs r0, r0, r4
	lsrs r4, r3, #3
	orrs r2, r4
.L0815CD6A:
	cmp r0, #0
	beq .L0815CD76
	lsrs r3, r3, #4
	beq .L0815CD76
	lsrs r1, r1, #4
	b .L0815CD3E
.L0815CD76:
	adds r0, r2, #0
	mov r4, ip
	cmp r4, #0
	bpl .L0815CD80
	rsbs r0, r0, #0
.L0815CD80:
	pop {r4}
	mov pc, lr
.L0815CD84:
	push {lr}
	bl __div0
	movs r0, #0
	pop {pc}
	.byte 0x00, 0x00

	thumb_func_start __div0
__div0: @ 0x0815CD90
.L0815CD90:
	mov pc, lr
	.byte 0x00, 0x00

	thumb_func_start __modsi3
__modsi3: @ 0x0815CD94
.L0815CD94:
	movs r3, #1
	cmp r1, #0
	beq .L0815CE58
	bpl .L0815CD9E
	rsbs r1, r1, #0
.L0815CD9E:
	push {r4}
	push {r0}
	cmp r0, #0
	bpl .L0815CDA8
	rsbs r0, r0, #0
.L0815CDA8:
	cmp r0, r1
	blo .L0815CE4C
	movs r4, #1
	lsls r4, r4, #0x1c
.L0815CDB0:
	cmp r1, r4
	bhs .L0815CDBE
	cmp r1, r0
	bhs .L0815CDBE
	lsls r1, r1, #4
	lsls r3, r3, #4
	b .L0815CDB0
.L0815CDBE:
	lsls r4, r4, #3
.L0815CDC0:
	cmp r1, r4
	bhs .L0815CDCE
	cmp r1, r0
	bhs .L0815CDCE
	lsls r1, r1, #1
	lsls r3, r3, #1
	b .L0815CDC0
.L0815CDCE:
	movs r2, #0
	cmp r0, r1
	blo .L0815CDD6
	subs r0, r0, r1
.L0815CDD6:
	lsrs r4, r1, #1
	cmp r0, r4
	blo .L0815CDE8
	subs r0, r0, r4
	mov ip, r3
	movs r4, #1
	rors r3, r4
	orrs r2, r3
	mov r3, ip
.L0815CDE8:
	lsrs r4, r1, #2
	cmp r0, r4
	blo .L0815CDFA
	subs r0, r0, r4
	mov ip, r3
	movs r4, #2
	rors r3, r4
	orrs r2, r3
	mov r3, ip
.L0815CDFA:
	lsrs r4, r1, #3
	cmp r0, r4
	blo .L0815CE0C
	subs r0, r0, r4
	mov ip, r3
	movs r4, #3
	rors r3, r4
	orrs r2, r3
	mov r3, ip
.L0815CE0C:
	mov ip, r3
	cmp r0, #0
	beq .L0815CE1A
	lsrs r3, r3, #4
	beq .L0815CE1A
	lsrs r1, r1, #4
	b .L0815CDCE
.L0815CE1A:
	movs r4, #0xe
	lsls r4, r4, #0x1c
	ands r2, r4
	beq .L0815CE4C
	mov r3, ip
	movs r4, #3
	rors r3, r4
	tst r2, r3
	beq .L0815CE30
	lsrs r4, r1, #3
	adds r0, r0, r4
.L0815CE30:
	mov r3, ip
	movs r4, #2
	rors r3, r4
	tst r2, r3
	beq .L0815CE3E
	lsrs r4, r1, #2
	adds r0, r0, r4
.L0815CE3E:
	mov r3, ip
	movs r4, #1
	rors r3, r4
	tst r2, r3
	beq .L0815CE4C
	lsrs r4, r1, #1
	adds r0, r0, r4
.L0815CE4C:
	pop {r4}
	cmp r4, #0
	bpl .L0815CE54
	rsbs r0, r0, #0
.L0815CE54:
	pop {r4}
	mov pc, lr
.L0815CE58:
	push {lr}
	bl __div0
	movs r0, #0
	pop {pc}
	.byte 0x00, 0x00

	thumb_func_start __udivsi3
__udivsi3: @ 0x0815CE64
.L0815CE64:
	cmp r1, #0
	beq .L0815CED2
	movs r3, #1
	movs r2, #0
	push {r4}
	cmp r0, r1
	blo .L0815CECC
	movs r4, #1
	lsls r4, r4, #0x1c
.L0815CE76:
	cmp r1, r4
	bhs .L0815CE84
	cmp r1, r0
	bhs .L0815CE84
	lsls r1, r1, #4
	lsls r3, r3, #4
	b .L0815CE76
.L0815CE84:
	lsls r4, r4, #3
.L0815CE86:
	cmp r1, r4
	bhs .L0815CE94
	cmp r1, r0
	bhs .L0815CE94
	lsls r1, r1, #1
	lsls r3, r3, #1
	b .L0815CE86
.L0815CE94:
	cmp r0, r1
	blo .L0815CE9C
	subs r0, r0, r1
	orrs r2, r3
.L0815CE9C:
	lsrs r4, r1, #1
	cmp r0, r4
	blo .L0815CEA8
	subs r0, r0, r4
	lsrs r4, r3, #1
	orrs r2, r4
.L0815CEA8:
	lsrs r4, r1, #2
	cmp r0, r4
	blo .L0815CEB4
	subs r0, r0, r4
	lsrs r4, r3, #2
	orrs r2, r4
.L0815CEB4:
	lsrs r4, r1, #3
	cmp r0, r4
	blo .L0815CEC0
	subs r0, r0, r4
	lsrs r4, r3, #3
	orrs r2, r4
.L0815CEC0:
	cmp r0, #0
	beq .L0815CECC
	lsrs r3, r3, #4
	beq .L0815CECC
	lsrs r1, r1, #4
	b .L0815CE94
.L0815CECC:
	adds r0, r2, #0
	pop {r4}
	mov pc, lr
.L0815CED2:
	push {lr}
	bl __div0
	movs r0, #0
	pop {pc}

	thumb_func_start __umodsi3
__umodsi3: @ 0x0815CEDC
.L0815CEDC:
	cmp r1, #0
	beq .L0815CF92
	movs r3, #1
	cmp r0, r1
	bhs .L0815CEE8
	mov pc, lr
.L0815CEE8:
	push {r4}
	movs r4, #1
	lsls r4, r4, #0x1c
.L0815CEEE:
	cmp r1, r4
	bhs .L0815CEFC
	cmp r1, r0
	bhs .L0815CEFC
	lsls r1, r1, #4
	lsls r3, r3, #4
	b .L0815CEEE
.L0815CEFC:
	lsls r4, r4, #3
.L0815CEFE:
	cmp r1, r4
	bhs .L0815CF0C
	cmp r1, r0
	bhs .L0815CF0C
	lsls r1, r1, #1
	lsls r3, r3, #1
	b .L0815CEFE
.L0815CF0C:
	movs r2, #0
	cmp r0, r1
	blo .L0815CF14
	subs r0, r0, r1
.L0815CF14:
	lsrs r4, r1, #1
	cmp r0, r4
	blo .L0815CF26
	subs r0, r0, r4
	mov ip, r3
	movs r4, #1
	rors r3, r4
	orrs r2, r3
	mov r3, ip
.L0815CF26:
	lsrs r4, r1, #2
	cmp r0, r4
	blo .L0815CF38
	subs r0, r0, r4
	mov ip, r3
	movs r4, #2
	rors r3, r4
	orrs r2, r3
	mov r3, ip
.L0815CF38:
	lsrs r4, r1, #3
	cmp r0, r4
	blo .L0815CF4A
	subs r0, r0, r4
	mov ip, r3
	movs r4, #3
	rors r3, r4
	orrs r2, r3
	mov r3, ip
.L0815CF4A:
	mov ip, r3
	cmp r0, #0
	beq .L0815CF58
	lsrs r3, r3, #4
	beq .L0815CF58
	lsrs r1, r1, #4
	b .L0815CF0C
.L0815CF58:
	movs r4, #0xe
	lsls r4, r4, #0x1c
	ands r2, r4
	bne .L0815CF64
	pop {r4}
	mov pc, lr
.L0815CF64:
	mov r3, ip
	movs r4, #3
	rors r3, r4
	tst r2, r3
	beq .L0815CF72
	lsrs r4, r1, #3
	adds r0, r0, r4
.L0815CF72:
	mov r3, ip
	movs r4, #2
	rors r3, r4
	tst r2, r3
	beq .L0815CF80
	lsrs r4, r1, #2
	adds r0, r0, r4
.L0815CF80:
	mov r3, ip
	movs r4, #1
	rors r3, r4
	tst r2, r3
	beq .L0815CF8E
	lsrs r4, r1, #1
	adds r0, r0, r4
.L0815CF8E:
	pop {r4}
	mov pc, lr
.L0815CF92:
	push {lr}
	bl __div0
	movs r0, #0
	pop {pc}

	thumb_func_start sub_0815CF9C
sub_0815CF9C: @ 0x0815CF9C
.L0815CF9C:
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r1, r0, #0
	ldr r4, [r1, #0xc]
	ldr r5, [r1, #0x10]
	ldr r7, [r1, #4]
	movs r6, #0
	movs r2, #0
	ldr r0, [r1]
	cmp r0, #1
	bhi .L0815CFB4
	movs r2, #1
.L0815CFB4:
	cmp r2, #0
	beq .L0815CFD4
	ldr r6, .L0815CFC8
	ldr r2, .L0815CFCC
	ldr r3, .L0815CFD0
	adds r0, r4, #0
	adds r1, r5, #0
	orrs r1, r3
	b .L0815D08C
	.byte 0x00, 0x00
.L0815CFC8: .4byte 0x000007FF
.L0815CFCC: .4byte 0x00000000
.L0815CFD0: .4byte 0x00080000
.L0815CFD4:
	movs r2, #0
	cmp r0, #4
	bne .L0815CFDC
	movs r2, #1
.L0815CFDC:
	cmp r2, #0
	bne .L0815D028
	movs r2, #0
	cmp r0, #2
	bne .L0815CFE8
	movs r2, #1
.L0815CFE8:
	cmp r2, #0
	beq .L0815CFF2
	movs r4, #0
	movs r5, #0
	b .L0815D090
.L0815CFF2:
	adds r0, r5, #0
	orrs r0, r4
	cmp r0, #0
	beq .L0815D090
	ldr r2, [r1, #8]
	ldr r0, .L0815D010
	cmp r2, r0
	bge .L0815D022
	subs r2, r0, r2
	cmp r2, #0x38
	ble .L0815D014
	movs r4, #0
	movs r5, #0
	b .L0815D082
	.byte 0x00, 0x00
.L0815D010: .4byte 0xFFFFFC02
.L0815D014:
	adds r1, r5, #0
	adds r0, r4, #0
	bl sub_0815E684
	adds r5, r1, #0
	adds r4, r0, #0
	b .L0815D082
.L0815D022:
	ldr r0, .L0815D030
	cmp r2, r0
	ble .L0815D038
.L0815D028:
	ldr r6, .L0815D034
	movs r4, #0
	movs r5, #0
	b .L0815D090
.L0815D030: .4byte 0x000003FF
.L0815D034: .4byte 0x000007FF
.L0815D038:
	ldr r0, .L0815D060
	adds r6, r2, r0
	movs r0, #0xff
	adds r1, r4, #0
	ands r1, r0
	movs r2, #0
	cmp r1, #0x80
	bne .L0815D064
	cmp r2, #0
	bne .L0815D064
	adds r0, #1
	adds r1, r4, #0
	ands r1, r0
	adds r0, r2, #0
	orrs r0, r1
	cmp r0, #0
	beq .L0815D06C
	movs r0, #0x80
	movs r1, #0
	b .L0815D068
.L0815D060: .4byte 0x000003FF
.L0815D064:
	movs r0, #0x7f
	movs r1, #0
.L0815D068:
	adds r4, r4, r0
	adcs r5, r1
.L0815D06C:
	ldr r0, .L0815D0D0
	cmp r5, r0
	bls .L0815D082
	lsls r3, r5, #0x1f
	lsrs r2, r4, #1
	adds r0, r3, #0
	orrs r0, r2
	lsrs r1, r5, #1
	adds r5, r1, #0
	adds r4, r0, #0
	adds r6, #1
.L0815D082:
	lsls r3, r5, #0x18
	lsrs r2, r4, #8
	adds r0, r3, #0
	orrs r0, r2
	lsrs r1, r5, #8
.L0815D08C:
	adds r5, r1, #0
	adds r4, r0, #0
.L0815D090:
	str r4, [sp]
	ldr r2, .L0815D0D4
	ands r2, r5
	ldr r0, [sp, #4]
	ldr r1, .L0815D0D8
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #4]
	mov r2, sp
	ldr r1, .L0815D0DC
	adds r0, r1, #0
	ands r6, r0
	lsls r1, r6, #4
	ldr r0, .L0815D0E0
	ldrh r3, [r2, #6]
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #6]
	lsls r1, r7, #7
	movs r0, #0x7f
	ldrb r3, [r2, #7]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #7]
	ldr r1, [sp]
	ldr r0, [sp, #4]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	add sp, #8
	pop {r4, r5, r6, r7, pc}
.L0815D0D0: .4byte 0x1FFFFFFF
.L0815D0D4: .4byte 0x000FFFFF
.L0815D0D8: .4byte 0xFFF00000
.L0815D0DC: .4byte 0x000007FF
.L0815D0E0: .4byte 0xFFFF800F

	thumb_func_start sub_0815D0E4
sub_0815D0E4: @ 0x0815D0E4
.L0815D0E4:
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r6, r1, #0
	ldr r1, [r2, #4]
	str r1, [sp]
	ldr r0, [r2]
	str r0, [sp, #4]
	mov r2, sp
	adds r4, r1, #0
	lsls r0, r0, #0xc
	lsrs r5, r0, #0xc
	ldrh r3, [r2, #6]
	lsls r0, r3, #0x11
	lsrs r3, r0, #0x15
	ldrb r2, [r2, #7]
	lsrs r0, r2, #7
	str r0, [r6, #4]
	cmp r3, #0
	bne .L0815D158
	orrs r1, r5
	cmp r1, #0
	bne .L0815D118
	movs r0, #2
	str r0, [r6]
	b .L0815D1AC
.L0815D118:
	ldr r0, .L0815D150
	str r0, [r6, #8]
	lsrs r3, r4, #0x18
	lsls r2, r5, #8
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #8
	adds r5, r1, #0
	adds r4, r0, #0
	movs r0, #3
	str r0, [r6]
	ldr r0, .L0815D154
	cmp r5, r0
	bhi .L0815D188
	adds r7, r0, #0
.L0815D136:
	lsrs r3, r4, #0x1f
	lsls r2, r5, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #1
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [r6, #8]
	subs r0, #1
	str r0, [r6, #8]
	cmp r5, r7
	bls .L0815D136
	b .L0815D188
.L0815D150: .4byte 0xFFFFFC02
.L0815D154: .4byte 0x0FFFFFFF
.L0815D158:
	ldr r0, .L0815D16C
	cmp r3, r0
	bne .L0815D18E
	orrs r1, r5
	cmp r1, #0
	bne .L0815D170
	movs r0, #4
	str r0, [r6]
	b .L0815D1AC
	.byte 0x00, 0x00
.L0815D16C: .4byte 0x000007FF
.L0815D170:
	movs r2, #0x80
	lsls r2, r2, #0xc
	movs r0, #0
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	cmp r1, #0
	beq .L0815D186
	movs r0, #1
	str r0, [r6]
	b .L0815D188
.L0815D186:
	str r1, [r6]
.L0815D188:
	str r4, [r6, #0xc]
	str r5, [r6, #0x10]
	b .L0815D1AC
.L0815D18E:
	ldr r1, .L0815D1B0
	adds r0, r3, r1
	str r0, [r6, #8]
	movs r0, #3
	str r0, [r6]
	lsrs r3, r4, #0x18
	lsls r2, r5, #8
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #8
	ldr r2, .L0815D1B4
	ldr r3, .L0815D1B8
	orrs r1, r3
	str r0, [r6, #0xc]
	str r1, [r6, #0x10]
.L0815D1AC:
	add sp, #8
	pop {r4, r5, r6, r7, pc}
.L0815D1B0: .4byte 0xFFFFFC01
.L0815D1B4: .4byte 0x00000000
.L0815D1B8: .4byte 0x10000000

	thumb_func_start sub_0815D1BC
sub_0815D1BC: @ 0x0815D1BC
.L0815D1BC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r3, r0, #0
	adds r4, r1, #0
	mov sl, r2
	movs r0, #0
	ldr r2, [r3]
	cmp r2, #1
	bhi .L0815D1D8
	movs r0, #1
.L0815D1D8:
	cmp r0, #0
	beq .L0815D1E0
.L0815D1DC:
	adds r0, r3, #0
	b .L0815D418
.L0815D1E0:
	movs r1, #0
	ldr r0, [r4]
	cmp r0, #1
	bhi .L0815D1EA
	movs r1, #1
.L0815D1EA:
	cmp r1, #0
	bne .L0815D262
	movs r1, #0
	cmp r2, #4
	bne .L0815D1F6
	movs r1, #1
.L0815D1F6:
	cmp r1, #0
	beq .L0815D218
	movs r1, #0
	cmp r0, #4
	bne .L0815D202
	movs r1, #1
.L0815D202:
	cmp r1, #0
	beq .L0815D1DC
	ldr r1, [r3, #4]
	ldr r0, [r4, #4]
	cmp r1, r0
	beq .L0815D1DC
	ldr r0, .L0815D214
	b .L0815D418
	.byte 0x00, 0x00
.L0815D214: .4byte 0x030020B8 @ IWRAM+0x20B8
.L0815D218:
	movs r1, #0
	cmp r0, #4
	bne .L0815D220
	movs r1, #1
.L0815D220:
	cmp r1, #0
	bne .L0815D262
	movs r1, #0
	cmp r0, #2
	bne .L0815D22C
	movs r1, #1
.L0815D22C:
	cmp r1, #0
	beq .L0815D254
	movs r0, #0
	cmp r2, #2
	bne .L0815D238
	movs r0, #1
.L0815D238:
	cmp r0, #0
	beq .L0815D1DC
	mov r1, sl
	adds r0, r3, #0
	ldm r0!, {r2, r5, r6}
	stm r1!, {r2, r5, r6}
	ldm r0!, {r2, r5}
	stm r1!, {r2, r5}
	ldr r0, [r3, #4]
	ldr r1, [r4, #4]
	ands r0, r1
	mov r6, sl
	str r0, [r6, #4]
	b .L0815D416
.L0815D254:
	movs r1, #0
	ldr r0, [r3]
	cmp r0, #2
	bne .L0815D25E
	movs r1, #1
.L0815D25E:
	cmp r1, #0
	beq .L0815D266
.L0815D262:
	adds r0, r4, #0
	b .L0815D418
.L0815D266:
	ldr r0, [r3, #8]
	mov sb, r0
	ldr r1, [r4, #8]
	mov r8, r1
	ldr r6, [r3, #0xc]
	ldr r7, [r3, #0x10]
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, sb
	mov r2, r8
	subs r0, r1, r2
	cmp r0, #0
	bge .L0815D286
	rsbs r0, r0, #0
.L0815D286:
	cmp r0, #0x3f
	bgt .L0815D304
	ldr r3, [r3, #4]
	mov ip, r3
	ldr r4, [r4, #4]
	str r4, [sp, #8]
	cmp sb, r8
	ble .L0815D2D0
	mov r3, sb
	mov r4, r8
	subs r3, r3, r4
	mov r8, r3
.L0815D29E:
	movs r5, #1
	rsbs r5, r5, #0
	add r8, r5
	ldr r2, [sp]
	movs r0, #1
	ands r2, r0
	movs r3, #0
	ldr r1, [sp, #4]
	lsls r5, r1, #0x1f
	ldr r0, [sp]
	lsrs r4, r0, #1
	adds r0, r5, #0
	orrs r0, r4
	adds r4, r1, #0
	lsrs r1, r4, #1
	adds r5, r2, #0
	orrs r5, r0
	str r5, [sp]
	adds r4, r3, #0
	orrs r4, r1
	str r4, [sp, #4]
	mov r5, r8
	cmp r5, #0
	bne .L0815D29E
	mov r8, sb
.L0815D2D0:
	cmp r8, sb
	ble .L0815D320
	mov r0, r8
	mov r1, sb
	subs r0, r0, r1
	mov sb, r0
.L0815D2DC:
	movs r2, #1
	rsbs r2, r2, #0
	add sb, r2
	movs r2, #1
	ands r2, r6
	movs r3, #0
	lsls r5, r7, #0x1f
	lsrs r4, r6, #1
	adds r0, r5, #0
	orrs r0, r4
	lsrs r1, r7, #1
	adds r6, r2, #0
	orrs r6, r0
	adds r7, r3, #0
	orrs r7, r1
	mov r3, sb
	cmp r3, #0
	bne .L0815D2DC
	mov sb, r8
	b .L0815D320
.L0815D304:
	cmp sb, r8
	ble .L0815D312
	movs r0, #0
	movs r1, #0
	str r0, [sp]
	str r1, [sp, #4]
	b .L0815D318
.L0815D312:
	mov sb, r8
	movs r6, #0
	movs r7, #0
.L0815D318:
	ldr r3, [r3, #4]
	mov ip, r3
	ldr r4, [r4, #4]
	str r4, [sp, #8]
.L0815D320:
	ldr r1, [sp, #8]
	cmp ip, r1
	beq .L0815D3C8
	mov r2, ip
	cmp r2, #0
	beq .L0815D342
	adds r1, r7, #0
	adds r0, r6, #0
	bl sub_0815E728
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r4, [sp]
	ldr r5, [sp, #4]
	adds r2, r2, r4
	adcs r3, r5
	b .L0815D34E
.L0815D342:
	adds r3, r7, #0
	adds r2, r6, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	subs r2, r2, r0
	sbcs r3, r1
.L0815D34E:
	cmp r3, #0
	blt .L0815D364
	movs r0, #0
	mov r1, sl
	str r0, [r1, #4]
	mov r4, sb
	str r4, [r1, #8]
	mov r5, sl
	str r2, [r5, #0xc]
	str r3, [r5, #0x10]
	b .L0815D37C
.L0815D364:
	movs r0, #1
	mov r6, sl
	str r0, [r6, #4]
	mov r0, sb
	str r0, [r6, #8]
	adds r1, r3, #0
	adds r0, r2, #0
	bl sub_0815E728
	mov r2, sl
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
.L0815D37C:
	mov r4, sl
	ldr r2, [r4, #0xc]
	ldr r3, [r4, #0x10]
	movs r0, #1
	rsbs r0, r0, #0
	asrs r1, r0, #0x1f
.L0815D388:
	adds r2, r2, r0
	adcs r3, r1
	ldr r0, .L0815D3C4
	cmp r3, r0
	bhi .L0815D3E0
	cmp r3, r0
	bne .L0815D39E
	movs r0, #2
	rsbs r0, r0, #0
	cmp r2, r0
	bhi .L0815D3E0
.L0815D39E:
	mov r5, sl
	ldr r0, [r5, #0xc]
	ldr r1, [r5, #0x10]
	lsrs r3, r0, #0x1f
	lsls r2, r1, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r0, #1
	mov r6, sl
	str r0, [r6, #0xc]
	str r1, [r6, #0x10]
	ldr r2, [r6, #8]
	subs r2, #1
	str r2, [r6, #8]
	movs r2, #1
	rsbs r2, r2, #0
	asrs r3, r2, #0x1f
	b .L0815D388
	.byte 0x00, 0x00
.L0815D3C4: .4byte 0x0FFFFFFF
.L0815D3C8:
	mov r0, ip
	mov r1, sl
	str r0, [r1, #4]
	mov r2, sb
	str r2, [r1, #8]
	ldr r3, [sp]
	ldr r4, [sp, #4]
	adds r6, r6, r3
	adcs r7, r4
	mov r4, sl
	str r6, [r4, #0xc]
	str r7, [r4, #0x10]
.L0815D3E0:
	movs r0, #3
	mov r5, sl
	str r0, [r5]
	ldr r1, [r5, #0x10]
	ldr r0, .L0815D424
	cmp r1, r0
	bls .L0815D416
	ldr r4, [r5, #0xc]
	ldr r5, [r5, #0x10]
	movs r2, #1
	adds r0, r4, #0
	ands r0, r2
	movs r1, #0
	lsls r6, r5, #0x1f
	mov r8, r6
	lsrs r6, r4, #1
	mov r2, r8
	orrs r2, r6
	lsrs r3, r5, #1
	orrs r0, r2
	orrs r1, r3
	mov r2, sl
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
	ldr r0, [r2, #8]
	adds r0, #1
	str r0, [r2, #8]
.L0815D416:
	mov r0, sl
.L0815D418:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
.L0815D424: .4byte 0x1FFFFFFF

	thumb_func_start sub_0815D428
sub_0815D428: @ 0x0815D428
.L0815D428:
	push {r4, lr}
	sub sp, #0x4c
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	str r3, [sp, #0x48]
	add r0, sp, #0x3c
	mov r1, sp
	bl sub_0815D0E4
	add r0, sp, #0x44
	add r4, sp, #0x14
	adds r1, r4, #0
	bl sub_0815D0E4
	add r2, sp, #0x28
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815D1BC
	bl sub_0815CF9C
	add sp, #0x4c
	pop {r4, pc}

	thumb_func_start sub_0815D458
sub_0815D458: @ 0x0815D458
	push {r4, lr}
	sub sp, #0x4c
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	str r3, [sp, #0x48]
	add r0, sp, #0x3c
	mov r1, sp
	bl sub_0815D0E4
	add r0, sp, #0x44
	add r4, sp, #0x14
	adds r1, r4, #0
	bl sub_0815D0E4
	ldr r0, [r4, #4]
	movs r1, #1
	eors r0, r1
	str r0, [r4, #4]
	add r2, sp, #0x28
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815D1BC
	bl sub_0815CF9C
	add sp, #0x4c
	pop {r4, pc}

	thumb_func_start sub_0815D490
sub_0815D490: @ 0x0815D490
.L0815D490:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x74
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	str r3, [sp, #0x48]
	add r0, sp, #0x3c
	mov r1, sp
	bl sub_0815D0E4
	add r0, sp, #0x44
	add r4, sp, #0x14
	adds r1, r4, #0
	bl sub_0815D0E4
	mov r8, sp
	add r0, sp, #0x28
	mov sl, r0
	movs r0, #0
	ldr r1, [sp]
	cmp r1, #1
	bhi .L0815D4C6
	movs r0, #1
.L0815D4C6:
	cmp r0, #0
	bne .L0815D52A
	movs r2, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi .L0815D4D4
	movs r2, #1
.L0815D4D4:
	cmp r2, #0
	beq .L0815D4DC
	ldr r0, [sp, #4]
	b .L0815D54C
.L0815D4DC:
	movs r2, #0
	cmp r1, #4
	bne .L0815D4E4
	movs r2, #1
.L0815D4E4:
	cmp r2, #0
	beq .L0815D4F6
	movs r1, #0
	cmp r0, #2
	bne .L0815D4F0
	movs r1, #1
.L0815D4F0:
	cmp r1, #0
	bne .L0815D50E
	b .L0815D52A
.L0815D4F6:
	movs r2, #0
	cmp r0, #4
	bne .L0815D4FE
	movs r2, #1
.L0815D4FE:
	cmp r2, #0
	beq .L0815D51E
	movs r0, #0
	cmp r1, #2
	bne .L0815D50A
	movs r0, #1
.L0815D50A:
	cmp r0, #0
	beq .L0815D518
.L0815D50E:
	ldr r0, .L0815D514
	b .L0815D716
	.byte 0x00, 0x00
.L0815D514: .4byte 0x030020B8 @ IWRAM+0x20B8
.L0815D518:
	mov r1, r8
	ldr r0, [r1, #4]
	b .L0815D54C
.L0815D51E:
	movs r2, #0
	cmp r1, #2
	bne .L0815D526
	movs r2, #1
.L0815D526:
	cmp r2, #0
	beq .L0815D53C
.L0815D52A:
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x18]
	eors r0, r1
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	str r1, [sp, #4]
	mov r0, sp
	b .L0815D716
.L0815D53C:
	movs r1, #0
	cmp r0, #2
	bne .L0815D544
	movs r1, #1
.L0815D544:
	cmp r1, #0
	beq .L0815D55C
	mov r2, r8
	ldr r0, [r2, #4]
.L0815D54C:
	ldr r1, [sp, #0x18]
	eors r0, r1
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	str r1, [sp, #0x18]
	adds r0, r4, #0
	b .L0815D716
.L0815D55C:
	mov r4, r8
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	adds r6, r0, #0
	movs r7, #0
	str r1, [sp, #0x4c]
	movs r5, #0
	str r5, [sp, #0x50]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	adds r4, r0, #0
	str r1, [sp, #0x54]
	movs r0, #0
	str r0, [sp, #0x58]
	adds r1, r5, #0
	adds r0, r4, #0
	adds r3, r7, #0
	adds r2, r6, #0
	bl sub_0815E6B8
	str r0, [sp, #0x5c]
	str r1, [sp, #0x60]
	ldr r0, [sp, #0x54]
	ldr r1, [sp, #0x58]
	adds r3, r7, #0
	adds r2, r6, #0
	bl sub_0815E6B8
	adds r7, r1, #0
	adds r6, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x4c]
	ldr r3, [sp, #0x50]
	bl sub_0815E6B8
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x54]
	ldr r1, [sp, #0x58]
	ldr r2, [sp, #0x4c]
	ldr r3, [sp, #0x50]
	bl sub_0815E6B8
	str r0, [sp, #0x64]
	str r1, [sp, #0x68]
	movs r1, #0
	movs r2, #0
	str r1, [sp, #0x6c]
	str r2, [sp, #0x70]
	adds r3, r7, #0
	adds r2, r6, #0
	adds r2, r2, r4
	adcs r3, r5
	cmp r7, r3
	bhi .L0815D5D4
	cmp r7, r3
	bne .L0815D5DC
	cmp r6, r2
	bls .L0815D5DC
.L0815D5D4:
	ldr r5, .L0815D72C
	ldr r4, .L0815D728
	str r4, [sp, #0x6c]
	str r5, [sp, #0x70]
.L0815D5DC:
	adds r1, r2, #0
	movs r6, #0
	adds r7, r1, #0
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x60]
	adds r6, r6, r0
	adcs r7, r1
	cmp r1, r7
	bhi .L0815D5F8
	ldr r1, [sp, #0x60]
	cmp r1, r7
	bne .L0815D608
	cmp r0, r6
	bls .L0815D608
.L0815D5F8:
	movs r0, #1
	movs r1, #0
	ldr r4, [sp, #0x6c]
	ldr r5, [sp, #0x70]
	adds r4, r4, r0
	adcs r5, r1
	str r4, [sp, #0x6c]
	str r5, [sp, #0x70]
.L0815D608:
	adds r0, r3, #0
	adds r2, r0, #0
	movs r3, #0
	adds r5, r3, #0
	adds r4, r2, #0
	ldr r0, [sp, #0x64]
	ldr r1, [sp, #0x68]
	adds r4, r4, r0
	adcs r5, r1
	ldr r1, [sp, #0x6c]
	ldr r2, [sp, #0x70]
	adds r4, r4, r1
	adcs r5, r2
	mov r0, r8
	ldr r2, [r0, #8]
	ldr r0, [sp, #0x1c]
	adds r2, r2, r0
	str r2, [sp, #0x30]
	mov r0, r8
	ldr r1, [r0, #4]
	ldr r0, [sp, #0x18]
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	str r0, [sp, #0x2c]
	adds r2, #4
	str r2, [sp, #0x30]
	ldr r0, .L0815D730
	cmp r5, r0
	bls .L0815D68A
	movs r1, #1
	mov sb, r1
	mov r8, r0
	mov ip, r2
.L0815D64E:
	movs r2, #1
	add ip, r2
	mov r0, sb
	ands r0, r4
	cmp r0, #0
	beq .L0815D674
	lsls r3, r7, #0x1f
	lsrs r2, r6, #1
	adds r0, r3, #0
	orrs r0, r2
	lsrs r1, r7, #1
	adds r7, r1, #0
	adds r6, r0, #0
	adds r0, r6, #0
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r1, r7
	adds r7, r1, #0
	adds r6, r0, #0
.L0815D674:
	lsls r3, r5, #0x1f
	lsrs r2, r4, #1
	adds r0, r3, #0
	orrs r0, r2
	lsrs r1, r5, #1
	adds r5, r1, #0
	adds r4, r0, #0
	cmp r5, r8
	bhi .L0815D64E
	mov r0, ip
	str r0, [sp, #0x30]
.L0815D68A:
	ldr r0, .L0815D734
	cmp r5, r0
	bhi .L0815D6DC
	movs r1, #0x80
	lsls r1, r1, #0x18
	mov sb, r1
	mov r8, r0
	ldr r2, [sp, #0x30]
	mov ip, r2
.L0815D69C:
	movs r0, #1
	rsbs r0, r0, #0
	add ip, r0
	lsrs r3, r4, #0x1f
	lsls r2, r5, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #1
	adds r5, r1, #0
	adds r4, r0, #0
	movs r0, #0
	mov r1, sb
	ands r1, r7
	orrs r0, r1
	cmp r0, #0
	beq .L0815D6C6
	movs r0, #1
	orrs r0, r4
	adds r1, r5, #0
	adds r5, r1, #0
	adds r4, r0, #0
.L0815D6C6:
	lsrs r3, r6, #0x1f
	lsls r2, r7, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r6, #1
	adds r7, r1, #0
	adds r6, r0, #0
	cmp r5, r8
	bls .L0815D69C
	mov r1, ip
	str r1, [sp, #0x30]
.L0815D6DC:
	movs r0, #0xff
	adds r1, r4, #0
	ands r1, r0
	movs r2, #0
	cmp r1, #0x80
	bne .L0815D70A
	cmp r2, #0
	bne .L0815D70A
	adds r0, #1
	adds r1, r4, #0
	ands r1, r0
	adds r0, r2, #0
	orrs r0, r1
	cmp r0, #0
	bne .L0815D702
	adds r0, r7, #0
	orrs r0, r6
	cmp r0, #0
	beq .L0815D70A
.L0815D702:
	movs r0, #0x80
	movs r1, #0
	adds r4, r4, r0
	adcs r5, r1
.L0815D70A:
	str r4, [sp, #0x34]
	str r5, [sp, #0x38]
	movs r0, #3
	mov r2, sl
	str r0, [r2]
	add r0, sp, #0x28
.L0815D716:
	bl sub_0815CF9C
	add sp, #0x74
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
.L0815D728: .4byte 0x00000000
.L0815D72C: .4byte 0x00000001
.L0815D730: .4byte 0x1FFFFFFF
.L0815D734: .4byte 0x0FFFFFFF

	thumb_func_start sub_0815D738
sub_0815D738: @ 0x0815D738
	push {r4, r5, r6, r7, lr}
	sub sp, #0x48
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl sub_0815D0E4
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl sub_0815D0E4
	mov ip, sp
	movs r0, #0
	ldr r3, [sp]
	cmp r3, #1
	bhi .L0815D762
	movs r0, #1
.L0815D762:
	cmp r0, #0
	beq .L0815D76A
	mov r1, sp
	b .L0815D8AC
.L0815D76A:
	movs r0, #0
	ldr r2, [sp, #0x14]
	adds r5, r2, #0
	cmp r2, #1
	bhi .L0815D776
	movs r0, #1
.L0815D776:
	cmp r0, #0
	beq .L0815D77E
	adds r1, r4, #0
	b .L0815D8AC
.L0815D77E:
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x18]
	eors r0, r1
	str r0, [sp, #4]
	movs r0, #0
	cmp r3, #4
	bne .L0815D78E
	movs r0, #1
.L0815D78E:
	cmp r0, #0
	bne .L0815D79E
	movs r4, #0
	cmp r3, #2
	bne .L0815D79A
	movs r4, #1
.L0815D79A:
	cmp r4, #0
	beq .L0815D7B0
.L0815D79E:
	mov r1, ip
	ldr r0, [r1]
	cmp r0, r5
	beq .L0815D7A8
	b .L0815D8AC
.L0815D7A8:
	ldr r1, .L0815D7AC
	b .L0815D8AC
.L0815D7AC: .4byte 0x030020B8 @ IWRAM+0x20B8
.L0815D7B0:
	movs r0, #0
	cmp r2, #4
	bne .L0815D7B8
	movs r0, #1
.L0815D7B8:
	cmp r0, #0
	beq .L0815D7CA
	movs r0, #0
	movs r1, #0
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	str r4, [sp, #8]
	mov r1, sp
	b .L0815D8AC
.L0815D7CA:
	movs r0, #0
	cmp r2, #2
	bne .L0815D7D2
	movs r0, #1
.L0815D7D2:
	cmp r0, #0
	beq .L0815D7DE
	movs r0, #4
	mov r2, ip
	str r0, [r2]
	b .L0815D8AA
.L0815D7DE:
	mov r3, ip
	ldr r1, [r3, #8]
	ldr r0, [sp, #0x1c]
	subs r6, r1, r0
	str r6, [r3, #8]
	ldr r4, [r3, #0xc]
	ldr r5, [r3, #0x10]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	str r0, [sp, #0x38]
	str r1, [sp, #0x3c]
	cmp r1, r5
	bhi .L0815D802
	ldr r1, [sp, #0x3c]
	cmp r1, r5
	bne .L0815D816
	cmp r0, r4
	bls .L0815D816
.L0815D802:
	lsrs r3, r4, #0x1f
	lsls r2, r5, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #1
	adds r5, r1, #0
	adds r4, r0, #0
	subs r0, r6, #1
	mov r2, ip
	str r0, [r2, #8]
.L0815D816:
	ldr r7, .L0815D8BC
	ldr r6, .L0815D8B8
	movs r0, #0
	movs r1, #0
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
.L0815D822:
	ldr r1, [sp, #0x3c]
	cmp r1, r5
	bhi .L0815D846
	cmp r1, r5
	bne .L0815D832
	ldr r2, [sp, #0x38]
	cmp r2, r4
	bhi .L0815D846
.L0815D832:
	ldr r0, [sp, #0x40]
	orrs r0, r6
	ldr r1, [sp, #0x44]
	orrs r1, r7
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x3c]
	subs r4, r4, r0
	sbcs r5, r1
.L0815D846:
	lsls r3, r7, #0x1f
	lsrs r2, r6, #1
	adds r0, r3, #0
	orrs r0, r2
	lsrs r1, r7, #1
	adds r7, r1, #0
	adds r6, r0, #0
	lsrs r3, r4, #0x1f
	lsls r2, r5, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r4, #1
	adds r5, r1, #0
	adds r4, r0, #0
	adds r0, r7, #0
	orrs r0, r6
	cmp r0, #0
	bne .L0815D822
	movs r0, #0xff
	ldr r1, [sp, #0x40]
	ands r1, r0
	movs r2, #0
	cmp r1, #0x80
	bne .L0815D8A0
	cmp r2, #0
	bne .L0815D8A0
	adds r0, #1
	ldr r1, [sp, #0x40]
	ands r1, r0
	adds r0, r2, #0
	orrs r0, r1
	cmp r0, #0
	bne .L0815D890
	adds r0, r5, #0
	orrs r0, r4
	cmp r0, #0
	beq .L0815D8A0
.L0815D890:
	movs r0, #0x80
	movs r1, #0
	ldr r2, [sp, #0x40]
	ldr r3, [sp, #0x44]
	adds r2, r2, r0
	adcs r3, r1
	str r2, [sp, #0x40]
	str r3, [sp, #0x44]
.L0815D8A0:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	mov r2, ip
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
.L0815D8AA:
	mov r1, ip
.L0815D8AC:
	adds r0, r1, #0
	bl sub_0815CF9C
	add sp, #0x48
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
.L0815D8B8: .4byte 0x00000000
.L0815D8BC: .4byte 0x10000000

	thumb_func_start sub_0815D8C0
sub_0815D8C0: @ 0x0815D8C0
.L0815D8C0:
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0
	ldr r1, [r5]
	cmp r1, #1
	bhi .L0815D8D0
	movs r0, #1
.L0815D8D0:
	cmp r0, #0
	bne .L0815D8E2
	movs r0, #0
	ldr r2, [r6]
	cmp r2, #1
	bhi .L0815D8DE
	movs r0, #1
.L0815D8DE:
	cmp r0, #0
	beq .L0815D8E6
.L0815D8E2:
	movs r0, #1
	b .L0815D9BC
.L0815D8E6:
	movs r0, #0
	cmp r1, #4
	bne .L0815D8EE
	movs r0, #1
.L0815D8EE:
	cmp r0, #0
	beq .L0815D906
	movs r0, #0
	cmp r2, #4
	bne .L0815D8FA
	movs r0, #1
.L0815D8FA:
	cmp r0, #0
	beq .L0815D906
	ldr r0, [r6, #4]
	ldr r1, [r5, #4]
	subs r0, r0, r1
	b .L0815D9BC
.L0815D906:
	movs r1, #0
	ldr r0, [r5]
	cmp r0, #4
	bne .L0815D910
	movs r1, #1
.L0815D910:
	cmp r1, #0
	bne .L0815D95E
	movs r1, #0
	cmp r2, #4
	bne .L0815D91C
	movs r1, #1
.L0815D91C:
	cmp r1, #0
	beq .L0815D92E
.L0815D920:
	ldr r0, [r6, #4]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq .L0815D968
	movs r1, #1
	b .L0815D968
.L0815D92E:
	movs r1, #0
	cmp r0, #2
	bne .L0815D936
	movs r1, #1
.L0815D936:
	cmp r1, #0
	beq .L0815D946
	movs r1, #0
	cmp r2, #2
	bne .L0815D942
	movs r1, #1
.L0815D942:
	cmp r1, #0
	bne .L0815D9BA
.L0815D946:
	movs r1, #0
	cmp r0, #2
	bne .L0815D94E
	movs r1, #1
.L0815D94E:
	cmp r1, #0
	bne .L0815D920
	movs r0, #0
	cmp r2, #2
	bne .L0815D95A
	movs r0, #1
.L0815D95A:
	cmp r0, #0
	beq .L0815D96C
.L0815D95E:
	ldr r0, [r5, #4]
	movs r1, #1
	cmp r0, #0
	beq .L0815D968
	subs r1, #2
.L0815D968:
	adds r0, r1, #0
	b .L0815D9BC
.L0815D96C:
	ldr r0, [r6, #4]
	ldr r4, [r5, #4]
	cmp r4, r0
	beq .L0815D97E
.L0815D974:
	movs r0, #1
	cmp r4, #0
	beq .L0815D9BC
	subs r0, #2
	b .L0815D9BC
.L0815D97E:
	ldr r1, [r5, #8]
	ldr r0, [r6, #8]
	cmp r1, r0
	bgt .L0815D974
	cmp r1, r0
	bge .L0815D996
.L0815D98A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, #0
	beq .L0815D9BC
	movs r0, #1
	b .L0815D9BC
.L0815D996:
	ldr r3, [r5, #0x10]
	ldr r2, [r6, #0x10]
	cmp r3, r2
	bhi .L0815D974
	cmp r3, r2
	bne .L0815D9AA
	ldr r1, [r5, #0xc]
	ldr r0, [r6, #0xc]
	cmp r1, r0
	bhi .L0815D974
.L0815D9AA:
	cmp r2, r3
	bhi .L0815D98A
	cmp r2, r3
	bne .L0815D9BA
	ldr r1, [r6, #0xc]
	ldr r0, [r5, #0xc]
	cmp r1, r0
	bhi .L0815D98A
.L0815D9BA:
	movs r0, #0
.L0815D9BC:
	pop {r4, r5, r6, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815D9C0
sub_0815D9C0: @ 0x0815D9C0
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl sub_0815D0E4
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl sub_0815D0E4
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815D8C0
	add sp, #0x38
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815D9EC
sub_0815D9EC: @ 0x0815D9EC
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl sub_0815D0E4
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl sub_0815D0E4
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815DA14
	movs r1, #1
.L0815DA14:
	cmp r1, #0
	bne .L0815DA26
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi .L0815DA22
	movs r1, #1
.L0815DA22:
	cmp r1, #0
	beq .L0815DA2A
.L0815DA26:
	movs r0, #1
	b .L0815DA32
.L0815DA2A:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815D8C0
.L0815DA32:
	add sp, #0x38
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815DA38
sub_0815DA38: @ 0x0815DA38
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl sub_0815D0E4
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl sub_0815D0E4
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815DA60
	movs r1, #1
.L0815DA60:
	cmp r1, #0
	bne .L0815DA72
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi .L0815DA6E
	movs r1, #1
.L0815DA6E:
	cmp r1, #0
	beq .L0815DA76
.L0815DA72:
	movs r0, #1
	b .L0815DA7E
.L0815DA76:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815D8C0
.L0815DA7E:
	add sp, #0x38
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815DA84
sub_0815DA84: @ 0x0815DA84
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl sub_0815D0E4
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl sub_0815D0E4
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815DAAC
	movs r1, #1
.L0815DAAC:
	cmp r1, #0
	bne .L0815DABE
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi .L0815DABA
	movs r1, #1
.L0815DABA:
	cmp r1, #0
	beq .L0815DAC4
.L0815DABE:
	movs r0, #1
	rsbs r0, r0, #0
	b .L0815DACC
.L0815DAC4:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815D8C0
.L0815DACC:
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start sub_0815DAD0
sub_0815DAD0: @ 0x0815DAD0
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl sub_0815D0E4
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl sub_0815D0E4
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815DAF8
	movs r1, #1
.L0815DAF8:
	cmp r1, #0
	bne .L0815DB0A
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi .L0815DB06
	movs r1, #1
.L0815DB06:
	cmp r1, #0
	beq .L0815DB10
.L0815DB0A:
	movs r0, #1
	rsbs r0, r0, #0
	b .L0815DB18
.L0815DB10:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815D8C0
.L0815DB18:
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start sub_0815DB1C
sub_0815DB1C: @ 0x0815DB1C
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl sub_0815D0E4
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl sub_0815D0E4
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815DB44
	movs r1, #1
.L0815DB44:
	cmp r1, #0
	bne .L0815DB56
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi .L0815DB52
	movs r1, #1
.L0815DB52:
	cmp r1, #0
	beq .L0815DB5A
.L0815DB56:
	movs r0, #1
	b .L0815DB62
.L0815DB5A:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815D8C0
.L0815DB62:
	add sp, #0x38
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815DB68
sub_0815DB68: @ 0x0815DB68
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl sub_0815D0E4
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl sub_0815D0E4
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815DB90
	movs r1, #1
.L0815DB90:
	cmp r1, #0
	bne .L0815DBA2
	movs r1, #0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bhi .L0815DB9E
	movs r1, #1
.L0815DB9E:
	cmp r1, #0
	beq .L0815DBA6
.L0815DBA2:
	movs r0, #1
	b .L0815DBAE
.L0815DBA6:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815D8C0
.L0815DBAE:
	add sp, #0x38
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815DBB4
sub_0815DBB4: @ 0x0815DBB4
.L0815DBB4:
	push {r4, r5, lr}
	sub sp, #0x14
	adds r2, r0, #0
	movs r0, #3
	str r0, [sp]
	lsrs r1, r2, #0x1f
	str r1, [sp, #4]
	cmp r2, #0
	bne .L0815DBCC
	movs r0, #2
	str r0, [sp]
	b .L0815DC22
.L0815DBCC:
	movs r0, #0x3c
	str r0, [sp, #8]
	cmp r1, #0
	beq .L0815DBF2
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r2, r0
	bne .L0815DBEC
	ldr r1, .L0815DBE8
	ldr r0, .L0815DBE4
	b .L0815DC28
	.byte 0x00, 0x00
.L0815DBE4: .4byte 0xC1E00000
.L0815DBE8: .4byte 0x00000000
.L0815DBEC:
	rsbs r0, r2, #0
	asrs r1, r0, #0x1f
	b .L0815DBF6
.L0815DBF2:
	adds r0, r2, #0
	asrs r1, r2, #0x1f
.L0815DBF6:
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x10]
	ldr r1, .L0815DC2C
	cmp r0, r1
	bhi .L0815DC22
	adds r5, r1, #0
	ldr r4, [sp, #8]
.L0815DC06:
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	lsrs r3, r0, #0x1f
	lsls r2, r1, #1
	adds r1, r3, #0
	orrs r1, r2
	lsls r0, r0, #1
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	subs r4, #1
	ldr r0, [sp, #0x10]
	cmp r0, r5
	bls .L0815DC06
	str r4, [sp, #8]
.L0815DC22:
	mov r0, sp
	bl sub_0815CF9C
.L0815DC28:
	add sp, #0x14
	pop {r4, r5, pc}
.L0815DC2C: .4byte 0x0FFFFFFF

	thumb_func_start sub_0815DC30
sub_0815DC30: @ 0x0815DC30
	push {lr}
	sub sp, #0x1c
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r0, sp, #0x14
	mov r1, sp
	bl sub_0815D0E4
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #2
	bne .L0815DC4A
	movs r1, #1
.L0815DC4A:
	cmp r1, #0
	bne .L0815DC7E
	movs r1, #0
	cmp r0, #1
	bhi .L0815DC56
	movs r1, #1
.L0815DC56:
	cmp r1, #0
	bne .L0815DC7E
	movs r1, #0
	cmp r0, #4
	bne .L0815DC62
	movs r1, #1
.L0815DC62:
	cmp r1, #0
	beq .L0815DC78
.L0815DC66:
	ldr r0, [sp, #4]
	ldr r1, .L0815DC74
	cmp r0, #0
	beq .L0815DC9C
	adds r1, #1
	b .L0815DC9C
	.byte 0x00, 0x00
.L0815DC74: .4byte 0x7FFFFFFF
.L0815DC78:
	ldr r0, [sp, #8]
	cmp r0, #0
	bge .L0815DC82
.L0815DC7E:
	movs r0, #0
	b .L0815DC9E
.L0815DC82:
	cmp r0, #0x1e
	bgt .L0815DC66
	movs r2, #0x3c
	subs r2, r2, r0
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	bl sub_0815E684
	adds r1, r0, #0
	ldr r0, [sp, #4]
	cmp r0, #0
	beq .L0815DC9C
	rsbs r1, r1, #0
.L0815DC9C:
	adds r0, r1, #0
.L0815DC9E:
	add sp, #0x1c
	pop {pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815DCA4
sub_0815DCA4: @ 0x0815DCA4
	push {lr}
	sub sp, #0x1c
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r0, sp, #0x14
	mov r1, sp
	bl sub_0815D0E4
	movs r1, #0
	ldr r0, [sp, #4]
	cmp r0, #0
	bne .L0815DCBE
	movs r1, #1
.L0815DCBE:
	str r1, [sp, #4]
	mov r0, sp
	bl sub_0815CF9C
	add sp, #0x1c
	pop {pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815DCCC
sub_0815DCCC: @ 0x0815DCCC
.L0815DCCC:
	sub sp, #4
	push {r4, lr}
	sub sp, #0x14
	str r3, [sp, #0x1c]
	ldr r3, [sp, #0x1c]
	ldr r4, [sp, #0x20]
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	str r4, [sp, #0x10]
	mov r0, sp
	bl sub_0815CF9C
	add sp, #0x14
	pop {r4}
	pop {r3}
	add sp, #4
	bx r3
	.byte 0x00, 0x00

	thumb_func_start sub_0815DCF4
sub_0815DCF4: @ 0x0815DCF4
.L0815DCF4:
	push {r4, r5, lr}
	sub sp, #0x1c
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r0, sp, #0x14
	mov r1, sp
	bl sub_0815D0E4
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	lsls r5, r3, #2
	lsrs r4, r2, #0x1e
	adds r0, r5, #0
	orrs r0, r4
	adds r5, r0, #0
	ldr r4, .L0815DD34
	adds r0, r2, #0
	ands r0, r4
	movs r1, #0
	orrs r0, r1
	cmp r0, #0
	beq .L0815DD24
	movs r0, #1
	orrs r5, r0
.L0815DD24:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	adds r3, r5, #0
	bl sub_0815E640
	add sp, #0x1c
	pop {r4, r5, pc}
.L0815DD34: .4byte 0x3FFFFFFF

	thumb_func_start sub_0815DD38
sub_0815DD38: @ 0x0815DD38
.L0815DD38:
	push {r4, r5, r6, lr}
	ldr r2, [r0, #0xc]
	ldr r6, [r0, #4]
	movs r5, #0
	movs r1, #0
	ldr r3, [r0]
	cmp r3, #1
	bhi .L0815DD4A
	movs r1, #1
.L0815DD4A:
	cmp r1, #0
	beq .L0815DD58
	movs r5, #0xff
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r2, r0
	b .L0815DDBE
.L0815DD58:
	movs r1, #0
	cmp r3, #4
	bne .L0815DD60
	movs r1, #1
.L0815DD60:
	cmp r1, #0
	bne .L0815DD94
	movs r1, #0
	cmp r3, #2
	bne .L0815DD6C
	movs r1, #1
.L0815DD6C:
	cmp r1, #0
	beq .L0815DD74
	movs r2, #0
	b .L0815DDBE
.L0815DD74:
	cmp r2, #0
	beq .L0815DDBE
	ldr r0, [r0, #8]
	movs r3, #0x7e
	rsbs r3, r3, #0
	cmp r0, r3
	bge .L0815DD90
	subs r0, r3, r0
	cmp r0, #0x19
	ble .L0815DD8C
	movs r2, #0
	b .L0815DDBC
.L0815DD8C:
	lsrs r2, r0
	b .L0815DDBC
.L0815DD90:
	cmp r0, #0x7f
	ble .L0815DD9A
.L0815DD94:
	movs r5, #0xff
	movs r2, #0
	b .L0815DDBE
.L0815DD9A:
	adds r5, r0, #0
	adds r5, #0x7f
	movs r0, #0x7f
	ands r0, r2
	cmp r0, #0x40
	bne .L0815DDB2
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq .L0815DDB4
	adds r2, #0x40
	b .L0815DDB4
.L0815DDB2:
	adds r2, #0x3f
.L0815DDB4:
	cmp r2, #0
	bge .L0815DDBC
	lsrs r2, r2, #1
	adds r5, #1
.L0815DDBC:
	lsrs r2, r2, #7
.L0815DDBE:
	ldr r0, .L0815DDE0
	ands r2, r0
	ldr r0, .L0815DDE4
	ands r4, r0
	orrs r4, r2
	movs r0, #0xff
	ands r5, r0
	lsls r1, r5, #0x17
	ldr r0, .L0815DDE8
	ands r4, r0
	orrs r4, r1
	lsls r1, r6, #0x1f
	ldr r0, .L0815DDEC
	ands r4, r0
	orrs r4, r1
	adds r0, r4, #0
	pop {r4, r5, r6, pc}
.L0815DDE0: .4byte 0x007FFFFF
.L0815DDE4: .4byte 0xFF800000
.L0815DDE8: .4byte 0x807FFFFF
.L0815DDEC: .4byte 0x7FFFFFFF

	thumb_func_start sub_0815DDF0
sub_0815DDF0: @ 0x0815DDF0
.L0815DDF0:
	push {r4, lr}
	adds r3, r1, #0
	ldr r0, [r0]
	lsls r1, r0, #9
	lsrs r2, r1, #9
	lsls r1, r0, #1
	lsrs r1, r1, #0x18
	lsrs r0, r0, #0x1f
	str r0, [r3, #4]
	cmp r1, #0
	bne .L0815DE34
	cmp r2, #0
	bne .L0815DE10
	movs r0, #2
	str r0, [r3]
	b .L0815DE68
.L0815DE10:
	adds r4, r1, #0
	subs r4, #0x7e
	str r4, [r3, #8]
	lsls r2, r2, #7
	movs r0, #3
	str r0, [r3]
	ldr r1, .L0815DE30
	cmp r2, r1
	bhi .L0815DE50
	adds r0, r4, #0
.L0815DE24:
	lsls r2, r2, #1
	subs r0, #1
	cmp r2, r1
	bls .L0815DE24
	str r0, [r3, #8]
	b .L0815DE50
.L0815DE30: .4byte 0x3FFFFFFF
.L0815DE34:
	cmp r1, #0xff
	bne .L0815DE54
	cmp r2, #0
	bne .L0815DE42
	movs r0, #4
	str r0, [r3]
	b .L0815DE68
.L0815DE42:
	movs r0, #0x80
	lsls r0, r0, #0xd
	ands r0, r2
	cmp r0, #0
	beq .L0815DE4E
	movs r0, #1
.L0815DE4E:
	str r0, [r3]
.L0815DE50:
	str r2, [r3, #0xc]
	b .L0815DE68
.L0815DE54:
	adds r0, r1, #0
	subs r0, #0x7f
	str r0, [r3, #8]
	movs r0, #3
	str r0, [r3]
	lsls r0, r2, #7
	movs r1, #0x80
	lsls r1, r1, #0x17
	orrs r0, r1
	str r0, [r3, #0xc]
.L0815DE68:
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815DE6C
sub_0815DE6C: @ 0x0815DE6C
.L0815DE6C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	movs r0, #0
	ldr r2, [r6]
	cmp r2, #1
	bhi .L0815DE82
	movs r0, #1
.L0815DE82:
	cmp r0, #0
	beq .L0815DE8A
.L0815DE86:
	adds r0, r6, #0
	b .L0815DFE0
.L0815DE8A:
	movs r1, #0
	ldr r0, [r7]
	cmp r0, #1
	bhi .L0815DE94
	movs r1, #1
.L0815DE94:
	cmp r1, #0
	bne .L0815DF08
	movs r1, #0
	cmp r2, #4
	bne .L0815DEA0
	movs r1, #1
.L0815DEA0:
	cmp r1, #0
	beq .L0815DEC0
	movs r1, #0
	cmp r0, #4
	bne .L0815DEAC
	movs r1, #1
.L0815DEAC:
	cmp r1, #0
	beq .L0815DE86
	ldr r1, [r6, #4]
	ldr r0, [r7, #4]
	cmp r1, r0
	beq .L0815DE86
	ldr r0, .L0815DEBC
	b .L0815DFE0
.L0815DEBC: .4byte 0x030020D0 @ IWRAM+0x20D0
.L0815DEC0:
	movs r1, #0
	cmp r0, #4
	bne .L0815DEC8
	movs r1, #1
.L0815DEC8:
	cmp r1, #0
	bne .L0815DF08
	movs r1, #0
	cmp r0, #2
	bne .L0815DED4
	movs r1, #1
.L0815DED4:
	cmp r1, #0
	beq .L0815DEFA
	movs r0, #0
	cmp r2, #2
	bne .L0815DEE0
	movs r0, #1
.L0815DEE0:
	cmp r0, #0
	beq .L0815DE86
	adds r1, r5, #0
	adds r0, r6, #0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r6, #4]
	ldr r1, [r7, #4]
	ands r0, r1
	str r0, [r5, #4]
	b .L0815DFDE
.L0815DEFA:
	movs r1, #0
	ldr r0, [r6]
	cmp r0, #2
	bne .L0815DF04
	movs r1, #1
.L0815DF04:
	cmp r1, #0
	beq .L0815DF0C
.L0815DF08:
	adds r0, r7, #0
	b .L0815DFE0
.L0815DF0C:
	ldr r1, [r6, #8]
	ldr r3, [r7, #8]
	ldr r2, [r6, #0xc]
	ldr r4, [r7, #0xc]
	subs r0, r1, r3
	cmp r0, #0
	bge .L0815DF1C
	rsbs r0, r0, #0
.L0815DF1C:
	cmp r0, #0x1f
	bgt .L0815DF60
	ldr r6, [r6, #4]
	ldr r7, [r7, #4]
	mov r8, r7
	cmp r1, r3
	ble .L0815DF42
	movs r7, #1
	mov ip, r7
	subs r3, r1, r3
.L0815DF30:
	subs r3, #1
	adds r0, r4, #0
	mov r7, ip
	ands r0, r7
	lsrs r4, r4, #1
	orrs r4, r0
	cmp r3, #0
	bne .L0815DF30
	adds r3, r1, #0
.L0815DF42:
	cmp r3, r1
	ble .L0815DF72
	movs r0, #1
	mov ip, r0
	subs r1, r3, r1
.L0815DF4C:
	subs r1, #1
	adds r0, r2, #0
	mov r7, ip
	ands r0, r7
	lsrs r2, r2, #1
	orrs r2, r0
	cmp r1, #0
	bne .L0815DF4C
	adds r1, r3, #0
	b .L0815DF72
.L0815DF60:
	cmp r1, r3
	ble .L0815DF68
	movs r4, #0
	b .L0815DF6C
.L0815DF68:
	adds r1, r3, #0
	movs r2, #0
.L0815DF6C:
	ldr r6, [r6, #4]
	ldr r7, [r7, #4]
	mov r8, r7
.L0815DF72:
	cmp r6, r8
	beq .L0815DFBC
	cmp r6, #0
	beq .L0815DF7E
	subs r3, r4, r2
	b .L0815DF80
.L0815DF7E:
	subs r3, r2, r4
.L0815DF80:
	cmp r3, #0
	blt .L0815DF8E
	movs r0, #0
	str r0, [r5, #4]
	str r1, [r5, #8]
	str r3, [r5, #0xc]
	b .L0815DF98
.L0815DF8E:
	movs r0, #1
	str r0, [r5, #4]
	str r1, [r5, #8]
	rsbs r0, r3, #0
	str r0, [r5, #0xc]
.L0815DF98:
	ldr r1, [r5, #0xc]
	subs r0, r1, #1
	ldr r2, .L0815DFB8
	cmp r0, r2
	bhi .L0815DFC4
.L0815DFA2:
	lsls r0, r1, #1
	str r0, [r5, #0xc]
	ldr r1, [r5, #8]
	subs r1, #1
	str r1, [r5, #8]
	adds r1, r0, #0
	subs r0, r1, #1
	cmp r0, r2
	bls .L0815DFA2
	b .L0815DFC4
	.byte 0x00, 0x00
.L0815DFB8: .4byte 0x3FFFFFFE
.L0815DFBC:
	str r6, [r5, #4]
	str r1, [r5, #8]
	adds r0, r2, r4
	str r0, [r5, #0xc]
.L0815DFC4:
	movs r0, #3
	str r0, [r5]
	ldr r1, [r5, #0xc]
	cmp r1, #0
	bge .L0815DFDE
	movs r0, #1
	ands r0, r1
	lsrs r1, r1, #1
	orrs r0, r1
	str r0, [r5, #0xc]
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
.L0815DFDE:
	adds r0, r5, #0
.L0815DFE0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815DFE8
sub_0815DFE8: @ 0x0815DFE8
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	add r0, sp, #0x30
	mov r1, sp
	bl sub_0815DDF0
	add r0, sp, #0x34
	add r4, sp, #0x10
	adds r1, r4, #0
	bl sub_0815DDF0
	add r2, sp, #0x20
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815DE6C
	bl sub_0815DD38
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start sub_0815E014
sub_0815E014: @ 0x0815E014
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	add r0, sp, #0x30
	mov r1, sp
	bl sub_0815DDF0
	add r0, sp, #0x34
	add r4, sp, #0x10
	adds r1, r4, #0
	bl sub_0815DDF0
	ldr r0, [r4, #4]
	movs r1, #1
	eors r0, r1
	str r0, [r4, #4]
	add r2, sp, #0x20
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815DE6C
	bl sub_0815DD38
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start sub_0815E048
sub_0815E048: @ 0x0815E048
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x38
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	add r0, sp, #0x30
	mov r1, sp
	bl sub_0815DDF0
	add r0, sp, #0x34
	add r4, sp, #0x10
	adds r1, r4, #0
	bl sub_0815DDF0
	mov r7, sp
	add r0, sp, #0x20
	mov r8, r0
	movs r0, #0
	ldr r1, [sp]
	mov sb, r8
	cmp r1, #1
	bhi .L0815E07A
	movs r0, #1
.L0815E07A:
	cmp r0, #0
	bne .L0815E0D8
	movs r2, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi .L0815E088
	movs r2, #1
.L0815E088:
	cmp r2, #0
	beq .L0815E090
	ldr r0, [sp, #4]
	b .L0815E0F8
.L0815E090:
	movs r2, #0
	cmp r1, #4
	bne .L0815E098
	movs r2, #1
.L0815E098:
	cmp r2, #0
	beq .L0815E0AA
	movs r1, #0
	cmp r0, #2
	bne .L0815E0A4
	movs r1, #1
.L0815E0A4:
	cmp r1, #0
	bne .L0815E0C2
	b .L0815E0D8
.L0815E0AA:
	movs r2, #0
	cmp r0, #4
	bne .L0815E0B2
	movs r2, #1
.L0815E0B2:
	cmp r2, #0
	beq .L0815E0CC
	movs r0, #0
	cmp r1, #2
	bne .L0815E0BE
	movs r0, #1
.L0815E0BE:
	cmp r0, #0
	beq .L0815E0F6
.L0815E0C2:
	ldr r0, .L0815E0C8
	b .L0815E19A
	.byte 0x00, 0x00
.L0815E0C8: .4byte 0x030020D0 @ IWRAM+0x20D0
.L0815E0CC:
	movs r2, #0
	cmp r1, #2
	bne .L0815E0D4
	movs r2, #1
.L0815E0D4:
	cmp r2, #0
	beq .L0815E0EA
.L0815E0D8:
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x14]
	eors r0, r1
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	str r1, [sp, #4]
	mov r0, sp
	b .L0815E19A
.L0815E0EA:
	movs r1, #0
	cmp r0, #2
	bne .L0815E0F2
	movs r1, #1
.L0815E0F2:
	cmp r1, #0
	beq .L0815E108
.L0815E0F6:
	ldr r0, [r7, #4]
.L0815E0F8:
	ldr r1, [sp, #0x14]
	eors r0, r1
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	str r1, [sp, #0x14]
	adds r0, r4, #0
	b .L0815E19A
.L0815E108:
	ldr r0, [r7, #0xc]
	movs r1, #0
	ldr r2, [sp, #0x1c]
	movs r3, #0
	bl sub_0815E6B8
	adds r2, r1, #0
	adds r5, r2, #0
	adds r6, r0, #0
	ldr r4, [r7, #8]
	ldr r0, [sp, #0x18]
	adds r4, r4, r0
	str r4, [sp, #0x28]
	ldr r1, [r7, #4]
	ldr r0, [sp, #0x14]
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	str r0, [sp, #0x24]
	adds r4, #2
	str r4, [sp, #0x28]
	cmp r2, #0
	bge .L0815E154
	movs r2, #1
	movs r1, #0x80
	lsls r1, r1, #0x18
.L0815E13E:
	adds r4, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq .L0815E14C
	lsrs r6, r6, #1
	orrs r6, r1
.L0815E14C:
	lsrs r5, r5, #1
	cmp r5, #0
	blt .L0815E13E
	str r4, [sp, #0x28]
.L0815E154:
	ldr r0, .L0815E1A8
	cmp r5, r0
	bhi .L0815E17A
	movs r4, #0x80
	lsls r4, r4, #0x18
	movs r3, #1
	adds r2, r0, #0
	ldr r1, [sp, #0x28]
.L0815E164:
	subs r1, #1
	lsls r5, r5, #1
	adds r0, r6, #0
	ands r0, r4
	cmp r0, #0
	beq .L0815E172
	orrs r5, r3
.L0815E172:
	lsls r6, r6, #1
	cmp r5, r2
	bls .L0815E164
	str r1, [sp, #0x28]
.L0815E17A:
	movs r0, #0x7f
	ands r0, r5
	cmp r0, #0x40
	bne .L0815E190
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0
	bne .L0815E18E
	cmp r6, #0
	beq .L0815E190
.L0815E18E:
	adds r5, #0x40
.L0815E190:
	str r5, [sp, #0x2c]
	movs r0, #3
	mov r1, r8
	str r0, [r1]
	mov r0, sb
.L0815E19A:
	bl sub_0815DD38
	add sp, #0x38
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7, pc}
.L0815E1A8: .4byte 0x3FFFFFFF

	thumb_func_start sub_0815E1AC
sub_0815E1AC: @ 0x0815E1AC
	push {r4, r5, r6, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl sub_0815DDF0
	add r0, sp, #0x24
	add r5, sp, #0x10
	adds r1, r5, #0
	bl sub_0815DDF0
	mov r4, sp
	movs r0, #0
	ldr r3, [sp]
	cmp r3, #1
	bhi .L0815E1D2
	movs r0, #1
.L0815E1D2:
	cmp r0, #0
	beq .L0815E1DA
	mov r1, sp
	b .L0815E28C
.L0815E1DA:
	movs r0, #0
	ldr r2, [sp, #0x10]
	adds r6, r2, #0
	cmp r2, #1
	bhi .L0815E1E6
	movs r0, #1
.L0815E1E6:
	cmp r0, #0
	beq .L0815E1EE
	adds r1, r5, #0
	b .L0815E28C
.L0815E1EE:
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x14]
	eors r0, r1
	str r0, [sp, #4]
	movs r0, #0
	cmp r3, #4
	bne .L0815E1FE
	movs r0, #1
.L0815E1FE:
	cmp r0, #0
	bne .L0815E20E
	movs r0, #0
	cmp r3, #2
	bne .L0815E20A
	movs r0, #1
.L0815E20A:
	cmp r0, #0
	beq .L0815E220
.L0815E20E:
	ldr r0, [r4]
	adds r1, r4, #0
	cmp r0, r6
	bne .L0815E28C
	ldr r1, .L0815E21C
	b .L0815E28C
	.byte 0x00, 0x00
.L0815E21C: .4byte 0x030020D0 @ IWRAM+0x20D0
.L0815E220:
	movs r1, #0
	cmp r2, #4
	bne .L0815E228
	movs r1, #1
.L0815E228:
	cmp r1, #0
	beq .L0815E234
	str r0, [sp, #0xc]
	str r0, [sp, #8]
	mov r1, sp
	b .L0815E28C
.L0815E234:
	movs r0, #0
	cmp r2, #2
	bne .L0815E23C
	movs r0, #1
.L0815E23C:
	cmp r0, #0
	beq .L0815E246
	movs r0, #4
	str r0, [r4]
	b .L0815E28A
.L0815E246:
	ldr r1, [r4, #8]
	ldr r0, [sp, #0x18]
	subs r0, r1, r0
	str r0, [r4, #8]
	ldr r2, [r4, #0xc]
	ldr r3, [sp, #0x1c]
	cmp r2, r3
	bhs .L0815E25C
	lsls r2, r2, #1
	subs r0, #1
	str r0, [r4, #8]
.L0815E25C:
	movs r0, #0x80
	lsls r0, r0, #0x17
	movs r1, #0
.L0815E262:
	cmp r2, r3
	blo .L0815E26A
	orrs r1, r0
	subs r2, r2, r3
.L0815E26A:
	lsrs r0, r0, #1
	lsls r2, r2, #1
	cmp r0, #0
	bne .L0815E262
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x40
	bne .L0815E288
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne .L0815E286
	cmp r2, #0
	beq .L0815E288
.L0815E286:
	adds r1, #0x40
.L0815E288:
	str r1, [r4, #0xc]
.L0815E28A:
	adds r1, r4, #0
.L0815E28C:
	adds r0, r1, #0
	bl sub_0815DD38
	add sp, #0x28
	pop {r4, r5, r6, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815E298
sub_0815E298: @ 0x0815E298
.L0815E298:
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	ldr r2, [r4]
	cmp r2, #1
	bhi .L0815E2A6
	movs r0, #1
.L0815E2A6:
	cmp r0, #0
	bne .L0815E2B8
	movs r0, #0
	ldr r3, [r1]
	cmp r3, #1
	bhi .L0815E2B4
	movs r0, #1
.L0815E2B4:
	cmp r0, #0
	beq .L0815E2BC
.L0815E2B8:
	movs r0, #1
	b .L0815E37A
.L0815E2BC:
	movs r0, #0
	cmp r2, #4
	bne .L0815E2C4
	movs r0, #1
.L0815E2C4:
	cmp r0, #0
	beq .L0815E2DC
	movs r0, #0
	cmp r3, #4
	bne .L0815E2D0
	movs r0, #1
.L0815E2D0:
	cmp r0, #0
	beq .L0815E2DC
	ldr r0, [r1, #4]
	ldr r1, [r4, #4]
	subs r0, r0, r1
	b .L0815E37A
.L0815E2DC:
	movs r2, #0
	ldr r0, [r4]
	cmp r0, #4
	bne .L0815E2E6
	movs r2, #1
.L0815E2E6:
	cmp r2, #0
	bne .L0815E334
	movs r2, #0
	cmp r3, #4
	bne .L0815E2F2
	movs r2, #1
.L0815E2F2:
	cmp r2, #0
	beq .L0815E304
.L0815E2F6:
	ldr r0, [r1, #4]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq .L0815E33E
	movs r1, #1
	b .L0815E33E
.L0815E304:
	movs r2, #0
	cmp r0, #2
	bne .L0815E30C
	movs r2, #1
.L0815E30C:
	cmp r2, #0
	beq .L0815E31C
	movs r2, #0
	cmp r3, #2
	bne .L0815E318
	movs r2, #1
.L0815E318:
	cmp r2, #0
	bne .L0815E378
.L0815E31C:
	movs r2, #0
	cmp r0, #2
	bne .L0815E324
	movs r2, #1
.L0815E324:
	cmp r2, #0
	bne .L0815E2F6
	movs r0, #0
	cmp r3, #2
	bne .L0815E330
	movs r0, #1
.L0815E330:
	cmp r0, #0
	beq .L0815E342
.L0815E334:
	ldr r0, [r4, #4]
	movs r1, #1
	cmp r0, #0
	beq .L0815E33E
	subs r1, #2
.L0815E33E:
	adds r0, r1, #0
	b .L0815E37A
.L0815E342:
	ldr r3, [r4, #4]
	ldr r0, [r1, #4]
	cmp r3, r0
	beq .L0815E354
.L0815E34A:
	movs r0, #1
	cmp r3, #0
	beq .L0815E37A
	subs r0, #2
	b .L0815E37A
.L0815E354:
	ldr r2, [r4, #8]
	ldr r0, [r1, #8]
	cmp r2, r0
	bgt .L0815E34A
	cmp r2, r0
	bge .L0815E36C
.L0815E360:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, #0
	beq .L0815E37A
	movs r0, #1
	b .L0815E37A
.L0815E36C:
	ldr r0, [r4, #0xc]
	ldr r1, [r1, #0xc]
	cmp r0, r1
	bhi .L0815E34A
	cmp r0, r1
	blo .L0815E360
.L0815E378:
	movs r0, #0
.L0815E37A:
	pop {r4, pc}

	thumb_func_start sub_0815E37C
sub_0815E37C: @ 0x0815E37C
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl sub_0815DDF0
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl sub_0815DDF0
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815E298
	add sp, #0x28
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815E3A4
sub_0815E3A4: @ 0x0815E3A4
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl sub_0815DDF0
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl sub_0815DDF0
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815E3C8
	movs r1, #1
.L0815E3C8:
	cmp r1, #0
	bne .L0815E3DA
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi .L0815E3D6
	movs r1, #1
.L0815E3D6:
	cmp r1, #0
	beq .L0815E3DE
.L0815E3DA:
	movs r0, #1
	b .L0815E3E6
.L0815E3DE:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815E298
.L0815E3E6:
	add sp, #0x28
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815E3EC
sub_0815E3EC: @ 0x0815E3EC
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl sub_0815DDF0
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl sub_0815DDF0
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815E410
	movs r1, #1
.L0815E410:
	cmp r1, #0
	bne .L0815E422
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi .L0815E41E
	movs r1, #1
.L0815E41E:
	cmp r1, #0
	beq .L0815E426
.L0815E422:
	movs r0, #1
	b .L0815E42E
.L0815E426:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815E298
.L0815E42E:
	add sp, #0x28
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815E434
sub_0815E434: @ 0x0815E434
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl sub_0815DDF0
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl sub_0815DDF0
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815E458
	movs r1, #1
.L0815E458:
	cmp r1, #0
	bne .L0815E46A
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi .L0815E466
	movs r1, #1
.L0815E466:
	cmp r1, #0
	beq .L0815E470
.L0815E46A:
	movs r0, #1
	rsbs r0, r0, #0
	b .L0815E478
.L0815E470:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815E298
.L0815E478:
	add sp, #0x28
	pop {r4, pc}

	thumb_func_start sub_0815E47C
sub_0815E47C: @ 0x0815E47C
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl sub_0815DDF0
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl sub_0815DDF0
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815E4A0
	movs r1, #1
.L0815E4A0:
	cmp r1, #0
	bne .L0815E4B2
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi .L0815E4AE
	movs r1, #1
.L0815E4AE:
	cmp r1, #0
	beq .L0815E4B8
.L0815E4B2:
	movs r0, #1
	rsbs r0, r0, #0
	b .L0815E4C0
.L0815E4B8:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815E298
.L0815E4C0:
	add sp, #0x28
	pop {r4, pc}

	thumb_func_start sub_0815E4C4
sub_0815E4C4: @ 0x0815E4C4
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl sub_0815DDF0
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl sub_0815DDF0
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815E4E8
	movs r1, #1
.L0815E4E8:
	cmp r1, #0
	bne .L0815E4FA
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi .L0815E4F6
	movs r1, #1
.L0815E4F6:
	cmp r1, #0
	beq .L0815E4FE
.L0815E4FA:
	movs r0, #1
	b .L0815E506
.L0815E4FE:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815E298
.L0815E506:
	add sp, #0x28
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815E50C
sub_0815E50C: @ 0x0815E50C
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl sub_0815DDF0
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl sub_0815DDF0
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #1
	bhi .L0815E530
	movs r1, #1
.L0815E530:
	cmp r1, #0
	bne .L0815E542
	movs r1, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bhi .L0815E53E
	movs r1, #1
.L0815E53E:
	cmp r1, #0
	beq .L0815E546
.L0815E542:
	movs r0, #1
	b .L0815E54E
.L0815E546:
	mov r0, sp
	adds r1, r4, #0
	bl sub_0815E298
.L0815E54E:
	add sp, #0x28
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815E554
sub_0815E554: @ 0x0815E554
	push {lr}
	sub sp, #0x10
	adds r1, r0, #0
	movs r0, #3
	str r0, [sp]
	lsrs r2, r1, #0x1f
	str r2, [sp, #4]
	cmp r1, #0
	bne .L0815E56C
	movs r0, #2
	str r0, [sp]
	b .L0815E5A4
.L0815E56C:
	movs r0, #0x1e
	str r0, [sp, #8]
	cmp r2, #0
	beq .L0815E58A
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r1, r0
	bne .L0815E584
	ldr r0, .L0815E580
	b .L0815E5AA
.L0815E580: .4byte 0xCF000000
.L0815E584:
	rsbs r0, r1, #0
	str r0, [sp, #0xc]
	b .L0815E58C
.L0815E58A:
	str r1, [sp, #0xc]
.L0815E58C:
	ldr r2, [sp, #0xc]
	ldr r3, .L0815E5B0
	cmp r2, r3
	bhi .L0815E5A4
	ldr r1, [sp, #8]
.L0815E596:
	lsls r0, r2, #1
	subs r1, #1
	adds r2, r0, #0
	cmp r0, r3
	bls .L0815E596
	str r1, [sp, #8]
	str r0, [sp, #0xc]
.L0815E5A4:
	mov r0, sp
	bl sub_0815DD38
.L0815E5AA:
	add sp, #0x10
	pop {pc}
	.byte 0x00, 0x00
.L0815E5B0: .4byte 0x3FFFFFFF

	thumb_func_start sub_0815E5B4
sub_0815E5B4: @ 0x0815E5B4
.L0815E5B4:
	push {lr}
	sub sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, sp
	bl sub_0815DDF0
	movs r1, #0
	ldr r0, [sp]
	cmp r0, #2
	bne .L0815E5CC
	movs r1, #1
.L0815E5CC:
	cmp r1, #0
	bne .L0815E5FE
	movs r1, #0
	cmp r0, #1
	bhi .L0815E5D8
	movs r1, #1
.L0815E5D8:
	cmp r1, #0
	bne .L0815E5FE
	movs r1, #0
	cmp r0, #4
	bne .L0815E5E4
	movs r1, #1
.L0815E5E4:
	cmp r1, #0
	beq .L0815E5F8
.L0815E5E8:
	ldr r0, [sp, #4]
	ldr r1, .L0815E5F4
	cmp r0, #0
	beq .L0815E616
	adds r1, #1
	b .L0815E616
.L0815E5F4: .4byte 0x7FFFFFFF
.L0815E5F8:
	ldr r1, [sp, #8]
	cmp r1, #0
	bge .L0815E602
.L0815E5FE:
	movs r0, #0
	b .L0815E618
.L0815E602:
	cmp r1, #0x1e
	bgt .L0815E5E8
	movs r0, #0x1e
	subs r0, r0, r1
	ldr r1, [sp, #0xc]
	lsrs r1, r0
	ldr r0, [sp, #4]
	cmp r0, #0
	beq .L0815E616
	rsbs r1, r1, #0
.L0815E616:
	adds r0, r1, #0
.L0815E618:
	add sp, #0x14
	pop {pc}

	thumb_func_start sub_0815E61C
sub_0815E61C: @ 0x0815E61C
	push {lr}
	sub sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, sp
	bl sub_0815DDF0
	movs r1, #0
	ldr r0, [sp, #4]
	cmp r0, #0
	bne .L0815E634
	movs r1, #1
.L0815E634:
	str r1, [sp, #4]
	mov r0, sp
	bl sub_0815DD38
	add sp, #0x14
	pop {pc}

	thumb_func_start sub_0815E640
sub_0815E640: @ 0x0815E640
.L0815E640:
	push {lr}
	sub sp, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	mov r0, sp
	bl sub_0815DD38
	add sp, #0x10
	pop {pc}
	.byte 0x00, 0x00

	thumb_func_start sub_0815E658
sub_0815E658: @ 0x0815E658
	push {r4, r5, r6, lr}
	sub sp, #0x18
	str r0, [sp, #0x14]
	add r0, sp, #0x14
	add r1, sp, #4
	bl sub_0815DDF0
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	movs r4, #0
	lsrs r6, r3, #2
	lsls r5, r4, #0x1e
	adds r4, r6, #0
	orrs r4, r5
	lsls r3, r3, #0x1e
	str r4, [sp]
	bl sub_0815DCCC
	add sp, #0x18
	pop {r4, r5, r6, pc}
