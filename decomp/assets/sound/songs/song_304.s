@ song_304: m4a song, header 0x086BD884
	.include "assets/sound/MPlayDef.inc"

	.global song_304_track1
song_304_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 127
	.byte N96, 53, 127
	.byte W96
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_304
song_304:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_304_track1
