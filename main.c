#include "get.h"
#include "struct.h"
#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
    system("cls");
    char *filename = {"libr.txt"};
    Node* root = NULL;

    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Can't open file.");
        root = NULL;
        fclose(file);
    }
    else root = load_db(file, 1);
    menu(&root);
    system("pause");
        return 0;
}
