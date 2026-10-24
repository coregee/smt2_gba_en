@ sample_08643D6C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08643D6C
sample_08643D6C:
	.4byte 0x00000000, 0x00FA0000, 0x00000000, 0x00006A9A
	.incbin "build/sound/samples/sample_08643D6C.pcm"
	.byte 0x00, 0x00
