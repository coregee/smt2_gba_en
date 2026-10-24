@ song_251: m4a song, header 0x086BD528
	.include "assets/sound/MPlayDef.inc"

	.global song_251_track1
song_251_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 31
	.byte VOL, 84
	.byte N01, 57, 127
	.byte W02
	.byte N21, 60
	.byte W32
	.byte W02
	.byte N01, 57
	.byte W02
	.byte N28, 60
	.byte W32
	.byte W02
	.byte N01, 57
	.byte W02
	.byte N21, 60
	.byte W21
	.byte FINE

	.byte 0x00, 0x00
	.global song_251
song_251:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_251_track1
