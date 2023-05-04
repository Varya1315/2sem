#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <math.h>
#include <string.h>
void menu(Pixel* pixels, int width, int height)
{
    int chs = 0;

        printf("\nChoose:\n");
        printf("1 - Negative\n");
        printf("2 - Black and white\n");
        printf("3 - Gammacorection\n");
        printf("4 - Median filtering\n");
        printf(":Input number :\n");
        input_range(&chs, 1,5);
        printf("U entered %d\n", chs);
        switch (chs) {
            case 1:
                negativeImage(pixels, width, height);
                break;
            case 2:
                convertToBlackAndWhite(pixels, width, height);
                break;

            case 3:
                gammaCorrection(pixels, width, height);
                break;

            case 4:
                MedianFilter(pixels, width, height);
                break;

            default:
                break;
        }
    }
void negativeImage(Pixel* pixels, int width, int height)
{

    for (int i = 0; i < width * height; i++)
    {
        pixels[i].red = 255 - pixels[i].red;
        pixels[i].green = 255 - pixels[i].green;
        pixels[i].blue = 255 - pixels[i].blue;
    }
}

void convertToBlackAndWhite(Pixel* pixels, int width, int height)
{
    unsigned char average;
    for (int i = 0; i < width * height; i++)
    {
        average = (pixels[i].red + pixels[i].green + pixels[i].blue) / 3;
        pixels[i].red = average;
        pixels[i].green = average;
        pixels[i].blue = average;
    }
}

void gammaCorrection(Pixel* pixels, int width, int height)
{
    float gamma = 0;
    printf(":Input gamma cf:\n");
    scanf("%f", &gamma);
    printf("Gamma = %f\n", gamma);
    for (int i = 0; i < width * height; i++)
    {
        pixels[i].red = (unsigned char)(pow((double)pixels[i].red / 255.0, gamma) * 255.0 + 0.5);
        pixels[i].green = (unsigned char)(pow((double)pixels[i].green / 255.0, gamma) * 255.0 + 0.5);
        pixels[i].blue = (unsigned char)(pow((double)pixels[i].blue / 255.0, gamma) * 255.0 + 0.5);
    }
}

void MedianFilter(Pixel* pixels, int width, int height)
{
    Pixel window[9];
    for (int y = 1; y < height - 1; y++)
    {
        for (int x = 1; x < width - 1; x++)
        {
            int k = 0;
            for (int j = -1; j <= 1; j++)
            {
                for (int i = -1; i <= 1; i++)
                {
                    window[k++] = pixels[(y + j) * width + x + i];
                }
            }
            pixels[y * width + x] = median(window, k);
        }
    }
}
Pixel median(Pixel* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].red > arr[j].red) {
                Pixel temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr[n / 2];
}

void writeFile(const char* filename, BMPHeader header, Pixel* pixels) {
    FILE *f = fopen(filename, "wb");

    if (!f) {
        printf("Could not open file %s\n", filename);
        return;
    }

    fwrite(&header.file_header, sizeof(header.file_header), 1, f);
    fwrite(&header.info_header, sizeof(header.info_header), 1, f);

    int padding = (4 - (header.info_header.width * sizeof(Pixel)) % 4) % 4;

    for (int y = 0; y < header.info_header.height; y++) {
        for (int x = 0; x < header.info_header.width; x++) {
            fwrite(&pixels[y*header.info_header.width + x], sizeof(Pixel), 1, f);
        }
        fwrite(&pixels,padding* sizeof(unsigned char), 1, f);
    }

    fclose(f);
}
void input_range(int* num, int min, int max) {
    int in = 0;
    do {
        printf("Enter a value (%d-%d): ", min, max);
        if (scanf("%d", num) != 1) {
            printf("Error input\n");
            scanf("%*[^\n]");
            continue;
        }
        in = (*num >= min) && (*num <= max);
        if (!in) {
            printf("Error input\n");
        }
    } while (!in);
}
