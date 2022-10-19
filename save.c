#include "functions.h"

void save(char *path, bmp_file *bmp) {
    FILE *out = fopen(path, "wb");
    check_fopen(out, "save");

    fwrite(&bmp->fileh, sizeof(bmp_fileheader), 1, out);
    fwrite(&bmp->infoh, sizeof(bmp_infoheader), 1, out);

    int rowsize = ((bmp->infoh.bitPix * bmp->infoh.w + PAD_C2) / PAD_C1) * 4;
    int padding = rowsize - bmp->infoh.w * RGB;
    unsigned char null = 0;

    for (int i = 0; i < bmp->pic.h; i++) {
        fwrite(bmp->pic.map[i], sizeof(color), bmp->pic.w, out);

        for (int j = 0; j < padding; j++)
            fwrite(&null, sizeof(unsigned char), 1, out);
    }

    freemap(bmp);
    fclose(out);
}

void freemap(bmp_file *bmp) {
    for (int i = 0; i < bmp->pic.h; i++)
        free(bmp->pic.map[i]);
    free(bmp->pic.map);
}
