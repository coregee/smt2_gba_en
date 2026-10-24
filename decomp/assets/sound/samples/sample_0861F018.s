@ sample_0861F018: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0861F018
sample_0861F018:
	.4byte 0x00000000, 0x00BB8000, 0x00000000, 0x000019AD
	.incbin "build/sound/samples/sample_0861F018.pcm"
	.byte 0x00, 0x00, 0x00
