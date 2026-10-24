@ sample_0865C5D8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0865C5D8
sample_0865C5D8:
	.4byte 0x40000000, 0x01588800, 0xFFFFFF92, 0x000028EC
	.incbin "build/sound/samples/sample_0865C5D8.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
