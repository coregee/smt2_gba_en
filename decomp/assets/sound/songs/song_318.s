@ song_318: m4a song, header 0x086BDDA8
	.include "assets/sound/MPlayDef.inc"

	.global song_318_track1
song_318_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 16
	.byte VOL, 127
	.byte TIE, 60, 127
	.byte W96
	.byte W96
	.byte W96
	.byte W24
	.byte EOT
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_318
song_318:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_318_track1
