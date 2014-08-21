#ifndef ERRORSTRUCT

#define ERRORSTRUCT

#define Maybe(type) Maybe_rename(type, type)
#define Maybe_rename(type, tn) \
    typedef struct { \
        char* errorstring;\
        type* data; \
    } maybe_tn;


#define maybeify(type, variable) \
    maybe_type* variable_m = malloc(sizeof maybe_type); \
    variable_m->data = variable;

Maybe(int);
Maybe(long);
Maybe(char);
Maybe_rename(char*, string);
#endif /* end of include guard: ERRORSTRUCT */
