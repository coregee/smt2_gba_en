@ song_116: m4a song, header 0x086BC94C
	.include "assets/sound/MPlayDef.inc"

	.global song_116_track1
song_116_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 16
	.byte VOL, 127
	.byte PAN, 64
	.byte N36, 60, 96
	.byte W36
	.byte FINE

	.byte 0x00
	.global song_116
song_116:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_116_track1
