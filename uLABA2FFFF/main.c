#include "help.h"

int main()
{
    FILE* filename;
    FILE* putFilename;
    fopen_s(&putFilename, "C:/Users/varvara/CLionProjects/decompressed.txt", "w+");

    if (fopen_s(&filename, "C:/Users/varvara/CLionProjects/compressed.txt", "r") != 0)
    {
        printf("File is not open or does not exist!!!\n");
    }

    int size = 1;
    Words* words = (Words*)malloc(size * sizeof(Words));
    Words* wordsOne = (Words*)malloc(size * sizeof(Words));
    Words* wordsTwo = (Words*)malloc(size * sizeof(Words));

    replacement(filename, &wordsOne, &wordsTwo, &size, words);
    changeFile(filename, putFilename, wordsOne, wordsTwo, size);

    for (int i = 0; i < size - 1; i++)
    {
        free(wordsOne[i].word);
        free(wordsTwo[i].word);
    }

    fclose(filename);
    fclose(putFilename);
}
