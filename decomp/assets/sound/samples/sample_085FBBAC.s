@ sample_085FBBAC: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085FBBAC
sample_085FBBAC:
	.4byte 0x00000000, 0x01588800, 0x00000000, 0x00000F0A
	.incbin "build/sound/samples/sample_085FBBAC.pcm"
	.byte 0x00, 0x00
