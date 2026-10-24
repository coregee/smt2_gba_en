@ sample_08612E60: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08612E60
sample_08612E60:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x0000065D
	.incbin "build/sound/samples/sample_08612E60.pcm"
	.byte 0x00, 0x00, 0x00
