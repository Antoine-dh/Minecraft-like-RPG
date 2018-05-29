/*
** EPITECH PROJECT, 2018
** obj_header
** File description:
** Created by lucas_ben,
*/

#include "model.h"
#include "game.h"

void parse_v_line(raw_model_t *model, const char *line)
{
	float value = 0;
	char **split = my_str_split(line, " ");

	for (int i = 0 ; split[i] != NULL ; i++) {
		value = my_strtof(split[i]);
		if (i == 1)
			model->vertices[model->vertices_count].x = value;
		if (i == 2)
			model->vertices[model->vertices_count].y = value;
		if (i == 3)
			model->vertices[model->vertices_count].z = value;
		free(split[i]);
	}
	free(split);
	model->vertices_count++;
}

void parse_vt_line(raw_model_t *model, const char *line)
{
	float value = 0;
	char **split = my_str_split(line, " ");

	for (int i = 0 ; split[i] != NULL ; i++) {
		value = my_strtof(split[i]);
		if (i == 1)
			model->textures[model->textures_count].x = value;
		if (i == 2)
			model->textures[model->textures_count].y = value;
		free(split[i]);
	}
	free(split);
	model->textures_count++;
}

void parse_sub_f_line(char **split, raw_model_t *model, face_t *face, int sub_i)
{
	int value = 0;

	for (int i = 0 ; split[i] != NULL ; i++) {
		if (my_strlen(split[i]) == 0)
			continue;
		value = my_getnbr(split[i]);
		if (i == 0)
			face->v[sub_i - 1] = model->vertices[value - 1];
		if (i == 1)
			face->vt[sub_i - 1] = model->textures[value - 1];
	}
}

void sub_parse_f_line(char **split, raw_model_t *model, face_t *face)
{
	char **sub_split = NULL;

	for (int i = 0 ; split[i] != NULL ; i++) {
		if (i > 0) {
			sub_split = my_str_usplit(split[i], "/");

			parse_sub_f_line(sub_split, model, face, i);
			for (int j = 0 ; sub_split[j] ; j++)
				free(sub_split[j]);
			free(sub_split);
		}
		free(split[i]);
	}
}

int parse_f_line(raw_model_t *model, const char *line)
{
	int count = 0;
	face_t *face = &model->faces[model->faces_count];
	char **split = my_str_split(line, " ");

	for (count = 0 ; split[count] != NULL ; count++);
	face->points_count = count - 1;
	face->v = malloc(sizeof(sfVector3f) * (count - 1));
	face->vt = malloc(sizeof(sfVector2f) * (count - 1));
	if (face->v == NULL || face->vt == NULL)
		return (0);
	memset(face->v, -1, sizeof(sfVector3f) * (count - 1));
	memset(face->vt, -1, sizeof(sfVector2f) * (count - 1));
	sub_parse_f_line(split, model, face);
	model->faces_count++;
	free(split);
	return (1);
}