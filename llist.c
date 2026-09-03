/* An intrusive linked list data structure
 * Intrusive data structures are embedded inside of structs and eliminate the pointer chasing of the usual implementations */

#include <stddef.h>
#include <stdlib.h>
#include "llist.h"

llist* create_llist(){
    llist* list = (llist*)malloc(sizeof(llist));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
    
void delete_llist(llist* list){
    llist_n* ptr = list->tail;
    llist_n* hd = list->head;
    while (ptr != hd){ 
        ptr->next = NULL; // unlink node's next field 
        ptr = ptr->prev; 
        ptr->next->prev = NULL; // unlink node's previous field
    }
    ptr->next = NULL;
    free(list);
}

void llist_n_clean(llist_n* node){
    node->next = NULL;
    node->prev = NULL;
}

void llist_append(llist* list, llist_n* node){
    if (!list || !node) return;
    llist_n_clean(node);
    if (list->size == 0){
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    list->size++;
}

void llist_prepend(llist* list, llist_n* node){
    if (!list || !node) return;
    llist_n_clean(node);
    if (list->size == 0){
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
}

llist_n* llist_get(llist* list, int n){
    if (n > list->size || n < 0) return NULL;

    llist_n* ptr = list->head;
    int i = 0;
    while (ptr && (i < n)){
        ptr = ptr->next;
        i++;
    }
    return ptr;
} 

int llist_size(llist* list){
    if (list) return list->size;
    return 0;
}
