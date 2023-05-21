#ifndef LABA44_STRUCT_H
#define LABA44_STRUCT_H
#define MAX_NAME_LENGTH 1024
#include "stdio.h"
#include "stdlib.h"
typedef struct node {
    char name[MAX_NAME_LENGTH];
    int index;
    struct node* yes;
    struct node* no;
} Node;



#endif //LABA44_STRUCT_H