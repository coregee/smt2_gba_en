@ sample_085EB5C0: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085EB5C0
sample_085EB5C0:
	.4byte 0x40000000, 0x00AC4400, 0x00002A8E, 0x00002E2F
	.incbin "build/sound/samples/sample_085EB5C0.pcm"
	.byte 0xEB
