@ song_157: m4a song, header 0x086BCFE4
	.include "assets/sound/MPlayDef.inc"

	.global song_157_track1
song_157_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 48
	.byte VOL, 127
	.byte PAN, 64
	.byte N18, 60, 88
	.byte W18
	.byte FINE

	.global song_157_track2
song_157_track2:
	.byte KEYSH, 0
	.byte VOICE, 49
	.byte VOL, 127
	.byte PAN, 64
	.byte W09
	.byte N48, 60, 100
	.byte W48
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_157
song_157:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_157_track1
	.4byte song_157_track2
