@ song_166: m4a song, header 0x086BD178
	.include "assets/sound/MPlayDef.inc"

	.global song_166_track1
song_166_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 55
	.byte VOL, 127
	.byte PAN, 64
	.byte N30, 60, 96
	.byte W01
	.byte 63, 72
	.byte W30
	.byte FINE

	.global song_166_track2
song_166_track2:
	.byte KEYSH, 0
	.byte VOICE, 57
	.byte VOL, 127
	.byte PAN, 64
	.byte W24
	.byte W03
	.byte N48, 57, 96
	.byte W48
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_166
song_166:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_166_track1
	.4byte song_166_track2
