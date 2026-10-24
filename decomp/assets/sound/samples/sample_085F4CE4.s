@ sample_085F4CE4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F4CE4
sample_085F4CE4:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x0000184F
	.incbin "build/sound/samples/sample_085F4CE4.pcm"
	.byte 0x00
