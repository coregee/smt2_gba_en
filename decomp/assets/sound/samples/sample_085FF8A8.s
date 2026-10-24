@ sample_085FF8A8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085FF8A8
sample_085FF8A8:
	.4byte 0x00000000, 0x00FA0000, 0x00000000, 0x00001B32
	.incbin "build/sound/samples/sample_085FF8A8.pcm"
	.byte 0x00, 0x00
