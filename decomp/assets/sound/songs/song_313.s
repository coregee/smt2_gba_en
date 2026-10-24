@ song_313: m4a song, header 0x086BDBC4
	.include "assets/sound/MPlayDef.inc"

	.global song_313_track1
song_313_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 11
	.byte VOL, 127
	.byte N11, 62, 124
	.byte W12
	.byte N18, 62, 12
	.byte W18
	.byte FINE

	.byte 0x00, 0x00, 0x00
	.global song_313
song_313:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_005
	.4byte song_313_track1
