@ song_349: m4a song, header 0x086BE258
	.include "assets/sound/MPlayDef.inc"

	.global song_349_track1
song_349_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 51
	.byte N03, 60, 80
	.byte W01
	.byte 62
	.byte W02
	.byte 64
	.byte W01
	.byte 84
	.byte W02
	.byte 72
	.byte W01
	.byte 76
	.byte W02
	.byte N01, 84
	.byte W01
	.byte N03, 84, 40
	.byte W02
	.byte 72
	.byte W01
	.byte 76
	.byte W02
	.byte N01, 84
	.byte W01
	.byte N03, 84, 20
	.byte W02
	.byte 72
	.byte W01
	.byte 76
	.byte W02
	.byte 84
	.byte W03
	.byte FINE

	.byte 0x00
	.global song_349
song_349:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_004
	.4byte song_349_track1
