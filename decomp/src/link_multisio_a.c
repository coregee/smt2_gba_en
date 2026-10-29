#include "global.h"
#include "extras.h"

/* Link cable driver at 0x030061C0. The layout and the code follow the multi-play SIO sample
   library of the AGB SDK (MultiSioMain, MultiSioSendDataSet, MultiSioRecvDataCheck,
   MultiSioIntr); field names are after that library. Packets are 0x18 bytes: frame counter,
   receive-error flags, checksum, 16 data bytes and two overrun words; 10 halfwords are sent
   per frame. */
struct MultiSioPacket
{
    u8 frameCounter;             /* 0x00 */
    u8 recvErrorFlags;           /* 0x01 */
    u16 checkSum;                /* 0x02 */
    u32 data[4];                 /* 0x04 */
    u16 overRunCatch[2];         /* 0x14 */
};

struct MultiSioArea
{
    u8 type;                     /* 0x00: 8 = master (parent) */
    u8 state;                    /* 0x01 */
    u8 connectedFlags;           /* 0x02 */
    u8 recvSuccessFlags;         /* 0x03 */
    u8 sendBufFlag;              /* 0x04 */
    u8 recvDone;                 /* 0x05 */
    u8 startFlag;                /* 0x06 */
    u8 hardError;                /* 0x07 */
    u8 syncCounter;              /* 0x08 */
    u8 intrFlag;                 /* 0x09 */
    u8 pad0A;
    u8 sendFrameCounter;         /* 0x0B */
    u8 pad0C[8];
    s32 sendBufCounter;          /* 0x14 */
    s32 recvBufCounter;          /* 0x18 */
    struct MultiSioPacket *nextSendBufp;    /* 0x1C */
    struct MultiSioPacket *currentSendBufp; /* 0x20 */
    struct MultiSioPacket *currentRecvBufp; /* 0x24 */
    struct MultiSioPacket *lastRecvBufp;    /* 0x28 */
    struct MultiSioPacket *recvCheckBufp;   /* 0x2C */
};
#define gMultiSio (*(struct MultiSioArea *)gUnk_030061C0)

/* REG_SIOCNT in multi-player mode, followed by REG_SIOMLT_SEND. */
struct SioMultiCnt
{
    u16 baudRate:2;
    u16 si:1;
    u16 sd:1;
    u16 id:2;
    u16 error:1;
    u16 enable:1;
    u16 unused8:4;
    u16 mode:2;
    u16 ifEnable:1;
    u16 unused15:1;
    u16 data;
};

#define SIO_MULTI_CNT ((struct SioMultiCnt *)(REG_BASE + 0x128))
#define INTR_CHECK (*(vu16 *)0x03007FF8)

u32 MultiSio_CheckRecvData(void *recvp);

/* Once per frame: the master/slave decision (state 0), waits 8 frames for the others (1),
   then checks the received packets into recvp (2 slots of 16 bytes). Returns the status:
   bits 0-1 received this frame, 8-9 connected, 7 master, 12 hardware error, 13 player id
   >= 2, 15 synchronised. */
// MultiSio_Main @ 0x080DEF50
u32 MultiSio_Main(void *recvp)
{
    struct SioMultiCnt *cntp = (struct SioMultiCnt *)&REG_SIOCNT;
    struct SioMultiCnt cnt;

    cnt = *cntp;
    switch (gMultiSio.state)
    {
    case 0:
        if (gMultiSio.recvBufCounter == 11)
        {
            if (!cnt.sd || cnt.enable)
                break;
            if (!cnt.si)
            {
                REG_IME = 0;
                REG_IE &= 0xFF7F;
                REG_IE |= 0x40;
                REG_IME = 1;
                cntp->ifEnable = 0;
                *(vu32 *)(REG_BASE + 0x10C) = 0xABFB;
                REG_IF = 0xC0;
                gMultiSio.type = 8;
            }
        }
        gMultiSio.state = 1;
    case 1:
        if (gMultiSio.connectedFlags)
        {
            if (gMultiSio.syncCounter < 8)
                gMultiSio.syncCounter++;
            else
                gMultiSio.state = 2;
        }
    case 2:
        MultiSio_CheckRecvData(recvp);
        break;
    }
    gMultiSio.sendFrameCounter++;
    return gMultiSio.recvSuccessFlags
         | (gMultiSio.type == 8) << 7
         | gMultiSio.connectedFlags << 8
         | (gMultiSio.hardError != 0) << 12
         | (cnt.id > 1) << 13
         | (gMultiSio.syncCounter >> 3) << 15;
}

/* Builds the next packet from 16 bytes at sendp. */
// MultiSio_SetSendData @ 0x080DF05C
void MultiSio_SetSendData(void *sendp)
{
    s32 checkSum = 0;
    u32 i;

    gMultiSio.nextSendBufp->frameCounter = gMultiSio.sendFrameCounter;
    gMultiSio.nextSendBufp->recvErrorFlags = gMultiSio.connectedFlags ^ gMultiSio.recvSuccessFlags;
    gMultiSio.nextSendBufp->checkSum = 0;
    CpuSet(sendp, gMultiSio.nextSendBufp->data, 0x04000004);
    for (i = 0; i < 10; i++)
        checkSum += ((u16 *)gMultiSio.nextSendBufp)[i];
    gMultiSio.nextSendBufp->checkSum = ~checkSum - 12;
    gMultiSio.sendBufFlag = 1;
}

/* Swaps in the last received packets (arm_08032B7C, run from IWRAM) and copies each valid
   packet (checksum) to recvp + 16 * player. Returns the players received. */
// MultiSio_CheckRecvData @ 0x080DF0AC
u32 MultiSio_CheckRecvData(void *recvp)
{
    u8 (*recvBufChange)(void) = (u8 (*)(void))gUnk_030062B0;
    u8 recvd;
    s32 checkSum;
    vu32 recvCheck = 0;
    u32 zero;
    s32 i;
    u32 j;

    recvd = recvBufChange();
    gMultiSio.recvSuccessFlags = 0;
    if (recvd)
    {
        for (i = 0; i < 2; i++)
        {
            struct MultiSioPacket *pkt = &gMultiSio.recvCheckBufp[i];

            checkSum = 0;
            for (j = 0; j < 10; j++)
                checkSum += ((u16 *)pkt)[j];
            if ((s16)checkSum == -13)
            {
                CpuSet(pkt->data, (u8 *)recvp + i * 16, 0x04000004);
                gMultiSio.recvSuccessFlags |= 1 << i;
            }
            zero = 0;
            CpuSet(&zero, pkt->data, 0x05000004);
        }
    }
    gMultiSio.connectedFlags |= gMultiSio.recvSuccessFlags;
    return gMultiSio.recvSuccessFlags;
}

/* Master: starts the frame's transfer once started (swaps the buffers like the interrupt).
   Slave: re-arms the serial interrupt check if no interrupt came. */
// MultiSio_StartTransfer @ 0x080DF15C
void MultiSio_StartTransfer(void)
{
    struct MultiSioPacket *tmp;

    if (gMultiSio.type)
    {
        if (gMultiSio.state && gMultiSio.startFlag)
        {
            gMultiSio.recvBufCounter = -1;
            tmp = gMultiSio.lastRecvBufp;
            gMultiSio.lastRecvBufp = gMultiSio.currentRecvBufp;
            gMultiSio.currentRecvBufp = tmp;
            if (gMultiSio.sendBufFlag)
            {
                tmp = gMultiSio.currentSendBufp;
                gMultiSio.currentSendBufp = gMultiSio.nextSendBufp;
                gMultiSio.nextSendBufp = tmp;
                gMultiSio.sendBufFlag = 0;
                gMultiSio.sendBufCounter = 0;
            }
            gMultiSio.hardError = SIO_MULTI_CNT->error;
            SIO_MULTI_CNT->data = 0xFEFE;
            *(vu16 *)SIO_MULTI_CNT |= 0x80;
            *(vu16 *)(REG_BASE + 0x10E) = 0xC0;
        }
    }
    else
    {
        if (!gMultiSio.intrFlag)
        {
            REG_IME = 0;
            INTR_CHECK |= 0x80;
            REG_IME = 1;
        }
        gMultiSio.intrFlag = 0;
    }
}

/* Serial and timer 3 interrupt: stores the halfword received from each player, sends the
   next halfword, and (master) restarts the transfer through timer 3. */
// SerialTimer3Intr @ 0x080DF1EC
void SerialTimer3Intr(void)
{
    u16 recvTmp[4];
    struct MultiSioPacket *tmp;
    s32 i;

    *(unsigned long long *)recvTmp = *(unsigned long long *)(REG_BASE + 0x120);
    gMultiSio.hardError = SIO_MULTI_CNT->error;
    if (recvTmp[0] == 0xFEFE && gMultiSio.recvBufCounter > 9)
    {
        gMultiSio.recvBufCounter = -1;
        tmp = gMultiSio.lastRecvBufp;
        gMultiSio.lastRecvBufp = gMultiSio.currentRecvBufp;
        gMultiSio.currentRecvBufp = tmp;
        if (gMultiSio.sendBufFlag)
        {
            tmp = gMultiSio.currentSendBufp;
            gMultiSio.currentSendBufp = gMultiSio.nextSendBufp;
            gMultiSio.nextSendBufp = tmp;
            gMultiSio.sendBufFlag = 0;
            gMultiSio.sendBufCounter = 0;
        }
        REG_IME = 0;
        INTR_CHECK |= 0x80;
        REG_IME = 1;
    }
    if (gMultiSio.sendBufCounter < 10)
        SIO_MULTI_CNT->data = ((u16 *)gMultiSio.currentSendBufp)[gMultiSio.sendBufCounter];
    if (gMultiSio.sendBufCounter < 11)
        gMultiSio.sendBufCounter++;
    if (gMultiSio.recvBufCounter >= 0)
    {
        for (i = 0; i < 2; i++)
            ((u16 *)&gMultiSio.currentRecvBufp[i])[gMultiSio.recvBufCounter] = recvTmp[i];
        if (gMultiSio.recvBufCounter == 9)
            gMultiSio.recvDone = 1;
    }
    if (gMultiSio.recvBufCounter < 10)
        gMultiSio.recvBufCounter++;
    if (gMultiSio.type)
        *(vu16 *)(REG_BASE + 0x10E) = 0;
    if (gMultiSio.sendBufCounter < 11 && gMultiSio.type)
    {
        *(vu16 *)SIO_MULTI_CNT |= 0x80;
        *(vu16 *)(REG_BASE + 0x10E) = 0xC0;
    }
    gMultiSio.intrFlag = 1;
}
