#include "Header.h"
int main()
{
    FILE* inputFilename;
    fopen_s(&inputFilename, "C:/Users/varvara/CLionProjects/text.txt", "r");

    if (fopen_s(&inputFilename, "C:/Users/varvara/CLionProjects/text.txt", "r") != 0)
    {
        printf("Error opening file.\n");
        return 0;
    }
    FILE* outputFilename;
    fopen_s(&outputFilename, "C:/Users/varvara/CLionProjects/compressed.txt", "w+");

    int size = 1;
    Words* words = (Words*)malloc(size * sizeof(Words));
    Words* wordsOne = (Words*)malloc(size * sizeof(Words));
    Words* wordsTwo = (Words*)malloc(size * sizeof(Words));

    initializeArr(inputFilename, &words, &size);
    replacement(words, &size, &wordsOne, &wordsTwo);

    frequency(wordsOne, size);
    frequency(wordsTwo, size);

    qsort(wordsTwo, size, sizeof(Words), (int(*) (const void *, const void *)) compareLong);
    qsort(wordsOne, size, sizeof(Words), (int(*) (const void *, const void *)) compareShort);

    library(outputFilename, wordsTwo, wordsOne, size);
    changeFile(inputFilename, outputFilename, wordsOne, wordsTwo, size);

    printWords(wordsOne, wordsTwo, size);

    for (int i = 0; i < size - 1; i++)
    {
        free(wordsOne[i].word);
        free(wordsTwo[i].word);
        free(words[i].word);
    }

    free(wordsOne);
    free(wordsTwo);

    fclose(inputFilename);
    fclose(outputFilename);
}