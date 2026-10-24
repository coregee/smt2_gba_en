@ song_329: m4a song, header 0x086BDF58
	.include "assets/sound/MPlayDef.inc"

	.global song_329_track1
song_329_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 60
	.byte N02, 64, 127
	.byte W03
	.byte 71
	.byte W03
	.byte 78
	.byte W06
	.byte 64, 20
	.byte W03
	.byte 71
	.byte W03
	.byte 78
	.byte W02
	.byte FINE

	.global song_329
song_329:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_329_track1
