#include <stdlib.h>
#include "DATATYPE_darr.h"

DATATYPE_darr* new_DATATYPE_darr(int n){
    DATATYPE_darr* darr = malloc(sizeof(DATATYPE_darr));
    darr->elements = malloc(sizeof(int) * n);
    darr->max = n; darr->size = 0;
    return darr;
}

void delete_DATATYPE_darr(DATATYPE_darr* darr){
    free(darr->elements);
    free(darr);
    return;
}

void DATATYPE_darr_push_back(DATATYPE_darr* darr, DATATYPE elem){
    if (darr->size + 1 > darr->max){
        darr->max *= 2;
        darr->elements = realloc(darr->elements, sizeof(DATATYPE) * darr->max);
    }
    darr->elements[darr->size] = elem;
    darr->size++;
}

void DATATYPE_darr_pop_back(DATATYPE_darr* darr){
    darr->size--;
    return;
}

void DATATYPE_darr_insert(DATATYPE_darr* darr, DATATYPE elem, int n){
    if (n < 0) return; 
    if (darr->size + 1 > darr->max){ // if exceeding size of the array
       darr->max *= 2;
       darr->elements = realloc(darr->elements, sizeof(DATATYPE) * darr->max);
    }
    if (n >= darr->size){ // if the index is greater than the bounds, make it the last element
        darr->elements[darr->size] = elem;
        darr->size++;
        return;
    }
    for (int i = darr->size; i >= n; i--) // move over all following elements
       darr->elements[i+1] = i;
    darr->size++;
    darr->elements[n] = elem;
}    

void DATATYPE_darr_remove(DATATYPE_darr* darr, int n){
    if (n < 0 || n > darr->max || darr->size == 0) return;
    for (int i = n; i < darr->size - 1; i++) 
        darr->elements[i] = darr->elements[i+1]; 
    darr->size--; 
}

