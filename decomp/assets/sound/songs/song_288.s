@ song_288: m4a song, header 0x086BD784
	.include "assets/sound/MPlayDef.inc"

	.global song_288_track1
song_288_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 8
	.byte VOL, 127
	.byte TIE, 57, 127
	.byte W96
	.byte W54
	.byte EOT
	.byte FINE

	.byte 0x00
	.global song_288
song_288:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_288_track1
