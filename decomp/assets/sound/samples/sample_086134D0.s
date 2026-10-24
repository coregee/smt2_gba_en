@ sample_086134D0: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086134D0
sample_086134D0:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000CE0
	.incbin "build/sound/samples/sample_086134D0.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
