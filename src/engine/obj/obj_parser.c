/*
** EPITECH PROJECT, 2018
** obj_parser
** File description:
** Created by lucas_ben,
*/

#include <model.h>
#include "game.h"

void parse_obj_line(raw_model_t *raw_model, const char *line)
{
	if (line[0] == '#')
		return;
	if (line[0] == 'v') {
		if (line[1] == ' ')
			parse_v_line(raw_model, line);
		if (line[1] == 'n')
			return;
		if (line[1] == 't')
			parse_vt_line(raw_model, line);
	}
	if (line[0] == 'f') {
		if (!parse_f_line(raw_model, line))
			my_printf("[OBJ][ERROR][FACE] -> %s\n", line);
	}
}

int pre_parse_raw_model(raw_model_t *raw_model, list_t *lines)
{
	char *line = NULL;

	while (lines != NULL) {
		line = (char *)lines->data;
		if (line[0] == 'v' && line[1] == 't')
			raw_model->textures_count++;
		if (line[0] == 'v' && line[1] == ' ')
			raw_model->vertices_count++;
		if (line[0] == 'f' && line[1] == ' ')
			raw_model->faces_count++;
		lines = lines->next;
	}
	raw_model->vertices = malloc(sizeof(sfVector3f) *
		raw_model->vertices_count);
	raw_model->textures = malloc(sizeof(sfVector3f) *
		raw_model->textures_count);
	raw_model->faces = malloc(sizeof(face_t) * raw_model->faces_count);
	if (raw_model->vertices == NULL || raw_model->textures == NULL)
		return (0);
	return (1);
}

int parse_raw_model(raw_model_t *raw_model, list_t *lines)
{
	if (!pre_parse_raw_model(raw_model, lines))
		return (0);
	memset(raw_model->vertices, 0, (sizeof(sfVector3f) *
		raw_model->vertices_count));
	memset(raw_model->textures, 0, (sizeof(sfVector3f) *
		raw_model->textures_count));
	memset(raw_model->faces, 0, (sizeof(face_t) *
		raw_model->faces_count));
	raw_model->textures_count = 0;
	raw_model->vertices_count = 0;
	raw_model->faces_count = 0;
	while (lines != NULL) {
		parse_obj_line(raw_model, (char *)lines->data);
		lines = lines->next;
	}
	return (1);
}