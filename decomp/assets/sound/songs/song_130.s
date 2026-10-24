@ song_130: m4a song, header 0x086BCAEC
	.include "assets/sound/MPlayDef.inc"

	.global song_130_track1
song_130_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 30
	.byte VOL, 120
	.byte N44, 57, 92
	.byte W48
	.byte N32, 60, 100
	.byte W48
	.byte W12
	.byte N19, 57
	.byte W36
	.byte N20, 60, 88
	.byte W48
	.byte W36
	.byte N23, 57, 92
	.byte W23
	.byte FINE

	.byte 0x00, 0x00
	.global song_130
song_130:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_130_track1
