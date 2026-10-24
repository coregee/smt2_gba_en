@ sample_086236D0: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086236D0
sample_086236D0:
	.4byte 0x00000000, 0x01588800, 0x00000000, 0x00003DBC
	.incbin "build/sound/samples/sample_086236D0.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
