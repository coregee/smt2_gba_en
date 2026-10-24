@ Function boundary markers.  They only mark symbols; they never align or pad, because the
@ layout is reproduced byte for byte from explicit padding in the source.
	.macro thumb_func_start name
	.global \name
	.thumb_func
	.type \name, %function
	.endm

	.macro arm_func_start name
	.global \name
	.arm
	.type \name, %function
	.endm

	.macro non_word_aligned_thumb_func_start name
	thumb_func_start \name
	.endm
