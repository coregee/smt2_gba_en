@ song_115: m4a song, header 0x086BC930
	.include "assets/sound/MPlayDef.inc"

	.global song_115_track1
song_115_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 15
	.byte VOL, 127
	.byte PAN, 64
	.byte N18, 60, 88
	.byte W18
	.byte FINE

	.byte 0x00
	.global song_115
song_115:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_115_track1
