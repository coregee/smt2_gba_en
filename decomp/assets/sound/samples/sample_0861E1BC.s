@ sample_0861E1BC: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0861E1BC
sample_0861E1BC:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000E49
	.incbin "build/sound/samples/sample_0861E1BC.pcm"
	.byte 0x00, 0x00, 0x00
