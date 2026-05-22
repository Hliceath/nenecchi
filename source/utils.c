#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "utils.h"

void create_file(char* path) {
    FILE* file = fopen(path, "w");

    if (!file) {
        printf("error: failed to open file '%s' for writing!", path);
        exit(-1);
    }

    fclose(file);
}

void create_directory(const char* path) {
    if (mkdir(path, CHMOD) == -1) {
        printf("error: directory already exists.\n");
        exit(-1);
    }
}
