	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

	thumb_func_start sub_080AE574
sub_080AE574: @ 0x080AE574
.L080AE574:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	str r1, [sp, #4]
	ldr r0, .L080AE5B4
	ldrh r7, [r0, #0x12]
	ldrh r6, [r0, #0x14]
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080AE5B8
	mov r0, sp
	str r0, [r1]
	ldr r0, .L080AE5BC
	str r0, [r1, #4]
	ldr r0, .L080AE5C0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r1, r8
	cmp r1, #1
	beq .L080AE5CE
	cmp r1, #1
	blo .L080AE5C4
	cmp r1, #2
	beq .L080AE5D8
	cmp r1, #3
	beq .L080AE5E2
	b .L080AE5EE
	.byte 0x00, 0x00
.L080AE5B4: .4byte 0x03004550 @ IWRAM+0x4550
.L080AE5B8: .4byte 0x040000D4 @ REG_DMA3SAD
.L080AE5BC: .4byte 0x0200AB08 @ EWRAM+0xAB08
.L080AE5C0: .4byte 0x850000F3
.L080AE5C4:
	subs r0, r7, #4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	subs r0, r6, #5
	b .L080AE5EA
.L080AE5CE:
	adds r0, r7, #5
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	subs r0, r6, #4
	b .L080AE5EA
.L080AE5D8:
	adds r0, r7, #4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r6, #5
	b .L080AE5EA
.L080AE5E2:
	subs r0, r7, #5
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r6, #4
.L080AE5EA:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L080AE5EE:
	movs r5, #0
	cmp r5, #9
	bhs .L080AE674
.L080AE5F4:
	movs r4, #0
	adds r2, r5, #1
	str r2, [sp, #8]
	cmp r4, #9
	bhs .L080AE66A
	adds r0, r6, r5
	lsls r0, r0, #0x10
	mov sl, r0
	subs r0, r7, r5
	lsls r0, r0, #0x10
	mov sb, r0
.L080AE60A:
	mov r3, r8
	cmp r3, #1
	beq .L080AE62A
	cmp r3, #1
	blo .L080AE61E
	cmp r3, #2
	beq .L080AE636
	cmp r3, #3
	beq .L080AE64C
	b .L080AE660
.L080AE61E:
	adds r0, r7, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, sl
	lsrs r1, r2, #0x10
	b .L080AE642
.L080AE62A:
	adds r1, r6, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, sb
	lsrs r0, r3, #0x10
	b .L080AE642
.L080AE636:
	subs r0, r7, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r6, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
.L080AE642:
	adds r2, r4, #0
	adds r3, r5, #0
	bl View_FillCell
	b .L080AE660
.L080AE64C:
	adds r0, r7, r5
	lsls r0, r0, #0x10
	subs r1, r6, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsrs r0, r0, #0x10
	adds r2, r4, #0
	adds r3, r5, #0
	bl View_FillCell
.L080AE660:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #9
	blo .L080AE60A
.L080AE66A:
	ldr r1, [sp, #8]
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #9
	blo .L080AE5F4
.L080AE674:
	ldr r2, [sp, #4]
	cmp r2, #0
	beq .L080AE67C
	b .L080AECB0
.L080AE67C:
	bl sub_080ADF40
	cmp r0, #0
	beq .L080AE686
	b .L080AECB0
.L080AE686:
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE6A2
	ldr r2, .L080AE9B8
	movs r0, #3
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE6F8
.L080AE6A2:
	ldr r4, .L080AE9B8
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE6C0
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE6F8
.L080AE6C0:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE6DC
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE6F8
.L080AE6DC:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE70A
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE70A
.L080AE6F8:
	ldr r2, .L080AE9BC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r1, #0
	strh r1, [r0]
	subs r3, #0x68
	adds r0, r2, r3
	strh r1, [r0]
.L080AE70A:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE726
	ldr r2, .L080AE9B8
	movs r0, #1
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE77A
.L080AE726:
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE742
	ldr r2, .L080AE9B8
	movs r0, #1
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE77A
.L080AE742:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE75E
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE77A
.L080AE75E:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE78E
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE78E
.L080AE77A:
	ldr r2, .L080AE9BC
	movs r1, #0xf8
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
.L080AE78E:
	ldr r4, .L080AE9B8
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE7AC
	ldr r2, .L080AE9C0
	movs r0, #3
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE800
.L080AE7AC:
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE7C8
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE800
.L080AE7C8:
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE7E4
	movs r0, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE800
.L080AE7E4:
	movs r0, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE814
	ldr r2, .L080AE9C0
	movs r0, #3
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE814
.L080AE800:
	ldr r2, .L080AE9BC
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
.L080AE814:
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE830
	ldr r2, .L080AE9B8
	movs r0, #3
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE8A2
.L080AE830:
	ldr r4, .L080AE9B8
	movs r0, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE84E
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE8A2
.L080AE84E:
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE86A
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE8A2
.L080AE86A:
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE886
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE8A2
.L080AE886:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE8B2
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE8B2
.L080AE8A2:
	ldr r0, .L080AE9BC
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	adds r0, #0xf8
	strh r2, [r0]
.L080AE8B2:
	ldr r4, .L080AE9B8
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE8D0
	ldr r2, .L080AE9C0
	movs r0, #1
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE924
.L080AE8D0:
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE8EC
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE924
.L080AE8EC:
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE908
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE924
.L080AE908:
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE936
	ldr r2, .L080AE9C0
	movs r0, #1
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE936
.L080AE924:
	ldr r2, .L080AE9BC
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r1, #0
	strh r1, [r0]
	subs r3, #0x68
	adds r0, r2, r3
	strh r1, [r0]
.L080AE936:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE952
	ldr r2, .L080AE9B8
	movs r0, #1
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE9D4
.L080AE952:
	ldr r4, .L080AE9B8
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE970
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE9D4
.L080AE970:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE98C
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE9D4
.L080AE98C:
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE9A8
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AE9D4
.L080AE9A8:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	b .L080AE9C4
	.byte 0x00, 0x00
.L080AE9B8: .4byte 0x0000FFFF
.L080AE9BC: .4byte 0x0200AB08 @ EWRAM+0xAB08
.L080AE9C0: .4byte 0x0000FFFE
.L080AE9C4:
	beq .L080AE9E8
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AE9E8
.L080AE9D4:
	ldr r2, .L080AECC0
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
.L080AE9E8:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEA04
	ldr r1, .L080AECC4
	movs r0, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AEA3E
.L080AEA04:
	ldr r4, .L080AECC4
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEA22
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AEA3E
.L080AEA22:
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEA52
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEA52
.L080AEA3E:
	ldr r1, .L080AECC0
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
.L080AEA52:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEA6E
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AEAA6
.L080AEA6E:
	movs r0, #0
	movs r1, #1
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEA8A
	ldr r2, .L080AECC4
	movs r0, #1
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AEAA6
.L080AEA8A:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEABA
	ldr r2, .L080AECC4
	movs r0, #1
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEABA
.L080AEAA6:
	ldr r1, .L080AECC0
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r0, #0
	strh r0, [r2]
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
.L080AEABA:
	ldr r4, .L080AECC4
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEAD8
	movs r0, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AEB1E
.L080AEAD8:
	movs r0, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEAF4
	ldr r2, .L080AECC8
	movs r0, #3
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AEB1E
.L080AEAF4:
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEB10
	ldr r2, .L080AECC8
	movs r0, #3
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AEB1E
.L080AEB10:
	ldr r2, .L080AECC8
	movs r0, #0
	adds r1, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEB2E
.L080AEB1E:
	ldr r0, .L080AECC0
	movs r3, #0x83
	lsls r3, r3, #1
	adds r2, r0, r3
	movs r1, #0
	strh r1, [r2]
	adds r0, #0xf6
	strh r1, [r0]
.L080AEB2E:
	ldr r4, .L080AECC4
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEB4C
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AEB92
.L080AEB4C:
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEB68
	ldr r2, .L080AECC8
	movs r0, #1
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AEB92
.L080AEB68:
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEB84
	ldr r2, .L080AECC8
	movs r0, #1
	movs r1, #0
	bl View_GetWall
	cmp r0, #0
	bne .L080AEB92
.L080AEB84:
	ldr r2, .L080AECC8
	movs r0, #0
	movs r1, #1
	bl View_GetWall
	cmp r0, #0
	beq .L080AEBA6
.L080AEB92:
	ldr r1, .L080AECC0
	movs r0, #0x8d
	lsls r0, r0, #1
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	movs r2, #0x95
	lsls r2, r2, #1
	adds r1, r1, r2
	strh r0, [r1]
.L080AEBA6:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEBE0
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEBE0
	ldr r2, .L080AECC0
	movs r3, #0xb9
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #0
	strh r0, [r1]
	subs r3, #0x10
	adds r1, r2, r3
	strh r0, [r1]
	subs r3, #2
	adds r1, r2, r3
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0xf8
	strh r0, [r1]
.L080AEBE0:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEC1C
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEC1C
	ldr r2, .L080AECC0
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r1, r2, r3
	strh r0, [r1]
	subs r3, #6
	adds r1, r2, r3
	strh r0, [r1]
	subs r3, #0x68
	adds r1, r2, r3
	strh r0, [r1]
.L080AEC1C:
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEC3C
	ldr r0, .L080AECC0
	ldr r2, .L080AECCC
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r2, [r0]
.L080AEC3C:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEC5C
	ldr r0, .L080AECC0
	ldr r2, .L080AECD0
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r2, [r0]
.L080AEC5C:
	ldr r4, .L080AECC4
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEC86
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AEC86
	ldr r0, .L080AECC0
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0
	strh r0, [r1]
.L080AEC86:
	ldr r4, .L080AECC4
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AECB0
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl View_GetWall
	cmp r0, #0
	beq .L080AECB0
	ldr r0, .L080AECC0
	movs r3, #0x8d
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #0
	strh r0, [r1]
.L080AECB0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.L080AECC0: .4byte 0x0200AB08 @ EWRAM+0xAB08
.L080AECC4: .4byte 0x0000FFFF
.L080AECC8: .4byte 0x0000FFFE
.L080AECCC: .4byte 0x0000024A
.L080AECD0: .4byte 0x0000025E
