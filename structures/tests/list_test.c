// Darray tests

#include <stdlib.h>
#include "speedunit.h"
#include "darray.h"

DArray* make_int_arr(){
	DArray *arr = DArray_init(NULL, 5, sizeof(int));
    return arr;
}

sp_test(darray_get_set){
    DArray *arr = DArray_init(NULL, 5, sizeof(int));
    int a = 3;
    sp_assert(DArray_set(arr, 0, &a) == 0, "Darray_set returned an error.");
    int arrnum = *(int*)(arr->arr[0]);
    sp_assert(arrnum == 3, "Darray item was not returned.");
    arrnum = *(int*)DArray_get(arr, 0);
    sp_assert(arrnum == 3, "Darray item was not returned.");
    sp_assert(DArray_set(arr, 5, &a) != 0, "DArray_set did not prevent boundary check.");
    sp_assert(DArray_set(arr, -1, &a) != 0, "DArray_set did not prevent negative boundary check.");    

    sp_assert(DArray_get(arr, -1) == NULL, "DArray_get did not prevent negative index access.");
    sp_assert(DArray_get(arr, -5) == NULL, "DArray_get did not prevent past the end index access.");
    return NULL;
}

sp_suite(darray_suite){
	sp_run_test(darray_get_set);
    return NULL;
}
