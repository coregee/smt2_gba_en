@ song_151: m4a song, header 0x086BCEBC
	.include "assets/sound/MPlayDef.inc"

	.global song_151_track1
song_151_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 42
	.byte VOL, 127
	.byte PAN, 64
	.byte W01
	.byte N01, 55, 80
	.byte W02
	.byte N01
	.byte W01
	.byte N01
	.byte W02
	.byte N01
	.byte W01
	.byte N01
	.byte W02
	.byte N01
	.byte W01
	.byte N01
	.byte W02
	.byte TIE, 55, 127
	.byte W84
	.byte W60
	.byte EOT
	.byte FINE

	.global song_151_track2
song_151_track2:
	.byte KEYSH, 0
	.byte VOICE, 43
	.byte VOL, 127
	.byte PAN, 64
	.byte W04
	.byte N05, 57, 127
	.byte W06
	.byte 57, 100
	.byte W06
	.byte N12, 57, 127
	.byte W12
	.byte N48, 57, 80
	.byte W48
	.byte FINE

	.byte 0x00
	.global song_151
song_151:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_151_track1
	.4byte song_151_track2
