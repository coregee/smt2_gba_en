@ song_156: m4a song, header 0x086BCFB4
	.include "assets/sound/MPlayDef.inc"

	.global song_156_track1
song_156_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 45
	.byte VOL, 127
	.byte PAN, 64
	.byte N30, 56, 104
	.byte W06
	.byte N24, 64, 88
	.byte W24
	.byte FINE

	.global song_156_track2
song_156_track2:
	.byte KEYSH, 0
	.byte VOICE, 46
	.byte VOL, 127
	.byte PAN, 64
	.byte W30
	.byte N48, 58, 72
	.byte N48, 62, 100
	.byte W48
	.byte FINE

	.global song_156
song_156:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_156_track1
	.4byte song_156_track2
