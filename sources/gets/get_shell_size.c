// B3WW

#include "wAscii_game_libuses.h"
#include <ncurses.h>

wv2ui_t wget_shell_size(void)
{
    wv2ui_t to_return;

    WINDOW *tmp = initscr();
    getmaxyx(tmp, to_return.y, to_return.x);
    return to_return;
}
