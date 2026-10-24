@ song_330: m4a song, header 0x086BDF74
	.include "assets/sound/MPlayDef.inc"

	.global song_330_track1
song_330_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 25
	.byte VOL, 60
	.byte N96, 60, 127
	.byte W96
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_330
song_330:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_330_track1
