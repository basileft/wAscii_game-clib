// B3WW

#include "wAscii_game_types.h"
#include <stdlib.h>

wClock_t *wClock_create(void)
{
    wClock_t *ret = malloc(sizeof(wClock_t));

    ret->start_time = clock();
    ret->current_time.hours = 0;
    ret->current_time.minutes = 0;
    ret->current_time.seconds = 0;
    ret->current_time.milliseconds = 0;
    return ret;
}
