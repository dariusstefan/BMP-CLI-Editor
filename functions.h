#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bmp_header.h"

#define MAX_CHARS 50
#define MAX_CHARS_OP 20

#define RGB 3  // bytes per RGB pixel
#define PAD_C1 32  // constant for computing padding
#define PAD_C2 31  // constant for computing padding

#define SAVE 1
#define EDIT 2
#define INSERT 3
#define SET 4
#define DRAW 5
#define FILL 6
#define QUIT 7
#define OTHER 8

#define uint unsigned int

void parser(bmp_file *bmp, set *drawset);
void menu(char *operation, char *command, bmp_file *bmp, set *drawset);
int op_to_int(char *operation);

void save(char *path, bmp_file *bmp);
void edit(char *path, bmp_file *bmp);
void readmap(FILE *inp, int height, int width, image *pic,  int bitPix);
void freemap(bmp_file *bmp);

void insert(char *path, bmp_file *bmp, uint y, uint x);

void draw(char *command, bmp_file *bmp, set *drawset);
void set_f(char *command, set *drawset);

void line(bmp_file *bmp, set *drawset, pt2D A, pt2D B);
void rectangle(bmp_file *bmp, set *drawset, pt2D A, uint width, uint height);
void triangle(bmp_file *bmp, set *drawset, pt2D A, pt2D B, pt2D C);

int check_pt(int y, int x, int width, int height);
void ch_clr(color *color0, color new_color);
void paint(bmp_file *bmp, set *drawset, pt2D A);

void vertical_line(bmp_file *bmp, set *drawset, pt2D A, pt2D B);
void horizontal_line(bmp_file *bmp, set *drawset, pt2D A, pt2D B);
void oblique_line(bmp_file *bmp, set *drawset, pt2D A, pt2D B);

void fill(bmp_file *bmp, set *drawset, color clr0, int y, int x);
int clr_equal(color a, color b);

void check_alloc(void *pointer, char *func);
void check_fopen(FILE *f, char *func);
uint maxim(uint a, uint b);
