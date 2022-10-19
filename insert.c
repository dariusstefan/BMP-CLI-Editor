#include "functions.h"

void insert(char *path, bmp_file *bmp, uint y, uint x) {
    int H = bmp->infoh.h;
    int W = bmp->infoh.w;

    if (x < H && y < W) {
        FILE *insertf = fopen(path, "rb");
        check_fopen(insertf, "insert");

        bmp_fileheader insertheader;
        bmp_infoheader insertinfo;

        memset(&insertheader, 0, sizeof(bmp_fileheader));
        memset(&insertinfo, 0, sizeof(bmp_infoheader));

        fread(&insertheader, sizeof(insertheader), 1, insertf);
        fread(&insertinfo, sizeof(insertinfo), 1, insertf);

        fseek(insertf, insertheader.imageDataOffset, SEEK_SET);

        int h = insertinfo.h;
        int w = insertinfo.w;

        int cols = W - (int)y;

        int insertrowsz = ((insertinfo.bitPix * w + PAD_C2) / PAD_C1) * 4;

        int insertpadding = insertrowsz - w * RGB;

        uint i = 0, j = 0, k = 0, l = 0;

        for (i = x; i < H && l < h; i++, l++) {
            for (j = y, k = 0; j < W && k < w; j++, k++)
                fread(&bmp->pic.map[i][j], sizeof(color), 1, insertf);

            if (w - cols > 0)
                fseek(insertf, insertpadding + (w - cols) * RGB, SEEK_CUR);
            else
                fseek(insertf, insertpadding, SEEK_CUR);
        }

        fclose(insertf);
    }
}
