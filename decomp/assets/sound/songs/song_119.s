@ song_119: m4a song, header 0x086BC9A0
	.include "assets/sound/MPlayDef.inc"

	.global song_119_track1
song_119_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 19
	.byte VOL, 127
	.byte N12, 60, 127
	.byte W12
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_119
song_119:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_119_track1
