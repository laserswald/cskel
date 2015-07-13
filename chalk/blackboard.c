
#include "blackboard.h"
/* Allocation functions. */
blackboard* bb_new(){
    
}

blackboard_post* bb_newpost(void* data, bstring type, struct bstrList *tags){
}

// Post manipulation.
/* Add an item to the blackboard. */
int bb_add(blackboard* b, blackboard_post* p){
}

/* retrieve the first match available */
blackboard_post* bb_retr(blackboard* b, bstring search){
}

/* remove and return the first match available */
blackboard_post* bb_takefirst(blackboard* b, bstring search){
}

/* remove and return the last match available*/
blackboard_post* bb_takelast(blackboard* b, bstring search){
}

/* retrieve all matches in a DArray. */
DArray* bb_retrall(blackboard* b, bstring search){
}

