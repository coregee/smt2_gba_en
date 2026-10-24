@ song_106: m4a song, header 0x086BC810
	.include "assets/sound/MPlayDef.inc"

	.global song_106_track1
song_106_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 6
	.byte VOL, 127
	.byte PAN, 64
	.byte N13, 60, 96
	.byte W14
	.byte FINE

	.byte 0x00
	.global song_106
song_106:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_106_track1
