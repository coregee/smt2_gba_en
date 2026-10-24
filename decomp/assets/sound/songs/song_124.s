@ song_124: m4a song, header 0x086BCA2C
	.include "assets/sound/MPlayDef.inc"

	.global song_124_track1
song_124_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 24
	.byte VOL, 127
	.byte PAN, 64
	.byte N30, 60, 104
	.byte W30
	.byte FINE

	.byte 0x00
	.global song_124
song_124:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_124_track1
