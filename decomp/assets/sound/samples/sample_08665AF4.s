@ sample_08665AF4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08665AF4
sample_08665AF4:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000A3B
	.incbin "build/sound/samples/sample_08665AF4.pcm"
	.byte 0x00
