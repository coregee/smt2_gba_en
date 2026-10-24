@ song_139: m4a song, header 0x086BCD0C
	.include "assets/sound/MPlayDef.inc"

	.global song_139_track1
song_139_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 32
	.byte VOL, 127
	.byte PAN, 64
	.byte N24, 60, 100
	.byte W24
	.byte FINE

	.byte 0x00
	.global song_139
song_139:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_139_track1
