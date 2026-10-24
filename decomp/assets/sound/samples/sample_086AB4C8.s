@ sample_086AB4C8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086AB4C8
sample_086AB4C8:
	.4byte 0x40000000, 0x00AC4400, 0x00000000, 0x00001630
	.incbin "build/sound/samples/sample_086AB4C8.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
