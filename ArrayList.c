#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "ArrayList.h"

struct list{
    void** array;
    size_t num_elements;
    size_t array_size;
    size_t data_size;
};

// Get array ptr to data ptr at index
static void** index_into_list(array_list* list, int index){
    return (void**)((uint8_t*)list->array + (index*sizeof(void*)));
}

// Double the Backing Array's Size
static bool increase_array_size(array_list* list){

    assert(list != NULL);
    assert(list->array_size >= 0);

    // Calculate old and new size in bytes
    size_t old_size, new_size;
    if(list->array_size == 0){
        old_size = 1;
        new_size = 1;
    }else{
        old_size = list->array_size;
        new_size = list->array_size * 2;
    }

    // Double Array Size
    void** ptr = realloc(list->array, new_size * sizeof(void*));
    if(!ptr){
        fprintf(stderr, "Increase Array Size Error - Reallocation Failed\n");
        return false;
    }
    
    // Update List Values
    list->array = ptr;
    list->array_size = new_size;

    // Zero Out the New Memory
    void* pStart = (void*)index_into_list(list, new_size/2);
    memset(pStart, 0, old_size*sizeof(void*));

    return true;
}

// Create New Array List
array_list* create_array_list(size_t list_size, size_t data_size){
    if(list_size < 0 || data_size <= 0){
        fprintf(stderr, "create_array_list Error - list_size or data_size is not large enough\n");
        return NULL;
    }

    // Allocate struct memory
    array_list* new_list = malloc(sizeof(array_list));
    if(!new_list){
        fprintf(stderr, "create_array_list Error - Struct Allocation Failed\n");
        return NULL;
    }

    // Allocate for background array
    void** ptr = calloc(list_size, sizeof(void*));
    if(!ptr){
        destroy_array_list(new_list);
        fprintf(stderr, "create_array_list Error - List Allocation Failed\n");
        return NULL;
    }

    new_list->array = ptr;
    new_list->array_size = list_size;
    new_list->data_size = data_size;
    new_list->num_elements = 0;

    return new_list;
}

// Free Memory
void destroy_array_list(array_list* list){
    assert(list != NULL);
    assert(list->array_size >= 0);
    assert(list->data_size > 0);
    for(int i = 0; i < list->array_size; i++){
        void** ptr = index_into_list(list, i);
        free(*ptr);
    }
    free(list->array);
    free(list);
}

/**
 * True - Data Added
 * False - Unable to add data
 * 
 * data parameter will be copied into array
 */
bool array_list_add(array_list* list, void* data){
    assert(list != NULL);
    assert(list->array_size >= 0);
    assert(list->data_size > 0);
    assert(list->num_elements <= list->array_size);
    assert(data != NULL);

    // Should we increase the array size? If so, did the increase fail?
    if(list->num_elements >= list->array_size && !increase_array_size(list)){
        return false; // Unable to increase array size
    }

    // Allocate Element Memory
    void* element = malloc(sizeof(list->data_size));
    if(!element){
        fprintf(stderr, "add Error - List Data Allocation Failed\n");
        return false;
    }

    // Add Element to Array & Copy the data
    void** ptr = index_into_list(list, list->num_elements);
    *ptr = element;
    memcpy(element, data, list->data_size);
    list->num_elements += 1;
    return true;
}

// Returns Data
void* array_list_get(array_list* list, int index){
    assert(list != NULL);
    assert(list->array_size >= 0);
    assert(list->data_size > 0);
    assert(list->num_elements <= list->array_size);
    return NULL;
}

// Set data at specific index
bool array_list_set(array_list* list, int index, void* new_data){
    assert(list != NULL);
    assert(list->array_size >= 0);
    assert(list->data_size > 0);
    assert(list->num_elements <= list->array_size);
    return false;
} 

// Delete and Return Data
void* array_list_remove(array_list* list, int index){
    assert(list != NULL);
    assert(list->array_size >= 0);
    assert(list->data_size > 0);
    assert(list->num_elements <= list->array_size);
    return NULL;
}

// Remove all elements from the list
void array_list_clear(array_list* list){
    assert(list != NULL);
    assert(list->array_size >= 0);
    assert(list->data_size > 0);
    assert(list->num_elements <= list->array_size);
}

// Return size of list
size_t array_list_size(array_list* list){
    assert(list != NULL);
    assert(list->array_size >= 0);
    assert(list->data_size > 0);
    assert(list->num_elements <= list->array_size);
    return list->array_size;
}


/**
 * Sort list based on a user's compare function
 */
// void array_list_sort(array_list* list, int (*compar)(const void *p1, const void *p2)){
//     assert(list != NULL);
//     assert(list->array_size >= 0);
//     assert(list->data_size > 0);

//     // Won't work cause the array is a double ptr
//     // qsort(list->array, list->array_size, list->data_size, compar);
// }



// Used for Testing
void print_integers(array_list* list){
    assert(list != NULL);
    assert(list->array_size >= 0);
    assert(list->data_size > 0);
    
    printf("Total List Size (%zu)\n", list->array_size);
    printf("Num Elements (%zu)\n[", list->num_elements);
    int i;
    for(i = 0; i < list->num_elements-1; i++){
        void** backing_array = index_into_list(list, i);
        int* element = *backing_array;
        printf("%d, ", *element);
    }
    void** backing_array = index_into_list(list, i);
    int* element = *backing_array;
    printf("%d]\n", *element);
}
