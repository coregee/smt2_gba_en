@ sample_085F3D08: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_085F3D08
sample_085F3D08:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00000FC8
	.incbin "build/sound/samples/sample_085F3D08.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
