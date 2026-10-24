@ sample_086141C4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_086141C4
sample_086141C4:
	.4byte 0x00000000, 0x005DC000, 0x00000000, 0x000004D9
	.incbin "build/sound/samples/sample_086141C4.pcm"
	.byte 0x00, 0x00, 0x00
