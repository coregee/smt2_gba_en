@ sample_085B8040: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085B8040
sample_085B8040:
	.4byte 0x40000000, 0x00AC4400, 0x00000A91, 0x00003B13
	.incbin "build/sound/samples/sample_085B8040.pcm"
	.byte 0x20
