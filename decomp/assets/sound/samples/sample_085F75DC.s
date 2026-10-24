@ sample_085F75DC: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F75DC
sample_085F75DC:
	.4byte 0x00000000, 0x01588800, 0x00000000, 0x0000072B
	.incbin "build/sound/samples/sample_085F75DC.pcm"
	.byte 0x00
