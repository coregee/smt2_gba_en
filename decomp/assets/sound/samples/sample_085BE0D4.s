@ sample_085BE0D4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085BE0D4
sample_085BE0D4:
	.4byte 0x40000000, 0x00AC4400, 0x00002550, 0x00002B8E
	.incbin "build/sound/samples/sample_085BE0D4.pcm"
	.byte 0x06, 0x00
