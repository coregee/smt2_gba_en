@ song_302: m4a song, header 0x086BD84C
	.include "assets/sound/MPlayDef.inc"

	.global song_302_track1
song_302_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 75
	.byte VOL, 127
	.byte PAN, 64
	.byte N36, 63, 92
	.byte W36
	.byte FINE

	.byte 0x00
	.global song_302
song_302:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_302_track1
