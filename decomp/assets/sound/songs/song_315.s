@ song_315: m4a song, header 0x086BDC80
	.include "assets/sound/MPlayDef.inc"

	.global song_315_track1
song_315_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 91
	.byte VOL, 80
	.byte BENDR, 12
	.byte BEND, 64
	.byte TIE, 57, 64
	.byte W23
	.byte BEND, 65
	.byte W01
	.byte 68
	.byte W01
	.byte 71
	.byte W02
	.byte 73
	.byte W01
	.byte 75
	.byte W01
	.byte 79
	.byte W01
	.byte 80
	.byte W01
	.byte 84
	.byte W01
	.byte 87
	.byte W01
	.byte 89
	.byte W01
	.byte 91
	.byte W02
	.byte 94
	.byte W02
	.byte 96
	.byte W02
	.byte 98
	.byte W01
	.byte 100
	.byte W01
	.byte 102
	.byte W01
	.byte 105
	.byte W02
	.byte 110
	.byte W01
	.byte 111
	.byte W01
	.byte 113
	.byte W01
	.byte 117
	.byte W01
	.byte 119
	.byte W01
	.byte 124
	.byte W01
	.byte 126
	.byte W01
	.byte 127
	.byte W44
	.byte W84
	.byte W02
	.byte EOT
	.byte W02
	.byte BEND, 64
	.byte W01
	.byte 64
	.byte W01
	.byte 65
	.byte W01
	.byte 64
	.byte FINE

	.global song_315_track2
song_315_track2:
	.byte KEYSH, 0
	.byte VOICE, 90
	.byte VOL, 50
	.byte BENDR, 12
	.byte BEND, 65
	.byte TIE, 57, 64
	.byte W23
	.byte BEND, 66
	.byte W01
	.byte 69
	.byte W01
	.byte 72
	.byte W02
	.byte 74
	.byte W01
	.byte 76
	.byte W01
	.byte 80
	.byte W01
	.byte 81
	.byte W01
	.byte 85
	.byte W01
	.byte 88
	.byte W01
	.byte 90
	.byte W01
	.byte 92
	.byte W02
	.byte 95
	.byte W02
	.byte 97
	.byte W02
	.byte 99
	.byte W01
	.byte 101
	.byte W01
	.byte 103
	.byte W01
	.byte 106
	.byte W02
	.byte 111
	.byte W01
	.byte 112
	.byte W01
	.byte 114
	.byte W01
	.byte 118
	.byte W01
	.byte 120
	.byte W01
	.byte 125
	.byte W01
	.byte 127
	.byte W01
	.byte 126
	.byte W44
	.byte W84
	.byte W02
	.byte EOT
	.byte W02
	.byte BEND, 65
	.byte W01
	.byte 65
	.byte W01
	.byte 66
	.byte W01
	.byte 65
	.byte FINE

	.global song_315_track3
song_315_track3:
	.byte KEYSH, 0
	.byte VOICE, 20
	.byte VOL, 80
	.byte W96
	.byte W90
	.byte N05, 57, 68
	.byte W05
	.byte N24, 69, 80
	.byte W01
	.byte W23
	.byte FINE

	.global song_315
song_315:
	.byte 3  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_002
	.4byte song_315_track1
	.4byte song_315_track2
	.4byte song_315_track3
