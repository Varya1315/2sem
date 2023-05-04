#pragma pack(push, 1)

typedef struct {
    unsigned short type;
    unsigned int size;//размер файла BMP
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPFileHeader;

typedef struct {
    unsigned int size;//размер заголовка
    int width;
    int height;
    unsigned short planes;
    unsigned short bit_count;
    unsigned int compression;
    unsigned int size_image;
    int x_pels_per_meter;
    int y_pels_per_meter;
    unsigned int clr_used;
    unsigned int clr_important;
} BMPInfoHeader;

typedef struct {
    BMPFileHeader file_header;
    BMPInfoHeader info_header;
} BMPHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

#pragma pack(pop)//востановление предыдущего выравнивания

void input_range(int* num, int min, int max);
Pixel median(Pixel* arr, int n);
void negativeImage(Pixel* pixels, int width, int height);
void convertToBlackAndWhite(Pixel* pixels, int width, int height);
void menu(Pixel* pixels, int width, int height);
void gammaCorrection(Pixel* pixels, int width, int height);
void MedianFilter(Pixel* pixels, int width, int height);

void input_range(int* num, int min, int max);

void writeFile(const char* filename, BMPHeader header, Pixel* pixels);

