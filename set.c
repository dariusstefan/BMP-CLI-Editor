#include "functions.h"

void set_f(char *command, set *drawset) {
    char *arg = malloc(MAX_CHARS_OP * sizeof(char));
    check_alloc(arg, "set_f");

    int skip = strlen("set");
    int i = skip + 1, j = 0;

    while (command[i] != ' ') {
        arg[j++] = command[i++];
    }
    arg[j] = '\0';

    if (strcmp(arg, "draw_color") == 0) {
        char *ptr = strtok(command + skip + 1, " ");
        i = 0;

        while (ptr != NULL) {
            if (i == 1) {
                drawset->draw_clr.blue = atoi(ptr);
            } else {
                if (i == 2) {
                    drawset->draw_clr.green = atoi(ptr);
                } else {
                    if (i == 3)
                        drawset->draw_clr.red = atoi(ptr);
                }
            }
            ptr = strtok(NULL, " ");
            i++;
        }

        printf("Color set: R:%hu ", drawset->draw_clr.red);
        printf("G:%hu ", drawset->draw_clr.green);
        printf("B:%hu\n", drawset->draw_clr.blue);

    } else {
        if (strcmp(arg, "line_width") == 0) {
            char *ptr = strtok(command + skip + 1, " ");
            i = 0;

            while (ptr != NULL) {
                if (i == 1)
                    drawset->l_w = atoi(ptr);
                ptr = strtok(NULL, " ");
                i++;
            }
        }

        printf("New line_width: %hu\n", drawset->l_w);
    }
    free(arg);
}
