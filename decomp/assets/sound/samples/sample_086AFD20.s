@ sample_086AFD20: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086AFD20
sample_086AFD20:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x000002A8
	.incbin "build/sound/samples/sample_086AFD20.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
