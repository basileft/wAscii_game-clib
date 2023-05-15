// B3WW

#pragma once

    #include "wmtype.h"
    #include <time.h>
    #include <ncurses.h>

typedef enum wcolor_enum {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
} wcolor_t;

typedef enum welement_type_enum_not_user {
    WSPRITE,
    WELIST
} welement_type_t;

typedef struct wcases_struct {
    char character;
    wcolor_t color;
} wcase_t;

typedef struct object_position_struct {
    wv3ui_t position;
    wv2ui_t origin_postion;
} wpos_t;

typedef struct wView_struct {
    wv2i_t size;
    wpos_t position_in_window;
    wpos_t display_positon;
} vView_t;

typedef struct wSample_struct {
    char const *name;
    wcase_t **cases;
} wSample_t;


typedef struct wSrpite_struct {
    welement_type_t type;
    wv2ui_t scale; // negative handling...
    wpos_t positon;
    wSample_t *sample;
    wcolor_t color;
} wSprite_t;

typedef struct wTime_struct {
    int hours;
    int minutes;
    int seconds;
    int milliseconds;
} wTime_t;

typedef struct wClock_struct {
    clock_t start_time;
    wTime_t current_time;
} wClock_t;

/* NOT USER */

typedef struct wWindow_strcut_not_user {
    wv2i_t size;
    wcase_t **cases;
    vView_t *view;
    WINDOW *ncurses_window;
} wWindow_t;

typedef struct global_struct_not_user {
    wWindow_t *window;
    wv2ui_t shell_size;
    int key;
} wglob_t;


typedef struct head_to_cast_struct_not_user {
    welement_type_t type;
} whead_t;