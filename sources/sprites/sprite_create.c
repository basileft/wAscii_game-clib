// B3WW

#include "wAscii_game.h"
#include "wtools.h"
#include <stdlib.h>

wSprite_t *wSprite_create(wSample_t *sample)
{
    wSprite_t *to_create = malloc(sizeof(wSprite_t));

    to_create->type = WSPRITE;
    to_create->color = WHITE;
    to_create->sample = sample;
    to_create->positon = VEC2UI_INIT;
    return to_create;
}

