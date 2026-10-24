@ sample_08671254: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08671254
sample_08671254:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x000009F6
	.incbin "build/sound/samples/sample_08671254.pcm"
	.byte 0x00, 0x00
