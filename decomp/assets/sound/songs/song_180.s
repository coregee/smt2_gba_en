@ song_180: m4a song, header 0x086BD338
	.include "assets/sound/MPlayDef.inc"

	.global song_180_track1
song_180_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 6
	.byte VOL, 63
	.byte N18, 35, 127
	.byte W18
	.byte FINE

	.global song_180_track2
song_180_track2:
	.byte KEYSH, 0
	.byte VOICE, 23
	.byte VOL, 70
	.byte N02, 51, 127
	.byte W03
	.byte 54
	.byte W03
	.byte 60
	.byte W03
	.byte N24, 69
	.byte W24
	.byte FINE

	.byte 0x00
	.global song_180
song_180:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_002
	.4byte song_180_track1
	.4byte song_180_track2
