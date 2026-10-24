@ sample_08652E50: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08652E50
sample_08652E50:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00001480
	.incbin "build/sound/samples/sample_08652E50.pcm"
	.byte 0x00, 0x00, 0x00, 0x00
