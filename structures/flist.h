#ifndef FUNCTIONAL_LIST
#define FUNCTIONAL_LIST

#define flist(type) flist_type
#define inst_flist(type) \
    typedef struct _flist_#type { \
        #type data; \
        flist_#type * next; \
    } flist_#type;

inst_flist(char);
inst_flist(int);
inst_flist(bool);

#define flist_find()

#endif /* end of include guard: FUNCTIONAL_LIST */
