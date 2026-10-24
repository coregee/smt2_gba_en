@ song_112: m4a song, header 0x086BC8DC
	.include "assets/sound/MPlayDef.inc"

	.global song_112_track1
song_112_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 12
	.byte VOL, 127
	.byte PAN, 64
	.byte W03
	.byte N48, 60, 88
	.byte W48
	.byte FINE

	.global song_112
song_112:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_112_track1
