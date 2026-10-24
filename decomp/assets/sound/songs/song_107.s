@ song_107: m4a song, header 0x086BC82C
	.include "assets/sound/MPlayDef.inc"

	.global song_107_track1
song_107_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 7
	.byte VOL, 127
	.byte N24, 60, 127
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_107
song_107:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_107_track1
