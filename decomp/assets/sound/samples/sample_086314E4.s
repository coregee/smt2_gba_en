@ sample_086314E4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086314E4
sample_086314E4:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x0000806F
	.incbin "build/sound/samples/sample_086314E4.pcm"
	.byte 0x00
