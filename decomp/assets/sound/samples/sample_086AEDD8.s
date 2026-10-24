@ sample_086AEDD8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086AEDD8
sample_086AEDD8:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00000F37
	.incbin "build/sound/samples/sample_086AEDD8.pcm"
	.byte 0x00
