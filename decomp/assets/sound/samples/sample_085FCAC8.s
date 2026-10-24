@ sample_085FCAC8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085FCAC8
sample_085FCAC8:
	.4byte 0x00000000, 0x01588800, 0x00000000, 0x0000135C
	.incbin "build/sound/samples/sample_085FCAC8.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
