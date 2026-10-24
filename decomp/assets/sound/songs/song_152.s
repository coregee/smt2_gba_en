@ song_152: m4a song, header 0x086BCEEC
	.include "assets/sound/MPlayDef.inc"

	.global song_152_track1
song_152_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 42
	.byte VOL, 127
	.byte PAN, 64
	.byte N60, 49, 112
	.byte W60
	.byte FINE

	.global song_152_track2
song_152_track2:
	.byte KEYSH, 0
	.byte VOICE, 43
	.byte VOL, 127
	.byte PAN, 64
	.byte W05
	.byte N48, 54, 96
	.byte W48
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_152
song_152:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_152_track1
	.4byte song_152_track2
