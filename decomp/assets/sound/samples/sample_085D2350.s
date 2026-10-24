@ sample_085D2350: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085D2350
sample_085D2350:
	.4byte 0x40000000, 0x01588800, 0x00003053, 0x00003275
	.incbin "build/sound/samples/sample_085D2350.pcm"
	.byte 0x2E, 0x00, 0x00
