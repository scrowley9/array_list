#include <stdio.h>
#include "ArrayList.h"

void test1_int(void){

    // Size 5
    array_list* list = create_array_list(5, sizeof(int));

    int arr[5] = {1, 2, 3, 4, 5};

    array_list_add(list, &arr[0]);
    print_integers(list);
    array_list_add(list, &arr[1]);
    print_integers(list);

    array_list_add(list, &arr[2]); // Error
    print_integers(list);
    array_list_add(list, &arr[3]);
    print_integers(list);
    array_list_add(list, &arr[4]);
    print_integers(list);

    destroy_array_list(list);
}

int main(int argc, char const *argv[])
{
    test1_int();
    return 0;
}


