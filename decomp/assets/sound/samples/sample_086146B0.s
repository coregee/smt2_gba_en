@ sample_086146B0: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086146B0
sample_086146B0:
	.4byte 0x00000000, 0x01588800, 0x00000000, 0x00003082
	.incbin "build/sound/samples/sample_086146B0.pcm"
	.byte 0x00, 0x00
