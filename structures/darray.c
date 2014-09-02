// darray.c

#include <stdlib.h>
#include "darray.h"
#include "util/dbg.h"


/** Initialize or allocate a new array.
	If given a pointer to a DArray, reinitializes the entire
	array given the parameters.
	If the array is NULL, array is allocated to a new item 
	on the stack.
	
	returns 0 if everything is fine, returns something else
	when something bad happened.
*/
DArray* DArray_init(DArray* array, int ispace, size_t datasize){
	if (array == NULL){ array = (DArray*)malloc(sizeof(DArray)); }	
    check_mem(array);
	array->space = ispace;
	array->data_size = datasize;
	array->arr = calloc(ispace, datasize);
	array->length = 0;
	return array;
error:
    array = NULL;
    return NULL;
}

int DArray_check(DArray* array){
   	check(array, "Array is null");
    check(array->arr, "Array not initialized"); 
    return 0;
error:
    return -1;
}

int DArray_free(DArray* array){
	free(array->arr);
	free(array);
	return 0;
}

/**
 *  Goes through the array and destroys everything in the array using the
 *  given function.
 */
int DArray_destroy(DArray* array, int (*destroyfn)(void*)){
    // Go through the array, calling the destroy function.
    int i;
    for(i = 0; i < array->space; i++){
        check(destroyfn(array->arr[i]), "Destruction of item %d returned error", i);
    }
    DArray_free(array);
    return 0;
error:
    return 1;
}

int DArray_expand(DArray* array){
    return DArray_grow(array, array->space * 2);
}

int DArray_grow(DArray* array, int newsize){
	// TODO: Make sure this is unbreakable.
	check(array, "Array is null.");
    check(newsize < array->length, "Resize of array would destroy items.");
    check(newsize < array->space, "No need to expand the array"); 
	array->arr = realloc(array->arr, newsize*array->data_size);
	check_mem(array->arr);
    array->space = newsize;
	return 0;
error:
	return -1;
}

int DArray_set(DArray* array, int index, void* item){
	check(index < array->space && index >= 0, "Index is outside range");
    array->arr[index] = item;    
    if (index == array->length) array->length++;
	return 0;
	error:
		return -1;
}

void* DArray_get(DArray* array, int index){
	check(array, "Array does not exist");
	check(array->arr, "Array not initialized");
    check(index >= 0, "Index below zero.");
    check(index < array->space, "Given index is too large.");
	void* returnvar = (array->arr)[index];
	
	return returnvar;
	error:
		return NULL;
}

void* DArray_remove(DArray* array, int index){
    void* ret = DArray_get(array, index);
    // TODO: Check ret for problems.
    DArray_set(array, index, NULL);
    // TODO: check if DArray_set returned error
    if(index == array->length) array->length--;
    return ret;
}

int DArray_push(DArray* array, void* item){
    // TODO: check the array for inconsistency
    //
    if( array->length == (array->space-1))
        DArray_expand(array);
    DArray_set(array, array->length, item);
    return 0;
}

void* DArray_pop(DArray* array){
    return DArray_remove(array, array->length); 
}
