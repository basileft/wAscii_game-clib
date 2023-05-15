// B3WW

#include "wAscii_game.h"
#include "wAscii_game_types.h"
#include "wtools.h"
#include <string.h>

wSample_t *wSample_create(char const *file_path, char const *name, wcolor_t color)
{
    char const *sample_tmp = get_file_content(file_path);
    char **sample_lines = wstr_to_word_array((char *)sample_tmp, "\n");
    wcase_t **sample = NULL;
    wSample_t *to_return = NULL;
    int size = TABSIZE(sample_lines);

    if (!sample_tmp)
        return NULL;
    sample = malloc(sizeof(wcase_t *) * (size + 1));
    sample[size] = NULL;
    for (int i = 0; i < size; i++) {
        sample[i] = malloc(sizeof(wcase_t) * (strlen(sample_lines[i]) + 1));
        sample[i][strlen(sample_lines[i])].character = 0;
        for (int j = 0; sample_lines[i][j]; j++) {
            sample[i][j].character = sample_lines[i][j];
            sample[i][j].color = color;
        }
    }
    to_return = malloc(sizeof(wSample_t));
    to_return->cases = sample;
    to_return->name = name;
    return to_return;
}
