@ song_122: m4a song, header 0x086BC9F4
	.include "assets/sound/MPlayDef.inc"

	.global song_122_track1
song_122_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 22
	.byte VOL, 127
	.byte PAN, 64
	.byte N36, 60, 104
	.byte W36
	.byte FINE

	.byte 0x00
	.global song_122
song_122:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_122_track1
