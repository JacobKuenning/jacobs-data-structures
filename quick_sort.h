#pragma once
#include "darray.h"

// swap function for use in quick sorting
void quick_swap(void* darr, int a, int b, size_t size);

// pick random element and sort it into place, returning it's position
int partition(void* darr, int left, int right, size_t size, int (*cmp)(void* a, void* b));

// use the quick sort algorithm to sort dynamic array
void quick_sort(void* darr, int left, int right, size_t size, int (*cmp)(void* a, void* b));

