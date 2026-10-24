@ sample_085F2368: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F2368
sample_085F2368:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00000B6C
	.incbin "build/sound/samples/sample_085F2368.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
