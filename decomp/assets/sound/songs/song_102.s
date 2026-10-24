@ song_102: m4a song, header 0x086BC7A0
	.include "assets/sound/MPlayDef.inc"

	.global song_102_track1
song_102_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 90
	.byte N12, 60, 127
	.byte W12
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_102
song_102:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_102_track1
