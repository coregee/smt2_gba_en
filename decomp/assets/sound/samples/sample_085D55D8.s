@ sample_085D55D8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085D55D8
sample_085D55D8:
	.4byte 0x40000000, 0x00F66000, 0x00000000, 0x0000001E
	.incbin "build/sound/samples/sample_085D55D8.pcm"
	.byte 0xFF, 0x00
