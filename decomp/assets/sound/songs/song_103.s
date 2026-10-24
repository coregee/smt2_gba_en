@ song_103: m4a song, header 0x086BC7BC
	.include "assets/sound/MPlayDef.inc"

	.global song_103_track1
song_103_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 3
	.byte VOL, 90
	.byte N24, 60, 127
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_103
song_103:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_103_track1
