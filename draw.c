#include "functions.h"
#define yA 1
#define xA 2
#define yB 3
#define xB 4
#define yC 5
#define xC 6
#define WIDTH 3
#define HEIGHT 4

void draw(char *command, bmp_file *bmp, set *drawset) {
    char *arg = malloc(MAX_CHARS_OP * sizeof(char));
    check_alloc(arg, "draw");

    int skip = strlen("draw");
    int i = skip + 1, j = 0;

    while (command[i] != ' ') {
        arg[j++] = command[i++];
    }
    arg[j] = '\0';

    if (strcmp(arg, "line") == 0) {
        pt2D A, B;
        i = 0;
        char *ptr = strtok(command + skip + 1, " ");

        while (ptr != NULL) {
            switch (i) {
                case yA:
                    A.y = atoi(ptr);
                    break;
                case xA:
                    A.x = atoi(ptr);
                    break;
                case yB:
                    B.y = atoi(ptr);
                    break;
                case xB:
                    B.x = atoi(ptr);
                    break;
            }
            ptr = strtok(NULL, " ");
            i++;
        }

        printf("Drawing line:\n");
        printf("(%i,%i) -> (%i,%i)\n", A.y, A.x, B.y, B.x);

        line(bmp, drawset, A, B);

    } else {
        if (strcmp(arg, "rectangle") == 0) {
            uint width = 0, height = 0;
            pt2D A;
            i = 0;

            char *ptr = strtok(command + skip + 1, " ");
            while (ptr != NULL) {
                switch (i) {
                    case yA:
                        A.y = atoi(ptr);
                        break;
                    case xA:
                        A.x = atoi(ptr);
                        break;
                    case WIDTH:
                        width = atoi(ptr);
                        break;
                    case HEIGHT:
                        height = atoi(ptr);
                        break;
                }
                ptr = strtok(NULL, " ");
                i++;
            }

            printf("Drawing rectangle:\n");
            printf("Start point: (%i,%i) W:%i H:%i\n", A.y, A.x, width, height);

            rectangle(bmp, drawset, A, width, height);

        } else {
            if (strcmp(arg, "triangle") == 0) {
                pt2D A, B, C;
                i = 0;
                char *ptr = strtok(command + skip + 1, " ");

                while (ptr != NULL) {
                    switch (i) {
                        case yA:
                            A.y = atoi(ptr);
                            break;
                        case xA:
                            A.x = atoi(ptr);
                            break;
                        case yB:
                            B.y = atoi(ptr);
                            break;
                        case xB:
                            B.x = atoi(ptr);
                            break;
                        case yC:
                            C.y = atoi(ptr);
                            break;
                        case xC:
                            C.x = atoi(ptr);
                    }
                    ptr = strtok(NULL, " ");
                    i++;
                }

                printf("Drawing triangle:\n");
                printf("A(%i,%i) ", A.y, A.x);
                printf("B(%i,%i) ", B.y, B.x);
                printf("C(%i,%i)\n", C.y, C.x);

                triangle(bmp, drawset, A, B, C);
            }
        }
    }
}
