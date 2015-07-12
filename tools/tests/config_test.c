#include "tools/config.h"
#include "util/minunit.h"

mu_test(config_parseln){
    char* wellformed = "key=value";
    char* noequals = "key value";
    char* space_after = "key=value value2";
    
    setting_t* setting = settings_parseln(wellformed);
    mu_streql(setting->name, "key", "Well formed string was not parsed."); 
    mu_streql(setting->value, "value", "Well formed string was not parsed."); 
    
    setting = settings_parseln(noequals);
    mu_assert(setting == NULL, "Parsing did not fail as expected.");
    
    setting = settings_parseln(space_after);
    mu_streql(setting->name, "key", "Space after string was not parsed correctly (key)."); 
    mu_streql(setting->value, "value value2", "Space after string was not parsed (value)."); 
    
    setting = settings_parseln(NULL);
    mu_assert(setting == NULL, "Setting did not catch null pointer given problem");
    return NULL;
}

mu_test(config_read_file){
    setting_arr_t *well = settings_read("test/wellformed.cfg");    
    mu_assert(well, "did not return settings");
    return NULL;
}

mu_suite(config_suite){
    mu_run_test(config_parseln);
    return NULL;
}
