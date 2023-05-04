#ifndef COMPRESSION_INITIALIZATION_H
#define COMPRESSION_INITIALIZATION_H
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 3
#define COUNT 2

typedef struct
{
    char* word;
    int wordSize;
    int countWords;
    int freq;
} Words;

int averageCount(Words* words, int size);
int averageLength(Words* words, int size);
int replaceWords(FILE* file, Words* wordsArrayOne, Words* wordsArrayTwo, int size, char* word);
int counterWord(Words* words, char* word, int size);
void initializeArr(FILE* file, Words** words, int* size);
int compareLong(void *a, void *b);
int compareShort(void* a, void* b);
void changeFile(FILE* file, FILE* newFile, Words* wordsArrayOne, Words* wordsArrayTwo, int size);
void replacement(Words* words, int* size, Words** wordsArrayOne, Words** wordsArrayTwo);
void printWords(Words* words1, Words* words2, int size);
void library(FILE* newFile, Words* wordsArrayTwo, Words* wordsArrayOne, int size);

void frequency(Words* words, int size);

int profit(Words *word1, Words *word2);

#endif //COMPRESSION_INITIALIZATION_H