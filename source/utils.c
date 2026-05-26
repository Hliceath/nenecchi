#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "utils.h"

extern int errno;

void create_file(char* path, const char* content) {
    FILE* file = fopen(path, "w");

    if (!file) {
        fprintf(stderr, RED "error: " RESET "%s\n", strerror(errno));
        exit(-1);
    }

    fputs(content, file);

    fclose(file);
}

void create_directory(const char* path) {
    if (mkdir(path, CHMOD) == -1) {
        fprintf(stderr, RED "error: " RESET "%s\n", strerror(errno));
        exit(-1);
    }
}

void show_version() {
    char version_str[20] = "nenecchi " VERSION;
    print_msg(INFO, version_str);
}

void show_help() {
    print_msg(INFO, "create a new C/C++ project with the command `nenecchi new "
                    "<project_name>`");
}

void print_msg(enum MSG_TYPE type, char* msg) {
    switch (type) {
    case SUCCESS:
        printf(GREEN "success: " RESET "%s\n", msg);
        break;
    case ERROR:
        printf(RED "error: " RESET "%s\n", msg);
        break;
    case INFO:
        printf(CYAN "info: " RESET "%s\n", msg);
        break;
    default:
        printf("%s\n", msg);
        break;
    }
}
