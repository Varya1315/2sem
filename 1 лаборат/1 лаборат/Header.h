#pragma once
int input();
int input_oper();
int input_size();
int input_sort();
int input_cost();

int str_len(char* str);

void get_str(char** str);

void str_copy(char* str1, char** str2);

void clear_and_stop_console();

typedef struct {
	//char* kind;
	int amount;
	int size;
	int cost;
	char* name;
    enum kind kind;
}pizza;


enum kind{
	Margherita = 1,
	Vegana,
	Peppeponi,
	Capricciosa,
	BBQ,
};

pizza* creating_struct(int* size);
 kind(int num);

void creating(pizza* pizza, int size);
void showing(pizza* pizza, int size);
int main(pizza* pizza);

void sort_size(pizza* pizza, int size);
void sort_amount(pizza* pizza, int size);
void sort_cost(pizza* pizza, int size);;
void sort_kind(pizza* pizza, int size);

void deleting(pizza* pizza, int* size);

 //freeshka(pizza* pizza, int size);