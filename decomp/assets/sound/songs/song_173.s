@ song_173: m4a song, header 0x086BD2E0
	.include "assets/sound/MPlayDef.inc"

	.global song_173_track1
song_173_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 20
	.byte VOL, 80
	.byte N02, 56, 127
	.byte W03
	.byte 61
	.byte W03
	.byte 56
	.byte W03
	.byte 61
	.byte W03
	.byte 56
	.byte W03
	.byte 61
	.byte W03
	.byte 56
	.byte W03
	.byte N03, 61
	.byte W03
	.byte FINE

	.global song_173
song_173:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_002
	.4byte song_173_track1
