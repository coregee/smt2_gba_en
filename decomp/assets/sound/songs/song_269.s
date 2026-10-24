@ song_269: m4a song, header 0x086BD68C
	.include "assets/sound/MPlayDef.inc"

	.global song_269_track1
song_269_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 3
	.byte VOL, 127
	.byte TIE, 57, 127
	.byte W96
	.byte W48
	.byte EOT
	.byte FINE

	.global song_269_track2
song_269_track2:
	.byte KEYSH, 0
	.byte VOICE, 20
	.byte VOL, 52
	.byte N05, 51, 127
	.byte W06
	.byte TIE, 57
	.byte W90
	.byte W54
	.byte EOT
	.byte FINE

	.byte 0x00
	.global song_269
song_269:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_269_track1
	.4byte song_269_track2
