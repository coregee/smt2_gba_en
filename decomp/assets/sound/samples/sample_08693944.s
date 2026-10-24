@ sample_08693944: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08693944
sample_08693944:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x0000986E
	.incbin "build/sound/samples/sample_08693944.pcm"
	.byte 0x00, 0x00
