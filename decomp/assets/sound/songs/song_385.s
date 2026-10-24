@ song_385: m4a song, header 0x086BE498
	.include "assets/sound/MPlayDef.inc"

	.global song_385_track1
song_385_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 60
	.byte N05, 60, 127
	.byte W06
	.byte N05
	.byte W06
	.byte N18
	.byte W18
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_385
song_385:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_385_track1
