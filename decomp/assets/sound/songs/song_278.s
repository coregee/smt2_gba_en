@ song_278: m4a song, header 0x086BD768
	.include "assets/sound/MPlayDef.inc"

	.global song_278_track1
song_278_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 7
	.byte VOL, 127
	.byte TIE, 58, 127
	.byte W96
	.byte W06
	.byte EOT
	.byte FINE

	.byte 0x00
	.global song_278
song_278:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_278_track1
