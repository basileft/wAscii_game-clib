// B3WW

#include "wAscii_game_libuses.h"
#include "wAscii_game.h"
#include "wtools.h"

void wfilter(wcase_t **to_add, wpos_t pos)
{
    wcase_t **cases = WMAIN_STRUCT->window->cases;
    int isize = TABSIZE(cases);
    int jsize = 0;

    while (cases[0][jsize].character)
        jsize++;
    for (int i = 0; to_add[i]; i++) {
        for (int j = 0; to_add[i][j].character; j++) {
            if (i + pos.position.y < isize && j + pos.position.x < jsize)
                cases[i + pos.position.y][j + pos.position.x] = to_add[i][j];
        }
    }
}

void wdisplay_view(vView_t *View)
{
    wcase_t **cases = WMAIN_STRUCT->window->cases;

    WMAIN_STRUCT->key = getch();
    refresh();
    for (int i = 0; cases[i]; i++) {
        for (int j = 0; cases[i][j].character; j++) {
            attron(WCOLOR(cases[i][j].color));
            mvprintw(i, j, "%c", cases[i][j].character);
            attroff(WCOLOR(cases[i][j].color));
        }
    }
    for (int i = 0; cases[i]; i++)
            for (int j = 0; cases[i][j].character; j++)
                cases[i][j].character = WCASE_BLANK;
}