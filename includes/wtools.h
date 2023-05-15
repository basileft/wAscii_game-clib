// B3WW

#pragma once

    #include <stdlib.h>

    #define TABSIZE(tab) ({int _i = 0;while(tab[_i]){_i++;}_i;})
    #define TABFREE(tab) ({int _i = 0;for(;tab[_i];_i++){free(tab[_i]);}})
    #define TABDESTROY(tab) ({TABFREE(tab);free(tab);})

    #define WERROR(__error_string__) fprintf(stderr, "error : %s\n", __error_string__)

/* GET FILE CONTENT */
char const *get_file_content(char const *path);
/* SPLIT STR */
char **wstr_to_word_array(char *str, char *sample);