#include <stdio.h>
#include "darr.h"

void print_darr(int_darr * darr){
    for (int i = 0; i < darr->size; i++) {
        printf("%d\n", int_darr_at(darr, i)); 
    }
}

void populate_darr(int_darr* darr){
    for (int i = 0; i < 10; i++) {
        int_darr_push_back(darr, i);
    }
}

int main(){
    int_darr* darr = new_int_darr(10);
    populate_darr(darr);
    print_darr(darr);
    delete_int_darr(darr);    
}
