@ sample_085CB044: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085CB044
sample_085CB044:
	.4byte 0x40000000, 0x00E5F270, 0x000031AF, 0x00005312
	.incbin "build/sound/samples/sample_085CB044.pcm"
	.byte 0xEF, 0x00
