@ sample_085FE200: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085FE200
sample_085FE200:
	.4byte 0x00000000, 0x00FA0000, 0x00000000, 0x00001696
	.incbin "build/sound/samples/sample_085FE200.pcm"
	.byte 0x00, 0x00
