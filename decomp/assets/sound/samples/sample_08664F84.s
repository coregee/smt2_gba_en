@ sample_08664F84: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08664F84
sample_08664F84:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000B5D
	.incbin "build/sound/samples/sample_08664F84.pcm"
	.byte 0x00, 0x00, 0x00
