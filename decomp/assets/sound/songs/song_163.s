@ song_163: m4a song, header 0x086BD0E4
	.include "assets/sound/MPlayDef.inc"

	.global song_163_track1
song_163_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 44
	.byte VOL, 127
	.byte PAN, 64
	.byte N18, 60, 104
	.byte W18
	.byte FINE

	.global song_163_track2
song_163_track2:
	.byte KEYSH, 0
	.byte VOICE, 53
	.byte VOL, 127
	.byte PAN, 64
	.byte W15
	.byte N30, 60, 76
	.byte W30
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_163
song_163:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_163_track1
	.4byte song_163_track2
