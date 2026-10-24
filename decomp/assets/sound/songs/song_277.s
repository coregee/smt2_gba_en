@ song_277: m4a song, header 0x086BD74C
	.include "assets/sound/MPlayDef.inc"

	.global song_277_track1
song_277_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 6
	.byte VOL, 127
	.byte N54, 60, 127
	.byte W54
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_277
song_277:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_277_track1
