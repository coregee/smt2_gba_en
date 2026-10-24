@ sample_085E7FC8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085E7FC8
sample_085E7FC8:
	.4byte 0x40000000, 0x00AC4400, 0x00001D93, 0x000035E4
	.incbin "build/sound/samples/sample_085E7FC8.pcm"
	.byte 0xBC, 0x00, 0x00, 0x00
