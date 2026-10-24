@ sample_085BBB64: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085BBB64
sample_085BBB64:
	.4byte 0x40000000, 0x00AC4400, 0x00001612, 0x0000255F
	.incbin "build/sound/samples/sample_085BBB64.pcm"
	.byte 0x00
