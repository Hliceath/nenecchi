#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "utils.h"

void create_file(char* path, const char* content) {
    FILE* file = fopen(path, "w");

    if (!file) {
        printf(RED "error" RESET ": failed to open file '%s' for writing!",
               path);
        exit(-1);
    }

    fputs(content, file);

    fclose(file);
}

void create_directory(const char* path) {
    if (mkdir(path, CHMOD) == -1) {
        printf(RED "error" RESET ": failed creating '%s' directory.\n", path);
        exit(-1);
    }
}
