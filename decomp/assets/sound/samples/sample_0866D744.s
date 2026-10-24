@ sample_0866D744: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0866D744
sample_0866D744:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000A3B
	.incbin "build/sound/samples/sample_0866D744.pcm"
	.byte 0x00
