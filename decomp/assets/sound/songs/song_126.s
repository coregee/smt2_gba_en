@ song_126: m4a song, header 0x086BCA68
	.include "assets/sound/MPlayDef.inc"

	.global song_126_track1
song_126_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 26
	.byte VOL, 127
	.byte PAN, 64
	.byte N36, 60, 104
	.byte W36
	.byte FINE

	.byte 0x00
	.global song_126
song_126:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_126_track1
