@ song_337: m4a song, header 0x086BE09C
	.include "assets/sound/MPlayDef.inc"

	.global song_337_track1
song_337_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 32
	.byte VOL, 127
	.byte N24, 60, 127
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_337
song_337:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_337_track1
