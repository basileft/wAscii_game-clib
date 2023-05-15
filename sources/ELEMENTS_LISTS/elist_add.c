// B3WW

#include "wAscii_game_elist.h"

void wElist_add(wElist_t *element_list, void *to_add)
{
    welement_t *element_p = element_list->head;
    if (!element_p) {
        element_list->head = to_add;
        element_list->size++;
        return;
    }
    for (int i = 0; i < element_list->size; i++) {
        if (!element_p)
            return;
        element_p = element_p->next;
    }
    element_p->element = to_add;
    element_list->size++;
}
