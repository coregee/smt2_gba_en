@ song_194: m4a song, header 0x086BD468
	.include "assets/sound/MPlayDef.inc"

	.global song_194_track1
song_194_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 58
	.byte VOL, 127
	.byte PAN, 64
	.byte N36, 47, 104
	.byte W36
	.byte FINE

	.global song_194_track2
song_194_track2:
	.byte KEYSH, 0
	.byte VOICE, 59
	.byte VOL, 127
	.byte PAN, 64
	.byte N36, 48, 72
	.byte W36
	.byte FINE

	.global song_194
song_194:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_194_track1
	.4byte song_194_track2
