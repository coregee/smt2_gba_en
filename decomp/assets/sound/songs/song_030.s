@ song_030: m4a song, header 0x086BC744
	.include "assets/sound/MPlayDef.inc"

	.global song_030_track1
song_030_track1:
	.byte KEYSH, 0
	.byte TEMPO, 120
	.byte VOICE, 1
	.byte VOL, 86
	.byte N23, 57, 100
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W24
	.byte 57
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W23
.Lsong_030_086BC60A:
	.byte W01
.Lsong_030_086BC60B:
	.byte N23, 57, 100
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W24
	.byte 57
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W24
	.byte PEND
	.byte PATT
	.4byte .Lsong_030_086BC60B
	.byte PATT
	.4byte .Lsong_030_086BC60B
.Lsong_030_086BC628:
	.byte N23, 58, 100
	.byte W24
	.byte 55
	.byte W24
	.byte 53
	.byte W24
	.byte 55
	.byte W24
	.byte 58
	.byte W24
	.byte 55
	.byte W24
	.byte 53
	.byte W24
	.byte 55
	.byte W24
	.byte PEND
	.byte PATT
	.4byte .Lsong_030_086BC628
	.byte PATT
	.4byte .Lsong_030_086BC628
	.byte PATT
	.4byte .Lsong_030_086BC628
	.byte N23, 57, 100
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W24
	.byte 57
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W23
	.byte GOTO
	.4byte .Lsong_030_086BC60A
	.byte FINE

	.global song_030_track2
song_030_track2:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 86
	.byte TIE, 48, 100
	.byte W96
	.byte W92
	.byte W03
	.byte EOT
.Lsong_030_086BC66F:
	.byte W01
.Lsong_030_086BC670:
	.byte TIE, 46, 100
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT
	.byte W01
.Lsong_030_086BC679:
	.byte TIE, 48, 100
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT
	.byte W01
	.byte PATT
	.4byte .Lsong_030_086BC670
	.byte EOT, 46
	.byte W01
.Lsong_030_086BC68A:
	.byte TIE, 49, 100
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT
	.byte W01
.Lsong_030_086BC693:
	.byte TIE, 47, 100
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT
	.byte W01
	.byte PATT
	.4byte .Lsong_030_086BC68A
	.byte EOT, 49
	.byte W01
	.byte PATT
	.4byte .Lsong_030_086BC693
	.byte EOT, 47
	.byte W01
	.byte PATT
	.4byte .Lsong_030_086BC679
	.byte EOT, 48
	.byte GOTO
	.4byte .Lsong_030_086BC66F
	.byte FINE

	.global song_030_track3
song_030_track3:
	.byte KEYSH, 0
	.byte W24
	.byte VOICE, 34
	.byte VOL, 62
	.byte N23, 57, 100
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W24
	.byte 57
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W23
.Lsong_030_086BC6D2:
	.byte W01
	.byte N23, 57, 100
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W24
	.byte 57
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
.Lsong_030_086BC6E3:
	.byte N23, 54, 100
	.byte W24
	.byte 57
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W24
	.byte 57
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte PEND
	.byte PATT
	.4byte .Lsong_030_086BC6E3
	.byte N23, 54, 100
	.byte W24
	.byte 58
	.byte W24
	.byte 55
	.byte W24
	.byte 53
	.byte W24
	.byte 55
	.byte W24
	.byte 58
	.byte W24
	.byte 55
	.byte W24
	.byte 53
	.byte W24
.Lsong_030_086BC70D:
	.byte N23, 55, 100
	.byte W24
	.byte 58
	.byte W24
	.byte 55
	.byte W24
	.byte 53
	.byte W24
	.byte 55
	.byte W24
	.byte 58
	.byte W24
	.byte 55
	.byte W24
	.byte 53
	.byte W24
	.byte PEND
	.byte PATT
	.4byte .Lsong_030_086BC70D
	.byte PATT
	.4byte .Lsong_030_086BC70D
	.byte N23, 55, 100
	.byte W24
	.byte 57
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W24
	.byte 57
	.byte W24
	.byte 54
	.byte W24
	.byte 52
	.byte W24
	.byte 54
	.byte W23
	.byte GOTO
	.4byte .Lsong_030_086BC6D2
	.byte FINE

	.global song_030
song_030:
	.byte 3  @ tracks
	.byte 0  @ blocks
	.byte 10  @ priority
	.byte 166  @ reverb
	.4byte voicegroup_000
	.4byte song_030_track1
	.4byte song_030_track2
	.4byte song_030_track3
