@ song_186: m4a song, header 0x086BD3A8
	.include "assets/sound/MPlayDef.inc"

	.global song_186_track1
song_186_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 59
	.byte VOL, 127
	.byte PAN, 64
	.byte N06, 60, 104
	.byte W06
	.byte N24
	.byte W06
	.byte N06, 59, 48
	.byte W06
	.byte N24, 58, 32
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_186
song_186:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_186_track1
