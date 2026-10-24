@ sample_0866CED0: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0866CED0
sample_0866CED0:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000862
	.incbin "build/sound/samples/sample_0866CED0.pcm"
	.byte 0x00, 0x00
