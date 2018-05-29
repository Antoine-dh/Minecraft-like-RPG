/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** place_block
*/

#include "game.h"
#include "raycasting.h"

void break_block(game_t *game)
{
	block_t *block = get_block_from_ray(game->map, game->player);
	sfVector3f pos;

	if (block != NULL) {
		pos.x = block->pos.x + 0.5f;
		pos.y = block->pos.y + 0.5f;
		pos.z = block->pos.z + 0.5f;
		block_set_id(block, 0);
		particle_sys_instantiate(&game->particle_systems,
			&PARTICLE_BREAK, &pos);
		sound_play("break", game->sounds);
	}
}

static void sub_place_block(game_t *game, map_t *map, sfVector3f *p)
{
	sfVector3f dir = vector_from_angle(&game->player->cam->rot);

	p->x -= 0.1f * dir.x;
	p->y -= 0.1f * dir.y;
	p->z -= 0.1f * dir.z;
	if (CONTAINS(p->x, 0, map->size.x) && CONTAINS(p->y, 0, map->size.y) &&
		CONTAINS(p->z, 0, map->size.z)) {
		block_set_id(&map->blocks[(int)p->z][(int)p->y][(int)p->x],
			game->player->selection);
	}
}

void place_block(game_t *game, map_t *map)
{
	sfVector3f dir = vector_from_angle(&game->player->cam->rot);
	sfVector3f p = game->player->cam->pos;
	int i;

	for (i = 0 ; i < (RAY_LENGTH * 2) * 10 ; i++) {
		p.x += 0.1f * dir.x;
		p.y += 0.1f * dir.y;
		p.z += 0.1f * dir.z;
		if (CONTAINS(p.x, 0, map->size.x) &&
			CONTAINS(p.y, 0, map->size.y) &&
			CONTAINS(p.z, 0, map->size.z) &&
			map->blocks[(int)p.z][(int)p.y][(int)p.x].id != 0)
			break;
	}
	if (i != (RAY_LENGTH * 2) * 10)
		sub_place_block(game, map, &p);
}
