#ifndef __DYN_ARRAY
#define __DYN_ARRAY

#include <stdlib.h>

typedef struct DArray {
	int length;	// place of the last item in the array (recorded);
	int space; // amount of allocated memory for the array
	size_t data_size; // size of data elements
	void **arr; // pointer to array in memory
}DArray;

//typedef (int)(dasortfunc*)(void* first, void* second) DArray_sortfunc;

// Init and free. Init because arrays should be able to be
// stack allocated.
DArray* DArray_init(DArray* array, int ispace, size_t datasize);
int DArray_free(DArray* array);

// Load a standard C array.
int DArray_load(DArray* array, void* arr, int length, size_t data_size);


// Functions operating on values.
int DArray_set(DArray* array, int index, void* item);
void* DArray_get(DArray* array, int index);

/// Sort all the items in the array, using quicksort.
/* 
 * returns: 0 if okay, -1 if there was a problem.
 */
//int DArray_qsort(DArray* array, DArray_sortfunc func);
//int DArray_msort()

int DArray_grow(DArray* array, int new_len);
int DArray_clear(DArray* array);


#endif // __DYN_ARRAY
