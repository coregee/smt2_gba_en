@ song_020: m4a song, header 0x086B9310
	.include "assets/sound/MPlayDef.inc"

	.global song_020_track1
song_020_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 78
	.byte N92, 31, 100
	.byte N92, 36
	.byte N92, 43, 80
	.byte N92, 48
	.byte W96
	.byte 29, 100
	.byte N92, 34
	.byte N92, 41, 80
	.byte N92, 46
	.byte W96
.Lsong_020_086B9045:
	.byte N92, 31, 100
	.byte N92, 36
	.byte N92, 43, 80
	.byte N92, 48
	.byte W96
	.byte 29, 100
	.byte N92, 34
	.byte N92, 41, 80
	.byte N92, 46
	.byte W96
	.byte PEND
	.byte PATT
	.4byte .Lsong_020_086B9045
	.byte N92, 31, 100
	.byte N92, 36
	.byte N92, 43, 80
	.byte N92, 48
	.byte W96
	.byte 29, 100
	.byte N92, 34
	.byte N92, 41, 80
	.byte N92, 46
	.byte W92
	.byte W03
.Lsong_020_086B9076:
	.byte W01
	.byte PATT
	.4byte .Lsong_020_086B9045
	.byte PATT
	.4byte .Lsong_020_086B9045
	.byte PATT
	.4byte .Lsong_020_086B9045
	.byte PATT
	.4byte .Lsong_020_086B9045
	.byte PATT
	.4byte .Lsong_020_086B9045
	.byte PATT
	.4byte .Lsong_020_086B9045
	.byte PATT
	.4byte .Lsong_020_086B9045
	.byte PATT
	.4byte .Lsong_020_086B9045
.Lsong_020_086B909F:
	.byte N92, 31, 100
	.byte N92, 36
	.byte N92, 43, 80
	.byte N92, 48
	.byte N92, 51
	.byte W96
	.byte 29, 100
	.byte N92, 34
	.byte N92, 41, 80
	.byte N92, 46
	.byte N92, 50
	.byte W96
	.byte PEND
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte PATT
	.4byte .Lsong_020_086B909F
	.byte N92, 31, 100
	.byte N92, 36
	.byte N92, 43, 80
	.byte N92, 48
	.byte N92, 51
	.byte W96
	.byte 29, 100
	.byte N92, 34
	.byte N92, 41, 80
	.byte N92, 46
	.byte N92, 50
	.byte W92
	.byte W03
	.byte GOTO
	.4byte .Lsong_020_086B9076
	.byte FINE

	.global song_020_track2
song_020_track2:
	.byte KEYSH, 0
	.byte VOICE, 45
	.byte VOL, 78
	.byte BENDR, 8
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W72
	.byte N11, 67, 92
	.byte W12
	.byte 68
	.byte W11
.Lsong_020_086B9135:
	.byte W01
.Lsong_020_086B9136:
	.byte TIE, 70, 92
	.byte W96
	.byte W96
	.byte PEND
.Lsong_020_086B913C:
	.byte W96
	.byte W76
	.byte W01
	.byte PEND
	.byte EOT, 70
	.byte W01
	.byte N06, 68, 92
	.byte W06
	.byte 70
	.byte W06
	.byte 68
	.byte W06
.Lsong_020_086B914B:
	.byte TIE, 67, 92
	.byte W96
	.byte W96
	.byte PEND
	.byte PATT
	.4byte .Lsong_020_086B913C
	.byte EOT, 67
	.byte W01
	.byte N06, 65, 92
	.byte W06
	.byte 67
	.byte W06
	.byte 65
	.byte W06
.Lsong_020_086B9161:
	.byte TIE, 63, 92
	.byte W96
	.byte W96
	.byte PEND
.Lsong_020_086B9167:
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT, 63
	.byte W01
	.byte TIE, 62, 92
	.byte W96
	.byte W92
	.byte W03
	.byte EOT
	.byte W01
	.byte TIE, 65
	.byte W96
	.byte W92
	.byte W03
	.byte EOT
	.byte W01
	.byte PATT
	.4byte .Lsong_020_086B9161
	.byte PATT
	.4byte .Lsong_020_086B9167
	.byte EOT, 63
	.byte W01
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte PATT
	.4byte .Lsong_020_086B914B
.Lsong_020_086B9193:
	.byte W96
	.byte W80
	.byte W03
	.byte PEND
	.byte EOT, 67
	.byte W01
	.byte N06, 67, 92
	.byte W06
	.byte 68
	.byte W06
	.byte PATT
	.4byte .Lsong_020_086B9136
	.byte PATT
	.4byte .Lsong_020_086B9193
	.byte EOT, 70
	.byte W01
	.byte N06, 72, 92
	.byte W06
	.byte 74
	.byte W06
	.byte TIE, 75
	.byte W96
	.byte W96
	.byte PATT
	.4byte .Lsong_020_086B9167
	.byte EOT, 75
	.byte W01
	.byte TIE, 74, 92
	.byte W96
	.byte W76
	.byte W01
	.byte EOT
	.byte W01
	.byte N06, 72
	.byte W06
	.byte 74
	.byte W06
	.byte 72
	.byte W06
	.byte TIE, 70
	.byte W96
	.byte W76
	.byte W01
	.byte EOT
	.byte W01
	.byte N06, 68
	.byte W06
	.byte 70
	.byte W06
	.byte 68
	.byte W06
	.byte PATT
	.4byte .Lsong_020_086B914B
	.byte BEND, 64
	.byte W24
	.byte 62
	.byte W12
	.byte 60
	.byte W12
	.byte 59
	.byte W12
	.byte 57
	.byte W12
	.byte 56
	.byte W12
	.byte 53
	.byte W12
	.byte 51
	.byte W12
	.byte 49
	.byte W12
	.byte 46
	.byte W12
	.byte 43
	.byte W12
	.byte 41
	.byte W12
	.byte 38
	.byte W12
	.byte 34
	.byte W12
	.byte 29
	.byte W12
	.byte 24
	.byte W12
	.byte 18
	.byte W12
	.byte 12
	.byte W12
	.byte 5
	.byte W12
	.byte 1
	.byte W44
	.byte W03
	.byte EOT, 67
	.byte W96
	.byte W01
	.byte W96
	.byte W72
	.byte BEND, 64
	.byte N11, 67, 92
	.byte W12
	.byte 68
	.byte W11
	.byte GOTO
	.4byte .Lsong_020_086B9135
	.byte FINE

	.global song_020_track3
song_020_track3:
	.byte KEYSH, 0
	.byte VOICE, 46
	.byte VOL, 47
	.byte BEND, 65
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W84
	.byte N11, 67, 80
	.byte W11
.Lsong_020_086B9233:
	.byte W01
	.byte N11, 68, 80
	.byte W12
	.byte TIE, 70
	.byte W96
	.byte W84
.Lsong_020_086B923C:
	.byte W96
	.byte W88
	.byte W01
	.byte PEND
	.byte EOT, 70
	.byte W01
	.byte N06, 68, 80
	.byte W06
.Lsong_020_086B9247:
	.byte N06, 70, 80
	.byte W06
	.byte 68
	.byte W06
	.byte TIE, 67
	.byte W96
	.byte W84
	.byte PEND
	.byte PATT
	.4byte .Lsong_020_086B923C
	.byte EOT, 67
	.byte W01
	.byte N06, 65, 80
	.byte W06
	.byte 67
	.byte W06
	.byte 65
	.byte W06
	.byte TIE, 63
	.byte W96
	.byte W84
	.byte W96
	.byte W96
	.byte W11
	.byte EOT
	.byte W01
	.byte TIE, 62
	.byte W96
	.byte W84
	.byte W11
	.byte EOT
	.byte W01
	.byte TIE, 65
	.byte W96
	.byte W84
	.byte W11
	.byte EOT
	.byte W01
	.byte TIE, 63
	.byte W96
	.byte W84
	.byte W96
	.byte W96
	.byte W11
	.byte EOT
	.byte W96
	.byte W84
	.byte W01
	.byte W96
	.byte W96
	.byte W12
	.byte TIE, 67
	.byte W96
	.byte W84
.Lsong_020_086B928B:
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT, 67
	.byte W01
	.byte N06, 67, 80
	.byte W06
	.byte 68
	.byte W06
	.byte TIE, 70
	.byte W96
	.byte W84
	.byte PATT
	.4byte .Lsong_020_086B928B
	.byte EOT, 70
	.byte W01
	.byte N06, 72, 80
	.byte W06
	.byte 74
	.byte W06
	.byte TIE, 75
	.byte W96
	.byte W84
	.byte W96
	.byte W96
	.byte W11
	.byte EOT
	.byte W01
	.byte TIE, 74
	.byte W96
	.byte W76
	.byte W01
	.byte EOT
	.byte W01
	.byte N06, 72
	.byte W06
	.byte 74
	.byte W06
	.byte 72
	.byte W06
	.byte TIE, 70
	.byte W96
	.byte W76
	.byte W01
	.byte EOT
	.byte W01
	.byte N06, 68
	.byte W06
	.byte PATT
	.4byte .Lsong_020_086B9247
	.byte W12
	.byte BEND, 65
	.byte W24
	.byte 63
	.byte W12
	.byte 61
	.byte W12
	.byte 60
	.byte W12
	.byte 58
	.byte W12
	.byte 57
	.byte W12
	.byte 54
	.byte W12
	.byte 52
	.byte W12
	.byte 50
	.byte W12
	.byte 47
	.byte W12
	.byte 44
	.byte W12
	.byte 42
	.byte W12
	.byte 39
	.byte W12
	.byte 35
	.byte W12
	.byte 30
	.byte W12
	.byte 25
	.byte W12
	.byte 19
	.byte W12
	.byte 13
	.byte W12
	.byte 6
	.byte W12
	.byte 2
	.byte W44
	.byte W03
	.byte EOT, 67
	.byte W84
	.byte W01
	.byte W96
	.byte W84
	.byte BEND, 65
	.byte N11, 67, 80
	.byte W11
	.byte GOTO
	.4byte .Lsong_020_086B9233
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_020
song_020:
	.byte 3  @ tracks
	.byte 0  @ blocks
	.byte 10  @ priority
	.byte 166  @ reverb
	.4byte voicegroup_000
	.4byte song_020_track1
	.4byte song_020_track2
	.4byte song_020_track3
