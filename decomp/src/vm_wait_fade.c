/* Script VM wait-state handler that waits for the palette fade started by the script
   (sub_080B092C returns 1 while gUnk_0300452C's fade is still running). */

#include "global.h"
#include "vm.h"

u32 sub_080B092C(void);

// ScriptWait_Fade @ 0x0813D0F4
void ScriptWait_Fade(void)
{
    if (sub_080B092C() == 1)
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}
