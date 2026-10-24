@ sample_086AFFDC: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086AFFDC
sample_086AFFDC:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x000031BB
	.incbin "build/sound/samples/sample_086AFFDC.pcm"
	.byte 0x00
