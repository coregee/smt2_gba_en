@ song_118: m4a song, header 0x086BC984
	.include "assets/sound/MPlayDef.inc"

	.global song_118_track1
song_118_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 18
	.byte VOL, 127
	.byte N48, 60, 127
	.byte W48
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_118
song_118:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_118_track1
