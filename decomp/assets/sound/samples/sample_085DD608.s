@ sample_085DD608: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085DD608
sample_085DD608:
	.4byte 0x00000000, 0x00FA0000, 0x00000000, 0x00003ECB
	.incbin "build/sound/samples/sample_085DD608.pcm"
	.byte 0x00
