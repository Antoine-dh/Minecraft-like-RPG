/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"
#include "skybox.h"

void map_draw(const map_t *map, const sfVector3f *from, int far, float elapsed)
{
	vector3i_t a = {(int)CLAMP(from->x - far, 0, map->size.x),
		(int)CLAMP(from->y - far, 0, map->size.y),
		(int)CLAMP(from->z - far, 0, map->size.z)};
	vector3i_t b = {(int)CLAMP(from->x + far, 0, map->size.x),
		(int)CLAMP(from->y + far, 0, map->size.y),
		(int)CLAMP(from->z + far, 0, map->size.z)};

	if (map->tileset == NULL)
		return;
	sfTexture_bind(map->tileset);
	glBegin(GL_QUADS);
	for (int x = a.x ; x < b.x ; x++)
		for (int y = a.y ; y < b.y ; y++)
			for (int z = a.z ; z < b.z ; z++)
				block_draw(map, &map->blocks[z][y][x].pos,
					elapsed);
	glEnd();
	sfTexture_bind(NULL);
}
