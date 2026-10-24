@ sample_08655E58: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08655E58
sample_08655E58:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x000006BE
	.incbin "build/sound/samples/sample_08655E58.pcm"
	.byte 0x00, 0x00
