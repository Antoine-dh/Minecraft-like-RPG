/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "raycasting.h"
#include "game.h"

static void sub_getblock(block_t *block, block_t **block_ptr, float *distance,
	const ray_t *ray)
{
	hitbox_t cube_hitbox = {.size = CUBE_HITBOX.size};
	sfVector3f block_pos;
	sfVector3f dist_vect;
	float tmp_distance = 0;

	if (block == NULL || block->id == 0)
		return;
	block_pos = (sfVector3f){block->pos.x, block->pos.y, block->pos.z};
	cube_hitbox.origin = block_pos;
	dist_vect = vector3_sub(&block_pos, &ray->origin);
	if (ray_intersects_hitbox(ray, &cube_hitbox)) {
		tmp_distance = vector3_magnitude(&dist_vect);
		if (tmp_distance != -1 &&
			(*distance == -1 || tmp_distance < *distance)) {
			*block_ptr = block;
			*distance = tmp_distance;
		}
	}
}

block_t *get_block_from_ray(const map_t *map, const player_t *player)
{
	const vector3i_t _p = {(int)player->cam->pos.x, (int)player->cam->pos.y,
		(int)player->cam->pos.z};
	vector3i_t p;
	ray_t ray = {.origin = player->cam->pos};
	block_t *block = NULL;
	float distance = -1;
	int r = RAY_LENGTH;

	ray.dir = vector3_sub(&player->cam->look_at, &player->cam->pos);
	ray.dir = vector3_normalize(&ray.dir);
	for (p.z = _p.z - r ; p.z < _p.z + r + 1 ; ++p.z)
		for (p.y = _p.y - r ; p.y < _p.y + r + 1 ; ++p.y)
			for (p.x = _p.x - r ; p.x < _p.x + r + 1 ; ++p.x)
				sub_getblock(get_map_block(map, p.x, p.y, p.z),
					&block, &distance, &ray);
	return (block);
}

entity_t *get_entity_from_ray(const game_t *game, const player_t *player)
{
	sfVector3f dir;
	ray_t ray = {.origin = player->cam->pos};

	dir.x = player->cam->look_at.x - player->cam->pos.x;
	dir.y = player->cam->look_at.y - player->cam->pos.y;
	dir.z = player->cam->look_at.z - player->cam->pos.z;
	dir = vector3_normalize(&dir);
	ray.dir = dir;
	for (list_t *tmp = game->entities ; tmp != NULL ; tmp = tmp->next)
		if (ray_intersects_hitbox(&ray,
			&((entity_t *)(tmp->data))->hitbox))
			return ((entity_t *)tmp->data);
	return (NULL);
}

sfBool ray_intersects_hitbox(const ray_t *ray, const hitbox_t *box)
{
	sfVector3f dirfrac = {1.0f, 1.0f, 1.0f};
	sfVector3f a;
	sfVector3f b;
	float tmax;
	float tmin;

	dirfrac = vector3_div(&dirfrac, &ray->dir);
	a.x = (box->origin.x - ray->origin.x) * dirfrac.x;
	b.x = (box->origin.x + box->size.x - ray->origin.x) * dirfrac.x;
	a.y = (box->origin.y - ray->origin.y) * dirfrac.y;
	b.y = (box->origin.y + box->size.y - ray->origin.y) * dirfrac.y;
	a.z = (box->origin.z - ray->origin.z) * dirfrac.z;
	b.z = (box->origin.z + box->size.z - ray->origin.z) * dirfrac.z;
	tmin = MAX(MAX(MIN(a.x, b.x), MIN(a.y, b.y)), MIN(a.z, b.z));
	tmax = MIN(MIN(MAX(a.x, b.x), MAX(a.y, b.y)), MAX(a.z, b.z));
	if (tmin < 0 || tmin > tmax)
		return (sfFalse);
	return (sfTrue);
}

