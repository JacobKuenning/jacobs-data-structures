#pragma once

struct DATATYPE;
typedef struct {
    int max;
    int size;
    DATATYPE* elements;
} DATATYPE_darr;

#define DATATYPE_darr_at(darr, n) darr->elements[n]

DATATYPE_darr* new_DATATYPE_darr(int n);
void delete_DATATYPE_darr(DATATYPE_darr* darr);
void DATATYPE_darr_pop_back(DATATYPE_darr* darr);
void DATATYPE_darr_push_back(DATATYPE_darr* darr, DATATYPE elem);
void DATATYPE_darr_insert(DATATYPE_darr* darr, DATATYPE elem, int n);
void DATATYPE_darr_remove(DATATYPE_darr* darr, int n);
