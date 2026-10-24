@ sample_0866C21C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0866C21C
sample_0866C21C:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000CA1
	.incbin "build/sound/samples/sample_0866C21C.pcm"
	.byte 0x00, 0x00, 0x00
