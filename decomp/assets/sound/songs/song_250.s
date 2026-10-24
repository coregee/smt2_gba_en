@ song_250: m4a song, header 0x086BD4FC
	.include "assets/sound/MPlayDef.inc"

	.global song_250_track1
song_250_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 22
	.byte VOL, 84
	.byte N01, 57, 127
	.byte W02
	.byte N76, 60
	.byte W76
	.byte FINE

	.global song_250
song_250:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_250_track1
