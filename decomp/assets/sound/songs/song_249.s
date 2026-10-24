@ song_249: m4a song, header 0x086BD4E0
	.include "assets/sound/MPlayDef.inc"

	.global song_249_track1
song_249_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 20
	.byte VOL, 84
	.byte N04, 72, 127
	.byte W04
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_249
song_249:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_249_track1
