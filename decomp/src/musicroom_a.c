#include "global.h"
#include "extras.h"

/* Task data of the music player at 0x080DD278.. (the extras' sound test). Seven buttons:
   previous, stop, play, next, continuous, shuffle, exit. The playlist holds the 27 tracks
   1..27 (Cards_Deal, shuffled when shuffle is on). */
struct MusicRoom
{
    u8 state;                    /* 0x00: 0 stopped, 1 playing, 2 idle, 3 leaving */
    s8 cursor;                   /* 0x01: button 0-6 (two rows, 0-3 and 4-6) */
    s8 track;                    /* 0x02: index into gUnknown_085861C8 */
    u8 continuous;               /* 0x03: play the next track at the end */
    u8 shuffle;                  /* 0x04 */
    u8 flash[7];                 /* 0x05: per-button highlight timers */
    u8 min, sec, frame;          /* 0x0C: play time */
    u8 pad0F;
    s16 idle;                    /* 0x10 */
    u16 song;                    /* 0x12 */
    s8 index;                    /* 0x14: position in the playlist */
    u8 playlist[27];             /* 0x15 */
    u8 view;                     /* 0x30: 0-2, changed with SELECT */
};

/* Per track: song number, length (minutes, seconds) and title (sprite-font string). */
struct MusicTrack
{
    u16 song;
    u8 min;
    u8 sec;
    const u16 *title;
};

/* Per button: position and the normal and pressed sprites. */
struct MusicButton
{
    u16 x, y;
    const void *normal;
    const void *pressed;
};
extern const struct MusicButton gUnknown_0858614C[7];
extern const void *const gUnknown_085861A0[10];
extern const u8 gUnknown_080087B8[], gUnknown_08008958[], gUnknown_08008C44[];
extern const u8 gUnknown_08008890[], gUnknown_08008928[], gUnknown_080088F0[], gUnknown_080088C0[];
void Text_DrawSpriteStringTinted(const u16 *str, u32 a1, u32 a2, u32 x, u32 y, u32 advance, u32 tint);
extern const struct MusicTrack gUnknown_085861C8[];
extern u16 gUnk_030031B4;
void m4aSongNumStop(u16 n);
void Music_FadeOut(u32 a);

#define MR_PLAY(m)                                      \
{                                                       \
    (m)->flash[2] = 0xF;                                \
    (m)->flash[1] = 0;                                  \
    (m)->song = gUnknown_085861C8[(m)->track].song;     \
    Music_Play((m)->song);                              \
    gUnk_030031B4 = 0;                                  \
    (m)->state = 1;                                     \
    (m)->min = (m)->sec = (m)->frame = 0;               \
}

#define MR_STOP(m)                                      \
{                                                       \
    (m)->flash[1] = 0xF;                                \
    (m)->flash[2] = 0;                                  \
    if ((m)->state == 1)                                \
    {                                                   \
        (m)->state = 0;                                 \
        m4aSongNumStop((m)->song);                      \
        (m)->min = (m)->sec = (m)->frame = 0;           \
        gUnk_030031B4 = 0;                              \
    }                                                   \
}

/* Selects the playlist entry index, restarting the song if one is playing. */
#define MR_SELECT(m)                                    \
{                                                       \
    (m)->track = (m)->playlist[(m)->index];             \
    (m)->song = gUnknown_085861C8[(m)->track].song;     \
    if ((m)->state == 1)                                \
    {                                                   \
        Music_Play((m)->song);                          \
        gUnk_030031B4 = 0;                              \
        (m)->state = 1;                                 \
        (m)->min = (m)->sec = (m)->frame = 0;           \
    }                                                   \
}

#define MR_NEXT(m)                                      \
{                                                       \
    (m)->flash[3] = 0xF;                                \
    if (++(m)->index > 26)                              \
        (m)->index = 0;                                 \
    MR_SELECT(m);                                       \
}

#define MR_PREV(m)                                      \
{                                                       \
    (m)->flash[0] = 0xF;                                \
    if (--(m)->index < 0)                               \
        (m)->index = 26;                                \
    MR_SELECT(m);                                       \
}

/* Input and timing of the music player. A presses the button under the cursor, B stops,
   START plays, SELECT changes the view, L/R pick the previous/next track. While playing,
   the time runs and at the track's length the song fades out, then the next track starts
   (continuous) or the player stops. Result 1 once the exit button's flash has run out. */
// MusicRoom_HandleInput @ 0x080DD30C
void MusicRoom_HandleInput(struct Task *task)
{
    struct MusicRoom *m = (struct MusicRoom *)&task->data;
    const struct MusicTrack *t;

    task->result = 0;
    task->unk1E = 0;
    if (m->state == 3)
    {
        if (m->flash[6] == 0)
            task->result = 1;
        return;
    }
    if (m->state == 2 && ++m->idle > 180)
    {
        m->idle = 0;
        m->state = 0;
    }
    if (gKeysNew & 1)
    {
        Sound_Play(0x65);
        switch (m->cursor)
        {
        case 0:
            MR_PREV(m);
            break;
        case 1:
            MR_STOP(m);
            break;
        case 2:
            MR_PLAY(m);
            break;
        case 3:
            MR_NEXT(m);
            break;
        case 4:
            m->flash[4] = 0xF;
            m->continuous = 1 - m->continuous;
            if (m->continuous == 1)
                Cards_Deal(task);
            break;
        case 5:
            m->flash[5] = 0xF;
            m->shuffle = 1 - m->shuffle;
            Cards_Deal(task);
            break;
        case 6:
            m->flash[6] = 0xF;
            m->state = 3;
            break;
        }
    }
    else if (gKeysNew & 2)
    {
        MR_STOP(m);
        Sound_Play(0x66);
    }
    else if (gKeysNew & 8)
    {
        MR_PLAY(m);
        Sound_Play(0x65);
    }
    else if (gKeysNew & 4)
    {
        if (++m->view > 2)
            m->view = 0;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x10)
    {
        if (++m->cursor == 4)
            m->cursor = 0;
        else if (m->cursor == 7)
            m->cursor = 4;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x20)
    {
        if (--m->cursor < 0)
            m->cursor = 3;
        else if (m->cursor == 3)
            m->cursor = 6;
        Sound_Play(0x64);
    }
    else if (gKeysNew & 0x40)
    {
        if (m->cursor > 3)
        {
            m->cursor -= 4;
            Sound_Play(0x64);
        }
    }
    else if (gKeysNew & 0x80)
    {
        if (m->cursor == 3)
        {
            m->cursor = 6;
            Sound_Play(0x64);
        }
        else if (m->cursor <= 3)
        {
            m->cursor += 4;
            Sound_Play(0x64);
        }
    }
    else if (gRepeatedKeys & 0x100)
    {
        MR_NEXT(m);
        Sound_Play(0x65);
    }
    else if (gRepeatedKeys & 0x200)
    {
        MR_PREV(m);
        Sound_Play(0x65);
    }

    if (m->state == 1)
    {
        m->frame++;
        if (m->frame > 59)
        {
            m->frame = 0;
            m->sec++;
            if (m->sec > 59)
            {
                m->sec = 0;
                m->min++;
            }
        }
    }
    t = &gUnknown_085861C8[m->track];
    if (m->min == t->min && m->sec == t->sec - 2 && m->frame == 0)
    {
        Music_FadeOut(8);
        return;
    }
    if (*(u16 *)&m->min == *(u16 *)&t->min && m->frame > 10)
    {
        if (m->continuous == 1)
        {
            if (++m->index > 26)
                m->index = 0;
            m->track = m->playlist[m->index];
            m->song = gUnknown_085861C8[m->track].song;
            Music_Play(m->song);
            gUnk_030031B4 = 0;
            m->state = 1;
            m->min = m->sec = m->frame = 0;
        }
        else
            MR_STOP(m);
    }
}

#define MR_SPRITE(def, x, y) Sprite_Draw(def, 0, 0xE, 0, 0x140, x, y)

/* Draws the music player: track number, shuffle marker, title (sprite font, 12-pixel
   advance at (0x15, 0x3A)), the continuous marker, the time in one of three views (elapsed,
   remaining, rolling seconds digit) and the buttons with their highlights. */
// MusicRoom_Draw @ 0x080DD7CC
void MusicRoom_Draw(struct Task *task)
{
    struct MusicRoom *m = (struct MusicRoom *)&task->data;
    u8 tens, ones;
    u8 cur, next;
    u8 stage;
    s8 min, sec;
    u8 pressed;
    const struct MusicButton *b;

    tens = m->track / 10;
    ones = m->track % 10;
    MR_SPRITE(gUnknown_085861A0[tens], 0x31, 0x2B);
    MR_SPRITE(gUnknown_085861A0[ones], 0x39, 0x2B);
    MR_SPRITE(gUnknown_080087B8, 0x78, m->shuffle * 9 + 0x20);
    Font_ResetGlyphSpriteCache(0x3C0);
    Text_DrawSpriteStringTinted(gUnknown_085861C8[m->track].title, 0, 0, 0x15, 0x3A, 12, 14);
    if (m->continuous == 1)
    {
        b = &gUnknown_0858614C[4];
        MR_SPRITE(gUnknown_08008958, b->x, b->y);
        MR_SPRITE(gUnknown_08008C44, 0x66, 0x41);
    }
    if (m->view == 0)
    {
        tens = m->min / 10;
        ones = m->min % 10;
        MR_SPRITE(gUnknown_085861A0[tens], 0x3B, 0x43);
        MR_SPRITE(gUnknown_085861A0[ones], 0x43, 0x43);
        tens = m->sec / 10;
        ones = m->sec % 10;
        MR_SPRITE(gUnknown_085861A0[tens], 0x53, 0x43);
        MR_SPRITE(gUnknown_085861A0[ones], 0x5B, 0x43);
    }
    else if (m->view == 1)
    {
        min = gUnknown_085861C8[m->track].min - m->min;
        sec = gUnknown_085861C8[m->track].sec - m->sec;
        if (min > 0 && sec < 0)
        {
            min--;
            sec += 60;
        }
        tens = min / 10;
        ones = min % 10;
        MR_SPRITE(gUnknown_085861A0[tens], 0x3B, 0x43);
        MR_SPRITE(gUnknown_085861A0[ones], 0x43, 0x43);
        tens = sec / 10;
        ones = sec % 10;
        MR_SPRITE(gUnknown_085861A0[tens], 0x53, 0x43);
        MR_SPRITE(gUnknown_085861A0[ones], 0x5B, 0x43);
    }
    else if (m->view == 2)
    {
        cur = m->sec % 10;
        next = cur + 1;
        if (next > 9)
            next = 0;
        if (m->frame < 12)
            stage = 0;
        else if (m->frame >= 12 && m->frame < 24)
            stage = 1;
        else if (m->frame >= 24 && m->frame < 36)
            stage = 2;
        else if (m->frame >= 36 && m->frame < 48)
            stage = 3;
        else if (m->frame >= 48 && m->frame < 60)
            stage = 4;
        if (stage == 0)
            MR_SPRITE(gUnknown_085861A0[cur], 0x3B, 0x43);
        else
            MR_SPRITE(gUnknown_085861A0[next], 0x3B, 0x43);
        if (stage <= 1)
            MR_SPRITE(gUnknown_085861A0[cur], 0x43, 0x43);
        else
            MR_SPRITE(gUnknown_085861A0[next], 0x43, 0x43);
        if (stage <= 2)
            MR_SPRITE(gUnknown_085861A0[cur], 0x53, 0x43);
        else
            MR_SPRITE(gUnknown_085861A0[next], 0x53, 0x43);
        if (stage <= 3)
            MR_SPRITE(gUnknown_085861A0[cur], 0x5B, 0x43);
        else
            MR_SPRITE(gUnknown_085861A0[next], 0x5B, 0x43);
    }

    /* the button under the cursor, pressed while its state holds */
    pressed = 0;
    if (*(u16 *)&m->state == 0x100)
        pressed = 1;
    if (*(u16 *)&m->state == 0x201 && m->flash[2] < 60)
        pressed = 1;
    if ((*(u32 *)&m->state & 0xFF00FF00) == 0x01000400)
        pressed = 1;
    if (m->cursor == 5 && m->shuffle == 1)
        pressed = 1;
    b = &gUnknown_0858614C[m->cursor];
    if (pressed == 1)
        MR_SPRITE(b->pressed, b->x, b->y);
    else
        MR_SPRITE(b->normal, b->x, b->y);

    if (m->flash[0] != 0)
    {
        m->flash[0]--;
        b = &gUnknown_0858614C[0];
        MR_SPRITE(gUnknown_08008890, b->x, b->y);
    }
    if (m->flash[3] != 0)
    {
        m->flash[3]--;
        b = &gUnknown_0858614C[3];
        MR_SPRITE(gUnknown_08008928, b->x, b->y);
    }
    if (m->flash[2] != 0)
    {
        if (--m->flash[2] < 45)
        {
            b = &gUnknown_0858614C[2];
            MR_SPRITE(gUnknown_080088F0, b->x, b->y);
        }
    }
    else if (m->state == 1)
        m->flash[2] = 90;
    if (m->flash[1] != 0)
    {
        b = &gUnknown_0858614C[1];
        MR_SPRITE(gUnknown_080088C0, b->x, b->y);
    }
    if (m->flash[6] != 0)
    {
        m->flash[6]--;
        b = &gUnknown_0858614C[6];
        MR_SPRITE(b->pressed, b->x, b->y);
    }
    if (m->flash[4] != 0)
    {
        m->flash[4]--;
        b = &gUnknown_0858614C[4];
        MR_SPRITE(b->pressed, b->x, b->y);
    }
    if (m->flash[5] != 0)
    {
        m->flash[5]--;
        b = &gUnknown_0858614C[5];
        MR_SPRITE(b->pressed, b->x, b->y);
    }
}
