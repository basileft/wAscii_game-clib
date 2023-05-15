/*
** EPITECH PROJECT, 2023
** wAscii_game-clib
** File description:
** get_file_content
*/

#include "wtools.h"
#include <stdio.h>
#include <string.h>

char const *get_file_content(char const *path)
{
    FILE *file = fopen(path, "r");
    char *content  = NULL;
    long size = 0;

    if (file == NULL)
        return NULL;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    content = malloc(size + 1);
    fread(content, 1, size, file);
    fclose(file);
    content[size] = '\0';
    return content;
}