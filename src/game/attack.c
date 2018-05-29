/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** attack
*/

#include "game.h"

void entity_attack(game_t *game, entity_t *entity)
{
	float distance = vector3_distance(&game->player->entity.position,
		&entity->position);

	if (distance > 2.0f)
		return;
	entity->cooldown += game->dt;
	entity->hit_rate = 2;
	if (entity->cooldown >= entity->hit_rate) {
		entity->cooldown = 0;
		if (!game->player->godmode)
			game->player->entity.health_point -= 2.0f;
		if (game->player->entity.health_point <= 0)
			game->player->entity.health_point = 0;
	}
}