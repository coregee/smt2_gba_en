@ song_145: m4a song, header 0x086BCDC0
	.include "assets/sound/MPlayDef.inc"

	.global song_145_track1
song_145_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 38
	.byte VOL, 127
	.byte PAN, 64
	.byte N24, 57, 127
	.byte W02
	.byte 62
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_145
song_145:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_145_track1
