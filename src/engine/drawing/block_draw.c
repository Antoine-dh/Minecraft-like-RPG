/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"

void block_face_draw(const map_t *map, block_t *block, int i, float elapsed)
{
	int offset = 0;

	if (block->attribute & BLOCK_LIQUID)
		offset = (int)(cosf(elapsed) * 10.0f);
	offset = ABS(offset);
	for (int j = 0 ; j < 4 ; ++j) {
		glTexCoord2f(map->uv[block->faces[i] + offset][j].x,
			map->uv[block->faces[i] + offset][j].y);
		glVertex3f(CUBE_VERTS[CUBE_FACES_V[i][j]].x + block->pos.x,
			CUBE_VERTS[CUBE_FACES_V[i][j]].y + block->pos.y,
			CUBE_VERTS[CUBE_FACES_V[i][j]].z + block->pos.z);
	}
}

static bool_t can_be_draw(const map_t *map, const block_t *block,
	vector3i_t *pos, int i)
{
	if (!(CONTAINS(pos->x + BLOCK_POS[i].x, 0, map->size.x - 1) &&
		CONTAINS(pos->y + BLOCK_POS[i].y, 0, map->size.y - 1) &&
		CONTAINS(pos->z + BLOCK_POS[i].z, 0, map->size.z - 1)) ||
		(!((map->blocks[pos->z + BLOCK_POS[i].z][pos->y +
			BLOCK_POS[i].y][pos->x + BLOCK_POS[i].x].attribute !=
			BLOCK_NULL) &&
			!(map->blocks[pos->z + BLOCK_POS[i].z][pos->y +
				BLOCK_POS[i].y][pos->x +
				BLOCK_POS[i].x].attribute & BLOCK_ALPHA)) &&
		!(block->attribute & BLOCK_ALPHA &&
			map->blocks[pos->z + BLOCK_POS[i].z][pos->y +
				BLOCK_POS[i].y][pos->x +
				BLOCK_POS[i].x].attribute & BLOCK_ALPHA)))
		return (TRUE);
	return (FALSE);
}

void block_draw(const map_t *map, vector3i_t *pos, float elapsed)
{
	block_t *block = &map->blocks[pos->z][pos->y][pos->x];

	if (block->attribute == BLOCK_NULL)
		return;
	for (int i = 0 ; i < 6 ; ++i) {
		if (can_be_draw(map, block, pos, i)) {
			glNormal3f(CUBE_NORMALS[i].x, CUBE_NORMALS[i].y,
				CUBE_NORMALS[i].z);
			block_face_draw(map, block, i, elapsed);
		}
	}
}
