@ song_354: m4a song, header 0x086BE310
	.include "assets/sound/MPlayDef.inc"

	.global song_354_track1
song_354_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N02, 87, 80
	.byte W03
	.byte 76
	.byte W03
	.byte 87
	.byte W03
	.byte 76
	.byte W03
	.byte 87, 40
	.byte W03
	.byte 76
	.byte W03
	.byte FINE

	.global song_354
song_354:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_354_track1
