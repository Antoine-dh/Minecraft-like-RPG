/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lucas_ben
*/

#ifndef MY_RPG_FILE_H
#define MY_RPG_FILE_H

#include <stdio.h>
#include "list.h"

int file_extension(const char *str, const char *extension);
list_t *file_to_list(FILE *file);
char *get_full_path(char *path, char *file);
char *get_filename(const char *path);

#endif //MY_RPG_FILE_H
