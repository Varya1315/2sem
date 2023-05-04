//#define _CRT_SECURE_NO_WARNINGS
#define CONST 128
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    char name[CONST];
    printf("Enter a filename: ");
    scanf("%s", name);

    FILE* input_file = fopen(name, "rb");
    if (!input_file) {
        printf("Error: could not open input file.\n");
        return -1;
    }
    fseek(input_file,0, SEEK_SET);
    BMPHeader header;
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    fread(&fileHeader, sizeof(BMPFileHeader), 1, input_file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, input_file);
    header.file_header=fileHeader;
    header.info_header=infoHeader;
    if (header.file_header.type != 0x4D42) {
        printf("Error: not a BMP file.\n");
        fclose(input_file);
        return -1;
    }

    if (header.info_header.bit_count != 24) {
        printf("Error: only 24-bit images are supported.\n");
        fclose(input_file);
        return -1;
    }
    fseek(input_file, header.file_header.offset, SEEK_SET);

    int width = header.info_header.width;
    int height = header.info_header.height;

    int padding = (4 - (header.info_header.width * sizeof(Pixel)) % 4) % 4;

    Pixel* pixels = malloc(width * height * sizeof(Pixel));
    for (int i = 0; i < height; i++) {
        fread(pixels+(i*width), sizeof(Pixel), width, input_file);
        fseek(input_file,padding*sizeof(unsigned char),SEEK_CUR);
    }
    fread(pixels, sizeof(Pixel), width * height, input_file);
    menu(pixels, width, height);
    writeFile("out.bmp", header, pixels);

    free(pixels);
    fclose(input_file);

    return 0;
}
