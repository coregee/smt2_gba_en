@ song_147: m4a song, header 0x086BCDF8
	.include "assets/sound/MPlayDef.inc"

	.global song_147_track1
song_147_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 40
	.byte VOL, 127
	.byte PAN, 64
	.byte N30, 60, 124
	.byte W30
	.byte FINE

	.byte 0x00
	.global song_147
song_147:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_147_track1
