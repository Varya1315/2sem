#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef struct
{
    char* word;
    int wordSize;
    int countWords;
    int freq;
}Words;
void replacement(FILE* file, Words** wordsArrayOne, Words** wordsArrayTwo, int* size, Words* words);//из файла в структуру Words
void changeFile(FILE* file, FILE* newFile, Words* wordsArrayOne, Words* wordsArrayTwo, int size);
int replaceWords(FILE* file, Words* wordsArrOne, Words* wordsArrTwo, int size, char* word);
