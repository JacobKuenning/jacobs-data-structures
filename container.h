#include <stddef.h>

// finds the pointer to struct STRUCT_NAME that contains NODE_PTR as MEMBER
#define container_of(NODE_PTR, STRUCT_NAME, MEMBER)\
    (STRUCT_NAME*)((char*)NODE_PTR - offsetof(STRUCT_NAME, MEMBER))
