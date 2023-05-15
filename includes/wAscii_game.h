// B3WW

#pragma once

    #include <ncurses.h>
    #include <wAscii_game_libuses.h>
    #include <wAscii_game_types.h>

    #define WASCII_MIN_LIMIT 33
    #define WASCII_MAX_LIMIT 126

    #define WSHELL_SIZE WMAIN_STRUCT->shell_size

    #define WCASE_BLANK 32
    #define WCASE_EMPTY 0

    #define WCOLOR(__color_id__) COLOR_PAIR(__color_id__)

    #define WPOS(x, y) (wpos_t) {{x, y, 0}, {0, 0}}


/* INIT NECCESSARYS FOR LIB FUNCS */
int winit(void);

/* DISPLAY VIEW IN WINDOW */
void wdisplay_view(vView_t *View);

/* CREATE SPRITE */
wSprite_t *wSprite_create(wSample_t *sample);

/* CREATE SAMPLE */
wSample_t *wSample_create(char const *file_path, char const *name, wcolor_t color);

/* DIDPLAY SPRITE */
void wSprite_display(wSprite_t *sprite);

/* SPRITE SET NEW POSITION (DEFALUT 0, 0) */
void wSprite_set_position(wSprite_t *sprite, wv3ui_t position);

/* SPRITE SET MOVE */
void wSprite_set_move(wSprite_t *sprite, wv3ui_t position);