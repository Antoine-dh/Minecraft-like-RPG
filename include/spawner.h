/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** spawner
*/

#ifndef SPAWNER_H_
#define SPAWNER_H_

#include <SFML/Graphics.h>
#include "vector.h"

#define MAX_ENTITY 100

typedef struct spawner {
	char *name;
	vector3i_t position;
	vector3i_t size;
	float spawn_rate;
	float cooldown;
} spawner_t;

/* format: x,y,z,sx,sy,sz,rate,name */

typedef struct game game_t;

list_t *load_spawners(list_t *save);
void update_spawner(game_t *game, spawner_t *spawner);

#endif /* !SPAWNER_H_ */
