#pragma once

typedef struct {
    int max;
    int size;
    int* elements;
} int_darr;

#define int_darr_at(darr, n) darr->elements[n]

int_darr* new_int_darr(int n);
void delete_int_darr(int_darr* darr);
void int_darr_pop_back(int_darr* darr);
void int_darr_push_back(int_darr* darr, int elem);
void int_darr_insert(int_darr* darr, int elem, int n);
void int_darr_remove(int_darr* darr, int n);
