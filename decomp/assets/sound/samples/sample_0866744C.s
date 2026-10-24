@ sample_0866744C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0866744C
sample_0866744C:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000CF2
	.incbin "build/sound/samples/sample_0866744C.pcm"
	.byte 0x00, 0x00
