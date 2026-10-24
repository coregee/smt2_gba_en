@ sample_08663158: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08663158
sample_08663158:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00001E19
	.incbin "build/sound/samples/sample_08663158.pcm"
	.byte 0x00, 0x00, 0x00
