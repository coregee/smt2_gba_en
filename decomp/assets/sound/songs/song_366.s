@ song_366: m4a song, header 0x086BE3A8
	.include "assets/sound/MPlayDef.inc"

	.global song_366_track1
song_366_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N02, 86, 80
	.byte W02
	.byte 85
	.byte W02
	.byte 84
	.byte W02
	.byte 83
	.byte W03
	.byte 86, 40
	.byte W02
	.byte 85
	.byte W02
	.byte 84
	.byte W02
	.byte 83
	.byte W02
	.byte FINE

	.global song_366
song_366:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_366_track1
