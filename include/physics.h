/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh, lucas_ben
*/

#ifndef MY_RPG_PHYSICS_H
#define MY_RPG_PHYSICS_H

#include <SFML/Graphics.h>

typedef struct game game_t;
typedef struct map map_t;
typedef struct entity entity_t;

static const float GRAVITY = 45.0f;

typedef struct {
	sfVector3f origin;
	sfVector3f size;
} hitbox_t;

static const hitbox_t CUBE_HITBOX = {
	{0, 0, 0},
	{1, 1, 1}
};

void entity_apply_physic(entity_t *entity, game_t *game);
sfBool hitbox3_collide(const hitbox_t *a, const hitbox_t *b);

#endif //MY_RPG_PHYSICS_H
