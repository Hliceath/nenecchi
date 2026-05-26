#pragma once

#define CHMOD 0755

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

#define VERSION "v1.1.3"

enum MSG_TYPE { SUCCESS, ERROR, INFO };

void create_file(char* path, const char* content);
void create_directory(const char* path);
void show_version();
void show_help();
void print_msg(enum MSG_TYPE type, char* msg);
