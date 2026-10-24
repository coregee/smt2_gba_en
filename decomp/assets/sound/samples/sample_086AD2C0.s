@ sample_086AD2C0: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086AD2C0
sample_086AD2C0:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00000F4E
	.incbin "build/sound/samples/sample_086AD2C0.pcm"
	.byte 0x00, 0x00
