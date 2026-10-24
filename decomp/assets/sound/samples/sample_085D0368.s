@ sample_085D0368: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085D0368
sample_085D0368:
	.4byte 0x40000000, 0x00AC4400, 0x00001173, 0x00001FD7
	.incbin "build/sound/samples/sample_085D0368.pcm"
	.byte 0xB7
