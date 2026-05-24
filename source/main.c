#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

void create_template_subdirs(char* root_dir);

int main(int argc, const char* argv[]) {

    if (strcmp(argv[1], "new") == 0) {
        if (argc != 3) {
            printf(RED "error" RESET ": missing project name\n");
            exit(-1);
        }

        if (sizeof(argv[2]) > 250) {
            printf(RED "error" RESET
                       ": name of folder too long (limit 250 chars)\n");
            exit(-1);
        }

        char root_dir[253] = "./";

        printf(GREEN "creating" RESET " a new C/C++ template \"%s\"\n",
               argv[2]);

        create_directory(argv[2]);
        strcat(root_dir, argv[2]);
        create_template_subdirs(root_dir);

        printf(BLUE
               "note" RESET
               ": for a c++ project make sure to rename main.c to main.cpp\n");
    } else if (strcmp(argv[1], "--version") == 0 ||
               strcmp(argv[1], "-v") == 0) {
        show_version();

    } else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        show_help();
    } else {
        printf(RED "invalid command" RESET
                   ": use the keyword 'new' to create a new "
                   "project: 'nenecchi new <project_name>.'\n");
        exit(-1);
    }

    return 0;
}

void create_template_subdirs(char* root_dir) {
    const char* subdirs[4] = {"/bin", "/build", "/include", "/source"};
    const char main_file[8] = "/main.c";
    const char* root_files[2] = {"/Makefile", "/.clang-format"};
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
            create_file(strcat(path_subdir, main_file), main_content);
        }
    }

    for (int i = 0; i < (sizeof(root_files) / sizeof(root_files[0])); i++) {
        char path_file[267] = "";

        strcpy(path_file, root_dir);
        create_file(strcat(path_file, root_files[i]), "# your config here");
    }
}
