@ sample_08675FC4: DirectSound sample (header: type, pitch, loop start, size)
	.global sample_08675FC4
sample_08675FC4:
	.4byte 0x00000000, 0x00AC4400, 0x00000000, 0x00000F41
	.incbin "build/sound/samples/sample_08675FC4.pcm"
	.byte 0x00, 0x00, 0x00
