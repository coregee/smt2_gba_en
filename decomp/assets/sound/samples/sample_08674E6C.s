@ sample_08674E6C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08674E6C
sample_08674E6C:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00001145
	.incbin "build/sound/samples/sample_08674E6C.pcm"
	.byte 0x00, 0x00, 0x00
