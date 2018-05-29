/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** teleporter
*/

#ifndef TELEPORTER_H_
#define TELEPORTER_H_

#include "game.h"

typedef struct teleporter {
	sfVector3f position;
	char *where;
} teleporter_t;

void load_teleporters(map_t *map, list_t *save);
void update_teleporters(game_t *game);


#endif /* !TELEPORTER_H_ */
