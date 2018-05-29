/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"
#include "spawner.h"

void free_spawner(spawner_t *spawner)
{
	free(spawner->name);
	free(spawner);
}

void free_map(map_t *map)
{
	for (int z = 0 ; z < map->size.z ; ++z) {
		for (int y = 0 ; y < map->size.y ; ++y)
			free(map->blocks[z][y]);
		free(map->blocks[z]);
	}
	free(map->blocks);
	free(map->name);
	sfTexture_destroy(map->tileset);
	sfTexture_destroy(map->skybox);
	sfMusic_destroy(map->music);
	list_free(&map->spawners, free_spawner);
	free(map);
}

static void set_block(block_t *block, vector3i_t *pos)
{
	block->pos = *pos;
	block_set_id(block, 0);
}

map_t *map_create(vector3i_t *size)
{
	vector3i_t p;
	size_t nmemb[3] = {(size_t)size->x, (size_t)size->y, (size_t)size->z};
	map_t *map = malloc(sizeof(map_t));

	if (map == NULL)
		return (NULL);
	map->size = *size;
	map->tileset = NULL;
	map->skybox = NULL;
	map->blocks = multi_array_alloc(nmemb, sizeof(block_t), 3);
	if (map->blocks == NULL)
		return (NULL);
	map->name = NULL;
	for (p.x = 0 ; p.x < map->size.x ; ++p.x)
		for (p.y = 0 ; p.y < map->size.y ; ++p.y)
			for (p.z = 0 ; p.z < map->size.z ; ++p.z)
				set_block(&map->blocks[p.z][p.y][p.x], &p);
	return (map);
}
