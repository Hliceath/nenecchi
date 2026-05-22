#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "utils.h"

void create_template(char* root_dir);

int main(int argc, const char* argv[]) {
    char root_dir[253] = "./";

    if (argc != 3) {
        printf("error: number of arguments must be 2.\n");
        exit(-1);
    }

    if (strcmp(argv[1], "new") == 0) {
        printf("creating a new C/C++ template \"%s\"\n", argv[2]);
    } else {
        printf("invalid command: use the keyword 'new' to create a new "
               "project: 'nenecchi new <project_name>.'\n");
        exit(-1);
    }

    if (sizeof(argv[2]) > 250) {
        printf("error: name of folder too long (limit 250 chars)\n");
        exit(-1);
    }

    create_directory(argv[2]);
    strcat(root_dir, argv[2]);
    create_template(root_dir);
    printf("note: for a c++ project make sure to rename name.c -> name.cpp\n");

    return 0;
}

void create_template(char* root_dir) {
    const char* subdirs[4] = {"/bin", "/build", "/include", "/source"};
    const char main_file[8] = "/main.c";
    const char* root_files[2] = {"/Makefile", "/.clang-format"};

    for (int i = 0; i < (sizeof(subdirs) / sizeof(subdirs[0])); i++) {
        char path_subdir[280] = "";

        strcpy(path_subdir, root_dir);
        strcat(path_subdir, subdirs[i]);
        create_directory(path_subdir);

        if (strcmp(subdirs[i], "/source") == 0) {
            create_file(strcat(path_subdir, main_file));
        }
    }

    for (int i = 0; i < (sizeof(root_files) / sizeof(root_files[0])); i++) {
        char path_file[267] = "";

        strcpy(path_file, root_dir);
        create_file(strcat(path_file, root_files[i]));
    }
}
