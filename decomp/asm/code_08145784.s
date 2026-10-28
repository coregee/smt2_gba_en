	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_08145784
sub_08145784: @ 0x08145784
	ldr r0, .L08145790
	adds r0, #0x96
	movs r1, #1
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L08145790: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08145794
sub_08145794: @ 0x08145794
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r2, .L081457B4
	movs r0, #0
	strh r0, [r5, #0x1c]
	cmp r1, #0
	bne .L081457B8
	adds r0, r2, #0
	adds r0, #0xa0
	ldr r0, [r0]
	cmp r0, #0
	beq .L081457EE
	movs r0, #1
	strh r0, [r5, #0x1c]
	b .L081457EE
	.byte 0x00, 0x00
.L081457B4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081457B8:
	movs r4, #1
	ldr r0, .L081457F4
	ldrh r1, [r0]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	adds r6, r2, #0
	adds r6, #0xa0
	cmp r0, #0
	beq .L081457D4
	ldr r0, [r6]
	bl sub_081493D4
	adds r4, r0, #0
.L081457D4:
	ldr r0, .L081457F8
	bl sub_080C51D4
	ldr r0, [r6]
	subs r0, r0, r4
	str r0, [r6]
	adds r0, r4, #0
	bl sub_080C31B4
	ldr r0, [r6]
	cmp r0, #0
	bne .L081457EE
	strh r7, [r5, #0x1c]
.L081457EE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L081457F4: .4byte 0x03003964 @ IWRAM+0x3964
.L081457F8: .4byte 0x00000159

	thumb_func_start sub_081457FC
sub_081457FC: @ 0x081457FC
.L081457FC:
	push {r4, lr}
	ldr r4, .L08145814
	ldr r0, .L08145818
	ldr r1, .L0814581C
	bl Task_Create
	movs r0, #4
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08145814: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145818: .4byte gUnknown_0879AC84
.L0814581C: .4byte 0x0000FFFF

	thumb_func_start sub_08145820
sub_08145820: @ 0x08145820
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r0, #0x24
	adds r0, r0, r5
	mov r8, r0
	ldrh r1, [r5, #0x24]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L0814588C
	adds r0, r0, r1
	ldr r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_08145290
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldrh r1, [r5, #0x24]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L0814588C
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_08145290
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrh r1, [r5, #0x24]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L08145890
	adds r0, r0, r1
	ldr r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_08145290
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, #5
	beq .L08145894
	adds r6, r4, #0
	b .L081458A2
.L0814588C: .4byte gUnknown_0879AC18
.L08145890: .4byte gUnknown_0879AC20
.L08145894:
	cmp r7, #5
	beq .L0814589C
	adds r6, r7, #0
	b .L081458A2
.L0814589C:
	cmp r0, #5
	beq .L081458A2
	adds r6, r0, #0
.L081458A2:
	ldr r0, .L081458BC
	lsls r1, r6, #2
	adds r1, r1, r0
	ldr r0, [r1]
	mov r1, r8
	str r0, [r1, #8]
	strh r6, [r1, #2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081458BC: .4byte gUnknown_0879B53C

	thumb_func_start sub_081458C0
sub_081458C0: @ 0x081458C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r7, .L081458FC
	adds r4, r5, #0
	adds r4, #0x24
	movs r3, #1
	ldr r0, .L08145900
	ldrh r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L081458E2
	ldr r0, [r4, #8]
	bl sub_081493D4
	adds r3, r0, #0
.L081458E2:
	ldr r0, [r4, #8]
	subs r0, r0, r3
	str r0, [r4, #8]
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r1, [r2]
	adds r1, r1, r3
	str r1, [r2]
	cmp r0, #0
	beq .L08145904
	movs r0, #0
	strh r0, [r5, #0x1c]
	b .L08145906
.L081458FC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145900: .4byte 0x03003964 @ IWRAM+0x3964
.L08145904:
	strh r6, [r5, #0x1c]
.L08145906:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814590C
sub_0814590C: @ 0x0814590C
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r1, [r0, #0x24]
	movs r2, #0
	bl sub_08145488
	ldrh r0, [r4, #2]
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08145934
sub_08145934: @ 0x08145934
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r2, #0
	adds r4, #0x24
	ldr r0, .L08145970
	ldr r0, [r0]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L08145974
	ldrh r1, [r2, #0x24]
	adds r0, r2, #0
	movs r2, #1
	bl sub_08145488
	movs r0, #0xaf
	lsls r0, r0, #1
	bl sub_080C51D4
	ldrh r0, [r4, #2]
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	b .L08145990
.L08145970: .4byte 0x030031BC @ IWRAM+0x31BC
.L08145974:
	ldrh r1, [r2, #0x24]
	adds r0, r2, #0
	movs r2, #0
	bl sub_08145488
	ldrh r0, [r4, #2]
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
.L08145990:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08145998
sub_08145998: @ 0x08145998
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, .L081459B0
	ldrh r1, [r2, #2]
	bl Task_Create
	strh r4, [r0, #0x24]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081459B0: .4byte gUnknown_0879B550

	thumb_func_start sub_081459B4
sub_081459B4: @ 0x081459B4
	push {r4, r5, lr}
	ldr r5, .L081459D0
	adds r4, r0, #0
	adds r4, #0x24
	ldrh r0, [r0, #0x24]
	cmp r0, #9
	bne .L081459D8
	ldr r1, .L081459D4
	adds r0, r5, #0
	adds r0, #0x98
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	b .L08145A50
.L081459D0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081459D4: .4byte gUnknown_0879B5A0
.L081459D8:
	ldrh r0, [r4, #2]
	cmp r0, #4
	bhi .L08145A52
	lsls r0, r0, #2
	ldr r1, .L081459E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L081459E8: .4byte gUnknown_081459EC
	.global gUnknown_081459EC
gUnknown_081459EC:
.L081459EC: @ jump table
	.4byte .L08145A00
	.4byte .L08145A30
	.4byte .L08145A38
	.4byte .L08145A08
	.4byte .L08145A10
.L08145A00:
	ldr r2, .L08145A04
	b .L08145A12
.L08145A04: .4byte gUnknown_0879B804
.L08145A08:
	ldr r2, .L08145A0C
	b .L08145A12
.L08145A0C: .4byte gUnknown_0879B704
.L08145A10:
	ldr r2, .L08145A2C
.L08145A12:
	ldrh r1, [r4]
	subs r1, #5
	lsls r1, r1, #2
	adds r0, r5, #0
	adds r0, #0x98
	ldr r0, [r0]
	subs r0, #1
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r1, r1, r2
	ldr r1, [r1]
	b .L08145A52
	.byte 0x00, 0x00
.L08145A2C: .4byte gUnknown_0879B784
.L08145A30:
	ldr r3, .L08145A34
	b .L08145A3A
.L08145A34: .4byte gUnknown_0879B5C4
.L08145A38:
	ldr r3, .L08145A5C
.L08145A3A:
	ldrh r2, [r4]
	subs r2, #4
	adds r0, r5, #0
	adds r0, #0x98
	ldr r1, [r0]
	subs r1, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r3
.L08145A50:
	ldr r1, [r0]
.L08145A52:
	str r1, [r4, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08145A5C: .4byte gUnknown_0879B664

	thumb_func_start sub_08145A60
sub_08145A60: @ 0x08145A60
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r7, .L08145A9C
	adds r4, r5, #0
	adds r4, #0x24
	movs r3, #1
	ldr r0, .L08145AA0
	ldrh r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L08145A82
	ldr r0, [r4, #8]
	bl sub_081493D4
	adds r3, r0, #0
.L08145A82:
	ldr r0, [r4, #8]
	subs r0, r0, r3
	str r0, [r4, #8]
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r1, [r2]
	adds r1, r1, r3
	str r1, [r2]
	cmp r0, #0
	beq .L08145AA4
	movs r0, #0
	strh r0, [r5, #0x1c]
	b .L08145AA6
.L08145A9C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145AA0: .4byte 0x03003964 @ IWRAM+0x3964
.L08145AA4:
	strh r6, [r5, #0x1c]
.L08145AA6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08145AAC
sub_08145AAC: @ 0x08145AAC
	push {r4, r5, r6, lr}
	ldr r1, .L08145AE0
	adds r6, r0, #0
	adds r6, #0x24
	movs r5, #0
	adds r4, r1, #0
	adds r4, #0x4c
.L08145ABA:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_08145290
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #2]
	cmp r0, r1
	bne .L08145AEC
	ldr r0, .L08145AE4
	ldr r0, [r0]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L08145AE8
	strh r1, [r4]
	b .L08145AEC
	.byte 0x00, 0x00
.L08145AE0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145AE4: .4byte 0x030031BC @ IWRAM+0x31BC
.L08145AE8:
	movs r0, #0
	strh r0, [r4]
.L08145AEC:
	adds r4, #2
	adds r5, #1
	cmp r5, #8
	bls .L08145ABA
	ldr r0, .L08145B14
	ldr r0, [r0]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L08145B18
	ldrh r0, [r6, #2]
	adds r0, #9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	b .L08145B2A
.L08145B14: .4byte 0x030031BC @ IWRAM+0x31BC
.L08145B18:
	ldrh r0, [r6, #2]
	adds r0, #9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
.L08145B2A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_08145B30
sub_08145B30: @ 0x08145B30
	push {lr}
	ldr r1, .L08145B5C
	adds r0, #0x24
	movs r2, #0
	movs r3, #0
	adds r1, #0x4c
.L08145B3C:
	strh r3, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #8
	bls .L08145B3C
	ldrh r0, [r0, #2]
	adds r0, #9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08144868
	pop {r0}
	bx r0
.L08145B5C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08145B60
sub_08145B60: @ 0x08145B60
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r6, #0
	strh r6, [r5, #0x1c]
	movs r4, #0
.L08145B6C:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_08145290
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r7
	bne .L08145B7E
	adds r6, #1
.L08145B7E:
	adds r4, #1
	cmp r4, #8
	bls .L08145B6C
	cmp r7, #4
	bhi .L08145BBA
	lsls r0, r7, #2
	ldr r1, .L08145B94
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L08145B94: .4byte gUnknown_08145B98
	.global gUnknown_08145B98
gUnknown_08145B98:
.L08145B98: @ jump table
	.4byte .L08145BAC
	.4byte .L08145BB2
	.4byte .L08145BB2
	.4byte .L08145BAC
	.4byte .L08145BAC
.L08145BAC:
	cmp r6, #4
	bls .L08145BBA
	b .L08145BB6
.L08145BB2:
	cmp r6, #3
	bls .L08145BBA
.L08145BB6:
	movs r0, #1
	strh r0, [r5, #0x1c]
.L08145BBA:
	ldrh r0, [r5, #0x1c]
	cmp r0, #1
	bne .L08145BCC
	ldr r0, .L08145BD4
	ldrh r1, [r5, #2]
	bl Task_Create
	strh r7, [r0, #0x26]
	strh r6, [r0, #0x24]
.L08145BCC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08145BD4: .4byte gUnknown_0879B884

	thumb_func_start sub_08145BD8
sub_08145BD8: @ 0x08145BD8
	movs r1, #0xc8
	str r1, [r0, #0x2c]
	bx lr
	.byte 0x00, 0x00

	thumb_func_start sub_08145BE0
sub_08145BE0: @ 0x08145BE0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r7, .L08145C1C
	adds r4, r5, #0
	adds r4, #0x24
	movs r3, #1
	ldr r0, .L08145C20
	ldrh r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L08145C02
	ldr r0, [r4, #8]
	bl sub_081493D4
	adds r3, r0, #0
.L08145C02:
	ldr r0, [r4, #8]
	subs r0, r0, r3
	str r0, [r4, #8]
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r1, [r2]
	adds r1, r1, r3
	str r1, [r2]
	cmp r0, #0
	beq .L08145C24
	movs r0, #0
	strh r0, [r5, #0x1c]
	b .L08145C26
.L08145C1C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145C20: .4byte 0x03003964 @ IWRAM+0x3964
.L08145C24:
	strh r6, [r5, #0x1c]
.L08145C26:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08145C2C
sub_08145C2C: @ 0x08145C2C
	push {r4, r5, r6, lr}
	ldr r1, .L08145C60
	adds r6, r0, #0
	adds r6, #0x24
	movs r5, #0
	adds r4, r1, #0
	adds r4, #0x4c
.L08145C3A:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_08145290
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #2]
	cmp r0, r1
	bne .L08145C6C
	ldr r0, .L08145C64
	ldr r0, [r0]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne .L08145C68
	strh r1, [r4]
	b .L08145C6C
	.byte 0x00, 0x00
.L08145C60: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145C64: .4byte 0x030031BC @ IWRAM+0x31BC
.L08145C68:
	movs r0, #0
	strh r0, [r4]
.L08145C6C:
	adds r4, #2
	adds r5, #1
	cmp r5, #8
	bls .L08145C3A
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08145C7C
sub_08145C7C: @ 0x08145C7C
	push {lr}
	ldr r0, .L08145C94
	movs r1, #0
	movs r2, #0
	adds r0, #0x4c
.L08145C86:
	strh r2, [r0]
	adds r0, #2
	adds r1, #1
	cmp r1, #8
	bls .L08145C86
	pop {r0}
	bx r0
.L08145C94: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08145C98
sub_08145C98: @ 0x08145C98
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_081454CC
	adds r5, r0, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	cmp r5, #9
	bne .L08145CBC
	ldr r0, .L08145CC4
	ldrh r1, [r4, #2]
	bl Task_Create
	movs r1, #6
	strh r1, [r0, #0x26]
	strh r5, [r0, #0x24]
	movs r0, #1
	strh r0, [r4, #0x1c]
.L08145CBC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08145CC4: .4byte gUnknown_0879B8D4

	thumb_func_start sub_08145CC8
sub_08145CC8: @ 0x08145CC8
.L08145CC8:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	ldr r4, .L08145D5C
	subs r0, #1
	mov sb, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_08145290
	adds r7, r4, #0
	adds r7, #0xac
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L08145D60
	str r0, [r1]
	str r0, [r7]
	ldr r2, [sp, #4]
	subs r2, #1
	mov r8, r2
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	bl sub_08145290
	adds r6, r4, #0
	adds r6, #0xb0
	movs r3, #0xbc
	adds r3, r3, r4
	mov sl, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r3]
	str r0, [r6]
	ldr r5, [sp, #8]
	subs r5, #1
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl sub_08145290
	adds r1, r4, #0
	adds r1, #0xb4
	movs r2, #0xc0
	adds r2, r2, r4
	mov ip, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov r3, ip
	str r2, [r3]
	str r2, [r1]
	ldr r3, [r7]
	cmp r3, #6
	beq .L08145E30
	ldr r1, [r6]
	cmp r1, #6
	beq .L08145E30
	cmp r2, #6
	beq .L08145E30
	cmp r3, #5
	beq .L08145D64
	cmp r1, #5
	beq .L08145D52
	cmp r2, #5
	bne .L08145DFA
.L08145D52:
	adds r0, r4, #0
	adds r0, #0xc4
	str r3, [r0]
	b .L08145D7A
	.byte 0x00, 0x00
.L08145D5C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145D60: .4byte 0x0203A50C @ EWRAM+0x3A50C
.L08145D64:
	cmp r1, #5
	beq .L08145D70
	adds r0, r4, #0
	adds r0, #0xc4
	str r1, [r0]
	b .L08145D7A
.L08145D70:
	cmp r2, #5
	beq .L08145D7A
	adds r0, r4, #0
	adds r0, #0xc4
	str r2, [r0]
.L08145D7A:
	adds r3, r4, #0
	adds r3, #0xac
	ldr r0, [r3]
	cmp r0, #5
	bne .L08145D8C
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	str r0, [r3]
.L08145D8C:
	adds r2, r4, #0
	adds r2, #0xb0
	ldr r0, [r2]
	cmp r0, #5
	bne .L08145D9E
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	str r0, [r2]
.L08145D9E:
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r1]
	cmp r0, #5
	bne .L08145DB0
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	str r0, [r1]
.L08145DB0:
	ldr r3, [r3]
	ldr r0, [r2]
	cmp r3, r0
	bne .L08145E30
	ldr r0, [r1]
	cmp r3, r0
	bne .L08145E30
	ldr r0, [sp]
	subs r0, #1
	lsls r0, r0, #2
	adds r2, r4, #0
	adds r2, #0xc8
	adds r0, r2, r0
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r1, [r1]
	str r1, [r0]
	ldr r0, [sp, #4]
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r2, r0
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r1, [r1]
	str r1, [r0]
	ldr r0, [sp, #8]
	subs r0, #1
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	str r0, [r2]
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	b .L08145E34
.L08145DFA:
	cmp r3, r1
	bne .L08145E30
	cmp r1, r2
	bne .L08145E30
	mov r1, sb
	lsls r0, r1, #2
	adds r2, r4, #0
	adds r2, #0xc8
	adds r0, r0, r2
	ldr r3, .L08145E2C
	ldr r1, [r3]
	str r1, [r0]
	mov r1, r8
	lsls r0, r1, #2
	adds r0, r0, r2
	mov r3, sl
	ldr r1, [r3]
	str r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r2
	mov r2, ip
	ldr r1, [r2]
	str r1, [r0]
	ldr r0, [r7]
	b .L08145E34
.L08145E2C: .4byte 0x0203A50C @ EWRAM+0x3A50C
.L08145E30:
	movs r0, #1
	rsbs r0, r0, #0
.L08145E34:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_08145E44
sub_08145E44: @ 0x08145E44
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r5, .L08145F1C
	movs r4, #0
	str r4, [sp]
	ldr r2, .L08145F20
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	ldr r1, .L08145F24
	ldr r2, .L08145F28
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L08145F2C
	strh r4, [r0]
	ldr r0, .L08145F30
	strh r4, [r0]
	movs r0, #1
	strh r0, [r5]
	bl sub_080C31F0
	movs r1, #0x64
	muls r0, r1, r0
	str r0, [r5, #8]
	str r0, [r5, #0xc]
	movs r0, #0x1e
	strb r0, [r5, #0x1c]
	movs r0, #0xaa
	lsls r0, r0, #1
	strh r0, [r5, #0x3c]
	movs r0, #0x40
	strh r0, [r5, #0x3e]
	adds r1, r5, #0
	adds r1, #0x40
	movs r0, #0x50
	strh r0, [r1]
	ldr r3, .L08145F34
	adds r0, r5, r3
	movs r2, #0x3a
	strh r2, [r0]
	movs r7, #0x94
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r0, #0x25
	strh r0, [r1]
	ldr r1, .L08145F38
	adds r0, r5, r1
	strh r2, [r0]
	adds r3, #0xa
	adds r0, r5, r3
	movs r1, #0x4b
	strh r1, [r0]
	adds r7, #0xe
	adds r0, r5, r7
	strh r2, [r0]
	movs r2, #0x98
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r6, .L08145F3C
.L08145EBE:
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r5, r1
	ldr r3, .L08145F40
	adds r2, r1, r3
	movs r0, #0xfc
	strh r0, [r2]
	lsls r2, r4, #3
	adds r2, r2, r6
	ldrh r3, [r2]
	movs r7, #0x9a
	lsls r7, r7, #2
	adds r0, r1, r7
	strh r3, [r0]
	ldrh r3, [r2, #4]
	adds r7, #2
	adds r0, r1, r7
	strh r3, [r0]
	ldrh r0, [r2, #2]
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r0, [r1]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #5
	bls .L08145EBE
	movs r4, #0
	movs r2, #0
.L08145EFC:
	lsls r0, r4, #3
	adds r0, r5, r0
	adds r1, r0, #0
	adds r1, #0x48
	strb r2, [r1]
	adds r0, #0x4c
	strh r2, [r0]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x3f
	bls .L08145EFC
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08145F1C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08145F20: .4byte 0x05000200 @ PLTT+0x200
.L08145F24: .4byte 0x04000008 @ REG_BG0CNT
.L08145F28: .4byte 0x00004008
.L08145F2C: .4byte 0x03000002 @ IWRAM+0x2
.L08145F30: .4byte 0x03000040 @ IWRAM+0x40
.L08145F34: .4byte 0x0000024E
.L08145F38: .4byte 0x00000256
.L08145F3C: .4byte gUnknown_0879C8EC
.L08145F40: .4byte 0x00000266

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
	bl sub_08146FC8
	ldr r0, [r6, #0x10]
	movs r1, #0xd3
	movs r2, #0x20
	movs r3, #0
	bl sub_08147128
	ldr r0, [r6, #0x14]
	movs r1, #0xd3
	movs r2, #0x39
	movs r3, #0
	bl sub_08147128
	ldr r0, [r6, #0x18]
	movs r1, #0xd3
	movs r2, #0x52
	movs r3, #0
	bl sub_08147128
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
	bl sub_081483B4
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
	bl sub_080C51D4
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
	bl sub_080C51D4
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
	bl sub_080C51D4
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
	bl sub_080C51D4
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
	bl sub_080C51D4
	movs r0, #0x18
.L081461CC:
	strb r0, [r6, #4]
	ldrb r0, [r6, #0x1c]
	movs r1, #1
.L081461D2:
	movs r2, #0
	bl sub_08147240
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
	bl sub_080C51D4
	ldrb r0, [r6, #0x1c]
	movs r1, #0xa
	movs r2, #0
	bl sub_08147240
.L0814626A:
	ldr r0, .L0814628C
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L081462E8
	movs r0, #0xb0
	lsls r0, r0, #1
	bl sub_080C51D4
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
	bl sub_080C51D4
	ldrb r0, [r6, #0x1c]
	movs r1, #1
	movs r2, #0
	bl sub_08147240
.L081462B4:
	ldr r0, .L081462FC
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L081462E8
	movs r0, #0xb0
	lsls r0, r0, #1
	bl sub_080C51D4
	ldrb r0, [r6, #0x1c]
	movs r1, #1
.L081462CC:
	movs r2, #1
	bl sub_08147240
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
	bl sub_080C51D4
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
	bl sub_080C51D4
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
	bl sub_080C51D4
	bl .L08146ED0
.L0814663C: .4byte 0x0000026E
.L08146640: .4byte 0x00000266
.L08146644:
	bl sub_0814789C
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
	bl sub_080C51D4
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
	bl sub_08148030
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
	bl sub_080C51D4
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
	bl sub_08147A90
	b .L08146EEC
.L08146D36:
	bl sub_081471CC
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

	thumb_func_start sub_08146EFC
sub_08146EFC: @ 0x08146EFC
.L08146EFC:
	push {r4, lr}
	sub sp, #0xc
	ldr r0, .L08146F3C
	adds r4, r0, #0
	adds r4, #0x25
	ldrb r0, [r4]
	cmp r0, #0xc
	bls .L08146F24
	ldr r0, .L08146F40
	movs r1, #0
	str r1, [sp]
	movs r1, #0x68
	str r1, [sp, #4]
	movs r1, #0x3a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08146F24:
	ldrb r0, [r4]
	cmp r0, #0x18
	bls .L08146F2E
	movs r0, #0
	strb r0, [r4]
.L08146F2E:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
.L08146F3C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08146F40: .4byte gUnknown_081501DC

	thumb_func_start sub_08146F44
sub_08146F44: @ 0x08146F44
.L08146F44:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r5, .L08146F58
	adds r6, r5, #0
	adds r6, #0x26
	ldrb r1, [r6]
	cmp r1, #0xc
	bhi .L08146F60
	ldr r0, .L08146F5C
	b .L08146F6E
.L08146F58: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08146F5C: .4byte gUnknown_081501AC
.L08146F60:
	adds r0, r1, #0
	subs r0, #0xd
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bhi .L08146F8C
	ldr r0, .L08146F88
.L08146F6E:
	movs r1, #0
	str r1, [sp]
	movs r1, #0xdd
	str r1, [sp, #4]
	ldrb r1, [r5, #0x1c]
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L08146FB2
	.byte 0x00, 0x00
.L08146F88: .4byte gUnknown_08150454
.L08146F8C:
	adds r0, r1, #0
	subs r0, #0x19
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi .L08146FB2
	ldr r0, .L08146FC4
	movs r4, #0
	str r4, [sp]
	movs r1, #0xdd
	str r1, [sp, #4]
	ldrb r1, [r5, #0x1c]
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	strb r4, [r6]
.L08146FB2:
	adds r1, r5, #0
	adds r1, #0x26
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08146FC4: .4byte gUnknown_08150464

	thumb_func_start sub_08146FC8
sub_08146FC8: @ 0x08146FC8
.L08146FC8:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r2, #0
	adds r5, r3, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	bl NumberToDigits
	mov sb, r0
	ldr r0, .L08147124
	mov r8, r0
	mov r1, sb
	ldrb r0, [r1]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	movs r6, #0
	str r6, [sp]
	adds r1, r7, #0
	adds r1, #0x16
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0xff
	ands r4, r1
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, sb
	ldrb r0, [r1, #1]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	adds r1, #0xe
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldr r0, [r1, #0x28]
	str r6, [sp]
	adds r1, r7, #0
	adds r1, #0xa
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, sb
	ldrb r0, [r1, #2]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r6, [sp]
	str r7, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, sb
	ldrb r0, [r1, #3]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, sb
	ldrb r0, [r1, #4]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, sb
	ldrb r0, [r1, #5]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, sb
	ldrb r0, [r1, #6]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x20
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, sb
	ldrb r0, [r1, #7]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08147124: .4byte gUnknown_0879C7F4

	thumb_func_start sub_08147128
sub_08147128: @ 0x08147128
.L08147128:
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0xc
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	bl NumberToDigits
	mov sb, r0
	ldr r0, .L081471C8
	mov sl, r0
	mov r1, sb
	ldrb r0, [r1]
	lsls r0, r0, #2
	add r0, sl
	ldr r0, [r0]
	movs r1, #0
	mov r8, r1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0xff
	ands r5, r1
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl Sprite_Draw
	mov r1, sb
	ldrb r0, [r1, #1]
	lsls r0, r0, #2
	add r0, sl
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r4, #0
	subs r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl Sprite_Draw
	mov r1, sb
	ldrb r0, [r1, #2]
	lsls r0, r0, #2
	add r0, sl
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	subs r4, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r6, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L081471C8: .4byte gUnknown_0879C7F4

	thumb_func_start sub_081471CC
sub_081471CC: @ 0x081471CC
.L081471CC:
	push {r4, lr}
	ldr r4, .L081471FC
	ldr r0, .L08147200
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L08147238
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #8]
	adds r2, r0, #0
	cmp r0, r1
	beq .L08147232
	ldr r0, .L08147204
	cmp r1, r0
	bls .L08147210
	ldr r0, .L08147208
	bl sub_080C51D4
	ldr r0, .L0814720C
	str r0, [r4, #8]
	movs r0, #0x63
	b .L08147236
	.byte 0x00, 0x00
.L081471FC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08147200: .4byte 0x030031BC @ IWRAM+0x31BC
.L08147204: .4byte 0x05F5E09B
.L08147208: .4byte 0x00000159
.L0814720C: .4byte 0x05F5E09C
.L08147210:
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08147220
	adds r0, r1, #0
	adds r0, #0x37
	b .L08147226
.L08147220:
	movs r3, #0xfa
	lsls r3, r3, #1
	adds r0, r1, r3
.L08147226:
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	cmp r2, r0
	bhi .L08147238
	str r2, [r4, #8]
	b .L08147238
.L08147232:
	str r0, [r4, #0xc]
	movs r0, #2
.L08147236:
	strb r0, [r4, #4]
.L08147238:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08147240
sub_08147240: @ 0x08147240
.L08147240:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r4, .L08147260
	cmp r0, #0x37
	beq .L081472EE
	cmp r0, #0x37
	bgt .L08147264
	cmp r0, #0x1e
	beq .L0814726A
	b .L081473D4
.L08147260: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08147264:
	cmp r3, #0x50
	beq .L08147354
	b .L081473D4
.L0814726A:
	cmp r2, #0
	bne .L081472A6
	ldr r3, [r4, #0x10]
	cmp r3, #0x63
	bhi .L081472A6
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne .L081472A6
	cmp r3, #0x59
	bls .L08147294
	cmp r1, #0xa
	bne .L08147294
	movs r1, #0x64
	subs r0, r1, r3
	adds r2, r0, #0
	muls r2, r1, r2
	ldr r0, [r4, #8]
	subs r0, r0, r2
	str r0, [r4, #8]
	str r1, [r4, #0x10]
	b .L081472A2
.L08147294:
	adds r0, r3, r1
	str r0, [r4, #0x10]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, [r4, #8]
	subs r0, r0, r1
	str r0, [r4, #8]
.L081472A2:
	movs r0, #1
	b .L081472EA
.L081472A6:
	cmp r2, #1
	beq .L081472AC
	b .L081473D0
.L081472AC:
	ldr r2, [r4, #0x10]
	cmp r2, #0
	bne .L081472B4
	b .L081473D0
.L081472B4:
	ldrb r3, [r4, #0x1f]
	cmp r3, #0
	beq .L081472BC
	b .L081473D0
.L081472BC:
	cmp r2, #0xa
	bhi .L081472D4
	cmp r1, #0xa
	bne .L081472D4
	movs r0, #0x64
	adds r1, r2, #0
	muls r1, r0, r1
	ldr r0, [r4, #8]
	adds r0, r0, r1
	str r0, [r4, #8]
	str r3, [r4, #0x10]
	b .L081472E4
.L081472D4:
	ldr r0, [r4, #0x10]
	subs r0, r0, r1
	str r0, [r4, #0x10]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, [r4, #8]
	adds r0, r0, r1
	str r0, [r4, #8]
.L081472E4:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne .L081473D0
.L081472EA:
	strb r0, [r4, #0x1e]
	b .L081473D0
.L081472EE:
	cmp r2, #0
	bne .L08147320
	ldr r3, [r4, #0x14]
	cmp r3, #0x63
	bhi .L08147320
	cmp r3, #0x59
	bls .L08147312
	cmp r1, #0xa
	bne .L08147312
	movs r1, #0x64
	subs r0, r1, r3
	adds r2, r0, #0
	muls r2, r1, r2
	ldr r0, [r4, #8]
	subs r0, r0, r2
	str r0, [r4, #8]
	str r1, [r4, #0x14]
	b .L081473D0
.L08147312:
	adds r0, r3, r1
	str r0, [r4, #0x14]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, [r4, #8]
	subs r0, r0, r1
	b .L08147350
.L08147320:
	cmp r2, #1
	bne .L081473D0
	ldr r3, [r4, #0x14]
	cmp r3, #0
	beq .L081473D0
	cmp r3, #0xa
	bhi .L08147344
	cmp r1, #0xa
	bne .L08147344
	movs r0, #0x64
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r0, [r4, #8]
	adds r0, r0, r1
	str r0, [r4, #8]
	movs r0, #0
	str r0, [r4, #0x14]
	b .L081473D0
.L08147344:
	subs r0, r3, r1
	str r0, [r4, #0x14]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, [r4, #8]
	adds r0, r0, r1
.L08147350:
	str r0, [r4, #8]
	b .L081473D0
.L08147354:
	cmp r2, #0
	bne .L08147390
	ldr r3, [r4, #0x18]
	cmp r3, #0x63
	bhi .L08147390
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	bne .L08147390
	cmp r3, #0x59
	bls .L0814737E
	cmp r1, #0xa
	bne .L0814737E
	movs r1, #0x64
	subs r0, r1, r3
	adds r2, r0, #0
	muls r2, r1, r2
	ldr r0, [r4, #8]
	subs r0, r0, r2
	str r0, [r4, #8]
	str r1, [r4, #0x18]
	b .L0814738C
.L0814737E:
	adds r0, r3, r1
	str r0, [r4, #0x18]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, [r4, #8]
	subs r0, r0, r1
	str r0, [r4, #8]
.L0814738C:
	movs r0, #1
	b .L081473CE
.L08147390:
	cmp r2, #1
	bne .L081473D0
	ldr r2, [r4, #0x18]
	cmp r2, #0
	beq .L081473D0
	ldrb r3, [r4, #0x1e]
	cmp r3, #0
	bne .L081473D0
	cmp r2, #0xa
	bhi .L081473B8
	cmp r1, #0xa
	bne .L081473B8
	movs r0, #0x64
	adds r1, r2, #0
	muls r1, r0, r1
	ldr r0, [r4, #8]
	adds r0, r0, r1
	str r0, [r4, #8]
	str r3, [r4, #0x18]
	b .L081473C8
.L081473B8:
	ldr r0, [r4, #0x18]
	subs r0, r0, r1
	str r0, [r4, #0x18]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, [r4, #8]
	adds r0, r0, r1
	str r0, [r4, #8]
.L081473C8:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	bne .L081473D0
.L081473CE:
	strb r0, [r4, #0x1f]
.L081473D0:
	ldr r0, [r4, #8]
	str r0, [r4, #0xc]
.L081473D4:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081473DC
sub_081473DC: @ 0x081473DC
.L081473DC:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, .L08147408
	adds r5, r4, #0
	adds r5, #0x32
	movs r2, #0
	strb r2, [r5]
	movs r0, #0x31
	adds r0, r0, r4
	mov ip, r0
	ldrb r1, [r0]
	adds r3, r1, #0
	cmp r3, #3
	bhi .L08147410
	ldr r0, .L0814740C
	str r2, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	b .L0814743E
.L08147408: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814740C: .4byte gUnknown_08150414
.L08147410:
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi .L08147424
	ldr r0, .L08147420
	b .L08147430
	.byte 0x00, 0x00
.L08147420: .4byte gUnknown_0815042C
.L08147424:
	subs r0, r1, #7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi .L0814744C
	ldr r0, .L08147448
.L08147430:
	str r2, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
.L0814743E:
	movs r3, #0
	bl Sprite_Draw
	b .L08147458
	.byte 0x00, 0x00
.L08147448: .4byte gUnknown_08150444
.L0814744C:
	cmp r3, #9
	bls .L08147458
	mov r0, ip
	strb r2, [r0]
	strb r2, [r5]
	strb r2, [r4, #4]
.L08147458:
	adds r1, r4, #0
	adds r1, #0x31
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814746C
sub_0814746C: @ 0x0814746C
.L0814746C:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r5, .L08147484
	adds r6, r5, #0
	adds r6, #0x31
	ldrb r1, [r6]
	adds r2, r1, #0
	cmp r2, #3
	bhi .L0814748C
	ldr r0, .L08147488
	b .L081474AC
	.byte 0x00, 0x00
.L08147484: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08147488: .4byte gUnknown_08150444
.L0814748C:
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi .L081474A0
	ldr r0, .L0814749C
	b .L081474AC
	.byte 0x00, 0x00
.L0814749C: .4byte gUnknown_0815042C
.L081474A0:
	subs r0, r1, #7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi .L081474C8
	ldr r0, .L081474C4
.L081474AC:
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
	b .L081474F2
.L081474C4: .4byte gUnknown_08150414
.L081474C8:
	cmp r2, #9
	bls .L081474F2
	ldr r0, .L08147504
	movs r4, #0
	str r4, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	strb r4, [r6]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	movs r0, #3
	strb r0, [r5, #4]
.L081474F2:
	adds r1, r5, #0
	adds r1, #0x31
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08147504: .4byte gUnknown_081503FC

	thumb_func_start sub_08147508
sub_08147508: @ 0x08147508
.L08147508:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	ldr r0, .L081475F4
	mov sb, r0
	movs r5, #0
	movs r7, #0
	movs r1, #0xff
	mov r8, r1
.L0814751E:
	lsls r1, r5, #1
	adds r0, r1, r5
	lsls r0, r0, #2
	mov r2, sb
	adds r4, r2, r0
	ldr r3, .L081475F8
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r6, r1, #0
	cmp r0, #1
	bne .L08147558
	str r7, [sp]
	ldr r1, .L081475FC
	adds r0, r4, r1
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, .L08147600
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08147558:
	ldr r3, .L08147604
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #1
	bne .L081475DC
	movs r1, #0x99
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq .L08147572
	cmp r0, #3
	bne .L0814759C
.L08147572:
	ldr r1, .L08147608
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r7, [sp]
	ldr r2, .L081475FC
	adds r1, r4, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r2, [r1]
	mov r1, r8
	ands r1, r2
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814759C:
	adds r0, r6, r5
	lsls r0, r0, #2
	mov r1, sb
	adds r2, r1, r0
	movs r3, #0x99
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq .L081475B4
	cmp r0, #2
	bne .L081475DC
.L081475B4:
	ldr r1, .L08147608
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r7, [sp]
	ldr r3, .L081475FC
	adds r1, r2, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r3, #6
	adds r1, r2, r3
	ldrh r2, [r1]
	mov r1, r8
	ands r1, r2
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl Sprite_Draw
.L081475DC:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #5
	bls .L0814751E
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L081475F4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081475F8: .4byte 0x0000026E
.L081475FC: .4byte 0x00000266
.L08147600: .4byte gUnknown_08150348
.L08147604: .4byte 0x0000026F
.L08147608: .4byte gUnknown_0879C8D4

	thumb_func_start sub_0814760C
sub_0814760C: @ 0x0814760C
.L0814760C:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r6, .L08147660
	adds r5, r6, #0
	adds r5, #0x35
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r1, .L08147664
	adds r0, r0, r1
	movs r4, #0
	strb r4, [r0]
	adds r7, r6, #0
	adds r7, #0x36
	ldrb r1, [r7]
	adds r2, r1, #0
	cmp r2, #6
	bhi .L08147670
	ldr r0, .L08147668
	str r4, [sp]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r2, .L0814766C
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrb r1, [r1]
	b .L081477CC
	.byte 0x00, 0x00
.L08147660: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08147664: .4byte 0x0000026E
.L08147668: .4byte gUnknown_08150348
.L0814766C: .4byte 0x00000266
.L08147670:
	subs r0, r1, #7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bhi .L081476B4
	ldr r0, .L081476AC
	str r4, [sp]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r2, .L081476B0
	adds r1, r1, r2
	ldrh r1, [r1]
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	subs r1, #2
	b .L081477C8
.L081476AC: .4byte gUnknown_08150384
.L081476B0: .4byte 0x00000266
.L081476B4:
	adds r0, r1, #0
	subs r0, #0xd
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bhi .L081476FC
	ldr r0, .L081476F4
	str r4, [sp]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r2, .L081476F8
	adds r1, r1, r2
	ldrh r1, [r1]
	adds r1, #0xf
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	subs r1, #3
	b .L081477C8
	.byte 0x00, 0x00
.L081476F4: .4byte gUnknown_0815039C
.L081476F8: .4byte 0x00000266
.L081476FC:
	adds r0, r1, #0
	subs r0, #0x13
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bhi .L08147744
	ldr r0, .L0814773C
	str r4, [sp]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r2, .L08147740
	adds r1, r1, r2
	ldrh r1, [r1]
	adds r1, #0x15
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	subs r1, #9
	b .L081477C8
	.byte 0x00, 0x00
.L0814773C: .4byte gUnknown_081503B4
.L08147740: .4byte 0x00000266
.L08147744:
	adds r0, r1, #0
	subs r0, #0x19
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bhi .L0814778C
	ldr r0, .L08147784
	str r4, [sp]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r2, .L08147788
	adds r1, r1, r2
	ldrh r1, [r1]
	adds r1, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	subs r1, #9
	b .L081477C8
	.byte 0x00, 0x00
.L08147784: .4byte gUnknown_081503CC
.L08147788: .4byte 0x00000266
.L0814778C:
	adds r0, r1, #0
	subs r0, #0x1f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bhi .L081477E4
	ldr r0, .L081477DC
	str r4, [sp]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r2, .L081477E0
	adds r1, r1, r2
	ldrh r1, [r1]
	adds r1, #0xf
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	subs r1, #4
.L081477C8:
	movs r2, #0xff
	ands r1, r2
.L081477CC:
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814780A
	.byte 0x00, 0x00
.L081477DC: .4byte gUnknown_081503E4
.L081477E0: .4byte 0x00000266
.L081477E4:
	cmp r2, #0x24
	bls .L0814780A
	movs r0, #0xbe
	lsls r0, r0, #1
	bl sub_080C51D4
	strb r4, [r7]
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r1, .L0814781C
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
.L0814780A:
	adds r1, r6, #0
	adds r1, #0x36
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814781C: .4byte 0x0000026F

	thumb_func_start sub_08147820
sub_08147820: @ 0x08147820
.L08147820:
	push {r4, lr}
	sub sp, #0xc
	ldr r3, .L08147890
	adds r4, r3, #0
	adds r4, #0x24
	ldrb r0, [r4]
	cmp r0, #0xc
	bls .L08147876
	ldr r0, .L08147894
	movs r1, #0
	str r1, [sp]
	movs r1, #0x35
	adds r1, r1, r3
	mov ip, r1
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r2, .L08147898
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	mov r1, ip
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrb r1, [r1]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r0, #0xbf
	lsls r0, r0, #1
	bl sub_080C51D4
.L08147876:
	ldrb r0, [r4]
	cmp r0, #0x18
	bls .L08147880
	movs r0, #0
	strb r0, [r4]
.L08147880:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08147890: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08147894: .4byte gUnknown_08150360
.L08147898: .4byte 0x00000266

	thumb_func_start sub_0814789C
sub_0814789C: @ 0x0814789C
.L0814789C:
	push {r4, r5, r6, lr}
	ldr r6, .L08147968
	adds r5, r6, #0
	adds r5, #0x2e
	movs r0, #0
	strb r0, [r5]
	bl Random_Byte
	movs r4, #0xff
	ands r0, r4
	strh r0, [r6, #0x28]
	ldrh r0, [r6, #0x28]
	movs r1, #0x55
	bl __divsi3
	strh r0, [r6, #0x28]
	bl Random_Byte
	ands r0, r4
	strh r0, [r6, #0x2a]
	ldrh r1, [r6, #0x2a]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0xff
	bl __divsi3
	strh r0, [r6, #0x2a]
	movs r2, #0
.L081478D6:
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0x99
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	adds r3, r6, #0
	adds r3, #0x2e
	ldrh r4, [r6, #0x28]
	cmp r0, r4
	bne .L08147900
	ldr r4, .L0814796C
	adds r0, r1, r4
	ldrb r0, [r0]
	ldrh r1, [r6, #0x2a]
	cmp r0, r1
	bne .L08147900
	movs r0, #1
	strb r0, [r5]
.L08147900:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #5
	bls .L081478D6
	ldrb r0, [r3]
	cmp r0, #0
	bne .L08147952
	ldrh r1, [r6, #0x2c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r6, r0
	ldrh r1, [r6, #0x28]
	movs r3, #0x99
	lsls r3, r3, #2
	adds r0, r0, r3
	strb r1, [r0]
	ldrh r1, [r6, #0x2c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r6, r0
	ldrh r1, [r6, #0x2a]
	ldr r4, .L0814796C
	adds r0, r0, r4
	strb r1, [r0]
	ldrh r0, [r6, #0x2c]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r6, r2
	adds r3, r2, r3
	ldrb r1, [r3]
	adds r2, r2, r4
	ldrb r2, [r2]
	bl sub_08148510
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
.L08147952:
	ldrh r0, [r6, #0x2c]
	cmp r0, #6
	bne .L08147960
	movs r0, #0
	strh r0, [r6, #0x2c]
	movs r0, #7
	strb r0, [r6, #4]
.L08147960:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08147968: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814796C: .4byte 0x00000265

	thumb_func_start sub_08147970
sub_08147970: @ 0x08147970
.L08147970:
	push {r4, lr}
	sub sp, #0xc
	ldr r4, .L0814798C
	ldr r1, .L08147990
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #4
	bhi .L081479FC
	lsls r0, r0, #2
	ldr r1, .L08147994
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L0814798C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08147990: .4byte 0x0000024D
.L08147994: .4byte gUnknown_08147998
	.global gUnknown_08147998
gUnknown_08147998:
.L08147998: @ jump table
	.4byte .L081479AC
	.4byte .L081479B4
	.4byte .L081479BC
	.4byte .L081479C4
	.4byte .L081479E4
.L081479AC:
	ldr r0, .L081479B0
	b .L081479C6
.L081479B0: .4byte gUnknown_08150284
.L081479B4:
	ldr r0, .L081479B8
	b .L081479C6
.L081479B8: .4byte gUnknown_0815029C
.L081479BC:
	ldr r0, .L081479C0
	b .L081479C6
.L081479C0: .4byte gUnknown_081502CC
.L081479C4:
	ldr r0, .L081479E0
.L081479C6:
	movs r1, #0
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0x24
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L081479FC
	.byte 0x00, 0x00
.L081479E0: .4byte gUnknown_081502B4
.L081479E4:
	ldr r0, .L08147A14
	movs r1, #0
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0x24
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L081479FC:
	ldr r1, .L08147A18
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #4
	bhi .L08147A84
	lsls r0, r0, #2
	ldr r1, .L08147A1C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.byte 0x00, 0x00
.L08147A14: .4byte gUnknown_081502FC
.L08147A18: .4byte 0x00000255
.L08147A1C: .4byte gUnknown_08147A20
	.global gUnknown_08147A20
gUnknown_08147A20:
.L08147A20: @ jump table
	.4byte .L08147A34
	.4byte .L08147A3C
	.4byte .L08147A44
	.4byte .L08147A4C
	.4byte .L08147A6C
.L08147A34:
	ldr r0, .L08147A38
	b .L08147A4E
.L08147A38: .4byte gUnknown_08150284
.L08147A3C:
	ldr r0, .L08147A40
	b .L08147A4E
.L08147A40: .4byte gUnknown_0815029C
.L08147A44:
	ldr r0, .L08147A48
	b .L08147A4E
.L08147A48: .4byte gUnknown_081502CC
.L08147A4C:
	ldr r0, .L08147A68
.L08147A4E:
	movs r1, #0
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0x4a
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L08147A84
	.byte 0x00, 0x00
.L08147A68: .4byte gUnknown_081502B4
.L08147A6C:
	ldr r0, .L08147A8C
	movs r1, #0
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0x4a
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08147A84:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
.L08147A8C: .4byte gUnknown_081502FC

	thumb_func_start sub_08147A90
sub_08147A90: @ 0x08147A90
.L08147A90:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r7, .L08147AD4
	ldrh r0, [r7, #0x3a]
	cmp r0, #0
	bne .L08147ADE
	ldrh r0, [r7, #0x3c]
	cmp r0, #0xa2
	bhi .L08147ADE
	adds r1, r7, #0
	adds r1, #0x39
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #1
	beq .L08147ACA
	cmp r0, #3
	bne .L08147AD8
	adds r0, r7, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08147AD8
.L08147ACA:
	movs r0, #0xaf
	lsls r0, r0, #1
	bl sub_080C51D4
	b .L08147ADE
.L08147AD4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08147AD8:
	ldr r0, .L08147B38
	bl sub_080C51D4
.L08147ADE:
	adds r0, r7, #0
	adds r0, #0x39
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #1
	bne .L08147AFE
	ldrh r0, [r7, #0x3a]
	adds r0, #1
	strh r0, [r7, #0x3a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x14
	bne .L08147AFE
	movs r0, #0
	mov r1, sl
	strb r0, [r1]
.L08147AFE:
	adds r0, r7, #0
	adds r0, #0x30
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #1
	beq .L08147B16
	cmp r1, #3
	bne .L08147B40
	subs r0, #0x10
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08147B40
.L08147B16:
	ldr r0, .L08147B3C
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r7, #0x3c]
	ldrh r2, [r7, #0x3e]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x3f
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L08147B64
.L08147B38: .4byte 0x00000163
.L08147B3C: .4byte gUnknown_08150314
.L08147B40:
	ldr r0, .L08147B9C
	movs r1, #0
	str r1, [sp]
	adds r2, r7, #0
	adds r2, #0x40
	ldrh r1, [r7, #0x3c]
	ldrh r2, [r2]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	movs r1, #0x3f
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08147B64:
	mov r2, sb
	ldrb r0, [r2]
	cmp r0, #1
	bne .L08147BE0
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0xc
	bls .L08147BCA
	ldr r6, .L08147BA0
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08147BA8
	ldr r0, .L08147BA4
	movs r1, #0
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0x24
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L08147BCA
.L08147B9C: .4byte gUnknown_08150330
.L08147BA0: .4byte 0x0000024D
.L08147BA4: .4byte gUnknown_081501F4
.L08147BA8:
	ldr r1, .L08147BD8
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08147BCA
	ldr r0, .L08147BDC
	movs r1, #0
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0x4a
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08147BCA:
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0x18
	bls .L08147C2A
	movs r0, #0
	strb r0, [r2]
	b .L08147C2A
.L08147BD8: .4byte 0x00000255
.L08147BDC: .4byte gUnknown_081501F4
.L08147BE0:
	movs r6, #0x42
	adds r6, r6, r7
	mov r8, r6
	cmp r0, #3
	bne .L08147C2A
	ldrb r0, [r6]
	cmp r0, #0xc
	bls .L08147C1E
	ldr r6, .L08147C60
	movs r5, #0
	str r5, [sp]
	movs r4, #4
	str r4, [sp, #4]
	movs r0, #0x24
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0x4a
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08147C1E:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0x18
	bls .L08147C2A
	movs r0, #0
	strb r0, [r1]
.L08147C2A:
	adds r5, r7, #0
	adds r5, #0x44
	ldrh r0, [r5]
	cmp r0, #0x3d
	bne .L08147C6E
	ldr r6, .L08147C64
	movs r2, #0x92
	lsls r2, r2, #2
	adds r4, r7, r2
	ldrh r1, [r4]
	strh r1, [r6]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	bne .L08147C68
	bl sub_0814837C
	ldrh r0, [r6]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r6]
	movs r0, #0
	strh r0, [r4]
	ldrh r0, [r5]
	subs r0, #4
	strh r0, [r5]
	b .L08147C9E
.L08147C60: .4byte gUnknown_0815023C
.L08147C64: .4byte 0x0300000C @ IWRAM+0xC
.L08147C68:
	adds r0, r1, #1
	strh r0, [r4]
	b .L08147C9E
.L08147C6E:
	movs r6, #0x93
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bne .L08147C8C
	bl sub_08147F68
	b .L08147C9E
.L08147C8C:
	cmp r2, r0
	ble .L08147C96
	bl sub_08147DB8
	b .L08147C9E
.L08147C96:
	cmp r2, r0
	bge .L08147C9E
	bl sub_08147E90
.L08147C9E:
	ldrh r3, [r7, #0x3c]
	cmp r3, #0
	bne .L08147D8E
	adds r5, r7, #0
	adds r5, #0x38
	ldrb r0, [r5]
	cmp r0, #1
	bne .L08147D8E
	movs r4, #0
	movs r0, #0xaa
	lsls r0, r0, #1
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3a]
	ldr r6, .L08147D0C
	adds r0, r7, r6
	movs r2, #0x3a
	strh r2, [r0]
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0x25
	strh r0, [r1]
	ldr r1, .L08147D10
	adds r0, r7, r1
	strh r2, [r0]
	adds r6, #0xa
	adds r0, r7, r6
	movs r1, #0x4b
	strh r1, [r0]
	adds r6, #6
	adds r0, r7, r6
	strh r2, [r0]
	movs r2, #0x98
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	strb r4, [r7, #0x1f]
	strb r4, [r7, #0x1e]
	strb r4, [r5]
	mov r6, sb
	ldrb r0, [r6]
	cmp r0, #1
	bne .L08147D36
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08147D14
	ldr r0, [r7, #0x10]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #6
	adds r1, r1, r0
	b .L08147D1E
	.byte 0x00, 0x00
.L08147D0C: .4byte 0x0000024E
.L08147D10: .4byte 0x00000256
.L08147D14:
	cmp r0, #1
	bne .L08147D24
	ldr r1, [r7, #0x18]
	movs r0, #0xc8
	muls r1, r0, r1
.L08147D1E:
	ldr r0, [r7, #0xc]
	adds r0, r0, r1
	str r0, [r7, #0xc]
.L08147D24:
	movs r0, #0
	str r0, [r7, #0x18]
	str r0, [r7, #0x14]
	str r0, [r7, #0x10]
	adds r1, r7, #0
	adds r1, #0x20
	strb r0, [r1]
	movs r0, #0x17
	b .L08147D8C
.L08147D36:
	cmp r0, #3
	bne .L08147D7A
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	adds r3, r7, #0
	adds r3, #0x20
	cmp r0, #2
	beq .L08147D4E
	ldrb r0, [r3]
	cmp r0, #1
	bne .L08147D6C
.L08147D4E:
	ldr r1, [r7, #0x14]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, [r7, #0xc]
	adds r2, r2, r0
	ldr r0, [r7, #0x10]
	ldr r1, [r7, #0x18]
	adds r0, r0, r1
	movs r1, #0x64
	muls r0, r1, r0
	adds r2, r2, r0
	str r2, [r7, #0xc]
.L08147D6C:
	movs r0, #0
	str r0, [r7, #0x18]
	str r0, [r7, #0x14]
	str r0, [r7, #0x10]
	strb r0, [r3]
	movs r0, #0x17
	b .L08147D8C
.L08147D7A:
	str r3, [r7, #0x18]
	str r3, [r7, #0x14]
	str r3, [r7, #0x10]
	ldr r0, [r7, #8]
	str r0, [r7, #0xc]
	adds r0, r7, #0
	adds r0, #0x20
	strb r4, [r0]
	movs r0, #2
.L08147D8C:
	strb r0, [r7, #4]
.L08147D8E:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne .L08147DA0
	ldrh r0, [r7, #0x3c]
	cmp r0, #0
	beq .L08147DA0
	subs r0, #4
	strh r0, [r7, #0x3c]
.L08147DA0:
	mov r2, r8
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08147DB8
sub_08147DB8: @ 0x08147DB8
.L08147DB8:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r7, .L08147E28
	ldr r1, .L08147E2C
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldr r3, .L08147E30
	adds r4, r7, r3
	ldrh r1, [r4]
	str r1, [sp, #4]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r5, r7, r1
	ldrb r1, [r5]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r6, .L08147E34
	adds r3, r7, #0
	adds r3, #0x44
	ldrh r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	adds r2, r0, r6
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldrh r0, [r4]
	cmp r1, r0
	beq .L08147E54
	cmp r1, r0
	bgt .L08147E38
	subs r0, #3
	strh r0, [r4]
	ldrh r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	adds r1, r0, r6
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldrh r3, [r4]
	cmp r0, r3
	blt .L08147E88
	b .L08147E4E
	.byte 0x00, 0x00
.L08147E28: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08147E2C: .4byte gUnknown_0879C820
.L08147E30: .4byte 0x0000024E
.L08147E34: .4byte gUnknown_0879C92C
.L08147E38:
	adds r0, #3
	strh r0, [r4]
	ldrh r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	adds r1, r0, r6
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldrh r3, [r4]
	cmp r0, r3
	bgt .L08147E88
.L08147E4E:
	ldrh r0, [r1]
	strh r0, [r4]
	b .L08147E88
.L08147E54:
	movs r1, #2
	ldrsh r0, [r2, r1]
	ldrh r1, [r5]
	cmp r0, r1
	blt .L08147E88
	adds r0, r1, #3
	strh r0, [r5]
	ldrh r0, [r3]
	subs r2, r0, #1
	lsls r0, r2, #2
	adds r1, r0, r6
	movs r3, #2
	ldrsh r0, [r1, r3]
	ldrh r3, [r5]
	cmp r0, r3
	bgt .L08147E88
	ldrh r0, [r1, #2]
	strh r0, [r5]
	lsls r0, r2, #3
	adds r0, r0, r7
	adds r0, #0x48
	movs r1, #1
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x38
	strb r1, [r0]
.L08147E88:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08147E90
sub_08147E90: @ 0x08147E90
.L08147E90:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r7, .L08147F00
	ldr r1, .L08147F04
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldr r3, .L08147F08
	adds r4, r7, r3
	ldrh r1, [r4]
	str r1, [sp, #4]
	movs r1, #0x96
	lsls r1, r1, #2
	adds r5, r7, r1
	ldrb r1, [r5]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r6, .L08147F0C
	adds r3, r7, #0
	adds r3, #0x44
	ldrh r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	adds r2, r0, r6
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldrh r0, [r4]
	cmp r1, r0
	beq .L08147F2C
	cmp r1, r0
	bgt .L08147F10
	subs r0, #3
	strh r0, [r4]
	ldrh r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	adds r1, r0, r6
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldrh r3, [r4]
	cmp r0, r3
	blt .L08147F60
	b .L08147F26
	.byte 0x00, 0x00
.L08147F00: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08147F04: .4byte gUnknown_0879C84C
.L08147F08: .4byte 0x00000256
.L08147F0C: .4byte gUnknown_0879C92C
.L08147F10:
	adds r0, #3
	strh r0, [r4]
	ldrh r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	adds r1, r0, r6
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldrh r3, [r4]
	cmp r0, r3
	bgt .L08147F60
.L08147F26:
	ldrh r0, [r1]
	strh r0, [r4]
	b .L08147F60
.L08147F2C:
	movs r1, #2
	ldrsh r0, [r2, r1]
	ldrh r1, [r5]
	cmp r0, r1
	blt .L08147F60
	adds r0, r1, #3
	strh r0, [r5]
	ldrh r0, [r3]
	subs r2, r0, #1
	lsls r0, r2, #2
	adds r1, r0, r6
	movs r3, #2
	ldrsh r0, [r1, r3]
	ldrh r3, [r5]
	cmp r0, r3
	bgt .L08147F60
	ldrh r0, [r1, #2]
	strh r0, [r5]
	lsls r0, r2, #3
	adds r0, r0, r7
	adds r0, #0x48
	movs r1, #1
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x38
	strb r1, [r0]
.L08147F60:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08147F68
sub_08147F68: @ 0x08147F68
.L08147F68:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r7, .L08147FC8
	ldr r0, .L08147FCC
	ldr r0, [r0, #0x58]
	movs r1, #0
	str r1, [sp]
	ldr r1, .L08147FD0
	adds r4, r7, r1
	ldrh r1, [r4]
	str r1, [sp, #4]
	movs r2, #0x98
	lsls r2, r2, #2
	adds r5, r7, r2
	ldrb r1, [r5]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r6, .L08147FD4
	adds r3, r7, #0
	adds r3, #0x44
	ldrh r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	adds r2, r0, r6
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldrh r0, [r4]
	cmp r1, r0
	beq .L08147FF4
	cmp r1, r0
	bgt .L08147FD8
	subs r0, #3
	strh r0, [r4]
	ldrh r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	adds r1, r0, r6
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldrh r3, [r4]
	cmp r0, r3
	blt .L08148028
	b .L08147FEE
	.byte 0x00, 0x00
.L08147FC8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08147FCC: .4byte gUnknown_0879C878
.L08147FD0: .4byte 0x0000025E
.L08147FD4: .4byte gUnknown_0879C92C
.L08147FD8:
	adds r0, #3
	strh r0, [r4]
	ldrh r0, [r3]
	subs r0, #1
	lsls r0, r0, #2
	adds r1, r0, r6
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldrh r3, [r4]
	cmp r0, r3
	bgt .L08148028
.L08147FEE:
	ldrh r0, [r1]
	strh r0, [r4]
	b .L08148028
.L08147FF4:
	movs r1, #2
	ldrsh r0, [r2, r1]
	ldrh r1, [r5]
	cmp r0, r1
	blt .L08148028
	adds r0, r1, #3
	strh r0, [r5]
	ldrh r0, [r3]
	subs r2, r0, #1
	lsls r0, r2, #2
	adds r1, r0, r6
	movs r3, #2
	ldrsh r0, [r1, r3]
	ldrh r3, [r5]
	cmp r0, r3
	bgt .L08148028
	ldrh r0, [r1, #2]
	strh r0, [r5]
	lsls r0, r2, #3
	adds r0, r0, r7
	adds r0, #0x48
	movs r1, #1
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x38
	strb r1, [r0]
.L08148028:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08148030
sub_08148030: @ 0x08148030
.L08148030:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r5, .L0814806C
	adds r6, r5, #0
	adds r6, #0x44
	ldrh r0, [r6]
	cmp r0, #0
	bne .L081480A4
	movs r0, #0x93
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r1, #0x95
	lsls r1, r1, #2
	adds r3, r5, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r1, r0
	bne .L08148070
	ldrh r0, [r6]
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, #0x4c
	movs r1, #0x16
	b .L08148092
	.byte 0x00, 0x00
.L0814806C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08148070:
	cmp r1, r0
	ble .L08148080
	ldrh r0, [r6]
	lsls r0, r0, #3
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r2, r1]
	b .L08148090
.L08148080:
	cmp r1, r0
	bge .L08148094
	ldrh r0, [r6]
	lsls r0, r0, #3
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r3, r1]
	adds r1, #0xb
.L08148090:
	adds r0, #0x4c
.L08148092:
	strh r1, [r0]
.L08148094:
	adds r1, r5, #0
	adds r1, #0x44
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r1, #2
	movs r0, #1
	b .L0814836C
.L081480A4:
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r2, r5
	mov r8, r2
	movs r3, #0x93
	lsls r3, r3, #2
	adds r3, r3, r5
	mov ip, r3
	movs r3, #0
	ldrsb r3, [r2, r3]
	mov r4, ip
	movs r2, #0
	ldrsb r2, [r4, r2]
	cmp r3, r2
	bne .L081480DC
	ldrh r0, [r6]
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, #0x4c
	movs r1, #0x16
	strh r1, [r0]
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	adds r1, r5, #0
	adds r1, #0x46
	movs r0, #1
	b .L0814836C
.L081480DC:
	ldrh r1, [r6]
	movs r0, #0x46
	adds r0, r0, r5
	mov sb, r0
	ldrh r0, [r0]
	subs r7, r1, r0
	lsls r0, r7, #3
	adds r0, r0, r5
	adds r0, #0x4c
	ldrh r4, [r0]
	mov sl, sb
	cmp r4, #0x16
	beq .L081480F8
	b .L0814824C
.L081480F8:
	subs r0, r7, #1
	cmp r0, #0
	bge .L08148100
	b .L08148204
.L08148100:
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, #0x4c
	ldrh r0, [r0]
	cmp r0, #0xb
	bls .L08148190
	cmp r3, r2
	ble .L08148126
	lsls r1, r1, #3
	adds r1, r1, r5
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, #0xb
	adds r1, #0x4c
	strh r0, [r1]
	ldrh r0, [r6]
	adds r0, #1
	b .L08148346
.L08148126:
	movs r3, #3
	ands r3, r1
	cmp r3, #1
	beq .L08148156
	cmp r3, #1
	bgt .L08148138
	cmp r3, #0
	beq .L08148142
	b .L0814836E
.L08148138:
	cmp r3, #2
	beq .L08148164
	cmp r3, #3
	beq .L08148172
	b .L0814836E
.L08148142:
	lsls r0, r1, #3
	adds r0, r0, r5
	mov r4, ip
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, #0x4c
	strh r1, [r0]
	ldrh r0, [r6]
	adds r0, #1
	b .L08148366
.L08148156:
	adds r0, r1, #3
	lsls r0, r0, #3
	adds r0, r0, r5
	mov r2, ip
	movs r1, #0
	ldrsb r1, [r2, r1]
	b .L08148320
.L08148164:
	adds r0, r1, #2
	lsls r0, r0, #3
	adds r0, r0, r5
	mov r2, ip
	movs r1, #0
	ldrsb r1, [r2, r1]
	b .L0814833E
.L08148172:
	adds r2, r5, #0
	adds r2, #0x44
	ldrh r0, [r2]
	adds r0, #1
	lsls r0, r0, #3
	adds r0, r5, r0
	mov r4, ip
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, #0x4c
	strh r1, [r0]
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
	b .L08148368
.L08148190:
	cmp r0, #0xa
	bls .L08148196
	b .L0814836E
.L08148196:
	cmp r2, r3
	ble .L081481AE
	lsls r0, r1, #3
	adds r0, r0, r5
	mov r2, ip
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, #0x4c
	strh r1, [r0]
	ldrh r0, [r6]
	adds r0, #1
	b .L08148346
.L081481AE:
	movs r3, #3
	ands r3, r1
	cmp r3, #1
	bne .L081481B8
	b .L08148312
.L081481B8:
	cmp r3, #1
	bgt .L081481C2
	cmp r3, #0
	beq .L081481CE
	b .L0814836E
.L081481C2:
	cmp r3, #2
	bne .L081481C8
	b .L08148330
.L081481C8:
	cmp r3, #3
	beq .L081481E4
	b .L0814836E
.L081481CE:
	lsls r1, r1, #3
	adds r1, r1, r5
	mov r4, r8
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r0, #0xb
	adds r1, #0x4c
	strh r0, [r1]
	ldrh r0, [r6]
	adds r0, #1
	b .L08148366
.L081481E4:
	adds r2, r5, #0
	adds r2, #0x44
	ldrh r0, [r2]
	adds r0, #1
	lsls r0, r0, #3
	adds r0, r5, r0
	mov r4, r8
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r1, #0xb
	adds r0, #0x4c
	strh r1, [r0]
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
	b .L08148368
.L08148204:
	cmp r2, r3
	ble .L08148218
	lsls r0, r1, #3
	adds r0, r0, r5
	mov r2, ip
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, #0x4c
	strh r1, [r0]
	b .L0814823A
.L08148218:
	cmp r2, r3
	bge .L0814822E
	lsls r1, r1, #3
	adds r1, r1, r5
	mov r3, r8
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, #0xb
	adds r1, #0x4c
	strh r0, [r1]
	b .L0814823A
.L0814822E:
	cmp r2, r3
	bne .L0814823A
	lsls r0, r1, #3
	adds r0, r0, r5
	adds r0, #0x4c
	strh r4, [r0]
.L0814823A:
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r0, #1
	mov r4, sl
	strh r0, [r4]
	b .L0814836E
.L0814824C:
	cmp r4, #0xb
	bls .L081482C4
	cmp r3, r2
	ble .L0814826A
	lsls r1, r1, #3
	adds r1, r1, r5
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, #0xb
	adds r1, #0x4c
	strh r0, [r1]
	ldrh r0, [r6]
	adds r0, #1
	b .L08148346
.L0814826A:
	movs r3, #3
	ands r3, r1
	cmp r3, #1
	beq .L0814829A
	cmp r3, #1
	bgt .L0814827C
	cmp r3, #0
	beq .L08148286
	b .L0814836E
.L0814827C:
	cmp r3, #2
	beq .L081482A8
	cmp r3, #3
	beq .L081482B6
	b .L0814836E
.L08148286:
	lsls r0, r1, #3
	adds r0, r0, r5
	mov r4, ip
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, #0x4c
	strh r1, [r0]
	ldrh r0, [r6]
	adds r0, #1
	b .L08148366
.L0814829A:
	adds r0, r1, #3
	lsls r0, r0, #3
	adds r0, r0, r5
	mov r2, ip
	movs r1, #0
	ldrsb r1, [r2, r1]
	b .L08148320
.L081482A8:
	adds r0, r1, #2
	lsls r0, r0, #3
	adds r0, r0, r5
	mov r2, ip
	movs r1, #0
	ldrsb r1, [r2, r1]
	b .L0814833E
.L081482B6:
	adds r0, r1, #1
	lsls r0, r0, #3
	adds r0, r0, r5
	mov r4, ip
	movs r1, #0
	ldrsb r1, [r4, r1]
	b .L0814835E
.L081482C4:
	cmp r4, #0xa
	bhi .L0814836E
	cmp r2, r3
	ble .L081482E0
	lsls r0, r1, #3
	adds r0, r0, r5
	mov r2, ip
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, #0x4c
	strh r1, [r0]
	ldrh r0, [r6]
	adds r0, #1
	b .L08148346
.L081482E0:
	movs r3, #3
	ands r3, r1
	cmp r3, #1
	beq .L08148312
	cmp r3, #1
	bgt .L081482F2
	cmp r3, #0
	beq .L081482FC
	b .L0814836E
.L081482F2:
	cmp r3, #2
	beq .L08148330
	cmp r3, #3
	beq .L08148350
	b .L0814836E
.L081482FC:
	lsls r1, r1, #3
	adds r1, r1, r5
	mov r4, r8
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r0, #0xb
	adds r1, #0x4c
	strh r0, [r1]
	ldrh r0, [r6]
	adds r0, #1
	b .L08148366
.L08148312:
	adds r0, r1, #3
	lsls r0, r0, #3
	adds r0, r0, r5
	mov r2, r8
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r1, #0xb
.L08148320:
	adds r0, #0x4c
	strh r1, [r0]
	ldrh r0, [r6]
	adds r0, #4
	strh r0, [r6]
	mov r4, sb
	strh r3, [r4]
	b .L0814836E
.L08148330:
	adds r0, r1, #2
	lsls r0, r0, #3
	adds r0, r0, r5
	mov r2, r8
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r1, #0xb
.L0814833E:
	adds r0, #0x4c
	strh r1, [r0]
	ldrh r0, [r6]
	adds r0, #3
.L08148346:
	strh r0, [r6]
	movs r0, #1
	mov r3, sb
	strh r0, [r3]
	b .L0814836E
.L08148350:
	adds r0, r1, #1
	lsls r0, r0, #3
	adds r0, r0, r5
	mov r4, r8
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r1, #0xb
.L0814835E:
	adds r0, #0x4c
	strh r1, [r0]
	ldrh r0, [r6]
	adds r0, #2
.L08148366:
	strh r0, [r6]
.L08148368:
	movs r0, #1
	mov r1, sb
.L0814836C:
	strh r0, [r1]
.L0814836E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0814837C
sub_0814837C: @ 0x0814837C
.L0814837C:
	push {r4, r5, lr}
	ldr r5, .L081483B0
	movs r4, #0
.L08148382:
	lsls r3, r4, #3
	adds r3, r5, r3
	adds r0, r4, #4
	lsls r0, r0, #3
	adds r0, r5, r0
	adds r1, r0, #0
	adds r1, #0x48
	ldrb r2, [r1]
	adds r1, r3, #0
	adds r1, #0x48
	strb r2, [r1]
	adds r0, #0x4c
	ldrh r0, [r0]
	adds r3, #0x4c
	strh r0, [r3]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x3b
	bls .L08148382
	pop {r4, r5}
	pop {r0}
	bx r0
.L081483B0: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081483B4
sub_081483B4: @ 0x081483B4
.L081483B4:
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r5, .L08148414
	movs r4, #0
	ldr r6, .L08148418
.L081483BE:
	lsls r0, r4, #3
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0x48
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08148402
	adds r0, r1, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	ldr r1, .L0814841C
	lsls r3, r4, #2
	adds r3, r3, r1
	movs r1, #0x92
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r3]
	ldrh r2, [r2]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldrb r1, [r3, #2]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #2
	bl Sprite_Draw
.L08148402:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x3b
	bls .L081483BE
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.L08148414: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08148418: .4byte gUnknown_0879C878
.L0814841C: .4byte gUnknown_0879C92C

	thumb_func_start sub_08148420
sub_08148420: @ 0x08148420
	ldr r0, .L08148428
	strh r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L08148428: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start Baccarat_LoadCards
Baccarat_LoadCards: @ 0x0814842C
	push {r4, r5, lr}
	ldr r5, .L0814845C
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #9
	adds r5, r0, r5
	ldr r0, .L08148460
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r4, .L08148464
	adds r1, r4, #0
	bl HuffUnComp
	adds r0, r4, #0
	adds r1, r5, #0
	bl LZ77UnCompWram
	ldr r1, .L08148468
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
.L0814845C: .4byte 0x0200F874 @ EWRAM+0xF874
.L08148460: .4byte gBaccaratCardGfx
.L08148464: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L08148468: .4byte 0x03003BB4 @ IWRAM+0x3BB4

	thumb_func_start sub_0814846C
sub_0814846C: @ 0x0814846C
.L0814846C:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, .L081484B0
	ldr r4, .L081484B4
	movs r2, #0xab
	lsls r2, r2, #2
	adds r1, r3, r2
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r2, r1, #3
	adds r2, r2, r1
	lsls r2, r2, #0xa
	ldr r1, .L081484B8
	adds r3, r3, r1
	adds r3, r0, r3
	ldrb r3, [r3]
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #7
	adds r2, r2, r1
	adds r4, r2, r4
	ldr r1, .L081484BC
	str r4, [r1]
	lsls r0, r0, #0xa
	ldr r2, .L081484C0
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, .L081484C4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4}
	pop {r0}
	bx r0
.L081484B0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081484B4: .4byte 0x0200F874 @ EWRAM+0xF874
.L081484B8: .4byte 0x000002B2
.L081484BC: .4byte 0x040000D4 @ REG_DMA3SAD
.L081484C0: .4byte 0x06014C00 @ VRAM+0x14C00
.L081484C4: .4byte 0x840000A0

	thumb_func_start sub_081484C8
sub_081484C8: @ 0x081484C8
	push {lr}
	movs r0, #0
	bl sub_0814846C
	pop {r0}
	bx r0

	thumb_func_start sub_081484D4
sub_081484D4: @ 0x081484D4
	push {lr}
	movs r0, #1
	bl sub_0814846C
	pop {r0}
	bx r0

	thumb_func_start sub_081484E0
sub_081484E0: @ 0x081484E0
	push {lr}
	movs r0, #2
	bl sub_0814846C
	pop {r0}
	bx r0

	thumb_func_start sub_081484EC
sub_081484EC: @ 0x081484EC
	push {lr}
	movs r0, #3
	bl sub_0814846C
	pop {r0}
	bx r0

	thumb_func_start sub_081484F8
sub_081484F8: @ 0x081484F8
	push {lr}
	movs r0, #4
	bl sub_0814846C
	pop {r0}
	bx r0

	thumb_func_start sub_08148504
sub_08148504: @ 0x08148504
	push {lr}
	movs r0, #5
	bl sub_0814846C
	pop {r0}
	bx r0

	thumb_func_start sub_08148510
sub_08148510: @ 0x08148510
.L08148510:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r3, .L08148538
	movs r5, #0xab
	lsls r5, r5, #2
	adds r0, r3, r5
	adds r0, r4, r0
	strb r1, [r0]
	ldr r0, .L0814853C
	adds r3, r3, r0
	adds r3, r4, r3
	strb r2, [r3]
	cmp r4, #5
	bhi .L08148594
	lsls r0, r4, #2
	ldr r1, .L08148540
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08148538: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814853C: .4byte 0x000002B2
.L08148540: .4byte gUnknown_08148544
	.global gUnknown_08148544
gUnknown_08148544:
.L08148544: @ jump table
	.4byte .L0814855C
	.4byte .L08148564
	.4byte .L0814856C
	.4byte .L08148574
	.4byte .L0814857C
	.4byte .L0814858C
.L0814855C:
	ldr r0, .L08148560
	b .L0814857E
.L08148560: .4byte sub_081484C8
.L08148564:
	ldr r0, .L08148568
	b .L0814857E
.L08148568: .4byte sub_081484D4
.L0814856C:
	ldr r0, .L08148570
	b .L0814857E
.L08148570: .4byte sub_081484E0
.L08148574:
	ldr r0, .L08148578
	b .L0814857E
.L08148578: .4byte sub_081484EC
.L0814857C:
	ldr r0, .L08148588
.L0814857E:
	movs r1, #1
	bl VBlankTask_AddCounted
	b .L08148594
	.byte 0x00, 0x00
.L08148588: .4byte sub_081484F8
.L0814858C:
	ldr r0, .L0814859C
	movs r1, #1
	bl VBlankTask_AddCounted
.L08148594:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814859C: .4byte sub_08148504

	thumb_func_start sub_081485A0
sub_081485A0: @ 0x081485A0
.L081485A0:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sb, r3
	bl NumberToDigits
	mov r8, r0
	subs r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r5, #0
	cmp r5, r7
	bhs .L08148604
	ldr r0, .L08148614
	mov sl, r0
.L081485D0:
	mov r1, r8
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #2
	add r0, sl
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r6, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	subs r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r6, #0
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r5, #1
	cmp r5, r7
	blo .L081485D0
.L08148604:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08148614: .4byte gUnknown_0879CE24

	thumb_func_start sub_08148618
sub_08148618: @ 0x08148618
.L08148618:
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r3, .L08148690
	ldrh r0, [r3]
	cmp r0, #3
	bne .L08148688
	adds r0, r3, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r3, #0
	adds r0, #0xfe
	ldrh r1, [r0]
	movs r0, #0xb
	muls r0, r1, r0
	adds r0, #0x24
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r1, #3
	bls .L08148650
	adds r0, r2, #0
	adds r0, #0x1b
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L08148650:
	ldr r1, .L08148694
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r3, r0
	ldrh r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r5, [sp, #4]
	str r2, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L08148698
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne .L08148688
	ldrh r0, [r4]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strh r0, [r4]
.L08148688:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
.L08148690: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08148694: .4byte gUnknown_0879CE58
.L08148698: .4byte 0x030031BC @ IWRAM+0x31BC

	thumb_func_start sub_0814869C
sub_0814869C: @ 0x0814869C
.L0814869C:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r3, .L08148710
	ldr r1, .L08148714
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov ip, r0
	lsls r1, r4, #1
	adds r0, r3, #0
	adds r0, #0x84
	adds r0, r1, r0
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08148706
	adds r0, r3, #0
	adds r0, #0xac
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r5, r3, #0
	adds r5, #0xd4
	cmp r0, #0
	bne .L081486DE
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq .L081486E4
.L081486DE:
	ldrh r7, [r2]
	adds r0, r1, r5
	ldrh r6, [r0]
.L081486E4:
	lsls r1, r4, #1
	adds r0, r3, #0
	adds r0, #0x84
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, ip
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r7, [sp, #4]
	str r6, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08148706:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08148710: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08148714: .4byte gUnknown_0879CEA8

	thumb_func_start sub_08148718
sub_08148718: @ 0x08148718
.L08148718:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r2, .L08148750
	mov ip, r2
	lsrs r2, r0, #0xf
	mov r0, ip
	adds r0, #0x84
	adds r0, r2, r0
	strh r1, [r0]
	cmp r4, #0
	beq .L0814873E
	mov r0, ip
	adds r0, #0xac
	adds r0, r2, r0
	strh r4, [r0]
.L0814873E:
	cmp r3, #0
	beq .L0814874A
	mov r0, ip
	adds r0, #0xd4
	adds r0, r2, r0
	strh r3, [r0]
.L0814874A:
	pop {r4}
	pop {r0}
	bx r0
.L08148750: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08148754
sub_08148754: @ 0x08148754
.L08148754:
	push {r4, lr}
	lsls r0, r0, #0x10
	ldr r4, .L0814877C
	mov ip, r4
	lsrs r0, r0, #0xf
	adds r4, #0x84
	adds r4, r0, r4
	strh r1, [r4]
	mov r1, ip
	adds r1, #0xac
	adds r1, r0, r1
	strh r2, [r1]
	mov r1, ip
	adds r1, #0xd4
	adds r0, r0, r1
	strh r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814877C: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08148780
sub_08148780: @ 0x08148780
	push {lr}
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r3, [sp, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	bl sub_08148718
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081487A4
sub_081487A4: @ 0x081487A4
	push {lr}
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r3, [sp, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	bl sub_08148754
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_081487C8
sub_081487C8: @ 0x081487C8
.L081487C8:
	ldr r1, .L081487D4
	movs r2, #0xb9
	lsls r2, r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	bx lr
.L081487D4: .4byte 0x03000040 @ IWRAM+0x40

	thumb_func_start sub_081487D8
sub_081487D8: @ 0x081487D8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r6, .L08148900
	movs r4, #0
	str r4, [sp]
	ldr r2, .L08148904
	mov r0, sp
	adds r1, r6, #0
	bl CpuSet
	str r4, [sp, #4]
	ldr r1, .L08148908
	add r0, sp, #4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, .L0814890C
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xcc
	ldr r2, .L08148910
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L08148914
	strh r4, [r0]
	ldr r1, .L08148918
	movs r0, #0xf0
	strh r0, [r1]
	bl sub_081487C8
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #8
	strh r1, [r0]
	movs r2, #0xcd
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	movs r0, #0xce
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x10
	strh r0, [r1]
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	ldr r1, .L0814891C
	ldr r0, .L08148920
	strh r0, [r1]
	ldr r1, .L08148924
	movs r0, #0x10
	strh r0, [r1]
	movs r0, #1
	strh r0, [r6]
	movs r0, #0
	movs r2, #0xb4
	adds r2, r2, r6
	mov r8, r2
	movs r1, #0xdc
	adds r1, r1, r6
	mov sb, r1
.L0814885E:
	movs r5, #0
	adds r7, r0, #1
.L08148862:
	bl Random_Byte
	movs r1, #0x3f
	ands r0, r1
	lsls r0, r0, #1
	movs r2, #0x81
	lsls r2, r2, #1
	adds r4, r6, r2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne .L08148862
	movs r0, #1
	strh r0, [r1]
	adds r5, #1
	cmp r5, #0xf
	bls .L08148862
	bl sub_08149B38
	movs r5, #0
	movs r1, #0
	adds r0, r4, #0
.L0814888E:
	strh r1, [r0]
	adds r0, #2
	adds r5, #1
	cmp r5, #0x3f
	bls .L0814888E
	adds r0, r7, #0
	cmp r0, #0xf
	bls .L0814885E
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08148718
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08148718
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08148718
	movs r0, #3
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_08148718
	movs r0, #4
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_08148718
	movs r0, #0x87
	mov r1, r8
	strh r0, [r1]
	movs r0, #0xa0
	mov r2, sb
	strh r0, [r2]
	bl sub_080C31F0
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08148900: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08148904: .4byte 0x05000200 @ PLTT+0x200
.L08148908: .4byte 0x040000D4 @ REG_DMA3SAD
.L0814890C: .4byte 0x85001000
.L08148910: .4byte 0x00004008
.L08148914: .4byte 0x03000002 @ IWRAM+0x2
.L08148918: .4byte 0x03000000 @ IWRAM
.L0814891C: .4byte 0x03000042 @ IWRAM+0x42
.L08148920: .4byte 0x00000808
.L08148924: .4byte 0x03000044 @ IWRAM+0x44

	thumb_func_start sub_08148928
sub_08148928: @ 0x08148928
.L08148928:
	push {lr}
	ldr r1, .L0814893C
	ldrh r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls .L08148940
	movs r0, #0
	b .L0814895E
.L0814893C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08148940:
	movs r2, #0
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, #0
	beq .L0814895C
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r2, r0, #0x1f
.L0814895C:
	adds r0, r2, #0
.L0814895E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08148964
sub_08148964: @ 0x08148964
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	ldr r5, .L081489A8
	ldr r0, .L081489AC
	ldr r1, [r0]
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne .L081489EA
	movs r0, #0xcf
	lsls r0, r0, #1
	adds r3, r5, r0
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	bne .L081489B0
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r1, r5, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	bne .L081489C6
	movs r0, #1
	strh r0, [r3]
	b .L081489C6
	.byte 0x00, 0x00
.L081489A8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081489AC: .4byte 0x030031BC @ IWRAM+0x31BC
.L081489B0:
	movs r0, #0xcd
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne .L081489C6
	strh r1, [r3]
.L081489C6:
	ldr r2, .L08148A0C
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	lsls r0, r0, #8
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, .L08148A10
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrh r0, [r0]
	strh r0, [r1]
.L081489EA:
	ldrh r0, [r5]
	cmp r0, #1
	beq .L08148A14
	adds r1, r5, #4
	mov r8, r1
	movs r2, #0x84
	adds r2, r2, r5
	mov sb, r2
	cmp r0, #1
	bgt .L08148A00
	b .L08148DF6
.L08148A00:
	cmp r0, #2
	beq .L08148A2C
	cmp r0, #3
	bne .L08148A0A
	b .L08148C86
.L08148A0A:
	b .L08148DF6
.L08148A0C: .4byte 0x03000042 @ IWRAM+0x42
.L08148A10: .4byte 0x03000044 @ IWRAM+0x44
.L08148A14:
	ldr r0, .L08148A24
	ldr r1, .L08148A28
	bl Task_Create
	movs r0, #0
	strh r0, [r5]
	b .L08148BAC
	.byte 0x00, 0x00
.L08148A24: .4byte gUnknown_0879D100
.L08148A28: .4byte 0x0000FFFF
.L08148A2C:
	ldr r0, .L08148A80
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08148A88
	ldrh r0, [r5, #2]
	cmp r0, #1
	bne .L08148A88
	movs r0, #0xca
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r2, [r4]
	cmp r2, #0
	bne .L08148A4C
	b .L08148DF6
.L08148A4C:
	movs r3, #1
	ldr r0, .L08148A84
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L08148A5C
	movs r3, #0xa
.L08148A5C:
	cmp r3, r2
	bls .L08148A62
	adds r3, r2, #0
.L08148A62:
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, [r2]
	adds r0, r1, r3
	cmp r0, #0x64
	bls .L08148A74
	movs r0, #0x64
	subs r3, r0, r1
.L08148A74:
	adds r0, r1, r3
	str r0, [r2]
	ldr r0, [r4]
	subs r0, r0, r3
	str r0, [r4]
	b .L08148C2A
.L08148A80: .4byte 0x03003964 @ IWRAM+0x3964
.L08148A84: .4byte 0x030031D0 @ IWRAM+0x31D0
.L08148A88:
	ldr r2, .L08148AB0
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08148A96
	b .L08148B94
.L08148A96:
	ldrh r1, [r5, #2]
	cmp r1, #2
	beq .L08148B10
	cmp r1, #2
	bgt .L08148AB4
	cmp r1, #0
	beq .L08148AC4
	adds r2, r5, #4
	mov r8, r2
	movs r3, #0x84
	adds r3, r3, r5
	mov sb, r3
	b .L08148DF6
.L08148AB0: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08148AB4:
	cmp r1, #3
	beq .L08148B54
	adds r6, r5, #4
	mov r8, r6
	movs r0, #0x84
	adds r0, r0, r5
	mov sb, r0
	b .L08148DF6
.L08148AC4:
	adds r0, r5, #0
	adds r0, #0xfc
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #3
	strh r0, [r5]
	ldrh r1, [r5, #2]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r5, #2]
	movs r4, #0
	ldr r3, .L08148B0C
	adds r6, r5, #4
	mov r8, r6
	movs r0, #0x84
	adds r0, r0, r5
	mov sb, r0
	movs r2, #0x81
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0
.L08148AF4:
	lsls r0, r4, #1
	adds r0, r1, r0
	strh r2, [r0]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x3f
	bls .L08148AF4
	movs r0, #0xf0
	strh r0, [r3]
	b .L08148DF6
	.byte 0x00, 0x00
.L08148B0C: .4byte 0x03000000 @ IWRAM
.L08148B10:
	ldrh r0, [r5, #4]
	ldr r4, .L08148B28
	ands r4, r0
	cmp r4, #0
	bne .L08148B34
	ldr r0, .L08148B2C
	ldr r1, .L08148B30
	bl Task_Create
	strh r4, [r5]
	b .L08148B40
	.byte 0x00, 0x00
.L08148B28: .4byte 0x00007FFF
.L08148B2C: .4byte gUnknown_0879D910
.L08148B30: .4byte 0x0000FFFF
.L08148B34:
	ldr r0, .L08148B4C
	ldr r1, .L08148B50
	bl Task_Create
	movs r0, #0
	strh r0, [r5]
.L08148B40:
	movs r0, #0xb2
	lsls r0, r0, #1
	bl sub_080C51D4
	b .L08148BAC
	.byte 0x00, 0x00
.L08148B4C: .4byte gUnknown_0879D9B0
.L08148B50: .4byte 0x0000FFFF
.L08148B54:
	movs r4, #0
	adds r0, r5, #4
	mov r8, r0
	movs r1, #0x84
	adds r1, r1, r5
	mov sb, r1
	mov r3, r8
	ldr r6, .L08148B8C
.L08148B64:
	lsls r1, r4, #1
	adds r1, r3, r1
	ldrh r2, [r1]
	adds r0, r6, #0
	ands r0, r2
	strh r0, [r1]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x3f
	bls .L08148B64
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	str r1, [r0]
	ldr r0, .L08148B90
	bl sub_080C51D4
	b .L08148DF6
.L08148B8C: .4byte 0x00007FFF
.L08148B90: .4byte 0x00000163
.L08148B94:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08148BB8
	bl sub_08148928
	cmp r0, #1
	bne .L08148BB8
	bl sub_08149510
.L08148BAC:
	adds r3, r5, #4
	mov r8, r3
	movs r6, #0x84
	adds r6, r6, r5
	mov sb, r6
	b .L08148DF6
.L08148BB8:
	ldr r2, .L08148BDC
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	adds r3, r2, #0
	movs r1, #0x84
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	beq .L08148BE0
	ldrh r0, [r1]
	cmp r0, #0
	bne .L08148BE0
	bl sub_08149640
	b .L08148DC8
	.byte 0x00, 0x00
.L08148BDC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08148BE0:
	ldr r2, .L08148C34
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08148C3C
	ldrh r0, [r5, #2]
	cmp r0, #1
	bne .L08148C3C
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r4, r5, r3
	ldr r2, [r4]
	adds r6, r5, #4
	mov r8, r6
	cmp r2, #0
	bne .L08148C04
	b .L08148DF6
.L08148C04:
	movs r3, #1
	ldr r0, .L08148C38
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L08148C14
	movs r3, #0xa
.L08148C14:
	cmp r3, r2
	bls .L08148C1A
	adds r3, r2, #0
.L08148C1A:
	subs r0, r2, r3
	str r0, [r4]
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, r0, r3
	str r0, [r1]
.L08148C2A:
	movs r0, #0xb0
	lsls r0, r0, #1
	bl sub_080C51D4
	b .L08148DF6
.L08148C34: .4byte 0x03003964 @ IWRAM+0x3964
.L08148C38: .4byte 0x030031D0 @ IWRAM+0x31D0
.L08148C3C:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	adds r1, r5, #4
	mov r8, r1
	cmp r0, #0
	beq .L08148C4C
	b .L08148DF6
.L08148C4C:
	ldrh r2, [r2]
	movs r0, #0x20
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq .L08148C6C
	ldrh r0, [r5, #2]
	cmp r0, #0
	beq .L08148C66
	subs r0, #1
	strh r0, [r5, #2]
	b .L08148DF6
.L08148C66:
	movs r0, #3
	strh r0, [r5, #2]
	b .L08148DF6
.L08148C6C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne .L08148C76
	b .L08148DF6
.L08148C76:
	ldrh r0, [r5, #2]
	cmp r0, #3
	beq .L08148C82
	adds r0, #1
	strh r0, [r5, #2]
	b .L08148DF6
.L08148C82:
	strh r1, [r5, #2]
	b .L08148DF6
.L08148C86:
	movs r0, #2
	movs r1, #0xa0
	bl sub_081490E4
	cmp r0, #0
	bne .L08148C94
	b .L08148DF6
.L08148C94:
	ldr r2, .L08148CDC
	ldrh r1, [r2]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L08148D04
	adds r0, r5, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0xfc
	lsls r0, r0, #3
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, #4
	adds r3, r5, r0
	ldrh r2, [r3]
	movs r6, #0x80
	lsls r6, r6, #8
	adds r0, r6, #0
	ands r0, r2
	cmp r0, #0
	beq .L08148CE4
	ldr r0, .L08148CE0
	ands r0, r2
	strh r0, [r3]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	b .L08148CFA
	.byte 0x00, 0x00
.L08148CDC: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08148CE0: .4byte 0x00007FFF
.L08148CE4:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r1, [r4]
	cmp r1, #0x10
	beq .L08148CFA
	adds r0, r6, #0
	orrs r0, r2
	strh r0, [r3]
	adds r0, r1, #1
	str r0, [r4]
.L08148CFA:
	movs r0, #0xb2
	lsls r0, r0, #1
	bl sub_080C51D4
	b .L08148DF6
.L08148D04:
	ldrh r1, [r2]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L08148D16
	strh r3, [r5]
	strh r4, [r5, #2]
	b .L08148DF6
.L08148D16:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08148D38
	bl sub_08148928
	cmp r0, #1
	bne .L08148D38
	movs r0, #0xac
	lsls r0, r0, #1
	bl sub_080C51D4
	bl sub_08149510
	b .L08148DF6
.L08148D38:
	ldr r0, .L08148D58
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	movs r1, #0x84
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	beq .L08148D5C
	ldrh r0, [r1]
	cmp r0, #0
	bne .L08148D5C
	bl sub_08149640
	b .L08148DC8
.L08148D58: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08148D5C:
	ldr r0, .L08148D7C
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L08148D8A
	adds r1, r5, #0
	adds r1, #0xfe
	ldrh r0, [r1]
	cmp r0, #0
	beq .L08148D80
	subs r0, #1
	b .L08148DD0
	.byte 0x00, 0x00
.L08148D7C: .4byte 0x03003964 @ IWRAM+0x3964
.L08148D80:
	movs r0, #7
	strh r0, [r1]
	adds r6, r5, #4
	mov r8, r6
	b .L08148DF6
.L08148D8A:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08148DAE
	adds r1, r5, #0
	adds r1, #0xfe
	ldrh r0, [r1]
	cmp r0, #7
	beq .L08148DA6
	adds r0, #1
	strh r0, [r1]
	adds r0, r5, #4
	mov r8, r0
	b .L08148DF6
.L08148DA6:
	strh r2, [r1]
	adds r1, r5, #4
	mov r8, r1
	b .L08148DF6
.L08148DAE:
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq .L08148DD8
	adds r1, r5, #0
	adds r1, #0xfc
	ldrh r0, [r1]
	cmp r0, #0
	beq .L08148DCE
	subs r0, #1
	strh r0, [r1]
.L08148DC8:
	adds r2, r5, #4
	mov r8, r2
	b .L08148DF6
.L08148DCE:
	movs r0, #7
.L08148DD0:
	strh r0, [r1]
	adds r3, r5, #4
	mov r8, r3
	b .L08148DF6
.L08148DD8:
	movs r0, #0x10
	ands r0, r1
	adds r6, r5, #4
	mov r8, r6
	cmp r0, #0
	beq .L08148DF6
	adds r1, r5, #0
	adds r1, #0xfc
	ldrh r0, [r1]
	cmp r0, #7
	beq .L08148DF4
	adds r0, #1
	strh r0, [r1]
	b .L08148DF6
.L08148DF4:
	strh r2, [r1]
.L08148DF6:
	movs r0, #8
	str r0, [sp, #0xc]
	movs r1, #0x27
	str r1, [sp, #0x10]
	movs r4, #0
	ldr r2, .L08148E70
	mov sl, r2
.L08148E04:
	movs r1, #7
	ands r1, r4
	lsls r0, r1, #4
	subs r0, r0, r1
	ldr r3, [sp, #0xc]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov ip, r7
	lsrs r1, r4, #3
	movs r0, #0xb
	muls r0, r1, r0
	ldr r6, [sp, #0x10]
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r4, #0x1f
	bls .L08148E30
	adds r0, r2, #0
	adds r0, #0x1b
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L08148E30:
	lsls r1, r4, #1
	movs r3, #0x81
	lsls r3, r3, #1
	adds r0, r5, r3
	adds r0, r0, r1
	ldrh r3, [r0]
	cmp r3, #0
	beq .L08148E86
	mov r6, r8
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq .L08148E74
	lsls r0, r4, #2
	add r0, sl
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r7, [sp, #4]
	str r2, [sp, #8]
	movs r1, #1
	movs r2, #9
	movs r3, #0
	bl Sprite_DrawBlended
	b .L08148EFA
.L08148E70: .4byte gUnknown_0879CD14
.L08148E74:
	lsls r0, r4, #2
	add r0, sl
	ldr r0, [r0]
	str r1, [sp]
	str r7, [sp, #4]
	str r2, [sp, #8]
	movs r1, #1
	movs r2, #9
	b .L08148EBE
.L08148E86:
	mov r6, r8
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r6, #0x80
	lsls r6, r6, #8
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne .L08148ECC
	subs r6, #1
	adds r0, r6, #0
	ands r0, r1
	movs r6, #5
	cmp r0, #0
	beq .L08148EAE
	subs r0, #1
	lsls r0, r0, #1
	ldr r1, .L08148EC8
	adds r0, r0, r1
	ldrh r6, [r0]
.L08148EAE:
	lsls r0, r4, #2
	add r0, sl
	ldr r0, [r0]
	str r3, [sp]
	str r7, [sp, #4]
	str r2, [sp, #8]
	movs r1, #1
	adds r2, r6, #0
.L08148EBE:
	movs r3, #0
	bl Sprite_Draw
	b .L08148EFA
	.byte 0x00, 0x00
.L08148EC8: .4byte gUnknown_0879DDC4
.L08148ECC:
	ldr r6, .L08148FDC
	adds r0, r6, #0
	ands r0, r1
	movs r6, #0xb
	cmp r0, #0
	beq .L08148EE2
	subs r0, #1
	lsls r0, r0, #1
	ldr r1, .L08148FE0
	adds r0, r0, r1
	ldrh r6, [r0]
.L08148EE2:
	lsls r0, r4, #2
	add r0, sl
	ldr r0, [r0]
	str r3, [sp]
	mov r3, ip
	str r3, [sp, #4]
	str r2, [sp, #8]
	movs r1, #1
	adds r2, r6, #0
	movs r3, #0
	bl Sprite_DrawBlended
.L08148EFA:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x3f
	bhi .L08148F06
	b .L08148E04
.L08148F06:
	bl sub_08148618
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, #2
	movs r2, #0xf
	movs r3, #0x5e
	bl sub_081485A0
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #2
	movs r2, #0x3d
	movs r3, #0x5e
	bl sub_081485A0
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #2
	movs r2, #0x6a
	movs r3, #0x5e
	bl sub_081485A0
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #3
	movs r2, #0x93
	movs r3, #0x1c
	bl sub_081485A0
	adds r6, #0x10
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, #6
	movs r2, #0xba
	movs r3, #0x1c
	bl sub_081485A0
	ldrh r1, [r5, #2]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne .L08148FA0
	ldrh r1, [r5, #2]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #0x11
	movs r3, #0x90
	lsls r3, r3, #0xc
	adds r0, r0, r3
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	movs r6, #0x1b
	ldr r0, .L08148FE4
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r2, [sp]
	ldr r1, [sp, #0xc]
	str r1, [sp, #4]
	str r6, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08148FA0:
	bl sub_0814971C
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #1
	beq .L08148FF8
	movs r0, #2
	movs r1, #8
	movs r2, #6
	bl sub_0814869C
	ldrh r0, [r5]
	cmp r0, #4
	bne .L08148FF8
	ldr r0, .L08148FE8
	ldr r0, [r0]
	movs r1, #7
	bl __udivsi3
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne .L08148FEC
	movs r0, #2
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_08148718
	b .L08148FF8
.L08148FDC: .4byte 0x00007FFF
.L08148FE0: .4byte gUnknown_0879DDC4
.L08148FE4: .4byte gUnknown_0879CE14
.L08148FE8: .4byte 0x030031BC @ IWRAM+0x31BC
.L08148FEC:
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08148718
.L08148FF8:
	ldr r0, .L08149020
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L08149048
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r3, [r0]
	cmp r3, #0
	beq .L08149030
	mov r6, sb
	ldrh r0, [r6]
	adds r1, r0, #0
	cmp r1, #0
	bne .L08149024
	movs r0, #4
	strh r0, [r6]
	b .L08149048
.L08149020: .4byte 0x030031BC @ IWRAM+0x31BC
.L08149024:
	cmp r1, #1
	beq .L08149048
	subs r0, #1
	mov r1, sb
	strh r0, [r1]
	b .L08149048
.L08149030:
	mov r2, sb
	ldrh r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq .L08149048
	cmp r1, #4
	beq .L08149044
	adds r0, #1
	strh r0, [r2]
	b .L08149048
.L08149044:
	mov r2, sb
	strh r3, [r2]
.L08149048:
	movs r0, #0
	movs r1, #7
	movs r2, #4
	bl sub_0814869C
	movs r0, #3
	movs r1, #0xba
	movs r2, #6
	bl sub_0814869C
	bl sub_08148928
	adds r1, r0, #0
	cmp r1, #1
	bne .L0814908A
	ldr r0, .L08149078
	ldr r0, [r0]
	lsrs r0, r0, #4
	ands r0, r1
	cmp r0, #0
	bne .L0814907C
	movs r0, #3
	movs r1, #1
	b .L08149080
.L08149078: .4byte 0x030031BC @ IWRAM+0x31BC
.L0814907C:
	movs r0, #3
	movs r1, #0
.L08149080:
	movs r2, #0
	movs r3, #0
	bl sub_08148718
	b .L08149096
.L0814908A:
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_08148718
.L08149096:
	movs r0, #1
	movs r1, #0xbb
	movs r2, #4
	bl sub_0814869C
	ldrh r0, [r5]
	cmp r0, #5
	beq .L081490D4
	movs r0, #4
	movs r1, #0xbb
	movs r2, #4
	bl sub_0814869C
	ldr r0, .L081490CC
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L081490D4
	adds r1, r5, #0
	adds r1, #0x8c
	ldrh r0, [r1]
	cmp r0, #6
	beq .L081490D0
	adds r0, #1
	b .L081490D2
	.byte 0x00, 0x00
.L081490CC: .4byte 0x030031BC @ IWRAM+0x31BC
.L081490D0:
	movs r0, #1
.L081490D2:
	strh r0, [r1]
.L081490D4:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_081490E4
sub_081490E4: @ 0x081490E4
.L081490E4:
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, .L08149104
	adds r2, r0, #0
	adds r2, #0xdc
	movs r4, #0
	ldrh r0, [r2]
	cmp r0, r1
	bls .L08149108
	subs r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, r1
	bhi .L08149116
	b .L08149112
	.byte 0x00, 0x00
.L08149104: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149108:
	adds r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, r1
	blo .L08149116
.L08149112:
	strh r1, [r2]
	movs r4, #1
.L08149116:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00

	thumb_func_start sub_08149120
sub_08149120: @ 0x08149120
.L08149120:
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r1, r2, #0
	bl sub_081490E4
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_08149134
sub_08149134: @ 0x08149134
	push {r4, r5, lr}
	ldr r4, .L08149164
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r2, r4, r3
	ldr r2, [r2]
	lsls r3, r2, #4
	adds r3, r3, r2
	lsls r3, r3, #1
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r2, r4, r5
	ldr r2, [r2]
	lsls r2, r2, #1
	ldr r4, .L08149168
	adds r2, r2, r4
	adds r3, r3, r2
	ldrh r2, [r3]
	bl sub_08149120
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08149164: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149168: .4byte gUnknown_0879CEBC

	thumb_func_start sub_0814916C
sub_0814916C: @ 0x0814916C
	push {lr}
	ldr r2, .L08149184
	strh r1, [r2]
	cmp r1, #2
	bne .L0814917E
	ldrh r1, [r2, #2]
	ldr r0, .L08149188
	ands r0, r1
	strh r0, [r2, #2]
.L0814917E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08149184: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149188: .4byte 0x00007FFF

	thumb_func_start sub_0814918C
sub_0814918C: @ 0x0814918C
	push {r4, lr}
	sub sp, #4
	adds r0, r1, #0
	ldr r4, .L081491B4
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r2, .L081491B8
	movs r3, #0x80
	lsls r3, r3, #2
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r4, #0
	bl Palette_CopyWithEffect
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
.L081491B4: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L081491B8: .4byte 0x03002BB0 @ IWRAM+0x2BB0

	thumb_func_start sub_081491BC
sub_081491BC: @ 0x081491BC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r4, .L08149224
	movs r0, #0
	strh r0, [r6, #0x1c]
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r7, r4, r0
.L081491CC:
	bl Random_Byte
	adds r2, r0, #0
	movs r0, #0x3f
	ands r2, r0
	lsls r3, r2, #1
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, #0
	bne .L081491CC
	movs r5, #1
	strh r5, [r1]
	adds r0, r4, #4
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
	ands r0, r1
	cmp r0, #0
	beq .L08149210
	ldr r0, [r7]
	adds r0, #1
	str r0, [r7]
	strh r5, [r6, #0x1c]
	ldr r1, .L08149228
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, .L0814922C
	bl sub_080C51D4
.L08149210:
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08149224: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149228: .4byte 0x00000221
.L0814922C: .4byte 0x0000015D

	thumb_func_start sub_08149230
sub_08149230: @ 0x08149230
	push {r4, lr}
	sub sp, #0xc
	ldr r0, .L08149274
	ldr r1, .L08149278
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r1, #7
	ands r1, r2
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsrs r1, r2, #3
	movs r0, #0xb
	muls r0, r1, r0
	adds r3, r0, #0
	adds r3, #0x27
	cmp r2, #0x1f
	bls .L0814925A
	adds r3, #0x1b
.L0814925A:
	ldr r0, .L0814927C
	movs r1, #0
	str r1, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
.L08149274: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149278: .4byte 0x00000221
.L0814927C: .4byte gUnknown_081513A4

	thumb_func_start sub_08149280
sub_08149280: @ 0x08149280
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L081492D4
	mov ip, r0
	adds r5, r4, #0
	adds r5, #0x24
	movs r0, #0xc2
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0]
	movs r0, #0x34
	muls r1, r0, r1
	ldr r0, .L081492D8
	adds r1, r1, r0
	movs r3, #0x89
	lsls r3, r3, #2
	add r3, ip
	movs r2, #0xc8
	lsls r2, r2, #1
	add r2, ip
	movs r0, #0xc6
	lsls r0, r0, #1
	add r0, ip
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r2]
	ldr r1, [r0]
	muls r1, r2, r1
	str r1, [r3]
	ldr r0, [r0]
	cmp r0, #0
	beq .L081492C4
	movs r0, #1
.L081492C4:
	strh r0, [r4, #0x1c]
	movs r0, #0xf0
	strh r0, [r5]
	movs r0, #0x5a
	strh r0, [r5, #2]
	pop {r4, r5}
	pop {r0}
	bx r0
.L081492D4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081492D8: .4byte gUnknown_0879D338

	thumb_func_start sub_081492DC
sub_081492DC: @ 0x081492DC
	push {lr}
	sub sp, #0xc
	ldr r2, .L08149300
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r0, #0x24]
	str r1, [sp, #4]
	ldrh r0, [r0, #0x26]
	str r0, [sp, #8]
	adds r0, r2, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r0}
	bx r0
.L08149300: .4byte gUnknown_081519E8

	thumb_func_start sub_08149304
sub_08149304: @ 0x08149304
	push {lr}
	sub sp, #0xc
	ldr r2, .L08149328
	movs r1, #0
	str r1, [sp]
	ldrh r1, [r0, #0x24]
	str r1, [sp, #4]
	ldrh r0, [r0, #0x26]
	str r0, [sp, #8]
	adds r0, r2, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r0}
	bx r0
.L08149328: .4byte gUnknown_081519D0

	thumb_func_start sub_0814932C
sub_0814932C: @ 0x0814932C
	ldrh r2, [r0, #0x24]
	subs r2, r2, r1
	strh r2, [r0, #0x24]
	bx lr

	thumb_func_start sub_08149334
sub_08149334: @ 0x08149334
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r4, #0x4c
	movs r2, #0x44
	ldr r0, .L081493C8
	movs r1, #0
	str r1, [sp]
	str r4, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r0, #6
	mov sl, r0
	ldr r1, .L081493CC
	movs r2, #0x89
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	bl NumberToDigits
	adds r7, r0, #0
	movs r5, #5
	movs r6, #0
	ldr r0, .L081493D0
	mov sb, r0
	movs r1, #0x4a
	mov r8, r1
.L08149376:
	adds r0, r7, r5
	ldrb r0, [r0]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	adds r1, r4, #0
	adds r1, #0x14
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	subs r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r4, #0
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r6, #1
	cmp r6, sl
	blo .L08149376
	movs r0, #5
	ldr r1, .L081493CC
	strh r0, [r1]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081493C8: .4byte gUnknown_081519B4
.L081493CC: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081493D0: .4byte gUnknown_0879CE24

	thumb_func_start sub_081493D4
sub_081493D4: @ 0x081493D4
.L081493D4:
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, .L081493E4
	cmp r6, #0
	bne .L081493EC
	movs r0, #0
	b .L0814940A
	.byte 0x00, 0x00
.L081493E4: .4byte 0x00989680
.L081493E8:
	adds r0, r4, #0
	b .L0814940A
.L081493EC:
	movs r5, #0
.L081493EE:
	adds r0, r6, #0
	adds r1, r4, #0
	bl __udivsi3
	cmp r0, #0
	bne .L081493E8
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	adds r4, r0, #0
	adds r5, #1
	cmp r5, #7
	bls .L081493EE
.L0814940A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_08149410
sub_08149410: @ 0x08149410
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r4, .L08149434
	movs r2, #1
	movs r0, #0
	strh r0, [r5, #0x1c]
	movs r0, #0xca
	lsls r0, r0, #1
	adds r6, r4, r0
	ldr r0, [r6]
	ldr r7, .L08149438
	cmp r0, r7
	bne .L0814943C
	strh r2, [r5, #0x1c]
	b .L08149486
	.byte 0x00, 0x00
.L08149434: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149438: .4byte 0x000F423F
.L0814943C:
	ldr r0, .L08149490
	ldrh r1, [r0]
	movs r0, #1
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	beq .L08149458
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl sub_081493D4
	adds r2, r0, #0
.L08149458:
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	cmp r0, r2
	bhs .L08149466
	adds r2, r0, #0
.L08149466:
	subs r0, r0, r2
	str r0, [r1]
	ldr r0, [r6]
	adds r0, r0, r2
	str r0, [r6]
	cmp r0, r7
	bls .L08149476
	str r7, [r6]
.L08149476:
	ldr r0, [r1]
	cmp r0, #0
	beq .L08149482
	ldr r0, [r6]
	cmp r0, r7
	bne .L08149486
.L08149482:
	mov r1, r8
	strh r1, [r5, #0x1c]
.L08149486:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08149490: .4byte 0x03003964 @ IWRAM+0x3964

	thumb_func_start sub_08149494
sub_08149494: @ 0x08149494
	push {lr}
	ldr r2, .L081494B4
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	str r0, [r1]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	bl sub_080C31FC
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L081494B4: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081494B8
sub_081494B8: @ 0x081494B8
	ldr r0, .L081494C8
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0x1e
	str r1, [r0]
	bx lr
	.byte 0x00, 0x00
.L081494C8: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_081494CC
sub_081494CC: @ 0x081494CC
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r5, .L08149508
	movs r2, #1
	movs r0, #0
	strh r0, [r3, #0x1c]
	ldr r0, .L0814950C
	ldrh r1, [r0]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L081494E8
	movs r2, #3
.L081494E8:
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, r2
	bhs .L081494F6
	adds r2, r0, #0
.L081494F6:
	subs r0, r0, r2
	str r0, [r1]
	cmp r0, #0
	bne .L08149500
	strh r4, [r3, #0x1c]
.L08149500:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08149508: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814950C: .4byte 0x030031D0 @ IWRAM+0x31D0

	thumb_func_start sub_08149510
sub_08149510: @ 0x08149510
.L08149510:
	push {r4, r5, r6, r7, lr}
	ldr r4, .L08149570
	ldr r0, .L08149574
	ldr r1, .L08149578
	bl Task_Create
	movs r0, #0
	strh r0, [r4]
	movs r5, #0
	movs r6, #0
	movs r7, #0x80
	lsls r7, r7, #8
	adds r2, r4, #4
	movs r0, #0x81
	lsls r0, r0, #1
	adds r3, r4, r0
.L08149530:
	strh r6, [r3]
	ldrh r1, [r2]
	adds r0, r7, #0
	ands r0, r1
	strh r0, [r2]
	adds r2, #2
	adds r3, #2
	adds r5, #1
	cmp r5, #0x3f
	bls .L08149530
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, .L0814957C
	movs r0, #0xf0
	strh r0, [r1]
	ldrh r1, [r4, #2]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4, #2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08149570: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149574: .4byte gUnknown_0879D6AC
.L08149578: .4byte 0x0000FFFF
.L0814957C: .4byte 0x03000000 @ IWRAM

	thumb_func_start sub_08149580
sub_08149580: @ 0x08149580
	push {r4, lr}
	ldr r4, .L081495A4
	movs r0, #0xa0
	lsls r0, r0, #1
	movs r1, #0x80
	movs r2, #2
	bl PalFade_FadeRangeToWhite
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r4, r4, r1
	str r0, [r4]
	ldr r1, .L081495A8
	movs r0, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
.L081495A4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081495A8: .4byte 0x03000040 @ IWRAM+0x40

	thumb_func_start sub_081495AC
sub_081495AC: @ 0x081495AC
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, .L081495F4
	ldr r4, .L081495F8
	ldr r0, .L081495FC
	adds r1, r4, #0
	bl LZ77UnCompWram
	adds r4, #0x80
	ldr r2, .L08149600
	movs r3, #0x80
	lsls r3, r3, #1
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	adds r1, r4, #0
	bl Palette_CopyWithEffect
	movs r0, #0xa0
	lsls r0, r0, #1
	movs r1, #0x80
	movs r2, #2
	movs r3, #0x20
	bl PalFade_FadeRangeWithDuration
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r5, r5, r1
	str r0, [r5]
	ldr r1, .L08149604
	movs r0, #0
	strh r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
.L081495F4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L081495F8: .4byte 0x0200AFC8 @ EWRAM+0xAFC8
.L081495FC: .4byte gUnknown_087B59DC
.L08149600: .4byte 0x03002C30 @ IWRAM+0x2C30
.L08149604: .4byte 0x03000040 @ IWRAM+0x40

	thumb_func_start sub_08149608
sub_08149608: @ 0x08149608
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08149624
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl PalFade_IsActive
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08149628
	movs r0, #1
	b .L0814962A
.L08149624: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149628:
	movs r0, #0
.L0814962A:
	strh r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08149634
sub_08149634: @ 0x08149634
	ldr r1, .L0814963C
	movs r0, #0
	strh r0, [r1]
	bx lr
.L0814963C: .4byte 0x03000000 @ IWRAM

	thumb_func_start sub_08149640
sub_08149640: @ 0x08149640
.L08149640:
	push {r4, lr}
	ldr r4, .L08149660
	movs r0, #0xac
	lsls r0, r0, #1
	bl sub_080C51D4
	ldr r0, .L08149664
	ldr r1, .L08149668
	bl Task_Create
	movs r0, #4
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08149660: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149664: .4byte gUnknown_0879DA00
.L08149668: .4byte 0x0000FFFF

	thumb_func_start sub_0814966C
sub_0814966C: @ 0x0814966C
.L0814966C:
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r2, r1, #0x10
	adds r0, r2, #0
	subs r0, #0xa
	cmp r0, #4
	bhi .L081496F4
	lsls r0, r0, #2
	ldr r1, .L08149698
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08149698: .4byte gUnknown_0814969C
	.global gUnknown_0814969C
gUnknown_0814969C:
.L0814969C: @ jump table
	.4byte .L081496D4
	.4byte .L081496B0
	.4byte .L081496D4
	.4byte .L0814970E
	.4byte .L0814970E
.L081496B0:
	ldr r1, .L081496D0
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	movs r0, #1
	b .L08149710
	.byte 0x00, 0x00
.L081496D0: .4byte gUnknown_0879DDAC
.L081496D4:
	ldr r1, .L081496F0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814970E
.L081496F0: .4byte gUnknown_0879CE24
.L081496F4:
	ldr r1, .L08149718
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814970E:
	movs r0, #0
.L08149710:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
.L08149718: .4byte gUnknown_0879CE24

	thumb_func_start sub_0814971C
sub_0814971C: @ 0x0814971C
.L0814971C:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	ldr r0, .L08149884
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	bne .L08149738
	b .L08149A00
.L08149738:
	ldr r0, .L08149888
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08149742
	b .L08149A00
.L08149742:
	movs r2, #0x8c
	mov r8, r2
	movs r6, #0x34
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r2, r0, #1
	ldr r1, .L0814988C
	adds r2, r2, r1
	mov sl, r2
	lsls r0, r0, #2
	ldr r1, .L08149890
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r3, #0
	str r3, [sp, #0xc]
	ldrh r0, [r2]
	cmp r0, #0
	bne .L08149768
	b .L08149A00
.L08149768:
	mov r0, sl
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r0, r1
	lsrs r0, r0, #0xc
	movs r1, #0
	mov r2, r8
	adds r3, r6, #0
	bl sub_0814966C
	adds r0, r4, #0
	movs r2, #0xf0
	lsls r2, r2, #4
	ands r0, r2
	lsrs r0, r0, #8
	mov r2, r8
	adds r2, #8
	lsls r2, r2, #0x10
	movs r1, #0
	lsrs r2, r2, #0x10
	adds r3, r6, #0
	bl sub_0814966C
	adds r0, r4, #0
	movs r3, #0xf0
	ands r0, r3
	lsrs r0, r0, #4
	mov r2, r8
	adds r2, #0x10
	lsls r2, r2, #0x10
	movs r1, #0
	lsrs r2, r2, #0x10
	adds r3, r6, #0
	bl sub_0814966C
	movs r0, #0xf
	ands r4, r0
	mov r2, r8
	adds r2, #0x18
	lsls r2, r2, #0x10
	adds r0, r4, #0
	movs r1, #0
	lsrs r2, r2, #0x10
	adds r3, r6, #0
	bl sub_0814966C
	ldr r0, [sp, #0x10]
	ldr r4, [r0]
	movs r7, #0xf0
	lsls r7, r7, #0x18
	ands r7, r4
	movs r0, #0xb0
	lsls r0, r0, #0x18
	cmp r7, r0
	bne .L081497E2
	movs r0, #0xf0
	lsls r0, r0, #0x14
	ands r0, r4
	lsrs r5, r0, #0x18
.L081497E2:
	movs r1, #0xf0
	lsls r1, r1, #0x14
	mov sb, r1
	mov r2, sb
	ands r2, r4
	mov sb, r2
	movs r0, #0xb0
	lsls r0, r0, #0x14
	cmp sb, r0
	bne .L081497FE
	movs r0, #0xf0
	lsls r0, r0, #0x10
	ands r0, r4
	lsrs r5, r0, #0x14
.L081497FE:
	movs r0, #0xf0
	lsls r0, r0, #0x10
	ands r0, r4
	movs r1, #0xb0
	lsls r1, r1, #0x10
	cmp r0, r1
	bne .L08149814
	movs r0, #0xf0
	lsls r0, r0, #0xc
	ands r0, r4
	lsrs r5, r0, #0x10
.L08149814:
	movs r0, #0xf0
	lsls r0, r0, #0xc
	ands r0, r4
	movs r1, #0xb0
	lsls r1, r1, #0xc
	adds r2, r4, #0
	movs r3, #0xf0
	lsls r3, r3, #8
	ands r2, r3
	cmp r0, r1
	bne .L0814982C
	lsrs r5, r2, #0xc
.L0814982C:
	movs r0, #0xb0
	lsls r0, r0, #8
	adds r3, r4, #0
	movs r1, #0xf0
	lsls r1, r1, #4
	ands r3, r1
	cmp r2, r0
	bne .L0814983E
	lsrs r5, r3, #8
.L0814983E:
	movs r0, #0xb0
	lsls r0, r0, #4
	adds r1, r4, #0
	movs r2, #0xf0
	ands r1, r2
	cmp r3, r0
	bne .L0814984E
	lsrs r5, r1, #4
.L0814984E:
	cmp r1, #0xb0
	bne .L08149858
	adds r5, r4, #0
	movs r3, #0xf
	ands r5, r3
.L08149858:
	lsrs r0, r7, #0x1c
	mov r2, r8
	adds r2, #0x20
	lsls r2, r2, #0x10
	adds r1, r5, #0
	lsrs r2, r2, #0x10
	adds r3, r6, #0
	bl sub_0814966C
	cmp r0, #0
	bne .L08149894
	mov r1, sb
	lsrs r0, r1, #0x18
	mov r2, r8
	adds r2, #0x28
	lsls r2, r2, #0x10
	adds r1, r5, #0
	lsrs r2, r2, #0x10
	adds r3, r6, #0
	bl sub_0814966C
	b .L08149896
.L08149884: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149888: .4byte 0x03000000 @ IWRAM
.L0814988C: .4byte gUnknown_0879DA14
.L08149890: .4byte gUnknown_0879DB48
.L08149894:
	movs r0, #0
.L08149896:
	cmp r0, #0
	bne .L081498B4
	movs r0, #0xf0
	lsls r0, r0, #0x10
	ands r0, r4
	lsrs r0, r0, #0x14
	mov r2, r8
	adds r2, #0x30
	lsls r2, r2, #0x10
	adds r1, r5, #0
	lsrs r2, r2, #0x10
	adds r3, r6, #0
	bl sub_0814966C
	b .L081498B6
.L081498B4:
	movs r0, #0
.L081498B6:
	ldr r1, .L081498CC
	ands r1, r4
	cmp r1, #0
	bne .L081498D4
	str r1, [sp]
	mov r0, r8
	adds r0, #0x38
	str r0, [sp, #4]
	str r6, [sp, #8]
	ldr r0, .L081498D0
	b .L0814998A
.L081498CC: .4byte 0x000FFFFF
.L081498D0: .4byte gUnknown_08151B68
.L081498D4:
	cmp r0, #0
	bne .L081498F2
	movs r0, #0xf0
	lsls r0, r0, #0xc
	ands r0, r4
	lsrs r0, r0, #0x10
	mov r2, r8
	adds r2, #0x38
	lsls r2, r2, #0x10
	adds r1, r5, #0
	lsrs r2, r2, #0x10
	adds r3, r6, #0
	bl sub_0814966C
	b .L081498F4
.L081498F2:
	movs r0, #0
.L081498F4:
	ldr r1, .L0814990C
	ands r1, r4
	cmp r1, #0
	bne .L08149914
	str r1, [sp]
	mov r0, r8
	adds r0, #0x40
	str r0, [sp, #4]
	str r6, [sp, #8]
	ldr r0, .L08149910
	b .L0814998A
	.byte 0x00, 0x00
.L0814990C: .4byte 0x0000FFFF
.L08149910: .4byte gUnknown_08151B50
.L08149914:
	cmp r0, #0
	bne .L08149934
	adds r0, r4, #0
	movs r2, #0xf0
	lsls r2, r2, #8
	ands r0, r2
	lsrs r0, r0, #0xc
	mov r2, r8
	adds r2, #0x40
	lsls r2, r2, #0x10
	adds r1, r5, #0
	lsrs r2, r2, #0x10
	adds r3, r6, #0
	bl sub_0814966C
	b .L08149936
.L08149934:
	movs r0, #0
.L08149936:
	ldr r1, .L0814994C
	ands r1, r4
	cmp r1, #0
	bne .L08149954
	str r1, [sp]
	mov r0, r8
	adds r0, #0x48
	str r0, [sp, #4]
	str r6, [sp, #8]
	ldr r0, .L08149950
	b .L0814998A
.L0814994C: .4byte 0x00000FFF
.L08149950: .4byte gUnknown_08151B40
.L08149954:
	cmp r0, #0
	bne .L08149974
	adds r0, r4, #0
	movs r3, #0xf0
	lsls r3, r3, #4
	ands r0, r3
	lsrs r0, r0, #8
	mov r2, r8
	adds r2, #0x48
	lsls r2, r2, #0x10
	adds r1, r5, #0
	lsrs r2, r2, #0x10
	adds r3, r6, #0
	bl sub_0814966C
	b .L08149976
.L08149974:
	movs r0, #0
.L08149976:
	movs r1, #0xff
	ands r1, r4
	cmp r1, #0
	bne .L0814999C
	str r1, [sp]
	mov r0, r8
	adds r0, #0x50
	str r0, [sp, #4]
	str r6, [sp, #8]
	ldr r0, .L08149998
.L0814998A:
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L081499D6
	.byte 0x00, 0x00
.L08149998: .4byte gUnknown_08151B28
.L0814999C:
	cmp r0, #0
	bne .L081499BA
	adds r0, r4, #0
	movs r1, #0xf0
	ands r0, r1
	lsrs r0, r0, #4
	mov r2, r8
	adds r2, #0x50
	lsls r2, r2, #0x10
	adds r1, r5, #0
	lsrs r2, r2, #0x10
	adds r3, r6, #0
	bl sub_0814966C
	b .L081499BC
.L081499BA:
	movs r0, #0
.L081499BC:
	cmp r0, #0
	bne .L081499D6
	movs r2, #0xf
	ands r4, r2
	mov r2, r8
	adds r2, #0x58
	lsls r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	lsrs r2, r2, #0x10
	adds r3, r6, #0
	bl sub_0814966C
.L081499D6:
	movs r3, #2
	add sl, r3
	ldr r0, [sp, #0x10]
	adds r0, #4
	str r0, [sp, #0x10]
	adds r0, r6, #0
	adds r0, #0xb
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, [sp, #0xc]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	cmp r0, #8
	bhi .L08149A00
	mov r1, sl
	ldrh r0, [r1]
	cmp r0, #0
	beq .L08149A00
	b .L08149768
.L08149A00:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08149A10
sub_08149A10: @ 0x08149A10
.L08149A10:
	push {r4, r5, r6, r7, lr}
	ldr r0, .L08149A48
	movs r4, #0
	adds r7, r0, #4
	movs r1, #0x80
	lsls r1, r1, #8
	mov ip, r1
	movs r6, #0
	movs r1, #0x81
	lsls r1, r1, #1
	adds r5, r0, r1
.L08149A26:
	lsls r1, r4, #1
	adds r3, r7, r1
	ldrh r2, [r3]
	mov r0, ip
	ands r0, r2
	strh r0, [r3]
	adds r1, r5, r1
	strh r6, [r1]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x3f
	bls .L08149A26
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L08149A48: .4byte 0x0203A454 @ EWRAM+0x3A454

	thumb_func_start sub_08149A4C
sub_08149A4C: @ 0x08149A4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, .L08149AB0
	mov r8, r0
	bl sub_08149A10
	movs r0, #0
.L08149A60:
	movs r5, #0
	movs r1, #0
	lsls r3, r0, #1
	mov r2, r8
	adds r2, #4
	adds r4, r0, #1
	mov sb, r4
	lsrs r7, r0, #3
	mov sl, r7
	movs r6, #0xd0
	lsls r6, r6, #1
	add r6, r8
	movs r4, #7
	ands r4, r0
	movs r0, #1
	mov ip, r0
.L08149A80:
	lsls r0, r1, #3
	add r0, sl
	adds r0, r6, r0
	ldrb r0, [r0]
	asrs r0, r4
	mov r7, ip
	ands r0, r7
	cmp r0, #0
	beq .L08149A98
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L08149A98:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xf
	bls .L08149A80
	cmp r5, #8
	bhi .L08149B14
	lsls r0, r5, #2
	ldr r1, .L08149AB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08149AB0: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149AB4: .4byte gUnknown_08149AB8
	.global gUnknown_08149AB8
gUnknown_08149AB8:
.L08149AB8: @ jump table
	.4byte .L08149ADC
	.4byte .L08149AE4
	.4byte .L08149AEC
	.4byte .L08149AF4
	.4byte .L08149AF4
	.4byte .L08149AF4
	.4byte .L08149AFC
	.4byte .L08149B04
	.4byte .L08149B0C
.L08149ADC:
	adds r2, r2, r3
	ldrh r1, [r2]
	movs r0, #1
	b .L08149B1A
.L08149AE4:
	adds r2, r2, r3
	ldrh r1, [r2]
	movs r0, #2
	b .L08149B1A
.L08149AEC:
	adds r2, r2, r3
	ldrh r1, [r2]
	movs r0, #3
	b .L08149B1A
.L08149AF4:
	adds r2, r2, r3
	ldrh r1, [r2]
	movs r0, #4
	b .L08149B1A
.L08149AFC:
	adds r2, r2, r3
	ldrh r1, [r2]
	movs r0, #5
	b .L08149B1A
.L08149B04:
	adds r2, r2, r3
	ldrh r1, [r2]
	movs r0, #6
	b .L08149B1A
.L08149B0C:
	adds r2, r2, r3
	ldrh r1, [r2]
	movs r0, #7
	b .L08149B1A
.L08149B14:
	adds r2, r2, r3
	ldrh r1, [r2]
	movs r0, #8
.L08149B1A:
	orrs r0, r1
	strh r0, [r2]
	mov r1, sb
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls .L08149A60
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_08149B38
sub_08149B38: @ 0x08149B38
.L08149B38:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, .L08149B80
	mov ip, r0
	movs r0, #0x88
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
	movs r3, #0
	movs r1, #0x81
	lsls r1, r1, #1
	add r1, ip
	mov r8, r1
	lsls r4, r0, #3
	movs r6, #0xd0
	lsls r6, r6, #1
	add r6, ip
	movs r5, #7
	movs r7, #1
.L08149B60:
	lsls r0, r3, #1
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08149B84
	lsrs r2, r3, #3
	adds r2, r2, r4
	adds r2, r6, r2
	adds r1, r3, #0
	ands r1, r5
	adds r0, r7, #0
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	b .L08149B96
	.byte 0x00, 0x00
.L08149B80: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149B84:
	lsrs r2, r3, #3
	adds r2, r2, r4
	adds r2, r6, r2
	adds r0, r3, #0
	ands r0, r5
	adds r1, r7, #0
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
.L08149B96:
	strb r0, [r2]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x3f
	bls .L08149B60
	movs r0, #0x88
	lsls r0, r0, #2
	add r0, ip
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #0xf
	ands r1, r2
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08149BBC
sub_08149BBC: @ 0x08149BBC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r5, .L08149C1C
	movs r6, #0
	str r6, [sp]
	ldr r2, .L08149C20
	mov r0, sp
	adds r1, r5, #0
	bl CpuSet
	ldr r1, .L08149C24
	ldr r2, .L08149C28
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, .L08149C2C
	strh r6, [r0]
	ldr r0, .L08149C30
	strh r6, [r0]
	movs r4, #1
	movs r7, #1
	strh r7, [r5]
	bl sub_080C31F0
	str r0, [r5, #0x28]
	movs r0, #8
	strb r0, [r5, #0xf]
	strb r4, [r5, #0x18]
	strb r4, [r5, #0x16]
	adds r1, r5, #0
	adds r1, #0x40
	movs r0, #0xaa
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x40
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x50
	strh r0, [r1]
	ldr r0, .L08149C34
	ldr r0, [r0]
	cmp r0, #0x26
	beq .L08149C50
	cmp r0, #0x26
	bhi .L08149C38
	cmp r0, #3
	beq .L08149C42
	b .L08149C70
.L08149C1C: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149C20: .4byte 0x05000200 @ PLTT+0x200
.L08149C24: .4byte 0x04000008 @ REG_BG0CNT
.L08149C28: .4byte 0x00004008
.L08149C2C: .4byte 0x03000002 @ IWRAM+0x2
.L08149C30: .4byte 0x03000040 @ IWRAM+0x40
.L08149C34: .4byte 0x03004614 @ IWRAM+0x4614
.L08149C38:
	cmp r0, #0x30
	beq .L08149C5C
	cmp r0, #0x40
	beq .L08149C68
	b .L08149C70
.L08149C42:
	ldr r1, .L08149C4C
	adds r0, r5, r1
	strh r6, [r0]
	b .L08149C70
	.byte 0x00, 0x00
.L08149C4C: .4byte 0x00000262
.L08149C50:
	ldr r2, .L08149C58
	adds r0, r5, r2
	strh r7, [r0]
	b .L08149C70
.L08149C58: .4byte 0x00000262
.L08149C5C:
	ldr r0, .L08149C64
	adds r1, r5, r0
	movs r0, #2
	b .L08149C6E
.L08149C64: .4byte 0x00000262
.L08149C68:
	ldr r2, .L08149C78
	adds r1, r5, r2
	movs r0, #3
.L08149C6E:
	strh r0, [r1]
.L08149C70:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L08149C78: .4byte 0x00000262

	thumb_func_start sub_08149C7C
sub_08149C7C: @ 0x08149C7C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r6, .L08149CC8
	ldrh r0, [r6]
	cmp r0, #1
	bne .L08149C94
	ldr r0, .L08149CCC
	ldr r1, .L08149CD0
	bl Task_Create
	movs r0, #0
	strh r0, [r6]
.L08149C94:
	ldrb r5, [r6, #0x1b]
	cmp r5, #0
	bne .L08149CDC
	ldr r0, .L08149CD4
	str r5, [sp]
	movs r1, #0xbb
	str r1, [sp, #4]
	movs r4, #5
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L08149CD8
	str r5, [sp]
	movs r1, #9
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L08149D08
	.byte 0x00, 0x00
.L08149CC8: .4byte 0x0203A454 @ EWRAM+0x3A454
.L08149CCC: .4byte gUnknown_0879E354
.L08149CD0: .4byte 0x0000FFFF
.L08149CD4: .4byte gUnknown_0814F824
.L08149CD8: .4byte gUnknown_0814F7F4
.L08149CDC:
	ldr r0, .L08149D70
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
	ldr r0, .L08149D74
	str r5, [sp]
	movs r1, #9
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08149D08:
	ldr r0, [r6, #0x2c]
	movs r1, #0x30
	movs r2, #0x21
	movs r3, #0
	bl sub_0814A26C
	ldr r0, [r6, #0x28]
	movs r1, #0xe3
	movs r2, #0x21
	movs r3, #0
	bl sub_0814A26C
	ldr r1, .L08149D78
	ldrh r0, [r6, #0x12]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	str r1, [sp]
	movs r1, #0x4b
	str r1, [sp, #4]
	movs r1, #0x1a
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrb r0, [r6, #0x18]
	cmp r0, #1
	beq .L08149D4C
	ldrb r0, [r6, #0x19]
	cmp r0, #1
	bne .L08149D50
.L08149D4C:
	bl sub_0814A1FC
.L08149D50:
	ldrb r0, [r6, #0x18]
	cmp r0, #2
	bne .L08149D80
	ldr r0, .L08149D7C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x82
	str r1, [sp, #4]
	movs r1, #0x19
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L08149D9E
.L08149D70: .4byte gUnknown_0814F888
.L08149D74: .4byte gUnknown_0814F858
.L08149D78: .4byte gUnknown_0879DDFC
.L08149D7C: .4byte gUnknown_0814F790
.L08149D80:
	ldrb r0, [r6, #0x19]
	cmp r0, #2
	bne .L08149D9E
	ldr r0, .L08149E38
	movs r1, #0
	str r1, [sp]
	movs r1, #0x82
	str r1, [sp, #4]
	movs r1, #0x38
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08149D9E:
	adds r0, r6, #0
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08149DC0
	ldr r0, .L08149E3C
	movs r1, #0
	str r1, [sp]
	movs r1, #0xba
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08149DC0:
	adds r0, r6, #0
	adds r0, #0x27
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #1
	bne .L08149DE4
	ldr r0, .L08149E3C
	movs r1, #0
	str r1, [sp]
	movs r1, #7
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L08149DE4:
	bl sub_0814A8B0
	bl sub_0814AA04
	movs r1, #0x99
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08149EC6
	ldrb r2, [r6, #4]
	cmp r2, #0
	bne .L08149EC6
	ldr r0, .L08149E40
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08149E64
	strh r2, [r6, #0xc]
	adds r0, r6, #0
	adds r0, #0x5c
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	ldrb r0, [r6, #0x1b]
	cmp r0, #0
	bne .L08149E44
	ldr r1, [r6, #0x28]
	cmp r1, #9
	bls .L08149E44
	movs r0, #4
	strb r0, [r6, #4]
	adds r0, r1, #0
	subs r0, #0xa
	str r0, [r6, #0x28]
	movs r0, #0xa
	str r0, [r6, #0x30]
	str r0, [r6, #0x2c]
	b .L08149E4E
	.byte 0x00, 0x00
.L08149E38: .4byte gUnknown_0814F7A8
.L08149E3C: .4byte gUnknown_0814F958
.L08149E40: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08149E44:
	ldrb r0, [r6, #0x1b]
	cmp r0, #1
	bne .L08149E4E
	movs r0, #4
	strb r0, [r6, #4]
.L08149E4E:
	ldrb r0, [r6, #0x16]
	cmp r0, #1
	bne .L08149E5A
	movs r0, #2
	strb r0, [r6, #0x18]
	b .L08149E64
.L08149E5A:
	ldrb r0, [r6, #0x17]
	cmp r0, #1
	bne .L08149E64
	movs r0, #2
	strb r0, [r6, #0x19]
.L08149E64:
	ldr r0, .L08149E84
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08149E8C
	ldrb r0, [r6, #0x1b]
	cmp r0, #0
	bne .L08149E88
	movs r0, #0xac
	lsls r0, r0, #1
	bl sub_080C51D4
	movs r0, #0xa
	b .L08149E8A
.L08149E84: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08149E88:
	movs r0, #9
.L08149E8A:
	strb r0, [r6, #4]
.L08149E8C:
	ldr r2, .L08149ED8
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L08149EAA
	ldrb r3, [r6, #0x16]
	cmp r3, #0
	bne .L08149EAA
	movs r0, #1
	strb r0, [r6, #0x16]
	movs r0, #2
	strb r0, [r6, #0x18]
	strb r3, [r6, #0x17]
	strb r3, [r6, #0x19]
.L08149EAA:
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L08149EC6
	ldrb r1, [r6, #0x17]
	cmp r1, #0
	bne .L08149EC6
	movs r0, #1
	strb r0, [r6, #0x17]
	movs r0, #2
	strb r0, [r6, #0x19]
	strb r1, [r6, #0x16]
	strb r1, [r6, #0x18]
.L08149EC6:
	ldrb r0, [r6, #4]
	cmp r0, #0xa
	bls .L08149ECE
	b .L0814A1F2
.L08149ECE:
	lsls r0, r0, #2
	ldr r1, .L08149EDC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
.L08149ED8: .4byte 0x030031B8 @ IWRAM+0x31B8
.L08149EDC: .4byte gUnknown_08149EE0
	.global gUnknown_08149EE0
gUnknown_08149EE0:
.L08149EE0: @ jump table
	.4byte .L08149F0C
	.4byte .L0814A088
	.4byte .L0814A116
	.4byte .L0814A184
	.4byte .L08149FC8
	.4byte .L08149FDE
	.4byte .L0814A054
	.4byte .L08149FF8
	.4byte .L0814A17E
	.4byte .L0814A18A
	.4byte .L0814A1A6
.L08149F0C:
	ldrb r4, [r6, #0x1b]
	cmp r4, #0
	bne .L08149F4C
	ldrh r0, [r6, #0xa]
	cmp r0, #0x14
	bls .L08149F72
	ldr r0, .L08149F48
	str r4, [sp]
	movs r1, #0xbb
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r6, #0xa]
	cmp r0, #0x28
	bls .L08149F72
	strh r4, [r6, #0xa]
	movs r0, #0x99
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne .L08149F72
	movs r0, #1
	strb r0, [r1]
	b .L08149F72
.L08149F48: .4byte gUnknown_0814F83C
.L08149F4C:
	ldrh r0, [r6, #0xa]
	cmp r0, #0x14
	bls .L08149F72
	ldr r0, .L08149FBC
	movs r4, #0
	str r4, [sp]
	movs r1, #0xbb
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r6, #0xa]
	cmp r0, #0x28
	bls .L08149F72
	strh r4, [r6, #0xa]
.L08149F72:
	ldrh r0, [r6, #0x14]
	cmp r0, #0xa
	bls .L08149FAC
	ldr r0, .L08149FC0
	movs r5, #0
	str r5, [sp]
	movs r4, #0x92
	str r4, [sp, #4]
	movs r1, #0x25
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldr r0, .L08149FC4
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #0x31
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	ldrh r0, [r6, #0x14]
	cmp r0, #0x14
	bls .L08149FAC
	strh r5, [r6, #0x14]
.L08149FAC:
	ldrh r0, [r6, #0xa]
	adds r0, #1
	strh r0, [r6, #0xa]
	ldrh r0, [r6, #0x14]
	adds r0, #1
	strh r0, [r6, #0x14]
	b .L0814A1F2
	.byte 0x00, 0x00
.L08149FBC: .4byte gUnknown_0814F8A0
.L08149FC0: .4byte gUnknown_0814F768
.L08149FC4: .4byte gUnknown_0814F778
.L08149FC8:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08149FD4
	bl sub_0814A684
	b .L0814A1F2
.L08149FD4:
	movs r1, #0
	movs r0, #1
	strb r0, [r6, #4]
	strh r1, [r6, #0x22]
	b .L0814A1F2
.L08149FDE:
	adds r0, r6, #0
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08149FEE
	bl sub_0814A568
	b .L0814A1F2
.L08149FEE:
	movs r1, #0
	movs r0, #8
	strb r0, [r6, #4]
	strh r1, [r6, #0x1e]
	b .L0814A1F2
.L08149FF8:
	ldrb r0, [r6, #0x1a]
	adds r1, r0, #0
	adds r2, r0, #0
	cmp r1, #0x63
	beq .L0814A006
	cmp r1, #1
	bne .L0814A04E
.L0814A006:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0814A016
	bl sub_0814A684
	bl sub_0814A5F0
	b .L0814A1F2
.L0814A016:
	movs r0, #0
	movs r1, #6
	strb r1, [r6, #4]
	strh r0, [r6, #0x22]
	ldrb r0, [r6, #0x1b]
	cmp r0, #0
	bne .L0814A028
	movs r0, #1
	b .L0814A02A
.L0814A028:
	movs r0, #0
.L0814A02A:
	strb r0, [r6, #0x1b]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x63
	beq .L0814A036
	b .L0814A1F2
.L0814A036:
	movs r1, #0
	adds r2, r6, #0
	adds r2, #0x4a
	movs r3, #0
.L0814A03E:
	adds r0, r2, r1
	strb r3, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #9
	bls .L0814A03E
	b .L0814A1F2
.L0814A04E:
	movs r0, #6
	strb r0, [r6, #4]
	b .L0814A1F2
.L0814A054:
	ldrb r1, [r6, #0x1a]
	cmp r1, #0x63
	beq .L0814A05E
	cmp r1, #1
	bne .L0814A082
.L0814A05E:
	adds r0, r6, #0
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0814A072
	bl sub_0814A568
	bl sub_0814A4DC
	b .L0814A1F2
.L0814A072:
	movs r0, #0
	strb r0, [r6, #4]
	strh r0, [r6, #0x1e]
	cmp r1, #1
	bne .L0814A07E
	b .L0814A1F2
.L0814A07E:
	strb r0, [r6, #0x1a]
	b .L0814A1F2
.L0814A082:
	movs r0, #0
	strb r0, [r6, #4]
	b .L0814A1F2
.L0814A088:
	ldrb r4, [r6, #0x10]
	cmp r4, #1
	beq .L0814A0BE
	cmp r4, #1
	bgt .L0814A098
	cmp r4, #0
	beq .L0814A09E
	b .L0814A1F2
.L0814A098:
	cmp r4, #2
	beq .L0814A0DA
	b .L0814A1F2
.L0814A09E:
	ldrh r0, [r6, #6]
	cmp r0, #5
	bhi .L0814A0B8
	ldrb r0, [r6, #0xe]
	ldrb r1, [r6, #0xf]
	cmp r0, r1
	bls .L0814A0FE
	bl sub_0814A4AC
	strb r4, [r6, #0xe]
	ldrb r0, [r6, #0xf]
	subs r0, #1
	b .L0814A0F4
.L0814A0B8:
	movs r0, #1
	strb r0, [r6, #0x10]
	b .L0814A1F2
.L0814A0BE:
	ldrh r0, [r6, #6]
	cmp r0, #0x50
	bhi .L0814A0D4
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	bls .L0814A0FE
	bl sub_0814A4AC
	movs r0, #0
	strb r0, [r6, #0xe]
	b .L0814A0F6
.L0814A0D4:
	movs r0, #2
	strb r0, [r6, #0x10]
	b .L0814A1F2
.L0814A0DA:
	ldrh r0, [r6, #6]
	cmp r0, #0x5a
	bhi .L0814A106
	ldrb r0, [r6, #0xe]
	ldrb r1, [r6, #0xf]
	cmp r0, r1
	bls .L0814A0FE
	bl sub_0814A4AC
	movs r0, #0
	strb r0, [r6, #0xe]
	ldrb r0, [r6, #0xf]
	adds r0, #1
.L0814A0F4:
	strb r0, [r6, #0xf]
.L0814A0F6:
	movs r0, #0xad
	lsls r0, r0, #1
	bl sub_080C51D4
.L0814A0FE:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b .L0814A1F2
.L0814A106:
	bl sub_0814AC48
	movs r1, #0
	movs r0, #8
	strb r0, [r6, #0xf]
	strh r1, [r6, #6]
	strb r4, [r6, #4]
	b .L0814A1F2
.L0814A116:
	movs r0, #0
	strb r0, [r6, #0x10]
	movs r0, #5
	strb r0, [r6, #4]
	ldrh r0, [r6, #0x12]
	cmp r0, #4
	bls .L0814A14A
	ldrb r0, [r6, #0x16]
	adds r1, r0, #0
	cmp r1, #1
	bne .L0814A13A
	ldrb r0, [r6, #0x1a]
	adds r0, #1
	strb r0, [r6, #0x1a]
	ldr r0, [r6, #0x30]
	lsls r0, r0, #1
	str r0, [r6, #0x30]
	b .L0814A16A
.L0814A13A:
	ldrb r0, [r6, #0x1b]
	cmp r0, #0
	bne .L0814A144
	strb r0, [r6, #0x1a]
	b .L0814A16A
.L0814A144:
	movs r0, #0x63
	strb r0, [r6, #0x1a]
	b .L0814A16A
.L0814A14A:
	ldrb r0, [r6, #0x17]
	cmp r0, #1
	bne .L0814A15E
	ldrb r0, [r6, #0x1a]
	adds r0, #1
	strb r0, [r6, #0x1a]
	ldr r0, [r6, #0x30]
	lsls r0, r0, #1
	str r0, [r6, #0x30]
	b .L0814A168
.L0814A15E:
	ldrb r0, [r6, #0x1b]
	cmp r0, #0
	beq .L0814A166
	movs r0, #0x63
.L0814A166:
	strb r0, [r6, #0x1a]
.L0814A168:
	ldrb r1, [r6, #0x16]
.L0814A16A:
	adds r0, r1, #0
	cmp r0, #1
	bne .L0814A174
	strb r0, [r6, #0x18]
	b .L0814A1F2
.L0814A174:
	ldrb r0, [r6, #0x17]
	cmp r0, #1
	bne .L0814A1F2
	strb r0, [r6, #0x19]
	b .L0814A1F2
.L0814A17E:
	bl sub_0814A718
	b .L0814A1F2
.L0814A184:
	bl sub_0814A3A8
	b .L0814A1F2
.L0814A18A:
	ldrh r0, [r6, #0xc]
	cmp r0, #5
	bhi .L0814A1A0
	ldrh r0, [r6, #0xa]
	cmp r0, #3
	bls .L0814A1CA
	ldr r0, .L0814A19C
	b .L0814A1B4
	.byte 0x00, 0x00
.L0814A19C: .4byte gUnknown_0814F870
.L0814A1A0:
	bl sub_0814A414
	b .L0814A1F2
.L0814A1A6:
	ldrh r0, [r6, #0xc]
	cmp r0, #5
	bhi .L0814A1E8
	ldrh r0, [r6, #0xa]
	cmp r0, #3
	bls .L0814A1CA
	ldr r0, .L0814A1E4
.L0814A1B4:
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
.L0814A1CA:
	ldrh r0, [r6, #0xa]
	cmp r0, #6
	bls .L0814A1DA
	movs r0, #0
	strh r0, [r6, #0xa]
	ldrh r0, [r6, #0xc]
	adds r0, #1
	strh r0, [r6, #0xc]
.L0814A1DA:
	ldrh r0, [r6, #0xa]
	adds r0, #1
	strh r0, [r6, #0xa]
	b .L0814A1F2
	.byte 0x00, 0x00
.L0814A1E4: .4byte gUnknown_0814F80C
.L0814A1E8:
	ldr r0, [r6, #0x28]
	bl sub_080C31FC
	bl sub_080BE4C4
.L0814A1F2:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00

	thumb_func_start sub_0814A1FC
sub_0814A1FC: @ 0x0814A1FC
.L0814A1FC:
	push {r4, lr}
	sub sp, #0xc
	ldr r4, .L0814A228
	ldrh r0, [r4, #8]
	cmp r0, #0x14
	bls .L0814A258
	ldrb r0, [r4, #0x18]
	cmp r0, #1
	bne .L0814A230
	ldr r0, .L0814A22C
	movs r1, #0
	str r1, [sp]
	movs r1, #0x82
	str r1, [sp, #4]
	movs r1, #0x19
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
	b .L0814A24E
.L0814A228: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814A22C: .4byte gUnknown_0814F790
.L0814A230:
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bne .L0814A24E
	ldr r0, .L0814A268
	movs r1, #0
	str r1, [sp]
	movs r1, #0x82
	str r1, [sp, #4]
	movs r1, #0x38
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Sprite_Draw
.L0814A24E:
	ldrh r0, [r4, #8]
	cmp r0, #0x28
	bls .L0814A258
	movs r0, #0
	strh r0, [r4, #8]
.L0814A258:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.L0814A268: .4byte gUnknown_0814F7A8

	thumb_func_start sub_0814A26C
sub_0814A26C: @ 0x0814A26C
.L0814A26C:
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r2, #0
	adds r5, r3, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	bl NumberToDigits
	mov r8, r0
	ldr r0, .L0814A368
	mov sb, r0
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	movs r6, #0
	str r6, [sp]
	str r7, [sp, #4]
	movs r1, #0xff
	ands r4, r1
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #1]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #2]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #3]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #4]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x20
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	mov r1, r8
	ldrb r0, [r1, #5]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r6, [sp]
	adds r1, r7, #0
	subs r1, #0x28
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Sprite_Draw
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L0814A368: .4byte gUnknown_0879DDD4

	thumb_func_start sub_0814A36C
sub_0814A36C: @ 0x0814A36C
.L0814A36C:
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, .L0814A37C
	cmp r6, #0
	bne .L0814A384
	movs r0, #0
	b .L0814A3A2
	.byte 0x00, 0x00
.L0814A37C: .4byte 0x00002710
.L0814A380:
	adds r0, r4, #0
	b .L0814A3A2
.L0814A384:
	movs r5, #0
.L0814A386:
	adds r0, r6, #0
	adds r1, r4, #0
	bl __udivsi3
	cmp r0, #0
	bne .L0814A380
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	adds r4, r0, #0
	adds r5, #1
	cmp r5, #4
	bls .L0814A386
.L0814A3A2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_0814A3A8
sub_0814A3A8: @ 0x0814A3A8
.L0814A3A8:
	push {r4, lr}
	ldr r4, .L0814A3D4
	ldr r0, .L0814A3D8
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L0814A40C
	ldr r0, .L0814A3DC
	bl sub_080C51D4
	ldr r0, .L0814A3E0
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0814A3E4
	ldr r0, [r4, #0x2c]
	bl sub_0814A36C
	b .L0814A3E6
	.byte 0x00, 0x00
.L0814A3D4: .4byte 0x0203A454 @ EWRAM+0x3A454
.L0814A3D8: .4byte 0x030031BC @ IWRAM+0x31BC
.L0814A3DC: .4byte 0x00000159
.L0814A3E0: .4byte 0x03003964 @ IWRAM+0x3964
.L0814A3E4:
	movs r0, #5
.L0814A3E6:
	str r0, [r4, #0x38]
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x38]
	adds r0, r0, r1
	str r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	cmp r0, r1
	blt .L0814A40C
	str r1, [r4, #0x2c]
	ldr r0, [r4, #0x28]
	str r0, [r4, #0x34]
	movs r0, #0xa0
	lsls r0, r0, #6
	cmp r1, r0
	bne .L0814A408
	movs r0, #9
	b .L0814A40A
.L0814A408:
	movs r0, #7
.L0814A40A:
	strb r0, [r4, #4]
.L0814A40C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
