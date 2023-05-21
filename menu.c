#include "get.h"
#include "struct.h"
#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
void menu (Node** root) {
    int option;
    do {
        printf("Menu:"
               "\t1. Start Play\n"
               "\t2. Print List\n"
               "\t3. Exit\n"
               "Option: ");
        option = getint_min_max(1, 4);
        switch (option)
        {
            case 1:
                printf("\nGuess the game and I'll try to guess it.\n");
                move_tree(*root);
                break;
            case 2:
                printf("Choose what you want to make a wish:\n"
                       "\t* Sushi\n"
                       "\t* Pizza\n"
                       "\t* Tacos\n"
                       "\t* Baked apples\n"
                       "\t* Omelette\n"
                       "\t* Mozzarella\n"
                       "\t* Coffee\n"
                       "\t* Lobster\n"
                       "\t* Cheese Sandwich\n"
                       "\t* Hamburgers\n");
                break;
        }
        if(option != 3) {
            printf("\nReturn to menu? ");
            if (!get_answer()) {
                system("pause");
                break;
            }
        }
    } while (option != 3);
    freeTree(*root);
}