@ song_170: m4a song, header 0x086BD244
	.include "assets/sound/MPlayDef.inc"

	.global song_170_track1
song_170_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 61
	.byte VOL, 127
	.byte PAN, 64
	.byte N24, 60, 96
	.byte W24
	.byte FINE

	.global song_170_track2
song_170_track2:
	.byte KEYSH, 0
	.byte VOICE, 59
	.byte VOL, 127
	.byte PAN, 64
	.byte W23
	.byte N36, 57, 40
	.byte N36, 63, 64
	.byte W36
	.byte FINE

	.global song_170
song_170:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_170_track1
	.4byte song_170_track2
