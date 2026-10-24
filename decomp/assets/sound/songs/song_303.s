@ song_303: m4a song, header 0x086BD868
	.include "assets/sound/MPlayDef.inc"

	.global song_303_track1
song_303_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 76
	.byte VOL, 127
	.byte PAN, 64
	.byte N32, 60, 92
	.byte W32
	.byte W01
	.byte FINE

	.global song_303
song_303:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_303_track1
