@ song_296: m4a song, header 0x086BD7B0
	.include "assets/sound/MPlayDef.inc"

	.global song_296_track1
song_296_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 20
	.byte VOL, 127
	.byte N05, 69, 127
	.byte W06
	.byte 69, 112
	.byte W06
	.byte 69, 84
	.byte W06
	.byte 69, 60
	.byte W06
	.byte 69, 44
	.byte W06
	.byte N06, 69, 20
	.byte W06
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_296
song_296:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_296_track1
