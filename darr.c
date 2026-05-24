#include <stdlib.h>
#include "darr.h"

int_darr* new_int_darr(int n){
    int_darr* darr = malloc(sizeof(int_darr));
    darr->elements = malloc(sizeof(int) * n);
    darr->max = n; darr->size = 0;
    return darr;
}

void delete_int_darr(int_darr* darr){
    free(darr->elements);
    free(darr);
    return;
}

void int_darr_push_back(int_darr* darr, int elem){
    if (darr->size + 1 > darr->max){
        darr->max *= 2;
        darr->elements = realloc(darr->elements, sizeof(int) * darr->max);
    }
    darr->elements[darr->size] = elem;
    darr->size++;
}

void int_darr_pop_back(int_darr* darr){
    darr->size--;
    return;
}

void int_darr_insert(int_darr* darr, int elem, int n){
    if (n < 0) return; 
    if (darr->size + 1 > darr->max){ // if exceeding size of the array
       darr->max *= 2;
       darr->elements = realloc(darr, sizeof(int) * darr->max);
    }
    for (int i = darr->size; i >= n; i--) // move over all following elements
       darr->elements[i+1] = i;
    if (n > darr->size + 1)
        darr->elements[darr->size + 1] = elem;
    else
        darr->elements[n] = elem;
    darr->size++;
}    

void int_darr_remove(int_darr* darr, int n){
    if (n < 0 || n > darr->max || darr->size == 0) return;
    for (int i = n; i < darr->size - 1; i++) 
        darr->elements[i] = darr->elements[i+1]; 
    darr->size--; 
}

