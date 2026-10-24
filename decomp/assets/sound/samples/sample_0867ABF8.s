@ sample_0867ABF8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0867ABF8
sample_0867ABF8:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00004077
	.incbin "build/sound/samples/sample_0867ABF8.pcm"
	.byte 0x00
