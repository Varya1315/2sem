#ifndef LABA44_FUNCS_H
#define LABA44_FUNCS_H
#include "stdio.h"
#include "stdlib.h"

void menu (Node** root);
Node* new_node(char* name, int index);

void add_item(Node* current_node);

void move_tree(Node* current_node);
Node* load_db(FILE* file, int index);
void freeTree(Node *node);
#endif //LABA44_FUNCS_H
