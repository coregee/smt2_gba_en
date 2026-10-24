@ song_270: m4a song, header 0x086BD6C0
	.include "assets/sound/MPlayDef.inc"

	.global song_270_track1
song_270_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 127
	.byte N05, 54, 127
	.byte W06
	.byte N12, 50
	.byte W06
	.byte N05, 54
	.byte W06
	.byte N12, 50
	.byte W06
	.byte N05, 54, 60
	.byte W06
	.byte N12, 50
	.byte W06
	.byte N05, 54
	.byte W06
	.byte N12, 50
	.byte W12
	.byte FINE

	.byte 0x00
	.global song_270
song_270:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_270_track1
