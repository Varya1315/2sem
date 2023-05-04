
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

void distribution(Words* words, int* size, Words** wordsArrayOne, Words** wordsArrayTwo)//что менять
{
    int countWords = averageCount(words, *size);// среднее значение числа повторений слов (averageCount)
    int wordSize = averageLength(words, *size);//длины слов (averageLength)
    int newSize = 0, sizeOne = 1, sizeTwo = 1;

    for (int i = 0; i < *size; i++)
    {
        if (words[i].countWords > countWords && words[i].wordSize > wordSize)//кол во повторений > среднее знач повторений и длина больше средней
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

int replaceWords(FILE* file, Words* wordsArrayOne, Words* wordsArrayTwo, int size, char* word)
{
    int ss = 0;

    for (int i = 0; i < size; i++)
    {
        if (!strcmp(wordsArrayOne[i].word, word))//сравнение строк ergh>ty
        {
            fprintf(file, "%s", wordsArrayTwo[i].word);
            ss = 1;
        }

        else if (!strcmp(wordsArrayTwo[i].word, word))
        {
            fprintf(file, "%s", wordsArrayOne[i].word);
            ss = 1;
        }
    }

    return ss;
}

int counterWord(Words* words, char* word, int size)
{
    int ss = 0;
    for (int i = 0; i < size - 1; i++)
    {

        if (!strcmp(words[i].word, word))//i элемент структуры words
            //поля строки
        {
            words[i].countWords++;
            ss = 1;
        }
    }

    return ss;
}

void initializeArr(FILE* file, Words** words, int* size)//из файла в структуру Words
{
    for (int i = 0; !feof(file); i++)
    {
        char* word = malloc(100);
        fscanf_s(file, "%s", word, 100);
        if (!counterWord((*words), word, (*size)) && strlen(word) > 0)
        {
            (*words)[(*size) - 1].word = malloc(100);
            (*words)[(*size) - 1].word = word;//считывание слова
            (*words)[(*size) - 1].wordSize = strlen(word);//длина слова
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
    return (wordsA->freq - wordsB->freq);//затем возвращает разность частот слов
}

void changeFile(FILE* file, FILE* newFile, Words* wordsArrayOne, Words* wordsArrayTwo, int size)
{
    while (!feof(file))
    {
        char c;
        char* word = malloc(100);
        fscanf_s(file, "%s%c", word, 100, &c, 1);

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

void printWords(Words* words1, Words* words2, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d: %s -- %s\n", i + 1, words1[i].word, words2[i].word);
    }
}

void library(FILE* newFile, Words* wordsArrayTwo, Words* wordsArrayOne, int size)//записывает в файл
{
    for (int i = 0; i < size; i++)
    {
        fprintf(newFile, "%s %s ", wordsArrayTwo[i].word, wordsArrayOne[i].word);
    }
    fprintf(newFile, "%s\n", "<!>");
}

void displaySize(FILE* inputFilename, FILE* outputFilename)
{
    fseek(inputFilename, 0, SEEK_END);
    long inputSize = ftell(inputFilename);//возвращает длину файла

    fseek(outputFilename, 0, SEEK_END);
    long outputSize = ftell(outputFilename);

    printf("Input file size: %ld bytes\n", inputSize);
    printf("Output file size: %ld bytes\n", outputSize);
}

void frequency(Words* words, int size)//частота слова
{
    for (int i = 0; i < size; i++)
    {
        words[i].freq = words[i].countWords * strlen(words[i].word);//умножая число повторений слова на длину этого слова в символах
    }
}
