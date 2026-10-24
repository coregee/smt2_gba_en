@ sample_08617744: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08617744
sample_08617744:
	.4byte 0x00000000, 0x01588800, 0x00000000, 0x00000433
	.incbin "build/sound/samples/sample_08617744.pcm"
	.byte 0x00
