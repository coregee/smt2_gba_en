@ song_165: m4a song, header 0x086BD144
	.include "assets/sound/MPlayDef.inc"

	.global song_165_track1
song_165_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 55
	.byte VOL, 127
	.byte PAN, 64
	.byte N30, 60, 104
	.byte W30
	.byte FINE

	.global song_165_track2
song_165_track2:
	.byte KEYSH, 0
	.byte VOICE, 56
	.byte VOL, 127
	.byte PAN, 64
	.byte W24
	.byte W03
	.byte N30, 60, 100
	.byte W30
	.byte FINE

	.byte 0x00, 0x00
	.global song_165
song_165:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_165_track1
	.4byte song_165_track2
