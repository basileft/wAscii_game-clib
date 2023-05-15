// B3WW

#include "wAscii_game_libuses.h"
#include <stdlib.h>

void wend(void)
{
    free(WMAIN_STRUCT->window);
    free(WMAIN_STRUCT);
}
