@ song_396: m4a song, header 0x086BE540
	.include "assets/sound/MPlayDef.inc"

	.global song_396_track1
song_396_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 38
	.byte VOL, 127
	.byte N54, 60, 127
	.byte W54
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_396
song_396:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_396_track1
