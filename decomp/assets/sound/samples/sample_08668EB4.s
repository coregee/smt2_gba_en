@ sample_08668EB4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08668EB4
sample_08668EB4:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000881
	.incbin "build/sound/samples/sample_08668EB4.pcm"
	.byte 0x00, 0x00, 0x00
