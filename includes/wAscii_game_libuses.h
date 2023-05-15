// B3WW

#include "wAscii_game_types.h"

#define WMAIN_STRUCT wAscii_game_main_struct_not_user
#define VEC2UI_INIT (wpos_t) {0, 0}

/* GLOBAL MAIN STRUCT */
wglob_t *wAscii_game_main_struct_not_user;

/* RETURN wv2ui_t TO REPRESENT SHELL SIZE */
wv2ui_t wget_shell_size(void);

/* APPLY CASES TAB ON WIN */
void wfilter(wcase_t **to_add, wpos_t pos);