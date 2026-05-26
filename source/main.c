#include <stdlib.h>
#include <string.h>

#include "utils.h"

void create_project(int argc, const char* argv[]);
void create_project_subdirs(char* root_dir);
void create_template_files(char* root_dir);

int main(int argc, const char* argv[]) {
    if (argc <= 1) {
        print_msg(ERROR, "no arguments given");
        exit(-1);
    }

    if (strcmp(argv[1], "new") == 0) {
        create_project(argc, argv);
    } else if (strcmp(argv[1], "--version") == 0 ||
               strcmp(argv[1], "-v") == 0) {
        show_version();

    } else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        show_help();
    } else {
        print_msg(ERROR, "invalid command");
        exit(-1);
    }

    return 0;
}

void create_project(int argc, const char* argv[]) {
    char root_dir[253] = "./";
    if (argc != 3) {
        print_msg(ERROR, "missing project name");
        exit(-1);
    }

    if (sizeof(argv[2]) > 250) {
        print_msg(ERROR, "name of folder too long (limit 250 chars)");
        exit(-1);
    }

    print_msg(INFO, "creating a new C/C++ project");

    create_directory(argv[2]);
    strcat(root_dir, argv[2]);
    create_project_subdirs(root_dir);
    create_template_files(root_dir);

    print_msg(SUCCESS,
              "for a c++ project make sure to rename main.c to main.cpp");
}

void create_project_subdirs(char* root_dir) {
    const char* subdirs[4] = {"/bin", "/build", "/include", "/source"};
    const char main_content[105] = "#include <stdio.h>\n\n"
                                   "int main(int argc, const char* argv[]) {"
                                   "\n    printf(\"new game!\");\n"
                                   "    return 0;\n"
                                   "}";

    for (int i = 0; i < (sizeof(subdirs) / sizeof(subdirs[0])); i++) {
        char path_subdir[280] = "";

        strcpy(path_subdir, root_dir);
        strcat(path_subdir, subdirs[i]);
        create_directory(path_subdir);

        if (strcmp(subdirs[i], "/source") == 0) {
            create_file(strcat(path_subdir, "/main.c"), main_content);
        }
    }
}

void create_template_files(char* root_dir) {
    const char* root_files[2] = {"/Makefile", "/.clang-format"};

    for (int i = 0; i < (sizeof(root_files) / sizeof(root_files[0])); i++) {
        char path_file[267] = "";

        strcpy(path_file, root_dir);
        create_file(strcat(path_file, root_files[i]), "# your config here");
    }
}
