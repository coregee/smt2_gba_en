// compiler: old_agbcc
/* Nintendo MusicPlayer2000 sound library, C part (the assembly part is SoundMain..ply_note in
   asm/).  Reconstructed from the pret m4a.c layout; this game links an older revision whose
   MPlayContinue has no ident lock. */

#include "global.h"
#include "gba/m4a_internal.h"

// MidiKeyToFreq @ 0x080E2EFC
u32 MidiKeyToFreq(struct WaveData *wav, u8 key, u8 fineAdjust)
{
    u32 val1, val2;
    u32 fineAdjustShifted = fineAdjust << 24;

    if (key > 178)
    {
        key = 178;
        fineAdjustShifted = 255 << 24;
    }

    val1 = gScaleTable[key];
    val1 = gFreqTable[val1 & 0xF] >> (val1 >> 4);

    val2 = gScaleTable[key + 1];
    val2 = gFreqTable[val2 & 0xF] >> (val2 >> 4);

    return umul3232H32(wav->freq, val1 + umul3232H32(val2 - val1, fineAdjustShifted));
}

// UnusedDummyFunc @ 0x080E2F60
void UnusedDummyFunc(void)
{
}

// MPlayContinue @ 0x080E2F64
#ifdef NONMATCHING
void MPlayContinue(struct MusicPlayerInfo *mplayInfo)
{
    if (mplayInfo->ident == ID_NUMBER)
        mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
}
#else
NAKED
void MPlayContinue(struct MusicPlayerInfo *mplayInfo)
{
    asm_unified(
        ".L080E2F64:\n"
        "    adds r2, r0, #0\n"
        "    ldr r3, [r2, #0x34]\n"
        "    ldr r0, .L080E2F78\n"
        "    cmp r3, r0\n"
        "    bne .L080E2F76\n"
        "    ldr r0, [r2, #4]\n"
        "    ldr r1, .L080E2F7C\n"
        "    ands r0, r1\n"
        "    str r0, [r2, #4]\n"
        ".L080E2F76:\n"
        "    bx lr\n"
        ".L080E2F78: .4byte 0x68736D53\n"
        ".L080E2F7C: .4byte 0x7FFFFFFF\n"
    );
}
#endif

// MPlayFadeOut @ 0x080E2F80
#ifdef NONMATCHING
void MPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = (64 << FADE_VOL_SHIFT);
    }
}
#else
NAKED
void MPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    asm_unified(
        ".L080E2F80:\n"
        "    adds r2, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    ldr r3, [r2, #0x34]\n"
        "    ldr r0, .L080E2F9C\n"
        "    cmp r3, r0\n"
        "    bne .L080E2F98\n"
        "    strh r1, [r2, #0x26]\n"
        "    strh r1, [r2, #0x24]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    strh r0, [r2, #0x28]\n"
        ".L080E2F98:\n"
        "    bx lr\n"
        "    .byte 0x00, 0x00\n"
        ".L080E2F9C: .4byte 0x68736D53\n"
    );
}
#endif

// m4aSoundInit @ 0x080E2FA0
void m4aSoundInit(void)
{
    s32 i;

    CpuSet((void *)((s32)SoundMainRAM & ~1), SoundMainRAM_Buffer, CPU_SET_32BIT | (0x380 / 4));

    SoundInit(gSoundInfo);
    MPlayExtender(gCgbChans);
    m4aSoundMode(0x0095FB00);

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
    {
        struct MusicPlayerInfo *mplayInfo = gMPlayTable[i].info;
        MPlayOpen(mplayInfo, gMPlayTable[i].track, gMPlayTable[i].numTracks);
        mplayInfo->unk_B = gMPlayTable[i].unk_A;
        mplayInfo->memAccArea = gMPlayMemAccArea;
    }
}

// m4aSoundMain @ 0x080E3018
void m4aSoundMain(void)
{
    SoundMain();
}

// m4aSongNumStart @ 0x080E3024
void m4aSongNumStart(u16 n)
{
    const struct MusicPlayer *mplayTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[n];
    const struct MusicPlayer *mplay = &mplayTable[song->ms];

    MPlayStart(mplay->info, song->header);
}

// m4aSongNumStartOrChange @ 0x080E3050
void m4aSongNumStartOrChange(u16 n)
{
    const struct MusicPlayer *mplayTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[n];
    const struct MusicPlayer *mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader != song->header)
    {
        MPlayStart(mplay->info, song->header);
    }
    else
    {
        if ((mplay->info->status & MUSICPLAYER_STATUS_TRACK) == 0
         || (mplay->info->status & MUSICPLAYER_STATUS_PAUSE))
        {
            MPlayStart(mplay->info, song->header);
        }
    }
}

// m4aSongNumStartOrContinue @ 0x080E309C
void m4aSongNumStartOrContinue(u16 n)
{
    const struct MusicPlayer *mplayTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[n];
    const struct MusicPlayer *mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader != song->header)
        MPlayStart(mplay->info, song->header);
    else if ((mplay->info->status & MUSICPLAYER_STATUS_TRACK) == 0)
        MPlayStart(mplay->info, song->header);
    else if (mplay->info->status & MUSICPLAYER_STATUS_PAUSE)
        MPlayContinue(mplay->info);
}

// m4aSongNumStop @ 0x080E30F0
void m4aSongNumStop(u16 n)
{
    const struct MusicPlayer *mplayTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[n];
    const struct MusicPlayer *mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader == song->header)
        m4aMPlayStop(mplay->info);
}

// m4aSongNumContinue @ 0x080E3124
void m4aSongNumContinue(u16 n)
{
    const struct MusicPlayer *mplayTable = gMPlayTable;
    const struct Song *songTable = gSongTable;
    const struct Song *song = &songTable[n];
    const struct MusicPlayer *mplay = &mplayTable[song->ms];

    if (mplay->info->songHeader == song->header)
        MPlayContinue(mplay->info);
}

// m4aMPlayAllStop @ 0x080E3158
void m4aMPlayAllStop(void)
{
    s32 i;

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
        m4aMPlayStop(gMPlayTable[i].info);
}

// m4aMPlayContinue @ 0x080E3184
void m4aMPlayContinue(struct MusicPlayerInfo *mplayInfo)
{
    MPlayContinue(mplayInfo);
}

// m4aMPlayAllContinue @ 0x080E3190
void m4aMPlayAllContinue(void)
{
    s32 i;

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
        MPlayContinue(gMPlayTable[i].info);
}

// m4aMPlayFadeOut @ 0x080E31BC
void m4aMPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    MPlayFadeOut(mplayInfo, speed);
}

// m4aMPlayFadeOutTemporarily @ 0x080E31CC
#ifdef NONMATCHING
void m4aMPlayFadeOutTemporarily(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = (64 << FADE_VOL_SHIFT) | TEMPORARY_FADE;
    }
}
#else
NAKED
void m4aMPlayFadeOutTemporarily(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    asm_unified(
        "    adds r2, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    ldr r3, [r2, #0x34]\n"
        "    ldr r0, .L080E31E4\n"
        "    cmp r3, r0\n"
        "    bne .L080E31E2\n"
        "    strh r1, [r2, #0x26]\n"
        "    strh r1, [r2, #0x24]\n"
        "    ldr r0, .L080E31E8\n"
        "    strh r0, [r2, #0x28]\n"
        ".L080E31E2:\n"
        "    bx lr\n"
        ".L080E31E4: .4byte 0x68736D53\n"
        ".L080E31E8: .4byte 0x00000101\n"
    );
}
#endif

// m4aMPlayFadeIn @ 0x080E31EC
#ifdef NONMATCHING
void m4aMPlayFadeIn(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    if (mplayInfo->ident == ID_NUMBER)
    {
        mplayInfo->fadeOC = speed;
        mplayInfo->fadeOI = speed;
        mplayInfo->fadeOV = (0 << FADE_VOL_SHIFT) | FADE_IN;
        mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
    }
}
#else
NAKED
void m4aMPlayFadeIn(struct MusicPlayerInfo *mplayInfo, u16 speed)
{
    asm_unified(
        "    adds r2, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    ldr r3, [r2, #0x34]\n"
        "    ldr r0, .L080E320C\n"
        "    cmp r3, r0\n"
        "    bne .L080E320A\n"
        "    strh r1, [r2, #0x26]\n"
        "    strh r1, [r2, #0x24]\n"
        "    movs r0, #2\n"
        "    strh r0, [r2, #0x28]\n"
        "    ldr r0, [r2, #4]\n"
        "    ldr r1, .L080E3210\n"
        "    ands r0, r1\n"
        "    str r0, [r2, #4]\n"
        ".L080E320A:\n"
        "    bx lr\n"
        ".L080E320C: .4byte 0x68736D53\n"
        ".L080E3210: .4byte 0x7FFFFFFF\n"
    );
}
#endif

// m4aMPlayImmInit @ 0x080E3214
void m4aMPlayImmInit(struct MusicPlayerInfo *mplayInfo)
{
    s32 trackCount = mplayInfo->trackCount;
    struct MusicPlayerTrack *track = mplayInfo->tracks;

    while (trackCount > 0)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            if (track->flags & MPT_FLG_START)
            {
                Clear64byte(track);
                track->flags = MPT_FLG_EXIST;
                track->bendRange = 2;
                track->volX = 64;
                track->lfoSpeed = 22;
                track->tone.type = 1;
            }
        }

        trackCount--;
        track++;
    }
}
