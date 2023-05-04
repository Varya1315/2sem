
int replaceWords(FILE* file, Words* wordsArrOne, Words* wordsArrTwo, int size, char* word)
{
    int ss = 0;

    for (int i = 0; i < size; i++)
    {
        if (!strcmp(wordsArrOne[i].word, word))//сравнивает две строки
        {
            fprintf(file, "%s", wordsArrTwo[i].word);
            ss = 1;
        }
        else if (!strcmp(wordsArrTwo[i].word, word))
        {
            fprintf(file, "%s", wordsArrOne[i].word);
            ss = 1;
        }
    }
    return ss;
}

void initializeArr(FILE* file, Words** wordsArrayOne, Words** wordsArrayTwo, int* size, Words* words)//из файла в структуру Words
{
    for (int i = 0; !feof(file); i++)
    {
        char* word1 = malloc(100);
        char* word2 = malloc(100);

        fscanf_s(file, "%s", word1, 100);

        if (strcmp(word1, "<!>") == 0)
        {
            (*wordsArrayOne) = realloc(*wordsArrayOne, (--(*size)) * sizeof(Words));
            (*wordsArrayTwo) = realloc(*wordsArrayTwo, (*size) * sizeof(Words));
            break;
        }
        fscanf_s(file, "%s", word2, 100);

        (*wordsArrayOne)[(*size) - 1].word = malloc(100);
        (*wordsArrayOne)[(*size) - 1].word = word1;//считывание слова

        (*wordsArrayTwo)[(*size) - 1].word = malloc(100);
        (*wordsArrayTwo)[(*size) - 1].word = word2;

        (*wordsArrayOne) = realloc(*wordsArrayOne, (++(*size)) * sizeof(Words));
        (*wordsArrayTwo) = realloc(*wordsArrayTwo, (*size) * sizeof(Words));

        printf("%d: %s -- %s\n", i + 1, (*wordsArrayOne)[i].word, (*wordsArrayTwo)[i].word);
    }
}

void changeFile(FILE* file, FILE* newFile, Words* wordsArrayOne, Words* wordsArrayTwo, int size)
{
    for (int i = 0; !feof(file); i++)
    {
        char c;
        char* word = malloc(100);
        fscanf_s(file, "%s%c", word, 100, &c, 1);
        if (!replaceWords(newFile, wordsArrayOne, wordsArrayTwo, size, word) && !feof(file))
        {
            fprintf(newFile, "%s", word);
        }
        if (!feof(file)) fprintf(newFile, "%c", c);
        free(word);
    }
}

void displaySize(FILE* inputFilename, FILE* outputFilename)
{
    fseek(inputFilename, 0, SEEK_END);
    long inputSize = ftell(inputFilename);

    fseek(outputFilename, 0, SEEK_END);
    long outputSize = ftell(outputFilename);

    printf("Input file size: %ld bytes\n", inputSize);
    printf("Output file size: %ld bytes\n", outputSize);
}
