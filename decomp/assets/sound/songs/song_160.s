@ song_160: m4a song, header 0x086BD07C
	.include "assets/sound/MPlayDef.inc"

	.global song_160_track1
song_160_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 49
	.byte VOL, 127
	.byte PAN, 64
	.byte N06, 61, 96
	.byte W06
	.byte N30
	.byte W30
	.byte FINE

	.global song_160_track2
song_160_track2:
	.byte KEYSH, 0
	.byte VOICE, 50
	.byte VOL, 127
	.byte PAN, 64
	.byte W03
	.byte N06, 54, 88
	.byte W06
	.byte N42
	.byte W42
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_160
song_160:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_160_track1
	.4byte song_160_track2
