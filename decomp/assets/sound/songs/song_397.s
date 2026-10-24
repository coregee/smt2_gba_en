@ song_397: m4a song, header 0x086BE55C
	.include "assets/sound/MPlayDef.inc"

	.global song_397_track1
song_397_track1:
	.byte KEYSH, 0
	.byte TEMPO, 58
	.byte VOICE, 36
	.byte VOL, 127
	.byte N48, 60, 120
	.byte W48
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_397
song_397:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_000
	.4byte song_397_track1
