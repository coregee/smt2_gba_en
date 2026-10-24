@ sample_08671C5C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08671C5C
sample_08671C5C:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x000009FC
	.incbin "build/sound/samples/sample_08671C5C.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
