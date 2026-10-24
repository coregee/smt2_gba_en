@ song_162: m4a song, header 0x086BD0B8
	.include "assets/sound/MPlayDef.inc"

	.global song_162_track1
song_162_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 52
	.byte VOL, 127
	.byte PAN, 64
	.byte N42, 60, 96
	.byte W42
	.byte FINE

	.byte 0x00
	.global song_162
song_162:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_162_track1
