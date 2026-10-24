@ song_309: m4a song, header 0x086BD9E4
	.include "assets/sound/MPlayDef.inc"

	.global song_309_track1
song_309_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 9
	.byte VOL, 127
	.byte N24, 70, 124
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_309
song_309:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_309_track1
