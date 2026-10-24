@ sample_0866A850: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0866A850
sample_0866A850:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000CEB
	.incbin "build/sound/samples/sample_0866A850.pcm"
	.byte 0x00
