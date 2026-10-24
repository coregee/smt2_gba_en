@ song_355: m4a song, header 0x086BE338
	.include "assets/sound/MPlayDef.inc"

	.global song_355_track1
song_355_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N02, 88, 80
	.byte W03
	.byte 79
	.byte W03
	.byte 83
	.byte W03
	.byte 76
	.byte W03
	.byte 79
	.byte W03
	.byte 71
	.byte W03
	.byte 79, 40
	.byte W03
	.byte 71
	.byte W03
	.byte FINE

	.global song_355
song_355:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_355_track1
