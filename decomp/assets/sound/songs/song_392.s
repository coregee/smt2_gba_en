@ song_392: m4a song, header 0x086BE4D0
	.include "assets/sound/MPlayDef.inc"

	.global song_392_track1
song_392_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 34
	.byte VOL, 127
	.byte N24, 60, 127
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_392
song_392:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_392_track1
