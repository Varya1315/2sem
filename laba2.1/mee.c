#define N 100

#include "Header.h"
int averageCount(Words* words, int size)
{
    int average = 0;

    for (int i = 0; i < size; i++)
    {
        average += words[i].countWords;
    }

    return (average / size);
}

int averageLength(Words* words, int size)
{
    int average = 0;

    for (int i = 0; i < size; i++)
    {
        average += words[i].wordSize;
    }


    return (average / size);
}

int replaceWords(FILE* file, Words* wordsArrayOne, Words* wordsArrayTwo, int size, char* word)
{
    int ss = 0;

    for (int i = 0; i < size; i++)
    {
        if (!strcmp(wordsArrayOne[i].word, word) && profit(&wordsArrayTwo[i], &wordsArrayOne[i]))
        {
            fprintf(file, "%s", wordsArrayTwo[i].word);
            ss = 1;
        }

        else if (!strcmp(wordsArrayTwo[i].word, word) && profit(&wordsArrayOne[i], &wordsArrayTwo[i]))
        {
            fprintf(file, "%s", wordsArrayOne[i].word);
            ss = 1;
        }
    }

    return ss;
}

int profit(Words *word1, Words *word2)
{
    int lenA = strlen(word1->word);
    int lenB = strlen(word2->word);//что меняем
    int countA = word1->countWords;
    int countB = word2->countWords;

    if (lenA * countA + lenB * countB - lenA * countB - lenB * countA - 2 - lenB - lenA > 0)
        return 1;
    else
    {
        return 0;
    }
}

int counterWord(Words* words, char* word, int size)
{
    int ss = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (!strcmp(words[i].word, word))
        {
            words[i].countWords++;
            ss = 1;
        }
    }

    return ss;
}

void initializeArr(FILE* file, Words** words, int* size)
{
    for (int i = 0; !feof(file); i++)
    {
        char* word = malloc(N);
        fscanf_s(file, "%s", word, N);
        if (!counterWord((*words), word, (*size)) && strlen(word) > 0)
        {
            (*words)[(*size) - 1].word = malloc(N);
            (*words)[(*size) - 1].word = word;
            (*words)[(*size) - 1].wordSize = strlen(word);
            (*words)[(*size) - 1].countWords = 1;
            (*words) = realloc(*words, (++(*size)) * sizeof(Words));
        }
    }
    words = realloc(*words, ((*size)--) * sizeof(Words));
    rewind(file);
}

int compareLong(void *a, void *b)
{
    Words* wordsA = (Words*)a;
    Words* wordsB = (Words*)b;
    return (wordsB->freq - wordsA->freq);
}

int compareShort(void* a, void* b)
{
    Words* wordsA = (Words*)a;
    Words* wordsB = (Words*)b;
    return (wordsA->freq - wordsB->freq);
}

void changeFile(FILE* file, FILE* newFile, Words* wordsArrayOne, Words* wordsArrayTwo, int size)
{
    while (!feof(file))
    {
        char c;
        char* word = malloc(N);
        fscanf_s(file, "%s%c", word, N, &c, 1);

        if (!replaceWords(newFile, wordsArrayOne, wordsArrayTwo, size, word) && !feof(file))
        {
            fprintf(newFile, "%s", word);
        }

        if (!feof(file))
        {
            fprintf(newFile, "%c", c);
        }
        free(word);
    }
}

void replacement(Words* words, int* size, Words** wordsArrayOne, Words** wordsArrayTwo)
{
    int countWords = averageCount(words, *size);
    int wordSize = averageLength(words, *size);
    int newSize = 0, sizeOne = 1, sizeTwo = 1;
    for (int i = 0; i < *size; i++)
    {
        if (words[i].countWords > countWords && words[i].wordSize > wordSize)
        {
            (*wordsArrayTwo)[(sizeTwo++) - 1] = words[i];
            *wordsArrayTwo = realloc(*wordsArrayTwo, sizeTwo * sizeof(Words));
        }
        if (words[i].countWords < countWords && words[i].wordSize < wordSize)
        {
            (*wordsArrayOne)[(sizeOne++) - 1] = words[i];
            *wordsArrayOne = realloc(*wordsArrayOne, sizeOne * sizeof(Words));
        }
    }
    newSize = sizeTwo - 1;
    *wordsArrayTwo = realloc(*wordsArrayTwo, newSize * sizeof(Words));
    *wordsArrayOne = realloc(*wordsArrayOne, newSize * sizeof(Words));
    *size = newSize;
}

void printWords(Words* words1, Words* words2, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d: %s -- %s\n", i + 1, words1[i].word, words2[i].word);
    }
}

void library(FILE* newFile, Words* wordsArrayTwo, Words* wordsArrayOne, int size)
{
    for (int i = 0; i < size; i++)
    {
        fprintf(newFile, "%s %s ", wordsArrayTwo[i].word, wordsArrayOne[i].word);
    }
    fprintf(newFile, "%s\n", "/");
}

void frequency(Words* words, int size)
{
    for (int i = 0; i < size; i++)
    {
        words[i].freq = words[i].countWords * strlen(words[i].word) ;
    }
}



