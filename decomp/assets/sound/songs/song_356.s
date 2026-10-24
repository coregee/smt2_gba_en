@ song_356: m4a song, header 0x086BE35C
	.include "assets/sound/MPlayDef.inc"

	.global song_356_track1
song_356_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N02, 79, 80
	.byte W02
	.byte 85
	.byte W02
	.byte 90
	.byte W02
	.byte 79, 40
	.byte W02
	.byte 85
	.byte W02
	.byte 90
	.byte W02
	.byte FINE

	.global song_356
song_356:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_356_track1
