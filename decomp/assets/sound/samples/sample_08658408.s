@ sample_08658408: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08658408
sample_08658408:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000743
	.incbin "build/sound/samples/sample_08658408.pcm"
	.byte 0x00
