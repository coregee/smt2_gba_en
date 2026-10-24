@ song_101: m4a song, header 0x086BC784
	.include "assets/sound/MPlayDef.inc"

	.global song_101_track1
song_101_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 90
	.byte N12, 60, 127
	.byte W12
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_101
song_101:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_101_track1
