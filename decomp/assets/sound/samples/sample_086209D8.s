@ sample_086209D8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086209D8
sample_086209D8:
	.4byte 0x40000000, 0x005DC000, 0xFFFFFEA3, 0x00002CE6
	.incbin "build/sound/samples/sample_086209D8.pcm"
	.byte 0x00, 0x00
