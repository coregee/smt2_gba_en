@ sample_085F9EEC: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F9EEC
sample_085F9EEC:
	.4byte 0x00000000, 0x01588800, 0x00000000, 0x00001CAF
	.incbin "build/sound/samples/sample_085F9EEC.pcm"
	.byte 0x00
