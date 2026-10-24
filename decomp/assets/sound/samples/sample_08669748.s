@ sample_08669748: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08669748
sample_08669748:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x000010F7
	.incbin "build/sound/samples/sample_08669748.pcm"
	.byte 0x00
