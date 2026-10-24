@ sample_085FDE38: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085FDE38
sample_085FDE38:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x000003B7
	.incbin "build/sound/samples/sample_085FDE38.pcm"
	.byte 0x00
