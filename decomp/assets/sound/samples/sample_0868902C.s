@ sample_0868902C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0868902C
sample_0868902C:
	.4byte 0x00000000, 0x01588800, 0x00000000, 0x000014DD
	.incbin "build/sound/samples/sample_0868902C.pcm"
	.byte 0x00, 0x00, 0x00
