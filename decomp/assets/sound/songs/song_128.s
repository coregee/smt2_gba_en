@ song_128: m4a song, header 0x086BCAA4
	.include "assets/sound/MPlayDef.inc"

	.global song_128_track1
song_128_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 24
	.byte VOL, 127
	.byte PAN, 64
	.byte N05, 57, 104
	.byte W06
	.byte N30, 60
	.byte W30
	.byte FINE

	.byte 0x00, 0x00
	.global song_128
song_128:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_128_track1
