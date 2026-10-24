@ song_117: m4a song, header 0x086BC968
	.include "assets/sound/MPlayDef.inc"

	.global song_117_track1
song_117_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 17
	.byte VOL, 127
	.byte PAN, 64
	.byte N18, 60, 96
	.byte W18
	.byte FINE

	.byte 0x00
	.global song_117
song_117:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_117_track1
