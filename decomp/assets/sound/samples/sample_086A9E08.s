@ sample_086A9E08: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086A9E08
sample_086A9E08:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x000016AD
	.incbin "build/sound/samples/sample_086A9E08.pcm"
	.byte 0x00, 0x00, 0x00
