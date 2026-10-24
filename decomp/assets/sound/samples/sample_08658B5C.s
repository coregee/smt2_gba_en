@ sample_08658B5C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08658B5C
sample_08658B5C:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x000013F8
	.incbin "build/sound/samples/sample_08658B5C.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
