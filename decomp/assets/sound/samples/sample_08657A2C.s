@ sample_08657A2C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08657A2C
sample_08657A2C:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x000009C9
	.incbin "build/sound/samples/sample_08657A2C.pcm"
	.byte 0x00, 0x00, 0x00
