@ song_297: m4a song, header 0x086BD7DC
	.include "assets/sound/MPlayDef.inc"

	.global song_297_track1
song_297_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 20
	.byte VOL, 127
	.byte N05, 55, 127
	.byte W06
	.byte 55, 112
	.byte W06
	.byte 55, 84
	.byte W06
	.byte 55, 60
	.byte W06
	.byte 55, 44
	.byte W06
	.byte N06, 55, 20
	.byte W06
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_297
song_297:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_297_track1
