@ sample_08659F68: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08659F68
sample_08659F68:
	.4byte 0x40000000, 0x01588800, 0xFFFFFF92, 0x0000265C
	.incbin "build/sound/samples/sample_08659F68.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
