@ song_143: m4a song, header 0x086BCD84
	.include "assets/sound/MPlayDef.inc"

	.global song_143_track1
song_143_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 36
	.byte VOL, 127
	.byte PAN, 64
	.byte N03, 60, 100
	.byte W04
	.byte N24
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_143
song_143:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_143_track1
