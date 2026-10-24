@ sample_086A9138: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086A9138
sample_086A9138:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00000CBC
	.incbin "build/sound/samples/sample_086A9138.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
