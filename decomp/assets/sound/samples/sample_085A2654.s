@ sample_085A2654: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085A2654
sample_085A2654:
	.4byte 0x40000000, 0x02C31B56, 0x0000463A, 0x00009A24
	.incbin "build/sound/samples/sample_085A2654.pcm"
	.byte 0xF3, 0x00, 0x00, 0x00
