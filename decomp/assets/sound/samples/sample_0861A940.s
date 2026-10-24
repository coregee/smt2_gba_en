@ sample_0861A940: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0861A940
sample_0861A940:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000CCF
	.incbin "build/sound/samples/sample_0861A940.pcm"
	.byte 0x00
