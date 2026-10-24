@ song_168: m4a song, header 0x086BD1F8
	.include "assets/sound/MPlayDef.inc"

	.global song_168_track1
song_168_track1:
	.byte KEYSH, 0
	.byte TEMPO, 56
	.byte VOICE, 58
	.byte VOL, 127
	.byte PAN, 64
	.byte N09, 60, 88
	.byte W09
	.byte N09
	.byte W09
	.byte N09
	.byte W09
	.byte N09
	.byte W09
	.byte N09
	.byte W09
	.byte N09
	.byte W09
	.byte N09
	.byte W09
	.byte N09
	.byte W09
	.byte FINE

	.global song_168_track2
song_168_track2:
	.byte KEYSH, 0
	.byte VOICE, 59
	.byte VOL, 127
	.byte PAN, 64
	.byte W72
	.byte N48, 54, 72
	.byte N24, 60, 96
	.byte W24
	.byte W24
	.byte FINE

	.byte 0x00
	.global song_168
song_168:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_168_track1
	.4byte song_168_track2
