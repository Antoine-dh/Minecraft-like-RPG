/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_MAP_H
#define MY_RPG_MAP_H

#include <SFML/Audio.h>
#include "block.h"
#include "list.h"
#include <SFML/Graphics.h>

typedef struct map {
	char *name;
	sfTexture *tileset;
	sfTexture *skybox;
	sfVector2f uv[MAX_TILES][4];
	block_t ***blocks;
	vector3i_t size;
	sfMusic *music;
	list_t *teleporters;
	vector3i_t spawn;
	list_t *spawners;
} map_t;

map_t *map_create(vector3i_t *size);
map_t *map_load(const char *file);
void map_draw(const map_t *map, const sfVector3f *from, int far, float elapsed);
void free_map(map_t *map);

void *multi_array_alloc(const size_t *nmemb, size_t size, int depth);
vector3i_t load_vector(list_t *save, const char *name);

void save_map(map_t *map, const char *filename);

#endif //MY_RPG_MAP_H
