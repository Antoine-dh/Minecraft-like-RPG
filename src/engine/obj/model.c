/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "model.h"
#include "game.h"

int animodel_cmp_by_name(animodel_t *a, animodel_t *b)
{
	if (a->name == NULL || b->name == NULL)
		return ((int)(a->name - b->name));
	return (my_strcmp(a->name, b->name));
}

void free_model(model_t *model)
{
	for (int i = 0 ; i < model->faces_count ; i++) {
		free(model->faces[i].v);
		free(model->faces[i].vt);
	}
	free(model->faces);
	free(model);
}

void free_animodel(animodel_t *model)
{
	for (int i = 0 ; i < model->frames_count ; ++i)
		free_model(model->frames[i]);
	free(model->name);
	free(model);
}
