@ song_332: m4a song, header 0x086BDFAC
	.include "assets/sound/MPlayDef.inc"

	.global song_332_track1
song_332_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 27
	.byte VOL, 60
	.byte N72, 56, 127
	.byte W72
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_332
song_332:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_332_track1
