@ sample_0866EEF4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_0866EEF4
sample_0866EEF4:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000F6F
	.incbin "build/sound/samples/sample_0866EEF4.pcm"
	.byte 0x00
