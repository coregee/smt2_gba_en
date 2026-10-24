@ song_351: m4a song, header 0x086BE2C0
	.include "assets/sound/MPlayDef.inc"

	.global song_351_track1
song_351_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N02, 69, 80
	.byte W03
	.byte 76
	.byte W03
	.byte 73
	.byte W03
	.byte 81
	.byte W03
	.byte 76
	.byte W03
	.byte 85
	.byte W03
	.byte 81
	.byte W03
	.byte 88
	.byte W03
	.byte 81, 40
	.byte W03
	.byte 88
	.byte W02
	.byte FINE

	.global song_351
song_351:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_351_track1
