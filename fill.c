#include "functions.h"

void fill(bmp_file *bmp, set *drawset, color clr0, int y, int x) {
    if (check_pt(y, x, bmp->infoh.w, bmp->infoh.h)) {
        if (clr_equal(bmp->pic.map[x][y], clr0)) {
            ch_clr(&bmp->pic.map[x][y], drawset->draw_clr);

            fill(bmp, drawset, clr0, y - 1, x);
            fill(bmp, drawset, clr0, y, x - 1);
            fill(bmp, drawset, clr0, y, x + 1);
            fill(bmp, drawset, clr0, y + 1, x);
        }
    }
}

int clr_equal(color a, color b) {
    if (a.blue == b.blue && a.red == b.red && a.green == b.green)
        return 1;
    return 0;
}
