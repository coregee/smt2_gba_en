@ sample_08652814: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08652814
sample_08652814:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000628
	.incbin "build/sound/samples/sample_08652814.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
