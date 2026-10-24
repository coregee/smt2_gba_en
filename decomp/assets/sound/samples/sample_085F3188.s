@ sample_085F3188: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F3188
sample_085F3188:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00000B6C
	.incbin "build/sound/samples/sample_085F3188.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
