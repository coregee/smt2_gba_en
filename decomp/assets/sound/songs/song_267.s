@ song_267: m4a song, header 0x086BD660
	.include "assets/sound/MPlayDef.inc"

	.global song_267_track1
song_267_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 127
	.byte N72, 60, 127
	.byte W72
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_267
song_267:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_267_track1
