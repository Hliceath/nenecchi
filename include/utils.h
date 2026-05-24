#pragma once

#define CHMOD 0755

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[36m"
#define RESET "\x1b[0m"

#define VERSION "v1.1.0"

void create_file(char* path, const char* content);
void create_directory(const char* path);
void show_version();
void show_help();
