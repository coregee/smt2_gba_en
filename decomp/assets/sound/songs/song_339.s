@ song_339: m4a song, header 0x086BE0D8
	.include "assets/sound/MPlayDef.inc"

	.global song_339_track1
song_339_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 89
	.byte VOL, 127
	.byte PAN, 64
	.byte N48, 60, 96
	.byte W48
	.byte FINE

	.byte 0x00
	.global song_339
song_339:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_339_track1
