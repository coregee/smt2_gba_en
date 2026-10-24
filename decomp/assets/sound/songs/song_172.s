@ song_172: m4a song, header 0x086BD2B0
	.include "assets/sound/MPlayDef.inc"

	.global song_172_track1
song_172_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 62
	.byte VOL, 127
	.byte PAN, 64
	.byte W24
	.byte N06, 60, 96
	.byte W06
	.byte FINE

	.global song_172_track2
song_172_track2:
	.byte KEYSH, 0
	.byte VOICE, 63
	.byte VOL, 127
	.byte PAN, 64
	.byte W30
	.byte N36, 60, 104
	.byte W36
	.byte FINE

	.global song_172_track3
song_172_track3:
	.byte KEYSH, 0
	.byte VOICE, 64
	.byte VOL, 127
	.byte PAN, 64
	.byte N24, 60, 96
	.byte W24
	.byte FINE

	.byte 0x00
	.global song_172
song_172:
	.byte 3  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_172_track1
	.4byte song_172_track2
	.4byte song_172_track3
