@ sample_0869D1C4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0869D1C4
sample_0869D1C4:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x0000723C
	.incbin "build/sound/samples/sample_0869D1C4.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
