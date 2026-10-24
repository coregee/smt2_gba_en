@ song_167: m4a song, header 0x086BD1B8
	.include "assets/sound/MPlayDef.inc"

	.global song_167_track1
song_167_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 58
	.byte VOL, 127
	.byte PAN, 64
	.byte N06, 60, 48
	.byte W06
	.byte 60, 72
	.byte W06
	.byte 60, 100
	.byte W06
	.byte 60, 108
	.byte W06
	.byte 60, 60
	.byte W06
	.byte N12, 60, 48
	.byte W12
	.byte FINE

	.global song_167_track2
song_167_track2:
	.byte KEYSH, 0
	.byte VOICE, 59
	.byte VOL, 127
	.byte PAN, 64
	.byte W36
	.byte N24, 60, 96
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_167
song_167:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_167_track1
	.4byte song_167_track2
