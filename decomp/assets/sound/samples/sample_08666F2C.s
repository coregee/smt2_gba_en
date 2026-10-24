@ sample_08666F2C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08666F2C
sample_08666F2C:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x0000050D
	.incbin "build/sound/samples/sample_08666F2C.pcm"
	.byte 0x00, 0x00, 0x00
