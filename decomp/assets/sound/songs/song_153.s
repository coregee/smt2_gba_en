@ song_153: m4a song, header 0x086BCF1C
	.include "assets/sound/MPlayDef.inc"

	.global song_153_track1
song_153_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 44
	.byte VOL, 127
	.byte PAN, 64
	.byte N24, 60, 100
	.byte W24
	.byte FINE

	.global song_153_track2
song_153_track2:
	.byte KEYSH, 0
	.byte VOICE, 46
	.byte VOL, 127
	.byte PAN, 64
	.byte W18
	.byte N48, 60, 88
	.byte W48
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_153
song_153:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_153_track1
	.4byte song_153_track2
