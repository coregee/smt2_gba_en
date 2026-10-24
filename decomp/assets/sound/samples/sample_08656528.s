@ sample_08656528: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08656528
sample_08656528:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x000014F2
	.incbin "build/sound/samples/sample_08656528.pcm"
	.byte 0x00, 0x00
