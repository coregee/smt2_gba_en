@ sample_086542E4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086542E4
sample_086542E4:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000755
	.incbin "build/sound/samples/sample_086542E4.pcm"
	.byte 0x00, 0x00, 0x00
