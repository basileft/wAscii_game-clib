// B3WW

/* This is modulary part te elements list use to organise game element wiithout type handling */

#include "wAscii_game_types.h"

#pragma once

typedef struct welement_struct_not_user {
    welement_type_t type;
    void *element;
    struct welement_struct_not_user *next;
} welement_t;

typedef struct welement_list_struct {
    welement_type_t type;
    int size;
    welement_t *head;
} wElist_t;

/* CREATE ELIST */
wElist_t *wElist_create(void);

/* ADD TO ELIST */
void wElist_add(wElist_t *element_list, void *to_add);