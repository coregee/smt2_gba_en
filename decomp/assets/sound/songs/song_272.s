@ song_272: m4a song, header 0x086BD6F4
	.include "assets/sound/MPlayDef.inc"

	.global song_272_track1
song_272_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 4
	.byte VOL, 127
	.byte N23, 60, 127
	.byte W24
	.byte N24, 60, 80
	.byte W24
	.byte 60, 52
	.byte W24
	.byte FINE

	.global song_272_track2
song_272_track2:
	.byte KEYSH, 0
	.byte VOICE, 23
	.byte VOL, 20
	.byte N12, 60, 120
	.byte W24
	.byte 60, 104
	.byte W24
	.byte 60, 96
	.byte W12
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_272
song_272:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_272_track1
	.4byte song_272_track2
