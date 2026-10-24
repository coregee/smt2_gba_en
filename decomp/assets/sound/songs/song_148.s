@ song_148: m4a song, header 0x086BCE14
	.include "assets/sound/MPlayDef.inc"

	.global song_148_track1
song_148_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 41
	.byte VOL, 127
	.byte PAN, 64
	.byte N18, 60, 124
	.byte W18
	.byte FINE

	.byte 0x00
	.global song_148
song_148:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_148_track1
