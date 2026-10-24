@ sample_085F2EE8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F2EE8
sample_085F2EE8:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x0000028C
	.incbin "build/sound/samples/sample_085F2EE8.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
