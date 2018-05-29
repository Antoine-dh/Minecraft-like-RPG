/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "my.h"
#include "block.h"
#include "map.h"

block_t *get_map_block(const map_t *map, int x, int y, int z)
{
	if (!(CONTAINS(x, 0, map->size.x - 1) &&
		CONTAINS(y, 0, map->size.y - 1) &&
		CONTAINS(z, 0, map->size.z - 1)))
		return (NULL);
	return (&map->blocks[z][y][x]);
}

void block_set_id(block_t *block, int id)
{
	if (!CONTAINS(id, 0, (int)LEN(BLOCKS)))
		return;
	block->id = id;
	for (int i = 0 ; i < 6 ; ++i)
		block->faces[i] = BLOCKS[id].faces[i];
	block->attribute = BLOCKS[id].attribute;
}
