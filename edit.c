#include "functions.h"

void edit(char *path, bmp_file *bmp) {
    FILE *inp = fopen(path, "rb");
    check_fopen(inp, "edit");

    fread(&bmp->fileh, sizeof(bmp_fileheader), 1, inp);
    fread(&bmp->infoh, sizeof(bmp_infoheader), 1, inp);

    fseek(inp, bmp->fileh.imageDataOffset, SEEK_SET);

    readmap(inp, bmp->infoh.h, bmp->infoh.w, &bmp->pic, bmp->infoh.bitPix);

    fclose(inp);
}

void readmap(FILE *inp, int height, int width, image *pic,  int bitPix) {
    pic->w = width;
    pic->h = height;

    pic->map = (color **) malloc(height * sizeof(color *));
    check_alloc(pic->map, "readmap");

    int rowsize = ((bitPix * width + PAD_C2) / PAD_C1) * 4;

    int padding = rowsize - width * RGB;

    for (int i = 0; i < height; i++) {
        pic->map[i] = (color *) malloc(width * sizeof(color));
        check_alloc(pic->map[i], "readmap");

        fread(pic->map[i], width, sizeof(color), inp);

        fseek(inp, padding, SEEK_CUR);
    }
}
