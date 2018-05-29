/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_RAYCASTING_H
#define MY_RPG_RAYCASTING_H

#include "physics.h"

static const int RAY_LENGTH = 3;

typedef struct ray {
	sfVector3f origin;
	sfVector3f dir;
} ray_t;

typedef struct player player_t;
typedef struct game game_t;
typedef struct map map_t;
typedef struct block block_t;

sfBool ray_intersects_hitbox(const ray_t *ray, const hitbox_t *box);
entity_t *get_entity_from_ray(const game_t *game, const player_t *player);
block_t *get_block_from_ray(const map_t *map, const player_t *player);

#endif //MY_RPG_RAYCASTING_H
