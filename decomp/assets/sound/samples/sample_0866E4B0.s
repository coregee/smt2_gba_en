@ sample_0866E4B0: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0866E4B0
sample_0866E4B0:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000A31
	.incbin "build/sound/samples/sample_0866E4B0.pcm"
	.byte 0x00, 0x00, 0x00
