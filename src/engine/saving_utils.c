/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** saving_utils
*/

#include "my.h"
#include "saving.h"

void save_free(save_t *save)
{
	free(save->name);
	my_free_array((void **)save->data);
	free(save);
}

int save_cmp_name(save_t *a, save_t *b)
{
	if (a->name == NULL || b->name == NULL)
		return ((int)(a->name - b->name));
	return (my_strcmp(a->name, b->name));
}