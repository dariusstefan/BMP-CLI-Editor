#include "functions.h"

int main() {
    bmp_file *bmp = malloc(sizeof(bmp_file));
    check_alloc(bmp, "main");

    set *drawset = malloc(sizeof(set));
    check_alloc(drawset, "main");

    drawset->l_w = 1;
    drawset->draw_clr.blue = 0;
    drawset->draw_clr.green = 0;
    drawset->draw_clr.red = 0;

    parser(bmp, drawset);

    free(bmp);
    free(drawset);

    return 0;
}

void parser(bmp_file *bmp, set *drawset) {
    char *command = malloc(MAX_CHARS * sizeof(char));
    check_alloc(command, "parser");

    char *op = malloc(MAX_CHARS_OP * sizeof(char));
    check_alloc(op, "parser");

    do {
        scanf("%[^\n]%*c", command);

        int i = 0;
        while (command[i] != ' ' && command[i] != '\0') {
            op[i] = command[i];
            i++;
        }
        op[i] = '\0';

        menu(op, command, bmp, drawset);
    } while (strcmp(op, "quit") != 0);

    free(command);
    free(op);
}

int op_to_int(char *operation) {
    if (strcmp(operation, "save") == 0) {
        return SAVE;
    } else {
        if (strcmp(operation, "edit") == 0) {
            return EDIT;
        } else {
            if (strcmp(operation, "insert") == 0) {
                return INSERT;
            } else {
                if (strcmp(operation, "set") == 0) {
                    return SET;
                } else {
                    if (strcmp(operation, "draw") == 0) {
                        return DRAW;
                    } else {
                        if (strcmp(operation, "fill") == 0) {
                            return FILL;
                        } else {
                            if (strcmp(operation, "quit") == 0) {
                                return QUIT;
                            } else {
                                return OTHER;
                            }
                        }
                    }
                }
            }
        }
    }
}

void menu(char *operation, char *command, bmp_file *bmp, set *drawset) {
    int i = 0;
    char *ptr = NULL;
    char *path = NULL;

    switch (op_to_int(operation)) {
        case SAVE:
            ptr = strtok(command, " ");
            while (ptr != NULL) {
                if (i > 0)
                    path = ptr;
                ptr = strtok(NULL, " ");
                i++;
            }

            printf("Image saved at path %s...\n", path);
            save(path, bmp);
            break;

        case EDIT:
            ptr = strtok(command, " ");
            while (ptr != NULL) {
                if (i > 0)
                    path = ptr;
                ptr = strtok(NULL, " ");
                i++;
            }

            printf("Start editing file %s...\n", path);
            edit(path, bmp);
            break;

        case INSERT:
            ptr = strtok(command, " ");
            unsigned int y = 0, x = 0;

            while (ptr != NULL) {
                if (i == 1) {
                    path = ptr;
                } else {
                    if (i == 2) {
                        y = atoi(ptr);
                    } else {
                        if (i == 3)
                            x = atoi(ptr);
                    }
                }
                ptr = strtok(NULL, " ");
                i++;
            }

            printf("Inserting image %s at point (%d,%d)...\n", path, x, y);
            insert(path, bmp, y, x);
            break;

        case SET:
            set_f(command, drawset);
            break;

        case DRAW:
            draw(command, bmp, drawset);
            break;

        case FILL:
            ptr = strtok(command + strlen("fill") + 1, " ");
            int Y = 0, X = 0;

            while (ptr != NULL) {
                if (i == 0) {
                    Y = atoi(ptr);
                } else {
                    if (i == 1)
                        X = atoi(ptr);
                }
                i++;
                ptr = strtok(NULL, " ");
            }

            printf("Filling from point (%d,%d) ...\n", Y, X);
            fill(bmp, drawset, bmp->pic.map[X][Y], Y, X);
            break;

        case OTHER:
            printf("Try with a valid command... \n\n");
            break;

        case QUIT:
            printf("Exiting the program... Thank you!\n");
            break;

        default: break;
    }
}
