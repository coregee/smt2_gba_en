@ song_273: m4a song, header 0x086BD714
	.include "assets/sound/MPlayDef.inc"

	.global song_273_track1
song_273_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 5
	.byte VOL, 127
	.byte N30, 50, 127
	.byte W30
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_273
song_273:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_273_track1
