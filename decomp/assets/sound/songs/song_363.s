@ song_363: m4a song, header 0x086BE380
	.include "assets/sound/MPlayDef.inc"

	.global song_363_track1
song_363_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N02, 86, 80
	.byte W03
	.byte N02
	.byte W03
	.byte N02
	.byte W03
	.byte 86, 40
	.byte W03
	.byte 86, 20
	.byte W03
	.byte FINE

	.byte 0x00
	.global song_363
song_363:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_363_track1
