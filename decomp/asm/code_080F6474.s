	.include "asm/macros.inc"

	.syntax unified
	.text

	.byte 0x06, 0x00, 0x00, 0x40, 0x00, 0xC0, 0x00, 0x03, 0x00, 0x80, 0x40, 0x80, 0x08, 0x03, 0x20, 0x40
	.byte 0x00, 0xC0, 0x0A, 0x03, 0x20, 0x80, 0x40, 0x80, 0x12, 0x03, 0x40, 0x40, 0x00, 0xC0, 0x14, 0x03
	.byte 0x40, 0x80, 0x40, 0x80, 0x1C, 0x03, 0x00, 0x00
	.global gUnknown_080F649C
gUnknown_080F649C: @ 0x080F649C
	.incbin "baserom.gba", 0xF649C, 0x22828
	.global gUnknown_08118CC4
gUnknown_08118CC4: @ 0x08118CC4
	.byte 0xB0, 0x8C, 0x11, 0x08, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0xBC, 0x40, 0xF7, 0x01, 0x02, 0x00
	.byte 0xC4, 0x00, 0xEF, 0x81, 0x04, 0x00, 0xE4, 0x00, 0xEF, 0x81, 0x08, 0x00
	.global gUnknown_08118CE0
gUnknown_08118CE0: @ 0x08118CE0
	.incbin "baserom.gba", 0x118CE0, 0xA358
.Lspan_08123038:
	.include "assets/text/battle.s"
	.global gUnknown_081230A8
	.set gUnknown_081230A8, .Lspan_08123038 + 0x70
	.global gUnknown_081230BE
	.set gUnknown_081230BE, .Lspan_08123038 + 0x86
	.global gUnknown_081230DC
	.set gUnknown_081230DC, .Lspan_08123038 + 0xA4
	.global gUnknown_0812310C
	.set gUnknown_0812310C, .Lspan_08123038 + 0xD4
	.global gUnknown_0812326A
	.set gUnknown_0812326A, .Lspan_08123038 + 0x232
	.global gUnknown_081232AE
	.set gUnknown_081232AE, .Lspan_08123038 + 0x276
	.global gUnknown_08123374
	.set gUnknown_08123374, .Lspan_08123038 + 0x33C
	.global gUnknown_081233D2
	.set gUnknown_081233D2, .Lspan_08123038 + 0x39A
	.global gUnknown_08123444
	.set gUnknown_08123444, .Lspan_08123038 + 0x40C
	.global gUnknown_081236BC
	.set gUnknown_081236BC, .Lspan_08123038 + 0x684
	.global gUnknown_081236FC
	.set gUnknown_081236FC, .Lspan_08123038 + 0x6C4
	.global gUnknown_08123708
	.set gUnknown_08123708, .Lspan_08123038 + 0x6D0
	.global gUnknown_08123BC2
	.set gUnknown_08123BC2, .Lspan_08123038 + 0xB8A
	.global gUnknown_08123BCC
	.set gUnknown_08123BCC, .Lspan_08123038 + 0xB94
	.global gUnknown_08123DF0
	.set gUnknown_08123DF0, .Lspan_08123038 + 0xDB8
	.global gUnknown_081240A0
	.set gUnknown_081240A0, .Lspan_08123038 + 0x1068
	.global gUnknown_081240BC
	.set gUnknown_081240BC, .Lspan_08123038 + 0x1084
	.global gUnknown_081240F0
	.set gUnknown_081240F0, .Lspan_08123038 + 0x10B8
	.global gUnknown_0812410A
	.set gUnknown_0812410A, .Lspan_08123038 + 0x10D2
	.global gUnknown_08124154
	.set gUnknown_08124154, .Lspan_08123038 + 0x111C
	.global gUnknown_0812416C
	.set gUnknown_0812416C, .Lspan_08123038 + 0x1134
	.global gUnknown_08124182
	.set gUnknown_08124182, .Lspan_08123038 + 0x114A
	.global gUnknown_08124198
	.set gUnknown_08124198, .Lspan_08123038 + 0x1160
	.global gUnknown_081241B0
	.set gUnknown_081241B0, .Lspan_08123038 + 0x1178
	.global gUnknown_081241D0
	.set gUnknown_081241D0, .Lspan_08123038 + 0x1198
	.global gUnknown_081241E0
	.set gUnknown_081241E0, .Lspan_08123038 + 0x11A8
	.global gUnknown_081241F0
	.set gUnknown_081241F0, .Lspan_08123038 + 0x11B8
	.global gUnknown_08124200
	.set gUnknown_08124200, .Lspan_08123038 + 0x11C8
	.global gUnknown_08124218
	.set gUnknown_08124218, .Lspan_08123038 + 0x11E0
	.global gUnknown_08124234
	.set gUnknown_08124234, .Lspan_08123038 + 0x11FC
	.global gUnknown_08124264
	.set gUnknown_08124264, .Lspan_08123038 + 0x122C
	.global gUnknown_08124270
	.set gUnknown_08124270, .Lspan_08123038 + 0x1238
	.global gUnknown_08124284
	.set gUnknown_08124284, .Lspan_08123038 + 0x124C
	.global gUnknown_0812428E
	.set gUnknown_0812428E, .Lspan_08123038 + 0x1256
	.global gUnknown_081242CE
	.set gUnknown_081242CE, .Lspan_08123038 + 0x1296
	.global gUnknown_081242EC
	.set gUnknown_081242EC, .Lspan_08123038 + 0x12B4
	.global gUnknown_081242FC
	.set gUnknown_081242FC, .Lspan_08123038 + 0x12C4
	.global gUnknown_0812430C
	.set gUnknown_0812430C, .Lspan_08123038 + 0x12D4
	.global gUnknown_08124316
	.set gUnknown_08124316, .Lspan_08123038 + 0x12DE
	.global gUnknown_0812434A
	.set gUnknown_0812434A, .Lspan_08123038 + 0x1312
	.global gUnknown_08124364
	.set gUnknown_08124364, .Lspan_08123038 + 0x132C
	.global gUnknown_0812437C
	.set gUnknown_0812437C, .Lspan_08123038 + 0x1344
	.global gUnknown_0812439A
	.set gUnknown_0812439A, .Lspan_08123038 + 0x1362
	.global gUnknown_081243B0
	.set gUnknown_081243B0, .Lspan_08123038 + 0x1378
	.global gUnknown_081243C6
	.set gUnknown_081243C6, .Lspan_08123038 + 0x138E
	.global gUnknown_081243EE
	.set gUnknown_081243EE, .Lspan_08123038 + 0x13B6
	.global gUnknown_0812440A
	.set gUnknown_0812440A, .Lspan_08123038 + 0x13D2
	.global gUnknown_08124426
	.set gUnknown_08124426, .Lspan_08123038 + 0x13EE
	.global gUnknown_0812443C
	.set gUnknown_0812443C, .Lspan_08123038 + 0x1404
	.global gUnknown_08124452
	.set gUnknown_08124452, .Lspan_08123038 + 0x141A
	.global gUnknown_081244BA
	.set gUnknown_081244BA, .Lspan_08123038 + 0x1482
	.global gUnknown_081244C4
	.set gUnknown_081244C4, .Lspan_08123038 + 0x148C
	.global gUnknown_08124514
	.set gUnknown_08124514, .Lspan_08123038 + 0x14DC
	.global gUnknown_08124534
	.set gUnknown_08124534, .Lspan_08123038 + 0x14FC
	.global gUnknown_08124570
	.set gUnknown_08124570, .Lspan_08123038 + 0x1538
	.global gUnknown_081245B4
	.set gUnknown_081245B4, .Lspan_08123038 + 0x157C
	.global gUnknown_081245D2
	.set gUnknown_081245D2, .Lspan_08123038 + 0x159A
	.global gUnknown_081245F6
	.set gUnknown_081245F6, .Lspan_08123038 + 0x15BE
	.global gUnknown_08124608
	.set gUnknown_08124608, .Lspan_08123038 + 0x15D0
	.global gUnknown_0812461A
	.set gUnknown_0812461A, .Lspan_08123038 + 0x15E2
	.global gUnknown_0812463A
	.set gUnknown_0812463A, .Lspan_08123038 + 0x1602
	.global gUnknown_0812464E
	.set gUnknown_0812464E, .Lspan_08123038 + 0x1616
	.global gUnknown_0812466C
	.set gUnknown_0812466C, .Lspan_08123038 + 0x1634
	.global gUnknown_0812490C
	.set gUnknown_0812490C, .Lspan_08123038 + 0x18D4
	.global gUnknown_08124A50
	.set gUnknown_08124A50, .Lspan_08123038 + 0x1A18
	.global gUnknown_08124A62
	.set gUnknown_08124A62, .Lspan_08123038 + 0x1A2A
	.global gUnknown_08124BD2
	.set gUnknown_08124BD2, .Lspan_08123038 + 0x1B9A
	.global gUnknown_08124BF4
	.set gUnknown_08124BF4, .Lspan_08123038 + 0x1BBC
	.global gUnknown_08124C20
	.set gUnknown_08124C20, .Lspan_08123038 + 0x1BE8
	.global gUnknown_08124C38
	.set gUnknown_08124C38, .Lspan_08123038 + 0x1C00
	.global gUnknown_08124CC8
	.set gUnknown_08124CC8, .Lspan_08123038 + 0x1C90
	.global gUnknown_08124CE6
	.set gUnknown_08124CE6, .Lspan_08123038 + 0x1CAE
	.global gUnknown_08124D5E
	.set gUnknown_08124D5E, .Lspan_08123038 + 0x1D26
	.global gUnknown_08124D72
	.set gUnknown_08124D72, .Lspan_08123038 + 0x1D3A
	.global gUnknown_08124DBC
	.set gUnknown_08124DBC, .Lspan_08123038 + 0x1D84
	.global gUnknown_08124DD8
	.set gUnknown_08124DD8, .Lspan_08123038 + 0x1DA0
	.global gUnknown_08124EFA
	.set gUnknown_08124EFA, .Lspan_08123038 + 0x1EC2
	.global gUnknown_08124F12
	.set gUnknown_08124F12, .Lspan_08123038 + 0x1EDA
	.global gUnknown_08124F2C
	.set gUnknown_08124F2C, .Lspan_08123038 + 0x1EF4
	.global gUnknown_08124F46
	.set gUnknown_08124F46, .Lspan_08123038 + 0x1F0E
	.global gUnknown_08124F60
	.set gUnknown_08124F60, .Lspan_08123038 + 0x1F28
	.global gUnknown_08124F82
	.set gUnknown_08124F82, .Lspan_08123038 + 0x1F4A
	.global gUnknown_08126254
	.set gUnknown_08126254, .Lspan_08123038 + 0x321C
	.global gUnknown_081262BE
	.set gUnknown_081262BE, .Lspan_08123038 + 0x3286
	.global gUnknown_0812634E
	.set gUnknown_0812634E, .Lspan_08123038 + 0x3316
	.global gUnknown_08126368
	.set gUnknown_08126368, .Lspan_08123038 + 0x3330
	.global gUnknown_081265BE
	.set gUnknown_081265BE, .Lspan_08123038 + 0x3586
	.global gUnknown_081267A6
	.set gUnknown_081267A6, .Lspan_08123038 + 0x376E
	.global gUnknown_081267BA
	.set gUnknown_081267BA, .Lspan_08123038 + 0x3782
	.global gUnknown_081267E0
	.set gUnknown_081267E0, .Lspan_08123038 + 0x37A8
