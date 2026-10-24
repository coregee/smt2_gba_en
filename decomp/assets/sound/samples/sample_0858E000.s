@ sample_0858E000: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0858E000
sample_0858E000:
	.4byte 0x00000000, 0x00FA0000, 0x00000000, 0x00014642
	.incbin "build/sound/samples/sample_0858E000.pcm"
	.byte 0x00, 0x00
