@ sample_086A4414: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086A4414
sample_086A4414:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00004D10
	.incbin "build/sound/samples/sample_086A4414.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
