#ifndef GUARD_GBA_M4A_INTERNAL_H
#define GUARD_GBA_M4A_INTERNAL_H

/* Nintendo MusicPlayer2000 ("m4a") structures, as laid out by this game's (older) library
   version.  Offsets are noted where the code proves them. */

#define ID_NUMBER 0x68736D53 /* "Smsh" */

#define MUSICPLAYER_STATUS_TRACK 0x0000FFFF
#define MUSICPLAYER_STATUS_PAUSE 0x80000000

#define MPT_FLG_START 0x40
#define MPT_FLG_EXIST 0x80

#define FADE_IN 0x2
#define TEMPORARY_FADE 0x1
#define FADE_VOL_SHIFT 2

struct WaveData
{
    u16 type;
    u16 status;
    u32 freq;        /* 0x04 */
    u32 loopStart;
    u32 size;
    s8 data[1];
};

struct ToneData
{
    u8 type;
    u8 key;
    u8 length;
    u8 pan_sweep;
    struct WaveData *wav;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};

struct SongHeader
{
    u8 trackCount;
    u8 blockCount;
    u8 priority;
    u8 reverb;
    struct ToneData *tone;
    u8 *part[1];
};

struct MusicPlayerTrack
{
    u8 flags;              /* 0x00 */
    u8 wait;
    u8 patternLevel;
    u8 repN;
    u8 gateTime;
    u8 key;
    u8 velocity;
    u8 runningStatus;
    u8 keyM;               /* 0x08 */
    u8 pitM;
    s8 keyShift;
    s8 keyShiftX;
    s8 tune;
    u8 pitX;
    s8 bend;
    u8 bendRange;          /* 0x0F */
    u8 volMR;              /* 0x10 */
    u8 volML;
    u8 vol;
    u8 volX;               /* 0x13 */
    s8 pan;
    s8 panX;
    s8 modM;
    u8 mod;
    u8 modT;               /* 0x18 */
    u8 lfoSpeed;           /* 0x19 */
    u8 lfoSpeedC;
    u8 lfoDelay;
    u8 lfoDelayC;
    u8 priority;
    u8 pseudoEchoVolume;
    u8 pseudoEchoLength;
    void *chan;            /* 0x20 */
    struct ToneData tone;  /* 0x24 */
    u8 gap[10];
    u16 unk_3A;
    u32 unk_3C;
    u8 *cmdPtr;            /* 0x40 */
    u8 *patternStack[3];
};

struct MusicPlayerInfo
{
    struct SongHeader *songHeader;   /* 0x00 */
    u32 status;                      /* 0x04 */
    u8 trackCount;                   /* 0x08 */
    u8 priority;
    u8 cmd;
    u8 unk_B;                        /* 0x0B */
    u32 clock;
    u8 gap[8];
    u8 *memAccArea;                  /* 0x18 */
    u16 tempoD;
    u16 tempoU;
    u16 tempoI;
    u16 tempoC;
    u16 fadeOI;                      /* 0x24 */
    u16 fadeOC;                      /* 0x26 */
    u16 fadeOV;                      /* 0x28 */
    struct MusicPlayerTrack *tracks; /* 0x2C */
    struct ToneData *tone;
    u32 ident;                       /* 0x34 */
    void *func;
    void *intp;
};

struct MusicPlayer
{
    struct MusicPlayerInfo *info;
    struct MusicPlayerTrack *track;
    u8 numTracks;
    u16 unk_A;
};

struct Song
{
    struct SongHeader *header;
    u16 ms;
    u16 me;
};

extern const struct MusicPlayer gMPlayTable[];
extern const struct Song gSongTable[];
extern const u8 gScaleTable[];
extern const u32 gFreqTable[];
extern char gNumMusicPlayers[];   /* absolute symbol: its address is the count */
#define NUM_MUSIC_PLAYERS ((u16)(u32)gNumMusicPlayers)

extern u8 gSoundInfo[];
extern u8 gCgbChans[];
extern u8 gMPlayMemAccArea[];
extern u8 SoundMainRAM_Buffer[];

u32 umul3232H32(u32 multiplier, u32 multiplicand);
void SoundMain(void);
void SoundMainRAM(void);
void SoundInit(void *soundInfo);
void MPlayExtender(void *cgbChans);
void m4aSoundMode(u32 mode);
void MPlayOpen(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *tracks, u8 trackCount);
void MPlayStart(struct MusicPlayerInfo *mplayInfo, struct SongHeader *songHeader);
void m4aMPlayStop(struct MusicPlayerInfo *mplayInfo);
void Clear64byte(void *addr);

#endif
