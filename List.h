#pragma once
#include "ArrayList.h"


// Class containing function pointers to available list functions
typedef struct {

    // list
    struct array_list* data;

    // function ptrs


} list;

list* create_list(size_t list_size, size_t data_size);
void destroy_list(list* list);
