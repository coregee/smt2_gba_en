@ song_136: m4a song, header 0x086BCCA8
	.include "assets/sound/MPlayDef.inc"

	.global song_136_track1
song_136_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 28
	.byte VOL, 127
	.byte PAN, 64
	.byte N02, 58, 104
	.byte W03
	.byte N18, 62, 127
	.byte W18
	.byte FINE

	.byte 0x00
	.global song_136
song_136:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_136_track1
