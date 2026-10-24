@ song_266: m4a song, header 0x086BD644
	.include "assets/sound/MPlayDef.inc"

	.global song_266_track1
song_266_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 127
	.byte TIE, 54, 127
	.byte W96
	.byte W48
	.byte EOT
	.byte FINE

	.byte 0x00
	.global song_266
song_266:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_266_track1
