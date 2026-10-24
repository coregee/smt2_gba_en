@ song_328: m4a song, header 0x086BDF34
	.include "assets/sound/MPlayDef.inc"

	.global song_328_track1
song_328_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 60
	.byte N05, 45, 127
	.byte W06
	.byte N05
	.byte W06
	.byte N05
	.byte W05
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_328
song_328:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_328_track1
