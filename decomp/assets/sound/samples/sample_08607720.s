@ sample_08607720: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08607720
sample_08607720:
	.4byte 0x40000000, 0x01588800, 0x000048B3, 0x00006E76
	.incbin "build/sound/samples/sample_08607720.pcm"
	.byte 0xD7, 0x00
