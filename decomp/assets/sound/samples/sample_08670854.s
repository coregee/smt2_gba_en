@ sample_08670854: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08670854
sample_08670854:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x000009EF
	.incbin "build/sound/samples/sample_08670854.pcm"
	.byte 0x00
