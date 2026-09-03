#include <stddef.h>
#include <stdlib.h>
#include "container.h"

/* a quick note about this struct and how it works
 * first we create an alias for "struct llist_n" and call it just llist_n
 * then we define this struct. but how can we use the struct within itself if its not defined??
 * this is because they are only pointers! of which all pointers are 8 bytes
 * because of this it knows how big to make the struct, so we don't get any problems */
typedef struct llist_n llist_n;
struct llist_n{
    llist_n* next;
    llist_n* prev;
};

typedef struct llist llist;
struct llist{
    llist_n* head;
    llist_n* tail;
    int size;
};

llist* create_llist();
void delete_llist(llist* list);
void llist_n_clean(llist_n* node);
void llist_append(llist* list, llist_n* node);
llist_n* llist_get(llist* list, int n);
int llist_size(llist* list);
