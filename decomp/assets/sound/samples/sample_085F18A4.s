@ sample_085F18A4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F18A4
sample_085F18A4:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00000AB3
	.incbin "build/sound/samples/sample_085F18A4.pcm"
	.byte 0x00
