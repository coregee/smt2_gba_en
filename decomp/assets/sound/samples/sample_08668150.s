@ sample_08668150: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08668150
sample_08668150:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x00000D53
	.incbin "build/sound/samples/sample_08668150.pcm"
	.byte 0x00
