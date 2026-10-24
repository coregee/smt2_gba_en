@ sample_0861B620: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0861B620
sample_0861B620:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000B6A
	.incbin "build/sound/samples/sample_0861B620.pcm"
	.byte 0x00, 0x00
