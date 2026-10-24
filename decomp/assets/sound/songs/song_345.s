@ song_345: m4a song, header 0x086BE1AC
	.include "assets/sound/MPlayDef.inc"

	.global song_345_track1
song_345_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N01, 71, 72
	.byte W01
	.byte 69
	.byte W01
	.byte 74
	.byte W01
	.byte 76
	.byte W02
	.byte N03, 79
	.byte W03
	.byte FINE

	.byte 0x00, 0x00
	.global song_345
song_345:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_345_track1
