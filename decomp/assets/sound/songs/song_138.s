@ song_138: m4a song, header 0x086BCCF0
	.include "assets/sound/MPlayDef.inc"

	.global song_138_track1
song_138_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 31
	.byte VOL, 127
	.byte PAN, 64
	.byte N24, 58, 88
	.byte W03
	.byte 62, 104
	.byte W24
	.byte FINE

	.byte 0x00, 0x00
	.global song_138
song_138:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_138_track1
