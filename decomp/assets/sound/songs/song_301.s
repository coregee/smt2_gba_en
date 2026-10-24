@ song_301: m4a song, header 0x086BD830
	.include "assets/sound/MPlayDef.inc"

	.global song_301_track1
song_301_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 75
	.byte VOL, 127
	.byte PAN, 64
	.byte N36, 60, 96
	.byte W36
	.byte FINE

	.byte 0x00
	.global song_301
song_301:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_301_track1
