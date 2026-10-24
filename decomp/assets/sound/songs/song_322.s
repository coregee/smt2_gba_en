@ song_322: m4a song, header 0x086BDE80
	.include "assets/sound/MPlayDef.inc"

	.global song_322_track1
song_322_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 20
	.byte VOL, 100
	.byte N96, 60, 112
	.byte W96
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_322
song_322:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_322_track1
