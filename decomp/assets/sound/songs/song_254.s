@ song_254: m4a song, header 0x086BD588
	.include "assets/sound/MPlayDef.inc"

	.global song_254_track1
song_254_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 67
	.byte VOL, 127
	.byte N80, 47, 127
	.byte W80
	.byte W01
	.byte FINE

	.global song_254_track2
song_254_track2:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 85
	.byte N44, 47, 40
	.byte W44
	.byte W01
	.byte FINE

	.byte 0x00, 0x00
	.global song_254
song_254:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_254_track1
	.4byte song_254_track2
