@ song_007: m4a song, header 0x086B4790
	.include "assets/sound/MPlayDef.inc"

	.global song_007_track1
song_007_track1:
	.byte KEYSH, 0
	.byte TEMPO, 72
	.byte VOICE, 1
	.byte VOL, 100
	.byte BENDR, 8
	.byte TIE, 26, 72
	.byte TIE, 38, 92
	.byte TIE, 41, 80
	.byte W96
	.byte W92
	.byte W03
	.byte EOT, 26
	.byte 38
	.byte 41
.Lsong_007_086B4582:
	.byte W01
.Lsong_007_086B4583:
	.byte TIE, 28, 72
	.byte TIE, 40, 92
	.byte TIE, 43, 80
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT, 28
	.byte 40
	.byte 43
	.byte W01
.Lsong_007_086B4595:
	.byte TIE, 26, 72
	.byte TIE, 38, 92
	.byte TIE, 41, 80
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT, 26
	.byte 38
	.byte 41
	.byte W01
	.byte TIE, 24, 72
	.byte TIE, 36, 92
	.byte TIE, 40, 80
	.byte W96
	.byte W92
	.byte W03
	.byte EOT, 24
	.byte 36
	.byte 40
	.byte W01
	.byte PATT
	.4byte .Lsong_007_086B4595
	.byte EOT, 26
	.byte 38
	.byte 41
	.byte W01
	.byte PATT
	.4byte .Lsong_007_086B4583
	.byte EOT, 28
	.byte 40
	.byte 43
	.byte W01
	.byte N92, 22, 72
	.byte N92, 34, 92
	.byte N92, 41, 80
	.byte W96
	.byte 24, 72
	.byte N92, 36, 92
	.byte N92, 40, 80
	.byte W96
	.byte TIE, 22, 72
	.byte TIE, 34, 92
	.byte TIE, 38, 80
	.byte W96
	.byte W92
	.byte W03
	.byte EOT, 22
	.byte 34
	.byte 38
	.byte W01
	.byte PATT
	.4byte .Lsong_007_086B4595
	.byte EOT, 26
	.byte 38
	.byte 41
	.byte GOTO
	.4byte .Lsong_007_086B4582
	.byte FINE

	.global song_007_track2
song_007_track2:
	.byte KEYSH, 0
	.byte VOICE, 34
	.byte VOL, 72
	.byte BENDR, 8
	.byte BEND, 64
	.byte TIE, 45, 80
	.byte TIE, 57, 100
	.byte W90
	.byte BEND, 64
	.byte W02
	.byte 55
	.byte W02
	.byte 46
	.byte W02
	.byte 36
	.byte W02
	.byte 27
	.byte W02
	.byte 17
	.byte W02
	.byte 8
	.byte W36
	.byte 8
	.byte W02
	.byte 21
	.byte W02
	.byte 34
	.byte W02
	.byte 47
	.byte W02
	.byte 60
	.byte W02
	.byte 74
	.byte W02
	.byte 88
	.byte W40
	.byte W01
	.byte EOT, 45
	.byte 57
.Lsong_007_086B4631:
	.byte W01
.Lsong_007_086B4632:
	.byte BEND, 64
	.byte TIE, 47, 80
	.byte N92, 59, 100
	.byte W96
	.byte N68, 57
	.byte W72
	.byte N23, 55
	.byte W23
	.byte PEND
	.byte EOT, 47
	.byte W01
	.byte TIE, 45, 80
	.byte TIE, 57, 100
	.byte W90
	.byte BEND, 64
	.byte W02
	.byte 71
	.byte W02
	.byte 77
	.byte W02
	.byte 84
	.byte W02
	.byte 91
	.byte W02
	.byte 97
	.byte W02
	.byte 104
	.byte W88
	.byte W01
	.byte EOT, 45
	.byte 57
	.byte W01
	.byte BEND, 64
	.byte TIE, 43, 80
	.byte N92, 60, 100
	.byte W96
	.byte 59
	.byte W92
	.byte W03
	.byte EOT, 43
	.byte W01
.Lsong_007_086B466F:
	.byte TIE, 45, 80
	.byte TIE, 57, 100
	.byte W90
	.byte BEND, 64
	.byte W02
	.byte 55
	.byte W02
	.byte 46
	.byte W02
	.byte 36
	.byte W02
	.byte 27
	.byte W02
	.byte 17
	.byte W02
	.byte 8
	.byte W36
	.byte 8
	.byte W02
	.byte 21
	.byte W02
	.byte 34
	.byte W02
	.byte 47
	.byte W02
	.byte 60
	.byte W02
	.byte 74
	.byte W02
	.byte 88
	.byte W40
	.byte W01
	.byte PEND
	.byte EOT, 45
	.byte 57
	.byte W01
	.byte PATT
	.4byte .Lsong_007_086B4632
	.byte EOT, 47
	.byte W01
	.byte N92, 45, 80
	.byte N30, 57, 100
	.byte W32
	.byte 50
	.byte W32
	.byte 55
	.byte W32
	.byte N92, 43, 80
	.byte N92, 52, 100
	.byte W96
	.byte TIE, 41, 80
	.byte TIE, 53, 100
	.byte W96
	.byte W92
	.byte W03
	.byte EOT, 41
	.byte 53
	.byte W01
	.byte PATT
	.4byte .Lsong_007_086B466F
	.byte EOT, 45
	.byte 57
	.byte GOTO
	.4byte .Lsong_007_086B4631
	.byte FINE

	.global song_007_track3
song_007_track3:
	.byte KEYSH, 0
	.byte W24
	.byte VOICE, 35
	.byte VOL, 25
	.byte BENDR, 8
	.byte BEND, 64
	.byte TIE, 57, 100
	.byte W90
	.byte BEND, 64
	.byte W02
	.byte 55
	.byte W02
	.byte 46
	.byte W02
	.byte 36
	.byte W02
	.byte 27
	.byte W02
	.byte 17
	.byte W02
	.byte 8
	.byte W36
	.byte 8
	.byte W02
	.byte 21
	.byte W02
	.byte 34
	.byte W02
	.byte 47
	.byte W02
	.byte 60
	.byte W02
	.byte 74
	.byte W02
	.byte 88
	.byte W18
	.byte W23
	.byte EOT
.Lsong_007_086B46FC:
	.byte W01
	.byte BEND, 64
	.byte N92, 59, 100
	.byte W96
	.byte N68, 57
	.byte W72
	.byte N23, 55
	.byte W24
	.byte TIE, 57
	.byte W90
	.byte BEND, 64
	.byte W02
	.byte 71
	.byte W02
	.byte 77
	.byte W02
	.byte 84
	.byte W02
	.byte 91
	.byte W02
	.byte 97
	.byte W02
	.byte 104
	.byte W66
	.byte W23
	.byte EOT
	.byte W01
	.byte BEND, 64
	.byte N92, 60
	.byte W96
	.byte 59
	.byte W72
	.byte W24
	.byte TIE, 57
	.byte W90
	.byte BEND, 64
	.byte W02
	.byte 55
	.byte W02
	.byte 46
	.byte W02
	.byte 36
	.byte W02
	.byte 27
	.byte W02
	.byte 17
	.byte W02
	.byte 8
	.byte W36
	.byte 8
	.byte W02
	.byte 21
	.byte W02
	.byte 34
	.byte W02
	.byte 47
	.byte W02
	.byte 60
	.byte W02
	.byte 74
	.byte W02
	.byte 88
	.byte W18
	.byte W23
	.byte EOT
	.byte W01
	.byte BEND, 64
	.byte N92, 59
	.byte W96
	.byte N68, 57
	.byte W72
	.byte N23, 55
	.byte W24
	.byte N30, 57
	.byte W32
	.byte 50
	.byte W32
	.byte 55
	.byte W32
	.byte N92, 52
	.byte W72
	.byte W24
	.byte TIE, 53
	.byte W96
	.byte W72
	.byte W23
	.byte EOT
	.byte W01
	.byte TIE, 57
	.byte W90
	.byte BEND, 64
	.byte W02
	.byte 55
	.byte W02
	.byte 46
	.byte W02
	.byte 36
	.byte W02
	.byte 27
	.byte W02
	.byte 17
	.byte W02
	.byte 8
	.byte W36
	.byte 8
	.byte W02
	.byte 21
	.byte W02
	.byte 34
	.byte W02
	.byte 47
	.byte W02
	.byte 60
	.byte W02
	.byte 74
	.byte W02
	.byte 88
	.byte W18
	.byte W23
	.byte EOT
	.byte GOTO
	.4byte .Lsong_007_086B46FC
	.byte FINE

	.byte 0x00, 0x00
	.global song_007
song_007:
	.byte 3  @ tracks
	.byte 0  @ blocks
	.byte 10  @ priority
	.byte 166  @ reverb
	.4byte voicegroup_000
	.4byte song_007_track1
	.4byte song_007_track2
	.4byte song_007_track3
