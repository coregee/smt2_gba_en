@ sample_0865EED8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0865EED8
sample_0865EED8:
	.4byte 0x40000000, 0x01588800, 0xFFFFFF92, 0x00002B11
	.incbin "build/sound/samples/sample_0865EED8.pcm"
	.byte 0x00, 0x00, 0x00
