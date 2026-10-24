@ song_260: m4a song, header 0x086BD628
	.include "assets/sound/MPlayDef.inc"

	.global song_260_track1
song_260_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 51
	.byte VOL, 127
	.byte N03, 69, 127
	.byte W03
	.byte 67
	.byte W03
	.byte 65
	.byte W03
	.byte 64
	.byte W03
	.byte 62
	.byte W03
	.byte 60
	.byte W03
	.byte 59
	.byte W03
	.byte 57
	.byte W03
	.byte 55
	.byte W03
	.byte 53
	.byte W03
	.byte 52
	.byte W03
	.byte 50
	.byte W03
	.byte 48
	.byte W03
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_260
song_260:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_260_track1
