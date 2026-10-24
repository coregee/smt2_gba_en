@ song_370: m4a song, header 0x086BE440
	.include "assets/sound/MPlayDef.inc"

	.global song_370_track1
song_370_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N02, 78, 80
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W04
	.byte 78
	.byte W02
	.byte 85
	.byte W02
	.byte FINE

	.byte 0x00
	.global song_370
song_370:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_370_track1
