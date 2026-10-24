@ sample_085EE400: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085EE400
sample_085EE400:
	.4byte 0x40000000, 0x00AC4400, 0x00001F95, 0x0000223B
	.incbin "build/sound/samples/sample_085EE400.pcm"
	.byte 0xDC
