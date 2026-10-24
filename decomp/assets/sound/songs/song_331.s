@ song_331: m4a song, header 0x086BDF90
	.include "assets/sound/MPlayDef.inc"

	.global song_331_track1
song_331_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 26
	.byte VOL, 60
	.byte N36, 55, 127
	.byte W36
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_331
song_331:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_331_track1
