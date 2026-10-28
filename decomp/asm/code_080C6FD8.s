	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080C6FD8
sub_080C6FD8: @ 0x080C6FD8
.L080C6FD8:
	push {r4, lr}
	movs r4, #0
.L080C6FDC:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_080C6F30
	adds r4, #1
	cmp r4, #5
	ble .L080C6FDC
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080C6FF0
sub_080C6FF0: @ 0x080C6FF0
.L080C6FF0:
	push {lr}
	ldr r1, .L080C7008
	ldrh r2, [r1]
	cmp r2, #0
	bne .L080C7002
	movs r0, #1
	strh r0, [r1]
	strh r2, [r1, #0x10]
	strh r0, [r1, #0x20]
.L080C7002:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7008: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C700C
sub_080C700C: @ 0x080C700C
.L080C700C:
	push {lr}
	ldr r0, .L080C7030
	ldrh r0, [r0]
	bl sub_080C8AF8
	cmp r0, #0
	beq .L080C702A
	ldr r1, .L080C7034
	ldrh r0, [r1]
	cmp r0, #3
	bne .L080C702A
	movs r0, #2
	strh r0, [r1]
	movs r0, #1
	strh r0, [r1, #0x20]
.L080C702A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7030: .4byte 0x03004614 @ IWRAM+0x4614
.L080C7034: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7038
sub_080C7038: @ 0x080C7038
.L080C7038:
	push {lr}
	ldr r1, .L080C7050
	ldrh r2, [r1, #2]
	cmp r2, #0
	bne .L080C704A
	movs r0, #1
	strh r0, [r1, #2]
	strh r2, [r1, #0x12]
	strh r0, [r1, #0x22]
.L080C704A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7050: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7054
sub_080C7054: @ 0x080C7054
.L080C7054:
	push {lr}
	ldr r1, .L080C706C
	ldrh r0, [r1, #2]
	cmp r0, #3
	bne .L080C7066
	movs r0, #2
	strh r0, [r1, #2]
	movs r0, #1
	strh r0, [r1, #0x22]
.L080C7066:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C706C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7070
sub_080C7070: @ 0x080C7070
.L080C7070:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sb, r0
	adds r7, r1, #0
	adds r4, r2, #0
	movs r0, #0
	mov r8, r0
	movs r5, #1
	movs r6, #7
	movs r1, #3
	mov sl, r1
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #1
	bne .L080C7120
	ldr r1, .L080C70F8
	movs r0, #8
	str r0, [sp]
	mov r0, sl
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_FillRect
	ldrh r2, [r4]
	cmp r5, r2
	bhs .L080C70BE
	subs r0, r2, #1
	subs r1, r6, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
.L080C70BE:
	subs r0, r5, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r6, #0
	beq .L080C7100
	ldr r3, .L080C70FC
	adds r2, r5, #0
	movs r1, #0
	lsls r0, r1, #5
	add r0, r8
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C70DE
	movs r2, #0
.L080C70DE:
	ldr r1, .L080C70F8
	str r2, [sp]
	movs r0, #0
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	b .L080C7106
.L080C70F8: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C70FC: .4byte gUnknown_081B8270
.L080C7100:
	movs r0, #3
	mov r1, sb
	strh r0, [r1]
.L080C7106:
	bl sub_080C6764
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C71AA
	movs r0, #1
	strh r0, [r7]
	ldrh r0, [r4]
	adds r0, #1
	b .L080C71A8
.L080C7120:
	cmp r0, #2
	bne .L080C71AA
	ldr r1, .L080C71E0
	movs r0, #8
	str r0, [sp]
	mov r0, sl
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_FillRect
	ldrh r2, [r4]
	cmp r5, r2
	bhs .L080C714C
	subs r0, r2, #1
	subs r1, r6, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
.L080C714C:
	subs r0, r5, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r0, r6, #0x10
	cmp r0, #0
	ble .L080C7190
	ldr r3, .L080C71E4
	adds r2, r5, #0
	movs r1, #0
	lsls r0, r1, #5
	add r0, r8
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C716E
	movs r2, #0
.L080C716E:
	ldr r1, .L080C71E0
	str r2, [sp]
	movs r0, #0
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080C7190
	mov r1, sb
	strh r0, [r1]
.L080C7190:
	bl sub_080C6764
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C71AA
	movs r0, #1
	strh r0, [r7]
	ldrh r0, [r4]
	subs r0, #1
.L080C71A8:
	strh r0, [r4]
.L080C71AA:
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #3
	beq .L080C71D0
	ldr r0, .L080C71E8
	movs r1, #0
	str r1, [sp]
	lsls r1, r5, #3
	adds r1, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080C71D0:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080C71E0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C71E4: .4byte gUnknown_081B8270
.L080C71E8: .4byte gUnknown_080005A0

	thumb_func_start sub_080C71EC
sub_080C71EC: @ 0x080C71EC
.L080C71EC:
	push {r4, lr}
	ldr r4, .L080C7214
	adds r1, r4, #0
	adds r1, #0x20
	adds r2, r4, #0
	adds r2, #0x10
	adds r0, r4, #0
	bl sub_080C7070
	adds r0, r4, #2
	adds r1, r4, #0
	adds r1, #0x22
	adds r4, #0x12
	adds r2, r4, #0
	bl sub_080C7070
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7214: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7218
sub_080C7218: @ 0x080C7218
.L080C7218:
	push {lr}
	ldr r1, .L080C7230
	ldrh r2, [r1, #4]
	cmp r2, #0
	bne .L080C722A
	movs r0, #1
	strh r0, [r1, #4]
	strh r2, [r1, #0x14]
	strh r0, [r1, #0x24]
.L080C722A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7230: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7234
sub_080C7234: @ 0x080C7234
.L080C7234:
	push {lr}
	ldr r0, .L080C7260
	ldrh r0, [r0]
	bl sub_080C8AF8
	cmp r0, #0
	beq .L080C725A
	ldr r1, .L080C7264
	ldrh r0, [r1, #4]
	cmp r0, #3
	bne .L080C725A
	movs r0, #2
	strh r0, [r1, #4]
	movs r0, #1
	strh r0, [r1, #0x24]
	ldr r0, .L080C7268
	movs r1, #1
	bl VBlankTask_AddCounted
.L080C725A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7260: .4byte 0x03004614 @ IWRAM+0x4614
.L080C7264: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7268: .4byte sub_080C65A4

	thumb_func_start sub_080C726C
sub_080C726C: @ 0x080C726C
.L080C726C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r0, #0
	mov sl, r0
	movs r7, #0
	movs r1, #0xd
	mov sb, r1
	movs r6, #0
	movs r2, #4
	mov r8, r2
	movs r4, #2
	ldr r5, .L080C72EC
	ldrh r0, [r5, #4]
	cmp r0, #1
	bne .L080C7320
	ldr r1, .L080C72F0
	str r2, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0xd
	movs r3, #0
	bl Tilemap_FillRect
	ldrh r1, [r5, #0x14]
	adds r2, r1, #0
	cmp r6, r2
	bhs .L080C72B2
	subs r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r7, r2, #0
.L080C72B2:
	rsbs r0, r1, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r4, #0
	beq .L080C72F8
	ldr r3, .L080C72F4
	adds r2, r6, #0
	lsls r0, r7, #5
	add r0, sl
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C72D0
	movs r2, #0
.L080C72D0:
	ldr r1, .L080C72F0
	mov r0, sb
	str r0, [sp]
	str r2, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	b .L080C72FE
	.byte 0x00, 0x00
.L080C72EC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C72F0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C72F4: .4byte gUnknown_081B92B0
.L080C72F8:
	ldr r1, .L080C731C
	movs r0, #3
	strh r0, [r1, #4]
.L080C72FE:
	bl sub_080C6764
	ldr r1, .L080C731C
	ldrh r0, [r1, #0x24]
	subs r0, #1
	strh r0, [r1, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C73B2
	movs r0, #1
	strh r0, [r1, #0x24]
	ldrh r0, [r1, #0x14]
	adds r0, #1
	b .L080C73B0
	.byte 0x00, 0x00
.L080C731C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7320:
	cmp r0, #2
	bne .L080C73B2
	ldr r0, .L080C73FC
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080C73EC
	ldr r1, .L080C7400
	mov r2, r8
	str r2, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0xd
	movs r3, #0
	bl Tilemap_FillRect
	ldrh r1, [r5, #0x14]
	adds r2, r1, #0
	cmp r6, r2
	bhs .L080C7354
	subs r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r7, r2, #0
.L080C7354:
	rsbs r0, r1, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r0, r4, #0x10
	cmp r0, #0
	ble .L080C7396
	ldr r3, .L080C7404
	adds r2, r6, #0
	lsls r0, r7, #5
	add r0, sl
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C7374
	movs r2, #0
.L080C7374:
	ldr r1, .L080C7400
	mov r0, sb
	str r0, [sp]
	str r2, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r1, .L080C7408
	ldrh r0, [r1, #0x14]
	cmp r0, #0
	bne .L080C7396
	strh r0, [r1, #4]
.L080C7396:
	bl sub_080C6764
	ldr r1, .L080C7408
	ldrh r0, [r1, #0x24]
	subs r0, #1
	strh r0, [r1, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C73B2
	movs r0, #1
	strh r0, [r1, #0x24]
	ldrh r0, [r1, #0x14]
	subs r0, #1
.L080C73B0:
	strh r0, [r1, #0x14]
.L080C73B2:
	ldr r0, .L080C7408
	ldrh r0, [r0, #4]
	cmp r0, #3
	beq .L080C73EC
	ldr r1, .L080C740C
	ldr r0, .L080C7410
	ldrh r0, [r0, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	mov r2, sb
	lsls r1, r2, #0x13
	movs r2, #0x80
	lsls r2, r2, #0xc
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	lsls r1, r6, #3
	adds r1, #5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L080C73EC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080C73FC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C7400: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C7404: .4byte gUnknown_081B92B0
.L080C7408: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C740C: .4byte gUnknown_0834A214
.L080C7410: .4byte 0x03004550 @ IWRAM+0x4550

	thumb_func_start sub_080C7414
sub_080C7414: @ 0x080C7414
.L080C7414:
	push {lr}
	ldr r1, .L080C742C
	ldrh r2, [r1, #6]
	cmp r2, #0
	bne .L080C7426
	movs r0, #1
	strh r0, [r1, #6]
	strh r2, [r1, #0x16]
	strh r0, [r1, #0x26]
.L080C7426:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C742C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7430
sub_080C7430: @ 0x080C7430
.L080C7430:
	push {lr}
	ldr r0, .L080C7454
	ldrh r0, [r0]
	bl sub_080C8AF8
	cmp r0, #0
	beq .L080C744E
	ldr r1, .L080C7458
	ldrh r0, [r1, #6]
	cmp r0, #3
	bne .L080C744E
	movs r0, #2
	strh r0, [r1, #6]
	movs r0, #1
	strh r0, [r1, #0x26]
.L080C744E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7454: .4byte 0x03004614 @ IWRAM+0x4614
.L080C7458: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C745C
sub_080C745C: @ 0x080C745C
.L080C745C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r6, #0
	mov sl, r6
	movs r7, #0x15
	mov sb, r6
	movs r4, #8
	movs r0, #2
	mov r8, r0
	ldr r5, .L080C74A8
	ldrh r0, [r5, #6]
	cmp r0, #1
	bne .L080C751C
	ldr r1, .L080C74AC
	movs r0, #9
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0x15
	movs r3, #0
	bl Tilemap_FillRect
	ldrh r1, [r5, #0x16]
	adds r0, r1, #0
	adds r0, #0x1d
	cmp r0, #0x1e
	ble .L080C74B0
	subs r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r6, r1, #0
	adds r0, r6, #0
	b .L080C74B2
.L080C74A8: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C74AC: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C74B0:
	adds r0, r1, #0
.L080C74B2:
	adds r0, #0x15
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r4, #0
	beq .L080C74F4
	ldr r3, .L080C74EC
	adds r2, r7, #0
	mov r1, sl
	lsls r0, r1, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C74D2
	movs r2, #0
.L080C74D2:
	ldr r1, .L080C74F0
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	b .L080C74FA
.L080C74EC: .4byte gUnknown_081B8170
.L080C74F0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C74F4:
	ldr r1, .L080C7518
	movs r0, #3
	strh r0, [r1, #6]
.L080C74FA:
	bl sub_080C6764
	ldr r1, .L080C7518
	ldrh r0, [r1, #0x26]
	subs r0, #1
	strh r0, [r1, #0x26]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C75B2
	movs r0, #1
	strh r0, [r1, #0x26]
	ldrh r0, [r1, #0x16]
	adds r0, #1
	b .L080C75B0
	.byte 0x00, 0x00
.L080C7518: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C751C:
	cmp r0, #2
	bne .L080C75B2
	ldr r1, .L080C754C
	movs r0, #9
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0x15
	movs r3, #0
	bl Tilemap_FillRect
	ldrh r1, [r5, #0x16]
	adds r0, r1, #0
	adds r0, #0x1d
	cmp r0, #0x1e
	ble .L080C7550
	subs r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r6, r1, #0
	adds r0, r6, #0
	b .L080C7552
	.byte 0x00, 0x00
.L080C754C: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C7550:
	adds r0, r1, #0
.L080C7552:
	adds r0, #0x15
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r0, r4, #0x10
	cmp r0, #0
	ble .L080C7596
	ldr r3, .L080C761C
	adds r2, r7, #0
	mov r1, sl
	lsls r0, r1, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C7574
	movs r2, #0
.L080C7574:
	ldr r1, .L080C7620
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r1, .L080C7624
	ldrh r0, [r1, #0x16]
	cmp r0, #0
	bne .L080C7596
	strh r0, [r1, #6]
.L080C7596:
	bl sub_080C6764
	ldr r1, .L080C7624
	ldrh r0, [r1, #0x26]
	subs r0, #1
	strh r0, [r1, #0x26]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C75B2
	movs r0, #1
	strh r0, [r1, #0x26]
	ldrh r0, [r1, #0x16]
	subs r0, #1
.L080C75B0:
	strh r0, [r1, #0x16]
.L080C75B2:
	ldr r1, .L080C7624
	ldrh r0, [r1, #6]
	cmp r0, #3
	beq .L080C760A
	movs r6, #0
	adds r1, #0x70
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080C75D6
	movs r6, #2
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls .L080C75D6
	movs r0, #0
	strh r0, [r1]
.L080C75D6:
	ldr r0, .L080C7628
	movs r1, #0
	str r1, [sp]
	lsls r4, r7, #3
	adds r1, r4, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r5, #5
	str r5, [sp, #8]
	movs r1, #0
	adds r2, r6, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_080C3168
	adds r4, #8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r6, [sp]
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl sub_080C7FD0
.L080C760A:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C761C: .4byte gUnknown_081B8170
.L080C7620: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C7624: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7628: .4byte gUnknown_080007FC

	thumb_func_start sub_080C762C
sub_080C762C: @ 0x080C762C
.L080C762C:
	push {lr}
	ldr r1, .L080C7644
	ldrh r2, [r1, #8]
	cmp r2, #0
	bne .L080C763E
	movs r0, #1
	strh r0, [r1, #8]
	strh r2, [r1, #0x18]
	strh r0, [r1, #0x28]
.L080C763E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7644: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7648
sub_080C7648: @ 0x080C7648
.L080C7648:
	push {lr}
	ldr r1, .L080C7660
	ldrh r0, [r1, #8]
	cmp r0, #3
	bne .L080C765A
	movs r0, #2
	strh r0, [r1, #8]
	movs r0, #1
	strh r0, [r1, #0x28]
.L080C765A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7660: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7664
sub_080C7664: @ 0x080C7664
.L080C7664:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	lsls r4, r4, #0x10
	lsls r5, r5, #0x10
	ldr r0, .L080C76B0
	movs r1, #1
	str r1, [sp]
	lsrs r4, r4, #0xd
	adds r1, r4, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	lsrs r5, r5, #0xd
	adds r5, #5
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	adds r4, #8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl sub_080C8048
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C76B0: .4byte gUnknown_0800080C

	thumb_func_start sub_080C76B4
sub_080C76B4: @ 0x080C76B4
.L080C76B4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r6, #0
	mov sb, r6
	movs r7, #0x15
	movs r0, #2
	mov r8, r0
	movs r5, #8
	mov sl, r0
	ldr r4, .L080C7700
	ldrh r0, [r4, #8]
	cmp r0, #1
	bne .L080C7774
	ldr r1, .L080C7704
	movs r0, #0xa
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0x15
	movs r3, #2
	bl Tilemap_FillRect
	ldrh r1, [r4, #0x18]
	adds r0, r1, #0
	adds r0, #0x1c
	cmp r0, #0x1e
	ble .L080C7708
	subs r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r6, r1, #0
	adds r0, r6, #0
	b .L080C770A
.L080C7700: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7704: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C7708:
	adds r0, r1, #0
.L080C770A:
	adds r0, #0x15
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r5, #0
	beq .L080C774C
	ldr r3, .L080C7744
	adds r2, r7, #0
	mov r1, sb
	lsls r0, r1, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C772A
	movs r2, #0
.L080C772A:
	ldr r1, .L080C7748
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r5, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	b .L080C7752
.L080C7744: .4byte gUnknown_081B8170
.L080C7748: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C774C:
	ldr r1, .L080C7770
	movs r0, #3
	strh r0, [r1, #8]
.L080C7752:
	bl sub_080C6764
	ldr r1, .L080C7770
	ldrh r0, [r1, #0x28]
	subs r0, #1
	strh r0, [r1, #0x28]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C780A
	movs r0, #1
	strh r0, [r1, #0x28]
	ldrh r0, [r1, #0x18]
	adds r0, #1
	b .L080C7808
	.byte 0x00, 0x00
.L080C7770: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7774:
	cmp r0, #2
	bne .L080C780A
	ldr r1, .L080C77A4
	movs r0, #0xa
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0x15
	movs r3, #2
	bl Tilemap_FillRect
	ldrh r1, [r4, #0x18]
	adds r0, r1, #0
	adds r0, #0x1d
	cmp r0, #0x1e
	ble .L080C77A8
	subs r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r6, r1, #0
	adds r0, r6, #0
	b .L080C77AA
	.byte 0x00, 0x00
.L080C77A4: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C77A8:
	adds r0, r1, #0
.L080C77AA:
	adds r0, #0x15
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r0, r5, #0x10
	cmp r0, #0
	ble .L080C77EE
	ldr r3, .L080C7834
	adds r2, r7, #0
	mov r1, sb
	lsls r0, r1, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C77CC
	movs r2, #0
.L080C77CC:
	ldr r1, .L080C7838
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r5, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r1, .L080C783C
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	bne .L080C77EE
	strh r0, [r1, #8]
.L080C77EE:
	bl sub_080C6764
	ldr r1, .L080C783C
	ldrh r0, [r1, #0x28]
	subs r0, #1
	strh r0, [r1, #0x28]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C780A
	movs r0, #1
	strh r0, [r1, #0x28]
	ldrh r0, [r1, #0x18]
	subs r0, #1
.L080C7808:
	strh r0, [r1, #0x18]
.L080C780A:
	ldr r0, .L080C783C
	ldrh r0, [r0, #8]
	cmp r0, #3
	beq .L080C7822
	ldr r0, .L080C7840
	ldr r1, .L080C7844
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r7, #0
	mov r1, r8
	bl sub_080C7664
.L080C7822:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7834: .4byte gUnknown_081B8170
.L080C7838: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C783C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7840: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C7844: .4byte 0x00000AD8

	thumb_func_start sub_080C7848
sub_080C7848: @ 0x080C7848
.L080C7848:
	push {lr}
	ldr r1, .L080C7860
	ldrh r2, [r1, #0xc]
	cmp r2, #0
	bne .L080C785A
	movs r0, #1
	strh r0, [r1, #0xc]
	strh r2, [r1, #0x1c]
	strh r0, [r1, #0x2c]
.L080C785A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7860: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7864
sub_080C7864: @ 0x080C7864
.L080C7864:
	push {lr}
	ldr r1, .L080C787C
	ldrh r0, [r1, #0xc]
	cmp r0, #3
	bne .L080C7876
	movs r0, #2
	strh r0, [r1, #0xc]
	movs r0, #1
	strh r0, [r1, #0x2c]
.L080C7876:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C787C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7880
sub_080C7880: @ 0x080C7880
.L080C7880:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r6, #0
	mov sl, r6
	movs r5, #0x16
	mov sb, r6
	movs r7, #6
	movs r0, #6
	mov r8, r0
	ldr r4, .L080C78D0
	ldrh r0, [r4, #0xc]
	cmp r0, #1
	bne .L080C7944
	ldr r1, .L080C78D4
	movs r0, #8
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r0, #0
	movs r2, #0x16
	movs r3, #0
	bl Tilemap_FillRect
	ldrh r1, [r4, #0x1c]
	adds r0, r1, #0
	adds r0, #0x1c
	cmp r0, #0x1e
	ble .L080C78D8
	mov r2, r8
	subs r0, r2, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r6, r1, #0
	adds r0, r6, #0
	b .L080C78DA
	.byte 0x00, 0x00
.L080C78D0: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C78D4: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C78D8:
	adds r0, r1, #0
.L080C78DA:
	adds r0, #0x16
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r7, #0
	beq .L080C791C
	ldr r3, .L080C7914
	adds r2, r5, #0
	mov r1, sl
	lsls r0, r1, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C78FA
	movs r2, #0
.L080C78FA:
	ldr r1, .L080C7918
	str r2, [sp]
	mov r2, sb
	str r2, [sp, #4]
	str r7, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	b .L080C7922
.L080C7914: .4byte gUnknown_081B7170
.L080C7918: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C791C:
	ldr r1, .L080C7940
	movs r0, #3
	strh r0, [r1, #0xc]
.L080C7922:
	bl sub_080C6764
	ldr r1, .L080C7940
	ldrh r0, [r1, #0x2c]
	subs r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C79DA
	movs r0, #1
	strh r0, [r1, #0x2c]
	ldrh r0, [r1, #0x1c]
	adds r0, #1
	b .L080C79D8
	.byte 0x00, 0x00
.L080C7940: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7944:
	cmp r0, #2
	bne .L080C79DA
	ldr r1, .L080C7974
	movs r0, #8
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r0, #0
	movs r2, #0x16
	movs r3, #0
	bl Tilemap_FillRect
	ldrh r1, [r4, #0x1c]
	adds r0, r1, #0
	adds r0, #0x1c
	cmp r0, #0x1e
	ble .L080C7978
	mov r2, r8
	subs r0, r2, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r6, r1, #0
	adds r0, r6, #0
	b .L080C797A
.L080C7974: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C7978:
	adds r0, r1, #0
.L080C797A:
	adds r0, #0x16
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r0, r7, #0x10
	cmp r0, #0
	ble .L080C79BE
	ldr r3, .L080C7AB8
	adds r2, r5, #0
	mov r1, sl
	lsls r0, r1, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C799C
	movs r2, #0
.L080C799C:
	ldr r1, .L080C7ABC
	str r2, [sp]
	mov r2, sb
	str r2, [sp, #4]
	str r7, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r1, .L080C7AC0
	ldrh r0, [r1, #0x1c]
	cmp r0, #0
	bne .L080C79BE
	strh r0, [r1, #0xc]
.L080C79BE:
	bl sub_080C6764
	ldr r1, .L080C7AC0
	ldrh r0, [r1, #0x2c]
	subs r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C79DA
	movs r0, #1
	strh r0, [r1, #0x2c]
	ldrh r0, [r1, #0x1c]
	subs r0, #1
.L080C79D8:
	strh r0, [r1, #0x1c]
.L080C79DA:
	ldr r0, .L080C7AC0
	ldrh r0, [r0, #0xc]
	cmp r0, #3
	beq .L080C7AA6
	bl sub_080B447C
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L080C7AC4
	movs r1, #0
	mov sb, r1
	str r1, [sp]
	lsls r7, r5, #3
	adds r1, r7, #0
	adds r1, #0xc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0xa
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldr r2, .L080C7AC8
	mov r8, r2
	movs r6, #3
	adds r0, r4, #0
	ands r0, r6
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	mov r1, sb
	str r1, [sp]
	adds r5, r7, #0
	adds r5, #0x16
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #4]
	movs r1, #6
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	adds r0, r4, #1
	ands r0, r6
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	mov r2, sb
	str r2, [sp]
	adds r1, r7, #0
	adds r1, #0x22
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x12
	mov sl, r1
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	adds r0, r4, #2
	ands r0, r6
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	mov r2, sb
	str r2, [sp]
	str r5, [sp, #4]
	movs r1, #0x1e
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	adds r4, #3
	ands r4, r6
	lsls r4, r4, #2
	add r4, r8
	ldr r0, [r4]
	mov r1, sb
	str r1, [sp]
	adds r1, r7, #0
	adds r1, #0xa
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080C7AA6:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7AB8: .4byte gUnknown_081B7170
.L080C7ABC: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C7AC0: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7AC4: .4byte gUnknown_08000A74
.L080C7AC8: .4byte gUnknown_0834A3CC

	thumb_func_start sub_080C7ACC
sub_080C7ACC: @ 0x080C7ACC
.L080C7ACC:
	ldr r0, .L080C7ADC
	movs r2, #0
	movs r1, #1
	strh r1, [r0, #0xe]
	strh r2, [r0, #0x1e]
	strh r1, [r0, #0x2e]
	bx lr
	.byte 0x00, 0x00
.L080C7ADC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7AE0
sub_080C7AE0: @ 0x080C7AE0
.L080C7AE0:
	ldr r0, .L080C7AEC
	movs r1, #2
	strh r1, [r0, #0xe]
	movs r1, #1
	strh r1, [r0, #0x2e]
	bx lr
.L080C7AEC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7AF0
sub_080C7AF0: @ 0x080C7AF0
.L080C7AF0:
	ldr r0, .L080C7AF8
	ldrh r0, [r0, #0xe]
	bx lr
	.byte 0x00, 0x00
.L080C7AF8: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7AFC
sub_080C7AFC: @ 0x080C7AFC
.L080C7AFC:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	movs r6, #0
	mov r8, r6
	movs r0, #3
	mov sb, r0
	movs r5, #6
	movs r7, #8
	ldr r4, .L080C7B40
	ldrh r0, [r4, #0xe]
	cmp r0, #1
	bne .L080C7BB4
	ldr r1, .L080C7B44
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0
	movs r2, #0x17
	movs r3, #3
	bl Tilemap_FillRect
	ldrh r1, [r4, #0x1e]
	adds r0, r1, #0
	adds r0, #0x1d
	cmp r0, #0x1e
	ble .L080C7B48
	subs r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r6, r1, #0
	adds r0, r6, #0
	b .L080C7B4A
.L080C7B40: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7B44: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C7B48:
	adds r0, r1, #0
.L080C7B4A:
	adds r0, #0x17
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r5, #0
	beq .L080C7B8C
	ldr r3, .L080C7B84
	adds r2, r1, #0
	mov r1, r8
	lsls r0, r1, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C7B6A
	movs r2, #0
.L080C7B6A:
	ldr r1, .L080C7B88
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	b .L080C7B92
	.byte 0x00, 0x00
.L080C7B84: .4byte gUnknown_0834A3DC
.L080C7B88: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C7B8C:
	ldr r1, .L080C7BB0
	movs r0, #3
	strh r0, [r1, #0xe]
.L080C7B92:
	bl sub_080C6764
	ldr r1, .L080C7BB0
	ldrh r0, [r1, #0x2e]
	subs r0, #1
	strh r0, [r1, #0x2e]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C7C44
	movs r0, #1
	strh r0, [r1, #0x2e]
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	b .L080C7C42
	.byte 0x00, 0x00
.L080C7BB0: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7BB4:
	cmp r0, #2
	bne .L080C7C44
	ldr r1, .L080C7BE0
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0
	movs r2, #0x17
	movs r3, #3
	bl Tilemap_FillRect
	ldrh r1, [r4, #0x1e]
	adds r0, r1, #0
	adds r0, #0x1d
	cmp r0, #0x1e
	ble .L080C7BE4
	subs r0, r5, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r6, r1, #0
	adds r0, r6, #0
	b .L080C7BE6
	.byte 0x00, 0x00
.L080C7BE0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C7BE4:
	adds r0, r1, #0
.L080C7BE6:
	adds r0, #0x17
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r0, r5, #0x10
	cmp r0, #0
	ble .L080C7C28
	ldr r3, .L080C7C54
	adds r2, r1, #0
	mov r1, r8
	lsls r0, r1, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	adds r3, r0, r3
	lsls r0, r2, #0x10
	cmp r0, #0
	bge .L080C7C08
	movs r2, #0
.L080C7C08:
	ldr r1, .L080C7C58
	str r2, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r3, #0
	movs r2, #0
	movs r3, #0
	bl Tilemap_CopyRectSkipZero
	ldr r1, .L080C7C5C
	ldrh r0, [r1, #0x1e]
	cmp r0, #0
	bne .L080C7C28
	strh r0, [r1, #0xe]
.L080C7C28:
	bl sub_080C6764
	ldr r1, .L080C7C5C
	ldrh r0, [r1, #0x2e]
	subs r0, #1
	strh r0, [r1, #0x2e]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C7C44
	movs r0, #1
	strh r0, [r1, #0x2e]
	ldrh r0, [r1, #0x1e]
	subs r0, #1
.L080C7C42:
	strh r0, [r1, #0x1e]
.L080C7C44:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7C54: .4byte gUnknown_0834A3DC
.L080C7C58: .4byte 0x0200DFD4 @ EWRAM+0xDFD4
.L080C7C5C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7C60
sub_080C7C60: @ 0x080C7C60
.L080C7C60:
	push {lr}
	sub sp, #8
	ldr r1, .L080C7C8C
	movs r2, #1
	strh r2, [r1, #0x30]
	movs r0, #3
	strh r0, [r1, #0xa]
	ldr r1, .L080C7C90
	movs r0, #0x18
	str r0, [sp]
	str r2, [sp, #4]
	movs r0, #0
	movs r2, #3
	movs r3, #0xc
	bl Tilemap_FillRect
	bl sub_080C6764
	add sp, #8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7C8C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7C90: .4byte 0x0200DFD4 @ EWRAM+0xDFD4

	thumb_func_start sub_080C7C94
sub_080C7C94: @ 0x080C7C94
.L080C7C94:
	push {lr}
	ldr r1, .L080C7CAC
	movs r0, #0
	strh r0, [r1, #0x30]
	strh r0, [r1, #0xa]
	bl sub_080C6558
	bl sub_080C6764
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7CAC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7CB0
sub_080C7CB0: @ 0x080C7CB0
	ldr r1, .L080C7CB8
	movs r0, #0
	strh r0, [r1]
	bx lr
.L080C7CB8: .4byte 0x0203A44E @ EWRAM+0x3A44E

	thumb_func_start sub_080C7CBC
sub_080C7CBC: @ 0x080C7CBC
.L080C7CBC:
	ldr r1, .L080C7CC4
	movs r0, #1
	strh r0, [r1]
	bx lr
.L080C7CC4: .4byte 0x0203A44E @ EWRAM+0x3A44E

	thumb_func_start sub_080C7CC8
sub_080C7CC8: @ 0x080C7CC8
.L080C7CC8:
	push {lr}
	bl sub_080C7CBC
	bl sub_080C7EFC
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C7CD8
sub_080C7CD8: @ 0x080C7CD8
.L080C7CD8:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r0, .L080C7D84
	ldrh r1, [r0, #0x34]
	cmp r1, #0
	bne .L080C7D7C
	ldr r0, .L080C7D88
	str r1, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L080C7D8C
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne .L080C7D1E
	ldr r2, .L080C7D90
	ldr r0, .L080C7D94
	adds r2, r2, r0
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	strb r0, [r2]
	ldr r0, .L080C7D98
	movs r1, #1
	bl VBlankTask_AddCounted
.L080C7D1E:
	ldr r0, .L080C7D9C
	movs r1, #0xe0
	str r1, [sp]
	movs r1, #0x90
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xc
	movs r3, #0
	bl Sprite_Draw
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne .L080C7D7C
	ldr r0, .L080C7DA0
	ldrh r5, [r0]
	cmp r5, #0
	bne .L080C7D7C
	ldr r4, .L080C7DA4
	ldrh r0, [r4, #0x38]
	cmp r0, #0
	beq .L080C7D5A
	subs r0, #1
	strh r0, [r4, #0x38]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L080C7D7C
.L080C7D5A:
	ldr r0, .L080C7DA8
	movs r1, #0xc
	bl sub_080C67C0
	bl sub_080C7E90
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #0x32]
	adds r1, #1
	strh r1, [r4, #0x32]
	ldrh r1, [r4, #0x32]
	cmp r1, r0
	blo .L080C7D78
	strh r5, [r4, #0x32]
.L080C7D78:
	bl Palette_MarkDirty
.L080C7D7C:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C7D84: .4byte 0x030069F0 @ IWRAM+0x69F0
.L080C7D88: .4byte gUnknown_080005A0
.L080C7D8C: .4byte 0x030031BC @ IWRAM+0x31BC
.L080C7D90: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C7D94: .4byte 0x00000A27
.L080C7D98: .4byte sub_080C7EFC
.L080C7D9C: .4byte gUnknown_080019D4
.L080C7DA0: .4byte 0x0203A44E @ EWRAM+0x3A44E
.L080C7DA4: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C7DA8: .4byte 0x03002DB0 @ IWRAM+0x2DB0

	thumb_func_start sub_080C7DAC
sub_080C7DAC: @ 0x080C7DAC
	ldr r1, .L080C7DC0
	ldr r0, .L080C7DC4
	str r0, [r1]
	ldr r0, .L080C7DC8
	str r0, [r1, #4]
	ldr r0, .L080C7DCC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C7DC0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C7DC4: .4byte 0x0200E8D8 @ EWRAM+0xE8D8
.L080C7DC8: .4byte 0x06016040 @ VRAM+0x16040
.L080C7DCC: .4byte 0x84000060

	thumb_func_start sub_080C7DD0
sub_080C7DD0: @ 0x080C7DD0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, .L080C7E08
	movs r5, #0
	str r5, [sp]
	ldr r1, .L080C7E0C
	mov r2, sp
	str r2, [r1]
	str r0, [r1, #4]
	ldr r2, .L080C7E10
	str r2, [r1, #8]
	ldr r1, [r1, #8]
	adds r1, r4, #0
	bl sub_080C7E24
	ldr r0, .L080C7E14
	movs r1, #1
	bl VBlankTask_AddCounted
.L080C7DF8:
	ldrb r0, [r4]
	cmp r0, #0
	beq .L080C7E18
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r4, #1
	b .L080C7DF8
.L080C7E08: .4byte 0x0200E8D8 @ EWRAM+0xE8D8
.L080C7E0C: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C7E10: .4byte 0x85000060
.L080C7E14: .4byte sub_080C7DAC
.L080C7E18:
	adds r0, r5, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C7E24
sub_080C7E24: @ 0x080C7E24
.L080C7E24:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080C7E8A
	ldr r7, .L080C7E4C
	ldr r5, .L080C7E50
	adds r6, r5, #0
	subs r6, #0xe0
.L080C7E36:
	cmp r0, #0x2e
	bne .L080C7E54
	adds r3, r5, #0
	movs r2, #0
	adds r1, #1
.L080C7E40:
	ldm r3!, {r0}
	stm r4!, {r0}
	adds r2, #1
	cmp r2, #7
	bls .L080C7E40
	b .L080C7E84
.L080C7E4C: .4byte gUnknown_0834A5DC
.L080C7E50: .4byte gUnknown_081AD898
.L080C7E54:
	cmp r0, #0x20
	bne .L080C7E68
	movs r2, #0
	adds r1, #1
	movs r0, #0
.L080C7E5E:
	stm r4!, {r0}
	adds r2, #1
	cmp r2, #7
	bls .L080C7E5E
	b .L080C7E84
.L080C7E68:
	ldrb r0, [r1]
	subs r0, #0x2f
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r3, r0, r6
	movs r2, #0
	adds r1, #1
.L080C7E7A:
	ldm r3!, {r0}
	stm r4!, {r0}
	adds r2, #1
	cmp r2, #7
	bls .L080C7E7A
.L080C7E84:
	ldrb r0, [r1]
	cmp r0, #0
	bne .L080C7E36
.L080C7E8A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_080C7E90
sub_080C7E90: @ 0x080C7E90
.L080C7E90:
	push {lr}
	ldr r0, .L080C7EA4
	ldr r0, [r0]
	ldr r1, .L080C7EA8
	ands r0, r1
	cmp r0, #0
	beq .L080C7EAC
	movs r0, #0xb
	b .L080C7EAE
	.byte 0x00, 0x00
.L080C7EA4: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080C7EA8: .4byte 0x00007FFF
.L080C7EAC:
	movs r0, #0xe
.L080C7EAE:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C7EB4
sub_080C7EB4: @ 0x080C7EB4
.L080C7EB4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r5, r1, #0
	ldr r0, .L080C7EF8
	ldrh r4, [r0, #0x32]
	bl sub_080C7E90
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r6, #0
	cmp r6, r7
	bhs .L080C7EEE
.L080C7ED0:
	lsls r0, r4, #1
	mov r1, r8
	subs r0, r1, r0
	ldrh r0, [r0]
	bl Color_ApplyEffect
	strh r0, [r5]
	adds r4, #1
	cmp r4, r7
	bne .L080C7EE6
	movs r4, #0
.L080C7EE6:
	subs r5, #2
	adds r6, #1
	cmp r6, r7
	blo .L080C7ED0
.L080C7EEE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080C7EF8: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C7EFC
sub_080C7EFC: @ 0x080C7EFC
.L080C7EFC:
	push {r4, lr}
	ldr r4, .L080C7F44
	bl sub_080C1D9C
	lsrs r0, r0, #4
	ldr r1, .L080C7F48
	ldr r2, .L080C7F4C
	adds r1, r1, r2
	lsls r0, r0, #3
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r1, r0, #7
	adds r4, r1, r4
	ldr r2, .L080C7F50
	str r4, [r2]
	ldr r1, .L080C7F54
	str r1, [r2, #4]
	ldr r3, .L080C7F58
	str r3, [r2, #8]
	ldr r1, [r2, #8]
	ldr r1, .L080C7F5C
	lsrs r0, r0, #3
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L080C7F44
	adds r4, r1, r0
	str r4, [r2]
	ldr r0, .L080C7F60
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C7F44: .4byte gUnknown_081BBA70
.L080C7F48: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C7F4C: .4byte 0x00000A27
.L080C7F50: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C7F54: .4byte 0x06010120 @ VRAM+0x10120
.L080C7F58: .4byte 0x84000020
.L080C7F5C: .4byte gUnknown_0834A634
.L080C7F60: .4byte 0x06010020 @ VRAM+0x10020

	thumb_func_start sub_080C7F64
sub_080C7F64: @ 0x080C7F64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	bl NumberToDigits
	adds r6, r0, #0
	movs r1, #0
	movs r4, #0
.L080C7F84:
	adds r0, r6, #7
	subs r0, r0, r4
	ldrb r0, [r0]
	cmp r4, #7
	beq .L080C7F96
	cmp r1, #1
	beq .L080C7F96
	cmp r0, #0
	beq .L080C7FB4
.L080C7F96:
	ldr r1, .L080C7FCC
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r5, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	adds r1, r7, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	movs r1, #1
.L080C7FB4:
	adds r4, #1
	adds r0, r5, #6
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r4, #7
	bls .L080C7F84
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080C7FCC: .4byte gUnknown_0834A674

	thumb_func_start sub_080C7FD0
sub_080C7FD0: @ 0x080C7FD0
.L080C7FD0:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	ldr r4, [sp, #0x28]
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sb, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	bl NumberToDigits
	adds r6, r0, #0
	movs r1, #0
	movs r4, #0
.L080C7FFA:
	adds r0, r6, #7
	subs r0, r0, r4
	ldrb r0, [r0]
	cmp r4, #7
	beq .L080C800C
	cmp r1, #1
	beq .L080C800C
	cmp r0, #0
	beq .L080C802A
.L080C800C:
	ldr r1, .L080C8044
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r5, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	mov r1, r8
	adds r2, r7, #0
	movs r3, #1
	bl Sprite_Draw
	movs r1, #1
.L080C802A:
	adds r4, #1
	adds r0, r5, #5
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r4, #7
	bls .L080C7FFA
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080C8044: .4byte gUnknown_0834A69C

	thumb_func_start sub_080C8048
sub_080C8048: @ 0x080C8048
.L080C8048:
	push {r4, lr}
	sub sp, #4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r4, #0
	str r4, [sp]
	bl sub_080C7FD0
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080C8068
sub_080C8068: @ 0x080C8068
.L080C8068:
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
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sl, r2
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	cmp r6, #0x1e
	beq .L080C80C8
	ldr r4, .L080C80C4
	str r6, [sp]
	str r7, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	mov r3, sl
	bl Sprite_DrawSingle
	adds r4, #8
	str r6, [sp]
	str r7, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	mov r3, sl
	bl Sprite_DrawSingle
	b .L080C80F0
.L080C80C4: .4byte gUnknown_0834A6C4
.L080C80C8:
	ldr r4, .L080C8100
	str r6, [sp]
	str r7, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	mov r3, sl
	bl Sprite_DrawSingle
	adds r4, #8
	str r6, [sp]
	str r7, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	mov r3, sl
	bl Sprite_DrawSingle
.L080C80F0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080C8100: .4byte gUnknown_0834A6D4

	thumb_func_start sub_080C8104
sub_080C8104: @ 0x080C8104
.L080C8104:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #0x20]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, .L080C8144
	str r3, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	adds r1, r4, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl Sprite_DrawSingle
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C8144: .4byte gUnknown_0834A6E4

	thumb_func_start sub_080C8148
sub_080C8148: @ 0x080C8148
.L080C8148:
	ldr r2, .L080C8170
	adds r0, r0, r2
	ldm r0!, {r2}
	stm r1!, {r2}
	ldm r0!, {r2}
	stm r1!, {r2}
	ldm r0!, {r2}
	stm r1!, {r2}
	ldm r0!, {r2}
	stm r1!, {r2}
	ldm r0!, {r2}
	stm r1!, {r2}
	ldm r0!, {r2}
	stm r1!, {r2}
	ldm r0!, {r2}
	stm r1!, {r2}
	ldr r0, [r0]
	stm r1!, {r0}
	adds r0, r1, #0
	bx lr
.L080C8170: .4byte gUnknown_081AD5B8

	thumb_func_start sub_080C8174
sub_080C8174: @ 0x080C8174
.L080C8174:
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r3, r0, #0
	adds r5, r2, #0
	movs r6, #0
	ldr r0, .L080C8188
	cmp r3, r0
	bhi .L080C818C
	adds r0, r3, #0
	b .L080C818E
.L080C8188: .4byte 0x000003E7
.L080C818C:
	adds r0, r1, #0
.L080C818E:
	bl NumberToDigits
	adds r4, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq .L080C81BA
	lsls r0, r0, #5
	ldr r1, .L080C8210
	adds r2, r0, r1
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #8
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl Canvas_BlitOr
	movs r6, #1
.L080C81BA:
	cmp r6, #1
	beq .L080C81C4
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq .L080C81E6
.L080C81C4:
	ldrb r0, [r4, #1]
	lsls r0, r0, #5
	ldr r1, .L080C8210
	adds r2, r0, r1
	movs r0, #4
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #8
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl Canvas_BlitOr
.L080C81E6:
	ldrb r0, [r4]
	lsls r0, r0, #5
	ldr r1, .L080C8210
	adds r2, r0, r1
	movs r1, #8
	str r1, [sp]
	movs r0, #0
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl Canvas_BlitOr
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C8210: .4byte gUnknown_081B17B8

	thumb_func_start sub_080C8214
sub_080C8214: @ 0x080C8214
.L080C8214:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	ldr r4, [sp, #0x4c]
	ldr r5, [sp, #0x50]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0xc]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x10]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #0x14]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x18]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov sb, r5
	movs r0, #7
	mov r8, r0
	cmp sb, r4
	bhi .L080C8260
	movs r1, #0x2e
	mov r0, sb
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b .L080C8262
.L080C8260:
	movs r5, #0x2e
.L080C8262:
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne .L080C8280
	lsls r2, r6, #1
	adds r0, r2, r6
	lsls r0, r0, #7
	ldr r1, .L080C8278
	adds r3, r0, r1
	lsls r1, r6, #2
	ldr r0, .L080C827C
	b .L080C828E
.L080C8278: .4byte 0x0200E8D8 @ EWRAM+0xE8D8
.L080C827C: .4byte 0x0200F7D8 @ EWRAM+0xF7D8
.L080C8280:
	lsls r2, r6, #1
	adds r0, r2, r6
	lsls r0, r0, #7
	ldr r1, .L080C82E4
	adds r3, r0, r1
	lsls r1, r6, #2
	ldr r0, .L080C82E8
.L080C828E:
	adds r1, r1, r0
	mov sl, r2
	ldrh r0, [r1]
	lsls r2, r6, #3
	str r2, [sp, #0x20]
	ldr r2, [sp, #0x10]
	adds r2, #0x1d
	str r2, [sp, #0x28]
	ldr r2, [sp, #0x14]
	subs r2, #3
	str r2, [sp, #0x1c]
	cmp r0, sb
	beq .L080C839C
	mov r0, sb
	strh r0, [r1]
	adds r2, r5, #0
	cmp r2, r8
	bls .L080C82B4
	movs r2, #7
.L080C82B4:
	ldr r1, .L080C82EC
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r3, #0
	bl sub_080C8148
	adds r3, r0, #0
	mov r0, r8
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r1, #0
	movs r7, #4
	lsls r2, r6, #8
	str r2, [sp, #0x24]
	cmp r1, r7
	bge .L080C832C
.L080C82DA:
	cmp r5, r8
	bls .L080C82F0
	movs r2, #8
	adds r4, r1, #1
	b .L080C830A
.L080C82E4: .4byte 0x0200E998 @ EWRAM+0xE998
.L080C82E8: .4byte 0x0200F7DA @ EWRAM+0xF7DA
.L080C82EC: .4byte gUnknown_0834A6EC
.L080C82F0:
	mov r0, r8
	subs r0, #8
	cmp r5, r0
	bgt .L080C82FE
	movs r2, #0
	adds r4, r1, #1
	b .L080C830A
.L080C82FE:
	adds r0, r1, #1
	lsls r1, r0, #3
	subs r2, r5, r1
	movs r1, #7
	ands r2, r1
	adds r4, r0, #0
.L080C830A:
	ldr r1, .L080C8334
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r3, #0
	bl sub_080C8148
	adds r3, r0, #0
	mov r0, r8
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r0, r4, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r7
	blt .L080C82DA
.L080C832C:
	cmp r5, #0x2e
	bne .L080C8338
	movs r2, #7
	b .L080C834E
.L080C8334: .4byte gUnknown_0834A70C
.L080C8338:
	movs r0, #0x2e
	subs r0, #7
	cmp r5, r0
	bge .L080C8344
	movs r2, #0
	b .L080C834E
.L080C8344:
	adds r0, r5, #7
	movs r1, #0x2e
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L080C834E:
	ldr r0, .L080C836C
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	adds r1, r3, #0
	bl sub_080C8148
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne .L080C8374
	ldr r0, .L080C8370
	ldr r1, [sp, #0x24]
	adds r3, r1, r0
	b .L080C837A
	.byte 0x00, 0x00
.L080C836C: .4byte gUnknown_0834A730
.L080C8370: .4byte 0x0200F1D8 @ EWRAM+0xF1D8
.L080C8374:
	ldr r0, .L080C83DC
	ldr r2, [sp, #0x24]
	adds r3, r2, r0
.L080C837A:
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, .L080C83E0
	add r1, sp, #8
	str r1, [r0]
	str r3, [r0, #4]
	ldr r1, .L080C83E4
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	mov r0, sb
	ldr r1, [sp, #0x18]
	adds r2, r3, #0
	bl sub_080C8174
	ldr r1, .L080C83E8
	movs r0, #1
	str r0, [r1]
.L080C839C:
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne .L080C83EC
	mov r0, sl
	adds r3, r0, r6
	lsls r3, r3, #0x12
	lsrs r3, r3, #0x10
	ldr r1, [sp, #0x10]
	str r1, [sp]
	ldr r2, [sp, #0x14]
	str r2, [sp, #4]
	movs r0, #7
	movs r1, #1
	movs r2, #1
	bl sub_080C8068
	lsls r3, r6, #0x13
	lsrs r3, r3, #0x10
	ldr r1, [sp, #0x28]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r2, [sp, #0x1c]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #7
	movs r1, #0
	movs r2, #1
	bl sub_080C8104
	b .L080C842E
.L080C83DC: .4byte 0x0200F258 @ EWRAM+0xF258
.L080C83E0: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C83E4: .4byte 0x85000020
.L080C83E8: .4byte 0x0200F7F0 @ EWRAM+0xF7F0
.L080C83EC:
	mov r0, sl
	adds r3, r0, r6
	lsls r3, r3, #0x12
	movs r1, #0xc0
	lsls r1, r1, #0xb
	adds r3, r3, r1
	lsrs r3, r3, #0x10
	ldr r2, [sp, #0x10]
	str r2, [sp]
	ldr r0, [sp, #0x14]
	str r0, [sp, #4]
	movs r0, #7
	movs r1, #2
	movs r2, #1
	bl sub_080C8068
	ldr r3, [sp, #0x20]
	adds r3, #4
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r1, [sp, #0x28]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r2, [sp, #0x1c]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #7
	movs r1, #0
	movs r2, #1
	bl sub_080C8104
.L080C842E:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C8440
sub_080C8440: @ 0x080C8440
.L080C8440:
	ldr r1, .L080C8454
	ldr r0, .L080C8458
	str r0, [r1]
	ldr r0, .L080C845C
	str r0, [r1, #4]
	ldr r0, .L080C8460
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C8454: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C8458: .4byte 0x0200E8D8 @ EWRAM+0xE8D8
.L080C845C: .4byte 0x06012000 @ VRAM+0x12000
.L080C8460: .4byte 0x840003C0

	thumb_func_start sub_080C8464
sub_080C8464: @ 0x080C8464
.L080C8464:
	push {lr}
	ldr r3, .L080C847C
	lsls r0, r0, #0x10
	asrs r2, r0, #0xf
	adds r3, #0x60
	adds r2, r2, r3
	strh r1, [r2]
	lsrs r0, r0, #0x10
	bl sub_080C6F30
	pop {r0}
	bx r0
.L080C847C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C8480
sub_080C8480: @ 0x080C8480
.L080C8480:
	push {lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	bl sub_080C8464
	pop {r0}
	bx r0

	thumb_func_start sub_080C8490
sub_080C8490: @ 0x080C8490
.L080C8490:
	push {lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C8464
	pop {r0}
	bx r0

	thumb_func_start sub_080C84A0
sub_080C84A0: @ 0x080C84A0
.L080C84A0:
	push {r4, lr}
	movs r4, #0
.L080C84A4:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C8464
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #5
	bls .L080C84A4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C84C0
sub_080C84C0: @ 0x080C84C0
.L080C84C0:
	push {r4, lr}
	movs r4, #0
.L080C84C4:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	bl sub_080C8464
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #5
	bls .L080C84C4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C84E0
sub_080C84E0: @ 0x080C84E0
.L080C84E0:
	push {r4, r5, lr}
	lsls r4, r0, #0x10
	lsrs r0, r4, #0x10
	bl sub_080C0148
	cmp r0, #0
	bne .L080C84F0
	b .L080C861C
.L080C84F0:
	ldrh r2, [r0, #0x10]
	ldrh r5, [r0, #0x18]
	ldrh r3, [r0, #0x1a]
	ldr r0, .L080C8520
	asrs r1, r4, #0x10
	movs r4, #0xa2
	lsls r4, r4, #4
	adds r0, r0, r4
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	bgt .L080C8524
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq .L080C852E
	movs r0, #1
	b .L080C861E
	.byte 0x00, 0x00
.L080C8520: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C8524:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	bne .L080C8618
.L080C852E:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r4, r0, #0
	cmp r1, #0xf
	ble .L080C8544
	lsls r1, r3, #0x10
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0x12
	cmp r0, r1
	blt .L080C8618
.L080C8544:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq .L080C8552
	movs r0, #4
	b .L080C861E
.L080C8552:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r2
	cmp r0, #0
	beq .L080C8560
	movs r0, #5
	b .L080C861E
.L080C8560:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq .L080C856C
	movs r0, #0x10
	b .L080C861E
.L080C856C:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r2
	cmp r0, #0
	beq .L080C857A
	movs r0, #6
	b .L080C861E
.L080C857A:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r2
	cmp r0, #0
	beq .L080C8588
	movs r0, #8
	b .L080C861E
.L080C8588:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r2
	cmp r0, #0
	beq .L080C8596
	movs r0, #3
	b .L080C861E
.L080C8596:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq .L080C85A2
	movs r0, #0x12
	b .L080C861E
.L080C85A2:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080C85B0
	movs r0, #9
	b .L080C861E
.L080C85B0:
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L080C85BC
	movs r0, #0xc
	b .L080C861E
.L080C85BC:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq .L080C85C8
	movs r0, #0xd
	b .L080C861E
.L080C85C8:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq .L080C85D6
	movs r0, #0xa
	b .L080C861E
.L080C85D6:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq .L080C85E2
	movs r0, #0xb
	b .L080C861E
.L080C85E2:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080C85EE
	movs r0, #0x11
	b .L080C861E
.L080C85EE:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq .L080C85FA
	movs r0, #0xe
	b .L080C861E
.L080C85FA:
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq .L080C8606
	movs r0, #0xf
	b .L080C861E
.L080C8606:
	asrs r0, r4, #0x10
	cmp r0, #0xf
	bgt .L080C861C
	lsls r1, r3, #0x10
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0x12
	cmp r0, r1
	bge .L080C861C
.L080C8618:
	movs r0, #2
	b .L080C861E
.L080C861C:
	movs r0, #0
.L080C861E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_080C8624
sub_080C8624: @ 0x080C8624
.L080C8624:
	push {r4, r5, lr}
	lsls r5, r0, #0x10
	lsrs r0, r5, #0x10
	bl sub_080C0148
	cmp r0, #0
	beq .L080C86A4
	ldrh r4, [r0, #0x10]
	ldr r0, .L080C8660
	asrs r1, r5, #0x10
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	bl sub_080C35E4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, .L080C8664
	ands r4, r0
	cmp r4, #0
	bne .L080C86A4
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne .L080C8668
	movs r0, #0x13
	b .L080C86AC
.L080C8660: .4byte 0x030046C0 @ IWRAM+0x46C0
.L080C8664: .4byte 0x0000B1E0
.L080C8668:
	cmp r0, #5
	bne .L080C8670
	movs r0, #0x14
	b .L080C86AC
.L080C8670:
	cmp r0, #0xa
	bne .L080C8678
	movs r0, #0x15
	b .L080C86AC
.L080C8678:
	cmp r0, #6
	bne .L080C8680
	movs r0, #0x1a
	b .L080C86AC
.L080C8680:
	cmp r0, #7
	bne .L080C8688
	movs r0, #0x16
	b .L080C86AC
.L080C8688:
	cmp r0, #8
	bne .L080C8690
	movs r0, #0x1b
	b .L080C86AC
.L080C8690:
	cmp r0, #9
	bne .L080C8698
	movs r0, #0x18
	b .L080C86AC
.L080C8698:
	cmp r0, #0xb
	bne .L080C86A0
	movs r0, #0x17
	b .L080C86AC
.L080C86A0:
	cmp r0, #0xc
	beq .L080C86AA
.L080C86A4:
	movs r0, #1
	rsbs r0, r0, #0
	b .L080C86AC
.L080C86AA:
	movs r0, #0x19
.L080C86AC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C86B4
sub_080C86B4: @ 0x080C86B4
.L080C86B4:
	push {r4, lr}
	ldr r1, .L080C86F0
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #1
	adds r1, #0x60
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq .L080C86DC
	adds r0, r4, #0
	bl sub_080C8624
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L080C86E6
.L080C86DC:
	adds r0, r4, #0
	bl sub_080C84E0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L080C86E6:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
.L080C86F0: .4byte 0x0200E7D4 @ EWRAM+0xE7D4

	thumb_func_start sub_080C86F4
sub_080C86F4: @ 0x080C86F4
.L080C86F4:
	lsls r0, r0, #0x10
	ldr r3, .L080C8710
	lsrs r0, r0, #0xf
	adds r1, r3, #0
	adds r1, #0x48
	adds r1, r0, r1
	movs r2, #8
	strh r2, [r1]
	adds r3, #0x54
	adds r0, r0, r3
	ldr r1, .L080C8714
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L080C8710: .4byte 0x0200E7D4 @ EWRAM+0xE7D4
.L080C8714: .4byte 0x0000FFFE

	thumb_func_start sub_080C8718
sub_080C8718: @ 0x080C8718
.L080C8718:
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	ldrh r1, [r4, #2]
	lsls r1, r1, #5
	ldrh r0, [r4, #4]
	adds r0, #1
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, .L080C8758
	adds r1, r1, r0
	ldr r2, .L080C875C
	ldrh r1, [r1]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r3, #2
	bl Palette_FillWithEffect
	bl Palette_MarkDirty
	ldrh r0, [r4, #4]
	adds r0, #2
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls .L080C8760
	movs r0, #1
	b .L080C8762
.L080C8758: .4byte gUnknown_081B70D0
.L080C875C: .4byte 0x03002FD2 @ IWRAM+0x2FD2
.L080C8760:
	movs r0, #0
.L080C8762:
	strh r0, [r5, #0x1c]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_080C876C
sub_080C876C: @ 0x080C876C
	ldr r1, .L080C8780
	ldr r0, .L080C8784
	str r0, [r1]
	ldr r0, .L080C8788
	str r0, [r1, #4]
	ldr r0, .L080C878C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.byte 0x00, 0x00
.L080C8780: .4byte 0x040000D4 @ REG_DMA3SAD
.L080C8784: .4byte gUnknown_081B3F10
.L080C8788: .4byte 0x06015000 @ VRAM+0x15000
.L080C878C: .4byte 0x84000400

	thumb_func_start sub_080C8790
sub_080C8790: @ 0x080C8790
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080C87A8
	movs r1, #1
	bl VBlankTask_AddCounted
	adds r0, r4, #0
	bl sub_080C8718
	pop {r4}
	pop {r0}
	bx r0
.L080C87A8: .4byte sub_080C876C

	thumb_func_start sub_080C87AC
sub_080C87AC: @ 0x080C87AC
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r3, .L080C87D0
	ldrh r1, [r0, #0x24]
	lsls r1, r1, #2
	adds r2, r1, r3
	ldrh r4, [r2]
	adds r5, r4, #0
	adds r3, #2
	adds r1, r1, r3
	ldrh r2, [r1]
	adds r3, r2, #0
	ldrh r0, [r0, #0x26]
	cmp r0, #0
	bne .L080C87D8
	ldr r0, .L080C87D4
	b .L080C87EA
	.byte 0x00, 0x00
.L080C87D0: .4byte gUnknown_0834A750
.L080C87D4: .4byte gUnknown_080013DC
.L080C87D8:
	cmp r0, #1
	bne .L080C87E4
	ldr r0, .L080C87E0
	b .L080C87EA
.L080C87E0: .4byte gUnknown_0800143C
.L080C87E4:
	cmp r0, #2
	bne .L080C8804
	ldr r0, .L080C8800
.L080C87EA:
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	str r2, [sp, #8]
	movs r1, #9
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	b .L080C881E
.L080C8800: .4byte gUnknown_08001424
.L080C8804:
	cmp r0, #3
	bne .L080C881E
	ldr r0, .L080C8828
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	str r5, [sp, #4]
	str r3, [sp, #8]
	movs r1, #9
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L080C881E:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C8828: .4byte gUnknown_08001454

	thumb_func_start sub_080C882C
sub_080C882C: @ 0x080C882C
	push {r4, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x24
	movs r3, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldrb r0, [r1, #9]
	ldrb r4, [r1, #8]
	cmp r0, r4
	blo .L080C884C
	movs r0, #1
	strh r0, [r2, #0x1c]
	strb r3, [r1, #9]
	strb r3, [r1, #8]
	b .L080C8850
.L080C884C:
	adds r0, #1
	strb r0, [r1, #9]
.L080C8850:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C8858
sub_080C8858: @ 0x080C8858
.L080C8858:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	ldr r0, .L080C8888
	ldr r1, .L080C888C
	bl Task_Create
	adds r1, r0, #0
	adds r1, #0x24
	movs r2, #0
	strh r4, [r0, #0x24]
	strh r5, [r1, #2]
	strb r6, [r1, #8]
	strb r2, [r1, #9]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080C8888: .4byte gUnknown_0834A768
.L080C888C: .4byte 0x0000FFFF

	thumb_func_start sub_080C8890
sub_080C8890: @ 0x080C8890
.L080C8890:
	push {lr}
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r1, #0
	bl sub_080C8858
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C88A8
sub_080C88A8: @ 0x080C88A8
.L080C88A8:
	push {lr}
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r1, #1
	bl sub_080C8858
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C88C0
sub_080C88C0: @ 0x080C88C0
.L080C88C0:
	push {lr}
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r1, #2
	bl sub_080C8858
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C88D8
sub_080C88D8: @ 0x080C88D8
.L080C88D8:
	push {lr}
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r1, #3
	bl sub_080C8858
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C88F0
sub_080C88F0: @ 0x080C88F0
.L080C88F0:
	push {lr}
	movs r1, #0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080C88FC
	movs r1, #1
.L080C88FC:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C8904
sub_080C8904: @ 0x080C8904
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r3, .L080C8950
	ldrh r1, [r0, #0x24]
	lsls r1, r1, #2
	adds r2, r1, r3
	ldrh r6, [r2]
	adds r3, #2
	adds r1, r1, r3
	ldrh r5, [r1]
	ldrh r0, [r0, #0x26]
	cmp r0, #0
	bne .L080C8960
	ldr r0, .L080C8954
	movs r1, #0xa0
	lsls r1, r1, #2
	str r1, [sp]
	subs r1, r6, #4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #9
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldr r0, .L080C8958
	ldr r1, .L080C895C
	str r1, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	movs r1, #9
	movs r2, #2
	movs r3, #1
	bl Sprite_Draw
	b .L080C898E
.L080C8950: .4byte gUnknown_0834A750
.L080C8954: .4byte gUnknown_080013F4
.L080C8958: .4byte gUnknown_080013DC
.L080C895C: .4byte 0x00000293
.L080C8960:
	ldr r0, .L080C8998
	movs r4, #0xa0
	lsls r4, r4, #2
	str r4, [sp]
	subs r1, r6, #4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #9
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldr r0, .L080C899C
	str r4, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	movs r1, #9
	movs r2, #4
	movs r3, #1
	bl Sprite_Draw
.L080C898E:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C8998: .4byte gUnknown_0800140C
.L080C899C: .4byte gUnknown_080013DC

	thumb_func_start sub_080C89A0
sub_080C89A0: @ 0x080C89A0
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	ldr r0, .L080C89DC
	ldrh r0, [r0]
	adds r3, r0, #0
	adds r5, r3, #0
	movs r0, #0
	strh r0, [r2, #0x1c]
	ldrh r0, [r2, #0x2a]
	cmp r0, #0
	bne .L080C8A70
	movs r6, #1
	adds r0, r3, #0
	ands r0, r6
	cmp r0, #0
	beq .L080C89C8
	ldr r1, .L080C89E0
	ldrh r0, [r2, #0x24]
	str r0, [r1]
	strh r6, [r2, #0x1c]
.L080C89C8:
	movs r7, #2
	adds r0, r3, #0
	ands r0, r7
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L080C89E4
	strh r6, [r2, #0x1c]
	b .L080C8A70
	.byte 0x00, 0x00
.L080C89DC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L080C89E0: .4byte 0x030037F0 @ IWRAM+0x37F0
.L080C89E4:
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq .L080C8A00
	ldrh r0, [r2, #0x24]
	adds r1, r0, #0
	cmp r1, #2
	beq .L080C8A30
	cmp r1, #5
	bne .L080C89FC
	movs r0, #3
	b .L080C8A6E
.L080C89FC:
	adds r0, #1
	b .L080C8A6E
.L080C8A00:
	movs r0, #0x20
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L080C8A20
	ldrh r0, [r2, #0x24]
	adds r1, r0, #0
	cmp r1, #0
	beq .L080C8A40
	cmp r1, #3
	bne .L080C8A1C
	movs r0, #5
	b .L080C8A6E
.L080C8A1C:
	subs r0, #1
	b .L080C8A6E
.L080C8A20:
	movs r0, #0x80
	ands r3, r0
	cmp r3, #0
	beq .L080C8A48
	ldrh r0, [r2, #0x24]
	adds r1, r0, #0
	cmp r1, #3
	bne .L080C8A34
.L080C8A30:
	strh r4, [r2, #0x24]
	b .L080C8A70
.L080C8A34:
	cmp r1, #4
	bne .L080C8A3C
	strh r6, [r2, #0x24]
	b .L080C8A70
.L080C8A3C:
	cmp r1, #5
	bne .L080C8A44
.L080C8A40:
	strh r7, [r2, #0x24]
	b .L080C8A70
.L080C8A44:
	adds r0, #3
	b .L080C8A6E
.L080C8A48:
	movs r0, #0x40
	ands r5, r0
	cmp r5, #0
	beq .L080C8A70
	ldrh r0, [r2, #0x24]
	adds r1, r0, #0
	cmp r1, #0
	bne .L080C8A5C
	movs r0, #3
	b .L080C8A6E
.L080C8A5C:
	cmp r1, #1
	bne .L080C8A64
	movs r0, #4
	b .L080C8A6E
.L080C8A64:
	cmp r1, #2
	bne .L080C8A6C
	movs r0, #5
	b .L080C8A6E
.L080C8A6C:
	subs r0, #3
.L080C8A6E:
	strh r0, [r2, #0x24]
.L080C8A70:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C8A78
sub_080C8A78: @ 0x080C8A78
.L080C8A78:
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L080C8AA4
	ldr r1, .L080C8AA8
	bl Task_Create
	adds r1, r0, #0
	adds r1, #0x24
	strh r4, [r1, #2]
	strh r5, [r0, #0x24]
	strh r6, [r1, #6]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.L080C8AA4: .4byte gUnknown_0834A7C4
.L080C8AA8: .4byte 0x0000FFFF

	thumb_func_start sub_080C8AAC
sub_080C8AAC: @ 0x080C8AAC
.L080C8AAC:
	push {lr}
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0
	bl sub_080C8A78
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C8AC4
sub_080C8AC4: @ 0x080C8AC4
.L080C8AC4:
	push {lr}
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #1
	bl sub_080C8A78
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C8ADC
sub_080C8ADC: @ 0x080C8ADC
.L080C8ADC:
	strh r1, [r0, #0x1e]
	bx lr

	thumb_func_start sub_080C8AE0
sub_080C8AE0: @ 0x080C8AE0
	push {lr}
	movs r1, #0
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080C8AEC
	movs r1, #1
.L080C8AEC:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_080C8AF4
sub_080C8AF4: @ 0x080C8AF4
.L080C8AF4:
	ldrh r0, [r0, #0x24]
	bx lr

	thumb_func_start sub_080C8AF8
sub_080C8AF8: @ 0x080C8AF8
.L080C8AF8:
	push {lr}
	ldr r0, .L080C8B0C
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r0, #1
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L080C8B0C: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start DungeonMap_GetFloor
DungeonMap_GetFloor: @ 0x080C8B10
.L080C8B10:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	ldr r2, .L080C8B38
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldr r1, [r1]
	cmp r1, #0
	beq .L080C8B32
	movs r0, #0x9a
	lsls r0, r0, #2
	muls r0, r3, r0
	adds r1, r1, r0
.L080C8B32:
	adds r0, r1, #0
	pop {r1}
	bx r1
.L080C8B38: .4byte gDungeonMaps

	thumb_func_start sub_080C8B3C
sub_080C8B3C: @ 0x080C8B3C
.L080C8B3C:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L080C8B50
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r2, #4
	adds r1, r1, r2
	ldr r0, [r1]
	bx lr
.L080C8B50: .4byte gDungeonMaps

	thumb_func_start sub_080C8B54
sub_080C8B54: @ 0x080C8B54
.L080C8B54:
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, .L080C8B70
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080C8B74
	adds r0, r1, #0
	b .L080C8B76
	.byte 0x00, 0x00
.L080C8B70: .4byte gUnknown_084ED5A4
.L080C8B74:
	movs r0, #0
.L080C8B76:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start MarkerHeader_DrawLocationName
MarkerHeader_DrawLocationName: @ 0x080C8B7C
.L080C8B7C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, [sp, #0x24]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	ldr r0, .L080C8BBC
	ldrh r0, [r0]
	ldr r1, .L080C8BC0
	ldrh r1, [r1]
	ldr r3, .L080C8BC4
	ldrh r2, [r3, #0x12]
	ldrh r3, [r3, #0x14]
	bl Location_GetNameCellFromCoords
	adds r4, r0, #0
	movs r6, #0
	b .L080C8BE6
.L080C8BBC: .4byte 0x03004614 @ IWRAM+0x4614
.L080C8BC0: .4byte 0x03004514 @ IWRAM+0x4514
.L080C8BC4: .4byte 0x03004550 @ IWRAM+0x4550
.L080C8BC8:
	ldrh r0, [r4]
	mov r1, r8
	str r1, [sp]
	mov r1, sl
	mov r2, sb
	adds r3, r5, #0
	bl FontSprite_DrawGlyph
	adds r4, #2
	adds r0, r5, r7
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r6, #1
	cmp r6, #0xf
	bhi .L080C8BEC
.L080C8BE6:
	ldrh r0, [r4]
	cmp r0, #0x57
	bne .L080C8BC8
.L080C8BEC:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start MarkerList_DrawLocationName
MarkerList_DrawLocationName: @ 0x080C8BFC
.L080C8BFC:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, [sp, #0x24]
	ldr r5, [sp, #0x28]
	ldr r6, [sp, #0x2c]
	ldr r7, [sp, #0x30]
	mov r8, r7
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
	mov sl, r4
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov sb, r5
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r4, r8
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	bl Location_GetNameCellFromCoords
	adds r4, r0, #0
	movs r5, #0
	b .L080C8C60
.L080C8C42:
	ldrh r0, [r4]
	str r7, [sp]
	mov r1, sl
	mov r2, sb
	adds r3, r6, #0
	bl FontSprite_DrawGlyph
	adds r4, #2
	adds r0, r6, #0
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r5, #1
	cmp r5, #0xf
	bhi .L080C8C66
.L080C8C60:
	ldrh r0, [r4]
	cmp r0, #0x57
	bne .L080C8C42
.L080C8C66:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C8C78
sub_080C8C78: @ 0x080C8C78
.L080C8C78:
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L080C8CC4
	ldr r1, [r0]
	ldr r4, .L080C8CC8
	ldrh r0, [r1]
	strh r0, [r4]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r0, .L080C8CCC
	ldr r1, [r0]
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r4, r0
	str r5, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r4, .L080C8CD0
	adds r0, r4, #0
	movs r1, #0xd0
	movs r2, #0x30
	movs r3, #3
	bl PalFade_Setup
	strh r5, [r4, #2]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C8CC4: .4byte 0x03004630 @ IWRAM+0x4630
.L080C8CC8: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080C8CCC: .4byte 0x03004510 @ IWRAM+0x4510
.L080C8CD0: .4byte 0x0203A3E8 @ EWRAM+0x3A3E8

	thumb_func_start sub_080C8CD4
sub_080C8CD4: @ 0x080C8CD4
.L080C8CD4:
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r1, .L080C8D20
	ldr r5, [r1]
	ldr r1, .L080C8D24
	ldr r1, [r1]
	lsls r2, r0, #5
	adds r1, r1, r2
	lsls r0, r0, #6
	adds r5, r5, r0
	ldr r4, .L080C8D28
	movs r6, #0x20
	str r6, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	adds r4, #0x20
	str r6, [sp]
	movs r0, #3
	adds r1, r5, #0
	adds r2, r4, #0
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r4, .L080C8D2C
	adds r0, r4, #0
	movs r1, #0xd0
	movs r2, #0x30
	movs r3, #3
	bl PalFade_Setup
	strh r6, [r4, #2]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C8D20: .4byte 0x03004630 @ IWRAM+0x4630
.L080C8D24: .4byte 0x03004510 @ IWRAM+0x4510
.L080C8D28: .4byte 0x03002B50 @ IWRAM+0x2B50
.L080C8D2C: .4byte 0x0203A3E8 @ EWRAM+0x3A3E8

	thumb_func_start sub_080C8D30
sub_080C8D30: @ 0x080C8D30
	push {r4, lr}
	ldr r4, .L080C8D64
	bl PalFade_AllDone
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L080C8DFA
	ldr r0, .L080C8D68
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L080C8DFA
	bl Palette_IsBg13Black
	cmp r0, #1
	beq .L080C8DFA
	ldr r1, .L080C8D6C
	ldrh r0, [r1]
	cmp r0, #0
	beq .L080C8D70
	adds r0, r1, #0
	bl PalFade_Update
	b .L080C8DFA
.L080C8D64: .4byte 0x030045B4 @ IWRAM+0x45B4
.L080C8D68: .4byte 0x0200AB04 @ EWRAM+0xAB04
.L080C8D6C: .4byte 0x0203A3E8 @ EWRAM+0x3A3E8
.L080C8D70:
	ldrh r0, [r4]
	cmp r0, #7
	bhi .L080C8DFA
	lsls r0, r0, #2
	ldr r1, .L080C8D80
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080C8D80: .4byte gUnknown_080C8D84
	.global gUnknown_080C8D84
gUnknown_080C8D84:
.L080C8D84: @ jump table
	.4byte .L080C8DA4
	.4byte .L080C8DAE
	.4byte .L080C8DBA
	.4byte .L080C8DC4
	.4byte .L080C8DD0
	.4byte .L080C8DDA
	.4byte .L080C8DE6
	.4byte .L080C8DF0
.L080C8DA4:
	bl sub_080C8C78
	ldrh r0, [r4]
	adds r0, #1
	b .L080C8DF8
.L080C8DAE:
	movs r0, #0
	bl sub_080C8CD4
	ldrh r0, [r4]
	adds r0, #1
	b .L080C8DF8
.L080C8DBA:
	bl sub_080C8C78
	ldrh r0, [r4]
	adds r0, #1
	b .L080C8DF8
.L080C8DC4:
	movs r0, #1
	bl sub_080C8CD4
	ldrh r0, [r4]
	adds r0, #1
	b .L080C8DF8
.L080C8DD0:
	bl sub_080C8C78
	ldrh r0, [r4]
	adds r0, #1
	b .L080C8DF8
.L080C8DDA:
	movs r0, #2
	bl sub_080C8CD4
	ldrh r0, [r4]
	adds r0, #1
	b .L080C8DF8
.L080C8DE6:
	bl sub_080C8C78
	ldrh r0, [r4]
	adds r0, #1
	b .L080C8DF8
.L080C8DF0:
	movs r0, #3
	bl sub_080C8CD4
	movs r0, #0
.L080C8DF8:
	strh r0, [r4]
.L080C8DFA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_080C8E00
sub_080C8E00: @ 0x080C8E00
	push {lr}
	movs r0, #0x84
	lsls r0, r0, #1
	bl Flag_Set
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_080C8E10
sub_080C8E10: @ 0x080C8E10
	ldr r2, .L080C8E28
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	ldr r2, .L080C8E2C
	ldrh r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.byte 0x00, 0x00
.L080C8E28: .4byte 0x04000200 @ REG_IE
.L080C8E2C: .4byte 0x04000004 @ REG_DISPSTAT

	thumb_func_start sub_080C8E30
sub_080C8E30: @ 0x080C8E30
	ldr r2, .L080C8E4C
	ldrh r1, [r2]
	ldr r0, .L080C8E50
	ands r0, r1
	strh r0, [r2]
	ldr r2, .L080C8E54
	ldrh r1, [r2]
	ldr r0, .L080C8E58
	ands r0, r1
	strh r0, [r2]
	ldr r1, .L080C8E5C
	ldr r0, .L080C8E60
	str r0, [r1, #4]
	bx lr
.L080C8E4C: .4byte 0x04000200 @ REG_IE
.L080C8E50: .4byte 0x0000FFFD
.L080C8E54: .4byte 0x04000004 @ REG_DISPSTAT
.L080C8E58: .4byte 0x0000FFEF
.L080C8E5C: .4byte 0x030020F0 @ IWRAM+0x20F0
.L080C8E60: .4byte IntrDummy

	thumb_func_start sub_080C8E64
sub_080C8E64: @ 0x080C8E64
	push {r4, lr}
	ldr r4, .L080C8EF0
	bl sub_080C2244
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L080C8EF8
	ldr r0, .L080C8EF4
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	adds r0, #2
	adds r4, #2
	ldrh r1, [r0]
	strh r1, [r4]
	ldrh r0, [r0, #2]
	b .L080C8F76
	.byte 0x00, 0x00
.L080C8EF0: .4byte 0x050001A2 @ PLTT+0x1A2
.L080C8EF4: .4byte gUnknown_083D8F78
.L080C8EF8:
	ldr r1, .L080C8F80
	movs r0, #0xd1
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	adds r1, #2
	adds r4, #2
	ldrh r0, [r1]
	strh r0, [r4]
	ldrh r0, [r1, #2]
.L080C8F76:
	strh r0, [r4, #2]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C8F80: .4byte 0x03002DB0 @ IWRAM+0x2DB0

	thumb_func_start sub_080C8F84
sub_080C8F84: @ 0x080C8F84
	push {lr}
	ldr r0, .L080C8F9C
	ldr r1, .L080C8FA0
	str r1, [r0, #4]
	ldr r0, .L080C8FA4
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	bl Palette_MarkDirty
	pop {r0}
	bx r0
.L080C8F9C: .4byte 0x030020F0 @ IWRAM+0x20F0
.L080C8FA0: .4byte sub_080C8E64
.L080C8FA4: .4byte sub_080C8E10

	thumb_func_start sub_080C8FA8
sub_080C8FA8: @ 0x080C8FA8
	push {lr}
	ldr r0, .L080C8FBC
	movs r1, #1
	bl VBlankTask_AddCountedAlways
	bl Palette_MarkDirty
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080C8FBC: .4byte sub_080C8E30

	thumb_func_start sub_080C8FC0
sub_080C8FC0: @ 0x080C8FC0
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, .L080C900C
	ldr r1, [r0]
	ldr r4, .L080C9010
	ldrh r0, [r1]
	strh r0, [r4]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r5, #0x20
	str r5, [sp]
	movs r0, #3
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r0, .L080C9014
	ldr r1, [r0]
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r2, r4, r0
	str r5, [sp]
	movs r0, #3
	movs r3, #0x20
	bl Palette_CopyWithEffect
	ldr r4, .L080C9018
	adds r0, r4, #0
	movs r1, #0xd0
	movs r2, #0x30
	movs r3, #8
	bl PalFade_Setup
	strh r5, [r4, #2]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L080C900C: .4byte 0x03004630 @ IWRAM+0x4630
.L080C9010: .4byte 0x030029B0 @ IWRAM+0x29B0
.L080C9014: .4byte 0x03004510 @ IWRAM+0x4510
.L080C9018: .4byte 0x0203A3E8 @ EWRAM+0x3A3E8

	thumb_func_start sub_080C901C
sub_080C901C: @ 0x080C901C
	push {r4, r5, r6, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L080C906C
	ldr r5, [r1]
	ldr r1, .L080C9070
	ldr r1, [r1]
	lsls r2, r0, #5
	adds r1, r1, r2
	lsls r0, r0, #6
	adds r5, r5, r0
	ldr r4, .L080C9074
	movs r6, #0x20
	str r6, [sp]
	movs r0, #3
	adds r2, r4, #0
	movs r3, #0x20
	bl Palette_CopyWithEffect
	adds r4, #0x20
	str r6, [sp]
	movs r0, #3
	adds r1, r5, #0
	adds r2, r4, #0
	movs r3, #0x40
	bl Palette_CopyWithEffect
	ldr r4, .L080C9078
	adds r0, r4, #0
	movs r1, #0xd0
	movs r2, #0x30
	movs r3, #3
	bl PalFade_Setup
	strh r6, [r4, #2]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L080C906C: .4byte 0x03004630 @ IWRAM+0x4630
.L080C9070: .4byte 0x03004510 @ IWRAM+0x4510
.L080C9074: .4byte 0x03002B50 @ IWRAM+0x2B50
.L080C9078: .4byte 0x0203A3E8 @ EWRAM+0x3A3E8

	thumb_func_start sub_080C907C
sub_080C907C: @ 0x080C907C
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_080C9080
sub_080C9080: @ 0x080C9080
	movs r0, #0
	bx lr

	thumb_func_start sub_080C9084
sub_080C9084: @ 0x080C9084
.L080C9084:
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r5, .L080C90C0
	mov r4, sp
	adds r4, #2
	mov r2, sp
	adds r3, r4, #0
	bl sub_080C1F50
	mov ip, r4
	ldr r4, .L080C90C4
.L080C90A8:
	ldrh r2, [r5, #2]
	lsrs r0, r2, #5
	movs r1, #6
	ands r0, r1
	lsrs r3, r0, #1
	ldrh r1, [r5]
	cmp r1, r4
	bne .L080C90C8
	strh r1, [r6]
	movs r0, #0
	b .L080C90EC
	.byte 0x00, 0x00
.L080C90C0: .4byte gUnknown_084EDE54
.L080C90C4: .4byte 0x0000FFFF
.L080C90C8:
	mov r0, sp
	ldrh r0, [r0]
	cmp r1, r0
	bne .L080C90E8
	movs r0, #0x3f
	ands r0, r2
	mov r1, ip
	ldrh r1, [r1]
	cmp r0, r1
	bne .L080C90E8
	cmp r3, r7
	bne .L080C90E8
	ldrh r0, [r5, #8]
	strh r0, [r6]
	adds r0, r5, #0
	b .L080C90EC
.L080C90E8:
	adds r5, #0xc
	b .L080C90A8
.L080C90EC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_080C90F4
sub_080C90F4: @ 0x080C90F4
	movs r0, #1
	bx lr

	thumb_func_start sub_080C90F8
sub_080C90F8: @ 0x080C90F8
.L080C90F8:
	movs r0, #1
	bx lr

	thumb_func_start sub_080C90FC
sub_080C90FC: @ 0x080C90FC
.L080C90FC:
	bx lr
	.byte 0x00, 0x00
