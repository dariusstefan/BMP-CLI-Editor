#include "functions.h"

uint maxim(uint a, uint b) {
    if (a > b)
        return a;
    return b;
}
void check_alloc(void *pointer, char *func) {
    if (pointer == NULL) {
        printf("Allocation failed in %s function!\n", func);
        exit(-1);
    }
}

void check_fopen(FILE *f, char *func) {
    if (f == NULL) {
        printf("fopen failed in %s function!\n", func);
        exit(-1);
    }
}
