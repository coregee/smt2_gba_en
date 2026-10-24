@ song_137: m4a song, header 0x086BCCD0
	.include "assets/sound/MPlayDef.inc"

	.global song_137_track1
song_137_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 28
	.byte VOL, 127
	.byte PAN, 64
	.byte N12, 57, 127
	.byte W02
	.byte N01, 60
	.byte W02
	.byte N07, 62
	.byte W08
	.byte N24, 62, 40
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_137
song_137:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_137_track1
