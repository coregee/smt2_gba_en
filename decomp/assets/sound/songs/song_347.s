@ song_347: m4a song, header 0x086BE1F4
	.include "assets/sound/MPlayDef.inc"

	.global song_347_track1
song_347_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N01, 69, 72
	.byte W02
	.byte 74
	.byte W02
	.byte 80
	.byte W02
	.byte 69, 36
	.byte W02
	.byte 74
	.byte W02
	.byte 80
	.byte W01
	.byte FINE

	.global song_347
song_347:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_347_track1
