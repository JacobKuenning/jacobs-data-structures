/* a set of macros to help easily build dynamic arrays. 
 * use the declare_vector_struct macro to declare a dynamic array struct, that contains elements of type DATATYPE
 * the macros have bounds checks for insert and remove, but not for get and set. */

#include <stdlib.h>

// macro for declaring dynamic array structs, named NAME that holds elements of DATATYPE
#define declare_vector_struct(DATATYPE, NAME)\
    typedef struct {\
        int max; /* allocated space for the array */\
        int size; /* current number of elements */\
        DATATYPE* elements; /* the array */\
        int elem_size; /* the size in bytes of DATATYPE, used for realloc calls */\
    } NAME;

// create a new dynamic array
// USAGE: STRUCT_NAME* NAME = new_vector((DATATYPE, STRUCT_NAME, NAME, NUM_ELEMENTS);
#define new_vector(DATATYPE, STRUCT_NAME, NAME, NUM_ELEMENTS) \
    (STRUCT_NAME*)malloc(sizeof(STRUCT_NAME));\
    NAME->max = NUM_ELEMENTS;\
    NAME->elem_size = sizeof(DATATYPE);\
    NAME->elements = (DATATYPE*)malloc(sizeof(DATATYPE) * NUM_ELEMENTS);\
    NAME->size = 0;
    
// free vector and its elements
#define delete_vector(NAME)\
    free(NAME->elements);\
    free(NAME);\

// copy elements from SRC to DEST. DEST must be an existing vector.
// The arguments may use different vector structs but cant have different element types
#define vector_copy(SRC, DEST)\
    if (SRC->size > DEST->max){\
        DEST->max = SRC->size;\
        DEST->elements = realloc(DEST->elements, DEST->elem_size * DEST->max);\
    }\
    for (int i = 0; i < SRC->size; i++)\
        DEST->elements[i] = SRC->elements[i];\
    DEST->size = SRC->size;

// get value from vector NAME at INDEX
#define vector_get(NAME, INDEX) NAME->elements[INDEX]

// set value from vector NAME at INDEX to VALUE
#define vector_set(NAME, INDEX, VALUE) NAME->elements[INDEX] = VALUE

// set all elements in vector NAME to VALUE
#define vector_set_all(NAME, VALUE)\
    for (int i = 0; i < NAME->size; i++)\
        NAME->elements[i] = value;

// size of the vector
#define vector_size(NAME) NAME->size

// is zero if vector is empty
#define vector_empty(NAME) vector_size(NAME)

// if an added element would exceed the bounds of the array, reallocate the array
#define resize_vector_if_needed(NAME)\
    if (NAME->size + 1 > NAME->max){\
        NAME->max *= 2;\
        NAME->elements = realloc(NAME->elements, NAME->max * NAME->elem_size);\
    }\

// add VALUE to the back of vector NAME
#define vector_push_back(NAME, VALUE)\
    resize_vector_if_needed(NAME)\
    NAME->elements[NAME->size] = VALUE;\
    NAME->size++;

// remove the element at the back of vector NAME
#define vector_pop_back(NAME)\
    if (NAME->size > 0) NAME->size--;
    
// insert VALUE into position INDEX of vector NAME
#define vector_insert(NAME, VALUE, INDEX)\
    if (VALUE >= 0){/* don't insert at negative indices */\
        resize_vector_if_needed(NAME)\
        if (INDEX > NAME->size){/* if the index exceeds the size, append to the end */\
            NAME->elements[NAME->size] = VALUE;\
            NAME->size++;\
        } else {/* otherwise, move over all elements after INDEX, inclusive, then insert VALUE at INDEX */\
            for (int i = NAME->size; i >= INDEX; i--)\
                NAME->elements[i+1] = i;\
            NAME->size++;\
            NAME->elements[INDEX] = VALUE;\
        }\
    }

// remove the value at INDEX from vector NAME
#define vector_remove(NAME, INDEX)\
    if (INDEX >= 0 && INDEX < NAME->size && NAME->size != 0){/* bounds and empty array check */\
        for (int i = INDEX; i < NAME->size - 1; i++)\
            NAME->elements[i] = NAME->elements[i+1];\
        NAME->size--;\
    }

