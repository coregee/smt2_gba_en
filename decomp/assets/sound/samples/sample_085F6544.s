@ sample_085F6544: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F6544
sample_085F6544:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00001084
	.incbin "build/sound/samples/sample_085F6544.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
