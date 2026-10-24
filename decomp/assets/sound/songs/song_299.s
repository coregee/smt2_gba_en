@ song_299: m4a song, header 0x086BD7F8
	.include "assets/sound/MPlayDef.inc"

	.global song_299_track1
song_299_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 73
	.byte VOL, 127
	.byte PAN, 64
	.byte N18, 60, 96
	.byte W18
	.byte FINE

	.byte 0x00
	.global song_299
song_299:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_299_track1
