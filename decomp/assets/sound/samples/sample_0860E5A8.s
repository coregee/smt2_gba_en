@ sample_0860E5A8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0860E5A8
sample_0860E5A8:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00001325
	.incbin "build/sound/samples/sample_0860E5A8.pcm"
	.byte 0x00, 0x00, 0x00
