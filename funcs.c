#include <stdlib.h>
#include "get.h"
#include "struct.h"
#include "funcs.h"
#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 1024

Node* new_node(char* name, int index) {
    Node* node = malloc(sizeof(Node));
    if(node == NULL) {
        printf("Can't allocate memory\n");
        exit(1);
    }
    strncpy(node->name, name, MAX_NAME_LENGTH);
    node->index = index;
    node->yes = NULL;
    node->no = NULL;
    return node;
}y
void add_item(Node* current_node) {
    char new_item[MAX_NAME_LENGTH];
    char question[MAX_NAME_LENGTH];
    printf("what is the correct answer? ");
    fgets(new_item, MAX_NAME_LENGTH, stdin);
    new_item[strcspn(new_item, "\n")] = 0;
    printf("Write a question that distinguishes %s from %s: ", new_item, current_node->name);
    fgets(question, MAX_NAME_LENGTH, stdin);
    question[strcspn(question, "\n")] = 0;
    Node* new_question = new_node(question, current_node->index);
    Node* new_node_ = new_node(new_item, current_node->index * 2);
    Node* old_node_ = new_node(current_node->name, current_node->index * 2 + 1);
    new_question->yes = new_node_;
    new_question->no = old_node_;
    *current_node = *new_question;
}

void move_tree(Node* current_node) {
    if (current_node->yes == NULL && current_node->no == NULL) {
        printf("I think it's %s. I guessed? ", current_node->name);
        if (get_answer()) {
            printf("Hoohoo! I guessed!\n");

        } else {
            printf("Oh no! I didn't guess.\n");
            printf("Do you want to add new object? ");
            if (get_answer()) {
                add_item(current_node);
            }
        }
        return;
    }
    printf("%s ", current_node->name);
    if (get_answer()) {
        move_tree(current_node->yes);
    } else {
        move_tree(current_node->no);
    }
}

Node* load_db(FILE* file, int index) {
    int current_index;
    char name[MAX_NAME_LENGTH];
    char line[MAX_NAME_LENGTH];
    fseek(file, 0, SEEK_SET);
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "[%d] %[^\n]s", &current_index, name);
        if (current_index == index) {
            Node* node = new_node(name, index);
            node->yes = load_db(file, index * 2);
            node->no = load_db(file, index * 2 + 1);
            return node;
        }
    }
    return NULL;
}
void freeTree(Node *node){
    if(node!=NULL)
    {
        freeTree(node->yes);
        freeTree(node->no);
        free(node);
    }
}