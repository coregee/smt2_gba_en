@ song_155: m4a song, header 0x086BCF80
	.include "assets/sound/MPlayDef.inc"

	.global song_155_track1
song_155_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 45
	.byte VOL, 127
	.byte PAN, 64
	.byte N24, 57, 88
	.byte W09
	.byte N21, 61, 127
	.byte W21
	.byte FINE

	.global song_155_track2
song_155_track2:
	.byte KEYSH, 0
	.byte VOICE, 47
	.byte VOL, 127
	.byte PAN, 64
	.byte W24
	.byte N06, 60, 127
	.byte W06
	.byte N48, 62
	.byte W48
	.byte FINE

	.global song_155
song_155:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_155_track1
	.4byte song_155_track2
