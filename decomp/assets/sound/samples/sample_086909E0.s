@ sample_086909E0: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086909E0
sample_086909E0:
	.4byte 0x40000000, 0x00AC4400, 0x00000000, 0x00002F50
	.incbin "build/sound/samples/sample_086909E0.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
