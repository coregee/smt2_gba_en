@ song_127: m4a song, header 0x086BCA84
	.include "assets/sound/MPlayDef.inc"

	.global song_127_track1
song_127_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 27
	.byte VOL, 127
	.byte PAN, 64
	.byte N36, 60, 96
	.byte W36
	.byte FINE

	.byte 0x00
	.global song_127
song_127:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_127_track1
