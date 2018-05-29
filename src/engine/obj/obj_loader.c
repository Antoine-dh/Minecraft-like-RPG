/*
** EPITECH PROJECT, 2018
** obj_loader
** File description:
** Created by lucas_ben,
*/

#include <model.h>
#include "game.h"

model_t *get_model_from_raw(raw_model_t *raw_model)
{
	model_t *model = malloc(sizeof(model_t));

	if (model == NULL)
		return (NULL);
	model->faces_count = raw_model->faces_count;
	model->faces = malloc(sizeof(face_t) * model->faces_count);
	if (model->faces == NULL)
		return (NULL);
	for (int i = 0 ; i < model->faces_count ; i++) {
		model->faces[i].points_count = raw_model->faces[i].points_count;
		model->faces[i].v = malloc(
			sizeof(sfVector3f) * model->faces[i].points_count);
		model->faces[i].vt = malloc(
			sizeof(sfVector2f) * model->faces[i].points_count);
		for (int j = 0 ; j < raw_model->faces[i].points_count ; ++j) {
			model->faces[i].v[j] = raw_model->faces[i].v[j];
			model->faces[i].vt[j] = raw_model->faces[i].vt[j];
		}
	}
	return (model);
}

raw_model_t *get_raw_model(list_t *lines)
{
	raw_model_t *raw_model = malloc(sizeof(raw_model_t));

	if (raw_model == NULL)
		return (NULL);
	memset(raw_model, 0, sizeof(raw_model_t));
	if (!parse_raw_model(raw_model, lines))
		return (NULL);
	return (raw_model);
}

void free_raw_model(raw_model_t *raw_model)
{
	for (int i = 0 ; i < raw_model->faces_count ; i++) {
		free(raw_model->faces[i].v);
		free(raw_model->faces[i].vt);
	}
	free(raw_model->vertices);
	free(raw_model->textures);
	free(raw_model->faces);
	free(raw_model);
}

model_t *load_model(const char *path)
{
	list_t *lines = NULL;
	FILE *file = NULL;
	raw_model_t *raw_model = NULL;
	model_t *model = NULL;

	if (!file_extension(path, MODEL_FORMAT))
		return (NULL);
	file = fopen(path, "r");
	if (path == NULL || file == NULL)
		return (NULL);
	lines = file_to_list(file);
	raw_model = get_raw_model(lines);
	fclose(file);
	if (raw_model == NULL)
		return (NULL);
	model = get_model_from_raw(raw_model);
	if (model == NULL)
		return (NULL);
	list_free(&lines, NULL);
	return (free_raw_model(raw_model), model);
}
