@ song_158: m4a song, header 0x086BD014
	.include "assets/sound/MPlayDef.inc"

	.global song_158_track1
song_158_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 48
	.byte VOL, 127
	.byte PAN, 64
	.byte N18, 58, 88
	.byte W18
	.byte FINE

	.global song_158_track2
song_158_track2:
	.byte KEYSH, 0
	.byte VOICE, 50
	.byte VOL, 127
	.byte PAN, 64
	.byte W15
	.byte N06, 60, 88
	.byte W06
	.byte N48
	.byte W48
	.byte FINE

	.byte 0x00
	.global song_158
song_158:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_158_track1
	.4byte song_158_track2
