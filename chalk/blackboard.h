// An implementation of a blackboard, an asynchronous data sharing structure.
#ifndef BLACKBOARD_H

#define BLACKBOARD_H

#include "structures/darray.h"
#include "bstrlib/bstrlib.h"

// A blackboard is a collection of posts; no object knows who posted, they just know the information.
//
typedef struct blackboard_post {
    /* data */
    void* data;
    bstring type;
    struct bstrList tags;
} blackboard_post;


typedef struct blackboard {
    /* data */
    DArray* data;
} blackboard;

/* Allocation functions. */
blackboard* bb_new();
blackboard_post* bb_newpost(void* data, bstring type, struct bstrList* tags);

void* bb_unpack(blackboard_post* post);

// Post manipulation.
/* Add an item to the blackboard. */
int bb_add(blackboard* b, blackboard_post* p);

/* retrieve the first match available */
blackboard_post* bb_retr(blackboard* b, bstring search);

/* remove and return the first match available */
blackboard_post* bb_takefirst(blackboard* b, bstring search);

/* remove and return the last match available*/
blackboard_post* bb_takelast(blackboard* b, bstring search);

/* retrieve all matches in a DArray. */
DArray* bb_retrall(blackboard* b, bstring search);



#endif /* end of include guard: BLACKBOARD_H */
