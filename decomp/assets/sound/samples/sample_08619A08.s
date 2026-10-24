@ sample_08619A08: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08619A08
sample_08619A08:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000F24
	.incbin "build/sound/samples/sample_08619A08.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
