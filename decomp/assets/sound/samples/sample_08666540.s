@ sample_08666540: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08666540
sample_08666540:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x000009DB
	.incbin "build/sound/samples/sample_08666540.pcm"
	.byte 0x00
