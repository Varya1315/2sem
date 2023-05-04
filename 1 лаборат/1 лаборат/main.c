#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
//#define scanf scanf_s

/*
void menu()
{
	printf("Task menu:\n");
	printf("1)Task condition\n");
	printf("2)Creating a Structure\n3)Showing a structure\n4)Deleting\n5)Sort\n");
	printf("6)Exit\n");
}
*/


void task()
{
	printf("1. Implement a function to create an array of structures.\n");
	printf("2. Implement a function for displaying an array of structures on the screen.\n");
	printf("3. Implement a function to initialize an instance of the structure.\n");
	printf("4. Implement array sorting functions for each field of the structure. (For example, you can sort students first by date of birth, then change your mind and sort by average score).\n");
	printf("5. Implement a menu to test the functionality.\n");
	printf("6. Functions should not be bound to a specific array: such must be passed as an argument.\n");
	printf("7. Use enum as the type of one of the fields of the structure (for example, for color).\n");
	printf("8. Implement a function to remove a structure from an array.\n");
	printf("9. Implement sorting by two fields at the same time. (For example, sort cars by color, so that all cars of the same color go in the order of the year of manufacture).\n");
}

int main()
{
	int size = 0;
	int oper = 0;
	pizza* piz = (pizza*)calloc(size, sizeof(pizza));
	while (oper != 6) {
		printf("Task menu:\n");
		printf("1)Task condition\n");
		printf("2)Creating a Structure\n3)Showing a structure\n4)Deleting\n5)Sort\n");
		printf("6)Exit\n");
		//menu();
		oper = input_oper();
		system("cls");
		switch (oper)
		{
		case 1:
		{
			task();
			break;
		}
		case 2:
		{
			size = input_size();
			piz = (pizza*)realloc(piz,size * sizeof(pizza));
			for (int i = 0; i < size; i++) {
				creating(&piz, i);
			}
		    
			printf("The structure:\n");
			printf("\n");
			showing(piz, size);
			break;

		}
		case 3:
		{
			printf("The structure:\n");
			printf("\n");
			showing(piz, size);
			break;
		}
		case 4:
		{
			printf("Cooming soon....");
			break;
		}
		case 5:
		{
			int op = 0;
			printf("Sorting menu:\n1)Enter kind of pizza\n2)Enter size of pizza\n3)Enter amount  of pizza\n4)Enter cost of pizza\n");
			op = input_sort();
			switch (op)
			{
			case 1:
			{
				sort_kind(piz, size);
				break;
			}
			case 2:
			{
				sort_size(piz, size);
				break;
			}
			case 3:
			{
				sort_amount(piz, size);
				break;
			}
			case 4:
			{
				sort_cost(piz, size);
				break;
			}
		
			default:
			{
				printf("\nExit from theese menu\n");
			}
			}
			break;
		}
		case 6:
		{
			printf("Thanks for the order\n");
			break;
		}
		default:
		{
			printf("\nExit from theese menu\n");
			//eeshka(&piz, size);
		}
		}
		clear_and_stop_console();
	}
}