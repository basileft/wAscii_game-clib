// B3WW

#include "wAscii_game_types.h"

wTime_t wget_clock_current_time(wClock_t *__clock)
{
    clock_t elapsed_time = clock() - __clock->start_time;

    __clock->current_time.hours = (int)(elapsed_time / 3600);
    __clock->current_time.minutes = (int)((elapsed_time / 60) - (__clock->current_time.hours * 60));
    __clock->current_time.seconds = (int)(elapsed_time - (__clock->current_time.hours * 3600) - (__clock->current_time.minutes * 60));
    __clock->current_time.milliseconds = (int)((elapsed_time - (int)elapsed_time) * 1000);
    return __clock->current_time;
}