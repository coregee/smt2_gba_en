	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_08159A60
sub_08159A60: @ 0x08159A60
.L08159A60:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, .L08159A8C
	adds r5, r0, #0
	adds r5, #0x97
	ldrb r4, [r5]
	adds r7, r0, #0
	cmp r4, #8
	beq .L08159A90
	adds r1, r7, #0
	adds r1, #0x90
	ldrb r3, [r1]
	adds r2, r7, #0
	adds r2, #0x92
	ldrh r0, [r2]
	strh r0, [r1]
	strh r3, [r2]
	b .L08159AAA
	.byte 0x00, 0x00
.L08159A8C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159A90:
	adds r5, r7, #0
	adds r5, #0x98
	ldrb r4, [r5]
	cmp r4, #8
	beq .L08159AB4
	adds r2, r7, #0
	adds r2, #0x90
	ldrb r3, [r2]
	adds r1, r7, #0
	adds r1, #0x94
	ldrh r0, [r1]
	strh r0, [r2]
	strh r3, [r1]
.L08159AAA:
	adds r0, r7, #0
	adds r0, #0x96
	ldrb r3, [r0]
	strb r4, [r0]
	strb r3, [r5]
.L08159AB4:
	mov r8, r7
	ldr r1, .L08159B5C
	ldrh r0, [r1]
	adds r3, r0, #0
	subs r3, #0x32
	movs r2, #3
	adds r1, r3, #0
	ands r1, r2
	movs r0, #0x94
	add r0, r8
	mov sl, r0
	ldrh r4, [r0]
	adds r5, r4, #0
	subs r5, #0x32
	adds r0, r5, #0
	ands r0, r2
	cmp r1, r0
	bne .L08159B8A
	mov r0, r8
	adds r0, #0x96
	ldrb r2, [r0]
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r7, .L08159B60
	adds r0, r0, r7
	ldrb r3, [r0]
	movs r6, #1
	ands r1, r6
	cmp r1, #0
	bne .L08159AFC
	lsrs r3, r3, #4
.L08159AFC:
	movs r4, #0xf
	ands r3, r4
	adds r0, r3, #0
	cmp r0, #0
	bne .L08159B0C
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
.L08159B0C:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	adds r0, r0, r2
	adds r0, r0, r7
	ldrb r2, [r0]
	ands r1, r6
	cmp r1, #0
	bne .L08159B24
	lsrs r2, r2, #4
.L08159B24:
	ands r2, r4
	adds r0, r2, #0
	cmp r0, #0
	bne .L08159B32
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L08159B32:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r1
	adds r0, #1
	lsls r2, r0, #0x10
	asrs r1, r2, #0x10
	cmp r1, #0
	bge .L08159B64
	rsbs r1, r1, #0
	mov r0, r8
	adds r0, #0x90
	ldrh r0, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl Fusion_RankUp
	bl sub_08158CBC
	b .L08159BEC
.L08159B5C: .4byte 0x0203B8FA @ EWRAM+0x3B8FA
.L08159B60: .4byte gUnknown_087F1611
.L08159B64:
	cmp r1, #0
	ble .L08159B7A
	mov r0, r8
	adds r0, #0x90
	ldrh r0, [r0]
	lsrs r1, r2, #0x10
	bl Fusion_RankDown
	bl sub_08158CBC
	b .L08159BEC
.L08159B7A:
	mov r0, r8
	adds r0, #0x90
	ldrh r1, [r0]
	adds r0, #0x10
	strh r1, [r0]
	bl sub_08158CBC
	b .L08159BEC
.L08159B8A:
	movs r1, #0x90
	add r1, r8
	mov sb, r1
	ldrb r3, [r1]
	strh r4, [r1]
	mov r0, sl
	strh r3, [r0]
	ldrh r4, [r1]
	ldr r1, .L08159BE4
	ldrh r5, [r1]
	ldrh r6, [r0]
	bl sub_08158A34
	mov r0, sb
	strh r4, [r0]
	ldr r1, .L08159BE4
	strh r5, [r1]
	mov r0, sl
	strh r6, [r0]
	mov r5, r8
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L08159BE8
	adds r4, r7, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	movs r1, #1
	bl Fusion_RankDown
	ldrh r0, [r4]
	mov r1, sb
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1]
	ldr r1, .L08159BE4
	strh r0, [r1]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L08159BE8
	bl sub_08158CBC
	b .L08159BEC
.L08159BE4: .4byte 0x0203B8FA @ EWRAM+0x3B8FA
.L08159BE8:
	bl sub_08158E00
.L08159BEC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08159BFC
sub_08159BFC: @ 0x08159BFC
.L08159BFC:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, .L08159C18
	adds r2, r0, #0
	adds r2, #0x90
	ldrh r1, [r2]
	mov r8, r0
	cmp r1, #0x35
	bls .L08159C1C
	movs r2, #0x36
	b .L08159CEE
.L08159C18: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159C1C:
	movs r0, #0x92
	add r0, r8
	mov sb, r0
	ldrh r0, [r0]
	cmp r0, #0x35
	bls .L08159C94
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r4, r8
	adds r4, #0x94
	ldrh r0, [r4]
	strh r0, [r2]
	strh r1, [r4]
	ldrh r5, [r2]
	mov r1, sb
	ldrh r6, [r1]
	ldrh r7, [r4]
	str r2, [sp]
	bl sub_08158A34
	ldr r2, [sp]
	strh r5, [r2]
	mov r3, sb
	strh r6, [r3]
	strh r7, [r4]
	adds r4, #0xe
	ldrb r0, [r4]
	cmp r0, #0xff
	bne .L08159C5C
	bl sub_08158E00
	b .L08159D38
.L08159C5C:
	mov r5, r8
	adds r5, #0xa0
	ldrh r0, [r5]
	strh r0, [r2]
	mov r0, sb
	strh r7, [r0]
	bl sub_08158A34
	ldrb r0, [r4]
	cmp r0, #0xff
	bne .L08159C78
	bl sub_08158E00
	b .L08159D38
.L08159C78:
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #1
	bl Fusion_RankDown
	ldrh r0, [r5]
	cmp r0, r4
	bne .L08159D34
	ldr r0, .L08159C90
	strh r0, [r5]
	b .L08159D34
	.byte 0x00, 0x00
.L08159C90: .4byte 0x0000FFFF
.L08159C94:
	mov r4, r8
	adds r4, #0x94
	ldrh r0, [r4]
	cmp r0, #0x35
	bls .L08159CEC
	ldrh r5, [r2]
	mov r1, sb
	ldrh r6, [r1]
	adds r7, r0, #0
	str r2, [sp]
	bl sub_08158A34
	ldr r2, [sp]
	strh r5, [r2]
	mov r3, sb
	strh r6, [r3]
	strh r7, [r4]
	mov r5, r8
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	bne .L08159CC6
	bl sub_08158E00
	b .L08159D38
.L08159CC6:
	mov r4, r8
	adds r4, #0xa0
	ldrh r0, [r4]
	strh r0, [r2]
	mov r0, sb
	strh r7, [r0]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	bne .L08159CE2
	bl sub_08158E00
	b .L08159D38
.L08159CE2:
	ldrh r0, [r4]
	movs r1, #1
	bl Fusion_RankDown
	b .L08159D34
.L08159CEC:
	movs r2, #0x32
.L08159CEE:
	lsls r1, r2, #0x10
	asrs r0, r1, #0x10
	ldr r6, .L08159D48
	cmp r0, #0x39
	bgt .L08159D24
	ldr r0, .L08159D4C
	ldrh r3, [r0]
	adds r5, r0, #4
	adds r4, r0, #2
.L08159D00:
	asrs r1, r1, #0x10
	cmp r3, r1
	beq .L08159D12
	ldrh r0, [r4]
	cmp r0, r1
	beq .L08159D12
	ldrh r0, [r5]
	cmp r0, r1
	bne .L08159D24
.L08159D12:
	lsls r0, r2, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	lsls r1, r2, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0x39
	ble .L08159D00
.L08159D24:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r0, #0x32
	adds r0, r0, r6
	mov r1, r8
	adds r1, #0xa0
	ldrb r0, [r0]
	strh r0, [r1]
.L08159D34:
	bl sub_08158CBC
.L08159D38:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08159D48: .4byte gUnknown_087F198B
.L08159D4C: .4byte 0x0203B8F8 @ EWRAM+0x3B8F8

	thumb_func_start sub_08159D50
sub_08159D50: @ 0x08159D50
.L08159D50:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
.L08159D5A:
	movs r0, #0
	ldr r1, .L08159DC0
	str r0, [r1]
	ldr r7, .L08159DC4
	movs r2, #0x90
	adds r2, r2, r7
	mov sb, r2
	ldrh r6, [r2]
	movs r0, #0x92
	adds r0, r0, r7
	mov sl, r0
	ldrh r5, [r0]
	movs r1, #0x94
	adds r1, r1, r7
	mov r8, r1
	ldrh r4, [r1]
	bl sub_08158A34
	mov r2, sb
	strh r6, [r2]
	mov r0, sl
	strh r5, [r0]
	mov r1, r8
	strh r4, [r1]
	adds r5, r7, #0
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L08159DB8
	adds r4, r7, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	movs r1, #1
	bl Fusion_RankDown
	ldrh r0, [r4]
	mov r2, sb
	strh r0, [r2]
	mov r1, r8
	ldrh r0, [r1]
	mov r2, sl
	strh r0, [r2]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	bne .L08159DC8
.L08159DB8:
	bl sub_08158E00
	b .L08159DDC
	.byte 0x00, 0x00
.L08159DC0: .4byte 0x03006A38 @ IWRAM+0x6A38
.L08159DC4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159DC8:
	bl sub_08158CBC
	adds r1, r0, #0
	ldr r2, .L08159DEC
	ldr r0, [r2]
	cmp r0, #0
	beq .L08159DDA
	cmp r1, #0
	beq .L08159D5A
.L08159DDA:
	adds r0, r1, #0
.L08159DDC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08159DEC: .4byte 0x03006A38 @ IWRAM+0x6A38

	thumb_func_start sub_08159DF0
sub_08159DF0: @ 0x08159DF0
.L08159DF0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
.L08159DFA:
	movs r0, #0
	ldr r1, .L08159E6C
	str r0, [r1]
	ldr r7, .L08159E70
	movs r2, #0x90
	adds r2, r2, r7
	mov sb, r2
	ldrh r1, [r2]
	movs r0, #0x94
	adds r0, r0, r7
	mov r8, r0
	ldrh r0, [r0]
	strh r0, [r2]
	mov r2, r8
	strh r1, [r2]
	mov r0, sb
	ldrh r6, [r0]
	movs r1, #0x92
	adds r1, r1, r7
	mov sl, r1
	ldrh r4, [r1]
	ldrh r5, [r2]
	bl sub_08158A34
	mov r2, sb
	strh r6, [r2]
	mov r0, sl
	strh r4, [r0]
	mov r1, r8
	strh r5, [r1]
	adds r5, r7, #0
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L08159E64
	adds r4, r7, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	movs r1, #1
	bl Fusion_RankDown
	ldrh r0, [r4]
	mov r2, sb
	strh r0, [r2]
	mov r1, r8
	ldrh r0, [r1]
	mov r2, sl
	strh r0, [r2]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	bne .L08159E74
.L08159E64:
	bl sub_08158E00
	b .L08159E88
	.byte 0x00, 0x00
.L08159E6C: .4byte 0x03006A38 @ IWRAM+0x6A38
.L08159E70: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159E74:
	bl sub_08158CBC
	adds r1, r0, #0
	ldr r2, .L08159E98
	ldr r0, [r2]
	cmp r0, #0
	beq .L08159E86
	cmp r1, #0
	beq .L08159DFA
.L08159E86:
	adds r0, r1, #0
.L08159E88:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L08159E98: .4byte 0x03006A38 @ IWRAM+0x6A38

	thumb_func_start sub_08159E9C
sub_08159E9C: @ 0x08159E9C
.L08159E9C:
	push {r4, lr}
.L08159E9E:
	ldr r4, .L08159ED0
	movs r0, #0
	str r0, [r4]
	ldr r3, .L08159ED4
	adds r2, r3, #0
	adds r2, #0xa4
	ldrb r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x9c
	adds r1, r3, #0
	adds r1, #0x9d
	ldrb r2, [r0]
	ldrb r1, [r1]
	cmp r2, r1
	bhs .L08159ED8
	adds r0, #2
	ldrb r0, [r0]
	cmp r1, r0
	blo .L08159EE2
	adds r0, r3, #0
	adds r0, #0x92
	b .L08159EE6
.L08159ED0: .4byte 0x03006A38 @ IWRAM+0x6A38
.L08159ED4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159ED8:
	adds r0, r3, #0
	adds r0, #0x9e
	ldrb r0, [r0]
	cmp r2, r0
	bhs .L08159EF4
.L08159EE2:
	adds r0, r3, #0
	adds r0, #0x94
.L08159EE6:
	ldrh r0, [r0]
	movs r1, #3
	bl Fusion_RankDown
	bl sub_08158CBC
	b .L08159F12
.L08159EF4:
	adds r0, r3, #0
	adds r0, #0x90
	ldrh r0, [r0]
	movs r1, #3
	bl Fusion_RankDown
	bl sub_08158CBC
	adds r1, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	beq .L08159F10
	cmp r1, #0
	beq .L08159E9E
.L08159F10:
	adds r0, r1, #0
.L08159F12:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_08159F18
sub_08159F18: @ 0x08159F18
.L08159F18:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	movs r0, #0
	ldr r3, .L08159F5C
	adds r1, r3, #0
	adds r1, #0x99
	ldrb r6, [r1]
	cmp r6, #0xb
	bne .L08159F30
	movs r0, #1
.L08159F30:
	adds r1, r3, #0
	adds r1, #0x9a
	ldrb r5, [r1]
	cmp r5, #0xb
	bne .L08159F40
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
.L08159F40:
	adds r1, r3, #0
	adds r1, #0x9b
	ldrb r4, [r1]
	cmp r4, #0xb
	bne .L08159F50
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
.L08159F50:
	cmp r0, #1
	bls .L08159F60
	bl sub_08158E00
	b .L0815A050
	.byte 0x00, 0x00
.L08159F5C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L08159F60:
	adds r2, r3, #0
	adds r2, #0xa4
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	adds r2, #2
	ldrb r1, [r2]
	movs r0, #3
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	strb r0, [r2]
	cmp r6, #0xb
	beq .L08159F98
	cmp r5, #0xb
	bne .L08159F8C
	movs r0, #1
	movs r1, #0
	bl sub_0815A060
	b .L08159F98
.L08159F8C:
	cmp r4, #0xb
	bne .L08159F98
	movs r0, #2
	movs r1, #0
	bl sub_0815A060
.L08159F98:
	ldr r4, .L0815A000
	adds r0, r4, #0
	adds r0, #0x9d
	adds r1, r4, #0
	adds r1, #0x9e
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	blo .L08159FB2
	movs r0, #1
	movs r1, #2
	bl sub_0815A060
.L08159FB2:
	adds r1, r4, #0
	adds r1, #0x90
	movs r0, #0x92
	adds r0, r0, r4
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0x94
.L08159FC0:
	ldrh r4, [r1]
	mov r2, r8
	ldrh r5, [r2]
	ldrh r6, [r7]
	str r1, [sp]
	bl sub_08158A34
	ldr r1, [sp]
	strh r4, [r1]
	mov r2, r8
	strh r5, [r2]
	strh r6, [r7]
	cmp r0, #0
	beq .L08159FC0
	ldr r4, .L0815A000
	adds r5, r4, #0
	adds r5, #0xa0
	ldrh r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	strh r1, [r0]
	adds r0, #4
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	bl sub_08158A34
	cmp r0, #0
	bne .L0815A004
	adds r0, r4, #0
	b .L0815A046
.L0815A000: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A004:
	ldrh r0, [r5]
	movs r1, #1
	bl Fusion_RankDown
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r5]
	ldrh r0, [r0]
	cmp r1, r0
	beq .L0815A044
	adds r0, r4, #0
	adds r0, #0x8c
	ldrh r0, [r0]
	cmp r1, r0
	beq .L0815A044
	adds r0, r4, #0
	adds r0, #0x8e
	ldrh r0, [r0]
	cmp r1, r0
	beq .L0815A044
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0x30
	strb r0, [r1]
	ldrh r0, [r5]
	bl sub_0815BA28
	cmp r0, #0
	beq .L0815A044
	bl sub_08158CBC
	b .L0815A050
.L0815A044:
	ldr r0, .L0815A05C
.L0815A046:
	adds r0, #0xa6
	movs r1, #0x30
	strb r1, [r0]
	bl sub_08158CA4
.L0815A050:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L0815A05C: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815A060
sub_0815A060: @ 0x0815A060
.L0815A060:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r3, #0
	bne .L0815A070
	ldr r5, .L0815A120
.L0815A070:
	cmp r3, #1
	bne .L0815A076
	ldr r5, .L0815A124
.L0815A076:
	cmp r3, #2
	bne .L0815A07C
	ldr r5, .L0815A128
.L0815A07C:
	cmp r1, #0
	bne .L0815A082
	ldr r4, .L0815A120
.L0815A082:
	cmp r1, #1
	bne .L0815A088
	ldr r4, .L0815A124
.L0815A088:
	cmp r1, #2
	bne .L0815A08E
	ldr r4, .L0815A128
.L0815A08E:
	ldrb r2, [r4]
	ldrb r0, [r5]
	strb r0, [r4]
	strb r2, [r5]
	cmp r3, #0
	bne .L0815A09C
	ldr r5, .L0815A12C
.L0815A09C:
	cmp r3, #1
	bne .L0815A0A2
	ldr r5, .L0815A130
.L0815A0A2:
	cmp r3, #2
	bne .L0815A0A8
	ldr r5, .L0815A134
.L0815A0A8:
	cmp r1, #0
	bne .L0815A0AE
	ldr r4, .L0815A12C
.L0815A0AE:
	cmp r1, #1
	bne .L0815A0B4
	ldr r4, .L0815A130
.L0815A0B4:
	cmp r1, #2
	bne .L0815A0BA
	ldr r4, .L0815A134
.L0815A0BA:
	ldrb r2, [r4]
	ldrb r0, [r5]
	strb r0, [r4]
	strb r2, [r5]
	cmp r3, #0
	bne .L0815A0C8
	ldr r5, .L0815A138
.L0815A0C8:
	cmp r3, #1
	bne .L0815A0CE
	ldr r5, .L0815A13C
.L0815A0CE:
	cmp r3, #2
	bne .L0815A0D4
	ldr r5, .L0815A140
.L0815A0D4:
	cmp r1, #0
	bne .L0815A0DA
	ldr r4, .L0815A138
.L0815A0DA:
	cmp r1, #1
	bne .L0815A0E0
	ldr r4, .L0815A13C
.L0815A0E0:
	cmp r1, #2
	bne .L0815A0E6
	ldr r4, .L0815A140
.L0815A0E6:
	ldrb r2, [r4]
	ldrb r0, [r5]
	strb r0, [r4]
	strb r2, [r5]
	cmp r3, #0
	bne .L0815A0F4
	ldr r7, .L0815A144
.L0815A0F4:
	cmp r3, #1
	bne .L0815A0FA
	ldr r7, .L0815A148
.L0815A0FA:
	cmp r3, #2
	bne .L0815A100
	ldr r7, .L0815A14C
.L0815A100:
	cmp r1, #0
	bne .L0815A106
	ldr r6, .L0815A144
.L0815A106:
	cmp r1, #1
	bne .L0815A10C
	ldr r6, .L0815A148
.L0815A10C:
	cmp r1, #2
	bne .L0815A112
	ldr r6, .L0815A14C
.L0815A112:
	ldrh r1, [r6]
	ldrh r0, [r7]
	strh r0, [r6]
	strh r1, [r7]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0815A120: .4byte 0x0203B901 @ EWRAM+0x3B901
.L0815A124: .4byte 0x0203B902 @ EWRAM+0x3B902
.L0815A128: .4byte 0x0203B903 @ EWRAM+0x3B903
.L0815A12C: .4byte 0x0203B8FE @ EWRAM+0x3B8FE
.L0815A130: .4byte 0x0203B8FF @ EWRAM+0x3B8FF
.L0815A134: .4byte 0x0203B900 @ EWRAM+0x3B900
.L0815A138: .4byte 0x0203B904 @ EWRAM+0x3B904
.L0815A13C: .4byte 0x0203B905 @ EWRAM+0x3B905
.L0815A140: .4byte 0x0203B906 @ EWRAM+0x3B906
.L0815A144: .4byte 0x0203B8F8 @ EWRAM+0x3B8F8
.L0815A148: .4byte 0x0203B8FA @ EWRAM+0x3B8FA
.L0815A14C: .4byte 0x0203B8FC @ EWRAM+0x3B8FC

	thumb_func_start sub_0815A150
sub_0815A150: @ 0x0815A150
.L0815A150:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r2, #0
	ldr r1, .L0815A194
	adds r0, r1, #0
	adds r0, #0x96
	ldrb r4, [r0]
	cmp r4, #0x16
	bne .L0815A16A
	movs r2, #1
.L0815A16A:
	adds r0, r1, #0
	adds r0, #0x97
	ldrb r3, [r0]
	cmp r3, #0x16
	bne .L0815A17A
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
.L0815A17A:
	adds r0, r1, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0x16
	bne .L0815A18A
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
.L0815A18A:
	cmp r2, #3
	bne .L0815A198
	bl sub_0815A2F4
	b .L0815A220
.L0815A194: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A198:
	cmp r2, #2
	bne .L0815A1A2
	bl sub_0815A230
	b .L0815A220
.L0815A1A2:
	cmp r4, #0x16
	bne .L0815A1B0
	movs r0, #0
	movs r1, #2
	bl sub_0815A060
	b .L0815A1BC
.L0815A1B0:
	cmp r3, #0x16
	bne .L0815A1BC
	movs r0, #1
	movs r1, #2
	bl sub_0815A060
.L0815A1BC:
	ldr r7, .L0815A218
	movs r0, #0x90
	adds r0, r0, r7
	mov sb, r0
	ldrh r6, [r0]
	movs r1, #0x92
	adds r1, r1, r7
	mov r8, r1
	ldrh r5, [r1]
	adds r4, r7, #0
	adds r4, #0x94
	ldrh r0, [r4]
	mov sl, r0
	bl sub_08158A34
	mov r1, sb
	strh r6, [r1]
	mov r0, r8
	strh r5, [r0]
	mov r1, sl
	strh r1, [r4]
	adds r5, r7, #0
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L0815A21C
	adds r4, r7, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	mov r1, sb
	strh r0, [r1]
	mov r1, sl
	mov r0, r8
	strh r1, [r0]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L0815A21C
	ldrh r0, [r4]
	movs r1, #1
	bl Fusion_RankDown
	bl sub_08158CBC
	b .L0815A220
.L0815A218: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A21C:
	bl sub_08158E00
.L0815A220:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815A230
sub_0815A230: @ 0x0815A230
.L0815A230:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, .L0815A25C
	adds r0, r1, #0
	adds r0, #0x96
	ldrb r0, [r0]
	cmp r0, #0x16
	bne .L0815A268
	adds r0, r1, #0
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #0x16
	beq .L0815A260
	movs r0, #0
	movs r1, #1
	bl sub_0815A060
	b .L0815A268
	.byte 0x00, 0x00
.L0815A25C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A260:
	movs r0, #0
	movs r1, #2
	bl sub_0815A060
.L0815A268:
	ldr r7, .L0815A2DC
	adds r0, r7, #0
	adds r0, #0x9d
	adds r1, r7, #0
	adds r1, #0x9e
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs .L0815A282
	movs r0, #1
	movs r1, #2
	bl sub_0815A060
.L0815A282:
	movs r0, #0x90
	adds r0, r0, r7
	mov sb, r0
	ldrh r6, [r0]
	movs r1, #0x92
	adds r1, r1, r7
	mov r8, r1
	ldrh r5, [r1]
	adds r4, r7, #0
	adds r4, #0x94
	ldrh r0, [r4]
	mov sl, r0
	bl sub_08158A34
	mov r1, sb
	strh r6, [r1]
	mov r0, r8
	strh r5, [r0]
	mov r1, sl
	strh r1, [r4]
	adds r5, r7, #0
	adds r5, #0xa2
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L0815A2E0
	adds r4, r7, #0
	adds r4, #0xa0
	ldrh r0, [r4]
	mov r1, sb
	strh r0, [r1]
	mov r1, sl
	mov r0, r8
	strh r1, [r0]
	bl sub_08158A34
	ldrb r0, [r5]
	cmp r0, #0xff
	beq .L0815A2E0
	ldrh r0, [r4]
	movs r1, #1
	bl Fusion_RankDown
	bl sub_08158CBC
	b .L0815A2E4
.L0815A2DC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A2E0:
	bl sub_08158E00
.L0815A2E4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815A2F4
sub_0815A2F4: @ 0x0815A2F4
.L0815A2F4:
	push {lr}
	ldr r0, .L0815A308
	adds r0, #0xa0
	movs r1, #0x35
	strh r1, [r0]
	bl sub_08158CBC
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815A308: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815A30C
sub_0815A30C: @ 0x0815A30C
.L0815A30C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r7, #0
	ldr r1, .L0815A3D0
	adds r0, r1, #0
	adds r0, #0x96
	ldrb r0, [r0]
	adds r6, r1, #0
	cmp r0, #0xc
	bhi .L0815A32A
	movs r7, #1
.L0815A32A:
	ldr r0, .L0815A3D4
	ldrb r0, [r0]
	mov r8, r0
	mov r1, r8
	cmp r1, #0xc
	bhi .L0815A340
	lsls r0, r7, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r7, r0, #0x10
.L0815A340:
	adds r3, r6, #0
	adds r3, #0x98
	ldrb r0, [r3]
	cmp r0, #0xc
	bhi .L0815A354
	lsls r0, r7, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r7, r0, #0x10
.L0815A354:
	lsls r0, r7, #0x12
	ldr r1, .L0815A3D8
	adds r0, r0, r1
	lsrs r7, r0, #0x10
	adds r0, r6, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	movs r1, #0x9d
	adds r1, r1, r6
	mov sl, r1
	ldrb r5, [r1]
	adds r0, r0, r5
	movs r1, #0x9e
	adds r1, r1, r6
	mov sb, r1
	ldrb r4, [r1]
	adds r0, r0, r4
	movs r1, #3
	str r3, [sp, #4]
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r3, [sp, #4]
	cmp r4, r5
	bls .L0815A3DC
	ldrb r2, [r3]
	mov r0, r8
	strb r0, [r3]
	ldr r1, .L0815A3D4
	strb r2, [r1]
	adds r3, r6, #0
	adds r3, #0x9b
	ldrb r2, [r3]
	adds r1, r6, #0
	adds r1, #0x9a
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r0, sb
	ldrb r2, [r0]
	mov r1, sl
	ldrb r0, [r1]
	mov r1, sb
	strb r0, [r1]
	mov r0, sl
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0x94
	ldrh r2, [r1]
	subs r3, #9
	ldrh r0, [r3]
	strh r0, [r1]
	strh r2, [r3]
	b .L0815A420
	.byte 0x00, 0x00
.L0815A3D0: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A3D4: .4byte 0x0203B8FF @ EWRAM+0x3B8FF
.L0815A3D8: .4byte 0xFFFC0000
.L0815A3DC:
	cmp r4, r5
	bne .L0815A420
	adds r4, r6, #0
	adds r4, #0x94
	adds r7, r6, #0
	adds r7, #0x92
	ldrh r5, [r7]
	ldrh r0, [r4]
	cmp r0, r5
	bhs .L0815A420
	ldrb r2, [r3]
	mov r1, r8
	strb r1, [r3]
	ldr r0, .L0815A46C
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x9b
	ldrb r2, [r3]
	adds r1, r6, #0
	adds r1, #0x9a
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r1, sb
	ldrb r2, [r1]
	mov r1, sl
	ldrb r0, [r1]
	mov r1, sb
	strb r0, [r1]
	mov r0, sl
	strb r2, [r0]
	ldrh r2, [r4]
	strh r5, [r4]
	strh r2, [r7]
.L0815A420:
	movs r1, #0x9d
	adds r1, r1, r6
	mov ip, r1
	movs r0, #0x9c
	adds r0, r0, r6
	mov r8, r0
	ldrb r4, [r0]
	ldrb r1, [r1]
	adds r0, r4, #0
	cmp r1, r0
	bls .L0815A470
	adds r3, r6, #0
	adds r3, #0x97
	ldrb r2, [r3]
	adds r1, r6, #0
	adds r1, #0x96
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	adds r3, #3
	ldrb r2, [r3]
	adds r1, #3
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r1, ip
	ldrb r2, [r1]
	strb r4, [r1]
	mov r0, r8
	strb r2, [r0]
	subs r3, #8
	ldrh r2, [r3]
	adds r1, r6, #0
	adds r1, #0x90
	ldrh r0, [r1]
	strh r0, [r3]
	strh r2, [r1]
	b .L0815A4B4
.L0815A46C: .4byte 0x0203B8FF @ EWRAM+0x3B8FF
.L0815A470:
	cmp r1, r0
	bne .L0815A4B4
	adds r5, r6, #0
	adds r5, #0x92
	movs r1, #0x90
	adds r1, r1, r6
	mov sb, r1
	ldrh r7, [r1]
	ldrh r0, [r5]
	cmp r0, r7
	bhs .L0815A4B4
	adds r3, r6, #0
	adds r3, #0x97
	ldrb r2, [r3]
	adds r1, r6, #0
	adds r1, #0x96
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	adds r3, #3
	ldrb r2, [r3]
	adds r1, #3
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r0, ip
	ldrb r2, [r0]
	strb r4, [r0]
	mov r1, r8
	strb r2, [r1]
	ldrh r2, [r5]
	strh r7, [r5]
	mov r0, sb
	strh r2, [r0]
.L0815A4B4:
	movs r1, #0x9e
	adds r1, r1, r6
	mov ip, r1
	movs r0, #0x9d
	adds r0, r0, r6
	mov r8, r0
	ldrb r4, [r0]
	ldrb r1, [r1]
	adds r0, r4, #0
	cmp r1, r0
	bls .L0815A500
	adds r1, r6, #0
	adds r1, #0x98
	ldrb r2, [r1]
	adds r3, r6, #0
	adds r3, #0x97
	ldrb r0, [r3]
	strb r0, [r1]
	strb r2, [r3]
	adds r3, #4
	ldrb r2, [r3]
	adds r1, #2
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r1, ip
	ldrb r2, [r1]
	strb r4, [r1]
	mov r0, r8
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0x94
	ldrh r2, [r1]
	subs r3, #9
	ldrh r0, [r3]
	strh r0, [r1]
	strh r2, [r3]
	b .L0815A546
.L0815A500:
	cmp r1, r0
	bne .L0815A546
	adds r5, r6, #0
	adds r5, #0x94
	movs r1, #0x92
	adds r1, r1, r6
	mov sb, r1
	ldrh r7, [r1]
	ldrh r0, [r5]
	cmp r0, r7
	bhs .L0815A546
	adds r0, r6, #0
	adds r0, #0x98
	ldrb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x97
	ldrb r1, [r3]
	strb r1, [r0]
	strb r2, [r3]
	adds r3, #4
	ldrb r2, [r3]
	adds r1, r6, #0
	adds r1, #0x9a
	ldrb r0, [r1]
	strb r0, [r3]
	strb r2, [r1]
	mov r0, ip
	ldrb r2, [r0]
	strb r4, [r0]
	mov r1, r8
	strb r2, [r1]
	ldrh r2, [r5]
	strh r7, [r5]
	mov r0, sb
	strh r2, [r0]
.L0815A546:
	adds r0, r6, #0
	adds r0, #0x99
	adds r1, r6, #0
	adds r1, #0x9a
	ldrb r2, [r0]
	ldrb r1, [r1]
	cmp r2, r1
	bne .L0815A55E
	adds r0, #2
	ldrb r0, [r0]
	cmp r2, r0
	beq .L0815A59E
.L0815A55E:
	adds r7, r6, #0
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	adds r5, r7, #0
	adds r5, #0x9a
	adds r2, r7, #0
	adds r2, #0x97
	adds r1, r5, #0
	bl Demon_GetRaceAndAlign
	adds r0, r7, #0
	adds r0, #0x94
	ldrh r0, [r0]
	adds r4, r7, #0
	adds r4, #0x9b
	adds r2, r7, #0
	adds r2, #0x98
	adds r1, r4, #0
	bl Demon_GetRaceAndAlign
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldrb r4, [r4]
	adds r2, r0, r4
	ldr r0, .L0815A5A4
	adds r0, r2, r0
	ldrb r5, [r0]
	cmp r5, #0xff
	bne .L0815A5A8
.L0815A59E:
	bl sub_0815A670
	b .L0815A658
.L0815A5A4: .4byte gUnknown_087F1993
.L0815A5A8:
	adds r0, r7, #0
	adds r0, #0x90
	ldrh r0, [r0]
	adds r4, r7, #0
	adds r4, #0x99
	adds r2, r7, #0
	adds r2, #0x96
	adds r1, r4, #0
	bl Demon_GetRaceAndAlign
	ldrb r1, [r4]
	movs r0, #0x16
	muls r0, r1, r0
	adds r2, r5, r0
	ldr r0, .L0815A5EC
	adds r0, r2, r0
	ldrb r0, [r0]
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
	cmp r0, #0xff
	beq .L0815A5FC
.L0815A5D4:
	ldr r1, [sp]
	lsls r4, r1, #0x10
	lsrs r0, r4, #0x10
	bl Fusion_FindRaceDemonByLevel
	lsls r0, r0, #0x10
	cmp r0, #0
	blt .L0815A5F0
	bl sub_08158CBC
	b .L0815A658
	.byte 0x00, 0x00
.L0815A5EC: .4byte gUnknown_087F1A23
.L0815A5F0:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	b .L0815A5D4
.L0815A5FC:
	adds r2, r6, #0
	adds r2, #0xa4
	ldrb r0, [r2]
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	adds r2, #2
	ldrb r1, [r2]
	movs r0, #3
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	strb r0, [r2]
.L0815A616:
	bl sub_08159144
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xff
	beq .L0815A616
	ldr r0, .L0815A668
	adds r4, r0, #0
	adds r4, #0xa0
	strh r1, [r4]
	ldrh r0, [r4]
	bl sub_0815BA28
	cmp r0, #0
	beq .L0815A616
	ldrh r0, [r4]
	bl Demon_GetLevel
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, .L0815A66C
	ldrb r1, [r1, #0xd]
	cmp r0, r1
	bhs .L0815A616
	bl sub_08158CBC
	adds r1, r0, #0
	cmp r1, #0
	beq .L0815A616
	ldrh r0, [r4]
	cmp r0, #0xfe
	bhi .L0815A616
	adds r0, r1, #0
.L0815A658:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.L0815A668: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A66C: .4byte 0x030046C0 @ IWRAM+0x46C0

	thumb_func_start sub_0815A670
sub_0815A670: @ 0x0815A670
.L0815A670:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r7, .L0815A6D8
	ldr r0, .L0815A6DC
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x90
	ldrh r0, [r2]
	ldr r3, .L0815A6DC
	strh r0, [r3]
	strh r1, [r2]
	ldrh r6, [r2]
	movs r0, #0x92
	adds r0, r0, r7
	mov r8, r0
	ldrh r5, [r0]
	ldrh r4, [r3]
	str r2, [sp]
	bl sub_08158A34
	ldr r2, [sp]
	strh r6, [r2]
	mov r3, r8
	strh r5, [r3]
	ldr r0, .L0815A6DC
	strh r4, [r0]
	adds r6, r7, #0
	adds r6, #0xa2
	ldrb r0, [r6]
	cmp r0, #0xff
	beq .L0815A6E0
	adds r5, r7, #0
	adds r5, #0xa0
	ldrh r0, [r5]
	strh r0, [r2]
	mov r3, r8
	strh r4, [r3]
	bl sub_08158A34
	ldrb r0, [r6]
	cmp r0, #0xff
	beq .L0815A6E0
	ldrh r0, [r5]
	movs r1, #1
	bl Fusion_RankDown
	bl sub_08158CBC
	b .L0815A6E4
	.byte 0x00, 0x00
.L0815A6D8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A6DC: .4byte 0x0203B8FC @ EWRAM+0x3B8FC
.L0815A6E0:
	bl sub_08158E00
.L0815A6E4:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0815A6F0
sub_0815A6F0: @ 0x0815A6F0
.L0815A6F0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r5, .L0815A7BC
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r7, [r0]
	adds r0, r7, #0
	bl Demon_GetRecord
	ldrb r1, [r0, #0x1e]
	movs r0, #0xf
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0x80
	movs r3, #0
	strb r0, [r1]
	movs r0, #0x94
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r0, #0xff
	strb r0, [r4]
	ldr r2, .L0815A7C0
	adds r1, r5, r2
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2]
	ldr r0, .L0815A7C4
	adds r1, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x81
	strb r3, [r1]
	adds r0, r5, #0
	adds r0, #0x82
	strb r3, [r0]
	movs r6, #0
	mov sb, r5
	movs r3, #0x83
	add r3, sb
	mov r8, r3
	adds r3, r0, #0
	mov sl, r4
	adds r4, r2, #0
	adds r5, r1, #0
.L0815A760:
	adds r0, r7, #0
	str r3, [sp]
	bl Demon_GetRecord
	adds r0, #0x11
	adds r0, r0, r6
	ldrb r0, [r0]
	mov r1, r8
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, [sp]
	cmp r0, #0xff
	beq .L0815A7E6
	cmp r0, #0x3f
	bhi .L0815A79A
	ldrb r0, [r1]
	bl sub_0815AE68
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r3, [sp]
	cmp r1, #0xf
	beq .L0815A79A
	mov r0, sb
	adds r0, #0x80
	ldrb r0, [r0]
	cmp r1, r0
	beq .L0815A7C8
.L0815A79A:
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r4
	mov r2, r8
	ldrb r1, [r2]
	strb r1, [r0]
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, #1
	adds r0, r0, r4
	movs r1, #0xff
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	b .L0815A7E6
	.byte 0x00, 0x00
.L0815A7BC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A7C0: .4byte 0x00000251
.L0815A7C4: .4byte 0x00000271
.L0815A7C8:
	movs r0, #0
	ldrsb r0, [r5, r0]
	add r0, sl
	mov r2, r8
	ldrb r1, [r2]
	strb r1, [r0]
	movs r0, #0
	ldrsb r0, [r5, r0]
	adds r0, #1
	add r0, sl
	movs r1, #0xff
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
.L0815A7E6:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #5
	bls .L0815A760
	ldr r4, .L0815A85C
	adds r5, r4, #0
	adds r5, #0x81
	movs r0, #0
	strb r0, [r5]
	adds r1, r4, #0
	adds r1, #0x82
	strb r0, [r1]
	adds r1, #0x2e
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r6, r4, r3
	strb r0, [r6]
	ldr r0, .L0815A860
	adds r1, r4, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, .L0815A864
	adds r1, r4, r3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	bl sub_0815ABA8
	adds r0, r4, #0
	adds r0, #0x92
	ldrh r0, [r0]
	bl sub_0815ABA8
	adds r0, r4, #0
	adds r0, #0x90
	ldrh r0, [r0]
	bl sub_0815ABA8
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bne .L0815A876
	bl sub_0815A99C
	b .L0815A984
	.byte 0x00, 0x00
.L0815A85C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A860: .4byte 0x00000181
.L0815A864: .4byte 0x00000291
.L0815A868:
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	bl sub_0815AA30
	b .L0815A984
.L0815A876:
	movs r7, #0
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0xff
	beq .L0815A8BA
	adds r2, r5, #0
	adds r4, r6, #0
	adds r3, r1, #0
	movs r5, #0xff
.L0815A88C:
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r1, r1, r4
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r1]
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r1, #1
	adds r1, r1, r4
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A88C
.L0815A8BA:
	adds r4, r6, #0
	adds r0, r4, #0
	bl sub_0815AB38
	movs r7, #0
	movs r6, #0
	adds r1, r4, #0
	adds r1, #0xf0
	ldrb r0, [r1]
	cmp r0, #0xff
	beq .L0815A8FA
	subs r4, #0xd0
	adds r3, r1, #0
	movs r5, #0xff
.L0815A8D6:
	adds r1, r6, r4
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, r6, #1
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A8D6
.L0815A8FA:
	movs r6, #0
	ldr r0, .L0815A994
	adds r2, r0, #0
	adds r2, #0xb0
	ldrb r1, [r2]
	adds r3, r0, #0
	cmp r1, #0xff
	beq .L0815A91A
	adds r1, r2, #0
.L0815A90C:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A90C
.L0815A91A:
	movs r7, #0
	cmp r6, #6
	beq .L0815A976
	movs r1, #0xff
	mov r8, r1
	ldr r5, .L0815A998
.L0815A926:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	adds r0, r7, r0
	ldrb r2, [r0]
	adds r1, r2, #0
	mov r3, r8
	ands r1, r3
	cmp r1, #0xff
	beq .L0815A868
	adds r0, r6, r5
	strb r2, [r0]
	adds r1, r6, #1
	adds r1, r1, r5
	ldrb r2, [r1]
	mov r0, r8
	orrs r0, r2
	strb r0, [r1]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r4, r5, #0
	adds r0, r4, #0
	bl sub_0815AAC8
	movs r6, #0
	ldrb r0, [r4]
	cmp r0, #0xff
	beq .L0815A970
	adds r1, r4, #0
.L0815A962:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A962
.L0815A970:
	ldr r3, .L0815A994
	cmp r6, #6
	bne .L0815A926
.L0815A976:
	adds r0, r3, #0
	adds r0, #0xb0
	adds r0, r6, r0
	movs r1, #0xff
	strb r1, [r0]
	bl sub_0815AAC4
.L0815A984:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0815A994: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815A998: .4byte 0x0203B918 @ EWRAM+0x3B918

	thumb_func_start sub_0815A99C
sub_0815A99C: @ 0x0815A99C
.L0815A99C:
	push {r4, r5, r6, lr}
	ldr r4, .L0815AA24
	adds r0, r4, #0
	adds r0, #0x20
	bl sub_0815AB38
	movs r3, #0
	movs r2, #0
	ldrb r0, [r4]
	cmp r0, #0xff
	beq .L0815A9DC
	ldr r0, .L0815AA28
	adds r5, r4, r0
	movs r6, #0xff
.L0815A9B8:
	adds r1, r2, r5
	adds r0, r3, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, #1
	adds r1, r2, r5
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A9B8
.L0815A9DC:
	movs r3, #0
	ldr r1, .L0815AA2C
	movs r0, #0x94
	lsls r0, r0, #2
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0xff
	beq .L0815AA16
	adds r5, r1, #0
	adds r5, #0xb0
	movs r6, #0xff
.L0815A9F2:
	adds r1, r2, r5
	adds r0, r3, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, #1
	adds r1, r2, r5
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815A9F2
.L0815AA16:
	adds r0, r3, #0
	adds r1, r2, #0
	bl sub_0815AA30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L0815AA24: .4byte 0x0203BAD8 @ EWRAM+0x3BAD8
.L0815AA28: .4byte 0xFFFFFE40
.L0815AA2C: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815AA30
sub_0815AA30: @ 0x0815AA30
.L0815AA30:
	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r4, .L0815AAB8
	adds r0, r4, #0
	adds r0, #0x20
	bl sub_0815AB38
	ldr r0, .L0815AABC
	adds r4, r4, r0
	adds r0, r4, #0
	bl sub_0815AAC8
	movs r3, #0
	ldrb r0, [r4]
	cmp r0, #0xff
	beq .L0815AA60
	adds r1, r4, #0
.L0815AA52:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815AA52
.L0815AA60:
	ldr r6, .L0815AAC0
	cmp r3, #5
	bhi .L0815AAA2
	adds r2, r5, #0
	adds r2, #0x20
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	beq .L0815AAA2
	adds r4, r1, #0
	adds r7, r6, #0
	adds r7, #0xb0
.L0815AA7E:
	adds r1, r3, r7
	adds r0, r2, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #5
	bhi .L0815AAA2
	adds r2, r5, #0
	adds r2, #0x20
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L0815AA7E
.L0815AAA2:
	adds r0, r6, #0
	adds r0, #0xb0
	adds r0, r3, r0
	movs r1, #0xff
	strb r1, [r0]
	bl sub_0815AAC4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815AAB8: .4byte 0x0203BAD8 @ EWRAM+0x3BAD8
.L0815AABC: .4byte 0xFFFFFE40
.L0815AAC0: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815AAC4
sub_0815AAC4: @ 0x0815AAC4
.L0815AAC4:
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0815AAC8
sub_0815AAC8: @ 0x0815AAC8
.L0815AAC8:
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldrb r0, [r3]
	cmp r0, #0xff
	beq .L0815AB32
	ldrb r0, [r3, #1]
	cmp r0, #0xff
	beq .L0815AB32
	movs r7, #0
	movs r5, #0
.L0815AADC:
	adds r0, r5, r3
	ldrb r0, [r0, #1]
	adds r1, r7, #1
	mov ip, r1
	cmp r0, #0xff
	beq .L0815AB22
.L0815AAE8:
	adds r2, r3, r7
	adds r6, r5, r3
	ldrb r4, [r6, #1]
	ldrb r1, [r2]
	adds r0, r4, #0
	cmp r1, r0
	bne .L0815AB0A
	adds r2, r5, #0
.L0815AAF8:
	adds r0, r2, r3
	ldrb r1, [r0, #2]
	strb r1, [r0, #1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r1, #0xff
	bne .L0815AAF8
	b .L0815AADC
.L0815AB0A:
	cmp r1, r0
	bls .L0815AB14
	ldrb r1, [r2]
	strb r4, [r2]
	strb r1, [r6, #1]
.L0815AB14:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r5, r3
	ldrb r0, [r0, #1]
	cmp r0, #0xff
	bne .L0815AAE8
.L0815AB22:
	mov r1, ip
	lsls r0, r1, #0x18
	lsrs r7, r0, #0x18
	adds r5, r7, #0
	adds r0, r7, r3
	ldrb r0, [r0, #1]
	cmp r0, #0xff
	bne .L0815AADC
.L0815AB32:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0815AB38
sub_0815AB38: @ 0x0815AB38
.L0815AB38:
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldrb r0, [r3]
	cmp r0, #0xff
	beq .L0815ABA2
	ldrb r0, [r3, #1]
	cmp r0, #0xff
	beq .L0815ABA2
	movs r7, #0
	movs r4, #0
.L0815AB4C:
	adds r0, r4, r3
	ldrb r0, [r0, #1]
	adds r1, r7, #1
	mov ip, r1
	cmp r0, #0xff
	beq .L0815AB7C
.L0815AB58:
	adds r2, r3, r7
	adds r6, r4, r3
	ldrb r5, [r6, #1]
	ldrb r1, [r2]
	adds r0, r5, #0
	cmp r1, r0
	beq .L0815AB8E
	cmp r1, r0
	bhs .L0815AB6E
	strb r5, [r2]
	strb r1, [r6, #1]
.L0815AB6E:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, r3
	ldrb r0, [r0, #1]
	cmp r0, #0xff
	bne .L0815AB58
.L0815AB7C:
	mov r1, ip
	lsls r0, r1, #0x18
	lsrs r4, r0, #0x18
	adds r7, r4, #0
	adds r0, r4, r3
	ldrb r0, [r0, #1]
	cmp r0, #0xff
	bne .L0815AB4C
	b .L0815ABA2
.L0815AB8E:
	adds r2, r4, #0
.L0815AB90:
	adds r0, r2, r3
	ldrb r1, [r0, #2]
	strb r1, [r0, #1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r1, #0xff
	bne .L0815AB90
	b .L0815AB4C
.L0815ABA2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0815ABA8
sub_0815ABA8: @ 0x0815ABA8
.L0815ABA8:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L0815ABE4
	cmp r4, r0
	bne .L0815ABB6
	b .L0815AD80
.L0815ABB6:
	adds r0, r4, #0
	bl Stock_FindByDemonId
	adds r5, r0, #0
	cmp r5, #0
	bne .L0815ABC4
	b .L0815AD80
.L0815ABC4:
	movs r0, #0xff
	ands r0, r4
	bl Demon_GetRecord
	ldrb r1, [r0, #0x1e]
	ldr r0, .L0815ABE8
	adds r0, #0x80
	ldrb r0, [r0]
	cmp r1, r0
	bne .L0815ACA6
	movs r7, #0
.L0815ABDA:
	lsls r0, r7, #2
	ldr r1, .L0815ABEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L0815ABE4: .4byte 0x0000FFFF
.L0815ABE8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ABEC: .4byte gUnknown_0815ABF0
	.global gUnknown_0815ABF0
gUnknown_0815ABF0:
.L0815ABF0: @ jump table
	.4byte .L0815AC08
	.4byte .L0815AC14
	.4byte .L0815AC20
	.4byte .L0815AC2C
	.4byte .L0815AC38
	.4byte .L0815AC44
.L0815AC08:
	ldr r0, .L0815AC10
	adds r1, r5, #0
	adds r1, #0x5d
	b .L0815AC4A
.L0815AC10: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AC14:
	ldr r0, .L0815AC1C
	adds r1, r5, #0
	adds r1, #0x5e
	b .L0815AC4A
.L0815AC1C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AC20:
	ldr r0, .L0815AC28
	adds r1, r5, #0
	adds r1, #0x5f
	b .L0815AC4A
.L0815AC28: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AC2C:
	ldr r0, .L0815AC34
	adds r1, r5, #0
	adds r1, #0x60
	b .L0815AC4A
.L0815AC34: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AC38:
	ldr r0, .L0815AC40
	adds r1, r5, #0
	adds r1, #0x61
	b .L0815AC4A
.L0815AC40: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AC44:
	ldr r0, .L0815ACB4
	adds r1, r5, #0
	adds r1, #0x62
.L0815AC4A:
	ldrb r1, [r1]
	adds r0, #0x83
	strb r1, [r0]
	ldr r4, .L0815ACB4
	adds r6, r4, #0
	adds r6, #0x83
	ldrb r0, [r6]
	cmp r0, #0x3f
	bhi .L0815AC9C
	bl sub_0815AE68
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r4, #0
	adds r0, #0x80
	ldrb r0, [r0]
	cmp r1, r0
	bne .L0815AC9C
	bl sub_0815ADCC
	cmp r0, #0
	bne .L0815AC9C
	adds r3, r4, #0
	adds r3, #0x81
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r4, r0
	adds r1, r1, r2
	ldrb r0, [r6]
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, #1
	adds r0, r0, r2
	movs r1, #0xff
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
.L0815AC9C:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #5
	bls .L0815ABDA
.L0815ACA6:
	movs r7, #0
.L0815ACA8:
	lsls r0, r7, #2
	ldr r1, .L0815ACB8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L0815ACB4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ACB8: .4byte gUnknown_0815ACBC
	.global gUnknown_0815ACBC
gUnknown_0815ACBC:
.L0815ACBC: @ jump table
	.4byte .L0815ACD4
	.4byte .L0815ACE0
	.4byte .L0815ACEC
	.4byte .L0815ACF8
	.4byte .L0815AD10
	.4byte .L0815AD1C
.L0815ACD4:
	ldr r1, .L0815ACDC
	adds r0, r5, #0
	adds r0, #0x5d
	b .L0815AD22
.L0815ACDC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ACE0:
	ldr r1, .L0815ACE8
	adds r0, r5, #0
	adds r0, #0x5e
	b .L0815AD22
.L0815ACE8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ACEC:
	ldr r1, .L0815ACF4
	adds r0, r5, #0
	adds r0, #0x5f
	b .L0815AD22
.L0815ACF4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ACF8:
	ldr r0, .L0815AD0C
	adds r1, r5, #0
	adds r1, #0x60
	ldrb r1, [r1]
	adds r3, r0, #0
	adds r3, #0x83
	strb r1, [r3]
	adds r6, r0, #0
	b .L0815AD2C
	.byte 0x00, 0x00
.L0815AD0C: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AD10:
	ldr r1, .L0815AD18
	adds r0, r5, #0
	adds r0, #0x61
	b .L0815AD22
.L0815AD18: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AD1C:
	ldr r1, .L0815AD88
	adds r0, r5, #0
	adds r0, #0x62
.L0815AD22:
	ldrb r0, [r0]
	adds r3, r1, #0
	adds r3, #0x83
	strb r0, [r3]
	adds r6, r1, #0
.L0815AD2C:
	adds r4, r6, #0
	adds r4, #0x83
	ldrb r0, [r4]
	subs r0, #0x24
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x15
	bhi .L0815AD76
	ldrb r0, [r4]
	bl sub_0815AD8C
	cmp r0, #0
	bne .L0815AD76
	bl sub_0815AE18
	cmp r0, #0
	bne .L0815AD76
	adds r3, r6, #0
	adds r3, #0x82
	movs r1, #0
	ldrsb r1, [r3, r1]
	adds r1, #0x20
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r2, r6, r0
	adds r1, r1, r2
	ldrb r0, [r4]
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, #0x21
	adds r0, r0, r2
	movs r1, #0xff
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
.L0815AD76:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #5
	bls .L0815ACA8
.L0815AD80:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0815AD88: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815AD8C
sub_0815AD8C: @ 0x0815AD8C
.L0815AD8C:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r2, #0
	ldr r0, .L0815ADAC
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #0xff
	beq .L0815ADC2
	adds r4, r0, #0
.L0815ADA4:
	cmp r1, r3
	bne .L0815ADB0
	movs r0, #1
	b .L0815ADC4
.L0815ADAC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ADB0:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #5
	bhi .L0815ADC2
	adds r0, r2, r4
	ldrb r1, [r0]
	cmp r1, #0xff
	bne .L0815ADA4
.L0815ADC2:
	movs r0, #0
.L0815ADC4:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815ADCC
sub_0815ADCC: @ 0x0815ADCC
.L0815ADCC:
	push {lr}
	ldr r2, .L0815ADE4
	adds r0, r2, #0
	adds r0, #0x81
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0815ADEC
	b .L0815AE12
	.byte 0x00, 0x00
.L0815ADE4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815ADE8:
	movs r0, #1
	b .L0815AE14
.L0815ADEC:
	subs r0, r1, #1
	lsls r1, r0, #0x18
	cmp r1, #0
	blt .L0815AE12
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r3, r2, r0
	adds r0, r2, #0
	adds r0, #0x83
	ldrb r2, [r0]
.L0815AE00:
	asrs r1, r1, #0x18
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	beq .L0815ADE8
	subs r0, r1, #1
	lsls r1, r0, #0x18
	cmp r1, #0
	bge .L0815AE00
.L0815AE12:
	movs r0, #0
.L0815AE14:
	pop {r1}
	bx r1

	thumb_func_start sub_0815AE18
sub_0815AE18: @ 0x0815AE18
.L0815AE18:
	push {lr}
	ldr r2, .L0815AE30
	adds r0, r2, #0
	adds r0, #0x82
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0815AE38
	b .L0815AE62
	.byte 0x00, 0x00
.L0815AE30: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AE34:
	movs r0, #1
	b .L0815AE64
.L0815AE38:
	subs r0, r1, #1
	lsls r1, r0, #0x18
	cmp r1, #0
	blt .L0815AE62
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r3, r2, r0
	adds r0, r2, #0
	adds r0, #0x83
	ldrb r2, [r0]
.L0815AE4C:
	asrs r1, r1, #0x18
	adds r0, r1, #0
	adds r0, #0x20
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, r2
	beq .L0815AE34
	subs r0, r1, #1
	lsls r1, r0, #0x18
	cmp r1, #0
	bge .L0815AE4C
.L0815AE62:
	movs r0, #0
.L0815AE64:
	pop {r1}
	bx r1

	thumb_func_start sub_0815AE68
sub_0815AE68: @ 0x0815AE68
.L0815AE68:
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r1
	lsrs r0, r0, #0x10
	bl sub_080BF5C0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	pop {r1}
	bx r1

	thumb_func_start sub_0815AE84
sub_0815AE84: @ 0x0815AE84
.L0815AE84:
	push {lr}
	ldr r1, .L0815AEB8
	adds r0, r1, #0
	adds r0, #0x90
	ldrh r0, [r0]
	adds r2, r1, #0
	adds r2, #0x8a
	strh r0, [r2]
	adds r0, r1, #0
	adds r0, #0x92
	ldrh r2, [r0]
	subs r0, #6
	strh r2, [r0]
	adds r0, #8
	ldrh r0, [r0]
	adds r1, #0x8e
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L0815AEBC
	cmp r0, r1
	bne .L0815AEC0
	bl sub_0815B08C
	b .L0815AED2
	.byte 0x00, 0x00
.L0815AEB8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AEBC: .4byte 0x0000FFFF
.L0815AEC0:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bne .L0815AECE
	bl sub_0815AFB0
	b .L0815AED2
.L0815AECE:
	bl sub_0815AF00
.L0815AED2:
	adds r3, r0, #0
	ldr r2, .L0815AEFC
	adds r0, r2, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x8e
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	adds r0, r3, #0
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815AEFC: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815AF00
sub_0815AF00: @ 0x0815AF00
.L0815AF00:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r4, #0
	ldr r6, .L0815AF7C
	ldr r3, .L0815AF80
	adds r0, r3, #0
	adds r0, #0x94
	ldrh r0, [r0]
	mov r8, r0
	movs r0, #0xa0
	adds r0, r0, r3
	mov sl, r0
	movs r1, #0x92
	adds r1, r1, r3
	mov ip, r1
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r5, r5, r3
	mov sb, r5
.L0815AF2E:
	adds r0, r4, #2
	ldr r7, .L0815AF7C
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, r8
	bne .L0815AF84
	adds r0, r4, r6
	ldrb r0, [r0]
	adds r2, r0, #0
	adds r0, r4, #1
	adds r0, r0, r6
	ldrb r1, [r0]
	str r1, [sp]
	adds r0, r3, #0
	adds r0, #0x90
	ldrh r0, [r0]
	cmp r2, r0
	bne .L0815AF5A
	mov r5, ip
	ldrh r5, [r5]
	cmp r1, r5
	beq .L0815AF68
.L0815AF5A:
	mov r7, ip
	ldrh r7, [r7]
	cmp r2, r7
	bne .L0815AF84
	ldr r1, [sp]
	cmp r1, r0
	bne .L0815AF84
.L0815AF68:
	adds r0, r4, #3
	ldr r5, .L0815AF7C
	adds r0, r0, r5
	ldrb r0, [r0]
	mov r7, sb
	strh r0, [r7]
	mov r1, sl
	strh r0, [r1]
	movs r0, #1
	b .L0815AFA0
.L0815AF7C: .4byte gUnknown_087F1C53
.L0815AF80: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815AF84:
	adds r0, r4, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x77
	bls .L0815AF2E
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r0, r3, r5
	movs r1, #0xff
	strh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xa0
	strh r1, [r0]
	movs r0, #0
.L0815AFA0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0815AFB0
sub_0815AFB0: @ 0x0815AFB0
.L0815AFB0:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r3, .L0815B014
	adds r0, r3, #0
	adds r0, #0x90
	ldrh r1, [r0]
	subs r1, #0x40
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0x11
	lsrs r2, r0, #0x10
	movs r6, #0
	adds r5, r3, #0
	mov sb, r5
	movs r0, #0xa2
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x94
.L0815AFDA:
	ldr r0, .L0815B018
	adds r0, r2, r0
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L0815B030
	movs r4, #0xa4
	lsls r4, r4, #2
	add r4, sb
	strh r2, [r4]
	movs r0, #0x3f
	ands r1, r0
	mov r2, r8
	strb r1, [r2]
	ldrh r0, [r7]
	bl Demon_GetRace
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov r0, r8
	ldrb r0, [r0]
	cmp r2, r0
	beq .L0815B020
	ldrh r2, [r4]
	ldr r1, .L0815B01C
	adds r5, r4, r1
	b .L0815B054
	.byte 0x00, 0x00
.L0815B014: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B018: .4byte gUnknown_087F1B13
.L0815B01C: .4byte 0xFFFFFD70
.L0815B020:
	ldrh r2, [r4]
	ldr r0, .L0815B02C
	adds r0, r2, r0
	ldrb r1, [r0]
	strh r1, [r4]
	b .L0815B044
.L0815B02C: .4byte gUnknown_087F1BB3
.L0815B030:
	ldrh r0, [r7]
	cmp r1, r0
	bne .L0815B054
	ldr r0, .L0815B050
	adds r0, r2, r0
	ldrb r1, [r0]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
.L0815B044:
	adds r0, r5, #0
	adds r0, #0xa0
	strh r1, [r0]
	movs r0, #1
	b .L0815B07E
	.byte 0x00, 0x00
.L0815B050: .4byte gUnknown_087F1BB3
.L0815B054:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #4
	bls .L0815AFDA
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #0xff
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0xa0
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa6
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
.L0815B07E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_0815B08C
sub_0815B08C: @ 0x0815B08C
.L0815B08C:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r3, .L0815B0E0
	adds r0, r3, #0
	adds r0, #0x90
	ldrh r1, [r0]
	subs r1, #0x40
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0x11
	lsrs r5, r0, #0x10
	movs r2, #5
	ldr r0, .L0815B0E4
	mov r8, r0
	adds r0, r3, #0
	adds r0, #0x92
	ldrh r4, [r0]
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r1, r1, r3
	mov ip, r1
	ldr r6, .L0815B0E8
	movs r7, #0xa0
	adds r7, r7, r3
	mov sb, r7
.L0815B0C2:
	adds r1, r5, r2
	mov r7, r8
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, r4
	bne .L0815B0EC
	adds r0, r1, r6
	ldrb r0, [r0]
	mov r1, ip
	strh r0, [r1]
	mov r7, sb
	strh r0, [r7]
	movs r0, #1
	b .L0815B110
	.byte 0x00, 0x00
.L0815B0E0: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B0E4: .4byte gUnknown_087F1B13
.L0815B0E8: .4byte gUnknown_087F1BB3
.L0815B0EC:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #9
	bls .L0815B0C2
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r1, #0xff
	strh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xa0
	strh r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa6
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #0
.L0815B110:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_0815B11C
sub_0815B11C: @ 0x0815B11C
.L0815B11C:
	push {r4, r5, r6, lr}
	bl Random_Byte
	adds r4, r0, #0
	movs r0, #0xff
	ands r4, r0
	movs r0, #0xd8
	bl Flag_Test
	cmp r0, #0
	bne .L0815B140
	cmp r4, #0
	beq .L0815B140
	ldr r0, .L0815B13C
	b .L0815B23C
	.byte 0x00, 0x00
.L0815B13C: .4byte 0x0000FFFF
.L0815B140:
	ldr r3, .L0815B170
	adds r2, r3, #0
	adds r2, #0xa4
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, .L0815B174
	ldrb r2, [r0, #0xd]
	adds r0, r3, #0
	adds r0, #0x8e
	ldrh r1, [r0]
	ldr r0, .L0815B178
	cmp r1, r0
	bne .L0815B194
	cmp r2, #0x3a
	bhi .L0815B17C
	adds r1, r2, #0
	adds r1, #0x10
	adds r0, r3, #0
	adds r0, #0x9c
	strb r1, [r0]
	b .L0815B184
	.byte 0x00, 0x00
.L0815B170: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B174: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815B178: .4byte 0x0000FFFF
.L0815B17C:
	adds r1, r3, #0
	adds r1, #0x9c
	movs r0, #0x4b
	strb r0, [r1]
.L0815B184:
	adds r0, r3, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #0x19
	bls .L0815B1C2
	adds r1, r0, #0
	subs r1, #0x19
	b .L0815B1BA
.L0815B194:
	cmp r2, #0x30
	bhi .L0815B1A4
	adds r1, r2, #0
	adds r1, #0x1a
	adds r0, r3, #0
	adds r0, #0x9c
	strb r1, [r0]
	b .L0815B1AC
.L0815B1A4:
	adds r1, r3, #0
	adds r1, #0x9c
	movs r0, #0x4b
	strb r0, [r1]
.L0815B1AC:
	adds r0, r3, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #0x28
	bls .L0815B1C2
	adds r1, r0, #0
	subs r1, #0x28
.L0815B1BA:
	adds r0, r3, #0
	adds r0, #0x9d
	strb r1, [r0]
	b .L0815B1CA
.L0815B1C2:
	adds r1, r3, #0
	adds r1, #0x9d
	movs r0, #0
	strb r0, [r1]
.L0815B1CA:
	movs r4, #0
.L0815B1CC:
	bl sub_08159144
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xff
	beq .L0815B20E
	adds r6, r2, #0
	adds r0, r6, #0
	bl sub_0815BA28
	cmp r0, #0
	beq .L0815B20E
	adds r0, r6, #0
	bl Demon_GetLevel
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, .L0815B244
	adds r0, r1, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r2, r0
	bhs .L0815B20E
	adds r0, r1, #0
	adds r0, #0x9d
	ldrb r0, [r0]
	cmp r2, r0
	blo .L0815B20E
	adds r0, r6, #0
	bl Stock_FindByDemonId
	cmp r0, #0
	beq .L0815B218
.L0815B20E:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x1f
	bls .L0815B1CC
.L0815B218:
	cmp r4, #0x20
	bne .L0815B228
	movs r6, #0xfb
	movs r0, #0xfb
	bl Stock_FindByDemonId
	cmp r0, #0
	bne .L0815B1CA
.L0815B228:
	ldr r4, .L0815B244
	adds r5, r4, #0
	adds r5, #0xa0
	strh r6, [r5]
	ldrh r0, [r5]
	bl Demon_GetRace
	adds r4, #0xa2
	strb r0, [r4]
	ldrh r0, [r5]
.L0815B23C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815B244: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815B248
sub_0815B248: @ 0x0815B248
.L0815B248:
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_0815B24C
sub_0815B24C: @ 0x0815B24C
	push {lr}
	ldr r0, .L0815B25C
	adds r0, #0xa5
	ldrb r0, [r0]
	bl Stock_FindByDemonId
	pop {r1}
	bx r1
.L0815B25C: .4byte 0x0203B868 @ EWRAM+0x3B868

	thumb_func_start sub_0815B260
sub_0815B260: @ 0x0815B260
.L0815B260:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r5, .L0815B2E0
	adds r6, r5, #0
	adds r6, #0x90
	ldrh r1, [r6]
	ldr r0, .L0815B2E4
	strh r1, [r0]
	movs r2, #0x92
	adds r2, r2, r5
	mov r8, r2
	ldrh r2, [r2]
	ldr r3, .L0815B2E8
	strh r2, [r3]
	movs r0, #0x94
	adds r0, r0, r5
	mov sb, r0
	ldrh r0, [r0]
	ldr r3, .L0815B2EC
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsls r0, r2, #0x10
	cmp r1, r0
	bls .L0815B29E
	ldrh r0, [r6]
	strh r2, [r6]
	mov r1, r8
	strh r0, [r1]
.L0815B29E:
	mov r2, sb
	ldrh r1, [r2]
	ldrh r0, [r6]
	cmp r0, r1
	bls .L0815B2AC
	strh r1, [r6]
	strh r0, [r2]
.L0815B2AC:
	mov r3, sb
	ldrh r1, [r3]
	mov r2, r8
	ldrh r0, [r2]
	cmp r0, r1
	bls .L0815B2BC
	strh r1, [r2]
	strh r0, [r3]
.L0815B2BC:
	adds r7, r5, #0
	adds r7, #0xa0
	ldrh r1, [r7]
	ldr r0, .L0815B2F0
	cmp r1, r0
	bne .L0815B2CA
	b .L0815B3C0
.L0815B2CA:
	bl sub_0815A6F0
	bl sub_0815B248
	ldrh r0, [r7]
	bl Stock_FindByDemonId
	cmp r0, #0
	beq .L0815B2F4
	movs r0, #4
	b .L0815B3D8
.L0815B2E0: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B2E4: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B2E8: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B2EC: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6
.L0815B2F0: .4byte 0x0000FFFF
.L0815B2F4:
	ldrh r4, [r7]
	adds r0, r4, #0
	bl Demon_GetRecord
	movs r3, #0xff
	mov sl, r3
	ldrb r2, [r0, #1]
	ldr r0, .L0815B334
	ldrb r4, [r0, #0xd]
	adds r0, r5, #0
	adds r0, #0xa4
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L0815B316
	adds r4, #9
.L0815B316:
	cmp r4, r2
	bhs .L0815B344
	ldr r1, .L0815B338
	ldrh r0, [r1]
	strh r0, [r6]
	ldr r2, .L0815B33C
	ldrh r0, [r2]
	mov r3, r8
	strh r0, [r3]
	ldr r1, .L0815B340
	ldrh r0, [r1]
	mov r2, sb
	strh r0, [r2]
	movs r0, #3
	b .L0815B3D8
.L0815B334: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815B338: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B33C: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B340: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6
.L0815B344:
	ldrh r0, [r7]
	bl sub_0815B958
	mov r4, sl
	ands r4, r0
	ldr r0, .L0815B388
	adds r0, #0x58
	ldrh r0, [r0]
	lsrs r2, r0, #8
	adds r0, r2, #0
	bl sub_0815B970
	mov r2, sl
	ands r2, r0
	cmp r4, #1
	beq .L0815B398
	cmp r2, #1
	beq .L0815B398
	cmp r2, r4
	beq .L0815B398
	ldr r3, .L0815B38C
	ldrh r0, [r3]
	strh r0, [r6]
	ldr r1, .L0815B390
	ldrh r0, [r1]
	mov r2, r8
	strh r0, [r2]
	ldr r3, .L0815B394
	ldrh r0, [r3]
	mov r1, sb
	strh r0, [r1]
	movs r0, #2
	b .L0815B3D8
	.byte 0x00, 0x00
.L0815B388: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815B38C: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B390: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B394: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6
.L0815B398:
	ldr r2, .L0815B3BC
	adds r0, r2, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x8e
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	movs r0, #1
	b .L0815B3D8
.L0815B3BC: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B3C0:
	ldr r2, .L0815B3E8
	ldrh r0, [r2]
	strh r0, [r6]
	ldr r3, .L0815B3EC
	ldrh r0, [r3]
	mov r1, r8
	strh r0, [r1]
	ldr r2, .L0815B3F0
	ldrh r0, [r2]
	mov r3, sb
	strh r0, [r3]
	movs r0, #0
.L0815B3D8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815B3E8: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B3EC: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B3F0: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6

	thumb_func_start sub_0815B3F4
sub_0815B3F4: @ 0x0815B3F4
.L0815B3F4:
	push {r4, r5, lr}
	ldr r4, .L0815B464
	adds r1, r4, #0
	adds r1, #0x90
	ldrh r0, [r1]
	ldr r5, .L0815B468
	cmp r0, r5
	beq .L0815B40A
	movs r1, #2
	bl ItemStock_Remove
.L0815B40A:
	adds r1, r4, #0
	adds r1, #0x92
	ldrh r0, [r1]
	cmp r0, r5
	beq .L0815B41A
	movs r1, #2
	bl ItemStock_Remove
.L0815B41A:
	adds r1, r4, #0
	adds r1, #0x94
	ldrh r0, [r1]
	cmp r0, r5
	beq .L0815B42A
	movs r1, #2
	bl ItemStock_Remove
.L0815B42A:
	adds r4, #0xa0
	ldrh r0, [r4]
	movs r1, #4
	bl ItemStock_Add
	movs r0, #0xe0
	bl Flag_Test
	cmp r0, #0
	bne .L0815B4AC
	ldrh r0, [r4]
	bl sub_0815B958
	movs r2, #3
	ands r2, r0
	cmp r2, #0
	bne .L0815B474
	ldr r0, .L0815B46C
	adds r3, r0, #0
	adds r3, #0x58
	ldrh r1, [r3]
	adds r4, r0, #0
	cmp r1, #0x19
	bls .L0815B470
	adds r0, r1, #0
	subs r0, #0x1a
	strh r0, [r3]
	b .L0815B49A
	.byte 0x00, 0x00
.L0815B464: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B468: .4byte 0x0000FFFF
.L0815B46C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815B470:
	strh r2, [r3]
	b .L0815B49A
.L0815B474:
	ldr r4, .L0815B48C
	cmp r2, #2
	bne .L0815B49A
	adds r2, r4, #0
	adds r2, #0x58
	ldrh r1, [r2]
	ldr r0, .L0815B490
	cmp r1, r0
	bhi .L0815B494
	adds r0, r1, #0
	adds r0, #0x1a
	b .L0815B498
.L0815B48C: .4byte 0x030046C0 @ IWRAM+0x46C0
.L0815B490: .4byte 0x0000FFE6
.L0815B494:
	adds r0, r5, #0
	orrs r0, r1
.L0815B498:
	strh r0, [r2]
.L0815B49A:
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r1, [r0]
	adds r0, #0x80
	strh r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
.L0815B4AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0815B4B4
sub_0815B4B4: @ 0x0815B4B4
.L0815B4B4:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r5, .L0815B5B4
	adds r4, r5, #0
	adds r4, #0x90
	ldrh r1, [r4]
	ldr r0, .L0815B5B8
	strh r1, [r0]
	movs r2, #0x92
	adds r2, r2, r5
	mov sb, r2
	ldrh r2, [r2]
	ldr r3, .L0815B5BC
	strh r2, [r3]
	adds r6, r5, #0
	adds r6, #0x94
	ldrh r0, [r6]
	ldr r3, .L0815B5C0
	strh r0, [r3]
	lsls r1, r1, #0x10
	lsls r0, r2, #0x10
	cmp r1, r0
	bls .L0815B4F2
	ldrh r0, [r4]
	strh r2, [r4]
	mov r1, sb
	strh r0, [r1]
.L0815B4F2:
	ldrh r1, [r6]
	ldrh r0, [r4]
	cmp r0, r1
	bls .L0815B4FE
	strh r1, [r4]
	strh r0, [r6]
.L0815B4FE:
	ldrh r1, [r6]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, r1
	bls .L0815B50C
	strh r1, [r2]
	strh r0, [r6]
.L0815B50C:
	ldrh r0, [r4]
	adds r2, r5, #0
	adds r2, #0x96
	ldr r1, .L0815B5C4
	bl Demon_GetRaceAndAlign
	mov r3, sb
	ldrh r0, [r3]
	movs r1, #0x9a
	adds r1, r1, r5
	mov sl, r1
	adds r2, r5, #0
	adds r2, #0x97
	bl Demon_GetRaceAndAlign
	ldrh r1, [r6]
	ldr r0, .L0815B5C8
	cmp r1, r0
	bne .L0815B534
	b .L0815B772
.L0815B534:
	adds r0, r1, #0
	adds r4, r5, #0
	adds r4, #0x9b
	adds r2, r5, #0
	adds r2, #0x98
	adds r1, r4, #0
	bl Demon_GetRaceAndAlign
	ldr r2, .L0815B5C4
	ldrb r0, [r2]
	cmp r0, #0xb
	bne .L0815B55C
	mov r3, sl
	ldrb r0, [r3]
	cmp r0, #0xb
	beq .L0815B566
	ldrb r0, [r4]
	adds r4, r5, #0
	cmp r0, #0xb
	bne .L0815B59C
.L0815B55C:
	mov r1, sl
	ldrb r0, [r1]
	adds r4, r5, #0
	cmp r0, #0xb
	bne .L0815B57E
.L0815B566:
	ldr r1, .L0815B5B4
	adds r0, r1, #0
	adds r0, #0x9b
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #0xb
	beq .L0815B588
	adds r0, r4, #0
	adds r0, #0x99
	ldrb r0, [r0]
	cmp r0, #0xb
	bne .L0815B59C
.L0815B57E:
	adds r0, r4, #0
	adds r0, #0x9b
	ldrb r0, [r0]
	cmp r0, #0xb
	bne .L0815B5CC
.L0815B588:
	adds r0, r4, #0
	adds r0, #0x99
	ldrb r0, [r0]
	cmp r0, #0xb
	beq .L0815B5CC
	adds r0, r4, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	cmp r0, #0xb
	beq .L0815B5CC
.L0815B59C:
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r4, #0
	b .L0815B7DC
.L0815B5B4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B5B8: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B5BC: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B5C0: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6
.L0815B5C4: .4byte 0x0203B901 @ EWRAM+0x3B901
.L0815B5C8: .4byte 0x0000FFFF
.L0815B5CC:
	adds r0, r4, #0
	adds r0, #0x96
	ldrb r0, [r0]
	cmp r0, #0x1a
	bhi .L0815B5EA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #0x1a
	bhi .L0815B5EA
	adds r0, r4, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0x1a
	bls .L0815B602
.L0815B5EA:
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r4, #0
	b .L0815B804
.L0815B602:
	adds r0, r4, #0
	adds r0, #0x90
	ldrh r0, [r0]
	bl Demon_GetLevel
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r4, #0
	adds r0, #0x92
	ldrh r0, [r0]
	bl Demon_GetLevel
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	bl Demon_GetLevel
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r6, r5
	blo .L0815B65C
	cmp r6, r0
	blo .L0815B65C
	adds r1, r4, #0
	adds r1, #0x99
	ldrb r1, [r1]
	str r1, [sp]
	cmp r5, r0
	blo .L0815B64E
	adds r0, r4, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x9b
	b .L0815B6C4
.L0815B64E:
	adds r0, r4, #0
	adds r0, #0x9b
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x9a
	b .L0815B6C4
.L0815B65C:
	cmp r5, r6
	blo .L0815B68E
	cmp r5, r0
	blo .L0815B68E
	ldr r1, .L0815B684
	adds r2, r1, #0
	adds r2, #0x9a
	ldrb r2, [r2]
	str r2, [sp]
	adds r4, r1, #0
	cmp r6, r0
	blo .L0815B688
	adds r0, r4, #0
	adds r0, #0x99
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x9b
	b .L0815B6C4
	.byte 0x00, 0x00
.L0815B684: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B688:
	adds r0, r4, #0
	adds r0, #0x9b
	b .L0815B6BC
.L0815B68E:
	ldr r4, .L0815B6B4
	cmp r0, r6
	blo .L0815B6C6
	cmp r0, r5
	blo .L0815B6C6
	adds r0, r4, #0
	adds r0, #0x9b
	ldrb r0, [r0]
	str r0, [sp]
	cmp r6, r5
	blo .L0815B6B8
	adds r0, r4, #0
	adds r0, #0x99
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x9a
	b .L0815B6C4
	.byte 0x00, 0x00
.L0815B6B4: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B6B8:
	adds r0, r4, #0
	adds r0, #0x9a
.L0815B6BC:
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r0, #0x99
.L0815B6C4:
	ldrb r7, [r0]
.L0815B6C6:
	ldr r2, [sp]
	cmp r2, #3
	bne .L0815B6E0
	mov r3, r8
	cmp r3, #3
	bne .L0815B6D6
	cmp r7, #2
	beq .L0815B742
.L0815B6D6:
	mov r0, r8
	cmp r0, #2
	bne .L0815B6E0
	cmp r7, #3
	beq .L0815B742
.L0815B6E0:
	ldr r1, [sp]
	cmp r1, #7
	bne .L0815B70E
	mov r2, r8
	cmp r2, #7
	bne .L0815B6F0
	cmp r7, #5
	beq .L0815B742
.L0815B6F0:
	mov r3, r8
	cmp r3, #5
	bne .L0815B6FA
	cmp r7, #7
	beq .L0815B742
.L0815B6FA:
	mov r0, r8
	cmp r0, #1
	bne .L0815B704
	cmp r7, #5
	beq .L0815B742
.L0815B704:
	mov r1, r8
	cmp r1, #5
	bne .L0815B70E
	cmp r7, #1
	beq .L0815B742
.L0815B70E:
	ldr r2, [sp]
	cmp r2, #6
	bne .L0815B728
	mov r3, r8
	cmp r3, #1
	bne .L0815B71E
	cmp r7, #7
	beq .L0815B742
.L0815B71E:
	mov r0, r8
	cmp r0, #7
	bne .L0815B728
	cmp r7, #1
	beq .L0815B742
.L0815B728:
	ldr r1, [sp]
	cmp r1, #5
	bne .L0815B75A
	mov r2, r8
	cmp r2, #5
	bne .L0815B738
	cmp r7, #3
	beq .L0815B742
.L0815B738:
	mov r3, r8
	cmp r3, #3
	bne .L0815B75A
	cmp r7, #5
	bne .L0815B75A
.L0815B742:
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r4, #0
	b .L0815B7DC
.L0815B75A:
	adds r0, r4, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r4, #0
	b .L0815B804
.L0815B772:
	ldrh r0, [r4]
	cmp r0, #0xfb
	beq .L0815B780
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0xfb
	bne .L0815B7A4
.L0815B780:
	ldr r2, .L0815B798
	ldrh r0, [r2]
	strh r0, [r4]
	ldr r3, .L0815B79C
	ldrh r0, [r3]
	mov r1, sb
	strh r0, [r1]
	ldr r2, .L0815B7A0
	ldrh r0, [r2]
	strh r0, [r6]
	b .L0815B80C
	.byte 0x00, 0x00
.L0815B798: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2
.L0815B79C: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4
.L0815B7A0: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6
.L0815B7A4:
	ldr r3, .L0815B7B8
	ldrb r0, [r3]
	cmp r0, #0xb
	bne .L0815B7BC
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0xb
	bne .L0815B7C4
	b .L0815B7EC
	.byte 0x00, 0x00
.L0815B7B8: .4byte 0x0203B901 @ EWRAM+0x3B901
.L0815B7BC:
	mov r2, sl
	ldrb r0, [r2]
	cmp r0, #0xb
	bne .L0815B7EC
.L0815B7C4:
	ldr r2, .L0815B7E8
	adds r0, r2, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r2, #0
.L0815B7DC:
	adds r0, #0x8e
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	movs r0, #1
	b .L0815B80E
.L0815B7E8: .4byte 0x0203B868 @ EWRAM+0x3B868
.L0815B7EC:
	ldr r2, .L0815B820
	adds r0, r2, #0
	adds r0, #0x8a
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
	subs r0, #4
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x92
	strh r0, [r1]
	adds r0, r2, #0
.L0815B804:
	adds r0, #0x8e
	ldrh r1, [r0]
	adds r0, #6
	strh r1, [r0]
.L0815B80C:
	movs r0, #0
.L0815B80E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.L0815B820: .4byte 0x0203B868 @ EWRAM+0x3B868
