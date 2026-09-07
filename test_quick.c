#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quick_sort.h"
#include "darray.h"

declare_darray_struct(int, int_darray)

int int_cmp(void* a, void* b){
    if (*(int*)a < *(int*)b) return -1;
    if (*(int*)a > *(int*)b) return 1;
    return 0;
}

int main(){
    srand(time(0));
    int_darray* darr = create_int_darray(20);
    printf("Original array: ");
    for (int i = 0; i < 20; i++) {
        int n = rand() % 10;
        printf("%d, ", n);
        darray_push_back(darr, n);
    }
    printf("\n");

    quick_sort(darr->elements, 0, 20, darr->elem_size, int_cmp);

    printf("Sorted array: ");
    for (int i = 0; i < 20; i++) {
        printf("%d, ", darray_get(darr, i));
    }
    printf("\n");

    return 0;
}
