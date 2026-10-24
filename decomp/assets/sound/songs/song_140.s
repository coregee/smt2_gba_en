@ song_140: m4a song, header 0x086BCD28
	.include "assets/sound/MPlayDef.inc"

	.global song_140_track1
song_140_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 33
	.byte VOL, 127
	.byte PAN, 64
	.byte N24, 62, 127
	.byte W24
	.byte FINE

	.byte 0x00
	.global song_140
song_140:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_140_track1
