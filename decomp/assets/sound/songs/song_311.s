@ song_311: m4a song, header 0x086BDAC0
	.include "assets/sound/MPlayDef.inc"

	.global song_311_track1
song_311_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 9
	.byte VOL, 127
	.byte TIE, 60, 127
	.byte W96
	.byte W96
	.byte EOT
	.byte FINE

	.byte 0x00
	.global song_311
song_311:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_311_track1
