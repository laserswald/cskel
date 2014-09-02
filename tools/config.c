#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "util/dbg.h"

// Parse a line of a settings file.
setting_t*
settings_parseln(char* string){
    setting_t* ret = malloc(sizeof(setting_t));

    check(string, "Tried to parse line that is NULL.");
    // Check if we have an equals sign somewhere. 
    char* eqls = strchr(string, '=');
    check(eqls, "Configuration parsing error!");
  
    // Find the size_t of the first part of the string (before the equals sign)
    size_t keylen = eqls - string;
   
    // Okay, now create a new string for the key.
    ret->name = malloc(sizeof(char) * keylen); 
    strncpy(ret->name, string, keylen);
    ret->name[keylen] = '\0';
    debug("setting name: '%s'", ret->name);
    
    // Now we need a place for the value.
    ret->value = malloc(sizeof(char) * strlen(eqls));
    strncpy(ret->value, eqls+1, strlen(eqls));
    ret->value[strlen(eqls)] = '\0';
    debug("setting name: '%s'", ret->value);
    return ret;

error:
    free(ret); 
    return NULL;
}

setting_arr_t*
settings_read(char* filename){
    FILE* settingfile = fopen(filename, "r");
    setting_arr_t* settings = malloc(sizeof(setting_arr_t));
    settings->list = DArray_init(NULL, 10, sizeof(setting_t*));
    char buffer[256];
    int line = 0;
    while((fgets(buffer, 255, settingfile)) != NULL){ 
        setting_t* tempset = settings_parseln(buffer); 
        if (tempset){
            DArray_set(settings->list, settings->list->length, tempset);
        }
        line++; 
    } 
    return settings;
}
