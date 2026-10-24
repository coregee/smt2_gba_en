@ song_141: m4a song, header 0x086BCD44
	.include "assets/sound/MPlayDef.inc"

	.global song_141_track1
song_141_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 34
	.byte VOL, 127
	.byte PAN, 64
	.byte N18, 60, 104
	.byte W18
	.byte FINE

	.byte 0x00
	.global song_141
song_141:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_141_track1
