@ sample_086AEB24: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086AEB24
sample_086AEB24:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x000002A3
	.incbin "build/sound/samples/sample_086AEB24.pcm"
	.byte 0x00
