@ sample_085E14E4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085E14E4
sample_085E14E4:
	.4byte 0x40000000, 0x03E80000, 0x00005366, 0x00006AD1
	.incbin "build/sound/samples/sample_085E14E4.pcm"
	.byte 0x0E, 0x00, 0x00
