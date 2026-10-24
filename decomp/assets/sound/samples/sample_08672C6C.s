@ sample_08672C6C: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08672C6C
sample_08672C6C:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000E59
	.incbin "build/sound/samples/sample_08672C6C.pcm"
	.byte 0x00, 0x00, 0x00
