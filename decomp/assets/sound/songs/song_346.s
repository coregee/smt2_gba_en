@ song_346: m4a song, header 0x086BE1D0
	.include "assets/sound/MPlayDef.inc"

	.global song_346_track1
song_346_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N01, 79, 72
	.byte W02
	.byte 74
	.byte W02
	.byte 67
	.byte W02
	.byte 79, 36
	.byte W02
	.byte 74
	.byte W02
	.byte 67
	.byte W01
	.byte FINE

	.global song_346
song_346:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_346_track1
