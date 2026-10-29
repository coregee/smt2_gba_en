	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_08145F44
sub_08145F44: @ 0x08145F44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r6, .L081460C4
	ldrh r0, [r6]
	cmp r0, #1
	bne .L08145F64
	ldr r0, .L081460C8
	ldr r1, .L081460CC
	bl Task_Create
	movs r0, #0
	strh r0, [r6]
.L08145F64:
	ldr r0, .L081460D0
	movs r5, #0
	str r5, [sp]
	movs r1, #0xbb
	str r1, [sp, #4]
	movs r4, #5
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L081460D4
	str r5, [sp]
	movs r1, #9
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, [r6, #8]
	movs r1, #0x37
	movs r2, #0x39
	movs r3, #0
	bl Baccarat_DrawNumber8
	ldr r0, [r6, #0x10]
	movs r1, #0xd3
	movs r2, #0x20
	movs r3, #0
	bl Baccarat_DrawNumber3
	ldr r0, [r6, #0x14]
	movs r1, #0xd3
	movs r2, #0x39
	movs r3, #0
	bl Baccarat_DrawNumber3
	ldr r0, [r6, #0x18]
	movs r1, #0xd3
	movs r2, #0x52
	movs r3, #0
	bl Baccarat_DrawNumber3
	ldr r1, .L081460D8
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r5, [sp]
	movs r4, #0x3a
	str r4, [sp, #4]
	movs r1, #0x25
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r1, .L081460DC
	movs r3, #0x95
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0x4b
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_08146F44
	ldrb r0, [r6, #4]
	cmp r0, #3
	bls .L08146020
	cmp r0, #0x18
	beq .L08146020
	cmp r0, #0x19
	bne .L0814603C
.L08146020:
	ldr r0, .L081460E0
	movs r1, #0
	str r1, [sp]
	movs r1, #0x68
	str r1, [sp, #4]
	movs r1, #0x3a
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	bl sub_08146EFC
.L0814603C:
	adds r4, r6, #0
	adds r4, #0x32
	ldrb r0, [r4]
	cmp r0, #1
	bne .L0814605E
	ldr r0, .L081460E4
	movs r1, #0
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814605E:
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #1
	bne .L0814606E
	bl sub_08147508
.L0814606E:
	bl sub_08147970
	bl Baccarat_DrawRoad
	movs r7, #0xae
	lsls r7, r7, #2
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #1
	beq .L08146084
	b .L081461E0
.L08146084:
	ldrb r0, [r6, #4]
	cmp r0, #0
	beq .L0814608C
	b .L081461E0
.L0814608C:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L081460AC
	ldr r0, .L081460E8
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L081460AC
	movs r0, #0xac
	lsls r0, r0, #1
	bl Sound_Play
	movs r0, #0x63
	strb r0, [r6, #4]
.L081460AC:
	ldr r2, .L081460E8
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L081460F0
	ldrb r0, [r6, #0x1c]
	cmp r0, #0x1e
	bne .L081460EC
	movs r0, #0x50
	b .L081460EE
	.byte 0x00, 0x00
.L081460C4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081460C8: .4byte gUnknown_0879CA1C
.L081460CC: .4byte 0x0000FFFF
.L081460D0: .4byte gUnknown_08150154
.L081460D4: .4byte gUnknown_08150184
.L081460D8: .4byte gUnknown_0879C820
.L081460DC: .4byte gUnknown_0879C84C
.L081460E0: .4byte gUnknown_081501C4
.L081460E4: .4byte gUnknown_081503FC
.L081460E8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L081460EC:
	subs r0, #0x19
.L081460EE:
	strb r0, [r6, #0x1c]
.L081460F0:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08146108
	ldrb r0, [r6, #0x1c]
	cmp r0, #0x50
	bne .L08146104
	movs r0, #0x1e
	b .L08146106
.L08146104:
	adds r0, #0x19
.L08146106:
	strb r0, [r6, #0x1c]
.L08146108:
	ldr r0, [r6, #8]
	cmp r0, #0
	bne .L08146110
	b .L081462E8
.L08146110:
	ldr r1, .L08146154
	adds r0, r6, r1
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r2, r0
	beq .L08146180
	ldr r0, .L08146158
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L08146160
	ldr r0, .L0814615C
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08146140
	b .L081462E8
.L08146140:
	movs r0, #0xb0
	lsls r0, r0, #1
	bl Sound_Play
	movs r0, #1
	strb r0, [r6, #4]
	ldrb r0, [r6, #0x1c]
	movs r1, #0xa
	b .L081461D2
	.byte 0x00, 0x00
.L08146154: .4byte 0x00000266
.L08146158: .4byte 0x030031D0 @ IWRAM+0x31D0
.L0814615C: .4byte 0x03003964 @ IWRAM+0x3964
.L08146160:
	ldr r0, .L0814617C
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0814616E
	b .L081462E8
.L0814616E:
	movs r0, #0xb0
	lsls r0, r0, #1
	bl Sound_Play
	movs r0, #1
	b .L081461CC
	.byte 0x00, 0x00
.L0814617C: .4byte 0x03003964 @ IWRAM+0x3964
.L08146180:
	ldr r0, .L081461AC
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L081461B4
	ldr r0, .L081461B0
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0814619A
	b .L081462E8
.L0814619A:
	movs r0, #0xb0
	lsls r0, r0, #1
	bl Sound_Play
	movs r0, #0x18
	strb r0, [r6, #4]
	ldrb r0, [r6, #0x1c]
	movs r1, #0xa
	b .L081461D2
.L081461AC: .4byte 0x030031D0 @ IWRAM+0x31D0
.L081461B0: .4byte 0x03003964 @ IWRAM+0x3964
.L081461B4:
	ldr r0, .L081461DC
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L081461C2
	b .L081462E8
.L081461C2:
	movs r0, #0xb0
	lsls r0, r0, #1
	bl Sound_Play
	movs r0, #0x18
.L081461CC:
	strb r0, [r6, #4]
	ldrb r0, [r6, #0x1c]
	movs r1, #1
.L081461D2:
	movs r2, #0
	bl Baccarat_ChangeBet
	b .L081462E8
	.byte 0x00, 0x00
.L081461DC: .4byte 0x03003964 @ IWRAM+0x3964
.L081461E0:
	ldrb r0, [r6, #4]
	cmp r0, #3
	beq .L081461E8
	b .L081462E8
.L081461E8:
	ldr r2, .L08146218
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08146204
	adds r0, r6, #0
	adds r0, #0x37
	ldrb r0, [r0]
	cmp r0, #5
	bls .L08146204
	movs r0, #4
	strb r0, [r6, #4]
.L08146204:
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L08146220
	ldrb r0, [r6, #0x1c]
	cmp r0, #0x1e
	bne .L0814621C
	movs r0, #0x50
	b .L0814621E
.L08146218: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0814621C:
	subs r0, #0x19
.L0814621E:
	strb r0, [r6, #0x1c]
.L08146220:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08146238
	ldrb r0, [r6, #0x1c]
	cmp r0, #0x50
	bne .L08146234
	movs r0, #0x1e
	b .L08146236
.L08146234:
	adds r0, #0x19
.L08146236:
	strb r0, [r6, #0x1c]
.L08146238:
	ldr r0, .L08146284
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L08146290
	ldr r1, [r6, #8]
	ldr r0, .L08146288
	cmp r1, r0
	bls .L0814626A
	ldr r0, .L0814628C
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0814626A
	movs r0, #0xb0
	lsls r0, r0, #1
	bl Sound_Play
	ldrb r0, [r6, #0x1c]
	movs r1, #0xa
	movs r2, #0
	bl Baccarat_ChangeBet
.L0814626A:
	ldr r0, .L0814628C
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L081462E8
	movs r0, #0xb0
	lsls r0, r0, #1
	bl Sound_Play
	ldrb r0, [r6, #0x1c]
	movs r1, #0xa
	b .L081462CC
.L08146284: .4byte 0x030031D0 @ IWRAM+0x31D0
.L08146288: .4byte 0x000003E7
.L0814628C: .4byte 0x03003964 @ IWRAM+0x3964
.L08146290:
	ldr r0, [r6, #8]
	cmp r0, #0x63
	bls .L081462B4
	ldr r0, .L081462FC
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L081462B4
	movs r0, #0xb0
	lsls r0, r0, #1
	bl Sound_Play
	ldrb r0, [r6, #0x1c]
	movs r1, #1
	movs r2, #0
	bl Baccarat_ChangeBet
.L081462B4:
	ldr r0, .L081462FC
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L081462E8
	movs r0, #0xb0
	lsls r0, r0, #1
	bl Sound_Play
	ldrb r0, [r6, #0x1c]
	movs r1, #1
.L081462CC:
	movs r2, #1
	bl Baccarat_ChangeBet
	ldr r0, [r6, #0x10]
	cmp r0, #0
	bne .L081462E8
	ldr r0, [r6, #0x18]
	cmp r0, #0
	bne .L081462E8
	ldr r0, [r6, #0x14]
	cmp r0, #0
	bne .L081462E8
	movs r0, #2
	strb r0, [r6, #4]
.L081462E8:
	ldrb r0, [r6, #4]
	cmp r0, #0x63
	bls .L081462F2
	bl .L08146EEC
.L081462F2:
	lsls r0, r0, #2
	ldr r1, .L08146300
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L081462FC: .4byte 0x03003964 @ IWRAM+0x3964
.L08146300: .4byte gUnknown_08146304
	.global gUnknown_08146304
gUnknown_08146304:
.L08146304: @ jump table
	.4byte .L08146494
	.4byte .L081464BA
	.4byte .L081464C2
	.4byte .L081464CA
	.4byte .L08146558
	.4byte .L08146594
	.4byte .L08146644
	.4byte .L0814664C
	.4byte .L081466BE
	.4byte .L08146728
	.4byte .L08146780
	.4byte .L081467B4
	.4byte .L08146808
	.4byte .L08146890
	.4byte .L081468E4
	.4byte .L0814690C
	.4byte .L0814691E
	.4byte .L08146A86
	.4byte .L08146B20
	.4byte .L08146B48
	.4byte .L08146BA0
	.4byte .L08146C44
	.4byte .L08146D30
	.4byte .L08146D36
	.4byte .L08146D3C
	.4byte .L08146DE4
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146EEC
	.4byte .L08146E94
.L08146494:
	ldr r5, .L081464A8
	adds r1, r6, r5
	ldrb r0, [r1]
	cmp r0, #0x28
	bhi .L081464AC
	adds r0, #1
	strb r0, [r1]
	bl .L08146EEC
	.byte 0x00, 0x00
.L081464A8: .4byte 0x000002B9
.L081464AC:
	movs r7, #0xae
	lsls r7, r7, #2
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
	bl .L08146EEC
.L081464BA:
	bl sub_0814746C
	bl .L08146EEC
.L081464C2:
	bl sub_081473DC
	bl .L08146EEC
.L081464CA:
	adds r4, r6, #0
	adds r4, #0x24
	ldrb r0, [r4]
	cmp r0, #0xc
	bls .L081464EC
	ldr r0, .L08146548
	movs r1, #0
	str r1, [sp]
	movs r1, #0xbb
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081464EC:
	ldrb r0, [r4]
	cmp r0, #0x18
	bls .L081464F6
	movs r0, #0
	strb r0, [r4]
.L081464F6:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r1, r6, #0
	adds r1, #0x37
	ldrb r0, [r1]
	cmp r0, #6
	bls .L0814650A
	bl .L08146EEC
.L0814650A:
	movs r4, #0
	ldr r0, .L0814654C
	mov r8, r0
	mov sb, r4
	adds r2, r1, #0
	movs r5, #1
	ldr r3, .L08146550
.L08146518:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r6, r0
	mov r7, r8
	adds r1, r0, r7
	strb r5, [r1]
	adds r1, r0, r3
	mov r7, sb
	strb r7, [r1]
	ldr r1, .L08146554
	adds r0, r0, r1
	movs r1, #0xfc
	strh r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls .L08146518
	bl .L08146EEC
.L08146548: .4byte gUnknown_0815016C
.L0814654C: .4byte 0x0000026E
.L08146550: .4byte 0x0000026F
.L08146554: .4byte 0x00000266
.L08146558:
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r6, r2
	movs r1, #0
	strb r1, [r0]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, .L0814658C
	adds r0, r6, r4
	strb r1, [r0]
	ldr r7, .L08146590
	adds r0, r6, r7
	strb r1, [r0]
	movs r0, #1
	strb r0, [r5]
	movs r0, #5
	strb r0, [r6, #4]
	movs r0, #0xad
	lsls r0, r0, #1
	bl Sound_Play
	bl .L08146EEC
	.byte 0x00, 0x00
.L0814658C: .4byte 0x00000255
.L08146590: .4byte 0x0000024D
.L08146594:
	ldr r1, .L081465C4
	adds r0, r6, r1
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r2, r0
	bne .L081465C8
	adds r1, r6, #0
	adds r1, #0x35
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	bl Sound_Play
	movs r0, #6
	strb r0, [r6, #4]
	bl .L08146EEC
	.byte 0x00, 0x00
.L081465C4: .4byte 0x0000028A
.L081465C8:
	adds r4, r6, #0
	adds r4, #0x35
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r6, r0
	ldr r5, .L0814663C
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r6, r0
	ldr r7, .L08146640
	adds r2, r0, r7
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r3, [r2]
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r1, r0
	bge .L08146604
	bl .L08146EEC
.L08146604:
	subs r0, r3, #6
	strh r0, [r2]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r6, r0
	ldr r1, .L08146640
	adds r2, r0, r1
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r5, #0
	ldrsh r1, [r2, r5]
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r1, r0
	ble .L0814662E
	bl .L08146EEC
.L0814662E:
	strh r3, [r2]
	movs r0, #0xbe
	lsls r0, r0, #1
	bl Sound_Play
	bl .L08146ED0
.L0814663C: .4byte 0x0000026E
.L08146640: .4byte 0x00000266
.L08146644:
	bl Baccarat_DealCard
	bl .L08146EEC
.L0814664C:
	ldr r0, [r6, #0x10]
	cmp r0, #0
	beq .L08146676
	ldr r1, [r6, #0x14]
	cmp r1, #0
	beq .L08146668
	adds r1, r6, #0
	adds r1, #0x2f
	movs r0, #0
	strb r0, [r1]
	subs r1, #0xf
	movs r0, #1
	strb r0, [r1]
	b .L0814666E
.L08146668:
	adds r0, r6, #0
	adds r0, #0x2f
	strb r1, [r0]
.L0814666E:
	movs r0, #8
	strb r0, [r6, #4]
	bl .L08146EEC
.L08146676:
	ldr r1, [r6, #0x14]
	cmp r1, #0
	beq .L08146692
	ldr r0, [r6, #0x18]
	cmp r0, #0
	bne .L0814669C
	adds r1, r6, #0
	adds r1, #0x2f
	movs r0, #2
	strb r0, [r1]
	movs r0, #9
	strb r0, [r6, #4]
	bl .L08146EEC
.L08146692:
	ldr r0, [r6, #0x18]
	cmp r0, #0
	bne .L0814669C
	bl .L08146EEC
.L0814669C:
	cmp r1, #0
	beq .L081466AE
	adds r0, r6, #0
	adds r0, #0x20
	movs r1, #1
	strb r1, [r0]
	adds r0, #0xf
	strb r1, [r0]
	b .L081466B6
.L081466AE:
	adds r1, r6, #0
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
.L081466B6:
	movs r0, #0xa
	strb r0, [r6, #4]
	bl .L08146EEC
.L081466BE:
	adds r0, r6, #0
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #3
	beq .L081466CA
	b .L08146B52
.L081466CA:
	bl sub_08147820
	ldr r2, .L08146718
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L081466E6
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L081466EA
.L081466E6:
	movs r0, #0xb
	strb r0, [r6, #4]
.L081466EA:
	ldr r2, .L0814671C
	ldr r1, .L08146720
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r3, .L08146724
	adds r1, r6, r3
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0xa
	bl __modsi3
	adds r0, #1
	movs r4, #0x95
	lsls r4, r4, #2
	adds r1, r6, r4
	strb r0, [r1]
	bl .L08146EEC
	.byte 0x00, 0x00
.L08146718: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0814671C: .4byte gUnknown_0879C91C
.L08146720: .4byte 0x00000265
.L08146724: .4byte 0x0000027D
.L08146728:
	adds r0, r6, #0
	adds r0, #0x35
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #4
	beq .L0814673A
	bl sub_0814760C
	b .L0814673E
.L0814673A:
	movs r0, #0xc
	strb r0, [r6, #4]
.L0814673E:
	ldrb r0, [r4]
	cmp r0, #3
	beq .L08146748
	bl .L08146EEC
.L08146748:
	ldr r2, .L08146774
	ldr r5, .L08146778
	adds r0, r6, r5
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r7, .L0814677C
	adds r1, r6, r7
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0xa
	bl __modsi3
	adds r0, #1
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	b .L08146EEC
	.byte 0x00, 0x00
.L08146774: .4byte gUnknown_0879C91C
.L08146778: .4byte 0x00000265
.L0814677C: .4byte 0x0000027D
.L08146780:
	adds r0, r6, #0
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #2
	beq .L0814678C
	b .L08146B52
.L0814678C:
	bl sub_08147820
	ldr r2, .L081467B0
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L081467AA
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L081467AA
	b .L08146EEC
.L081467AA:
	movs r0, #0xb
	strb r0, [r6, #4]
	b .L08146EEC
.L081467B0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L081467B4:
	adds r0, r6, #0
	adds r0, #0x35
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #4
	beq .L081467C6
	bl sub_0814760C
	b .L081467CA
.L081467C6:
	movs r0, #0xc
	strb r0, [r6, #4]
.L081467CA:
	ldrb r0, [r4]
	cmp r0, #3
	beq .L081467D2
	b .L08146EEC
.L081467D2:
	ldr r2, .L081467FC
	ldr r3, .L08146800
	adds r0, r6, r3
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r4, .L08146804
	adds r1, r6, r4
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0xa
	bl __modsi3
	adds r0, #1
	movs r5, #0x95
	lsls r5, r5, #2
	adds r1, r6, r5
	strb r0, [r1]
	b .L08146EEC
.L081467FC: .4byte gUnknown_0879C91C
.L08146800: .4byte 0x00000265
.L08146804: .4byte 0x0000027D
.L08146808:
	ldr r2, .L08146854
	ldr r7, .L08146858
	adds r0, r6, r7
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r3, .L0814685C
	adds r1, r6, r3
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0xa
	bl __modsi3
	adds r2, r0, #1
	movs r4, #0x93
	lsls r4, r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	movs r5, #0x95
	lsls r5, r5, #2
	adds r0, r6, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #8
	bgt .L08146846
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	ble .L08146860
.L08146846:
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne .L08146850
	b .L08146D16
.L08146850:
	b .L08146A80
	.byte 0x00, 0x00
.L08146854: .4byte gUnknown_0879C91C
.L08146858: .4byte 0x00000271
.L0814685C: .4byte 0x00000289
.L08146860:
	cmp r1, #6
	ble .L08146878
	adds r1, r6, #0
	adds r1, #0x35
	movs r0, #5
	strb r0, [r1]
	ldr r7, .L08146874
	adds r1, r6, r7
	strb r0, [r1]
	b .L08146A56
.L08146874: .4byte 0x00000255
.L08146878:
	cmp r1, #0
	bge .L0814687E
	b .L08146EEC
.L0814687E:
	ldr r1, .L0814688C
	adds r0, r6, r1
	movs r1, #4
	strb r1, [r0]
	movs r0, #0xd
	strb r0, [r6, #4]
	b .L08146EEC
.L0814688C: .4byte 0x00000255
.L08146890:
	ldr r2, .L081468AC
	adds r0, r6, r2
	movs r3, #0xa6
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0
	ldrsh r2, [r0, r4]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r2, r0
	bne .L081468B0
	movs r0, #0xe
	strb r0, [r6, #4]
	b .L08146EEC
.L081468AC: .4byte 0x00000296
.L081468B0:
	adds r3, r6, #0
	adds r3, #0x35
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r6, r0
	ldr r7, .L081468DC
	adds r0, r0, r7
	movs r1, #1
	strb r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r6, r0
	ldr r1, .L081468E0
	adds r2, r0, r1
	movs r4, #0x9a
	lsls r4, r4, #2
	adds r0, r0, r4
	b .L08146AD2
.L081468DC: .4byte 0x0000026E
.L081468E0: .4byte 0x00000266
.L081468E4:
	bl sub_08147820
	ldr r2, .L08146908
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08146902
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08146902
	b .L08146EEC
.L08146902:
	movs r0, #0xf
	strb r0, [r6, #4]
	b .L08146EEC
.L08146908: .4byte 0x030031B8 @ IWRAM+0x31B8
.L0814690C:
	adds r0, r6, #0
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #4
	bne .L08146918
	b .L08146B52
.L08146918:
	movs r0, #0x10
	strb r0, [r6, #4]
	b .L08146EEC
.L0814691E:
	ldr r2, .L08146970
	ldr r7, .L08146974
	adds r0, r6, r7
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r3, .L08146978
	adds r1, r6, r3
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r3, [r1]
	ldr r4, .L0814697C
	adds r1, r6, r4
	ldrb r1, [r1]
	adds r1, r1, r2
	adds r0, r0, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0xa
	bl __modsi3
	adds r0, #1
	movs r5, #0x95
	lsls r5, r5, #2
	adds r1, r6, r5
	strb r0, [r1]
	subs r7, #0x19
	adds r0, r6, r7
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bls .L08146964
	b .L08146EEC
.L08146964:
	lsls r0, r0, #2
	ldr r1, .L08146980
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L08146970: .4byte gUnknown_0879C91C
.L08146974: .4byte 0x00000265
.L08146978: .4byte 0x0000027D
.L0814697C: .4byte 0x00000295
.L08146980: .4byte gUnknown_08146984
	.global gUnknown_08146984
gUnknown_08146984:
.L08146984: @ jump table
	.4byte .L08146A4E
	.4byte .L081469AC
	.4byte .L081469B8
	.4byte .L081469C4
	.4byte .L081469F0
	.4byte .L08146A10
	.4byte .L08146A3C
	.4byte .L08146A70
	.4byte .L08146A80
	.4byte .L08146A80
.L081469AC:
	ldr r2, .L081469B4
	adds r0, r6, r2
	b .L08146A52
	.byte 0x00, 0x00
.L081469B4: .4byte 0x0000024D
.L081469B8:
	ldr r3, .L081469C0
	adds r0, r6, r3
	b .L08146A52
	.byte 0x00, 0x00
.L081469C0: .4byte 0x0000024D
.L081469C4:
	movs r4, #0x95
	lsls r4, r4, #2
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bgt .L081469E0
	ldr r5, .L081469DC
	adds r0, r6, r5
	b .L08146A52
	.byte 0x00, 0x00
.L081469DC: .4byte 0x0000024D
.L081469E0:
	ldr r7, .L081469EC
	adds r0, r6, r7
	movs r1, #5
	strb r1, [r0]
	b .L08146D16
	.byte 0x00, 0x00
.L081469EC: .4byte 0x0000024D
.L081469F0:
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls .L08146A04
	b .L08146D16
.L08146A04:
	ldr r2, .L08146A0C
	adds r0, r6, r2
	b .L08146A52
	.byte 0x00, 0x00
.L08146A0C: .4byte 0x0000024D
.L08146A10:
	movs r3, #0x95
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi .L08146A2C
	ldr r4, .L08146A28
	adds r0, r6, r4
	b .L08146A52
.L08146A28: .4byte 0x0000024D
.L08146A2C:
	ldr r5, .L08146A38
	adds r0, r6, r5
	movs r1, #5
	strb r1, [r0]
	b .L08146D16
	.byte 0x00, 0x00
.L08146A38: .4byte 0x0000024D
.L08146A3C:
	movs r7, #0x95
	lsls r7, r7, #2
	adds r0, r6, r7
	ldrb r0, [r0]
	subs r0, #7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi .L08146A60
.L08146A4E:
	ldr r1, .L08146A5C
	adds r0, r6, r1
.L08146A52:
	movs r1, #4
	strb r1, [r0]
.L08146A56:
	movs r0, #0x11
	strb r0, [r6, #4]
	b .L08146EEC
.L08146A5C: .4byte 0x0000024D
.L08146A60:
	ldr r2, .L08146A6C
	adds r0, r6, r2
	movs r1, #5
	strb r1, [r0]
	b .L08146D16
	.byte 0x00, 0x00
.L08146A6C: .4byte 0x0000024D
.L08146A70:
	ldr r3, .L08146A7C
	adds r0, r6, r3
	movs r1, #5
	strb r1, [r0]
	b .L08146D16
	.byte 0x00, 0x00
.L08146A7C: .4byte 0x0000024D
.L08146A80:
	movs r0, #0x15
	strb r0, [r6, #4]
	b .L08146EEC
.L08146A86:
	ldr r4, .L08146AA4
	adds r0, r6, r4
	movs r5, #0xa9
	lsls r5, r5, #2
	adds r1, r6, r5
	movs r7, #0
	ldrsh r2, [r0, r7]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r2, r0
	bne .L08146AA8
	movs r0, #0x12
	strb r0, [r6, #4]
	b .L08146EEC
	.byte 0x00, 0x00
.L08146AA4: .4byte 0x000002A2
.L08146AA8:
	adds r3, r6, #0
	adds r3, #0x35
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r6, r0
	ldr r4, .L08146B18
	adds r0, r0, r4
	movs r1, #1
	strb r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r6, r0
	ldr r5, .L08146B1C
	adds r2, r0, r5
	movs r7, #0x9a
	lsls r7, r7, #2
	adds r0, r0, r7
.L08146AD2:
	ldrh r4, [r2]
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r1, r0
	bge .L08146AE2
	b .L08146EEC
.L08146AE2:
	subs r0, r4, #6
	strh r0, [r2]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r6, r0
	ldr r1, .L08146B1C
	adds r2, r0, r1
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldrh r3, [r0]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	ble .L08146B0A
	b .L08146EEC
.L08146B0A:
	strh r3, [r2]
	movs r0, #0xbe
	lsls r0, r0, #1
	bl Sound_Play
	b .L08146EEC
	.byte 0x00, 0x00
.L08146B18: .4byte 0x0000026E
.L08146B1C: .4byte 0x00000266
.L08146B20:
	bl sub_08147820
	ldr r2, .L08146B44
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08146B3E
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08146B3E
	b .L08146EEC
.L08146B3E:
	movs r0, #0x13
	strb r0, [r6, #4]
	b .L08146EEC
.L08146B44: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08146B48:
	adds r0, r6, #0
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #5
	bne .L08146B58
.L08146B52:
	bl sub_0814760C
	b .L08146EEC
.L08146B58:
	ldr r2, .L08146B90
	ldr r7, .L08146B94
	adds r0, r6, r7
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r3, .L08146B98
	adds r1, r6, r3
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r3, [r1]
	ldr r4, .L08146B9C
	adds r1, r6, r4
	ldrb r1, [r1]
	adds r1, r1, r2
	adds r0, r0, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0xa
	bl __modsi3
	adds r0, #1
	movs r5, #0x93
	lsls r5, r5, #2
	adds r1, r6, r5
	strb r0, [r1]
	b .L08146D16
	.byte 0x00, 0x00
.L08146B90: .4byte gUnknown_0879C91C
.L08146B94: .4byte 0x00000271
.L08146B98: .4byte 0x00000289
.L08146B9C: .4byte 0x000002A1
.L08146BA0:
	bl Baccarat_RecordRoad
	movs r7, #0x93
	lsls r7, r7, #2
	adds r0, r6, r7
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	ble .L08146BE8
	ldr r3, .L08146BE0
	adds r0, r6, r3
	movs r2, #1
	strb r2, [r0]
	ldr r4, .L08146BE4
	adds r0, r6, r4
	movs r1, #2
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08146C30
	adds r0, r6, #0
	adds r0, #0x30
	strb r2, [r0]
	b .L08146C36
	.byte 0x00, 0x00
.L08146BE0: .4byte 0x0000024D
.L08146BE4: .4byte 0x00000255
.L08146BE8:
	cmp r2, r0
	bge .L08146C1C
	ldr r5, .L08146C0C
	adds r0, r6, r5
	movs r2, #2
	strb r2, [r0]
	ldr r7, .L08146C10
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	cmp r1, #1
	bne .L08146C14
	adds r0, #1
	b .L08146C34
	.byte 0x00, 0x00
.L08146C0C: .4byte 0x0000024D
.L08146C10: .4byte 0x00000255
.L08146C14:
	adds r0, r6, #0
	adds r0, #0x30
	strb r2, [r0]
	b .L08146C36
.L08146C1C:
	cmp r2, r0
	beq .L08146C22
	b .L08146EEC
.L08146C22:
	ldr r1, .L08146C3C
	adds r0, r6, r1
	movs r1, #3
	strb r1, [r0]
	ldr r2, .L08146C40
	adds r0, r6, r2
	strb r1, [r0]
.L08146C30:
	adds r0, r6, #0
	adds r0, #0x30
.L08146C34:
	strb r1, [r0]
.L08146C36:
	movs r0, #0x16
	strb r0, [r6, #4]
	b .L08146EEC
.L08146C3C: .4byte 0x00000255
.L08146C40: .4byte 0x0000024D
.L08146C44:
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	ble .L08146CA2
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0xb
	bhi .L08146C80
	ldr r0, .L08146C7C
	movs r1, #0
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0x24
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L08146C98
	.byte 0x00, 0x00
.L08146C7C: .4byte gUnknown_08150254
.L08146C80:
	ldr r0, .L08146CD8
	movs r1, #0
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0x24
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08146C98:
	ldrb r0, [r4]
	cmp r0, #0x18
	bls .L08146CA2
	movs r0, #0
	strb r0, [r4]
.L08146CA2:
	movs r4, #0x95
	lsls r4, r4, #2
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	ble .L08146D02
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0xb
	bhi .L08146CE0
	ldr r0, .L08146CDC
	movs r1, #0
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0x4a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L08146CF8
.L08146CD8: .4byte gUnknown_081502E4
.L08146CDC: .4byte gUnknown_08150254
.L08146CE0:
	ldr r0, .L08146D1C
	movs r1, #0
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0x4a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08146CF8:
	ldrb r0, [r4]
	cmp r0, #0x18
	bls .L08146D02
	movs r0, #0
	strb r0, [r4]
.L08146D02:
	adds r2, r6, #0
	adds r2, #0x43
	ldrb r0, [r2]
	cmp r0, #0x54
	bne .L08146D24
	movs r0, #0
	strb r0, [r2]
	ldr r0, .L08146D20
	bl Sound_Play
.L08146D16:
	movs r0, #0x14
	strb r0, [r6, #4]
	b .L08146EEC
.L08146D1C: .4byte gUnknown_081502E4
.L08146D20: .4byte 0x00000181
.L08146D24:
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	b .L08146E7A
.L08146D30:
	bl Baccarat_ShowResult
	b .L08146EEC
.L08146D36:
	bl Baccarat_CountUpCoins
	b .L08146EEC
.L08146D3C:
	movs r4, #2
	movs r5, #0x24
	adds r5, r5, r6
	mov r8, r5
.L08146D44:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r1, r6, r0
	ldr r7, .L08146DD4
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08146D94
	ldr r0, .L08146DD8
	mov sb, r0
	adds r2, r1, r0
	ldr r3, .L08146DDC
	adds r5, r1, r3
	ldrh r3, [r2]
	movs r7, #0
	ldrsh r1, [r2, r7]
	movs r7, #0
	ldrsh r0, [r5, r7]
	cmp r1, r0
	beq .L08146D72
	subs r0, r3, #2
	strh r0, [r2]
.L08146D72:
	adds r0, r6, #0
	adds r0, #0x35
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r6, r0
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne .L08146D94
	movs r0, #0x19
	strb r0, [r6, #4]
.L08146D94:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls .L08146D44
	mov r4, r8
	ldrb r0, [r4]
	cmp r0, #0xc
	bls .L08146DBE
	ldr r0, .L08146DE0
	movs r1, #0
	str r1, [sp]
	movs r1, #0xbb
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08146DBE:
	mov r5, r8
	ldrb r0, [r5]
	cmp r0, #0x18
	bls .L08146DCA
	movs r0, #0
	strb r0, [r5]
.L08146DCA:
	mov r7, r8
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	b .L08146EEC
.L08146DD4: .4byte 0x0000026F
.L08146DD8: .4byte 0x00000266
.L08146DDC: .4byte 0x0000026A
.L08146DE0: .4byte gUnknown_0815016C
.L08146DE4:
	movs r4, #0
	movs r0, #0x24
	adds r0, r0, r6
	mov r8, r0
	ldr r1, .L08146E84
	mov sb, r1
	mov ip, r4
.L08146DF2:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r1, r6, r0
	ldr r2, .L08146E88
	adds r0, r1, r2
	ldrb r3, [r0]
	cmp r3, #1
	bne .L08146E44
	ldr r5, .L08146E8C
	mov sl, r5
	add r1, sl
	ldrh r2, [r1]
	movs r7, #0
	ldrsh r0, [r1, r7]
	mov r7, sb
	asrs r5, r7, #0x10
	cmp r0, r5
	blt .L08146E1C
	subs r0, r2, #4
	strh r0, [r1]
.L08146E1C:
	adds r2, r6, #0
	adds r2, #0x35
	ldrb r0, [r2]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r6, r1
	add r1, sl
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	bgt .L08146E44
	mov r0, ip
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x37
	mov r1, ip
	strb r1, [r0]
	strb r3, [r6, #4]
.L08146E44:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls .L08146DF2
	mov r4, r8
	ldrb r0, [r4]
	cmp r0, #0xc
	bls .L08146E6E
	ldr r0, .L08146E90
	movs r1, #0
	str r1, [sp]
	movs r1, #0xbb
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08146E6E:
	ldrb r0, [r4]
	cmp r0, #0x18
	bls .L08146E78
	movs r0, #0
	strb r0, [r4]
.L08146E78:
	mov r2, r8
.L08146E7A:
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b .L08146EEC
	.byte 0x00, 0x00
.L08146E84: .4byte 0xFFE20000
.L08146E88: .4byte 0x0000026F
.L08146E8C: .4byte 0x00000266
.L08146E90: .4byte gUnknown_0815016C
.L08146E94:
	adds r5, r6, #0
	adds r5, #0x23
	ldrb r0, [r5]
	cmp r0, #5
	bhi .L08146EDC
	adds r4, r6, #0
	adds r4, #0x24
	ldrb r0, [r4]
	cmp r0, #3
	bls .L08146EC0
	ldr r0, .L08146ED8
	movs r1, #0
	str r1, [sp]
	movs r1, #9
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08146EC0:
	ldrb r0, [r4]
	cmp r0, #6
	bls .L08146ED0
	movs r0, #0
	strb r0, [r4]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
.L08146ED0:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b .L08146EEC
.L08146ED8: .4byte gUnknown_0815019C
.L08146EDC:
	ldr r0, [r6, #8]
	movs r1, #0x64
	bl __udivsi3
	bl sub_080C31FC
	bl sub_080BE4C4
.L08146EEC:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
