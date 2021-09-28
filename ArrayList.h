
#pragma once
#include <stdbool.h>

typedef struct list array_list;

array_list* create_array_list(size_t list_size, size_t data_size);
void destroy_array_list(array_list* list);

bool array_list_add(array_list* list, void* data);
// void* array_list_get(array_list* list, int index); // Returns Data
// bool array_list_set(array_list* list, int index, void* new_data) // Set data at specific index
// void* array_list_remove(array_list* list, int index); // Delete and Return Data
// void array_list_clear(array_list* list); // Remove all elements from the list
// size_t array_list_size(array_list* list); // Return size of list


/**
 * Sort list based on a user's compare function
 * 
 * Comparator Return Value:
 *  Negative - *p1 goes BEFORE *p2
 *  Zero - *p1 == *p2 (order doesn't matter)
 *  Positive - *p1 goes AFTER *p2
 *  
 */
// void array_list_sort(array_list* list, int (*compar)(const void *p1, const void *p2));


// Used for Testing
void print_integers(array_list* list);

