@ song_338: m4a song, header 0x086BE0BC
	.include "assets/sound/MPlayDef.inc"

	.global song_338_track1
song_338_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 88
	.byte VOL, 127
	.byte PAN, 64
	.byte TIE, 60, 112
	.byte W96
	.byte W48
	.byte EOT
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_338
song_338:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_338_track1
