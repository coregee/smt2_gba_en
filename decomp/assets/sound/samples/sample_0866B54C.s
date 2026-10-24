@ sample_0866B54C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0866B54C
sample_0866B54C:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000CBD
	.incbin "build/sound/samples/sample_0866B54C.pcm"
	.byte 0x00, 0x00, 0x00
