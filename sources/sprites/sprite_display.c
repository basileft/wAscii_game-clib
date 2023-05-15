// B3WW

#include "wAscii_game.h"

void wSprite_display(wSprite_t *sprite)
{
    wfilter(sprite->sample->cases, sprite->positon);
}
