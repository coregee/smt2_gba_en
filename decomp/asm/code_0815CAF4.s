	.include "asm/macros.inc"

	.syntax unified
	.text

	.thumb

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

	thumb_func_start ReadSram_Core
ReadSram_Core: @ 0x0815CB2C
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

	thumb_func_start ReadSram
ReadSram: @ 0x0815CB50
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
.L0815CB84: .4byte ReadSram_Core
.L0815CB88: .4byte ReadSram
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

	thumb_func_start WriteSram
WriteSram: @ 0x0815CBB4
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

	thumb_func_start VerifySram_Core
VerifySram_Core: @ 0x0815CBF4
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

	thumb_func_start VerifySram
VerifySram: @ 0x0815CC24
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
.L0815CC58: .4byte VerifySram_Core
.L0815CC5C: .4byte VerifySram
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

	thumb_func_start WriteSramEx
WriteSramEx: @ 0x0815CC88
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
	bl WriteSram
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl VerifySram
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

	thumb_func_start __pack_d
__pack_d: @ 0x0815CF9C
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
	bl __lshrdi3
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

	thumb_func_start __unpack_d
__unpack_d: @ 0x0815D0E4
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

	thumb_func_start __fpadd_parts_d
__fpadd_parts_d: @ 0x0815D1BC
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
	bl __negdi2
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
	bl __negdi2
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

	thumb_func_start __adddf3
__adddf3: @ 0x0815D428
.L0815D428:
	push {r4, lr}
	sub sp, #0x4c
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	str r3, [sp, #0x48]
	add r0, sp, #0x3c
	mov r1, sp
	bl __unpack_d
	add r0, sp, #0x44
	add r4, sp, #0x14
	adds r1, r4, #0
	bl __unpack_d
	add r2, sp, #0x28
	mov r0, sp
	adds r1, r4, #0
	bl __fpadd_parts_d
	bl __pack_d
	add sp, #0x4c
	pop {r4, pc}

	thumb_func_start __subdf3
__subdf3: @ 0x0815D458
	push {r4, lr}
	sub sp, #0x4c
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	str r3, [sp, #0x48]
	add r0, sp, #0x3c
	mov r1, sp
	bl __unpack_d
	add r0, sp, #0x44
	add r4, sp, #0x14
	adds r1, r4, #0
	bl __unpack_d
	ldr r0, [r4, #4]
	movs r1, #1
	eors r0, r1
	str r0, [r4, #4]
	add r2, sp, #0x28
	mov r0, sp
	adds r1, r4, #0
	bl __fpadd_parts_d
	bl __pack_d
	add sp, #0x4c
	pop {r4, pc}

	thumb_func_start __muldf3
__muldf3: @ 0x0815D490
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
	bl __unpack_d
	add r0, sp, #0x44
	add r4, sp, #0x14
	adds r1, r4, #0
	bl __unpack_d
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
	bl __muldi3
	str r0, [sp, #0x5c]
	str r1, [sp, #0x60]
	ldr r0, [sp, #0x54]
	ldr r1, [sp, #0x58]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __muldi3
	adds r7, r1, #0
	adds r6, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x4c]
	ldr r3, [sp, #0x50]
	bl __muldi3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x54]
	ldr r1, [sp, #0x58]
	ldr r2, [sp, #0x4c]
	ldr r3, [sp, #0x50]
	bl __muldi3
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
	bl __pack_d
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

	thumb_func_start __divdf3
__divdf3: @ 0x0815D738
	push {r4, r5, r6, r7, lr}
	sub sp, #0x48
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl __unpack_d
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
	bl __pack_d
	add sp, #0x48
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
.L0815D8B8: .4byte 0x00000000
.L0815D8BC: .4byte 0x10000000

	thumb_func_start __fpcmp_parts_d
__fpcmp_parts_d: @ 0x0815D8C0
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

	thumb_func_start __cmpdf2
__cmpdf2: @ 0x0815D9C0
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl __unpack_d
	mov r0, sp
	adds r1, r4, #0
	bl __fpcmp_parts_d
	add sp, #0x38
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start __eqdf2
__eqdf2: @ 0x0815D9EC
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl __unpack_d
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
	bl __fpcmp_parts_d
.L0815DA32:
	add sp, #0x38
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start __nedf2
__nedf2: @ 0x0815DA38
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl __unpack_d
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
	bl __fpcmp_parts_d
.L0815DA7E:
	add sp, #0x38
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start __gtdf2
__gtdf2: @ 0x0815DA84
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl __unpack_d
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
	bl __fpcmp_parts_d
.L0815DACC:
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start __gedf2
__gedf2: @ 0x0815DAD0
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl __unpack_d
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
	bl __fpcmp_parts_d
.L0815DB18:
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start __ltdf2
__ltdf2: @ 0x0815DB1C
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl __unpack_d
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
	bl __fpcmp_parts_d
.L0815DB62:
	add sp, #0x38
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start __ledf2
__ledf2: @ 0x0815DB68
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	add r0, sp, #0x28
	mov r1, sp
	bl __unpack_d
	add r0, sp, #0x30
	add r4, sp, #0x14
	adds r1, r4, #0
	bl __unpack_d
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
	bl __fpcmp_parts_d
.L0815DBAE:
	add sp, #0x38
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start __floatsidf
__floatsidf: @ 0x0815DBB4
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
	bl __pack_d
.L0815DC28:
	add sp, #0x14
	pop {r4, r5, pc}
.L0815DC2C: .4byte 0x0FFFFFFF

	thumb_func_start __fixdfsi
__fixdfsi: @ 0x0815DC30
	push {lr}
	sub sp, #0x1c
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r0, sp, #0x14
	mov r1, sp
	bl __unpack_d
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
	bl __lshrdi3
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

	thumb_func_start __negdf2
__negdf2: @ 0x0815DCA4
	push {lr}
	sub sp, #0x1c
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r0, sp, #0x14
	mov r1, sp
	bl __unpack_d
	movs r1, #0
	ldr r0, [sp, #4]
	cmp r0, #0
	bne .L0815DCBE
	movs r1, #1
.L0815DCBE:
	str r1, [sp, #4]
	mov r0, sp
	bl __pack_d
	add sp, #0x1c
	pop {pc}
	.byte 0x00, 0x00

	thumb_func_start __make_dp
__make_dp: @ 0x0815DCCC
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
	bl __pack_d
	add sp, #0x14
	pop {r4}
	pop {r3}
	add sp, #4
	bx r3
	.byte 0x00, 0x00

	thumb_func_start __truncdfsf2
__truncdfsf2: @ 0x0815DCF4
.L0815DCF4:
	push {r4, r5, lr}
	sub sp, #0x1c
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r0, sp, #0x14
	mov r1, sp
	bl __unpack_d
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
	bl __make_fp
	add sp, #0x1c
	pop {r4, r5, pc}
.L0815DD34: .4byte 0x3FFFFFFF

	thumb_func_start __pack_f
__pack_f: @ 0x0815DD38
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

	thumb_func_start __unpack_f
__unpack_f: @ 0x0815DDF0
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

	thumb_func_start __fpadd_parts_f
__fpadd_parts_f: @ 0x0815DE6C
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

	thumb_func_start __addsf3
__addsf3: @ 0x0815DFE8
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	add r0, sp, #0x30
	mov r1, sp
	bl __unpack_f
	add r0, sp, #0x34
	add r4, sp, #0x10
	adds r1, r4, #0
	bl __unpack_f
	add r2, sp, #0x20
	mov r0, sp
	adds r1, r4, #0
	bl __fpadd_parts_f
	bl __pack_f
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start __subsf3
__subsf3: @ 0x0815E014
	push {r4, lr}
	sub sp, #0x38
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	add r0, sp, #0x30
	mov r1, sp
	bl __unpack_f
	add r0, sp, #0x34
	add r4, sp, #0x10
	adds r1, r4, #0
	bl __unpack_f
	ldr r0, [r4, #4]
	movs r1, #1
	eors r0, r1
	str r0, [r4, #4]
	add r2, sp, #0x20
	mov r0, sp
	adds r1, r4, #0
	bl __fpadd_parts_f
	bl __pack_f
	add sp, #0x38
	pop {r4, pc}

	thumb_func_start __mulsf3
__mulsf3: @ 0x0815E048
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x38
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	add r0, sp, #0x30
	mov r1, sp
	bl __unpack_f
	add r0, sp, #0x34
	add r4, sp, #0x10
	adds r1, r4, #0
	bl __unpack_f
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
	bl __muldi3
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
	bl __pack_f
	add sp, #0x38
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7, pc}
.L0815E1A8: .4byte 0x3FFFFFFF

	thumb_func_start __divsf3
__divsf3: @ 0x0815E1AC
	push {r4, r5, r6, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, #0x24
	add r5, sp, #0x10
	adds r1, r5, #0
	bl __unpack_f
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
	bl __pack_f
	add sp, #0x28
	pop {r4, r5, r6, pc}
	.byte 0x00, 0x00

	thumb_func_start __fpcmp_parts_f
__fpcmp_parts_f: @ 0x0815E298
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

	thumb_func_start __cmpsf2
__cmpsf2: @ 0x0815E37C
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl __unpack_f
	mov r0, sp
	adds r1, r4, #0
	bl __fpcmp_parts_f
	add sp, #0x28
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start __eqsf2
__eqsf2: @ 0x0815E3A4
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl __unpack_f
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
	bl __fpcmp_parts_f
.L0815E3E6:
	add sp, #0x28
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start __nesf2
__nesf2: @ 0x0815E3EC
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl __unpack_f
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
	bl __fpcmp_parts_f
.L0815E42E:
	add sp, #0x28
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start __gtsf2
__gtsf2: @ 0x0815E434
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl __unpack_f
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
	bl __fpcmp_parts_f
.L0815E478:
	add sp, #0x28
	pop {r4, pc}

	thumb_func_start __gesf2
__gesf2: @ 0x0815E47C
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl __unpack_f
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
	bl __fpcmp_parts_f
.L0815E4C0:
	add sp, #0x28
	pop {r4, pc}

	thumb_func_start __ltsf2
__ltsf2: @ 0x0815E4C4
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl __unpack_f
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
	bl __fpcmp_parts_f
.L0815E506:
	add sp, #0x28
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start __lesf2
__lesf2: @ 0x0815E50C
	push {r4, lr}
	sub sp, #0x28
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, sp, #0x20
	mov r1, sp
	bl __unpack_f
	add r0, sp, #0x24
	add r4, sp, #0x10
	adds r1, r4, #0
	bl __unpack_f
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
	bl __fpcmp_parts_f
.L0815E54E:
	add sp, #0x28
	pop {r4, pc}
	.byte 0x00, 0x00

	thumb_func_start __floatsisf
__floatsisf: @ 0x0815E554
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
	bl __pack_f
.L0815E5AA:
	add sp, #0x10
	pop {pc}
	.byte 0x00, 0x00
.L0815E5B0: .4byte 0x3FFFFFFF

	thumb_func_start __fixsfsi
__fixsfsi: @ 0x0815E5B4
.L0815E5B4:
	push {lr}
	sub sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, sp
	bl __unpack_f
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

	thumb_func_start __negsf2
__negsf2: @ 0x0815E61C
	push {lr}
	sub sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, sp
	bl __unpack_f
	movs r1, #0
	ldr r0, [sp, #4]
	cmp r0, #0
	bne .L0815E634
	movs r1, #1
.L0815E634:
	str r1, [sp, #4]
	mov r0, sp
	bl __pack_f
	add sp, #0x14
	pop {pc}

	thumb_func_start __make_fp
__make_fp: @ 0x0815E640
.L0815E640:
	push {lr}
	sub sp, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	mov r0, sp
	bl __pack_f
	add sp, #0x10
	pop {pc}
	.byte 0x00, 0x00

	thumb_func_start __extendsfdf2
__extendsfdf2: @ 0x0815E658
	push {r4, r5, r6, lr}
	sub sp, #0x18
	str r0, [sp, #0x14]
	add r0, sp, #0x14
	add r1, sp, #4
	bl __unpack_f
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
	bl __make_dp
	add sp, #0x18
	pop {r4, r5, r6, pc}
