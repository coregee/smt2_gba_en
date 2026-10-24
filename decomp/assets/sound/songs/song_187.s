@ song_187: m4a song, header 0x086BD3DC
	.include "assets/sound/MPlayDef.inc"

	.global song_187_track1
song_187_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 20
	.byte VOL, 70
	.byte N04, 60, 127
	.byte W04
	.byte 64
	.byte W05
	.byte 64, 100
	.byte W04
	.byte 64, 92
	.byte W05
	.byte 64, 80
	.byte W04
	.byte 64, 72
	.byte W05
	.byte 64, 60
	.byte W04
	.byte 64, 40
	.byte W05
	.byte N22, 64, 20
	.byte W22
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_187
song_187:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_002
	.4byte song_187_track1
