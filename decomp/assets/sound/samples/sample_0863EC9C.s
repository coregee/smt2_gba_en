@ sample_0863EC9C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0863EC9C
sample_0863EC9C:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00000FA3
	.incbin "build/sound/samples/sample_0863EC9C.pcm"
	.byte 0x00
