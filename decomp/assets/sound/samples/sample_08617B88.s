@ sample_08617B88: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08617B88
sample_08617B88:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000D0E
	.incbin "build/sound/samples/sample_08617B88.pcm"
	.byte 0x00, 0x00
