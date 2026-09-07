#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "quick_sort.h"

void quick_swap(void* darr, int a, int b, size_t size){
    char temp[size];
    memcpy(temp, (char*)darr + (a * size), size);
    memcpy((char*)darr + (a * size), (char*)darr + (b * size), size);
    memcpy((char*)darr + (b * size), temp, size);
}

int partition(void* darr, int left, int right, size_t size, int (*cmp)(void* a, void* b)){
    int p = (rand() % (right - left + 1)) + left; // select pivot index
    quick_swap(darr, p, right, size); // move partition element to the right
    int store = left;
    for (int i = left; i < right; i++) { // compare all numbers from the start to the end with the end
        int compar = cmp((char*)darr + (i * size), (char*)darr + (right * size)); // compare curr element with partioned element
        if (compar <= 0){ // if the element is less than the partitioned element, move to appropriate side
            quick_swap(darr, i, store, size);
            store++;
        }
    }
    quick_swap(darr, store, right, size); // put partion element exactly where it goes
    return store;
}

void quick_sort(void* darr, int left, int right, size_t size, int (*cmp)(void* a, void* b)){
    if (left < right){
        int pi = partition(darr, left, right, size, cmp);
        quick_sort(darr, left, pi - 1, size, cmp); // recurse right and left
        quick_sort(darr, pi + 1, right, size, cmp);
    }
}
