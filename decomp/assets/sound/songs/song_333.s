@ song_333: m4a song, header 0x086BDFC8
	.include "assets/sound/MPlayDef.inc"

	.global song_333_track1
song_333_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 28
	.byte VOL, 60
	.byte TIE, 60, 127
	.byte W96
	.byte W96
	.byte W48
	.byte EOT
	.byte FINE

	.global song_333
song_333:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_333_track1
