/*
** EPITECH PROJECT, 2023
** wAscii_game-clib
** File description:
** e_list.create
*/

#include "wAscii_game.h"
#include "wAscii_game_elist.h"
#include <stdlib.h>

wElist_t *wElist_create(void)
{
    wElist_t *to_create = malloc(sizeof(wElist_t));

    to_create->type = WELIST;
    to_create->head = NULL;
    to_create->size = 0;
    return to_create;
}