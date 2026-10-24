@ song_340: m4a song, header 0x086BE0F8
	.include "assets/sound/MPlayDef.inc"

	.global song_340_track1
song_340_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 84
	.byte VOL, 127
	.byte PAN, 64
	.byte N90, 60, 96
	.byte N42, 66, 72
	.byte W90
	.byte FINE

	.byte 0x00, 0x00
	.global song_340
song_340:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_340_track1
