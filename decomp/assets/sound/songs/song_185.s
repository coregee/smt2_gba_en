@ song_185: m4a song, header 0x086BD380
	.include "assets/sound/MPlayDef.inc"

	.global song_185_track1
song_185_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 58
	.byte VOL, 127
	.byte PAN, 64
	.byte N06, 60, 104
	.byte W06
	.byte N12
	.byte W06
	.byte 59, 48
	.byte W06
	.byte 58, 32
	.byte W12
	.byte FINE

	.byte 0x00
	.global song_185
song_185:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_185_track1
