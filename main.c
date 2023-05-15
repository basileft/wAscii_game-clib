// B3WW

#include "wAscii_game.h"
#include <unistd.h>

int main(void)
{
    if (!winit())
        return -1;
    wSprite_t *my_sprite = wSprite_create(wSample_create("sample", "name", 5));
    wSprite_set_position(my_sprite, (wv3ui_t){-4, 1, 1});
    while (1) {
        wSprite_display(my_sprite);
        wdisplay_view(NULL);
        if (WMAIN_STRUCT->key == 'd')
            wSprite_set_move(my_sprite, (wv3ui_t){2, 0, 0});
        if (WMAIN_STRUCT->key == 'q')
            wSprite_set_move(my_sprite, (wv3ui_t){-2, 0, 0});
        if (WMAIN_STRUCT->key == 'z')
            wSprite_set_move(my_sprite, (wv3ui_t){0, -2, 0});
        if (WMAIN_STRUCT->key == 's')
            wSprite_set_move(my_sprite, (wv3ui_t){0, 2, 0});
    }
}