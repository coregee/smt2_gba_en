@ sample_08673AD8: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08673AD8
sample_08673AD8:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00001382
	.incbin "build/sound/samples/sample_08673AD8.pcm"
	.byte 0x00, 0x00
