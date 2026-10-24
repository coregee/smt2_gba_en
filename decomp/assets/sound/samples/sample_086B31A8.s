@ sample_086B31A8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086B31A8
sample_086B31A8:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x000006BF
	.incbin "build/sound/samples/sample_086B31A8.pcm"
	.byte 0x00
