@ song_394: m4a song, header 0x086BE508
	.include "assets/sound/MPlayDef.inc"

	.global song_394_track1
song_394_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 36
	.byte VOL, 127
	.byte N42, 60, 127
	.byte W42
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_394
song_394:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_394_track1
