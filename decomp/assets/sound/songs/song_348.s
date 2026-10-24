@ song_348: m4a song, header 0x086BE21C
	.include "assets/sound/MPlayDef.inc"

	.global song_348_track1
song_348_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N01, 74, 72
	.byte W02
	.byte 71
	.byte W02
	.byte 80
	.byte W02
	.byte 82
	.byte W04
	.byte 74, 36
	.byte W02
	.byte 71
	.byte W02
	.byte 80
	.byte W02
	.byte 82
	.byte W01
	.byte FINE

	.global song_348
song_348:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_348_track1
