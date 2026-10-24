@ song_159: m4a song, header 0x086BD048
	.include "assets/sound/MPlayDef.inc"

	.global song_159_track1
song_159_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 49
	.byte VOL, 127
	.byte PAN, 64
	.byte N36, 62, 96
	.byte W06
	.byte 61
	.byte W36
	.byte FINE

	.global song_159_track2
song_159_track2:
	.byte KEYSH, 0
	.byte VOICE, 50
	.byte VOL, 127
	.byte PAN, 64
	.byte W01
	.byte N42, 57, 127
	.byte W08
	.byte 50
	.byte W42
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_159
song_159:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_159_track1
	.4byte song_159_track2
