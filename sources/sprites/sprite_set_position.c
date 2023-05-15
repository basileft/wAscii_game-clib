// B3WW

#include "wAscii_game.h"

void wSprite_set_position(wSprite_t *sprite, wv3ui_t position)
{
    sprite->positon.position = position;
}

void wSprite_set_move(wSprite_t *sprite, wv3ui_t position)
{
    sprite->positon.position.x += position.x;
    sprite->positon.position.y += position.y;
    sprite->positon.position.z += position.z;
}
