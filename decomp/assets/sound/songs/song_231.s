@ song_231: m4a song, header 0x086BD488
	.include "assets/sound/MPlayDef.inc"

	.global song_231_track1
song_231_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 69
	.byte VOL, 127
	.byte PAN, 64
	.byte N44, 60, 88
	.byte W44
	.byte W01
	.byte FINE

	.global song_231
song_231:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_231_track1
