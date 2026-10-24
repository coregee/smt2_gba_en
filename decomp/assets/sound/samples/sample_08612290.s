@ sample_08612290: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08612290
sample_08612290:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000BBE
	.incbin "build/sound/samples/sample_08612290.pcm"
	.byte 0x00, 0x00
