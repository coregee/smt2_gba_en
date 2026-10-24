@ sample_0864A818: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0864A818
sample_0864A818:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00007FE9
	.incbin "build/sound/samples/sample_0864A818.pcm"
	.byte 0x00, 0x00, 0x00
