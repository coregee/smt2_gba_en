@ sample_08639564: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08639564
sample_08639564:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00005726
	.incbin "build/sound/samples/sample_08639564.pcm"
	.byte 0x00, 0x00
