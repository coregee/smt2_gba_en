@ m4a voicegroups (ToneData, 12 bytes each).  Voicegroups overlap: each label
@ starts a 128-entry program table that runs into the following ones.
	.include "assets/sound/MPlayDef.inc"

	.global voicegroup_000
voicegroup_000: @ 0x0858BE94
	.byte 0x00, 60, 0, 0
	.4byte sample_0858E000
	.byte 128, 127, 206, 127  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085A2654
	.byte 128, 127, 206, 127  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085AC08C
	.byte 128, 127, 206, 127  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085B3F64
	.byte 128, 188, 180, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085B732C
	.byte 128, 127, 206, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085B8040
	.byte 85, 188, 180, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085BBB64
	.byte 128, 127, 206, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085BBB64
	.byte 128, 127, 206, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085B732C
	.byte 128, 127, 206, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085B8040
	.byte 85, 188, 180, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085BE0D4
	.byte 128, 188, 128, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085C0C74
	.byte 128, 188, 128, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085A2654
	.byte 128, 127, 206, 127  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085CB044
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085D0368
	.byte 128, 127, 206, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085D2350
	.byte 128, 127, 103, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085D2350
	.byte 128, 127, 103, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085D55D8
	.byte 128, 188, 77, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085D55D8
	.byte 128, 188, 77, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085D55D8
	.byte 255, 127, 231, 127  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085D55D8
	.byte 255, 127, 231, 127  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085D5608
	.byte 128, 188, 180, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085D5608
	.byte 128, 188, 180, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_085D9A60
	.byte 128, 188, 180, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085D9A60
	.byte 128, 188, 180, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085BE0D4
	.byte 128, 188, 128, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_085A2654
	.byte 128, 127, 206, 127  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085A2654
	.byte 128, 127, 206, 127  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085DD608
	.byte 128, 127, 206, 127  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_085E14E4
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085E14E4
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_085E7FC8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085E7FC8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085E7FC8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085CB044
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.global voicegroup_kit_0858C2E4
voicegroup_kit_0858C2E4: @ 0x0858C2E4
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_085EB5C0
	.byte 128, 188, 180, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_085EE400
	.byte 128, 188, 180, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x80, 0, 0, 0
	.4byte voicegroup_kit_0858C2E4
	.byte 0, 0, 0, 0  @ rhythm (drum kit)
	.byte 0x08, 60, 0, 192
	.4byte sample_085F064C
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x0C, 48, 0, 192
	.4byte 0x00000000
	.byte 0, 0, 15, 0  @ CGB noise
	.byte 0x08, 60, 0, 192
	.4byte sample_085F0D94
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x08, 60, 0, 192
	.4byte sample_085F18A4
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x00, 54, 0, 148
	.4byte sample_085F2368
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x08, 60, 0, 202
	.4byte sample_085F2EE8
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x00, 60, 0, 170
	.4byte sample_085F2368
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x08, 60, 0, 202
	.4byte sample_085F2EE8
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x00, 60, 0, 181
	.4byte sample_085F3188
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x08, 60, 0, 202
	.4byte sample_085F3D08
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x00, 68, 0, 203
	.4byte sample_085F3188
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x08, 60, 0, 174
	.4byte sample_085F4CE4
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 177
	.4byte sample_085F6544
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 207
	.4byte sample_085F6544
	.byte 128, 0, 255, 0  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 72, 0, 202
	.4byte sample_085F2EE8
	.byte 128, 0, 255, 0  @ DirectSound
	.global voicegroup_001
voicegroup_001: @ 0x0858C590
	.byte 0x00, 60, 0, 0
	.4byte sample_085F75DC
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085F7D18
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085F8DF8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085F9EEC
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085FBBAC
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085FCAC8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085FDE38
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085FE200
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085FF8A8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086013EC
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08606A2C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08607720
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0860E5A8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0860F8E0
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08612290
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08612E60
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086134D0
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086141C4
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086146B0
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08617744
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08617B88
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086188A8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08619A08
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0861A940
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0861B620
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_0861C19C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0861D244
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0861E1BC
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_0861F018
	.byte 128, 188, 154, 165  @ DirectSound
	.global voicegroup_002
voicegroup_002: @ 0x0858C704
	.byte 0x09, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 4, 0, 4  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 4, 0, 2  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 4, 0, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 7, 15, 7  @ CGB square 1
	.byte 0x0A, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 4, 0, 4  @ CGB square 2
	.byte 0x0A, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 4, 0, 2  @ CGB square 2
	.byte 0x0A, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 4, 0, 0  @ CGB square 2
	.byte 0x0A, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 7, 15, 7  @ CGB square 2
	.byte 0x09, 60, 0, 0
	.4byte 0x00000003
	.byte 0, 1, 9, 4  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000003
	.byte 0, 4, 0, 4  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000003
	.byte 0, 4, 0, 2  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000003
	.byte 0, 4, 0, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 4, 0, 4  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 4, 0, 2  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 4, 0, 0  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 7, 15, 7  @ CGB noise
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 4  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 2  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 0  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 7, 15, 7  @ CGB noise
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 4  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 2  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 0  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 2, 0, 15, 2  @ CGB noise
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000002
	.byte 1, 6, 0, 6  @ CGB square 1
	.byte 0x0B, 60, 0, 0
	.4byte cgb_wave_0858D344
	.byte 0, 4, 0, 2  @ CGB wave
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 2, 7, 10, 7  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 7, 4, 3  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 5, 2, 6, 6  @ CGB noise
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 4, 0, 4  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 4, 0, 2  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 4, 0, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000000
	.byte 1, 0, 15, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000000
	.byte 3, 0, 15, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 4  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 2  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000000
	.byte 1, 0, 15, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000000
	.byte 3, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 6, 0, 3  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_085E7FC8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_085E7FC8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_086209D8
	.byte 128, 188, 154, 165  @ DirectSound
	.global voicegroup_003
voicegroup_003: @ 0x0858CBC0
	.byte 0x00, 60, 0, 0
	.4byte sample_086236D0
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086274A0
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0862EA5C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086314E4
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08639564
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0863EC9C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0863FC50
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08643D6C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0864A818
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 4  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 2  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 0  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 2, 0, 15, 2  @ CGB noise
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 4, 0, 4  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 4, 0, 2  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 4, 0, 0  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 7, 15, 7  @ CGB noise
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 4  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 2  @ CGB noise
	.byte 0x0C, 60, 0, 0
	.4byte 0x00000001
	.byte 0, 4, 0, 0  @ CGB noise
	.byte 0x00, 60, 0, 0
	.4byte sample_08652814
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_08652E50
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086542E4
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08654A4C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08655E58
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08656528
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08657A2C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08658408
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08658B5C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08659F68
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0865C5D8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0865EED8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086619FC
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0866259C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08663158
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08664F84
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08665AF4
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08666540
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08666F2C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0866744C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08668150
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08668EB4
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08669748
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0866A850
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0866B54C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0866C21C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0866CED0
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0866D744
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0866E190
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0866E4B0
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0866EEF4
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0866FE74
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08670854
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08671254
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08671C5C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_0867266C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08672C6C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_08673AD8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_08674E6C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08675FC4
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08676F18
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0867928C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_086209D8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_0867ABF8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0867EC80
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_08680224
	.byte 128, 188, 154, 165  @ DirectSound
	.global voicegroup_004
voicegroup_004: @ 0x0858D010
	.byte 0x09, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 4, 0, 4  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 4, 0, 2  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 4, 0, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 7, 15, 7  @ CGB square 1
	.byte 0x0A, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 4, 0, 4  @ CGB square 2
	.byte 0x0A, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 7, 15, 7  @ CGB square 2
	.byte 0x09, 60, 0, 0
	.4byte 0x00000003
	.byte 0, 1, 9, 4  @ CGB square 1
	.global voicegroup_005
voicegroup_005: @ 0x0858D064
	.byte 0x09, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 4, 0, 0  @ CGB square 1
	.byte 0x09, 60, 0, 0
	.4byte 0x00000000
	.byte 0, 4, 0, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte 0x08174204  @ all-zero header (no sample) outside sound data
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte 0x08174214  @ all-zero header (no sample) outside sound data
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte 0x08174224  @ all-zero header (no sample) outside sound data
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08684C08
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0868902C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_0868A51C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte 0x08174234  @ all-zero header (no sample) outside sound data
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte 0x08174244  @ all-zero header (no sample) outside sound data
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0868DD88
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086909E0
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte 0x08174254  @ all-zero header (no sample) outside sound data
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte 0x08174264  @ all-zero header (no sample) outside sound data
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_08693944
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_0869D1C4
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086A4414
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086A9138
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte 0x081741E4  @ all-zero header (no sample) outside sound data
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086A9E08
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte 0x08174274  @ all-zero header (no sample) outside sound data
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte 0x081741F4  @ all-zero header (no sample) outside sound data
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte 0x08174284  @ all-zero header (no sample) outside sound data
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086AB4C8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086ACB0C
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086AD2C0
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086AE220
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086AEB24
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x01, 60, 0, 0
	.4byte 0x00000002
	.byte 0, 0, 15, 0  @ CGB square 1
	.byte 0x00, 60, 0, 0
	.4byte sample_086AEDD8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086AFD20
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086AFFDC
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 60, 0, 0
	.4byte sample_086B31A8
	.byte 128, 188, 154, 165  @ DirectSound
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 1, 1, 1
	.4byte 0x01010101
	.byte 1, 1, 1, 1  @ CGB square 1
	.byte 0x01, 1, 1, 1
	.4byte 0x01010101
	.byte 1, 1, 1, 1  @ CGB square 1
	.byte 0x01, 1, 1, 1
	.4byte 0x01010101
	.byte 1, 1, 1, 1  @ CGB square 1
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 1, 1, 1
	.4byte 0x01010101
	.byte 1, 1, 1, 1  @ CGB square 1
	.byte 0x01, 1, 1, 1
	.4byte 0x01010101
	.byte 1, 1, 1, 1  @ CGB square 1
	.byte 0x01, 1, 1, 1
	.4byte 0x01010101
	.byte 1, 1, 1, 1  @ CGB square 1
	.byte 0x00, 0x11, 0x23, 0x56, 0x89, 0xAC, 0xDE, 0xEF, 0xFF, 0xEE, 0xDC, 0xA9, 0x86, 0x53, 0x21, 0x10
	.byte 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10
	.byte 0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00
	.byte 0xFE, 0xDC, 0xBA, 0x99, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x77, 0x77, 0x66, 0x54, 0x32, 0x10
	.byte 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.global cgb_wave_0858D344
cgb_wave_0858D344: @ 0x0858D344
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
