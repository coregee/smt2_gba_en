@ sample_086619FC: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086619FC
sample_086619FC:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000B8F
	.incbin "build/sound/samples/sample_086619FC.pcm"
	.byte 0x00
