@ song_252: m4a song, header 0x086BD544
	.include "assets/sound/MPlayDef.inc"

	.global song_252_track1
song_252_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 23
	.byte VOL, 84
	.byte N01, 51, 127
	.byte W02
	.byte N21, 47
	.byte W22
	.byte FINE

	.global song_252
song_252:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_252_track1
