#pragma pack(1)

typedef struct {
    unsigned char  fileMarker1;
    unsigned char  fileMarker2;
    unsigned int   bfSize;
    unsigned short unused1;
    unsigned short unused2;
    unsigned int   imageDataOffset;
} bmp_fileheader;

typedef struct {
    unsigned int  biSize;
    signed int     w;  // width
    signed int     h;  // height
    unsigned short planes;
    unsigned short bitPix;
    unsigned int   biCompression;
    unsigned int   biSizeImage;
    int            biXPelsPerMeter;
    int            biYPelsPerMeter;
    unsigned int   biClrUsed;
    unsigned int   biClrImportant;
} bmp_infoheader;

#pragma pack()

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} color;

typedef struct {
    color **map;
    int w;
    int h;
} image;

typedef struct {
    image pic;
    bmp_fileheader fileh;
    bmp_infoheader infoh;
} bmp_file;

typedef struct {
    unsigned char l_w;  // line_width
    color draw_clr;
} set;

typedef struct {
    unsigned int y;
    unsigned int x;
} pt2D;
