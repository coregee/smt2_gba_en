@ song_336: m4a song, header 0x086BE080
	.include "assets/sound/MPlayDef.inc"

	.global song_336_track1
song_336_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 31
	.byte VOL, 127
	.byte N24, 60, 127
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_336
song_336:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_336_track1
