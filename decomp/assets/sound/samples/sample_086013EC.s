@ sample_086013EC: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086013EC
sample_086013EC:
	.4byte 0x00000000, 0x00FA0000, 0x00000000, 0x0000562C
	.incbin "build/sound/samples/sample_086013EC.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
