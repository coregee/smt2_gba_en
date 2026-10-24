@ song_109: m4a song, header 0x086BC864
	.include "assets/sound/MPlayDef.inc"

	.global song_109_track1
song_109_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 9
	.byte VOL, 127
	.byte N72, 60, 127
	.byte W72
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_109
song_109:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_109_track1
