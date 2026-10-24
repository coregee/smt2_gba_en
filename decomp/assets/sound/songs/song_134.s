@ song_134: m4a song, header 0x086BCC5C
	.include "assets/sound/MPlayDef.inc"

	.global song_134_track1
song_134_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 127
	.byte VOL, 127
	.byte N05, 36, 127
	.byte W12
	.byte 38
	.byte W06
	.byte N05
	.byte W06
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte N05, 36
	.byte W12
	.byte N11, 38
	.byte W12
	.byte N05, 36
	.byte W12
	.byte N11, 38
	.byte W12
	.byte N05, 36
	.byte N11, 38
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W72
	.byte N44, 50, 72
	.byte W48
	.byte N44
	.byte W48
	.byte N05, 36, 127
	.byte W12
	.byte 38
	.byte W06
	.byte N05
	.byte W06
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte N05, 36
	.byte W12
	.byte N11, 38
	.byte W12
	.byte N05, 36
	.byte W12
	.byte N11, 38
	.byte W12
	.byte N05, 36
	.byte N11, 38
	.byte W11
	.byte FINE

	.global song_134_track2
song_134_track2:
	.byte KEYSH, 0
	.byte VOICE, 102
	.byte VOL, 120
	.byte N11, 57, 100
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte 54
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte 52
	.byte W12
	.byte N11
	.byte W12
	.byte N17
	.byte W72
	.byte N92, 64
	.byte W96
	.byte N11, 57
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte N11
	.byte W12
	.byte N17
	.byte W17
	.byte FINE

	.global song_134_track3
song_134_track3:
	.byte KEYSH, 0
	.byte VOICE, 63
	.byte VOL, 110
	.byte N05, 45, 96
	.byte N05, 49, 120
	.byte W12
	.byte 45, 96
	.byte N05, 49, 120
	.byte W06
	.byte 45, 96
	.byte N05, 49, 120
	.byte W06
	.byte 45, 96
	.byte N05, 52, 120
	.byte W12
	.byte 45, 96
	.byte N05, 52, 120
	.byte W12
	.byte 49, 96
	.byte N05, 54, 120
	.byte W12
	.byte 49, 96
	.byte N05, 54, 120
	.byte W12
	.byte 49, 96
	.byte N05, 57, 120
	.byte W12
	.byte 49, 96
	.byte N05, 57, 120
	.byte W12
	.byte 52, 96
	.byte N05, 59, 120
	.byte W12
	.byte 52, 96
	.byte N05, 59, 120
	.byte W12
	.byte 52, 96
	.byte N05, 59, 120
	.byte W72
	.byte N92, 44, 96
	.byte N92, 52, 120
	.byte W96
	.byte N05, 49, 96
	.byte N05, 57, 120
	.byte W12
	.byte 49, 96
	.byte N05, 57, 120
	.byte W12
	.byte 49, 96
	.byte N05, 57, 120
	.byte W12
	.byte 49, 96
	.byte N05, 57, 120
	.byte W12
	.byte 49, 96
	.byte N05, 57, 120
	.byte W12
	.byte 49, 96
	.byte N05, 57, 120
	.byte W12
	.byte 49, 96
	.byte N05, 57, 120
	.byte W12
	.byte 49, 96
	.byte N05, 57, 120
	.byte W12
	.byte 49, 96
	.byte N05, 57, 120
	.byte W05
	.byte FINE

	.global song_134_track4
song_134_track4:
	.byte KEYSH, 0
	.byte VOICE, 17
	.byte VOL, 127
	.byte BENDR, 4
	.byte W96
	.byte W48
	.byte BEND, 64
	.byte N23, 64, 72
	.byte W04
	.byte BEND, 96
	.byte W20
	.byte 64
	.byte N23
	.byte W24
	.byte N44, 61
	.byte W48
	.byte N23, 59
	.byte W24
	.byte 61
	.byte W12
	.byte BEND, 48
	.byte W06
	.byte 32
	.byte W06
	.byte 64
	.byte N92, 57
	.byte W92
	.byte W03
	.byte FINE

	.global song_134_track5
song_134_track5:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 50
	.byte BENDR, 4
	.byte W96
	.byte BEND, 64
	.byte W60
	.byte 64
	.byte N23, 64, 72
	.byte W04
	.byte BEND, 96
	.byte W20
	.byte 64
	.byte N23
	.byte W12
	.byte W12
	.byte N44, 61
	.byte W48
	.byte N23, 59
	.byte W24
	.byte 61
	.byte W12
	.byte BEND, 48
	.byte W06
	.byte 32
	.byte W06
	.byte 64
	.byte N92, 57
	.byte W84
	.byte W11
	.byte FINE

	.global song_134
song_134:
	.byte 5  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_000
	.4byte song_134_track1
	.4byte song_134_track2
	.4byte song_134_track3
	.4byte song_134_track4
	.4byte song_134_track5
