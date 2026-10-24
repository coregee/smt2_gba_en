@ song_183: m4a song, header 0x086BD35C
	.include "assets/sound/MPlayDef.inc"

	.global song_183_track1
song_183_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 44
	.byte VOL, 70
	.byte N11, 59, 127
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W11
	.byte N32
	.byte W32
	.byte W01
	.byte FINE

	.global song_183
song_183:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_002
	.4byte song_183_track1
