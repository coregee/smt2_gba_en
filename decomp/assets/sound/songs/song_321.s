@ song_321: m4a song, header 0x086BDE64
	.include "assets/sound/MPlayDef.inc"

	.global song_321_track1
song_321_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 19
	.byte VOL, 127
	.byte N96, 60, 127
	.byte W96
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_321
song_321:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_321_track1
