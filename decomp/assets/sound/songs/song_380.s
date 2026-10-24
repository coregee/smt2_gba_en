@ song_380: m4a song, header 0x086BE45C
	.include "assets/sound/MPlayDef.inc"

	.global song_380_track1
song_380_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 39
	.byte VOL, 127
	.byte N24, 60, 127
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_380
song_380:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_380_track1
