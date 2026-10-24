@ sample_085F0D94: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F0D94
sample_085F0D94:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00000AFD
	.incbin "build/sound/samples/sample_085F0D94.pcm"
	.byte 0x00, 0x00, 0x00
