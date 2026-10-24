@ sample_0860F8E0: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0860F8E0
sample_0860F8E0:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x0000299E
	.incbin "build/sound/samples/sample_0860F8E0.pcm"
	.byte 0x00, 0x00
