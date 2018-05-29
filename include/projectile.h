/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** projectile
*/

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "game.h"

typedef struct projectile {
	float time;
	float velocity;
	sfVector3f position;
	hitbox_t hitbox;
	sfVector2f rotation;
	sfVector3f force;
	particle_sys_t *trails; //NULL for NONE
	int damage;
} projectile_t;

void update_projectile(game_t *game, projectile_t *projectile);
void instantiate_projectile(game_t *game, player_t *player);
int is_projectile_alive(UNUSED projectile_t *a, projectile_t *b);
void free_projectile(projectile_t *projectile);

#endif /* !PROJECTILE_H_ */
