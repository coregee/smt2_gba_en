@ sample_086274A0: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086274A0
sample_086274A0:
	.4byte 0x00000000, 0x00ADDC00, 0x00000000, 0x000075A8
	.incbin "build/sound/samples/sample_086274A0.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
