@ sample_08680224: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08680224
sample_08680224:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x000049D0
	.incbin "build/sound/samples/sample_08680224.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
