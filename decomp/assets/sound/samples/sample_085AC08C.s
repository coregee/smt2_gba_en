@ sample_085AC08C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085AC08C
sample_085AC08C:
	.4byte 0x40000000, 0x00FA0000, 0x00004EC3, 0x00007EC4
	.incbin "build/sound/samples/sample_085AC08C.pcm"
	.byte 0x09, 0x00, 0x00, 0x00
