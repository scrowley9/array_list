#include <stdio.h>
#include "ArrayList.h"

void test1_int(void){
    printf("TEST 1\n");

    // Size 5
    array_list* list = create_array_list(5, sizeof(int));

    int arr[5] = {1, 2, 3, 4, 5};

    array_list_add(list, &arr[0]);
    print_integers(list);
    array_list_add(list, &arr[1]);
    print_integers(list);
    array_list_add(list, &arr[2]);
    print_integers(list);
    array_list_add(list, &arr[3]);
    print_integers(list);
    array_list_add(list, &arr[4]);
    print_integers(list);

    destroy_array_list(list);

    printf("\n");
}

void test2_int(void){

    printf("TEST 2\n");

    // Size 0
    array_list* list = create_array_list(0, sizeof(int));

    int arr[5] = {3, 2, 3, 4, 5};

    // Add elements to empty array list
    printf("Output: %s\n", array_list_add(list, &arr[0]) ? "true" : "false");
    print_integers(list);
    printf("Output: %s\n", array_list_add(list, &arr[1]) ? "true" : "false");
    print_integers(list);
    printf("Output: %s\n", array_list_add(list, &arr[2]) ? "true" : "false");
    print_integers(list);
    printf("Output: %s\n", array_list_add(list, &arr[3]) ? "true" : "false");
    print_integers(list);
    printf("Output: %s\n", array_list_add(list, &arr[4]) ? "true" : "false");
    print_integers(list);

    destroy_array_list(list);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // test1_int();
    test2_int();
    return 0;
}


