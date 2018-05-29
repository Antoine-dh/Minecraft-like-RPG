/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "raycasting.h"
#include "game.h"

void knockback_management(entity_t *entity, player_t *player)
{
	sfVector3f dir;

	dir.x = player->cam->look_at.x - player->cam->pos.x;
	dir.y = player->cam->look_at.y - player->cam->pos.y;
	dir.z = player->cam->look_at.z - player->cam->pos.z;
	dir = vector3_normalize(&dir);
	entity->knockback_coefficient.x = dir.x * 7.0f;
	entity->knockback_coefficient.y = 1.2f;
	entity->knockback_coefficient.z = dir.z * 7.0f;
}

void entity_hit(game_t *game, entity_t *entity)
{
	particle_sys_instantiate(&game->particle_systems, &PARTICLE_BLOOD,
		&entity->position);
	entity->health_point -= game->player->attack;
	knockback_management(entity, game->player);
	if (entity->health_point > 0)
		sound_play(entity->sound, game->sounds);
	else
		game->player->experience_actual += 20;
}

void attack_management(game_t *game)
{
	entity_t *tmp;

	tmp = get_entity_from_ray(game, game->player);
	if (tmp == NULL)
		return;
	else
		entity_hit(game, tmp);
}
