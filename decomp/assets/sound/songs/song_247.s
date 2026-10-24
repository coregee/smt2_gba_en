@ song_247: m4a song, header 0x086BD4C4
	.include "assets/sound/MPlayDef.inc"

	.global song_247_track1
song_247_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 51
	.byte VOL, 127
	.byte N04, 56, 127
	.byte W02
	.byte 52
	.byte W04
	.byte FINE

	.byte 0x00
	.global song_247
song_247:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_247_track1
