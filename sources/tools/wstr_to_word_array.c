/*
** EPITECH PROJECT, 2022
** mdata_base
** File description:
** mstr_to_word_array
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_in(char *sample, char c)
{
    for (int i = 0; sample[i]; i++) {
        if (c == sample[i])
            return true;
    }
    return false;
}


static char **prepare(char *str, char *sample)
{
    int size = 0;
    int len = strlen(str);
    char **ret;

    for (int i = 0; i < len; i++) {
        while (str[i] && is_in(sample, str[i]))
            i++;
        if (!str[i])
            break;
        size++;
        while (str[i] && !is_in(sample, str[i]))
            i++;
    }
    ret = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size + 1; i++)
        ret[i] = (void *)1;
    ret[size] = NULL;
    return ret;
}

char **wstr_to_word_array(char *str, char *sample)
{
    int index = 0;
    int len = strlen(str);
    char **ret = prepare(str, sample);

    for (int i = 0; i < len && ret[index]; i++) {
        while (str[i] && is_in(sample, str[i]))
            i++;
        ret[index++] = str + i;
        while (str[i] && !is_in(sample, str[i]))
            i++;
        if (str[i])
            str[i] = '\0';
    }
    return ret;
}
