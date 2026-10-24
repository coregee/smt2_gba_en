@ song_150: m4a song, header 0x086BCE70
	.include "assets/sound/MPlayDef.inc"

	.global song_150_track1
song_150_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 42
	.byte VOL, 127
	.byte PAN, 64
	.byte W24
	.byte W03
	.byte N30, 61, 104
	.byte W30
	.byte FINE

	.global song_150_track2
song_150_track2:
	.byte KEYSH, 0
	.byte VOICE, 43
	.byte VOL, 127
	.byte PAN, 64
	.byte N30, 59, 104
	.byte W30
	.byte FINE

	.byte 0x00, 0x00
	.global song_150
song_150:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_150_track1
	.4byte song_150_track2
