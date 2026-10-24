@ song_164: m4a song, header 0x086BD114
	.include "assets/sound/MPlayDef.inc"

	.global song_164_track1
song_164_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 45
	.byte VOL, 127
	.byte PAN, 64
	.byte N18, 60, 104
	.byte W18
	.byte FINE

	.global song_164_track2
song_164_track2:
	.byte KEYSH, 0
	.byte VOICE, 54
	.byte VOL, 127
	.byte PAN, 64
	.byte W15
	.byte N30, 60, 92
	.byte W30
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_164
song_164:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_164_track1
	.4byte song_164_track2
