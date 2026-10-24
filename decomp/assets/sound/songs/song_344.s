@ song_344: m4a song, header 0x086BE188
	.include "assets/sound/MPlayDef.inc"

	.global song_344_track1
song_344_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 80
	.byte N03, 69, 64
	.byte N03, 74, 76
	.byte W01
	.byte 65, 64
	.byte W01
	.byte 60, 68
	.byte W01
	.byte 57, 64
	.byte W01
	.byte 52, 68
	.byte W03
	.byte FINE

	.global song_344
song_344:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_344_track1
