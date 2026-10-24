@ song_125: m4a song, header 0x086BCA4C
	.include "assets/sound/MPlayDef.inc"

	.global song_125_track1
song_125_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 22
	.byte VOL, 127
	.byte PAN, 64
	.byte N05, 57, 104
	.byte W06
	.byte N36, 60
	.byte W36
	.byte FINE

	.byte 0x00, 0x00
	.global song_125
song_125:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_125_track1
