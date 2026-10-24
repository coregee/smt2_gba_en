@ song_110: m4a song, header 0x086BC88C
	.include "assets/sound/MPlayDef.inc"

	.global song_110_track1
song_110_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 10
	.byte VOL, 110
	.byte PAN, 64
	.byte N04, 55, 72
	.byte W05
	.byte 57, 100
	.byte W05
	.byte 57, 127
	.byte W05
	.byte N04
	.byte W05
	.byte N02, 57, 20
	.byte W03
	.byte FINE

	.byte 0x00
	.global song_110
song_110:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_110_track1
