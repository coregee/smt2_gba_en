@ sample_08654A4C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08654A4C
sample_08654A4C:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x000013FA
	.incbin "build/sound/samples/sample_08654A4C.pcm"
	.byte 0x00, 0x00
