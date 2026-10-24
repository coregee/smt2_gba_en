@ sample_086ACB0C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086ACB0C
sample_086ACB0C:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x000007A3
	.incbin "build/sound/samples/sample_086ACB0C.pcm"
	.byte 0x00
