@ sample_085D5608: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085D5608
sample_085D5608:
	.4byte 0x00000000, 0x00F66000, 0x00000000, 0x00004447
	.incbin "build/sound/samples/sample_085D5608.pcm"
	.byte 0x00
