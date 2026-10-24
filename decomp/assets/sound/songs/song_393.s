@ song_393: m4a song, header 0x086BE4EC
	.include "assets/sound/MPlayDef.inc"

	.global song_393_track1
song_393_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 34
	.byte VOL, 127
	.byte N24, 67, 127
	.byte W24
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_393
song_393:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_393_track1
