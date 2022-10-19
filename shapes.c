#include "functions.h"

void line(bmp_file *bmp, set *drawset, pt2D A, pt2D B) {
    if (A.x == B.x) {
        horizontal_line(bmp, drawset, A, B);
    } else {
        if (A.y == B.y) {
            vertical_line(bmp, drawset, A, B);
        } else {
            oblique_line(bmp, drawset, A, B);
        }
    }
}

void rectangle(bmp_file *bmp, set *drawset, pt2D A, uint width, uint height) {
    pt2D B = {0, 0}, C = {0, 0}, D = {0, 0};

    B.x = A.x;
    B.y = A.y + width;

    C.x = B.x + height;
    C.y = B.y;

    D.x = C.x;
    D.y = A.y;

    line(bmp, drawset, A, B);
    line(bmp, drawset, B, C);
    line(bmp, drawset, C, D);
    line(bmp, drawset, D, A);
}

void triangle(bmp_file *bmp, set *drawset, pt2D A, pt2D B, pt2D C) {
    line(bmp, drawset, A, B);
    line(bmp, drawset, B, C);
    line(bmp, drawset, C, A);
}

int check_pt(int y, int x, int width, int height) {
    if (y >= 0 && y < width && x >= 0 && x < height)
        return 1;
    return 0;
}

void paint(bmp_file *bmp, set *drawset, pt2D A) {
    int xstart = (int) A.x - drawset->l_w / 2;
    int xfinal = (int) A.x + drawset->l_w / 2;

    int ystart = (int) A.y - drawset->l_w / 2;
    int yfinal = (int) A.y + drawset->l_w / 2;

    for (int i = xstart; i <= xfinal; i++) {
        for (int j = ystart; j <= yfinal; j++) {
            if (check_pt(j, i, bmp->infoh.w, bmp->infoh.h) == 1) {
                ch_clr(&bmp->pic.map[i][j], drawset->draw_clr);
            }
        }
    }
}

void ch_clr(color *color0, color new_color) {
    *color0 = new_color;
}

void vertical_line(bmp_file *bmp, set *drawset, pt2D A, pt2D B) {
    uint start = 0, final = 0;
    final = maxim(A.x, B.x);

    if (A.x == final)
        start = B.x;
    else
        start = A.x;

    uint i = start;

    for (; i <= final && i < bmp->infoh.h; i++) {
        pt2D color_point = {A.y, i};
        paint(bmp, drawset, color_point);
    }
}

void horizontal_line(bmp_file *bmp, set *drawset, pt2D A, pt2D B) {
    uint start = 0, final = 0;
    final = maxim(A.y, B.y);

    if (A.y == final)
        start = B.y;
    else
        start = A.y;

    uint i = start;

    for (; i <= final && i < bmp->infoh.w; i++) {
        pt2D color_point = {i, A.x};
        paint(bmp, drawset, color_point);
    }
}

void oblique_line(bmp_file *bmp, set *drawset, pt2D A, pt2D B) {
    paint(bmp, drawset, A);
    paint(bmp, drawset, B);

    uint maxx = maxim(A.x, B.x);
    uint maxy = maxim(A.y, B.y);

    uint diffx = maxx - (A.x + B.x - maxx);
    uint diffy = maxy - (A.y + B.y - maxy);

    if (diffx == maxim(diffx, diffy)) {
        uint final = maxx - 1;
        uint start = A.x + B.x - maxx + 1;

        int i = (int)start;

        int m = (int)(B.x - A.x);
        int n = (int)(B.y - A.y);

        for (; i <= final && i < bmp->infoh.h; i++) {
            int j = (n * (i - (int)A.x) + (int) A.y * m) / m;

            if (j < bmp->infoh.w) {
                pt2D color_point = {j, i};
                paint(bmp, drawset, color_point);
            }
        }
    } else {
        uint final = maxy - 1;
        uint start = A.y + B.y - maxy + 1;

        int i = (int)start;

        int m = (int)(B.x - A.x);
        int n = (int)(B.y - A.y);

        for (; i <= final && i < bmp->infoh.w; i++) {
            int j = (m * (i - (int)A.y) + (int)A.x * n) / n;

            if (j < bmp->infoh.h) {
                pt2D color_point = {i, j};
                paint(bmp, drawset, color_point);
            }
        }
    }
}
