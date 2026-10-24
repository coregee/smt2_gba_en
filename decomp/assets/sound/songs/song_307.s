@ song_307: m4a song, header 0x086BD8DC
	.include "assets/sound/MPlayDef.inc"

	.global song_307_track1
song_307_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 91
	.byte VOL, 60
	.byte TIE, 79, 80
	.byte W96
	.byte W96
	.byte W96
	.byte EOT
	.byte FINE

	.global song_307_track2
song_307_track2:
	.byte KEYSH, 0
	.byte VOICE, 90
	.byte VOL, 30
	.byte BEND, 68
	.byte TIE, 79, 80
	.byte W96
	.byte W96
	.byte W96
	.byte EOT
	.byte FINE

	.global song_307_track3
song_307_track3:
	.byte KEYSH, 0
	.byte VOICE, 100
	.byte VOL, 120
	.byte TIE, 48, 80
	.byte W96
	.byte W84
	.byte W03
	.byte EOT
	.byte FINE

	.byte 0x00, 0x00
	.global song_307
song_307:
	.byte 3  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_307_track1
	.4byte song_307_track2
	.4byte song_307_track3
