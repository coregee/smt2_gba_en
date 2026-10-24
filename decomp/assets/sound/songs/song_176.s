@ song_176: m4a song, header 0x086BD308
	.include "assets/sound/MPlayDef.inc"

	.global song_176_track1
song_176_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 6
	.byte VOL, 80
	.byte N18, 24, 127
	.byte W18
	.byte FINE

	.global song_176_track2
song_176_track2:
	.byte KEYSH, 0
	.byte VOICE, 20
	.byte VOL, 80
	.byte W06
	.byte N12, 56, 127
	.byte W12
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_176
song_176:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_002
	.4byte song_176_track1
	.4byte song_176_track2
