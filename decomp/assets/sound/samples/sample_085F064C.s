@ sample_085F064C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F064C
sample_085F064C:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00000735
	.incbin "build/sound/samples/sample_085F064C.pcm"
	.byte 0x00, 0x00, 0x00
