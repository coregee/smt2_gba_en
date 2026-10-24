@ song_154: m4a song, header 0x086BCF4C
	.include "assets/sound/MPlayDef.inc"

	.global song_154_track1
song_154_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 45
	.byte VOL, 127
	.byte PAN, 64
	.byte N30, 60, 100
	.byte W30
	.byte FINE

	.global song_154_track2
song_154_track2:
	.byte KEYSH, 0
	.byte VOICE, 46
	.byte VOL, 127
	.byte PAN, 64
	.byte W24
	.byte W03
	.byte N48, 60, 100
	.byte W48
	.byte FINE

	.byte 0x00, 0x00
	.global song_154
song_154:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_154_track1
	.4byte song_154_track2
