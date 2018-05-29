/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_SAVING_H
#define MY_RPG_SAVING_H

#include "list.h"
#include "my.h"

typedef struct save {
	char *name;
	char **data;
} save_t;

list_t *save_load(const char *path);
save_t *save_create(const char *name, char **data);
void save_free(save_t *save);
bool_t save_write(list_t *save, const char *filename);
int save_cmp_name(save_t *a, save_t *b);
char *save_get_data(list_t *save, const char *name, size_t index);
list_t *load_all_from_dir(const char *path, void *(*loader)(const char *));

#endif //MY_RPG_SAVING_H
