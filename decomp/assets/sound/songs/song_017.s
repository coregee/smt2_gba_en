@ song_017: m4a song, header 0x086B7DFC
	.include "assets/sound/MPlayDef.inc"

	.global song_017_track1
song_017_track1:
	.byte KEYSH, 0
	.byte TEMPO, 88
	.byte VOICE, 15
	.byte VOL, 86
	.byte TIE, 45, 100
	.byte TIE, 64, 120
	.byte W96
	.byte W23
	.byte EOT
	.byte W24
	.byte EOT, 45
	.byte W01
.Lsong_017_086B7AF1:
	.byte TIE, 48, 100
	.byte N44, 62, 120
	.byte W48
	.byte 69
	.byte W48
	.byte 67
	.byte W44
	.byte W03
	.byte PEND
	.byte EOT, 48
	.byte W01
.Lsong_017_086B7B01:
	.byte TIE, 47, 100
	.byte TIE, 64, 120
	.byte W96
	.byte W23
	.byte PEND
	.byte EOT
	.byte W24
	.byte EOT, 47
	.byte W01
.Lsong_017_086B7B0F:
	.byte TIE, 48, 100
	.byte N44, 62, 120
	.byte W48
	.byte 67
	.byte W48
	.byte 69
	.byte W44
	.byte W03
	.byte PEND
	.byte EOT, 48
	.byte W01
.Lsong_017_086B7B1F:
	.byte TIE, 45, 100
	.byte TIE, 64, 120
	.byte W96
	.byte W23
	.byte PEND
	.byte EOT
	.byte W24
	.byte EOT, 45
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7AF1
	.byte EOT, 48
	.byte W01
.Lsong_017_086B7B35:
	.byte TIE, 52, 100
	.byte N44, 64, 120
	.byte W48
	.byte 57
	.byte W48
	.byte 62
	.byte W44
	.byte W03
	.byte PEND
	.byte EOT, 52
	.byte W01
.Lsong_017_086B7B45:
	.byte TIE, 47, 100
	.byte TIE, 59, 120
	.byte W96
	.byte W23
	.byte PEND
	.byte EOT
	.byte W24
	.byte EOT, 47
.Lsong_017_086B7B52:
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7B1F
	.byte EOT, 64
	.byte W24
	.byte 45
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7AF1
	.byte EOT, 48
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7B01
	.byte EOT, 64
	.byte W24
	.byte 47
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7B0F
	.byte EOT, 48
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7B1F
	.byte EOT, 64
	.byte W24
	.byte 45
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7AF1
	.byte EOT, 48
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7B35
	.byte EOT, 52
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7B45
	.byte EOT, 59
	.byte W24
	.byte 47
	.byte GOTO
	.4byte .Lsong_017_086B7B52
	.byte FINE

	.global song_017_track2
song_017_track2:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 55
	.byte TIE, 52, 92
	.byte TIE, 57
	.byte W96
	.byte W48
.Lsong_017_086B7BAD:
	.byte W96
	.byte W44
	.byte W03
	.byte PEND
	.byte EOT, 52
	.byte 57
	.byte W01
.Lsong_017_086B7BB5:
	.byte TIE, 53, 92
	.byte TIE, 57
	.byte W96
	.byte W48
	.byte PEND
	.byte PATT
	.4byte .Lsong_017_086B7BAD
	.byte EOT, 53
	.byte 57
	.byte W01
.Lsong_017_086B7BC6:
	.byte TIE, 52, 92
	.byte TIE, 57
	.byte W96
	.byte W48
	.byte PEND
	.byte PATT
	.4byte .Lsong_017_086B7BAD
	.byte EOT, 52
	.byte 57
	.byte W01
.Lsong_017_086B7BD7:
	.byte TIE, 53, 92
	.byte TIE, 57
	.byte W96
	.byte W44
	.byte W03
	.byte PEND
	.byte EOT, 53
	.byte 57
	.byte W01
.Lsong_017_086B7BE4:
	.byte TIE, 55, 92
	.byte TIE, 59
	.byte W96
	.byte W44
	.byte W03
	.byte PEND
	.byte EOT, 55
	.byte 59
.Lsong_017_086B7BF0:
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7BC6
	.byte PATT
	.4byte .Lsong_017_086B7BAD
	.byte EOT, 52
	.byte 57
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7BB5
	.byte PATT
	.4byte .Lsong_017_086B7BAD
	.byte EOT, 53
	.byte 57
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7BC6
	.byte PATT
	.4byte .Lsong_017_086B7BAD
	.byte EOT, 52
	.byte 57
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7BD7
	.byte EOT, 53
	.byte 57
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7BE4
	.byte EOT, 55
	.byte 59
	.byte GOTO
	.4byte .Lsong_017_086B7BF0
	.byte FINE

	.global song_017_track3
song_017_track3:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 62
	.byte N11, 57, 92
	.byte W12
	.byte 57, 48
	.byte W12
	.byte 60, 92
	.byte W12
	.byte 60, 48
	.byte W12
	.byte 64, 92
	.byte W12
	.byte 64, 48
	.byte W12
	.byte 67, 92
	.byte W12
	.byte 67, 48
	.byte W12
	.byte 69, 92
	.byte W12
	.byte 69, 48
	.byte W12
	.byte 72, 92
	.byte W12
	.byte 72, 48
	.byte W12
.Lsong_017_086B7C5D:
	.byte N11, 76, 92
	.byte W12
	.byte 76, 48
	.byte W12
	.byte 72, 92
	.byte W12
	.byte 72, 48
	.byte W12
	.byte 69, 92
	.byte W12
	.byte 69, 48
	.byte W12
	.byte 67, 92
	.byte W12
	.byte 67, 48
	.byte W12
	.byte 64, 92
	.byte W12
	.byte 64, 48
	.byte W12
	.byte 60, 92
	.byte W12
	.byte 60, 48
	.byte W12
	.byte PEND
.Lsong_017_086B7C83:
	.byte N11, 57, 92
	.byte W12
	.byte 57, 48
	.byte W12
	.byte 60, 92
	.byte W12
	.byte 60, 48
	.byte W12
	.byte 64, 92
	.byte W12
	.byte 64, 48
	.byte W12
	.byte 65, 92
	.byte W12
	.byte 65, 48
	.byte W12
	.byte 69, 92
	.byte W12
	.byte 69, 48
	.byte W12
	.byte 72, 92
	.byte W12
	.byte 72, 48
	.byte W12
	.byte PEND
.Lsong_017_086B7CA9:
	.byte N11, 76, 92
	.byte W12
	.byte 76, 48
	.byte W12
	.byte 72, 92
	.byte W12
	.byte 72, 48
	.byte W12
	.byte 69, 92
	.byte W12
	.byte 69, 48
	.byte W12
	.byte 65, 92
	.byte W12
	.byte 65, 48
	.byte W12
	.byte 64, 92
	.byte W12
	.byte 64, 48
	.byte W12
	.byte 60, 92
	.byte W12
	.byte 60, 48
	.byte W12
	.byte PEND
.Lsong_017_086B7CCF:
	.byte N11, 57, 92
	.byte W12
	.byte 57, 48
	.byte W12
	.byte 60, 92
	.byte W12
	.byte 60, 48
	.byte W12
	.byte 64, 92
	.byte W12
	.byte 64, 48
	.byte W12
	.byte 67, 92
	.byte W12
	.byte 67, 48
	.byte W12
	.byte 69, 92
	.byte W12
	.byte 69, 48
	.byte W12
	.byte 72, 92
	.byte W12
	.byte 72, 48
	.byte W12
	.byte PEND
	.byte PATT
	.4byte .Lsong_017_086B7C5D
	.byte PATT
	.4byte .Lsong_017_086B7C83
	.byte N11, 74, 92
	.byte W12
	.byte 74, 48
	.byte W12
	.byte 71, 92
	.byte W12
	.byte 71, 48
	.byte W12
	.byte 67, 92
	.byte W12
	.byte 67, 48
	.byte W12
	.byte 64, 92
	.byte W12
	.byte 64, 48
	.byte W12
	.byte 62, 92
	.byte W12
	.byte 62, 48
	.byte W12
	.byte 59, 92
	.byte W12
	.byte 59, 48
	.byte W11
.Lsong_017_086B7D24:
	.byte W01
	.byte PATT
	.4byte .Lsong_017_086B7CCF
	.byte PATT
	.4byte .Lsong_017_086B7C5D
	.byte PATT
	.4byte .Lsong_017_086B7C83
	.byte PATT
	.4byte .Lsong_017_086B7CA9
	.byte PATT
	.4byte .Lsong_017_086B7CCF
	.byte PATT
	.4byte .Lsong_017_086B7C5D
	.byte PATT
	.4byte .Lsong_017_086B7C83
	.byte N11, 74, 92
	.byte W12
	.byte 74, 48
	.byte W12
	.byte 71, 92
	.byte W12
	.byte 71, 48
	.byte W12
	.byte 67, 92
	.byte W12
	.byte 67, 48
	.byte W12
	.byte 64, 92
	.byte W12
	.byte 64, 48
	.byte W12
	.byte 62, 92
	.byte W12
	.byte 62, 48
	.byte W12
	.byte 59, 92
	.byte W12
	.byte 59, 48
	.byte W11
	.byte GOTO
	.4byte .Lsong_017_086B7D24
	.byte FINE

	.global song_017_track4
song_017_track4:
	.byte KEYSH, 0
	.byte W12
	.byte VOICE, 16
	.byte VOL, 31
	.byte TIE, 64, 120
	.byte W96
	.byte W23
	.byte EOT
	.byte W13
.Lsong_017_086B7D81:
	.byte W12
	.byte N44, 62, 120
	.byte W48
	.byte 69
	.byte W48
	.byte 67
	.byte W36
	.byte PEND
.Lsong_017_086B7D8B:
	.byte W12
	.byte TIE, 64, 120
	.byte W96
	.byte W23
	.byte PEND
	.byte EOT
	.byte W13
.Lsong_017_086B7D94:
	.byte W12
	.byte N44, 62, 120
	.byte W48
	.byte 67
	.byte W48
	.byte 69
	.byte W36
	.byte PEND
	.byte PATT
	.4byte .Lsong_017_086B7D8B
	.byte EOT, 64
	.byte W13
	.byte PATT
	.4byte .Lsong_017_086B7D81
.Lsong_017_086B7DAB:
	.byte W12
	.byte N44, 64, 120
	.byte W48
	.byte 57
	.byte W48
	.byte 62
	.byte W36
	.byte PEND
.Lsong_017_086B7DB5:
	.byte W12
	.byte TIE, 59, 120
	.byte W96
	.byte W23
	.byte PEND
	.byte EOT
	.byte W13
	.byte W11
.Lsong_017_086B7DBF:
	.byte W01
	.byte TIE, 64, 120
	.byte W96
	.byte W23
	.byte EOT
	.byte W13
	.byte PATT
	.4byte .Lsong_017_086B7D81
	.byte PATT
	.4byte .Lsong_017_086B7D8B
	.byte EOT, 64
	.byte W13
	.byte PATT
	.4byte .Lsong_017_086B7D94
	.byte PATT
	.4byte .Lsong_017_086B7D8B
	.byte EOT, 64
	.byte W13
	.byte PATT
	.4byte .Lsong_017_086B7D81
	.byte PATT
	.4byte .Lsong_017_086B7DAB
	.byte PATT
	.4byte .Lsong_017_086B7DB5
	.byte EOT, 59
	.byte W13
	.byte W11
	.byte GOTO
	.4byte .Lsong_017_086B7DBF
	.byte FINE

	.byte 0x00, 0x00
	.global song_017
song_017:
	.byte 4  @ tracks
	.byte 0  @ blocks
	.byte 10  @ priority
	.byte 166  @ reverb
	.4byte voicegroup_000
	.4byte song_017_track1
	.4byte song_017_track2
	.4byte song_017_track3
	.4byte song_017_track4
