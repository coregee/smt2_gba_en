@ sample_08684C08: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08684C08
sample_08684C08:
	.4byte 0x40000000, 0x007D0000, 0x00003B5A, 0x00004411
	.incbin "build/sound/samples/sample_08684C08.pcm"
	.byte 0x01, 0x00, 0x00
