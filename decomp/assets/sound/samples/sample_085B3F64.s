@ sample_085B3F64: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085B3F64
sample_085B3F64:
	.4byte 0x40000000, 0x00AC4400, 0x00002B03, 0x000033B7
	.incbin "build/sound/samples/sample_085B3F64.pcm"
	.byte 0x23
