@ song_171: m4a song, header 0x086BD274
	.include "assets/sound/MPlayDef.inc"

	.global song_171_track1
song_171_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 62
	.byte VOL, 127
	.byte PAN, 64
	.byte N24, 60, 96
	.byte W24
	.byte FINE

	.global song_171_track2
song_171_track2:
	.byte KEYSH, 0
	.byte VOICE, 63
	.byte VOL, 127
	.byte PAN, 64
	.byte W23
	.byte N36, 60, 100
	.byte W36
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_171
song_171:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_171_track1
	.4byte song_171_track2
