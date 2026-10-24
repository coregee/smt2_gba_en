@ sample_0862EA5C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0862EA5C
sample_0862EA5C:
	.4byte 0x00000000, 0x00ADDC00, 0x00000000, 0x00002A75
	.incbin "build/sound/samples/sample_0862EA5C.pcm"
	.byte 0x00, 0x00, 0x00
