@ song_100: m4a song, header 0x086BC768
	.include "assets/sound/MPlayDef.inc"

	.global song_100_track1
song_100_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 0
	.byte VOL, 77
	.byte N06, 60, 120
	.byte W06
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_100
song_100:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_100_track1
