	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_0812BF54
sub_0812BF54: @ 0x0812BF54
	push {lr}
	movs r0, #4
	bl sub_08126D1C
	ldrh r1, [r0, #0xc]
	movs r0, #6
	bl BattleMenu_DrawListPage
	pop {r0}
	bx r0

	thumb_func_start sub_0812BF68
sub_0812BF68: @ 0x0812BF68
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, .L0812BFA4
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r7, r0, r1
	movs r0, #4
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r6, [r5, #0xc]
	movs r0, #4
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r2, .L0812BFA8
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812BFAC
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	b .L0812BFCC
.L0812BFA4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812BFA8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812BFAC:
	ldrh r1, [r2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812BFCC
	ldrh r0, [r5, #0x12]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrh r1, [r0]
	strh r1, [r4, #0x1e]
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x24
	strb r1, [r0]
	strh r2, [r4, #0x1c]
.L0812BFCC:
	ldrh r0, [r5, #0xc]
	cmp r6, r0
	beq .L0812BFDA
	ldrh r1, [r5, #0xc]
	movs r0, #6
	bl BattleMenu_DrawListPage
.L0812BFDA:
	ldr r0, .L0812C048
	movs r4, #0
	str r4, [sp]
	movs r1, #0x14
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L0812C03E
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L0812C01E
	ldr r0, .L0812C04C
	str r4, [sp]
	movs r1, #0x94
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812C01E:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r5, [r5, #0xa]
	cmp r0, r5
	beq .L0812C03E
	ldr r0, .L0812C050
	str r4, [sp]
	movs r1, #0x94
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812C03E:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812C048: .4byte gUnknown_08000F8C
.L0812C04C: .4byte gUnknown_08000FF0
.L0812C050: .4byte gUnknown_08001000

	thumb_func_start sub_0812C054
sub_0812C054: @ 0x0812C054
	push {lr}
	ldr r0, .L0812C078
	ldr r0, [r0, #0x4c]
	cmp r0, #0
	beq .L0812C064
	movs r1, #0
	bl TextWindow_Close
.L0812C064:
	movs r0, #4
	bl sub_081269B0
	bl BattleMsg_Close
	bl sub_08128388
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812C078: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812C07C
sub_0812C07C: @ 0x0812C07C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0812C0B0
	ldr r0, .L0812C0B4
	adds r4, r4, r0
	bl sub_080EA210
	movs r0, #0
	bl YesNo_Create
	str r0, [r4, #4]
	ldrh r0, [r5, #0x1e]
	ldr r1, .L0812C0B8
	bl Battle_BuildItemDropText
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812C0B0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812C0B4: .4byte 0x0000110C
.L0812C0B8: .4byte gUnknown_08124514

	thumb_func_start sub_0812C0BC
sub_0812C0BC: @ 0x0812C0BC
	push {lr}
	adds r0, #0x24
	ldrb r0, [r0]
	bl sub_080C33AC
	bl BattleMsg_Close
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812C0D0
sub_0812C0D0: @ 0x0812C0D0
.L0812C0D0:
	push {r4, lr}
	ldr r4, .L0812C0F4
	ldr r0, .L0812C0F8
	ldr r1, .L0812C0FC
	bl Task_Create
	str r0, [r4, #0x48]
	movs r0, #0
	str r0, [r4, #0x50]
	str r0, [r4, #0x4c]
	ldr r0, .L0812C100
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812C0F4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812C0F8: .4byte gUnknown_08779834
.L0812C0FC: .4byte 0x0000FFFF
.L0812C100: .4byte 0x00000691

	thumb_func_start sub_0812C104
sub_0812C104: @ 0x0812C104
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, .L0812C120
	movs r0, #0
	strh r0, [r4, #0x1e]
	bl sub_080EA210
	bl sub_080F31E0
	cmp r0, #0
	beq .L0812C128
	ldr r0, .L0812C124
	b .L0812C132
	.byte 0x00, 0x00
.L0812C120: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812C124: .4byte gUnknown_08124F82
.L0812C128:
	bl sub_080F4444
	cmp r0, #0
	bne .L0812C14C
	ldr r0, .L0812C148
.L0812C132:
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	b .L0812C170
.L0812C148: .4byte gUnknown_08124EFA
.L0812C14C:
	ldr r0, .L0812C178
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #4
	bl BattleMenu_SetMode
	ldr r1, .L0812C17C
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #0
	bl sub_080C8AAC
	str r0, [r5, #0x4c]
	movs r1, #1
	bl sub_080C8ADC
.L0812C170:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812C178: .4byte gUnknown_08124F12
.L0812C17C: .4byte 0x00000691

	thumb_func_start sub_0812C180
sub_0812C180: @ 0x0812C180
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r6, .L0812C1B0
	movs r0, #0
	strh r0, [r5, #0x1c]
	strh r0, [r5, #0x1e]
	ldr r2, .L0812C1B4
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812C1B8
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r5, #0x1e]
	movs r0, #1
	strh r0, [r5, #0x1c]
	ldr r0, [r6, #0x4c]
	movs r1, #0
	bl sub_080C8ADC
	b .L0812C1FC
.L0812C1B0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812C1B4: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812C1B8:
	ldrh r1, [r2]
	movs r0, #1
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	beq .L0812C234
	ldr r0, [r6, #0x4c]
	bl sub_080C8AF4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L0812C204
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r0, r4, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	asrs r1, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0812C1FC
	adds r0, r1, #0
	bl Combatant_GetStatus
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq .L0812C208
.L0812C1FC:
	movs r0, #0x66
	bl sub_080ECF70
	b .L0812C244
.L0812C204: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812C208:
	mov r0, r8
	strh r0, [r5, #0x1c]
	ldr r0, [r6, #0x4c]
	movs r1, #0
	bl sub_080C8ADC
	ldr r1, .L0812C22C
	adds r0, r6, r1
	strb r4, [r0]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x1e]
	ldr r0, .L0812C230
	strh r7, [r0, #6]
	movs r0, #0x65
	bl sub_080ECF70
	b .L0812C244
.L0812C22C: .4byte 0x00000691
.L0812C230: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812C234:
	ldrh r1, [r2]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq .L0812C244
	movs r0, #0x64
	bl sub_080ECF70
.L0812C244:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812C250
sub_0812C250: @ 0x0812C250
	push {r4, lr}
	ldr r4, .L0812C270
	movs r0, #1
	bl sub_08128B84
	bl BattleMsg_Close
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812C268
	bl Task_End
.L0812C268:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812C270: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812C274
sub_0812C274: @ 0x0812C274
	push {lr}
	movs r0, #0
	movs r1, #0
	bl sub_0812C490
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812C284
sub_0812C284: @ 0x0812C284
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_0812C4D4
	adds r5, r0, #0
	ldr r1, .L0812C2B4
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	subs r0, #1
	cmp r5, r0
	beq .L0812C2DA
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r3, .L0812C2B8
	ands r3, r5
	ldr r0, .L0812C2BC
	cmp r3, r0
	bne .L0812C2C0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	b .L0812C2DA
	.byte 0x00, 0x00
.L0812C2B4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812C2B8: .4byte 0xFFFF0000
.L0812C2BC: .4byte 0xFFFE0000
.L0812C2C0:
	lsrs r3, r3, #0x10
	ldr r2, .L0812C2E0
	movs r4, #6
	ldrsh r0, [r2, r4]
	lsls r0, r0, #1
	movs r4, #0xf3
	lsls r4, r4, #4
	adds r1, r1, r4
	adds r0, r0, r1
	strh r3, [r0]
	strh r5, [r2, #2]
	movs r0, #7
	strh r0, [r2, #4]
.L0812C2DA:
	pop {r4, r5}
	pop {r0}
	bx r0
.L0812C2E0: .4byte 0x030065C0 @ IWRAM+0x65C0

	thumb_func_start sub_0812C2E4
sub_0812C2E4: @ 0x0812C2E4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, .L0812C300
	movs r0, #0
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x1e]
	cmp r0, #6
	bls .L0812C2F6
	b .L0812C46A
.L0812C2F6:
	lsls r0, r0, #2
	ldr r1, .L0812C304
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L0812C300: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812C304: .4byte gUnknown_0812C308
	.global gUnknown_0812C308
gUnknown_0812C308:
.L0812C308: @ jump table
	.4byte .L0812C324
	.4byte .L0812C368
	.4byte .L0812C46A
	.4byte .L0812C3C6
	.4byte .L0812C3F8
	.4byte .L0812C400
	.4byte .L0812C3B8
.L0812C324:
	ldr r6, .L0812C33C
	ldrh r4, [r6, #2]
	bl sub_080EA210
	adds r0, r4, #0
	subs r0, #0x3e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0812C340
	movs r0, #6
	b .L0812C468
.L0812C33C: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812C340:
	movs r0, #1
	strh r0, [r5, #0x1e]
	ldr r1, .L0812C364
	adds r0, r1, #0
	ldrh r6, [r6, #6]
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r1, r4, #0
	bl sub_080EAF1C
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	b .L0812C46A
.L0812C364: .4byte 0xFFFF8000
.L0812C368:
	bl BattleMsg_IsDone
	cmp r0, #1
	beq .L0812C372
	b .L0812C46A
.L0812C372:
	ldr r4, .L0812C3B0
	movs r2, #6
	ldrsh r0, [r4, r2]
	movs r2, #2
	ldrsh r1, [r4, r2]
	bl sub_080ED6DC
	movs r1, #6
	ldrsh r0, [r4, r1]
	movs r2, #0xf3
	lsls r2, r2, #4
	adds r1, r6, r2
	ldr r2, .L0812C3B4
	movs r3, #0
	bl sub_0812E780
	movs r1, #6
	ldrsh r0, [r4, r1]
	bl sub_080F4410
	movs r0, #4
	strh r0, [r5, #0x1e]
	ldr r0, .L0812C3B0
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq .L0812C46A
	movs r0, #1
	strh r0, [r5, #0x1c]
	movs r0, #0xff
	b .L0812C468
.L0812C3B0: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812C3B4: .4byte gUnknown_08124D5E
.L0812C3B8:
	bl sub_0812931C
	movs r0, #2
	bl sub_081293F8
	movs r0, #3
	b .L0812C468
.L0812C3C6:
	bl sub_08129440
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #0
	beq .L0812C46A
	cmp r0, #1
	bne .L0812C3F0
	movs r0, #5
	strh r0, [r5, #0x1e]
	ldr r1, .L0812C3EC
	movs r2, #6
	ldrsh r0, [r1, r2]
	movs r2, #2
	ldrsh r1, [r1, r2]
	bl sub_080ED6DC
	b .L0812C46A
.L0812C3EC: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812C3F0:
	cmp r1, #0xff
	bne .L0812C46A
	movs r0, #5
	b .L0812C468
.L0812C3F8:
	bl BattleMsg_IsDone
	cmp r0, #1
	bne .L0812C46A
.L0812C400:
	bl BattleMenu_Reset
	ldr r4, .L0812C438
	movs r1, #2
	ldrsh r0, [r4, r1]
	cmp r0, #0x38
	bne .L0812C43C
	movs r0, #1
	strh r0, [r5, #0x1c]
	movs r0, #0xfe
	strh r0, [r5, #0x1e]
	bl sub_080C366C
	bl Party_BuildMemberNameTiles
	bl sub_080C6FD8
	bl Battle_IsPartyDefeated
	cmp r0, #0
	beq .L0812C46A
	bl sub_080B9058
	movs r0, #0
	strh r0, [r5, #0x1c]
	movs r0, #2
	b .L0812C468
	.byte 0x00, 0x00
.L0812C438: .4byte 0x030065C0 @ IWRAM+0x65C0
.L0812C43C:
	bl Battle_IsPartyDefeated
	adds r1, r0, #0
	cmp r1, #0
	beq .L0812C452
	bl sub_080B9058
	movs r0, #0
	strh r0, [r5, #0x1c]
	movs r0, #2
	b .L0812C468
.L0812C452:
	movs r0, #1
	strh r0, [r5, #0x1c]
	strh r1, [r5, #0x1e]
	ldrh r4, [r4, #2]
	adds r0, r4, #0
	subs r0, #0x3e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi .L0812C46A
	movs r0, #0xfe
.L0812C468:
	strh r0, [r5, #0x1e]
.L0812C46A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_0812C470
sub_0812C470: @ 0x0812C470
	push {r4, lr}
	ldr r4, .L0812C48C
	bl BattleMsg_Close
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812C482
	bl Task_End
.L0812C482:
	bl sub_081269D0
	pop {r4}
	pop {r0}
	bx r0
.L0812C48C: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812C490
sub_0812C490: @ 0x0812C490
.L0812C490:
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r5, .L0812C4C4
	ldr r0, .L0812C4C8
	ldr r1, .L0812C4CC
	bl Task_Create
	str r0, [r5, #0x48]
	adds r0, #0x24
	strb r4, [r0]
	ldr r1, [r5, #0x48]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1, #0x28]
	cmp r4, #0
	beq .L0812C4BE
	ldr r1, .L0812C4D0
	adds r0, r5, r1
	strb r6, [r0]
.L0812C4BE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0812C4C4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812C4C8: .4byte gUnknown_087799D0
.L0812C4CC: .4byte 0x0000FFFF
.L0812C4D0: .4byte 0x00000691

	thumb_func_start sub_0812C4D4
sub_0812C4D4: @ 0x0812C4D4
.L0812C4D4:
	ldr r0, .L0812C4DC
	ldr r0, [r0, #0x48]
	ldr r0, [r0, #0x28]
	bx lr
.L0812C4DC: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812C4E0
sub_0812C4E0: @ 0x0812C4E0
.L0812C4E0:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	movs r2, #0
	ldr r0, .L0812C538
	ldrh r1, [r0]
	ldr r3, .L0812C53C
	adds r5, r0, #0
	cmp r1, r3
	beq .L0812C516
	adds r6, r5, #0
	adds r1, r3, #0
.L0812C4FC:
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, r4
	beq .L0812C534
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, r1
	bne .L0812C4FC
.L0812C516:
	cmp r4, #0x3f
	bls .L0812C546
	adds r0, r7, #0
	bl Demon_GetRecord
	adds r2, r0, #0
	movs r1, #0
.L0812C524:
	cmp r1, #6
	bne .L0812C540
	ldrb r0, [r2, #0x17]
	cmp r0, r4
	bne .L0812C540
	ldrb r0, [r2, #0x16]
	cmp r0, #0xff
	bne .L0812C540
.L0812C534:
	movs r0, #1
	b .L0812C548
.L0812C538: .4byte gUnknown_087799A8
.L0812C53C: .4byte 0x0000FFFF
.L0812C540:
	adds r1, #1
	cmp r1, #6
	ble .L0812C524
.L0812C546:
	movs r0, #0
.L0812C548:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0812C550
sub_0812C550: @ 0x0812C550
.L0812C550:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r1, r1, #0x10
	ldr r4, .L0812C5C4
	movs r0, #0x80
	lsls r0, r0, #0x18
	adds r0, r0, r1
	mov r8, r0
	lsrs r0, r0, #0x10
	bl Battle_GetCombatant
	adds r1, r0, #0
	adds r6, r1, #0
	adds r6, #0x5d
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r7, r4, r2
	movs r0, #0
	str r0, [sp]
	movs r0, #0xc0
	mov r2, sl
	cmp r2, #0
	beq .L0812C58E
	movs r0, #0x20
.L0812C58E:
	str r0, [sp, #4]
	movs r0, #0
	mov sb, r0
	movs r5, #0
	ldrb r4, [r6]
	adds r6, r1, #0
	adds r6, #0x5e
	cmp r4, #0xff
	beq .L0812C608
.L0812C5A0:
	mov r1, sl
	cmp r1, #2
	bne .L0812C5C8
	cmp r4, #0x3f
	bls .L0812C5C0
	mov r2, r8
	lsrs r0, r2, #0x10
	bl Battle_GetCombatant
	ldrh r1, [r0, #0x12]
	adds r0, r4, #0
	bl sub_0812C4E0
	movs r5, #1
	cmp r0, #0
	beq .L0812C5CE
.L0812C5C0:
	movs r5, #0
	b .L0812C5CE
.L0812C5C4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812C5C8:
	cmp r4, #0x3f
	bhi .L0812C5CE
	movs r5, #1
.L0812C5CE:
	adds r0, r4, #0
	bl sub_080BF5C0
	ldrb r0, [r0]
	ldr r1, [sp, #4]
	ands r0, r1
	cmp r0, #0
	beq .L0812C5F0
	cmp r5, #0
	beq .L0812C5F0
	strh r4, [r7]
	adds r7, #2
	ldr r0, [sp]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
.L0812C5F0:
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0x1f
	bhi .L0812C608
	movs r5, #0
	ldrb r4, [r6]
	adds r6, #1
	cmp r4, #0xff
	bne .L0812C5A0
.L0812C608:
	ldr r2, .L0812C620
	adds r0, r2, #0
	strh r0, [r7]
	ldr r0, [sp]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L0812C620: .4byte 0x0000FFFF

	thumb_func_start sub_0812C624
sub_0812C624: @ 0x0812C624
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, .L0812C678
	mov r8, r0
	movs r6, #0
	ldr r0, .L0812C67C
	ldr r1, .L0812C680
	add r1, r8
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	strh r6, [r7, #0x1e]
	adds r4, r7, #0
	adds r4, #0x24
	ldrb r0, [r4]
	adds r1, r5, #0
	bl sub_0812C550
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq .L0812C69A
	ldrb r0, [r4]
	cmp r0, #2
	beq .L0812C6CC
	bl sub_080F31E0
	cmp r0, #0
	beq .L0812C688
	ldr r0, .L0812C684
	b .L0812C69C
	.byte 0x00, 0x00
.L0812C678: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812C67C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812C680: .4byte 0x00000691
.L0812C684: .4byte gUnknown_08124F82
.L0812C688:
	adds r0, r5, #0
	bl sub_080F4410
	adds r4, r0, #0
	cmp r4, #0
	beq .L0812C69A
	cmp r4, #1
	beq .L0812C6B4
	b .L0812C6CC
.L0812C69A:
	ldr r0, .L0812C6B0
.L0812C69C:
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	strh r0, [r7, #0x1e]
	b .L0812C71A
.L0812C6B0: .4byte gUnknown_08124F46
.L0812C6B4:
	ldr r0, .L0812C6C8
	adds r1, r5, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	strh r4, [r7, #0x1e]
	b .L0812C71A
.L0812C6C8: .4byte gUnknown_08124F60
.L0812C6CC:
	movs r0, #1
	str r0, [sp]
	movs r1, #0
	movs r2, #0x13
	movs r3, #0xa
	bl TextWindow_Create
	mov r1, r8
	str r0, [r1, #0x4c]
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #0xd
	movs r2, #0x1a
	movs r3, #6
	bl sub_080AB890
	mov r2, r8
	str r0, [r2, #0x50]
	bl sub_081272AC
	cmp r6, #4
	bhi .L0812C70A
	str r6, [sp]
	movs r0, #4
	movs r1, #0
	movs r2, #1
	adds r3, r6, #0
	bl sub_08126928
	b .L0812C71A
.L0812C70A:
	movs r0, #5
	str r0, [sp]
	movs r0, #4
	movs r1, #0x10
	movs r2, #1
	adds r3, r6, #0
	bl sub_08126928
.L0812C71A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812C728
sub_0812C728: @ 0x0812C728
	push {lr}
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq .L0812C748
	ldr r0, .L0812C744
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #4
	bl BattleMenu_SetMode
	b .L0812C758
.L0812C744: .4byte gUnknown_08124F2C
.L0812C748:
	ldr r0, .L0812C75C
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #4
	bl BattleMenu_SetMode
.L0812C758:
	pop {r0}
	bx r0
.L0812C75C: .4byte gUnknown_08124570

	thumb_func_start sub_0812C760
sub_0812C760: @ 0x0812C760
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #4
	bl sub_08126D1C
	adds r1, r0, #0
	ldr r0, .L0812C78C
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r2, [r1, #0x12]
	adds r0, r0, r2
	ldrb r5, [r0]
	adds r4, #0x24
	ldrb r0, [r4]
	cmp r0, #2
	beq .L0812C790
	ldrh r1, [r1, #0xc]
	movs r0, #7
	bl BattleMenu_DrawListPage
	b .L0812C798
.L0812C78C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812C790:
	ldrh r1, [r1, #0xc]
	movs r0, #8
	bl BattleMenu_DrawListPage
.L0812C798:
	adds r0, r5, #0
	bl sub_080BF5C0
	ldr r0, [r0, #0x18]
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #8
	bl BattleMenu_SetMode
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0812C7B4
sub_0812C7B4: @ 0x0812C7B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	ldr r4, .L0812C7F8
	movs r0, #4
	bl sub_08126D1C
	adds r7, r0, #0
	ldrb r0, [r7, #0xc]
	str r0, [sp, #0xc]
	ldrb r1, [r7, #0x12]
	str r1, [sp, #0x10]
	movs r0, #4
	bl sub_08126A08
	movs r0, #0
	strh r0, [r6, #0x1e]
	strh r0, [r6, #0x1c]
	ldr r2, .L0812C7FC
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812C800
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r6, #0x1e]
	movs r0, #1
	strh r0, [r6, #0x1c]
	b .L0812C88A
.L0812C7F8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812C7FC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812C800:
	ldrh r1, [r2]
	movs r2, #1
	mov sl, r2
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq .L0812C88A
	mov r0, sl
	strh r0, [r6, #0x1c]
	ldr r0, .L0812C868
	ldr r2, .L0812C86C
	adds r1, r4, r2
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldrh r0, [r7, #0x12]
	lsls r0, r0, #1
	ldr r1, .L0812C870
	adds r0, r0, r1
	ldrh r0, [r0]
	mov sb, r0
	mov r2, sb
	lsls r2, r2, #0x10
	mov r8, r2
	asrs r4, r2, #0x10
	adds r0, r4, #0
	bl sub_080ED6CC
	adds r0, r5, #0
	bl Battle_GetMp
	adds r0, r4, #0
	bl sub_080ED694
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080ED744
	cmp r0, #1
	bne .L0812C874
	adds r0, r6, #0
	adds r0, #0x2c
	mov r1, sb
	strb r1, [r0]
	b .L0812C88A
	.byte 0x00, 0x00
.L0812C868: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812C86C: .4byte 0x00000691
.L0812C870: .4byte 0x0203C4D0 @ EWRAM+0x3C4D0
.L0812C874:
	mov r2, r8
	lsrs r0, r2, #0x10
	bl sub_08127E98
	cmp r0, #1
	bne .L0812C886
	movs r0, #2
	strh r0, [r6, #0x1e]
	b .L0812C88A
.L0812C886:
	mov r1, sl
	strh r1, [r6, #0x1e]
.L0812C88A:
	ldr r2, [sp, #0xc]
	ldrh r0, [r7, #0xc]
	cmp r2, r0
	beq .L0812C8AE
	adds r0, r6, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq .L0812C8A6
	ldrh r1, [r7, #0xc]
	movs r0, #7
	bl BattleMenu_DrawListPage
	b .L0812C8AE
.L0812C8A6:
	ldrh r1, [r7, #0xc]
	movs r0, #8
	bl BattleMenu_DrawListPage
.L0812C8AE:
	ldr r1, [sp, #0x10]
	ldrh r2, [r7, #0x12]
	cmp r1, r2
	beq .L0812C8D4
	ldrh r0, [r7, #0x12]
	lsls r0, r0, #1
	ldr r1, .L0812C948
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_080BF5C0
	ldr r0, [r0, #0x18]
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #8
	bl BattleMenu_SetMode
.L0812C8D4:
	ldr r0, .L0812C94C
	movs r4, #0
	str r4, [sp]
	movs r1, #0x14
	str r1, [sp, #4]
	ldrh r2, [r7, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r7, #0xa]
	cmp r0, #5
	bls .L0812C938
	ldrh r0, [r7, #0xc]
	cmp r0, #0
	beq .L0812C918
	ldr r0, .L0812C950
	str r4, [sp]
	movs r1, #0x94
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812C918:
	ldrh r0, [r7, #0xc]
	adds r0, #5
	ldrh r7, [r7, #0xa]
	cmp r0, r7
	beq .L0812C938
	ldr r0, .L0812C954
	str r4, [sp]
	movs r1, #0x94
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812C938:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0812C948: .4byte 0x0203C4D0 @ EWRAM+0x3C4D0
.L0812C94C: .4byte gUnknown_08000F8C
.L0812C950: .4byte gUnknown_08000FF0
.L0812C954: .4byte gUnknown_08001000

	thumb_func_start sub_0812C958
sub_0812C958: @ 0x0812C958
	push {lr}
	movs r0, #0x97
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812C974
sub_0812C974: @ 0x0812C974
	push {lr}
	ldr r1, .L0812C984
	movs r0, #3
	bl BattleMenu_SetMode
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812C984: .4byte gUnknown_081241E0

	thumb_func_start sub_0812C988
sub_0812C988: @ 0x0812C988
	push {r4, lr}
	ldr r4, .L0812C9B8
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812C998
	movs r1, #0
	bl TextWindow_Close
.L0812C998:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812C9A4
	movs r1, #0
	bl Window_Close
.L0812C9A4:
	movs r0, #4
	bl sub_081269B0
	bl BattleMenu_Reset
	bl sub_08128388
	pop {r4}
	pop {r0}
	bx r0
.L0812C9B8: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812C9BC
sub_0812C9BC: @ 0x0812C9BC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	bl sub_080BF5C0
	movs r1, #0
	strh r1, [r4, #0x1e]
	ldrb r0, [r0, #2]
	cmp r0, #0x80
	beq .L0812C9DA
	cmp r0, #0x82
	beq .L0812C9DA
	cmp r0, #0x83
	bne .L0812C9DE
.L0812C9DA:
	movs r0, #1
	b .L0812C9E8
.L0812C9DE:
	cmp r0, #0xf
	beq .L0812C9EA
	cmp r0, #0xff
	beq .L0812C9EA
	movs r0, #2
.L0812C9E8:
	strh r0, [r4, #0x1e]
.L0812C9EA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0812C9F0
sub_0812C9F0: @ 0x0812C9F0
	ldrh r1, [r0, #0x1e]
	lsls r1, r1, #0x10
	adds r2, r0, #0
	adds r2, #0x2c
	ldrb r2, [r2]
	adds r1, r1, r2
	str r1, [r0, #0x28]
	bx lr

	thumb_func_start sub_0812CA00
sub_0812CA00: @ 0x0812CA00
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	bl sub_080BF5C0
	movs r5, #0
	ldr r6, .L0812CA24
	strh r5, [r7, #0x1e]
	ldrb r0, [r0, #2]
	cmp r0, #0x82
	beq .L0812CA40
	cmp r0, #0x82
	bgt .L0812CA28
	cmp r0, #0x80
	beq .L0812CA2E
	b .L0812CA5C
.L0812CA24: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812CA28:
	cmp r0, #0x83
	beq .L0812CA52
	b .L0812CA5C
.L0812CA2E:
	ldr r0, [r6, #0x48]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0812CA3C
	movs r0, #1
	b .L0812CA54
.L0812CA3C:
	movs r0, #0
	b .L0812CA54
.L0812CA40:
	ldr r0, [r6, #0x48]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0812CA4E
	movs r0, #1
	b .L0812CA54
.L0812CA4E:
	movs r0, #0
	b .L0812CA54
.L0812CA52:
	movs r0, #6
.L0812CA54:
	bl BattleMenu_BuildMemberList
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0812CA5C:
	cmp r5, #0
	beq .L0812CACE
	ldr r0, [r6, #0x4c]
	bl Task_End
	ldr r0, [r6, #0x50]
	bl Task_End
	movs r4, #1
	str r4, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r6, #0x4c]
	str r4, [sp]
	movs r0, #0x11
	movs r1, #0
	movs r2, #0xc
	movs r3, #6
	bl TextWindow_Create
	str r0, [r6, #0x50]
	bl sub_081272AC
	cmp r5, #4
	bhi .L0812CAA6
	str r5, [sp]
	movs r0, #4
	movs r1, #0
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
	b .L0812CAB6
.L0812CAA6:
	movs r0, #5
	str r0, [sp]
	movs r0, #4
	movs r1, #0x10
	movs r2, #1
	adds r3, r5, #0
	bl sub_08126928
.L0812CAB6:
	movs r0, #1
	strh r0, [r7, #0x1e]
	bl sub_080EA210
	ldr r0, .L0812CAD8
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #4
	bl BattleMenu_SetMode
.L0812CACE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812CAD8: .4byte gUnknown_08124D72

	thumb_func_start sub_0812CADC
sub_0812CADC: @ 0x0812CADC
	push {r4, lr}
	movs r0, #4
	bl sub_08126D1C
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	movs r0, #0
	bl BattleMenu_DrawListPage
	ldrh r1, [r4, #0x12]
	movs r0, #0
	bl sub_081283C4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0812CAFC
sub_0812CAFC: @ 0x0812CAFC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r6, .L0812CB2C
	movs r0, #4
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r7, [r5, #0x12]
	movs r0, #4
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r0, .L0812CB30
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812CB34
	movs r0, #0x80
	lsls r0, r0, #1
	b .L0812CB48
.L0812CB2C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812CB30: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812CB34:
	ldrb r0, [r5]
	cmp r0, #3
	bne .L0812CB4E
	ldrh r0, [r5, #0x12]
	lsls r0, r0, #1
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r6, r2
	adds r0, r0, r1
	ldrh r0, [r0]
.L0812CB48:
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
.L0812CB4E:
	ldr r0, .L0812CBD0
	movs r4, #0
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L0812CBB2
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L0812CB92
	ldr r0, .L0812CBD4
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812CB92:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r1, [r5, #0xa]
	cmp r0, r1
	beq .L0812CBB2
	ldr r0, .L0812CBD8
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812CBB2:
	ldrh r2, [r5, #0x12]
	cmp r7, r2
	beq .L0812CBC8
	ldrh r1, [r5, #0xc]
	movs r0, #0
	bl BattleMenu_DrawListPage
	ldrh r1, [r5, #0x12]
	movs r0, #0
	bl sub_081283C4
.L0812CBC8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0812CBD0: .4byte gUnknown_08000EA4
.L0812CBD4: .4byte gUnknown_08000FF0
.L0812CBD8: .4byte gUnknown_08001000

	thumb_func_start sub_0812CBDC
sub_0812CBDC: @ 0x0812CBDC
	push {r4, lr}
	ldr r4, .L0812CC0C
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812CBEC
	movs r1, #0
	bl TextWindow_Close
.L0812CBEC:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812CBF8
	movs r1, #0
	bl TextWindow_Close
.L0812CBF8:
	movs r0, #4
	bl sub_081269B0
	bl BattleMenu_Reset
	bl sub_08128388
	pop {r4}
	pop {r0}
	bx r0
.L0812CC0C: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812CC10
sub_0812CC10: @ 0x0812CC10
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0812CC54
	bl sub_080E6E08
	ldr r1, .L0812CC58
	ldr r2, .L0812CC5C
	adds r4, r4, r2
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r1, r1, r2
	ldrb r4, [r4]
	adds r1, r1, r4
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	movs r1, #0
	strh r1, [r5, #0x1c]
	strh r1, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	beq .L0812CC60
	cmp r0, #3
	bne .L0812CC6A
	movs r0, #1
	strh r0, [r5, #0x1c]
	adds r0, r2, #0
	bl sub_080EDA64
	strh r0, [r5, #0x1e]
	b .L0812CC6A
.L0812CC54: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812CC58: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812CC5C: .4byte 0x00000691
.L0812CC60:
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r5, #0x1e]
	movs r0, #1
	strh r0, [r5, #0x1c]
.L0812CC6A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0812CC70
sub_0812CC70: @ 0x0812CC70
.L0812CC70:
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r4, .L0812CC90
	ldr r0, .L0812CC94
	ldr r1, .L0812CC98
	bl Task_Create
	str r0, [r4, #0x48]
	ldr r0, .L0812CC9C
	adds r4, r4, r0
	strb r5, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
.L0812CC90: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812CC94: .4byte gUnknown_08779CA4
.L0812CC98: .4byte 0x0000FFFF
.L0812CC9C: .4byte 0x00000694

	thumb_func_start sub_0812CCA0
sub_0812CCA0: @ 0x0812CCA0
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, .L0812CCE8
	movs r4, #1
	str r4, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r5, #0x4c]
	str r4, [sp]
	movs r0, #0x11
	movs r1, #0
	movs r2, #0xc
	movs r3, #6
	bl TextWindow_Create
	str r0, [r5, #0x50]
	bl sub_081272AC
	movs r0, #0
	bl BattleMenu_BuildMemberList
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #4
	bhi .L0812CCEC
	str r3, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #1
	bl sub_08126928
	b .L0812CCFA
.L0812CCE8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812CCEC:
	movs r0, #5
	str r0, [sp]
	movs r0, #2
	movs r1, #0x10
	movs r2, #1
	bl sub_08126928
.L0812CCFA:
	ldr r1, .L0812CD1C
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #2
	bl MenuCursor_SetIndex
	bl sub_080EA210
	ldr r1, .L0812CD20
	movs r0, #4
	bl BattleMenu_SetMode
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812CD1C: .4byte 0x00000694
.L0812CD20: .4byte gUnknown_08123DF0

	thumb_func_start sub_0812CD24
sub_0812CD24: @ 0x0812CD24
	push {r4, lr}
	movs r0, #2
	bl sub_08126D1C
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	movs r0, #0
	bl BattleMenu_DrawListPage
	ldrh r1, [r4, #0x12]
	movs r0, #0
	bl sub_081283C4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0812CD44
sub_0812CD44: @ 0x0812CD44
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #2
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r6, [r5, #0x12]
	movs r0, #2
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r0, .L0812CD78
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq .L0812CD7C
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	b .L0812CD84
.L0812CD78: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812CD7C:
	ldrb r0, [r5]
	cmp r0, #3
	bne .L0812CD88
	strh r1, [r4, #0x1e]
.L0812CD84:
	movs r0, #1
	strh r0, [r4, #0x1c]
.L0812CD88:
	ldr r0, .L0812CE0C
	movs r4, #0
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L0812CDEC
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L0812CDCC
	ldr r0, .L0812CE10
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812CDCC:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r1, [r5, #0xa]
	cmp r0, r1
	beq .L0812CDEC
	ldr r0, .L0812CE14
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812CDEC:
	ldrh r0, [r5, #0x12]
	cmp r6, r0
	beq .L0812CE02
	ldrh r1, [r5, #0xc]
	movs r0, #0
	bl BattleMenu_DrawListPage
	ldrh r1, [r5, #0x12]
	movs r0, #0
	bl sub_081283C4
.L0812CE02:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812CE0C: .4byte gUnknown_08000EA4
.L0812CE10: .4byte gUnknown_08000FF0
.L0812CE14: .4byte gUnknown_08001000

	thumb_func_start sub_0812CE18
sub_0812CE18: @ 0x0812CE18
	push {lr}
	movs r0, #1
	bl sub_08128B84
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812CE2C
sub_0812CE2C: @ 0x0812CE2C
	push {r4, lr}
	ldr r4, .L0812CE58
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812CE3C
	movs r1, #0
	bl TextWindow_Close
.L0812CE3C:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812CE48
	movs r1, #0
	bl TextWindow_Close
.L0812CE48:
	bl sub_08128388
	bl BattleMsg_Close
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812CE58: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812CE5C
sub_0812CE5C: @ 0x0812CE5C
	push {lr}
	movs r0, #2
	bl sub_08126D1C
	ldrh r1, [r0, #0x12]
	movs r0, #0
	bl sub_080CAFD0
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812CE78
sub_0812CE78: @ 0x0812CE78
.L0812CE78:
	push {r4, lr}
	ldr r4, .L0812CE9C
	ldr r0, .L0812CEA0
	ldr r1, .L0812CEA4
	bl Task_Create
	str r0, [r4, #0x48]
	movs r0, #0
	str r0, [r4, #0x50]
	str r0, [r4, #0x4c]
	ldr r0, .L0812CEA8
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812CE9C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812CEA0: .4byte gUnknown_08779DB8
.L0812CEA4: .4byte 0x0000FFFF
.L0812CEA8: .4byte 0x00000691

	thumb_func_start sub_0812CEAC
sub_0812CEAC: @ 0x0812CEAC
	push {r4, lr}
	ldr r4, .L0812CED8
	ldr r1, .L0812CEDC
	movs r0, #4
	bl BattleMenu_SetMode
	ldr r1, .L0812CEE0
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0
	bl sub_080C8AAC
	str r0, [r4, #0x4c]
	movs r1, #1
	bl sub_080C8ADC
	movs r0, #0
	str r0, [r4, #0x50]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812CED8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812CEDC: .4byte gUnknown_08124198
.L0812CEE0: .4byte 0x00000691

	thumb_func_start sub_0812CEE4
sub_0812CEE4: @ 0x0812CEE4
	push {lr}
	bl sub_080EA210
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812CEF0
sub_0812CEF0: @ 0x0812CEF0
	push {r4, r5, lr}
	ldr r4, .L0812CF24
	ldr r0, .L0812CF28
	adds r5, r4, r0
	ldrb r1, [r5]
	movs r0, #0
	bl sub_080C8AAC
	str r0, [r4, #0x4c]
	ldrb r1, [r5]
	movs r0, #1
	bl sub_080C8AC4
	str r0, [r4, #0x50]
	ldr r0, [r4, #0x4c]
	movs r1, #1
	bl sub_080C8ADC
	ldr r0, [r4, #0x50]
	movs r1, #1
	bl sub_080C8ADC
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812CF24: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812CF28: .4byte 0x00000691

	thumb_func_start sub_0812CF2C
sub_0812CF2C: @ 0x0812CF2C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r6, .L0812CF90
	movs r0, #0
	strh r0, [r5, #0x1c]
	strh r0, [r5, #0x1e]
	ldr r2, .L0812CF94
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L0812CFA0
	ldrh r1, [r2]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812CFBA
	ldr r0, [r6, #0x4c]
	bl sub_080C8AF4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L0812CF98
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r0, r4, r0
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0812CFB2
	strh r7, [r5, #0x1c]
	ldr r0, [r6, #0x4c]
	movs r1, #0
	bl sub_080C8ADC
	ldr r1, .L0812CF9C
	adds r0, r6, r1
	strb r4, [r0]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x1e]
	movs r0, #0x65
	bl sub_080ECF70
	b .L0812CFCA
	.byte 0x00, 0x00
.L0812CF90: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812CF94: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812CF98: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812CF9C: .4byte 0x00000691
.L0812CFA0:
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r5, #0x1e]
	movs r0, #1
	strh r0, [r5, #0x1c]
	ldr r0, [r6, #0x4c]
	movs r1, #0
	bl sub_080C8ADC
.L0812CFB2:
	movs r0, #0x66
	bl sub_080ECF70
	b .L0812CFCA
.L0812CFBA:
	ldrh r1, [r2]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq .L0812CFCA
	movs r0, #0x64
	bl sub_080ECF70
.L0812CFCA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0812CFD0
sub_0812CFD0: @ 0x0812CFD0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, .L0812D00C
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	ldr r2, .L0812D010
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812D014
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	ldr r0, [r5, #0x4c]
	movs r1, #0
	bl sub_080C8ADC
	ldr r0, [r5, #0x50]
	movs r1, #0
	bl sub_080C8ADC
	movs r0, #0x66
	bl sub_080ECF70
	b .L0812D05C
	.byte 0x00, 0x00
.L0812D00C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D010: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812D014:
	ldrh r1, [r2]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812D04C
	strh r3, [r4, #0x1c]
	ldr r0, [r5, #0x4c]
	movs r1, #0
	bl sub_080C8ADC
	ldr r0, [r5, #0x50]
	movs r1, #0
	bl sub_080C8ADC
	ldr r0, [r5, #0x4c]
	bl sub_080C8AF4
	strh r0, [r4, #0x1e]
	ldr r2, .L0812D048
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x65
	bl sub_080ECF70
	b .L0812D05C
.L0812D048: .4byte 0x00000692
.L0812D04C:
	ldrh r1, [r2]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq .L0812D05C
	movs r0, #0x64
	bl sub_080ECF70
.L0812D05C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812D064
sub_0812D064: @ 0x0812D064
	push {r4, lr}
	ldr r4, .L0812D094
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812D076
	bl Task_End
	movs r0, #0
	str r0, [r4, #0x4c]
.L0812D076:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812D084
	bl Task_End
	movs r0, #0
	str r0, [r4, #0x50]
.L0812D084:
	movs r0, #1
	bl sub_08128B84
	bl BattleMsg_Close
	pop {r4}
	pop {r0}
	bx r0
.L0812D094: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812D098
sub_0812D098: @ 0x0812D098
	push {r4, lr}
	ldr r4, .L0812D0B0
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812D0AA
	bl Task_End
	movs r0, #0
	str r0, [r4, #0x50]
.L0812D0AA:
	pop {r4}
	pop {r0}
	bx r0
.L0812D0B0: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812D0B4
sub_0812D0B4: @ 0x0812D0B4
	push {r4, lr}
	ldr r4, .L0812D0F0
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812D0C6
	bl Task_End
	movs r0, #0
	str r0, [r4, #0x4c]
.L0812D0C6:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812D0D4
	bl Task_End
	movs r0, #0
	str r0, [r4, #0x50]
.L0812D0D4:
	ldr r1, .L0812D0F4
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, .L0812D0F8
	adds r1, r4, r2
	ldrb r1, [r1]
	bl sub_080C363C
	bl sub_080C366C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812D0F0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D0F4: .4byte 0x00000691
.L0812D0F8: .4byte 0x00000692

	thumb_func_start sub_0812D0FC
sub_0812D0FC: @ 0x0812D0FC
.L0812D0FC:
	push {r4, lr}
	lsls r0, r0, #0x18
	ldr r4, .L0812D124
	cmp r0, #0
	bne .L0812D112
	bl sub_080C6FF0
	bl sub_080C7414
	bl sub_080C7218
.L0812D112:
	ldr r0, .L0812D128
	ldr r1, .L0812D12C
	bl Task_Create
	str r0, [r4, #0x40]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812D124: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D128: .4byte gUnknown_08779EC4
.L0812D12C: .4byte 0x0000FFFF

	thumb_func_start sub_0812D130
sub_0812D130: @ 0x0812D130
	push {lr}
	ldr r1, .L0812D158
	ldr r0, .L0812D15C
	str r0, [r1]
	ldr r0, .L0812D160
	str r0, [r1, #4]
	ldr r0, .L0812D164
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L0812D154
.L0812D14C:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L0812D14C
.L0812D154:
	pop {r0}
	bx r0
.L0812D158: .4byte 0x040000D4 @ REG_DMA3SAD
.L0812D15C: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812D160: .4byte 0x06015000 @ VRAM+0x15000
.L0812D164: .4byte 0x840000C0

	thumb_func_start sub_0812D168
sub_0812D168: @ 0x0812D168
	push {r4, lr}
	sub sp, #4
	ldr r4, .L0812D1A8
	movs r0, #1
	str r0, [sp]
	movs r0, #0xb
	movs r1, #1
	movs r2, #8
	movs r3, #6
	bl TextWindow_Create
	str r0, [r4, #0x4c]
	ldr r0, .L0812D1AC
	ldr r1, .L0812D1B0
	bl sub_080C7E24
	ldr r0, .L0812D1B4
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	movs r1, #1
	movs r2, #1
	movs r3, #3
	bl sub_08126928
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L0812D1A8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D1AC: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812D1B0: .4byte gUnknown_08779E9C
.L0812D1B4: .4byte sub_0812D130

	thumb_func_start sub_0812D1B8
sub_0812D1B8: @ 0x0812D1B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r7, .L0812D1F0
	movs r0, #0
	bl sub_08126D1C
	adds r5, r0, #0
	ldrh r6, [r5, #0x18]
	movs r0, #0
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r3, .L0812D1F4
	ldrh r1, [r3]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812D1F8
	ldrh r0, [r5, #0x18]
	b .L0812D204
	.byte 0x00, 0x00
.L0812D1F0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D1F4: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812D1F8:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812D20A
	movs r0, #0xff
.L0812D204:
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x1c]
	b .L0812D262
.L0812D20A:
	ldrb r0, [r5]
	cmp r0, #6
	bne .L0812D240
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812D226
	bl BattleMenu_Reset
	bl BattleMsg_Close
	b .L0812D262
.L0812D226:
	bl sub_080EA210
	ldr r0, .L0812D23C
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
	b .L0812D262
.L0812D23C: .4byte gUnknown_08779EB8
.L0812D240:
	ldrh r2, [r5, #0x18]
	cmp r6, r2
	beq .L0812D262
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812D262
	ldr r0, .L0812D2EC
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L0812D262:
	ldr r0, .L0812D2F0
	movs r1, #0
	str r1, [sp]
	movs r1, #0x5c
	str r1, [sp, #4]
	ldrh r2, [r5, #0x18]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0xc0
	lsls r2, r2, #0xc
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r6, #0
	ldr r0, .L0812D2F4
	mov r8, r0
	movs r7, #0
	movs r1, #8
	add r1, r8
	mov sb, r1
.L0812D296:
	lsls r5, r6, #4
	mov r2, r8
	adds r0, r5, r2
	str r7, [sp]
	movs r1, #0x60
	str r1, [sp, #4]
	lsls r4, r6, #1
	adds r4, r4, r6
	lsls r4, r4, #0x12
	movs r1, #0x80
	lsls r1, r1, #0xd
	adds r4, r4, r1
	lsrs r4, r4, #0x10
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	add r5, sb
	str r7, [sp]
	movs r0, #0x80
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #2
	bls .L0812D296
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812D2EC: .4byte gUnknown_08779EB8
.L0812D2F0: .4byte gUnknown_08000F28
.L0812D2F4: .4byte gUnknown_08777F60

	thumb_func_start sub_0812D2F8
sub_0812D2F8: @ 0x0812D2F8
	push {r4, lr}
	ldr r4, .L0812D324
	movs r0, #0
	bl sub_081269B0
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812D30E
	movs r1, #0
	bl TextWindow_Close
.L0812D30E:
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812D31E
	bl BattleMsg_Close
.L0812D31E:
	pop {r4}
	pop {r0}
	bx r0
.L0812D324: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812D328
sub_0812D328: @ 0x0812D328
	push {r4, lr}
	bl sub_081279D4
	ldr r4, .L0812D344
	ldrh r0, [r4]
	cmp r0, #0x1b
	bne .L0812D348
	movs r0, #0x1e
	bl Field_SetState
	movs r0, #0
	strh r0, [r4, #0x1e]
	b .L0812D34E
	.byte 0x00, 0x00
.L0812D344: .4byte 0x03004550 @ IWRAM+0x4550
.L0812D348:
	movs r0, #1
	bl Field_SetState
.L0812D34E:
	bl sub_080C700C
	bl sub_080C7430
	bl sub_080C7234
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0812D360
sub_0812D360: @ 0x0812D360
	push {lr}
	ldrh r0, [r0, #0x1e]
	cmp r0, #1
	beq .L0812D37C
	cmp r0, #1
	bgt .L0812D372
	cmp r0, #0
	beq .L0812D378
	b .L0812D38C
.L0812D372:
	cmp r0, #2
	beq .L0812D386
	b .L0812D38C
.L0812D378:
	movs r0, #2
	b .L0812D37E
.L0812D37C:
	movs r0, #0
.L0812D37E:
	movs r1, #1
	bl SaveScreen_Open
	b .L0812D38C
.L0812D386:
	movs r0, #1
	bl sub_080CFFE0
.L0812D38C:
	pop {r0}
	bx r0

	thumb_func_start sub_0812D390
sub_0812D390: @ 0x0812D390
.L0812D390:
	push {r4, lr}
	ldr r4, .L0812D3AC
	ldr r0, .L0812D3B0
	ldr r1, .L0812D3B4
	bl Task_Create
	str r0, [r4, #0x48]
	adds r0, #0x24
	movs r1, #0
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812D3AC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D3B0: .4byte gUnknown_0877A078
.L0812D3B4: .4byte 0x0000FFFF

	thumb_func_start sub_0812D3B8
sub_0812D3B8: @ 0x0812D3B8
	push {lr}
	ldr r1, .L0812D3E0
	ldr r0, .L0812D3E4
	str r0, [r1]
	ldr r0, .L0812D3E8
	str r0, [r1, #4]
	ldr r0, .L0812D3EC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L0812D3DC
.L0812D3D4:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L0812D3D4
.L0812D3DC:
	pop {r0}
	bx r0
.L0812D3E0: .4byte 0x040000D4 @ REG_DMA3SAD
.L0812D3E4: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812D3E8: .4byte 0x06015000 @ VRAM+0x15000
.L0812D3EC: .4byte 0x84000180

	thumb_func_start sub_0812D3F0
sub_0812D3F0: @ 0x0812D3F0
	push {r4, lr}
	sub sp, #4
	ldr r4, .L0812D43C
	movs r0, #1
	str r0, [sp]
	movs r0, #8
	movs r1, #1
	movs r2, #0xe
	movs r3, #6
	bl TextWindow_Create
	str r0, [r4, #0x4c]
	ldr r0, .L0812D440
	ldr r1, .L0812D444
	bl sub_080C7E24
	ldr r0, .L0812D448
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #3
	str r0, [sp]
	movs r1, #1
	movs r2, #1
	movs r3, #3
	bl sub_08126928
	ldr r1, .L0812D44C
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L0812D43C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D440: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812D444: .4byte gUnknown_08779FD0
.L0812D448: .4byte sub_0812D3B8
.L0812D44C: .4byte gUnknown_081232AE

	thumb_func_start sub_0812D450
sub_0812D450: @ 0x0812D450
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r7, .L0812D488
	movs r0, #3
	bl sub_08126D1C
	adds r5, r0, #0
	ldrh r6, [r5, #0x18]
	movs r0, #3
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r3, .L0812D48C
	ldrh r1, [r3]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812D490
	ldrh r0, [r5, #0x18]
	b .L0812D49C
	.byte 0x00, 0x00
.L0812D488: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D48C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812D490:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812D4A2
	movs r0, #0xff
.L0812D49C:
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x1c]
	b .L0812D4FE
.L0812D4A2:
	ldrb r0, [r5]
	cmp r0, #6
	bne .L0812D4DC
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812D4C4
	ldr r1, .L0812D4C0
	movs r0, #3
	bl BattleMenu_SetMode
	b .L0812D4FE
	.byte 0x00, 0x00
.L0812D4C0: .4byte gUnknown_081232AE
.L0812D4C4:
	ldr r0, .L0812D4D8
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
	b .L0812D4FE
	.byte 0x00, 0x00
.L0812D4D8: .4byte gUnknown_0877A004
.L0812D4DC:
	ldrh r2, [r5, #0x18]
	cmp r6, r2
	beq .L0812D4FE
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812D4FE
	ldr r0, .L0812D5BC
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L0812D4FE:
	ldr r0, .L0812D5C0
	movs r1, #0
	str r1, [sp]
	movs r1, #0x40
	str r1, [sp, #4]
	ldrh r2, [r5, #0x18]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0xc0
	lsls r2, r2, #0xc
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r7, #0
	ldr r6, .L0812D5C4
	movs r0, #0
	mov r8, r0
	movs r1, #0x18
	adds r1, r1, r6
	mov sb, r1
.L0812D532:
	lsls r5, r7, #5
	adds r0, r5, r6
	mov r2, r8
	str r2, [sp]
	movs r1, #0x44
	str r1, [sp, #4]
	lsls r4, r7, #1
	adds r4, r4, r7
	lsls r4, r4, #0x12
	movs r1, #0x80
	lsls r1, r1, #0xd
	adds r4, r4, r1
	lsrs r4, r4, #0x10
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r0, r6, #0
	adds r0, #8
	adds r0, r5, r0
	mov r2, r8
	str r2, [sp]
	movs r1, #0x64
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r0, r6, #0
	adds r0, #0x10
	adds r0, r5, r0
	mov r1, r8
	str r1, [sp]
	movs r1, #0x84
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	add r5, sb
	mov r2, r8
	str r2, [sp]
	movs r0, #0xa4
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #2
	bls .L0812D532
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0812D5BC: .4byte gUnknown_0877A004
.L0812D5C0: .4byte gUnknown_08000E28
.L0812D5C4: .4byte gUnknown_08777F60

	thumb_func_start sub_0812D5C8
sub_0812D5C8: @ 0x0812D5C8
	push {r4, lr}
	ldr r4, .L0812D5E8
	movs r0, #3
	bl sub_081269B0
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812D5DE
	movs r1, #0
	bl TextWindow_Close
.L0812D5DE:
	bl BattleMenu_Reset
	pop {r4}
	pop {r0}
	bx r0
.L0812D5E8: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812D5EC
sub_0812D5EC: @ 0x0812D5EC
	ldr r0, .L0812D5F8
	ldr r0, [r0, #0x48]
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
	bx lr
.L0812D5F8: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812D5FC
sub_0812D5FC: @ 0x0812D5FC
.L0812D5FC:
	ldr r0, .L0812D608
	ldr r0, [r0, #0x48]
	adds r0, #0x24
	ldrb r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L0812D608: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812D60C
sub_0812D60C: @ 0x0812D60C
	push {lr}
	ldr r1, .L0812D634
	ldr r0, .L0812D638
	str r0, [r1]
	ldr r0, .L0812D63C
	str r0, [r1, #4]
	ldr r0, .L0812D640
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L0812D630
.L0812D628:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L0812D628
.L0812D630:
	pop {r0}
	bx r0
.L0812D634: .4byte 0x040000D4 @ REG_DMA3SAD
.L0812D638: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812D63C: .4byte 0x06015000 @ VRAM+0x15000
.L0812D640: .4byte 0x84000040

	thumb_func_start sub_0812D644
sub_0812D644: @ 0x0812D644
	push {r4, lr}
	sub sp, #4
	ldr r4, .L0812D6A4
	movs r0, #1
	str r0, [sp]
	movs r0, #0xc
	movs r1, #1
	movs r2, #6
	movs r3, #4
	bl TextWindow_Create
	str r0, [r4, #0x4c]
	ldr r0, .L0812D6A8
	ldr r1, .L0812D6AC
	bl sub_080C7E24
	ldr r0, .L0812D6B0
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	movs r1, #1
	movs r2, #1
	movs r3, #2
	bl sub_08126928
	bl sub_080C2B6C
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #3
	bl MenuCursor_SetIndex
	ldr r1, .L0812D6B4
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812D6A4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D6A8: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812D6AC: .4byte gUnknown_0877A010
.L0812D6B0: .4byte sub_0812D60C
.L0812D6B4: .4byte gUnknown_08123374

	thumb_func_start sub_0812D6B8
sub_0812D6B8: @ 0x0812D6B8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r7, .L0812D6FC
	movs r0, #3
	bl sub_08126D1C
	adds r6, r0, #0
	ldrh r5, [r6, #0x18]
	movs r0, #3
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r3, .L0812D700
	ldrh r1, [r3]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812D708
	ldrh r0, [r6, #0x18]
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x1c]
	ldr r1, .L0812D704
	ldrh r0, [r6, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_080C2B84
	b .L0812D77A
	.byte 0x00, 0x00
.L0812D6FC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D700: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812D704: .4byte gUnknown_0877A024
.L0812D708:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812D71A
	movs r0, #0xff
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x1c]
	b .L0812D77A
.L0812D71A:
	ldrb r0, [r6]
	cmp r0, #6
	bne .L0812D758
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812D740
	ldr r1, .L0812D73C
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	b .L0812D77A
.L0812D73C: .4byte gUnknown_08123374
.L0812D740:
	ldr r0, .L0812D754
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
	b .L0812D77A
	.byte 0x00, 0x00
.L0812D754: .4byte gUnknown_0877A01C
.L0812D758:
	ldrh r2, [r6, #0x18]
	cmp r5, r2
	beq .L0812D77A
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812D77A
	ldr r0, .L0812D7D8
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L0812D77A:
	ldr r0, .L0812D7DC
	movs r5, #0
	str r5, [sp]
	movs r1, #0x64
	str r1, [sp, #4]
	ldrh r2, [r6, #0x18]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0xa0
	lsls r2, r2, #0xc
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r4, .L0812D7E0
	str r5, [sp]
	movs r6, #0x6c
	str r6, [sp, #4]
	movs r0, #0xe
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r4, #8
	str r5, [sp]
	str r6, [sp, #4]
	movs r0, #0x1a
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812D7D8: .4byte gUnknown_0877A01C
.L0812D7DC: .4byte gUnknown_08000F00
.L0812D7E0: .4byte gUnknown_08777F60

	thumb_func_start sub_0812D7E4
sub_0812D7E4: @ 0x0812D7E4
	push {lr}
	ldr r1, .L0812D80C
	ldr r0, .L0812D810
	str r0, [r1]
	ldr r0, .L0812D814
	str r0, [r1, #4]
	ldr r0, .L0812D818
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L0812D808
.L0812D800:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L0812D800
.L0812D808:
	pop {r0}
	bx r0
.L0812D80C: .4byte 0x040000D4 @ REG_DMA3SAD
.L0812D810: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812D814: .4byte 0x06015000 @ VRAM+0x15000
.L0812D818: .4byte 0x84000080

	thumb_func_start sub_0812D81C
sub_0812D81C: @ 0x0812D81C
	push {r4, lr}
	sub sp, #4
	ldr r4, .L0812D87C
	movs r0, #1
	str r0, [sp]
	movs r0, #0xb
	movs r1, #1
	movs r2, #8
	movs r3, #4
	bl TextWindow_Create
	str r0, [r4, #0x4c]
	ldr r0, .L0812D880
	ldr r1, .L0812D884
	bl sub_080C7E24
	ldr r0, .L0812D888
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	movs r1, #1
	movs r2, #1
	movs r3, #2
	bl sub_08126928
	bl Settings_GetBattleMsgSpeed
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #3
	bl MenuCursor_SetIndex
	ldr r1, .L0812D88C
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812D87C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D880: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812D884: .4byte gUnknown_0877A028
.L0812D888: .4byte sub_0812D7E4
.L0812D88C: .4byte gUnknown_081233D2

	thumb_func_start sub_0812D890
sub_0812D890: @ 0x0812D890
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r7, .L0812D8D8
	movs r0, #3
	bl sub_08126D1C
	adds r5, r0, #0
	ldrh r6, [r5, #0x18]
	movs r0, #3
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r3, .L0812D8DC
	ldrh r1, [r3]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812D8E4
	ldrh r0, [r5, #0x18]
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x1c]
	ldr r1, .L0812D8E0
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_080C2B4C
	b .L0812D956
.L0812D8D8: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812D8DC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812D8E0: .4byte gUnknown_0877A044
.L0812D8E4:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812D8F6
	movs r0, #0xff
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x1c]
	b .L0812D956
.L0812D8F6:
	ldrb r0, [r5]
	cmp r0, #6
	bne .L0812D934
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812D91C
	ldr r1, .L0812D918
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	b .L0812D956
.L0812D918: .4byte gUnknown_081233D2
.L0812D91C:
	ldr r0, .L0812D930
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
	b .L0812D956
	.byte 0x00, 0x00
.L0812D930: .4byte gUnknown_0877A03C
.L0812D934:
	ldrh r2, [r5, #0x18]
	cmp r6, r2
	beq .L0812D956
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812D956
	ldr r0, .L0812D9E0
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L0812D956:
	ldr r0, .L0812D9E4
	movs r1, #0
	str r1, [sp]
	movs r1, #0x5c
	str r1, [sp, #4]
	ldrh r2, [r5, #0x18]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0xa0
	lsls r2, r2, #0xc
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r6, #0
	ldr r0, .L0812D9E8
	mov r8, r0
	movs r7, #0
	movs r1, #8
	add r1, r8
	mov sb, r1
.L0812D98A:
	lsls r5, r6, #4
	mov r2, r8
	adds r0, r5, r2
	str r7, [sp]
	movs r1, #0x60
	str r1, [sp, #4]
	lsls r4, r6, #1
	adds r4, r4, r6
	lsls r4, r4, #0x12
	movs r1, #0xe0
	lsls r1, r1, #0xc
	adds r4, r4, r1
	lsrs r4, r4, #0x10
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	add r5, sb
	str r7, [sp]
	movs r0, #0x80
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #1
	bls .L0812D98A
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812D9E0: .4byte gUnknown_0877A03C
.L0812D9E4: .4byte gUnknown_08000F28
.L0812D9E8: .4byte gUnknown_08777F60

	thumb_func_start sub_0812D9EC
sub_0812D9EC: @ 0x0812D9EC
	push {lr}
	ldr r1, .L0812DA14
	ldr r0, .L0812DA18
	str r0, [r1]
	ldr r0, .L0812DA1C
	str r0, [r1, #4]
	ldr r0, .L0812DA20
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r0, #0
	bge .L0812DA10
.L0812DA08:
	ldr r0, [r1, #8]
	ands r0, r2
	cmp r0, #0
	bne .L0812DA08
.L0812DA10:
	pop {r0}
	bx r0
.L0812DA14: .4byte 0x040000D4 @ REG_DMA3SAD
.L0812DA18: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812DA1C: .4byte 0x06015000 @ VRAM+0x15000
.L0812DA20: .4byte 0x840000C0

	thumb_func_start sub_0812DA24
sub_0812DA24: @ 0x0812DA24
	push {r4, lr}
	sub sp, #4
	ldr r4, .L0812DA80
	movs r0, #1
	str r0, [sp]
	movs r0, #0xb
	movs r1, #1
	movs r2, #8
	movs r3, #6
	bl TextWindow_Create
	str r0, [r4, #0x4c]
	ldr r0, .L0812DA84
	ldr r1, .L0812DA88
	bl sub_080C7E24
	ldr r0, .L0812DA8C
	movs r1, #1
	bl VBlankTask_AddCounted
	movs r0, #3
	str r0, [sp]
	movs r1, #1
	movs r2, #1
	movs r3, #3
	bl sub_08126928
	bl sub_080C2BA4
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #3
	bl MenuCursor_SetIndex
	ldr r1, .L0812DA90
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L0812DA80: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812DA84: .4byte 0x030000B4 @ IWRAM+0xB4
.L0812DA88: .4byte gUnknown_0877A048
.L0812DA8C: .4byte sub_0812D9EC
.L0812DA90: .4byte gUnknown_08123444

	thumb_func_start sub_0812DA94
sub_0812DA94: @ 0x0812DA94
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r7, .L0812DADC
	movs r0, #3
	bl sub_08126D1C
	adds r5, r0, #0
	ldrh r6, [r5, #0x18]
	movs r0, #3
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r3, .L0812DAE0
	ldrh r1, [r3]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0812DAE8
	ldrh r0, [r5, #0x18]
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x1c]
	ldr r1, .L0812DAE4
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_080C2BCC
	b .L0812DB5A
.L0812DADC: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812DAE0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812DAE4: .4byte gUnknown_0877A070
.L0812DAE8:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812DAFA
	movs r0, #0xff
	strh r0, [r4, #0x1e]
	strh r2, [r4, #0x1c]
	b .L0812DB5A
.L0812DAFA:
	ldrb r0, [r5]
	cmp r0, #6
	bne .L0812DB38
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812DB20
	ldr r1, .L0812DB1C
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #1
	bl BattleMsg_SetDone
	b .L0812DB5A
.L0812DB1C: .4byte gUnknown_08123444
.L0812DB20:
	ldr r0, .L0812DB34
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
	b .L0812DB5A
	.byte 0x00, 0x00
.L0812DB34: .4byte gUnknown_0877A064
.L0812DB38:
	ldrh r2, [r5, #0x18]
	cmp r6, r2
	beq .L0812DB5A
	movs r1, #0xfc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0812DB5A
	ldr r0, .L0812DBE4
	ldrh r1, [r5, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #4
	bl BattleMenu_SetMode
.L0812DB5A:
	ldr r0, .L0812DBE8
	movs r1, #0
	str r1, [sp]
	movs r1, #0x5c
	str r1, [sp, #4]
	ldrh r2, [r5, #0x18]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0x12
	movs r2, #0xd0
	lsls r2, r2, #0xc
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r6, #0
	ldr r0, .L0812DBEC
	mov r8, r0
	movs r7, #0
	movs r1, #8
	add r1, r8
	mov sb, r1
.L0812DB8E:
	lsls r5, r6, #4
	mov r2, r8
	adds r0, r5, r2
	str r7, [sp]
	movs r1, #0x64
	str r1, [sp, #4]
	lsls r4, r6, #1
	adds r4, r4, r6
	lsls r4, r4, #0x12
	movs r1, #0x88
	lsls r1, r1, #0xd
	adds r4, r4, r1
	lsrs r4, r4, #0x10
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	add r5, sb
	str r7, [sp]
	movs r0, #0x84
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_DrawSingle
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #2
	bls .L0812DB8E
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812DBE4: .4byte gUnknown_0877A064
.L0812DBE8: .4byte gUnknown_08000F28
.L0812DBEC: .4byte gUnknown_08777F60

	thumb_func_start sub_0812DBF0
sub_0812DBF0: @ 0x0812DBF0
.L0812DBF0:
	ldr r0, .L0812DBFC
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
.L0812DBFC: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812DC00
sub_0812DC00: @ 0x0812DC00
.L0812DC00:
	ldr r0, .L0812DC0C
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
.L0812DC0C: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812DC10
sub_0812DC10: @ 0x0812DC10
.L0812DC10:
	ldr r0, .L0812DC1C
	ldr r1, .L0812DC20
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.byte 0x00, 0x00
.L0812DC1C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812DC20: .4byte 0x00000692

	thumb_func_start sub_0812DC24
sub_0812DC24: @ 0x0812DC24
.L0812DC24:
	push {r4, lr}
	ldr r4, .L0812DC40
	ldr r0, .L0812DC44
	ldr r1, .L0812DC48
	bl Task_Create
	str r0, [r4, #0x48]
	ldr r0, .L0812DC4C
	adds r4, r4, r0
	movs r0, #0xfe
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
.L0812DC40: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812DC44: .4byte gUnknown_0877A310
.L0812DC48: .4byte 0x0000FFFF
.L0812DC4C: .4byte 0x00000692

	thumb_func_start sub_0812DC50
sub_0812DC50: @ 0x0812DC50
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r4, .L0812DCB0
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r6, r4, r0
	movs r5, #1
	str r5, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r4, #0x4c]
	str r5, [sp]
	movs r0, #0x11
	movs r1, #0
	movs r2, #0xc
	movs r3, #6
	bl TextWindow_Create
	str r0, [r4, #0x50]
	bl sub_081272AC
	movs r3, #0
	ldrh r0, [r6]
	ldr r1, .L0812DCB4
	ldr r2, .L0812DCB8
	adds r6, r4, r2
	cmp r0, r1
	beq .L0812DC9E
.L0812DC90:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r6]
	adds r6, #2
	cmp r0, r1
	bne .L0812DC90
.L0812DC9E:
	cmp r3, #4
	bhi .L0812DCBC
	str r3, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #1
	bl sub_08126928
	b .L0812DCCA
.L0812DCB0: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812DCB4: .4byte 0x0000FFFF
.L0812DCB8: .4byte 0x000002D2
.L0812DCBC:
	movs r0, #5
	str r0, [sp]
	movs r0, #2
	movs r1, #0x10
	movs r2, #1
	bl sub_08126928
.L0812DCCA:
	movs r0, #2
	bl sub_08126D1C
	ldr r1, .L0812DCDC
	strh r1, [r0, #0x1e]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0812DCDC: .4byte 0x0000FFFF

	thumb_func_start sub_0812DCE0
sub_0812DCE0: @ 0x0812DCE0
	push {r4, lr}
	movs r0, #2
	bl sub_08126D1C
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	movs r0, #0
	bl BattleMenu_DrawListPage
	ldrh r1, [r4, #0x12]
	movs r0, #0
	bl sub_081283C4
	bl sub_0812DC00
	ldr r1, [r0]
	movs r0, #2
	bl sub_080D3654
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0812DD0C
sub_0812DD0C: @ 0x0812DD0C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	movs r0, #2
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r7, [r5, #0x12]
	movs r0, #2
	bl sub_08126A08
	movs r0, #0
	strh r0, [r6, #0x1e]
	strh r0, [r6, #0x1c]
	ldr r0, .L0812DD3C
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812DD40
	movs r0, #0x80
	lsls r0, r0, #1
	b .L0812DD6A
	.byte 0x00, 0x00
.L0812DD3C: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812DD40:
	ldrb r0, [r5]
	cmp r0, #3
	bne .L0812DD70
	bl sub_0812DC00
	ldrh r4, [r5, #0x12]
	lsls r4, r4, #2
	adds r4, r4, r0
	bl sub_080C3100
	ldr r1, [r4]
	cmp r1, r0
	bls .L0812DD62
	movs r0, #0x66
	bl sub_080ECF70
	b .L0812DD68
.L0812DD62:
	movs r0, #0xe7
	bl sub_080ECF70
.L0812DD68:
	ldrh r0, [r5, #0x12]
.L0812DD6A:
	strh r0, [r6, #0x1e]
	movs r0, #1
	strh r0, [r6, #0x1c]
.L0812DD70:
	ldr r0, .L0812DE04
	movs r4, #0
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L0812DDD4
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L0812DDB4
	ldr r0, .L0812DE08
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812DDB4:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r1, [r5, #0xa]
	cmp r0, r1
	beq .L0812DDD4
	ldr r0, .L0812DE0C
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812DDD4:
	ldrh r0, [r5, #0x12]
	cmp r7, r0
	beq .L0812DDFA
	bl sub_0812DC00
	ldrh r1, [r5, #0x12]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl sub_080D367C
	ldrh r1, [r5, #0xc]
	movs r0, #0
	bl BattleMenu_DrawListPage
	ldrh r1, [r5, #0x12]
	movs r0, #0
	bl sub_081283C4
.L0812DDFA:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812DE04: .4byte gUnknown_08000EA4
.L0812DE08: .4byte gUnknown_08000FF0
.L0812DE0C: .4byte gUnknown_08001000

	thumb_func_start sub_0812DE10
sub_0812DE10: @ 0x0812DE10
	push {r4, lr}
	ldr r4, .L0812DE3C
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812DE20
	movs r1, #0
	bl TextWindow_Close
.L0812DE20:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812DE2C
	movs r1, #0
	bl TextWindow_Close
.L0812DE2C:
	bl sub_08128388
	bl sub_080D3688
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812DE3C: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812DE40
sub_0812DE40: @ 0x0812DE40
	push {lr}
	adds r2, r0, #0
	ldr r3, .L0812DE5C
	ldrh r1, [r2, #0x1e]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0812DE64
	ldr r0, .L0812DE60
	adds r1, r3, r0
	movs r0, #0xff
	strb r0, [r1]
	b .L0812DE78
	.byte 0x00, 0x00
.L0812DE5C: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812DE60: .4byte 0x00000692
.L0812DE64:
	ldrh r0, [r2, #0x1e]
	lsls r0, r0, #1
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r3, r2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, .L0812DE84
	adds r0, r3, r2
	strb r1, [r0]
.L0812DE78:
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812DE84: .4byte 0x00000692

	thumb_func_start sub_0812DE88
sub_0812DE88: @ 0x0812DE88
	push {r4, lr}
	ldr r4, .L0812DEA4
	ldr r0, .L0812DEA8
	ldr r1, .L0812DEAC
	bl Task_Create
	str r0, [r4, #0x48]
	ldr r0, .L0812DEB0
	adds r4, r4, r0
	movs r0, #0xfe
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
.L0812DEA4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812DEA8: .4byte gUnknown_0877A3B4
.L0812DEAC: .4byte 0x0000FFFF
.L0812DEB0: .4byte 0x00000692

	thumb_func_start sub_0812DEB4
sub_0812DEB4: @ 0x0812DEB4
	push {r4, lr}
	movs r0, #2
	bl sub_08126D1C
	adds r4, r0, #0
	ldrh r1, [r4, #0xc]
	movs r0, #0
	bl BattleMenu_DrawListPage
	ldrh r1, [r4, #0x12]
	movs r0, #0
	bl sub_081283C4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_0812DED4
sub_0812DED4: @ 0x0812DED4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #2
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r6, [r5, #0x12]
	movs r0, #2
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r0, .L0812DF04
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812DF08
	movs r0, #0x80
	lsls r0, r0, #1
	b .L0812DF10
	.byte 0x00, 0x00
.L0812DF04: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812DF08:
	ldrb r0, [r5]
	cmp r0, #3
	bne .L0812DF16
	ldrh r0, [r5, #0x12]
.L0812DF10:
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
.L0812DF16:
	ldr r0, .L0812DF9C
	movs r4, #0
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L0812DF7A
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L0812DF5A
	ldr r0, .L0812DFA0
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812DF5A:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r1, [r5, #0xa]
	cmp r0, r1
	beq .L0812DF7A
	ldr r0, .L0812DFA4
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812DF7A:
	ldrh r0, [r5, #0x12]
	cmp r6, r0
	beq .L0812DF94
	bl sub_0812DC00
	ldrh r1, [r5, #0xc]
	movs r0, #0
	bl BattleMenu_DrawListPage
	ldrh r1, [r5, #0x12]
	movs r0, #0
	bl sub_081283C4
.L0812DF94:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0812DF9C: .4byte gUnknown_08000EA4
.L0812DFA0: .4byte gUnknown_08000FF0
.L0812DFA4: .4byte gUnknown_08001000

	thumb_func_start sub_0812DFA8
sub_0812DFA8: @ 0x0812DFA8
	push {r4, lr}
	ldr r4, .L0812DFD0
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq .L0812DFB8
	movs r1, #0
	bl TextWindow_Close
.L0812DFB8:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0812DFC4
	movs r1, #0
	bl TextWindow_Close
.L0812DFC4:
	bl sub_08128388
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0812DFD0: .4byte 0x0203C200 @ EWRAM+0x3C200

	thumb_func_start sub_0812DFD4
sub_0812DFD4: @ 0x0812DFD4
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r4, .L0812E034
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r6, r4, r0
	movs r5, #1
	str r5, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r4, #0x4c]
	str r5, [sp]
	movs r0, #0x11
	movs r1, #0
	movs r2, #0xc
	movs r3, #6
	bl TextWindow_Create
	str r0, [r4, #0x50]
	bl sub_081272AC
	movs r3, #0
	ldrh r0, [r6]
	ldr r1, .L0812E038
	ldr r2, .L0812E03C
	adds r6, r4, r2
	cmp r0, r1
	beq .L0812E022
.L0812E014:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r6]
	adds r6, #2
	cmp r0, r1
	bne .L0812E014
.L0812E022:
	cmp r3, #4
	bhi .L0812E040
	str r3, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #1
	bl sub_08126928
	b .L0812E04E
.L0812E034: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812E038: .4byte 0x0000FFFF
.L0812E03C: .4byte 0x000002D2
.L0812E040:
	movs r0, #5
	str r0, [sp]
	movs r0, #2
	movs r1, #0x10
	movs r2, #1
	bl sub_08126928
.L0812E04E:
	movs r0, #2
	bl sub_08126D1C
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_0812E05C
sub_0812E05C: @ 0x0812E05C
	push {r4, lr}
	ldr r4, .L0812E078
	ldr r0, .L0812E07C
	ldr r1, .L0812E080
	bl Task_Create
	str r0, [r4, #0x48]
	ldr r0, .L0812E084
	adds r4, r4, r0
	movs r0, #0xfe
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
.L0812E078: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812E07C: .4byte gUnknown_0877A458
.L0812E080: .4byte 0x0000FFFF
.L0812E084: .4byte 0x00000692

	thumb_func_start sub_0812E088
sub_0812E088: @ 0x0812E088
	push {lr}
	ldr r1, .L0812E0A4
	ldr r0, .L0812E0A8
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0xfd
	bhi .L0812E0AC
	lsls r0, r0, #1
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	b .L0812E0B6
.L0812E0A4: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812E0A8: .4byte 0x00000692
.L0812E0AC:
	ldrb r0, [r2]
	movs r2, #0xff
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r0, r1
.L0812E0B6:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0812E0BC
sub_0812E0BC: @ 0x0812E0BC
	push {r4, r5, lr}
	sub sp, #4
	ldr r4, .L0812E110
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r0, #1
	str r0, [sp]
	movs r1, #0
	movs r2, #0xf
	movs r3, #0xa
	bl TextWindow_Create
	str r0, [r4, #0x4c]
	movs r0, #0
	str r0, [r4, #0x50]
	bl sub_081272AC
	movs r3, #0
	ldrh r0, [r5]
	ldr r1, .L0812E114
	ldr r2, .L0812E118
	adds r5, r4, r2
	cmp r0, r1
	beq .L0812E0FC
.L0812E0EE:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r5]
	adds r5, #2
	cmp r0, r1
	bne .L0812E0EE
.L0812E0FC:
	cmp r3, #4
	bhi .L0812E11C
	str r3, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #1
	bl sub_08126928
	b .L0812E12A
	.byte 0x00, 0x00
.L0812E110: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812E114: .4byte 0x0000FFFF
.L0812E118: .4byte 0x000002D2
.L0812E11C:
	movs r0, #5
	str r0, [sp]
	movs r0, #2
	movs r1, #0x10
	movs r2, #1
	bl sub_08126928
.L0812E12A:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0812E134
sub_0812E134: @ 0x0812E134
	push {lr}
	movs r0, #2
	bl sub_08126D1C
	ldrh r1, [r0, #0xc]
	movs r0, #1
	bl BattleMenu_DrawListPage
	pop {r0}
	bx r0

	thumb_func_start sub_0812E148
sub_0812E148: @ 0x0812E148
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #2
	bl sub_08126D1C
	adds r5, r0, #0
	ldrb r6, [r5, #0x12]
	movs r0, #2
	bl sub_08126A08
	movs r0, #0
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x1c]
	ldr r0, .L0812E178
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0812E17C
	movs r0, #0x80
	lsls r0, r0, #1
	b .L0812E184
	.byte 0x00, 0x00
.L0812E178: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0812E17C:
	ldrb r0, [r5]
	cmp r0, #3
	bne .L0812E18A
	ldrh r0, [r5, #0x12]
.L0812E184:
	strh r0, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
.L0812E18A:
	ldr r0, .L0812E204
	movs r4, #0
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	ldrh r2, [r5, #0xe]
	movs r1, #0xd
	muls r1, r2, r1
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
	ldrh r0, [r5, #0xa]
	cmp r0, #5
	bls .L0812E1EE
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	beq .L0812E1CE
	ldr r0, .L0812E208
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812E1CE:
	ldrh r0, [r5, #0xc]
	adds r0, #5
	ldrh r1, [r5, #0xa]
	cmp r0, r1
	beq .L0812E1EE
	ldr r0, .L0812E20C
	str r4, [sp]
	movs r1, #0x74
	str r1, [sp, #4]
	movs r1, #0x43
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_Draw
.L0812E1EE:
	ldrh r0, [r5, #0x12]
	cmp r6, r0
	beq .L0812E1FC
	ldrh r1, [r5, #0xc]
	movs r0, #1
	bl BattleMenu_DrawListPage
.L0812E1FC:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0812E204: .4byte gUnknown_08000EA4
.L0812E208: .4byte gUnknown_08000FF0
.L0812E20C: .4byte gUnknown_08001000

	thumb_func_start sub_0812E210
sub_0812E210: @ 0x0812E210
	push {lr}
	ldr r1, .L0812E228
	ldrh r2, [r0, #0x1e]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r2, r0
	bne .L0812E230
	ldr r0, .L0812E22C
	adds r1, r1, r0
	movs r0, #0xff
	strb r0, [r1]
	b .L0812E236
.L0812E228: .4byte 0x0203C200 @ EWRAM+0x3C200
.L0812E22C: .4byte 0x00000692
.L0812E230:
	ldr r3, .L0812E240
	adds r0, r1, r3
	strb r2, [r0]
.L0812E236:
	movs r0, #2
	bl sub_081269B0
	pop {r0}
	bx r0
.L0812E240: .4byte 0x00000692

	thumb_func_start sub_0812E244
sub_0812E244: @ 0x0812E244
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r5, .L0812E260
	movs r0, #0
	strh r0, [r1, #0x1c]
	ldrb r0, [r5, #1]
	cmp r0, #1
	beq .L0812E296
	cmp r0, #1
	bgt .L0812E264
	cmp r0, #0
	beq .L0812E26E
	b .L0812E2F6
	.byte 0x00, 0x00
.L0812E260: .4byte 0x030065CC @ IWRAM+0x65CC
.L0812E264:
	cmp r0, #2
	beq .L0812E2DC
	cmp r0, #3
	beq .L0812E2F2
	b .L0812E2F6
.L0812E26E:
	movs r1, #0
.L0812E270:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0
	bl Combatant_IsUsed
	cmp r0, #0
	beq .L0812E284
	adds r0, r4, #0
	bl Party_BuildSkillList
.L0812E284:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble .L0812E270
	movs r0, #1
	strb r0, [r5, #1]
	b .L0812E2F6
.L0812E296:
	bl sub_0812E2FC
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0812E2C0
	bl sub_080C84A0
	movs r0, #0xd7
	bl Battle_GetMessage
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
	movs r0, #0xe7
	bl sub_080ECF70
	b .L0812E2D0
.L0812E2C0:
	ldr r0, .L0812E2D8
	movs r1, #0
	bl Menu_ExpandListTemplate
	adds r1, r0, #0
	movs r0, #3
	bl BattleMenu_SetMode
.L0812E2D0:
	movs r0, #2
	strb r0, [r5, #1]
	b .L0812E2F6
	.byte 0x00, 0x00
.L0812E2D8: .4byte gUnknown_08124534
.L0812E2DC:
	bl BattleMsg_IsDone
	cmp r0, #1
	bne .L0812E2F6
	bl BattleMenu_Reset
	bl BattleMsg_Close
	movs r0, #3
	strb r0, [r5, #1]
	b .L0812E2F6
.L0812E2F2:
	movs r0, #1
	strh r0, [r1, #0x1c]
.L0812E2F6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_0812E2FC
sub_0812E2FC: @ 0x0812E2FC
.L0812E2FC:
	push {lr}
	ldr r1, .L0812E330
	movs r0, #0
	strh r0, [r1]
.L0812E304:
	bl sub_0812E3C4
	cmp r0, #0
	blt .L0812E314
	bl sub_0812E4C0
	cmp r0, #0
	bne .L0812E304
.L0812E314:
	bl sub_0812E334
	cmp r0, #0
	blt .L0812E324
	bl sub_0812E400
	cmp r0, #0
	bne .L0812E314
.L0812E324:
	ldr r0, .L0812E330
	movs r1, #0
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0812E330: .4byte 0x030020B4 @ IWRAM+0x20B4

	thumb_func_start sub_0812E334
sub_0812E334: @ 0x0812E334
.L0812E334:
	push {r4, r5, r6, lr}
	ldr r4, .L0812E364
	movs r5, #0
	movs r0, #0x80
	lsls r0, r0, #8
	adds r6, r0, #0
.L0812E340:
	adds r0, r5, #0
	bl Combatant_IsInParty
	cmp r0, #0
	beq .L0812E368
	ldrh r0, [r4, #0x10]
	ands r0, r6
	cmp r0, #0
	bne .L0812E368
	movs r2, #0x18
	ldrsh r1, [r4, r2]
	movs r2, #0x1a
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge .L0812E368
	adds r0, r5, #0
	b .L0812E374
	.byte 0x00, 0x00
.L0812E364: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812E368:
	adds r5, #1
	adds r4, #0x80
	cmp r5, #0xf
	ble .L0812E340
	movs r0, #1
	rsbs r0, r0, #0
.L0812E374:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0812E37C
sub_0812E37C: @ 0x0812E37C
	push {r4, r5, r6, lr}
	ldr r4, .L0812E3AC
	movs r5, #0
	movs r0, #0x80
	lsls r0, r0, #8
	adds r6, r0, #0
.L0812E388:
	adds r0, r5, #0
	bl Combatant_IsInParty
	cmp r0, #0
	beq .L0812E3B0
	ldrh r0, [r4, #0x10]
	ands r0, r6
	cmp r0, #0
	bne .L0812E3B0
	movs r2, #0x1c
	ldrsh r1, [r4, r2]
	movs r2, #0x1e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge .L0812E3B0
	adds r0, r5, #0
	b .L0812E3BC
	.byte 0x00, 0x00
.L0812E3AC: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812E3B0:
	adds r5, #1
	adds r4, #0x80
	cmp r5, #0xf
	ble .L0812E388
	movs r0, #1
	rsbs r0, r0, #0
.L0812E3BC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0812E3C4
sub_0812E3C4: @ 0x0812E3C4
.L0812E3C4:
	push {r4, r5, r6, lr}
	ldr r5, .L0812E3E4
	movs r4, #0
	ldr r0, .L0812E3E8
	adds r6, r0, #0
.L0812E3CE:
	adds r0, r4, #0
	bl Combatant_IsInParty
	cmp r0, #0
	beq .L0812E3EC
	ldrh r0, [r5, #0x10]
	ands r0, r6
	cmp r0, #0
	beq .L0812E3EC
	adds r0, r4, #0
	b .L0812E3F8
.L0812E3E4: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0812E3E8: .4byte 0x0000B3FE
.L0812E3EC:
	adds r4, #1
	adds r5, #0x80
	cmp r4, #0xf
	ble .L0812E3CE
	movs r0, #1
	rsbs r0, r0, #0
.L0812E3F8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0812E400
sub_0812E400: @ 0x0812E400
.L0812E400:
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_080C2C30
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0812E42A
	ldr r4, .L0812E414
	b .L0812E424
	.byte 0x00, 0x00
.L0812E414: .4byte gUnknown_0877A4FC
.L0812E418:
	ldrb r0, [r4]
	bl sub_080C10B4
	cmp r0, #0
	bne .L0812E434
	adds r4, #1
.L0812E424:
	ldrb r0, [r4]
	cmp r0, #0xff
	bne .L0812E418
.L0812E42A:
	bl sub_080F31E0
	cmp r0, #0
	beq .L0812E456
	b .L0812E474
.L0812E434:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldrb r2, [r4]
	movs r1, #0
	bl sub_0812E6C4
	movs r0, #1
	b .L0812E476
.L0812E444:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrb r2, [r4]
	bl sub_0812E688
	movs r0, #1
	b .L0812E476
.L0812E456:
	ldr r4, .L0812E45C
	b .L0812E46E
	.byte 0x00, 0x00
.L0812E45C: .4byte gUnknown_0877A502
.L0812E460:
	ldrb r0, [r4]
	bl sub_0812E558
	adds r1, r0, #0
	cmp r1, #0
	bge .L0812E444
	adds r4, #1
.L0812E46E:
	ldrb r0, [r4]
	cmp r0, #0xff
	bne .L0812E460
.L0812E474:
	movs r0, #0
.L0812E476:
	pop {r4, r5}
	pop {r1}
	bx r1
