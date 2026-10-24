@ sample_08676F18: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08676F18
sample_08676F18:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00002360
	.incbin "build/sound/samples/sample_08676F18.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
