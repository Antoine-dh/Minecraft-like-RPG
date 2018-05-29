/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"

int quest_walk_somewhere(game_t *game, const int data[10])
{
	if ((int)game->player->entity.position.x == data[0] &&
		(int)game->player->entity.position.y == data[1] &&
		(int)game->player->entity.position.z == data[2]) {
		return (1);
	}
	return (0);
}

int quest_talk_to(UNUSED game_t *game, UNUSED const int data[10])
{
	return (0);
}

int quest_have(UNUSED game_t *game, UNUSED const int data[10])
{
	return (0);
}

int quest_give(game_t *game, const int data[10])
{
	add_inventory(game, data[0]);
	return (1);
}

int quest_remove(UNUSED game_t *game, UNUSED const int data[10])
{
	return (0);
}
