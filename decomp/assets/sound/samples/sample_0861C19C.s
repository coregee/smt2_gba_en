@ sample_0861C19C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0861C19C
sample_0861C19C:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00001097
	.incbin "build/sound/samples/sample_0861C19C.pcm"
	.byte 0x00
