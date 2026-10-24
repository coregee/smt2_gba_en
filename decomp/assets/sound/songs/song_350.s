@ song_350: m4a song, header 0x086BE294
	.include "assets/sound/MPlayDef.inc"

	.global song_350_track1
song_350_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N02, 69, 80
	.byte W03
	.byte 73
	.byte W03
	.byte 76
	.byte W03
	.byte 81
	.byte W03
	.byte 85
	.byte W03
	.byte 88
	.byte W03
	.byte 93
	.byte W03
	.byte 88
	.byte W03
	.byte 97
	.byte W03
	.byte 93
	.byte W03
	.byte 88
	.byte W03
	.byte 97
	.byte W03
	.byte 93
	.byte W03
	.byte 88, 40
	.byte W03
	.byte 93
	.byte W03
	.byte 88
	.byte W03
	.byte 97
	.byte W03
	.byte FINE

	.byte 0x00, 0x00
	.global song_350
song_350:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_350_track1
