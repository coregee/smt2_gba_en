@ sample_0863FC50: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0863FC50
sample_0863FC50:
	.4byte 0x00000000, 0x00FA0000, 0x00000000, 0x0000410A
	.incbin "build/sound/samples/sample_0863FC50.pcm"
	.byte 0x00, 0x00
