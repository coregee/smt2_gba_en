@ song_257: m4a song, header 0x086BD5F4
	.include "assets/sound/MPlayDef.inc"

	.global song_257_track1
song_257_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 51
	.byte VOL, 127
	.byte N04, 56, 127
	.byte W02
	.byte N03, 52
	.byte W04
	.byte N04, 56
	.byte W01
	.byte N03, 52
	.byte W05
	.byte N04, 56
	.byte W01
	.byte N03, 52
	.byte W05
	.byte N04, 56
	.byte W01
	.byte N03, 52
	.byte W05
	.byte N04, 56
	.byte W01
	.byte N03, 52
	.byte W05
	.byte N04, 56
	.byte W01
	.byte N03, 52
	.byte W05
	.byte N04, 56
	.byte W01
	.byte N03, 52
	.byte W05
	.byte N04, 56
	.byte W01
	.byte N03, 52
	.byte W05
	.byte N04, 56
	.byte W01
	.byte 52
	.byte W05
	.byte FINE

	.byte 0x00
	.global song_257
song_257:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_257_track1
