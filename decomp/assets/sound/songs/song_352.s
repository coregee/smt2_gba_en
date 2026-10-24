@ song_352: m4a song, header 0x086BE2EC
	.include "assets/sound/MPlayDef.inc"

	.global song_352_track1
song_352_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N02, 87, 80
	.byte W03
	.byte 80
	.byte W03
	.byte 83
	.byte W03
	.byte 75
	.byte W03
	.byte 80
	.byte W03
	.byte 71
	.byte W03
	.byte 75
	.byte W03
	.byte 68
	.byte W03
	.byte 75, 40
	.byte W03
	.byte 68
	.byte W03
	.byte FINE

	.global song_352
song_352:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_352_track1
