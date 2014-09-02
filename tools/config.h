
#ifndef SETTINGS_H

#define SETTINGS_H

#include "structures/darray.h"

typedef struct _setting {
    /* data */
    char* name;
    char* value;
} setting_t;

typedef struct _settings_t {
    /* data */
    DArray* list;
} setting_arr_t;

// Parse a string into a config value.
setting_t *settings_parseln(char* string);

// Read a file and return a list of settings.
setting_arr_t *settings_read(char* filename);

//settings_t* settings_fill_from_argl(ArgList* argl);
#endif /* end of include guard: SETTINGS */
