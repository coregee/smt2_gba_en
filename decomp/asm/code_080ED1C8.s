	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080ED1C8
sub_080ED1C8: @ 0x080ED1C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r6, .L080ED204
	movs r0, #0
	strh r0, [r5, #0x1c]
	bl BattleMsg_IsDone
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne .L080ED254
	cmp r4, #0
	bne .L080ED250
	ldr r0, .L080ED208
	ldr r0, [r0]
	movs r1, #0x93
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bhi .L080ED250
	lsls r0, r0, #2
	ldr r1, .L080ED20C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L080ED204: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ED208: .4byte 0x03006434 @ IWRAM+0x6434
.L080ED20C: .4byte gUnknown_080ED210
	.global gUnknown_080ED210
gUnknown_080ED210:
.L080ED210: @ jump table
	.4byte .L080ED238
	.4byte .L080ED230
	.4byte .L080ED238
	.4byte .L080ED238
	.4byte .L080ED250
	.4byte .L080ED238
	.4byte .L080ED238
	.4byte .L080ED238
.L080ED230:
	bl sub_080ED9F4
	cmp r0, #0
	bne .L080ED250
.L080ED238:
	bl BattleMenu_Reset
	ldr r0, .L080ED25C
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, #0
	beq .L080ED250
	movs r1, #0
	bl Window_Close
	movs r0, #0
	str r0, [r4]
.L080ED250:
	movs r0, #1
	strh r0, [r5, #0x1c]
.L080ED254:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080ED25C: .4byte 0x00000974

	thumb_func_start sub_080ED260
sub_080ED260: @ 0x080ED260
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #0
	movs r5, #0
	ldr r0, .L080ED2CC
	mov r8, r0
	movs r7, #1
	rsbs r7, r7, #0
.L080ED272:
	mov r2, r8
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, r7
	beq .L080ED2A6
	adds r0, r5, #0
	bl sub_080C0148
	ldrb r0, [r0, #0xc]
	bl sub_080C0818
	movs r2, #0x80
	lsls r2, r2, #7
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L080ED2A6
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl sub_080C0290
	movs r6, #1
.L080ED2A6:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #5
	bls .L080ED272
	cmp r6, #1
	bne .L080ED2C0
	bl sub_080C366C
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
.L080ED2C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080ED2CC: .4byte 0x030050E0 @ IWRAM+0x50E0

	thumb_func_start sub_080ED2D0
sub_080ED2D0: @ 0x080ED2D0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, .L080ED30C
	movs r0, #0
	strh r0, [r4, #0x1c]
	bl sub_080ED954
	cmp r0, #0
	beq .L080ED304
	ldr r1, .L080ED310
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080ED304
	movs r0, #0
	bl sub_080EDA24
	cmp r0, #0
	beq .L080ED300
	movs r0, #1
	bl sub_080EDA24
	cmp r0, #0
	bne .L080ED304
.L080ED300:
	movs r0, #1
	strh r0, [r4, #0x1c]
.L080ED304:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L080ED30C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L080ED310: .4byte 0x0000118C
