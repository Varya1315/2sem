#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

int str_len(char* str)
{
	int i = 0;
	if (str == NULL)
		printf("aboba\n");
	else {
		//int i = 0;
		while (str[i] != '\0')
			i++;
	}
	return i;
}

void get_str(char** str) {
	int c, i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		(*str)[i++] = c;   
		(*str) = (char*)realloc((*str), i + 1);
	}
	(*str)[i] = '\0';

}

void str_copy(char* str1, char** str2) {

	int i = 0;
	int n = str_len(str1);
	*str2 = (char*)calloc(n, sizeof(char));
	while (str1[i] != '\0')
	{
		(*str2)[i] = str1[i];
		i++;
	}
	(*str2)[i] = '\0';
}

 int input()
{
	int b = 0;
	scanf_s("%d", &b);
	while (getchar() != '\n')
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%d", &b);
	}
	return b;
}

int input_oper()
{
	int b;
	scanf_s("%d", &b);
	while (getchar() != '\n' || b > 6 || b < 1)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%d", &b);
	}
	return b;
}

int input_size()
{
	int b;
	scanf_s("%d", &b);
	while (getchar() != '\n' || b > 9000000 || b < 70)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%d", &b);
	}
	return b;
}

int input_amount()
{
	int b = 0;
	scanf_s("%d", &b);
	while (getchar() != '\n' || b < 0 || b>999)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%d", &b);
	}
	return b;
}

int input_cost()
{
	int b = 0;
	scanf_s("%d", &b);
	while (getchar() != '\n' || b < 24900)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%d", &b);
	}
	return b;
}

int input_kind()
{
	int b = 0;
	scanf_s("%d", &b);
	while (getchar() != '\n' || b < 0 || b>6)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%d", &b);
	}
	return b;
}

int input_sort()
{
	int b = 0;
	scanf_s("%d", &b);
	while (getchar() != '\n' || b < 0 || b>6)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%d", &b);
	}
	return b;
}

void clear_and_stop_console()
{
	rewind(stdin);
	getchar();
	system("cls");
}

void outkind(enum kind num)
{
	switch (num) {
	case Margherita: {
		printf("Margherita");
		break;
	}
	case Vegana: {
		printf("Vegana");
		break;
	}
	case Peppeponi: {
		printf("Peppeponi");
		break;
	}
	case Capricciosa: {
		printf("Capricciosa");
		break;
	}
	case BBQ: {
		printf("BBQ");
		break;
	}

	default: {
		break;
	}
	}
}

void creating(pizza** piz, int size)
{
	printf("Enter kind %d of pizza:", size + 1);
	printf("\n1)Margherita \n2)Vegana\n 3)Peppeponi \n 4)Capricciosa\n 5)BBQ\n");
	(*piz)[size].kind = input_kind();

	printf("Enter zise of %d pizza:\n ", size + 1);
	(*piz)[size].size = input_size();

	printf("Enter amount of %d pizza:\n ", size + 1);
	(*piz)[size].amount = input_size();

	printf("Enter cost of %d pizza:\n ", size + 1);
	(*piz)[size].cost = input_cost();

	printf("Enter name customer of %i pizza:\n ", size + 1);
	char* temp = (char*)calloc(1, 1);
	get_str(&temp);
	str_copy(temp, &(*piz)[size].name);

}
/*

pizza* creating_struct(int* size) {
	printf("Enter the number of objects:\n");
	int ans = input_size();
	*size = ans;
	pizza* pizza = (pizza*)malloc(ans * sizeof(pizza));
	for (int i = 0; i < ans; i++)
	{
		pizza[i].kind = (char*)calloc(1, 2 * sizeof(char));
		//pizza[i].country = (char*)calloc(1, 2 * sizeof(char));
	}
	for (int i = 0; i < ans; i++) {
		creating(pizza, i);
		printf("\n");
	}
	return pizza;
}
*/


void showing(pizza* piz, int size)
{
	for (int i = 0; i < size; i++) {

		printf_s("%d)", i + 1);
		outkind(piz[i].kind);

		printf_s("%d)", i + 1);
		printf_s("%s", "size: ");
		//for (int j = 0; j < strlen(pizza[i].size); j++) {
		//	printf_s("%c", pizza[i].size[j]);
		//}
		
		printf_s("%d)", i + 1);
		printf("amount: %d \n", piz[i].amount);

		printf_s("%d)", i + 1);
		printf("cost: %d \n", piz[i].cost);

		printf_s("%d)", i + 1);
	//	printf_s("%s", "Name: ");
	//  for (int j = 0; j < strlen(cars[i].country); j++)
		printf("name: %s \n", piz[i].name);

		printf("\n");
		printf("- - - - - - - - - - -\n");
		printf("\n");

	}
}

void sort_size(pizza* pizza, int size)
{
	int i = 0;
	int j = 0;
	int p = 0;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (strcmp(pizza[i].size, pizza[j].size) > 0) {


				int tmp = pizza[p].size;
				pizza[p].size = pizza[p - 1].size;
				pizza[p - 1].size = tmp;

				tmp = pizza[p].amount;
				pizza[p].amount = pizza[p - 1].amount;
				pizza[p - 1].amount = tmp;

				int tmpi = pizza[p].cost;
				pizza[p].cost = pizza[p - 1].cost;
				pizza[p - 1].cost = tmpi;

				int tmpi2 = pizza[p].kind;
				pizza[p - 1].kind = pizza[p - 1].kind;
				pizza[p - 1].kind = tmpi2;
			}
		}
	}
	showing(pizza, size);
}

void sort_amount(pizza* pizza, int size)
{
	int i = 0;
	int j = 0;
	int p = 0;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (strcmp(pizza[i].amount, pizza[j].amount) > 0) {


				int tmp = pizza[p].size;
				pizza[p].size = pizza[p - 1].size;
				pizza[p - 1].size = tmp;

				tmp = pizza[p].amount;
				pizza[p].amount = pizza[p - 1].amount;
				pizza[p - 1].amount = tmp;

				int tmpi = pizza[p].cost;
				pizza[p].cost = pizza[p - 1].cost;
				pizza[p - 1].cost = tmpi;

				int tmpi2 = pizza[p].kind;
				pizza[p - 1].kind = pizza[p - 1].kind;
				pizza[p - 1].kind = tmpi2;
			}
		}
	}
	showing(pizza, size);
}

void sort_cost(pizza* pizza, int size)
{
	for (int i = 0; i < size; i++) {
		int p = i;
		while (p > 0 && pizza[p].cost < pizza[p - 1].cost) {

			int tmp = pizza[p].size;
			pizza[p].size = pizza[p-1].size;
			pizza[p-1].size = tmp;

			tmp = pizza[p].amount;
			pizza[p].amount = pizza[p-1].amount;
			pizza[p-1].amount = tmp;

			int tmpi = pizza[p].cost;
			pizza[p].cost = pizza[p-1].cost;
			pizza[p-1].cost = tmpi;

			int tmpi2 = pizza[p].kind;
			pizza[p-1].kind = pizza[p-1].kind;
			pizza[p-1].kind = tmpi2;
		}
	}
	showing(pizza, size);
}

void sort_kind(pizza* pizza, int size)
{
	for (int i = 0; i < size; i++) {
		int p = i;
		while (p > 0 && pizza[p].kind < pizza[p - 1].kind) {

			int tmp = pizza[p].size;
			pizza[p].size = pizza[p - 1].size;
			pizza[p - 1].size = tmp;

			tmp = pizza[p].amount;
			pizza[p].amount = pizza[p - 1].amount;
			pizza[p - 1].amount = tmp;

			int tmpi = pizza[p].cost;
			pizza[p].cost = pizza[p - 1].cost;
			pizza[p - 1].cost = tmpi;

			int tmpi2 = pizza[p].kind;
			pizza[p - 1].kind = pizza[p - 1].kind;
			pizza[p - 1].kind = tmpi2;
		}
	}
	showing(pizza, size);
}

void deleting(pizza* pizza, int* size)
{
	printf("Enter the number of object, that you want to delete:\n");
	int oper = 0;
	while (oper > (*size) || oper <= 0) {
		printf("Error, you can not delete structure that you have not\n");
		oper = input_size();
		oper = oper - 1;
	}
	for (int i = 0; i < (*size); i++)
	{
		
	   int  tmp = pizza[oper].size;
		pizza[oper].size = pizza[oper + 1].size;
		pizza[oper + 1].size = tmp;

		int tmp1 = pizza[oper].amount;
		pizza[oper].amount = pizza[oper + 1].amount;
		pizza[oper + 1].amount = tmp1;

		int tmp2 = pizza[oper].cost;
		pizza[oper].cost = pizza[oper + 1].cost;
		pizza[oper + 1].cost = tmp2;

		int tmp3 = pizza[oper].kind;
		pizza[oper].kind = pizza[oper + 1].kind;
		pizza[oper + 1].kind = tmp3;
	}
	(*size)--;
}

//void freeshka(pizza* pizza, int size) {
//	for (int i = 0; i < size; i++) {
//		free(pizza[i].name);
//	
//	}
//	free(pizza);
//}

