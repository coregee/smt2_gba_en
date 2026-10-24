@ song_193: m4a song, header 0x086BD43C
	.include "assets/sound/MPlayDef.inc"

	.global song_193_track1
song_193_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 58
	.byte VOL, 127
	.byte PAN, 64
	.byte N36, 54, 104
	.byte W36
	.byte FINE

	.global song_193_track2
song_193_track2:
	.byte KEYSH, 0
	.byte VOICE, 59
	.byte VOL, 127
	.byte PAN, 64
	.byte N36, 58, 72
	.byte W36
	.byte FINE

	.global song_193
song_193:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_193_track1
	.4byte song_193_track2
