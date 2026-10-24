@ sample_086AE220: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086AE220
sample_086AE220:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x000008F3
	.incbin "build/sound/samples/sample_086AE220.pcm"
	.byte 0x00
