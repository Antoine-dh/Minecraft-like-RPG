/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lucas_ben
*/

#ifndef MY_RPG_MODEL_H
#define MY_RPG_MODEL_H

#define MODEL_FORMAT ".obj"

#include <SFML/Graphics.h>
#include "list.h"

typedef struct {
	int points_count;
	sfVector3f *v;
	sfVector2f *vt;
} face_t;

typedef struct {
	int faces_count;
	int vertices_count;
	int textures_count;
	sfVector3f *vertices;
	sfVector2f *textures;
	face_t *faces;
} raw_model_t;

typedef struct {
	int faces_count;
	face_t *faces;
} model_t;

typedef struct {
	int frames_count;
	model_t **frames;
	char *name;
} animodel_t;

raw_model_t *get_raw_model(list_t *lines);
model_t *get_model_from_raw(raw_model_t *raw_model);
model_t *load_model(const char *path);
int parse_raw_model(raw_model_t *raw_model, list_t *lines);
void parse_v_line(raw_model_t *model, const char *line);
void parse_vt_line(raw_model_t *model, const char *line);
int parse_f_line(raw_model_t *model, const char *line);
animodel_t *load_animation(char *path);
void free_model(model_t *model);
void free_animodel(animodel_t *model);
int animodel_cmp_by_name(animodel_t *a, animodel_t *b);

#endif
