
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "structures/list.h"
#include "util/minunit.h"
#include "util/dbg.h"

static List* list = NULL;
char* first = "one";
char* second = "two";
char* third = "three";
char* testarray[] = {"two", "one", "three"};

char* assertlistvals(List* l, char* vals[]){
    ListNode* ln = l->head;
    int i = 0;
    for ( ; ln; i++, ln=ln->next){
        mu_streql(vals[i], (char*)ln->data, "Lists are unequal.");
    }  
}

mu_test(list_alloc_test){
    list = List_new();
    mu_assert(list != NULL, "List is null.");
    mu_assert(list->head == NULL, "List does not nullify head pointer");
    mu_assert(list->tail == NULL, "List does not nullify tail pointer");
    mu_assert(list->length == 0, "List length is not zero"); 
}

mu_test(add_get_test){
    List_append(list, first);
    char* f = List_get(list, 0);
    mu_assert(f == first, "Stored data is not equal to non-stored data");
}

mu_test(push_pop_test){
    // Test: pop normal use
    char* popped = List_pop(list);
    mu_streql(popped, first, "Normal pop use not equal");
    
    // Test: pop on blank list
    popped = List_pop(list); 
    mu_assert(popped == NULL, "Pop returned something. That's strange.");
    
    // Test: push on blank list
    List_push(list, first);
    mu_assert(list->head->data == first, "Pushing did not happen!");
   
    // Test: push on no list or
}

mu_test(remove_test){
    List_append(list, second);
    List_remove(list, 0);
    char *thingy = List_get(list, 0);
    mu_assert(thingy == second, "Removal did not happen.");    
    debug("thingy = %s", thingy);     
}

void applytestfn(void* v){
    char* item = v; 
    printf("Item: %s\n", item);
}

mu_test(do_test){
    List_append(list, first);
    List_append(list, third);
    List_do(list, &applytestfn); 
}

int stringcmp(void* a, void* b){
    char* as = a;
    char* bs = b;
    return strcmp(as, bs);
}

mu_test(list_sort_test){
    List* sorted = List_sort(list, &stringcmp);
    char* sortedarray[] = {"one", "three", "two"};
    assertlistvals(sorted, sortedarray); 
    List_free(sorted);
}

mu_test(list_free_test){
    List_free(list);
}

mu_suite(linkedlist_fixture)
{
    mu_run_test(list_alloc_test);
    mu_run_test(add_get_test);
    mu_run_test(push_pop_test);
    mu_run_test(remove_test);
    mu_run_test(do_test);
    mu_run_test(list_sort_test);
    mu_run_test(list_free_test);
}
