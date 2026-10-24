@ sample_0868A51C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0868A51C
sample_0868A51C:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00003858
	.incbin "build/sound/samples/sample_0868A51C.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
