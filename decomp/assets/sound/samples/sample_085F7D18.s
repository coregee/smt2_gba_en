@ sample_085F7D18: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F7D18
sample_085F7D18:
	.4byte 0x00000000, 0x01588800, 0x00000000, 0x000010CD
	.incbin "build/sound/samples/sample_085F7D18.pcm"
	.byte 0x00, 0x00, 0x00
