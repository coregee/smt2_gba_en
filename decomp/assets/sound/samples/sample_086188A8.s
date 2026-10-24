@ sample_086188A8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086188A8
sample_086188A8:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x0000114C
	.incbin "build/sound/samples/sample_086188A8.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
