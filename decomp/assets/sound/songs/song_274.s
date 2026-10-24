@ song_274: m4a song, header 0x086BD730
	.include "assets/sound/MPlayDef.inc"

	.global song_274_track1
song_274_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 40
	.byte VOL, 127
	.byte N06, 50, 127
	.byte W06
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_274
song_274:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_274_track1
