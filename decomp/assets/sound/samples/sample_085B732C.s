@ sample_085B732C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085B732C
sample_085B732C:
	.4byte 0x40000000, 0x00BB8000, 0x00000243, 0x00000D01
	.incbin "build/sound/samples/sample_085B732C.pcm"
	.byte 0xF2, 0x00, 0x00
