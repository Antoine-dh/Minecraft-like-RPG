/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** projectile
*/

#include "game.h"

void projectile_knockback(projectile_t *projectile, entity_t *entity)
{
	sfVector3f dir;

	dir = vector_from_angle(&projectile->rotation);
	entity->knockback_coefficient.x = dir.x * 7.0f;
	entity->knockback_coefficient.y = 1.2f;
	entity->knockback_coefficient.z = dir.z * 7.0f;
}

void collide_projectile(game_t *game, projectile_t *projectile)
{
	for (list_t *tmp = game->entities ; tmp ; tmp = tmp->next) {
		if (hitbox3_collide(&((entity_t *)(tmp->data))->hitbox,
			&projectile->hitbox)) {
			entity_hit(game, tmp->data);
			projectile->time = -1.0f;
		}
	}
}

void update_projectile(game_t *game, projectile_t *projectile)
{
	projectile->time -= game->dt;
	projectile->position.x += projectile->force.x * game->dt;
	projectile->position.y += projectile->force.y * game->dt;
	projectile->position.z += projectile->force.z * game->dt;
	projectile->trails->pos = projectile->position;
	projectile->hitbox.origin = projectile->position;
	collide_projectile(game, projectile);
}

void instantiate_projectile(game_t *game, player_t *player)
{
	projectile_t *projectile = malloc(sizeof(projectile_t));
	sfVector3f normal;

	if (!projectile)
		return;
	projectile->time = 3.0f;
	projectile->position = player->cam->pos;
	projectile->position.y -= 1.0f;
	projectile->rotation = player->cam->rot;
	normal = vector_from_angle(&projectile->rotation);
	projectile->force.x = 15.0f * normal.x;
	projectile->force.y = 15.0f * normal.y;
	projectile->force.z = 15.0f * normal.z;
	projectile->hitbox = CUBE_HITBOX;
	projectile->trails = particle_sys_instantiate(&game->particle_systems,
		&PARTICLE_FIRE, &projectile->position);
	projectile->trails->sys_lifetime = INFINITY;
	projectile->damage = player->attack;
	list_push(&game->projectile, projectile);
}
