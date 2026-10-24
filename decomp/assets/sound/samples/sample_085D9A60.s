@ sample_085D9A60: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085D9A60
sample_085D9A60:
	.4byte 0x40000000, 0x00BB8000, 0x00003521, 0x00003B96
	.incbin "build/sound/samples/sample_085D9A60.pcm"
	.byte 0xF8, 0x00
