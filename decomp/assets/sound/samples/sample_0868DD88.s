@ sample_0868DD88: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0868DD88
sample_0868DD88:
	.4byte 0x40000000, 0x00AC4400, 0x000000FA, 0x00002C45
	.incbin "build/sound/samples/sample_0868DD88.pcm"
	.byte 0xEF, 0x00, 0x00
