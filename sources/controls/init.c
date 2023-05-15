// B3WW

#include "wAscii_game.h"
#include "wtools.h"
#include <stdlib.h>
#include <string.h>

static void init_window(void)
{
    wcase_t *line = NULL;

    WMAIN_STRUCT->window = malloc(sizeof(wWindow_t));
    WMAIN_STRUCT->window->ncurses_window = newwin(WSHELL_SIZE.x, WSHELL_SIZE.y, 0, 0);
    WMAIN_STRUCT->window->cases = malloc(sizeof(wcase_t) * (WSHELL_SIZE.y + 1));
    WMAIN_STRUCT->window->cases[WSHELL_SIZE.y] = NULL;
    for (int i = 0; i < WSHELL_SIZE.y; i++) {
        line = malloc(sizeof(wcase_t) * (WSHELL_SIZE.x + 1));
        for (int j = 0; j < WSHELL_SIZE.x; j++) {
            line[j].character = WCASE_BLANK;
            line[j].color = WHITE;
        }
        line[WSHELL_SIZE.x].character = WCASE_EMPTY;
        WMAIN_STRUCT->window->cases[i] = line;
    }
}

static void init_color_pairs(void)
{
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

int winit(void)
{
    WMAIN_STRUCT = malloc(sizeof(wglob_t));
    WMAIN_STRUCT->shell_size = wget_shell_size(); // init also ncurses lib
    WMAIN_STRUCT->key = 0;
    start_color();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    init_window();
    init_color_pairs();
    if (!WMAIN_STRUCT->window) {
        free(WMAIN_STRUCT->window);
        free(WMAIN_STRUCT);
        WERROR("failed to load ncurses window !");
        return 0;
    }
    return 1;
}
