@ sample_08606A2C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08606A2C
sample_08606A2C:
	.4byte 0x00000000, 0x01588800, 0x00000000, 0x00000CE2
	.incbin "build/sound/samples/sample_08606A2C.pcm"
	.byte 0x00, 0x00
